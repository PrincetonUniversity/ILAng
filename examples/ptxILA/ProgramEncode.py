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
SRC0_BIT = 12
SRC1_BIT = 7
SRC2_BIT = 2
BASE_BIT = 2
source_file = 'test.ptx'
program_file = 'program_' + source_file
program_obj = open(program_file, 'r')
program = pickle.load(program_obj)

reg_map_file = 'reg_map'
reg_map_obj = open(reg_map_file)
reg_map = pickle.load(reg_map_obj)

instruction_map_file = 'instruction_map'
instruction_map_obj = open(instruction_map_file)
instruction_map = pickle.load(instruction_map_obj)
program_bin = []
for program_line in program:
    op = 0
    if program_line[op][len(program_line[op]) - 1] == ':':
        op = 1
        pass
	#TODO: think about tag.
    opcode_text = program_line[op]
    opcode_bin = instruction_map[opcode_text]
    dst = 0
    src0 = 0
    src1 = 0
    src2 = 0
    op += 1
    immInput = -1
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
    print (bin(program_bin_line))

program_bin_file = 'program.bin'
program_bin_obj = open(program_bin_file, 'w')
pickle.dump(program_bin, program_bin_obj)
    

