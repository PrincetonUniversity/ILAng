# This is a dummy one
# Its responsibility is to 
import cPickle
import operator
import subprocess
import os
import copy
from resultObj import resultObj

dirName = 'Vsim'

class WrapperGenException(Exception):
    def __init__ (self,value):
        self.value = value
    def __str__(self):
        return repr(self.value)
    def __repr__(self):
        return repr(self.value)
    

def findtuple(tupleList, name):
    for (n,w) in tupleList:
        if n == name:
            return w

def findtuple2(tupleList,second):
    for (n,w) in tupleList:
        if w==second:
            return True
    return False

def createDir(dname = dirName):
    if not os.path.isdir(os.path.join(os.getcwd(),dname)):
        os.mkdir(dname)

Macro_abstraction = ''
fsm_list = {} #name -> ref
gen = 0

def Abstraction(name):
    global Macro_abstraction
    global fsm_list
    fsm_macro = collector(name)
    Macro_abstraction = name
    fsm_list[name] = fsm_macro
    return fsm_macro
def saveAll(fname):
    with open(fname,'w') as savef:
        cPickle.dump(Macro_abstraction,savef)
        cPickle.dump(fsm_list,savef)


class collector:
    
    fetch_expr = []
    fetch_valid = True
    decode_exprs = []
        
    def __init__(self,name):
        self.name = name
        self.state_list = []
        self.mem_list = []
        self.port = []
        self.pure_stateList = []
        self.stageList = []
        self.ufsm = {}              # name -> valid_expr, used to bookkeep names also
        self.usedParentStates = []  # names of getmem and getreg
        self.stateConnection = {}   # statename -> um name

    def getStateInfo(self,state_name):
        for (name,width) in self.state_list:
            if name == state_name:
                return (name,width)
        return None
    def gen_stateType(self):
        return stateType(self.state_list,self.mem_list,self.port,self.pure_stateList,self.stageList)
    # for the support of micro-insts
    def connect_microabstraction(self,state_name,link):
        self.stateConnection[state_name] = link.name

    def add_microabstraction(self,name,valid):
        ucollector = collector(name)

        ucollector.state_list = copy.deepcopy(self.state_list)
        ucollector.mem_list = copy.deepcopy(self.mem_list)
        ucollector.port = copy.deepcopy(self.port)
        ucollector.pure_stateList = copy.deepcopy(self.pure_stateList)
        ucollector.stageList = copy.deepcopy(self.stageList)

        self.ufsm[name] = valid
        fsm_list[name] = ucollector
        return ucollector

    def getreg(self,name):
        if name not in self.usedParentStates:
            self.usedParentStates.append(name)
        return resultObj(name)

    def getmem(self,name):
        if name not in self.usedParentStates:
            self.usedParentStates.append(name)
        return resultObj(name)

    # normal abstraction not micros
    def stage(self,name,stageNo):
        if stageNo >= len(self.stageList):
            self.stageList.extend([''] * (stageNo - len(self.stageList) + 1))
        self.stageList[stageNo] = name  
        return resultObj(name)
    
    def mem(self,name,addw,dataw):
        print 'adding mem %s:%d->%d' % (name,addw,dataw)
        self.mem_list.append( (name,addw,dataw) )
        return resultObj(name)

    def reg(self,name,width):
        print 'adding %s:%d' % (name,width)
        self.state_list.append( (name,width) )
        self.pure_stateList.append(name)
        return resultObj(name)

    def bit(self,name):
        print 'adding %s:%d' % (name,1)
        self.state_list.append( (name,1) )
        self.pure_stateList.append(name)
        return resultObj(name)
    
    def inp(self,name,width):
        print 'adding %s:%d' % (name,width)
        self.state_list.append( (name,width) )
        self.port.append(name)
        return resultObj(name)

    def set_init(self,name,*args,**kwargs):
        for (n,w) in self.state_list:
            if name == n:
                return None
        for (n,a,d) in self.mem_list:
            if name == n:
                return None
        raise WrapperGenException('Undefined state name: %s' % (name,))
    
    def set_next(self,name,*args,**kwargs):
        for (n,w) in self.state_list:
            if name == n:
                return None
        for (n,a,d) in self.mem_list:
            if name == n:
                return None
        raise WrapperGenException('Undefined state name: %s' % (name,))
    
    def synthesize(self,stateName,simObj):
        self.VerilogFile,self.topModule,self.refineMapName = simObj(0)
        
    def syn_elem(self,*args,**kwargs):
        return resultObj()
        
    def areEqual(self,*args,**kwargs):
        return True

    def generateVerilog(self,*args,**kwargs):
        self.generateSimToDir()
        
        
    def generateSimToDir(self,*args,**kwargs):
        global gen
        if gen==0:
            gen = 1
            # and then continue
        else:
            return # make sure it is only executed once
        saveAll('template_parse_result')
        # save all the related informations
                


    def fun(self,*args,**kwargs): # currently we don't have the ability to handle fun
        pass
            
    def get_next(self,*args,**kwargs):
        pass
    def exportOne(self,*args,**kwargs):
        pass
    def exportCVerifyFile(self,*args,**kwargs):
        pass
    def const(self,val,width):
        return resultObj("%d'd%d" % (width,val))
    
    def add_assumption(self, *args, **kwargs):
        pass
    


