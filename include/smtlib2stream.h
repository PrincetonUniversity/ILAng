/* -*- C -*-
 *
 * Interfaces for abstract character-based I/O streams
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
#ifndef SMTLIB2STREAM_H_INCLUDED
#define SMTLIB2STREAM_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#include "smtlib2charbuf.h"

typedef struct smtlib2_stream smtlib2_stream;

struct smtlib2_stream {
    int (*get_char)(smtlib2_stream *s);
    int (*put_char)(smtlib2_stream *s, char c);
    bool (*eof)(smtlib2_stream *s);
};

#define smtlib2_stream_getc(s) ((s)->get_char(s))
#define smtlib2_stream_putc(s, c) ((s)->put_char(s, c))
#define smtlib2_stream_eof(s) ((s)->eof(s))

/*****************************************************************************
 * FILE-based streams
 *****************************************************************************/

typedef struct {
    smtlib2_stream parent_;
    FILE *f_;
} smtlib2_fstream;

smtlib2_fstream *smtlib2_fstream_new(FILE *f);
void smtlib2_fstream_delete(smtlib2_fstream *s);

/*****************************************************************************
 * Buffer-based streams
 *****************************************************************************/

typedef struct {
    smtlib2_stream parent_;
    smtlib2_charbuf *buf_;
    size_t nextidx_;
} smtlib2_sstream;

smtlib2_sstream *smtlib2_sstream_new(smtlib2_charbuf *buf);
void smtlib2_sstream_delete(smtlib2_sstream *s);


#endif /* SMTLIB2STREAM_H_INCLUDED */
