kubectl delete -f ./srcs/influxdb/influxdb.yaml
eval $(minikube docker-env)
sleep 8
docker ps > /dev/null 2>&1
docker rmi build_influxdb > /dev/null 2>&1
docker images > /dev/null 2>&1
docker rmi build_influxdb > /dev/null 2>&1
docker ps > /dev/null 2>&1
docker rmi build_influxdb > /dev/null 2>&1
docker images > /dev/null 2>&1
docker rmi build_influxdb > /dev/null 2>&1
echo "[build influxdb...!!!]"
docker build -t build_influxdb ./srcs/influxdb > /dev/null 2>&1
kubectl apply -f ./srcs/influxdb/influxdb.yaml
