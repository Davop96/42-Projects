#!/bin/sh

DB_PASSWORD=$(cat /run/secrets/mariadb_db_password)
DB_ROOT_PASSWORD=$(cat /run/secrets/mariadb_db_root_password)

# Check whether the user mysql is active
if [ -d "/run/mysqld" ]; then
    echo "[i] mysqld already present, skipping creation"
    chown -R mysql:mysql /run/mysqld || true
else
    echo "[i] mysqld not found, creating..."
    mkdir -p /run/mysqld
    chown -R mysql:mysql /run/mysqld || true
    chmod 755 /run/mysqld
fi

# Check whether mysql has started
if [ -d "\/var/lib/mysql/${MYSQL_DATABASE}" ]; then
    echo "[i] MySQL directory already present, skipping creation"
else
    echo "[i] Initializing database..."
    chown -R mysql:mysql /var/lib/mysql

    # To make a temp file for the configuration
    tfile=$(mktemp)
    if [ ! -f "$tfile" ]; then
        echo "Failed to create temp file"
        exit 1
    fi

    # To config the database and the users
    cat << EOF > $tfile
USE mysql;
FLUSH PRIVILEGES;
GRANT ALL ON *.* TO 'root'@'%' IDENTIFIED BY '${DB_ROOT_PASSWORD}' WITH GRANT OPTION;
GRANT ALL ON *.* TO 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}' WITH GRANT OPTION;
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

    # Init MariaDB server temporaly to start the instructions
    echo "[i] Starting temporary MariaDB server..."
    /usr/sbin/mysqld --user=mysql --bootstrap < $tfile
    rm -f $tfile
fi

echo "[i] MariaDB setup complete. Starting MariaDB server..."
# Init MariaDB server
exec /usr/sbin/mysqld --user=mysql --console --skip-networking=0 --bind-address=0.0.0.0