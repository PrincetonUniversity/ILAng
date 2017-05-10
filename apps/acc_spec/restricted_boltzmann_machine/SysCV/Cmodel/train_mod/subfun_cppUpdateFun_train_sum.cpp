#include "common.hpp"
#include "model_train_class.hpp"

BIT_VEC model_train::cppUpdateFun_train_sum(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_779;
	bool cppVar_780;
	BIT_VEC cppVar_801;
	bool cppVar_802;
	BIT_VEC cppVar_835;
	bool cppVar_836;
	BIT_VEC cppVar_790;
	BIT_VEC cppVar_791;
	BIT_VEC cppVar_792;
	BIT_VEC cppVar_782;
	bool cppVar_783;
	BIT_VEC cppVar_784;
	BIT_VEC cppVar_781;
	BIT_VEC cppVar_786;
	BIT_VEC cppVar_787;
	BIT_VEC cppVar_788;
	bool cppVar_789;
	BIT_VEC cppVar_793;
	BIT_VEC cppVar_794;
	BIT_VEC cppVar_795;
	BIT_VEC cppVar_796;
	BIT_VEC cppVar_797;
	BIT_VEC cppVar_798;
	BIT_VEC cppVar_785;
	BIT_VEC cppVar_799;
	BIT_VEC cppVar_804;
	bool cppVar_805;
	bool cppVar_806;
	BIT_VEC cppVar_823;
	bool cppVar_824;
	bool cppVar_825;
	BIT_VEC cppVar_827;
	bool cppVar_828;
	bool cppVar_829;
	BIT_VEC cppVar_831;
	bool cppVar_832;
	bool cppVar_833;
	BIT_VEC cppVar_808;
	bool cppVar_809;
	BIT_VEC cppVar_807;
	BIT_VEC cppVar_812;
	BIT_VEC cppVar_813;
	BIT_VEC cppVar_814;
	bool cppVar_815;
	BIT_VEC cppVar_816;
	BIT_VEC cppVar_817;
	BIT_VEC cppVar_818;
	BIT_VEC cppVar_819;
	BIT_VEC cppVar_820;
	BIT_VEC cppVar_811;
	BIT_VEC cppVar_821;
	BIT_VEC cppVar_830;
	BIT_VEC cppVar_826;
	BIT_VEC cppVar_822;
	BIT_VEC cppVar_803;
	BIT_VEC cppVar_834;
	BIT_VEC cppVar_800;
	BIT_VEC cppVar_778;
	BIT_VEC cppVar_810;
	cppVar_780 = (train_upc == 0);
	if (cppVar_780) {
	cppVar_783 = (train_v_cnt == 0);
	if (cppVar_783) {
	cppVar_781 = 0;
	} else {
	cppVar_781 = train_sum;
	}
	cppVar_786 = (train_v_cnt >> 0) & cppMask_un_9_;
	cppVar_787 = data.rd(cppVar_786);
	cppVar_789 = (cppVar_787 == 1);
	if (cppVar_789) {
	cppVar_791 = 101 * train_v_cnt;
	cppVar_791 = (cppVar_791 & cppMask_un_16_);
	cppVar_792 = cppVar_791 + train_h_cnt;
	cppVar_792 = (cppVar_792 & cppMask_un_16_);
	cppVar_793 = edges.rd(cppVar_792);
	cppVar_794 = (cppVar_793 >> 1) & cppMask_un_7_;
	cppVar_795 = ((cppVar_794 & cppMask_bit_7_) ? (cppVar_794 | cppMask_sign_7_) : cppVar_794);
	cppVar_796 = (cppVar_793 >> 0) & cppMask_un_1_;
	cppVar_797 = (cppVar_795 << 1) | cppVar_796;
	cppVar_797 = (cppVar_797 & cppMask_un_16_);
	cppVar_785 = cppVar_797;
	} else {
	cppVar_785 = 0;
	}
	cppVar_799 = cppVar_781 + cppVar_785;
	cppVar_799 = (cppVar_799 & cppMask_un_16_);
	cppVar_778 = cppVar_799;
	} else {
	cppVar_802 = (train_upc == 1);
	if (cppVar_802) {
	cppVar_805 = (per_v_pc == 0);
	cppVar_806 = cppVar_802 && cppVar_805;
	if (cppVar_806) {
	cppVar_809 = (train_h_cnt == 0);
	if (cppVar_809) {
	cppVar_807 = 0;
	} else {
	cppVar_807 = train_sum;
	}
	cppVar_812 = (train_h_cnt >> 0) & cppMask_un_7_;
	cppVar_813 = hidden_unit.rd(cppVar_812);
	cppVar_815 = (cppVar_813 == 1);
	if (cppVar_815) {
	cppVar_816 = edges.rd(cppVar_792);
	cppVar_817 = (cppVar_816 >> 1) & cppMask_un_7_;
	cppVar_818 = ((cppVar_817 & cppMask_bit_7_) ? (cppVar_817 | cppMask_sign_7_) : cppVar_817);
	cppVar_819 = (cppVar_816 >> 0) & cppMask_un_1_;
	cppVar_820 = (cppVar_818 << 1) | cppVar_819;
	cppVar_820 = (cppVar_820 & cppMask_un_16_);
	cppVar_811 = cppVar_820;
	} else {
	cppVar_811 = 0;
	}
	cppVar_821 = cppVar_807 + cppVar_811;
	cppVar_821 = (cppVar_821 & cppMask_un_16_);
	cppVar_803 = cppVar_821;
	} else {
	cppVar_824 = (per_v_pc == 1);
	cppVar_825 = cppVar_802 && cppVar_824;
	if (cppVar_825) {
	cppVar_822 = train_sum;
	} else {
	cppVar_828 = (per_v_pc == 2);
	cppVar_829 = cppVar_802 && cppVar_828;
	if (cppVar_829) {
	cppVar_826 = train_sum;
	} else {
	cppVar_832 = (per_v_pc == 3);
	cppVar_833 = cppVar_802 && cppVar_832;
	if (cppVar_833) {
	cppVar_830 = train_sum;
	} else {
	cppVar_830 = train_sum;
	}
	cppVar_826 = cppVar_830;
	}
	cppVar_822 = cppVar_826;
	}
	cppVar_803 = cppVar_822;
	}
	cppVar_800 = cppVar_803;
	} else {
	cppVar_836 = (train_upc == 2);
	if (cppVar_836) {
	cppVar_834 = train_sum;
	} else {
	cppVar_834 = train_sum;
	}
	cppVar_800 = cppVar_834;
	}
	cppVar_778 = cppVar_800;
	}
	return cppVar_778;
}
