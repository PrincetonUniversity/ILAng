import ila
import pickle
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
        self.THREAD_NUM = 128

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
        self.createStates()
        self.ubar()
        self.assumptions()
         
    def createStates(self):
        self.createPC()
        self.createRegs()
        self.createMems()
        self.createuBar()
        self.instructionFetch()
        self.instructionDecode()
        #self.addInstruction()

    def createPC(self):
        self.pc = self.model.reg('pc', PC_BITS)

    def createRegs(self):
        self.scalar_registers = []
        reg_book_obj = open(reg_book_file)
        reg_book = pickle.load(reg_book_obj)
        #Here's something to be cleaned up in future.
        #These 3 states are needed for ptxSim, 
        #but here we have to remove them,
        #because the length of these regs are not as general regs.
        reg_book.remove('bar_state')
        reg_book.remove('bar_counter_enter') 
        reg_book.remove('bar_counter_exit')
        for reg_name in reg_book :
            self.scalar_registers.append(self.model.reg(reg_name, REG_BITS))			

    def createMems(self):
        self.mem = self.model.mem('mem', MEM_ADDRESS_BITS, MEM_ADDRESS_BITS)
        
    def createuBar(self):
        bar_spec = barSpec()
        self.bar_state = self.model.reg('bar_state', bar_spec.BAR_STATE_BITS)
        #self.bar_counter_enter = self.model.reg('bar_counter_enter', bar_spec.BAR_COUNTER_ENTER_BITS)
        #self.bar_counter_exit = self.model.reg('bar_counter_exit', bar_spec.BAR_COUNTER_EXIT_BITS)
        #self.bar_state = self.model.getreg('bar_state')
        #self.bar_counter_enter = self.model.getreg('bar_counter_enter')
        #self.bar_counter_exit = self.model.getreg('bar_counter_exit')
        bar_state_next = ila.choice('bar_state_next', [ila.const(bar_spec.BAR_INIT ,bar_spec.BAR_STATE_BITS), ila.const(bar_spec.BAR_ENTER, bar_spec.BAR_STATE_BITS)])
        self.model.set_next('bar_state', bar_state_next)
        #self.model.set_next('bar_counter_enter', self.bar_counter_enter)
        #self.model.set_next('bar_counter_exit', self.bar_counter_exit)

    def instructionFetch(self):
        self.inst = ila.load(self.mem, ila.zero_extend(self.pc[31:2], MEM_ADDRESS_BITS))
        self.opcode = self.inst[(REG_BITS - 1):OPCODE_BIT]
        self.fetch_expr = self.inst
        self.dest = self.inst[(OPCODE_BIT - 1):DST_BIT]
        self.src1 = self.inst[(DST_BIT - 1):SRC0_BIT]
        self.src2 = self.inst[(SRC0_BIT - 1):SRC1_BIT]
        self.src3 = self.inst[(SRC1_BIT - 1):SRC2_BIT]
        self.baseImm = ila.sign_extend(self.inst[(BASE_BIT-1): 0], PC_BITS)
        self.branchPred = self.dest
        self.predReg = self.indexIntoReg(self.branchPred)
        self.branchImm = ila.zero_extend(self.inst[(DST_BIT - 1) : BASE_BIT], PC_BITS)
        self.sreg1 = self.indexIntoReg(self.src1)
        self.sreg2 = self.indexIntoReg(self.src2)
        self.sreg3 = self.indexIntoReg(self.src3)
        self.sregdest = self.indexIntoReg(self.dest)
    
    def instructionDecode(self):
        instruction_map_file = 'instruction_map'
        instruction_map_obj = open(instruction_map_file, 'r')
        instruction_map = pickle.load(instruction_map_obj)
        bar_spec = barSpec()
        #ALUInstructions = [(self.opcode == instruction_map['add']), (self.opcode == instruction_map['sub']),(self.opcode == instruction_map['mul']), ((self.opcode == instruction_map['bra']) & (self.predReg != 0) & (self.baseImm != 0)), ((self.opcode == instruction_map['bra']) & (self.baseImm == 0)), (self.opcode != instruction_map['add']) & (self.opcode != instruction_map['sub']) & (self.opcode != instruction_map['mul']) & ((self.opcode != instruction_map['bra']) | (self.predReg == 0) | (self.baseImm == 0))&((self.opcode != instruction_map['bra']) | (self.baseImm != 0)) ]
        #decodeList = ALUInstructions + [(self.opcode == instruction_map['bar']) & (self.bar_state == bar_spec.BAR_INIT), (self.opcode == instruction_map['bar']) & (self.bar_state == bar_spec.BAR_FINISH)]
        decodeList = [(self.opcode == instruction_map['bar']) & (self.bar_state == bar_spec.BAR_INIT), (self.opcode == instruction_map['bar']) & (self.bar_state == bar_spec.BAR_FINISH)]

        self.model.decode_exprs = decodeList
        #self.bar_state_next = ila.ite((self.opcode == instruction_map['bar']) & (self.bar_state == bar_spec.BAR_INIT), ila.const(1, bar_spec.BAR_STATE_BITS) ila.ite(self.bar_state == bar_spec.BAR_FINISH, bar_spec.BAR_INIT, self.bar_state)) #non-synthesize bar instruction

    def ubar(self):
        instruction_map_file = 'instruction_map'
        instruction_map_obj = open(instruction_map_file, 'r')
        instruction_map = pickle.load(instruction_map_obj)
        bar_spec = barSpec()
        self.u_bar_model = self.model.add_microabstraction('bar_instruction', ((self.bar_state > bar_spec.BAR_INIT) & (self.bar_state < bar_spec.BAR_FINISH)))
        self.bar_counter_enter = self.u_bar_model.reg('bar_counter_enter', bar_spec.BAR_COUNTER_ENTER_BITS)
        self.bar_counter_exit = self.u_bar_model.reg('bar_counter_exit', bar_spec.BAR_COUNTER_EXIT_BITS)
        #bar_counter_enter = self.model.getreg('bar_counter_enter')
        #bar_counter_exit = self.model.getreg('bar_counter_exit')
        bar_state = self.model.getreg('bar_state')
        self.bar_counter_max = bar_spec.THREAD_NUM  # need cleanup
        #bar_state_next = ila.ite(bar_state == bar_spec.bar_enter, ila.ite(bar_counter_exit != 0, bar_spec.bar_enter, ila.ite(bar_counter_enter == (bar_counter_max - 1), bar_spec.bar_exit, bar_wait)), ila.ite(bar_state == bar_spec.bar_wait, ila.ite(bar_counter_enter == bar_counter_max, bar_spec.bar_exit, bar_spec.bar_wait), ila.ite(bar_state == bar_spec.bar_exit, bar_spec.bar_finish , bar_state)))
        #bar_counter_enter_next = ila.ite(bar_state == bar_spec.bar_enter, ila.ite(bar_counter_exit != 0, bar_counter_enter, bar_counter_enter + 1), ila.ite((bar_state == bar_spec.bar_exit) & (bar_counter_exit == 1), ila.const(0x0, bar_spec.bar_counter_enter_bits), bar_counter_enter))
        #bar_counter_exit_next = ila.ite((bar_state == bar_spec.bar_enter) & (counter_enter == (bar_counter_max - 1)), bar_counter_max, ila.ite(bar_state == bar_spec.bar_exit, bar_counter_exit - 1, bar_counter_exit))
        bar_state_next = ila.choice('bar_state_next', [ila.const(i, bar_spec.BAR_STATE_BITS) for i in range(1,4)])
        self.bar_counter_enter_next = ila.choice('bar_counter_enter_next', [self.bar_counter_enter, self.bar_counter_enter + 1, ila.const(0x0, bar_spec.BAR_COUNTER_ENTER_BITS)])
        self.bar_counter_exit_next = ila.choice('bar_counter_exit_next', [self.bar_counter_exit, self.bar_counter_exit + 1, ila.const(self.bar_counter_max, bar_spec.BAR_COUNTER_EXIT_BITS)])
        self.u_bar_model.set_next('bar_state', bar_state_next)
        self.u_bar_model.set_next('bar_counter_enter', self.bar_counter_enter_next)
        self.u_bar_model.set_next('bar_counter_exit', self.bar_counter_exit_next)
        bar_decode_list = [(bar_state == bar_spec.BAR_ENTER) & (self.bar_counter_exit != 0),\
                           (bar_state == bar_spec.BAR_ENTER) & (self.bar_counter_exit == 0) & (self.bar_counter_enter == (self.bar_counter_max - 1)),\
                           (bar_state == bar_spec.BAR_ENTER) & (self.bar_counter_exit == 0) & (self.bar_counter_enter != (self.bar_counter_max - 1)),\
                           (bar_state == bar_spec.BAR_WAIT) & (self.bar_counter_enter != self.bar_counter_max),\
                           (bar_state == bar_spec.BAR_WAIT) & (self.bar_counter_enter == self.bar_counter_max),\
                           (bar_state == bar_spec.BAR_EXIT) & (self.bar_counter_exit != 1),\
                           (bar_state == bar_spec.BAR_EXIT) & (self.bar_counter_exit == 1)]
        self.u_bar_model.decode_exprs = bar_decode_list

    def assumptions(self):
        instruction_map_file = 'instruction_map'
        instruction_map_obj = open(instruction_map_file, 'r')
        instruction_map = pickle.load(instruction_map_obj)
        bar_spec = barSpec()
        self.model.add_assumption((self.opcode == instruction_map['bar'])) #& ((self.bar_state == bar_spec.BAR_INIT) | (self.bar_state == bar_spec.BAR_FINISH) ))
        #self.u_bar_model.add_assumption((self.opcode == instruction_map['bar']) & (self.bar_state > bar_spec.BAR_INIT) & (self.bar_state < bar_spec.BAR_FINISH))


    def pc_nxt(self):
        self.pcPlus4 = self.pc + ila.const(0b100, PC_BITS)
        self.branchPC = self.pcPlus4 + self.branchImm
        return ila.choice("pc_nxt", [self.pc ,self.pcPlus4, self.branchPC])

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

    def compare(self):
        next_1 = self.u_bar_model.get_next('bar_state')
        next_2 = self.ptxSample()
        if not self.u_bar_model.areEqual(next_1, next_2):
            print 'not equal'
        else:
            print 'equal'
    '''
    def ptxSample(self):
        bar_spec = barSpec()
        return ila.ite(self.bar_state == bar_spec.BAR_ENTER, ila.ite(self.bar_counter_exit != 0, self.bar_counter_enter, self.bar_counter_enter + 1), ila.ite((self.bar_state == bar_spec.BAR_EXIT) & (self.bar_counter_exit == 1), ila.const(0x0, bar_spec.BAR_COUNTER_ENTER_BITS), self.bar_counter_enter))
    '''
    
    #sample for uILA bar_state update.
    def ptxSample(self):
        bar_spec = barSpec()
        return ila.ite(self.bar_state == bar_spec.BAR_ENTER, ila.ite(self.bar_counter_exit != 0, ila.const(bar_spec.BAR_ENTER, bar_spec.BAR_STATE_BITS), ila.ite(self.bar_counter_enter == (self.bar_counter_max - 1), ila.const(bar_spec.BAR_EXIT, bar_spec.BAR_STATE_BITS), ila.const(bar_spec.BAR_WAIT, bar_spec.BAR_STATE_BITS))), ila.ite(self.bar_state == bar_spec.BAR_WAIT, ila.ite(self.bar_counter_enter == self.bar_counter_max, ila.const(bar_spec.BAR_EXIT, bar_spec.BAR_STATE_BITS), ila.const(bar_spec.BAR_WAIT, bar_spec.BAR_STATE_BITS)), ila.ite(self.bar_state == bar_spec.BAR_EXIT, ila.const(bar_spec.BAR_FINISH, bar_spec.BAR_STATE_BITS), self.bar_state)))
    
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
        return ila.ite(self.opcode == 67, ila.ite(self.baseImm == 0, self.pc + ila.const(0b100, PC_BITS) + self.branchImm, ila.ite(self.predReg == 0, self.pc + ila.const(0b100, PC_BITS), self.pc + ila.const(0b100, PC_BITS) + self.branchImm)), self.pc + ila.const(0b100, PC_BITS))
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
