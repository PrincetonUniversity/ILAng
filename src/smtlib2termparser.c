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

#include "smtlib2termparser.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>


static void free_term_params(intptr_t p);
static void free_let_bindings(intptr_t p);

static void smtlib2_term_parser_format_error(smtlib2_term_parser *tp,
                                             const char *fmt, ...);
static smtlib2_term smtlib2_term_parser_get_binding(smtlib2_term_parser *tp,
                                                    const char *symbol);
static smtlib2_vector *smtlib2_term_parser_get_params(smtlib2_term_parser *tp,
                                                      smtlib2_term term);


smtlib2_term_parser *smtlib2_term_parser_new(smtlib2_context ctx)
{
    smtlib2_term_parser *ret =
        (smtlib2_term_parser *)malloc(sizeof(smtlib2_term_parser));
    ret->ctx_ = ctx;
    ret->symbol_handlers_ = smtlib2_hashtable_new(smtlib2_hashfun_str,
                                                  smtlib2_eqfun_str);
    ret->function_term_handler_ = NULL;
    ret->number_term_handler_ = NULL;
    ret->let_bindings_ = smtlib2_hashtable_new(smtlib2_hashfun_str,
                                               smtlib2_eqfun_str);
    ret->let_levels_ = smtlib2_vector_new();
    ret->bindings_ = smtlib2_hashtable_new(smtlib2_hashfun_str,
                                           smtlib2_eqfun_str);
    ret->term_params_ = smtlib2_hashtable_new(NULL, NULL);
    ret->errmsg_ = NULL;

    return ret;
}


void smtlib2_term_parser_delete(smtlib2_term_parser *tp)
{
    if (tp->errmsg_) {
        free(tp->errmsg_);
    }
    smtlib2_hashtable_delete(tp->term_params_, NULL, free_term_params);
    smtlib2_hashtable_delete(tp->bindings_, (smtlib2_freefun)free, NULL);
    smtlib2_vector_delete(tp->let_levels_);
    smtlib2_hashtable_delete(tp->let_bindings_, (smtlib2_freefun)free,
                             free_let_bindings);
    smtlib2_hashtable_delete(tp->symbol_handlers_, (smtlib2_freefun)free, NULL);
    free(tp);
}


smtlib2_term smtlib2_term_parser_make_term(smtlib2_term_parser *tp,
                                           const char *symbol,
                                           smtlib2_sort sort,
                                           smtlib2_vector *index,
                                           smtlib2_vector *args)
{
    intptr_t val;
    smtlib2_term ret = NULL;
    
    if (!index) {
        smtlib2_term def = smtlib2_term_parser_get_binding(tp, symbol);
        if (def) {
            smtlib2_vector *params = smtlib2_term_parser_get_params(tp, def);
            if (params) {
                smtlib2_term_parser_format_error(
                    tp, "macros with parameters not supported yet");
                return NULL;
            } else {
                if (args) {
                    smtlib2_term_parser_format_error(
                        tp, "wrong number of arguments for symbol `%s'",
                        symbol);
                    return NULL;
                }
                ret = def;
            }
            if (!ret) {
                smtlib2_term_parser_format_error(
                    tp, "error in parsing symbol `%s'", symbol);
            }
            return ret;
        }
    }
    
    if (smtlib2_hashtable_find(tp->symbol_handlers_, (intptr_t)symbol, &val)) {
        smtlib2_term_parser_symbolhandler handler =
            (smtlib2_term_parser_symbolhandler)val;
        smtlib2_term ret = handler(tp->ctx_, symbol, sort, index, args);
        if (!ret) {
            smtlib2_term_parser_format_error(
                tp, "handler for symbol `%s' returned error", symbol);
        }
        return ret;
    } else {
        /* if we are here, this must be an uninterpreted function, otherwise
         * it is a parsing error */
        assert(tp->function_term_handler_);
        ret = tp->function_term_handler_(tp->ctx_, symbol, sort, index, args);
        if (!ret) {
            smtlib2_term_parser_format_error(tp, "error in parsing symbol `%s'",
                                             symbol);
        }
        return ret;
    }
}


