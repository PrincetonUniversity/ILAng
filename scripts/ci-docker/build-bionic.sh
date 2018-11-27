apt-get update --yes

apt-get install g++ --yes
apt-get install libtool --yes
apt-get install autoconf --yes
apt-get install flex bison --yes

# boost
apt-get install libboost-all-dev --yes

# cmake
apt-get install cmake --yes

#set BUILD_DIR=$pwd

# z3
cd $BUILD_DIR
git clone https://github.com/Z3Prover/z3.git
cd $BUILD_DIR/z3
python scripts/mk_make.py
cd build
make -j8 && make install

# glog
cd $BUILD_DIR
git clone https://github.com/google/glog.git
cd glog
mkdir -p build
cd build
cmake ..
make -j8 && make install

# ILA
cd $BUILD_DIR/ILA-Tools
mkdir -p build
cd build
cmake .. -DZ3_INCLUDE_DIR=/usr/include 
make -j8 && make install
make run_test

