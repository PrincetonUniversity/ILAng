sudo apt-get update --yes

sudo apt-get install g++ --yes
sudo apt-get install libtool --yes
sudo apt-get install autoconf --yes
sudo apt-get install flex bison --yes

# boost
sudo mv /var/cache/apt/archives/lock /var/cache/apt/archives/lock_bak
sudo apt-get install libboost-all-dev --yes

# cmake
sudo apt-get install cmake --yes

#set BUILD_DIR=$pwd

# z3
cd $BUILD_DIR
git clone https://github.com/Z3Prover/z3.git
cd $BUILD_DIR/z3
python scripts/mk_make.py
cd build
make -j8 && sudo make install

# glog
cd $BUILD_DIR
git clone https://github.com/google/glog.git
cd glog
mkdir -p build
cd build
cmake ..
make -j8 && sudo make install

# ILA
cd $BUILD_DIR/ILA-Tools
mkdir -p build
cd build
cmake .. -DZ3_INCLUDE_DIR=/usr/include -Djson-inout=OFF
make -j8 && sudo make install
make run_test

