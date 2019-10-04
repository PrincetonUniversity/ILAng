#!/bin/bash

CI_BUILD_DIR=$1

cd $CI_BUILD_DIR
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DILANG_COVERITY=ON -DILANG_BUILD_TEST=OFF
make -j$(nproc)
