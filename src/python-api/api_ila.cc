/// \file
/// Source for Python API -- ILA

#include "ila/instr_lvl_abs.h"
#include "python-api/ila_py_api.h"

namespace ila {
using namespace boost::python;

void export_instr_lvl_abs() {
  class_<InstrLvlAbs, std::shared_ptr<InstrLvlAbs>>("ILA", init<>())
      .def("instr_num", &InstrLvlAbs::instr_num);
  //.staticmethod("create")
  //.def("hello", &A::hello);
}

} // namespace ila

