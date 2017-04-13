set ROOT [pwd]
set SRC $ROOT/verilog
set TCL $ROOT/scripts_spec_a
set EXP $ROOT/exps_spec_a

include $TCL/setup_r.tcl
include $TCL/eqcheck_r.tcl

set_prove_time_limit 0s; set_prove_per_property_time_limit 0s
#set_max_trace_length 25; set_prove_per_property_max_time_limit 60m
set_prove_per_property_max_time_limit 60m

assert -disable {<embedded>::eq - RAM_0}; assert -disable {<embedded>::eq - RAM_1}; assert -disable {<embedded>::eq - RAM_2}; assert -disable {<embedded>::eq - RAM_3}; assert -disable {<embedded>::eq - RAM_4}; assert -disable {<embedded>::eq - RAM_5}; assert -disable {<embedded>::eq - RAM_6}; assert -disable {<embedded>::eq - RAM_7}

assume -disable {::Subset - C1}
assume -disable {::Subset - C2}
assume -disable {::Subset - C3}
assume -disable {::Subset - D}
assume -disable {::Subset - E}

#assume -enable {::Subset - C1}
#assume -enable {::Subset - C2}
#assume -enable {::Subset - C3}
#assume -enable {::Subset - D}
#assume -enable {::Subset - E}

#prove -all

#save -jdb $EXP/spec_a_rdi_C1.jdb -capture_setup -capture_session_data
#save -jdb $EXP/spec_a_rdi_C2.jdb -capture_setup -capture_session_data
#save -jdb $EXP/spec_a_rdi_C3.jdb -capture_setup -capture_session_data
#save -jdb $EXP/spec_a_rdi_D.jdb -capture_setup -capture_session_data
#save -jdb $EXP/spec_a_rdi_E.jdb -capture_setup -capture_session_data

#exit

