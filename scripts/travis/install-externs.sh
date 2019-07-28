#!/bin/bash        

CI_BUILD_DIR=$1

git submodule update --init --recursive
mkdir -p $CI_BUILD_DIR/build

# glog
mkdir -p $CI_BUILD_DIR/extern/glog/build
cd $CI_BUILD_DIR/extern/glog/build
cmake ..
sudo cmake --build . --target install

# json
mkdir -p $CI_BUILD_DIR/extern/json/build
cd $CI_BUILD_DIR/extern/json/build
cmake ..
sudo cmake --build . --target install

# vlog-parser
mkdir -p $CI_BUILD_DIR/extern/vlog-parser/build
cd $CI_BUILD_DIR/extern/vlog-parser/build
cmake ..
sudo cmake --build . --target install

# tmpl-synth 
mkdir -p $CI_BUILD_DIR/extern/tmpl-synth/build
cd $CI_BUILD_DIR/extern/tmpl-synth/build
cmake ..
sudo cmake --build . --target install

