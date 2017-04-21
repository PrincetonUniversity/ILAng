#include "common.hpp"
#include "model_train_class.hpp"

BIT_VEC model_train::cppUpdateFun_per_v_pc(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_573;
	bool cppVar_574;
	BIT_VEC cppVar_577;
	bool cppVar_578;
	BIT_VEC cppVar_616;
	bool cppVar_617;
	bool cppVar_586;
	BIT_VEC cppVar_584;
	bool cppVar_585;
	BIT_VEC cppVar_607;
	BIT_VEC cppVar_608;
	bool cppVar_609;
	BIT_VEC cppVar_610;
	BIT_VEC cppVar_611;
	BIT_VEC cppVar_612;
	bool cppVar_613;
	bool cppVar_614;
	BIT_VEC cppVar_580;
	bool cppVar_581;
	bool cppVar_582;
	BIT_VEC cppVar_590;
	bool cppVar_591;
	bool cppVar_592;
	BIT_VEC cppVar_596;
	bool cppVar_597;
	bool cppVar_598;
	BIT_VEC cppVar_602;
	bool cppVar_603;
	bool cppVar_604;
	bool cppVar_587;
	BIT_VEC cppVar_583;
	BIT_VEC cppVar_593;
	BIT_VEC cppVar_599;
	BIT_VEC cppVar_606;
	BIT_VEC cppVar_605;
	BIT_VEC cppVar_601;
	BIT_VEC cppVar_595;
	BIT_VEC cppVar_589;
	BIT_VEC cppVar_579;
	BIT_VEC cppVar_575;
	BIT_VEC cppVar_588;
	BIT_VEC cppVar_594;
	BIT_VEC cppVar_600;
	BIT_VEC cppVar_615;
	BIT_VEC cppVar_576;
	BIT_VEC cppVar_572;

	cppVar_574 = (train_upc == 0);
	if (cppVar_574) {
	cppVar_572 = 0;
	} 
	else {
		cppVar_578 = (train_upc == 1);
		if (cppVar_578) {
			cppVar_581 = (per_v_pc == 0);
			cppVar_582 = cppVar_578 && cppVar_581;
			if (cppVar_582) {
				cppVar_585 = (jstate == 4);
				cppVar_586 = (train_h_cnt == num_hidden);
				cppVar_587 = cppVar_585 && cppVar_586;
				if (cppVar_587) {
				cppVar_583 = 1;
				} else {
				cppVar_583 = per_v_pc;
				}
				cppVar_579 = cppVar_583;
			} 
			else {
				cppVar_591 = (per_v_pc == 1);
				cppVar_592 = cppVar_578 && cppVar_591;
				cppVar_585 = (jstate == 4);
				if (cppVar_592) {
					if (cppVar_585) {
					cppVar_593 = 2;
					} else {
					cppVar_593 = per_v_pc;
					}
					cppVar_589 = cppVar_593;
				} 
				else {
					cppVar_597 = (per_v_pc == 2);
					cppVar_598 = cppVar_578 && cppVar_597;
					if (cppVar_598) {
						if (cppVar_585) {
						cppVar_599 = 3;
						} else {
						cppVar_599 = per_v_pc;
						}
						cppVar_595 = cppVar_599;
					} 
					else {
						cppVar_603 = (per_v_pc == 3);
						cppVar_604 = cppVar_578 && cppVar_603;
						if (cppVar_604) {
						if (cppVar_585) {
						cppVar_608 = train_v_cnt + 5;
						cppVar_608 = (cppVar_608 & cppMask_un_16_);
						cppVar_609 = (cppVar_608 == num_visible);
						cppVar_611 = train_v_cnt + 5;
						cppVar_611 = (cppVar_611 & cppMask_un_16_);
						cppVar_613 = cppVar_611 >= 500;
						cppVar_614 = cppVar_609 || cppVar_613;
						if (cppVar_614) {
						cppVar_606 = 0;
						} else {
						cppVar_606 = 0;
						}
						cppVar_605 = cppVar_606;
						} else {
						cppVar_605 = per_v_pc;
						}
						cppVar_601 = cppVar_605;
						} else {
						cppVar_601 = per_v_pc;
						}
						cppVar_595 = cppVar_601;
					}
					cppVar_589 = cppVar_595;
				}
				cppVar_579 = cppVar_589;
			}
			cppVar_576 = cppVar_579;
		} else {
		cppVar_617 = (train_upc == 2);
		if (cppVar_617) {
		cppVar_615 = per_v_pc;
		} else {
		cppVar_615 = per_v_pc;
		}
		cppVar_576 = cppVar_615;
		}
		cppVar_572 = cppVar_576;
	}
	return cppVar_572;
}
