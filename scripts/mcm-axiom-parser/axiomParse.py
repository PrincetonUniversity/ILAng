import ply.yacc as yacc
import logging
import ParseConfig

import z3
import re
# This is very important
# we need z3 ability to simplify

# --------------------------------------------------------------------------
#  Simplify AST
# --------------------------------------------------------------------------
from collections import namedtuple
ExprAst = namedtuple('ExprAst', 'val body simpleInfo')
plainDescriptionAst = namedtuple('plainDescriptionAst', 'val simpleInfo')

z3vNameToFunc = {}


def NoneSimpInfo():
    return None


class ExprAst(object):
    def __init__(self, val, body, simpleInfo=None):
        if isinstance(val, str):
            self.val = repText(val)
        else:
            self.val = val
        if isinstance(body, str):
            self.body = repText(body)
        else:
            self.body = body
        self.simpleInfo = simpleInfo


class simpInfo(object):
    def __init__(self, z3e, z3vlist=[], simpAux=''):
        self.z3e = z3e
        self.z3vlist = z3vlist
        self.simpAux = simpAux


def MergeSimpInfo(l, r, op):
    if l is None:
        return r
    if r is None:
        return l
    return simpInfo(z3e=op(l.z3e, r.z3e),
                    z3vlist=l.z3vlist + r.z3vlist, simpAux='')

# --------------------------------------------------------------------------


class repText(object):
    def __init__(self, text, labelList=set([])):
        self.text = text
        # find
        strlabelList = set(
            re.findall(
                r'\{[A-Za-z0-9_]+?\}',
                self.text))  # not greedy
        if len(labelList) == 0 and '{' in text and '}' in text:
            # find '{simp}' in text, record in labelList
            self.labelList = strlabelList
        else:
            if not labelList.issuperset(strlabelList):
                print text
                print labelList
                print strlabelList
            assert labelList.issuperset(strlabelList)
            self.labelList = labelList

    def __add__(self, obj):
        if isinstance(obj, str):
            return repText(self.text + obj)
        assert isinstance(obj, repText)
        # will recalculate label List
        return repText(self.text + obj.text,
                       labelList=self.labelList | obj.labelList)

    def __radd__(self, lobj):
        if isinstance(lobj, str):
            return repText(lobj + self.text)
        assert isinstance(lobj, repText)
        return repText(lobj.text + self.text,
                       labelList=lobj.labelList | self.labelList)

    def format(self, **keys):  # a =  123
        retLabel = self.labelList.copy()
        retText = self.text[:]

        for k, v in keys.items():
            searchStr = '{' + k + '}'
            retLabel.discard(k)
            if isinstance(v, repText):
                subsStr = v.text
                retLabel = retLabel | v.labelList
            else:
                subsStr = str(v)
            retText = retText.replace(searchStr, subsStr)
        return repText(retText, retLabel)

    def get(self):
        if not (len(self.labelList) == 0 or len(
                re.findall(r'\{[A-Za-z0-9_]+?\}', self.text)) == 0):
            print self.text
            print self.labelList
            print re.findall(r'\{[A-Za-z0-9_]+?\}', self.text)
        assert(len(self.labelList) == 0 or len(
            re.findall(r'\{[A-Za-z0-9_]+?\}', self.text)) == 0)
        return self.text

    def __str__(self):
        return self.get()


# ---------------------FUNC LISTINGS--------------------------------------

ArgTypeTs = 0
ArgTypeState = 1
ArgTypeTsPtr = 2

FunctionDeclList = [
    ('SameAddress', [ArgTypeTs, ArgTypeTs, ArgTypeState]),
    ('SameData', [ArgTypeTs, ArgTypeTs, ArgTypeState]),
    ('HB', [ArgTypeTs, ArgTypeTs]),
    ('Sync', [ArgTypeTs, ArgTypeTs]),
    ('SameCore', [ArgTypeTs, ArgTypeTs]),
    ('Decode', [ArgTypeTs])]

# Not included: PO

# --------------------------------------------------------------------------

from axiomLex import tokens

SIMPLE = True
TAB = True

precedence = (
    ('right', 'BAR'),
    ('right', 'IMPLY'),
    ('left', 'AND', 'OR'),
    ('left', 'NOT'),
    ('left', 'EQ', 'NEQ', 'LT', 'LE', 'GT', 'GE'),
    ('left', 'ADD', 'SUB'),
    ('left', 'MUL')
)


