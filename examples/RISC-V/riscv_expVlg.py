import ila
import riscv_um

def genVlg():
    rm = riscv_um.riscvModel()
    rm.loadUnprivNxtFromDir('unpriv_asts')
    rm.model.generateVerilog('RISC-V-VLG.v')

if __name__ == '__main__':
    genVlg()
