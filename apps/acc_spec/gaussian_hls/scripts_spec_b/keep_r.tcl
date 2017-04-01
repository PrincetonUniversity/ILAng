set ROOT [pwd]
set SRC $ROOT/verilog
set TCL $ROOT/scripts
set EXP $ROOT/exps

#restore -jdb $EXP/r1_d.jdb
#restore -jdb $EXP/r2_d.jdb

assert -name {<embedded>::eq - LB1D_in} {(counter > 1 & ila_complete == 1 & hls_complete == 1 & hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.in_axi_stream_V_value_V_0_has_vld_data_reg == 1) |-> (  ila_LB1D_in == hls_LB1D_in  )} -update_db -replace;

set_prove_time_limit 0s; set_prove_per_property_time_limit 0s
set_max_trace_length 15

prove -property {{<embedded>::eq - stencil_stream_buff_0} {<embedded>::eq - stencil_stream_buff_1} {<embedded>::eq - LB2D_shift_7} {<embedded>::eq - arg_0_TDATA} {<embedded>::eq - LB2D_proc_0} {<embedded>::eq - LB2D_proc_1} {<embedded>::eq - LB2D_proc_2} {<embedded>::eq - LB2D_proc_3} {<embedded>::eq - LB2D_proc_4} {<embedded>::eq - LB2D_proc_5} {<embedded>::eq - LB2D_proc_6} {<embedded>::eq - LB1D_in}}

#save -jdb $EXP/r1_d2.jdb -capture_setup -capture_session_data
#save -jdb $EXP/r2_d2.jdb -capture_setup -capture_session_data
