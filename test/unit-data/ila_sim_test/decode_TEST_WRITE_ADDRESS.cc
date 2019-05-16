#include "systemc.h"
#include "test.h"
bool TEST::decode_TEST_WRITE_ADDRESS() {
  c_97754 = TEST_cmd == 1;
  c_97750 = TEST_cmd == 2;
  c_97756 = (c_97754 | c_97750);
  if (!c_97756) {
    return false;
  }
  c_97775 = TEST_cmd == 2;
  c_97768 = TEST_cmdaddr == 65282;
  c_97770 = TEST_cmdaddr > 65282;
  c_97772 = (c_97768 | c_97770);
  c_97777 = (c_97775 & c_97772);
  c_97764 = TEST_cmdaddr < 65284;
  c_97778 = (c_97777 & c_97764);
  return c_97778;
};
