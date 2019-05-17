#include "systemc.h"
#include "test.h"
bool TEST::decode_97151() {
  c_97123 = TEST_cmd == 1;
  c_97119 = TEST_cmd == 2;
  c_97125 = (c_97123 | c_97119);
  if (!c_97125) {
    return false;
  }
  c_97148 = TEST_cmd == 2;
  c_97141 = TEST_cmdaddr == 65282;
  c_97143 = TEST_cmdaddr > 65282;
  c_97145 = (c_97141 | c_97143);
  c_97150 = (c_97148 & c_97145);
  c_97137 = TEST_cmdaddr < 65284;
  c_97151 = (c_97150 & c_97137);
  return c_97151;
};