#---AUX------------------
ctr = 0


def uniqueName():
    global ctr
    ctr += 1
    return "var" + str(ctr)
#---AUX------------------


#---AUX------------------
z3ctr = 0


def z3UniqueName():
    global z3ctr
    z3ctr += 1
    return "z3var" + str(z3ctr)
#---AUX------------------


def body(x): return x.body


def val(x): return x.val


def addTab(x):
    if isinstance(x, repText):
        x = x.text
        splitList = x.split('\n')
        return repText(
            '\n'.join(['\t' + l for l in splitList if l and l != '\n']))

    assert isinstance(x, str)
    splitList = x.split('\n')
    return '\n'.join(['\t' + l for l in splitList if l and l != '\n'])


axiomList = []
functionList = []


#----------------------
#  top: def axiom funcs
#----------------------
def p_top(p):
    """top : defList functions axiomList"""
    pass


#----------------------
#  defs
#----------------------

def p_defList(p):
    """defList : defs"""
    pass


def p_defs(p):
    """defs : def defs
        | empty"""
    pass


def p_def(p):
    """def : preddef
        | cmpdef"""
    pass


def p_preddef(p):
    """preddef : INSTSET ID LEFTBRACKET predexpr RIGHTBRACKET fevtdefs"""
    pass


def p_fevtdefs(p):
    """fevtdefs : fevtdef fevtdefs
        | empty"""
    pass


def p_cmpdef(p):
    """cmpdef : INSTSET ID ASSIGN LEFTBRACKET cmpexpr RIGHTBRACKET"""
    pass

#----------------------
#  facet event def
#----------------------


def p_fevtdef(p):
    """fevtdef : WITHFACETEVENT iddot LEFTBRACKET updatelist RIGHTBRACKET"""
    pass


def p_updatelist(p):
    """updatelist : update
        | update COMMA updatelist"""
    pass


def p_update(p):
    """update : ID idmacro"""
    assert p[1] == 'R' or p[1] == 'W'  # R idmacro || W idmacro
    pass

#----------------------
#  pred expr
#----------------------


def p_preds_singleton(p):
    """predexpr : pred"""
    pass


def p_preds_para(p):
    """predexpr : LEFTPARA predexpr RIGHTPARA"""
    pass


def p_preds_unary(p):
    """predexpr : NOT predexpr"""
    pass


def p_preds_binary(p):
    """predexpr : predexpr AND predexpr
        | predexpr OR predexpr
        | predexpr IMPLY predexpr"""
    pass


def p_pred(p):
    """pred : ILANAME idmacro
        | ILAWRITE idmacro
        | ILAREAD idmacro"""
    pass


def p_idmacro(p):
    """idmacro : ID
        | MACRO"""
    pass

#----------------------
#  cmp expr
#----------------------

# this is the name of set that should be previously defined
# we should not solve the problem of deciding the order of definition


def p_cmpexpr_singleton(p):
    """cmpexpr : ID"""
    pass


def p_cmpexpr_para(p):
    """cmpexpr : LEFTPARA cmpexpr RIGHTPARA"""
    pass

# BAR SETAND SUB SETXOR


def p_cmpexpr_binary(p):
    """cmpexpr : cmpexpr BAR cmpexpr
        | cmpexpr SETAND cmpexpr
        | cmpexpr SUB cmpexpr
        | cmpexpr SETXOR cmpexpr"""
    pass


#----------------------
#  func
#----------------------

def p_functions(p):
    """functions : funcs """
    pass


def p_funcs(p):
    """funcs : func funcs
        | empty"""


def p_empty(p):
    """empty :"""
    pass


def p_function(p):
    """func : DEFINE ID LEFTFUNC paramlist RIGHTFUNC ASSIGN expr
        | DEFINE ID LEFTPARA paramlist RIGHTPARA ASSIGN expr"""
    (_, iden, _, paramlist, _, _, expr) = tuple(p[1:])

    # here we do the simplification
    restrict = static_simplify(expr.simpleInfo.z3e, expr.simpleInfo.z3vlist)
    restrict = restrict.format(res='return') + '\n'

    retStr = 'z3::expr ' + ParseConfig.AxiomName + '::' + iden + '( '
    retStr += ','.join(['const TraceStepPtr &' + x for x in paramlist])
    retStr += ') {\n'
    retStr += addTab(str(expr.body))
    if (restrict):
        retStr += addTab(str(restrict)) + '\n'
    retStr += '\treturn ( ' + expr.val + ' );\n}\n'

    p[0] = str(retStr)
    functionList.append(p[0])
    FunctionDeclList.append((str(iden), [ArgTypeTsPtr] * len(paramlist)))


