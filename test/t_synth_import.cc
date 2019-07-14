/// \file
/// Unit tests for importing ILA from the synthesis engine

#include <ilang/ilang++.h>
#include <ilang/util/fs.h>

#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

class TestSynthImport : public ::testing::Test {
public:
  TestSynthImport() {}
  ~TestSynthImport() {}
  void SetUp() {
    // SetToStdErr(1);
    // DebugLog::Enable("SynthImport");
  }
  void TearDown() {
    DebugLog::Disable("SynthImport");
    // SetToStdErr(0);
  }

  const std::string dir_aes =
      os_portable_append_dir(ILANG_TEST_DATA_DIR, "aes");
  const std::string dir_rbm =
      os_portable_append_dir(ILANG_TEST_DATA_DIR, "rbm");
  const std::string dir_gb = os_portable_append_dir(ILANG_TEST_DATA_DIR, "gb");
  const std::string dir_oc = os_portable_append_dir(ILANG_TEST_DATA_DIR, "oc");

}; // class TestSynthImport

TEST_F(TestSynthImport, AES_V_top) {
  auto abst_file = os_portable_append_dir(dir_aes, "aes_v_top.abst");
  auto json_file = os_portable_append_dir(dir_aes, "aes_v_top.json");

  auto top_abst = ImportSynthAbstraction(abst_file, "top");
  auto top = ImportIlaPortable(json_file);

  CheckIlaEqLegacy(top_abst.get(), top.get());
}

TEST_F(TestSynthImport, AES_V_child) {
  auto abst_file = os_portable_append_dir(dir_aes, "aes_v_child.abst");
  auto json_file = os_portable_append_dir(dir_aes, "aes_v_child.json");

  auto child_abst = ImportSynthAbstraction(abst_file, "child");
  auto child = ImportIlaPortable(json_file);

  CheckIlaEqLegacy(child_abst.get(), child.get());
}

TEST_F(TestSynthImport, AES_V) {
  auto top_abst_file = os_portable_append_dir(dir_aes, "aes_v_top.abst");
  auto child_abst_file = os_portable_append_dir(dir_aes, "aes_v_child.abst");

  auto aes_abst = ImportSynthAbstraction(top_abst_file, "top");
  ImportChildSynthAbstraction(child_abst_file, aes_abst, "child");

  auto json_file = os_portable_append_dir(dir_aes, "aes_v.json");
  auto aes = ImportIlaPortable(json_file);

  CheckIlaEqLegacy(aes_abst.get(), aes.get());
}

TEST_F(TestSynthImport, AES_C_top) {
  auto abst_file = os_portable_append_dir(dir_aes, "aes_c_top.abst");
  auto json_file = os_portable_append_dir(dir_aes, "aes_c_top.json");

  auto top_abst = ImportSynthAbstraction(abst_file, "top");
  auto top = ImportIlaPortable(json_file);

  CheckIlaEqLegacy(top_abst.get(), top.get());
}

TEST_F(TestSynthImport, AES_C_child) {
  auto abst_file = os_portable_append_dir(dir_aes, "aes_c_child.abst");
  auto json_file = os_portable_append_dir(dir_aes, "aes_c_child.json");

  auto child_abst = ImportSynthAbstraction(abst_file, "child");
  auto child = ImportIlaPortable(json_file);

  CheckIlaEqLegacy(child_abst.get(), child.get());
}

TEST_F(TestSynthImport, AES_C) {
  auto top_abst_file = os_portable_append_dir(dir_aes, "aes_c_top.abst");
  auto child_abst_file = os_portable_append_dir(dir_aes, "aes_c_child.abst");

  auto aes_abst = ImportSynthAbstraction(top_abst_file, "top");
  ImportChildSynthAbstraction(child_abst_file, aes_abst, "child");

  auto json_file = os_portable_append_dir(dir_aes, "aes_c.json");
  auto aes = ImportIlaPortable(json_file);

  CheckIlaEqLegacy(aes_abst.get(), aes.get());
}

TEST_F(TestSynthImport, GB_low_top) {
  auto abst_file = os_portable_append_dir(dir_gb, "gb_low_top.abst");
  auto json_file = os_portable_append_dir(dir_gb, "gb_low_top.json");

  auto top_abst = ImportSynthAbstraction(abst_file, "top");
  auto top = ImportIlaPortable(json_file);

  CheckIlaEqLegacy(top_abst.get(), top.get());
}

TEST_F(TestSynthImport, GB_low_child) {
  auto abst_file = os_portable_append_dir(dir_gb, "gb_low_child.abst");
  auto json_file = os_portable_append_dir(dir_gb, "gb_low_child.json");

  auto child_abst = ImportSynthAbstraction(abst_file, "child");
  auto child = ImportIlaPortable(json_file);

  CheckIlaEqLegacy(child_abst.get(), child.get());
}

