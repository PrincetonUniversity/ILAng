import ila
import Encoding

SCALAR_REG_BITS = 32
SCALAR_REG_BITS_LONG = 64
VECTOR_REG_BITS = 32
PC_REG_BITS = 40
SCALAR_REG_NUM_PER_WORK_GROUP = 103
VECTOR_REG_NUM_PER_WAVE_FRONT = 256
VECTOR_THREAD = 64
SCC_BITS = 1
EXEC_BITS = 32
VCC_BITS = 64
MEMORY_ADDRESS_BITS = 64
VECTOR_SOURCE_BIT = 9
#scalar instruction format:

# -|-|-------|-------|--------|--------|
# 1 0  op(7)   sdst(7) ssrc1(8) ssrc0(8)   sop2
# 1 0 11op(5)  sdst(7)    simm(16)         sopk
# 1 0 1111101  sdst(7) ssrc1(8) ssrc0(8)   sop1
# 1 0 1111110  op  (7) ssrc1(8) ssrc0(8)   sopc
# 1 0 1111111  op  (7)    simm(16)         sopp
VOP1_V_NOP = 0x0
VOP1_V_MOV_B32 = 0x1
VOP1_V_READFIRSTLANE_B32 = 0x2
VOP1_V_CVT_I32_F64 = 0x3
VOP1_V_CVT_F64_I32 = 0x4    
VOP1_V_CVT_F32_I32 = 0x5
VOP1_V_CVT_F32_U32 = 0x6
VOP1_V_CVT_U32_F32 = 0x7
VOP1_V_CVT_I32_F32 = 0x8
VOP1_V_CVT_F16_F32 = 0xA
VOP1_V_CVT_F32_F16 = 0xB
VOP1_V_CVT_RPI_I32_F32 = 0xC
VOP1_V_CVT_FLR_I32_F32 = 0xD
VOP1_V_CVT_OFF_F32_I4 = 0xE
VOP1_V_CVT_F32_F64 = 0xF
VOP1_V_CVT_F64_F32 = 0x10
VOP1_V_CVT_F32_UBYTE0 = 0x11
VOP1_V_CVT_F32_UBYTE1 = 0x12
VOP1_V_CVT_F32_UBYTE2 = 0x13   
VOP1_V_CVT_F32_UBYTE3 = 0x14
VOP1_V_CVT_U32_F64 = 0x15
VOP1_V_CVT_F64_U32 = 0x16
VOP1_V_FRACT_F32 = 0x20
VOP1_V_TRUNC_F32 = 0x21
VOP1_V_CEIL_F32 = 0x22
VOP1_V_RNDNE_F32 = 0x23
VOP1_V_FLOOR_F32 = 0x24
VOP1_V_EXP_F32 = 0x25
VOP1_V_LOG_CLAMP_F32 = 0x26
VOP1_V_LOG_F32 = 0x27
VOP1_V_RCP_CLAMP_F32 = 0x28
VOP1_V_RCP_LEGACY_F32 = 0x29
VOP1_V_RCP_F32 = 0x2A
VOP1_V_RCP_IFLAG_F32 = 0x2B
VOP1_V_RSQ_CLAMP_F32 = 0x2C
VOP1_V_RSQ_LEGACY_F32 = 0x2D
VOP1_V_RSQ_F32 = 0x2E
VOP1_V_RCP_F64 = 0x2F
VOP1_V_RCP_CLAMP_F64 = 0x30
VOP1_V_RSQ_F64 = 0x31
VOP1_V_RSQ_CLAMP_F64 = 0x32
VOP1_V_SQRT_F32 = 0x33
VOP1_V_SQRT_F64 = 0x34
VOP1_V_SIN_F32 = 0x35
VOP1_V_COS_F32 = 0x36
VOP1_V_NOT_B32 = 0x37
VOP1_V_BFREV_B32 = 0x38
VOP1_V_FFBH_U32 = 0x39
VOP1_V_FFBL_B32 = 0x3A
VOP1_V_FFBH_I32 = 0x3B
VOP1_V_FREXP_EXP_I32_F64 = 0x3C
VOP1_V_FREXP_MANT_F64 = 0x3D
VOP1_V_FRACT_F64 = 0x3E
VOP1_V_FREXP_EXP_I32_F32 = 0x3F
VOP1_V_FREXP_MANT_F32 = 0x40
VOP1_V_CLREXCP = 0x41
VOP1_V_MOVRELD_B32 = 0x42
VOP1_V_MOVRELS_B32 = 0x43
VOP1_V_MOVRELSD_B32 = 0x44

