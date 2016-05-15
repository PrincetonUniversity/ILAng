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
	type_mem(BIT_VEC def = 0)
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
};
#endif
/****************************************************/


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
	bool decode_0();
	bool decode_1();
	bool decode_10();
	bool decode_100();
	bool decode_101();
	bool decode_102();
	bool decode_103();
	bool decode_104();
	bool decode_105();
	bool decode_106();
	bool decode_107();
	bool decode_108();
	bool decode_109();
	bool decode_11();
	bool decode_110();
	bool decode_111();
	bool decode_112();
	bool decode_113();
	bool decode_114();
	bool decode_115();
	bool decode_116();
	bool decode_117();
	bool decode_118();
	bool decode_119();
	bool decode_12();
	bool decode_120();
	bool decode_121();
	bool decode_122();
	bool decode_123();
	bool decode_124();
	bool decode_125();
	bool decode_126();
	bool decode_127();
	bool decode_128();
	bool decode_129();
	bool decode_13();
	bool decode_130();
	bool decode_131();
	bool decode_132();
	bool decode_133();
	bool decode_134();
	bool decode_135();
	bool decode_136();
	bool decode_137();
	bool decode_138();
	bool decode_139();
	bool decode_14();
	bool decode_140();
	bool decode_141();
	bool decode_142();
	bool decode_143();
	bool decode_144();
	bool decode_145();
	bool decode_146();
	bool decode_147();
	bool decode_148();
	bool decode_149();
	bool decode_15();
	bool decode_150();
	bool decode_151();
	bool decode_152();
	bool decode_153();
	bool decode_154();
	bool decode_155();
	bool decode_156();
	bool decode_157();
	bool decode_158();
	bool decode_159();
	bool decode_16();
	bool decode_160();
	bool decode_161();
	bool decode_162();
	bool decode_163();
	bool decode_164();
	bool decode_165();
	bool decode_166();
	bool decode_167();
	bool decode_168();
	bool decode_169();
	bool decode_17();
	bool decode_170();
	bool decode_171();
	bool decode_172();
	bool decode_173();
	bool decode_174();
	bool decode_175();
	bool decode_176();
	bool decode_177();
	bool decode_178();
	bool decode_179();
	bool decode_18();
	bool decode_180();
	bool decode_181();
	bool decode_182();
	bool decode_183();
	bool decode_184();
	bool decode_185();
	bool decode_186();
	bool decode_187();
	bool decode_188();
	bool decode_189();
	bool decode_19();
	bool decode_190();
	bool decode_191();
	bool decode_192();
	bool decode_193();
	bool decode_194();
	bool decode_195();
	bool decode_196();
	bool decode_197();
	bool decode_198();
	bool decode_199();
	bool decode_2();
	bool decode_20();
	bool decode_200();
	bool decode_201();
	bool decode_202();
	bool decode_203();
	bool decode_204();
	bool decode_205();
	bool decode_206();
	bool decode_207();
	bool decode_208();
	bool decode_209();
	bool decode_21();
	bool decode_210();
	bool decode_211();
	bool decode_212();
	bool decode_213();
	bool decode_214();
	bool decode_215();
	bool decode_216();
	bool decode_217();
	bool decode_218();
	bool decode_219();
	bool decode_22();
	bool decode_220();
	bool decode_221();
	bool decode_222();
	bool decode_223();
	bool decode_224();
	bool decode_225();
	bool decode_226();
	bool decode_227();
	bool decode_228();
	bool decode_229();
	bool decode_23();
	bool decode_230();
	bool decode_231();
	bool decode_232();
	bool decode_233();
	bool decode_234();
	bool decode_235();
	bool decode_236();
	bool decode_237();
	bool decode_238();
	bool decode_239();
	bool decode_24();
	bool decode_240();
	bool decode_241();
	bool decode_242();
	bool decode_243();
	bool decode_244();
	bool decode_245();
	bool decode_246();
	bool decode_247();
	bool decode_248();
	bool decode_249();
	bool decode_25();
	bool decode_250();
	bool decode_251();
	bool decode_252();
	bool decode_253();
	bool decode_254();
	bool decode_255();
	bool decode_26();
	bool decode_27();
	bool decode_28();
	bool decode_29();
	bool decode_3();
	bool decode_30();
	bool decode_31();
	bool decode_32();
	bool decode_33();
	bool decode_34();
	bool decode_35();
	bool decode_36();
	bool decode_37();
	bool decode_38();
	bool decode_39();
	bool decode_4();
	bool decode_40();
	bool decode_41();
	bool decode_42();
	bool decode_43();
	bool decode_44();
	bool decode_45();
	bool decode_46();
	bool decode_47();
	bool decode_48();
	bool decode_49();
	bool decode_5();
	bool decode_50();
	bool decode_51();
	bool decode_52();
	bool decode_53();
	bool decode_54();
	bool decode_55();
	bool decode_56();
	bool decode_57();
	bool decode_58();
	bool decode_59();
	bool decode_6();
	bool decode_60();
	bool decode_61();
	bool decode_62();
	bool decode_63();
	bool decode_64();
	bool decode_65();
	bool decode_66();
	bool decode_67();
	bool decode_68();
	bool decode_69();
	bool decode_7();
	bool decode_70();
	bool decode_71();
	bool decode_72();
	bool decode_73();
	bool decode_74();
	bool decode_75();
	bool decode_76();
	bool decode_77();
	bool decode_78();
	bool decode_79();
	bool decode_8();
	bool decode_80();
	bool decode_81();
	bool decode_82();
	bool decode_83();
	bool decode_84();
	bool decode_85();
	bool decode_86();
	bool decode_87();
	bool decode_88();
	bool decode_89();
	bool decode_9();
	bool decode_90();
	bool decode_91();
	bool decode_92();
	bool decode_93();
	bool decode_94();
	bool decode_95();
	bool decode_96();
	bool decode_97();
	bool decode_98();
	bool decode_99();
	BIT_VEC fetch();
	bool fetchValid();
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

#endif
