#include "systemc.h"
#include "test.h"
sc_biguint<16> TEST::decode_TEST_WRITE_ADDRESS_update_TEST_address() {
  c_97781 = TEST_status == 0;
  c_97816 = TEST_cmdaddr == 65283;
  c_97812 = TEST_address.range(15, 8);
  c_97818 = (c_97816) ? TEST_cmddata : c_97812;
  c_97809 = TEST_cmdaddr == 65282;
  c_97805 = TEST_address.range(7, 0);
  c_97811 = (c_97809) ? TEST_cmddata : c_97805;
  c_97823 = (c_97818, c_97811);
  c_97825 = (c_97781) ? c_97823 : TEST_address;
  return c_97825;
};
