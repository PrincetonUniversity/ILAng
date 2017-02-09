        ; mapping for write 0xfd00
        (= addr_rsa_state 64768)
        (= addr_rsa_addr 64770)
        ; 
        (= mmio_input_addr (+ @rsa_regs_0 0))
        (= cmd 2)
        (= cmdaddr 64768)
        (= cmddata mmio_input_data)
        (= rsa_state (select entryMem addr_rsa_state))
        (= rsa_addr (select entryMem addr_rsa_addr))
        ;
        (rsa_fd00 XRAM_0 cmd cmdaddr cmddata rsa_addr_0 rsa_buff_0 rsa_byte_counter_0 rsa_state_0 rsa_state_1 rsa_addr_1 XRAM_1 rsa_byte_counter_1 rsa_buff_1)
        ;
        (= mem_state (store XRAM_1 addr_rsa_state rsa_state_1))
        (= mem_addr (store mem_state addr_rsa_addr rsa_addr_1))
        (= mem_addr memExit)

