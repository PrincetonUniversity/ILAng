import pickle
import re

ptx_program_file = 'ptx_add_neighbor'
ptx_program_obj = open(ptx_program_file, 'r')
ptx_program = pickle.load(ptx_program_obj)
ptx_program_obj.close()

current_pc = 0
pc_target = {}
tag_pred = {}
# format: map[branch pc] = [p, target]
branch_map = {}
pred_list = []
# format: p -> [start pc with p = 0, end pc with p = 0, start pc with p = 1, end pc with p = 1]
flag_list = {}

for program_line in ptx_program:
    if len(program_line) < 2:
        if len(program_line) == 0:
            continue
        else:
            if program_line[0][-1] == ':':
                pc_target[program_line[0][:-1]] = current_pc
    else:
        current_pc += 4

end_pc = current_pc
current_pc = 0
for program_line in ptx_program:
    if len(program_line) >= 2:
        if program_line[0] == '@':
            tag_pred[program_line[3]] = program_line[1]
            temp_list = [tag_pred[program_line[3]], pc_target[program_line[3]]]
            branch_map[current_pc] = temp_list
            pred_list.append(program_line[1])
            temp_flag = []
            if (current_pc > branch_map[current_pc][1]):
                # loop
#                temp_flag.append(current_pc+4)
#                temp_flag.append(end_pc)
                temp_flag.append(branch_map[current_pc][1])
                temp_flag.append(current_pc)
                temp_flag.append('loop')
            else:
                # normal jump
                temp_flag.append(current_pc)
                temp_flag.append(branch_map[current_pc][1]-4)
                temp_flag.append('branch')
#                temp_flag.append(branch_map[current_pc][1])
#                temp_flag.append(end_pc)
            flag_list[branch_map[current_pc][0]] = temp_flag
        current_pc += 4

pc = 0
# format: map[pc] = [p0, p1, p2....] (%p1_0 means %p1 = 0, %p1_1 means %p1 = 1)
pred_flag_map = {}
for program_line in ptx_program:
    if len(program_line) >= 2:
        temp_pc_status = []
        for pred_index in pred_list:
            temp_flag = flag_list[pred_index]
            if pc >= temp_flag[0] and pc <= temp_flag[1]:
            	if temp_flag[2] == 'loop':
                	temp_pc_status.append(pred_index)
                elif temp_flag[2] == 'branch':
                	opcode_split = re.split('\.', program_line[0])
                	if opcode_split[0] == '@':
                		temp_pc_status.append(pred_index)
                	else:
                		temp_pc_status.append('-'+pred_index)
#            elif pc >= temp_flag[0] and pc <= temp_flag[1]:
#                temp_pc_status.append(pred_index)
            else:
                continue
        pred_flag_map[pc] = temp_pc_status
        pc += 4

branch_map_obj = open('branch_map', 'w')
pickle.dump(branch_map, branch_map_obj)
pred_flag_map_obj = open('pred_flag_map', 'w')
pickle.dump(pred_flag_map, pred_flag_map_obj)