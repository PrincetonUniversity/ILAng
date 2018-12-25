FROM ubuntu:bionic

WORKDIR /app

COPY . /app

RUN apt-get update && apt-get install -y \
  bison \
  build-essential \
  cmake \
  flex \
  git \
  libboost-all-dev \
  vim

RUN /bin/bash -c "source install-z3.sh"

RUN /bin/bash -c "source install-ilang.sh"

RUN groupadd -r ilang && useradd --no-log-init -r -g ilang ilang

USER ilang

CMD ["/bin/bash"]

