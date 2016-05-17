#include "common.hpp"
#include "model_aes_class.hpp"

void model_aes::update(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_42 = cppUpdateFun_aes_addr(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_247 = cppUpdateFun_aes_ctr(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_452 = cppUpdateFun_aes_key0(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_657 = cppUpdateFun_aes_key1(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_668 = cppUpdateFun_aes_keysel(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_691 = cppUpdateFun_aes_len(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_5313 = cppUpdateFun_aes_state(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_6481 = cppUpdateFun_byte_cnt(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_11145 = cppUpdateFun_dataout(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_15761 = cppUpdateFun_enc_data(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_16917 = cppUpdateFun_rd_data(cmd, cmdaddr, cmddata);
	type_mem cppVar_18074 = cppUpdateFun_XRAM(cmd, cmdaddr, cmddata);
	aes_addr = cppVar_42;
	aes_ctr = cppVar_247;
	aes_key0 = cppVar_452;
	aes_key1 = cppVar_657;
	aes_keysel = cppVar_668;
	aes_len = cppVar_691;
	aes_state = cppVar_5313;
	byte_cnt = cppVar_6481;
	dataout = cppVar_11145;
	enc_data = cppVar_15761;
	rd_data = cppVar_16917;
	XRAM = cppVar_18074;
	return;
}
