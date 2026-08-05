# User Documentation

## Overview

This project deploys a small web infrastructure using Docker containers as part of the 42 Inception project.

The stack includes the following services:

| Service   | Description                                                |
| --------- | ---------------------------------------------------------- |
| NGINX     | Web server and reverse proxy with TLS support.             |
| WordPress | CMS used to serve the website.                             |
| MariaDB   | Database server used by WordPress.                         |

All services run in isolated containers and communicate through a dedicated Docker network.

---

## Project Configuration

The project is configured through the `.env` file and Docker secrets.

### Domain

The website is available at:

```text
https://dbohoyo-.42.fr
```

### Environment Variables

Main configuration values are stored in:

```text
srcs/.env
```

Relevant variables include:

- `DOMAIN_NAME=dbohoyo-.42.fr`
- `DEBIAN_USER=dbohoyo`
- `MYSQL_USER=dbohoyo-`
- `MYSQL_DATABASE=wordpress`
- `WORDPRESS_DB_HOST=mariadb`
- `WORDPRESS_DB_NAME=wordpress`
- `WORDPRESS_DB_USER=dbohoyo-`
- `WORDPRESS_URL=https://dbohoyo-.42.fr`
- `WORDPRESS_ADMIN_USER=superuser`
- `WORDPRESS_USER=dbohoyo-`

These values define the project configuration and should match the infrastructure being deployed.

### Secrets

Sensitive passwords are stored in the `secrets/` directory:

- `secrets/db_password.txt`
- `secrets/db_root_password.txt`
- `secrets/credentials.txt`

### Credentials

The project uses different credentials for different services:

- `srcs/.env` contains the main configuration values for the project.
- `secrets/db_password.txt` stores the MariaDB user password.
- `secrets/db_root_password.txt` stores the MariaDB root password.
- `secrets/credentials.txt` stores the WordPress administrator credentials used by the project setup.
- `DEBIAN_USER` and `DEBIAN_PASSWORD` are used for the Debian virtual machine user.

In this setup, the WordPress and MariaDB services read their credentials from the environment variables and secret files defined by the project.

Keep these values private and do not share them publicly.

---

## Starting the Project

From the project root, build and start the infrastructure with:

```bash
make
```

The `make` command runs the default target and starts the project.

You can also use:

```bash
make up
```

If the containers are running correctly, the following services should be available:

- `nginx`
- `wordpress`
- `mariadb`

To verify that the services are running correctly:

```bash
docker ps
```

You should see the `nginx`, `wordpress`, and `mariadb` containers in the running state.

You can also confirm the setup by opening the website in a browser and checking that the page loads correctly over HTTPS.

---

## Stopping the Project

To stop the infrastructure:

```bash
make down
```

To remove the containers, networks, and volumes, use:

```bash
make clean
```

To remove all project artifacts including images, use:

```bash
make fclean
```

To remove all project artifacts and rebuild everything from scratch, use:

```bash
make re
```

---

## Accessing the Website

Open a browser and go to:

```text
https://dbohoyo-.42.fr
```

The NGINX container should serve the WordPress site over HTTPS.

---

## Accessing WordPress Administration

The administration panel is available at:

```text
https://dbohoyo-.42.fr/wp-admin
```

Use the WordPress administrator username and password defined in `srcs/.env` and `secrets/`.

---

## Checking the Containers

To inspect the running containers:

```bash
docker ps
```

To view logs for a specific container:

```bash
docker logs <container_name>
```

Examples:

```bash
docker logs nginx
docker logs wordpress
docker logs mariadb
```

If a service is not working as expected, checking its logs is the first step to identify the issue.

---

## Troubleshooting

### The website does not open

Check that:

- Docker is running correctly.
- All containers are up.
- The domain resolves correctly.
- Port 443 is available.

### WordPress cannot connect to the database

Check that:

- MariaDB is running.
- The database credentials match the `.env` file.
- The `WORDPRESS_DB_HOST` value is correctly set to `mariadb`.

### TLS warning in the browser

Check the NGINX configuration and the certificate files generated for the project.

---

## Notes

This infrastructure is designed to be reproducible and isolated.
Each service runs in its own container, with persistent data stored in volumes.
```
