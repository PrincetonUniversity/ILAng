import ila
import ptxSim
import ptxILA
import pickle
reg_map_file = 'reg_map'

def synthesize():
    ptxModel = ptxILA.ptxGPUModel()
    ptxSimulator = ptxSim.ptx_sim()
    ptxModel.model.set_next('pc', ptxModel.pc_nxt())
    ptxModel.model.set_next('mem', ptxModel.mem_nxt())
    reg_map_obj = open(reg_map_file, 'r')
    reg_map = pickle.load(reg_map_obj)
    for reg_name in reg_map.keys():
        if reg_name == 'bar_state':
            continue
        if reg_name == 'bar_counter_enter':
            continue
        if reg_name == 'bar_counter_exit':
            continue
        ptxModel.model.set_next(reg_name, ptxModel.sreg_nxt(reg_map[reg_name]))
    test_reg = 'bar_counter_exit'
    print 'start'
    ptxModel.model.synthesize(test_reg, lambda s:ptxSimulator.state_parser(s))
    ast = ptxModel.model.get_next(test_reg)
    print ast
#    ptxModel.model.exportOne(ast, 'ast%r4')
    ptxModel.compare()




if __name__ == '__main__':
    synthesize()
