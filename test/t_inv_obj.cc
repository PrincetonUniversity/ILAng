/// \file
/// Unit test for invariant object/cnf/cex/...

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/ilang++.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/vtarget-out/inv-syn/inv_syn_cegar.h>
#include <ilang/vtarget-out/vtarget_gen.h>

#include "unit-include/config.h"
#include "unit-include/memswap.h"
#include "unit-include/pipe_ila.h"
#include "unit-include/util.h"

namespace ilang {

#ifdef ILANG_BUILD_INVSYN

TEST(InvSynSupportAuxClass, CexObj) {
  auto dirName = os_portable_append_dir(
      ILANG_TEST_SRC_ROOT, std::vector<std::string>({"unit-data", "cex"}));
  auto vcdfile = os_portable_append_dir(dirName, "cex.vcd");
  auto cexfile = os_portable_append_dir(dirName, "cex.txt");

  CexExtractor cex(
      vcdfile, "m1", [](const std::string&) { return true; }, true);

  cex.DropStates({"m1.m1__DOT__out[3:0]"});
  cex.StoreCexToFile(cexfile);
  {
    CexExtractor cex(cexfile);
    EXPECT_TRUE(!IN("m1.m1__DOT__out[3:0]", cex.GetCex()));
  }
  os_portable_remove_file(cexfile);
}

TEST(InvSynSupportAuxClass, InvCnf) {
  auto dirName = os_portable_append_dir(
      ILANG_TEST_SRC_ROOT, std::vector<std::string>({"unit-data", "cex"}));
  auto cnffile = os_portable_append_dir(dirName, "cnf.txt");

  InvariantInCnf cnf;
  {
    std::ifstream fin(cnffile);
    EXPECT_TRUE(fin.is_open());
    cnf.ImportFromFile(fin);
    InvariantInCnf::clause cl({std::make_tuple(true, "m1.imp", 1U),
                               std::make_tuple(true, "m1.v", 1U)});
    cnf.InsertClauseNoReorder(cl);
    EXPECT_EQ(cnf.GetCnfs().size(), 2);
    fin.close();
  }
  {
    InvariantInCnf cnf2;
    std::ifstream fin(cnffile);
    EXPECT_TRUE(fin.is_open());
    cnf2.ImportFromFile(fin);
    cnf.InsertClauseIncremental(cnf2);
    EXPECT_EQ(cnf.GetCnfs().size(), 2);
    cnf2.Clear();
    EXPECT_EQ(cnf2.GetCnfs().size(), 0);
    fin.close();
  }
  {
    auto cocifile = os_portable_append_dir(dirName, "coci.txt");
    std::ofstream fout(cocifile);
    cnf.ExportInCociFormat(fout);
    fout.close();
    os_portable_remove_file(cocifile);
  }
  {
    auto cnfout = os_portable_append_dir(dirName, "cnfout.txt");
    std::ofstream fout(cnfout);
    cnf.ExportInCnfFormat(fout);
    fout.close();
    os_portable_remove_file(cnfout);
  }
}

#endif

}; // namespace ilang
