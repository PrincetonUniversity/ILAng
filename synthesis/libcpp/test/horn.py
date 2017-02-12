# This is a test playing with the horn clause transformation utilities.
import ila
import os

def getDummyILA():
    A = ila.Abstraction("dummy")
    r0 = A.reg('r0', 8)
    r1 = A.reg('r1', 8)
    r2 = A.reg('r2', 8)

    r2_nxt = r0 + r1

    A.set_next('r2', r2_nxt)
    return A

def main():
    iteAsNode = False
    iteAsNode = True
    hornFile = "tmp/horn_test_node.smt2"
    A = getDummyILA()
    ila.setloglevel(3, "")
    ila.enablelog("Horn")
    A.hornifyAll("tmp/horn_test_ILA.smt2")
    r2_nxt = A.get_next('r2')
    A.hornifyNode(r2_nxt, "r2_nxt")
    A.exportHornToFile(hornFile)

    m = ila.Abstraction("fun")
    x = m.reg ('x', 8)
    y = m.reg ('y', 16)
    f = m.fun ('foo', 8, [8, 16])
    r = ila.appfun (f, x, y)
    m.hornifyBvAsInt (True)
    m.hornifyNode (r, "foo")
    m.exportHornToFile (hornFile)

    alu = ila.Abstraction("alu")
    alu.hornifyBvAsInt(True)
    aluFile = 'tmp/alu.txt'
    if not os.path.exists (aluFile):
        print 'alu file not exist'
        return
    alu.importAll(aluFile)
    r0_nxt = alu.get_next('r0')
    r1_nxt = alu.get_next('r1')
    pc_nxt = alu.get_next('pc')
    rom_nxt = alu.get_next('rom')
    """
    alu.hornifyNode(pc_nxt, "pc_nxt")
    alu.hornifyNode(r0_nxt, "r0_nxt")
    alu.hornifyNode(r1_nxt, "r1_nxt")
    alu.hornifyNode(rom_nxt, "rom_nxt")
    alu.exportHornToFile(hornFile)
    """

    alu.addHornInstr ('alu_instr', alu.bool(True))
    alu.addHornNext ('alu_instr', 'pc', pc_nxt)
    alu.addHornNext ('alu_instr', 'r0', r0_nxt)
    alu.addHornNext ('alu_instr', 'r1', r1_nxt)
    alu.addHornNext ('alu_instr', 'rom', rom_nxt)

    alu.addHornChild ('alu_child', 'alu_instr', alu.bool(True))
    alu.addHornNext ('alu_child', 'pc', pc_nxt)
    alu.addHornNext ('alu_child', 'r0', r0_nxt)
    alu.addHornNext ('alu_child', 'r1', r1_nxt)
    alu.addHornNext ('alu_child', 'rom', rom_nxt)
    alu.generateHornMapping ('Interleave')
    #alu.generateHornMapping ('Blocking')
    alu.exportHornToFile (hornFile)

    
if __name__ == '__main__':
    main()
