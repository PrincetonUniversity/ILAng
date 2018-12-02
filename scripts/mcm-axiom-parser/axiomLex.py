
import ply.lex as lex

reserved = {
    'forall':'FORALL',
    'exists' : 'EXISTS',
    'Define': 'DEFINE',
    'Axiom' : 'AXIOM' ,
    'InstructionSet' : 'INSTSET',
    'ila-inst-read' : 'ILAREAD',
    'ila-inst-write' : 'ILAWRITE',
    'ila-inst-name' : 'ILANAME',
    'with-facet-event' : 'WITHFACETEVENT'
}

tokens = [
    'MACRO',
    'ID',
    'DOT',
    'COMMA',
    'BAR',
    'LEFTPARA',
    'RIGHTPARA',
    'AND',
    'OR',
    'NOT',
    'NEQSTATIC',
    'IMPLY',
    'EQ',
    'NEQ',
    'LT',
    'GT',
    'GE',
    'LE',
    'ADD',
    'SUB',
    'MUL',
    'LEFTFUNC',
    'RIGHTFUNC',
    'LEFTBRACKET',
    'RIGHTBRACKET',
    'SETAND',
    'SETXOR',
    'ASSIGN',
    'COLON'] + list(reserved.values())



def t_MACRO(t):
    r'\%[a-zA-Z_][a-zA-Z_0-9\-]*'
    t.type = 'MACRO'
    return t

def t_ID(t):
    r'[a-zA-Z_][a-zA-Z_0-9\-]*'
    t.type = reserved.get(t.value,'ID')
    return t

t_DOT = r'\.'
t_COLON = r'\:'
t_COMMA = r'\,'
t_BAR = r'\|'

def t_COMMENT(t):
    r'\#.*'
    pass

t_LEFTPARA = r'\('
t_RIGHTPARA = r'\)'
t_AND = r'\/\\'
t_OR = r'\\\/'
t_NEQSTATIC = r'\~\='
t_NOT = r'\~'
t_IMPLY = r'=>'
t_EQ = r'=='
t_NEQ = r'!='
t_LEFTFUNC = r'\['
t_RIGHTFUNC = r'\]'
t_LEFTBRACKET = r'\{'
t_RIGHTBRACKET = r'\}'
t_SETAND = r'\&'
t_SETXOR = r'\^'
t_ASSIGN = r'\:='

t_LT = r'\<'
t_GT = r'\>'
t_GE = r'\>\='
t_LE = r'\<\='
t_ADD = r'\+'
t_SUB = r'\-'
t_MUL = r'\*'


# Define a rule so we can track line numbers
def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)


t_ignore  = ' \t'
# Error handling rule
def t_error(t):
    print("Illegal character '%s'" % t.value[0])
    t.lexer.skip(1)

# Build the lexer
lexer = lex.lex()

def test():
    with open('test.axiom') as w:
        lexer.input( w.read() )
    word = lexer.token()
    while word:
        print word
        word = lexer.token()

if __name__ == '__main__':
    test()
