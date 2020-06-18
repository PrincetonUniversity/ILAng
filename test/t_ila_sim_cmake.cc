#include <ilang/target-sc/ila_sim.h>

//#include <iostream>
//#include <sstream>
//#include <string>

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>

#include "unit-include/config.h"
#include "unit-include/ila_sim_test.h"
#include "unit-include/util.h"

namespace ilang {

class TestIlaSimCMake : public ::testing::Test {
public:
  TestIlaSimCMake() {}
  ~TestIlaSimCMake() {}

  void SetUp() {
    out_dir = GetRandomFileName(fs::temp_directory_path());
    os_portable_mkdir(out_dir);

    ilator.set_instr_lvl_abs(m.model.get());
    ilator.enable_cmake_support();
  }

  void TearDown() {
    // for CI tests, may be needed for out-of-scope build tests
    os_portable_remove_directory(out_dir);
  }

  IlaSimTest m;
  IlaSim ilator;
  fs::path out_dir;

  void SanityCheck() {
    // TODO config and build
    // - setup systemc lib in CI
    // - provide uninterpreted func impl. for all
    // - provide external memory for T**
  }

}; // TestIlaSimCmake

TEST_F(TestIlaSimCMake, FFF) {
  ilator.sim_gen(out_dir, false, false, false);
  SanityCheck();
}

TEST_F(TestIlaSimCMake, FFT) {
  ilator.sim_gen(out_dir, false, false, true);
  SanityCheck();
}

TEST_F(TestIlaSimCMake, FTF) {
  ilator.sim_gen(out_dir, false, true, false);
  SanityCheck();
}

TEST_F(TestIlaSimCMake, FTT) {
  ilator.sim_gen(out_dir, false, true, true);
  SanityCheck();
}

TEST_F(TestIlaSimCMake, TFF) {
  ilator.sim_gen(out_dir, true, false, false);
  SanityCheck();
}

TEST_F(TestIlaSimCMake, DISABLED_TFT) {
  ilator.sim_gen(out_dir, true, false, true);
  SanityCheck();
}

TEST_F(TestIlaSimCMake, TTF) {
  ilator.sim_gen(out_dir, true, true, false);
  SanityCheck();
}

TEST_F(TestIlaSimCMake, DISABLED_TTT) {
  ilator.sim_gen(out_dir, true, true, true);
  SanityCheck();
}

} // namespace ilang
