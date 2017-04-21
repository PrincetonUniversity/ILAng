set ROOT [pwd]
set SRC $ROOT/verilog
set TCL $ROOT/scripts_a_b
set EXP $ROOT/exps_a_b

include $TCL/setup_w.tcl
include $TCL/eqcheck_w.tcl

set_engine_mode {Hp Ht B N}
set_prove_time_limit 0s; set_prove_per_property_time_limit 0s
set_max_trace_length 0; set_prove_per_property_max_time_limit 60m

assume -disable {::Subset - A}; 
assume -disable {::Subset - B}; 
assume -disable {::Subset - C1}; 
assume -disable {::Subset - C2}; 
assume -disable {::Subset - C3}; 
assume -disable {::Subset - C4}; 
assume -disable {::Subset - D}; 
assume -disable {::Subset - E}

#assert -remove {<embedded>::eq - arg_1_TREADY}; assert -remove {<embedded>::eq - arg_0_TVALID}; assert -remove {<embedded>::eq - RAM_x}; assert -remove {<embedded>::eq - RAM_y}; assert -remove {<embedded>::eq - RAM_w}; assert -remove {<embedded>::eq - cur_pix}; assert -remove {<embedded>::eq - stencil_0}; assert -remove {<embedded>::eq - stencil_1}; assert -remove {<embedded>::eq - stencil_2}; assert -remove {<embedded>::eq - stencil_3}; assert -remove {<embedded>::eq - stencil_4}; assert -remove {<embedded>::eq - stencil_5}; assert -remove {<embedded>::eq - stencil_6}; assert -remove {<embedded>::eq - stencil_7}; assert -remove {<embedded>::eq - RAM_0}; assert -remove {<embedded>::eq - RAM_1}; assert -remove {<embedded>::eq - RAM_2}; assert -remove {<embedded>::eq - RAM_3}; assert -remove {<embedded>::eq - RAM_4}; assert -remove {<embedded>::eq - RAM_5}; assert -remove {<embedded>::eq - RAM_6}; assert -remove {<embedded>::eq - RAM_7}

#assume -enable {::Subset - C1}
#prove -property {<embedded>::bound}
#prove -property {{<embedded>::eq - arg_0_TDATA}}
#save -jdb $EXP/wri_data_C1.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C1}

#assume -enable {::Subset - C2}
#prove -property {<embedded>::bound}
#prove -property {{<embedded>::eq - arg_0_TDATA}}
#save -jdb $EXP/wri_data_C2.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C2}

#assume -enable {::Subset - C3}
#prove -property {<embedded>::bound}
#prove -property {{<embedded>::eq - arg_0_TDATA}}
#save -jdb $EXP/wri_data_C3.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C3}

#assume -enable {::Subset - C4}
#prove -property {<embedded>::bound}
#prove -property {{<embedded>::eq - arg_0_TDATA}}
#save -jdb $EXP/wri_data_C4.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - C4}

#assume -enable {::Subset - D}
#prove -property {<embedded>::bound}
#prove -property {{<embedded>::eq - arg_0_TDATA}}
#save -jdb $EXP/wri_data_D.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - D}

#assume -enable {::Subset - E}
#prove -property {<embedded>::bound}
#prove -property {{<embedded>::eq - arg_0_TDATA}}
#save -jdb $EXP/wri_data_E.jdb -capture_setup -capture_session_data
#assume -disable {::Subset - E}

###

#restore -jdb $EXP/wri_C1.jdb
#set_engine_mode {Hp Ht B N}
#set_prove_time_limit 0s; set_prove_per_property_time_limit 0s
#set_max_trace_length 0; set_prove_per_property_max_time_limit 60m
#prove -all
#save -jdb $EXP/wri_C1.jdb -capture_setup -capture_session_data

#restore -jdb $EXP/wri_C2.jdb
#set_engine_mode {Hp Ht B N}
#set_prove_time_limit 0s; set_prove_per_property_time_limit 0s
#set_max_trace_length 0; set_prove_per_property_max_time_limit 60m
#prove -all
#save -jdb $EXP/wri_C2.jdb -capture_setup -capture_session_data

#restore -jdb $EXP/wri_C3.jdb
#set_engine_mode {Hp Ht B N}
#set_prove_time_limit 0s; set_prove_per_property_time_limit 0s
#set_max_trace_length 0; set_prove_per_property_max_time_limit 60m
#prove -all
#save -jdb $EXP/wri_C3.jdb -capture_setup -capture_session_data

#restore -jdb $EXP/wri_C4.jdb
#set_engine_mode {Hp Ht B N}
#set_prove_time_limit 0s; set_prove_per_property_time_limit 0s
#set_max_trace_length 0; set_prove_per_property_max_time_limit 60m
#prove -all
#save -jdb $EXP/wri_C4.jdb -capture_setup -capture_session_data

#restore -jdb $EXP/wri_D.jdb
#set_engine_mode {Hp Ht B N}
#set_prove_time_limit 0s; set_prove_per_property_time_limit 0s
#set_max_trace_length 0; set_prove_per_property_max_time_limit 60m
#prove -all
#save -jdb $EXP/wri_D.jdb -capture_setup -capture_session_data

#restore -jdb $EXP/wri_E.jdb
#set_engine_mode {Hp Ht B N}
#set_prove_time_limit 0s; set_prove_per_property_time_limit 0s
#set_max_trace_length 0; set_prove_per_property_max_time_limit 60m
#prove -all
#save -jdb $EXP/wri_E.jdb -capture_setup -capture_session_data

#exit
