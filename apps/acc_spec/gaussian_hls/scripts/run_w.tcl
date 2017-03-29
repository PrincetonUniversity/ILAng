set ROOT [pwd]
set SRC $ROOT/verilog
set TCL $ROOT/scripts
set EXP $ROOT/exps

include $TCL/setup.tcl
include $TCL/eqcheck_w.tcl

set_max_trace_length 25; set_prove_per_property_max_time_limit 60m

assume -disable {::Subset - 1}
assume -disable {::Subset - 1.1}
assume -disable {::Subset - 2}
assume -disable {::Subset - 2.1}
assume -disable {::Subset - 3}
assume -disable {::Subset - 3.1}
assume -disable {::Subset - 4}

assert -disable {<embedded>::terminate - ila}; assert -disable {<embedded>::terminate - hls}; assert -disable {<embedded>::eq - arg_1_TREADY}; assert -disable {<embedded>::eq - arg_0_TVALID}; assert -disable {<embedded>::eq - LB1D_p_cnt}; assert -disable {<embedded>::eq - in_stream_empty}; assert -disable {<embedded>::eq - in_stream_full}; assert -disable {<embedded>::eq - LB2D_proc_x}; assert -disable {<embedded>::eq - LB2D_proc_y}; assert -disable {<embedded>::eq - LB2D_proc_w}; assert -disable {<embedded>::eq - slice_stream_empty}; assert -disable {<embedded>::eq - slice_stream_full}; assert -disable {<embedded>::eq - LB2D_shift_x}; assert -disable {<embedded>::eq - LB2D_shift_y}; assert -disable {<embedded>::eq - stencil_stream_empty}; assert -disable {<embedded>::eq - stencil_stream_full}; assert -disable {<embedded>::eq - pp_it_1}; assert -disable {<embedded>::eq - pp_it_2}; assert -disable {<embedded>::eq - pp_it_3}; assert -disable {<embedded>::eq - pp_it_4}; assert -disable {<embedded>::eq - pp_it_5}; assert -disable {<embedded>::eq - pp_it_6}; assert -disable {<embedded>::eq - pp_it_7}; assert -disable {<embedded>::eq - pp_it_8}; assert -disable {<embedded>::eq - pp_it_9}; assert -disable {<embedded>::eq - exit_it_1}; assert -disable {<embedded>::eq - exit_it_2}; assert -disable {<embedded>::eq - exit_it_3}; assert -disable {<embedded>::eq - exit_it_4}; assert -disable {<embedded>::eq - exit_it_5}; assert -disable {<embedded>::eq - exit_it_6}; assert -disable {<embedded>::eq - exit_it_7}; assert -disable {<embedded>::eq - LB1D_in}; assert -disable {<embedded>::eq - LB1D_buff}; assert -disable {<embedded>::eq - in_stream_buff_0}; assert -disable {<embedded>::eq - in_stream_buff_1}; assert -disable {<embedded>::eq - slice_stream_buff_0}; assert -disable {<embedded>::eq - slice_stream_buff_1}; assert -disable {<embedded>::eq - stencil_stream_buff_0}; assert -disable {<embedded>::eq - stencil_stream_buff_1}; assert -disable {<embedded>::eq - LB2D_shift_0}; assert -disable {<embedded>::eq - LB2D_shift_1}; assert -disable {<embedded>::eq - LB2D_shift_2}; assert -disable {<embedded>::eq - LB2D_shift_3}; assert -disable {<embedded>::eq - LB2D_shift_4}; assert -disable {<embedded>::eq - LB2D_shift_5}; assert -disable {<embedded>::eq - LB2D_shift_6}; assert -disable {<embedded>::eq - LB2D_shift_7}; assert -disable {<embedded>::eq - arg_0_TDATA}; assert -disable {<embedded>::eq - LB2D_proc_0}; assert -disable {<embedded>::eq - LB2D_proc_1}; assert -disable {<embedded>::eq - LB2D_proc_2}; assert -disable {<embedded>::eq - LB2D_proc_3}; assert -disable {<embedded>::eq - LB2D_proc_4}; assert -disable {<embedded>::eq - LB2D_proc_5}; assert -disable {<embedded>::eq - LB2D_proc_6}; assert -disable {<embedded>::eq - LB2D_proc_7}

assume -disable {::arch equal - data}

assert -enable {<embedded>::terminate - ila}; assert -enable {<embedded>::terminate - hls}; assert -enable {<embedded>::eq - arg_1_TREADY}; assert -enable {<embedded>::eq - arg_0_TVALID}; assert -enable {<embedded>::eq - LB1D_p_cnt}; assert -enable {<embedded>::eq - in_stream_empty}; assert -enable {<embedded>::eq - in_stream_full}; assert -enable {<embedded>::eq - LB2D_proc_x}; assert -enable {<embedded>::eq - LB2D_proc_y}; assert -enable {<embedded>::eq - LB2D_proc_w}; assert -enable {<embedded>::eq - slice_stream_empty}; assert -enable {<embedded>::eq - slice_stream_full}; assert -enable {<embedded>::eq - LB2D_shift_x}; assert -enable {<embedded>::eq - LB2D_shift_y}; assert -enable {<embedded>::eq - stencil_stream_empty}; assert -enable {<embedded>::eq - stencil_stream_full}; assert -enable {<embedded>::eq - pp_it_1}; assert -enable {<embedded>::eq - pp_it_2}; assert -enable {<embedded>::eq - pp_it_3}; assert -enable {<embedded>::eq - pp_it_4}; assert -enable {<embedded>::eq - pp_it_5}; assert -enable {<embedded>::eq - pp_it_6}; assert -enable {<embedded>::eq - pp_it_7}; assert -enable {<embedded>::eq - pp_it_8}; assert -enable {<embedded>::eq - pp_it_9}; assert -enable {<embedded>::eq - exit_it_1}; assert -enable {<embedded>::eq - exit_it_2}; assert -enable {<embedded>::eq - exit_it_3}; assert -enable {<embedded>::eq - exit_it_4}; assert -enable {<embedded>::eq - exit_it_5}; assert -enable {<embedded>::eq - exit_it_6}; assert -enable {<embedded>::eq - exit_it_7}

