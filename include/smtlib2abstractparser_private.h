/* -*- C -*-
 *
 * Private interface to the abstract parser for the SMT-LIB v2 language
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
#ifndef SMTLIB2ABSTRACTPARSER_PRIVATE_H_INCLUDED
#define SMTLIB2ABSTRACTPARSER_PRIVATE_H_INCLUDED

#include "smtlib2abstractparser.h"
#include "smtlib2scanner.h"

typedef enum {
    SMTLIB2_RESPONSE_SUCCESS,
    SMTLIB2_RESPONSE_ERROR,
    SMTLIB2_RESPONSE_UNSUPPORTED,
    SMTLIB2_RESPONSE_STATUS,
    SMTLIB2_RESPONSE_INFO,
    SMTLIB2_RESPONSE_UNSATCORE,
    SMTLIB2_RESPONSE_MODEL
} smtlib2_response;


typedef enum {
    SMTLIB2_STATUS_UNKNOWN,
    SMTLIB2_STATUS_UNSAT,
    SMTLIB2_STATUS_SAT
} smtlib2_status;


/**
 * An abstract SMT-LIB 2 parser, providing functionalities for parsing terms
 */
struct smtlib2_abstract_parser {
    smtlib2_parser_interface parent_;
    smtlib2_term_parser *termparser_;

    FILE *outstream_;
    FILE *errstream_;

    smtlib2_response response_;
    bool print_success_;

    char *errmsg_;
    smtlib2_vector *response_data_;

    smtlib2_status status_;

    bool set_logic_ok_;
    bool exiting_;

    smtlib2_hashtable *info_;

    smtlib2_vector *internal_parsed_terms_;
    bool internal_parsed_terms_enabled_;

    smtlib2_scanner *scanner_;
};


void smtlib2_abstract_parser_set_logic(smtlib2_parser_interface *p,
                                       const char *logic);
void smtlib2_abstract_parser_declare_sort(smtlib2_parser_interface *p,
                                          const char *sortname,
                                          int arity);
void smtlib2_abstract_parser_define_sort(smtlib2_parser_interface *p,
                                         const char *sortname,
                                         smtlib2_vector *params,
                                         smtlib2_sort sort);
void smtlib2_abstract_parser_push_sort_param_scope(smtlib2_parser_interface *p);
void smtlib2_abstract_parser_pop_sort_param_scope(smtlib2_parser_interface *p);
                                                   
void smtlib2_abstract_parser_declare_function(smtlib2_parser_interface *p,
                                              const char *name,
                                              smtlib2_sort sort);
void smtlib2_abstract_parser_declare_variable(smtlib2_parser_interface *p,
                                              const char *name,
                                              smtlib2_sort sort);
void smtlib2_abstract_parser_define_function(smtlib2_parser_interface *p,
                                             const char *name,
                                             smtlib2_vector *params,
                                             smtlib2_sort sort,
                                             smtlib2_term term);
void smtlib2_abstract_parser_push(smtlib2_parser_interface *p, int n);
void smtlib2_abstract_parser_pop(smtlib2_parser_interface *p, int n);
void smtlib2_abstract_parser_assert_formula(smtlib2_parser_interface *p,
                                            smtlib2_term term);
void smtlib2_abstract_parser_check_sat(smtlib2_parser_interface *p);
void smtlib2_abstract_parser_get_unsat_core(smtlib2_parser_interface *p);
void smtlib2_abstract_parser_get_proof(smtlib2_parser_interface *p);

void smtlib2_abstract_parser_set_str_option(smtlib2_parser_interface *p,
                                            const char *keyword,
                                            const char *value);
void smtlib2_abstract_parser_set_int_option(smtlib2_parser_interface *p,
                                            const char *keyword,
                                            int value);
void smtlib2_abstract_parser_set_rat_option(smtlib2_parser_interface *p,
                                            const char *keyword,
                                            double value);
void smtlib2_abstract_parser_get_info(smtlib2_parser_interface *p,
                                      const char *keyword);
void smtlib2_abstract_parser_set_info(smtlib2_parser_interface *p,
                                      const char *keyword,
                                      const char *value);
void smtlib2_abstract_parser_get_assignment(smtlib2_parser_interface *p);
void smtlib2_abstract_parser_get_value(smtlib2_parser_interface *p,
                                       smtlib2_vector *terms);
void smtlib2_abstract_parser_exit(smtlib2_parser_interface *p);

void smtlib2_abstract_parser_set_internal_parsed_terms(
                                                    smtlib2_parser_interface *p,
                                                    smtlib2_vector *terms);

void smtlib2_abstract_parser_handle_error(smtlib2_parser_interface *p,
                                          const char *msg);

void smtlib2_abstract_parser_push_let_scope(smtlib2_parser_interface *p);
void smtlib2_abstract_parser_pop_let_scope(smtlib2_parser_interface *p);

void smtlib2_abstract_parser_push_quantifier_scope(smtlib2_parser_interface *p);
void smtlib2_abstract_parser_pop_quantifier_scope(smtlib2_parser_interface *p);

smtlib2_term smtlib2_abstract_parser_make_term(smtlib2_parser_interface *p,
                                               const char *symbol,
                                               smtlib2_sort sort,
                                               smtlib2_vector *index,
                                               smtlib2_vector *args);
smtlib2_term smtlib2_abstract_parser_make_number_term(
                                                    smtlib2_parser_interface *p,
                                                    const char *numval,
                                                    int width,
                                                    int base);

void smtlib2_abstract_parser_annotate_term(smtlib2_parser_interface *p,
                                           smtlib2_term term,
                                           smtlib2_vector *annotations);

void smtlib2_abstract_parser_define_let_binding(smtlib2_parser_interface *p,
                                                const char *symbol,
                                                smtlib2_term term);
smtlib2_sort smtlib2_abstract_parser_make_sort(smtlib2_parser_interface *p,
                                               const char *sortname,
                                               smtlib2_vector *index);
smtlib2_sort smtlib2_abstract_parser_make_parametric_sort(
                                                    smtlib2_parser_interface *p,
                                                    const char *name,
                                                    smtlib2_vector *tps);
smtlib2_sort smtlib2_abstract_parser_make_function_sort(
                                                    smtlib2_parser_interface *p,
                                                    smtlib2_vector *tps);

void smtlib2_abstract_parser_print_response(smtlib2_abstract_parser *p);
void smtlib2_abstract_parser_reset_response(smtlib2_abstract_parser *p);

#endif /* SMTLIB2ABSTRACTPARSER_PRIVATE_H_INCLUDED */
