#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_expectation(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1325;
	bool cppVar_1326;
	BIT_VEC cppVar_1328;
	bool cppVar_1329;
	BIT_VEC cppVar_1337;
	BIT_VEC cppVar_1351;
	bool cppVar_1352;
	BIT_VEC cppVar_1331;
	bool cppVar_1332;
	bool cppVar_1333;
	BIT_VEC cppVar_1338;
	BIT_VEC cppVar_1339;
	BIT_VEC cppVar_1340;
	BIT_VEC cppVar_1341;
	BIT_VEC cppVar_1342;
	BIT_VEC cppVar_1343;
	BIT_VEC cppVar_1335;
	bool cppVar_1336;
	BIT_VEC cppVar_1334;
	BIT_VEC cppVar_1344;
	BIT_VEC cppVar_1345;
	BIT_VEC cppVar_1346;
	BIT_VEC cppVar_1347;
	BIT_VEC cppVar_1348;
	BIT_VEC cppVar_1349;
	BIT_VEC cppVar_1330;
	BIT_VEC cppVar_1350;
	BIT_VEC cppVar_1327;
	BIT_VEC cppVar_1324;
	cppVar_1326 = (predict_upc == 0);
	if (cppVar_1326) {
	cppVar_1324 = expectation;
	} else {
	cppVar_1329 = (predict_upc == 1);
	if (cppVar_1329) {
	cppVar_1332 = (per_v_pc == 3);
	cppVar_1333 = cppVar_1329 && cppVar_1332;
	if (cppVar_1333) {
	cppVar_1336 = (jstate == 0);
	if (cppVar_1336) {
	cppVar_1334 = 0;
	} else {
	cppVar_1334 = expectation;
	}
	cppVar_1338 = (jstate >> 0) & cppMask_un_3_;
	cppVar_1339 = pow2.rd(cppVar_1338);
	cppVar_1340 = divide(cppVar_1339, sumOfpow2);
	cppVar_1341 = (cppVar_1340 & cppMask_un_64_);
	cppVar_1342 = (jstate & cppMask_un_16_);
	cppVar_1343 = cppVar_1341 * cppVar_1342;
	cppVar_1343 = (cppVar_1343 & cppMask_un_80_);
	cppVar_1344 = (cppVar_1343 >> 63) & cppMask_un_17_;
	cppVar_1345 = (cppVar_1344 >> 0) & cppMask_un_3_;
	cppVar_1346 = (cppVar_1343 >> 0) & cppMask_un_63_;
	cppVar_1347 = (cppVar_1346 >> 34) & cppMask_un_29_;
	cppVar_1348 = (cppVar_1345 << 29) | cppVar_1347;
	cppVar_1348 = (cppVar_1348 & cppMask_un_32_);
	cppVar_1349 = cppVar_1334 + cppVar_1348;
	cppVar_1349 = (cppVar_1349 & cppMask_un_32_);
	cppVar_1330 = cppVar_1349;
	} else {
	cppVar_1330 = expectation;
	}
	cppVar_1327 = cppVar_1330;
	} else {
	cppVar_1352 = (predict_upc == 2);
	if (cppVar_1352) {
	cppVar_1350 = expectation;
	} else {
	cppVar_1350 = expectation;
	}
	cppVar_1327 = cppVar_1350;
	}
	cppVar_1324 = cppVar_1327;
	}
	return cppVar_1324;
}
