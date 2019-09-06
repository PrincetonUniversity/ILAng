[![ILAng](https://raw.githubusercontent.com/Bo-Yuan-Huang/ILAng/master/docs/pics/ilang-logo.png)](https://bo-yuan-huang.gitbook.io/ilang/)

[![Build Status](https://travis-ci.org/Bo-Yuan-Huang/ILAng.svg?branch=master)](https://travis-ci.org/Bo-Yuan-Huang/ILAng)
[![Build Status](https://semaphoreci.com/api/v1/bo-yuan-huang/ilang/branches/master/shields_badge.svg)](https://semaphoreci.com/bo-yuan-huang/ilang)
[![Build status](https://ci.appveyor.com/api/projects/status/cwhlq09513art6hw/branch/master?svg=true)](https://ci.appveyor.com/project/Bo-Yuan-Huang/ilang/branch/master)
[![Build Status](https://dev.azure.com/byhuang/ILAng/_apis/build/status/Bo-Yuan-Huang.ILAng?branchName=master)](https://dev.azure.com/byhuang/ILAng/_build/latest?definitionId=1&branchName=master)
[![Coverage Status](https://coveralls.io/repos/github/Bo-Yuan-Huang/ILAng/badge.svg?branch=master)](https://coveralls.io/github/Bo-Yuan-Huang/ILAng?branch=master)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/b120e2527cc04d4aacd1dc11581e2f30)](https://www.codacy.com/app/Bo-Yuan-Huang/ILAng?utm_source=github.com&utm_medium=referral&utm_content=Bo-Yuan-Huang/ILAng&utm_campaign=Badge_Grade)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/Bo-Yuan-Huang/ILAng.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/Bo-Yuan-Huang/ILAng/context:cpp)
[![license](https://img.shields.io/github/license/bo-yuan-huang/ilang.svg?style=flat)](https://github.com/Bo-Yuan-Huang/ILA-Tools/blob/master/LICENSE)
[![Documentation](https://img.shields.io/badge/docs-manual-blue.svg)](https://bo-yuan-huang.gitbook.io/ilang/)
[![Documentation](https://img.shields.io/badge/docs-doxygen-blue.svg)](https://bo-yuan-huang.github.io/ILAng-Doc/doxygen-output-html/namespaceilang.html)
[![docker](https://images.microbadger.com/badges/image/byhuang/ilang.svg)](https://hub.docker.com/r/byhuang/ilang)

-   [Build](#build)
    -   [Prerequisites](#prerequisites)
    -   [Default Build](#default-build)
    -   [Options](#options)

-   [CMake Integration](#cmake-integration)
    -   [External](#external)
    -   [Embedded](#embedded)
    -   [Supporting Both](#supporting-both)

-   [Docker](#docker-image)

-   [License](#license)

-   [Contributing](#contributing)

## Build

### Prerequisites

ILAng requires CMake (3.9.6 or above) and compilers with CXX11 support.
To install dependencies on Debian-based UNIX:

```bash
apt-get install bison flex libboost-all-dev z3 libz3-dev
```

To install dependencies on OSX:

```bash
brew install bison flex boost boost-python z3
```

-   The [z3](https://github.com/Z3Prover/z3) SMT solver (over 4.4.0) is required. Detailed instruction for building latest z3 can be found [here](https://github.com/Z3prover/z3#building-z3-using-make-and-gccclang).
-   The [Boost](https://www.boost.org) package is required only for building the synthesis engine and the Python API. 

#### Regression Environments

| OS                        | Compiler     | CMake  | z3    | Boost | Bison | Flex   | Build   |
| ------------------------- | ------------ | ------ | ----- | ----- | ----- | ------ | ------- |
| Ubuntu 14.04 (Trusty)     | gcc 4.8.4    | 3.8.0  | 4.8.5 | 1.54  | 3.0.4 | 2.5.25 | Release |
| Ubuntu 16.04 (Xenial)     | gcc 5.4.0    | 3.12.4 | 4.4.1 | 1.58  | 3.0.4 | 2.6.0  | Debug   |
| Ubuntu 16.04 (Xenial)     | clang 7.0.0  | 3.12.4 | 4.4.1 | 1.58  | 3.0.4 | 2.6.0  | Debug   |
| Ubuntu 16.04 (Xenial)     | gcc 5.4.0    | 3.12.4 | 4.4.1 | 1.69  | 3.0.4 | 2.6.0  | Default |
| Ubuntu 18.04 (Bionic)     | gcc 7.4.0    | 3.14.4 | 4.4.1 | 1.65  | 3.0.4 | 2.6.4  | Default |
| OSX 10.13.3 (High Sierra) | Xcode 9.4.1  | 3.11.3 | 4.8.5 | 1.70  | 3.4.1 | 2.5.35 | Debug   |
| OSX 10.13.6 (High Sierra) | Xcode 10.1.0 | 3.14.5 | 4.8.5 | 1.70  | 3.4.1 | 2.5.35 | Default |
| OSX 10.14.5 (Mojave)      | Xcode 10.2.1 | 3.14.5 | 4.8.5 | 1.70  | 3.4.1 | 2.5.35 | Default |
| Windows Server 2016       | VS 2017      | 3.14.5 | 4.8.5 | -     | 3.3.2 | 2.6.4  | Default |

### Default Build

To build ILAng with default configuration, create a build directory and execute:

```bash
mkdir -p build && cd build
cmake .. 
make
```

After the build complete, run unit tests and install the library. 

```bash
make run_test
sudo make install
```

### Options

-   Use `-DILANG_FETCH_DEPS=OFF` to disable config-time updating submodules for in-source dependencies.
-   Use `-DILANG_BUILD_TEST=OFF` to disalbe building the unit tests.
-   Use `-DILANG_BUILD_SYNTH=OFF` to disable building the synthesis engine. 
-   Use `-DILANG_INSTALL_DEV=ON` to enable installing working features. 

## CMake Integration

You can use the `ilang::ilang` interface target in CMake. 
This target populates the appropriate usage requirements for include directories, linked libraries, and compile features. 
To use the ILAng library, `ilang++.h` is the file to include. 
(This does not include working features.)

```c++
// cxx source

#include <ilang/ilang++.h>

void foo () {
  auto m = ilang::Ila("new_ila_model");
}
```

### External

To use the ILAng library from a CMake project, you can locate it directly with `find_package()` and use the namespaced imported target from the generated package configuration:

```cmake
# CMakeLists.txt

find_package(ilang REQUIRED)

add_library(my_proj ...)

target_link_libraries(my_proj PRIVATE ilang::ilang)
```

### Embedded

ILAng also supports embedded build, but is not recommended due to its size. 
To embed the library directly into an existing CMake project, place the entire source tree in a subdirectory and call `add_subdirectory()` in your `CMakeLists.txt` file:

```cmake
# CMakeLists.txt

add_subdirectory(ilang)

add_library(my_proj ...)

target_link_libraries(my_proj PRIVATE ilang::ilang)
```

### Supporting Both

To allow your project to support either an externally installed or an embedded library, you can use the following pattern:

```cmake
# Top level CMakeLists.txt

project(MY_PROJ)

option(MY_PROJ_USE_EXTERNAL_ILANG "Use an external ILAng library" OFF)

add_subdirectory(externals)

add_library(my_proj ...)

target_link_libraries(my_proj PRIVATE ilang::ilang)
```

```cmake
# externals/CMakeLists.txt

if(MY_PROJ_USE_EXTERNAL_ILANG)
  find_package(ilang REQUIRED)
else()
  add_subdirectory(ilang)
endif()
```

`externals/ilang` is then a complete copy of this source tree, if enabled.

## Docker Image

[![docker-io](http://dockeri.co/image/byhuang/ilang)](https://hub.docker.com/r/byhuang/ilang)
[![docker-image](https://images.microbadger.com/badges/image/byhuang/ilang.svg)](https://microbadger.com/images/byhuang/ilang "Get your own image badge on microbadger.com")
[![docker-version](https://images.microbadger.com/badges/version/byhuang/ilang.svg)](https://microbadger.com/images/byhuang/ilang "Get your own version badge on microbadger.com")

An docker image with the ILAng platform and all dependencies can be fetched from [Docker Hub](https://hub.docker.com/r/byhuang/ilang).

```bash
docker pull byhuang/ilang:latest
```

Once the container is initiated, run 

```bash
source init.sh
```

to initialize the environment settings. 
This docker image also contains the model checker [CoSA](https://github.com/cristian-mattarei/CoSA) with the SMT solvers [z3](https://github.com/Z3Prover/z3) and [Boolector](https://github.com/Boolector/boolector).

## License

<img align="right" src="http://opensource.org/trademarks/opensource/OSI-Approved-License-100x137.png">

ILAng is licensed under the [MIT license](https://opensource.org/licenses/MIT):

Copyright © 2018-2019 [Princeton University ILA Team](https://sites.google.com/view/princeton-malik-group/people)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

* * *

ILAng contains the [Google logging module](https://github.com/google/glog), which is licensed under [glog license](extern/glog/COPYING).
Copyright (c) 2008, Google Inc.

ILAng contains the [Google Test project](https://github.com/google/googletest), which is licensed under [googletest license](extern/googletest/LICENSE).
Copyright 2008, Google Inc.

ILAng contains the [JSON library](https://github.com/nlohmann/json), which is licensed under the [MIT License](https://github.com/nlohmann/json/blob/develop/LICENSE.MIT). 
Copyright (c) 2013-2019 Niels Lohmann.

ILAng uses the [Verilog parser](https://github.com/ben-marshall/verilog-parser), which is licensed under the [MIT License](https://github.com/ben-marshall/verilog-parser/blob/master/LICENSE.txt).
Copyright (c) 2016 Ben Marshall.

ILAng uses [ItSy](https://github.com/PrincetonUniversity/ItSy), which is licensed under the [MIT License](https://github.com/PrincetonUniversity/ItSy/blob/master/LICENSE).
Copyright (c) 2016 Princeton University ILA Team.

## Contributing

Please refer to [CONTRIBUTING](docs/CONTRIBUTING.md) for further details. 
