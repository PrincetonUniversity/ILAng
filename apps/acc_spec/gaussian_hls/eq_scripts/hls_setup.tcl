set ROOT /home/byhuang/ILA/apps/acc_spec/gaussian_hls

analyze -clear
elaborate -clear

analyze -verilog {/home/byhuang/ILA/apps/acc_spec/gaussian_hls/eqcheck/FIFO_hls_target_call_slice_stream_V_value_V.v} ; analyze -verilog {/home/byhuang/ILA/apps/acc_spec/gaussian_hls/eqcheck/FIFO_hls_target_linebuffer_1_in_stream_V_value_V.v} ; analyze -verilog {/home/byhuang/ILA/apps/acc_spec/gaussian_hls/eqcheck/FIFO_hls_target_p_p2_in_bounded_stencil_stream_s.v} ; analyze -verilog {/home/byhuang/ILA/apps/acc_spec/gaussian_hls/eqcheck/hls_target.v} ; analyze -verilog {/home/byhuang/ILA/apps/acc_spec/gaussian_hls/eqcheck/hls_target_Loop_1_proc.v} ; analyze -verilog {/home/byhuang/ILA/apps/acc_spec/gaussian_hls/eqcheck/hls_target_call.v} ; analyze -verilog {/home/byhuang/ILA/apps/acc_spec/gaussian_hls/eqcheck/hls_target_call_Loop_LB2D_buf_proc.v} ; analyze -verilog {/home/byhuang/ILA/apps/acc_spec/gaussian_hls/eqcheck/hls_target_call_Loop_LB2D_buf_proc_buffer_0_value_V.v} ; analyze -verilog {/home/byhuang/ILA/apps/acc_spec/gaussian_hls/eqcheck/hls_target_call_Loop_LB2D_shift_proc.v} ; analyze -verilog {/home/byhuang/ILA/apps/acc_spec/gaussian_hls/eqcheck/hls_target_linebuffer.v} ; analyze -verilog {/home/byhuang/ILA/apps/acc_spec/gaussian_hls/eqcheck/hls_target_linebuffer_1.v} ; analyze -verilog {/home/byhuang/ILA/apps/acc_spec/gaussian_hls/eqcheck/hls_target_linebuffer_Loop_1_proc.v} ; 

elaborate -bbox {1} -bbox_a {4096} -top {hls_target}

clock -clear; clock ap_clk
reset -expression {:global_formal_reset} {eqcheck_init};
#reset -expression {:global_formal_reset} {!(ap_rst_n)};
