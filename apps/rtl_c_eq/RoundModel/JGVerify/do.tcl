set ROOT_PATH ./
set RTL_PATH  ${ROOT_PATH}

analyze -sv \
	${RTL_PATH}/aes.v 
	
analyze -sva \
	${RTL_PATH}/wrapper.v 

elaborate -top wrapper

clock clk
reset rst
