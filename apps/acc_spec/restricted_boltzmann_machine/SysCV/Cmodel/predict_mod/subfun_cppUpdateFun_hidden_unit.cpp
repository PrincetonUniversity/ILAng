#include "common.hpp"
#include "model_predict_class.hpp"

type_mem<BV1,128> model_predict::cppUpdateFun_hidden_unit(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_2011;
	BIT_VEC cppVar_2010;
	BIT_VEC cppVar_1968;
	bool cppVar_1969;
	BIT_VEC cppVar_2016;
	bool cppVar_2017;
	BIT_VEC cppVar_2019;
	bool cppVar_2020;
	BIT_VEC cppVar_1998;
	BIT_VEC cppVar_1999;
	BIT_VEC cppVar_2000;
	BIT_VEC cppVar_1990;
	bool cppVar_1991;
	BIT_VEC cppVar_1992;
	BIT_VEC cppVar_1989;
	BIT_VEC cppVar_1994;
	BIT_VEC cppVar_1995;
	BIT_VEC cppVar_1996;
	bool cppVar_1997;
	BIT_VEC cppVar_2001;
	BIT_VEC cppVar_2002;
	BIT_VEC cppVar_2003;
	BIT_VEC cppVar_2004;
	BIT_VEC cppVar_2005;
	BIT_VEC cppVar_2006;
	BIT_VEC cppVar_1993;
	BIT_VEC cppVar_2007;
	BIT_VEC cppVar_1980;
	BIT_VEC cppVar_1981;
	BIT_VEC cppVar_1982;
	BIT_VEC cppVar_1983;
	BIT_VEC cppVar_1984;
	BIT_VEC cppVar_1985;
	BIT_VEC cppVar_1986;
	BIT_VEC cppVar_1987;
	BIT_VEC cppVar_1988;
	BIT_VEC cppVar_2008;
	bool cppVar_2009;
	BIT_VEC cppVar_1979;
	bool cppVar_1977;
	BIT_VEC cppVar_1978;
	type_mem<BV1,128> cppVar_2012;
	type_mem<BV1,128> cppVar_1976;
	bool cppVar_1971;
	BIT_VEC cppVar_1972;
	BIT_VEC cppVar_1973;
	bool cppVar_1974;
	bool cppVar_1975;
	BIT_VEC cppVar_2013;
	type_mem<BV1,128> cppVar_2014;
	type_mem<BV1,128> cppVar_1970;
	type_mem<BV1,128> cppVar_2018;
	type_mem<BV1,128> cppVar_2015;
	type_mem<BV1,128> cppVar_1967;
	cppVar_1969 = (predict_upc == 0);
	if (cppVar_1969) {
	cppVar_1971 = (predict_v_cnt == num_visible);
	cppVar_1973 = num_hidden - 1;
	cppVar_1973 = (cppVar_1973 & cppMask_un_16_);
	cppVar_1974 = (predict_h_cnt == cppVar_1973);
	cppVar_1975 = cppVar_1971 && cppVar_1974;
	if (cppVar_1975) {
	cppVar_1977 = (predict_v_cnt == num_visible);
	if (cppVar_1977) {
	cppVar_1978 = (predict_h_cnt >> 0) & cppMask_un_7_;
	cppVar_1983 = 0 << 0;
	cppVar_1983 = (cppVar_1983 & cppMask_un_64_);
	cppVar_1984 = 0 | cppVar_1983;
	cppVar_1987 = 1073741824 << 32;
	cppVar_1987 = (cppVar_1987 & cppMask_un_64_);
	cppVar_1988 = cppVar_1984 | cppVar_1987;
	cppVar_1991 = (predict_v_cnt == 0);
	if (cppVar_1991) {
	cppVar_1989 = 0;
	} else {
	cppVar_1989 = predict_sum;
	}
	cppVar_1994 = (predict_v_cnt >> 0) & cppMask_un_9_;
	cppVar_1995 = data.rd(cppVar_1994);
	cppVar_1997 = (cppVar_1995 == 1);
	if (cppVar_1997) {
	cppVar_1999 = 101 * predict_v_cnt;
	cppVar_1999 = (cppVar_1999 & cppMask_un_16_);
	cppVar_2000 = cppVar_1999 + predict_h_cnt;
	cppVar_2000 = (cppVar_2000 & cppMask_un_16_);
	cppVar_2001 = edges.rd(cppVar_2000);
	cppVar_2002 = (cppVar_2001 >> 1) & cppMask_un_7_;
	cppVar_2003 = ((cppVar_2002 & cppMask_bit_7_) ? (cppVar_2002 | cppMask_sign_7_) : cppVar_2002);
	cppVar_2004 = (cppVar_2001 >> 0) & cppMask_un_1_;
	cppVar_2005 = (cppVar_2003 << 1) | cppVar_2004;
	cppVar_2005 = (cppVar_2005 & cppMask_un_16_);
	cppVar_1993 = cppVar_2005;
	} else {
	cppVar_1993 = 0;
	}
	cppVar_2007 = cppVar_1989 + cppVar_1993;
	cppVar_2007 = (cppVar_2007 & cppMask_un_16_);
	cppVar_2008 = sigmoid(cppVar_2007);
	cppVar_2009 = cppVar_1988 < cppVar_2008;
	if (cppVar_2009) {
	cppVar_1979 = 1;
	} else {
	cppVar_1979 = 0;
	}
	cppVar_2012 = hidden_unit;
	cppVar_2012.wr(cppVar_1978, cppVar_1979);
	cppVar_1976 = cppVar_2012;
	} else {
	cppVar_1976 = hidden_unit;
	}
	cppVar_2013 = (num_hidden >> 0) & cppMask_un_7_;
	cppVar_2014 = cppVar_1976;
	cppVar_2014.wr(cppVar_2013, 1);
	cppVar_1970 = cppVar_2014;
	} else {
	cppVar_1970 = cppVar_1976;
	}
	cppVar_1967 = cppVar_1970;
	} else {
	cppVar_2017 = (predict_upc == 1);
	if (cppVar_2017) {
	cppVar_2015 = hidden_unit;
	} else {
	cppVar_2020 = (predict_upc == 2);
	if (cppVar_2020) {
	cppVar_2018 = hidden_unit;
	} else {
	cppVar_2018 = hidden_unit;
	}
	cppVar_2015 = cppVar_2018;
	}
	cppVar_1967 = cppVar_2015;
	}
	return cppVar_1967;
}
