#include "common.hpp"
#include "model_sha_class.hpp"

BIT_VEC model_sha::cppUpdateFun_sha_state(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_961;
	bool cppVar_963 = (sha_state != 0);
	if (cppVar_963) {
	BIT_VEC cppVar_964;
	bool cppVar_966 = (sha_state == 4);
	if (cppVar_966) {
	cppVar_964 = 0;
	} else {
	BIT_VEC cppVar_968;
	bool cppVar_970 = (sha_state == 3);
	if (cppVar_970) {
	BIT_VEC cppVar_971;
	bool cppVar_972 = sha_bytes_read < sha_len;
	if (cppVar_972) {
	cppVar_971 = 1;
	} else {
	cppVar_971 = 4;
	}
	cppVar_968 = cppVar_971;
	} else {
	BIT_VEC cppVar_975;
	bool cppVar_977 = (sha_state == 2);
	if (cppVar_977) {
	cppVar_975 = 3;
	} else {
	BIT_VEC cppVar_979;
	bool cppVar_981 = (sha_state == 1);
	if (cppVar_981) {
	cppVar_979 = 2;
	} else {
	cppVar_979 = sha_state;
	}
	cppVar_975 = cppVar_979;
	}
	cppVar_968 = cppVar_975;
	}
	cppVar_964 = cppVar_968;
	}
	cppVar_961 = cppVar_964;
	} else {
	BIT_VEC cppVar_983;
	bool cppVar_985 = (sha_state == 0);
	bool cppVar_987 = (cmd == 2);
	bool cppVar_988 = cppVar_985 && cppVar_987;
	bool cppVar_990 = (cmdaddr == 65024);
	bool cppVar_991 = cppVar_988 && cppVar_990;
	if (cppVar_991) {
	BIT_VEC cppVar_992;
	bool cppVar_994 = (cmddata == 1);
	if (cppVar_994) {
	cppVar_992 = 1;
	} else {
	cppVar_992 = sha_state;
	}
	cppVar_983 = cppVar_992;
	} else {
	cppVar_983 = sha_state;
	}
	cppVar_961 = cppVar_983;
	}
	return cppVar_961;
}
