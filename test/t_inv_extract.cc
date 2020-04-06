/// \file
/// Unit test for invariant extract

#include <ilang/util/fs.h>
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/ilang++.h>
#include <ilang/smt-inout/chc_inv_in_wrapper.h>
#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/vtarget-out/inv-syn/inv_syn_cegar.h>

#include "unit-include/config.h"
#include "unit-include/pipe_ila.h"
#include "unit-include/memswap.h"
#include "unit-include/util.h"


namespace ilang {

#ifdef ILANG_BUILD_INVSYN

TEST(TestInvExtract, Abc) {

  auto dirName = 
    os_portable_append_dir(ILANG_TEST_SRC_ROOT, {"unit-data", "inv_extract", "abc"});

  InvariantObject inv_obj;
  InvariantInCnf inv_cnf;
  inv_obj.set_dut_inst_name("m1");

  inv_obj.AddInvariantFromAbcResultFile(
    os_portable_append_dir( dirName , "wrapper.blif"),
    os_portable_append_dir( dirName , "ffmap.info"),
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


TEST(TestInvExtract, PipeBlifGla) {

  auto dirName = 
    os_portable_append_dir(ILANG_TEST_SRC_ROOT, {"unit-data", "inv_extract", "pipe", "blif-gla"});

  InvariantObject inv_obj;
  InvariantInCnf inv_cnf;
  inv_obj.set_dut_inst_name("m1");

  inv_obj.AddInvariantFromAbcResultFile(
    os_portable_append_dir( dirName , "wrapper.blif"),
    os_portable_append_dir( dirName , "ffmap.info"),
    true,
    false,
    os_portable_append_dir( dirName , "glamap.info"), /*,dirName + "glamap.info"*/
    false, // use aiger, if false, the following has no use
    "",
    inv_cnf,
    InvariantInCnf());

  EXPECT_EQ(inv_obj.GetVlgConstraints().size() , 1);
  std::cout << inv_obj.GetVlgConstraints().at(0) << std::endl;
}



TEST(TestInvExtract, AbcAiger) {
  auto dirName = 
    os_portable_append_dir(ILANG_TEST_SRC_ROOT, {"unit-data", "inv_extract", "abc-aig"});

  InvariantObject inv_obj;
  InvariantInCnf inv_cnf;
  inv_obj.set_dut_inst_name("m1");

  inv_obj.AddInvariantFromAbcResultFile(
    os_portable_append_dir( dirName ,  "__aiger_prepare.blif"),
    os_portable_append_dir( dirName ,  "ffmap.info"),
    true,
    false,
    "",/*,dirName + "glamap.info"*/
    true, // use aiger, if false, the following has no use
    os_portable_append_dir( dirName , "wrapper.aig.map"),
    inv_cnf,
    InvariantInCnf());

  EXPECT_EQ(inv_obj.GetVlgConstraints().size() , 1);
  std::cout << inv_obj.GetVlgConstraints().at(0) << std::endl;
}


TEST(TestInvExtract, AbcAigerGLA) {
  auto dirName = 
    os_portable_append_dir(ILANG_TEST_SRC_ROOT, {"unit-data", "inv_extract", "abc-aig-gla"});

  InvariantObject inv_obj;
  InvariantInCnf inv_cnf;
  inv_obj.set_dut_inst_name("m1");

  inv_obj.AddInvariantFromAbcResultFile(
    os_portable_append_dir( dirName , "__aiger_prepare.blif"),
    os_portable_append_dir( dirName , "ffmap.info"),
    true,
    false,
    os_portable_append_dir( dirName , "glamap.info"), /*,dirName + "glamap.info"*/
    true, // use aiger, if false, the following has no use
    os_portable_append_dir( dirName , "wrapper.aig.map"),
    inv_cnf,
    InvariantInCnf());

  EXPECT_EQ(inv_obj.GetVlgConstraints().size() , 1);
  std::cout << inv_obj.GetVlgConstraints().at(0) << std::endl;
}


TEST(TestInvExtract, PipeAigerGLA) {
  auto dirName = 
    os_portable_append_dir(ILANG_TEST_SRC_ROOT, {"unit-data", "inv_extract", "pipe", "aiger-gla"});

  InvariantObject inv_obj;
  InvariantInCnf inv_cnf;
  inv_obj.set_dut_inst_name("m1");

  inv_obj.AddInvariantFromAbcResultFile(
    os_portable_append_dir( dirName , "__aiger_prepare.blif"),
    os_portable_append_dir( dirName , "ffmap.info"),
    true,
    false,
    os_portable_append_dir( dirName , "glamap.info"), /*,dirName + "glamap.info"*/
    true, // use aiger, if false, the following has no use
    os_portable_append_dir( dirName , "wrapper.aig.map"),
    inv_cnf,
    InvariantInCnf());

  EXPECT_EQ(inv_obj.GetVlgConstraints().size() , 1);
  std::cout << inv_obj.GetVlgConstraints().at(0) << std::endl;
}

TEST(TestInvExtract, GrainInvExtract) {
  auto dirName = 
    os_portable_append_dir(ILANG_TEST_SRC_ROOT, {"unit-data", "inv_extract", "grain"});
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

  {
    smt::YosysSmtParser design_info(buffer.str());

    auto inv_file = os_portable_append_dir(dirName, "outside_var.result");
    inv_obj.AddInvariantFromGrainResultFile(
      design_info, // smt
      "" , // tag
      inv_file // result file
      ), ".*";
  }
}

// Current implementation does not support extract invariants
// from un-flattened hierarchy
TEST(TestInvExtract, Z3InvExtract) {
  // prepare for ...
  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_extract/z3/";
  auto smt_file = os_portable_append_dir(dirName, "__design_smt.smt2");

  InvariantInCnf inv_cnf;
 
  bool flatten_datatype = false;
  bool flatten_hierarchy = true;

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


TEST(TestInvExtract, Z3InvExtractPipe) {
  // prepare for ...
  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_extract/pipe/z3/";
  auto smt_file = os_portable_append_dir(dirName, "__design_smt.smt2");

  InvariantInCnf inv_cnf;
 
  bool flatten_datatype = false;
  bool flatten_hierarchy = true;

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

// Test whether it is able to handle [][] in the description
TEST(TestInvExtract, Z3InvExtractRangeSpec) {
  // prepare for ...
  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_extract/z3-range/";
  auto smt_file = os_portable_append_dir(dirName, "__design_smt.smt2");
 
  bool flatten_datatype = false;
  bool flatten_hierarchy = true;

  std::ifstream fin(smt_file);
  std::stringstream buffer;
  buffer << fin.rdbuf();
  {
    smt::YosysSmtParser design_info(buffer.str());

    auto inv_file = os_portable_append_dir(dirName, "__synthesis_result.txt");

    InvariantObject inv_obj;
    inv_obj.set_dut_inst_name("m1");
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
    EXPECT_FALSE(inv_obj.GetExtraVarDefs().empty());
    for (auto && var_expr_width : inv_obj.GetExtraVarDefs()) {
      std::cout << "DEF: " << std::get<0>(var_expr_width) << " (width=" << std::get<2>(var_expr_width)
        <<") := " << std::get<1>(var_expr_width) << std::endl;
    }
    EXPECT_TRUE(smt::SmtlibInvariantParserBase::get_local_ctr() >= 2);
    inv_obj.ExportToFile(os_portable_append_dir(dirName, "inv.txt"));
  }
  unsigned ctr_old = smt::SmtlibInvariantParserBase::get_local_ctr();
  {
    InvariantObject inv_obj2;
    inv_obj2.set_dut_inst_name("m1");
    inv_obj2.ImportFromFile(os_portable_append_dir(dirName, "inv.txt"));
    unsigned ctr_new = smt::SmtlibInvariantParserBase::get_local_ctr();
    EXPECT_EQ(ctr_old, ctr_new);

    smt::YosysSmtParser design_info(buffer.str());

    auto inv_file = os_portable_append_dir(dirName, "__synthesis_result.txt");

    inv_obj2.AddInvariantFromChcResultFile(
      design_info, // smt
      "" , // tag
      inv_file, // result file
      flatten_datatype,
      flatten_hierarchy
      );
    
    EXPECT_EQ(inv_obj2.GetVlgConstraints().size() , 2);
    std::cout << inv_obj2.GetVlgConstraints().at(0) << std::endl;
    std::cout << inv_obj2.GetVlgConstraints().at(1) << std::endl;
    EXPECT_TRUE(inv_obj2.GetExtraFreeVarDefs().empty());
    EXPECT_FALSE(inv_obj2.GetExtraVarDefs().empty());
    for (auto && var_expr_width : inv_obj2.GetExtraVarDefs()) {
      std::cout << "DEF: " << std::get<0>(var_expr_width) << " (width=" << std::get<2>(var_expr_width)
        <<") := " << std::get<1>(var_expr_width) << std::endl;
    }
    EXPECT_TRUE(smt::SmtlibInvariantParserBase::get_local_ctr() >= 4);
    inv_obj2.ExportToFile(os_portable_append_dir(dirName, "inv.txt"));
  }
} // Z3InvExtractRangeSpec


// Parsing back chc invariant is not ready yet
// You may want to partially flatten. Done in
// Yosys scripts, and then when parse back the
// invariant, you only need to handle one-level
// of hierarchy.
#if 0
// Test whether it is able to handle [][] in the description
TEST(TestInvExtract, Z3RelChcExtract) {

  // prepare for ...
  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/inv_extract/relchc";
  auto smt_file = os_portable_append_dir(dirName, "__design_smt.smt2");
 
  bool flatten_datatype = false;
  bool flatten_hierarchy = false;

  std::ifstream fin(smt_file);
  std::stringstream buffer;
  buffer << fin.rdbuf();
  {
    smt::YosysSmtParser design_info(buffer.str());

    auto inv_file = os_portable_append_dir(dirName, "result.txt");

    InvariantObject inv_obj;
    inv_obj.set_dut_inst_name("m1");
    inv_obj.AddInvariantFromChcResultFile(
      design_info, // smt
      "" , // tag
      inv_file, // result file
      flatten_datatype,
      flatten_hierarchy
      );

    for (auto && inv : inv_obj.GetVlgConstraints()) {
      std::cout << inv << std::endl;
    }  
  } // read inv
} // Z3RelChcExtract
#endif

#endif

}; // namespace ilang