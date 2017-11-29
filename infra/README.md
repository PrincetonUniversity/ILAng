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

[![Build Status](https://semaphoreci.com/api/v1/bo-yuan-huang/ila/branches/ilair/badge.svg)](https://semaphoreci.com/bo-yuan-huang/ila)

## Building with Cmake:

```bash
  cd path/to/infra
  mkdir build
  cd build
  cmake .. -L -DZ3_INCLUDE_DIR=/usr/include -DBUILD_PYTHON_API=ON
```

