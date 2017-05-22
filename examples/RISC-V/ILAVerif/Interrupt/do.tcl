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


prove -bg -property {<embedded>::RocketFV.pc_as1 <embedded>::RocketFV.pc_as1:precondition1 <embedded>::RocketFV.pc_a <embedded>::RocketFV.pc_a:precondition1 <embedded>::RocketFV.mem_match <embedded>::RocketFV.mem_match:precondition1 <embedded>::RocketFV.mem_nodirty1 <embedded>::RocketFV.mem_nodirty1:precondition1 <embedded>::RocketFV.mem_nodirty2 <embedded>::RocketFV.mem_nodirty2:precondition1 <embedded>::RocketFV._assume_60:precondition1 <embedded>::RocketFV._assume_61:precondition1 <embedded>::RocketFV._assume_62:precondition1 <embedded>::RocketFV._assume_63:precondition1 <embedded>::RocketFV._assume_64:precondition1 <embedded>::RocketFV._assume_65:precondition1 <embedded>::RocketFV._assume_66:precondition1 <embedded>::RocketFV._assume_67:precondition1 <embedded>::RocketFV._assume_68:precondition1 <embedded>::RocketFV._assume_69:precondition1 <embedded>::RocketFV._assume_70:precondition1 <embedded>::RocketFV._assume_71:precondition1 <embedded>::RocketFV._assume_72:precondition1 <embedded>::RocketFV._assume_73:precondition1 <embedded>::RocketFV._assume_74:precondition1 <embedded>::RocketFV._assume_75:precondition1 <embedded>::RocketFV._assume_76:precondition1 <embedded>::RocketFV.PRIV <embedded>::RocketFV.PRIV:precondition1 <embedded>::RocketFV._assert_78 <embedded>::RocketFV._assert_78:precondition1 <embedded>::RocketFV.mcause <embedded>::RocketFV.mcause:precondition1 <embedded>::RocketFV.mepc <embedded>::RocketFV.mepc:precondition1 <embedded>::RocketFV._assert_81 <embedded>::RocketFV._assert_81:precondition1 <embedded>::RocketFV._assert_82 <embedded>::RocketFV._assert_82:precondition1 <embedded>::RocketFV.mip <embedded>::RocketFV.mip:precondition1 <embedded>::RocketFV._assert_84 <embedded>::RocketFV._assert_84:precondition1 <embedded>::RocketFV._assert_85 <embedded>::RocketFV._assert_85:precondition1 <embedded>::RocketFV.mstatus <embedded>::RocketFV.mstatus:precondition1 <embedded>::RocketFV._assert_87 <embedded>::RocketFV._assert_87:precondition1}

	
	
