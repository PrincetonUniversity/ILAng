FROM ubuntu:bionic as builder

# var
ENV VIRT_ENV ilang-env
ENV BUILD_ROOT /ibuild
ENV BUILD_PREF $BUILD_ROOT/$VIRT_ENV

# root dir
WORKDIR $BUILD_ROOT

# build packages
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
    bison \
    build-essential \
    cmake \
    expect \
    flex \
    gawk \
    git \
    graphviz \
    libboost-all-dev \
    libreadline-dev \
    libffi-dev \
    pkg-config \
    python3 \
    python3-pip \
    tcl-dev \
    vim \
    wget \
    xdot \
    && rm -rf /var/lib/apt/lists/*

# portable build result
RUN pip3 install virtualenv 
RUN virtualenv $VIRT_ENV

# z3
ENV Z3_DIR $BUILD_ROOT/z3
RUN wget https://github.com/Z3Prover/z3/releases/download/z3-4.7.1/z3-4.7.1.tar.gz
RUN mkdir -p $Z3_DIR && tar zxvf z3-4.7.1.tar.gz -C $Z3_DIR --strip-components 1
RUN cd $Z3_DIR && \
    $BUILD_PREF/bin/python scripts/mk_make.py --prefix=$BUILD_PREF --python && \
    cd build && \
    make -j$(nproc) && \
    make install

# Yosys
ENV YOSYS_DIR $BUILD_ROOT/yosys
RUN wget https://github.com/cliffordwolf/yosys/archive/yosys-0.8.tar.gz
RUN mkdir -p $YOSYS_DIR && tar zxvf yosys-0.8.tar.gz -C $YOSYS_DIR --strip-components 1
RUN cd $YOSYS_DIR && \
    make config-gcc && \
    make -j$(nproc) && \
    PREFIX=$BUILD_PREF make install

# ILAng
ENV ILANG_DIR $BUILD_ROOT/ILA-Tools
ADD https://api.github.com/repos/Bo-Yuan-Huang/ILA-Tools/git/refs/heads/master ilang_version.json
RUN git clone --depth=1 https://github.com/Bo-Yuan-Huang/ILA-Tools.git $ILANG_DIR
RUN cd $ILANG_DIR && \
    mkdir -p build && \
    cd build && \
    cmake .. -DCMAKE_INSTALL_PREFIX=$BUILD_PREF -DILANG_INSTALL_DEV=ON -DILANG_BUILD_TEST=OFF -DILANG_BUILD_SYNTH=OFF && \
    make -j$(nproc) && \
    make install 

# CoSA
ENV COSA_DIR $BUILD_ROOT/CoSA
ADD https://api.github.com/repos/cristian-mattarei/CoSA/git/refs/heads/master cosa_version.json
RUN git clone https://github.com/cristian-mattarei/CoSA.git $COSA_DIR
RUN cd $COSA_DIR && \
    git checkout remotes/origin/dev -b dev
RUN cd $COSA_DIR && \
    $BUILD_PREF/bin/pip3 install -e .

#
# Deployment
#
FROM ubuntu:bionic

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
    bison \
    build-essential \
    cmake \
    flex \
    gawk \
    libboost-all-dev \
    libreadline-dev \
    libffi-dev \
    python3 \
    tcl-dev \
    vim \
    && rm -rf /var/lib/apt/lists/*

ENV VIRT_ENV ilang-env
ENV BUILD_ROOT /ibuild
ENV BUILD_PREF $BUILD_ROOT/$VIRT_ENV

WORKDIR $BUILD_ROOT

RUN echo "source $BUILD_PREF/bin/activate" >> ~/.bashrc
RUN echo "export PYTHONPATH=$BUILD_ROOT/CoSA/:\$PYTHONPATH" >> ~/.bashrc

# configure files
COPY --from=builder $BUILD_PREF $BUILD_PREF
COPY --from=builder $BUILD_ROOT/CoSA/ ./CoSA/
COPY --from=builder $BUILD_ROOT/ILA-Tools/apps/acc_spec/aes/ ./aes-demo/

# build aes demo
RUN cd aes-demo && \ 
    mkdir -p build && \
    cd build && \ 
    cmake .. -DCMAKE_PREFIX_PATH=$BUILD_PREF && \
    make
RUN cd aes-demo/build && ./AESExe

# done
CMD ["/bin/bash"]

