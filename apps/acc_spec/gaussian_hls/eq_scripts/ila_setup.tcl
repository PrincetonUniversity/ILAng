set ROOT /home/byhuang/ILA/apps/acc_spec/gaussian_hls

analyze -clear
elaborate -clear

analyze -verilog $ROOT/eqcheck/ila_top.v
elaborate -bbox {1} -bbox_a {4096}

clock -clear; clock clk
reset -expression {:global_formal_reset} {rst};
