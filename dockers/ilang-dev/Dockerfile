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
    cmake .. -DCMAKE_INSTALL_PREFIX=$BUILD_PREF -DILANG_INSTALL_DEV=ON && \
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

# Boolector
ENV BTOR_DIR $BUILD_ROOT/Boolector
ADD https://api.github.com/repos/Boolector/boolector/git/refs/heads/master btor_version.json
RUN git clone --depth=1 https://github.com/Boolector/boolector.git $BTOR_DIR
RUN pip3 install cython
RUN cd $BTOR_DIR && ./contrib/setup-lingeling.sh 
RUN cd $BTOR_DIR && ./contrib/setup-cadical.sh
RUN cd $BTOR_DIR && ./contrib/setup-btor2tools.sh
RUN cd $BTOR_DIR && ./configure.sh --python --py3 --prefix $BUILD_PREF
RUN cd $BTOR_DIR/build && \
    make -j$(nproc) && \
    make install

# PySMT
RUN wget https://raw.githubusercontent.com/makaimann/pysmt/fast/pysmt/solvers/btor.py 
RUN mv btor.py btor-solver.py
RUN cp btor-solver.py $BUILD_PREF/lib/python3.6/site-packages/pysmt/solvers/btor.py
RUN wget https://raw.githubusercontent.com/makaimann/pysmt/fast/pysmt/cmd/installers/btor.py 
RUN mv btor.py btor-installer.py
RUN cp btor-installer.py /ibuild/ilang-env/lib/python3.6/site-packages/pysmt/cmd/installers/btor.py

#
# Deployment
#
FROM ubuntu:bionic

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
    bison \
    build-essential \
    cmake \
    flex \
    git \
    libboost-all-dev \
    libgomp1 \
    pkg-config \
    python3 \
    python3-pip \
    tcl-dev \
    vim \
    wget \
    && rm -rf /var/lib/apt/lists/*

ENV VIRT_ENV ilang-env
ENV BUILD_ROOT /ibuild
ENV BUILD_PREF $BUILD_ROOT/$VIRT_ENV

WORKDIR ~/workspace

RUN echo "source $BUILD_PREF/bin/activate" >> init.sh
RUN echo "export PYTHONPATH=$BUILD_PREF/lib:\$PYTHONPATH" >> init.sh
RUN echo "export CMAKE_PREFIX_PATH=$BUILD_PREF:\$CMAKE_PREFIX_PATH" >> init.sh
RUN echo "cd $(pwd)" >> init.sh

# configure files
COPY --from=builder $BUILD_PREF $BUILD_PREF
COPY --from=builder $BUILD_ROOT/CoSA/ $BUILD_ROOT/CoSA/
COPY --from=builder $BUILD_ROOT/ILA-Tools/examples/simple/ ./simple/

# done
CMD echo "run 'source init.sh' to start" && /bin/bash

