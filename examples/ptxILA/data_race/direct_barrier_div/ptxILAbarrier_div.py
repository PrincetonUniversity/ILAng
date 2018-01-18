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
        #next state functions for monitors.
        self.bar_list = []
        self.createPC(0)
        self.createPC(1)
        
        self.createRegs(0)
        self.createRegs(1)
        self.createConst()
 
        self.generate_next_state(0)
        self.generate_next_state(1)

        self.bar_guarder_list = []
        self.bar_guarder_next_list = []
        self.set_bar_guarder(0)
        self.set_bar_guarder(1)
 

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
                op_preds = []
                if self.current_pc in self.pred_map.keys():
                    op_preds = self.pred_map[self.current_pc]
                conj_pred = ila.bool(True)
                for op_pred in op_preds:
                    if op_pred[0] == '-':
                        op_pred_name = op_pred[1:]
                        pred_cmp = self.pred_zero
                    else:
                        op_pred_name = op_pred
                        pred_cmp = self.pred_one
                    op_pred_reg = self.model.getreg(op_pred_name + '_%d' % (index))
                    conj_pred = conj_pred & (op_pred_reg == pred_cmp)
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
                ns = self.next_state_dict[dest_str + '_%d' % (index)]
                self.next_state_dict[dest_str + '_%d' % (index)] = ila.ite(self.pc_list[index] == self.current_pc, ila.ite(conj_pred, dest, ns), ns)
                self.current_pc += 4
                return 
            else:
                op_preds = []
                if self.current_pc in self.pred_map.keys():
                    op_preds = self.pred_map[self.current_pc]
                conj_pred0 = ila.bool(True)
                conj_pred1 = ila.bool(True)
                for op_pred in op_preds:
                    if op_pred[0] == '-':
                        op_pred_name = op_pred[1:]
                        pred_cmp = self.pred_zero
                    else:
                        op_pred_name = op_pred
                        pred_cmp = self.pred_one 
                    opcode_pred = self.model.getreg(op_pred_name + '_%d' % (0))
                    conj_pred0 = conj_pred0 & (opcode_pred == pred_cmp)
                    opcode_pred = self.model.getreg(op_pred_name + '_%d' % (1))
                    conj_pred1 = conj_pred1 & (opcode_pred == pred_cmp)
                
                target = pc_target[program_line[3]]
                if self.current_pc < target:
                    pc_jmp = ila.ite(conj_pred0 & conj_pred1, ila.const(target, instruction_format.PC_BITS), self.pc_list[index] + 4)
                    self.pc_next_list[index] = ila.ite(self.pc_list[index] == self.current_pc, pc_jmp, self.pc_next_list[index])
                else:
                    pc_jmp = ila.ite(conj_pred0 | conj_pred1, ila.const(target, instruction_format.PC_BITS), self.pc_list[index] + 4)
                    self.pc_next_list[index] = ila.ite(self.pc_list[index] == self.current_pc, pc_jmp, self.pc_next_list[index])

                self.current_pc += 4



            
 
    def generate_next_state(self, index):
        instruction_book_obj = open('instruction_book', 'r')
        instruction_book = instruction_book_obj.readlines()
        self.next_state_finished = []
        pc_target = {}
        self.current_pc = 0
        pred_map_obj = open('pred_flag_map', 'r')
        self.pred_map = pickle.load(pred_map_obj)
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

    def set_bar_guarder(self, index):
        self.bar_guarder_list.append(self.model.bit('bar_guarder_%d' % (index)))
        condition = ila.bool(False)
        for pc in self.bar_list:
            bar_preds = []
            if pc in self.pred_map.keys():
                bar_preds = self.pred_map[pc]
            bar_predicate = ila.bool(True)
            for bar_pred in bar_preds:
                if bar_pred[0] == '-':
                    bar_pred_name = bar_pred[1:]
                    bar_pred_cmp = self.pred_zero
                else:
                    bar_pred_name = bar_pred
                    bar_pred_cmp = self.pred_one
                bar_pred_reg = self.model.getreg(bar_pred_name + '_%d' % (index))
                bar_predicate = bar_predicate & (bar_pred_reg == bar_pred_cmp)
            condition = ((self.pc_list[index] == pc) & (bar_predicate)) | condition
        self.model.set_next('bar_guarder_%d' % (index), ila.ite(condition, ila.bool(True), ila.bool(False)))
 
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
        self.init = ila.bool(True) 
        for index in range(self.thread_num):
            pc = self.model.getreg('pc_%d' %(index))
            self.init = self.init & (pc == self.model.const(0x0, instruction_format.PC_BITS))
        i = 1
        for reg_name in ptx_declaration_shared:
            reg_type = ptx_declaration[reg_name]
            reg0 = self.model.getreg(reg_name + '_%d' % (0))
            reg1 = self.model.getreg(reg_name + '_%d' % (1))
            self.init = self.init & (reg0 == reg1)
            if int(reg_type[2:]) != instruction_format.LONG_REG_BITS:
                continue 
            self.init_max = self.model.const(i, instruction_format.LONG_REG_BITS) << 59
            self.init_range = self.model.const(1, instruction_format.LONG_REG_BITS) << 58
            self.init = self.init & (reg0 < self.init_max) & (reg0 > (self.init_max - self.init_range))
            i += 1

        for reg in ptx_declaration_diff:
            reg0 = self.model.getreg(reg + '_%d' %(0))
            reg1 = self.model.getreg(reg + '_%d' %(1))
            self.init = self.init & (reg0 != reg1) & (reg0 <= 128) & (reg0 >= 0) & (reg1 <= 128) & (reg1 >= 0)
        for reg in self.pred_registers:
            self.init = self.init & (reg == self.pred_one)
        
 
        #self.condition = []
        #for index in range(self.thread_num):
        #    self.condition.append(self.pc_list[index] >= (self.pc_max)) 
        #self.constrain = self.condition[0]
        #for index in range(1, len(self.condition)):
        #    self.constrain = self.constrain & self.condition[index]
        self.init = self.init & (self.bar_guarder_list[0] == ila.bool(True)) & (self.bar_guarder_list[1] == ila.bool(True))
        self.bar_diverge_check = self.model.bit('bar_diverge_check')
        self.model.set_next('bar_diverge_check', ila.ite(self.bar_guarder_list[0] ^ self.bar_guarder_list[1], ila.bool(True), self.bar_diverge_check))
        self.init = self.init & (self.bar_diverge_check == ila.bool(False))

     #   self.implied = self.implied & (self.mem_list[0] == self.mem_list[1])

        #self.model.set_init('predicate_bit', self.model.bool(True))
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
print ptx.model.bmcCond(ptx.bar_diverge_check == ila.bool(False), 40, ptx.init)
  
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
