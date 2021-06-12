# ################ # 
#    ID    : admin #
# psaaword : admin #
# ################ # 

# ################### # 
# port : 192.168.49.3 #
# ################### #

# ############# # 
# ssh resetting #
# ############# #
ssh-keygen -R 192.168.49.3

# ########## #
# replace IP #
# ########## #
sed -i "s/https:\/\/localhost/http:\/\/192.168.49.3:5050/g" wordpress.sql

# ################# #
# upload / download #
# ################# #
curl ftp://192.168.49.2 --ssl -k --user admin:admin -T ./test.txt
curl ftp://192.168.49.2 --ssl -k --user admin:admin  -o ./test.txt

# ############## #
# KILL PROCESSES #
# ############## #
kubectl exec deploy/wordpress -- pkill php-fpm7
kubectl exec deploy/phpmyadmin -- pkill php-fpm7
kubectl exec deploy/grafana -- pkill grafana
kubectl exec deploy/ftps -- pkill vsftpd
kubectl exec deploy/mysql -- pkill mariadb 
kubectl exec deploy/influxdb -- pkill influxd
kubectl exec deploy/nginx -- pkill nginx
kubectl get po

# ################# #
# EXPORTS IF NEEDED #
# ################# #
export MINIKUBE_HOME="$HOME/goinfre/.minikube"
export KUBECONFIG="$MINIKUBE_HOME/.kube/config"
export MINIKUBE_ACTIVE_DOCKERD=minikube
export KUBE_EDITOR="code -w"
export MACHINE_STORAGE_PATH=~/goinfre/youngrch/.docker
# $ env
현재 세션에 정의된 환경 변수들을 화면에 출력
# $ export NAME=VALUE 
NAME이라는 환경변수에 VALUE라는 값을 지정
# $ unset NAME
삭제 
 curl -Ik 
 