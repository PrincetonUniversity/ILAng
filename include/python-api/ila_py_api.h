/// \file
/// Header for Python API -- top level for all tools

#ifndef __ILA_PY_API_H__
#define __ILA_PY_API_H__

#include <boost/python.hpp>

namespace ila {
using namespace boost::python;

void export_log();

void export_instr_lvl_abs();

} // namespace pyila

#endif // __ILA_PY_API_H__

