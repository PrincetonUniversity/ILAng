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

real_program = {}
pred_map = {}
for program_line in ptx_program:
    if len(program_line) < 2:
        if len(program_line) == 0:
            continue
        else:
            if program_line[0][-1] == ':':
                pc_target[program_line[0][:-1]] = current_pc
    else:
        pred_map[current_pc] = []
        real_program[current_pc] = program_line
        current_pc += 4

end_pc = current_pc
current_pc = 0

for program_line in ptx_program:
    if len(program_line) >= 2:
        if program_line[0] == '@':
            preds = []
            for p in pred_map[current_pc]:
                preds.append(p)
            pred_map[current_pc].append(program_line[1])
            target = pc_target[program_line[3]]
            flag = True
            loop_pc = current_pc + 4
            neg_str ='-' + program_line[1]
            preds += [neg_str]
            print preds
            while(flag):
                flag = False
                for neg_pc in range(loop_pc, target, 4):
                    print neg_pc
                    for pred in preds:
                        if pred not in pred_map[neg_pc]:
                            pred_map[neg_pc].append(pred)
                    program_context = real_program[neg_pc]
                    if len(program_context) < 1:
                        continue
                    opcode = program_context[0].split('.')
                    if len(opcode) > 0:
                        if opcode[0] == 'bra':
                            flag = True
                            loop_pc = pc_target[program_context[1]]
                            target = end_pc
                            for next_pc in range(loop_pc, target, 4):
                                if len(real_program[next_pc]) >= 2:
                                    if real_program[next_pc][0] == '@':
                                        target = next_pc + 4
                                        break
                            break
            flag = True
            loop_pc = pc_target[program_line[3]]
            target = end_pc
            preds[-1] = program_line[1]
            while(flag):
                flag = False
                for pos_pc in range(loop_pc, target, 4):
                    for pred in preds:
                        if pred not in pred_map[pos_pc]:
                            pred_map[pos_pc].append(pred)
                    program_context = real_program[pos_pc]
                    if len(program_context) < 1:
                        continue
                    opcode = program_context[0].split('.')
                    if len(opcode) > 0:
                        if opcode[0] == 'bra':
                            flag = True
                            loop_pc = pc_target[program_context[1]]
                            target = end_pc
                            for next_pc in range(loop_pc, target, 4):
                                if len(real_program[next_pc]) >= 2:
                                    if real_program[next_pc][0] == '@':
                                        target = next_pc + 4
                                        break
                            break
        current_pc += 4
for key in pred_map.keys():
    for v in pred_map[key]:
        if ('-' + v) in pred_map[key]:
            pred_map[key].remove(v)
            pred_map[key].remove('-' + v)
print pred_map
obj = open('pred_map', 'w')
pickle.dump(pred_map, obj)
obj.close()
