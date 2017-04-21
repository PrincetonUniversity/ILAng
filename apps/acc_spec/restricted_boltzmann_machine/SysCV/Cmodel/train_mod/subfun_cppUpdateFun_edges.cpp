#include "common.hpp"
#include "model_train_class.hpp"

type_mem<BV8,65536> model_train::cppUpdateFun_edges(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_949;
	bool cppVar_950;
	BIT_VEC cppVar_952;
	bool cppVar_953;
	BIT_VEC cppVar_955;
	bool cppVar_956;
	BIT_VEC cppVar_961;
	BIT_VEC cppVar_962;
	BIT_VEC cppVar_963;
	BIT_VEC cppVar_964;
	BIT_VEC cppVar_965;
	bool cppVar_966;
	BIT_VEC cppVar_967;
	BIT_VEC cppVar_968;
	BIT_VEC cppVar_969;
	bool cppVar_970;
	BIT_VEC cppVar_971;
	BIT_VEC cppVar_972;
	BIT_VEC cppVar_973;
	bool cppVar_974;
	bool cppVar_975;
	BIT_VEC cppVar_978;
	BIT_VEC cppVar_979;
	BIT_VEC cppVar_980;
	BIT_VEC cppVar_981;
	bool cppVar_976;
	bool cppVar_977;
	BIT_VEC cppVar_982;
	BIT_VEC cppVar_983;
	bool cppVar_985;
	bool cppVar_986;
	BIT_VEC cppVar_987;
	BIT_VEC cppVar_988;
	BIT_VEC cppVar_984;
	BIT_VEC cppVar_960;
	BIT_VEC cppVar_957;
	BIT_VEC cppVar_958;
	BIT_VEC cppVar_959;
	type_mem<BV8,65536> cppVar_989;
	type_mem<BV8,65536> cppVar_954;
	type_mem<BV8,65536> cppVar_951;
	type_mem<BV8,65536> cppVar_948;
	cppVar_950 = (train_upc == 0);
	if (cppVar_950) {
	cppVar_948 = edges;
	} else {
	cppVar_953 = (train_upc == 1);
	if (cppVar_953) {
	cppVar_951 = edges;
	} else {
	cppVar_956 = (train_upc == 2);
	if (cppVar_956) {
	cppVar_958 = 101 * train_v_cnt;
	cppVar_958 = (cppVar_958 & cppMask_un_16_);
	cppVar_959 = cppVar_958 + train_h_cnt;
	cppVar_959 = (cppVar_959 & cppMask_un_16_);
	cppVar_962 = 101 * train_v_cnt;
	cppVar_962 = (cppVar_962 & cppMask_un_16_);
	cppVar_963 = cppVar_962 + train_h_cnt;
	cppVar_963 = (cppVar_963 & cppMask_un_16_);
	cppVar_964 = pos.rd(cppVar_963);
	cppVar_966 = (cppVar_964 != 0);
	cppVar_967 = (train_h_cnt >> 0) & cppMask_un_7_;
	cppVar_968 = hidden_unit.rd(cppVar_967);
	cppVar_970 = (cppVar_968 != 0);
	cppVar_971 = (train_v_cnt >> 0) & cppMask_un_9_;
	cppVar_972 = visible_unit.rd(cppVar_971);
	cppVar_974 = (cppVar_972 != 0);
	cppVar_975 = cppVar_970 && cppVar_974;
	cppVar_976 = !cppVar_975;
	cppVar_977 = cppVar_966 && cppVar_976;
	if (cppVar_977) {
	cppVar_979 = 101 * train_v_cnt;
	cppVar_979 = (cppVar_979 & cppMask_un_16_);
	cppVar_980 = cppVar_979 + train_h_cnt;
	cppVar_980 = (cppVar_980 & cppMask_un_16_);
	cppVar_981 = edges.rd(cppVar_980);
	cppVar_983 = cppVar_981 + 1;
	cppVar_983 = (cppVar_983 & cppMask_un_8_);
	cppVar_960 = cppVar_983;
	} else {
	cppVar_985 = !cppVar_966;
	cppVar_986 = cppVar_985 && cppVar_975;
	if (cppVar_986) {
	cppVar_988 = cppVar_981 - 1;
	cppVar_988 = (cppVar_988 & cppMask_un_8_);
	cppVar_984 = cppVar_988;
	} else {
	cppVar_984 = cppVar_981;
	}
	cppVar_960 = cppVar_984;
	}
	cppVar_989 = edges;
	cppVar_989.wr(cppVar_959, cppVar_960);
	cppVar_954 = cppVar_989;
	} else {
	cppVar_954 = edges;
	}
	cppVar_951 = cppVar_954;
	}
	cppVar_948 = cppVar_951;
	}
	return cppVar_948;
}
