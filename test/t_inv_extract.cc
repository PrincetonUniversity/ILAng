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
  InvariantInCnf inv_cnf;
  inv_obj.set_dut_inst_name("m1");

  inv_obj.AddInvariantFromAbcResultFile(
    dirName + "wrapper.blif",
    dirName + "ffmap.info",
    true,
    false,
    "",/*,dirName + "glamap.info"*/
    false, // use aiger, if false, the following has no use
    "",
    inv_cnf,
    InvariantInCnf());

  EXPECT_EQ(inv_obj.GetVlgConstraints().size() , 1);
  std::cout << inv_obj.GetVlgConstraints().at(0) << std::endl;
}


TEST(TestInvExtract, AbcAiger) {
  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_extract/abc-aig/";

  InvariantObject inv_obj;
  InvariantInCnf inv_cnf;
  inv_obj.set_dut_inst_name("m1");

  inv_obj.AddInvariantFromAbcResultFile(
    dirName + "__aiger_prepare.blif",
    dirName + "ffmap.info",
    true,
    false,
    "",/*,dirName + "glamap.info"*/
    true, // use aiger, if false, the following has no use
    dirName + "wrapper.aig.map",
    inv_cnf,
    InvariantInCnf());

  EXPECT_EQ(inv_obj.GetVlgConstraints().size() , 1);
  std::cout << inv_obj.GetVlgConstraints().at(0) << std::endl;
}


TEST(TestInvExtract, AbcAigerGLA) {
  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_extract/abc-aig-gla/";

  InvariantObject inv_obj;
  InvariantInCnf inv_cnf;
  inv_obj.set_dut_inst_name("m1");

  inv_obj.AddInvariantFromAbcResultFile(
    dirName + "__aiger_prepare.blif",
    dirName + "ffmap.info",
    true,
    false,
    dirName + "glamap.info", /*,dirName + "glamap.info"*/
    true, // use aiger, if false, the following has no use
    dirName + "wrapper.aig.map",
    inv_cnf,
    InvariantInCnf());

  EXPECT_EQ(inv_obj.GetVlgConstraints().size() , 1);
  std::cout << inv_obj.GetVlgConstraints().at(0) << std::endl;
}

}; // namespace ilang