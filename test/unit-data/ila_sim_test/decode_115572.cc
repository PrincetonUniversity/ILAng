#include "systemc.h"
#include "test.h"
bool TEST::decode_115572() {
  c_115544 = TEST_cmd == 1;
  c_115540 = TEST_cmd == 2;
  c_115546 = (c_115544 | c_115540);
  if (!c_115546) {
    return false;
  }
  c_115569 = TEST_cmd == 2;
  c_115562 = TEST_cmdaddr == 65282;
  c_115564 = TEST_cmdaddr > 65282;
  c_115566 = (c_115562 | c_115564);
  c_115571 = (c_115569 & c_115566);
  c_115558 = TEST_cmdaddr < 65284;
  c_115572 = (c_115571 & c_115558);
  return c_115572;
};
