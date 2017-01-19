# signal matching

# type: Inport RegDirect Indirect

import pyverilog.utils.version
from pyverilog.dataflow.dataflow_analyzer import VerilogDataflowAnalyzer

ShowList = False
AutoChooseFirst = False
AutoChooseShort = (not AutoChooseFirst) and True

class NonExistSignal(Exception):
    def __init__ (self,value):
        self.value = value
    def __str__(self):
        return repr(self.value)


typeList = ['Inport','RegDirect','Indirect']
Inport = 0
RegDirect = 1
Indirect = 2

# aux function
# return bind from binddict
def lookupSigBind(binddict,signame):
    for bk,bv in binddict.items():
        #print "<"+ str(bk) + ">"
        if str(bk) == str(signame):
            return bv
    return None

# return if signal exists
def SigExist(terms,signame):
    for tk,tv in terms.items():
        if str(tk) == signame:
            return True
    return False

# partial_name -> one from NameList
def promptAndChooseSig(NameList, partial_name):
    def dotCount(L):
        minDot = 10000
        idxD = -1
        for idx,name in enumerate(L):
            DotCount = name.count('.')
            if DotCount < minDot:
                minDot = DotCount
                idxD = idx
        assert(idxD != -1)
        return idxD

    options = len(NameList)
    if options == 1:
        return NameList[0]
    else:
        print '<INFO> Multiple existing signals for:', partial_name
        if ShowList:
            for idx,n in enumerate(NameList):
                print '     [%d] %s' % (idx,n)
        if AutoChooseFirst:
            print '     %s is selected as default.' % NameList[0]
            return NameList[0]
        elif AutoChooseShort:
            idxD = dotCount(NameList)
            print '     %s is selected as default.' % NameList[idxD]
            return NameList[idxD]

        # else
        choice = ''
        while (not choice.isdigit() ) or int(choice) < 0 or int(choice) >= options:
            choice = raw_input('     Choose [0]: ')
            if choice == '':
                choice = '0'
        return NameList[int(choice)]

def GetSigWidth(terms,full_name):
    for tk,tv in terms.items():
        if str(tk) == full_name:
            return (int(str(tv.msb)),int(str(tv.lsb)))
    return None

# use to expand names
def GetSigAndScope(terms, partial_name):
    NameList = []
    for tk,tv in terms.items():
        scope = str(tk).split('.')
        if scope[-1] == partial_name:
            NameList.append(str(tk))
    if NameList:
        return promptAndChooseSig(NameList,partial_name)

    NameList = []
    for tk,tv in terms.items():
        if partial_name in str(tk):
            NameList.append(str(tk))
    if NameList:
        return promptAndChooseSig(NameList,partial_name)
            
    raise NonExistSignal(partial_name)

# is reg/mem? need full name
def isReg(terms,signame):
    for tk,tv in terms.items():
        if str(tk) == signame:
            if 'Reg' in tv.termtype or 'RegArray' in tv.termtype:
                return True
    return False
# is inp? (may not be the top one), need full name
def isInp(terms,signame):
    for tk,tv in terms.items():
        if str(tk) == signame:
            if 'Input' in tv.termtype:
                return True
    return False


#--------------------------------------
#
#   Aux Function for Instantiation
#
#--------------------------------------

ModuleInp = 0
ModuleOup = 1

# return list of (I/O, partial_name)
def getAllIO_top(terms,topModule): # only works for top module
    topIOList = []
    for tk,tv in terms.items():
        scope = str(tk).split('.')
        if len(scope)==2 and scope[0] == topModule:
            if 'Input' in tv.termtype:
                topIOList.append( (ModuleInp,scope[1]) )
            elif 'Output' in tv.termtype:
                topIOList.append( (ModuleOup,scope[1]) )
            else:
                pass
                #print '<I> Ignoring top signal : ' +str(tk) +" Type: ", tv.termtype
    return topIOList
