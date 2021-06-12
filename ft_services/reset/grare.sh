kubectl delete -f ./srcs/grafana/grafana.yaml
eval $(minikube docker-env)
sleep 8
docker ps > /dev/null 2>&1
docker rmi build_grafana > /dev/null 2>&1
docker images > /dev/null 2>&1
docker rmi build_grafana > /dev/null 2>&1
docker ps > /dev/null 2>&1
docker rmi build_grafana > /dev/null 2>&1
docker images > /dev/null 2>&1
docker rmi build_grafana > /dev/null 2>&1
echo "[build grafana...!!!]"
docker build -t build_grafana ./srcs/grafana > /dev/null 2>&1
kubectl apply -f ./srcs/grafana/grafana.yaml