smtlib2_term smtlib2_term_parser_make_number_term(smtlib2_term_parser *tp,
                                                  const char *rep,
                                                  unsigned int width,
                                                  unsigned int base)
{
    if (!tp->number_term_handler_) {
        smtlib2_term_parser_format_error(tp, "no handler for numbers");
        return NULL;
    } else {
        smtlib2_term ret = tp->number_term_handler_(tp->ctx_, rep, width, base);
        if (!ret) {
            smtlib2_term_parser_format_error(
                tp, "handler for numbers returned error");
        }
        return ret;
    }
}


void smtlib2_term_parser_push_let_scope(smtlib2_term_parser *tp)
{
    smtlib2_vector_push(tp->let_levels_, (intptr_t)NULL);
}


void smtlib2_term_parser_pop_let_scope(smtlib2_term_parser *tp)
{
    char *key;
    
    assert(smtlib2_vector_size(tp->let_levels_) > 0);

    key = (char *)smtlib2_vector_last(tp->let_levels_);
    while (key != NULL) {
        intptr_t v;
        bool ok;
        smtlib2_vector *vv;
        
        ok = smtlib2_hashtable_find(tp->let_bindings_, (intptr_t)key, &v);
        assert(ok);

        vv = (smtlib2_vector *)v;

        assert(smtlib2_vector_size(vv) > 0);

        smtlib2_vector_pop(vv);
        if (smtlib2_vector_size(vv) == 0) {
            smtlib2_hashtable_erase(tp->let_bindings_, (intptr_t)key);
            smtlib2_vector_delete(vv);
        }
        smtlib2_vector_pop(tp->let_levels_);
        free(key);
        key = (char *)smtlib2_vector_last(tp->let_levels_);
    }
    smtlib2_vector_pop(tp->let_levels_);
}


void smtlib2_term_parser_define_let_binding(smtlib2_term_parser *tp,
                                            const char *symbol,
                                            smtlib2_term term)
{
    if (smtlib2_vector_size(tp->let_levels_) == 0) {
        smtlib2_term_parser_format_error(tp, "parse error");
    } else {
        intptr_t v;
        if (smtlib2_hashtable_find(tp->bindings_, (intptr_t)symbol, &v)) {
            smtlib2_term_parser_format_error(tp, "symbol `%s' already defined",
                                             symbol);
        } else {
            int i;
            char *s;
            smtlib2_vector *vv;
            
            for (i = smtlib2_vector_size(tp->let_levels_)-1; i >= 0; --i) {
                const char *s2 =
                    (const char *)smtlib2_vector_at(tp->let_levels_, i);
                if (!s2) {
                    break;
                }
                if (strcmp(symbol, s2) == 0) {
                    smtlib2_term_parser_format_error(
                        tp, "symbol `%s' already defined", symbol);
                    return;
                }
            }

            s = smtlib2_strdup(symbol);
            smtlib2_vector_push(tp->let_levels_, (intptr_t)s);
            vv = (smtlib2_vector *)smtlib2_hashtable_get(
                tp->let_bindings_, (intptr_t)s);
            if (!vv) {
                vv = smtlib2_vector_new();
                smtlib2_hashtable_set(tp->let_bindings_, (intptr_t)s,
                                      (intptr_t)vv);
            }
            smtlib2_vector_push(vv, (intptr_t)term);
        }
    }
}


void smtlib2_term_parser_define_binding(smtlib2_term_parser *tp,
                                        const char *symbol,
                                        smtlib2_vector *params,
                                        smtlib2_term term)
{
    if (smtlib2_term_parser_get_binding(tp, symbol)) {
        smtlib2_term_parser_format_error(tp, "symbol `%s' already defined",
                                         symbol);
    } else {
        smtlib2_hashtable_set(tp->bindings_, (intptr_t)smtlib2_strdup(symbol),
                              (intptr_t)term);
        if (params != NULL) {
            size_t i;
            smtlib2_vector *p = smtlib2_vector_new();
            smtlib2_vector_reserve(p, smtlib2_vector_size(params));
            for (i = 0; i < smtlib2_vector_size(params); ++i) {
                smtlib2_vector_push(p, smtlib2_vector_at(params, i));
            }
            smtlib2_hashtable_set(tp->term_params_, (intptr_t)term,
                                  (intptr_t)p);
        }
    }
}


