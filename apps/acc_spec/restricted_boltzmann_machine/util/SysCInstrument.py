import re
import SysCrfmaplib
import SysCSimRfRelation


### Exception  ###
class CInstException(Exception):
    def __init__ (self,value):
        self.value = value
    def __str__(self):
        return repr(self.value)

ctlGlobalTemplate="""
bool __start__ = false;
bool __end__ = false;
int __pc_state__;

int mem_iter;
int mem_nd_count;
uint32_t mem_default;
"""

ctlGlobalDumpFunc = """
void __dump__()
{
    FILE * fp = fopen("Cresult.out","w");
    fprintf(fp,".RTL_OP_START\\n");
    %s
    fprintf(fp,".RTL_OP_END\\n");
    fclose(fp);
}
"""

memDefTemplate="""
    for(mem_iter=0;mem_iter<{upper};mem_iter++)
        {cname}[mem_iter] = {default};
"""
memCtlTemplate="\t{cname}[{idx}] = {value};\n"

memDumpTemplate = """
    if({cname}[0] == {cname}[1])
        mem_default = {cname}[0];
    else if ({cname}[1]=={cname}[2])
        mem_default = {cname}[1];
    else
        mem_default = {cname}[0];
    mem_nd_count = 0;
    for(mem_iter=0;mem_iter<{upper};mem_iter++)
        if({cname}[mem_iter] != mem_default)
            mem_nd_count ++;
    fprintf(fp,"{ILAname} %d %x\\n",mem_nd_count,mem_default);
    for(mem_iter=0;mem_iter<{upper};mem_iter++)
        if({cname}[mem_iter] != mem_default)
            fprintf(fp,"%x %x\\n", mem_iter ,{cname}[mem_iter] );
"""

memDumpFixPointTemplate = """
    {type} mem_defVal;
    if({cname}[0] == {cname}[1])
        mem_defVal = {cname}[0];
    else if ({cname}[1]=={cname}[2])
        mem_defVal = {cname}[1];
    else
        mem_defVal = {cname}[0];
    mem_nd_count = 0;
    for(mem_iter=0;mem_iter<{upper};mem_iter++)
        if({cname}[mem_iter] != mem_defVal)
            mem_nd_count ++;
    fprintf(fp,"{ILAname} %d %x\\n",mem_nd_count,mem_defVal.to_string(SC_BIN) );
    for(mem_iter=0;mem_iter<{upper};mem_iter++)
        if({cname}[mem_iter] != mem_defVal)
            fprintf(fp,"%x %x\\n", mem_iter ,{cname}[mem_iter].to_string(SC_BIN) );
"""


valDumpTemplate = """\tfprintf(fp,"{ILAname} %x\\n", *{cname} );\n"""
valPCDumpTemplate = """\tfprintf(fp,"{ILAname} %x\\n", {cname} );\n"""
valSlicedpTemplateBeg = """\tfprintf(fp,"{ILAname} ");\n"""
valSlicedpTemplateBdy = """\tfprintf(fp,"%0{l}x", *{cname});\n"""
valSlicedpTemplateEnd = """\tfprintf(fp,"\\n");\n"""

valFixpDumpTemplate = """\tfprintf(fp,"{ILAname} %s\\n", {cname}->to_string(SC_BIN) );\n"""
valSignalDumpTemplate = """\tfprintf(fp,"{ILAname} %s\\n", ({cname}->read()).to_string(SC_BIN) );\n"""

dumpTemplate = """
    if(__end__) {
        __dump__();
        exit(__pc_state__);
    }
"""

def NameToLabel(name):
    return '//##LABEL##%s##//' % name

