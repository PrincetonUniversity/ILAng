import ila
import time
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
        self.bar_spec = barSpec()
        self.thread_num = 2
        self.createStates()
        self.add_assumptions()
        #self.ubar()
         
    def createStates(self):
        self.pc_list = []   #Two pc
        self.pc_next_list = []    #Two pc's next state function
        #self.imem_list = []
        self.next_state_dict = {}   #For next state function
        self.pred_registers = []    
        self.scalar_registers = []
        self.long_scalar_registers = []
        self.log_register = self.model.reg('log_register', instruction_format.LONG_REG_BITS)
        self.check_register = self.model.reg('check_register', instruction_format.LONG_REG_BITS)
        self.en_log_register = self.model.reg('en_log_register', 1)
        self.en_check_register = self.model.reg('en_check_register', 1)
        #next state functions for monitors.
        self.log_register_next = self.log_register
        self.en_log_register_next = self.en_log_register
        self.check_register_next = self.check_register
        self.en_check_register_next = self.en_check_register
        self.arb_fun_list = [self.model.fun('arb_fun_0', 1, []), self.model.fun('arb_fun_1', 1, [])]
        self.arb_list = [ila.appfun(self.arb_fun_list[0], []), ila.appfun(self.arb_fun_list[1], [])]
        self.bar_inst = []
        self.bar_list = []
        self.createPC(0)
        self.createPC(1)
        
        self.createRegs(0)
        self.createRegs(1)
        self.createConst()
        self.bar_state_list = []
 
        self.generate_next_state(0)
        self.generate_next_state(1)
 
        self.createLog()
        self.createCheck()

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
    def createConst(self):
        self.pred_one = ila.const(0x1, instruction_format.PRED_REG_BITS)
        self.pred_zero = ila.const(0x0, instruction_format.PRED_REG_BITS)
    
    def create_data_race_element(self, access_set, pred_map, log):
        if log == True:
            suffix = 'log'
            index = 0
        else:
            suffix = 'check'    
            index = 1 
        bar_pred_map_obj = open('bar_pred_map', 'r')
        bar_pred_map = pickle.load(bar_pred_map_obj)
        bar_pred_map_obj.close()
        self.log_clean = ila.bool(False)
        self.check_clean = ila.bool(False)
        for pc in self.bar_list:
            bar_pred_list = bar_pred_map[pc]
            bar_pred = ila.bool(True)
            for bar_pred_name in bar_pred_list:
                bar_pred_reg = self.model.getreg(bar_pred_name + '_%d' % (index))
                bar_pred = bar_pred & (bar_pred_reg == ila.const(0x0, 1))
            self.log_clean = self.log_clean | ((self.pc_list[index] == pc) & (bar_pred))
            self.check_clean = self.check_clean | ((self.pc_list[index] == pc) & (bar_pred))
            
        for pc in access_set.keys():
            reg_name = access_set[pc]
            operands = re.split('\+', reg_name)
            reg_len = 64
            for i in range(len(operands)):
                operand = operands[i]
                if operand in ptx_declaration.keys():
                    op_reg_type = ptx_declaration[operand]
                    op_reg_len = int(op_reg_type[2:])
                    if op_reg_len < reg_len:
                        operands[i] = ila.sign_extend(self.model.getreg(operand + '_%d' % (index)), reg_len)
                    else:
                        operands[i] = self.model.getreg(operand + '_%d' % (index))
                else:
                    operands[i] = ila.const(int(operand), reg_len)

            access_reg_next = operands[0]
            for i in range(1, len(operands)):
                access_reg_next = access_reg_next + operands[i]

            en_access_reg_next = ila.const(0x1, 1)
            en_access_reg_clear = ila.const(0x0, 1)
            pred_list = pred_map[pc]
            for pred in pred_list:
                pred_reg = self.model.getreg(pred + '_%d' % (index))
                en_access_reg_next = ila.ite(pred_reg == ila.const(0x0, 1), en_access_reg_next, en_access_reg_clear)
            #if log:
            #    self.model.set_next(reg_name + '_en_%s_%d' % (suffix, pc), ila.ite(self.pc_list[index] == pc, en_access_reg_next, ila.ite(self.log_clean, ila.const(0x0, 1), en_access_reg)))
            #else:
            #    self.model.set_next(reg_name + '_en_%s_%d' % (suffix, pc), ila.ite(self.pc_list[index] == pc, en_access_reg_next, ila.ite(self.check_clean, ila.const(0x0, 1), en_access_reg)))
 
            if log:
                self.log_register_next = ila.ite(self.pc_list[index] == pc, ila.ite(self.arb_list[index] == 1, access_reg_next, self.log_register_next), self.log_register_next)
                self.en_log_register_next = ila.ite(self.pc_list[index] == pc, ila.ite(self.arb_list[index] == 1, en_access_reg_next, self.en_log_register_next), self.en_log_register_next)
            else:
                self.check_register_next = ila.ite(self.pc_list[index] == pc, ila.ite(self.arb_list[index] == 1, access_reg_next, self.check_register_next), self.check_register_next)
                self.en_check_register_next = ila.ite(self.pc_list[index] == pc, ila.ite(self.arb_list[index] == 1, en_access_reg_next, self.en_check_register_next), self.en_check_register_next)
        if log:
            self.en_log_register_next = ila.ite(self.log_clean, ila.const(0x0, 1), self.en_log_register_next)
        else:
            self.en_check_register_next = ila.ite(self.check_clean, ila.const(0x0, 1), self.en_check_register_next)
 

 
 
 
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
        for pc in st_set.keys():
            ld_set[pc] = st_set[pc]
        self.create_data_race_element(ld_set, pred_map, True)

    def createCheck(self):
        st_set_file = 'st_set'
        st_set_obj = open(st_set_file, 'r')
        st_set = pickle.load(st_set_obj)
        st_set_obj.close()
        pred_map_file = 'pred_map'
        pred_map_obj = open(pred_map_file, 'r')
        pred_map = pickle.load(pred_map_obj)
        pred_map_obj.close()
        self.create_data_race_element(st_set, pred_map, False)

    def aux_dest(self, opcode, src_list, index):
        dest = None
        opcode_split = re.split('\.', opcode)
        opcode_name = opcode_split[0]
        if opcode_name == 'mov':
            dest = src_list[0]
        if opcode_name == 'and':
            dest = src_list[0] & src_list[1]
        if opcode_name == 'cvta':
            dest = src_list[0]
        if opcode_name == 'shr':
            dest = ila.ashr(src_list[0], src_list[1])
        if opcode_name == 'shl':
            dest = src_list[0] << src_list[1]
        if opcode_name == 'add':
            dest = src_list[0] + src_list[1]
        if opcode_name == 'sub':
            dest = src_list[0] - src_list[1]
        if opcode_name == 'mul':
            opcode_width = opcode_split[1]
            op_len = int(opcode_split[2][1:])
            if opcode_width == 'wide':
                src0 = ila.sign_extend(src_list[0], op_len * 2)
                src1 = ila.sign_extend(src_list[1], op_len * 2)
                dest = src0 * src1
            elif opcode_width == 'lo':
                src0 = ila.sign_extend(src_list[0], op_len * 2)
                src1 = ila.sign_extend(src_list[1], op_len * 2)
                dest_long = src0 * src1
                dest = dest_long[(op_len - 1):0]

        if opcode_name == 'setp':
            opcode_cmp = opcode_split[1]
            if opcode_cmp == 'ne':
                dest = ila.ite(src_list[0] != src_list[1], self.pred_one, self.pred_zero)
            if opcode_cmp == 'gt':
                dest = ila.ite(src_list[0] > src_list[1], self.pred_one, self.pred_zero)
            if opcode_cmp == 'lt':
                dest = ila.ite(src_list[0] < src_list[1], self.pred_one, self.pred_zero)
        if opcode_name == 'bar':
            self.bar_inst[index] = self.bar_inst[index] | (self.pc_list[index] == self.current_pc)
            if self.current_pc not in self.bar_list:
                self.bar_list.append(self.current_pc)
            #TODO: pc_next when bar
            
        return dest

    def adjust_dest(self, index, dest, dest_str, op_len):
        dest_type = ptx_declaration[dest_str]
        if dest_type == '.pred':
            return dest
        else:
            dest_len = int(dest_type[2:])
            if dest_len > op_len:
                return ila.sign_extend(dest, dest_len)
            elif dest_len < op_len:
                return dest[(dest_len - 1) : 0]
            else:
                return dest

             


    def perform_instruction(self, index, program_line, pc_target):
            if len(program_line) < 2:
                return
            opcode = program_line[0]
            opcode_split = re.split('\.', opcode)
            opcode_name = opcode_split[0]
            if opcode_name != '@':
                self.next_state_finished.append(program_line[1])
                if opcode_name == 'bar':
                    op_len = 0
                else:
                    op_len = int(opcode_split[-1][1:])
                src_list = []
                for i in range(2, len(program_line)):
                    src_str = program_line[i]
                    src_components = re.split('\+', src_str)
                    for i in range(len(src_components)):
                        src_component = src_components[i]
                        src_components[i] = self.aux_imm(src_component, index, op_len)
                    src_sum = src_components[0]
                    for i in range(1, len(src_components)):
                        src_sum = src_sum + src_components[0]
                    src_list.append(src_sum)
                dest = self.aux_dest(program_line[0], src_list, index)
                if not dest:
                    self.current_pc += 4
                    return
                dest_str = program_line[1]
                dest = self.adjust_dest(index, dest, dest_str, op_len)
                self.next_state_dict[dest_str + '_%d' % (index)] = ila.ite(self.pc_list[index] == self.current_pc, dest, self.next_state_dict[dest_str + '_%d' % (index)])
                self.current_pc += 4
                return 
            else:
                opcode_pred_name = program_line[1]
                opcode_pred = self.model.getreg(opcode_pred_name + '_%d' % (index))
                opcode_jmp_dest = program_line[3]
                opcode_jmp_target = pc_target[opcode_jmp_dest]
                pc_jmp = ila.ite(opcode_pred == 1, ila.const(opcode_jmp_target, instruction_format.PC_BITS), self.pc_list[index] + 4)
                self.pc_next_list[index] = ila.ite(self.pc_list[index] == self.current_pc, pc_jmp, self.pc_next_list[index])
                self.current_pc += 4



            
 
    def generate_next_state(self, index):
        instruction_book_obj = open('instruction_book', 'r')
        instruction_book = instruction_book_obj.readlines()
        self.next_state_finished = []
        pc_target = {}
        self.current_pc = 0
        self.bar_inst.append(ila.bool(False))
        for program_line in program:
            if len(program_line) < 2:
                if len(program_line) == 0:
                    continue
                if program_line[0][-1] == ':':
                    pc_target[program_line[0][:-1]] = self.current_pc 
            else:
                self.current_pc += 4
        #print pc_target
        self.current_pc = 0
        for program_line in program:
            current_pc_in = self.current_pc
            self.perform_instruction(index, program_line, pc_target)
            if self.current_pc == current_pc_in: #Just to find if there's any instruction not in the instruction-book
                print program_line

        for reg_name in ptx_declaration.keys():
            if reg_name not in self.next_state_finished:
                #print reg_name
                reg = self.model.getreg(reg_name + '_%d' %(index))
                self.model.set_next(reg_name + '_%d' %(index), reg)
        self.pc_max = self.current_pc
 
    def set_next_state(self):
        #reg
        for state_name in self.next_state_dict.keys():
            index = int(state_name[-1])
            self.model.set_next(state_name, self.next_state_dict[state_name])
        print self.en_log_register_next
        self.model.set_next('log_register', self.log_register_next)
        self.model.set_next('check_register', self.check_register_next)
        self.model.set_next('en_log_register', self.en_log_register_next)
        self.model.set_next('en_check_register', self.en_check_register_next)

    def set_next_pc(self, index):
        self.model.set_next('pc_%d' %(index) , ila.ite(self.pc_list[index] < (self.pc_max), self.pc_next_list[index], self.pc_list[index]))
    
    def add_assumptions(self):
        ptx_declaration_diff_obj = open('diff_read_only_regs', 'r')
        ptx_declaration_diff = pickle.load(ptx_declaration_diff_obj)
        ptx_declaration_shared_obj = open('shared_read_only_regs', 'r')
        ptx_declaration_shared = pickle.load(ptx_declaration_shared_obj)
        self.init = ila.bool(True) 
        for index in range(self.thread_num):
            pc = self.model.getreg('pc_%d' %(index))
            self.init = self.init & (pc == self.model.const(0x0, instruction_format.PC_BITS))
        i = 1
        for reg_name in ptx_declaration_shared:
            reg0 = self.model.getreg(reg_name + '_%d' % (0))
            reg1 = self.model.getreg(reg_name + '_%d' % (1))
            self.init = self.init & (reg0 == reg1)
            operand_type = ptx_declaration[reg_name]
            operand_len = int(operand_type[2:])
            if operand_len < 64:
                continue
            self.init_max = self.model.const(i, instruction_format.LONG_REG_BITS) << 59
            self.init_range = self.model.const(1, instruction_format.LONG_REG_BITS) << 58
            self.init = self.init & (reg0 < self.init_max) & (reg0 > (self.init_max - self.init_range))
            i += 1

        for reg in ptx_declaration_diff:
            reg0 = self.model.getreg(reg + '_%d' %(0))
            reg1 = self.model.getreg(reg + '_%d' %(1))
            self.init = self.init & (reg0 != reg1) & (reg0 <= 128) & (reg0 >= 0) & (reg1 <= 128) & (reg1 >= 0)
        
        self.init = self.init & (self.en_log_register == 0) & (self.en_check_register == 0)

        bar_pred_map_obj = open('bar_pred_map', 'r')
        bar_pred_map = pickle.load(bar_pred_map_obj)
        bar_pred_map_obj.close()
        self.check_point = ila.bool(False)
        for pc in self.bar_list:
            bar_pred_list = bar_pred_map[pc]
            bar_pred = ila.bool(True)
            for bar_pred_name in bar_pred_list:
                bar_pred_reg = self.model.getreg(bar_pred_name + '_%d' % (0))
                bar_pred = bar_pred & (bar_pred_reg == ila.const(0x0, 1))
 
        #self.condition = []
        #for index in range(self.thread_num):
        #    self.condition.append(self.pc_list[index] >= (self.pc_max)) 
        #self.constrain = self.condition[0]
        #for index in range(1, len(self.condition)):
        #    self.constrain = self.constrain & self.condition[index]
        self.imply = (self.check_register == self.log_register) & (self.en_log_register == 1) & (self.en_check_register == 1)

     #   self.implied = self.implied & (self.mem_list[0] == self.mem_list[1])

        self.predicate_bit = self.model.bit('predicate_bit')  
        #self.model.set_init('predicate_bit', self.model.bool(True))
        self.init = self.init & (self.predicate_bit == self.model.bool(True))
        self.model.set_next('predicate_bit', ila.ite(self.imply, self.model.bool(False), self.predicate_bit))
