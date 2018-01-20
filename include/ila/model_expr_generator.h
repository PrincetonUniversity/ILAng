/// \file
/// Header for the model z3 expression generator.

#ifndef __MODEL_EXPR_GEN_H__
#define __MODEL_EXPR_GEN_H__

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

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Turn on z3 expression simplification if true.
  void set_z3_simplify(bool z3_smpl);

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Get the z3 expression for the AST node.
  z3::expr Node(const ExprPtr node, const std::string& prefix,
                const std::string& suffix);
  /// \brief Get the set of z3 expression (constraints) for the instruction.
  /// Note that states with no update functions are encoded as unchanged.
  Z3ExprMapPtr Instr(const InstrPtr instr, const std::string& prefix,
                     const std::string& suffix);
  /// \brief Get the set of z3 expression (constraints) for the flat (no child)
  /// ILA. Note that all states are encoded as unchanged if the next state
  /// function is not specified.
  Z3ExprVecPtr ILA(const InstrLvlAbsPtr ila, const std::string& prefix,
                   const std::string& suffix);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The underlying z3 context.
  z3::context& ctx_;
  /// The z3 expression adapter.
  Z3ExprAdapter gen_;

  // ------------------------- HELPERS -------------------------------------- //

}; // class ModelExprGen

} // namespace ila

#endif // __MODEL_EXPR_GEN_H__

