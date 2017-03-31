set ROOT [pwd]
set SRC $ROOT/verilog
set TCL $ROOT/scripts
set EXP $ROOT/exps

restore -jdb $EXP/w1_d.jdb
#restore -jdb $EXP/w2_d.jdb

set_max_trace_length 15; set_prove_time_limit 0s; set_prove_per_property_time_limit 0s

prove -all

save -jdb $EXP/w1_d2.jdb -capture_setup -capture_session_data
#save -jdb $EXP/w2_d2.jdb -capture_setup -capture_session_data

