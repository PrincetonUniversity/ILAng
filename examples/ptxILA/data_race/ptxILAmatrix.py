import ila
import pickle
import Instruction_Format
import re
ila.setloglevel(3, '')
ila.enablelog('BMCResult')
ptx_declaration_obj = open('ptx_declaration_file.ptx', 'r')
ptx_declaration = pickle.load(ptx_declaration_obj)
program_obj = open('ptx_add_neighbor.ptx', 'r')
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
        self.run_num = 2
        self.flag_num = 10   #TODO: 
        self.current_flag = 0
        self.createStates()
        self.add_assumptions()
        #self.ubar()
         
    def createStates(self):
        self.pc_list = []
        self.arb_choice_list = []
        self.arb_list = []
        self.arb_next_state_list = []
        self.mem_list = []
        #self.imem_list = []
        self.mem_next_state_list = []
        self.mem_access_list = []
        for i in range(self.run_num):
            self.pc_list.append([])
            self.arb_choice_list.append([])

        self.next_state_dict = []
        self.pred_registers = []
        self.scalar_registers = []
        self.long_scalar_registers = []
        for i in range(self.run_num):
            self.next_state_dict.append({})
            self.pred_registers.append([])
            self.scalar_registers.append([])
            self.long_scalar_registers.append([])
        self.createPC(0, 0)
        self.createPC(0, 1)
        self.createPC(1, 0)
        self.createPC(1, 1)
        
        self.createRegs(0, 0)
        self.createRegs(0, 1)
        self.createRegs(1, 0)
        self.createRegs(1, 1)
        self.createMems(0)
        self.createMems(1)
        self.createArb(0)
        self.createArb(1)
        self.createInp()
        self.generate_next_state(0, 0)
        self.generate_next_state(0, 1)
        self.generate_next_state(1, 0)
        self.generate_next_state(1, 1)
        self.set_next_state(0)
        self.set_next_state(1)
        self.set_next_pc(0, 0)
        self.set_next_pc(0, 1)
        self.set_next_pc(1, 0)
        self.set_next_pc(1, 1)
        #self.createuBar()
        #self.addInstruction()

    def createPC(self, run_index, index):
        self.pc_list[run_index].append(self.model.reg('pc_%d_%d' %(run_index, index), instruction_format.PC_BITS))
        self.arb_choice_list[run_index].append(ila.const(index, 1))

    def createRegs(self, run_index, index):
        for reg_name in ptx_declaration.keys():
            reg_type = ptx_declaration[reg_name]
            if isinstance(reg_type, tuple):
                continue
            if reg_type == '.pred':
                self.pred_registers[run_index].append(self.model.reg(reg_name + '_%d_%d' %(run_index, index), instruction_format.PRED_REG_BITS))
                self.next_state_dict[run_index][reg_name + '_%d_%d' %(run_index, index)] = self.pred_registers[run_index][-1]
                continue
            reg_len = int(reg_type[2:])
            if reg_len == 32:
                self.scalar_registers[run_index].append(self.model.reg(reg_name + '_%d_%d' %(run_index, index), instruction_format.REG_BITS))
                self.next_state_dict[run_index][reg_name + '_%d_%d' %(run_index, index)] = self.scalar_registers[run_index][-1]
            else:
                self.long_scalar_registers[run_index].append(self.model.reg(reg_name + '_%d_%d' %(run_index, index), instruction_format.LONG_REG_BITS)) 
                self.next_state_dict[run_index][reg_name + '_%d_%d' %(run_index, index)] = self.long_scalar_registers[run_index][-1]
        self.scalar_register_num = len(self.scalar_registers)
        self.long_scalar_register_num = len(self.long_scalar_registers)
        self.register_total_num = self.scalar_register_num + self.long_scalar_register_num

    def createMems(self, run_index):
        self.mem_list.append(self.model.mem('mem_%d' %(run_index), instruction_format.MEM_ADDRESS_BITS, instruction_format.DMEM_BITS))
        self.mem_next_state_list.append(self.mem_list[run_index])
        #self.imem_list.append(self.model.mem('imem_%d' %(run_index), instruction_format.MEM_ADDRESS_BITS, instruction_format.DMEM_BITS))
        #self.model.set_next('imem_%d' %(run_index), self.imem_list[run_index])
        
    def createArb(self, run_index):
        self.arb_list.append(self.model.reg('arb_%d' %(run_index), 1))

    def createInp(self):
        self.random_inp = self.model.inp('arb_input', 1)

    def generate_next_state(self, run_index, index):
        self.mem_access_list = []
        instruction_book_obj = open('instruction_book', 'r')
        instruction_book = instruction_book_obj.readlines()
        current_pc = 0
        next_state_finished = []
        pc_target = {}
        current_pc = 0
        for program_line in program:
            if len(program_line) < 2:
                if len(program_line) == 0:
                    continue
                if program_line[0][-1] == ':':
                    pc_target[program_line[0][:-1]] = current_pc
            else:
                current_pc += 4
        current_pc = 0
        for program_line in program:
            if len(program_line) < 2:
                continue
            opcode = program_line[0]
            opcode_split = re.split('\.', opcode)
            opcode_name = opcode_split[0]
            #opcode_length = int(opcode_split[-1][1:])
            current_pc_in = current_pc
            if opcode_name == 'ld':
                opcode_mem_type = opcode_split[1]
                self.mem_access_list.append(current_pc)
                dest_str = program_line[1]
                addr_str = program_line[2]
                imm_pos = addr_str.find('+') # a = 'ss+2' a.find('+'), a[:2], a[2 + 1:] 
                imm_str = '0'
                if imm_pos != -1:
                    imm_str = addr_str[(imm_pos + 1):]
                    addr_str = addr_str[:imm_pos]
                dest_type = ptx_declaration[dest_str]
                addr_type = ptx_declaration[addr_str]
                dest_length = int(dest_type[2:])
                addr_length = int(addr_type[2:]) 
                dest_reg = self.model.getreg(dest_str + '_%d_%d' %(run_index, index))
                addr_reg = self.model.getreg(addr_str + '_%d_%d' %(run_index, index))
                if addr_length >= instruction_format.MEM_ADDRESS_BITS:
                    address = addr_reg[(instruction_format.MEM_ADDRESS_BITS - 1) : 0]
                else:
                    address = ila.sign_extend(addr_reg, instruction_format.MEM_ADDRESS_BITS)
                if dest_length > instruction_format.DMEM_BITS:
                    if opcode_mem_type == 'param':
                        #dest = ila.sign_extend(self.imem_list[run_index][address + ila.const(int(imm_str), instruction_format.MEM_ADDRESS_BITS)], dest_length)
                        continue
                    else:
                        dest = ila.sign_extend(self.mem_list[run_index][address + ila.const(int(imm_str), instruction_format.MEM_ADDRESS_BITS)], dest_length) 
                elif dest_length == instruction_format.DMEM_BITS:
                    if opcode_mem_type == 'param':
                        #dest = self.imem_list[run_index][address + ila.const(int(imm_str), instruction_format.MEM_ADDRESS_BITS)]
                        continue
                    else:
                        dest = self.mem_list[run_index][address + ila.const(int(imm_str), instruction_format.MEM_ADDRESS_BITS)] 
                else:
                    if opcode_mem_type == 'param':
                        #dest_interim = self.imem_list[run_index][address + ila.const(int(imm_str), instruction_format.MEM_ADDRESS_BITS)]
                        continue
                    else:
                        dest_interim = self.mem_list[run_index][address + ila.const(int(imm_str), instruction_format.MEM_ADDRESS_BITS)] 
                    dest = dest_interim[(dest_length - 1) : 0]
                self.next_state_dict[run_index][dest_str + '_%d_%d' %(run_index, index)] = ila.ite(self.pc_list[run_index][index] == current_pc, dest, self.next_state_dict[run_index][dest_str + '_%d_%d' %(run_index, index)])
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'cvta':
                dest_type = ptx_declaration[program_line[1]]
                src_type = ptx_declaration[program_line[2]]
                dest_length = int(dest_type[2:])
                src_length = int(src_type[2:])
                dest = self.model.getreg(program_line[1] + '_%d_%d' %(run_index, index))
                src = self.model.getreg(program_line[2] + '_%d_%d' %(run_index, index))
                if dest_length > src_length:
                    src = ila.sign_extend(src, dest_length)
                if dest_length < src_length:
                    src = src[(dest_length - 1) : 0]
                self.next_state_dict[run_index][program_line[1] + '_%d_%d' %(run_index, index)] = ila.ite(self.pc_list[run_index][index] == current_pc, src, self.next_state_dict[run_index][program_line[1] + '_%d_%d' %(run_index, index)])
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'mov':
                dest_type = ptx_declaration[program_line[1]]
                dest_length = int(dest_type[2:])
                dest = self.model.getreg(program_line[1] + '_%d_%d' %(run_index, index))
                src_str = program_line[2]
                if src_str in ptx_declaration.keys():
                    src = self.model.getreg(src_str + '_%d_%d' %(run_index, index))
                    src_type = ptx_declaration[program_line[2]]
                    src_length = int(src_type[2:])
                    if dest_length > src_length:
                        src = ila.sign_extend(src, dest_length)
                    if dest_length < src_length:
                        src = src[(dest_length - 1) : 0]
                else:
                    src = ila.const(int(src_str), dest_length)
                self.next_state_dict[run_index][program_line[1] + '_%d_%d' %(run_index, index)] = ila.ite(self.pc_list[run_index][index] == current_pc, src, self.next_state_dict[run_index][program_line[1] + '_%d_%d'%(run_index, index)])
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'add':
                dest = self.model.getreg(program_line[1] + '_%d_%d' %(run_index, index))
                dest_type = ptx_declaration[program_line[1]]
                dest_length = int(dest_type[2:])

                src0_str = program_line[2] 
                if src0_str in ptx_declaration.keys():
                    src0 = self.model.getreg(src0_str + '_%d_%d' %(run_index, index))
                    src0_type = ptx_declaration[src0_str]
                    src0_length = int(src0_type[2:])
                    if dest_length > src0_length:
                        src0 = ila.sign_extend(src0, dest_length)
                    elif dest_length < src0_length:
                        src0 = src0[(dest_length - 1) : 0]    
                else:
                    src0 = ila.const(int(src0_str), dest_length)
                
                src1_str = program_line[3]
                if src1_str in ptx_declaration.keys():
                    src1 = self.model.getreg(src1_str + '_%d_%d' %(run_index, index))
                    src1_type = ptx_declaration[src1_str]
                    src1_length = int(src1_type[2:])
                    if dest_length > src1_length:
                        src1 = ila.sign_extend(src1, dest_length)
                    elif dest_length < src1_length:
                        src1 = src1[(dest_length - 1) : 0]
                else:
                    src1 = ila.const(int(src1_str), dest_length)

                self.next_state_dict[run_index][program_line[1] + '_%d_%d' %(run_index, index)] = ila.ite(self.pc_list[run_index][index] == current_pc, src0 + src1, self.next_state_dict[run_index][program_line[1] + '_%d_%d' %(run_index, index)])
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'mul':
                dest = self.model.getreg(program_line[1] + '_%d_%d' %(run_index, index))
                dest_type = ptx_declaration[program_line[1]]
                dest_length = int(dest_type[2:])

                src0_str = program_line[2]
                if src0_str in ptx_declaration.keys():
                    src0 = self.model.getreg(src0_str + '_%d_%d' %(run_index, index))
                    src0_type = ptx_declaration[src0_str]
                    src0_length = int(src0_type[2:])
                    if dest_length > src0_length:
                        src0 = ila.sign_extend(src0, dest_length)
                    elif dest_length < src0_length:
                        src0 = src0[(dest_length - 1) : 0]
                else:
                    src0 = ila.const(int(src0_str), dest_length)

                src1_str = program_line[3]
                if src1_str in ptx_declaration.keys():
                    src1 = self.model.getreg(src1_str + '_%d_%d' %(run_index, index))
                    src1_type = ptx_declaration[src1_str]
                    src1_length = int(src1_type[2:])
                    if dest_length > src1_length:
                        src1 = ila.sign_extend(src1, dest_length)
                    elif dest_length < src1_length:
                        src1 = src1[(dest_length - 1) : 0]
                else:
                    src1 = ila.const(int(src1_str), dest_length)

                self.next_state_dict[run_index][program_line[1] + '_%d_%d' %(run_index, index)] = ila.ite(self.pc_list[run_index][index] == current_pc, src0 * src1, self.next_state_dict[run_index][program_line[1] + '_%d_%d' %(run_index, index)])
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'st':
                self.mem_access_list.append(current_pc)
                src_str = program_line[2]
                addr_str = program_line[1]
                imm_pos = addr_str.find('+') # a = 'ss+2' a.find('+'), a[:2], a[2 + 1:] 
                imm_str = '0'
                if imm_pos != -1:
                    imm_str = addr[(imm_pos + 1):]
                    addr_str = addr_str[:imm_pos]
                src_type = ptx_declaration[src_str]
                addr_type = ptx_declaration[addr_str]
                src_length = int(src_type[2:])
                addr_length = int(addr_type[2:]) 
                src = self.model.getreg(src_str + '_%d_%d' %(run_index, index))
                addr = self.model.getreg(addr_str + '_%d_%d' %(run_index, index))
                self.mem_next_state_list[run_index] = ila.ite((self.pc_list[run_index][index] == current_pc) & (self.arb_list[run_index] == self.arb_choice_list[run_index][index]), ila.store(self.mem_list[run_index], addr[(instruction_format.MEM_ADDRESS_BITS - 1) : 0] + ila.const(int(imm_str), instruction_format.MEM_ADDRESS_BITS), src), self.mem_next_state_list[run_index])
                current_pc += 4
            if current_pc == current_pc_in:
                print program_line

        #a = self.model.reg('support', 32)
        #self.model.set_next('support', self.model.getreg('s3') + self.model.getreg('s1'))
        for reg_name in ptx_declaration.keys():
            if reg_name not in next_state_finished:
                reg = self.model.getreg(reg_name + '_%d_%d' %(run_index, index))
                self.model.set_next(reg_name + '_%d_%d' %(run_index, index), reg)
        self.pc_max = current_pc
 
    def set_next_state(self, run_index):
        #reg
        for state_name in self.next_state_dict[run_index].keys():
            index = int(state_name[-1])
            self.model.set_next(state_name, ila.ite(self.arb_list[run_index] == self.arb_choice_list[run_index][index], self.next_state_dict[run_index][state_name], self.model.getreg(state_name)))
        #mem
        self.model.set_next('mem_%d' %(run_index), self.mem_next_state_list[run_index])
        #arb
        if run_index == 0: 
            self.arb_next_state_list.append(self.arb_list[run_index])
            self.arb_next_state_list[run_index] = ila.ite(self.pc_list[run_index][0] == self.pc_max, self.arb_choice_list[run_index][1], ila.ite(self.pc_list[run_index][1] == self.pc_max, self.arb_choice_list[run_index][0], self.arb_next_state_list[run_index])) 
            self.model.set_next('arb_%d' %(run_index), self.arb_next_state_list[run_index])
        #run 1
        else:
            self.arb_next_state_list.append(self.arb_list[run_index])
            for mem_access_pc in self.mem_access_list:
                self.arb_next_state_list[run_index] = ila.ite(self.pc_list[run_index][0] == (mem_access_pc - 4), self.arb_choice_list[run_index][1], self.arb_next_state_list[run_index])
                self.arb_next_state_list[run_index] = ila.ite(self.pc_list[run_index][1] == (mem_access_pc - 4), self.arb_choice_list[run_index][0], self.arb_next_state_list[run_index])
            for mem_access_pc0 in self.mem_access_list:
                for mem_access_pc1 in self.mem_access_list:
                    self.arb_next_state_list[run_index] = ila.ite((self.pc_list[run_index][0] == (mem_access_pc0 - 4)) & (self.pc_list[run_index][1] == (mem_access_pc1 - 4)), self.random_inp, self.arb_next_state_list[run_index]) 
            self.model.set_next('arb_%d' %(run_index), self.arb_next_state_list[run_index])

    def set_next_pc(self, run_index, index):
        self.model.set_next('pc_%d_%d' %(run_index, index) , ila.ite((self.arb_list[run_index] == self.arb_choice_list[run_index][index]) & (self.pc_list[run_index][index] < self.pc_max), self.pc_list[run_index][index] + 4, self.pc_list[run_index][index]))

    def add_assumptions(self):
        ptx_declaration_diff_obj = open('ptx_declaration_diff_file.ptx', 'r')
        ptx_declaration_diff = pickle.load(ptx_declaration_diff_obj)
        ptx_declaration_shared_obj = open('ptx_declaration_shared_file.ptx', 'r')
        ptx_declaration_shared = pickle.load(ptx_declaration_shared_obj)
        
        self.cond = self.model.bool(True)
        for run_index in range(self.run_num):
            for index in range(self.thread_num):
                pc = self.model.getreg('pc_%d_%d' %(run_index, index))
                self.cond = self.cond & (pc == self.model.const(0x0, instruction_format.PC_BITS))
        
        for reg_name in ptx_declaration.keys():
            reg_type = ptx_declaration[reg_name]
            reg_len = int(reg_type[2:])
            if reg_name not in ptx_declaration_shared:
                for index in range(self.thread_num):
                    reg0 = self.model.getreg(reg_name + '_%d_%d' %(0, index))
                    reg1 = self.model.getreg(reg_name + '_%d_%d' %(1, index))
                    self.cond = self.cond & (reg0 == reg1)
            else:
                reg0 = self.model.getreg(reg_name + '_%d_%d' %(0, 0))
                reg1 = self.model.getreg(reg_name + '_%d_%d' %(0, 1))
                reg2 = self.model.getreg(reg_name + '_%d_%d' %(1, 0))
                reg3 = self.model.getreg(reg_name + '_%d_%d' %(1, 1))
                self.cond = self.cond & (reg0 == reg1)
                self.cond = self.cond & (reg1 == reg2)
                self.cond = self.cond & (reg2 == reg3)
        for reg in ptx_declaration_diff:
            for run_index in range(self.run_num):
                reg0 = self.model.getreg(reg + '_%d_%d' %(run_index, 0))
                reg1 = self.model.getreg(reg + '_%d_%d' %(run_index, 1))
                self.cond = self.cond & (reg0 != reg1)
        rega = self.model.getreg('%rd1_0_1')
        regb = self.model.getreg('%rd1_1_1') 
        #self.cond = self.cond & (self.mem_list[0] == self.mem_list[1]) & (self.imem_list[0] == self.imem_list[1])
        self.cond = self.cond & (self.mem_list[0] == self.mem_list[1]) & (rega == regb)
        regc = self.model.getreg('%rd1_0_0')
        regd = self.model.getreg('%rd1_1_0') 
        self.cond = self.cond & (rega == regc) & (regc == regd)
        rega = self.model.getreg('%r1_0_0')
        regb = self.model.getreg('%r1_1_0') 
        self.cond = self.cond & (rega == regb)
        regc = self.model.getreg('%r1_0_1')
        regd = self.model.getreg('%r1_1_1') 
        self.cond = self.cond & (rega == regc) & (regc == regd)




 


        '''
        for run_index in range(self.run_num):
            for index in range(self.thread_num):
                 self.model.set_init('pc_%d_%d' %(run_index, index), self.model.const(0x0, instruction_format.PC_BITS))   
        
        for reg_name in ptx_declaration.keys():
            reg_type = ptx_declaration[reg_name]
            reg_len = int(reg_type[2:])
            if reg_name not in ptx_declaration_shared:
                for index in range(self.thread_num):
                    current_arb = ila.appfun(self.model.fun(reg_name + '_arb_%d' %(index), reg_len, []))
                    for run_index in range(self.run_num):
                        self.model.set_init(reg_name + '_%d_%d' %(run_index, index), current_arb)
            else:
                current_arb = ila.appfun(self.model.fun(reg_name + '_arb', reg_len, []))
                for index in range(self.thread_num):
                    for run_index in range(self.run_num):
                        self.model.set_init(reg_name + '_%d_%d' %(run_index, index), current_arb)

        self.condition = []
        for reg in ptx_declaration_diff:
            for run_index in range(self.run_num):
                for index in range(self.thread_num - 1):
                    rega = self.model.getreg(reg + '_%d_%d' %(run_index, index))
                    regb = self.model.getreg(reg + '_%d_%d' %(run_index, index + 1))
                    self.condition.append(rega != regb) 
        '''
        self.condition = []
        for run_index in range(self.run_num):
            for index in range(self.thread_num):
                self.condition.append(self.pc_list[run_index][index] >= (self.pc_max - 4)) 
        self.constrain = self.condition[0]
        for index in range(1, len(self.condition)):
            self.constrain = self.constrain & self.condition[index]
        self.implied = self.model.bool(True)
        for reg_name in ptx_declaration.keys(): 
            if reg_name not in ptx_declaration_diff:
                rega = self.model.getreg(reg_name + '_%d_%d' %(0, 0))
                regb = self.model.getreg(reg_name + '_%d_%d' %(1, 0))
                self.implied = self.implied & (rega == regb)

     #   self.implied = self.implied & (self.mem_list[0] == self.mem_list[1])
        self.imply = (~(self.constrain))  | (self.implied)

        self.predicate_bit = self.model.bit('predicate_bit')  
        #self.model.set_init('predicate_bit', self.model.bool(True))
        self.cond = self.cond & (self.predicate_bit == self.model.bool(True))
        self.model.set_next('predicate_bit', ila.ite(self.imply, self.predicate_bit, self.model.bool(False)))


ptx = ptxGPUModel()
golden_model = ila.Abstraction('golden')
g_prop = golden_model.bit('prop')
golden_model.set_init('prop', golden_model.bool(True))
golden_model.set_next('prop', golden_model.bool(True))

print ptx.model.bmcCond(ptx.predicate_bit == ila.bool(True), 23, ptx.cond)
#print ptx.model.bmcInit(ptx.predicate_bit == ila.bool(True), 28, True)
