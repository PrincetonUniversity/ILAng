# Building ILA synthesis tool

Build Status
------------

[![Build Status](https://semaphoreci.com/api/v1/bo-yuan-huang/ila/branches/ilair/badge.svg)](https://semaphoreci.com/bo-yuan-huang/ila)

[![Coverage Status](https://coveralls.io/repos/github/Bo-Yuan-Huang/ILA/badge.svg)](https://coveralls.io/github/Bo-Yuan-Huang/ILA)

<a href="https://scan.coverity.com/projects/bo-yuan-huang-ila">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/14436/badge.svg"/>
</a>

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
