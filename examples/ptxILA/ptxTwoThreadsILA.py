import ila
import ptxILA
import pickle
import Instruction_Format

instruction_format = Instruction_Format.InstructionFormat()
BAR_OPCODE = 71


class ptxTwoThreadsILA(object):
    def __init__(self):
        self.model = ila.Abstraction('ptxTwoThreads')
        self.createStates()

    def createStates(self):
        self.createPC()
        self.createRegs()
        self.createMems()
        self.instructionFetch()
        self.createBar()
        self.pc_nxt()

    def createPC(self):
        self.pc_a = self.model.reg('pc_a', instruction_format.PC_BITS)
        self.pc_b = self.model.reg('pc_b', instruction_format.PC_BITS)
        self.model.set_init('pc_a', self.model.const(0x0, instruction_format.PC_BITS))
        self.model.set_init('pc_b', self.model.const(0x0, instruction_format.PC_BITS))
    
    def createRegs(self):
        self.scalar_registers_a = []
        self.scalar_registers_b = []
        reg_book_obj = open(ptxILA.reg_book_file)
        reg_book = pickle.load(reg_book_obj)
        reg_book.remove('bar_state')
        reg_book.remove('bar_counter_enter')
        reg_book.remove('bar_counter_exit')
        '''
        for reg_name in reg_book:
            self.scalar_registers_a.append(self.model.reg(reg_name + '_a', instruction_format.REG_BITS))
            self.scalar_registers_b.append(self.model.reg(reg_name + '_b', instruction_format.REG_BITS)) 
        '''
        self.arb_fun = self.model.fun('arb_fun', 1, [])
        self.arb = self.model.reg('arb', 1)
        self.model.set_next('arb', ila.appfun(self.arb_fun, []))    #Non-determined value
        self.arbA = ila.const(0x0, 1)
        self.arbB = ila.const(0x1, 1)
        self.model.set_init('arb', self.model.const(0x0, 1))

    def createMems(self):
        self.mem = self.model.mem('mem', instruction_format.MEM_ADDRESS_BITS, instruction_format.MEM_BITS)
        self.model.set_next('mem', self.mem)
        self.mem_init_value = ila.MemValues(instruction_format.MEM_ADDRESS_BITS, instruction_format.MEM_BITS, 0x0)
        self.mem_init_value[0x4] = 0x0000000011c00000
        self.mem_init_value[0xc] = 0x0000000011c00000
        #self.mem_init_value[0x40] = 0x11c00000
        self.model.set_init('mem', self.model.const(self.mem_init_value)) 
            

    def createBar(self):
        bar_spec = ptxILA.barSpec()
        self.bar_state_a = self.model.reg('bar_state_a', bar_spec.BAR_STATE_BITS)
        self.bar_state_b = self.model.reg('bar_state_b', bar_spec.BAR_STATE_BITS)
        self.bar_counter_enter = self.model.reg('bar_counter_enter', bar_spec.BAR_COUNTER_ENTER_BITS)
        self.bar_counter_exit = self.model.reg('bar_counter_exit', bar_spec.BAR_COUNTER_EXIT_BITS)
        self.bar_counter_max = bar_spec.THREAD_NUM
        self.bar_state_a_next = ila.ite(self.arb == self.arbA, ila.ite(self.opcode_a == bar_spec.BAR_OPCODE, ila.ite(self.bar_state_a == bar_spec.BAR_FINISH, ila.const(bar_spec.BAR_INIT, bar_spec.BAR_STATE_BITS),\
         ila.ite(self.bar_state_a == bar_spec.BAR_INIT, ila.const(bar_spec.BAR_ENTER, bar_spec.BAR_STATE_BITS),\
         ila.ite(self.bar_state_a == bar_spec.BAR_ENTER, ila.ite(self.bar_counter_exit != 0, self.bar_state_a,\
         ila.ite(self.bar_counter_enter == (self.bar_counter_max - 1), ila.const(bar_spec.BAR_EXIT, bar_spec.BAR_STATE_BITS), ila.const(bar_spec.BAR_WAIT, bar_spec.BAR_STATE_BITS))),\
         ila.ite(self.bar_state_a == bar_spec.BAR_WAIT, ila.ite(self.bar_counter_enter == self.bar_counter_max, ila.const(bar_spec.BAR_EXIT, bar_spec.BAR_STATE_BITS), self.bar_state_a),\
         ila.ite(self.bar_state_a == bar_spec.BAR_EXIT, ila.const(bar_spec.BAR_FINISH, bar_spec.BAR_STATE_BITS), self.bar_state_a))))), self.bar_state_a), self.bar_state_a)
    
        self.bar_state_b_next = ila.ite(self.arb == self.arbB, ila.ite(self.opcode_b == bar_spec.BAR_OPCODE, ila.ite(self.bar_state_b == bar_spec.BAR_FINISH, ila.const(bar_spec.BAR_INIT, bar_spec.BAR_STATE_BITS),\
        ila.ite(self.bar_state_b == bar_spec.BAR_INIT, ila.const(bar_spec.BAR_ENTER, bar_spec.BAR_STATE_BITS),\
        ila.ite(self.bar_state_b == bar_spec.BAR_ENTER, ila.ite(self.bar_counter_exit != 0, self.bar_state_b,\
        ila.ite(self.bar_counter_enter == (self.bar_counter_max - 1), ila.const(bar_spec.BAR_EXIT, bar_spec.BAR_STATE_BITS), ila.const(bar_spec.BAR_WAIT, bar_spec.BAR_STATE_BITS))),\
        ila.ite(self.bar_state_b == bar_spec.BAR_WAIT, ila.ite(self.bar_counter_enter == self.bar_counter_max, ila.const(bar_spec.BAR_EXIT, bar_spec.BAR_STATE_BITS), self.bar_state_b),\
        ila.ite(self.bar_state_b == bar_spec.BAR_EXIT, ila.const(bar_spec.BAR_FINISH, bar_spec.BAR_STATE_BITS), self.bar_state_b))))), self.bar_state_b), self.bar_state_b)
    
        self.bar_counter_enter_next_a = ila.ite(self.opcode_a == bar_spec.BAR_OPCODE, \
        ila.ite(self.bar_state_a == bar_spec.BAR_INIT, self.bar_counter_enter, \
        ila.ite(self.bar_state_a == bar_spec.BAR_FINISH, self.bar_counter_enter,\
        ila.ite(self.bar_state_a == bar_spec.BAR_ENTER, ila.ite(self.bar_counter_exit == 0, self.bar_counter_enter + 1, self.bar_counter_enter),\
        ila.ite(self.bar_state_a == bar_spec.BAR_WAIT, self.bar_counter_enter, \
        ila.ite(self.bar_state_a == bar_spec.BAR_EXIT, ila.ite(self.bar_counter_exit == 1, ila.const(0x0, bar_spec.BAR_COUNTER_ENTER_BITS), self.bar_counter_enter), self.bar_counter_enter))))), \
        self.bar_counter_enter)
        self.bar_counter_enter_next_b = ila.ite(self.opcode_b == bar_spec.BAR_OPCODE, \
        ila.ite(self.bar_state_b == bar_spec.BAR_INIT, self.bar_counter_enter, \
        ila.ite(self.bar_state_b == bar_spec.BAR_FINISH, self.bar_counter_enter,\
        ila.ite(self.bar_state_b == bar_spec.BAR_ENTER, ila.ite(self.bar_counter_exit == 0, self.bar_counter_enter + 1, self.bar_counter_enter),\
        ila.ite(self.bar_state_b == bar_spec.BAR_WAIT, self.bar_counter_enter, \
        ila.ite(self.bar_state_b == bar_spec.BAR_EXIT, ila.ite(self.bar_counter_exit == 1, ila.const(0x0, bar_spec.BAR_COUNTER_ENTER_BITS), self.bar_counter_enter), self.bar_counter_enter))))), \
        self.bar_counter_enter)
        self.bar_counter_enter_next = ila.ite(self.arb == self.arbA, self.bar_counter_enter_next_a, self.bar_counter_enter_next_b)

        self.bar_counter_exit_next_a = ila.ite(self.opcode_a == bar_spec.BAR_OPCODE,\
        ila.ite(self.bar_state_a == bar_spec.BAR_INIT, self.bar_counter_exit,\
        ila.ite(self.bar_state_a == bar_spec.BAR_FINISH, self.bar_counter_exit,\
        ila.ite(self.bar_state_a == bar_spec.BAR_ENTER, ila.ite(self.bar_counter_exit == 0, ila.ite(self.bar_counter_enter == (self.bar_counter_max - 1), ila.const(self.bar_counter_max, bar_spec.BAR_COUNTER_EXIT_BITS), self.bar_counter_exit), self.bar_counter_exit),\
        ila.ite(self.bar_state_a == bar_spec.BAR_WAIT, self.bar_counter_exit,\
        ila.ite(self.bar_state_a == bar_spec.BAR_EXIT, ila.ite(self.bar_counter_exit != 0, self.bar_counter_exit - 1, self.bar_counter_exit - 1), self.bar_counter_exit))))),\
        self.bar_counter_exit) 
        self.bar_counter_exit_next_b = ila.ite(self.opcode_b == bar_spec.BAR_OPCODE,\
        ila.ite(self.bar_state_b == bar_spec.BAR_INIT, self.bar_counter_exit,\
        ila.ite(self.bar_state_b == bar_spec.BAR_FINISH, self.bar_counter_exit,\
        ila.ite(self.bar_state_b == bar_spec.BAR_ENTER, ila.ite(self.bar_counter_exit == 0, ila.ite(self.bar_counter_enter == (self.bar_counter_max - 1), ila.const(self.bar_counter_max, bar_spec.BAR_COUNTER_EXIT_BITS), self.bar_counter_exit), self.bar_counter_exit),\
        ila.ite(self.bar_state_b == bar_spec.BAR_WAIT, self.bar_counter_exit,\
        ila.ite(self.bar_state_b == bar_spec.BAR_EXIT, ila.ite(self.bar_counter_exit != 0, self.bar_counter_exit - 1, self.bar_counter_exit - 1), self.bar_counter_exit))))),\
        self.bar_counter_exit) 
        self.bar_counter_exit_next = ila.ite(self.arb == self.arbA, self.bar_counter_exit_next_a, self.bar_counter_exit_next_b)  
        self.model.set_next('bar_state_a', self.bar_state_a_next)
        self.model.set_next('bar_state_b', self.bar_state_b_next)
        self.model.set_next('bar_counter_enter', self.bar_counter_enter_next)
        self.model.set_next('bar_counter_exit', self.bar_counter_exit_next)
        self.model.set_init('bar_state_a', self.model.const(bar_spec.BAR_INIT, bar_spec.BAR_STATE_BITS))
        self.model.set_init('bar_state_b', self.model.const(bar_spec.BAR_INIT, bar_spec.BAR_STATE_BITS))
        self.model.set_init('bar_counter_enter', self.model.const(0x0, bar_spec.BAR_COUNTER_ENTER_BITS))
        self.model.set_init('bar_counter_exit', self.model.const(0x0, bar_spec.BAR_COUNTER_EXIT_BITS))


    def pc_nxt(self):
        bar_spec = ptxILA.barSpec()
        self.pc_a_next = ila.ite(self.arb == self.arbA, ila.ite(self.opcode_a == bar_spec.BAR_OPCODE, ila.ite(self.bar_state_a == bar_spec.BAR_FINISH, self.pc_a + 4 , self.pc_a), self.pc_a + 4), self.pc_a)
        self.pc_b_next = ila.ite(self.arb == self.arbB, ila.ite(self.opcode_b == bar_spec.BAR_OPCODE, ila.ite(self.bar_state_b == bar_spec.BAR_FINISH, self.pc_b + 4 , self.pc_b), self.pc_b + 4), self.pc_b)
        self.model.set_next('pc_a', self.pc_a_next)
        self.model.set_next('pc_b', self.pc_b_next)
    def instructionFetch(self):
        self.inst_a = ila.load(self.mem, ila.zero_extend(self.pc_a[31:2], instruction_format.MEM_ADDRESS_BITS))
        self.inst_b = ila.load(self.mem, ila.zero_extend(self.pc_b[31:2], instruction_format.MEM_ADDRESS_BITS))
        self.opcode_a = self.inst_a[(instruction_format.OPCODE_BIT_TOP - 1) : instruction_format.OPCODE_BIT_BOT]
        self.opcode_b = self.inst_b[(instruction_format.OPCODE_BIT_TOP - 1) : instruction_format.OPCODE_BIT_BOT]
       
    def set_init(self):
        bar_spec = ptxILA.barSpec()
        self.a_is_bar = (self.opcode_a == bar_spec.BAR_OPCODE)
        #self.a_is_bar = (self.pc_a == 20)
        self.a_previous_bar = self.model.bit('a_previous_bar')
        self.model.set_next('a_previous_bar', self.a_is_bar)
        self.a_cross_bar_flag = self.model.bit('a_cross_bar_flag')
        self.model.set_next('a_cross_bar_flag', ila.ite((self.a_is_bar == ila.bool(False)) & (self.a_previous_bar == ila.bool(True)), ila.bool(True), self.a_cross_bar_flag))
        self.b_is_bar = (self.opcode_b == bar_spec.BAR_OPCODE)
        self.b_come_to_bar_flag = self.model.bit('b_come_to_bar_flag')
        self.model.set_next('b_come_to_bar_flag', ila.ite(self.b_is_bar, ila.bool(True), self.b_come_to_bar_flag))
        
        self.predicate_one = self.model.bit('predicate_one')
        self.model.set_next('predicate_one', (~self.a_cross_bar_flag) | (self.b_come_to_bar_flag))
        
        self.model.set_init('a_previous_bar', self.model.bool(False))
        self.model.set_init('a_cross_bar_flag', self.model.bool(False))
        self.model.set_init('b_come_to_bar_flag', self.model.bool(False))
        self.model.set_init('predicate_one', self.model.bool(True))
        


        golden = ila.Abstraction('golden')
        g_prop = golden.bit('prop')
        golden.set_next('prop', golden.bool(True))
        golden.set_init('prop', golden.bool(True))
        ila.bmc(30, self.model, self.predicate_one, 1, golden, g_prop)
         
    def property_test2(self):
        bar_spec = ptxILA.barSpec()
        self.a_is_second_bar = (self.pc_a == 12 * instruction_format.MEM_BITS / 8)
        self.a_previous_is_second_bar = self.model.bit('a_previous_is_second_bar')
        self.model.set_next('a_previous_is_second_bar', self.a_is_second_bar)
        self.a_cross_second_bar_flag = self.model.bit('a_cross_second_bar_flag')
        self.model.set_next('a_cross_second_bar_flag', ila.ite((self.a_is_second_bar == ila.bool(False)) & (self.a_previous_is_second_bar == ila.bool(True)), ila.bool(True), self.a_cross_second_bar_flag))
        self.b_is_second_bar = (self.pc_b == ila.const(12 * instruction_format.MEM_BITS / 8, instruction_format.PC_BITS))
        self.b_come_to_second_bar_flag = self.model.bit('b_come_to_second_bar_flag')
        self.model.set_next('b_come_to_second_bar_flag', ila.ite(self.b_is_second_bar, ila.bool(True), self.b_come_to_second_bar_flag))

        self.predicate_two = self.model.bit('predicate_two')
        self.model.set_next('predicate_two', (~self.a_cross_second_bar_flag) | (self.b_come_to_second_bar_flag))
        self.model.set_init('a_previous_is_second_bar', self.model.bool(False))
        self.model.set_init('a_cross_second_bar_flag', self.model.bool(False))
        self.model.set_init('b_come_to_second_bar_flag', self.model.bool(False))
        self.model.set_init('predicate_two', self.model.bool(True))

        golden = ila.Abstraction('golden')
        g_prop = golden.bit('prop')
        golden.set_next('prop', golden.bool(True))
        golden.set_init('prop', golden.bool(True))
        ila.bmc(10, self.model, self.predicate_two, 1, golden, g_prop)
if __name__ == '__main__':
    two_threads = ptxTwoThreadsILA()
    two_threads.property_test2()
    #two_threads.set_init()




