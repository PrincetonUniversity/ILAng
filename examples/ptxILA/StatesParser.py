import re

REGTOKEN = ".reg"
SPECREGTOKEN = ".sreg"
CONSTTOKEN = ".const"
GLOBALMEMTOKEN = ".global"
LOCALTOKEN = ".local"
source_file = "test.ptx"
source_obj = open(source_file)
try:
	source_code = source_obj.readlines()
finally:
	source_obj.close()

reg_states_dict = {}
mem_states_dict = {}
for source_line in source_code:
	dot = source_line[0]
	if dot != '.':
		continue
	source_tokens = source_line.split()
	if source_tokens[0] == REGTOKEN:
		reg_infos = source_tokens[1:]
		current_type = 'int64'
		for reg_info in reg_infos:
			if reg_info[0] == '.':
				current_type = reg_info[1:]
			else:
				reg_states_dict[reg_info] = current_type
	if source_tokens[0] == GLOBALMEMTOKEN:
		mem_infos = source_tokens[1:]
		current_type = 'int64'
		for mem_info in mem_infos:
			if mem_info[0] == ".":
				current_type = mem_info[1:]
			else:
				mem_states_dict[mem_info] = current_type



#test use
pattern = re.compile(r'[a-zA-Z0-9_\[\]]+(?=[,;$])')
reg_state_type_name_dict = {}
reg_state_type_length_dict = {}
for reg_key in reg_states_dict.keys():
	state_type = reg_states_dict[reg_key]
	type_pattern = re.compile(r'[a-zA-Z]+')
	type_name = type_pattern.findall(state_type)
	type_length = type_pattern.split(state_type)
	reg_state_type_name_dict[pattern.match(reg_key).group()] = type_name[0]
	reg_state_type_length_dict[pattern.match(reg_key).group()] = type_length[1]

for reg_key in reg_state_type_name_dict.keys():
	print (reg_key + ' ' + reg_state_type_name_dict[reg_key] + ' ' + reg_state_type_length_dict[reg_key])

for mem_key in mem_states_dict.keys():
#TODO: if the type of mem_dim_group is Nonetype, then keep the mem_state_key_with_dim as mem_state_key_name, else use split to get the mem_state_key_name
	state_type = mem_states_dict[mem_key]
	type_pattern = re.compile(r'[a-zA-Z]+')
	type_name = type_pattern.findall(state_type)
	type_length = type_pattern.split(state_type)
	mem_state_key_with_dim = pattern.match(mem_key).group()
	print(mem_state_key_with_dim)
	mem_dim_pattern = re.compile(r'\[[a-zA-Z0-9]+\]')
	mem_dim_group = mem_dim_pattern.findall(mem_state_key_with_dim)
	mem_name_group = mem_dim_pattern.split(mem_state_key_with_dim)
	for mem_dim in mem_dim_group:
		print(mem_dim)
	for mem_name in mem_name_group:
		print(mem_name)



#TODO: write dictionary from reg_state_name to reg_state_type into a file
#      write dictionary from mem_state_name ot mem_state_tyep into a file
'''
#test for regular expression	
	for reg_key in reg_states_dict.keys():
		print (pattern.match(reg_key).group() + ' ' + reg_states_dict[reg_key])
	for mem_key in mem_states_dict.keys():
		print (pattern.match(mem_key).group() + ' ' + mem_states_dict[mem_key])
'''