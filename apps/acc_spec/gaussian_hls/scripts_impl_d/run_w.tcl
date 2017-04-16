set ROOT [pwd]
set SRC $ROOT/verilog
set TCL $ROOT/scripts_impl_d
set EXP $ROOT/exps_impl_d

include $TCL/setup_w.tcl
include $TCL/eqcheck_w.tcl

set_prove_time_limit 0s; set_prove_per_property_time_limit 0s
set_max_trace_length 25; set_prove_per_property_max_time_limit 15m


#assume -disable {::Subset - A}
#assume -disable {::Subset - B}
#assume -disable {::Subset - C1}
#assume -disable {::Subset - C2}
#assume -disable {::Subset - D}
#assume -disable {::Subset - E}

assert -disable {<embedded>::eq - pp_it_2}; assert -disable {<embedded>::eq - pp_it_3}; assert -disable {<embedded>::eq - pp_it_4}; assert -disable {<embedded>::eq - pp_it_5}; assert -disable {<embedded>::eq - pp_it_6}; assert -disable {<embedded>::eq - pp_it_7}; assert -disable {<embedded>::eq - pp_it_8}

assert -disable {<embedded>::eq - exit_it_2}; assert -disable {<embedded>::eq - exit_it_3}; assert -disable {<embedded>::eq - exit_it_4}; assert -disable {<embedded>::eq - exit_it_5}; assert -disable {<embedded>::eq - exit_it_6}; assert -disable {<embedded>::eq - exit_it_7}; assert -disable {<embedded>::eq - LB1D_in}; assert -disable {<embedded>::eq - LB1D_buff}; assert -disable {<embedded>::eq - in_stream_buff_0}; assert -disable {<embedded>::eq - in_stream_buff_1}; assert -disable {<embedded>::eq - slice_stream_buff_0}; assert -disable {<embedded>::eq - slice_stream_buff_1}; assert -disable {<embedded>::eq - stencil_stream_buff_0}; assert -disable {<embedded>::eq - stencil_stream_buff_1}; assert -disable {<embedded>::eq - LB2D_shift_0}; assert -disable {<embedded>::eq - LB2D_shift_1}; assert -disable {<embedded>::eq - LB2D_shift_2}; assert -disable {<embedded>::eq - LB2D_shift_3}; assert -disable {<embedded>::eq - LB2D_shift_4}; assert -disable {<embedded>::eq - LB2D_shift_5}; assert -disable {<embedded>::eq - LB2D_shift_6}; assert -disable {<embedded>::eq - LB2D_shift_7}; assert -disable {<embedded>::eq - arg_0_TDATA}; assert -disable {<embedded>::eq - LB2D_proc_0}; assert -disable {<embedded>::eq - LB2D_proc_1}; assert -disable {<embedded>::eq - LB2D_proc_2}; assert -disable {<embedded>::eq - LB2D_proc_3}; assert -disable {<embedded>::eq - LB2D_proc_4}; assert -disable {<embedded>::eq - LB2D_proc_5}; assert -disable {<embedded>::eq - LB2D_proc_6}; assert -disable {<embedded>::eq - LB2D_proc_7}

assume -disable {::arch equal - data}; assume -disable {::Subset - A}; assume -disable {::Subset - B}; assume -disable {::Subset - C1}; assume -disable {::Subset - C2}; assume -disable {::Subset - D}; assume -disable {::Subset - E}


assume -disable {::init - valid iterator}; assume -disable {::init - complete input}; assume -disable {::init - consistent input proc}; assume -disable {::init - complete output}; assume -disable {::init - consistent proc_w}; assume -disable {::init - consistent exitcond in}; assume -disable {::init - consistent exitcond buff}; assume -disable {::init - consistent exitcond shift}; assume -disable {::init - consistent exitcond GB}; assume -disable {::init - consistent input ready}; assume -disable {::init - consistent valid record}; assume -disable {::init - consistent pixel position}; assume -disable {::init - consistent RAM select}; assume -disable {::init - consistent RAM RW}; assume -disable {::init - consistent RAM access}; assume -disable {::init - processing iterator}; assume -disable {::init - no holding iterator}; assume -disable {::init - no holding iterator - buff}; assume -disable {::init - no holding iterator - shift}; assume -disable {::init - cnt vs pp - ila}; assume -disable {::init - cnt vs exit - ila}; assume -disable {::inv - buff vs shift - ila}; assume -disable {::inv - buff vs shift - hls}; assume -disable {::inv - shift vs gb}

#assume -enable {::Subset - A}
#prove -all
#save -jdb $EXP/wri_A.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - A}

#assume -enable {::Subset - C3}
#prove -all
#save -jdb $EXP/wri_C3.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C3}

#assume -enable {::Subset - C4}
#prove -all
#save -jdb $EXP/wri_C4.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C4}

#assume -enable {::Subset - E}
#prove -all
#save -jdb $EXP/wri_E.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - E}

#

#assume -enable {::Subset - C1}
#prove -all
#save -jdb $EXP/wri_C1.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C1}

#assume -enable {::Subset - C2}
#prove -all
#save -jdb $EXP/wri_C2.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C2}

#

#assume -enable {::Subset - B}
#prove -all
#save -jdb $EXP/wri_B.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - B}

#assume -enable {::Subset - D}
#prove -all
#save -jdb $EXP/wri_D.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - D}

#exit