void smtlib2_term_parser_undefine_binding(smtlib2_term_parser *tp,
                                          const char *symbol)
{
    intptr_t k, v;
    if (!smtlib2_hashtable_find_key_value(tp->bindings_,
                                          (intptr_t)symbol, &k, &v)) {
        smtlib2_term_parser_format_error(tp, "symbol `%s' is not defined",
                                         symbol);
    } else {
        smtlib2_term t = (smtlib2_term)v;
        smtlib2_hashtable_erase(tp->bindings_, (intptr_t)symbol);
        free((char *)k);
        if (smtlib2_hashtable_find(tp->term_params_, (intptr_t)t, &v)) {
            smtlib2_vector *vv = (smtlib2_vector *)v;
            smtlib2_hashtable_erase(tp->term_params_, (intptr_t)t);
            smtlib2_vector_delete(vv);
        }
    }
}


void smtlib2_term_parser_set_handler(smtlib2_term_parser *tp,
                                     const char *symbol,
                                     smtlib2_term_parser_symbolhandler handler)
{
    const char *s = smtlib2_strdup(symbol);
    smtlib2_hashtable_set(tp->symbol_handlers_, (intptr_t)s, (intptr_t)handler);
}


void smtlib2_term_parser_set_function_handler(
    smtlib2_term_parser *tp,
    smtlib2_term_parser_functionhandler handler)
{
    tp->function_term_handler_ = handler;
}


void smtlib2_term_parser_set_number_handler(
    smtlib2_term_parser *tp,
    smtlib2_term_parser_numberhandler handler)
{
    tp->number_term_handler_ = handler;
}


bool smtlib2_term_parser_error(smtlib2_term_parser *tp)
{
    return tp->errmsg_ != NULL;
}


const char *smtlib2_term_parser_get_error_msg(smtlib2_term_parser *tp)
{
    return tp->errmsg_;
}


static void free_term_params(intptr_t p)
{
    smtlib2_vector_delete((smtlib2_vector *)p);
}


static void free_let_bindings(intptr_t p)
{
    size_t i;
    smtlib2_vector *v = (smtlib2_vector *)p;

    for (i = 0; i < smtlib2_vector_size(v); ++i) {
        free((char *)smtlib2_vector_at(v, i));
    }
    smtlib2_vector_delete(v);
}


static void smtlib2_term_parser_format_error(smtlib2_term_parser *tp,
                                             const char *fmt, ...)
{
    va_list args;
    if (tp->errmsg_) {
        free(tp->errmsg_);
    }
    va_start(args, fmt);
    tp->errmsg_ = smtlib2_vsprintf(fmt, args);
    va_end(args);
}


static smtlib2_term smtlib2_term_parser_get_binding(smtlib2_term_parser *tp,
                                                    const char *symbol)
{
    intptr_t v;
    if (smtlib2_hashtable_find(tp->let_bindings_, (intptr_t)symbol, &v)) {
        smtlib2_vector *vv = (smtlib2_vector *)v;
        assert(smtlib2_vector_size(vv) > 0);
        return (smtlib2_term)smtlib2_vector_last(vv);
    } else if (smtlib2_hashtable_find(tp->bindings_, (intptr_t)symbol, &v)) {
        return (smtlib2_term)v;
    } else {
        return NULL;
    }
}


static smtlib2_vector *smtlib2_term_parser_get_params(smtlib2_term_parser *tp,
                                                      smtlib2_term term)
{
    intptr_t v;
    if (smtlib2_hashtable_find(tp->term_params_, (intptr_t)term, &v)) {
        return (smtlib2_vector *)v;
    } else {
        return NULL;
    }
}
