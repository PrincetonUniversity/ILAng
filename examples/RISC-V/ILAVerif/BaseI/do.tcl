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


jasper_model_mpram -init sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem
jasper_model_mpram -justify sm.inst_mem

clock clock
reset reset

get_design_info

#set_engine_mode {R D AD N AM G}
#prove -bg -property {<embedded>::RocketFV.x1_ro <embedded>::RocketFV.x1_ld <embedded>::RocketFV.pc_a <embedded>::RocketFV.mem_match <embedded>::RocketFV.x1_nro}



	
	
