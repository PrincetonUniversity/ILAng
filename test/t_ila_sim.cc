#include "unit-include/config.h"
#include "unit-include/util.h"
#include <ilang/ila_sim/ila_sim.h>
#include <ilang/ila/instr_lvl_abs.h>
#include "unit-include/ila_sim_test.h"
#include <iostream>

namespace ilang{
int get_line_number(ifstream& i) {
  int count = 0;
  string line;
  while (getline(i, line))
    count++;
  i.clear();
  i.seekg(0, ios::beg);
  return count;
}

TEST(TestIlaSim, hashed_file_name) {
  IlaSimTest ila_sim_test;
  IlaSim ila_sim;
  ila_sim.set_instr_lvl_abs(ila_sim_test.model.get());
  ila_sim.set_systemc_path("/home/yuex/bin/systemc-2.3.1/");
  ila_sim.sim_gen("/tmp/", false, false);


  string test_decode_file = "/tmp/decode_97141.cc";
  string test_update_file = "/tmp/decode_97141_update_TEST_address.cc";
  string test_header_file = "/tmp/test.h";
  string test_mk_file = "/tmp/mk.sh";

  try {
    ifstream test_decode_stream(test_decode_file);
    ifstream test_update_stream(test_update_file);
    ifstream test_header_stream(test_header_file);
    ifstream test_mk_stream(test_mk_file);
  } catch (...) {
    ILA_ERROR << "test files do not exist.";
  }

  ifstream test_decode_stream(test_decode_file);
  ifstream test_update_stream(test_update_file);
  ifstream test_header_stream(test_header_file);
  ifstream test_mk_stream(test_mk_file); 

  string ref_decode_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim_test/decode_97141.cc";
  string ref_update_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim_test/decode_97141_update_TEST_address.cc";
  string ref_header_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim_test/test.h";
  string ref_mk_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim_test/mk.sh";

  ifstream ref_decode_stream(ref_decode_file);
  ifstream ref_update_stream(ref_update_file);
  ifstream ref_header_stream(ref_header_file);
  ifstream ref_mk_stream(ref_mk_file);

  EXPECT_EQ(get_line_number(ref_decode_stream), get_line_number(test_decode_stream));

  string ref_decode_string;
  string test_decode_string;
  while(getline(ref_decode_stream, ref_decode_string)) {
    getline(test_decode_stream, test_decode_string);
    EXPECT_EQ(test_decode_string, ref_decode_string);
  }
}

TEST(TestIlaSim, readable_file_name) {
  IlaSimTest ila_sim_test;
  IlaSim ila_sim;
  ila_sim.set_instr_lvl_abs(ila_sim_test.model.get());
  ila_sim.set_systemc_path("/home/yuex/bin/systemc-2.3.1/");
  ila_sim.sim_gen("/tmp/", false, true);


  string test_decode_file = "/tmp/decode_TEST_WRITE_ADDRESS.cc";
  string test_update_file = "/tmp/decode_TEST_WRITE_ADDRESS_update_TEST_address.cc";
  string test_header_file = "/tmp/test.h";
  string test_mk_file = "/tmp/mk.sh";

  try {
    ifstream test_decode_stream(test_decode_file);
    ifstream test_update_stream(test_update_file);
    ifstream test_header_stream(test_header_file);
    ifstream test_mk_stream(test_mk_file);
  } catch (...) {
    ILA_ERROR << "test files do not exist.";
  }

  ifstream test_decode_stream(test_decode_file);
  ifstream test_update_stream(test_update_file);
  ifstream test_header_stream(test_header_file);
  ifstream test_mk_stream(test_mk_file); 

  string ref_decode_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim_test/decode_TEST_WRITE_ADDRESS.cc";
  string ref_update_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim_test/decode_TEST_WRITE_ADDRESS_update_TEST_address.cc";
  string ref_header_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim_test/test_readable.h";
  string ref_mk_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim_test/mk_readable.sh";

  ifstream ref_decode_stream(ref_decode_file);
  ifstream ref_update_stream(ref_update_file);
  ifstream ref_header_stream(ref_header_file);
  ifstream ref_mk_stream(ref_mk_file);

  EXPECT_EQ(get_line_number(ref_decode_stream), get_line_number(test_decode_stream));

  string ref_decode_string;
  string test_decode_string;
  while(getline(ref_decode_stream, ref_decode_string)) {
    getline(test_decode_stream, test_decode_string);
    EXPECT_EQ(test_decode_string, ref_decode_string);
  }
}

TEST(TestIlaSim, external_mem) {
  IlaSimTest ila_sim_test;
  IlaSim ila_sim;
  ila_sim.set_instr_lvl_abs(ila_sim_test.model.get());
  ila_sim.set_systemc_path("/home/yuex/bin/systemc-2.3.1/");
  ila_sim.sim_gen("/tmp/", true, false);


  string test_compute_file = "/tmp/compute.cc";
  string test_header_file = "/tmp/test.h";
  string test_mk_file = "/tmp/mk.sh";

  try {
    ifstream test_compute_stream(test_compute_file);
    ifstream test_header_stream(test_header_file);
    ifstream test_mk_stream(test_mk_file);
  } catch (...) {
    ILA_ERROR << "test files do not exist.";
  }

  ifstream test_compute_stream(test_compute_file);
  ifstream test_header_stream(test_header_file);
  ifstream test_mk_stream(test_mk_file); 

  string ref_compute_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim_test/compute_external_mem.cc";
  string ref_header_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim_test/test_external_mem.h";
  string ref_mk_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim_test/mk_external_mem.sh";

  ifstream ref_compute_stream(ref_compute_file);
  ifstream ref_header_stream(ref_header_file);
  ifstream ref_mk_stream(ref_mk_file);

  EXPECT_EQ(get_line_number(ref_compute_stream), get_line_number(test_compute_stream));

  string ref_compute_string;
  string test_compute_string;
  while(getline(ref_compute_stream, ref_compute_string)) {
    getline(test_compute_stream, test_compute_string);
    EXPECT_EQ(test_compute_string, ref_compute_string);
  }
}



}
