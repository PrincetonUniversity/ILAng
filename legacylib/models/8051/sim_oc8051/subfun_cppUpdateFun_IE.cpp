#include "common.hpp"
#include "model_oc8051_class.hpp"

BIT_VEC model_oc8051::cppUpdateFun_IE()
{
	BIT_VEC cppVar_13434;
	BIT_VEC cppVar_13435;
	bool cppVar_13436;
	BIT_VEC cppVar_13439;
	BIT_VEC cppVar_13440;
	BIT_VEC cppVar_13441;
	BIT_VEC cppVar_13442;
	BIT_VEC cppVar_13443;
	bool cppVar_13444;
	BIT_VEC cppVar_13445;
	BIT_VEC cppVar_13446;
	BIT_VEC cppVar_13447;
	BIT_VEC cppVar_13448;
	BIT_VEC cppVar_13449;
	BIT_VEC cppVar_13450;
	BIT_VEC cppVar_13451;
	BIT_VEC cppVar_13452;
	BIT_VEC cppVar_13453;
	BIT_VEC cppVar_13454;
	BIT_VEC cppVar_13455;
	BIT_VEC cppVar_13438;
	BIT_VEC cppVar_13456;
	bool cppVar_13457;
	BIT_VEC cppVar_13458;
	BIT_VEC cppVar_13459;
	BIT_VEC cppVar_13460;
	BIT_VEC cppVar_13461;
	BIT_VEC cppVar_13462;
	BIT_VEC cppVar_13463;
	BIT_VEC cppVar_13464;
	BIT_VEC cppVar_13467;
	BIT_VEC cppVar_13468;
	BIT_VEC cppVar_13469;
	bool cppVar_13470;
	BIT_VEC cppVar_13471;
	BIT_VEC cppVar_13472;
	BIT_VEC cppVar_13473;
	BIT_VEC cppVar_13474;
	BIT_VEC cppVar_13475;
	BIT_VEC cppVar_13476;
	BIT_VEC cppVar_13477;
	BIT_VEC cppVar_13478;
	BIT_VEC cppVar_13479;
	BIT_VEC cppVar_13466;
	BIT_VEC cppVar_13480;
	BIT_VEC cppVar_13481;
	bool cppVar_13482;
	BIT_VEC cppVar_13484;
	BIT_VEC cppVar_13485;
	BIT_VEC cppVar_13486;
	bool cppVar_13487;
	BIT_VEC cppVar_13488;
	BIT_VEC cppVar_13489;
	BIT_VEC cppVar_13490;
	BIT_VEC cppVar_13491;
	BIT_VEC cppVar_13492;
	BIT_VEC cppVar_13493;
	BIT_VEC cppVar_13494;
	BIT_VEC cppVar_13495;
	BIT_VEC cppVar_13496;
	BIT_VEC cppVar_13483;
	BIT_VEC cppVar_13497;
	BIT_VEC cppVar_13500;
	BIT_VEC cppVar_13501;
	BIT_VEC cppVar_13502;
	bool cppVar_13503;
	BIT_VEC cppVar_13504;
	BIT_VEC cppVar_13505;
	BIT_VEC cppVar_13506;
	BIT_VEC cppVar_13507;
	BIT_VEC cppVar_13508;
	BIT_VEC cppVar_13509;
	BIT_VEC cppVar_13510;
	BIT_VEC cppVar_13511;
	BIT_VEC cppVar_13512;
	BIT_VEC cppVar_13499;
	BIT_VEC cppVar_13513;
	bool cppVar_13514;
	BIT_VEC cppVar_13517;
	BIT_VEC cppVar_13518;
	BIT_VEC cppVar_13519;
	bool cppVar_13520;
	BIT_VEC cppVar_13521;
	BIT_VEC cppVar_13522;
	BIT_VEC cppVar_13523;
	BIT_VEC cppVar_13524;
	BIT_VEC cppVar_13525;
	BIT_VEC cppVar_13526;
	BIT_VEC cppVar_13527;
	BIT_VEC cppVar_13528;
	BIT_VEC cppVar_13529;
	BIT_VEC cppVar_13516;
	BIT_VEC cppVar_13530;
	bool cppVar_13531;
	BIT_VEC cppVar_13534;
	BIT_VEC cppVar_13535;
	BIT_VEC cppVar_13536;
	bool cppVar_13537;
	BIT_VEC cppVar_13538;
	BIT_VEC cppVar_13539;
	BIT_VEC cppVar_13540;
	BIT_VEC cppVar_13541;
	BIT_VEC cppVar_13542;
	BIT_VEC cppVar_13543;
	BIT_VEC cppVar_13544;
	BIT_VEC cppVar_13545;
	BIT_VEC cppVar_13546;
	BIT_VEC cppVar_13533;
	BIT_VEC cppVar_13547;
	bool cppVar_13548;
	BIT_VEC cppVar_13551;
	BIT_VEC cppVar_13552;
	BIT_VEC cppVar_13553;
	bool cppVar_13554;
	BIT_VEC cppVar_13555;
	BIT_VEC cppVar_13556;
	BIT_VEC cppVar_13557;
	BIT_VEC cppVar_13558;
	BIT_VEC cppVar_13559;
	BIT_VEC cppVar_13560;
	BIT_VEC cppVar_13561;
	BIT_VEC cppVar_13562;
	BIT_VEC cppVar_13563;
	BIT_VEC cppVar_13550;
	BIT_VEC cppVar_13564;
	bool cppVar_13565;
	BIT_VEC cppVar_13568;
	BIT_VEC cppVar_13569;
	BIT_VEC cppVar_13570;
	bool cppVar_13571;
	BIT_VEC cppVar_13572;
	BIT_VEC cppVar_13573;
	BIT_VEC cppVar_13574;
	BIT_VEC cppVar_13575;
	BIT_VEC cppVar_13576;
	BIT_VEC cppVar_13577;
	BIT_VEC cppVar_13578;
	BIT_VEC cppVar_13579;
	BIT_VEC cppVar_13580;
	BIT_VEC cppVar_13567;
	BIT_VEC cppVar_13581;
	bool cppVar_13582;
	BIT_VEC cppVar_13585;
	BIT_VEC cppVar_13586;
	BIT_VEC cppVar_13587;
	bool cppVar_13588;
	BIT_VEC cppVar_13589;
	BIT_VEC cppVar_13590;
	BIT_VEC cppVar_13591;
	BIT_VEC cppVar_13592;
	BIT_VEC cppVar_13593;
	BIT_VEC cppVar_13594;
	BIT_VEC cppVar_13595;
	BIT_VEC cppVar_13596;
	BIT_VEC cppVar_13597;
	BIT_VEC cppVar_13584;
	BIT_VEC cppVar_13598;
	bool cppVar_13599;
	BIT_VEC cppVar_13602;
	BIT_VEC cppVar_13603;
	BIT_VEC cppVar_13604;
	bool cppVar_13605;
	BIT_VEC cppVar_13606;
	BIT_VEC cppVar_13607;
	BIT_VEC cppVar_13608;
	BIT_VEC cppVar_13609;
	BIT_VEC cppVar_13610;
	BIT_VEC cppVar_13611;
	BIT_VEC cppVar_13612;
	BIT_VEC cppVar_13613;
	BIT_VEC cppVar_13614;
	BIT_VEC cppVar_13601;
	BIT_VEC cppVar_13615;
	bool cppVar_13616;
	BIT_VEC cppVar_13619;
	BIT_VEC cppVar_13620;
	BIT_VEC cppVar_13621;
	bool cppVar_13622;
	BIT_VEC cppVar_13623;
	BIT_VEC cppVar_13624;
	BIT_VEC cppVar_13625;
	BIT_VEC cppVar_13626;
	BIT_VEC cppVar_13627;
	BIT_VEC cppVar_13628;
	BIT_VEC cppVar_13629;
	BIT_VEC cppVar_13630;
	BIT_VEC cppVar_13631;
	BIT_VEC cppVar_13618;
	BIT_VEC cppVar_13632;
	bool cppVar_13633;
	BIT_VEC cppVar_13636;
	BIT_VEC cppVar_13637;
	BIT_VEC cppVar_13638;
	bool cppVar_13639;
	BIT_VEC cppVar_13640;
	BIT_VEC cppVar_13641;
	BIT_VEC cppVar_13642;
	BIT_VEC cppVar_13643;
	BIT_VEC cppVar_13644;
	BIT_VEC cppVar_13645;
	BIT_VEC cppVar_13646;
	BIT_VEC cppVar_13647;
	BIT_VEC cppVar_13648;
	BIT_VEC cppVar_13635;
	BIT_VEC cppVar_13649;
	bool cppVar_13650;
	BIT_VEC cppVar_13653;
	BIT_VEC cppVar_13654;
	BIT_VEC cppVar_13655;
	bool cppVar_13656;
	BIT_VEC cppVar_13657;
	BIT_VEC cppVar_13658;
	BIT_VEC cppVar_13659;
	BIT_VEC cppVar_13660;
	BIT_VEC cppVar_13661;
	BIT_VEC cppVar_13662;
	BIT_VEC cppVar_13663;
	BIT_VEC cppVar_13664;
	BIT_VEC cppVar_13665;
	BIT_VEC cppVar_13652;
	BIT_VEC cppVar_13666;
	bool cppVar_13667;
	BIT_VEC cppVar_13670;
	BIT_VEC cppVar_13671;
	BIT_VEC cppVar_13672;
	bool cppVar_13673;
	BIT_VEC cppVar_13674;
	BIT_VEC cppVar_13675;
	BIT_VEC cppVar_13676;
	BIT_VEC cppVar_13677;
	BIT_VEC cppVar_13678;
	BIT_VEC cppVar_13679;
	BIT_VEC cppVar_13680;
	BIT_VEC cppVar_13681;
	BIT_VEC cppVar_13682;
	BIT_VEC cppVar_13669;
	BIT_VEC cppVar_13683;
	bool cppVar_13684;
	BIT_VEC cppVar_13687;
	BIT_VEC cppVar_13688;
	BIT_VEC cppVar_13689;
	bool cppVar_13690;
	BIT_VEC cppVar_13691;
	BIT_VEC cppVar_13692;
	BIT_VEC cppVar_13693;
	BIT_VEC cppVar_13694;
	BIT_VEC cppVar_13695;
	BIT_VEC cppVar_13696;
	BIT_VEC cppVar_13697;
	BIT_VEC cppVar_13698;
	BIT_VEC cppVar_13699;
	BIT_VEC cppVar_13686;
	BIT_VEC cppVar_13700;
	bool cppVar_13701;
	BIT_VEC cppVar_13704;
	BIT_VEC cppVar_13705;
	BIT_VEC cppVar_13706;
	bool cppVar_13707;
	BIT_VEC cppVar_13708;
	BIT_VEC cppVar_13709;
	BIT_VEC cppVar_13710;
	BIT_VEC cppVar_13711;
	BIT_VEC cppVar_13712;
	BIT_VEC cppVar_13713;
	BIT_VEC cppVar_13714;
	BIT_VEC cppVar_13715;
	BIT_VEC cppVar_13716;
	BIT_VEC cppVar_13703;
	BIT_VEC cppVar_13717;
	bool cppVar_13718;
	BIT_VEC cppVar_13721;
	BIT_VEC cppVar_13722;
	BIT_VEC cppVar_13723;
	bool cppVar_13724;
	BIT_VEC cppVar_13725;
	BIT_VEC cppVar_13726;
	BIT_VEC cppVar_13727;
	BIT_VEC cppVar_13728;
	BIT_VEC cppVar_13729;
	BIT_VEC cppVar_13730;
	BIT_VEC cppVar_13731;
	BIT_VEC cppVar_13732;
	BIT_VEC cppVar_13733;
	BIT_VEC cppVar_13720;
	BIT_VEC cppVar_13734;
	bool cppVar_13735;
	BIT_VEC cppVar_13738;
	BIT_VEC cppVar_13739;
	BIT_VEC cppVar_13740;
	bool cppVar_13741;
	BIT_VEC cppVar_13742;
	BIT_VEC cppVar_13743;
	BIT_VEC cppVar_13744;
	BIT_VEC cppVar_13745;
	BIT_VEC cppVar_13746;
	BIT_VEC cppVar_13747;
	BIT_VEC cppVar_13748;
	BIT_VEC cppVar_13749;
	BIT_VEC cppVar_13750;
	BIT_VEC cppVar_13737;
	BIT_VEC cppVar_13751;
	bool cppVar_13752;
	BIT_VEC cppVar_13755;
	BIT_VEC cppVar_13756;
	BIT_VEC cppVar_13757;
	bool cppVar_13758;
	BIT_VEC cppVar_13759;
	BIT_VEC cppVar_13760;
	BIT_VEC cppVar_13761;
	BIT_VEC cppVar_13762;
	BIT_VEC cppVar_13763;
	BIT_VEC cppVar_13764;
	BIT_VEC cppVar_13765;
	BIT_VEC cppVar_13766;
	BIT_VEC cppVar_13767;
	BIT_VEC cppVar_13754;
	BIT_VEC cppVar_13768;
	bool cppVar_13769;
	BIT_VEC cppVar_13772;
	BIT_VEC cppVar_13773;
	BIT_VEC cppVar_13774;
	bool cppVar_13775;
	BIT_VEC cppVar_13776;
	BIT_VEC cppVar_13777;
	BIT_VEC cppVar_13778;
	BIT_VEC cppVar_13779;
	BIT_VEC cppVar_13780;
	BIT_VEC cppVar_13781;
	BIT_VEC cppVar_13782;
	BIT_VEC cppVar_13783;
	BIT_VEC cppVar_13784;
	BIT_VEC cppVar_13771;
	BIT_VEC cppVar_13785;
	bool cppVar_13786;
	BIT_VEC cppVar_13789;
	BIT_VEC cppVar_13790;
	BIT_VEC cppVar_13791;
	bool cppVar_13792;
	BIT_VEC cppVar_13793;
	BIT_VEC cppVar_13794;
	BIT_VEC cppVar_13795;
	BIT_VEC cppVar_13796;
	BIT_VEC cppVar_13797;
	BIT_VEC cppVar_13798;
	BIT_VEC cppVar_13799;
	BIT_VEC cppVar_13800;
	BIT_VEC cppVar_13801;
	BIT_VEC cppVar_13788;
	BIT_VEC cppVar_13802;
	bool cppVar_13803;
	BIT_VEC cppVar_13806;
	BIT_VEC cppVar_13807;
	BIT_VEC cppVar_13808;
	bool cppVar_13809;
	BIT_VEC cppVar_13810;
	BIT_VEC cppVar_13811;
	BIT_VEC cppVar_13812;
	BIT_VEC cppVar_13813;
	BIT_VEC cppVar_13814;
	BIT_VEC cppVar_13815;
	BIT_VEC cppVar_13816;
	BIT_VEC cppVar_13817;
	BIT_VEC cppVar_13818;
	BIT_VEC cppVar_13805;
	BIT_VEC cppVar_13819;
	bool cppVar_13820;
	BIT_VEC cppVar_13823;
	BIT_VEC cppVar_13824;
	BIT_VEC cppVar_13825;
	bool cppVar_13826;
	BIT_VEC cppVar_13827;
	BIT_VEC cppVar_13828;
	BIT_VEC cppVar_13829;
	BIT_VEC cppVar_13830;
	BIT_VEC cppVar_13831;
	BIT_VEC cppVar_13832;
	BIT_VEC cppVar_13833;
	BIT_VEC cppVar_13834;
	BIT_VEC cppVar_13835;
	BIT_VEC cppVar_13822;
	BIT_VEC cppVar_13836;
	bool cppVar_13837;
	BIT_VEC cppVar_13840;
	BIT_VEC cppVar_13841;
	BIT_VEC cppVar_13842;
	bool cppVar_13843;
	BIT_VEC cppVar_13844;
	BIT_VEC cppVar_13845;
	BIT_VEC cppVar_13846;
	BIT_VEC cppVar_13847;
	BIT_VEC cppVar_13848;
	BIT_VEC cppVar_13849;
	BIT_VEC cppVar_13850;
	BIT_VEC cppVar_13851;
	BIT_VEC cppVar_13852;
	BIT_VEC cppVar_13839;
	BIT_VEC cppVar_13853;
	bool cppVar_13854;
	BIT_VEC cppVar_13855;
	BIT_VEC cppVar_13838;
	BIT_VEC cppVar_13821;
	BIT_VEC cppVar_13804;
	BIT_VEC cppVar_13787;
	BIT_VEC cppVar_13770;
	BIT_VEC cppVar_13753;
	BIT_VEC cppVar_13736;
	BIT_VEC cppVar_13719;
	BIT_VEC cppVar_13702;
	BIT_VEC cppVar_13685;
	BIT_VEC cppVar_13668;
	BIT_VEC cppVar_13651;
	BIT_VEC cppVar_13634;
	BIT_VEC cppVar_13617;
	BIT_VEC cppVar_13600;
	BIT_VEC cppVar_13583;
	BIT_VEC cppVar_13566;
	BIT_VEC cppVar_13549;
	BIT_VEC cppVar_13532;
	BIT_VEC cppVar_13515;
	BIT_VEC cppVar_13498;
	BIT_VEC cppVar_13465;
	BIT_VEC cppVar_13856;
	BIT_VEC cppVar_13857;
	BIT_VEC cppVar_13858;
	BIT_VEC cppVar_13859;
	BIT_VEC cppVar_13860;
	BIT_VEC cppVar_13861;
	BIT_VEC cppVar_13862;
	BIT_VEC cppVar_13863;
	BIT_VEC cppVar_13864;
	BIT_VEC cppVar_13437;
	BIT_VEC cppVar_13866;
	BIT_VEC cppVar_13867;
	bool cppVar_13868;
	BIT_VEC cppVar_13870;
	BIT_VEC cppVar_13871;
	BIT_VEC cppVar_13872;
	BIT_VEC cppVar_13873;
	bool cppVar_13874;
	BIT_VEC cppVar_13875;
	BIT_VEC cppVar_13869;
	BIT_VEC cppVar_13877;
	BIT_VEC cppVar_13878;
	bool cppVar_13879;
	BIT_VEC cppVar_13880;
	BIT_VEC cppVar_13881;
	bool cppVar_13882;
	bool cppVar_13883;
	BIT_VEC cppVar_13885;
	BIT_VEC cppVar_13886;
	BIT_VEC cppVar_13887;
	BIT_VEC cppVar_13888;
	bool cppVar_13889;
	BIT_VEC cppVar_13884;
	BIT_VEC cppVar_13891;
	BIT_VEC cppVar_13892;
	bool cppVar_13893;
	BIT_VEC cppVar_13896;
	BIT_VEC cppVar_13897;
	BIT_VEC cppVar_13898;
	BIT_VEC cppVar_13899;
	BIT_VEC cppVar_13900;
	bool cppVar_13901;
	BIT_VEC cppVar_13902;
	BIT_VEC cppVar_13903;
	BIT_VEC cppVar_13904;
	BIT_VEC cppVar_13905;
	BIT_VEC cppVar_13906;
	BIT_VEC cppVar_13907;
	BIT_VEC cppVar_13908;
	BIT_VEC cppVar_13909;
	BIT_VEC cppVar_13910;
	BIT_VEC cppVar_13911;
	BIT_VEC cppVar_13912;
	BIT_VEC cppVar_13895;
	BIT_VEC cppVar_13913;
	bool cppVar_13914;
	BIT_VEC cppVar_13915;
	BIT_VEC cppVar_13916;
	BIT_VEC cppVar_13917;
	BIT_VEC cppVar_13918;
	BIT_VEC cppVar_13919;
	BIT_VEC cppVar_13920;
	BIT_VEC cppVar_13921;
	BIT_VEC cppVar_13924;
	BIT_VEC cppVar_13925;
	BIT_VEC cppVar_13926;
	bool cppVar_13927;
	BIT_VEC cppVar_13928;
	BIT_VEC cppVar_13929;
	BIT_VEC cppVar_13930;
	BIT_VEC cppVar_13931;
	BIT_VEC cppVar_13932;
	BIT_VEC cppVar_13933;
	BIT_VEC cppVar_13934;
	BIT_VEC cppVar_13935;
	BIT_VEC cppVar_13936;
	BIT_VEC cppVar_13923;
	BIT_VEC cppVar_13937;
	BIT_VEC cppVar_13938;
	bool cppVar_13939;
	BIT_VEC cppVar_13941;
	BIT_VEC cppVar_13942;
	BIT_VEC cppVar_13943;
	bool cppVar_13944;
	BIT_VEC cppVar_13945;
	BIT_VEC cppVar_13946;
	BIT_VEC cppVar_13947;
	BIT_VEC cppVar_13948;
	BIT_VEC cppVar_13949;
	BIT_VEC cppVar_13950;
	BIT_VEC cppVar_13951;
	BIT_VEC cppVar_13952;
	BIT_VEC cppVar_13953;
	BIT_VEC cppVar_13940;
	BIT_VEC cppVar_13954;
	BIT_VEC cppVar_13957;
	BIT_VEC cppVar_13958;
	BIT_VEC cppVar_13959;
	bool cppVar_13960;
	BIT_VEC cppVar_13961;
	BIT_VEC cppVar_13962;
	BIT_VEC cppVar_13963;
	BIT_VEC cppVar_13964;
	BIT_VEC cppVar_13965;
	BIT_VEC cppVar_13966;
	BIT_VEC cppVar_13967;
	BIT_VEC cppVar_13968;
	BIT_VEC cppVar_13969;
	BIT_VEC cppVar_13956;
	BIT_VEC cppVar_13970;
	bool cppVar_13971;
	BIT_VEC cppVar_13974;
	BIT_VEC cppVar_13975;
	BIT_VEC cppVar_13976;
	bool cppVar_13977;
	BIT_VEC cppVar_13978;
	BIT_VEC cppVar_13979;
	BIT_VEC cppVar_13980;
	BIT_VEC cppVar_13981;
	BIT_VEC cppVar_13982;
	BIT_VEC cppVar_13983;
	BIT_VEC cppVar_13984;
	BIT_VEC cppVar_13985;
	BIT_VEC cppVar_13986;
	BIT_VEC cppVar_13973;
	BIT_VEC cppVar_13987;
	bool cppVar_13988;
	BIT_VEC cppVar_13991;
	BIT_VEC cppVar_13992;
	BIT_VEC cppVar_13993;
	bool cppVar_13994;
	BIT_VEC cppVar_13995;
	BIT_VEC cppVar_13996;
	BIT_VEC cppVar_13997;
	BIT_VEC cppVar_13998;
	BIT_VEC cppVar_13999;
	BIT_VEC cppVar_14000;
	BIT_VEC cppVar_14001;
	BIT_VEC cppVar_14002;
	BIT_VEC cppVar_14003;
	BIT_VEC cppVar_13990;
	BIT_VEC cppVar_14004;
	bool cppVar_14005;
	BIT_VEC cppVar_14008;
	BIT_VEC cppVar_14009;
	BIT_VEC cppVar_14010;
	bool cppVar_14011;
	BIT_VEC cppVar_14012;
	BIT_VEC cppVar_14013;
	BIT_VEC cppVar_14014;
	BIT_VEC cppVar_14015;
	BIT_VEC cppVar_14016;
	BIT_VEC cppVar_14017;
	BIT_VEC cppVar_14018;
	BIT_VEC cppVar_14019;
	BIT_VEC cppVar_14020;
	BIT_VEC cppVar_14007;
	BIT_VEC cppVar_14021;
	bool cppVar_14022;
	BIT_VEC cppVar_14025;
	BIT_VEC cppVar_14026;
	BIT_VEC cppVar_14027;
	bool cppVar_14028;
	BIT_VEC cppVar_14029;
	BIT_VEC cppVar_14030;
	BIT_VEC cppVar_14031;
	BIT_VEC cppVar_14032;
	BIT_VEC cppVar_14033;
	BIT_VEC cppVar_14034;
	BIT_VEC cppVar_14035;
	BIT_VEC cppVar_14036;
	BIT_VEC cppVar_14037;
	BIT_VEC cppVar_14024;
	BIT_VEC cppVar_14038;
	bool cppVar_14039;
	BIT_VEC cppVar_14042;
	BIT_VEC cppVar_14043;
	BIT_VEC cppVar_14044;
	bool cppVar_14045;
	BIT_VEC cppVar_14046;
	BIT_VEC cppVar_14047;
	BIT_VEC cppVar_14048;
	BIT_VEC cppVar_14049;
	BIT_VEC cppVar_14050;
	BIT_VEC cppVar_14051;
	BIT_VEC cppVar_14052;
	BIT_VEC cppVar_14053;
	BIT_VEC cppVar_14054;
	BIT_VEC cppVar_14041;
	BIT_VEC cppVar_14055;
	bool cppVar_14056;
	BIT_VEC cppVar_14059;
	BIT_VEC cppVar_14060;
	BIT_VEC cppVar_14061;
	bool cppVar_14062;
	BIT_VEC cppVar_14063;
	BIT_VEC cppVar_14064;
	BIT_VEC cppVar_14065;
	BIT_VEC cppVar_14066;
	BIT_VEC cppVar_14067;
	BIT_VEC cppVar_14068;
	BIT_VEC cppVar_14069;
	BIT_VEC cppVar_14070;
	BIT_VEC cppVar_14071;
	BIT_VEC cppVar_14058;
	BIT_VEC cppVar_14072;
	bool cppVar_14073;
	BIT_VEC cppVar_14076;
	BIT_VEC cppVar_14077;
	BIT_VEC cppVar_14078;
	bool cppVar_14079;
	BIT_VEC cppVar_14080;
	BIT_VEC cppVar_14081;
	BIT_VEC cppVar_14082;
	BIT_VEC cppVar_14083;
	BIT_VEC cppVar_14084;
	BIT_VEC cppVar_14085;
	BIT_VEC cppVar_14086;
	BIT_VEC cppVar_14087;
	BIT_VEC cppVar_14088;
	BIT_VEC cppVar_14075;
	BIT_VEC cppVar_14089;
	bool cppVar_14090;
	BIT_VEC cppVar_14093;
	BIT_VEC cppVar_14094;
	BIT_VEC cppVar_14095;
	bool cppVar_14096;
	BIT_VEC cppVar_14097;
	BIT_VEC cppVar_14098;
	BIT_VEC cppVar_14099;
	BIT_VEC cppVar_14100;
	BIT_VEC cppVar_14101;
	BIT_VEC cppVar_14102;
	BIT_VEC cppVar_14103;
	BIT_VEC cppVar_14104;
	BIT_VEC cppVar_14105;
	BIT_VEC cppVar_14092;
	BIT_VEC cppVar_14106;
	bool cppVar_14107;
	BIT_VEC cppVar_14110;
	BIT_VEC cppVar_14111;
	BIT_VEC cppVar_14112;
	bool cppVar_14113;
	BIT_VEC cppVar_14114;
	BIT_VEC cppVar_14115;
	BIT_VEC cppVar_14116;
	BIT_VEC cppVar_14117;
	BIT_VEC cppVar_14118;
	BIT_VEC cppVar_14119;
	BIT_VEC cppVar_14120;
	BIT_VEC cppVar_14121;
	BIT_VEC cppVar_14122;
	BIT_VEC cppVar_14109;
	BIT_VEC cppVar_14123;
	bool cppVar_14124;
	BIT_VEC cppVar_14127;
	BIT_VEC cppVar_14128;
	BIT_VEC cppVar_14129;
	bool cppVar_14130;
	BIT_VEC cppVar_14131;
	BIT_VEC cppVar_14132;
	BIT_VEC cppVar_14133;
	BIT_VEC cppVar_14134;
	BIT_VEC cppVar_14135;
	BIT_VEC cppVar_14136;
	BIT_VEC cppVar_14137;
	BIT_VEC cppVar_14138;
	BIT_VEC cppVar_14139;
	BIT_VEC cppVar_14126;
	BIT_VEC cppVar_14140;
	bool cppVar_14141;
	BIT_VEC cppVar_14144;
	BIT_VEC cppVar_14145;
	BIT_VEC cppVar_14146;
	bool cppVar_14147;
	BIT_VEC cppVar_14148;
	BIT_VEC cppVar_14149;
	BIT_VEC cppVar_14150;
	BIT_VEC cppVar_14151;
	BIT_VEC cppVar_14152;
	BIT_VEC cppVar_14153;
	BIT_VEC cppVar_14154;
	BIT_VEC cppVar_14155;
	BIT_VEC cppVar_14156;
	BIT_VEC cppVar_14143;
	BIT_VEC cppVar_14157;
	bool cppVar_14158;
	BIT_VEC cppVar_14161;
	BIT_VEC cppVar_14162;
	BIT_VEC cppVar_14163;
	bool cppVar_14164;
	BIT_VEC cppVar_14165;
	BIT_VEC cppVar_14166;
	BIT_VEC cppVar_14167;
	BIT_VEC cppVar_14168;
	BIT_VEC cppVar_14169;
	BIT_VEC cppVar_14170;
	BIT_VEC cppVar_14171;
	BIT_VEC cppVar_14172;
	BIT_VEC cppVar_14173;
	BIT_VEC cppVar_14160;
	BIT_VEC cppVar_14174;
	bool cppVar_14175;
	BIT_VEC cppVar_14178;
	BIT_VEC cppVar_14179;
	BIT_VEC cppVar_14180;
	bool cppVar_14181;
	BIT_VEC cppVar_14182;
	BIT_VEC cppVar_14183;
	BIT_VEC cppVar_14184;
	BIT_VEC cppVar_14185;
	BIT_VEC cppVar_14186;
	BIT_VEC cppVar_14187;
	BIT_VEC cppVar_14188;
	BIT_VEC cppVar_14189;
	BIT_VEC cppVar_14190;
	BIT_VEC cppVar_14177;
	BIT_VEC cppVar_14191;
	bool cppVar_14192;
	BIT_VEC cppVar_14195;
	BIT_VEC cppVar_14196;
	BIT_VEC cppVar_14197;
	bool cppVar_14198;
	BIT_VEC cppVar_14199;
	BIT_VEC cppVar_14200;
	BIT_VEC cppVar_14201;
	BIT_VEC cppVar_14202;
	BIT_VEC cppVar_14203;
	BIT_VEC cppVar_14204;
	BIT_VEC cppVar_14205;
	BIT_VEC cppVar_14206;
	BIT_VEC cppVar_14207;
	BIT_VEC cppVar_14194;
	BIT_VEC cppVar_14208;
	bool cppVar_14209;
	BIT_VEC cppVar_14212;
	BIT_VEC cppVar_14213;
	BIT_VEC cppVar_14214;
	bool cppVar_14215;
	BIT_VEC cppVar_14216;
	BIT_VEC cppVar_14217;
	BIT_VEC cppVar_14218;
	BIT_VEC cppVar_14219;
	BIT_VEC cppVar_14220;
	BIT_VEC cppVar_14221;
	BIT_VEC cppVar_14222;
	BIT_VEC cppVar_14223;
	BIT_VEC cppVar_14224;
	BIT_VEC cppVar_14211;
	BIT_VEC cppVar_14225;
	bool cppVar_14226;
	BIT_VEC cppVar_14229;
	BIT_VEC cppVar_14230;
	BIT_VEC cppVar_14231;
	bool cppVar_14232;
	BIT_VEC cppVar_14233;
	BIT_VEC cppVar_14234;
	BIT_VEC cppVar_14235;
	BIT_VEC cppVar_14236;
	BIT_VEC cppVar_14237;
	BIT_VEC cppVar_14238;
	BIT_VEC cppVar_14239;
	BIT_VEC cppVar_14240;
	BIT_VEC cppVar_14241;
	BIT_VEC cppVar_14228;
	BIT_VEC cppVar_14242;
	bool cppVar_14243;
	BIT_VEC cppVar_14246;
	BIT_VEC cppVar_14247;
	BIT_VEC cppVar_14248;
	bool cppVar_14249;
	BIT_VEC cppVar_14250;
	BIT_VEC cppVar_14251;
	BIT_VEC cppVar_14252;
	BIT_VEC cppVar_14253;
	BIT_VEC cppVar_14254;
	BIT_VEC cppVar_14255;
	BIT_VEC cppVar_14256;
	BIT_VEC cppVar_14257;
	BIT_VEC cppVar_14258;
	BIT_VEC cppVar_14245;
	BIT_VEC cppVar_14259;
	bool cppVar_14260;
	BIT_VEC cppVar_14263;
	BIT_VEC cppVar_14264;
	BIT_VEC cppVar_14265;
	bool cppVar_14266;
	BIT_VEC cppVar_14267;
	BIT_VEC cppVar_14268;
	BIT_VEC cppVar_14269;
	BIT_VEC cppVar_14270;
	BIT_VEC cppVar_14271;
	BIT_VEC cppVar_14272;
	BIT_VEC cppVar_14273;
	BIT_VEC cppVar_14274;
	BIT_VEC cppVar_14275;
	BIT_VEC cppVar_14262;
	BIT_VEC cppVar_14276;
	bool cppVar_14277;
	BIT_VEC cppVar_14280;
	BIT_VEC cppVar_14281;
	BIT_VEC cppVar_14282;
	bool cppVar_14283;
	BIT_VEC cppVar_14284;
	BIT_VEC cppVar_14285;
	BIT_VEC cppVar_14286;
	BIT_VEC cppVar_14287;
	BIT_VEC cppVar_14288;
	BIT_VEC cppVar_14289;
	BIT_VEC cppVar_14290;
	BIT_VEC cppVar_14291;
	BIT_VEC cppVar_14292;
	BIT_VEC cppVar_14279;
	BIT_VEC cppVar_14293;
	bool cppVar_14294;
	BIT_VEC cppVar_14297;
	BIT_VEC cppVar_14298;
	BIT_VEC cppVar_14299;
	bool cppVar_14300;
	BIT_VEC cppVar_14301;
	BIT_VEC cppVar_14302;
	BIT_VEC cppVar_14303;
	BIT_VEC cppVar_14304;
	BIT_VEC cppVar_14305;
	BIT_VEC cppVar_14306;
	BIT_VEC cppVar_14307;
	BIT_VEC cppVar_14308;
	BIT_VEC cppVar_14309;
	BIT_VEC cppVar_14296;
	BIT_VEC cppVar_14310;
	bool cppVar_14311;
	BIT_VEC cppVar_14312;
	BIT_VEC cppVar_14295;
	BIT_VEC cppVar_14278;
	BIT_VEC cppVar_14261;
	BIT_VEC cppVar_14244;
	BIT_VEC cppVar_14227;
	BIT_VEC cppVar_14210;
	BIT_VEC cppVar_14193;
	BIT_VEC cppVar_14176;
	BIT_VEC cppVar_14159;
	BIT_VEC cppVar_14142;
	BIT_VEC cppVar_14125;
	BIT_VEC cppVar_14108;
	BIT_VEC cppVar_14091;
	BIT_VEC cppVar_14074;
	BIT_VEC cppVar_14057;
	BIT_VEC cppVar_14040;
	BIT_VEC cppVar_14023;
	BIT_VEC cppVar_14006;
	BIT_VEC cppVar_13989;
	BIT_VEC cppVar_13972;
	BIT_VEC cppVar_13955;
	BIT_VEC cppVar_13922;
	BIT_VEC cppVar_14313;
	BIT_VEC cppVar_14316;
	BIT_VEC cppVar_14317;
	BIT_VEC cppVar_14318;
	BIT_VEC cppVar_14319;
	bool cppVar_14320;
	BIT_VEC cppVar_14321;
	BIT_VEC cppVar_14322;
	BIT_VEC cppVar_14323;
	BIT_VEC cppVar_14324;
	BIT_VEC cppVar_14325;
	BIT_VEC cppVar_14326;
	BIT_VEC cppVar_14327;
	BIT_VEC cppVar_14328;
	BIT_VEC cppVar_14329;
	BIT_VEC cppVar_14330;
	BIT_VEC cppVar_14331;
	BIT_VEC cppVar_14315;
	BIT_VEC cppVar_14332;
	BIT_VEC cppVar_14333;
	bool cppVar_14334;
	BIT_VEC cppVar_14336;
	BIT_VEC cppVar_14337;
	BIT_VEC cppVar_14338;
	bool cppVar_14339;
	BIT_VEC cppVar_14340;
	BIT_VEC cppVar_14341;
	BIT_VEC cppVar_14342;
	BIT_VEC cppVar_14343;
	BIT_VEC cppVar_14344;
	BIT_VEC cppVar_14345;
	BIT_VEC cppVar_14346;
	BIT_VEC cppVar_14347;
	BIT_VEC cppVar_14348;
	BIT_VEC cppVar_14335;
	BIT_VEC cppVar_14349;
	BIT_VEC cppVar_14352;
	BIT_VEC cppVar_14353;
	BIT_VEC cppVar_14354;
	bool cppVar_14355;
	BIT_VEC cppVar_14356;
	BIT_VEC cppVar_14357;
	BIT_VEC cppVar_14358;
	BIT_VEC cppVar_14359;
	BIT_VEC cppVar_14360;
	BIT_VEC cppVar_14361;
	BIT_VEC cppVar_14362;
	BIT_VEC cppVar_14363;
	BIT_VEC cppVar_14364;
	BIT_VEC cppVar_14351;
	BIT_VEC cppVar_14365;
	bool cppVar_14366;
	BIT_VEC cppVar_14369;
	BIT_VEC cppVar_14370;
	BIT_VEC cppVar_14371;
	bool cppVar_14372;
	BIT_VEC cppVar_14373;
	BIT_VEC cppVar_14374;
	BIT_VEC cppVar_14375;
	BIT_VEC cppVar_14376;
	BIT_VEC cppVar_14377;
	BIT_VEC cppVar_14378;
	BIT_VEC cppVar_14379;
	BIT_VEC cppVar_14380;
	BIT_VEC cppVar_14381;
	BIT_VEC cppVar_14368;
	BIT_VEC cppVar_14382;
	bool cppVar_14383;
	BIT_VEC cppVar_14386;
	BIT_VEC cppVar_14387;
	BIT_VEC cppVar_14388;
	bool cppVar_14389;
	BIT_VEC cppVar_14390;
	BIT_VEC cppVar_14391;
	BIT_VEC cppVar_14392;
	BIT_VEC cppVar_14393;
	BIT_VEC cppVar_14394;
	BIT_VEC cppVar_14395;
	BIT_VEC cppVar_14396;
	BIT_VEC cppVar_14397;
	BIT_VEC cppVar_14398;
	BIT_VEC cppVar_14385;
	BIT_VEC cppVar_14399;
	bool cppVar_14400;
	BIT_VEC cppVar_14403;
	BIT_VEC cppVar_14404;
	BIT_VEC cppVar_14405;
	bool cppVar_14406;
	BIT_VEC cppVar_14407;
	BIT_VEC cppVar_14408;
	BIT_VEC cppVar_14409;
	BIT_VEC cppVar_14410;
	BIT_VEC cppVar_14411;
	BIT_VEC cppVar_14412;
	BIT_VEC cppVar_14413;
	BIT_VEC cppVar_14414;
	BIT_VEC cppVar_14415;
	BIT_VEC cppVar_14402;
	BIT_VEC cppVar_14416;
	bool cppVar_14417;
	BIT_VEC cppVar_14420;
	BIT_VEC cppVar_14421;
	BIT_VEC cppVar_14422;
	bool cppVar_14423;
	BIT_VEC cppVar_14424;
	BIT_VEC cppVar_14425;
	BIT_VEC cppVar_14426;
	BIT_VEC cppVar_14427;
	BIT_VEC cppVar_14428;
	BIT_VEC cppVar_14429;
	BIT_VEC cppVar_14430;
	BIT_VEC cppVar_14431;
	BIT_VEC cppVar_14432;
	BIT_VEC cppVar_14419;
	BIT_VEC cppVar_14433;
	bool cppVar_14434;
	BIT_VEC cppVar_14437;
	BIT_VEC cppVar_14438;
	BIT_VEC cppVar_14439;
	bool cppVar_14440;
	BIT_VEC cppVar_14441;
	BIT_VEC cppVar_14442;
	BIT_VEC cppVar_14443;
	BIT_VEC cppVar_14444;
	BIT_VEC cppVar_14445;
	BIT_VEC cppVar_14446;
	BIT_VEC cppVar_14447;
	BIT_VEC cppVar_14448;
	BIT_VEC cppVar_14449;
	BIT_VEC cppVar_14436;
	BIT_VEC cppVar_14450;
	bool cppVar_14451;
	BIT_VEC cppVar_14454;
	BIT_VEC cppVar_14455;
	BIT_VEC cppVar_14456;
	bool cppVar_14457;
	BIT_VEC cppVar_14458;
	BIT_VEC cppVar_14459;
	BIT_VEC cppVar_14460;
	BIT_VEC cppVar_14461;
	BIT_VEC cppVar_14462;
	BIT_VEC cppVar_14463;
	BIT_VEC cppVar_14464;
	BIT_VEC cppVar_14465;
	BIT_VEC cppVar_14466;
	BIT_VEC cppVar_14453;
	BIT_VEC cppVar_14467;
	bool cppVar_14468;
	BIT_VEC cppVar_14471;
	BIT_VEC cppVar_14472;
	BIT_VEC cppVar_14473;
	bool cppVar_14474;
	BIT_VEC cppVar_14475;
	BIT_VEC cppVar_14476;
	BIT_VEC cppVar_14477;
	BIT_VEC cppVar_14478;
	BIT_VEC cppVar_14479;
	BIT_VEC cppVar_14480;
	BIT_VEC cppVar_14481;
	BIT_VEC cppVar_14482;
	BIT_VEC cppVar_14483;
	BIT_VEC cppVar_14470;
	BIT_VEC cppVar_14484;
	bool cppVar_14485;
	BIT_VEC cppVar_14488;
	BIT_VEC cppVar_14489;
	BIT_VEC cppVar_14490;
	bool cppVar_14491;
	BIT_VEC cppVar_14492;
	BIT_VEC cppVar_14493;
	BIT_VEC cppVar_14494;
	BIT_VEC cppVar_14495;
	BIT_VEC cppVar_14496;
	BIT_VEC cppVar_14497;
	BIT_VEC cppVar_14498;
	BIT_VEC cppVar_14499;
	BIT_VEC cppVar_14500;
	BIT_VEC cppVar_14487;
	BIT_VEC cppVar_14501;
	bool cppVar_14502;
	BIT_VEC cppVar_14505;
	BIT_VEC cppVar_14506;
	BIT_VEC cppVar_14507;
	bool cppVar_14508;
	BIT_VEC cppVar_14509;
	BIT_VEC cppVar_14510;
	BIT_VEC cppVar_14511;
	BIT_VEC cppVar_14512;
	BIT_VEC cppVar_14513;
	BIT_VEC cppVar_14514;
	BIT_VEC cppVar_14515;
	BIT_VEC cppVar_14516;
	BIT_VEC cppVar_14517;
	BIT_VEC cppVar_14504;
	BIT_VEC cppVar_14518;
	bool cppVar_14519;
	BIT_VEC cppVar_14522;
	BIT_VEC cppVar_14523;
	BIT_VEC cppVar_14524;
	bool cppVar_14525;
	BIT_VEC cppVar_14526;
	BIT_VEC cppVar_14527;
	BIT_VEC cppVar_14528;
	BIT_VEC cppVar_14529;
	BIT_VEC cppVar_14530;
	BIT_VEC cppVar_14531;
	BIT_VEC cppVar_14532;
	BIT_VEC cppVar_14533;
	BIT_VEC cppVar_14534;
	BIT_VEC cppVar_14521;
	BIT_VEC cppVar_14535;
	bool cppVar_14536;
	BIT_VEC cppVar_14539;
	BIT_VEC cppVar_14540;
	BIT_VEC cppVar_14541;
	bool cppVar_14542;
	BIT_VEC cppVar_14543;
	BIT_VEC cppVar_14544;
	BIT_VEC cppVar_14545;
	BIT_VEC cppVar_14546;
	BIT_VEC cppVar_14547;
	BIT_VEC cppVar_14548;
	BIT_VEC cppVar_14549;
	BIT_VEC cppVar_14550;
	BIT_VEC cppVar_14551;
	BIT_VEC cppVar_14538;
	BIT_VEC cppVar_14552;
	bool cppVar_14553;
	BIT_VEC cppVar_14556;
	BIT_VEC cppVar_14557;
	BIT_VEC cppVar_14558;
	bool cppVar_14559;
	BIT_VEC cppVar_14560;
	BIT_VEC cppVar_14561;
	BIT_VEC cppVar_14562;
	BIT_VEC cppVar_14563;
	BIT_VEC cppVar_14564;
	BIT_VEC cppVar_14565;
	BIT_VEC cppVar_14566;
	BIT_VEC cppVar_14567;
	BIT_VEC cppVar_14568;
	BIT_VEC cppVar_14555;
	BIT_VEC cppVar_14569;
	bool cppVar_14570;
	BIT_VEC cppVar_14573;
	BIT_VEC cppVar_14574;
	BIT_VEC cppVar_14575;
	bool cppVar_14576;
	BIT_VEC cppVar_14577;
	BIT_VEC cppVar_14578;
	BIT_VEC cppVar_14579;
	BIT_VEC cppVar_14580;
	BIT_VEC cppVar_14581;
	BIT_VEC cppVar_14582;
	BIT_VEC cppVar_14583;
	BIT_VEC cppVar_14584;
	BIT_VEC cppVar_14585;
	BIT_VEC cppVar_14572;
	BIT_VEC cppVar_14586;
	bool cppVar_14587;
	BIT_VEC cppVar_14590;
	BIT_VEC cppVar_14591;
	BIT_VEC cppVar_14592;
	bool cppVar_14593;
	BIT_VEC cppVar_14594;
	BIT_VEC cppVar_14595;
	BIT_VEC cppVar_14596;
	BIT_VEC cppVar_14597;
	BIT_VEC cppVar_14598;
	BIT_VEC cppVar_14599;
	BIT_VEC cppVar_14600;
	BIT_VEC cppVar_14601;
	BIT_VEC cppVar_14602;
	BIT_VEC cppVar_14589;
	BIT_VEC cppVar_14603;
	bool cppVar_14604;
	BIT_VEC cppVar_14607;
	BIT_VEC cppVar_14608;
	BIT_VEC cppVar_14609;
	bool cppVar_14610;
	BIT_VEC cppVar_14611;
	BIT_VEC cppVar_14612;
	BIT_VEC cppVar_14613;
	BIT_VEC cppVar_14614;
	BIT_VEC cppVar_14615;
	BIT_VEC cppVar_14616;
	BIT_VEC cppVar_14617;
	BIT_VEC cppVar_14618;
	BIT_VEC cppVar_14619;
	BIT_VEC cppVar_14606;
	BIT_VEC cppVar_14620;
	bool cppVar_14621;
	BIT_VEC cppVar_14624;
	BIT_VEC cppVar_14625;
	BIT_VEC cppVar_14626;
	bool cppVar_14627;
	BIT_VEC cppVar_14628;
	BIT_VEC cppVar_14629;
	BIT_VEC cppVar_14630;
	BIT_VEC cppVar_14631;
	BIT_VEC cppVar_14632;
	BIT_VEC cppVar_14633;
	BIT_VEC cppVar_14634;
	BIT_VEC cppVar_14635;
	BIT_VEC cppVar_14636;
	BIT_VEC cppVar_14623;
	BIT_VEC cppVar_14637;
	bool cppVar_14638;
	BIT_VEC cppVar_14641;
	BIT_VEC cppVar_14642;
	BIT_VEC cppVar_14643;
	bool cppVar_14644;
	BIT_VEC cppVar_14645;
	BIT_VEC cppVar_14646;
	BIT_VEC cppVar_14647;
	BIT_VEC cppVar_14648;
	BIT_VEC cppVar_14649;
	BIT_VEC cppVar_14650;
	BIT_VEC cppVar_14651;
	BIT_VEC cppVar_14652;
	BIT_VEC cppVar_14653;
	BIT_VEC cppVar_14640;
	BIT_VEC cppVar_14654;
	bool cppVar_14655;
	BIT_VEC cppVar_14658;
	BIT_VEC cppVar_14659;
	BIT_VEC cppVar_14660;
	bool cppVar_14661;
	BIT_VEC cppVar_14662;
	BIT_VEC cppVar_14663;
	BIT_VEC cppVar_14664;
	BIT_VEC cppVar_14665;
	BIT_VEC cppVar_14666;
	BIT_VEC cppVar_14667;
	BIT_VEC cppVar_14668;
	BIT_VEC cppVar_14669;
	BIT_VEC cppVar_14670;
	BIT_VEC cppVar_14657;
	BIT_VEC cppVar_14671;
	bool cppVar_14672;
	BIT_VEC cppVar_14675;
	BIT_VEC cppVar_14676;
	BIT_VEC cppVar_14677;
	bool cppVar_14678;
	BIT_VEC cppVar_14679;
	BIT_VEC cppVar_14680;
	BIT_VEC cppVar_14681;
	BIT_VEC cppVar_14682;
	BIT_VEC cppVar_14683;
	BIT_VEC cppVar_14684;
	BIT_VEC cppVar_14685;
	BIT_VEC cppVar_14686;
	BIT_VEC cppVar_14687;
	BIT_VEC cppVar_14674;
	BIT_VEC cppVar_14688;
	bool cppVar_14689;
	BIT_VEC cppVar_14692;
	BIT_VEC cppVar_14693;
	BIT_VEC cppVar_14694;
	bool cppVar_14695;
	BIT_VEC cppVar_14696;
	BIT_VEC cppVar_14697;
	BIT_VEC cppVar_14698;
	BIT_VEC cppVar_14699;
	BIT_VEC cppVar_14700;
	BIT_VEC cppVar_14701;
	BIT_VEC cppVar_14702;
	BIT_VEC cppVar_14703;
	BIT_VEC cppVar_14704;
	BIT_VEC cppVar_14691;
	BIT_VEC cppVar_14705;
	bool cppVar_14706;
	BIT_VEC cppVar_14707;
	BIT_VEC cppVar_14690;
	BIT_VEC cppVar_14673;
	BIT_VEC cppVar_14656;
	BIT_VEC cppVar_14639;
	BIT_VEC cppVar_14622;
	BIT_VEC cppVar_14605;
	BIT_VEC cppVar_14588;
	BIT_VEC cppVar_14571;
	BIT_VEC cppVar_14554;
	BIT_VEC cppVar_14537;
	BIT_VEC cppVar_14520;
	BIT_VEC cppVar_14503;
	BIT_VEC cppVar_14486;
	BIT_VEC cppVar_14469;
	BIT_VEC cppVar_14452;
	BIT_VEC cppVar_14435;
	BIT_VEC cppVar_14418;
	BIT_VEC cppVar_14401;
	BIT_VEC cppVar_14384;
	BIT_VEC cppVar_14367;
	BIT_VEC cppVar_14350;
	BIT_VEC cppVar_14314;
	BIT_VEC cppVar_14708;
	BIT_VEC cppVar_14709;
	BIT_VEC cppVar_14710;
	BIT_VEC cppVar_14711;
	BIT_VEC cppVar_14712;
	BIT_VEC cppVar_14713;
	BIT_VEC cppVar_14714;
	BIT_VEC cppVar_14715;
	BIT_VEC cppVar_14716;
	BIT_VEC cppVar_14717;
	BIT_VEC cppVar_14718;
	BIT_VEC cppVar_14719;
	BIT_VEC cppVar_13894;
	BIT_VEC cppVar_14721;
	BIT_VEC cppVar_14722;
	bool cppVar_14723;
	BIT_VEC cppVar_14726;
	BIT_VEC cppVar_14727;
	BIT_VEC cppVar_14728;
	BIT_VEC cppVar_14729;
	BIT_VEC cppVar_14730;
	bool cppVar_14731;
	BIT_VEC cppVar_14732;
	BIT_VEC cppVar_14733;
	BIT_VEC cppVar_14734;
	BIT_VEC cppVar_14735;
	BIT_VEC cppVar_14736;
	BIT_VEC cppVar_14737;
	BIT_VEC cppVar_14738;
	BIT_VEC cppVar_14739;
	BIT_VEC cppVar_14740;
	BIT_VEC cppVar_14741;
	BIT_VEC cppVar_14742;
	BIT_VEC cppVar_14725;
	BIT_VEC cppVar_14743;
	bool cppVar_14744;
	BIT_VEC cppVar_14745;
	BIT_VEC cppVar_14746;
	BIT_VEC cppVar_14747;
	BIT_VEC cppVar_14748;
	BIT_VEC cppVar_14749;
	BIT_VEC cppVar_14750;
	BIT_VEC cppVar_14751;
	BIT_VEC cppVar_14754;
	BIT_VEC cppVar_14755;
	BIT_VEC cppVar_14756;
	bool cppVar_14757;
	BIT_VEC cppVar_14758;
	BIT_VEC cppVar_14759;
	BIT_VEC cppVar_14760;
	BIT_VEC cppVar_14761;
	BIT_VEC cppVar_14762;
	BIT_VEC cppVar_14763;
	BIT_VEC cppVar_14764;
	BIT_VEC cppVar_14765;
	BIT_VEC cppVar_14766;
	BIT_VEC cppVar_14753;
	BIT_VEC cppVar_14767;
	BIT_VEC cppVar_14768;
	bool cppVar_14769;
	BIT_VEC cppVar_14771;
	BIT_VEC cppVar_14772;
	BIT_VEC cppVar_14773;
	bool cppVar_14774;
	BIT_VEC cppVar_14775;
	BIT_VEC cppVar_14776;
	BIT_VEC cppVar_14777;
	BIT_VEC cppVar_14778;
	BIT_VEC cppVar_14779;
	BIT_VEC cppVar_14780;
	BIT_VEC cppVar_14781;
	BIT_VEC cppVar_14782;
	BIT_VEC cppVar_14783;
	BIT_VEC cppVar_14770;
	BIT_VEC cppVar_14784;
	BIT_VEC cppVar_14787;
	BIT_VEC cppVar_14788;
	BIT_VEC cppVar_14789;
	bool cppVar_14790;
	BIT_VEC cppVar_14791;
	BIT_VEC cppVar_14792;
	BIT_VEC cppVar_14793;
	BIT_VEC cppVar_14794;
	BIT_VEC cppVar_14795;
	BIT_VEC cppVar_14796;
	BIT_VEC cppVar_14797;
	BIT_VEC cppVar_14798;
	BIT_VEC cppVar_14799;
	BIT_VEC cppVar_14786;
	BIT_VEC cppVar_14800;
	bool cppVar_14801;
	BIT_VEC cppVar_14804;
	BIT_VEC cppVar_14805;
	BIT_VEC cppVar_14806;
	bool cppVar_14807;
	BIT_VEC cppVar_14808;
	BIT_VEC cppVar_14809;
	BIT_VEC cppVar_14810;
	BIT_VEC cppVar_14811;
	BIT_VEC cppVar_14812;
	BIT_VEC cppVar_14813;
	BIT_VEC cppVar_14814;
	BIT_VEC cppVar_14815;
	BIT_VEC cppVar_14816;
	BIT_VEC cppVar_14803;
	BIT_VEC cppVar_14817;
	bool cppVar_14818;
	BIT_VEC cppVar_14821;
	BIT_VEC cppVar_14822;
	BIT_VEC cppVar_14823;
	bool cppVar_14824;
	BIT_VEC cppVar_14825;
	BIT_VEC cppVar_14826;
	BIT_VEC cppVar_14827;
	BIT_VEC cppVar_14828;
	BIT_VEC cppVar_14829;
	BIT_VEC cppVar_14830;
	BIT_VEC cppVar_14831;
	BIT_VEC cppVar_14832;
	BIT_VEC cppVar_14833;
	BIT_VEC cppVar_14820;
	BIT_VEC cppVar_14834;
	bool cppVar_14835;
	BIT_VEC cppVar_14838;
	BIT_VEC cppVar_14839;
	BIT_VEC cppVar_14840;
	bool cppVar_14841;
	BIT_VEC cppVar_14842;
	BIT_VEC cppVar_14843;
	BIT_VEC cppVar_14844;
	BIT_VEC cppVar_14845;
	BIT_VEC cppVar_14846;
	BIT_VEC cppVar_14847;
	BIT_VEC cppVar_14848;
	BIT_VEC cppVar_14849;
	BIT_VEC cppVar_14850;
	BIT_VEC cppVar_14837;
	BIT_VEC cppVar_14851;
	bool cppVar_14852;
	BIT_VEC cppVar_14855;
	BIT_VEC cppVar_14856;
	BIT_VEC cppVar_14857;
	bool cppVar_14858;
	BIT_VEC cppVar_14859;
	BIT_VEC cppVar_14860;
	BIT_VEC cppVar_14861;
	BIT_VEC cppVar_14862;
	BIT_VEC cppVar_14863;
	BIT_VEC cppVar_14864;
	BIT_VEC cppVar_14865;
	BIT_VEC cppVar_14866;
	BIT_VEC cppVar_14867;
	BIT_VEC cppVar_14854;
	BIT_VEC cppVar_14868;
	bool cppVar_14869;
	BIT_VEC cppVar_14872;
	BIT_VEC cppVar_14873;
	BIT_VEC cppVar_14874;
	bool cppVar_14875;
	BIT_VEC cppVar_14876;
	BIT_VEC cppVar_14877;
	BIT_VEC cppVar_14878;
	BIT_VEC cppVar_14879;
	BIT_VEC cppVar_14880;
	BIT_VEC cppVar_14881;
	BIT_VEC cppVar_14882;
	BIT_VEC cppVar_14883;
	BIT_VEC cppVar_14884;
	BIT_VEC cppVar_14871;
	BIT_VEC cppVar_14885;
	bool cppVar_14886;
	BIT_VEC cppVar_14889;
	BIT_VEC cppVar_14890;
	BIT_VEC cppVar_14891;
	bool cppVar_14892;
	BIT_VEC cppVar_14893;
	BIT_VEC cppVar_14894;
	BIT_VEC cppVar_14895;
	BIT_VEC cppVar_14896;
	BIT_VEC cppVar_14897;
	BIT_VEC cppVar_14898;
	BIT_VEC cppVar_14899;
	BIT_VEC cppVar_14900;
	BIT_VEC cppVar_14901;
	BIT_VEC cppVar_14888;
	BIT_VEC cppVar_14902;
	bool cppVar_14903;
	BIT_VEC cppVar_14906;
	BIT_VEC cppVar_14907;
	BIT_VEC cppVar_14908;
	bool cppVar_14909;
	BIT_VEC cppVar_14910;
	BIT_VEC cppVar_14911;
	BIT_VEC cppVar_14912;
	BIT_VEC cppVar_14913;
	BIT_VEC cppVar_14914;
	BIT_VEC cppVar_14915;
	BIT_VEC cppVar_14916;
	BIT_VEC cppVar_14917;
	BIT_VEC cppVar_14918;
	BIT_VEC cppVar_14905;
	BIT_VEC cppVar_14919;
	bool cppVar_14920;
	BIT_VEC cppVar_14923;
	BIT_VEC cppVar_14924;
	BIT_VEC cppVar_14925;
	bool cppVar_14926;
	BIT_VEC cppVar_14927;
	BIT_VEC cppVar_14928;
	BIT_VEC cppVar_14929;
	BIT_VEC cppVar_14930;
	BIT_VEC cppVar_14931;
	BIT_VEC cppVar_14932;
	BIT_VEC cppVar_14933;
	BIT_VEC cppVar_14934;
	BIT_VEC cppVar_14935;
	BIT_VEC cppVar_14922;
	BIT_VEC cppVar_14936;
	bool cppVar_14937;
	BIT_VEC cppVar_14940;
	BIT_VEC cppVar_14941;
	BIT_VEC cppVar_14942;
	bool cppVar_14943;
	BIT_VEC cppVar_14944;
	BIT_VEC cppVar_14945;
	BIT_VEC cppVar_14946;
	BIT_VEC cppVar_14947;
	BIT_VEC cppVar_14948;
	BIT_VEC cppVar_14949;
	BIT_VEC cppVar_14950;
	BIT_VEC cppVar_14951;
	BIT_VEC cppVar_14952;
	BIT_VEC cppVar_14939;
	BIT_VEC cppVar_14953;
	bool cppVar_14954;
	BIT_VEC cppVar_14957;
	BIT_VEC cppVar_14958;
	BIT_VEC cppVar_14959;
	bool cppVar_14960;
	BIT_VEC cppVar_14961;
	BIT_VEC cppVar_14962;
	BIT_VEC cppVar_14963;
	BIT_VEC cppVar_14964;
	BIT_VEC cppVar_14965;
	BIT_VEC cppVar_14966;
	BIT_VEC cppVar_14967;
	BIT_VEC cppVar_14968;
	BIT_VEC cppVar_14969;
	BIT_VEC cppVar_14956;
	BIT_VEC cppVar_14970;
	bool cppVar_14971;
	BIT_VEC cppVar_14974;
	BIT_VEC cppVar_14975;
	BIT_VEC cppVar_14976;
	bool cppVar_14977;
	BIT_VEC cppVar_14978;
	BIT_VEC cppVar_14979;
	BIT_VEC cppVar_14980;
	BIT_VEC cppVar_14981;
	BIT_VEC cppVar_14982;
	BIT_VEC cppVar_14983;
	BIT_VEC cppVar_14984;
	BIT_VEC cppVar_14985;
	BIT_VEC cppVar_14986;
	BIT_VEC cppVar_14973;
	BIT_VEC cppVar_14987;
	bool cppVar_14988;
	BIT_VEC cppVar_14991;
	BIT_VEC cppVar_14992;
	BIT_VEC cppVar_14993;
	bool cppVar_14994;
	BIT_VEC cppVar_14995;
	BIT_VEC cppVar_14996;
	BIT_VEC cppVar_14997;
	BIT_VEC cppVar_14998;
	BIT_VEC cppVar_14999;
	BIT_VEC cppVar_15000;
	BIT_VEC cppVar_15001;
	BIT_VEC cppVar_15002;
	BIT_VEC cppVar_15003;
	BIT_VEC cppVar_14990;
	BIT_VEC cppVar_15004;
	bool cppVar_15005;
	BIT_VEC cppVar_15008;
	BIT_VEC cppVar_15009;
	BIT_VEC cppVar_15010;
	bool cppVar_15011;
	BIT_VEC cppVar_15012;
	BIT_VEC cppVar_15013;
	BIT_VEC cppVar_15014;
	BIT_VEC cppVar_15015;
	BIT_VEC cppVar_15016;
	BIT_VEC cppVar_15017;
	BIT_VEC cppVar_15018;
	BIT_VEC cppVar_15019;
	BIT_VEC cppVar_15020;
	BIT_VEC cppVar_15007;
	BIT_VEC cppVar_15021;
	bool cppVar_15022;
	BIT_VEC cppVar_15025;
	BIT_VEC cppVar_15026;
	BIT_VEC cppVar_15027;
	bool cppVar_15028;
	BIT_VEC cppVar_15029;
	BIT_VEC cppVar_15030;
	BIT_VEC cppVar_15031;
	BIT_VEC cppVar_15032;
	BIT_VEC cppVar_15033;
	BIT_VEC cppVar_15034;
	BIT_VEC cppVar_15035;
	BIT_VEC cppVar_15036;
	BIT_VEC cppVar_15037;
	BIT_VEC cppVar_15024;
	BIT_VEC cppVar_15038;
	bool cppVar_15039;
	BIT_VEC cppVar_15042;
	BIT_VEC cppVar_15043;
	BIT_VEC cppVar_15044;
	bool cppVar_15045;
	BIT_VEC cppVar_15046;
	BIT_VEC cppVar_15047;
	BIT_VEC cppVar_15048;
	BIT_VEC cppVar_15049;
	BIT_VEC cppVar_15050;
	BIT_VEC cppVar_15051;
	BIT_VEC cppVar_15052;
	BIT_VEC cppVar_15053;
	BIT_VEC cppVar_15054;
	BIT_VEC cppVar_15041;
	BIT_VEC cppVar_15055;
	bool cppVar_15056;
	BIT_VEC cppVar_15059;
	BIT_VEC cppVar_15060;
	BIT_VEC cppVar_15061;
	bool cppVar_15062;
	BIT_VEC cppVar_15063;
	BIT_VEC cppVar_15064;
	BIT_VEC cppVar_15065;
	BIT_VEC cppVar_15066;
	BIT_VEC cppVar_15067;
	BIT_VEC cppVar_15068;
	BIT_VEC cppVar_15069;
	BIT_VEC cppVar_15070;
	BIT_VEC cppVar_15071;
	BIT_VEC cppVar_15058;
	BIT_VEC cppVar_15072;
	bool cppVar_15073;
	BIT_VEC cppVar_15076;
	BIT_VEC cppVar_15077;
	BIT_VEC cppVar_15078;
	bool cppVar_15079;
	BIT_VEC cppVar_15080;
	BIT_VEC cppVar_15081;
	BIT_VEC cppVar_15082;
	BIT_VEC cppVar_15083;
	BIT_VEC cppVar_15084;
	BIT_VEC cppVar_15085;
	BIT_VEC cppVar_15086;
	BIT_VEC cppVar_15087;
	BIT_VEC cppVar_15088;
	BIT_VEC cppVar_15075;
	BIT_VEC cppVar_15089;
	bool cppVar_15090;
	BIT_VEC cppVar_15093;
	BIT_VEC cppVar_15094;
	BIT_VEC cppVar_15095;
	bool cppVar_15096;
	BIT_VEC cppVar_15097;
	BIT_VEC cppVar_15098;
	BIT_VEC cppVar_15099;
	BIT_VEC cppVar_15100;
	BIT_VEC cppVar_15101;
	BIT_VEC cppVar_15102;
	BIT_VEC cppVar_15103;
	BIT_VEC cppVar_15104;
	BIT_VEC cppVar_15105;
	BIT_VEC cppVar_15092;
	BIT_VEC cppVar_15106;
	bool cppVar_15107;
	BIT_VEC cppVar_15110;
	BIT_VEC cppVar_15111;
	BIT_VEC cppVar_15112;
	bool cppVar_15113;
	BIT_VEC cppVar_15114;
	BIT_VEC cppVar_15115;
	BIT_VEC cppVar_15116;
	BIT_VEC cppVar_15117;
	BIT_VEC cppVar_15118;
	BIT_VEC cppVar_15119;
	BIT_VEC cppVar_15120;
	BIT_VEC cppVar_15121;
	BIT_VEC cppVar_15122;
	BIT_VEC cppVar_15109;
	BIT_VEC cppVar_15123;
	bool cppVar_15124;
	BIT_VEC cppVar_15127;
	BIT_VEC cppVar_15128;
	BIT_VEC cppVar_15129;
	bool cppVar_15130;
	BIT_VEC cppVar_15131;
	BIT_VEC cppVar_15132;
	BIT_VEC cppVar_15133;
	BIT_VEC cppVar_15134;
	BIT_VEC cppVar_15135;
	BIT_VEC cppVar_15136;
	BIT_VEC cppVar_15137;
	BIT_VEC cppVar_15138;
	BIT_VEC cppVar_15139;
	BIT_VEC cppVar_15126;
	BIT_VEC cppVar_15140;
	bool cppVar_15141;
	BIT_VEC cppVar_15142;
	BIT_VEC cppVar_15125;
	BIT_VEC cppVar_15108;
	BIT_VEC cppVar_15091;
	BIT_VEC cppVar_15074;
	BIT_VEC cppVar_15057;
	BIT_VEC cppVar_15040;
	BIT_VEC cppVar_15023;
	BIT_VEC cppVar_15006;
	BIT_VEC cppVar_14989;
	BIT_VEC cppVar_14972;
	BIT_VEC cppVar_14955;
	BIT_VEC cppVar_14938;
	BIT_VEC cppVar_14921;
	BIT_VEC cppVar_14904;
	BIT_VEC cppVar_14887;
	BIT_VEC cppVar_14870;
	BIT_VEC cppVar_14853;
	BIT_VEC cppVar_14836;
	BIT_VEC cppVar_14819;
	BIT_VEC cppVar_14802;
	BIT_VEC cppVar_14785;
	BIT_VEC cppVar_14752;
	BIT_VEC cppVar_15143;
	BIT_VEC cppVar_15144;
	BIT_VEC cppVar_15145;
	BIT_VEC cppVar_15146;
	BIT_VEC cppVar_15147;
	BIT_VEC cppVar_15148;
	BIT_VEC cppVar_15149;
	BIT_VEC cppVar_15150;
	BIT_VEC cppVar_15151;
	BIT_VEC cppVar_14724;
	BIT_VEC cppVar_15153;
	BIT_VEC cppVar_15154;
	bool cppVar_15155;
	BIT_VEC cppVar_15157;
	BIT_VEC cppVar_15158;
	BIT_VEC cppVar_15159;
	BIT_VEC cppVar_15160;
	bool cppVar_15161;
	BIT_VEC cppVar_15163;
	BIT_VEC cppVar_15164;
	BIT_VEC cppVar_15165;
	BIT_VEC cppVar_15166;
	BIT_VEC cppVar_15167;
	BIT_VEC cppVar_15168;
	BIT_VEC cppVar_15169;
	bool cppVar_15170;
	BIT_VEC cppVar_15171;
	BIT_VEC cppVar_15172;
	BIT_VEC cppVar_15173;
	BIT_VEC cppVar_15174;
	BIT_VEC cppVar_15176;
	BIT_VEC cppVar_15177;
	BIT_VEC cppVar_15178;
	BIT_VEC cppVar_15179;
	bool cppVar_15180;
	BIT_VEC cppVar_15182;
	BIT_VEC cppVar_15183;
	BIT_VEC cppVar_15184;
	BIT_VEC cppVar_15185;
	bool cppVar_15186;
	BIT_VEC cppVar_15188;
	BIT_VEC cppVar_15189;
	BIT_VEC cppVar_15190;
	BIT_VEC cppVar_15191;
	bool cppVar_15192;
	BIT_VEC cppVar_15194;
	BIT_VEC cppVar_15195;
	BIT_VEC cppVar_15196;
	BIT_VEC cppVar_15197;
	bool cppVar_15198;
	BIT_VEC cppVar_15200;
	BIT_VEC cppVar_15201;
	BIT_VEC cppVar_15202;
	BIT_VEC cppVar_15203;
	bool cppVar_15204;
	BIT_VEC cppVar_15206;
	BIT_VEC cppVar_15207;
	BIT_VEC cppVar_15208;
	BIT_VEC cppVar_15209;
	bool cppVar_15210;
	BIT_VEC cppVar_15212;
	BIT_VEC cppVar_15213;
	BIT_VEC cppVar_15214;
	BIT_VEC cppVar_15215;
	bool cppVar_15216;
	BIT_VEC cppVar_15218;
	BIT_VEC cppVar_15219;
	BIT_VEC cppVar_15220;
	BIT_VEC cppVar_15221;
	bool cppVar_15222;
	BIT_VEC cppVar_15224;
	BIT_VEC cppVar_15225;
	BIT_VEC cppVar_15226;
	BIT_VEC cppVar_15227;
	bool cppVar_15228;
	BIT_VEC cppVar_15230;
	BIT_VEC cppVar_15231;
	BIT_VEC cppVar_15232;
	BIT_VEC cppVar_15233;
	bool cppVar_15234;
	BIT_VEC cppVar_15236;
	BIT_VEC cppVar_15237;
	BIT_VEC cppVar_15238;
	BIT_VEC cppVar_15239;
	bool cppVar_15240;
	BIT_VEC cppVar_15242;
	BIT_VEC cppVar_15243;
	BIT_VEC cppVar_15244;
	BIT_VEC cppVar_15245;
	bool cppVar_15246;
	BIT_VEC cppVar_15248;
	BIT_VEC cppVar_15249;
	BIT_VEC cppVar_15250;
	BIT_VEC cppVar_15251;
	bool cppVar_15252;
	BIT_VEC cppVar_15254;
	BIT_VEC cppVar_15255;
	BIT_VEC cppVar_15256;
	BIT_VEC cppVar_15257;
	bool cppVar_15258;
	BIT_VEC cppVar_15260;
	BIT_VEC cppVar_15261;
	BIT_VEC cppVar_15262;
	BIT_VEC cppVar_15263;
	bool cppVar_15264;
	BIT_VEC cppVar_15266;
	BIT_VEC cppVar_15267;
	BIT_VEC cppVar_15268;
	BIT_VEC cppVar_15269;
	bool cppVar_15270;
	BIT_VEC cppVar_15272;
	BIT_VEC cppVar_15273;
	BIT_VEC cppVar_15274;
	BIT_VEC cppVar_15275;
	bool cppVar_15276;
	BIT_VEC cppVar_15278;
	BIT_VEC cppVar_15279;
	BIT_VEC cppVar_15280;
	BIT_VEC cppVar_15281;
	bool cppVar_15282;
	BIT_VEC cppVar_15284;
	BIT_VEC cppVar_15285;
	BIT_VEC cppVar_15286;
	BIT_VEC cppVar_15287;
	bool cppVar_15288;
	BIT_VEC cppVar_15290;
	BIT_VEC cppVar_15291;
	BIT_VEC cppVar_15292;
	BIT_VEC cppVar_15293;
	bool cppVar_15294;
	BIT_VEC cppVar_15296;
	BIT_VEC cppVar_15297;
	BIT_VEC cppVar_15298;
	BIT_VEC cppVar_15299;
	bool cppVar_15300;
	BIT_VEC cppVar_15301;
	BIT_VEC cppVar_15295;
	BIT_VEC cppVar_15289;
	BIT_VEC cppVar_15283;
	BIT_VEC cppVar_15277;
	BIT_VEC cppVar_15271;
	BIT_VEC cppVar_15265;
	BIT_VEC cppVar_15259;
	BIT_VEC cppVar_15253;
	BIT_VEC cppVar_15247;
	BIT_VEC cppVar_15241;
	BIT_VEC cppVar_15235;
	BIT_VEC cppVar_15229;
	BIT_VEC cppVar_15223;
	BIT_VEC cppVar_15217;
	BIT_VEC cppVar_15211;
	BIT_VEC cppVar_15205;
	BIT_VEC cppVar_15199;
	BIT_VEC cppVar_15193;
	BIT_VEC cppVar_15187;
	BIT_VEC cppVar_15181;
	BIT_VEC cppVar_15175;
	BIT_VEC cppVar_15162;
	BIT_VEC cppVar_15156;
	BIT_VEC cppVar_15303;
	BIT_VEC cppVar_15304;
	bool cppVar_15305;
	BIT_VEC cppVar_15307;
	BIT_VEC cppVar_15308;
	BIT_VEC cppVar_15309;
	BIT_VEC cppVar_15310;
	bool cppVar_15311;
	BIT_VEC cppVar_15313;
	BIT_VEC cppVar_15314;
	BIT_VEC cppVar_15315;
	BIT_VEC cppVar_15316;
	BIT_VEC cppVar_15317;
	BIT_VEC cppVar_15318;
	BIT_VEC cppVar_15319;
	bool cppVar_15320;
	BIT_VEC cppVar_15321;
	BIT_VEC cppVar_15322;
	BIT_VEC cppVar_15323;
	BIT_VEC cppVar_15324;
	BIT_VEC cppVar_15326;
	BIT_VEC cppVar_15327;
	BIT_VEC cppVar_15328;
	BIT_VEC cppVar_15329;
	bool cppVar_15330;
	BIT_VEC cppVar_15332;
	BIT_VEC cppVar_15333;
	BIT_VEC cppVar_15334;
	BIT_VEC cppVar_15335;
	bool cppVar_15336;
	BIT_VEC cppVar_15338;
	BIT_VEC cppVar_15339;
	BIT_VEC cppVar_15340;
	BIT_VEC cppVar_15341;
	bool cppVar_15342;
	BIT_VEC cppVar_15344;
	BIT_VEC cppVar_15345;
	BIT_VEC cppVar_15346;
	BIT_VEC cppVar_15347;
	bool cppVar_15348;
	BIT_VEC cppVar_15350;
	BIT_VEC cppVar_15351;
	BIT_VEC cppVar_15352;
	BIT_VEC cppVar_15353;
	bool cppVar_15354;
	BIT_VEC cppVar_15356;
	BIT_VEC cppVar_15357;
	BIT_VEC cppVar_15358;
	BIT_VEC cppVar_15359;
	bool cppVar_15360;
	BIT_VEC cppVar_15362;
	BIT_VEC cppVar_15363;
	BIT_VEC cppVar_15364;
	BIT_VEC cppVar_15365;
	bool cppVar_15366;
	BIT_VEC cppVar_15368;
	BIT_VEC cppVar_15369;
	BIT_VEC cppVar_15370;
	BIT_VEC cppVar_15371;
	bool cppVar_15372;
	BIT_VEC cppVar_15374;
	BIT_VEC cppVar_15375;
	BIT_VEC cppVar_15376;
	BIT_VEC cppVar_15377;
	bool cppVar_15378;
	BIT_VEC cppVar_15380;
	BIT_VEC cppVar_15381;
	BIT_VEC cppVar_15382;
	BIT_VEC cppVar_15383;
	bool cppVar_15384;
	BIT_VEC cppVar_15386;
	BIT_VEC cppVar_15387;
	BIT_VEC cppVar_15388;
	BIT_VEC cppVar_15389;
	bool cppVar_15390;
	BIT_VEC cppVar_15392;
	BIT_VEC cppVar_15393;
	BIT_VEC cppVar_15394;
	BIT_VEC cppVar_15395;
	bool cppVar_15396;
	BIT_VEC cppVar_15398;
	BIT_VEC cppVar_15399;
	BIT_VEC cppVar_15400;
	BIT_VEC cppVar_15401;
	bool cppVar_15402;
	BIT_VEC cppVar_15404;
	BIT_VEC cppVar_15405;
	BIT_VEC cppVar_15406;
	BIT_VEC cppVar_15407;
	bool cppVar_15408;
	BIT_VEC cppVar_15410;
	BIT_VEC cppVar_15411;
	BIT_VEC cppVar_15412;
	BIT_VEC cppVar_15413;
	bool cppVar_15414;
	BIT_VEC cppVar_15416;
	BIT_VEC cppVar_15417;
	BIT_VEC cppVar_15418;
	BIT_VEC cppVar_15419;
	bool cppVar_15420;
	BIT_VEC cppVar_15422;
	BIT_VEC cppVar_15423;
	BIT_VEC cppVar_15424;
	BIT_VEC cppVar_15425;
	bool cppVar_15426;
	BIT_VEC cppVar_15428;
	BIT_VEC cppVar_15429;
	BIT_VEC cppVar_15430;
	BIT_VEC cppVar_15431;
	bool cppVar_15432;
	BIT_VEC cppVar_15434;
	BIT_VEC cppVar_15435;
	BIT_VEC cppVar_15436;
	BIT_VEC cppVar_15437;
	bool cppVar_15438;
	BIT_VEC cppVar_15440;
	BIT_VEC cppVar_15441;
	BIT_VEC cppVar_15442;
	BIT_VEC cppVar_15443;
	bool cppVar_15444;
	BIT_VEC cppVar_15446;
	BIT_VEC cppVar_15447;
	BIT_VEC cppVar_15448;
	BIT_VEC cppVar_15449;
	bool cppVar_15450;
	BIT_VEC cppVar_15451;
	BIT_VEC cppVar_15445;
	BIT_VEC cppVar_15439;
	BIT_VEC cppVar_15433;
	BIT_VEC cppVar_15427;
	BIT_VEC cppVar_15421;
	BIT_VEC cppVar_15415;
	BIT_VEC cppVar_15409;
	BIT_VEC cppVar_15403;
	BIT_VEC cppVar_15397;
	BIT_VEC cppVar_15391;
	BIT_VEC cppVar_15385;
	BIT_VEC cppVar_15379;
	BIT_VEC cppVar_15373;
	BIT_VEC cppVar_15367;
	BIT_VEC cppVar_15361;
	BIT_VEC cppVar_15355;
	BIT_VEC cppVar_15349;
	BIT_VEC cppVar_15343;
	BIT_VEC cppVar_15337;
	BIT_VEC cppVar_15331;
	BIT_VEC cppVar_15325;
	BIT_VEC cppVar_15312;
	BIT_VEC cppVar_15306;
	BIT_VEC cppVar_15453;
	BIT_VEC cppVar_15454;
	bool cppVar_15455;
	BIT_VEC cppVar_15457;
	BIT_VEC cppVar_15458;
	BIT_VEC cppVar_15459;
	BIT_VEC cppVar_15460;
	bool cppVar_15461;
	BIT_VEC cppVar_15463;
	BIT_VEC cppVar_15464;
	BIT_VEC cppVar_15465;
	BIT_VEC cppVar_15466;
	BIT_VEC cppVar_15467;
	BIT_VEC cppVar_15468;
	BIT_VEC cppVar_15469;
	bool cppVar_15470;
	BIT_VEC cppVar_15471;
	BIT_VEC cppVar_15472;
	BIT_VEC cppVar_15473;
	BIT_VEC cppVar_15474;
	BIT_VEC cppVar_15476;
	BIT_VEC cppVar_15477;
	BIT_VEC cppVar_15478;
	BIT_VEC cppVar_15479;
	bool cppVar_15480;
	BIT_VEC cppVar_15482;
	BIT_VEC cppVar_15483;
	BIT_VEC cppVar_15484;
	BIT_VEC cppVar_15485;
	bool cppVar_15486;
	BIT_VEC cppVar_15488;
	BIT_VEC cppVar_15489;
	BIT_VEC cppVar_15490;
	BIT_VEC cppVar_15491;
	bool cppVar_15492;
	BIT_VEC cppVar_15494;
	BIT_VEC cppVar_15495;
	BIT_VEC cppVar_15496;
	BIT_VEC cppVar_15497;
	bool cppVar_15498;
	BIT_VEC cppVar_15500;
	BIT_VEC cppVar_15501;
	BIT_VEC cppVar_15502;
	BIT_VEC cppVar_15503;
	bool cppVar_15504;
	BIT_VEC cppVar_15506;
	BIT_VEC cppVar_15507;
	BIT_VEC cppVar_15508;
	BIT_VEC cppVar_15509;
	bool cppVar_15510;
	BIT_VEC cppVar_15512;
	BIT_VEC cppVar_15513;
	BIT_VEC cppVar_15514;
	BIT_VEC cppVar_15515;
	bool cppVar_15516;
	BIT_VEC cppVar_15518;
	BIT_VEC cppVar_15519;
	BIT_VEC cppVar_15520;
	BIT_VEC cppVar_15521;
	bool cppVar_15522;
	BIT_VEC cppVar_15524;
	BIT_VEC cppVar_15525;
	BIT_VEC cppVar_15526;
	BIT_VEC cppVar_15527;
	bool cppVar_15528;
	BIT_VEC cppVar_15530;
	BIT_VEC cppVar_15531;
	BIT_VEC cppVar_15532;
	BIT_VEC cppVar_15533;
	bool cppVar_15534;
	BIT_VEC cppVar_15536;
	BIT_VEC cppVar_15537;
	BIT_VEC cppVar_15538;
	BIT_VEC cppVar_15539;
	bool cppVar_15540;
	BIT_VEC cppVar_15542;
	BIT_VEC cppVar_15543;
	BIT_VEC cppVar_15544;
	BIT_VEC cppVar_15545;
	bool cppVar_15546;
	BIT_VEC cppVar_15548;
	BIT_VEC cppVar_15549;
	BIT_VEC cppVar_15550;
	BIT_VEC cppVar_15551;
	bool cppVar_15552;
	BIT_VEC cppVar_15554;
	BIT_VEC cppVar_15555;
	BIT_VEC cppVar_15556;
	BIT_VEC cppVar_15557;
	bool cppVar_15558;
	BIT_VEC cppVar_15560;
	BIT_VEC cppVar_15561;
	BIT_VEC cppVar_15562;
	BIT_VEC cppVar_15563;
	bool cppVar_15564;
	BIT_VEC cppVar_15566;
	BIT_VEC cppVar_15567;
	BIT_VEC cppVar_15568;
	BIT_VEC cppVar_15569;
	bool cppVar_15570;
	BIT_VEC cppVar_15572;
	BIT_VEC cppVar_15573;
	BIT_VEC cppVar_15574;
	BIT_VEC cppVar_15575;
	bool cppVar_15576;
	BIT_VEC cppVar_15578;
	BIT_VEC cppVar_15579;
	BIT_VEC cppVar_15580;
	BIT_VEC cppVar_15581;
	bool cppVar_15582;
	BIT_VEC cppVar_15584;
	BIT_VEC cppVar_15585;
	BIT_VEC cppVar_15586;
	BIT_VEC cppVar_15587;
	bool cppVar_15588;
	BIT_VEC cppVar_15590;
	BIT_VEC cppVar_15591;
	BIT_VEC cppVar_15592;
	BIT_VEC cppVar_15593;
	bool cppVar_15594;
	BIT_VEC cppVar_15596;
	BIT_VEC cppVar_15597;
	BIT_VEC cppVar_15598;
	BIT_VEC cppVar_15599;
	bool cppVar_15600;
	BIT_VEC cppVar_15601;
	BIT_VEC cppVar_15595;
	BIT_VEC cppVar_15589;
	BIT_VEC cppVar_15583;
	BIT_VEC cppVar_15577;
	BIT_VEC cppVar_15571;
	BIT_VEC cppVar_15565;
	BIT_VEC cppVar_15559;
	BIT_VEC cppVar_15553;
	BIT_VEC cppVar_15547;
	BIT_VEC cppVar_15541;
	BIT_VEC cppVar_15535;
	BIT_VEC cppVar_15529;
	BIT_VEC cppVar_15523;
	BIT_VEC cppVar_15517;
	BIT_VEC cppVar_15511;
	BIT_VEC cppVar_15505;
	BIT_VEC cppVar_15499;
	BIT_VEC cppVar_15493;
	BIT_VEC cppVar_15487;
	BIT_VEC cppVar_15481;
	BIT_VEC cppVar_15475;
	BIT_VEC cppVar_15462;
	BIT_VEC cppVar_15456;
	BIT_VEC cppVar_15603;
	BIT_VEC cppVar_15604;
	bool cppVar_15605;
	BIT_VEC cppVar_15607;
	BIT_VEC cppVar_15608;
	BIT_VEC cppVar_15609;
	BIT_VEC cppVar_15610;
	bool cppVar_15611;
	BIT_VEC cppVar_15613;
	BIT_VEC cppVar_15614;
	BIT_VEC cppVar_15615;
	BIT_VEC cppVar_15616;
	BIT_VEC cppVar_15617;
	BIT_VEC cppVar_15618;
	BIT_VEC cppVar_15619;
	bool cppVar_15620;
	BIT_VEC cppVar_15621;
	BIT_VEC cppVar_15622;
	BIT_VEC cppVar_15623;
	BIT_VEC cppVar_15624;
	BIT_VEC cppVar_15626;
	BIT_VEC cppVar_15627;
	BIT_VEC cppVar_15628;
	BIT_VEC cppVar_15629;
	bool cppVar_15630;
	BIT_VEC cppVar_15632;
	BIT_VEC cppVar_15633;
	BIT_VEC cppVar_15634;
	BIT_VEC cppVar_15635;
	bool cppVar_15636;
	BIT_VEC cppVar_15638;
	BIT_VEC cppVar_15639;
	BIT_VEC cppVar_15640;
	BIT_VEC cppVar_15641;
	bool cppVar_15642;
	BIT_VEC cppVar_15644;
	BIT_VEC cppVar_15645;
	BIT_VEC cppVar_15646;
	BIT_VEC cppVar_15647;
	bool cppVar_15648;
	BIT_VEC cppVar_15650;
	BIT_VEC cppVar_15651;
	BIT_VEC cppVar_15652;
	BIT_VEC cppVar_15653;
	bool cppVar_15654;
	BIT_VEC cppVar_15656;
	BIT_VEC cppVar_15657;
	BIT_VEC cppVar_15658;
	BIT_VEC cppVar_15659;
	bool cppVar_15660;
	BIT_VEC cppVar_15662;
	BIT_VEC cppVar_15663;
	BIT_VEC cppVar_15664;
	BIT_VEC cppVar_15665;
	bool cppVar_15666;
	BIT_VEC cppVar_15668;
	BIT_VEC cppVar_15669;
	BIT_VEC cppVar_15670;
	BIT_VEC cppVar_15671;
	bool cppVar_15672;
	BIT_VEC cppVar_15674;
	BIT_VEC cppVar_15675;
	BIT_VEC cppVar_15676;
	BIT_VEC cppVar_15677;
	bool cppVar_15678;
	BIT_VEC cppVar_15680;
	BIT_VEC cppVar_15681;
	BIT_VEC cppVar_15682;
	BIT_VEC cppVar_15683;
	bool cppVar_15684;
	BIT_VEC cppVar_15686;
	BIT_VEC cppVar_15687;
	BIT_VEC cppVar_15688;
	BIT_VEC cppVar_15689;
	bool cppVar_15690;
	BIT_VEC cppVar_15692;
	BIT_VEC cppVar_15693;
	BIT_VEC cppVar_15694;
	BIT_VEC cppVar_15695;
	bool cppVar_15696;
	BIT_VEC cppVar_15698;
	BIT_VEC cppVar_15699;
	BIT_VEC cppVar_15700;
	BIT_VEC cppVar_15701;
	bool cppVar_15702;
	BIT_VEC cppVar_15704;
	BIT_VEC cppVar_15705;
	BIT_VEC cppVar_15706;
	BIT_VEC cppVar_15707;
	bool cppVar_15708;
	BIT_VEC cppVar_15710;
	BIT_VEC cppVar_15711;
	BIT_VEC cppVar_15712;
	BIT_VEC cppVar_15713;
	bool cppVar_15714;
	BIT_VEC cppVar_15716;
	BIT_VEC cppVar_15717;
	BIT_VEC cppVar_15718;
	BIT_VEC cppVar_15719;
	bool cppVar_15720;
	BIT_VEC cppVar_15722;
	BIT_VEC cppVar_15723;
	BIT_VEC cppVar_15724;
	BIT_VEC cppVar_15725;
	bool cppVar_15726;
	BIT_VEC cppVar_15728;
	BIT_VEC cppVar_15729;
	BIT_VEC cppVar_15730;
	BIT_VEC cppVar_15731;
	bool cppVar_15732;
	BIT_VEC cppVar_15734;
	BIT_VEC cppVar_15735;
	BIT_VEC cppVar_15736;
	BIT_VEC cppVar_15737;
	bool cppVar_15738;
	BIT_VEC cppVar_15740;
	BIT_VEC cppVar_15741;
	BIT_VEC cppVar_15742;
	BIT_VEC cppVar_15743;
	bool cppVar_15744;
	BIT_VEC cppVar_15746;
	BIT_VEC cppVar_15747;
	BIT_VEC cppVar_15748;
	BIT_VEC cppVar_15749;
	bool cppVar_15750;
	BIT_VEC cppVar_15751;
	BIT_VEC cppVar_15745;
	BIT_VEC cppVar_15739;
	BIT_VEC cppVar_15733;
	BIT_VEC cppVar_15727;
	BIT_VEC cppVar_15721;
	BIT_VEC cppVar_15715;
	BIT_VEC cppVar_15709;
	BIT_VEC cppVar_15703;
	BIT_VEC cppVar_15697;
	BIT_VEC cppVar_15691;
	BIT_VEC cppVar_15685;
	BIT_VEC cppVar_15679;
	BIT_VEC cppVar_15673;
	BIT_VEC cppVar_15667;
	BIT_VEC cppVar_15661;
	BIT_VEC cppVar_15655;
	BIT_VEC cppVar_15649;
	BIT_VEC cppVar_15643;
	BIT_VEC cppVar_15637;
	BIT_VEC cppVar_15631;
	BIT_VEC cppVar_15625;
	BIT_VEC cppVar_15612;
	BIT_VEC cppVar_15606;
	BIT_VEC cppVar_15753;
	BIT_VEC cppVar_15754;
	bool cppVar_15755;
	BIT_VEC cppVar_15757;
	BIT_VEC cppVar_15758;
	BIT_VEC cppVar_15759;
	BIT_VEC cppVar_15760;
	bool cppVar_15761;
	BIT_VEC cppVar_15763;
	BIT_VEC cppVar_15764;
	BIT_VEC cppVar_15765;
	BIT_VEC cppVar_15766;
	BIT_VEC cppVar_15767;
	BIT_VEC cppVar_15768;
	BIT_VEC cppVar_15769;
	bool cppVar_15770;
	BIT_VEC cppVar_15771;
	BIT_VEC cppVar_15772;
	BIT_VEC cppVar_15773;
	BIT_VEC cppVar_15774;
	BIT_VEC cppVar_15776;
	BIT_VEC cppVar_15777;
	BIT_VEC cppVar_15778;
	BIT_VEC cppVar_15779;
	bool cppVar_15780;
	BIT_VEC cppVar_15782;
	BIT_VEC cppVar_15783;
	BIT_VEC cppVar_15784;
	BIT_VEC cppVar_15785;
	bool cppVar_15786;
	BIT_VEC cppVar_15788;
	BIT_VEC cppVar_15789;
	BIT_VEC cppVar_15790;
	BIT_VEC cppVar_15791;
	bool cppVar_15792;
	BIT_VEC cppVar_15794;
	BIT_VEC cppVar_15795;
	BIT_VEC cppVar_15796;
	BIT_VEC cppVar_15797;
	bool cppVar_15798;
	BIT_VEC cppVar_15800;
	BIT_VEC cppVar_15801;
	BIT_VEC cppVar_15802;
	BIT_VEC cppVar_15803;
	bool cppVar_15804;
	BIT_VEC cppVar_15806;
	BIT_VEC cppVar_15807;
	BIT_VEC cppVar_15808;
	BIT_VEC cppVar_15809;
	bool cppVar_15810;
	BIT_VEC cppVar_15812;
	BIT_VEC cppVar_15813;
	BIT_VEC cppVar_15814;
	BIT_VEC cppVar_15815;
	bool cppVar_15816;
	BIT_VEC cppVar_15818;
	BIT_VEC cppVar_15819;
	BIT_VEC cppVar_15820;
	BIT_VEC cppVar_15821;
	bool cppVar_15822;
	BIT_VEC cppVar_15824;
	BIT_VEC cppVar_15825;
	BIT_VEC cppVar_15826;
	BIT_VEC cppVar_15827;
	bool cppVar_15828;
	BIT_VEC cppVar_15830;
	BIT_VEC cppVar_15831;
	BIT_VEC cppVar_15832;
	BIT_VEC cppVar_15833;
	bool cppVar_15834;
	BIT_VEC cppVar_15836;
	BIT_VEC cppVar_15837;
	BIT_VEC cppVar_15838;
	BIT_VEC cppVar_15839;
	bool cppVar_15840;
	BIT_VEC cppVar_15842;
	BIT_VEC cppVar_15843;
	BIT_VEC cppVar_15844;
	BIT_VEC cppVar_15845;
	bool cppVar_15846;
	BIT_VEC cppVar_15848;
	BIT_VEC cppVar_15849;
	BIT_VEC cppVar_15850;
	BIT_VEC cppVar_15851;
	bool cppVar_15852;
	BIT_VEC cppVar_15854;
	BIT_VEC cppVar_15855;
	BIT_VEC cppVar_15856;
	BIT_VEC cppVar_15857;
	bool cppVar_15858;
	BIT_VEC cppVar_15860;
	BIT_VEC cppVar_15861;
	BIT_VEC cppVar_15862;
	BIT_VEC cppVar_15863;
	bool cppVar_15864;
	BIT_VEC cppVar_15866;
	BIT_VEC cppVar_15867;
	BIT_VEC cppVar_15868;
	BIT_VEC cppVar_15869;
	bool cppVar_15870;
	BIT_VEC cppVar_15872;
	BIT_VEC cppVar_15873;
	BIT_VEC cppVar_15874;
	BIT_VEC cppVar_15875;
	bool cppVar_15876;
	BIT_VEC cppVar_15878;
	BIT_VEC cppVar_15879;
	BIT_VEC cppVar_15880;
	BIT_VEC cppVar_15881;
	bool cppVar_15882;
	BIT_VEC cppVar_15884;
	BIT_VEC cppVar_15885;
	BIT_VEC cppVar_15886;
	BIT_VEC cppVar_15887;
	bool cppVar_15888;
	BIT_VEC cppVar_15890;
	BIT_VEC cppVar_15891;
	BIT_VEC cppVar_15892;
	BIT_VEC cppVar_15893;
	bool cppVar_15894;
	BIT_VEC cppVar_15896;
	BIT_VEC cppVar_15897;
	BIT_VEC cppVar_15898;
	BIT_VEC cppVar_15899;
	bool cppVar_15900;
	BIT_VEC cppVar_15901;
	BIT_VEC cppVar_15895;
	BIT_VEC cppVar_15889;
	BIT_VEC cppVar_15883;
	BIT_VEC cppVar_15877;
	BIT_VEC cppVar_15871;
	BIT_VEC cppVar_15865;
	BIT_VEC cppVar_15859;
	BIT_VEC cppVar_15853;
	BIT_VEC cppVar_15847;
	BIT_VEC cppVar_15841;
	BIT_VEC cppVar_15835;
	BIT_VEC cppVar_15829;
	BIT_VEC cppVar_15823;
	BIT_VEC cppVar_15817;
	BIT_VEC cppVar_15811;
	BIT_VEC cppVar_15805;
	BIT_VEC cppVar_15799;
	BIT_VEC cppVar_15793;
	BIT_VEC cppVar_15787;
	BIT_VEC cppVar_15781;
	BIT_VEC cppVar_15775;
	BIT_VEC cppVar_15762;
	BIT_VEC cppVar_15756;
	BIT_VEC cppVar_15903;
	BIT_VEC cppVar_15904;
	bool cppVar_15905;
	BIT_VEC cppVar_15907;
	BIT_VEC cppVar_15908;
	BIT_VEC cppVar_15909;
	BIT_VEC cppVar_15910;
	bool cppVar_15911;
	BIT_VEC cppVar_15913;
	BIT_VEC cppVar_15914;
	BIT_VEC cppVar_15915;
	BIT_VEC cppVar_15916;
	BIT_VEC cppVar_15917;
	BIT_VEC cppVar_15918;
	BIT_VEC cppVar_15919;
	bool cppVar_15920;
	BIT_VEC cppVar_15921;
	BIT_VEC cppVar_15922;
	BIT_VEC cppVar_15923;
	BIT_VEC cppVar_15924;
	BIT_VEC cppVar_15926;
	BIT_VEC cppVar_15927;
	BIT_VEC cppVar_15928;
	BIT_VEC cppVar_15929;
	bool cppVar_15930;
	BIT_VEC cppVar_15932;
	BIT_VEC cppVar_15933;
	BIT_VEC cppVar_15934;
	BIT_VEC cppVar_15935;
	bool cppVar_15936;
	BIT_VEC cppVar_15938;
	BIT_VEC cppVar_15939;
	BIT_VEC cppVar_15940;
	BIT_VEC cppVar_15941;
	bool cppVar_15942;
	BIT_VEC cppVar_15944;
	BIT_VEC cppVar_15945;
	BIT_VEC cppVar_15946;
	BIT_VEC cppVar_15947;
	bool cppVar_15948;
	BIT_VEC cppVar_15950;
	BIT_VEC cppVar_15951;
	BIT_VEC cppVar_15952;
	BIT_VEC cppVar_15953;
	bool cppVar_15954;
	BIT_VEC cppVar_15956;
	BIT_VEC cppVar_15957;
	BIT_VEC cppVar_15958;
	BIT_VEC cppVar_15959;
	bool cppVar_15960;
	BIT_VEC cppVar_15962;
	BIT_VEC cppVar_15963;
	BIT_VEC cppVar_15964;
	BIT_VEC cppVar_15965;
	bool cppVar_15966;
	BIT_VEC cppVar_15968;
	BIT_VEC cppVar_15969;
	BIT_VEC cppVar_15970;
	BIT_VEC cppVar_15971;
	bool cppVar_15972;
	BIT_VEC cppVar_15974;
	BIT_VEC cppVar_15975;
	BIT_VEC cppVar_15976;
	BIT_VEC cppVar_15977;
	bool cppVar_15978;
	BIT_VEC cppVar_15980;
	BIT_VEC cppVar_15981;
	BIT_VEC cppVar_15982;
	BIT_VEC cppVar_15983;
	bool cppVar_15984;
	BIT_VEC cppVar_15986;
	BIT_VEC cppVar_15987;
	BIT_VEC cppVar_15988;
	BIT_VEC cppVar_15989;
	bool cppVar_15990;
	BIT_VEC cppVar_15992;
	BIT_VEC cppVar_15993;
	BIT_VEC cppVar_15994;
	BIT_VEC cppVar_15995;
	bool cppVar_15996;
	BIT_VEC cppVar_15998;
	BIT_VEC cppVar_15999;
	BIT_VEC cppVar_16000;
	BIT_VEC cppVar_16001;
	bool cppVar_16002;
	BIT_VEC cppVar_16004;
	BIT_VEC cppVar_16005;
	BIT_VEC cppVar_16006;
	BIT_VEC cppVar_16007;
	bool cppVar_16008;
	BIT_VEC cppVar_16010;
	BIT_VEC cppVar_16011;
	BIT_VEC cppVar_16012;
	BIT_VEC cppVar_16013;
	bool cppVar_16014;
	BIT_VEC cppVar_16016;
	BIT_VEC cppVar_16017;
	BIT_VEC cppVar_16018;
	BIT_VEC cppVar_16019;
	bool cppVar_16020;
	BIT_VEC cppVar_16022;
	BIT_VEC cppVar_16023;
	BIT_VEC cppVar_16024;
	BIT_VEC cppVar_16025;
	bool cppVar_16026;
	BIT_VEC cppVar_16028;
	BIT_VEC cppVar_16029;
	BIT_VEC cppVar_16030;
	BIT_VEC cppVar_16031;
	bool cppVar_16032;
	BIT_VEC cppVar_16034;
	BIT_VEC cppVar_16035;
	BIT_VEC cppVar_16036;
	BIT_VEC cppVar_16037;
	bool cppVar_16038;
	BIT_VEC cppVar_16040;
	BIT_VEC cppVar_16041;
	BIT_VEC cppVar_16042;
	BIT_VEC cppVar_16043;
	bool cppVar_16044;
	BIT_VEC cppVar_16046;
	BIT_VEC cppVar_16047;
	BIT_VEC cppVar_16048;
	BIT_VEC cppVar_16049;
	bool cppVar_16050;
	BIT_VEC cppVar_16051;
	BIT_VEC cppVar_16045;
	BIT_VEC cppVar_16039;
	BIT_VEC cppVar_16033;
	BIT_VEC cppVar_16027;
	BIT_VEC cppVar_16021;
	BIT_VEC cppVar_16015;
	BIT_VEC cppVar_16009;
	BIT_VEC cppVar_16003;
	BIT_VEC cppVar_15997;
	BIT_VEC cppVar_15991;
	BIT_VEC cppVar_15985;
	BIT_VEC cppVar_15979;
	BIT_VEC cppVar_15973;
	BIT_VEC cppVar_15967;
	BIT_VEC cppVar_15961;
	BIT_VEC cppVar_15955;
	BIT_VEC cppVar_15949;
	BIT_VEC cppVar_15943;
	BIT_VEC cppVar_15937;
	BIT_VEC cppVar_15931;
	BIT_VEC cppVar_15925;
	BIT_VEC cppVar_15912;
	BIT_VEC cppVar_15906;
	BIT_VEC cppVar_16053;
	BIT_VEC cppVar_16054;
	bool cppVar_16055;
	BIT_VEC cppVar_16057;
	BIT_VEC cppVar_16058;
	BIT_VEC cppVar_16059;
	BIT_VEC cppVar_16060;
	bool cppVar_16061;
	BIT_VEC cppVar_16063;
	BIT_VEC cppVar_16064;
	BIT_VEC cppVar_16065;
	BIT_VEC cppVar_16066;
	BIT_VEC cppVar_16067;
	BIT_VEC cppVar_16068;
	BIT_VEC cppVar_16069;
	bool cppVar_16070;
	BIT_VEC cppVar_16071;
	BIT_VEC cppVar_16072;
	BIT_VEC cppVar_16073;
	BIT_VEC cppVar_16074;
	BIT_VEC cppVar_16076;
	BIT_VEC cppVar_16077;
	BIT_VEC cppVar_16078;
	BIT_VEC cppVar_16079;
	bool cppVar_16080;
	BIT_VEC cppVar_16082;
	BIT_VEC cppVar_16083;
	BIT_VEC cppVar_16084;
	BIT_VEC cppVar_16085;
	bool cppVar_16086;
	BIT_VEC cppVar_16088;
	BIT_VEC cppVar_16089;
	BIT_VEC cppVar_16090;
	BIT_VEC cppVar_16091;
	bool cppVar_16092;
	BIT_VEC cppVar_16094;
	BIT_VEC cppVar_16095;
	BIT_VEC cppVar_16096;
	BIT_VEC cppVar_16097;
	bool cppVar_16098;
	BIT_VEC cppVar_16100;
	BIT_VEC cppVar_16101;
	BIT_VEC cppVar_16102;
	BIT_VEC cppVar_16103;
	bool cppVar_16104;
	BIT_VEC cppVar_16106;
	BIT_VEC cppVar_16107;
	BIT_VEC cppVar_16108;
	BIT_VEC cppVar_16109;
	bool cppVar_16110;
	BIT_VEC cppVar_16112;
	BIT_VEC cppVar_16113;
	BIT_VEC cppVar_16114;
	BIT_VEC cppVar_16115;
	bool cppVar_16116;
	BIT_VEC cppVar_16118;
	BIT_VEC cppVar_16119;
	BIT_VEC cppVar_16120;
	BIT_VEC cppVar_16121;
	bool cppVar_16122;
	BIT_VEC cppVar_16124;
	BIT_VEC cppVar_16125;
	BIT_VEC cppVar_16126;
	BIT_VEC cppVar_16127;
	bool cppVar_16128;
	BIT_VEC cppVar_16130;
	BIT_VEC cppVar_16131;
	BIT_VEC cppVar_16132;
	BIT_VEC cppVar_16133;
	bool cppVar_16134;
	BIT_VEC cppVar_16136;
	BIT_VEC cppVar_16137;
	BIT_VEC cppVar_16138;
	BIT_VEC cppVar_16139;
	bool cppVar_16140;
	BIT_VEC cppVar_16142;
	BIT_VEC cppVar_16143;
	BIT_VEC cppVar_16144;
	BIT_VEC cppVar_16145;
	bool cppVar_16146;
	BIT_VEC cppVar_16148;
	BIT_VEC cppVar_16149;
	BIT_VEC cppVar_16150;
	BIT_VEC cppVar_16151;
	bool cppVar_16152;
	BIT_VEC cppVar_16154;
	BIT_VEC cppVar_16155;
	BIT_VEC cppVar_16156;
	BIT_VEC cppVar_16157;
	bool cppVar_16158;
	BIT_VEC cppVar_16160;
	BIT_VEC cppVar_16161;
	BIT_VEC cppVar_16162;
	BIT_VEC cppVar_16163;
	bool cppVar_16164;
	BIT_VEC cppVar_16166;
	BIT_VEC cppVar_16167;
	BIT_VEC cppVar_16168;
	BIT_VEC cppVar_16169;
	bool cppVar_16170;
	BIT_VEC cppVar_16172;
	BIT_VEC cppVar_16173;
	BIT_VEC cppVar_16174;
	BIT_VEC cppVar_16175;
	bool cppVar_16176;
	BIT_VEC cppVar_16178;
	BIT_VEC cppVar_16179;
	BIT_VEC cppVar_16180;
	BIT_VEC cppVar_16181;
	bool cppVar_16182;
	BIT_VEC cppVar_16184;
	BIT_VEC cppVar_16185;
	BIT_VEC cppVar_16186;
	BIT_VEC cppVar_16187;
	bool cppVar_16188;
	BIT_VEC cppVar_16190;
	BIT_VEC cppVar_16191;
	BIT_VEC cppVar_16192;
	BIT_VEC cppVar_16193;
	bool cppVar_16194;
	BIT_VEC cppVar_16196;
	BIT_VEC cppVar_16197;
	BIT_VEC cppVar_16198;
	BIT_VEC cppVar_16199;
	bool cppVar_16200;
	BIT_VEC cppVar_16201;
	BIT_VEC cppVar_16195;
	BIT_VEC cppVar_16189;
	BIT_VEC cppVar_16183;
	BIT_VEC cppVar_16177;
	BIT_VEC cppVar_16171;
	BIT_VEC cppVar_16165;
	BIT_VEC cppVar_16159;
	BIT_VEC cppVar_16153;
	BIT_VEC cppVar_16147;
	BIT_VEC cppVar_16141;
	BIT_VEC cppVar_16135;
	BIT_VEC cppVar_16129;
	BIT_VEC cppVar_16123;
	BIT_VEC cppVar_16117;
	BIT_VEC cppVar_16111;
	BIT_VEC cppVar_16105;
	BIT_VEC cppVar_16099;
	BIT_VEC cppVar_16093;
	BIT_VEC cppVar_16087;
	BIT_VEC cppVar_16081;
	BIT_VEC cppVar_16075;
	BIT_VEC cppVar_16062;
	BIT_VEC cppVar_16056;
	BIT_VEC cppVar_16203;
	BIT_VEC cppVar_16204;
	bool cppVar_16205;
	BIT_VEC cppVar_16207;
	BIT_VEC cppVar_16208;
	BIT_VEC cppVar_16209;
	BIT_VEC cppVar_16210;
	bool cppVar_16211;
	BIT_VEC cppVar_16213;
	BIT_VEC cppVar_16214;
	BIT_VEC cppVar_16215;
	BIT_VEC cppVar_16216;
	BIT_VEC cppVar_16217;
	BIT_VEC cppVar_16218;
	BIT_VEC cppVar_16219;
	bool cppVar_16220;
	BIT_VEC cppVar_16221;
	BIT_VEC cppVar_16222;
	BIT_VEC cppVar_16223;
	BIT_VEC cppVar_16224;
	BIT_VEC cppVar_16226;
	BIT_VEC cppVar_16227;
	BIT_VEC cppVar_16228;
	BIT_VEC cppVar_16229;
	bool cppVar_16230;
	BIT_VEC cppVar_16232;
	BIT_VEC cppVar_16233;
	BIT_VEC cppVar_16234;
	BIT_VEC cppVar_16235;
	bool cppVar_16236;
	BIT_VEC cppVar_16238;
	BIT_VEC cppVar_16239;
	BIT_VEC cppVar_16240;
	BIT_VEC cppVar_16241;
	bool cppVar_16242;
	BIT_VEC cppVar_16244;
	BIT_VEC cppVar_16245;
	BIT_VEC cppVar_16246;
	BIT_VEC cppVar_16247;
	bool cppVar_16248;
	BIT_VEC cppVar_16250;
	BIT_VEC cppVar_16251;
	BIT_VEC cppVar_16252;
	BIT_VEC cppVar_16253;
	bool cppVar_16254;
	BIT_VEC cppVar_16256;
	BIT_VEC cppVar_16257;
	BIT_VEC cppVar_16258;
	BIT_VEC cppVar_16259;
	bool cppVar_16260;
	BIT_VEC cppVar_16262;
	BIT_VEC cppVar_16263;
	BIT_VEC cppVar_16264;
	BIT_VEC cppVar_16265;
	bool cppVar_16266;
	BIT_VEC cppVar_16268;
	BIT_VEC cppVar_16269;
	BIT_VEC cppVar_16270;
	BIT_VEC cppVar_16271;
	bool cppVar_16272;
	BIT_VEC cppVar_16274;
	BIT_VEC cppVar_16275;
	BIT_VEC cppVar_16276;
	BIT_VEC cppVar_16277;
	bool cppVar_16278;
	BIT_VEC cppVar_16280;
	BIT_VEC cppVar_16281;
	BIT_VEC cppVar_16282;
	BIT_VEC cppVar_16283;
	bool cppVar_16284;
	BIT_VEC cppVar_16286;
	BIT_VEC cppVar_16287;
	BIT_VEC cppVar_16288;
	BIT_VEC cppVar_16289;
	bool cppVar_16290;
	BIT_VEC cppVar_16292;
	BIT_VEC cppVar_16293;
	BIT_VEC cppVar_16294;
	BIT_VEC cppVar_16295;
	bool cppVar_16296;
	BIT_VEC cppVar_16298;
	BIT_VEC cppVar_16299;
	BIT_VEC cppVar_16300;
	BIT_VEC cppVar_16301;
	bool cppVar_16302;
	BIT_VEC cppVar_16304;
	BIT_VEC cppVar_16305;
	BIT_VEC cppVar_16306;
	BIT_VEC cppVar_16307;
	bool cppVar_16308;
	BIT_VEC cppVar_16310;
	BIT_VEC cppVar_16311;
	BIT_VEC cppVar_16312;
	BIT_VEC cppVar_16313;
	bool cppVar_16314;
	BIT_VEC cppVar_16316;
	BIT_VEC cppVar_16317;
	BIT_VEC cppVar_16318;
	BIT_VEC cppVar_16319;
	bool cppVar_16320;
	BIT_VEC cppVar_16322;
	BIT_VEC cppVar_16323;
	BIT_VEC cppVar_16324;
	BIT_VEC cppVar_16325;
	bool cppVar_16326;
	BIT_VEC cppVar_16328;
	BIT_VEC cppVar_16329;
	BIT_VEC cppVar_16330;
	BIT_VEC cppVar_16331;
	bool cppVar_16332;
	BIT_VEC cppVar_16334;
	BIT_VEC cppVar_16335;
	BIT_VEC cppVar_16336;
	BIT_VEC cppVar_16337;
	bool cppVar_16338;
	BIT_VEC cppVar_16340;
	BIT_VEC cppVar_16341;
	BIT_VEC cppVar_16342;
	BIT_VEC cppVar_16343;
	bool cppVar_16344;
	BIT_VEC cppVar_16346;
	BIT_VEC cppVar_16347;
	BIT_VEC cppVar_16348;
	BIT_VEC cppVar_16349;
	bool cppVar_16350;
	BIT_VEC cppVar_16351;
	BIT_VEC cppVar_16345;
	BIT_VEC cppVar_16339;
	BIT_VEC cppVar_16333;
	BIT_VEC cppVar_16327;
	BIT_VEC cppVar_16321;
	BIT_VEC cppVar_16315;
	BIT_VEC cppVar_16309;
	BIT_VEC cppVar_16303;
	BIT_VEC cppVar_16297;
	BIT_VEC cppVar_16291;
	BIT_VEC cppVar_16285;
	BIT_VEC cppVar_16279;
	BIT_VEC cppVar_16273;
	BIT_VEC cppVar_16267;
	BIT_VEC cppVar_16261;
	BIT_VEC cppVar_16255;
	BIT_VEC cppVar_16249;
	BIT_VEC cppVar_16243;
	BIT_VEC cppVar_16237;
	BIT_VEC cppVar_16231;
	BIT_VEC cppVar_16225;
	BIT_VEC cppVar_16212;
	BIT_VEC cppVar_16206;
	BIT_VEC cppVar_16353;
	BIT_VEC cppVar_16354;
	bool cppVar_16355;
	BIT_VEC cppVar_16357;
	BIT_VEC cppVar_16358;
	BIT_VEC cppVar_16359;
	BIT_VEC cppVar_16360;
	bool cppVar_16361;
	BIT_VEC cppVar_16362;
	BIT_VEC cppVar_16363;
	BIT_VEC cppVar_16364;
	BIT_VEC cppVar_16365;
	BIT_VEC cppVar_16366;
	BIT_VEC cppVar_16367;
	BIT_VEC cppVar_16368;
	BIT_VEC cppVar_16356;
	BIT_VEC cppVar_16370;
	BIT_VEC cppVar_16371;
	bool cppVar_16372;
	BIT_VEC cppVar_16374;
	BIT_VEC cppVar_16375;
	BIT_VEC cppVar_16376;
	BIT_VEC cppVar_16377;
	bool cppVar_16378;
	BIT_VEC cppVar_16379;
	BIT_VEC cppVar_16380;
	BIT_VEC cppVar_16381;
	BIT_VEC cppVar_16382;
	BIT_VEC cppVar_16383;
	BIT_VEC cppVar_16384;
	BIT_VEC cppVar_16385;
	BIT_VEC cppVar_16373;
	BIT_VEC cppVar_16387;
	BIT_VEC cppVar_16388;
	bool cppVar_16389;
	BIT_VEC cppVar_16391;
	BIT_VEC cppVar_16392;
	BIT_VEC cppVar_16393;
	BIT_VEC cppVar_16394;
	bool cppVar_16395;
	BIT_VEC cppVar_16397;
	BIT_VEC cppVar_16398;
	BIT_VEC cppVar_16399;
	BIT_VEC cppVar_16400;
	BIT_VEC cppVar_16401;
	bool cppVar_16402;
	BIT_VEC cppVar_16403;
	BIT_VEC cppVar_16404;
	BIT_VEC cppVar_16405;
	BIT_VEC cppVar_16407;
	BIT_VEC cppVar_16408;
	BIT_VEC cppVar_16409;
	bool cppVar_16410;
	BIT_VEC cppVar_16412;
	BIT_VEC cppVar_16413;
	BIT_VEC cppVar_16414;
	bool cppVar_16415;
	BIT_VEC cppVar_16417;
	BIT_VEC cppVar_16418;
	BIT_VEC cppVar_16419;
	bool cppVar_16420;
	BIT_VEC cppVar_16422;
	BIT_VEC cppVar_16423;
	BIT_VEC cppVar_16424;
	bool cppVar_16425;
	BIT_VEC cppVar_16427;
	BIT_VEC cppVar_16428;
	BIT_VEC cppVar_16429;
	bool cppVar_16430;
	BIT_VEC cppVar_16432;
	BIT_VEC cppVar_16433;
	BIT_VEC cppVar_16434;
	bool cppVar_16435;
	BIT_VEC cppVar_16437;
	BIT_VEC cppVar_16438;
	BIT_VEC cppVar_16439;
	bool cppVar_16440;
	BIT_VEC cppVar_16442;
	BIT_VEC cppVar_16443;
	BIT_VEC cppVar_16444;
	bool cppVar_16445;
	BIT_VEC cppVar_16447;
	BIT_VEC cppVar_16448;
	BIT_VEC cppVar_16449;
	bool cppVar_16450;
	BIT_VEC cppVar_16452;
	BIT_VEC cppVar_16453;
	BIT_VEC cppVar_16454;
	bool cppVar_16455;
	BIT_VEC cppVar_16457;
	BIT_VEC cppVar_16458;
	BIT_VEC cppVar_16459;
	bool cppVar_16460;
	BIT_VEC cppVar_16462;
	BIT_VEC cppVar_16463;
	BIT_VEC cppVar_16464;
	bool cppVar_16465;
	BIT_VEC cppVar_16467;
	BIT_VEC cppVar_16468;
	BIT_VEC cppVar_16469;
	bool cppVar_16470;
	BIT_VEC cppVar_16472;
	BIT_VEC cppVar_16473;
	BIT_VEC cppVar_16474;
	bool cppVar_16475;
	BIT_VEC cppVar_16477;
	BIT_VEC cppVar_16478;
	BIT_VEC cppVar_16479;
	bool cppVar_16480;
	BIT_VEC cppVar_16482;
	BIT_VEC cppVar_16483;
	BIT_VEC cppVar_16484;
	bool cppVar_16485;
	BIT_VEC cppVar_16487;
	BIT_VEC cppVar_16488;
	BIT_VEC cppVar_16489;
	bool cppVar_16490;
	BIT_VEC cppVar_16492;
	BIT_VEC cppVar_16493;
	BIT_VEC cppVar_16494;
	bool cppVar_16495;
	BIT_VEC cppVar_16497;
	BIT_VEC cppVar_16498;
	BIT_VEC cppVar_16499;
	bool cppVar_16500;
	BIT_VEC cppVar_16502;
	BIT_VEC cppVar_16503;
	BIT_VEC cppVar_16504;
	bool cppVar_16505;
	BIT_VEC cppVar_16507;
	BIT_VEC cppVar_16508;
	BIT_VEC cppVar_16509;
	bool cppVar_16510;
	BIT_VEC cppVar_16511;
	BIT_VEC cppVar_16506;
	BIT_VEC cppVar_16501;
	BIT_VEC cppVar_16496;
	BIT_VEC cppVar_16491;
	BIT_VEC cppVar_16486;
	BIT_VEC cppVar_16481;
	BIT_VEC cppVar_16476;
	BIT_VEC cppVar_16471;
	BIT_VEC cppVar_16466;
	BIT_VEC cppVar_16461;
	BIT_VEC cppVar_16456;
	BIT_VEC cppVar_16451;
	BIT_VEC cppVar_16446;
	BIT_VEC cppVar_16441;
	BIT_VEC cppVar_16436;
	BIT_VEC cppVar_16431;
	BIT_VEC cppVar_16426;
	BIT_VEC cppVar_16421;
	BIT_VEC cppVar_16416;
	BIT_VEC cppVar_16411;
	BIT_VEC cppVar_16406;
	BIT_VEC cppVar_16396;
	BIT_VEC cppVar_16390;
	BIT_VEC cppVar_16513;
	BIT_VEC cppVar_16514;
	bool cppVar_16515;
	BIT_VEC cppVar_16517;
	BIT_VEC cppVar_16518;
	BIT_VEC cppVar_16519;
	BIT_VEC cppVar_16520;
	bool cppVar_16521;
	BIT_VEC cppVar_16522;
	BIT_VEC cppVar_16523;
	BIT_VEC cppVar_16524;
	BIT_VEC cppVar_16516;
	BIT_VEC cppVar_16526;
	BIT_VEC cppVar_16527;
	bool cppVar_16528;
	BIT_VEC cppVar_16530;
	BIT_VEC cppVar_16531;
	BIT_VEC cppVar_16532;
	BIT_VEC cppVar_16533;
	bool cppVar_16534;
	BIT_VEC cppVar_16536;
	BIT_VEC cppVar_16537;
	BIT_VEC cppVar_16538;
	BIT_VEC cppVar_16539;
	bool cppVar_16540;
	BIT_VEC cppVar_16541;
	BIT_VEC cppVar_16542;
	BIT_VEC cppVar_16543;
	BIT_VEC cppVar_16545;
	BIT_VEC cppVar_16546;
	BIT_VEC cppVar_16547;
	bool cppVar_16548;
	BIT_VEC cppVar_16550;
	BIT_VEC cppVar_16551;
	BIT_VEC cppVar_16552;
	bool cppVar_16553;
	BIT_VEC cppVar_16555;
	BIT_VEC cppVar_16556;
	BIT_VEC cppVar_16557;
	bool cppVar_16558;
	BIT_VEC cppVar_16560;
	BIT_VEC cppVar_16561;
	BIT_VEC cppVar_16562;
	bool cppVar_16563;
	BIT_VEC cppVar_16565;
	BIT_VEC cppVar_16566;
	BIT_VEC cppVar_16567;
	bool cppVar_16568;
	BIT_VEC cppVar_16570;
	BIT_VEC cppVar_16571;
	BIT_VEC cppVar_16572;
	bool cppVar_16573;
	BIT_VEC cppVar_16575;
	BIT_VEC cppVar_16576;
	BIT_VEC cppVar_16577;
	bool cppVar_16578;
	BIT_VEC cppVar_16580;
	BIT_VEC cppVar_16581;
	BIT_VEC cppVar_16582;
	bool cppVar_16583;
	BIT_VEC cppVar_16585;
	BIT_VEC cppVar_16586;
	BIT_VEC cppVar_16587;
	bool cppVar_16588;
	BIT_VEC cppVar_16590;
	BIT_VEC cppVar_16591;
	BIT_VEC cppVar_16592;
	bool cppVar_16593;
	BIT_VEC cppVar_16595;
	BIT_VEC cppVar_16596;
	BIT_VEC cppVar_16597;
	bool cppVar_16598;
	BIT_VEC cppVar_16600;
	BIT_VEC cppVar_16601;
	BIT_VEC cppVar_16602;
	bool cppVar_16603;
	BIT_VEC cppVar_16605;
	BIT_VEC cppVar_16606;
	BIT_VEC cppVar_16607;
	bool cppVar_16608;
	BIT_VEC cppVar_16610;
	BIT_VEC cppVar_16611;
	BIT_VEC cppVar_16612;
	bool cppVar_16613;
	BIT_VEC cppVar_16615;
	BIT_VEC cppVar_16616;
	BIT_VEC cppVar_16617;
	bool cppVar_16618;
	BIT_VEC cppVar_16620;
	BIT_VEC cppVar_16621;
	BIT_VEC cppVar_16622;
	bool cppVar_16623;
	BIT_VEC cppVar_16625;
	BIT_VEC cppVar_16626;
	BIT_VEC cppVar_16627;
	bool cppVar_16628;
	BIT_VEC cppVar_16630;
	BIT_VEC cppVar_16631;
	BIT_VEC cppVar_16632;
	bool cppVar_16633;
	BIT_VEC cppVar_16635;
	BIT_VEC cppVar_16636;
	BIT_VEC cppVar_16637;
	bool cppVar_16638;
	BIT_VEC cppVar_16640;
	BIT_VEC cppVar_16641;
	BIT_VEC cppVar_16642;
	bool cppVar_16643;
	BIT_VEC cppVar_16645;
	BIT_VEC cppVar_16646;
	BIT_VEC cppVar_16647;
	bool cppVar_16648;
	BIT_VEC cppVar_16649;
	BIT_VEC cppVar_16644;
	BIT_VEC cppVar_16639;
	BIT_VEC cppVar_16634;
	BIT_VEC cppVar_16629;
	BIT_VEC cppVar_16624;
	BIT_VEC cppVar_16619;
	BIT_VEC cppVar_16614;
	BIT_VEC cppVar_16609;
	BIT_VEC cppVar_16604;
	BIT_VEC cppVar_16599;
	BIT_VEC cppVar_16594;
	BIT_VEC cppVar_16589;
	BIT_VEC cppVar_16584;
	BIT_VEC cppVar_16579;
	BIT_VEC cppVar_16574;
	BIT_VEC cppVar_16569;
	BIT_VEC cppVar_16564;
	BIT_VEC cppVar_16559;
	BIT_VEC cppVar_16554;
	BIT_VEC cppVar_16549;
	BIT_VEC cppVar_16544;
	BIT_VEC cppVar_16535;
	BIT_VEC cppVar_16650;
	BIT_VEC cppVar_16651;
	BIT_VEC cppVar_16652;
	BIT_VEC cppVar_16653;
	BIT_VEC cppVar_16529;
	BIT_VEC cppVar_16655;
	BIT_VEC cppVar_16656;
	bool cppVar_16657;
	BIT_VEC cppVar_16659;
	BIT_VEC cppVar_16660;
	BIT_VEC cppVar_16661;
	BIT_VEC cppVar_16662;
	bool cppVar_16663;
	BIT_VEC cppVar_16665;
	BIT_VEC cppVar_16666;
	BIT_VEC cppVar_16667;
	BIT_VEC cppVar_16668;
	bool cppVar_16669;
	BIT_VEC cppVar_16670;
	BIT_VEC cppVar_16671;
	BIT_VEC cppVar_16672;
	BIT_VEC cppVar_16674;
	BIT_VEC cppVar_16675;
	BIT_VEC cppVar_16676;
	bool cppVar_16677;
	BIT_VEC cppVar_16679;
	BIT_VEC cppVar_16680;
	BIT_VEC cppVar_16681;
	bool cppVar_16682;
	BIT_VEC cppVar_16684;
	BIT_VEC cppVar_16685;
	BIT_VEC cppVar_16686;
	bool cppVar_16687;
	BIT_VEC cppVar_16689;
	BIT_VEC cppVar_16690;
	BIT_VEC cppVar_16691;
	bool cppVar_16692;
	BIT_VEC cppVar_16694;
	BIT_VEC cppVar_16695;
	BIT_VEC cppVar_16696;
	bool cppVar_16697;
	BIT_VEC cppVar_16699;
	BIT_VEC cppVar_16700;
	BIT_VEC cppVar_16701;
	bool cppVar_16702;
	BIT_VEC cppVar_16704;
	BIT_VEC cppVar_16705;
	BIT_VEC cppVar_16706;
	bool cppVar_16707;
	BIT_VEC cppVar_16709;
	BIT_VEC cppVar_16710;
	BIT_VEC cppVar_16711;
	bool cppVar_16712;
	BIT_VEC cppVar_16714;
	BIT_VEC cppVar_16715;
	BIT_VEC cppVar_16716;
	bool cppVar_16717;
	BIT_VEC cppVar_16719;
	BIT_VEC cppVar_16720;
	BIT_VEC cppVar_16721;
	bool cppVar_16722;
	BIT_VEC cppVar_16724;
	BIT_VEC cppVar_16725;
	BIT_VEC cppVar_16726;
	bool cppVar_16727;
	BIT_VEC cppVar_16729;
	BIT_VEC cppVar_16730;
	BIT_VEC cppVar_16731;
	bool cppVar_16732;
	BIT_VEC cppVar_16734;
	BIT_VEC cppVar_16735;
	BIT_VEC cppVar_16736;
	bool cppVar_16737;
	BIT_VEC cppVar_16739;
	BIT_VEC cppVar_16740;
	BIT_VEC cppVar_16741;
	bool cppVar_16742;
	BIT_VEC cppVar_16744;
	BIT_VEC cppVar_16745;
	BIT_VEC cppVar_16746;
	bool cppVar_16747;
	BIT_VEC cppVar_16749;
	BIT_VEC cppVar_16750;
	BIT_VEC cppVar_16751;
	bool cppVar_16752;
	BIT_VEC cppVar_16754;
	BIT_VEC cppVar_16755;
	BIT_VEC cppVar_16756;
	bool cppVar_16757;
	BIT_VEC cppVar_16759;
	BIT_VEC cppVar_16760;
	BIT_VEC cppVar_16761;
	bool cppVar_16762;
	BIT_VEC cppVar_16764;
	BIT_VEC cppVar_16765;
	BIT_VEC cppVar_16766;
	bool cppVar_16767;
	BIT_VEC cppVar_16769;
	BIT_VEC cppVar_16770;
	BIT_VEC cppVar_16771;
	bool cppVar_16772;
	BIT_VEC cppVar_16774;
	BIT_VEC cppVar_16775;
	BIT_VEC cppVar_16776;
	bool cppVar_16777;
	BIT_VEC cppVar_16778;
	BIT_VEC cppVar_16773;
	BIT_VEC cppVar_16768;
	BIT_VEC cppVar_16763;
	BIT_VEC cppVar_16758;
	BIT_VEC cppVar_16753;
	BIT_VEC cppVar_16748;
	BIT_VEC cppVar_16743;
	BIT_VEC cppVar_16738;
	BIT_VEC cppVar_16733;
	BIT_VEC cppVar_16728;
	BIT_VEC cppVar_16723;
	BIT_VEC cppVar_16718;
	BIT_VEC cppVar_16713;
	BIT_VEC cppVar_16708;
	BIT_VEC cppVar_16703;
	BIT_VEC cppVar_16698;
	BIT_VEC cppVar_16693;
	BIT_VEC cppVar_16688;
	BIT_VEC cppVar_16683;
	BIT_VEC cppVar_16678;
	BIT_VEC cppVar_16673;
	BIT_VEC cppVar_16664;
	BIT_VEC cppVar_16779;
	BIT_VEC cppVar_16658;
	BIT_VEC cppVar_16781;
	BIT_VEC cppVar_16782;
	bool cppVar_16783;
	BIT_VEC cppVar_16785;
	BIT_VEC cppVar_16786;
	BIT_VEC cppVar_16787;
	BIT_VEC cppVar_16788;
	bool cppVar_16789;
	BIT_VEC cppVar_16791;
	BIT_VEC cppVar_16792;
	BIT_VEC cppVar_16793;
	BIT_VEC cppVar_16794;
	bool cppVar_16795;
	BIT_VEC cppVar_16796;
	BIT_VEC cppVar_16797;
	BIT_VEC cppVar_16798;
	BIT_VEC cppVar_16800;
	BIT_VEC cppVar_16801;
	BIT_VEC cppVar_16802;
	bool cppVar_16803;
	BIT_VEC cppVar_16805;
	BIT_VEC cppVar_16806;
	BIT_VEC cppVar_16807;
	bool cppVar_16808;
	BIT_VEC cppVar_16810;
	BIT_VEC cppVar_16811;
	BIT_VEC cppVar_16812;
	bool cppVar_16813;
	BIT_VEC cppVar_16815;
	BIT_VEC cppVar_16816;
	BIT_VEC cppVar_16817;
	bool cppVar_16818;
	BIT_VEC cppVar_16820;
	BIT_VEC cppVar_16821;
	BIT_VEC cppVar_16822;
	bool cppVar_16823;
	BIT_VEC cppVar_16825;
	BIT_VEC cppVar_16826;
	BIT_VEC cppVar_16827;
	bool cppVar_16828;
	BIT_VEC cppVar_16830;
	BIT_VEC cppVar_16831;
	BIT_VEC cppVar_16832;
	bool cppVar_16833;
	BIT_VEC cppVar_16835;
	BIT_VEC cppVar_16836;
	BIT_VEC cppVar_16837;
	bool cppVar_16838;
	BIT_VEC cppVar_16840;
	BIT_VEC cppVar_16841;
	BIT_VEC cppVar_16842;
	bool cppVar_16843;
	BIT_VEC cppVar_16845;
	BIT_VEC cppVar_16846;
	BIT_VEC cppVar_16847;
	bool cppVar_16848;
	BIT_VEC cppVar_16850;
	BIT_VEC cppVar_16851;
	BIT_VEC cppVar_16852;
	bool cppVar_16853;
	BIT_VEC cppVar_16855;
	BIT_VEC cppVar_16856;
	BIT_VEC cppVar_16857;
	bool cppVar_16858;
	BIT_VEC cppVar_16860;
	BIT_VEC cppVar_16861;
	BIT_VEC cppVar_16862;
	bool cppVar_16863;
	BIT_VEC cppVar_16865;
	BIT_VEC cppVar_16866;
	BIT_VEC cppVar_16867;
	bool cppVar_16868;
	BIT_VEC cppVar_16870;
	BIT_VEC cppVar_16871;
	BIT_VEC cppVar_16872;
	bool cppVar_16873;
	BIT_VEC cppVar_16875;
	BIT_VEC cppVar_16876;
	BIT_VEC cppVar_16877;
	bool cppVar_16878;
	BIT_VEC cppVar_16880;
	BIT_VEC cppVar_16881;
	BIT_VEC cppVar_16882;
	bool cppVar_16883;
	BIT_VEC cppVar_16885;
	BIT_VEC cppVar_16886;
	BIT_VEC cppVar_16887;
	bool cppVar_16888;
	BIT_VEC cppVar_16890;
	BIT_VEC cppVar_16891;
	BIT_VEC cppVar_16892;
	bool cppVar_16893;
	BIT_VEC cppVar_16895;
	BIT_VEC cppVar_16896;
	BIT_VEC cppVar_16897;
	bool cppVar_16898;
	BIT_VEC cppVar_16900;
	BIT_VEC cppVar_16901;
	BIT_VEC cppVar_16902;
	bool cppVar_16903;
	BIT_VEC cppVar_16904;
	BIT_VEC cppVar_16899;
	BIT_VEC cppVar_16894;
	BIT_VEC cppVar_16889;
	BIT_VEC cppVar_16884;
	BIT_VEC cppVar_16879;
	BIT_VEC cppVar_16874;
	BIT_VEC cppVar_16869;
	BIT_VEC cppVar_16864;
	BIT_VEC cppVar_16859;
	BIT_VEC cppVar_16854;
	BIT_VEC cppVar_16849;
	BIT_VEC cppVar_16844;
	BIT_VEC cppVar_16839;
	BIT_VEC cppVar_16834;
	BIT_VEC cppVar_16829;
	BIT_VEC cppVar_16824;
	BIT_VEC cppVar_16819;
	BIT_VEC cppVar_16814;
	BIT_VEC cppVar_16809;
	BIT_VEC cppVar_16804;
	BIT_VEC cppVar_16799;
	BIT_VEC cppVar_16790;
	BIT_VEC cppVar_16905;
	BIT_VEC cppVar_16906;
	BIT_VEC cppVar_16907;
	BIT_VEC cppVar_16908;
	BIT_VEC cppVar_16784;
	BIT_VEC cppVar_16910;
	BIT_VEC cppVar_16911;
	bool cppVar_16912;
	BIT_VEC cppVar_16914;
	BIT_VEC cppVar_16915;
	BIT_VEC cppVar_16916;
	BIT_VEC cppVar_16917;
	bool cppVar_16918;
	BIT_VEC cppVar_16920;
	BIT_VEC cppVar_16921;
	BIT_VEC cppVar_16922;
	BIT_VEC cppVar_16923;
	bool cppVar_16924;
	BIT_VEC cppVar_16925;
	BIT_VEC cppVar_16926;
	BIT_VEC cppVar_16927;
	BIT_VEC cppVar_16929;
	BIT_VEC cppVar_16930;
	BIT_VEC cppVar_16931;
	bool cppVar_16932;
	BIT_VEC cppVar_16934;
	BIT_VEC cppVar_16935;
	BIT_VEC cppVar_16936;
	bool cppVar_16937;
	BIT_VEC cppVar_16939;
	BIT_VEC cppVar_16940;
	BIT_VEC cppVar_16941;
	bool cppVar_16942;
	BIT_VEC cppVar_16944;
	BIT_VEC cppVar_16945;
	BIT_VEC cppVar_16946;
	bool cppVar_16947;
	BIT_VEC cppVar_16949;
	BIT_VEC cppVar_16950;
	BIT_VEC cppVar_16951;
	bool cppVar_16952;
	BIT_VEC cppVar_16954;
	BIT_VEC cppVar_16955;
	BIT_VEC cppVar_16956;
	bool cppVar_16957;
	BIT_VEC cppVar_16959;
	BIT_VEC cppVar_16960;
	BIT_VEC cppVar_16961;
	bool cppVar_16962;
	BIT_VEC cppVar_16964;
	BIT_VEC cppVar_16965;
	BIT_VEC cppVar_16966;
	bool cppVar_16967;
	BIT_VEC cppVar_16969;
	BIT_VEC cppVar_16970;
	BIT_VEC cppVar_16971;
	bool cppVar_16972;
	BIT_VEC cppVar_16974;
	BIT_VEC cppVar_16975;
	BIT_VEC cppVar_16976;
	bool cppVar_16977;
	BIT_VEC cppVar_16979;
	BIT_VEC cppVar_16980;
	BIT_VEC cppVar_16981;
	bool cppVar_16982;
	BIT_VEC cppVar_16984;
	BIT_VEC cppVar_16985;
	BIT_VEC cppVar_16986;
	bool cppVar_16987;
	BIT_VEC cppVar_16989;
	BIT_VEC cppVar_16990;
	BIT_VEC cppVar_16991;
	bool cppVar_16992;
	BIT_VEC cppVar_16994;
	BIT_VEC cppVar_16995;
	BIT_VEC cppVar_16996;
	bool cppVar_16997;
	BIT_VEC cppVar_16999;
	BIT_VEC cppVar_17000;
	BIT_VEC cppVar_17001;
	bool cppVar_17002;
	BIT_VEC cppVar_17004;
	BIT_VEC cppVar_17005;
	BIT_VEC cppVar_17006;
	bool cppVar_17007;
	BIT_VEC cppVar_17009;
	BIT_VEC cppVar_17010;
	BIT_VEC cppVar_17011;
	bool cppVar_17012;
	BIT_VEC cppVar_17014;
	BIT_VEC cppVar_17015;
	BIT_VEC cppVar_17016;
	bool cppVar_17017;
	BIT_VEC cppVar_17019;
	BIT_VEC cppVar_17020;
	BIT_VEC cppVar_17021;
	bool cppVar_17022;
	BIT_VEC cppVar_17024;
	BIT_VEC cppVar_17025;
	BIT_VEC cppVar_17026;
	bool cppVar_17027;
	BIT_VEC cppVar_17029;
	BIT_VEC cppVar_17030;
	BIT_VEC cppVar_17031;
	bool cppVar_17032;
	BIT_VEC cppVar_17033;
	BIT_VEC cppVar_17028;
	BIT_VEC cppVar_17023;
	BIT_VEC cppVar_17018;
	BIT_VEC cppVar_17013;
	BIT_VEC cppVar_17008;
	BIT_VEC cppVar_17003;
	BIT_VEC cppVar_16998;
	BIT_VEC cppVar_16993;
	BIT_VEC cppVar_16988;
	BIT_VEC cppVar_16983;
	BIT_VEC cppVar_16978;
	BIT_VEC cppVar_16973;
	BIT_VEC cppVar_16968;
	BIT_VEC cppVar_16963;
	BIT_VEC cppVar_16958;
	BIT_VEC cppVar_16953;
	BIT_VEC cppVar_16948;
	BIT_VEC cppVar_16943;
	BIT_VEC cppVar_16938;
	BIT_VEC cppVar_16933;
	BIT_VEC cppVar_16928;
	BIT_VEC cppVar_16919;
	BIT_VEC cppVar_17034;
	BIT_VEC cppVar_16913;
	BIT_VEC cppVar_17036;
	BIT_VEC cppVar_17037;
	bool cppVar_17038;
	BIT_VEC cppVar_17040;
	BIT_VEC cppVar_17041;
	BIT_VEC cppVar_17042;
	BIT_VEC cppVar_17043;
	bool cppVar_17044;
	BIT_VEC cppVar_17046;
	BIT_VEC cppVar_17047;
	BIT_VEC cppVar_17048;
	BIT_VEC cppVar_17049;
	bool cppVar_17050;
	BIT_VEC cppVar_17051;
	BIT_VEC cppVar_17052;
	BIT_VEC cppVar_17053;
	BIT_VEC cppVar_17055;
	BIT_VEC cppVar_17056;
	BIT_VEC cppVar_17057;
	bool cppVar_17058;
	BIT_VEC cppVar_17060;
	BIT_VEC cppVar_17061;
	BIT_VEC cppVar_17062;
	bool cppVar_17063;
	BIT_VEC cppVar_17065;
	BIT_VEC cppVar_17066;
	BIT_VEC cppVar_17067;
	bool cppVar_17068;
	BIT_VEC cppVar_17070;
	BIT_VEC cppVar_17071;
	BIT_VEC cppVar_17072;
	bool cppVar_17073;
	BIT_VEC cppVar_17075;
	BIT_VEC cppVar_17076;
	BIT_VEC cppVar_17077;
	bool cppVar_17078;
	BIT_VEC cppVar_17080;
	BIT_VEC cppVar_17081;
	BIT_VEC cppVar_17082;
	bool cppVar_17083;
	BIT_VEC cppVar_17085;
	BIT_VEC cppVar_17086;
	BIT_VEC cppVar_17087;
	bool cppVar_17088;
	BIT_VEC cppVar_17090;
	BIT_VEC cppVar_17091;
	BIT_VEC cppVar_17092;
	bool cppVar_17093;
	BIT_VEC cppVar_17095;
	BIT_VEC cppVar_17096;
	BIT_VEC cppVar_17097;
	bool cppVar_17098;
	BIT_VEC cppVar_17100;
	BIT_VEC cppVar_17101;
	BIT_VEC cppVar_17102;
	bool cppVar_17103;
	BIT_VEC cppVar_17105;
	BIT_VEC cppVar_17106;
	BIT_VEC cppVar_17107;
	bool cppVar_17108;
	BIT_VEC cppVar_17110;
	BIT_VEC cppVar_17111;
	BIT_VEC cppVar_17112;
	bool cppVar_17113;
	BIT_VEC cppVar_17115;
	BIT_VEC cppVar_17116;
	BIT_VEC cppVar_17117;
	bool cppVar_17118;
	BIT_VEC cppVar_17120;
	BIT_VEC cppVar_17121;
	BIT_VEC cppVar_17122;
	bool cppVar_17123;
	BIT_VEC cppVar_17125;
	BIT_VEC cppVar_17126;
	BIT_VEC cppVar_17127;
	bool cppVar_17128;
	BIT_VEC cppVar_17130;
	BIT_VEC cppVar_17131;
	BIT_VEC cppVar_17132;
	bool cppVar_17133;
	BIT_VEC cppVar_17135;
	BIT_VEC cppVar_17136;
	BIT_VEC cppVar_17137;
	bool cppVar_17138;
	BIT_VEC cppVar_17140;
	BIT_VEC cppVar_17141;
	BIT_VEC cppVar_17142;
	bool cppVar_17143;
	BIT_VEC cppVar_17145;
	BIT_VEC cppVar_17146;
	BIT_VEC cppVar_17147;
	bool cppVar_17148;
	BIT_VEC cppVar_17150;
	BIT_VEC cppVar_17151;
	BIT_VEC cppVar_17152;
	bool cppVar_17153;
	BIT_VEC cppVar_17155;
	BIT_VEC cppVar_17156;
	BIT_VEC cppVar_17157;
	bool cppVar_17158;
	BIT_VEC cppVar_17159;
	BIT_VEC cppVar_17154;
	BIT_VEC cppVar_17149;
	BIT_VEC cppVar_17144;
	BIT_VEC cppVar_17139;
	BIT_VEC cppVar_17134;
	BIT_VEC cppVar_17129;
	BIT_VEC cppVar_17124;
	BIT_VEC cppVar_17119;
	BIT_VEC cppVar_17114;
	BIT_VEC cppVar_17109;
	BIT_VEC cppVar_17104;
	BIT_VEC cppVar_17099;
	BIT_VEC cppVar_17094;
	BIT_VEC cppVar_17089;
	BIT_VEC cppVar_17084;
	BIT_VEC cppVar_17079;
	BIT_VEC cppVar_17074;
	BIT_VEC cppVar_17069;
	BIT_VEC cppVar_17064;
	BIT_VEC cppVar_17059;
	BIT_VEC cppVar_17054;
	BIT_VEC cppVar_17045;
	BIT_VEC cppVar_17160;
	BIT_VEC cppVar_17161;
	BIT_VEC cppVar_17162;
	BIT_VEC cppVar_17163;
	BIT_VEC cppVar_17039;
	BIT_VEC cppVar_17165;
	BIT_VEC cppVar_17166;
	bool cppVar_17167;
	BIT_VEC cppVar_17169;
	BIT_VEC cppVar_17170;
	BIT_VEC cppVar_17171;
	BIT_VEC cppVar_17172;
	bool cppVar_17173;
	BIT_VEC cppVar_17175;
	BIT_VEC cppVar_17176;
	BIT_VEC cppVar_17177;
	BIT_VEC cppVar_17178;
	bool cppVar_17179;
	BIT_VEC cppVar_17180;
	BIT_VEC cppVar_17181;
	BIT_VEC cppVar_17182;
	BIT_VEC cppVar_17184;
	BIT_VEC cppVar_17185;
	BIT_VEC cppVar_17186;
	bool cppVar_17187;
	BIT_VEC cppVar_17189;
	BIT_VEC cppVar_17190;
	BIT_VEC cppVar_17191;
	bool cppVar_17192;
	BIT_VEC cppVar_17194;
	BIT_VEC cppVar_17195;
	BIT_VEC cppVar_17196;
	bool cppVar_17197;
	BIT_VEC cppVar_17199;
	BIT_VEC cppVar_17200;
	BIT_VEC cppVar_17201;
	bool cppVar_17202;
	BIT_VEC cppVar_17204;
	BIT_VEC cppVar_17205;
	BIT_VEC cppVar_17206;
	bool cppVar_17207;
	BIT_VEC cppVar_17209;
	BIT_VEC cppVar_17210;
	BIT_VEC cppVar_17211;
	bool cppVar_17212;
	BIT_VEC cppVar_17214;
	BIT_VEC cppVar_17215;
	BIT_VEC cppVar_17216;
	bool cppVar_17217;
	BIT_VEC cppVar_17219;
	BIT_VEC cppVar_17220;
	BIT_VEC cppVar_17221;
	bool cppVar_17222;
	BIT_VEC cppVar_17224;
	BIT_VEC cppVar_17225;
	BIT_VEC cppVar_17226;
	bool cppVar_17227;
	BIT_VEC cppVar_17229;
	BIT_VEC cppVar_17230;
	BIT_VEC cppVar_17231;
	bool cppVar_17232;
	BIT_VEC cppVar_17234;
	BIT_VEC cppVar_17235;
	BIT_VEC cppVar_17236;
	bool cppVar_17237;
	BIT_VEC cppVar_17239;
	BIT_VEC cppVar_17240;
	BIT_VEC cppVar_17241;
	bool cppVar_17242;
	BIT_VEC cppVar_17244;
	BIT_VEC cppVar_17245;
	BIT_VEC cppVar_17246;
	bool cppVar_17247;
	BIT_VEC cppVar_17249;
	BIT_VEC cppVar_17250;
	BIT_VEC cppVar_17251;
	bool cppVar_17252;
	BIT_VEC cppVar_17254;
	BIT_VEC cppVar_17255;
	BIT_VEC cppVar_17256;
	bool cppVar_17257;
	BIT_VEC cppVar_17259;
	BIT_VEC cppVar_17260;
	BIT_VEC cppVar_17261;
	bool cppVar_17262;
	BIT_VEC cppVar_17264;
	BIT_VEC cppVar_17265;
	BIT_VEC cppVar_17266;
	bool cppVar_17267;
	BIT_VEC cppVar_17269;
	BIT_VEC cppVar_17270;
	BIT_VEC cppVar_17271;
	bool cppVar_17272;
	BIT_VEC cppVar_17274;
	BIT_VEC cppVar_17275;
	BIT_VEC cppVar_17276;
	bool cppVar_17277;
	BIT_VEC cppVar_17279;
	BIT_VEC cppVar_17280;
	BIT_VEC cppVar_17281;
	bool cppVar_17282;
	BIT_VEC cppVar_17284;
	BIT_VEC cppVar_17285;
	BIT_VEC cppVar_17286;
	bool cppVar_17287;
	BIT_VEC cppVar_17288;
	BIT_VEC cppVar_17283;
	BIT_VEC cppVar_17278;
	BIT_VEC cppVar_17273;
	BIT_VEC cppVar_17268;
	BIT_VEC cppVar_17263;
	BIT_VEC cppVar_17258;
	BIT_VEC cppVar_17253;
	BIT_VEC cppVar_17248;
	BIT_VEC cppVar_17243;
	BIT_VEC cppVar_17238;
	BIT_VEC cppVar_17233;
	BIT_VEC cppVar_17228;
	BIT_VEC cppVar_17223;
	BIT_VEC cppVar_17218;
	BIT_VEC cppVar_17213;
	BIT_VEC cppVar_17208;
	BIT_VEC cppVar_17203;
	BIT_VEC cppVar_17198;
	BIT_VEC cppVar_17193;
	BIT_VEC cppVar_17188;
	BIT_VEC cppVar_17183;
	BIT_VEC cppVar_17174;
	BIT_VEC cppVar_17289;
	BIT_VEC cppVar_17168;
	BIT_VEC cppVar_17291;
	BIT_VEC cppVar_17292;
	bool cppVar_17293;
	BIT_VEC cppVar_17294;
	BIT_VEC cppVar_17295;
	bool cppVar_17296;
	bool cppVar_17297;
	BIT_VEC cppVar_17299;
	BIT_VEC cppVar_17300;
	BIT_VEC cppVar_17301;
	BIT_VEC cppVar_17302;
	bool cppVar_17303;
	BIT_VEC cppVar_17305;
	BIT_VEC cppVar_17306;
	BIT_VEC cppVar_17307;
	BIT_VEC cppVar_17308;
	bool cppVar_17309;
	BIT_VEC cppVar_17310;
	BIT_VEC cppVar_17311;
	BIT_VEC cppVar_17312;
	BIT_VEC cppVar_17314;
	BIT_VEC cppVar_17315;
	BIT_VEC cppVar_17316;
	bool cppVar_17317;
	BIT_VEC cppVar_17319;
	BIT_VEC cppVar_17320;
	BIT_VEC cppVar_17321;
	bool cppVar_17322;
	BIT_VEC cppVar_17324;
	BIT_VEC cppVar_17325;
	BIT_VEC cppVar_17326;
	bool cppVar_17327;
	BIT_VEC cppVar_17329;
	BIT_VEC cppVar_17330;
	BIT_VEC cppVar_17331;
	bool cppVar_17332;
	BIT_VEC cppVar_17334;
	BIT_VEC cppVar_17335;
	BIT_VEC cppVar_17336;
	bool cppVar_17337;
	BIT_VEC cppVar_17339;
	BIT_VEC cppVar_17340;
	BIT_VEC cppVar_17341;
	bool cppVar_17342;
	BIT_VEC cppVar_17344;
	BIT_VEC cppVar_17345;
	BIT_VEC cppVar_17346;
	bool cppVar_17347;
	BIT_VEC cppVar_17349;
	BIT_VEC cppVar_17350;
	BIT_VEC cppVar_17351;
	bool cppVar_17352;
	BIT_VEC cppVar_17354;
	BIT_VEC cppVar_17355;
	BIT_VEC cppVar_17356;
	bool cppVar_17357;
	BIT_VEC cppVar_17359;
	BIT_VEC cppVar_17360;
	BIT_VEC cppVar_17361;
	bool cppVar_17362;
	BIT_VEC cppVar_17364;
	BIT_VEC cppVar_17365;
	BIT_VEC cppVar_17366;
	bool cppVar_17367;
	BIT_VEC cppVar_17369;
	BIT_VEC cppVar_17370;
	BIT_VEC cppVar_17371;
	bool cppVar_17372;
	BIT_VEC cppVar_17374;
	BIT_VEC cppVar_17375;
	BIT_VEC cppVar_17376;
	bool cppVar_17377;
	BIT_VEC cppVar_17379;
	BIT_VEC cppVar_17380;
	BIT_VEC cppVar_17381;
	bool cppVar_17382;
	BIT_VEC cppVar_17384;
	BIT_VEC cppVar_17385;
	BIT_VEC cppVar_17386;
	bool cppVar_17387;
	BIT_VEC cppVar_17389;
	BIT_VEC cppVar_17390;
	BIT_VEC cppVar_17391;
	bool cppVar_17392;
	BIT_VEC cppVar_17394;
	BIT_VEC cppVar_17395;
	BIT_VEC cppVar_17396;
	bool cppVar_17397;
	BIT_VEC cppVar_17399;
	BIT_VEC cppVar_17400;
	BIT_VEC cppVar_17401;
	bool cppVar_17402;
	BIT_VEC cppVar_17404;
	BIT_VEC cppVar_17405;
	BIT_VEC cppVar_17406;
	bool cppVar_17407;
	BIT_VEC cppVar_17409;
	BIT_VEC cppVar_17410;
	BIT_VEC cppVar_17411;
	bool cppVar_17412;
	BIT_VEC cppVar_17414;
	BIT_VEC cppVar_17415;
	BIT_VEC cppVar_17416;
	bool cppVar_17417;
	BIT_VEC cppVar_17418;
	BIT_VEC cppVar_17413;
	BIT_VEC cppVar_17408;
	BIT_VEC cppVar_17403;
	BIT_VEC cppVar_17398;
	BIT_VEC cppVar_17393;
	BIT_VEC cppVar_17388;
	BIT_VEC cppVar_17383;
	BIT_VEC cppVar_17378;
	BIT_VEC cppVar_17373;
	BIT_VEC cppVar_17368;
	BIT_VEC cppVar_17363;
	BIT_VEC cppVar_17358;
	BIT_VEC cppVar_17353;
	BIT_VEC cppVar_17348;
	BIT_VEC cppVar_17343;
	BIT_VEC cppVar_17338;
	BIT_VEC cppVar_17333;
	BIT_VEC cppVar_17328;
	BIT_VEC cppVar_17323;
	BIT_VEC cppVar_17318;
	BIT_VEC cppVar_17313;
	BIT_VEC cppVar_17304;
	BIT_VEC cppVar_17419;
	BIT_VEC cppVar_17420;
	BIT_VEC cppVar_17298;
	BIT_VEC cppVar_17422;
	BIT_VEC cppVar_17423;
	bool cppVar_17424;
	BIT_VEC cppVar_17425;
	BIT_VEC cppVar_17426;
	bool cppVar_17427;
	bool cppVar_17428;
	BIT_VEC cppVar_17431;
	BIT_VEC cppVar_17432;
	BIT_VEC cppVar_17433;
	BIT_VEC cppVar_17434;
	BIT_VEC cppVar_17435;
	bool cppVar_17436;
	BIT_VEC cppVar_17437;
	BIT_VEC cppVar_17438;
	BIT_VEC cppVar_17439;
	BIT_VEC cppVar_17440;
	BIT_VEC cppVar_17441;
	BIT_VEC cppVar_17442;
	BIT_VEC cppVar_17443;
	BIT_VEC cppVar_17444;
	BIT_VEC cppVar_17445;
	BIT_VEC cppVar_17446;
	BIT_VEC cppVar_17447;
	BIT_VEC cppVar_17430;
	BIT_VEC cppVar_17448;
	bool cppVar_17449;
	BIT_VEC cppVar_17450;
	BIT_VEC cppVar_17451;
	BIT_VEC cppVar_17452;
	BIT_VEC cppVar_17453;
	BIT_VEC cppVar_17454;
	BIT_VEC cppVar_17455;
	BIT_VEC cppVar_17456;
	BIT_VEC cppVar_17459;
	BIT_VEC cppVar_17460;
	BIT_VEC cppVar_17461;
	bool cppVar_17462;
	BIT_VEC cppVar_17463;
	BIT_VEC cppVar_17464;
	BIT_VEC cppVar_17465;
	BIT_VEC cppVar_17466;
	BIT_VEC cppVar_17467;
	BIT_VEC cppVar_17468;
	BIT_VEC cppVar_17469;
	BIT_VEC cppVar_17470;
	BIT_VEC cppVar_17471;
	BIT_VEC cppVar_17458;
	BIT_VEC cppVar_17472;
	BIT_VEC cppVar_17473;
	bool cppVar_17474;
	BIT_VEC cppVar_17476;
	BIT_VEC cppVar_17477;
	BIT_VEC cppVar_17478;
	bool cppVar_17479;
	BIT_VEC cppVar_17480;
	BIT_VEC cppVar_17481;
	BIT_VEC cppVar_17482;
	BIT_VEC cppVar_17483;
	BIT_VEC cppVar_17484;
	BIT_VEC cppVar_17485;
	BIT_VEC cppVar_17486;
	BIT_VEC cppVar_17487;
	BIT_VEC cppVar_17488;
	BIT_VEC cppVar_17475;
	BIT_VEC cppVar_17489;
	BIT_VEC cppVar_17492;
	BIT_VEC cppVar_17493;
	BIT_VEC cppVar_17494;
	bool cppVar_17495;
	BIT_VEC cppVar_17496;
	BIT_VEC cppVar_17497;
	BIT_VEC cppVar_17498;
	BIT_VEC cppVar_17499;
	BIT_VEC cppVar_17500;
	BIT_VEC cppVar_17501;
	BIT_VEC cppVar_17502;
	BIT_VEC cppVar_17503;
	BIT_VEC cppVar_17504;
	BIT_VEC cppVar_17491;
	BIT_VEC cppVar_17505;
	bool cppVar_17506;
	BIT_VEC cppVar_17509;
	BIT_VEC cppVar_17510;
	BIT_VEC cppVar_17511;
	bool cppVar_17512;
	BIT_VEC cppVar_17513;
	BIT_VEC cppVar_17514;
	BIT_VEC cppVar_17515;
	BIT_VEC cppVar_17516;
	BIT_VEC cppVar_17517;
	BIT_VEC cppVar_17518;
	BIT_VEC cppVar_17519;
	BIT_VEC cppVar_17520;
	BIT_VEC cppVar_17521;
	BIT_VEC cppVar_17508;
	BIT_VEC cppVar_17522;
	bool cppVar_17523;
	BIT_VEC cppVar_17526;
	BIT_VEC cppVar_17527;
	BIT_VEC cppVar_17528;
	bool cppVar_17529;
	BIT_VEC cppVar_17530;
	BIT_VEC cppVar_17531;
	BIT_VEC cppVar_17532;
	BIT_VEC cppVar_17533;
	BIT_VEC cppVar_17534;
	BIT_VEC cppVar_17535;
	BIT_VEC cppVar_17536;
	BIT_VEC cppVar_17537;
	BIT_VEC cppVar_17538;
	BIT_VEC cppVar_17525;
	BIT_VEC cppVar_17539;
	bool cppVar_17540;
	BIT_VEC cppVar_17543;
	BIT_VEC cppVar_17544;
	BIT_VEC cppVar_17545;
	bool cppVar_17546;
	BIT_VEC cppVar_17547;
	BIT_VEC cppVar_17548;
	BIT_VEC cppVar_17549;
	BIT_VEC cppVar_17550;
	BIT_VEC cppVar_17551;
	BIT_VEC cppVar_17552;
	BIT_VEC cppVar_17553;
	BIT_VEC cppVar_17554;
	BIT_VEC cppVar_17555;
	BIT_VEC cppVar_17542;
	BIT_VEC cppVar_17556;
	bool cppVar_17557;
	BIT_VEC cppVar_17560;
	BIT_VEC cppVar_17561;
	BIT_VEC cppVar_17562;
	bool cppVar_17563;
	BIT_VEC cppVar_17564;
	BIT_VEC cppVar_17565;
	BIT_VEC cppVar_17566;
	BIT_VEC cppVar_17567;
	BIT_VEC cppVar_17568;
	BIT_VEC cppVar_17569;
	BIT_VEC cppVar_17570;
	BIT_VEC cppVar_17571;
	BIT_VEC cppVar_17572;
	BIT_VEC cppVar_17559;
	BIT_VEC cppVar_17573;
	bool cppVar_17574;
	BIT_VEC cppVar_17577;
	BIT_VEC cppVar_17578;
	BIT_VEC cppVar_17579;
	bool cppVar_17580;
	BIT_VEC cppVar_17581;
	BIT_VEC cppVar_17582;
	BIT_VEC cppVar_17583;
	BIT_VEC cppVar_17584;
	BIT_VEC cppVar_17585;
	BIT_VEC cppVar_17586;
	BIT_VEC cppVar_17587;
	BIT_VEC cppVar_17588;
	BIT_VEC cppVar_17589;
	BIT_VEC cppVar_17576;
	BIT_VEC cppVar_17590;
	bool cppVar_17591;
	BIT_VEC cppVar_17594;
	BIT_VEC cppVar_17595;
	BIT_VEC cppVar_17596;
	bool cppVar_17597;
	BIT_VEC cppVar_17598;
	BIT_VEC cppVar_17599;
	BIT_VEC cppVar_17600;
	BIT_VEC cppVar_17601;
	BIT_VEC cppVar_17602;
	BIT_VEC cppVar_17603;
	BIT_VEC cppVar_17604;
	BIT_VEC cppVar_17605;
	BIT_VEC cppVar_17606;
	BIT_VEC cppVar_17593;
	BIT_VEC cppVar_17607;
	bool cppVar_17608;
	BIT_VEC cppVar_17611;
	BIT_VEC cppVar_17612;
	BIT_VEC cppVar_17613;
	bool cppVar_17614;
	BIT_VEC cppVar_17615;
	BIT_VEC cppVar_17616;
	BIT_VEC cppVar_17617;
	BIT_VEC cppVar_17618;
	BIT_VEC cppVar_17619;
	BIT_VEC cppVar_17620;
	BIT_VEC cppVar_17621;
	BIT_VEC cppVar_17622;
	BIT_VEC cppVar_17623;
	BIT_VEC cppVar_17610;
	BIT_VEC cppVar_17624;
	bool cppVar_17625;
	BIT_VEC cppVar_17628;
	BIT_VEC cppVar_17629;
	BIT_VEC cppVar_17630;
	bool cppVar_17631;
	BIT_VEC cppVar_17632;
	BIT_VEC cppVar_17633;
	BIT_VEC cppVar_17634;
	BIT_VEC cppVar_17635;
	BIT_VEC cppVar_17636;
	BIT_VEC cppVar_17637;
	BIT_VEC cppVar_17638;
	BIT_VEC cppVar_17639;
	BIT_VEC cppVar_17640;
	BIT_VEC cppVar_17627;
	BIT_VEC cppVar_17641;
	bool cppVar_17642;
	BIT_VEC cppVar_17645;
	BIT_VEC cppVar_17646;
	BIT_VEC cppVar_17647;
	bool cppVar_17648;
	BIT_VEC cppVar_17649;
	BIT_VEC cppVar_17650;
	BIT_VEC cppVar_17651;
	BIT_VEC cppVar_17652;
	BIT_VEC cppVar_17653;
	BIT_VEC cppVar_17654;
	BIT_VEC cppVar_17655;
	BIT_VEC cppVar_17656;
	BIT_VEC cppVar_17657;
	BIT_VEC cppVar_17644;
	BIT_VEC cppVar_17658;
	bool cppVar_17659;
	BIT_VEC cppVar_17662;
	BIT_VEC cppVar_17663;
	BIT_VEC cppVar_17664;
	bool cppVar_17665;
	BIT_VEC cppVar_17666;
	BIT_VEC cppVar_17667;
	BIT_VEC cppVar_17668;
	BIT_VEC cppVar_17669;
	BIT_VEC cppVar_17670;
	BIT_VEC cppVar_17671;
	BIT_VEC cppVar_17672;
	BIT_VEC cppVar_17673;
	BIT_VEC cppVar_17674;
	BIT_VEC cppVar_17661;
	BIT_VEC cppVar_17675;
	bool cppVar_17676;
	BIT_VEC cppVar_17679;
	BIT_VEC cppVar_17680;
	BIT_VEC cppVar_17681;
	bool cppVar_17682;
	BIT_VEC cppVar_17683;
	BIT_VEC cppVar_17684;
	BIT_VEC cppVar_17685;
	BIT_VEC cppVar_17686;
	BIT_VEC cppVar_17687;
	BIT_VEC cppVar_17688;
	BIT_VEC cppVar_17689;
	BIT_VEC cppVar_17690;
	BIT_VEC cppVar_17691;
	BIT_VEC cppVar_17678;
	BIT_VEC cppVar_17692;
	bool cppVar_17693;
	BIT_VEC cppVar_17696;
	BIT_VEC cppVar_17697;
	BIT_VEC cppVar_17698;
	bool cppVar_17699;
	BIT_VEC cppVar_17700;
	BIT_VEC cppVar_17701;
	BIT_VEC cppVar_17702;
	BIT_VEC cppVar_17703;
	BIT_VEC cppVar_17704;
	BIT_VEC cppVar_17705;
	BIT_VEC cppVar_17706;
	BIT_VEC cppVar_17707;
	BIT_VEC cppVar_17708;
	BIT_VEC cppVar_17695;
	BIT_VEC cppVar_17709;
	bool cppVar_17710;
	BIT_VEC cppVar_17713;
	BIT_VEC cppVar_17714;
	BIT_VEC cppVar_17715;
	bool cppVar_17716;
	BIT_VEC cppVar_17717;
	BIT_VEC cppVar_17718;
	BIT_VEC cppVar_17719;
	BIT_VEC cppVar_17720;
	BIT_VEC cppVar_17721;
	BIT_VEC cppVar_17722;
	BIT_VEC cppVar_17723;
	BIT_VEC cppVar_17724;
	BIT_VEC cppVar_17725;
	BIT_VEC cppVar_17712;
	BIT_VEC cppVar_17726;
	bool cppVar_17727;
	BIT_VEC cppVar_17730;
	BIT_VEC cppVar_17731;
	BIT_VEC cppVar_17732;
	bool cppVar_17733;
	BIT_VEC cppVar_17734;
	BIT_VEC cppVar_17735;
	BIT_VEC cppVar_17736;
	BIT_VEC cppVar_17737;
	BIT_VEC cppVar_17738;
	BIT_VEC cppVar_17739;
	BIT_VEC cppVar_17740;
	BIT_VEC cppVar_17741;
	BIT_VEC cppVar_17742;
	BIT_VEC cppVar_17729;
	BIT_VEC cppVar_17743;
	bool cppVar_17744;
	BIT_VEC cppVar_17747;
	BIT_VEC cppVar_17748;
	BIT_VEC cppVar_17749;
	bool cppVar_17750;
	BIT_VEC cppVar_17751;
	BIT_VEC cppVar_17752;
	BIT_VEC cppVar_17753;
	BIT_VEC cppVar_17754;
	BIT_VEC cppVar_17755;
	BIT_VEC cppVar_17756;
	BIT_VEC cppVar_17757;
	BIT_VEC cppVar_17758;
	BIT_VEC cppVar_17759;
	BIT_VEC cppVar_17746;
	BIT_VEC cppVar_17760;
	bool cppVar_17761;
	BIT_VEC cppVar_17764;
	BIT_VEC cppVar_17765;
	BIT_VEC cppVar_17766;
	bool cppVar_17767;
	BIT_VEC cppVar_17768;
	BIT_VEC cppVar_17769;
	BIT_VEC cppVar_17770;
	BIT_VEC cppVar_17771;
	BIT_VEC cppVar_17772;
	BIT_VEC cppVar_17773;
	BIT_VEC cppVar_17774;
	BIT_VEC cppVar_17775;
	BIT_VEC cppVar_17776;
	BIT_VEC cppVar_17763;
	BIT_VEC cppVar_17777;
	bool cppVar_17778;
	BIT_VEC cppVar_17781;
	BIT_VEC cppVar_17782;
	BIT_VEC cppVar_17783;
	bool cppVar_17784;
	BIT_VEC cppVar_17785;
	BIT_VEC cppVar_17786;
	BIT_VEC cppVar_17787;
	BIT_VEC cppVar_17788;
	BIT_VEC cppVar_17789;
	BIT_VEC cppVar_17790;
	BIT_VEC cppVar_17791;
	BIT_VEC cppVar_17792;
	BIT_VEC cppVar_17793;
	BIT_VEC cppVar_17780;
	BIT_VEC cppVar_17794;
	bool cppVar_17795;
	BIT_VEC cppVar_17798;
	BIT_VEC cppVar_17799;
	BIT_VEC cppVar_17800;
	bool cppVar_17801;
	BIT_VEC cppVar_17802;
	BIT_VEC cppVar_17803;
	BIT_VEC cppVar_17804;
	BIT_VEC cppVar_17805;
	BIT_VEC cppVar_17806;
	BIT_VEC cppVar_17807;
	BIT_VEC cppVar_17808;
	BIT_VEC cppVar_17809;
	BIT_VEC cppVar_17810;
	BIT_VEC cppVar_17797;
	BIT_VEC cppVar_17811;
	bool cppVar_17812;
	BIT_VEC cppVar_17815;
	BIT_VEC cppVar_17816;
	BIT_VEC cppVar_17817;
	bool cppVar_17818;
	BIT_VEC cppVar_17819;
	BIT_VEC cppVar_17820;
	BIT_VEC cppVar_17821;
	BIT_VEC cppVar_17822;
	BIT_VEC cppVar_17823;
	BIT_VEC cppVar_17824;
	BIT_VEC cppVar_17825;
	BIT_VEC cppVar_17826;
	BIT_VEC cppVar_17827;
	BIT_VEC cppVar_17814;
	BIT_VEC cppVar_17828;
	bool cppVar_17829;
	BIT_VEC cppVar_17832;
	BIT_VEC cppVar_17833;
	BIT_VEC cppVar_17834;
	bool cppVar_17835;
	BIT_VEC cppVar_17836;
	BIT_VEC cppVar_17837;
	BIT_VEC cppVar_17838;
	BIT_VEC cppVar_17839;
	BIT_VEC cppVar_17840;
	BIT_VEC cppVar_17841;
	BIT_VEC cppVar_17842;
	BIT_VEC cppVar_17843;
	BIT_VEC cppVar_17844;
	BIT_VEC cppVar_17831;
	BIT_VEC cppVar_17845;
	bool cppVar_17846;
	BIT_VEC cppVar_17847;
	BIT_VEC cppVar_17830;
	BIT_VEC cppVar_17813;
	BIT_VEC cppVar_17796;
	BIT_VEC cppVar_17779;
	BIT_VEC cppVar_17762;
	BIT_VEC cppVar_17745;
	BIT_VEC cppVar_17728;
	BIT_VEC cppVar_17711;
	BIT_VEC cppVar_17694;
	BIT_VEC cppVar_17677;
	BIT_VEC cppVar_17660;
	BIT_VEC cppVar_17643;
	BIT_VEC cppVar_17626;
	BIT_VEC cppVar_17609;
	BIT_VEC cppVar_17592;
	BIT_VEC cppVar_17575;
	BIT_VEC cppVar_17558;
	BIT_VEC cppVar_17541;
	BIT_VEC cppVar_17524;
	BIT_VEC cppVar_17507;
	BIT_VEC cppVar_17490;
	BIT_VEC cppVar_17457;
	BIT_VEC cppVar_17848;
	BIT_VEC cppVar_17849;
	BIT_VEC cppVar_17850;
	BIT_VEC cppVar_17851;
	BIT_VEC cppVar_17852;
	BIT_VEC cppVar_17853;
	BIT_VEC cppVar_17854;
	BIT_VEC cppVar_17855;
	BIT_VEC cppVar_17856;
	BIT_VEC cppVar_17429;
	BIT_VEC cppVar_17858;
	BIT_VEC cppVar_17859;
	bool cppVar_17860;
	BIT_VEC cppVar_17862;
	BIT_VEC cppVar_17863;
	BIT_VEC cppVar_17864;
	BIT_VEC cppVar_17865;
	bool cppVar_17866;
	BIT_VEC cppVar_17868;
	BIT_VEC cppVar_17869;
	BIT_VEC cppVar_17870;
	BIT_VEC cppVar_17871;
	bool cppVar_17872;
	BIT_VEC cppVar_17873;
	BIT_VEC cppVar_17874;
	BIT_VEC cppVar_17875;
	BIT_VEC cppVar_17877;
	BIT_VEC cppVar_17878;
	BIT_VEC cppVar_17879;
	bool cppVar_17880;
	BIT_VEC cppVar_17882;
	BIT_VEC cppVar_17883;
	BIT_VEC cppVar_17884;
	bool cppVar_17885;
	BIT_VEC cppVar_17887;
	BIT_VEC cppVar_17888;
	BIT_VEC cppVar_17889;
	bool cppVar_17890;
	BIT_VEC cppVar_17892;
	BIT_VEC cppVar_17893;
	BIT_VEC cppVar_17894;
	bool cppVar_17895;
	BIT_VEC cppVar_17897;
	BIT_VEC cppVar_17898;
	BIT_VEC cppVar_17899;
	bool cppVar_17900;
	BIT_VEC cppVar_17902;
	BIT_VEC cppVar_17903;
	BIT_VEC cppVar_17904;
	bool cppVar_17905;
	BIT_VEC cppVar_17907;
	BIT_VEC cppVar_17908;
	BIT_VEC cppVar_17909;
	bool cppVar_17910;
	BIT_VEC cppVar_17912;
	BIT_VEC cppVar_17913;
	BIT_VEC cppVar_17914;
	bool cppVar_17915;
	BIT_VEC cppVar_17917;
	BIT_VEC cppVar_17918;
	BIT_VEC cppVar_17919;
	bool cppVar_17920;
	BIT_VEC cppVar_17922;
	BIT_VEC cppVar_17923;
	BIT_VEC cppVar_17924;
	bool cppVar_17925;
	BIT_VEC cppVar_17927;
	BIT_VEC cppVar_17928;
	BIT_VEC cppVar_17929;
	bool cppVar_17930;
	BIT_VEC cppVar_17932;
	BIT_VEC cppVar_17933;
	BIT_VEC cppVar_17934;
	bool cppVar_17935;
	BIT_VEC cppVar_17937;
	BIT_VEC cppVar_17938;
	BIT_VEC cppVar_17939;
	bool cppVar_17940;
	BIT_VEC cppVar_17942;
	BIT_VEC cppVar_17943;
	BIT_VEC cppVar_17944;
	bool cppVar_17945;
	BIT_VEC cppVar_17947;
	BIT_VEC cppVar_17948;
	BIT_VEC cppVar_17949;
	bool cppVar_17950;
	BIT_VEC cppVar_17952;
	BIT_VEC cppVar_17953;
	BIT_VEC cppVar_17954;
	bool cppVar_17955;
	BIT_VEC cppVar_17957;
	BIT_VEC cppVar_17958;
	BIT_VEC cppVar_17959;
	bool cppVar_17960;
	BIT_VEC cppVar_17962;
	BIT_VEC cppVar_17963;
	BIT_VEC cppVar_17964;
	bool cppVar_17965;
	BIT_VEC cppVar_17967;
	BIT_VEC cppVar_17968;
	BIT_VEC cppVar_17969;
	bool cppVar_17970;
	BIT_VEC cppVar_17972;
	BIT_VEC cppVar_17973;
	BIT_VEC cppVar_17974;
	bool cppVar_17975;
	BIT_VEC cppVar_17977;
	BIT_VEC cppVar_17978;
	BIT_VEC cppVar_17979;
	bool cppVar_17980;
	BIT_VEC cppVar_17981;
	BIT_VEC cppVar_17976;
	BIT_VEC cppVar_17971;
	BIT_VEC cppVar_17966;
	BIT_VEC cppVar_17961;
	BIT_VEC cppVar_17956;
	BIT_VEC cppVar_17951;
	BIT_VEC cppVar_17946;
	BIT_VEC cppVar_17941;
	BIT_VEC cppVar_17936;
	BIT_VEC cppVar_17931;
	BIT_VEC cppVar_17926;
	BIT_VEC cppVar_17921;
	BIT_VEC cppVar_17916;
	BIT_VEC cppVar_17911;
	BIT_VEC cppVar_17906;
	BIT_VEC cppVar_17901;
	BIT_VEC cppVar_17896;
	BIT_VEC cppVar_17891;
	BIT_VEC cppVar_17886;
	BIT_VEC cppVar_17881;
	BIT_VEC cppVar_17876;
	BIT_VEC cppVar_17867;
	BIT_VEC cppVar_17982;
	BIT_VEC cppVar_17983;
	BIT_VEC cppVar_17861;
	BIT_VEC cppVar_17857;
	BIT_VEC cppVar_17421;
	BIT_VEC cppVar_17290;
	BIT_VEC cppVar_17164;
	BIT_VEC cppVar_17035;
	BIT_VEC cppVar_16909;
	BIT_VEC cppVar_16780;
	BIT_VEC cppVar_16654;
	BIT_VEC cppVar_16525;
	BIT_VEC cppVar_16512;
	BIT_VEC cppVar_16386;
	BIT_VEC cppVar_16369;
	BIT_VEC cppVar_16352;
	BIT_VEC cppVar_16202;
	BIT_VEC cppVar_16052;
	BIT_VEC cppVar_15902;
	BIT_VEC cppVar_15752;
	BIT_VEC cppVar_15602;
	BIT_VEC cppVar_15452;
	BIT_VEC cppVar_15302;
	BIT_VEC cppVar_15152;
	BIT_VEC cppVar_14720;
	BIT_VEC cppVar_13890;
	BIT_VEC cppVar_13876;
	BIT_VEC cppVar_13865;
	BIT_VEC cppVar_13433;
	cppVar_13434 = ROM.rd(PC);
	cppVar_13436 = (cppVar_13434 == 210);
	if (cppVar_13436) {
	cppVar_13440 = PC + 1;
	cppVar_13440 = (cppVar_13440 & cppMask_un_16_);
	cppVar_13441 = ROM.rd(cppVar_13440);
	cppVar_13442 = (cppVar_13441 >> 7) & cppMask_un_1_;
	cppVar_13444 = (cppVar_13442 == 1);
	if (cppVar_13444) {
	cppVar_13445 = PC + 1;
	cppVar_13445 = (cppVar_13445 & cppMask_un_16_);
	cppVar_13446 = ROM.rd(cppVar_13445);
	cppVar_13447 = (cppVar_13446 >> 3) & cppMask_un_5_;
	cppVar_13449 = (cppVar_13447 << 3) | 0;
	cppVar_13449 = (cppVar_13449 & cppMask_un_8_);
	cppVar_13438 = cppVar_13449;
	} else {
	cppVar_13450 = PC + 1;
	cppVar_13450 = (cppVar_13450 & cppMask_un_16_);
	cppVar_13451 = ROM.rd(cppVar_13450);
	cppVar_13452 = (cppVar_13451 >> 3) & cppMask_un_5_;
	cppVar_13453 = (cppVar_13452 & cppMask_un_5_);
	cppVar_13455 = cppVar_13453 + 32;
	cppVar_13455 = (cppVar_13455 & cppMask_un_8_);
	cppVar_13438 = cppVar_13455;
	}
	cppVar_13457 = (cppVar_13438 == 168);
	if (cppVar_13457) {
	cppVar_13459 = PC + 1;
	cppVar_13459 = (cppVar_13459 & cppMask_un_16_);
	cppVar_13460 = ROM.rd(cppVar_13459);
	cppVar_13461 = (cppVar_13460 >> 0) & cppMask_un_3_;
	cppVar_13462 = (cppVar_13461 & cppMask_un_3_);
	cppVar_13463 = 1 << static_cast<unsigned>(cppVar_13462);
	cppVar_13463 = (cppVar_13463 & cppMask_un_8_);
	cppVar_13464 = ~cppVar_13463;
	cppVar_13467 = PC + 1;
	cppVar_13467 = (cppVar_13467 & cppMask_un_16_);
	cppVar_13468 = ROM.rd(cppVar_13467);
	cppVar_13469 = (cppVar_13468 >> 7) & cppMask_un_1_;
	cppVar_13470 = (cppVar_13469 == 1);
	if (cppVar_13470) {
	cppVar_13471 = PC + 1;
	cppVar_13471 = (cppVar_13471 & cppMask_un_16_);
	cppVar_13472 = ROM.rd(cppVar_13471);
	cppVar_13473 = (cppVar_13472 >> 3) & cppMask_un_5_;
	cppVar_13474 = (cppVar_13473 << 3) | 0;
	cppVar_13474 = (cppVar_13474 & cppMask_un_8_);
	cppVar_13466 = cppVar_13474;
	} else {
	cppVar_13475 = PC + 1;
	cppVar_13475 = (cppVar_13475 & cppMask_un_16_);
	cppVar_13476 = ROM.rd(cppVar_13475);
	cppVar_13477 = (cppVar_13476 >> 3) & cppMask_un_5_;
	cppVar_13478 = (cppVar_13477 & cppMask_un_5_);
	cppVar_13479 = cppVar_13478 + 32;
	cppVar_13479 = (cppVar_13479 & cppMask_un_8_);
	cppVar_13466 = cppVar_13479;
	}
	cppVar_13480 = (cppVar_13466 >> 7) & cppMask_un_1_;
	cppVar_13482 = (cppVar_13480 == 0);
	if (cppVar_13482) {
	cppVar_13484 = PC + 1;
	cppVar_13484 = (cppVar_13484 & cppMask_un_16_);
	cppVar_13485 = ROM.rd(cppVar_13484);
	cppVar_13486 = (cppVar_13485 >> 7) & cppMask_un_1_;
	cppVar_13487 = (cppVar_13486 == 1);
	if (cppVar_13487) {
	cppVar_13488 = PC + 1;
	cppVar_13488 = (cppVar_13488 & cppMask_un_16_);
	cppVar_13489 = ROM.rd(cppVar_13488);
	cppVar_13490 = (cppVar_13489 >> 3) & cppMask_un_5_;
	cppVar_13491 = (cppVar_13490 << 3) | 0;
	cppVar_13491 = (cppVar_13491 & cppMask_un_8_);
	cppVar_13483 = cppVar_13491;
	} else {
	cppVar_13492 = PC + 1;
	cppVar_13492 = (cppVar_13492 & cppMask_un_16_);
	cppVar_13493 = ROM.rd(cppVar_13492);
	cppVar_13494 = (cppVar_13493 >> 3) & cppMask_un_5_;
	cppVar_13495 = (cppVar_13494 & cppMask_un_5_);
	cppVar_13496 = cppVar_13495 + 32;
	cppVar_13496 = (cppVar_13496 & cppMask_un_8_);
	cppVar_13483 = cppVar_13496;
	}
	cppVar_13497 = IRAM.rd(cppVar_13483);
	cppVar_13465 = cppVar_13497;
	} else {
	cppVar_13500 = PC + 1;
	cppVar_13500 = (cppVar_13500 & cppMask_un_16_);
	cppVar_13501 = ROM.rd(cppVar_13500);
	cppVar_13502 = (cppVar_13501 >> 7) & cppMask_un_1_;
	cppVar_13503 = (cppVar_13502 == 1);
	if (cppVar_13503) {
	cppVar_13504 = PC + 1;
	cppVar_13504 = (cppVar_13504 & cppMask_un_16_);
	cppVar_13505 = ROM.rd(cppVar_13504);
	cppVar_13506 = (cppVar_13505 >> 3) & cppMask_un_5_;
	cppVar_13507 = (cppVar_13506 << 3) | 0;
	cppVar_13507 = (cppVar_13507 & cppMask_un_8_);
	cppVar_13499 = cppVar_13507;
	} else {
	cppVar_13508 = PC + 1;
	cppVar_13508 = (cppVar_13508 & cppMask_un_16_);
	cppVar_13509 = ROM.rd(cppVar_13508);
	cppVar_13510 = (cppVar_13509 >> 3) & cppMask_un_5_;
	cppVar_13511 = (cppVar_13510 & cppMask_un_5_);
	cppVar_13512 = cppVar_13511 + 32;
	cppVar_13512 = (cppVar_13512 & cppMask_un_8_);
	cppVar_13499 = cppVar_13512;
	}
	cppVar_13514 = (cppVar_13499 == 128);
	if (cppVar_13514) {
	cppVar_13498 = P0;
	} else {
	cppVar_13517 = PC + 1;
	cppVar_13517 = (cppVar_13517 & cppMask_un_16_);
	cppVar_13518 = ROM.rd(cppVar_13517);
	cppVar_13519 = (cppVar_13518 >> 7) & cppMask_un_1_;
	cppVar_13520 = (cppVar_13519 == 1);
	if (cppVar_13520) {
	cppVar_13521 = PC + 1;
	cppVar_13521 = (cppVar_13521 & cppMask_un_16_);
	cppVar_13522 = ROM.rd(cppVar_13521);
	cppVar_13523 = (cppVar_13522 >> 3) & cppMask_un_5_;
	cppVar_13524 = (cppVar_13523 << 3) | 0;
	cppVar_13524 = (cppVar_13524 & cppMask_un_8_);
	cppVar_13516 = cppVar_13524;
	} else {
	cppVar_13525 = PC + 1;
	cppVar_13525 = (cppVar_13525 & cppMask_un_16_);
	cppVar_13526 = ROM.rd(cppVar_13525);
	cppVar_13527 = (cppVar_13526 >> 3) & cppMask_un_5_;
	cppVar_13528 = (cppVar_13527 & cppMask_un_5_);
	cppVar_13529 = cppVar_13528 + 32;
	cppVar_13529 = (cppVar_13529 & cppMask_un_8_);
	cppVar_13516 = cppVar_13529;
	}
	cppVar_13531 = (cppVar_13516 == 129);
	if (cppVar_13531) {
	cppVar_13515 = SP;
	} else {
	cppVar_13534 = PC + 1;
	cppVar_13534 = (cppVar_13534 & cppMask_un_16_);
	cppVar_13535 = ROM.rd(cppVar_13534);
	cppVar_13536 = (cppVar_13535 >> 7) & cppMask_un_1_;
	cppVar_13537 = (cppVar_13536 == 1);
	if (cppVar_13537) {
	cppVar_13538 = PC + 1;
	cppVar_13538 = (cppVar_13538 & cppMask_un_16_);
	cppVar_13539 = ROM.rd(cppVar_13538);
	cppVar_13540 = (cppVar_13539 >> 3) & cppMask_un_5_;
	cppVar_13541 = (cppVar_13540 << 3) | 0;
	cppVar_13541 = (cppVar_13541 & cppMask_un_8_);
	cppVar_13533 = cppVar_13541;
	} else {
	cppVar_13542 = PC + 1;
	cppVar_13542 = (cppVar_13542 & cppMask_un_16_);
	cppVar_13543 = ROM.rd(cppVar_13542);
	cppVar_13544 = (cppVar_13543 >> 3) & cppMask_un_5_;
	cppVar_13545 = (cppVar_13544 & cppMask_un_5_);
	cppVar_13546 = cppVar_13545 + 32;
	cppVar_13546 = (cppVar_13546 & cppMask_un_8_);
	cppVar_13533 = cppVar_13546;
	}
	cppVar_13548 = (cppVar_13533 == 130);
	if (cppVar_13548) {
	cppVar_13532 = DPL;
	} else {
	cppVar_13551 = PC + 1;
	cppVar_13551 = (cppVar_13551 & cppMask_un_16_);
	cppVar_13552 = ROM.rd(cppVar_13551);
	cppVar_13553 = (cppVar_13552 >> 7) & cppMask_un_1_;
	cppVar_13554 = (cppVar_13553 == 1);
	if (cppVar_13554) {
	cppVar_13555 = PC + 1;
	cppVar_13555 = (cppVar_13555 & cppMask_un_16_);
	cppVar_13556 = ROM.rd(cppVar_13555);
	cppVar_13557 = (cppVar_13556 >> 3) & cppMask_un_5_;
	cppVar_13558 = (cppVar_13557 << 3) | 0;
	cppVar_13558 = (cppVar_13558 & cppMask_un_8_);
	cppVar_13550 = cppVar_13558;
	} else {
	cppVar_13559 = PC + 1;
	cppVar_13559 = (cppVar_13559 & cppMask_un_16_);
	cppVar_13560 = ROM.rd(cppVar_13559);
	cppVar_13561 = (cppVar_13560 >> 3) & cppMask_un_5_;
	cppVar_13562 = (cppVar_13561 & cppMask_un_5_);
	cppVar_13563 = cppVar_13562 + 32;
	cppVar_13563 = (cppVar_13563 & cppMask_un_8_);
	cppVar_13550 = cppVar_13563;
	}
	cppVar_13565 = (cppVar_13550 == 131);
	if (cppVar_13565) {
	cppVar_13549 = DPH;
	} else {
	cppVar_13568 = PC + 1;
	cppVar_13568 = (cppVar_13568 & cppMask_un_16_);
	cppVar_13569 = ROM.rd(cppVar_13568);
	cppVar_13570 = (cppVar_13569 >> 7) & cppMask_un_1_;
	cppVar_13571 = (cppVar_13570 == 1);
	if (cppVar_13571) {
	cppVar_13572 = PC + 1;
	cppVar_13572 = (cppVar_13572 & cppMask_un_16_);
	cppVar_13573 = ROM.rd(cppVar_13572);
	cppVar_13574 = (cppVar_13573 >> 3) & cppMask_un_5_;
	cppVar_13575 = (cppVar_13574 << 3) | 0;
	cppVar_13575 = (cppVar_13575 & cppMask_un_8_);
	cppVar_13567 = cppVar_13575;
	} else {
	cppVar_13576 = PC + 1;
	cppVar_13576 = (cppVar_13576 & cppMask_un_16_);
	cppVar_13577 = ROM.rd(cppVar_13576);
	cppVar_13578 = (cppVar_13577 >> 3) & cppMask_un_5_;
	cppVar_13579 = (cppVar_13578 & cppMask_un_5_);
	cppVar_13580 = cppVar_13579 + 32;
	cppVar_13580 = (cppVar_13580 & cppMask_un_8_);
	cppVar_13567 = cppVar_13580;
	}
	cppVar_13582 = (cppVar_13567 == 135);
	if (cppVar_13582) {
	cppVar_13566 = PCON;
	} else {
	cppVar_13585 = PC + 1;
	cppVar_13585 = (cppVar_13585 & cppMask_un_16_);
	cppVar_13586 = ROM.rd(cppVar_13585);
	cppVar_13587 = (cppVar_13586 >> 7) & cppMask_un_1_;
	cppVar_13588 = (cppVar_13587 == 1);
	if (cppVar_13588) {
	cppVar_13589 = PC + 1;
	cppVar_13589 = (cppVar_13589 & cppMask_un_16_);
	cppVar_13590 = ROM.rd(cppVar_13589);
	cppVar_13591 = (cppVar_13590 >> 3) & cppMask_un_5_;
	cppVar_13592 = (cppVar_13591 << 3) | 0;
	cppVar_13592 = (cppVar_13592 & cppMask_un_8_);
	cppVar_13584 = cppVar_13592;
	} else {
	cppVar_13593 = PC + 1;
	cppVar_13593 = (cppVar_13593 & cppMask_un_16_);
	cppVar_13594 = ROM.rd(cppVar_13593);
	cppVar_13595 = (cppVar_13594 >> 3) & cppMask_un_5_;
	cppVar_13596 = (cppVar_13595 & cppMask_un_5_);
	cppVar_13597 = cppVar_13596 + 32;
	cppVar_13597 = (cppVar_13597 & cppMask_un_8_);
	cppVar_13584 = cppVar_13597;
	}
	cppVar_13599 = (cppVar_13584 == 136);
	if (cppVar_13599) {
	cppVar_13583 = TCON;
	} else {
	cppVar_13602 = PC + 1;
	cppVar_13602 = (cppVar_13602 & cppMask_un_16_);
	cppVar_13603 = ROM.rd(cppVar_13602);
	cppVar_13604 = (cppVar_13603 >> 7) & cppMask_un_1_;
	cppVar_13605 = (cppVar_13604 == 1);
	if (cppVar_13605) {
	cppVar_13606 = PC + 1;
	cppVar_13606 = (cppVar_13606 & cppMask_un_16_);
	cppVar_13607 = ROM.rd(cppVar_13606);
	cppVar_13608 = (cppVar_13607 >> 3) & cppMask_un_5_;
	cppVar_13609 = (cppVar_13608 << 3) | 0;
	cppVar_13609 = (cppVar_13609 & cppMask_un_8_);
	cppVar_13601 = cppVar_13609;
	} else {
	cppVar_13610 = PC + 1;
	cppVar_13610 = (cppVar_13610 & cppMask_un_16_);
	cppVar_13611 = ROM.rd(cppVar_13610);
	cppVar_13612 = (cppVar_13611 >> 3) & cppMask_un_5_;
	cppVar_13613 = (cppVar_13612 & cppMask_un_5_);
	cppVar_13614 = cppVar_13613 + 32;
	cppVar_13614 = (cppVar_13614 & cppMask_un_8_);
	cppVar_13601 = cppVar_13614;
	}
	cppVar_13616 = (cppVar_13601 == 137);
	if (cppVar_13616) {
	cppVar_13600 = TMOD;
	} else {
	cppVar_13619 = PC + 1;
	cppVar_13619 = (cppVar_13619 & cppMask_un_16_);
	cppVar_13620 = ROM.rd(cppVar_13619);
	cppVar_13621 = (cppVar_13620 >> 7) & cppMask_un_1_;
	cppVar_13622 = (cppVar_13621 == 1);
	if (cppVar_13622) {
	cppVar_13623 = PC + 1;
	cppVar_13623 = (cppVar_13623 & cppMask_un_16_);
	cppVar_13624 = ROM.rd(cppVar_13623);
	cppVar_13625 = (cppVar_13624 >> 3) & cppMask_un_5_;
	cppVar_13626 = (cppVar_13625 << 3) | 0;
	cppVar_13626 = (cppVar_13626 & cppMask_un_8_);
	cppVar_13618 = cppVar_13626;
	} else {
	cppVar_13627 = PC + 1;
	cppVar_13627 = (cppVar_13627 & cppMask_un_16_);
	cppVar_13628 = ROM.rd(cppVar_13627);
	cppVar_13629 = (cppVar_13628 >> 3) & cppMask_un_5_;
	cppVar_13630 = (cppVar_13629 & cppMask_un_5_);
	cppVar_13631 = cppVar_13630 + 32;
	cppVar_13631 = (cppVar_13631 & cppMask_un_8_);
	cppVar_13618 = cppVar_13631;
	}
	cppVar_13633 = (cppVar_13618 == 138);
	if (cppVar_13633) {
	cppVar_13617 = TL0;
	} else {
	cppVar_13636 = PC + 1;
	cppVar_13636 = (cppVar_13636 & cppMask_un_16_);
	cppVar_13637 = ROM.rd(cppVar_13636);
	cppVar_13638 = (cppVar_13637 >> 7) & cppMask_un_1_;
	cppVar_13639 = (cppVar_13638 == 1);
	if (cppVar_13639) {
	cppVar_13640 = PC + 1;
	cppVar_13640 = (cppVar_13640 & cppMask_un_16_);
	cppVar_13641 = ROM.rd(cppVar_13640);
	cppVar_13642 = (cppVar_13641 >> 3) & cppMask_un_5_;
	cppVar_13643 = (cppVar_13642 << 3) | 0;
	cppVar_13643 = (cppVar_13643 & cppMask_un_8_);
	cppVar_13635 = cppVar_13643;
	} else {
	cppVar_13644 = PC + 1;
	cppVar_13644 = (cppVar_13644 & cppMask_un_16_);
	cppVar_13645 = ROM.rd(cppVar_13644);
	cppVar_13646 = (cppVar_13645 >> 3) & cppMask_un_5_;
	cppVar_13647 = (cppVar_13646 & cppMask_un_5_);
	cppVar_13648 = cppVar_13647 + 32;
	cppVar_13648 = (cppVar_13648 & cppMask_un_8_);
	cppVar_13635 = cppVar_13648;
	}
	cppVar_13650 = (cppVar_13635 == 140);
	if (cppVar_13650) {
	cppVar_13634 = TH0;
	} else {
	cppVar_13653 = PC + 1;
	cppVar_13653 = (cppVar_13653 & cppMask_un_16_);
	cppVar_13654 = ROM.rd(cppVar_13653);
	cppVar_13655 = (cppVar_13654 >> 7) & cppMask_un_1_;
	cppVar_13656 = (cppVar_13655 == 1);
	if (cppVar_13656) {
	cppVar_13657 = PC + 1;
	cppVar_13657 = (cppVar_13657 & cppMask_un_16_);
	cppVar_13658 = ROM.rd(cppVar_13657);
	cppVar_13659 = (cppVar_13658 >> 3) & cppMask_un_5_;
	cppVar_13660 = (cppVar_13659 << 3) | 0;
	cppVar_13660 = (cppVar_13660 & cppMask_un_8_);
	cppVar_13652 = cppVar_13660;
	} else {
	cppVar_13661 = PC + 1;
	cppVar_13661 = (cppVar_13661 & cppMask_un_16_);
	cppVar_13662 = ROM.rd(cppVar_13661);
	cppVar_13663 = (cppVar_13662 >> 3) & cppMask_un_5_;
	cppVar_13664 = (cppVar_13663 & cppMask_un_5_);
	cppVar_13665 = cppVar_13664 + 32;
	cppVar_13665 = (cppVar_13665 & cppMask_un_8_);
	cppVar_13652 = cppVar_13665;
	}
	cppVar_13667 = (cppVar_13652 == 139);
	if (cppVar_13667) {
	cppVar_13651 = TL1;
	} else {
	cppVar_13670 = PC + 1;
	cppVar_13670 = (cppVar_13670 & cppMask_un_16_);
	cppVar_13671 = ROM.rd(cppVar_13670);
	cppVar_13672 = (cppVar_13671 >> 7) & cppMask_un_1_;
	cppVar_13673 = (cppVar_13672 == 1);
	if (cppVar_13673) {
	cppVar_13674 = PC + 1;
	cppVar_13674 = (cppVar_13674 & cppMask_un_16_);
	cppVar_13675 = ROM.rd(cppVar_13674);
	cppVar_13676 = (cppVar_13675 >> 3) & cppMask_un_5_;
	cppVar_13677 = (cppVar_13676 << 3) | 0;
	cppVar_13677 = (cppVar_13677 & cppMask_un_8_);
	cppVar_13669 = cppVar_13677;
	} else {
	cppVar_13678 = PC + 1;
	cppVar_13678 = (cppVar_13678 & cppMask_un_16_);
	cppVar_13679 = ROM.rd(cppVar_13678);
	cppVar_13680 = (cppVar_13679 >> 3) & cppMask_un_5_;
	cppVar_13681 = (cppVar_13680 & cppMask_un_5_);
	cppVar_13682 = cppVar_13681 + 32;
	cppVar_13682 = (cppVar_13682 & cppMask_un_8_);
	cppVar_13669 = cppVar_13682;
	}
	cppVar_13684 = (cppVar_13669 == 141);
	if (cppVar_13684) {
	cppVar_13668 = TH1;
	} else {
	cppVar_13687 = PC + 1;
	cppVar_13687 = (cppVar_13687 & cppMask_un_16_);
	cppVar_13688 = ROM.rd(cppVar_13687);
	cppVar_13689 = (cppVar_13688 >> 7) & cppMask_un_1_;
	cppVar_13690 = (cppVar_13689 == 1);
	if (cppVar_13690) {
	cppVar_13691 = PC + 1;
	cppVar_13691 = (cppVar_13691 & cppMask_un_16_);
	cppVar_13692 = ROM.rd(cppVar_13691);
	cppVar_13693 = (cppVar_13692 >> 3) & cppMask_un_5_;
	cppVar_13694 = (cppVar_13693 << 3) | 0;
	cppVar_13694 = (cppVar_13694 & cppMask_un_8_);
	cppVar_13686 = cppVar_13694;
	} else {
	cppVar_13695 = PC + 1;
	cppVar_13695 = (cppVar_13695 & cppMask_un_16_);
	cppVar_13696 = ROM.rd(cppVar_13695);
	cppVar_13697 = (cppVar_13696 >> 3) & cppMask_un_5_;
	cppVar_13698 = (cppVar_13697 & cppMask_un_5_);
	cppVar_13699 = cppVar_13698 + 32;
	cppVar_13699 = (cppVar_13699 & cppMask_un_8_);
	cppVar_13686 = cppVar_13699;
	}
	cppVar_13701 = (cppVar_13686 == 144);
	if (cppVar_13701) {
	cppVar_13685 = P1;
	} else {
	cppVar_13704 = PC + 1;
	cppVar_13704 = (cppVar_13704 & cppMask_un_16_);
	cppVar_13705 = ROM.rd(cppVar_13704);
	cppVar_13706 = (cppVar_13705 >> 7) & cppMask_un_1_;
	cppVar_13707 = (cppVar_13706 == 1);
	if (cppVar_13707) {
	cppVar_13708 = PC + 1;
	cppVar_13708 = (cppVar_13708 & cppMask_un_16_);
	cppVar_13709 = ROM.rd(cppVar_13708);
	cppVar_13710 = (cppVar_13709 >> 3) & cppMask_un_5_;
	cppVar_13711 = (cppVar_13710 << 3) | 0;
	cppVar_13711 = (cppVar_13711 & cppMask_un_8_);
	cppVar_13703 = cppVar_13711;
	} else {
	cppVar_13712 = PC + 1;
	cppVar_13712 = (cppVar_13712 & cppMask_un_16_);
	cppVar_13713 = ROM.rd(cppVar_13712);
	cppVar_13714 = (cppVar_13713 >> 3) & cppMask_un_5_;
	cppVar_13715 = (cppVar_13714 & cppMask_un_5_);
	cppVar_13716 = cppVar_13715 + 32;
	cppVar_13716 = (cppVar_13716 & cppMask_un_8_);
	cppVar_13703 = cppVar_13716;
	}
	cppVar_13718 = (cppVar_13703 == 152);
	if (cppVar_13718) {
	cppVar_13702 = SCON;
	} else {
	cppVar_13721 = PC + 1;
	cppVar_13721 = (cppVar_13721 & cppMask_un_16_);
	cppVar_13722 = ROM.rd(cppVar_13721);
	cppVar_13723 = (cppVar_13722 >> 7) & cppMask_un_1_;
	cppVar_13724 = (cppVar_13723 == 1);
	if (cppVar_13724) {
	cppVar_13725 = PC + 1;
	cppVar_13725 = (cppVar_13725 & cppMask_un_16_);
	cppVar_13726 = ROM.rd(cppVar_13725);
	cppVar_13727 = (cppVar_13726 >> 3) & cppMask_un_5_;
	cppVar_13728 = (cppVar_13727 << 3) | 0;
	cppVar_13728 = (cppVar_13728 & cppMask_un_8_);
	cppVar_13720 = cppVar_13728;
	} else {
	cppVar_13729 = PC + 1;
	cppVar_13729 = (cppVar_13729 & cppMask_un_16_);
	cppVar_13730 = ROM.rd(cppVar_13729);
	cppVar_13731 = (cppVar_13730 >> 3) & cppMask_un_5_;
	cppVar_13732 = (cppVar_13731 & cppMask_un_5_);
	cppVar_13733 = cppVar_13732 + 32;
	cppVar_13733 = (cppVar_13733 & cppMask_un_8_);
	cppVar_13720 = cppVar_13733;
	}
	cppVar_13735 = (cppVar_13720 == 153);
	if (cppVar_13735) {
	cppVar_13719 = SBUF;
	} else {
	cppVar_13738 = PC + 1;
	cppVar_13738 = (cppVar_13738 & cppMask_un_16_);
	cppVar_13739 = ROM.rd(cppVar_13738);
	cppVar_13740 = (cppVar_13739 >> 7) & cppMask_un_1_;
	cppVar_13741 = (cppVar_13740 == 1);
	if (cppVar_13741) {
	cppVar_13742 = PC + 1;
	cppVar_13742 = (cppVar_13742 & cppMask_un_16_);
	cppVar_13743 = ROM.rd(cppVar_13742);
	cppVar_13744 = (cppVar_13743 >> 3) & cppMask_un_5_;
	cppVar_13745 = (cppVar_13744 << 3) | 0;
	cppVar_13745 = (cppVar_13745 & cppMask_un_8_);
	cppVar_13737 = cppVar_13745;
	} else {
	cppVar_13746 = PC + 1;
	cppVar_13746 = (cppVar_13746 & cppMask_un_16_);
	cppVar_13747 = ROM.rd(cppVar_13746);
	cppVar_13748 = (cppVar_13747 >> 3) & cppMask_un_5_;
	cppVar_13749 = (cppVar_13748 & cppMask_un_5_);
	cppVar_13750 = cppVar_13749 + 32;
	cppVar_13750 = (cppVar_13750 & cppMask_un_8_);
	cppVar_13737 = cppVar_13750;
	}
	cppVar_13752 = (cppVar_13737 == 160);
	if (cppVar_13752) {
	cppVar_13736 = P2;
	} else {
	cppVar_13755 = PC + 1;
	cppVar_13755 = (cppVar_13755 & cppMask_un_16_);
	cppVar_13756 = ROM.rd(cppVar_13755);
	cppVar_13757 = (cppVar_13756 >> 7) & cppMask_un_1_;
	cppVar_13758 = (cppVar_13757 == 1);
	if (cppVar_13758) {
	cppVar_13759 = PC + 1;
	cppVar_13759 = (cppVar_13759 & cppMask_un_16_);
	cppVar_13760 = ROM.rd(cppVar_13759);
	cppVar_13761 = (cppVar_13760 >> 3) & cppMask_un_5_;
	cppVar_13762 = (cppVar_13761 << 3) | 0;
	cppVar_13762 = (cppVar_13762 & cppMask_un_8_);
	cppVar_13754 = cppVar_13762;
	} else {
	cppVar_13763 = PC + 1;
	cppVar_13763 = (cppVar_13763 & cppMask_un_16_);
	cppVar_13764 = ROM.rd(cppVar_13763);
	cppVar_13765 = (cppVar_13764 >> 3) & cppMask_un_5_;
	cppVar_13766 = (cppVar_13765 & cppMask_un_5_);
	cppVar_13767 = cppVar_13766 + 32;
	cppVar_13767 = (cppVar_13767 & cppMask_un_8_);
	cppVar_13754 = cppVar_13767;
	}
	cppVar_13769 = (cppVar_13754 == 168);
	if (cppVar_13769) {
	cppVar_13753 = IE;
	} else {
	cppVar_13772 = PC + 1;
	cppVar_13772 = (cppVar_13772 & cppMask_un_16_);
	cppVar_13773 = ROM.rd(cppVar_13772);
	cppVar_13774 = (cppVar_13773 >> 7) & cppMask_un_1_;
	cppVar_13775 = (cppVar_13774 == 1);
	if (cppVar_13775) {
	cppVar_13776 = PC + 1;
	cppVar_13776 = (cppVar_13776 & cppMask_un_16_);
	cppVar_13777 = ROM.rd(cppVar_13776);
	cppVar_13778 = (cppVar_13777 >> 3) & cppMask_un_5_;
	cppVar_13779 = (cppVar_13778 << 3) | 0;
	cppVar_13779 = (cppVar_13779 & cppMask_un_8_);
	cppVar_13771 = cppVar_13779;
	} else {
	cppVar_13780 = PC + 1;
	cppVar_13780 = (cppVar_13780 & cppMask_un_16_);
	cppVar_13781 = ROM.rd(cppVar_13780);
	cppVar_13782 = (cppVar_13781 >> 3) & cppMask_un_5_;
	cppVar_13783 = (cppVar_13782 & cppMask_un_5_);
	cppVar_13784 = cppVar_13783 + 32;
	cppVar_13784 = (cppVar_13784 & cppMask_un_8_);
	cppVar_13771 = cppVar_13784;
	}
	cppVar_13786 = (cppVar_13771 == 176);
	if (cppVar_13786) {
	cppVar_13770 = P3;
	} else {
	cppVar_13789 = PC + 1;
	cppVar_13789 = (cppVar_13789 & cppMask_un_16_);
	cppVar_13790 = ROM.rd(cppVar_13789);
	cppVar_13791 = (cppVar_13790 >> 7) & cppMask_un_1_;
	cppVar_13792 = (cppVar_13791 == 1);
	if (cppVar_13792) {
	cppVar_13793 = PC + 1;
	cppVar_13793 = (cppVar_13793 & cppMask_un_16_);
	cppVar_13794 = ROM.rd(cppVar_13793);
	cppVar_13795 = (cppVar_13794 >> 3) & cppMask_un_5_;
	cppVar_13796 = (cppVar_13795 << 3) | 0;
	cppVar_13796 = (cppVar_13796 & cppMask_un_8_);
	cppVar_13788 = cppVar_13796;
	} else {
	cppVar_13797 = PC + 1;
	cppVar_13797 = (cppVar_13797 & cppMask_un_16_);
	cppVar_13798 = ROM.rd(cppVar_13797);
	cppVar_13799 = (cppVar_13798 >> 3) & cppMask_un_5_;
	cppVar_13800 = (cppVar_13799 & cppMask_un_5_);
	cppVar_13801 = cppVar_13800 + 32;
	cppVar_13801 = (cppVar_13801 & cppMask_un_8_);
	cppVar_13788 = cppVar_13801;
	}
	cppVar_13803 = (cppVar_13788 == 184);
	if (cppVar_13803) {
	cppVar_13787 = IP;
	} else {
	cppVar_13806 = PC + 1;
	cppVar_13806 = (cppVar_13806 & cppMask_un_16_);
	cppVar_13807 = ROM.rd(cppVar_13806);
	cppVar_13808 = (cppVar_13807 >> 7) & cppMask_un_1_;
	cppVar_13809 = (cppVar_13808 == 1);
	if (cppVar_13809) {
	cppVar_13810 = PC + 1;
	cppVar_13810 = (cppVar_13810 & cppMask_un_16_);
	cppVar_13811 = ROM.rd(cppVar_13810);
	cppVar_13812 = (cppVar_13811 >> 3) & cppMask_un_5_;
	cppVar_13813 = (cppVar_13812 << 3) | 0;
	cppVar_13813 = (cppVar_13813 & cppMask_un_8_);
	cppVar_13805 = cppVar_13813;
	} else {
	cppVar_13814 = PC + 1;
	cppVar_13814 = (cppVar_13814 & cppMask_un_16_);
	cppVar_13815 = ROM.rd(cppVar_13814);
	cppVar_13816 = (cppVar_13815 >> 3) & cppMask_un_5_;
	cppVar_13817 = (cppVar_13816 & cppMask_un_5_);
	cppVar_13818 = cppVar_13817 + 32;
	cppVar_13818 = (cppVar_13818 & cppMask_un_8_);
	cppVar_13805 = cppVar_13818;
	}
	cppVar_13820 = (cppVar_13805 == 208);
	if (cppVar_13820) {
	cppVar_13804 = PSW;
	} else {
	cppVar_13823 = PC + 1;
	cppVar_13823 = (cppVar_13823 & cppMask_un_16_);
	cppVar_13824 = ROM.rd(cppVar_13823);
	cppVar_13825 = (cppVar_13824 >> 7) & cppMask_un_1_;
	cppVar_13826 = (cppVar_13825 == 1);
	if (cppVar_13826) {
	cppVar_13827 = PC + 1;
	cppVar_13827 = (cppVar_13827 & cppMask_un_16_);
	cppVar_13828 = ROM.rd(cppVar_13827);
	cppVar_13829 = (cppVar_13828 >> 3) & cppMask_un_5_;
	cppVar_13830 = (cppVar_13829 << 3) | 0;
	cppVar_13830 = (cppVar_13830 & cppMask_un_8_);
	cppVar_13822 = cppVar_13830;
	} else {
	cppVar_13831 = PC + 1;
	cppVar_13831 = (cppVar_13831 & cppMask_un_16_);
	cppVar_13832 = ROM.rd(cppVar_13831);
	cppVar_13833 = (cppVar_13832 >> 3) & cppMask_un_5_;
	cppVar_13834 = (cppVar_13833 & cppMask_un_5_);
	cppVar_13835 = cppVar_13834 + 32;
	cppVar_13835 = (cppVar_13835 & cppMask_un_8_);
	cppVar_13822 = cppVar_13835;
	}
	cppVar_13837 = (cppVar_13822 == 224);
	if (cppVar_13837) {
	cppVar_13821 = ACC;
	} else {
	cppVar_13840 = PC + 1;
	cppVar_13840 = (cppVar_13840 & cppMask_un_16_);
	cppVar_13841 = ROM.rd(cppVar_13840);
	cppVar_13842 = (cppVar_13841 >> 7) & cppMask_un_1_;
	cppVar_13843 = (cppVar_13842 == 1);
	if (cppVar_13843) {
	cppVar_13844 = PC + 1;
	cppVar_13844 = (cppVar_13844 & cppMask_un_16_);
	cppVar_13845 = ROM.rd(cppVar_13844);
	cppVar_13846 = (cppVar_13845 >> 3) & cppMask_un_5_;
	cppVar_13847 = (cppVar_13846 << 3) | 0;
	cppVar_13847 = (cppVar_13847 & cppMask_un_8_);
	cppVar_13839 = cppVar_13847;
	} else {
	cppVar_13848 = PC + 1;
	cppVar_13848 = (cppVar_13848 & cppMask_un_16_);
	cppVar_13849 = ROM.rd(cppVar_13848);
	cppVar_13850 = (cppVar_13849 >> 3) & cppMask_un_5_;
	cppVar_13851 = (cppVar_13850 & cppMask_un_5_);
	cppVar_13852 = cppVar_13851 + 32;
	cppVar_13852 = (cppVar_13852 & cppMask_un_8_);
	cppVar_13839 = cppVar_13852;
	}
	cppVar_13854 = (cppVar_13839 == 240);
	if (cppVar_13854) {
	cppVar_13838 = B;
	} else {
	cppVar_13838 = 0;
	}
	cppVar_13821 = cppVar_13838;
	}
	cppVar_13804 = cppVar_13821;
	}
	cppVar_13787 = cppVar_13804;
	}
	cppVar_13770 = cppVar_13787;
	}
	cppVar_13753 = cppVar_13770;
	}
	cppVar_13736 = cppVar_13753;
	}
	cppVar_13719 = cppVar_13736;
	}
	cppVar_13702 = cppVar_13719;
	}
	cppVar_13685 = cppVar_13702;
	}
	cppVar_13668 = cppVar_13685;
	}
	cppVar_13651 = cppVar_13668;
	}
	cppVar_13634 = cppVar_13651;
	}
	cppVar_13617 = cppVar_13634;
	}
	cppVar_13600 = cppVar_13617;
	}
	cppVar_13583 = cppVar_13600;
	}
	cppVar_13566 = cppVar_13583;
	}
	cppVar_13549 = cppVar_13566;
	}
	cppVar_13532 = cppVar_13549;
	}
	cppVar_13515 = cppVar_13532;
	}
	cppVar_13498 = cppVar_13515;
	}
	cppVar_13465 = cppVar_13498;
	}
	cppVar_13856 = cppVar_13464 & cppVar_13465;
	cppVar_13858 = 1;
	cppVar_13859 = PC + 1;
	cppVar_13859 = (cppVar_13859 & cppMask_un_16_);
	cppVar_13860 = ROM.rd(cppVar_13859);
	cppVar_13861 = (cppVar_13860 >> 0) & cppMask_un_3_;
	cppVar_13862 = (cppVar_13861 & cppMask_un_3_);
	cppVar_13863 = cppVar_13858 << static_cast<unsigned>(cppVar_13862);
	cppVar_13863 = (cppVar_13863 & cppMask_un_8_);
	cppVar_13864 = cppVar_13856 | cppVar_13863;
	cppVar_13437 = cppVar_13864;
	} else {
	cppVar_13437 = IE;
	}
	cppVar_13433 = cppVar_13437;
	} else {
	cppVar_13866 = ROM.rd(PC);
	cppVar_13868 = (cppVar_13866 == 208);
	if (cppVar_13868) {
	cppVar_13871 = PC + 1;
	cppVar_13871 = (cppVar_13871 & cppMask_un_16_);
	cppVar_13872 = ROM.rd(cppVar_13871);
	cppVar_13874 = (cppVar_13872 == 168);
	if (cppVar_13874) {
	cppVar_13875 = IRAM.rd(SP);
	cppVar_13869 = cppVar_13875;
	} else {
	cppVar_13869 = IE;
	}
	cppVar_13865 = cppVar_13869;
	} else {
	cppVar_13877 = ROM.rd(PC);
	cppVar_13879 = (cppVar_13877 == 245);
	cppVar_13880 = ROM.rd(PC);
	cppVar_13882 = (cppVar_13880 == 197);
	cppVar_13883 = cppVar_13879 || cppVar_13882;
	if (cppVar_13883) {
	cppVar_13886 = PC + 1;
	cppVar_13886 = (cppVar_13886 & cppMask_un_16_);
	cppVar_13887 = ROM.rd(cppVar_13886);
	cppVar_13889 = (cppVar_13887 == 168);
	if (cppVar_13889) {
	cppVar_13884 = ACC;
	} else {
	cppVar_13884 = IE;
	}
	cppVar_13876 = cppVar_13884;
	} else {
	cppVar_13891 = ROM.rd(PC);
	cppVar_13893 = (cppVar_13891 == 178);
	if (cppVar_13893) {
	cppVar_13897 = PC + 1;
	cppVar_13897 = (cppVar_13897 & cppMask_un_16_);
	cppVar_13898 = ROM.rd(cppVar_13897);
	cppVar_13899 = (cppVar_13898 >> 7) & cppMask_un_1_;
	cppVar_13901 = (cppVar_13899 == 1);
	if (cppVar_13901) {
	cppVar_13902 = PC + 1;
	cppVar_13902 = (cppVar_13902 & cppMask_un_16_);
	cppVar_13903 = ROM.rd(cppVar_13902);
	cppVar_13904 = (cppVar_13903 >> 3) & cppMask_un_5_;
	cppVar_13906 = (cppVar_13904 << 3) | 0;
	cppVar_13906 = (cppVar_13906 & cppMask_un_8_);
	cppVar_13895 = cppVar_13906;
	} else {
	cppVar_13907 = PC + 1;
	cppVar_13907 = (cppVar_13907 & cppMask_un_16_);
	cppVar_13908 = ROM.rd(cppVar_13907);
	cppVar_13909 = (cppVar_13908 >> 3) & cppMask_un_5_;
	cppVar_13910 = (cppVar_13909 & cppMask_un_5_);
	cppVar_13912 = cppVar_13910 + 32;
	cppVar_13912 = (cppVar_13912 & cppMask_un_8_);
	cppVar_13895 = cppVar_13912;
	}
	cppVar_13914 = (cppVar_13895 == 168);
	if (cppVar_13914) {
	cppVar_13916 = PC + 1;
	cppVar_13916 = (cppVar_13916 & cppMask_un_16_);
	cppVar_13917 = ROM.rd(cppVar_13916);
	cppVar_13918 = (cppVar_13917 >> 0) & cppMask_un_3_;
	cppVar_13919 = (cppVar_13918 & cppMask_un_3_);
	cppVar_13920 = 1 << static_cast<unsigned>(cppVar_13919);
	cppVar_13920 = (cppVar_13920 & cppMask_un_8_);
	cppVar_13921 = ~cppVar_13920;
	cppVar_13924 = PC + 1;
	cppVar_13924 = (cppVar_13924 & cppMask_un_16_);
	cppVar_13925 = ROM.rd(cppVar_13924);
	cppVar_13926 = (cppVar_13925 >> 7) & cppMask_un_1_;
	cppVar_13927 = (cppVar_13926 == 1);
	if (cppVar_13927) {
	cppVar_13928 = PC + 1;
	cppVar_13928 = (cppVar_13928 & cppMask_un_16_);
	cppVar_13929 = ROM.rd(cppVar_13928);
	cppVar_13930 = (cppVar_13929 >> 3) & cppMask_un_5_;
	cppVar_13931 = (cppVar_13930 << 3) | 0;
	cppVar_13931 = (cppVar_13931 & cppMask_un_8_);
	cppVar_13923 = cppVar_13931;
	} else {
	cppVar_13932 = PC + 1;
	cppVar_13932 = (cppVar_13932 & cppMask_un_16_);
	cppVar_13933 = ROM.rd(cppVar_13932);
	cppVar_13934 = (cppVar_13933 >> 3) & cppMask_un_5_;
	cppVar_13935 = (cppVar_13934 & cppMask_un_5_);
	cppVar_13936 = cppVar_13935 + 32;
	cppVar_13936 = (cppVar_13936 & cppMask_un_8_);
	cppVar_13923 = cppVar_13936;
	}
	cppVar_13937 = (cppVar_13923 >> 7) & cppMask_un_1_;
	cppVar_13939 = (cppVar_13937 == 0);
	if (cppVar_13939) {
	cppVar_13941 = PC + 1;
	cppVar_13941 = (cppVar_13941 & cppMask_un_16_);
	cppVar_13942 = ROM.rd(cppVar_13941);
	cppVar_13943 = (cppVar_13942 >> 7) & cppMask_un_1_;
	cppVar_13944 = (cppVar_13943 == 1);
	if (cppVar_13944) {
	cppVar_13945 = PC + 1;
	cppVar_13945 = (cppVar_13945 & cppMask_un_16_);
	cppVar_13946 = ROM.rd(cppVar_13945);
	cppVar_13947 = (cppVar_13946 >> 3) & cppMask_un_5_;
	cppVar_13948 = (cppVar_13947 << 3) | 0;
	cppVar_13948 = (cppVar_13948 & cppMask_un_8_);
	cppVar_13940 = cppVar_13948;
	} else {
	cppVar_13949 = PC + 1;
	cppVar_13949 = (cppVar_13949 & cppMask_un_16_);
	cppVar_13950 = ROM.rd(cppVar_13949);
	cppVar_13951 = (cppVar_13950 >> 3) & cppMask_un_5_;
	cppVar_13952 = (cppVar_13951 & cppMask_un_5_);
	cppVar_13953 = cppVar_13952 + 32;
	cppVar_13953 = (cppVar_13953 & cppMask_un_8_);
	cppVar_13940 = cppVar_13953;
	}
	cppVar_13954 = IRAM.rd(cppVar_13940);
	cppVar_13922 = cppVar_13954;
	} else {
	cppVar_13957 = PC + 1;
	cppVar_13957 = (cppVar_13957 & cppMask_un_16_);
	cppVar_13958 = ROM.rd(cppVar_13957);
	cppVar_13959 = (cppVar_13958 >> 7) & cppMask_un_1_;
	cppVar_13960 = (cppVar_13959 == 1);
	if (cppVar_13960) {
	cppVar_13961 = PC + 1;
	cppVar_13961 = (cppVar_13961 & cppMask_un_16_);
	cppVar_13962 = ROM.rd(cppVar_13961);
	cppVar_13963 = (cppVar_13962 >> 3) & cppMask_un_5_;
	cppVar_13964 = (cppVar_13963 << 3) | 0;
	cppVar_13964 = (cppVar_13964 & cppMask_un_8_);
	cppVar_13956 = cppVar_13964;
	} else {
	cppVar_13965 = PC + 1;
	cppVar_13965 = (cppVar_13965 & cppMask_un_16_);
	cppVar_13966 = ROM.rd(cppVar_13965);
	cppVar_13967 = (cppVar_13966 >> 3) & cppMask_un_5_;
	cppVar_13968 = (cppVar_13967 & cppMask_un_5_);
	cppVar_13969 = cppVar_13968 + 32;
	cppVar_13969 = (cppVar_13969 & cppMask_un_8_);
	cppVar_13956 = cppVar_13969;
	}
	cppVar_13971 = (cppVar_13956 == 128);
	if (cppVar_13971) {
	cppVar_13955 = P0;
	} else {
	cppVar_13974 = PC + 1;
	cppVar_13974 = (cppVar_13974 & cppMask_un_16_);
	cppVar_13975 = ROM.rd(cppVar_13974);
	cppVar_13976 = (cppVar_13975 >> 7) & cppMask_un_1_;
	cppVar_13977 = (cppVar_13976 == 1);
	if (cppVar_13977) {
	cppVar_13978 = PC + 1;
	cppVar_13978 = (cppVar_13978 & cppMask_un_16_);
	cppVar_13979 = ROM.rd(cppVar_13978);
	cppVar_13980 = (cppVar_13979 >> 3) & cppMask_un_5_;
	cppVar_13981 = (cppVar_13980 << 3) | 0;
	cppVar_13981 = (cppVar_13981 & cppMask_un_8_);
	cppVar_13973 = cppVar_13981;
	} else {
	cppVar_13982 = PC + 1;
	cppVar_13982 = (cppVar_13982 & cppMask_un_16_);
	cppVar_13983 = ROM.rd(cppVar_13982);
	cppVar_13984 = (cppVar_13983 >> 3) & cppMask_un_5_;
	cppVar_13985 = (cppVar_13984 & cppMask_un_5_);
	cppVar_13986 = cppVar_13985 + 32;
	cppVar_13986 = (cppVar_13986 & cppMask_un_8_);
	cppVar_13973 = cppVar_13986;
	}
	cppVar_13988 = (cppVar_13973 == 129);
	if (cppVar_13988) {
	cppVar_13972 = SP;
	} else {
	cppVar_13991 = PC + 1;
	cppVar_13991 = (cppVar_13991 & cppMask_un_16_);
	cppVar_13992 = ROM.rd(cppVar_13991);
	cppVar_13993 = (cppVar_13992 >> 7) & cppMask_un_1_;
	cppVar_13994 = (cppVar_13993 == 1);
	if (cppVar_13994) {
	cppVar_13995 = PC + 1;
	cppVar_13995 = (cppVar_13995 & cppMask_un_16_);
	cppVar_13996 = ROM.rd(cppVar_13995);
	cppVar_13997 = (cppVar_13996 >> 3) & cppMask_un_5_;
	cppVar_13998 = (cppVar_13997 << 3) | 0;
	cppVar_13998 = (cppVar_13998 & cppMask_un_8_);
	cppVar_13990 = cppVar_13998;
	} else {
	cppVar_13999 = PC + 1;
	cppVar_13999 = (cppVar_13999 & cppMask_un_16_);
	cppVar_14000 = ROM.rd(cppVar_13999);
	cppVar_14001 = (cppVar_14000 >> 3) & cppMask_un_5_;
	cppVar_14002 = (cppVar_14001 & cppMask_un_5_);
	cppVar_14003 = cppVar_14002 + 32;
	cppVar_14003 = (cppVar_14003 & cppMask_un_8_);
	cppVar_13990 = cppVar_14003;
	}
	cppVar_14005 = (cppVar_13990 == 130);
	if (cppVar_14005) {
	cppVar_13989 = DPL;
	} else {
	cppVar_14008 = PC + 1;
	cppVar_14008 = (cppVar_14008 & cppMask_un_16_);
	cppVar_14009 = ROM.rd(cppVar_14008);
	cppVar_14010 = (cppVar_14009 >> 7) & cppMask_un_1_;
	cppVar_14011 = (cppVar_14010 == 1);
	if (cppVar_14011) {
	cppVar_14012 = PC + 1;
	cppVar_14012 = (cppVar_14012 & cppMask_un_16_);
	cppVar_14013 = ROM.rd(cppVar_14012);
	cppVar_14014 = (cppVar_14013 >> 3) & cppMask_un_5_;
	cppVar_14015 = (cppVar_14014 << 3) | 0;
	cppVar_14015 = (cppVar_14015 & cppMask_un_8_);
	cppVar_14007 = cppVar_14015;
	} else {
	cppVar_14016 = PC + 1;
	cppVar_14016 = (cppVar_14016 & cppMask_un_16_);
	cppVar_14017 = ROM.rd(cppVar_14016);
	cppVar_14018 = (cppVar_14017 >> 3) & cppMask_un_5_;
	cppVar_14019 = (cppVar_14018 & cppMask_un_5_);
	cppVar_14020 = cppVar_14019 + 32;
	cppVar_14020 = (cppVar_14020 & cppMask_un_8_);
	cppVar_14007 = cppVar_14020;
	}
	cppVar_14022 = (cppVar_14007 == 131);
	if (cppVar_14022) {
	cppVar_14006 = DPH;
	} else {
	cppVar_14025 = PC + 1;
	cppVar_14025 = (cppVar_14025 & cppMask_un_16_);
	cppVar_14026 = ROM.rd(cppVar_14025);
	cppVar_14027 = (cppVar_14026 >> 7) & cppMask_un_1_;
	cppVar_14028 = (cppVar_14027 == 1);
	if (cppVar_14028) {
	cppVar_14029 = PC + 1;
	cppVar_14029 = (cppVar_14029 & cppMask_un_16_);
	cppVar_14030 = ROM.rd(cppVar_14029);
	cppVar_14031 = (cppVar_14030 >> 3) & cppMask_un_5_;
	cppVar_14032 = (cppVar_14031 << 3) | 0;
	cppVar_14032 = (cppVar_14032 & cppMask_un_8_);
	cppVar_14024 = cppVar_14032;
	} else {
	cppVar_14033 = PC + 1;
	cppVar_14033 = (cppVar_14033 & cppMask_un_16_);
	cppVar_14034 = ROM.rd(cppVar_14033);
	cppVar_14035 = (cppVar_14034 >> 3) & cppMask_un_5_;
	cppVar_14036 = (cppVar_14035 & cppMask_un_5_);
	cppVar_14037 = cppVar_14036 + 32;
	cppVar_14037 = (cppVar_14037 & cppMask_un_8_);
	cppVar_14024 = cppVar_14037;
	}
	cppVar_14039 = (cppVar_14024 == 135);
	if (cppVar_14039) {
	cppVar_14023 = PCON;
	} else {
	cppVar_14042 = PC + 1;
	cppVar_14042 = (cppVar_14042 & cppMask_un_16_);
	cppVar_14043 = ROM.rd(cppVar_14042);
	cppVar_14044 = (cppVar_14043 >> 7) & cppMask_un_1_;
	cppVar_14045 = (cppVar_14044 == 1);
	if (cppVar_14045) {
	cppVar_14046 = PC + 1;
	cppVar_14046 = (cppVar_14046 & cppMask_un_16_);
	cppVar_14047 = ROM.rd(cppVar_14046);
	cppVar_14048 = (cppVar_14047 >> 3) & cppMask_un_5_;
	cppVar_14049 = (cppVar_14048 << 3) | 0;
	cppVar_14049 = (cppVar_14049 & cppMask_un_8_);
	cppVar_14041 = cppVar_14049;
	} else {
	cppVar_14050 = PC + 1;
	cppVar_14050 = (cppVar_14050 & cppMask_un_16_);
	cppVar_14051 = ROM.rd(cppVar_14050);
	cppVar_14052 = (cppVar_14051 >> 3) & cppMask_un_5_;
	cppVar_14053 = (cppVar_14052 & cppMask_un_5_);
	cppVar_14054 = cppVar_14053 + 32;
	cppVar_14054 = (cppVar_14054 & cppMask_un_8_);
	cppVar_14041 = cppVar_14054;
	}
	cppVar_14056 = (cppVar_14041 == 136);
	if (cppVar_14056) {
	cppVar_14040 = TCON;
	} else {
	cppVar_14059 = PC + 1;
	cppVar_14059 = (cppVar_14059 & cppMask_un_16_);
	cppVar_14060 = ROM.rd(cppVar_14059);
	cppVar_14061 = (cppVar_14060 >> 7) & cppMask_un_1_;
	cppVar_14062 = (cppVar_14061 == 1);
	if (cppVar_14062) {
	cppVar_14063 = PC + 1;
	cppVar_14063 = (cppVar_14063 & cppMask_un_16_);
	cppVar_14064 = ROM.rd(cppVar_14063);
	cppVar_14065 = (cppVar_14064 >> 3) & cppMask_un_5_;
	cppVar_14066 = (cppVar_14065 << 3) | 0;
	cppVar_14066 = (cppVar_14066 & cppMask_un_8_);
	cppVar_14058 = cppVar_14066;
	} else {
	cppVar_14067 = PC + 1;
	cppVar_14067 = (cppVar_14067 & cppMask_un_16_);
	cppVar_14068 = ROM.rd(cppVar_14067);
	cppVar_14069 = (cppVar_14068 >> 3) & cppMask_un_5_;
	cppVar_14070 = (cppVar_14069 & cppMask_un_5_);
	cppVar_14071 = cppVar_14070 + 32;
	cppVar_14071 = (cppVar_14071 & cppMask_un_8_);
	cppVar_14058 = cppVar_14071;
	}
	cppVar_14073 = (cppVar_14058 == 137);
	if (cppVar_14073) {
	cppVar_14057 = TMOD;
	} else {
	cppVar_14076 = PC + 1;
	cppVar_14076 = (cppVar_14076 & cppMask_un_16_);
	cppVar_14077 = ROM.rd(cppVar_14076);
	cppVar_14078 = (cppVar_14077 >> 7) & cppMask_un_1_;
	cppVar_14079 = (cppVar_14078 == 1);
	if (cppVar_14079) {
	cppVar_14080 = PC + 1;
	cppVar_14080 = (cppVar_14080 & cppMask_un_16_);
	cppVar_14081 = ROM.rd(cppVar_14080);
	cppVar_14082 = (cppVar_14081 >> 3) & cppMask_un_5_;
	cppVar_14083 = (cppVar_14082 << 3) | 0;
	cppVar_14083 = (cppVar_14083 & cppMask_un_8_);
	cppVar_14075 = cppVar_14083;
	} else {
	cppVar_14084 = PC + 1;
	cppVar_14084 = (cppVar_14084 & cppMask_un_16_);
	cppVar_14085 = ROM.rd(cppVar_14084);
	cppVar_14086 = (cppVar_14085 >> 3) & cppMask_un_5_;
	cppVar_14087 = (cppVar_14086 & cppMask_un_5_);
	cppVar_14088 = cppVar_14087 + 32;
	cppVar_14088 = (cppVar_14088 & cppMask_un_8_);
	cppVar_14075 = cppVar_14088;
	}
	cppVar_14090 = (cppVar_14075 == 138);
	if (cppVar_14090) {
	cppVar_14074 = TL0;
	} else {
	cppVar_14093 = PC + 1;
	cppVar_14093 = (cppVar_14093 & cppMask_un_16_);
	cppVar_14094 = ROM.rd(cppVar_14093);
	cppVar_14095 = (cppVar_14094 >> 7) & cppMask_un_1_;
	cppVar_14096 = (cppVar_14095 == 1);
	if (cppVar_14096) {
	cppVar_14097 = PC + 1;
	cppVar_14097 = (cppVar_14097 & cppMask_un_16_);
	cppVar_14098 = ROM.rd(cppVar_14097);
	cppVar_14099 = (cppVar_14098 >> 3) & cppMask_un_5_;
	cppVar_14100 = (cppVar_14099 << 3) | 0;
	cppVar_14100 = (cppVar_14100 & cppMask_un_8_);
	cppVar_14092 = cppVar_14100;
	} else {
	cppVar_14101 = PC + 1;
	cppVar_14101 = (cppVar_14101 & cppMask_un_16_);
	cppVar_14102 = ROM.rd(cppVar_14101);
	cppVar_14103 = (cppVar_14102 >> 3) & cppMask_un_5_;
	cppVar_14104 = (cppVar_14103 & cppMask_un_5_);
	cppVar_14105 = cppVar_14104 + 32;
	cppVar_14105 = (cppVar_14105 & cppMask_un_8_);
	cppVar_14092 = cppVar_14105;
	}
	cppVar_14107 = (cppVar_14092 == 140);
	if (cppVar_14107) {
	cppVar_14091 = TH0;
	} else {
	cppVar_14110 = PC + 1;
	cppVar_14110 = (cppVar_14110 & cppMask_un_16_);
	cppVar_14111 = ROM.rd(cppVar_14110);
	cppVar_14112 = (cppVar_14111 >> 7) & cppMask_un_1_;
	cppVar_14113 = (cppVar_14112 == 1);
	if (cppVar_14113) {
	cppVar_14114 = PC + 1;
	cppVar_14114 = (cppVar_14114 & cppMask_un_16_);
	cppVar_14115 = ROM.rd(cppVar_14114);
	cppVar_14116 = (cppVar_14115 >> 3) & cppMask_un_5_;
	cppVar_14117 = (cppVar_14116 << 3) | 0;
	cppVar_14117 = (cppVar_14117 & cppMask_un_8_);
	cppVar_14109 = cppVar_14117;
	} else {
	cppVar_14118 = PC + 1;
	cppVar_14118 = (cppVar_14118 & cppMask_un_16_);
	cppVar_14119 = ROM.rd(cppVar_14118);
	cppVar_14120 = (cppVar_14119 >> 3) & cppMask_un_5_;
	cppVar_14121 = (cppVar_14120 & cppMask_un_5_);
	cppVar_14122 = cppVar_14121 + 32;
	cppVar_14122 = (cppVar_14122 & cppMask_un_8_);
	cppVar_14109 = cppVar_14122;
	}
	cppVar_14124 = (cppVar_14109 == 139);
	if (cppVar_14124) {
	cppVar_14108 = TL1;
	} else {
	cppVar_14127 = PC + 1;
	cppVar_14127 = (cppVar_14127 & cppMask_un_16_);
	cppVar_14128 = ROM.rd(cppVar_14127);
	cppVar_14129 = (cppVar_14128 >> 7) & cppMask_un_1_;
	cppVar_14130 = (cppVar_14129 == 1);
	if (cppVar_14130) {
	cppVar_14131 = PC + 1;
	cppVar_14131 = (cppVar_14131 & cppMask_un_16_);
	cppVar_14132 = ROM.rd(cppVar_14131);
	cppVar_14133 = (cppVar_14132 >> 3) & cppMask_un_5_;
	cppVar_14134 = (cppVar_14133 << 3) | 0;
	cppVar_14134 = (cppVar_14134 & cppMask_un_8_);
	cppVar_14126 = cppVar_14134;
	} else {
	cppVar_14135 = PC + 1;
	cppVar_14135 = (cppVar_14135 & cppMask_un_16_);
	cppVar_14136 = ROM.rd(cppVar_14135);
	cppVar_14137 = (cppVar_14136 >> 3) & cppMask_un_5_;
	cppVar_14138 = (cppVar_14137 & cppMask_un_5_);
	cppVar_14139 = cppVar_14138 + 32;
	cppVar_14139 = (cppVar_14139 & cppMask_un_8_);
	cppVar_14126 = cppVar_14139;
	}
	cppVar_14141 = (cppVar_14126 == 141);
	if (cppVar_14141) {
	cppVar_14125 = TH1;
	} else {
	cppVar_14144 = PC + 1;
	cppVar_14144 = (cppVar_14144 & cppMask_un_16_);
	cppVar_14145 = ROM.rd(cppVar_14144);
	cppVar_14146 = (cppVar_14145 >> 7) & cppMask_un_1_;
	cppVar_14147 = (cppVar_14146 == 1);
	if (cppVar_14147) {
	cppVar_14148 = PC + 1;
	cppVar_14148 = (cppVar_14148 & cppMask_un_16_);
	cppVar_14149 = ROM.rd(cppVar_14148);
	cppVar_14150 = (cppVar_14149 >> 3) & cppMask_un_5_;
	cppVar_14151 = (cppVar_14150 << 3) | 0;
	cppVar_14151 = (cppVar_14151 & cppMask_un_8_);
	cppVar_14143 = cppVar_14151;
	} else {
	cppVar_14152 = PC + 1;
	cppVar_14152 = (cppVar_14152 & cppMask_un_16_);
	cppVar_14153 = ROM.rd(cppVar_14152);
	cppVar_14154 = (cppVar_14153 >> 3) & cppMask_un_5_;
	cppVar_14155 = (cppVar_14154 & cppMask_un_5_);
	cppVar_14156 = cppVar_14155 + 32;
	cppVar_14156 = (cppVar_14156 & cppMask_un_8_);
	cppVar_14143 = cppVar_14156;
	}
	cppVar_14158 = (cppVar_14143 == 144);
	if (cppVar_14158) {
	cppVar_14142 = P1;
	} else {
	cppVar_14161 = PC + 1;
	cppVar_14161 = (cppVar_14161 & cppMask_un_16_);
	cppVar_14162 = ROM.rd(cppVar_14161);
	cppVar_14163 = (cppVar_14162 >> 7) & cppMask_un_1_;
	cppVar_14164 = (cppVar_14163 == 1);
	if (cppVar_14164) {
	cppVar_14165 = PC + 1;
	cppVar_14165 = (cppVar_14165 & cppMask_un_16_);
	cppVar_14166 = ROM.rd(cppVar_14165);
	cppVar_14167 = (cppVar_14166 >> 3) & cppMask_un_5_;
	cppVar_14168 = (cppVar_14167 << 3) | 0;
	cppVar_14168 = (cppVar_14168 & cppMask_un_8_);
	cppVar_14160 = cppVar_14168;
	} else {
	cppVar_14169 = PC + 1;
	cppVar_14169 = (cppVar_14169 & cppMask_un_16_);
	cppVar_14170 = ROM.rd(cppVar_14169);
	cppVar_14171 = (cppVar_14170 >> 3) & cppMask_un_5_;
	cppVar_14172 = (cppVar_14171 & cppMask_un_5_);
	cppVar_14173 = cppVar_14172 + 32;
	cppVar_14173 = (cppVar_14173 & cppMask_un_8_);
	cppVar_14160 = cppVar_14173;
	}
	cppVar_14175 = (cppVar_14160 == 152);
	if (cppVar_14175) {
	cppVar_14159 = SCON;
	} else {
	cppVar_14178 = PC + 1;
	cppVar_14178 = (cppVar_14178 & cppMask_un_16_);
	cppVar_14179 = ROM.rd(cppVar_14178);
	cppVar_14180 = (cppVar_14179 >> 7) & cppMask_un_1_;
	cppVar_14181 = (cppVar_14180 == 1);
	if (cppVar_14181) {
	cppVar_14182 = PC + 1;
	cppVar_14182 = (cppVar_14182 & cppMask_un_16_);
	cppVar_14183 = ROM.rd(cppVar_14182);
	cppVar_14184 = (cppVar_14183 >> 3) & cppMask_un_5_;
	cppVar_14185 = (cppVar_14184 << 3) | 0;
	cppVar_14185 = (cppVar_14185 & cppMask_un_8_);
	cppVar_14177 = cppVar_14185;
	} else {
	cppVar_14186 = PC + 1;
	cppVar_14186 = (cppVar_14186 & cppMask_un_16_);
	cppVar_14187 = ROM.rd(cppVar_14186);
	cppVar_14188 = (cppVar_14187 >> 3) & cppMask_un_5_;
	cppVar_14189 = (cppVar_14188 & cppMask_un_5_);
	cppVar_14190 = cppVar_14189 + 32;
	cppVar_14190 = (cppVar_14190 & cppMask_un_8_);
	cppVar_14177 = cppVar_14190;
	}
	cppVar_14192 = (cppVar_14177 == 153);
	if (cppVar_14192) {
	cppVar_14176 = SBUF;
	} else {
	cppVar_14195 = PC + 1;
	cppVar_14195 = (cppVar_14195 & cppMask_un_16_);
	cppVar_14196 = ROM.rd(cppVar_14195);
	cppVar_14197 = (cppVar_14196 >> 7) & cppMask_un_1_;
	cppVar_14198 = (cppVar_14197 == 1);
	if (cppVar_14198) {
	cppVar_14199 = PC + 1;
	cppVar_14199 = (cppVar_14199 & cppMask_un_16_);
	cppVar_14200 = ROM.rd(cppVar_14199);
	cppVar_14201 = (cppVar_14200 >> 3) & cppMask_un_5_;
	cppVar_14202 = (cppVar_14201 << 3) | 0;
	cppVar_14202 = (cppVar_14202 & cppMask_un_8_);
	cppVar_14194 = cppVar_14202;
	} else {
	cppVar_14203 = PC + 1;
	cppVar_14203 = (cppVar_14203 & cppMask_un_16_);
	cppVar_14204 = ROM.rd(cppVar_14203);
	cppVar_14205 = (cppVar_14204 >> 3) & cppMask_un_5_;
	cppVar_14206 = (cppVar_14205 & cppMask_un_5_);
	cppVar_14207 = cppVar_14206 + 32;
	cppVar_14207 = (cppVar_14207 & cppMask_un_8_);
	cppVar_14194 = cppVar_14207;
	}
	cppVar_14209 = (cppVar_14194 == 160);
	if (cppVar_14209) {
	cppVar_14193 = P2;
	} else {
	cppVar_14212 = PC + 1;
	cppVar_14212 = (cppVar_14212 & cppMask_un_16_);
	cppVar_14213 = ROM.rd(cppVar_14212);
	cppVar_14214 = (cppVar_14213 >> 7) & cppMask_un_1_;
	cppVar_14215 = (cppVar_14214 == 1);
	if (cppVar_14215) {
	cppVar_14216 = PC + 1;
	cppVar_14216 = (cppVar_14216 & cppMask_un_16_);
	cppVar_14217 = ROM.rd(cppVar_14216);
	cppVar_14218 = (cppVar_14217 >> 3) & cppMask_un_5_;
	cppVar_14219 = (cppVar_14218 << 3) | 0;
	cppVar_14219 = (cppVar_14219 & cppMask_un_8_);
	cppVar_14211 = cppVar_14219;
	} else {
	cppVar_14220 = PC + 1;
	cppVar_14220 = (cppVar_14220 & cppMask_un_16_);
	cppVar_14221 = ROM.rd(cppVar_14220);
	cppVar_14222 = (cppVar_14221 >> 3) & cppMask_un_5_;
	cppVar_14223 = (cppVar_14222 & cppMask_un_5_);
	cppVar_14224 = cppVar_14223 + 32;
	cppVar_14224 = (cppVar_14224 & cppMask_un_8_);
	cppVar_14211 = cppVar_14224;
	}
	cppVar_14226 = (cppVar_14211 == 168);
	if (cppVar_14226) {
	cppVar_14210 = IE;
	} else {
	cppVar_14229 = PC + 1;
	cppVar_14229 = (cppVar_14229 & cppMask_un_16_);
	cppVar_14230 = ROM.rd(cppVar_14229);
	cppVar_14231 = (cppVar_14230 >> 7) & cppMask_un_1_;
	cppVar_14232 = (cppVar_14231 == 1);
	if (cppVar_14232) {
	cppVar_14233 = PC + 1;
	cppVar_14233 = (cppVar_14233 & cppMask_un_16_);
	cppVar_14234 = ROM.rd(cppVar_14233);
	cppVar_14235 = (cppVar_14234 >> 3) & cppMask_un_5_;
	cppVar_14236 = (cppVar_14235 << 3) | 0;
	cppVar_14236 = (cppVar_14236 & cppMask_un_8_);
	cppVar_14228 = cppVar_14236;
	} else {
	cppVar_14237 = PC + 1;
	cppVar_14237 = (cppVar_14237 & cppMask_un_16_);
	cppVar_14238 = ROM.rd(cppVar_14237);
	cppVar_14239 = (cppVar_14238 >> 3) & cppMask_un_5_;
	cppVar_14240 = (cppVar_14239 & cppMask_un_5_);
	cppVar_14241 = cppVar_14240 + 32;
	cppVar_14241 = (cppVar_14241 & cppMask_un_8_);
	cppVar_14228 = cppVar_14241;
	}
	cppVar_14243 = (cppVar_14228 == 176);
	if (cppVar_14243) {
	cppVar_14227 = P3;
	} else {
	cppVar_14246 = PC + 1;
	cppVar_14246 = (cppVar_14246 & cppMask_un_16_);
	cppVar_14247 = ROM.rd(cppVar_14246);
	cppVar_14248 = (cppVar_14247 >> 7) & cppMask_un_1_;
	cppVar_14249 = (cppVar_14248 == 1);
	if (cppVar_14249) {
	cppVar_14250 = PC + 1;
	cppVar_14250 = (cppVar_14250 & cppMask_un_16_);
	cppVar_14251 = ROM.rd(cppVar_14250);
	cppVar_14252 = (cppVar_14251 >> 3) & cppMask_un_5_;
	cppVar_14253 = (cppVar_14252 << 3) | 0;
	cppVar_14253 = (cppVar_14253 & cppMask_un_8_);
	cppVar_14245 = cppVar_14253;
	} else {
	cppVar_14254 = PC + 1;
	cppVar_14254 = (cppVar_14254 & cppMask_un_16_);
	cppVar_14255 = ROM.rd(cppVar_14254);
	cppVar_14256 = (cppVar_14255 >> 3) & cppMask_un_5_;
	cppVar_14257 = (cppVar_14256 & cppMask_un_5_);
	cppVar_14258 = cppVar_14257 + 32;
	cppVar_14258 = (cppVar_14258 & cppMask_un_8_);
	cppVar_14245 = cppVar_14258;
	}
	cppVar_14260 = (cppVar_14245 == 184);
	if (cppVar_14260) {
	cppVar_14244 = IP;
	} else {
	cppVar_14263 = PC + 1;
	cppVar_14263 = (cppVar_14263 & cppMask_un_16_);
	cppVar_14264 = ROM.rd(cppVar_14263);
	cppVar_14265 = (cppVar_14264 >> 7) & cppMask_un_1_;
	cppVar_14266 = (cppVar_14265 == 1);
	if (cppVar_14266) {
	cppVar_14267 = PC + 1;
	cppVar_14267 = (cppVar_14267 & cppMask_un_16_);
	cppVar_14268 = ROM.rd(cppVar_14267);
	cppVar_14269 = (cppVar_14268 >> 3) & cppMask_un_5_;
	cppVar_14270 = (cppVar_14269 << 3) | 0;
	cppVar_14270 = (cppVar_14270 & cppMask_un_8_);
	cppVar_14262 = cppVar_14270;
	} else {
	cppVar_14271 = PC + 1;
	cppVar_14271 = (cppVar_14271 & cppMask_un_16_);
	cppVar_14272 = ROM.rd(cppVar_14271);
	cppVar_14273 = (cppVar_14272 >> 3) & cppMask_un_5_;
	cppVar_14274 = (cppVar_14273 & cppMask_un_5_);
	cppVar_14275 = cppVar_14274 + 32;
	cppVar_14275 = (cppVar_14275 & cppMask_un_8_);
	cppVar_14262 = cppVar_14275;
	}
	cppVar_14277 = (cppVar_14262 == 208);
	if (cppVar_14277) {
	cppVar_14261 = PSW;
	} else {
	cppVar_14280 = PC + 1;
	cppVar_14280 = (cppVar_14280 & cppMask_un_16_);
	cppVar_14281 = ROM.rd(cppVar_14280);
	cppVar_14282 = (cppVar_14281 >> 7) & cppMask_un_1_;
	cppVar_14283 = (cppVar_14282 == 1);
	if (cppVar_14283) {
	cppVar_14284 = PC + 1;
	cppVar_14284 = (cppVar_14284 & cppMask_un_16_);
	cppVar_14285 = ROM.rd(cppVar_14284);
	cppVar_14286 = (cppVar_14285 >> 3) & cppMask_un_5_;
	cppVar_14287 = (cppVar_14286 << 3) | 0;
	cppVar_14287 = (cppVar_14287 & cppMask_un_8_);
	cppVar_14279 = cppVar_14287;
	} else {
	cppVar_14288 = PC + 1;
	cppVar_14288 = (cppVar_14288 & cppMask_un_16_);
	cppVar_14289 = ROM.rd(cppVar_14288);
	cppVar_14290 = (cppVar_14289 >> 3) & cppMask_un_5_;
	cppVar_14291 = (cppVar_14290 & cppMask_un_5_);
	cppVar_14292 = cppVar_14291 + 32;
	cppVar_14292 = (cppVar_14292 & cppMask_un_8_);
	cppVar_14279 = cppVar_14292;
	}
	cppVar_14294 = (cppVar_14279 == 224);
	if (cppVar_14294) {
	cppVar_14278 = ACC;
	} else {
	cppVar_14297 = PC + 1;
	cppVar_14297 = (cppVar_14297 & cppMask_un_16_);
	cppVar_14298 = ROM.rd(cppVar_14297);
	cppVar_14299 = (cppVar_14298 >> 7) & cppMask_un_1_;
	cppVar_14300 = (cppVar_14299 == 1);
	if (cppVar_14300) {
	cppVar_14301 = PC + 1;
	cppVar_14301 = (cppVar_14301 & cppMask_un_16_);
	cppVar_14302 = ROM.rd(cppVar_14301);
	cppVar_14303 = (cppVar_14302 >> 3) & cppMask_un_5_;
	cppVar_14304 = (cppVar_14303 << 3) | 0;
	cppVar_14304 = (cppVar_14304 & cppMask_un_8_);
	cppVar_14296 = cppVar_14304;
	} else {
	cppVar_14305 = PC + 1;
	cppVar_14305 = (cppVar_14305 & cppMask_un_16_);
	cppVar_14306 = ROM.rd(cppVar_14305);
	cppVar_14307 = (cppVar_14306 >> 3) & cppMask_un_5_;
	cppVar_14308 = (cppVar_14307 & cppMask_un_5_);
	cppVar_14309 = cppVar_14308 + 32;
	cppVar_14309 = (cppVar_14309 & cppMask_un_8_);
	cppVar_14296 = cppVar_14309;
	}
	cppVar_14311 = (cppVar_14296 == 240);
	if (cppVar_14311) {
	cppVar_14295 = B;
	} else {
	cppVar_14295 = 0;
	}
	cppVar_14278 = cppVar_14295;
	}
	cppVar_14261 = cppVar_14278;
	}
	cppVar_14244 = cppVar_14261;
	}
	cppVar_14227 = cppVar_14244;
	}
	cppVar_14210 = cppVar_14227;
	}
	cppVar_14193 = cppVar_14210;
	}
	cppVar_14176 = cppVar_14193;
	}
	cppVar_14159 = cppVar_14176;
	}
	cppVar_14142 = cppVar_14159;
	}
	cppVar_14125 = cppVar_14142;
	}
	cppVar_14108 = cppVar_14125;
	}
	cppVar_14091 = cppVar_14108;
	}
	cppVar_14074 = cppVar_14091;
	}
	cppVar_14057 = cppVar_14074;
	}
	cppVar_14040 = cppVar_14057;
	}
	cppVar_14023 = cppVar_14040;
	}
	cppVar_14006 = cppVar_14023;
	}
	cppVar_13989 = cppVar_14006;
	}
	cppVar_13972 = cppVar_13989;
	}
	cppVar_13955 = cppVar_13972;
	}
	cppVar_13922 = cppVar_13955;
	}
	cppVar_14313 = cppVar_13921 & cppVar_13922;
	cppVar_14316 = PC + 1;
	cppVar_14316 = (cppVar_14316 & cppMask_un_16_);
	cppVar_14317 = ROM.rd(cppVar_14316);
	cppVar_14318 = (cppVar_14317 >> 7) & cppMask_un_1_;
	cppVar_14320 = (cppVar_14318 == 1);
	if (cppVar_14320) {
	cppVar_14321 = PC + 1;
	cppVar_14321 = (cppVar_14321 & cppMask_un_16_);
	cppVar_14322 = ROM.rd(cppVar_14321);
	cppVar_14323 = (cppVar_14322 >> 3) & cppMask_un_5_;
	cppVar_14325 = (cppVar_14323 << 3) | 0;
	cppVar_14325 = (cppVar_14325 & cppMask_un_8_);
	cppVar_14315 = cppVar_14325;
	} else {
	cppVar_14326 = PC + 1;
	cppVar_14326 = (cppVar_14326 & cppMask_un_16_);
	cppVar_14327 = ROM.rd(cppVar_14326);
	cppVar_14328 = (cppVar_14327 >> 3) & cppMask_un_5_;
	cppVar_14329 = (cppVar_14328 & cppMask_un_5_);
	cppVar_14331 = cppVar_14329 + 32;
	cppVar_14331 = (cppVar_14331 & cppMask_un_8_);
	cppVar_14315 = cppVar_14331;
	}
	cppVar_14332 = (cppVar_14315 >> 7) & cppMask_un_1_;
	cppVar_14334 = (cppVar_14332 == 0);
	if (cppVar_14334) {
	cppVar_14336 = PC + 1;
	cppVar_14336 = (cppVar_14336 & cppMask_un_16_);
	cppVar_14337 = ROM.rd(cppVar_14336);
	cppVar_14338 = (cppVar_14337 >> 7) & cppMask_un_1_;
	cppVar_14339 = (cppVar_14338 == 1);
	if (cppVar_14339) {
	cppVar_14340 = PC + 1;
	cppVar_14340 = (cppVar_14340 & cppMask_un_16_);
	cppVar_14341 = ROM.rd(cppVar_14340);
	cppVar_14342 = (cppVar_14341 >> 3) & cppMask_un_5_;
	cppVar_14343 = (cppVar_14342 << 3) | 0;
	cppVar_14343 = (cppVar_14343 & cppMask_un_8_);
	cppVar_14335 = cppVar_14343;
	} else {
	cppVar_14344 = PC + 1;
	cppVar_14344 = (cppVar_14344 & cppMask_un_16_);
	cppVar_14345 = ROM.rd(cppVar_14344);
	cppVar_14346 = (cppVar_14345 >> 3) & cppMask_un_5_;
	cppVar_14347 = (cppVar_14346 & cppMask_un_5_);
	cppVar_14348 = cppVar_14347 + 32;
	cppVar_14348 = (cppVar_14348 & cppMask_un_8_);
	cppVar_14335 = cppVar_14348;
	}
	cppVar_14349 = IRAM.rd(cppVar_14335);
	cppVar_14314 = cppVar_14349;
	} else {
	cppVar_14352 = PC + 1;
	cppVar_14352 = (cppVar_14352 & cppMask_un_16_);
	cppVar_14353 = ROM.rd(cppVar_14352);
	cppVar_14354 = (cppVar_14353 >> 7) & cppMask_un_1_;
	cppVar_14355 = (cppVar_14354 == 1);
	if (cppVar_14355) {
	cppVar_14356 = PC + 1;
	cppVar_14356 = (cppVar_14356 & cppMask_un_16_);
	cppVar_14357 = ROM.rd(cppVar_14356);
	cppVar_14358 = (cppVar_14357 >> 3) & cppMask_un_5_;
	cppVar_14359 = (cppVar_14358 << 3) | 0;
	cppVar_14359 = (cppVar_14359 & cppMask_un_8_);
	cppVar_14351 = cppVar_14359;
	} else {
	cppVar_14360 = PC + 1;
	cppVar_14360 = (cppVar_14360 & cppMask_un_16_);
	cppVar_14361 = ROM.rd(cppVar_14360);
	cppVar_14362 = (cppVar_14361 >> 3) & cppMask_un_5_;
	cppVar_14363 = (cppVar_14362 & cppMask_un_5_);
	cppVar_14364 = cppVar_14363 + 32;
	cppVar_14364 = (cppVar_14364 & cppMask_un_8_);
	cppVar_14351 = cppVar_14364;
	}
	cppVar_14366 = (cppVar_14351 == 128);
	if (cppVar_14366) {
	cppVar_14350 = P0;
	} else {
	cppVar_14369 = PC + 1;
	cppVar_14369 = (cppVar_14369 & cppMask_un_16_);
	cppVar_14370 = ROM.rd(cppVar_14369);
	cppVar_14371 = (cppVar_14370 >> 7) & cppMask_un_1_;
	cppVar_14372 = (cppVar_14371 == 1);
	if (cppVar_14372) {
	cppVar_14373 = PC + 1;
	cppVar_14373 = (cppVar_14373 & cppMask_un_16_);
	cppVar_14374 = ROM.rd(cppVar_14373);
	cppVar_14375 = (cppVar_14374 >> 3) & cppMask_un_5_;
	cppVar_14376 = (cppVar_14375 << 3) | 0;
	cppVar_14376 = (cppVar_14376 & cppMask_un_8_);
	cppVar_14368 = cppVar_14376;
	} else {
	cppVar_14377 = PC + 1;
	cppVar_14377 = (cppVar_14377 & cppMask_un_16_);
	cppVar_14378 = ROM.rd(cppVar_14377);
	cppVar_14379 = (cppVar_14378 >> 3) & cppMask_un_5_;
	cppVar_14380 = (cppVar_14379 & cppMask_un_5_);
	cppVar_14381 = cppVar_14380 + 32;
	cppVar_14381 = (cppVar_14381 & cppMask_un_8_);
	cppVar_14368 = cppVar_14381;
	}
	cppVar_14383 = (cppVar_14368 == 129);
	if (cppVar_14383) {
	cppVar_14367 = SP;
	} else {
	cppVar_14386 = PC + 1;
	cppVar_14386 = (cppVar_14386 & cppMask_un_16_);
	cppVar_14387 = ROM.rd(cppVar_14386);
	cppVar_14388 = (cppVar_14387 >> 7) & cppMask_un_1_;
	cppVar_14389 = (cppVar_14388 == 1);
	if (cppVar_14389) {
	cppVar_14390 = PC + 1;
	cppVar_14390 = (cppVar_14390 & cppMask_un_16_);
	cppVar_14391 = ROM.rd(cppVar_14390);
	cppVar_14392 = (cppVar_14391 >> 3) & cppMask_un_5_;
	cppVar_14393 = (cppVar_14392 << 3) | 0;
	cppVar_14393 = (cppVar_14393 & cppMask_un_8_);
	cppVar_14385 = cppVar_14393;
	} else {
	cppVar_14394 = PC + 1;
	cppVar_14394 = (cppVar_14394 & cppMask_un_16_);
	cppVar_14395 = ROM.rd(cppVar_14394);
	cppVar_14396 = (cppVar_14395 >> 3) & cppMask_un_5_;
	cppVar_14397 = (cppVar_14396 & cppMask_un_5_);
	cppVar_14398 = cppVar_14397 + 32;
	cppVar_14398 = (cppVar_14398 & cppMask_un_8_);
	cppVar_14385 = cppVar_14398;
	}
	cppVar_14400 = (cppVar_14385 == 130);
	if (cppVar_14400) {
	cppVar_14384 = DPL;
	} else {
	cppVar_14403 = PC + 1;
	cppVar_14403 = (cppVar_14403 & cppMask_un_16_);
	cppVar_14404 = ROM.rd(cppVar_14403);
	cppVar_14405 = (cppVar_14404 >> 7) & cppMask_un_1_;
	cppVar_14406 = (cppVar_14405 == 1);
	if (cppVar_14406) {
	cppVar_14407 = PC + 1;
	cppVar_14407 = (cppVar_14407 & cppMask_un_16_);
	cppVar_14408 = ROM.rd(cppVar_14407);
	cppVar_14409 = (cppVar_14408 >> 3) & cppMask_un_5_;
	cppVar_14410 = (cppVar_14409 << 3) | 0;
	cppVar_14410 = (cppVar_14410 & cppMask_un_8_);
	cppVar_14402 = cppVar_14410;
	} else {
	cppVar_14411 = PC + 1;
	cppVar_14411 = (cppVar_14411 & cppMask_un_16_);
	cppVar_14412 = ROM.rd(cppVar_14411);
	cppVar_14413 = (cppVar_14412 >> 3) & cppMask_un_5_;
	cppVar_14414 = (cppVar_14413 & cppMask_un_5_);
	cppVar_14415 = cppVar_14414 + 32;
	cppVar_14415 = (cppVar_14415 & cppMask_un_8_);
	cppVar_14402 = cppVar_14415;
	}
	cppVar_14417 = (cppVar_14402 == 131);
	if (cppVar_14417) {
	cppVar_14401 = DPH;
	} else {
	cppVar_14420 = PC + 1;
	cppVar_14420 = (cppVar_14420 & cppMask_un_16_);
	cppVar_14421 = ROM.rd(cppVar_14420);
	cppVar_14422 = (cppVar_14421 >> 7) & cppMask_un_1_;
	cppVar_14423 = (cppVar_14422 == 1);
	if (cppVar_14423) {
	cppVar_14424 = PC + 1;
	cppVar_14424 = (cppVar_14424 & cppMask_un_16_);
	cppVar_14425 = ROM.rd(cppVar_14424);
	cppVar_14426 = (cppVar_14425 >> 3) & cppMask_un_5_;
	cppVar_14427 = (cppVar_14426 << 3) | 0;
	cppVar_14427 = (cppVar_14427 & cppMask_un_8_);
	cppVar_14419 = cppVar_14427;
	} else {
	cppVar_14428 = PC + 1;
	cppVar_14428 = (cppVar_14428 & cppMask_un_16_);
	cppVar_14429 = ROM.rd(cppVar_14428);
	cppVar_14430 = (cppVar_14429 >> 3) & cppMask_un_5_;
	cppVar_14431 = (cppVar_14430 & cppMask_un_5_);
	cppVar_14432 = cppVar_14431 + 32;
	cppVar_14432 = (cppVar_14432 & cppMask_un_8_);
	cppVar_14419 = cppVar_14432;
	}
	cppVar_14434 = (cppVar_14419 == 135);
	if (cppVar_14434) {
	cppVar_14418 = PCON;
	} else {
	cppVar_14437 = PC + 1;
	cppVar_14437 = (cppVar_14437 & cppMask_un_16_);
	cppVar_14438 = ROM.rd(cppVar_14437);
	cppVar_14439 = (cppVar_14438 >> 7) & cppMask_un_1_;
	cppVar_14440 = (cppVar_14439 == 1);
	if (cppVar_14440) {
	cppVar_14441 = PC + 1;
	cppVar_14441 = (cppVar_14441 & cppMask_un_16_);
	cppVar_14442 = ROM.rd(cppVar_14441);
	cppVar_14443 = (cppVar_14442 >> 3) & cppMask_un_5_;
	cppVar_14444 = (cppVar_14443 << 3) | 0;
	cppVar_14444 = (cppVar_14444 & cppMask_un_8_);
	cppVar_14436 = cppVar_14444;
	} else {
	cppVar_14445 = PC + 1;
	cppVar_14445 = (cppVar_14445 & cppMask_un_16_);
	cppVar_14446 = ROM.rd(cppVar_14445);
	cppVar_14447 = (cppVar_14446 >> 3) & cppMask_un_5_;
	cppVar_14448 = (cppVar_14447 & cppMask_un_5_);
	cppVar_14449 = cppVar_14448 + 32;
	cppVar_14449 = (cppVar_14449 & cppMask_un_8_);
	cppVar_14436 = cppVar_14449;
	}
	cppVar_14451 = (cppVar_14436 == 136);
	if (cppVar_14451) {
	cppVar_14435 = TCON;
	} else {
	cppVar_14454 = PC + 1;
	cppVar_14454 = (cppVar_14454 & cppMask_un_16_);
	cppVar_14455 = ROM.rd(cppVar_14454);
	cppVar_14456 = (cppVar_14455 >> 7) & cppMask_un_1_;
	cppVar_14457 = (cppVar_14456 == 1);
	if (cppVar_14457) {
	cppVar_14458 = PC + 1;
	cppVar_14458 = (cppVar_14458 & cppMask_un_16_);
	cppVar_14459 = ROM.rd(cppVar_14458);
	cppVar_14460 = (cppVar_14459 >> 3) & cppMask_un_5_;
	cppVar_14461 = (cppVar_14460 << 3) | 0;
	cppVar_14461 = (cppVar_14461 & cppMask_un_8_);
	cppVar_14453 = cppVar_14461;
	} else {
	cppVar_14462 = PC + 1;
	cppVar_14462 = (cppVar_14462 & cppMask_un_16_);
	cppVar_14463 = ROM.rd(cppVar_14462);
	cppVar_14464 = (cppVar_14463 >> 3) & cppMask_un_5_;
	cppVar_14465 = (cppVar_14464 & cppMask_un_5_);
	cppVar_14466 = cppVar_14465 + 32;
	cppVar_14466 = (cppVar_14466 & cppMask_un_8_);
	cppVar_14453 = cppVar_14466;
	}
	cppVar_14468 = (cppVar_14453 == 137);
	if (cppVar_14468) {
	cppVar_14452 = TMOD;
	} else {
	cppVar_14471 = PC + 1;
	cppVar_14471 = (cppVar_14471 & cppMask_un_16_);
	cppVar_14472 = ROM.rd(cppVar_14471);
	cppVar_14473 = (cppVar_14472 >> 7) & cppMask_un_1_;
	cppVar_14474 = (cppVar_14473 == 1);
	if (cppVar_14474) {
	cppVar_14475 = PC + 1;
	cppVar_14475 = (cppVar_14475 & cppMask_un_16_);
	cppVar_14476 = ROM.rd(cppVar_14475);
	cppVar_14477 = (cppVar_14476 >> 3) & cppMask_un_5_;
	cppVar_14478 = (cppVar_14477 << 3) | 0;
	cppVar_14478 = (cppVar_14478 & cppMask_un_8_);
	cppVar_14470 = cppVar_14478;
	} else {
	cppVar_14479 = PC + 1;
	cppVar_14479 = (cppVar_14479 & cppMask_un_16_);
	cppVar_14480 = ROM.rd(cppVar_14479);
	cppVar_14481 = (cppVar_14480 >> 3) & cppMask_un_5_;
	cppVar_14482 = (cppVar_14481 & cppMask_un_5_);
	cppVar_14483 = cppVar_14482 + 32;
	cppVar_14483 = (cppVar_14483 & cppMask_un_8_);
	cppVar_14470 = cppVar_14483;
	}
	cppVar_14485 = (cppVar_14470 == 138);
	if (cppVar_14485) {
	cppVar_14469 = TL0;
	} else {
	cppVar_14488 = PC + 1;
	cppVar_14488 = (cppVar_14488 & cppMask_un_16_);
	cppVar_14489 = ROM.rd(cppVar_14488);
	cppVar_14490 = (cppVar_14489 >> 7) & cppMask_un_1_;
	cppVar_14491 = (cppVar_14490 == 1);
	if (cppVar_14491) {
	cppVar_14492 = PC + 1;
	cppVar_14492 = (cppVar_14492 & cppMask_un_16_);
	cppVar_14493 = ROM.rd(cppVar_14492);
	cppVar_14494 = (cppVar_14493 >> 3) & cppMask_un_5_;
	cppVar_14495 = (cppVar_14494 << 3) | 0;
	cppVar_14495 = (cppVar_14495 & cppMask_un_8_);
	cppVar_14487 = cppVar_14495;
	} else {
	cppVar_14496 = PC + 1;
	cppVar_14496 = (cppVar_14496 & cppMask_un_16_);
	cppVar_14497 = ROM.rd(cppVar_14496);
	cppVar_14498 = (cppVar_14497 >> 3) & cppMask_un_5_;
	cppVar_14499 = (cppVar_14498 & cppMask_un_5_);
	cppVar_14500 = cppVar_14499 + 32;
	cppVar_14500 = (cppVar_14500 & cppMask_un_8_);
	cppVar_14487 = cppVar_14500;
	}
	cppVar_14502 = (cppVar_14487 == 140);
	if (cppVar_14502) {
	cppVar_14486 = TH0;
	} else {
	cppVar_14505 = PC + 1;
	cppVar_14505 = (cppVar_14505 & cppMask_un_16_);
	cppVar_14506 = ROM.rd(cppVar_14505);
	cppVar_14507 = (cppVar_14506 >> 7) & cppMask_un_1_;
	cppVar_14508 = (cppVar_14507 == 1);
	if (cppVar_14508) {
	cppVar_14509 = PC + 1;
	cppVar_14509 = (cppVar_14509 & cppMask_un_16_);
	cppVar_14510 = ROM.rd(cppVar_14509);
	cppVar_14511 = (cppVar_14510 >> 3) & cppMask_un_5_;
	cppVar_14512 = (cppVar_14511 << 3) | 0;
	cppVar_14512 = (cppVar_14512 & cppMask_un_8_);
	cppVar_14504 = cppVar_14512;
	} else {
	cppVar_14513 = PC + 1;
	cppVar_14513 = (cppVar_14513 & cppMask_un_16_);
	cppVar_14514 = ROM.rd(cppVar_14513);
	cppVar_14515 = (cppVar_14514 >> 3) & cppMask_un_5_;
	cppVar_14516 = (cppVar_14515 & cppMask_un_5_);
	cppVar_14517 = cppVar_14516 + 32;
	cppVar_14517 = (cppVar_14517 & cppMask_un_8_);
	cppVar_14504 = cppVar_14517;
	}
	cppVar_14519 = (cppVar_14504 == 139);
	if (cppVar_14519) {
	cppVar_14503 = TL1;
	} else {
	cppVar_14522 = PC + 1;
	cppVar_14522 = (cppVar_14522 & cppMask_un_16_);
	cppVar_14523 = ROM.rd(cppVar_14522);
	cppVar_14524 = (cppVar_14523 >> 7) & cppMask_un_1_;
	cppVar_14525 = (cppVar_14524 == 1);
	if (cppVar_14525) {
	cppVar_14526 = PC + 1;
	cppVar_14526 = (cppVar_14526 & cppMask_un_16_);
	cppVar_14527 = ROM.rd(cppVar_14526);
	cppVar_14528 = (cppVar_14527 >> 3) & cppMask_un_5_;
	cppVar_14529 = (cppVar_14528 << 3) | 0;
	cppVar_14529 = (cppVar_14529 & cppMask_un_8_);
	cppVar_14521 = cppVar_14529;
	} else {
	cppVar_14530 = PC + 1;
	cppVar_14530 = (cppVar_14530 & cppMask_un_16_);
	cppVar_14531 = ROM.rd(cppVar_14530);
	cppVar_14532 = (cppVar_14531 >> 3) & cppMask_un_5_;
	cppVar_14533 = (cppVar_14532 & cppMask_un_5_);
	cppVar_14534 = cppVar_14533 + 32;
	cppVar_14534 = (cppVar_14534 & cppMask_un_8_);
	cppVar_14521 = cppVar_14534;
	}
	cppVar_14536 = (cppVar_14521 == 141);
	if (cppVar_14536) {
	cppVar_14520 = TH1;
	} else {
	cppVar_14539 = PC + 1;
	cppVar_14539 = (cppVar_14539 & cppMask_un_16_);
	cppVar_14540 = ROM.rd(cppVar_14539);
	cppVar_14541 = (cppVar_14540 >> 7) & cppMask_un_1_;
	cppVar_14542 = (cppVar_14541 == 1);
	if (cppVar_14542) {
	cppVar_14543 = PC + 1;
	cppVar_14543 = (cppVar_14543 & cppMask_un_16_);
	cppVar_14544 = ROM.rd(cppVar_14543);
	cppVar_14545 = (cppVar_14544 >> 3) & cppMask_un_5_;
	cppVar_14546 = (cppVar_14545 << 3) | 0;
	cppVar_14546 = (cppVar_14546 & cppMask_un_8_);
	cppVar_14538 = cppVar_14546;
	} else {
	cppVar_14547 = PC + 1;
	cppVar_14547 = (cppVar_14547 & cppMask_un_16_);
	cppVar_14548 = ROM.rd(cppVar_14547);
	cppVar_14549 = (cppVar_14548 >> 3) & cppMask_un_5_;
	cppVar_14550 = (cppVar_14549 & cppMask_un_5_);
	cppVar_14551 = cppVar_14550 + 32;
	cppVar_14551 = (cppVar_14551 & cppMask_un_8_);
	cppVar_14538 = cppVar_14551;
	}
	cppVar_14553 = (cppVar_14538 == 144);
	if (cppVar_14553) {
	cppVar_14537 = P1;
	} else {
	cppVar_14556 = PC + 1;
	cppVar_14556 = (cppVar_14556 & cppMask_un_16_);
	cppVar_14557 = ROM.rd(cppVar_14556);
	cppVar_14558 = (cppVar_14557 >> 7) & cppMask_un_1_;
	cppVar_14559 = (cppVar_14558 == 1);
	if (cppVar_14559) {
	cppVar_14560 = PC + 1;
	cppVar_14560 = (cppVar_14560 & cppMask_un_16_);
	cppVar_14561 = ROM.rd(cppVar_14560);
	cppVar_14562 = (cppVar_14561 >> 3) & cppMask_un_5_;
	cppVar_14563 = (cppVar_14562 << 3) | 0;
	cppVar_14563 = (cppVar_14563 & cppMask_un_8_);
	cppVar_14555 = cppVar_14563;
	} else {
	cppVar_14564 = PC + 1;
	cppVar_14564 = (cppVar_14564 & cppMask_un_16_);
	cppVar_14565 = ROM.rd(cppVar_14564);
	cppVar_14566 = (cppVar_14565 >> 3) & cppMask_un_5_;
	cppVar_14567 = (cppVar_14566 & cppMask_un_5_);
	cppVar_14568 = cppVar_14567 + 32;
	cppVar_14568 = (cppVar_14568 & cppMask_un_8_);
	cppVar_14555 = cppVar_14568;
	}
	cppVar_14570 = (cppVar_14555 == 152);
	if (cppVar_14570) {
	cppVar_14554 = SCON;
	} else {
	cppVar_14573 = PC + 1;
	cppVar_14573 = (cppVar_14573 & cppMask_un_16_);
	cppVar_14574 = ROM.rd(cppVar_14573);
	cppVar_14575 = (cppVar_14574 >> 7) & cppMask_un_1_;
	cppVar_14576 = (cppVar_14575 == 1);
	if (cppVar_14576) {
	cppVar_14577 = PC + 1;
	cppVar_14577 = (cppVar_14577 & cppMask_un_16_);
	cppVar_14578 = ROM.rd(cppVar_14577);
	cppVar_14579 = (cppVar_14578 >> 3) & cppMask_un_5_;
	cppVar_14580 = (cppVar_14579 << 3) | 0;
	cppVar_14580 = (cppVar_14580 & cppMask_un_8_);
	cppVar_14572 = cppVar_14580;
	} else {
	cppVar_14581 = PC + 1;
	cppVar_14581 = (cppVar_14581 & cppMask_un_16_);
	cppVar_14582 = ROM.rd(cppVar_14581);
	cppVar_14583 = (cppVar_14582 >> 3) & cppMask_un_5_;
	cppVar_14584 = (cppVar_14583 & cppMask_un_5_);
	cppVar_14585 = cppVar_14584 + 32;
	cppVar_14585 = (cppVar_14585 & cppMask_un_8_);
	cppVar_14572 = cppVar_14585;
	}
	cppVar_14587 = (cppVar_14572 == 153);
	if (cppVar_14587) {
	cppVar_14571 = SBUF;
	} else {
	cppVar_14590 = PC + 1;
	cppVar_14590 = (cppVar_14590 & cppMask_un_16_);
	cppVar_14591 = ROM.rd(cppVar_14590);
	cppVar_14592 = (cppVar_14591 >> 7) & cppMask_un_1_;
	cppVar_14593 = (cppVar_14592 == 1);
	if (cppVar_14593) {
	cppVar_14594 = PC + 1;
	cppVar_14594 = (cppVar_14594 & cppMask_un_16_);
	cppVar_14595 = ROM.rd(cppVar_14594);
	cppVar_14596 = (cppVar_14595 >> 3) & cppMask_un_5_;
	cppVar_14597 = (cppVar_14596 << 3) | 0;
	cppVar_14597 = (cppVar_14597 & cppMask_un_8_);
	cppVar_14589 = cppVar_14597;
	} else {
	cppVar_14598 = PC + 1;
	cppVar_14598 = (cppVar_14598 & cppMask_un_16_);
	cppVar_14599 = ROM.rd(cppVar_14598);
	cppVar_14600 = (cppVar_14599 >> 3) & cppMask_un_5_;
	cppVar_14601 = (cppVar_14600 & cppMask_un_5_);
	cppVar_14602 = cppVar_14601 + 32;
	cppVar_14602 = (cppVar_14602 & cppMask_un_8_);
	cppVar_14589 = cppVar_14602;
	}
	cppVar_14604 = (cppVar_14589 == 160);
	if (cppVar_14604) {
	cppVar_14588 = P2;
	} else {
	cppVar_14607 = PC + 1;
	cppVar_14607 = (cppVar_14607 & cppMask_un_16_);
	cppVar_14608 = ROM.rd(cppVar_14607);
	cppVar_14609 = (cppVar_14608 >> 7) & cppMask_un_1_;
	cppVar_14610 = (cppVar_14609 == 1);
	if (cppVar_14610) {
	cppVar_14611 = PC + 1;
	cppVar_14611 = (cppVar_14611 & cppMask_un_16_);
	cppVar_14612 = ROM.rd(cppVar_14611);
	cppVar_14613 = (cppVar_14612 >> 3) & cppMask_un_5_;
	cppVar_14614 = (cppVar_14613 << 3) | 0;
	cppVar_14614 = (cppVar_14614 & cppMask_un_8_);
	cppVar_14606 = cppVar_14614;
	} else {
	cppVar_14615 = PC + 1;
	cppVar_14615 = (cppVar_14615 & cppMask_un_16_);
	cppVar_14616 = ROM.rd(cppVar_14615);
	cppVar_14617 = (cppVar_14616 >> 3) & cppMask_un_5_;
	cppVar_14618 = (cppVar_14617 & cppMask_un_5_);
	cppVar_14619 = cppVar_14618 + 32;
	cppVar_14619 = (cppVar_14619 & cppMask_un_8_);
	cppVar_14606 = cppVar_14619;
	}
	cppVar_14621 = (cppVar_14606 == 168);
	if (cppVar_14621) {
	cppVar_14605 = IE;
	} else {
	cppVar_14624 = PC + 1;
	cppVar_14624 = (cppVar_14624 & cppMask_un_16_);
	cppVar_14625 = ROM.rd(cppVar_14624);
	cppVar_14626 = (cppVar_14625 >> 7) & cppMask_un_1_;
	cppVar_14627 = (cppVar_14626 == 1);
	if (cppVar_14627) {
	cppVar_14628 = PC + 1;
	cppVar_14628 = (cppVar_14628 & cppMask_un_16_);
	cppVar_14629 = ROM.rd(cppVar_14628);
	cppVar_14630 = (cppVar_14629 >> 3) & cppMask_un_5_;
	cppVar_14631 = (cppVar_14630 << 3) | 0;
	cppVar_14631 = (cppVar_14631 & cppMask_un_8_);
	cppVar_14623 = cppVar_14631;
	} else {
	cppVar_14632 = PC + 1;
	cppVar_14632 = (cppVar_14632 & cppMask_un_16_);
	cppVar_14633 = ROM.rd(cppVar_14632);
	cppVar_14634 = (cppVar_14633 >> 3) & cppMask_un_5_;
	cppVar_14635 = (cppVar_14634 & cppMask_un_5_);
	cppVar_14636 = cppVar_14635 + 32;
	cppVar_14636 = (cppVar_14636 & cppMask_un_8_);
	cppVar_14623 = cppVar_14636;
	}
	cppVar_14638 = (cppVar_14623 == 176);
	if (cppVar_14638) {
	cppVar_14622 = P3;
	} else {
	cppVar_14641 = PC + 1;
	cppVar_14641 = (cppVar_14641 & cppMask_un_16_);
	cppVar_14642 = ROM.rd(cppVar_14641);
	cppVar_14643 = (cppVar_14642 >> 7) & cppMask_un_1_;
	cppVar_14644 = (cppVar_14643 == 1);
	if (cppVar_14644) {
	cppVar_14645 = PC + 1;
	cppVar_14645 = (cppVar_14645 & cppMask_un_16_);
	cppVar_14646 = ROM.rd(cppVar_14645);
	cppVar_14647 = (cppVar_14646 >> 3) & cppMask_un_5_;
	cppVar_14648 = (cppVar_14647 << 3) | 0;
	cppVar_14648 = (cppVar_14648 & cppMask_un_8_);
	cppVar_14640 = cppVar_14648;
	} else {
	cppVar_14649 = PC + 1;
	cppVar_14649 = (cppVar_14649 & cppMask_un_16_);
	cppVar_14650 = ROM.rd(cppVar_14649);
	cppVar_14651 = (cppVar_14650 >> 3) & cppMask_un_5_;
	cppVar_14652 = (cppVar_14651 & cppMask_un_5_);
	cppVar_14653 = cppVar_14652 + 32;
	cppVar_14653 = (cppVar_14653 & cppMask_un_8_);
	cppVar_14640 = cppVar_14653;
	}
	cppVar_14655 = (cppVar_14640 == 184);
	if (cppVar_14655) {
	cppVar_14639 = IP;
	} else {
	cppVar_14658 = PC + 1;
	cppVar_14658 = (cppVar_14658 & cppMask_un_16_);
	cppVar_14659 = ROM.rd(cppVar_14658);
	cppVar_14660 = (cppVar_14659 >> 7) & cppMask_un_1_;
	cppVar_14661 = (cppVar_14660 == 1);
	if (cppVar_14661) {
	cppVar_14662 = PC + 1;
	cppVar_14662 = (cppVar_14662 & cppMask_un_16_);
	cppVar_14663 = ROM.rd(cppVar_14662);
	cppVar_14664 = (cppVar_14663 >> 3) & cppMask_un_5_;
	cppVar_14665 = (cppVar_14664 << 3) | 0;
	cppVar_14665 = (cppVar_14665 & cppMask_un_8_);
	cppVar_14657 = cppVar_14665;
	} else {
	cppVar_14666 = PC + 1;
	cppVar_14666 = (cppVar_14666 & cppMask_un_16_);
	cppVar_14667 = ROM.rd(cppVar_14666);
	cppVar_14668 = (cppVar_14667 >> 3) & cppMask_un_5_;
	cppVar_14669 = (cppVar_14668 & cppMask_un_5_);
	cppVar_14670 = cppVar_14669 + 32;
	cppVar_14670 = (cppVar_14670 & cppMask_un_8_);
	cppVar_14657 = cppVar_14670;
	}
	cppVar_14672 = (cppVar_14657 == 208);
	if (cppVar_14672) {
	cppVar_14656 = PSW;
	} else {
	cppVar_14675 = PC + 1;
	cppVar_14675 = (cppVar_14675 & cppMask_un_16_);
	cppVar_14676 = ROM.rd(cppVar_14675);
	cppVar_14677 = (cppVar_14676 >> 7) & cppMask_un_1_;
	cppVar_14678 = (cppVar_14677 == 1);
	if (cppVar_14678) {
	cppVar_14679 = PC + 1;
	cppVar_14679 = (cppVar_14679 & cppMask_un_16_);
	cppVar_14680 = ROM.rd(cppVar_14679);
	cppVar_14681 = (cppVar_14680 >> 3) & cppMask_un_5_;
	cppVar_14682 = (cppVar_14681 << 3) | 0;
	cppVar_14682 = (cppVar_14682 & cppMask_un_8_);
	cppVar_14674 = cppVar_14682;
	} else {
	cppVar_14683 = PC + 1;
	cppVar_14683 = (cppVar_14683 & cppMask_un_16_);
	cppVar_14684 = ROM.rd(cppVar_14683);
	cppVar_14685 = (cppVar_14684 >> 3) & cppMask_un_5_;
	cppVar_14686 = (cppVar_14685 & cppMask_un_5_);
	cppVar_14687 = cppVar_14686 + 32;
	cppVar_14687 = (cppVar_14687 & cppMask_un_8_);
	cppVar_14674 = cppVar_14687;
	}
	cppVar_14689 = (cppVar_14674 == 224);
	if (cppVar_14689) {
	cppVar_14673 = ACC;
	} else {
	cppVar_14692 = PC + 1;
	cppVar_14692 = (cppVar_14692 & cppMask_un_16_);
	cppVar_14693 = ROM.rd(cppVar_14692);
	cppVar_14694 = (cppVar_14693 >> 7) & cppMask_un_1_;
	cppVar_14695 = (cppVar_14694 == 1);
	if (cppVar_14695) {
	cppVar_14696 = PC + 1;
	cppVar_14696 = (cppVar_14696 & cppMask_un_16_);
	cppVar_14697 = ROM.rd(cppVar_14696);
	cppVar_14698 = (cppVar_14697 >> 3) & cppMask_un_5_;
	cppVar_14699 = (cppVar_14698 << 3) | 0;
	cppVar_14699 = (cppVar_14699 & cppMask_un_8_);
	cppVar_14691 = cppVar_14699;
	} else {
	cppVar_14700 = PC + 1;
	cppVar_14700 = (cppVar_14700 & cppMask_un_16_);
	cppVar_14701 = ROM.rd(cppVar_14700);
	cppVar_14702 = (cppVar_14701 >> 3) & cppMask_un_5_;
	cppVar_14703 = (cppVar_14702 & cppMask_un_5_);
	cppVar_14704 = cppVar_14703 + 32;
	cppVar_14704 = (cppVar_14704 & cppMask_un_8_);
	cppVar_14691 = cppVar_14704;
	}
	cppVar_14706 = (cppVar_14691 == 240);
	if (cppVar_14706) {
	cppVar_14690 = B;
	} else {
	cppVar_14690 = 0;
	}
	cppVar_14673 = cppVar_14690;
	}
	cppVar_14656 = cppVar_14673;
	}
	cppVar_14639 = cppVar_14656;
	}
	cppVar_14622 = cppVar_14639;
	}
	cppVar_14605 = cppVar_14622;
	}
	cppVar_14588 = cppVar_14605;
	}
	cppVar_14571 = cppVar_14588;
	}
	cppVar_14554 = cppVar_14571;
	}
	cppVar_14537 = cppVar_14554;
	}
	cppVar_14520 = cppVar_14537;
	}
	cppVar_14503 = cppVar_14520;
	}
	cppVar_14486 = cppVar_14503;
	}
	cppVar_14469 = cppVar_14486;
	}
	cppVar_14452 = cppVar_14469;
	}
	cppVar_14435 = cppVar_14452;
	}
	cppVar_14418 = cppVar_14435;
	}
	cppVar_14401 = cppVar_14418;
	}
	cppVar_14384 = cppVar_14401;
	}
	cppVar_14367 = cppVar_14384;
	}
	cppVar_14350 = cppVar_14367;
	}
	cppVar_14314 = cppVar_14350;
	}
	cppVar_14708 = PC + 1;
	cppVar_14708 = (cppVar_14708 & cppMask_un_16_);
	cppVar_14709 = ROM.rd(cppVar_14708);
	cppVar_14710 = (cppVar_14709 >> 0) & cppMask_un_3_;
	cppVar_14711 = (cppVar_14314 >> static_cast<unsigned>(cppVar_14710)) & 0x1;
	cppVar_14712 = ~cppVar_14711;
	cppVar_14713 = (cppVar_14712 & cppMask_un_1_);
	cppVar_14714 = PC + 1;
	cppVar_14714 = (cppVar_14714 & cppMask_un_16_);
	cppVar_14715 = ROM.rd(cppVar_14714);
	cppVar_14716 = (cppVar_14715 >> 0) & cppMask_un_3_;
	cppVar_14717 = (cppVar_14716 & cppMask_un_3_);
	cppVar_14718 = cppVar_14713 << static_cast<unsigned>(cppVar_14717);
	cppVar_14718 = (cppVar_14718 & cppMask_un_8_);
	cppVar_14719 = cppVar_14313 | cppVar_14718;
	cppVar_13894 = cppVar_14719;
	} else {
	cppVar_13894 = IE;
	}
	cppVar_13890 = cppVar_13894;
	} else {
	cppVar_14721 = ROM.rd(PC);
	cppVar_14723 = (cppVar_14721 == 146);
	if (cppVar_14723) {
	cppVar_14727 = PC + 1;
	cppVar_14727 = (cppVar_14727 & cppMask_un_16_);
	cppVar_14728 = ROM.rd(cppVar_14727);
	cppVar_14729 = (cppVar_14728 >> 7) & cppMask_un_1_;
	cppVar_14731 = (cppVar_14729 == 1);
	if (cppVar_14731) {
	cppVar_14732 = PC + 1;
	cppVar_14732 = (cppVar_14732 & cppMask_un_16_);
	cppVar_14733 = ROM.rd(cppVar_14732);
	cppVar_14734 = (cppVar_14733 >> 3) & cppMask_un_5_;
	cppVar_14736 = (cppVar_14734 << 3) | 0;
	cppVar_14736 = (cppVar_14736 & cppMask_un_8_);
	cppVar_14725 = cppVar_14736;
	} else {
	cppVar_14737 = PC + 1;
	cppVar_14737 = (cppVar_14737 & cppMask_un_16_);
	cppVar_14738 = ROM.rd(cppVar_14737);
	cppVar_14739 = (cppVar_14738 >> 3) & cppMask_un_5_;
	cppVar_14740 = (cppVar_14739 & cppMask_un_5_);
	cppVar_14742 = cppVar_14740 + 32;
	cppVar_14742 = (cppVar_14742 & cppMask_un_8_);
	cppVar_14725 = cppVar_14742;
	}
	cppVar_14744 = (cppVar_14725 == 168);
	if (cppVar_14744) {
	cppVar_14746 = PC + 1;
	cppVar_14746 = (cppVar_14746 & cppMask_un_16_);
	cppVar_14747 = ROM.rd(cppVar_14746);
	cppVar_14748 = (cppVar_14747 >> 0) & cppMask_un_3_;
	cppVar_14749 = (cppVar_14748 & cppMask_un_3_);
	cppVar_14750 = 1 << static_cast<unsigned>(cppVar_14749);
	cppVar_14750 = (cppVar_14750 & cppMask_un_8_);
	cppVar_14751 = ~cppVar_14750;
	cppVar_14754 = PC + 1;
	cppVar_14754 = (cppVar_14754 & cppMask_un_16_);
	cppVar_14755 = ROM.rd(cppVar_14754);
	cppVar_14756 = (cppVar_14755 >> 7) & cppMask_un_1_;
	cppVar_14757 = (cppVar_14756 == 1);
	if (cppVar_14757) {
	cppVar_14758 = PC + 1;
	cppVar_14758 = (cppVar_14758 & cppMask_un_16_);
	cppVar_14759 = ROM.rd(cppVar_14758);
	cppVar_14760 = (cppVar_14759 >> 3) & cppMask_un_5_;
	cppVar_14761 = (cppVar_14760 << 3) | 0;
	cppVar_14761 = (cppVar_14761 & cppMask_un_8_);
	cppVar_14753 = cppVar_14761;
	} else {
	cppVar_14762 = PC + 1;
	cppVar_14762 = (cppVar_14762 & cppMask_un_16_);
	cppVar_14763 = ROM.rd(cppVar_14762);
	cppVar_14764 = (cppVar_14763 >> 3) & cppMask_un_5_;
	cppVar_14765 = (cppVar_14764 & cppMask_un_5_);
	cppVar_14766 = cppVar_14765 + 32;
	cppVar_14766 = (cppVar_14766 & cppMask_un_8_);
	cppVar_14753 = cppVar_14766;
	}
	cppVar_14767 = (cppVar_14753 >> 7) & cppMask_un_1_;
	cppVar_14769 = (cppVar_14767 == 0);
	if (cppVar_14769) {
	cppVar_14771 = PC + 1;
	cppVar_14771 = (cppVar_14771 & cppMask_un_16_);
	cppVar_14772 = ROM.rd(cppVar_14771);
	cppVar_14773 = (cppVar_14772 >> 7) & cppMask_un_1_;
	cppVar_14774 = (cppVar_14773 == 1);
	if (cppVar_14774) {
	cppVar_14775 = PC + 1;
	cppVar_14775 = (cppVar_14775 & cppMask_un_16_);
	cppVar_14776 = ROM.rd(cppVar_14775);
	cppVar_14777 = (cppVar_14776 >> 3) & cppMask_un_5_;
	cppVar_14778 = (cppVar_14777 << 3) | 0;
	cppVar_14778 = (cppVar_14778 & cppMask_un_8_);
	cppVar_14770 = cppVar_14778;
	} else {
	cppVar_14779 = PC + 1;
	cppVar_14779 = (cppVar_14779 & cppMask_un_16_);
	cppVar_14780 = ROM.rd(cppVar_14779);
	cppVar_14781 = (cppVar_14780 >> 3) & cppMask_un_5_;
	cppVar_14782 = (cppVar_14781 & cppMask_un_5_);
	cppVar_14783 = cppVar_14782 + 32;
	cppVar_14783 = (cppVar_14783 & cppMask_un_8_);
	cppVar_14770 = cppVar_14783;
	}
	cppVar_14784 = IRAM.rd(cppVar_14770);
	cppVar_14752 = cppVar_14784;
	} else {
	cppVar_14787 = PC + 1;
	cppVar_14787 = (cppVar_14787 & cppMask_un_16_);
	cppVar_14788 = ROM.rd(cppVar_14787);
	cppVar_14789 = (cppVar_14788 >> 7) & cppMask_un_1_;
	cppVar_14790 = (cppVar_14789 == 1);
	if (cppVar_14790) {
	cppVar_14791 = PC + 1;
	cppVar_14791 = (cppVar_14791 & cppMask_un_16_);
	cppVar_14792 = ROM.rd(cppVar_14791);
	cppVar_14793 = (cppVar_14792 >> 3) & cppMask_un_5_;
	cppVar_14794 = (cppVar_14793 << 3) | 0;
	cppVar_14794 = (cppVar_14794 & cppMask_un_8_);
	cppVar_14786 = cppVar_14794;
	} else {
	cppVar_14795 = PC + 1;
	cppVar_14795 = (cppVar_14795 & cppMask_un_16_);
	cppVar_14796 = ROM.rd(cppVar_14795);
	cppVar_14797 = (cppVar_14796 >> 3) & cppMask_un_5_;
	cppVar_14798 = (cppVar_14797 & cppMask_un_5_);
	cppVar_14799 = cppVar_14798 + 32;
	cppVar_14799 = (cppVar_14799 & cppMask_un_8_);
	cppVar_14786 = cppVar_14799;
	}
	cppVar_14801 = (cppVar_14786 == 128);
	if (cppVar_14801) {
	cppVar_14785 = P0;
	} else {
	cppVar_14804 = PC + 1;
	cppVar_14804 = (cppVar_14804 & cppMask_un_16_);
	cppVar_14805 = ROM.rd(cppVar_14804);
	cppVar_14806 = (cppVar_14805 >> 7) & cppMask_un_1_;
	cppVar_14807 = (cppVar_14806 == 1);
	if (cppVar_14807) {
	cppVar_14808 = PC + 1;
	cppVar_14808 = (cppVar_14808 & cppMask_un_16_);
	cppVar_14809 = ROM.rd(cppVar_14808);
	cppVar_14810 = (cppVar_14809 >> 3) & cppMask_un_5_;
	cppVar_14811 = (cppVar_14810 << 3) | 0;
	cppVar_14811 = (cppVar_14811 & cppMask_un_8_);
	cppVar_14803 = cppVar_14811;
	} else {
	cppVar_14812 = PC + 1;
	cppVar_14812 = (cppVar_14812 & cppMask_un_16_);
	cppVar_14813 = ROM.rd(cppVar_14812);
	cppVar_14814 = (cppVar_14813 >> 3) & cppMask_un_5_;
	cppVar_14815 = (cppVar_14814 & cppMask_un_5_);
	cppVar_14816 = cppVar_14815 + 32;
	cppVar_14816 = (cppVar_14816 & cppMask_un_8_);
	cppVar_14803 = cppVar_14816;
	}
	cppVar_14818 = (cppVar_14803 == 129);
	if (cppVar_14818) {
	cppVar_14802 = SP;
	} else {
	cppVar_14821 = PC + 1;
	cppVar_14821 = (cppVar_14821 & cppMask_un_16_);
	cppVar_14822 = ROM.rd(cppVar_14821);
	cppVar_14823 = (cppVar_14822 >> 7) & cppMask_un_1_;
	cppVar_14824 = (cppVar_14823 == 1);
	if (cppVar_14824) {
	cppVar_14825 = PC + 1;
	cppVar_14825 = (cppVar_14825 & cppMask_un_16_);
	cppVar_14826 = ROM.rd(cppVar_14825);
	cppVar_14827 = (cppVar_14826 >> 3) & cppMask_un_5_;
	cppVar_14828 = (cppVar_14827 << 3) | 0;
	cppVar_14828 = (cppVar_14828 & cppMask_un_8_);
	cppVar_14820 = cppVar_14828;
	} else {
	cppVar_14829 = PC + 1;
	cppVar_14829 = (cppVar_14829 & cppMask_un_16_);
	cppVar_14830 = ROM.rd(cppVar_14829);
	cppVar_14831 = (cppVar_14830 >> 3) & cppMask_un_5_;
	cppVar_14832 = (cppVar_14831 & cppMask_un_5_);
	cppVar_14833 = cppVar_14832 + 32;
	cppVar_14833 = (cppVar_14833 & cppMask_un_8_);
	cppVar_14820 = cppVar_14833;
	}
	cppVar_14835 = (cppVar_14820 == 130);
	if (cppVar_14835) {
	cppVar_14819 = DPL;
	} else {
	cppVar_14838 = PC + 1;
	cppVar_14838 = (cppVar_14838 & cppMask_un_16_);
	cppVar_14839 = ROM.rd(cppVar_14838);
	cppVar_14840 = (cppVar_14839 >> 7) & cppMask_un_1_;
	cppVar_14841 = (cppVar_14840 == 1);
	if (cppVar_14841) {
	cppVar_14842 = PC + 1;
	cppVar_14842 = (cppVar_14842 & cppMask_un_16_);
	cppVar_14843 = ROM.rd(cppVar_14842);
	cppVar_14844 = (cppVar_14843 >> 3) & cppMask_un_5_;
	cppVar_14845 = (cppVar_14844 << 3) | 0;
	cppVar_14845 = (cppVar_14845 & cppMask_un_8_);
	cppVar_14837 = cppVar_14845;
	} else {
	cppVar_14846 = PC + 1;
	cppVar_14846 = (cppVar_14846 & cppMask_un_16_);
	cppVar_14847 = ROM.rd(cppVar_14846);
	cppVar_14848 = (cppVar_14847 >> 3) & cppMask_un_5_;
	cppVar_14849 = (cppVar_14848 & cppMask_un_5_);
	cppVar_14850 = cppVar_14849 + 32;
	cppVar_14850 = (cppVar_14850 & cppMask_un_8_);
	cppVar_14837 = cppVar_14850;
	}
	cppVar_14852 = (cppVar_14837 == 131);
	if (cppVar_14852) {
	cppVar_14836 = DPH;
	} else {
	cppVar_14855 = PC + 1;
	cppVar_14855 = (cppVar_14855 & cppMask_un_16_);
	cppVar_14856 = ROM.rd(cppVar_14855);
	cppVar_14857 = (cppVar_14856 >> 7) & cppMask_un_1_;
	cppVar_14858 = (cppVar_14857 == 1);
	if (cppVar_14858) {
	cppVar_14859 = PC + 1;
	cppVar_14859 = (cppVar_14859 & cppMask_un_16_);
	cppVar_14860 = ROM.rd(cppVar_14859);
	cppVar_14861 = (cppVar_14860 >> 3) & cppMask_un_5_;
	cppVar_14862 = (cppVar_14861 << 3) | 0;
	cppVar_14862 = (cppVar_14862 & cppMask_un_8_);
	cppVar_14854 = cppVar_14862;
	} else {
	cppVar_14863 = PC + 1;
	cppVar_14863 = (cppVar_14863 & cppMask_un_16_);
	cppVar_14864 = ROM.rd(cppVar_14863);
	cppVar_14865 = (cppVar_14864 >> 3) & cppMask_un_5_;
	cppVar_14866 = (cppVar_14865 & cppMask_un_5_);
	cppVar_14867 = cppVar_14866 + 32;
	cppVar_14867 = (cppVar_14867 & cppMask_un_8_);
	cppVar_14854 = cppVar_14867;
	}
	cppVar_14869 = (cppVar_14854 == 135);
	if (cppVar_14869) {
	cppVar_14853 = PCON;
	} else {
	cppVar_14872 = PC + 1;
	cppVar_14872 = (cppVar_14872 & cppMask_un_16_);
	cppVar_14873 = ROM.rd(cppVar_14872);
	cppVar_14874 = (cppVar_14873 >> 7) & cppMask_un_1_;
	cppVar_14875 = (cppVar_14874 == 1);
	if (cppVar_14875) {
	cppVar_14876 = PC + 1;
	cppVar_14876 = (cppVar_14876 & cppMask_un_16_);
	cppVar_14877 = ROM.rd(cppVar_14876);
	cppVar_14878 = (cppVar_14877 >> 3) & cppMask_un_5_;
	cppVar_14879 = (cppVar_14878 << 3) | 0;
	cppVar_14879 = (cppVar_14879 & cppMask_un_8_);
	cppVar_14871 = cppVar_14879;
	} else {
	cppVar_14880 = PC + 1;
	cppVar_14880 = (cppVar_14880 & cppMask_un_16_);
	cppVar_14881 = ROM.rd(cppVar_14880);
	cppVar_14882 = (cppVar_14881 >> 3) & cppMask_un_5_;
	cppVar_14883 = (cppVar_14882 & cppMask_un_5_);
	cppVar_14884 = cppVar_14883 + 32;
	cppVar_14884 = (cppVar_14884 & cppMask_un_8_);
	cppVar_14871 = cppVar_14884;
	}
	cppVar_14886 = (cppVar_14871 == 136);
	if (cppVar_14886) {
	cppVar_14870 = TCON;
	} else {
	cppVar_14889 = PC + 1;
	cppVar_14889 = (cppVar_14889 & cppMask_un_16_);
	cppVar_14890 = ROM.rd(cppVar_14889);
	cppVar_14891 = (cppVar_14890 >> 7) & cppMask_un_1_;
	cppVar_14892 = (cppVar_14891 == 1);
	if (cppVar_14892) {
	cppVar_14893 = PC + 1;
	cppVar_14893 = (cppVar_14893 & cppMask_un_16_);
	cppVar_14894 = ROM.rd(cppVar_14893);
	cppVar_14895 = (cppVar_14894 >> 3) & cppMask_un_5_;
	cppVar_14896 = (cppVar_14895 << 3) | 0;
	cppVar_14896 = (cppVar_14896 & cppMask_un_8_);
	cppVar_14888 = cppVar_14896;
	} else {
	cppVar_14897 = PC + 1;
	cppVar_14897 = (cppVar_14897 & cppMask_un_16_);
	cppVar_14898 = ROM.rd(cppVar_14897);
	cppVar_14899 = (cppVar_14898 >> 3) & cppMask_un_5_;
	cppVar_14900 = (cppVar_14899 & cppMask_un_5_);
	cppVar_14901 = cppVar_14900 + 32;
	cppVar_14901 = (cppVar_14901 & cppMask_un_8_);
	cppVar_14888 = cppVar_14901;
	}
	cppVar_14903 = (cppVar_14888 == 137);
	if (cppVar_14903) {
	cppVar_14887 = TMOD;
	} else {
	cppVar_14906 = PC + 1;
	cppVar_14906 = (cppVar_14906 & cppMask_un_16_);
	cppVar_14907 = ROM.rd(cppVar_14906);
	cppVar_14908 = (cppVar_14907 >> 7) & cppMask_un_1_;
	cppVar_14909 = (cppVar_14908 == 1);
	if (cppVar_14909) {
	cppVar_14910 = PC + 1;
	cppVar_14910 = (cppVar_14910 & cppMask_un_16_);
	cppVar_14911 = ROM.rd(cppVar_14910);
	cppVar_14912 = (cppVar_14911 >> 3) & cppMask_un_5_;
	cppVar_14913 = (cppVar_14912 << 3) | 0;
	cppVar_14913 = (cppVar_14913 & cppMask_un_8_);
	cppVar_14905 = cppVar_14913;
	} else {
	cppVar_14914 = PC + 1;
	cppVar_14914 = (cppVar_14914 & cppMask_un_16_);
	cppVar_14915 = ROM.rd(cppVar_14914);
	cppVar_14916 = (cppVar_14915 >> 3) & cppMask_un_5_;
	cppVar_14917 = (cppVar_14916 & cppMask_un_5_);
	cppVar_14918 = cppVar_14917 + 32;
	cppVar_14918 = (cppVar_14918 & cppMask_un_8_);
	cppVar_14905 = cppVar_14918;
	}
	cppVar_14920 = (cppVar_14905 == 138);
	if (cppVar_14920) {
	cppVar_14904 = TL0;
	} else {
	cppVar_14923 = PC + 1;
	cppVar_14923 = (cppVar_14923 & cppMask_un_16_);
	cppVar_14924 = ROM.rd(cppVar_14923);
	cppVar_14925 = (cppVar_14924 >> 7) & cppMask_un_1_;
	cppVar_14926 = (cppVar_14925 == 1);
	if (cppVar_14926) {
	cppVar_14927 = PC + 1;
	cppVar_14927 = (cppVar_14927 & cppMask_un_16_);
	cppVar_14928 = ROM.rd(cppVar_14927);
	cppVar_14929 = (cppVar_14928 >> 3) & cppMask_un_5_;
	cppVar_14930 = (cppVar_14929 << 3) | 0;
	cppVar_14930 = (cppVar_14930 & cppMask_un_8_);
	cppVar_14922 = cppVar_14930;
	} else {
	cppVar_14931 = PC + 1;
	cppVar_14931 = (cppVar_14931 & cppMask_un_16_);
	cppVar_14932 = ROM.rd(cppVar_14931);
	cppVar_14933 = (cppVar_14932 >> 3) & cppMask_un_5_;
	cppVar_14934 = (cppVar_14933 & cppMask_un_5_);
	cppVar_14935 = cppVar_14934 + 32;
	cppVar_14935 = (cppVar_14935 & cppMask_un_8_);
	cppVar_14922 = cppVar_14935;
	}
	cppVar_14937 = (cppVar_14922 == 140);
	if (cppVar_14937) {
	cppVar_14921 = TH0;
	} else {
	cppVar_14940 = PC + 1;
	cppVar_14940 = (cppVar_14940 & cppMask_un_16_);
	cppVar_14941 = ROM.rd(cppVar_14940);
	cppVar_14942 = (cppVar_14941 >> 7) & cppMask_un_1_;
	cppVar_14943 = (cppVar_14942 == 1);
	if (cppVar_14943) {
	cppVar_14944 = PC + 1;
	cppVar_14944 = (cppVar_14944 & cppMask_un_16_);
	cppVar_14945 = ROM.rd(cppVar_14944);
	cppVar_14946 = (cppVar_14945 >> 3) & cppMask_un_5_;
	cppVar_14947 = (cppVar_14946 << 3) | 0;
	cppVar_14947 = (cppVar_14947 & cppMask_un_8_);
	cppVar_14939 = cppVar_14947;
	} else {
	cppVar_14948 = PC + 1;
	cppVar_14948 = (cppVar_14948 & cppMask_un_16_);
	cppVar_14949 = ROM.rd(cppVar_14948);
	cppVar_14950 = (cppVar_14949 >> 3) & cppMask_un_5_;
	cppVar_14951 = (cppVar_14950 & cppMask_un_5_);
	cppVar_14952 = cppVar_14951 + 32;
	cppVar_14952 = (cppVar_14952 & cppMask_un_8_);
	cppVar_14939 = cppVar_14952;
	}
	cppVar_14954 = (cppVar_14939 == 139);
	if (cppVar_14954) {
	cppVar_14938 = TL1;
	} else {
	cppVar_14957 = PC + 1;
	cppVar_14957 = (cppVar_14957 & cppMask_un_16_);
	cppVar_14958 = ROM.rd(cppVar_14957);
	cppVar_14959 = (cppVar_14958 >> 7) & cppMask_un_1_;
	cppVar_14960 = (cppVar_14959 == 1);
	if (cppVar_14960) {
	cppVar_14961 = PC + 1;
	cppVar_14961 = (cppVar_14961 & cppMask_un_16_);
	cppVar_14962 = ROM.rd(cppVar_14961);
	cppVar_14963 = (cppVar_14962 >> 3) & cppMask_un_5_;
	cppVar_14964 = (cppVar_14963 << 3) | 0;
	cppVar_14964 = (cppVar_14964 & cppMask_un_8_);
	cppVar_14956 = cppVar_14964;
	} else {
	cppVar_14965 = PC + 1;
	cppVar_14965 = (cppVar_14965 & cppMask_un_16_);
	cppVar_14966 = ROM.rd(cppVar_14965);
	cppVar_14967 = (cppVar_14966 >> 3) & cppMask_un_5_;
	cppVar_14968 = (cppVar_14967 & cppMask_un_5_);
	cppVar_14969 = cppVar_14968 + 32;
	cppVar_14969 = (cppVar_14969 & cppMask_un_8_);
	cppVar_14956 = cppVar_14969;
	}
	cppVar_14971 = (cppVar_14956 == 141);
	if (cppVar_14971) {
	cppVar_14955 = TH1;
	} else {
	cppVar_14974 = PC + 1;
	cppVar_14974 = (cppVar_14974 & cppMask_un_16_);
	cppVar_14975 = ROM.rd(cppVar_14974);
	cppVar_14976 = (cppVar_14975 >> 7) & cppMask_un_1_;
	cppVar_14977 = (cppVar_14976 == 1);
	if (cppVar_14977) {
	cppVar_14978 = PC + 1;
	cppVar_14978 = (cppVar_14978 & cppMask_un_16_);
	cppVar_14979 = ROM.rd(cppVar_14978);
	cppVar_14980 = (cppVar_14979 >> 3) & cppMask_un_5_;
	cppVar_14981 = (cppVar_14980 << 3) | 0;
	cppVar_14981 = (cppVar_14981 & cppMask_un_8_);
	cppVar_14973 = cppVar_14981;
	} else {
	cppVar_14982 = PC + 1;
	cppVar_14982 = (cppVar_14982 & cppMask_un_16_);
	cppVar_14983 = ROM.rd(cppVar_14982);
	cppVar_14984 = (cppVar_14983 >> 3) & cppMask_un_5_;
	cppVar_14985 = (cppVar_14984 & cppMask_un_5_);
	cppVar_14986 = cppVar_14985 + 32;
	cppVar_14986 = (cppVar_14986 & cppMask_un_8_);
	cppVar_14973 = cppVar_14986;
	}
	cppVar_14988 = (cppVar_14973 == 144);
	if (cppVar_14988) {
	cppVar_14972 = P1;
	} else {
	cppVar_14991 = PC + 1;
	cppVar_14991 = (cppVar_14991 & cppMask_un_16_);
	cppVar_14992 = ROM.rd(cppVar_14991);
	cppVar_14993 = (cppVar_14992 >> 7) & cppMask_un_1_;
	cppVar_14994 = (cppVar_14993 == 1);
	if (cppVar_14994) {
	cppVar_14995 = PC + 1;
	cppVar_14995 = (cppVar_14995 & cppMask_un_16_);
	cppVar_14996 = ROM.rd(cppVar_14995);
	cppVar_14997 = (cppVar_14996 >> 3) & cppMask_un_5_;
	cppVar_14998 = (cppVar_14997 << 3) | 0;
	cppVar_14998 = (cppVar_14998 & cppMask_un_8_);
	cppVar_14990 = cppVar_14998;
	} else {
	cppVar_14999 = PC + 1;
	cppVar_14999 = (cppVar_14999 & cppMask_un_16_);
	cppVar_15000 = ROM.rd(cppVar_14999);
	cppVar_15001 = (cppVar_15000 >> 3) & cppMask_un_5_;
	cppVar_15002 = (cppVar_15001 & cppMask_un_5_);
	cppVar_15003 = cppVar_15002 + 32;
	cppVar_15003 = (cppVar_15003 & cppMask_un_8_);
	cppVar_14990 = cppVar_15003;
	}
	cppVar_15005 = (cppVar_14990 == 152);
	if (cppVar_15005) {
	cppVar_14989 = SCON;
	} else {
	cppVar_15008 = PC + 1;
	cppVar_15008 = (cppVar_15008 & cppMask_un_16_);
	cppVar_15009 = ROM.rd(cppVar_15008);
	cppVar_15010 = (cppVar_15009 >> 7) & cppMask_un_1_;
	cppVar_15011 = (cppVar_15010 == 1);
	if (cppVar_15011) {
	cppVar_15012 = PC + 1;
	cppVar_15012 = (cppVar_15012 & cppMask_un_16_);
	cppVar_15013 = ROM.rd(cppVar_15012);
	cppVar_15014 = (cppVar_15013 >> 3) & cppMask_un_5_;
	cppVar_15015 = (cppVar_15014 << 3) | 0;
	cppVar_15015 = (cppVar_15015 & cppMask_un_8_);
	cppVar_15007 = cppVar_15015;
	} else {
	cppVar_15016 = PC + 1;
	cppVar_15016 = (cppVar_15016 & cppMask_un_16_);
	cppVar_15017 = ROM.rd(cppVar_15016);
	cppVar_15018 = (cppVar_15017 >> 3) & cppMask_un_5_;
	cppVar_15019 = (cppVar_15018 & cppMask_un_5_);
	cppVar_15020 = cppVar_15019 + 32;
	cppVar_15020 = (cppVar_15020 & cppMask_un_8_);
	cppVar_15007 = cppVar_15020;
	}
	cppVar_15022 = (cppVar_15007 == 153);
	if (cppVar_15022) {
	cppVar_15006 = SBUF;
	} else {
	cppVar_15025 = PC + 1;
	cppVar_15025 = (cppVar_15025 & cppMask_un_16_);
	cppVar_15026 = ROM.rd(cppVar_15025);
	cppVar_15027 = (cppVar_15026 >> 7) & cppMask_un_1_;
	cppVar_15028 = (cppVar_15027 == 1);
	if (cppVar_15028) {
	cppVar_15029 = PC + 1;
	cppVar_15029 = (cppVar_15029 & cppMask_un_16_);
	cppVar_15030 = ROM.rd(cppVar_15029);
	cppVar_15031 = (cppVar_15030 >> 3) & cppMask_un_5_;
	cppVar_15032 = (cppVar_15031 << 3) | 0;
	cppVar_15032 = (cppVar_15032 & cppMask_un_8_);
	cppVar_15024 = cppVar_15032;
	} else {
	cppVar_15033 = PC + 1;
	cppVar_15033 = (cppVar_15033 & cppMask_un_16_);
	cppVar_15034 = ROM.rd(cppVar_15033);
	cppVar_15035 = (cppVar_15034 >> 3) & cppMask_un_5_;
	cppVar_15036 = (cppVar_15035 & cppMask_un_5_);
	cppVar_15037 = cppVar_15036 + 32;
	cppVar_15037 = (cppVar_15037 & cppMask_un_8_);
	cppVar_15024 = cppVar_15037;
	}
	cppVar_15039 = (cppVar_15024 == 160);
	if (cppVar_15039) {
	cppVar_15023 = P2;
	} else {
	cppVar_15042 = PC + 1;
	cppVar_15042 = (cppVar_15042 & cppMask_un_16_);
	cppVar_15043 = ROM.rd(cppVar_15042);
	cppVar_15044 = (cppVar_15043 >> 7) & cppMask_un_1_;
	cppVar_15045 = (cppVar_15044 == 1);
	if (cppVar_15045) {
	cppVar_15046 = PC + 1;
	cppVar_15046 = (cppVar_15046 & cppMask_un_16_);
	cppVar_15047 = ROM.rd(cppVar_15046);
	cppVar_15048 = (cppVar_15047 >> 3) & cppMask_un_5_;
	cppVar_15049 = (cppVar_15048 << 3) | 0;
	cppVar_15049 = (cppVar_15049 & cppMask_un_8_);
	cppVar_15041 = cppVar_15049;
	} else {
	cppVar_15050 = PC + 1;
	cppVar_15050 = (cppVar_15050 & cppMask_un_16_);
	cppVar_15051 = ROM.rd(cppVar_15050);
	cppVar_15052 = (cppVar_15051 >> 3) & cppMask_un_5_;
	cppVar_15053 = (cppVar_15052 & cppMask_un_5_);
	cppVar_15054 = cppVar_15053 + 32;
	cppVar_15054 = (cppVar_15054 & cppMask_un_8_);
	cppVar_15041 = cppVar_15054;
	}
	cppVar_15056 = (cppVar_15041 == 168);
	if (cppVar_15056) {
	cppVar_15040 = IE;
	} else {
	cppVar_15059 = PC + 1;
	cppVar_15059 = (cppVar_15059 & cppMask_un_16_);
	cppVar_15060 = ROM.rd(cppVar_15059);
	cppVar_15061 = (cppVar_15060 >> 7) & cppMask_un_1_;
	cppVar_15062 = (cppVar_15061 == 1);
	if (cppVar_15062) {
	cppVar_15063 = PC + 1;
	cppVar_15063 = (cppVar_15063 & cppMask_un_16_);
	cppVar_15064 = ROM.rd(cppVar_15063);
	cppVar_15065 = (cppVar_15064 >> 3) & cppMask_un_5_;
	cppVar_15066 = (cppVar_15065 << 3) | 0;
	cppVar_15066 = (cppVar_15066 & cppMask_un_8_);
	cppVar_15058 = cppVar_15066;
	} else {
	cppVar_15067 = PC + 1;
	cppVar_15067 = (cppVar_15067 & cppMask_un_16_);
	cppVar_15068 = ROM.rd(cppVar_15067);
	cppVar_15069 = (cppVar_15068 >> 3) & cppMask_un_5_;
	cppVar_15070 = (cppVar_15069 & cppMask_un_5_);
	cppVar_15071 = cppVar_15070 + 32;
	cppVar_15071 = (cppVar_15071 & cppMask_un_8_);
	cppVar_15058 = cppVar_15071;
	}
	cppVar_15073 = (cppVar_15058 == 176);
	if (cppVar_15073) {
	cppVar_15057 = P3;
	} else {
	cppVar_15076 = PC + 1;
	cppVar_15076 = (cppVar_15076 & cppMask_un_16_);
	cppVar_15077 = ROM.rd(cppVar_15076);
	cppVar_15078 = (cppVar_15077 >> 7) & cppMask_un_1_;
	cppVar_15079 = (cppVar_15078 == 1);
	if (cppVar_15079) {
	cppVar_15080 = PC + 1;
	cppVar_15080 = (cppVar_15080 & cppMask_un_16_);
	cppVar_15081 = ROM.rd(cppVar_15080);
	cppVar_15082 = (cppVar_15081 >> 3) & cppMask_un_5_;
	cppVar_15083 = (cppVar_15082 << 3) | 0;
	cppVar_15083 = (cppVar_15083 & cppMask_un_8_);
	cppVar_15075 = cppVar_15083;
	} else {
	cppVar_15084 = PC + 1;
	cppVar_15084 = (cppVar_15084 & cppMask_un_16_);
	cppVar_15085 = ROM.rd(cppVar_15084);
	cppVar_15086 = (cppVar_15085 >> 3) & cppMask_un_5_;
	cppVar_15087 = (cppVar_15086 & cppMask_un_5_);
	cppVar_15088 = cppVar_15087 + 32;
	cppVar_15088 = (cppVar_15088 & cppMask_un_8_);
	cppVar_15075 = cppVar_15088;
	}
	cppVar_15090 = (cppVar_15075 == 184);
	if (cppVar_15090) {
	cppVar_15074 = IP;
	} else {
	cppVar_15093 = PC + 1;
	cppVar_15093 = (cppVar_15093 & cppMask_un_16_);
	cppVar_15094 = ROM.rd(cppVar_15093);
	cppVar_15095 = (cppVar_15094 >> 7) & cppMask_un_1_;
	cppVar_15096 = (cppVar_15095 == 1);
	if (cppVar_15096) {
	cppVar_15097 = PC + 1;
	cppVar_15097 = (cppVar_15097 & cppMask_un_16_);
	cppVar_15098 = ROM.rd(cppVar_15097);
	cppVar_15099 = (cppVar_15098 >> 3) & cppMask_un_5_;
	cppVar_15100 = (cppVar_15099 << 3) | 0;
	cppVar_15100 = (cppVar_15100 & cppMask_un_8_);
	cppVar_15092 = cppVar_15100;
	} else {
	cppVar_15101 = PC + 1;
	cppVar_15101 = (cppVar_15101 & cppMask_un_16_);
	cppVar_15102 = ROM.rd(cppVar_15101);
	cppVar_15103 = (cppVar_15102 >> 3) & cppMask_un_5_;
	cppVar_15104 = (cppVar_15103 & cppMask_un_5_);
	cppVar_15105 = cppVar_15104 + 32;
	cppVar_15105 = (cppVar_15105 & cppMask_un_8_);
	cppVar_15092 = cppVar_15105;
	}
	cppVar_15107 = (cppVar_15092 == 208);
	if (cppVar_15107) {
	cppVar_15091 = PSW;
	} else {
	cppVar_15110 = PC + 1;
	cppVar_15110 = (cppVar_15110 & cppMask_un_16_);
	cppVar_15111 = ROM.rd(cppVar_15110);
	cppVar_15112 = (cppVar_15111 >> 7) & cppMask_un_1_;
	cppVar_15113 = (cppVar_15112 == 1);
	if (cppVar_15113) {
	cppVar_15114 = PC + 1;
	cppVar_15114 = (cppVar_15114 & cppMask_un_16_);
	cppVar_15115 = ROM.rd(cppVar_15114);
	cppVar_15116 = (cppVar_15115 >> 3) & cppMask_un_5_;
	cppVar_15117 = (cppVar_15116 << 3) | 0;
	cppVar_15117 = (cppVar_15117 & cppMask_un_8_);
	cppVar_15109 = cppVar_15117;
	} else {
	cppVar_15118 = PC + 1;
	cppVar_15118 = (cppVar_15118 & cppMask_un_16_);
	cppVar_15119 = ROM.rd(cppVar_15118);
	cppVar_15120 = (cppVar_15119 >> 3) & cppMask_un_5_;
	cppVar_15121 = (cppVar_15120 & cppMask_un_5_);
	cppVar_15122 = cppVar_15121 + 32;
	cppVar_15122 = (cppVar_15122 & cppMask_un_8_);
	cppVar_15109 = cppVar_15122;
	}
	cppVar_15124 = (cppVar_15109 == 224);
	if (cppVar_15124) {
	cppVar_15108 = ACC;
	} else {
	cppVar_15127 = PC + 1;
	cppVar_15127 = (cppVar_15127 & cppMask_un_16_);
	cppVar_15128 = ROM.rd(cppVar_15127);
	cppVar_15129 = (cppVar_15128 >> 7) & cppMask_un_1_;
	cppVar_15130 = (cppVar_15129 == 1);
	if (cppVar_15130) {
	cppVar_15131 = PC + 1;
	cppVar_15131 = (cppVar_15131 & cppMask_un_16_);
	cppVar_15132 = ROM.rd(cppVar_15131);
	cppVar_15133 = (cppVar_15132 >> 3) & cppMask_un_5_;
	cppVar_15134 = (cppVar_15133 << 3) | 0;
	cppVar_15134 = (cppVar_15134 & cppMask_un_8_);
	cppVar_15126 = cppVar_15134;
	} else {
	cppVar_15135 = PC + 1;
	cppVar_15135 = (cppVar_15135 & cppMask_un_16_);
	cppVar_15136 = ROM.rd(cppVar_15135);
	cppVar_15137 = (cppVar_15136 >> 3) & cppMask_un_5_;
	cppVar_15138 = (cppVar_15137 & cppMask_un_5_);
	cppVar_15139 = cppVar_15138 + 32;
	cppVar_15139 = (cppVar_15139 & cppMask_un_8_);
	cppVar_15126 = cppVar_15139;
	}
	cppVar_15141 = (cppVar_15126 == 240);
	if (cppVar_15141) {
	cppVar_15125 = B;
	} else {
	cppVar_15125 = 0;
	}
	cppVar_15108 = cppVar_15125;
	}
	cppVar_15091 = cppVar_15108;
	}
	cppVar_15074 = cppVar_15091;
	}
	cppVar_15057 = cppVar_15074;
	}
	cppVar_15040 = cppVar_15057;
	}
	cppVar_15023 = cppVar_15040;
	}
	cppVar_15006 = cppVar_15023;
	}
	cppVar_14989 = cppVar_15006;
	}
	cppVar_14972 = cppVar_14989;
	}
	cppVar_14955 = cppVar_14972;
	}
	cppVar_14938 = cppVar_14955;
	}
	cppVar_14921 = cppVar_14938;
	}
	cppVar_14904 = cppVar_14921;
	}
	cppVar_14887 = cppVar_14904;
	}
	cppVar_14870 = cppVar_14887;
	}
	cppVar_14853 = cppVar_14870;
	}
	cppVar_14836 = cppVar_14853;
	}
	cppVar_14819 = cppVar_14836;
	}
	cppVar_14802 = cppVar_14819;
	}
	cppVar_14785 = cppVar_14802;
	}
	cppVar_14752 = cppVar_14785;
	}
	cppVar_15143 = cppVar_14751 & cppVar_14752;
	cppVar_15144 = (PSW >> 7) & cppMask_un_1_;
	cppVar_15145 = (cppVar_15144 & cppMask_un_1_);
	cppVar_15146 = PC + 1;
	cppVar_15146 = (cppVar_15146 & cppMask_un_16_);
	cppVar_15147 = ROM.rd(cppVar_15146);
	cppVar_15148 = (cppVar_15147 >> 0) & cppMask_un_3_;
	cppVar_15149 = (cppVar_15148 & cppMask_un_3_);
	cppVar_15150 = cppVar_15145 << static_cast<unsigned>(cppVar_15149);
	cppVar_15150 = (cppVar_15150 & cppMask_un_8_);
	cppVar_15151 = cppVar_15143 | cppVar_15150;
	cppVar_14724 = cppVar_15151;
	} else {
	cppVar_14724 = IE;
	}
	cppVar_14720 = cppVar_14724;
	} else {
	cppVar_15153 = ROM.rd(PC);
	cppVar_15155 = (cppVar_15153 == 143);
	if (cppVar_15155) {
	cppVar_15158 = PC + 1;
	cppVar_15158 = (cppVar_15158 & cppMask_un_16_);
	cppVar_15159 = ROM.rd(cppVar_15158);
	cppVar_15161 = (cppVar_15159 == 168);
	if (cppVar_15161) {
	cppVar_15164 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15166 = (cppVar_15164 << 3) | 7;
	cppVar_15166 = (cppVar_15166 & cppMask_un_5_);
	cppVar_15167 = (0 << 5) | cppVar_15166;
	cppVar_15167 = (cppVar_15167 & cppMask_un_8_);
	cppVar_15168 = (cppVar_15167 >> 7) & cppMask_un_1_;
	cppVar_15170 = (cppVar_15168 == 0);
	if (cppVar_15170) {
	cppVar_15171 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15172 = (cppVar_15171 << 3) | 7;
	cppVar_15172 = (cppVar_15172 & cppMask_un_5_);
	cppVar_15173 = (0 << 5) | cppVar_15172;
	cppVar_15173 = (cppVar_15173 & cppMask_un_8_);
	cppVar_15174 = IRAM.rd(cppVar_15173);
	cppVar_15162 = cppVar_15174;
	} else {
	cppVar_15176 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15177 = (cppVar_15176 << 3) | 7;
	cppVar_15177 = (cppVar_15177 & cppMask_un_5_);
	cppVar_15178 = (0 << 5) | cppVar_15177;
	cppVar_15178 = (cppVar_15178 & cppMask_un_8_);
	cppVar_15180 = (cppVar_15178 == 128);
	if (cppVar_15180) {
	cppVar_15175 = P0;
	} else {
	cppVar_15182 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15183 = (cppVar_15182 << 3) | 7;
	cppVar_15183 = (cppVar_15183 & cppMask_un_5_);
	cppVar_15184 = (0 << 5) | cppVar_15183;
	cppVar_15184 = (cppVar_15184 & cppMask_un_8_);
	cppVar_15186 = (cppVar_15184 == 129);
	if (cppVar_15186) {
	cppVar_15181 = SP;
	} else {
	cppVar_15188 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15189 = (cppVar_15188 << 3) | 7;
	cppVar_15189 = (cppVar_15189 & cppMask_un_5_);
	cppVar_15190 = (0 << 5) | cppVar_15189;
	cppVar_15190 = (cppVar_15190 & cppMask_un_8_);
	cppVar_15192 = (cppVar_15190 == 130);
	if (cppVar_15192) {
	cppVar_15187 = DPL;
	} else {
	cppVar_15194 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15195 = (cppVar_15194 << 3) | 7;
	cppVar_15195 = (cppVar_15195 & cppMask_un_5_);
	cppVar_15196 = (0 << 5) | cppVar_15195;
	cppVar_15196 = (cppVar_15196 & cppMask_un_8_);
	cppVar_15198 = (cppVar_15196 == 131);
	if (cppVar_15198) {
	cppVar_15193 = DPH;
	} else {
	cppVar_15200 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15201 = (cppVar_15200 << 3) | 7;
	cppVar_15201 = (cppVar_15201 & cppMask_un_5_);
	cppVar_15202 = (0 << 5) | cppVar_15201;
	cppVar_15202 = (cppVar_15202 & cppMask_un_8_);
	cppVar_15204 = (cppVar_15202 == 135);
	if (cppVar_15204) {
	cppVar_15199 = PCON;
	} else {
	cppVar_15206 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15207 = (cppVar_15206 << 3) | 7;
	cppVar_15207 = (cppVar_15207 & cppMask_un_5_);
	cppVar_15208 = (0 << 5) | cppVar_15207;
	cppVar_15208 = (cppVar_15208 & cppMask_un_8_);
	cppVar_15210 = (cppVar_15208 == 136);
	if (cppVar_15210) {
	cppVar_15205 = TCON;
	} else {
	cppVar_15212 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15213 = (cppVar_15212 << 3) | 7;
	cppVar_15213 = (cppVar_15213 & cppMask_un_5_);
	cppVar_15214 = (0 << 5) | cppVar_15213;
	cppVar_15214 = (cppVar_15214 & cppMask_un_8_);
	cppVar_15216 = (cppVar_15214 == 137);
	if (cppVar_15216) {
	cppVar_15211 = TMOD;
	} else {
	cppVar_15218 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15219 = (cppVar_15218 << 3) | 7;
	cppVar_15219 = (cppVar_15219 & cppMask_un_5_);
	cppVar_15220 = (0 << 5) | cppVar_15219;
	cppVar_15220 = (cppVar_15220 & cppMask_un_8_);
	cppVar_15222 = (cppVar_15220 == 138);
	if (cppVar_15222) {
	cppVar_15217 = TL0;
	} else {
	cppVar_15224 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15225 = (cppVar_15224 << 3) | 7;
	cppVar_15225 = (cppVar_15225 & cppMask_un_5_);
	cppVar_15226 = (0 << 5) | cppVar_15225;
	cppVar_15226 = (cppVar_15226 & cppMask_un_8_);
	cppVar_15228 = (cppVar_15226 == 140);
	if (cppVar_15228) {
	cppVar_15223 = TH0;
	} else {
	cppVar_15230 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15231 = (cppVar_15230 << 3) | 7;
	cppVar_15231 = (cppVar_15231 & cppMask_un_5_);
	cppVar_15232 = (0 << 5) | cppVar_15231;
	cppVar_15232 = (cppVar_15232 & cppMask_un_8_);
	cppVar_15234 = (cppVar_15232 == 139);
	if (cppVar_15234) {
	cppVar_15229 = TL1;
	} else {
	cppVar_15236 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15237 = (cppVar_15236 << 3) | 7;
	cppVar_15237 = (cppVar_15237 & cppMask_un_5_);
	cppVar_15238 = (0 << 5) | cppVar_15237;
	cppVar_15238 = (cppVar_15238 & cppMask_un_8_);
	cppVar_15240 = (cppVar_15238 == 141);
	if (cppVar_15240) {
	cppVar_15235 = TH1;
	} else {
	cppVar_15242 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15243 = (cppVar_15242 << 3) | 7;
	cppVar_15243 = (cppVar_15243 & cppMask_un_5_);
	cppVar_15244 = (0 << 5) | cppVar_15243;
	cppVar_15244 = (cppVar_15244 & cppMask_un_8_);
	cppVar_15246 = (cppVar_15244 == 144);
	if (cppVar_15246) {
	cppVar_15241 = P1;
	} else {
	cppVar_15248 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15249 = (cppVar_15248 << 3) | 7;
	cppVar_15249 = (cppVar_15249 & cppMask_un_5_);
	cppVar_15250 = (0 << 5) | cppVar_15249;
	cppVar_15250 = (cppVar_15250 & cppMask_un_8_);
	cppVar_15252 = (cppVar_15250 == 152);
	if (cppVar_15252) {
	cppVar_15247 = SCON;
	} else {
	cppVar_15254 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15255 = (cppVar_15254 << 3) | 7;
	cppVar_15255 = (cppVar_15255 & cppMask_un_5_);
	cppVar_15256 = (0 << 5) | cppVar_15255;
	cppVar_15256 = (cppVar_15256 & cppMask_un_8_);
	cppVar_15258 = (cppVar_15256 == 153);
	if (cppVar_15258) {
	cppVar_15253 = SBUF;
	} else {
	cppVar_15260 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15261 = (cppVar_15260 << 3) | 7;
	cppVar_15261 = (cppVar_15261 & cppMask_un_5_);
	cppVar_15262 = (0 << 5) | cppVar_15261;
	cppVar_15262 = (cppVar_15262 & cppMask_un_8_);
	cppVar_15264 = (cppVar_15262 == 160);
	if (cppVar_15264) {
	cppVar_15259 = P2;
	} else {
	cppVar_15266 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15267 = (cppVar_15266 << 3) | 7;
	cppVar_15267 = (cppVar_15267 & cppMask_un_5_);
	cppVar_15268 = (0 << 5) | cppVar_15267;
	cppVar_15268 = (cppVar_15268 & cppMask_un_8_);
	cppVar_15270 = (cppVar_15268 == 168);
	if (cppVar_15270) {
	cppVar_15265 = IE;
	} else {
	cppVar_15272 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15273 = (cppVar_15272 << 3) | 7;
	cppVar_15273 = (cppVar_15273 & cppMask_un_5_);
	cppVar_15274 = (0 << 5) | cppVar_15273;
	cppVar_15274 = (cppVar_15274 & cppMask_un_8_);
	cppVar_15276 = (cppVar_15274 == 176);
	if (cppVar_15276) {
	cppVar_15271 = P3;
	} else {
	cppVar_15278 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15279 = (cppVar_15278 << 3) | 7;
	cppVar_15279 = (cppVar_15279 & cppMask_un_5_);
	cppVar_15280 = (0 << 5) | cppVar_15279;
	cppVar_15280 = (cppVar_15280 & cppMask_un_8_);
	cppVar_15282 = (cppVar_15280 == 184);
	if (cppVar_15282) {
	cppVar_15277 = IP;
	} else {
	cppVar_15284 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15285 = (cppVar_15284 << 3) | 7;
	cppVar_15285 = (cppVar_15285 & cppMask_un_5_);
	cppVar_15286 = (0 << 5) | cppVar_15285;
	cppVar_15286 = (cppVar_15286 & cppMask_un_8_);
	cppVar_15288 = (cppVar_15286 == 208);
	if (cppVar_15288) {
	cppVar_15283 = PSW;
	} else {
	cppVar_15290 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15291 = (cppVar_15290 << 3) | 7;
	cppVar_15291 = (cppVar_15291 & cppMask_un_5_);
	cppVar_15292 = (0 << 5) | cppVar_15291;
	cppVar_15292 = (cppVar_15292 & cppMask_un_8_);
	cppVar_15294 = (cppVar_15292 == 224);
	if (cppVar_15294) {
	cppVar_15289 = ACC;
	} else {
	cppVar_15296 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15297 = (cppVar_15296 << 3) | 7;
	cppVar_15297 = (cppVar_15297 & cppMask_un_5_);
	cppVar_15298 = (0 << 5) | cppVar_15297;
	cppVar_15298 = (cppVar_15298 & cppMask_un_8_);
	cppVar_15300 = (cppVar_15298 == 240);
	if (cppVar_15300) {
	cppVar_15295 = B;
	} else {
	cppVar_15295 = 0;
	}
	cppVar_15289 = cppVar_15295;
	}
	cppVar_15283 = cppVar_15289;
	}
	cppVar_15277 = cppVar_15283;
	}
	cppVar_15271 = cppVar_15277;
	}
	cppVar_15265 = cppVar_15271;
	}
	cppVar_15259 = cppVar_15265;
	}
	cppVar_15253 = cppVar_15259;
	}
	cppVar_15247 = cppVar_15253;
	}
	cppVar_15241 = cppVar_15247;
	}
	cppVar_15235 = cppVar_15241;
	}
	cppVar_15229 = cppVar_15235;
	}
	cppVar_15223 = cppVar_15229;
	}
	cppVar_15217 = cppVar_15223;
	}
	cppVar_15211 = cppVar_15217;
	}
	cppVar_15205 = cppVar_15211;
	}
	cppVar_15199 = cppVar_15205;
	}
	cppVar_15193 = cppVar_15199;
	}
	cppVar_15187 = cppVar_15193;
	}
	cppVar_15181 = cppVar_15187;
	}
	cppVar_15175 = cppVar_15181;
	}
	cppVar_15162 = cppVar_15175;
	}
	cppVar_15156 = cppVar_15162;
	} else {
	cppVar_15156 = IE;
	}
	cppVar_15152 = cppVar_15156;
	} else {
	cppVar_15303 = ROM.rd(PC);
	cppVar_15305 = (cppVar_15303 == 142);
	if (cppVar_15305) {
	cppVar_15308 = PC + 1;
	cppVar_15308 = (cppVar_15308 & cppMask_un_16_);
	cppVar_15309 = ROM.rd(cppVar_15308);
	cppVar_15311 = (cppVar_15309 == 168);
	if (cppVar_15311) {
	cppVar_15314 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15316 = (cppVar_15314 << 3) | 6;
	cppVar_15316 = (cppVar_15316 & cppMask_un_5_);
	cppVar_15317 = (0 << 5) | cppVar_15316;
	cppVar_15317 = (cppVar_15317 & cppMask_un_8_);
	cppVar_15318 = (cppVar_15317 >> 7) & cppMask_un_1_;
	cppVar_15320 = (cppVar_15318 == 0);
	if (cppVar_15320) {
	cppVar_15321 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15322 = (cppVar_15321 << 3) | 6;
	cppVar_15322 = (cppVar_15322 & cppMask_un_5_);
	cppVar_15323 = (0 << 5) | cppVar_15322;
	cppVar_15323 = (cppVar_15323 & cppMask_un_8_);
	cppVar_15324 = IRAM.rd(cppVar_15323);
	cppVar_15312 = cppVar_15324;
	} else {
	cppVar_15326 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15327 = (cppVar_15326 << 3) | 6;
	cppVar_15327 = (cppVar_15327 & cppMask_un_5_);
	cppVar_15328 = (0 << 5) | cppVar_15327;
	cppVar_15328 = (cppVar_15328 & cppMask_un_8_);
	cppVar_15330 = (cppVar_15328 == 128);
	if (cppVar_15330) {
	cppVar_15325 = P0;
	} else {
	cppVar_15332 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15333 = (cppVar_15332 << 3) | 6;
	cppVar_15333 = (cppVar_15333 & cppMask_un_5_);
	cppVar_15334 = (0 << 5) | cppVar_15333;
	cppVar_15334 = (cppVar_15334 & cppMask_un_8_);
	cppVar_15336 = (cppVar_15334 == 129);
	if (cppVar_15336) {
	cppVar_15331 = SP;
	} else {
	cppVar_15338 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15339 = (cppVar_15338 << 3) | 6;
	cppVar_15339 = (cppVar_15339 & cppMask_un_5_);
	cppVar_15340 = (0 << 5) | cppVar_15339;
	cppVar_15340 = (cppVar_15340 & cppMask_un_8_);
	cppVar_15342 = (cppVar_15340 == 130);
	if (cppVar_15342) {
	cppVar_15337 = DPL;
	} else {
	cppVar_15344 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15345 = (cppVar_15344 << 3) | 6;
	cppVar_15345 = (cppVar_15345 & cppMask_un_5_);
	cppVar_15346 = (0 << 5) | cppVar_15345;
	cppVar_15346 = (cppVar_15346 & cppMask_un_8_);
	cppVar_15348 = (cppVar_15346 == 131);
	if (cppVar_15348) {
	cppVar_15343 = DPH;
	} else {
	cppVar_15350 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15351 = (cppVar_15350 << 3) | 6;
	cppVar_15351 = (cppVar_15351 & cppMask_un_5_);
	cppVar_15352 = (0 << 5) | cppVar_15351;
	cppVar_15352 = (cppVar_15352 & cppMask_un_8_);
	cppVar_15354 = (cppVar_15352 == 135);
	if (cppVar_15354) {
	cppVar_15349 = PCON;
	} else {
	cppVar_15356 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15357 = (cppVar_15356 << 3) | 6;
	cppVar_15357 = (cppVar_15357 & cppMask_un_5_);
	cppVar_15358 = (0 << 5) | cppVar_15357;
	cppVar_15358 = (cppVar_15358 & cppMask_un_8_);
	cppVar_15360 = (cppVar_15358 == 136);
	if (cppVar_15360) {
	cppVar_15355 = TCON;
	} else {
	cppVar_15362 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15363 = (cppVar_15362 << 3) | 6;
	cppVar_15363 = (cppVar_15363 & cppMask_un_5_);
	cppVar_15364 = (0 << 5) | cppVar_15363;
	cppVar_15364 = (cppVar_15364 & cppMask_un_8_);
	cppVar_15366 = (cppVar_15364 == 137);
	if (cppVar_15366) {
	cppVar_15361 = TMOD;
	} else {
	cppVar_15368 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15369 = (cppVar_15368 << 3) | 6;
	cppVar_15369 = (cppVar_15369 & cppMask_un_5_);
	cppVar_15370 = (0 << 5) | cppVar_15369;
	cppVar_15370 = (cppVar_15370 & cppMask_un_8_);
	cppVar_15372 = (cppVar_15370 == 138);
	if (cppVar_15372) {
	cppVar_15367 = TL0;
	} else {
	cppVar_15374 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15375 = (cppVar_15374 << 3) | 6;
	cppVar_15375 = (cppVar_15375 & cppMask_un_5_);
	cppVar_15376 = (0 << 5) | cppVar_15375;
	cppVar_15376 = (cppVar_15376 & cppMask_un_8_);
	cppVar_15378 = (cppVar_15376 == 140);
	if (cppVar_15378) {
	cppVar_15373 = TH0;
	} else {
	cppVar_15380 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15381 = (cppVar_15380 << 3) | 6;
	cppVar_15381 = (cppVar_15381 & cppMask_un_5_);
	cppVar_15382 = (0 << 5) | cppVar_15381;
	cppVar_15382 = (cppVar_15382 & cppMask_un_8_);
	cppVar_15384 = (cppVar_15382 == 139);
	if (cppVar_15384) {
	cppVar_15379 = TL1;
	} else {
	cppVar_15386 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15387 = (cppVar_15386 << 3) | 6;
	cppVar_15387 = (cppVar_15387 & cppMask_un_5_);
	cppVar_15388 = (0 << 5) | cppVar_15387;
	cppVar_15388 = (cppVar_15388 & cppMask_un_8_);
	cppVar_15390 = (cppVar_15388 == 141);
	if (cppVar_15390) {
	cppVar_15385 = TH1;
	} else {
	cppVar_15392 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15393 = (cppVar_15392 << 3) | 6;
	cppVar_15393 = (cppVar_15393 & cppMask_un_5_);
	cppVar_15394 = (0 << 5) | cppVar_15393;
	cppVar_15394 = (cppVar_15394 & cppMask_un_8_);
	cppVar_15396 = (cppVar_15394 == 144);
	if (cppVar_15396) {
	cppVar_15391 = P1;
	} else {
	cppVar_15398 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15399 = (cppVar_15398 << 3) | 6;
	cppVar_15399 = (cppVar_15399 & cppMask_un_5_);
	cppVar_15400 = (0 << 5) | cppVar_15399;
	cppVar_15400 = (cppVar_15400 & cppMask_un_8_);
	cppVar_15402 = (cppVar_15400 == 152);
	if (cppVar_15402) {
	cppVar_15397 = SCON;
	} else {
	cppVar_15404 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15405 = (cppVar_15404 << 3) | 6;
	cppVar_15405 = (cppVar_15405 & cppMask_un_5_);
	cppVar_15406 = (0 << 5) | cppVar_15405;
	cppVar_15406 = (cppVar_15406 & cppMask_un_8_);
	cppVar_15408 = (cppVar_15406 == 153);
	if (cppVar_15408) {
	cppVar_15403 = SBUF;
	} else {
	cppVar_15410 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15411 = (cppVar_15410 << 3) | 6;
	cppVar_15411 = (cppVar_15411 & cppMask_un_5_);
	cppVar_15412 = (0 << 5) | cppVar_15411;
	cppVar_15412 = (cppVar_15412 & cppMask_un_8_);
	cppVar_15414 = (cppVar_15412 == 160);
	if (cppVar_15414) {
	cppVar_15409 = P2;
	} else {
	cppVar_15416 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15417 = (cppVar_15416 << 3) | 6;
	cppVar_15417 = (cppVar_15417 & cppMask_un_5_);
	cppVar_15418 = (0 << 5) | cppVar_15417;
	cppVar_15418 = (cppVar_15418 & cppMask_un_8_);
	cppVar_15420 = (cppVar_15418 == 168);
	if (cppVar_15420) {
	cppVar_15415 = IE;
	} else {
	cppVar_15422 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15423 = (cppVar_15422 << 3) | 6;
	cppVar_15423 = (cppVar_15423 & cppMask_un_5_);
	cppVar_15424 = (0 << 5) | cppVar_15423;
	cppVar_15424 = (cppVar_15424 & cppMask_un_8_);
	cppVar_15426 = (cppVar_15424 == 176);
	if (cppVar_15426) {
	cppVar_15421 = P3;
	} else {
	cppVar_15428 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15429 = (cppVar_15428 << 3) | 6;
	cppVar_15429 = (cppVar_15429 & cppMask_un_5_);
	cppVar_15430 = (0 << 5) | cppVar_15429;
	cppVar_15430 = (cppVar_15430 & cppMask_un_8_);
	cppVar_15432 = (cppVar_15430 == 184);
	if (cppVar_15432) {
	cppVar_15427 = IP;
	} else {
	cppVar_15434 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15435 = (cppVar_15434 << 3) | 6;
	cppVar_15435 = (cppVar_15435 & cppMask_un_5_);
	cppVar_15436 = (0 << 5) | cppVar_15435;
	cppVar_15436 = (cppVar_15436 & cppMask_un_8_);
	cppVar_15438 = (cppVar_15436 == 208);
	if (cppVar_15438) {
	cppVar_15433 = PSW;
	} else {
	cppVar_15440 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15441 = (cppVar_15440 << 3) | 6;
	cppVar_15441 = (cppVar_15441 & cppMask_un_5_);
	cppVar_15442 = (0 << 5) | cppVar_15441;
	cppVar_15442 = (cppVar_15442 & cppMask_un_8_);
	cppVar_15444 = (cppVar_15442 == 224);
	if (cppVar_15444) {
	cppVar_15439 = ACC;
	} else {
	cppVar_15446 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15447 = (cppVar_15446 << 3) | 6;
	cppVar_15447 = (cppVar_15447 & cppMask_un_5_);
	cppVar_15448 = (0 << 5) | cppVar_15447;
	cppVar_15448 = (cppVar_15448 & cppMask_un_8_);
	cppVar_15450 = (cppVar_15448 == 240);
	if (cppVar_15450) {
	cppVar_15445 = B;
	} else {
	cppVar_15445 = 0;
	}
	cppVar_15439 = cppVar_15445;
	}
	cppVar_15433 = cppVar_15439;
	}
	cppVar_15427 = cppVar_15433;
	}
	cppVar_15421 = cppVar_15427;
	}
	cppVar_15415 = cppVar_15421;
	}
	cppVar_15409 = cppVar_15415;
	}
	cppVar_15403 = cppVar_15409;
	}
	cppVar_15397 = cppVar_15403;
	}
	cppVar_15391 = cppVar_15397;
	}
	cppVar_15385 = cppVar_15391;
	}
	cppVar_15379 = cppVar_15385;
	}
	cppVar_15373 = cppVar_15379;
	}
	cppVar_15367 = cppVar_15373;
	}
	cppVar_15361 = cppVar_15367;
	}
	cppVar_15355 = cppVar_15361;
	}
	cppVar_15349 = cppVar_15355;
	}
	cppVar_15343 = cppVar_15349;
	}
	cppVar_15337 = cppVar_15343;
	}
	cppVar_15331 = cppVar_15337;
	}
	cppVar_15325 = cppVar_15331;
	}
	cppVar_15312 = cppVar_15325;
	}
	cppVar_15306 = cppVar_15312;
	} else {
	cppVar_15306 = IE;
	}
	cppVar_15302 = cppVar_15306;
	} else {
	cppVar_15453 = ROM.rd(PC);
	cppVar_15455 = (cppVar_15453 == 141);
	if (cppVar_15455) {
	cppVar_15458 = PC + 1;
	cppVar_15458 = (cppVar_15458 & cppMask_un_16_);
	cppVar_15459 = ROM.rd(cppVar_15458);
	cppVar_15461 = (cppVar_15459 == 168);
	if (cppVar_15461) {
	cppVar_15464 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15466 = (cppVar_15464 << 3) | 5;
	cppVar_15466 = (cppVar_15466 & cppMask_un_5_);
	cppVar_15467 = (0 << 5) | cppVar_15466;
	cppVar_15467 = (cppVar_15467 & cppMask_un_8_);
	cppVar_15468 = (cppVar_15467 >> 7) & cppMask_un_1_;
	cppVar_15470 = (cppVar_15468 == 0);
	if (cppVar_15470) {
	cppVar_15471 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15472 = (cppVar_15471 << 3) | 5;
	cppVar_15472 = (cppVar_15472 & cppMask_un_5_);
	cppVar_15473 = (0 << 5) | cppVar_15472;
	cppVar_15473 = (cppVar_15473 & cppMask_un_8_);
	cppVar_15474 = IRAM.rd(cppVar_15473);
	cppVar_15462 = cppVar_15474;
	} else {
	cppVar_15476 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15477 = (cppVar_15476 << 3) | 5;
	cppVar_15477 = (cppVar_15477 & cppMask_un_5_);
	cppVar_15478 = (0 << 5) | cppVar_15477;
	cppVar_15478 = (cppVar_15478 & cppMask_un_8_);
	cppVar_15480 = (cppVar_15478 == 128);
	if (cppVar_15480) {
	cppVar_15475 = P0;
	} else {
	cppVar_15482 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15483 = (cppVar_15482 << 3) | 5;
	cppVar_15483 = (cppVar_15483 & cppMask_un_5_);
	cppVar_15484 = (0 << 5) | cppVar_15483;
	cppVar_15484 = (cppVar_15484 & cppMask_un_8_);
	cppVar_15486 = (cppVar_15484 == 129);
	if (cppVar_15486) {
	cppVar_15481 = SP;
	} else {
	cppVar_15488 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15489 = (cppVar_15488 << 3) | 5;
	cppVar_15489 = (cppVar_15489 & cppMask_un_5_);
	cppVar_15490 = (0 << 5) | cppVar_15489;
	cppVar_15490 = (cppVar_15490 & cppMask_un_8_);
	cppVar_15492 = (cppVar_15490 == 130);
	if (cppVar_15492) {
	cppVar_15487 = DPL;
	} else {
	cppVar_15494 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15495 = (cppVar_15494 << 3) | 5;
	cppVar_15495 = (cppVar_15495 & cppMask_un_5_);
	cppVar_15496 = (0 << 5) | cppVar_15495;
	cppVar_15496 = (cppVar_15496 & cppMask_un_8_);
	cppVar_15498 = (cppVar_15496 == 131);
	if (cppVar_15498) {
	cppVar_15493 = DPH;
	} else {
	cppVar_15500 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15501 = (cppVar_15500 << 3) | 5;
	cppVar_15501 = (cppVar_15501 & cppMask_un_5_);
	cppVar_15502 = (0 << 5) | cppVar_15501;
	cppVar_15502 = (cppVar_15502 & cppMask_un_8_);
	cppVar_15504 = (cppVar_15502 == 135);
	if (cppVar_15504) {
	cppVar_15499 = PCON;
	} else {
	cppVar_15506 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15507 = (cppVar_15506 << 3) | 5;
	cppVar_15507 = (cppVar_15507 & cppMask_un_5_);
	cppVar_15508 = (0 << 5) | cppVar_15507;
	cppVar_15508 = (cppVar_15508 & cppMask_un_8_);
	cppVar_15510 = (cppVar_15508 == 136);
	if (cppVar_15510) {
	cppVar_15505 = TCON;
	} else {
	cppVar_15512 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15513 = (cppVar_15512 << 3) | 5;
	cppVar_15513 = (cppVar_15513 & cppMask_un_5_);
	cppVar_15514 = (0 << 5) | cppVar_15513;
	cppVar_15514 = (cppVar_15514 & cppMask_un_8_);
	cppVar_15516 = (cppVar_15514 == 137);
	if (cppVar_15516) {
	cppVar_15511 = TMOD;
	} else {
	cppVar_15518 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15519 = (cppVar_15518 << 3) | 5;
	cppVar_15519 = (cppVar_15519 & cppMask_un_5_);
	cppVar_15520 = (0 << 5) | cppVar_15519;
	cppVar_15520 = (cppVar_15520 & cppMask_un_8_);
	cppVar_15522 = (cppVar_15520 == 138);
	if (cppVar_15522) {
	cppVar_15517 = TL0;
	} else {
	cppVar_15524 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15525 = (cppVar_15524 << 3) | 5;
	cppVar_15525 = (cppVar_15525 & cppMask_un_5_);
	cppVar_15526 = (0 << 5) | cppVar_15525;
	cppVar_15526 = (cppVar_15526 & cppMask_un_8_);
	cppVar_15528 = (cppVar_15526 == 140);
	if (cppVar_15528) {
	cppVar_15523 = TH0;
	} else {
	cppVar_15530 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15531 = (cppVar_15530 << 3) | 5;
	cppVar_15531 = (cppVar_15531 & cppMask_un_5_);
	cppVar_15532 = (0 << 5) | cppVar_15531;
	cppVar_15532 = (cppVar_15532 & cppMask_un_8_);
	cppVar_15534 = (cppVar_15532 == 139);
	if (cppVar_15534) {
	cppVar_15529 = TL1;
	} else {
	cppVar_15536 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15537 = (cppVar_15536 << 3) | 5;
	cppVar_15537 = (cppVar_15537 & cppMask_un_5_);
	cppVar_15538 = (0 << 5) | cppVar_15537;
	cppVar_15538 = (cppVar_15538 & cppMask_un_8_);
	cppVar_15540 = (cppVar_15538 == 141);
	if (cppVar_15540) {
	cppVar_15535 = TH1;
	} else {
	cppVar_15542 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15543 = (cppVar_15542 << 3) | 5;
	cppVar_15543 = (cppVar_15543 & cppMask_un_5_);
	cppVar_15544 = (0 << 5) | cppVar_15543;
	cppVar_15544 = (cppVar_15544 & cppMask_un_8_);
	cppVar_15546 = (cppVar_15544 == 144);
	if (cppVar_15546) {
	cppVar_15541 = P1;
	} else {
	cppVar_15548 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15549 = (cppVar_15548 << 3) | 5;
	cppVar_15549 = (cppVar_15549 & cppMask_un_5_);
	cppVar_15550 = (0 << 5) | cppVar_15549;
	cppVar_15550 = (cppVar_15550 & cppMask_un_8_);
	cppVar_15552 = (cppVar_15550 == 152);
	if (cppVar_15552) {
	cppVar_15547 = SCON;
	} else {
	cppVar_15554 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15555 = (cppVar_15554 << 3) | 5;
	cppVar_15555 = (cppVar_15555 & cppMask_un_5_);
	cppVar_15556 = (0 << 5) | cppVar_15555;
	cppVar_15556 = (cppVar_15556 & cppMask_un_8_);
	cppVar_15558 = (cppVar_15556 == 153);
	if (cppVar_15558) {
	cppVar_15553 = SBUF;
	} else {
	cppVar_15560 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15561 = (cppVar_15560 << 3) | 5;
	cppVar_15561 = (cppVar_15561 & cppMask_un_5_);
	cppVar_15562 = (0 << 5) | cppVar_15561;
	cppVar_15562 = (cppVar_15562 & cppMask_un_8_);
	cppVar_15564 = (cppVar_15562 == 160);
	if (cppVar_15564) {
	cppVar_15559 = P2;
	} else {
	cppVar_15566 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15567 = (cppVar_15566 << 3) | 5;
	cppVar_15567 = (cppVar_15567 & cppMask_un_5_);
	cppVar_15568 = (0 << 5) | cppVar_15567;
	cppVar_15568 = (cppVar_15568 & cppMask_un_8_);
	cppVar_15570 = (cppVar_15568 == 168);
	if (cppVar_15570) {
	cppVar_15565 = IE;
	} else {
	cppVar_15572 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15573 = (cppVar_15572 << 3) | 5;
	cppVar_15573 = (cppVar_15573 & cppMask_un_5_);
	cppVar_15574 = (0 << 5) | cppVar_15573;
	cppVar_15574 = (cppVar_15574 & cppMask_un_8_);
	cppVar_15576 = (cppVar_15574 == 176);
	if (cppVar_15576) {
	cppVar_15571 = P3;
	} else {
	cppVar_15578 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15579 = (cppVar_15578 << 3) | 5;
	cppVar_15579 = (cppVar_15579 & cppMask_un_5_);
	cppVar_15580 = (0 << 5) | cppVar_15579;
	cppVar_15580 = (cppVar_15580 & cppMask_un_8_);
	cppVar_15582 = (cppVar_15580 == 184);
	if (cppVar_15582) {
	cppVar_15577 = IP;
	} else {
	cppVar_15584 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15585 = (cppVar_15584 << 3) | 5;
	cppVar_15585 = (cppVar_15585 & cppMask_un_5_);
	cppVar_15586 = (0 << 5) | cppVar_15585;
	cppVar_15586 = (cppVar_15586 & cppMask_un_8_);
	cppVar_15588 = (cppVar_15586 == 208);
	if (cppVar_15588) {
	cppVar_15583 = PSW;
	} else {
	cppVar_15590 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15591 = (cppVar_15590 << 3) | 5;
	cppVar_15591 = (cppVar_15591 & cppMask_un_5_);
	cppVar_15592 = (0 << 5) | cppVar_15591;
	cppVar_15592 = (cppVar_15592 & cppMask_un_8_);
	cppVar_15594 = (cppVar_15592 == 224);
	if (cppVar_15594) {
	cppVar_15589 = ACC;
	} else {
	cppVar_15596 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15597 = (cppVar_15596 << 3) | 5;
	cppVar_15597 = (cppVar_15597 & cppMask_un_5_);
	cppVar_15598 = (0 << 5) | cppVar_15597;
	cppVar_15598 = (cppVar_15598 & cppMask_un_8_);
	cppVar_15600 = (cppVar_15598 == 240);
	if (cppVar_15600) {
	cppVar_15595 = B;
	} else {
	cppVar_15595 = 0;
	}
	cppVar_15589 = cppVar_15595;
	}
	cppVar_15583 = cppVar_15589;
	}
	cppVar_15577 = cppVar_15583;
	}
	cppVar_15571 = cppVar_15577;
	}
	cppVar_15565 = cppVar_15571;
	}
	cppVar_15559 = cppVar_15565;
	}
	cppVar_15553 = cppVar_15559;
	}
	cppVar_15547 = cppVar_15553;
	}
	cppVar_15541 = cppVar_15547;
	}
	cppVar_15535 = cppVar_15541;
	}
	cppVar_15529 = cppVar_15535;
	}
	cppVar_15523 = cppVar_15529;
	}
	cppVar_15517 = cppVar_15523;
	}
	cppVar_15511 = cppVar_15517;
	}
	cppVar_15505 = cppVar_15511;
	}
	cppVar_15499 = cppVar_15505;
	}
	cppVar_15493 = cppVar_15499;
	}
	cppVar_15487 = cppVar_15493;
	}
	cppVar_15481 = cppVar_15487;
	}
	cppVar_15475 = cppVar_15481;
	}
	cppVar_15462 = cppVar_15475;
	}
	cppVar_15456 = cppVar_15462;
	} else {
	cppVar_15456 = IE;
	}
	cppVar_15452 = cppVar_15456;
	} else {
	cppVar_15603 = ROM.rd(PC);
	cppVar_15605 = (cppVar_15603 == 140);
	if (cppVar_15605) {
	cppVar_15608 = PC + 1;
	cppVar_15608 = (cppVar_15608 & cppMask_un_16_);
	cppVar_15609 = ROM.rd(cppVar_15608);
	cppVar_15611 = (cppVar_15609 == 168);
	if (cppVar_15611) {
	cppVar_15614 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15616 = (cppVar_15614 << 3) | 4;
	cppVar_15616 = (cppVar_15616 & cppMask_un_5_);
	cppVar_15617 = (0 << 5) | cppVar_15616;
	cppVar_15617 = (cppVar_15617 & cppMask_un_8_);
	cppVar_15618 = (cppVar_15617 >> 7) & cppMask_un_1_;
	cppVar_15620 = (cppVar_15618 == 0);
	if (cppVar_15620) {
	cppVar_15621 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15622 = (cppVar_15621 << 3) | 4;
	cppVar_15622 = (cppVar_15622 & cppMask_un_5_);
	cppVar_15623 = (0 << 5) | cppVar_15622;
	cppVar_15623 = (cppVar_15623 & cppMask_un_8_);
	cppVar_15624 = IRAM.rd(cppVar_15623);
	cppVar_15612 = cppVar_15624;
	} else {
	cppVar_15626 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15627 = (cppVar_15626 << 3) | 4;
	cppVar_15627 = (cppVar_15627 & cppMask_un_5_);
	cppVar_15628 = (0 << 5) | cppVar_15627;
	cppVar_15628 = (cppVar_15628 & cppMask_un_8_);
	cppVar_15630 = (cppVar_15628 == 128);
	if (cppVar_15630) {
	cppVar_15625 = P0;
	} else {
	cppVar_15632 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15633 = (cppVar_15632 << 3) | 4;
	cppVar_15633 = (cppVar_15633 & cppMask_un_5_);
	cppVar_15634 = (0 << 5) | cppVar_15633;
	cppVar_15634 = (cppVar_15634 & cppMask_un_8_);
	cppVar_15636 = (cppVar_15634 == 129);
	if (cppVar_15636) {
	cppVar_15631 = SP;
	} else {
	cppVar_15638 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15639 = (cppVar_15638 << 3) | 4;
	cppVar_15639 = (cppVar_15639 & cppMask_un_5_);
	cppVar_15640 = (0 << 5) | cppVar_15639;
	cppVar_15640 = (cppVar_15640 & cppMask_un_8_);
	cppVar_15642 = (cppVar_15640 == 130);
	if (cppVar_15642) {
	cppVar_15637 = DPL;
	} else {
	cppVar_15644 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15645 = (cppVar_15644 << 3) | 4;
	cppVar_15645 = (cppVar_15645 & cppMask_un_5_);
	cppVar_15646 = (0 << 5) | cppVar_15645;
	cppVar_15646 = (cppVar_15646 & cppMask_un_8_);
	cppVar_15648 = (cppVar_15646 == 131);
	if (cppVar_15648) {
	cppVar_15643 = DPH;
	} else {
	cppVar_15650 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15651 = (cppVar_15650 << 3) | 4;
	cppVar_15651 = (cppVar_15651 & cppMask_un_5_);
	cppVar_15652 = (0 << 5) | cppVar_15651;
	cppVar_15652 = (cppVar_15652 & cppMask_un_8_);
	cppVar_15654 = (cppVar_15652 == 135);
	if (cppVar_15654) {
	cppVar_15649 = PCON;
	} else {
	cppVar_15656 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15657 = (cppVar_15656 << 3) | 4;
	cppVar_15657 = (cppVar_15657 & cppMask_un_5_);
	cppVar_15658 = (0 << 5) | cppVar_15657;
	cppVar_15658 = (cppVar_15658 & cppMask_un_8_);
	cppVar_15660 = (cppVar_15658 == 136);
	if (cppVar_15660) {
	cppVar_15655 = TCON;
	} else {
	cppVar_15662 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15663 = (cppVar_15662 << 3) | 4;
	cppVar_15663 = (cppVar_15663 & cppMask_un_5_);
	cppVar_15664 = (0 << 5) | cppVar_15663;
	cppVar_15664 = (cppVar_15664 & cppMask_un_8_);
	cppVar_15666 = (cppVar_15664 == 137);
	if (cppVar_15666) {
	cppVar_15661 = TMOD;
	} else {
	cppVar_15668 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15669 = (cppVar_15668 << 3) | 4;
	cppVar_15669 = (cppVar_15669 & cppMask_un_5_);
	cppVar_15670 = (0 << 5) | cppVar_15669;
	cppVar_15670 = (cppVar_15670 & cppMask_un_8_);
	cppVar_15672 = (cppVar_15670 == 138);
	if (cppVar_15672) {
	cppVar_15667 = TL0;
	} else {
	cppVar_15674 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15675 = (cppVar_15674 << 3) | 4;
	cppVar_15675 = (cppVar_15675 & cppMask_un_5_);
	cppVar_15676 = (0 << 5) | cppVar_15675;
	cppVar_15676 = (cppVar_15676 & cppMask_un_8_);
	cppVar_15678 = (cppVar_15676 == 140);
	if (cppVar_15678) {
	cppVar_15673 = TH0;
	} else {
	cppVar_15680 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15681 = (cppVar_15680 << 3) | 4;
	cppVar_15681 = (cppVar_15681 & cppMask_un_5_);
	cppVar_15682 = (0 << 5) | cppVar_15681;
	cppVar_15682 = (cppVar_15682 & cppMask_un_8_);
	cppVar_15684 = (cppVar_15682 == 139);
	if (cppVar_15684) {
	cppVar_15679 = TL1;
	} else {
	cppVar_15686 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15687 = (cppVar_15686 << 3) | 4;
	cppVar_15687 = (cppVar_15687 & cppMask_un_5_);
	cppVar_15688 = (0 << 5) | cppVar_15687;
	cppVar_15688 = (cppVar_15688 & cppMask_un_8_);
	cppVar_15690 = (cppVar_15688 == 141);
	if (cppVar_15690) {
	cppVar_15685 = TH1;
	} else {
	cppVar_15692 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15693 = (cppVar_15692 << 3) | 4;
	cppVar_15693 = (cppVar_15693 & cppMask_un_5_);
	cppVar_15694 = (0 << 5) | cppVar_15693;
	cppVar_15694 = (cppVar_15694 & cppMask_un_8_);
	cppVar_15696 = (cppVar_15694 == 144);
	if (cppVar_15696) {
	cppVar_15691 = P1;
	} else {
	cppVar_15698 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15699 = (cppVar_15698 << 3) | 4;
	cppVar_15699 = (cppVar_15699 & cppMask_un_5_);
	cppVar_15700 = (0 << 5) | cppVar_15699;
	cppVar_15700 = (cppVar_15700 & cppMask_un_8_);
	cppVar_15702 = (cppVar_15700 == 152);
	if (cppVar_15702) {
	cppVar_15697 = SCON;
	} else {
	cppVar_15704 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15705 = (cppVar_15704 << 3) | 4;
	cppVar_15705 = (cppVar_15705 & cppMask_un_5_);
	cppVar_15706 = (0 << 5) | cppVar_15705;
	cppVar_15706 = (cppVar_15706 & cppMask_un_8_);
	cppVar_15708 = (cppVar_15706 == 153);
	if (cppVar_15708) {
	cppVar_15703 = SBUF;
	} else {
	cppVar_15710 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15711 = (cppVar_15710 << 3) | 4;
	cppVar_15711 = (cppVar_15711 & cppMask_un_5_);
	cppVar_15712 = (0 << 5) | cppVar_15711;
	cppVar_15712 = (cppVar_15712 & cppMask_un_8_);
	cppVar_15714 = (cppVar_15712 == 160);
	if (cppVar_15714) {
	cppVar_15709 = P2;
	} else {
	cppVar_15716 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15717 = (cppVar_15716 << 3) | 4;
	cppVar_15717 = (cppVar_15717 & cppMask_un_5_);
	cppVar_15718 = (0 << 5) | cppVar_15717;
	cppVar_15718 = (cppVar_15718 & cppMask_un_8_);
	cppVar_15720 = (cppVar_15718 == 168);
	if (cppVar_15720) {
	cppVar_15715 = IE;
	} else {
	cppVar_15722 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15723 = (cppVar_15722 << 3) | 4;
	cppVar_15723 = (cppVar_15723 & cppMask_un_5_);
	cppVar_15724 = (0 << 5) | cppVar_15723;
	cppVar_15724 = (cppVar_15724 & cppMask_un_8_);
	cppVar_15726 = (cppVar_15724 == 176);
	if (cppVar_15726) {
	cppVar_15721 = P3;
	} else {
	cppVar_15728 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15729 = (cppVar_15728 << 3) | 4;
	cppVar_15729 = (cppVar_15729 & cppMask_un_5_);
	cppVar_15730 = (0 << 5) | cppVar_15729;
	cppVar_15730 = (cppVar_15730 & cppMask_un_8_);
	cppVar_15732 = (cppVar_15730 == 184);
	if (cppVar_15732) {
	cppVar_15727 = IP;
	} else {
	cppVar_15734 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15735 = (cppVar_15734 << 3) | 4;
	cppVar_15735 = (cppVar_15735 & cppMask_un_5_);
	cppVar_15736 = (0 << 5) | cppVar_15735;
	cppVar_15736 = (cppVar_15736 & cppMask_un_8_);
	cppVar_15738 = (cppVar_15736 == 208);
	if (cppVar_15738) {
	cppVar_15733 = PSW;
	} else {
	cppVar_15740 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15741 = (cppVar_15740 << 3) | 4;
	cppVar_15741 = (cppVar_15741 & cppMask_un_5_);
	cppVar_15742 = (0 << 5) | cppVar_15741;
	cppVar_15742 = (cppVar_15742 & cppMask_un_8_);
	cppVar_15744 = (cppVar_15742 == 224);
	if (cppVar_15744) {
	cppVar_15739 = ACC;
	} else {
	cppVar_15746 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15747 = (cppVar_15746 << 3) | 4;
	cppVar_15747 = (cppVar_15747 & cppMask_un_5_);
	cppVar_15748 = (0 << 5) | cppVar_15747;
	cppVar_15748 = (cppVar_15748 & cppMask_un_8_);
	cppVar_15750 = (cppVar_15748 == 240);
	if (cppVar_15750) {
	cppVar_15745 = B;
	} else {
	cppVar_15745 = 0;
	}
	cppVar_15739 = cppVar_15745;
	}
	cppVar_15733 = cppVar_15739;
	}
	cppVar_15727 = cppVar_15733;
	}
	cppVar_15721 = cppVar_15727;
	}
	cppVar_15715 = cppVar_15721;
	}
	cppVar_15709 = cppVar_15715;
	}
	cppVar_15703 = cppVar_15709;
	}
	cppVar_15697 = cppVar_15703;
	}
	cppVar_15691 = cppVar_15697;
	}
	cppVar_15685 = cppVar_15691;
	}
	cppVar_15679 = cppVar_15685;
	}
	cppVar_15673 = cppVar_15679;
	}
	cppVar_15667 = cppVar_15673;
	}
	cppVar_15661 = cppVar_15667;
	}
	cppVar_15655 = cppVar_15661;
	}
	cppVar_15649 = cppVar_15655;
	}
	cppVar_15643 = cppVar_15649;
	}
	cppVar_15637 = cppVar_15643;
	}
	cppVar_15631 = cppVar_15637;
	}
	cppVar_15625 = cppVar_15631;
	}
	cppVar_15612 = cppVar_15625;
	}
	cppVar_15606 = cppVar_15612;
	} else {
	cppVar_15606 = IE;
	}
	cppVar_15602 = cppVar_15606;
	} else {
	cppVar_15753 = ROM.rd(PC);
	cppVar_15755 = (cppVar_15753 == 139);
	if (cppVar_15755) {
	cppVar_15758 = PC + 1;
	cppVar_15758 = (cppVar_15758 & cppMask_un_16_);
	cppVar_15759 = ROM.rd(cppVar_15758);
	cppVar_15761 = (cppVar_15759 == 168);
	if (cppVar_15761) {
	cppVar_15764 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15766 = (cppVar_15764 << 3) | 3;
	cppVar_15766 = (cppVar_15766 & cppMask_un_5_);
	cppVar_15767 = (0 << 5) | cppVar_15766;
	cppVar_15767 = (cppVar_15767 & cppMask_un_8_);
	cppVar_15768 = (cppVar_15767 >> 7) & cppMask_un_1_;
	cppVar_15770 = (cppVar_15768 == 0);
	if (cppVar_15770) {
	cppVar_15771 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15772 = (cppVar_15771 << 3) | 3;
	cppVar_15772 = (cppVar_15772 & cppMask_un_5_);
	cppVar_15773 = (0 << 5) | cppVar_15772;
	cppVar_15773 = (cppVar_15773 & cppMask_un_8_);
	cppVar_15774 = IRAM.rd(cppVar_15773);
	cppVar_15762 = cppVar_15774;
	} else {
	cppVar_15776 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15777 = (cppVar_15776 << 3) | 3;
	cppVar_15777 = (cppVar_15777 & cppMask_un_5_);
	cppVar_15778 = (0 << 5) | cppVar_15777;
	cppVar_15778 = (cppVar_15778 & cppMask_un_8_);
	cppVar_15780 = (cppVar_15778 == 128);
	if (cppVar_15780) {
	cppVar_15775 = P0;
	} else {
	cppVar_15782 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15783 = (cppVar_15782 << 3) | 3;
	cppVar_15783 = (cppVar_15783 & cppMask_un_5_);
	cppVar_15784 = (0 << 5) | cppVar_15783;
	cppVar_15784 = (cppVar_15784 & cppMask_un_8_);
	cppVar_15786 = (cppVar_15784 == 129);
	if (cppVar_15786) {
	cppVar_15781 = SP;
	} else {
	cppVar_15788 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15789 = (cppVar_15788 << 3) | 3;
	cppVar_15789 = (cppVar_15789 & cppMask_un_5_);
	cppVar_15790 = (0 << 5) | cppVar_15789;
	cppVar_15790 = (cppVar_15790 & cppMask_un_8_);
	cppVar_15792 = (cppVar_15790 == 130);
	if (cppVar_15792) {
	cppVar_15787 = DPL;
	} else {
	cppVar_15794 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15795 = (cppVar_15794 << 3) | 3;
	cppVar_15795 = (cppVar_15795 & cppMask_un_5_);
	cppVar_15796 = (0 << 5) | cppVar_15795;
	cppVar_15796 = (cppVar_15796 & cppMask_un_8_);
	cppVar_15798 = (cppVar_15796 == 131);
	if (cppVar_15798) {
	cppVar_15793 = DPH;
	} else {
	cppVar_15800 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15801 = (cppVar_15800 << 3) | 3;
	cppVar_15801 = (cppVar_15801 & cppMask_un_5_);
	cppVar_15802 = (0 << 5) | cppVar_15801;
	cppVar_15802 = (cppVar_15802 & cppMask_un_8_);
	cppVar_15804 = (cppVar_15802 == 135);
	if (cppVar_15804) {
	cppVar_15799 = PCON;
	} else {
	cppVar_15806 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15807 = (cppVar_15806 << 3) | 3;
	cppVar_15807 = (cppVar_15807 & cppMask_un_5_);
	cppVar_15808 = (0 << 5) | cppVar_15807;
	cppVar_15808 = (cppVar_15808 & cppMask_un_8_);
	cppVar_15810 = (cppVar_15808 == 136);
	if (cppVar_15810) {
	cppVar_15805 = TCON;
	} else {
	cppVar_15812 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15813 = (cppVar_15812 << 3) | 3;
	cppVar_15813 = (cppVar_15813 & cppMask_un_5_);
	cppVar_15814 = (0 << 5) | cppVar_15813;
	cppVar_15814 = (cppVar_15814 & cppMask_un_8_);
	cppVar_15816 = (cppVar_15814 == 137);
	if (cppVar_15816) {
	cppVar_15811 = TMOD;
	} else {
	cppVar_15818 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15819 = (cppVar_15818 << 3) | 3;
	cppVar_15819 = (cppVar_15819 & cppMask_un_5_);
	cppVar_15820 = (0 << 5) | cppVar_15819;
	cppVar_15820 = (cppVar_15820 & cppMask_un_8_);
	cppVar_15822 = (cppVar_15820 == 138);
	if (cppVar_15822) {
	cppVar_15817 = TL0;
	} else {
	cppVar_15824 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15825 = (cppVar_15824 << 3) | 3;
	cppVar_15825 = (cppVar_15825 & cppMask_un_5_);
	cppVar_15826 = (0 << 5) | cppVar_15825;
	cppVar_15826 = (cppVar_15826 & cppMask_un_8_);
	cppVar_15828 = (cppVar_15826 == 140);
	if (cppVar_15828) {
	cppVar_15823 = TH0;
	} else {
	cppVar_15830 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15831 = (cppVar_15830 << 3) | 3;
	cppVar_15831 = (cppVar_15831 & cppMask_un_5_);
	cppVar_15832 = (0 << 5) | cppVar_15831;
	cppVar_15832 = (cppVar_15832 & cppMask_un_8_);
	cppVar_15834 = (cppVar_15832 == 139);
	if (cppVar_15834) {
	cppVar_15829 = TL1;
	} else {
	cppVar_15836 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15837 = (cppVar_15836 << 3) | 3;
	cppVar_15837 = (cppVar_15837 & cppMask_un_5_);
	cppVar_15838 = (0 << 5) | cppVar_15837;
	cppVar_15838 = (cppVar_15838 & cppMask_un_8_);
	cppVar_15840 = (cppVar_15838 == 141);
	if (cppVar_15840) {
	cppVar_15835 = TH1;
	} else {
	cppVar_15842 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15843 = (cppVar_15842 << 3) | 3;
	cppVar_15843 = (cppVar_15843 & cppMask_un_5_);
	cppVar_15844 = (0 << 5) | cppVar_15843;
	cppVar_15844 = (cppVar_15844 & cppMask_un_8_);
	cppVar_15846 = (cppVar_15844 == 144);
	if (cppVar_15846) {
	cppVar_15841 = P1;
	} else {
	cppVar_15848 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15849 = (cppVar_15848 << 3) | 3;
	cppVar_15849 = (cppVar_15849 & cppMask_un_5_);
	cppVar_15850 = (0 << 5) | cppVar_15849;
	cppVar_15850 = (cppVar_15850 & cppMask_un_8_);
	cppVar_15852 = (cppVar_15850 == 152);
	if (cppVar_15852) {
	cppVar_15847 = SCON;
	} else {
	cppVar_15854 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15855 = (cppVar_15854 << 3) | 3;
	cppVar_15855 = (cppVar_15855 & cppMask_un_5_);
	cppVar_15856 = (0 << 5) | cppVar_15855;
	cppVar_15856 = (cppVar_15856 & cppMask_un_8_);
	cppVar_15858 = (cppVar_15856 == 153);
	if (cppVar_15858) {
	cppVar_15853 = SBUF;
	} else {
	cppVar_15860 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15861 = (cppVar_15860 << 3) | 3;
	cppVar_15861 = (cppVar_15861 & cppMask_un_5_);
	cppVar_15862 = (0 << 5) | cppVar_15861;
	cppVar_15862 = (cppVar_15862 & cppMask_un_8_);
	cppVar_15864 = (cppVar_15862 == 160);
	if (cppVar_15864) {
	cppVar_15859 = P2;
	} else {
	cppVar_15866 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15867 = (cppVar_15866 << 3) | 3;
	cppVar_15867 = (cppVar_15867 & cppMask_un_5_);
	cppVar_15868 = (0 << 5) | cppVar_15867;
	cppVar_15868 = (cppVar_15868 & cppMask_un_8_);
	cppVar_15870 = (cppVar_15868 == 168);
	if (cppVar_15870) {
	cppVar_15865 = IE;
	} else {
	cppVar_15872 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15873 = (cppVar_15872 << 3) | 3;
	cppVar_15873 = (cppVar_15873 & cppMask_un_5_);
	cppVar_15874 = (0 << 5) | cppVar_15873;
	cppVar_15874 = (cppVar_15874 & cppMask_un_8_);
	cppVar_15876 = (cppVar_15874 == 176);
	if (cppVar_15876) {
	cppVar_15871 = P3;
	} else {
	cppVar_15878 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15879 = (cppVar_15878 << 3) | 3;
	cppVar_15879 = (cppVar_15879 & cppMask_un_5_);
	cppVar_15880 = (0 << 5) | cppVar_15879;
	cppVar_15880 = (cppVar_15880 & cppMask_un_8_);
	cppVar_15882 = (cppVar_15880 == 184);
	if (cppVar_15882) {
	cppVar_15877 = IP;
	} else {
	cppVar_15884 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15885 = (cppVar_15884 << 3) | 3;
	cppVar_15885 = (cppVar_15885 & cppMask_un_5_);
	cppVar_15886 = (0 << 5) | cppVar_15885;
	cppVar_15886 = (cppVar_15886 & cppMask_un_8_);
	cppVar_15888 = (cppVar_15886 == 208);
	if (cppVar_15888) {
	cppVar_15883 = PSW;
	} else {
	cppVar_15890 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15891 = (cppVar_15890 << 3) | 3;
	cppVar_15891 = (cppVar_15891 & cppMask_un_5_);
	cppVar_15892 = (0 << 5) | cppVar_15891;
	cppVar_15892 = (cppVar_15892 & cppMask_un_8_);
	cppVar_15894 = (cppVar_15892 == 224);
	if (cppVar_15894) {
	cppVar_15889 = ACC;
	} else {
	cppVar_15896 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15897 = (cppVar_15896 << 3) | 3;
	cppVar_15897 = (cppVar_15897 & cppMask_un_5_);
	cppVar_15898 = (0 << 5) | cppVar_15897;
	cppVar_15898 = (cppVar_15898 & cppMask_un_8_);
	cppVar_15900 = (cppVar_15898 == 240);
	if (cppVar_15900) {
	cppVar_15895 = B;
	} else {
	cppVar_15895 = 0;
	}
	cppVar_15889 = cppVar_15895;
	}
	cppVar_15883 = cppVar_15889;
	}
	cppVar_15877 = cppVar_15883;
	}
	cppVar_15871 = cppVar_15877;
	}
	cppVar_15865 = cppVar_15871;
	}
	cppVar_15859 = cppVar_15865;
	}
	cppVar_15853 = cppVar_15859;
	}
	cppVar_15847 = cppVar_15853;
	}
	cppVar_15841 = cppVar_15847;
	}
	cppVar_15835 = cppVar_15841;
	}
	cppVar_15829 = cppVar_15835;
	}
	cppVar_15823 = cppVar_15829;
	}
	cppVar_15817 = cppVar_15823;
	}
	cppVar_15811 = cppVar_15817;
	}
	cppVar_15805 = cppVar_15811;
	}
	cppVar_15799 = cppVar_15805;
	}
	cppVar_15793 = cppVar_15799;
	}
	cppVar_15787 = cppVar_15793;
	}
	cppVar_15781 = cppVar_15787;
	}
	cppVar_15775 = cppVar_15781;
	}
	cppVar_15762 = cppVar_15775;
	}
	cppVar_15756 = cppVar_15762;
	} else {
	cppVar_15756 = IE;
	}
	cppVar_15752 = cppVar_15756;
	} else {
	cppVar_15903 = ROM.rd(PC);
	cppVar_15905 = (cppVar_15903 == 138);
	if (cppVar_15905) {
	cppVar_15908 = PC + 1;
	cppVar_15908 = (cppVar_15908 & cppMask_un_16_);
	cppVar_15909 = ROM.rd(cppVar_15908);
	cppVar_15911 = (cppVar_15909 == 168);
	if (cppVar_15911) {
	cppVar_15914 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15916 = (cppVar_15914 << 3) | 2;
	cppVar_15916 = (cppVar_15916 & cppMask_un_5_);
	cppVar_15917 = (0 << 5) | cppVar_15916;
	cppVar_15917 = (cppVar_15917 & cppMask_un_8_);
	cppVar_15918 = (cppVar_15917 >> 7) & cppMask_un_1_;
	cppVar_15920 = (cppVar_15918 == 0);
	if (cppVar_15920) {
	cppVar_15921 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15922 = (cppVar_15921 << 3) | 2;
	cppVar_15922 = (cppVar_15922 & cppMask_un_5_);
	cppVar_15923 = (0 << 5) | cppVar_15922;
	cppVar_15923 = (cppVar_15923 & cppMask_un_8_);
	cppVar_15924 = IRAM.rd(cppVar_15923);
	cppVar_15912 = cppVar_15924;
	} else {
	cppVar_15926 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15927 = (cppVar_15926 << 3) | 2;
	cppVar_15927 = (cppVar_15927 & cppMask_un_5_);
	cppVar_15928 = (0 << 5) | cppVar_15927;
	cppVar_15928 = (cppVar_15928 & cppMask_un_8_);
	cppVar_15930 = (cppVar_15928 == 128);
	if (cppVar_15930) {
	cppVar_15925 = P0;
	} else {
	cppVar_15932 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15933 = (cppVar_15932 << 3) | 2;
	cppVar_15933 = (cppVar_15933 & cppMask_un_5_);
	cppVar_15934 = (0 << 5) | cppVar_15933;
	cppVar_15934 = (cppVar_15934 & cppMask_un_8_);
	cppVar_15936 = (cppVar_15934 == 129);
	if (cppVar_15936) {
	cppVar_15931 = SP;
	} else {
	cppVar_15938 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15939 = (cppVar_15938 << 3) | 2;
	cppVar_15939 = (cppVar_15939 & cppMask_un_5_);
	cppVar_15940 = (0 << 5) | cppVar_15939;
	cppVar_15940 = (cppVar_15940 & cppMask_un_8_);
	cppVar_15942 = (cppVar_15940 == 130);
	if (cppVar_15942) {
	cppVar_15937 = DPL;
	} else {
	cppVar_15944 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15945 = (cppVar_15944 << 3) | 2;
	cppVar_15945 = (cppVar_15945 & cppMask_un_5_);
	cppVar_15946 = (0 << 5) | cppVar_15945;
	cppVar_15946 = (cppVar_15946 & cppMask_un_8_);
	cppVar_15948 = (cppVar_15946 == 131);
	if (cppVar_15948) {
	cppVar_15943 = DPH;
	} else {
	cppVar_15950 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15951 = (cppVar_15950 << 3) | 2;
	cppVar_15951 = (cppVar_15951 & cppMask_un_5_);
	cppVar_15952 = (0 << 5) | cppVar_15951;
	cppVar_15952 = (cppVar_15952 & cppMask_un_8_);
	cppVar_15954 = (cppVar_15952 == 135);
	if (cppVar_15954) {
	cppVar_15949 = PCON;
	} else {
	cppVar_15956 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15957 = (cppVar_15956 << 3) | 2;
	cppVar_15957 = (cppVar_15957 & cppMask_un_5_);
	cppVar_15958 = (0 << 5) | cppVar_15957;
	cppVar_15958 = (cppVar_15958 & cppMask_un_8_);
	cppVar_15960 = (cppVar_15958 == 136);
	if (cppVar_15960) {
	cppVar_15955 = TCON;
	} else {
	cppVar_15962 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15963 = (cppVar_15962 << 3) | 2;
	cppVar_15963 = (cppVar_15963 & cppMask_un_5_);
	cppVar_15964 = (0 << 5) | cppVar_15963;
	cppVar_15964 = (cppVar_15964 & cppMask_un_8_);
	cppVar_15966 = (cppVar_15964 == 137);
	if (cppVar_15966) {
	cppVar_15961 = TMOD;
	} else {
	cppVar_15968 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15969 = (cppVar_15968 << 3) | 2;
	cppVar_15969 = (cppVar_15969 & cppMask_un_5_);
	cppVar_15970 = (0 << 5) | cppVar_15969;
	cppVar_15970 = (cppVar_15970 & cppMask_un_8_);
	cppVar_15972 = (cppVar_15970 == 138);
	if (cppVar_15972) {
	cppVar_15967 = TL0;
	} else {
	cppVar_15974 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15975 = (cppVar_15974 << 3) | 2;
	cppVar_15975 = (cppVar_15975 & cppMask_un_5_);
	cppVar_15976 = (0 << 5) | cppVar_15975;
	cppVar_15976 = (cppVar_15976 & cppMask_un_8_);
	cppVar_15978 = (cppVar_15976 == 140);
	if (cppVar_15978) {
	cppVar_15973 = TH0;
	} else {
	cppVar_15980 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15981 = (cppVar_15980 << 3) | 2;
	cppVar_15981 = (cppVar_15981 & cppMask_un_5_);
	cppVar_15982 = (0 << 5) | cppVar_15981;
	cppVar_15982 = (cppVar_15982 & cppMask_un_8_);
	cppVar_15984 = (cppVar_15982 == 139);
	if (cppVar_15984) {
	cppVar_15979 = TL1;
	} else {
	cppVar_15986 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15987 = (cppVar_15986 << 3) | 2;
	cppVar_15987 = (cppVar_15987 & cppMask_un_5_);
	cppVar_15988 = (0 << 5) | cppVar_15987;
	cppVar_15988 = (cppVar_15988 & cppMask_un_8_);
	cppVar_15990 = (cppVar_15988 == 141);
	if (cppVar_15990) {
	cppVar_15985 = TH1;
	} else {
	cppVar_15992 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15993 = (cppVar_15992 << 3) | 2;
	cppVar_15993 = (cppVar_15993 & cppMask_un_5_);
	cppVar_15994 = (0 << 5) | cppVar_15993;
	cppVar_15994 = (cppVar_15994 & cppMask_un_8_);
	cppVar_15996 = (cppVar_15994 == 144);
	if (cppVar_15996) {
	cppVar_15991 = P1;
	} else {
	cppVar_15998 = (PSW >> 3) & cppMask_un_2_;
	cppVar_15999 = (cppVar_15998 << 3) | 2;
	cppVar_15999 = (cppVar_15999 & cppMask_un_5_);
	cppVar_16000 = (0 << 5) | cppVar_15999;
	cppVar_16000 = (cppVar_16000 & cppMask_un_8_);
	cppVar_16002 = (cppVar_16000 == 152);
	if (cppVar_16002) {
	cppVar_15997 = SCON;
	} else {
	cppVar_16004 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16005 = (cppVar_16004 << 3) | 2;
	cppVar_16005 = (cppVar_16005 & cppMask_un_5_);
	cppVar_16006 = (0 << 5) | cppVar_16005;
	cppVar_16006 = (cppVar_16006 & cppMask_un_8_);
	cppVar_16008 = (cppVar_16006 == 153);
	if (cppVar_16008) {
	cppVar_16003 = SBUF;
	} else {
	cppVar_16010 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16011 = (cppVar_16010 << 3) | 2;
	cppVar_16011 = (cppVar_16011 & cppMask_un_5_);
	cppVar_16012 = (0 << 5) | cppVar_16011;
	cppVar_16012 = (cppVar_16012 & cppMask_un_8_);
	cppVar_16014 = (cppVar_16012 == 160);
	if (cppVar_16014) {
	cppVar_16009 = P2;
	} else {
	cppVar_16016 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16017 = (cppVar_16016 << 3) | 2;
	cppVar_16017 = (cppVar_16017 & cppMask_un_5_);
	cppVar_16018 = (0 << 5) | cppVar_16017;
	cppVar_16018 = (cppVar_16018 & cppMask_un_8_);
	cppVar_16020 = (cppVar_16018 == 168);
	if (cppVar_16020) {
	cppVar_16015 = IE;
	} else {
	cppVar_16022 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16023 = (cppVar_16022 << 3) | 2;
	cppVar_16023 = (cppVar_16023 & cppMask_un_5_);
	cppVar_16024 = (0 << 5) | cppVar_16023;
	cppVar_16024 = (cppVar_16024 & cppMask_un_8_);
	cppVar_16026 = (cppVar_16024 == 176);
	if (cppVar_16026) {
	cppVar_16021 = P3;
	} else {
	cppVar_16028 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16029 = (cppVar_16028 << 3) | 2;
	cppVar_16029 = (cppVar_16029 & cppMask_un_5_);
	cppVar_16030 = (0 << 5) | cppVar_16029;
	cppVar_16030 = (cppVar_16030 & cppMask_un_8_);
	cppVar_16032 = (cppVar_16030 == 184);
	if (cppVar_16032) {
	cppVar_16027 = IP;
	} else {
	cppVar_16034 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16035 = (cppVar_16034 << 3) | 2;
	cppVar_16035 = (cppVar_16035 & cppMask_un_5_);
	cppVar_16036 = (0 << 5) | cppVar_16035;
	cppVar_16036 = (cppVar_16036 & cppMask_un_8_);
	cppVar_16038 = (cppVar_16036 == 208);
	if (cppVar_16038) {
	cppVar_16033 = PSW;
	} else {
	cppVar_16040 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16041 = (cppVar_16040 << 3) | 2;
	cppVar_16041 = (cppVar_16041 & cppMask_un_5_);
	cppVar_16042 = (0 << 5) | cppVar_16041;
	cppVar_16042 = (cppVar_16042 & cppMask_un_8_);
	cppVar_16044 = (cppVar_16042 == 224);
	if (cppVar_16044) {
	cppVar_16039 = ACC;
	} else {
	cppVar_16046 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16047 = (cppVar_16046 << 3) | 2;
	cppVar_16047 = (cppVar_16047 & cppMask_un_5_);
	cppVar_16048 = (0 << 5) | cppVar_16047;
	cppVar_16048 = (cppVar_16048 & cppMask_un_8_);
	cppVar_16050 = (cppVar_16048 == 240);
	if (cppVar_16050) {
	cppVar_16045 = B;
	} else {
	cppVar_16045 = 0;
	}
	cppVar_16039 = cppVar_16045;
	}
	cppVar_16033 = cppVar_16039;
	}
	cppVar_16027 = cppVar_16033;
	}
	cppVar_16021 = cppVar_16027;
	}
	cppVar_16015 = cppVar_16021;
	}
	cppVar_16009 = cppVar_16015;
	}
	cppVar_16003 = cppVar_16009;
	}
	cppVar_15997 = cppVar_16003;
	}
	cppVar_15991 = cppVar_15997;
	}
	cppVar_15985 = cppVar_15991;
	}
	cppVar_15979 = cppVar_15985;
	}
	cppVar_15973 = cppVar_15979;
	}
	cppVar_15967 = cppVar_15973;
	}
	cppVar_15961 = cppVar_15967;
	}
	cppVar_15955 = cppVar_15961;
	}
	cppVar_15949 = cppVar_15955;
	}
	cppVar_15943 = cppVar_15949;
	}
	cppVar_15937 = cppVar_15943;
	}
	cppVar_15931 = cppVar_15937;
	}
	cppVar_15925 = cppVar_15931;
	}
	cppVar_15912 = cppVar_15925;
	}
	cppVar_15906 = cppVar_15912;
	} else {
	cppVar_15906 = IE;
	}
	cppVar_15902 = cppVar_15906;
	} else {
	cppVar_16053 = ROM.rd(PC);
	cppVar_16055 = (cppVar_16053 == 137);
	if (cppVar_16055) {
	cppVar_16058 = PC + 1;
	cppVar_16058 = (cppVar_16058 & cppMask_un_16_);
	cppVar_16059 = ROM.rd(cppVar_16058);
	cppVar_16061 = (cppVar_16059 == 168);
	if (cppVar_16061) {
	cppVar_16064 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16066 = (cppVar_16064 << 3) | 1;
	cppVar_16066 = (cppVar_16066 & cppMask_un_5_);
	cppVar_16067 = (0 << 5) | cppVar_16066;
	cppVar_16067 = (cppVar_16067 & cppMask_un_8_);
	cppVar_16068 = (cppVar_16067 >> 7) & cppMask_un_1_;
	cppVar_16070 = (cppVar_16068 == 0);
	if (cppVar_16070) {
	cppVar_16071 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16072 = (cppVar_16071 << 3) | 1;
	cppVar_16072 = (cppVar_16072 & cppMask_un_5_);
	cppVar_16073 = (0 << 5) | cppVar_16072;
	cppVar_16073 = (cppVar_16073 & cppMask_un_8_);
	cppVar_16074 = IRAM.rd(cppVar_16073);
	cppVar_16062 = cppVar_16074;
	} else {
	cppVar_16076 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16077 = (cppVar_16076 << 3) | 1;
	cppVar_16077 = (cppVar_16077 & cppMask_un_5_);
	cppVar_16078 = (0 << 5) | cppVar_16077;
	cppVar_16078 = (cppVar_16078 & cppMask_un_8_);
	cppVar_16080 = (cppVar_16078 == 128);
	if (cppVar_16080) {
	cppVar_16075 = P0;
	} else {
	cppVar_16082 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16083 = (cppVar_16082 << 3) | 1;
	cppVar_16083 = (cppVar_16083 & cppMask_un_5_);
	cppVar_16084 = (0 << 5) | cppVar_16083;
	cppVar_16084 = (cppVar_16084 & cppMask_un_8_);
	cppVar_16086 = (cppVar_16084 == 129);
	if (cppVar_16086) {
	cppVar_16081 = SP;
	} else {
	cppVar_16088 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16089 = (cppVar_16088 << 3) | 1;
	cppVar_16089 = (cppVar_16089 & cppMask_un_5_);
	cppVar_16090 = (0 << 5) | cppVar_16089;
	cppVar_16090 = (cppVar_16090 & cppMask_un_8_);
	cppVar_16092 = (cppVar_16090 == 130);
	if (cppVar_16092) {
	cppVar_16087 = DPL;
	} else {
	cppVar_16094 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16095 = (cppVar_16094 << 3) | 1;
	cppVar_16095 = (cppVar_16095 & cppMask_un_5_);
	cppVar_16096 = (0 << 5) | cppVar_16095;
	cppVar_16096 = (cppVar_16096 & cppMask_un_8_);
	cppVar_16098 = (cppVar_16096 == 131);
	if (cppVar_16098) {
	cppVar_16093 = DPH;
	} else {
	cppVar_16100 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16101 = (cppVar_16100 << 3) | 1;
	cppVar_16101 = (cppVar_16101 & cppMask_un_5_);
	cppVar_16102 = (0 << 5) | cppVar_16101;
	cppVar_16102 = (cppVar_16102 & cppMask_un_8_);
	cppVar_16104 = (cppVar_16102 == 135);
	if (cppVar_16104) {
	cppVar_16099 = PCON;
	} else {
	cppVar_16106 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16107 = (cppVar_16106 << 3) | 1;
	cppVar_16107 = (cppVar_16107 & cppMask_un_5_);
	cppVar_16108 = (0 << 5) | cppVar_16107;
	cppVar_16108 = (cppVar_16108 & cppMask_un_8_);
	cppVar_16110 = (cppVar_16108 == 136);
	if (cppVar_16110) {
	cppVar_16105 = TCON;
	} else {
	cppVar_16112 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16113 = (cppVar_16112 << 3) | 1;
	cppVar_16113 = (cppVar_16113 & cppMask_un_5_);
	cppVar_16114 = (0 << 5) | cppVar_16113;
	cppVar_16114 = (cppVar_16114 & cppMask_un_8_);
	cppVar_16116 = (cppVar_16114 == 137);
	if (cppVar_16116) {
	cppVar_16111 = TMOD;
	} else {
	cppVar_16118 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16119 = (cppVar_16118 << 3) | 1;
	cppVar_16119 = (cppVar_16119 & cppMask_un_5_);
	cppVar_16120 = (0 << 5) | cppVar_16119;
	cppVar_16120 = (cppVar_16120 & cppMask_un_8_);
	cppVar_16122 = (cppVar_16120 == 138);
	if (cppVar_16122) {
	cppVar_16117 = TL0;
	} else {
	cppVar_16124 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16125 = (cppVar_16124 << 3) | 1;
	cppVar_16125 = (cppVar_16125 & cppMask_un_5_);
	cppVar_16126 = (0 << 5) | cppVar_16125;
	cppVar_16126 = (cppVar_16126 & cppMask_un_8_);
	cppVar_16128 = (cppVar_16126 == 140);
	if (cppVar_16128) {
	cppVar_16123 = TH0;
	} else {
	cppVar_16130 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16131 = (cppVar_16130 << 3) | 1;
	cppVar_16131 = (cppVar_16131 & cppMask_un_5_);
	cppVar_16132 = (0 << 5) | cppVar_16131;
	cppVar_16132 = (cppVar_16132 & cppMask_un_8_);
	cppVar_16134 = (cppVar_16132 == 139);
	if (cppVar_16134) {
	cppVar_16129 = TL1;
	} else {
	cppVar_16136 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16137 = (cppVar_16136 << 3) | 1;
	cppVar_16137 = (cppVar_16137 & cppMask_un_5_);
	cppVar_16138 = (0 << 5) | cppVar_16137;
	cppVar_16138 = (cppVar_16138 & cppMask_un_8_);
	cppVar_16140 = (cppVar_16138 == 141);
	if (cppVar_16140) {
	cppVar_16135 = TH1;
	} else {
	cppVar_16142 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16143 = (cppVar_16142 << 3) | 1;
	cppVar_16143 = (cppVar_16143 & cppMask_un_5_);
	cppVar_16144 = (0 << 5) | cppVar_16143;
	cppVar_16144 = (cppVar_16144 & cppMask_un_8_);
	cppVar_16146 = (cppVar_16144 == 144);
	if (cppVar_16146) {
	cppVar_16141 = P1;
	} else {
	cppVar_16148 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16149 = (cppVar_16148 << 3) | 1;
	cppVar_16149 = (cppVar_16149 & cppMask_un_5_);
	cppVar_16150 = (0 << 5) | cppVar_16149;
	cppVar_16150 = (cppVar_16150 & cppMask_un_8_);
	cppVar_16152 = (cppVar_16150 == 152);
	if (cppVar_16152) {
	cppVar_16147 = SCON;
	} else {
	cppVar_16154 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16155 = (cppVar_16154 << 3) | 1;
	cppVar_16155 = (cppVar_16155 & cppMask_un_5_);
	cppVar_16156 = (0 << 5) | cppVar_16155;
	cppVar_16156 = (cppVar_16156 & cppMask_un_8_);
	cppVar_16158 = (cppVar_16156 == 153);
	if (cppVar_16158) {
	cppVar_16153 = SBUF;
	} else {
	cppVar_16160 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16161 = (cppVar_16160 << 3) | 1;
	cppVar_16161 = (cppVar_16161 & cppMask_un_5_);
	cppVar_16162 = (0 << 5) | cppVar_16161;
	cppVar_16162 = (cppVar_16162 & cppMask_un_8_);
	cppVar_16164 = (cppVar_16162 == 160);
	if (cppVar_16164) {
	cppVar_16159 = P2;
	} else {
	cppVar_16166 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16167 = (cppVar_16166 << 3) | 1;
	cppVar_16167 = (cppVar_16167 & cppMask_un_5_);
	cppVar_16168 = (0 << 5) | cppVar_16167;
	cppVar_16168 = (cppVar_16168 & cppMask_un_8_);
	cppVar_16170 = (cppVar_16168 == 168);
	if (cppVar_16170) {
	cppVar_16165 = IE;
	} else {
	cppVar_16172 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16173 = (cppVar_16172 << 3) | 1;
	cppVar_16173 = (cppVar_16173 & cppMask_un_5_);
	cppVar_16174 = (0 << 5) | cppVar_16173;
	cppVar_16174 = (cppVar_16174 & cppMask_un_8_);
	cppVar_16176 = (cppVar_16174 == 176);
	if (cppVar_16176) {
	cppVar_16171 = P3;
	} else {
	cppVar_16178 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16179 = (cppVar_16178 << 3) | 1;
	cppVar_16179 = (cppVar_16179 & cppMask_un_5_);
	cppVar_16180 = (0 << 5) | cppVar_16179;
	cppVar_16180 = (cppVar_16180 & cppMask_un_8_);
	cppVar_16182 = (cppVar_16180 == 184);
	if (cppVar_16182) {
	cppVar_16177 = IP;
	} else {
	cppVar_16184 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16185 = (cppVar_16184 << 3) | 1;
	cppVar_16185 = (cppVar_16185 & cppMask_un_5_);
	cppVar_16186 = (0 << 5) | cppVar_16185;
	cppVar_16186 = (cppVar_16186 & cppMask_un_8_);
	cppVar_16188 = (cppVar_16186 == 208);
	if (cppVar_16188) {
	cppVar_16183 = PSW;
	} else {
	cppVar_16190 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16191 = (cppVar_16190 << 3) | 1;
	cppVar_16191 = (cppVar_16191 & cppMask_un_5_);
	cppVar_16192 = (0 << 5) | cppVar_16191;
	cppVar_16192 = (cppVar_16192 & cppMask_un_8_);
	cppVar_16194 = (cppVar_16192 == 224);
	if (cppVar_16194) {
	cppVar_16189 = ACC;
	} else {
	cppVar_16196 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16197 = (cppVar_16196 << 3) | 1;
	cppVar_16197 = (cppVar_16197 & cppMask_un_5_);
	cppVar_16198 = (0 << 5) | cppVar_16197;
	cppVar_16198 = (cppVar_16198 & cppMask_un_8_);
	cppVar_16200 = (cppVar_16198 == 240);
	if (cppVar_16200) {
	cppVar_16195 = B;
	} else {
	cppVar_16195 = 0;
	}
	cppVar_16189 = cppVar_16195;
	}
	cppVar_16183 = cppVar_16189;
	}
	cppVar_16177 = cppVar_16183;
	}
	cppVar_16171 = cppVar_16177;
	}
	cppVar_16165 = cppVar_16171;
	}
	cppVar_16159 = cppVar_16165;
	}
	cppVar_16153 = cppVar_16159;
	}
	cppVar_16147 = cppVar_16153;
	}
	cppVar_16141 = cppVar_16147;
	}
	cppVar_16135 = cppVar_16141;
	}
	cppVar_16129 = cppVar_16135;
	}
	cppVar_16123 = cppVar_16129;
	}
	cppVar_16117 = cppVar_16123;
	}
	cppVar_16111 = cppVar_16117;
	}
	cppVar_16105 = cppVar_16111;
	}
	cppVar_16099 = cppVar_16105;
	}
	cppVar_16093 = cppVar_16099;
	}
	cppVar_16087 = cppVar_16093;
	}
	cppVar_16081 = cppVar_16087;
	}
	cppVar_16075 = cppVar_16081;
	}
	cppVar_16062 = cppVar_16075;
	}
	cppVar_16056 = cppVar_16062;
	} else {
	cppVar_16056 = IE;
	}
	cppVar_16052 = cppVar_16056;
	} else {
	cppVar_16203 = ROM.rd(PC);
	cppVar_16205 = (cppVar_16203 == 136);
	if (cppVar_16205) {
	cppVar_16208 = PC + 1;
	cppVar_16208 = (cppVar_16208 & cppMask_un_16_);
	cppVar_16209 = ROM.rd(cppVar_16208);
	cppVar_16211 = (cppVar_16209 == 168);
	if (cppVar_16211) {
	cppVar_16214 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16216 = (cppVar_16214 << 3) | 0;
	cppVar_16216 = (cppVar_16216 & cppMask_un_5_);
	cppVar_16217 = (0 << 5) | cppVar_16216;
	cppVar_16217 = (cppVar_16217 & cppMask_un_8_);
	cppVar_16218 = (cppVar_16217 >> 7) & cppMask_un_1_;
	cppVar_16220 = (cppVar_16218 == 0);
	if (cppVar_16220) {
	cppVar_16221 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16222 = (cppVar_16221 << 3) | 0;
	cppVar_16222 = (cppVar_16222 & cppMask_un_5_);
	cppVar_16223 = (0 << 5) | cppVar_16222;
	cppVar_16223 = (cppVar_16223 & cppMask_un_8_);
	cppVar_16224 = IRAM.rd(cppVar_16223);
	cppVar_16212 = cppVar_16224;
	} else {
	cppVar_16226 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16227 = (cppVar_16226 << 3) | 0;
	cppVar_16227 = (cppVar_16227 & cppMask_un_5_);
	cppVar_16228 = (0 << 5) | cppVar_16227;
	cppVar_16228 = (cppVar_16228 & cppMask_un_8_);
	cppVar_16230 = (cppVar_16228 == 128);
	if (cppVar_16230) {
	cppVar_16225 = P0;
	} else {
	cppVar_16232 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16233 = (cppVar_16232 << 3) | 0;
	cppVar_16233 = (cppVar_16233 & cppMask_un_5_);
	cppVar_16234 = (0 << 5) | cppVar_16233;
	cppVar_16234 = (cppVar_16234 & cppMask_un_8_);
	cppVar_16236 = (cppVar_16234 == 129);
	if (cppVar_16236) {
	cppVar_16231 = SP;
	} else {
	cppVar_16238 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16239 = (cppVar_16238 << 3) | 0;
	cppVar_16239 = (cppVar_16239 & cppMask_un_5_);
	cppVar_16240 = (0 << 5) | cppVar_16239;
	cppVar_16240 = (cppVar_16240 & cppMask_un_8_);
	cppVar_16242 = (cppVar_16240 == 130);
	if (cppVar_16242) {
	cppVar_16237 = DPL;
	} else {
	cppVar_16244 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16245 = (cppVar_16244 << 3) | 0;
	cppVar_16245 = (cppVar_16245 & cppMask_un_5_);
	cppVar_16246 = (0 << 5) | cppVar_16245;
	cppVar_16246 = (cppVar_16246 & cppMask_un_8_);
	cppVar_16248 = (cppVar_16246 == 131);
	if (cppVar_16248) {
	cppVar_16243 = DPH;
	} else {
	cppVar_16250 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16251 = (cppVar_16250 << 3) | 0;
	cppVar_16251 = (cppVar_16251 & cppMask_un_5_);
	cppVar_16252 = (0 << 5) | cppVar_16251;
	cppVar_16252 = (cppVar_16252 & cppMask_un_8_);
	cppVar_16254 = (cppVar_16252 == 135);
	if (cppVar_16254) {
	cppVar_16249 = PCON;
	} else {
	cppVar_16256 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16257 = (cppVar_16256 << 3) | 0;
	cppVar_16257 = (cppVar_16257 & cppMask_un_5_);
	cppVar_16258 = (0 << 5) | cppVar_16257;
	cppVar_16258 = (cppVar_16258 & cppMask_un_8_);
	cppVar_16260 = (cppVar_16258 == 136);
	if (cppVar_16260) {
	cppVar_16255 = TCON;
	} else {
	cppVar_16262 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16263 = (cppVar_16262 << 3) | 0;
	cppVar_16263 = (cppVar_16263 & cppMask_un_5_);
	cppVar_16264 = (0 << 5) | cppVar_16263;
	cppVar_16264 = (cppVar_16264 & cppMask_un_8_);
	cppVar_16266 = (cppVar_16264 == 137);
	if (cppVar_16266) {
	cppVar_16261 = TMOD;
	} else {
	cppVar_16268 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16269 = (cppVar_16268 << 3) | 0;
	cppVar_16269 = (cppVar_16269 & cppMask_un_5_);
	cppVar_16270 = (0 << 5) | cppVar_16269;
	cppVar_16270 = (cppVar_16270 & cppMask_un_8_);
	cppVar_16272 = (cppVar_16270 == 138);
	if (cppVar_16272) {
	cppVar_16267 = TL0;
	} else {
	cppVar_16274 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16275 = (cppVar_16274 << 3) | 0;
	cppVar_16275 = (cppVar_16275 & cppMask_un_5_);
	cppVar_16276 = (0 << 5) | cppVar_16275;
	cppVar_16276 = (cppVar_16276 & cppMask_un_8_);
	cppVar_16278 = (cppVar_16276 == 140);
	if (cppVar_16278) {
	cppVar_16273 = TH0;
	} else {
	cppVar_16280 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16281 = (cppVar_16280 << 3) | 0;
	cppVar_16281 = (cppVar_16281 & cppMask_un_5_);
	cppVar_16282 = (0 << 5) | cppVar_16281;
	cppVar_16282 = (cppVar_16282 & cppMask_un_8_);
	cppVar_16284 = (cppVar_16282 == 139);
	if (cppVar_16284) {
	cppVar_16279 = TL1;
	} else {
	cppVar_16286 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16287 = (cppVar_16286 << 3) | 0;
	cppVar_16287 = (cppVar_16287 & cppMask_un_5_);
	cppVar_16288 = (0 << 5) | cppVar_16287;
	cppVar_16288 = (cppVar_16288 & cppMask_un_8_);
	cppVar_16290 = (cppVar_16288 == 141);
	if (cppVar_16290) {
	cppVar_16285 = TH1;
	} else {
	cppVar_16292 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16293 = (cppVar_16292 << 3) | 0;
	cppVar_16293 = (cppVar_16293 & cppMask_un_5_);
	cppVar_16294 = (0 << 5) | cppVar_16293;
	cppVar_16294 = (cppVar_16294 & cppMask_un_8_);
	cppVar_16296 = (cppVar_16294 == 144);
	if (cppVar_16296) {
	cppVar_16291 = P1;
	} else {
	cppVar_16298 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16299 = (cppVar_16298 << 3) | 0;
	cppVar_16299 = (cppVar_16299 & cppMask_un_5_);
	cppVar_16300 = (0 << 5) | cppVar_16299;
	cppVar_16300 = (cppVar_16300 & cppMask_un_8_);
	cppVar_16302 = (cppVar_16300 == 152);
	if (cppVar_16302) {
	cppVar_16297 = SCON;
	} else {
	cppVar_16304 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16305 = (cppVar_16304 << 3) | 0;
	cppVar_16305 = (cppVar_16305 & cppMask_un_5_);
	cppVar_16306 = (0 << 5) | cppVar_16305;
	cppVar_16306 = (cppVar_16306 & cppMask_un_8_);
	cppVar_16308 = (cppVar_16306 == 153);
	if (cppVar_16308) {
	cppVar_16303 = SBUF;
	} else {
	cppVar_16310 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16311 = (cppVar_16310 << 3) | 0;
	cppVar_16311 = (cppVar_16311 & cppMask_un_5_);
	cppVar_16312 = (0 << 5) | cppVar_16311;
	cppVar_16312 = (cppVar_16312 & cppMask_un_8_);
	cppVar_16314 = (cppVar_16312 == 160);
	if (cppVar_16314) {
	cppVar_16309 = P2;
	} else {
	cppVar_16316 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16317 = (cppVar_16316 << 3) | 0;
	cppVar_16317 = (cppVar_16317 & cppMask_un_5_);
	cppVar_16318 = (0 << 5) | cppVar_16317;
	cppVar_16318 = (cppVar_16318 & cppMask_un_8_);
	cppVar_16320 = (cppVar_16318 == 168);
	if (cppVar_16320) {
	cppVar_16315 = IE;
	} else {
	cppVar_16322 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16323 = (cppVar_16322 << 3) | 0;
	cppVar_16323 = (cppVar_16323 & cppMask_un_5_);
	cppVar_16324 = (0 << 5) | cppVar_16323;
	cppVar_16324 = (cppVar_16324 & cppMask_un_8_);
	cppVar_16326 = (cppVar_16324 == 176);
	if (cppVar_16326) {
	cppVar_16321 = P3;
	} else {
	cppVar_16328 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16329 = (cppVar_16328 << 3) | 0;
	cppVar_16329 = (cppVar_16329 & cppMask_un_5_);
	cppVar_16330 = (0 << 5) | cppVar_16329;
	cppVar_16330 = (cppVar_16330 & cppMask_un_8_);
	cppVar_16332 = (cppVar_16330 == 184);
	if (cppVar_16332) {
	cppVar_16327 = IP;
	} else {
	cppVar_16334 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16335 = (cppVar_16334 << 3) | 0;
	cppVar_16335 = (cppVar_16335 & cppMask_un_5_);
	cppVar_16336 = (0 << 5) | cppVar_16335;
	cppVar_16336 = (cppVar_16336 & cppMask_un_8_);
	cppVar_16338 = (cppVar_16336 == 208);
	if (cppVar_16338) {
	cppVar_16333 = PSW;
	} else {
	cppVar_16340 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16341 = (cppVar_16340 << 3) | 0;
	cppVar_16341 = (cppVar_16341 & cppMask_un_5_);
	cppVar_16342 = (0 << 5) | cppVar_16341;
	cppVar_16342 = (cppVar_16342 & cppMask_un_8_);
	cppVar_16344 = (cppVar_16342 == 224);
	if (cppVar_16344) {
	cppVar_16339 = ACC;
	} else {
	cppVar_16346 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16347 = (cppVar_16346 << 3) | 0;
	cppVar_16347 = (cppVar_16347 & cppMask_un_5_);
	cppVar_16348 = (0 << 5) | cppVar_16347;
	cppVar_16348 = (cppVar_16348 & cppMask_un_8_);
	cppVar_16350 = (cppVar_16348 == 240);
	if (cppVar_16350) {
	cppVar_16345 = B;
	} else {
	cppVar_16345 = 0;
	}
	cppVar_16339 = cppVar_16345;
	}
	cppVar_16333 = cppVar_16339;
	}
	cppVar_16327 = cppVar_16333;
	}
	cppVar_16321 = cppVar_16327;
	}
	cppVar_16315 = cppVar_16321;
	}
	cppVar_16309 = cppVar_16315;
	}
	cppVar_16303 = cppVar_16309;
	}
	cppVar_16297 = cppVar_16303;
	}
	cppVar_16291 = cppVar_16297;
	}
	cppVar_16285 = cppVar_16291;
	}
	cppVar_16279 = cppVar_16285;
	}
	cppVar_16273 = cppVar_16279;
	}
	cppVar_16267 = cppVar_16273;
	}
	cppVar_16261 = cppVar_16267;
	}
	cppVar_16255 = cppVar_16261;
	}
	cppVar_16249 = cppVar_16255;
	}
	cppVar_16243 = cppVar_16249;
	}
	cppVar_16237 = cppVar_16243;
	}
	cppVar_16231 = cppVar_16237;
	}
	cppVar_16225 = cppVar_16231;
	}
	cppVar_16212 = cppVar_16225;
	}
	cppVar_16206 = cppVar_16212;
	} else {
	cppVar_16206 = IE;
	}
	cppVar_16202 = cppVar_16206;
	} else {
	cppVar_16353 = ROM.rd(PC);
	cppVar_16355 = (cppVar_16353 == 135);
	if (cppVar_16355) {
	cppVar_16358 = PC + 1;
	cppVar_16358 = (cppVar_16358 & cppMask_un_16_);
	cppVar_16359 = ROM.rd(cppVar_16358);
	cppVar_16361 = (cppVar_16359 == 168);
	if (cppVar_16361) {
	cppVar_16363 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16365 = (cppVar_16363 << 3) | 1;
	cppVar_16365 = (cppVar_16365 & cppMask_un_5_);
	cppVar_16366 = (0 << 5) | cppVar_16365;
	cppVar_16366 = (cppVar_16366 & cppMask_un_8_);
	cppVar_16367 = IRAM.rd(cppVar_16366);
	cppVar_16368 = IRAM.rd(cppVar_16367);
	cppVar_16356 = cppVar_16368;
	} else {
	cppVar_16356 = IE;
	}
	cppVar_16352 = cppVar_16356;
	} else {
	cppVar_16370 = ROM.rd(PC);
	cppVar_16372 = (cppVar_16370 == 134);
	if (cppVar_16372) {
	cppVar_16375 = PC + 1;
	cppVar_16375 = (cppVar_16375 & cppMask_un_16_);
	cppVar_16376 = ROM.rd(cppVar_16375);
	cppVar_16378 = (cppVar_16376 == 168);
	if (cppVar_16378) {
	cppVar_16380 = (PSW >> 3) & cppMask_un_2_;
	cppVar_16382 = (cppVar_16380 << 3) | 0;
	cppVar_16382 = (cppVar_16382 & cppMask_un_5_);
	cppVar_16383 = (0 << 5) | cppVar_16382;
	cppVar_16383 = (cppVar_16383 & cppMask_un_8_);
	cppVar_16384 = IRAM.rd(cppVar_16383);
	cppVar_16385 = IRAM.rd(cppVar_16384);
	cppVar_16373 = cppVar_16385;
	} else {
	cppVar_16373 = IE;
	}
	cppVar_16369 = cppVar_16373;
	} else {
	cppVar_16387 = ROM.rd(PC);
	cppVar_16389 = (cppVar_16387 == 133);
	if (cppVar_16389) {
	cppVar_16392 = PC + 2;
	cppVar_16392 = (cppVar_16392 & cppMask_un_16_);
	cppVar_16393 = ROM.rd(cppVar_16392);
	cppVar_16395 = (cppVar_16393 == 168);
	if (cppVar_16395) {
	cppVar_16398 = PC + 1;
	cppVar_16398 = (cppVar_16398 & cppMask_un_16_);
	cppVar_16399 = ROM.rd(cppVar_16398);
	cppVar_16400 = (cppVar_16399 >> 7) & cppMask_un_1_;
	cppVar_16402 = (cppVar_16400 == 0);
	if (cppVar_16402) {
	cppVar_16403 = PC + 1;
	cppVar_16403 = (cppVar_16403 & cppMask_un_16_);
	cppVar_16404 = ROM.rd(cppVar_16403);
	cppVar_16405 = IRAM.rd(cppVar_16404);
	cppVar_16396 = cppVar_16405;
	} else {
	cppVar_16407 = PC + 1;
	cppVar_16407 = (cppVar_16407 & cppMask_un_16_);
	cppVar_16408 = ROM.rd(cppVar_16407);
	cppVar_16410 = (cppVar_16408 == 128);
	if (cppVar_16410) {
	cppVar_16406 = P0;
	} else {
	cppVar_16412 = PC + 1;
	cppVar_16412 = (cppVar_16412 & cppMask_un_16_);
	cppVar_16413 = ROM.rd(cppVar_16412);
	cppVar_16415 = (cppVar_16413 == 129);
	if (cppVar_16415) {
	cppVar_16411 = SP;
	} else {
	cppVar_16417 = PC + 1;
	cppVar_16417 = (cppVar_16417 & cppMask_un_16_);
	cppVar_16418 = ROM.rd(cppVar_16417);
	cppVar_16420 = (cppVar_16418 == 130);
	if (cppVar_16420) {
	cppVar_16416 = DPL;
	} else {
	cppVar_16422 = PC + 1;
	cppVar_16422 = (cppVar_16422 & cppMask_un_16_);
	cppVar_16423 = ROM.rd(cppVar_16422);
	cppVar_16425 = (cppVar_16423 == 131);
	if (cppVar_16425) {
	cppVar_16421 = DPH;
	} else {
	cppVar_16427 = PC + 1;
	cppVar_16427 = (cppVar_16427 & cppMask_un_16_);
	cppVar_16428 = ROM.rd(cppVar_16427);
	cppVar_16430 = (cppVar_16428 == 135);
	if (cppVar_16430) {
	cppVar_16426 = PCON;
	} else {
	cppVar_16432 = PC + 1;
	cppVar_16432 = (cppVar_16432 & cppMask_un_16_);
	cppVar_16433 = ROM.rd(cppVar_16432);
	cppVar_16435 = (cppVar_16433 == 136);
	if (cppVar_16435) {
	cppVar_16431 = TCON;
	} else {
	cppVar_16437 = PC + 1;
	cppVar_16437 = (cppVar_16437 & cppMask_un_16_);
	cppVar_16438 = ROM.rd(cppVar_16437);
	cppVar_16440 = (cppVar_16438 == 137);
	if (cppVar_16440) {
	cppVar_16436 = TMOD;
	} else {
	cppVar_16442 = PC + 1;
	cppVar_16442 = (cppVar_16442 & cppMask_un_16_);
	cppVar_16443 = ROM.rd(cppVar_16442);
	cppVar_16445 = (cppVar_16443 == 138);
	if (cppVar_16445) {
	cppVar_16441 = TL0;
	} else {
	cppVar_16447 = PC + 1;
	cppVar_16447 = (cppVar_16447 & cppMask_un_16_);
	cppVar_16448 = ROM.rd(cppVar_16447);
	cppVar_16450 = (cppVar_16448 == 140);
	if (cppVar_16450) {
	cppVar_16446 = TH0;
	} else {
	cppVar_16452 = PC + 1;
	cppVar_16452 = (cppVar_16452 & cppMask_un_16_);
	cppVar_16453 = ROM.rd(cppVar_16452);
	cppVar_16455 = (cppVar_16453 == 139);
	if (cppVar_16455) {
	cppVar_16451 = TL1;
	} else {
	cppVar_16457 = PC + 1;
	cppVar_16457 = (cppVar_16457 & cppMask_un_16_);
	cppVar_16458 = ROM.rd(cppVar_16457);
	cppVar_16460 = (cppVar_16458 == 141);
	if (cppVar_16460) {
	cppVar_16456 = TH1;
	} else {
	cppVar_16462 = PC + 1;
	cppVar_16462 = (cppVar_16462 & cppMask_un_16_);
	cppVar_16463 = ROM.rd(cppVar_16462);
	cppVar_16465 = (cppVar_16463 == 144);
	if (cppVar_16465) {
	cppVar_16461 = P1;
	} else {
	cppVar_16467 = PC + 1;
	cppVar_16467 = (cppVar_16467 & cppMask_un_16_);
	cppVar_16468 = ROM.rd(cppVar_16467);
	cppVar_16470 = (cppVar_16468 == 152);
	if (cppVar_16470) {
	cppVar_16466 = SCON;
	} else {
	cppVar_16472 = PC + 1;
	cppVar_16472 = (cppVar_16472 & cppMask_un_16_);
	cppVar_16473 = ROM.rd(cppVar_16472);
	cppVar_16475 = (cppVar_16473 == 153);
	if (cppVar_16475) {
	cppVar_16471 = SBUF;
	} else {
	cppVar_16477 = PC + 1;
	cppVar_16477 = (cppVar_16477 & cppMask_un_16_);
	cppVar_16478 = ROM.rd(cppVar_16477);
	cppVar_16480 = (cppVar_16478 == 160);
	if (cppVar_16480) {
	cppVar_16476 = P2;
	} else {
	cppVar_16482 = PC + 1;
	cppVar_16482 = (cppVar_16482 & cppMask_un_16_);
	cppVar_16483 = ROM.rd(cppVar_16482);
	cppVar_16485 = (cppVar_16483 == 168);
	if (cppVar_16485) {
	cppVar_16481 = IE;
	} else {
	cppVar_16487 = PC + 1;
	cppVar_16487 = (cppVar_16487 & cppMask_un_16_);
	cppVar_16488 = ROM.rd(cppVar_16487);
	cppVar_16490 = (cppVar_16488 == 176);
	if (cppVar_16490) {
	cppVar_16486 = P3;
	} else {
	cppVar_16492 = PC + 1;
	cppVar_16492 = (cppVar_16492 & cppMask_un_16_);
	cppVar_16493 = ROM.rd(cppVar_16492);
	cppVar_16495 = (cppVar_16493 == 184);
	if (cppVar_16495) {
	cppVar_16491 = IP;
	} else {
	cppVar_16497 = PC + 1;
	cppVar_16497 = (cppVar_16497 & cppMask_un_16_);
	cppVar_16498 = ROM.rd(cppVar_16497);
	cppVar_16500 = (cppVar_16498 == 208);
	if (cppVar_16500) {
	cppVar_16496 = PSW;
	} else {
	cppVar_16502 = PC + 1;
	cppVar_16502 = (cppVar_16502 & cppMask_un_16_);
	cppVar_16503 = ROM.rd(cppVar_16502);
	cppVar_16505 = (cppVar_16503 == 224);
	if (cppVar_16505) {
	cppVar_16501 = ACC;
	} else {
	cppVar_16507 = PC + 1;
	cppVar_16507 = (cppVar_16507 & cppMask_un_16_);
	cppVar_16508 = ROM.rd(cppVar_16507);
	cppVar_16510 = (cppVar_16508 == 240);
	if (cppVar_16510) {
	cppVar_16506 = B;
	} else {
	cppVar_16506 = 0;
	}
	cppVar_16501 = cppVar_16506;
	}
	cppVar_16496 = cppVar_16501;
	}
	cppVar_16491 = cppVar_16496;
	}
	cppVar_16486 = cppVar_16491;
	}
	cppVar_16481 = cppVar_16486;
	}
	cppVar_16476 = cppVar_16481;
	}
	cppVar_16471 = cppVar_16476;
	}
	cppVar_16466 = cppVar_16471;
	}
	cppVar_16461 = cppVar_16466;
	}
	cppVar_16456 = cppVar_16461;
	}
	cppVar_16451 = cppVar_16456;
	}
	cppVar_16446 = cppVar_16451;
	}
	cppVar_16441 = cppVar_16446;
	}
	cppVar_16436 = cppVar_16441;
	}
	cppVar_16431 = cppVar_16436;
	}
	cppVar_16426 = cppVar_16431;
	}
	cppVar_16421 = cppVar_16426;
	}
	cppVar_16416 = cppVar_16421;
	}
	cppVar_16411 = cppVar_16416;
	}
	cppVar_16406 = cppVar_16411;
	}
	cppVar_16396 = cppVar_16406;
	}
	cppVar_16390 = cppVar_16396;
	} else {
	cppVar_16390 = IE;
	}
	cppVar_16386 = cppVar_16390;
	} else {
	cppVar_16513 = ROM.rd(PC);
	cppVar_16515 = (cppVar_16513 == 117);
	if (cppVar_16515) {
	cppVar_16518 = PC + 1;
	cppVar_16518 = (cppVar_16518 & cppMask_un_16_);
	cppVar_16519 = ROM.rd(cppVar_16518);
	cppVar_16521 = (cppVar_16519 == 168);
	if (cppVar_16521) {
	cppVar_16523 = PC + 2;
	cppVar_16523 = (cppVar_16523 & cppMask_un_16_);
	cppVar_16524 = ROM.rd(cppVar_16523);
	cppVar_16516 = cppVar_16524;
	} else {
	cppVar_16516 = IE;
	}
	cppVar_16512 = cppVar_16516;
	} else {
	cppVar_16526 = ROM.rd(PC);
	cppVar_16528 = (cppVar_16526 == 99);
	if (cppVar_16528) {
	cppVar_16531 = PC + 1;
	cppVar_16531 = (cppVar_16531 & cppMask_un_16_);
	cppVar_16532 = ROM.rd(cppVar_16531);
	cppVar_16534 = (cppVar_16532 == 168);
	if (cppVar_16534) {
	cppVar_16536 = PC + 1;
	cppVar_16536 = (cppVar_16536 & cppMask_un_16_);
	cppVar_16537 = ROM.rd(cppVar_16536);
	cppVar_16538 = (cppVar_16537 >> 7) & cppMask_un_1_;
	cppVar_16540 = (cppVar_16538 == 0);
	if (cppVar_16540) {
	cppVar_16541 = PC + 1;
	cppVar_16541 = (cppVar_16541 & cppMask_un_16_);
	cppVar_16542 = ROM.rd(cppVar_16541);
	cppVar_16543 = IRAM.rd(cppVar_16542);
	cppVar_16535 = cppVar_16543;
	} else {
	cppVar_16545 = PC + 1;
	cppVar_16545 = (cppVar_16545 & cppMask_un_16_);
	cppVar_16546 = ROM.rd(cppVar_16545);
	cppVar_16548 = (cppVar_16546 == 128);
	if (cppVar_16548) {
	cppVar_16544 = P0;
	} else {
	cppVar_16550 = PC + 1;
	cppVar_16550 = (cppVar_16550 & cppMask_un_16_);
	cppVar_16551 = ROM.rd(cppVar_16550);
	cppVar_16553 = (cppVar_16551 == 129);
	if (cppVar_16553) {
	cppVar_16549 = SP;
	} else {
	cppVar_16555 = PC + 1;
	cppVar_16555 = (cppVar_16555 & cppMask_un_16_);
	cppVar_16556 = ROM.rd(cppVar_16555);
	cppVar_16558 = (cppVar_16556 == 130);
	if (cppVar_16558) {
	cppVar_16554 = DPL;
	} else {
	cppVar_16560 = PC + 1;
	cppVar_16560 = (cppVar_16560 & cppMask_un_16_);
	cppVar_16561 = ROM.rd(cppVar_16560);
	cppVar_16563 = (cppVar_16561 == 131);
	if (cppVar_16563) {
	cppVar_16559 = DPH;
	} else {
	cppVar_16565 = PC + 1;
	cppVar_16565 = (cppVar_16565 & cppMask_un_16_);
	cppVar_16566 = ROM.rd(cppVar_16565);
	cppVar_16568 = (cppVar_16566 == 135);
	if (cppVar_16568) {
	cppVar_16564 = PCON;
	} else {
	cppVar_16570 = PC + 1;
	cppVar_16570 = (cppVar_16570 & cppMask_un_16_);
	cppVar_16571 = ROM.rd(cppVar_16570);
	cppVar_16573 = (cppVar_16571 == 136);
	if (cppVar_16573) {
	cppVar_16569 = TCON;
	} else {
	cppVar_16575 = PC + 1;
	cppVar_16575 = (cppVar_16575 & cppMask_un_16_);
	cppVar_16576 = ROM.rd(cppVar_16575);
	cppVar_16578 = (cppVar_16576 == 137);
	if (cppVar_16578) {
	cppVar_16574 = TMOD;
	} else {
	cppVar_16580 = PC + 1;
	cppVar_16580 = (cppVar_16580 & cppMask_un_16_);
	cppVar_16581 = ROM.rd(cppVar_16580);
	cppVar_16583 = (cppVar_16581 == 138);
	if (cppVar_16583) {
	cppVar_16579 = TL0;
	} else {
	cppVar_16585 = PC + 1;
	cppVar_16585 = (cppVar_16585 & cppMask_un_16_);
	cppVar_16586 = ROM.rd(cppVar_16585);
	cppVar_16588 = (cppVar_16586 == 140);
	if (cppVar_16588) {
	cppVar_16584 = TH0;
	} else {
	cppVar_16590 = PC + 1;
	cppVar_16590 = (cppVar_16590 & cppMask_un_16_);
	cppVar_16591 = ROM.rd(cppVar_16590);
	cppVar_16593 = (cppVar_16591 == 139);
	if (cppVar_16593) {
	cppVar_16589 = TL1;
	} else {
	cppVar_16595 = PC + 1;
	cppVar_16595 = (cppVar_16595 & cppMask_un_16_);
	cppVar_16596 = ROM.rd(cppVar_16595);
	cppVar_16598 = (cppVar_16596 == 141);
	if (cppVar_16598) {
	cppVar_16594 = TH1;
	} else {
	cppVar_16600 = PC + 1;
	cppVar_16600 = (cppVar_16600 & cppMask_un_16_);
	cppVar_16601 = ROM.rd(cppVar_16600);
	cppVar_16603 = (cppVar_16601 == 144);
	if (cppVar_16603) {
	cppVar_16599 = P1;
	} else {
	cppVar_16605 = PC + 1;
	cppVar_16605 = (cppVar_16605 & cppMask_un_16_);
	cppVar_16606 = ROM.rd(cppVar_16605);
	cppVar_16608 = (cppVar_16606 == 152);
	if (cppVar_16608) {
	cppVar_16604 = SCON;
	} else {
	cppVar_16610 = PC + 1;
	cppVar_16610 = (cppVar_16610 & cppMask_un_16_);
	cppVar_16611 = ROM.rd(cppVar_16610);
	cppVar_16613 = (cppVar_16611 == 153);
	if (cppVar_16613) {
	cppVar_16609 = SBUF;
	} else {
	cppVar_16615 = PC + 1;
	cppVar_16615 = (cppVar_16615 & cppMask_un_16_);
	cppVar_16616 = ROM.rd(cppVar_16615);
	cppVar_16618 = (cppVar_16616 == 160);
	if (cppVar_16618) {
	cppVar_16614 = P2;
	} else {
	cppVar_16620 = PC + 1;
	cppVar_16620 = (cppVar_16620 & cppMask_un_16_);
	cppVar_16621 = ROM.rd(cppVar_16620);
	cppVar_16623 = (cppVar_16621 == 168);
	if (cppVar_16623) {
	cppVar_16619 = IE;
	} else {
	cppVar_16625 = PC + 1;
	cppVar_16625 = (cppVar_16625 & cppMask_un_16_);
	cppVar_16626 = ROM.rd(cppVar_16625);
	cppVar_16628 = (cppVar_16626 == 176);
	if (cppVar_16628) {
	cppVar_16624 = P3;
	} else {
	cppVar_16630 = PC + 1;
	cppVar_16630 = (cppVar_16630 & cppMask_un_16_);
	cppVar_16631 = ROM.rd(cppVar_16630);
	cppVar_16633 = (cppVar_16631 == 184);
	if (cppVar_16633) {
	cppVar_16629 = IP;
	} else {
	cppVar_16635 = PC + 1;
	cppVar_16635 = (cppVar_16635 & cppMask_un_16_);
	cppVar_16636 = ROM.rd(cppVar_16635);
	cppVar_16638 = (cppVar_16636 == 208);
	if (cppVar_16638) {
	cppVar_16634 = PSW;
	} else {
	cppVar_16640 = PC + 1;
	cppVar_16640 = (cppVar_16640 & cppMask_un_16_);
	cppVar_16641 = ROM.rd(cppVar_16640);
	cppVar_16643 = (cppVar_16641 == 224);
	if (cppVar_16643) {
	cppVar_16639 = ACC;
	} else {
	cppVar_16645 = PC + 1;
	cppVar_16645 = (cppVar_16645 & cppMask_un_16_);
	cppVar_16646 = ROM.rd(cppVar_16645);
	cppVar_16648 = (cppVar_16646 == 240);
	if (cppVar_16648) {
	cppVar_16644 = B;
	} else {
	cppVar_16644 = 0;
	}
	cppVar_16639 = cppVar_16644;
	}
	cppVar_16634 = cppVar_16639;
	}
	cppVar_16629 = cppVar_16634;
	}
	cppVar_16624 = cppVar_16629;
	}
	cppVar_16619 = cppVar_16624;
	}
	cppVar_16614 = cppVar_16619;
	}
	cppVar_16609 = cppVar_16614;
	}
	cppVar_16604 = cppVar_16609;
	}
	cppVar_16599 = cppVar_16604;
	}
	cppVar_16594 = cppVar_16599;
	}
	cppVar_16589 = cppVar_16594;
	}
	cppVar_16584 = cppVar_16589;
	}
	cppVar_16579 = cppVar_16584;
	}
	cppVar_16574 = cppVar_16579;
	}
	cppVar_16569 = cppVar_16574;
	}
	cppVar_16564 = cppVar_16569;
	}
	cppVar_16559 = cppVar_16564;
	}
	cppVar_16554 = cppVar_16559;
	}
	cppVar_16549 = cppVar_16554;
	}
	cppVar_16544 = cppVar_16549;
	}
	cppVar_16535 = cppVar_16544;
	}
	cppVar_16651 = PC + 2;
	cppVar_16651 = (cppVar_16651 & cppMask_un_16_);
	cppVar_16652 = ROM.rd(cppVar_16651);
	cppVar_16653 = cppVar_16535 ^ cppVar_16652;
	cppVar_16529 = cppVar_16653;
	} else {
	cppVar_16529 = IE;
	}
	cppVar_16525 = cppVar_16529;
	} else {
	cppVar_16655 = ROM.rd(PC);
	cppVar_16657 = (cppVar_16655 == 98);
	if (cppVar_16657) {
	cppVar_16660 = PC + 1;
	cppVar_16660 = (cppVar_16660 & cppMask_un_16_);
	cppVar_16661 = ROM.rd(cppVar_16660);
	cppVar_16663 = (cppVar_16661 == 168);
	if (cppVar_16663) {
	cppVar_16665 = PC + 1;
	cppVar_16665 = (cppVar_16665 & cppMask_un_16_);
	cppVar_16666 = ROM.rd(cppVar_16665);
	cppVar_16667 = (cppVar_16666 >> 7) & cppMask_un_1_;
	cppVar_16669 = (cppVar_16667 == 0);
	if (cppVar_16669) {
	cppVar_16670 = PC + 1;
	cppVar_16670 = (cppVar_16670 & cppMask_un_16_);
	cppVar_16671 = ROM.rd(cppVar_16670);
	cppVar_16672 = IRAM.rd(cppVar_16671);
	cppVar_16664 = cppVar_16672;
	} else {
	cppVar_16674 = PC + 1;
	cppVar_16674 = (cppVar_16674 & cppMask_un_16_);
	cppVar_16675 = ROM.rd(cppVar_16674);
	cppVar_16677 = (cppVar_16675 == 128);
	if (cppVar_16677) {
	cppVar_16673 = P0;
	} else {
	cppVar_16679 = PC + 1;
	cppVar_16679 = (cppVar_16679 & cppMask_un_16_);
	cppVar_16680 = ROM.rd(cppVar_16679);
	cppVar_16682 = (cppVar_16680 == 129);
	if (cppVar_16682) {
	cppVar_16678 = SP;
	} else {
	cppVar_16684 = PC + 1;
	cppVar_16684 = (cppVar_16684 & cppMask_un_16_);
	cppVar_16685 = ROM.rd(cppVar_16684);
	cppVar_16687 = (cppVar_16685 == 130);
	if (cppVar_16687) {
	cppVar_16683 = DPL;
	} else {
	cppVar_16689 = PC + 1;
	cppVar_16689 = (cppVar_16689 & cppMask_un_16_);
	cppVar_16690 = ROM.rd(cppVar_16689);
	cppVar_16692 = (cppVar_16690 == 131);
	if (cppVar_16692) {
	cppVar_16688 = DPH;
	} else {
	cppVar_16694 = PC + 1;
	cppVar_16694 = (cppVar_16694 & cppMask_un_16_);
	cppVar_16695 = ROM.rd(cppVar_16694);
	cppVar_16697 = (cppVar_16695 == 135);
	if (cppVar_16697) {
	cppVar_16693 = PCON;
	} else {
	cppVar_16699 = PC + 1;
	cppVar_16699 = (cppVar_16699 & cppMask_un_16_);
	cppVar_16700 = ROM.rd(cppVar_16699);
	cppVar_16702 = (cppVar_16700 == 136);
	if (cppVar_16702) {
	cppVar_16698 = TCON;
	} else {
	cppVar_16704 = PC + 1;
	cppVar_16704 = (cppVar_16704 & cppMask_un_16_);
	cppVar_16705 = ROM.rd(cppVar_16704);
	cppVar_16707 = (cppVar_16705 == 137);
	if (cppVar_16707) {
	cppVar_16703 = TMOD;
	} else {
	cppVar_16709 = PC + 1;
	cppVar_16709 = (cppVar_16709 & cppMask_un_16_);
	cppVar_16710 = ROM.rd(cppVar_16709);
	cppVar_16712 = (cppVar_16710 == 138);
	if (cppVar_16712) {
	cppVar_16708 = TL0;
	} else {
	cppVar_16714 = PC + 1;
	cppVar_16714 = (cppVar_16714 & cppMask_un_16_);
	cppVar_16715 = ROM.rd(cppVar_16714);
	cppVar_16717 = (cppVar_16715 == 140);
	if (cppVar_16717) {
	cppVar_16713 = TH0;
	} else {
	cppVar_16719 = PC + 1;
	cppVar_16719 = (cppVar_16719 & cppMask_un_16_);
	cppVar_16720 = ROM.rd(cppVar_16719);
	cppVar_16722 = (cppVar_16720 == 139);
	if (cppVar_16722) {
	cppVar_16718 = TL1;
	} else {
	cppVar_16724 = PC + 1;
	cppVar_16724 = (cppVar_16724 & cppMask_un_16_);
	cppVar_16725 = ROM.rd(cppVar_16724);
	cppVar_16727 = (cppVar_16725 == 141);
	if (cppVar_16727) {
	cppVar_16723 = TH1;
	} else {
	cppVar_16729 = PC + 1;
	cppVar_16729 = (cppVar_16729 & cppMask_un_16_);
	cppVar_16730 = ROM.rd(cppVar_16729);
	cppVar_16732 = (cppVar_16730 == 144);
	if (cppVar_16732) {
	cppVar_16728 = P1;
	} else {
	cppVar_16734 = PC + 1;
	cppVar_16734 = (cppVar_16734 & cppMask_un_16_);
	cppVar_16735 = ROM.rd(cppVar_16734);
	cppVar_16737 = (cppVar_16735 == 152);
	if (cppVar_16737) {
	cppVar_16733 = SCON;
	} else {
	cppVar_16739 = PC + 1;
	cppVar_16739 = (cppVar_16739 & cppMask_un_16_);
	cppVar_16740 = ROM.rd(cppVar_16739);
	cppVar_16742 = (cppVar_16740 == 153);
	if (cppVar_16742) {
	cppVar_16738 = SBUF;
	} else {
	cppVar_16744 = PC + 1;
	cppVar_16744 = (cppVar_16744 & cppMask_un_16_);
	cppVar_16745 = ROM.rd(cppVar_16744);
	cppVar_16747 = (cppVar_16745 == 160);
	if (cppVar_16747) {
	cppVar_16743 = P2;
	} else {
	cppVar_16749 = PC + 1;
	cppVar_16749 = (cppVar_16749 & cppMask_un_16_);
	cppVar_16750 = ROM.rd(cppVar_16749);
	cppVar_16752 = (cppVar_16750 == 168);
	if (cppVar_16752) {
	cppVar_16748 = IE;
	} else {
	cppVar_16754 = PC + 1;
	cppVar_16754 = (cppVar_16754 & cppMask_un_16_);
	cppVar_16755 = ROM.rd(cppVar_16754);
	cppVar_16757 = (cppVar_16755 == 176);
	if (cppVar_16757) {
	cppVar_16753 = P3;
	} else {
	cppVar_16759 = PC + 1;
	cppVar_16759 = (cppVar_16759 & cppMask_un_16_);
	cppVar_16760 = ROM.rd(cppVar_16759);
	cppVar_16762 = (cppVar_16760 == 184);
	if (cppVar_16762) {
	cppVar_16758 = IP;
	} else {
	cppVar_16764 = PC + 1;
	cppVar_16764 = (cppVar_16764 & cppMask_un_16_);
	cppVar_16765 = ROM.rd(cppVar_16764);
	cppVar_16767 = (cppVar_16765 == 208);
	if (cppVar_16767) {
	cppVar_16763 = PSW;
	} else {
	cppVar_16769 = PC + 1;
	cppVar_16769 = (cppVar_16769 & cppMask_un_16_);
	cppVar_16770 = ROM.rd(cppVar_16769);
	cppVar_16772 = (cppVar_16770 == 224);
	if (cppVar_16772) {
	cppVar_16768 = ACC;
	} else {
	cppVar_16774 = PC + 1;
	cppVar_16774 = (cppVar_16774 & cppMask_un_16_);
	cppVar_16775 = ROM.rd(cppVar_16774);
	cppVar_16777 = (cppVar_16775 == 240);
	if (cppVar_16777) {
	cppVar_16773 = B;
	} else {
	cppVar_16773 = 0;
	}
	cppVar_16768 = cppVar_16773;
	}
	cppVar_16763 = cppVar_16768;
	}
	cppVar_16758 = cppVar_16763;
	}
	cppVar_16753 = cppVar_16758;
	}
	cppVar_16748 = cppVar_16753;
	}
	cppVar_16743 = cppVar_16748;
	}
	cppVar_16738 = cppVar_16743;
	}
	cppVar_16733 = cppVar_16738;
	}
	cppVar_16728 = cppVar_16733;
	}
	cppVar_16723 = cppVar_16728;
	}
	cppVar_16718 = cppVar_16723;
	}
	cppVar_16713 = cppVar_16718;
	}
	cppVar_16708 = cppVar_16713;
	}
	cppVar_16703 = cppVar_16708;
	}
	cppVar_16698 = cppVar_16703;
	}
	cppVar_16693 = cppVar_16698;
	}
	cppVar_16688 = cppVar_16693;
	}
	cppVar_16683 = cppVar_16688;
	}
	cppVar_16678 = cppVar_16683;
	}
	cppVar_16673 = cppVar_16678;
	}
	cppVar_16664 = cppVar_16673;
	}
	cppVar_16779 = cppVar_16664 ^ ACC;
	cppVar_16658 = cppVar_16779;
	} else {
	cppVar_16658 = IE;
	}
	cppVar_16654 = cppVar_16658;
	} else {
	cppVar_16781 = ROM.rd(PC);
	cppVar_16783 = (cppVar_16781 == 83);
	if (cppVar_16783) {
	cppVar_16786 = PC + 1;
	cppVar_16786 = (cppVar_16786 & cppMask_un_16_);
	cppVar_16787 = ROM.rd(cppVar_16786);
	cppVar_16789 = (cppVar_16787 == 168);
	if (cppVar_16789) {
	cppVar_16791 = PC + 1;
	cppVar_16791 = (cppVar_16791 & cppMask_un_16_);
	cppVar_16792 = ROM.rd(cppVar_16791);
	cppVar_16793 = (cppVar_16792 >> 7) & cppMask_un_1_;
	cppVar_16795 = (cppVar_16793 == 0);
	if (cppVar_16795) {
	cppVar_16796 = PC + 1;
	cppVar_16796 = (cppVar_16796 & cppMask_un_16_);
	cppVar_16797 = ROM.rd(cppVar_16796);
	cppVar_16798 = IRAM.rd(cppVar_16797);
	cppVar_16790 = cppVar_16798;
	} else {
	cppVar_16800 = PC + 1;
	cppVar_16800 = (cppVar_16800 & cppMask_un_16_);
	cppVar_16801 = ROM.rd(cppVar_16800);
	cppVar_16803 = (cppVar_16801 == 128);
	if (cppVar_16803) {
	cppVar_16799 = P0;
	} else {
	cppVar_16805 = PC + 1;
	cppVar_16805 = (cppVar_16805 & cppMask_un_16_);
	cppVar_16806 = ROM.rd(cppVar_16805);
	cppVar_16808 = (cppVar_16806 == 129);
	if (cppVar_16808) {
	cppVar_16804 = SP;
	} else {
	cppVar_16810 = PC + 1;
	cppVar_16810 = (cppVar_16810 & cppMask_un_16_);
	cppVar_16811 = ROM.rd(cppVar_16810);
	cppVar_16813 = (cppVar_16811 == 130);
	if (cppVar_16813) {
	cppVar_16809 = DPL;
	} else {
	cppVar_16815 = PC + 1;
	cppVar_16815 = (cppVar_16815 & cppMask_un_16_);
	cppVar_16816 = ROM.rd(cppVar_16815);
	cppVar_16818 = (cppVar_16816 == 131);
	if (cppVar_16818) {
	cppVar_16814 = DPH;
	} else {
	cppVar_16820 = PC + 1;
	cppVar_16820 = (cppVar_16820 & cppMask_un_16_);
	cppVar_16821 = ROM.rd(cppVar_16820);
	cppVar_16823 = (cppVar_16821 == 135);
	if (cppVar_16823) {
	cppVar_16819 = PCON;
	} else {
	cppVar_16825 = PC + 1;
	cppVar_16825 = (cppVar_16825 & cppMask_un_16_);
	cppVar_16826 = ROM.rd(cppVar_16825);
	cppVar_16828 = (cppVar_16826 == 136);
	if (cppVar_16828) {
	cppVar_16824 = TCON;
	} else {
	cppVar_16830 = PC + 1;
	cppVar_16830 = (cppVar_16830 & cppMask_un_16_);
	cppVar_16831 = ROM.rd(cppVar_16830);
	cppVar_16833 = (cppVar_16831 == 137);
	if (cppVar_16833) {
	cppVar_16829 = TMOD;
	} else {
	cppVar_16835 = PC + 1;
	cppVar_16835 = (cppVar_16835 & cppMask_un_16_);
	cppVar_16836 = ROM.rd(cppVar_16835);
	cppVar_16838 = (cppVar_16836 == 138);
	if (cppVar_16838) {
	cppVar_16834 = TL0;
	} else {
	cppVar_16840 = PC + 1;
	cppVar_16840 = (cppVar_16840 & cppMask_un_16_);
	cppVar_16841 = ROM.rd(cppVar_16840);
	cppVar_16843 = (cppVar_16841 == 140);
	if (cppVar_16843) {
	cppVar_16839 = TH0;
	} else {
	cppVar_16845 = PC + 1;
	cppVar_16845 = (cppVar_16845 & cppMask_un_16_);
	cppVar_16846 = ROM.rd(cppVar_16845);
	cppVar_16848 = (cppVar_16846 == 139);
	if (cppVar_16848) {
	cppVar_16844 = TL1;
	} else {
	cppVar_16850 = PC + 1;
	cppVar_16850 = (cppVar_16850 & cppMask_un_16_);
	cppVar_16851 = ROM.rd(cppVar_16850);
	cppVar_16853 = (cppVar_16851 == 141);
	if (cppVar_16853) {
	cppVar_16849 = TH1;
	} else {
	cppVar_16855 = PC + 1;
	cppVar_16855 = (cppVar_16855 & cppMask_un_16_);
	cppVar_16856 = ROM.rd(cppVar_16855);
	cppVar_16858 = (cppVar_16856 == 144);
	if (cppVar_16858) {
	cppVar_16854 = P1;
	} else {
	cppVar_16860 = PC + 1;
	cppVar_16860 = (cppVar_16860 & cppMask_un_16_);
	cppVar_16861 = ROM.rd(cppVar_16860);
	cppVar_16863 = (cppVar_16861 == 152);
	if (cppVar_16863) {
	cppVar_16859 = SCON;
	} else {
	cppVar_16865 = PC + 1;
	cppVar_16865 = (cppVar_16865 & cppMask_un_16_);
	cppVar_16866 = ROM.rd(cppVar_16865);
	cppVar_16868 = (cppVar_16866 == 153);
	if (cppVar_16868) {
	cppVar_16864 = SBUF;
	} else {
	cppVar_16870 = PC + 1;
	cppVar_16870 = (cppVar_16870 & cppMask_un_16_);
	cppVar_16871 = ROM.rd(cppVar_16870);
	cppVar_16873 = (cppVar_16871 == 160);
	if (cppVar_16873) {
	cppVar_16869 = P2;
	} else {
	cppVar_16875 = PC + 1;
	cppVar_16875 = (cppVar_16875 & cppMask_un_16_);
	cppVar_16876 = ROM.rd(cppVar_16875);
	cppVar_16878 = (cppVar_16876 == 168);
	if (cppVar_16878) {
	cppVar_16874 = IE;
	} else {
	cppVar_16880 = PC + 1;
	cppVar_16880 = (cppVar_16880 & cppMask_un_16_);
	cppVar_16881 = ROM.rd(cppVar_16880);
	cppVar_16883 = (cppVar_16881 == 176);
	if (cppVar_16883) {
	cppVar_16879 = P3;
	} else {
	cppVar_16885 = PC + 1;
	cppVar_16885 = (cppVar_16885 & cppMask_un_16_);
	cppVar_16886 = ROM.rd(cppVar_16885);
	cppVar_16888 = (cppVar_16886 == 184);
	if (cppVar_16888) {
	cppVar_16884 = IP;
	} else {
	cppVar_16890 = PC + 1;
	cppVar_16890 = (cppVar_16890 & cppMask_un_16_);
	cppVar_16891 = ROM.rd(cppVar_16890);
	cppVar_16893 = (cppVar_16891 == 208);
	if (cppVar_16893) {
	cppVar_16889 = PSW;
	} else {
	cppVar_16895 = PC + 1;
	cppVar_16895 = (cppVar_16895 & cppMask_un_16_);
	cppVar_16896 = ROM.rd(cppVar_16895);
	cppVar_16898 = (cppVar_16896 == 224);
	if (cppVar_16898) {
	cppVar_16894 = ACC;
	} else {
	cppVar_16900 = PC + 1;
	cppVar_16900 = (cppVar_16900 & cppMask_un_16_);
	cppVar_16901 = ROM.rd(cppVar_16900);
	cppVar_16903 = (cppVar_16901 == 240);
	if (cppVar_16903) {
	cppVar_16899 = B;
	} else {
	cppVar_16899 = 0;
	}
	cppVar_16894 = cppVar_16899;
	}
	cppVar_16889 = cppVar_16894;
	}
	cppVar_16884 = cppVar_16889;
	}
	cppVar_16879 = cppVar_16884;
	}
	cppVar_16874 = cppVar_16879;
	}
	cppVar_16869 = cppVar_16874;
	}
	cppVar_16864 = cppVar_16869;
	}
	cppVar_16859 = cppVar_16864;
	}
	cppVar_16854 = cppVar_16859;
	}
	cppVar_16849 = cppVar_16854;
	}
	cppVar_16844 = cppVar_16849;
	}
	cppVar_16839 = cppVar_16844;
	}
	cppVar_16834 = cppVar_16839;
	}
	cppVar_16829 = cppVar_16834;
	}
	cppVar_16824 = cppVar_16829;
	}
	cppVar_16819 = cppVar_16824;
	}
	cppVar_16814 = cppVar_16819;
	}
	cppVar_16809 = cppVar_16814;
	}
	cppVar_16804 = cppVar_16809;
	}
	cppVar_16799 = cppVar_16804;
	}
	cppVar_16790 = cppVar_16799;
	}
	cppVar_16906 = PC + 2;
	cppVar_16906 = (cppVar_16906 & cppMask_un_16_);
	cppVar_16907 = ROM.rd(cppVar_16906);
	cppVar_16908 = cppVar_16790 & cppVar_16907;
	cppVar_16784 = cppVar_16908;
	} else {
	cppVar_16784 = IE;
	}
	cppVar_16780 = cppVar_16784;
	} else {
	cppVar_16910 = ROM.rd(PC);
	cppVar_16912 = (cppVar_16910 == 82);
	if (cppVar_16912) {
	cppVar_16915 = PC + 1;
	cppVar_16915 = (cppVar_16915 & cppMask_un_16_);
	cppVar_16916 = ROM.rd(cppVar_16915);
	cppVar_16918 = (cppVar_16916 == 168);
	if (cppVar_16918) {
	cppVar_16920 = PC + 1;
	cppVar_16920 = (cppVar_16920 & cppMask_un_16_);
	cppVar_16921 = ROM.rd(cppVar_16920);
	cppVar_16922 = (cppVar_16921 >> 7) & cppMask_un_1_;
	cppVar_16924 = (cppVar_16922 == 0);
	if (cppVar_16924) {
	cppVar_16925 = PC + 1;
	cppVar_16925 = (cppVar_16925 & cppMask_un_16_);
	cppVar_16926 = ROM.rd(cppVar_16925);
	cppVar_16927 = IRAM.rd(cppVar_16926);
	cppVar_16919 = cppVar_16927;
	} else {
	cppVar_16929 = PC + 1;
	cppVar_16929 = (cppVar_16929 & cppMask_un_16_);
	cppVar_16930 = ROM.rd(cppVar_16929);
	cppVar_16932 = (cppVar_16930 == 128);
	if (cppVar_16932) {
	cppVar_16928 = P0;
	} else {
	cppVar_16934 = PC + 1;
	cppVar_16934 = (cppVar_16934 & cppMask_un_16_);
	cppVar_16935 = ROM.rd(cppVar_16934);
	cppVar_16937 = (cppVar_16935 == 129);
	if (cppVar_16937) {
	cppVar_16933 = SP;
	} else {
	cppVar_16939 = PC + 1;
	cppVar_16939 = (cppVar_16939 & cppMask_un_16_);
	cppVar_16940 = ROM.rd(cppVar_16939);
	cppVar_16942 = (cppVar_16940 == 130);
	if (cppVar_16942) {
	cppVar_16938 = DPL;
	} else {
	cppVar_16944 = PC + 1;
	cppVar_16944 = (cppVar_16944 & cppMask_un_16_);
	cppVar_16945 = ROM.rd(cppVar_16944);
	cppVar_16947 = (cppVar_16945 == 131);
	if (cppVar_16947) {
	cppVar_16943 = DPH;
	} else {
	cppVar_16949 = PC + 1;
	cppVar_16949 = (cppVar_16949 & cppMask_un_16_);
	cppVar_16950 = ROM.rd(cppVar_16949);
	cppVar_16952 = (cppVar_16950 == 135);
	if (cppVar_16952) {
	cppVar_16948 = PCON;
	} else {
	cppVar_16954 = PC + 1;
	cppVar_16954 = (cppVar_16954 & cppMask_un_16_);
	cppVar_16955 = ROM.rd(cppVar_16954);
	cppVar_16957 = (cppVar_16955 == 136);
	if (cppVar_16957) {
	cppVar_16953 = TCON;
	} else {
	cppVar_16959 = PC + 1;
	cppVar_16959 = (cppVar_16959 & cppMask_un_16_);
	cppVar_16960 = ROM.rd(cppVar_16959);
	cppVar_16962 = (cppVar_16960 == 137);
	if (cppVar_16962) {
	cppVar_16958 = TMOD;
	} else {
	cppVar_16964 = PC + 1;
	cppVar_16964 = (cppVar_16964 & cppMask_un_16_);
	cppVar_16965 = ROM.rd(cppVar_16964);
	cppVar_16967 = (cppVar_16965 == 138);
	if (cppVar_16967) {
	cppVar_16963 = TL0;
	} else {
	cppVar_16969 = PC + 1;
	cppVar_16969 = (cppVar_16969 & cppMask_un_16_);
	cppVar_16970 = ROM.rd(cppVar_16969);
	cppVar_16972 = (cppVar_16970 == 140);
	if (cppVar_16972) {
	cppVar_16968 = TH0;
	} else {
	cppVar_16974 = PC + 1;
	cppVar_16974 = (cppVar_16974 & cppMask_un_16_);
	cppVar_16975 = ROM.rd(cppVar_16974);
	cppVar_16977 = (cppVar_16975 == 139);
	if (cppVar_16977) {
	cppVar_16973 = TL1;
	} else {
	cppVar_16979 = PC + 1;
	cppVar_16979 = (cppVar_16979 & cppMask_un_16_);
	cppVar_16980 = ROM.rd(cppVar_16979);
	cppVar_16982 = (cppVar_16980 == 141);
	if (cppVar_16982) {
	cppVar_16978 = TH1;
	} else {
	cppVar_16984 = PC + 1;
	cppVar_16984 = (cppVar_16984 & cppMask_un_16_);
	cppVar_16985 = ROM.rd(cppVar_16984);
	cppVar_16987 = (cppVar_16985 == 144);
	if (cppVar_16987) {
	cppVar_16983 = P1;
	} else {
	cppVar_16989 = PC + 1;
	cppVar_16989 = (cppVar_16989 & cppMask_un_16_);
	cppVar_16990 = ROM.rd(cppVar_16989);
	cppVar_16992 = (cppVar_16990 == 152);
	if (cppVar_16992) {
	cppVar_16988 = SCON;
	} else {
	cppVar_16994 = PC + 1;
	cppVar_16994 = (cppVar_16994 & cppMask_un_16_);
	cppVar_16995 = ROM.rd(cppVar_16994);
	cppVar_16997 = (cppVar_16995 == 153);
	if (cppVar_16997) {
	cppVar_16993 = SBUF;
	} else {
	cppVar_16999 = PC + 1;
	cppVar_16999 = (cppVar_16999 & cppMask_un_16_);
	cppVar_17000 = ROM.rd(cppVar_16999);
	cppVar_17002 = (cppVar_17000 == 160);
	if (cppVar_17002) {
	cppVar_16998 = P2;
	} else {
	cppVar_17004 = PC + 1;
	cppVar_17004 = (cppVar_17004 & cppMask_un_16_);
	cppVar_17005 = ROM.rd(cppVar_17004);
	cppVar_17007 = (cppVar_17005 == 168);
	if (cppVar_17007) {
	cppVar_17003 = IE;
	} else {
	cppVar_17009 = PC + 1;
	cppVar_17009 = (cppVar_17009 & cppMask_un_16_);
	cppVar_17010 = ROM.rd(cppVar_17009);
	cppVar_17012 = (cppVar_17010 == 176);
	if (cppVar_17012) {
	cppVar_17008 = P3;
	} else {
	cppVar_17014 = PC + 1;
	cppVar_17014 = (cppVar_17014 & cppMask_un_16_);
	cppVar_17015 = ROM.rd(cppVar_17014);
	cppVar_17017 = (cppVar_17015 == 184);
	if (cppVar_17017) {
	cppVar_17013 = IP;
	} else {
	cppVar_17019 = PC + 1;
	cppVar_17019 = (cppVar_17019 & cppMask_un_16_);
	cppVar_17020 = ROM.rd(cppVar_17019);
	cppVar_17022 = (cppVar_17020 == 208);
	if (cppVar_17022) {
	cppVar_17018 = PSW;
	} else {
	cppVar_17024 = PC + 1;
	cppVar_17024 = (cppVar_17024 & cppMask_un_16_);
	cppVar_17025 = ROM.rd(cppVar_17024);
	cppVar_17027 = (cppVar_17025 == 224);
	if (cppVar_17027) {
	cppVar_17023 = ACC;
	} else {
	cppVar_17029 = PC + 1;
	cppVar_17029 = (cppVar_17029 & cppMask_un_16_);
	cppVar_17030 = ROM.rd(cppVar_17029);
	cppVar_17032 = (cppVar_17030 == 240);
	if (cppVar_17032) {
	cppVar_17028 = B;
	} else {
	cppVar_17028 = 0;
	}
	cppVar_17023 = cppVar_17028;
	}
	cppVar_17018 = cppVar_17023;
	}
	cppVar_17013 = cppVar_17018;
	}
	cppVar_17008 = cppVar_17013;
	}
	cppVar_17003 = cppVar_17008;
	}
	cppVar_16998 = cppVar_17003;
	}
	cppVar_16993 = cppVar_16998;
	}
	cppVar_16988 = cppVar_16993;
	}
	cppVar_16983 = cppVar_16988;
	}
	cppVar_16978 = cppVar_16983;
	}
	cppVar_16973 = cppVar_16978;
	}
	cppVar_16968 = cppVar_16973;
	}
	cppVar_16963 = cppVar_16968;
	}
	cppVar_16958 = cppVar_16963;
	}
	cppVar_16953 = cppVar_16958;
	}
	cppVar_16948 = cppVar_16953;
	}
	cppVar_16943 = cppVar_16948;
	}
	cppVar_16938 = cppVar_16943;
	}
	cppVar_16933 = cppVar_16938;
	}
	cppVar_16928 = cppVar_16933;
	}
	cppVar_16919 = cppVar_16928;
	}
	cppVar_17034 = cppVar_16919 & ACC;
	cppVar_16913 = cppVar_17034;
	} else {
	cppVar_16913 = IE;
	}
	cppVar_16909 = cppVar_16913;
	} else {
	cppVar_17036 = ROM.rd(PC);
	cppVar_17038 = (cppVar_17036 == 67);
	if (cppVar_17038) {
	cppVar_17041 = PC + 1;
	cppVar_17041 = (cppVar_17041 & cppMask_un_16_);
	cppVar_17042 = ROM.rd(cppVar_17041);
	cppVar_17044 = (cppVar_17042 == 168);
	if (cppVar_17044) {
	cppVar_17046 = PC + 1;
	cppVar_17046 = (cppVar_17046 & cppMask_un_16_);
	cppVar_17047 = ROM.rd(cppVar_17046);
	cppVar_17048 = (cppVar_17047 >> 7) & cppMask_un_1_;
	cppVar_17050 = (cppVar_17048 == 0);
	if (cppVar_17050) {
	cppVar_17051 = PC + 1;
	cppVar_17051 = (cppVar_17051 & cppMask_un_16_);
	cppVar_17052 = ROM.rd(cppVar_17051);
	cppVar_17053 = IRAM.rd(cppVar_17052);
	cppVar_17045 = cppVar_17053;
	} else {
	cppVar_17055 = PC + 1;
	cppVar_17055 = (cppVar_17055 & cppMask_un_16_);
	cppVar_17056 = ROM.rd(cppVar_17055);
	cppVar_17058 = (cppVar_17056 == 128);
	if (cppVar_17058) {
	cppVar_17054 = P0;
	} else {
	cppVar_17060 = PC + 1;
	cppVar_17060 = (cppVar_17060 & cppMask_un_16_);
	cppVar_17061 = ROM.rd(cppVar_17060);
	cppVar_17063 = (cppVar_17061 == 129);
	if (cppVar_17063) {
	cppVar_17059 = SP;
	} else {
	cppVar_17065 = PC + 1;
	cppVar_17065 = (cppVar_17065 & cppMask_un_16_);
	cppVar_17066 = ROM.rd(cppVar_17065);
	cppVar_17068 = (cppVar_17066 == 130);
	if (cppVar_17068) {
	cppVar_17064 = DPL;
	} else {
	cppVar_17070 = PC + 1;
	cppVar_17070 = (cppVar_17070 & cppMask_un_16_);
	cppVar_17071 = ROM.rd(cppVar_17070);
	cppVar_17073 = (cppVar_17071 == 131);
	if (cppVar_17073) {
	cppVar_17069 = DPH;
	} else {
	cppVar_17075 = PC + 1;
	cppVar_17075 = (cppVar_17075 & cppMask_un_16_);
	cppVar_17076 = ROM.rd(cppVar_17075);
	cppVar_17078 = (cppVar_17076 == 135);
	if (cppVar_17078) {
	cppVar_17074 = PCON;
	} else {
	cppVar_17080 = PC + 1;
	cppVar_17080 = (cppVar_17080 & cppMask_un_16_);
	cppVar_17081 = ROM.rd(cppVar_17080);
	cppVar_17083 = (cppVar_17081 == 136);
	if (cppVar_17083) {
	cppVar_17079 = TCON;
	} else {
	cppVar_17085 = PC + 1;
	cppVar_17085 = (cppVar_17085 & cppMask_un_16_);
	cppVar_17086 = ROM.rd(cppVar_17085);
	cppVar_17088 = (cppVar_17086 == 137);
	if (cppVar_17088) {
	cppVar_17084 = TMOD;
	} else {
	cppVar_17090 = PC + 1;
	cppVar_17090 = (cppVar_17090 & cppMask_un_16_);
	cppVar_17091 = ROM.rd(cppVar_17090);
	cppVar_17093 = (cppVar_17091 == 138);
	if (cppVar_17093) {
	cppVar_17089 = TL0;
	} else {
	cppVar_17095 = PC + 1;
	cppVar_17095 = (cppVar_17095 & cppMask_un_16_);
	cppVar_17096 = ROM.rd(cppVar_17095);
	cppVar_17098 = (cppVar_17096 == 140);
	if (cppVar_17098) {
	cppVar_17094 = TH0;
	} else {
	cppVar_17100 = PC + 1;
	cppVar_17100 = (cppVar_17100 & cppMask_un_16_);
	cppVar_17101 = ROM.rd(cppVar_17100);
	cppVar_17103 = (cppVar_17101 == 139);
	if (cppVar_17103) {
	cppVar_17099 = TL1;
	} else {
	cppVar_17105 = PC + 1;
	cppVar_17105 = (cppVar_17105 & cppMask_un_16_);
	cppVar_17106 = ROM.rd(cppVar_17105);
	cppVar_17108 = (cppVar_17106 == 141);
	if (cppVar_17108) {
	cppVar_17104 = TH1;
	} else {
	cppVar_17110 = PC + 1;
	cppVar_17110 = (cppVar_17110 & cppMask_un_16_);
	cppVar_17111 = ROM.rd(cppVar_17110);
	cppVar_17113 = (cppVar_17111 == 144);
	if (cppVar_17113) {
	cppVar_17109 = P1;
	} else {
	cppVar_17115 = PC + 1;
	cppVar_17115 = (cppVar_17115 & cppMask_un_16_);
	cppVar_17116 = ROM.rd(cppVar_17115);
	cppVar_17118 = (cppVar_17116 == 152);
	if (cppVar_17118) {
	cppVar_17114 = SCON;
	} else {
	cppVar_17120 = PC + 1;
	cppVar_17120 = (cppVar_17120 & cppMask_un_16_);
	cppVar_17121 = ROM.rd(cppVar_17120);
	cppVar_17123 = (cppVar_17121 == 153);
	if (cppVar_17123) {
	cppVar_17119 = SBUF;
	} else {
	cppVar_17125 = PC + 1;
	cppVar_17125 = (cppVar_17125 & cppMask_un_16_);
	cppVar_17126 = ROM.rd(cppVar_17125);
	cppVar_17128 = (cppVar_17126 == 160);
	if (cppVar_17128) {
	cppVar_17124 = P2;
	} else {
	cppVar_17130 = PC + 1;
	cppVar_17130 = (cppVar_17130 & cppMask_un_16_);
	cppVar_17131 = ROM.rd(cppVar_17130);
	cppVar_17133 = (cppVar_17131 == 168);
	if (cppVar_17133) {
	cppVar_17129 = IE;
	} else {
	cppVar_17135 = PC + 1;
	cppVar_17135 = (cppVar_17135 & cppMask_un_16_);
	cppVar_17136 = ROM.rd(cppVar_17135);
	cppVar_17138 = (cppVar_17136 == 176);
	if (cppVar_17138) {
	cppVar_17134 = P3;
	} else {
	cppVar_17140 = PC + 1;
	cppVar_17140 = (cppVar_17140 & cppMask_un_16_);
	cppVar_17141 = ROM.rd(cppVar_17140);
	cppVar_17143 = (cppVar_17141 == 184);
	if (cppVar_17143) {
	cppVar_17139 = IP;
	} else {
	cppVar_17145 = PC + 1;
	cppVar_17145 = (cppVar_17145 & cppMask_un_16_);
	cppVar_17146 = ROM.rd(cppVar_17145);
	cppVar_17148 = (cppVar_17146 == 208);
	if (cppVar_17148) {
	cppVar_17144 = PSW;
	} else {
	cppVar_17150 = PC + 1;
	cppVar_17150 = (cppVar_17150 & cppMask_un_16_);
	cppVar_17151 = ROM.rd(cppVar_17150);
	cppVar_17153 = (cppVar_17151 == 224);
	if (cppVar_17153) {
	cppVar_17149 = ACC;
	} else {
	cppVar_17155 = PC + 1;
	cppVar_17155 = (cppVar_17155 & cppMask_un_16_);
	cppVar_17156 = ROM.rd(cppVar_17155);
	cppVar_17158 = (cppVar_17156 == 240);
	if (cppVar_17158) {
	cppVar_17154 = B;
	} else {
	cppVar_17154 = 0;
	}
	cppVar_17149 = cppVar_17154;
	}
	cppVar_17144 = cppVar_17149;
	}
	cppVar_17139 = cppVar_17144;
	}
	cppVar_17134 = cppVar_17139;
	}
	cppVar_17129 = cppVar_17134;
	}
	cppVar_17124 = cppVar_17129;
	}
	cppVar_17119 = cppVar_17124;
	}
	cppVar_17114 = cppVar_17119;
	}
	cppVar_17109 = cppVar_17114;
	}
	cppVar_17104 = cppVar_17109;
	}
	cppVar_17099 = cppVar_17104;
	}
	cppVar_17094 = cppVar_17099;
	}
	cppVar_17089 = cppVar_17094;
	}
	cppVar_17084 = cppVar_17089;
	}
	cppVar_17079 = cppVar_17084;
	}
	cppVar_17074 = cppVar_17079;
	}
	cppVar_17069 = cppVar_17074;
	}
	cppVar_17064 = cppVar_17069;
	}
	cppVar_17059 = cppVar_17064;
	}
	cppVar_17054 = cppVar_17059;
	}
	cppVar_17045 = cppVar_17054;
	}
	cppVar_17161 = PC + 2;
	cppVar_17161 = (cppVar_17161 & cppMask_un_16_);
	cppVar_17162 = ROM.rd(cppVar_17161);
	cppVar_17163 = cppVar_17045 | cppVar_17162;
	cppVar_17039 = cppVar_17163;
	} else {
	cppVar_17039 = IE;
	}
	cppVar_17035 = cppVar_17039;
	} else {
	cppVar_17165 = ROM.rd(PC);
	cppVar_17167 = (cppVar_17165 == 66);
	if (cppVar_17167) {
	cppVar_17170 = PC + 1;
	cppVar_17170 = (cppVar_17170 & cppMask_un_16_);
	cppVar_17171 = ROM.rd(cppVar_17170);
	cppVar_17173 = (cppVar_17171 == 168);
	if (cppVar_17173) {
	cppVar_17175 = PC + 1;
	cppVar_17175 = (cppVar_17175 & cppMask_un_16_);
	cppVar_17176 = ROM.rd(cppVar_17175);
	cppVar_17177 = (cppVar_17176 >> 7) & cppMask_un_1_;
	cppVar_17179 = (cppVar_17177 == 0);
	if (cppVar_17179) {
	cppVar_17180 = PC + 1;
	cppVar_17180 = (cppVar_17180 & cppMask_un_16_);
	cppVar_17181 = ROM.rd(cppVar_17180);
	cppVar_17182 = IRAM.rd(cppVar_17181);
	cppVar_17174 = cppVar_17182;
	} else {
	cppVar_17184 = PC + 1;
	cppVar_17184 = (cppVar_17184 & cppMask_un_16_);
	cppVar_17185 = ROM.rd(cppVar_17184);
	cppVar_17187 = (cppVar_17185 == 128);
	if (cppVar_17187) {
	cppVar_17183 = P0;
	} else {
	cppVar_17189 = PC + 1;
	cppVar_17189 = (cppVar_17189 & cppMask_un_16_);
	cppVar_17190 = ROM.rd(cppVar_17189);
	cppVar_17192 = (cppVar_17190 == 129);
	if (cppVar_17192) {
	cppVar_17188 = SP;
	} else {
	cppVar_17194 = PC + 1;
	cppVar_17194 = (cppVar_17194 & cppMask_un_16_);
	cppVar_17195 = ROM.rd(cppVar_17194);
	cppVar_17197 = (cppVar_17195 == 130);
	if (cppVar_17197) {
	cppVar_17193 = DPL;
	} else {
	cppVar_17199 = PC + 1;
	cppVar_17199 = (cppVar_17199 & cppMask_un_16_);
	cppVar_17200 = ROM.rd(cppVar_17199);
	cppVar_17202 = (cppVar_17200 == 131);
	if (cppVar_17202) {
	cppVar_17198 = DPH;
	} else {
	cppVar_17204 = PC + 1;
	cppVar_17204 = (cppVar_17204 & cppMask_un_16_);
	cppVar_17205 = ROM.rd(cppVar_17204);
	cppVar_17207 = (cppVar_17205 == 135);
	if (cppVar_17207) {
	cppVar_17203 = PCON;
	} else {
	cppVar_17209 = PC + 1;
	cppVar_17209 = (cppVar_17209 & cppMask_un_16_);
	cppVar_17210 = ROM.rd(cppVar_17209);
	cppVar_17212 = (cppVar_17210 == 136);
	if (cppVar_17212) {
	cppVar_17208 = TCON;
	} else {
	cppVar_17214 = PC + 1;
	cppVar_17214 = (cppVar_17214 & cppMask_un_16_);
	cppVar_17215 = ROM.rd(cppVar_17214);
	cppVar_17217 = (cppVar_17215 == 137);
	if (cppVar_17217) {
	cppVar_17213 = TMOD;
	} else {
	cppVar_17219 = PC + 1;
	cppVar_17219 = (cppVar_17219 & cppMask_un_16_);
	cppVar_17220 = ROM.rd(cppVar_17219);
	cppVar_17222 = (cppVar_17220 == 138);
	if (cppVar_17222) {
	cppVar_17218 = TL0;
	} else {
	cppVar_17224 = PC + 1;
	cppVar_17224 = (cppVar_17224 & cppMask_un_16_);
	cppVar_17225 = ROM.rd(cppVar_17224);
	cppVar_17227 = (cppVar_17225 == 140);
	if (cppVar_17227) {
	cppVar_17223 = TH0;
	} else {
	cppVar_17229 = PC + 1;
	cppVar_17229 = (cppVar_17229 & cppMask_un_16_);
	cppVar_17230 = ROM.rd(cppVar_17229);
	cppVar_17232 = (cppVar_17230 == 139);
	if (cppVar_17232) {
	cppVar_17228 = TL1;
	} else {
	cppVar_17234 = PC + 1;
	cppVar_17234 = (cppVar_17234 & cppMask_un_16_);
	cppVar_17235 = ROM.rd(cppVar_17234);
	cppVar_17237 = (cppVar_17235 == 141);
	if (cppVar_17237) {
	cppVar_17233 = TH1;
	} else {
	cppVar_17239 = PC + 1;
	cppVar_17239 = (cppVar_17239 & cppMask_un_16_);
	cppVar_17240 = ROM.rd(cppVar_17239);
	cppVar_17242 = (cppVar_17240 == 144);
	if (cppVar_17242) {
	cppVar_17238 = P1;
	} else {
	cppVar_17244 = PC + 1;
	cppVar_17244 = (cppVar_17244 & cppMask_un_16_);
	cppVar_17245 = ROM.rd(cppVar_17244);
	cppVar_17247 = (cppVar_17245 == 152);
	if (cppVar_17247) {
	cppVar_17243 = SCON;
	} else {
	cppVar_17249 = PC + 1;
	cppVar_17249 = (cppVar_17249 & cppMask_un_16_);
	cppVar_17250 = ROM.rd(cppVar_17249);
	cppVar_17252 = (cppVar_17250 == 153);
	if (cppVar_17252) {
	cppVar_17248 = SBUF;
	} else {
	cppVar_17254 = PC + 1;
	cppVar_17254 = (cppVar_17254 & cppMask_un_16_);
	cppVar_17255 = ROM.rd(cppVar_17254);
	cppVar_17257 = (cppVar_17255 == 160);
	if (cppVar_17257) {
	cppVar_17253 = P2;
	} else {
	cppVar_17259 = PC + 1;
	cppVar_17259 = (cppVar_17259 & cppMask_un_16_);
	cppVar_17260 = ROM.rd(cppVar_17259);
	cppVar_17262 = (cppVar_17260 == 168);
	if (cppVar_17262) {
	cppVar_17258 = IE;
	} else {
	cppVar_17264 = PC + 1;
	cppVar_17264 = (cppVar_17264 & cppMask_un_16_);
	cppVar_17265 = ROM.rd(cppVar_17264);
	cppVar_17267 = (cppVar_17265 == 176);
	if (cppVar_17267) {
	cppVar_17263 = P3;
	} else {
	cppVar_17269 = PC + 1;
	cppVar_17269 = (cppVar_17269 & cppMask_un_16_);
	cppVar_17270 = ROM.rd(cppVar_17269);
	cppVar_17272 = (cppVar_17270 == 184);
	if (cppVar_17272) {
	cppVar_17268 = IP;
	} else {
	cppVar_17274 = PC + 1;
	cppVar_17274 = (cppVar_17274 & cppMask_un_16_);
	cppVar_17275 = ROM.rd(cppVar_17274);
	cppVar_17277 = (cppVar_17275 == 208);
	if (cppVar_17277) {
	cppVar_17273 = PSW;
	} else {
	cppVar_17279 = PC + 1;
	cppVar_17279 = (cppVar_17279 & cppMask_un_16_);
	cppVar_17280 = ROM.rd(cppVar_17279);
	cppVar_17282 = (cppVar_17280 == 224);
	if (cppVar_17282) {
	cppVar_17278 = ACC;
	} else {
	cppVar_17284 = PC + 1;
	cppVar_17284 = (cppVar_17284 & cppMask_un_16_);
	cppVar_17285 = ROM.rd(cppVar_17284);
	cppVar_17287 = (cppVar_17285 == 240);
	if (cppVar_17287) {
	cppVar_17283 = B;
	} else {
	cppVar_17283 = 0;
	}
	cppVar_17278 = cppVar_17283;
	}
	cppVar_17273 = cppVar_17278;
	}
	cppVar_17268 = cppVar_17273;
	}
	cppVar_17263 = cppVar_17268;
	}
	cppVar_17258 = cppVar_17263;
	}
	cppVar_17253 = cppVar_17258;
	}
	cppVar_17248 = cppVar_17253;
	}
	cppVar_17243 = cppVar_17248;
	}
	cppVar_17238 = cppVar_17243;
	}
	cppVar_17233 = cppVar_17238;
	}
	cppVar_17228 = cppVar_17233;
	}
	cppVar_17223 = cppVar_17228;
	}
	cppVar_17218 = cppVar_17223;
	}
	cppVar_17213 = cppVar_17218;
	}
	cppVar_17208 = cppVar_17213;
	}
	cppVar_17203 = cppVar_17208;
	}
	cppVar_17198 = cppVar_17203;
	}
	cppVar_17193 = cppVar_17198;
	}
	cppVar_17188 = cppVar_17193;
	}
	cppVar_17183 = cppVar_17188;
	}
	cppVar_17174 = cppVar_17183;
	}
	cppVar_17289 = cppVar_17174 | ACC;
	cppVar_17168 = cppVar_17289;
	} else {
	cppVar_17168 = IE;
	}
	cppVar_17164 = cppVar_17168;
	} else {
	cppVar_17291 = ROM.rd(PC);
	cppVar_17293 = (cppVar_17291 == 213);
	cppVar_17294 = ROM.rd(PC);
	cppVar_17296 = (cppVar_17294 == 21);
	cppVar_17297 = cppVar_17293 || cppVar_17296;
	if (cppVar_17297) {
	cppVar_17300 = PC + 1;
	cppVar_17300 = (cppVar_17300 & cppMask_un_16_);
	cppVar_17301 = ROM.rd(cppVar_17300);
	cppVar_17303 = (cppVar_17301 == 168);
	if (cppVar_17303) {
	cppVar_17305 = PC + 1;
	cppVar_17305 = (cppVar_17305 & cppMask_un_16_);
	cppVar_17306 = ROM.rd(cppVar_17305);
	cppVar_17307 = (cppVar_17306 >> 7) & cppMask_un_1_;
	cppVar_17309 = (cppVar_17307 == 0);
	if (cppVar_17309) {
	cppVar_17310 = PC + 1;
	cppVar_17310 = (cppVar_17310 & cppMask_un_16_);
	cppVar_17311 = ROM.rd(cppVar_17310);
	cppVar_17312 = IRAM.rd(cppVar_17311);
	cppVar_17304 = cppVar_17312;
	} else {
	cppVar_17314 = PC + 1;
	cppVar_17314 = (cppVar_17314 & cppMask_un_16_);
	cppVar_17315 = ROM.rd(cppVar_17314);
	cppVar_17317 = (cppVar_17315 == 128);
	if (cppVar_17317) {
	cppVar_17313 = P0;
	} else {
	cppVar_17319 = PC + 1;
	cppVar_17319 = (cppVar_17319 & cppMask_un_16_);
	cppVar_17320 = ROM.rd(cppVar_17319);
	cppVar_17322 = (cppVar_17320 == 129);
	if (cppVar_17322) {
	cppVar_17318 = SP;
	} else {
	cppVar_17324 = PC + 1;
	cppVar_17324 = (cppVar_17324 & cppMask_un_16_);
	cppVar_17325 = ROM.rd(cppVar_17324);
	cppVar_17327 = (cppVar_17325 == 130);
	if (cppVar_17327) {
	cppVar_17323 = DPL;
	} else {
	cppVar_17329 = PC + 1;
	cppVar_17329 = (cppVar_17329 & cppMask_un_16_);
	cppVar_17330 = ROM.rd(cppVar_17329);
	cppVar_17332 = (cppVar_17330 == 131);
	if (cppVar_17332) {
	cppVar_17328 = DPH;
	} else {
	cppVar_17334 = PC + 1;
	cppVar_17334 = (cppVar_17334 & cppMask_un_16_);
	cppVar_17335 = ROM.rd(cppVar_17334);
	cppVar_17337 = (cppVar_17335 == 135);
	if (cppVar_17337) {
	cppVar_17333 = PCON;
	} else {
	cppVar_17339 = PC + 1;
	cppVar_17339 = (cppVar_17339 & cppMask_un_16_);
	cppVar_17340 = ROM.rd(cppVar_17339);
	cppVar_17342 = (cppVar_17340 == 136);
	if (cppVar_17342) {
	cppVar_17338 = TCON;
	} else {
	cppVar_17344 = PC + 1;
	cppVar_17344 = (cppVar_17344 & cppMask_un_16_);
	cppVar_17345 = ROM.rd(cppVar_17344);
	cppVar_17347 = (cppVar_17345 == 137);
	if (cppVar_17347) {
	cppVar_17343 = TMOD;
	} else {
	cppVar_17349 = PC + 1;
	cppVar_17349 = (cppVar_17349 & cppMask_un_16_);
	cppVar_17350 = ROM.rd(cppVar_17349);
	cppVar_17352 = (cppVar_17350 == 138);
	if (cppVar_17352) {
	cppVar_17348 = TL0;
	} else {
	cppVar_17354 = PC + 1;
	cppVar_17354 = (cppVar_17354 & cppMask_un_16_);
	cppVar_17355 = ROM.rd(cppVar_17354);
	cppVar_17357 = (cppVar_17355 == 140);
	if (cppVar_17357) {
	cppVar_17353 = TH0;
	} else {
	cppVar_17359 = PC + 1;
	cppVar_17359 = (cppVar_17359 & cppMask_un_16_);
	cppVar_17360 = ROM.rd(cppVar_17359);
	cppVar_17362 = (cppVar_17360 == 139);
	if (cppVar_17362) {
	cppVar_17358 = TL1;
	} else {
	cppVar_17364 = PC + 1;
	cppVar_17364 = (cppVar_17364 & cppMask_un_16_);
	cppVar_17365 = ROM.rd(cppVar_17364);
	cppVar_17367 = (cppVar_17365 == 141);
	if (cppVar_17367) {
	cppVar_17363 = TH1;
	} else {
	cppVar_17369 = PC + 1;
	cppVar_17369 = (cppVar_17369 & cppMask_un_16_);
	cppVar_17370 = ROM.rd(cppVar_17369);
	cppVar_17372 = (cppVar_17370 == 144);
	if (cppVar_17372) {
	cppVar_17368 = P1;
	} else {
	cppVar_17374 = PC + 1;
	cppVar_17374 = (cppVar_17374 & cppMask_un_16_);
	cppVar_17375 = ROM.rd(cppVar_17374);
	cppVar_17377 = (cppVar_17375 == 152);
	if (cppVar_17377) {
	cppVar_17373 = SCON;
	} else {
	cppVar_17379 = PC + 1;
	cppVar_17379 = (cppVar_17379 & cppMask_un_16_);
	cppVar_17380 = ROM.rd(cppVar_17379);
	cppVar_17382 = (cppVar_17380 == 153);
	if (cppVar_17382) {
	cppVar_17378 = SBUF;
	} else {
	cppVar_17384 = PC + 1;
	cppVar_17384 = (cppVar_17384 & cppMask_un_16_);
	cppVar_17385 = ROM.rd(cppVar_17384);
	cppVar_17387 = (cppVar_17385 == 160);
	if (cppVar_17387) {
	cppVar_17383 = P2;
	} else {
	cppVar_17389 = PC + 1;
	cppVar_17389 = (cppVar_17389 & cppMask_un_16_);
	cppVar_17390 = ROM.rd(cppVar_17389);
	cppVar_17392 = (cppVar_17390 == 168);
	if (cppVar_17392) {
	cppVar_17388 = IE;
	} else {
	cppVar_17394 = PC + 1;
	cppVar_17394 = (cppVar_17394 & cppMask_un_16_);
	cppVar_17395 = ROM.rd(cppVar_17394);
	cppVar_17397 = (cppVar_17395 == 176);
	if (cppVar_17397) {
	cppVar_17393 = P3;
	} else {
	cppVar_17399 = PC + 1;
	cppVar_17399 = (cppVar_17399 & cppMask_un_16_);
	cppVar_17400 = ROM.rd(cppVar_17399);
	cppVar_17402 = (cppVar_17400 == 184);
	if (cppVar_17402) {
	cppVar_17398 = IP;
	} else {
	cppVar_17404 = PC + 1;
	cppVar_17404 = (cppVar_17404 & cppMask_un_16_);
	cppVar_17405 = ROM.rd(cppVar_17404);
	cppVar_17407 = (cppVar_17405 == 208);
	if (cppVar_17407) {
	cppVar_17403 = PSW;
	} else {
	cppVar_17409 = PC + 1;
	cppVar_17409 = (cppVar_17409 & cppMask_un_16_);
	cppVar_17410 = ROM.rd(cppVar_17409);
	cppVar_17412 = (cppVar_17410 == 224);
	if (cppVar_17412) {
	cppVar_17408 = ACC;
	} else {
	cppVar_17414 = PC + 1;
	cppVar_17414 = (cppVar_17414 & cppMask_un_16_);
	cppVar_17415 = ROM.rd(cppVar_17414);
	cppVar_17417 = (cppVar_17415 == 240);
	if (cppVar_17417) {
	cppVar_17413 = B;
	} else {
	cppVar_17413 = 0;
	}
	cppVar_17408 = cppVar_17413;
	}
	cppVar_17403 = cppVar_17408;
	}
	cppVar_17398 = cppVar_17403;
	}
	cppVar_17393 = cppVar_17398;
	}
	cppVar_17388 = cppVar_17393;
	}
	cppVar_17383 = cppVar_17388;
	}
	cppVar_17378 = cppVar_17383;
	}
	cppVar_17373 = cppVar_17378;
	}
	cppVar_17368 = cppVar_17373;
	}
	cppVar_17363 = cppVar_17368;
	}
	cppVar_17358 = cppVar_17363;
	}
	cppVar_17353 = cppVar_17358;
	}
	cppVar_17348 = cppVar_17353;
	}
	cppVar_17343 = cppVar_17348;
	}
	cppVar_17338 = cppVar_17343;
	}
	cppVar_17333 = cppVar_17338;
	}
	cppVar_17328 = cppVar_17333;
	}
	cppVar_17323 = cppVar_17328;
	}
	cppVar_17318 = cppVar_17323;
	}
	cppVar_17313 = cppVar_17318;
	}
	cppVar_17304 = cppVar_17313;
	}
	cppVar_17420 = cppVar_17304 - 1;
	cppVar_17420 = (cppVar_17420 & cppMask_un_8_);
	cppVar_17298 = cppVar_17420;
	} else {
	cppVar_17298 = IE;
	}
	cppVar_17290 = cppVar_17298;
	} else {
	cppVar_17422 = ROM.rd(PC);
	cppVar_17424 = (cppVar_17422 == 194);
	cppVar_17425 = ROM.rd(PC);
	cppVar_17427 = (cppVar_17425 == 16);
	cppVar_17428 = cppVar_17424 || cppVar_17427;
	if (cppVar_17428) {
	cppVar_17432 = PC + 1;
	cppVar_17432 = (cppVar_17432 & cppMask_un_16_);
	cppVar_17433 = ROM.rd(cppVar_17432);
	cppVar_17434 = (cppVar_17433 >> 7) & cppMask_un_1_;
	cppVar_17436 = (cppVar_17434 == 1);
	if (cppVar_17436) {
	cppVar_17437 = PC + 1;
	cppVar_17437 = (cppVar_17437 & cppMask_un_16_);
	cppVar_17438 = ROM.rd(cppVar_17437);
	cppVar_17439 = (cppVar_17438 >> 3) & cppMask_un_5_;
	cppVar_17441 = (cppVar_17439 << 3) | 0;
	cppVar_17441 = (cppVar_17441 & cppMask_un_8_);
	cppVar_17430 = cppVar_17441;
	} else {
	cppVar_17442 = PC + 1;
	cppVar_17442 = (cppVar_17442 & cppMask_un_16_);
	cppVar_17443 = ROM.rd(cppVar_17442);
	cppVar_17444 = (cppVar_17443 >> 3) & cppMask_un_5_;
	cppVar_17445 = (cppVar_17444 & cppMask_un_5_);
	cppVar_17447 = cppVar_17445 + 32;
	cppVar_17447 = (cppVar_17447 & cppMask_un_8_);
	cppVar_17430 = cppVar_17447;
	}
	cppVar_17449 = (cppVar_17430 == 168);
	if (cppVar_17449) {
	cppVar_17451 = PC + 1;
	cppVar_17451 = (cppVar_17451 & cppMask_un_16_);
	cppVar_17452 = ROM.rd(cppVar_17451);
	cppVar_17453 = (cppVar_17452 >> 0) & cppMask_un_3_;
	cppVar_17454 = (cppVar_17453 & cppMask_un_3_);
	cppVar_17455 = 1 << static_cast<unsigned>(cppVar_17454);
	cppVar_17455 = (cppVar_17455 & cppMask_un_8_);
	cppVar_17456 = ~cppVar_17455;
	cppVar_17459 = PC + 1;
	cppVar_17459 = (cppVar_17459 & cppMask_un_16_);
	cppVar_17460 = ROM.rd(cppVar_17459);
	cppVar_17461 = (cppVar_17460 >> 7) & cppMask_un_1_;
	cppVar_17462 = (cppVar_17461 == 1);
	if (cppVar_17462) {
	cppVar_17463 = PC + 1;
	cppVar_17463 = (cppVar_17463 & cppMask_un_16_);
	cppVar_17464 = ROM.rd(cppVar_17463);
	cppVar_17465 = (cppVar_17464 >> 3) & cppMask_un_5_;
	cppVar_17466 = (cppVar_17465 << 3) | 0;
	cppVar_17466 = (cppVar_17466 & cppMask_un_8_);
	cppVar_17458 = cppVar_17466;
	} else {
	cppVar_17467 = PC + 1;
	cppVar_17467 = (cppVar_17467 & cppMask_un_16_);
	cppVar_17468 = ROM.rd(cppVar_17467);
	cppVar_17469 = (cppVar_17468 >> 3) & cppMask_un_5_;
	cppVar_17470 = (cppVar_17469 & cppMask_un_5_);
	cppVar_17471 = cppVar_17470 + 32;
	cppVar_17471 = (cppVar_17471 & cppMask_un_8_);
	cppVar_17458 = cppVar_17471;
	}
	cppVar_17472 = (cppVar_17458 >> 7) & cppMask_un_1_;
	cppVar_17474 = (cppVar_17472 == 0);
	if (cppVar_17474) {
	cppVar_17476 = PC + 1;
	cppVar_17476 = (cppVar_17476 & cppMask_un_16_);
	cppVar_17477 = ROM.rd(cppVar_17476);
	cppVar_17478 = (cppVar_17477 >> 7) & cppMask_un_1_;
	cppVar_17479 = (cppVar_17478 == 1);
	if (cppVar_17479) {
	cppVar_17480 = PC + 1;
	cppVar_17480 = (cppVar_17480 & cppMask_un_16_);
	cppVar_17481 = ROM.rd(cppVar_17480);
	cppVar_17482 = (cppVar_17481 >> 3) & cppMask_un_5_;
	cppVar_17483 = (cppVar_17482 << 3) | 0;
	cppVar_17483 = (cppVar_17483 & cppMask_un_8_);
	cppVar_17475 = cppVar_17483;
	} else {
	cppVar_17484 = PC + 1;
	cppVar_17484 = (cppVar_17484 & cppMask_un_16_);
	cppVar_17485 = ROM.rd(cppVar_17484);
	cppVar_17486 = (cppVar_17485 >> 3) & cppMask_un_5_;
	cppVar_17487 = (cppVar_17486 & cppMask_un_5_);
	cppVar_17488 = cppVar_17487 + 32;
	cppVar_17488 = (cppVar_17488 & cppMask_un_8_);
	cppVar_17475 = cppVar_17488;
	}
	cppVar_17489 = IRAM.rd(cppVar_17475);
	cppVar_17457 = cppVar_17489;
	} else {
	cppVar_17492 = PC + 1;
	cppVar_17492 = (cppVar_17492 & cppMask_un_16_);
	cppVar_17493 = ROM.rd(cppVar_17492);
	cppVar_17494 = (cppVar_17493 >> 7) & cppMask_un_1_;
	cppVar_17495 = (cppVar_17494 == 1);
	if (cppVar_17495) {
	cppVar_17496 = PC + 1;
	cppVar_17496 = (cppVar_17496 & cppMask_un_16_);
	cppVar_17497 = ROM.rd(cppVar_17496);
	cppVar_17498 = (cppVar_17497 >> 3) & cppMask_un_5_;
	cppVar_17499 = (cppVar_17498 << 3) | 0;
	cppVar_17499 = (cppVar_17499 & cppMask_un_8_);
	cppVar_17491 = cppVar_17499;
	} else {
	cppVar_17500 = PC + 1;
	cppVar_17500 = (cppVar_17500 & cppMask_un_16_);
	cppVar_17501 = ROM.rd(cppVar_17500);
	cppVar_17502 = (cppVar_17501 >> 3) & cppMask_un_5_;
	cppVar_17503 = (cppVar_17502 & cppMask_un_5_);
	cppVar_17504 = cppVar_17503 + 32;
	cppVar_17504 = (cppVar_17504 & cppMask_un_8_);
	cppVar_17491 = cppVar_17504;
	}
	cppVar_17506 = (cppVar_17491 == 128);
	if (cppVar_17506) {
	cppVar_17490 = P0;
	} else {
	cppVar_17509 = PC + 1;
	cppVar_17509 = (cppVar_17509 & cppMask_un_16_);
	cppVar_17510 = ROM.rd(cppVar_17509);
	cppVar_17511 = (cppVar_17510 >> 7) & cppMask_un_1_;
	cppVar_17512 = (cppVar_17511 == 1);
	if (cppVar_17512) {
	cppVar_17513 = PC + 1;
	cppVar_17513 = (cppVar_17513 & cppMask_un_16_);
	cppVar_17514 = ROM.rd(cppVar_17513);
	cppVar_17515 = (cppVar_17514 >> 3) & cppMask_un_5_;
	cppVar_17516 = (cppVar_17515 << 3) | 0;
	cppVar_17516 = (cppVar_17516 & cppMask_un_8_);
	cppVar_17508 = cppVar_17516;
	} else {
	cppVar_17517 = PC + 1;
	cppVar_17517 = (cppVar_17517 & cppMask_un_16_);
	cppVar_17518 = ROM.rd(cppVar_17517);
	cppVar_17519 = (cppVar_17518 >> 3) & cppMask_un_5_;
	cppVar_17520 = (cppVar_17519 & cppMask_un_5_);
	cppVar_17521 = cppVar_17520 + 32;
	cppVar_17521 = (cppVar_17521 & cppMask_un_8_);
	cppVar_17508 = cppVar_17521;
	}
	cppVar_17523 = (cppVar_17508 == 129);
	if (cppVar_17523) {
	cppVar_17507 = SP;
	} else {
	cppVar_17526 = PC + 1;
	cppVar_17526 = (cppVar_17526 & cppMask_un_16_);
	cppVar_17527 = ROM.rd(cppVar_17526);
	cppVar_17528 = (cppVar_17527 >> 7) & cppMask_un_1_;
	cppVar_17529 = (cppVar_17528 == 1);
	if (cppVar_17529) {
	cppVar_17530 = PC + 1;
	cppVar_17530 = (cppVar_17530 & cppMask_un_16_);
	cppVar_17531 = ROM.rd(cppVar_17530);
	cppVar_17532 = (cppVar_17531 >> 3) & cppMask_un_5_;
	cppVar_17533 = (cppVar_17532 << 3) | 0;
	cppVar_17533 = (cppVar_17533 & cppMask_un_8_);
	cppVar_17525 = cppVar_17533;
	} else {
	cppVar_17534 = PC + 1;
	cppVar_17534 = (cppVar_17534 & cppMask_un_16_);
	cppVar_17535 = ROM.rd(cppVar_17534);
	cppVar_17536 = (cppVar_17535 >> 3) & cppMask_un_5_;
	cppVar_17537 = (cppVar_17536 & cppMask_un_5_);
	cppVar_17538 = cppVar_17537 + 32;
	cppVar_17538 = (cppVar_17538 & cppMask_un_8_);
	cppVar_17525 = cppVar_17538;
	}
	cppVar_17540 = (cppVar_17525 == 130);
	if (cppVar_17540) {
	cppVar_17524 = DPL;
	} else {
	cppVar_17543 = PC + 1;
	cppVar_17543 = (cppVar_17543 & cppMask_un_16_);
	cppVar_17544 = ROM.rd(cppVar_17543);
	cppVar_17545 = (cppVar_17544 >> 7) & cppMask_un_1_;
	cppVar_17546 = (cppVar_17545 == 1);
	if (cppVar_17546) {
	cppVar_17547 = PC + 1;
	cppVar_17547 = (cppVar_17547 & cppMask_un_16_);
	cppVar_17548 = ROM.rd(cppVar_17547);
	cppVar_17549 = (cppVar_17548 >> 3) & cppMask_un_5_;
	cppVar_17550 = (cppVar_17549 << 3) | 0;
	cppVar_17550 = (cppVar_17550 & cppMask_un_8_);
	cppVar_17542 = cppVar_17550;
	} else {
	cppVar_17551 = PC + 1;
	cppVar_17551 = (cppVar_17551 & cppMask_un_16_);
	cppVar_17552 = ROM.rd(cppVar_17551);
	cppVar_17553 = (cppVar_17552 >> 3) & cppMask_un_5_;
	cppVar_17554 = (cppVar_17553 & cppMask_un_5_);
	cppVar_17555 = cppVar_17554 + 32;
	cppVar_17555 = (cppVar_17555 & cppMask_un_8_);
	cppVar_17542 = cppVar_17555;
	}
	cppVar_17557 = (cppVar_17542 == 131);
	if (cppVar_17557) {
	cppVar_17541 = DPH;
	} else {
	cppVar_17560 = PC + 1;
	cppVar_17560 = (cppVar_17560 & cppMask_un_16_);
	cppVar_17561 = ROM.rd(cppVar_17560);
	cppVar_17562 = (cppVar_17561 >> 7) & cppMask_un_1_;
	cppVar_17563 = (cppVar_17562 == 1);
	if (cppVar_17563) {
	cppVar_17564 = PC + 1;
	cppVar_17564 = (cppVar_17564 & cppMask_un_16_);
	cppVar_17565 = ROM.rd(cppVar_17564);
	cppVar_17566 = (cppVar_17565 >> 3) & cppMask_un_5_;
	cppVar_17567 = (cppVar_17566 << 3) | 0;
	cppVar_17567 = (cppVar_17567 & cppMask_un_8_);
	cppVar_17559 = cppVar_17567;
	} else {
	cppVar_17568 = PC + 1;
	cppVar_17568 = (cppVar_17568 & cppMask_un_16_);
	cppVar_17569 = ROM.rd(cppVar_17568);
	cppVar_17570 = (cppVar_17569 >> 3) & cppMask_un_5_;
	cppVar_17571 = (cppVar_17570 & cppMask_un_5_);
	cppVar_17572 = cppVar_17571 + 32;
	cppVar_17572 = (cppVar_17572 & cppMask_un_8_);
	cppVar_17559 = cppVar_17572;
	}
	cppVar_17574 = (cppVar_17559 == 135);
	if (cppVar_17574) {
	cppVar_17558 = PCON;
	} else {
	cppVar_17577 = PC + 1;
	cppVar_17577 = (cppVar_17577 & cppMask_un_16_);
	cppVar_17578 = ROM.rd(cppVar_17577);
	cppVar_17579 = (cppVar_17578 >> 7) & cppMask_un_1_;
	cppVar_17580 = (cppVar_17579 == 1);
	if (cppVar_17580) {
	cppVar_17581 = PC + 1;
	cppVar_17581 = (cppVar_17581 & cppMask_un_16_);
	cppVar_17582 = ROM.rd(cppVar_17581);
	cppVar_17583 = (cppVar_17582 >> 3) & cppMask_un_5_;
	cppVar_17584 = (cppVar_17583 << 3) | 0;
	cppVar_17584 = (cppVar_17584 & cppMask_un_8_);
	cppVar_17576 = cppVar_17584;
	} else {
	cppVar_17585 = PC + 1;
	cppVar_17585 = (cppVar_17585 & cppMask_un_16_);
	cppVar_17586 = ROM.rd(cppVar_17585);
	cppVar_17587 = (cppVar_17586 >> 3) & cppMask_un_5_;
	cppVar_17588 = (cppVar_17587 & cppMask_un_5_);
	cppVar_17589 = cppVar_17588 + 32;
	cppVar_17589 = (cppVar_17589 & cppMask_un_8_);
	cppVar_17576 = cppVar_17589;
	}
	cppVar_17591 = (cppVar_17576 == 136);
	if (cppVar_17591) {
	cppVar_17575 = TCON;
	} else {
	cppVar_17594 = PC + 1;
	cppVar_17594 = (cppVar_17594 & cppMask_un_16_);
	cppVar_17595 = ROM.rd(cppVar_17594);
	cppVar_17596 = (cppVar_17595 >> 7) & cppMask_un_1_;
	cppVar_17597 = (cppVar_17596 == 1);
	if (cppVar_17597) {
	cppVar_17598 = PC + 1;
	cppVar_17598 = (cppVar_17598 & cppMask_un_16_);
	cppVar_17599 = ROM.rd(cppVar_17598);
	cppVar_17600 = (cppVar_17599 >> 3) & cppMask_un_5_;
	cppVar_17601 = (cppVar_17600 << 3) | 0;
	cppVar_17601 = (cppVar_17601 & cppMask_un_8_);
	cppVar_17593 = cppVar_17601;
	} else {
	cppVar_17602 = PC + 1;
	cppVar_17602 = (cppVar_17602 & cppMask_un_16_);
	cppVar_17603 = ROM.rd(cppVar_17602);
	cppVar_17604 = (cppVar_17603 >> 3) & cppMask_un_5_;
	cppVar_17605 = (cppVar_17604 & cppMask_un_5_);
	cppVar_17606 = cppVar_17605 + 32;
	cppVar_17606 = (cppVar_17606 & cppMask_un_8_);
	cppVar_17593 = cppVar_17606;
	}
	cppVar_17608 = (cppVar_17593 == 137);
	if (cppVar_17608) {
	cppVar_17592 = TMOD;
	} else {
	cppVar_17611 = PC + 1;
	cppVar_17611 = (cppVar_17611 & cppMask_un_16_);
	cppVar_17612 = ROM.rd(cppVar_17611);
	cppVar_17613 = (cppVar_17612 >> 7) & cppMask_un_1_;
	cppVar_17614 = (cppVar_17613 == 1);
	if (cppVar_17614) {
	cppVar_17615 = PC + 1;
	cppVar_17615 = (cppVar_17615 & cppMask_un_16_);
	cppVar_17616 = ROM.rd(cppVar_17615);
	cppVar_17617 = (cppVar_17616 >> 3) & cppMask_un_5_;
	cppVar_17618 = (cppVar_17617 << 3) | 0;
	cppVar_17618 = (cppVar_17618 & cppMask_un_8_);
	cppVar_17610 = cppVar_17618;
	} else {
	cppVar_17619 = PC + 1;
	cppVar_17619 = (cppVar_17619 & cppMask_un_16_);
	cppVar_17620 = ROM.rd(cppVar_17619);
	cppVar_17621 = (cppVar_17620 >> 3) & cppMask_un_5_;
	cppVar_17622 = (cppVar_17621 & cppMask_un_5_);
	cppVar_17623 = cppVar_17622 + 32;
	cppVar_17623 = (cppVar_17623 & cppMask_un_8_);
	cppVar_17610 = cppVar_17623;
	}
	cppVar_17625 = (cppVar_17610 == 138);
	if (cppVar_17625) {
	cppVar_17609 = TL0;
	} else {
	cppVar_17628 = PC + 1;
	cppVar_17628 = (cppVar_17628 & cppMask_un_16_);
	cppVar_17629 = ROM.rd(cppVar_17628);
	cppVar_17630 = (cppVar_17629 >> 7) & cppMask_un_1_;
	cppVar_17631 = (cppVar_17630 == 1);
	if (cppVar_17631) {
	cppVar_17632 = PC + 1;
	cppVar_17632 = (cppVar_17632 & cppMask_un_16_);
	cppVar_17633 = ROM.rd(cppVar_17632);
	cppVar_17634 = (cppVar_17633 >> 3) & cppMask_un_5_;
	cppVar_17635 = (cppVar_17634 << 3) | 0;
	cppVar_17635 = (cppVar_17635 & cppMask_un_8_);
	cppVar_17627 = cppVar_17635;
	} else {
	cppVar_17636 = PC + 1;
	cppVar_17636 = (cppVar_17636 & cppMask_un_16_);
	cppVar_17637 = ROM.rd(cppVar_17636);
	cppVar_17638 = (cppVar_17637 >> 3) & cppMask_un_5_;
	cppVar_17639 = (cppVar_17638 & cppMask_un_5_);
	cppVar_17640 = cppVar_17639 + 32;
	cppVar_17640 = (cppVar_17640 & cppMask_un_8_);
	cppVar_17627 = cppVar_17640;
	}
	cppVar_17642 = (cppVar_17627 == 140);
	if (cppVar_17642) {
	cppVar_17626 = TH0;
	} else {
	cppVar_17645 = PC + 1;
	cppVar_17645 = (cppVar_17645 & cppMask_un_16_);
	cppVar_17646 = ROM.rd(cppVar_17645);
	cppVar_17647 = (cppVar_17646 >> 7) & cppMask_un_1_;
	cppVar_17648 = (cppVar_17647 == 1);
	if (cppVar_17648) {
	cppVar_17649 = PC + 1;
	cppVar_17649 = (cppVar_17649 & cppMask_un_16_);
	cppVar_17650 = ROM.rd(cppVar_17649);
	cppVar_17651 = (cppVar_17650 >> 3) & cppMask_un_5_;
	cppVar_17652 = (cppVar_17651 << 3) | 0;
	cppVar_17652 = (cppVar_17652 & cppMask_un_8_);
	cppVar_17644 = cppVar_17652;
	} else {
	cppVar_17653 = PC + 1;
	cppVar_17653 = (cppVar_17653 & cppMask_un_16_);
	cppVar_17654 = ROM.rd(cppVar_17653);
	cppVar_17655 = (cppVar_17654 >> 3) & cppMask_un_5_;
	cppVar_17656 = (cppVar_17655 & cppMask_un_5_);
	cppVar_17657 = cppVar_17656 + 32;
	cppVar_17657 = (cppVar_17657 & cppMask_un_8_);
	cppVar_17644 = cppVar_17657;
	}
	cppVar_17659 = (cppVar_17644 == 139);
	if (cppVar_17659) {
	cppVar_17643 = TL1;
	} else {
	cppVar_17662 = PC + 1;
	cppVar_17662 = (cppVar_17662 & cppMask_un_16_);
	cppVar_17663 = ROM.rd(cppVar_17662);
	cppVar_17664 = (cppVar_17663 >> 7) & cppMask_un_1_;
	cppVar_17665 = (cppVar_17664 == 1);
	if (cppVar_17665) {
	cppVar_17666 = PC + 1;
	cppVar_17666 = (cppVar_17666 & cppMask_un_16_);
	cppVar_17667 = ROM.rd(cppVar_17666);
	cppVar_17668 = (cppVar_17667 >> 3) & cppMask_un_5_;
	cppVar_17669 = (cppVar_17668 << 3) | 0;
	cppVar_17669 = (cppVar_17669 & cppMask_un_8_);
	cppVar_17661 = cppVar_17669;
	} else {
	cppVar_17670 = PC + 1;
	cppVar_17670 = (cppVar_17670 & cppMask_un_16_);
	cppVar_17671 = ROM.rd(cppVar_17670);
	cppVar_17672 = (cppVar_17671 >> 3) & cppMask_un_5_;
	cppVar_17673 = (cppVar_17672 & cppMask_un_5_);
	cppVar_17674 = cppVar_17673 + 32;
	cppVar_17674 = (cppVar_17674 & cppMask_un_8_);
	cppVar_17661 = cppVar_17674;
	}
	cppVar_17676 = (cppVar_17661 == 141);
	if (cppVar_17676) {
	cppVar_17660 = TH1;
	} else {
	cppVar_17679 = PC + 1;
	cppVar_17679 = (cppVar_17679 & cppMask_un_16_);
	cppVar_17680 = ROM.rd(cppVar_17679);
	cppVar_17681 = (cppVar_17680 >> 7) & cppMask_un_1_;
	cppVar_17682 = (cppVar_17681 == 1);
	if (cppVar_17682) {
	cppVar_17683 = PC + 1;
	cppVar_17683 = (cppVar_17683 & cppMask_un_16_);
	cppVar_17684 = ROM.rd(cppVar_17683);
	cppVar_17685 = (cppVar_17684 >> 3) & cppMask_un_5_;
	cppVar_17686 = (cppVar_17685 << 3) | 0;
	cppVar_17686 = (cppVar_17686 & cppMask_un_8_);
	cppVar_17678 = cppVar_17686;
	} else {
	cppVar_17687 = PC + 1;
	cppVar_17687 = (cppVar_17687 & cppMask_un_16_);
	cppVar_17688 = ROM.rd(cppVar_17687);
	cppVar_17689 = (cppVar_17688 >> 3) & cppMask_un_5_;
	cppVar_17690 = (cppVar_17689 & cppMask_un_5_);
	cppVar_17691 = cppVar_17690 + 32;
	cppVar_17691 = (cppVar_17691 & cppMask_un_8_);
	cppVar_17678 = cppVar_17691;
	}
	cppVar_17693 = (cppVar_17678 == 144);
	if (cppVar_17693) {
	cppVar_17677 = P1;
	} else {
	cppVar_17696 = PC + 1;
	cppVar_17696 = (cppVar_17696 & cppMask_un_16_);
	cppVar_17697 = ROM.rd(cppVar_17696);
	cppVar_17698 = (cppVar_17697 >> 7) & cppMask_un_1_;
	cppVar_17699 = (cppVar_17698 == 1);
	if (cppVar_17699) {
	cppVar_17700 = PC + 1;
	cppVar_17700 = (cppVar_17700 & cppMask_un_16_);
	cppVar_17701 = ROM.rd(cppVar_17700);
	cppVar_17702 = (cppVar_17701 >> 3) & cppMask_un_5_;
	cppVar_17703 = (cppVar_17702 << 3) | 0;
	cppVar_17703 = (cppVar_17703 & cppMask_un_8_);
	cppVar_17695 = cppVar_17703;
	} else {
	cppVar_17704 = PC + 1;
	cppVar_17704 = (cppVar_17704 & cppMask_un_16_);
	cppVar_17705 = ROM.rd(cppVar_17704);
	cppVar_17706 = (cppVar_17705 >> 3) & cppMask_un_5_;
	cppVar_17707 = (cppVar_17706 & cppMask_un_5_);
	cppVar_17708 = cppVar_17707 + 32;
	cppVar_17708 = (cppVar_17708 & cppMask_un_8_);
	cppVar_17695 = cppVar_17708;
	}
	cppVar_17710 = (cppVar_17695 == 152);
	if (cppVar_17710) {
	cppVar_17694 = SCON;
	} else {
	cppVar_17713 = PC + 1;
	cppVar_17713 = (cppVar_17713 & cppMask_un_16_);
	cppVar_17714 = ROM.rd(cppVar_17713);
	cppVar_17715 = (cppVar_17714 >> 7) & cppMask_un_1_;
	cppVar_17716 = (cppVar_17715 == 1);
	if (cppVar_17716) {
	cppVar_17717 = PC + 1;
	cppVar_17717 = (cppVar_17717 & cppMask_un_16_);
	cppVar_17718 = ROM.rd(cppVar_17717);
	cppVar_17719 = (cppVar_17718 >> 3) & cppMask_un_5_;
	cppVar_17720 = (cppVar_17719 << 3) | 0;
	cppVar_17720 = (cppVar_17720 & cppMask_un_8_);
	cppVar_17712 = cppVar_17720;
	} else {
	cppVar_17721 = PC + 1;
	cppVar_17721 = (cppVar_17721 & cppMask_un_16_);
	cppVar_17722 = ROM.rd(cppVar_17721);
	cppVar_17723 = (cppVar_17722 >> 3) & cppMask_un_5_;
	cppVar_17724 = (cppVar_17723 & cppMask_un_5_);
	cppVar_17725 = cppVar_17724 + 32;
	cppVar_17725 = (cppVar_17725 & cppMask_un_8_);
	cppVar_17712 = cppVar_17725;
	}
	cppVar_17727 = (cppVar_17712 == 153);
	if (cppVar_17727) {
	cppVar_17711 = SBUF;
	} else {
	cppVar_17730 = PC + 1;
	cppVar_17730 = (cppVar_17730 & cppMask_un_16_);
	cppVar_17731 = ROM.rd(cppVar_17730);
	cppVar_17732 = (cppVar_17731 >> 7) & cppMask_un_1_;
	cppVar_17733 = (cppVar_17732 == 1);
	if (cppVar_17733) {
	cppVar_17734 = PC + 1;
	cppVar_17734 = (cppVar_17734 & cppMask_un_16_);
	cppVar_17735 = ROM.rd(cppVar_17734);
	cppVar_17736 = (cppVar_17735 >> 3) & cppMask_un_5_;
	cppVar_17737 = (cppVar_17736 << 3) | 0;
	cppVar_17737 = (cppVar_17737 & cppMask_un_8_);
	cppVar_17729 = cppVar_17737;
	} else {
	cppVar_17738 = PC + 1;
	cppVar_17738 = (cppVar_17738 & cppMask_un_16_);
	cppVar_17739 = ROM.rd(cppVar_17738);
	cppVar_17740 = (cppVar_17739 >> 3) & cppMask_un_5_;
	cppVar_17741 = (cppVar_17740 & cppMask_un_5_);
	cppVar_17742 = cppVar_17741 + 32;
	cppVar_17742 = (cppVar_17742 & cppMask_un_8_);
	cppVar_17729 = cppVar_17742;
	}
	cppVar_17744 = (cppVar_17729 == 160);
	if (cppVar_17744) {
	cppVar_17728 = P2;
	} else {
	cppVar_17747 = PC + 1;
	cppVar_17747 = (cppVar_17747 & cppMask_un_16_);
	cppVar_17748 = ROM.rd(cppVar_17747);
	cppVar_17749 = (cppVar_17748 >> 7) & cppMask_un_1_;
	cppVar_17750 = (cppVar_17749 == 1);
	if (cppVar_17750) {
	cppVar_17751 = PC + 1;
	cppVar_17751 = (cppVar_17751 & cppMask_un_16_);
	cppVar_17752 = ROM.rd(cppVar_17751);
	cppVar_17753 = (cppVar_17752 >> 3) & cppMask_un_5_;
	cppVar_17754 = (cppVar_17753 << 3) | 0;
	cppVar_17754 = (cppVar_17754 & cppMask_un_8_);
	cppVar_17746 = cppVar_17754;
	} else {
	cppVar_17755 = PC + 1;
	cppVar_17755 = (cppVar_17755 & cppMask_un_16_);
	cppVar_17756 = ROM.rd(cppVar_17755);
	cppVar_17757 = (cppVar_17756 >> 3) & cppMask_un_5_;
	cppVar_17758 = (cppVar_17757 & cppMask_un_5_);
	cppVar_17759 = cppVar_17758 + 32;
	cppVar_17759 = (cppVar_17759 & cppMask_un_8_);
	cppVar_17746 = cppVar_17759;
	}
	cppVar_17761 = (cppVar_17746 == 168);
	if (cppVar_17761) {
	cppVar_17745 = IE;
	} else {
	cppVar_17764 = PC + 1;
	cppVar_17764 = (cppVar_17764 & cppMask_un_16_);
	cppVar_17765 = ROM.rd(cppVar_17764);
	cppVar_17766 = (cppVar_17765 >> 7) & cppMask_un_1_;
	cppVar_17767 = (cppVar_17766 == 1);
	if (cppVar_17767) {
	cppVar_17768 = PC + 1;
	cppVar_17768 = (cppVar_17768 & cppMask_un_16_);
	cppVar_17769 = ROM.rd(cppVar_17768);
	cppVar_17770 = (cppVar_17769 >> 3) & cppMask_un_5_;
	cppVar_17771 = (cppVar_17770 << 3) | 0;
	cppVar_17771 = (cppVar_17771 & cppMask_un_8_);
	cppVar_17763 = cppVar_17771;
	} else {
	cppVar_17772 = PC + 1;
	cppVar_17772 = (cppVar_17772 & cppMask_un_16_);
	cppVar_17773 = ROM.rd(cppVar_17772);
	cppVar_17774 = (cppVar_17773 >> 3) & cppMask_un_5_;
	cppVar_17775 = (cppVar_17774 & cppMask_un_5_);
	cppVar_17776 = cppVar_17775 + 32;
	cppVar_17776 = (cppVar_17776 & cppMask_un_8_);
	cppVar_17763 = cppVar_17776;
	}
	cppVar_17778 = (cppVar_17763 == 176);
	if (cppVar_17778) {
	cppVar_17762 = P3;
	} else {
	cppVar_17781 = PC + 1;
	cppVar_17781 = (cppVar_17781 & cppMask_un_16_);
	cppVar_17782 = ROM.rd(cppVar_17781);
	cppVar_17783 = (cppVar_17782 >> 7) & cppMask_un_1_;
	cppVar_17784 = (cppVar_17783 == 1);
	if (cppVar_17784) {
	cppVar_17785 = PC + 1;
	cppVar_17785 = (cppVar_17785 & cppMask_un_16_);
	cppVar_17786 = ROM.rd(cppVar_17785);
	cppVar_17787 = (cppVar_17786 >> 3) & cppMask_un_5_;
	cppVar_17788 = (cppVar_17787 << 3) | 0;
	cppVar_17788 = (cppVar_17788 & cppMask_un_8_);
	cppVar_17780 = cppVar_17788;
	} else {
	cppVar_17789 = PC + 1;
	cppVar_17789 = (cppVar_17789 & cppMask_un_16_);
	cppVar_17790 = ROM.rd(cppVar_17789);
	cppVar_17791 = (cppVar_17790 >> 3) & cppMask_un_5_;
	cppVar_17792 = (cppVar_17791 & cppMask_un_5_);
	cppVar_17793 = cppVar_17792 + 32;
	cppVar_17793 = (cppVar_17793 & cppMask_un_8_);
	cppVar_17780 = cppVar_17793;
	}
	cppVar_17795 = (cppVar_17780 == 184);
	if (cppVar_17795) {
	cppVar_17779 = IP;
	} else {
	cppVar_17798 = PC + 1;
	cppVar_17798 = (cppVar_17798 & cppMask_un_16_);
	cppVar_17799 = ROM.rd(cppVar_17798);
	cppVar_17800 = (cppVar_17799 >> 7) & cppMask_un_1_;
	cppVar_17801 = (cppVar_17800 == 1);
	if (cppVar_17801) {
	cppVar_17802 = PC + 1;
	cppVar_17802 = (cppVar_17802 & cppMask_un_16_);
	cppVar_17803 = ROM.rd(cppVar_17802);
	cppVar_17804 = (cppVar_17803 >> 3) & cppMask_un_5_;
	cppVar_17805 = (cppVar_17804 << 3) | 0;
	cppVar_17805 = (cppVar_17805 & cppMask_un_8_);
	cppVar_17797 = cppVar_17805;
	} else {
	cppVar_17806 = PC + 1;
	cppVar_17806 = (cppVar_17806 & cppMask_un_16_);
	cppVar_17807 = ROM.rd(cppVar_17806);
	cppVar_17808 = (cppVar_17807 >> 3) & cppMask_un_5_;
	cppVar_17809 = (cppVar_17808 & cppMask_un_5_);
	cppVar_17810 = cppVar_17809 + 32;
	cppVar_17810 = (cppVar_17810 & cppMask_un_8_);
	cppVar_17797 = cppVar_17810;
	}
	cppVar_17812 = (cppVar_17797 == 208);
	if (cppVar_17812) {
	cppVar_17796 = PSW;
	} else {
	cppVar_17815 = PC + 1;
	cppVar_17815 = (cppVar_17815 & cppMask_un_16_);
	cppVar_17816 = ROM.rd(cppVar_17815);
	cppVar_17817 = (cppVar_17816 >> 7) & cppMask_un_1_;
	cppVar_17818 = (cppVar_17817 == 1);
	if (cppVar_17818) {
	cppVar_17819 = PC + 1;
	cppVar_17819 = (cppVar_17819 & cppMask_un_16_);
	cppVar_17820 = ROM.rd(cppVar_17819);
	cppVar_17821 = (cppVar_17820 >> 3) & cppMask_un_5_;
	cppVar_17822 = (cppVar_17821 << 3) | 0;
	cppVar_17822 = (cppVar_17822 & cppMask_un_8_);
	cppVar_17814 = cppVar_17822;
	} else {
	cppVar_17823 = PC + 1;
	cppVar_17823 = (cppVar_17823 & cppMask_un_16_);
	cppVar_17824 = ROM.rd(cppVar_17823);
	cppVar_17825 = (cppVar_17824 >> 3) & cppMask_un_5_;
	cppVar_17826 = (cppVar_17825 & cppMask_un_5_);
	cppVar_17827 = cppVar_17826 + 32;
	cppVar_17827 = (cppVar_17827 & cppMask_un_8_);
	cppVar_17814 = cppVar_17827;
	}
	cppVar_17829 = (cppVar_17814 == 224);
	if (cppVar_17829) {
	cppVar_17813 = ACC;
	} else {
	cppVar_17832 = PC + 1;
	cppVar_17832 = (cppVar_17832 & cppMask_un_16_);
	cppVar_17833 = ROM.rd(cppVar_17832);
	cppVar_17834 = (cppVar_17833 >> 7) & cppMask_un_1_;
	cppVar_17835 = (cppVar_17834 == 1);
	if (cppVar_17835) {
	cppVar_17836 = PC + 1;
	cppVar_17836 = (cppVar_17836 & cppMask_un_16_);
	cppVar_17837 = ROM.rd(cppVar_17836);
	cppVar_17838 = (cppVar_17837 >> 3) & cppMask_un_5_;
	cppVar_17839 = (cppVar_17838 << 3) | 0;
	cppVar_17839 = (cppVar_17839 & cppMask_un_8_);
	cppVar_17831 = cppVar_17839;
	} else {
	cppVar_17840 = PC + 1;
	cppVar_17840 = (cppVar_17840 & cppMask_un_16_);
	cppVar_17841 = ROM.rd(cppVar_17840);
	cppVar_17842 = (cppVar_17841 >> 3) & cppMask_un_5_;
	cppVar_17843 = (cppVar_17842 & cppMask_un_5_);
	cppVar_17844 = cppVar_17843 + 32;
	cppVar_17844 = (cppVar_17844 & cppMask_un_8_);
	cppVar_17831 = cppVar_17844;
	}
	cppVar_17846 = (cppVar_17831 == 240);
	if (cppVar_17846) {
	cppVar_17830 = B;
	} else {
	cppVar_17830 = 0;
	}
	cppVar_17813 = cppVar_17830;
	}
	cppVar_17796 = cppVar_17813;
	}
	cppVar_17779 = cppVar_17796;
	}
	cppVar_17762 = cppVar_17779;
	}
	cppVar_17745 = cppVar_17762;
	}
	cppVar_17728 = cppVar_17745;
	}
	cppVar_17711 = cppVar_17728;
	}
	cppVar_17694 = cppVar_17711;
	}
	cppVar_17677 = cppVar_17694;
	}
	cppVar_17660 = cppVar_17677;
	}
	cppVar_17643 = cppVar_17660;
	}
	cppVar_17626 = cppVar_17643;
	}
	cppVar_17609 = cppVar_17626;
	}
	cppVar_17592 = cppVar_17609;
	}
	cppVar_17575 = cppVar_17592;
	}
	cppVar_17558 = cppVar_17575;
	}
	cppVar_17541 = cppVar_17558;
	}
	cppVar_17524 = cppVar_17541;
	}
	cppVar_17507 = cppVar_17524;
	}
	cppVar_17490 = cppVar_17507;
	}
	cppVar_17457 = cppVar_17490;
	}
	cppVar_17848 = cppVar_17456 & cppVar_17457;
	cppVar_17850 = 0;
	cppVar_17851 = PC + 1;
	cppVar_17851 = (cppVar_17851 & cppMask_un_16_);
	cppVar_17852 = ROM.rd(cppVar_17851);
	cppVar_17853 = (cppVar_17852 >> 0) & cppMask_un_3_;
	cppVar_17854 = (cppVar_17853 & cppMask_un_3_);
	cppVar_17855 = cppVar_17850 << static_cast<unsigned>(cppVar_17854);
	cppVar_17855 = (cppVar_17855 & cppMask_un_8_);
	cppVar_17856 = cppVar_17848 | cppVar_17855;
	cppVar_17429 = cppVar_17856;
	} else {
	cppVar_17429 = IE;
	}
	cppVar_17421 = cppVar_17429;
	} else {
	cppVar_17858 = ROM.rd(PC);
	cppVar_17860 = (cppVar_17858 == 5);
	if (cppVar_17860) {
	cppVar_17863 = PC + 1;
	cppVar_17863 = (cppVar_17863 & cppMask_un_16_);
	cppVar_17864 = ROM.rd(cppVar_17863);
	cppVar_17866 = (cppVar_17864 == 168);
	if (cppVar_17866) {
	cppVar_17868 = PC + 1;
	cppVar_17868 = (cppVar_17868 & cppMask_un_16_);
	cppVar_17869 = ROM.rd(cppVar_17868);
	cppVar_17870 = (cppVar_17869 >> 7) & cppMask_un_1_;
	cppVar_17872 = (cppVar_17870 == 0);
	if (cppVar_17872) {
	cppVar_17873 = PC + 1;
	cppVar_17873 = (cppVar_17873 & cppMask_un_16_);
	cppVar_17874 = ROM.rd(cppVar_17873);
	cppVar_17875 = IRAM.rd(cppVar_17874);
	cppVar_17867 = cppVar_17875;
	} else {
	cppVar_17877 = PC + 1;
	cppVar_17877 = (cppVar_17877 & cppMask_un_16_);
	cppVar_17878 = ROM.rd(cppVar_17877);
	cppVar_17880 = (cppVar_17878 == 128);
	if (cppVar_17880) {
	cppVar_17876 = P0;
	} else {
	cppVar_17882 = PC + 1;
	cppVar_17882 = (cppVar_17882 & cppMask_un_16_);
	cppVar_17883 = ROM.rd(cppVar_17882);
	cppVar_17885 = (cppVar_17883 == 129);
	if (cppVar_17885) {
	cppVar_17881 = SP;
	} else {
	cppVar_17887 = PC + 1;
	cppVar_17887 = (cppVar_17887 & cppMask_un_16_);
	cppVar_17888 = ROM.rd(cppVar_17887);
	cppVar_17890 = (cppVar_17888 == 130);
	if (cppVar_17890) {
	cppVar_17886 = DPL;
	} else {
	cppVar_17892 = PC + 1;
	cppVar_17892 = (cppVar_17892 & cppMask_un_16_);
	cppVar_17893 = ROM.rd(cppVar_17892);
	cppVar_17895 = (cppVar_17893 == 131);
	if (cppVar_17895) {
	cppVar_17891 = DPH;
	} else {
	cppVar_17897 = PC + 1;
	cppVar_17897 = (cppVar_17897 & cppMask_un_16_);
	cppVar_17898 = ROM.rd(cppVar_17897);
	cppVar_17900 = (cppVar_17898 == 135);
	if (cppVar_17900) {
	cppVar_17896 = PCON;
	} else {
	cppVar_17902 = PC + 1;
	cppVar_17902 = (cppVar_17902 & cppMask_un_16_);
	cppVar_17903 = ROM.rd(cppVar_17902);
	cppVar_17905 = (cppVar_17903 == 136);
	if (cppVar_17905) {
	cppVar_17901 = TCON;
	} else {
	cppVar_17907 = PC + 1;
	cppVar_17907 = (cppVar_17907 & cppMask_un_16_);
	cppVar_17908 = ROM.rd(cppVar_17907);
	cppVar_17910 = (cppVar_17908 == 137);
	if (cppVar_17910) {
	cppVar_17906 = TMOD;
	} else {
	cppVar_17912 = PC + 1;
	cppVar_17912 = (cppVar_17912 & cppMask_un_16_);
	cppVar_17913 = ROM.rd(cppVar_17912);
	cppVar_17915 = (cppVar_17913 == 138);
	if (cppVar_17915) {
	cppVar_17911 = TL0;
	} else {
	cppVar_17917 = PC + 1;
	cppVar_17917 = (cppVar_17917 & cppMask_un_16_);
	cppVar_17918 = ROM.rd(cppVar_17917);
	cppVar_17920 = (cppVar_17918 == 140);
	if (cppVar_17920) {
	cppVar_17916 = TH0;
	} else {
	cppVar_17922 = PC + 1;
	cppVar_17922 = (cppVar_17922 & cppMask_un_16_);
	cppVar_17923 = ROM.rd(cppVar_17922);
	cppVar_17925 = (cppVar_17923 == 139);
	if (cppVar_17925) {
	cppVar_17921 = TL1;
	} else {
	cppVar_17927 = PC + 1;
	cppVar_17927 = (cppVar_17927 & cppMask_un_16_);
	cppVar_17928 = ROM.rd(cppVar_17927);
	cppVar_17930 = (cppVar_17928 == 141);
	if (cppVar_17930) {
	cppVar_17926 = TH1;
	} else {
	cppVar_17932 = PC + 1;
	cppVar_17932 = (cppVar_17932 & cppMask_un_16_);
	cppVar_17933 = ROM.rd(cppVar_17932);
	cppVar_17935 = (cppVar_17933 == 144);
	if (cppVar_17935) {
	cppVar_17931 = P1;
	} else {
	cppVar_17937 = PC + 1;
	cppVar_17937 = (cppVar_17937 & cppMask_un_16_);
	cppVar_17938 = ROM.rd(cppVar_17937);
	cppVar_17940 = (cppVar_17938 == 152);
	if (cppVar_17940) {
	cppVar_17936 = SCON;
	} else {
	cppVar_17942 = PC + 1;
	cppVar_17942 = (cppVar_17942 & cppMask_un_16_);
	cppVar_17943 = ROM.rd(cppVar_17942);
	cppVar_17945 = (cppVar_17943 == 153);
	if (cppVar_17945) {
	cppVar_17941 = SBUF;
	} else {
	cppVar_17947 = PC + 1;
	cppVar_17947 = (cppVar_17947 & cppMask_un_16_);
	cppVar_17948 = ROM.rd(cppVar_17947);
	cppVar_17950 = (cppVar_17948 == 160);
	if (cppVar_17950) {
	cppVar_17946 = P2;
	} else {
	cppVar_17952 = PC + 1;
	cppVar_17952 = (cppVar_17952 & cppMask_un_16_);
	cppVar_17953 = ROM.rd(cppVar_17952);
	cppVar_17955 = (cppVar_17953 == 168);
	if (cppVar_17955) {
	cppVar_17951 = IE;
	} else {
	cppVar_17957 = PC + 1;
	cppVar_17957 = (cppVar_17957 & cppMask_un_16_);
	cppVar_17958 = ROM.rd(cppVar_17957);
	cppVar_17960 = (cppVar_17958 == 176);
	if (cppVar_17960) {
	cppVar_17956 = P3;
	} else {
	cppVar_17962 = PC + 1;
	cppVar_17962 = (cppVar_17962 & cppMask_un_16_);
	cppVar_17963 = ROM.rd(cppVar_17962);
	cppVar_17965 = (cppVar_17963 == 184);
	if (cppVar_17965) {
	cppVar_17961 = IP;
	} else {
	cppVar_17967 = PC + 1;
	cppVar_17967 = (cppVar_17967 & cppMask_un_16_);
	cppVar_17968 = ROM.rd(cppVar_17967);
	cppVar_17970 = (cppVar_17968 == 208);
	if (cppVar_17970) {
	cppVar_17966 = PSW;
	} else {
	cppVar_17972 = PC + 1;
	cppVar_17972 = (cppVar_17972 & cppMask_un_16_);
	cppVar_17973 = ROM.rd(cppVar_17972);
	cppVar_17975 = (cppVar_17973 == 224);
	if (cppVar_17975) {
	cppVar_17971 = ACC;
	} else {
	cppVar_17977 = PC + 1;
	cppVar_17977 = (cppVar_17977 & cppMask_un_16_);
	cppVar_17978 = ROM.rd(cppVar_17977);
	cppVar_17980 = (cppVar_17978 == 240);
	if (cppVar_17980) {
	cppVar_17976 = B;
	} else {
	cppVar_17976 = 0;
	}
	cppVar_17971 = cppVar_17976;
	}
	cppVar_17966 = cppVar_17971;
	}
	cppVar_17961 = cppVar_17966;
	}
	cppVar_17956 = cppVar_17961;
	}
	cppVar_17951 = cppVar_17956;
	}
	cppVar_17946 = cppVar_17951;
	}
	cppVar_17941 = cppVar_17946;
	}
	cppVar_17936 = cppVar_17941;
	}
	cppVar_17931 = cppVar_17936;
	}
	cppVar_17926 = cppVar_17931;
	}
	cppVar_17921 = cppVar_17926;
	}
	cppVar_17916 = cppVar_17921;
	}
	cppVar_17911 = cppVar_17916;
	}
	cppVar_17906 = cppVar_17911;
	}
	cppVar_17901 = cppVar_17906;
	}
	cppVar_17896 = cppVar_17901;
	}
	cppVar_17891 = cppVar_17896;
	}
	cppVar_17886 = cppVar_17891;
	}
	cppVar_17881 = cppVar_17886;
	}
	cppVar_17876 = cppVar_17881;
	}
	cppVar_17867 = cppVar_17876;
	}
	cppVar_17983 = cppVar_17867 + 1;
	cppVar_17983 = (cppVar_17983 & cppMask_un_8_);
	cppVar_17861 = cppVar_17983;
	} else {
	cppVar_17861 = IE;
	}
	cppVar_17857 = cppVar_17861;
	} else {
	cppVar_17857 = IE;
	}
	cppVar_17421 = cppVar_17857;
	}
	cppVar_17290 = cppVar_17421;
	}
	cppVar_17164 = cppVar_17290;
	}
	cppVar_17035 = cppVar_17164;
	}
	cppVar_16909 = cppVar_17035;
	}
	cppVar_16780 = cppVar_16909;
	}
	cppVar_16654 = cppVar_16780;
	}
	cppVar_16525 = cppVar_16654;
	}
	cppVar_16512 = cppVar_16525;
	}
	cppVar_16386 = cppVar_16512;
	}
	cppVar_16369 = cppVar_16386;
	}
	cppVar_16352 = cppVar_16369;
	}
	cppVar_16202 = cppVar_16352;
	}
	cppVar_16052 = cppVar_16202;
	}
	cppVar_15902 = cppVar_16052;
	}
	cppVar_15752 = cppVar_15902;
	}
	cppVar_15602 = cppVar_15752;
	}
	cppVar_15452 = cppVar_15602;
	}
	cppVar_15302 = cppVar_15452;
	}
	cppVar_15152 = cppVar_15302;
	}
	cppVar_14720 = cppVar_15152;
	}
	cppVar_13890 = cppVar_14720;
	}
	cppVar_13876 = cppVar_13890;
	}
	cppVar_13865 = cppVar_13876;
	}
	cppVar_13433 = cppVar_13865;
	}
	return cppVar_13433;
}
