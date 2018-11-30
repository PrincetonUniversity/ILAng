/// \file
/// Source for Python API -- ILA

#include <ilang/python-api/ila_py_api.h>
#include <ilang/python-api/wrap_ila.h>

namespace ilang {
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
} // namespace ilang
