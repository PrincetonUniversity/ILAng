; mapping from ILA to HW_REG_WRITE_ptr for (sha_reg + 4)
(rule (let ((a!1 (and (HW_REG_WRITE_ptr@_1
                  HW_REG_WRITE_ptr@%_call_0
                  HW_REG_WRITE_ptr@%_3_0
                  HW_REG_WRITE_ptr@%_2_0
                  HW_REG_WRITE_ptr@%_4_0
                  @sha_regs_0
                  HW_REG_WRITE_ptr@%data_0
                  HW_REG_WRITE_ptr@%addr_0)
                true
    ;; 
    (= addr_state 65025)
    (= addr_rdaddr 65028)
    (= addr_wraddr 65032)
    (= addr_len 65036)
    ;
    (= HW_REG_WRITE_ptr@%addr_0 (+ @sha_regs_0 4))
    (= cmd 2)
    (= cmdaddr 65028)
    (= cmddata (bv2int ((_ int2bv 8) HW_REG_WRITE_ptr@%data_0)))
    (= sha_state (select HW_REG_WRITE_ptr@%_call_0 addr_state))
    (= sha_rdaddr (select HW_REG_WRITE_ptr@%_call_0 addr_rdaddr))
    (= sha_wraddr (select HW_REG_WRITE_ptr@%_call_0 addr_wraddr))
    (= sha_len (select HW_REG_WRITE_ptr@%_call_0 addr_len))
    ;
    (rel.decode_fe04 cmd cmdaddr b149)
    ;b149
    (rel.instr_fe04_sha_state_nxt cmd cmdaddr sha_state sha_state_nxt_1)
    (rel.instr_fe04_sha_len_nxt sha_len sha_len_nxt_1)
    (rel.instr_fe04_sha_rdaddr_nxt cmd cmdaddr cmddata sha_rdaddr sha_rdaddr_nxt_1)
    (rel.instr_fe04_sha_wraddr_nxt sha_wraddr sha_wraddr_nxt_1)
    (rel.instr_fe04_XRAM_nxt XRAM cmd cmdaddr cmddata sha_state XRAM_nxt_1)
    ;
    (= cmdaddr_1 65029)
    (= cmddata_1 (bv2int ((_ extract 15 8) ((_ int2bv 16) HW_REG_WRITE_ptr@%data_0))))
    (rel.decode_fe05 cmd cmdaddr_1 b187)
    ;b187
    (rel.instr_fe05_sha_state_nxt cmd cmdaddr_1 sha_state_nxt_1 sha_state_nxt)
    (rel.instr_fe05_sha_len_nxt sha_len_nxt_1 sha_len_nxt)
    (rel.instr_fe05_sha_rdaddr_nxt cmd cmdaddr_1 cmddata_1 sha_rdaddr_nxt_1 sha_rdaddr_nxt)
    (rel.instr_fe05_sha_wraddr_nxt sha_wraddr_nxt_1 sha_wraddr_nxt)
    (rel.instr_fe05_XRAM_nxt XRAM_nxt_1 cmd cmdaddr_1 cmddata_1 sha_state_nxt_1 XRAM_nxt)
    ;
    (= XRAM_state (store XRAM_nxt addr_state sha_state_nxt))
    (= XRAM_len (store XRAM_state addr_len sha_len_nxt))
    (= XRAM_rdaddr (store XRAM_len addr_rdaddr sha_rdaddr_nxt))
    (= XRAM_wraddr (store XRAM_rdaddr addr_wraddr sha_wraddr_nxt))
    (= HW_REG_WRITE_ptr@%_store4_0 XRAM_wraddr))))
    ;; store
  (=> a!1
      (HW_REG_WRITE_ptr@.split
        HW_REG_WRITE_ptr@%_call_0
        HW_REG_WRITE_ptr@%_store4_0
        HW_REG_WRITE_ptr@%_3_0
        HW_REG_WRITE_ptr@%_2_0
        HW_REG_WRITE_ptr@%_4_0
        @sha_regs_0
        HW_REG_WRITE_ptr@%data_0
        HW_REG_WRITE_ptr@%addr_0))))

