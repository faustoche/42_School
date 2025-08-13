#!/bin/bash

set -e  # Arrêter en cas d'erreur

echo "=== DÉMARRAGE DE LA CONFIGURATION WORDPRESS ==="

#-----------------------INSTALL WP-CLI (toujours)
if [ ! -f /usr/bin/wp ]; then
    echo "Installation de WP-CLI..."
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/bin/wp
    echo "WP-CLI installé !"
fi

# Fonction pour attendre Redis
wait_for_redis() {
    echo "Attente de Redis..."
    max_attempts=30
    attempt=0
    while ! nc -z redis 6379 && [ $attempt -lt $max_attempts ]; do
        attempt=$((attempt + 1))
        echo "Tentative $attempt/$max_attempts pour Redis..."
        sleep 2
    done
    if [ $attempt -eq $max_attempts ]; then
        echo "ATTENTION: Redis non accessible après $max_attempts tentatives"
        return 1
    fi
    echo "Redis est prêt !"
    return 0
}

# Fonction pour attendre MariaDB
wait_for_mariadb() {
    echo "Attente de MariaDB..."
    max_attempts=60
    attempt=0
    while ! nc -z mariadb 3306 && [ $attempt -lt $max_attempts ]; do
        attempt=$((attempt + 1))
        echo "Tentative $attempt/$max_attempts pour MariaDB..."
        sleep 2
    done
    if [ $attempt -eq $max_attempts ]; then
        echo "ERREUR: MariaDB non accessible après $max_attempts tentatives"
        exit 1
    fi
    echo "MariaDB est prêt !"
}

#-----------------------VÉRIFICATION DES VARIABLES D'ENVIRONNEMENT
echo "Vérification des variables d'environnement..."
required_vars="SQL_DATABASE SQL_USER SQL_PWD WP_DOMAIN_NAME WP_TITLE WP_ADMIN_NAME WP_ADMIN_PWD WP_ADMIN_EMAIL WP_USER_NAME WP_USER_EMAIL WP_USER_PWD WP_USER_ROLE"

for var in $required_vars; do
    if [ -z "${!var}" ]; then
        echo "ERREUR: Variable d'environnement $var manquante"
        exit 1
    fi
done
echo "Variables d'environnement OK !"

#-----------------------INSTALL WORDPRESS
if [ ! -f /var/www/wordpress/wp-config.php ]; then
    echo "=== INSTALLATION DE WORDPRESS ==="
    
    # Attendre que MariaDB soit prêt avant l'installation
    wait_for_mariadb
    
    # prepare wordpress directory
    mkdir -p /var/www/wordpress
    cd /var/www/wordpress
    
    # installer wordpress
    echo "Téléchargement de WordPress..."
    wp core download --allow-root
    
    if [ ! -f wp-config-sample.php ]; then
        echo "ERREUR: fichier wp-config-sample.php non trouvé..."
        exit 1
    fi
    
    echo "Configuration de WordPress..."
    cp wp-config-sample.php wp-config.php
    
    # Configuration de la base de données
    sed -i "s/database_name_here/$SQL_DATABASE/" wp-config.php
    sed -i "s/username_here/$SQL_USER/" wp-config.php
    sed -i "s/password_here/$SQL_PWD/" wp-config.php
    sed -i "s/localhost/mariadb/" wp-config.php
    
    # Ajouter les clés de sécurité WordPress
    wp config shuffle-salts --allow-root
    
    # Configuration Redis et autres paramètres
    cat >> wp-config.php << 'EOF'

// Redis Configuration
define('WP_REDIS_HOST', 'redis');
define('WP_REDIS_PORT', 6379);
define('WP_REDIS_TIMEOUT', 1);
define('WP_REDIS_READ_TIMEOUT', 1);
define('WP_REDIS_DATABASE', 0);

// Enable Redis Object Cache
define('WP_CACHE', true);

// Désactiver demande FTP pour installer les plugins
define('FS_METHOD', 'direct');

// Permissions des fichiers
define('FS_CHMOD_DIR', (0755 & ~ umask()));
define('FS_CHMOD_FILE', (0644 & ~ umask()));

// Désactiver l'éditeur de fichiers
define('DISALLOW_FILE_EDIT', true);

// Augmenter la limite de mémoire
define('WP_MEMORY_LIMIT', '256M');
EOF

    echo "Installation de WordPress..."
    # wordpress installation + configuration
    wp core install \
        --url="$WP_DOMAIN_NAME" \
        --title="$WP_TITLE" \
        --admin_user="$WP_ADMIN_NAME" \
        --admin_password="$WP_ADMIN_PWD" \
        --admin_email="$WP_ADMIN_EMAIL" \
        --allow-root
    
    # Configuration Redis si disponible
    if wait_for_redis; then
        echo "Configuration du cache Redis..."
        # Vérifier que l'extension Redis PHP est disponible
        if php -m | grep -q redis; then
            echo "Extension Redis PHP détectée, installation du plugin..."
            wp plugin install redis-cache --activate --allow-root || echo "Installation du plugin Redis échouée"
            wp redis enable --allow-root || echo "Activation Redis échouée, mais on continue..."
        else
            echo "ATTENTION: Extension Redis PHP non disponible!"
        fi
    else
        echo "Redis non disponible, cache désactivé"
        # Désactiver Redis dans wp-config.php
        sed -i "s/define('WP_CACHE', true);/define('WP_CACHE', false);/" wp-config.php
    fi
    
    # create a new user
    echo "Création de l'utilisateur WordPress..."
    wp user create "$WP_USER_NAME" "$WP_USER_EMAIL" \
        --user_pass="$WP_USER_PWD" \
        --role="$WP_USER_ROLE" \
        --allow-root
    
    echo "WordPress installé avec succès !"
