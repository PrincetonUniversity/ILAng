# initialize and fetch the build script from the GitHub repo
apt update
apt upgrade --yes
DEBIAN_FRONTEND=noninteractive apt install git-all --yes
export BUILD_DIR=$(pwd)

cd $BUILD_DIR
if [ ! -d "ILA-Tools" ]; then
  git clone https://github.com/Bo-Yuan-Huang/ILA-Tools.git
  /bin/bash -c "source $BUILD_DIR/ILA-Tools/docker-scripts/build-bionic.sh"
fi

