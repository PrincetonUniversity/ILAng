# set up all assumptions and assertions for the read instruction.
#
assume -clear -env
assert -clear

include $TCL/cond_r.tcl
include $TCL/cond_r_ila.tcl
include $TCL/cond_r_hls.tcl

include $TCL/prop_r.tcl