class SouthIslandGPUModel:
	def __init__(self, GPU_work_groups_num):
		self.model = ila.Abstraction('south_island_gpu')
		self.createStates(GPU_work_groups_num)
		self.instructionFetch()
        self.cond_true = m.const(0x1, 1)
        self.cond_false = m.const(0x1, 0)

	def createStates(self, GPU_work_groups_num):
		self.createStatesforPC(GPU_work_groups_num)
		self.createStatesforMemory(GPU_work_groups_num)
		self.createStatesforGeneralRegister(GPU_work_groups_num)
		

	def createStatesforPC(self, GPU_work_groups_num):
		#self.pc_list is commented because different pc wont see each other.
		#self.pc_list = []
		self.pc = self.model.reg('pc', PC_REG_BITS)
		# for work_group_index in xrange(GPU_work_groups_num):
		# 	self.pc_list.append(self.model.reg('pc' + \
		# 		str(work_group_index), PC_REG_BITS))
	def createStatesforMemory(self, GPU_work_groups_num): #TODO:
        self.mem = self.model.mem('mem', MEMORY_ADDRESS_BITS, 32)


    def createStatesforGeneralRegister(self,GPU_work_groups_num):
    	self.base_register_address = self.model.reg('base_reg', SCALAR_REG_BITS)
    	self.scalar_registers = []
    	for scalar_register_index in xrange(SCALAR_REG_NUM_PER_WORK_GROUP):
    		self.scalar_registers.append(self.model.reg('s' + '_' + \
    			str(scalar_register_index), SCALAR_REG_BITS))
    	self.SCC = self.model.reg('SCC', SCC_BITS)
    	self.VCC = self.model.reg('VCC', VCC_BITS)
        self.EXEC = self.model.reg('EXEC', EXEC_BITS)
    	self.vector_registers = []
    	for vector_register_index in xrange(VECTOR_REG_NUM_PER_WAVE_FRONT):
    		self.vector_registers.append([])
    		for vector_thread in xrange(VECTOR_THREAD):
	    		self.vector_registers[vector_register_index].append(self.model.reg('v' + '_' + \
    				str(vector_register_index) + '_' + str(vector_thread), VECTOR_REG_BITS))

    	# self.registers_list is commented because different registers wont see each other.
    	# self.registers_list = [];
    	# for work_group_index in xrange(GPU_work_groups_num):
    	# 	self.registers_list.append([]);
    	# 	for scalar_register_index in xrange(SCALAR_REG_NUM_PER_WORK_GROUP):
    	# 		scalar_register = self.model.reg('s' + str(work_group_index) + \
    	# 			'_' + str(scalar_register_index), SCALAR_REG_BITS)
    	# 		self.registers_list[work_group_index].append(scalar_register)
    	# 	for vector_register_index in xrange(VECTOR_REG_NUM_PER_WORK_GROUP):
    	# 		vector_register = self.model.reg('v' + str(work_group_index) + \
    	# 			'_' + str(vector_register_index), VECTOR_REG_BITS)
    	# 		self.registers_list[work_group_index].append(vector_register)

    def instructionFetch(self):
    	self.instruction = self.model.load(self.mem, ila.zero_extend(self.pc, MEMORY_ADDRESS_BITS))			#TODO: How to fetch the instruction in GPU?
    	self.opcode_SOPP = self.instruction[22:16]
    	self.opcode_SOP2 = self.instruction[30:23]
    	self.opcode_VOP2 = self.instruction[30:25]
    	self.opcode_SMRD = self.instruction[26:22]
        self.opcode_SOP1 = self.instruction[15:8]
        self.opcode_SOPK = self.instruction[27:23]
    	self.SOPPIdentifier = self.instruction[31:23]
    	self.SOP2Identifier = self.instruction[31]
    	self.VOP2Identifier = self.instruction[31]
    	self.SMRDIdentifier = self.instruction[31:27]
        self.VOP3Identifier = self.instruction[31:26]
        self.SOPKIdentifier = self.instruction[31:28]
        self.isSOPK = (self.SOPKIdentifier == 0b1011)
    	self.isSOPP = (self.SOPPIdentifier == 0b101111111)
    	self.isSOP2 = (self.SOP2Identifier == 0b1)
    	self.isVOP2 = (self.VOP2Identifier == 0b0)
    	self.isSMRD = (self.SMRDIdentifier == 0b11000)
        self.isVOP3 = (self.VOP3Identifier == 0b110100)
    	self.sdstSOP2 = self.instruction[22:16]
    	self.ssrc1 = self.instruction[15:8]
    	self.ssrc0 = self.instruction[7:0]
    	self.vdst = self.instruction[24:17]
    	self.vsrc1 = self.instruction[16:9]
    	self.vsrc0 = self.instruction[8:0]		#why whitepaper says its offset?
    	self.sdstSMRD = self.instruction[21:15]
    	self.sbase = self.instruction[14:9]
    	self.imm = self.instruction[8]
    	self.simm = self.instruction[15:0]

        self.extend_instruction = self.model.load(self.mem, ila.zero_extend(self.pc + 1, MEMORY_ADDRESS_BITS))


    def indexIntoSGPR(self, index, base_flag = False, SCC_flag = False, EXEC_flag = False):
    	SGPR = self.scalar_registers[0] 	#start from s0
    	for idxIter in xrange(1, SCALAR_REG_NUM_PER_WORK_GROUP):
    		SGPR = ila.ite(index == idxIter, self.scalar_registers[index], SGPR)
    	SGPR = ila.ite(base_flag, self.base_register_address, SGPR)
    	SGPR = ila.ite(SCC_flag, self.SCC, SGPR)
        SGPR = ila.ite(EXEC_flag, self.EXEC, SGPR)
    	return SGPR

    def indexIntoVGPR(self, index, threadNo, VCC_flag = False):
    	VGPR = self.vector_registers[0][0]
    	for idxIter in xrange(1, VECTOR_REG_NUM_PER_WAVE_FRONT):
    		for thrdIter in xrange(1, VECTOR_THREAD):
    			VGPR = ila.ite((index == idxIter) & (threadNo == thrdIter), 
    					self.vector_registers[index][threadNo], VGPR)
    	VGPR = ila.ite(VCC_flag, self.VCC, VGPR)

    	return VGPR


    def nxtStateFunction(self):
