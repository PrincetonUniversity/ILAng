/* -*- C -*-
 *
 * An abstract parser interface for the SMT-LIB v2 language
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
#ifndef SMTLIB2PARSERINTERFACE_H_INCLUDED
#define SMTLIB2PARSERINTERFACE_H_INCLUDED

#include "smtlib2types.h"
#include "smtlib2utils.h"


/* typedefs */
typedef struct smtlib2_parser_interface smtlib2_parser_interface;

#define SMTLIB2_PARSER_INTERFACE(p) ((smtlib2_parser_interface *)p)

/**
 * Interface for SMT-LIB v2 parsers
 */
struct smtlib2_parser_interface {
    /**
     * callback for a "set-logic" command
     */
    void (*set_logic)(smtlib2_parser_interface *parser, const char *logic);

    /**
     * callback for a "declare-sort" command
     */
    void (*declare_sort)(smtlib2_parser_interface *parser,
                         const char *sortname, int arity);

    /**
     * callback for a "define-sort" command
     * "params" is a vector of smtlib2_sort for the parameters,
     *          NULL when no parameters are given
     * "sort" is the "template" sort when parameters are used,
     *        otherwise it is a concrete sort
     */
    void (*define_sort)(smtlib2_parser_interface *parser,
                        const char *sortname, smtlib2_vector *params,
                        smtlib2_sort sort);

    /**
     * callback for a "declare-function" command
     */
    void (*declare_function)(smtlib2_parser_interface *parser,
                             const char *name, smtlib2_sort sort);

    /**
     * callback for declaring a quantified variable
     * This gets called for variables declared by an "exists" or "forall"
     * quantification, but also for parameters of a "define-function" command
     */
    void (*declare_variable)(smtlib2_parser_interface *parser,
                             const char *name, smtlib2_sort sort);

    /**
     * callback for a "define-function" command
     * "params" is a vector of smtlib2_term returned by make_term (see below),
     *          declared by declare_variable (see above) in the current scope
     *          (see push_quantifier_scope below),
     *          NULL when no parameters are given
     * "sort" is the sort of the definition
     * "term" is the term "template" term when parameters are used,
     *        or the actual definition when no parameters are given
     */
    void (*define_function)(smtlib2_parser_interface *parser,
                            const char *name,
                            smtlib2_vector *params,
                            smtlib2_sort sort, smtlib2_term term);

    /**
     * callback for a "push" command
     */
    void (*push)(smtlib2_parser_interface *parser, int n);

    /**
     * callback for a "pop" command
     */
    void (*pop)(smtlib2_parser_interface *parser, int n);

    /**
     * callback for an "assert" command
     */
    void (*assert_formula)(smtlib2_parser_interface *parser, smtlib2_term term);

    /**
     * callback for a "check-sat" command
     */
    void (*check_sat)(smtlib2_parser_interface *parser);

    /**
     * callback for a "get-assignment" command
     */
    void (*get_assignment)(smtlib2_parser_interface *parser);

    /**
     * callback for a "get-assertions" command
     */
    void (*get_assertions)(smtlib2_parser_interface *parser);

    /**
     * callback for a "get-unsat-core" command
     */
    void (*get_unsat_core)(smtlib2_parser_interface *parser);

    /**
     * callback for a "get-proof" command
     */
    void (*get_proof)(smtlib2_parser_interface *parser);

    /**
     * callback for a "set-option" command with string value
     */
    void (*set_str_option)(smtlib2_parser_interface *parser,
                           const char *keyword, const char *value);

    /**
     * callback for a "set-option" command with integer value
     * also options with true/false values will trigger this callback
     */
    void (*set_int_option)(smtlib2_parser_interface *parser,
                           const char *keyword, int value);

    /**
     * callback for a "set-option" command with a rational value (e.g. timeout)
     */
    void (*set_rat_option)(smtlib2_parser_interface *parser,
                           const char *keyword, double value);

    /**
     * callback for a "get-info" command
     */
    void (*get_info)(smtlib2_parser_interface *parser,
                     const char *keyword);

    /**
     * callback for a "set-info" command
     */
    void (*set_info)(smtlib2_parser_interface *parser,
                     const char *keyword, const char *value);

    /**
     * callback for a "get-value" command
     * "terms" is a vector of *string representations* of the terms for which
     *         the model value is requested. In order to get the actual terms,
     *         such strings should be parsed. For this, the (non-standard)
     *         ".internal-parse-terms" command can be used.
     *
     *         The reason for this choice is that the SMT-LIB v2 language
     *         mandates that responses to a get-value command return the same
     *         string representation as the input: by explicitly passing the
     *         strings themselves, it is actually possible to perform
     *         arbitrary simplifications to terms (including e.g. expansion of
     *         let bindings) directly at parsing time
     *
     *         See smtlib2yices.c for an example of use of
     *         ".internal-parse-terms" from within a "get-value" callback
     */
    void (*get_value)(smtlib2_parser_interface *parser, smtlib2_vector *terms);

    /**
     * callback for a "exit" command
     */
    void (*exit)(smtlib2_parser_interface *parser);

    /**
     * callback for handling parse errors
     */
    void (*handle_error)(smtlib2_parser_interface *parser, const char *msg);

