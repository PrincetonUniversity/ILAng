/// \file
/// Ser/Des shared config, e.g., data types, constants, etc.

#ifndef ILANG_PORTABLE_SERDES_CONFIG_H__
#define ILANG_PORTABLE_SERDES_CONFIG_H__

/// \namespace ilang
namespace ilang {

/// Ser/Des ID for Sort.
enum SERDES_SORT_ID { BOOL = 1, BITVECTOR, MEMORY };
/// Ser/Des ID for Expr.
enum SERDES_EXPR_ID { VAR = 1, CONST, OP };

}; // namespace ilang

#endif // ILANG_PORTABLE_SERDES_CONFIG_H__
