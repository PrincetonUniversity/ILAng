/// \file Header Externally Provided Target for inv-syn
/// to be specific:
///     1. reachability : add cex assertion, add wires / connect
///         so you need to analyze the low level design indeed, but
///         the top level one: add to placeholder (%assert%) (%declare%)
///         the lowlevel one, do it according to vlg_mod
///         
///         then generate smt -> chc -> auto run -> extract result -> to inv_obj
///
///     2. eq check : add inv_obj as assumptions (%assumpt%) ?  to a tcl I think is enough
///                     push to server, run it, generate vcd (how?) fetch back, 
///                     cex_extract to extract the counterexample
///
///


#ifndef LOOP_EXTERN_H__
#define LOOP_EXTERN_H__



#endif // LOOP_EXTERN_H__
