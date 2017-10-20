import pickle
import math

def isNum(token):
    try:
        intToken = int(token)
    except ValueError:
        return False
    try:
        floatToken = float(token)
    except ValueError:
        return False
    return True

OP_BIT = 22
DST_BIT = 17
PRED_BIT = 17
SRC0_BIT = 12
SRC1_BIT = 7
SRC2_BIT = 2
BASE_BIT = 2
OPCODE_BRA = 67
BRANCH_IMM_MODEL = 0b111111111111111
source_file = 'test.ptx'
program_file = 'program_' + source_file
program_obj = open(program_file, 'r')
program = pickle.load(program_obj)

program_counter = 0

reg_map_file = 'full_reg_map'
reg_map_obj = open(reg_map_file)
reg_map = pickle.load(reg_map_obj)

instruction_map_file = 'instruction_map'
instruction_map_obj = open(instruction_map_file)
instruction_map = pickle.load(instruction_map_obj)

tag_map = {}
for program_line in program:
    if program_line[0][-1] == ':':
        tag_map[program_line[0][0:-1]] = program_counter
    else:
        program_counter += 4
print tag_map
program_bin = []
program_counter = 0
for program_line in program:
    program_counter += 4
    print program_line
    program_bin_line = 0
    op = 0
    if program_line[0][-1] == ':':
        continue
    predicate_reg_name = ''
    predicate_flag = False
    if program_line[op][0] == '@':
        predicate_reg_name = program_line[op]
        op += 1
        predicate_flag = True
	#TODO: think about tag.
    opcode_text = program_line[op]
    opcode_bin = instruction_map[opcode_text]
    dst = 0
    src0 = 0
    src1 = 0
    src2 = 0
    op += 1
    immInput = -1
    if (opcode_bin == OPCODE_BRA):
        program_bin_line += (opcode_bin << OP_BIT)
        target = program_line[op]
        instruction_base = 0
        if predicate_flag:
            target = program_line[op]
            instruction_base = 1
            program_bin_line += (reg_map[predicate_reg_name] << PRED_BIT)
            program_bin_line += (0b01)      #BASE_BIT Need cleanup
        target = program_line[op]
        target_address = tag_map[target]
        to_target_address = target_address - program_counter
        if to_target_address > 0:
            program_bin_line += (to_target_address << BASE_BIT) 
        else:
            abs_to_target_address = 0 - to_target_address
            to_target_address = BRANCH_IMM_MODEL - abs_to_target_address + 1
            program_bin_line += (to_target_address << BASE_BIT)   
        program_bin.append(program_bin_line)
        continue
    if (len(program_line) > (op)):
        if isNum(program_line[op]):
            dst = (int(program_line[op]) << BASE_BIT) % (1 << OP_BIT)
            immInput = 0
        else:
            dst = reg_map[program_line[op]]
    op += 1
    if (len(program_line) > (op)):
        if isNum(program_line[op]):
	        src0 = (int(program_line[op]) << BASE_BIT) % (1 << DST_BIT)
	        immInput = 1
        else:
            src0 = reg_map[program_line[op]]
    op += 1
    if(len(program_line) > op):
        if isNum(program_line[op]):
	        src1 = (int(program_line[op]) << BASE_BIT) % (1 << SRC0_BIT)
	        immInput = 2
        else:
            src1 = reg_map[program_line[op]]
    op += 1
    if(len(program_line) > op):
        if isNum(program_line[op]):
	        src2 = (int(program_line[op]) << BASE_BIT) % (1 << SRC1_BIT)
	        immInput = 3
        else:
            src2 = reg_map[program_line[op]]
    if immInput < 0:
        program_bin_line = (opcode_bin << OP_BIT) + (dst << DST_BIT) + (src0 << SRC0_BIT) + (src1 << SRC1_BIT) + (src2 << SRC2_BIT);
    else:
        if immInput == 0:
	        program_bin_line = (opcode_bin << OP_BIT) + dst
        elif immInput == 1:
	        program_bin_line = (opcode_bin << OP_BIT) + (dst << DST_BIT) + src0
        elif immInput == 2:
	        program_bin_line = (opcode_bin << OP_BIT) + (dst << DST_BIT) + (src0 << SRC0_BIT) + src1
		print(program_line[3])
        else:
	        progran_bin_line = (opcode_bin << OP_BIT) + (dst << DST_BIT) + (src0 << SRC0_BIT) + (src1 << SRC1_BIT) + src2
        program_bin_line += 2
    program_bin.append(program_bin_line)

for program_bin_line in program_bin:
    print ((bin(program_bin_line)))

program_bin_file = 'program.bin'
program_bin_obj = open(program_bin_file, 'w')
pickle.dump(program_bin, program_bin_obj)
    

