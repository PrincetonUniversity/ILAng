#include "common.hpp"
#include "model_train_class.hpp"

BIT_VEC model_train::cppUpdateFun_sumOfpow2(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_620;
	bool cppVar_621;
	BIT_VEC cppVar_623;
	bool cppVar_624;
	BIT_VEC cppVar_652;
	bool cppVar_653;
	BIT_VEC cppVar_626;
	bool cppVar_627;
	bool cppVar_628;
	BIT_VEC cppVar_630;
	bool cppVar_631;
	bool cppVar_632;
	BIT_VEC cppVar_634;
	bool cppVar_635;
	bool cppVar_636;
	BIT_VEC cppVar_648;
	bool cppVar_649;
	bool cppVar_650;
	BIT_VEC cppVar_641;
	BIT_VEC cppVar_642;
	BIT_VEC cppVar_643;
	BIT_VEC cppVar_644;
	BIT_VEC cppVar_645;
	BIT_VEC cppVar_638;
	bool cppVar_639;
	BIT_VEC cppVar_637;
	BIT_VEC cppVar_646;
	BIT_VEC cppVar_647;
	BIT_VEC cppVar_633;
	BIT_VEC cppVar_629;
	BIT_VEC cppVar_625;
	BIT_VEC cppVar_651;
	BIT_VEC cppVar_622;
	BIT_VEC cppVar_619;
	BIT_VEC cppVar_640;
	cppVar_621 = (train_upc == 0);
	if (cppVar_621) {
	cppVar_619 = sumOfpow2;
	} else {
	cppVar_624 = (train_upc == 1);
	if (cppVar_624) {
		cppVar_627 = (per_v_pc == 0);
		cppVar_628 = cppVar_624 && cppVar_627;
		if (cppVar_628) {
		cppVar_625 = sumOfpow2;
		} else {
		cppVar_631 = (per_v_pc == 1);
		cppVar_632 = cppVar_624 && cppVar_631;
		if (cppVar_632) {
		cppVar_629 = sumOfpow2;
		} else {
		cppVar_635 = (per_v_pc == 2);
		cppVar_636 = cppVar_624 && cppVar_635;
		if (cppVar_636) {
		cppVar_639 = (jstate == 0);
		if (cppVar_639) {
		cppVar_637 = 0;
		} else {
		cppVar_637 = sumOfpow2;
		}
		cppVar_641 = (jstate >> 0) & cppMask_un_3_;
		cppVar_642 = visibleEnergies.rd(cppVar_641);
		cppVar_643 = to_int_exp(cppVar_642);
		cppVar_644 = (cppVar_643 >> 0) & cppMask_un_32_;
		cppVar_645 = (cppVar_644 & cppMask_un_32_);
		cppVar_646 = cppVar_637 + cppVar_645;
		cppVar_646 = (cppVar_646 & cppMask_un_64_);
		cppVar_633 = cppVar_646;
		} else {
		cppVar_649 = (per_v_pc == 3);
		cppVar_650 = cppVar_624 && cppVar_649;
		if (cppVar_650) {
		cppVar_647 = sumOfpow2;
		} else {
		cppVar_647 = sumOfpow2;
		}
		cppVar_633 = cppVar_647;
		}
		cppVar_629 = cppVar_633;
		}
		cppVar_625 = cppVar_629;
		}
		cppVar_622 = cppVar_625;
	} else {
	cppVar_653 = (train_upc == 2);
	if (cppVar_653) {
	cppVar_651 = sumOfpow2;
	} else {
	cppVar_651 = sumOfpow2;
	}
	cppVar_622 = cppVar_651;
	}
	cppVar_619 = cppVar_622;
	}
	return cppVar_619;
}
