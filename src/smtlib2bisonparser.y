/* -*- C -*-
 *
 * Bison parser for the SMT-LIB v2 command language
 * 
 * Author: Alberto Griggio <griggio@fbk.eu>
 *
 * Copyright (C) 2010 Alberto Griggio
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

%{
#include "smtlib2parserinterface.h"
#include "smtlib2bisonparser.h"
#include "smtlib2flexlexer.h"
#include <limits.h>
#include <assert.h>

#define YYMAXDEPTH LONG_MAX
#define YYLTYPE_IS_TRIVIAL 1

void smtlib2_parser_error(YYLTYPE *yylloc, yyscan_t scanner,
                          smtlib2_parser_interface *parser,
                          const char *s);

/*
 * Stores information about an identifier. Used to handle type annotations and
 * indexed identifiers, without supporting such things in the core solver
 */
typedef struct smtlib2_indexed_identifier {
    char *name;
    smtlib2_vector *idx;
    smtlib2_sort tp;
} smtlib2_indexed_identifier;

smtlib2_indexed_identifier *smtlib2_indexed_identifier_new(
    const char *n, smtlib2_vector *i, smtlib2_sort t);
void smtlib2_indexed_identifier_delete(smtlib2_indexed_identifier *i);

smtlib2_term smtlib2_make_term_from_identifier(
    smtlib2_parser_interface *parser,
    smtlib2_indexed_identifier *ident, smtlib2_vector *args);

%}

%locations
%pure_parser
%defines
%name-prefix="smtlib2_parser_"
%debug
%verbose

%parse-param {yyscan_t scanner}
%parse-param {smtlib2_parser_interface *parser}
%lex-param {yyscan_t scanner}

%union {
    char *string;
    smtlib2_vector *termlist;
    smtlib2_sort sort;
    smtlib2_vector *sortlist;
    smtlib2_vector *numlist;
    smtlib2_term term;
    void *identifier;
    smtlib2_charbuf *buf;
    char **attribute;
    smtlib2_vector *attributelist;
    smtlib2_vector *stringlist;
    smtlib2_vector *intlist;
};


%token_table

%token <string> BINCONSTANT
%token <string> HEXCONSTANT
%token <string> BVCONSTANT
%token <string> RATCONSTANT
%token <string> NUMERAL
%token <string> STRING
%token <string> SYMBOL
%token <string> KEYWORD
%token TK_EOF

%token TK_AS            "as"
%token TK_UNDERSCORE    "_"
%token TK_LET           "let"
%token TK_BANG          "!"
%token TK_FORALL        "forall"
%token TK_EXISTS        "exists"

%token TK_SET_LOGIC            "set-logic"
%token TK_DECLARE_SORT         "declare-sort"
%token TK_DEFINE_SORT          "define-sort"
%token TK_DECLARE_FUN          "declare-fun"
%token TK_DEFINE_FUN           "define-fun"
%token TK_PUSH                 "push"
%token TK_POP                  "pop"
%token TK_ASSERT               "assert"
%token TK_CHECK_SAT            "check-sat"
%token TK_GET_ASSERTIONS       "get-assertions"
%token TK_GET_UNSAT_CORE       "get-unsat-core"
%token TK_GET_PROOF            "get-proof"
%token TK_SET_OPTION           "set-option"
%token TK_GET_INFO             "get-info"
%token TK_SET_INFO             "set-info"
%token TK_GET_ASSIGNMENT       "get-assignment"
%token TK_GET_MODEL            "get-model"
%token TK_GET_VALUE            "get-value"
%token TK_EXIT                 "exit"
%token TK_INTERNAL_PARSE_TERMS ".internal-parse-terms"

%type <string> logic_name
%type <sort> a_sort
%type <sort> a_sort_param
%type <term> a_term
%type <term> annotated_term
%type <term> plain_term
%type <term> term_num_constant
%type <termlist> term_list

%type <sortlist> sort_list
%type <sortlist> sort_param_list
%type <termlist> quant_var_list
%type <numlist> num_list
%type <intlist> int_list
%type <identifier> term_symbol
%type <identifier> term_unqualified_symbol
%type <string> info_argument

%type <attribute> term_attribute
%type <string> attribute_value
%type <stringlist> attribute_value_list
%type <attributelist> term_attribute_list

%type <string> verbatim_term
%type <stringlist> verbatim_term_list

%destructor { free($$); } BINCONSTANT HEXCONSTANT RATCONSTANT NUMERAL SYMBOL KEYWORD STRING logic_name

