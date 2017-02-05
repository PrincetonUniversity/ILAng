; shared definition for the mapping
;; variables
(declare-var XRAM_nxt (Array Int Int))
(declare-var sha_state_nxt Int)
(declare-var sha_rdaddr_nxt Int)
(declare-var sha_wraddr_nxt Int)
(declare-var sha_len_nxt Int)
(declare-var sha_hs_data_nxt Int)

(declare-var cmdaddr_1 Int)
(declare-var cmddata_1 Int)
(declare-var XRAM_nxt_1 (Array Int Int))
(declare-var sha_state_nxt_1 Int)
(declare-var sha_rdaddr_nxt_1 Int)
(declare-var sha_wraddr_nxt_1 Int)
(declare-var sha_len_nxt_1 Int)
(declare-var sha_hs_data_nxt_1 Int)

(declare-var XRAM_state (Array Int Int))
(declare-var XRAM_rdaddr (Array Int Int))
(declare-var XRAM_wraddr (Array Int Int))
(declare-var XRAM_len (Array Int Int))
;
(declare-var addr_state Int)
(declare-var addr_len Int)
(declare-var addr_rdaddr Int)
(declare-var addr_wraddr Int)
;; relations
;; clauses
