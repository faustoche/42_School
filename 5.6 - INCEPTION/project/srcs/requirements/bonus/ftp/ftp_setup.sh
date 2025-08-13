#!/bin/bash

#-----------------------CREATE FTP USER
if ! id "ftpuser" &>/dev/null; then
    useradd -m -d /var/ftp ftpuser
    echo "ftpuser:ftppass" | chpasswd
    echo "Utilisateur FTP créé"
fi

#-----------------------SET PERMISSIONS
chown -R ftpuser:ftpuser /var/ftp
chmod -R 755 /var/ftp

#-----------------------CREATE NECESSARY DIRECTORIES
mkdir -p /var/run/vsftpd/empty

#-----------------------START VSFTPD
exec /usr/sbin/vsftpd /etc/vsftpd.conf