def p_axioms(p):
    """axiomList : axiomList axiom
        | axiom"""
    if len(p[1:]) == 2:
        p[0] = p[1] + [p[2]]
    else:
        p[0] = [p[1]]


def p_axiom(p):
    """axiom : AXIOM ID expr """
    beg = ''
    end = ''
    # p[2] axiom name: p[3] body
    p[0] = ('\n// ----- AXIOM %s BEGIN -----\n' % p[2]) + str(body(p[3])) + '\n' + ParseConfig.OutputListName + \
        '.push_back( ' + beg + str(val(p[3])) + end + \
        (');\n// ----- AXIOM %s END -----\n\n' % p[2])
    if TAB:
        p[0] = addTab(p[0])
    axiomList.append(p[0])


def p_quanexpr_forall(p):
    """expr : FORALL ID COLON typelist BAR expr
        | FORALL ID COLON typelist restriction BAR expr """
    (_, varname, _, typelist) = tuple(p[1:4 + 1])
    expr = p[7] if len(p[1:]) == 7 else p[6]
    retBody = ''
    retVal = uniqueName() + '_L'
    retList = uniqueName()
    retBody += 'ZExprVec ' + retVal + ';\n'
    retBody += 'for (auto && ' + varname + ' : ' + typelist + \
        ') { ' + ' // ' + ' '.join(p[1:5]) + '\n'

    retSimpleInfo = simpInfo(z3e=z3.Bool(z3UniqueName()), z3vlist=[])
    extra_restrict = static_determine(
        expr.simpleInfo.z3e, expr.simpleInfo.z3vlist, True)
    print extra_restrict

    CurrentVarAccType = 'CurrentVarAccType'
    QAccTypeName = varname + 'AccType'
    QAccType = "HINT_READ" if typelist == "READ_list" else (
        "HINT_WRITE" if typelist == "WRITE_list" else "HINT_NONE")
    VarAccessType = "READ" if typelist == "READ_list" else (
        "WRITE" if typelist == "WRITE_list" else "EITHER")
    nameKey = {QAccTypeName: QAccType, CurrentVarAccType: VarAccessType}

    if len(p[1:]) == 7:  # has restriction
        (_, _, _, typelist, restriction, _, e) = tuple(p[1:])

        # if ( ?? == x ) continue
        retBody += addTab(restriction[1].format(varname=varname)) + '\n'
        if extra_restrict:
            retBody += addTab(extra_restrict)  # if( SameCore ... )
        retBody += addTab(body(e)) + '\n'  # the body of inside
        expr = val(e)
        # varX = z3.Implies( z3.And( ) , ... )
        retBody += '\t' + \
            restriction[2].format(
                expr=expr,
                varname=varname,
                OPANDIMPLY='Implies')
        retBody += '\t' + retVal + '.push_back( ' + restriction[0] + '); }\n'
        retBody += 'ZExpr ' + retList + ' = Z3ForallList( ' + retVal + ');\n'
        p[0] = ExprAst(
            retList,
            retBody.format(
                **nameKey),
            simpleInfo=retSimpleInfo)
    else:  # 6
        (_, _, _, typelist, _, e) = tuple(p[1:])
        if extra_restrict:
            retBody += addTab(extra_restrict)  # if( SameCore ... )
        retBody += addTab(body(e)) + '\n'
        expr = val(e)
        retBody += '\t' + retVal + '.push_back( ' + expr + '); }\n'
        retBody += 'ZExpr ' + retList + ' = Z3ForallList( ' + retVal + ');\n'
        p[0] = ExprAst(
            retList,
            retBody.format(
                **nameKey),
            simpleInfo=retSimpleInfo)


