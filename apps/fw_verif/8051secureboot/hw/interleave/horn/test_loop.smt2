; chc for the nondeterministic loop for interleave ILA
(rule (loop_sha
       sha_state sha_wraddr sha_len sha_bytes_read
       sha_state sha_bytes_read))
;
(rule (=> (and b71
    (loop_sha 
     sha_state sha_wraddr sha_len sha_bytes_read
     sha_state_1 sha_bytes_read_1)
    (rel.delta_1 sha_state_1 b71)
    (rel.N_1_sha_state_nxt sha_bytes_read_1 sha_len sha_state_1 sha_state_nxt)
    (rel.N_1_sha_bytes_read_nxt sha_bytes_read_1 sha_state_1 sha_bytes_read_nxt)
    )
    ;
    (loop_sha 
     sha_state sha_wraddr sha_len sha_bytes_read
     sha_state_nxt sha_bytes_read_nxt)))
;
(rule (=> (and b93
    (loop_sha 
     sha_state sha_wraddr sha_len sha_bytes_read
     sha_state_1 sha_bytes_read_1)
    (rel.delta_2 sha_state_1 b93)
    (rel.N_2_sha_state_nxt sha_bytes_read_1 sha_len sha_state_1 sha_state_nxt)
    (rel.N_2_sha_bytes_read_nxt sha_bytes_read_1 sha_bytes_read_nxt)
    )
    ;
    (loop_sha 
     sha_state sha_wraddr sha_len sha_bytes_read
     sha_state_nxt sha_bytes_read_nxt)))
;
(rule (=> (and b110
    (loop_sha 
     sha_state sha_wraddr sha_len sha_bytes_read
     sha_state_1 sha_bytes_read_1)
    (rel.delta_3 sha_state_1 b110)
    (rel.N_3_sha_state_nxt sha_bytes_read_1 sha_len sha_state_1 sha_state_nxt)
    (rel.N_3_sha_bytes_read_nxt sha_bytes_read_1 sha_bytes_read_nxt)
    )
    ;
    (loop_sha 
     sha_state sha_wraddr sha_len sha_bytes_read
     sha_state_nxt sha_bytes_read_nxt)))
;
(rule (=> (and b127
    (loop_sha 
     sha_state sha_wraddr sha_len sha_bytes_read
     sha_state_1 sha_bytes_read_1)
    (rel.delta_4 sha_state_1 b127)
    (rel.N_4_sha_state_nxt sha_bytes_read_1 sha_len sha_state_1 sha_state_nxt)
    (rel.N_4_sha_bytes_read_nxt sha_bytes_read_1 sha_bytes_read_nxt)
    )
    ;
    (loop_sha 
     sha_state sha_wraddr sha_len sha_bytes_read
     sha_state_nxt sha_bytes_read_nxt)))
