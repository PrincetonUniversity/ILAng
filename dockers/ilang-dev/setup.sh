#!/bin/bash
##
## before install
##
DEBIAN_FRONTEND=noninteractive apt install --yes git

export DOCKER_WORK_ROOT=$(pwd)
export DOCKER_TOOL_ROOT=$DOCKER_WORK_ROOT/packages
mkdir -p $DOCKER_TOOL_ROOT

##
## install: z3
##
cd $DOCKER_TOOL_ROOT
git clone https://github.com/Z3Prover/z3.git
cd z3
git checkout tags/z3-4.7.1 -b v471
python scripts/mk_make.py
cd build
make
make install
z3 --version

##
## build script
##
cd $DOCKER_TOOL_ROOT
git clone https://github.com/Bo-Yuan-Huang/ILA-Tools.git
cd ILA-Tools
mkdir -p build
cd build
cmake .. -DILANG_INSTALL_DEV=ON
make
make install
make test

##
## configure example
##
cp -r $DOCKER_TOOL_ROOT/ILA-Tools/examples/simple $DOCKER_WORK_ROOT/example
