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

#include "smtlib2scanner.h"
#include "smtlib2bisonparser.h"
#include "smtlib2flexlexer.h"
#include <stdlib.h>

extern int smtlib2_parser_parse(yyscan_t scanner, smtlib2_parser_interface *p);


struct smtlib2_scanner {
    yyscan_t flex_scanner_;
    smtlib2_stream *stream_;
};


smtlib2_scanner *smtlib2_scanner_new(smtlib2_stream *source)
{
    smtlib2_scanner *ret = (smtlib2_scanner *)malloc(sizeof(smtlib2_scanner));
    smtlib2_parser_lex_init(&(ret->flex_scanner_));
    ret->stream_ = source;
    smtlib2_parser_set_extra(source, ret->flex_scanner_);

    return ret;
}


void smtlib2_scanner_delete(smtlib2_scanner *s)
{
    smtlib2_parser_lex_destroy(s->flex_scanner_);
    free(s);
}


void smtlib2_parse(smtlib2_scanner *scanner, smtlib2_parser_interface *parser)
{
    smtlib2_parser_parse(scanner->flex_scanner_, parser);
}
