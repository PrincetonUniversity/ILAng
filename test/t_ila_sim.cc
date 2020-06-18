#include <ilang/target-sc/ila_sim.h>

#include <iostream>
#include <sstream>
#include <string>

#include "unit-include/config.h"
#include "unit-include/ila_sim_test.h"
#include "unit-include/util.h"
#include <ilang/ila/instr_lvl_abs.h>

namespace ilang {
int get_line_number(std::ifstream& i) {
  int count = 0;
  std::string line;
  while (getline(i, line))
    count++;
  i.clear();
  i.seekg(0, std::ios::beg);
  return count;
}

int get_word_number(std::string& s) {
  int count = 0;
  std::stringstream s_stream(s);
  std::string word;
  while (getline(s_stream, word, ' ')) {
    count++;
  }
  return count;
}

TEST(DISABLED_TestIlaSimSC, hashed_file_name) {
  // This test should be muted, if the basic structure of ILA is changed,
  // such as how state/decode/state_update are changed.
  // Specifically, the test on "decode_stream" and "update_stream".

  IlaSimTest ila_sim_test;
  IlaSim ila_sim;
  ila_sim.set_instr_lvl_abs(ila_sim_test.model.get());
  ila_sim.set_systemc_path("/home/yuex/bin/systemc-2.3.1/");
  ila_sim.sim_gen("/tmp/", false, false);

  std::string test_decode_file = "/tmp/decode_115572.cc";
  std::string test_update_file = "/tmp/decode_115572_update_TEST_address.cc";
  std::string test_header_file = "/tmp/TEST.h";
  std::string test_mk_file = "/tmp/mk.sh";

  try {
    std::ifstream test_decode_stream(test_decode_file);
    std::ifstream test_update_stream(test_update_file);
    std::ifstream test_header_stream(test_header_file);
    std::ifstream test_mk_stream(test_mk_file);
  } catch (...) {
    ILA_ERROR << "test files do not exist.";
  }

  std::ifstream test_decode_stream(test_decode_file);
  std::ifstream test_update_stream(test_update_file);
  std::ifstream test_header_stream(test_header_file);
  std::ifstream test_mk_stream(test_mk_file);

  std::string ref_decode_file = std::string(ILANG_TEST_SRC_ROOT) +
                                "/unit-data/ila_sim_test/decode_115572.cc";
  std::string ref_update_file =
      std::string(ILANG_TEST_SRC_ROOT) +
      "/unit-data/ila_sim_test/decode_115572_update_TEST_address.cc";
  std::string ref_header_file =
      std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim_test/test.h";
  std::string ref_mk_file =
      std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim_test/mk.sh";

  std::ifstream ref_decode_stream(ref_decode_file);
  std::ifstream ref_update_stream(ref_update_file);
  std::ifstream ref_header_stream(ref_header_file);
  std::ifstream ref_mk_stream(ref_mk_file);
#if 0
  EXPECT_EQ(get_line_number(ref_decode_stream),
            get_line_number(test_decode_stream));
  std::string ref_decode_string;
  std::string test_decode_string;
  while (getline(ref_decode_stream, ref_decode_string)) {
    getline(test_decode_stream, test_decode_string);
    EXPECT_EQ(get_word_number(test_decode_string),
              get_word_number(ref_decode_string));
  }

  EXPECT_EQ(get_line_number(ref_update_stream),
            get_line_number(test_update_stream));
  std::string ref_update_string;
  std::string test_update_string;
  while (getline(ref_update_stream, ref_update_string)) {
    getline(test_update_stream, test_update_string);
    EXPECT_EQ(get_word_number(test_update_string),
              get_word_number(ref_update_string));
  }
#endif
  EXPECT_EQ(get_line_number(ref_header_stream),
            get_line_number(test_header_stream));
  std::string ref_header_string;
  std::string test_header_string;
  while (getline(ref_header_stream, ref_header_string)) {
    getline(test_header_stream, test_header_string);
    EXPECT_EQ(get_word_number(test_header_string),
              get_word_number(ref_header_string));
  }

  EXPECT_EQ(get_line_number(ref_mk_stream), get_line_number(test_mk_stream));
  std::string ref_mk_string;
  std::string test_mk_string;
  while (getline(ref_mk_stream, ref_mk_string)) {
    getline(test_mk_stream, test_mk_string);
    EXPECT_EQ(get_word_number(test_mk_string), get_word_number(ref_mk_string));
  }
}

TEST(DISABLED_TestIlaSimSC, readable_file_name) {
  IlaSimTest ila_sim_test;
  IlaSim ila_sim;
  ila_sim.set_instr_lvl_abs(ila_sim_test.model.get());
  ila_sim.set_systemc_path("/home/yuex/bin/systemc-2.3.1/");
  ila_sim.sim_gen("/tmp/", false, true);

  std::string test_decode_file = "/tmp/decode_TEST_WRITE_ADDRESS.cc";
  std::string test_update_file =
      "/tmp/decode_TEST_WRITE_ADDRESS_update_TEST_address.cc";
  std::string test_header_file = "/tmp/TEST.h";
  std::string test_mk_file = "/tmp/mk.sh";

  try {
    std::ifstream test_decode_stream(test_decode_file);
    std::ifstream test_update_stream(test_update_file);
    std::ifstream test_header_stream(test_header_file);
    std::ifstream test_mk_stream(test_mk_file);
  } catch (...) {
    ILA_ERROR << "test files do not exist.";
  }

  std::ifstream test_decode_stream(test_decode_file);
  std::ifstream test_update_stream(test_update_file);
  std::ifstream test_header_stream(test_header_file);
  std::ifstream test_mk_stream(test_mk_file);

  std::string ref_decode_file =
      std::string(ILANG_TEST_SRC_ROOT) +
      "/unit-data/ila_sim_test/decode_TEST_WRITE_ADDRESS.cc";
  std::string ref_update_file =
      std::string(ILANG_TEST_SRC_ROOT) +
      "/unit-data/ila_sim_test/"
      "decode_TEST_WRITE_ADDRESS_update_TEST_address.cc";
  std::string ref_header_file = std::string(ILANG_TEST_SRC_ROOT) +
                                "/unit-data/ila_sim_test/test_readable.h";
  std::string ref_mk_file = std::string(ILANG_TEST_SRC_ROOT) +
                            "/unit-data/ila_sim_test/mk_readable.sh";

  std::ifstream ref_decode_stream(ref_decode_file);
  std::ifstream ref_update_stream(ref_update_file);
  std::ifstream ref_header_stream(ref_header_file);
  std::ifstream ref_mk_stream(ref_mk_file);

  EXPECT_EQ(get_line_number(ref_decode_stream),
            get_line_number(test_decode_stream));
  std::string ref_decode_string;
  std::string test_decode_string;
  while (getline(ref_decode_stream, ref_decode_string)) {
    getline(test_decode_stream, test_decode_string);
    EXPECT_EQ(get_word_number(test_decode_string),
              get_word_number(ref_decode_string));
  }

  EXPECT_EQ(get_line_number(ref_update_stream),
            get_line_number(test_update_stream));
  std::string ref_update_string;
  std::string test_update_string;
  while (getline(ref_update_stream, ref_update_string)) {
    getline(test_update_stream, test_update_string);
    EXPECT_EQ(get_word_number(test_update_string),
              get_word_number(ref_update_string));
  }

  EXPECT_EQ(get_line_number(ref_header_stream),
            get_line_number(test_header_stream));
  std::string ref_header_string;
  std::string test_header_string;
  while (getline(ref_header_stream, ref_header_string)) {
    getline(test_header_stream, test_header_string);
    EXPECT_EQ(get_word_number(test_header_string),
              get_word_number(ref_header_string));
  }

  EXPECT_EQ(get_line_number(ref_mk_stream), get_line_number(test_mk_stream));
  std::string ref_mk_string;
  std::string test_mk_string;
  while (getline(ref_mk_stream, ref_mk_string)) {
    getline(test_mk_stream, test_mk_string);
    EXPECT_EQ(get_word_number(test_mk_string), get_word_number(ref_mk_string));
  }
}

TEST(DISABLED_TestIlaSimSC, external_mem) {
  IlaSimTest ila_sim_test;
  IlaSim ila_sim(ila_sim_test.model.get());
  ila_sim.set_systemc_path("/home/yuex/bin/systemc-2.3.1/");
  ila_sim.sim_gen("/tmp/", true, false);

  std::string test_compute_file = "/tmp/compute.cc";
  std::string test_header_file = "/tmp/TEST.h";
  std::string test_mk_file = "/tmp/mk.sh";

  try {
    std::ifstream test_compute_stream(test_compute_file);
    std::ifstream test_header_stream(test_header_file);
    std::ifstream test_mk_stream(test_mk_file);
  } catch (...) {
    ILA_ERROR << "test files do not exist.";
  }

  std::ifstream test_compute_stream(test_compute_file);
  std::ifstream test_header_stream(test_header_file);
  std::ifstream test_mk_stream(test_mk_file);

  std::string ref_compute_file =
      std::string(ILANG_TEST_SRC_ROOT) +
      "/unit-data/ila_sim_test/compute_external_mem.cc";
  std::string ref_header_file = std::string(ILANG_TEST_SRC_ROOT) +
                                "/unit-data/ila_sim_test/test_external_mem.h";
  std::string ref_mk_file = std::string(ILANG_TEST_SRC_ROOT) +
                            "/unit-data/ila_sim_test/mk_external_mem.sh";

  std::ifstream ref_compute_stream(ref_compute_file);
  std::ifstream ref_header_stream(ref_header_file);
  std::ifstream ref_mk_stream(ref_mk_file);

  EXPECT_EQ(get_line_number(ref_compute_stream),
            get_line_number(test_compute_stream));
  std::string ref_compute_string;
  std::string test_compute_string;
  while (getline(ref_compute_stream, ref_compute_string)) {
    getline(test_compute_stream, test_compute_string);
    EXPECT_EQ(get_word_number(test_compute_string),
              get_word_number(ref_compute_string));
  }

  EXPECT_EQ(get_line_number(ref_header_stream),
            get_line_number(test_header_stream));
  std::string ref_header_string;
  std::string test_header_string;
  while (getline(ref_header_stream, ref_header_string)) {
    getline(test_header_stream, test_header_string);
    EXPECT_EQ(get_word_number(test_header_string),
              get_word_number(ref_header_string));
  }

  EXPECT_EQ(get_line_number(ref_mk_stream), get_line_number(test_mk_stream));
  std::string ref_mk_string;
  std::string test_mk_string;
  while (getline(ref_mk_stream, ref_mk_string)) {
    getline(test_mk_stream, test_mk_string);
    EXPECT_EQ(get_word_number(test_mk_string), get_word_number(ref_mk_string));
  }
}

TEST(DISABLED_TestIlaSimQemu, hashed_file_name) {
  // This test should be muted, if the basic structure of ILA is changed,
  // such as how state/decode/state_update are changed.
  // Specifically, the test on "decode_stream" and "update_stream".

  IlaSimTest ila_sim_test;
  IlaSim ila_sim;
  ila_sim.set_instr_lvl_abs(ila_sim_test.model.get());
  ila_sim.sim_gen("/tmp/", false, false, true);

  std::string test_header_file = "/tmp/TEST.h";
  std::string test_mk_file = "/tmp/mk.sh";

  try {
    std::ifstream test_header_stream(test_header_file);
    std::ifstream test_mk_stream(test_mk_file);
  } catch (...) {
    ILA_ERROR << "test files do not exist.";
  }

  std::ifstream test_header_stream(test_header_file);
  std::ifstream test_mk_stream(test_mk_file);

  std::string ref_header_file =
      std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim_test/test_qemu.h";
  std::string ref_mk_file =
      std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim_test/mk_qemu.sh";

  std::ifstream ref_header_stream(ref_header_file);
  std::ifstream ref_mk_stream(ref_mk_file);

  EXPECT_EQ(get_line_number(ref_header_stream),
            get_line_number(test_header_stream));
  std::string ref_header_string;
  std::string test_header_string;
  while (getline(ref_header_stream, ref_header_string)) {
    getline(test_header_stream, test_header_string);
    EXPECT_EQ(get_word_number(test_header_string),
              get_word_number(ref_header_string));
  }

  EXPECT_EQ(get_line_number(ref_mk_stream), get_line_number(test_mk_stream));
  std::string ref_mk_string;
  std::string test_mk_string;
  while (getline(ref_mk_stream, ref_mk_string)) {
    getline(test_mk_stream, test_mk_string);
    EXPECT_EQ(get_word_number(test_mk_string), get_word_number(ref_mk_string));
  }
}

TEST(DISABLED_TestIlaSimQemu, readable_file_name) {
  IlaSimTest ila_sim_test;
  IlaSim ila_sim;
  ila_sim.set_instr_lvl_abs(ila_sim_test.model.get());
  ila_sim.sim_gen("/tmp/", false, true, true);

  std::string test_decode_file = "/tmp/decode_TEST_WRITE_ADDRESS.cc";
  std::string test_update_file =
      "/tmp/decode_TEST_WRITE_ADDRESS_update_TEST_address.cc";
  std::string test_header_file = "/tmp/TEST.h";
  std::string test_mk_file = "/tmp/mk.sh";

  try {
    std::ifstream test_decode_stream(test_decode_file);
    std::ifstream test_update_stream(test_update_file);
    std::ifstream test_header_stream(test_header_file);
    std::ifstream test_mk_stream(test_mk_file);
  } catch (...) {
    ILA_ERROR << "test files do not exist.";
  }

  std::ifstream test_decode_stream(test_decode_file);
  std::ifstream test_update_stream(test_update_file);
  std::ifstream test_header_stream(test_header_file);
  std::ifstream test_mk_stream(test_mk_file);

  std::string ref_decode_file =
      std::string(ILANG_TEST_SRC_ROOT) +
      "/unit-data/ila_sim_test/decode_TEST_WRITE_ADDRESS_qemu.cc";
  std::string ref_update_file =
      std::string(ILANG_TEST_SRC_ROOT) +
      "/unit-data/ila_sim_test/"
      "decode_TEST_WRITE_ADDRESS_update_TEST_address_qemu.cc";
  std::string ref_header_file = std::string(ILANG_TEST_SRC_ROOT) +
                                "/unit-data/ila_sim_test/test_readable_qemu.h";
  std::string ref_mk_file = std::string(ILANG_TEST_SRC_ROOT) +
                            "/unit-data/ila_sim_test/mk_readable_qemu.sh";

  std::ifstream ref_decode_stream(ref_decode_file);
  std::ifstream ref_update_stream(ref_update_file);
  std::ifstream ref_header_stream(ref_header_file);
  std::ifstream ref_mk_stream(ref_mk_file);

  EXPECT_EQ(get_line_number(ref_decode_stream),
            get_line_number(test_decode_stream));
  std::string ref_decode_string;
  std::string test_decode_string;
  while (getline(ref_decode_stream, ref_decode_string)) {
    getline(test_decode_stream, test_decode_string);
    EXPECT_EQ(get_word_number(test_decode_string),
              get_word_number(ref_decode_string));
  }

  EXPECT_EQ(get_line_number(ref_update_stream),
            get_line_number(test_update_stream));
  std::string ref_update_string;
  std::string test_update_string;
  while (getline(ref_update_stream, ref_update_string)) {
    getline(test_update_stream, test_update_string);
    EXPECT_EQ(get_word_number(test_update_string),
              get_word_number(ref_update_string));
  }

  EXPECT_EQ(get_line_number(ref_header_stream),
            get_line_number(test_header_stream));
  std::string ref_header_string;
  std::string test_header_string;
  while (getline(ref_header_stream, ref_header_string)) {
    getline(test_header_stream, test_header_string);
    EXPECT_EQ(get_word_number(test_header_string),
              get_word_number(ref_header_string));
  }

  EXPECT_EQ(get_line_number(ref_mk_stream), get_line_number(test_mk_stream));
  std::string ref_mk_string;
  std::string test_mk_string;
  while (getline(ref_mk_stream, ref_mk_string)) {
    getline(test_mk_stream, test_mk_string);
    EXPECT_EQ(get_word_number(test_mk_string), get_word_number(ref_mk_string));
  }
}

} // namespace ilang
