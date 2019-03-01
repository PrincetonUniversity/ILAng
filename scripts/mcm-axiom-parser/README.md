## Axiom Parser

Prerequisite:

-   Python 2.7
-   PLY (Python Lex Yacc) (you can install it from pip)

Info:
1\. In `ParseConfig.py` you can specify the input file
2\. Then run `python axiomParse.py`
3\. This will create an output file: axiom.cpp, where you can find the translated C++ version of axioms and function definitions
4\. Currently this file cannot generate a complete C++ class and its header file, you still need to manually create an axiom module
5\. Examples for TSO/SC can be found in `tso-simple.axiom` and `sc-simple.axiom`