else
    echo "=== WORDPRESS DÉJÀ INSTALLÉ ==="
    cd /var/www/wordpress
    
    if [ ! -f /usr/bin/wp ]; then
        echo "Installation de WP-CLI manquante..."
        curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
        chmod +x wp-cli.phar
        mv wp-cli.phar /usr/bin/wp
    fi
    
    # AJOUTER LA CONFIGURATION FS_METHOD même si WordPress existe déjà
    if ! grep -q "FS_METHOD" wp-config.php; then
        echo "Ajout de la configuration FS_METHOD..."
        sed -i "/\/\* That's all, stop editing/i\\
// Désactiver demande FTP pour installer les plugins\\
define('FS_METHOD', 'direct');\\
\\
// Permissions des fichiers\\
define('FS_CHMOD_DIR', (0755 & ~ umask()));\\
define('FS_CHMOD_FILE', (0644 & ~ umask()));\\
" wp-config.php
    fi
    
    # Test Redis
    if wait_for_redis; then
        if php -m | grep -q redis; then
            echo "Test de la connexion Redis..."
            wp redis enable --allow-root || echo "Redis activation failed"
        else
            echo "Extension Redis PHP non disponible, ignoré..."
        fi
    fi
fi

#-----------------------PERMISSIONS
echo "Configuration des permissions..."
chown -R www-data:www-data /var/www/wordpress
find /var/www/wordpress -type d -exec chmod 755 {} \;
find /var/www/wordpress -type f -exec chmod 644 {} \;
chmod 600 /var/www/wordpress/wp-config.php

#-----------------------PHP-FPM CONFIGURATION
echo "Configuration de PHP-FPM 8.2..."

# Vérifier que le fichier de configuration existe
if [ ! -f /etc/php/8.2/fpm/pool.d/www.conf ]; then
    echo "ERREUR: Fichier de configuration PHP-FPM non trouvé!"
    echo "Fichiers disponibles:"
    find /etc/php -name "*.conf" 2>/dev/null || echo "Aucun fichier de configuration trouvé"
    exit 1
fi

# Configurer PHP-FPM 8.2 pour écouter sur le port 9000
sed -i 's@listen = /run/php/php8.2-fpm.sock@listen = 9000@' /etc/php/8.2/fpm/pool.d/www.conf
sed -i 's/;listen.owner = www-data/listen.owner = www-data/' /etc/php/8.2/fpm/pool.d/www.conf
sed -i 's/;listen.group = www-data/listen.group = www-data/' /etc/php/8.2/fpm/pool.d/www.conf
sed -i 's/;listen.mode = 0660/listen.mode = 0660/' /etc/php/8.2/fpm/pool.d/www.conf

# Configuration supplémentaire pour PHP-FPM
sed -i 's/;catch_workers_output = yes/catch_workers_output = yes/' /etc/php/8.2/fpm/pool.d/www.conf
sed -i 's/;decorate_workers_output = no/decorate_workers_output = no/' /etc/php/8.2/fpm/pool.d/www.conf

# Créer le répertoire run/php si nécessaire
mkdir -p /run/php

# Tester la configuration PHP-FPM
echo "Test de la configuration PHP-FPM..."
php-fpm8.2 -t

if [ $? -eq 0 ]; then
    echo "Configuration PHP-FPM OK !"
else
    echo "ERREUR: Configuration PHP-FPM invalide!"
    exit 1
fi

# Afficher les informations de débogage
echo "=== INFORMATIONS DE DÉBOGAGE ==="
echo "Version PHP: $(php --version | head -n 1)"
echo "Extensions PHP Redis: $(php -m | grep redis || echo 'Non trouvé')"
echo "Configuration PHP-FPM: $(grep '^listen' /etc/php/8.2/fpm/pool.d/www.conf)"
echo "Utilisateur PHP-FPM: $(grep '^user' /etc/php/8.2/fpm/pool.d/www.conf || echo 'www-data par défaut')"
echo "Groupe PHP-FPM: $(grep '^group' /etc/php/8.2/fpm/pool.d/www.conf || echo 'www-data par défaut')"

#-----------------------LAUNCH PHP-FPM
echo "=== DÉMARRAGE DE PHP-FPM 8.2 ==="
exec php-fpm8.2 -F