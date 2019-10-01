#!/bin/bash

CI_BUILD_DIR=$1

cd $CI_BUILD_DIR
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DBoost_NO_BOOST_CMAKE=ON
make -j$(nproc)
sudo make install
make run_test
ctest -R ExampleCMakeBuild
