
import os
import cPickle
from collections import namedtuple

### Exception  ###
class RefinementException(Exception):
    def __init__ (self,value):
        self.value = value
    def __str__(self):
        return repr(self.value)

class Separator:
    def __init__(self,beg,ed, beginCond, endCond):
        self.begin = beg
        self.end = ed
        self.beginCond = beginCond
        self.endCond = endCond
        if beginCond and not isinstance(beginCond, dict):
            raise RefinementException('Begin Condition should be a ConcreteCond object')
        if endCond and not isinstance(endCond, dict):
            raise RefinementException('End Condition should be a ConcreteCond object.')

def ConcreteCond(cond_dict):
    return cond_dict

class Crecord:
    def __init__(self):
        self.ANY = None
    def Sep(self,begin,end, beginCond = None, endCond = None):
        return Separator(beg = begin, ed = end, beginCond = beginCond, endCond = endCond)

class ILA:
    AnyInstruction = {}
    def _load_from_file(self,fname):
        with open(fname) as inf:
            self.macrofsm = cPickle.load(inf)
            self.fsm_list = cPickle.load(inf)
    def __init__(self,template_parse_file = "template_parse_result" ):
        self._load_from_file(template_parse_file)
        pass

#--------------
#  Collectors
#--------------

class VarMap:
    def __init__(self,d,ec = None):
        self.varmap = d
        self.extraControlDict = None
    def copy(self):
        if self.extraControlDict is None:
            return VarMap( self.varmap.copy() )
        return VarMap( self.varmap.copy(), self.extraControlDict.copy() )
    def append(self,d2):
        self.varmap.update(d2)
    def __getitem__(self, key):
        return self.varmap[key]
    def __setitem__(self, key, value):
        self.varmap[key] = value
    def extraControl(self,cdict):
        self.extraControlDict = cdict

class PC2stateClass:
    def __init__(self, name = None):
        self.name = name

# d : label_name:String -> ( var_name:String X value )
def PC2state(d, refSimSp):
    if refSimSp.pcdict is not None:
        raise RefinementException('cannot define two pc2state mapping')
    refSimSp.pcdict = (d)
    return PC2stateClass()

def PC2stateVerif(name,d,refVerifSp):
    dict_ref = []
    for n,dc in refVerifSp.pcdict:
        if n == name:
            dict_ref = dc
            break
        else:
            dict_ref = []
    if dict_ref != []:
        #print 'name:%s found.' % name
        #print 'before:',d,'->'
        dict_ref.update(d)
        #print 'after:',dict_ref,'->'
    else:
        refVerifSp.pcdict.append( (name,d) )
    return PC2stateClass(name)


class CArray:
    def __init__(self,cname, ctype = ''):
        self.cname  = cname
        self.ctype  = ctype

# we allow multiple pc state ( label -> variable assignment )
# 

class refSimSeparator:
    def __init__(self):
        self.sepList = []
        self.pcdict = None # list of dict
    def setCondition(self, level, instDecode, CInstSet, varMap):
        self.sepList.append( (level,instDecode,CInstSet, varMap) )


CondItem = namedtuple('CondItem', ['name', 'instDecode', 'funcCall', 'pcMap', 'varMap'])

class refVerifSeparator:
    def __init__(self):
        self.sepList = []
        self.pcdict  = []
    def setCondition(self, name, instDecode, funcCall, pcMap, varMap):
        # type : name       : string 
        #        instDecode : (string->int) List 
        #        funcCall   : string List
        #        pcMap      : Separator List
        #        varMap     : (string X VarMap) List
        self.sepList.append( CondItem(name, instDecode, funcCall, pcMap, varMap) )

def invokeFunc(funcObj):
    refSimSp = refSimSeparator()
    PCstate = lambda d: PC2state(d,refSimSp)
    Cinfo = Crecord()
    ilaRef = ILA()
    funcObj(Cinfo = Cinfo, refSimSp = refSimSp, PCstate = PCstate)
    return (Cinfo,refSimSp,ilaRef)


def invokeFuncVerif(funcObj):
    refVerifSp = refVerifSeparator()
    PCstate = lambda n,d: PC2stateVerif(n, d,refVerifSp)
    Cinfo = Crecord()
    ilaRef = ILA()
    funcObj(Cinfo = Cinfo, refVerifSp = refVerifSp, PCstate = PCstate)
    return (Cinfo,refVerifSp,ilaRef)

DirectType = 0
FixPoint = 1
SignalVar = 2

class SysCType:
    def __init__(self):
        pass

class SysCCustomType(SysCType):
    def __init__(self, strName):
        self.strName = strName
    def __str__(self):
        return self.strName
    def type(self):
        return DirectType

# the following two are all BIT_VEC in verification
class SysCFixedType(SysCCustomType):
    def __init__(self,w,i):
        SysCCustomType.__init__(self, 'sc_fixed<%d,%d>' % (w,i) )
        self.w = w; self.i = i
    def type(self):
        return FixPoint

class SysCUFixedType(SysCCustomType):
    def __init__(self,w,i):
        SysCCustomType.__init__(self, 'sc_ufixed<%d,%d>' % (w,i) )
        self.w = w; self.i = i
    def type(self):
        return FixPoint

class SysCSignal(SysCCustomType):
    def __init__(self,t):
        SysCCustomType.__init__(self, 'sc_signal<%s >' % (t,) )
        self.originalSig = t
    def getWrappedSig(self):
        return self.originalSig
    def type(self):
        return SignalVar

u32  = SysCCustomType('unsigned int')
u16  = SysCCustomType('short unsigned int')
u8   = SysCCustomType('unsigned char')
Bool = SysCCustomType('bool')