######next state function for pc
        m = self.model
        self.pc_nxt_32 = self.pc + m.const(0x1, PC_REG_BITS)
        self.pc_nxt_64 = self.pc + m.const(0x2, PC_REG_BITS)

        self.source_reg0 = m.indexIntoSGPR(self.ssrc0)
        self.source_reg1 = m.indexIntoSGPR(self.ssrc1)
        self.scc = m.indexIntoSGPR(0, False, True)
        self.exec = m.indexIntoSGPR(0, False, False, True)
        self.source_reg0_ext = m.indexIntoSGPR(self.ssrc0 + m.const(0x1))
        self.source_reg1_ext = m.indexIntoSGPR(self.ssrc1 + m.const(0x1))
        self.dst_reg = m.indexIntoSGPR(self.sdstSOP2)
        self.dst_reg_ext = m.indexIntoSGPR(self.sdstSOP2 + m.const(0x1))
        self.source_reg0_long = ila.concat(self.source_reg0_ext, self.source_reg0)
        self.source_reg1_long = ila.concat(self.source_reg1_ext, self.source_reg1)
        self.dst_reg_long = ila.concat(self.dst_reg, self.dst_reg_ext)
        self.source_reg2_bfe = self.source_reg1[20:16]
        self.source_reg1_bfe = self.source_reg1[4:0]
        self.source_reg2_bfe_long = self.source_reg1[22:16]
        self.source_reg1_bfe_long = self.source_reg1[5:0]
        self.nxt_dst_sop2 = ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_ABSDIFF_I32_OPCODE, \
                                ila.ite(self.source_reg0 > self.source_reg1, self.source_reg0 - self.source_reg1, self.source_reg1 - self.source_reg0), \
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_ADD_I32_OPCODE, self.source_reg0 + self.source_reg1,\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_ADD_U32_OPCODE, self.source_reg0 + self.source_reg1,\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_ADDC_U32_OPCODE, self.source_reg0 + self.source_reg1 + self.scc,\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_AND_B32_OPCODE, self.source_reg0 & self.source_reg1,\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_AND_B64_OPCODE, self.source_reg0_long & self.source_reg1_long,\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_ANDN2_B32_OPCODE, self.source_reg0 & (~self.source_reg1),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_ANDN2_B64_OPCODE, self.source_reg0_long & (~self.source_reg1_long),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_ASHR_I32_OPCODE, ila.ashr(self.source_reg0, self.source_reg1[4:0]),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_ASHR_I64_OPCODE, ila.ashr(self.source_reg0_long, self.source_reg1_long[5:0]),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_BFE_I32_OPCODE, ila.ite(self.source_reg2_bfe == 0, m.const(0, SCALAR_REG_BITS), ila.ite((self.source_reg2_bfe + self.source_reg1_bfe) < 32, (self.source_reg0 << (SCALAR_REG_BITS - self.source_reg2_bfe - self.source_reg1_bfe)) >> (32 - self.source_reg2_bfe), source_reg0 >> source_reg1_bfe)),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_BFE_U32_OPCODE, ila.ite(self.source_reg2_bfe == 0, m.const(0, SCALAR_REG_BITS), ila.ite((self.source_reg2_bfe + self.source_reg1_bfe) < 32, (self.source_reg0 << (SCALAR_REG_BITS - self.source_reg2_bfe - self.source_reg1_bfe)) >> (32 - self.source_reg2_bfe), source_reg0 >> source_reg1_bfe)),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_BFE_I64_OPCODE, (self.source_reg0 >> self.source_reg1_bfe_long) & ((1 << self.source_reg2_bfe_long) - 1), \
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_BFE_U64_OPCODE, (self.source_reg0 >> self.source_reg1_bfe_long) & ((1 << self.source_reg2_bfe_long) - 1), \
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_BFM_B32_OPCODE, ((1 << self.source_reg0[4:0]) - 1) << self.source_reg1[4:0],\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_BFM_B64_OPCODE, ((1 << self.source_reg0_long[5:0]) - 1) << self.source_reg1_long[5:0],\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_CBRANCH_G_FORK_OPCODE, ,\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_CSELECT_B32_OPCODE, ila.ite(self.scc, self.source_reg0, self.source_reg1),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_CSELECT_B64_OPCODE, ila.ite(self.scc, self.source_reg0_long, self.source_reg1_long),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_LSHL_B32_OPCODE, self.source_reg0 << self.source_reg1[4:0],\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_LSHL_B64_OPCODE, self.source_reg0_long << self.source_reg1_long[5:0],\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_LSHR_B32_OPCODE, self.source_reg0 >> self.source_reg0[4:0],\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_LSHR_B64_OPCODE, self.source_reg0_long >> self.source_reg1_long[5:0],\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_MAX_I32_OPCODE, ila.ite(self.source_reg0 > self.source_reg1, self.source_reg0, self.source_reg1),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_MAX_U32_OPCODE, ila.ite(self.source_reg0 > self.source_reg1, self.source_reg0, self.source_reg1),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_MIN_I32_OPCODE, ila.ite(self.source_reg0 < self.source_reg1, self.source_reg0, self.source_reg1),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_MIN_U32_OPCODE, ila.ite(self.source_reg0 < self.source_reg1, self.source_reg0, self.source_reg1),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_MUL_I32_OPCODE, self.source_reg0 * self.source_reg1 ,\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_NAND_B32_OPCODE, ~(self.source_reg0 & self.source_reg1),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_NAND_B64_OPCODE, ~(self.source_reg0_long & self.source_reg1_long),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_NOR_B32_OPCODE, ~(self.source_reg0 | self.source_reg1),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_NOR_B64_OPCODE, ~(self.source_reg0_long | self.source_reg1_long),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_OR_B32_OPCODE, self.source_reg0 | self.source_reg1,\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_OR_B64_OPCODE, self.source_reg0_long | self.source_reg1_long,\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_ORN2_B32_OPCODE, self.source_reg0 | (~self.source_reg1),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_ORN2_B64_OPCODE, self.source_reg0_long | (~self.source_reg1_long),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_SUB_I32_OPCODE, self.source_reg0 - self.source_reg1 ,\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_SUB_U32_OPCODE, self.source_reg0 - self.source_reg1,\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_SUBB_U32_OPCODE, self.source_reg0 - self.source_reg1 - self.scc,\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_XNOR_B32_OPCODE, ~(self.source_reg0 ^ self.source_reg1),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_XNOR_B64_OPCODE, ~(self.source_reg0_long ^ self.source_reg1_long),\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_XOR_B32_OPCODE, self.source_reg0 ^ self.source_reg1,\
                            ila.ite(self.opcode_SOP2 == Encoding.SOP2_S_XOR_B64_OPCODE, self.source_reg0_long ^ self.source_reg1_long),\
                            self.dst_reg\
                            )\
                            )\
                            )\
                            )\
                            )\
                            )\
                            )\
                            )\
                            )\
                            )\
                            )\
                            )\
                            )\
                            )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
                                )\
    
        self.nxt_dst_sop1 = ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_ABS_I32_OPCODE, ile.ite(self.source_reg0 > 0, self.source_reg0, -self.source_reg0),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_AND_SAVEEXEC_B64_OPCODE, self.exec,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_ANDN2_SAVEEXEC_B64_OPCODE, self.exec, \
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_BCNT0_I32_B32_OPCODE, aux_count(self.source_reg0, m.const(0x1, 1), m.const(SCALAR_REG_BITS)),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_BCNT0_I32_B64_OPCODE, aux_count(self.source_reg0, m.const(0x1, 1), m.const(SCALAR_REG_BITS_LONG)),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_BCNT1_I32_B32_OPCODE, aux_count(self.source_reg0, m.const(0x1, 0), m.const(SCALAR_REG_BITS)),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_BCNT1_I32_B64_OPCODE, aux_count(self.source_reg0, m.const(0x1, 0), m.const(SCALAR_REG_BITS_LONG)),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_BITSET0_B32_OPCODE, aux_bit_set_zero(self.dst_reg, self.source_reg0[4:0]),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_BITSET0_B64_OPCODE, aux_bit_set_zero(self.dst_reg_long, self.source_reg0_long[5:0]),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_BITSET1_B32_OPCODE, aux_bit_set_one(self.dst_reg, self.source_reg0[4:0]),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_BITSET1_B64_OPCODE, aux_bit_set_one(self.dst_reg_long, self.source_reg0_long[5:0]),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_BREV_B32_OPCODE, aux_bit_rev(self.source_reg0, SCALAR_REG_BITS),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_BREV_B64_OPCODE, aux_bit_rev(self.source_reg0_long, SCALAR_REG_BITS_LONG),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_CBRANCH_JOIN_OPCODE, #TODO
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_CMOV_B32_OPCODE, ila.ite(self.scc, self.source_reg0, ~(self.source_reg0 | self.dst_reg)),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_CMOV_B64_OPCODE, ila.ite(self.scc, self.source_reg0_long, ~(self.source_reg0_long | self.dst_reg_long)),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_FF0_I32_B32_OPCODE, aux_ff_bit(self.source_reg0, SCALAR_REG_BITS, m.const(0x0, 1)),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_FF1_I32_B32_OPCODE, aux_ff_bit(self.source_reg0, SCALAR_REG_BITS, m.const(0x1, 1)),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_FF0_I32_B64_OPCODE, aux_ff_bit(self.source_reg0_long, SCALAR_REG_BITS_LONG, m.const(0x0, 1)),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_FF1_I32_B64_OPCODE, aux_ff_bit(self.source_reg0_long, SCALAR_REG_BITS_LONG, m.const(0x1, 1)),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_FLBIT_I32_OPCODE, aux_ff_op_bit(self.source_reg0, SCALAR_REG_BITS),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_FLBIT_I32_I64_OPCODE, aux_ff_op_bit(self.source_reg0_long, SCALAR_REG_BITS_LONG),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_FLBIT_I32_B32_OPCODE, aux_ff_bit_m(self.source_reg0, SCALAR_REG_BITS, m.const(0x1, 1)),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_FLBIT_I32_B64_OPCODE, aux_ff_bit_m(self.source_reg0_long, SCALAR_REG_BITS_LONG, m.const(0x1, 1)),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_GETPC_B64_OPCODE, self.pc + m.const(0x4, SCALAR_REG_BITS_LONG) ,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_MOV_B32_OPCODE, self.source_reg0,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_MOV_B64_OPCODE, self.source_reg0_long,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_MOVRELD_B32_OPCODE, #TODO ,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_MOVRELD_B64_OPCODE, #TODO ,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_MOVRELS_B32_OPCODE, #TODO ,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_MOVRELS_B64_OPCODE, #TODO ,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_NAND_SAVEEXEC_B64_OPCODE, self.exec, \
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_NOR_SAVEEXEC_B64_OPCODE, self.exec,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_NOT_B32_OPCODE, ~(self.source_reg0),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_NOT_B64_OPCODE, ~(self.source_reg0_long),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_OR_SAVEEXEC_B64_OPCODE, self.exec,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_ORN2_SAVEEXEC_B64_OPCODE, self.exec ,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_QUADMASK_B32_OPCODE, ila.zero_extend(aux_quadmask(self.source_reg0, SCALAR_REG_BITS)) ,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_QUADMASK_B64_OPCODE, ila.zero_extend(aux_quadmask(self.source_reg0_long)),\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_RFE_B64_OPCODE, ila.source_reg0_long,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_WQM_B32_OPCODE, ila.zero_extend(aux_quadmask(self.source_reg0, SCALAR_REG_BITS)) ,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_WQM_B64_OPCODE, ila.zero_extend(aux_quadmask(self.source_reg0, SCALAR_REG_BITS)) ,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_SEXT_I32_I8_OPCODE, ila.sign_extend(self.source_reg0[7:0]) ,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_SEXT_I32_I16_OPCODE, ila.sign_extend(self.source_reg0[15:0]) ,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_SWAPPC_B64_OPCODE, self.pc + m.const(0x4, SCALAR_REG_BITS_LONG) ,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_MOV_FED_B32_OPCODE, self.source_reg0,\
                            ila.ite(self,opcode_SOP1 == Encoding.SOP1_S_XOR_SAVEEXEC_B64_OPCODE, self.exec,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_XNOR_SAVEEXEC_B64_OPCODE, self.exec,\
                            ila.ite(self.opcode_SOP1 == Encoding.SOP1_S_SETPC_B64_OPCODE, self.dst_reg,\
                            self.dst_reg
                            )
                            )
                            )
                            )
                            )
                            )
                            )
                            )
                            )
                            )
                            )
                                )
                            )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )                                
                                )
                                )
                                )
                                )    
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )

        self.nxt_dst_sopk = ila.ite( self.opcode_SOPK == Encoding.SOPK_S_MOVK_I32_OPCODE, ila.sign_extend(self.simm, SCALAR_REG_BITS),\
                            ila.ite( self.opcode_SOPK == Encoding.SOPK_S_CMOVK_I32_OPCODE, ila.ite(self.scc != m.const(0x1, 1), ila.sign_extend(self.simm, SCALAR_REG_BITS, self.dst_reg)),\
                            ila.ite( self.opcode_SOPK == Encoding.SOPK_S_ADDK_I32_OPCODE, self.dst_reg + sign_extend(self.simm, SCALAR_REG_BITS),\
                            ila.ite( self.opcode_SOPK == Encoding.SOPK_S_MULK_I32_OPCODE, self.dst_reg * sign_extend(self.simm, SCALAR_REG_BITS),\
                            )
                            )
                            )
                            )

    def nextStateVALUFunction(self, threadNo):
        m = self.model
        self.vsource_reg0 = ila.ite(self.vsrc0 > 255, m.indexIntoVGPR(self.vsrc0 - m.const(0x100, VECTOR_SOURCE_BIT), threadNo), m.indexIntoSGPR(self.vsrc0))
        self.vsource_reg1 = m.indexIntoVGPR(self.vsrc1)
        self.vcc = m.indexIntoVGPR(0, 0, True)
        self.vsource_reg0_ext = ila.ite(self.vsrc0 > 255, m.indexIntoVGPR(self.vsrc0 + m.const(0x1, VECTOR_SOURCE_BIT) - m.const(0x100, VECTOR_SOURCE_BIT), threadNo), m.indexIntoSGPR(self.vsrc0 + m.const(0x1,1)))
        self.vsource_reg1_ext = m.indexIntoVGPR(self.vsrc1 + m.const(0x1, VECTOR_SOURCE_BIT - 1))
        self.vdst_reg = m.indexIntoVGPR(self.vdst)
        self.vdst_reg_ext = m.indexIntoVGPR(self.vdst + m.const(0x1, VECTOR_SOURCE_BIT - 1))
        self.vsource_reg0_long = ila.concat(self.vsource_reg0_ext, self.vsource_reg0)
        self.vsource_reg1_long = ila.concat(self.vsource_reg1_ext, self.vsource_reg1)
        self.vdst_reg_long = ila.concat(self.vdst_reg, self.vdst_reg_ext)

        self.nxt_dst_vop2 = ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_CNDMASK_B32, ila.ite(self.vcc[threadNo] != 0, self.vsource_reg1, slef.vsource_reg0),\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_READLANE_B32, ,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_WRITELANE_B32, , \
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_ADD_F32, self.vsource_reg0 + self.vsource_reg1,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_SUB_F32, self.vsource_reg0 - self.vsource_reg1,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_SUBREV_F32, self.vsource_reg1 - self.vsource_reg0 ,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MAC_LEGACY_F32, self.vsource_reg0 * self.vsource_reg1 + self.vdst_reg,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MUL_LEGACY_F32, self.vsource_reg0 * self.vsource_reg1,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MUL_F32, self.vsource_reg0 * self.vsource_reg1.\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MUL_I32_I24, ila.sign_extend((self.vsource_reg0[23:0] * self.vsource_reg1[23:0])[30:0], VECTOR_REG_BITS),\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MUL_HI_I32_I24, ila.sign_extend((self.vsource_reg0[23:0] * self.vsource_reg1[23:0])[47:32], VECTOR_REG_BITS),\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MUL_U32_U24, (self.vsource_reg0[23:0] * self.vsource_reg1[23:0])[31:0],\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MUL_HI_U32_U24, ila.zero_extend((self.vsource_reg0[23:0] * self.vsource_reg1[23:0])[47:32], VECTOR_REG_BITS),\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MIN_LEGACY_F32, ila.ite(self.vsource_reg0 < self.vsource_reg1, self.vsource_reg0, self.vsource_reg1),\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MAX_LEGACY_F32, ila.ite(self.vsource_reg0 >= self.vsource_reg1, self.vsource_reg0, self.vsource_reg1),\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MIN_F32, ila.ite(self.vsource_reg0 < self.vsource_reg1, self.vsource_reg0, self.vsource_reg1),\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MAX_F32, ila.ite(self.vsource_reg0 > self.vsource_reg1, self.vsource_reg0, self.vsource_reg1),\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MIN_I32, ila.ite(self.vsource_reg0 < self.vsource_reg1, self.vsource_reg0, self.vsource_reg1),\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MAX_I32, ila.ite(self.vsource_reg0 > self.vsource_reg1, self.vsource_reg0, self.vsource_reg1),\ 
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MIN_U32, ila.ite(self.vsource_reg0 < self.vsource_reg1, self.vsource_reg0, self.vsource_reg1),\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MAX_U32, ila.ite(self.vsource_reg0 > self.vsource_reg1, self.vsource_reg0, self.vsource_reg1),\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_LSHR_B32, self.vsource_reg0 >> self.vsource_reg1[4:0],\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_LSHRREV_B32, self.vsource_reg1 >> self.vsource_reg0[4:0],\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_ASHR_I32, ila.ashr(self.vsource_reg0, self.vsource_reg1[4:0]),\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_ASHRREV_I32, ila.ashr(self.vsource_reg1, self.vsource_reg0[4:0]),\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_LSHL_B32, self.vsource_reg0 << self.vsource_reg1[4:0],\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_LSHLREV_B32, self.vsource_reg1 << self.vsource_reg0[4:0],\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_AND_B32, self.vsource_reg0 & self.vsource_reg1,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_OR_B32, self.vsource_reg0 | self.vsource_reg1,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_XOR_B32, self.vsource_reg0 ^ self.vsource_reg1,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_BFM_B32, ((1 << self.vsource_reg0[4:0]) - 1) << self.vsource_reg1[4:0],\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MAC_F32, self.vsource_reg0 * self.vsource_reg1 + self.vdst_reg,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MADMK_F32, ,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MADAK_F32, ,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_BCNT_U32_B32, aux_count(self.vsource_reg0, False ,VECTOR_REG_BITS) + self.vsource_reg1,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MBCNT_LO_U32_B32, ,\ #TODO: ThreadMask
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_MBCNT_HI_U32_B32, ,\ 
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_ADD_I32, self.vsource_reg0 + self.vsource_reg1 ,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_SUB_I32, self.vsource_reg0 - self.vsource_reg1, \
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_SUBREV_I32, self.vsource_reg1 - self.vsource_reg1,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_ADDC_U32, self.vsource_reg0 + self.vsource_reg1 + self.vcc[threadNo],\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_SUBB_U32, self.vsource_reg0 - self.vsource_reg1 - self.vcc[threadNo],\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_SUBBREV_U32, self.vsource_reg1 - self.vsource_reg0 - self.VCC[threadNo],\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_LDEXP_F32, ,\#TODO:EXP
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_CVT_PKACCUM_U8_F32, ,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_CVT_PKNORM_I16_F32, ,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_CVT_PKNORM_U16_F32, ,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_CVT_PKRTZ_F16_F32, ,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_CVT_PK_U16_U32, ,\
                            ila.ite( self.opcode_VOP2 == Encoding.VOP2_V_CVT_PK_I16_I32, ,\
                            )
                            )
                            )
                            )
                            )
                            )
                            )
                            )
                            )

                            )
                            )
                            )
                            )
                            )
                            )
                            )
                            )
                            )
                            )
                            )
                            )
                                )
                                )

                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )   
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                                )
                            )
                            )
                            )
                            )

      

    def aux_count(self, data, zero_flag, bits):
        count = m.const(0x0, bits)
        for i in range(bits):
            count = count + ila.ite(data[0] == 0, m.const(0x1, bits), m.const(0x0. bits))
            data = data>>1
        return ila.ite(zero_flag, count, m.const(bits, bits) - count)


    def aux_bit_set_zero(self, dst_reg, src_reg):   #dst_reg[src_reg] = 0/1
    	dst_reg[src_reg] = m.const(0x0, 1)
        return dst_reg
    def aux_bit_set_one(self, dst_reg, src_reg):
        dst_reg[src_reg] = m.const(0x1, 1)
        return dst_reg

    def aux_bit_rev(self, src_reg, bits):
        result = src_reg[bits - 1]
        for i in range(bits - 1)[::-1]:
            result = ila.concat(result, src_reg[i])
        return result

    def aux_ff_bit(self, src_reg, bits, find_bit):
        result = ila.sign_extend(m.const(0x11, 2), SCALAR_REG_BITS)
        for i in range(bits):
            result = ila.ite(result < 0, ila.ite(src_reg[i] == find_bit, m.const(i, SCALAR_REG_BITS), result), result)
        return result

    def aux_ff_op_bit(self, src_reg, bits):
        result = ila.sign_extend(m.const(0x11, 2), SCALAR_REG_BITS)
        for i in range(bits - 1)[::-1]:
            result = ila.ite(result < 0, ila.ite(src_reg[bits - 1] != src_reg[i], m.const(i, SCALAR_REG_BITS_LONG), result), result)
        return result

    def aux_ff_bit_m(self, src_reg, bits, find_bit):
        result = ila.sign_extend(m.const(0x11, 2), SCALAR_REG_BITS)
        for i in range(bits)[::-1]:
            result = ila.ite(result < 0, ila.ite(src_reg[i] == find_bit, m.const(i, SCALAR_REG_BITS), result), result)
        return result

    def aux_quadmask(self, src_reg, bits):
        result = (src_reg[0] | src_reg[1] | src_reg[2] | src_reg[3])
        for i in range(bits / 4 - 1):
            result = ila.concat((src_reg[i * 4 + 4] | src_reg[i * 4 + 5] | src_reg[i * 4 + 6] | src_reg[i * 4 + 7]),result)
        return result


