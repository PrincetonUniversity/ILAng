ILA vs Verilog Verification Tutorial
==================================================================================


## What's inside the Artifact? ##

Here we leave the background knowledge to the end of the tutorial since you may want
to first play with the artifact before getting confused by the formal verification
terminologies.

In this demo you can explore

  * Checking design correctness using ILA.
  * Synthetic bug insertion and bug-finding using ILA verification.


### Prerequisites ###

You will need to have a machine that runs docker and has Internat connection because you will
need to download the docker image from the Docker Hub.

If you don't have docker installed, you can follow the steps below to install Docker on Ubuntu 16.04/18.04. The other Linux distribution be similar except that the package manager will 
be different.

1. Uninstall old versions. Older versions of Docker were called `docker` or `docker-engine`. If these are installed, uninstall them: 

```
$ sudo apt-get remove docker docker-engine docker.io
```

2. Update the apt package index:
```
$ sudo apt-get update
```

3. Install packages to allow apt to use a repository over HTTPS:
```
sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    software-properties-common

```

4. Add Docker’s official GPG key:

```
$ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
```

5. Use the following command to set up the **stable** repository.
```
$ sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"
```

6. Install Docker CE
```
$ sudo apt-get update
$ sudo apt-get install docker-ce
```

7. Verify that Docker CE is installed correctly by running the hello-world image.
```
$ sudo docker run hello-world
```
Upon successful installation, you will see a `Hello from Docker!` message. 


### Download the Demo Docker Image ###

Download our provided Docker image using:
```
sudo docker pull byhuang/ilang:posh-demo
``` 
And then run it with:
```
sudo docker run -it byhuang/ilang:posh-demo
```
If you see a command line prompt starting with `(ilang-env)`, you have 
successfully downloaded and started the demo docker image.



### Checking Correctness Using ILA Verification ###


This is the demo we presented in the Tuesday meeting. The Verilog design is already bug-free w.r.t
the ILA specification. First change directory to the AES example and list what's in this directory.

```
cd aes-demo
ls
```


#### Directory Structure ####


```
|- app
|   \---main.cc : the verification script that 
|                 instantiates the ILA models and
|                 invoke the verification target
|                 generation procedures
|- include
|   \-+--aes_ila.h : the header of AES ILA model
|     |--aes_128.h : the header of AES-128 function model
|
|
|- src
|   \-+--aes_util.cc : provides some utility functions that makes
|     |                writing AES ILA expressions simpler
|     |--aes_ila.cc  : the model of the AES ILA instructions and
|     |                their semantics
|     |--aes_child.cc: the model of the child instructions that
|     |                accomplish the START_ENCRYPT instruction
|     |--aes_128.cc  : the model of the AES 128 function
|
|
|- refinement
|   \-+-- ref-rel-inst-cond.json        : instruction start and end conditions of
|     |                                   the AES instructions
|     |-- ref-rel-inst-cond-uaes.json   : instruction start and end conditions
|     |                                   of the AES child instructions
|     |-- ref-rel-inst-cond-aes128.json : instruction start and end conditions
|     |                                   of the instructions in AES 128 functions
|     |-- ref-rel-var-map.json          : the variable mapping of the AES instructions
|     |-- ref-rel-var-map-uaes.json     : the variable mapping of the AES child 
|     |                                   instructions
|     |-- ref-rel-var-map-aes128.json   : the variable mapping for the AES 128
|                                         functions
|
|- verilog : the folder with the AES block encryption accelerator implementation.
|
|
|- verification: the verification target will be put in this folder.
|                Each instruction and sub-instruction has its own sub-folder. A script named
|                `RunAll.sh` is provided to run the verification of all the instructions
|                and sub-instructions.
|
|- cmake: contains a cmake script to help find Z3 (a SMT solver). You can safely ignore it.
|
|- build: the folder to contains the executable (AESExe) complied from the verification script 
|         provided in the `app` folder.
|
|- patch: the folder of two example bugs that can be inserted into the Verilog design.

```


#### Run the Target Generation Script ####

