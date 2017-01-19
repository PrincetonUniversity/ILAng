
import os
import cPickle


### Exception  ###
class RefinementException(Exception):
    def __init__ (self,value):
        self.value = value
    def __str__(self):
        return repr(self.value)

class Separator:
    def __init__(self,beg,ed):
        self.begin = beg
        self.end = ed

class Crecord:
    def __init__(self):
        self.ANY = None
    def Sep(self,begin,end):
        return Separator(beg = begin, ed = end)

class ILA:
    AnyInstruction = {}
    def _load_from_file(self,fname):
        with open(fname) as inf:
            self.macrofsm = cPickle.load(inf)
            self.fsm_list = cPickle.load(inf)
    def __init__(self,template_parse_file = "template_parse" ):
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
    def __getitem__(self, key):
        return self.varmap[key]
    def __setitem__(self, key, value):
        self.varmap[key] = value
    def extraControl(self,cdict):
        self.extraControlDict = cdict

class PC2stateClass:
    def __init__(self):
        pass

def PC2state(d, refSimSp):
    if refSimSp.pcdict is not None:
        raise RefinementException('cannot define two pc2state mapping')
    refSimSp.pcdict = (d)
    return PC2stateClass()

class CArray:
    def __init__(self,cname):
        self.cname  = cname

class refSimSeparator:
    def __init__(self):
        self.sepList = []
        self.pcdict = None # list of dict
    def setCondition(self, level, instDecode, CInstSet, varMap):
        self.sepList.append( (level,instDecode,CInstSet, varMap) )

def invokeFunc(funcObj):
    refSimSp = refSimSeparator()
    PCstate = lambda d: PC2state(d,refSimSp)
    Cinfo = Crecord()
    ilaRef = ILA()
    funcObj(Cinfo = Cinfo, refSimSp = refSimSp, PCstate = PCstate)
    return (Cinfo,refSimSp,ilaRef)

