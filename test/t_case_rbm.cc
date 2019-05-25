/// file
/// Unit test for the RBM case study.

#include "unit-include/config.h"
#include "unit-include/util.h"

#include <ilang/ilang++.h>
#include <ilang/util/fs.h>

namespace ilang {

TEST(TestCase, RBM_Import_Export_Import) {
  SetToStdErr(false);

  // get the abstraction
  auto data_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, "rbm");

  auto top_file = os_portable_append_dir(data_dir, "rbm.ila");
  auto compute_file = os_portable_append_dir(data_dir, "compute.ila");
  auto predict_file = os_portable_append_dir(data_dir, "predict.ila");
  auto train_file = os_portable_append_dir(data_dir, "train.ila");
  auto dmaload_file = os_portable_append_dir(data_dir, "DMAload.ila");
  auto store_file = os_portable_append_dir(data_dir, "store.ila");

  // parent
  auto rbm = ImportSynthAbstraction(top_file, "rbm");

  // parent --> compute
  ImportChildSynthAbstraction(compute_file, rbm, "compute");

  auto compute = rbm.child("compute");
  // parent --> compute --> predict
  ImportChildSynthAbstraction(predict_file, compute, "predict");
  // parent --> compute --> train
  ImportChildSynthAbstraction(train_file, compute, "train");

  // parent --> DMAload
  ImportChildSynthAbstraction(dmaload_file, rbm, "DMAload");
  // parent --> store
  ImportChildSynthAbstraction(store_file, rbm, "store");

  // export
  auto tmp_file_name = GetRandomFileName(NULL);
  ExportIlaPortable(rbm, tmp_file_name);

  // import
  auto read_back = ImportIlaPortable(tmp_file_name);

  EXPECT_EQ(read_back.state_num(), rbm.state_num());
  EXPECT_EQ(read_back.input_num(), rbm.input_num());
  EXPECT_EQ(read_back.instr_num(), rbm.instr_num());
  EXPECT_EQ(read_back.child_num(), rbm.child_num());

  SetToStdErr(false);
};

TEST(TestCase, RBM_Import) {
  SetToStdErr(false);

  // get the ILA model
  auto rbm_data_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, "rbm");
  auto rbm_portable = os_portable_append_dir(rbm_data_dir, "rbm.json");

  auto rbm_ila = ImportIlaPortable(rbm_portable);

  EXPECT_GT(rbm_ila.state_num(), 0);
  EXPECT_GT(rbm_ila.input_num(), 0);
  EXPECT_GT(rbm_ila.instr_num(), 0);
  EXPECT_GT(rbm_ila.child_num(), 0);
  SetToStdErr(false);
};

}; // namespace ilang
