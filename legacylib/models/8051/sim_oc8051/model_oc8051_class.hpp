#include "common.hpp"

/****************************************************/
#ifndef MODEL_OC8051_CLASS
#define MODEL_OC8051_CLASS
class model_oc8051
{
public:
	model_oc8051() {
		cppMask_un_1_ = ((BIT_VEC)1 << 1) - 1;
		cppMask_un_16_ = ((BIT_VEC)1 << 16) - 1;
		cppMask_un_2_ = ((BIT_VEC)1 << 2) - 1;
		cppMask_un_3_ = ((BIT_VEC)1 << 3) - 1;
		cppMask_un_4_ = ((BIT_VEC)1 << 4) - 1;
		cppMask_un_5_ = ((BIT_VEC)1 << 5) - 1;
		cppMask_un_6_ = ((BIT_VEC)1 << 6) - 1;
		cppMask_un_7_ = ((BIT_VEC)1 << 7) - 1;
		cppMask_un_8_ = ((BIT_VEC)1 << 8) - 1;
		cppMask_un_9_ = ((BIT_VEC)1 << 9) - 1;
		cppMask_bit_1_ = (BIT_VEC)1 << (1 - 1);
		cppMask_bit_8_ = (BIT_VEC)1 << (8 - 1);
		cppMask_sign_1_ = ~cppMask_un_1_;
		cppMask_sign_8_ = ~cppMask_un_8_;
	};
	~model_oc8051() {};
public:
	// State variables.
	BIT_VEC ACC;
	BIT_VEC B;
	BIT_VEC DPH;
	BIT_VEC DPL;
	BIT_VEC IE;
	BIT_VEC IP;
	type_mem IRAM;
	BIT_VEC P0;
	BIT_VEC P1;
	BIT_VEC P2;
	BIT_VEC P3;
	BIT_VEC PC;
	BIT_VEC PCON;
	BIT_VEC PSW;
	type_mem ROM;
	BIT_VEC SBUF;
	BIT_VEC SCON;
	BIT_VEC SP;
	BIT_VEC TCON;
	BIT_VEC TH0;
	BIT_VEC TH1;
	BIT_VEC TL0;
	BIT_VEC TL1;
	BIT_VEC TMOD;
	BIT_VEC XRAM_ADDR;
	BIT_VEC XRAM_DATA_IN;
	BIT_VEC XRAM_DATA_OUT;
public:
	// Public functions: fetch, decode, update, ...
	BIT_VEC cppUpdateFun_ACC();
	BIT_VEC cppUpdateFun_B();
	BIT_VEC cppUpdateFun_DPH();
	BIT_VEC cppUpdateFun_DPL();
	BIT_VEC cppUpdateFun_IE();
	BIT_VEC cppUpdateFun_IP();
	type_mem cppUpdateFun_IRAM();
	BIT_VEC cppUpdateFun_P0();
	BIT_VEC cppUpdateFun_P1();
	BIT_VEC cppUpdateFun_P2();
	BIT_VEC cppUpdateFun_P3();
	BIT_VEC cppUpdateFun_PC();
	BIT_VEC cppUpdateFun_PCON();
	BIT_VEC cppUpdateFun_PSW();
	BIT_VEC cppUpdateFun_SBUF();
	BIT_VEC cppUpdateFun_SCON();
	BIT_VEC cppUpdateFun_SP();
	BIT_VEC cppUpdateFun_TCON();
	BIT_VEC cppUpdateFun_TH0();
	BIT_VEC cppUpdateFun_TH1();
	BIT_VEC cppUpdateFun_TL0();
	BIT_VEC cppUpdateFun_TL1();
	BIT_VEC cppUpdateFun_TMOD();
	BIT_VEC cppUpdateFun_XRAM_ADDR();
	BIT_VEC cppUpdateFun_XRAM_DATA_OUT();
	void update();
private:
	// Bitvector masks.
	BIT_VEC cppMask_un_1_;
	BIT_VEC cppMask_un_16_;
	BIT_VEC cppMask_un_2_;
	BIT_VEC cppMask_un_3_;
	BIT_VEC cppMask_un_4_;
	BIT_VEC cppMask_un_5_;
	BIT_VEC cppMask_un_6_;
	BIT_VEC cppMask_un_7_;
	BIT_VEC cppMask_un_8_;
	BIT_VEC cppMask_un_9_;
	BIT_VEC cppMask_bit_1_;
	BIT_VEC cppMask_bit_8_;
	BIT_VEC cppMask_sign_1_;
	BIT_VEC cppMask_sign_8_;

};

/****************************************************/
/****************************************************/
#endif
/****************************************************/
