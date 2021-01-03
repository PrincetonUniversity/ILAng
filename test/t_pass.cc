/// \file
/// Unit tests for ILA passes.

#include <ilang/ila-mngr/pass.h>
#include <ilang/ilang++.h>
#include <ilang/util/fs.h>

#include "unit-include/config.h"
#include "unit-include/util.h"

namespace ilang {

void ApplyPass(const std::string& dir, const std::string& file,
               bool simplify = true) {
  EnableDebug("PassSimpSemantic");
  EnableDebug("PassRewrCondStore");
  EnableDebug("PassRewrStoreLoad");
  EnableDebug("PassInferChildProgCFG");
  EnableDebug("PassMapChildProgEntry");
  EnableDebug("PassSanityCheck");

  auto file_dir = os_portable_append_dir(ILANG_TEST_DATA_DIR, dir);
  auto ila_file = os_portable_append_dir(file_dir, file);
  auto ila = ImportIlaPortable(ila_file);

  ila.ExecutePass({Ila::PassID::SANITY_CHECK_AND_FIX}); // this may add instr.

  ila.ExecutePass({Ila::PassID::SIMPLIFY_SYNTACTIC,
                   Ila::PassID::SIMPLIFY_SEMANTIC,
                   Ila::PassID::REWRITE_CONDITIONAL_STORE,
                   Ila::PassID::REWRITE_LOAD_FROM_STORE});

  pass::InferChildProgCFG(ila.get());
  pass::MapChildProgEntryPoint(ila.get());

  auto org = ImportIlaPortable(ila_file);
  org.ExecutePass({Ila::PassID::SANITY_CHECK_AND_FIX}); // this may add instr.

  CheckIlaEqLegacy(org.get(), ila.get());

  DisableDebug("PassSimpSemantic");
  DisableDebug("PassRewrCondStore");
  DisableDebug("PassRewrStoreLoad");
  DisableDebug("PassInferChildProgCFG");
  DisableDebug("PassMapChildProgEntry");
  DisableDebug("PassSanityCheck");
}

TEST(TestPass, AES) { ApplyPass("aes", "aes.json"); }

TEST(TestPass, AES_128) { ApplyPass("aes", "aes_128.json"); }

TEST(TestPass, AES_C) { ApplyPass("aes", "aes_c.json"); }

#if 0
TEST(TestPass, AES_V) { ApplyPass("aes", "aes_v.json"); }
#endif

TEST(TestPass, GB_LOW) { ApplyPass("gb", "gb_low.json"); }

TEST(TestPass, RBM) { ApplyPass("rbm", "rbm.json"); }

#if 0
TEST(TestPass, OC8051) { ApplyPass("oc", "oc.json"); }
#endif

}; // namespace ilang
