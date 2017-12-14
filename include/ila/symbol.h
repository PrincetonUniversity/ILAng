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
/// The symbol is the name of an object. If not specified, it will be generated
/// from an internal coutner by default.
class Symbol {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor (integer by default).
  Symbol();
  /// Constructor with cstring name.
  Symbol(const char* str);
  /// Constructor with string name.
  Symbol(const std::string& str);
  /// Default destructor.
  ~Symbol();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Get the symbol as cpp string.
  const std::string& str() const;
  /// Get the symbol as c string.
  const char* c_str() const;
  /// Get the symbol as integer.
  int to_int() const;

  // ------------------------- METHODS -------------------------------------- //
  /// Generate the hash
  int Hash() const;
  /// Output function
  std::ostream& Print(std::ostream& out) const;

  /// Overload assignment.
  Symbol& operator=(const Symbol& rhs);
  /// Overload comparison.
  friend bool operator==(const Symbol& lhs, const Symbol& rhs);
  /// Overload output stream.
  friend std::ostream& operator<<(std::ostream& out, const Symbol& s);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Data container.
  std::string data_;
  /// Static counter for symbols.
  static unsigned counter_;

  // ------------------------- HELPERS -------------------------------------- //

}; // class Symbol

} // namespace ila

#endif // __SYMBOL_H__

