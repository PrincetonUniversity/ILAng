#include "common.hpp"
#include "model_aes_class.hpp"

void model_aes::update(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_59 = cppUpdateFun_aes_addr(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_264 = cppUpdateFun_aes_ctr(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_469 = cppUpdateFun_aes_key0(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_674 = cppUpdateFun_aes_key1(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_685 = cppUpdateFun_aes_keysel(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_708 = cppUpdateFun_aes_len(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_1183 = cppUpdateFun_aes_state(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_4134 = cppUpdateFun_dataout(cmd, cmdaddr, cmddata);
	type_mem cppVar_4145 = cppUpdateFun_XRAM(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_4158 = cppUpdateFun_byte_cnt(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_4169 = cppUpdateFun_enc_data(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_4179 = cppUpdateFun_rd_data(cmd, cmdaddr, cmddata);
	aes_addr = cppVar_59;
	aes_ctr = cppVar_264;
	aes_key0 = cppVar_469;
	aes_key1 = cppVar_674;
	aes_keysel = cppVar_685;
	aes_len = cppVar_708;
	aes_state = cppVar_1183;
	dataout = cppVar_4134;
	XRAM = cppVar_4145;
	byte_cnt = cppVar_4158;
	enc_data = cppVar_4169;
	rd_data = cppVar_4179;
	return;
}
