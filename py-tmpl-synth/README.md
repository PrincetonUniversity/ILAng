# Building ILA synthesis tool

Build Status
------------

[![Build Status](https://semaphoreci.com/api/v1/bo-yuan-huang/ila-tools/branches/master/badge.svg)](https://semaphoreci.com/bo-yuan-huang/ila-tools)


#### z3 
Building ILA synthesis tool requires [z3](https://github.com/Z3Prover/z3) 4.4.0 to 4.7.1 (latest release).

#### boost
Building ILA synthesis tool requires [boost](https://www.boost.org) 1.54.0 to 1.60.0.

### Building with boost:

```bash
	cd path/to/synthesis/libcpp/
	bjam [-j4]
```

### Building with cmake:

```bash
	cd path/to/synthesis/libcpp/
	mkdir cbuild
	cd cbuild
	cmake ../ -L -DZ3_INCLUDE_DIR=/usr/include
```

#### Set python path for python API:

```bash
	export PYTHONPATH=/path/to/synthesis/libcpp/build/:$PYTHONPATH
```
