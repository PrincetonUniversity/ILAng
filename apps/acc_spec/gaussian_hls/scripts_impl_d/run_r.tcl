set ROOT [pwd]
set SRC $ROOT/verilog
set TCL $ROOT/scripts_impl_d
set EXP $ROOT/exps_impl_d

include $TCL/setup_r.tcl
include $TCL/eqcheck_r.tcl

set_prove_time_limit 0s; set_prove_per_property_time_limit 0s
set_max_trace_length 30; set_prove_per_property_max_time_limit 60m

assume -disable {::Subset - C1}
assume -disable {::Subset - C2}
assume -disable {::Subset - C3}
assume -disable {::Subset - C4}
assume -disable {::Subset - D}
assume -disable {::Subset - E}

#assert -disable <embedded>::terminate

assume -disable {::arch equal - data}; 
assume -disable {::init - consistent RAM access}

#assume -enable {::Subset - C1}
#include $TCL/bound_hint_r.tcl
#prove -all
#save -jdb $EXP/rdi_ctr_C1.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C1}

#assume -enable {::Subset - C2}
#include $TCL/bound_hint_r.tcl
#prove -all
#save -jdb $EXP/rdi_ctr_C2.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C2}

#assume -enable {::Subset - C3}
#include $TCL/bound_hint_r.tcl
#prove -all
#save -jdb $EXP/rdi_ctr_C3.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C3}

#assume -enable {::Subset - C4}
#include $TCL/bound_hint_r.tcl
#prove -all
#save -jdb $EXP/rdi_ctr_C4.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C4}

#assume -enable {::Subset - D}
#include $TCL/bound_hint_r.tcl
#prove -all
#save -jdb $EXP/rdi_ctr_D.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - D}

#assume -enable {::Subset - E}
#include $TCL/bound_hint_r.tcl
#prove -all
#save -jdb $EXP/rdi_ctr_E.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - E}

########

#assume -enable {::arch equal - data}
#assume -enable {::init - consistent RAM access}

#assume -enable {::Subset - C1}
#prove -all
#save -jdb $EXP/rdi_dat_C1.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C1}

#assume -enable {::Subset - C2}
#prove -all
#save -jdb $EXP/rdi_dat_C2.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C2}

#assume -enable {::Subset - C3}
#prove -all
#save -jdb $EXP/rdi_dat_C3.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C3}

#assume -enable {::Subset - D}
#prove -all
#save -jdb $EXP/rdi_dat_D.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - D}

#assume -enable {::Subset - E}
#prove -all
#save -jdb $EXP/rdi_dat_E.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - E}

#exit

