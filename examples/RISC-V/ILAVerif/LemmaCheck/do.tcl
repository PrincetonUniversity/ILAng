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


set_engine_mode {R D I AD N AM AG}
prove -property {<embedded>::RocketFV._assert_56 <embedded>::RocketFV._assert_57 <embedded>::RocketFV._assert_58 <embedded>::RocketFV._assert_59 <embedded>::RocketFV._assert_60 <embedded>::RocketFV._assert_61 <embedded>::RocketFV._assert_62 <embedded>::RocketFV._assert_63 <embedded>::RocketFV._assert_64 <embedded>::RocketFV._assert_65 <embedded>::RocketFV._assert_66 <embedded>::RocketFV._assert_67 <embedded>::RocketFV._assert_68 <embedded>::RocketFV._assert_69 <embedded>::RocketFV._assert_70 <embedded>::RocketFV._assert_71 <embedded>::RocketFV._assert_72 <embedded>::RocketFV._assert_73 <embedded>::RocketFV._assert_74 <embedded>::RocketFV._assert_75 <embedded>::RocketFV._assert_76 <embedded>::RocketFV._assert_77 <embedded>::RocketFV._assert_78 <embedded>::RocketFV._assert_79 <embedded>::RocketFV._assert_80 <embedded>::RocketFV._assert_81 <embedded>::RocketFV._assert_82 <embedded>::RocketFV._assert_83 <embedded>::RocketFV._assert_84 <embedded>::RocketFV._assert_85 <embedded>::RocketFV._assert_86 <embedded>::RocketFV._assert_87 <embedded>::RocketFV._assert_88 <embedded>::RocketFV._assert_89 <embedded>::RocketFV._assert_90 <embedded>::RocketFV._assert_91 <embedded>::RocketFV._assert_92 <embedded>::RocketFV._assert_93 <embedded>::RocketFV._assert_94 <embedded>::RocketFV._assert_95 <embedded>::RocketFV._assert_96 <embedded>::RocketFV._assert_97 <embedded>::RocketFV._assert_98 <embedded>::RocketFV._assert_99 <embedded>::RocketFV._assert_100 <embedded>::RocketFV._assert_101 <embedded>::RocketFV._assert_102 <embedded>::RocketFV._assert_103 <embedded>::RocketFV._assert_104 <embedded>::RocketFV._assert_105 <embedded>::RocketFV._assert_106 <embedded>::RocketFV._assert_107 <embedded>::RocketFV._assert_108 <embedded>::RocketFV._assert_109 <embedded>::RocketFV._assert_110 <embedded>::RocketFV._assert_111 <embedded>::RocketFV._assert_112 <embedded>::RocketFV._assert_113 <embedded>::RocketFV._assert_114 <embedded>::RocketFV._assert_115 <embedded>::RocketFV._assert_116 <embedded>::RocketFV._assert_117 <embedded>::RocketFV._assert_118 <embedded>::RocketFV._assert_119 <embedded>::RocketFV.dut._assert_1 <embedded>::RocketFV.dut._assert_2 <embedded>::RocketFV.dut._assert_3 <embedded>::RocketFV.dut._assert_4 <embedded>::RocketFV.dut._assert_5 <embedded>::RocketFV.dut._assert_6 <embedded>::RocketFV.dut._assert_7 <embedded>::RocketFV.dut._assert_8 <embedded>::RocketFV.dut.no_rvc_lemma <embedded>::RocketFV.dut.csr._assert_1}

save -jdb ./lemma.jdb -capture_setup -capture_session_data


	
	
