#include "TEST.h"
uint16_t TEST::decode_TEST_WRITE_ADDRESS_update_TEST_address() {
  c_739 = TEST_status == 0;
  c_774 = TEST_cmdaddr == 65283;
  uint8_t tmp_770 = 0 - 1;
  c_770 = static_cast<uint8_t> ((TEST_address >> 8) & tmp_770);
  c_776 = (c_774) ? TEST_cmddata : c_770;
  c_767 = TEST_cmdaddr == 65282;
  uint8_t tmp_763 = 0 - 1;
  c_763 = static_cast<uint8_t> ((TEST_address >> 0) & tmp_763);
  c_769 = (c_767) ? TEST_cmddata : c_763;
  c_781 = (static_cast<uint16_t>(c_776) << 8) + (static_cast<uint16_t>(c_769));
  c_783 = (c_739) ? c_781 : TEST_address;
  return c_783;
};
