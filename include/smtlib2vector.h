/* -*- C -*-
 *
 * Resizable arrays for the SMT-LIB v2 parser
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
#ifndef SMTLIB2VECTOR_H_INCLUDED
#define SMTLIB2VECTOR_H_INCLUDED

#include "smtlib2genvector.h"

SMTLIB2_DECLARE_VECTOR(smtlib2_vector, intptr_t)

#define smtlib2_vector_size(v) SMTLIB2_VECTOR_SIZE(v)
#define smtlib2_vector_capacity(v) SMTLIB2_VECTOR_CAPACITY(v)
#define smtlib2_vector_at(v, i) (SMTLIB2_VECTOR_ARRAY(v)[(i)])
#define smtlib2_vector_last(v) smtlib2_vector_at(v, SMTLIB2_VECTOR_SIZE(v)-1)
#define smtlib2_vector_array(v) SMTLIB2_VECTOR_ARRAY(v)

#endif /* SMTLIB2VECTOR_H_INCLUDED */
