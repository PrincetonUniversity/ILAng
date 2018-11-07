sudo apt-get update --yes

#sudo apt-get install git-all --yes
#sudo apt-get install wget --yes
#sudo apt-get install build-essential --yes

sudo apt-get install g++ --yes
sudo apt-get install libtool --yes
sudo apt-get install autoconf --yes
sudo apt-get install flex bison --yes

# boost
sudo mv /var/cache/apt/archives/lock /var/cache/apt/archives/lock_bak
sudo apt-get install libboost-all-dev --yes

# cmake
sudo apt-get install cmake3 --yes

#wget https://cmake.org/files/v3.10/cmake-3.10.2.tar.gz
#tar zxvf cmake-3.10.2.tar.gz
#cd cmake-3.10.2
#./bootstrap
#make -j8 && sudo make install

set ROOT_DIR=$pwd

# z3
cd $ROOT_DIR
git clone https://github.com/Z3Prover/z3.git
cd $ROOT_DIR/z3
python scripts/mk_make.py
cd build
make -j8 && sudo make install

# glog
cd $ROOT_DIR
git clone https://github.com/google/glog.git
cd glog
mkdir -p build
cd build
cmake ..
make -j8 && sudo make install

# ILA
cd $ROOT_DIR/ILA-Tools
#git clone https://github.com/Bo-Yuan-Huang/ILA-Tools.git
#cd ILA-Tools
#git pull
mkdir -p build
cd build
cmake .. -DZ3_INCLUDE_DIR=/usr/include -Djson-inout=OFF
make -j8 && sudo make install
make run_test

