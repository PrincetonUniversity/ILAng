/* -*- C -*-
 *
 * An abstract parser for the SMT-LIB v2 language
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

#include "smtlib2abstractparser.h"
#include "smtlib2abstractparser_private.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>


void smtlib2_abstract_parser_init(smtlib2_abstract_parser *p,
                                  smtlib2_context ctx)
{
    smtlib2_parser_interface *pi;
    
    p->termparser_ = smtlib2_term_parser_new(ctx);
    p->outstream_ = stdout;
    p->errstream_ = stderr;
    p->response_ = SMTLIB2_RESPONSE_SUCCESS;
    p->print_success_ = true;
    p->errmsg_ = NULL;
    p->response_data_ = smtlib2_vector_new();
    p->status_ = SMTLIB2_STATUS_UNKNOWN;
    p->set_logic_ok_ = true;
    p->exiting_ = false;
    p->info_ = smtlib2_hashtable_new(smtlib2_hashfun_str, smtlib2_eqfun_str);
    p->internal_parsed_terms_ = smtlib2_vector_new();
    p->internal_parsed_terms_enabled_ = false;
    p->scanner_ = NULL;

    /* set the default interface */
    pi = SMTLIB2_PARSER_INTERFACE(p);
    pi->set_logic = smtlib2_abstract_parser_set_logic;
    pi->declare_sort = smtlib2_abstract_parser_declare_sort;
    pi->define_sort = smtlib2_abstract_parser_define_sort;
    pi->push_sort_param_scope = smtlib2_abstract_parser_push_sort_param_scope;
    pi->pop_sort_param_scope = smtlib2_abstract_parser_pop_sort_param_scope;
    pi->declare_function = smtlib2_abstract_parser_declare_function;
    pi->declare_variable = smtlib2_abstract_parser_declare_variable;
    pi->define_function = smtlib2_abstract_parser_define_function;
    pi->push = smtlib2_abstract_parser_push;
    pi->pop = smtlib2_abstract_parser_pop;
    pi->assert_formula = smtlib2_abstract_parser_assert_formula;
    pi->check_sat = smtlib2_abstract_parser_check_sat;
    pi->get_unsat_core = smtlib2_abstract_parser_get_unsat_core;
    pi->get_proof = smtlib2_abstract_parser_get_proof;
    pi->set_str_option = smtlib2_abstract_parser_set_str_option;
    pi->set_int_option = smtlib2_abstract_parser_set_int_option;
    pi->set_rat_option = smtlib2_abstract_parser_set_rat_option;
    pi->get_info = smtlib2_abstract_parser_get_info;
    pi->set_info = smtlib2_abstract_parser_set_info;
    pi->get_assignment = smtlib2_abstract_parser_get_assignment;
    pi->get_value = smtlib2_abstract_parser_get_value;
    pi->exit = smtlib2_abstract_parser_exit;
    pi->handle_error = smtlib2_abstract_parser_handle_error;
    pi->push_let_scope = smtlib2_abstract_parser_push_let_scope;
    pi->pop_let_scope = smtlib2_abstract_parser_pop_let_scope;
    pi->push_quantifier_scope = smtlib2_abstract_parser_push_quantifier_scope;
    pi->pop_quantifier_scope = smtlib2_abstract_parser_pop_quantifier_scope;
    pi->make_term = smtlib2_abstract_parser_make_term;
    pi->make_number_term = smtlib2_abstract_parser_make_number_term;
    pi->annotate_term = smtlib2_abstract_parser_annotate_term;
    pi->define_let_binding = smtlib2_abstract_parser_define_let_binding;
    pi->make_sort = smtlib2_abstract_parser_make_sort;
    pi->make_parametric_sort = smtlib2_abstract_parser_make_parametric_sort;
    pi->make_function_sort = smtlib2_abstract_parser_make_function_sort;
    pi->set_internal_parsed_terms =
        smtlib2_abstract_parser_set_internal_parsed_terms;
}


void smtlib2_abstract_parser_deinit(smtlib2_abstract_parser *p)
{
    smtlib2_vector_delete(p->internal_parsed_terms_);
    smtlib2_hashtable_delete(p->info_,
                             (smtlib2_freefun)free, (smtlib2_freefun)free);
    smtlib2_vector_delete(p->response_data_);
    smtlib2_term_parser_delete(p->termparser_);
}