#assume -enable {::Subset - 1}
#assume -enable {::Subset - 2}
#assume -enable {::Subset - 3}
assume -enable {::Subset - 4}

prove -all

#save -jdb $EXP/w1_c.jdb -capture_setup -capture_session_data
#save -jdb $EXP/w2_c.jdb -capture_setup -capture_session_data
#save -jdb $EXP/w3_c.jdb -capture_setup -capture_session_data
save -jdb $EXP/w4_c.jdb -capture_setup -capture_session_data

assert -disable {<embedded>::eq - arg_1_TREADY}; assert -disable {<embedded>::eq - arg_0_TVALID}; assert -disable {<embedded>::eq - LB1D_p_cnt}; assert -disable {<embedded>::eq - in_stream_empty}; assert -disable {<embedded>::eq - in_stream_full}; assert -disable {<embedded>::eq - LB2D_proc_x}; assert -disable {<embedded>::eq - LB2D_proc_y}; assert -disable {<embedded>::eq - LB2D_proc_w}; assert -disable {<embedded>::eq - slice_stream_empty}; assert -disable {<embedded>::eq - slice_stream_full}; assert -disable {<embedded>::eq - LB2D_shift_x}; assert -disable {<embedded>::eq - LB2D_shift_y}; assert -disable {<embedded>::eq - stencil_stream_empty}; assert -disable {<embedded>::eq - stencil_stream_full}; assert -disable {<embedded>::eq - pp_it_1}; assert -disable {<embedded>::eq - pp_it_2}; assert -disable {<embedded>::eq - pp_it_3}; assert -disable {<embedded>::eq - pp_it_4}; assert -disable {<embedded>::eq - pp_it_5}; assert -disable {<embedded>::eq - pp_it_6}; assert -disable {<embedded>::eq - pp_it_7}; assert -disable {<embedded>::eq - pp_it_8}; assert -disable {<embedded>::eq - pp_it_9}; assert -disable {<embedded>::eq - exit_it_1}; assert -disable {<embedded>::eq - exit_it_2}; assert -disable {<embedded>::eq - exit_it_3}; assert -disable {<embedded>::eq - exit_it_4}; assert -disable {<embedded>::eq - exit_it_5}; assert -disable {<embedded>::eq - exit_it_6}; assert -disable {<embedded>::eq - exit_it_7}

assert -enable {<embedded>::eq - LB1D_in}; assert -enable {<embedded>::eq - LB1D_buff}; assert -enable {<embedded>::eq - in_stream_buff_0}; assert -enable {<embedded>::eq - in_stream_buff_1}; assert -enable {<embedded>::eq - slice_stream_buff_0}; assert -enable {<embedded>::eq - slice_stream_buff_1}; assert -enable {<embedded>::eq - stencil_stream_buff_0}; assert -enable {<embedded>::eq - stencil_stream_buff_1}; assert -enable {<embedded>::eq - LB2D_shift_0}; assert -enable {<embedded>::eq - LB2D_shift_1}; assert -enable {<embedded>::eq - LB2D_shift_2}; assert -enable {<embedded>::eq - LB2D_shift_3}; assert -enable {<embedded>::eq - LB2D_shift_4}; assert -enable {<embedded>::eq - LB2D_shift_5}; assert -enable {<embedded>::eq - LB2D_shift_6}; assert -enable {<embedded>::eq - LB2D_shift_7}; assert -enable {<embedded>::eq - arg_0_TDATA}; assert -enable {<embedded>::eq - LB2D_proc_0}; assert -enable {<embedded>::eq - LB2D_proc_1}; assert -enable {<embedded>::eq - LB2D_proc_2}; assert -enable {<embedded>::eq - LB2D_proc_3}; assert -enable {<embedded>::eq - LB2D_proc_4}; assert -enable {<embedded>::eq - LB2D_proc_5}; assert -enable {<embedded>::eq - LB2D_proc_6}; assert -enable {<embedded>::eq - LB2D_proc_7}

assume -enable {::arch equal - data}

prove -all

#save -jdb $EXP/w1_d.jdb -capture_setup -capture_session_data
#save -jdb $EXP/w2_d.jdb -capture_setup -capture_session_data
#save -jdb $EXP/w3_d.jdb -capture_setup -capture_session_data
save -jdb $EXP/w4_d.jdb -capture_setup -capture_session_data

