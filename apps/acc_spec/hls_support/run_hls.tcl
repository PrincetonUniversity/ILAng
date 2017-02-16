set HALIDE_PATH $env(RUN_PATH)/../../..
set INC_FLAGS "-I${HALIDE_PATH}/include -I${HALIDE_PATH}/tools -I$env(RUN_PATH)/../../support -I$env(RUN_PATH)/../hls_support"
set LD_FLAGS "$env(RUN_PATH)/pipeline_native.o -lpthread -ldl -lpng12"

# creating the project and seting up the environtment
open_project hls_prj
set_top hls_target
add_files hls_target.cpp -cflags "-std=c++0x -I../hls_support"
add_files -tb pipeline_hls.cpp -cflags "-std=c++0x $INC_FLAGS"
add_files -tb run.cpp -cflags "-std=c++0x $INC_FLAGS"

# Target FPGA and clock constraints
open_solution "solution1"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
#config_rom_infer -array_size_threshold 1024
config_bind -effort high
config_schedule -effort high

# C simluation
csim_design -O -ldflags ${LD_FLAGS} -argv $env(RUN_ARGS)

# C-to-Verilog synthesis
csynth_design

# Co-simulation (i.e. verifying RTL using C testbench)
#cosim_design -O -ldflags ${LD_FLAGS} -argv $env(RUN_ARGS)

# export the RTL design as a Xilix IP Catalog
#export_design -format ip_catalog
#export_design -evaluate verilog -format ip_catalog

exit
