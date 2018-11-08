# initialize and fetch the build script from the GitHub repo
sudo apt-get update --yes
sudo apt-get install git-all --yes
export BUILD_DIR=$(pwd)

cd $BUILD_DIR
if [ ! -d "ILA-Tools" ]; then
  git clone https://github.com/Bo-Yuan-Huang/ILA-Tools.git
  /bin/bash -c "source $BUILD_DIR/ILA-Tools/docker-scripts/build-trusty.sh"
fi

