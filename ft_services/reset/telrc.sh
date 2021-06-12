kubectl delete -f ./srcs/telegraf/telegraf.yaml
eval $(minikube docker-env)
sleep 8
docker ps > /dev/null 2>&1
docker rmi build_telegraf > /dev/null 2>&1
docker images > /dev/null 2>&1
docker rmi build_telegraf > /dev/null 2>&1
docker ps > /dev/null 2>&1
docker rmi build_telegraf > /dev/null 2>&1
docker images > /dev/null 2>&1
docker rmi build_telegraf > /dev/null 2>&1
echo "[build telegraf...!!!]"
docker build -t build_telegraf ./srcs/telegraf > /dev/null 2>&1
kubectl apply -f ./srcs/telegraf/telegraf.yaml
