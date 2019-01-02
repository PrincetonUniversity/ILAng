ILA vs Verilog Verification Tutorial
==================================================================================

Hongce Zhang (hongcez @princeton.edu)

File Structure
-------------------

```
|- app
|   \---main.cc : the verification script that 
|                 instantiates the ILA models and
|                 invoke the verification target
|                 generation procedures
|- include
|   \-+--aes_ila.h : the header of AES ILA model
|     |--aes_128.h : the header of AES 128 function model
|
|
|- src
|   \-+--aes_util.cc : provides some utility functions that 
|     |                makes writing ILA expressions simple
|     |--aes_ila.cc  : the model of the AES ILA instructions
|     |                and their semantics
|     |--aes_child.cc: the model of the child instructions
|     |                that accomplish the START_ENCRYPT instruction
|     |--aes_128.cc  : the model of the AES 128 function
|
|
|- refinement
|   \-+-- ref-rel-inst-cond.json : instruction start and end conditions of
|     |                            the AES instructions
|     |-- ref-rel-inst-cond-uaes.json : instruction start and end conditions
|     |                            of the AES child instructions
|     |-- ref-rel-inst-cond-aes128.json : instruction start and end conditions
|     |                            of the instructions in AES 128 functions
|     |-- ref-rel-var-map.json : the variable mapping of the AES instructions
|     |-- ref-rel-var-map-uaes.json : the variable mapping of the AES child 
|     |                               instructions
|     |-- ref-rel-var-map-aes128.json : the variable mapping for the AES 128
|                                       functions
|
|- verilog : the folder with the AES block encryption accelerator implementation.
```


Design Overview
-------------------
This example contains a manually constructed Verilog Module.
The AES module works in Counter Mode, the counter is incremented for each block. Tthe module only
provides AES encryption function. This AES accelerator is assumed to be connected through
memory-mapped IO, while the memory interface is the 8051 interface. The accelerator is assigned
to the following address space. Encryption happens in-place, in other words, the plaintext in
the memory will be overwritten by ciphertext after encryption.


| Memory Address | Content   | Comment                          |
|----------------|-----------|----------------------------------|
| 0xff00         | AES_START | Write 1 to start encryption      |
| 0xff01         | AES_STATE | Read-only, 0: Idle, >0: Busy     |
| 0xff02         | AES_ADDR  | Memory address for the plaintext |
| 0xff10         | AES_KEY   | Key for encryption               |
| 0xff20         | AES_CTR   | Initial value of the counter     |


The design comes in Verilog, which can be found in the subdirectory `verilog`.
The top module is `aes_top.v` which contains the interface and instantiate the 
accelerator registers and the aes128 function (`aes_128.v`).


AES ILA Model
-------------------
The AES model is built as a hierarchical model. It comes with 3 layers. In the top layer
are the instructions and the outside visible states. The outside (e.g. a processor core)
can trigger these instructions and they can directly sees the visible states defined
in this layer. 

However, one instruction `START_ENCRYPT` is very complex. It implements the counter-mode
block encryption. It operates block-by-block, first fetches one plaintext block 
from a designated memory region (computed from the register `address` and the offset 
baesd on the number of rounds). Invokes the AES128 function and do the following computation 
and then stores ciphertext back into the memory. 

C[i] = P[i] XOR AES128( COUNTER )

After handling one block, it count up the counter and check if it should continue to the next block.

So this instruction is modeled by 3 child-instructions, `LOAD`, `OPERATE` and `STORE`, in the 
child-ILA.

Finally, there are the AES 128 functions. The initial round is just a preprocessing step of the 
encryption key, followed by 10 rounds of operations. The final round omits MixColumns so it is 
different than the first 9 rounds. So it is modeled as a separate instruction `FinalRound`.


Verification Target Generation
-------------------





ILAng Library and Functions
-------------------




Bug Insertion Try-out
-------------------

In this section, we will show some bugs that
can be catched by the ILA verification methodology.
By inserting some artificial bugs, you can have a better 
idea of the ILAng capability.



