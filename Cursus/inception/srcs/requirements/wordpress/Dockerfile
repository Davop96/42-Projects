FROM	debian:bookworm

#installs the necessary dependencies
RUN	apt update && apt install -y php8.2-fpm php8.2-mysql curl mariadb-client

#installs the necessary PHP extensions
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

COPY	conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf
COPY	tools/wp.sh /usr/local/bin/wp.sh

RUN	chmod +x /usr/local/bin/wp.sh

CMD ["/usr/local/bin/wp.sh"]