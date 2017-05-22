import ila
import riscv_um
import riscv_inst
import riscv_sim

def synthesize():
    rm = riscv_um.riscvModel()
    riscv_inst.AddInst(rm)
    sim = riscv_sim.RiscVSim()

    for state in riscv_sim.GPRList+['mem'] : #riscv_sim.GPRList+['mem']:
        print 'syn: ',state
        sim.SetSynState(state)
        rm.model.synthesize(state, lambda s:sim.Sim(s) )
        ast = rm.model.get_next(state)
        print ast
        rm.model.exportOne(ast, 'asts/%s'%state)

if __name__ == '__main__':
    synthesize()


