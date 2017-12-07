/// \file
/// The header for the class Node.

#ifndef __NODE_H__
#define __NODE_H__

#include <memory>
#include <string>

namespace ila {

/// \brief The class for the Node.
/// Node is the basic type for variables, expressions, functions, etc. It is
/// at the lowest level of the ast-based representation.
class Node {
public:
  /// The constructor for the class Node.
  Node();
  /// The destructor for the class Node.
  ~Node();

  // Type definitions.
  /****************************************************************************/

  // Node definition.
  /****************************************************************************/
  /// Set the name of the Node.
  /// \param[in] name Node name.
  void SetName(const std::string& name);

  /// Get the name of the Node.
  /// \return the name of the Node.
  const std::string& GetName() const;

private:
  /// The name of the Node.
  std::string name_;

}; // class Node

} // namespace ila

#endif // __NODE_H__

