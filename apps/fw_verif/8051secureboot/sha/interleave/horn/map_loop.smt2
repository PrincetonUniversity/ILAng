; chc for the nondeterministic loop for interleave ILA
(rule (loop_sha 
       XRAM sha_hs_data sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read
       XRAM sha_hs_data sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read))
;
(rule (=> (and b71
    (loop_sha 
     XRAM sha_hs_data sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read
     XRAM_1 sha_hs_data_1 sha_state_1 sha_rdaddr_1 sha_wraddr_1 sha_len_1 sha_bytes_read_1)
    (rel.delta_1 sha_state_1 b71)
    (rel.N_1_XRAM_nxt XRAM_1 XRAM_nxt)
    (rel.N_1_sha_state_nxt sha_bytes_read_1 sha_len_1 sha_state_1 sha_state_nxt)
    (rel.N_1_sha_rdaddr_nxt sha_rdaddr_1 sha_rdaddr_nxt)
    (rel.N_1_sha_wraddr_nxt sha_wraddr_1 sha_wraddr_nxt)
    (rel.N_1_sha_len_nxt sha_len_1 sha_len_nxt)
    (rel.N_1_sha_bytes_read_nxt sha_bytes_read_1 sha_state_1 sha_bytes_read_nxt)
    )
    (loop_sha 
     XRAM sha_hs_data sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read
     XRAM_nxt sha_hs_data_nxt sha_state_nxt sha_rdaddr_nxt sha_wraddr_nxt sha_len_nxt sha_bytes_read_nxt)))
;
(rule (=> (and b98
    (loop_sha 
     XRAM sha_hs_data sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read
     XRAM_1 sha_hs_data_1 sha_state_1 sha_rdaddr_1 sha_wraddr_1 sha_len_1 sha_bytes_read_1)
    (rel.delta_2 sha_state_1 b98)
    (rel.N_2_XRAM_nxt XRAM_1 XRAM_nxt)
    (rel.N_2_sha_state_nxt sha_bytes_read_1 sha_len_1 sha_state_1 sha_state_nxt)
    (rel.N_2_sha_rdaddr_nxt sha_rdaddr_1 sha_rdaddr_nxt)
    (rel.N_2_sha_wraddr_nxt sha_wraddr_1 sha_wraddr_nxt)
    (rel.N_2_sha_len_nxt sha_len_1 sha_len_nxt)
    (rel.N_2_sha_bytes_read_nxt sha_bytes_read_1 sha_bytes_read_nxt)
    )
    (loop_sha 
     XRAM sha_hs_data sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read
     XRAM_nxt sha_hs_data_nxt sha_state_nxt sha_rdaddr_nxt sha_wraddr_nxt sha_len_nxt sha_bytes_read_nxt)))
;
(rule (=> (and b115
    (loop_sha 
     XRAM sha_hs_data sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read
     XRAM_1 sha_hs_data_1 sha_state_1 sha_rdaddr_1 sha_wraddr_1 sha_len_1 sha_bytes_read_1)
    (rel.delta_3 sha_state_1 b115)
    (rel.N_3_XRAM_nxt XRAM_1 XRAM_nxt)
    (rel.N_3_sha_state_nxt sha_bytes_read_1 sha_len_1 sha_state_1 sha_state_nxt)
    (rel.N_3_sha_rdaddr_nxt sha_rdaddr_1 sha_rdaddr_nxt)
    (rel.N_3_sha_wraddr_nxt sha_wraddr_1 sha_wraddr_nxt)
    (rel.N_3_sha_len_nxt sha_len_1 sha_len_nxt)
    (rel.N_3_sha_bytes_read_nxt sha_bytes_read_1 sha_bytes_read_nxt)
    )
    (loop_sha 
     XRAM sha_hs_data sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read
     XRAM_nxt sha_hs_data_nxt sha_state_nxt sha_rdaddr_nxt sha_wraddr_nxt sha_len_nxt sha_bytes_read_nxt)))
;
(rule (=> (and b137
    (loop_sha 
     XRAM sha_hs_data sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read
     XRAM_1 sha_hs_data_1 sha_state_1 sha_rdaddr_1 sha_wraddr_1 sha_len_1 sha_bytes_read_1)
    (rel.delta_4 sha_state_1 b137)
    (rel.N_4_XRAM_nxt XRAM_1 sha_hs_data_1 sha_state_1 sha_wraddr_1 XRAM_nxt)
    ;(= XRAM_1 XRAM_nxt)
    (rel.N_4_sha_state_nxt sha_bytes_read_1 sha_len_1 sha_state_1 sha_state_nxt)
    (rel.N_4_sha_rdaddr_nxt sha_rdaddr_1 sha_rdaddr_nxt)
    (rel.N_4_sha_wraddr_nxt sha_wraddr_1 sha_wraddr_nxt)
    (rel.N_4_sha_len_nxt sha_len_1 sha_len_nxt)
    (rel.N_4_sha_bytes_read_nxt sha_bytes_read_1 sha_bytes_read_nxt)
    )
    (loop_sha 
     XRAM sha_hs_data sha_state sha_rdaddr sha_wraddr sha_len sha_bytes_read
     XRAM_nxt sha_hs_data_nxt sha_state_nxt sha_rdaddr_nxt sha_wraddr_nxt sha_len_nxt sha_bytes_read_nxt)))
