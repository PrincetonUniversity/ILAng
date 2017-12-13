/// \file
/// The header for the class Symbol.

#ifndef __SYMBOL_H__
#define __SYMBOL_H__

#include <fstream>
#include <ostream>
#include <string>

/// \namespace ila
namespace ila {

/// \class Symbol
/// The symbol (name) can be either int or string
class Symbol {
public:
  /// The default constructor for Symbol (with integer name).
  Symbol();
  /// The constructor for Symbol using string.
  Symbol(const std::string& str);
  /// The destructor for Symbol.
  ~Symbol();

  /// Generate integer version of the symbol.
  int ToInt() const;

  /// Generate string version of the symbol.
  const std::string& Str() const;

  /// Generate the hash
  int Hash() const;

  /// Overload assignment.
  Symbol& operator=(const Symbol& s);

  /// Overload comparison.
  friend bool operator==(const Symbol& lhs, const Symbol& rhs);

  /// Overload output stream.
  friend std::ostream& operator<<(std::ostream& out, const Symbol& s);
  // friend std::fstream& operator<<(std::fstream& out, const Symbol& s);

private:
  /// Data container.
  std::string data_;

  /// static counter for symbols.
  static unsigned counter_;

}; // class Symbol

} // namespace ila

#endif // __SYMBOL_H__

