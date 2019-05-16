#include "ilang/ila/ila_sim/ila_sim.h"
#include "unit-include/ila_sim_test.h"
#include <iostream>

int get_line_number(ifstream& i) {
  int count = 0;
  string line;
  while (getline(i, line))
    count++;
  i.clear();
  i.seekg(0, ios::beg);
  return count;
}

namespace ilang{
TEST(TestIlaSim, AES) {
  IlaSimTest ila_sim_test;
  InstrLvlAbs model = ila_sim_test.model; 
  IlaSim ila_sim;
  ila_sim.set_instr_lvl_abs(model);
  ila_sim.set_systemc_path("/home/yuex/bin/systemc-2.3.1/");
  ila_sim.sim_gen("/tmp/", false, false);


  string test_decode_file = "/tmp/" + "decode_59.cc";
  string test_update_file = "/tmp/" + "decode_59_update_TEST_address.cc";
  string test_header_file = "/tmp/" + "test.h";
  string test_mk_file = "/tmp/" + "mk.sh";

  try {
    ifstream test_decode_stream(test_decode_file);
    ifstream test_update_stream(test_update_file);
    ifstream test_header_stream(test_header_file);
    ifstream test_mk_stream(test_mk_file);
  } catch (...) {
    ILA_ERROR << "test files do not exist.";
  }

  string ref_decode_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim/decode_59.cc";
  string ref_update_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim/decode_59_update_TEST_address.cc";
  string ref_header_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim/test.h"
  string ref_mk_file = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/ila_sim/mk.sh"

  ifstream ref_docode_stream(ref_decode_file);
  ifstream ref_update_stream(ref_update_file);
  ifstream ref_header_stream(ref_header_file);
  ifstream ref_mk_stream(ref_mk_file);

  EXPECT_EQ(get_line_number(ref_decode_stream, get_line_number(test_decode_stream)));

  string ref_decode_string;
  string test_decode_string;
  while(getline(ref_decode_stream, ref_decode_string)) {
    getline(test_decode_stream, test_decode_string);
    EXPECT_EQ(test_decode_string, ref_decode_string);
  }

}
}