def enablelog(*args, **kwargs):
    pass

def setloglevel(*args, **kwargs):
    pass

def inrange(*args, **kwargs):
    return resultObj('x')

def appfun(*args, **kwargs):
    return resultObj('x')

def concat(l):
    l2 = [str(p) for p in l]
    cat = ','.join(l2)
    return resultObj('{' + cat + '}')
    
def zero_extend(e,width):
    return resultObj(e)

def writeslice(self,*args,**kwargs):
    return resultObj('x')

def writechunk(*args, **kwargs):
    return resultObj('x')

def readslice(self,*args,**kwargs):
    return resultObj('x')
        
def readchunk(*args, **kwargs):
    return resultObj('x')
    
def choice(*args, **kwargs):
    return resultObj('x')
    
def ite(e,t,f):
    return resultObj('(' + str(e) + ') ? (' + str(t) + ') : (' + str(f) + ')')
def load(m,a):
    return resultObj(str(m) + '[' + str(a) + ']')
def loadblk(m,a,n):
    return resultObj( '{' + ','.join( [ str(m) + '[' + str(a) + '+' + str(p) + ']'  for p in range(n) ] ) + '}' )
     
def store(m,a,d):
    return resultObj(str(m)) # unable to translate
def storeblk(m,a,d):
    return resultObj(str(m)) # unable to translate


def setloglevel(*args, **kwargs):
    return None




class dummySimClass():
    def __init__(self):
        pass
    def SetMaxTime(self,a):
        pass
    def SetSimState(self,b):
        pass
    def usim(self,c):
        return (self.vlgName,self.vlgTopModule,self.refineMap)
    def msim(self,c):
        return (self.vlgName,self.vlgTopModule,self.refineMap)
    def SetSimUfsmName(self,*args, **kwargs):
        pass
    def SetVlgInfo(self,vlgName,vlgTopModule,refineMap):
        self.vlgName = vlgName
        self.vlgTopModule = vlgTopModule
        self.refineMap = refineMap
    # Csim function
    def simMacro(self,s):
        return ('','','')
    def simMicro(self,s):
        return ('','','')

# These are for dummy simulator
def RTLSim():
    return dummySimClass()

def CSim():
    return dummySimClass()


class stateType:

    TYPE_unknown= 0
    TYPE_regbit = 1
    TYPE_port   = 2
    TYPE_mem    = 4

    def __init__(self,fileName = 'states_collection'):
        self.load(fileName)
        self._genPureNames()

    @classmethod
    def fromFile(cls,fileName):
        with open(fileName) as stateF:
            state_list = cPickle.load(stateF)
            mem_list = cPickle.load(stateF)
            port = cPickle.load(stateF)
            pure_stateList = cPickle.load(stateF)
            stage = cPickle.load(stateF)
        return cls(state_list,mem_list,port,pure_stateList,stage)

    def _genPureNames(self):
        self._name_state_dict = {}
        for (n,w) in self.state_list:
            self._name_state_dict[n] = (n,w)
        self._name_mem_dict = {}
        for (n,a,d) in self.mem_list:
            self._name_mem_dict[n] = (n,a,d)
        

    def __init__(self,state_list,mem_list,port,pure_stateList,stage):
        self.state_list = state_list    # list of state and width, input/bit/reg
        self.mem_list = mem_list        # list of memory (name,addrwidth,datawidth)
        self.port = port                # only port name list
        self.pure_stateList = pure_stateList # list of reg
        self.stage = stage              # stage list [stageNo] -> stage
        self.sortedStates = sorted(self.state_list,key=operator.itemgetter(0))
        self._genPureNames()



    def save(self,fileName = 'states_collection'):
        with open(fileName,'wt') as outf:
            cPickle.dump(self.state_list,outf)
            cPickle.dump(self.mem_list,outf)
            cPickle.dump(self.port,outf)
            cPickle.dump(self.pure_stateList,outf)
            cPickle.dump(self.stage,outf)

    def load(self,fileName = 'states_collection'):
        with open(fileName) as stateF:
            self.state_list = cPickle.load(stateF)
            self.mem_list = cPickle.load(stateF)
            self.port = cPickle.load(stateF)
            self.pure_stateList = cPickle.load(stateF)
            self.sortedStates = sorted(self.state_list,key=operator.itemgetter(0))
            self.stage = cPickle.load(stateF)


    def isInp(self,name):
        return name in self.port
    def isPureState(self,name):
        return name in self.pure_stateList
    def isStage(self,name):
        return name in self.stage
    def isMem(self,name):
        return name in self._name_mem_dict
    def isInpRegBit(self,name):
        return name in self._name_state_dict
    def stateItems(self):
        return self._name_state_dict.keys() + self._name_mem_dict.keys()
    # (n,w) or (n,a,d) or (None,None)
    def getTuple(self,name):
        if name in self._name_mem_dict:
            return self._name_mem_dict[name]
        if name in self._name_state_dict:
            return self._name_state_dict[name]
        return (None,None)

        