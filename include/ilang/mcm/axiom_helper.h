/// \file
/// Header for Axiom helpers (some helper classes to used in writing Axioms)

#ifndef ILANG_MCM_AXIOM_HELPER_H__
#define ILANG_MCM_AXIOM_HELPER_H__

/// \namespace ilang
namespace ilang {

/******************************************************************************/
// Helper Functions
/******************************************************************************/

#if 0
/// This is to deal with forall (if does not exist, it should be true also)
z3::expr Z3ForallList(const std::vector<z3::expr> & l); // move into mcm class
/// This is to apply to exists, (if does not exist, it should be false)
z3::expr Z3ExistsList(const std::vector<z3::expr> & l);
#endif

/// This is just a shortcut to be used for generated axiom
z3::expr Z3And(const z3::expr& a, const z3::expr& b);

} // namespace ilang

#endif // ILANG_MCM_AXIOM_HELPER_H__
