#include "common.hpp"

/****************************************************/
#ifndef MODEL_AES_CLASS
#define MODEL_AES_CLASS
extern BIT_VEC aes(BIT_VEC cppVar_17, BIT_VEC cppVar_18, BIT_VEC cppVar_19);
class model_aes
{
public:
	model_aes() {
		cppMask_un_1_ = ((BIT_VEC)1 << 1) - 1;
		cppMask_un_104_ = ((BIT_VEC)1 << 104) - 1;
		cppMask_un_112_ = ((BIT_VEC)1 << 112) - 1;
		cppMask_un_120_ = ((BIT_VEC)1 << 120) - 1;
		cppMask_un_128_ = ((BIT_VEC)1 << 128) - 1;
		cppMask_un_16_ = ((BIT_VEC)1 << 16) - 1;
		cppMask_un_2_ = ((BIT_VEC)1 << 2) - 1;
		cppMask_un_24_ = ((BIT_VEC)1 << 24) - 1;
		cppMask_un_32_ = ((BIT_VEC)1 << 32) - 1;
		cppMask_un_40_ = ((BIT_VEC)1 << 40) - 1;
		cppMask_un_48_ = ((BIT_VEC)1 << 48) - 1;
		cppMask_un_56_ = ((BIT_VEC)1 << 56) - 1;
		cppMask_un_64_ = ((BIT_VEC)1 << 64) - 1;
		cppMask_un_72_ = ((BIT_VEC)1 << 72) - 1;
		cppMask_un_8_ = ((BIT_VEC)1 << 8) - 1;
		cppMask_un_80_ = ((BIT_VEC)1 << 80) - 1;
		cppMask_un_88_ = ((BIT_VEC)1 << 88) - 1;
		cppMask_un_96_ = ((BIT_VEC)1 << 96) - 1;
	};
	~model_aes() {};
public:
	// State variables.
	type_mem XRAM;
	BIT_VEC aes_addr;
	BIT_VEC aes_ctr;
	BIT_VEC aes_key0;
	BIT_VEC aes_key1;
	BIT_VEC aes_keysel;
	BIT_VEC aes_len;
	BIT_VEC aes_state;
	BIT_VEC byte_cnt;
	BIT_VEC dataout;
	BIT_VEC enc_data;
	BIT_VEC rd_data;
public:
	// Public functions: fetch, decode, update, ...
	type_mem cppUpdateFun_XRAM(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_aes_addr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_aes_ctr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_aes_key0(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_aes_key1(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_aes_keysel(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_aes_len(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_aes_state(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_byte_cnt(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_dataout(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_enc_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_rd_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	void update(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
private:
	// Bitvector masks.
	BIT_VEC cppMask_un_1_;
	BIT_VEC cppMask_un_104_;
	BIT_VEC cppMask_un_112_;
	BIT_VEC cppMask_un_120_;
	BIT_VEC cppMask_un_128_;
	BIT_VEC cppMask_un_16_;
	BIT_VEC cppMask_un_2_;
	BIT_VEC cppMask_un_24_;
	BIT_VEC cppMask_un_32_;
	BIT_VEC cppMask_un_40_;
	BIT_VEC cppMask_un_48_;
	BIT_VEC cppMask_un_56_;
	BIT_VEC cppMask_un_64_;
	BIT_VEC cppMask_un_72_;
	BIT_VEC cppMask_un_8_;
	BIT_VEC cppMask_un_80_;
	BIT_VEC cppMask_un_88_;
	BIT_VEC cppMask_un_96_;

};

/****************************************************/
/****************************************************/
#endif
/****************************************************/
