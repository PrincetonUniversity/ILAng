#include "common.hpp"
#include "model_train_class.hpp"

BIT_VEC model_train::cppUpdateFun_train_h_cnt(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_656;
	bool cppVar_657;
	BIT_VEC cppVar_668;
	bool cppVar_669;
	BIT_VEC cppVar_691;
	bool cppVar_692;
	BIT_VEC cppVar_698;
	bool cppVar_699;
	bool cppVar_659;
	BIT_VEC cppVar_661;
	BIT_VEC cppVar_662;
	bool cppVar_663;
	BIT_VEC cppVar_665;
	BIT_VEC cppVar_666;
	BIT_VEC cppVar_660;
	BIT_VEC cppVar_658;
	bool cppVar_675;
	BIT_VEC cppVar_671;
	bool cppVar_672;
	bool cppVar_673;
	BIT_VEC cppVar_679;
	bool cppVar_680;
	bool cppVar_681;
	BIT_VEC cppVar_683;
	bool cppVar_684;
	bool cppVar_685;
	BIT_VEC cppVar_687;
	bool cppVar_688;
	bool cppVar_689;
	BIT_VEC cppVar_676;
	BIT_VEC cppVar_677;
	BIT_VEC cppVar_674;
	BIT_VEC cppVar_686;
	BIT_VEC cppVar_682;
	BIT_VEC cppVar_678;
	BIT_VEC cppVar_670;
	bool cppVar_694;
	BIT_VEC cppVar_695;
	BIT_VEC cppVar_696;
	BIT_VEC cppVar_693;
	bool cppVar_701;
	BIT_VEC cppVar_702;
	BIT_VEC cppVar_703;
	BIT_VEC cppVar_700;
	BIT_VEC cppVar_697;
	BIT_VEC cppVar_690;
	BIT_VEC cppVar_667;
	BIT_VEC cppVar_655;
	BIT_VEC cppVar_664;
	cppVar_657 = (train_upc == 0);
	if (cppVar_657) {
	cppVar_659 = (train_v_cnt == num_visible);
	if (cppVar_659) {
	cppVar_662 = num_hidden - 1;
	cppVar_662 = (cppVar_662 & cppMask_un_16_);
	cppVar_663 = (train_h_cnt == cppVar_662);
	if (cppVar_663) {
	cppVar_660 = 0;
	} else {
	cppVar_666 = train_h_cnt + 1;
	cppVar_666 = (cppVar_666 & cppMask_un_16_);
	cppVar_660 = cppVar_666;
	}
	cppVar_658 = cppVar_660;
	} else {
	cppVar_658 = train_h_cnt;
	}
	cppVar_655 = cppVar_658;
	} else {
	cppVar_669 = (train_upc == 1);
	if (cppVar_669) {
	cppVar_672 = (per_v_pc == 0);
	cppVar_673 = cppVar_669 && cppVar_672;
	if (cppVar_673) {
	cppVar_675 = (train_h_cnt == num_hidden);
	if (cppVar_675) {
	cppVar_674 = 0;
	} else {
	cppVar_677 = train_h_cnt + 1;
	cppVar_677 = (cppVar_677 & cppMask_un_16_);
	cppVar_674 = cppVar_677;
	}
	cppVar_670 = cppVar_674;
	} else {
	cppVar_680 = (per_v_pc == 1);
	cppVar_681 = cppVar_669 && cppVar_680;
	if (cppVar_681) {
	cppVar_678 = train_h_cnt;
	} else {
	cppVar_684 = (per_v_pc == 2);
	cppVar_685 = cppVar_669 && cppVar_684;
	if (cppVar_685) {
	cppVar_682 = train_h_cnt;
	} else {
	cppVar_688 = (per_v_pc == 3);
	cppVar_689 = cppVar_669 && cppVar_688;
	if (cppVar_689) {
	cppVar_686 = train_h_cnt;
	} else {
	cppVar_686 = train_h_cnt;
	}
	cppVar_682 = cppVar_686;
	}
	cppVar_678 = cppVar_682;
	}
	cppVar_670 = cppVar_678;
	}
	cppVar_667 = cppVar_670;
	} else {
	cppVar_692 = (train_upc == 3);
	if (cppVar_692) {
	cppVar_694 = (train_h_cnt == num_hidden);
	if (cppVar_694) {
	cppVar_693 = 0;
	} else {
	cppVar_696 = train_h_cnt + 1;
	cppVar_696 = (cppVar_696 & cppMask_un_16_);
	cppVar_693 = cppVar_696;
	}
	cppVar_690 = cppVar_693;
	} else {
	cppVar_699 = (train_upc == 2);
	if (cppVar_699) {
	cppVar_701 = (train_h_cnt == num_hidden);
	if (cppVar_701) {
	cppVar_700 = 0;
	} else {
	cppVar_703 = train_h_cnt + 1;
	cppVar_703 = (cppVar_703 & cppMask_un_16_);
	cppVar_700 = cppVar_703;
	}
	cppVar_697 = cppVar_700;
	} else {
	cppVar_697 = train_h_cnt;
	}
	cppVar_690 = cppVar_697;
	}
	cppVar_667 = cppVar_690;
	}
	cppVar_655 = cppVar_667;
	}
	return cppVar_655;
}
