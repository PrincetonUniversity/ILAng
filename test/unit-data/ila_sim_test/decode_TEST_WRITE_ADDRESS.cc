#include "systemc.h"
#include "TEST.h"
bool TEST::decode_TEST_WRITE_ADDRESS() {
  c_1690967 = TEST_cmd == 1;
  c_1690963 = TEST_cmd == 2;
  c_1690969 = (c_1690967 | c_1690963);
  if (!c_1690969) {
    return false;
  }
  c_1690992 = TEST_cmd == 2;
  c_1690985 = TEST_cmdaddr == 65282;
  c_1690987 = TEST_cmdaddr > 65282;
  c_1690989 = (c_1690985 | c_1690987);
  c_1690994 = (c_1690992 & c_1690989);
  c_1690981 = TEST_cmdaddr < 65284;
  c_1690995 = (c_1690994 & c_1690981);
  return c_1690995;
};
