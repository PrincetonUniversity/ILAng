
### Exception  ###
class ResultObjException(Exception):
    def __init__ (self,value):
        self.value = value
    def __str__(self):
        return repr(self.value)

class smtObj:
    def __init__(self,name,width = 1,val = None):
        if val is None: # here we create a bv 
            self.expr = name
        else:
            self.expr = smtObj._convert_bv(width,val)
        self.width = width

    @staticmethod
    def _extendToWidth(expr,owidth,nwidth):
        extzero = smtObj._convert_bv(nwidth-owidth,0)
        return '(concat {0} {1})'.format(extzero,expr)
    @staticmethod
    def _convert_bv(width,val):
        retStr  = "{0:b}".format(val)
        lendiff = width - len(retStr)
        lendiff = 0 if lendiff<0 else lendiff
        retStr  = '#b' + '0'*lendiff + retStr
        return retStr
    def _checkOtherAndSelf(self,other,owidth = None, swidth = None, Weq = False):
        if isinstance(other,resultObj):
            other = other.smtExpr
        assert(other is not None)
        if not isinstance(other,smtObj):
            other = smtObj('',width = self.width, val = other)
        if owidth is not None: assert(other.width == owidth)
        if swidth is not None: assert(self.width == swidth)
        se = self.expr
        ow = other.expr
        if Weq: 
            selfWidth = swidth if swidth else self.width
            if selfWidth > other.width:
                ow = smtObj._extendToWidth(ow,owidth = other.width, nwidth = selfWidth)
            if selfWidth < other.width:
                se = smtObj._extendToWidth(se,owidth = selfWidth, nwidth = other.width)
        return ow,se
    def Inv(self):
        assert(self.width == 1)
        return smtObj( '(not {0})'.format(self.expr) , self.width )
    def And(self,other):
        ow,se = self._checkOtherAndSelf(other, swidth = 1, Weq = True)
        return smtObj( '(and {0} {1})'.format(se,ow) , self.width )
    def RAnd(self,other):
        ow,se = self._checkOtherAndSelf(other, swidth = 1, Weq = True)
        return smtObj( '(and {1} {0})'.format(se,ow) , self.width )
    def Or(self,other):
        ow,se = self._checkOtherAndSelf(other, swidth = 1, Weq = True)
        return smtObj( '(or {0} {1})'.format(se,ow) , self.width )
    def ROr(self,other):
        ow,se = self._checkOtherAndSelf(other, swidth = 1, Weq = True)
        return smtObj( '(or {1} {0})'.format(se,ow) , self.width )
    def Xor(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvxor {0} {1})'.format(se,ow) , self.width )
    def RXor(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvxor {1} {0})'.format(se,ow) , self.width )
    def Add(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvadd {0} {1})'.format(se,ow) , self.width )
    def RAdd(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvadd {1} {0})'.format(se,ow) , self.width )
    def Sub(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvsub {0} {1})'.format(se,ow) , self.width )
    def RSub(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvsub {0} {1})'.format(ow,se) , self.width )
    def Mul(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvmul {0} {1})'.format(se,ow) , self.width )
    def RMul(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvmul {0} {1})'.format(ow,se) , self.width )
    def Div(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvdiv {0} {1})'.format(se,ow) , self.width )
    def RDiv(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvdiv {0} {1})'.format(ow,se) , self.width )
    def Mod(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvmod {0} {1})'.format(se,ow) , self.width )
    def RMod(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvmod {0} {1})'.format(ow,se) , self.width )
    def Lshift(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvlshift {0} {1})'.format(se,ow) , self.width )
    def RLshift(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvlshift {0} {1})'.format(ow,se) , self.width )
    def Rshift(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvrshift {0} {1})'.format(se,ow) , self.width )
    def RRshift(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvrshift {0} {1})'.format(ow,se) , self.width )
    def Eq(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(= {0} {1})'.format(se,ow) , 1 )
    def Ne(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(not (= {0} {1}))'.format(se,ow) , 1 )
    def Lt(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvult {0} {1})'.format(se,ow) , 1 )
    def Le(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvule {0} {1})'.format(se,ow) , 1 )
    def Gt(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvugt {0} {1})'.format(se,ow) , 1 )
    def Ge(self,other):
        ow,se = self._checkOtherAndSelf(other, Weq = True)
        return smtObj( '(bvuge {0} {1})'.format(se,ow) , 1 )
    def Select(self,idx):
        if isinstance(idx,int):
            assert(idx >= 0 and idx < self.width)
            return smtObj( '((_ extract {1} {1}) {0})'.format(self.expr,idx) , 1)
        else:
            start = idx.start
            stop  = idx.stop
            assert(start >= 0 and start < self.width)
            assert(stop >=0 and stop < self.width)
            assert(start >= stop)
            length = start-stop+1
            return smtObj( '((_ extract {1} {2}) {0})'.format(self.expr,start,stop) , length)


class resultObj:
    def __init__(self,name,smtExpr = None): # width is only used in smtObj
        self.expr = name
        self.smtExpr = smtExpr

    def _checksmtExpr(self,p1 = None):
        if not isinstance(p1,resultObj):
            if isinstance(p1,int) and self.smtExpr is not None:
                return 1  # special case
            p1 = None
        if p1 is not None:
            if p1.smtExpr is not None and self.smtExpr is None:
                raise ResultObjException("Check failed!")
            if p1.smtExpr is None and self.smtExpr is not None:
                raise ResultObjException("Check failed!")
            if p1.smtExpr is None:
                return None
            return 1
        elif self.smtExpr is not None:
            return 1
        return None
    def __str__(self):
        return self.expr
    def __invert__(self):
        if self._checksmtExpr() is None:
            return resultObj('~(' + self.expr+')' )
        return resultObj('~(' + self.expr+')', self.smtExpr.Inv() )
    def __neg__(self):
        if self._checksmtExpr() is None:
            return resultObj('-(' + self.expr+')' , )
        return resultObj('-(' + self.expr+')' , self.smtExpr.RSub(0) )
    def __and__(self,other):
        if self._checksmtExpr(other) is None:
            return resultObj('(' + self.expr+') && (' + str(other) + ')' , )
        return resultObj('(' + self.expr+') && (' + str(other) + ')' , self.smtExpr.And(other) )
    def __rand__(self,other):
        if self._checksmtExpr(other) is None:
            return resultObj('(' + str(other) +') && (' + self.expr + ')')
        return resultObj('(' + str(other) +') && (' + self.expr + ')', self.smtExpr.RAnd(other) )
    def __or__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.Or(other)
        return resultObj('(' + self.expr+') || (' + str(other) + ')', smtexpr)
    def __ror__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.ROr(other)
        return resultObj('(' + str(other) +') || (' + self.expr + ')', smtexpr)
    def __xor__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.Xor(other)
        return resultObj('(' + self.expr+') ^ (' + str(other) + ')', smtexpr)
    def __rxor__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.RXor(other)
        return resultObj('(' + str(other) +') ^ (' + self.expr + ')', smtexpr)
    def __add__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.Add(other)
        return resultObj('(' + self.expr+') + (' + str(other) + ')', smtexpr)
    def __radd__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.RAdd(other)
        return resultObj('(' + str(other) +') + (' + self.expr + ')', smtexpr)
    def __sub__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.Sub(other)
        return resultObj('(' + self.expr+') - (' + str(other) + ')', smtexpr)
    def __rsub__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.RSub(other)
        return resultObj('(' + str(other) +') - (' + self.expr + ')', smtexpr)
    def __mul__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.Mul(other)
        return resultObj('(' + self.expr+') * (' + str(other) + ')', smtexpr)
    def __rmul__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.RMul(other)
        return resultObj('(' + str(other) +') * (' + self.expr + ')', smtexpr)
    def __div__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.Div(other)
        return resultObj('(' + self.expr+') / (' + str(other) + ')', smtexpr)
    def __rdiv__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.RDiv(other)
        return resultObj('(' + str(other) +') / (' + self.expr + ')', smtexpr)
    def __mod__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.Mod(other)
        return resultObj('(' + self.expr+') % (' + str(other) + ')', smtexpr)
    def __rmod__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.RMod(other)
        return resultObj('(' + str(other) +') % (' + self.expr + ')', smtexpr)
    def __lshift__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.Lshift(other)
        return resultObj('(' + self.expr+') << (' + str(other) + ')', smtexpr)
    def __rlshift__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.RLshift(other)
        return resultObj('(' + str(other) +') << (' + self.expr + ')', smtexpr)
    def __rshift__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.Rshift(other)
        return resultObj('(' + self.expr+') >> (' + str(other) + ')', smtexpr)
    def __rrshift__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.RRshift(other)
        return resultObj('(' + str(other) +') >> (' + self.expr + ')', smtexpr)
    def __eq__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.Eq(other)
        return resultObj('(' + self.expr+') == (' + str(other) + ')', smtexpr)
    def __ne__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.Ne(other)
        return resultObj('(' + self.expr+') != (' + str(other) + ')', smtexpr)
    def __lt__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.Lt(other)
        return resultObj('(' + self.expr+') < (' + str(other) + ')', smtexpr)
    def __le__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.Le(other)
        return resultObj('(' + self.expr+') <= (' + str(other) + ')', smtexpr)
    def __gt__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.Gt(other)
        return resultObj('(' + self.expr+') > (' + str(other) + ')', smtexpr)
    def __ge__(self,other):
        if self._checksmtExpr(other) is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.Ge(other)
        return resultObj('(' + self.expr+') >= (' + str(other) + ')', smtexpr)
    def __getitem__(self,idx):
        if self._checksmtExpr() is None:
            smtexpr = None
        else:
            smtexpr = self.smtExpr.Select(idx)
        if isinstance(idx,int):
            return resultObj('(' + self.expr+') ['+ str(idx) +']', smtexpr)
        else: # slice object
            start = idx.start
            stop  = idx.stop
            assert(idx.step == None)
            return resultObj('(' + self.expr+') ['+ str(start) + ':' +str(stop) +']', smtexpr)
