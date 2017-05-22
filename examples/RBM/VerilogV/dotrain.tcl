set ROOT_PATH ./
set RTL_PATH  ${ROOT_PATH}/vprj

analyze -sv \
	${RTL_PATH}/rbm_0_cmos32soi_rtl.v \
	${RTL_PATH}/mem_rbm_0_cmos32soi_rtl.v \
	${RTL_PATH}/Train.v \
	${RTL_PATH}/Vtop_train.v 

elaborate -top Vtop

clock clk
reset rst



