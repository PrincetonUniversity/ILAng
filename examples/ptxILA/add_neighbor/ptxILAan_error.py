import ila
import pickle
import Instruction_Format
import re
ila.setloglevel(3, '')
ila.enablelog('BMCResult')
ssa_declaration_obj = open('ssa_declaration_file.ptx', 'r')
ssa_declaration = pickle.load(ssa_declaration_obj)
program_obj = open('ssa_add_neighbor.ptx', 'r')
program = pickle.load(program_obj)
instruction_format = Instruction_Format.InstructionFormat()
PC_BITS = 32
REG_BITS = 32
MEM_ADDRESS_BITS = 32
OPCODE_BIT = 22
DST_BIT = 17
SRC0_BIT = 12
SRC1_BIT = 7
SRC2_BIT = 2
BASE_BIT = 2

class barSpec(object):
    def __init__(self):
        self.BAR_INIT = 0
        self.BAR_ENTER = 1
        self.BAR_WAIT = 2
        self.BAR_EXIT = 3
        self.BAR_FINISH = 4
        self.BAR_COUNTER_ENTER_BITS = 32
        self.BAR_COUNTER_EXIT_BITS = 32
        self.BAR_STATE_BITS = 3
        self.THREAD_NUM = 2
        self.BAR_OPCODE = 71

reg_source_file = "test_reg_source.txt"
mem_source_file = "test_mem_source.txt"
program_file = "program_test.ptx"

