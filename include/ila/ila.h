/// \file
/// The header file for the class Ila.

#ifndef __ILA_H__
#define __ILA_H__

#include "ila/ast/ast.h"
#include <memory>
#include <string>

namespace ila {

/// \brief The class for the Instruction-Level Abstraction (ILA).
/// An Ila object should contain state variables, input varialbes, the valid
/// function, the fetch function, the set of instructions, and the set of
/// child-ILAs.
class Ila {
public:
  /// The constructor for the Ila.
  Ila();

  /// The constructor for the Ila (with name).
  Ila(std::string name);

  /// The destructor for the Ila.
  ~Ila();

  // ILA definition.
  /****************************************************************************/

  /// Set Ila name.
  /// \param[in] name ILA name.
  void SetName(const std::string& name);

  /// Get Ila name.
  /// \return the name of the Ila.
  const std::string& GetName() const;

protected:
  AstPtr valid_;

private:
  /// The name for the Ila.
  std::string name_;

}; // class Ila

/// \typedef Pointer type for Ila.
typedef std::shared_ptr<Ila> IlaPtr;

} // namespace ila

#endif // __ILA_H__

