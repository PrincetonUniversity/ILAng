#include "common.hpp"
#include "model_aes_class.hpp"

void model_aes::update(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_61 = cppUpdateFun_aes_addr(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_266 = cppUpdateFun_aes_ctr(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_471 = cppUpdateFun_aes_key0(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_676 = cppUpdateFun_aes_key1(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_687 = cppUpdateFun_aes_keysel(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_710 = cppUpdateFun_aes_len(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_904 = cppUpdateFun_aes_state(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_3855 = cppUpdateFun_dataout(cmd, cmdaddr, cmddata);
	type_mem cppVar_4035 = cppUpdateFun_XRAM(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_4051 = cppUpdateFun_blk_cnt(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_4256 = cppUpdateFun_byte_cnt(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_4267 = cppUpdateFun_enc_data(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_4279 = cppUpdateFun_oped_byte_cnt(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_4587 = cppUpdateFun_rd_data(cmd, cmdaddr, cmddata);
	aes_addr = cppVar_61;
	aes_ctr = cppVar_266;
	aes_key0 = cppVar_471;
	aes_key1 = cppVar_676;
	aes_keysel = cppVar_687;
	aes_len = cppVar_710;
	aes_state = cppVar_904;
	dataout = cppVar_3855;
	XRAM = cppVar_4035;
	blk_cnt = cppVar_4051;
	byte_cnt = cppVar_4256;
	enc_data = cppVar_4267;
	oped_byte_cnt = cppVar_4279;
	rd_data = cppVar_4587;
	return;
}
