/// \file
/// Header for the class Sort

#ifndef __SORT_H__
#define __SORT_H__

#include "ila/ast.h"

/// \namespace ila
namespace ila {

/// \def SortType
typedef enum { SORT_BOOL, SORT_BV, SORT_ARRAY, SORT_APP } SortType;

/// \class Sort
/// The class for sort (type for expr, and the range/domain of functions).
class Sort : public Ast {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  Sort();
  /// Default destructor.
  ~Sort();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //

  // ------------------------- METHODS -------------------------------------- //
  /// Is Bool sort.
  bool IsBool() const;
  /// Is Bitvector sort.
  bool IsBv() const;
  /// Is Array sort.
  bool IsArray() const;
  /// Is Application sort.
  bool IsApp() const;
  /// Is well sorted.
  bool IsWellSorted(const Sort& srt) const;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The type for the sort.
  SortType type_;

  // ------------------------- HELPERS -------------------------------------- //

}; // class Sort

} // namespace ila

#endif // __SORT_H__

