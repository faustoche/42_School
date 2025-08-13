FROM debian:bookworm-slim

# Install PHP and necessary packages
RUN apt-get update && apt-get install -y --no-install-recommends \
    php8.2-cli \
    php8.2-mysql \
    php8.2-curl \
    php8.2-gd \
    php8.2-xml \
    php8.2-mbstring \
    php8.2-zip \
    wget \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /var/www

RUN wget https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php && \
    mv adminer-4.8.1.php index.php && \
    chown -R www-data:www-data /var/www/

EXPOSE 8080

CMD [ "php", "-S", "0.0.0.0:8080", "-t", "/var/www" ]