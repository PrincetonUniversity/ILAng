import ply.yacc as yacc
import logging
import ParseConfig

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

def body(x) : return x[1]
def val(x)  : return x[0]
def addTab(x):
    splitList = x.split('\n')

    return '\n'.join( ['\t' + l for l in splitList if l and l != '\n'] )

axiomList = []
functionList =  []

def p_top(p):
    """top : axiomList functions"""
    pass

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
    """func : DEFINE ID LEFTFUNC paramlist RIGHTFUNC FUNCASSIGN expr
        | DEFINE ID LEFTPARA paramlist RIGHTPARA FUNCASSIGN expr"""
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
    beg = ' z3.simplify( ' if SIMPLE else ''
    end = ' ) ' if SIMPLE else ''
    p[0] = ('\n# ----- AXIOM %s BEGIN -----\n' % p[2]) + body(p[3]) + '\n' + ParseConfig.OutputListName + '.append( ' + beg + val(p[3]) + end + ( ')\n# ----- AXIOM %s END -----\n\n' % p[2] )
    if TAB:
        p[0] = addTab(p[0])
    axiomList.append(p[0])

def p_quanexpr_forall(p):
    """expr : FORALL ID COLON typelist BAR expr
        | FORALL ID COLON typelist restriction BAR expr """

    retBody = ''
    retVal  = uniqueName() +'_L'
    retList = uniqueName()
    varname = p[2]
    retBody += retVal +' = []\n'
    retBody += 'for ' + varname + ' in ' + p[4]  + ': '+' # '+ ' '.join(p[1:5])  + '\n'

    if len(p[1:]) == 7: # has restriction
        retBody += addTab( p[5][1].format(varname = varname) ) + '\n' # if ( ?? == x ) continue
        retBody += addTab( body(p[7]) ) + '\n'  # the body of inside
        expr = val(p[7])
        retBody += '\t' + p[5][2].format(expr = expr, varname = varname, OPANDIMPLY = 'Implies') # varX = z3.Implies( z3.And( ) , ... )
        retBody += '\t' + retVal + '.append( ' +  p[5][0] + ')\n'
        retBody += retList + ' = LAnd( ' +retVal + ')\n'
        p[0] = ( retList, retBody )
    else: # 6
        retBody += addTab( body(p[6]) ) + '\n'
        expr = val(p[6])
        retBody += '\t' + retVal + '.append( '  + expr +  ')\n'
        retBody += retList + ' = LAnd( ' +retVal + ')\n'
        p[0] = ( retList, retBody )


def p_quanexpr_exists(p):
    """expr : EXISTS ID COLON typelist BAR expr
        | EXISTS ID COLON typelist restriction BAR expr  """

    retBody = ''
    retVal  = uniqueName() +'_L'
    retList = uniqueName()
    varname = p[2]
    retBody += retVal +' = []\n'
    retBody += 'for ' + varname + ' in ' + p[4]  + ' : # exists\n'

    if len(p[1:]) == 7: # has restriction
        retBody += addTab( p[5][1].format(varname = varname) ) + '\n' # if ( ?? == x ) continue
        retBody += addTab( body(p[7]) ) + '\n'  # the body of inside
        expr = val(p[7])
        retBody += '\t' + p[5][2].format(expr = expr, varname = varname, OPANDIMPLY = 'And') # varX = z3.Implies( z3.And( ) , ... )
        retBody += '\t' + retVal + '.append( ' +  p[5][0] + ')\n'
        retBody += retList + ' = LOr( ' +retVal + ')\n'
        p[0] = ( retList, retBody )
    else: # 6
        retBody += addTab( body(p[6]) ) + '\n'
        expr = val(p[6])
        retBody += '\t' + retVal + '.append( '  + expr +  ')\n'
        if 'var40' in retVal :
            print expr
        retBody += retList + ' = LOr( ' +retVal + ')\n'
        p[0] = ( retList, retBody )


    

def p_quanexpr_parath(p):
    """expr : LEFTPARA expr RIGHTPARA  """
    p[0] = ( '( ' + val(p[2]) + ' )', body(p[2]) )


def p_quanexpr_logic_and(p):
    """expr : expr AND expr"""
    p[0] = ( 'z3.And( ' + val(p[1]) + ' , ' + val(p[3]) +' ) ' , body(p[1]) + body(p[3]) )

def p_quanexpr_logic_or(p):
    """expr : expr OR expr"""
    p[0] = ( 'z3.Or( ' + val(p[1]) + ' , ' + val(p[3]) +' ) ' , body(p[1]) + body(p[3]) )

def p_quanexpr_logic_imply(p):
    """expr : expr IMPLY expr"""
    p[0] = ( 'z3.Implies( ' + val(p[1]) + ' , ' + val(p[3]) +' ) ' , body(p[1]) + body(p[3]) )

def p_quanexpr_logic_not(p):
    """expr : NOT expr"""
    p[0] = ('z3.Not( ' + val(p[2]) + ' ) ' , body(p[2]))


def p_quanexpr_plain(p):
    """expr : plainDescription"""
    p[0] = ( p[1], '' ) # empty body


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
        p[0] = p[1]
    elif len(p[1:]) == 3:
        p[0] = p[1] + p[2] + p[3]
    elif len(p[1:]) == 4:
        p[0] = p[1] + ' ( ' + p[3] + ' ) '

def p_compResult(p):
    """compRel : compRel MUL compRel
        | compRel ADD compRel
        | compRel SUB compRel
        | iddot
        """
    if len(p[1:]) == 1:
        p[0] = p[1]
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
        p[0] = p[1]
    else:
        p[0] = p[1] + '.' + p[3]


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
        retText += 'if  {varname} is ' + s + ': continue \n'
    retId = uniqueName()
    
    if len(condList) == 0:
        cond = 'True'
    elif len(condList) == 1:
        cond = condList[0]
    else:
        cond = 'z3.And( '+' , '.join(condList)+' )' 
    #cond =  condList[0] if len(condList) == 1 else 'z3.And( '+' , '.join(condList)+' )' 
    finalLine = retId + (' = z3.{OPANDIMPLY}( %s , {expr} )\n' % (cond) )  # this line was finalLine = retId + (' = z3.Implies( %s , {expr} )\n' % (cond) )
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
    p[0] = (0,'{varname}.'+p[1])

def p_res_NEQSTATIC(p):
    """res : NEQSTATIC ID """
    p[0] = (1,p[2])

def p_res_NOT_ID(p):
    """res : NOT ID"""
    p[0] = (0,'z3.Not( {varname}.' +  p[2] +' )' )


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
    """type : ID
        | WC
        | RC
        | IC
        | MC """
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
        parser.parse( fin.read() ) #, debug = log )

    with open(fout,'w') as fout:
        fout.write( '\n'.join( axiomList ) )

if __name__ == '__main__':
    parseAixomTest( ParseConfig.InputFile , ParseConfig.OutputFile )
