*This project has been created as part of the 42 curriculum by dbohoyo-.*

# Inception

## Description

Inception is a system administration project from the 42 curriculum focused on containerization using Docker. The objective is to design and deploy a small infrastructure composed of multiple interconnected services running inside Docker containers.

The project introduces the concepts of virtualization, container orchestration, networking, persistent storage, and secure configuration management. The infrastructure is defined using Docker Compose and must be built following specific constraints imposed by the subject.

The mandatory part of the project consists of creating a Docker-based environment including:

* An NGINX container configured with TLS.
* A WordPress container running with PHP-FPM.
* A MariaDB container for database management.
* Persistent storage for both the database and WordPress files.
* A dedicated Docker network allowing communication between services.
* Proper use of environment variables and secrets.

The main goal of this project is to understand how modern applications are deployed using isolated services while ensuring maintainability, reproducibility, and security.

---

## Instructions

### Requirements

* Docker — required to run containers.
* Docker Compose — required to orchestrate the multi-container setup.
* OS: 64-bit Debian.
* Disk: 15-20 GB available for the VM.
* RAM: 2-4 GB.
* CPU: 2 cores (recommended)
* Browser to test the site.

### Installation

Clone the repository:

```bash
git clone git@vogsphere.42malaga.com:vogsphere/intra-uuid-83eae8a2-3874-4f0f-957e-987af4c994f2-7095003-dbohoyo-
```

### Build and Run

Build and start all containers:

```bash
make
```

or explicitly:

```bash
make up
```

This uses the Docker Compose file defined in the Makefile and starts the services in detached mode with build enabled.

### Stop the Infrastructure

```bash
make down
```

### Clean the Infrastructure

Remove containers, networks and volumes:

```bash
make clean
```

Remove everything related to the project, including images and volumes:

```bash
make fclean
```

Rebuild everything from scratch:

```bash
make re
```

---

## Resources

### Official Documentation

* Docker Documentation:
  https://docs.docker.com/

* Docker Compose Documentation:
  https://docs.docker.com/compose/

* NGINX Documentation:
  https://nginx.org/en/docs/

* WordPress Documentation:
  https://developer.wordpress.org/

* MariaDB Documentation:
  https://mariadb.com/kb/en/documentation/

* PHP-FPM Documentation:
  https://www.php.net/manual/en/install.fpm.php

---

### Tutorials and Articles

* Docker — Get Started: https://docs.docker.com/get-started/
* Docker Compose — Getting Started: https://docs.docker.com/compose/gettingstarted/
* Dockerfile best practices: https://docs.docker.com/develop/develop-images/dockerfile_best-practices/
* Docker networking overview: https://docs.docker.com/network/
* NGINX documentation & beginner guides: https://nginx.org/en/docs/
* WordPress installation guide: https://wordpress.org/support/article/how-to-install-wordpress/
* MariaDB getting started: https://mariadb.com/kb/en/getting-started-with-mariadb/
* TLS / Let's Encrypt: https://letsencrypt.org/getting-started/
* Practical tutorial: Docker Curriculum — https://docker-curriculum.com/

---

### Use of Artificial Intelligence

Artificial intelligence tools were used as supplementary learning aids during the development of this project.

AI assistance was limited to:

* Clarifying Docker concepts and terminology.
* Explaining documentation and subject requirements.
* Reviewing written documentation and improving readability.
* Answering conceptual questions related to containerization.

All architectural decisions, implementation, configuration, debugging, and validation of the project were performed and verified by the author.

---

## Project Description

### Docker Usage

Docker was chosen to isolate each service into independent containers. This approach simplifies deployment, improves portability, and ensures that the application behaves consistently across different environments.

Each service is responsible for a single task:

* **NGINX:** reverse proxy and TLS termination.
* **WordPress:** PHP application serving the website.
* **MariaDB:** persistent relational database.

Docker Compose coordinates these services, networks, and volumes through declarative configuration.

### Sources Included in the Project

The project infrastructure is built from custom Dockerfiles and Docker Compose definitions.

Main technologies used:

* Docker
* Docker Compose
* NGINX
* WordPress
* PHP-FPM
* MariaDB
* TLS/SSL certificates

---

## Technical Comparisons

### Virtual Machines vs Docker

#### Virtual Machines

**Advantages:**

* Full operating system isolation.
* Strong separation between environments.
* Suitable for running different operating systems simultaneously.

**Disadvantages:**

* Higher resource consumption.
* Slower startup times.
* Larger storage requirements.

#### Docker Containers

**Advantages:**

* Lightweight and efficient.
* Fast startup.
* Share the host kernel.
* Easy to reproduce and distribute.

**Disadvantages:**

* Weaker isolation compared to full virtual machines.
* Containers depend on the host kernel.

Docker is generally preferred for microservices and modern deployment workflows due to its efficiency.

---

### Secrets vs Environment Variables

#### Environment Variables

Environment variables store configuration values accessible to applications.

**Advantages:**

* Easy to configure.
* Simple integration.

**Disadvantages:**

* Values can sometimes be exposed through logs or inspection commands.
* Not intended for highly sensitive information.

Examples:

* Domain names
* Ports
* Application settings

#### Secrets

Secrets provide a secure mechanism for storing sensitive information.

**Advantages:**

* Restricted access.
* Better protection of confidential data.

**Disadvantages:**

* Slightly more complex setup.

Examples:

* Database passwords
* API keys
* Authentication credentials

Sensitive information should always be managed using secrets whenever possible.

---

### Docker Network vs Host Network

#### Docker Network

Containers communicate through an isolated virtual network.

**Advantages:**

* Improved security.
* Service discovery using container names.
* Better traffic isolation.

**Disadvantages:**

* Slight networking overhead.

#### Host Network

Containers share the host's network stack.

**Advantages:**

* Reduced overhead.
* Direct access to host interfaces.

**Disadvantages:**

* Lower isolation.
* Greater exposure to conflicts and security concerns.

Docker networks are generally preferred because they provide better separation between services.

---

### Docker Volumes vs Bind Mounts

#### Docker Volumes

Managed directly by Docker.

**Advantages:**

* Easier backup and migration.
* Better portability.
* Independent of host directory structure.

**Disadvantages:**

* Less transparent from the host filesystem.

Used in this project for persistent application and database data.

#### Bind Mounts

Map host directories directly into containers.

**Advantages:**

* Easy access to files from the host.
* Convenient during development.

**Disadvantages:**

* Depend on host paths.
* Reduced portability.

Volumes are usually preferred in production environments, while bind mounts are useful during development.

---

## Author

* **42 Login:** dbohoyo-
