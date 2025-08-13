FROM debian:bookworm-slim

#-----------------------INSTALL MARIADB
RUN apt-get update && apt-get install -y --no-install-recommends \
    mariadb-server \
    mariadb-client \
    && rm -rf /var/lib/apt/lists/*

#-----------------------CREATE NECESSARY DIRECTORIES AND SET PERMISSIONS
RUN mkdir -p /var/run/mysqld \
    && mkdir -p /var/log/mysql \
    && chown -R mysql:mysql /var/run/mysqld /var/lib/mysql /var/log/mysql \
    && chmod 755 /var/run/mysqld /var/log/mysql

#-----------------------COPY MDB CONFIG
COPY ./mdb-conf.sh /mdb-conf.sh
COPY ./my.cnf /etc/mysql/my.cnf
RUN chmod +x /mdb-conf.sh

#-----------------------EXPOSE PORT
EXPOSE 3306

#-----------------------LAUNCH THE CONFIGURATION FILE
ENTRYPOINT ["./mdb-conf.sh"]
