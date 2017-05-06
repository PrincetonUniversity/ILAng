set ROOT_PATH ./
set RTL_PATH  ${ROOT_PATH}

analyze -sv \
	${RTL_PATH}/aes_128.v \
	${RTL_PATH}/expand_key_128.v \
	${RTL_PATH}/one_round.v \
	${RTL_PATH}/S.v \
	${RTL_PATH}/T.v \
	${RTL_PATH}/xS.v \
	${RTL_PATH}/aesV.v \
	${RTL_PATH}/final_round.v \
	${RTL_PATH}/S4.v \
	${RTL_PATH}/table_lookup.v 

analyze -sva \
	${RTL_PATH}/vtop.v 

elaborate -top vtop

clock clk
reset rst
