# initialize and fetch the build script from the GitHub repo
apt-get update --yes
apt-get install git-all --yes
export BUILD_DIR=$(pwd)

cd $BUILD_DIR
if [ ! -d "ILA-Tools" ]; then
  git clone https://github.com/Bo-Yuan-Huang/ILA-Tools.git
  /bin/bash -c "source $BUILD_DIR/ILA-Tools/docker-scripts/build-xenial.sh"
fi