TEST_F(TestSynthImport, GB_low) {
  auto top_abst_file = os_portable_append_dir(dir_gb, "gb_low_top.abst");
  auto child_abst_file = os_portable_append_dir(dir_gb, "gb_low_child.abst");

  auto gb_abst = ImportSynthAbstraction(top_abst_file, "top");
  ImportChildSynthAbstraction(child_abst_file, gb_abst, "child");

  auto json_file = os_portable_append_dir(dir_gb, "gb_low.json");
  auto gb = ImportIlaPortable(json_file);

  CheckIlaEqLegacy(gb_abst.get(), gb.get());
}

TEST_F(TestSynthImport, GB_high) {
  auto abst_file = os_portable_append_dir(dir_gb, "gb_high.abst");
  auto json_file = os_portable_append_dir(dir_gb, "gb_high.json");

  auto gb_abst = ImportSynthAbstraction(abst_file, "gb");
  auto gb = ImportIlaPortable(json_file);

  CheckIlaEqLegacy(gb_abst.get(), gb.get());
}

TEST_F(TestSynthImport, RBM_top) {
  auto abst_file = os_portable_append_dir(dir_rbm, "top.abst");
  auto json_file = os_portable_append_dir(dir_rbm, "top.json");

  auto top_abst = ImportSynthAbstraction(abst_file, "top");
  auto top = ImportIlaPortable(json_file);

  CheckIlaEqLegacy(top_abst.get(), top.get());
}

TEST_F(TestSynthImport, RBM_compute) {
  auto abst_file = os_portable_append_dir(dir_rbm, "compute.abst");
  auto json_file = os_portable_append_dir(dir_rbm, "compute.json");

  auto compute_abst = ImportSynthAbstraction(abst_file, "compute");
  auto compute = ImportIlaPortable(json_file);

  CheckIlaEqLegacy(compute_abst.get(), compute.get());
}

TEST_F(TestSynthImport, RBM_predict) {
  auto abst_file = os_portable_append_dir(dir_rbm, "predict.abst");
  auto json_file = os_portable_append_dir(dir_rbm, "predict.json");

  auto predict_abst = ImportSynthAbstraction(abst_file, "predict");
  auto predict = ImportIlaPortable(json_file);

  CheckIlaEqLegacy(predict_abst.get(), predict.get());
}

TEST_F(TestSynthImport, RBM_train) {
  auto abst_file = os_portable_append_dir(dir_rbm, "train.abst");
  auto json_file = os_portable_append_dir(dir_rbm, "train.json");

  auto train_abst = ImportSynthAbstraction(abst_file, "train");
  auto train = ImportIlaPortable(json_file);

  CheckIlaEqLegacy(train_abst.get(), train.get());
}

TEST_F(TestSynthImport, RBM_dmaload) {
  auto abst_file = os_portable_append_dir(dir_rbm, "dmaload.abst");
  auto json_file = os_portable_append_dir(dir_rbm, "dmaload.json");

  auto dma_abst = ImportSynthAbstraction(abst_file, "dmaload");
  auto dma = ImportIlaPortable(json_file);

  CheckIlaEqLegacy(dma_abst.get(), dma.get());
}

TEST_F(TestSynthImport, RBM_store) {
  auto abst_file = os_portable_append_dir(dir_rbm, "store.abst");
  auto json_file = os_portable_append_dir(dir_rbm, "store.json");

  auto store_abst = ImportSynthAbstraction(abst_file, "store");
  auto store = ImportIlaPortable(json_file);

  CheckIlaEqLegacy(store_abst.get(), store.get());
}

TEST_F(TestSynthImport, RBM_hierarchy) {
  auto top_file = os_portable_append_dir(dir_rbm, "top.abst");
  auto compute_file = os_portable_append_dir(dir_rbm, "compute.abst");
  auto predict_file = os_portable_append_dir(dir_rbm, "predict.abst");
  auto train_file = os_portable_append_dir(dir_rbm, "train.abst");
  auto dmaload_file = os_portable_append_dir(dir_rbm, "dmaload.abst");
  auto store_file = os_portable_append_dir(dir_rbm, "store.abst");

  // parent
  auto rbm_abst = ImportSynthAbstraction(top_file, "rbm");

  // parent --> compute
  ImportChildSynthAbstraction(compute_file, rbm_abst, "compute");

  auto compute = rbm_abst.child("compute");
  // parent --> compute --> predict
  ImportChildSynthAbstraction(predict_file, compute, "predict");
  // parent --> compute --> train
  ImportChildSynthAbstraction(train_file, compute, "train");

  // parent --> DMAload
  ImportChildSynthAbstraction(dmaload_file, rbm_abst, "dmaload");
  // parent --> store
  ImportChildSynthAbstraction(store_file, rbm_abst, "store");

  auto json_file = os_portable_append_dir(dir_rbm, "rbm.json");
  auto rbm = ImportIlaPortable(json_file);

  CheckIlaEqLegacy(rbm_abst.get(), rbm.get());
}

TEST_F(TestSynthImport, OC8051) {
  auto abst_file = os_portable_append_dir(dir_oc, "oc.abst");
  auto json_file = os_portable_append_dir(dir_oc, "oc.json");

  auto oc_abst = ImportSynthAbstraction(abst_file, "oc");
  auto oc = ImportIlaPortable(json_file);

  // CheckIlaEqLegacy(oc_abst.get(), oc.get());
}

}; // namespace ilang
