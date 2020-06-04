#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
typedef number<cpp_int_backend<2, 2, unsigned_magnitude, unchecked, void> > uint2_t;
typedef number<cpp_int_backend<4, 4, unsigned_magnitude, unchecked, void> > uint4_t;
typedef number<cpp_int_backend<24, 24, unsigned_magnitude, unchecked, void> > uint24_t;
typedef number<cpp_int_backend<40, 40, unsigned_magnitude, unchecked, void> > uint40_t;
typedef number<cpp_int_backend<48, 48, unsigned_magnitude, unchecked, void> > uint48_t;
typedef number<cpp_int_backend<56, 56, unsigned_magnitude, unchecked, void> > uint56_t;
typedef number<cpp_int_backend<72, 72, unsigned_magnitude, unchecked, void> > uint72_t;
typedef number<cpp_int_backend<80, 80, unsigned_magnitude, unchecked, void> > uint80_t;
typedef number<cpp_int_backend<88, 88, unsigned_magnitude, unchecked, void> > uint88_t;
typedef number<cpp_int_backend<96, 96, unsigned_magnitude, unchecked, void> > uint96_t;
typedef number<cpp_int_backend<104, 104, unsigned_magnitude, unchecked, void> > uint104_t;
typedef number<cpp_int_backend<112, 112, unsigned_magnitude, unchecked, void> > uint112_t;
typedef number<cpp_int_backend<120, 120, unsigned_magnitude, unchecked, void> > uint120_t;
#include <map>
class TEST {
public:
  uint2_t TEST_cmd;
  uint16_t TEST_cmdaddr;
  uint8_t TEST_cmddata;
  bool TEST_cmdflag;
  uint2_t TEST_status;
  uint16_t TEST_address;
  uint16_t TEST_length;
  uint128_t TEST_counter;
  uint8_t TEST_XRAM[65536];
  bool TEST_flag;
  std::map<uint32_t, uint32_t>TEST_big_ram;
  uint128_t ENCRYPT_rd_data;
  uint128_t ENCRYPT_enc_data;
  uint4_t ENCRYPT_byte_cnt;
  uint16_t ENCRYPT_blk_cnt;
  void init_ENCRYPT();
  bool c_1693149;
  bool c_1693151;
  bool decode_TEST_WRITE_ADDRESS();
  bool c_1693068;
  bool c_1693064;
  bool c_1693070;
  bool c_1693093;
  bool c_1693086;
  bool c_1693088;
  bool c_1693090;
  bool c_1693095;
  bool c_1693082;
  bool c_1693096;
  bool decode_TEST_START_ENCRYPT();
  bool c_1693132;
  bool c_1693128;
  bool c_1693134;
  bool c_1693124;
  bool c_1693135;
  bool decode_ENCRYPT_LOAD();
  bool c_1693171;
  bool decode_ENCRYPT_ENC();
  bool c_1693446;
  bool c_1693442;
  bool c_1693448;
  bool decode_ENCRYPT_STORE();
  bool c_1693470;
  uint16_t decode_TEST_WRITE_ADDRESS_update_TEST_address();
  bool c_1693073;
  bool c_1693110;
  uint8_t c_1693107;
  uint8_t c_1693105;
  uint8_t c_1693112;
  bool c_1693102;
  uint8_t c_1693099;
  uint8_t c_1693097;
  uint8_t c_1693104;
  uint16_t c_1693117;
  uint16_t c_1693119;
  bool decode_TEST_WRITE_ADDRESS_update_TEST_flag();
  bool c_1693120;
  uint2_t decode_TEST_START_ENCRYPT_update_TEST_status();
  uint2_t unknown0();
  uint2_t c_1693138;
  uint2_t c_1693141;
  uint4_t decode_ENCRYPT_LOAD_update_ENCRYPT_byte_cnt();
  uint4_t c_1693175;
  uint128_t decode_ENCRYPT_LOAD_update_ENCRYPT_rd_data();
  uint4_t c_1693420;
  bool c_1693423;
  uint16_t c_1693178;
  uint16_t c_1693176;
  uint16_t c_1693179;
  uint8_t c_1693180;
  uint8_t c_1693416;
  uint8_t c_1693425;
  uint4_t c_1693404;
  bool c_1693407;
  uint8_t c_1693400;
  uint8_t c_1693409;
  uint4_t c_1693388;
  bool c_1693391;
  uint8_t c_1693384;
  uint8_t c_1693393;
  uint4_t c_1693372;
  bool c_1693375;
  uint8_t c_1693368;
  uint8_t c_1693377;
  uint4_t c_1693356;
  bool c_1693359;
  uint8_t c_1693352;
  uint8_t c_1693361;
  uint4_t c_1693340;
  bool c_1693343;
  uint8_t c_1693336;
  uint8_t c_1693345;
  uint4_t c_1693324;
  bool c_1693327;
  uint8_t c_1693320;
  uint8_t c_1693329;
  uint4_t c_1693308;
  bool c_1693311;
  uint8_t c_1693304;
  uint8_t c_1693313;
  uint4_t c_1693292;
  bool c_1693295;
  uint8_t c_1693288;
  uint8_t c_1693297;
  uint4_t c_1693276;
  bool c_1693279;
  uint8_t c_1693272;
  uint8_t c_1693281;
  uint4_t c_1693260;
  bool c_1693263;
  uint8_t c_1693256;
  uint8_t c_1693265;
  uint4_t c_1693244;
  bool c_1693247;
  uint8_t c_1693240;
  uint8_t c_1693249;
  uint4_t c_1693228;
  bool c_1693231;
  uint8_t c_1693224;
  uint8_t c_1693233;
  uint4_t c_1693212;
  bool c_1693215;
  uint8_t c_1693208;
  uint8_t c_1693217;
  uint4_t c_1693196;
  bool c_1693199;
  uint8_t c_1693192;
  uint8_t c_1693201;
  uint4_t c_1693186;
  bool c_1693189;
  uint8_t c_1693182;
  uint8_t c_1693191;
  uint16_t c_1693206;
  uint24_t c_1693222;
  uint32_t c_1693238;
  uint40_t c_1693254;
  uint48_t c_1693270;
  uint56_t c_1693286;
  uint64_t c_1693302;
  uint72_t c_1693318;
  uint80_t c_1693334;
  uint88_t c_1693350;
  uint96_t c_1693366;
  uint104_t c_1693382;
  uint112_t c_1693398;
  uint120_t c_1693414;
  uint128_t c_1693430;
  uint2_t decode_ENCRYPT_LOAD_update_TEST_status();
  bool c_1693436;
  uint2_t c_1693438;
  uint128_t decode_ENCRYPT_ENC_update_ENCRYPT_enc_data();
  const uint128_t c_1693450[16] = {0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  uint128_t c_1693458;
  uint128_t c_1693460;
  uint128_t c_1693454;
  uint128_t c_1693461;
  uint128_t c_1693452;
  uint128_t c_1693462;
  uint128_t process128(uint128_t arg_0, uint128_t arg_1);
  uint128_t c_1693463;
  uint128_t c_1693464;
  uint2_t decode_ENCRYPT_ENC_update_TEST_status();
  void ite_1693632(std::map<int, int>& mem_update_map);
  uint16_t c_1693474;
  uint16_t c_1693472;
  uint16_t c_1693475;
  uint4_t c_1693625;
  bool c_1693628;
  uint8_t c_1693621;
  uint4_t c_1693615;
  bool c_1693618;
  uint8_t c_1693611;
  uint4_t c_1693605;
  bool c_1693608;
  uint8_t c_1693601;
  uint4_t c_1693595;
  bool c_1693598;
  uint8_t c_1693591;
  uint4_t c_1693585;
  bool c_1693588;
  uint8_t c_1693581;
  uint4_t c_1693575;
  bool c_1693578;
  uint8_t c_1693571;
  uint4_t c_1693565;
  bool c_1693568;
  uint8_t c_1693561;
  uint4_t c_1693555;
  bool c_1693558;
  uint8_t c_1693551;
  uint4_t c_1693545;
  bool c_1693548;
  uint8_t c_1693541;
  uint4_t c_1693535;
  bool c_1693538;
  uint8_t c_1693531;
  uint4_t c_1693525;
  bool c_1693528;
  uint8_t c_1693521;
  uint4_t c_1693515;
  bool c_1693518;
  uint8_t c_1693511;
  uint4_t c_1693505;
  bool c_1693508;
  uint8_t c_1693501;
  uint4_t c_1693495;
  bool c_1693498;
  uint8_t c_1693491;
  uint4_t c_1693485;
  bool c_1693488;
  uint8_t c_1693481;
  uint8_t c_1693479;
  uint8_t c_1693490;
  uint8_t c_1693500;
  uint8_t c_1693510;
  uint8_t c_1693520;
  uint8_t c_1693530;
  uint8_t c_1693540;
  uint8_t c_1693550;
  uint8_t c_1693560;
  uint8_t c_1693570;
  uint8_t c_1693580;
  uint8_t c_1693590;
  uint8_t c_1693600;
  uint8_t c_1693610;
  uint8_t c_1693620;
  uint8_t c_1693630;
  std::map<int, int> decode_ENCRYPT_STORE_update_TEST_XRAM_map;
  void decode_ENCRYPT_STORE_update_TEST_XRAM(std::map<int, int>& mem_update_map);
  uint16_t decode_ENCRYPT_STORE_update_ENCRYPT_blk_cnt();
  bool c_1693644;
  uint16_t c_1693638;
  bool c_1693639;
  uint16_t c_1693635;
  uint16_t c_1693641;
  uint16_t c_1693646;
  uint4_t decode_ENCRYPT_STORE_update_ENCRYPT_byte_cnt();
  uint4_t c_1693478;
  uint2_t decode_ENCRYPT_STORE_update_TEST_status();
  bool c_1693659;
  uint16_t c_1693653;
  bool c_1693654;
  uint2_t c_1693656;
  uint2_t c_1693661;
  void compute();
};