def p_quanexpr_exists(p):
    """expr : EXISTS ID COLON typelist BAR expr
        | EXISTS ID COLON typelist restriction BAR expr  """

    (_, varname, _, typelist) = tuple(p[1:4 + 1])
    retBody = ''
    retVal = uniqueName() + '_L'
    retList = uniqueName()
    retBody += 'ZExprVec ' + retVal + ';\n'
    retBody += 'for (auto && ' + varname + ' : ' + typelist + \
        ' )  { // ' + ' '.join(p[1:5]) + '\n'

    CurrentVarAccType = 'CurrentVarAccType'
    QAccTypeName = varname + 'AccType'
    QAccType = "HINT_READ" if typelist == "READ_list" else (
        "HINT_WRITE" if typelist == "WRITE_list" else "HINT_NONE")
    VarAccessType = "READ" if typelist == "READ_list" else (
        "WRITE" if typelist == "WRITE_list" else "EITHER")
    nameKey = {QAccTypeName: QAccType, CurrentVarAccType: VarAccessType}

    retSimpleInfo = simpInfo(z3e=z3.Bool(z3UniqueName()), z3vlist=[])

    if len(p[1:]) == 7:  # has restriction
        (_, _, _, typelist, restriction, _, e) = tuple(p[1:])
        # if ( ?? == x ) continue
        retBody += addTab(restriction[1].format(varname=varname)) + '\n'
        retBody += addTab(body(e)) + '\n'  # the body of inside
        expr = val(e)
        # varX = z3.Implies( z3.And( ) , ... )
        retBody += '\t' + \
            restriction[2].format(expr=expr, varname=varname, OPANDIMPLY='And')
        retBody += '\t' + retVal + '.push_back( ' + restriction[0] + '); }\n'
        retBody += 'ZExpr ' + retList + ' = Z3ExistsList( ' + retVal + ');\n'
        p[0] = ExprAst(
            retList,
            retBody.format(
                **nameKey),
            simpleInfo=retSimpleInfo)
    else:  # 6
        (_, _, _, typelist, _, e) = tuple(p[1:])
        retBody += addTab(body(e)) + '\n'
        expr = val(e)
        retBody += '\t' + retVal + '.push_back( ' + expr + ')\n'
        retBody += 'ZExpr ' + retList + ' = Z3ExistsList( ' + retVal + ')\n'
        p[0] = ExprAst(
            retList,
            retBody.format(
                **nameKey),
            simpleInfo=retSimpleInfo)


def p_quanexpr_parath(p):
    """expr : LEFTPARA expr RIGHTPARA  """
    p[0] = ExprAst('( ' + val(p[2]) + ' )', body(p[2]),
                   simpleInfo=p[2].simpleInfo)


def p_quanexpr_logic_and(p):
    """expr : expr AND expr"""
    p[0] = ExprAst('( ' + val(p[1]) + ' && ' + val(p[3]) + ' ) ', body(p[1]) + body(p[3]),
                   simpleInfo=MergeSimpInfo(p[1].simpleInfo, p[3].simpleInfo, z3.And))


def p_quanexpr_logic_or(p):
    """expr : expr OR expr"""
    p[0] = ExprAst('( ' + val(p[1]) + ' || ' + val(p[3]) + ' ) ', body(p[1]) + body(p[3]),
                   simpleInfo=MergeSimpInfo(p[1].simpleInfo, p[3].simpleInfo, z3.Or))


def p_quanexpr_logic_imply(p):
    """expr : expr IMPLY expr"""
    p[0] = ExprAst('z3::implies( ' + val(p[1]) + ' , ' + val(p[3]) + ' ) ', body(p[1]) + body(p[3]),
                   simpleInfo=MergeSimpInfo(p[1].simpleInfo, p[3].simpleInfo, z3.Implies))


def p_quanexpr_logic_not(p):
    """expr : NOT expr"""
    p[0] = ExprAst('!( ' + val(p[2]) + ' ) ', body(p[2]),
                   simpleInfo=simpInfo(z3e=z3.Not(p[2].simpleInfo.z3e), z3vlist=p[2].simpleInfo.z3vlist))


def p_quanexpr_plain(p):
    """expr : plainDescription"""
    p[0] = ExprAst(p[1].val, '',
                   simpleInfo=p[1].simpleInfo)  # empty body


