/// \file
/// Header for the class ExprOp

#ifndef EXPR_OP_H__
#define EXPR_OP_H__

#include "ila/ast/expr.h"
#include "util/log.h"
#include <string>

/// \namespace ila
namespace ila {

/// \brief Expression for operations, e.g. AND, OR, ADD, etc. Operations are
/// non-terminating nodes in the AST.
class ExprOp : public Expr {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor. DO NOT USE.
  ExprOp();
  /// Constructor for unary operators.
  ExprOp(const ExprPtr arg);
  /// Constructor for binary operators.
  ExprOp(const ExprPtr arg0, const ExprPtr arg1);
  /// Constructor for ternary operators.
  ExprOp(const ExprPtr arg0, const ExprPtr arg1, const ExprPtr arg2);
  /// Constructor for ternary operators with parameters.
  ExprOp(const ExprPtr arg0, const int& param1, const int& param2);
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
  Sort GetSortBinaryOperation(const Sort& s0, const Sort& s1);
  /// Derived the sort for binary comparisons.
  Sort GetSortBinaryComparison(const Sort& s0, const Sort& s1);

private:
  // ------------------------- MEMBERS -------------------------------------- //

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

// TODO ExprOpShl

// TODO ExprOpShr

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

// ExprOpNe is implemented in ExprFuse with Eq and Not.

/// \brief The class wrapper for binary comparison LT "<".
class ExprOpLt : public ExprOp {
public:
  /// Construtor for Lt comparison.
  ExprOpLt(const ExprPtr arg0, const ExprPtr arg1);
  std::string op_name() const { return "LT"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpLt

/// \brief The class wrapper for binary comparison GT ">".
class ExprOpGt : public ExprOp {
public:
  /// Constructor for Gt comparison.
  ExprOpGt(const ExprPtr arg0, const ExprPtr arg1);
  std::string op_name() const { return "GT"; }
  z3::expr GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                     const std::string& suffix = "") const;
}; // class ExprOpGt

// ExprOpLe is implemented in ExprFuse with Eq and Lt.

// ExprOpGe is implemented in ExprFuse with Eq and Gt.

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

// TODO ExprOpZeroExtend

/******************************************************************************/
// Function usage
/******************************************************************************/

// TODO ExprOpAppFunc

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

