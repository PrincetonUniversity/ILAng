Accelerator = ila.Abstraction('ExampleILA')         # Define the Abstraction
                                                    # Define the Interface
write_grant = Accelerator.inp('write_grant',  1)    #   - request grant
write_data  = Accelerator.reg('write_data' , 32)    #   - data port
write_length= Accelerator.reg('write_len'  , 16)    #   - burst length
...                                                 #   - possibly more ports
writing     = Accelerator.reg('writing'    ,  1)    # 1 bit flag indicating if  
                                                    # it is writing to the bus
Accerlator.decode_exprs += [ write_grant == 1 ]     
# The grant operation is considered as an instruction to the accelerator

writing_nxt = ila.ite( write_grant == 1,  # The effect of the instruction above
                b1,                       # This is the complete function 
                writing )                 # without holes. However, you can 
                                          # use synthesis to create this
                                          # function
#Note: b0 = ila.const(0,1) (1-bit-wide constant 0)
#and   b1 = ila.const(1,1) (1-bit-wide constant 1)

Accelerator.set_next('writing', writing_nxt )

write_fsm   = Accelerator.add_microabstraction('WriteFsm', writing == 1 )  
# Bus Write logic.
counter     = write_fsm.reg('counter', 32) # The counter here is used 
                                           # to count cycles
write_fsm.set_init('counter', h0_16 )      # b0_16 = ila.const(0,16)
write_fsm.set_next('counter', counter + 1)
write_fsm.set_next('writing', 
        ila.ite(counter == write_length-1, b0, writing) )  # turn the flag off,
                                                           # when necessary
write_fsm.set_next('write_data', ?? )                      # write some values 
                                                           # each cycle



