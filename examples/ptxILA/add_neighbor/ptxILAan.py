import ila
import pickle
import Instruction_Format
import re
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
        self.createStates()
        #self.ubar()
         
    def createStates(self):
        self.createPC()
        self.createRegs()
        self.createMems()
        self.ssa_next_state()
        #self.createuBar()
        #self.addInstruction()

    def createPC(self):
        self.pc = self.model.reg('pc', instruction_format.PC_BITS)

    def createRegs(self):
        self.scalar_registers = []
        self.long_scalar_registers = []
        for reg_name in ssa_declaration.keys():
            reg_type = ssa_declaration[reg_name]
            reg_len = int(reg_type[2:])
            if reg_len == 32:
                self.scalar_registers.append(self.model.reg(reg_name, instruction_format.REG_BITS))
            else:
                self.long_scalar_registers.append(self.model.reg(reg_name, instruction_format.LONG_REG_BITS)) 
        self.scalar_register_flag = self.model.bool(True)
        self.long_scalar_register_flag = self.model.bool(False)
        self.scalar_register_num = len(self.scalar_registers)
        self.long_scalar_register_num = len(self.long_scalar_registers)
        self.register_total_num = self.scalar_register_num + self.long_scalar_register_num

    def createMems(self):
        self.mem = self.model.mem('mem', instruction_format.MEM_ADDRESS_BITS, instruction_format.DMEM_BITS)

    def ssa_next_state(self):
        self.model.set_next('pc', self.pc + 4)
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
                dest_reg = self.model.getreg(program_line[1])
                addr_reg = self.model.getreg(program_line[2])
                if dest_length > instruction_format.DMEM_BITS:
                    dest = ila.sign_extend(self.mem[addr_reg[(instruction_format.MEM_ADDRESS_BITS - 1) : 0]], dest_length)
                elif dest_length == instruction_format.DMEM_BITS:
                    dest = self.mem[addr_reg[(instruction_format.MEM_ADDRESS_BITS - 1) : 0]]
                else:
                    dest_interim = self.mem[addr_reg[(instruction_format.MEM_ADDRESS_BITS - 1) : 0]]
                    dest = dest_interim[(dest_length - 1) : 0]
                self.model.set_next(program_line[1], ila.ite(self.pc == current_pc, dest, dest_reg))
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'cvta':
                dest_type = ssa_declaration[program_line[1]]
                src_type = ssa_declaration[program_line[2]]
                dest_length = int(dest_type[2:])
                src_length = int(src_type[2:])
                dest = self.model.getreg(program_line[1])
                src = self.model.getreg(program_line[2])
                if dest_length > src_length:
                    src = ila.sign_extend(src, dest_length)
                if dest_length < src_length:
                    src = src[(dest_length - 1) : 0]
                self.model.set_next(program_line[1], ila.ite(self.pc == current_pc, src, dest))
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'mov':
                dest_type = ssa_declaration[program_line[1]]
                src_type = ssa_declaration[program_line[2]]
                dest_length = int(dest_type[2:])
                src_length = int(src_type[2:])
                dest = self.model.getreg(program_line[1])
                src = self.model.getreg(program_line[2])
                if dest_length > src_length:
                    src = ila.sign_extend(src, dest_length)
                if dest_length < src_length:
                    src = src[(dest_length - 1) : 0]
                self.model.set_next(program_line[1], ila.ite(self.pc == current_pc, src, dest))
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'add':
                dest = self.model.getreg(program_line[1])
                src0 = self.model.getreg(program_line[2])
                src1 = self.model.getreg(program_line[3])
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
                self.model.set_next(program_line[1], ila.ite(self.pc == current_pc, src0 + src1, dest))
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'mul':
                dest_type = ssa_declaration[program_line[1]]
                src0_type = ssa_declaration[program_line[2]]
                dest_length = int(dest_type[2:])
                src0_length = int(src0_type[2:])
                dest = self.model.getreg(program_line[1])
                src0 = self.model.getreg(program_line[2])
                src1 = ila.const(int(program_line[3]), dest_length)
                if dest_length > src0_length:
                    src0 = ila.sign_extend(src0, dest_length)
                if dest_length < src0_length:
                    src0 = src0[(dest_length - 1) : 0]
                self.model.set_next(program_line[1], ila.ite(self.pc == current_pc, src0 * src1, dest))
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'st':
                addr = self.model.getreg(program_line[1])
                src = self.model.getreg(program_line[2])
                self.model.set_next('mem', ila.ite(self.pc == current_pc,ila.store(self.mem, addr[(instruction_format.MEM_ADDRESS_BITS - 1):0], src[(instruction_format.DMEM_BITS - 1):0]), self.mem))
                current_pc += 4
            if current_pc == current_pc_in:
                print program_line
        a = self.model.reg('support', 32)
        self.model.set_next('support', self.model.getreg('s3') + self.model.getreg('s1'))
        for reg_name in ssa_declaration.keys():
            if reg_name not in next_state_finished:
                reg = self.model.getreg(reg_name)
                self.model.set_next(reg_name, reg)

ptx = ptxGPUModel()
ptx.model.set_init('pc', ila.const(0x0, 32))
print ila.bmc(2, ptx.model, ptx.model.getreg('s4'), 2, ptx.model, ptx.model.getreg('support'))
