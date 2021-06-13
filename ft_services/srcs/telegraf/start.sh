echo "domain 42seoul.kr" > /etc/resolv.conf && echo "nameserver 8.8.8.8" >> /etc/resolv.conf && wget https://dl.influxdata.com/telegraf/releases/telegraf-1.16.2_linux_amd64.tar.gz && tar xf telegraf-1.16.2_linux_amd64.tar.gz
cp -r ./telegraf-1.16.2/* /
wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub
wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.32-r0/glibc-2.32-r0.apk
apk add glibc-2.32-r0.apk
telegraf

