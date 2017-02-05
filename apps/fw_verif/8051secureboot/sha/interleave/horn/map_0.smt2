; mapping from ILA to HW_REG_WRITE_chr for (sha_reg + 0) for interleave ILA
(rule (let ((a!1 (and (HW_REG_WRITE_chr@entry
                  HW_REG_WRITE_chr@%_6_0
                  HW_REG_WRITE_chr@%_4_0
                  HW_REG_WRITE_chr@%_5_0
                  HW_REG_WRITE_chr@%_1_0
                  HW_REG_WRITE_chr@%_2_0
                  HW_REG_WRITE_chr@%_3_0
                  HW_REG_WRITE_chr@%_0_0
                  HW_REG_WRITE_chr@%data_0
                  HW_REG_WRITE_chr@%addr_0
                  @sha_regs_0)
                true
    ;; 
    (= XRAM HW_REG_WRITE_chr@%_0_0)
    (= addr_state 65025)
    (= addr_rdaddr 65028)
    (= addr_wraddr 65032)
    (= addr_len 65036)
    (= addr_bytes 65040)
    ;
    (= HW_REG_WRITE_chr@%addr_0 (+ @sha_regs_0 0))
    (= cmd 2)
    (= cmdaddr 65024)
    (= cmddata HW_REG_WRITE_chr@%data_0)
    (= sha_state (select XRAM addr_state))
    (= sha_rdaddr (select XRAM addr_rdaddr))
    (= sha_wraddr (select XRAM addr_wraddr))
    (= sha_len (select XRAM addr_len))
    (= sha_bytes_read (select XRAM addr_bytes))
    ;
    (rel.delta_fe00 cmd cmdaddr sha_state b0)
    b0
    (rel.N_fe00_XRAM_nxt XRAM XRAM_1)
    (rel.N_fe00_sha_state_nxt cmd cmdaddr cmddata sha_state sha_state_1)
    (rel.N_fe00_sha_rdaddr_nxt sha_rdaddr sha_rdaddr_1)
    (rel.N_fe00_sha_wraddr_nxt sha_wraddr sha_wraddr_1)
    (rel.N_fe00_sha_len_nxt sha_len sha_len_1)
    (rel.N_fe00_sha_bytes_read_nxt cmd cmdaddr cmddata sha_bytes_read sha_state sha_bytes_read_1)
    (loop_sha 
     XRAM_1 sha_hs_data_1 sha_state_1 sha_rdaddr_1 sha_wraddr_1 sha_len_1 sha_bytes_read_1
     XRAM_nxt sha_hs_data_nxt sha_state_nxt sha_rdaddr_nxt sha_wraddr_nxt sha_len_nxt sha_bytes_read_nxt)
    ;
    (= XRAM_state (store XRAM_nxt addr_state sha_state_nxt))
    (= XRAM_len (store XRAM_state addr_len sha_len_nxt))
    (= XRAM_rdaddr (store XRAM_len addr_rdaddr sha_rdaddr_nxt))
    (= XRAM_wraddr (store XRAM_rdaddr addr_wraddr sha_wraddr_nxt))
    (= XRAM_bytes (store XRAM_wraddr addr_bytes sha_bytes_read_nxt))
    (= XRAM_bytes HW_REG_WRITE_chr@%_10_0)
    ;; 
    )))
  (=> a!1
      (HW_REG_WRITE_chr@entry.split
        HW_REG_WRITE_chr@%_6_0
        HW_REG_WRITE_chr@%_4_0
        HW_REG_WRITE_chr@%_5_0
        HW_REG_WRITE_chr@%_1_0
        HW_REG_WRITE_chr@%_2_0
        HW_REG_WRITE_chr@%_3_0
        HW_REG_WRITE_chr@%_0_0
        HW_REG_WRITE_chr@%_10_0
        HW_REG_WRITE_chr@%data_0
        HW_REG_WRITE_chr@%addr_0
        @sha_regs_0))))
