#include "common.hpp"

/****************************************************/
#ifndef MODEL_ALU_CLASS
#define MODEL_ALU_CLASS
class model_alu
{
public:
	model_alu():
	rom(0),
	xram(0)
	{
		cppMask_un_24_ = ((BIT_VEC)1 << 24) - 1;
		cppMask_un_4_ = ((BIT_VEC)1 << 4) - 1;
		cppMask_un_8_ = ((BIT_VEC)1 << 8) - 1;
		cppMask_bit_4_ = (BIT_VEC)1 << (4 - 1);
		cppMask_sign_4_ = ~cppMask_un_4_;
	};
	~model_alu() {};
public:
	// State variables.
	BIT_VEC pc;
	BIT_VEC r0;
	BIT_VEC r1;
	type_mem<BV4,16> rom;
	BIT_VEC wrrd;
	BIT_VEC wrrdblx;
	type_mem<BV8,256> xram;
public:
	// Public functions: fetch, decode, update, ...
	BIT_VEC cppUpdateFun_pc();
	BIT_VEC cppUpdateFun_r0();
	BIT_VEC cppUpdateFun_r1();
	type_mem<BV4,16> cppUpdateFun_rom();
	BIT_VEC cppUpdateFun_wrrd();
	BIT_VEC cppUpdateFun_wrrdblx();
	void update();
private:
	// Bitvector masks.
	BIT_VEC cppMask_un_24_;
	BIT_VEC cppMask_un_4_;
	BIT_VEC cppMask_un_8_;
	BIT_VEC cppMask_bit_4_;
	BIT_VEC cppMask_sign_4_;

};

/****************************************************/
/****************************************************/
#endif
/****************************************************/
