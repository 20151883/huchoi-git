kubectl delete -f ./srcs/ftps/ftps.yaml
eval $(minikube docker-env)
sleep 8
docker ps > /dev/null 2>&1
docker rmi build_ftps > /dev/null 2>&1
docker images > /dev/null 2>&1
docker rmi build_ftps > /dev/null 2>&1
docker ps > /dev/null 2>&1
docker rmi build_ftps > /dev/null 2>&1
docker images > /dev/null 2>&1
docker rmi build_ftps > /dev/null 2>&1
echo "[build ftps...!!!]"
docker build -t build_ftps ./srcs/ftps > /dev/null 2>&1
kubectl apply -f ./srcs/ftps/ftps.yaml
