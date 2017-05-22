#include "common.hpp"
#include "model_train_class.hpp"

BIT_VEC model_train::cppUpdateFun_jstate(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_43;
	BIT_VEC cppVar_35;
	BIT_VEC cppVar_26;
	BIT_VEC cppVar_14;
	BIT_VEC cppVar_52;
	bool cppVar_53;
	BIT_VEC cppVar_51;
	BIT_VEC cppVar_11;
	BIT_VEC cppVar_7;
	BIT_VEC cppVar_8;
	bool cppVar_9;
	BIT_VEC cppVar_10;
	BIT_VEC cppVar_12;
	bool cppVar_13;
	bool cppVar_15;
	BIT_VEC cppVar_16;
	bool cppVar_17;
	bool cppVar_18;
	bool cppVar_20;
	BIT_VEC cppVar_22;
	bool cppVar_23;
	BIT_VEC cppVar_24;
	BIT_VEC cppVar_25;
	BIT_VEC cppVar_21;
	BIT_VEC cppVar_19;
	bool cppVar_27;
	BIT_VEC cppVar_28;
	bool cppVar_29;
	bool cppVar_30;
	bool cppVar_32;
	BIT_VEC cppVar_33;
	BIT_VEC cppVar_34;
	BIT_VEC cppVar_31;
	bool cppVar_36;
	BIT_VEC cppVar_37;
	bool cppVar_38;
	bool cppVar_39;
	bool cppVar_41;
	BIT_VEC cppVar_42;
	BIT_VEC cppVar_40;
	bool cppVar_44;
	BIT_VEC cppVar_45;
	bool cppVar_46;
	bool cppVar_47;
	bool cppVar_49;
	BIT_VEC cppVar_50;
	BIT_VEC cppVar_48;
	cppVar_9 = (train_upc == 0);
	if (cppVar_9) {
	cppVar_7 = 0;
	} else {
	cppVar_13 = (train_upc == 1);
	if (cppVar_13) {
	cppVar_15 = (train_upc == 1);
	cppVar_17 = (per_v_pc == 0);
	cppVar_18 = cppVar_15 && cppVar_17;
	if (cppVar_18) {
	cppVar_20 = (train_h_cnt == num_hidden);
	if (cppVar_20) {
	cppVar_23 = (jstate == 4);
	if (cppVar_23) {
	cppVar_21 = 0;
	} else {
	cppVar_25 = jstate + 1;
	cppVar_25 = (cppVar_25 & cppMask_un_16_);
	cppVar_21 = cppVar_25;
	}
	cppVar_19 = cppVar_21;
	} else {
	cppVar_19 = jstate;
	}
	cppVar_14 = cppVar_19;
	} else {
	cppVar_27 = (train_upc == 1);
	cppVar_29 = (per_v_pc == 1);
	cppVar_30 = cppVar_27 && cppVar_29;
	if (cppVar_30) {
	cppVar_32 = (jstate == 4);
	if (cppVar_32) {
	cppVar_31 = 0;
	} else {
	cppVar_34 = jstate + 1;
	cppVar_34 = (cppVar_34 & cppMask_un_16_);
	cppVar_31 = cppVar_34;
	}
	cppVar_26 = cppVar_31;
	} else {
	cppVar_36 = (train_upc == 1);
	cppVar_38 = (per_v_pc == 2);
	cppVar_39 = cppVar_36 && cppVar_38;
	if (cppVar_39) {
	cppVar_41 = (jstate == 4);
	if (cppVar_41) {
	cppVar_40 = 0;
	} else {
	cppVar_42 = jstate + 1;
	cppVar_42 = (cppVar_42 & cppMask_un_16_);
	cppVar_40 = cppVar_42;
	}
	cppVar_35 = cppVar_40;
	} else {
	cppVar_44 = (train_upc == 1);
	cppVar_46 = (per_v_pc == 3);
	cppVar_47 = cppVar_44 && cppVar_46;
	if (cppVar_47) {
	cppVar_49 = (jstate == 4);
	if (cppVar_49) {
	cppVar_48 = 0;
	} else {
	cppVar_50 = jstate + 1;
	cppVar_50 = (cppVar_50 & cppMask_un_16_);
	cppVar_48 = cppVar_50;
	}
	cppVar_43 = cppVar_48;
	} else {
	cppVar_43 = jstate;
	}
	cppVar_35 = cppVar_43;
	}
	cppVar_26 = cppVar_35;
	}
	cppVar_14 = cppVar_26;
	}
	cppVar_11 = cppVar_14;
	} else {
	cppVar_53 = (train_upc == 2);
	if (cppVar_53) {
	cppVar_51 = jstate;
	} else {
	cppVar_51 = jstate;
	}
	cppVar_11 = cppVar_51;
	}
	cppVar_7 = cppVar_11;
	}
	return cppVar_7;
}
