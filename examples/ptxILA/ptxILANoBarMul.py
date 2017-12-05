import ila
import pickle
import Instruction_Format

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
reg_map_file = "reg_map"
mem_map_file = "mem_map"
reg_book_file = "reg_book"
long_int_reg_book_file = 'long_int_reg_book'
mem_book_file = "mem_book"
reg_source_obj = open(reg_source_file, 'r')
mem_source_obj = open(mem_source_file, 'r')
mem_map_obj = open(mem_map_file, 'r')
[reg_state_type_name_dict, reg_state_type_length_dict] = pickle.load(reg_source_obj)
[mem_state_type_name_dict, mem_state_type_length_dict, mem_state_size_dict] = pickle.load(mem_source_obj)
[mem_map, max_addr_size] = pickle.load(mem_map_obj)
reg_state_list = reg_state_type_name_dict.keys()
mem_state_list = mem_state_type_name_dict.keys()

class ptxGPUModel(object):
    def __init__(self):
        self.model = ila.Abstraction('GPU_ptx')
        self.program_name = 'test.ptx'
        self.createStates()
        #self.ubar()
        self.assumptions()
         
    def createStates(self):
        self.createPC()
        self.createRegs()
        self.createMems()
        #self.createuBar()
        self.instructionFetch()
        self.instructionDecode()
        #self.addInstruction()

    def createPC(self):
        self.pc = self.model.reg('pc', instruction_format.PC_BITS)

    def createRegs(self):
        self.scalar_registers = []
        self.long_scalar_registers = []
        reg_book_obj = open(reg_book_file)
        reg_book = pickle.load(reg_book_obj)
        long_int_reg_book_obj = open(long_int_reg_book_file, 'r')
        long_int_reg_book = pickle.load(long_int_reg_book_obj) 
        #Here's something to be cleaned up in future.
        #These 3 states are needed for ptxSim, 
        #but here we have to remove them,
        #because the length of these regs are not as general regs.
        reg_book.remove('bar_state')
        reg_book.remove('bar_counter_enter') 
        reg_book.remove('bar_counter_exit')
        for reg_name in reg_book :
            self.scalar_registers.append(self.model.reg(reg_name, instruction_format.REG_BITS))			
        for reg_name in long_int_reg_book:
            self.long_scalar_registers.append(self.model.reg(reg_name, instruction_format.LONG_REG_BITS))
        self.scalar_register_flag = self.model.bool(True)
        self.long_scalar_register_flag = self.model.bool(False)
        self.scalar_register_num = len(self.scalar_registers)
        self.long_scalar_register_num = len(self.long_scalar_registers)
        self.register_total_num = self.scalar_register_num + self.long_scalar_register_num

    def createMems(self):
        self.mem = self.model.mem('mem', instruction_format.MEM_ADDRESS_BITS, instruction_format.MEM_BITS)
        self.dmem = self.model.mem('dmem', instruction_format.MEM_ADDRESS_BITS, instruction_format.MEM_ADDRESS_BITS)
    '''
    def createuBar(self):
        bar_spec = barSpec()
        self.bar_state = self.model.reg('bar_state', bar_spec.BAR_STATE_BITS)
        #self.bar_counter_enter = self.model.reg('bar_counter_enter', bar_spec.BAR_COUNTER_ENTER_BITS)
        #self.bar_counter_exit = self.model.reg('bar_counter_exit', bar_spec.BAR_COUNTER_EXIT_BITS)
        #self.bar_state = self.model.getreg('bar_state')
        #self.bar_counter_enter = self.model.getreg('bar_counter_enter')
        #self.bar_counter_exit = self.model.getreg('bar_counter_exit')
        #self.model.set_next('bar_counter_enter', self.bar_counter_enter)
        #self.model.set_next('bar_counter_exit', self.bar_counter_exit)
        instruction_map_file = 'instruction_map'
        instruction_map_obj = open(instruction_map_file, 'r')
        instruction_map = pickle.load(instruction_map_obj)
        self.bar_counter_enter = self.model.reg('bar_counter_enter', bar_spec.BAR_COUNTER_ENTER_BITS)
        self.bar_counter_exit = self.model.reg('bar_counter_exit', bar_spec.BAR_COUNTER_EXIT_BITS)
        #bar_counter_enter = self.model.getreg('bar_counter_enter')
        #bar_counter_exit = self.model.getreg('bar_counter_exit')
        self.bar_counter_max = bar_spec.THREAD_NUM  # need cleanup
        #bar_state_next = ila.ite(bar_state == bar_spec.bar_enter, ila.ite(bar_counter_exit != 0, bar_spec.bar_enter, ila.ite(bar_counter_enter == (bar_counter_max - 1), bar_spec.bar_exit, bar_wait)), ila.ite(bar_state == bar_spec.bar_wait, ila.ite(bar_counter_enter == bar_counter_max, bar_spec.bar_exit, bar_spec.bar_wait), ila.ite(bar_state == bar_spec.bar_exit, bar_spec.bar_finish , bar_state)))
        #bar_counter_enter_next = ila.ite(bar_state == bar_spec.bar_enter, ila.ite(bar_counter_exit != 0, bar_counter_enter, bar_counter_enter + 1), ila.ite((bar_state == bar_spec.bar_exit) & (bar_counter_exit == 1), ila.const(0x0, bar_spec.bar_counter_enter_bits), bar_counter_enter))
        #bar_counter_exit_next = ila.ite((bar_state == bar_spec.bar_enter) & (counter_enter == (bar_counter_max - 1)), bar_counter_max, ila.ite(bar_state == bar_spec.bar_exit, bar_counter_exit - 1, bar_counter_exit))
        bar_state_next = ila.choice('bar_state_next', [ila.const(i, bar_spec.BAR_STATE_BITS) for i in range(0, 5)])
        self.bar_counter_enter_next = ila.choice('bar_counter_enter_next', [self.bar_counter_enter, self.bar_counter_enter + 1, ila.const(0x0, bar_spec.BAR_COUNTER_ENTER_BITS)])
        self.bar_counter_exit_next = ila.choice('bar_counter_exit_next', [self.bar_counter_exit, self.bar_counter_exit - 1, ila.const(self.bar_counter_max, bar_spec.BAR_COUNTER_EXIT_BITS)])
        self.model.set_next('bar_state', bar_state_next)
        self.model.set_next('bar_counter_enter', self.bar_counter_enter_next)
        self.model.set_next('bar_counter_exit', self.bar_counter_exit_next)
        self.bar_decode_list = [(self.bar_state == bar_spec.BAR_ENTER) & (self.bar_counter_exit != 0),\
                           (self.bar_state == bar_spec.BAR_ENTER) & (self.bar_counter_exit == 0) & (self.bar_counter_enter == (self.bar_counter_max - 1)),\
                           (self.bar_state == bar_spec.BAR_ENTER) & (self.bar_counter_exit == 0) & (self.bar_counter_enter != (self.bar_counter_max - 1)),\
                           (self.bar_state == bar_spec.BAR_WAIT) & (self.bar_counter_enter != self.bar_counter_max),\
                           (self.bar_state == bar_spec.BAR_WAIT) & (self.bar_counter_enter == self.bar_counter_max),\
                           (self.bar_state == bar_spec.BAR_EXIT) & (self.bar_counter_exit > 1),\
                           (self.bar_state == bar_spec.BAR_EXIT) & (self.bar_counter_exit == 1),\
                           (self.bar_state == bar_spec.BAR_EXIT) & (self.bar_counter_exit == 0)]
    '''
    def instructionFetch(self):
        self.inst = ila.load(self.mem, ila.zero_extend(self.pc[31:3], instruction_format.MEM_ADDRESS_BITS))
        self.opcode = self.inst[(instruction_format.OPCODE_BIT_TOP - 1): instruction_format.OPCODE_BIT_BOT]
        self.fetch_expr = self.inst
        self.dest = self.inst[(instruction_format.DST_BIT_TOP - 1): instruction_format.DST_BIT_BOT]
        self.src1 = self.inst[(instruction_format.SRC0_BIT_TOP - 1): instruction_format.SRC0_BIT_BOT]
        self.src2 = self.inst[(instruction_format.SRC1_BIT_TOP - 1): instruction_format.SRC1_BIT_BOT]
        self.src3 = self.inst[(instruction_format.SRC2_BIT_TOP - 1): instruction_format.SRC2_BIT_BOT]
        self.baseImm = ila.sign_extend(self.inst[(instruction_format.BASE_BIT_TOP-1): instruction_format.BASE_BIT_BOT], instruction_format.PC_BITS)
        #self.branchPred = self.dest
        #(self.predReg, self.predReg_flag) = self.indexIntoReg(self.branchPred)
        self.branchImm = ila.zero_extend(self.inst[(instruction_format.IMM_BIT_TOP - 1) : instruction_format.IMM_BIT_BOT], instruction_format.PC_BITS)
        self.ldImm = ila.zero_extend(self.inst[(instruction_format.IMM_BIT_TOP - 1) : instruction_format.IMM_BIT_BOT], instruction_format.PC_BITS)
        self.stImm = ila.zero_extend(self.inst[(instruction_format.IMM_BIT_TOP - 1) : instruction_format.IMM_BIT_BOT], instruction_format.PC_BITS)
        
        self.sreg1_flag = ila.ite((self.src1 >= self.scalar_register_num) & (self.src1 < self.register_total_num), self.long_scalar_register_flag, self.scalar_register_flag)
        self.sreg2_flag = ila.ite((self.src2 >= self.scalar_register_num) & (self.src2 < self.register_total_num), self.long_scalar_register_flag, self.scalar_register_flag)
        self.sreg3_flag = ila.ite((self.src3 >= self.scalar_register_num) & (self.src3 < self.register_total_num), self.long_scalar_register_flag, self.scalar_register_flag)
        self.sregdest_flag = ila.ite((self.dest >= self.scalar_register_num) & (self.dest < self.register_total_num), self.long_scalar_register_flag, self.scalar_register_flag)
        
        self.ssreg1 = self.indexIntoSReg(self.src1)
        self.ssreg2 = self.indexIntoSReg(self.src2)
        self.ssreg3 = self.indexIntoSReg(self.src3)
        self.ssregdest = self.indexIntoSReg(self.dest)
        
        self.lsreg1 = self.indexIntoLReg(self.src1)
        self.lsreg2 = self.indexIntoLReg(self.src2)
        self.lsreg3 = self.indexIntoLReg(self.src3)
        self.lsregdest = self.indexIntoLReg(self.dest)
        self.sreg1 = ila.ite(self.sreg1_flag, self.ssreg1, self.lsreg1[instruction_format.REG_BITS - 1:0])
        self.sreg2 = ila.ite(self.sreg2_flag, self.ssreg2, self.lsreg2[instruction_format.REG_BITS - 1:0])
        self.sreg3 = ila.ite(self.sreg3_flag, self.ssreg3, self.lsreg3[instruction_format.REG_BITS - 1:0])
        self.sregdest = ila.ite(self.sregdest_flag, self.ssregdest, self.lsregdest[instruction_format.REG_BITS - 1:0])

    
    def instructionDecode(self):
        instruction_map_file = 'instruction_map'
        instruction_map_obj = open(instruction_map_file, 'r')
        instruction_map = pickle.load(instruction_map_obj)
        bar_spec = barSpec()
        #ALUInstructions = [(self.opcode == instruction_map['add']), (self.opcode == instruction_map['sub']),(self.opcode == instruction_map['mul.lo']), ((self.opcode == instruction_map['bra']) & (self.predReg != 0) & (self.baseImm != 0)), ((self.opcode == instruction_map['bra']) & (self.baseImm == 0)), (self.opcode == instruction_map['ld'])] 
        ALUInstructions = [(self.opcode == instruction_map['mul.wide'])]
        #ALUInstructions = [(self.opcode == instruction_map['mov']), (self.opcode == instruction_map['ld']), (self.opcode == instruction_map['st']), (self.opcode == instruction_map['add']), (self.opcode == instruction_map['sub']), (self.opcode == instruction_map['mul.lo'])]
        #ALUInstructions = [(self.opcode == instruction_map['st'])]
        #ALUInstructions = [(self.opcode == instruction_map['ld'])]
        #ALUInstructions = [(self.opcode == instruction_map['add']), (self.opcode == instruction_map['sub']),(self.opcode == instruction_map['mul.lo']), ((self.opcode == instruction_map['bra']) & (self.predReg != 0) & (self.baseImm != 0)), ((self.opcode == instruction_map['bra']) & (self.baseImm == 0)), (self.opcode != instruction_map['add']) & (self.opcode != instruction_map['sub']) & (self.opcode != instruction_map['mul.lo']) & ((self.opcode != instruction_map['bra']) | (self.predReg == 0) | (self.baseImm == 0))&((self.opcode != instruction_map['bra']) | (self.baseImm != 0)) ]
        decodeList = ALUInstructions
        #decodeList = ALUInstructions + [(self.opcode == instruction_map['bar']) & (self.bar_state == bar_spec.BAR_INIT), (self.opcode == instruction_map['bar']) & (self.bar_state == bar_spec.BAR_FINISH)]
        #decodeList = [(self.opcode == instruction_map['bar']) & (self.bar_state == bar_spec.BAR_INIT), (self.opcode == instruction_map['bar']) & (self.bar_state == bar_spec.BAR_FINISH)]
        #for bdl in self.bar_decode_list:
        #    decodeList.append((self.opcode == instruction_map['bar']) & bdl)
        #for dl in decodeList:
        #    print dl
        self.model.decode_exprs = decodeList
        #self.bar_state_next = ila.ite((self.opcode == instruction_map['bar']) & (self.bar_state == bar_spec.BAR_INIT), ila.const(1, bar_spec.BAR_STATE_BITS) ila.ite(self.bar_state == bar_spec.BAR_FINISH, bar_spec.BAR_INIT, self.bar_state)) #non-synthesize bar instruction
    def assumptions(self):#assumption for st instruction
        instruction_map_file = 'instruction_map'
        instruction_map_obj = open(instruction_map_file, 'r')
        instruction_map = pickle.load(instruction_map_obj)
        self.model.add_assumption(self.stImm >= ila.const(0x0, instruction_format.IMM_BIT_TOP - instruction_format.IMM_BIT_BOT))
        self.model.add_assumption(self.stImm < ila.const(max_addr_size / 4, instruction_format.IMM_BIT_TOP - instruction_format.IMM_BIT_BOT))
        #self.model.add_assumption((self.opcode == instruction_map['mul.lo']) | ((self.sreg1_flag == self.scalar_register_flag) & (self.sreg2_flag == self.scalar_register_flag) & (self.sregdest_flag == self.scalar_register_flag)))
        self.model.add_assumption((self.opcode == instruction_map['mul.wide']) | ((self.sreg1_flag == self.scalar_register_flag) & (self.sreg2_flag == self.scalar_register_flag) & (self.sregdest_flag == self.long_scalar_register_flag)))
    #def assumptions(self): #assumption for ld instruction 
        #self.model.add_assumption((self.ldImm >= ila.const(0x0, instruction_format.IMM_BIT_TOP - instruction_format.IMM_BIT_BOT)))
        #self.model.add_assumption((self.ldImm < ila.const(max_addr_size / 4, instruction_format.IMM_BIT_TOP - instruction_format.IMM_BIT_BOT)))

    '''
    #Sync for bar instruction
    def assumptions(self):
        instruction_map_file = 'instruction_map'
        instruction_map_obj = open(instruction_map_file, 'r')
        instruction_map = pickle.load(instruction_map_obj)
        bar_spec = barSpec()
        self.model.add_assumption((self.opcode == instruction_map['bar']) & (self.bar_state >= bar_spec.BAR_INIT) & (self.bar_state <= bar_spec.BAR_FINISH) & (self.bar_counter_enter <= bar_spec.THREAD_NUM) & (self.bar_counter_exit >= 0) & (self.bar_counter_enter >= 0) & (self.bar_counter_exit <= bar_spec.THREAD_NUM)) #& ((self.bar_state == bar_spec.BAR_INIT) | (self.bar_state == bar_spec.BAR_FINISH) ))
        #self.u_bar_model.add_assumption((self.opcode == instruction_map['bar']) & (self.bar_state > bar_spec.BAR_INIT) & (self.bar_state < bar_spec.BAR_FINISH))
    '''

    def pc_nxt(self):
        self.pcPlus4 = self.pc + ila.const(0b100, instruction_format.PC_BITS)
        self.branchPC = self.pcPlus4 + self.branchImm
        return ila.choice("pc_nxt", [self.pc ,self.pcPlus4, self.branchPC])

    def sreg_nxt(self, regNo):
        return ila.ite(self.dest == regNo, ila.choice(str(regNo) + "_nxt", [self.sreg1 + self.sreg2, self.sreg1 - self.sreg2, self.sreg1 * self.sreg2, self.dmem[self.ldImm << 0x2], self.sreg1, self.scalar_registers[regNo]]),self.scalar_registers[regNo])
