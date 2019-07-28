#!/bin/bash

CI_BUILD_DIR=$1

cd $CI_BUILD_DIR
mkdir -p build
cd build
cmake .. -DILANG_BUILD_COV=ON -DCMAKE_BUILD_TYPE=Debug
make -j$(nproc)
sudo make install
make test

