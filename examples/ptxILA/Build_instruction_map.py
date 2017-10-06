import pickle
instruction_book_obj = open('instruction_book', 'r')
try:
    instruction_book = instruction_book_obj.readlines()
finally:
    instruction_book_obj.close()

instruction_map = {}
for iter in range(len(instruction_book)):
    instruction_map[instruction_book[iter][:(len(instruction_book[iter]) - 1)]] = iter
#    debug
    print(instruction_book[iter][:(len(instruction_book[iter]) - 1)])
instruction_map_file = 'instruction_map'
instruction_map_obj = open(instruction_map_file, 'w')
pickle.dump(instruction_map, instruction_map_obj)
instruction_map_obj.close()
