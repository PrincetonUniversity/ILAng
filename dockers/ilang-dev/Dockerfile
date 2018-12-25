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

RUN /bin/bash -c "source setup.sh"

CMD ["/bin/bash"]

