#include "systemc.h"
#include "test.h"
void TEST::compute() {
  if (decode_98909_update_TEST_XRAM_iter < decode_98909_update_TEST_XRAM_map.size()) {
    TEST_XRAM_write_valid.write(1);
    std::map<int, int>::iterator it = decode_98909_update_TEST_XRAM_map.begin();
    for (int i = 0; i < decode_98909_update_TEST_XRAM_iter; i++)
      it++;
    TEST_XRAM_write_address.write(it->first);
    TEST_XRAM_write_data.write(it->second);
  }
  if (decode_98909_update_TEST_XRAM_iter < decode_98909_update_TEST_XRAM_map.size()) {
    if (TEST_XRAM_write_ready.read() == 1) 
      decode_98909_update_TEST_XRAM_iter++;
    return;
  }
  if (c_98619_ctrl == 1) {
    if (TEST_XRAM_read_valid.read() == 1) {
      c_98619_ctrl = 2;
      c_98619 = TEST_XRAM_data.read();
      TEST_XRAM_read_ready.write(0);
    } else {
      TEST_XRAM_read_address.write(c_98618.to_int());
      TEST_XRAM_read_ready.write(1);
      return;
    }
  }
  if ((c_98619_ctrl == 0) & 1) {
    TEST_cmd = TEST_cmd_in.read();
    TEST_cmdaddr = TEST_cmdaddr_in.read();
    TEST_cmddata = TEST_cmddata_in.read();
    TEST_cmdflag = TEST_cmdflag_in.read();
  }
  if (decode_98537()) {
cout << "decode_98537" << endl;
    sc_biguint<16> TEST_address_next = decode_98537_update_TEST_address();
    bool TEST_flag_next = decode_98537_update_TEST_flag();
    TEST_address = TEST_address_next;
    TEST_flag = TEST_flag_next;
  }
  if (decode_98574()) {
cout << "decode_98574" << endl;
    sc_biguint<2> TEST_status_next = decode_98574_update_TEST_status();
    TEST_status = TEST_status_next;
  }
  while (1) {
    int schedule_counter = 0;
    if (decode_98610()) {
cout << "decode_98610" << endl;
      sc_biguint<4> ENCRYPT_byte_cnt_next = decode_98610_update_ENCRYPT_byte_cnt();
      sc_biguint<128> ENCRYPT_rd_data_next = decode_98610_update_ENCRYPT_rd_data();
      sc_biguint<2> TEST_status_next = decode_98610_update_TEST_status();
      if (((c_98619_ctrl == 0) | (c_98619_ctrl == 2)) & 1) {
        ENCRYPT_byte_cnt = ENCRYPT_byte_cnt_next;
        ENCRYPT_rd_data = ENCRYPT_rd_data_next;
        TEST_status = TEST_status_next;
        schedule_counter++;
      }
    }
    if (decode_98887()) {
cout << "decode_98887" << endl;
      sc_biguint<128> ENCRYPT_enc_data_next = decode_98887_update_ENCRYPT_enc_data();
      sc_biguint<2> TEST_status_next = decode_98887_update_TEST_status();
      ENCRYPT_enc_data = ENCRYPT_enc_data_next;
      TEST_status = TEST_status_next;
      schedule_counter++;
    }
    if (decode_98909()) {
cout << "decode_98909" << endl;
      decode_98909_update_TEST_XRAM(decode_98909_update_TEST_XRAM_map);
      sc_biguint<16> ENCRYPT_blk_cnt_next = decode_98909_update_ENCRYPT_blk_cnt();
      sc_biguint<4> ENCRYPT_byte_cnt_next = decode_98909_update_ENCRYPT_byte_cnt();
      sc_biguint<2> TEST_status_next = decode_98909_update_TEST_status();
      ENCRYPT_blk_cnt = ENCRYPT_blk_cnt_next;
      ENCRYPT_byte_cnt = ENCRYPT_byte_cnt_next;
      TEST_status = TEST_status_next;
      schedule_counter++;
    }
    if (schedule_counter == 0) 
      break;
  }
  if ((decode_98909_update_TEST_XRAM_iter < decode_98909_update_TEST_XRAM_map.size()))
    return;
  if ((c_98619_ctrl == 1))
    return;
  c_98619_ctrl = 0;
  decode_98909_update_TEST_XRAM_map.clear();
  decode_98909_update_TEST_XRAM_iter = 0;
  TEST_status_out.write(TEST_status);
  TEST_address_out.write(TEST_address);
  TEST_length_out.write(TEST_length);
  TEST_counter_out.write(TEST_counter);
  TEST_flag_out.write(TEST_flag);
};