void smtlib2_abstract_parser_parse(smtlib2_abstract_parser *p, FILE *src)
{
    smtlib2_fstream *stream;
    smtlib2_scanner *scanner;

    stream = smtlib2_fstream_new(src);
    scanner = smtlib2_scanner_new((smtlib2_stream *)stream);

    smtlib2_abstract_parser_reset_response(p);

    while (!smtlib2_stream_eof((smtlib2_stream *)stream)) {
        smtlib2_parse(scanner, SMTLIB2_PARSER_INTERFACE(p));
        if (p->exiting_) {
            break;
        }
        if (!smtlib2_stream_eof((smtlib2_stream *)stream)) {
            smtlib2_abstract_parser_print_response(p);
            smtlib2_abstract_parser_reset_response(p);
        }
    }

    smtlib2_scanner_delete(scanner);
    smtlib2_fstream_delete(stream);
}


void smtlib2_abstract_parser_set_logic(smtlib2_parser_interface *p,
                                       const char *logic)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    if (pp->set_logic_ok_) {
        pp->set_logic_ok_ = false;
    } else {
        pp->response_ = SMTLIB2_RESPONSE_ERROR;
        pp->errmsg_ = smtlib2_strdup("set-logic can't be called at this point");
    }
}


void smtlib2_abstract_parser_declare_sort(smtlib2_parser_interface *p,
                                          const char *sortname,
                                          int arity)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    pp->response_ = SMTLIB2_RESPONSE_ERROR;
    pp->errmsg_ = smtlib2_strdup("unimplemented");
}


void smtlib2_abstract_parser_define_sort(smtlib2_parser_interface *p,
                                         const char *sortname,
                                         smtlib2_vector *params,
                                         smtlib2_sort sort)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    pp->response_ = SMTLIB2_RESPONSE_ERROR;
    pp->errmsg_ = smtlib2_strdup("unimplemented");
}


void smtlib2_abstract_parser_push_sort_param_scope(smtlib2_parser_interface *p)
{
    /* nothing to do */
}


void smtlib2_abstract_parser_pop_sort_param_scope(smtlib2_parser_interface *p)
{
    /* nothing to do */
}


void smtlib2_abstract_parser_declare_function(smtlib2_parser_interface *p,
                                              const char *name,
                                              smtlib2_sort sort)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    pp->response_ = SMTLIB2_RESPONSE_ERROR;
    pp->errmsg_ = smtlib2_strdup("unimplemented");
}


void smtlib2_abstract_parser_declare_variable(smtlib2_parser_interface *p,
                                              const char *name,
                                              smtlib2_sort sort)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    pp->response_ = SMTLIB2_RESPONSE_ERROR;
    pp->errmsg_ = smtlib2_strdup("unimplemented");
}


void smtlib2_abstract_parser_define_function(smtlib2_parser_interface *p,
                                             const char *name,
                                             smtlib2_vector *params,
                                             smtlib2_sort sort,
                                             smtlib2_term term)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    if (pp->response_ != SMTLIB2_RESPONSE_ERROR) {
        smtlib2_term_parser_define_binding(pp->termparser_, name, params, term);
        if (smtlib2_term_parser_error(pp->termparser_)) {
            pp->response_ = SMTLIB2_RESPONSE_ERROR;
            pp->errmsg_ = smtlib2_strdup(
                smtlib2_term_parser_get_error_msg(pp->termparser_));
        } else {
            pp->response_ = SMTLIB2_RESPONSE_SUCCESS;
        }
    }
}


void smtlib2_abstract_parser_push(smtlib2_parser_interface *p, int n)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    pp->response_ = SMTLIB2_RESPONSE_ERROR;
    pp->errmsg_ = smtlib2_strdup("unimplemented");
}


void smtlib2_abstract_parser_pop(smtlib2_parser_interface *p, int n)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    pp->response_ = SMTLIB2_RESPONSE_ERROR;
    pp->errmsg_ = smtlib2_strdup("unimplemented");
}


void smtlib2_abstract_parser_assert_formula(smtlib2_parser_interface *p,
                                            smtlib2_term term)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    pp->response_ = SMTLIB2_RESPONSE_ERROR;
    pp->errmsg_ = smtlib2_strdup("unimplemented");
}


