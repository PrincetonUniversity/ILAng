/// \file
/// Header for the class Sort

#ifndef SORT_H__
#define SORT_H__

#include "ila/ast/ast.h"
#include <ostream>
#include <vector>

/// \namespace ila
namespace ila {

/// SortType
typedef enum { SORT_BOOL, SORT_BV, SORT_MEM } SortType;

/// \brief The class for sort (type for expr, and the range/domain of
/// functions).
class Sort : public Ast {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor for Boolean type.
  Sort();
  /// Constructor for Bitvector type.
  Sort(const int& bit_width);
  /// Constructor for Memory (Array) type.
  Sort(const int& addr_width, const int& data_width);
  /// Default destructor.
  ~Sort();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the bit width (bitvector).
  inline const int& bit_width() const { return bit_width_; }
  /// Return the address width (mem).
  inline const int& addr_width() const { return addr_width_; }
  /// Return the data width (mem).
  inline const int& data_width() const { return data_width_; }

  /// Is type sort (object).
  bool is_sort() const { return true; }

  /// Return true if this is a Boolean expression.
  inline bool is_bool() const { return (type_ == SortType::SORT_BOOL); }
  /// Return true if this is a Bitvector expression.
  inline bool is_bv() const { return (type_ == SortType::SORT_BV); }
  /// Return true if this is an Memory expression.
  inline bool is_mem() const { return (type_ == SortType::SORT_MEM); }

  // ------------------------- METHODS -------------------------------------- //
  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;
  /// Compare two Sorts.
  static bool Equal(const Sort& lhs, const Sort& rhs);

  /// Overload output stream operator.
  friend std::ostream& operator<<(std::ostream& out, const Sort& s);
  /// Overlaod comparison.
  friend bool operator==(const Sort& lhs, const Sort& rhs);

  /// Create Bool sort
  static Sort MakeBoolSort();
  /// Create Bitvector sort.
  static Sort MakeBvSort(const int& bit_width);
  /// Create Memory sort.
  static Sort MakeMemSort(const int& addr_width, const int& data_width);

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

  // ------------------------- HELPERS -------------------------------------- //

  /// Print Boolean type sort.
  std::ostream& PrintBool(std::ostream& out) const;
  /// Print Bitvector type sort.
  std::ostream& PrintBv(std::ostream& out) const;
  /// Print Array type sort.
  std::ostream& PrintMem(std::ostream& out) const;

}; // class Sort

} // namespace ila

#endif // SORT_H__

