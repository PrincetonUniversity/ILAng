import pickle
import re

ptx_program_file = 'ptx_add_neighbor'
ptx_program_obj = open(ptx_program_file, 'r')
ptx_program = pickle.load(ptx_program_obj)
ptx_program_obj.close()

ld_set = {}
st_set = {}
current_pc = 0
end_pc = 0
pc_target = {}
pc_start = {}
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
            dest = program_line[3]
            pc_start[program_line[3]] = current_pc
            tag_pred[program_line[3]] = program_line[1]
            temp_list = [tag_pred[program_line[3]], pc_target[program_line[3]]]
            branch_map[current_pc] = temp_list
            pred_list.append(program_line[1])
            temp_flag = []
            if (current_pc > branch_map[current_pc][1]):
                # loop
                temp_flag.append(current_pc+4)
                temp_flag.append(end_pc)
                temp_flag.append(branch_map[current_pc][1])
                temp_flag.append(current_pc)
            else:
                # normal jump
                temp_flag.append(current_pc+4)
                temp_flag.append(branch_map[current_pc][1]-4)
                temp_flag.append(branch_map[current_pc][1])
                temp_flag.append(end_pc)
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
                temp_pc_status.append('-'+pred_index)
            elif pc >= temp_flag[2] and pc <= temp_flag[3]:
                temp_pc_status.append(pred_index)
            else:
                continue
        pred_flag_map[pc] = temp_pc_status
        pc += 4

pc = 0
pred_map = {}
bar_pred_map = {}
for program_line in ptx_program:
    if len(program_line) >= 2:
        opcode = program_line[0]
        opcode_split = re.split('\.', opcode)
        if opcode_split[0] == 'ld':
            if opcode_split[1] != 'param':
                ld_set[pc] = program_line[2] 
                pred_map[pc] = []
                for tag in tag_pred.keys():
                    start = pc_start[tag]
                    target = pc_target[tag]
                    pred = tag_pred[tag]
                    if ((start < pc) & (target > pc)):
                        pred_map[pc].append(pred)
        if opcode_split[0] == 'st':
            st_set[pc] = program_line[1]
            pred_map[pc] = []
            for tag in tag_pred.keys():
                if ((pc_start[tag] < pc) & (pc_target[tag] > pc)):
                    pred_map[pc].append(tag_pred[tag])
        if opcode_split[0] == 'bar':
            bar_pred_map[pc] = []
            for tag in tag_pred.keys():
                if ((pc_start[tag] < pc) & (pc_target[tag] > pc)):
                    bar_pred_map[pc].append(tag_pred[tag])
        pc += 4

ld_set_obj = open('ld_set', 'w')
pickle.dump(ld_set, ld_set_obj)
st_set_obj = open('st_set', 'w')
pickle.dump(st_set, st_set_obj)
branch_map_obj = open('branch_map', 'w')
pickle.dump(branch_map, branch_map_obj)
pred_flag_map_obj = open('pred_flag_map', 'w')
pickle.dump(pred_flag_map, pred_flag_map_obj)
print pred_flag_map
pred_map_obj = open('pred_map', 'w')
pickle.dump(pred_map, pred_map_obj)
bar_pred_map_obj = open('bar_pred_map', 'w')
pickle.dump(bar_pred_map, bar_pred_map_obj)
ld_set_obj.close()
st_set_obj.close()
pred_map_obj.close()
bar_pred_map_obj.close()


