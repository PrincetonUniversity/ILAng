#include "systemc.h"
#include "test.h"
bool TEST::decode_TEST_WRITE_ADDRESS() {
  c_97776 = TEST_cmd == 1;
  c_97772 = TEST_cmd == 2;
  c_97778 = (c_97776 | c_97772);
  if (!c_97778) {
    return false;
  }
  c_97801 = TEST_cmd == 2;
  c_97794 = TEST_cmdaddr == 65282;
  c_97796 = TEST_cmdaddr > 65282;
  c_97798 = (c_97794 | c_97796);
  c_97803 = (c_97801 & c_97798);
  c_97790 = TEST_cmdaddr < 65284;
  c_97804 = (c_97803 & c_97790);
  return c_97804;
};
