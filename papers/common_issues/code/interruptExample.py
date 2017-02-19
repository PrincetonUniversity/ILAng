Processor   = ila.Abstraction('ExampleILA')     # Define the abstraction
                                                # Define arch-states
intrpt_sig  = Processor.inp('intrpt_sig', 1)    #   - interrupt signal
instr_mem   = Processor.mem('instr_mem', 32, 8) #   - instruction memory
pc          = Processor.reg('pc', 32)           #   - program counter
...                                             #   - registers, flags, ...

Processor.decode_exprs  = [(intrpt_sig == False) & (ISA_DECODEs)]
    # ISA_DECODEs: the decode functions of normal instructions (defined in ISA)
Processor.decode_exprs += [intrpt_sig == True]
    # Add a new instruction to handle the interrupt

pc_nxt_interrupt = ISR_entry
pc_nxt = ila.choice('pc_nxt', pc_nxt_interrupt, pc_nxt_normal)
Processor.set_next('pc', pc_nxt)
    # In addition to next state functions defined in the ISA (pc_nxt_normal), 
    # the program counter now can be updated to the ISR entry point (ISA_entry) 
    # when the interrupt signal is raised.
