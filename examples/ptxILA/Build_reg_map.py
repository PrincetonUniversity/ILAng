import pickle

source_reg_file = 'test_reg_source.txt'
source_reg_obj = open(source_reg_file, 'r')
[reg_state_type_name_dict, reg_state_type_length_dict] = pickle.load(source_reg_obj)
reg_book = reg_state_type_name_dict.keys()

general_reg_book_file = 'general_reg_book'
general_reg_book_obj = open(general_reg_book_file, 'w')
pickle.dump(reg_book, general_reg_book_obj)

#special_reg_file = 'special_reg_book'
#special_reg_obj = open(special_reg_file, 'r')
#special_reg_book = special_reg_obj.readlines()
special_reg_book = []

#For barrier
reg_book.append('bar_counter_enter')
reg_book.append('bar_counter_exit')
reg_book.append('bar_state')

for special_reg in special_reg_book:
    reg_book.append(special_reg[:(len(special_reg) - 1)])

'''
reg_map = {}
for idx in range(len(reg_book)):
    reg_map[reg_book[idx]] = idx
#debug use
    print reg_book[idx]
    print idx
reg_map_file = 'reg_map'
reg_map_obj = open(reg_map_file, 'w')
pickle.dump(reg_map, reg_map_obj)
reg_map_obj.close()
'''
reg_book_file = 'reg_book'
reg_book_obj = open(reg_book_file, 'w')
pickle.dump(reg_book, reg_book_obj)
reg_book_obj.close()

long_int_reg_book_file = 'long_int_reg_book'
long_int_reg_book_obj = open(long_int_reg_book_file, 'r')
long_int_reg_book = pickle.load(long_int_reg_book_obj)
for long_int_reg in long_int_reg_book:
    reg_book.append(long_int_reg)
reg_map = {} 
for idx in range(len(reg_book)):
    reg_map[reg_book[idx]] = idx
#debug use
    print reg_book[idx]
    print idx
reg_map_file = 'reg_map'
reg_map_obj = open(reg_map_file, 'w')
pickle.dump(reg_map, reg_map_obj)
reg_map_obj.close()

source_reg_obj = open(source_reg_file, 'r')
[reg_state_type_name_dict, reg_state_type_length_dict] = pickle.load(source_reg_obj)
full_reg_book = reg_state_type_name_dict.keys()


special_reg_file = 'special_reg_book'
special_reg_obj = open(special_reg_file, 'r')
special_reg_book = special_reg_obj.readlines()

for special_reg in special_reg_book:
    full_reg_book.append(special_reg[:(len(special_reg) - 1)])

full_reg_map = {}
for idx in range(len(full_reg_book)):
    full_reg_map[full_reg_book[idx]] = idx
full_reg_map_file = 'full_reg_map'
full_reg_map_obj = open(full_reg_map_file, 'w')
pickle.dump(full_reg_map, full_reg_map_obj)
full_reg_map_obj.close()
full_reg_book_file = 'full_reg_book'
full_reg_book_obj = open(full_reg_book_file, 'w')
pickle.dump(full_reg_book, full_reg_book_obj)
full_reg_book_obj.close()



