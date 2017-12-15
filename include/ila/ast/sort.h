/// \file
/// Header for the class Sort

#ifndef __SORT_H__
#define __SORT_H__

#include "ila/ast.h"
#include <ostream>
#include <vector>

/// \namespace ila
namespace ila {

/// \def SortType
typedef enum { SORT_BOOL, SORT_BV, SORT_ARRAY, SORT_APP } SortType;

/// \class Sort
/// The class for sort (type for expr, and the range/domain of functions).
class Sort : public Ast {
public:
  /// \def SortPtr
  typedef std::shared_ptr<Sort> SortPtr;
  /// \def SortPtrVec
  typedef std::vector<SortPtr> SortPtrVec;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor for Boolean type.
  Sort();
  /// Constructor for Bitvector type.
  Sort(const int& bit_width);
  /// Constructor for Array (Memory) type.
  Sort(const int& addr_width, const int& data_width);
  /// Constructor for Application type.
  Sort(const SortPtr& range_sort, const SortPtrVec& args_sort);
  /// Default destructor.
  ~Sort();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the bit width (bitvector).
  const int& bit_width() const;
  /// Return the address width (array).
  const int& addr_width() const;
  /// Return the data width (array).
  const int& data_width() const;
  /// Return the range sort (app).
  const SortPtr& range_sort() const;
  /// Return the domain sort (app).
  const SortPtr& args_sort() const;

  // ------------------------- METHODS -------------------------------------- //
  /// Return true if this is a Boolean expression.
  bool IsBool() const;
  /// Return true if this is a Bitvector expression.
  bool IsBv() const;
  /// Return true if this is an Array expression.
  bool IsArray() const;
  /// Return true if this is an Application expression.
  bool IsApp() const;

  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;

  /// Overload output stream operator.
  friend std::ostream& operator<<(std::ostream& out, const Sort& s);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The type for the sort.
  SortType type_;
  /// Bit width of bitvector.
  int bit_width_;
  /// Address width of array.
  int addr_width_;
  /// Data width of array.
  int data_width_;
  /// Sort of the output data of application.
  SortPtr range_sort_;
  /// Sorts of the application arguments (domain).
  SortPtrVec args_sort_;

  // ------------------------- HELPERS -------------------------------------- //
  /// Print Boolean type sort.
  std::ostream& PrintBool(std::ostream& out) const;
  /// Print Bitvector type sort.
  std::ostream& PrintBv(std::ostream& out) const;
  /// Print Array type sort.
  std::ostream& PrintArray(std::ostream& out) const;
  /// Print Application type sort.
  std::ostream& PrintApp(std::ostream& out) const;

}; // class Sort

typedef Sort::SortPtr SortPtr;
typedef Sort::SortPtrVec SortPtrVec;

} // namespace ila

#endif // __SORT_H__

