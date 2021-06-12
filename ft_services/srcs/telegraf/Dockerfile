FROM	alpine
# install basic
RUN		apk update
RUN		apk add wget
RUN		wget https://dl.influxdata.com/telegraf/releases/telegraf-1.16.2_linux_amd64.tar.gz
RUN		tar xf telegraf-1.16.2_linux_amd64.tar.gz
RUN		cp -r ./telegraf-1.16.2/* /
# intall glibc
RUN		wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub
RUN		wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.32-r0/glibc-2.32-r0.apk
RUN		apk add glibc-2.32-r0.apk
# copy
COPY    telegraf.conf /etc/telegraf/
# start
CMD		telegraf