def p_plainDescript(p):
    """plainDescription : compRel
        | compRel EQ compRel
        | compRel NEQ compRel
        | compRel LT compRel
        | compRel GT compRel
        | compRel LE compRel
        | compRel GE compRel
        | ID LEFTFUNC paramlist RIGHTFUNC"""
    if len(p[1:]) == 1:
        p[0] = plainDescriptionAst(
            repText(
                p[1]), simpInfo(
                z3e=z3.Bool(
                    z3UniqueName()), z3vlist=[]))  # create z3var but uncontrolled
    elif len(p[1:]) == 3:
        p[0] = plainDescriptionAst(
            repText(
                p[1] + p[2] + p[3]),
            simpInfo(
                z3e=z3.Bool(
                    z3UniqueName()),
                z3vlist=[]))  # create z3var but uncontrolled
    elif len(p[1:]) == 4:
        iden, _, paramlist, _ = p[1:]
        # function application
        # this is the place we add z3 variable
        # checking Type : for internal functions
        paramGenList = []
        for func_name, argList in FunctionDeclList:
            argNo = len(argList)
            if func_name == iden:
                if len(paramlist) != argNo:
                    print 'Error: argNo required:', argNo, ' provided:', len(
                        paramlist)
                    exit(1)
                # for each arg, treat it differently
                print func_name, argList
                for paramIdx, param in enumerate(paramlist):
                    argType = argList[paramIdx]
                    if argType == ArgTypeTs:
                        paramGenList.append('*' + param)
                    else:
                        paramGenList.append(param)
                break
        else:  # not found
            # otherwise treated as all Ts Type
            paramGenList = ['*' + x for x in paramlist]

        print paramGenList
        applyText = ','.join(paramGenList)
        # special handling
        if iden in ['SameAddress', 'SameData']:
            larg = paramlist[0]
            rarg = paramlist[1]
            sname = paramlist[2]
            lhint = 'AxiomFuncHint::{' + larg + 'AccType}'
            rhint = 'AxiomFuncHint::{' + rarg + 'AccType}'
            applyText += ',' + lhint + ',' + rhint

        # track expression using z3
        z3vName = z3UniqueName()
        func_replace_val = z3.Bool(z3vName)
        func_repl_list = [func_replace_val] if iden in ['SameCore'] else []
        z3vNameToFunc[z3vName] = (
            func_replace_val, repText(
                iden + ' ( ' + applyText + ' ) '))
        p[0] = plainDescriptionAst(
            repText(
                iden + ' ( ' + applyText + ' ) '),
            simpInfo(
                z3e=func_replace_val,
                z3vlist=func_repl_list))


def p_compResult(p):
    """compRel : compRel MUL compRel
        | compRel ADD compRel
        | compRel SUB compRel
        | iddot
        """
    if len(p[1:]) == 1:  # compRel -> iddot
        # p[1] is a list
        assert len(p[1]) >= 1
        if len(p[1]) == 1:
            p[0] = p[1][0]
        else:
            facet_name = p[1][0]
            attri_name = p[1][1:]
            ret = '__' + ('_'.join(attri_name)) + '( ' + facet_name + ')'
            p[0] = ret
        # convert iddot
    else:
        p[0] = p[1] + p[2] + p[3]


def p_paramlist(p):
    """paramlist : compRel
        | compRel COMMA paramlist"""
    if len(p[1:]) == 1:
        p[0] = [p[1]]  # make a single elem list
    else:
        p[0] = [p[1]] + p[3]


def p_iddot(p):
    """iddot : ID
        | ID DOT iddot"""
    if len(p[1:]) == 1:
        p[0] = [p[1]]
    else:
        p[0] = [p[1]] + p[3]


def p_restriction(p):  # return (val, body)
    """restriction : LEFTPARA reslist RIGHTPARA"""
    staticDistinctComp = []
    staticStateAccComp = []
    condList = []
    for static, text in p[2]:
        if static == 1:  # static distinct
            staticDistinctComp.append(text)
        elif static == 2:  # static access state check
            staticStateAccComp.append(text)
        else:
            condList.append(text)

    retText = repText('')

    for s in staticDistinctComp:
        retText += repText('if  ( {varname}->name() == ' +
                           s + '->name() ) continue; \n')
    for s in staticStateAccComp:  # this creates 's'AccType
        retText += repText(
            'if  ( ! {varname}->Access(AccessType::{CurrentVarAccType}, ' + s + ') ) continue;')
    retId = uniqueName()

    if len(condList) == 0:
        cond = '_ctx_.bool_val(true)'
    elif len(condList) == 1:
        cond = condList[0]
    else:
        cond = '( ' + ' && '.join(condList) + ' )'
    #cond =  condList[0] if len(condList) == 1 else 'z3.And( '+' , '.join(condList)+' )'
    # this line was finalLine = retId + (' = z3.Implies( %s , {expr} )\n' %
    # (cond) )
    finalLine = repText('ZExpr ' +
                        retId +
                        (' = Z3{OPANDIMPLY}( %s , {expr} );\n' %
                         (cond)))
    p[0] = (retId, retText, finalLine)


