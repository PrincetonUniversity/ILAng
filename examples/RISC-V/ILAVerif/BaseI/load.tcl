set ROOT_PATH ./
set RTL_PATH  ${ROOT_PATH}

analyze -sv \
	${RTL_PATH}/ALU.v \
	${RTL_PATH}/BreakpointUnit.v \
	${RTL_PATH}/CSRFile.v \
	${RTL_PATH}/RVCExpander.v \
	${RTL_PATH}/IBuf.v \
	${RTL_PATH}/MulDiv.v \
	${RTL_PATH}/RISC-V-VLG.v \
	${RTL_PATH}/Rocket.v \
	${RTL_PATH}/ShareMem.v 

analyze -sva \
	${RTL_PATH}/RocketFV.v 

elaborate -top RocketFV -bbox_a 65536


clock clock
reset reset

get_design_info




	
	
