#include "systemc.h"
#include "test.h"
sc_biguint<16> TEST::decode_97151_update_TEST_address() {
  c_97128 = TEST_status == 0;
  c_97163 = TEST_cmdaddr == 65283;
  c_97159 = TEST_address.range(15, 8);
  c_97165 = (c_97163) ? TEST_cmddata : c_97159;
  c_97156 = TEST_cmdaddr == 65282;
  c_97152 = TEST_address.range(7, 0);
  c_97158 = (c_97156) ? TEST_cmddata : c_97152;
  c_97170 = (c_97165, c_97158);
  c_97172 = (c_97128) ? c_97170 : TEST_address;
  return c_97172;
};
