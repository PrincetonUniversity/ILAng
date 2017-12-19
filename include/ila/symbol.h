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
/// The symbol is the name and ID of an object. Every object has an unique
/// symbol.
class Symbol {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor (empty name).
  Symbol();
#if 0
  /// Copy constructor.
  Symbol(const Symbol& sym);
#endif
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
  /// Get the id
  const size_t& id() const;

  /// Set the name.
  bool set_name(const std::string& name);

  // ------------------------- METHODS -------------------------------------- //
  /// Output function
  std::ostream& Print(std::ostream& out) const;
  /// Overload output stream.
  friend std::ostream& operator<<(std::ostream& out, const Symbol& s);

  /// Overload assignment.
  Symbol& operator=(const Symbol& rhs);
  /// Overload comparison.
  friend bool operator==(const Symbol& lhs, const Symbol& rhs);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Name of the object.
  std::string name_;
  /// The unique ID of the object.
  size_t id_;
  /// Static counter for symbols IDs.
  static size_t counter_;

  // ------------------------- HELPERS -------------------------------------- //

}; // class Symbol

} // namespace ila

#endif // __SYMBOL_H__

