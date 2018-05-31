/// \file
/// Header for the class ExprOp

#ifndef EXPR_OP_H__
#define EXPR_OP_H__

#include "ila/ast/expr.h"
#include "util/log.h"

/// \namespace ila
namespace ila {

// Forward declaration.
class Func;

/// \brief Expression for operations, e.g. AND, OR, ADD, etc. Operations are
/// non-terminating nodes in the AST.
class ExprOp : public Expr {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor for unary operators.
  ExprOp(const ExprPtr arg);
  /// Constructor for binary operators.
  ExprOp(const ExprPtr arg0, const ExprPtr arg1);
  /// Constructor for ternary operators.
  ExprOp(const ExprPtr arg0, const ExprPtr arg1, const ExprPtr arg2);
  /// Constructor for binary operators with parameters.
  ExprOp(const ExprPtr arg0, const int& param1);
  /// Constructor for ternary operators with parameters.
  ExprOp(const ExprPtr arg0, const int& param1, const int& param2);
  /// Constructor for multiple argument operators (AppFunc).
  ExprOp(const ExprPtrVec& args);

  /// Default destructor.
  virtual ~ExprOp();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the name of the operation.
  virtual std::string op_name() const = 0;

  /// Return trus since this is an operation.
  bool is_op() const { return true; }

  // ------------------------- METHODS -------------------------------------- //
  /// Return the z3 expression for the node.
  virtual z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                             const std::string& suffix = "") const = 0;

  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;

protected:
  // ------------------------- HELPERS -------------------------------------- //
  /// Derived the sort for binary operations.
  SortPtr GetSortBinaryOperation(const ExprPtr e0, const ExprPtr e1);
  /// Derived the sort for binary comparisons.
  SortPtr GetSortBinaryComparison(const ExprPtr e0, const ExprPtr e1);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  InstrLvlAbsPtr GetHost(const ExprPtrVec& args) const;

}; // class ExprOp

/******************************************************************************/
// Unary
/******************************************************************************/

