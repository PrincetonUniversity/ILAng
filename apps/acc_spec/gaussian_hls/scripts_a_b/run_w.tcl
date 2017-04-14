set ROOT [pwd]
set SRC $ROOT/verilog
set TCL $ROOT/scripts_a_b
set EXP $ROOT/exps_a_b

include $TCL/setup_w.tcl
include $TCL/eqcheck_w.tcl

set_prove_time_limit 0s; set_prove_per_property_time_limit 0s
set_max_trace_length 25; set_prove_per_property_max_time_limit 60m

#assume -disable {::Subset - A}

#assume -enable {::Subset - A}

#prove -all

#save -jdb $EXP/a_b_wri_A.jdb -capture_setup -capture_session_data

#exit


assert -disable {<embedded>::eq - arg_0_TDATA}; assert -disable {<embedded>::eq - RAM_0}; assert -disable {<embedded>::eq - RAM_1}; assert -disable {<embedded>::eq - RAM_2}; assert -disable {<embedded>::eq - RAM_3}; assert -disable {<embedded>::eq - RAM_4}; assert -disable {<embedded>::eq - RAM_5}; assert -disable {<embedded>::eq - RAM_6}; assert -disable {<embedded>::eq - RAM_7}
assume -disable {::arch equal - data}
assert -disable {<embedded>::eq - stencil_1}; assert -disable {<embedded>::eq - stencil_2}; assert -disable {<embedded>::eq - stencil_3}; assert -disable {<embedded>::eq - stencil_4}; assert -disable {<embedded>::eq - stencil_5}; assert -disable {<embedded>::eq - stencil_6}
assert -disable {<embedded>::eq - cur_pix}
assume -disable {::Subset - A}; assume -disable {::Subset - B}; assume -disable {::Subset - C1}; assume -disable {::Subset - C2}; assume -disable {::Subset - C3}; assume -disable {::Subset - C4}; assume -disable {::Subset - D}; assume -disable {::Subset - E}
assert -disable {<embedded>::eq - stencil_0}; assert -disable {<embedded>::eq - stencil_7}