#        self.a = self.model.reg('a', 1)
#        self.b = self.model.reg('b', 1)
#        self.model.set_next('a', ila.ite(self.pc_list[0] == 4, self.arb, self.a))
#        self.model.set_next('b', ila.ite(self.pc_list[0] == 8, self.arb, self.b))
#        self.test = ila.ite(self.pc_list[0] > 8, self.a == self.b, ila.bool(True)) 
        
    def aux_imm(self, operand_str, index, op_len):
        if operand_str in ptx_declaration.keys():
            operand = self.model.getreg(operand_str + '_%d' % (index))
            operand_type = ptx_declaration[operand_str]
            if operand_type == '.pred':
                operand_length = instruction_format.PRED_REG_BITS
            else: 
                operand_length = int(operand_type[2:])
            if operand_length < op_len:
                return ila.sign_extend(operand, op_len)
            elif operand_length > op_len:
                return operand[(op_len - 1) : 0]
            else:
                return operand
        else:
            operand_int = int(operand_str)
            #print operand_int
            if operand_int < 0:
                operand_int = -operand_int
                operand_int = (1 << (op_len - 1)) - operand_int + (1 << (op_len - 1))
            #print operand_int
            operand = self.model.const(operand_int, op_len)
            return operand
ptx = ptxGPUModel()
time_consumption = []
result = []
print ptx.model.bmcCond(ptx.predicate_bit == ila.bool(True), 20, ptx.init)
  
#for i in range(1, 30):
#    start = time.clock()
#    ptx.model.bmcCond(ptx.predicate_bit == ila.bool(True), i, ptx.init)
#    end = time.clock()
#    time_consumption.append(end - start)
#    r = ptx.model.bmcCond(ptx.predicate_bit == ila.bool(True), i, ptx.init)
#    result.append(r)
#print time_consumption
#print result   

#print ptx.model.bmcInit(ptx.predicate_bit == ila.bool(True), 28, True)
