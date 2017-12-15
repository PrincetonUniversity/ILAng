import ila
import os
from random import randint

def main():
    c = ila.Abstraction("test")

    top = c.bool(True)
    bot = c.bool(False)

    x = c.reg('x', 8)
    y = c.reg('y', 8)

    g = c.fun('cnst', 8, [])
    h1 = ila.appfun(g, [])
    h2 = c.const(40, 8)
    c.add_assumption((h1 >= 10) & (h1 <= 15))
    val = ila.choice('val', h1, h2)
    res = val + x + y

    def sim(d):
        x = d['x']
        y = d['y']
        d_out = {}
        d_out['res'] = (x + y + randint(11, 12)) & 0xff
        return d_out

    res_s = c.syn_elem('res', res, sim)
    assert c.areEqual(res_s, h1 + x + y)

    z = c.reg('z', 16)
    c0 = c.const(0, 8)
    c1 = c.const(1, 8)
    cmax = c.const(255, 8)
    
    f = c.fun('foo', 8, [8, 16])
    r = ila.appfun(f, x, z)
    t = ila.appfun(f, y, z)
    eq = x == y
    req = r == t
    assert c.areEqual(ila.implies(eq, req), top)

    assert c.areEqual(r <= cmax, top)

    up = c.const(128, 8)
    down = c.const(120, 16)
    con = ila.implies((x < up) & (z > down), ila.appfun(f, x, z) > up)
    test = ila.implies(con & (x == 125) & (z == 125), ila.appfun(f, x, z) > up)
    assert c.areEqual(test, top)

    x_next = ila.appfun(f, y, z)
    c.set_next('x', x_next)

    exportFile = 'tmp/test_ila_export.txt'
    c.exportAll(exportFile)
    c.importAll(exportFile)

    simFile = 'tmp/test_ila_sim.hpp'
    c.generateSim(simFile)

if __name__ == '__main__':
    main()
