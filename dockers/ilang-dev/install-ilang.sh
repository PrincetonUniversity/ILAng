#!/bin/bash

export CURRENT_DIR=$(pwd)

git clone https://github.com/Bo-Yuan-Huang/ILA-Tools.git
cd ILA-Tools
mkdir -p build
cd build
cmake .. -DILANG_INSTALL_DEV=ON
make
make install
make test

cd $CURRENT_DIR
rm -rf ILA-Tools