%destructor { smtlib2_vector_delete($$); } term_list
%destructor { smtlib2_vector_delete($$); } sort_list
%destructor { smtlib2_vector_delete($$); } sort_param_list
%destructor { smtlib2_vector_delete($$); } quant_var_list
%destructor { smtlib2_vector_delete($$); } num_list int_list
%destructor { smtlib2_indexed_identifier_delete((smtlib2_indexed_identifier *)$$); } term_symbol
%destructor { smtlib2_indexed_identifier_delete((smtlib2_indexed_identifier *)$$); } term_unqualified_symbol
%destructor { smtlib2_vector_delete($$); } term_attribute_list
%destructor { free($$[0]); free($$[1]); free($$); } term_attribute

%start single_command

%%

single_command : command
  {
      YYACCEPT;
  }
;

command :
  cmd_set_logic
| cmd_declare_sort
| cmd_define_sort
| cmd_declare_fun
| cmd_define_fun
| cmd_push
| cmd_pop
| cmd_assert
| cmd_check_sat
| cmd_get_assertions
| cmd_get_unsat_core
| cmd_get_proof
| cmd_set_option
| cmd_get_info
| cmd_set_info
| cmd_get_assignment
| cmd_get_value
| cmd_exit
| cmd_internal_parse_terms
| cmd_error
;

cmd_error : 
  {
      YYERROR;
  }
;


cmd_set_logic : '(' TK_SET_LOGIC logic_name ')'
  {
      parser->set_logic(parser, $3);
      free($3);
  }
;


cmd_declare_sort : '(' TK_DECLARE_SORT SYMBOL NUMERAL ')'
  {
      int n = atoi($4);
      parser->declare_sort(parser, $3, n);
      free($4);
      free($3);
  }
;


cmd_define_sort :
  '(' TK_DEFINE_SORT SYMBOL '(' ')' a_sort ')'
  {
      parser->define_sort(parser, $3, NULL, $6);
      free($3);
  }
| '(' TK_DEFINE_SORT SYMBOL '(' sort_param_list ')' a_sort ')'
  {
      parser->define_sort(parser, $3, $5, $7);
      parser->pop_sort_param_scope(parser);
      smtlib2_vector_delete($5);
      free($3);
  }
;


cmd_declare_fun :
  '(' TK_DECLARE_FUN SYMBOL '(' ')' a_sort ')'
  {
      smtlib2_sort tp = $6;
      parser->declare_function(parser, $3, tp);
      free($3);
  }
| '(' TK_DECLARE_FUN SYMBOL '(' sort_list ')' a_sort ')'
  {
      smtlib2_sort tp = $7;
      assert(smtlib2_vector_size($5) > 0);
      smtlib2_vector_push($5, (intptr_t)tp);
      tp = parser->make_function_sort(parser, $5);
      parser->declare_function(parser, $3, tp);
      free($3);
      smtlib2_vector_delete($5);
  }
;

cmd_define_fun :
  '(' TK_DEFINE_FUN SYMBOL '(' ')' a_sort a_term ')'
  {
      parser->define_function(parser, $3, NULL, $6, $7);
      free($3);
  }
| '(' TK_DEFINE_FUN SYMBOL '(' quant_var_list ')' a_sort a_term ')'
  {
      parser->define_function(parser, $3, $5, $7, $8);
      parser->pop_quantifier_scope(parser);
      free($3);
      smtlib2_vector_delete($5);
  }
;


cmd_push : '(' TK_PUSH NUMERAL ')'
  {
      int n = atoi($3);
      free($3);
      parser->push(parser, n);
  }
;


cmd_pop : '(' TK_POP NUMERAL ')'
  {
      int n = atoi($3);
      free($3);
      parser->pop(parser, n);
  }
;


cmd_assert :
  '(' TK_ASSERT a_term ')'
  {
      parser->assert_formula(parser, $3);
  }
;


cmd_check_sat : '(' TK_CHECK_SAT ')'
  {
      parser->check_sat(parser);
  }
;


cmd_get_assertions : '(' TK_GET_ASSERTIONS ')'
  {
      parser->get_assertions(parser);
  }
;


cmd_get_unsat_core : '(' TK_GET_UNSAT_CORE ')'
  {
      parser->get_unsat_core(parser);
  }
;


cmd_get_proof : '(' TK_GET_PROOF ')'
  {
      parser->get_proof(parser);
  }
