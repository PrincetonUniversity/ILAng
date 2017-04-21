#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_predict_input_done(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1538;
	BIT_VEC cppVar_1524;
	bool cppVar_1525;
	BIT_VEC cppVar_1527;
	bool cppVar_1528;
	BIT_VEC cppVar_1530;
	bool cppVar_1531;
	BIT_VEC cppVar_1533;
	bool cppVar_1534;
	BIT_VEC cppVar_1535;
	bool cppVar_1536;
	bool cppVar_1537;
	BIT_VEC cppVar_1532;
	BIT_VEC cppVar_1529;
	BIT_VEC cppVar_1526;
	BIT_VEC cppVar_1523;
	cppVar_1525 = (predict_upc == 0);
	if (cppVar_1525) {
	cppVar_1523 = predict_input_done;
	} else {
	cppVar_1528 = (predict_upc == 1);
	if (cppVar_1528) {
	cppVar_1526 = predict_input_done;
	} else {
	cppVar_1531 = (predict_upc == 2);
	if (cppVar_1531) {
	cppVar_1534 = (wr_request == 0);
	cppVar_1536 = (wr_complete == 1);
	cppVar_1537 = cppVar_1534 && cppVar_1536;
	if (cppVar_1537) {
	cppVar_1532 = 0;
	} else {
	cppVar_1532 = predict_input_done;
	}
	cppVar_1529 = cppVar_1532;
	} else {
	cppVar_1529 = predict_input_done;
	}
	cppVar_1526 = cppVar_1529;
	}
	cppVar_1523 = cppVar_1526;
	}
	return cppVar_1523;
}
