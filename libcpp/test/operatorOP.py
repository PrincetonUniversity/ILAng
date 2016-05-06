import ila

def main():
    c = ila.Abstraction("test")
#    n = ila.Node()

    # test on boolOp
    top = c.bool(True)
    bot = c.bool(False)
    Band = (top & bot)      # 0
    Bor = (top | bot)       # 1
    Bxor = (Band ^ Bor)     # 1
    Bnor = ila.nor(Band, Bor)       # 0
    Bxnor = ila.xnor(Bxor, Bnor)    # 0
    Bnand = ila.nand(Bnor, Bxnor)   # 1
    nBnor = ~Bnor           # 1
    assert c.areEqual(nBnor, top)

    b1 = c.bit('b1')
    b2 = c.bit('b2')
    b3 = c.bit('b3')
    b4 = (b1 & b2) ^ b3
    b5 = ila.xnor(ila.nand(b1, b2), b3)
    assert c.areEqual(b4, b5)

    b6 = ila.ite(b1, b2, b3)
    b7 = (b1 & b2) | (~b1 & b3)
    assert c.areEqual(b6, b7)

    # test on bitvectorOp
    x = c.reg('x', 8)
    y = c.reg('y', 8)
    c0 = c.const(0, 8)
    c1 = c.const(1, 8)
    c2 = c.const(2, 8)
    c4 = c.const(4, 8)
    c6 = c.const(6, 8)
    c8 = c.const(8, 8)
    v1 = (x == c4)
    v2 = x << 1
    v3 = c4 << 1

    assert c.areEqual(c8, v3)
    assert c.areEqual(c8, (c4 + c4))
    assert c.areEqual(c4, (c8 - c4))
    assert c.areEqual(c8, (c4 * c2))
    assert c.areEqual(c4, (c8 / c2))
    v4 = ila.ite(v1, v2, v3)    # 8
    assert c.areEqual(v4, c8)
    assert c.areEqual(v4, v3)
    assert c.areEqual(v4, (4 + c4))
    assert c.areEqual(-c4, (c4 - 8))
    assert c.areEqual(v4, (2 * c4))
    assert c.areEqual(v4 >> 2, (v3 / c2) - 2)
    assert c.areEqual(c8 % 5, 7 % (1 << c2))
    assert c.areEqual( (x < y) ^ (y <= x), (x == y) | (x != y) )
    assert c.areEqual( (x > y) | (x == y) | ~(x >= y), top )
    assert c.areEqual( ~x ^ x, y ^ ~y)
    assert c.areEqual( ~x, ila.nand(x, x) )
    v5 = ~ila.nor(c2, c4)   # 00000110
    assert c.areEqual( ~v5, ila.xnor(c4, c2))
    v6 = c2 - c4    # 11111110
    v7 = 3 - c8     # 11111011
    v8 = ~(c2 - 2)  # 11111111
    assert c.areEqual( v8, ~c0)
    assert c.areEqual( v8 - 1, v6)
    assert c.areEqual( c4 + c1, -v7) # 00000101
    assert c.areEqual( ila.sdiv(c4, c2), c2)
    assert c.areEqual( ila.sdiv(-c4, c2), -c2)
    assert c.areEqual( ila.sdiv(v5, -4), -c1)
    assert c.areEqual( ila.srem(v5, -4), c2)
    # -6  = -4 * 1 + -2  ??
    assert c.areEqual( ila.sdiv(-6, -c4), c1)
    assert c.areEqual( ila.srem(-v5, -c4), -c2)
    assert c.areEqual( x - ila.srem(x, y), ila.sdiv(x, y) * y )
    assert c.areEqual( x - x % y, (x / y) * y )
    assert c.areEqual( ila.ashr(v6, 1), v8)
    assert c.areEqual( ila.slt(v7, v6), top)

    s1 = c.const(1, 4)
    s2 = c.const(2, 4)
    v9 = ila.concat(s1, s2) # 00010010
    v10 = (c1 << 4) + c2
    assert c.areEqual(v9, v10)
    v11 = ila.rrotate(v9, 2) # 10000100
    v12 = ila.lrotate(v9, 6)
    assert c.areEqual(v11, v12)
    s3 = c.const(9, 4)
    v13 = v9[4:1]
    assert c.areEqual(s3, v13)
    v14 = x[3:0]
    v15 = y[7:4]
    v16 = ila.concat(v15, v14)
    v17 = ((x << 4) >> 4) + ((y >> 4) << 4)
    assert c.areEqual(v16, v17)

    # imply
    v18 = ila.slt(x, 5)
    v19 = ila.sge(x, 5)
    c.areEqual(ila.implies(v18, ~v19), top)

    #nonzero & bool ite
    v20 = ila.ite( ila.nonzero(x), (x<7), ~(x>=7) )
    assert c.areEqual(v20, (x!=7) & ~(x>7))
    assert c.areEqual(ila.nonzero(c4), top)

    #add nonzero to ite
    assert c.areEqual( ila.ite(ila.nonzero(c2), top, bot), top)
    assert c.areEqual( ila.ite(ila.nonzero(c0), top, bot), bot)

    # zero/sign extend
    short = c4[3:0]
    recover = ila.zero_extend(short, 8)
    assert c.areEqual(recover, c4)

    longC4 = c.const(4, 16)
    nlongC4 = -longC4
    nshortC4 = -c4
    extNS4 = ila.sign_extend(nshortC4, 16)
    assert c.areEqual(nlongC4, extNS4)

    # extract/slice with var
    v21 = c0[3:0]
    v21r = ila.zero_extend(v21, 8)
    assert c.areEqual(c0, v21r)
    # v14 = x[3:0]
    v14ex = ila.zero_extend(v14, 8)
    v14re = (x << 4) >> 4
    assert c.areEqual(v14ex, v14re)
    # v15 = y[7:4]
    v15ex = ila.zero_extend(v15, 8)
    v15re = (y >> 4)
    assert c.areEqual(v15ex, v15re)
    """
    v21 = ila.extractIV(x, 3, c0)
    v22 = ila.extractVI(y, c4+3, 4)
    assert c.areEqual(v14ex, v21)
    assert c.areEqual(v15ex << 4, v22 << 4)

    v23 = v21 + (v22 << 4)
    assert c.areEqual(v23, v16)
    
    v24 = ila.extractVV(c8, c8-1, c0)
    assert c.areEqual(v24, c8)
    v25 = ila.extractVV(x, c8-1, c4)
    v26 = ila.zero_extend(x[7:4], 8)
    assert c.areEqual(v25, v26)

    # slice one bit
    bv1 = c.const(1, 1)
    s1 = ila.get_bit(c1, c0)
    assert c.areEqual(bv1, s1)
    """
    
    z = x & x
    bx = y[x]
    bz = y[z]
    assert c.areEqual(bx, bz)
    bx = c8[x]
    by = c8[y]
    inv = ila.implies(x == y, bx == by)
    assert c.areEqual(inv, top)
    dum = ila.ite(b1, bx, by)
    shd = ila.implies(x == y, dum == bx)
    assert c.areEqual(shd, top)
    assert c.areEqual(c6[1], c6[2])
    assert c.areEqual(c6[4], c6[c0])

if __name__ == '__main__':
    main()
