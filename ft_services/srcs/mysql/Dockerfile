FROM     alpine
# Installation
RUN     apk update
RUN     apk add mariadb mariadb-client && apk add --no-cache --upgrade bash
# Copy initialisation script
COPY    init_mysql.sh /init_mysql.sh
COPY    wordpress.sql /wordpress.sql
RUN     chmod 777 init_mysql.sh
# port
EXPOSE  3306
# start
COPY	start.sh /start.sh
RUN		chmod 777 /start.sh
CMD		sh /start.sh
