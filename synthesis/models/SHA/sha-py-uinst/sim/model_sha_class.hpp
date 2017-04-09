#include "common.hpp"

/****************************************************/
#ifndef MODEL_SHA_CLASS
#define MODEL_SHA_CLASS
extern BIT_VEC sha(BIT_VEC cppVar_11);
class model_sha
{
public:
	model_sha() {
		cppMask_un_16_ = ((BIT_VEC)1 << 16) - 1;
		cppMask_un_3_ = ((BIT_VEC)1 << 3) - 1;
		cppMask_un_512_ = ((BIT_VEC)1 << 512) - 1;
		cppMask_un_8_ = ((BIT_VEC)1 << 8) - 1;
	};
	~model_sha() {};
public:
	// State variables.
	type_mem XRAM;
	BIT_VEC dataout;
	BIT_VEC sha_bytes_read;
	BIT_VEC sha_hs_data;
	BIT_VEC sha_len;
	BIT_VEC sha_rd_data;
	BIT_VEC sha_rdaddr;
	BIT_VEC sha_state;
	BIT_VEC sha_wraddr;
public:
	// Public functions: fetch, decode, update, ...
	type_mem cppUpdateFun_XRAM(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_dataout(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_sha_bytes_read(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_sha_hs_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_sha_len(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_sha_rd_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_sha_rdaddr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_sha_state(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_sha_wraddr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	void update(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
private:
	// Bitvector masks.
	BIT_VEC cppMask_un_16_;
	BIT_VEC cppMask_un_3_;
	BIT_VEC cppMask_un_512_;
	BIT_VEC cppMask_un_8_;

};

/****************************************************/
/****************************************************/
#endif
/****************************************************/