The target generation script (`app/main.cc`) has been linked with the ILA library and
it results in an executable (`build/AESExec`). This script instantiates the ILA models,
reads in the given Verilog design and the refinement relations and generates the verification 
targets in the `verification` folder. To run this script:

```
cd build
./AESExec Solver=btor
```

This will generate 17 targets in the `verification` folder.


#### Run the Target Generation Script ####

You can run separately of each target using
```
cd verification
cd <target-name>
. run.sh
```

Or you can run all the targets together using
```
cd verification
. RunAll.sh
```

The complete verification took around 15mins on a laptop with 
Core-i5 8300H CPU and 32GB of RAM.


### Synthetic Bug Insertion and Bug Finding Using ILA Verification  ###


In this artifact, we provide two exammples of bugs. 

Please first return to the AES example directory by:
```
cd ~/aes-demo/
```


#### Interface Bug ####

This synthetic bug lies in the interface of the Verilog design. 
Specifically, it allows the configuration registers, like encryption
key, to be changed when the accelerator is operating. This is dangerous
as it could potentially result in ciphertext that are not usable at all.
In the ILA specification, it is specified that only when the core is idle
can these configuration register get updated. 

You can view the bug by:
```
vim patch/AllowWriteRegWhenNotIdle.patch
```

The difference between the buggy and correct design is that the buggy one does
not use the `aes_state_idle` signal in the register-write-enable signal. 

Exit vim by typing `:q <Enter>`

Now, you can insert this synthetic bug by:
```
patch verilog/aes_top.v patch/AllowWriteRegWhenNotIdle.patch
```

And now regenerate the verification targets and invoke CoSA by:
```
cd build
./AESExe Solver=Btor
cd ../verification
. RunAll.sh
```
The print-out information will show that the implementation of instructions: 
`WRITE_ADDRESS`, `WRITE_KEY`, and  `WRITE_LENGTH`, and sub-instructions `LOAD`, 
`OPERATE` and `STORE`  does not match the specification, along with short traces
showing how the implementation transits to this buggy state (a state 
where the state variables in ILA and Verilog do not match any more, 
in other words, `variable_map_assert` signal is low). 

The waveform (`trace[1]-variable_map_assert_.vcd`) demonstrating this bug is also 
generated in the sub-folders of the failing instructions, which can be viewed 
by waveform viewer such as GtkWave (not included in this docker image, but you 
can transfer the waveform to the outside of the Docker using, for example:

```
scp "WRITE_LENGTH/trace[1]-variable_map_assert_.vcd" <server-name>:<path>
```

where `WRITE_LENGTH` can be replaced by the name of other buggy instructions and 
`<server-name>:<path>` points to a path on a SSH server that you have access to)

