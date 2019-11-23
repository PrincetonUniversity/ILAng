/// \file  some macros to help deal with smt operators
/// because they are macros, no need to namespace

#ifndef SMT_OP_H__
#define SMT_OP_H__

#define CHECK_EMPTY_PARAM(idx,args) \
  ILA_ASSERT((idx).empty()); \
  ILA_ASSERT((args).empty())


#define CHECK_BV_MULTI_ARG(idx,args) \
  ILA_ASSERT((idx).empty()); \
  ILA_ASSERT((args).size() >= 2);

#define CHECK_BOOL_MULTI_ARG(idx,args) CHECK_BV_MULTI_ARG(idx,args)

#define CHECK_BOOL_ONE_ARG(idx,args) \
  ILA_ASSERT(idx.empty()); \
  ILA_ASSERT(args.size() == 1); \
  ILA_ASSERT(args[0]->_type._type == var_type::tp::Bool)

#define CHECK_BOOL_TWO_ARG(idx,args) \
  ILA_ASSERT((idx).empty()); \
  ILA_ASSERT((args).size() == 2); \
  ILA_ASSERT((args)[0]->_type._type == var_type::tp::Bool); \
  ILA_ASSERT((args)[1]->_type._type == var_type::tp::Bool)

#define CHECK_BV_TWO_ARG(idx,args) \
  ILA_ASSERT((idx).empty()); \
  ILA_ASSERT((args).size() == 2); \
  ILA_ASSERT((args)[0]->_type._type == var_type::tp::BV); \
  ILA_ASSERT((args)[1]->_type._type == var_type::tp::BV); \
  ILA_ASSERT(var_type::eqtype((args)[0]->_type, (args)[1]->_type))
  
#define CHECK_BV_COMPARE(idx,args) CHECK_BV_TWO_ARG(idx,args)

#define CHECK_BV_ONE_ARG(idx,args) \
  ILA_ASSERT(idx.empty()); \
  ILA_ASSERT(args.size() == 1); \
  ILA_ASSERT(args[0]->_type._type == var_type::tp::BV);

#define CHECK_BV_TWO_ARG_DIFF_WIDTH(idx,args) \
  ILA_ASSERT((idx).empty()); \
  ILA_ASSERT((args).size() == 2); \
  ILA_ASSERT((args)[0]->_type._type == var_type::tp::BV); \
  ILA_ASSERT((args)[1]->_type._type == var_type::tp::BV); 

#define MAKE_BOOL_RESULT(vlg_expr) \
std::string search_name = "##bool_"  + (vlg_expr); \
  if (not IN(search_name, term_container)) { \
    term_container.insert( std::make_pair( search_name, \
      SmtTermInfoVerilog( \
        (vlg_expr) , \
        var_type(var_type::tp::Bool,1,""), \
        this ) ) ); \
  } \
  return & ( term_container[search_name] )

#define MAKE_MULTI_OP(vlg_expr, args, TYPE, op) \
  bool first = true; \
  for(auto && arg:(args)) { \
    ILA_ASSERT(arg->_type._type == (TYPE)); \
    if (first) \
      (vlg_expr) = "(" + arg->_translate + ")"; \
    else \
      (vlg_expr) += " " op "(" + arg->_translate + ")"; \
    first = false; \
  }



#define MAKE_BV_RESULT_TYPE_AS_ARGN(vlg_expr, args, n) \
  std::string search_name = "##bv"+std::to_string(args[(n)]->_type._width) + "_"  + (vlg_expr); \
  if (not IN(search_name, term_container)) { \
    term_container.insert( std::make_pair( search_name,  \
      SmtTermInfoVerilog( \
        vlg_expr ,  \
        args[(n)]->_type,  \
        this ) ) ); \
  } \
  return & ( term_container[search_name] )

#define MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args) MAKE_BV_RESULT_TYPE_AS_ARGN(vlg_expr,args,0)


#endif // SMT_OP_H__