;


cmd_set_option :
  '(' TK_SET_OPTION KEYWORD NUMERAL ')'
  {
      int n = atoi($4);
      parser->set_int_option(parser, $3, n);
      free($4);
      free($3);
  }
| '(' TK_SET_OPTION KEYWORD RATCONSTANT ')'
  {
      double n = atof($4);
      parser->set_rat_option(parser, $3, n);
      free($4);
      free($3);
  }
| '(' TK_SET_OPTION KEYWORD SYMBOL ')'
  {
      if (strcmp($4, "true") == 0) {
          parser->set_int_option(parser, $3, 1);
      } else if (strcmp($4, "false") == 0) {
          parser->set_int_option(parser, $3, 0);
      } else if (strcmp($4, "none") == 0) {
          parser->set_rat_option(parser, $3, 0);
      } else {
          free($4);
          free($3);
          YYERROR;
      }
      free($4);
      free($3);
  }
| '(' TK_SET_OPTION KEYWORD STRING ')'
  {
      parser->set_str_option(parser, $3, $4);
      free($4);
      free($3);
  }
;


cmd_get_info : '(' TK_GET_INFO KEYWORD ')'
  {
      parser->get_info(parser, $3);
      free($3);
  }
;


cmd_set_info :
  '(' TK_SET_INFO KEYWORD info_argument ')'
  {
      parser->set_info(parser, $3, $4);
      free($4);
      free($3);
  }
;


info_argument :
  NUMERAL
  {
      $$ = $1;
  }
| RATCONSTANT
  {
      $$ = $1;
  }
| SYMBOL
  {
      $$ = $1;
  }
| STRING
  {
      $$ = $1;
  }
;


cmd_get_assignment : '(' TK_GET_ASSIGNMENT ')'
  {
      parser->get_assignment(parser);
  }
;


cmd_get_value : '(' TK_GET_VALUE '(' verbatim_term_list ')' ')'
  {
      size_t i;
      parser->get_value(parser, $4);
      for (i = 0; i < smtlib2_vector_size($4); ++i) {
          char *s = (char *)smtlib2_vector_at($4, i);
          free(s);
      }
      smtlib2_vector_delete($4);
  }
;


cmd_exit : '(' TK_EXIT ')'
  {
      parser->exit(parser);
  }
;


cmd_internal_parse_terms : '(' TK_INTERNAL_PARSE_TERMS '(' term_list ')' ')'
  {
      parser->set_internal_parsed_terms(parser, $4);
      smtlib2_vector_delete($4);
  }
;

    

a_term :
  annotated_term
  {
      $$ = $1;
  }
| plain_term
  {
      $$ = $1;
  }
;


annotated_term :
  '(' TK_BANG a_term term_attribute_list ')'
  {
      size_t i;
      $$ = $3;
      parser->annotate_term(parser, $$, $4);
      for (i = 0; i < smtlib2_vector_size($4); ++i) {
          char **pair = (char **)smtlib2_vector_at($4, i);
          free(pair[0]);
          free(pair[1]);
          free(pair);
      }
      smtlib2_vector_delete($4);
  }
;


plain_term :
 '(' begin_let_scope '(' let_bindings ')' a_term ')'
  {
      $$ = parser->pop_let_scope(parser);
      if (! $$) {
          $$ = $6;
      }
  }
| '(' TK_FORALL '(' quant_var_list ')' a_term ')'
  {
      smtlib2_term tmp;
      $$ = parser->make_forall_term(parser, $6);
      tmp = parser->pop_quantifier_scope(parser);
      if (tmp) {
          $$ = tmp;
      }
      smtlib2_vector_delete($4);
  }
| '(' TK_EXISTS '(' quant_var_list ')' a_term ')'
  {
      smtlib2_term tmp;
      $$ = parser->make_exists_term(parser, $6);
      tmp = parser->pop_quantifier_scope(parser);
      if (tmp) {
          $$ = tmp;
      }
      smtlib2_vector_delete($4);
  }
| term_num_constant
  {
      $$ = $1;
  }
| term_symbol
  {
      smtlib2_indexed_identifier *id = (smtlib2_indexed_identifier *)$1;
      $$ = smtlib2_make_term_from_identifier(parser, id, NULL);
      smtlib2_indexed_identifier_delete(id);
  }