If you are using Ubuntu as the Host OS, you can use 
[this guide](https://help.ubuntu.com/lts/serverguide/openssh-server.html.en) 
to setup a SSH server locally.


After testing with this interface bug, correct it by undoing the patch:
```
cd ~/aes-demo
patch -R verilog/aes_top.v patch/AllowWriteRegWhenNotIdle.patch
```



#### Internal Logic Bug ####


This synthetic bug lies in the internal logic of the ILA. Specifically,
a lookup table entry is mistaken.


You can view this bug by:
```
cd ~/aes-demo
vim patch/WrongTableEntry.patch
```

The number 0x57 entry should be 0x5b, but was mistaken as 0x5c. You can
inject this bug by: (please first exit from vim)
```
patch verilog/S.v patch/WrongTableEntry.patch
```

Now regenerate the verification targets and invoke CoSA by:
```
cd build
./AESExe Solver=Btor
cd ../verification
. RunAll.sh
```

The verification will show that two instructions `IntermediateRound` and
`FinalRound` will fail as they both use the S-box lookup table. Similarly,
waveform (`trace[1]-variable_map_assert_.vcd`) is generated in the sub-folders
of the two failing instructions, which could be used to locate the bug.

After testing with this logic bug, correct it by undoing the patch:
```
cd ~/aes-demo
patch -R verilog/S.v patch/WrongTableEntry.patch
```

Besides the two bugs, you can also try modifying the
Verilog yourself and see how our tool reacts to the changes.



## Background Information ##



### Design Overview ###

This example is a manually written Verilog module that performs AES block encryption.
This AES module works in Counter Mode, the counter is incremented for each block. This AES 
accelerator is assumed to be connected through memory-mapped IO, while the memory interface 
is the 8051 memory interface. The accelerator is assigned to the following address space. 
After the encryption the plaintext in the memory will be overwritten by ciphertext.


| Memory Address | Content   | Comment                          |
|----------------|-----------|----------------------------------|
| 0xff00         | AES_START | Write 1 to start encryption      |
| 0xff01         | AES_STATE | Read-only, 0: Idle, >0: Busy     |
| 0xff02         | AES_ADDR  | Memory address for the plaintext |
| 0xff10         | AES_KEY   | Key for encryption               |
| 0xff20         | AES_CTR   | Initial value of the counter     |


The design can be found in the subdirectory `verilog`.
The top module is `aes_top.v` which contains the interface and instantiate the 
accelerator registers and the aes128 function (`aes_128.v`).


### The AES ILA Model ###

The AES ILA model is built as a hierarchical model. It has three layers. In the top layer
there are the instructions and the outside visible states. The outside (e.g. a processor core)
can trigger these instructions and they can directly sees the visible states (by reading the
corresponding memory location) defined in this layer. 

However, one instruction: `START_ENCRYPT` is very complex. It implements the counter-mode
AES block encryption. It operates block-by-block, first fetches one plaintext block 
from a designated memory region (computed from the register `address` plus an offset incremented
each round). It invokes the AES-128 function and does the following computation 
and then stores ciphertext back into the memory. 

C[i] = P[i] XOR AES128( COUNTER )

Where C[i] is the i-th ciphertext block and P[i] is the i-th plaintext block.

After encrypting one block, it counts up the counter and checks whether it should continue to the next block or return to the idle state.

This `START_ENCRYPT` instruction triggers this process and it is modeled with the help of 3 child-instructions, `LOAD`, `OPERATE` and `STORE`.

Finally, there is the AES-128 function. The initial round is just one step of `AddRoundKey`, 
followed by 10 rounds of operations. The final round omits MixColumns so it is 
different from the first 9 rounds and is modeled as a separate instruction: `FinalRound`.

The modeling of this AES module uses our ILA library functions. A complete specification 
of the library function that can be used in modeling can be found [here](https://).


### Refinement Map (Refinement Relation) ###

The verification is to check whether the per-instruction state update function matches
the Verilog Design. It assumes a state mapping between the initial states of the two
models (ILA and Verilog) and at the end of the instruction checks for the state mapping.
It actually forms a commutative diagram as shown below.

```

  ILA state1 ------instr--------> ILA state2
     ||                               ||
     ||                               ||
     ||                               ||
     ||                               ||
     ||                               ||
     ||                               ||
  Verilog s1 ----transitions----> Verilog sn


```

In the refinement relations, one must specify (1) the state mapping, and (2) in the Verilog,
when should be regarded as the end of an instruction. These two parts are specified in 
two files, both in JSON format.

The complete specification of the refinement map format in the JSON file can be found [here](https://).




### Verification Target Generation ###

For the open-souce toolchain, we support CoSA (CoreIR Symbolic Analyzer) as the verifier. 
Our tool will generate verification targets (Verilog and also properties) that CoSA can take as input.

The verification target generation functionality is triggered via instantiating a 
`VerilogVerificationTargetGenerator` object. The arguments of this 
object constructors are:

1. A list of paths to search for Verilog include files
2. A list of Verilog design files
3. The Verilog top module
4. The variable mapping file (first part of refinement map)
5. The instruction start/ready conditions (second part of refinement map)
6. The output path of the verification targets
7. The ILA model
8. The choice backend (CoSA/JapserGold, the latter is not open-source and not included in the demo)
9. (Optional) Target generator configuration
10. (Optional) Verilog generator configuration

In the verification script you can find that there are three such objects (Line -, - , -), 
corresponding to the checking of three layers of the model.


