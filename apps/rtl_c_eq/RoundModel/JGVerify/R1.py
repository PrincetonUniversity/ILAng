import ila

innerTable = [
99,99,165,198,124,124,132,248,119,119,153,238,123,123,141,246,
242,242,13,255,107,107,189,214,111,111,177,222,197,197,84,145,48,
48,80,96,1,1,3,2,103,103,169,206,43,43,125,86,254,254,25,231,215,
215,98,181,171,171,230,77,118,118,154,236,202,202,69,143,130,130,
157,31,201,201,64,137,125,125,135,250,250,250,21,239,89,89,235,178,
71,71,201,142,240,240,11,251,173,173,236,65,212,212,103,179,162,
162,253,95,175,175,234,69,156,156,191,35,164,164,247,83,114,114,150,
228,192,192,91,155,183,183,194,117,253,253,28,225,147,147,174,61,38,
38,106,76,54,54,90,108,63,63,65,126,247,247,2,245,204,204,79,131,52,
52,92,104,165,165,244,81,229,229,52,209,241,241,8,249,113,113,147,226,
216,216,115,171,49,49,83,98,21,21,63,42,4,4,12,8,199,199,82,149,35,35,
101,70,195,195,94,157,24,24,40,48,150,150,161,55,5,5,15,10,154,154,181,
47,7,7,9,14,18,18,54,36,128,128,155,27,226,226,61,223,235,235,38,205,
39,39,105,78,178,178,205,127,117,117,159,234,9,9,27,18,131,131,158,
29,44,44,116,88,26,26,46,52,27,27,45,54,110,110,178,220,90,90,238,180,
160,160,251,91,82,82,246,164,59,59,77,118,214,214,97,183,179,179,206,
125,41,41,123,82,227,227,62,221,47,47,113,94,132,132,151,19,83,83,245,
166,209,209,104,185,0,0,0,0,237,237,44,193,32,32,96,64,252,252,31,227,
177,177,200,121,91,91,237,182,106,106,190,212,203,203,70,141,190,190,217,
103,57,57,75,114,74,74,222,148,76,76,212,152,88,88,232,176,207,207,74,133,
208,208,107,187,239,239,42,197,170,170,229,79,251,251,22,237,67,67,197,134,
77,77,215,154,51,51,85,102,133,133,148,17,69,69,207,138,249,249,16,233,2,2,
6,4,127,127,129,254,80,80,240,160,60,60,68,120,159,159,186,37,168,168,227,75,
81,81,243,162,163,163,254,93,64,64,192,128,143,143,138,5,146,146,173,63,157,
157,188,33,56,56,72,112,245,245,4,241,188,188,223,99,182,182,193,119,218,218,
117,175,33,33,99,66,16,16,48,32,255,255,26,229,243,243,14,253,210,210,109,191,
205,205,76,129,12,12,20,24,19,19,53,38,236,236,47,195,95,95,225,190,151,151,
162,53,68,68,204,136,23,23,57,46,196,196,87,147,167,167,242,85,126,126,130,
252,61,61,71,122,100,100,172,200,93,93,231,186,25,25,43,50,115,115,149,230,
96,96,160,192,129,129,152,25,79,79,209,158,220,220,127,163,34,34,102,68,42,
42,126,84,144,144,171,59,136,136,131,11,70,70,202,140,238,238,41,199,184,
184,211,107,20,20,60,40,222,222,121,167,94,94,226,188,11,11,29,22,219,219,
118,173,224,224,59,219,50,50,86,100,58,58,78,116,10,10,30,20,73,73,219,
146,6,6,10,12,36,36,108,72,92,92,228,184,194,194,93,159,211,211,110,189,
172,172,239,67,98,98,166,196,145,145,168,57,149,149,164,49,228,228,55,211,
121,121,139,242,231,231,50,213,200,200,67,139,55,55,89,110,109,109,183,218,
141,141,140,1,213,213,100,177,78,78,210,156,169,169,224,73,108,108,180,216,
86,86,250,172,244,244,7,243,234,234,37,207,101,101,175,202,122,122,142,244,
174,174,233,71,8,8,24,16,186,186,213,111,120,120,136,240,37,37,111,74,46,
46,114,92,28,28,36,56,166,166,241,87,180,180,199,115,198,198,81,151,232,
232,35,203,221,221,124,161,116,116,156,232,31,31,33,62,75,75,221,150,189,
189,220,97,139,139,134,13,138,138,133,15,112,112,144,224,62,62,66,124,181,
181,196,113,102,102,170,204,72,72,216,144,3,3,5,6,246,246,1,247,14,14,18,
28,97,97,163,194,53,53,95,106,87,87,249,174,185,185,208,105,134,134,145,
23,193,193,88,153,29,29,39,58,158,158,185,39,225,225,56,217,248,248,19,
235,152,152,179,43,17,17,51,34,105,105,187,210,217,217,112,169,142,142,
137,7,148,148,167,51,155,155,182,45,30,30,34,60,135,135,146,21,233,233,
32,201,206,206,73,135,85,85,255,170,40,40,120,80,223,223,122,165,140,140,
143,3,161,161,248,89,137,137,128,9,13,13,23,26,191,191,218,101,230,230,49,
215,66,66,198,132,104,104,184,208,65,65,195,130,153,153,176,41,45,45,119,90,
15,15,17,30,176,176,203,123,84,84,252,168,187,187,214,109,22,22,58,44 ]