void smtlib2_abstract_parser_check_sat(smtlib2_parser_interface *p)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    pp->response_ = SMTLIB2_RESPONSE_ERROR;
    pp->errmsg_ = smtlib2_strdup("unimplemented");
}


void smtlib2_abstract_parser_get_unsat_core(smtlib2_parser_interface *p)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    pp->response_ = SMTLIB2_RESPONSE_ERROR;
    pp->errmsg_ = smtlib2_strdup("unimplemented");
}


void smtlib2_abstract_parser_get_proof(smtlib2_parser_interface *p)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    pp->response_ = SMTLIB2_RESPONSE_ERROR;
    pp->errmsg_ = smtlib2_strdup("unimplemented");
}


void smtlib2_abstract_parser_set_str_option(smtlib2_parser_interface *p,
                                            const char *keyword,
                                            const char *value)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    if (pp->response_ == SMTLIB2_RESPONSE_SUCCESS) {
        FILE **which = NULL;
        if (strcmp(keyword, ":regular-output-channel") == 0) {
            which = &(pp->outstream_);
        } else if (strcmp(keyword, ":diagnostic-output-channel") == 0) {
            which = &(pp->errstream_);
        } else {
            pp->response_ = SMTLIB2_RESPONSE_UNSUPPORTED;
        }
        if (which != NULL) {
            if (*which != stdout && *which != stderr) {
                fclose(*which);
            }
            if (strcmp(value, "stdout") == 0) {
                *which = stdout;
            } else if (strcmp(value, "stderr") == 0) {
                *which = stderr;
            } else {
                *which = fopen(value, "w");
                if (!*which) {
                    pp->response_ = SMTLIB2_RESPONSE_ERROR;
                    pp->errmsg_ =
                        smtlib2_sprintf("Impossible to open `%s' as `%s'",
                                        value, keyword);
                    if (strcmp(keyword, ":regular-output-channel") == 0) {
                        *which = stdout;
                    } else {
                        *which = stderr;
                    }
                }
            }
        }
    }
}


void smtlib2_abstract_parser_set_int_option(smtlib2_parser_interface *p,
                                            const char *keyword,
                                            int value)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;

    if (pp->response_ == SMTLIB2_RESPONSE_SUCCESS) {
        if (strcmp(keyword, ":print-success") == 0) {
            pp->print_success_ = value;
        } else {
            pp->response_ = SMTLIB2_RESPONSE_UNSUPPORTED;
        }
    }
}


void smtlib2_abstract_parser_set_rat_option(smtlib2_parser_interface *p,
                                            const char *keyword,
                                            double value)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    pp->response_ = SMTLIB2_RESPONSE_UNSUPPORTED;
}


void smtlib2_abstract_parser_get_info(smtlib2_parser_interface *p,
                                      const char *keyword)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;

    if (pp->response_ != SMTLIB2_RESPONSE_ERROR) {
        intptr_t v;
        if (smtlib2_hashtable_find(pp->info_, (intptr_t)keyword, &v)) {
            smtlib2_vector_push(pp->response_data_, (intptr_t)keyword);
            smtlib2_vector_push(pp->response_data_, v);
            pp->response_ = SMTLIB2_RESPONSE_INFO;
        } else {
            pp->response_ = SMTLIB2_RESPONSE_UNSUPPORTED;
        }
    }
}


void smtlib2_abstract_parser_set_info(smtlib2_parser_interface *p,
                                      const char *keyword,
                                      const char *value)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;

    if (pp->response_ != SMTLIB2_RESPONSE_ERROR) {
        smtlib2_hashtable_set(pp->info_, (intptr_t)smtlib2_strdup(keyword),
                              (intptr_t)smtlib2_strdup(value));
        pp->response_ = SMTLIB2_RESPONSE_SUCCESS;
    }
}


void smtlib2_abstract_parser_get_assignment(smtlib2_parser_interface *p)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    pp->response_ = SMTLIB2_RESPONSE_ERROR;
    pp->errmsg_ = smtlib2_strdup("unimplemented");
}


