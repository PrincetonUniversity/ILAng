#include "common.hpp"
#include "model_sha_class.hpp"

void model_sha::update(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_914 = cppUpdateFun_dataout(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_937 = cppUpdateFun_sha_len(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_960 = cppUpdateFun_sha_rdaddr(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_1014 = cppUpdateFun_sha_state(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_1037 = cppUpdateFun_sha_wraddr(cmd, cmdaddr, cmddata);
	type_mem cppVar_1047 = cppUpdateFun_XRAM(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_1056 = cppUpdateFun_sha_bytes_read(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_1064 = cppUpdateFun_sha_hs_data(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_1074 = cppUpdateFun_sha_rd_data(cmd, cmdaddr, cmddata);
	dataout = cppVar_914;
	sha_len = cppVar_937;
	sha_rdaddr = cppVar_960;
	sha_state = cppVar_1014;
	sha_wraddr = cppVar_1037;
	XRAM = cppVar_1047;
	sha_bytes_read = cppVar_1056;
	sha_hs_data = cppVar_1064;
	sha_rd_data = cppVar_1074;
	return;
}
