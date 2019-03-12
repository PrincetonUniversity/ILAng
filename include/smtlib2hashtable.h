/* -*- C -*-
 *
 * Hash tables for the SMT-LIB v2 parser
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
#ifndef SMTLIB2HASHTABLE_H_INCLUDED
#define SMTLIB2HASHTABLE_H_INCLUDED

#include "smtlib2vector.h"
#include <stdbool.h>

typedef uint32_t (*smtlib2_hashfun)(intptr_t elem);
typedef bool (*smtlib2_eqfun)(intptr_t e1, intptr_t e2);
typedef void (*smtlib2_freefun)(intptr_t p);

typedef struct smtlib2_hashtable {
    smtlib2_vector *table_;
    size_t size_;
    smtlib2_hashfun hf_;
    smtlib2_eqfun eqf_;
} smtlib2_hashtable;


smtlib2_hashtable *smtlib2_hashtable_new(smtlib2_hashfun hf, smtlib2_eqfun ef);
void smtlib2_hashtable_delete(smtlib2_hashtable *t,
                              smtlib2_freefun fk, smtlib2_freefun fv);
void smtlib2_hashtable_set(smtlib2_hashtable *t, intptr_t key, intptr_t val);
intptr_t smtlib2_hashtable_get(smtlib2_hashtable *t, intptr_t key);
void smtlib2_hashtable_erase_free(smtlib2_hashtable *t, intptr_t key,
                                  smtlib2_freefun fk, smtlib2_freefun fv);
bool smtlib2_hashtable_find_key_value(smtlib2_hashtable *t, intptr_t key,
                                      intptr_t *out_key, intptr_t *out_val);
void smtlib2_hashtable_clear(smtlib2_hashtable *t,
                             smtlib2_freefun fk, smtlib2_freefun fv);
smtlib2_vector *smtlib2_hashtable_keys(smtlib2_hashtable *t);

#define smtlib2_hashtable_size(t) ((t)->size_)
#define smtlib2_hashtable_find(t, k, ov) smtlib2_hashtable_find_key_value((t), (k), NULL, (ov))
#define smtlib2_hashtable_find_key(t, k, ok) smtlib2_hashtable_find_key_value((t), (k), (ok), NULL)
#define smtlib2_hashtable_erase(t, k) smtlib2_hashtable_erase_free((t), (k), NULL, NULL)

uint32_t smtlib2_hashfun_str(intptr_t s);
bool smtlib2_eqfun_str(intptr_t s1, intptr_t s2);

#endif /* SMTLIB2HASHTABLE_H_INCLUDED */
