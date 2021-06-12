FROM	alpine
# instal basic
RUN		apk upgrade
RUN		apk add openssl vsftpd
# ssl
RUN     openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -keyout /etc/ssl/private/vsftpd.key -out /etc/ssl/certs/vsftpd.crt \
		-subj '/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=youngrch/CN=192.168.49.3'
# storage folder
RUN     mkdir -p /var/ftp
# copy
COPY    vsftpd.conf /etc/vsftpd/vsftpd.conf
# port
EXPOSE  20 21 21022
# start
COPY	start.sh /start.sh
RUN		chmod 777 /start.sh
CMD		sh /start.sh