void smtlib2_abstract_parser_get_value(smtlib2_parser_interface *p,
                                       smtlib2_vector *terms)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    pp->response_ = SMTLIB2_RESPONSE_ERROR;
    pp->errmsg_ = smtlib2_strdup("unimplemented");
}


void smtlib2_abstract_parser_exit(smtlib2_parser_interface *p)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    pp->exiting_ = true;
}


void smtlib2_abstract_parser_set_internal_parsed_terms(
    smtlib2_parser_interface *p,
    smtlib2_vector *terms)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    if (pp->response_ != SMTLIB2_RESPONSE_ERROR) {
        if (pp->internal_parsed_terms_enabled_) {
            smtlib2_vector_swap(pp->internal_parsed_terms_, terms);
        } else {
            pp->response_ = SMTLIB2_RESPONSE_ERROR;
            pp->errmsg_ =
                smtlib2_strdup("unknown command `.internal-parse-terms'");
        }
    }
}



void smtlib2_abstract_parser_handle_error(smtlib2_parser_interface *p,
                                          const char *msg)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    pp->response_ = SMTLIB2_RESPONSE_ERROR;
    pp->errmsg_ = smtlib2_strdup(msg);
}


void smtlib2_abstract_parser_push_let_scope(smtlib2_parser_interface *p)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    if (pp->response_ != SMTLIB2_RESPONSE_ERROR) {
        smtlib2_term_parser_push_let_scope(pp->termparser_);
        if (smtlib2_term_parser_error(pp->termparser_)) {
            pp->response_ = SMTLIB2_RESPONSE_ERROR;
            pp->errmsg_ = smtlib2_strdup(
                smtlib2_term_parser_get_error_msg(pp->termparser_));
        }
    }
}


void smtlib2_abstract_parser_pop_let_scope(smtlib2_parser_interface *p)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    if (pp->response_ != SMTLIB2_RESPONSE_ERROR) {
        smtlib2_term_parser_pop_let_scope(pp->termparser_);
        if (smtlib2_term_parser_error(pp->termparser_)) {
            pp->response_ = SMTLIB2_RESPONSE_ERROR;
            pp->errmsg_ = smtlib2_strdup(
                smtlib2_term_parser_get_error_msg(pp->termparser_));
        }
    }
}


void smtlib2_abstract_parser_push_quantifier_scope(smtlib2_parser_interface *p)
{
    /* nothing to do */
}


void smtlib2_abstract_parser_pop_quantifier_scope(smtlib2_parser_interface *p)
{
    /* nothing to do */
}


smtlib2_term smtlib2_abstract_parser_make_term(smtlib2_parser_interface *p,
                                               const char *symbol,
                                               smtlib2_sort sort,
                                               smtlib2_vector *index,
                                               smtlib2_vector *args)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    smtlib2_term ret = NULL;

    if (pp->response_ != SMTLIB2_RESPONSE_ERROR) {
        ret = smtlib2_term_parser_make_term(pp->termparser_, symbol, sort,
                                            index, args);
        if (smtlib2_term_parser_error(pp->termparser_)) {
            pp->response_ = SMTLIB2_RESPONSE_ERROR;
            pp->errmsg_ = smtlib2_strdup(
                smtlib2_term_parser_get_error_msg(pp->termparser_));
        }
    }
    return ret;
}


smtlib2_term smtlib2_abstract_parser_make_number_term(
    smtlib2_parser_interface *p,
    const char *numval,
    int width,
    int base)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    smtlib2_term ret = NULL;

    if (pp->response_ != SMTLIB2_RESPONSE_ERROR) {
        ret = smtlib2_term_parser_make_number_term(pp->termparser_,
                                                   numval, width, base);
        if (smtlib2_term_parser_error(pp->termparser_)) {
            pp->response_ = SMTLIB2_RESPONSE_ERROR;
            pp->errmsg_ = smtlib2_strdup(
                smtlib2_term_parser_get_error_msg(pp->termparser_));
        }
    }
    return ret;
}


void smtlib2_abstract_parser_annotate_term(smtlib2_parser_interface *p,
                                           smtlib2_term term,
                                           smtlib2_vector *annotations)
{
    /* do nothing for now */
}



