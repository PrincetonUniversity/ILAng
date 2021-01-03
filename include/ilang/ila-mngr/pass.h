/// \file
/// ILA passes

#ifndef ILANG_ILA_MNGR_PASS_H__
#define ILANG_ILA_MNGR_PASS_H__

#include <functional>

#include <ilang/ila/instr_lvl_abs.h>

/// \namespace ilang
namespace ilang {

/// \namespace pass
namespace pass {

/// Infer the control flow graph among the child-instructions (instr. seq.)
bool InferChildProgCFG(const InstrLvlAbsPtr& m);

/// Map the child program (and its entry point) to the parent instruction
bool MapChildProgEntryPoint(const InstrLvlAbsPtr& m);

/// Rewrite the conditional STORE in the AST.
bool RewriteConditionalStore(const InstrLvlAbsPtr& m);

/// Rewrite the STORE-LOAD pattern in the AST.
bool RewriteStoreLoad(const InstrLvlAbsPtr& m);

/// A pass template for rewriting AST in an ILA.
/// \param[in] m The target ILA.
/// \param[in] Rewr The pass-specific rewriting function.
bool RewriteGeneric(const InstrLvlAbsPtr& m,
                    std::function<ExprPtr(const ExprPtr)> Rewr);

/// \brief Simplify instructions (across the hierarchy) semantically (z3).
/// \param[in] m The top-level ILA.
/// \param[in] timeout Max time (ms) for each SMT query. (-1 for default)
bool SimplifySemantic(const InstrLvlAbsCnstPtr& m, const int& timeout = -1);

/// \brief Simplify instructions (across the hierarchy) syntactically.
/// (Light-weight simplification, no SMT query.)
/// \param[in] m The top-level ILA.
bool SimplifySyntactic(const InstrLvlAbsPtr& m);

/// \brief Sanity check instruction completness and determinism and fix if
/// possible.
/// \param[in] m The top-level ILA.
bool SanityCheckAndFix(const InstrLvlAbsPtr& m);

} // namespace pass

}; // namespace ilang

#endif // ILANG_ILA_MNGR_PASS_H__
