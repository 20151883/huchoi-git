kubectl delete -f ./srcs/wordpress/wordpress.yaml
eval $(minikube docker-env)
sleep 8
docker ps > /dev/null 2>&1
docker rmi build_wordpress > /dev/null 2>&1
docker images > /dev/null 2>&1
docker rmi build_wordpress > /dev/null 2>&1
docker ps > /dev/null 2>&1
docker rmi build_wordpress > /dev/null 2>&1
docker images > /dev/null 2>&1
docker rmi build_wordpress > /dev/null 2>&1
echo "[build wordpress...!!!]"
docker build -t build_wordpress ./srcs/wordpress > /dev/null 2>&1
kubectl apply -f ./srcs/wordpress/wordpress.yaml
