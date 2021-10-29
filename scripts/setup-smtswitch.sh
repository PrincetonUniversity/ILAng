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

SRC_DIR=$1
DEP_DIR=$2
Z3_VERSION=tags/z3-4.8.12

# fetch smt-switch
cd $SRC_DIR
git submodule update --init extern/smt-switch

# setup dir for SMT solvers
mkdir -p $SRC_DIR/extern/smt-switch/deps

# fetch/build/install z3
cd $SRC_DIR/extern/smt-switch/deps
git clone https://github.com/Z3Prover/z3.git
cd z3
git checkout $Z3_VERSION
python3 scripts/mk_make.py --staticlib --single-threaded --prefix=$DEP_DIR
cd build
make -j$(nproc)
make install

#fetch/build boolector
cd $SRC_DIR/extern/smt-switch
source contrib/setup-btor.sh

#build/install smt-switch
mkdir -p $SRC_DIR/extern/smt-switch/build
cd $SRC_DIR/extern/smt-switch
./configure.sh --static --btor --z3 --prefix=$DEP_DIR
cd build
make -j$(nproc)
make install
