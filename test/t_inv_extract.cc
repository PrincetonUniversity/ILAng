/// \file
/// Unit test for invariant synthesis

#include <ilang/util/fs.h>
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/ilang++.h>
#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/vtarget-out/inv-syn/inv_syn_cegar.h>

#include "unit-include/config.h"
#include "unit-include/pipe_ila.h"
#include "unit-include/memswap.h"
#include "unit-include/util.h"


namespace ilang {

#ifdef ILANG_BUILD_INVSYN

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

TEST(TestInvExtract, GrainInvExtract) {
  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_extract/grain/";
  auto smt_file = os_portable_append_dir(dirName, "__design_smt.smt2");
  
  bool flatten_datatype = true;
  bool flatten_hierarchy = true;

  InvariantObject inv_obj;
  inv_obj.set_dut_inst_name("m1");

  std::ifstream fin(smt_file);
  std::stringstream buffer;
  buffer << fin.rdbuf();
  {
    smt::YosysSmtParser design_info(buffer.str());

    auto inv_file = os_portable_append_dir(dirName, "smt-op-okay.result");
    inv_obj.AddInvariantFromGrainResultFile(
      design_info, // smt
      "" , // tag
      inv_file // result file
      );
    
    EXPECT_EQ(inv_obj.GetVlgConstraints().size() , 1);
    std::cout << inv_obj.GetVlgConstraints().at(0) << std::endl;
    EXPECT_TRUE(inv_obj.GetExtraFreeVarDefs().empty());
    EXPECT_EQ(inv_obj.GetExtraVarDefs().size() , 1);
    for (auto && vdef: inv_obj.GetExtraVarDefs()) {
      std::cout << std::get<0>(vdef) << std::endl << std::get<1>(vdef) << std::endl
        << std::get<2>(vdef) << std::endl;
    }
  }

  {
    smt::YosysSmtParser design_info(buffer.str());

    auto inv_file = os_portable_append_dir(dirName, "bvsrem.result");
    EXPECT_DEATH(inv_obj.AddInvariantFromGrainResultFile(
      design_info, // smt
      "" , // tag
      inv_file // result file
      ), ".*");
  }

  {
    smt::YosysSmtParser design_info(buffer.str());

    auto inv_file = os_portable_append_dir(dirName, "repeat.result");
    EXPECT_DEATH(inv_obj.AddInvariantFromGrainResultFile(
      design_info, // smt
      "" , // tag
      inv_file // result file
      ), ".*");
  }

  {
    smt::YosysSmtParser design_info(buffer.str());

    auto inv_file = os_portable_append_dir(dirName, "rotate_left.result");
    EXPECT_DEATH(inv_obj.AddInvariantFromGrainResultFile(
      design_info, // smt
      "" , // tag
      inv_file // result file
      ), ".*");
  }

  {
    smt::YosysSmtParser design_info(buffer.str());

    auto inv_file = os_portable_append_dir(dirName, "rotate_right.result");
    EXPECT_DEATH(inv_obj.AddInvariantFromGrainResultFile(
      design_info, // smt
      "" , // tag
      inv_file // result file
      ), ".*");
  }

  {
    smt::YosysSmtParser design_info(buffer.str());

    auto inv_file = os_portable_append_dir(dirName, "sign_extend.result");
    EXPECT_DEATH(inv_obj.AddInvariantFromGrainResultFile(
      design_info, // smt
      "" , // tag
      inv_file // result file
      ), ".*");
  }

  {
    smt::YosysSmtParser design_info(buffer.str());

    auto inv_file = os_portable_append_dir(dirName, "zero_extend.result");
    EXPECT_DEATH(inv_obj.AddInvariantFromGrainResultFile(
      design_info, // smt
      "" , // tag
      inv_file // result file
      ), ".*");
  }
}

// Current implementation does not support extract invariants
// from un-flattened hierarchy
#if 0
TEST(TestInvExtract, Z3InvExtract) {
  // prepare for ...
  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_extract/z3/";
  auto smt_file = os_portable_append_dir(dirName, "__design_smt.smt2");

  InvariantInCnf inv_cnf;
 
  bool flatten_datatype = true;
  bool flatten_hierarchy = false;

  InvariantObject inv_obj;
  inv_obj.set_dut_inst_name("m1");

  std::ifstream fin(smt_file);
  std::stringstream buffer;
  buffer << fin.rdbuf();
  {
    smt::YosysSmtParser design_info(buffer.str());

    auto inv_file = os_portable_append_dir(dirName, "__synthesis_result.txt");
    inv_obj.AddInvariantFromChcResultFile(
      design_info, // smt
      "" , // tag
      inv_file, // result file
      flatten_datatype,
      flatten_hierarchy
      );
    
    EXPECT_EQ(inv_obj.GetVlgConstraints().size() , 1);
    std::cout << inv_obj.GetVlgConstraints().at(0) << std::endl;
    EXPECT_TRUE(inv_obj.GetExtraFreeVarDefs().empty());
    EXPECT_TRUE(inv_obj.GetExtraVarDefs().empty());
  }
}
#endif

#endif

}; // namespace ilang