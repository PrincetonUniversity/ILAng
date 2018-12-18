/// \file
/// Elevated interface for the portable manager and utilities.

#ifndef ILANG_PORTABLE_INTERFACE_H__
#define ILANG_PORTABLE_INTERFACE_H__

#include <ilang/ila/instr_lvl_abs.h>
#include <string>

/// \namespace ilang
namespace ilang {

/// \brief Export the ILA portable to a file.
/// \param[in] ila pointer to the ila model to be exported.
/// \param[in] file output file name.
/// \return export status.
bool ExportPortableToFile(const InstrLvlAbsPtr& ila, const std::string& file);

/// \brief Import the ILA model from the file.
/// \param[in] file input file name.
/// \return the generated ILA model.
InstrLvlAbsPtr ImportPortableFromFile(const std::string& file);

}; // namespace ilang

#endif // ILANG_PORTABLE_INTERFACE_H__

