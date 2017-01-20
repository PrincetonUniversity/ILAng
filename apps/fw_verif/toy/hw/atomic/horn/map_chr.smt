; mapping between ila and the MMIO function
;; variables
(declare-var acc_state_nxt (_ BitVec 3))
;; relations
(declare-rel mmio_acc ((_ BitVec 3) (_ BitVec 2) (_ BitVec 16) (_ BitVec 3)))
;; clauses for each ILA instruction
(rule (=> (and b0
           (rel.decode_fe00 cmd cmdaddr b0)
           (rel.instr_fe00_acc_state_nxt acc_state cmd cmdaddr acc_state_nxt))
          (mmio_acc acc_state cmd cmdaddr acc_state_nxt)))
;
(rule (=> (and b17
           (rel.decode_fe01 cmd cmdaddr b17)
           (rel.instr_fe01_acc_state_nxt acc_state cmd cmdaddr acc_state_nxt))
          (mmio_acc acc_state cmd cmdaddr acc_state_nxt)))
;
(rule (=> (and b31
           (rel.decode_fe02 cmd cmdaddr b31)
           (rel.instr_fe02_acc_state_nxt acc_state cmd cmdaddr acc_state_nxt))
          (mmio_acc acc_state cmd cmdaddr acc_state_nxt)))
;
(rule (=> (and b45
           (rel.decode_fe03 cmd cmdaddr b45)
           (rel.instr_fe03_acc_state_nxt acc_state cmd cmdaddr acc_state_nxt))
          (mmio_acc acc_state cmd cmdaddr acc_state_nxt)))
;; clauses for mapping to MMIO fuctions
(rule (=> (and (HW_REG_WRITE@_1 HW_REG_WRITE@%_2_0
                          HW_REG_WRITE@%data_0
                          HW_REG_WRITE@%addr_0)
         true
         ;;
         (= cmd #b10)
         ;(= cmdaddr ((_ int2bv 16) HW_REG_WRITE@%addr_0))
         (= (bv2int cmdaddr) HW_REG_WRITE@%addr_0)
         ;(= acc_state ((_ int2bv 3) (select HW_REG_WRITE@%_2_0 65025)))
         (= (bv2int acc_state) (select HW_REG_WRITE@%_2_0 65025))
         (mmio_acc acc_state cmd cmdaddr acc_state_nxt)
         (= HW_REG_WRITE@%_store_0 (store HW_REG_WRITE@%_2_0 65025 
                                        (bv2int acc_state_nxt))))
         ;;
    (HW_REG_WRITE@.split
      HW_REG_WRITE@%_2_0
      HW_REG_WRITE@%_store_0
      HW_REG_WRITE@%data_0
      HW_REG_WRITE@%addr_0)))

