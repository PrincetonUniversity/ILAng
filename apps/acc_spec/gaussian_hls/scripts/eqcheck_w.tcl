# set up all assumptions and assertions for the write instruction.
#
assume -clear -env
assert -clear

include $TCL/exec_w.tcl
include $TCL/comp_w.tcl
include $TCL/init_w.tcl
include $TCL/invariant.tcl
include $TCL/property.tcl
