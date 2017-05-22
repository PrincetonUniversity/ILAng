#include "common.hpp"
#include "model_train_class.hpp"

type_mem<BV1,65536> model_train::cppUpdateFun_pos(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1039;
	bool cppVar_1040;
	BIT_VEC cppVar_1045;
	BIT_VEC cppVar_1046;
	BIT_VEC cppVar_1047;
	bool cppVar_1048;
	BIT_VEC cppVar_1044;
	BIT_VEC cppVar_1051;
	BIT_VEC cppVar_1052;
	BIT_VEC cppVar_1053;
	BIT_VEC cppVar_1041;
	BIT_VEC cppVar_1042;
	BIT_VEC cppVar_1043;
	type_mem<BV1,65536> cppVar_1054;
	BIT_VEC cppVar_1050;
	BIT_VEC cppVar_1049;
	type_mem<BV1,65536> cppVar_1038;
	cppVar_1040 = (train_upc == 3);
	if (cppVar_1040 && data.rd((train_v_cnt >> 0) & cppMask_un_9_)  != 2) {
	cppVar_1042 = 101 * train_v_cnt;
	cppVar_1042 = (cppVar_1042 & cppMask_un_16_);
	cppVar_1043 = cppVar_1042 + train_h_cnt;
	cppVar_1043 = (cppVar_1043 & cppMask_un_16_);
	cppVar_1045 = (train_v_cnt >> 0) & cppMask_un_9_;
	cppVar_1046 = data.rd(cppVar_1045);
	cppVar_1048 = (cppVar_1046 != 0);
	if (cppVar_1048) {
	cppVar_1044 = 1;
	} else {
	cppVar_1044 = 0;
	}
	cppVar_1051 = (train_h_cnt >> 0) & cppMask_un_7_;
	cppVar_1052 = hidden_unit.rd(cppVar_1051);
	cppVar_1053 = cppVar_1044 & cppVar_1052;
	cppVar_1054 = pos;
	cppVar_1054.wr(cppVar_1043, cppVar_1053);
	cppVar_1038 = cppVar_1054;
	} else {
	cppVar_1038 = pos;
	}
	return cppVar_1038;
}
