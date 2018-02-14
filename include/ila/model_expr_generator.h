/// \file
/// Header for the model z3 expression generator.

#ifndef MODEL_EXPR_GEN_H__
#define MODEL_EXPR_GEN_H__

#include "ila/defines.h"
#include "ila/instr_lvl_abs.h"
#include "ila/z3_expr_adapter.h"
#include "z3++.h"
#include <unordered_map>

/// \namespace ila
namespace ila {

/// \brief The class for different z3 expression generator, from ILA,
/// instruction, to state updates, etc.
class ModelExprGen {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor.
  ModelExprGen(z3::context& ctx);
  /// Destructor.
  ~ModelExprGen();

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Get the z3 expression for the AST node.
  z3::expr Node(const ExprPtr node, const std::string& suffix);

  /// \brief Get the set of z3 expression (constraints) for the instruction.
  /// - States with no update functions are encoded as unchanged.
  z3::expr Instr(const InstrPtr instr, const std::string& suffix_prev = "0",
                 const std::string& suffix_next = "1", bool complete = true);

  /// \brief Get the set of z3 expression (constraints) for the ILA.
  /// - Assume no child-ILAs (not considered).
  /// - States with no update functions are encoded as unchanged.
  /// - Assume one-hot encoding of all instructions.
  z3::expr IlaOneHotFlat(const InstrLvlAbsPtr ila,
                         const std::string& suffix_prev = "0",
                         const std::string& suffix_next = "1");

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The underlying z3 context.
  z3::context& ctx_;
  /// The z3 expression adapter.
  Z3ExprAdapter gen_;

  // ------------------------- HELPERS -------------------------------------- //

}; // class ModelExprGen

} // namespace ila

#endif // MODEL_EXPR_GEN_H__

