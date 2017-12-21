#include "common.hpp"
#include "model_alu_class.hpp"

BIT_VEC model_alu::cppUpdateFun_wrrd()
{
	BIT_VEC cppVar_176;
	BIT_VEC cppVar_175;
	type_mem<BV8,256> cppVar_177;
	BIT_VEC cppVar_178;
	cppVar_177 = xram;
	cppVar_177.wr(4, 254);
	cppVar_178 = cppVar_177.rd(4);
	return cppVar_178;
}
