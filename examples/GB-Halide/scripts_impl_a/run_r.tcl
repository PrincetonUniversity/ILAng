set ROOT [pwd]
set SRC $ROOT/verilog
set TCL $ROOT/scripts_impl_a
set EXP $ROOT/exps_impl_a

include $TCL/setup_r.tcl
include $TCL/eqcheck_r.tcl

set_prove_time_limit 0s; set_prove_per_property_time_limit 0s
set_max_trace_length 0; set_prove_per_property_max_time_limit 60m
set_engine_mode {Hp Ht Bm J B D I M N G Hps Hts}

assume -disable {::Subset - C1}
assume -disable {::Subset - C2}
assume -disable {::Subset - C3}
assume -disable {::Subset - D}
assume -disable {::Subset - E}

#prove -property {<embedded>::bound}

#set_max_trace_length 15; set_prove_per_property_max_time_limit 0s

#exit
