set ROOT [pwd]
set SRC $ROOT/verilog
set TCL $ROOT/scripts_impl_d
set EXP $ROOT/exps_impl_d

include $TCL/setup_w.tcl
include $TCL/eqcheck_w.tcl

set_prove_time_limit 0s; set_prove_per_property_time_limit 0s
set_max_trace_length 0; set_prove_per_property_max_time_limit 60m

assume -disable {::Subset - A}
assume -disable {::Subset - B}
assume -disable {::Subset - C1}
assume -disable {::Subset - C2}
assume -disable {::Subset - D}
assume -disable {::Subset - E}

assert -disable <embedded>::terminate

assume -disable {::arch equal - data}; 
assume -disable {::init - consistent RAM access}

set_max_trace_length 16; set_prove_per_property_max_time_limit 0s 

#assume -enable {::Subset - A}
#include $TCL/bound_hint_w.tcl
#prove -all
#save -jdb $EXP/wri_ctr_Hp_A.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - A}

#assume -enable {::Subset - B}
#include $TCL/bound_hint_w.tcl
#prove -all
#save -jdb $EXP/wri_ctr_Hp_B.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - B}

#assume -enable {::Subset - C1}
#include $TCL/bound_hint_w.tcl
#prove -all
#save -jdb $EXP/wri_ctr_Hp_C1.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C1}

#assume -enable {::Subset - C2}
#include $TCL/bound_hint_w.tcl
#prove -all
#save -jdb $EXP/wri_ctr_Hp_C2.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C2}

#assume -enable {::Subset - D}
#include $TCL/bound_hint_w.tcl
#prove -all
#save -jdb $EXP/wri_ctr_Hp_D.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - D}

#assume -enable {::Subset - E}
#include $TCL/bound_hint_w.tcl
#prove -all
#save -jdb $EXP/wri_ctr_Hp_E.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - E}

########

#set_max_trace_length 30; set_prove_per_property_max_time_limit 60m
#set_engine_mode {Hp Ht B N}

#assume -enable {::arch equal - data}
#assume -enable {::init - consistent RAM access}

#assume -from_assert {<embedded>::bound help 0} {<embedded>::bound help 1} {<embedded>::bound help 2} {<embedded>::bound help 3} {<embedded>::bound help 4} {<embedded>::bound help 5} {<embedded>::bound help 6} {<embedded>::bound help 7} {<embedded>::bound help 8} {<embedded>::bound help 9} {<embedded>::bound help 10} {<embedded>::bound help 11} {<embedded>::bound help 12} {<embedded>::bound help 13} {<embedded>::bound help 14} {<embedded>::bound help 15} {<embedded>::bound help 16} {<embedded>::bound help 17} {<embedded>::bound help 18} {<embedded>::bound help 19} {<embedded>::bound help 20} {<embedded>::bound help 21} {<embedded>::bound help 22} {<embedded>::bound help 23} {<embedded>::bound help 24} {<embedded>::bound help 25} {<embedded>::bound help 26} {<embedded>::bound help 27} {<embedded>::bound help 28} {<embedded>::bound help 29} {<embedded>::bound help 30} {<embedded>::bound help 31} {<embedded>::bound end} {<embedded>::bound inv} {<embedded>::bound - ila} {<embedded>::bound - hls} {<embedded>::fix point entry - ila} {<embedded>::fix point entry - hls} {<embedded>::fix point - ila} {<embedded>::fix point - hls}

#assert -enable {<embedded>::eq - LB1D_in}; assert -enable {<embedded>::eq - LB1D_buff}; assert -enable {<embedded>::eq - in_stream_buff_0}; assert -enable {<embedded>::eq - in_stream_buff_1}; assert -enable {<embedded>::eq - slice_stream_buff_0}; assert -enable {<embedded>::eq - slice_stream_buff_1}; assert -enable {<embedded>::eq - stencil_stream_buff_0}; assert -enable {<embedded>::eq - stencil_stream_buff_1}; assert -enable {<embedded>::eq - LB2D_shift_0}; assert -enable {<embedded>::eq - LB2D_shift_1}; assert -enable {<embedded>::eq - LB2D_shift_2}; assert -enable {<embedded>::eq - LB2D_shift_3}; assert -enable {<embedded>::eq - LB2D_shift_4}; assert -enable {<embedded>::eq - LB2D_shift_5}; assert -enable {<embedded>::eq - LB2D_shift_6}; assert -enable {<embedded>::eq - LB2D_shift_7}; assert -enable {<embedded>::eq - arg_0_TDATA}; assert -enable {<embedded>::eq - LB2D_proc_0}; assert -enable {<embedded>::eq - LB2D_proc_1}; assert -enable {<embedded>::eq - LB2D_proc_2}; assert -enable {<embedded>::eq - LB2D_proc_3}; assert -enable {<embedded>::eq - LB2D_proc_4}; assert -enable {<embedded>::eq - LB2D_proc_5}; assert -enable {<embedded>::eq - LB2D_proc_6}; assert -enable {<embedded>::eq - LB2D_proc_7}

