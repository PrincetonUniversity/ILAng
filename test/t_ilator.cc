/// \file
/// Test for Ilator

#include <ilang/ilang++.h>

#include <ilang/util/fs.h>
#include <ilang/util/log.h>

#include "unit-include/config.h"
#include "unit-include/ila_sim_test.h"
#include "unit-include/util.h"

namespace ilang {

class TestIlator : public ::testing::Test {
public:
  TestIlator() {}
  ~TestIlator() {}

  void SetUp() {
    out_dir = GetRandomFileName(fs::temp_directory_path());
    os_portable_mkdir(out_dir);
  }

  void TearDown() {
    // for CI tests, may be needed for out-of-scope build tests
    os_portable_remove_directory(out_dir);
  }

  fs::path out_dir;

}; // TestIlator

TEST_F(TestIlator, Default) {
  IlaSimTest m;
  ExportSysCSim(m.model, out_dir);
}

TEST_F(TestIlator, Optimize) {
  IlaSimTest m;
  ExportSysCSim(m.model, out_dir, true);
}

} // namespace ilang