def fulltable(tab):
    expr = tab
    for i in range(1024):
        idx = ila.const(i, 10)
        val = ila.const(innerTable[i],8)
        expr = ila.store(expr, idx, val)
    return expr

def tableR(inp):
    expr = ila.const(0,8)
    for i in range(1024):
        val = ila.const(innerTable[i],8)
        expr = ila.ite(inp == i, val, expr )
    return expr

# endian is set to be the same as verilog
# need SWAP for C
def _32toL(_32):
    retL = []
    for bidx in range(3,-1,-1):
        retL.append( _32[(bidx*8+7):(bidx*8)] )
    return retL

def Lto32(l):
    return ila.concat( [l[0], l[1], l[2], l[3]] )

def sub_byte(w, tab): # modify in place
    w[0] = tableR( ila.concat([w[0], ila.const(0,2) ]) )
    w[1] = tableR( ila.concat([w[1], ila.const(0,2) ]) )
    w[2] = tableR( ila.concat([w[2], ila.const(0,2) ]) )
    w[3] = tableR( ila.concat([w[3], ila.const(0,2) ]) )

def rot_up_8(x): # word # we assume little endian, so right is
    return [x[3],x[0],x[1],x[2]]
def rot_16(x):
    return [x[2],x[3],x[0],x[1]]
def rot_down_8(x):
    return [x[1],x[2],x[3],x[0]]

def table_lookup(b,tab, byte0): # modify p
    retList = [0,0,0,0]
    retList[0] = [ tableR( ila.concat([b[0], ila.const(0,2) ]) ) , tableR( ila.concat([b[0], ila.const(1,2) ]) ), tableR( ila.concat([b[0], ila.const(2,2) ]) ), tableR( ila.concat([b[0], ila.const(3,2) ]) ) ]
    retList[1] = [ tableR( ila.concat([b[1], ila.const(0,2) ]) ) , tableR( ila.concat([b[1], ila.const(1,2) ]) ), tableR( ila.concat([b[1], ila.const(2,2) ]) ), tableR( ila.concat([b[1], ila.const(3,2) ]) ) ]
    retList[2] = [ tableR( ila.concat([b[2], ila.const(0,2) ]) ) , tableR( ila.concat([b[2], ila.const(1,2) ]) ), tableR( ila.concat([b[2], ila.const(2,2) ]) ), tableR( ila.concat([b[2], ila.const(3,2) ]) ) ]
    retList[3] = [ tableR( ila.concat([b[3], ila.const(0,2) ]) ) , tableR( ila.concat([b[3], ila.const(1,2) ]) ), tableR( ila.concat([b[3], ila.const(2,2) ]) ), tableR( ila.concat([b[3], ila.const(3,2) ]) ) ]
    return retList

def rot(pList): # modify in place
    pList[0] = rot_up_8(pList[0])
    pList[1] = rot_16(pList[1])
    pList[2] = rot_down_8(pList[2])

def xor(aList,bList):
    return [ aList[i] ^ bList[i] for i in range(4) ]

