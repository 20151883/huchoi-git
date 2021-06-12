kubectl delete -f ./srcs/nginx/nginx.yaml
eval $(minikube docker-env)
sleep 8
docker ps > /dev/null 2>&1
docker rmi build_nginx > /dev/null 2>&1
docker images > /dev/null 2>&1
docker rmi build_nginx > /dev/null 2>&1
docker ps > /dev/null 2>&1
docker rmi build_nginx > /dev/null 2>&1
docker images > /dev/null 2>&1
docker rmi build_nginx > /dev/null 2>&1
echo "[build nginx...!!!]"
docker build -t build_nginx ./srcs/nginx > /dev/null 2>&1
kubectl apply -f ./srcs/nginx/nginx.yaml
