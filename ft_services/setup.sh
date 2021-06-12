#!/bin/sh
# Colors.
GREEN='\e[0;32m'
RED='\e[0;33m'
BLUE='\e[0;34m'
END='\e[0;0m'
# minikube start
minikube delete
minikube start --vm-driver=docker
minikube addons enable metallb
minikube addons enable dashboard
minikube dashboard &
eval $(minikube docker-env)
# docker build
sleep 30
clear
echo "${GREEN}[building nginx....]${END}"
echo "${RED}[🐳][ ][ ][ ][ ][ ][ ]${END}"
docker build -t build_nginx ./srcs/nginx > /dev/null 2>&1
clear
echo "${GREEN}[building mysql....]${EDN}"
echo "${RED}[✅][🐳][ ][ ][ ][ ][ ][ ]${EDN}"
docker build -t build_mysql ./srcs/mysql > /dev/null 2>&1
clear
echo "${GREEN}[building phpmyadmin....]${END}"
echo "${RED}[✅][✅][🐳][ ][ ][ ][ ][ ]${END}"
docker build -t build_phpmyadmin ./srcs/phpmyadmin > /dev/null 2>&1
clear
echo "${GREEN}[building wordpress....]${EDN}"
echo "${RED}[✅][✅][✅][🐳][ ][ ][ ][ ]${END}"
docker build -t build_wordpress ./srcs/wordpress > /dev/null 2>&1
clear
echo "${GREEN}[building ftps....]${EDN}"
echo "${RED}[✅][✅][✅][✅][✅][🐳][ ][ ]${END}"
docker build -t build_ftps ./srcs/ftps > /dev/null 2>&1
clear
echo "${GREEN}[building influxdb....]${EDN}"
echo "${RED}[✅][✅][✅][✅][✅][🐳][ ][ ]${END}"
docker build -t build_influxdb ./srcs/influxdb > /dev/null 2>&1
clear
echo "${GREEN}[building telegraf....]${EDN}"
echo "${RED}[✅][✅][✅][✅][✅][✅][🐳][ ]${END}"
docker build -t build_telegraf ./srcs/telegraf > /dev/null 2>&1
clear
echo "${GREEN}[building grafana....]${EDN}"
echo "${RED}[✅][✅][✅][✅][✅][✅][✅][🐳]${END}"
docker build -t build_grafana ./srcs/grafana > /dev/null 2>&1
clear
echo "${RED}[✅][✅][✅][✅][✅][✅][✅][✅]${END}"
sleep 5
# kubectl apply
kubectl apply -f ./srcs/metallb/metallb.yaml
kubectl apply -f ./srcs/nginx/nginx.yaml
kubectl apply -f ./srcs/mysql/mysql.yaml
kubectl apply -f ./srcs/phpmyadmin/phpmyadmin.yaml
kubectl apply -f ./srcs/wordpress/wordpress.yaml
kubectl apply -f ./srcs/ftps/ftps.yaml
kubectl apply -f ./srcs/influxdb/influxdb.yaml
kubectl apply -f ./srcs/telegraf/telegraf.yaml
kubectl apply -f ./srcs/grafana/grafana.yaml
echo "${GREEN}[complete!!!]${END}"
