#!/bin/bash

set -e

echo "=== DÉMARRAGE DE LA CONFIGURATION MARIADB ==="

#-----------------------CHECK ENVIRONMENT VARIABLES
if [ -z "$SQL_DATABASE" ] || [ -z "$SQL_USER" ] || [ -z "$SQL_PWD" ] || [ -z "$SQL_ROOT_PWD" ]; then
    echo "ERREUR: Variables d'environnement manquantes (SQL_DATABASE, SQL_USER, SQL_PWD, SQL_ROOT_PWD)"
    exit 1
fi

echo "Variables d'environnement OK"
echo "Base de données: $SQL_DATABASE"
echo "Utilisateur: $SQL_USER"

#-----------------------CREATE REQUIRED DIRECTORIES & PERMISSIONS
mkdir -p /var/run/mysqld /var/log/mysql /run/mysqld
chown -R mysql:mysql /var/lib/mysql /var/run/mysqld /var/log/mysql /run/mysqld
chmod 755 /var/run/mysqld /var/log/mysql /run/mysqld

#-----------------------INITIALIZE DATABASE IF NEEDED
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initialisation de la base de données..."
    if command -v mariadb-install-db &> /dev/null; then
        mariadb-install-db --user=mysql --datadir=/var/lib/mysql --skip-test-db
    else
        mysql_install_db --user=mysql --datadir=/var/lib/mysql
    fi
fi

#-----------------------KILL EXISTING PROCESSES
echo "Nettoyage des processus existants..."
pkill mysqld || true
pkill mariadb || true
sleep 2

#-----------------------START MARIADB IN SAFE MODE
echo "Démarrage de MariaDB en mode sécurisé..."
mysqld_safe --skip-grant-tables --skip-networking --user=mysql &
MYSQL_PID=$!

#-----------------------WAIT FOR MYSQL
echo "Attente du démarrage de MySQL..."
for i in {1..30}; do
    if mysqladmin ping --silent; then
        echo "MySQL est prêt !"
        break
    fi
    if [ $i -eq 30 ]; then
        echo "ERREUR: Timeout - MySQL ne répond pas"
        kill $MYSQL_PID 2>/dev/null || true
        exit 1
    fi
    echo "Tentative $i/30..."
    sleep 2
done

#-----------------------CONFIGURE DATABASE
echo "Configuration de la base de données..."
mysql -u root << EOF
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY '$SQL_ROOT_PWD';
CREATE DATABASE IF NOT EXISTS \`$SQL_DATABASE\`;
CREATE USER IF NOT EXISTS '$SQL_USER'@'%' IDENTIFIED BY '$SQL_PWD';
GRANT ALL PRIVILEGES ON \`$SQL_DATABASE\`.* TO '$SQL_USER'@'%';
FLUSH PRIVILEGES;
EOF

#-----------------------STOP SAFE MODE
echo "Arrêt du mode sécurisé..."
kill $MYSQL_PID 2>/dev/null || true
sleep 3
pkill mysqld || true
pkill mariadb || true
sleep 2

#-----------------------START MARIADB IN NORMAL MODE
echo "Démarrage de MariaDB en mode normal..."
exec mysqld \
    --user=mysql \
    --port=3306 \
    --bind-address=0.0.0.0 \
    --datadir=/var/lib/mysql \
    --socket=/var/run/mysqld/mysqld.sock \
    --pid-file=/var/run/mysqld/mysqld.pid \
    --log-error=/var/log/mysql/error.log
