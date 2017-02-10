        ; mapping for write 0xfe00
        (= addr_sha_state 65025)
        (= addr_sha_rdaddr 65028)
        (= addr_sha_wraddr 65032)
        (= addr_sha_len 65036)
        (= addr_sha_bytes 65040)
        ;
        (= mmio_input_addr (+ @sha_regs_0 0))
        (= cmd 2)
        (= cmdaddr 65025)
        (= cmddata mmio_input_data)
        (= sha_state (select entryMem addr_sha_state))
        (= sha_rdaddr (select entryMem addr_sha_rdaddr))
        (= sha_wraddr (select entryMem addr_sha_wraddr))
        (= sha_len (select entryMem addr_sha_len))
        (= sha_bytes_read (select entryMem addr_sha_bytes))
        ;
        (= sha_mem_state (store XRAM_1 addr_sha_state sha_state_1))
        (= sha_mem_len (store sha_mem_state addr_sha_len sha_len_1))
        (= sha_mem_rdaddr (store sha_mem_len addr_sha_rdaddr sha_rdaddr_1))
        (= sha_mem_wraddr (store sha_mem_rdaddr addr_sha_wraddr sha_wraddr_1))
        (= sha_mem_bytes (store sha_mem_wraddr addr_sha_bytes sha_bytes_read_1))
        (= sha_mem_bytes memExit)
