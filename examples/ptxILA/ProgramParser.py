import re
import pickle

source_file = "test.ptx"
source_obj = open(source_file)
try:
    source_code = source_obj.readlines()
finally:
    source_obj.close()

#Remove comment with /**/
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

#Remove comment with //
for source_line in source_code:
    if source_line.find('//') == -1:
        instruction_lines.append(source_line)
    else:
        instruction_lines.append(source_line[0:source_line.find('//')])

source_code = instruction_lines
instruction_lines = []

#Get rid of directive statements
pattern = re.compile(r'\A[\s]*\.[^\s]+')
for source_line in source_code:
    match_flag = pattern.match(source_line)
    if not match_flag:
        instruction_lines.append(source_line)

#Get rid of blank lines
pattern = re.compile(r'\A[\s]*$')
source_code = instruction_lines
instruction_lines = []
for source_line in source_code:
    match_flag = pattern.match(source_line)
    if not match_flag:
        instruction_lines.append(source_line)

#Get rid of comma,;
source_code = instruction_lines
instruction_lines = []
for source_line in source_code:
    source_line = source_line.replace(',', '')
    source_line = source_line.replace(';', '')
    instruction_lines.append(source_line)

#Split lines
source_code = instruction_lines
instruction_lines = []
for source_line in source_code:
    instruction_lines.append(source_line.split())

#Delete type eg:.b32
source_lines = instruction_lines
instruction_lines = []
for source_line in source_lines:
    token = source_line[0]
    source_rest = source_line[1:]
    if token[len(token) - 1] == ':':
        if len(source_line) > 1:
            instruction_lines.append([source_line[0]])
            token = source_line[1]
            source_rest = source_line[2:]
            source_line = []
        else:
            instruction_lines.append(source_line)
            continue
    else:
        source_line = []
    token_split = token.split('.')
    source_line.append(token_split[0])
    for rest in source_rest:
        source_line.append(rest)
    instruction_lines.append(source_line)

for instruction_line in instruction_lines:
    for token in instruction_line:
        print token,
    print ' '

#There are 3 types of code now: 
# xxxx: opcode oprands
# opcode operands
# @p opcode oprands
program_file = 'program_' + source_file
program_obj = open(program_file, 'w')
pickle.dump(instruction_lines, program_obj)
program_obj.close()

