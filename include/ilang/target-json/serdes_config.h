/// \file
/// ILA to JSON Ser/Des config, macro, etc.

#ifndef ILANG_TARGET_JSON_SERDES_CONFIG_H__
#define ILANG_TARGET_JSON_SERDES_CONFIG_H__

#include <ilang/util/log.h>

/// \namespace ilange
namespace ilang {

/// ILA ser/des specific ID for Expr type.
enum ExprTypeId { kVar = 1, kConst, kOp };

// Sort
#define SERDES_SORT_UID "u"
#define SERDES_SORT_WIDTH "w"
#define SERDES_SORT_ADDR_WIDTH "a"
#define SERDES_SORT_DATA_WIDTH "d"

// Func
#define SERDES_FUNC_ID "i"
#define SERDES_FUNC_NAME "n"
#define SERDES_FUNC_OUT "o"
#define SERDES_FUNC_ARGS "a"

// Expr
#define SERDES_EXPR_ID "i"
#define SERDES_EXPR_UID "u"
#define SERDES_EXPR_SORT "s"
#define SERDES_EXPR_NAME "n"
#define SERDES_EXPR_VAL "v"
#define SERDES_EXPR_OP "o"
#define SERDES_EXPR_ARGS "a"
#define SERDES_EXPR_PARAMS "p"
#define SERDES_EXPR_FUNC "f"

// Instr
#define SERDES_INSTR_NAME "n"
#define SERDES_INSTR_DECODE "d"
#define SERDES_INSTR_UPDATE "u"

// InstrLvlAbs
#define SERDES_ILA_NAME "n"
#define SERDES_ILA_INPUT "i"
#define SERDES_ILA_STATE "s"
#define SERDES_ILA_FETCH "f"
#define SERDES_ILA_VALID "v"
#define SERDES_ILA_INSTR "instr"
#define SERDES_ILA_INIT "init"
#define SERDES_ILA_CHILD "c"

// ConstVal
#define SERDES_CONST_VAL "v"
#define SERDES_CONST_DEF "d"
#define SERDES_CONST_MAP "m"

// Global
#define SERDES_GLOBAL_AST "a"
#define SERDES_GLOBAL_FUNC "f"
#define SERDES_GLOBAL_TOP "t"

}; // namespace ilang

#endif // ILANG_TARGET_JSON_SERDES_CONFIG_H__
