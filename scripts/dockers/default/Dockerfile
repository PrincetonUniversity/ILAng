FROM ubuntu:bionic as builder

# var
ENV VIRT_ENV ilang-env
ENV BUILD_ROOT /ibuild
ENV BUILD_PREF $BUILD_ROOT/$VIRT_ENV

# root dir
WORKDIR $BUILD_ROOT

# build packages
RUN apt update && DEBIAN_FRONTEND=noninteractive apt install --yes --no-install-recommends \
    bison=2:3.0.4.dfsg-1build1 \
    build-essential=12.4ubuntu1 \
    cmake=3.10.2-1ubuntu2 \
    expect=5.45.4-1 \
    flex=2.6.4-6 \
    gawk=1:4.1.4+dfsg-1build1 \
    git=1:2.17.1-1ubuntu0.4 \
    graphviz=2.40.1-2 \
    libboost-all-dev=1.65.1.0ubuntu1 \
    libreadline-dev=7.0-3 \
    libffi-dev=3.2.1-8 \
    pkg-config=0.29.1-0ubuntu2 \
    python3=3.6.7-1~18.04 \
    python3-pip=9.0.1-2.3~ubuntu1 \
    tcl-dev=8.6.0+9 \
    vim=2:8.0.1453-1ubuntu1 \
    wget=1.19.4-1ubuntu2.1 \
    xdot=0.9-1 \
    && rm -rf /var/lib/apt/lists/*

# portable build result
WORKDIR $BUILD_ROOT
RUN pip3 install virtualenv==16.2.0
RUN virtualenv $VIRT_ENV

# z3
ENV Z3_DIR $BUILD_ROOT/z3
WORKDIR $BUILD_ROOT
RUN wget https://github.com/Z3Prover/z3/releases/download/z3-4.7.1/z3-4.7.1.tar.gz
RUN mkdir -p $Z3_DIR 
RUN tar zxvf z3-4.7.1.tar.gz -C $Z3_DIR --strip-components 1
WORKDIR $Z3_DIR 
RUN $BUILD_PREF/bin/python scripts/mk_make.py --prefix=$BUILD_PREF --python 
WORKDIR $Z3_DIR/build
RUN make -j$(nproc) && \
    make install

# Yosys
ENV YOSYS_DIR $BUILD_ROOT/yosys
WORKDIR $BUILD_ROOT
RUN wget https://github.com/cliffordwolf/yosys/archive/yosys-0.8.tar.gz
RUN mkdir -p $YOSYS_DIR 
RUN tar zxvf yosys-0.8.tar.gz -C $YOSYS_DIR --strip-components 1
WORKDIR $YOSYS_DIR 
RUN make config-gcc && \
    make -j$(nproc) && \
    PREFIX=$BUILD_PREF make install

# CoSA
ENV COSA_DIR $BUILD_ROOT/CoSA
WORKDIR $BUILD_ROOT
ADD https://api.github.com/repos/cristian-mattarei/CoSA/git/refs/heads/master cosa_version.json
RUN git clone https://github.com/cristian-mattarei/CoSA.git $COSA_DIR
WORKDIR $COSA_DIR
RUN git checkout remotes/origin/dev -b dev
RUN $BUILD_PREF/bin/pip3 install -e .

# Boolector
ENV BTOR_DIR $BUILD_ROOT/Boolector
WORKDIR $BUILD_ROOT
ADD https://api.github.com/repos/Boolector/boolector/git/refs/heads/master btor_version.json
RUN git clone --depth=1 https://github.com/Boolector/boolector.git $BTOR_DIR
RUN pip3 install cython==0.29.3
RUN cd $BTOR_DIR && ./contrib/setup-lingeling.sh 
WORKDIR $BTOR_DIR
RUN ./contrib/setup-cadical.sh
RUN ./contrib/setup-btor2tools.sh
RUN ./configure.sh --python --py3 --prefix $BUILD_PREF
WORKDIR $BTOR_DIR/build
RUN make -j$(nproc) && \
    make install

# PySMT
WORKDIR $BUILD_ROOT
RUN wget https://raw.githubusercontent.com/makaimann/pysmt/fast/pysmt/solvers/btor.py 
RUN mv btor.py btor-solver.py
RUN cp btor-solver.py $BUILD_PREF/lib/python3.6/site-packages/pysmt/solvers/btor.py
RUN wget https://raw.githubusercontent.com/makaimann/pysmt/fast/pysmt/cmd/installers/btor.py 
RUN mv btor.py btor-installer.py
RUN cp btor-installer.py /ibuild/ilang-env/lib/python3.6/site-packages/pysmt/cmd/installers/btor.py

# ILAng
ENV ILANG_DIR $BUILD_ROOT/ILAng
WORKDIR $BUILD_ROOT
ADD https://api.github.com/repos/Bo-Yuan-Huang/ILAng/git/refs/heads/master ilang_version.json
RUN git clone --depth=1 https://github.com/Bo-Yuan-Huang/ILAng.git $ILANG_DIR
WORKDIR $ILANG_DIR
RUN mkdir -p build 
WORKDIR $ILANG_DIR/build
RUN cmake .. -DCMAKE_INSTALL_PREFIX=$BUILD_PREF -DILANG_INSTALL_DEV=ON && \
    make -j$(nproc) && \
    make install 

#
# Deployment
#
FROM ubuntu:bionic

RUN apt update && DEBIAN_FRONTEND=noninteractive apt install --yes --no-install-recommends \
    bison=2:3.0.4.dfsg-1build1 \
    build-essential=12.4ubuntu1 \
    cmake=3.10.2-1ubuntu2 \
    flex=2.6.4-6 \
    git=1:2.17.1-1ubuntu0.4 \
    libboost-all-dev=1.65.1.0ubuntu1 \
    libgomp1=8.2.0-1ubuntu2~18.04 \
    pkg-config=0.29.1-0ubuntu2 \
    python3=3.6.7-1~18.04 \
    python3-pip=9.0.1-2.3~ubuntu1 \
    tcl-dev=8.6.0+9 \
    vim=2:8.0.1453-1ubuntu1 \
    wget=1.19.4-1ubuntu2.1 \
    && rm -rf /var/lib/apt/lists/*

ENV VIRT_ENV ilang-env
ENV BUILD_ROOT /ibuild
ENV BUILD_PREF $BUILD_ROOT/$VIRT_ENV

WORKDIR /root/workspace

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

