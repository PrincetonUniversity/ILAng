/// \file
/// Source for Python API -- ILA

#include "python-api/ila_py_api.h"
#include "python-api/wrap_ila.h"

namespace ila {
using namespace boost::python;

void export_instr_lvl_abs() {

  // Expose ILA wrapper to Boost.Python
  class_<InstrLvlAbsWrap>("Abstraction", init<std::string>())
      .def("inp", &InstrLvlAbsWrap::NewBvInput) // FIXME return instr
      .def("getinp", &InstrLvlAbsWrap::input,
           return_value_policy<manage_new_object>());
}

} // namespace ila