| '(' term_symbol term_list ')'
  {
      smtlib2_indexed_identifier *id = (smtlib2_indexed_identifier *)$2;
      $$ = smtlib2_make_term_from_identifier(parser, id, $3);
      smtlib2_indexed_identifier_delete(id);
      smtlib2_vector_delete($3);
  }
;


term_symbol :
  term_unqualified_symbol
  { $$ = $1; }
| '(' TK_AS term_unqualified_symbol a_sort ')'
  {
      $$ = $3;
      ((smtlib2_indexed_identifier *)$$)->tp = $4;
  }
;


term_unqualified_symbol :
  SYMBOL
  {
      $$ = smtlib2_indexed_identifier_new($1, NULL, NULL);
      free($1);
  }
| '(' TK_UNDERSCORE SYMBOL num_list ')'
  {
      $$ = smtlib2_indexed_identifier_new($3, $4, NULL);
      free($3);
      /* $$ takes ownership of $4, so we don't delete it here */
  }
;


term_num_constant :
  NUMERAL
  {
      $$ = parser->make_number_term(parser, $1, 0, 10);
      free($1);
  }
| RATCONSTANT
  {
      $$ = parser->make_number_term(parser, $1, 0, 10);
      free($1);
  }
| BINCONSTANT
  {
      const char *s = $1 + 2; /* skip the "#b" prefix */
      $$ = parser->make_number_term(parser, s, strlen(s), 2);
      free($1);
  }
| HEXCONSTANT
  {
      const char *s = $1 + 2; /* skip the "#x" prefix */
      $$ = parser->make_number_term(parser, s, 4 * strlen(s), 16);
      free($1);
  }
| '(' TK_UNDERSCORE BVCONSTANT NUMERAL ')'
  {
      const char *s = $3 + 2; /* skip the "bv" prefix */
      $$ = parser->make_number_term(parser, s, atoi($4), 10);
      free($4);
      free($3);
  }
;


term_attribute_list :
  term_attribute
  {
      $$ = smtlib2_vector_new();
      smtlib2_vector_push($$, (intptr_t)$1);
  }
| term_attribute_list term_attribute
  {
      $$ = $1;
      smtlib2_vector_push($$, (intptr_t)$2);
  }
;


term_attribute :
  KEYWORD attribute_value
  {
      $$ = (char **)malloc(sizeof(char *) * 2);
      $$[0] = $1;
      $$[1] = $2;
  }
;


attribute_value :
  info_argument
  {
      $$ = $1;
  }
| TK_LET
  {
      $$ = smtlib2_strdup("let");
  }
| '(' ')'
  {
      $$ = smtlib2_strdup("()");
  }
| '(' attribute_value_list ')'
  {
      size_t howmany = 0;
      size_t i;
      char *s;
      
      for (i = 0; i < smtlib2_vector_size($2); ++i) {
          howmany += strlen((char *)smtlib2_vector_at($2, i));
      }
      howmany += 2 /* '(' and ')' */ +
          (smtlib2_vector_size($2)-1) /* ' 's */ + 1; /* '\0' */
      $$ = (char *)malloc(sizeof(char) * howmany);

      /* concatenate everything together */
      s = $$;
      s[0] = '(';
      ++s;
      for (i = 0; i < smtlib2_vector_size($2); ++i) {
          char *s2 = (char *)smtlib2_vector_at($2, i);
          char *s3 = s2;
          while (*s2) {
              *s++ = *s2++;
          }
          *s++ = ' ';
          free(s3);
      }
      *(s-1) = ')';
      *s = '\0';
      
      smtlib2_vector_delete($2);
  }
;


attribute_value_list :
  attribute_value
  {
      $$ = smtlib2_vector_new();
      smtlib2_vector_push($$, (intptr_t)$1);
  }
| attribute_value_list attribute_value
  {
      $$ = $1;
      smtlib2_vector_push($$, (intptr_t)$2);
  }
;


num_list :
  NUMERAL
  {
      $$ = smtlib2_vector_new();
      int n = atoi($1);
      smtlib2_vector_push($$, n);
      free($1);
  }
| num_list NUMERAL
  {
      int n = atoi($2);
      smtlib2_vector_push($1, n);
      $$ = $1;
      free($2);
  }
;


int_list :
  NUMERAL
  {
      int n;
      $$ = smtlib2_vector_new();
      n = atoi($1);
      smtlib2_vector_push($$, n);
      free($1);
  }
| int_list NUMERAL
  {
      int n = atoi($2);
      smtlib2_vector_push($1, n);
      $$ = $1;
      free($2);
  }
