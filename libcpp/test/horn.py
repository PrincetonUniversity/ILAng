# This is a test playing with the horn clause transformation utilities.
import ila

def getDummyILA():
    A = ila.Abstraction("dummy")
    r0 = A.reg('r0', 8)
    r1 = A.reg('r1', 8)
    r2 = A.reg('r2', 8)

    r2_nxt = r0 + r1

    A.set_next('r2', r2_nxt)
    return A

def main():
    A = getDummyILA()
    ila.setloglevel(3, "")
    ila.enablelog("Horn")
    A.toHorn("tmp/horn_test_ILA.smt2")
    r2_nxt = A.get_next('r2')
    A.nodeToHorn(r2_nxt, "r2_nxt", "tmp/horn_test_node.smt2")


if __name__ == '__main__':
    main()
