FROM debian:bookworm-slim

#-----------------------INSTALL NGINX
RUN apt-get update && apt-get install -y --no-install-recommends \
    nginx \
    && rm -rf /var/lib/apt/lists/*

#-----------------------COPY STATIC FILES
COPY ./public/ /var/www/static/

#-----------------------COPY NGINX CONFIG
COPY ./nginx.conf /etc/nginx/nginx.conf

#-----------------------SET PERMISSIONS
RUN chown -R www-data:www-data /var/www/static

#-----------------------EXPOSE PORT
EXPOSE 80

#-----------------------START NGINX
CMD ["nginx", "-g", "daemon off;"]