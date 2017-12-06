import ila
import ptxSimMul
#import ptxILA
import ptxILANoBarMul
import pickle
reg_map_file = 'reg_map'

def synthesize():
    #ptxModel = ptxILA.ptxGPUModel()
    ptxModel = ptxILANoBarMul.ptxGPUModel()
    ptxSimulator = ptxSimMul.ptx_sim()
    ptxModel.model.set_next('pc', ptxModel.pc_nxt())
    ptxModel.model.set_next('mem', ptxModel.mem_nxt())
    ptxModel.model.set_next('dmem', ptxModel.dmem_nxt())
    reg_map_obj = open(reg_map_file, 'r')
    reg_map = pickle.load(reg_map_obj)
    reg_book_file = 'reg_book'
    reg_book_obj = open(reg_book_file, 'r')
    reg_book = pickle.load(reg_book_obj)
    long_int_reg_book_file = 'long_int_reg_book'
    long_int_reg_book_obj = open(long_int_reg_book_file, 'r')
    long_int_reg_book = pickle.load(long_int_reg_book_obj)
    
    reg_book.remove('bar_state')
    reg_book.remove('bar_counter_enter')
    reg_book.remove('bar_counter_exit')

    for i in range(len(reg_book)):
        ptxModel.model.set_next(reg_book[i], ptxModel.sreg_nxt(i))
    for i in range(len(long_int_reg_book)):
        ptxModel.model.set_next(long_int_reg_book[i], ptxModel.lreg_nxt(i))
    #for reg_name in reg_book:
    #    ptxModel.model.set_next(reg_name, ptxModel.sreg_nxt(reg_map[reg_name]))
    '''
    #synthesize bar
    for reg_name in reg_map.keys():
        if reg_name == 'bar_state':
            continue
        if reg_name == 'bar_counter_enter':
            continue
        if reg_name == 'bar_counter_exit':
            continue
        ptxModel.model.set_next(reg_name, ptxModel.sreg_nxt(reg_map[reg_name]))
    
    #test_reg = 'pc'
    #print 'start'
    synthesize_regs = ['pc', 'bar_state', 'bar_counter_enter', 'bar_counter_exit']
    '''
    '''
    synthesize_regs = reg_book + ['pc']
    for synthesize_reg in synthesize_regs:
        ptxModel.model.synthesize(synthesize_reg, lambda s:ptxSimulator.state_parser(s))
        ast = ptxModel.model.get_next(synthesize_reg)
        ptxModel.model.exportOne(ast, 'ast' + synthesize_reg)
    '''
    ptxModel.model.synthesize('%rd0', lambda s:ptxSimulator.state_parser(s))
    ptxModel.compare()

    
    #ptxModel.model.synthesize(test_reg, lambda s:ptxSimulator.state_parser(s))
    #ast = ptxModel.model.get_next(test_reg)
    #print ast
    #ptxModel.model.exportOne(ast, 'ast%r4')
    #ptxModel.compare()




if __name__ == '__main__':
    synthesize()
