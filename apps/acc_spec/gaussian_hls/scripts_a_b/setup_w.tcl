analyze -clear
elaborate -clear

analyze -verilog $SRC/eq_a_b_wri.v
analyze -verilog $SRC/spec_a_wri.v
analyze -verilog $SRC/spec_b_wri.v

elaborate -bbox {1} -bbox_a {4096}

clock -clear; clock clk

reset -expression {:global_formal_reset} {rst_init};

