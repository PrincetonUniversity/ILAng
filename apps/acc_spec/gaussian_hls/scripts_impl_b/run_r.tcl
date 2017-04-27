set ROOT [pwd]
set SRC $ROOT/verilog
set TCL $ROOT/scripts_impl_b
set EXP $ROOT/exps_impl_b

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

assert -disable <embedded>::terminate
assume -disable {::arch equal - data}; 
assume -disable {::init - consistent RAM access}

set_max_trace_length 19; set_prove_per_property_max_time_limit 0s

#exit
