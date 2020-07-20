/// \file
/// Header for the class Sort

#ifndef ILANG_ILA_AST_SORT_H__
#define ILANG_ILA_AST_SORT_H__

#include <memory>
#include <ostream>

#include <z3++.h>

#include <ilang/ila/ast/ast.h>

/// \namespace ilang
namespace ilang {

/// Unified ID for Sort.
enum AstUidSort { kBool = 1, kBv, kMem };

/// \brief The class for sort (type for expr, and the range/domain of
/// functions).
class Sort : public Ast {
public:
  /// Pointer type for storing/passing Sort.
  typedef std::shared_ptr<Sort> SortPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  Sort();
  /// Virtual default destructor.
  virtual ~Sort();

  // ------------------------- HELPERS -------------------------------------- //
  /// Create a Boolean Sort
  static SortPtr MakeBoolSort();
  /// Create a bit-vector Sort.
  static SortPtr MakeBvSort(const int& bit_width);
  /// Create a memory (array) Sort.
  static SortPtr MakeMemSort(const int& addr_width, const int& data_width);

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the unified ID of Sort.
  virtual AstUidSort uid() const = 0;
  /// Return true if have Boolean sort.
  virtual bool is_bool() const { return false; }
  /// Return true if have bit-vector sort.
  virtual bool is_bv(const int& width = 0) const { return false; }
  /// Return true if have memory (array) sort.
  virtual bool is_mem() const { return false; }

  /// Return the bit-width of bit-vector sort.
  virtual int bit_width() const;
  /// Return the bit-width of the address (index).
  virtual int addr_width() const;
  /// Return the bit-width of the data (value).
  virtual int data_width() const;

  // ------------------------- METHODS -------------------------------------- //
  /// Return z3::sort of the Sort.
  virtual z3::sort GetZ3Sort(z3::context& ctx) const = 0;
  /// Return a z3 variable of the Sort.
  virtual z3::expr GetZ3Expr(z3::context& ctx,
                             const std::string& name) const = 0;

  /// Compare two Sorts.
  virtual bool Equal(const SortPtr rhs) const = 0;
  /// Overlaod comparison.
  friend bool operator==(const SortPtr lhs, const SortPtr rhs) {
    return lhs->Equal(rhs);
  }

  /// Print out to output stream.
  virtual std::ostream& Print(std::ostream& out) const = 0;
  /// Overload output stream operator.
  friend std::ostream& operator<<(std::ostream& out, const SortPtr s) {
    return s->Print(out);
  }

}; // class Sort

/// Pointer type for storing/passing Sort.
typedef Sort::SortPtr SortPtr;

/// \brief The class of Boolean Sort.
class SortBool : public Sort {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  SortBool();
  /// Default destructor.
  ~SortBool();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the unified ID of SortBool.
  AstUidSort uid() const { return AstUidSort::kBool; }
  /// Return true since it is Boolean Sort.
  bool is_bool() const { return true; }

  // ------------------------- METHODS -------------------------------------- //
  /// Return the z3::sort of Boolean Sort.
  z3::sort GetZ3Sort(z3::context& ctx) const;
  /// Return a z3 variable of the Sort.
  z3::expr GetZ3Expr(z3::context& ctx, const std::string& name) const;
  /// Compare with another Sort.
  bool Equal(const SortPtr rhs) const;
  /// Print out to output stream.
  std::ostream& Print(std::ostream& out) const;
}; // class SortBool

/// \brief The class of bit-vector Sort.
class SortBv : public Sort {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  SortBv(const int& width);
  /// Default destructor.
  ~SortBv();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the unified ID of SortBv.
  AstUidSort uid() const { return AstUidSort::kBv; }
  /// Return true since it is bit-vector Sort.
  bool is_bv(const int& width) const {
    return (width == 0) ? true : (width == bit_width_);
  }

  // ------------------------- METHODS -------------------------------------- //
  /// Return the bit-width.
  int bit_width() const { return bit_width_; }
  /// Return the z3::sort of bit-vector.
  z3::sort GetZ3Sort(z3::context& ctx) const;
  /// Return a z3 variable of the Sort.
  z3::expr GetZ3Expr(z3::context& ctx, const std::string& name) const;
  /// Compare with another Sort.
  bool Equal(const SortPtr rhs) const;
  /// Print out to output stream.
  std::ostream& Print(std::ostream& out) const;

private:
  /// Bit-width of the bit-vector.
  int bit_width_;
}; // class SortBv

/// \brief The class of memory (array) Sort.
class SortMem : public Sort {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  SortMem(const int& addr_w, const int& data_w);
  /// Default destructor.
  ~SortMem();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the unified ID of SortMem.
  AstUidSort uid() const { return AstUidSort::kMem; }
  /// Return true since it is memory (array) Sort.
  bool is_mem() const { return true; }

  // ------------------------- METHODS -------------------------------------- //
  /// Return the bit-width of address (index).
  int addr_width() const { return addr_width_; }
  /// Return the bit-width of data (value).
  int data_width() const { return data_width_; }
  /// Return the z3::sort of array.
  z3::sort GetZ3Sort(z3::context& ctx) const;
  /// Return a z3 variable of the Sort.
  z3::expr GetZ3Expr(z3::context& ctx, const std::string& name) const;
  /// Compare with another Sort.
  bool Equal(const SortPtr rhs) const;
  /// Print out to output stream.
  std::ostream& Print(std::ostream& out) const;

private:
  /// Bit-width of the address.
  int addr_width_;
  /// Bit-width of the data.
  int data_width_;
}; // class SortMem

} // namespace ilang

#endif // ILANG_ILA_AST_SORT_H__
