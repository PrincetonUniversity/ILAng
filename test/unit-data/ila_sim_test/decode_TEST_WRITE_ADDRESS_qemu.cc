#include "TEST.h"
bool TEST::decode_TEST_WRITE_ADDRESS() {
  c_1693068 = TEST_cmd == 1;
  c_1693064 = TEST_cmd == 2;
  c_1693070 = (c_1693068 | c_1693064);
  if (!c_1693070) {
    return false;
  }
  c_1693093 = TEST_cmd == 2;
  c_1693086 = TEST_cmdaddr == 65282;
  c_1693088 = TEST_cmdaddr > 65282;
  c_1693090 = (c_1693086 | c_1693088);
  c_1693095 = (c_1693093 & c_1693090);
  c_1693082 = TEST_cmdaddr < 65284;
  c_1693096 = (c_1693095 & c_1693082);
  return c_1693096;
};
