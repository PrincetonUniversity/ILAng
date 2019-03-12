/* -*- C -*-
 *
 * A (abstract) lexical scanner for the SMT-LIB v2 language
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

#ifndef SMTLIB2SCANNER_H_INCLUDED
#define SMTLIB2SCANNER_H_INCLUDED

#include "smtlib2parserinterface.h"
#include "smtlib2stream.h"

typedef struct smtlib2_scanner smtlib2_scanner;

smtlib2_scanner *smtlib2_scanner_new(smtlib2_stream *source);
void smtlib2_scanner_delete(smtlib2_scanner *s);
void smtlib2_parse(smtlib2_scanner *scanner, smtlib2_parser_interface *parser);

#endif /* SMTLIB2SCANNER_H_INCLUDED */
