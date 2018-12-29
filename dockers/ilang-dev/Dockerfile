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
    flex \
    git \
    libboost-all-dev \
    python-pip \
    vim \
    wget \
    && rm -rf /var/lib/apt/lists/*

# portable build result
RUN pip install virtualenv
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

# ILAng
ENV ILANG_DIR $BUILD_ROOT/ILA-Tools
ADD https://api.github.com/repos/Bo-Yuan-Huang/ILA-Tools/git/refs/heads/master ilang_version.json
RUN git clone --depth=1 https://github.com/Bo-Yuan-Huang/ILA-Tools.git $ILANG_DIR
RUN cd $ILANG_DIR && \
    mkdir -p build && \
    cd build && \
    cmake .. -DCMAKE_INSTALL_PREFIX=$BUILD_PREF -DILANG_INSTALL_DEV=ON && \
    make -j$(nproc) && \
    make install 

#
# Deployment
#
FROM ubuntu:bionic

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
    bison \
    build-essential \
    cmake \
    flex \
    libboost-all-dev \
    vim \
    && rm -rf /var/lib/apt/lists/*

ENV VIRT_ENV ilang-env
ENV BUILD_ROOT /ibuild
ENV BUILD_PREF $BUILD_ROOT/$VIRT_ENV

WORKDIR $BUILD_ROOT

COPY --from=builder $BUILD_PREF $BUILD_PREF
COPY --from=builder $BUILD_ROOT/ILA-Tools/examples/simple/ ./example/

RUN echo "source $BUILD_PREF/bin/activate" >> ~/.bashrc

# done
CMD ["/bin/bash"]

