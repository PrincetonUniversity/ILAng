# Instruction-Level Abstraction Infrastructure 

### Coding Style
Follow [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

### Components
* C/C++ and Python API
* Intermediate Representation (ILA-IR)
* Front-end from verification objectives, e.g. C/C++, Verilog, and SMT-LIB
* Compilation to verification objectives, e.g. C/C++, Verilog, and SMT-LIB
* Applications, e.g. equivalence checking, FW/HW co-verification, MCM analysis, etc

#### ILA-IR Features
* Instruction decomposition 
* Phase decomposition (fetch/decode/execute)
* Hierarchical ILA
* SSA-like language?


[![linux build status](https://travis-ci.org/Bo-Yuan-Huang/ILA.svg?branch=master)](https://travis-ci.org/Bo-Yuan-Huang/ILA)
[![Coverage Status](https://coveralls.io/repos/github/Bo-Yuan-Huang/ILA/badge.svg)](https://coveralls.io/github/Bo-Yuan-Huang/ILA)
<a href="https://scan.coverity.com/projects/bo-yuan-huang-ila">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/14436/badge.svg"/>
</a>

## Building with Cmake:

```bash
  cd path/to/infra
  mkdir build
  cd build
  cmake .. -L -DZ3_INCLUDE_DIR=/usr/include -DBUILD_PYTHON_API=ON
```

