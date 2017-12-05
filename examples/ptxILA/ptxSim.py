import pickle
import commands
import os
import time
import ptxILA
import Instruction_Format
import ila
instruction_format = Instruction_Format.InstructionFormat()
instruction_map_file = 'instruction_map'
instruction_map_obj = open(instruction_map_file, 'r')
instruction_map = pickle.load(instruction_map_obj)
mem_map_file = 'mem_map'
mem_map_obj = open(mem_map_file, 'r')
[mem_map, mem_size] = pickle.load(mem_map_obj)


class ptx_sim(object):
    def __init__(self):
        #self.OP_BIT = 22
        #self.DST_BIT = 17
        #self.SRC0_BIT = 12
        #self.SRC1_BIT = 7
        #self.SRC2_BIT = 2
        #self.BASE_BIT = 2
        #self.PRED_BIT = 17 
        self.OP_BIT = instruction_format.OPCODE_BIT 
        self.DST_BIT = instruction_format.DST_BIT
        self.SRC0_BIT = instruction_format.SRC0_BIT
        self.SRC1_BIT = instruction_format.SRC1_BIT
        self.SRC2_BIT = instruction_format.SRC2_BIT 
        self.BASE_BIT = instruction_format.BASE_BIT
        self.PRED_BIT = instruction_format.PRED_BIT
        self.OPCODE_LENGTH = instruction_format.OPCODE_LENGTH
        
        #self.OPERAND_WIDTH = 5
        #self.OPCODE_MASK = 0xffc00000
        #self.DST_MASK = 0x003e0000
        #self.SRC0_MASK = 0x0001f000
        #self.SRC1_MASK = 0x00000f80
        #self.SRC2_MASK = 0x0000007c
        #self.BASE_MASK = 0x00000003
        #self.IMM_MASK = 0x00000fff
        #self.P_MASK = 0x003e0000
        #self.BRA_MASK = 0x0001fffc
        
        self.OPCODE_MASK = (1 << instruction_format.OPCODE_BIT_TOP) - (1 << instruction_format.OPCODE_BIT_BOT)
        self.DST_MASK = (1 << instruction_format.DST_BIT_TOP) - (1 << instruction_format.DST_BIT_BOT)
        self.SRC0_MASK = (1 << instruction_format.SRC0_BIT_TOP) - (1 << instruction_format.SRC0_BIT_BOT)
        self.SRC1_MASK = (1 << instruction_format.SRC1_BIT_TOP) - (1 << instruction_format.SRC1_BIT_BOT)
        self.SRC2_MASK = (1 << instruction_format.SRC2_BIT_TOP) - (1 << instruction_format.SRC2_BIT_BOT)
        self.BASE_MASK = (1 << instruction_format.BASE_BIT_TOP) - (1 << instruction_format.BASE_BIT_BOT)
        self.IMM_MASK = (1 << instruction_format.IMM_BIT_TOP) - (1 << instruction_format.IMM_BIT_BOT)
        self.P_REG_MASK = self.DST_MASK
        self.P_REG_BIT = self.DST_BIT
        self.ldIMM_MASK = self.IMM_MASK
        self.stIMM_MASK = self.IMM_MASK
        self.BRA_MASK = self.ldIMM_MASK

        self.OPCODE_MUL = 29
        self.OPCODE_SUB = 28
        self.OPCODE_ADD = 27
        self.OPCODE_BRA = 67 
        self.OPCODE_BAR = 71
        self.OPCODE_LD = instruction_map['ld']
        self.OPCODE_ST = instruction_map['st']
        self.OPCODE_MOV = instruction_map['mov']
        self.EXAMPLE_PROGRAM_HOLE = 57
        self.PRE_LD_HOLE = 33 
        
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
        print instruction
        #pc += 4
        #state['pc'] = pc
        
        opcode = self.OPCODE_MASK & instruction
        opcode = opcode >> instruction_format.OPCODE_BIT_BOT
        dst = self.DST_MASK & instruction
        dst = dst >> instruction_format.DST_BIT_BOT
        src0 = self.SRC0_MASK & instruction
        src0 = src0 >> instruction_format.SRC0_BIT_BOT
        src1 = self.SRC1_MASK & instruction
        src1 = src1 >> instruction_format.SRC1_BIT_BOT
        base = self.BASE_MASK & instruction
        base = base >> instruction_format.BASE_BIT_BOT
        pred = self.P_REG_MASK & instruction
        pred = pred >> self.P_REG_BIT
        bra = (self.BRA_MASK & instruction) >> instruction_format.IMM_BIT_BOT
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
        if((opcode != self.OPCODE_ADD) & (opcode != self.OPCODE_SUB) & (opcode != self.OPCODE_BRA) & (opcode != self.OPCODE_BAR) & (opcode != self.OPCODE_LD) & (opcode != self.OPCODE_ST) & (opcode != self.OPCODE_MOV) & (opcode != self.OPCODE_MUL)):
            state['pc'] = state['pc'] + 4
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
        '''
        if (opcode == self.OPCODE_BAR):
            bar_state = state['bar_state']
            bar_spec = ptxILA.barSpec();
            bar_counter_enter = state['bar_counter_enter']
            bar_counter_exit = state['bar_counter_exit']
            if (bar_state == bar_spec.BAR_FINISH):
                state['pc'] = state['pc'] + 4
            sim_program_line = ''
            sim_program_line += 'mov.u32 %r1, ' + str(bar_state) + ';'
            sim_program_line += 'mov.u32 %r23, ' + str(bar_counter_enter) + ';'
            sim_program_line += 'mov.u32 %r24, ' + str(bar_counter_exit) + '; \n'
            example_sim_program_file = 'tbar.ptx'
            example_sim_program_obj = open(example_sim_program_file, 'r')
            example_sim_program = example_sim_program_obj.readlines()
            sim_program = []
            bar_program_hole = 42
            for i in range(len(example_sim_program)):
                if i == bar_program_hole:
                    sim_program.append(sim_program_line)
                else:
                    sim_program.append(example_sim_program[i])
             
            example_sim_program_obj.close()
            sim_program_file = 'tbar.ptx'
            sim_program_obj = open(sim_program_file, 'w')
            for sim_line in sim_program:
                sim_program_obj.write(sim_line)
            sim_program_obj.close()
            (status, output) = commands.getstatusoutput('./dryrun_bar.out')
            print status
            print output
            (status, output) = commands.getstatusoutput('sbatch parallel_bar.cmd')
            print status
            print output
            output_word = output.split()
            taskTag = output_word[3]
            time.sleep(5)
            (status, output) = commands.getstatusoutput('cat slurm-' + taskTag + '.out')
            while(status == 256):
                time.sleep(5)
                (status, output) = commands.getstatusoutput('cat slurm-' + taskTag + '.out')
            [bar_state, bar_counter_enter, bar_counter_exit] = output.split()
            bar_state = int(bar_state)
            bar_counter_enter = int(bar_counter_enter)
            bar_counter_exit = int(bar_counter_exit)
            if (bar_counter_enter < 0):
                bar_counter_enter = -bar_counter_enter
                bar_counter_enter = (1<<31) - bar_counter_enter + (1<<31)
            if (bar_counter_exit < 0):
                bar_counter_exit = -bar_counter_exit
                bar_counter_exit = (1<<31) - bar_counter_exit + (1<<31)
            state['bar_state'] = bar_state
            state['bar_counter_enter'] = bar_counter_enter
            state['bar_counter_exit'] = bar_counter_exit
            return state
            '''
            
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
                    if (bar_counter_exit < 0):
                        bar_counter_exit = -bar_counter_exit
                        bar_counter_exit = (1<<(bar_spec.BAR_COUNTER_EXIT_BITS - 1)) - bar_counter_exit + (1<< (bar_spec.BAR_COUNTER_EXIT - 1))
                    state['bar_counter_exit'] = bar_counter_exit
                    return state
                if bar_counter_exit == 0:
                    bar_counter_enter = 0

            state['bar_state'] = bar_state
            state['bar_counter_enter'] = bar_counter_enter
            state['bar_counter_exit'] = bar_counter_exit
            return state
            
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
            
            return state
            '''
        pc = pc + 4
        state['pc'] = pc
        op_text = instruction_book[opcode]
        op_text = op_text[:(len(op_text) - 1)]
        def find_addr(laddr):
            for mem_key in mem_map.keys():
                if (mem_map[mem_key][1]) >= laddr:
                    start_addr = mem_map[mem_key][0]
                    dmem_name = mem_key
                    return [dmem_name, start_addr]

        if opcode == self.OPCODE_LD:
            mem = state['dmem']
            default = mem.default
            values = mem.values
            addr = []
            value = []
            for (a, v) in values:
                addr.append(a * 4)
                value.append(v)
            dest_text = reg_book[dst]
            self.ldAddr = (self.ldIMM_MASK & instruction) >> instruction_format.IMM_BIT_BOT
            self.ldAddr = (self.ldAddr) << 2
            print 'load_addr' + str(self.ldAddr)
            [dmem_name, start_addr] = find_addr(self.ldAddr)
            item = (self.ldAddr - start_addr) >> 2
            pre_ld_program = ''
            pre_ld_program += '.reg .b64 %r_sim_ld<3>; .reg .b32 %r_ssim_ld;'
            for i in range(len(addr)):
                pre_addr = addr[i]
                [pre_mem_name, pre_start_addr] = find_addr(pre_addr)
                pre_item = (pre_addr - pre_start_addr) >> 2
                pre_ld_program += 'ld.param.u64 %r_sim_ld1, [' + pre_mem_name + ']; '
                pre_ld_program += 'cvta.to.global.u64 %r_sim_ld2, %r_sim_ld1; '
                pre_ld_program += 'mov.u32 %r_ssim_ld, ' + str(pre_item) + '; '
                pre_ld_program += 'mul.wide.s32 %r_sim_ld1, %r_ssim_ld, 4; '
                pre_ld_program += 'add.s64 %r_sim_ld2, %r_sim_ld1, %r_sim_ld2; '
                pre_ld_program += 'mov.u32 %r_ssim_ld, ' + str(value[i]) + '; '
                pre_ld_program += 'st.global.b32 [%r_sim_ld2], %r_ssim_ld; '
            pre_ld_program += '\n'
            ld_program = ''
            ld_program += 'ld.param.u64 %r_sim_ld1, [' + dmem_name + ']; '
            ld_program += 'cvta.to.global.u64 %r_sim_ld2, %r_sim_ld1; '
            ld_program += 'mov.u32 %r_ssim_ld, ' + str(item) + '; '
            ld_program += 'mul.wide.s32 %r_sim_ld1, %r_ssim_ld, 4; '
            ld_program += 'add.s64 %r_sim_ld2, %r_sim_ld1, %r_sim_ld2; '
            ld_program += 'ld.global.b32 ' + dest_text + ',[%r_sim_ld2]; '
            ld_program += 'mov.s32 %r9, ' + dest_text + '; '
            example_sim_program_file = 't266.ptx'
            example_sim_program_obj = open(example_sim_program_file, 'r')
            example_sim_program = example_sim_program_obj.readlines()
            sim_program = []
            for test_program_line in test_program:
                ld_program = test_program_line + ld_program
            for i in range(len(example_sim_program)):
                if i == self.EXAMPLE_PROGRAM_HOLE:
                    sim_program.append(ld_program + '\n')
                elif i == self.PRE_LD_HOLE:
                    sim_program.append(pre_ld_program)
                else:
                    sim_program.append(example_sim_program[i])       
            example_sim_program_obj.close()
            sim_program_file = 't266.ptx'
            sim_program_obj = open(sim_program_file, 'w')
            for sim_program_line in sim_program:
                sim_program_obj.write(sim_program_line)
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
                poutput = (1 << (instruction_format.REG_BITS - 1)) - poutput + (1 << (instruction_format.REG_BITS - 1)) 
            print 'poutput: ' + str(poutput)
            state[dest_text] = poutput
            if self.ldAddr not in addr:
                state[dest_text] = default
            return state 

        if opcode == self.OPCODE_ST:
            dmem = state['dmem']
            dest_text = reg_book[dst]
            st_value = state[dest_text]
            self.stAddr = (self.stIMM_MASK & instruction) >> instruction_format.IMM_BIT_BOT
            self.stAddr = self.stAddr << 2      
            print 'store_addr' + str(self.stAddr)
            outMem = ila.MemValues(instruction_format.MEM_ADDRESS_BITS, instruction_format.DMEM_BITS, dmem.default) 
            for (a,v) in dmem.values:
                outMem[a] = v
            outMem[self.stAddr] = st_value
            state['dmem'] = outMem
            return state
             
        if (opcode == self.OPCODE_MOV):
            dst_text = reg_book[dst]
            if (src0 >= len(reg_book)) | (dst >= len(reg_book)):
                return state
            if dst_text not in general_reg_book:
                return state
            src0_text = reg_book[src0]
            if src0_text not in general_reg_book:
                return state
            if base:
                return state
            src0_data = state[src0_text]
            test_program.append(op_text + '.s32 ' + dst_text + ',' + src0_text + ';')
            test_program.append('mov.s32 %r9, ' + dst_text + ';')
            single_op_program = ''
            for t in test_program:
                single_op_program += t
            single_op_program += '\n'
            
            example_sim_program_file = 't266.ptx'
            example_sim_program_obj = open(example_sim_program_file, 'r')
            example_sim_program = example_sim_program_obj.readlines()
            sim_program = []
            for i in range(len(example_sim_program)):
                if i == self.EXAMPLE_PROGRAM_HOLE:
                    sim_program.append(single_op_program)
                else:
                    sim_program.append(example_sim_program[i])
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
            (status, output)  = commands.getstatusoutput('cat slurm-' + taskTag + '.out')
            while(status == 256):
                time.sleep(5)
                (status, output) = commands.getstatusoutput('cat slurm-' + taskTag + '.out')
            poutput = int(output)
            if (poutput < 0):
                poutput = -poutput
                poutput = (1 << (instruction_format.REG_BITS - 1)) - poutput + (1 << (instruction_format.REG_BITS - 1))
            nxt_state = poutput
            state[dst_text] = nxt_state
            return state         


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
            poutput = (1 << (instruction_format.REG_BITS - 1)) - poutput + (1 << (instruction_format.REG_BITS - 1))
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

#test for alu instructions
test = ptx_sim()
state = {}
state['pc'] = 0
state['mem'] = [0x11c00000]
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
state['bar_state'] = 0b011
state['bar_counter_enter'] = 0x00000020
state['bar_counter_exit'] = 0x00800000
print state
state = test.state_parser(state)
print state

