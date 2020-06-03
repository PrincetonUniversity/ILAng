#include "systemc.h"
#include "TEST.h"
sc_biguint<16> TEST::decode_TEST_WRITE_ADDRESS_update_TEST_address() {
  c_1690972 = TEST_status == 0;
  c_1691009 = TEST_cmdaddr == 65283;
  c_1691006 = (TEST_cmddata/TEST_cmddata);
  c_1691004 = TEST_address.range(15, 8);
  c_1691011 = (c_1691009) ? c_1691006 : c_1691004;
  c_1691001 = TEST_cmdaddr == 65282;
  c_1690998 = (TEST_cmddata * TEST_cmddata);
  c_1690996 = TEST_address.range(7, 0);
  c_1691003 = (c_1691001) ? c_1690998 : c_1690996;
  c_1691016 = (c_1691011, c_1691003);
  c_1691018 = (c_1690972) ? c_1691016 : TEST_address;
  return c_1691018;
};