    /**
     * callback for the ".internal-parse-terms" command (see above)
     */
    void (*set_internal_parsed_terms)(smtlib2_parser_interface *parser,
                                      smtlib2_vector *terms);

    /**
     * push a scope for let bindings. called every time a "let" is parsed
     */
    void (*push_let_scope)(smtlib2_parser_interface *parser);

    /**
     * pop a scope for let bindings. called every time the closing parenthesis
     * for a "let" is parsed
     */
    smtlib2_term (*pop_let_scope)(smtlib2_parser_interface *parser);

    /**
     * push a scope for quantified variables. called every time an "exist" or
     * "forall" is parsed, and also when a "define-function" with parameters
     * is parsed
     */
    smtlib2_term (*push_quantifier_scope)(smtlib2_parser_interface *parser);

    /**
     * pop a scope for quantified variabled. called when the closing
     * parenthesis for an "exists", "forall" or "define-function" is parsed
     */
    smtlib2_term (*pop_quantifier_scope)(smtlib2_parser_interface *parser);

    /**
     * push a scope for sort parameters. called when a "define-sort" is parsed
     */
    void (*push_sort_param_scope)(smtlib2_parser_interface *parser);

    /**
     * pop a scope for sort parameters. called when the closing parenthesis
     * for a "define-sort" is parsed
     */
    void (*pop_sort_param_scope)(smtlib2_parser_interface *parser);

    /**
     * callback for creating terms
     * "symbol" is the identifier associated to this term,
     *          which must have been declared or defined before by a
     *          "declare-function", "define-function", "declare-variable"
     *          command or by a let binding
     * "sort" is the requested sort for this term. it is not NULL only when
     *        an "(as term sort)" construct is used
     * "index" is the index for the identifier (a vector of integers),
     *         used in bit-vector terms.
     *         example: in "(_ extract 3 1)" "extract" is the symbol,
     *         and {3, 1} is the index
     * "args" is the vector of arguments for this term
     *        (a vector of smtlib2_term)         
     */
    smtlib2_term (*make_term)(smtlib2_parser_interface *parser,
                              const char *symbol, smtlib2_sort sort,
                              smtlib2_vector *index,
                              smtlib2_vector *args);

    /**
     * callback for creating numbers
     * "numval" is the string representation of the number, in the given base
     *         (see below). notice that the prefix which identifies the base
     *         (e.g. "#b" for base 2) is not included in "numval"
     *         (so for instance when parsing "#b011" "numval" will be "011")
     * "width" is the bit-width of the number. this is zero if the number
     *         is not a bit-vector
     * "base" is the base used for the representation "numval".
     *        can be 2, 10 or 16
     */
    smtlib2_term (*make_number_term)(smtlib2_parser_interface *parser,
                                     const char *numval, int width, int base);

    /**
     * callback for creating universally-quantified terms
     */
    smtlib2_term (*make_forall_term)(smtlib2_parser_interface *parser,
                                     smtlib2_term term);

    /**
     * callback for creating existentially-quantified terms
     */
    smtlib2_term (*make_exists_term)(smtlib2_parser_interface *parser,
                                     smtlib2_term term);

    /**
     * callback for attaching annotations to terms
     * "term" is the term to annotate
     * "annotations" is a vector of size-2 arrays of strings. each element
     *               represents a pair <keyword, value>. the parser checks
     *               that values are valid sexps, but doesn't interpret
     *               them in any way
     *
     * example: parsing "(! x :named pippo)" will result in a call to
     *          "annotate_term" with "term" set to "x" and annotations to
     *          { { ":named", "pippo" } }
     */
    void (*annotate_term)(smtlib2_parser_interface *parser,
                          smtlib2_term term, smtlib2_vector *annotations);

    /**
     * callback for defining let bindings
     * "symbol" is the name of the binding
     * "term" is the definition
     */
    void (*define_let_binding)(smtlib2_parser_interface *parser,
                               const char *symbol, smtlib2_term term);

    /**
     * callback for creating sorts
     * "sortname" is the name of the sort. it must have been declared with
     *            "declare-sort" or defined with "define-sort"
     * "index" is the sort index, a vector of integers
     *         (e.g. when parsing "(_ BitVec 32)"
     *         "sortname" is "BitVec" and "index" is { 32 })
     */
    smtlib2_sort (*make_sort)(smtlib2_parser_interface *parser,
                              const char *sortname, smtlib2_vector *index);

    /**
     * callback for instantiating parametric sorts
     * "name" is the name of the parametric sort. it must have been declared
     *        with "declare-sort" or defined with "define-sort"
     * "tps" is a vector of smtlib2_sort corresponding to the actual parameters
     *       for the parametric sort "name" 
     */
    smtlib2_sort (*make_parametric_sort)(smtlib2_parser_interface *parser,
                                         const char *name, smtlib2_vector *tps);

    /**
     * callback for creating function sorts
     * "tps" is a vector of size N of smtlib2_sort.
     *       the first N-1 elements are the sorts of the function domain,
     *       and the last one is the sort of the codomain
     */
    smtlib2_sort (*make_function_sort)(smtlib2_parser_interface *parser,
                                       smtlib2_vector *tps);
};


#endif /* SMTLIB2PARSERINTERFACE_H_INCLUDED */
