sudo apt-get update --yes

#sudo apt-get install git-all --yes
#sudo apt-get install wget --yes
#sudo apt-get install build-essential --yes

sudo apt-get install g++ --yes
sudo apt-get install libtool --yes
sudo apt-get install autoconf --yes

# boost
sudo mv /var/cache/apt/archives/lock /var/cache/apt/archives/lock_bak
sudo apt-get install libboost-all-dev --yes

# cmake
sudo apt-get install cmake3

#wget https://cmake.org/files/v3.10/cmake-3.10.2.tar.gz
#tar zxvf cmake-3.10.2.tar.gz
#cd cmake-3.10.2
#./bootstrap
#make -j8 && sudo make install

# z3
cd ~
git clone https://github.com/Z3Prover/z3.git
cd z3
python scripts/mk_make.py
cd build
make -j8 && sudo make install

# glog
cd ~
git clone https://github.com/google/glog.git
cd glog
mkdir -p build
cd build
cmake ..
make -j8 && sudo make install

# ILA
cd ~
git clone https://github.com/Bo-Yuan-Huang/ILA-Tools.git
cd ILA-Tools
mkdir -p build
cd build
cmake .. -DZ3_INCLDUE_DIR=/usr/include -Djson-inout=OFF
make -j8 && sudo make install
make run_test

