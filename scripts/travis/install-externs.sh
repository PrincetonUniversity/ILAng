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

git submodule update --init --recursive
mkdir -p $CI_BUILD_DIR/local

# glog
mkdir -p $CI_BUILD_DIR/extern/glog/build
cd $CI_BUILD_DIR/extern/glog/build
cmake .. -DCMAKE_INSTALL_PREFIX=$CI_BUILD_DIR/local
cmake --build . --target install

# json
mkdir -p $CI_BUILD_DIR/extern/json/build
cd $CI_BUILD_DIR/extern/json/build
cmake .. -DCMAKE_INSTALL_PREFIX=$CI_BUILD_DIR/local
cmake --build . --target install

# vlog-parser
mkdir -p $CI_BUILD_DIR/extern/vlog-parser/build
cd $CI_BUILD_DIR/extern/vlog-parser/build
cmake .. -DCMAKE_INSTALL_PREFIX=$CI_BUILD_DIR/local
cmake --build . --target install

# smt-switch with Boolector
cd $CI_BUILD_DIR/extern/smt-switch
source contrib/setup-btor.sh
mkdir -p $CI_BUILD_DIR/extern/smt-switch/build
cmake .. -DCMAKE_INSTALL_PREFIX=$CI_BUILD_DIR/local -DBUILD_BTOR=ON
cmake --build . --target install