;


term_list :
  a_term
  {
      $$ = smtlib2_vector_new();
      smtlib2_vector_push($$, (intptr_t)$1);
  }
| term_list a_term
  {
      smtlib2_vector_push($1, (intptr_t)$2);
      $$ = $1;
  }
;


quant_var_list :
  '(' SYMBOL a_sort ')'
  {
      intptr_t t;
      parser->push_quantifier_scope(parser);
      $$ = smtlib2_vector_new();
      parser->declare_variable(parser, $2, $3);
      t = (intptr_t)parser->make_term(parser, $2, $3, NULL, NULL);
      smtlib2_vector_push($$, t);
      free($2);
  }
| quant_var_list '(' SYMBOL a_sort ')'
  {
      intptr_t t;
      parser->declare_variable(parser, $3, $4);
      t = (intptr_t)parser->make_term(parser, $3, $4, NULL, NULL);
      smtlib2_vector_push($1, t);
      free($3);
      $$ = $1;
  }
;


begin_let_scope : TK_LET
  {
      parser->push_let_scope(parser);
  }
;


let_bindings :
  let_binding {}
| let_binding let_bindings {}
;


let_binding : '(' SYMBOL a_term ')'
  {
      parser->define_let_binding(parser, $2, $3);
      free($2);
  }
;


logic_name : 
  SYMBOL
  { $$ = $1; }
| SYMBOL '[' NUMERAL ']'
  {
      $$ = (char *)(malloc(strlen($1) + strlen($3) + 2 + 1));
      sprintf($$, "%s[%s]", $1, $3);
      free($1);
      free($3);
  }
;


sort_list :
  a_sort
  {
      $$ = smtlib2_vector_new();
      smtlib2_vector_push($$, (intptr_t)$1);
  }
| sort_list a_sort
  {
      $$ = $1;
      smtlib2_vector_push($$, (intptr_t)$2);
  }
;


a_sort : 
  SYMBOL
  {
      $$ = parser->make_sort(parser, $1, NULL);
      free($1);
  }
| '(' TK_UNDERSCORE SYMBOL int_list ')'
  {
      $$ = parser->make_sort(parser, $3, $4);
      smtlib2_vector_delete($4);
      free($3);
  }
| '(' SYMBOL sort_list ')'
  {
      $$ = parser->make_parametric_sort(parser, $2, $3);
      smtlib2_vector_delete($3);
      free($2);
  }
;


sort_param_list : 
  a_sort_param
  {
      parser->push_sort_param_scope(parser);
      $$ = smtlib2_vector_new();
      smtlib2_vector_push($$, (intptr_t)$1);
  }
| sort_param_list a_sort_param
  {
      $$ = $1;
      smtlib2_vector_push($$, (intptr_t)$2);
  }
;


a_sort_param : SYMBOL
  {
      parser->declare_sort(parser, $1, 0);
      $$ = parser->make_sort(parser, $1, NULL);
      free($1);
  }
;


verbatim_term_list :
  verbatim_term
  {
      $$ = smtlib2_vector_new();
      smtlib2_vector_push($$, (intptr_t)$1);
  }
| verbatim_term_list verbatim_term
  {
      $$ = $1;
      smtlib2_vector_push($$, (intptr_t)$2);
  }
;


verbatim_term : 
  attribute_value
  {
      $$ = $1;
  }
| KEYWORD
  {
      $$ = $1;
  }
;


%%


smtlib2_indexed_identifier *smtlib2_indexed_identifier_new(
    const char *n, smtlib2_vector *i, smtlib2_sort t)
{
    smtlib2_indexed_identifier *ret = (smtlib2_indexed_identifier *)malloc(
        sizeof(smtlib2_indexed_identifier));
    ret->name = smtlib2_strdup(n);
    ret->idx = i;
    ret->tp = t;

    return ret;
}


void smtlib2_indexed_identifier_delete(smtlib2_indexed_identifier *i)
{
    free(i->name);
    free(i);
}


smtlib2_term smtlib2_make_term_from_identifier(
    smtlib2_parser_interface *parser,
    smtlib2_indexed_identifier *ident, smtlib2_vector *args)
{
    return parser->make_term(parser, ident->name, ident->tp, ident->idx, args);
}


void smtlib2_parser_error(YYLTYPE *yylloc, yyscan_t scanner,
                          smtlib2_parser_interface *parser,
                          const char *s)
{
    parser->handle_error(parser, s);
}
