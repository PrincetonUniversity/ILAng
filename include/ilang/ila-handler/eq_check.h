/// \file
/// The header for checking the equivalence of two ILAs.

#ifndef ILANG_ILA_HANDLER_EQ_CHECK_H__
#define ILANG_ILA_HANDLER_EQ_CHECK_H__

#include <ilang/ilang++.h>

/// \namespace ilang
namespace ilang {

/// \brief Check if two ILAs have an exact same architecture, i.e., at the
/// highest level of hierarchy.
/// \param[in] a first ILA.
/// \param[in] b second ILA.
/// \param[in] update check update if true.
bool CheckEqSameArch(const Ila& a, const Ila& b, bool update = true);

/// \brief Check if two ILAs have an exact same micro-architecture. That is,
/// they have a same architecture at every level in the hierarchy.
/// \param[in] a first ILA.
/// \param[in] b second ILA.
/// \param[in] update check update if true.
bool CheckEqSameMicroArch(const Ila& a, const Ila& b, bool update = true);

}; // namespace ilang

#endif // ILANG_ILA_HANDLER_EQ_CHECK_H__
