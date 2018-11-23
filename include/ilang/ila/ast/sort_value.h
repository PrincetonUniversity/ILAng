/// \file
/// Header for the class BoolVal, BvVal, and MemVal

#ifndef SORT_VALUE_H__
#define SORT_VALUE_H__

#include <map>
#include <memory>
#include <ostream>
#include <string>

/// \namespace ila
namespace ila {

/// \brief The base type for constant value.
class Value {
public:
  /// virtual destructor.
  virtual ~Value() {}
  /// Pointer type for all use of Value.
  typedef std::shared_ptr<Value> ValPtr;

}; // class Value

/// Pointer type for all use of Value.
typedef Value::ValPtr ValPtr;

/// \brief The container for representing Boolean values.
class BoolVal : public Value {
public:
  /// Pointer type for all use of BoolVal.
  typedef std::shared_ptr<BoolVal> BoolValPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor with boolean value.
  BoolVal(const bool& val);
  /// Constructor with cpp string.
  BoolVal(const std::string& str);
  /// Constructor with c string.
  BoolVal(const char* cstr);
  /// Default destructor.
  ~BoolVal();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the string representation of the value.
  std::string str() const;
  /// Return the bool representation of the value.
  const bool& val() const;

  // ------------------------- METHODS -------------------------------------- //
  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;
  /// Overload output stream operator
  friend std::ostream& operator<<(std::ostream& out, const BoolVal& val);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Data container for the contant.
  bool val_;

}; // class BoolVal

/// Pointer type for all use of BoolVal.
typedef BoolVal::BoolValPtr BoolValPtr;

/// \brief The container for representing Bitvector values.
class BvVal : public Value {
public:
  /// Data type for storing BvVal
  typedef int BvValType;
  /// Pointer type for all use of BvVal.
  typedef std::shared_ptr<BvVal> BvValPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor with boolean value.
  BvVal(const int& val);
  /// Constructor with cpp string.
  BvVal(const std::string& str);
  /// Default destructor.
  ~BvVal();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the string representation of the value.
  std::string str() const;
  /// Return the arithmetic representation of the value.
  const int& val() const;

  // ------------------------- METHODS -------------------------------------- //
  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;
  /// Overload output stream operator
  friend std::ostream& operator<<(std::ostream& out, const BvVal& val);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Data container for the contant.
  BvValType val_;

}; // class BvVal

/// Data type for storing BvVal.
typedef BvVal::BvValType BvValType;
/// Pointer type for all use of BvVal.
typedef BvVal::BvValPtr BvValPtr;

/// \brief The container for representing memory (array) values.
class MemVal : public Value {
public:
  /// Pointer type for all use of MemVal.
  typedef std::shared_ptr<MemVal> MemValPtr;
  /// Type for storing the address/data mapping.
  typedef std::map<int, int> MemValMap;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor with only the default value.
  MemVal(const int& def_val);
  /// Constructor with an existed Memory value.
  MemVal(const int& def_val, const MemValMap& vals);
  /// Default destructor.
  ~MemVal();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the map of addr/data
  const MemValMap& val_map() const;
  /// Return the default value
  const int& def_val() const;

  /// Return the value stored in the address.
  const int& get_data(const int& addr) const;
  /// Set the value stored in the address.
  void set_data(const int& addr, const int& data);

  // ------------------------- METHODS ---------------------------------------//
  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;
  /// Overload output stream operator
  friend std::ostream& operator<<(std::ostream& out, const MemVal& val);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Mapping of the address/data.
  MemValMap val_map_;
  /// Default value of non-specified data.
  int default_;

}; // class MemVal

/// Pointer type for all use of MemVal.
typedef MemVal::MemValPtr MemValPtr;
/// Type for storing the address/data mapping.
typedef MemVal::MemValMap MemValMap;

} // namespace ila

#endif // SORT_VALUE_H__

