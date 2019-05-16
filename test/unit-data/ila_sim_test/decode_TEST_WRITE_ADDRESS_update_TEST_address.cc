#include "systemc.h"
#include "test.h"
sc_biguint<16> TEST::decode_TEST_WRITE_ADDRESS_update_TEST_address() {
  c_97759 = TEST_status == 0;
  c_97790 = TEST_cmdaddr == 65283;
  c_97786 = TEST_address.range(15, 8);
  c_97792 = (c_97790) ? TEST_cmddata : c_97786;
  c_97783 = TEST_cmdaddr == 65282;
  c_97779 = TEST_address.range(7, 0);
  c_97785 = (c_97783) ? TEST_cmddata : c_97779;
  c_97797 = (c_97792, c_97785);
  c_97799 = (c_97759) ? c_97797 : TEST_address;
  return c_97799;
};
