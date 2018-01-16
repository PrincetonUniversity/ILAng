/// \file
/// Source for Python API -- top level for all tools

#include "python-api/ila_py_api.h"

namespace ila {
using namespace boost::python;

BOOST_PYTHON_MODULE(ila) {
  export_log();
  export_instr_lvl_abs();
}

} // namespace ila

