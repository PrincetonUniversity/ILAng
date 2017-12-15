import pickle
import re

ptx_program_file = 'ptx_add_neighbor'
ptx_program_obj = open(ptx_program_file, 'r')
ptx_program = pickle.load(ptx_program_obj)
ptx_program_obj.close()

ld_set = {}
st_set = {}
pc = 0
for program_line in ptx_program:
    if len(program_line) >= 2:
        opcode = program_line[0]
        opcode_split = re.split('\.', opcode)
        if opcode_split[0] == 'ld':
            if opcode_split[1] != 'param':
                ld_set[pc] = program_line[2] 
        if opcode_split[0] == 'st':
            st_set[pc] = program_line[1]
        pc += 4

ld_set_obj = open('ld_set', 'w')
pickle.dump(ld_set, ld_set_obj)
st_set_obj = open('st_set', 'w')
pickle.dump(st_set, st_set_obj)
ld_set_obj.close()
st_set_obj.close()



