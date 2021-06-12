kubectl delete -f ./srcs/mysql/mysql.yaml
eval $(minikube docker-env)
sleep 8
docker ps > /dev/null 2>&1
docker rmi build_mysql > /dev/null 2>&1
docker images > /dev/null 2>&1
docker rmi build_mysql > /dev/null 2>&1
docker ps > /dev/null 2>&1
docker rmi build_mysql > /dev/null 2>&1
docker images > /dev/null 2>&1
docker rmi build_mysql > /dev/null 2>&1
echo "[build mysql...!!!]"
docker build -t build_mysql ./srcs/mysql > /dev/null 2>&1
kubectl apply -f ./srcs/mysql/mysql.yaml
