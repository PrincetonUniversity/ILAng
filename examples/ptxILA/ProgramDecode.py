import pickle

program_bin_file = 'program.bin'
program_bin_obj = open(program_bin_file, 'r')
program_bin = pickle.load(program_bin_obj)

instruction_book_file = 'instruction_book'
instruction_book_obj = open(instruction_book_file, 'r')
instruction_book = instruction_book_obj.readlines()

reg_book_file = 'reg_book'
reg_book_obj = open(reg_book_file, 'r')
reg_book = pickle.load(reg_book_obj)

OP_BIT = 22
DST_BIT = 17
SRC0_BIT = 12
SRC1_BIT = 7
SRC2_BIT = 2
BASE_BIT = 2
OPERAND_WIDTH = 5
for program_bin_line in program_bin:
    instruction_line = int(program_bin_line)
    base = instruction_line % (1 << BASE_BIT)
    src1 = 0
    if base == 0:
        src1 = (instruction_line >> SRC1_BIT) % (1 << OPERAND_WIDTH)
    else:
        src1 = (instruction_line >> BASE_BIT) % (1 << (SRC0_BIT - BASE_BIT))
    src0 = (instruction_line >> SRC0_BIT) % (1 << OPERAND_WIDTH)
    dst = (instruction_line >> DST_BIT) % (1 << OPERAND_WIDTH)
    op = (instruction_line >> OP_BIT)
    operation = instruction_book[op]
    operation = operation[:(len(operation) - 1)]
    dst_reg = reg_book[dst]
    src0_reg = reg_book[src0]
    src1_reg = 0
    if base == 0:
        src1_reg = reg_book[src1]  
    else:
        src1_reg = src1
    print (operation + ' ' + dst_reg + ',' + src0_reg + ',' + str(src1_reg))
