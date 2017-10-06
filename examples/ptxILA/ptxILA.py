import ila
import pickle
PC_BITS = 32
REG_BITS = 32
MEM_ADDRESS_BITS = 32

reg_source_file = "test_reg_source.txt"
mem_source_file = "test_mem_source.txt"
program_file = "program_test.ptx"
reg_map_file = "reg_map"
mem_map_file = "mem_map"
reg_book_file = "reg_book"
mem_book_file = "mem_book"
reg_source_obj = open(reg_source_file, 'r')
mem_source_obj = open(mem_source_file, 'r')
[reg_state_type_name_dict, reg_state_type_length_dict] = pickle.load(reg_source_obj)
[mem_state_type_name_dict, mem_state_type_length_dict, mem_state_size_dict] = pickle.load(mem_source_obj)
reg_state_list = reg_state_type_name_dict.keys()
mem_state_list = mem_state_type_name_dict.keys()

class ptxGPUModel:
	def __int__(self):
		self.model = ila.Abstraction('GPU_ptx')
		self.program_name = 'test.ptx'
		self.createStates()

	def createStates(self):
		self.createPC()
		self.createRegs()
		self.createMems()
		self.instructionFetch()
		self.addInstruction()

	def createPC(self):
		self.pc = self.model.reg('pc', PC_BITS)

	def createRegs(self):
		reg_book_obj = open(reg_book_file)
		reg_book = pickle.load(reg_book_obj)
		for reg_name in reg_book :
			self.scalar_registers.append(self.model.reg(reg_name, REG_BITS))			

	def createMems(self):
		self.mem = self.model.mem('mem', MEM_ADDRESS_BITS, MEM_ADDRESS_BITS)

	def instructionFetch(self):
		self.inst = ila.load(self.mem, ila.zero_extend(self.pc[31:2], MEM_ADDRESS_BITS))
		self.opcode = self.inst[31:22]
		self.dest = self.inst[21:17]
		self.src1 = self.inst[16:12]
		self.src2 = self.inst[11:7]
		self.src3 = self.inst[6:2]
		self.branchPC = self.zero_extend(self.inst[21:0], PC_BITS)

	def pc_nxt(self):
		pcPlus4 = self.pc + self.model.const(0b100, PC_BITS)
		return ila.choice("pc_nxt", [pcPlus4, self.branchPC])

	def sreg_nxt(self, regNo):
		sreg1 = self.scalar_registers[self.src1]
		sreg2 = self.scalar_registers[self.src2]
		sreg3 = self.scalar_registers[self.src3]

		return ila.ite(self.dest == regNo, ila.choice(str(regNo) + "_nxt", [sreg1 + sreg2, sreg1 - sreg2, sreg * sreg2]),self.scalar_registers[regNo])




