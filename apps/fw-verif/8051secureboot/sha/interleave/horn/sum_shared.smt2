; shared definition for the mapping
;; variables
(declare-var sha_state_nxt Int)
(declare-var sha_bytes_read_nxt Int)
;
(declare-var sha_state_1 Int)
(declare-var sha_bytes_read_1 Int)
;
(declare-var XRAM_state (Array Int Int))
(declare-var XRAM_bytes (Array Int Int))
;
(declare-var addr_state Int)
(declare-var addr_wraddr Int)
(declare-var addr_len Int)
(declare-var addr_bytes Int)

;; relations
(declare-rel loop_sha (Int Int Int Int Int Int))
(declare-rel sha_fe00 (Int Int Int Int Int))
(declare-rel sha_fe01 (Int Int))

;; clauses
(rule (=> (and 
    (= cmd 2)
    (= cmdaddr 65024)
    (rel.N_fe00_sha_state_nxt cmd cmdaddr cmddata sha_state sha_state_nxt)
    (rel.N_fe00_sha_bytes_read_nxt cmd cmdaddr cmddata sha_bytes_read sha_state sha_bytes_read_nxt)
    )
    ;
    (sha_fe00 cmddata sha_state sha_bytes_read sha_state_nxt sha_bytes_read_nxt)))
;
(rule (=> (and true
    (= sha_state sha_state_nxt)
    )
    ;
    (sha_fe01 sha_state sha_state_nxt)))