class CInstrument:
    def _find_all_labels(self):
        allLabels = []
        labelPattern = re.compile(r'//##LABEL##([A-Za-z0-9_\@]+)##//')
        self.allLabels = list(set(labelPattern.findall(self.Cbuffer)))
        if '@_global' not in self.allLabels:
            raise CInstException('No @_global label!')

    def _set_default_type(self):
        # please modify me ?
        pass
    def _ila_lookup_mem(self,fsm,name):
        fsmref = self.ilaRef.fsm_list[fsm]
        for (n,a,d) in fsmref.mem_list:
            if n == name:
                return (n,a,d)
        raise CInstException('mem name:%s in fsm: %s is not found' % (name,fsm) )
    def _ila_lookup_state(self,fsm,name):
        fsmref = self.ilaRef.fsm_list[fsm]
        for (n,w) in fsmref.state_list:
            if n == name:
                return (n,w)

    def __init__(self, cFileName, cOutName = 'instC.c'):
        self.Ccontrol,self.refSimSp, self.ilaRef = SysCrfmaplib.invokeFunc(SysCSimRfRelation.buildRefMap)
        self.cFileName = cFileName
        self.cOutName = cOutName
        with open(cFileName) as cfin:
            self.Cbuffer = cfin.read()
            self._find_all_labels()
        self.cAnnotate = ''
        self._set_default_type()

    def _choose_sep(self,s_in,fsmName): # return an item in refSimSp
        for item in self.refSimSp.sepList:
            # item = (level, instDecode, CInstSet, varMap)
            if item[0] == fsmName: # level
                misMatchFlag = False
                for instDecField in item[1]: # instDecode
                    if s_in[instDecField] != item[1][instDecField]:
                        misMatchFlag = True
                        break
                if misMatchFlag:
                    continue
                # else we find a matched one:
                return item

    def _gen_dump_str(self,varMapPair, globalPnt, fsmName):
        # l
        def lookupInVarmap(ILAname):
            for label,varMap in varMapPair:
                varmapdict = varMap.varmap
                if ILAname in varmapdict:
                    return varMap[ILAname]
        dumpStr = ''
        for ILAname,ptrName,tp in globalPnt:
            Cvar = lookupInVarmap(ILAname)
            if isinstance(Cvar, tuple):
                CType = Cvar[1]
                Cvar = Cvar[0]
            else:
                CType = None

            if isinstance(Cvar,str):
                dumpStr += valDumpTemplate.format(ILAname = ILAname,cname = ptrName)
            elif isinstance(Cvar,dict):
                dumpStr += valSlicedpTemplateBeg.format(ILAname = ILAname)
                # here we use it: tp
                for idx in range(len(Cvar.keys())):
                    cname = ptrName + '_%d' % idx
                    l = tp[idx][2]/4
                    dumpStr += valSlicedpTemplateBdy.format(cname = cname,l=l)
                dumpStr += valSlicedpTemplateEnd
            elif isinstance(Cvar,SysCrfmaplib.CArray):
                upper = 2 ** ( self._ila_lookup_mem(fsmName,ILAname)[1] )
                dumpStr += memDumpTemplate.format(cname = ptrName,upper = upper, ILAname = ILAname)
            elif isinstance(Cvar,SysCrfmaplib.PC2stateClass):
                dumpStr += valPCDumpTemplate.format(ILAname = ILAname, cname = '__pc_state__')
            else:
                raise CInstException('unrecognized var map type:'+repr(Cvar))
        retStr = ctlGlobalDumpFunc % dumpStr
        return retStr


    def _translate_to_ctl(self,item,s_in,fsmName):
        def getslice(num,lm,rm):
            mask = 2**(lm-rm+1)-1
            return (num>>rm)&mask
        def SysCConvertToValue(Val, Type):
            if Type.type() == SysCrfmaplib.FixPoint: # 
                orig = bin(Val)
                frac = Type.w - Type.i
                retV = orig[:-frac] + '.'+orig[-frac:]
                return retV
            elif Type.type() == SysCrfmaplib.DirectType:
                return str(Val)
            else:
                raise(repr(Type) + ' is not convertible.')

        def remove_illegal(s):
            return s.replace('@','')
        def widthTotype(w):
            if w<=8:
                return 'unsigned char' #'uint8_t'
            if w<=16:
                return 'unsigned short'#'uint16_t'
            if w<=32:
                return 'unsigned int'#'uint32_t'
            raise CInstException("unable to identify type for w:%d" % w)
        def sort_dict(d):
            def tp2w(t):
                return max(t)-min(t)+1
            kvpair = d.items()
            skvpair = sorted(kvpair,key = lambda x : x[1][0] ,reverse = True)
            return [(kvp[0], widthTotype(tp2w(kvp[1])),tp2w(kvp[1])) for kvp in skvpair]

        ctlGlobal = ctlGlobalTemplate
        ctlAnnotate = {}
        for key in self.allLabels:
            ctlAnnotate[key] = ''
        Sep = item[2]
        varMap = item[3]

        # here let's set the correct pc to state value
        for label in self.refSimSp.pcdict:
            if label not in ctlAnnotate:
                raise CInstException('label:'+label+' not defined in Source!')
            ctlAnnotate[label] += '\t__pc_state__ = %d;\n' % (self.refSimSp.pcdict[label])

        # here we determine the control method!
        globalPnt = [] # (name,pntName,type)
        globalPntDecl = ''
        def Decl(tp,name):
            return '%s *%20s;\n' % (tp,name)
        # generate global pointers
        for label,varmap in varMap:
            # assign separately 
            ptrAssign = '\n\t/*********** BEGIN of PNT ASSIGN:%s ************/\n' % label 
            vmap = varmap.varmap
            for ILAname,Cvar in vmap.items():
                pntName = remove_illegal(label) + ILAname

                if isinstance(Cvar,tuple):
                    Type = str(Cvar[1])
                    Cvar = Cvar[0]
                else:
                    Type = None

                if isinstance(Cvar, str):
                    width = self._ila_lookup_state(fsmName, ILAname)[1]
                    tp = Type or widthTotype(width)
                    globalPntDecl += Decl(tp,pntName)
                    globalPnt.append( (ILAname,pntName,tp) )
                    ptrAssign += '\t%s = & %s;\n' % (pntName,Cvar)
                elif isinstance(Cvar,dict):
                    #width = self._ila_lookup_state(fsmName, ILAname)[1]
                    ntpair = sort_dict(Cvar)
                    idx = 0
                    globalPnt.append( (ILAname,pntName,ntpair) )
                    if Type is not None:
                        raise CInstException("FIXME: slicing with predefined type is not supported.")
                    for n,tp,w in ntpair:
                        realPntName = pntName + '_%d' % idx
                        globalPntDecl += Decl(tp,realPntName)
                        ptrAssign += '\t%s = & %s;\n' % (realPntName,n)
                        idx += 1
                elif isinstance(Cvar, SysCrfmaplib.CArray):
                    width = self._ila_lookup_mem(fsmName, ILAname)[2]
                    tp = Type or widthTotype(width)
                    globalPntDecl += Decl(tp,pntName)
                    globalPnt.append( (ILAname,pntName,tp) )
                    ptrAssign += '\t%s = %s;\n' % (pntName,Cvar.cname)
                elif isinstance(Cvar,SysCrfmaplib.PC2stateClass): # you also need to add to global Pnt
                    globalPnt.append( (ILAname, None, None) )
                else:
                    raise CInstException('unrecognized var map type:'+ repr(Cvar)+' for '+ILAname)
            ctlAnnotate[label] += ptrAssign + '\n\t/*********** END of PNT ASSIGN:%s ************/\n' % label 

        # generate control assigns
        for label,varmap in varMap: # for each : label,varmap pair
            controlStr = '\n\t/*********** BEGIN of LABEL:%s ************/\n' % label # if (!__start__) {\n
            vmap = varmap.varmap
            extraControl = varmap.extraControlDict
            for ILAname in vmap:
                if vmap[ILAname] is None:
                    continue
                simValue = s_in[ILAname] # extract value from input state
                if isinstance(vmap[ILAname], tuple): # unpeeling the (Cimpl, Ctype1 tuple)
                    CImpl = vmap[ILAname][0]
                    CType = vmap[ILAname][1]
                else:
                    CImpl = vmap[ILAname]
                    CType = None

                if isinstance(CImpl , str): # direct control
                    # check for signal/fixpoint etc.
                    if CType and CType.type() != SysCrfmaplib.DirectType:
                        if CType.type() == SysCrfmaplib.FixPoint:
                            controlStr += '\t%s = "%s"; \n' % (CImpl, SysCConvertToValue(simValue,CType) )
                        elif CType.type() == SysCrfmaplib.SignalVar:
                            controlStr += '\t%s.write(%s);\n' % (CImpl, SysCConvertToValue(simValue, CType.getWrappedSig() ) )
                        else:
                            raise('CType:%d is not supported' % CType.type() )
                    else:
                        controlStr += '\t%s = %d ;\n' % (CImpl, simValue)
                elif isinstance(CImpl , dict ): # not supported
                    for subname in CImpl:   # bitslice
                        slices = CImpl[subname]
                        controlStr += '\t%s = %d ;\n' % ( subname,getslice(simValue,slices[0],slices[1]) )
                elif isinstance(CImpl, SysCrfmaplib.CArray):  # then simValue should be a memValue
                    # check for signal/fixpoint etc.
                    memValList = simValue.values
                    memValDefault = simValue.default
                    if CType and CType.type() != SysCrfmaplib.DirectType:
                        memValDefault = SysCConvertToValue(memValDefault, CType)
                    
                    cname = CImpl.cname
                    upper = 2 ** ( self._ila_lookup_mem(fsmName,ILAname)[1] )

                    controlStr += memDefTemplate.format(upper = upper, default = memValDefault, cname = cname)
                    for (addr,data) in memValList:
                        if CType and CType.type() != SysCrfmaplib.DirectType:
                            data = SysCConvertToValue(data, CType)
                        controlStr += memCtlTemplate.format(cname = cname, idx = addr, value = data)
                elif isinstance(CImpl, SysCrfmaplib.PC2stateClass):
                    continue # the mapping is actually set by all the labels, not HERE
                else:
                    raise CInstException('unrecognized var map type')
            if extraControl:
                for var in extraControl:
                    # check for signal/fixpoint etc.
                    controlStr += '\t%s = %s;\n' % (var,extraControl[var])
            ctlAnnotate[label] += controlStr  + '\n\t/*********** END of LABEL:%s ************/\n' % label

        # generate collectors
        dumpFunc = self._gen_dump_str(varMap,globalPnt,fsmName)

        if Sep.end is None:
            # add to all 
            for label in ctlAnnotate:
                ctlAnnotate[label] += '\tif (__start__) \n\t\t__end__ = true; \n'
                ctlAnnotate[label] += dumpTemplate;
        else:
            ctlAnnotate[Sep.end] += '\tif (__start__) \n\t\t__end__ = true; \n'
            ctlAnnotate[Sep.end] += dumpTemplate;
        if Sep.begin is None:
            # add to all others
            for label in ctlAnnotate:
                ctlAnnotate[label] += '\t__start__ = true;\n'
        else:
            # add to the only one
            ctlAnnotate[Sep.begin] += '\t__start__ = true;\n'
        # set global:
        ctlAnnotate['@_global'] = ctlGlobalTemplate + globalPntDecl + dumpFunc

        return ctlAnnotate
        
    def annotate(self,s_in,fsmName):
        # first to know about using which sep
        sepItem = self._choose_sep(s_in,fsmName)
        ctlAnnotate = self._translate_to_ctl(sepItem,s_in,fsmName)
        newCcode = self.Cbuffer[:]
        # let's do the annotation
        for k,repl in ctlAnnotate.items():
            label = NameToLabel(k)
            newCcode = newCcode.replace(label,repl) # replace all
        return newCcode
    def genCcode(self,s_in,fsmName):
        newCcode = self.annotate(s_in,fsmName)
        with open(self.cOutName,'wt') as outc:
            outc.write(newCcode)

def test():
    pass
# unit test
if __name__ == '__main__':
    test()
