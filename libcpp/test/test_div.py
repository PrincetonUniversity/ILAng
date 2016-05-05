import ila
import random

def main():
    c = ila.Abstraction("test")
    a = c.reg('a', 8)
    b = c.reg('b', 8)

    r = a % b
    for i in xrange(25):
        av = random.randint(0, 0xff)
        bv = random.randint(0, 0xff)

        if bv == 0:
            r = av
        else:
            r = av % bv

        assump = (a == av) & (b == bv)
        assert c.areEqual(assump, a % b, c.const(r, 8))
        print '%02x %% %02x = %02x' % (av, bv, r)

if __name__ == '__main__':
    main()
