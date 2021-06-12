FROM	alpine

RUN		apk update
RUN     apk add grafana --repository=http://dl-3.alpinelinux.org/alpine/edge/testing/

COPY	grafana.ini /usr/share/grafana/conf/custom.ini
COPY	datasources.yaml /usr/share/grafana/conf/provisioning/datasources/influxdb.yaml
COPY	dashboards.yaml /usr/share/grafana/conf/provisioning/dashboards/dashboards.yaml
COPY	grafana.json /var/lib/grafana/dashboards/grafana.json

EXPOSE	3000

CMD		/usr/sbin/grafana-server --homepath=/usr/share/grafana
