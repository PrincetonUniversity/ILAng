/// \file
/// Header for Python API -- top level for all tools

#ifndef ILA_PY_API_H__
#define ILA_PY_API_H__

#include <boost/python.hpp>

namespace ilang {
namespace pyapi {
using namespace boost::python;

void export_log();

void export_expr();

void export_instr();

void export_instr_lvl_abs();

} // namespace pyapi
} // namespace ilang

#endif // ILA_PY_API_H__
