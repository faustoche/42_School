FROM debian:bookworm-slim

#-----------------------INSTALL REDIS
RUN apt-get update && apt-get install -y --no-install-recommends \
    redis-server \
    && rm -rf /var/lib/apt/lists/*

#-----------------------COPY REDIS CONFIG
COPY ./redis.conf /etc/redis/redis.conf

#-----------------------CREATE REDIS USER AND SET PERMISSIONS
# Utiliser adduser au lieu de adduser -D (qui n'existe pas sur Debian)
RUN adduser --system --group --home /var/lib/redis --shell /bin/false redis \
    && mkdir -p /var/lib/redis \
    && chown redis:redis /var/lib/redis \
    && chmod 755 /var/lib/redis

#-----------------------EXPOSE PORT
EXPOSE 6379

#-----------------------START REDIS
USER redis
CMD ["redis-server", "/etc/redis/redis.conf"]