def FullInst(terms,moduleName,instName,AllPrevParam):
    instStr = ''
    firstline = True
    topIOdef = getAllIO_top(terms,moduleName)
    instStr += '%s %s ( \n' % (moduleName,instName)
    for (IOtype,portname) in topIOdef:
        # first handle clk and rst
        if firstline:
            firstline = False
        else:
            instStr +=',\n'

        if IOtype == ModuleInp:
            assert(portname in AllPrevParam)
            instStr += '\t\t\t.%20s(%20s)' % (portname,AllPrevParam[portname])
        elif IOtype == sigmatch.ModuleOup:
            if portname in AllPrevParam:
                instStr += '\t\t\t.%20s(%20s)' % (portname,AllPrevParam[portname])
            else:
                instStr += '\t\t\t.%20s(%20s)' % (portname,'')
                print '<I> ignore output port: %s' % portname
        else:
            print "Warning: design bug. IOtype %d not handled" % IOtype
    instStr += '\n\t);\n'
    return instStr

def MergeParam(terms,moduleName,instName,ParamList1,ParamList2): # => ParamList
    topIOdef = getAllIO_top(terms,moduleName)
    ResultDict = {}
    for (IOtype,portname) in topIOdef:
        (clkTF,clkName) = isClk(portname)
        (rstTF,rstName) = isRst(portname)
        if clkTF and IOtype == ModuleInp:
            ResultDict[portname] = clkName
        elif rstTF and IOtype == ModuleInp:
            ResultDict[portname] = rstName
        elif IOtype == ModuleInp:
            if portname in ParamList1 and ParamList1[portname] != '':
                ResultDict[portname] = ParamList1[portname]
            elif portname in ParamList2:
                ResultDict[portname] = ParamList2[portname]
            else:
                ResultDict[portname] = ''
    return ResultDict


def isClk(name):
    if name == 'clk' or name == 'clock' or name == 'ap_clk':
        return (True,'clk')
    return (False,'')

def isRst(name):
    if name == 'rst' or name == 'reset' or name == 'ap_reset':
        return (True,'rst')
    elif name == 'rst_n' or name == 'reset_n':
        return (True,'~rst')
    return (False,'')

class VerilogTypeAnalyzer:

    def __init__(self,vfileName,topModule):
        analyzer = VerilogDataflowAnalyzer([vfileName],topModule,
                                                noreorder = False,
                                                nobind = False,
                                                preprocess_include = [],
                                                preprocess_define = [])
        analyzer.generate()
        self.terms = analyzer.getTerms()
        self.binddict = analyzer.getBinddict()
        self.topModule = topModule
    
    def isTopInp(self,signame):
        scope = signame.split('.')
        if len(scope) == 2 and scope[0] == self.topModule and isInp(self.terms, signame):
            return True
        return False

    def GetSigWidth(self,full_name):
        return GetSigWidth(self.terms,full_name)
    # return type inside module (Indirect/reg/inp)
    # get full name, with the help of rfMap (rfMap can provide partial name)
    # 
    def getType(self,signame,retCname = False):  # return type (int , full_name)
        osigname = signame
        # first expand name
        if SigExist(self.terms,self.topModule + '.' + signame):
            signame = self.topModule + '.' + signame
        else:
            signame = GetSigAndScope(self.terms,signame)
        
        # only for topModule signals
        if isInp(self.terms,signame) and SigExist(self.terms,self.topModule + '.' + osigname):
            return (Inport,signame)
        elif isReg(self.terms,signame):
            return (RegDirect,signame)
        else:
            #start traversal
            #print "<"+ str(signame) +">"
            bindSig = lookupSigBind(self.binddict,signame)[0].tree
            bindSigName = str(bindSig)
            #print "->>",bindSigName
            while ( '.' in bindSigName) and not ( isReg(self.terms,bindSigName) ) :
                bindSig = lookupSigBind(self.binddict,bindSigName)[0].tree
                bindSigName = str(bindSig)
                #print "->>",bindSigName
                if self.isTopInp(bindSigName):
                    return (Inport,bindSigName)
            if isReg(self.terms,bindSigName):
                return (RegDirect,bindSigName)
            
            assert( '.' not in  bindSigName)
            if retCname:
                return (Indirect,signame)
            return (Indirect,osigname)


if __name__ == '__main__':
    #let's do some test
    v = VerilogTypeAnalyzer("concat_rtl.v","top")
    print isReg(v.terms,"top.top_core_inst.top_core_valxi_inst.top_core_valxi_valx_wait_dp_inst.rvalue")
    print v.getType("valx_z")
    print v.getType("valx_vz")
    print v.getType("outxi_d")
            

