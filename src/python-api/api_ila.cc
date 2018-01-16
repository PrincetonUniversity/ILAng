/// \file
/// Source for Python API -- ILA

#include "ila/instr_lvl_abs.h"
#include "python-api/ila_py_api.h"
#include "python-api/wrap_ila.h"

namespace ila {
using namespace boost::python;

void export_instr_lvl_abs() {

  // TODO use wrapper

  class_<WrapInstrLvlAbs>("ILA", init<std::string>())
      .def("inp", &WrapInstrLvlAbs::NewBvInput,
           return_value_policy<manage_new_object>())
      .def("getinp", &WrapInstrLvlAbs::input,
           return_value_policy<manage_new_object>());

#if 0
  class_<InstrLvlAbs, std::shared_ptr<InstrLvlAbs>>("ILA", init<std::string>())
      // .def_readonly("name", &InstrLvlAbs::name().str())
      .def("inp", &InstrLvlAbs::AddInput,
           return_value_policy<manage_new_object>())
      //.def("getinp", &InstrLvlAbs::input_str,
      // return_value_policy<manage_new_object>())

      .def("instr_num", &InstrLvlAbs::instr_num)
      .staticmethod("New");
#endif
}

} // namespace ila

