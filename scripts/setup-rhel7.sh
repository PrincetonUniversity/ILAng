#!/usr/bin/bash
# bash script to set up environment for ILAng development
export BUILD_ROOT=$(pwd)
export BUILD_PREFIX=$BUILD_ROOT/ilang-env
export BUILD_DOWNLOAD=$BUILD_ROOT/ilang-env-dw

virtualenv ilang-env
source ilang-env/bin/activate
mkdir -p $BUILD_DOWNLOAD

# build, boost, bison, flex
sudo yum install -y make automake gcc gcc-c++ boost-devel bison bison-devel flex flex-devel

# cmake
cd $BUILD_DOWNLOAD
wget https://github.com/Kitware/CMake/releases/download/v3.12.4/cmake-3.12.4-Linux-x86_64.tar.gz
tar zxvf cmake-3.12.4-Linux-x86_64.tar.gz
cd cmake-3.12.4-Linux-x86_64
cp -R * $BUILD_PREFIX
export CMAKD_PREFIX_PATH=$BUILD_PREFIX

# z3
cd $BUILD_DOWNLOAD
wget https://github.com/Z3Prover/z3/releases/download/z3-4.7.1/z3-4.7.1.tar.gz
tar zxvf z3-4.7.1.tar.gz
cd z3rel
python scripts/mk_make.py --prefix=$BUILD_PREFIX
cd build
make -j$(nproc)
make install

# ILAng
cd $BUILD_DOWNLOAD
git clone --depth=1 https://github.com/Bo-Yuan-Huang/ILA-Tools.git
cd ILA-Tools
git submodule update --init --recursive
mkdir -p build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=$BUILD_PREFIX -DILANG_INSTALL_DEV=ON -DILANG_FETCH_DEPS=OFF -DILANG_BUILD_SYNTH=OFF -DILANG_BUILD_TEST=OFF
make -j$(nproc)
make install

# configure simple
cp -r $BUILD_DOWNLOAD/ILA-Tools/examples/simple/ $BUILD_ROOT/simple/
