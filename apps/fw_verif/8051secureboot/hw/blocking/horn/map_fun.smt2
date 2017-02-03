; chc for blocking function call
(rule (=> (and b0
    (rel.delta_fe00 cmd cmdaddr sha_state b0)
    (rel.N_fe00_XRAM_nxt XRAM XRAM_nxt)
    (rel.N_fe00_sha_state_nxt cmd cmdaddr cmddata sha_state sha_state_nxt)
    (rel.N_fe00_sha_rdaddr_nxt sha_rdaddr sha_rdaddr_nxt)
    (rel.N_fe00_sha_wraddr_nxt sha_wraddr sha_wraddr_nxt)
    (rel.N_fe00_sha_len_nxt sha_len sha_len_nxt)
    (rel.N_fe00_sha_bytes_read_nxt cmd cmdaddr cmddata sha_bytes_read sha_state sha_bytes_read_nxt)
    (rel.N_fe00_sha_hs_data_nxt sha_hs_data sha_hs_data_nxt)
    )
    (mmio_sha_fe00_A 
     cmd cmdaddr cmddata XRAM sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read sha_hs_data
     XRAM_nxt sha_state_nxt sha_rdaddr_nxt sha_wraddr_nxt sha_len_nxt sha_bytes_read_nxt sha_hs_data_nxt)))
;
(rule (=> (and true
    (mmio_sha_fe00_A
     cmd cmdaddr cmddata XRAM sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read sha_hs_data
     XRAM_1 sha_state_1 sha_rdaddr_1 sha_wraddr_1 sha_len_1 sha_bytes_read_1 sha_hs_data_1)
    b71
    (rel.delta_1 sha_state_1 b71)
    (rel.N_1_XRAM_nxt XRAM_1 XRAM_2)
    (rel.N_1_sha_state_nxt sha_bytes_read_1 sha_len_1 sha_state_1 sha_state_2)
    (rel.N_1_sha_rdaddr_nxt sha_rdaddr_1 sha_rdaddr_2)
    (rel.N_1_sha_wraddr_nxt sha_wraddr_1 sha_wraddr_2)
    (rel.N_1_sha_len_nxt sha_len_1 sha_len_2)
    (rel.N_1_sha_bytes_read_nxt sha_bytes_read_1 sha_state_1 sha_bytes_read_2)
    b98
    (rel.delta_2 sha_state_2 b98)
    (rel.N_2_XRAM_nxt XRAM_2 XRAM_nxt)
    (rel.N_2_sha_state_nxt sha_bytes_read_2 sha_len_2 sha_state_2 sha_state_3)
    (rel.N_2_sha_rdaddr_nxt sha_rdaddr_2 sha_rdaddr_3)
    (rel.N_2_sha_wraddr_nxt sha_wraddr_2 sha_wraddr_3)
    (rel.N_2_sha_len_nxt sha_len_2 sha_len_3)
    (rel.N_2_sha_bytes_read_nxt sha_bytes_read_2 sha_bytes_read_3)
    b115
    (rel.delta_3 sha_state_3 b115)
    (rel.N_3_XRAM_nxt XRAM_3 XRAM_nxt)
    (rel.N_3_sha_state_nxt sha_bytes_read_3 sha_len_3 sha_state_3 sha_state_nxt)
    (rel.N_3_sha_rdaddr_nxt sha_rdaddr_3 sha_rdaddr_nxt)
    (rel.N_3_sha_wraddr_nxt sha_wraddr_3 sha_wraddr_nxt)
    (rel.N_3_sha_len_nxt sha_len_3 sha_len_nxt)
    (rel.N_3_sha_bytes_read_nxt sha_bytes_read_3 sha_bytes_read_nxt)
    )
    (mmio_sha_fe00_B
     cmd cmdaddr cmddata XRAM sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read sha_hs_data
     XRAM_nxt sha_state_nxt sha_rdaddr_nxt sha_wraddr_nxt sha_len_nxt sha_bytes_read_nxt sha_hs_data_nxt)))
