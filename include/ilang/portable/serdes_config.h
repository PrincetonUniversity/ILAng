/// \file
/// ILA to JSON Ser/Des config, macro, etc.

#ifndef ILANG_PORTABLE_SERDES_CONFIG_H__
#define ILANG_PORTABLE_SERDES_CONFIG_H__

/// \namespace ilange
namespace ilang {

// Sort
#define SERDES_SORT_UID "u"
#define SERDES_SORT_WIDTH "w"
#define SERDES_SORT_ADDR_WIDTH "a"
#define SERDES_SORT_DATA_WIDTH "d"

// Expr
#define SERDES_EXPR_ID "i"
#define SERDES_EXPR_UID "u"
#define SERDES_EXPR_SORT "s"
#define SERDES_EXPR_NAME "n"
#define SERDES_EXPR_VAL "v"
#define SERDES_EXPR_OP "o"
#define SERDES_EXPR_ARGS "a"
#define SERDES_EXPR_PARAMS "p"

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
#define SERDES_ILA_AST "a"
#define SERDES_ILA_CHILD "c"

// ConstVal
#define SERDES_CONST_VAL "v"
#define SERDES_CONST_DEF "d"
#define SERDES_CONST_MAP "m"

}; // namespace ilang

#endif // ILANG_PORTABLE_SERDES_CONFIG_H__
