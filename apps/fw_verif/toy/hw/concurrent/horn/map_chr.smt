; mapping between ILA to the MMIO functions
;; variables
(declare-var acc_state_nxt (_ BitVec 3))
(declare-var acc_state_nxt_1 (_ BitVec 3))
(declare-var bytes_read_nxt (_ BitVec 16))
(declare-var bytes_read_nxt_1 (_ BitVec 16))
(declare-var XRAM_nxt (Array Int Int))
;; relations
(declare-rel mmio_acc ((_ BitVec 16) (_ BitVec 3) (_ BitVec 16) (_ BitVec 2) (_ BitVec 16) (_ BitVec 8) (_ BitVec 3) (_ BitVec 16)))
(declare-rel loop_acc ((_ BitVec 16) (_ BitVec 3) (_ BitVec 16) (_ BitVec 3) (_ BitVec 16)))
;;;;;;;;;;;;;;;;;;;; clauses for interleaving loop ;;;;;;;;;;;;;;;;;;;;;;;
(rule (loop_acc acc_len acc_state bytes_read acc_state bytes_read))
;
(rule (=> (and b64
            (loop_acc acc_len acc_state bytes_read acc_state_nxt bytes_read_nxt)
            (rel.decode_st1 acc_state_nxt b64)
            (rel.child_1_acc_state_nxt acc_state_nxt acc_state_nxt_1)
            (rel.child_1_bytes_read_nxt acc_state_nxt bytes_read_nxt bytes_read_nxt_1))
          (loop_acc acc_len acc_state bytes_read acc_state_nxt_1 bytes_read_nxt_1)))
;
(rule (=> (and b78
            (loop_acc acc_len acc_state bytes_read acc_state_nxt bytes_read_nxt)
            (rel.decode_st2 acc_state_nxt b78)
            (rel.child_2_acc_state_nxt acc_state_nxt acc_state_nxt_1)
            (rel.child_2_bytes_read_nxt bytes_read_nxt bytes_read_nxt_1))
          (loop_acc acc_len acc_state bytes_read acc_state_nxt_1 bytes_read_nxt_1)))
;
(rule (=> (and b87
            (loop_acc acc_len acc_state bytes_read acc_state_nxt bytes_read_nxt)
            (rel.decode_st3 acc_state_nxt b87)
            (rel.child_3_acc_state_nxt acc_len acc_state_nxt bytes_read_nxt acc_state_nxt_1)
            (rel.child_3_bytes_read_nxt bytes_read_nxt bytes_read_nxt_1))
          (loop_acc acc_len acc_state bytes_read acc_state_nxt_1 bytes_read_nxt_1)))
;
(rule (=> (and b100
            (loop_acc acc_len acc_state bytes_read acc_state_nxt bytes_read_nxt)
            (rel.decode_st4 acc_state_nxt b100)
            (rel.child_4_acc_state_nxt acc_state_nxt acc_state_nxt_1)
            (rel.child_4_bytes_read_nxt bytes_read_nxt bytes_read_nxt_1))
          (loop_acc acc_len acc_state bytes_read acc_state_nxt_1 bytes_read_nxt_1)))
;;;;;;;;;;;;;;;;;;;;;;;;; clauses for instructions ;;;;;;;;;;;;;;;;;;;;;;;;;
(rule (=> (and b0
            (rel.decode_fe00 cmd cmdaddr b0)
            (rel.instr_fe00_acc_state_nxt acc_state cmd cmdaddr cmddata acc_state_nxt)
            (rel.instr_fe00_bytes_read_nxt acc_state bytes_read cmd cmdaddr cmddata bytes_read_nxt)
            (loop_acc acc_len acc_state_nxt bytes_read_nxt acc_state_nxt_1 bytes_read_nxt_1))
          (mmio_acc acc_len acc_state bytes_read cmd cmdaddr cmddata acc_state_nxt_1 bytes_read_nxt_1)))
;
(rule (=> (and b40
            (rel.decode_fe01 cmd cmdaddr b40)
            (rel.instr_fe01_acc_state_nxt acc_state acc_state_nxt)
            (rel.instr_fe01_bytes_read_nxt bytes_read bytes_read_nxt)
            (loop_acc acc_len acc_state_nxt bytes_read_nxt acc_state_nxt_1 bytes_read_nxt_1))
          (mmio_acc acc_len acc_state bytes_read cmd cmdaddr cmddata acc_state_nxt_1 bytes_read_nxt_1)))
;
(rule (=> (and b48
            (rel.decode_fe02 cmd cmdaddr b48)
            (rel.instr_fe02_acc_state_nxt acc_state acc_state_nxt)
            (rel.instr_fe02_bytes_read_nxt bytes_read bytes_read_nxt)
            (loop_acc acc_len acc_state_nxt bytes_read_nxt acc_state_nxt_1 bytes_read_nxt_1))
          (mmio_acc acc_len acc_state bytes_read cmd cmdaddr cmddata acc_state_nxt_1 bytes_read_nxt_1)))
;
(rule (=> (and b56
            (rel.decode_fe03 cmd cmdaddr b56)
            (rel.instr_fe03_acc_state_nxt acc_state acc_state_nxt)
            (rel.instr_fe03_bytes_read_nxt bytes_read bytes_read_nxt)
            (loop_acc acc_len acc_state_nxt bytes_read_nxt acc_state_nxt_1 bytes_read_nxt_1))
          (mmio_acc acc_len acc_state bytes_read cmd cmdaddr cmddata acc_state_nxt_1 bytes_read_nxt_1)))

;;;;;;;;;;;;;;;;;;;;;;;;; clauses for mapping to mmio function ;;;;;;;;;;;;;
(rule (=> (and (HW_REG_WRITE@_1 HW_REG_WRITE@%_2_0
                          HW_REG_WRITE@%data_0
                          HW_REG_WRITE@%addr_0)
         true
         ;; 
         (= cmd #b10)
         (= (bv2int cmdaddr) HW_REG_WRITE@%addr_0)
         (= (bv2int cmddata) HW_REG_WRITE@%data_0)
         ;(= cmddata ((_ int2bv 8) HW_REG_WRITE@%data_0))
         (= (bv2int acc_state) (select HW_REG_WRITE@%_2_0 65025))
         ;(= acc_state ((_ int2bv 3) (select HW_REG_WRITE@%_2_0 65025)))
         (= (bv2int acc_len) (select HW_REG_WRITE@%_2_0 65036))
         (= (bv2int bytes_read) (select HW_REG_WRITE@%_2_0 65040))
         (mmio_acc acc_len acc_state bytes_read cmd cmdaddr cmddata acc_state_nxt bytes_read_nxt)
         ;(= XRAM_nxt (store HW_REG_WRITE@%_2_0 65025 (bv2int acc_state_nxt)))
         ;(= HW_REG_WRITE@%_store_0 (store XRAM_nxt 65040 (bv2int bytes_read_nxt))))
         )
         ;;
    (HW_REG_WRITE@.split
      HW_REG_WRITE@%_2_0
      HW_REG_WRITE@%_store_0
      HW_REG_WRITE@%data_0
      HW_REG_WRITE@%addr_0)))
