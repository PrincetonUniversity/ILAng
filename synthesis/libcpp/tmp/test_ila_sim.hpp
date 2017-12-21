#include <map>
#include <stdint.h>
#include <boost/multiprecision/cpp_int.hpp>

#ifndef CPP_BITVEC_TYPE
#define CPP_BITVEC_TYPE
typedef boost::multiprecision::cpp_int BIT_VEC;
#endif

/****************************************************/
#ifndef TYPE_MEM_CLASS
#define TYPE_MEM_CLASS
class type_mem
{
private:
	std::map<BIT_VEC, BIT_VEC> _map;
	BIT_VEC _def_val;
public:
	type_mem(BIT_VEC def, unsigned addrw, unsigned dataw)
		: _def_val(def)
	{
	}
	~type_mem() {}

	void setDef(BIT_VEC def)
	{
		_def_val = def;
	}

	void wr(BIT_VEC addr, BIT_VEC data)
	{
		if (data == _def_val) {
			_map.erase(addr);
		} else {
			_map[addr] = data;
		}
	}

	BIT_VEC rd(BIT_VEC addr)
	{
		std::map<BIT_VEC, BIT_VEC>::iterator it = _map.find(addr);
		if (it == _map.end()) {
			return _def_val;
		} else {
			return _map[addr];
		}
	}

	bool operator == (type_mem targ)
	{
		return (_map == targ._map) & (_def_val == targ._def_val);
	}
};
#endif
/****************************************************/

/****************************************************/
#ifndef MODEL_TEST_CLASS
#define MODEL_TEST_CLASS
extern BIT_VEC cnst();
extern BIT_VEC foo(BIT_VEC cppVar_7, BIT_VEC cppVar_8);
class model_test
{
public:
	model_test():

	{
	};
	~model_test() {};
public:
	// State variables.
	BIT_VEC x;
	BIT_VEC y;
	BIT_VEC z;
public:
	// Public functions: fetch, decode, update, ...
	bool assumps_0();
	void update();
private:
	// Bitvector masks.

};

/****************************************************/
/****************************************************/
#endif
/****************************************************/
bool model_test::assumps_0()
{
	BIT_VEC cppVar_10;
	BIT_VEC cppVar_11;
	bool cppVar_12;
	BIT_VEC cppVar_13;
	BIT_VEC cppVar_14;
	bool cppVar_15;
	bool cppVar_16;
	cppVar_10 = cnst();
	cppVar_12 = cppVar_10 >= 10;
	cppVar_13 = cnst();
	cppVar_15 = cppVar_13 <= 15;
	cppVar_16 = cppVar_12 && cppVar_15;
	return cppVar_16;
}
void model_test::update()
{
	BIT_VEC cppVar_9;
	cppVar_9 = foo(y, z);
	x = cppVar_9;
	return;
}
