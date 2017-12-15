# Instruction-Level Abstraction (ILA)

Formal definition and modeling scenarios: [ILA Wiki](https://github.com/Bo-Yuan-Huang/ILA-Tools/wiki).


## Templated-based ILA synthesis

[![Build Status](https://semaphoreci.com/api/v1/bo-yuan-huang/ila/branches/master/shields_badge.svg)](https://semaphoreci.com/bo-yuan-huang/ila)

To build ILA synthesis tool, look in the [py-tmpl-synth](https://github.com/Bo-Yuan-Huang/ILA-Tools/tree/master/py-tmpl-synth) directory.

For some examples, see the [examples](https://github.com/Bo-Yuan-Huang/ILA-Tools/tree/master/examples) directory.

For API documents and tutorials, see the [docs](https://github.com/Bo-Yuan-Huang/ILA-Tools/tree/master/docs) directory.


## ILA description and C/C++/Python API (under construction)

[![Build Status](https://travis-ci.org/Bo-Yuan-Huang/ILA-Tools.svg?branch=master)](https://travis-ci.org/Bo-Yuan-Huang/ILA-Tools)
[![Coverage Status](https://coveralls.io/repos/github/Bo-Yuan-Huang/ILA-Tools/badge.svg?branch=master)](https://coveralls.io/github/Bo-Yuan-Huang/ILA-Tools?branch=master)
[![Coverity Scan Build Status](https://img.shields.io/coverity/scan/14490.svg)](https://scan.coverity.com/projects/bo-yuan-huang-ila-tools)
[![Project Status: Active – The project has reached a stable, usable state and is being actively developed.](http://www.repostatus.org/badges/latest/active.svg)](http://www.repostatus.org/#active)
[![license](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/Bo-Yuan-Huang/ILA-Tools/blob/master/LICENSE)

### Building with Cmake:
```bash
  mkdir -p build
  cd build
  cmake .. -L -DZ3_INCLUDE_DIR=/usr/include 
```

For API documentations, see the page [code-doc](https://rawgit.com/Bo-Yuan-Huang/ILA-Tools/master/docs/html/index.html).


### Publications:

* __Template-based Parameterized Synthesis of Uniform Instruction-Level Abstractions for SoC Verification__.
  Pramod Subramanyan, Bo-Yuan Huang, Yakir Vizel, Aarti Gupta, and Sharad Malik.
  *in* IEEE Transactions on Computer-Aided Design of Integrated Circuits and Systems (TCAD), 2017.
  [[PDF](https://github.com/Bo-Yuan-Huang/ILA-Tools/blob/master/docs/publications/Template-based%20Parameterized%20Synthesis%20of%20Uniform%20Instruction-Level%20Abstractions%20for%20SoC%20Verification.pdf)]

* __Invited: Specification and Modeling for Systems-on-Chip Security Verification__. 
  Sharad Malik and Pramod Subramanyan. 
  *in* Proceedings of the Design Automation Conference. (DAC 2016), Austin, TX. June 2016. 
  [[PDF](https://github.com/Bo-Yuan-Huang/ILA-Tools/blob/master/docs/publications/Invited_Specification_and_Modeling_for_Systems_on_Chip_Security_Verification.pdf)] 

* __Verifying Information Flow Properties of Firmware using Symbolic Execution__. 
  Pramod Subramanyan, Sharad Malik, Hareesh Khattri, Abhranil Maiti and Jason Fung.
  *in* Proceedings of Design Automation and Test in Europe. (DATE 2016). Dresden, Germany, March 2016.
  [[PDF](https://github.com/Bo-Yuan-Huang/ILA-Tools/blob/master/docs/publications/Verifying_Information_Flow_Properties_of_Firmware_using_Symbolic_Execution.pdf)]

* __Template-based Synthesis of Instruction-Level Abstractions for SoC Verification__. 
  Pramod Subramanyan, Yakir Vizel, Sayak Ray and Sharad Malik. 
  *in* Proceedings of Formal Methods in Computer-Aided Design. (FMCAD 2015). Austin, TX, September 2015.
  [[PDF](https://github.com/Bo-Yuan-Huang/ILA-Tools/blob/master/docs/publications/Template_based_Instruction_Level_Abstraction_for_SoC_Verification.pdf)]
