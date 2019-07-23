#include "TEST.h"
bool TEST::decode_TEST_WRITE_ADDRESS() {
  c_734 = TEST_cmd == 1;
  c_730 = TEST_cmd == 2;
  c_736 = (c_734 | c_730);
  if (!c_736) {
    return false;
  }
  c_759 = TEST_cmd == 2;
  c_752 = TEST_cmdaddr == 65282;
  c_754 = TEST_cmdaddr > 65282;
  c_756 = (c_752 | c_754);
  c_761 = (c_759 & c_756);
  c_748 = TEST_cmdaddr < 65284;
  c_762 = (c_761 & c_748);
  return c_762;
};
