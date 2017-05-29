### Acknowledgement 
Thanks to the Standford VLSI Research Group led by Prof Mark Horowitz for providing the example (https://github.com/jingpu/Halide-HLS.git).

### Overview

This is an example to demonstrate the capability of ILA in modeling at different levels of abstraction, and 
to perform equivalence checking between the ILAs and between the ILA and the FSM. 

### Directories
 
* ila_spec_a: high-level ILA 
* ila_spec_b: low-level ILA
* Verilog: FSM model (high-level synthesized RTL implementation)


The refinement relations for proving the equivalence are in:
* scripts_a_b: high-level ILA v.s. low-level ILA
* scripts_impl_a: high-level ILA v.s. FSM
* scripts_impl_b: low-level ILA v.s. FSM

### Tools

The verification is conducted via JasperGold, with the refinement written in SVA.
