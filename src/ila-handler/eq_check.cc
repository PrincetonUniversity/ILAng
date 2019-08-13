/// \file
/// The implementation for checking the equivalence of two ILAs.

#include <ilang/ila-handler/eq_check.h>

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/util/log.h>

namespace ilang {

bool CheckEqSameMicroArch(const Ila& a, const Ila& b, bool update) {
  auto ma = a.get();
  auto mb = b.get();

  ILA_NOT_NULL(ma);
  ILA_NOT_NULL(mb);

  if (ma->state_num() != mb->state_num()) {
    ILA_INFO << "#state mismatch";
    return false;
  }

  for (decltype(ma->state_num()) i = 0; i != ma->state_num(); i++) {
    // for (auto i = 0; i != ma->state_num(); i++) {
    //
  }

  if (ma->input_num() != mb->input_num()) {
    ILA_INFO << "#input mismatch";
    return false;
  }

  if (ma->instr_num() != mb->instr_num()) {
    ILA_INFO << "#instruction mismatch";
    return false;
  }

  if (ma->child_num() != mb->child_num()) {
    return false;
  }

  return true;
}

}; // namespace ilang

