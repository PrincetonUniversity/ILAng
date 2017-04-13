set ROOT [pwd]
set SRC $ROOT/verilog
set TCL $ROOT/scripts_a_b
set EXP $ROOT/exps_a_b

include $TCL/setup_w.tcl
include $TCL/eqcheck_w.tcl

set_prove_time_limit 0s; set_prove_per_property_time_limit 0s
set_max_trace_length 25; set_prove_per_property_max_time_limit 60m

#assume -disable {::Subset - A}

#assume -enable {::Subset - A}

#prove -all

#save -jdb $EXP/a_b_wri_A.jdb -capture_setup -capture_session_data

#exit
