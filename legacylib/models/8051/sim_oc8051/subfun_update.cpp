#include "common.hpp"
#include "model_oc8051_class.hpp"

void model_oc8051::update()
{
	BIT_VEC cppVar_2947 = cppUpdateFun_ACC();
	BIT_VEC cppVar_7515 = cppUpdateFun_B();
	BIT_VEC cppVar_9949 = cppUpdateFun_DPH();
	BIT_VEC cppVar_13432 = cppUpdateFun_DPL();
	BIT_VEC cppVar_17984 = cppUpdateFun_IE();
	BIT_VEC cppVar_22536 = cppUpdateFun_IP();
	BIT_VEC cppVar_27088 = cppUpdateFun_P0();
	BIT_VEC cppVar_31640 = cppUpdateFun_P1();
	BIT_VEC cppVar_36192 = cppUpdateFun_P2();
	BIT_VEC cppVar_41660 = cppUpdateFun_P3();
	BIT_VEC cppVar_44272 = cppUpdateFun_PC();
	BIT_VEC cppVar_46694 = cppUpdateFun_PCON();
	BIT_VEC cppVar_57108 = cppUpdateFun_PSW();
	BIT_VEC cppVar_59530 = cppUpdateFun_SBUF();
	BIT_VEC cppVar_64082 = cppUpdateFun_SCON();
	BIT_VEC cppVar_67873 = cppUpdateFun_SP();
	BIT_VEC cppVar_72425 = cppUpdateFun_TCON();
	BIT_VEC cppVar_74847 = cppUpdateFun_TH0();
	BIT_VEC cppVar_77269 = cppUpdateFun_TH1();
	BIT_VEC cppVar_79691 = cppUpdateFun_TL0();
	BIT_VEC cppVar_82113 = cppUpdateFun_TL1();
	BIT_VEC cppVar_84535 = cppUpdateFun_TMOD();
	BIT_VEC cppVar_85578 = cppUpdateFun_XRAM_ADDR();
	BIT_VEC cppVar_86604 = cppUpdateFun_XRAM_DATA_OUT();
	type_mem cppVar_95849 = cppUpdateFun_IRAM();
	ACC = cppVar_2947;
	B = cppVar_7515;
	DPH = cppVar_9949;
	DPL = cppVar_13432;
	IE = cppVar_17984;
	IP = cppVar_22536;
	P0 = cppVar_27088;
	P1 = cppVar_31640;
	P2 = cppVar_36192;
	P3 = cppVar_41660;
	PC = cppVar_44272;
	PCON = cppVar_46694;
	PSW = cppVar_57108;
	SBUF = cppVar_59530;
	SCON = cppVar_64082;
	SP = cppVar_67873;
	TCON = cppVar_72425;
	TH0 = cppVar_74847;
	TH1 = cppVar_77269;
	TL0 = cppVar_79691;
	TL1 = cppVar_82113;
	TMOD = cppVar_84535;
	XRAM_ADDR = cppVar_85578;
	XRAM_DATA_OUT = cppVar_86604;
	IRAM = cppVar_95849;
	return;
}
