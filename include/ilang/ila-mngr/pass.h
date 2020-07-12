/// \file
/// ILA passes

#ifndef ILANG_ILA_MNGR_PASS_H__
#define ILANG_ILA_MNGR_PASS_H__

#include <functional>

#include <ilang/ila/instr_lvl_abs.h>

/// \namespace ilang
namespace ilang {

/// Infer the control flow graph among the child-instructions (instr. seq.)
bool PassInferChildProgCFG(const InstrLvlAbsPtr& m);

/// Map the child program (and its entry point) to the parent instruction
bool PassMapChildProgEntryPoint(const InstrLvlAbsPtr& m);

/// Rewrite the conditional STORE in the AST.
bool PassRewriteConditionalStore(const InstrLvlAbsPtr& m);

/// Rewrite the STORE-LOAD pattern in the AST.
bool PassRewriteStoreLoad(const InstrLvlAbsPtr& m);

/// A pass template for rewriting AST in an ILA.
/// \param[in] m The target ILA.
/// \param[in] Rewr The pass-specific rewriting function.
bool PassRewriteGeneric(const InstrLvlAbsPtr& m,
                        std::function<ExprPtr(const ExprPtr)> Rewr);

/// Simplify instruction state updates.
/// \param[in] m The target ILA.
/// \param[in] timeout Max time (ms) for each SMT query. (-1 for default)
bool PassSimplifyInstrUpdate(const InstrLvlAbsPtr& m, const int& timeout = -1);

/// \namespace pass
namespace pass {

/// \brief Simplify instructions (across the hierarchy) syntactically.
/// (Light-weight simplification, no SMT query.)
/// \param[in] m The top-level ILA.
bool SimplifySyntactic(const InstrLvlAbsCnstPtr& m);

} // namespace pass

}; // namespace ilang

#endif // ILANG_ILA_MNGR_PASS_H__
