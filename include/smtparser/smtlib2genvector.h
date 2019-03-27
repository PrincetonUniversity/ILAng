/* -*- C -*-
 *
 * Generic resizable arrays for the SMT-LIB v2 parser
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
#ifndef SMTLIB2GENVECTOR_H_INCLUDED
#define SMTLIB2GENVECTOR_H_INCLUDED

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define SMTLIB2_DECLARE_VECTOR(name, type)                              \
typedef struct name {                                                   \
    type *data_;                                                        \
    size_t size_;                                                       \
    size_t capacity_;                                                   \
} name;                                                             \
name * name ## _new(void);                           \
void name ## _delete(name *v);                      \
void name ## _push(name *v, type elem);         \
void name ## _pop(name *v);                         \
void name ## _resize(name *v, size_t newsz);        \
void name ## _reserve(name *v, size_t cap);         \
void name ## _clear(name *v); \
void name ## _copy(name *src, name *dest);      \
void name ## _swap(name *v1, name *v2);

#define SMTLIB2_VECTOR_SIZE(v) ((v)->size_)
#define SMTLIB2_VECTOR_CAPACITY(v) ((v)->capacity_)
#define SMTLIB2_VECTOR_ARRAY(v) ((v)->data_)


#define SMTLIB2_DEFINE_VECTOR(name, type) \
name *name ## _new(void)                                \
{                                                                       \
    name *ret = (name *)malloc(sizeof(name)); \
    ret->data_ = NULL;                                                  \
    ret->size_ = 0;                                                     \
    ret->capacity_ = 0;                                                 \
                                                                        \
    return ret;                                                         \
}                                                                       \
                                                                        \
                                                                        \
void name ## _delete(name *v)                           \
{                                                                       \
    if (v->data_) {                                                     \
        free(v->data_);                                                 \
    }                                                                   \
    free(v);                                                            \
}                                                                       \
                                                                        \
                                                                        \
void name ## _push(name *v, type elem)              \
{                                                                       \
    if (v->size_ >= v->capacity_) {                                     \
        name ## _reserve(v, v->capacity_ ? v->capacity_ * 2 : 2); \
    }                                                                   \
    v->data_[v->size_++] = elem;                                        \
}                                                                       \
                                                                        \
                                                                        \
void name ## _pop(name *v)                              \
{                                                                       \
    assert(v->size_ > 0);                                               \
    --v->size_;                                                         \
}                                                                       \
                                                                        \
                                                                        \
void name ## _resize(name *v, size_t newsz)             \
{                                                                       \
    if (v->size_ >= newsz) {                                            \
        v->size_ = newsz;                                               \
    } else {                                                            \
        size_t i;                                                       \
        name ## _reserve(v, newsz);                               \
        for (i = v->size_; i < newsz; ++i) {                            \
            v->data_[i] = 0;                                            \
        }                                                               \
        v->size_ = newsz;                                               \
    }                                                                   \
}                                                                       \
                                                                        \
                                                                        \
void name ## _reserve(name *v, size_t cap)              \
{                                                                       \
    assert(cap > 0);                                                    \
                                                                        \
    if (v->capacity_ < cap) {                                           \
        v->data_ = (type *)realloc(v->data_, sizeof(type)*cap); \
        v->capacity_ = cap;                                             \
    }                                                                   \
}                                                                       \
                                                                        \
                                                                        \
void name ## _clear(name *v)                            \
{                                                                       \
    v->size_ = 0;                                                       \
    v->capacity_ = 0;                                                   \
    if (v->data_) {                                                     \
        free(v->data_);                                                 \
        v->data_ = NULL;                                                \
    }                                                                   \
}                                                                       \
                                                                        \
                                                                        \
void name ## _copy(name *src, name *dest)                               \
{                                                                       \
    name ## _resize(dest, src->size_);                                  \
    dest->size_ = src->size_;                                           \
    if (src->data_ != NULL) {                                          \
        memcpy(dest->data_, src->data_, sizeof(type) * src->size_);     \
    }                                                                   \
}                                                                       \
                                                                        \
                                                                        \
void name ## _swap(name *v1, name *v2)                                  \
{                                                                       \
    size_t tmp1;                                                        \
    type *tmp2;                                                         \
                                                                        \
    tmp1 = v1->size_;                                                   \
    v1->size_ = v2->size_;                                              \
    v2->size_ = tmp1;                                                   \
                                                                        \
    tmp1 = v1->capacity_;                                               \
    v1->capacity_ = v2->capacity_;                                      \
    v2->capacity_ = tmp1;                                               \
                                                                        \
    tmp2 = v1->data_;                                                   \
    v1->data_ = v2->data_;                                              \
    v2->data_ = tmp2;                                                   \
}

#endif /* SMTLIB2GENVECTOR_H_INCLUDED */
