/// \file
/// Unit test for invariant synthesis

#include <ilang/util/fs.h>
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/ilang++.h>
#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/vtarget-out/inv-syn/inv_syn_cegar.h>
#include <ilang/vtarget-out/inv-syn/sygus/sim_trace_extract.h>

#include "unit-include/config.h"
#include "unit-include/pipe_ila.h"
#include "unit-include/memswap.h"
#include "unit-include/util.h"


namespace ilang {


TEST(TestInvExtract, Abc) {

  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_extract/abc/";

  InvariantObject inv_obj;
  inv_obj.set_dut_inst_name("dut");

  inv_obj.AddInvariantFromAbcResultFile(
    dirName + "wrapper.blif",
    dirName + "ffmap.info",
    true,
    false,
    ""/*,dirName + "glamap.info"*/);

  EXPECT_EQ(inv_obj.GetVlgConstraints().size() , 1);
  std::cout << inv_obj.GetVlgConstraints().at(0) << std::endl;
}


}; // namespace ilang