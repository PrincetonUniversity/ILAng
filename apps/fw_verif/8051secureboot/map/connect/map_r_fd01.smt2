        ; mapping for read 0xfd01
        (= addr_rsa_state 64769)
        (= addr_rsa_addr 64772)
        (= addr_rsa_byte 64776)
        ; 
        ;(= mmio_input_addr (+ @rsa_regs_0 769))
        (= mmio_input_addr (+ @rsa_regs_0 49))
        (= cmd 1)
        (= cmdaddr 64769)
        (= rsa_state_0 (select entryMem addr_rsa_state))
        (= rsa_addr_0 (select entryMem addr_rsa_addr))
        (= rsa_byte_counter_0 (select entryMem addr_rsa_byte))
        ;
        (= rsa_mem_state (store XRAM_1 addr_rsa_state rsa_state_1))
        (= rsa_mem_addr (store rsa_mem_state addr_rsa_addr rsa_addr_1))
        (= rsa_mem_byte (store rsa_mem_addr addr_rsa_byte rsa_byte_counter_1))
        (= rsa_mem_byte exitMem)
        (= dataout_1 returnVal)
