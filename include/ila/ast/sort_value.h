/// \file
/// Header for the class BoolVal, BvVal, and MemVal

#ifndef __SORT_VALUE_H__
#define __SORT_VALUE_H__

#include <map>
#include <memory>
#include <ostream>
#include <string>

/// \namespace ila
namespace ila {

/// \class BoolVal
/// The container for representing Boolean values.
class BoolVal {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor. DO NOT USE.
  BoolVal();
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

/// \def BoolValPtr
typedef std::shared_ptr<BoolVal> BoolValPtr;

/// \class BvVal
/// The container for representing Bitvector values.
class BvVal {
public:
  /// \def data type for storing BvVal
  typedef int BvValType;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor. DO NOT USE.
  BvVal();
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

/// \def BvValPtr
typedef std::shared_ptr<BvVal> BvValPtr;

/// \class MemVal
/// The container for representing memory (array) values.
class MemVal {
public:
  /// \def MemValMap
  typedef std::map<int, int> MemValMap;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor. DO NOT USE.
  MemVal();
  /// Constructor with only the default value.
  MemVal(const int& addr_width, const int& data_width, const int& def_val);
  /// Constructor with an existed Memory value.
  MemVal(const int& addr_width, const int& data_width, const int& def_val,
         const MemValMap& vals);
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
  /// Address width
  int addr_width_;
  /// Data width
  int data_width_;

}; // class MemVal

typedef MemVal::MemValMap MemValMap;
/// \def MemValPtr
typedef std::shared_ptr<MemVal> MemValPtr;

} // namespace ila

#endif // __SORT_VALUE_H__

