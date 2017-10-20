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

class ptxGPUModel(object):
    def __init__(self):
        self.model = ila.Abstraction('GPU_ptx')
        self.program_name = 'test.ptx'
        self.scalar_registers = []
        self.createStates()

    def createStates(self):
        self.createPC()
        self.createRegs()
        self.createMems()
        self.instructionFetch()
        self.instructionDecode()
        #self.addInstruction()

    def createPC(self):
        self.pc = self.model.reg('pc', PC_BITS)

    def createRegs(self):
        reg_book_obj = open(reg_book_file)
        reg_book = pickle.load(reg_book_obj)
        for reg_name in reg_book :
            print reg_name
            self.scalar_registers.append(self.model.reg(reg_name, REG_BITS))			

    def createMems(self):
        self.mem = self.model.mem('mem', MEM_ADDRESS_BITS, MEM_ADDRESS_BITS)

    def instructionFetch(self):
        self.inst = ila.load(self.mem, ila.zero_extend(self.pc[31:2], MEM_ADDRESS_BITS))
        self.opcode = self.inst[31:22]
        self.fetch_expr = self.inst
        self.dest = self.inst[21:17]
        self.src1 = self.inst[16:12]
        self.src2 = self.inst[11:7]
        self.src3 = self.inst[6:2]
        self.branchPC = ila.zero_extend(self.inst[21:0], PC_BITS)
        self.sreg1 = self.indexIntoReg(self.src1)
        self.sreg2 = self.indexIntoReg(self.src2)
        self.sreg3 = self.indexIntoReg(self.src3)
        self.sregdest = self.indexIntoReg(self.dest)
    
    def instructionDecode(self):
        instruction_map_file = 'instruction_map'
        instruction_map_obj = open(instruction_map_file, 'r')
        instruction_map = pickle.load(instruction_map_obj)
        ALUInstructions = [(self.opcode == instruction_map['add']), (self.opcode == instruction_map['sub']),(self.opcode == instruction_map['mul'])]
        decodeList = ALUInstructions
        self.model.decode_exprs = decodeList


    def pc_nxt(self):
        pcPlus4 = self.pc + self.model.const(0b100, PC_BITS)
        return ila.choice("pc_nxt", [pcPlus4, self.branchPC])

    def sreg_nxt(self, regNo):
        return ila.ite(self.dest == regNo, ila.choice(str(regNo) + "_nxt", [self.sreg1 + self.sreg2, self.sreg1 - self.sreg2, self.sreg1 * self.sreg2, self.sregdest]),self.scalar_registers[regNo])
#        return ila.choice(str(regNo) + "_nxt", [self.sreg1 + self.sreg2, self.sreg1 - self.sreg2, self.sreg1 * self.sreg2, self.sregdest ,self.scalar_registers[regNo]])



    def mem_nxt(self):
        return self.mem

    def indexIntoReg(self, idx):
        expr = self.scalar_registers[0]
        for i in range(len(self.scalar_registers)):
            expr = ila.ite(idx == i, self.scalar_registers[i], expr)
        return expr
    '''
    def compare(self):
        next_1 = self.model.get_next('%r4')
        next_2 = self.ptxSample()
        if not self.model.areEqual(next_1, next_2):
            print 'not equal'
        else:
            print 'equal'
    def ptxSample(self):
        return ila.ite(self.dest == 0, ila.ite(self.opcode == 26, self.sreg1 + self.sreg2, ila.ite(self.opcode == 28, self.sreg1 - self.sreg2, self.sregdest)), self.scalar_registers[0])
    '''
