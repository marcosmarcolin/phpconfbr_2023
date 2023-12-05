FROM debian:bullseye-slim

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y wget nano ca-certificates lsb-release gnupg build-essential libssl-dev libcurl4-openssl-dev && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN wget -O /etc/apt/trusted.gpg.d/php.gpg https://packages.sury.org/php/apt.gpg
RUN echo "deb https://packages.sury.org/php/ $(lsb_release -sc) main" > /etc/apt/sources.list.d/php.list

RUN apt-get update && \
    apt-get install -y php8.3-cli php8.3-readline php8.3-dev && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /var/www

CMD ["/bin/bash"]
