/// \file
/// The header for the class NodeRef.

#ifndef __NODE_REF_H__
#define __NODE_REF_H__

#include "ila/expr_fuse.h"

/// \namespace ila
namespace ila {

/// \brief NodeRef is wrapper for ExprRef without raw c-type pointers.
class NodeRef {
private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The actual pointer to expression.
  ExprPtr ptr_;

public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor. DO NOT USE.
  NodeRef();
  /// Constructor with data member (pointer to expression).
  NodeRef(const ExprPtr ptr);
  /// Copy constructor.
  NodeRef(const NodeRef& node);
  /// Default destructor.
  ~NodeRef();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Get the node name in basic string.
  const std::string& name() const;

  // ------------------------- METHODS -------------------------------------- //
  /// Overload assignment operator.
  NodeRef& operator=(const NodeRef& rhs);

private:
  // ------------------------- MEMBERS -------------------------------------- //

  // ------------------------- HELPERS -------------------------------------- //

}; // class NodeRef

} // namespace ila

#endif // __NODE_REF_H__

