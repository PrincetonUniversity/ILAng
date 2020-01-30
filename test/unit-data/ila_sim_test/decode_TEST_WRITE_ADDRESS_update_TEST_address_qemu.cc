#include "TEST.h"
uint16_t TEST::decode_TEST_WRITE_ADDRESS_update_TEST_address() {
  c_1693073 = TEST_status == 0;
  c_1693110 = TEST_cmdaddr == 65283;
  c_1693107 = (TEST_cmddata/TEST_cmddata);
  uint8_t tmp_1693105 = 0 - 1;
  c_1693105 = static_cast<uint8_t> ((TEST_address >> 8) & tmp_1693105);
  c_1693112 = (c_1693110) ? c_1693107 : c_1693105;
  c_1693102 = TEST_cmdaddr == 65282;
  c_1693099 = (TEST_cmddata * TEST_cmddata);
  uint8_t tmp_1693097 = 0 - 1;
  c_1693097 = static_cast<uint8_t> ((TEST_address >> 0) & tmp_1693097);
  c_1693104 = (c_1693102) ? c_1693099 : c_1693097;
  c_1693117 = (static_cast<uint16_t>(c_1693112) << 8) + (static_cast<uint16_t>(c_1693104));
  c_1693119 = (c_1693073) ? c_1693117 : TEST_address;
  return c_1693119;
};
