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

#include "smtlib2hashtable.h"
#include <stdlib.h>
#include <string.h>


typedef struct smtlib2_hashtable_bucket {
    struct smtlib2_hashtable_bucket *next_;
    intptr_t key_;
    intptr_t val_;
} smtlib2_hashtable_bucket;


static const uint32_t primes[] = {
    31U, 73U, 151U, 313U, 643U, 1291U, 2593U, 5233U, 10501U, 21013U,
    42073U, 84181U, 168451U, 337219U, 674701U, 1349473U, 2699299U,
    5398891U, 10798093U, 21596719U, 43193641U, 86387383U, 172775299U,
    345550609U, 691101253U, 1382202559U, 2764405229U, 4294867387U
};
static const size_t num_primes = sizeof(primes)/sizeof(uint32_t);


static uint32_t get_next_prime(size_t n);
static void delete_buckets(smtlib2_hashtable_bucket *b,
                           smtlib2_freefun fk, smtlib2_freefun fv);
static float load_factor(smtlib2_hashtable *t);
static void rehash(smtlib2_hashtable *t, size_t min_buckets);
static smtlib2_hashtable_bucket *find_bucket(smtlib2_hashtable *t,
                                             intptr_t key, size_t idx);
static uint32_t identity_hashfun(intptr_t key);
static bool identity_eqfun(intptr_t k1, intptr_t k2);


smtlib2_hashtable *smtlib2_hashtable_new(smtlib2_hashfun hf, smtlib2_eqfun ef)
{
    smtlib2_hashtable *ret =
        (smtlib2_hashtable *)malloc(sizeof(smtlib2_hashtable));
    ret->table_ = smtlib2_vector_new();
    smtlib2_vector_resize(ret->table_, primes[0]);
    ret->size_ = 0;
    if (!hf) hf = identity_hashfun;
    if (!ef) ef = identity_eqfun;
    ret->hf_ = hf;
    ret->eqf_ = ef;

    return ret;
}


void smtlib2_hashtable_delete(smtlib2_hashtable *t,
                              smtlib2_freefun fk, smtlib2_freefun fv)
{
    size_t i;
    for (i = 0; i < smtlib2_vector_size(t->table_); ++i) {
        smtlib2_hashtable_bucket *b =
            (smtlib2_hashtable_bucket *)smtlib2_vector_at(t->table_, i);
        delete_buckets(b, fk, fv);
    }
    smtlib2_vector_delete(t->table_);
    free(t);
}


void smtlib2_hashtable_set(smtlib2_hashtable *t, intptr_t key, intptr_t val)
{
    size_t i;
    uint32_t h;
    smtlib2_hashtable_bucket *b;
    if (load_factor(t) > 0.7) {
        rehash(t, smtlib2_vector_size(t->table_)+1);
    }
    h = t->hf_(key);
    i = h % smtlib2_vector_size(t->table_);
    b = find_bucket(t, key, i);
    if (b) {
        b->val_ = val;
    } else {
        b = (smtlib2_hashtable_bucket *)malloc(
            sizeof(smtlib2_hashtable_bucket));
        b->next_ = (smtlib2_hashtable_bucket *)smtlib2_vector_at(t->table_, i);
        b->key_ = key;
        b->val_ = val;
        smtlib2_vector_at(t->table_, i) = (intptr_t)b;
        ++t->size_;
    }
}


intptr_t smtlib2_hashtable_get(smtlib2_hashtable *t, intptr_t key)
{
    intptr_t ret;
    if (smtlib2_hashtable_find(t, key, &ret)) {
        return ret;
    } else {
        return 0;
    }
}


bool smtlib2_hashtable_find_key_value(smtlib2_hashtable *t, intptr_t key,
                                      intptr_t *out_key, intptr_t *out_val)
{
    uint32_t h;
    size_t i;
    smtlib2_hashtable_bucket *b;

    if (!t->size_) {
        return 0;
    }
    
    h = t->hf_(key);
    i = h % smtlib2_vector_size(t->table_);

    b = find_bucket(t, key, i);

    if (b) {
        if (out_key) {
            *out_key = b->key_;
        }
        if (out_val) {
            *out_val = b->val_;
        }
        return true;
    } else {
        return false;
    }
}


