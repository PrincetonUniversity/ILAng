set ROOT [pwd]
set SRC $ROOT/verilog
set TCL $ROOT/scripts_spec_a
set EXP $ROOT/exps_spec_a

include $TCL/setup_w.tcl
include $TCL/eqcheck_w.tcl

set_max_trace_length 25; set_prove_per_property_max_time_limit 60m
