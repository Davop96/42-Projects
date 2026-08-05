# DEV_DOC.md

## Developer Documentation

This document describes the current Inception project layout and the commands that are useful during development and correction.

## Project Overview

This project deploys a small Docker infrastructure made of three services:

- NGINX as reverse proxy and TLS termination.
- WordPress running with PHP-FPM.
- MariaDB as the database backend.

The services are orchestrated with Docker Compose and launched from the root `Makefile`.

## Current Project Layout

```text
.
├── Makefile
├── README.md
├── DEV_DOC.md
├── commands.txt
├── secrets/
│   ├── mariadb/
│   │   ├── db_password.txt
│   │   └── db_root_password.txt
│   └── wordpress/
│       ├── admin_user.txt
│       ├── admin_password.txt
│       ├── db_password.txt
│       └── wordpress_user_password.txt
└── srcs/
    ├── .env
    ├── docker-compose.yml
    └── requirements/
        ├── mariadb/
        │   ├── Dockerfile
        │   └── tools/
        │       └── mariadb.sh
        ├── nginx/
        │   ├── Dockerfile
        │   ├── conf/
        │   │   └── nginx.conf
        │   └── ssl/
        └── wordpress/
            ├── Dockerfile
            ├── conf/
            │   └── www.conf
            └── tools/
                └── wp.sh
```

## Configuration

### Environment Variables

The main configuration file is `srcs/.env`.

Typical values used by the project:

- `DOMAIN_NAME`: the domain served by NGINX.
- `DEBIAN_USER` and `DEBIAN_PASSWORD`: system user created in the VM.
- `MYSQL_USER`, `MYSQL_DATABASE`: MariaDB database setup.
- `WORDPRESS_DB_HOST`, `WORDPRESS_DB_NAME`, `WORDPRESS_DB_USER`: WordPress database connection.
- `WORDPRESS_URL`: base URL used by WordPress.
- `WORDPRESS_ADMIN_USER`, `WORDPRESS_ADMIN_EMAIL`: WordPress admin account.
- `WORDPRESS_USER`, `WORDPRESS_EMAIL`: additional WordPress user.

### Secrets

Sensitive values are mounted through Docker secrets from the `secrets/` folder.

- `secrets/mariadb/db_password.txt`
- `secrets/mariadb/db_root_password.txt`
- `secrets/wordpress/admin_user.txt`
- `secrets/wordpress/admin_password.txt`
- `secrets/wordpress/db_password.txt`
- `secrets/wordpress/wordpress_user_password.txt`

## Build and Run

### Start the infrastructure

```bash
make
```

or explicitly:

```bash
make up
```

This builds the images and starts the stack in detached mode.

### Stop the infrastructure

```bash
make down
```

### Clean the infrastructure

Remove containers, networks, and volumes:

```bash
make clean
```

Remove everything related to the project, including images:

```bash
make fclean
```

Rebuild everything from scratch:

```bash
make re
```

## Useful Correction Commands

These commands are useful when validating the project during correction.

### Containers and Compose

Show running containers:

```bash
docker ps
```

Show containers managed by Compose:

```bash
docker-compose -f srcs/docker-compose.yml ps
```

### Networks

List Docker networks:

```bash
docker network ls
```

### WordPress / MariaDB

Enter MariaDB:

```bash
docker exec -it mariadb mariadb -u dbohoyo- -p
docker exec -it mariadb mariadb -u root -p
```

Inside MariaDB, useful queries:

```sql
SHOW DATABASES;
USE wordpress;
SHOW TABLES;
DESCRIBE wp_links;
EXIT;
```

### Host and Domain Checks

Check the host mapping:

```bash
grep 'dbohoyo' /etc/hosts
```

If needed, add the host mapping:

```bash
echo '127.0.0.1 dbohoyo-.42.fr' | sudo tee -a /etc/hosts
```

### TLS / NGINX

Inspect the certificate and TLS version:

```bash
openssl s_client -connect dbohoyo-.42.fr:443 -servername dbohoyo-.42.fr -tls1_2
```

Check the certificate subject and validity dates:

```bash
openssl s_client -connect dbohoyo-.42.fr:443 -servername dbohoyo-.42.fr -tls1_2 </dev/null 2>/dev/null | openssl x509 -noout -subject -issuer -dates
```

### System and Environment

Check Debian version:

```bash
cat /etc/debian_version
```

## Accessing the Site

Open the configured domain in a browser:

```text
https://dbohoyo-.42.fr
```

The browser may show a self-signed certificate warning. That is expected.

## Troubleshooting

If the site does not open correctly:

1. Check that the containers are running with `docker ps`.
2. Check `docker-compose -f srcs/docker-compose.yml ps`.
3. Check that `/etc/hosts` contains `dbohoyo-.42.fr`.
4. Run `make down && make up` to rebuild the stack.
5. Verify the TLS certificate with `openssl s_client`.

## Notes

- The project uses Docker volumes for persistent data.
- NGINX listens only on port `443`.
- The WordPress database is MariaDB, reached by the service name `mariadb`.
