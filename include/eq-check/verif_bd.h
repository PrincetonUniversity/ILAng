/// \file
/// Header for equivalence checking using the Birch-Dill methodology

#ifndef VERIF_BD_H__
#define VERIF_BD_H__

#include "eq-check/ref_rel.h"

/// \namespace ila
namespace ila {

#if 0
/// \brief The class for performing equivalence checking using the Birch-Dill
/// methodology (i.e. commutative diagram with the flushing/stall function).
class VerifBd {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  VerifBd(RefRelPtr ref);
  /// Default destructor.
  ~VerifBd();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the number of refinement unit.
  size_t unit_num() const;

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Perform equivalence checking for all refinement units up to the
  /// given bound.
  /// \param[in] bound the number of steps to unroll.
  bool CheckAll(const unsigned& bound) const;

  /// \brief Perform equivalence checking on the i-th refinement unit up to the
  /// given bound.
  /// \param[in] bound the number of steps to unroll.
  /// \param[in] i the index of the refinement unit.
  bool CheckUnit(const unsigned& bound, const size_t& i) const;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The refinement relation.
  RefRelPtr ref_;

  // ------------------------- HELPERS -------------------------------------- //

}; // class VerifBd
#endif

} // namespace ila

#endif // VERIF_BD_H__

