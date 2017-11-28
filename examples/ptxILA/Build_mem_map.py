import pickle

source_mem_file = 'test_ld_mem_source.txt'
source_mem_obj = open(source_mem_file, 'r')
[mem_state_type_name_dict, mem_state_type_length_dict, mem_state_size_dict] = pickle.load(source_mem_obj)
mem_book = mem_state_type_name_dict.keys()
mem_map = {}
start_address = 0x00000000
for mem in mem_book:
    mem_all_dim_size = mem_state_size_dict[mem]
    mem_map[mem] = [start_address]
    mem_size = 0x4
    for mem_each_dim_size in mem_all_dim_size:
        dim_size = int(mem_each_dim_size[1:(len(mem_each_dim_size) - 1)])
	mem_size *= dim_size
    start_address += mem_size
    mem_map[mem].append(start_address)

max_addr_size = start_address
mem_map_file = 'mem_map'
mem_map_obj = open(mem_map_file, 'w')
pickle.dump([mem_map, max_addr_size], mem_map_obj)
mem_map_obj.close()