def buildTemplate():
    aes = ila.Abstraction('aesr')

    def _debug_print(dvar):
        aes.set_next('debug', Lto32(dvar))

    byte0 = ila.const(0,8)

    key0 = aes.reg('in_key0',32)
    key1 = aes.reg('in_key1',32)
    key2 = aes.reg('in_key2',32)
    key3 = aes.reg('in_key3',32)

    state0 = aes.reg('state0',32)
    state1 = aes.reg('state1',32)
    state2 = aes.reg('state2',32)
    state3 = aes.reg('state3',32)

    debug = aes.reg('debug',32)

    #table0 = aes.mem('table',10,8)
    rcon = aes.reg('rcon',8)
    i = aes.reg('i',4)

    aes.set_init('rcon', ila.const(1,8) )
    aes.set_init('i', ila.const(1,4) )
    # round 1
    # but not the last one
    tab = 0

    [k0,k1,k2,k3] = [key0,key1,key2,key3]
    stateL = [state0,state1,state2,state3]
    
    stateL[0] = ila.ite(i==1, stateL[0] ^ k0, stateL[0] )
    stateL[1] = ila.ite(i==1, stateL[1] ^ k1, stateL[1] )
    stateL[2] = ila.ite(i==1, stateL[2] ^ k2, stateL[2] )
    stateL[3] = ila.ite(i==1, stateL[3] ^ k3, stateL[3] )

    k0 = _32toL(key0)
    k1 = _32toL(key1)
    k2 = _32toL(key2)
    k3 = _32toL(key3)
    for idx in range(4):
        stateL[idx] = _32toL(stateL[idx])


    tempL = k3        
    tempL = rot_down_8(tempL)
    sub_byte(tempL, tab)
    tempL = xor(tempL, [rcon,byte0, byte0, byte0] )

    j = ila.sign_extend(rcon, 32 )
    j = j << 1
    j = j ^ ( (j>>8)&ila.const(0x1b,32) )
    rcon = j[7:0] # set next ?

    k0 = xor(k0, tempL)
    k1 = xor(k1, k0)
    k2 = xor(k2, k1)
    k3 = xor(k3, k2)

    z0 = k0[:]; z1 = k1[:]; z2 = k2[:]; z3 = k3[:]
    bList = stateL[0] # this is a list
    pListWord = table_lookup(bList, tab, byte0)
    _debug_print(pListWord[0])
    rot(pListWord)
    z0 = xor(z0,pListWord[0]); z3 = xor(z3,pListWord[1]); z2 = xor(z2,pListWord[2]); z1 = xor(z1,pListWord[3])

    bList = stateL[1]
    pListWord = table_lookup(bList, tab, byte0)
    rot(pListWord)
    z1= xor(z1,pListWord[0]); z0 = xor(z0,pListWord[1]); z3 = xor(z3,pListWord[2]); z2 = xor(z2,pListWord[3])

    bList = stateL[2]
    pListWord = table_lookup(bList, tab, byte0)
    rot(pListWord)
    z2= xor(z2,pListWord[0]); z1 = xor(z1,pListWord[1]); z0 = xor(z0,pListWord[2]); z3 = xor(z3,pListWord[3])


    bList = stateL[3]
    pListWord = table_lookup(bList, tab, byte0)
    rot(pListWord)

    stateL[0] = xor(z0, pListWord[3])
    stateL[1] = xor(z1, pListWord[2])
    stateL[2] = xor(z2, pListWord[1])
    stateL[3] = xor(z3, pListWord[0])

    stateL[0] = Lto32(stateL[0])
    stateL[1] = Lto32(stateL[1])
    stateL[2] = Lto32(stateL[2])
    stateL[3] = Lto32(stateL[3])

    k0 = Lto32(k0)
    k1 = Lto32(k1)
    k2 = Lto32(k2)
    k3 = Lto32(k3)

    # set next to stateList

    aes.set_next('state0', stateL[0] )
    aes.set_next('state1', stateL[1] )
    aes.set_next('state2', stateL[2] )
    aes.set_next('state3', stateL[3] )

    aes.set_next('i', i+1 )
    aes.set_next('rcon', rcon)

    aes.set_next('in_key0', k0 )
    aes.set_next('in_key1', k1 )
    aes.set_next('in_key2', k2 )
    aes.set_next('in_key3', k3 )

    aes.set_next('debug',debug);
    return aes

def main():
    aes = buildTemplate()
    #aes.generateCbmcC('cbmcAes.c')


if __name__ == '__main__':
    main()