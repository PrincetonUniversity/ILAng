/* -*- C -*-
 *
 * A unified header file for the smtlib2parser library
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

#include "smtparser/smtlib2abstractparser.h"
#include "smtparser/smtlib2abstractparser_private.h"
#include "smtlib2bisonparser.h"
#include "smtparser/smtlib2charbuf.h"
#include "smtlib2flexlexer.h"
#include "smtparser/smtlib2genlist.h"
#include "smtparser/smtlib2genvector.h"
#include "smtparser/smtlib2hashtable.h"
#include "smtparser/smtlib2parserinterface.h"
#include "smtparser/smtlib2scanner.h"
#include "smtparser/smtlib2stream.h"
#include "smtparser/smtlib2termparser.h"
#include "smtparser/smtlib2types.h"
#include "smtparser/smtlib2utils.h"
#include "smtparser/smtlib2vector.h"