void smtlib2_hashtable_erase_free(smtlib2_hashtable *t, intptr_t key,
                                  smtlib2_freefun fk, smtlib2_freefun fv)
{
    uint32_t h;
    size_t i;
    smtlib2_hashtable_bucket *b, *prev;

    if (!t->size_) {
        return;
    }
    
    h = t->hf_(key);
    i = h % smtlib2_vector_size(t->table_);

    b = (smtlib2_hashtable_bucket *)smtlib2_vector_at(t->table_, i);
    prev = NULL;
    while (b) {
        if (t->eqf_(b->key_, key)) {
            if (prev) {
                prev->next_ = b->next_;
            } else {
                smtlib2_vector_at(t->table_, i) = (intptr_t)b->next_;
            }
            --t->size_;
            if (fk) {
                fk(b->key_);
            }
            if (fv) {
                fv(b->val_);
            }
            free(b);
            return;
        } else {
            prev = b;
            b = b->next_;
        }
    }
}


void smtlib2_hashtable_clear(smtlib2_hashtable *t,
                             smtlib2_freefun fk, smtlib2_freefun fv)
{
    size_t i;
    for (i = 0; i < smtlib2_vector_size(t->table_); ++i) {
        smtlib2_hashtable_bucket *b =
            (smtlib2_hashtable_bucket *)smtlib2_vector_at(t->table_, i);
        delete_buckets(b, fk, fv);
    }
    smtlib2_vector_delete(t->table_);
    t->size_ = 0;
    t->table_ = smtlib2_vector_new();
    smtlib2_vector_resize(t->table_, primes[0]);
}


smtlib2_vector *smtlib2_hashtable_keys(smtlib2_hashtable *t)
{
    size_t i;
    smtlib2_vector *ret = smtlib2_vector_new();
    smtlib2_vector_reserve(ret, t->size_);

    for (i = 0; i < smtlib2_vector_size(t->table_); ++i) {
        smtlib2_hashtable_bucket *b =
            (smtlib2_hashtable_bucket *)smtlib2_vector_at(t->table_, i);
        while (b) {
            smtlib2_vector_push(ret, b->key_);
            b = b->next_;
        }
    }

    return ret;
}


uint32_t smtlib2_hashfun_str(intptr_t s)
{
    char *str = (char *)s;
    uint32_t ret = 0;
    for (; *str; ++str) {
        ret = 5 * ret + *str;
    }
    return ret;
}


bool smtlib2_eqfun_str(intptr_t s1, intptr_t s2)
{
    return strcmp((char *)s1, (char *)s2) == 0;
}


static uint32_t get_next_prime(size_t n)
{
    size_t i;
    for (i = 0; i < num_primes; ++i) {
        if (primes[i] >= n) {
            return primes[i];
        }
    }
    return primes[num_primes-1];
}


static void delete_buckets(smtlib2_hashtable_bucket *b,
                           smtlib2_freefun fk, smtlib2_freefun fv)
{
    while (b) {
        smtlib2_hashtable_bucket *tmp = b->next_;
        if (fk) {
            fk(b->key_);
        }
        if (fv) {
            fv(b->val_);
        }
        free(b);
        b = tmp;
    }
}


static float load_factor(smtlib2_hashtable *t)
{
    return ((float)t->size_) / ((float)smtlib2_vector_size(t->table_));
}


static smtlib2_hashtable_bucket *find_bucket(smtlib2_hashtable *t,
                                             intptr_t key, size_t idx)
{
    smtlib2_hashtable_bucket *b =
        (smtlib2_hashtable_bucket *)smtlib2_vector_at(t->table_, idx);
    while (b) {
        if (t->eqf_(key, b->key_)) {
            break;
        } else {
            b = b->next_;
        }
    }
    return b;
}


static void rehash(smtlib2_hashtable *t, size_t min_buckets)
{
    size_t cursz = smtlib2_vector_size(t->table_);
    if (cursz < min_buckets) {
        size_t i;
        uint32_t newsz = get_next_prime(min_buckets);
        smtlib2_vector *tmp = smtlib2_vector_new();
        smtlib2_vector_resize(tmp, newsz);

        for (i = 0; i < cursz; ++i) {
            smtlib2_hashtable_bucket *b =
                (smtlib2_hashtable_bucket *)smtlib2_vector_at(t->table_, i);
            while (b) {
                size_t j = t->hf_(b->key_) % newsz;
                smtlib2_hashtable_bucket *n = b;
                b = b->next_;
                n->next_ =
                    (smtlib2_hashtable_bucket *)smtlib2_vector_at(tmp, j);
                smtlib2_vector_at(tmp, j) = (intptr_t)n;
            }
        }

        smtlib2_vector_delete(t->table_);
        t->table_ = tmp;
    }
}


static uint32_t identity_hashfun(intptr_t key) { return (uint32_t)key; }
static bool identity_eqfun(intptr_t k1, intptr_t k2) { return k1 == k2; }
