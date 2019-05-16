#include "systemc.h"
#include "test.h"
sc_biguint<16> TEST::decode_97141_update_TEST_address() {
  c_97122 = TEST_status == 0;
  c_97153 = TEST_cmdaddr == 65283;
  c_97149 = TEST_address.range(15, 8);
  c_97155 = (c_97153) ? TEST_cmddata : c_97149;
  c_97146 = TEST_cmdaddr == 65282;
  c_97142 = TEST_address.range(7, 0);
  c_97148 = (c_97146) ? TEST_cmddata : c_97142;
  c_97160 = (c_97155, c_97148);
  c_97162 = (c_97122) ? c_97160 : TEST_address;
  return c_97162;
};
