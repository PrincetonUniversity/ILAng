
Synthesizing ILA from AES RTL implementation and C implementation and Comparison
==================================================================================

Prerequisite
-------------------
* ILA library installed
* Verilator >= 3.8
* GCC >= 4.8.4

Overview
-------------------
This example will guide you through the steps of synthesizing the ILA model from both Verilog
and C designs. It will also talk a bit about the format of writing refinement relations. The
ILA model in this design contains micro-instructions, which means for a visible state update,
there can be many invisible micro-operations. The Verilog design is mostly the same as the the
one in `aes-rtl-uinst`. 

The AES module works in Counter Mode, the counter is incremented for each block. For the sake of
simplicity, the module only provides AES encryption function. This AES accelerator is assumed to 
be connected through memory-mapped IO, it is assigned to the following address space.


| Memory Address | Content   | Comment                          |
|----------------|-----------|----------------------------------|
| 0xff00         | AES_START | Write 1 to start encryption      |
| 0xff01         | AES_STATE | Read-only, 0: Idle, >0: Busy     |
| 0xff02         | AES_ADDR  | Memory address for the plaintext |
| 0xff10         | AES_KEY   | Key for encryption               |
| 0xff20         | AES_CTR   | Initial value of the counter     |



File Content
-------------------

* C 					: C code for AES Encryption
  * AES.h			: Header of AES computation
  * mmio.h			: Header of memory mapped IO interface 
  * AES_CTR_TOP.c	: Top module of C module
* Verilog
  * aes_top.v		: Top module of Verilog
  * simulateAES.hpp	:
  * simulateAES.cpp	: Simulator wrapper
* CSimRfRelation.py	: Refinement relation for C implementation
* VSimRfRelation.py	: Refinement relation for Verilog implementation
* CTemplate.py			: ILA template for C implementation
* VTemplate.py			: ILA template for Verilog implementation
* syn_C.py				: Script for synthesize ILA from C 
* syn_Vlg.py			: Script for synthesize ILA from Verilog
* EQCheckLib.py			: Providing functions to check inductive invariants
* EQcheck.py			: Tactics for proving equivalence


Commands for running the example
---------------------------------

First, compile the Verilog Simulator.
		
		cd Verilog
		make

This will generate the simulator named `AESsim` and save a copy on the 
parent directory.

Then, synthesize ILA from Verilog.

		cd ..
		python syn_Vlg.py
		
Now, in the subfolder `vILA`, there will be files each named by a state
storing the state update function. There are also two extra file called
`all` and `allu`. They are the complete ILA model for all instructions
and micro-instructions.

Next, let's synthesize ILA from C.

		python syn_C.py

Now `cILA` folder should contain the ILA we got from C implementation.

Equivalence checking
		python EQcheck.py


Equivalence Checking
---------------------------------

The equivalence checking here tries to prove (or disprove)
that the architectural states are matched. The two implementations
share the same number of architectural states, but they are different
in the microarchitectural states and their state update functions. 

Because intermediate microarchitectural steps are invisible, they can be
put together (or in other words, unrolled) to get the final visible update
and this visible update should keep the same between two implementation.
Although there is a bound on the maximum microarchitecural steps before
it is visible, it is not realistic to fully unroll. A better way is to
find inductive invariants, and try to prove certain microarchitectural 
steps are matched between the two implementation.

The indutive invariant we use in our equivalence checking is,

		If one instruction has not completed,
		then the operated block count must be less or equal to 
		the given length, block counts are matched, and so are the
		two counters.

This invariant can tell us in the beginning of last iteration, block
counts and counters are still matched. And in the last iteration (exit
step), we check the equivalence of the encrypted data.


Format for Refinement Relations
---------------------------------

Because the implementation can have many intermediate states before
an architectural visible instruction is finished, refinement relation
is used to identify the point which can be considered as the end of
(micro-/sub-) instructions.

Refinement relations maps a  
For C implementation, the base structure is like this

		from rfmaplib import VarMap, ILA, CArray
	
		def buildRefMap(Cinfo, refSimSp, PCstate):
			# build the refinement mapping by invoking
			# refSimSp.setCondition(level, instDecode, CINSTSet, list_of_var_Map_per_location)
			#
			
 * level is the name for abstraction/micro-/sub-abstraction
 * instDecode is used to distinguish the instructions, for different instructions 
   it should map to different places of the C code (for example, different micro
   instructions in the micro-program
 * CINSTSet specifies the beginning and end of an (micro-/sub-) instruction,
   It is the name of the label in C code
 * list\_of\_var\_Map\_per\_location is a list of tuples. Each tuple is combination
   of string and a variable mapping. Variable mappings can be created by 
		name = VarMap( dict )
   A dict is a dictionary, whose keys are the name of states and whose values are 
   the variables in C code. It can be one of the 4 types. 
     * string, the name of a single variable in C code.
     * pcstate, created by calling PCstate( pc_dict ), pc_dict is a dictionary
       that maps labels to a number
     * dictionary, which means the state on the left corresponds to a the combination
       of the C variables on the right.
     * CArray( name ). It means this state is a memory and it should correspond 
       to an array in C.
		

The C code, some labels can be used. Labels are in the following format: `//##LABEL##...##//`, 
where ... should be replaced by its name. For one label, it can be placed in multiple places in
the source code.


	
	
	
