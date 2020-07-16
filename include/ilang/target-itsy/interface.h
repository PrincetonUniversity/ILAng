/// \file
/// Elevated interface for the synthesis engine.

#ifndef ILANG_TARGET_ITSY_INTERFACE_H__
#define ILANG_TARGET_ITSY_INTERFACE_H__

#include <string>

#include <ilang/ila/instr_lvl_abs.h>

/// \namespace ilang
namespace ilang {

/// \brief Import from file the abstraction from the synthesis engine and
/// convert it into an ILA model.
/// \param[in] file_name file name of the abstraction from the synthesis engine.
/// \param[in] ila_name name of the created ILA model.
/// \return the generated ILA model.
InstrLvlAbsPtr ImportSynthAbsFromFile(const std::string& file_name,
                                      const std::string& ila_name = "");

/// \brief Import from file the abstraction from the synthesis engine and
/// convert it into a child-ILA of the specified parent ILA.
/// \param[in] file_name file name of the abstraction from the synthesis engine.
/// \param[in] parent pointer to the parent ILA.
/// \param[in] ila_name name of the created ILA model.
/// \return the generated ILA model.
InstrLvlAbsPtr ImportSynthAbsFromFileHier(const std::string& file_name,
                                          const InstrLvlAbsPtr& parent,
                                          const std::string& ila_name = "");

}; // namespace ilang

#endif // ILANG_TARGET_ITSY_INTERFACE_H__
