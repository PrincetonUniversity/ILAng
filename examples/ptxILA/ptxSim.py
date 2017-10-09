import pickle
import commands
import os
import time
class ptx_sim(object):
    def __init__(self):
        self.OP_BIT = 22
        self.DST_BIT = 17
        self.SRC0_BIT = 12
        self.SRC1_BIT = 7
        self.SRC2_BIT = 2
        self.BASE_BIT = 2
        self.OPERAND_WIDTH = 5
        self.OPCODE_MASK = 0xffc00000
        self.DST_MASK = 0x003e0000
        self.SRC0_MASK = 0x0001f000
        self.SRC1_MASK = 0x00000f80
        self.SRC2_MASK = 0x0000007c
        self.BASE_MASK = 0x00000003
        self.IMM_MASK = 0x00000fff
        self.OPCODE_MUL = 29
        self.OPCODE_SUB = 28
        self.OPCODE_ADD = 27
        self.EXAMPLE_PROGRAM_HOLE = 53
    def state_parser(self, state):
        state = self.ptx_next_state(state)
    
    def ptx_next_state(self, state):
        mem = state['mem']
        pc = state['pc']
        instruction = mem[pc]
        pc += 1
        state['pc'] = pc
        
        opcode = self.OPCODE_MASK & instruction
        opcode = opcode >> self.OP_BIT
        dst = self.DST_MASK & instruction
        dst = dst >> self.DST_BIT
        src0 = self.SRC0_MASK & instruction
        src0 = src0 >> self.SRC0_BIT
        src1 = self.SRC1_MASK & instruction
        src1 = src1 >> self.SRC1_BIT
        base = self.BASE_MASK & instruction

        test_program = []
        general_reg_book_file = 'general_reg_book'
        general_reg_book_obj = open(general_reg_book_file)
        general_reg_book = pickle.load(general_reg_book_obj)
        for general_reg in general_reg_book:
            test_program.append('mov.s32 ' + general_reg + ' ' + str(state[general_reg]) + ';\n')
        
        reg_book_file = 'reg_book'
        reg_book_obj = open(reg_book_file, 'r')
        reg_book = pickle.load(reg_book_obj)
        instruction_book_file = 'instruction_book'
        instruction_book_obj = open(instruction_book_file, 'r')
        instruction_book = instruction_book_obj.readlines()
        
        if ((opcode != self.OPCODE_MUL) & (opcode != self.OPCODE_ADD) & (opcode != self.OPCODE_SUB)): 
            return state
        op_text = instruction_book[opcode]
        op_text = op_text[:(len(op_text) - 1)]
       
        dst_text = reg_book[dst] 
        if dst_text not in general_reg_book:
            return state

        src0_text = reg_book[dst]
        src1_text = reg_book[dst]
        src2_text = reg_book[dst]
        
        if (base):
            return state

        src0_data = state[src0_text]
        src1_data = state[src1_text]
        test_program.append(op_text + '.32 ' + dst_text + ' ' + src0_text + ' ' + src1_text)
        print (op_text + ' ' + dst_text + ' ' + src0_text + ' ' + src1_text) 
        
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
        '''
        (status, output) = commands.getstatusoutput('sbatch parallel.cmd')
        output_word = output.split()
        taskTag = output_word[3]
        time.sleep(5)
        (status, output) = commands.getstatusoutput('cat slurm-' + taskTag + '.out')
        while(status == 256):
            time.sleep(5)
            (status, output) = commands.getstatusoutput('cat slurm-' + taskTag + '.out')
        nxt_state = output
        time.sleep(5)
        '''
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
state['%r4'] = 0x0000004
state['%r5'] = 0x0000005
state['%r6'] = 0x0000006
state['%r7'] = 0x0000007
state['%r8'] = 0x0000008
state['%r9'] = 0x0000009
test.state_parser(state)
