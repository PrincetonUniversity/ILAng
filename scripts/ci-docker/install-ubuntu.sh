export BUILD_DIR=$(pwd)


##
## build option
##
COMPILER=$1


##
## environment
##
apt-get update --yes
apt-get install --yes flex 
apt-get install --yes bison 
apt-get install --yes libboost-all-dev 

if ["$COMPILER" == "CLANG"]; then
  apt-get install --yes clang++ 
  apt-get install --yes libtool
  apt-get install --yes autoconf 
else 
  apt-get install --yes build-essential 
fi

DEBIAN_FRONTEND=noninteractive apt install --yes git-all

# cmake
cd $BUILD_DIR
git clone https://github.com/Kitware/CMake.git
cd CMake
git checkout tags/v3.8.0 -b v380
./bootstrap
make && make install


##
## third-party tools
##

# z3
cd $BUILD_DIR
git clone https://github.com/Z3Prover/z3.git
cd z3
mkdir -p build
cd build
cmake ..
make && make install

##
## build
##
cd $BUILD_DIR
git clone https://github.com/Bo-Yuan-Huang/ILA-Tools.git
cd ILA-Tools
mkdir -p build
cd build
cmake ..
make
make test
make install

