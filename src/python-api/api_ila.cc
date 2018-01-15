/// \file
/// Source for Python API -- ILA

#include "ila/instr_lvl_abs.h"
#include "util/log.h"
#include <boost/python.hpp>

// namespace ila {

BOOST_PYTHON_MODULE(lib_ilapyd) {
  boost::python::def("SetLogLevel", ila::SetLogLevel);

#if 0
  boost::python::class_<InstrLvlAbs>("InstrLvlAbs")
      .def("Check", &InstrLvlAbs::Check)
      .add_property("input_num", &InstrLvlAbs::input_num);
#endif
}

//} // namespace ila