/// \brief The wrapper for unary negate operation "-".
class ExprOpNeg : public ExprOp {
public:
  /// Constructor for Negate operation.
  ExprOpNeg(const ExprPtr arg);
  std::string op_name() const { return "NEGATE"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpNeg

/// \brief The wrapper for unary not operation "!". (bool only)
class ExprOpNot : public ExprOp {
public:
  /// Constructor for Not operation.
  ExprOpNot(const ExprPtr arg);
  std::string op_name() const { return "NOT"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpNot

/// \brief The wrapper for unary bit-wise complement "~". (bv only)
class ExprOpCompl : public ExprOp {
public:
  /// Constructor for Complement operation.
  ExprOpCompl(const ExprPtr arg);
  std::string op_name() const { return "COMPLEMENT"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpCompl

/******************************************************************************/
// Binary operation
/******************************************************************************/

/// \brief The wrapper for binary logical AND operation "&".
class ExprOpAnd : public ExprOp {
public:
  /// Constructor for AND operation.
  ExprOpAnd(const ExprPtr arg0, const ExprPtr arg1);
  std::string op_name() const { return "AND"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpAnd

/// \brief The wrapper for binary logical OR operation "|".
class ExprOpOr : public ExprOp {
public:
  /// Constructor for OR operation.
  ExprOpOr(const ExprPtr arg0, const ExprPtr arg1);
  std::string op_name() const { return "OR"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpOr

/// \brief The wrapper for binary logical XOR operation "^".
class ExprOpXor : public ExprOp {
public:
  /// Constructor for XOR operation.
  ExprOpXor(const ExprPtr arg0, const ExprPtr arg1);
  std::string op_name() const { return "XOR"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpXor

/// \brief The wrapper for left shifting a bit-vector.
class ExprOpShl : public ExprOp {
public:
  /// Constructor for left shifting a bit-vector.
  ExprOpShl(const ExprPtr bv, const ExprPtr n);
  std::string op_name() const { return "SHL"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpShl

/// \brief The wrapper for arithmetic right shifting a bit-vector.
class ExprOpAshr : public ExprOp {
public:
  /// Constructor for arithmetic right shifting a bit-vector.
  ExprOpAshr(const ExprPtr bv, const ExprPtr n);
  std::string op_name() const { return "ASHR"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpAshr

/// \brief The wrapper for logical right shifting a bit-vector.
class ExprOpLshr : public ExprOp {
public:
  /// Constructor for logical right shifting a bit-vector.
  ExprOpLshr(const ExprPtr bv, const ExprPtr n);
  std::string op_name() const { return "LSHR"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpLshr

/// \brief The wrapper for unsigned addition.
class ExprOpAdd : public ExprOp {
public:
  /// Constructor for ADD operation.
  ExprOpAdd(const ExprPtr arg0, const ExprPtr arg1);
  std::string op_name() const { return "ADD"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpAdd

/// \brief The wrapper for unsigned subtraction.
class ExprOpSub : public ExprOp {
public:
  /// Constructor for SUB operation.
  ExprOpSub(const ExprPtr arg0, const ExprPtr arg1);
  std::string op_name() const { return "SUB"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpSub

// TODO ExprOpDiv

// TODO ExprOpRem

// TODO ExprOpMod

// TODO ExprOpMul

/******************************************************************************/
// Binary comparison
/******************************************************************************/

/// \brief The class wrapper for binary comparison EQ "==".
class ExprOpEq : public ExprOp {
public:
  /// Constructor for Equal comparison.
  ExprOpEq(const ExprPtr arg0, const ExprPtr arg1);
  std::string op_name() const { return "EQ"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpEq

// Not equal is implemented in ExprFuse with Eq and Not.

/// \brief The class wrapper for binary comparison signed less than "<".
class ExprOpLt : public ExprOp {
public:
  /// Construtor for Lt comparison.
  ExprOpLt(const ExprPtr arg0, const ExprPtr arg1);
  std::string op_name() const { return "LT"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpLt

/// \brief The class wrapper for binary comparison signed greater than ">".
class ExprOpGt : public ExprOp {
public:
  /// Constructor for Gt comparison.
  ExprOpGt(const ExprPtr arg0, const ExprPtr arg1);
  std::string op_name() const { return "GT"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpGt

// Signed less than or equal to is implemented in ExprFuse with Eq and Lt.

// Signed greater than or equal to is implemented in ExprFuse with Eq and Gt.

/// \brief The class wrapper for binary comparison unsigned less than.
class ExprOpUlt : public ExprOp {
public:
  /// Construtor for ULt comparison.
  ExprOpUlt(const ExprPtr arg0, const ExprPtr arg1);
  std::string op_name() const { return "ULT"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpUlt

/// \brief The class wrapper for binary comparison unsigned greater than.
class ExprOpUgt : public ExprOp {
public:
  /// Constructor for UGt comparison.
  ExprOpUgt(const ExprPtr arg0, const ExprPtr arg1);
  std::string op_name() const { return "UGT"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpUgt

// Unsigned less than or equal to is implemented in ExprFuse with Eq and ULt.

// Unsigned greater than or equal to is implemented in ExprFuse with Eq and UGt.

/******************************************************************************/
// Memory
/******************************************************************************/

/// \brief The class wrapper for memory load.
class ExprOpLoad : public ExprOp {
public:
  /// Constructor for memory load.
  ExprOpLoad(const ExprPtr mem, const ExprPtr addr);
  std::string op_name() const { return "LOAD"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpLoad

/// \brief The class wrapper for memory store.
class ExprOpStore : public ExprOp {
public:
  /// Constructor for memory store.
  ExprOpStore(const ExprPtr mem, const ExprPtr addr, const ExprPtr data);
  std::string op_name() const { return "STORE"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpStore

/******************************************************************************/
// Bit-manipulation
/******************************************************************************/

/// \brief The class wrapper for bitvector concatenation.
class ExprOpConcat : public ExprOp {
public:
  /// Constructor for bitvector concatenation.
  ExprOpConcat(const ExprPtr hi, const ExprPtr lo);
  std::string op_name() const { return "CONCAT"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpConcat

/// \brief The class wrapper for bitvector extraction.
class ExprOpExtract : public ExprOp {
public:
  /// Constructor for bitvector extraction.
  ExprOpExtract(const ExprPtr bv, const int& hi, const int& lo);
  std::string op_name() const { return "EXTRACT"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpExtract

/// \brief The class wrapper for zero-extend.
class ExprOpZExt : public ExprOp {
public:
  /// Constructor for bitvector zero-extend.
  ExprOpZExt(const ExprPtr bv, const int& bit_width);
  std::string op_name() const { return "ZERO_EXTEND"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpZExtend

/// \brief The calss wrapper for sign-extend.
class ExprOpSExt : public ExprOp {
public:
  /// Constructor for bitvector sign-extend.
  ExprOpSExt(const ExprPtr bv, const int& bit_width);
  std::string op_name() const { return "SIGN_EXTEND"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpSExt

/******************************************************************************/
// Function usage
/******************************************************************************/

/// \brief The class wrapper for apply uninterpreted function.
class ExprOpAppFunc : public ExprOp {
public:
  /// Type for forware declaring Func.
  typedef std::shared_ptr<Func> FuncPtr;

  /// Constructor for apply uninterpreted function.
  ExprOpAppFunc(const FuncPtr f, const ExprPtrVec& args);
  std::string op_name() const { return "APP"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;

private:
  /// Uninterpreted funcion.
  FuncPtr f;
}; // class ExprOpAppFunc

/******************************************************************************/
// Others
/******************************************************************************/

/// \brief The class wrapper for logical imply.
class ExprOpImply : public ExprOp {
public:
  /// Constructor for imply.
  ExprOpImply(const ExprPtr ante, const ExprPtr cons);
  std::string op_name() const { return "IMPLY"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpImply

/// \brief The class wrapper for if-then-else.
class ExprOpIte : public ExprOp {
public:
  /// Constructor for if-then-else.
  ExprOpIte(const ExprPtr cnd, const ExprPtr true_expr,
            const ExprPtr false_expr);
  std::string op_name() const { return "ITE"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpIte

} // namespace ila

#endif // EXPR_OP_H__

