/// \file
/// The header for the class Symbol.

#ifndef ILANG_ILA_SYMBOL_H__
#define ILANG_ILA_SYMBOL_H__

#include <fstream>
#include <ostream>
#include <string>

/// \namespace ilang
namespace ilang {

/// \brief The symbol is the name and ID of an object. Every object has an
/// unique symbol.
class Symbol {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor (empty name).
  Symbol();
  /// Constructor with cstring name.
  Symbol(const char* str);
  /// Constructor with string name.
  Symbol(const std::string& str);
  /// Copy constructor.
  Symbol(const Symbol& rhs);
  /// Default destructor.
  ~Symbol();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Get the name as basic string.
  const std::string& str() const;
  /// Get the name as c-type string.
  const char* c_str() const;
  /// Get the symbol as cpp string.
  const std::string format_str(const std::string& prefix = "",
                               const std::string& suffix = "") const;
  /// Convert the name to integer and return.
  int to_int() const;
  /// Get the id
  const size_t& id() const;

  /// Update the name (should not be initialized before).
  void set_name(const std::string& name);

  // ------------------------- METHODS -------------------------------------- //
  /// Output function
  std::ostream& Print(std::ostream& out) const;
  /// Overload output stream.
  friend std::ostream& operator<<(std::ostream& out, const Symbol& s);

  /// Overload assignment.
  Symbol& operator=(const Symbol& rhs);
  /// Overload comparison ==.
  friend bool operator==(const Symbol& lhs, const Symbol& rhs);
  /// Overload comparison <.
  friend bool operator<(const Symbol& lhs, const Symbol& rhs);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Name of the object.
  std::string name_;
  /// The unique ID of the object.
  size_t id_;
  /// Static counter for symbols IDs.
  static size_t counter_;

}; // class Symbol

} // namespace ilang

#endif // ILANG_ILA_SYMBOL_H__