#        return ila.choice(str(regNo) + "_nxt", [self.sreg1 + self.sreg2, self.sreg1 - self.sreg2, self.sreg1 * self.sreg2, self.sregdest ,self.scalar_registers[regNo]])

    def lreg_nxt(self, regNo):
        return ila.ite(self.dest == (regNo + len(self.scalar_registers)), ila.choice(str(regNo) + '_lnxt', [ila.sign_extend(self.sreg1 + self.sreg2, instruction_format.LONG_REG_BITS), ila.sign_extend(self.sreg1 - self.sreg2, instruction_format.LONG_REG_BITS), ila.sign_extend(self.sreg1 * self.sreg2, instruction_format.LONG_REG_BITS), ila.sign_extend(self.dmem[self.ldImm << 0x2], instruction_format.LONG_REG_BITS), ila.sign_extend(self.sreg1, instruction_format.LONG_REG_BITS), self.long_scalar_registers[regNo]]), self.long_scalar_registers[regNo])
   
    def mem_nxt(self):
        return self.mem 
    
    def dmem_nxt(self):
        self.st_addr = self.stImm << 0x2 
        self.store_value = self.sregdest 
        return ila.choice('dmem_nxt', [self.dmem, ila.store(self.dmem, self.st_addr, self.store_value)])

    def indexIntoSReg(self, idx):
        expr = self.scalar_registers[0]
        for i in range(len(self.scalar_registers)):
            expr = ila.ite(idx == i, self.scalar_registers[i], expr)
        return expr

    def indexIntoLReg(self, idx):
        expr = self.long_scalar_registers[0]
        for i in range(len(self.long_scalar_registers)):
            expr = ila.ite(idx == (i + self.scalar_register_num), self.long_scalar_registers[i], expr)
        return expr

    def compare(self):
        #next_1 = self.model.get_next('%r4')
        #next_2 = self.ptxSample('%r4')
        next_1 = self.model.get_next('%rd0')
        next_2 = self.ptxSample()
        if not self.model.areEqual(next_1, next_2):
            print 'not equal'
        else:
            print 'equal'

    '''
    def ptxSample(self):
        instruction_map_file = 'instruction_map'
        instruction_map_obj = open(instruction_map_file, 'r')
        instruction_map = pickle.load(instruction_map_obj)
        return ila.ite(self.dest == 0, ila.ite(self.opcode == instruction_map['mov'], self.sreg1, ila.ite(self.opcode == instruction_map['ld'], self.dmem[self.ldImm << 0x2], ila.ite(self.opcode == instruction_map['add'], self.sreg1 + self.sreg2, ila.ite(self.opcode == instruction_map['sub'], self.sreg1 - self.sreg2,  self.scalar_registers[0])))) ,self.scalar_registers[0])
    '''
    '''
    def ptxSample(self):
        instruction_map_file = 'instruction_map'
        instruction_map_obj = open(instruction_map_file, 'r')
        instruction_map = pickle.load(instruction_map_obj)
        return ila.ite(self.dest == 0, ila.ite(self.opcode == instruction_map['mul.wide'], self.sreg1 * self.sreg2, self.scalar_registers[0]), self.scalar_registers[0])
    '''

    def ptxSample(self):
        instruction_map_file = 'instruction_map'
        instruction_map_obj = open(instruction_map_file, 'r')
        instruction_map = pickle.load(instruction_map_obj)
        self.mlsreg1 = ila.sign_extend(self.sreg1, instruction_format.LONG_REG_BITS)
        self.mlsreg2 = ila.sign_extend(self.sreg2, instruction_format.LONG_REG_BITS)
        self.mldestreg = ila.sign_extend(self.sreg1 * self.sreg2, instruction_format.LONG_REG_BITS)
        return ila.ite(self.dest == len(self.scalar_registers), ila.ite(self.opcode == instruction_map['mul.wide'], self.mldestreg, self.long_scalar_registers[0]), self.long_scalar_registers[0])
    

    '''
    #ptxSample to st
    def ptxSample(self):
        instruction_map_file = 'instruction_map'
        instruction_map_obj = open(instruction_map_file, 'r')
        instruction_map = pickle.load(instruction_map_obj)
        return ila.ite(self.opcode == instruction_map['st'], ila.store(self.dmem, self.st_addr, self.store_value), self.dmem)
    '''

    #ptxSample for ld
    '''
    def ptxSample(self, t_reg):
        instruction_map_file = 'instruction_map'
        instruction_map_obj = open(instruction_map_file, 'r')
        instruction_map = pickle.load(instruction_map_obj)
        reg_map_obj = open(reg_map_file, 'r')
        reg_map = pickle.load(reg_map_obj)
        return ila.ite(self.opcode == instruction_map['ld'], ila.ite(self.dest == 0, (self.dmem[self.ldImm << 0x2 ]), self.scalar_registers[0]), self.scalar_registers[0])
    '''

    '''
        #ptxSample for bar_counter_exit
    def ptxSample(self):
        bar_spec = barSpec()
        return ila.ite(self.opcode == 71,\
        ila.ite(self.bar_state == bar_spec.BAR_INIT, self.bar_counter_exit,\
        ila.ite(self.bar_state == bar_spec.BAR_FINISH, self.bar_counter_exit,\
        ila.ite(self.bar_state == bar_spec.BAR_ENTER, ila.ite(self.bar_counter_exit == 0, ila.ite(self.bar_counter_enter == (self.bar_counter_max - 1), ila.const(self.bar_counter_max, bar_spec.BAR_COUNTER_EXIT_BITS), self.bar_counter_exit), self.bar_counter_exit),\
        ila.ite(self.bar_state == bar_spec.BAR_WAIT, self.bar_counter_exit,\
        ila.ite(self.bar_state == bar_spec.BAR_EXIT, ila.ite(self.bar_counter_exit != 0, self.bar_counter_exit - 1, self.bar_counter_exit - 1), self.bar_counter_exit))))),\
        self.bar_counter_exit)
    ''' 

    '''
    #ptxSample for bar_counter_enter 
    def ptxSample(self):
        bar_spec = barSpec()
        return ila.ite(self.opcode == 71, \
        ila.ite(self.bar_state == bar_spec.BAR_INIT, self.bar_counter_enter, \
        ila.ite(self.bar_state == bar_spec.BAR_FINISH, self.bar_counter_enter,\
        ila.ite(self.bar_state == bar_spec.BAR_ENTER, ila.ite(self.bar_counter_exit == 0, self.bar_counter_enter + 1, self.bar_counter_enter),\
        ila.ite(self.bar_state == bar_spec.BAR_WAIT, self.bar_counter_enter, \
        ila.ite(self.bar_state == bar_spec.BAR_EXIT, ila.ite(self.bar_counter_exit == 1, ila.const(0x0, bar_spec.BAR_COUNTER_ENTER_BITS), self.bar_counter_enter), self.bar_counter_enter))))), \
        self.bar_counter_enter)
    '''
    '''
    #ptxSample for bar_state
    def ptxSample(self):
        bar_spec = barSpec()
        return ila.ite(self.opcode == 71, ila.ite(self.bar_state == bar_spec.BAR_FINISH, ila.const(bar_spec.BAR_INIT, bar_spec.BAR_STATE_BITS),\
         ila.ite(self.bar_state == bar_spec.BAR_INIT, ila.const(bar_spec.BAR_ENTER, bar_spec.BAR_STATE_BITS),\
         ila.ite(self.bar_state == bar_spec.BAR_ENTER, ila.ite(self.bar_counter_exit != 0, self.bar_state,\
         ila.ite(self.bar_counter_enter == (self.bar_counter_max - 1), ila.const(bar_spec.BAR_EXIT, bar_spec.BAR_STATE_BITS), ila.const(bar_spec.BAR_WAIT, bar_spec.BAR_STATE_BITS))),\
         ila.ite(self.bar_state == bar_spec.BAR_WAIT, ila.ite(self.bar_counter_enter == self.bar_counter_max, ila.const(bar_spec.BAR_EXIT, bar_spec.BAR_STATE_BITS), self.bar_state),\
         ila.ite(self.bar_state == bar_spec.BAR_EXIT, ila.const(bar_spec.BAR_FINISH, bar_spec.BAR_STATE_BITS), self.bar_state))))), self.bar_state)
    '''
    '''
#sample for uILA bar_counter_enter update
    def ptxSample(self):
        bar_spec = barSpec()
        return ila.ite(self.bar_state == bar_spec.BAR_ENTER, ila.ite(self.bar_counter_exit != 0, self.bar_counter_enter, self.bar_counter_enter + 1), ila.ite((self.bar_state == bar_spec.BAR_EXIT) & (self.bar_counter_exit == 1), ila.const(0x0, bar_spec.BAR_COUNTER_ENTER_BITS), self.bar_counter_enter))
    '''
    '''
    #sample for uILA bar_state update.
    def ptxSample(self):
        bar_spec = barSpec()
        return ila.ite(self.bar_state == bar_spec.BAR_ENTER, ila.ite(self.bar_counter_exit != 0, ila.const(bar_spec.BAR_ENTER, bar_spec.BAR_STATE_BITS), ila.ite(self.bar_counter_enter == (self.bar_counter_max - 1), ila.const(bar_spec.BAR_EXIT, bar_spec.BAR_STATE_BITS), ila.const(bar_spec.BAR_WAIT, bar_spec.BAR_STATE_BITS))), ila.ite(self.bar_state == bar_spec.BAR_WAIT, ila.ite(self.bar_counter_enter == self.bar_counter_max, ila.const(bar_spec.BAR_EXIT, bar_spec.BAR_STATE_BITS), ila.const(bar_spec.BAR_WAIT, bar_spec.BAR_STATE_BITS)), ila.ite(self.bar_state == bar_spec.BAR_EXIT, ila.const(bar_spec.BAR_FINISH, bar_spec.BAR_STATE_BITS), self.bar_state)))
    '''
    '''
    #sample for topILA bar_state update.
    def ptxSample(self):
        bar_spec = barSpec()
        return ila.ite(self.opcode == 71, ila.ite(self.bar_state == bar_spec.BAR_FINISH, ila.const(bar_spec.BAR_INIT, bar_spec.BAR_STATE_BITS), ila.ite(self.bar_state == bar_spec.BAR_INIT, ila.const(bar_spec.BAR_ENTER, bar_spec.BAR_STATE_BITS), self.bar_state)), self.bar_state)
    '''
    '''
    #sample for topILA pc.    
    def ptxSample(self):
        bar_spec = barSpec()
        return ila.ite(self.opcode == 71, ila.ite(self.bar_state == bar_spec.BAR_FINISH, self.pc + 4 , self.pc), self.pc + 4)

    '''
    '''
    #sample for branch instruction
    def ptxSample(self):
        return ila.ite(self.opcode == 67, ila.ite(self.baseImm == 0, self.pc + ila.const(0b100, instruction_format.PC_BITS) + self.branchImm, ila.ite(self.predReg == 0, self.pc + ila.const(0b100, instruction_format.PC_BITS), self.pc + ila.const(0b100, instruction_format.PC_BITS) + self.branchImm)), self.pc + ila.const(0b100, instruction_format.PC_BITS))
    '''

    '''
    #Only with alu intruction
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
