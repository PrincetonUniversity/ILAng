/// \file
/// Source for Python API -- Expr

#include "python-api/ila_py_api.h"
#include "python-api/wrap_expr.h"

namespace ila {
namespace pyapi {

void export_expr() {

  class_<ExprWrap>("Expr", init<>())
      .add_property("name", &ExprWrap::Name)
      // unary operators
      .def("__invert__", &ExprWrap::Complement,
           return_value_policy<manage_new_object>())
      .def("__neg__", &ExprWrap::Negate,
           return_value_policy<manage_new_object>())
      .def("__and__", &ExprWrap::And, return_value_policy<manage_new_object>())
      // TODO operator override
      ;

  def("load", &ExprWrap::Load, return_value_policy<manage_new_object>());
  // TODO static functions
}

} // namespace pyapi
} // namespace ila

