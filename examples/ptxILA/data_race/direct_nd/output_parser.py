import re
import pickle
from optparse import OptionParser
parser = OptionParser()
parser.add_option('-b', '--bmc_input', type = 'string', action = 'store', dest='bmc_file')
parser.add_option('-i', '--input', type = 'string', action = 'store', dest = 'input_file')
parser.add_option('-o', '--output', type = 'string', action = 'store', dest = 'output_file')
(options, args) = parser.parse_args()
bmc_obj = open(options.bmc_file, 'r')
bmc = bmc_obj.readlines()
bmc = bmc[:-1]
bmc_obj.close()

frame_list = []
i = 0
for bmc_line in bmc:
    if bmc_line[0:6] == '<Frame':
        frame_list.append(i)
    i += 1

frame_list.append(len(bmc))
frame_text = []
for i in range(len(frame_list) - 1):
    frame_text.append(bmc[frame_list[i] : frame_list[i + 1]])

rule_obj = open(options.input_file, 'r')
rule_list = rule_obj.readlines()
rule_obj.close()
rule = ''
for rule_text in rule_list:
    rule += (rule_text + '|')
rule = rule[:-1]

output_text = []
output_text.append(frame_text[0])
for i in range(1, len(frame_text)):
    current_frame = frame_text[i]
    last_frame = frame_text[i - 1]
    new_frame = []
    new_frame.append(current_frame[0])
    print len(current_frame)
    print len(last_frame)
    for j in range(1, len(current_frame)):
        if re.match(rule, current_frame[j]):
            new_frame.append(current_frame[j])
        else:
            if current_frame[j] != last_frame[j]:
                new_frame.append(current_frame[j])
    output_text.append(new_frame)

output_obj = open(options.output_file, 'w')
for frame in output_text:
    output_obj.writelines(frame)
output_obj.close()




