import ila

# help class for FixPoint:
class fixpointTemp:
    def __init__(self, w, i ,sign = False):
        self.w = w; self.i = i; self.sign = sign;

def lct_align(fp1, fp2):
    i_max = max(fp1.i , fp2.i)
    frac_max = max(fp1.w - fp1.i, fp2.w - fp2.i)
    w = frac_max + i_max

    pl = ila.sign_extend(fp1.ast,w) if fp1.sign else ila.zero_extend(fp1.ast,w) 
    pr = ila.sign_extend(fp2.ast,w) if fp2.sign else ila.zero_extend(fp2.ast,w) 

    pl = pl << (frac_max - (fp1.w - fp1.i) ) if (fp1.w - fp1.i) < frac_max else pl
    pr = pr << (frac_max - (fp2.w - fp2.i) ) if (fp2.w - fp2.i) < frac_max else pr

    osign = fp1.sign or fp2.sign

    return (pl,pr, fixpointTemp(w,i_max,osign) )

    
def lct_mul(fp1, fp2):
    i = fp1.i + fp2.i
    frac = fp1.w - fp1.i + fp2.w - fp2.i
    w = i + frac

    if fp1.sign == False:
        ast1 = ila.zero_extend(fp1.ast, w)
    else:
        ast1 = ila.sign_extend(fp1.ast, w)

    if fp2.sign == False:
        ast2 = ila.zero_extend(fp2.ast, w)
    else:
        ast2 = ila.sign_extend(fp2.ast, w)
    return (ast1, ast2, fixpointTemp(w, i, fp1.sign or fp2.sign) )



class fixpoint:
    def __init__(self, ast, temp):
        self.ast = ast
        self.w   = temp.w
        self.i   = temp.i
        self.sign = temp.sign

    def getTemp(self):
        return fixpointTemp(self.w,self.i,self.sign)

    def asSign(self):
        return fixpoint(self.ast,fixpointTemp(self.w,self.i,True))
    def asUnsign(self):
        return fixpoint(self.ast,fixpointTemp(self.w,self.i,False))
    def toFormat(self, w, i, sign):
        return self.toFormat(fixpointTemp(self.w,self.i,self.sign))

    def __int__(self):
        return self.toFormat( fixpointTemp(self.w, self.w, self.sign) )

    def toFormat(self, fpobj):
        # TODO:
        w = self.w;i = self.i;frac = w - i;
        new_frac = fpobj.w - fpobj.i
        new_i    = fpobj.i 

        if i == 0:
            if new_i > 0:
                integer = ila.const(0,1)
            else:
                integer = None
        else:
            integer = self.ast[w-1:w-i]
        if new_i > 0 and integer is not None:
            if new_i > i:
                integer =  ila.sign_extend(integer, new_i) if self.sign else ila.zero_extend(integer, new_i)
            elif new_i < i:
                integer = integer[new_i-1:0]
        else:
            integer = None

        if frac == 0:
            if new_frac > 0:
                fraction = ila.const(0,1)
            else:
                fraction = None
        else:
            fraction = self.ast[w-i-1:0]

        if new_frac > 0 and fraction is not None:
            if new_frac > frac:
                fraction = ila.zero_extend(fraction, new_frac) << (new_frac - frac)
            elif new_frac < frac:
                fraction = fraction[frac-1:frac-new_frac]
        else:
            fraction = None

        assert(integer is not None or fraction is not None)
        if integer is None:
            return fraction
        if fraction is None:
            return integer
        return ila.concat([integer,fraction])
        

    def get(self):
        return self.ast
    # TODO:
    def __add__(self,r):
        vl,vr,te = lct_align(self,r)
        return fixpoint(ast = vl + vr, temp = te)
    def __sub__(self,r):
        vl,vr,te = lct_align(self,r)
        return fixpoint(ast = vl - vr, temp = te)
    def __mul__(self,r):
        ast1,ast2,te = lct_mul(self,r)
        return fixpoint(ast = ast1 * ast2, temp = te)
    def __eq__(self,r):
        vl,vr,te = lct_align(self,r)
        return vl == vr
    def __ne__(self,r):
        vl,vr,te = lct_align(self,r)
        return vl != vr
    def __lt__(self,r):
        vl,vr,te = lct_align(self,r)
        if self.sign or r.sign:
            return ila.slt(vl,vr)
        return vl<vr

    def __le__(self,r):
        vl,vr,te = lct_align(self,r)
        if self.sign or r.sign:
            return ila.sle(vl,vr)
        return vl<=vr

    def __gt__(self,r):
        vl,vr,te = lct_align(self,r)
        if self.sign or r.sign:
            return ila.sgt(vl,vr)
        return vl>vr

    def __ge__(self,r):
        vl,vr,te = lct_align(self,r)
        if self.sign or r.sign:
            return ila.sge(vl,vr)
        return vl>=vr

def fpconst(v,temp):
    i = temp.i
    #print temp.w, temp.i
    frac = temp.w - temp.i

    assert(not ( v < 0 and temp.sign == False ) )
    if v < 0:
        neg = True
        v = -v
    else:
        neg = False

    int_value  = int(v) 
    frac_value = int((v - int_value) * ( 2 ** frac))
    #print frac, (v - int_value)
    integer_value = (int_value << frac)  + frac_value
    #print integer_value
    #print frac, frac_value, integer_value,temp.w
    if integer_value >= 2**32:
        ast = ila.const(0,temp.w)
        idx = 0
        while integer_value > 0:
            word_data = integer_value & 0xffffffff
            ast =  ast | ( ila.const(word_data, temp.w)  << 32*idx )
            #print hex(word_data), hex(integer_value), idx*32
            integer_value = integer_value >> 32
            #print 'new:', hex(integer_value)
            idx += 1
    else:
        ast = ila.const(integer_value, temp.w)

    if neg:
        ast = -ast    

    fpc = fixpoint(ast, temp )
    return fpc

def fpconvert(ast, t1, t2):
    return fixpoint(ast,t1).toFormat(t2)

if __name__ == '__main__':
    template1 = fixpointTemp(5,3,True)
    template2 = fixpointTemp(8,5,False)
    a = fpconst(-0.25,template1)
    print a.ast
    b = fpconst(8.5, template2)
    print (a+b).ast
    FP01_D = fixpointTemp(64,1)
    print fpconst(0.5,FP01_D).ast
