/// \file
/// Header for Axiom helpers (some helper classes to used in writing Axioms)


#ifndef AXIOM_HELPER_H__
#define AXIOM_HELPER_H__

/// \namespace ila
namespace ila {

	/******************************************************************************/
	// Helper Functions
	/******************************************************************************/

	/// This is to deal with forall (if does not exist, it should be true also)
	z3::expr Z3ForallList(const std::vector<z3::expr> & l, z3::context& ctx_);
	/// This is to apply to exists, (if does not exist, it should be false)
	z3::expr Z3ExistsList(const std::vector<z3::expr> & l, z3::context& ctx_);
	/// This is just a shortcut to be used for generated axiom 
	z3::expr Z3Implies(const z3::expr &a, const z3::expr &b);
	/// This is just a shortcut to be used for generated axiom 
	z3::expr Z3And(const z3::expr &a, const z3::expr &b);


	/******************************************************************************/
	// Helper Functions
	/******************************************************************************/
	

} // namespace ila

#endif // AXIOM_HELPER_H__
