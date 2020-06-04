#!/bin/sh

# ==============================================================================
# MIT License
#
# Copyright (c) 2019 Princeton University
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
# ==============================================================================

CI_BUILD_DIR=$1

# smt-switch with Boolector
git submodule update --init extern/smt-switch
cd $CI_BUILD_DIR/extern/smt-switch
source contrib/setup-btor.sh
mkdir -p $CI_BUILD_DIR/extern/smt-switch/build
cmake .. -DBUILD_BTOR=ON
make -j$(nproc)
sudo make install

cd $CI_BUILD_DIR
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DILANG_BUILD_COV=ON -DILANG_BUILD_SWITCH=ON
make -j$(nproc)
sudo make install
make run_test
ctest -R ExampleCMakeBuild
