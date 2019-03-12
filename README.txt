A Generic Parser for SMT-LIB v2
===============================

Alberto Griggio <griggio@fbk.eu>


This is a (complete, I think) parser/lexer for the SMT-LIB v2 language,
implemented in Flex, Bison and C99, released under the MIT license (see
LICENSE.txt). Besides a grammar and an abstract interface for implementing
backends, a sample implementation using the Yices 1 solver
(http://yices.csl.sri.com) is provided. The implementation is not 100%
complete, but it should be enough for understanding how the interface is
supposed to work.


REQUIREMENTS: 
-------------              

- a C99 compiler (tested only under gcc), 
- GNU flex >= 2.5.33
- GNU bison (tested under bison 2.4.1)

For compiling, copy Makefile.in to Makefile, edit the compilation flags and
the YICES_DIR variable, and run make


CONTENTS:
---------

LICENSE.txt: 
  the license file

Makefile.in: 
  Makefile template

smtlib2parserinterface.h:
  abstract interface for implementing backends to the parser

smtlib2abstractparser.h, smtlib2abstractparser.c: 
  an abstract implementation of the parser interface, providing default
  implementation for the callbacks and support for parsing terms  

smtlib2abstractparser_private.h:
  "protected" part of the abstract parser

smtlib2bisonparser.y:
  Bison grammar for the SMT-LIB v2 language, defining a re-entrant parser

smtlib2flexlexer.l:
  Flex definitions for a re-entrant SMT-LIB v2 lexical scanner

smtlib2termparser.c, smtlib2termparser.h:
  helper class for parsing terms and managing let bindings and definitions

smtlib2charbuf.h, smtlib2charbuf.c, smtlib2genvector.h, smtlib2hashtable.c, 
smtlib2hashtable.h, smtlib2scanner.c, smtlib2scanner.h, smtlib2stream.c,
smtlib2stream.h, smtlib2types.h, smtlib2utils.c, smtlib2utils.h, 
smtlib2vector.c, smtlib2vector.h:
  several utility data structures and functions

smtlib2yices.c, smtlib2yices.h, main.c: 
  example backend using the Yices 1 SMT solver


test1.smt2, test2.smt2, test3.smt2, test4.smt2, test5.smt2, test6.smt2:
  small test inputs for the Yices backend
