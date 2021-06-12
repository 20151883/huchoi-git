FROM	alpine
# install basic
RUN     apk update
RUN     apk add wget nginx
RUN     apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session php-ctype
RUN     mkdir -p /run/nginx
# setting phpmyadmin
RUN		mkdir -p /www/phpmyadmin
RUN		wget -c https://files.phpmyadmin.net/phpMyAdmin/4.9.2/phpMyAdmin-4.9.2-english.tar.gz -O - | tar -xz -C /www
RUN		mv /www/phpMyAdmin-4.9.2-english/* /www/phpmyadmin
# copy
COPY	phpmyadmin.inc.php /www/phpmyadmin/config.inc.php
COPY	nginx.conf /etc/nginx/nginx.conf
# port
EXPOSE	5000
# start
COPY	start.sh /start.sh
RUN		chmod 777 /start.sh
CMD		sh /start.sh