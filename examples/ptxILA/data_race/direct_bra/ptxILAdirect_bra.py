import ila
import pickle
import Instruction_Format
import re
ila.setloglevel(3, '')
ila.enablelog('BMCResult')
ptx_declaration_obj = open('ptx_declaration_file', 'r')
ptx_declaration = pickle.load(ptx_declaration_obj)
program_obj = open('ptx_add_neighbor', 'r')
program = pickle.load(program_obj)
instruction_format = Instruction_Format.InstructionFormat()

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

class ptxGPUModel(object):
    def __init__(self):
        self.model = ila.Abstraction('GPU_ptx')
        self.thread_num = 2
        self.createStates()
        self.add_assumptions()
        #self.ubar()
         
    def createStates(self):
        self.pc_list = []
        self.pc_next_list = []
        #self.imem_list = []
        self.next_state_dict = {}
        self.pred_registers = []
        self.scalar_registers = []
        self.long_scalar_registers = []
        self.log_registers = []
        self.check_registers = []
        self.en_log_registers = []
        self.en_check_registers = []
        self.createPC(0)
        self.createPC(1)
        
        self.createRegs(0)
        self.createRegs(1)

        self.createLog()
        self.createCheck()

        self.generate_next_state(0)
        self.generate_next_state(1)
        self.set_next_state()
        self.set_next_pc(0)
        self.set_next_pc(1)
        #self.createuBar()
        #self.addInstruction()

    def createPC(self, index):
        self.pc_list.append(self.model.reg('pc_%d' %(index), instruction_format.PC_BITS))
        self.pc_next_list.append(self.pc_list[index] + 4)

    def createRegs(self, index):
        for reg_name in ptx_declaration.keys():
            reg_type = ptx_declaration[reg_name]
            if isinstance(reg_type, tuple):
                continue
            if reg_type == '.pred':
                self.pred_registers.append(self.model.reg(reg_name + '_%d' %(index), instruction_format.PRED_REG_BITS))
                self.next_state_dict[reg_name + '_%d' %(index)] = self.pred_registers[-1]
                continue
            reg_len = int(reg_type[2:])
            if reg_len == 32:
                self.scalar_registers.append(self.model.reg(reg_name + '_%d' %(index), instruction_format.REG_BITS))
                self.next_state_dict[reg_name + '_%d' %(index)] = self.scalar_registers[-1]
            else:
                self.long_scalar_registers.append(self.model.reg(reg_name + '_%d' %(index), instruction_format.LONG_REG_BITS)) 
                self.next_state_dict[reg_name + '_%d' %(index)] = self.long_scalar_registers[-1]
        self.scalar_register_num = len(self.scalar_registers)
        self.long_scalar_register_num = len(self.long_scalar_registers)
        self.register_total_num = self.scalar_register_num + self.long_scalar_register_num
        
    def createLog(self):
        ld_set_file = 'ld_set'
        ld_set_obj = open(ld_set_file, 'r')
        ld_set = pickle.load(ld_set_obj)
        ld_set_obj.close()
        st_set_file = 'st_set'
        st_set_obj = open(st_set_file, 'r')
        st_set = pickle.load(st_set_obj)
        st_set_obj.close()
        pred_map_file = 'pred_map'
        pred_map_obj = open(pred_map_file, 'r')
        pred_map = pickle.load(pred_map_obj)
        pred_map_obj.close()
        for pc in ld_set.keys():
            reg_name = ld_set[pc]
            operands = re.split('\+', reg_name)
            reg_len = 64
            for i in range(len(operands)):
                operand = operands[i]
                if operand in ptx_declaration.keys():
                    op_reg_type = ptx_declaration[operand]
                    op_reg_len = int(op_reg_type[2:])
                    if op_reg_len < reg_len:
                        operands[i] = ila.sign_extend(self.model.getreg(operand + '_%d' % (0)), reg_len)
                    else:
                        operands[i] = self.model.getreg(operand + '_%d' % (0))
                else:
                    operands[i] = ila.const(int(operand), reg_len)

            log_reg = self.model.reg(reg_name + '_log_%d'% (pc) , instruction_format.LONG_REG_BITS)
            self.log_registers.append(log_reg)
            log_reg_next = operands[0]
            for i in range(1, len(operands)):
                log_reg_next = log_reg_next + operands[i]
            self.model.set_next(reg_name + '_log_%d' % (pc), ila.ite(self.pc_list[0] == (pc), log_reg_next, log_reg))

            en_log_reg = self.model.reg(reg_name + '_en_log_%d' % (pc), 1)
            self.en_log_registers.append(en_log_reg) 
            en_log_reg_next = ila.const(0x1, 1)
            pred_list = pred_map[pc]
            for pred in pred_list:
                pred_reg = self.model.getreg(pred + '_%d' % (0))
                en_log_reg_next = ila.ite(pred_reg == ila.const(0x0, 1), en_log_reg_next, en_log_reg)
            self.model.set_next(reg_name + '_en_log_%d' % (pc), ila.ite(self.pc_list[0] == pc, en_log_reg_next, en_log_reg))
            
        for pc in st_set.keys():
            reg_name = st_set[pc]
            operands = re.split('\+', reg_name)
            reg_len = 64
            for i in range(len(operands)):
                operand = operands[i]
                if operand in ptx_declaration.keys():
                    op_reg_type = ptx_declaration[operand]
                    op_reg_len = int(op_reg_type[2:])
                    if op_reg_len < reg_len:
                        operands[i] = ila.sign_extend(self.model.getreg(operand + '_%d' % (0)), reg_len)
                    else:
                        operands[i] = self.model.getreg(operand + '_%d' % (0))
                else:
                    operands[i] = ila.const(int(operand), reg_len)
            log_reg = self.model.reg(reg_name + '_log_%d'% (pc) , instruction_format.LONG_REG_BITS)
            self.log_registers.append(log_reg)
            log_reg_next = operands[0]
            for i in range(1, len(operands)):
                log_reg_next = log_reg_next + operands[i]
            self.model.set_next(reg_name + '_log_%d' % (pc), ila.ite(self.pc_list[0] == (pc), log_reg_next, log_reg))
 
            en_log_reg = self.model.reg(reg_name + '_en_log_%d' % (pc), 1)
            self.en_log_registers.append(en_log_reg) 
            en_log_reg_next = ila.const(0x1, 1)
            pred_list = pred_map[pc]
            for pred in pred_list:
                pred_reg = self.model.getreg(pred + '_%d' % (0))
                en_log_reg_next = ila.ite(pred_reg == ila.const(0x0, 1), en_log_reg_next, en_log_reg)
            self.model.set_next(reg_name + '_en_log_%d' % (pc), ila.ite(self.pc_list[0] == pc, en_log_reg_next, en_log_reg))
 

    def createCheck(self):
        st_set_file = 'st_set'
        st_set_obj = open(st_set_file, 'r')
        st_set = pickle.load(st_set_obj)
        st_set_obj.close()
        pred_map_file = 'pred_map'
        pred_map_obj = open(pred_map_file, 'r')
        pred_map = pickle.load(pred_map_obj)
        pred_map_obj.close()
        for pc in st_set.keys():
            reg_name = st_set[pc]
            operands = re.split('\+', reg_name)
            reg_len = 64
            for i in range(len(operands)):
                operand = operands[i]
                if operand in ptx_declaration.keys():
                    op_reg_type = ptx_declaration[operand]
                    op_reg_len = int(op_reg_type[2:])
                    if op_reg_len < reg_len:
                        operands[i] = ila.sign_extend(self.model.getreg(operand + '_%d' % (1)), reg_len)
                    else:
                        operands[i] = self.model.getreg(operand + '_%d' % (1))
                else:
                    operands[i] = ila.const(int(operand), reg_len)
            check_reg = self.model.reg(reg_name + '_check_%d' % (pc), instruction_format.LONG_REG_BITS) 
            self.check_registers.append(check_reg)
            check_reg_next = operands[0]
            for i in range(1, len(operands)):
                check_reg_next = check_reg_next + operands[i]
            self.model.set_next(reg_name + '_check_%d' % (pc), ila.ite(self.pc_list[1] == (pc), check_reg_next, check_reg))

            en_check_reg = self.model.reg(reg_name + '_en_check_%d' % (pc), 1)
            self.en_check_registers.append(en_check_reg) 
            en_check_reg_next = ila.const(0x1, 1)
            pred_list = pred_map[pc]
            for pred in pred_list:
                pred_reg = self.model.getreg(pred + '_%d' % (1))
                en_check_reg_next = ila.ite(pred_reg == ila.const(0x0, 1), en_check_reg_next, en_check_reg)
            self.model.set_next(reg_name + '_en_check_%d' % (pc), ila.ite(self.pc_list[1] == (pc), en_check_reg_next, en_check_reg))
 

    def generate_next_state(self, index):
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
        print pc_target
        current_pc = 0
        for program_line in program:
            if len(program_line) < 2:
                continue
            opcode = program_line[0]
            opcode_split = re.split('\.', opcode)
            opcode_name = opcode_split[0]
            #opcode_length = int(opcode_split[-1][1:])
            current_pc_in = current_pc
            if opcode_name == 'setp':
                opcode_cmp = opcode_split[1]
                dest_str = program_line[1]
                src0_str = program_line[2]
                src1_str = program_line[3]
                dest_pred = self.model.getreg(dest_str + '_%d' % (index))
                (src0, src0_length) = self.aux_imm(src0_str, index)
                (src1, src1_length) = self.aux_imm(src1_str, index)
                if src0_length > src1_length:
                    src1 = ila.sign_extend(src1, src0_length)
                if src1_length > src0_length:
                    src0 = ila.sign_extend(src0, src1_length)
                if opcode_cmp == 'gt':
                    dest = ila.ite(src0 > src1, self.model.const(0x1, 1), self.model.const(0x0, 1))
                if opcode_cmp == 'lt':
                    dest = ila.ite(src0 < src1, self.model.const(0x1, 1), self.model.const(0x0, 1))
                if opcode_cmp == 'ne':
                    dest = ila.ite(src0 != src1, self.model.const(0x1, 1), self.model.const(0x0, 1))
                self.next_state_dict[dest_str + '_%d' % (index)] = ila.ite(self.pc_list[index] == current_pc, dest, self.next_state_dict[dest_str + '_%d' % (index)])
                next_state_finished.append(dest_str)
                current_pc += 4

            if opcode_name == '@':
                opcode_pred_name = program_line[1]
                opcode_pred = self.model.getreg(opcode_pred_name + '_%d' % (index))
                opcode_jmp_dest = program_line[3]
                opcode_jmp_target = pc_target[opcode_jmp_dest]
                print opcode_jmp_target
                pc_jmp = ila.ite(opcode_pred == 1, ila.const(opcode_jmp_target, instruction_format.PC_BITS), self.pc_list[index] + 4)
                self.pc_next_list[index] = ila.ite(self.pc_list[index] == current_pc, pc_jmp, self.pc_next_list[index])
                current_pc += 4

            if opcode_name == 'ld':
                current_pc += 4
            if opcode_name == 'cvta':
                dest_type = ptx_declaration[program_line[1]]
                src_type = ptx_declaration[program_line[2]]
                dest_length = int(dest_type[2:])
                src_length = int(src_type[2:])
                dest = self.model.getreg(program_line[1] + '_%d' %(index))
                src = self.model.getreg(program_line[2] + '_%d' %(index))
                if dest_length > src_length:
                    src = ila.sign_extend(src, dest_length)
                if dest_length < src_length:
                    src = src[(dest_length - 1) : 0]
                self.next_state_dict[program_line[1] + '_%d' %(index)] = ila.ite(self.pc_list[index] == current_pc, src, self.next_state_dict[program_line[1] + '_%d' %(index)])
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'mov':
                dest_type = ptx_declaration[program_line[1]]
                dest_length = int(dest_type[2:])
                dest = self.model.getreg(program_line[1] + '_%d' %(index))
                src_str = program_line[2]
                if src_str in ptx_declaration.keys():
                    src = self.model.getreg(src_str + '_%d' %(index))
                    src_type = ptx_declaration[program_line[2]]
                    src_length = int(src_type[2:])
                    if dest_length > src_length:
                        src = ila.sign_extend(src, dest_length)
                    if dest_length < src_length:
                        src = src[(dest_length - 1) : 0]
                else:
                    src = ila.const(int(src_str), dest_length)
                self.next_state_dict[program_line[1] + '_%d' %(index)] = ila.ite(self.pc_list[index] == current_pc, src, self.next_state_dict[program_line[1] + '_%d'%(index)])
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'shr':
                dest = self.model.getreg(program_line[1] + '_%d' %(index))
                dest_type = ptx_declaration[program_line[1]]
                dest_length = int(dest_type[2:])

                src0_str = program_line[2] 
                if src0_str in ptx_declaration.keys():
                    src0 = self.model.getreg(src0_str + '_%d' %(index))
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
                    src1 = self.model.getreg(src1_str + '_%d' %(index))
                    src1_type = ptx_declaration[src1_str]
                    src1_length = int(src1_type[2:])
                    if dest_length > src1_length:
                        src1 = ila.sign_extend(src1, dest_length)
                    elif dest_length < src1_length:
                        src1 = src1[(dest_length - 1) : 0]
                else:
                    src1 = ila.const(int(src1_str), dest_length)

                self.next_state_dict[program_line[1] + '_%d' %(index)] = ila.ite(self.pc_list[index] == current_pc, ila.ashr(src0, src1), self.next_state_dict[program_line[1] + '_%d' %(index)])
                next_state_finished.append(program_line[1])
                current_pc += 4

            if opcode_name == 'sub':
                dest = self.model.getreg(program_line[1] + '_%d' %(index))
                dest_type = ptx_declaration[program_line[1]]
                dest_length = int(dest_type[2:])

                src0_str = program_line[2] 
                if src0_str in ptx_declaration.keys():
                    src0 = self.model.getreg(src0_str + '_%d' %(index))
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
                    src1 = self.model.getreg(src1_str + '_%d' %(index))
                    src1_type = ptx_declaration[src1_str]
                    src1_length = int(src1_type[2:])
                    if dest_length > src1_length:
                        src1 = ila.sign_extend(src1, dest_length)
                    elif dest_length < src1_length:
                        src1 = src1[(dest_length - 1) : 0]
                else:
                    src1 = ila.const(int(src1_str), dest_length)

                self.next_state_dict[program_line[1] + '_%d' %(index)] = ila.ite(self.pc_list[index] == current_pc, src0 - src1, self.next_state_dict[program_line[1] + '_%d' %(index)])
                next_state_finished.append(program_line[1])
                current_pc += 4

            if opcode_name == 'and':
                dest = self.model.getreg(program_line[1] + '_%d' %(index))
                dest_type = ptx_declaration[program_line[1]]
                dest_length = int(dest_type[2:])

                src0_str = program_line[2] 
                if src0_str in ptx_declaration.keys():
                    src0 = self.model.getreg(src0_str + '_%d' %(index))
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
                    src1 = self.model.getreg(src1_str + '_%d' %(index))
                    src1_type = ptx_declaration[src1_str]
                    src1_length = int(src1_type[2:])
                    if dest_length > src1_length:
                        src1 = ila.sign_extend(src1, dest_length)
                    elif dest_length < src1_length:
                        src1 = src1[(dest_length - 1) : 0]
                else:
                    src1_int = int(src1_str)
                    if src1_int < 0:
                        src1_int = -src1_int
                        src1_int = (1 << (instruction_format.REG_BITS - 1)) - src1_int + (1 << (instruction_format.REG_BITS - 1))
                    src1 = ila.const(src1_int, dest_length)

                self.next_state_dict[program_line[1] + '_%d' %(index)] = ila.ite(self.pc_list[index] == current_pc, src0 & src1, self.next_state_dict[program_line[1] + '_%d' %(index)])
                next_state_finished.append(program_line[1])
                current_pc += 4

            if opcode_name == 'add':
                dest = self.model.getreg(program_line[1] + '_%d' %(index))
                dest_type = ptx_declaration[program_line[1]]
                dest_length = int(dest_type[2:])

                src0_str = program_line[2] 
                if src0_str in ptx_declaration.keys():
                    src0 = self.model.getreg(src0_str + '_%d' %(index))
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
                    src1 = self.model.getreg(src1_str + '_%d' %(index))
                    src1_type = ptx_declaration[src1_str]
                    src1_length = int(src1_type[2:])
                    if dest_length > src1_length:
                        src1 = ila.sign_extend(src1, dest_length)
                    elif dest_length < src1_length:
                        src1 = src1[(dest_length - 1) : 0]
                else:
                    src1 = ila.const(int(src1_str), dest_length)

                self.next_state_dict[program_line[1] + '_%d' %(index)] = ila.ite(self.pc_list[index] == current_pc, src0 + src1, self.next_state_dict[program_line[1] + '_%d' %(index)])
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'mul':
                dest = self.model.getreg(program_line[1] + '_%d' %(index))
                dest_type = ptx_declaration[program_line[1]]
                dest_length = int(dest_type[2:])

                src0_str = program_line[2]
                if src0_str in ptx_declaration.keys():
                    src0 = self.model.getreg(src0_str + '_%d' %(index))
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
                    src1 = self.model.getreg(src1_str + '_%d' %(index))
                    src1_type = ptx_declaration[src1_str]
                    src1_length = int(src1_type[2:])
                    if dest_length > src1_length:
                        src1 = ila.sign_extend(src1, dest_length)
                    elif dest_length < src1_length:
                        src1 = src1[(dest_length - 1) : 0]
                else:
                    src1 = ila.const(int(src1_str), dest_length)

                self.next_state_dict[program_line[1] + '_%d' %(index)] = ila.ite(self.pc_list[index] == current_pc, src0 * src1, self.next_state_dict[program_line[1] + '_%d' %(index)])
                next_state_finished.append(program_line[1])
                current_pc += 4
            if opcode_name == 'st':
                current_pc += 4
            
            if current_pc == current_pc_in: #Just to find if there's any instruction not in the instruction-book
                print program_line

        #a = self.model.reg('support', 32)
        #self.model.set_next('support', self.model.getreg('s3') + self.model.getreg('s1'))
        for reg_name in ptx_declaration.keys():
            if reg_name not in next_state_finished:
                reg = self.model.getreg(reg_name + '_%d' %(index))
                self.model.set_next(reg_name + '_%d' %(index), reg)
        self.pc_max = current_pc
 
    def set_next_state(self):
        #reg
        for state_name in self.next_state_dict.keys():
            index = int(state_name[-1])
            self.model.set_next(state_name, self.next_state_dict[state_name])

    def set_next_pc(self, index):
        self.model.set_next('pc_%d' %(index) , ila.ite(self.pc_list[index] < (self.pc_max), self.pc_next_list[index], self.pc_list[index]))

    def add_assumptions(self):
        ptx_declaration_diff_obj = open('diff_read_only_regs', 'r')
        ptx_declaration_diff = pickle.load(ptx_declaration_diff_obj)
        ptx_declaration_shared_obj = open('shared_read_only_regs', 'r')
        ptx_declaration_shared = pickle.load(ptx_declaration_shared_obj)
        
        self.cond = self.model.bool(True)
        for index in range(self.thread_num):
            pc = self.model.getreg('pc_%d' %(index))
            self.cond = self.cond & (pc == self.model.const(0x0, instruction_format.PC_BITS))
        
        for reg_name in ptx_declaration_shared:
            reg0 = self.model.getreg(reg_name + '_%d' % (0))
            reg1 = self.model.getreg(reg_name + '_%d' % (1))
            self.cond = self.cond & (reg0 == reg1)

        for reg in ptx_declaration_diff:
            reg0 = self.model.getreg(reg + '_%d' %(0))
            reg1 = self.model.getreg(reg + '_%d' %(1))
            self.cond = self.cond & (reg0 != reg1)
        
        for reg in self.en_log_registers:
            self.cond = self.cond & (reg == 0)

        for reg in self.en_check_registers:
            self.cond = self.cond & (reg == 0)




 


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
        for index in range(self.thread_num):
            self.condition.append(self.pc_list[index] >= (self.pc_max)) 
        self.constrain = self.condition[0]
        for index in range(1, len(self.condition)):
            self.constrain = self.constrain & self.condition[index]
        self.implied = self.model.bool(True)
        for i in range(len(self.log_registers)):
            for j in range(len(self.check_registers)):
                log_reg = self.log_registers[i]
                en_log_reg = self.en_log_registers[i]
                check_reg = self.check_registers[j]
                en_check_reg = self.en_check_registers[j]
                self.implied = self.implied & ((log_reg != check_reg) | (en_check_reg == 0) | (en_log_reg == 0))

     #   self.implied = self.implied & (self.mem_list[0] == self.mem_list[1])
        self.imply = (~(self.constrain))  | (self.implied)

        self.predicate_bit = self.model.bit('predicate_bit')  
        #self.model.set_init('predicate_bit', self.model.bool(True))
        self.cond = self.cond & (self.predicate_bit == self.model.bool(True))
        self.model.set_next('predicate_bit', ila.ite(self.imply, self.predicate_bit, self.model.bool(False)))
        
    def aux_imm(self, operand_str, index):
        if operand_str in ptx_declaration.keys():
            operand = self.model.getreg(operand_str + '_%d' % (index))
            operand_type = ptx_declaration[operand_str]
            operand_length = int(operand_type[2:])
        else:
            operand_length = instruction_format.REG_BITS
            operand = self.model.const(int(operand_str), operand_length)
        return (operand, operand_length)
ptx = ptxGPUModel()
print ptx.model.bmcCond(ptx.predicate_bit == ila.bool(True), 20, ptx.cond)
#print ptx.model.bmcInit(ptx.predicate_bit == ila.bool(True), 28, True)
