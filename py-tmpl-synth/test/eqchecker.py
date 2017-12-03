import ila

def test():
    m1 = ila.Abstraction('t1')
    x1 = m1.reg('x', 8)
    y1 = m1.reg('y', 8)

    m1.set_next('x', x1)
    m1.set_init('x', m1.const(1, 8))
    m1.set_next('y', y1+x1)
    assert m1.areEqualUnrolled(3, y1, y1+3)
    assert not m1.areEqualUnrolled(3, y1, y1+4)

    m2 = ila.Abstraction('t2')
    y2 = m2.reg('y', 8)
    m2.set_next('y', y2+3)
    assert m2.areEqualUnrolled(3, y2, y2+9)
    assert not m2.areEqualUnrolled(3, y2, y2+10)

    assert ila.bmc(3, m2, y2, 9, m1, y1)
    assert not ila.bmc(4, m2, y2, 9, m1, y1)

def test2():
    m1 = ila.Abstraction('t1')
    x1 = m1.reg('x', 8)
    y1 = m1.reg('y', 8)
    f = m1.fun('foo', 8, [8])
    g = m1.fun('goo', 8, [8])

    m1.set_next('x', x1)
    m1.set_next('y', ila.appfun(f, x1))

    assert m1.areEqualUnrolled(1, y1, ila.appfun(f, x1))
    assert not m1.areEqualUnrolled(1, y1, ila.appfun(g, x1))

###### MICRO INST EQ Check #######


def test3():
    I1 = ila.Abstraction('a')
    inp1 = I1.inp('inp',1)
    r1 = I1.reg('r1'   ,5)
    
    I1.decode_exprs =  [inp1 == 1, inp1 ==0] 
    
    uI1 = I1.add_microabstraction( "mic", (r1!=0)&(r1<2) );
    
    I1.set_next('r1', ila.ite(inp1==1, I1.const(1,5), I1.const(0,5)))
    
    ur1 = uI1.reg('ur1',5)
    r1p = uI1.getreg('r1')
    uI1.set_init('ur1',uI1.const(0,5) )
    uI1.set_next('ur1',ur1+1)
    uI1.set_next('r1',ila.ite(ur1>5,ur1,r1p))
    
    #######################
    
    I2 = ila.Abstraction('b')
    inp2 = I2.inp('inp',1)
    r2 = I2.reg('r1'   ,5)
    
    uI2 = I2.add_microabstraction( "mic", (r2!=0)&(r2<2) );
    
    I2.set_next('r1', ila.ite(inp2==1, I2.const(1,5), I2.const(0,5)))
    
    I2.decode_exprs =  [inp2 == 1, inp2 ==0]
    ur2 = uI2.reg('ur1',5)
    r2p = uI2.getreg('r1')
    uI2.set_init('ur1',uI1.const(0,5) )
    uI2.set_next('ur1',ur2+3 )
    uI2.set_next('r1',ila.ite(ur2>5,ur2,r2p) )

    print 'simple signature test:'
    print ila.eqcheckSimple(I1,I2)
    
    print 'full test'
    u1 = I1.newUnroller(uI1, True)
    u1.addAssumption(inp1 == 1 )
    u1.unrollTo(20)
    u1.checkAssertion( ~ (uI1.fetch_valid) )
    u1.checkAssertion( r1 == 6 )
    
    
    u2 = I2.newUnroller(uI2, True)
    u2.addAssumption(inp2 == 1 )
    u2.unrollTo(20)
    u2.checkAssertion( ~ (uI2.fetch_valid) )
    u2.checkAssertion( r2 == 6 )
    
    print ila.eqcheck(u1,u2,'r1','r1')

def test4():
    I1 = ila.Abstraction('a')
    inp1 = I1.inp('inp',1)
    r1 = I1.reg('r1'   ,5)
    r1a= I1.reg('ra'   ,5)
    
    I1.decode_exprs =  [inp1 == 1, inp1 ==0] 
    
    uI1 = I1.add_microabstraction( "mic", (r1!=0)  );
    
    I1.set_next('r1', ila.ite(inp1==1, I1.const(1,5), I1.const(0,5)))
    I1.set_next('ra', r1a)
    
    ur1 = uI1.reg('ur1',5)
    
    r1p = uI1.getreg('r1')
    uI1.set_init('ur1',uI1.const(0,5) )
    uI1.set_next('ur1',ur1+1)
    
    ura1 = uI1.getreg('ra')
    uI1.set_next('ra', ura1 - 1 )    
    uI1.set_next('r1',ila.ite(ura1 == 1, I1.const(0,5),I1.const(1,5) ))
    
    #######################
    I2 = ila.Abstraction('b')
    inp2 = I2.inp('inp',1)
    r2 = I2.reg('r1'   ,5)
    r2a= I2.reg('ra'   ,5)
    
    I2.decode_exprs =  [inp2 == 1, inp2 ==0] 
    
    uI2 = I2.add_microabstraction( "mic", (r2!=0)  );
    
    I2.set_next('r1', ila.ite(inp2==1, I2.const(1,5), I2.const(0,5)))
    I2.set_next('ra', r2a)
    
    ur2 = uI2.reg('ur1',5)
    
    r2p = uI2.getreg('r1')
    uI2.set_init('ur1',uI2.const(0,5) )
    uI2.set_next('ur1',ur2+1)
    
    ura2 = uI2.getreg('ra')
    uI2.set_next('ra',uI2.getreg('ra') - 1 )    
    uI2.set_next('r1',ila.ite(ura2 == 1, I2.const(0,5),I2.const(1,5) ))
    
    

    print 'simple signature test:'
    print ila.eqcheckSimple(I1,I2)
    
    print 'full test'
    u1 = I1.newUnroller(uI1, False)
    u1.unrollTo(4)
    
    
    u2 = I2.newUnroller(uI2, False)
    u2.unrollTo(4)
    
    inductiveAssumpt = [(1,"r1","r1"), (1,"ra","ra"), (1,"ur1","ur1")]
    print ila.eqcheck(u1,u2,"r1","r1",inductiveAssumpt)
    print ila.eqcheck(u1,u2,"ra","ra",inductiveAssumpt)
    print ila.eqcheck(u1,u2,"ur1","ur1",inductiveAssumpt)




if __name__ == '__main__':
    test()
    test2()
    test3()
    test4()
