import re
import json
import Crfmaplib
import CSimRfRelation
## NOTE:
## currently we still need to provide ILA info
## in the future should be incorporated with API directly


### Exception  ###
class CInstException(Exception):
    def __init__ (self,value):
        self.value = value
    def __str__(self):
        return repr(self.value)


def NameToLabel(name):
    return '/*##LABEL##%s##*/' % name
def ConvertAtToUnder(sin):
    return sin.replace('@', '__').replace('.','_')

def FixPointToMF(fp):
    mask = hex(int('0b' + fp.w * '1',2))
    frac = str(2**(fp.w - fp.i))
    return (mask,frac)

globalLabel = '@_global'
gotoLabel   = '@_goto'
MemAssumeForLoopTemplate = """
    for(int idx = 0; idx < {depth}; idx ++)
        __CPROVER_assume( (GM.{ilaname}[idx] & {mask})/( {frac}.0 )  ==  {cname}[idx] );
"""

globalPCStateName = '__pc_state__'

VWrapperTemplate = """
// verification wrapper
#include "model_{fsmName}_class.hpp"
{extraInclude}
model_{fsmName} GM;

#include "{cOutName}"
{CclassName} IMPL;

int main() {{
    // call function 
    {FuncCall};
    return 0;
}}
"""

class SysCInstrument:

    def _find_all_labels(self):
        allLabels = []
        labelPattern = re.compile(r'/\*##LABEL##([A-Za-z0-9_\@\.]+)##\*/')
        self.allLabels = list(set(labelPattern.findall(self.Cbuffer)))
        # no gloabl label needed

    #                   the c src, 
    def __init__(self, cFileName , cOutName = 'verifyExample.cpp', wrapperName = 'vWrapper.cpp' , vmapJsonIn, rfJsonIn):
        self.vmap  = json.loads (open(vmapJsonIn))
        self.rfmap = json.loads (open(rfJsonIn)) #"ref-rel/ref-rel-aes.json"
        #self.uaesrf= json.loads(open("ref-rel/ref-rel-aes_compute.json"))

        self.cFileName   = cFileName
        self.cOutName    = cOutName
        self.wrapperName = wrapperName
        self.annDict     = {} # label name -> c code
        
        with open(cFileName) as cfin:
            self.Cbuffer = cfin.read().replace('main()','dummy_main()')
            self._find_all_labels()  # input CBuffer
            if globalLabel not in self.allLabels:
                raise CInstException('No %s label!' % globalLabel)
        # generated output    
        self.cAnnotate   = '' 

        _, _, self.ilaRef = Crfmaplib.invokeFuncVerif(CSimRfRelation.buildRefMap)

    def ReplaceLabels(self): # will only print it out
        for label,content in self.annDict.items():
            #print '<LABEL:%s>\n%s' % (label,content)
            if label not in self.allLabels:
                raise CInstException('label:%s not defined!' % label)
            self.Cbuffer = self.Cbuffer.replace(NameToLabel(label), content )
        with open(self.cOutName,'w')  as fout:
            fout.write(self.Cbuffer)

    def GenVwrapper(self, level,  CclassName, funlist = ''):
        with open(self.wrapperName,'w') as fout:
            fsmName  = level
            funcCall = 'dummy_main()'

            if funlist == '':
                extraInclude = ''
            else:
                with open(funlist) as fin:
                    srcs = fin.readline()
                if srcs[0:7] != 'SRCS = ':
                    raise CInstException('Line:<' + srcs +'> is not recognizable!')
                srcs = srcs[7:].split()
                extraInclude = ''.join( ['#include "%s"\n'%src for src in srcs] )

            fout.write( VWrapperTemplate.format(fsmName = fsmName, CclassName = CclassName, cOutName = self.cOutName, FuncCall = funcCall, extraInclude = extraInclude) )

    def ConditionItemFromInstName(instname):
        for ConditionItem in self.rfmap["instructions"]:
            if ConditionItem["instruction"] == instname:
                return ConditionItem
        raise CInstException("instname:"+instname+", not found in rfmap!")

    def AnnotateGOTO(self, instname = ''):
        startLabel = self.ConditionItemFromInstName(instname)["start signal"][0]

        if gotoLabel in self.allLabels:
            self.annDict[gotoLabel] = self.annDict.get(gotoLabel, '') + '\n\t\tgoto %s;\n' % ConvertAtToUnder(startLabel)
        else:
            print '<WARN> %s label not set!' % gotoLabel


    # need to use self.AdditionalPCDict in the global
    def AnnotatePCAssign(self):
        self.AdditionalPCDict = []
        
        for name,pcdict in self.refVerifSp.pcdict:
            self.AdditionalPCDict.append(name)
            for label,val in pcdict.items():
                self.annDict[label] = self.annDict.get(label, '') + '\t\t{name} = {val};\n'.format(name = globalPCStateName, val = val)
        
    def Annotate(self, which, CclassName, funlist = ''):
        ConditionItem = self.refVerifSp.sepList[which]
        self.AnnotateGOTO(ConditionItem)  # add goto for @goto label (to the begin of Sep)
        self.AnnotatePCAssign()
        self.AnnotateLabels(ConditionItem)
        self.ReplaceLabels()
        self.GenVwrapper(ConditionItem, CclassName, funlist)


    def _gen_pc_v_decl(self):
        assert(self.AdditionalPCDict is not None)
        retStr = ''
        for name in self.AdditionalPCDict:
            retStr += '\t\tunsigned %s;\n' % name
        return retStr

    def _gen_input_decl(self, fsmref):
        retStr = ''
        for (n,w) in fsmref.state_list:
            if n not in fsmref.port:
                continue
            # only handle port
            # only use their ilaname
            # its type can not be the fixpoint
            tp = 'BV%d' % w
            retStr += '\t{tp} {ilaname}_inp;\n' .format(tp = tp, ilaname = n)
        return retStr
        


    # Internal Gen Functions
    def _gen_pre_assumpt(self, fsmref, ConditionItem, StartN ):
        # ConditionItem is from refVerifSp
        # StartN is to choose which micro-arch to go with

        retStr = ''

        varMap = ConditionItem.varMap[StartN]
        varMapName = varMap[0]; varMapDict = varMap[1].varmap

        for (n,w) in fsmref.state_list: # not memory, but have port as well
            if n not in varMapDict:
                print '<WARN> %s,%d is missing in rfmap, for pre assumpt' % (n,w)
                continue
                #raise CInstException('%s needs to be defined in rfmap'%n)
            #assert( n in varMapDict )
            rfItem = varMapDict[n]

            if n in fsmref.port:
                retStr += '\t\t {cname}.data = {ilaname}_inp;\n' .format(cname = rfItem[0], ilaname = n)
                continue
                #that is it

            if isinstance(rfItem , tuple ):
                # deal with Signal generally ok
                # but Fixed/uFixed are float but in 
                cname, typ = rfItem
                if typ.type() == Crfmaplib.DirectType:
                    retStr += '\t\t {cname} = GM.{ilaname};\n'.format(cname = cname, ilaname = n)
                elif typ.type() == Crfmaplib.SignalVar:
                    retStr += '\t\t {cname}.write( GM.{ilaname} );\n'.format(cname = cname, ilaname = n)
                elif typ.type() == Crfmaplib.FixPoint:
                    mask,frac = FixPointToMF(typ)
                    retStr += '\t\t {cname} = ( GM.{ilaname} & {mask} ) / {frac}.0 ;\n'.format( cname = cname , ilaname = n , mask = mask, frac = frac )
                else:
                    raise CInstException('type unknown for '+ n)

            elif isinstance(rfItem, Crfmaplib.CArray):
                raise CInstException('Rf type mismatch')
            elif isinstance(rfItem, Crfmaplib.PC2stateClass):
                pass # They are not assigned here
            else:
                raise CInstException('type unknown for '+ n)

        for (n,a,d) in fsmref.mem_list:
            if n not in varMapDict:
                print '<WARN> mem %s,%d,%d is not in rfMap for pre assumpt' % (n,a,d)
                continue
            rfItem = varMapDict[n]
            if (not self.willModifyFPMem) and rfItem.ctype.type() == Crfmaplib.FixPoint:
                # let's do it by for loops
                mask,frac = FixPointToMF(typ)
                retStr += MemAssumeForLoopTemplate.format(depth = 2**a, ilaname = n, cname = rfItem.cname, mask = mask, frac = frac)
                continue
            elif rfItem.ctype.type() == Crfmaplib.FixPoint:
                # the other way around is to modify the content
                print '<WARN> In GM, mem:%s needs to be modify to type float!' % n

            if rfItem.cname[-1] == ']' : # 2D array
                retStr += '\t\t __CPROVER_array_copy( {cname}, GM.{ilaname}.arrayPnt );\n' .format(ilaname = n, cname = rfItem.cname)
            else:
                retStr += '\t\t __CPROVER_array_copy( {cname}.arrayPnt, GM.{ilaname}.arrayPnt );\n' .format(ilaname = n, cname = rfItem.cname)

        return retStr

    def _gen_decode_inst_assume(self, ConditionItem, fsmref):  # FIXME: don't use assume
        retStr = ''
        for name,val in ConditionItem.instDecode.items():
            if name in fsmref.port:
                name += '_inp'
            retStr += '\t\t {cname} = {val} ; // __CPROVER_assume( {cname} == {val} );\n' .format(cname = name , val = val)
        return retStr

    def _gen_post_assert(self, fsmref, ConditionItem, StartN ):

        retStr = ''
        varMap = ConditionItem[3]
        varMapName = varMap[0]; varMapDict = varMap[1].varmap

        for (n,w) in fsmref.state_list: # not memory, but have port as well
            if n not in varMapDict:
                print '<WARN> %s,%d is missing in rfmap, for post assert.' % (n,w)
                continue
            rfItem = varMapDict[n]

            if n in fsmref.port:
                # no need
                continue
                #that is it

            if isinstance(rfItem , tuple ):
                # deal with Signal generally ok
                # but Fixed/uFixed are float but in 
                cname, typ = rfItem
                if typ.type() == Crfmaplib.DirectType:
                    retStr += '\t\t __CPROVER_assert( {cname} == GM.{ilaname} , "{ilaname}_match");\n'.format(cname = cname, ilaname = n)
                elif typ.type() == Crfmaplib.SignalVar:
                    retStr += '\t\t __CPROVER_assert( {cname}.read() ==  GM.{ilaname} , "{ilaname}_match");\n'.format(cname = cname, ilaname = n)
                elif typ.type() == Crfmaplib.FixPoint:
                    mask,frac = FixPointToMF(typ)
                    retStr += '\t\t __CPROVER_assert( {cname} == ( GM.{ilaname} & {mask} ) / {frac}.0 , "{ilaname}_match");\n'.format( cname = cname , ilaname = n , mask = mask, frac = frac )
                else:
                    raise CInstException('type unknown for '+ n)

            elif isinstance(rfItem, Crfmaplib.CArray):
                raise CInstException('Rf type mismatch')
            elif isinstance(rfItem, Crfmaplib.PC2stateClass):
                retStr += '\t\t __CPROVER_assert( {cname} == GM.{ilaname} , "{ilaname}_match" );\n'.format(cname = rfItem.name, ilaname = n)  # globalPCStateName 
                # probably remove this assertion anyway
            else:
                raise CInstException('type unknown for '+ n)

        for (n,a,d) in fsmref.mem_list:
            if n not in varMapDict:
                print '<WARN> mem %s,%d,%d is not in rfMap for post assert' % (n,a,d)
                continue
            rfItem = varMapDict[n]
            assert( isinstance(rfItem, Crfmaplib.CArray ) )
            if rfItem.ctype.type() == Crfmaplib.FixPoint:
                # let's do it by for loops
                #mask,frac = FixPointToMF(typ)
                print '<INFO> ignore mem:%s for Fixpoint compare' % n
                retStr += '// {ilaname} is ignored for FixPoint\n'.format(ilaname = n) #MemAssumeForLoopTemplate.format(depth = 2**a, ilaname = n, mask = mask, frac = frac)
            else:
                if rfItem.cname[-1] == ']' : # 2D array
                    retStr += '\t\t __CPROVER_assert( __CPROVER_array_equal( GM.{ilaname}.arrayPnt,  {cname} ) , "{ilaname}_match" );\n' .format(ilaname = n, cname = rfItem.cname)
                else:
                    retStr += '\t\t __CPROVER_assert( __CPROVER_array_equal( GM.{ilaname}.arrayPnt,  {cname}.arrayPnt ) , "{ilaname}_match");\n' .format(ilaname = n, cname = rfItem.cname)

        return retStr
        # start with GM.update...
        #retStr += 'return;\n'
    def _gen_inputList(self,fsmref):
        inp_port = [p+'_inp' for p in fsmref.port ]
        return ' , ' . join (inp_port)

    def AnnotateLabels(self, ConditionItem, StartN):
        Name = ConditionItem.level
        fsmName = Name
        startLabel = ConditionItem.CInstSet.begin
        endLabel   = ConditionItem.CInstSet.end   ### endlabel is ANY???
        fsmref = self.ilaRef.fsm_list[fsmName]
        assert fsmref is not None

        Global = '// global annotation\n'
        Prelog = '\n' + ConvertAtToUnder(startLabel) + ':\n'
        Epilog = '\n' + ConvertAtToUnder(endLabel)   + ':\n'
        Epilog += '\t\tGM.update( ' + self._gen_inputList(fsmref) + ' );\n' #???

        Global += self._gen_input_decl(fsmref) + self._gen_pc_v_decl()
        Prelog += self._gen_decode_inst_assume(ConditionItem, fsmref) + self._gen_pre_assumpt(fsmref, ConditionItem, StartN)
        Epilog += self._gen_post_assert(fsmref, ConditionItem, StartN) 
        Epilog += '\n\t\treturn;\n'

        Global += '\t\t// *** END of global annotation\n'
        Prelog += '\t\t// *** END of LABEL: %s\n' % startLabel
        Epilog += '\t\t// *** END of LABEL: %s\n' % endLabel

        self.annDict[startLabel]  = self.annDict.get(startLabel, '')  + Prelog
        self.annDict[endLabel]    = self.annDict.get(endLabel, '')    + Epilog ### ANY ???
        self.annDict[globalLabel] = self.annDict.get(globalLabel, '') + Global        

    




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