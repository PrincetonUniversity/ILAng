/// \file
/// Source for Python API -- ILA

#include "python-api/ila_py_api.h"
#include "python-api/wrap_ila.h"

namespace ila {
namespace pyapi {

void export_instr_lvl_abs() {

  // Expose ILA wrapper to Boost.Python
  class_<InstrLvlAbsWrap>("Abstraction", init<std::string>())
      .def("inp", &InstrLvlAbsWrap::NewBvInput,
           return_value_policy<manage_new_object>())
      .def("getinp", &InstrLvlAbsWrap::input,
           return_value_policy<manage_new_object>())
      // TODO
      ;
}

} // namespace pyapi
} // namespace ila

