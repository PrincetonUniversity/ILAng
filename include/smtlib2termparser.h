/* -*- C -*-
 *
 * Parser for Terms in the SMT-LIB v2 format
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

#ifndef SMTLIB2TERMPARSER_H_INCLUDED
#define SMTLIB2TERMPARSER_H_INCLUDED

#include "smtlib2types.h"
#include "smtlib2utils.h"


typedef struct smtlib2_term_parser smtlib2_term_parser;

typedef smtlib2_term (*smtlib2_term_parser_symbolhandler)(smtlib2_context ctx,
                                                          const char *symbol,
                                                          smtlib2_sort sort,
                                                          smtlib2_vector *idx,
                                                          smtlib2_vector *args);

typedef smtlib2_term (*smtlib2_term_parser_numberhandler)(smtlib2_context ctx,
                                                          const char *rep,
                                                          unsigned int width,
                                                          unsigned int base);
typedef smtlib2_term (*smtlib2_term_parser_functionhandler)(
                                                          smtlib2_context ctx,
                                                          const char *symbol,
                                                          smtlib2_sort sort,
                                                          smtlib2_vector *index,
                                                          smtlib2_vector *args);

struct smtlib2_term_parser {
    smtlib2_context ctx_;
    smtlib2_hashtable *symbol_handlers_;
    smtlib2_term_parser_functionhandler function_term_handler_;
    smtlib2_term_parser_numberhandler number_term_handler_;
    smtlib2_hashtable *let_bindings_;
    smtlib2_vector *let_levels_;
    smtlib2_hashtable *bindings_;
    smtlib2_hashtable *term_params_;
    char *errmsg_;
};


smtlib2_term_parser *smtlib2_term_parser_new(smtlib2_context ctx);
void smtlib2_term_parser_delete(smtlib2_term_parser *tp);

smtlib2_term smtlib2_term_parser_make_term(smtlib2_term_parser *tp,
                                           const char *symbol,
                                           smtlib2_sort sort,
                                           smtlib2_vector *index,
                                           smtlib2_vector *args);
smtlib2_term smtlib2_term_parser_make_number_term(smtlib2_term_parser *tp,
                                                  const char *rep,
                                                  unsigned int width,
                                                  unsigned int base);

void smtlib2_term_parser_push_let_scope(smtlib2_term_parser *tp);
void smtlib2_term_parser_pop_let_scope(smtlib2_term_parser *tp);
void smtlib2_term_parser_define_let_binding(smtlib2_term_parser *tp,
                                            const char *symbol,
                                            smtlib2_term term);
void smtlib2_term_parser_define_binding(smtlib2_term_parser *tp,
                                        const char *symbol,
                                        smtlib2_vector *params,
                                        smtlib2_term term);
void smtlib2_term_parser_undefine_binding(smtlib2_term_parser *tp,
                                          const char *symbol);

void smtlib2_term_parser_set_handler(smtlib2_term_parser *tp,
                                     const char *symbol,
                                     smtlib2_term_parser_symbolhandler handler);
void smtlib2_term_parser_set_function_handler(
    smtlib2_term_parser *tp,
    smtlib2_term_parser_functionhandler handler);
void smtlib2_term_parser_set_number_handler(
    smtlib2_term_parser *tp,
    smtlib2_term_parser_numberhandler handler);

bool smtlib2_term_parser_error(smtlib2_term_parser *tp);
const char *smtlib2_term_parser_get_error_msg(smtlib2_term_parser *tp);

#endif /* SMTLIBTERMPARSER_H_INCLUDED */
