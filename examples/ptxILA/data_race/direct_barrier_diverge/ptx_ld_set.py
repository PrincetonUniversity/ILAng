import pickle
import re

ptx_program_file = 'ptx_add_neighbor'
ptx_program_obj = open(ptx_program_file, 'r')
ptx_program = pickle.load(ptx_program_obj)
ptx_program_obj.close()

ld_set = {}
st_set = {}
current_pc = 0
pc_target = {}
pc_start = {}
tag_pred = {}
for program_line in ptx_program:
    if len(program_line) >= 2:
        if program_line[0] == '@':
            dest = program_line[3]
            pc_start[program_line[3]] = current_pc
            tag_pred[program_line[3]] = program_line[1]

        current_pc += 4
    else:
        if len(program_line) == 0:
            continue
        else:
            if program_line[0][-1] == ':':
                pc_target[program_line[0][:-1]] = current_pc

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
pred_map_obj = open('pred_map', 'w')
pickle.dump(pred_map, pred_map_obj)
bar_pred_map_obj = open('bar_pred_map', 'w')
pickle.dump(bar_pred_map, bar_pred_map_obj)
ld_set_obj.close()
st_set_obj.close()
pred_map_obj.close()
bar_pred_map_obj.close()