void smtlib2_abstract_parser_define_let_binding(smtlib2_parser_interface *p,
                                                const char *symbol,
                                                smtlib2_term term)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;

    if (pp->response_ != SMTLIB2_RESPONSE_ERROR) {
        smtlib2_term_parser_define_let_binding(pp->termparser_, symbol, term);
        if (smtlib2_term_parser_error(pp->termparser_)) {
            pp->response_ = SMTLIB2_RESPONSE_ERROR;
            pp->errmsg_ = smtlib2_strdup(
                smtlib2_term_parser_get_error_msg(pp->termparser_));
        }
    }
}


smtlib2_sort smtlib2_abstract_parser_make_sort(smtlib2_parser_interface *p,
                                               const char *sortname,
                                               smtlib2_vector *index)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    pp->response_ = SMTLIB2_RESPONSE_ERROR;
    pp->errmsg_ = smtlib2_strdup("unimplemented");
    return NULL;
}


smtlib2_sort smtlib2_abstract_parser_make_parametric_sort(
    smtlib2_parser_interface *p,
    const char *name,
    smtlib2_vector *tps)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    pp->response_ = SMTLIB2_RESPONSE_ERROR;
    pp->errmsg_ = smtlib2_strdup("unimplemented");
    return NULL;
}


smtlib2_sort smtlib2_abstract_parser_make_function_sort(
    smtlib2_parser_interface *p,
    smtlib2_vector *tps)
{
    smtlib2_abstract_parser *pp = (smtlib2_abstract_parser *)p;
    pp->response_ = SMTLIB2_RESPONSE_ERROR;
    pp->errmsg_ = smtlib2_strdup("unimplemented");
    return NULL;
}


void smtlib2_abstract_parser_print_response(smtlib2_abstract_parser *p)
{
    switch (p->response_) {
    case SMTLIB2_RESPONSE_SUCCESS:
        if (p->print_success_) {
            fprintf(p->outstream_, "success\n");
        }
        break;
    case SMTLIB2_RESPONSE_ERROR:
        fprintf(p->errstream_, "(error \"%s\")\n", p->errmsg_);
        break;
    case SMTLIB2_RESPONSE_UNSUPPORTED:
        fprintf(p->outstream_, "unsupported\n");
        break;
    case SMTLIB2_RESPONSE_STATUS:
        switch (p->status_) {
        case SMTLIB2_STATUS_UNSAT: fprintf(p->outstream_, "unsat\n"); break;
        case SMTLIB2_STATUS_SAT: fprintf(p->outstream_, "sat\n"); break;
        default: fprintf(p->outstream_, "unknown\n");
        }
        break;
    case SMTLIB2_RESPONSE_INFO:
    case SMTLIB2_RESPONSE_MODEL: {
        bool first = true;
        size_t i;
        bool parens = (p->response_ == SMTLIB2_RESPONSE_MODEL);
        fprintf(p->outstream_, "( ");
        for (i = 0; i < smtlib2_vector_size(p->response_data_); i += 2) {
            if (!first) {
                fprintf(p->outstream_, "\n  ");
            } else {
                first = false;
            }
            if (parens) fputc('(', p->outstream_);
            fprintf(p->outstream_, "%s %s",
                    (const char *)smtlib2_vector_at(p->response_data_, i),
                    (const char *)smtlib2_vector_at(p->response_data_, i+1));
            if (parens) fputc(')', p->outstream_);
        }
        fprintf(p->outstream_, " )\n");
    }
        break;
    case SMTLIB2_RESPONSE_UNSATCORE: {
        bool first = true;
        size_t i;
        fprintf(p->outstream_, "( ");
        for (i = 0; i < smtlib2_vector_size(p->response_data_); ++i) {
            if (!first) {
                fprintf(p->outstream_, "\n  ");
            } else {
                first = false;
            }
            fprintf(p->outstream_, "%s",
                    (const char *)smtlib2_vector_at(p->response_data_, i));
        }
        fprintf(p->outstream_, " )\n");
    }
        break;
    }
    fflush(p->outstream_);
    fflush(p->errstream_);
}


void smtlib2_abstract_parser_reset_response(smtlib2_abstract_parser *p)
{
    p->response_ = SMTLIB2_RESPONSE_SUCCESS;
    if (p->errmsg_) {
        free(p->errmsg_);
        p->errmsg_ = NULL;
    }
    smtlib2_vector_clear(p->response_data_);
}
