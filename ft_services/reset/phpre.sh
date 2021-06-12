kubectl delete -f ./srcs/phpmyadmin/phpmyadmin.yaml
eval $(minikube docker-env)
sleep 8
docker ps > /dev/null 2>&1
docker rmi build_phpmyadmin > /dev/null 2>&1
docker images> /dev/null 2>&1
docker rmi build_phpmyadmin > /dev/null 2>&1
docker ps > /dev/null 2>&1
docker rmi build_phpmyadmin > /dev/null 2>&1
docker images > /dev/null 2>&1
docker rmi build_phpmyadmin > /dev/null 2>&1
echo "[build phpmyadmin...!!!]"
docker build -t build_phpmyadmin ./srcs/phpmyadmin > /dev/null 2>&1
kubectl apply -f ./srcs/phpmyadmin/phpmyadmin.yaml
