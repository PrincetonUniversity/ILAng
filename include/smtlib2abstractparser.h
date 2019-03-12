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
#ifndef SMTLIB2ABSTRACTPARSER_H_INCLUDED
#define SMTLIB2ABSTRACTPARSER_H_INCLUDED

#include "smtlib2parserinterface.h"
#include "smtlib2termparser.h"
#include "smtlib2utils.h"
#include <stdio.h>

typedef struct smtlib2_abstract_parser smtlib2_abstract_parser;

void smtlib2_abstract_parser_init(smtlib2_abstract_parser *p,
                                  smtlib2_context ctx);
void smtlib2_abstract_parser_deinit(smtlib2_abstract_parser *p);
void smtlib2_abstract_parser_parse(smtlib2_abstract_parser *p, FILE *src);

#endif /* SMTLIB2ABSTRACTPARSER_H_INCLUDED */
