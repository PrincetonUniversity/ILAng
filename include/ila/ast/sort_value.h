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
  int val_;

}; // class BvVal

/// \def BvValPtr
typedef std::shared_ptr<BvVal> BvValPtr;

/// \class MemVal
/// The container for representing memory (array) values.
class MemVal {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor. DO NOT USE.
  MemVal();
  /// Default destructor.
  ~MemVal();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the map of addr/data
  const std::map<BvVal, BvVal>& val() const;
  /// Return the default value
  const BvVal& default_val() const;

  // ------------------------- METHODS -------------------------------------- //
  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;
  /// Overload output stream operator
  friend std::ostream& operator<<(std::ostream& out, const MemVal& val);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Mapping of the address/data.
  std::map<BvVal, BvVal> map_;
  /// Default value of non-specified data.
  BvVal default_;

}; // class MemVal

/// \def MemValPtr
typedef std::shared_ptr<MemVal> MemValPtr;

} // namespace ila

#endif // __SORT_VALUE_H__

