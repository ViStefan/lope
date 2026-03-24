FROM debian:latest

WORKDIR /lope_test

RUN apt-get update && apt-get install -y --no-install-recommends \
  zsh \
  && rm -rf /var/lib/apt/lists/*

CMD ["/bin/sh", "-c", "./test/check.sh"]
