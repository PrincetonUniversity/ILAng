
assume -name {:try set internal sigs} -env \
{hls_target_U.hls_target_linebuffer_1_U0.ap_idle == 0} \
-type {temporary} -update_db;

assume -name {:set x index init} -env \
{hls_target_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.col_reg_349 == 0} \
-type {temporary} -update_db;
