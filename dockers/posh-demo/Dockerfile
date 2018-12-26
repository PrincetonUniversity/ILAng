FROM ubuntu:bionic as builder

WORKDIR /app

RUN apt-get update && apt-get install -y \
  bison \
  build-essential \
  cmake \
  flex \
  git \
  libboost-all-dev \
  python3-pip \
  vim \
  && rm -rf /var/lib/apt/lists/*

#RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y expect

# portable build result
ENV VENV ilang-venv
ENV PREF /app/$VENV
RUN pip3 install virtualenv 
RUN virtualenv $VENV

# z3
ENV Z3_TAG z3-4.7.1
ENV Z3_DIR /app/z3

RUN git clone -b $Z3_TAG https://github.com/Z3Prover/z3.git $Z3_DIR/
RUN cd $Z3_DIR && \
    python scripts/mk_make.py --prefix= $PREF && \
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
    cmake .. -DILANG_INSTALL_DEV=ON -DCMAKE_INSTALL_PREFIX=$PREF && \
    make -j$(nproc) && \
    make install 
RUN cp -r $ILANG_DIR/examples/simple /app/example

# cosa
RUN $VENV/bin/pip3 install cosa

# boolector
ENV BTOR_DIR pysmt_solvers 
ENV BTOR_PY --py3
RUN mkdir $BTOR_DIR
RUN git clone https://github.com/Boolector/boolector
RUN $VENV/bin/pip3 install cython
RUN cd boolector && \
    ./contrib/setup-lingeling.sh && \
    ./contrib/setup-cadical.sh && \
    ./contrib/setup-btor2tools.sh && \
    ./configure.sh --python $BTOR_PY && \
    cd build && \
    make -j$(nproc) && \
    cp ./lib/* ../../$BTOR_DIR/

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
#COPY --from=builder /app/local-build/ /app/local-build/
COPY --from=builder --chown=ilang /app/example/ /app/example/
COPY --from=builder /app/ilang-venv/ /app/ilang-venv/
COPY --from=builder /app/pysmt_solvers /app/pysmt_solvers

# done
CMD ["/bin/bash"]

