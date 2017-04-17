set ROOT [pwd]
set SRC $ROOT/verilog
set TCL $ROOT/scripts_a_b
set EXP $ROOT/exps_a_b

include $TCL/setup_w.tcl
include $TCL/eqcheck_w.tcl

set_prove_time_limit 0s; set_prove_per_property_time_limit 0s
set_max_trace_length 0; set_prove_per_property_max_time_limit 60m

assume -disable {::Subset - A}; assume -disable {::Subset - B}; assume -disable {::Subset - C1}; assume -disable {::Subset - C2}; assume -disable {::Subset - C3}; assume -disable {::Subset - C4}; assume -disable {::Subset - D}; assume -disable {::Subset - E}

#assume -enable {::Subset - A}
#prove -all
#save -jdb $EXP/wri_A.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - A}

#assume -enable {::Subset - E}
#prove -all
#save -jdb $EXP/wri_E.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - E}

#assume -enable {::Subset - C3}
#prove -all
#save -jdb $EXP/wri_C3.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C3}

#assume -enable {::Subset - C4}
#prove -all
#save -jdb $EXP/wri_C4.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C4}

####

#assume -enable {::Subset - B}
#prove -all
#save -jdb $EXP/wri_B.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - B}

#assume -enable {::Subset - D}
#prove -all
#save -jdb $EXP/wri_D.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - D}

####

#assume -enable {::Subset - C1}
#prove -all
#save -jdb $EXP/wri_C1.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C1}

#assume -enable {::Subset - C2}
#prove -all
#save -jdb $EXP/wri_C2.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C2}

#exit

