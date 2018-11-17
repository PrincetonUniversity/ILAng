ILAng BMC Engine Demo
======================

Overview
----------

This design is to demostrate the BMC capability of the ILA-Tool.
It constructs two FIFO designs. One with a counter that counts
the number of elements currently in the fifo and avoids enqueue
when full or dequeue when empty. The other design has no such
protection. 

The BMC here is to check if the FIFO could underflow or overflow
within a given bound. 

File Content
------------

	* src/main.cc    : the C++ code that provides the commandline interface
	* src/ila_fifo.h : definitions of ILAs of two FIFOs
	* src/util.h 	 : the utility function to use unroller for BMC


The Design
------------------

The parameter of the FIFO is a configurable through the Macros in `src/ila_fifo.h`,
including data width and FIFO depth. The bitvector state `rptr` and `wptr` are used 
to as the pointers to the memory `storage` for places to read/write next.

There are two instructions for each FIFO, one is `Dequeue` and the other is `Enqueue`.
The I/O interface is listed below

	|   name      | direction| bitwidth|
	|  ---------  | -------- | --------|
	|  w_en_in    |  input   | 1 bit   |
	|  r_en_in    |  input   | 1 bit   |
	|  w_data_in  |  input   | N bits  |
	|  r_data_out |  output  | N bits  |


Property to Check
-----------------

The underflow property is equivalent to LTL:  G !( empty /\ rptr == c /\ X ( rptr == c + 1)  ),
It says there should not be the case that the fifo is empty in a certain cycle the 
read pointer steps by one (aka, read when empty)

The overflow property is equivalent to LTL:  G !( full /\ wptr == c /\ X ( wptr == c + 1)  ),
It says there should not be the case that the fifo is full and write pointer steps by one 
(aka, write when empty)
