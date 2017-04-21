#include "common.hpp"
#include "model_predict_class.hpp"

type_mem<BV32,8> model_predict::cppUpdateFun_pow2(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_2023;
	bool cppVar_2024;
	BIT_VEC cppVar_2026;
	bool cppVar_2027;
	BIT_VEC cppVar_2054;
	bool cppVar_2055;
	BIT_VEC cppVar_2029;
	bool cppVar_2030;
	bool cppVar_2031;
	BIT_VEC cppVar_2033;
	bool cppVar_2034;
	bool cppVar_2035;
	BIT_VEC cppVar_2037;
	bool cppVar_2038;
	bool cppVar_2039;
	BIT_VEC cppVar_2046;
	bool cppVar_2047;
	bool cppVar_2048;
	BIT_VEC cppVar_2050;
	bool cppVar_2051;
	bool cppVar_2052;
	BIT_VEC cppVar_2041;
	BIT_VEC cppVar_2042;
	BIT_VEC cppVar_2043;
	BIT_VEC cppVar_2040;
	type_mem<BV32,8> cppVar_2044;
	type_mem<BV32,8> cppVar_2049;
	type_mem<BV32,8> cppVar_2045;
	type_mem<BV32,8> cppVar_2036;
	type_mem<BV32,8> cppVar_2032;
	type_mem<BV32,8> cppVar_2028;
	type_mem<BV32,8> cppVar_2053;
	type_mem<BV32,8> cppVar_2025;
	type_mem<BV32,8> cppVar_2022;
	cppVar_2024 = (predict_upc == 0);
	if (cppVar_2024) {
	cppVar_2022 = pow2;
	} else {
	cppVar_2027 = (predict_upc == 1);
	if (cppVar_2027) {
	cppVar_2030 = (per_v_pc == 0);
	cppVar_2031 = cppVar_2027 && cppVar_2030;
	if (cppVar_2031) {
	cppVar_2028 = pow2;
	} else {
	cppVar_2034 = (per_v_pc == 1);
	cppVar_2035 = cppVar_2027 && cppVar_2034;
	if (cppVar_2035) {
	cppVar_2032 = pow2;
	} else {
	cppVar_2038 = (per_v_pc == 2);
	cppVar_2039 = cppVar_2027 && cppVar_2038;
	if (cppVar_2039) {
	cppVar_2040 = (jstate >> 0) & cppMask_un_3_;
	cppVar_2041 = (jstate >> 0) & cppMask_un_3_;
	cppVar_2042 = visibleEnergies.rd(cppVar_2041);
	cppVar_2043 = to_int_exp(cppVar_2042);
	cppVar_2044 = pow2;
	cppVar_2044.wr(cppVar_2040, cppVar_2043);
	cppVar_2036 = cppVar_2044;
	} else {
	cppVar_2047 = (per_v_pc == 3);
	cppVar_2048 = cppVar_2027 && cppVar_2047;
	if (cppVar_2048) {
	cppVar_2045 = pow2;
	} else {
	cppVar_2051 = (per_v_pc == 4);
	cppVar_2052 = cppVar_2027 && cppVar_2051;
	if (cppVar_2052) {
	cppVar_2049 = pow2;
	} else {
	cppVar_2049 = pow2;
	}
	cppVar_2045 = cppVar_2049;
	}
	cppVar_2036 = cppVar_2045;
	}
	cppVar_2032 = cppVar_2036;
	}
	cppVar_2028 = cppVar_2032;
	}
	cppVar_2025 = cppVar_2028;
	} else {
	cppVar_2055 = (predict_upc == 2);
	if (cppVar_2055) {
	cppVar_2053 = pow2;
	} else {
	cppVar_2053 = pow2;
	}
	cppVar_2025 = cppVar_2053;
	}
	cppVar_2022 = cppVar_2025;
	}
	return cppVar_2022;
}
