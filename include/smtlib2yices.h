/* -*- C -*-
 *
 * SMT-LIB v2 interface to Yices 1
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
#ifndef SMTLIB2YICES_H_INCLUDED
#define SMTLIB2YICES_H_INCLUDED

#include "smtlib2abstractparser.h"
#include "smtlib2abstractparser_private.h"
#include <gmp.h>
#include "yices_c.h"

typedef struct smtlib2_yices_parser {
    smtlib2_abstract_parser parent_;
    yices_context ctx_;
    smtlib2_hashtable *sorts_;
    smtlib2_hashtable *parametric_sorts_;
    int next_sort_idx_;
    smtlib2_hashtable *numbers_;
    smtlib2_vector *defines_;
    smtlib2_vector *defines_sorts_;
    smtlib2_hashtable *logics_arith_only_;
    smtlib2_hashtable *named_terms_;
    smtlib2_hashtable *term_names_;
    smtlib2_hashtable *assertion_ids_;
    smtlib2_vector *names_;
    bool produce_unsat_cores_;
    bool produce_assignments_;
    bool produce_models_;
} smtlib2_yices_parser;


smtlib2_yices_parser *smtlib2_yices_parser_new(void);
void smtlib2_yices_parser_delete(smtlib2_yices_parser *p);

#endif /* SMTLIB2YICES_H_INCLUDED */
