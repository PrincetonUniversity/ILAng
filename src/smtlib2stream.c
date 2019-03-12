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
#include "smtlib2stream.h"
#include <stdlib.h>

static int smtlib2_fstream_getc(smtlib2_stream *s);
static int smtlib2_fstream_putc(smtlib2_stream *s, char c);
static bool smtlib2_fstream_eof(smtlib2_stream *s);

static int smtlib2_sstream_getc(smtlib2_stream *s);
static int smtlib2_sstream_putc(smtlib2_stream *s, char c);
static bool smtlib2_sstream_eof(smtlib2_stream *s);


smtlib2_fstream *smtlib2_fstream_new(FILE *f)
{
    smtlib2_fstream *ret = (smtlib2_fstream *)malloc(sizeof(smtlib2_fstream));
    ((smtlib2_stream *)ret)->get_char = smtlib2_fstream_getc;
    ((smtlib2_stream *)ret)->put_char = smtlib2_fstream_putc;
    ((smtlib2_stream *)ret)->eof = smtlib2_fstream_eof;
    ret->f_ = f;
    return ret;
}


void smtlib2_fstream_delete(smtlib2_fstream *s)
{
    free(s);
}


smtlib2_sstream *smtlib2_sstream_new(smtlib2_charbuf *buf)
{
    smtlib2_sstream *ret = (smtlib2_sstream *)malloc(sizeof(smtlib2_sstream));
    ((smtlib2_stream *)ret)->get_char = smtlib2_sstream_getc;
    ((smtlib2_stream *)ret)->put_char = smtlib2_sstream_putc;
    ((smtlib2_stream *)ret)->eof = smtlib2_sstream_eof;
    ret->buf_ = buf;
    ret->nextidx_ = 0;
    return ret;
}


void smtlib2_sstream_delete(smtlib2_sstream *s)
{
    free(s);
}


static int smtlib2_fstream_getc(smtlib2_stream *s)
{
    smtlib2_fstream *stream = (smtlib2_fstream *)s;
    return fgetc(stream->f_);
}


static int smtlib2_fstream_putc(smtlib2_stream *s, char c)
{
    smtlib2_fstream *stream = (smtlib2_fstream *)s;
    return fputc(c, stream->f_);
}


static bool smtlib2_fstream_eof(smtlib2_stream *s)
{
    smtlib2_fstream *stream = (smtlib2_fstream *)s;
    return feof(stream->f_);
}


static int smtlib2_sstream_getc(smtlib2_stream *s)
{
    smtlib2_sstream *stream = (smtlib2_sstream *)s;
    if (stream->nextidx_ < SMTLIB2_VECTOR_SIZE(stream->buf_)) {
        return smtlib2_charbuf_array(stream->buf_)[stream->nextidx_++];
    } else {
        return EOF;
    }
}


static int smtlib2_sstream_putc(smtlib2_stream *s, char c)
{
    smtlib2_sstream *stream = (smtlib2_sstream *)s;
    smtlib2_charbuf_push(stream->buf_, c);
    return (int)c;
}


static bool smtlib2_sstream_eof(smtlib2_stream *s)
{
    smtlib2_sstream *stream = (smtlib2_sstream *)s;
    return stream->nextidx_ >= SMTLIB2_VECTOR_SIZE(stream->buf_);
}
