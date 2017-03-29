set ROOT [pwd]
set SRC $ROOT/verilog
set TCL $ROOT/scripts
set EXP $ROOT/exps

include $TCL/setup.tcl
include $TCL/eqcheck_w.tcl

set_prove_per_property_max_time_limit 60m; set_prove_time_limit 0s

assume -disable {::Subset - 1}
assume -disable {::Subset - 1.1}
assume -disable {::Subset - 2}
assume -disable {::Subset - 2.1}
assume -disable {::Subset - 3}
assume -disable {::Subset - 3.1}
assume -disable {::Subset - 4}

#include $TCL/decomp/w_1.tcl
#include $TCL/decomp/w_2.tcl
#include $TCL/decomp/w_3.tcl
include $TCL/decomp/w_4.tcl
