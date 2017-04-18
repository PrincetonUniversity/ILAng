set ROOT [pwd]
set SRC $ROOT/verilog
set TCL $ROOT/scripts_impl_d
set EXP $ROOT/exps_impl_d

include $TCL/setup_w.tcl
include $TCL/eqcheck_w.tcl

set_prove_time_limit 0s; set_prove_per_property_time_limit 0s
set_max_trace_length 0; set_prove_per_property_max_time_limit 60m
set_engine_mode {Hp}

assume -disable {::Subset - A}
assume -disable {::Subset - B}
assume -disable {::Subset - C1}
assume -disable {::Subset - C2}
assume -disable {::Subset - D}
assume -disable {::Subset - E}

assert -disable <embedded>::terminate

assume -disable {::arch equal - data}; 
assume -disable {::init - consistent RAM access}

assert -disable {<embedded>::eq - LB1D_in}; assert -disable {<embedded>::eq - LB1D_buff}; assert -disable {<embedded>::eq - in_stream_buff_0}; assert -disable {<embedded>::eq - in_stream_buff_1}; assert -disable {<embedded>::eq - slice_stream_buff_0}; assert -disable {<embedded>::eq - slice_stream_buff_1}; assert -disable {<embedded>::eq - stencil_stream_buff_0}; assert -disable {<embedded>::eq - stencil_stream_buff_1}; assert -disable {<embedded>::eq - LB2D_shift_0}; assert -disable {<embedded>::eq - LB2D_shift_1}; assert -disable {<embedded>::eq - LB2D_shift_2}; assert -disable {<embedded>::eq - LB2D_shift_3}; assert -disable {<embedded>::eq - LB2D_shift_4}; assert -disable {<embedded>::eq - LB2D_shift_5}; assert -disable {<embedded>::eq - LB2D_shift_6}; assert -disable {<embedded>::eq - LB2D_shift_7}; assert -disable {<embedded>::eq - arg_0_TDATA}; assert -disable {<embedded>::eq - LB2D_proc_0}; assert -disable {<embedded>::eq - LB2D_proc_1}; assert -disable {<embedded>::eq - LB2D_proc_2}; assert -disable {<embedded>::eq - LB2D_proc_3}; assert -disable {<embedded>::eq - LB2D_proc_4}; assert -disable {<embedded>::eq - LB2D_proc_5}; assert -disable {<embedded>::eq - LB2D_proc_6}; assert -disable {<embedded>::eq - LB2D_proc_7}

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

set_max_trace_length 30; set_prove_per_property_max_time_limit 60m
set_engine_mode {Hp Ht B N}

assume -enable {::arch equal - data}
assume -enable {::init - consistent RAM access}

#assert -enable {<embedded>::eq - LB1D_in}; assert -enable {<embedded>::eq - LB1D_buff}; assert -enable {<embedded>::eq - in_stream_buff_0}; assert -enable {<embedded>::eq - in_stream_buff_1}; assert -enable {<embedded>::eq - slice_stream_buff_0}; assert -enable {<embedded>::eq - slice_stream_buff_1}; assert -enable {<embedded>::eq - stencil_stream_buff_0}; assert -enable {<embedded>::eq - stencil_stream_buff_1}; assert -enable {<embedded>::eq - LB2D_shift_0}; assert -enable {<embedded>::eq - LB2D_shift_1}; assert -enable {<embedded>::eq - LB2D_shift_2}; assert -enable {<embedded>::eq - LB2D_shift_3}; assert -enable {<embedded>::eq - LB2D_shift_4}; assert -enable {<embedded>::eq - LB2D_shift_5}; assert -enable {<embedded>::eq - LB2D_shift_6}; assert -enable {<embedded>::eq - LB2D_shift_7}; assert -enable {<embedded>::eq - arg_0_TDATA}; assert -enable {<embedded>::eq - LB2D_proc_0}; assert -enable {<embedded>::eq - LB2D_proc_1}; assert -enable {<embedded>::eq - LB2D_proc_2}; assert -enable {<embedded>::eq - LB2D_proc_3}; assert -enable {<embedded>::eq - LB2D_proc_4}; assert -enable {<embedded>::eq - LB2D_proc_5}; assert -enable {<embedded>::eq - LB2D_proc_6}; assert -enable {<embedded>::eq - LB2D_proc_7}
#assert -disable <embedded>::terminate; assert -disable {<embedded>::eq - arg_1_TREADY}; assert -disable {<embedded>::eq - arg_0_TVALID}; assert -disable {<embedded>::eq - LB1D_p_cnt}; assert -disable {<embedded>::eq - in_stream_empty}; assert -disable {<embedded>::eq - in_stream_full}; assert -disable {<embedded>::eq - LB2D_proc_x}; assert -disable {<embedded>::eq - LB2D_proc_y}; assert -disable {<embedded>::eq - LB2D_proc_w}; assert -disable {<embedded>::eq - slice_stream_empty}; assert -disable {<embedded>::eq - slice_stream_full}; assert -disable {<embedded>::eq - LB2D_shift_x}; assert -disable {<embedded>::eq - LB2D_shift_y}; assert -disable {<embedded>::eq - stencil_stream_empty}; assert -disable {<embedded>::eq - stencil_stream_full}; assert -disable {<embedded>::eq - pp_it_1}; assert -disable {<embedded>::eq - pp_it_2}; assert -disable {<embedded>::eq - pp_it_3}; assert -disable {<embedded>::eq - pp_it_4}; assert -disable {<embedded>::eq - pp_it_5}; assert -disable {<embedded>::eq - pp_it_6}; assert -disable {<embedded>::eq - pp_it_7}; assert -disable {<embedded>::eq - pp_it_8}; assert -disable {<embedded>::eq - pp_it_9}; assert -disable {<embedded>::eq - exit_it_1}; assert -disable {<embedded>::eq - exit_it_2}; assert -disable {<embedded>::eq - exit_it_3}; assert -disable {<embedded>::eq - exit_it_4}; assert -disable {<embedded>::eq - exit_it_5}; assert -disable {<embedded>::eq - exit_it_6}; assert -disable {<embedded>::eq - exit_it_7}

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

#

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

