#include "common.hpp"
#include "model_sha_class.hpp"

void model_sha::update(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_1463 = cppUpdateFun_dataout(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_1767 = cppUpdateFun_sha_bytes_read(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_2057 = cppUpdateFun_sha_hs_data(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_2080 = cppUpdateFun_sha_len(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_2372 = cppUpdateFun_sha_rd_data(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_2395 = cppUpdateFun_sha_rdaddr(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_3847 = cppUpdateFun_sha_state(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_3870 = cppUpdateFun_sha_wraddr(cmd, cmdaddr, cmddata);
	type_mem cppVar_5602 = cppUpdateFun_XRAM(cmd, cmdaddr, cmddata);
	dataout = cppVar_1463;
	sha_bytes_read = cppVar_1767;
	sha_hs_data = cppVar_2057;
	sha_len = cppVar_2080;
	sha_rd_data = cppVar_2372;
	sha_rdaddr = cppVar_2395;
	sha_state = cppVar_3847;
	sha_wraddr = cppVar_3870;
	XRAM = cppVar_5602;
	return;
}
