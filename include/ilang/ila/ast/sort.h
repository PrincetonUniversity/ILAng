/// \file
/// Header for the class Sort

#ifndef ILANG_ILA_AST_SORT_H__
#define ILANG_ILA_AST_SORT_H__

#include <memory>
#include <ostream>
#include <utility>
#include <vector>

#include <z3++.h>

#include <ilang/ila/ast/ast.h>

/// \namespace ilang
namespace ilang {

/// Unified ID for Sort.
enum AstUidSort { kBool = 1, kBv, kMem, kStruct, kVec };

/// \brief The class for sort (type for expr, and the range/domain of
/// functions).
class Sort : public Ast {
public:
  /// Pointer type for storing/passing Sort.
  typedef std::shared_ptr<Sort> SortPtr;
  typedef std::vector<std::pair<std::string, SortPtr>> StructImpl;


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
  
  /// Create a Struct Sort, representing a composite data-type.
  static SortPtr MakeStructSort(
    std::initializer_list<std::pair<std::string, SortPtr>> members);
  
  /// Create a Struct Sort, representing a composite data-type.
  static SortPtr MakeStructSort(const std::vector<std::pair<std::string, SortPtr>>& members);
  
  /// Create Vector Sort; a sort for a vector of data_atoms with the given sort.
  static SortPtr MakeVectorSort(const SortPtr& data_atom, const int vec_size);


  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the unified ID of Sort.
  virtual AstUidSort uid() const = 0;
  /// Return true if have Boolean sort.
  virtual bool is_bool() const { return false; }
  /// Return true if have bit-vector sort.
  virtual bool is_bv(const int& width = 0) const { return false; }
  /// Return true if have memory (array) sort.
  virtual bool is_mem() const { return false; }
  /// Returns true if is the sort of a struct.
  virtual bool is_struct() const { return false; }
  /// Returns true if is the sort of a vector of multiple instances
  /// of some data-atom.
  virtual bool is_vec() const { return false; }
  /// Returns true if is the sort of a vector of multiple instances 
  /// of a given data-atom.
  virtual bool is_vec(const SortPtr& data_atom) const { return false; }

  /// Return the bit-width of bit-vector sort.
  virtual int bit_width() const;
  /// Return the bit-width of the address (index).
  virtual int addr_width() const;
  /// Return the bit-width of the data (value).
  virtual int data_width() const;

  // Returns the sort of a member of a struct sort, or nullptr if not found.
  virtual const SortPtr get_member_sort(const std::string& name) const;
  // Gives access to the underlying list of (name, sort) pairs of a struct sort.
  virtual const StructImpl members() const;

  /// Returns the data-atom describing an element of a vector sort, or nullptr.
  virtual SortPtr data_atom() const;
  /// Returns the number of elements in a given vector sort.
  virtual int vec_size() const;

  // ------------------------- METHODS -------------------------------------- //
  /// Return z3::sort of the Sort.
  virtual z3::sort GetZ3Sort(z3::context& ctx) const = 0;
  /// Return a z3 variable of the Sort.
  virtual z3::expr GetZ3Expr(z3::context& ctx,
                             const std::string& name) const = 0;

  /// Compare two Sorts.
  virtual bool Equal(const SortPtr rhs) const = 0;
  /// Overload comparison.
  friend bool operator==(const SortPtr lhs, const SortPtr rhs) {
    return lhs->Equal(rhs);
  }

  /// Print out to output stream.
  virtual std::ostream& Print(std::ostream& out) const = 0;
  /// Overload output stream operator.
  friend std::ostream& operator<<(std::ostream& out, const SortPtr s) {
    return s->Print(out);
  }

  // /// Casts a SortPtr to a pointer to a subtype of Sort.
  // /// Use cautiously.
  // template<typename T> 
  // static std::shared_ptr<T> cast_sort(const SortPtr& s) {
  //   return std::dynamic_pointer_cast<T>(s);
  // }

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

/// \brief A class for defining a composite sort
class SortStruct : public Sort {

public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructs a StructSort from a list of members. 
  SortStruct(std::initializer_list<std::pair<std::string, SortPtr>> members);
  SortStruct(const std::vector<std::pair<std::string, SortPtr>>& members);
  /* Note: we create a struct all at once to prevent any weirdness from recursive 
     sorts. (I.e. we don't want to be able to create a StructSort, and then add
     itself as a member.) */

  /// Default destructor.
  ~SortStruct()=default;

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the unified ID of SortStruct.
  AstUidSort uid() const { return AstUidSort::kStruct; }
  /// Returns true, since this is a SortStruct.
  bool is_struct() const { return true; }

  // Returns the sort of a member of this struct, or nullptr if not found.
  const SortPtr get_member_sort(const std::string& name) const;
  // Gives access to the underlying list of (name, sort) pairs of a struct sort.
  const StructImpl members() const { return members_; }

  // ------------------------- METHODS -------------------------------------- //  
  /// Return the z3::sort of a SortStruct.
  z3::sort GetZ3Sort(z3::context& ctx) const;
  /// Return a z3 variable of the Sort.
  z3::expr GetZ3Expr(z3::context& ctx, const std::string& name) const;
  /// Compare with another Sort.
  bool Equal(const SortPtr rhs) const;
  /// Print out to output stream.
  std::ostream& Print(std::ostream& out) const;

private:
  const StructImpl members_;
  const Symbol id_ {};
};

/// \brief A class for defining vectors of data-atoms.
class SortVector : public Sort {

public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Creates a sort representing a vector having the given number of the
  /// given type of data-atom.
  SortVector(const SortPtr& data_atom, const int& vec_size);
  /// Default destructor.
  ~SortVector()=default;

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the unified ID of SortVector.
  AstUidSort uid() const { return AstUidSort::kVec; }
  /// Returns true if is a vector of data-atoms.
  bool is_vec() const { return true; }

  /// Returns the data-atom describing each element of the vector.
  SortPtr data_atom() const { return da_; }
  /// Returns the size of the vector of data-atoms.
  int vec_size() const { return size_; }
  // ------------------------- METHODS -------------------------------------- //
  /// Return the z3::sort of Vector Sort.
  z3::sort GetZ3Sort(z3::context& ctx) const;
  /// Return a z3 variable of the Sort.
  z3::expr GetZ3Expr(z3::context& ctx, const std::string& name) const;
  /// Compare with another Sort.
  bool Equal(const SortPtr rhs) const;
  /// Print out to output stream.
  std::ostream& Print(std::ostream& out) const;
private:
  SortPtr da_;
  int size_;  // the number of data-atoms in the vector
  const Symbol id_ {};
};

} // namespace ilang

#endif // ILANG_ILA_AST_SORT_H__