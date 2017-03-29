set ROOT [pwd]
set SRC $ROOT/verilog
set TCL $ROOT/scripts
set EXP $ROOT/exps

include $TCL/setup.tcl
include $TCL/eqcheck_r.tcl

set_max_trace_length 25; set_prove_per_property_max_time_limit 60m

assert -disable {<embedded>::eq - LB1D_in}; assert -disable {<embedded>::eq - LB1D_buff}; assert -disable {<embedded>::eq - in_stream_buff_0}; assert -disable {<embedded>::eq - in_stream_buff_1}; assert -disable {<embedded>::eq - slice_stream_buff_0}; assert -disable {<embedded>::eq - slice_stream_buff_1}; assert -disable {<embedded>::eq - stencil_stream_buff_0}; assert -disable {<embedded>::eq - stencil_stream_buff_1}; assert -disable {<embedded>::eq - LB2D_shift_0}; assert -disable {<embedded>::eq - LB2D_shift_1}; assert -disable {<embedded>::eq - LB2D_shift_2}; assert -disable {<embedded>::eq - LB2D_shift_3}; assert -disable {<embedded>::eq - LB2D_shift_4}; assert -disable {<embedded>::eq - LB2D_shift_5}; assert -disable {<embedded>::eq - LB2D_shift_6}; assert -disable {<embedded>::eq - LB2D_shift_7}; assert -disable {<embedded>::eq - arg_0_TDATA}; assert -disable {<embedded>::eq - LB2D_proc_0}; assert -disable {<embedded>::eq - LB2D_proc_1}; assert -disable {<embedded>::eq - LB2D_proc_2}; assert -disable {<embedded>::eq - LB2D_proc_3}; assert -disable {<embedded>::eq - LB2D_proc_4}; assert -disable {<embedded>::eq - LB2D_proc_5}; assert -disable {<embedded>::eq - LB2D_proc_6}; assert -disable {<embedded>::eq - LB2D_proc_7}

assume -disable {::arch equal - data}