def p_reslist(p):
    """reslist : res
        | res COMMA reslist"""
    if len(p[1:]) == 1:
        p[0] = [p[1]]
    else:
        p[0] = [p[1]] + p[3]

    # if ( ? == ? ) continue
    # z3.Imples( z3.And( , , ), ... )


def p_res_ID(p):
    """res : ID"""
    p[0] = (
        0,
        '__' +
        p[1] +
        '({varname})')  # a condition, which should be converted to a function? like DECODE ?


def p_res_AccessState(p):
    """res : MACRO"""
    p[0] = (2, p[1][1:])  # remove the '%'


def p_res_NEQSTATIC(p):
    """res : NEQSTATIC ID """
    p[0] = (1, p[2])  # static not another trace step


def p_res_NOT_ID(p):
    """res : NOT ID"""
    p[0] = (0, '!(__' + p[2] + '({varname}))')


def p_typelist_InstrSet(p):
    """typelist : ID"""
    p[0] = ParseConfig.InputObjName + p[1] + '_list'


def p_stateset_StateSet(p):
    """typelist : MACRO"""
    if p[1] == r'%shared':  # predefined state set
        p[0] = "m_shared_state_names"
    else:
        p[0] = ParseConfig.InputObjName + p[1] + '_stateset'


def static_simplify(z3e, z3vlist):
    list_of_check = []
    for v in z3vNameToFunc.values():
        list_of_check.append(v[0])

    retStr = ''
    for v in z3vlist:
        s = z3.Solver()
        s.add(z3e)
        print z3e
        print v
        print list_of_check
        _, consqs = s.consequences([v], list_of_check)
        print consqs
        for consq in consqs:
            varName = str(consq).split(',')[1][1:-1]
            if varName == str(v):
                continue

            funcToCheck = z3vNameToFunc[str(v)][1]
            if varName in z3vNameToFunc:
                funcToUse = z3vNameToFunc[varName][1]
                retStr += 'if (' + funcToCheck + \
                    ' ) {res} ' + funcToUse + '; \n'
        s.reset()
        s.add(z3e)
        _, consqs = s.consequences([z3.Not(v)], list_of_check)
        print consqs
        for consq in consqs:
            varName = str(consq).split(',')[1][1:-1]

            funcToCheck = z3vNameToFunc[str(v)][1]
            if varName in z3vNameToFunc:
                funcToUse = z3vNameToFunc[varName][1]
                retStr += 'if ( !' + funcToCheck + \
                    ' ) {res} ' + funcToUse + '; \n'
    return retStr


def static_determine(z3e, z3vlist, expectTorF):
    retStr = ''
    for v in z3vlist:
        s = z3.Solver()
        s.add(v)
        if expectTorF:  # expect True
            s.add(z3.Not(z3e))
        else:
            s.add(z3e)
        res = str(s.check())
        if res == 'unsat':  # okay we got it
            funcToCheck = z3vNameToFunc[str(v)][1]
            retStr += 'if ( ' + funcToCheck + ' ) continue;\n'

        s2 = z3.Solver()
        s2.add(z3.Not(v))
        if expectTorF:  # expect True
            s2.add(z3.Not(z3e))
        else:
            s2.add(z3e)
        res = str(s2.check())
        if res == 'unsat':  # okay we got it
            funcToCheck = z3vNameToFunc[str(v)][1]
            retStr += 'if ( !' + funcToCheck + ' ) continue;\n'

    return retStr


logging.basicConfig(
    level=logging.DEBUG,
    filename="parselog.txt",
    filemode="w",
    format="%(filename)10s:%(lineno)4d:%(message)s"
)

log = logging.getLogger()


# Error rule for syntax errors
def p_error(p):
    print("Syntax error in input!")
    print p


def parseAixomTest(fname, fout):
    #global AlterLists
    #AlterLists = []
    parser = yacc.yacc(debug=True, debuglog=log)
    with open(fname) as fin:
        parser.parse(fin.read(), debug=log)

    with open(fout, 'w') as fout:
        fout.write('\n'.join(axiomList))
        fout.write('\n // ------------------- Functions ----------------------\n')
        fout.write('\n'.join(functionList))


if __name__ == '__main__':
    parseAixomTest(ParseConfig.InputFile, ParseConfig.OutputFile)
