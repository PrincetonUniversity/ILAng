#include "systemc.h"
#include "test.h"
sc_biguint<16> TEST::decode_TEST_WRITE_ADDRESS_update_TEST_address() {
  c_97821 = TEST_status == 0;
  c_97856 = TEST_cmdaddr == 65283;
  c_97852 = TEST_address.range(15, 8);
  c_97858 = (c_97856) ? TEST_cmddata : c_97852;
  c_97849 = TEST_cmdaddr == 65282;
  c_97845 = TEST_address.range(7, 0);
  c_97851 = (c_97849) ? TEST_cmddata : c_97845;
  c_97863 = (c_97858, c_97851);
  c_97865 = (c_97821) ? c_97863 : TEST_address;
  return c_97865;
};
