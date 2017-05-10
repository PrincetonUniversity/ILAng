//#include <stdint.h>
#include <stddef.h>

#ifndef CPP_BITVEC_TYPE
#define CPP_BITVEC_TYPE
typedef long int BIT_VEC;
#endif

/****************************************************/
#ifndef TYPE_MEM_CLASS
#define TYPE_MEM_CLASS

typedef bool BV1;
typedef unsigned char BV8;
typedef unsigned short BV16;
typedef unsigned int BV32;

extern "C" bool __CPROVER_array_equal(const void *a, const void *b);
extern "C" void __CPROVER_array_set(const void *dest, ...);
extern "C" void __CPROVER_array_copy(const void *dest, const void *src);

extern "C" void __CPROVER_assume(bool);
extern "C" void __CPROVER_cover(bool);
extern "C" void __CPROVER_assert(bool, const char *);

extern "C" void *__CPROVER_malloc(size_t size);

BV16 nondet_BV();


template<class TP, unsigned DEPTH>
class type_mem
{
public:
	TP *arrayPnt;

public:
	type_mem()
	{
		arrayPnt = (TP *)__CPROVER_malloc(sizeof(TP)*DEPTH);
	}
	type_mem(BIT_VEC def)
	{
		//setDef(def);
		arrayPnt = (TP *)__CPROVER_malloc(sizeof(TP)*DEPTH);
	}
	type_mem(const type_mem & r){
		arrayPnt = (TP *)__CPROVER_malloc(sizeof(TP)*DEPTH);
		__CPROVER_array_copy( arrayPnt , r.arrayPnt );
	}
	~type_mem() {}

	const type_mem & operator=(const type_mem &r){
		__CPROVER_array_copy( arrayPnt , r.arrayPnt );
		return *this;
	}

	void setDef(BIT_VEC def)
	{
		//__CPROVER_array_set(arrayPnt, def);
	}

	void wr(BIT_VEC addr, BIT_VEC data)
	{
		arrayPnt[addr] = data;
	}
	BIT_VEC rd(BIT_VEC addr)
	{
		return arrayPnt[addr];
	}

	bool operator == (const type_mem &targ)
	{
		return __CPROVER_array_equal(arrayPnt, targ.arrayPnt );
	}

};


#endif
