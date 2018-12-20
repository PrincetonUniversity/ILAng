/********************

 ILA helpers

********************/

#include <ilang/ila/instr_lvl_abs.h>

#ifndef __ILA_HELPER_HPP__
#define __ILA_HELPER_HPP__

/*
template<typename First, typename ... Rest>
ExprRef mConcat(const First & arg, const Rest & ... rest ) {
    return Concat(  arg , mConcat(rest...) );
}
*/

#include <list>
typedef std::list<ilang::ExprRef> exp_list;
ila::ExprRef lConcat(const exp_list& l);

#endif
