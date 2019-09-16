#!/bin/bash

CI_BUILD_DIR=$1

cd $CI_BUILD_DIR
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DILANG_BUILD_COV=ON
make -j$(nproc)
sudo make install
make run_test
ctest -R ExampleCMakeBuild
