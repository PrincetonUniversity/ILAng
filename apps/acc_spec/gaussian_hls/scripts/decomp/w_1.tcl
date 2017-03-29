
assume -enable {::Subset - 1}
prove -all

#save -jdb $EXP/proof_w_1 -capture_setup -capture_session_data
save -jdb $EXP/proof_w_1.jdb -capture_session_data