class ptxGPUModel(object):
    def __init__(self):
        self.model = ila.Abstraction('GPU_ptx')
        self.thread_num = 2
        self.flag_num = 10 
        self.current_flag = 0
        self.createStates()
        self.add_assumptions()
        #self.ubar()
         
    def createStates(self):
        self.pc_list = []
        self.arb_list = []
        self.flag_list = []
        self.createPC(0)
        self.createPC(1)
        self.createFlag()
        self.createRegs(0)
        self.createRegs(1)
        self.createMems()
        self.createArb()
        self.ssa_next_state(0)
        self.ssa_next_state(1)
        #self.createuBar()
        #self.addInstruction()

    def createPC(self, index):
        self.pc_list.append(self.model.reg('pc_' + str(index), instruction_format.PC_BITS))
        self.arb_list.append(ila.const(index, 1))

    def createRegs(self, index):
        self.scalar_registers = []
        self.long_scalar_registers = []
        for reg_name in ssa_declaration.keys():
            reg_type = ssa_declaration[reg_name]
            reg_len = int(reg_type[2:])
            if reg_len == 32:
                self.scalar_registers.append(self.model.reg(reg_name + '_' + str(index), instruction_format.REG_BITS))
            else:
                self.long_scalar_registers.append(self.model.reg(reg_name + '_' + str(index), instruction_format.LONG_REG_BITS)) 
        self.scalar_register_flag = self.model.bool(True)
        self.long_scalar_register_flag = self.model.bool(False)
        self.scalar_register_num = len(self.scalar_registers)
        self.long_scalar_register_num = len(self.long_scalar_registers)
        self.register_total_num = self.scalar_register_num + self.long_scalar_register_num

    def createMems(self):
        self.mem = self.model.mem('mem', instruction_format.MEM_ADDRESS_BITS, instruction_format.DMEM_BITS)

    def createArb(self):
        #self.arb_fun = self.model.fun('arb_fun', 1, [])
        #self.arb = self.model.reg('arb', 1)
        #self.model.set_next('arb', ila.appfun(self.arb_fun))
        #self.model.set_next('arb', ila.ite(self.flag_list[0] & self.flag_list[1] & self.flag_list[2] & self.flag_list[3], self.model.const(0x1, 1), self.model.const(0x0, 1)))
        #self.model.set_next('arb', ila.ite(self.arb == 1, self.model.const(0x0, 1), self.model.const(0x1, 1)))
        #self.model.set_init('arb)', self.model.const(0x0, 1))
        self.arb = self.model.inp('arb', 1)

    def createFlag(self):
        for i in range(self.flag_num):
            self.flag_list.append(self.model.bit('flag_' + str(i)))
            self.model.set_init('flag_' + str(i), self.model.bool(False))

    def ssa_next_state(self, index):
        self.model.set_next('pc_'+ str(index) , ila.ite(self.arb == self.arb_list[index], self.pc_list[index] + 4, self.pc_list[index]))
        instruction_book_obj = open('instruction_book', 'r')
        instruction_book = instruction_book_obj.readlines()
        current_pc = 0
        next_state_finished = []
        for program_line in program:
            if len(program_line) < 2:
                continue
            opcode = program_line[0]
            opcode_split = re.split('\.', opcode)
            opcode_name = opcode_split[0]
            opcode_length = int(opcode_split[-1][1:])
            current_pc_in = current_pc
            if opcode_name == 'ld':
                dest_type = ssa_declaration[program_line[1]]
                addr_type = ssa_declaration[program_line[2]]
                dest_length = int(dest_type[2:])
                addr_length = int(addr_type[2:]) 
                dest_reg = self.model.getreg(program_line[1] + '_' + str(index))
                addr_reg = self.model.getreg(program_line[2] + '_' + str(index))
                if dest_length > instruction_format.DMEM_BITS:
                    dest = ila.sign_extend(self.mem[addr_reg[(instruction_format.MEM_ADDRESS_BITS - 1) : 0]], dest_length)
                elif dest_length == instruction_format.DMEM_BITS:
                    dest = self.mem[addr_reg[(instruction_format.MEM_ADDRESS_BITS - 1) : 0]]
                else:
                    dest_interim = self.mem[addr_reg[(instruction_format.MEM_ADDRESS_BITS - 1) : 0]]
                    dest = dest_interim[(dest_length - 1) : 0]
                self.model.set_next(program_line[1] + '_' + str(index), ila.ite((self.pc_list[index] == current_pc) & (self.arb == self.arb_list[index]), dest, dest_reg))
                self.model.set_next('flag_' + str(self.current_flag), ila.ite((self.pc_list[index] == current_pc) & (self.arb == self.arb_list[index]), self.model.bool(True), self.flag_list[self.current_flag]))
                self.current_flag += 1
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'cvta':
                dest_type = ssa_declaration[program_line[1]]
                src_type = ssa_declaration[program_line[2]]
                dest_length = int(dest_type[2:])
                src_length = int(src_type[2:])
                dest = self.model.getreg(program_line[1] + '_' + str(index))
                src = self.model.getreg(program_line[2] + '_' + str(index))
                if dest_length > src_length:
                    src = ila.sign_extend(src, dest_length)
                if dest_length < src_length:
                    src = src[(dest_length - 1) : 0]
                self.model.set_next(program_line[1] + '_' + str(index), ila.ite((self.pc_list[index] == current_pc) & (self.arb == self.arb_list[index]), src, dest))
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'mov':
                dest_type = ssa_declaration[program_line[1]]
                src_type = ssa_declaration[program_line[2]]
                dest_length = int(dest_type[2:])
                src_length = int(src_type[2:])
                dest = self.model.getreg(program_line[1] + '_' + str(index))
                src = self.model.getreg(program_line[2] + '_' + str(index))
                if dest_length > src_length:
                    src = ila.sign_extend(src, dest_length)
                if dest_length < src_length:
                    src = src[(dest_length - 1) : 0]
                self.model.set_next(program_line[1] + '_' + str(index), ila.ite((self.pc_list[index] == current_pc) & (self.arb == self.arb_list[index]), src, dest))
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'add':
                dest = self.model.getreg(program_line[1] + '_' + str(index))
                src0 = self.model.getreg(program_line[2] + '_' + str(index))
                src1 = self.model.getreg(program_line[3] + '_' + str(index))
                dest_type = ssa_declaration[program_line[1]]
                src0_type = ssa_declaration[program_line[2]]
                src1_type = ssa_declaration[program_line[3]]
                dest_length = int(dest_type[2:])
                src0_length = int(src0_type[2:])
                src1_length = int(src1_type[2:])
                if dest_length > src0_length:
                    src0 = ila.sign_extend(src0, dest_length)
                if dest_length < src0_length:
                    src0 = src0[(dest_length - 1) : 0]
                if dest_length > src1_length:
                    src1 = ila.sign_extend(src1, dest_length)
                if dest_length < src1_length:
                    src1 = src1[(dest_length - 1) : 0]
                self.model.set_next(program_line[1] + '_' + str(index), ila.ite((self.pc_list[index] == current_pc) & (self.arb == self.arb_list[index]), src0 + src1, dest))
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'mul':
                dest_type = ssa_declaration[program_line[1]]
                src0_type = ssa_declaration[program_line[2]]
                dest_length = int(dest_type[2:])
                src0_length = int(src0_type[2:])
                dest = self.model.getreg(program_line[1] + '_' + str(index))
                src0 = self.model.getreg(program_line[2] + '_' + str(index))
                src1 = ila.const(int(program_line[3]), dest_length)
                if dest_length > src0_length:
                    src0 = ila.sign_extend(src0, dest_length)
                if dest_length < src0_length:
                    src0 = src0[(dest_length - 1) : 0]
                self.model.set_next(program_line[1] + '_' + str(index), ila.ite((self.pc_list[index] == current_pc) & (self.arb == self.arb_list[index]), src0 * src1, dest))
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'st':
                addr = self.model.getreg(program_line[1] + '_' + str(index))
                src = self.model.getreg(program_line[2] + '_' + str(index))
                self.model.set_next('mem', ila.ite((self.pc_list[index] == current_pc) & (self.arb == self.arb_list[index]), ila.store(self.mem, addr[(instruction_format.MEM_ADDRESS_BITS - 1):0], src[(instruction_format.DMEM_BITS - 1):0]), self.mem))
                self.model.set_next('flag_' + str(self.current_flag), ila.ite((self.pc_list[index] == current_pc) & (self.arb == self.arb_list[index]), self.model.bool(True), self.flag_list[self.current_flag]))
                self.current_flag += 1
                current_pc += 4
            if current_pc == current_pc_in:
                print program_line
        #a = self.model.reg('support', 32)
        #self.model.set_next('support', self.model.getreg('s3') + self.model.getreg('s1'))
        for reg_name in ssa_declaration.keys():
            if reg_name not in next_state_finished:
                reg = self.model.getreg(reg_name + '_' + str(index))
                self.model.set_next(reg_name + '_' + str(index), reg)
    def add_assumptions(self):
        ssa_declaration_diff_obj = open('ssa_declaration_diff_file.ptx', 'r')
        ssa_declaration_diff = pickle.load(ssa_declaration_diff_obj)
        ssa_declaration_shared_obj = open('ssa_declaration_shared_file.ptx', 'r')
        ssa_declaration_shared = pickle.load(ssa_declaration_shared_obj)
        for index in range(self.thread_num):
             self.model.set_init('pc_' + str(index), self.model.const(0x0, instruction_format.PC_BITS))   
        self.condition = []
        for reg in ssa_declaration_shared:
            for index in range(self.thread_num - 1):
                rega = self.model.getreg(reg + '_' + str(index))
                regb = self.model.getreg(reg + '_' + str(index + 1))
                self.condition.append(rega == regb) 
        for reg in ssa_declaration_diff:
            for index in range(self.thread_num - 1):
                rega = self.model.getreg(reg + '_' + str(index))
                regb = self.model.getreg(reg + '_' + str(index + 1))
                self.condition.append(rega != regb)
        
        self.constrain = self.flag_list[0] 
        #for index in range(1, self.flag_num):
        #    self.constrain = self.constrain & self.flag_list[index]
        self.constrain = self.constrain & self.flag_list[1] & self.flag_list[2] & (self.flag_list[3]) & (~self.flag_list[4]) 
        for index in range(len(self.condition)):
            self.constrain = self.constrain & self.condition[index]
        self.imply_rega = self.model.getreg('s6_0')
        self.imply_regb = self.model.getreg('s8_0')
        self.imply_result_addra = self.model.getreg('s5_0')
        self.imply_result_addrb = self.model.getreg('s7_0')
        self.imply_result = self.mem[self.imply_result_addra[(instruction_format.MEM_ADDRESS_BITS - 1) : 0]] + self.mem[self.imply_result_addrb[(instruction_format.MEM_ADDRESS_BITS - 1) : 0]]
        self.imply = (~(self.constrain)) | ((self.imply_rega + self.imply_regb) == self.imply_result)
        print self.imply
        self.predicate_bit = self.model.bit('predicate_bit')  
        self.model.set_init('predicate_bit', self.model.bool(True))
        self.model.set_next('predicate_bit', ila.ite(self.imply, self.predicate_bit, self.model.bool(False)))


ptx = ptxGPUModel()
golden_model = ila.Abstraction('golden')
g_prop = golden_model.bit('prop')
golden_model.set_init('prop', golden_model.bool(True))
golden_model.set_next('prop', golden_model.bool(True))

#print ila.bmc(15, ptx.model, ptx.predicate_bit, 10, golden_model, g_prop)
print ptx.model.bmcInit(ptx.predicate_bit == ila.bool(True), 30, True)
