#include "common.hpp"
#include "model_alu_class.hpp"

void model_alu::update()
{
	BIT_VEC cppVar_106 = cppUpdateFun_pc();
	BIT_VEC cppVar_140 = cppUpdateFun_r0();
	BIT_VEC cppVar_174 = cppUpdateFun_r1();
	BIT_VEC cppVar_179 = cppUpdateFun_wrrd();
	BIT_VEC cppVar_189 = cppUpdateFun_wrrdblx();
	type_mem<BV4,16> cppVar_190 = cppUpdateFun_rom();
	pc = cppVar_106;
	r0 = cppVar_140;
	r1 = cppVar_174;
	wrrd = cppVar_179;
	wrrdblx = cppVar_189;
	rom = cppVar_190;
	return;
}
