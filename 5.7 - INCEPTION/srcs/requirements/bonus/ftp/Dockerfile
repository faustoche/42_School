FROM debian:bookworm-slim

#-----------------------INSTALL VSFTPD
RUN apt-get update && apt-get install -y --no-install-recommends \
    vsftpd \
    && rm -rf /var/lib/apt/lists/*

#-----------------------COPY FTP CONFIG
COPY ./vsftpd.conf /etc/vsftpd.conf
COPY ./ftp_setup.sh /ftp_setup.sh

RUN chmod +x /ftp_setup.sh

#-----------------------EXPOSE FTP PORTS
EXPOSE 21 21000-21010

#-----------------------LAUNCH THE CONFIGURATION FILE
ENTRYPOINT ["./ftp_setup.sh"]