#include "systemc.h"
#include "test.h"
bool TEST::decode_97141() {
  c_97117 = TEST_cmd == 1;
  c_97113 = TEST_cmd == 2;
  c_97119 = (c_97117 | c_97113);
  if (!c_97119) {
    return false;
  }
  c_97138 = TEST_cmd == 2;
  c_97131 = TEST_cmdaddr == 65282;
  c_97133 = TEST_cmdaddr > 65282;
  c_97135 = (c_97131 | c_97133);
  c_97140 = (c_97138 & c_97135);
  c_97127 = TEST_cmdaddr < 65284;
  c_97141 = (c_97140 & c_97127);
  return c_97141;
};