;
(rule (=> (and true
    (mmio_sha_fe00_B
     cmd cmdaddr cmddata XRAM sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read sha_hs_data
     XRAM_nxt sha_state_nxt sha_rdaddr_nxt sha_wraddr_nxt sha_len_nxt sha_bytes_read_nxt sha_hs_data_nxt)
    b71
    (rel.delta_1 sha_state_nxt b71)
    )
    (mmio_sha_fe00_A 
     cmd cmdaddr cmddata XRAM sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read sha_hs_data
     XRAM_nxt sha_state_nxt sha_rdaddr_nxt sha_wraddr_nxt sha_len_nxt sha_bytes_read_nxt sha_hs_data_nxt)))
;
(rule (=> (and true
    (mmio_sha_fe00_B
     cmd cmdaddr cmddata XRAM sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read sha_hs_data
     XRAM_1 sha_state_1 sha_rdaddr_1 sha_wraddr_1 sha_len_1 sha_bytes_read_1 sha_hs_data_1)
    b137
    (rel.delta_4 sha_state_1 b137)
    (rel.N_4_XRAM_nxt XRAM_1 sha_hs_data_1 sha_state_1 sha_wraddr_1 XRAM_nxt)
    ;(= XRAM_1 XRAM_nxt)
    (rel.N_4_sha_state_nxt sha_bytes_read_1 sha_len_1 sha_state_1 sha_state_nxt)
    (rel.N_4_sha_rdaddr_nxt sha_rdaddr_1 sha_rdaddr_nxt)
    (rel.N_4_sha_wraddr_nxt sha_wraddr_1 sha_wraddr_nxt)
    (rel.N_4_sha_len_nxt sha_len_1 sha_len_nxt)
    (rel.N_4_sha_bytes_read_nxt sha_bytes_read_1 sha_bytes_read_nxt)
    )
    (mmio_sha_fe00_C
     cmd cmdaddr cmddata XRAM sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read sha_hs_data
     XRAM_nxt sha_state_nxt sha_rdaddr_nxt sha_wraddr_nxt sha_len_nxt sha_bytes_read_nxt sha_hs_data_nxt)))

;; clauses for instruction
(rule (=> (and true
    (mmio_sha_fe00_C
     cmd cmdaddr cmddata XRAM sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read sha_hs_data
     XRAM_nxt sha_state_nxt sha_rdaddr_nxt sha_wraddr_nxt sha_len_nxt sha_bytes_read_nxt sha_hs_data_nxt)
    )
    (mmio_sha_fe00
     cmd cmdaddr cmddata XRAM sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read sha_hs_data
     XRAM_nxt sha_state_nxt sha_rdaddr_nxt sha_wraddr_nxt sha_len_nxt sha_bytes_read_nxt sha_hs_data_nxt)))
;
(rule (=> (and b54
    (rel.delta_fe01 cmd cmdaddr sha_state b54)
    (rel.N_fe01_XRAM_nxt XRAM XRAM_nxt)
    (rel.N_fe01_sha_state_nxt sha_state sha_state_nxt)
    (rel.N_fe01_sha_rdaddr_nxt sha_rdaddr sha_rdaddr_nxt)
    (rel.N_fe01_sha_wraddr_nxt sha_wraddr sha_wraddr_nxt)
    (rel.N_fe01_sha_len_nxt sha_len sha_len_nxt)
    (rel.N_fe01_sha_bytes_read_nxt sha_bytes_read sha_bytes_read_nxt)
    )
    (mmio_sha_fe01
     cmd cmdaddr cmddata XRAM sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read sha_hs_data
     XRAM_nxt sha_state_nxt sha_rdaddr_nxt sha_wraddr_nxt sha_len_nxt sha_bytes_read_nxt sha_hs_data_nxt)))

