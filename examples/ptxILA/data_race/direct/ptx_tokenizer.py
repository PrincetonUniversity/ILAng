import re
import pickle
test_file_name = 'add_neighbor_error.ptx'
test_file_obj = open(test_file_name, 'r')
test_file_code = test_file_obj.readlines()
instruction_book_file = 'instruction_book'
instruction_book_obj = open(instruction_book_file, 'r')
instruction_book = instruction_book_obj.readlines()
for i in range(len(instruction_book)):
    instruction_book[i] = instruction_book[i][:-1]
start_flag = '//start\n'

start_line = 0
for i in range(len(test_file_code)):
    if test_file_code[i] == start_flag:
        start_line = i + 1
        break
unchanged_code = test_file_code[:start_line]
process_code = test_file_code[start_line:]


shared_read_only_regs = []
type_map = {}
type_map['%tid.x'] = '.b32'
reg_pattern = re.compile(r'([_a-zA-Z\%\$]+)\<([0-9]+)\>',)
for i in range(len(unchanged_code)):
    a = re.split('\s|,|:', unchanged_code[i])
    a = filter(lambda a: a!='', a)
    unchanged_code[i] = a
    if len(a) >= 3:
        if a[0] == '.reg':
            match = reg_pattern.match(a[2])
            if match == None:
                type_map[a[2]] = a[1]
            else:
                name = match.group(1)
                num = int(match.group(2))
                for i in range(num):
                    type_map[name + str(i)] = a[1]
        if a[0] == '.param':
            type_map[a[2]] = a[1]

        if a[0] == ".shared":  #come from Nvidia matrix multiply example.
            shared_pattern = re.compile(r'([_0-9a-zA-Z\%\$]+)\[([0-9]+)\]')
            match = shared_pattern.match(a[4])
            if match == None:
                type_map[a[4]] = (a[2], a[3])
                shared_read_only_regs.append(a[4])
            else:
                name = match.group(1)
                num = int(match.group(2))
                shared_read_only_regs.append(name)
                for i in range(num):
                    type_map[name] = (a[2], a[3], match.group(2))
            # type_map[shared_memory_address] = (alignment, size-unit, total units)

process_code_split = []
for i in range(len(process_code)):
    a = re.split('\s|,|;', process_code[i])
    a = filter(lambda a: a != '', a)
    process_code[i] = a
ssa_counter = 0
reg_map = {}
parenthesis = []
parenthesis_re = re.compile(r'\[[a-zA-Z0-9\%\_\+]+\]')
for i in range(len(process_code)):
    for j in range(len(process_code[i])):
        if parenthesis_re.match(process_code[i][j]) != None:
            parenthesis.append((i, j))
            process_code[i][j] = process_code[i][j][1:-1]

#Remove ld.param
for i in range(len(process_code)):
    process_code_line = process_code[i]
    if len(process_code_line) < 1:
        continue
    opcode = process_code_line[0]
    opcode_split = re.split('\.', opcode)
    if (opcode_split[0] == 'ld'):
        if (opcode_split[1] == 'param'):
            process_code[i] = []
            shared_read_only_regs.append(process_code_line[1])
shared_read_only_obj = open('shared_read_only_regs', 'w')
pickle.dump(shared_read_only_regs, shared_read_only_obj)
shared_read_only_obj.close()

for i in range(len(process_code)):
    process_code_line = process_code[i]
    if len(process_code_line) < 1:
        continue
    opcode = process_code_line[0]
    if opcode[0] == '@':
        branch = opcode
        predicate_reg = branch[1:]
        process_code_line = [branch[0], predicate_reg] + process_code_line[1:]
        process_code[i] = process_code_line
        continue
for process_code_line in process_code:
    print process_code_line
'''
for i in range(len(process_code)):
    for j in range(len(process_code[i])):
        if (i, j) in parenthesis:
            process_code[i][j] = '[' + process_code[i][j] + ']' 

print_code = []
for i in range(len(process_code)):
    process_line = process_code[i]
    if len(process_line) == 0:
        print_line = '\n'
        print_code.append(print_line)
        continue
    if len(process_line) == 1:
        if process_line[0] in instruction_book:
            print_line = process_line[0] + ';' + '\n'
            print_code.append(print_line)
        else:
            print_code.append(process_line[0] + '\n')
        continue
    print_line = '    '
    print_flag = True
    for process_token in process_line:
        print_line += process_token
        if print_flag:
            print_line += '    '
            print_flag = False
        else:
            print_line += ' ,'
    print_line = print_line[:-2]
    print_line += ';\n'
    print_code.append(print_line)
ssa_print_code_obj = open('ssa_print_code.ptx', 'w')
ssa_print_code_obj.writelines(print_code)
ssa_print_code_obj.close()
'''
declaration_file = 'ptx_declaration_file'
declaration_obj = open(declaration_file, 'w')
pickle.dump(type_map, declaration_obj)
declaration_obj.close()
#print type_map

ssa_file = 'ptx_add_neighbor'
ssa_obj = open(ssa_file, 'w')
#ssa_obj.writelines(print_code)
pickle.dump(process_code, ssa_obj)
ssa_obj.close()
