/// \file  some macros to help deal with smt operators
/// because they are macros, no need to namespace

#ifndef SMT_OP_H__
#define SMT_OP_H__

#define CHECK_EMPTY_PARAM(idx, args)                                           \
  ILA_CHECK((idx).empty());                                                   \
  ILA_CHECK((args).empty())

#define CHECK_BV_MULTI_ARG(idx, args)                                          \
  ILA_CHECK((idx).empty());                                                   \
  ILA_CHECK((args).size() >= 2);

#define CHECK_BOOL_MULTI_ARG(idx, args) CHECK_BV_MULTI_ARG(idx, args)

#define CHECK_BOOL_ONE_ARG(idx, args)                                          \
  ILA_CHECK(idx.empty());                                                     \
  ILA_CHECK(args.size() == 1);                                                \
  ILA_CHECK(get_term(args[0])._type.is_bool())

#define CHECK_BOOL_TWO_ARG(idx, args)                                          \
  ILA_CHECK((idx).empty());                                                   \
  ILA_CHECK((args).size() == 2);                                              \
  ILA_CHECK(get_term((args)[0])._type.is_bool());                             \
  ILA_CHECK(get_term((args)[1])._type.is_bool())

#define CHECK_BV_TWO_ARG(idx, args)                                            \
  ILA_CHECK((idx).empty());                                                   \
  ILA_CHECK((args).size() == 2);                                              \
  ILA_CHECK(get_term((args)[0])._type.is_bv());                               \
  ILA_CHECK(get_term((args)[1])._type.is_bv());                               \
  ILA_CHECK(var_type::eqtype(get_term((args)[0])._type, get_term((args)[1])._type))

#define CHECK_BV_COMPARE(idx, args) CHECK_BV_TWO_ARG(idx, args)

#define CHECK_BV_ONE_ARG(idx, args)                                            \
  ILA_CHECK(idx.empty());                                                     \
  ILA_CHECK(args.size() == 1);                                                \
  ILA_CHECK(get_term(args[0])._type.is_bv());

#define CHECK_BV_TWO_ARG_DIFF_WIDTH(idx, args)                                 \
  ILA_CHECK((idx).empty());                                                   \
  ILA_CHECK((args).size() == 2);                                              \
  ILA_CHECK(get_term((args)[0])._type.is_bv());                               \
  ILA_CHECK(get_term((args)[1])._type.is_bv());

#define MAKE_BOOL_RESULT(vlg_expr)                                             \
  std::string search_name = "##bool_" + (vlg_expr);                            \
  if (!IN(search_name, name2term_map)) {                                       \
    return new_term(                                                           \
        search_name,                                                           \
        SmtTermInfoVerilog((vlg_expr), var_type(var_type::tp::Bool, 1, ""),    \
                           this));                                             \
  }                                                                            \
  return (name2term_map.at(search_name))

#define MAKE_MULTI_OP(vlg_expr, args, TYPE, op)                                \
  bool first = true;                                                           \
  for (auto&& arg : (args)) {                                                  \
    const auto & t = get_term(arg);                                            \
    ILA_CHECK(t._type._type == (TYPE));                                       \
    if (first)                                                                 \
      (vlg_expr) = "(" +t._translate + ")";                                    \
    else                                                                       \
      (vlg_expr) += " " op "(" + t._translate + ")";                           \
    first = false;                                                             \
  }

#define MAKE_BV_RESULT_TYPE_AS_ARGN(vlg_expr, args, n)                         \
  std::string search_name =                                                    \
      "##bv" + std::to_string(get_term(args[(n)])._type._width) + "_" + (vlg_expr);     \
  if (!IN(search_name, name2term_map)) {                                       \
    return new_term(                                      \
        search_name, SmtTermInfoVerilog(vlg_expr, get_term(args[(n)])._type, this));   \
  }                                                                            \
  return (name2term_map.at(search_name))

#define MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args)                            \
  MAKE_BV_RESULT_TYPE_AS_ARGN(vlg_expr, args, 0)

#endif // SMT_OP_H__
