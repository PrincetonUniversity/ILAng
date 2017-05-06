# Building ILA synthesis tool

Build Status
------------

| Linux                        |
|------------------------------|
| [![linux build status][1]][2]|

[1]: https://travis-ci.org/Bo-Yuan-Huang/ILA.svg?branch=master
[2]: https://travis-ci.org/Bo-Yuan-Huang/ILA

#### z3 
Building ILA synthesis tool requires [z3](https://github.com/Z3Prover/z3) 4.4.0 or above.

#### boost
Building ILA synthesis tool requires [boost](https://www.boost.org) 1.60.0 or above.

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
