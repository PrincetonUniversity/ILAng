set ROOT [pwd]
set SRC $ROOT/verilog
set TCL $ROOT/scripts_impl_a
set EXP $ROOT/exps_impl_a

include $TCL/setup_r.tcl
include $TCL/eqcheck_r.tcl

set_prove_time_limit 0s; set_prove_per_property_time_limit 0s
set_max_trace_length 0; set_prove_per_property_max_time_limit 60m

assume -disable {::Subset - C1}
assume -disable {::Subset - C2}
assume -disable {::Subset - C3}
assume -disable {::Subset - D}
assume -disable {::Subset - E}

#assume -enable {::Subset - C1}
#include $TCL/iterate_ctr_r.tcl
#save -jdb $EXP/rdi_ctr_C1.jdb -capture_setup -capture_session_data
#include $TCL/iterate_dat_r.tcl
#save -jdb $EXP/rdi_dat_C1.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C1}

#assume -enable {::Subset - C2}
#include $TCL/iterate_ctr_r.tcl
#save -jdb $EXP/rdi_ctr_C2.jdb -capture_setup -capture_session_data
#include $TCL/iterate_dat_r.tcl
#save -jdb $EXP/rdi_dat_C2.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C2}

#assume -enable {::Subset - C3}
#include $TCL/iterate_ctr_r.tcl
#save -jdb $EXP/rdi_ctr_C3.jdb -capture_setup -capture_session_data
#include $TCL/iterate_dat_r.tcl
#save -jdb $EXP/rdi_dat_C3.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C3}

#assume -enable {::Subset - D}
#include $TCL/iterate_ctr_r.tcl
#save -jdb $EXP/rdi_ctr_D.jdb -capture_setup -capture_session_data
#include $TCL/iterate_dat_r.tcl
#save -jdb $EXP/rdi_dat_D.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - D}

#assume -enable {::Subset - E}
#include $TCL/iterate_ctr_r.tcl
#save -jdb $EXP/rdi_ctr_E.jdb -capture_setup -capture_session_data
#include $TCL/iterate_dat_r.tcl
#save -jdb $EXP/rdi_dat_E.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - E}

#exit

