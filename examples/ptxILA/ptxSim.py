import pickle
import commands
import os
import time
import ptxILA
class ptx_sim(object):
    def __init__(self):
        self.OP_BIT = 22
        self.DST_BIT = 17
        self.SRC0_BIT = 12
        self.SRC1_BIT = 7
        self.SRC2_BIT = 2
        self.BASE_BIT = 2
        self.PRED_BIT = 17
        self.OPERAND_WIDTH = 5
        self.OPCODE_MASK = 0xffc00000
        self.DST_MASK = 0x003e0000
        self.SRC0_MASK = 0x0001f000
        self.SRC1_MASK = 0x00000f80
        self.SRC2_MASK = 0x0000007c
        self.BASE_MASK = 0x00000003
        self.IMM_MASK = 0x00000fff
        self.P_MASK = 0x003e0000
        self.BRA_MASK = 0x0001fffc
        #self.OPCODE_MUL = 29
        self.OPCODE_SUB = 28
        self.OPCODE_ADD = 27
        self.OPCODE_BRA = 67 
        self.OPCODE_BAR = 71
        self.EXAMPLE_PROGRAM_HOLE = 57
        
    def state_parser(self, state):
        print 'pre:'
        for s in state.keys():
            print s + ' ' + str(state[s]) 
        state = self.ptx_next_state(state)
        print 'post:'
        for s in state.keys():
            print s + ' ' + str(state[s])
        return state
    
    def ptx_next_state(self, state):
        mem = state['mem']
        pc = state['pc']
        instruction = mem[pc/4]
        #pc += 4
        #state['pc'] = pc
        
        opcode = self.OPCODE_MASK & instruction
        opcode = opcode >> self.OP_BIT
        dst = self.DST_MASK & instruction
        dst = dst >> self.DST_BIT
        src0 = self.SRC0_MASK & instruction
        src0 = src0 >> self.SRC0_BIT
        src1 = self.SRC1_MASK & instruction
        src1 = src1 >> self.SRC1_BIT
        base = self.BASE_MASK & instruction
        pred = self.P_MASK & instruction
        pred = pred >> self.PRED_BIT
        bra = (self.BRA_MASK & instruction) >> self.BASE_BIT
        test_program = []
        general_reg_book_file = 'general_reg_book'
        general_reg_book_obj = open(general_reg_book_file)
        general_reg_book = pickle.load(general_reg_book_obj)
        for general_reg in general_reg_book:
            test_program.append('mov.s32 ' + general_reg + ',' + str(state[general_reg]) + '; ')
        
        reg_book_file = 'reg_book'
        reg_book_obj = open(reg_book_file, 'r')
        reg_book = pickle.load(reg_book_obj)
        instruction_book_file = 'instruction_book'
        instruction_book_obj = open(instruction_book_file, 'r')
        instruction_book = instruction_book_obj.readlines()
        
        #if ((opcode != self.OPCODE_MUL) & (opcode != self.OPCODE_ADD) & (opcode != self.OPCODE_SUB)): 
        if((opcode != self.OPCODE_ADD) & (opcode != self.OPCODE_SUB) & (opcode != self.OPCODE_BRA) & (opcode != self.OPCODE_BAR)):
            return state
        if (opcode == self.OPCODE_BRA):
            if base:
                if pred >= len(reg_book):
                    return status
                pred_reg_text = reg_book[pred]
                if pred_reg_text not in general_reg_book:
                    return status
                pred_reg_data = state[pred_reg_text]
                if pred_reg_data:
                    pc += bra
                    state['pc'] = pc
            else:
                pc += bra
                state['pc'] = pc 
            return state
        
        if (opcode == self.OPCODE_BAR):
            bar_state = state['bar_state']
            #bar_counter_enter = state['bar_counter_enter']
            #bar_counter_exit = state['bar_counter_exit']
            bar_spec = ptxILA.barSpec()

            bar_counter_enter = state['bar_counter_enter']
            bar_counter_exit = state['bar_counter_exit']
            if bar_state == bar_spec.BAR_INIT:
                bar_state = bar_spec.BAR_ENTER
            elif bar_state == bar_spec.BAR_FINISH:
                state['pc'] = state['pc'] + 4
                bar_state = bar_spec.BAR_INIT
            elif bar_state == bar_spec.BAR_ENTER:
                if (bar_counter_exit == 0):
                    bar_counter_enter = bar_counter_enter + 1
                    if bar_counter_enter == bar_spec.THREAD_NUM:
                        bar_state = bar_spec.BAR_EXIT
                        bar_counter_exit = bar_spec.THREAD_NUM
                    else:
                        if bar_counter_enter > bar_spec.THREAD_NUM:
                            state['bar_state'] = bar_spec.BAR_WAIT
                            return state
                        bar_state = bar_spec.BAR_WAIT
            elif bar_state == bar_spec.BAR_WAIT:
                if bar_counter_enter == bar_spec.THREAD_NUM:
                    bar_state = bar_spec.BAR_EXIT
            elif bar_state == bar_spec.BAR_EXIT:
                bar_counter_exit -= 1
                bar_state = bar_spec.BAR_FINISH
                if bar_counter_exit < 0:
                    state['bar_state'] = bar_spec.BAR_FINISH
                    return state
                if bar_counter_exit == 0:
                    bar_counter_enter = 0

            state['bar_state'] = bar_state
            state['bar_counter_enter'] = bar_counter_enter
            state['bar_counter_exit'] = bar_counter_exit
            '''
            if (bar_micro_flag):
                bar_counter_enter = state['bar_counter_enter']
                bar_counter_exit = state['bar_counter_exit']
                if bar_state == bar_spec.BAR_ENTER:
                    if (bar_counter_exit == 0):
                        bar_counter_enter = bar_counter_enter + 1
                        if bar_counter_enter == bar_spec.THREAD_NUM:
                            bar_state = bar_spec.BAR_EXIT
                            bar_counter_exit = bar_spec.THREAD_NUM
                        else:
                            bar_state = bar_spec.BAR_WAIT
                elif bar_state == bar_spec.BAR_WAIT:
                    if bar_counter_enter == bar_spec.THREAD_NUM:
                        bar_state = bar_spec.BAR_EXIT
                elif bar_state == bar_spec.BAR_EXIT:
                    bar_counter_exit -= 1
                    bar_state = bar_spec.BAR_FINISH
                    if bar_counter_exit == 0:
                        bar_counter_enter = 0
                state['bar_state'] = bar_state
                state['bar_counter_enter'] = bar_counter_enter
                state['bar_counter_exit'] = bar_counter_exit
            else:
                if bar_state == bar_spec.BAR_INIT:
                    bar_state = bar_spec.BAR_ENTER
                elif bar_state == bar_spec.BAR_FINISH:
                    bar_state = bar_spec.BAR_INIT
                    state['pc'] = state['pc'] + 4
                state['bar_state'] = bar_state
                #state['bar_counter_enter'] = bar_counter_enter
                #state['bar_counter_exit'] = bar_counter_exit
            '''
            return state
        pc = pc + 4
        state['pc'] = pc
        op_text = instruction_book[opcode]
        op_text = op_text[:(len(op_text) - 1)]
       
        dst_text = reg_book[dst] 
        if (src0 >= len(reg_book)) | (src1 >= len(reg_book)) | (dst >= len(reg_book)):
            return state
        if dst_text not in general_reg_book:
            return state
        
        src0_text = reg_book[src0]
        src1_text = reg_book[src1]
        if (src0_text not in general_reg_book) | (src1_text not in general_reg_book):
            return state

        if (base):
            return state

        src0_data = state[src0_text]
        src1_data = state[src1_text]
        test_program.append(op_text + '.s32 ' + dst_text + ', ' + src0_text + ', ' + src1_text + ';')
        print (op_text + ' ' + dst_text + ', ' + src0_text + ', ' + src1_text) 
        test_program.append('mov.s32 %r9, ' + dst_text + ';')
        print test_program[-1]
        
        example_sim_program_file = 't266.ptx'
        example_sim_program_obj = open(example_sim_program_file, 'r')
        example_sim_program = example_sim_program_obj.readlines()
        sim_program = []
        sim_program_first_part = 0
        for i in range(len(example_sim_program)):
            if i != self.EXAMPLE_PROGRAM_HOLE:
                sim_program.append(example_sim_program[i])
            else:
                sim_program += test_program
                sim_program += '\n'
        example_sim_program_obj.close()
        sim_program_obj = open(example_sim_program_file, 'w')
        for sim_line in sim_program:
            sim_program_obj.write(sim_line)
        sim_program_obj.close()
        (status, output) = commands.getstatusoutput('./dryrun.out')
        print status
        print output
        (status, output) = commands.getstatusoutput('sbatch parallel.cmd')
        print status
        print output
        output_word = output.split()
        taskTag = output_word[3]
        time.sleep(5)
        (status, output) = commands.getstatusoutput('cat slurm-' + taskTag + '.out')
        while(status == 256):
            time.sleep(5)
            (status, output) = commands.getstatusoutput('cat slurm-' + taskTag + '.out')
        poutput = int(output)
        if (poutput < 0):
            poutput = -poutput
            poutput = (1<<31) - poutput + (1<<31)
        nxt_state = poutput
        (status, output) = commands.getstatusoutput('rm a_dlin*')
        (status, output) = commands.getstatusoutput('rm ' + 'slurm-' + taskTag + '.out')
        state[dst_text] = nxt_state
        return state
'''
test = ptx_sim()
state = {}
state['pc'] = 0
state['mem'] = [0x00000022]
state['r1'] = 0xffffffff
state['r2'] = 0xffffffff
state['%r0'] = 0xffffffff
state['%r1'] = 0xffffffff
state['%r2'] = 0xffffffff
state['%r3'] = 0xffffffff
state['%r4'] = 0xffffffff
state['%r5'] = 0xffffffff
state['%r6'] = 0xffffffff
state['%r7'] = 0xffffffff
state['%r8'] = 0xffffffff
state = test.state_parser(state)
'''
'''
#test for alu instructions
test = ptx_sim()
state = {}
state['pc'] = 0
state['mem'] = [0x06c00000]
state['r1'] = 0x00000010
state['r2'] = 0x00000001
state['%r0'] = 0x0000000
state['%r1'] = 0x0000001
state['%r2'] = 0x0000002
state['%r3'] = 0x0000003
state['%r4'] = 0x000000a
state['%r5'] = 0x0000005
state['%r6'] = 0x0000006
state['%r7'] = 0x0000007
state['%r8'] = 0x0000008
print state
state = test.state_parser(state)
print state
'''
