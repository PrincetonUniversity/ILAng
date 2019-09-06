#include "systemc.h"
#include "test.h"
bool TEST::decode_TEST_WRITE_ADDRESS() {
  c_97816 = TEST_cmd == 1;
  c_97812 = TEST_cmd == 2;
  c_97818 = (c_97816 | c_97812);
  if (!c_97818) {
    return false;
  }
  c_97841 = TEST_cmd == 2;
  c_97834 = TEST_cmdaddr == 65282;
  c_97836 = TEST_cmdaddr > 65282;
  c_97838 = (c_97834 | c_97836);
  c_97843 = (c_97841 & c_97838);
  c_97830 = TEST_cmdaddr < 65284;
  c_97844 = (c_97843 & c_97830);
  return c_97844;
};
