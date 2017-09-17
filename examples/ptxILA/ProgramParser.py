import re
import pickle

source_file = "test.ptx"
source_obj = open(source_file)
try:
    source_code = source_obj.readlines()
finally:
    source_obj.close()

instruction_lines = []
comment_flag = False
for source_line in source_code:
    if comment_flag:
        if source_line.find('*/') == -1:
	    continue
	else:
	    instruction_lines.append(source_line[source_line.find('*/'):])
	    comment_flag = False
    else:
        if source_line.find('/*') == -1:
	    instruction_lines.append(source_line)
	    continue
	else:
	    instruction_lines.append(source_line[:source_line.find('/*')])
	    comment_flag = True

source_code = instruction_lines
instruction_lines = []

for source_line in source_code:
    if source_line.find('//') == -1:
        instruction_lines.append(source_line)
    else:
        instruction_lines.append(source_line[0:source_line.find('//')])

source_code = instruction_lines
instruction_lines = []

pattern = re.compile(r'\A[\s]*\.[^\s]+')
for source_line in source_code:
    match_flag = pattern.match(source_line)
    if not match_flag:
        instruction_lines.append(source_line)

pattern = re.compile(r'\A[\s]*$')
source_code = instruction_lines
instruction_lines = []
for source_line in source_code:
    match_flag = pattern.match(source_line)
    if not match_flag:
        instruction_lines.append(source_line)


for instruction_line in instruction_lines:
    print instruction_line

