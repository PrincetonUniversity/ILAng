/// \file
/// Header for the class Sort

#ifndef SORT_H__
#define SORT_H__

#include "ila/ast/ast.h"
#include "z3++.h"
#include <memory>
#include <ostream>
#include <vector>

/// \namespace ila
namespace ila {

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
  /// Return true since this is the Sort type under Ast domain.
  bool is_sort() const { return true; }

  /// Return true if have Boolean sort.
  virtual bool is_bool() const { return false; }
  /// Return true if have bit-vector sort.
  virtual bool is_bv() const { return false; }
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
  /// Return true since it is Boolean Sort.
  bool is_bool() const { return true; }

  // ------------------------- METHODS -------------------------------------- //
  /// Return the z3::sort of Boolean Sort.
  z3::sort GetZ3Sort(z3::context& ctx) const;
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
  /// Return true since it is bit-vector Sort.
  bool is_bv() const { return true; }
  /// Return the bit-width.
  int bit_width() const { return bit_width_; }
  /// Return the z3::sort of bit-vector.
  z3::sort GetZ3Sort(z3::context& ctx) const;
  /// Compare with another Sort.
  bool Equal(const SortPtr rhs) const;
  /// Print out to output stream.
  std::ostream& Print(std::ostream& out) const;

private:
  /// Bit-width of the bit-vector.
  int bit_width_;

}; // class SortBv

class SortMem : public Sort {
public:
  SortMem(const int& addr_w, const int& data_w);
  ~SortMem();

  bool is_mem() const { return true; }

  int addr_width() const { return addr_width_; }

  int data_width() const { return data_width_; }

  z3::sort GetZ3Sort(z3::context& ctx) const;

  bool Equal(const SortPtr rhs) const;

  std::ostream& Print(std::ostream& out) const;

private:
  int addr_width_;
  int data_width_;
}; // class SortMem

#if 0
/// \brief The class for sort (type for expr, and the range/domain of
/// functions).
class Sort {
private:
  SortBasePtr ptr_;

public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor for Boolean type.
  Sort() { ptr_ = std::make_shared<SortBool>(); }
  /// Constructor for Bitvector type.
  Sort(const int& bit_width) { ptr_ = std::make_shared<SortBv>(bit_width); }
  /// Constructor for Memory (Array) type.
  Sort(const int& addr_width, const int& data_width) {
    ptr_ = std::make_shared<SortMem>(addr_width, data_width);
  }
  /// Constructor for wrapping existed sort.
  Sort(SortBasePtr s) : ptr_(s) {}
  /// Default destructor.
  ~Sort() {}

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the bit width (bitvector).
  inline int bit_width() const { return ptr_->bit_width(); }
  /// Return the address width (mem).
  inline int addr_width() const { return ptr_->addr_width(); }
  /// Return the data width (mem).
  inline int data_width() const { return ptr_->data_width(); }

  /// Is type sort (object).
  inline bool is_sort() const { return ptr_->is_sort(); }

  /// Return true if this is a Boolean expression.
  inline bool is_bool() const { return ptr_->is_bool(); }
  /// Return true if this is a Bitvector expression.
  inline bool is_bv() const { return ptr_->is_bv(); }
  /// Return true if this is an Memory expression.
  inline bool is_mem() const { return ptr_->is_mem(); }

  // ------------------------- METHODS -------------------------------------- //
  /// Return z3 sort.
  inline z3::sort GetZ3Sort(z3::context& ctx) const {
    return ptr_->GetZ3Sort(ctx);
  }

  /// Output to stream.
  inline std::ostream& Print(std::ostream& out) const {
    return ptr_->Print(out);
  }

/// Compare two Sorts.
#if 0
  static bool Equal(const Sort& lhs, const Sort& rhs) {
    return SortBase::Equal(lhs.ptr_, rhs.ptr_);
  }
#endif

  /// Overload output stream operator.
  friend std::ostream& operator<<(std::ostream& out, const Sort& s) {
    return out << s.ptr_;
  }
  /// Overlaod comparison.
  friend bool operator==(const Sort& lhs, const Sort& rhs) {
    return lhs.ptr_ == rhs.ptr_;
  }

  /// Create Bool sort
  static SortPtr MakeBoolSort() {
    SortBasePtr s = std::make_shared<SortBool>();
    return s;
    // return Sort(s);
  }
  /// Create Bitvector sort.
  static SortPtr MakeBvSort(const int& bit_width) {
    SortBasePtr s = std::make_shared<SortBv>(bit_width);
    return s;
    // return Sort(s);
  }
  /// Create Memory sort.
  static SortPtr MakeMemSort(const int& addr_width, const int& data_width) {
    SortBasePtr s = std::make_shared<SortMem>(addr_width, data_width);
    return s;
    // return Sort(s);
  }

}; // class Sort

#endif

#if 0
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
  /// Return z3 sort.
  z3::sort GetZ3Sort(z3::context& ctx) const;

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
#endif

} // namespace ila

#endif // SORT_H__

