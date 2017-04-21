#include "common.hpp"
#include "model_train_class.hpp"

BIT_VEC model_train::cppUpdateFun_train_max(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_721;
	bool cppVar_722;
	BIT_VEC cppVar_724;
	bool cppVar_725;
	BIT_VEC cppVar_775;
	bool cppVar_776;
	BIT_VEC cppVar_742;
	BIT_VEC cppVar_743;
	BIT_VEC cppVar_744;
	bool cppVar_731;
	BIT_VEC cppVar_727;
	bool cppVar_728;
	bool cppVar_729;
	BIT_VEC cppVar_758;
	bool cppVar_759;
	bool cppVar_760;
	BIT_VEC cppVar_767;
	bool cppVar_768;
	bool cppVar_769;
	BIT_VEC cppVar_771;
	bool cppVar_772;
	bool cppVar_773;
	BIT_VEC cppVar_734;
	bool cppVar_735;
	BIT_VEC cppVar_733;
	BIT_VEC cppVar_738;
	BIT_VEC cppVar_739;
	BIT_VEC cppVar_740;
	bool cppVar_741;
	BIT_VEC cppVar_745;
	BIT_VEC cppVar_746;
	BIT_VEC cppVar_747;
	BIT_VEC cppVar_748;
	BIT_VEC cppVar_749;
	BIT_VEC cppVar_737;
	BIT_VEC cppVar_750;
	BIT_VEC cppVar_752;
	bool cppVar_753;
	BIT_VEC cppVar_754;
	BIT_VEC cppVar_755;
	BIT_VEC cppVar_751;
	bool cppVar_756;
	BIT_VEC cppVar_732;
	BIT_VEC cppVar_730;
	BIT_VEC cppVar_764;
	BIT_VEC cppVar_762;
	bool cppVar_763;
	BIT_VEC cppVar_765;
	BIT_VEC cppVar_761;
	BIT_VEC cppVar_770;
	BIT_VEC cppVar_766;
	BIT_VEC cppVar_757;
	BIT_VEC cppVar_726;
	BIT_VEC cppVar_774;
	BIT_VEC cppVar_723;
	BIT_VEC cppVar_720;
	BIT_VEC cppVar_736;
	cppVar_722 = (train_upc == 0);
	if (cppVar_722) {
	cppVar_720 = train_max;
	} else {
		cppVar_725 = (train_upc == 1);
		if (cppVar_725) {
			cppVar_728 = (per_v_pc == 0);
			cppVar_729 = cppVar_725 && cppVar_728;
			if (cppVar_729) {
				cppVar_731 = (train_h_cnt == num_hidden);
				if (cppVar_731) {
				cppVar_735 = (train_h_cnt == 0);
				if (cppVar_735) {
				cppVar_733 = 0;
				} else {
				cppVar_733 = train_sum;
				}
				cppVar_738 = (train_h_cnt >> 0) & cppMask_un_7_;
				cppVar_739 = hidden_unit.rd(cppVar_738);
				cppVar_741 = (cppVar_739 == 1);
				if (cppVar_741) {
				cppVar_743 = 101 * train_v_cnt;
				cppVar_743 = (cppVar_743 & cppMask_un_16_);
				cppVar_744 = cppVar_743 + train_h_cnt;
				cppVar_744 = (cppVar_744 & cppMask_un_16_);
				cppVar_745 = edges.rd(cppVar_744);
				cppVar_746 = (cppVar_745 >> 1) & cppMask_un_7_;
				cppVar_747 = ((cppVar_746 & cppMask_bit_7_) ? (cppVar_746 | cppMask_sign_7_) : cppVar_746);
				cppVar_748 = (cppVar_745 >> 0) & cppMask_un_1_;
				cppVar_749 = (cppVar_747 << 1) | cppVar_748;
				cppVar_749 = (cppVar_749 & cppMask_un_16_);
				cppVar_737 = cppVar_749;
				} else {
				cppVar_737 = 0;
				}
				cppVar_750 = cppVar_733 + cppVar_737;
				cppVar_750 = (cppVar_750 & cppMask_un_16_);
				cppVar_753 = (jstate == 0);
				if (cppVar_753) {
				cppVar_755 = -1000;
				cppVar_751 = cppVar_755;
				} else {
				cppVar_751 = train_max;
				}
				cppVar_756 = ((cppVar_750 & cppMask_bit_16_) ? (cppVar_750 | cppMask_sign_16_) : cppVar_750) > ((cppVar_751 & cppMask_bit_16_) ? (cppVar_751 | cppMask_sign_16_) : cppVar_751);
				if (cppVar_756) {
				cppVar_732 = cppVar_750;
				} else {
				cppVar_732 = cppVar_751;
				}
				cppVar_730 = cppVar_732;
				} else {
				cppVar_730 = train_max;
				}
				cppVar_726 = cppVar_730;
			} 
			else {
				cppVar_759 = (per_v_pc == 1);
				cppVar_760 = cppVar_725 && cppVar_759;
				if (cppVar_760) {
				cppVar_763 = (jstate == 0);
				if (cppVar_763) {
				cppVar_765 = train_max - 62;
				cppVar_765 = (cppVar_765 & cppMask_un_16_);
				cppVar_761 = cppVar_765;
					//__CPROVER_assert(0,"t1");
				} else {
					//__CPROVER_assert(0,"t2");
				cppVar_761 = train_max;
				}
				cppVar_757 = cppVar_761;
				} else {
				cppVar_768 = (per_v_pc == 2);
				cppVar_769 = cppVar_725 && cppVar_768;
				if (cppVar_769) {
				cppVar_766 = train_max;
				} else {
				cppVar_772 = (per_v_pc == 3);
				cppVar_773 = cppVar_725 && cppVar_772;
				if (cppVar_773) {
				cppVar_770 = train_max;
				} else {
				cppVar_770 = train_max;
				}
				cppVar_766 = cppVar_770;
				}
				cppVar_757 = cppVar_766;
				}
				cppVar_726 = cppVar_757;
			}
			cppVar_723 = cppVar_726;
		} else {
		cppVar_776 = (train_upc == 2);
		if (cppVar_776) {
		cppVar_774 = train_max;
		} else {
		cppVar_774 = train_max;
		}
		cppVar_723 = cppVar_774;
		}
		cppVar_720 = cppVar_723;
	}
	return cppVar_720;
}
