FROM ubuntu:bionic as builder

WORKDIR /app

RUN apt-get update && apt-get install -y \
  bison \
  build-essential \
  cmake \
  flex \
  git \
  libboost-all-dev \
  vim \
  && rm -rf /var/lib/apt/lists/*

# z3
ENV Z3_TAG z3-4.7.1
ENV Z3_DIR /app/z3

RUN git clone -b $Z3_TAG https://github.com/Z3Prover/z3.git $Z3_DIR/
RUN cd $Z3_DIR && \
    python scripts/mk_make.py --prefix=/app/local-build && \
    cd build && \
    make -j$(nproc) && \
    make install

# ilang
ENV ILANG_DIR /app/ILA-Tools

ADD https://api.github.com/repos/Bo-Yuan-Huang/ILA-Tools/git/refs/heads/master ilang_version.json
RUN git clone --depth=1 https://github.com/Bo-Yuan-Huang/ILA-Tools.git $ILANG_DIR
RUN cd $ILANG_DIR && \
    mkdir -p build && \
    cd build && \
    cmake .. -DILANG_INSTALL_DEV=ON -DCMAKE_INSTALL_PREFIX=/app/local-build && \
    make -j$(nproc) && \
    make install 
RUN cp -r $ILANG_DIR/examples/simple /app/example

#
# multi stage
#
FROM ubuntu:bionic

WORKDIR /app

RUN apt-get update && apt-get install -y \
  bison \
  build-essential \
  cmake \
  flex \
  git \
  libboost-all-dev \
  vim \
  && rm -rf /var/lib/apt/lists/*

# add user account
RUN groupadd -r ilang && useradd --no-log-init -r -g ilang ilang
USER ilang

# configure files
COPY --from=builder /app/local-build/ /app/local-build/
COPY --from=builder --chown=ilang /app/example/ /app/example/

# done
CMD ["/bin/bash"]

