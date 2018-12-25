#!/bin/bash

export CURRENT_DIR=$(pwd)

git clone https://github.com/Z3Prover/z3.git
cd z3
git checkout tags/z3-4.7.1 -b v471
python scripts/mk_make.py
cd build
make
make install

cd $CURRENT_DIR
rm -rf z3
z3 --version

