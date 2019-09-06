#include "systemc.h"
#include "test.h"
sc_biguint<16> TEST::decode_115572_update_TEST_address() {
  c_115549 = TEST_status == 0;
  c_115584 = TEST_cmdaddr == 65283;
  c_115580 = TEST_address.range(15, 8);
  c_115586 = (c_115584) ? TEST_cmddata : c_115580;
  c_115577 = TEST_cmdaddr == 65282;
  c_115573 = TEST_address.range(7, 0);
  c_115579 = (c_115577) ? TEST_cmddata : c_115573;
  c_115591 = (c_115586, c_115579);
  c_115593 = (c_115549) ? c_115591 : TEST_address;
  return c_115593;
};
