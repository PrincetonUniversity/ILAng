; mapping from ILA to HW_REG_WRITE_chr for (sha_reg + 0) for interleave ILA
(rule (let ((a!1 (and (HW_REG_WRITE_chr@entry
                  HW_REG_WRITE_chr@%_3_0
                  HW_REG_WRITE_chr@%_5_0
                  HW_REG_WRITE_chr@%_1_0
                  HW_REG_WRITE_chr@%_6_0
                  HW_REG_WRITE_chr@%_4_0
                  HW_REG_WRITE_chr@%_2_0
                  HW_REG_WRITE_chr@%_0_0
                  HW_REG_WRITE_chr@%data_0
                  HW_REG_WRITE_chr@%addr_0
                  @sha_regs_0)
                true
    ;; 
    (= XRAM HW_REG_WRITE_chr@%_3_0)
    (= addr_state 65025)
    (= addr_wraddr 65032)
    (= addr_len 65036)
    (= addr_bytes 65040)
    ;
    (= HW_REG_WRITE_chr@%addr_0 (+ @sha_regs_0 0))
    (= cmd 2)
    (= cmdaddr 65024)
    (= cmddata HW_REG_WRITE_chr@%data_0)
    (= sha_state (select XRAM addr_state))
    (= sha_wraddr (select XRAM addr_wraddr))
    (= sha_len (select XRAM addr_len))
    (= sha_bytes_read (select XRAM addr_bytes))
    ;
    b0
    (rel.delta_fe00 cmd cmdaddr sha_state b0)
    (sha_fe00 cmddata sha_state sha_bytes_read sha_state_1 sha_bytes_read_1)
    (loop_sha 
     sha_state_1 sha_wraddr sha_len sha_bytes_read_1
     sha_state_nxt sha_bytes_read_nxt)
    ;
    (= XRAM_state (store XRAM addr_state sha_state_nxt))
    (= XRAM_bytes (store XRAM_state addr_bytes sha_bytes_read_nxt))
    (= XRAM_bytes HW_REG_WRITE_chr@%_9_0)
    ;; 
    )))
  (=> a!1
      (HW_REG_WRITE_chr@entry.split
        HW_REG_WRITE_chr@%_3_0
        HW_REG_WRITE_chr@%_9_0
        HW_REG_WRITE_chr@%_5_0
        HW_REG_WRITE_chr@%_1_0
        HW_REG_WRITE_chr@%_6_0
        HW_REG_WRITE_chr@%_4_0
        HW_REG_WRITE_chr@%_2_0
        HW_REG_WRITE_chr@%_0_0
        HW_REG_WRITE_chr@%data_0
        HW_REG_WRITE_chr@%addr_0
        @sha_regs_0))))
