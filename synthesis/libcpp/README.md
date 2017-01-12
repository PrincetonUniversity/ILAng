# Building ILA synthesis tool
===========================

#### z3 
Building ILA synthesis tool requires [z3] (https://github.com/Z3Prover/z3) 4.4.0 or above.

#### boost
Building ILA synthesis tool requires [boost] (https://www.boost.org) 1.60.0 or above.

### Building with boost:

	% cd path/to/synthesis/libcpp/
	% bjam [-j4]

### Building with cmake:

	% cd path/to/synthesis/libcpp/
	% mkdir cbuild
	% cd cbuild
	% cmake ../ -L -DZ3_INCLUDE_DIR=/usr/include

#### Set python path for python API:

	% export PYTHONPATH=/path/to/synthesis/libcpp/build/:$PYTHONPATH
