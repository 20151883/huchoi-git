FROM	debian:buster

RUN	apt-get update && apt-get install -y \
	nginx \ 
	openssl \ 
	wget \
	php7.3-fpm \
	vim \
	curl 
	# mariadb-server \
	# php-mysql \
	# php-mbstring \
	# vim \

COPY	./srcs/run.sh ./
COPY	./srcs/default ./tmp
COPY	./srcs/wp-config.php ./tmp
COPY	./srcs/config.inc.php ./tmp

EXPOSE	80 443 20000

CMD 	bash run.sh
