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

type_map = {}
type_map['%tid.x'] = '.b32'
reg_pattern = re.compile(r'([_a-zA-Z\%\$]+)\<([0-9]+)\>',)
for i in range(len(unchanged_code)):
    a = re.split('\s|,|:', unchanged_code[i])
    a = filter(lambda a: a!='', a)
    unchanged_code[i] = a
    if len(a) == 3:
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

process_code_split = []
for i in range(len(process_code)):
    a = re.split('\s|,|;', process_code[i])
    a = filter(lambda a: a != '', a)
    process_code[i] = a
ssa_counter = 0
reg_map = {}
parenthesis = []
parenthesis_re = re.compile(r'\[[a-zA-Z0-9\%\_]+\]')
for i in range(len(process_code)):
    for j in range(len(process_code[i])):
        if parenthesis_re.match(process_code[i][j]) != None:
            parenthesis.append((i, j))
            process_code[i][j] = process_code[i][j][1:-1]

for i in range(len(process_code)):
    process_code_line = process_code[i]
    if len(process_code_line) < 2:
        continue
    opcode = process_code_line[0]
    op_type_length = re.split('\.', opcode)
    op = op_type_length[0]
    if op in instruction_book:
         for j in range(2, len(process_code_line)):
            sreg = process_code_line[j]
            while sreg in reg_map.keys():
                sreg = reg_map[sreg]
            process_code_line[j] = sreg
         if op == 'st':
            sreg = process_code_line[1]
            while sreg in reg_map.keys():
                sreg = reg_map[sreg]
            process_code_line[1] = sreg
            process_code[i] = process_code_line
            continue
         dest = process_code_line[1]
         reg_map[dest] = 's' + str(ssa_counter)
         process_code_line[1] = reg_map[dest]
         type_map[reg_map[dest]] = type_map[dest]
         ssa_counter += 1 
    process_code[i] = process_code_line
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
declaration_file = 'ssa_declaration_file.ptx'
declaration_content = []
for reg_name in type_map.keys():
    declaration_content.append('    .reg  ' + type_map[reg_name] + '  ' + reg_name + ';\n')
declaration_obj = open(declaration_file, 'w')
pickle.dump(type_map, declaration_obj)
declaration_obj.close()

ssa_file = 'ssa_add_neighbor.ptx'
ssa_obj = open(ssa_file, 'w')
#ssa_obj.writelines(print_code)
pickle.dump(process_code, ssa_obj)
ssa_obj.close()
