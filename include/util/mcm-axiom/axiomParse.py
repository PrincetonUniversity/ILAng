import ply.yacc as yacc
import logging
import ParseConfig

import z3 
# This is very important
# we need z3 ability to simplify

# --------------------------------------------------------------------------
#  Simplify AST
# --------------------------------------------------------------------------
from collections import namedtuple
ExprAst = namedtuple('ExprAst', 'val body simpleInfo')
plainDescriptionAst = namedtuple('plainDescriptionAst', 'val simpleInfo')

def NoneSimpInfo():
    return None

class simpInfo(object):
    def __init__(self, z3e, z3vlist = [], simpAux = ''):
        self.z3e = z3e
        self.z3vlist = z3vlist
        self.simpAux = simpAux

def MergeSimpInfo(l,r, op):
    return simpInfo( z3e = op( l.z3e,r.z3e ) , z3vlist = l.z3vlist + r.z3vlist , simpAux

# --------------------------------------------------------------------------
    


from axiomLex import tokens

SIMPLE = True
TAB = True

precedence = (
    ('right', 'BAR'),
    ('right', 'IMPLY'),
    ('left', 'AND', 'OR'),
    ('left', 'NOT' ),
    ('left', 'EQ','NEQ','LT','LE','GT','GE'),
    ('left', 'ADD', 'SUB'),
    ('left', 'MUL')
)


#---AUX------------------
ctr = 0
def uniqueName():
    global ctr
    ctr += 1
    return "var"+str(ctr)
#---AUX------------------


#---AUX------------------
z3ctr = 0
def z3UniqueName():
    global z3ctr
    z3ctr += 1
    return "z3var"+str(z3ctr)
#---AUX------------------



def body(x) : return x.body
def val(x)  : return x.val
def addTab(x):
    splitList = x.split('\n')

    return '\n'.join( ['\t' + l for l in splitList if l and l != '\n'] )

axiomList = []
functionList =  []


#----------------------
#  top: def axiom funcs
#----------------------
def p_top(p):
    """top : defList axiomList functions"""
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
    assert p[1] == 'R' or p[1] == 'W' # R idmacro || W idmacro
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
    pass

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
    #p[2] axiom name: p[3] body
    p[0] = ('\n// ----- AXIOM %s BEGIN -----\n' % p[2]) + body(p[3]) + '\n' + ParseConfig.OutputListName + '.push_back( ' + beg + val(p[3]) + end + ( ');\n// ----- AXIOM %s END -----\n\n' % p[2] )
    if TAB:
        p[0] = addTab(p[0])
    axiomList.append(p[0])

def p_quanexpr_forall(p):
    """expr : FORALL ID COLON typelist BAR expr
        | FORALL ID COLON typelist restriction BAR expr """

	(_,varname,_,typelist) = tuple(p[1:4+1])
    retBody = ''
    retVal  = uniqueName() +'_L'
    retList = uniqueName()
    retBody += 'ZExprVec ' + retVal +';\n'
    retBody += 'for (auto && ' + varname + ' : ' + typelist  + ') { '+' // '+ ' '.join(p[1:5])  + '\n'

    if len(p[1:]) == 7: # has restriction
        (_,_,_,typelist,restriction,_,e) = tuple(p[1:])
        
        retBody += addTab( restriction[1].format(varname = varname) ) + '\n' # if ( ?? == x ) continue
        retBody += addTab( body(e) ) + '\n'  # the body of inside
        expr = val(e)
        retBody += '\t' + restriction[2].format(expr = expr, varname = varname, OPANDIMPLY = 'Implies') # varX = z3.Implies( z3.And( ) , ... )
        retBody += '\t' + retVal + '.push_back( ' +  restriction[0] + '); }\n'
        retBody += retList + ' = Z3ForallList( ' +retVal + ');\n'
        p[0] = ( retList, retBody )
    else: # 6
        (_,_,_,typelist,_,e) = tuple(p[1:])
        retBody += addTab( body(e) ) + '\n'
        expr = val(e)
        retBody += '\t' + retVal + '.push_back( '  + expr +  '); }\n'
        retBody += retList + ' = Z3ForallList( ' +retVal + ');\n'
        p[0] = ( retList, retBody )


def p_quanexpr_exists(p):
    """expr : EXISTS ID COLON typelist BAR expr
        | EXISTS ID COLON typelist restriction BAR expr  """

	(_,varname,_,typelist) = tuple(p[1:4+1])
    retBody = ''
    retVal  = uniqueName() +'_L'
    retList = uniqueName()
    retBody += 'ZExprVec ' + retVal +';\n'
    retBody += 'for (auto && ' + varname + ' : ' + typelist  + ' )  { // exists\n'

    if len(p[1:]) == 7: # has restriction
        (_,_,_,typelist,restriction,_,e) = tuple(p[1:])
        retBody += addTab( restriction[1].format(varname = varname) ) + '\n' # if ( ?? == x ) continue
        retBody += addTab( body(e) ) + '\n'  # the body of inside
        expr = val(e)
        retBody += '\t' + restriction[2].format(expr = expr, varname = varname, OPANDIMPLY = 'And') # varX = z3.Implies( z3.And( ) , ... )
        retBody += '\t' + retVal + '.push_back( ' +  restriction[0] + '); }\n'
        retBody += retList + ' = Z3ExistsList( ' +retVal + ');\n'
        p[0] = ( retList, retBody )
    else: # 6
        (_,_,_,typelist,_,e) = tuple(p[1:])
        retBody += addTab( body(e) ) + '\n'
        expr = val(e)
        retBody += '\t' + retVal + '.push_back( '  + expr +  ')\n'
        retBody += retList + ' = Z3ExistsList( ' +retVal + ')\n'
        p[0] = ( retList, retBody )


    

def p_quanexpr_parath(p):
    """expr : LEFTPARA expr RIGHTPARA  """
    p[0] = ExprAst( '( ' + val(p[2]) + ' )', body(p[2]) , 
             simpleInfo = p.simpleInfo )


def p_quanexpr_logic_and(p):
    """expr : expr AND expr"""
    p[0] = ExprAst( '( ' + val(p[1]) + ' && ' + val(p[3]) +' ) ' , body(p[1]) + body(p[3]) , 
             z3e = z3.And( p[1].z3e , p[3].z3e ) ,
             z3vlist = p[1].z3vlist + p[3].z3vlist )

def p_quanexpr_logic_or(p):
    """expr : expr OR expr"""
    p[0] = ExprAst( '( ' + val(p[1]) + ' || ' + val(p[3]) +' ) ' , body(p[1]) + body(p[3]) , 
             z3e = z3.Or( p[1].z3e , p[3].z3e ) ,
             z3vlist = p[1].z3vlist + p[3].z3vlist )

def p_quanexpr_logic_imply(p):
    """expr : expr IMPLY expr"""
    p[0] = ExprAst( 'z3::implies( ' + val(p[1]) + ' , ' + val(p[3]) +' ) ' , body(p[1]) + body(p[3]) , 
             z3e = z3.Imply( p[1].z3e , p[3].z3e ) ,
             z3vlist = p[1].z3vlist + p[3].z3vlist )


def p_quanexpr_logic_not(p):
    """expr : NOT expr"""
    p[0] = ExprAst('!( ' + val(p[2]) + ' ) ' , body(p[2])
             z3e = z3.Not( p[2].z3e ) ,
             z3vlist = p[2].z3vlist )


def p_quanexpr_plain(p):
    """expr : plainDescription"""
    p[0] = ( p[1], '' , z3e = p[1].z3e, z3vlist = p[1].z3vlist ) # empty body


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
        p[0] = plainDescriptionAst( p[1], z3e = z3.Bool(z3UniqueName()), z3vlist = [] ) # create z3var but uncontrolled
    elif len(p[1:]) == 3:
        p[0] = plainDescriptionAst( p[1] + p[2] + p[3], z3e = z3.Bool(z3UniqueName()), z3vlist = [] ) # create z3var but uncontrolled
    elif len(p[1:]) == 4:
        # this is the place we add z3 variable 
        func_replace_val = z3.Bool(z3UniqueName())
        p[0] = plainDescriptionAst( p[1] + ' ( ' + p[3] + ' ) ' , z3e = z3.Bool(z3UniqueName()), z3vlist = [] ) 

def p_compResult(p):
    """compRel : compRel MUL compRel
        | compRel ADD compRel
        | compRel SUB compRel
        | iddot
        """
    if len(p[1:]) == 1: # compRel -> iddot
        # p[1] is a list
        assert len(p[1]) >= 1
        if len(p[1]) == 1:
            p[0] = p[1][0]
        else:
            facet_name = p[1][0]
            attri_name = p[1][1:]
            ret = '__' + ( '_'.join( attri_name ) ) + '( ' + facet_name + ')'
            p[0] = ret
        # convert iddot
    else:
        p[0] = p[1] + p[2] + p[3] 


def p_paramlist(p):
    """paramlist : compRel 
        | compRel COMMA paramlist"""
    if len(p[1:]) == 1:
        p[0] = p[1]
    else:
        p[0] = p[1] + ' , ' + p[3]


def p_iddot(p):
    """iddot : ID 
        | ID DOT iddot"""
    if len(p[1:]) == 1:
        p[0] = [p[1]]
    else:
        p[0] = [p[1]] + p[3]


def p_restriction(p): # return (val, body)
    """restriction : LEFTPARA reslist RIGHTPARA"""
    staticComp = []
    condList = []
    for static,text in p[2]:
        if static:
            staticComp.append(text)
        else:
            condList.append(text) 


    retText = ''

    for s in staticComp:
        retText += 'if  ( {varname}.name() == ' + s + '.name() ) continue; \n'
    retId = uniqueName()
    
    if len(condList) == 0:
        cond = 'ctx_.bool_val(true)'
    elif len(condList) == 1:
        cond = condList[0]
    else:
        cond = '( '+' && '.join(condList)+' )' 
    #cond =  condList[0] if len(condList) == 1 else 'z3.And( '+' , '.join(condList)+' )' 
    finalLine = retId + (' = Z3{OPANDIMPLY}( %s , {expr} );\n' % (cond) )  # this line was finalLine = retId + (' = z3.Implies( %s , {expr} )\n' % (cond) )
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
    p[0] = (0, '__' + p[1] + '({varname})') # a condition

def p_res_NEQSTATIC(p):
    """res : NEQSTATIC ID """
    p[0] = (1,p[2]) # static not another trace step

def p_res_NOT_ID(p):
    """res : NOT ID"""
    p[0] = (0,'!(__' + p[2] + '({varname}))' )


def p_typelist(p):
    """typelist : type 
        | LEFTPARA tps RIGHTPARA"""
    if len(p[1:]) == 1:
        p[0] = p[1]
    else:
        p[0] = p[2] 

    pass

def p_tps(p):
    """tps : type 
        | type COMMA tps"""
    if len(p[1:]) == 1:
        p[0] = p[1]
    else:
        p[0] = p[1] + ' + ' + p[3]
    

def p_type(p):
    """type : ID"""
    p[0] = ParseConfig.InputObjName + p[1] + '_list'




logging.basicConfig(
    level = logging.DEBUG,
    filename = "parselog.txt",
    filemode = "w",
    format = "%(filename)10s:%(lineno)4d:%(message)s"
)

log = logging.getLogger()




# Error rule for syntax errors
def p_error(p):
    print("Syntax error in input!")
    print p


def parseAixomTest(fname, fout):
    #global AlterLists
    #AlterLists = []
    parser = yacc.yacc( debug=True,debuglog=log)
    with open(fname) as fin:
        parser.parse( fin.read() , debug = log )

    with open(fout,'w') as fout:
        fout.write( '\n'.join( axiomList ) )

if __name__ == '__main__':
    parseAixomTest( ParseConfig.InputFile , ParseConfig.OutputFile )
