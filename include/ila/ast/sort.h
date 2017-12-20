/// \file
/// Header for the class Sort

#ifndef __SORT_H__
#define __SORT_H__

#include "ila/ast/ast.h"
#include <ostream>
#include <vector>

/// \namespace ila
namespace ila {

/// \def SortType
typedef enum { SORT_BOOL, SORT_BV, SORT_MEM, SORT_APP } SortType;

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
  /// Constructor for Memory (Array) type.
  Sort(const int& addr_width, const int& data_width);
  /// Constructor for Application type.
  Sort(const SortPtr range_sort, const SortPtrVec& args_sort);
  /// Default destructor.
  ~Sort();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the bit width (bitvector).
  const int& bit_width() const;
  /// Return the address width (mem).
  const int& addr_width() const;
  /// Return the data width (mem).
  const int& data_width() const;
  /// Return the range sort (app).
  const SortPtr range() const;
  /// Return the number of domain argument (app).
  size_t num_arg() const;
  /// Return the i-th domain sort (app).
  const SortPtr arg(const size_t& i) const;

  /// Return true if this is a Boolean expression.
  bool is_bool() const;
  /// Return true if this is a Bitvector expression.
  bool is_bv() const;
  /// Return true if this is an Memory expression.
  bool is_mem() const;
  /// Return true if this is an Application expression.
  bool is_app() const;

  // ------------------------- METHODS -------------------------------------- //
  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;
  /// Compare two Sorts.
  static bool Equal(const Sort& lhs, const Sort& rhs);

  /// Overload output stream operator.
  friend std::ostream& operator<<(std::ostream& out, const Sort& s);
  /// Overlaod comparison.
  friend bool operator==(const Sort& lhs, const Sort& rhs);
#if 0
  /// Overlaod comparison with pointers.
  friend bool operator==(const SortPtr lhs, const SortPtr rhs);
#endif

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The type for the sort.
  SortType type_;
  /// Bit width of bitvector.
  int bit_width_;
  /// Address width of mem.
  int addr_width_;
  /// Data width of mem.
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
  std::ostream& PrintMem(std::ostream& out) const;
  /// Print Application type sort.
  std::ostream& PrintApp(std::ostream& out) const;

}; // class Sort

typedef Sort::SortPtr SortPtr;
typedef Sort::SortPtrVec SortPtrVec;

} // namespace ila

#endif // __SORT_H__

