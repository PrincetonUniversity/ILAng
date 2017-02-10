        ; mapping for write 0xfd00
        (= addr_rsa_state 64768)
        (= addr_rsa_addr 64772)
        ; 
        (= mmio_input_addr (+ @rsa_regs_0 768))
        (= cmd 2)
        (= cmdaddr 64769)
        (= cmddata mmio_input_data)
        (= rsa_state (select entryMem addr_rsa_state))
        (= rsa_addr (select entryMem addr_rsa_addr))
        ;
        (= rsa_mem_state (store XRAM_1 addr_rsa_state rsa_state_1))
        (= rsa_mem_addr (store rsa_mem_state addr_rsa_addr rsa_addr_1))
        (= rsa_mem_addr exitMem)
