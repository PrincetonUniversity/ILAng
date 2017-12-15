/// \file
/// Header for the class BoolVal, BvVal, and MemVal

#ifndef __SORT_VALUE_H__
#define __SORT_VALUE_H__

#include <map>
#include <ostream>
#include <string>

/// \namespace ila
namespace ila {

/// \class BoolVal
/// The container for representing Boolean values.
class BoolVal {
public:
  BoolVal();

  /// Return the string representation of the value.
  std::string str() const;
  /// Return the c-string representation of the value.
  const char* c_str() const;

  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;
  /// Overload output stream operator
  friend std::ostream& operator<<(std::ostream& out, const BoolVal& val);

private:
  bool val_;
}; // class BoolVal

/// \class BvVal
/// The container for representing Bitvector values.
class BvVal {
public:
  BvVal();
  ~BvVal();

  /// Return the string representation of the value.
  std::string str() const;
  /// Return the c-string representation of the value.
  const char* c_str() const;

  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;
  /// Overload output stream operator
  friend std::ostream& operator<<(std::ostream& out, const BvVal& val);

private:
  unsigned long long val_;
}; // class BvVal

/// \class MemVal
/// The container for representing memory (array) values.
class MemVal {
public:
  MemVal();
  ~MemVal();

  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;
  /// Overload output stream operator
  friend std::ostream& operator<<(std::ostream& out, const MemVal& val);

private:
  std::map<BvVal, BvVal> map_;
  BvVal default_;
}; // class MemVal

} // namespace ila

#endif // __SORT_VALUE_H__

