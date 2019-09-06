/// \file Source for Verilog Verification Targets Generation (single target)
/// the invariants (how they assume and assert)
/// the support for inv-syn (monolithic/cegar)
// --- Hongce Zhang


#include <ilang/ila/expr_fuse.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>

#include <cmath>
#include <fstream>
#include <iostream>

namespace ilang {

// ------------- CONFIGURATIONS -------------------- //

#define VLG_TRUE "`true"
#define VLG_FALSE "`false"

#define IntToStr(x) (std::to_string(x))



} // namespace ilang