#assert -disable <embedded>::terminate; assert -disable {<embedded>::eq - arg_1_TREADY}; assert -disable {<embedded>::eq - arg_0_TVALID}; assert -disable {<embedded>::eq - LB1D_p_cnt}; assert -disable {<embedded>::eq - in_stream_empty}; assert -disable {<embedded>::eq - in_stream_full}; assert -disable {<embedded>::eq - LB2D_proc_x}; assert -disable {<embedded>::eq - LB2D_proc_y}; assert -disable {<embedded>::eq - LB2D_proc_w}; assert -disable {<embedded>::eq - slice_stream_empty}; assert -disable {<embedded>::eq - slice_stream_full}; assert -disable {<embedded>::eq - LB2D_shift_x}; assert -disable {<embedded>::eq - LB2D_shift_y}; assert -disable {<embedded>::eq - stencil_stream_empty}; assert -disable {<embedded>::eq - stencil_stream_full}; assert -disable {<embedded>::eq - pp_it_1}; assert -disable {<embedded>::eq - pp_it_2}; assert -disable {<embedded>::eq - pp_it_3}; assert -disable {<embedded>::eq - pp_it_4}; assert -disable {<embedded>::eq - pp_it_5}; assert -disable {<embedded>::eq - pp_it_6}; assert -disable {<embedded>::eq - pp_it_7}; assert -disable {<embedded>::eq - pp_it_8}; assert -disable {<embedded>::eq - pp_it_9}; assert -disable {<embedded>::eq - exit_it_1}; assert -disable {<embedded>::eq - exit_it_2}; assert -disable {<embedded>::eq - exit_it_3}; assert -disable {<embedded>::eq - exit_it_4}; assert -disable {<embedded>::eq - exit_it_5}; assert -disable {<embedded>::eq - exit_it_6}; assert -disable {<embedded>::eq - exit_it_7}
#assert -remove <embedded>::terminate; assert -remove {<embedded>::bound help 0}; assert -remove {<embedded>::bound help 1}; assert -remove {<embedded>::bound help 2}; assert -remove {<embedded>::bound help 3}; assert -remove {<embedded>::bound help 4}; assert -remove {<embedded>::bound help 5}; assert -remove {<embedded>::bound help 6}; assert -remove {<embedded>::bound help 7}; assert -remove {<embedded>::bound help 8}; assert -remove {<embedded>::bound help 9}; assert -remove {<embedded>::bound help 10}; assert -remove {<embedded>::bound help 11}; assert -remove {<embedded>::bound help 12}; assert -remove {<embedded>::bound help 13}; assert -remove {<embedded>::bound help 14}; assert -remove {<embedded>::bound help 15}; assert -remove {<embedded>::bound help 16}; assert -remove {<embedded>::bound help 17}; assert -remove {<embedded>::bound help 18}; assert -remove {<embedded>::bound help 19}; assert -remove {<embedded>::bound help 20}; assert -remove {<embedded>::bound help 21}; assert -remove {<embedded>::bound help 22}; assert -remove {<embedded>::bound help 23}; assert -remove {<embedded>::bound help 24}; assert -remove {<embedded>::bound help 25}; assert -remove {<embedded>::bound help 26}; assert -remove {<embedded>::bound help 27}; assert -remove {<embedded>::bound help 28}; assert -remove {<embedded>::bound help 29}; assert -remove {<embedded>::bound help 30}; assert -remove {<embedded>::bound help 31}; assert -remove {<embedded>::bound end}; assert -remove {<embedded>::bound inv}; assert -remove {<embedded>::bound - ila}; assert -remove {<embedded>::bound - hls}; assert -remove {<embedded>::fix point entry - ila}; assert -remove {<embedded>::fix point entry - hls}; assert -remove {<embedded>::fix point - ila}; assert -remove {<embedded>::fix point - hls}; assert -remove {<embedded>::eq - arg_1_TREADY}; assert -remove {<embedded>::eq - arg_0_TVALID}; assert -remove {<embedded>::eq - LB1D_p_cnt}; assert -remove {<embedded>::eq - in_stream_empty}; assert -remove {<embedded>::eq - in_stream_full}; assert -remove {<embedded>::eq - LB2D_proc_x}; assert -remove {<embedded>::eq - LB2D_proc_y}; assert -remove {<embedded>::eq - LB2D_proc_w}; assert -remove {<embedded>::eq - slice_stream_empty}; assert -remove {<embedded>::eq - slice_stream_full}; assert -remove {<embedded>::eq - LB2D_shift_x}; assert -remove {<embedded>::eq - LB2D_shift_y}; assert -remove {<embedded>::eq - stencil_stream_empty}; assert -remove {<embedded>::eq - stencil_stream_full}; assert -remove {<embedded>::eq - pp_it_1}; assert -remove {<embedded>::eq - pp_it_2}; assert -remove {<embedded>::eq - pp_it_3}; assert -remove {<embedded>::eq - pp_it_4}; assert -remove {<embedded>::eq - pp_it_5}; assert -remove {<embedded>::eq - pp_it_6}; assert -remove {<embedded>::eq - pp_it_7}; assert -remove {<embedded>::eq - pp_it_8}; assert -remove {<embedded>::eq - pp_it_9}; assert -remove {<embedded>::eq - exit_it_1}; assert -remove {<embedded>::eq - exit_it_2}; assert -remove {<embedded>::eq - exit_it_3}; assert -remove {<embedded>::eq - exit_it_4}; assert -remove {<embedded>::eq - exit_it_5}; assert -remove {<embedded>::eq - exit_it_6}; assert -remove {<embedded>::eq - exit_it_7}


#assume -enable {::Subset - A}
#prove -all
#save -jdb $EXP/wri_dat_A.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - A}

#assume -enable {::Subset - B}
#prove -all
#save -jdb $EXP/wri_dat_B.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - B}

#assume -enable {::Subset - C1}
#prove -all
#save -jdb $EXP/wri_dat_C1.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C1}

#assume -enable {::Subset - C2}
#prove -all
#save -jdb $EXP/wri_dat_C2.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C2}

#assume -enable {::Subset - D}
#prove -all
#save -jdb $EXP/wri_dat_D.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - D}

#assume -enable {::Subset - E}
#prove -all
#save -jdb $EXP/wri_dat_E.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - E}

#exit

