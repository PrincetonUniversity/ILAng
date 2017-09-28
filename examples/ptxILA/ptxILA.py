import ila
import pickle
PC_BITS = 32
reg_source_file = "test_reg_source.txt"
mem_source_file = "test_mem_source.txt"
program_file = "program_test.ptx"
reg_map = "reg_map"
mem_map = "mem_map"

reg_source_obj = open(reg_source_file, 'r')
mem_source_obj = open(mem_source_file, 'r')
[reg_state_type_name_dict, reg_state_type_length_dict] = pickle.load(reg_source_obj)
[mem_state_type_name_dict, mem_state_type_length_dict, mem_state_size_dict] = pickle.load(mem_source_obj)
reg_state_list = reg_state_type_name_dict.keys()
mem_state_list = mem_state_type_name_dict.keys()

class ptxGPUModel:
	def __int__(self):
		self.model = ila.Abstraction('ptxGPU')
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
		self.scalar_registers



