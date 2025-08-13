FROM debian:bookworm-slim

#-----------------------INSTALL NECESSARY PACKAGES
RUN apt-get update && apt-get install -y --no-install-recommends \
    curl \
    ca-certificates \
    php8.2-fpm \
    php8.2-mysql \
    php8.2-redis \
    php8.2-curl \
    php8.2-gd \
    php8.2-xml \
    php8.2-mbstring \
    php8.2-zip \
    php8.2-intl \
    mariadb-client \
    netcat-openbsd \
    && rm -rf /var/lib/apt/lists/*

#-----------------------COPY WP_CONF.SH
COPY ./wp_conf.sh /

RUN chmod +x wp_conf.sh

#-----------------------LAUNCH THE CONFIGURATION FILE
ENTRYPOINT ["./wp_conf.sh"]