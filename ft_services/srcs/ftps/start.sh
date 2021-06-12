#!/bin/sh
adduser -D -h /var/ftp admin
echo "admin:admin" | chpasswd
vsftpd /etc/vsftpd/vsftpd.conf
