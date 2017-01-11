#include "common.hpp"
#include "model_oc8051_class.hpp"

BIT_VEC model_oc8051::cppUpdateFun_PSW()
{
	BIT_VEC cppVar_46696;
	BIT_VEC cppVar_46697;
	bool cppVar_46698;
	BIT_VEC cppVar_46701;
	BIT_VEC cppVar_46702;
	bool cppVar_46703;
	BIT_VEC cppVar_46704;
	BIT_VEC cppVar_46705;
	bool cppVar_46706;
	bool cppVar_46707;
	BIT_VEC cppVar_46708;
	BIT_VEC cppVar_46709;
	BIT_VEC cppVar_46710;
	BIT_VEC cppVar_46711;
	BIT_VEC cppVar_46700;
	BIT_VEC cppVar_46712;
	BIT_VEC cppVar_46713;
	BIT_VEC cppVar_46714;
	BIT_VEC cppVar_46715;
	bool cppVar_46716;
	BIT_VEC cppVar_46718;
	bool cppVar_46719;
	BIT_VEC cppVar_46720;
	bool cppVar_46721;
	bool cppVar_46722;
	BIT_VEC cppVar_46723;
	BIT_VEC cppVar_46724;
	BIT_VEC cppVar_46725;
	BIT_VEC cppVar_46717;
	BIT_VEC cppVar_46726;
	BIT_VEC cppVar_46727;
	bool cppVar_46728;
	bool cppVar_46729;
	BIT_VEC cppVar_46731;
	bool cppVar_46732;
	BIT_VEC cppVar_46733;
	bool cppVar_46734;
	bool cppVar_46735;
	BIT_VEC cppVar_46736;
	BIT_VEC cppVar_46737;
	BIT_VEC cppVar_46738;
	BIT_VEC cppVar_46730;
	BIT_VEC cppVar_46739;
	BIT_VEC cppVar_46740;
	BIT_VEC cppVar_46742;
	bool cppVar_46743;
	BIT_VEC cppVar_46744;
	bool cppVar_46745;
	bool cppVar_46746;
	BIT_VEC cppVar_46747;
	BIT_VEC cppVar_46748;
	BIT_VEC cppVar_46749;
	BIT_VEC cppVar_46741;
	BIT_VEC cppVar_46699;
	BIT_VEC cppVar_46750;
	BIT_VEC cppVar_46752;
	bool cppVar_46753;
	BIT_VEC cppVar_46754;
	bool cppVar_46755;
	bool cppVar_46756;
	BIT_VEC cppVar_46757;
	BIT_VEC cppVar_46758;
	BIT_VEC cppVar_46759;
	BIT_VEC cppVar_46751;
	BIT_VEC cppVar_46760;
	BIT_VEC cppVar_46761;
	BIT_VEC cppVar_46762;
	BIT_VEC cppVar_46763;
	BIT_VEC cppVar_46764;
	BIT_VEC cppVar_46765;
	BIT_VEC cppVar_46767;
	BIT_VEC cppVar_46768;
	bool cppVar_46769;
	BIT_VEC cppVar_46770;
	BIT_VEC cppVar_46771;
	BIT_VEC cppVar_46772;
	BIT_VEC cppVar_46774;
	BIT_VEC cppVar_46775;
	bool cppVar_46776;
	BIT_VEC cppVar_46779;
	BIT_VEC cppVar_46780;
	BIT_VEC cppVar_46781;
	BIT_VEC cppVar_46782;
	BIT_VEC cppVar_46783;
	bool cppVar_46784;
	BIT_VEC cppVar_46785;
	BIT_VEC cppVar_46786;
	BIT_VEC cppVar_46787;
	BIT_VEC cppVar_46788;
	BIT_VEC cppVar_46789;
	BIT_VEC cppVar_46790;
	BIT_VEC cppVar_46791;
	BIT_VEC cppVar_46792;
	BIT_VEC cppVar_46793;
	BIT_VEC cppVar_46794;
	BIT_VEC cppVar_46795;
	BIT_VEC cppVar_46778;
	BIT_VEC cppVar_46796;
	bool cppVar_46797;
	BIT_VEC cppVar_46798;
	BIT_VEC cppVar_46799;
	BIT_VEC cppVar_46800;
	BIT_VEC cppVar_46801;
	BIT_VEC cppVar_46802;
	BIT_VEC cppVar_46803;
	BIT_VEC cppVar_46804;
	BIT_VEC cppVar_46807;
	BIT_VEC cppVar_46808;
	BIT_VEC cppVar_46809;
	bool cppVar_46810;
	BIT_VEC cppVar_46811;
	BIT_VEC cppVar_46812;
	BIT_VEC cppVar_46813;
	BIT_VEC cppVar_46814;
	BIT_VEC cppVar_46815;
	BIT_VEC cppVar_46816;
	BIT_VEC cppVar_46817;
	BIT_VEC cppVar_46818;
	BIT_VEC cppVar_46819;
	BIT_VEC cppVar_46806;
	BIT_VEC cppVar_46820;
	BIT_VEC cppVar_46821;
	bool cppVar_46822;
	BIT_VEC cppVar_46824;
	BIT_VEC cppVar_46825;
	BIT_VEC cppVar_46826;
	bool cppVar_46827;
	BIT_VEC cppVar_46828;
	BIT_VEC cppVar_46829;
	BIT_VEC cppVar_46830;
	BIT_VEC cppVar_46831;
	BIT_VEC cppVar_46832;
	BIT_VEC cppVar_46833;
	BIT_VEC cppVar_46834;
	BIT_VEC cppVar_46835;
	BIT_VEC cppVar_46836;
	BIT_VEC cppVar_46823;
	BIT_VEC cppVar_46837;
	BIT_VEC cppVar_46840;
	BIT_VEC cppVar_46841;
	BIT_VEC cppVar_46842;
	bool cppVar_46843;
	BIT_VEC cppVar_46844;
	BIT_VEC cppVar_46845;
	BIT_VEC cppVar_46846;
	BIT_VEC cppVar_46847;
	BIT_VEC cppVar_46848;
	BIT_VEC cppVar_46849;
	BIT_VEC cppVar_46850;
	BIT_VEC cppVar_46851;
	BIT_VEC cppVar_46852;
	BIT_VEC cppVar_46839;
	BIT_VEC cppVar_46853;
	bool cppVar_46854;
	BIT_VEC cppVar_46857;
	BIT_VEC cppVar_46858;
	BIT_VEC cppVar_46859;
	bool cppVar_46860;
	BIT_VEC cppVar_46861;
	BIT_VEC cppVar_46862;
	BIT_VEC cppVar_46863;
	BIT_VEC cppVar_46864;
	BIT_VEC cppVar_46865;
	BIT_VEC cppVar_46866;
	BIT_VEC cppVar_46867;
	BIT_VEC cppVar_46868;
	BIT_VEC cppVar_46869;
	BIT_VEC cppVar_46856;
	BIT_VEC cppVar_46870;
	bool cppVar_46871;
	BIT_VEC cppVar_46874;
	BIT_VEC cppVar_46875;
	BIT_VEC cppVar_46876;
	bool cppVar_46877;
	BIT_VEC cppVar_46878;
	BIT_VEC cppVar_46879;
	BIT_VEC cppVar_46880;
	BIT_VEC cppVar_46881;
	BIT_VEC cppVar_46882;
	BIT_VEC cppVar_46883;
	BIT_VEC cppVar_46884;
	BIT_VEC cppVar_46885;
	BIT_VEC cppVar_46886;
	BIT_VEC cppVar_46873;
	BIT_VEC cppVar_46887;
	bool cppVar_46888;
	BIT_VEC cppVar_46891;
	BIT_VEC cppVar_46892;
	BIT_VEC cppVar_46893;
	bool cppVar_46894;
	BIT_VEC cppVar_46895;
	BIT_VEC cppVar_46896;
	BIT_VEC cppVar_46897;
	BIT_VEC cppVar_46898;
	BIT_VEC cppVar_46899;
	BIT_VEC cppVar_46900;
	BIT_VEC cppVar_46901;
	BIT_VEC cppVar_46902;
	BIT_VEC cppVar_46903;
	BIT_VEC cppVar_46890;
	BIT_VEC cppVar_46904;
	bool cppVar_46905;
	BIT_VEC cppVar_46908;
	BIT_VEC cppVar_46909;
	BIT_VEC cppVar_46910;
	bool cppVar_46911;
	BIT_VEC cppVar_46912;
	BIT_VEC cppVar_46913;
	BIT_VEC cppVar_46914;
	BIT_VEC cppVar_46915;
	BIT_VEC cppVar_46916;
	BIT_VEC cppVar_46917;
	BIT_VEC cppVar_46918;
	BIT_VEC cppVar_46919;
	BIT_VEC cppVar_46920;
	BIT_VEC cppVar_46907;
	BIT_VEC cppVar_46921;
	bool cppVar_46922;
	BIT_VEC cppVar_46925;
	BIT_VEC cppVar_46926;
	BIT_VEC cppVar_46927;
	bool cppVar_46928;
	BIT_VEC cppVar_46929;
	BIT_VEC cppVar_46930;
	BIT_VEC cppVar_46931;
	BIT_VEC cppVar_46932;
	BIT_VEC cppVar_46933;
	BIT_VEC cppVar_46934;
	BIT_VEC cppVar_46935;
	BIT_VEC cppVar_46936;
	BIT_VEC cppVar_46937;
	BIT_VEC cppVar_46924;
	BIT_VEC cppVar_46938;
	bool cppVar_46939;
	BIT_VEC cppVar_46942;
	BIT_VEC cppVar_46943;
	BIT_VEC cppVar_46944;
	bool cppVar_46945;
	BIT_VEC cppVar_46946;
	BIT_VEC cppVar_46947;
	BIT_VEC cppVar_46948;
	BIT_VEC cppVar_46949;
	BIT_VEC cppVar_46950;
	BIT_VEC cppVar_46951;
	BIT_VEC cppVar_46952;
	BIT_VEC cppVar_46953;
	BIT_VEC cppVar_46954;
	BIT_VEC cppVar_46941;
	BIT_VEC cppVar_46955;
	bool cppVar_46956;
	BIT_VEC cppVar_46959;
	BIT_VEC cppVar_46960;
	BIT_VEC cppVar_46961;
	bool cppVar_46962;
	BIT_VEC cppVar_46963;
	BIT_VEC cppVar_46964;
	BIT_VEC cppVar_46965;
	BIT_VEC cppVar_46966;
	BIT_VEC cppVar_46967;
	BIT_VEC cppVar_46968;
	BIT_VEC cppVar_46969;
	BIT_VEC cppVar_46970;
	BIT_VEC cppVar_46971;
	BIT_VEC cppVar_46958;
	BIT_VEC cppVar_46972;
	bool cppVar_46973;
	BIT_VEC cppVar_46976;
	BIT_VEC cppVar_46977;
	BIT_VEC cppVar_46978;
	bool cppVar_46979;
	BIT_VEC cppVar_46980;
	BIT_VEC cppVar_46981;
	BIT_VEC cppVar_46982;
	BIT_VEC cppVar_46983;
	BIT_VEC cppVar_46984;
	BIT_VEC cppVar_46985;
	BIT_VEC cppVar_46986;
	BIT_VEC cppVar_46987;
	BIT_VEC cppVar_46988;
	BIT_VEC cppVar_46975;
	BIT_VEC cppVar_46989;
	bool cppVar_46990;
	BIT_VEC cppVar_46993;
	BIT_VEC cppVar_46994;
	BIT_VEC cppVar_46995;
	bool cppVar_46996;
	BIT_VEC cppVar_46997;
	BIT_VEC cppVar_46998;
	BIT_VEC cppVar_46999;
	BIT_VEC cppVar_47000;
	BIT_VEC cppVar_47001;
	BIT_VEC cppVar_47002;
	BIT_VEC cppVar_47003;
	BIT_VEC cppVar_47004;
	BIT_VEC cppVar_47005;
	BIT_VEC cppVar_46992;
	BIT_VEC cppVar_47006;
	bool cppVar_47007;
	BIT_VEC cppVar_47010;
	BIT_VEC cppVar_47011;
	BIT_VEC cppVar_47012;
	bool cppVar_47013;
	BIT_VEC cppVar_47014;
	BIT_VEC cppVar_47015;
	BIT_VEC cppVar_47016;
	BIT_VEC cppVar_47017;
	BIT_VEC cppVar_47018;
	BIT_VEC cppVar_47019;
	BIT_VEC cppVar_47020;
	BIT_VEC cppVar_47021;
	BIT_VEC cppVar_47022;
	BIT_VEC cppVar_47009;
	BIT_VEC cppVar_47023;
	bool cppVar_47024;
	BIT_VEC cppVar_47027;
	BIT_VEC cppVar_47028;
	BIT_VEC cppVar_47029;
	bool cppVar_47030;
	BIT_VEC cppVar_47031;
	BIT_VEC cppVar_47032;
	BIT_VEC cppVar_47033;
	BIT_VEC cppVar_47034;
	BIT_VEC cppVar_47035;
	BIT_VEC cppVar_47036;
	BIT_VEC cppVar_47037;
	BIT_VEC cppVar_47038;
	BIT_VEC cppVar_47039;
	BIT_VEC cppVar_47026;
	BIT_VEC cppVar_47040;
	bool cppVar_47041;
	BIT_VEC cppVar_47044;
	BIT_VEC cppVar_47045;
	BIT_VEC cppVar_47046;
	bool cppVar_47047;
	BIT_VEC cppVar_47048;
	BIT_VEC cppVar_47049;
	BIT_VEC cppVar_47050;
	BIT_VEC cppVar_47051;
	BIT_VEC cppVar_47052;
	BIT_VEC cppVar_47053;
	BIT_VEC cppVar_47054;
	BIT_VEC cppVar_47055;
	BIT_VEC cppVar_47056;
	BIT_VEC cppVar_47043;
	BIT_VEC cppVar_47057;
	bool cppVar_47058;
	BIT_VEC cppVar_47061;
	BIT_VEC cppVar_47062;
	BIT_VEC cppVar_47063;
	bool cppVar_47064;
	BIT_VEC cppVar_47065;
	BIT_VEC cppVar_47066;
	BIT_VEC cppVar_47067;
	BIT_VEC cppVar_47068;
	BIT_VEC cppVar_47069;
	BIT_VEC cppVar_47070;
	BIT_VEC cppVar_47071;
	BIT_VEC cppVar_47072;
	BIT_VEC cppVar_47073;
	BIT_VEC cppVar_47060;
	BIT_VEC cppVar_47074;
	bool cppVar_47075;
	BIT_VEC cppVar_47078;
	BIT_VEC cppVar_47079;
	BIT_VEC cppVar_47080;
	bool cppVar_47081;
	BIT_VEC cppVar_47082;
	BIT_VEC cppVar_47083;
	BIT_VEC cppVar_47084;
	BIT_VEC cppVar_47085;
	BIT_VEC cppVar_47086;
	BIT_VEC cppVar_47087;
	BIT_VEC cppVar_47088;
	BIT_VEC cppVar_47089;
	BIT_VEC cppVar_47090;
	BIT_VEC cppVar_47077;
	BIT_VEC cppVar_47091;
	bool cppVar_47092;
	BIT_VEC cppVar_47095;
	BIT_VEC cppVar_47096;
	BIT_VEC cppVar_47097;
	bool cppVar_47098;
	BIT_VEC cppVar_47099;
	BIT_VEC cppVar_47100;
	BIT_VEC cppVar_47101;
	BIT_VEC cppVar_47102;
	BIT_VEC cppVar_47103;
	BIT_VEC cppVar_47104;
	BIT_VEC cppVar_47105;
	BIT_VEC cppVar_47106;
	BIT_VEC cppVar_47107;
	BIT_VEC cppVar_47094;
	BIT_VEC cppVar_47108;
	bool cppVar_47109;
	BIT_VEC cppVar_47112;
	BIT_VEC cppVar_47113;
	BIT_VEC cppVar_47114;
	bool cppVar_47115;
	BIT_VEC cppVar_47116;
	BIT_VEC cppVar_47117;
	BIT_VEC cppVar_47118;
	BIT_VEC cppVar_47119;
	BIT_VEC cppVar_47120;
	BIT_VEC cppVar_47121;
	BIT_VEC cppVar_47122;
	BIT_VEC cppVar_47123;
	BIT_VEC cppVar_47124;
	BIT_VEC cppVar_47111;
	BIT_VEC cppVar_47125;
	bool cppVar_47126;
	BIT_VEC cppVar_47129;
	BIT_VEC cppVar_47130;
	BIT_VEC cppVar_47131;
	bool cppVar_47132;
	BIT_VEC cppVar_47133;
	BIT_VEC cppVar_47134;
	BIT_VEC cppVar_47135;
	BIT_VEC cppVar_47136;
	BIT_VEC cppVar_47137;
	BIT_VEC cppVar_47138;
	BIT_VEC cppVar_47139;
	BIT_VEC cppVar_47140;
	BIT_VEC cppVar_47141;
	BIT_VEC cppVar_47128;
	BIT_VEC cppVar_47142;
	bool cppVar_47143;
	BIT_VEC cppVar_47146;
	BIT_VEC cppVar_47147;
	BIT_VEC cppVar_47148;
	bool cppVar_47149;
	BIT_VEC cppVar_47150;
	BIT_VEC cppVar_47151;
	BIT_VEC cppVar_47152;
	BIT_VEC cppVar_47153;
	BIT_VEC cppVar_47154;
	BIT_VEC cppVar_47155;
	BIT_VEC cppVar_47156;
	BIT_VEC cppVar_47157;
	BIT_VEC cppVar_47158;
	BIT_VEC cppVar_47145;
	BIT_VEC cppVar_47159;
	bool cppVar_47160;
	BIT_VEC cppVar_47163;
	BIT_VEC cppVar_47164;
	BIT_VEC cppVar_47165;
	bool cppVar_47166;
	BIT_VEC cppVar_47167;
	BIT_VEC cppVar_47168;
	BIT_VEC cppVar_47169;
	BIT_VEC cppVar_47170;
	BIT_VEC cppVar_47171;
	BIT_VEC cppVar_47172;
	BIT_VEC cppVar_47173;
	BIT_VEC cppVar_47174;
	BIT_VEC cppVar_47175;
	BIT_VEC cppVar_47162;
	BIT_VEC cppVar_47176;
	bool cppVar_47177;
	BIT_VEC cppVar_47180;
	BIT_VEC cppVar_47181;
	BIT_VEC cppVar_47182;
	bool cppVar_47183;
	BIT_VEC cppVar_47184;
	BIT_VEC cppVar_47185;
	BIT_VEC cppVar_47186;
	BIT_VEC cppVar_47187;
	BIT_VEC cppVar_47188;
	BIT_VEC cppVar_47189;
	BIT_VEC cppVar_47190;
	BIT_VEC cppVar_47191;
	BIT_VEC cppVar_47192;
	BIT_VEC cppVar_47179;
	BIT_VEC cppVar_47193;
	bool cppVar_47194;
	BIT_VEC cppVar_47195;
	BIT_VEC cppVar_47178;
	BIT_VEC cppVar_47161;
	BIT_VEC cppVar_47144;
	BIT_VEC cppVar_47127;
	BIT_VEC cppVar_47110;
	BIT_VEC cppVar_47093;
	BIT_VEC cppVar_47076;
	BIT_VEC cppVar_47059;
	BIT_VEC cppVar_47042;
	BIT_VEC cppVar_47025;
	BIT_VEC cppVar_47008;
	BIT_VEC cppVar_46991;
	BIT_VEC cppVar_46974;
	BIT_VEC cppVar_46957;
	BIT_VEC cppVar_46940;
	BIT_VEC cppVar_46923;
	BIT_VEC cppVar_46906;
	BIT_VEC cppVar_46889;
	BIT_VEC cppVar_46872;
	BIT_VEC cppVar_46855;
	BIT_VEC cppVar_46838;
	BIT_VEC cppVar_46805;
	BIT_VEC cppVar_47196;
	BIT_VEC cppVar_47197;
	BIT_VEC cppVar_47198;
	BIT_VEC cppVar_47199;
	BIT_VEC cppVar_47200;
	BIT_VEC cppVar_47201;
	BIT_VEC cppVar_47202;
	BIT_VEC cppVar_47203;
	BIT_VEC cppVar_47204;
	BIT_VEC cppVar_46777;
	BIT_VEC cppVar_47206;
	BIT_VEC cppVar_47207;
	bool cppVar_47208;
	BIT_VEC cppVar_47210;
	BIT_VEC cppVar_47211;
	BIT_VEC cppVar_47212;
	BIT_VEC cppVar_47213;
	bool cppVar_47214;
	BIT_VEC cppVar_47215;
	BIT_VEC cppVar_47209;
	BIT_VEC cppVar_47217;
	BIT_VEC cppVar_47218;
	bool cppVar_47219;
	BIT_VEC cppVar_47220;
	BIT_VEC cppVar_47221;
	bool cppVar_47222;
	bool cppVar_47223;
	BIT_VEC cppVar_47225;
	BIT_VEC cppVar_47226;
	BIT_VEC cppVar_47227;
	BIT_VEC cppVar_47228;
	bool cppVar_47229;
	BIT_VEC cppVar_47224;
	BIT_VEC cppVar_47231;
	BIT_VEC cppVar_47232;
	bool cppVar_47233;
	BIT_VEC cppVar_47234;
	BIT_VEC cppVar_47235;
	BIT_VEC cppVar_47236;
	BIT_VEC cppVar_47238;
	BIT_VEC cppVar_47239;
	bool cppVar_47240;
	BIT_VEC cppVar_47242;
	BIT_VEC cppVar_47243;
	BIT_VEC cppVar_47244;
	BIT_VEC cppVar_47245;
	BIT_VEC cppVar_47246;
	BIT_VEC cppVar_47247;
	BIT_VEC cppVar_47248;
	BIT_VEC cppVar_47249;
	BIT_VEC cppVar_47250;
	bool cppVar_47251;
	BIT_VEC cppVar_47252;
	BIT_VEC cppVar_47253;
	BIT_VEC cppVar_47241;
	BIT_VEC cppVar_47254;
	BIT_VEC cppVar_47255;
	BIT_VEC cppVar_47257;
	BIT_VEC cppVar_47258;
	bool cppVar_47259;
	BIT_VEC cppVar_47261;
	BIT_VEC cppVar_47262;
	BIT_VEC cppVar_47263;
	BIT_VEC cppVar_47264;
	BIT_VEC cppVar_47265;
	BIT_VEC cppVar_47266;
	BIT_VEC cppVar_47267;
	BIT_VEC cppVar_47268;
	BIT_VEC cppVar_47269;
	bool cppVar_47270;
	BIT_VEC cppVar_47271;
	BIT_VEC cppVar_47272;
	BIT_VEC cppVar_47260;
	BIT_VEC cppVar_47273;
	BIT_VEC cppVar_47274;
	BIT_VEC cppVar_47276;
	BIT_VEC cppVar_47277;
	bool cppVar_47278;
	BIT_VEC cppVar_47280;
	BIT_VEC cppVar_47281;
	BIT_VEC cppVar_47282;
	BIT_VEC cppVar_47283;
	BIT_VEC cppVar_47284;
	BIT_VEC cppVar_47285;
	BIT_VEC cppVar_47286;
	BIT_VEC cppVar_47287;
	BIT_VEC cppVar_47288;
	bool cppVar_47289;
	BIT_VEC cppVar_47290;
	BIT_VEC cppVar_47291;
	BIT_VEC cppVar_47279;
	BIT_VEC cppVar_47292;
	BIT_VEC cppVar_47293;
	BIT_VEC cppVar_47295;
	BIT_VEC cppVar_47296;
	bool cppVar_47297;
	BIT_VEC cppVar_47299;
	BIT_VEC cppVar_47300;
	BIT_VEC cppVar_47301;
	BIT_VEC cppVar_47302;
	BIT_VEC cppVar_47303;
	BIT_VEC cppVar_47304;
	BIT_VEC cppVar_47305;
	BIT_VEC cppVar_47306;
	BIT_VEC cppVar_47307;
	bool cppVar_47308;
	BIT_VEC cppVar_47309;
	BIT_VEC cppVar_47310;
	BIT_VEC cppVar_47298;
	BIT_VEC cppVar_47311;
	BIT_VEC cppVar_47312;
	BIT_VEC cppVar_47314;
	BIT_VEC cppVar_47315;
	bool cppVar_47316;
	BIT_VEC cppVar_47318;
	BIT_VEC cppVar_47319;
	BIT_VEC cppVar_47320;
	BIT_VEC cppVar_47321;
	BIT_VEC cppVar_47322;
	BIT_VEC cppVar_47323;
	BIT_VEC cppVar_47324;
	BIT_VEC cppVar_47325;
	BIT_VEC cppVar_47326;
	bool cppVar_47327;
	BIT_VEC cppVar_47328;
	BIT_VEC cppVar_47329;
	BIT_VEC cppVar_47317;
	BIT_VEC cppVar_47330;
	BIT_VEC cppVar_47331;
	BIT_VEC cppVar_47333;
	BIT_VEC cppVar_47334;
	bool cppVar_47335;
	BIT_VEC cppVar_47337;
	BIT_VEC cppVar_47338;
	BIT_VEC cppVar_47339;
	BIT_VEC cppVar_47340;
	BIT_VEC cppVar_47341;
	BIT_VEC cppVar_47342;
	BIT_VEC cppVar_47343;
	BIT_VEC cppVar_47344;
	BIT_VEC cppVar_47345;
	bool cppVar_47346;
	BIT_VEC cppVar_47347;
	BIT_VEC cppVar_47348;
	BIT_VEC cppVar_47336;
	BIT_VEC cppVar_47349;
	BIT_VEC cppVar_47350;
	BIT_VEC cppVar_47352;
	BIT_VEC cppVar_47353;
	bool cppVar_47354;
	BIT_VEC cppVar_47356;
	BIT_VEC cppVar_47357;
	BIT_VEC cppVar_47358;
	BIT_VEC cppVar_47359;
	BIT_VEC cppVar_47360;
	BIT_VEC cppVar_47361;
	BIT_VEC cppVar_47362;
	BIT_VEC cppVar_47363;
	BIT_VEC cppVar_47364;
	bool cppVar_47365;
	BIT_VEC cppVar_47366;
	BIT_VEC cppVar_47367;
	BIT_VEC cppVar_47355;
	BIT_VEC cppVar_47368;
	BIT_VEC cppVar_47369;
	BIT_VEC cppVar_47371;
	BIT_VEC cppVar_47372;
	bool cppVar_47373;
	BIT_VEC cppVar_47375;
	BIT_VEC cppVar_47376;
	BIT_VEC cppVar_47377;
	BIT_VEC cppVar_47378;
	BIT_VEC cppVar_47379;
	BIT_VEC cppVar_47380;
	BIT_VEC cppVar_47381;
	BIT_VEC cppVar_47382;
	BIT_VEC cppVar_47383;
	bool cppVar_47384;
	BIT_VEC cppVar_47385;
	BIT_VEC cppVar_47386;
	BIT_VEC cppVar_47374;
	BIT_VEC cppVar_47387;
	BIT_VEC cppVar_47388;
	BIT_VEC cppVar_47390;
	BIT_VEC cppVar_47391;
	bool cppVar_47392;
	BIT_VEC cppVar_47394;
	BIT_VEC cppVar_47395;
	BIT_VEC cppVar_47396;
	BIT_VEC cppVar_47397;
	BIT_VEC cppVar_47398;
	BIT_VEC cppVar_47399;
	BIT_VEC cppVar_47400;
	BIT_VEC cppVar_47401;
	BIT_VEC cppVar_47402;
	BIT_VEC cppVar_47403;
	bool cppVar_47404;
	BIT_VEC cppVar_47405;
	BIT_VEC cppVar_47406;
	BIT_VEC cppVar_47393;
	BIT_VEC cppVar_47407;
	BIT_VEC cppVar_47408;
	BIT_VEC cppVar_47410;
	BIT_VEC cppVar_47411;
	bool cppVar_47412;
	BIT_VEC cppVar_47414;
	BIT_VEC cppVar_47415;
	BIT_VEC cppVar_47416;
	BIT_VEC cppVar_47417;
	BIT_VEC cppVar_47418;
	BIT_VEC cppVar_47419;
	BIT_VEC cppVar_47420;
	BIT_VEC cppVar_47421;
	BIT_VEC cppVar_47422;
	BIT_VEC cppVar_47423;
	bool cppVar_47424;
	BIT_VEC cppVar_47425;
	BIT_VEC cppVar_47426;
	BIT_VEC cppVar_47413;
	BIT_VEC cppVar_47427;
	BIT_VEC cppVar_47428;
	BIT_VEC cppVar_47430;
	BIT_VEC cppVar_47431;
	bool cppVar_47432;
	BIT_VEC cppVar_47435;
	BIT_VEC cppVar_47436;
	BIT_VEC cppVar_47437;
	BIT_VEC cppVar_47438;
	BIT_VEC cppVar_47439;
	bool cppVar_47440;
	BIT_VEC cppVar_47441;
	BIT_VEC cppVar_47442;
	BIT_VEC cppVar_47443;
	BIT_VEC cppVar_47445;
	BIT_VEC cppVar_47446;
	BIT_VEC cppVar_47447;
	bool cppVar_47448;
	BIT_VEC cppVar_47450;
	BIT_VEC cppVar_47451;
	BIT_VEC cppVar_47452;
	bool cppVar_47453;
	BIT_VEC cppVar_47455;
	BIT_VEC cppVar_47456;
	BIT_VEC cppVar_47457;
	bool cppVar_47458;
	BIT_VEC cppVar_47460;
	BIT_VEC cppVar_47461;
	BIT_VEC cppVar_47462;
	bool cppVar_47463;
	BIT_VEC cppVar_47465;
	BIT_VEC cppVar_47466;
	BIT_VEC cppVar_47467;
	bool cppVar_47468;
	BIT_VEC cppVar_47470;
	BIT_VEC cppVar_47471;
	BIT_VEC cppVar_47472;
	bool cppVar_47473;
	BIT_VEC cppVar_47475;
	BIT_VEC cppVar_47476;
	BIT_VEC cppVar_47477;
	bool cppVar_47478;
	BIT_VEC cppVar_47480;
	BIT_VEC cppVar_47481;
	BIT_VEC cppVar_47482;
	bool cppVar_47483;
	BIT_VEC cppVar_47485;
	BIT_VEC cppVar_47486;
	BIT_VEC cppVar_47487;
	bool cppVar_47488;
	BIT_VEC cppVar_47490;
	BIT_VEC cppVar_47491;
	BIT_VEC cppVar_47492;
	bool cppVar_47493;
	BIT_VEC cppVar_47495;
	BIT_VEC cppVar_47496;
	BIT_VEC cppVar_47497;
	bool cppVar_47498;
	BIT_VEC cppVar_47500;
	BIT_VEC cppVar_47501;
	BIT_VEC cppVar_47502;
	bool cppVar_47503;
	BIT_VEC cppVar_47505;
	BIT_VEC cppVar_47506;
	BIT_VEC cppVar_47507;
	bool cppVar_47508;
	BIT_VEC cppVar_47510;
	BIT_VEC cppVar_47511;
	BIT_VEC cppVar_47512;
	bool cppVar_47513;
	BIT_VEC cppVar_47515;
	BIT_VEC cppVar_47516;
	BIT_VEC cppVar_47517;
	bool cppVar_47518;
	BIT_VEC cppVar_47520;
	BIT_VEC cppVar_47521;
	BIT_VEC cppVar_47522;
	bool cppVar_47523;
	BIT_VEC cppVar_47525;
	BIT_VEC cppVar_47526;
	BIT_VEC cppVar_47527;
	bool cppVar_47528;
	BIT_VEC cppVar_47530;
	BIT_VEC cppVar_47531;
	BIT_VEC cppVar_47532;
	bool cppVar_47533;
	BIT_VEC cppVar_47535;
	BIT_VEC cppVar_47536;
	BIT_VEC cppVar_47537;
	bool cppVar_47538;
	BIT_VEC cppVar_47540;
	BIT_VEC cppVar_47541;
	BIT_VEC cppVar_47542;
	bool cppVar_47543;
	BIT_VEC cppVar_47545;
	BIT_VEC cppVar_47546;
	BIT_VEC cppVar_47547;
	bool cppVar_47548;
	BIT_VEC cppVar_47549;
	BIT_VEC cppVar_47544;
	BIT_VEC cppVar_47539;
	BIT_VEC cppVar_47534;
	BIT_VEC cppVar_47529;
	BIT_VEC cppVar_47524;
	BIT_VEC cppVar_47519;
	BIT_VEC cppVar_47514;
	BIT_VEC cppVar_47509;
	BIT_VEC cppVar_47504;
	BIT_VEC cppVar_47499;
	BIT_VEC cppVar_47494;
	BIT_VEC cppVar_47489;
	BIT_VEC cppVar_47484;
	BIT_VEC cppVar_47479;
	BIT_VEC cppVar_47474;
	BIT_VEC cppVar_47469;
	BIT_VEC cppVar_47464;
	BIT_VEC cppVar_47459;
	BIT_VEC cppVar_47454;
	BIT_VEC cppVar_47449;
	BIT_VEC cppVar_47444;
	BIT_VEC cppVar_47434;
	bool cppVar_47550;
	BIT_VEC cppVar_47551;
	BIT_VEC cppVar_47552;
	BIT_VEC cppVar_47433;
	BIT_VEC cppVar_47553;
	BIT_VEC cppVar_47554;
	BIT_VEC cppVar_47556;
	BIT_VEC cppVar_47557;
	bool cppVar_47558;
	BIT_VEC cppVar_47560;
	BIT_VEC cppVar_47561;
	BIT_VEC cppVar_47562;
	bool cppVar_47563;
	BIT_VEC cppVar_47564;
	BIT_VEC cppVar_47565;
	BIT_VEC cppVar_47559;
	BIT_VEC cppVar_47566;
	BIT_VEC cppVar_47567;
	BIT_VEC cppVar_47569;
	BIT_VEC cppVar_47570;
	bool cppVar_47571;
	BIT_VEC cppVar_47572;
	BIT_VEC cppVar_47573;
	BIT_VEC cppVar_47574;
	BIT_VEC cppVar_47575;
	BIT_VEC cppVar_47577;
	BIT_VEC cppVar_47578;
	bool cppVar_47579;
	BIT_VEC cppVar_47582;
	BIT_VEC cppVar_47583;
	BIT_VEC cppVar_47584;
	BIT_VEC cppVar_47585;
	BIT_VEC cppVar_47586;
	bool cppVar_47587;
	BIT_VEC cppVar_47588;
	BIT_VEC cppVar_47589;
	BIT_VEC cppVar_47590;
	BIT_VEC cppVar_47591;
	BIT_VEC cppVar_47592;
	BIT_VEC cppVar_47593;
	BIT_VEC cppVar_47594;
	BIT_VEC cppVar_47595;
	BIT_VEC cppVar_47596;
	BIT_VEC cppVar_47597;
	BIT_VEC cppVar_47598;
	BIT_VEC cppVar_47581;
	BIT_VEC cppVar_47599;
	bool cppVar_47600;
	BIT_VEC cppVar_47601;
	BIT_VEC cppVar_47602;
	BIT_VEC cppVar_47603;
	BIT_VEC cppVar_47604;
	BIT_VEC cppVar_47605;
	BIT_VEC cppVar_47606;
	BIT_VEC cppVar_47607;
	BIT_VEC cppVar_47610;
	BIT_VEC cppVar_47611;
	BIT_VEC cppVar_47612;
	bool cppVar_47613;
	BIT_VEC cppVar_47614;
	BIT_VEC cppVar_47615;
	BIT_VEC cppVar_47616;
	BIT_VEC cppVar_47617;
	BIT_VEC cppVar_47618;
	BIT_VEC cppVar_47619;
	BIT_VEC cppVar_47620;
	BIT_VEC cppVar_47621;
	BIT_VEC cppVar_47622;
	BIT_VEC cppVar_47609;
	BIT_VEC cppVar_47623;
	BIT_VEC cppVar_47624;
	bool cppVar_47625;
	BIT_VEC cppVar_47627;
	BIT_VEC cppVar_47628;
	BIT_VEC cppVar_47629;
	bool cppVar_47630;
	BIT_VEC cppVar_47631;
	BIT_VEC cppVar_47632;
	BIT_VEC cppVar_47633;
	BIT_VEC cppVar_47634;
	BIT_VEC cppVar_47635;
	BIT_VEC cppVar_47636;
	BIT_VEC cppVar_47637;
	BIT_VEC cppVar_47638;
	BIT_VEC cppVar_47639;
	BIT_VEC cppVar_47626;
	BIT_VEC cppVar_47640;
	BIT_VEC cppVar_47643;
	BIT_VEC cppVar_47644;
	BIT_VEC cppVar_47645;
	bool cppVar_47646;
	BIT_VEC cppVar_47647;
	BIT_VEC cppVar_47648;
	BIT_VEC cppVar_47649;
	BIT_VEC cppVar_47650;
	BIT_VEC cppVar_47651;
	BIT_VEC cppVar_47652;
	BIT_VEC cppVar_47653;
	BIT_VEC cppVar_47654;
	BIT_VEC cppVar_47655;
	BIT_VEC cppVar_47642;
	BIT_VEC cppVar_47656;
	bool cppVar_47657;
	BIT_VEC cppVar_47660;
	BIT_VEC cppVar_47661;
	BIT_VEC cppVar_47662;
	bool cppVar_47663;
	BIT_VEC cppVar_47664;
	BIT_VEC cppVar_47665;
	BIT_VEC cppVar_47666;
	BIT_VEC cppVar_47667;
	BIT_VEC cppVar_47668;
	BIT_VEC cppVar_47669;
	BIT_VEC cppVar_47670;
	BIT_VEC cppVar_47671;
	BIT_VEC cppVar_47672;
	BIT_VEC cppVar_47659;
	BIT_VEC cppVar_47673;
	bool cppVar_47674;
	BIT_VEC cppVar_47677;
	BIT_VEC cppVar_47678;
	BIT_VEC cppVar_47679;
	bool cppVar_47680;
	BIT_VEC cppVar_47681;
	BIT_VEC cppVar_47682;
	BIT_VEC cppVar_47683;
	BIT_VEC cppVar_47684;
	BIT_VEC cppVar_47685;
	BIT_VEC cppVar_47686;
	BIT_VEC cppVar_47687;
	BIT_VEC cppVar_47688;
	BIT_VEC cppVar_47689;
	BIT_VEC cppVar_47676;
	BIT_VEC cppVar_47690;
	bool cppVar_47691;
	BIT_VEC cppVar_47694;
	BIT_VEC cppVar_47695;
	BIT_VEC cppVar_47696;
	bool cppVar_47697;
	BIT_VEC cppVar_47698;
	BIT_VEC cppVar_47699;
	BIT_VEC cppVar_47700;
	BIT_VEC cppVar_47701;
	BIT_VEC cppVar_47702;
	BIT_VEC cppVar_47703;
	BIT_VEC cppVar_47704;
	BIT_VEC cppVar_47705;
	BIT_VEC cppVar_47706;
	BIT_VEC cppVar_47693;
	BIT_VEC cppVar_47707;
	bool cppVar_47708;
	BIT_VEC cppVar_47711;
	BIT_VEC cppVar_47712;
	BIT_VEC cppVar_47713;
	bool cppVar_47714;
	BIT_VEC cppVar_47715;
	BIT_VEC cppVar_47716;
	BIT_VEC cppVar_47717;
	BIT_VEC cppVar_47718;
	BIT_VEC cppVar_47719;
	BIT_VEC cppVar_47720;
	BIT_VEC cppVar_47721;
	BIT_VEC cppVar_47722;
	BIT_VEC cppVar_47723;
	BIT_VEC cppVar_47710;
	BIT_VEC cppVar_47724;
	bool cppVar_47725;
	BIT_VEC cppVar_47728;
	BIT_VEC cppVar_47729;
	BIT_VEC cppVar_47730;
	bool cppVar_47731;
	BIT_VEC cppVar_47732;
	BIT_VEC cppVar_47733;
	BIT_VEC cppVar_47734;
	BIT_VEC cppVar_47735;
	BIT_VEC cppVar_47736;
	BIT_VEC cppVar_47737;
	BIT_VEC cppVar_47738;
	BIT_VEC cppVar_47739;
	BIT_VEC cppVar_47740;
	BIT_VEC cppVar_47727;
	BIT_VEC cppVar_47741;
	bool cppVar_47742;
	BIT_VEC cppVar_47745;
	BIT_VEC cppVar_47746;
	BIT_VEC cppVar_47747;
	bool cppVar_47748;
	BIT_VEC cppVar_47749;
	BIT_VEC cppVar_47750;
	BIT_VEC cppVar_47751;
	BIT_VEC cppVar_47752;
	BIT_VEC cppVar_47753;
	BIT_VEC cppVar_47754;
	BIT_VEC cppVar_47755;
	BIT_VEC cppVar_47756;
	BIT_VEC cppVar_47757;
	BIT_VEC cppVar_47744;
	BIT_VEC cppVar_47758;
	bool cppVar_47759;
	BIT_VEC cppVar_47762;
	BIT_VEC cppVar_47763;
	BIT_VEC cppVar_47764;
	bool cppVar_47765;
	BIT_VEC cppVar_47766;
	BIT_VEC cppVar_47767;
	BIT_VEC cppVar_47768;
	BIT_VEC cppVar_47769;
	BIT_VEC cppVar_47770;
	BIT_VEC cppVar_47771;
	BIT_VEC cppVar_47772;
	BIT_VEC cppVar_47773;
	BIT_VEC cppVar_47774;
	BIT_VEC cppVar_47761;
	BIT_VEC cppVar_47775;
	bool cppVar_47776;
	BIT_VEC cppVar_47779;
	BIT_VEC cppVar_47780;
	BIT_VEC cppVar_47781;
	bool cppVar_47782;
	BIT_VEC cppVar_47783;
	BIT_VEC cppVar_47784;
	BIT_VEC cppVar_47785;
	BIT_VEC cppVar_47786;
	BIT_VEC cppVar_47787;
	BIT_VEC cppVar_47788;
	BIT_VEC cppVar_47789;
	BIT_VEC cppVar_47790;
	BIT_VEC cppVar_47791;
	BIT_VEC cppVar_47778;
	BIT_VEC cppVar_47792;
	bool cppVar_47793;
	BIT_VEC cppVar_47796;
	BIT_VEC cppVar_47797;
	BIT_VEC cppVar_47798;
	bool cppVar_47799;
	BIT_VEC cppVar_47800;
	BIT_VEC cppVar_47801;
	BIT_VEC cppVar_47802;
	BIT_VEC cppVar_47803;
	BIT_VEC cppVar_47804;
	BIT_VEC cppVar_47805;
	BIT_VEC cppVar_47806;
	BIT_VEC cppVar_47807;
	BIT_VEC cppVar_47808;
	BIT_VEC cppVar_47795;
	BIT_VEC cppVar_47809;
	bool cppVar_47810;
	BIT_VEC cppVar_47813;
	BIT_VEC cppVar_47814;
	BIT_VEC cppVar_47815;
	bool cppVar_47816;
	BIT_VEC cppVar_47817;
	BIT_VEC cppVar_47818;
	BIT_VEC cppVar_47819;
	BIT_VEC cppVar_47820;
	BIT_VEC cppVar_47821;
	BIT_VEC cppVar_47822;
	BIT_VEC cppVar_47823;
	BIT_VEC cppVar_47824;
	BIT_VEC cppVar_47825;
	BIT_VEC cppVar_47812;
	BIT_VEC cppVar_47826;
	bool cppVar_47827;
	BIT_VEC cppVar_47830;
	BIT_VEC cppVar_47831;
	BIT_VEC cppVar_47832;
	bool cppVar_47833;
	BIT_VEC cppVar_47834;
	BIT_VEC cppVar_47835;
	BIT_VEC cppVar_47836;
	BIT_VEC cppVar_47837;
	BIT_VEC cppVar_47838;
	BIT_VEC cppVar_47839;
	BIT_VEC cppVar_47840;
	BIT_VEC cppVar_47841;
	BIT_VEC cppVar_47842;
	BIT_VEC cppVar_47829;
	BIT_VEC cppVar_47843;
	bool cppVar_47844;
	BIT_VEC cppVar_47847;
	BIT_VEC cppVar_47848;
	BIT_VEC cppVar_47849;
	bool cppVar_47850;
	BIT_VEC cppVar_47851;
	BIT_VEC cppVar_47852;
	BIT_VEC cppVar_47853;
	BIT_VEC cppVar_47854;
	BIT_VEC cppVar_47855;
	BIT_VEC cppVar_47856;
	BIT_VEC cppVar_47857;
	BIT_VEC cppVar_47858;
	BIT_VEC cppVar_47859;
	BIT_VEC cppVar_47846;
	BIT_VEC cppVar_47860;
	bool cppVar_47861;
	BIT_VEC cppVar_47864;
	BIT_VEC cppVar_47865;
	BIT_VEC cppVar_47866;
	bool cppVar_47867;
	BIT_VEC cppVar_47868;
	BIT_VEC cppVar_47869;
	BIT_VEC cppVar_47870;
	BIT_VEC cppVar_47871;
	BIT_VEC cppVar_47872;
	BIT_VEC cppVar_47873;
	BIT_VEC cppVar_47874;
	BIT_VEC cppVar_47875;
	BIT_VEC cppVar_47876;
	BIT_VEC cppVar_47863;
	BIT_VEC cppVar_47877;
	bool cppVar_47878;
	BIT_VEC cppVar_47881;
	BIT_VEC cppVar_47882;
	BIT_VEC cppVar_47883;
	bool cppVar_47884;
	BIT_VEC cppVar_47885;
	BIT_VEC cppVar_47886;
	BIT_VEC cppVar_47887;
	BIT_VEC cppVar_47888;
	BIT_VEC cppVar_47889;
	BIT_VEC cppVar_47890;
	BIT_VEC cppVar_47891;
	BIT_VEC cppVar_47892;
	BIT_VEC cppVar_47893;
	BIT_VEC cppVar_47880;
	BIT_VEC cppVar_47894;
	bool cppVar_47895;
	BIT_VEC cppVar_47898;
	BIT_VEC cppVar_47899;
	BIT_VEC cppVar_47900;
	bool cppVar_47901;
	BIT_VEC cppVar_47902;
	BIT_VEC cppVar_47903;
	BIT_VEC cppVar_47904;
	BIT_VEC cppVar_47905;
	BIT_VEC cppVar_47906;
	BIT_VEC cppVar_47907;
	BIT_VEC cppVar_47908;
	BIT_VEC cppVar_47909;
	BIT_VEC cppVar_47910;
	BIT_VEC cppVar_47897;
	BIT_VEC cppVar_47911;
	bool cppVar_47912;
	BIT_VEC cppVar_47915;
	BIT_VEC cppVar_47916;
	BIT_VEC cppVar_47917;
	bool cppVar_47918;
	BIT_VEC cppVar_47919;
	BIT_VEC cppVar_47920;
	BIT_VEC cppVar_47921;
	BIT_VEC cppVar_47922;
	BIT_VEC cppVar_47923;
	BIT_VEC cppVar_47924;
	BIT_VEC cppVar_47925;
	BIT_VEC cppVar_47926;
	BIT_VEC cppVar_47927;
	BIT_VEC cppVar_47914;
	BIT_VEC cppVar_47928;
	bool cppVar_47929;
	BIT_VEC cppVar_47932;
	BIT_VEC cppVar_47933;
	BIT_VEC cppVar_47934;
	bool cppVar_47935;
	BIT_VEC cppVar_47936;
	BIT_VEC cppVar_47937;
	BIT_VEC cppVar_47938;
	BIT_VEC cppVar_47939;
	BIT_VEC cppVar_47940;
	BIT_VEC cppVar_47941;
	BIT_VEC cppVar_47942;
	BIT_VEC cppVar_47943;
	BIT_VEC cppVar_47944;
	BIT_VEC cppVar_47931;
	BIT_VEC cppVar_47945;
	bool cppVar_47946;
	BIT_VEC cppVar_47949;
	BIT_VEC cppVar_47950;
	BIT_VEC cppVar_47951;
	bool cppVar_47952;
	BIT_VEC cppVar_47953;
	BIT_VEC cppVar_47954;
	BIT_VEC cppVar_47955;
	BIT_VEC cppVar_47956;
	BIT_VEC cppVar_47957;
	BIT_VEC cppVar_47958;
	BIT_VEC cppVar_47959;
	BIT_VEC cppVar_47960;
	BIT_VEC cppVar_47961;
	BIT_VEC cppVar_47948;
	BIT_VEC cppVar_47962;
	bool cppVar_47963;
	BIT_VEC cppVar_47966;
	BIT_VEC cppVar_47967;
	BIT_VEC cppVar_47968;
	bool cppVar_47969;
	BIT_VEC cppVar_47970;
	BIT_VEC cppVar_47971;
	BIT_VEC cppVar_47972;
	BIT_VEC cppVar_47973;
	BIT_VEC cppVar_47974;
	BIT_VEC cppVar_47975;
	BIT_VEC cppVar_47976;
	BIT_VEC cppVar_47977;
	BIT_VEC cppVar_47978;
	BIT_VEC cppVar_47965;
	BIT_VEC cppVar_47979;
	bool cppVar_47980;
	BIT_VEC cppVar_47983;
	BIT_VEC cppVar_47984;
	BIT_VEC cppVar_47985;
	bool cppVar_47986;
	BIT_VEC cppVar_47987;
	BIT_VEC cppVar_47988;
	BIT_VEC cppVar_47989;
	BIT_VEC cppVar_47990;
	BIT_VEC cppVar_47991;
	BIT_VEC cppVar_47992;
	BIT_VEC cppVar_47993;
	BIT_VEC cppVar_47994;
	BIT_VEC cppVar_47995;
	BIT_VEC cppVar_47982;
	BIT_VEC cppVar_47996;
	bool cppVar_47997;
	BIT_VEC cppVar_47998;
	BIT_VEC cppVar_47981;
	BIT_VEC cppVar_47964;
	BIT_VEC cppVar_47947;
	BIT_VEC cppVar_47930;
	BIT_VEC cppVar_47913;
	BIT_VEC cppVar_47896;
	BIT_VEC cppVar_47879;
	BIT_VEC cppVar_47862;
	BIT_VEC cppVar_47845;
	BIT_VEC cppVar_47828;
	BIT_VEC cppVar_47811;
	BIT_VEC cppVar_47794;
	BIT_VEC cppVar_47777;
	BIT_VEC cppVar_47760;
	BIT_VEC cppVar_47743;
	BIT_VEC cppVar_47726;
	BIT_VEC cppVar_47709;
	BIT_VEC cppVar_47692;
	BIT_VEC cppVar_47675;
	BIT_VEC cppVar_47658;
	BIT_VEC cppVar_47641;
	BIT_VEC cppVar_47608;
	BIT_VEC cppVar_47999;
	BIT_VEC cppVar_48002;
	BIT_VEC cppVar_48003;
	BIT_VEC cppVar_48004;
	BIT_VEC cppVar_48005;
	bool cppVar_48006;
	BIT_VEC cppVar_48007;
	BIT_VEC cppVar_48008;
	BIT_VEC cppVar_48009;
	BIT_VEC cppVar_48010;
	BIT_VEC cppVar_48011;
	BIT_VEC cppVar_48012;
	BIT_VEC cppVar_48013;
	BIT_VEC cppVar_48014;
	BIT_VEC cppVar_48015;
	BIT_VEC cppVar_48016;
	BIT_VEC cppVar_48017;
	BIT_VEC cppVar_48001;
	BIT_VEC cppVar_48018;
	BIT_VEC cppVar_48019;
	bool cppVar_48020;
	BIT_VEC cppVar_48022;
	BIT_VEC cppVar_48023;
	BIT_VEC cppVar_48024;
	bool cppVar_48025;
	BIT_VEC cppVar_48026;
	BIT_VEC cppVar_48027;
	BIT_VEC cppVar_48028;
	BIT_VEC cppVar_48029;
	BIT_VEC cppVar_48030;
	BIT_VEC cppVar_48031;
	BIT_VEC cppVar_48032;
	BIT_VEC cppVar_48033;
	BIT_VEC cppVar_48034;
	BIT_VEC cppVar_48021;
	BIT_VEC cppVar_48035;
	BIT_VEC cppVar_48038;
	BIT_VEC cppVar_48039;
	BIT_VEC cppVar_48040;
	bool cppVar_48041;
	BIT_VEC cppVar_48042;
	BIT_VEC cppVar_48043;
	BIT_VEC cppVar_48044;
	BIT_VEC cppVar_48045;
	BIT_VEC cppVar_48046;
	BIT_VEC cppVar_48047;
	BIT_VEC cppVar_48048;
	BIT_VEC cppVar_48049;
	BIT_VEC cppVar_48050;
	BIT_VEC cppVar_48037;
	BIT_VEC cppVar_48051;
	bool cppVar_48052;
	BIT_VEC cppVar_48055;
	BIT_VEC cppVar_48056;
	BIT_VEC cppVar_48057;
	bool cppVar_48058;
	BIT_VEC cppVar_48059;
	BIT_VEC cppVar_48060;
	BIT_VEC cppVar_48061;
	BIT_VEC cppVar_48062;
	BIT_VEC cppVar_48063;
	BIT_VEC cppVar_48064;
	BIT_VEC cppVar_48065;
	BIT_VEC cppVar_48066;
	BIT_VEC cppVar_48067;
	BIT_VEC cppVar_48054;
	BIT_VEC cppVar_48068;
	bool cppVar_48069;
	BIT_VEC cppVar_48072;
	BIT_VEC cppVar_48073;
	BIT_VEC cppVar_48074;
	bool cppVar_48075;
	BIT_VEC cppVar_48076;
	BIT_VEC cppVar_48077;
	BIT_VEC cppVar_48078;
	BIT_VEC cppVar_48079;
	BIT_VEC cppVar_48080;
	BIT_VEC cppVar_48081;
	BIT_VEC cppVar_48082;
	BIT_VEC cppVar_48083;
	BIT_VEC cppVar_48084;
	BIT_VEC cppVar_48071;
	BIT_VEC cppVar_48085;
	bool cppVar_48086;
	BIT_VEC cppVar_48089;
	BIT_VEC cppVar_48090;
	BIT_VEC cppVar_48091;
	bool cppVar_48092;
	BIT_VEC cppVar_48093;
	BIT_VEC cppVar_48094;
	BIT_VEC cppVar_48095;
	BIT_VEC cppVar_48096;
	BIT_VEC cppVar_48097;
	BIT_VEC cppVar_48098;
	BIT_VEC cppVar_48099;
	BIT_VEC cppVar_48100;
	BIT_VEC cppVar_48101;
	BIT_VEC cppVar_48088;
	BIT_VEC cppVar_48102;
	bool cppVar_48103;
	BIT_VEC cppVar_48106;
	BIT_VEC cppVar_48107;
	BIT_VEC cppVar_48108;
	bool cppVar_48109;
	BIT_VEC cppVar_48110;
	BIT_VEC cppVar_48111;
	BIT_VEC cppVar_48112;
	BIT_VEC cppVar_48113;
	BIT_VEC cppVar_48114;
	BIT_VEC cppVar_48115;
	BIT_VEC cppVar_48116;
	BIT_VEC cppVar_48117;
	BIT_VEC cppVar_48118;
	BIT_VEC cppVar_48105;
	BIT_VEC cppVar_48119;
	bool cppVar_48120;
	BIT_VEC cppVar_48123;
	BIT_VEC cppVar_48124;
	BIT_VEC cppVar_48125;
	bool cppVar_48126;
	BIT_VEC cppVar_48127;
	BIT_VEC cppVar_48128;
	BIT_VEC cppVar_48129;
	BIT_VEC cppVar_48130;
	BIT_VEC cppVar_48131;
	BIT_VEC cppVar_48132;
	BIT_VEC cppVar_48133;
	BIT_VEC cppVar_48134;
	BIT_VEC cppVar_48135;
	BIT_VEC cppVar_48122;
	BIT_VEC cppVar_48136;
	bool cppVar_48137;
	BIT_VEC cppVar_48140;
	BIT_VEC cppVar_48141;
	BIT_VEC cppVar_48142;
	bool cppVar_48143;
	BIT_VEC cppVar_48144;
	BIT_VEC cppVar_48145;
	BIT_VEC cppVar_48146;
	BIT_VEC cppVar_48147;
	BIT_VEC cppVar_48148;
	BIT_VEC cppVar_48149;
	BIT_VEC cppVar_48150;
	BIT_VEC cppVar_48151;
	BIT_VEC cppVar_48152;
	BIT_VEC cppVar_48139;
	BIT_VEC cppVar_48153;
	bool cppVar_48154;
	BIT_VEC cppVar_48157;
	BIT_VEC cppVar_48158;
	BIT_VEC cppVar_48159;
	bool cppVar_48160;
	BIT_VEC cppVar_48161;
	BIT_VEC cppVar_48162;
	BIT_VEC cppVar_48163;
	BIT_VEC cppVar_48164;
	BIT_VEC cppVar_48165;
	BIT_VEC cppVar_48166;
	BIT_VEC cppVar_48167;
	BIT_VEC cppVar_48168;
	BIT_VEC cppVar_48169;
	BIT_VEC cppVar_48156;
	BIT_VEC cppVar_48170;
	bool cppVar_48171;
	BIT_VEC cppVar_48174;
	BIT_VEC cppVar_48175;
	BIT_VEC cppVar_48176;
	bool cppVar_48177;
	BIT_VEC cppVar_48178;
	BIT_VEC cppVar_48179;
	BIT_VEC cppVar_48180;
	BIT_VEC cppVar_48181;
	BIT_VEC cppVar_48182;
	BIT_VEC cppVar_48183;
	BIT_VEC cppVar_48184;
	BIT_VEC cppVar_48185;
	BIT_VEC cppVar_48186;
	BIT_VEC cppVar_48173;
	BIT_VEC cppVar_48187;
	bool cppVar_48188;
	BIT_VEC cppVar_48191;
	BIT_VEC cppVar_48192;
	BIT_VEC cppVar_48193;
	bool cppVar_48194;
	BIT_VEC cppVar_48195;
	BIT_VEC cppVar_48196;
	BIT_VEC cppVar_48197;
	BIT_VEC cppVar_48198;
	BIT_VEC cppVar_48199;
	BIT_VEC cppVar_48200;
	BIT_VEC cppVar_48201;
	BIT_VEC cppVar_48202;
	BIT_VEC cppVar_48203;
	BIT_VEC cppVar_48190;
	BIT_VEC cppVar_48204;
	bool cppVar_48205;
	BIT_VEC cppVar_48208;
	BIT_VEC cppVar_48209;
	BIT_VEC cppVar_48210;
	bool cppVar_48211;
	BIT_VEC cppVar_48212;
	BIT_VEC cppVar_48213;
	BIT_VEC cppVar_48214;
	BIT_VEC cppVar_48215;
	BIT_VEC cppVar_48216;
	BIT_VEC cppVar_48217;
	BIT_VEC cppVar_48218;
	BIT_VEC cppVar_48219;
	BIT_VEC cppVar_48220;
	BIT_VEC cppVar_48207;
	BIT_VEC cppVar_48221;
	bool cppVar_48222;
	BIT_VEC cppVar_48225;
	BIT_VEC cppVar_48226;
	BIT_VEC cppVar_48227;
	bool cppVar_48228;
	BIT_VEC cppVar_48229;
	BIT_VEC cppVar_48230;
	BIT_VEC cppVar_48231;
	BIT_VEC cppVar_48232;
	BIT_VEC cppVar_48233;
	BIT_VEC cppVar_48234;
	BIT_VEC cppVar_48235;
	BIT_VEC cppVar_48236;
	BIT_VEC cppVar_48237;
	BIT_VEC cppVar_48224;
	BIT_VEC cppVar_48238;
	bool cppVar_48239;
	BIT_VEC cppVar_48242;
	BIT_VEC cppVar_48243;
	BIT_VEC cppVar_48244;
	bool cppVar_48245;
	BIT_VEC cppVar_48246;
	BIT_VEC cppVar_48247;
	BIT_VEC cppVar_48248;
	BIT_VEC cppVar_48249;
	BIT_VEC cppVar_48250;
	BIT_VEC cppVar_48251;
	BIT_VEC cppVar_48252;
	BIT_VEC cppVar_48253;
	BIT_VEC cppVar_48254;
	BIT_VEC cppVar_48241;
	BIT_VEC cppVar_48255;
	bool cppVar_48256;
	BIT_VEC cppVar_48259;
	BIT_VEC cppVar_48260;
	BIT_VEC cppVar_48261;
	bool cppVar_48262;
	BIT_VEC cppVar_48263;
	BIT_VEC cppVar_48264;
	BIT_VEC cppVar_48265;
	BIT_VEC cppVar_48266;
	BIT_VEC cppVar_48267;
	BIT_VEC cppVar_48268;
	BIT_VEC cppVar_48269;
	BIT_VEC cppVar_48270;
	BIT_VEC cppVar_48271;
	BIT_VEC cppVar_48258;
	BIT_VEC cppVar_48272;
	bool cppVar_48273;
	BIT_VEC cppVar_48276;
	BIT_VEC cppVar_48277;
	BIT_VEC cppVar_48278;
	bool cppVar_48279;
	BIT_VEC cppVar_48280;
	BIT_VEC cppVar_48281;
	BIT_VEC cppVar_48282;
	BIT_VEC cppVar_48283;
	BIT_VEC cppVar_48284;
	BIT_VEC cppVar_48285;
	BIT_VEC cppVar_48286;
	BIT_VEC cppVar_48287;
	BIT_VEC cppVar_48288;
	BIT_VEC cppVar_48275;
	BIT_VEC cppVar_48289;
	bool cppVar_48290;
	BIT_VEC cppVar_48293;
	BIT_VEC cppVar_48294;
	BIT_VEC cppVar_48295;
	bool cppVar_48296;
	BIT_VEC cppVar_48297;
	BIT_VEC cppVar_48298;
	BIT_VEC cppVar_48299;
	BIT_VEC cppVar_48300;
	BIT_VEC cppVar_48301;
	BIT_VEC cppVar_48302;
	BIT_VEC cppVar_48303;
	BIT_VEC cppVar_48304;
	BIT_VEC cppVar_48305;
	BIT_VEC cppVar_48292;
	BIT_VEC cppVar_48306;
	bool cppVar_48307;
	BIT_VEC cppVar_48310;
	BIT_VEC cppVar_48311;
	BIT_VEC cppVar_48312;
	bool cppVar_48313;
	BIT_VEC cppVar_48314;
	BIT_VEC cppVar_48315;
	BIT_VEC cppVar_48316;
	BIT_VEC cppVar_48317;
	BIT_VEC cppVar_48318;
	BIT_VEC cppVar_48319;
	BIT_VEC cppVar_48320;
	BIT_VEC cppVar_48321;
	BIT_VEC cppVar_48322;
	BIT_VEC cppVar_48309;
	BIT_VEC cppVar_48323;
	bool cppVar_48324;
	BIT_VEC cppVar_48327;
	BIT_VEC cppVar_48328;
	BIT_VEC cppVar_48329;
	bool cppVar_48330;
	BIT_VEC cppVar_48331;
	BIT_VEC cppVar_48332;
	BIT_VEC cppVar_48333;
	BIT_VEC cppVar_48334;
	BIT_VEC cppVar_48335;
	BIT_VEC cppVar_48336;
	BIT_VEC cppVar_48337;
	BIT_VEC cppVar_48338;
	BIT_VEC cppVar_48339;
	BIT_VEC cppVar_48326;
	BIT_VEC cppVar_48340;
	bool cppVar_48341;
	BIT_VEC cppVar_48344;
	BIT_VEC cppVar_48345;
	BIT_VEC cppVar_48346;
	bool cppVar_48347;
	BIT_VEC cppVar_48348;
	BIT_VEC cppVar_48349;
	BIT_VEC cppVar_48350;
	BIT_VEC cppVar_48351;
	BIT_VEC cppVar_48352;
	BIT_VEC cppVar_48353;
	BIT_VEC cppVar_48354;
	BIT_VEC cppVar_48355;
	BIT_VEC cppVar_48356;
	BIT_VEC cppVar_48343;
	BIT_VEC cppVar_48357;
	bool cppVar_48358;
	BIT_VEC cppVar_48361;
	BIT_VEC cppVar_48362;
	BIT_VEC cppVar_48363;
	bool cppVar_48364;
	BIT_VEC cppVar_48365;
	BIT_VEC cppVar_48366;
	BIT_VEC cppVar_48367;
	BIT_VEC cppVar_48368;
	BIT_VEC cppVar_48369;
	BIT_VEC cppVar_48370;
	BIT_VEC cppVar_48371;
	BIT_VEC cppVar_48372;
	BIT_VEC cppVar_48373;
	BIT_VEC cppVar_48360;
	BIT_VEC cppVar_48374;
	bool cppVar_48375;
	BIT_VEC cppVar_48378;
	BIT_VEC cppVar_48379;
	BIT_VEC cppVar_48380;
	bool cppVar_48381;
	BIT_VEC cppVar_48382;
	BIT_VEC cppVar_48383;
	BIT_VEC cppVar_48384;
	BIT_VEC cppVar_48385;
	BIT_VEC cppVar_48386;
	BIT_VEC cppVar_48387;
	BIT_VEC cppVar_48388;
	BIT_VEC cppVar_48389;
	BIT_VEC cppVar_48390;
	BIT_VEC cppVar_48377;
	BIT_VEC cppVar_48391;
	bool cppVar_48392;
	BIT_VEC cppVar_48393;
	BIT_VEC cppVar_48376;
	BIT_VEC cppVar_48359;
	BIT_VEC cppVar_48342;
	BIT_VEC cppVar_48325;
	BIT_VEC cppVar_48308;
	BIT_VEC cppVar_48291;
	BIT_VEC cppVar_48274;
	BIT_VEC cppVar_48257;
	BIT_VEC cppVar_48240;
	BIT_VEC cppVar_48223;
	BIT_VEC cppVar_48206;
	BIT_VEC cppVar_48189;
	BIT_VEC cppVar_48172;
	BIT_VEC cppVar_48155;
	BIT_VEC cppVar_48138;
	BIT_VEC cppVar_48121;
	BIT_VEC cppVar_48104;
	BIT_VEC cppVar_48087;
	BIT_VEC cppVar_48070;
	BIT_VEC cppVar_48053;
	BIT_VEC cppVar_48036;
	BIT_VEC cppVar_48000;
	BIT_VEC cppVar_48394;
	BIT_VEC cppVar_48395;
	BIT_VEC cppVar_48396;
	BIT_VEC cppVar_48397;
	BIT_VEC cppVar_48398;
	BIT_VEC cppVar_48399;
	BIT_VEC cppVar_48400;
	BIT_VEC cppVar_48401;
	BIT_VEC cppVar_48402;
	BIT_VEC cppVar_48403;
	BIT_VEC cppVar_48404;
	BIT_VEC cppVar_48405;
	BIT_VEC cppVar_47580;
	BIT_VEC cppVar_48407;
	BIT_VEC cppVar_48408;
	bool cppVar_48409;
	BIT_VEC cppVar_48410;
	BIT_VEC cppVar_48413;
	BIT_VEC cppVar_48414;
	BIT_VEC cppVar_48415;
	BIT_VEC cppVar_48416;
	BIT_VEC cppVar_48417;
	bool cppVar_48418;
	BIT_VEC cppVar_48419;
	BIT_VEC cppVar_48420;
	BIT_VEC cppVar_48421;
	BIT_VEC cppVar_48422;
	BIT_VEC cppVar_48423;
	BIT_VEC cppVar_48424;
	BIT_VEC cppVar_48425;
	BIT_VEC cppVar_48426;
	BIT_VEC cppVar_48427;
	BIT_VEC cppVar_48428;
	BIT_VEC cppVar_48429;
	BIT_VEC cppVar_48412;
	BIT_VEC cppVar_48430;
	BIT_VEC cppVar_48431;
	bool cppVar_48432;
	BIT_VEC cppVar_48434;
	BIT_VEC cppVar_48435;
	BIT_VEC cppVar_48436;
	bool cppVar_48437;
	BIT_VEC cppVar_48438;
	BIT_VEC cppVar_48439;
	BIT_VEC cppVar_48440;
	BIT_VEC cppVar_48441;
	BIT_VEC cppVar_48442;
	BIT_VEC cppVar_48443;
	BIT_VEC cppVar_48444;
	BIT_VEC cppVar_48445;
	BIT_VEC cppVar_48446;
	BIT_VEC cppVar_48433;
	BIT_VEC cppVar_48447;
	BIT_VEC cppVar_48450;
	BIT_VEC cppVar_48451;
	BIT_VEC cppVar_48452;
	bool cppVar_48453;
	BIT_VEC cppVar_48454;
	BIT_VEC cppVar_48455;
	BIT_VEC cppVar_48456;
	BIT_VEC cppVar_48457;
	BIT_VEC cppVar_48458;
	BIT_VEC cppVar_48459;
	BIT_VEC cppVar_48460;
	BIT_VEC cppVar_48461;
	BIT_VEC cppVar_48462;
	BIT_VEC cppVar_48449;
	BIT_VEC cppVar_48463;
	bool cppVar_48464;
	BIT_VEC cppVar_48467;
	BIT_VEC cppVar_48468;
	BIT_VEC cppVar_48469;
	bool cppVar_48470;
	BIT_VEC cppVar_48471;
	BIT_VEC cppVar_48472;
	BIT_VEC cppVar_48473;
	BIT_VEC cppVar_48474;
	BIT_VEC cppVar_48475;
	BIT_VEC cppVar_48476;
	BIT_VEC cppVar_48477;
	BIT_VEC cppVar_48478;
	BIT_VEC cppVar_48479;
	BIT_VEC cppVar_48466;
	BIT_VEC cppVar_48480;
	bool cppVar_48481;
	BIT_VEC cppVar_48484;
	BIT_VEC cppVar_48485;
	BIT_VEC cppVar_48486;
	bool cppVar_48487;
	BIT_VEC cppVar_48488;
	BIT_VEC cppVar_48489;
	BIT_VEC cppVar_48490;
	BIT_VEC cppVar_48491;
	BIT_VEC cppVar_48492;
	BIT_VEC cppVar_48493;
	BIT_VEC cppVar_48494;
	BIT_VEC cppVar_48495;
	BIT_VEC cppVar_48496;
	BIT_VEC cppVar_48483;
	BIT_VEC cppVar_48497;
	bool cppVar_48498;
	BIT_VEC cppVar_48501;
	BIT_VEC cppVar_48502;
	BIT_VEC cppVar_48503;
	bool cppVar_48504;
	BIT_VEC cppVar_48505;
	BIT_VEC cppVar_48506;
	BIT_VEC cppVar_48507;
	BIT_VEC cppVar_48508;
	BIT_VEC cppVar_48509;
	BIT_VEC cppVar_48510;
	BIT_VEC cppVar_48511;
	BIT_VEC cppVar_48512;
	BIT_VEC cppVar_48513;
	BIT_VEC cppVar_48500;
	BIT_VEC cppVar_48514;
	bool cppVar_48515;
	BIT_VEC cppVar_48518;
	BIT_VEC cppVar_48519;
	BIT_VEC cppVar_48520;
	bool cppVar_48521;
	BIT_VEC cppVar_48522;
	BIT_VEC cppVar_48523;
	BIT_VEC cppVar_48524;
	BIT_VEC cppVar_48525;
	BIT_VEC cppVar_48526;
	BIT_VEC cppVar_48527;
	BIT_VEC cppVar_48528;
	BIT_VEC cppVar_48529;
	BIT_VEC cppVar_48530;
	BIT_VEC cppVar_48517;
	BIT_VEC cppVar_48531;
	bool cppVar_48532;
	BIT_VEC cppVar_48535;
	BIT_VEC cppVar_48536;
	BIT_VEC cppVar_48537;
	bool cppVar_48538;
	BIT_VEC cppVar_48539;
	BIT_VEC cppVar_48540;
	BIT_VEC cppVar_48541;
	BIT_VEC cppVar_48542;
	BIT_VEC cppVar_48543;
	BIT_VEC cppVar_48544;
	BIT_VEC cppVar_48545;
	BIT_VEC cppVar_48546;
	BIT_VEC cppVar_48547;
	BIT_VEC cppVar_48534;
	BIT_VEC cppVar_48548;
	bool cppVar_48549;
	BIT_VEC cppVar_48552;
	BIT_VEC cppVar_48553;
	BIT_VEC cppVar_48554;
	bool cppVar_48555;
	BIT_VEC cppVar_48556;
	BIT_VEC cppVar_48557;
	BIT_VEC cppVar_48558;
	BIT_VEC cppVar_48559;
	BIT_VEC cppVar_48560;
	BIT_VEC cppVar_48561;
	BIT_VEC cppVar_48562;
	BIT_VEC cppVar_48563;
	BIT_VEC cppVar_48564;
	BIT_VEC cppVar_48551;
	BIT_VEC cppVar_48565;
	bool cppVar_48566;
	BIT_VEC cppVar_48569;
	BIT_VEC cppVar_48570;
	BIT_VEC cppVar_48571;
	bool cppVar_48572;
	BIT_VEC cppVar_48573;
	BIT_VEC cppVar_48574;
	BIT_VEC cppVar_48575;
	BIT_VEC cppVar_48576;
	BIT_VEC cppVar_48577;
	BIT_VEC cppVar_48578;
	BIT_VEC cppVar_48579;
	BIT_VEC cppVar_48580;
	BIT_VEC cppVar_48581;
	BIT_VEC cppVar_48568;
	BIT_VEC cppVar_48582;
	bool cppVar_48583;
	BIT_VEC cppVar_48586;
	BIT_VEC cppVar_48587;
	BIT_VEC cppVar_48588;
	bool cppVar_48589;
	BIT_VEC cppVar_48590;
	BIT_VEC cppVar_48591;
	BIT_VEC cppVar_48592;
	BIT_VEC cppVar_48593;
	BIT_VEC cppVar_48594;
	BIT_VEC cppVar_48595;
	BIT_VEC cppVar_48596;
	BIT_VEC cppVar_48597;
	BIT_VEC cppVar_48598;
	BIT_VEC cppVar_48585;
	BIT_VEC cppVar_48599;
	bool cppVar_48600;
	BIT_VEC cppVar_48603;
	BIT_VEC cppVar_48604;
	BIT_VEC cppVar_48605;
	bool cppVar_48606;
	BIT_VEC cppVar_48607;
	BIT_VEC cppVar_48608;
	BIT_VEC cppVar_48609;
	BIT_VEC cppVar_48610;
	BIT_VEC cppVar_48611;
	BIT_VEC cppVar_48612;
	BIT_VEC cppVar_48613;
	BIT_VEC cppVar_48614;
	BIT_VEC cppVar_48615;
	BIT_VEC cppVar_48602;
	BIT_VEC cppVar_48616;
	bool cppVar_48617;
	BIT_VEC cppVar_48620;
	BIT_VEC cppVar_48621;
	BIT_VEC cppVar_48622;
	bool cppVar_48623;
	BIT_VEC cppVar_48624;
	BIT_VEC cppVar_48625;
	BIT_VEC cppVar_48626;
	BIT_VEC cppVar_48627;
	BIT_VEC cppVar_48628;
	BIT_VEC cppVar_48629;
	BIT_VEC cppVar_48630;
	BIT_VEC cppVar_48631;
	BIT_VEC cppVar_48632;
	BIT_VEC cppVar_48619;
	BIT_VEC cppVar_48633;
	bool cppVar_48634;
	BIT_VEC cppVar_48637;
	BIT_VEC cppVar_48638;
	BIT_VEC cppVar_48639;
	bool cppVar_48640;
	BIT_VEC cppVar_48641;
	BIT_VEC cppVar_48642;
	BIT_VEC cppVar_48643;
	BIT_VEC cppVar_48644;
	BIT_VEC cppVar_48645;
	BIT_VEC cppVar_48646;
	BIT_VEC cppVar_48647;
	BIT_VEC cppVar_48648;
	BIT_VEC cppVar_48649;
	BIT_VEC cppVar_48636;
	BIT_VEC cppVar_48650;
	bool cppVar_48651;
	BIT_VEC cppVar_48654;
	BIT_VEC cppVar_48655;
	BIT_VEC cppVar_48656;
	bool cppVar_48657;
	BIT_VEC cppVar_48658;
	BIT_VEC cppVar_48659;
	BIT_VEC cppVar_48660;
	BIT_VEC cppVar_48661;
	BIT_VEC cppVar_48662;
	BIT_VEC cppVar_48663;
	BIT_VEC cppVar_48664;
	BIT_VEC cppVar_48665;
	BIT_VEC cppVar_48666;
	BIT_VEC cppVar_48653;
	BIT_VEC cppVar_48667;
	bool cppVar_48668;
	BIT_VEC cppVar_48671;
	BIT_VEC cppVar_48672;
	BIT_VEC cppVar_48673;
	bool cppVar_48674;
	BIT_VEC cppVar_48675;
	BIT_VEC cppVar_48676;
	BIT_VEC cppVar_48677;
	BIT_VEC cppVar_48678;
	BIT_VEC cppVar_48679;
	BIT_VEC cppVar_48680;
	BIT_VEC cppVar_48681;
	BIT_VEC cppVar_48682;
	BIT_VEC cppVar_48683;
	BIT_VEC cppVar_48670;
	BIT_VEC cppVar_48684;
	bool cppVar_48685;
	BIT_VEC cppVar_48688;
	BIT_VEC cppVar_48689;
	BIT_VEC cppVar_48690;
	bool cppVar_48691;
	BIT_VEC cppVar_48692;
	BIT_VEC cppVar_48693;
	BIT_VEC cppVar_48694;
	BIT_VEC cppVar_48695;
	BIT_VEC cppVar_48696;
	BIT_VEC cppVar_48697;
	BIT_VEC cppVar_48698;
	BIT_VEC cppVar_48699;
	BIT_VEC cppVar_48700;
	BIT_VEC cppVar_48687;
	BIT_VEC cppVar_48701;
	bool cppVar_48702;
	BIT_VEC cppVar_48705;
	BIT_VEC cppVar_48706;
	BIT_VEC cppVar_48707;
	bool cppVar_48708;
	BIT_VEC cppVar_48709;
	BIT_VEC cppVar_48710;
	BIT_VEC cppVar_48711;
	BIT_VEC cppVar_48712;
	BIT_VEC cppVar_48713;
	BIT_VEC cppVar_48714;
	BIT_VEC cppVar_48715;
	BIT_VEC cppVar_48716;
	BIT_VEC cppVar_48717;
	BIT_VEC cppVar_48704;
	BIT_VEC cppVar_48718;
	bool cppVar_48719;
	BIT_VEC cppVar_48722;
	BIT_VEC cppVar_48723;
	BIT_VEC cppVar_48724;
	bool cppVar_48725;
	BIT_VEC cppVar_48726;
	BIT_VEC cppVar_48727;
	BIT_VEC cppVar_48728;
	BIT_VEC cppVar_48729;
	BIT_VEC cppVar_48730;
	BIT_VEC cppVar_48731;
	BIT_VEC cppVar_48732;
	BIT_VEC cppVar_48733;
	BIT_VEC cppVar_48734;
	BIT_VEC cppVar_48721;
	BIT_VEC cppVar_48735;
	bool cppVar_48736;
	BIT_VEC cppVar_48739;
	BIT_VEC cppVar_48740;
	BIT_VEC cppVar_48741;
	bool cppVar_48742;
	BIT_VEC cppVar_48743;
	BIT_VEC cppVar_48744;
	BIT_VEC cppVar_48745;
	BIT_VEC cppVar_48746;
	BIT_VEC cppVar_48747;
	BIT_VEC cppVar_48748;
	BIT_VEC cppVar_48749;
	BIT_VEC cppVar_48750;
	BIT_VEC cppVar_48751;
	BIT_VEC cppVar_48738;
	BIT_VEC cppVar_48752;
	bool cppVar_48753;
	BIT_VEC cppVar_48756;
	BIT_VEC cppVar_48757;
	BIT_VEC cppVar_48758;
	bool cppVar_48759;
	BIT_VEC cppVar_48760;
	BIT_VEC cppVar_48761;
	BIT_VEC cppVar_48762;
	BIT_VEC cppVar_48763;
	BIT_VEC cppVar_48764;
	BIT_VEC cppVar_48765;
	BIT_VEC cppVar_48766;
	BIT_VEC cppVar_48767;
	BIT_VEC cppVar_48768;
	BIT_VEC cppVar_48755;
	BIT_VEC cppVar_48769;
	bool cppVar_48770;
	BIT_VEC cppVar_48773;
	BIT_VEC cppVar_48774;
	BIT_VEC cppVar_48775;
	bool cppVar_48776;
	BIT_VEC cppVar_48777;
	BIT_VEC cppVar_48778;
	BIT_VEC cppVar_48779;
	BIT_VEC cppVar_48780;
	BIT_VEC cppVar_48781;
	BIT_VEC cppVar_48782;
	BIT_VEC cppVar_48783;
	BIT_VEC cppVar_48784;
	BIT_VEC cppVar_48785;
	BIT_VEC cppVar_48772;
	BIT_VEC cppVar_48786;
	bool cppVar_48787;
	BIT_VEC cppVar_48790;
	BIT_VEC cppVar_48791;
	BIT_VEC cppVar_48792;
	bool cppVar_48793;
	BIT_VEC cppVar_48794;
	BIT_VEC cppVar_48795;
	BIT_VEC cppVar_48796;
	BIT_VEC cppVar_48797;
	BIT_VEC cppVar_48798;
	BIT_VEC cppVar_48799;
	BIT_VEC cppVar_48800;
	BIT_VEC cppVar_48801;
	BIT_VEC cppVar_48802;
	BIT_VEC cppVar_48789;
	BIT_VEC cppVar_48803;
	bool cppVar_48804;
	BIT_VEC cppVar_48805;
	BIT_VEC cppVar_48788;
	BIT_VEC cppVar_48771;
	BIT_VEC cppVar_48754;
	BIT_VEC cppVar_48737;
	BIT_VEC cppVar_48720;
	BIT_VEC cppVar_48703;
	BIT_VEC cppVar_48686;
	BIT_VEC cppVar_48669;
	BIT_VEC cppVar_48652;
	BIT_VEC cppVar_48635;
	BIT_VEC cppVar_48618;
	BIT_VEC cppVar_48601;
	BIT_VEC cppVar_48584;
	BIT_VEC cppVar_48567;
	BIT_VEC cppVar_48550;
	BIT_VEC cppVar_48533;
	BIT_VEC cppVar_48516;
	BIT_VEC cppVar_48499;
	BIT_VEC cppVar_48482;
	BIT_VEC cppVar_48465;
	BIT_VEC cppVar_48448;
	BIT_VEC cppVar_48411;
	BIT_VEC cppVar_48806;
	BIT_VEC cppVar_48807;
	BIT_VEC cppVar_48808;
	BIT_VEC cppVar_48809;
	BIT_VEC cppVar_48810;
	BIT_VEC cppVar_48811;
	BIT_VEC cppVar_48812;
	BIT_VEC cppVar_48813;
	BIT_VEC cppVar_48815;
	BIT_VEC cppVar_48816;
	bool cppVar_48817;
	BIT_VEC cppVar_48818;
	BIT_VEC cppVar_48819;
	BIT_VEC cppVar_48821;
	BIT_VEC cppVar_48822;
	BIT_VEC cppVar_48823;
	BIT_VEC cppVar_48824;
	BIT_VEC cppVar_48825;
	bool cppVar_48826;
	BIT_VEC cppVar_48827;
	BIT_VEC cppVar_48828;
	BIT_VEC cppVar_48820;
	BIT_VEC cppVar_48829;
	BIT_VEC cppVar_48830;
	BIT_VEC cppVar_48831;
	BIT_VEC cppVar_48832;
	BIT_VEC cppVar_48834;
	BIT_VEC cppVar_48835;
	bool cppVar_48836;
	BIT_VEC cppVar_48839;
	BIT_VEC cppVar_48840;
	BIT_VEC cppVar_48841;
	BIT_VEC cppVar_48842;
	BIT_VEC cppVar_48843;
	bool cppVar_48844;
	BIT_VEC cppVar_48845;
	BIT_VEC cppVar_48846;
	BIT_VEC cppVar_48847;
	BIT_VEC cppVar_48848;
	BIT_VEC cppVar_48849;
	BIT_VEC cppVar_48850;
	BIT_VEC cppVar_48851;
	BIT_VEC cppVar_48852;
	BIT_VEC cppVar_48853;
	BIT_VEC cppVar_48854;
	BIT_VEC cppVar_48855;
	BIT_VEC cppVar_48838;
	BIT_VEC cppVar_48856;
	BIT_VEC cppVar_48857;
	bool cppVar_48858;
	BIT_VEC cppVar_48860;
	BIT_VEC cppVar_48861;
	BIT_VEC cppVar_48862;
	bool cppVar_48863;
	BIT_VEC cppVar_48864;
	BIT_VEC cppVar_48865;
	BIT_VEC cppVar_48866;
	BIT_VEC cppVar_48867;
	BIT_VEC cppVar_48868;
	BIT_VEC cppVar_48869;
	BIT_VEC cppVar_48870;
	BIT_VEC cppVar_48871;
	BIT_VEC cppVar_48872;
	BIT_VEC cppVar_48859;
	BIT_VEC cppVar_48873;
	BIT_VEC cppVar_48876;
	BIT_VEC cppVar_48877;
	BIT_VEC cppVar_48878;
	bool cppVar_48879;
	BIT_VEC cppVar_48880;
	BIT_VEC cppVar_48881;
	BIT_VEC cppVar_48882;
	BIT_VEC cppVar_48883;
	BIT_VEC cppVar_48884;
	BIT_VEC cppVar_48885;
	BIT_VEC cppVar_48886;
	BIT_VEC cppVar_48887;
	BIT_VEC cppVar_48888;
	BIT_VEC cppVar_48875;
	BIT_VEC cppVar_48889;
	bool cppVar_48890;
	BIT_VEC cppVar_48893;
	BIT_VEC cppVar_48894;
	BIT_VEC cppVar_48895;
	bool cppVar_48896;
	BIT_VEC cppVar_48897;
	BIT_VEC cppVar_48898;
	BIT_VEC cppVar_48899;
	BIT_VEC cppVar_48900;
	BIT_VEC cppVar_48901;
	BIT_VEC cppVar_48902;
	BIT_VEC cppVar_48903;
	BIT_VEC cppVar_48904;
	BIT_VEC cppVar_48905;
	BIT_VEC cppVar_48892;
	BIT_VEC cppVar_48906;
	bool cppVar_48907;
	BIT_VEC cppVar_48910;
	BIT_VEC cppVar_48911;
	BIT_VEC cppVar_48912;
	bool cppVar_48913;
	BIT_VEC cppVar_48914;
	BIT_VEC cppVar_48915;
	BIT_VEC cppVar_48916;
	BIT_VEC cppVar_48917;
	BIT_VEC cppVar_48918;
	BIT_VEC cppVar_48919;
	BIT_VEC cppVar_48920;
	BIT_VEC cppVar_48921;
	BIT_VEC cppVar_48922;
	BIT_VEC cppVar_48909;
	BIT_VEC cppVar_48923;
	bool cppVar_48924;
	BIT_VEC cppVar_48927;
	BIT_VEC cppVar_48928;
	BIT_VEC cppVar_48929;
	bool cppVar_48930;
	BIT_VEC cppVar_48931;
	BIT_VEC cppVar_48932;
	BIT_VEC cppVar_48933;
	BIT_VEC cppVar_48934;
	BIT_VEC cppVar_48935;
	BIT_VEC cppVar_48936;
	BIT_VEC cppVar_48937;
	BIT_VEC cppVar_48938;
	BIT_VEC cppVar_48939;
	BIT_VEC cppVar_48926;
	BIT_VEC cppVar_48940;
	bool cppVar_48941;
	BIT_VEC cppVar_48944;
	BIT_VEC cppVar_48945;
	BIT_VEC cppVar_48946;
	bool cppVar_48947;
	BIT_VEC cppVar_48948;
	BIT_VEC cppVar_48949;
	BIT_VEC cppVar_48950;
	BIT_VEC cppVar_48951;
	BIT_VEC cppVar_48952;
	BIT_VEC cppVar_48953;
	BIT_VEC cppVar_48954;
	BIT_VEC cppVar_48955;
	BIT_VEC cppVar_48956;
	BIT_VEC cppVar_48943;
	BIT_VEC cppVar_48957;
	bool cppVar_48958;
	BIT_VEC cppVar_48961;
	BIT_VEC cppVar_48962;
	BIT_VEC cppVar_48963;
	bool cppVar_48964;
	BIT_VEC cppVar_48965;
	BIT_VEC cppVar_48966;
	BIT_VEC cppVar_48967;
	BIT_VEC cppVar_48968;
	BIT_VEC cppVar_48969;
	BIT_VEC cppVar_48970;
	BIT_VEC cppVar_48971;
	BIT_VEC cppVar_48972;
	BIT_VEC cppVar_48973;
	BIT_VEC cppVar_48960;
	BIT_VEC cppVar_48974;
	bool cppVar_48975;
	BIT_VEC cppVar_48978;
	BIT_VEC cppVar_48979;
	BIT_VEC cppVar_48980;
	bool cppVar_48981;
	BIT_VEC cppVar_48982;
	BIT_VEC cppVar_48983;
	BIT_VEC cppVar_48984;
	BIT_VEC cppVar_48985;
	BIT_VEC cppVar_48986;
	BIT_VEC cppVar_48987;
	BIT_VEC cppVar_48988;
	BIT_VEC cppVar_48989;
	BIT_VEC cppVar_48990;
	BIT_VEC cppVar_48977;
	BIT_VEC cppVar_48991;
	bool cppVar_48992;
	BIT_VEC cppVar_48995;
	BIT_VEC cppVar_48996;
	BIT_VEC cppVar_48997;
	bool cppVar_48998;
	BIT_VEC cppVar_48999;
	BIT_VEC cppVar_49000;
	BIT_VEC cppVar_49001;
	BIT_VEC cppVar_49002;
	BIT_VEC cppVar_49003;
	BIT_VEC cppVar_49004;
	BIT_VEC cppVar_49005;
	BIT_VEC cppVar_49006;
	BIT_VEC cppVar_49007;
	BIT_VEC cppVar_48994;
	BIT_VEC cppVar_49008;
	bool cppVar_49009;
	BIT_VEC cppVar_49012;
	BIT_VEC cppVar_49013;
	BIT_VEC cppVar_49014;
	bool cppVar_49015;
	BIT_VEC cppVar_49016;
	BIT_VEC cppVar_49017;
	BIT_VEC cppVar_49018;
	BIT_VEC cppVar_49019;
	BIT_VEC cppVar_49020;
	BIT_VEC cppVar_49021;
	BIT_VEC cppVar_49022;
	BIT_VEC cppVar_49023;
	BIT_VEC cppVar_49024;
	BIT_VEC cppVar_49011;
	BIT_VEC cppVar_49025;
	bool cppVar_49026;
	BIT_VEC cppVar_49029;
	BIT_VEC cppVar_49030;
	BIT_VEC cppVar_49031;
	bool cppVar_49032;
	BIT_VEC cppVar_49033;
	BIT_VEC cppVar_49034;
	BIT_VEC cppVar_49035;
	BIT_VEC cppVar_49036;
	BIT_VEC cppVar_49037;
	BIT_VEC cppVar_49038;
	BIT_VEC cppVar_49039;
	BIT_VEC cppVar_49040;
	BIT_VEC cppVar_49041;
	BIT_VEC cppVar_49028;
	BIT_VEC cppVar_49042;
	bool cppVar_49043;
	BIT_VEC cppVar_49046;
	BIT_VEC cppVar_49047;
	BIT_VEC cppVar_49048;
	bool cppVar_49049;
	BIT_VEC cppVar_49050;
	BIT_VEC cppVar_49051;
	BIT_VEC cppVar_49052;
	BIT_VEC cppVar_49053;
	BIT_VEC cppVar_49054;
	BIT_VEC cppVar_49055;
	BIT_VEC cppVar_49056;
	BIT_VEC cppVar_49057;
	BIT_VEC cppVar_49058;
	BIT_VEC cppVar_49045;
	BIT_VEC cppVar_49059;
	bool cppVar_49060;
	BIT_VEC cppVar_49063;
	BIT_VEC cppVar_49064;
	BIT_VEC cppVar_49065;
	bool cppVar_49066;
	BIT_VEC cppVar_49067;
	BIT_VEC cppVar_49068;
	BIT_VEC cppVar_49069;
	BIT_VEC cppVar_49070;
	BIT_VEC cppVar_49071;
	BIT_VEC cppVar_49072;
	BIT_VEC cppVar_49073;
	BIT_VEC cppVar_49074;
	BIT_VEC cppVar_49075;
	BIT_VEC cppVar_49062;
	BIT_VEC cppVar_49076;
	bool cppVar_49077;
	BIT_VEC cppVar_49080;
	BIT_VEC cppVar_49081;
	BIT_VEC cppVar_49082;
	bool cppVar_49083;
	BIT_VEC cppVar_49084;
	BIT_VEC cppVar_49085;
	BIT_VEC cppVar_49086;
	BIT_VEC cppVar_49087;
	BIT_VEC cppVar_49088;
	BIT_VEC cppVar_49089;
	BIT_VEC cppVar_49090;
	BIT_VEC cppVar_49091;
	BIT_VEC cppVar_49092;
	BIT_VEC cppVar_49079;
	BIT_VEC cppVar_49093;
	bool cppVar_49094;
	BIT_VEC cppVar_49097;
	BIT_VEC cppVar_49098;
	BIT_VEC cppVar_49099;
	bool cppVar_49100;
	BIT_VEC cppVar_49101;
	BIT_VEC cppVar_49102;
	BIT_VEC cppVar_49103;
	BIT_VEC cppVar_49104;
	BIT_VEC cppVar_49105;
	BIT_VEC cppVar_49106;
	BIT_VEC cppVar_49107;
	BIT_VEC cppVar_49108;
	BIT_VEC cppVar_49109;
	BIT_VEC cppVar_49096;
	BIT_VEC cppVar_49110;
	bool cppVar_49111;
	BIT_VEC cppVar_49114;
	BIT_VEC cppVar_49115;
	BIT_VEC cppVar_49116;
	bool cppVar_49117;
	BIT_VEC cppVar_49118;
	BIT_VEC cppVar_49119;
	BIT_VEC cppVar_49120;
	BIT_VEC cppVar_49121;
	BIT_VEC cppVar_49122;
	BIT_VEC cppVar_49123;
	BIT_VEC cppVar_49124;
	BIT_VEC cppVar_49125;
	BIT_VEC cppVar_49126;
	BIT_VEC cppVar_49113;
	BIT_VEC cppVar_49127;
	bool cppVar_49128;
	BIT_VEC cppVar_49131;
	BIT_VEC cppVar_49132;
	BIT_VEC cppVar_49133;
	bool cppVar_49134;
	BIT_VEC cppVar_49135;
	BIT_VEC cppVar_49136;
	BIT_VEC cppVar_49137;
	BIT_VEC cppVar_49138;
	BIT_VEC cppVar_49139;
	BIT_VEC cppVar_49140;
	BIT_VEC cppVar_49141;
	BIT_VEC cppVar_49142;
	BIT_VEC cppVar_49143;
	BIT_VEC cppVar_49130;
	BIT_VEC cppVar_49144;
	bool cppVar_49145;
	BIT_VEC cppVar_49148;
	BIT_VEC cppVar_49149;
	BIT_VEC cppVar_49150;
	bool cppVar_49151;
	BIT_VEC cppVar_49152;
	BIT_VEC cppVar_49153;
	BIT_VEC cppVar_49154;
	BIT_VEC cppVar_49155;
	BIT_VEC cppVar_49156;
	BIT_VEC cppVar_49157;
	BIT_VEC cppVar_49158;
	BIT_VEC cppVar_49159;
	BIT_VEC cppVar_49160;
	BIT_VEC cppVar_49147;
	BIT_VEC cppVar_49161;
	bool cppVar_49162;
	BIT_VEC cppVar_49165;
	BIT_VEC cppVar_49166;
	BIT_VEC cppVar_49167;
	bool cppVar_49168;
	BIT_VEC cppVar_49169;
	BIT_VEC cppVar_49170;
	BIT_VEC cppVar_49171;
	BIT_VEC cppVar_49172;
	BIT_VEC cppVar_49173;
	BIT_VEC cppVar_49174;
	BIT_VEC cppVar_49175;
	BIT_VEC cppVar_49176;
	BIT_VEC cppVar_49177;
	BIT_VEC cppVar_49164;
	BIT_VEC cppVar_49178;
	bool cppVar_49179;
	BIT_VEC cppVar_49182;
	BIT_VEC cppVar_49183;
	BIT_VEC cppVar_49184;
	bool cppVar_49185;
	BIT_VEC cppVar_49186;
	BIT_VEC cppVar_49187;
	BIT_VEC cppVar_49188;
	BIT_VEC cppVar_49189;
	BIT_VEC cppVar_49190;
	BIT_VEC cppVar_49191;
	BIT_VEC cppVar_49192;
	BIT_VEC cppVar_49193;
	BIT_VEC cppVar_49194;
	BIT_VEC cppVar_49181;
	BIT_VEC cppVar_49195;
	bool cppVar_49196;
	BIT_VEC cppVar_49199;
	BIT_VEC cppVar_49200;
	BIT_VEC cppVar_49201;
	bool cppVar_49202;
	BIT_VEC cppVar_49203;
	BIT_VEC cppVar_49204;
	BIT_VEC cppVar_49205;
	BIT_VEC cppVar_49206;
	BIT_VEC cppVar_49207;
	BIT_VEC cppVar_49208;
	BIT_VEC cppVar_49209;
	BIT_VEC cppVar_49210;
	BIT_VEC cppVar_49211;
	BIT_VEC cppVar_49198;
	BIT_VEC cppVar_49212;
	bool cppVar_49213;
	BIT_VEC cppVar_49216;
	BIT_VEC cppVar_49217;
	BIT_VEC cppVar_49218;
	bool cppVar_49219;
	BIT_VEC cppVar_49220;
	BIT_VEC cppVar_49221;
	BIT_VEC cppVar_49222;
	BIT_VEC cppVar_49223;
	BIT_VEC cppVar_49224;
	BIT_VEC cppVar_49225;
	BIT_VEC cppVar_49226;
	BIT_VEC cppVar_49227;
	BIT_VEC cppVar_49228;
	BIT_VEC cppVar_49215;
	BIT_VEC cppVar_49229;
	bool cppVar_49230;
	BIT_VEC cppVar_49231;
	BIT_VEC cppVar_49214;
	BIT_VEC cppVar_49197;
	BIT_VEC cppVar_49180;
	BIT_VEC cppVar_49163;
	BIT_VEC cppVar_49146;
	BIT_VEC cppVar_49129;
	BIT_VEC cppVar_49112;
	BIT_VEC cppVar_49095;
	BIT_VEC cppVar_49078;
	BIT_VEC cppVar_49061;
	BIT_VEC cppVar_49044;
	BIT_VEC cppVar_49027;
	BIT_VEC cppVar_49010;
	BIT_VEC cppVar_48993;
	BIT_VEC cppVar_48976;
	BIT_VEC cppVar_48959;
	BIT_VEC cppVar_48942;
	BIT_VEC cppVar_48925;
	BIT_VEC cppVar_48908;
	BIT_VEC cppVar_48891;
	BIT_VEC cppVar_48874;
	BIT_VEC cppVar_48837;
	BIT_VEC cppVar_49232;
	BIT_VEC cppVar_49233;
	BIT_VEC cppVar_49234;
	BIT_VEC cppVar_49235;
	BIT_VEC cppVar_49236;
	BIT_VEC cppVar_49237;
	BIT_VEC cppVar_49239;
	BIT_VEC cppVar_49240;
	bool cppVar_49241;
	BIT_VEC cppVar_49242;
	BIT_VEC cppVar_49245;
	BIT_VEC cppVar_49246;
	BIT_VEC cppVar_49247;
	BIT_VEC cppVar_49248;
	BIT_VEC cppVar_49249;
	bool cppVar_49250;
	BIT_VEC cppVar_49251;
	BIT_VEC cppVar_49252;
	BIT_VEC cppVar_49253;
	BIT_VEC cppVar_49254;
	BIT_VEC cppVar_49255;
	BIT_VEC cppVar_49256;
	BIT_VEC cppVar_49257;
	BIT_VEC cppVar_49258;
	BIT_VEC cppVar_49259;
	BIT_VEC cppVar_49260;
	BIT_VEC cppVar_49261;
	BIT_VEC cppVar_49244;
	BIT_VEC cppVar_49262;
	BIT_VEC cppVar_49263;
	bool cppVar_49264;
	BIT_VEC cppVar_49266;
	BIT_VEC cppVar_49267;
	BIT_VEC cppVar_49268;
	bool cppVar_49269;
	BIT_VEC cppVar_49270;
	BIT_VEC cppVar_49271;
	BIT_VEC cppVar_49272;
	BIT_VEC cppVar_49273;
	BIT_VEC cppVar_49274;
	BIT_VEC cppVar_49275;
	BIT_VEC cppVar_49276;
	BIT_VEC cppVar_49277;
	BIT_VEC cppVar_49278;
	BIT_VEC cppVar_49265;
	BIT_VEC cppVar_49279;
	BIT_VEC cppVar_49282;
	BIT_VEC cppVar_49283;
	BIT_VEC cppVar_49284;
	bool cppVar_49285;
	BIT_VEC cppVar_49286;
	BIT_VEC cppVar_49287;
	BIT_VEC cppVar_49288;
	BIT_VEC cppVar_49289;
	BIT_VEC cppVar_49290;
	BIT_VEC cppVar_49291;
	BIT_VEC cppVar_49292;
	BIT_VEC cppVar_49293;
	BIT_VEC cppVar_49294;
	BIT_VEC cppVar_49281;
	BIT_VEC cppVar_49295;
	bool cppVar_49296;
	BIT_VEC cppVar_49299;
	BIT_VEC cppVar_49300;
	BIT_VEC cppVar_49301;
	bool cppVar_49302;
	BIT_VEC cppVar_49303;
	BIT_VEC cppVar_49304;
	BIT_VEC cppVar_49305;
	BIT_VEC cppVar_49306;
	BIT_VEC cppVar_49307;
	BIT_VEC cppVar_49308;
	BIT_VEC cppVar_49309;
	BIT_VEC cppVar_49310;
	BIT_VEC cppVar_49311;
	BIT_VEC cppVar_49298;
	BIT_VEC cppVar_49312;
	bool cppVar_49313;
	BIT_VEC cppVar_49316;
	BIT_VEC cppVar_49317;
	BIT_VEC cppVar_49318;
	bool cppVar_49319;
	BIT_VEC cppVar_49320;
	BIT_VEC cppVar_49321;
	BIT_VEC cppVar_49322;
	BIT_VEC cppVar_49323;
	BIT_VEC cppVar_49324;
	BIT_VEC cppVar_49325;
	BIT_VEC cppVar_49326;
	BIT_VEC cppVar_49327;
	BIT_VEC cppVar_49328;
	BIT_VEC cppVar_49315;
	BIT_VEC cppVar_49329;
	bool cppVar_49330;
	BIT_VEC cppVar_49333;
	BIT_VEC cppVar_49334;
	BIT_VEC cppVar_49335;
	bool cppVar_49336;
	BIT_VEC cppVar_49337;
	BIT_VEC cppVar_49338;
	BIT_VEC cppVar_49339;
	BIT_VEC cppVar_49340;
	BIT_VEC cppVar_49341;
	BIT_VEC cppVar_49342;
	BIT_VEC cppVar_49343;
	BIT_VEC cppVar_49344;
	BIT_VEC cppVar_49345;
	BIT_VEC cppVar_49332;
	BIT_VEC cppVar_49346;
	bool cppVar_49347;
	BIT_VEC cppVar_49350;
	BIT_VEC cppVar_49351;
	BIT_VEC cppVar_49352;
	bool cppVar_49353;
	BIT_VEC cppVar_49354;
	BIT_VEC cppVar_49355;
	BIT_VEC cppVar_49356;
	BIT_VEC cppVar_49357;
	BIT_VEC cppVar_49358;
	BIT_VEC cppVar_49359;
	BIT_VEC cppVar_49360;
	BIT_VEC cppVar_49361;
	BIT_VEC cppVar_49362;
	BIT_VEC cppVar_49349;
	BIT_VEC cppVar_49363;
	bool cppVar_49364;
	BIT_VEC cppVar_49367;
	BIT_VEC cppVar_49368;
	BIT_VEC cppVar_49369;
	bool cppVar_49370;
	BIT_VEC cppVar_49371;
	BIT_VEC cppVar_49372;
	BIT_VEC cppVar_49373;
	BIT_VEC cppVar_49374;
	BIT_VEC cppVar_49375;
	BIT_VEC cppVar_49376;
	BIT_VEC cppVar_49377;
	BIT_VEC cppVar_49378;
	BIT_VEC cppVar_49379;
	BIT_VEC cppVar_49366;
	BIT_VEC cppVar_49380;
	bool cppVar_49381;
	BIT_VEC cppVar_49384;
	BIT_VEC cppVar_49385;
	BIT_VEC cppVar_49386;
	bool cppVar_49387;
	BIT_VEC cppVar_49388;
	BIT_VEC cppVar_49389;
	BIT_VEC cppVar_49390;
	BIT_VEC cppVar_49391;
	BIT_VEC cppVar_49392;
	BIT_VEC cppVar_49393;
	BIT_VEC cppVar_49394;
	BIT_VEC cppVar_49395;
	BIT_VEC cppVar_49396;
	BIT_VEC cppVar_49383;
	BIT_VEC cppVar_49397;
	bool cppVar_49398;
	BIT_VEC cppVar_49401;
	BIT_VEC cppVar_49402;
	BIT_VEC cppVar_49403;
	bool cppVar_49404;
	BIT_VEC cppVar_49405;
	BIT_VEC cppVar_49406;
	BIT_VEC cppVar_49407;
	BIT_VEC cppVar_49408;
	BIT_VEC cppVar_49409;
	BIT_VEC cppVar_49410;
	BIT_VEC cppVar_49411;
	BIT_VEC cppVar_49412;
	BIT_VEC cppVar_49413;
	BIT_VEC cppVar_49400;
	BIT_VEC cppVar_49414;
	bool cppVar_49415;
	BIT_VEC cppVar_49418;
	BIT_VEC cppVar_49419;
	BIT_VEC cppVar_49420;
	bool cppVar_49421;
	BIT_VEC cppVar_49422;
	BIT_VEC cppVar_49423;
	BIT_VEC cppVar_49424;
	BIT_VEC cppVar_49425;
	BIT_VEC cppVar_49426;
	BIT_VEC cppVar_49427;
	BIT_VEC cppVar_49428;
	BIT_VEC cppVar_49429;
	BIT_VEC cppVar_49430;
	BIT_VEC cppVar_49417;
	BIT_VEC cppVar_49431;
	bool cppVar_49432;
	BIT_VEC cppVar_49435;
	BIT_VEC cppVar_49436;
	BIT_VEC cppVar_49437;
	bool cppVar_49438;
	BIT_VEC cppVar_49439;
	BIT_VEC cppVar_49440;
	BIT_VEC cppVar_49441;
	BIT_VEC cppVar_49442;
	BIT_VEC cppVar_49443;
	BIT_VEC cppVar_49444;
	BIT_VEC cppVar_49445;
	BIT_VEC cppVar_49446;
	BIT_VEC cppVar_49447;
	BIT_VEC cppVar_49434;
	BIT_VEC cppVar_49448;
	bool cppVar_49449;
	BIT_VEC cppVar_49452;
	BIT_VEC cppVar_49453;
	BIT_VEC cppVar_49454;
	bool cppVar_49455;
	BIT_VEC cppVar_49456;
	BIT_VEC cppVar_49457;
	BIT_VEC cppVar_49458;
	BIT_VEC cppVar_49459;
	BIT_VEC cppVar_49460;
	BIT_VEC cppVar_49461;
	BIT_VEC cppVar_49462;
	BIT_VEC cppVar_49463;
	BIT_VEC cppVar_49464;
	BIT_VEC cppVar_49451;
	BIT_VEC cppVar_49465;
	bool cppVar_49466;
	BIT_VEC cppVar_49469;
	BIT_VEC cppVar_49470;
	BIT_VEC cppVar_49471;
	bool cppVar_49472;
	BIT_VEC cppVar_49473;
	BIT_VEC cppVar_49474;
	BIT_VEC cppVar_49475;
	BIT_VEC cppVar_49476;
	BIT_VEC cppVar_49477;
	BIT_VEC cppVar_49478;
	BIT_VEC cppVar_49479;
	BIT_VEC cppVar_49480;
	BIT_VEC cppVar_49481;
	BIT_VEC cppVar_49468;
	BIT_VEC cppVar_49482;
	bool cppVar_49483;
	BIT_VEC cppVar_49486;
	BIT_VEC cppVar_49487;
	BIT_VEC cppVar_49488;
	bool cppVar_49489;
	BIT_VEC cppVar_49490;
	BIT_VEC cppVar_49491;
	BIT_VEC cppVar_49492;
	BIT_VEC cppVar_49493;
	BIT_VEC cppVar_49494;
	BIT_VEC cppVar_49495;
	BIT_VEC cppVar_49496;
	BIT_VEC cppVar_49497;
	BIT_VEC cppVar_49498;
	BIT_VEC cppVar_49485;
	BIT_VEC cppVar_49499;
	bool cppVar_49500;
	BIT_VEC cppVar_49503;
	BIT_VEC cppVar_49504;
	BIT_VEC cppVar_49505;
	bool cppVar_49506;
	BIT_VEC cppVar_49507;
	BIT_VEC cppVar_49508;
	BIT_VEC cppVar_49509;
	BIT_VEC cppVar_49510;
	BIT_VEC cppVar_49511;
	BIT_VEC cppVar_49512;
	BIT_VEC cppVar_49513;
	BIT_VEC cppVar_49514;
	BIT_VEC cppVar_49515;
	BIT_VEC cppVar_49502;
	BIT_VEC cppVar_49516;
	bool cppVar_49517;
	BIT_VEC cppVar_49520;
	BIT_VEC cppVar_49521;
	BIT_VEC cppVar_49522;
	bool cppVar_49523;
	BIT_VEC cppVar_49524;
	BIT_VEC cppVar_49525;
	BIT_VEC cppVar_49526;
	BIT_VEC cppVar_49527;
	BIT_VEC cppVar_49528;
	BIT_VEC cppVar_49529;
	BIT_VEC cppVar_49530;
	BIT_VEC cppVar_49531;
	BIT_VEC cppVar_49532;
	BIT_VEC cppVar_49519;
	BIT_VEC cppVar_49533;
	bool cppVar_49534;
	BIT_VEC cppVar_49537;
	BIT_VEC cppVar_49538;
	BIT_VEC cppVar_49539;
	bool cppVar_49540;
	BIT_VEC cppVar_49541;
	BIT_VEC cppVar_49542;
	BIT_VEC cppVar_49543;
	BIT_VEC cppVar_49544;
	BIT_VEC cppVar_49545;
	BIT_VEC cppVar_49546;
	BIT_VEC cppVar_49547;
	BIT_VEC cppVar_49548;
	BIT_VEC cppVar_49549;
	BIT_VEC cppVar_49536;
	BIT_VEC cppVar_49550;
	bool cppVar_49551;
	BIT_VEC cppVar_49554;
	BIT_VEC cppVar_49555;
	BIT_VEC cppVar_49556;
	bool cppVar_49557;
	BIT_VEC cppVar_49558;
	BIT_VEC cppVar_49559;
	BIT_VEC cppVar_49560;
	BIT_VEC cppVar_49561;
	BIT_VEC cppVar_49562;
	BIT_VEC cppVar_49563;
	BIT_VEC cppVar_49564;
	BIT_VEC cppVar_49565;
	BIT_VEC cppVar_49566;
	BIT_VEC cppVar_49553;
	BIT_VEC cppVar_49567;
	bool cppVar_49568;
	BIT_VEC cppVar_49571;
	BIT_VEC cppVar_49572;
	BIT_VEC cppVar_49573;
	bool cppVar_49574;
	BIT_VEC cppVar_49575;
	BIT_VEC cppVar_49576;
	BIT_VEC cppVar_49577;
	BIT_VEC cppVar_49578;
	BIT_VEC cppVar_49579;
	BIT_VEC cppVar_49580;
	BIT_VEC cppVar_49581;
	BIT_VEC cppVar_49582;
	BIT_VEC cppVar_49583;
	BIT_VEC cppVar_49570;
	BIT_VEC cppVar_49584;
	bool cppVar_49585;
	BIT_VEC cppVar_49588;
	BIT_VEC cppVar_49589;
	BIT_VEC cppVar_49590;
	bool cppVar_49591;
	BIT_VEC cppVar_49592;
	BIT_VEC cppVar_49593;
	BIT_VEC cppVar_49594;
	BIT_VEC cppVar_49595;
	BIT_VEC cppVar_49596;
	BIT_VEC cppVar_49597;
	BIT_VEC cppVar_49598;
	BIT_VEC cppVar_49599;
	BIT_VEC cppVar_49600;
	BIT_VEC cppVar_49587;
	BIT_VEC cppVar_49601;
	bool cppVar_49602;
	BIT_VEC cppVar_49605;
	BIT_VEC cppVar_49606;
	BIT_VEC cppVar_49607;
	bool cppVar_49608;
	BIT_VEC cppVar_49609;
	BIT_VEC cppVar_49610;
	BIT_VEC cppVar_49611;
	BIT_VEC cppVar_49612;
	BIT_VEC cppVar_49613;
	BIT_VEC cppVar_49614;
	BIT_VEC cppVar_49615;
	BIT_VEC cppVar_49616;
	BIT_VEC cppVar_49617;
	BIT_VEC cppVar_49604;
	BIT_VEC cppVar_49618;
	bool cppVar_49619;
	BIT_VEC cppVar_49622;
	BIT_VEC cppVar_49623;
	BIT_VEC cppVar_49624;
	bool cppVar_49625;
	BIT_VEC cppVar_49626;
	BIT_VEC cppVar_49627;
	BIT_VEC cppVar_49628;
	BIT_VEC cppVar_49629;
	BIT_VEC cppVar_49630;
	BIT_VEC cppVar_49631;
	BIT_VEC cppVar_49632;
	BIT_VEC cppVar_49633;
	BIT_VEC cppVar_49634;
	BIT_VEC cppVar_49621;
	BIT_VEC cppVar_49635;
	bool cppVar_49636;
	BIT_VEC cppVar_49637;
	BIT_VEC cppVar_49620;
	BIT_VEC cppVar_49603;
	BIT_VEC cppVar_49586;
	BIT_VEC cppVar_49569;
	BIT_VEC cppVar_49552;
	BIT_VEC cppVar_49535;
	BIT_VEC cppVar_49518;
	BIT_VEC cppVar_49501;
	BIT_VEC cppVar_49484;
	BIT_VEC cppVar_49467;
	BIT_VEC cppVar_49450;
	BIT_VEC cppVar_49433;
	BIT_VEC cppVar_49416;
	BIT_VEC cppVar_49399;
	BIT_VEC cppVar_49382;
	BIT_VEC cppVar_49365;
	BIT_VEC cppVar_49348;
	BIT_VEC cppVar_49331;
	BIT_VEC cppVar_49314;
	BIT_VEC cppVar_49297;
	BIT_VEC cppVar_49280;
	BIT_VEC cppVar_49243;
	BIT_VEC cppVar_49638;
	BIT_VEC cppVar_49639;
	BIT_VEC cppVar_49640;
	BIT_VEC cppVar_49641;
	BIT_VEC cppVar_49642;
	BIT_VEC cppVar_49643;
	BIT_VEC cppVar_49644;
	BIT_VEC cppVar_49645;
	BIT_VEC cppVar_49647;
	BIT_VEC cppVar_49648;
	bool cppVar_49649;
	BIT_VEC cppVar_49651;
	BIT_VEC cppVar_49652;
	BIT_VEC cppVar_49653;
	BIT_VEC cppVar_49654;
	BIT_VEC cppVar_49655;
	BIT_VEC cppVar_49656;
	BIT_VEC cppVar_49657;
	BIT_VEC cppVar_49658;
	BIT_VEC cppVar_49659;
	bool cppVar_49660;
	BIT_VEC cppVar_49661;
	BIT_VEC cppVar_49662;
	BIT_VEC cppVar_49650;
	BIT_VEC cppVar_49664;
	BIT_VEC cppVar_49665;
	BIT_VEC cppVar_49666;
	BIT_VEC cppVar_49667;
	BIT_VEC cppVar_49668;
	BIT_VEC cppVar_49669;
	BIT_VEC cppVar_49670;
	BIT_VEC cppVar_49671;
	BIT_VEC cppVar_49672;
	BIT_VEC cppVar_49673;
	BIT_VEC cppVar_49674;
	bool cppVar_49675;
	BIT_VEC cppVar_49676;
	BIT_VEC cppVar_49677;
	BIT_VEC cppVar_49663;
	BIT_VEC cppVar_49678;
	BIT_VEC cppVar_49680;
	BIT_VEC cppVar_49681;
	BIT_VEC cppVar_49682;
	BIT_VEC cppVar_49683;
	BIT_VEC cppVar_49684;
	BIT_VEC cppVar_49685;
	BIT_VEC cppVar_49686;
	BIT_VEC cppVar_49687;
	BIT_VEC cppVar_49688;
	BIT_VEC cppVar_49689;
	BIT_VEC cppVar_49690;
	BIT_VEC cppVar_49691;
	BIT_VEC cppVar_49692;
	BIT_VEC cppVar_49693;
	BIT_VEC cppVar_49694;
	BIT_VEC cppVar_49695;
	BIT_VEC cppVar_49696;
	BIT_VEC cppVar_49697;
	BIT_VEC cppVar_49698;
	BIT_VEC cppVar_49699;
	BIT_VEC cppVar_49700;
	BIT_VEC cppVar_49701;
	bool cppVar_49702;
	BIT_VEC cppVar_49703;
	BIT_VEC cppVar_49704;
	BIT_VEC cppVar_49679;
	BIT_VEC cppVar_49705;
	BIT_VEC cppVar_49706;
	BIT_VEC cppVar_49707;
	BIT_VEC cppVar_49708;
	BIT_VEC cppVar_49709;
	BIT_VEC cppVar_49711;
	BIT_VEC cppVar_49712;
	bool cppVar_49713;
	BIT_VEC cppVar_49715;
	BIT_VEC cppVar_49716;
	BIT_VEC cppVar_49717;
	BIT_VEC cppVar_49718;
	BIT_VEC cppVar_49719;
	BIT_VEC cppVar_49720;
	BIT_VEC cppVar_49721;
	BIT_VEC cppVar_49722;
	BIT_VEC cppVar_49723;
	bool cppVar_49724;
	BIT_VEC cppVar_49725;
	BIT_VEC cppVar_49726;
	BIT_VEC cppVar_49714;
	BIT_VEC cppVar_49728;
	BIT_VEC cppVar_49729;
	BIT_VEC cppVar_49730;
	BIT_VEC cppVar_49731;
	BIT_VEC cppVar_49732;
	BIT_VEC cppVar_49733;
	BIT_VEC cppVar_49734;
	BIT_VEC cppVar_49735;
	BIT_VEC cppVar_49736;
	BIT_VEC cppVar_49737;
	BIT_VEC cppVar_49738;
	bool cppVar_49739;
	BIT_VEC cppVar_49740;
	BIT_VEC cppVar_49741;
	BIT_VEC cppVar_49727;
	BIT_VEC cppVar_49742;
	BIT_VEC cppVar_49744;
	BIT_VEC cppVar_49745;
	BIT_VEC cppVar_49746;
	BIT_VEC cppVar_49747;
	BIT_VEC cppVar_49748;
	BIT_VEC cppVar_49749;
	BIT_VEC cppVar_49750;
	BIT_VEC cppVar_49751;
	BIT_VEC cppVar_49752;
	BIT_VEC cppVar_49753;
	BIT_VEC cppVar_49754;
	BIT_VEC cppVar_49755;
	BIT_VEC cppVar_49756;
	BIT_VEC cppVar_49757;
	BIT_VEC cppVar_49758;
	BIT_VEC cppVar_49759;
	BIT_VEC cppVar_49760;
	BIT_VEC cppVar_49761;
	BIT_VEC cppVar_49762;
	BIT_VEC cppVar_49763;
	BIT_VEC cppVar_49764;
	BIT_VEC cppVar_49765;
	bool cppVar_49766;
	BIT_VEC cppVar_49767;
	BIT_VEC cppVar_49768;
	BIT_VEC cppVar_49743;
	BIT_VEC cppVar_49769;
	BIT_VEC cppVar_49770;
	BIT_VEC cppVar_49771;
	BIT_VEC cppVar_49772;
	BIT_VEC cppVar_49773;
	BIT_VEC cppVar_49775;
	BIT_VEC cppVar_49776;
	bool cppVar_49777;
	BIT_VEC cppVar_49779;
	BIT_VEC cppVar_49780;
	BIT_VEC cppVar_49781;
	BIT_VEC cppVar_49782;
	BIT_VEC cppVar_49783;
	BIT_VEC cppVar_49784;
	BIT_VEC cppVar_49785;
	BIT_VEC cppVar_49786;
	BIT_VEC cppVar_49787;
	bool cppVar_49788;
	BIT_VEC cppVar_49789;
	BIT_VEC cppVar_49790;
	BIT_VEC cppVar_49778;
	BIT_VEC cppVar_49792;
	BIT_VEC cppVar_49793;
	BIT_VEC cppVar_49794;
	BIT_VEC cppVar_49795;
	BIT_VEC cppVar_49796;
	BIT_VEC cppVar_49797;
	BIT_VEC cppVar_49798;
	BIT_VEC cppVar_49799;
	BIT_VEC cppVar_49800;
	BIT_VEC cppVar_49801;
	BIT_VEC cppVar_49802;
	bool cppVar_49803;
	BIT_VEC cppVar_49804;
	BIT_VEC cppVar_49805;
	BIT_VEC cppVar_49791;
	BIT_VEC cppVar_49806;
	BIT_VEC cppVar_49808;
	BIT_VEC cppVar_49809;
	BIT_VEC cppVar_49810;
	BIT_VEC cppVar_49811;
	BIT_VEC cppVar_49812;
	BIT_VEC cppVar_49813;
	BIT_VEC cppVar_49814;
	BIT_VEC cppVar_49815;
	BIT_VEC cppVar_49816;
	BIT_VEC cppVar_49817;
	BIT_VEC cppVar_49818;
	BIT_VEC cppVar_49819;
	BIT_VEC cppVar_49820;
	BIT_VEC cppVar_49821;
	BIT_VEC cppVar_49822;
	BIT_VEC cppVar_49823;
	BIT_VEC cppVar_49824;
	BIT_VEC cppVar_49825;
	BIT_VEC cppVar_49826;
	BIT_VEC cppVar_49827;
	BIT_VEC cppVar_49828;
	BIT_VEC cppVar_49829;
	bool cppVar_49830;
	BIT_VEC cppVar_49831;
	BIT_VEC cppVar_49832;
	BIT_VEC cppVar_49807;
	BIT_VEC cppVar_49833;
	BIT_VEC cppVar_49834;
	BIT_VEC cppVar_49835;
	BIT_VEC cppVar_49836;
	BIT_VEC cppVar_49837;
	BIT_VEC cppVar_49839;
	BIT_VEC cppVar_49840;
	bool cppVar_49841;
	BIT_VEC cppVar_49843;
	BIT_VEC cppVar_49844;
	BIT_VEC cppVar_49845;
	BIT_VEC cppVar_49846;
	BIT_VEC cppVar_49847;
	BIT_VEC cppVar_49848;
	BIT_VEC cppVar_49849;
	BIT_VEC cppVar_49850;
	BIT_VEC cppVar_49851;
	bool cppVar_49852;
	BIT_VEC cppVar_49853;
	BIT_VEC cppVar_49854;
	BIT_VEC cppVar_49842;
	BIT_VEC cppVar_49856;
	BIT_VEC cppVar_49857;
	BIT_VEC cppVar_49858;
	BIT_VEC cppVar_49859;
	BIT_VEC cppVar_49860;
	BIT_VEC cppVar_49861;
	BIT_VEC cppVar_49862;
	BIT_VEC cppVar_49863;
	BIT_VEC cppVar_49864;
	BIT_VEC cppVar_49865;
	BIT_VEC cppVar_49866;
	bool cppVar_49867;
	BIT_VEC cppVar_49868;
	BIT_VEC cppVar_49869;
	BIT_VEC cppVar_49855;
	BIT_VEC cppVar_49870;
	BIT_VEC cppVar_49872;
	BIT_VEC cppVar_49873;
	BIT_VEC cppVar_49874;
	BIT_VEC cppVar_49875;
	BIT_VEC cppVar_49876;
	BIT_VEC cppVar_49877;
	BIT_VEC cppVar_49878;
	BIT_VEC cppVar_49879;
	BIT_VEC cppVar_49880;
	BIT_VEC cppVar_49881;
	BIT_VEC cppVar_49882;
	BIT_VEC cppVar_49883;
	BIT_VEC cppVar_49884;
	BIT_VEC cppVar_49885;
	BIT_VEC cppVar_49886;
	BIT_VEC cppVar_49887;
	BIT_VEC cppVar_49888;
	BIT_VEC cppVar_49889;
	BIT_VEC cppVar_49890;
	BIT_VEC cppVar_49891;
	BIT_VEC cppVar_49892;
	BIT_VEC cppVar_49893;
	bool cppVar_49894;
	BIT_VEC cppVar_49895;
	BIT_VEC cppVar_49896;
	BIT_VEC cppVar_49871;
	BIT_VEC cppVar_49897;
	BIT_VEC cppVar_49898;
	BIT_VEC cppVar_49899;
	BIT_VEC cppVar_49900;
	BIT_VEC cppVar_49901;
	BIT_VEC cppVar_49903;
	BIT_VEC cppVar_49904;
	bool cppVar_49905;
	BIT_VEC cppVar_49907;
	BIT_VEC cppVar_49908;
	BIT_VEC cppVar_49909;
	BIT_VEC cppVar_49910;
	BIT_VEC cppVar_49911;
	BIT_VEC cppVar_49912;
	BIT_VEC cppVar_49913;
	BIT_VEC cppVar_49914;
	BIT_VEC cppVar_49915;
	bool cppVar_49916;
	BIT_VEC cppVar_49917;
	BIT_VEC cppVar_49918;
	BIT_VEC cppVar_49906;
	BIT_VEC cppVar_49920;
	BIT_VEC cppVar_49921;
	BIT_VEC cppVar_49922;
	BIT_VEC cppVar_49923;
	BIT_VEC cppVar_49924;
	BIT_VEC cppVar_49925;
	BIT_VEC cppVar_49926;
	BIT_VEC cppVar_49927;
	BIT_VEC cppVar_49928;
	BIT_VEC cppVar_49929;
	BIT_VEC cppVar_49930;
	bool cppVar_49931;
	BIT_VEC cppVar_49932;
	BIT_VEC cppVar_49933;
	BIT_VEC cppVar_49919;
	BIT_VEC cppVar_49934;
	BIT_VEC cppVar_49936;
	BIT_VEC cppVar_49937;
	BIT_VEC cppVar_49938;
	BIT_VEC cppVar_49939;
	BIT_VEC cppVar_49940;
	BIT_VEC cppVar_49941;
	BIT_VEC cppVar_49942;
	BIT_VEC cppVar_49943;
	BIT_VEC cppVar_49944;
	BIT_VEC cppVar_49945;
	BIT_VEC cppVar_49946;
	BIT_VEC cppVar_49947;
	BIT_VEC cppVar_49948;
	BIT_VEC cppVar_49949;
	BIT_VEC cppVar_49950;
	BIT_VEC cppVar_49951;
	BIT_VEC cppVar_49952;
	BIT_VEC cppVar_49953;
	BIT_VEC cppVar_49954;
	BIT_VEC cppVar_49955;
	BIT_VEC cppVar_49956;
	BIT_VEC cppVar_49957;
	bool cppVar_49958;
	BIT_VEC cppVar_49959;
	BIT_VEC cppVar_49960;
	BIT_VEC cppVar_49935;
	BIT_VEC cppVar_49961;
	BIT_VEC cppVar_49962;
	BIT_VEC cppVar_49963;
	BIT_VEC cppVar_49964;
	BIT_VEC cppVar_49965;
	BIT_VEC cppVar_49967;
	BIT_VEC cppVar_49968;
	bool cppVar_49969;
	BIT_VEC cppVar_49971;
	BIT_VEC cppVar_49972;
	BIT_VEC cppVar_49973;
	BIT_VEC cppVar_49974;
	BIT_VEC cppVar_49975;
	BIT_VEC cppVar_49976;
	BIT_VEC cppVar_49977;
	BIT_VEC cppVar_49978;
	BIT_VEC cppVar_49979;
	bool cppVar_49980;
	BIT_VEC cppVar_49981;
	BIT_VEC cppVar_49982;
	BIT_VEC cppVar_49970;
	BIT_VEC cppVar_49984;
	BIT_VEC cppVar_49985;
	BIT_VEC cppVar_49986;
	BIT_VEC cppVar_49987;
	BIT_VEC cppVar_49988;
	BIT_VEC cppVar_49989;
	BIT_VEC cppVar_49990;
	BIT_VEC cppVar_49991;
	BIT_VEC cppVar_49992;
	BIT_VEC cppVar_49993;
	BIT_VEC cppVar_49994;
	bool cppVar_49995;
	BIT_VEC cppVar_49996;
	BIT_VEC cppVar_49997;
	BIT_VEC cppVar_49983;
	BIT_VEC cppVar_49998;
	BIT_VEC cppVar_50000;
	BIT_VEC cppVar_50001;
	BIT_VEC cppVar_50002;
	BIT_VEC cppVar_50003;
	BIT_VEC cppVar_50004;
	BIT_VEC cppVar_50005;
	BIT_VEC cppVar_50006;
	BIT_VEC cppVar_50007;
	BIT_VEC cppVar_50008;
	BIT_VEC cppVar_50009;
	BIT_VEC cppVar_50010;
	BIT_VEC cppVar_50011;
	BIT_VEC cppVar_50012;
	BIT_VEC cppVar_50013;
	BIT_VEC cppVar_50014;
	BIT_VEC cppVar_50015;
	BIT_VEC cppVar_50016;
	BIT_VEC cppVar_50017;
	BIT_VEC cppVar_50018;
	BIT_VEC cppVar_50019;
	BIT_VEC cppVar_50020;
	BIT_VEC cppVar_50021;
	bool cppVar_50022;
	BIT_VEC cppVar_50023;
	BIT_VEC cppVar_50024;
	BIT_VEC cppVar_49999;
	BIT_VEC cppVar_50025;
	BIT_VEC cppVar_50026;
	BIT_VEC cppVar_50027;
	BIT_VEC cppVar_50028;
	BIT_VEC cppVar_50029;
	BIT_VEC cppVar_50031;
	BIT_VEC cppVar_50032;
	bool cppVar_50033;
	BIT_VEC cppVar_50035;
	BIT_VEC cppVar_50036;
	BIT_VEC cppVar_50037;
	BIT_VEC cppVar_50038;
	BIT_VEC cppVar_50039;
	BIT_VEC cppVar_50040;
	BIT_VEC cppVar_50041;
	BIT_VEC cppVar_50042;
	BIT_VEC cppVar_50043;
	bool cppVar_50044;
	BIT_VEC cppVar_50045;
	BIT_VEC cppVar_50046;
	BIT_VEC cppVar_50034;
	BIT_VEC cppVar_50048;
	BIT_VEC cppVar_50049;
	BIT_VEC cppVar_50050;
	BIT_VEC cppVar_50051;
	BIT_VEC cppVar_50052;
	BIT_VEC cppVar_50053;
	BIT_VEC cppVar_50054;
	BIT_VEC cppVar_50055;
	BIT_VEC cppVar_50056;
	BIT_VEC cppVar_50057;
	BIT_VEC cppVar_50058;
	bool cppVar_50059;
	BIT_VEC cppVar_50060;
	BIT_VEC cppVar_50061;
	BIT_VEC cppVar_50047;
	BIT_VEC cppVar_50062;
	BIT_VEC cppVar_50064;
	BIT_VEC cppVar_50065;
	BIT_VEC cppVar_50066;
	BIT_VEC cppVar_50067;
	BIT_VEC cppVar_50068;
	BIT_VEC cppVar_50069;
	BIT_VEC cppVar_50070;
	BIT_VEC cppVar_50071;
	BIT_VEC cppVar_50072;
	BIT_VEC cppVar_50073;
	BIT_VEC cppVar_50074;
	BIT_VEC cppVar_50075;
	BIT_VEC cppVar_50076;
	BIT_VEC cppVar_50077;
	BIT_VEC cppVar_50078;
	BIT_VEC cppVar_50079;
	BIT_VEC cppVar_50080;
	BIT_VEC cppVar_50081;
	BIT_VEC cppVar_50082;
	BIT_VEC cppVar_50083;
	BIT_VEC cppVar_50084;
	BIT_VEC cppVar_50085;
	bool cppVar_50086;
	BIT_VEC cppVar_50087;
	BIT_VEC cppVar_50088;
	BIT_VEC cppVar_50063;
	BIT_VEC cppVar_50089;
	BIT_VEC cppVar_50090;
	BIT_VEC cppVar_50091;
	BIT_VEC cppVar_50092;
	BIT_VEC cppVar_50093;
	BIT_VEC cppVar_50095;
	BIT_VEC cppVar_50096;
	bool cppVar_50097;
	BIT_VEC cppVar_50099;
	BIT_VEC cppVar_50100;
	BIT_VEC cppVar_50101;
	BIT_VEC cppVar_50102;
	BIT_VEC cppVar_50103;
	BIT_VEC cppVar_50104;
	BIT_VEC cppVar_50105;
	BIT_VEC cppVar_50106;
	BIT_VEC cppVar_50107;
	bool cppVar_50108;
	BIT_VEC cppVar_50109;
	BIT_VEC cppVar_50110;
	BIT_VEC cppVar_50098;
	BIT_VEC cppVar_50112;
	BIT_VEC cppVar_50113;
	BIT_VEC cppVar_50114;
	BIT_VEC cppVar_50115;
	BIT_VEC cppVar_50116;
	BIT_VEC cppVar_50117;
	BIT_VEC cppVar_50118;
	BIT_VEC cppVar_50119;
	BIT_VEC cppVar_50120;
	BIT_VEC cppVar_50121;
	BIT_VEC cppVar_50122;
	bool cppVar_50123;
	BIT_VEC cppVar_50124;
	BIT_VEC cppVar_50125;
	BIT_VEC cppVar_50111;
	BIT_VEC cppVar_50126;
	BIT_VEC cppVar_50128;
	BIT_VEC cppVar_50129;
	BIT_VEC cppVar_50130;
	BIT_VEC cppVar_50131;
	BIT_VEC cppVar_50132;
	BIT_VEC cppVar_50133;
	BIT_VEC cppVar_50134;
	BIT_VEC cppVar_50135;
	BIT_VEC cppVar_50136;
	BIT_VEC cppVar_50137;
	BIT_VEC cppVar_50138;
	BIT_VEC cppVar_50139;
	BIT_VEC cppVar_50140;
	BIT_VEC cppVar_50141;
	BIT_VEC cppVar_50142;
	BIT_VEC cppVar_50143;
	BIT_VEC cppVar_50144;
	BIT_VEC cppVar_50145;
	BIT_VEC cppVar_50146;
	BIT_VEC cppVar_50147;
	BIT_VEC cppVar_50148;
	BIT_VEC cppVar_50149;
	bool cppVar_50150;
	BIT_VEC cppVar_50151;
	BIT_VEC cppVar_50152;
	BIT_VEC cppVar_50127;
	BIT_VEC cppVar_50153;
	BIT_VEC cppVar_50154;
	BIT_VEC cppVar_50155;
	BIT_VEC cppVar_50156;
	BIT_VEC cppVar_50157;
	BIT_VEC cppVar_50159;
	BIT_VEC cppVar_50160;
	bool cppVar_50161;
	BIT_VEC cppVar_50163;
	BIT_VEC cppVar_50164;
	BIT_VEC cppVar_50165;
	BIT_VEC cppVar_50166;
	BIT_VEC cppVar_50167;
	BIT_VEC cppVar_50168;
	BIT_VEC cppVar_50169;
	BIT_VEC cppVar_50170;
	BIT_VEC cppVar_50171;
	BIT_VEC cppVar_50172;
	BIT_VEC cppVar_50173;
	BIT_VEC cppVar_50174;
	bool cppVar_50175;
	BIT_VEC cppVar_50176;
	BIT_VEC cppVar_50177;
	BIT_VEC cppVar_50162;
	BIT_VEC cppVar_50179;
	BIT_VEC cppVar_50180;
	BIT_VEC cppVar_50181;
	BIT_VEC cppVar_50182;
	BIT_VEC cppVar_50183;
	BIT_VEC cppVar_50184;
	BIT_VEC cppVar_50185;
	BIT_VEC cppVar_50186;
	BIT_VEC cppVar_50187;
	BIT_VEC cppVar_50188;
	BIT_VEC cppVar_50189;
	BIT_VEC cppVar_50190;
	bool cppVar_50191;
	BIT_VEC cppVar_50192;
	BIT_VEC cppVar_50193;
	BIT_VEC cppVar_50178;
	BIT_VEC cppVar_50194;
	BIT_VEC cppVar_50196;
	BIT_VEC cppVar_50197;
	BIT_VEC cppVar_50198;
	BIT_VEC cppVar_50199;
	BIT_VEC cppVar_50200;
	BIT_VEC cppVar_50201;
	BIT_VEC cppVar_50202;
	BIT_VEC cppVar_50203;
	BIT_VEC cppVar_50204;
	BIT_VEC cppVar_50205;
	BIT_VEC cppVar_50206;
	BIT_VEC cppVar_50207;
	BIT_VEC cppVar_50208;
	BIT_VEC cppVar_50209;
	BIT_VEC cppVar_50210;
	BIT_VEC cppVar_50211;
	BIT_VEC cppVar_50212;
	BIT_VEC cppVar_50213;
	BIT_VEC cppVar_50214;
	BIT_VEC cppVar_50215;
	BIT_VEC cppVar_50216;
	BIT_VEC cppVar_50217;
	BIT_VEC cppVar_50218;
	BIT_VEC cppVar_50219;
	bool cppVar_50220;
	BIT_VEC cppVar_50221;
	BIT_VEC cppVar_50222;
	BIT_VEC cppVar_50195;
	BIT_VEC cppVar_50223;
	BIT_VEC cppVar_50224;
	BIT_VEC cppVar_50225;
	BIT_VEC cppVar_50226;
	BIT_VEC cppVar_50227;
	BIT_VEC cppVar_50229;
	BIT_VEC cppVar_50230;
	bool cppVar_50231;
	BIT_VEC cppVar_50233;
	BIT_VEC cppVar_50234;
	BIT_VEC cppVar_50235;
	BIT_VEC cppVar_50236;
	BIT_VEC cppVar_50237;
	BIT_VEC cppVar_50238;
	BIT_VEC cppVar_50239;
	BIT_VEC cppVar_50240;
	BIT_VEC cppVar_50241;
	BIT_VEC cppVar_50242;
	BIT_VEC cppVar_50243;
	BIT_VEC cppVar_50244;
	bool cppVar_50245;
	BIT_VEC cppVar_50246;
	BIT_VEC cppVar_50247;
	BIT_VEC cppVar_50232;
	BIT_VEC cppVar_50249;
	BIT_VEC cppVar_50250;
	BIT_VEC cppVar_50251;
	BIT_VEC cppVar_50252;
	BIT_VEC cppVar_50253;
	BIT_VEC cppVar_50254;
	BIT_VEC cppVar_50255;
	BIT_VEC cppVar_50256;
	BIT_VEC cppVar_50257;
	BIT_VEC cppVar_50258;
	BIT_VEC cppVar_50259;
	BIT_VEC cppVar_50260;
	bool cppVar_50261;
	BIT_VEC cppVar_50262;
	BIT_VEC cppVar_50263;
	BIT_VEC cppVar_50248;
	BIT_VEC cppVar_50264;
	BIT_VEC cppVar_50266;
	BIT_VEC cppVar_50267;
	BIT_VEC cppVar_50268;
	BIT_VEC cppVar_50269;
	BIT_VEC cppVar_50270;
	BIT_VEC cppVar_50271;
	BIT_VEC cppVar_50272;
	BIT_VEC cppVar_50273;
	BIT_VEC cppVar_50274;
	BIT_VEC cppVar_50275;
	BIT_VEC cppVar_50276;
	BIT_VEC cppVar_50277;
	BIT_VEC cppVar_50278;
	BIT_VEC cppVar_50279;
	BIT_VEC cppVar_50280;
	BIT_VEC cppVar_50281;
	BIT_VEC cppVar_50282;
	BIT_VEC cppVar_50283;
	BIT_VEC cppVar_50284;
	BIT_VEC cppVar_50285;
	BIT_VEC cppVar_50286;
	BIT_VEC cppVar_50287;
	BIT_VEC cppVar_50288;
	BIT_VEC cppVar_50289;
	bool cppVar_50290;
	BIT_VEC cppVar_50291;
	BIT_VEC cppVar_50292;
	BIT_VEC cppVar_50265;
	BIT_VEC cppVar_50293;
	BIT_VEC cppVar_50294;
	BIT_VEC cppVar_50295;
	BIT_VEC cppVar_50296;
	BIT_VEC cppVar_50297;
	BIT_VEC cppVar_50299;
	BIT_VEC cppVar_50300;
	bool cppVar_50301;
	BIT_VEC cppVar_50304;
	BIT_VEC cppVar_50305;
	BIT_VEC cppVar_50306;
	BIT_VEC cppVar_50307;
	BIT_VEC cppVar_50308;
	bool cppVar_50309;
	BIT_VEC cppVar_50310;
	BIT_VEC cppVar_50311;
	BIT_VEC cppVar_50312;
	BIT_VEC cppVar_50314;
	BIT_VEC cppVar_50315;
	BIT_VEC cppVar_50316;
	bool cppVar_50317;
	BIT_VEC cppVar_50319;
	BIT_VEC cppVar_50320;
	BIT_VEC cppVar_50321;
	bool cppVar_50322;
	BIT_VEC cppVar_50324;
	BIT_VEC cppVar_50325;
	BIT_VEC cppVar_50326;
	bool cppVar_50327;
	BIT_VEC cppVar_50329;
	BIT_VEC cppVar_50330;
	BIT_VEC cppVar_50331;
	bool cppVar_50332;
	BIT_VEC cppVar_50334;
	BIT_VEC cppVar_50335;
	BIT_VEC cppVar_50336;
	bool cppVar_50337;
	BIT_VEC cppVar_50339;
	BIT_VEC cppVar_50340;
	BIT_VEC cppVar_50341;
	bool cppVar_50342;
	BIT_VEC cppVar_50344;
	BIT_VEC cppVar_50345;
	BIT_VEC cppVar_50346;
	bool cppVar_50347;
	BIT_VEC cppVar_50349;
	BIT_VEC cppVar_50350;
	BIT_VEC cppVar_50351;
	bool cppVar_50352;
	BIT_VEC cppVar_50354;
	BIT_VEC cppVar_50355;
	BIT_VEC cppVar_50356;
	bool cppVar_50357;
	BIT_VEC cppVar_50359;
	BIT_VEC cppVar_50360;
	BIT_VEC cppVar_50361;
	bool cppVar_50362;
	BIT_VEC cppVar_50364;
	BIT_VEC cppVar_50365;
	BIT_VEC cppVar_50366;
	bool cppVar_50367;
	BIT_VEC cppVar_50369;
	BIT_VEC cppVar_50370;
	BIT_VEC cppVar_50371;
	bool cppVar_50372;
	BIT_VEC cppVar_50374;
	BIT_VEC cppVar_50375;
	BIT_VEC cppVar_50376;
	bool cppVar_50377;
	BIT_VEC cppVar_50379;
	BIT_VEC cppVar_50380;
	BIT_VEC cppVar_50381;
	bool cppVar_50382;
	BIT_VEC cppVar_50384;
	BIT_VEC cppVar_50385;
	BIT_VEC cppVar_50386;
	bool cppVar_50387;
	BIT_VEC cppVar_50389;
	BIT_VEC cppVar_50390;
	BIT_VEC cppVar_50391;
	bool cppVar_50392;
	BIT_VEC cppVar_50394;
	BIT_VEC cppVar_50395;
	BIT_VEC cppVar_50396;
	bool cppVar_50397;
	BIT_VEC cppVar_50399;
	BIT_VEC cppVar_50400;
	BIT_VEC cppVar_50401;
	bool cppVar_50402;
	BIT_VEC cppVar_50404;
	BIT_VEC cppVar_50405;
	BIT_VEC cppVar_50406;
	bool cppVar_50407;
	BIT_VEC cppVar_50409;
	BIT_VEC cppVar_50410;
	BIT_VEC cppVar_50411;
	bool cppVar_50412;
	BIT_VEC cppVar_50414;
	BIT_VEC cppVar_50415;
	BIT_VEC cppVar_50416;
	bool cppVar_50417;
	BIT_VEC cppVar_50418;
	BIT_VEC cppVar_50413;
	BIT_VEC cppVar_50408;
	BIT_VEC cppVar_50403;
	BIT_VEC cppVar_50398;
	BIT_VEC cppVar_50393;
	BIT_VEC cppVar_50388;
	BIT_VEC cppVar_50383;
	BIT_VEC cppVar_50378;
	BIT_VEC cppVar_50373;
	BIT_VEC cppVar_50368;
	BIT_VEC cppVar_50363;
	BIT_VEC cppVar_50358;
	BIT_VEC cppVar_50353;
	BIT_VEC cppVar_50348;
	BIT_VEC cppVar_50343;
	BIT_VEC cppVar_50338;
	BIT_VEC cppVar_50333;
	BIT_VEC cppVar_50328;
	BIT_VEC cppVar_50323;
	BIT_VEC cppVar_50318;
	BIT_VEC cppVar_50313;
	BIT_VEC cppVar_50303;
	BIT_VEC cppVar_50419;
	BIT_VEC cppVar_50420;
	BIT_VEC cppVar_50421;
	bool cppVar_50422;
	BIT_VEC cppVar_50423;
	BIT_VEC cppVar_50424;
	BIT_VEC cppVar_50302;
	BIT_VEC cppVar_50426;
	BIT_VEC cppVar_50427;
	BIT_VEC cppVar_50429;
	BIT_VEC cppVar_50430;
	BIT_VEC cppVar_50431;
	bool cppVar_50432;
	BIT_VEC cppVar_50433;
	BIT_VEC cppVar_50434;
	BIT_VEC cppVar_50435;
	BIT_VEC cppVar_50437;
	BIT_VEC cppVar_50438;
	bool cppVar_50439;
	BIT_VEC cppVar_50441;
	BIT_VEC cppVar_50442;
	bool cppVar_50443;
	BIT_VEC cppVar_50445;
	BIT_VEC cppVar_50446;
	bool cppVar_50447;
	BIT_VEC cppVar_50449;
	BIT_VEC cppVar_50450;
	bool cppVar_50451;
	BIT_VEC cppVar_50453;
	BIT_VEC cppVar_50454;
	bool cppVar_50455;
	BIT_VEC cppVar_50457;
	BIT_VEC cppVar_50458;
	bool cppVar_50459;
	BIT_VEC cppVar_50461;
	BIT_VEC cppVar_50462;
	bool cppVar_50463;
	BIT_VEC cppVar_50465;
	BIT_VEC cppVar_50466;
	bool cppVar_50467;
	BIT_VEC cppVar_50469;
	BIT_VEC cppVar_50470;
	bool cppVar_50471;
	BIT_VEC cppVar_50473;
	BIT_VEC cppVar_50474;
	bool cppVar_50475;
	BIT_VEC cppVar_50477;
	BIT_VEC cppVar_50478;
	bool cppVar_50479;
	BIT_VEC cppVar_50481;
	BIT_VEC cppVar_50482;
	bool cppVar_50483;
	BIT_VEC cppVar_50485;
	BIT_VEC cppVar_50486;
	bool cppVar_50487;
	BIT_VEC cppVar_50489;
	BIT_VEC cppVar_50490;
	bool cppVar_50491;
	BIT_VEC cppVar_50493;
	BIT_VEC cppVar_50494;
	bool cppVar_50495;
	BIT_VEC cppVar_50497;
	BIT_VEC cppVar_50498;
	bool cppVar_50499;
	BIT_VEC cppVar_50501;
	BIT_VEC cppVar_50502;
	bool cppVar_50503;
	BIT_VEC cppVar_50505;
	BIT_VEC cppVar_50506;
	bool cppVar_50507;
	BIT_VEC cppVar_50509;
	BIT_VEC cppVar_50510;
	bool cppVar_50511;
	BIT_VEC cppVar_50513;
	BIT_VEC cppVar_50514;
	bool cppVar_50515;
	BIT_VEC cppVar_50517;
	BIT_VEC cppVar_50518;
	bool cppVar_50519;
	BIT_VEC cppVar_50516;
	BIT_VEC cppVar_50512;
	BIT_VEC cppVar_50508;
	BIT_VEC cppVar_50504;
	BIT_VEC cppVar_50500;
	BIT_VEC cppVar_50496;
	BIT_VEC cppVar_50492;
	BIT_VEC cppVar_50488;
	BIT_VEC cppVar_50484;
	BIT_VEC cppVar_50480;
	BIT_VEC cppVar_50476;
	BIT_VEC cppVar_50472;
	BIT_VEC cppVar_50468;
	BIT_VEC cppVar_50464;
	BIT_VEC cppVar_50460;
	BIT_VEC cppVar_50456;
	BIT_VEC cppVar_50452;
	BIT_VEC cppVar_50448;
	BIT_VEC cppVar_50444;
	BIT_VEC cppVar_50440;
	BIT_VEC cppVar_50436;
	BIT_VEC cppVar_50428;
	BIT_VEC cppVar_50520;
	BIT_VEC cppVar_50521;
	BIT_VEC cppVar_50522;
	BIT_VEC cppVar_50523;
	BIT_VEC cppVar_50524;
	bool cppVar_50525;
	BIT_VEC cppVar_50526;
	BIT_VEC cppVar_50527;
	BIT_VEC cppVar_50425;
	BIT_VEC cppVar_50528;
	BIT_VEC cppVar_50530;
	BIT_VEC cppVar_50532;
	BIT_VEC cppVar_50533;
	BIT_VEC cppVar_50534;
	bool cppVar_50535;
	BIT_VEC cppVar_50536;
	BIT_VEC cppVar_50537;
	BIT_VEC cppVar_50538;
	BIT_VEC cppVar_50540;
	BIT_VEC cppVar_50541;
	bool cppVar_50542;
	BIT_VEC cppVar_50544;
	BIT_VEC cppVar_50545;
	bool cppVar_50546;
	BIT_VEC cppVar_50548;
	BIT_VEC cppVar_50549;
	bool cppVar_50550;
	BIT_VEC cppVar_50552;
	BIT_VEC cppVar_50553;
	bool cppVar_50554;
	BIT_VEC cppVar_50556;
	BIT_VEC cppVar_50557;
	bool cppVar_50558;
	BIT_VEC cppVar_50560;
	BIT_VEC cppVar_50561;
	bool cppVar_50562;
	BIT_VEC cppVar_50564;
	BIT_VEC cppVar_50565;
	bool cppVar_50566;
	BIT_VEC cppVar_50568;
	BIT_VEC cppVar_50569;
	bool cppVar_50570;
	BIT_VEC cppVar_50572;
	BIT_VEC cppVar_50573;
	bool cppVar_50574;
	BIT_VEC cppVar_50576;
	BIT_VEC cppVar_50577;
	bool cppVar_50578;
	BIT_VEC cppVar_50580;
	BIT_VEC cppVar_50581;
	bool cppVar_50582;
	BIT_VEC cppVar_50584;
	BIT_VEC cppVar_50585;
	bool cppVar_50586;
	BIT_VEC cppVar_50588;
	BIT_VEC cppVar_50589;
	bool cppVar_50590;
	BIT_VEC cppVar_50592;
	BIT_VEC cppVar_50593;
	bool cppVar_50594;
	BIT_VEC cppVar_50596;
	BIT_VEC cppVar_50597;
	bool cppVar_50598;
	BIT_VEC cppVar_50600;
	BIT_VEC cppVar_50601;
	bool cppVar_50602;
	BIT_VEC cppVar_50604;
	BIT_VEC cppVar_50605;
	bool cppVar_50606;
	BIT_VEC cppVar_50608;
	BIT_VEC cppVar_50609;
	bool cppVar_50610;
	BIT_VEC cppVar_50612;
	BIT_VEC cppVar_50613;
	bool cppVar_50614;
	BIT_VEC cppVar_50616;
	BIT_VEC cppVar_50617;
	bool cppVar_50618;
	BIT_VEC cppVar_50620;
	BIT_VEC cppVar_50621;
	bool cppVar_50622;
	BIT_VEC cppVar_50619;
	BIT_VEC cppVar_50615;
	BIT_VEC cppVar_50611;
	BIT_VEC cppVar_50607;
	BIT_VEC cppVar_50603;
	BIT_VEC cppVar_50599;
	BIT_VEC cppVar_50595;
	BIT_VEC cppVar_50591;
	BIT_VEC cppVar_50587;
	BIT_VEC cppVar_50583;
	BIT_VEC cppVar_50579;
	BIT_VEC cppVar_50575;
	BIT_VEC cppVar_50571;
	BIT_VEC cppVar_50567;
	BIT_VEC cppVar_50563;
	BIT_VEC cppVar_50559;
	BIT_VEC cppVar_50555;
	BIT_VEC cppVar_50551;
	BIT_VEC cppVar_50547;
	BIT_VEC cppVar_50543;
	BIT_VEC cppVar_50539;
	BIT_VEC cppVar_50531;
	BIT_VEC cppVar_50623;
	BIT_VEC cppVar_50624;
	BIT_VEC cppVar_50625;
	BIT_VEC cppVar_50626;
	BIT_VEC cppVar_50627;
	BIT_VEC cppVar_50628;
	BIT_VEC cppVar_50629;
	BIT_VEC cppVar_50631;
	BIT_VEC cppVar_50632;
	BIT_VEC cppVar_50633;
	bool cppVar_50634;
	BIT_VEC cppVar_50635;
	BIT_VEC cppVar_50636;
	BIT_VEC cppVar_50637;
	BIT_VEC cppVar_50639;
	BIT_VEC cppVar_50640;
	bool cppVar_50641;
	BIT_VEC cppVar_50643;
	BIT_VEC cppVar_50644;
	bool cppVar_50645;
	BIT_VEC cppVar_50647;
	BIT_VEC cppVar_50648;
	bool cppVar_50649;
	BIT_VEC cppVar_50651;
	BIT_VEC cppVar_50652;
	bool cppVar_50653;
	BIT_VEC cppVar_50655;
	BIT_VEC cppVar_50656;
	bool cppVar_50657;
	BIT_VEC cppVar_50659;
	BIT_VEC cppVar_50660;
	bool cppVar_50661;
	BIT_VEC cppVar_50663;
	BIT_VEC cppVar_50664;
	bool cppVar_50665;
	BIT_VEC cppVar_50667;
	BIT_VEC cppVar_50668;
	bool cppVar_50669;
	BIT_VEC cppVar_50671;
	BIT_VEC cppVar_50672;
	bool cppVar_50673;
	BIT_VEC cppVar_50675;
	BIT_VEC cppVar_50676;
	bool cppVar_50677;
	BIT_VEC cppVar_50679;
	BIT_VEC cppVar_50680;
	bool cppVar_50681;
	BIT_VEC cppVar_50683;
	BIT_VEC cppVar_50684;
	bool cppVar_50685;
	BIT_VEC cppVar_50687;
	BIT_VEC cppVar_50688;
	bool cppVar_50689;
	BIT_VEC cppVar_50691;
	BIT_VEC cppVar_50692;
	bool cppVar_50693;
	BIT_VEC cppVar_50695;
	BIT_VEC cppVar_50696;
	bool cppVar_50697;
	BIT_VEC cppVar_50699;
	BIT_VEC cppVar_50700;
	bool cppVar_50701;
	BIT_VEC cppVar_50703;
	BIT_VEC cppVar_50704;
	bool cppVar_50705;
	BIT_VEC cppVar_50707;
	BIT_VEC cppVar_50708;
	bool cppVar_50709;
	BIT_VEC cppVar_50711;
	BIT_VEC cppVar_50712;
	bool cppVar_50713;
	BIT_VEC cppVar_50715;
	BIT_VEC cppVar_50716;
	bool cppVar_50717;
	BIT_VEC cppVar_50719;
	BIT_VEC cppVar_50720;
	bool cppVar_50721;
	BIT_VEC cppVar_50718;
	BIT_VEC cppVar_50714;
	BIT_VEC cppVar_50710;
	BIT_VEC cppVar_50706;
	BIT_VEC cppVar_50702;
	BIT_VEC cppVar_50698;
	BIT_VEC cppVar_50694;
	BIT_VEC cppVar_50690;
	BIT_VEC cppVar_50686;
	BIT_VEC cppVar_50682;
	BIT_VEC cppVar_50678;
	BIT_VEC cppVar_50674;
	BIT_VEC cppVar_50670;
	BIT_VEC cppVar_50666;
	BIT_VEC cppVar_50662;
	BIT_VEC cppVar_50658;
	BIT_VEC cppVar_50654;
	BIT_VEC cppVar_50650;
	BIT_VEC cppVar_50646;
	BIT_VEC cppVar_50642;
	BIT_VEC cppVar_50638;
	BIT_VEC cppVar_50630;
	BIT_VEC cppVar_50722;
	BIT_VEC cppVar_50723;
	BIT_VEC cppVar_50724;
	BIT_VEC cppVar_50725;
	BIT_VEC cppVar_50726;
	BIT_VEC cppVar_50727;
	bool cppVar_50728;
	BIT_VEC cppVar_50729;
	BIT_VEC cppVar_50730;
	BIT_VEC cppVar_50529;
	BIT_VEC cppVar_50731;
	BIT_VEC cppVar_50732;
	BIT_VEC cppVar_50733;
	BIT_VEC cppVar_50734;
	BIT_VEC cppVar_50735;
	BIT_VEC cppVar_50737;
	BIT_VEC cppVar_50738;
	bool cppVar_50739;
	BIT_VEC cppVar_50741;
	BIT_VEC cppVar_50742;
	BIT_VEC cppVar_50743;
	BIT_VEC cppVar_50744;
	BIT_VEC cppVar_50745;
	BIT_VEC cppVar_50746;
	bool cppVar_50747;
	BIT_VEC cppVar_50748;
	BIT_VEC cppVar_50749;
	BIT_VEC cppVar_50740;
	BIT_VEC cppVar_50751;
	BIT_VEC cppVar_50752;
	BIT_VEC cppVar_50753;
	BIT_VEC cppVar_50754;
	BIT_VEC cppVar_50755;
	BIT_VEC cppVar_50756;
	BIT_VEC cppVar_50757;
	BIT_VEC cppVar_50758;
	BIT_VEC cppVar_50759;
	bool cppVar_50760;
	BIT_VEC cppVar_50761;
	BIT_VEC cppVar_50762;
	BIT_VEC cppVar_50750;
	BIT_VEC cppVar_50763;
	BIT_VEC cppVar_50765;
	BIT_VEC cppVar_50766;
	BIT_VEC cppVar_50767;
	BIT_VEC cppVar_50768;
	BIT_VEC cppVar_50769;
	BIT_VEC cppVar_50770;
	BIT_VEC cppVar_50771;
	BIT_VEC cppVar_50772;
	BIT_VEC cppVar_50773;
	BIT_VEC cppVar_50774;
	BIT_VEC cppVar_50775;
	BIT_VEC cppVar_50776;
	BIT_VEC cppVar_50777;
	BIT_VEC cppVar_50778;
	BIT_VEC cppVar_50779;
	BIT_VEC cppVar_50780;
	BIT_VEC cppVar_50781;
	BIT_VEC cppVar_50782;
	bool cppVar_50783;
	BIT_VEC cppVar_50784;
	BIT_VEC cppVar_50785;
	BIT_VEC cppVar_50764;
	BIT_VEC cppVar_50786;
	BIT_VEC cppVar_50787;
	BIT_VEC cppVar_50788;
	BIT_VEC cppVar_50789;
	BIT_VEC cppVar_50790;
	BIT_VEC cppVar_50792;
	BIT_VEC cppVar_50793;
	bool cppVar_50794;
	BIT_VEC cppVar_50797;
	BIT_VEC cppVar_50798;
	BIT_VEC cppVar_50799;
	BIT_VEC cppVar_50800;
	BIT_VEC cppVar_50801;
	bool cppVar_50802;
	BIT_VEC cppVar_50803;
	BIT_VEC cppVar_50804;
	BIT_VEC cppVar_50805;
	BIT_VEC cppVar_50806;
	BIT_VEC cppVar_50807;
	BIT_VEC cppVar_50808;
	BIT_VEC cppVar_50809;
	BIT_VEC cppVar_50810;
	BIT_VEC cppVar_50811;
	BIT_VEC cppVar_50812;
	BIT_VEC cppVar_50813;
	BIT_VEC cppVar_50796;
	BIT_VEC cppVar_50814;
	bool cppVar_50815;
	BIT_VEC cppVar_50816;
	BIT_VEC cppVar_50817;
	BIT_VEC cppVar_50818;
	BIT_VEC cppVar_50819;
	BIT_VEC cppVar_50820;
	BIT_VEC cppVar_50821;
	BIT_VEC cppVar_50822;
	BIT_VEC cppVar_50825;
	BIT_VEC cppVar_50826;
	BIT_VEC cppVar_50827;
	bool cppVar_50828;
	BIT_VEC cppVar_50829;
	BIT_VEC cppVar_50830;
	BIT_VEC cppVar_50831;
	BIT_VEC cppVar_50832;
	BIT_VEC cppVar_50833;
	BIT_VEC cppVar_50834;
	BIT_VEC cppVar_50835;
	BIT_VEC cppVar_50836;
	BIT_VEC cppVar_50837;
	BIT_VEC cppVar_50824;
	BIT_VEC cppVar_50838;
	BIT_VEC cppVar_50839;
	bool cppVar_50840;
	BIT_VEC cppVar_50842;
	BIT_VEC cppVar_50843;
	BIT_VEC cppVar_50844;
	bool cppVar_50845;
	BIT_VEC cppVar_50846;
	BIT_VEC cppVar_50847;
	BIT_VEC cppVar_50848;
	BIT_VEC cppVar_50849;
	BIT_VEC cppVar_50850;
	BIT_VEC cppVar_50851;
	BIT_VEC cppVar_50852;
	BIT_VEC cppVar_50853;
	BIT_VEC cppVar_50854;
	BIT_VEC cppVar_50841;
	BIT_VEC cppVar_50855;
	BIT_VEC cppVar_50858;
	BIT_VEC cppVar_50859;
	BIT_VEC cppVar_50860;
	bool cppVar_50861;
	BIT_VEC cppVar_50862;
	BIT_VEC cppVar_50863;
	BIT_VEC cppVar_50864;
	BIT_VEC cppVar_50865;
	BIT_VEC cppVar_50866;
	BIT_VEC cppVar_50867;
	BIT_VEC cppVar_50868;
	BIT_VEC cppVar_50869;
	BIT_VEC cppVar_50870;
	BIT_VEC cppVar_50857;
	BIT_VEC cppVar_50871;
	bool cppVar_50872;
	BIT_VEC cppVar_50875;
	BIT_VEC cppVar_50876;
	BIT_VEC cppVar_50877;
	bool cppVar_50878;
	BIT_VEC cppVar_50879;
	BIT_VEC cppVar_50880;
	BIT_VEC cppVar_50881;
	BIT_VEC cppVar_50882;
	BIT_VEC cppVar_50883;
	BIT_VEC cppVar_50884;
	BIT_VEC cppVar_50885;
	BIT_VEC cppVar_50886;
	BIT_VEC cppVar_50887;
	BIT_VEC cppVar_50874;
	BIT_VEC cppVar_50888;
	bool cppVar_50889;
	BIT_VEC cppVar_50892;
	BIT_VEC cppVar_50893;
	BIT_VEC cppVar_50894;
	bool cppVar_50895;
	BIT_VEC cppVar_50896;
	BIT_VEC cppVar_50897;
	BIT_VEC cppVar_50898;
	BIT_VEC cppVar_50899;
	BIT_VEC cppVar_50900;
	BIT_VEC cppVar_50901;
	BIT_VEC cppVar_50902;
	BIT_VEC cppVar_50903;
	BIT_VEC cppVar_50904;
	BIT_VEC cppVar_50891;
	BIT_VEC cppVar_50905;
	bool cppVar_50906;
	BIT_VEC cppVar_50909;
	BIT_VEC cppVar_50910;
	BIT_VEC cppVar_50911;
	bool cppVar_50912;
	BIT_VEC cppVar_50913;
	BIT_VEC cppVar_50914;
	BIT_VEC cppVar_50915;
	BIT_VEC cppVar_50916;
	BIT_VEC cppVar_50917;
	BIT_VEC cppVar_50918;
	BIT_VEC cppVar_50919;
	BIT_VEC cppVar_50920;
	BIT_VEC cppVar_50921;
	BIT_VEC cppVar_50908;
	BIT_VEC cppVar_50922;
	bool cppVar_50923;
	BIT_VEC cppVar_50926;
	BIT_VEC cppVar_50927;
	BIT_VEC cppVar_50928;
	bool cppVar_50929;
	BIT_VEC cppVar_50930;
	BIT_VEC cppVar_50931;
	BIT_VEC cppVar_50932;
	BIT_VEC cppVar_50933;
	BIT_VEC cppVar_50934;
	BIT_VEC cppVar_50935;
	BIT_VEC cppVar_50936;
	BIT_VEC cppVar_50937;
	BIT_VEC cppVar_50938;
	BIT_VEC cppVar_50925;
	BIT_VEC cppVar_50939;
	bool cppVar_50940;
	BIT_VEC cppVar_50943;
	BIT_VEC cppVar_50944;
	BIT_VEC cppVar_50945;
	bool cppVar_50946;
	BIT_VEC cppVar_50947;
	BIT_VEC cppVar_50948;
	BIT_VEC cppVar_50949;
	BIT_VEC cppVar_50950;
	BIT_VEC cppVar_50951;
	BIT_VEC cppVar_50952;
	BIT_VEC cppVar_50953;
	BIT_VEC cppVar_50954;
	BIT_VEC cppVar_50955;
	BIT_VEC cppVar_50942;
	BIT_VEC cppVar_50956;
	bool cppVar_50957;
	BIT_VEC cppVar_50960;
	BIT_VEC cppVar_50961;
	BIT_VEC cppVar_50962;
	bool cppVar_50963;
	BIT_VEC cppVar_50964;
	BIT_VEC cppVar_50965;
	BIT_VEC cppVar_50966;
	BIT_VEC cppVar_50967;
	BIT_VEC cppVar_50968;
	BIT_VEC cppVar_50969;
	BIT_VEC cppVar_50970;
	BIT_VEC cppVar_50971;
	BIT_VEC cppVar_50972;
	BIT_VEC cppVar_50959;
	BIT_VEC cppVar_50973;
	bool cppVar_50974;
	BIT_VEC cppVar_50977;
	BIT_VEC cppVar_50978;
	BIT_VEC cppVar_50979;
	bool cppVar_50980;
	BIT_VEC cppVar_50981;
	BIT_VEC cppVar_50982;
	BIT_VEC cppVar_50983;
	BIT_VEC cppVar_50984;
	BIT_VEC cppVar_50985;
	BIT_VEC cppVar_50986;
	BIT_VEC cppVar_50987;
	BIT_VEC cppVar_50988;
	BIT_VEC cppVar_50989;
	BIT_VEC cppVar_50976;
	BIT_VEC cppVar_50990;
	bool cppVar_50991;
	BIT_VEC cppVar_50994;
	BIT_VEC cppVar_50995;
	BIT_VEC cppVar_50996;
	bool cppVar_50997;
	BIT_VEC cppVar_50998;
	BIT_VEC cppVar_50999;
	BIT_VEC cppVar_51000;
	BIT_VEC cppVar_51001;
	BIT_VEC cppVar_51002;
	BIT_VEC cppVar_51003;
	BIT_VEC cppVar_51004;
	BIT_VEC cppVar_51005;
	BIT_VEC cppVar_51006;
	BIT_VEC cppVar_50993;
	BIT_VEC cppVar_51007;
	bool cppVar_51008;
	BIT_VEC cppVar_51011;
	BIT_VEC cppVar_51012;
	BIT_VEC cppVar_51013;
	bool cppVar_51014;
	BIT_VEC cppVar_51015;
	BIT_VEC cppVar_51016;
	BIT_VEC cppVar_51017;
	BIT_VEC cppVar_51018;
	BIT_VEC cppVar_51019;
	BIT_VEC cppVar_51020;
	BIT_VEC cppVar_51021;
	BIT_VEC cppVar_51022;
	BIT_VEC cppVar_51023;
	BIT_VEC cppVar_51010;
	BIT_VEC cppVar_51024;
	bool cppVar_51025;
	BIT_VEC cppVar_51028;
	BIT_VEC cppVar_51029;
	BIT_VEC cppVar_51030;
	bool cppVar_51031;
	BIT_VEC cppVar_51032;
	BIT_VEC cppVar_51033;
	BIT_VEC cppVar_51034;
	BIT_VEC cppVar_51035;
	BIT_VEC cppVar_51036;
	BIT_VEC cppVar_51037;
	BIT_VEC cppVar_51038;
	BIT_VEC cppVar_51039;
	BIT_VEC cppVar_51040;
	BIT_VEC cppVar_51027;
	BIT_VEC cppVar_51041;
	bool cppVar_51042;
	BIT_VEC cppVar_51045;
	BIT_VEC cppVar_51046;
	BIT_VEC cppVar_51047;
	bool cppVar_51048;
	BIT_VEC cppVar_51049;
	BIT_VEC cppVar_51050;
	BIT_VEC cppVar_51051;
	BIT_VEC cppVar_51052;
	BIT_VEC cppVar_51053;
	BIT_VEC cppVar_51054;
	BIT_VEC cppVar_51055;
	BIT_VEC cppVar_51056;
	BIT_VEC cppVar_51057;
	BIT_VEC cppVar_51044;
	BIT_VEC cppVar_51058;
	bool cppVar_51059;
	BIT_VEC cppVar_51062;
	BIT_VEC cppVar_51063;
	BIT_VEC cppVar_51064;
	bool cppVar_51065;
	BIT_VEC cppVar_51066;
	BIT_VEC cppVar_51067;
	BIT_VEC cppVar_51068;
	BIT_VEC cppVar_51069;
	BIT_VEC cppVar_51070;
	BIT_VEC cppVar_51071;
	BIT_VEC cppVar_51072;
	BIT_VEC cppVar_51073;
	BIT_VEC cppVar_51074;
	BIT_VEC cppVar_51061;
	BIT_VEC cppVar_51075;
	bool cppVar_51076;
	BIT_VEC cppVar_51079;
	BIT_VEC cppVar_51080;
	BIT_VEC cppVar_51081;
	bool cppVar_51082;
	BIT_VEC cppVar_51083;
	BIT_VEC cppVar_51084;
	BIT_VEC cppVar_51085;
	BIT_VEC cppVar_51086;
	BIT_VEC cppVar_51087;
	BIT_VEC cppVar_51088;
	BIT_VEC cppVar_51089;
	BIT_VEC cppVar_51090;
	BIT_VEC cppVar_51091;
	BIT_VEC cppVar_51078;
	BIT_VEC cppVar_51092;
	bool cppVar_51093;
	BIT_VEC cppVar_51096;
	BIT_VEC cppVar_51097;
	BIT_VEC cppVar_51098;
	bool cppVar_51099;
	BIT_VEC cppVar_51100;
	BIT_VEC cppVar_51101;
	BIT_VEC cppVar_51102;
	BIT_VEC cppVar_51103;
	BIT_VEC cppVar_51104;
	BIT_VEC cppVar_51105;
	BIT_VEC cppVar_51106;
	BIT_VEC cppVar_51107;
	BIT_VEC cppVar_51108;
	BIT_VEC cppVar_51095;
	BIT_VEC cppVar_51109;
	bool cppVar_51110;
	BIT_VEC cppVar_51113;
	BIT_VEC cppVar_51114;
	BIT_VEC cppVar_51115;
	bool cppVar_51116;
	BIT_VEC cppVar_51117;
	BIT_VEC cppVar_51118;
	BIT_VEC cppVar_51119;
	BIT_VEC cppVar_51120;
	BIT_VEC cppVar_51121;
	BIT_VEC cppVar_51122;
	BIT_VEC cppVar_51123;
	BIT_VEC cppVar_51124;
	BIT_VEC cppVar_51125;
	BIT_VEC cppVar_51112;
	BIT_VEC cppVar_51126;
	bool cppVar_51127;
	BIT_VEC cppVar_51130;
	BIT_VEC cppVar_51131;
	BIT_VEC cppVar_51132;
	bool cppVar_51133;
	BIT_VEC cppVar_51134;
	BIT_VEC cppVar_51135;
	BIT_VEC cppVar_51136;
	BIT_VEC cppVar_51137;
	BIT_VEC cppVar_51138;
	BIT_VEC cppVar_51139;
	BIT_VEC cppVar_51140;
	BIT_VEC cppVar_51141;
	BIT_VEC cppVar_51142;
	BIT_VEC cppVar_51129;
	BIT_VEC cppVar_51143;
	bool cppVar_51144;
	BIT_VEC cppVar_51147;
	BIT_VEC cppVar_51148;
	BIT_VEC cppVar_51149;
	bool cppVar_51150;
	BIT_VEC cppVar_51151;
	BIT_VEC cppVar_51152;
	BIT_VEC cppVar_51153;
	BIT_VEC cppVar_51154;
	BIT_VEC cppVar_51155;
	BIT_VEC cppVar_51156;
	BIT_VEC cppVar_51157;
	BIT_VEC cppVar_51158;
	BIT_VEC cppVar_51159;
	BIT_VEC cppVar_51146;
	BIT_VEC cppVar_51160;
	bool cppVar_51161;
	BIT_VEC cppVar_51164;
	BIT_VEC cppVar_51165;
	BIT_VEC cppVar_51166;
	bool cppVar_51167;
	BIT_VEC cppVar_51168;
	BIT_VEC cppVar_51169;
	BIT_VEC cppVar_51170;
	BIT_VEC cppVar_51171;
	BIT_VEC cppVar_51172;
	BIT_VEC cppVar_51173;
	BIT_VEC cppVar_51174;
	BIT_VEC cppVar_51175;
	BIT_VEC cppVar_51176;
	BIT_VEC cppVar_51163;
	BIT_VEC cppVar_51177;
	bool cppVar_51178;
	BIT_VEC cppVar_51181;
	BIT_VEC cppVar_51182;
	BIT_VEC cppVar_51183;
	bool cppVar_51184;
	BIT_VEC cppVar_51185;
	BIT_VEC cppVar_51186;
	BIT_VEC cppVar_51187;
	BIT_VEC cppVar_51188;
	BIT_VEC cppVar_51189;
	BIT_VEC cppVar_51190;
	BIT_VEC cppVar_51191;
	BIT_VEC cppVar_51192;
	BIT_VEC cppVar_51193;
	BIT_VEC cppVar_51180;
	BIT_VEC cppVar_51194;
	bool cppVar_51195;
	BIT_VEC cppVar_51198;
	BIT_VEC cppVar_51199;
	BIT_VEC cppVar_51200;
	bool cppVar_51201;
	BIT_VEC cppVar_51202;
	BIT_VEC cppVar_51203;
	BIT_VEC cppVar_51204;
	BIT_VEC cppVar_51205;
	BIT_VEC cppVar_51206;
	BIT_VEC cppVar_51207;
	BIT_VEC cppVar_51208;
	BIT_VEC cppVar_51209;
	BIT_VEC cppVar_51210;
	BIT_VEC cppVar_51197;
	BIT_VEC cppVar_51211;
	bool cppVar_51212;
	BIT_VEC cppVar_51213;
	BIT_VEC cppVar_51196;
	BIT_VEC cppVar_51179;
	BIT_VEC cppVar_51162;
	BIT_VEC cppVar_51145;
	BIT_VEC cppVar_51128;
	BIT_VEC cppVar_51111;
	BIT_VEC cppVar_51094;
	BIT_VEC cppVar_51077;
	BIT_VEC cppVar_51060;
	BIT_VEC cppVar_51043;
	BIT_VEC cppVar_51026;
	BIT_VEC cppVar_51009;
	BIT_VEC cppVar_50992;
	BIT_VEC cppVar_50975;
	BIT_VEC cppVar_50958;
	BIT_VEC cppVar_50941;
	BIT_VEC cppVar_50924;
	BIT_VEC cppVar_50907;
	BIT_VEC cppVar_50890;
	BIT_VEC cppVar_50873;
	BIT_VEC cppVar_50856;
	BIT_VEC cppVar_50823;
	BIT_VEC cppVar_51214;
	BIT_VEC cppVar_51215;
	BIT_VEC cppVar_51216;
	BIT_VEC cppVar_51217;
	BIT_VEC cppVar_51218;
	BIT_VEC cppVar_51219;
	BIT_VEC cppVar_51220;
	BIT_VEC cppVar_51221;
	BIT_VEC cppVar_51222;
	BIT_VEC cppVar_50795;
	BIT_VEC cppVar_51224;
	BIT_VEC cppVar_51225;
	bool cppVar_51226;
	BIT_VEC cppVar_51228;
	BIT_VEC cppVar_51229;
	BIT_VEC cppVar_51230;
	BIT_VEC cppVar_51231;
	bool cppVar_51232;
	BIT_VEC cppVar_51234;
	BIT_VEC cppVar_51235;
	BIT_VEC cppVar_51236;
	BIT_VEC cppVar_51237;
	BIT_VEC cppVar_51238;
	BIT_VEC cppVar_51239;
	BIT_VEC cppVar_51240;
	bool cppVar_51241;
	BIT_VEC cppVar_51242;
	BIT_VEC cppVar_51243;
	BIT_VEC cppVar_51244;
	BIT_VEC cppVar_51245;
	BIT_VEC cppVar_51247;
	BIT_VEC cppVar_51248;
	BIT_VEC cppVar_51249;
	BIT_VEC cppVar_51250;
	bool cppVar_51251;
	BIT_VEC cppVar_51253;
	BIT_VEC cppVar_51254;
	BIT_VEC cppVar_51255;
	BIT_VEC cppVar_51256;
	bool cppVar_51257;
	BIT_VEC cppVar_51259;
	BIT_VEC cppVar_51260;
	BIT_VEC cppVar_51261;
	BIT_VEC cppVar_51262;
	bool cppVar_51263;
	BIT_VEC cppVar_51265;
	BIT_VEC cppVar_51266;
	BIT_VEC cppVar_51267;
	BIT_VEC cppVar_51268;
	bool cppVar_51269;
	BIT_VEC cppVar_51271;
	BIT_VEC cppVar_51272;
	BIT_VEC cppVar_51273;
	BIT_VEC cppVar_51274;
	bool cppVar_51275;
	BIT_VEC cppVar_51277;
	BIT_VEC cppVar_51278;
	BIT_VEC cppVar_51279;
	BIT_VEC cppVar_51280;
	bool cppVar_51281;
	BIT_VEC cppVar_51283;
	BIT_VEC cppVar_51284;
	BIT_VEC cppVar_51285;
	BIT_VEC cppVar_51286;
	bool cppVar_51287;
	BIT_VEC cppVar_51289;
	BIT_VEC cppVar_51290;
	BIT_VEC cppVar_51291;
	BIT_VEC cppVar_51292;
	bool cppVar_51293;
	BIT_VEC cppVar_51295;
	BIT_VEC cppVar_51296;
	BIT_VEC cppVar_51297;
	BIT_VEC cppVar_51298;
	bool cppVar_51299;
	BIT_VEC cppVar_51301;
	BIT_VEC cppVar_51302;
	BIT_VEC cppVar_51303;
	BIT_VEC cppVar_51304;
	bool cppVar_51305;
	BIT_VEC cppVar_51307;
	BIT_VEC cppVar_51308;
	BIT_VEC cppVar_51309;
	BIT_VEC cppVar_51310;
	bool cppVar_51311;
	BIT_VEC cppVar_51313;
	BIT_VEC cppVar_51314;
	BIT_VEC cppVar_51315;
	BIT_VEC cppVar_51316;
	bool cppVar_51317;
	BIT_VEC cppVar_51319;
	BIT_VEC cppVar_51320;
	BIT_VEC cppVar_51321;
	BIT_VEC cppVar_51322;
	bool cppVar_51323;
	BIT_VEC cppVar_51325;
	BIT_VEC cppVar_51326;
	BIT_VEC cppVar_51327;
	BIT_VEC cppVar_51328;
	bool cppVar_51329;
	BIT_VEC cppVar_51331;
	BIT_VEC cppVar_51332;
	BIT_VEC cppVar_51333;
	BIT_VEC cppVar_51334;
	bool cppVar_51335;
	BIT_VEC cppVar_51337;
	BIT_VEC cppVar_51338;
	BIT_VEC cppVar_51339;
	BIT_VEC cppVar_51340;
	bool cppVar_51341;
	BIT_VEC cppVar_51343;
	BIT_VEC cppVar_51344;
	BIT_VEC cppVar_51345;
	BIT_VEC cppVar_51346;
	bool cppVar_51347;
	BIT_VEC cppVar_51349;
	BIT_VEC cppVar_51350;
	BIT_VEC cppVar_51351;
	BIT_VEC cppVar_51352;
	bool cppVar_51353;
	BIT_VEC cppVar_51355;
	BIT_VEC cppVar_51356;
	BIT_VEC cppVar_51357;
	BIT_VEC cppVar_51358;
	bool cppVar_51359;
	BIT_VEC cppVar_51361;
	BIT_VEC cppVar_51362;
	BIT_VEC cppVar_51363;
	BIT_VEC cppVar_51364;
	bool cppVar_51365;
	BIT_VEC cppVar_51367;
	BIT_VEC cppVar_51368;
	BIT_VEC cppVar_51369;
	BIT_VEC cppVar_51370;
	bool cppVar_51371;
	BIT_VEC cppVar_51372;
	BIT_VEC cppVar_51366;
	BIT_VEC cppVar_51360;
	BIT_VEC cppVar_51354;
	BIT_VEC cppVar_51348;
	BIT_VEC cppVar_51342;
	BIT_VEC cppVar_51336;
	BIT_VEC cppVar_51330;
	BIT_VEC cppVar_51324;
	BIT_VEC cppVar_51318;
	BIT_VEC cppVar_51312;
	BIT_VEC cppVar_51306;
	BIT_VEC cppVar_51300;
	BIT_VEC cppVar_51294;
	BIT_VEC cppVar_51288;
	BIT_VEC cppVar_51282;
	BIT_VEC cppVar_51276;
	BIT_VEC cppVar_51270;
	BIT_VEC cppVar_51264;
	BIT_VEC cppVar_51258;
	BIT_VEC cppVar_51252;
	BIT_VEC cppVar_51246;
	BIT_VEC cppVar_51233;
	BIT_VEC cppVar_51227;
	BIT_VEC cppVar_51374;
	BIT_VEC cppVar_51375;
	bool cppVar_51376;
	BIT_VEC cppVar_51378;
	BIT_VEC cppVar_51379;
	BIT_VEC cppVar_51380;
	BIT_VEC cppVar_51381;
	bool cppVar_51382;
	BIT_VEC cppVar_51384;
	BIT_VEC cppVar_51385;
	BIT_VEC cppVar_51386;
	BIT_VEC cppVar_51387;
	BIT_VEC cppVar_51388;
	BIT_VEC cppVar_51389;
	BIT_VEC cppVar_51390;
	bool cppVar_51391;
	BIT_VEC cppVar_51392;
	BIT_VEC cppVar_51393;
	BIT_VEC cppVar_51394;
	BIT_VEC cppVar_51395;
	BIT_VEC cppVar_51397;
	BIT_VEC cppVar_51398;
	BIT_VEC cppVar_51399;
	BIT_VEC cppVar_51400;
	bool cppVar_51401;
	BIT_VEC cppVar_51403;
	BIT_VEC cppVar_51404;
	BIT_VEC cppVar_51405;
	BIT_VEC cppVar_51406;
	bool cppVar_51407;
	BIT_VEC cppVar_51409;
	BIT_VEC cppVar_51410;
	BIT_VEC cppVar_51411;
	BIT_VEC cppVar_51412;
	bool cppVar_51413;
	BIT_VEC cppVar_51415;
	BIT_VEC cppVar_51416;
	BIT_VEC cppVar_51417;
	BIT_VEC cppVar_51418;
	bool cppVar_51419;
	BIT_VEC cppVar_51421;
	BIT_VEC cppVar_51422;
	BIT_VEC cppVar_51423;
	BIT_VEC cppVar_51424;
	bool cppVar_51425;
	BIT_VEC cppVar_51427;
	BIT_VEC cppVar_51428;
	BIT_VEC cppVar_51429;
	BIT_VEC cppVar_51430;
	bool cppVar_51431;
	BIT_VEC cppVar_51433;
	BIT_VEC cppVar_51434;
	BIT_VEC cppVar_51435;
	BIT_VEC cppVar_51436;
	bool cppVar_51437;
	BIT_VEC cppVar_51439;
	BIT_VEC cppVar_51440;
	BIT_VEC cppVar_51441;
	BIT_VEC cppVar_51442;
	bool cppVar_51443;
	BIT_VEC cppVar_51445;
	BIT_VEC cppVar_51446;
	BIT_VEC cppVar_51447;
	BIT_VEC cppVar_51448;
	bool cppVar_51449;
	BIT_VEC cppVar_51451;
	BIT_VEC cppVar_51452;
	BIT_VEC cppVar_51453;
	BIT_VEC cppVar_51454;
	bool cppVar_51455;
	BIT_VEC cppVar_51457;
	BIT_VEC cppVar_51458;
	BIT_VEC cppVar_51459;
	BIT_VEC cppVar_51460;
	bool cppVar_51461;
	BIT_VEC cppVar_51463;
	BIT_VEC cppVar_51464;
	BIT_VEC cppVar_51465;
	BIT_VEC cppVar_51466;
	bool cppVar_51467;
	BIT_VEC cppVar_51469;
	BIT_VEC cppVar_51470;
	BIT_VEC cppVar_51471;
	BIT_VEC cppVar_51472;
	bool cppVar_51473;
	BIT_VEC cppVar_51475;
	BIT_VEC cppVar_51476;
	BIT_VEC cppVar_51477;
	BIT_VEC cppVar_51478;
	bool cppVar_51479;
	BIT_VEC cppVar_51481;
	BIT_VEC cppVar_51482;
	BIT_VEC cppVar_51483;
	BIT_VEC cppVar_51484;
	bool cppVar_51485;
	BIT_VEC cppVar_51487;
	BIT_VEC cppVar_51488;
	BIT_VEC cppVar_51489;
	BIT_VEC cppVar_51490;
	bool cppVar_51491;
	BIT_VEC cppVar_51493;
	BIT_VEC cppVar_51494;
	BIT_VEC cppVar_51495;
	BIT_VEC cppVar_51496;
	bool cppVar_51497;
	BIT_VEC cppVar_51499;
	BIT_VEC cppVar_51500;
	BIT_VEC cppVar_51501;
	BIT_VEC cppVar_51502;
	bool cppVar_51503;
	BIT_VEC cppVar_51505;
	BIT_VEC cppVar_51506;
	BIT_VEC cppVar_51507;
	BIT_VEC cppVar_51508;
	bool cppVar_51509;
	BIT_VEC cppVar_51511;
	BIT_VEC cppVar_51512;
	BIT_VEC cppVar_51513;
	BIT_VEC cppVar_51514;
	bool cppVar_51515;
	BIT_VEC cppVar_51517;
	BIT_VEC cppVar_51518;
	BIT_VEC cppVar_51519;
	BIT_VEC cppVar_51520;
	bool cppVar_51521;
	BIT_VEC cppVar_51522;
	BIT_VEC cppVar_51516;
	BIT_VEC cppVar_51510;
	BIT_VEC cppVar_51504;
	BIT_VEC cppVar_51498;
	BIT_VEC cppVar_51492;
	BIT_VEC cppVar_51486;
	BIT_VEC cppVar_51480;
	BIT_VEC cppVar_51474;
	BIT_VEC cppVar_51468;
	BIT_VEC cppVar_51462;
	BIT_VEC cppVar_51456;
	BIT_VEC cppVar_51450;
	BIT_VEC cppVar_51444;
	BIT_VEC cppVar_51438;
	BIT_VEC cppVar_51432;
	BIT_VEC cppVar_51426;
	BIT_VEC cppVar_51420;
	BIT_VEC cppVar_51414;
	BIT_VEC cppVar_51408;
	BIT_VEC cppVar_51402;
	BIT_VEC cppVar_51396;
	BIT_VEC cppVar_51383;
	BIT_VEC cppVar_51377;
	BIT_VEC cppVar_51524;
	BIT_VEC cppVar_51525;
	bool cppVar_51526;
	BIT_VEC cppVar_51528;
	BIT_VEC cppVar_51529;
	BIT_VEC cppVar_51530;
	BIT_VEC cppVar_51531;
	bool cppVar_51532;
	BIT_VEC cppVar_51534;
	BIT_VEC cppVar_51535;
	BIT_VEC cppVar_51536;
	BIT_VEC cppVar_51537;
	BIT_VEC cppVar_51538;
	BIT_VEC cppVar_51539;
	BIT_VEC cppVar_51540;
	bool cppVar_51541;
	BIT_VEC cppVar_51542;
	BIT_VEC cppVar_51543;
	BIT_VEC cppVar_51544;
	BIT_VEC cppVar_51545;
	BIT_VEC cppVar_51547;
	BIT_VEC cppVar_51548;
	BIT_VEC cppVar_51549;
	BIT_VEC cppVar_51550;
	bool cppVar_51551;
	BIT_VEC cppVar_51553;
	BIT_VEC cppVar_51554;
	BIT_VEC cppVar_51555;
	BIT_VEC cppVar_51556;
	bool cppVar_51557;
	BIT_VEC cppVar_51559;
	BIT_VEC cppVar_51560;
	BIT_VEC cppVar_51561;
	BIT_VEC cppVar_51562;
	bool cppVar_51563;
	BIT_VEC cppVar_51565;
	BIT_VEC cppVar_51566;
	BIT_VEC cppVar_51567;
	BIT_VEC cppVar_51568;
	bool cppVar_51569;
	BIT_VEC cppVar_51571;
	BIT_VEC cppVar_51572;
	BIT_VEC cppVar_51573;
	BIT_VEC cppVar_51574;
	bool cppVar_51575;
	BIT_VEC cppVar_51577;
	BIT_VEC cppVar_51578;
	BIT_VEC cppVar_51579;
	BIT_VEC cppVar_51580;
	bool cppVar_51581;
	BIT_VEC cppVar_51583;
	BIT_VEC cppVar_51584;
	BIT_VEC cppVar_51585;
	BIT_VEC cppVar_51586;
	bool cppVar_51587;
	BIT_VEC cppVar_51589;
	BIT_VEC cppVar_51590;
	BIT_VEC cppVar_51591;
	BIT_VEC cppVar_51592;
	bool cppVar_51593;
	BIT_VEC cppVar_51595;
	BIT_VEC cppVar_51596;
	BIT_VEC cppVar_51597;
	BIT_VEC cppVar_51598;
	bool cppVar_51599;
	BIT_VEC cppVar_51601;
	BIT_VEC cppVar_51602;
	BIT_VEC cppVar_51603;
	BIT_VEC cppVar_51604;
	bool cppVar_51605;
	BIT_VEC cppVar_51607;
	BIT_VEC cppVar_51608;
	BIT_VEC cppVar_51609;
	BIT_VEC cppVar_51610;
	bool cppVar_51611;
	BIT_VEC cppVar_51613;
	BIT_VEC cppVar_51614;
	BIT_VEC cppVar_51615;
	BIT_VEC cppVar_51616;
	bool cppVar_51617;
	BIT_VEC cppVar_51619;
	BIT_VEC cppVar_51620;
	BIT_VEC cppVar_51621;
	BIT_VEC cppVar_51622;
	bool cppVar_51623;
	BIT_VEC cppVar_51625;
	BIT_VEC cppVar_51626;
	BIT_VEC cppVar_51627;
	BIT_VEC cppVar_51628;
	bool cppVar_51629;
	BIT_VEC cppVar_51631;
	BIT_VEC cppVar_51632;
	BIT_VEC cppVar_51633;
	BIT_VEC cppVar_51634;
	bool cppVar_51635;
	BIT_VEC cppVar_51637;
	BIT_VEC cppVar_51638;
	BIT_VEC cppVar_51639;
	BIT_VEC cppVar_51640;
	bool cppVar_51641;
	BIT_VEC cppVar_51643;
	BIT_VEC cppVar_51644;
	BIT_VEC cppVar_51645;
	BIT_VEC cppVar_51646;
	bool cppVar_51647;
	BIT_VEC cppVar_51649;
	BIT_VEC cppVar_51650;
	BIT_VEC cppVar_51651;
	BIT_VEC cppVar_51652;
	bool cppVar_51653;
	BIT_VEC cppVar_51655;
	BIT_VEC cppVar_51656;
	BIT_VEC cppVar_51657;
	BIT_VEC cppVar_51658;
	bool cppVar_51659;
	BIT_VEC cppVar_51661;
	BIT_VEC cppVar_51662;
	BIT_VEC cppVar_51663;
	BIT_VEC cppVar_51664;
	bool cppVar_51665;
	BIT_VEC cppVar_51667;
	BIT_VEC cppVar_51668;
	BIT_VEC cppVar_51669;
	BIT_VEC cppVar_51670;
	bool cppVar_51671;
	BIT_VEC cppVar_51672;
	BIT_VEC cppVar_51666;
	BIT_VEC cppVar_51660;
	BIT_VEC cppVar_51654;
	BIT_VEC cppVar_51648;
	BIT_VEC cppVar_51642;
	BIT_VEC cppVar_51636;
	BIT_VEC cppVar_51630;
	BIT_VEC cppVar_51624;
	BIT_VEC cppVar_51618;
	BIT_VEC cppVar_51612;
	BIT_VEC cppVar_51606;
	BIT_VEC cppVar_51600;
	BIT_VEC cppVar_51594;
	BIT_VEC cppVar_51588;
	BIT_VEC cppVar_51582;
	BIT_VEC cppVar_51576;
	BIT_VEC cppVar_51570;
	BIT_VEC cppVar_51564;
	BIT_VEC cppVar_51558;
	BIT_VEC cppVar_51552;
	BIT_VEC cppVar_51546;
	BIT_VEC cppVar_51533;
	BIT_VEC cppVar_51527;
	BIT_VEC cppVar_51674;
	BIT_VEC cppVar_51675;
	bool cppVar_51676;
	BIT_VEC cppVar_51678;
	BIT_VEC cppVar_51679;
	BIT_VEC cppVar_51680;
	BIT_VEC cppVar_51681;
	bool cppVar_51682;
	BIT_VEC cppVar_51684;
	BIT_VEC cppVar_51685;
	BIT_VEC cppVar_51686;
	BIT_VEC cppVar_51687;
	BIT_VEC cppVar_51688;
	BIT_VEC cppVar_51689;
	BIT_VEC cppVar_51690;
	bool cppVar_51691;
	BIT_VEC cppVar_51692;
	BIT_VEC cppVar_51693;
	BIT_VEC cppVar_51694;
	BIT_VEC cppVar_51695;
	BIT_VEC cppVar_51697;
	BIT_VEC cppVar_51698;
	BIT_VEC cppVar_51699;
	BIT_VEC cppVar_51700;
	bool cppVar_51701;
	BIT_VEC cppVar_51703;
	BIT_VEC cppVar_51704;
	BIT_VEC cppVar_51705;
	BIT_VEC cppVar_51706;
	bool cppVar_51707;
	BIT_VEC cppVar_51709;
	BIT_VEC cppVar_51710;
	BIT_VEC cppVar_51711;
	BIT_VEC cppVar_51712;
	bool cppVar_51713;
	BIT_VEC cppVar_51715;
	BIT_VEC cppVar_51716;
	BIT_VEC cppVar_51717;
	BIT_VEC cppVar_51718;
	bool cppVar_51719;
	BIT_VEC cppVar_51721;
	BIT_VEC cppVar_51722;
	BIT_VEC cppVar_51723;
	BIT_VEC cppVar_51724;
	bool cppVar_51725;
	BIT_VEC cppVar_51727;
	BIT_VEC cppVar_51728;
	BIT_VEC cppVar_51729;
	BIT_VEC cppVar_51730;
	bool cppVar_51731;
	BIT_VEC cppVar_51733;
	BIT_VEC cppVar_51734;
	BIT_VEC cppVar_51735;
	BIT_VEC cppVar_51736;
	bool cppVar_51737;
	BIT_VEC cppVar_51739;
	BIT_VEC cppVar_51740;
	BIT_VEC cppVar_51741;
	BIT_VEC cppVar_51742;
	bool cppVar_51743;
	BIT_VEC cppVar_51745;
	BIT_VEC cppVar_51746;
	BIT_VEC cppVar_51747;
	BIT_VEC cppVar_51748;
	bool cppVar_51749;
	BIT_VEC cppVar_51751;
	BIT_VEC cppVar_51752;
	BIT_VEC cppVar_51753;
	BIT_VEC cppVar_51754;
	bool cppVar_51755;
	BIT_VEC cppVar_51757;
	BIT_VEC cppVar_51758;
	BIT_VEC cppVar_51759;
	BIT_VEC cppVar_51760;
	bool cppVar_51761;
	BIT_VEC cppVar_51763;
	BIT_VEC cppVar_51764;
	BIT_VEC cppVar_51765;
	BIT_VEC cppVar_51766;
	bool cppVar_51767;
	BIT_VEC cppVar_51769;
	BIT_VEC cppVar_51770;
	BIT_VEC cppVar_51771;
	BIT_VEC cppVar_51772;
	bool cppVar_51773;
	BIT_VEC cppVar_51775;
	BIT_VEC cppVar_51776;
	BIT_VEC cppVar_51777;
	BIT_VEC cppVar_51778;
	bool cppVar_51779;
	BIT_VEC cppVar_51781;
	BIT_VEC cppVar_51782;
	BIT_VEC cppVar_51783;
	BIT_VEC cppVar_51784;
	bool cppVar_51785;
	BIT_VEC cppVar_51787;
	BIT_VEC cppVar_51788;
	BIT_VEC cppVar_51789;
	BIT_VEC cppVar_51790;
	bool cppVar_51791;
	BIT_VEC cppVar_51793;
	BIT_VEC cppVar_51794;
	BIT_VEC cppVar_51795;
	BIT_VEC cppVar_51796;
	bool cppVar_51797;
	BIT_VEC cppVar_51799;
	BIT_VEC cppVar_51800;
	BIT_VEC cppVar_51801;
	BIT_VEC cppVar_51802;
	bool cppVar_51803;
	BIT_VEC cppVar_51805;
	BIT_VEC cppVar_51806;
	BIT_VEC cppVar_51807;
	BIT_VEC cppVar_51808;
	bool cppVar_51809;
	BIT_VEC cppVar_51811;
	BIT_VEC cppVar_51812;
	BIT_VEC cppVar_51813;
	BIT_VEC cppVar_51814;
	bool cppVar_51815;
	BIT_VEC cppVar_51817;
	BIT_VEC cppVar_51818;
	BIT_VEC cppVar_51819;
	BIT_VEC cppVar_51820;
	bool cppVar_51821;
	BIT_VEC cppVar_51822;
	BIT_VEC cppVar_51816;
	BIT_VEC cppVar_51810;
	BIT_VEC cppVar_51804;
	BIT_VEC cppVar_51798;
	BIT_VEC cppVar_51792;
	BIT_VEC cppVar_51786;
	BIT_VEC cppVar_51780;
	BIT_VEC cppVar_51774;
	BIT_VEC cppVar_51768;
	BIT_VEC cppVar_51762;
	BIT_VEC cppVar_51756;
	BIT_VEC cppVar_51750;
	BIT_VEC cppVar_51744;
	BIT_VEC cppVar_51738;
	BIT_VEC cppVar_51732;
	BIT_VEC cppVar_51726;
	BIT_VEC cppVar_51720;
	BIT_VEC cppVar_51714;
	BIT_VEC cppVar_51708;
	BIT_VEC cppVar_51702;
	BIT_VEC cppVar_51696;
	BIT_VEC cppVar_51683;
	BIT_VEC cppVar_51677;
	BIT_VEC cppVar_51824;
	BIT_VEC cppVar_51825;
	bool cppVar_51826;
	BIT_VEC cppVar_51828;
	BIT_VEC cppVar_51829;
	BIT_VEC cppVar_51830;
	BIT_VEC cppVar_51831;
	bool cppVar_51832;
	BIT_VEC cppVar_51834;
	BIT_VEC cppVar_51835;
	BIT_VEC cppVar_51836;
	BIT_VEC cppVar_51837;
	BIT_VEC cppVar_51838;
	BIT_VEC cppVar_51839;
	BIT_VEC cppVar_51840;
	bool cppVar_51841;
	BIT_VEC cppVar_51842;
	BIT_VEC cppVar_51843;
	BIT_VEC cppVar_51844;
	BIT_VEC cppVar_51845;
	BIT_VEC cppVar_51847;
	BIT_VEC cppVar_51848;
	BIT_VEC cppVar_51849;
	BIT_VEC cppVar_51850;
	bool cppVar_51851;
	BIT_VEC cppVar_51853;
	BIT_VEC cppVar_51854;
	BIT_VEC cppVar_51855;
	BIT_VEC cppVar_51856;
	bool cppVar_51857;
	BIT_VEC cppVar_51859;
	BIT_VEC cppVar_51860;
	BIT_VEC cppVar_51861;
	BIT_VEC cppVar_51862;
	bool cppVar_51863;
	BIT_VEC cppVar_51865;
	BIT_VEC cppVar_51866;
	BIT_VEC cppVar_51867;
	BIT_VEC cppVar_51868;
	bool cppVar_51869;
	BIT_VEC cppVar_51871;
	BIT_VEC cppVar_51872;
	BIT_VEC cppVar_51873;
	BIT_VEC cppVar_51874;
	bool cppVar_51875;
	BIT_VEC cppVar_51877;
	BIT_VEC cppVar_51878;
	BIT_VEC cppVar_51879;
	BIT_VEC cppVar_51880;
	bool cppVar_51881;
	BIT_VEC cppVar_51883;
	BIT_VEC cppVar_51884;
	BIT_VEC cppVar_51885;
	BIT_VEC cppVar_51886;
	bool cppVar_51887;
	BIT_VEC cppVar_51889;
	BIT_VEC cppVar_51890;
	BIT_VEC cppVar_51891;
	BIT_VEC cppVar_51892;
	bool cppVar_51893;
	BIT_VEC cppVar_51895;
	BIT_VEC cppVar_51896;
	BIT_VEC cppVar_51897;
	BIT_VEC cppVar_51898;
	bool cppVar_51899;
	BIT_VEC cppVar_51901;
	BIT_VEC cppVar_51902;
	BIT_VEC cppVar_51903;
	BIT_VEC cppVar_51904;
	bool cppVar_51905;
	BIT_VEC cppVar_51907;
	BIT_VEC cppVar_51908;
	BIT_VEC cppVar_51909;
	BIT_VEC cppVar_51910;
	bool cppVar_51911;
	BIT_VEC cppVar_51913;
	BIT_VEC cppVar_51914;
	BIT_VEC cppVar_51915;
	BIT_VEC cppVar_51916;
	bool cppVar_51917;
	BIT_VEC cppVar_51919;
	BIT_VEC cppVar_51920;
	BIT_VEC cppVar_51921;
	BIT_VEC cppVar_51922;
	bool cppVar_51923;
	BIT_VEC cppVar_51925;
	BIT_VEC cppVar_51926;
	BIT_VEC cppVar_51927;
	BIT_VEC cppVar_51928;
	bool cppVar_51929;
	BIT_VEC cppVar_51931;
	BIT_VEC cppVar_51932;
	BIT_VEC cppVar_51933;
	BIT_VEC cppVar_51934;
	bool cppVar_51935;
	BIT_VEC cppVar_51937;
	BIT_VEC cppVar_51938;
	BIT_VEC cppVar_51939;
	BIT_VEC cppVar_51940;
	bool cppVar_51941;
	BIT_VEC cppVar_51943;
	BIT_VEC cppVar_51944;
	BIT_VEC cppVar_51945;
	BIT_VEC cppVar_51946;
	bool cppVar_51947;
	BIT_VEC cppVar_51949;
	BIT_VEC cppVar_51950;
	BIT_VEC cppVar_51951;
	BIT_VEC cppVar_51952;
	bool cppVar_51953;
	BIT_VEC cppVar_51955;
	BIT_VEC cppVar_51956;
	BIT_VEC cppVar_51957;
	BIT_VEC cppVar_51958;
	bool cppVar_51959;
	BIT_VEC cppVar_51961;
	BIT_VEC cppVar_51962;
	BIT_VEC cppVar_51963;
	BIT_VEC cppVar_51964;
	bool cppVar_51965;
	BIT_VEC cppVar_51967;
	BIT_VEC cppVar_51968;
	BIT_VEC cppVar_51969;
	BIT_VEC cppVar_51970;
	bool cppVar_51971;
	BIT_VEC cppVar_51972;
	BIT_VEC cppVar_51966;
	BIT_VEC cppVar_51960;
	BIT_VEC cppVar_51954;
	BIT_VEC cppVar_51948;
	BIT_VEC cppVar_51942;
	BIT_VEC cppVar_51936;
	BIT_VEC cppVar_51930;
	BIT_VEC cppVar_51924;
	BIT_VEC cppVar_51918;
	BIT_VEC cppVar_51912;
	BIT_VEC cppVar_51906;
	BIT_VEC cppVar_51900;
	BIT_VEC cppVar_51894;
	BIT_VEC cppVar_51888;
	BIT_VEC cppVar_51882;
	BIT_VEC cppVar_51876;
	BIT_VEC cppVar_51870;
	BIT_VEC cppVar_51864;
	BIT_VEC cppVar_51858;
	BIT_VEC cppVar_51852;
	BIT_VEC cppVar_51846;
	BIT_VEC cppVar_51833;
	BIT_VEC cppVar_51827;
	BIT_VEC cppVar_51974;
	BIT_VEC cppVar_51975;
	bool cppVar_51976;
	BIT_VEC cppVar_51978;
	BIT_VEC cppVar_51979;
	BIT_VEC cppVar_51980;
	BIT_VEC cppVar_51981;
	bool cppVar_51982;
	BIT_VEC cppVar_51984;
	BIT_VEC cppVar_51985;
	BIT_VEC cppVar_51986;
	BIT_VEC cppVar_51987;
	BIT_VEC cppVar_51988;
	BIT_VEC cppVar_51989;
	BIT_VEC cppVar_51990;
	bool cppVar_51991;
	BIT_VEC cppVar_51992;
	BIT_VEC cppVar_51993;
	BIT_VEC cppVar_51994;
	BIT_VEC cppVar_51995;
	BIT_VEC cppVar_51997;
	BIT_VEC cppVar_51998;
	BIT_VEC cppVar_51999;
	BIT_VEC cppVar_52000;
	bool cppVar_52001;
	BIT_VEC cppVar_52003;
	BIT_VEC cppVar_52004;
	BIT_VEC cppVar_52005;
	BIT_VEC cppVar_52006;
	bool cppVar_52007;
	BIT_VEC cppVar_52009;
	BIT_VEC cppVar_52010;
	BIT_VEC cppVar_52011;
	BIT_VEC cppVar_52012;
	bool cppVar_52013;
	BIT_VEC cppVar_52015;
	BIT_VEC cppVar_52016;
	BIT_VEC cppVar_52017;
	BIT_VEC cppVar_52018;
	bool cppVar_52019;
	BIT_VEC cppVar_52021;
	BIT_VEC cppVar_52022;
	BIT_VEC cppVar_52023;
	BIT_VEC cppVar_52024;
	bool cppVar_52025;
	BIT_VEC cppVar_52027;
	BIT_VEC cppVar_52028;
	BIT_VEC cppVar_52029;
	BIT_VEC cppVar_52030;
	bool cppVar_52031;
	BIT_VEC cppVar_52033;
	BIT_VEC cppVar_52034;
	BIT_VEC cppVar_52035;
	BIT_VEC cppVar_52036;
	bool cppVar_52037;
	BIT_VEC cppVar_52039;
	BIT_VEC cppVar_52040;
	BIT_VEC cppVar_52041;
	BIT_VEC cppVar_52042;
	bool cppVar_52043;
	BIT_VEC cppVar_52045;
	BIT_VEC cppVar_52046;
	BIT_VEC cppVar_52047;
	BIT_VEC cppVar_52048;
	bool cppVar_52049;
	BIT_VEC cppVar_52051;
	BIT_VEC cppVar_52052;
	BIT_VEC cppVar_52053;
	BIT_VEC cppVar_52054;
	bool cppVar_52055;
	BIT_VEC cppVar_52057;
	BIT_VEC cppVar_52058;
	BIT_VEC cppVar_52059;
	BIT_VEC cppVar_52060;
	bool cppVar_52061;
	BIT_VEC cppVar_52063;
	BIT_VEC cppVar_52064;
	BIT_VEC cppVar_52065;
	BIT_VEC cppVar_52066;
	bool cppVar_52067;
	BIT_VEC cppVar_52069;
	BIT_VEC cppVar_52070;
	BIT_VEC cppVar_52071;
	BIT_VEC cppVar_52072;
	bool cppVar_52073;
	BIT_VEC cppVar_52075;
	BIT_VEC cppVar_52076;
	BIT_VEC cppVar_52077;
	BIT_VEC cppVar_52078;
	bool cppVar_52079;
	BIT_VEC cppVar_52081;
	BIT_VEC cppVar_52082;
	BIT_VEC cppVar_52083;
	BIT_VEC cppVar_52084;
	bool cppVar_52085;
	BIT_VEC cppVar_52087;
	BIT_VEC cppVar_52088;
	BIT_VEC cppVar_52089;
	BIT_VEC cppVar_52090;
	bool cppVar_52091;
	BIT_VEC cppVar_52093;
	BIT_VEC cppVar_52094;
	BIT_VEC cppVar_52095;
	BIT_VEC cppVar_52096;
	bool cppVar_52097;
	BIT_VEC cppVar_52099;
	BIT_VEC cppVar_52100;
	BIT_VEC cppVar_52101;
	BIT_VEC cppVar_52102;
	bool cppVar_52103;
	BIT_VEC cppVar_52105;
	BIT_VEC cppVar_52106;
	BIT_VEC cppVar_52107;
	BIT_VEC cppVar_52108;
	bool cppVar_52109;
	BIT_VEC cppVar_52111;
	BIT_VEC cppVar_52112;
	BIT_VEC cppVar_52113;
	BIT_VEC cppVar_52114;
	bool cppVar_52115;
	BIT_VEC cppVar_52117;
	BIT_VEC cppVar_52118;
	BIT_VEC cppVar_52119;
	BIT_VEC cppVar_52120;
	bool cppVar_52121;
	BIT_VEC cppVar_52122;
	BIT_VEC cppVar_52116;
	BIT_VEC cppVar_52110;
	BIT_VEC cppVar_52104;
	BIT_VEC cppVar_52098;
	BIT_VEC cppVar_52092;
	BIT_VEC cppVar_52086;
	BIT_VEC cppVar_52080;
	BIT_VEC cppVar_52074;
	BIT_VEC cppVar_52068;
	BIT_VEC cppVar_52062;
	BIT_VEC cppVar_52056;
	BIT_VEC cppVar_52050;
	BIT_VEC cppVar_52044;
	BIT_VEC cppVar_52038;
	BIT_VEC cppVar_52032;
	BIT_VEC cppVar_52026;
	BIT_VEC cppVar_52020;
	BIT_VEC cppVar_52014;
	BIT_VEC cppVar_52008;
	BIT_VEC cppVar_52002;
	BIT_VEC cppVar_51996;
	BIT_VEC cppVar_51983;
	BIT_VEC cppVar_51977;
	BIT_VEC cppVar_52124;
	BIT_VEC cppVar_52125;
	bool cppVar_52126;
	BIT_VEC cppVar_52128;
	BIT_VEC cppVar_52129;
	BIT_VEC cppVar_52130;
	BIT_VEC cppVar_52131;
	bool cppVar_52132;
	BIT_VEC cppVar_52134;
	BIT_VEC cppVar_52135;
	BIT_VEC cppVar_52136;
	BIT_VEC cppVar_52137;
	BIT_VEC cppVar_52138;
	BIT_VEC cppVar_52139;
	BIT_VEC cppVar_52140;
	bool cppVar_52141;
	BIT_VEC cppVar_52142;
	BIT_VEC cppVar_52143;
	BIT_VEC cppVar_52144;
	BIT_VEC cppVar_52145;
	BIT_VEC cppVar_52147;
	BIT_VEC cppVar_52148;
	BIT_VEC cppVar_52149;
	BIT_VEC cppVar_52150;
	bool cppVar_52151;
	BIT_VEC cppVar_52153;
	BIT_VEC cppVar_52154;
	BIT_VEC cppVar_52155;
	BIT_VEC cppVar_52156;
	bool cppVar_52157;
	BIT_VEC cppVar_52159;
	BIT_VEC cppVar_52160;
	BIT_VEC cppVar_52161;
	BIT_VEC cppVar_52162;
	bool cppVar_52163;
	BIT_VEC cppVar_52165;
	BIT_VEC cppVar_52166;
	BIT_VEC cppVar_52167;
	BIT_VEC cppVar_52168;
	bool cppVar_52169;
	BIT_VEC cppVar_52171;
	BIT_VEC cppVar_52172;
	BIT_VEC cppVar_52173;
	BIT_VEC cppVar_52174;
	bool cppVar_52175;
	BIT_VEC cppVar_52177;
	BIT_VEC cppVar_52178;
	BIT_VEC cppVar_52179;
	BIT_VEC cppVar_52180;
	bool cppVar_52181;
	BIT_VEC cppVar_52183;
	BIT_VEC cppVar_52184;
	BIT_VEC cppVar_52185;
	BIT_VEC cppVar_52186;
	bool cppVar_52187;
	BIT_VEC cppVar_52189;
	BIT_VEC cppVar_52190;
	BIT_VEC cppVar_52191;
	BIT_VEC cppVar_52192;
	bool cppVar_52193;
	BIT_VEC cppVar_52195;
	BIT_VEC cppVar_52196;
	BIT_VEC cppVar_52197;
	BIT_VEC cppVar_52198;
	bool cppVar_52199;
	BIT_VEC cppVar_52201;
	BIT_VEC cppVar_52202;
	BIT_VEC cppVar_52203;
	BIT_VEC cppVar_52204;
	bool cppVar_52205;
	BIT_VEC cppVar_52207;
	BIT_VEC cppVar_52208;
	BIT_VEC cppVar_52209;
	BIT_VEC cppVar_52210;
	bool cppVar_52211;
	BIT_VEC cppVar_52213;
	BIT_VEC cppVar_52214;
	BIT_VEC cppVar_52215;
	BIT_VEC cppVar_52216;
	bool cppVar_52217;
	BIT_VEC cppVar_52219;
	BIT_VEC cppVar_52220;
	BIT_VEC cppVar_52221;
	BIT_VEC cppVar_52222;
	bool cppVar_52223;
	BIT_VEC cppVar_52225;
	BIT_VEC cppVar_52226;
	BIT_VEC cppVar_52227;
	BIT_VEC cppVar_52228;
	bool cppVar_52229;
	BIT_VEC cppVar_52231;
	BIT_VEC cppVar_52232;
	BIT_VEC cppVar_52233;
	BIT_VEC cppVar_52234;
	bool cppVar_52235;
	BIT_VEC cppVar_52237;
	BIT_VEC cppVar_52238;
	BIT_VEC cppVar_52239;
	BIT_VEC cppVar_52240;
	bool cppVar_52241;
	BIT_VEC cppVar_52243;
	BIT_VEC cppVar_52244;
	BIT_VEC cppVar_52245;
	BIT_VEC cppVar_52246;
	bool cppVar_52247;
	BIT_VEC cppVar_52249;
	BIT_VEC cppVar_52250;
	BIT_VEC cppVar_52251;
	BIT_VEC cppVar_52252;
	bool cppVar_52253;
	BIT_VEC cppVar_52255;
	BIT_VEC cppVar_52256;
	BIT_VEC cppVar_52257;
	BIT_VEC cppVar_52258;
	bool cppVar_52259;
	BIT_VEC cppVar_52261;
	BIT_VEC cppVar_52262;
	BIT_VEC cppVar_52263;
	BIT_VEC cppVar_52264;
	bool cppVar_52265;
	BIT_VEC cppVar_52267;
	BIT_VEC cppVar_52268;
	BIT_VEC cppVar_52269;
	BIT_VEC cppVar_52270;
	bool cppVar_52271;
	BIT_VEC cppVar_52272;
	BIT_VEC cppVar_52266;
	BIT_VEC cppVar_52260;
	BIT_VEC cppVar_52254;
	BIT_VEC cppVar_52248;
	BIT_VEC cppVar_52242;
	BIT_VEC cppVar_52236;
	BIT_VEC cppVar_52230;
	BIT_VEC cppVar_52224;
	BIT_VEC cppVar_52218;
	BIT_VEC cppVar_52212;
	BIT_VEC cppVar_52206;
	BIT_VEC cppVar_52200;
	BIT_VEC cppVar_52194;
	BIT_VEC cppVar_52188;
	BIT_VEC cppVar_52182;
	BIT_VEC cppVar_52176;
	BIT_VEC cppVar_52170;
	BIT_VEC cppVar_52164;
	BIT_VEC cppVar_52158;
	BIT_VEC cppVar_52152;
	BIT_VEC cppVar_52146;
	BIT_VEC cppVar_52133;
	BIT_VEC cppVar_52127;
	BIT_VEC cppVar_52274;
	BIT_VEC cppVar_52275;
	bool cppVar_52276;
	BIT_VEC cppVar_52278;
	BIT_VEC cppVar_52279;
	BIT_VEC cppVar_52280;
	BIT_VEC cppVar_52281;
	bool cppVar_52282;
	BIT_VEC cppVar_52284;
	BIT_VEC cppVar_52285;
	BIT_VEC cppVar_52286;
	BIT_VEC cppVar_52287;
	BIT_VEC cppVar_52288;
	BIT_VEC cppVar_52289;
	BIT_VEC cppVar_52290;
	bool cppVar_52291;
	BIT_VEC cppVar_52292;
	BIT_VEC cppVar_52293;
	BIT_VEC cppVar_52294;
	BIT_VEC cppVar_52295;
	BIT_VEC cppVar_52297;
	BIT_VEC cppVar_52298;
	BIT_VEC cppVar_52299;
	BIT_VEC cppVar_52300;
	bool cppVar_52301;
	BIT_VEC cppVar_52303;
	BIT_VEC cppVar_52304;
	BIT_VEC cppVar_52305;
	BIT_VEC cppVar_52306;
	bool cppVar_52307;
	BIT_VEC cppVar_52309;
	BIT_VEC cppVar_52310;
	BIT_VEC cppVar_52311;
	BIT_VEC cppVar_52312;
	bool cppVar_52313;
	BIT_VEC cppVar_52315;
	BIT_VEC cppVar_52316;
	BIT_VEC cppVar_52317;
	BIT_VEC cppVar_52318;
	bool cppVar_52319;
	BIT_VEC cppVar_52321;
	BIT_VEC cppVar_52322;
	BIT_VEC cppVar_52323;
	BIT_VEC cppVar_52324;
	bool cppVar_52325;
	BIT_VEC cppVar_52327;
	BIT_VEC cppVar_52328;
	BIT_VEC cppVar_52329;
	BIT_VEC cppVar_52330;
	bool cppVar_52331;
	BIT_VEC cppVar_52333;
	BIT_VEC cppVar_52334;
	BIT_VEC cppVar_52335;
	BIT_VEC cppVar_52336;
	bool cppVar_52337;
	BIT_VEC cppVar_52339;
	BIT_VEC cppVar_52340;
	BIT_VEC cppVar_52341;
	BIT_VEC cppVar_52342;
	bool cppVar_52343;
	BIT_VEC cppVar_52345;
	BIT_VEC cppVar_52346;
	BIT_VEC cppVar_52347;
	BIT_VEC cppVar_52348;
	bool cppVar_52349;
	BIT_VEC cppVar_52351;
	BIT_VEC cppVar_52352;
	BIT_VEC cppVar_52353;
	BIT_VEC cppVar_52354;
	bool cppVar_52355;
	BIT_VEC cppVar_52357;
	BIT_VEC cppVar_52358;
	BIT_VEC cppVar_52359;
	BIT_VEC cppVar_52360;
	bool cppVar_52361;
	BIT_VEC cppVar_52363;
	BIT_VEC cppVar_52364;
	BIT_VEC cppVar_52365;
	BIT_VEC cppVar_52366;
	bool cppVar_52367;
	BIT_VEC cppVar_52369;
	BIT_VEC cppVar_52370;
	BIT_VEC cppVar_52371;
	BIT_VEC cppVar_52372;
	bool cppVar_52373;
	BIT_VEC cppVar_52375;
	BIT_VEC cppVar_52376;
	BIT_VEC cppVar_52377;
	BIT_VEC cppVar_52378;
	bool cppVar_52379;
	BIT_VEC cppVar_52381;
	BIT_VEC cppVar_52382;
	BIT_VEC cppVar_52383;
	BIT_VEC cppVar_52384;
	bool cppVar_52385;
	BIT_VEC cppVar_52387;
	BIT_VEC cppVar_52388;
	BIT_VEC cppVar_52389;
	BIT_VEC cppVar_52390;
	bool cppVar_52391;
	BIT_VEC cppVar_52393;
	BIT_VEC cppVar_52394;
	BIT_VEC cppVar_52395;
	BIT_VEC cppVar_52396;
	bool cppVar_52397;
	BIT_VEC cppVar_52399;
	BIT_VEC cppVar_52400;
	BIT_VEC cppVar_52401;
	BIT_VEC cppVar_52402;
	bool cppVar_52403;
	BIT_VEC cppVar_52405;
	BIT_VEC cppVar_52406;
	BIT_VEC cppVar_52407;
	BIT_VEC cppVar_52408;
	bool cppVar_52409;
	BIT_VEC cppVar_52411;
	BIT_VEC cppVar_52412;
	BIT_VEC cppVar_52413;
	BIT_VEC cppVar_52414;
	bool cppVar_52415;
	BIT_VEC cppVar_52417;
	BIT_VEC cppVar_52418;
	BIT_VEC cppVar_52419;
	BIT_VEC cppVar_52420;
	bool cppVar_52421;
	BIT_VEC cppVar_52422;
	BIT_VEC cppVar_52416;
	BIT_VEC cppVar_52410;
	BIT_VEC cppVar_52404;
	BIT_VEC cppVar_52398;
	BIT_VEC cppVar_52392;
	BIT_VEC cppVar_52386;
	BIT_VEC cppVar_52380;
	BIT_VEC cppVar_52374;
	BIT_VEC cppVar_52368;
	BIT_VEC cppVar_52362;
	BIT_VEC cppVar_52356;
	BIT_VEC cppVar_52350;
	BIT_VEC cppVar_52344;
	BIT_VEC cppVar_52338;
	BIT_VEC cppVar_52332;
	BIT_VEC cppVar_52326;
	BIT_VEC cppVar_52320;
	BIT_VEC cppVar_52314;
	BIT_VEC cppVar_52308;
	BIT_VEC cppVar_52302;
	BIT_VEC cppVar_52296;
	BIT_VEC cppVar_52283;
	BIT_VEC cppVar_52277;
	BIT_VEC cppVar_52424;
	BIT_VEC cppVar_52425;
	bool cppVar_52426;
	BIT_VEC cppVar_52428;
	BIT_VEC cppVar_52429;
	BIT_VEC cppVar_52430;
	BIT_VEC cppVar_52431;
	bool cppVar_52432;
	BIT_VEC cppVar_52433;
	BIT_VEC cppVar_52434;
	BIT_VEC cppVar_52435;
	BIT_VEC cppVar_52436;
	BIT_VEC cppVar_52437;
	BIT_VEC cppVar_52438;
	BIT_VEC cppVar_52439;
	BIT_VEC cppVar_52427;
	BIT_VEC cppVar_52441;
	BIT_VEC cppVar_52442;
	bool cppVar_52443;
	BIT_VEC cppVar_52445;
	BIT_VEC cppVar_52446;
	BIT_VEC cppVar_52447;
	BIT_VEC cppVar_52448;
	bool cppVar_52449;
	BIT_VEC cppVar_52450;
	BIT_VEC cppVar_52451;
	BIT_VEC cppVar_52452;
	BIT_VEC cppVar_52453;
	BIT_VEC cppVar_52454;
	BIT_VEC cppVar_52455;
	BIT_VEC cppVar_52456;
	BIT_VEC cppVar_52444;
	BIT_VEC cppVar_52458;
	BIT_VEC cppVar_52459;
	bool cppVar_52460;
	BIT_VEC cppVar_52462;
	BIT_VEC cppVar_52463;
	BIT_VEC cppVar_52464;
	BIT_VEC cppVar_52465;
	bool cppVar_52466;
	BIT_VEC cppVar_52468;
	BIT_VEC cppVar_52469;
	BIT_VEC cppVar_52470;
	BIT_VEC cppVar_52471;
	BIT_VEC cppVar_52472;
	bool cppVar_52473;
	BIT_VEC cppVar_52474;
	BIT_VEC cppVar_52475;
	BIT_VEC cppVar_52476;
	BIT_VEC cppVar_52478;
	BIT_VEC cppVar_52479;
	BIT_VEC cppVar_52480;
	bool cppVar_52481;
	BIT_VEC cppVar_52483;
	BIT_VEC cppVar_52484;
	BIT_VEC cppVar_52485;
	bool cppVar_52486;
	BIT_VEC cppVar_52488;
	BIT_VEC cppVar_52489;
	BIT_VEC cppVar_52490;
	bool cppVar_52491;
	BIT_VEC cppVar_52493;
	BIT_VEC cppVar_52494;
	BIT_VEC cppVar_52495;
	bool cppVar_52496;
	BIT_VEC cppVar_52498;
	BIT_VEC cppVar_52499;
	BIT_VEC cppVar_52500;
	bool cppVar_52501;
	BIT_VEC cppVar_52503;
	BIT_VEC cppVar_52504;
	BIT_VEC cppVar_52505;
	bool cppVar_52506;
	BIT_VEC cppVar_52508;
	BIT_VEC cppVar_52509;
	BIT_VEC cppVar_52510;
	bool cppVar_52511;
	BIT_VEC cppVar_52513;
	BIT_VEC cppVar_52514;
	BIT_VEC cppVar_52515;
	bool cppVar_52516;
	BIT_VEC cppVar_52518;
	BIT_VEC cppVar_52519;
	BIT_VEC cppVar_52520;
	bool cppVar_52521;
	BIT_VEC cppVar_52523;
	BIT_VEC cppVar_52524;
	BIT_VEC cppVar_52525;
	bool cppVar_52526;
	BIT_VEC cppVar_52528;
	BIT_VEC cppVar_52529;
	BIT_VEC cppVar_52530;
	bool cppVar_52531;
	BIT_VEC cppVar_52533;
	BIT_VEC cppVar_52534;
	BIT_VEC cppVar_52535;
	bool cppVar_52536;
	BIT_VEC cppVar_52538;
	BIT_VEC cppVar_52539;
	BIT_VEC cppVar_52540;
	bool cppVar_52541;
	BIT_VEC cppVar_52543;
	BIT_VEC cppVar_52544;
	BIT_VEC cppVar_52545;
	bool cppVar_52546;
	BIT_VEC cppVar_52548;
	BIT_VEC cppVar_52549;
	BIT_VEC cppVar_52550;
	bool cppVar_52551;
	BIT_VEC cppVar_52553;
	BIT_VEC cppVar_52554;
	BIT_VEC cppVar_52555;
	bool cppVar_52556;
	BIT_VEC cppVar_52558;
	BIT_VEC cppVar_52559;
	BIT_VEC cppVar_52560;
	bool cppVar_52561;
	BIT_VEC cppVar_52563;
	BIT_VEC cppVar_52564;
	BIT_VEC cppVar_52565;
	bool cppVar_52566;
	BIT_VEC cppVar_52568;
	BIT_VEC cppVar_52569;
	BIT_VEC cppVar_52570;
	bool cppVar_52571;
	BIT_VEC cppVar_52573;
	BIT_VEC cppVar_52574;
	BIT_VEC cppVar_52575;
	bool cppVar_52576;
	BIT_VEC cppVar_52578;
	BIT_VEC cppVar_52579;
	BIT_VEC cppVar_52580;
	bool cppVar_52581;
	BIT_VEC cppVar_52582;
	BIT_VEC cppVar_52577;
	BIT_VEC cppVar_52572;
	BIT_VEC cppVar_52567;
	BIT_VEC cppVar_52562;
	BIT_VEC cppVar_52557;
	BIT_VEC cppVar_52552;
	BIT_VEC cppVar_52547;
	BIT_VEC cppVar_52542;
	BIT_VEC cppVar_52537;
	BIT_VEC cppVar_52532;
	BIT_VEC cppVar_52527;
	BIT_VEC cppVar_52522;
	BIT_VEC cppVar_52517;
	BIT_VEC cppVar_52512;
	BIT_VEC cppVar_52507;
	BIT_VEC cppVar_52502;
	BIT_VEC cppVar_52497;
	BIT_VEC cppVar_52492;
	BIT_VEC cppVar_52487;
	BIT_VEC cppVar_52482;
	BIT_VEC cppVar_52477;
	BIT_VEC cppVar_52467;
	BIT_VEC cppVar_52461;
	BIT_VEC cppVar_52584;
	BIT_VEC cppVar_52585;
	bool cppVar_52586;
	BIT_VEC cppVar_52587;
	BIT_VEC cppVar_52588;
	BIT_VEC cppVar_52590;
	bool cppVar_52591;
	BIT_VEC cppVar_52592;
	BIT_VEC cppVar_52593;
	BIT_VEC cppVar_52589;
	BIT_VEC cppVar_52594;
	BIT_VEC cppVar_52595;
	BIT_VEC cppVar_52596;
	BIT_VEC cppVar_52597;
	BIT_VEC cppVar_52599;
	BIT_VEC cppVar_52600;
	bool cppVar_52601;
	BIT_VEC cppVar_52602;
	BIT_VEC cppVar_52605;
	BIT_VEC cppVar_52606;
	BIT_VEC cppVar_52607;
	BIT_VEC cppVar_52608;
	BIT_VEC cppVar_52609;
	bool cppVar_52610;
	BIT_VEC cppVar_52611;
	BIT_VEC cppVar_52612;
	BIT_VEC cppVar_52613;
	BIT_VEC cppVar_52614;
	BIT_VEC cppVar_52615;
	BIT_VEC cppVar_52616;
	BIT_VEC cppVar_52617;
	BIT_VEC cppVar_52618;
	BIT_VEC cppVar_52619;
	BIT_VEC cppVar_52620;
	BIT_VEC cppVar_52621;
	BIT_VEC cppVar_52604;
	BIT_VEC cppVar_52622;
	BIT_VEC cppVar_52623;
	bool cppVar_52624;
	BIT_VEC cppVar_52626;
	BIT_VEC cppVar_52627;
	BIT_VEC cppVar_52628;
	bool cppVar_52629;
	BIT_VEC cppVar_52630;
	BIT_VEC cppVar_52631;
	BIT_VEC cppVar_52632;
	BIT_VEC cppVar_52633;
	BIT_VEC cppVar_52634;
	BIT_VEC cppVar_52635;
	BIT_VEC cppVar_52636;
	BIT_VEC cppVar_52637;
	BIT_VEC cppVar_52638;
	BIT_VEC cppVar_52625;
	BIT_VEC cppVar_52639;
	BIT_VEC cppVar_52642;
	BIT_VEC cppVar_52643;
	BIT_VEC cppVar_52644;
	bool cppVar_52645;
	BIT_VEC cppVar_52646;
	BIT_VEC cppVar_52647;
	BIT_VEC cppVar_52648;
	BIT_VEC cppVar_52649;
	BIT_VEC cppVar_52650;
	BIT_VEC cppVar_52651;
	BIT_VEC cppVar_52652;
	BIT_VEC cppVar_52653;
	BIT_VEC cppVar_52654;
	BIT_VEC cppVar_52641;
	BIT_VEC cppVar_52655;
	bool cppVar_52656;
	BIT_VEC cppVar_52659;
	BIT_VEC cppVar_52660;
	BIT_VEC cppVar_52661;
	bool cppVar_52662;
	BIT_VEC cppVar_52663;
	BIT_VEC cppVar_52664;
	BIT_VEC cppVar_52665;
	BIT_VEC cppVar_52666;
	BIT_VEC cppVar_52667;
	BIT_VEC cppVar_52668;
	BIT_VEC cppVar_52669;
	BIT_VEC cppVar_52670;
	BIT_VEC cppVar_52671;
	BIT_VEC cppVar_52658;
	BIT_VEC cppVar_52672;
	bool cppVar_52673;
	BIT_VEC cppVar_52676;
	BIT_VEC cppVar_52677;
	BIT_VEC cppVar_52678;
	bool cppVar_52679;
	BIT_VEC cppVar_52680;
	BIT_VEC cppVar_52681;
	BIT_VEC cppVar_52682;
	BIT_VEC cppVar_52683;
	BIT_VEC cppVar_52684;
	BIT_VEC cppVar_52685;
	BIT_VEC cppVar_52686;
	BIT_VEC cppVar_52687;
	BIT_VEC cppVar_52688;
	BIT_VEC cppVar_52675;
	BIT_VEC cppVar_52689;
	bool cppVar_52690;
	BIT_VEC cppVar_52693;
	BIT_VEC cppVar_52694;
	BIT_VEC cppVar_52695;
	bool cppVar_52696;
	BIT_VEC cppVar_52697;
	BIT_VEC cppVar_52698;
	BIT_VEC cppVar_52699;
	BIT_VEC cppVar_52700;
	BIT_VEC cppVar_52701;
	BIT_VEC cppVar_52702;
	BIT_VEC cppVar_52703;
	BIT_VEC cppVar_52704;
	BIT_VEC cppVar_52705;
	BIT_VEC cppVar_52692;
	BIT_VEC cppVar_52706;
	bool cppVar_52707;
	BIT_VEC cppVar_52710;
	BIT_VEC cppVar_52711;
	BIT_VEC cppVar_52712;
	bool cppVar_52713;
	BIT_VEC cppVar_52714;
	BIT_VEC cppVar_52715;
	BIT_VEC cppVar_52716;
	BIT_VEC cppVar_52717;
	BIT_VEC cppVar_52718;
	BIT_VEC cppVar_52719;
	BIT_VEC cppVar_52720;
	BIT_VEC cppVar_52721;
	BIT_VEC cppVar_52722;
	BIT_VEC cppVar_52709;
	BIT_VEC cppVar_52723;
	bool cppVar_52724;
	BIT_VEC cppVar_52727;
	BIT_VEC cppVar_52728;
	BIT_VEC cppVar_52729;
	bool cppVar_52730;
	BIT_VEC cppVar_52731;
	BIT_VEC cppVar_52732;
	BIT_VEC cppVar_52733;
	BIT_VEC cppVar_52734;
	BIT_VEC cppVar_52735;
	BIT_VEC cppVar_52736;
	BIT_VEC cppVar_52737;
	BIT_VEC cppVar_52738;
	BIT_VEC cppVar_52739;
	BIT_VEC cppVar_52726;
	BIT_VEC cppVar_52740;
	bool cppVar_52741;
	BIT_VEC cppVar_52744;
	BIT_VEC cppVar_52745;
	BIT_VEC cppVar_52746;
	bool cppVar_52747;
	BIT_VEC cppVar_52748;
	BIT_VEC cppVar_52749;
	BIT_VEC cppVar_52750;
	BIT_VEC cppVar_52751;
	BIT_VEC cppVar_52752;
	BIT_VEC cppVar_52753;
	BIT_VEC cppVar_52754;
	BIT_VEC cppVar_52755;
	BIT_VEC cppVar_52756;
	BIT_VEC cppVar_52743;
	BIT_VEC cppVar_52757;
	bool cppVar_52758;
	BIT_VEC cppVar_52761;
	BIT_VEC cppVar_52762;
	BIT_VEC cppVar_52763;
	bool cppVar_52764;
	BIT_VEC cppVar_52765;
	BIT_VEC cppVar_52766;
	BIT_VEC cppVar_52767;
	BIT_VEC cppVar_52768;
	BIT_VEC cppVar_52769;
	BIT_VEC cppVar_52770;
	BIT_VEC cppVar_52771;
	BIT_VEC cppVar_52772;
	BIT_VEC cppVar_52773;
	BIT_VEC cppVar_52760;
	BIT_VEC cppVar_52774;
	bool cppVar_52775;
	BIT_VEC cppVar_52778;
	BIT_VEC cppVar_52779;
	BIT_VEC cppVar_52780;
	bool cppVar_52781;
	BIT_VEC cppVar_52782;
	BIT_VEC cppVar_52783;
	BIT_VEC cppVar_52784;
	BIT_VEC cppVar_52785;
	BIT_VEC cppVar_52786;
	BIT_VEC cppVar_52787;
	BIT_VEC cppVar_52788;
	BIT_VEC cppVar_52789;
	BIT_VEC cppVar_52790;
	BIT_VEC cppVar_52777;
	BIT_VEC cppVar_52791;
	bool cppVar_52792;
	BIT_VEC cppVar_52795;
	BIT_VEC cppVar_52796;
	BIT_VEC cppVar_52797;
	bool cppVar_52798;
	BIT_VEC cppVar_52799;
	BIT_VEC cppVar_52800;
	BIT_VEC cppVar_52801;
	BIT_VEC cppVar_52802;
	BIT_VEC cppVar_52803;
	BIT_VEC cppVar_52804;
	BIT_VEC cppVar_52805;
	BIT_VEC cppVar_52806;
	BIT_VEC cppVar_52807;
	BIT_VEC cppVar_52794;
	BIT_VEC cppVar_52808;
	bool cppVar_52809;
	BIT_VEC cppVar_52812;
	BIT_VEC cppVar_52813;
	BIT_VEC cppVar_52814;
	bool cppVar_52815;
	BIT_VEC cppVar_52816;
	BIT_VEC cppVar_52817;
	BIT_VEC cppVar_52818;
	BIT_VEC cppVar_52819;
	BIT_VEC cppVar_52820;
	BIT_VEC cppVar_52821;
	BIT_VEC cppVar_52822;
	BIT_VEC cppVar_52823;
	BIT_VEC cppVar_52824;
	BIT_VEC cppVar_52811;
	BIT_VEC cppVar_52825;
	bool cppVar_52826;
	BIT_VEC cppVar_52829;
	BIT_VEC cppVar_52830;
	BIT_VEC cppVar_52831;
	bool cppVar_52832;
	BIT_VEC cppVar_52833;
	BIT_VEC cppVar_52834;
	BIT_VEC cppVar_52835;
	BIT_VEC cppVar_52836;
	BIT_VEC cppVar_52837;
	BIT_VEC cppVar_52838;
	BIT_VEC cppVar_52839;
	BIT_VEC cppVar_52840;
	BIT_VEC cppVar_52841;
	BIT_VEC cppVar_52828;
	BIT_VEC cppVar_52842;
	bool cppVar_52843;
	BIT_VEC cppVar_52846;
	BIT_VEC cppVar_52847;
	BIT_VEC cppVar_52848;
	bool cppVar_52849;
	BIT_VEC cppVar_52850;
	BIT_VEC cppVar_52851;
	BIT_VEC cppVar_52852;
	BIT_VEC cppVar_52853;
	BIT_VEC cppVar_52854;
	BIT_VEC cppVar_52855;
	BIT_VEC cppVar_52856;
	BIT_VEC cppVar_52857;
	BIT_VEC cppVar_52858;
	BIT_VEC cppVar_52845;
	BIT_VEC cppVar_52859;
	bool cppVar_52860;
	BIT_VEC cppVar_52863;
	BIT_VEC cppVar_52864;
	BIT_VEC cppVar_52865;
	bool cppVar_52866;
	BIT_VEC cppVar_52867;
	BIT_VEC cppVar_52868;
	BIT_VEC cppVar_52869;
	BIT_VEC cppVar_52870;
	BIT_VEC cppVar_52871;
	BIT_VEC cppVar_52872;
	BIT_VEC cppVar_52873;
	BIT_VEC cppVar_52874;
	BIT_VEC cppVar_52875;
	BIT_VEC cppVar_52862;
	BIT_VEC cppVar_52876;
	bool cppVar_52877;
	BIT_VEC cppVar_52880;
	BIT_VEC cppVar_52881;
	BIT_VEC cppVar_52882;
	bool cppVar_52883;
	BIT_VEC cppVar_52884;
	BIT_VEC cppVar_52885;
	BIT_VEC cppVar_52886;
	BIT_VEC cppVar_52887;
	BIT_VEC cppVar_52888;
	BIT_VEC cppVar_52889;
	BIT_VEC cppVar_52890;
	BIT_VEC cppVar_52891;
	BIT_VEC cppVar_52892;
	BIT_VEC cppVar_52879;
	BIT_VEC cppVar_52893;
	bool cppVar_52894;
	BIT_VEC cppVar_52897;
	BIT_VEC cppVar_52898;
	BIT_VEC cppVar_52899;
	bool cppVar_52900;
	BIT_VEC cppVar_52901;
	BIT_VEC cppVar_52902;
	BIT_VEC cppVar_52903;
	BIT_VEC cppVar_52904;
	BIT_VEC cppVar_52905;
	BIT_VEC cppVar_52906;
	BIT_VEC cppVar_52907;
	BIT_VEC cppVar_52908;
	BIT_VEC cppVar_52909;
	BIT_VEC cppVar_52896;
	BIT_VEC cppVar_52910;
	bool cppVar_52911;
	BIT_VEC cppVar_52914;
	BIT_VEC cppVar_52915;
	BIT_VEC cppVar_52916;
	bool cppVar_52917;
	BIT_VEC cppVar_52918;
	BIT_VEC cppVar_52919;
	BIT_VEC cppVar_52920;
	BIT_VEC cppVar_52921;
	BIT_VEC cppVar_52922;
	BIT_VEC cppVar_52923;
	BIT_VEC cppVar_52924;
	BIT_VEC cppVar_52925;
	BIT_VEC cppVar_52926;
	BIT_VEC cppVar_52913;
	BIT_VEC cppVar_52927;
	bool cppVar_52928;
	BIT_VEC cppVar_52931;
	BIT_VEC cppVar_52932;
	BIT_VEC cppVar_52933;
	bool cppVar_52934;
	BIT_VEC cppVar_52935;
	BIT_VEC cppVar_52936;
	BIT_VEC cppVar_52937;
	BIT_VEC cppVar_52938;
	BIT_VEC cppVar_52939;
	BIT_VEC cppVar_52940;
	BIT_VEC cppVar_52941;
	BIT_VEC cppVar_52942;
	BIT_VEC cppVar_52943;
	BIT_VEC cppVar_52930;
	BIT_VEC cppVar_52944;
	bool cppVar_52945;
	BIT_VEC cppVar_52948;
	BIT_VEC cppVar_52949;
	BIT_VEC cppVar_52950;
	bool cppVar_52951;
	BIT_VEC cppVar_52952;
	BIT_VEC cppVar_52953;
	BIT_VEC cppVar_52954;
	BIT_VEC cppVar_52955;
	BIT_VEC cppVar_52956;
	BIT_VEC cppVar_52957;
	BIT_VEC cppVar_52958;
	BIT_VEC cppVar_52959;
	BIT_VEC cppVar_52960;
	BIT_VEC cppVar_52947;
	BIT_VEC cppVar_52961;
	bool cppVar_52962;
	BIT_VEC cppVar_52965;
	BIT_VEC cppVar_52966;
	BIT_VEC cppVar_52967;
	bool cppVar_52968;
	BIT_VEC cppVar_52969;
	BIT_VEC cppVar_52970;
	BIT_VEC cppVar_52971;
	BIT_VEC cppVar_52972;
	BIT_VEC cppVar_52973;
	BIT_VEC cppVar_52974;
	BIT_VEC cppVar_52975;
	BIT_VEC cppVar_52976;
	BIT_VEC cppVar_52977;
	BIT_VEC cppVar_52964;
	BIT_VEC cppVar_52978;
	bool cppVar_52979;
	BIT_VEC cppVar_52982;
	BIT_VEC cppVar_52983;
	BIT_VEC cppVar_52984;
	bool cppVar_52985;
	BIT_VEC cppVar_52986;
	BIT_VEC cppVar_52987;
	BIT_VEC cppVar_52988;
	BIT_VEC cppVar_52989;
	BIT_VEC cppVar_52990;
	BIT_VEC cppVar_52991;
	BIT_VEC cppVar_52992;
	BIT_VEC cppVar_52993;
	BIT_VEC cppVar_52994;
	BIT_VEC cppVar_52981;
	BIT_VEC cppVar_52995;
	bool cppVar_52996;
	BIT_VEC cppVar_52997;
	BIT_VEC cppVar_52980;
	BIT_VEC cppVar_52963;
	BIT_VEC cppVar_52946;
	BIT_VEC cppVar_52929;
	BIT_VEC cppVar_52912;
	BIT_VEC cppVar_52895;
	BIT_VEC cppVar_52878;
	BIT_VEC cppVar_52861;
	BIT_VEC cppVar_52844;
	BIT_VEC cppVar_52827;
	BIT_VEC cppVar_52810;
	BIT_VEC cppVar_52793;
	BIT_VEC cppVar_52776;
	BIT_VEC cppVar_52759;
	BIT_VEC cppVar_52742;
	BIT_VEC cppVar_52725;
	BIT_VEC cppVar_52708;
	BIT_VEC cppVar_52691;
	BIT_VEC cppVar_52674;
	BIT_VEC cppVar_52657;
	BIT_VEC cppVar_52640;
	BIT_VEC cppVar_52603;
	BIT_VEC cppVar_52998;
	BIT_VEC cppVar_52999;
	BIT_VEC cppVar_53000;
	BIT_VEC cppVar_53001;
	BIT_VEC cppVar_53002;
	BIT_VEC cppVar_53003;
	BIT_VEC cppVar_53004;
	BIT_VEC cppVar_53006;
	BIT_VEC cppVar_53007;
	bool cppVar_53008;
	BIT_VEC cppVar_53010;
	BIT_VEC cppVar_53011;
	BIT_VEC cppVar_53012;
	BIT_VEC cppVar_53013;
	bool cppVar_53014;
	BIT_VEC cppVar_53015;
	BIT_VEC cppVar_53016;
	BIT_VEC cppVar_53017;
	BIT_VEC cppVar_53009;
	BIT_VEC cppVar_53019;
	BIT_VEC cppVar_53020;
	bool cppVar_53021;
	BIT_VEC cppVar_53022;
	BIT_VEC cppVar_53025;
	BIT_VEC cppVar_53026;
	BIT_VEC cppVar_53027;
	BIT_VEC cppVar_53028;
	BIT_VEC cppVar_53029;
	bool cppVar_53030;
	BIT_VEC cppVar_53031;
	BIT_VEC cppVar_53032;
	BIT_VEC cppVar_53033;
	BIT_VEC cppVar_53034;
	BIT_VEC cppVar_53035;
	BIT_VEC cppVar_53036;
	BIT_VEC cppVar_53037;
	BIT_VEC cppVar_53038;
	BIT_VEC cppVar_53039;
	BIT_VEC cppVar_53040;
	BIT_VEC cppVar_53041;
	BIT_VEC cppVar_53024;
	BIT_VEC cppVar_53042;
	BIT_VEC cppVar_53043;
	bool cppVar_53044;
	BIT_VEC cppVar_53046;
	BIT_VEC cppVar_53047;
	BIT_VEC cppVar_53048;
	bool cppVar_53049;
	BIT_VEC cppVar_53050;
	BIT_VEC cppVar_53051;
	BIT_VEC cppVar_53052;
	BIT_VEC cppVar_53053;
	BIT_VEC cppVar_53054;
	BIT_VEC cppVar_53055;
	BIT_VEC cppVar_53056;
	BIT_VEC cppVar_53057;
	BIT_VEC cppVar_53058;
	BIT_VEC cppVar_53045;
	BIT_VEC cppVar_53059;
	BIT_VEC cppVar_53062;
	BIT_VEC cppVar_53063;
	BIT_VEC cppVar_53064;
	bool cppVar_53065;
	BIT_VEC cppVar_53066;
	BIT_VEC cppVar_53067;
	BIT_VEC cppVar_53068;
	BIT_VEC cppVar_53069;
	BIT_VEC cppVar_53070;
	BIT_VEC cppVar_53071;
	BIT_VEC cppVar_53072;
	BIT_VEC cppVar_53073;
	BIT_VEC cppVar_53074;
	BIT_VEC cppVar_53061;
	BIT_VEC cppVar_53075;
	bool cppVar_53076;
	BIT_VEC cppVar_53079;
	BIT_VEC cppVar_53080;
	BIT_VEC cppVar_53081;
	bool cppVar_53082;
	BIT_VEC cppVar_53083;
	BIT_VEC cppVar_53084;
	BIT_VEC cppVar_53085;
	BIT_VEC cppVar_53086;
	BIT_VEC cppVar_53087;
	BIT_VEC cppVar_53088;
	BIT_VEC cppVar_53089;
	BIT_VEC cppVar_53090;
	BIT_VEC cppVar_53091;
	BIT_VEC cppVar_53078;
	BIT_VEC cppVar_53092;
	bool cppVar_53093;
	BIT_VEC cppVar_53096;
	BIT_VEC cppVar_53097;
	BIT_VEC cppVar_53098;
	bool cppVar_53099;
	BIT_VEC cppVar_53100;
	BIT_VEC cppVar_53101;
	BIT_VEC cppVar_53102;
	BIT_VEC cppVar_53103;
	BIT_VEC cppVar_53104;
	BIT_VEC cppVar_53105;
	BIT_VEC cppVar_53106;
	BIT_VEC cppVar_53107;
	BIT_VEC cppVar_53108;
	BIT_VEC cppVar_53095;
	BIT_VEC cppVar_53109;
	bool cppVar_53110;
	BIT_VEC cppVar_53113;
	BIT_VEC cppVar_53114;
	BIT_VEC cppVar_53115;
	bool cppVar_53116;
	BIT_VEC cppVar_53117;
	BIT_VEC cppVar_53118;
	BIT_VEC cppVar_53119;
	BIT_VEC cppVar_53120;
	BIT_VEC cppVar_53121;
	BIT_VEC cppVar_53122;
	BIT_VEC cppVar_53123;
	BIT_VEC cppVar_53124;
	BIT_VEC cppVar_53125;
	BIT_VEC cppVar_53112;
	BIT_VEC cppVar_53126;
	bool cppVar_53127;
	BIT_VEC cppVar_53130;
	BIT_VEC cppVar_53131;
	BIT_VEC cppVar_53132;
	bool cppVar_53133;
	BIT_VEC cppVar_53134;
	BIT_VEC cppVar_53135;
	BIT_VEC cppVar_53136;
	BIT_VEC cppVar_53137;
	BIT_VEC cppVar_53138;
	BIT_VEC cppVar_53139;
	BIT_VEC cppVar_53140;
	BIT_VEC cppVar_53141;
	BIT_VEC cppVar_53142;
	BIT_VEC cppVar_53129;
	BIT_VEC cppVar_53143;
	bool cppVar_53144;
	BIT_VEC cppVar_53147;
	BIT_VEC cppVar_53148;
	BIT_VEC cppVar_53149;
	bool cppVar_53150;
	BIT_VEC cppVar_53151;
	BIT_VEC cppVar_53152;
	BIT_VEC cppVar_53153;
	BIT_VEC cppVar_53154;
	BIT_VEC cppVar_53155;
	BIT_VEC cppVar_53156;
	BIT_VEC cppVar_53157;
	BIT_VEC cppVar_53158;
	BIT_VEC cppVar_53159;
	BIT_VEC cppVar_53146;
	BIT_VEC cppVar_53160;
	bool cppVar_53161;
	BIT_VEC cppVar_53164;
	BIT_VEC cppVar_53165;
	BIT_VEC cppVar_53166;
	bool cppVar_53167;
	BIT_VEC cppVar_53168;
	BIT_VEC cppVar_53169;
	BIT_VEC cppVar_53170;
	BIT_VEC cppVar_53171;
	BIT_VEC cppVar_53172;
	BIT_VEC cppVar_53173;
	BIT_VEC cppVar_53174;
	BIT_VEC cppVar_53175;
	BIT_VEC cppVar_53176;
	BIT_VEC cppVar_53163;
	BIT_VEC cppVar_53177;
	bool cppVar_53178;
	BIT_VEC cppVar_53181;
	BIT_VEC cppVar_53182;
	BIT_VEC cppVar_53183;
	bool cppVar_53184;
	BIT_VEC cppVar_53185;
	BIT_VEC cppVar_53186;
	BIT_VEC cppVar_53187;
	BIT_VEC cppVar_53188;
	BIT_VEC cppVar_53189;
	BIT_VEC cppVar_53190;
	BIT_VEC cppVar_53191;
	BIT_VEC cppVar_53192;
	BIT_VEC cppVar_53193;
	BIT_VEC cppVar_53180;
	BIT_VEC cppVar_53194;
	bool cppVar_53195;
	BIT_VEC cppVar_53198;
	BIT_VEC cppVar_53199;
	BIT_VEC cppVar_53200;
	bool cppVar_53201;
	BIT_VEC cppVar_53202;
	BIT_VEC cppVar_53203;
	BIT_VEC cppVar_53204;
	BIT_VEC cppVar_53205;
	BIT_VEC cppVar_53206;
	BIT_VEC cppVar_53207;
	BIT_VEC cppVar_53208;
	BIT_VEC cppVar_53209;
	BIT_VEC cppVar_53210;
	BIT_VEC cppVar_53197;
	BIT_VEC cppVar_53211;
	bool cppVar_53212;
	BIT_VEC cppVar_53215;
	BIT_VEC cppVar_53216;
	BIT_VEC cppVar_53217;
	bool cppVar_53218;
	BIT_VEC cppVar_53219;
	BIT_VEC cppVar_53220;
	BIT_VEC cppVar_53221;
	BIT_VEC cppVar_53222;
	BIT_VEC cppVar_53223;
	BIT_VEC cppVar_53224;
	BIT_VEC cppVar_53225;
	BIT_VEC cppVar_53226;
	BIT_VEC cppVar_53227;
	BIT_VEC cppVar_53214;
	BIT_VEC cppVar_53228;
	bool cppVar_53229;
	BIT_VEC cppVar_53232;
	BIT_VEC cppVar_53233;
	BIT_VEC cppVar_53234;
	bool cppVar_53235;
	BIT_VEC cppVar_53236;
	BIT_VEC cppVar_53237;
	BIT_VEC cppVar_53238;
	BIT_VEC cppVar_53239;
	BIT_VEC cppVar_53240;
	BIT_VEC cppVar_53241;
	BIT_VEC cppVar_53242;
	BIT_VEC cppVar_53243;
	BIT_VEC cppVar_53244;
	BIT_VEC cppVar_53231;
	BIT_VEC cppVar_53245;
	bool cppVar_53246;
	BIT_VEC cppVar_53249;
	BIT_VEC cppVar_53250;
	BIT_VEC cppVar_53251;
	bool cppVar_53252;
	BIT_VEC cppVar_53253;
	BIT_VEC cppVar_53254;
	BIT_VEC cppVar_53255;
	BIT_VEC cppVar_53256;
	BIT_VEC cppVar_53257;
	BIT_VEC cppVar_53258;
	BIT_VEC cppVar_53259;
	BIT_VEC cppVar_53260;
	BIT_VEC cppVar_53261;
	BIT_VEC cppVar_53248;
	BIT_VEC cppVar_53262;
	bool cppVar_53263;
	BIT_VEC cppVar_53266;
	BIT_VEC cppVar_53267;
	BIT_VEC cppVar_53268;
	bool cppVar_53269;
	BIT_VEC cppVar_53270;
	BIT_VEC cppVar_53271;
	BIT_VEC cppVar_53272;
	BIT_VEC cppVar_53273;
	BIT_VEC cppVar_53274;
	BIT_VEC cppVar_53275;
	BIT_VEC cppVar_53276;
	BIT_VEC cppVar_53277;
	BIT_VEC cppVar_53278;
	BIT_VEC cppVar_53265;
	BIT_VEC cppVar_53279;
	bool cppVar_53280;
	BIT_VEC cppVar_53283;
	BIT_VEC cppVar_53284;
	BIT_VEC cppVar_53285;
	bool cppVar_53286;
	BIT_VEC cppVar_53287;
	BIT_VEC cppVar_53288;
	BIT_VEC cppVar_53289;
	BIT_VEC cppVar_53290;
	BIT_VEC cppVar_53291;
	BIT_VEC cppVar_53292;
	BIT_VEC cppVar_53293;
	BIT_VEC cppVar_53294;
	BIT_VEC cppVar_53295;
	BIT_VEC cppVar_53282;
	BIT_VEC cppVar_53296;
	bool cppVar_53297;
	BIT_VEC cppVar_53300;
	BIT_VEC cppVar_53301;
	BIT_VEC cppVar_53302;
	bool cppVar_53303;
	BIT_VEC cppVar_53304;
	BIT_VEC cppVar_53305;
	BIT_VEC cppVar_53306;
	BIT_VEC cppVar_53307;
	BIT_VEC cppVar_53308;
	BIT_VEC cppVar_53309;
	BIT_VEC cppVar_53310;
	BIT_VEC cppVar_53311;
	BIT_VEC cppVar_53312;
	BIT_VEC cppVar_53299;
	BIT_VEC cppVar_53313;
	bool cppVar_53314;
	BIT_VEC cppVar_53317;
	BIT_VEC cppVar_53318;
	BIT_VEC cppVar_53319;
	bool cppVar_53320;
	BIT_VEC cppVar_53321;
	BIT_VEC cppVar_53322;
	BIT_VEC cppVar_53323;
	BIT_VEC cppVar_53324;
	BIT_VEC cppVar_53325;
	BIT_VEC cppVar_53326;
	BIT_VEC cppVar_53327;
	BIT_VEC cppVar_53328;
	BIT_VEC cppVar_53329;
	BIT_VEC cppVar_53316;
	BIT_VEC cppVar_53330;
	bool cppVar_53331;
	BIT_VEC cppVar_53334;
	BIT_VEC cppVar_53335;
	BIT_VEC cppVar_53336;
	bool cppVar_53337;
	BIT_VEC cppVar_53338;
	BIT_VEC cppVar_53339;
	BIT_VEC cppVar_53340;
	BIT_VEC cppVar_53341;
	BIT_VEC cppVar_53342;
	BIT_VEC cppVar_53343;
	BIT_VEC cppVar_53344;
	BIT_VEC cppVar_53345;
	BIT_VEC cppVar_53346;
	BIT_VEC cppVar_53333;
	BIT_VEC cppVar_53347;
	bool cppVar_53348;
	BIT_VEC cppVar_53351;
	BIT_VEC cppVar_53352;
	BIT_VEC cppVar_53353;
	bool cppVar_53354;
	BIT_VEC cppVar_53355;
	BIT_VEC cppVar_53356;
	BIT_VEC cppVar_53357;
	BIT_VEC cppVar_53358;
	BIT_VEC cppVar_53359;
	BIT_VEC cppVar_53360;
	BIT_VEC cppVar_53361;
	BIT_VEC cppVar_53362;
	BIT_VEC cppVar_53363;
	BIT_VEC cppVar_53350;
	BIT_VEC cppVar_53364;
	bool cppVar_53365;
	BIT_VEC cppVar_53368;
	BIT_VEC cppVar_53369;
	BIT_VEC cppVar_53370;
	bool cppVar_53371;
	BIT_VEC cppVar_53372;
	BIT_VEC cppVar_53373;
	BIT_VEC cppVar_53374;
	BIT_VEC cppVar_53375;
	BIT_VEC cppVar_53376;
	BIT_VEC cppVar_53377;
	BIT_VEC cppVar_53378;
	BIT_VEC cppVar_53379;
	BIT_VEC cppVar_53380;
	BIT_VEC cppVar_53367;
	BIT_VEC cppVar_53381;
	bool cppVar_53382;
	BIT_VEC cppVar_53385;
	BIT_VEC cppVar_53386;
	BIT_VEC cppVar_53387;
	bool cppVar_53388;
	BIT_VEC cppVar_53389;
	BIT_VEC cppVar_53390;
	BIT_VEC cppVar_53391;
	BIT_VEC cppVar_53392;
	BIT_VEC cppVar_53393;
	BIT_VEC cppVar_53394;
	BIT_VEC cppVar_53395;
	BIT_VEC cppVar_53396;
	BIT_VEC cppVar_53397;
	BIT_VEC cppVar_53384;
	BIT_VEC cppVar_53398;
	bool cppVar_53399;
	BIT_VEC cppVar_53402;
	BIT_VEC cppVar_53403;
	BIT_VEC cppVar_53404;
	bool cppVar_53405;
	BIT_VEC cppVar_53406;
	BIT_VEC cppVar_53407;
	BIT_VEC cppVar_53408;
	BIT_VEC cppVar_53409;
	BIT_VEC cppVar_53410;
	BIT_VEC cppVar_53411;
	BIT_VEC cppVar_53412;
	BIT_VEC cppVar_53413;
	BIT_VEC cppVar_53414;
	BIT_VEC cppVar_53401;
	BIT_VEC cppVar_53415;
	bool cppVar_53416;
	BIT_VEC cppVar_53417;
	BIT_VEC cppVar_53400;
	BIT_VEC cppVar_53383;
	BIT_VEC cppVar_53366;
	BIT_VEC cppVar_53349;
	BIT_VEC cppVar_53332;
	BIT_VEC cppVar_53315;
	BIT_VEC cppVar_53298;
	BIT_VEC cppVar_53281;
	BIT_VEC cppVar_53264;
	BIT_VEC cppVar_53247;
	BIT_VEC cppVar_53230;
	BIT_VEC cppVar_53213;
	BIT_VEC cppVar_53196;
	BIT_VEC cppVar_53179;
	BIT_VEC cppVar_53162;
	BIT_VEC cppVar_53145;
	BIT_VEC cppVar_53128;
	BIT_VEC cppVar_53111;
	BIT_VEC cppVar_53094;
	BIT_VEC cppVar_53077;
	BIT_VEC cppVar_53060;
	BIT_VEC cppVar_53023;
	BIT_VEC cppVar_53418;
	BIT_VEC cppVar_53419;
	BIT_VEC cppVar_53420;
	BIT_VEC cppVar_53421;
	BIT_VEC cppVar_53422;
	BIT_VEC cppVar_53423;
	BIT_VEC cppVar_53424;
	BIT_VEC cppVar_53426;
	BIT_VEC cppVar_53427;
	bool cppVar_53428;
	BIT_VEC cppVar_53430;
	BIT_VEC cppVar_53431;
	BIT_VEC cppVar_53432;
	BIT_VEC cppVar_53433;
	bool cppVar_53434;
	BIT_VEC cppVar_53436;
	BIT_VEC cppVar_53437;
	BIT_VEC cppVar_53438;
	BIT_VEC cppVar_53439;
	bool cppVar_53440;
	BIT_VEC cppVar_53441;
	BIT_VEC cppVar_53442;
	BIT_VEC cppVar_53443;
	BIT_VEC cppVar_53445;
	BIT_VEC cppVar_53446;
	BIT_VEC cppVar_53447;
	bool cppVar_53448;
	BIT_VEC cppVar_53450;
	BIT_VEC cppVar_53451;
	BIT_VEC cppVar_53452;
	bool cppVar_53453;
	BIT_VEC cppVar_53455;
	BIT_VEC cppVar_53456;
	BIT_VEC cppVar_53457;
	bool cppVar_53458;
	BIT_VEC cppVar_53460;
	BIT_VEC cppVar_53461;
	BIT_VEC cppVar_53462;
	bool cppVar_53463;
	BIT_VEC cppVar_53465;
	BIT_VEC cppVar_53466;
	BIT_VEC cppVar_53467;
	bool cppVar_53468;
	BIT_VEC cppVar_53470;
	BIT_VEC cppVar_53471;
	BIT_VEC cppVar_53472;
	bool cppVar_53473;
	BIT_VEC cppVar_53475;
	BIT_VEC cppVar_53476;
	BIT_VEC cppVar_53477;
	bool cppVar_53478;
	BIT_VEC cppVar_53480;
	BIT_VEC cppVar_53481;
	BIT_VEC cppVar_53482;
	bool cppVar_53483;
	BIT_VEC cppVar_53485;
	BIT_VEC cppVar_53486;
	BIT_VEC cppVar_53487;
	bool cppVar_53488;
	BIT_VEC cppVar_53490;
	BIT_VEC cppVar_53491;
	BIT_VEC cppVar_53492;
	bool cppVar_53493;
	BIT_VEC cppVar_53495;
	BIT_VEC cppVar_53496;
	BIT_VEC cppVar_53497;
	bool cppVar_53498;
	BIT_VEC cppVar_53500;
	BIT_VEC cppVar_53501;
	BIT_VEC cppVar_53502;
	bool cppVar_53503;
	BIT_VEC cppVar_53505;
	BIT_VEC cppVar_53506;
	BIT_VEC cppVar_53507;
	bool cppVar_53508;
	BIT_VEC cppVar_53510;
	BIT_VEC cppVar_53511;
	BIT_VEC cppVar_53512;
	bool cppVar_53513;
	BIT_VEC cppVar_53515;
	BIT_VEC cppVar_53516;
	BIT_VEC cppVar_53517;
	bool cppVar_53518;
	BIT_VEC cppVar_53520;
	BIT_VEC cppVar_53521;
	BIT_VEC cppVar_53522;
	bool cppVar_53523;
	BIT_VEC cppVar_53525;
	BIT_VEC cppVar_53526;
	BIT_VEC cppVar_53527;
	bool cppVar_53528;
	BIT_VEC cppVar_53530;
	BIT_VEC cppVar_53531;
	BIT_VEC cppVar_53532;
	bool cppVar_53533;
	BIT_VEC cppVar_53535;
	BIT_VEC cppVar_53536;
	BIT_VEC cppVar_53537;
	bool cppVar_53538;
	BIT_VEC cppVar_53540;
	BIT_VEC cppVar_53541;
	BIT_VEC cppVar_53542;
	bool cppVar_53543;
	BIT_VEC cppVar_53545;
	BIT_VEC cppVar_53546;
	BIT_VEC cppVar_53547;
	bool cppVar_53548;
	BIT_VEC cppVar_53549;
	BIT_VEC cppVar_53544;
	BIT_VEC cppVar_53539;
	BIT_VEC cppVar_53534;
	BIT_VEC cppVar_53529;
	BIT_VEC cppVar_53524;
	BIT_VEC cppVar_53519;
	BIT_VEC cppVar_53514;
	BIT_VEC cppVar_53509;
	BIT_VEC cppVar_53504;
	BIT_VEC cppVar_53499;
	BIT_VEC cppVar_53494;
	BIT_VEC cppVar_53489;
	BIT_VEC cppVar_53484;
	BIT_VEC cppVar_53479;
	BIT_VEC cppVar_53474;
	BIT_VEC cppVar_53469;
	BIT_VEC cppVar_53464;
	BIT_VEC cppVar_53459;
	BIT_VEC cppVar_53454;
	BIT_VEC cppVar_53449;
	BIT_VEC cppVar_53444;
	BIT_VEC cppVar_53435;
	BIT_VEC cppVar_53550;
	BIT_VEC cppVar_53551;
	BIT_VEC cppVar_53552;
	BIT_VEC cppVar_53553;
	BIT_VEC cppVar_53429;
	BIT_VEC cppVar_53555;
	BIT_VEC cppVar_53556;
	bool cppVar_53557;
	BIT_VEC cppVar_53559;
	BIT_VEC cppVar_53560;
	BIT_VEC cppVar_53561;
	BIT_VEC cppVar_53562;
	bool cppVar_53563;
	BIT_VEC cppVar_53565;
	BIT_VEC cppVar_53566;
	BIT_VEC cppVar_53567;
	BIT_VEC cppVar_53568;
	bool cppVar_53569;
	BIT_VEC cppVar_53570;
	BIT_VEC cppVar_53571;
	BIT_VEC cppVar_53572;
	BIT_VEC cppVar_53574;
	BIT_VEC cppVar_53575;
	BIT_VEC cppVar_53576;
	bool cppVar_53577;
	BIT_VEC cppVar_53579;
	BIT_VEC cppVar_53580;
	BIT_VEC cppVar_53581;
	bool cppVar_53582;
	BIT_VEC cppVar_53584;
	BIT_VEC cppVar_53585;
	BIT_VEC cppVar_53586;
	bool cppVar_53587;
	BIT_VEC cppVar_53589;
	BIT_VEC cppVar_53590;
	BIT_VEC cppVar_53591;
	bool cppVar_53592;
	BIT_VEC cppVar_53594;
	BIT_VEC cppVar_53595;
	BIT_VEC cppVar_53596;
	bool cppVar_53597;
	BIT_VEC cppVar_53599;
	BIT_VEC cppVar_53600;
	BIT_VEC cppVar_53601;
	bool cppVar_53602;
	BIT_VEC cppVar_53604;
	BIT_VEC cppVar_53605;
	BIT_VEC cppVar_53606;
	bool cppVar_53607;
	BIT_VEC cppVar_53609;
	BIT_VEC cppVar_53610;
	BIT_VEC cppVar_53611;
	bool cppVar_53612;
	BIT_VEC cppVar_53614;
	BIT_VEC cppVar_53615;
	BIT_VEC cppVar_53616;
	bool cppVar_53617;
	BIT_VEC cppVar_53619;
	BIT_VEC cppVar_53620;
	BIT_VEC cppVar_53621;
	bool cppVar_53622;
	BIT_VEC cppVar_53624;
	BIT_VEC cppVar_53625;
	BIT_VEC cppVar_53626;
	bool cppVar_53627;
	BIT_VEC cppVar_53629;
	BIT_VEC cppVar_53630;
	BIT_VEC cppVar_53631;
	bool cppVar_53632;
	BIT_VEC cppVar_53634;
	BIT_VEC cppVar_53635;
	BIT_VEC cppVar_53636;
	bool cppVar_53637;
	BIT_VEC cppVar_53639;
	BIT_VEC cppVar_53640;
	BIT_VEC cppVar_53641;
	bool cppVar_53642;
	BIT_VEC cppVar_53644;
	BIT_VEC cppVar_53645;
	BIT_VEC cppVar_53646;
	bool cppVar_53647;
	BIT_VEC cppVar_53649;
	BIT_VEC cppVar_53650;
	BIT_VEC cppVar_53651;
	bool cppVar_53652;
	BIT_VEC cppVar_53654;
	BIT_VEC cppVar_53655;
	BIT_VEC cppVar_53656;
	bool cppVar_53657;
	BIT_VEC cppVar_53659;
	BIT_VEC cppVar_53660;
	BIT_VEC cppVar_53661;
	bool cppVar_53662;
	BIT_VEC cppVar_53664;
	BIT_VEC cppVar_53665;
	BIT_VEC cppVar_53666;
	bool cppVar_53667;
	BIT_VEC cppVar_53669;
	BIT_VEC cppVar_53670;
	BIT_VEC cppVar_53671;
	bool cppVar_53672;
	BIT_VEC cppVar_53674;
	BIT_VEC cppVar_53675;
	BIT_VEC cppVar_53676;
	bool cppVar_53677;
	BIT_VEC cppVar_53678;
	BIT_VEC cppVar_53673;
	BIT_VEC cppVar_53668;
	BIT_VEC cppVar_53663;
	BIT_VEC cppVar_53658;
	BIT_VEC cppVar_53653;
	BIT_VEC cppVar_53648;
	BIT_VEC cppVar_53643;
	BIT_VEC cppVar_53638;
	BIT_VEC cppVar_53633;
	BIT_VEC cppVar_53628;
	BIT_VEC cppVar_53623;
	BIT_VEC cppVar_53618;
	BIT_VEC cppVar_53613;
	BIT_VEC cppVar_53608;
	BIT_VEC cppVar_53603;
	BIT_VEC cppVar_53598;
	BIT_VEC cppVar_53593;
	BIT_VEC cppVar_53588;
	BIT_VEC cppVar_53583;
	BIT_VEC cppVar_53578;
	BIT_VEC cppVar_53573;
	BIT_VEC cppVar_53564;
	BIT_VEC cppVar_53679;
	BIT_VEC cppVar_53558;
	BIT_VEC cppVar_53681;
	BIT_VEC cppVar_53682;
	bool cppVar_53683;
	BIT_VEC cppVar_53685;
	BIT_VEC cppVar_53686;
	BIT_VEC cppVar_53687;
	BIT_VEC cppVar_53688;
	bool cppVar_53689;
	BIT_VEC cppVar_53691;
	BIT_VEC cppVar_53692;
	BIT_VEC cppVar_53693;
	BIT_VEC cppVar_53694;
	bool cppVar_53695;
	BIT_VEC cppVar_53696;
	BIT_VEC cppVar_53697;
	BIT_VEC cppVar_53698;
	BIT_VEC cppVar_53700;
	BIT_VEC cppVar_53701;
	BIT_VEC cppVar_53702;
	bool cppVar_53703;
	BIT_VEC cppVar_53705;
	BIT_VEC cppVar_53706;
	BIT_VEC cppVar_53707;
	bool cppVar_53708;
	BIT_VEC cppVar_53710;
	BIT_VEC cppVar_53711;
	BIT_VEC cppVar_53712;
	bool cppVar_53713;
	BIT_VEC cppVar_53715;
	BIT_VEC cppVar_53716;
	BIT_VEC cppVar_53717;
	bool cppVar_53718;
	BIT_VEC cppVar_53720;
	BIT_VEC cppVar_53721;
	BIT_VEC cppVar_53722;
	bool cppVar_53723;
	BIT_VEC cppVar_53725;
	BIT_VEC cppVar_53726;
	BIT_VEC cppVar_53727;
	bool cppVar_53728;
	BIT_VEC cppVar_53730;
	BIT_VEC cppVar_53731;
	BIT_VEC cppVar_53732;
	bool cppVar_53733;
	BIT_VEC cppVar_53735;
	BIT_VEC cppVar_53736;
	BIT_VEC cppVar_53737;
	bool cppVar_53738;
	BIT_VEC cppVar_53740;
	BIT_VEC cppVar_53741;
	BIT_VEC cppVar_53742;
	bool cppVar_53743;
	BIT_VEC cppVar_53745;
	BIT_VEC cppVar_53746;
	BIT_VEC cppVar_53747;
	bool cppVar_53748;
	BIT_VEC cppVar_53750;
	BIT_VEC cppVar_53751;
	BIT_VEC cppVar_53752;
	bool cppVar_53753;
	BIT_VEC cppVar_53755;
	BIT_VEC cppVar_53756;
	BIT_VEC cppVar_53757;
	bool cppVar_53758;
	BIT_VEC cppVar_53760;
	BIT_VEC cppVar_53761;
	BIT_VEC cppVar_53762;
	bool cppVar_53763;
	BIT_VEC cppVar_53765;
	BIT_VEC cppVar_53766;
	BIT_VEC cppVar_53767;
	bool cppVar_53768;
	BIT_VEC cppVar_53770;
	BIT_VEC cppVar_53771;
	BIT_VEC cppVar_53772;
	bool cppVar_53773;
	BIT_VEC cppVar_53775;
	BIT_VEC cppVar_53776;
	BIT_VEC cppVar_53777;
	bool cppVar_53778;
	BIT_VEC cppVar_53780;
	BIT_VEC cppVar_53781;
	BIT_VEC cppVar_53782;
	bool cppVar_53783;
	BIT_VEC cppVar_53785;
	BIT_VEC cppVar_53786;
	BIT_VEC cppVar_53787;
	bool cppVar_53788;
	BIT_VEC cppVar_53790;
	BIT_VEC cppVar_53791;
	BIT_VEC cppVar_53792;
	bool cppVar_53793;
	BIT_VEC cppVar_53795;
	BIT_VEC cppVar_53796;
	BIT_VEC cppVar_53797;
	bool cppVar_53798;
	BIT_VEC cppVar_53800;
	BIT_VEC cppVar_53801;
	BIT_VEC cppVar_53802;
	bool cppVar_53803;
	BIT_VEC cppVar_53804;
	BIT_VEC cppVar_53799;
	BIT_VEC cppVar_53794;
	BIT_VEC cppVar_53789;
	BIT_VEC cppVar_53784;
	BIT_VEC cppVar_53779;
	BIT_VEC cppVar_53774;
	BIT_VEC cppVar_53769;
	BIT_VEC cppVar_53764;
	BIT_VEC cppVar_53759;
	BIT_VEC cppVar_53754;
	BIT_VEC cppVar_53749;
	BIT_VEC cppVar_53744;
	BIT_VEC cppVar_53739;
	BIT_VEC cppVar_53734;
	BIT_VEC cppVar_53729;
	BIT_VEC cppVar_53724;
	BIT_VEC cppVar_53719;
	BIT_VEC cppVar_53714;
	BIT_VEC cppVar_53709;
	BIT_VEC cppVar_53704;
	BIT_VEC cppVar_53699;
	BIT_VEC cppVar_53690;
	BIT_VEC cppVar_53805;
	BIT_VEC cppVar_53806;
	BIT_VEC cppVar_53807;
	BIT_VEC cppVar_53808;
	BIT_VEC cppVar_53684;
	BIT_VEC cppVar_53810;
	BIT_VEC cppVar_53811;
	bool cppVar_53812;
	BIT_VEC cppVar_53814;
	BIT_VEC cppVar_53815;
	BIT_VEC cppVar_53816;
	BIT_VEC cppVar_53817;
	bool cppVar_53818;
	BIT_VEC cppVar_53820;
	BIT_VEC cppVar_53821;
	BIT_VEC cppVar_53822;
	BIT_VEC cppVar_53823;
	bool cppVar_53824;
	BIT_VEC cppVar_53825;
	BIT_VEC cppVar_53826;
	BIT_VEC cppVar_53827;
	BIT_VEC cppVar_53829;
	BIT_VEC cppVar_53830;
	BIT_VEC cppVar_53831;
	bool cppVar_53832;
	BIT_VEC cppVar_53834;
	BIT_VEC cppVar_53835;
	BIT_VEC cppVar_53836;
	bool cppVar_53837;
	BIT_VEC cppVar_53839;
	BIT_VEC cppVar_53840;
	BIT_VEC cppVar_53841;
	bool cppVar_53842;
	BIT_VEC cppVar_53844;
	BIT_VEC cppVar_53845;
	BIT_VEC cppVar_53846;
	bool cppVar_53847;
	BIT_VEC cppVar_53849;
	BIT_VEC cppVar_53850;
	BIT_VEC cppVar_53851;
	bool cppVar_53852;
	BIT_VEC cppVar_53854;
	BIT_VEC cppVar_53855;
	BIT_VEC cppVar_53856;
	bool cppVar_53857;
	BIT_VEC cppVar_53859;
	BIT_VEC cppVar_53860;
	BIT_VEC cppVar_53861;
	bool cppVar_53862;
	BIT_VEC cppVar_53864;
	BIT_VEC cppVar_53865;
	BIT_VEC cppVar_53866;
	bool cppVar_53867;
	BIT_VEC cppVar_53869;
	BIT_VEC cppVar_53870;
	BIT_VEC cppVar_53871;
	bool cppVar_53872;
	BIT_VEC cppVar_53874;
	BIT_VEC cppVar_53875;
	BIT_VEC cppVar_53876;
	bool cppVar_53877;
	BIT_VEC cppVar_53879;
	BIT_VEC cppVar_53880;
	BIT_VEC cppVar_53881;
	bool cppVar_53882;
	BIT_VEC cppVar_53884;
	BIT_VEC cppVar_53885;
	BIT_VEC cppVar_53886;
	bool cppVar_53887;
	BIT_VEC cppVar_53889;
	BIT_VEC cppVar_53890;
	BIT_VEC cppVar_53891;
	bool cppVar_53892;
	BIT_VEC cppVar_53894;
	BIT_VEC cppVar_53895;
	BIT_VEC cppVar_53896;
	bool cppVar_53897;
	BIT_VEC cppVar_53899;
	BIT_VEC cppVar_53900;
	BIT_VEC cppVar_53901;
	bool cppVar_53902;
	BIT_VEC cppVar_53904;
	BIT_VEC cppVar_53905;
	BIT_VEC cppVar_53906;
	bool cppVar_53907;
	BIT_VEC cppVar_53909;
	BIT_VEC cppVar_53910;
	BIT_VEC cppVar_53911;
	bool cppVar_53912;
	BIT_VEC cppVar_53914;
	BIT_VEC cppVar_53915;
	BIT_VEC cppVar_53916;
	bool cppVar_53917;
	BIT_VEC cppVar_53919;
	BIT_VEC cppVar_53920;
	BIT_VEC cppVar_53921;
	bool cppVar_53922;
	BIT_VEC cppVar_53924;
	BIT_VEC cppVar_53925;
	BIT_VEC cppVar_53926;
	bool cppVar_53927;
	BIT_VEC cppVar_53929;
	BIT_VEC cppVar_53930;
	BIT_VEC cppVar_53931;
	bool cppVar_53932;
	BIT_VEC cppVar_53933;
	BIT_VEC cppVar_53928;
	BIT_VEC cppVar_53923;
	BIT_VEC cppVar_53918;
	BIT_VEC cppVar_53913;
	BIT_VEC cppVar_53908;
	BIT_VEC cppVar_53903;
	BIT_VEC cppVar_53898;
	BIT_VEC cppVar_53893;
	BIT_VEC cppVar_53888;
	BIT_VEC cppVar_53883;
	BIT_VEC cppVar_53878;
	BIT_VEC cppVar_53873;
	BIT_VEC cppVar_53868;
	BIT_VEC cppVar_53863;
	BIT_VEC cppVar_53858;
	BIT_VEC cppVar_53853;
	BIT_VEC cppVar_53848;
	BIT_VEC cppVar_53843;
	BIT_VEC cppVar_53838;
	BIT_VEC cppVar_53833;
	BIT_VEC cppVar_53828;
	BIT_VEC cppVar_53819;
	BIT_VEC cppVar_53934;
	BIT_VEC cppVar_53813;
	BIT_VEC cppVar_53936;
	BIT_VEC cppVar_53937;
	bool cppVar_53938;
	BIT_VEC cppVar_53940;
	BIT_VEC cppVar_53941;
	BIT_VEC cppVar_53942;
	BIT_VEC cppVar_53943;
	bool cppVar_53944;
	BIT_VEC cppVar_53946;
	BIT_VEC cppVar_53947;
	BIT_VEC cppVar_53948;
	BIT_VEC cppVar_53949;
	bool cppVar_53950;
	BIT_VEC cppVar_53951;
	BIT_VEC cppVar_53952;
	BIT_VEC cppVar_53953;
	BIT_VEC cppVar_53955;
	BIT_VEC cppVar_53956;
	BIT_VEC cppVar_53957;
	bool cppVar_53958;
	BIT_VEC cppVar_53960;
	BIT_VEC cppVar_53961;
	BIT_VEC cppVar_53962;
	bool cppVar_53963;
	BIT_VEC cppVar_53965;
	BIT_VEC cppVar_53966;
	BIT_VEC cppVar_53967;
	bool cppVar_53968;
	BIT_VEC cppVar_53970;
	BIT_VEC cppVar_53971;
	BIT_VEC cppVar_53972;
	bool cppVar_53973;
	BIT_VEC cppVar_53975;
	BIT_VEC cppVar_53976;
	BIT_VEC cppVar_53977;
	bool cppVar_53978;
	BIT_VEC cppVar_53980;
	BIT_VEC cppVar_53981;
	BIT_VEC cppVar_53982;
	bool cppVar_53983;
	BIT_VEC cppVar_53985;
	BIT_VEC cppVar_53986;
	BIT_VEC cppVar_53987;
	bool cppVar_53988;
	BIT_VEC cppVar_53990;
	BIT_VEC cppVar_53991;
	BIT_VEC cppVar_53992;
	bool cppVar_53993;
	BIT_VEC cppVar_53995;
	BIT_VEC cppVar_53996;
	BIT_VEC cppVar_53997;
	bool cppVar_53998;
	BIT_VEC cppVar_54000;
	BIT_VEC cppVar_54001;
	BIT_VEC cppVar_54002;
	bool cppVar_54003;
	BIT_VEC cppVar_54005;
	BIT_VEC cppVar_54006;
	BIT_VEC cppVar_54007;
	bool cppVar_54008;
	BIT_VEC cppVar_54010;
	BIT_VEC cppVar_54011;
	BIT_VEC cppVar_54012;
	bool cppVar_54013;
	BIT_VEC cppVar_54015;
	BIT_VEC cppVar_54016;
	BIT_VEC cppVar_54017;
	bool cppVar_54018;
	BIT_VEC cppVar_54020;
	BIT_VEC cppVar_54021;
	BIT_VEC cppVar_54022;
	bool cppVar_54023;
	BIT_VEC cppVar_54025;
	BIT_VEC cppVar_54026;
	BIT_VEC cppVar_54027;
	bool cppVar_54028;
	BIT_VEC cppVar_54030;
	BIT_VEC cppVar_54031;
	BIT_VEC cppVar_54032;
	bool cppVar_54033;
	BIT_VEC cppVar_54035;
	BIT_VEC cppVar_54036;
	BIT_VEC cppVar_54037;
	bool cppVar_54038;
	BIT_VEC cppVar_54040;
	BIT_VEC cppVar_54041;
	BIT_VEC cppVar_54042;
	bool cppVar_54043;
	BIT_VEC cppVar_54045;
	BIT_VEC cppVar_54046;
	BIT_VEC cppVar_54047;
	bool cppVar_54048;
	BIT_VEC cppVar_54050;
	BIT_VEC cppVar_54051;
	BIT_VEC cppVar_54052;
	bool cppVar_54053;
	BIT_VEC cppVar_54055;
	BIT_VEC cppVar_54056;
	BIT_VEC cppVar_54057;
	bool cppVar_54058;
	BIT_VEC cppVar_54059;
	BIT_VEC cppVar_54054;
	BIT_VEC cppVar_54049;
	BIT_VEC cppVar_54044;
	BIT_VEC cppVar_54039;
	BIT_VEC cppVar_54034;
	BIT_VEC cppVar_54029;
	BIT_VEC cppVar_54024;
	BIT_VEC cppVar_54019;
	BIT_VEC cppVar_54014;
	BIT_VEC cppVar_54009;
	BIT_VEC cppVar_54004;
	BIT_VEC cppVar_53999;
	BIT_VEC cppVar_53994;
	BIT_VEC cppVar_53989;
	BIT_VEC cppVar_53984;
	BIT_VEC cppVar_53979;
	BIT_VEC cppVar_53974;
	BIT_VEC cppVar_53969;
	BIT_VEC cppVar_53964;
	BIT_VEC cppVar_53959;
	BIT_VEC cppVar_53954;
	BIT_VEC cppVar_53945;
	BIT_VEC cppVar_54060;
	BIT_VEC cppVar_54061;
	BIT_VEC cppVar_54062;
	BIT_VEC cppVar_54063;
	BIT_VEC cppVar_53939;
	BIT_VEC cppVar_54065;
	BIT_VEC cppVar_54066;
	bool cppVar_54067;
	BIT_VEC cppVar_54069;
	BIT_VEC cppVar_54070;
	BIT_VEC cppVar_54071;
	BIT_VEC cppVar_54072;
	bool cppVar_54073;
	BIT_VEC cppVar_54075;
	BIT_VEC cppVar_54076;
	BIT_VEC cppVar_54077;
	BIT_VEC cppVar_54078;
	bool cppVar_54079;
	BIT_VEC cppVar_54080;
	BIT_VEC cppVar_54081;
	BIT_VEC cppVar_54082;
	BIT_VEC cppVar_54084;
	BIT_VEC cppVar_54085;
	BIT_VEC cppVar_54086;
	bool cppVar_54087;
	BIT_VEC cppVar_54089;
	BIT_VEC cppVar_54090;
	BIT_VEC cppVar_54091;
	bool cppVar_54092;
	BIT_VEC cppVar_54094;
	BIT_VEC cppVar_54095;
	BIT_VEC cppVar_54096;
	bool cppVar_54097;
	BIT_VEC cppVar_54099;
	BIT_VEC cppVar_54100;
	BIT_VEC cppVar_54101;
	bool cppVar_54102;
	BIT_VEC cppVar_54104;
	BIT_VEC cppVar_54105;
	BIT_VEC cppVar_54106;
	bool cppVar_54107;
	BIT_VEC cppVar_54109;
	BIT_VEC cppVar_54110;
	BIT_VEC cppVar_54111;
	bool cppVar_54112;
	BIT_VEC cppVar_54114;
	BIT_VEC cppVar_54115;
	BIT_VEC cppVar_54116;
	bool cppVar_54117;
	BIT_VEC cppVar_54119;
	BIT_VEC cppVar_54120;
	BIT_VEC cppVar_54121;
	bool cppVar_54122;
	BIT_VEC cppVar_54124;
	BIT_VEC cppVar_54125;
	BIT_VEC cppVar_54126;
	bool cppVar_54127;
	BIT_VEC cppVar_54129;
	BIT_VEC cppVar_54130;
	BIT_VEC cppVar_54131;
	bool cppVar_54132;
	BIT_VEC cppVar_54134;
	BIT_VEC cppVar_54135;
	BIT_VEC cppVar_54136;
	bool cppVar_54137;
	BIT_VEC cppVar_54139;
	BIT_VEC cppVar_54140;
	BIT_VEC cppVar_54141;
	bool cppVar_54142;
	BIT_VEC cppVar_54144;
	BIT_VEC cppVar_54145;
	BIT_VEC cppVar_54146;
	bool cppVar_54147;
	BIT_VEC cppVar_54149;
	BIT_VEC cppVar_54150;
	BIT_VEC cppVar_54151;
	bool cppVar_54152;
	BIT_VEC cppVar_54154;
	BIT_VEC cppVar_54155;
	BIT_VEC cppVar_54156;
	bool cppVar_54157;
	BIT_VEC cppVar_54159;
	BIT_VEC cppVar_54160;
	BIT_VEC cppVar_54161;
	bool cppVar_54162;
	BIT_VEC cppVar_54164;
	BIT_VEC cppVar_54165;
	BIT_VEC cppVar_54166;
	bool cppVar_54167;
	BIT_VEC cppVar_54169;
	BIT_VEC cppVar_54170;
	BIT_VEC cppVar_54171;
	bool cppVar_54172;
	BIT_VEC cppVar_54174;
	BIT_VEC cppVar_54175;
	BIT_VEC cppVar_54176;
	bool cppVar_54177;
	BIT_VEC cppVar_54179;
	BIT_VEC cppVar_54180;
	BIT_VEC cppVar_54181;
	bool cppVar_54182;
	BIT_VEC cppVar_54184;
	BIT_VEC cppVar_54185;
	BIT_VEC cppVar_54186;
	bool cppVar_54187;
	BIT_VEC cppVar_54188;
	BIT_VEC cppVar_54183;
	BIT_VEC cppVar_54178;
	BIT_VEC cppVar_54173;
	BIT_VEC cppVar_54168;
	BIT_VEC cppVar_54163;
	BIT_VEC cppVar_54158;
	BIT_VEC cppVar_54153;
	BIT_VEC cppVar_54148;
	BIT_VEC cppVar_54143;
	BIT_VEC cppVar_54138;
	BIT_VEC cppVar_54133;
	BIT_VEC cppVar_54128;
	BIT_VEC cppVar_54123;
	BIT_VEC cppVar_54118;
	BIT_VEC cppVar_54113;
	BIT_VEC cppVar_54108;
	BIT_VEC cppVar_54103;
	BIT_VEC cppVar_54098;
	BIT_VEC cppVar_54093;
	BIT_VEC cppVar_54088;
	BIT_VEC cppVar_54083;
	BIT_VEC cppVar_54074;
	BIT_VEC cppVar_54189;
	BIT_VEC cppVar_54068;
	BIT_VEC cppVar_54191;
	BIT_VEC cppVar_54192;
	bool cppVar_54193;
	BIT_VEC cppVar_54194;
	BIT_VEC cppVar_54195;
	BIT_VEC cppVar_54196;
	BIT_VEC cppVar_54197;
	BIT_VEC cppVar_54198;
	BIT_VEC cppVar_54199;
	BIT_VEC cppVar_54200;
	BIT_VEC cppVar_54201;
	BIT_VEC cppVar_54202;
	BIT_VEC cppVar_54203;
	BIT_VEC cppVar_54204;
	BIT_VEC cppVar_54205;
	BIT_VEC cppVar_54206;
	BIT_VEC cppVar_54207;
	BIT_VEC cppVar_54208;
	BIT_VEC cppVar_54209;
	BIT_VEC cppVar_54210;
	BIT_VEC cppVar_54211;
	BIT_VEC cppVar_54212;
	BIT_VEC cppVar_54213;
	BIT_VEC cppVar_54214;
	BIT_VEC cppVar_54215;
	BIT_VEC cppVar_54216;
	BIT_VEC cppVar_54217;
	BIT_VEC cppVar_54218;
	BIT_VEC cppVar_54219;
	BIT_VEC cppVar_54220;
	BIT_VEC cppVar_54222;
	BIT_VEC cppVar_54223;
	BIT_VEC cppVar_54224;
	BIT_VEC cppVar_54225;
	BIT_VEC cppVar_54226;
	BIT_VEC cppVar_54227;
	BIT_VEC cppVar_54228;
	BIT_VEC cppVar_54229;
	BIT_VEC cppVar_54230;
	BIT_VEC cppVar_54231;
	BIT_VEC cppVar_54232;
	BIT_VEC cppVar_54233;
	BIT_VEC cppVar_54234;
	BIT_VEC cppVar_54235;
	BIT_VEC cppVar_54236;
	BIT_VEC cppVar_54237;
	BIT_VEC cppVar_54238;
	BIT_VEC cppVar_54239;
	BIT_VEC cppVar_54240;
	BIT_VEC cppVar_54241;
	BIT_VEC cppVar_54242;
	BIT_VEC cppVar_54243;
	bool cppVar_54244;
	BIT_VEC cppVar_54245;
	BIT_VEC cppVar_54246;
	BIT_VEC cppVar_54221;
	BIT_VEC cppVar_54247;
	BIT_VEC cppVar_54248;
	BIT_VEC cppVar_54249;
	BIT_VEC cppVar_54250;
	BIT_VEC cppVar_54251;
	BIT_VEC cppVar_54253;
	BIT_VEC cppVar_54254;
	bool cppVar_54255;
	BIT_VEC cppVar_54256;
	BIT_VEC cppVar_54257;
	BIT_VEC cppVar_54258;
	BIT_VEC cppVar_54259;
	BIT_VEC cppVar_54260;
	BIT_VEC cppVar_54261;
	BIT_VEC cppVar_54262;
	BIT_VEC cppVar_54263;
	BIT_VEC cppVar_54264;
	BIT_VEC cppVar_54265;
	BIT_VEC cppVar_54266;
	BIT_VEC cppVar_54267;
	BIT_VEC cppVar_54268;
	BIT_VEC cppVar_54269;
	BIT_VEC cppVar_54270;
	BIT_VEC cppVar_54271;
	BIT_VEC cppVar_54272;
	BIT_VEC cppVar_54273;
	BIT_VEC cppVar_54274;
	BIT_VEC cppVar_54275;
	BIT_VEC cppVar_54276;
	BIT_VEC cppVar_54277;
	BIT_VEC cppVar_54278;
	BIT_VEC cppVar_54279;
	BIT_VEC cppVar_54280;
	BIT_VEC cppVar_54281;
	BIT_VEC cppVar_54282;
	BIT_VEC cppVar_54284;
	BIT_VEC cppVar_54285;
	BIT_VEC cppVar_54286;
	BIT_VEC cppVar_54287;
	BIT_VEC cppVar_54288;
	BIT_VEC cppVar_54289;
	BIT_VEC cppVar_54290;
	BIT_VEC cppVar_54291;
	BIT_VEC cppVar_54292;
	BIT_VEC cppVar_54293;
	BIT_VEC cppVar_54294;
	BIT_VEC cppVar_54295;
	BIT_VEC cppVar_54296;
	BIT_VEC cppVar_54297;
	BIT_VEC cppVar_54298;
	BIT_VEC cppVar_54299;
	BIT_VEC cppVar_54300;
	BIT_VEC cppVar_54301;
	BIT_VEC cppVar_54302;
	BIT_VEC cppVar_54303;
	BIT_VEC cppVar_54304;
	BIT_VEC cppVar_54305;
	bool cppVar_54306;
	BIT_VEC cppVar_54307;
	BIT_VEC cppVar_54308;
	BIT_VEC cppVar_54283;
	BIT_VEC cppVar_54309;
	BIT_VEC cppVar_54310;
	BIT_VEC cppVar_54311;
	BIT_VEC cppVar_54312;
	BIT_VEC cppVar_54313;
	BIT_VEC cppVar_54315;
	BIT_VEC cppVar_54316;
	bool cppVar_54317;
	BIT_VEC cppVar_54318;
	BIT_VEC cppVar_54319;
	BIT_VEC cppVar_54320;
	BIT_VEC cppVar_54321;
	BIT_VEC cppVar_54322;
	BIT_VEC cppVar_54323;
	BIT_VEC cppVar_54324;
	BIT_VEC cppVar_54325;
	BIT_VEC cppVar_54326;
	BIT_VEC cppVar_54327;
	BIT_VEC cppVar_54328;
	BIT_VEC cppVar_54329;
	BIT_VEC cppVar_54330;
	BIT_VEC cppVar_54331;
	BIT_VEC cppVar_54332;
	BIT_VEC cppVar_54333;
	BIT_VEC cppVar_54334;
	BIT_VEC cppVar_54335;
	BIT_VEC cppVar_54336;
	BIT_VEC cppVar_54337;
	BIT_VEC cppVar_54338;
	BIT_VEC cppVar_54339;
	BIT_VEC cppVar_54340;
	BIT_VEC cppVar_54341;
	BIT_VEC cppVar_54342;
	BIT_VEC cppVar_54343;
	BIT_VEC cppVar_54344;
	BIT_VEC cppVar_54346;
	BIT_VEC cppVar_54347;
	BIT_VEC cppVar_54348;
	BIT_VEC cppVar_54349;
	BIT_VEC cppVar_54350;
	BIT_VEC cppVar_54351;
	BIT_VEC cppVar_54352;
	BIT_VEC cppVar_54353;
	BIT_VEC cppVar_54354;
	BIT_VEC cppVar_54355;
	BIT_VEC cppVar_54356;
	BIT_VEC cppVar_54357;
	BIT_VEC cppVar_54358;
	BIT_VEC cppVar_54359;
	BIT_VEC cppVar_54360;
	BIT_VEC cppVar_54361;
	BIT_VEC cppVar_54362;
	BIT_VEC cppVar_54363;
	BIT_VEC cppVar_54364;
	BIT_VEC cppVar_54365;
	BIT_VEC cppVar_54366;
	BIT_VEC cppVar_54367;
	bool cppVar_54368;
	BIT_VEC cppVar_54369;
	BIT_VEC cppVar_54370;
	BIT_VEC cppVar_54345;
	BIT_VEC cppVar_54371;
	BIT_VEC cppVar_54372;
	BIT_VEC cppVar_54373;
	BIT_VEC cppVar_54374;
	BIT_VEC cppVar_54375;
	BIT_VEC cppVar_54377;
	BIT_VEC cppVar_54378;
	bool cppVar_54379;
	BIT_VEC cppVar_54380;
	BIT_VEC cppVar_54381;
	BIT_VEC cppVar_54382;
	BIT_VEC cppVar_54383;
	BIT_VEC cppVar_54384;
	BIT_VEC cppVar_54385;
	BIT_VEC cppVar_54386;
	BIT_VEC cppVar_54387;
	BIT_VEC cppVar_54388;
	BIT_VEC cppVar_54389;
	BIT_VEC cppVar_54390;
	BIT_VEC cppVar_54391;
	BIT_VEC cppVar_54392;
	BIT_VEC cppVar_54393;
	BIT_VEC cppVar_54394;
	BIT_VEC cppVar_54395;
	BIT_VEC cppVar_54396;
	BIT_VEC cppVar_54397;
	BIT_VEC cppVar_54398;
	BIT_VEC cppVar_54399;
	BIT_VEC cppVar_54400;
	BIT_VEC cppVar_54401;
	BIT_VEC cppVar_54402;
	BIT_VEC cppVar_54403;
	BIT_VEC cppVar_54404;
	BIT_VEC cppVar_54405;
	BIT_VEC cppVar_54406;
	BIT_VEC cppVar_54408;
	BIT_VEC cppVar_54409;
	BIT_VEC cppVar_54410;
	BIT_VEC cppVar_54411;
	BIT_VEC cppVar_54412;
	BIT_VEC cppVar_54413;
	BIT_VEC cppVar_54414;
	BIT_VEC cppVar_54415;
	BIT_VEC cppVar_54416;
	BIT_VEC cppVar_54417;
	BIT_VEC cppVar_54418;
	BIT_VEC cppVar_54419;
	BIT_VEC cppVar_54420;
	BIT_VEC cppVar_54421;
	BIT_VEC cppVar_54422;
	BIT_VEC cppVar_54423;
	BIT_VEC cppVar_54424;
	BIT_VEC cppVar_54425;
	BIT_VEC cppVar_54426;
	BIT_VEC cppVar_54427;
	BIT_VEC cppVar_54428;
	BIT_VEC cppVar_54429;
	bool cppVar_54430;
	BIT_VEC cppVar_54431;
	BIT_VEC cppVar_54432;
	BIT_VEC cppVar_54407;
	BIT_VEC cppVar_54433;
	BIT_VEC cppVar_54434;
	BIT_VEC cppVar_54435;
	BIT_VEC cppVar_54436;
	BIT_VEC cppVar_54437;
	BIT_VEC cppVar_54439;
	BIT_VEC cppVar_54440;
	bool cppVar_54441;
	BIT_VEC cppVar_54442;
	BIT_VEC cppVar_54443;
	BIT_VEC cppVar_54444;
	BIT_VEC cppVar_54445;
	BIT_VEC cppVar_54446;
	BIT_VEC cppVar_54447;
	BIT_VEC cppVar_54448;
	BIT_VEC cppVar_54449;
	BIT_VEC cppVar_54450;
	BIT_VEC cppVar_54451;
	BIT_VEC cppVar_54452;
	BIT_VEC cppVar_54453;
	BIT_VEC cppVar_54454;
	BIT_VEC cppVar_54455;
	BIT_VEC cppVar_54456;
	BIT_VEC cppVar_54457;
	BIT_VEC cppVar_54458;
	BIT_VEC cppVar_54459;
	BIT_VEC cppVar_54460;
	BIT_VEC cppVar_54461;
	BIT_VEC cppVar_54462;
	BIT_VEC cppVar_54463;
	BIT_VEC cppVar_54464;
	BIT_VEC cppVar_54465;
	BIT_VEC cppVar_54466;
	BIT_VEC cppVar_54467;
	BIT_VEC cppVar_54468;
	BIT_VEC cppVar_54470;
	BIT_VEC cppVar_54471;
	BIT_VEC cppVar_54472;
	BIT_VEC cppVar_54473;
	BIT_VEC cppVar_54474;
	BIT_VEC cppVar_54475;
	BIT_VEC cppVar_54476;
	BIT_VEC cppVar_54477;
	BIT_VEC cppVar_54478;
	BIT_VEC cppVar_54479;
	BIT_VEC cppVar_54480;
	BIT_VEC cppVar_54481;
	BIT_VEC cppVar_54482;
	BIT_VEC cppVar_54483;
	BIT_VEC cppVar_54484;
	BIT_VEC cppVar_54485;
	BIT_VEC cppVar_54486;
	BIT_VEC cppVar_54487;
	BIT_VEC cppVar_54488;
	BIT_VEC cppVar_54489;
	BIT_VEC cppVar_54490;
	BIT_VEC cppVar_54491;
	bool cppVar_54492;
	BIT_VEC cppVar_54493;
	BIT_VEC cppVar_54494;
	BIT_VEC cppVar_54469;
	BIT_VEC cppVar_54495;
	BIT_VEC cppVar_54496;
	BIT_VEC cppVar_54497;
	BIT_VEC cppVar_54498;
	BIT_VEC cppVar_54499;
	BIT_VEC cppVar_54501;
	BIT_VEC cppVar_54502;
	bool cppVar_54503;
	BIT_VEC cppVar_54504;
	BIT_VEC cppVar_54505;
	BIT_VEC cppVar_54506;
	BIT_VEC cppVar_54507;
	BIT_VEC cppVar_54508;
	BIT_VEC cppVar_54509;
	BIT_VEC cppVar_54510;
	BIT_VEC cppVar_54511;
	BIT_VEC cppVar_54512;
	BIT_VEC cppVar_54513;
	BIT_VEC cppVar_54514;
	BIT_VEC cppVar_54515;
	BIT_VEC cppVar_54516;
	BIT_VEC cppVar_54517;
	BIT_VEC cppVar_54518;
	BIT_VEC cppVar_54519;
	BIT_VEC cppVar_54520;
	BIT_VEC cppVar_54521;
	BIT_VEC cppVar_54522;
	BIT_VEC cppVar_54523;
	BIT_VEC cppVar_54524;
	BIT_VEC cppVar_54525;
	BIT_VEC cppVar_54526;
	BIT_VEC cppVar_54527;
	BIT_VEC cppVar_54528;
	BIT_VEC cppVar_54529;
	BIT_VEC cppVar_54530;
	BIT_VEC cppVar_54532;
	BIT_VEC cppVar_54533;
	BIT_VEC cppVar_54534;
	BIT_VEC cppVar_54535;
	BIT_VEC cppVar_54536;
	BIT_VEC cppVar_54537;
	BIT_VEC cppVar_54538;
	BIT_VEC cppVar_54539;
	BIT_VEC cppVar_54540;
	BIT_VEC cppVar_54541;
	BIT_VEC cppVar_54542;
	BIT_VEC cppVar_54543;
	BIT_VEC cppVar_54544;
	BIT_VEC cppVar_54545;
	BIT_VEC cppVar_54546;
	BIT_VEC cppVar_54547;
	BIT_VEC cppVar_54548;
	BIT_VEC cppVar_54549;
	BIT_VEC cppVar_54550;
	BIT_VEC cppVar_54551;
	BIT_VEC cppVar_54552;
	BIT_VEC cppVar_54553;
	bool cppVar_54554;
	BIT_VEC cppVar_54555;
	BIT_VEC cppVar_54556;
	BIT_VEC cppVar_54531;
	BIT_VEC cppVar_54557;
	BIT_VEC cppVar_54558;
	BIT_VEC cppVar_54559;
	BIT_VEC cppVar_54560;
	BIT_VEC cppVar_54561;
	BIT_VEC cppVar_54563;
	BIT_VEC cppVar_54564;
	bool cppVar_54565;
	BIT_VEC cppVar_54566;
	BIT_VEC cppVar_54567;
	BIT_VEC cppVar_54568;
	BIT_VEC cppVar_54569;
	BIT_VEC cppVar_54570;
	BIT_VEC cppVar_54571;
	BIT_VEC cppVar_54572;
	BIT_VEC cppVar_54573;
	BIT_VEC cppVar_54574;
	BIT_VEC cppVar_54575;
	BIT_VEC cppVar_54576;
	BIT_VEC cppVar_54577;
	BIT_VEC cppVar_54578;
	BIT_VEC cppVar_54579;
	BIT_VEC cppVar_54580;
	BIT_VEC cppVar_54581;
	BIT_VEC cppVar_54582;
	BIT_VEC cppVar_54583;
	BIT_VEC cppVar_54584;
	BIT_VEC cppVar_54585;
	BIT_VEC cppVar_54586;
	BIT_VEC cppVar_54587;
	BIT_VEC cppVar_54588;
	BIT_VEC cppVar_54589;
	BIT_VEC cppVar_54590;
	BIT_VEC cppVar_54591;
	BIT_VEC cppVar_54592;
	BIT_VEC cppVar_54594;
	BIT_VEC cppVar_54595;
	BIT_VEC cppVar_54596;
	BIT_VEC cppVar_54597;
	BIT_VEC cppVar_54598;
	BIT_VEC cppVar_54599;
	BIT_VEC cppVar_54600;
	BIT_VEC cppVar_54601;
	BIT_VEC cppVar_54602;
	BIT_VEC cppVar_54603;
	BIT_VEC cppVar_54604;
	BIT_VEC cppVar_54605;
	BIT_VEC cppVar_54606;
	BIT_VEC cppVar_54607;
	BIT_VEC cppVar_54608;
	BIT_VEC cppVar_54609;
	BIT_VEC cppVar_54610;
	BIT_VEC cppVar_54611;
	BIT_VEC cppVar_54612;
	BIT_VEC cppVar_54613;
	BIT_VEC cppVar_54614;
	BIT_VEC cppVar_54615;
	bool cppVar_54616;
	BIT_VEC cppVar_54617;
	BIT_VEC cppVar_54618;
	BIT_VEC cppVar_54593;
	BIT_VEC cppVar_54619;
	BIT_VEC cppVar_54620;
	BIT_VEC cppVar_54621;
	BIT_VEC cppVar_54622;
	BIT_VEC cppVar_54623;
	BIT_VEC cppVar_54625;
	BIT_VEC cppVar_54626;
	bool cppVar_54627;
	BIT_VEC cppVar_54628;
	BIT_VEC cppVar_54629;
	BIT_VEC cppVar_54630;
	BIT_VEC cppVar_54631;
	BIT_VEC cppVar_54632;
	BIT_VEC cppVar_54633;
	BIT_VEC cppVar_54634;
	BIT_VEC cppVar_54635;
	BIT_VEC cppVar_54636;
	BIT_VEC cppVar_54637;
	BIT_VEC cppVar_54638;
	BIT_VEC cppVar_54639;
	BIT_VEC cppVar_54640;
	BIT_VEC cppVar_54641;
	BIT_VEC cppVar_54642;
	BIT_VEC cppVar_54643;
	BIT_VEC cppVar_54644;
	BIT_VEC cppVar_54645;
	BIT_VEC cppVar_54646;
	BIT_VEC cppVar_54647;
	BIT_VEC cppVar_54648;
	BIT_VEC cppVar_54649;
	BIT_VEC cppVar_54650;
	BIT_VEC cppVar_54651;
	BIT_VEC cppVar_54652;
	BIT_VEC cppVar_54653;
	BIT_VEC cppVar_54654;
	BIT_VEC cppVar_54656;
	BIT_VEC cppVar_54657;
	BIT_VEC cppVar_54658;
	BIT_VEC cppVar_54659;
	BIT_VEC cppVar_54660;
	BIT_VEC cppVar_54661;
	BIT_VEC cppVar_54662;
	BIT_VEC cppVar_54663;
	BIT_VEC cppVar_54664;
	BIT_VEC cppVar_54665;
	BIT_VEC cppVar_54666;
	BIT_VEC cppVar_54667;
	BIT_VEC cppVar_54668;
	BIT_VEC cppVar_54669;
	BIT_VEC cppVar_54670;
	BIT_VEC cppVar_54671;
	BIT_VEC cppVar_54672;
	BIT_VEC cppVar_54673;
	BIT_VEC cppVar_54674;
	BIT_VEC cppVar_54675;
	BIT_VEC cppVar_54676;
	BIT_VEC cppVar_54677;
	bool cppVar_54678;
	BIT_VEC cppVar_54679;
	BIT_VEC cppVar_54680;
	BIT_VEC cppVar_54655;
	BIT_VEC cppVar_54681;
	BIT_VEC cppVar_54682;
	BIT_VEC cppVar_54683;
	BIT_VEC cppVar_54684;
	BIT_VEC cppVar_54685;
	BIT_VEC cppVar_54687;
	BIT_VEC cppVar_54688;
	bool cppVar_54689;
	BIT_VEC cppVar_54690;
	BIT_VEC cppVar_54691;
	BIT_VEC cppVar_54692;
	BIT_VEC cppVar_54693;
	BIT_VEC cppVar_54694;
	BIT_VEC cppVar_54695;
	BIT_VEC cppVar_54696;
	BIT_VEC cppVar_54697;
	BIT_VEC cppVar_54698;
	BIT_VEC cppVar_54699;
	BIT_VEC cppVar_54700;
	BIT_VEC cppVar_54701;
	BIT_VEC cppVar_54702;
	BIT_VEC cppVar_54703;
	BIT_VEC cppVar_54704;
	BIT_VEC cppVar_54705;
	BIT_VEC cppVar_54706;
	BIT_VEC cppVar_54707;
	BIT_VEC cppVar_54708;
	BIT_VEC cppVar_54709;
	BIT_VEC cppVar_54710;
	BIT_VEC cppVar_54711;
	BIT_VEC cppVar_54712;
	BIT_VEC cppVar_54713;
	BIT_VEC cppVar_54714;
	BIT_VEC cppVar_54715;
	BIT_VEC cppVar_54716;
	BIT_VEC cppVar_54717;
	BIT_VEC cppVar_54718;
	BIT_VEC cppVar_54720;
	BIT_VEC cppVar_54721;
	BIT_VEC cppVar_54722;
	BIT_VEC cppVar_54723;
	BIT_VEC cppVar_54724;
	BIT_VEC cppVar_54725;
	BIT_VEC cppVar_54726;
	BIT_VEC cppVar_54727;
	BIT_VEC cppVar_54728;
	BIT_VEC cppVar_54729;
	BIT_VEC cppVar_54730;
	BIT_VEC cppVar_54731;
	BIT_VEC cppVar_54732;
	BIT_VEC cppVar_54733;
	BIT_VEC cppVar_54734;
	BIT_VEC cppVar_54735;
	BIT_VEC cppVar_54736;
	BIT_VEC cppVar_54737;
	BIT_VEC cppVar_54738;
	BIT_VEC cppVar_54739;
	BIT_VEC cppVar_54740;
	BIT_VEC cppVar_54741;
	BIT_VEC cppVar_54742;
	BIT_VEC cppVar_54743;
	bool cppVar_54744;
	BIT_VEC cppVar_54745;
	BIT_VEC cppVar_54746;
	BIT_VEC cppVar_54719;
	BIT_VEC cppVar_54747;
	BIT_VEC cppVar_54748;
	BIT_VEC cppVar_54749;
	BIT_VEC cppVar_54750;
	BIT_VEC cppVar_54751;
	BIT_VEC cppVar_54753;
	BIT_VEC cppVar_54754;
	bool cppVar_54755;
	BIT_VEC cppVar_54756;
	BIT_VEC cppVar_54757;
	BIT_VEC cppVar_54758;
	BIT_VEC cppVar_54759;
	BIT_VEC cppVar_54760;
	BIT_VEC cppVar_54761;
	BIT_VEC cppVar_54762;
	BIT_VEC cppVar_54763;
	BIT_VEC cppVar_54764;
	BIT_VEC cppVar_54765;
	BIT_VEC cppVar_54766;
	BIT_VEC cppVar_54767;
	BIT_VEC cppVar_54768;
	BIT_VEC cppVar_54769;
	BIT_VEC cppVar_54770;
	BIT_VEC cppVar_54771;
	BIT_VEC cppVar_54772;
	BIT_VEC cppVar_54773;
	BIT_VEC cppVar_54774;
	BIT_VEC cppVar_54775;
	BIT_VEC cppVar_54776;
	BIT_VEC cppVar_54777;
	BIT_VEC cppVar_54778;
	BIT_VEC cppVar_54779;
	BIT_VEC cppVar_54780;
	BIT_VEC cppVar_54781;
	BIT_VEC cppVar_54782;
	BIT_VEC cppVar_54783;
	BIT_VEC cppVar_54784;
	BIT_VEC cppVar_54786;
	BIT_VEC cppVar_54787;
	BIT_VEC cppVar_54788;
	BIT_VEC cppVar_54789;
	BIT_VEC cppVar_54790;
	BIT_VEC cppVar_54791;
	BIT_VEC cppVar_54792;
	BIT_VEC cppVar_54793;
	BIT_VEC cppVar_54794;
	BIT_VEC cppVar_54795;
	BIT_VEC cppVar_54796;
	BIT_VEC cppVar_54797;
	BIT_VEC cppVar_54798;
	BIT_VEC cppVar_54799;
	BIT_VEC cppVar_54800;
	BIT_VEC cppVar_54801;
	BIT_VEC cppVar_54802;
	BIT_VEC cppVar_54803;
	BIT_VEC cppVar_54804;
	BIT_VEC cppVar_54805;
	BIT_VEC cppVar_54806;
	BIT_VEC cppVar_54807;
	BIT_VEC cppVar_54808;
	BIT_VEC cppVar_54809;
	bool cppVar_54810;
	BIT_VEC cppVar_54811;
	BIT_VEC cppVar_54812;
	BIT_VEC cppVar_54785;
	BIT_VEC cppVar_54813;
	BIT_VEC cppVar_54814;
	BIT_VEC cppVar_54815;
	BIT_VEC cppVar_54816;
	BIT_VEC cppVar_54817;
	BIT_VEC cppVar_54819;
	BIT_VEC cppVar_54820;
	bool cppVar_54821;
	BIT_VEC cppVar_54822;
	BIT_VEC cppVar_54824;
	BIT_VEC cppVar_54825;
	BIT_VEC cppVar_54826;
	BIT_VEC cppVar_54827;
	BIT_VEC cppVar_54828;
	bool cppVar_54829;
	BIT_VEC cppVar_54830;
	BIT_VEC cppVar_54831;
	BIT_VEC cppVar_54832;
	BIT_VEC cppVar_54834;
	BIT_VEC cppVar_54835;
	BIT_VEC cppVar_54836;
	bool cppVar_54837;
	BIT_VEC cppVar_54839;
	BIT_VEC cppVar_54840;
	BIT_VEC cppVar_54841;
	bool cppVar_54842;
	BIT_VEC cppVar_54844;
	BIT_VEC cppVar_54845;
	BIT_VEC cppVar_54846;
	bool cppVar_54847;
	BIT_VEC cppVar_54849;
	BIT_VEC cppVar_54850;
	BIT_VEC cppVar_54851;
	bool cppVar_54852;
	BIT_VEC cppVar_54854;
	BIT_VEC cppVar_54855;
	BIT_VEC cppVar_54856;
	bool cppVar_54857;
	BIT_VEC cppVar_54859;
	BIT_VEC cppVar_54860;
	BIT_VEC cppVar_54861;
	bool cppVar_54862;
	BIT_VEC cppVar_54864;
	BIT_VEC cppVar_54865;
	BIT_VEC cppVar_54866;
	bool cppVar_54867;
	BIT_VEC cppVar_54869;
	BIT_VEC cppVar_54870;
	BIT_VEC cppVar_54871;
	bool cppVar_54872;
	BIT_VEC cppVar_54874;
	BIT_VEC cppVar_54875;
	BIT_VEC cppVar_54876;
	bool cppVar_54877;
	BIT_VEC cppVar_54879;
	BIT_VEC cppVar_54880;
	BIT_VEC cppVar_54881;
	bool cppVar_54882;
	BIT_VEC cppVar_54884;
	BIT_VEC cppVar_54885;
	BIT_VEC cppVar_54886;
	bool cppVar_54887;
	BIT_VEC cppVar_54889;
	BIT_VEC cppVar_54890;
	BIT_VEC cppVar_54891;
	bool cppVar_54892;
	BIT_VEC cppVar_54894;
	BIT_VEC cppVar_54895;
	BIT_VEC cppVar_54896;
	bool cppVar_54897;
	BIT_VEC cppVar_54899;
	BIT_VEC cppVar_54900;
	BIT_VEC cppVar_54901;
	bool cppVar_54902;
	BIT_VEC cppVar_54904;
	BIT_VEC cppVar_54905;
	BIT_VEC cppVar_54906;
	bool cppVar_54907;
	BIT_VEC cppVar_54909;
	BIT_VEC cppVar_54910;
	BIT_VEC cppVar_54911;
	bool cppVar_54912;
	BIT_VEC cppVar_54914;
	BIT_VEC cppVar_54915;
	BIT_VEC cppVar_54916;
	bool cppVar_54917;
	BIT_VEC cppVar_54919;
	BIT_VEC cppVar_54920;
	BIT_VEC cppVar_54921;
	bool cppVar_54922;
	BIT_VEC cppVar_54924;
	BIT_VEC cppVar_54925;
	BIT_VEC cppVar_54926;
	bool cppVar_54927;
	BIT_VEC cppVar_54929;
	BIT_VEC cppVar_54930;
	BIT_VEC cppVar_54931;
	bool cppVar_54932;
	BIT_VEC cppVar_54934;
	BIT_VEC cppVar_54935;
	BIT_VEC cppVar_54936;
	bool cppVar_54937;
	BIT_VEC cppVar_54938;
	BIT_VEC cppVar_54933;
	BIT_VEC cppVar_54928;
	BIT_VEC cppVar_54923;
	BIT_VEC cppVar_54918;
	BIT_VEC cppVar_54913;
	BIT_VEC cppVar_54908;
	BIT_VEC cppVar_54903;
	BIT_VEC cppVar_54898;
	BIT_VEC cppVar_54893;
	BIT_VEC cppVar_54888;
	BIT_VEC cppVar_54883;
	BIT_VEC cppVar_54878;
	BIT_VEC cppVar_54873;
	BIT_VEC cppVar_54868;
	BIT_VEC cppVar_54863;
	BIT_VEC cppVar_54858;
	BIT_VEC cppVar_54853;
	BIT_VEC cppVar_54848;
	BIT_VEC cppVar_54843;
	BIT_VEC cppVar_54838;
	BIT_VEC cppVar_54833;
	BIT_VEC cppVar_54823;
	BIT_VEC cppVar_54939;
	BIT_VEC cppVar_54940;
	BIT_VEC cppVar_54941;
	BIT_VEC cppVar_54942;
	BIT_VEC cppVar_54943;
	BIT_VEC cppVar_54944;
	BIT_VEC cppVar_54945;
	BIT_VEC cppVar_54946;
	BIT_VEC cppVar_54948;
	BIT_VEC cppVar_54949;
	BIT_VEC cppVar_54950;
	bool cppVar_54951;
	BIT_VEC cppVar_54952;
	BIT_VEC cppVar_54953;
	BIT_VEC cppVar_54954;
	BIT_VEC cppVar_54956;
	BIT_VEC cppVar_54957;
	bool cppVar_54958;
	BIT_VEC cppVar_54960;
	BIT_VEC cppVar_54961;
	bool cppVar_54962;
	BIT_VEC cppVar_54964;
	BIT_VEC cppVar_54965;
	bool cppVar_54966;
	BIT_VEC cppVar_54968;
	BIT_VEC cppVar_54969;
	bool cppVar_54970;
	BIT_VEC cppVar_54972;
	BIT_VEC cppVar_54973;
	bool cppVar_54974;
	BIT_VEC cppVar_54976;
	BIT_VEC cppVar_54977;
	bool cppVar_54978;
	BIT_VEC cppVar_54980;
	BIT_VEC cppVar_54981;
	bool cppVar_54982;
	BIT_VEC cppVar_54984;
	BIT_VEC cppVar_54985;
	bool cppVar_54986;
	BIT_VEC cppVar_54988;
	BIT_VEC cppVar_54989;
	bool cppVar_54990;
	BIT_VEC cppVar_54992;
	BIT_VEC cppVar_54993;
	bool cppVar_54994;
	BIT_VEC cppVar_54996;
	BIT_VEC cppVar_54997;
	bool cppVar_54998;
	BIT_VEC cppVar_55000;
	BIT_VEC cppVar_55001;
	bool cppVar_55002;
	BIT_VEC cppVar_55004;
	BIT_VEC cppVar_55005;
	bool cppVar_55006;
	BIT_VEC cppVar_55008;
	BIT_VEC cppVar_55009;
	bool cppVar_55010;
	BIT_VEC cppVar_55012;
	BIT_VEC cppVar_55013;
	bool cppVar_55014;
	BIT_VEC cppVar_55016;
	BIT_VEC cppVar_55017;
	bool cppVar_55018;
	BIT_VEC cppVar_55020;
	BIT_VEC cppVar_55021;
	bool cppVar_55022;
	BIT_VEC cppVar_55024;
	BIT_VEC cppVar_55025;
	bool cppVar_55026;
	BIT_VEC cppVar_55028;
	BIT_VEC cppVar_55029;
	bool cppVar_55030;
	BIT_VEC cppVar_55032;
	BIT_VEC cppVar_55033;
	bool cppVar_55034;
	BIT_VEC cppVar_55036;
	BIT_VEC cppVar_55037;
	bool cppVar_55038;
	BIT_VEC cppVar_55035;
	BIT_VEC cppVar_55031;
	BIT_VEC cppVar_55027;
	BIT_VEC cppVar_55023;
	BIT_VEC cppVar_55019;
	BIT_VEC cppVar_55015;
	BIT_VEC cppVar_55011;
	BIT_VEC cppVar_55007;
	BIT_VEC cppVar_55003;
	BIT_VEC cppVar_54999;
	BIT_VEC cppVar_54995;
	BIT_VEC cppVar_54991;
	BIT_VEC cppVar_54987;
	BIT_VEC cppVar_54983;
	BIT_VEC cppVar_54979;
	BIT_VEC cppVar_54975;
	BIT_VEC cppVar_54971;
	BIT_VEC cppVar_54967;
	BIT_VEC cppVar_54963;
	BIT_VEC cppVar_54959;
	BIT_VEC cppVar_54955;
	BIT_VEC cppVar_54947;
	BIT_VEC cppVar_55039;
	BIT_VEC cppVar_55040;
	BIT_VEC cppVar_55041;
	BIT_VEC cppVar_55042;
	BIT_VEC cppVar_55043;
	BIT_VEC cppVar_55044;
	BIT_VEC cppVar_55045;
	BIT_VEC cppVar_55046;
	BIT_VEC cppVar_55048;
	BIT_VEC cppVar_55050;
	BIT_VEC cppVar_55051;
	BIT_VEC cppVar_55052;
	bool cppVar_55053;
	BIT_VEC cppVar_55054;
	BIT_VEC cppVar_55055;
	BIT_VEC cppVar_55056;
	BIT_VEC cppVar_55058;
	BIT_VEC cppVar_55059;
	bool cppVar_55060;
	BIT_VEC cppVar_55062;
	BIT_VEC cppVar_55063;
	bool cppVar_55064;
	BIT_VEC cppVar_55066;
	BIT_VEC cppVar_55067;
	bool cppVar_55068;
	BIT_VEC cppVar_55070;
	BIT_VEC cppVar_55071;
	bool cppVar_55072;
	BIT_VEC cppVar_55074;
	BIT_VEC cppVar_55075;
	bool cppVar_55076;
	BIT_VEC cppVar_55078;
	BIT_VEC cppVar_55079;
	bool cppVar_55080;
	BIT_VEC cppVar_55082;
	BIT_VEC cppVar_55083;
	bool cppVar_55084;
	BIT_VEC cppVar_55086;
	BIT_VEC cppVar_55087;
	bool cppVar_55088;
	BIT_VEC cppVar_55090;
	BIT_VEC cppVar_55091;
	bool cppVar_55092;
	BIT_VEC cppVar_55094;
	BIT_VEC cppVar_55095;
	bool cppVar_55096;
	BIT_VEC cppVar_55098;
	BIT_VEC cppVar_55099;
	bool cppVar_55100;
	BIT_VEC cppVar_55102;
	BIT_VEC cppVar_55103;
	bool cppVar_55104;
	BIT_VEC cppVar_55106;
	BIT_VEC cppVar_55107;
	bool cppVar_55108;
	BIT_VEC cppVar_55110;
	BIT_VEC cppVar_55111;
	bool cppVar_55112;
	BIT_VEC cppVar_55114;
	BIT_VEC cppVar_55115;
	bool cppVar_55116;
	BIT_VEC cppVar_55118;
	BIT_VEC cppVar_55119;
	bool cppVar_55120;
	BIT_VEC cppVar_55122;
	BIT_VEC cppVar_55123;
	bool cppVar_55124;
	BIT_VEC cppVar_55126;
	BIT_VEC cppVar_55127;
	bool cppVar_55128;
	BIT_VEC cppVar_55130;
	BIT_VEC cppVar_55131;
	bool cppVar_55132;
	BIT_VEC cppVar_55134;
	BIT_VEC cppVar_55135;
	bool cppVar_55136;
	BIT_VEC cppVar_55138;
	BIT_VEC cppVar_55139;
	bool cppVar_55140;
	BIT_VEC cppVar_55137;
	BIT_VEC cppVar_55133;
	BIT_VEC cppVar_55129;
	BIT_VEC cppVar_55125;
	BIT_VEC cppVar_55121;
	BIT_VEC cppVar_55117;
	BIT_VEC cppVar_55113;
	BIT_VEC cppVar_55109;
	BIT_VEC cppVar_55105;
	BIT_VEC cppVar_55101;
	BIT_VEC cppVar_55097;
	BIT_VEC cppVar_55093;
	BIT_VEC cppVar_55089;
	BIT_VEC cppVar_55085;
	BIT_VEC cppVar_55081;
	BIT_VEC cppVar_55077;
	BIT_VEC cppVar_55073;
	BIT_VEC cppVar_55069;
	BIT_VEC cppVar_55065;
	BIT_VEC cppVar_55061;
	BIT_VEC cppVar_55057;
	BIT_VEC cppVar_55049;
	BIT_VEC cppVar_55141;
	BIT_VEC cppVar_55142;
	BIT_VEC cppVar_55143;
	BIT_VEC cppVar_55144;
	BIT_VEC cppVar_55145;
	BIT_VEC cppVar_55146;
	BIT_VEC cppVar_55147;
	BIT_VEC cppVar_55149;
	BIT_VEC cppVar_55150;
	BIT_VEC cppVar_55151;
	bool cppVar_55152;
	BIT_VEC cppVar_55153;
	BIT_VEC cppVar_55154;
	BIT_VEC cppVar_55155;
	BIT_VEC cppVar_55157;
	BIT_VEC cppVar_55158;
	bool cppVar_55159;
	BIT_VEC cppVar_55161;
	BIT_VEC cppVar_55162;
	bool cppVar_55163;
	BIT_VEC cppVar_55165;
	BIT_VEC cppVar_55166;
	bool cppVar_55167;
	BIT_VEC cppVar_55169;
	BIT_VEC cppVar_55170;
	bool cppVar_55171;
	BIT_VEC cppVar_55173;
	BIT_VEC cppVar_55174;
	bool cppVar_55175;
	BIT_VEC cppVar_55177;
	BIT_VEC cppVar_55178;
	bool cppVar_55179;
	BIT_VEC cppVar_55181;
	BIT_VEC cppVar_55182;
	bool cppVar_55183;
	BIT_VEC cppVar_55185;
	BIT_VEC cppVar_55186;
	bool cppVar_55187;
	BIT_VEC cppVar_55189;
	BIT_VEC cppVar_55190;
	bool cppVar_55191;
	BIT_VEC cppVar_55193;
	BIT_VEC cppVar_55194;
	bool cppVar_55195;
	BIT_VEC cppVar_55197;
	BIT_VEC cppVar_55198;
	bool cppVar_55199;
	BIT_VEC cppVar_55201;
	BIT_VEC cppVar_55202;
	bool cppVar_55203;
	BIT_VEC cppVar_55205;
	BIT_VEC cppVar_55206;
	bool cppVar_55207;
	BIT_VEC cppVar_55209;
	BIT_VEC cppVar_55210;
	bool cppVar_55211;
	BIT_VEC cppVar_55213;
	BIT_VEC cppVar_55214;
	bool cppVar_55215;
	BIT_VEC cppVar_55217;
	BIT_VEC cppVar_55218;
	bool cppVar_55219;
	BIT_VEC cppVar_55221;
	BIT_VEC cppVar_55222;
	bool cppVar_55223;
	BIT_VEC cppVar_55225;
	BIT_VEC cppVar_55226;
	bool cppVar_55227;
	BIT_VEC cppVar_55229;
	BIT_VEC cppVar_55230;
	bool cppVar_55231;
	BIT_VEC cppVar_55233;
	BIT_VEC cppVar_55234;
	bool cppVar_55235;
	BIT_VEC cppVar_55237;
	BIT_VEC cppVar_55238;
	bool cppVar_55239;
	BIT_VEC cppVar_55236;
	BIT_VEC cppVar_55232;
	BIT_VEC cppVar_55228;
	BIT_VEC cppVar_55224;
	BIT_VEC cppVar_55220;
	BIT_VEC cppVar_55216;
	BIT_VEC cppVar_55212;
	BIT_VEC cppVar_55208;
	BIT_VEC cppVar_55204;
	BIT_VEC cppVar_55200;
	BIT_VEC cppVar_55196;
	BIT_VEC cppVar_55192;
	BIT_VEC cppVar_55188;
	BIT_VEC cppVar_55184;
	BIT_VEC cppVar_55180;
	BIT_VEC cppVar_55176;
	BIT_VEC cppVar_55172;
	BIT_VEC cppVar_55168;
	BIT_VEC cppVar_55164;
	BIT_VEC cppVar_55160;
	BIT_VEC cppVar_55156;
	BIT_VEC cppVar_55148;
	BIT_VEC cppVar_55240;
	BIT_VEC cppVar_55241;
	BIT_VEC cppVar_55242;
	BIT_VEC cppVar_55243;
	BIT_VEC cppVar_55244;
	BIT_VEC cppVar_55245;
	bool cppVar_55246;
	BIT_VEC cppVar_55247;
	BIT_VEC cppVar_55248;
	BIT_VEC cppVar_55047;
	BIT_VEC cppVar_55249;
	BIT_VEC cppVar_55250;
	BIT_VEC cppVar_55251;
	BIT_VEC cppVar_55252;
	BIT_VEC cppVar_55253;
	BIT_VEC cppVar_55255;
	BIT_VEC cppVar_55256;
	bool cppVar_55257;
	BIT_VEC cppVar_55258;
	BIT_VEC cppVar_55259;
	BIT_VEC cppVar_55260;
	BIT_VEC cppVar_55261;
	BIT_VEC cppVar_55262;
	BIT_VEC cppVar_55263;
	BIT_VEC cppVar_55264;
	BIT_VEC cppVar_55265;
	BIT_VEC cppVar_55266;
	BIT_VEC cppVar_55267;
	BIT_VEC cppVar_55268;
	BIT_VEC cppVar_55269;
	BIT_VEC cppVar_55270;
	BIT_VEC cppVar_55271;
	BIT_VEC cppVar_55272;
	BIT_VEC cppVar_55273;
	BIT_VEC cppVar_55274;
	BIT_VEC cppVar_55275;
	BIT_VEC cppVar_55276;
	BIT_VEC cppVar_55277;
	BIT_VEC cppVar_55278;
	BIT_VEC cppVar_55279;
	BIT_VEC cppVar_55281;
	BIT_VEC cppVar_55282;
	BIT_VEC cppVar_55283;
	BIT_VEC cppVar_55284;
	BIT_VEC cppVar_55285;
	BIT_VEC cppVar_55286;
	BIT_VEC cppVar_55287;
	BIT_VEC cppVar_55288;
	BIT_VEC cppVar_55289;
	BIT_VEC cppVar_55290;
	BIT_VEC cppVar_55291;
	BIT_VEC cppVar_55292;
	BIT_VEC cppVar_55293;
	BIT_VEC cppVar_55294;
	BIT_VEC cppVar_55295;
	BIT_VEC cppVar_55296;
	BIT_VEC cppVar_55297;
	BIT_VEC cppVar_55298;
	bool cppVar_55299;
	BIT_VEC cppVar_55300;
	BIT_VEC cppVar_55301;
	BIT_VEC cppVar_55280;
	BIT_VEC cppVar_55302;
	BIT_VEC cppVar_55303;
	BIT_VEC cppVar_55304;
	BIT_VEC cppVar_55305;
	BIT_VEC cppVar_55306;
	BIT_VEC cppVar_55308;
	BIT_VEC cppVar_55309;
	bool cppVar_55310;
	BIT_VEC cppVar_55311;
	BIT_VEC cppVar_55312;
	BIT_VEC cppVar_55313;
	BIT_VEC cppVar_55314;
	BIT_VEC cppVar_55315;
	BIT_VEC cppVar_55316;
	BIT_VEC cppVar_55317;
	BIT_VEC cppVar_55318;
	BIT_VEC cppVar_55319;
	BIT_VEC cppVar_55321;
	BIT_VEC cppVar_55322;
	bool cppVar_55323;
	BIT_VEC cppVar_55324;
	BIT_VEC cppVar_55325;
	BIT_VEC cppVar_55326;
	BIT_VEC cppVar_55327;
	BIT_VEC cppVar_55328;
	BIT_VEC cppVar_55329;
	BIT_VEC cppVar_55330;
	BIT_VEC cppVar_55331;
	BIT_VEC cppVar_55332;
	BIT_VEC cppVar_55333;
	BIT_VEC cppVar_55334;
	BIT_VEC cppVar_55335;
	BIT_VEC cppVar_55336;
	BIT_VEC cppVar_55337;
	BIT_VEC cppVar_55338;
	BIT_VEC cppVar_55339;
	BIT_VEC cppVar_55340;
	BIT_VEC cppVar_55341;
	BIT_VEC cppVar_55342;
	BIT_VEC cppVar_55343;
	BIT_VEC cppVar_55344;
	BIT_VEC cppVar_55345;
	BIT_VEC cppVar_55346;
	BIT_VEC cppVar_55347;
	BIT_VEC cppVar_55348;
	BIT_VEC cppVar_55349;
	BIT_VEC cppVar_55351;
	BIT_VEC cppVar_55352;
	BIT_VEC cppVar_55353;
	BIT_VEC cppVar_55354;
	BIT_VEC cppVar_55355;
	BIT_VEC cppVar_55356;
	BIT_VEC cppVar_55357;
	BIT_VEC cppVar_55358;
	BIT_VEC cppVar_55359;
	BIT_VEC cppVar_55360;
	BIT_VEC cppVar_55361;
	BIT_VEC cppVar_55362;
	BIT_VEC cppVar_55363;
	BIT_VEC cppVar_55364;
	BIT_VEC cppVar_55365;
	BIT_VEC cppVar_55366;
	BIT_VEC cppVar_55367;
	BIT_VEC cppVar_55368;
	BIT_VEC cppVar_55369;
	BIT_VEC cppVar_55370;
	bool cppVar_55371;
	BIT_VEC cppVar_55372;
	BIT_VEC cppVar_55373;
	BIT_VEC cppVar_55350;
	BIT_VEC cppVar_55374;
	BIT_VEC cppVar_55375;
	BIT_VEC cppVar_55376;
	BIT_VEC cppVar_55377;
	BIT_VEC cppVar_55378;
	BIT_VEC cppVar_55380;
	BIT_VEC cppVar_55381;
	bool cppVar_55382;
	BIT_VEC cppVar_55383;
	BIT_VEC cppVar_55384;
	BIT_VEC cppVar_55385;
	BIT_VEC cppVar_55386;
	BIT_VEC cppVar_55387;
	BIT_VEC cppVar_55388;
	BIT_VEC cppVar_55389;
	BIT_VEC cppVar_55390;
	BIT_VEC cppVar_55391;
	BIT_VEC cppVar_55392;
	BIT_VEC cppVar_55393;
	BIT_VEC cppVar_55394;
	BIT_VEC cppVar_55395;
	BIT_VEC cppVar_55396;
	BIT_VEC cppVar_55397;
	BIT_VEC cppVar_55398;
	BIT_VEC cppVar_55399;
	BIT_VEC cppVar_55400;
	BIT_VEC cppVar_55401;
	BIT_VEC cppVar_55402;
	BIT_VEC cppVar_55403;
	BIT_VEC cppVar_55404;
	BIT_VEC cppVar_55405;
	BIT_VEC cppVar_55406;
	BIT_VEC cppVar_55407;
	BIT_VEC cppVar_55408;
	BIT_VEC cppVar_55410;
	BIT_VEC cppVar_55411;
	BIT_VEC cppVar_55412;
	BIT_VEC cppVar_55413;
	BIT_VEC cppVar_55414;
	BIT_VEC cppVar_55415;
	BIT_VEC cppVar_55416;
	BIT_VEC cppVar_55417;
	BIT_VEC cppVar_55418;
	BIT_VEC cppVar_55419;
	BIT_VEC cppVar_55420;
	BIT_VEC cppVar_55421;
	BIT_VEC cppVar_55422;
	BIT_VEC cppVar_55423;
	BIT_VEC cppVar_55424;
	BIT_VEC cppVar_55425;
	BIT_VEC cppVar_55426;
	BIT_VEC cppVar_55427;
	BIT_VEC cppVar_55428;
	BIT_VEC cppVar_55429;
	bool cppVar_55430;
	BIT_VEC cppVar_55431;
	BIT_VEC cppVar_55432;
	BIT_VEC cppVar_55409;
	BIT_VEC cppVar_55433;
	BIT_VEC cppVar_55434;
	BIT_VEC cppVar_55435;
	BIT_VEC cppVar_55436;
	BIT_VEC cppVar_55437;
	BIT_VEC cppVar_55439;
	BIT_VEC cppVar_55440;
	bool cppVar_55441;
	BIT_VEC cppVar_55442;
	BIT_VEC cppVar_55443;
	BIT_VEC cppVar_55444;
	BIT_VEC cppVar_55445;
	BIT_VEC cppVar_55446;
	BIT_VEC cppVar_55447;
	BIT_VEC cppVar_55448;
	BIT_VEC cppVar_55449;
	BIT_VEC cppVar_55450;
	BIT_VEC cppVar_55451;
	BIT_VEC cppVar_55452;
	BIT_VEC cppVar_55453;
	BIT_VEC cppVar_55454;
	BIT_VEC cppVar_55455;
	BIT_VEC cppVar_55456;
	BIT_VEC cppVar_55457;
	BIT_VEC cppVar_55458;
	BIT_VEC cppVar_55459;
	BIT_VEC cppVar_55460;
	BIT_VEC cppVar_55461;
	BIT_VEC cppVar_55462;
	BIT_VEC cppVar_55463;
	BIT_VEC cppVar_55464;
	BIT_VEC cppVar_55465;
	BIT_VEC cppVar_55466;
	BIT_VEC cppVar_55467;
	BIT_VEC cppVar_55469;
	BIT_VEC cppVar_55470;
	BIT_VEC cppVar_55471;
	BIT_VEC cppVar_55472;
	BIT_VEC cppVar_55473;
	BIT_VEC cppVar_55474;
	BIT_VEC cppVar_55475;
	BIT_VEC cppVar_55476;
	BIT_VEC cppVar_55477;
	BIT_VEC cppVar_55478;
	BIT_VEC cppVar_55479;
	BIT_VEC cppVar_55480;
	BIT_VEC cppVar_55481;
	BIT_VEC cppVar_55482;
	BIT_VEC cppVar_55483;
	BIT_VEC cppVar_55484;
	BIT_VEC cppVar_55485;
	BIT_VEC cppVar_55486;
	BIT_VEC cppVar_55487;
	BIT_VEC cppVar_55488;
	bool cppVar_55489;
	BIT_VEC cppVar_55490;
	BIT_VEC cppVar_55491;
	BIT_VEC cppVar_55468;
	BIT_VEC cppVar_55492;
	BIT_VEC cppVar_55493;
	BIT_VEC cppVar_55494;
	BIT_VEC cppVar_55495;
	BIT_VEC cppVar_55496;
	BIT_VEC cppVar_55498;
	BIT_VEC cppVar_55499;
	bool cppVar_55500;
	BIT_VEC cppVar_55501;
	BIT_VEC cppVar_55502;
	BIT_VEC cppVar_55503;
	BIT_VEC cppVar_55504;
	BIT_VEC cppVar_55505;
	BIT_VEC cppVar_55506;
	BIT_VEC cppVar_55507;
	BIT_VEC cppVar_55508;
	BIT_VEC cppVar_55509;
	BIT_VEC cppVar_55510;
	BIT_VEC cppVar_55511;
	BIT_VEC cppVar_55512;
	BIT_VEC cppVar_55513;
	BIT_VEC cppVar_55514;
	BIT_VEC cppVar_55515;
	BIT_VEC cppVar_55516;
	BIT_VEC cppVar_55517;
	BIT_VEC cppVar_55518;
	BIT_VEC cppVar_55519;
	BIT_VEC cppVar_55520;
	BIT_VEC cppVar_55521;
	BIT_VEC cppVar_55522;
	BIT_VEC cppVar_55523;
	BIT_VEC cppVar_55524;
	BIT_VEC cppVar_55525;
	BIT_VEC cppVar_55526;
	BIT_VEC cppVar_55528;
	BIT_VEC cppVar_55529;
	BIT_VEC cppVar_55530;
	BIT_VEC cppVar_55531;
	BIT_VEC cppVar_55532;
	BIT_VEC cppVar_55533;
	BIT_VEC cppVar_55534;
	BIT_VEC cppVar_55535;
	BIT_VEC cppVar_55536;
	BIT_VEC cppVar_55537;
	BIT_VEC cppVar_55538;
	BIT_VEC cppVar_55539;
	BIT_VEC cppVar_55540;
	BIT_VEC cppVar_55541;
	BIT_VEC cppVar_55542;
	BIT_VEC cppVar_55543;
	BIT_VEC cppVar_55544;
	BIT_VEC cppVar_55545;
	BIT_VEC cppVar_55546;
	BIT_VEC cppVar_55547;
	bool cppVar_55548;
	BIT_VEC cppVar_55549;
	BIT_VEC cppVar_55550;
	BIT_VEC cppVar_55527;
	BIT_VEC cppVar_55551;
	BIT_VEC cppVar_55552;
	BIT_VEC cppVar_55553;
	BIT_VEC cppVar_55554;
	BIT_VEC cppVar_55555;
	BIT_VEC cppVar_55557;
	BIT_VEC cppVar_55558;
	bool cppVar_55559;
	BIT_VEC cppVar_55560;
	BIT_VEC cppVar_55561;
	BIT_VEC cppVar_55562;
	BIT_VEC cppVar_55563;
	BIT_VEC cppVar_55564;
	BIT_VEC cppVar_55565;
	BIT_VEC cppVar_55566;
	BIT_VEC cppVar_55567;
	BIT_VEC cppVar_55568;
	BIT_VEC cppVar_55569;
	BIT_VEC cppVar_55570;
	BIT_VEC cppVar_55571;
	BIT_VEC cppVar_55572;
	BIT_VEC cppVar_55573;
	BIT_VEC cppVar_55574;
	BIT_VEC cppVar_55575;
	BIT_VEC cppVar_55576;
	BIT_VEC cppVar_55577;
	BIT_VEC cppVar_55578;
	BIT_VEC cppVar_55579;
	BIT_VEC cppVar_55580;
	BIT_VEC cppVar_55581;
	BIT_VEC cppVar_55582;
	BIT_VEC cppVar_55583;
	BIT_VEC cppVar_55584;
	BIT_VEC cppVar_55585;
	BIT_VEC cppVar_55587;
	BIT_VEC cppVar_55588;
	BIT_VEC cppVar_55589;
	BIT_VEC cppVar_55590;
	BIT_VEC cppVar_55591;
	BIT_VEC cppVar_55592;
	BIT_VEC cppVar_55593;
	BIT_VEC cppVar_55594;
	BIT_VEC cppVar_55595;
	BIT_VEC cppVar_55596;
	BIT_VEC cppVar_55597;
	BIT_VEC cppVar_55598;
	BIT_VEC cppVar_55599;
	BIT_VEC cppVar_55600;
	BIT_VEC cppVar_55601;
	BIT_VEC cppVar_55602;
	BIT_VEC cppVar_55603;
	BIT_VEC cppVar_55604;
	BIT_VEC cppVar_55605;
	BIT_VEC cppVar_55606;
	bool cppVar_55607;
	BIT_VEC cppVar_55608;
	BIT_VEC cppVar_55609;
	BIT_VEC cppVar_55586;
	BIT_VEC cppVar_55610;
	BIT_VEC cppVar_55611;
	BIT_VEC cppVar_55612;
	BIT_VEC cppVar_55613;
	BIT_VEC cppVar_55614;
	BIT_VEC cppVar_55616;
	BIT_VEC cppVar_55617;
	bool cppVar_55618;
	BIT_VEC cppVar_55619;
	BIT_VEC cppVar_55620;
	BIT_VEC cppVar_55621;
	BIT_VEC cppVar_55622;
	BIT_VEC cppVar_55623;
	BIT_VEC cppVar_55624;
	BIT_VEC cppVar_55625;
	BIT_VEC cppVar_55626;
	BIT_VEC cppVar_55627;
	BIT_VEC cppVar_55628;
	BIT_VEC cppVar_55629;
	BIT_VEC cppVar_55630;
	BIT_VEC cppVar_55631;
	BIT_VEC cppVar_55632;
	BIT_VEC cppVar_55633;
	BIT_VEC cppVar_55634;
	BIT_VEC cppVar_55635;
	BIT_VEC cppVar_55636;
	BIT_VEC cppVar_55637;
	BIT_VEC cppVar_55638;
	BIT_VEC cppVar_55639;
	BIT_VEC cppVar_55640;
	BIT_VEC cppVar_55641;
	BIT_VEC cppVar_55642;
	BIT_VEC cppVar_55643;
	BIT_VEC cppVar_55644;
	BIT_VEC cppVar_55646;
	BIT_VEC cppVar_55647;
	BIT_VEC cppVar_55648;
	BIT_VEC cppVar_55649;
	BIT_VEC cppVar_55650;
	BIT_VEC cppVar_55651;
	BIT_VEC cppVar_55652;
	BIT_VEC cppVar_55653;
	BIT_VEC cppVar_55654;
	BIT_VEC cppVar_55655;
	BIT_VEC cppVar_55656;
	BIT_VEC cppVar_55657;
	BIT_VEC cppVar_55658;
	BIT_VEC cppVar_55659;
	BIT_VEC cppVar_55660;
	BIT_VEC cppVar_55661;
	BIT_VEC cppVar_55662;
	BIT_VEC cppVar_55663;
	BIT_VEC cppVar_55664;
	BIT_VEC cppVar_55665;
	bool cppVar_55666;
	BIT_VEC cppVar_55667;
	BIT_VEC cppVar_55668;
	BIT_VEC cppVar_55645;
	BIT_VEC cppVar_55669;
	BIT_VEC cppVar_55670;
	BIT_VEC cppVar_55671;
	BIT_VEC cppVar_55672;
	BIT_VEC cppVar_55673;
	BIT_VEC cppVar_55675;
	BIT_VEC cppVar_55676;
	bool cppVar_55677;
	BIT_VEC cppVar_55678;
	BIT_VEC cppVar_55679;
	BIT_VEC cppVar_55680;
	BIT_VEC cppVar_55681;
	BIT_VEC cppVar_55682;
	BIT_VEC cppVar_55683;
	BIT_VEC cppVar_55684;
	BIT_VEC cppVar_55685;
	BIT_VEC cppVar_55686;
	BIT_VEC cppVar_55687;
	BIT_VEC cppVar_55688;
	BIT_VEC cppVar_55689;
	BIT_VEC cppVar_55690;
	BIT_VEC cppVar_55691;
	BIT_VEC cppVar_55692;
	BIT_VEC cppVar_55693;
	BIT_VEC cppVar_55694;
	BIT_VEC cppVar_55695;
	BIT_VEC cppVar_55696;
	BIT_VEC cppVar_55697;
	BIT_VEC cppVar_55698;
	BIT_VEC cppVar_55699;
	BIT_VEC cppVar_55700;
	BIT_VEC cppVar_55701;
	BIT_VEC cppVar_55702;
	BIT_VEC cppVar_55703;
	BIT_VEC cppVar_55705;
	BIT_VEC cppVar_55706;
	BIT_VEC cppVar_55707;
	BIT_VEC cppVar_55708;
	BIT_VEC cppVar_55709;
	BIT_VEC cppVar_55710;
	BIT_VEC cppVar_55711;
	BIT_VEC cppVar_55712;
	BIT_VEC cppVar_55713;
	BIT_VEC cppVar_55714;
	BIT_VEC cppVar_55715;
	BIT_VEC cppVar_55716;
	BIT_VEC cppVar_55717;
	BIT_VEC cppVar_55718;
	BIT_VEC cppVar_55719;
	BIT_VEC cppVar_55720;
	BIT_VEC cppVar_55721;
	BIT_VEC cppVar_55722;
	BIT_VEC cppVar_55723;
	BIT_VEC cppVar_55724;
	bool cppVar_55725;
	BIT_VEC cppVar_55726;
	BIT_VEC cppVar_55727;
	BIT_VEC cppVar_55704;
	BIT_VEC cppVar_55728;
	BIT_VEC cppVar_55729;
	BIT_VEC cppVar_55730;
	BIT_VEC cppVar_55731;
	BIT_VEC cppVar_55732;
	BIT_VEC cppVar_55734;
	BIT_VEC cppVar_55735;
	bool cppVar_55736;
	BIT_VEC cppVar_55737;
	BIT_VEC cppVar_55738;
	BIT_VEC cppVar_55739;
	BIT_VEC cppVar_55740;
	BIT_VEC cppVar_55741;
	BIT_VEC cppVar_55742;
	BIT_VEC cppVar_55743;
	BIT_VEC cppVar_55744;
	BIT_VEC cppVar_55745;
	BIT_VEC cppVar_55746;
	BIT_VEC cppVar_55747;
	BIT_VEC cppVar_55748;
	BIT_VEC cppVar_55749;
	BIT_VEC cppVar_55750;
	BIT_VEC cppVar_55751;
	BIT_VEC cppVar_55752;
	BIT_VEC cppVar_55753;
	BIT_VEC cppVar_55754;
	BIT_VEC cppVar_55755;
	BIT_VEC cppVar_55756;
	BIT_VEC cppVar_55757;
	BIT_VEC cppVar_55758;
	BIT_VEC cppVar_55759;
	BIT_VEC cppVar_55760;
	BIT_VEC cppVar_55761;
	BIT_VEC cppVar_55762;
	BIT_VEC cppVar_55764;
	BIT_VEC cppVar_55765;
	BIT_VEC cppVar_55766;
	BIT_VEC cppVar_55767;
	BIT_VEC cppVar_55768;
	BIT_VEC cppVar_55769;
	BIT_VEC cppVar_55770;
	BIT_VEC cppVar_55771;
	BIT_VEC cppVar_55772;
	BIT_VEC cppVar_55773;
	BIT_VEC cppVar_55774;
	BIT_VEC cppVar_55775;
	BIT_VEC cppVar_55776;
	BIT_VEC cppVar_55777;
	BIT_VEC cppVar_55778;
	BIT_VEC cppVar_55779;
	BIT_VEC cppVar_55780;
	BIT_VEC cppVar_55781;
	BIT_VEC cppVar_55782;
	BIT_VEC cppVar_55783;
	bool cppVar_55784;
	BIT_VEC cppVar_55785;
	BIT_VEC cppVar_55786;
	BIT_VEC cppVar_55763;
	BIT_VEC cppVar_55787;
	BIT_VEC cppVar_55788;
	BIT_VEC cppVar_55789;
	BIT_VEC cppVar_55790;
	BIT_VEC cppVar_55791;
	BIT_VEC cppVar_55793;
	BIT_VEC cppVar_55794;
	bool cppVar_55795;
	BIT_VEC cppVar_55796;
	BIT_VEC cppVar_55797;
	BIT_VEC cppVar_55798;
	BIT_VEC cppVar_55799;
	BIT_VEC cppVar_55800;
	BIT_VEC cppVar_55801;
	BIT_VEC cppVar_55802;
	BIT_VEC cppVar_55803;
	BIT_VEC cppVar_55804;
	BIT_VEC cppVar_55805;
	BIT_VEC cppVar_55806;
	BIT_VEC cppVar_55807;
	BIT_VEC cppVar_55808;
	BIT_VEC cppVar_55809;
	BIT_VEC cppVar_55810;
	BIT_VEC cppVar_55811;
	BIT_VEC cppVar_55812;
	BIT_VEC cppVar_55813;
	BIT_VEC cppVar_55814;
	BIT_VEC cppVar_55815;
	BIT_VEC cppVar_55816;
	BIT_VEC cppVar_55817;
	BIT_VEC cppVar_55818;
	BIT_VEC cppVar_55819;
	BIT_VEC cppVar_55820;
	BIT_VEC cppVar_55821;
	BIT_VEC cppVar_55822;
	BIT_VEC cppVar_55823;
	BIT_VEC cppVar_55825;
	BIT_VEC cppVar_55826;
	BIT_VEC cppVar_55827;
	BIT_VEC cppVar_55828;
	BIT_VEC cppVar_55829;
	BIT_VEC cppVar_55830;
	BIT_VEC cppVar_55831;
	BIT_VEC cppVar_55832;
	BIT_VEC cppVar_55833;
	BIT_VEC cppVar_55834;
	BIT_VEC cppVar_55835;
	BIT_VEC cppVar_55836;
	BIT_VEC cppVar_55837;
	BIT_VEC cppVar_55838;
	BIT_VEC cppVar_55839;
	BIT_VEC cppVar_55840;
	BIT_VEC cppVar_55841;
	BIT_VEC cppVar_55842;
	BIT_VEC cppVar_55843;
	BIT_VEC cppVar_55844;
	BIT_VEC cppVar_55845;
	BIT_VEC cppVar_55846;
	bool cppVar_55847;
	BIT_VEC cppVar_55848;
	BIT_VEC cppVar_55849;
	BIT_VEC cppVar_55824;
	BIT_VEC cppVar_55850;
	BIT_VEC cppVar_55851;
	BIT_VEC cppVar_55852;
	BIT_VEC cppVar_55853;
	BIT_VEC cppVar_55854;
	BIT_VEC cppVar_55856;
	BIT_VEC cppVar_55857;
	bool cppVar_55858;
	BIT_VEC cppVar_55859;
	BIT_VEC cppVar_55860;
	BIT_VEC cppVar_55861;
	BIT_VEC cppVar_55862;
	BIT_VEC cppVar_55863;
	BIT_VEC cppVar_55864;
	BIT_VEC cppVar_55865;
	BIT_VEC cppVar_55866;
	BIT_VEC cppVar_55867;
	BIT_VEC cppVar_55868;
	BIT_VEC cppVar_55869;
	BIT_VEC cppVar_55870;
	BIT_VEC cppVar_55871;
	BIT_VEC cppVar_55872;
	BIT_VEC cppVar_55873;
	BIT_VEC cppVar_55874;
	BIT_VEC cppVar_55875;
	BIT_VEC cppVar_55876;
	BIT_VEC cppVar_55877;
	BIT_VEC cppVar_55878;
	BIT_VEC cppVar_55879;
	BIT_VEC cppVar_55880;
	BIT_VEC cppVar_55881;
	BIT_VEC cppVar_55882;
	BIT_VEC cppVar_55883;
	BIT_VEC cppVar_55884;
	BIT_VEC cppVar_55885;
	BIT_VEC cppVar_55886;
	BIT_VEC cppVar_55888;
	BIT_VEC cppVar_55889;
	BIT_VEC cppVar_55890;
	BIT_VEC cppVar_55891;
	BIT_VEC cppVar_55892;
	BIT_VEC cppVar_55893;
	BIT_VEC cppVar_55894;
	BIT_VEC cppVar_55895;
	BIT_VEC cppVar_55896;
	BIT_VEC cppVar_55897;
	BIT_VEC cppVar_55898;
	BIT_VEC cppVar_55899;
	BIT_VEC cppVar_55900;
	BIT_VEC cppVar_55901;
	BIT_VEC cppVar_55902;
	BIT_VEC cppVar_55903;
	BIT_VEC cppVar_55904;
	BIT_VEC cppVar_55905;
	BIT_VEC cppVar_55906;
	BIT_VEC cppVar_55907;
	BIT_VEC cppVar_55908;
	BIT_VEC cppVar_55909;
	bool cppVar_55910;
	BIT_VEC cppVar_55911;
	BIT_VEC cppVar_55912;
	BIT_VEC cppVar_55887;
	BIT_VEC cppVar_55913;
	BIT_VEC cppVar_55914;
	BIT_VEC cppVar_55915;
	BIT_VEC cppVar_55916;
	BIT_VEC cppVar_55917;
	BIT_VEC cppVar_55919;
	BIT_VEC cppVar_55920;
	bool cppVar_55921;
	BIT_VEC cppVar_55922;
	BIT_VEC cppVar_55924;
	BIT_VEC cppVar_55925;
	BIT_VEC cppVar_55926;
	BIT_VEC cppVar_55927;
	BIT_VEC cppVar_55928;
	bool cppVar_55929;
	BIT_VEC cppVar_55930;
	BIT_VEC cppVar_55931;
	BIT_VEC cppVar_55932;
	BIT_VEC cppVar_55934;
	BIT_VEC cppVar_55935;
	BIT_VEC cppVar_55936;
	bool cppVar_55937;
	BIT_VEC cppVar_55939;
	BIT_VEC cppVar_55940;
	BIT_VEC cppVar_55941;
	bool cppVar_55942;
	BIT_VEC cppVar_55944;
	BIT_VEC cppVar_55945;
	BIT_VEC cppVar_55946;
	bool cppVar_55947;
	BIT_VEC cppVar_55949;
	BIT_VEC cppVar_55950;
	BIT_VEC cppVar_55951;
	bool cppVar_55952;
	BIT_VEC cppVar_55954;
	BIT_VEC cppVar_55955;
	BIT_VEC cppVar_55956;
	bool cppVar_55957;
	BIT_VEC cppVar_55959;
	BIT_VEC cppVar_55960;
	BIT_VEC cppVar_55961;
	bool cppVar_55962;
	BIT_VEC cppVar_55964;
	BIT_VEC cppVar_55965;
	BIT_VEC cppVar_55966;
	bool cppVar_55967;
	BIT_VEC cppVar_55969;
	BIT_VEC cppVar_55970;
	BIT_VEC cppVar_55971;
	bool cppVar_55972;
	BIT_VEC cppVar_55974;
	BIT_VEC cppVar_55975;
	BIT_VEC cppVar_55976;
	bool cppVar_55977;
	BIT_VEC cppVar_55979;
	BIT_VEC cppVar_55980;
	BIT_VEC cppVar_55981;
	bool cppVar_55982;
	BIT_VEC cppVar_55984;
	BIT_VEC cppVar_55985;
	BIT_VEC cppVar_55986;
	bool cppVar_55987;
	BIT_VEC cppVar_55989;
	BIT_VEC cppVar_55990;
	BIT_VEC cppVar_55991;
	bool cppVar_55992;
	BIT_VEC cppVar_55994;
	BIT_VEC cppVar_55995;
	BIT_VEC cppVar_55996;
	bool cppVar_55997;
	BIT_VEC cppVar_55999;
	BIT_VEC cppVar_56000;
	BIT_VEC cppVar_56001;
	bool cppVar_56002;
	BIT_VEC cppVar_56004;
	BIT_VEC cppVar_56005;
	BIT_VEC cppVar_56006;
	bool cppVar_56007;
	BIT_VEC cppVar_56009;
	BIT_VEC cppVar_56010;
	BIT_VEC cppVar_56011;
	bool cppVar_56012;
	BIT_VEC cppVar_56014;
	BIT_VEC cppVar_56015;
	BIT_VEC cppVar_56016;
	bool cppVar_56017;
	BIT_VEC cppVar_56019;
	BIT_VEC cppVar_56020;
	BIT_VEC cppVar_56021;
	bool cppVar_56022;
	BIT_VEC cppVar_56024;
	BIT_VEC cppVar_56025;
	BIT_VEC cppVar_56026;
	bool cppVar_56027;
	BIT_VEC cppVar_56029;
	BIT_VEC cppVar_56030;
	BIT_VEC cppVar_56031;
	bool cppVar_56032;
	BIT_VEC cppVar_56034;
	BIT_VEC cppVar_56035;
	BIT_VEC cppVar_56036;
	bool cppVar_56037;
	BIT_VEC cppVar_56038;
	BIT_VEC cppVar_56033;
	BIT_VEC cppVar_56028;
	BIT_VEC cppVar_56023;
	BIT_VEC cppVar_56018;
	BIT_VEC cppVar_56013;
	BIT_VEC cppVar_56008;
	BIT_VEC cppVar_56003;
	BIT_VEC cppVar_55998;
	BIT_VEC cppVar_55993;
	BIT_VEC cppVar_55988;
	BIT_VEC cppVar_55983;
	BIT_VEC cppVar_55978;
	BIT_VEC cppVar_55973;
	BIT_VEC cppVar_55968;
	BIT_VEC cppVar_55963;
	BIT_VEC cppVar_55958;
	BIT_VEC cppVar_55953;
	BIT_VEC cppVar_55948;
	BIT_VEC cppVar_55943;
	BIT_VEC cppVar_55938;
	BIT_VEC cppVar_55933;
	BIT_VEC cppVar_55923;
	BIT_VEC cppVar_56039;
	BIT_VEC cppVar_56040;
	BIT_VEC cppVar_56041;
	BIT_VEC cppVar_56042;
	BIT_VEC cppVar_56043;
	BIT_VEC cppVar_56044;
	BIT_VEC cppVar_56045;
	BIT_VEC cppVar_56046;
	BIT_VEC cppVar_56048;
	BIT_VEC cppVar_56049;
	BIT_VEC cppVar_56050;
	bool cppVar_56051;
	BIT_VEC cppVar_56052;
	BIT_VEC cppVar_56053;
	BIT_VEC cppVar_56054;
	BIT_VEC cppVar_56056;
	BIT_VEC cppVar_56057;
	bool cppVar_56058;
	BIT_VEC cppVar_56060;
	BIT_VEC cppVar_56061;
	bool cppVar_56062;
	BIT_VEC cppVar_56064;
	BIT_VEC cppVar_56065;
	bool cppVar_56066;
	BIT_VEC cppVar_56068;
	BIT_VEC cppVar_56069;
	bool cppVar_56070;
	BIT_VEC cppVar_56072;
	BIT_VEC cppVar_56073;
	bool cppVar_56074;
	BIT_VEC cppVar_56076;
	BIT_VEC cppVar_56077;
	bool cppVar_56078;
	BIT_VEC cppVar_56080;
	BIT_VEC cppVar_56081;
	bool cppVar_56082;
	BIT_VEC cppVar_56084;
	BIT_VEC cppVar_56085;
	bool cppVar_56086;
	BIT_VEC cppVar_56088;
	BIT_VEC cppVar_56089;
	bool cppVar_56090;
	BIT_VEC cppVar_56092;
	BIT_VEC cppVar_56093;
	bool cppVar_56094;
	BIT_VEC cppVar_56096;
	BIT_VEC cppVar_56097;
	bool cppVar_56098;
	BIT_VEC cppVar_56100;
	BIT_VEC cppVar_56101;
	bool cppVar_56102;
	BIT_VEC cppVar_56104;
	BIT_VEC cppVar_56105;
	bool cppVar_56106;
	BIT_VEC cppVar_56108;
	BIT_VEC cppVar_56109;
	bool cppVar_56110;
	BIT_VEC cppVar_56112;
	BIT_VEC cppVar_56113;
	bool cppVar_56114;
	BIT_VEC cppVar_56116;
	BIT_VEC cppVar_56117;
	bool cppVar_56118;
	BIT_VEC cppVar_56120;
	BIT_VEC cppVar_56121;
	bool cppVar_56122;
	BIT_VEC cppVar_56124;
	BIT_VEC cppVar_56125;
	bool cppVar_56126;
	BIT_VEC cppVar_56128;
	BIT_VEC cppVar_56129;
	bool cppVar_56130;
	BIT_VEC cppVar_56132;
	BIT_VEC cppVar_56133;
	bool cppVar_56134;
	BIT_VEC cppVar_56136;
	BIT_VEC cppVar_56137;
	bool cppVar_56138;
	BIT_VEC cppVar_56135;
	BIT_VEC cppVar_56131;
	BIT_VEC cppVar_56127;
	BIT_VEC cppVar_56123;
	BIT_VEC cppVar_56119;
	BIT_VEC cppVar_56115;
	BIT_VEC cppVar_56111;
	BIT_VEC cppVar_56107;
	BIT_VEC cppVar_56103;
	BIT_VEC cppVar_56099;
	BIT_VEC cppVar_56095;
	BIT_VEC cppVar_56091;
	BIT_VEC cppVar_56087;
	BIT_VEC cppVar_56083;
	BIT_VEC cppVar_56079;
	BIT_VEC cppVar_56075;
	BIT_VEC cppVar_56071;
	BIT_VEC cppVar_56067;
	BIT_VEC cppVar_56063;
	BIT_VEC cppVar_56059;
	BIT_VEC cppVar_56055;
	BIT_VEC cppVar_56047;
	BIT_VEC cppVar_56139;
	BIT_VEC cppVar_56140;
	BIT_VEC cppVar_56141;
	BIT_VEC cppVar_56142;
	BIT_VEC cppVar_56143;
	BIT_VEC cppVar_56144;
	BIT_VEC cppVar_56145;
	BIT_VEC cppVar_56147;
	BIT_VEC cppVar_56149;
	BIT_VEC cppVar_56150;
	BIT_VEC cppVar_56151;
	bool cppVar_56152;
	BIT_VEC cppVar_56153;
	BIT_VEC cppVar_56154;
	BIT_VEC cppVar_56155;
	BIT_VEC cppVar_56157;
	BIT_VEC cppVar_56158;
	bool cppVar_56159;
	BIT_VEC cppVar_56161;
	BIT_VEC cppVar_56162;
	bool cppVar_56163;
	BIT_VEC cppVar_56165;
	BIT_VEC cppVar_56166;
	bool cppVar_56167;
	BIT_VEC cppVar_56169;
	BIT_VEC cppVar_56170;
	bool cppVar_56171;
	BIT_VEC cppVar_56173;
	BIT_VEC cppVar_56174;
	bool cppVar_56175;
	BIT_VEC cppVar_56177;
	BIT_VEC cppVar_56178;
	bool cppVar_56179;
	BIT_VEC cppVar_56181;
	BIT_VEC cppVar_56182;
	bool cppVar_56183;
	BIT_VEC cppVar_56185;
	BIT_VEC cppVar_56186;
	bool cppVar_56187;
	BIT_VEC cppVar_56189;
	BIT_VEC cppVar_56190;
	bool cppVar_56191;
	BIT_VEC cppVar_56193;
	BIT_VEC cppVar_56194;
	bool cppVar_56195;
	BIT_VEC cppVar_56197;
	BIT_VEC cppVar_56198;
	bool cppVar_56199;
	BIT_VEC cppVar_56201;
	BIT_VEC cppVar_56202;
	bool cppVar_56203;
	BIT_VEC cppVar_56205;
	BIT_VEC cppVar_56206;
	bool cppVar_56207;
	BIT_VEC cppVar_56209;
	BIT_VEC cppVar_56210;
	bool cppVar_56211;
	BIT_VEC cppVar_56213;
	BIT_VEC cppVar_56214;
	bool cppVar_56215;
	BIT_VEC cppVar_56217;
	BIT_VEC cppVar_56218;
	bool cppVar_56219;
	BIT_VEC cppVar_56221;
	BIT_VEC cppVar_56222;
	bool cppVar_56223;
	BIT_VEC cppVar_56225;
	BIT_VEC cppVar_56226;
	bool cppVar_56227;
	BIT_VEC cppVar_56229;
	BIT_VEC cppVar_56230;
	bool cppVar_56231;
	BIT_VEC cppVar_56233;
	BIT_VEC cppVar_56234;
	bool cppVar_56235;
	BIT_VEC cppVar_56237;
	BIT_VEC cppVar_56238;
	bool cppVar_56239;
	BIT_VEC cppVar_56236;
	BIT_VEC cppVar_56232;
	BIT_VEC cppVar_56228;
	BIT_VEC cppVar_56224;
	BIT_VEC cppVar_56220;
	BIT_VEC cppVar_56216;
	BIT_VEC cppVar_56212;
	BIT_VEC cppVar_56208;
	BIT_VEC cppVar_56204;
	BIT_VEC cppVar_56200;
	BIT_VEC cppVar_56196;
	BIT_VEC cppVar_56192;
	BIT_VEC cppVar_56188;
	BIT_VEC cppVar_56184;
	BIT_VEC cppVar_56180;
	BIT_VEC cppVar_56176;
	BIT_VEC cppVar_56172;
	BIT_VEC cppVar_56168;
	BIT_VEC cppVar_56164;
	BIT_VEC cppVar_56160;
	BIT_VEC cppVar_56156;
	BIT_VEC cppVar_56148;
	BIT_VEC cppVar_56240;
	BIT_VEC cppVar_56241;
	BIT_VEC cppVar_56242;
	BIT_VEC cppVar_56243;
	BIT_VEC cppVar_56244;
	BIT_VEC cppVar_56245;
	BIT_VEC cppVar_56247;
	BIT_VEC cppVar_56248;
	BIT_VEC cppVar_56249;
	bool cppVar_56250;
	BIT_VEC cppVar_56251;
	BIT_VEC cppVar_56252;
	BIT_VEC cppVar_56253;
	BIT_VEC cppVar_56255;
	BIT_VEC cppVar_56256;
	bool cppVar_56257;
	BIT_VEC cppVar_56259;
	BIT_VEC cppVar_56260;
	bool cppVar_56261;
	BIT_VEC cppVar_56263;
	BIT_VEC cppVar_56264;
	bool cppVar_56265;
	BIT_VEC cppVar_56267;
	BIT_VEC cppVar_56268;
	bool cppVar_56269;
	BIT_VEC cppVar_56271;
	BIT_VEC cppVar_56272;
	bool cppVar_56273;
	BIT_VEC cppVar_56275;
	BIT_VEC cppVar_56276;
	bool cppVar_56277;
	BIT_VEC cppVar_56279;
	BIT_VEC cppVar_56280;
	bool cppVar_56281;
	BIT_VEC cppVar_56283;
	BIT_VEC cppVar_56284;
	bool cppVar_56285;
	BIT_VEC cppVar_56287;
	BIT_VEC cppVar_56288;
	bool cppVar_56289;
	BIT_VEC cppVar_56291;
	BIT_VEC cppVar_56292;
	bool cppVar_56293;
	BIT_VEC cppVar_56295;
	BIT_VEC cppVar_56296;
	bool cppVar_56297;
	BIT_VEC cppVar_56299;
	BIT_VEC cppVar_56300;
	bool cppVar_56301;
	BIT_VEC cppVar_56303;
	BIT_VEC cppVar_56304;
	bool cppVar_56305;
	BIT_VEC cppVar_56307;
	BIT_VEC cppVar_56308;
	bool cppVar_56309;
	BIT_VEC cppVar_56311;
	BIT_VEC cppVar_56312;
	bool cppVar_56313;
	BIT_VEC cppVar_56315;
	BIT_VEC cppVar_56316;
	bool cppVar_56317;
	BIT_VEC cppVar_56319;
	BIT_VEC cppVar_56320;
	bool cppVar_56321;
	BIT_VEC cppVar_56323;
	BIT_VEC cppVar_56324;
	bool cppVar_56325;
	BIT_VEC cppVar_56327;
	BIT_VEC cppVar_56328;
	bool cppVar_56329;
	BIT_VEC cppVar_56331;
	BIT_VEC cppVar_56332;
	bool cppVar_56333;
	BIT_VEC cppVar_56335;
	BIT_VEC cppVar_56336;
	bool cppVar_56337;
	BIT_VEC cppVar_56334;
	BIT_VEC cppVar_56330;
	BIT_VEC cppVar_56326;
	BIT_VEC cppVar_56322;
	BIT_VEC cppVar_56318;
	BIT_VEC cppVar_56314;
	BIT_VEC cppVar_56310;
	BIT_VEC cppVar_56306;
	BIT_VEC cppVar_56302;
	BIT_VEC cppVar_56298;
	BIT_VEC cppVar_56294;
	BIT_VEC cppVar_56290;
	BIT_VEC cppVar_56286;
	BIT_VEC cppVar_56282;
	BIT_VEC cppVar_56278;
	BIT_VEC cppVar_56274;
	BIT_VEC cppVar_56270;
	BIT_VEC cppVar_56266;
	BIT_VEC cppVar_56262;
	BIT_VEC cppVar_56258;
	BIT_VEC cppVar_56254;
	BIT_VEC cppVar_56246;
	BIT_VEC cppVar_56338;
	BIT_VEC cppVar_56339;
	BIT_VEC cppVar_56340;
	BIT_VEC cppVar_56341;
	BIT_VEC cppVar_56342;
	bool cppVar_56343;
	BIT_VEC cppVar_56344;
	BIT_VEC cppVar_56345;
	BIT_VEC cppVar_56146;
	BIT_VEC cppVar_56346;
	BIT_VEC cppVar_56347;
	BIT_VEC cppVar_56348;
	BIT_VEC cppVar_56349;
	BIT_VEC cppVar_56350;
	BIT_VEC cppVar_56352;
	BIT_VEC cppVar_56353;
	bool cppVar_56354;
	BIT_VEC cppVar_56355;
	BIT_VEC cppVar_56356;
	BIT_VEC cppVar_56357;
	BIT_VEC cppVar_56358;
	BIT_VEC cppVar_56359;
	BIT_VEC cppVar_56360;
	BIT_VEC cppVar_56361;
	BIT_VEC cppVar_56362;
	BIT_VEC cppVar_56363;
	BIT_VEC cppVar_56364;
	BIT_VEC cppVar_56365;
	BIT_VEC cppVar_56366;
	BIT_VEC cppVar_56367;
	BIT_VEC cppVar_56368;
	BIT_VEC cppVar_56369;
	BIT_VEC cppVar_56370;
	BIT_VEC cppVar_56371;
	BIT_VEC cppVar_56372;
	BIT_VEC cppVar_56373;
	BIT_VEC cppVar_56374;
	BIT_VEC cppVar_56375;
	BIT_VEC cppVar_56377;
	BIT_VEC cppVar_56378;
	BIT_VEC cppVar_56379;
	BIT_VEC cppVar_56380;
	BIT_VEC cppVar_56381;
	BIT_VEC cppVar_56382;
	BIT_VEC cppVar_56383;
	BIT_VEC cppVar_56384;
	BIT_VEC cppVar_56385;
	BIT_VEC cppVar_56386;
	BIT_VEC cppVar_56387;
	BIT_VEC cppVar_56388;
	BIT_VEC cppVar_56389;
	BIT_VEC cppVar_56390;
	BIT_VEC cppVar_56391;
	BIT_VEC cppVar_56392;
	bool cppVar_56393;
	BIT_VEC cppVar_56394;
	BIT_VEC cppVar_56395;
	BIT_VEC cppVar_56376;
	BIT_VEC cppVar_56396;
	BIT_VEC cppVar_56397;
	BIT_VEC cppVar_56398;
	BIT_VEC cppVar_56399;
	BIT_VEC cppVar_56400;
	BIT_VEC cppVar_56402;
	BIT_VEC cppVar_56403;
	bool cppVar_56404;
	BIT_VEC cppVar_56405;
	BIT_VEC cppVar_56406;
	bool cppVar_56407;
	bool cppVar_56408;
	BIT_VEC cppVar_56410;
	BIT_VEC cppVar_56411;
	BIT_VEC cppVar_56412;
	BIT_VEC cppVar_56413;
	bool cppVar_56414;
	BIT_VEC cppVar_56416;
	BIT_VEC cppVar_56417;
	BIT_VEC cppVar_56418;
	BIT_VEC cppVar_56419;
	bool cppVar_56420;
	BIT_VEC cppVar_56421;
	BIT_VEC cppVar_56422;
	BIT_VEC cppVar_56423;
	BIT_VEC cppVar_56425;
	BIT_VEC cppVar_56426;
	BIT_VEC cppVar_56427;
	bool cppVar_56428;
	BIT_VEC cppVar_56430;
	BIT_VEC cppVar_56431;
	BIT_VEC cppVar_56432;
	bool cppVar_56433;
	BIT_VEC cppVar_56435;
	BIT_VEC cppVar_56436;
	BIT_VEC cppVar_56437;
	bool cppVar_56438;
	BIT_VEC cppVar_56440;
	BIT_VEC cppVar_56441;
	BIT_VEC cppVar_56442;
	bool cppVar_56443;
	BIT_VEC cppVar_56445;
	BIT_VEC cppVar_56446;
	BIT_VEC cppVar_56447;
	bool cppVar_56448;
	BIT_VEC cppVar_56450;
	BIT_VEC cppVar_56451;
	BIT_VEC cppVar_56452;
	bool cppVar_56453;
	BIT_VEC cppVar_56455;
	BIT_VEC cppVar_56456;
	BIT_VEC cppVar_56457;
	bool cppVar_56458;
	BIT_VEC cppVar_56460;
	BIT_VEC cppVar_56461;
	BIT_VEC cppVar_56462;
	bool cppVar_56463;
	BIT_VEC cppVar_56465;
	BIT_VEC cppVar_56466;
	BIT_VEC cppVar_56467;
	bool cppVar_56468;
	BIT_VEC cppVar_56470;
	BIT_VEC cppVar_56471;
	BIT_VEC cppVar_56472;
	bool cppVar_56473;
	BIT_VEC cppVar_56475;
	BIT_VEC cppVar_56476;
	BIT_VEC cppVar_56477;
	bool cppVar_56478;
	BIT_VEC cppVar_56480;
	BIT_VEC cppVar_56481;
	BIT_VEC cppVar_56482;
	bool cppVar_56483;
	BIT_VEC cppVar_56485;
	BIT_VEC cppVar_56486;
	BIT_VEC cppVar_56487;
	bool cppVar_56488;
	BIT_VEC cppVar_56490;
	BIT_VEC cppVar_56491;
	BIT_VEC cppVar_56492;
	bool cppVar_56493;
	BIT_VEC cppVar_56495;
	BIT_VEC cppVar_56496;
	BIT_VEC cppVar_56497;
	bool cppVar_56498;
	BIT_VEC cppVar_56500;
	BIT_VEC cppVar_56501;
	BIT_VEC cppVar_56502;
	bool cppVar_56503;
	BIT_VEC cppVar_56505;
	BIT_VEC cppVar_56506;
	BIT_VEC cppVar_56507;
	bool cppVar_56508;
	BIT_VEC cppVar_56510;
	BIT_VEC cppVar_56511;
	BIT_VEC cppVar_56512;
	bool cppVar_56513;
	BIT_VEC cppVar_56515;
	BIT_VEC cppVar_56516;
	BIT_VEC cppVar_56517;
	bool cppVar_56518;
	BIT_VEC cppVar_56520;
	BIT_VEC cppVar_56521;
	BIT_VEC cppVar_56522;
	bool cppVar_56523;
	BIT_VEC cppVar_56525;
	BIT_VEC cppVar_56526;
	BIT_VEC cppVar_56527;
	bool cppVar_56528;
	BIT_VEC cppVar_56529;
	BIT_VEC cppVar_56524;
	BIT_VEC cppVar_56519;
	BIT_VEC cppVar_56514;
	BIT_VEC cppVar_56509;
	BIT_VEC cppVar_56504;
	BIT_VEC cppVar_56499;
	BIT_VEC cppVar_56494;
	BIT_VEC cppVar_56489;
	BIT_VEC cppVar_56484;
	BIT_VEC cppVar_56479;
	BIT_VEC cppVar_56474;
	BIT_VEC cppVar_56469;
	BIT_VEC cppVar_56464;
	BIT_VEC cppVar_56459;
	BIT_VEC cppVar_56454;
	BIT_VEC cppVar_56449;
	BIT_VEC cppVar_56444;
	BIT_VEC cppVar_56439;
	BIT_VEC cppVar_56434;
	BIT_VEC cppVar_56429;
	BIT_VEC cppVar_56424;
	BIT_VEC cppVar_56415;
	BIT_VEC cppVar_56530;
	BIT_VEC cppVar_56531;
	BIT_VEC cppVar_56409;
	BIT_VEC cppVar_56533;
	BIT_VEC cppVar_56534;
	bool cppVar_56535;
	BIT_VEC cppVar_56536;
	BIT_VEC cppVar_56537;
	BIT_VEC cppVar_56538;
	BIT_VEC cppVar_56539;
	BIT_VEC cppVar_56540;
	BIT_VEC cppVar_56541;
	BIT_VEC cppVar_56542;
	BIT_VEC cppVar_56543;
	BIT_VEC cppVar_56544;
	BIT_VEC cppVar_56546;
	BIT_VEC cppVar_56547;
	bool cppVar_56548;
	BIT_VEC cppVar_56549;
	BIT_VEC cppVar_56550;
	bool cppVar_56551;
	bool cppVar_56552;
	BIT_VEC cppVar_56555;
	BIT_VEC cppVar_56556;
	BIT_VEC cppVar_56557;
	BIT_VEC cppVar_56558;
	BIT_VEC cppVar_56559;
	bool cppVar_56560;
	BIT_VEC cppVar_56561;
	BIT_VEC cppVar_56562;
	BIT_VEC cppVar_56563;
	BIT_VEC cppVar_56564;
	BIT_VEC cppVar_56565;
	BIT_VEC cppVar_56566;
	BIT_VEC cppVar_56567;
	BIT_VEC cppVar_56568;
	BIT_VEC cppVar_56569;
	BIT_VEC cppVar_56570;
	BIT_VEC cppVar_56571;
	BIT_VEC cppVar_56554;
	BIT_VEC cppVar_56572;
	bool cppVar_56573;
	BIT_VEC cppVar_56574;
	BIT_VEC cppVar_56575;
	BIT_VEC cppVar_56576;
	BIT_VEC cppVar_56577;
	BIT_VEC cppVar_56578;
	BIT_VEC cppVar_56579;
	BIT_VEC cppVar_56580;
	BIT_VEC cppVar_56583;
	BIT_VEC cppVar_56584;
	BIT_VEC cppVar_56585;
	bool cppVar_56586;
	BIT_VEC cppVar_56587;
	BIT_VEC cppVar_56588;
	BIT_VEC cppVar_56589;
	BIT_VEC cppVar_56590;
	BIT_VEC cppVar_56591;
	BIT_VEC cppVar_56592;
	BIT_VEC cppVar_56593;
	BIT_VEC cppVar_56594;
	BIT_VEC cppVar_56595;
	BIT_VEC cppVar_56582;
	BIT_VEC cppVar_56596;
	BIT_VEC cppVar_56597;
	bool cppVar_56598;
	BIT_VEC cppVar_56600;
	BIT_VEC cppVar_56601;
	BIT_VEC cppVar_56602;
	bool cppVar_56603;
	BIT_VEC cppVar_56604;
	BIT_VEC cppVar_56605;
	BIT_VEC cppVar_56606;
	BIT_VEC cppVar_56607;
	BIT_VEC cppVar_56608;
	BIT_VEC cppVar_56609;
	BIT_VEC cppVar_56610;
	BIT_VEC cppVar_56611;
	BIT_VEC cppVar_56612;
	BIT_VEC cppVar_56599;
	BIT_VEC cppVar_56613;
	BIT_VEC cppVar_56616;
	BIT_VEC cppVar_56617;
	BIT_VEC cppVar_56618;
	bool cppVar_56619;
	BIT_VEC cppVar_56620;
	BIT_VEC cppVar_56621;
	BIT_VEC cppVar_56622;
	BIT_VEC cppVar_56623;
	BIT_VEC cppVar_56624;
	BIT_VEC cppVar_56625;
	BIT_VEC cppVar_56626;
	BIT_VEC cppVar_56627;
	BIT_VEC cppVar_56628;
	BIT_VEC cppVar_56615;
	BIT_VEC cppVar_56629;
	bool cppVar_56630;
	BIT_VEC cppVar_56633;
	BIT_VEC cppVar_56634;
	BIT_VEC cppVar_56635;
	bool cppVar_56636;
	BIT_VEC cppVar_56637;
	BIT_VEC cppVar_56638;
	BIT_VEC cppVar_56639;
	BIT_VEC cppVar_56640;
	BIT_VEC cppVar_56641;
	BIT_VEC cppVar_56642;
	BIT_VEC cppVar_56643;
	BIT_VEC cppVar_56644;
	BIT_VEC cppVar_56645;
	BIT_VEC cppVar_56632;
	BIT_VEC cppVar_56646;
	bool cppVar_56647;
	BIT_VEC cppVar_56650;
	BIT_VEC cppVar_56651;
	BIT_VEC cppVar_56652;
	bool cppVar_56653;
	BIT_VEC cppVar_56654;
	BIT_VEC cppVar_56655;
	BIT_VEC cppVar_56656;
	BIT_VEC cppVar_56657;
	BIT_VEC cppVar_56658;
	BIT_VEC cppVar_56659;
	BIT_VEC cppVar_56660;
	BIT_VEC cppVar_56661;
	BIT_VEC cppVar_56662;
	BIT_VEC cppVar_56649;
	BIT_VEC cppVar_56663;
	bool cppVar_56664;
	BIT_VEC cppVar_56667;
	BIT_VEC cppVar_56668;
	BIT_VEC cppVar_56669;
	bool cppVar_56670;
	BIT_VEC cppVar_56671;
	BIT_VEC cppVar_56672;
	BIT_VEC cppVar_56673;
	BIT_VEC cppVar_56674;
	BIT_VEC cppVar_56675;
	BIT_VEC cppVar_56676;
	BIT_VEC cppVar_56677;
	BIT_VEC cppVar_56678;
	BIT_VEC cppVar_56679;
	BIT_VEC cppVar_56666;
	BIT_VEC cppVar_56680;
	bool cppVar_56681;
	BIT_VEC cppVar_56684;
	BIT_VEC cppVar_56685;
	BIT_VEC cppVar_56686;
	bool cppVar_56687;
	BIT_VEC cppVar_56688;
	BIT_VEC cppVar_56689;
	BIT_VEC cppVar_56690;
	BIT_VEC cppVar_56691;
	BIT_VEC cppVar_56692;
	BIT_VEC cppVar_56693;
	BIT_VEC cppVar_56694;
	BIT_VEC cppVar_56695;
	BIT_VEC cppVar_56696;
	BIT_VEC cppVar_56683;
	BIT_VEC cppVar_56697;
	bool cppVar_56698;
	BIT_VEC cppVar_56701;
	BIT_VEC cppVar_56702;
	BIT_VEC cppVar_56703;
	bool cppVar_56704;
	BIT_VEC cppVar_56705;
	BIT_VEC cppVar_56706;
	BIT_VEC cppVar_56707;
	BIT_VEC cppVar_56708;
	BIT_VEC cppVar_56709;
	BIT_VEC cppVar_56710;
	BIT_VEC cppVar_56711;
	BIT_VEC cppVar_56712;
	BIT_VEC cppVar_56713;
	BIT_VEC cppVar_56700;
	BIT_VEC cppVar_56714;
	bool cppVar_56715;
	BIT_VEC cppVar_56718;
	BIT_VEC cppVar_56719;
	BIT_VEC cppVar_56720;
	bool cppVar_56721;
	BIT_VEC cppVar_56722;
	BIT_VEC cppVar_56723;
	BIT_VEC cppVar_56724;
	BIT_VEC cppVar_56725;
	BIT_VEC cppVar_56726;
	BIT_VEC cppVar_56727;
	BIT_VEC cppVar_56728;
	BIT_VEC cppVar_56729;
	BIT_VEC cppVar_56730;
	BIT_VEC cppVar_56717;
	BIT_VEC cppVar_56731;
	bool cppVar_56732;
	BIT_VEC cppVar_56735;
	BIT_VEC cppVar_56736;
	BIT_VEC cppVar_56737;
	bool cppVar_56738;
	BIT_VEC cppVar_56739;
	BIT_VEC cppVar_56740;
	BIT_VEC cppVar_56741;
	BIT_VEC cppVar_56742;
	BIT_VEC cppVar_56743;
	BIT_VEC cppVar_56744;
	BIT_VEC cppVar_56745;
	BIT_VEC cppVar_56746;
	BIT_VEC cppVar_56747;
	BIT_VEC cppVar_56734;
	BIT_VEC cppVar_56748;
	bool cppVar_56749;
	BIT_VEC cppVar_56752;
	BIT_VEC cppVar_56753;
	BIT_VEC cppVar_56754;
	bool cppVar_56755;
	BIT_VEC cppVar_56756;
	BIT_VEC cppVar_56757;
	BIT_VEC cppVar_56758;
	BIT_VEC cppVar_56759;
	BIT_VEC cppVar_56760;
	BIT_VEC cppVar_56761;
	BIT_VEC cppVar_56762;
	BIT_VEC cppVar_56763;
	BIT_VEC cppVar_56764;
	BIT_VEC cppVar_56751;
	BIT_VEC cppVar_56765;
	bool cppVar_56766;
	BIT_VEC cppVar_56769;
	BIT_VEC cppVar_56770;
	BIT_VEC cppVar_56771;
	bool cppVar_56772;
	BIT_VEC cppVar_56773;
	BIT_VEC cppVar_56774;
	BIT_VEC cppVar_56775;
	BIT_VEC cppVar_56776;
	BIT_VEC cppVar_56777;
	BIT_VEC cppVar_56778;
	BIT_VEC cppVar_56779;
	BIT_VEC cppVar_56780;
	BIT_VEC cppVar_56781;
	BIT_VEC cppVar_56768;
	BIT_VEC cppVar_56782;
	bool cppVar_56783;
	BIT_VEC cppVar_56786;
	BIT_VEC cppVar_56787;
	BIT_VEC cppVar_56788;
	bool cppVar_56789;
	BIT_VEC cppVar_56790;
	BIT_VEC cppVar_56791;
	BIT_VEC cppVar_56792;
	BIT_VEC cppVar_56793;
	BIT_VEC cppVar_56794;
	BIT_VEC cppVar_56795;
	BIT_VEC cppVar_56796;
	BIT_VEC cppVar_56797;
	BIT_VEC cppVar_56798;
	BIT_VEC cppVar_56785;
	BIT_VEC cppVar_56799;
	bool cppVar_56800;
	BIT_VEC cppVar_56803;
	BIT_VEC cppVar_56804;
	BIT_VEC cppVar_56805;
	bool cppVar_56806;
	BIT_VEC cppVar_56807;
	BIT_VEC cppVar_56808;
	BIT_VEC cppVar_56809;
	BIT_VEC cppVar_56810;
	BIT_VEC cppVar_56811;
	BIT_VEC cppVar_56812;
	BIT_VEC cppVar_56813;
	BIT_VEC cppVar_56814;
	BIT_VEC cppVar_56815;
	BIT_VEC cppVar_56802;
	BIT_VEC cppVar_56816;
	bool cppVar_56817;
	BIT_VEC cppVar_56820;
	BIT_VEC cppVar_56821;
	BIT_VEC cppVar_56822;
	bool cppVar_56823;
	BIT_VEC cppVar_56824;
	BIT_VEC cppVar_56825;
	BIT_VEC cppVar_56826;
	BIT_VEC cppVar_56827;
	BIT_VEC cppVar_56828;
	BIT_VEC cppVar_56829;
	BIT_VEC cppVar_56830;
	BIT_VEC cppVar_56831;
	BIT_VEC cppVar_56832;
	BIT_VEC cppVar_56819;
	BIT_VEC cppVar_56833;
	bool cppVar_56834;
	BIT_VEC cppVar_56837;
	BIT_VEC cppVar_56838;
	BIT_VEC cppVar_56839;
	bool cppVar_56840;
	BIT_VEC cppVar_56841;
	BIT_VEC cppVar_56842;
	BIT_VEC cppVar_56843;
	BIT_VEC cppVar_56844;
	BIT_VEC cppVar_56845;
	BIT_VEC cppVar_56846;
	BIT_VEC cppVar_56847;
	BIT_VEC cppVar_56848;
	BIT_VEC cppVar_56849;
	BIT_VEC cppVar_56836;
	BIT_VEC cppVar_56850;
	bool cppVar_56851;
	BIT_VEC cppVar_56854;
	BIT_VEC cppVar_56855;
	BIT_VEC cppVar_56856;
	bool cppVar_56857;
	BIT_VEC cppVar_56858;
	BIT_VEC cppVar_56859;
	BIT_VEC cppVar_56860;
	BIT_VEC cppVar_56861;
	BIT_VEC cppVar_56862;
	BIT_VEC cppVar_56863;
	BIT_VEC cppVar_56864;
	BIT_VEC cppVar_56865;
	BIT_VEC cppVar_56866;
	BIT_VEC cppVar_56853;
	BIT_VEC cppVar_56867;
	bool cppVar_56868;
	BIT_VEC cppVar_56871;
	BIT_VEC cppVar_56872;
	BIT_VEC cppVar_56873;
	bool cppVar_56874;
	BIT_VEC cppVar_56875;
	BIT_VEC cppVar_56876;
	BIT_VEC cppVar_56877;
	BIT_VEC cppVar_56878;
	BIT_VEC cppVar_56879;
	BIT_VEC cppVar_56880;
	BIT_VEC cppVar_56881;
	BIT_VEC cppVar_56882;
	BIT_VEC cppVar_56883;
	BIT_VEC cppVar_56870;
	BIT_VEC cppVar_56884;
	bool cppVar_56885;
	BIT_VEC cppVar_56888;
	BIT_VEC cppVar_56889;
	BIT_VEC cppVar_56890;
	bool cppVar_56891;
	BIT_VEC cppVar_56892;
	BIT_VEC cppVar_56893;
	BIT_VEC cppVar_56894;
	BIT_VEC cppVar_56895;
	BIT_VEC cppVar_56896;
	BIT_VEC cppVar_56897;
	BIT_VEC cppVar_56898;
	BIT_VEC cppVar_56899;
	BIT_VEC cppVar_56900;
	BIT_VEC cppVar_56887;
	BIT_VEC cppVar_56901;
	bool cppVar_56902;
	BIT_VEC cppVar_56905;
	BIT_VEC cppVar_56906;
	BIT_VEC cppVar_56907;
	bool cppVar_56908;
	BIT_VEC cppVar_56909;
	BIT_VEC cppVar_56910;
	BIT_VEC cppVar_56911;
	BIT_VEC cppVar_56912;
	BIT_VEC cppVar_56913;
	BIT_VEC cppVar_56914;
	BIT_VEC cppVar_56915;
	BIT_VEC cppVar_56916;
	BIT_VEC cppVar_56917;
	BIT_VEC cppVar_56904;
	BIT_VEC cppVar_56918;
	bool cppVar_56919;
	BIT_VEC cppVar_56922;
	BIT_VEC cppVar_56923;
	BIT_VEC cppVar_56924;
	bool cppVar_56925;
	BIT_VEC cppVar_56926;
	BIT_VEC cppVar_56927;
	BIT_VEC cppVar_56928;
	BIT_VEC cppVar_56929;
	BIT_VEC cppVar_56930;
	BIT_VEC cppVar_56931;
	BIT_VEC cppVar_56932;
	BIT_VEC cppVar_56933;
	BIT_VEC cppVar_56934;
	BIT_VEC cppVar_56921;
	BIT_VEC cppVar_56935;
	bool cppVar_56936;
	BIT_VEC cppVar_56939;
	BIT_VEC cppVar_56940;
	BIT_VEC cppVar_56941;
	bool cppVar_56942;
	BIT_VEC cppVar_56943;
	BIT_VEC cppVar_56944;
	BIT_VEC cppVar_56945;
	BIT_VEC cppVar_56946;
	BIT_VEC cppVar_56947;
	BIT_VEC cppVar_56948;
	BIT_VEC cppVar_56949;
	BIT_VEC cppVar_56950;
	BIT_VEC cppVar_56951;
	BIT_VEC cppVar_56938;
	BIT_VEC cppVar_56952;
	bool cppVar_56953;
	BIT_VEC cppVar_56956;
	BIT_VEC cppVar_56957;
	BIT_VEC cppVar_56958;
	bool cppVar_56959;
	BIT_VEC cppVar_56960;
	BIT_VEC cppVar_56961;
	BIT_VEC cppVar_56962;
	BIT_VEC cppVar_56963;
	BIT_VEC cppVar_56964;
	BIT_VEC cppVar_56965;
	BIT_VEC cppVar_56966;
	BIT_VEC cppVar_56967;
	BIT_VEC cppVar_56968;
	BIT_VEC cppVar_56955;
	BIT_VEC cppVar_56969;
	bool cppVar_56970;
	BIT_VEC cppVar_56971;
	BIT_VEC cppVar_56954;
	BIT_VEC cppVar_56937;
	BIT_VEC cppVar_56920;
	BIT_VEC cppVar_56903;
	BIT_VEC cppVar_56886;
	BIT_VEC cppVar_56869;
	BIT_VEC cppVar_56852;
	BIT_VEC cppVar_56835;
	BIT_VEC cppVar_56818;
	BIT_VEC cppVar_56801;
	BIT_VEC cppVar_56784;
	BIT_VEC cppVar_56767;
	BIT_VEC cppVar_56750;
	BIT_VEC cppVar_56733;
	BIT_VEC cppVar_56716;
	BIT_VEC cppVar_56699;
	BIT_VEC cppVar_56682;
	BIT_VEC cppVar_56665;
	BIT_VEC cppVar_56648;
	BIT_VEC cppVar_56631;
	BIT_VEC cppVar_56614;
	BIT_VEC cppVar_56581;
	BIT_VEC cppVar_56972;
	BIT_VEC cppVar_56973;
	BIT_VEC cppVar_56974;
	BIT_VEC cppVar_56975;
	BIT_VEC cppVar_56976;
	BIT_VEC cppVar_56977;
	BIT_VEC cppVar_56978;
	BIT_VEC cppVar_56979;
	BIT_VEC cppVar_56980;
	BIT_VEC cppVar_56553;
	BIT_VEC cppVar_56982;
	BIT_VEC cppVar_56983;
	bool cppVar_56984;
	BIT_VEC cppVar_56986;
	BIT_VEC cppVar_56987;
	BIT_VEC cppVar_56988;
	BIT_VEC cppVar_56989;
	bool cppVar_56990;
	BIT_VEC cppVar_56992;
	BIT_VEC cppVar_56993;
	BIT_VEC cppVar_56994;
	BIT_VEC cppVar_56995;
	bool cppVar_56996;
	BIT_VEC cppVar_56997;
	BIT_VEC cppVar_56998;
	BIT_VEC cppVar_56999;
	BIT_VEC cppVar_57001;
	BIT_VEC cppVar_57002;
	BIT_VEC cppVar_57003;
	bool cppVar_57004;
	BIT_VEC cppVar_57006;
	BIT_VEC cppVar_57007;
	BIT_VEC cppVar_57008;
	bool cppVar_57009;
	BIT_VEC cppVar_57011;
	BIT_VEC cppVar_57012;
	BIT_VEC cppVar_57013;
	bool cppVar_57014;
	BIT_VEC cppVar_57016;
	BIT_VEC cppVar_57017;
	BIT_VEC cppVar_57018;
	bool cppVar_57019;
	BIT_VEC cppVar_57021;
	BIT_VEC cppVar_57022;
	BIT_VEC cppVar_57023;
	bool cppVar_57024;
	BIT_VEC cppVar_57026;
	BIT_VEC cppVar_57027;
	BIT_VEC cppVar_57028;
	bool cppVar_57029;
	BIT_VEC cppVar_57031;
	BIT_VEC cppVar_57032;
	BIT_VEC cppVar_57033;
	bool cppVar_57034;
	BIT_VEC cppVar_57036;
	BIT_VEC cppVar_57037;
	BIT_VEC cppVar_57038;
	bool cppVar_57039;
	BIT_VEC cppVar_57041;
	BIT_VEC cppVar_57042;
	BIT_VEC cppVar_57043;
	bool cppVar_57044;
	BIT_VEC cppVar_57046;
	BIT_VEC cppVar_57047;
	BIT_VEC cppVar_57048;
	bool cppVar_57049;
	BIT_VEC cppVar_57051;
	BIT_VEC cppVar_57052;
	BIT_VEC cppVar_57053;
	bool cppVar_57054;
	BIT_VEC cppVar_57056;
	BIT_VEC cppVar_57057;
	BIT_VEC cppVar_57058;
	bool cppVar_57059;
	BIT_VEC cppVar_57061;
	BIT_VEC cppVar_57062;
	BIT_VEC cppVar_57063;
	bool cppVar_57064;
	BIT_VEC cppVar_57066;
	BIT_VEC cppVar_57067;
	BIT_VEC cppVar_57068;
	bool cppVar_57069;
	BIT_VEC cppVar_57071;
	BIT_VEC cppVar_57072;
	BIT_VEC cppVar_57073;
	bool cppVar_57074;
	BIT_VEC cppVar_57076;
	BIT_VEC cppVar_57077;
	BIT_VEC cppVar_57078;
	bool cppVar_57079;
	BIT_VEC cppVar_57081;
	BIT_VEC cppVar_57082;
	BIT_VEC cppVar_57083;
	bool cppVar_57084;
	BIT_VEC cppVar_57086;
	BIT_VEC cppVar_57087;
	BIT_VEC cppVar_57088;
	bool cppVar_57089;
	BIT_VEC cppVar_57091;
	BIT_VEC cppVar_57092;
	BIT_VEC cppVar_57093;
	bool cppVar_57094;
	BIT_VEC cppVar_57096;
	BIT_VEC cppVar_57097;
	BIT_VEC cppVar_57098;
	bool cppVar_57099;
	BIT_VEC cppVar_57101;
	BIT_VEC cppVar_57102;
	BIT_VEC cppVar_57103;
	bool cppVar_57104;
	BIT_VEC cppVar_57105;
	BIT_VEC cppVar_57100;
	BIT_VEC cppVar_57095;
	BIT_VEC cppVar_57090;
	BIT_VEC cppVar_57085;
	BIT_VEC cppVar_57080;
	BIT_VEC cppVar_57075;
	BIT_VEC cppVar_57070;
	BIT_VEC cppVar_57065;
	BIT_VEC cppVar_57060;
	BIT_VEC cppVar_57055;
	BIT_VEC cppVar_57050;
	BIT_VEC cppVar_57045;
	BIT_VEC cppVar_57040;
	BIT_VEC cppVar_57035;
	BIT_VEC cppVar_57030;
	BIT_VEC cppVar_57025;
	BIT_VEC cppVar_57020;
	BIT_VEC cppVar_57015;
	BIT_VEC cppVar_57010;
	BIT_VEC cppVar_57005;
	BIT_VEC cppVar_57000;
	BIT_VEC cppVar_56991;
	BIT_VEC cppVar_57106;
	BIT_VEC cppVar_57107;
	BIT_VEC cppVar_56985;
	BIT_VEC cppVar_56981;
	BIT_VEC cppVar_56545;
	BIT_VEC cppVar_56532;
	BIT_VEC cppVar_56401;
	BIT_VEC cppVar_56351;
	BIT_VEC cppVar_55918;
	BIT_VEC cppVar_55855;
	BIT_VEC cppVar_55792;
	BIT_VEC cppVar_55733;
	BIT_VEC cppVar_55674;
	BIT_VEC cppVar_55615;
	BIT_VEC cppVar_55556;
	BIT_VEC cppVar_55497;
	BIT_VEC cppVar_55438;
	BIT_VEC cppVar_55379;
	BIT_VEC cppVar_55320;
	BIT_VEC cppVar_55307;
	BIT_VEC cppVar_55254;
	BIT_VEC cppVar_54818;
	BIT_VEC cppVar_54752;
	BIT_VEC cppVar_54686;
	BIT_VEC cppVar_54624;
	BIT_VEC cppVar_54562;
	BIT_VEC cppVar_54500;
	BIT_VEC cppVar_54438;
	BIT_VEC cppVar_54376;
	BIT_VEC cppVar_54314;
	BIT_VEC cppVar_54252;
	BIT_VEC cppVar_54190;
	BIT_VEC cppVar_54064;
	BIT_VEC cppVar_53935;
	BIT_VEC cppVar_53809;
	BIT_VEC cppVar_53680;
	BIT_VEC cppVar_53554;
	BIT_VEC cppVar_53425;
	BIT_VEC cppVar_53018;
	BIT_VEC cppVar_53005;
	BIT_VEC cppVar_52598;
	BIT_VEC cppVar_52583;
	BIT_VEC cppVar_52457;
	BIT_VEC cppVar_52440;
	BIT_VEC cppVar_52423;
	BIT_VEC cppVar_52273;
	BIT_VEC cppVar_52123;
	BIT_VEC cppVar_51973;
	BIT_VEC cppVar_51823;
	BIT_VEC cppVar_51673;
	BIT_VEC cppVar_51523;
	BIT_VEC cppVar_51373;
	BIT_VEC cppVar_51223;
	BIT_VEC cppVar_50791;
	BIT_VEC cppVar_50736;
	BIT_VEC cppVar_50298;
	BIT_VEC cppVar_50228;
	BIT_VEC cppVar_50158;
	BIT_VEC cppVar_50094;
	BIT_VEC cppVar_50030;
	BIT_VEC cppVar_49966;
	BIT_VEC cppVar_49902;
	BIT_VEC cppVar_49838;
	BIT_VEC cppVar_49774;
	BIT_VEC cppVar_49710;
	BIT_VEC cppVar_49646;
	BIT_VEC cppVar_49238;
	BIT_VEC cppVar_48833;
	BIT_VEC cppVar_48814;
	BIT_VEC cppVar_48406;
	BIT_VEC cppVar_47576;
	BIT_VEC cppVar_47568;
	BIT_VEC cppVar_47555;
	BIT_VEC cppVar_47429;
	BIT_VEC cppVar_47409;
	BIT_VEC cppVar_47389;
	BIT_VEC cppVar_47370;
	BIT_VEC cppVar_47351;
	BIT_VEC cppVar_47332;
	BIT_VEC cppVar_47313;
	BIT_VEC cppVar_47294;
	BIT_VEC cppVar_47275;
	BIT_VEC cppVar_47256;
	BIT_VEC cppVar_47237;
	BIT_VEC cppVar_47230;
	BIT_VEC cppVar_47216;
	BIT_VEC cppVar_47205;
	BIT_VEC cppVar_46773;
	BIT_VEC cppVar_46766;
	BIT_VEC cppVar_46695;
	cppVar_46696 = ROM.rd(PC);
	cppVar_46698 = (cppVar_46696 == 212);
	if (cppVar_46698) {
	cppVar_46701 = (PSW >> 6) & cppMask_un_1_;
	cppVar_46703 = (cppVar_46701 == 1);
	cppVar_46704 = (ACC >> 0) & cppMask_un_4_;
	cppVar_46706 = cppVar_46704 > 9;
	cppVar_46707 = cppVar_46703 || cppVar_46706;
	if (cppVar_46707) {
	cppVar_46708 = (ACC & cppMask_un_8_);
	cppVar_46710 = cppVar_46708 + 6;
	cppVar_46710 = (cppVar_46710 & cppMask_un_9_);
	cppVar_46700 = cppVar_46710;
	} else {
	cppVar_46711 = (ACC & cppMask_un_8_);
	cppVar_46700 = cppVar_46711;
	}
	cppVar_46712 = (cppVar_46700 >> 8) & cppMask_un_1_;
	cppVar_46713 = (PSW >> 7) & cppMask_un_1_;
	cppVar_46714 = cppVar_46712 | cppVar_46713;
	cppVar_46716 = (cppVar_46714 == 1);
	cppVar_46718 = (PSW >> 6) & cppMask_un_1_;
	cppVar_46719 = (cppVar_46718 == 1);
	cppVar_46720 = (ACC >> 0) & cppMask_un_4_;
	cppVar_46721 = cppVar_46720 > 9;
	cppVar_46722 = cppVar_46719 || cppVar_46721;
	if (cppVar_46722) {
	cppVar_46723 = (ACC & cppMask_un_8_);
	cppVar_46724 = cppVar_46723 + 6;
	cppVar_46724 = (cppVar_46724 & cppMask_un_9_);
	cppVar_46717 = cppVar_46724;
	} else {
	cppVar_46725 = (ACC & cppMask_un_8_);
	cppVar_46717 = cppVar_46725;
	}
	cppVar_46726 = (cppVar_46717 >> 4) & cppMask_un_4_;
	cppVar_46728 = cppVar_46726 > 9;
	cppVar_46729 = cppVar_46716 || cppVar_46728;
	if (cppVar_46729) {
	cppVar_46731 = (PSW >> 6) & cppMask_un_1_;
	cppVar_46732 = (cppVar_46731 == 1);
	cppVar_46733 = (ACC >> 0) & cppMask_un_4_;
	cppVar_46734 = cppVar_46733 > 9;
	cppVar_46735 = cppVar_46732 || cppVar_46734;
	if (cppVar_46735) {
	cppVar_46736 = (ACC & cppMask_un_8_);
	cppVar_46737 = cppVar_46736 + 6;
	cppVar_46737 = (cppVar_46737 & cppMask_un_9_);
	cppVar_46730 = cppVar_46737;
	} else {
	cppVar_46738 = (ACC & cppMask_un_8_);
	cppVar_46730 = cppVar_46738;
	}
	cppVar_46740 = cppVar_46730 + 96;
	cppVar_46740 = (cppVar_46740 & cppMask_un_9_);
	cppVar_46699 = cppVar_46740;
	} else {
	cppVar_46742 = (PSW >> 6) & cppMask_un_1_;
	cppVar_46743 = (cppVar_46742 == 1);
	cppVar_46744 = (ACC >> 0) & cppMask_un_4_;
	cppVar_46745 = cppVar_46744 > 9;
	cppVar_46746 = cppVar_46743 || cppVar_46745;
	if (cppVar_46746) {
	cppVar_46747 = (ACC & cppMask_un_8_);
	cppVar_46748 = cppVar_46747 + 6;
	cppVar_46748 = (cppVar_46748 & cppMask_un_9_);
	cppVar_46741 = cppVar_46748;
	} else {
	cppVar_46749 = (ACC & cppMask_un_8_);
	cppVar_46741 = cppVar_46749;
	}
	cppVar_46699 = cppVar_46741;
	}
	cppVar_46750 = (cppVar_46699 >> 8) & cppMask_un_1_;
	cppVar_46752 = (PSW >> 6) & cppMask_un_1_;
	cppVar_46753 = (cppVar_46752 == 1);
	cppVar_46754 = (ACC >> 0) & cppMask_un_4_;
	cppVar_46755 = cppVar_46754 > 9;
	cppVar_46756 = cppVar_46753 || cppVar_46755;
	if (cppVar_46756) {
	cppVar_46757 = (ACC & cppMask_un_8_);
	cppVar_46758 = cppVar_46757 + 6;
	cppVar_46758 = (cppVar_46758 & cppMask_un_9_);
	cppVar_46751 = cppVar_46758;
	} else {
	cppVar_46759 = (ACC & cppMask_un_8_);
	cppVar_46751 = cppVar_46759;
	}
	cppVar_46760 = (cppVar_46751 >> 8) & cppMask_un_1_;
	cppVar_46761 = cppVar_46750 | cppVar_46760;
	cppVar_46762 = (PSW >> 7) & cppMask_un_1_;
	cppVar_46763 = cppVar_46761 | cppVar_46762;
	cppVar_46764 = (PSW >> 0) & cppMask_un_7_;
	cppVar_46765 = (cppVar_46763 << 7) | cppVar_46764;
	cppVar_46765 = (cppVar_46765 & cppMask_un_8_);
	cppVar_46695 = cppVar_46765;
	} else {
	cppVar_46767 = ROM.rd(PC);
	cppVar_46769 = (cppVar_46767 == 211);
	if (cppVar_46769) {
	cppVar_46771 = (PSW >> 0) & cppMask_un_7_;
	cppVar_46772 = (1 << 7) | cppVar_46771;
	cppVar_46772 = (cppVar_46772 & cppMask_un_8_);
	cppVar_46766 = cppVar_46772;
	} else {
	cppVar_46774 = ROM.rd(PC);
	cppVar_46776 = (cppVar_46774 == 210);
	if (cppVar_46776) {
	cppVar_46780 = PC + 1;
	cppVar_46780 = (cppVar_46780 & cppMask_un_16_);
	cppVar_46781 = ROM.rd(cppVar_46780);
	cppVar_46782 = (cppVar_46781 >> 7) & cppMask_un_1_;
	cppVar_46784 = (cppVar_46782 == 1);
	if (cppVar_46784) {
	cppVar_46785 = PC + 1;
	cppVar_46785 = (cppVar_46785 & cppMask_un_16_);
	cppVar_46786 = ROM.rd(cppVar_46785);
	cppVar_46787 = (cppVar_46786 >> 3) & cppMask_un_5_;
	cppVar_46789 = (cppVar_46787 << 3) | 0;
	cppVar_46789 = (cppVar_46789 & cppMask_un_8_);
	cppVar_46778 = cppVar_46789;
	} else {
	cppVar_46790 = PC + 1;
	cppVar_46790 = (cppVar_46790 & cppMask_un_16_);
	cppVar_46791 = ROM.rd(cppVar_46790);
	cppVar_46792 = (cppVar_46791 >> 3) & cppMask_un_5_;
	cppVar_46793 = (cppVar_46792 & cppMask_un_5_);
	cppVar_46795 = cppVar_46793 + 32;
	cppVar_46795 = (cppVar_46795 & cppMask_un_8_);
	cppVar_46778 = cppVar_46795;
	}
	cppVar_46797 = (cppVar_46778 == 208);
	if (cppVar_46797) {
	cppVar_46799 = PC + 1;
	cppVar_46799 = (cppVar_46799 & cppMask_un_16_);
	cppVar_46800 = ROM.rd(cppVar_46799);
	cppVar_46801 = (cppVar_46800 >> 0) & cppMask_un_3_;
	cppVar_46802 = (cppVar_46801 & cppMask_un_3_);
	cppVar_46803 = 1 << static_cast<unsigned>(cppVar_46802);
	cppVar_46803 = (cppVar_46803 & cppMask_un_8_);
	cppVar_46804 = ~cppVar_46803;
	cppVar_46807 = PC + 1;
	cppVar_46807 = (cppVar_46807 & cppMask_un_16_);
	cppVar_46808 = ROM.rd(cppVar_46807);
	cppVar_46809 = (cppVar_46808 >> 7) & cppMask_un_1_;
	cppVar_46810 = (cppVar_46809 == 1);
	if (cppVar_46810) {
	cppVar_46811 = PC + 1;
	cppVar_46811 = (cppVar_46811 & cppMask_un_16_);
	cppVar_46812 = ROM.rd(cppVar_46811);
	cppVar_46813 = (cppVar_46812 >> 3) & cppMask_un_5_;
	cppVar_46814 = (cppVar_46813 << 3) | 0;
	cppVar_46814 = (cppVar_46814 & cppMask_un_8_);
	cppVar_46806 = cppVar_46814;
	} else {
	cppVar_46815 = PC + 1;
	cppVar_46815 = (cppVar_46815 & cppMask_un_16_);
	cppVar_46816 = ROM.rd(cppVar_46815);
	cppVar_46817 = (cppVar_46816 >> 3) & cppMask_un_5_;
	cppVar_46818 = (cppVar_46817 & cppMask_un_5_);
	cppVar_46819 = cppVar_46818 + 32;
	cppVar_46819 = (cppVar_46819 & cppMask_un_8_);
	cppVar_46806 = cppVar_46819;
	}
	cppVar_46820 = (cppVar_46806 >> 7) & cppMask_un_1_;
	cppVar_46822 = (cppVar_46820 == 0);
	if (cppVar_46822) {
	cppVar_46824 = PC + 1;
	cppVar_46824 = (cppVar_46824 & cppMask_un_16_);
	cppVar_46825 = ROM.rd(cppVar_46824);
	cppVar_46826 = (cppVar_46825 >> 7) & cppMask_un_1_;
	cppVar_46827 = (cppVar_46826 == 1);
	if (cppVar_46827) {
	cppVar_46828 = PC + 1;
	cppVar_46828 = (cppVar_46828 & cppMask_un_16_);
	cppVar_46829 = ROM.rd(cppVar_46828);
	cppVar_46830 = (cppVar_46829 >> 3) & cppMask_un_5_;
	cppVar_46831 = (cppVar_46830 << 3) | 0;
	cppVar_46831 = (cppVar_46831 & cppMask_un_8_);
	cppVar_46823 = cppVar_46831;
	} else {
	cppVar_46832 = PC + 1;
	cppVar_46832 = (cppVar_46832 & cppMask_un_16_);
	cppVar_46833 = ROM.rd(cppVar_46832);
	cppVar_46834 = (cppVar_46833 >> 3) & cppMask_un_5_;
	cppVar_46835 = (cppVar_46834 & cppMask_un_5_);
	cppVar_46836 = cppVar_46835 + 32;
	cppVar_46836 = (cppVar_46836 & cppMask_un_8_);
	cppVar_46823 = cppVar_46836;
	}
	cppVar_46837 = IRAM.rd(cppVar_46823);
	cppVar_46805 = cppVar_46837;
	} else {
	cppVar_46840 = PC + 1;
	cppVar_46840 = (cppVar_46840 & cppMask_un_16_);
	cppVar_46841 = ROM.rd(cppVar_46840);
	cppVar_46842 = (cppVar_46841 >> 7) & cppMask_un_1_;
	cppVar_46843 = (cppVar_46842 == 1);
	if (cppVar_46843) {
	cppVar_46844 = PC + 1;
	cppVar_46844 = (cppVar_46844 & cppMask_un_16_);
	cppVar_46845 = ROM.rd(cppVar_46844);
	cppVar_46846 = (cppVar_46845 >> 3) & cppMask_un_5_;
	cppVar_46847 = (cppVar_46846 << 3) | 0;
	cppVar_46847 = (cppVar_46847 & cppMask_un_8_);
	cppVar_46839 = cppVar_46847;
	} else {
	cppVar_46848 = PC + 1;
	cppVar_46848 = (cppVar_46848 & cppMask_un_16_);
	cppVar_46849 = ROM.rd(cppVar_46848);
	cppVar_46850 = (cppVar_46849 >> 3) & cppMask_un_5_;
	cppVar_46851 = (cppVar_46850 & cppMask_un_5_);
	cppVar_46852 = cppVar_46851 + 32;
	cppVar_46852 = (cppVar_46852 & cppMask_un_8_);
	cppVar_46839 = cppVar_46852;
	}
	cppVar_46854 = (cppVar_46839 == 128);
	if (cppVar_46854) {
	cppVar_46838 = P0;
	} else {
	cppVar_46857 = PC + 1;
	cppVar_46857 = (cppVar_46857 & cppMask_un_16_);
	cppVar_46858 = ROM.rd(cppVar_46857);
	cppVar_46859 = (cppVar_46858 >> 7) & cppMask_un_1_;
	cppVar_46860 = (cppVar_46859 == 1);
	if (cppVar_46860) {
	cppVar_46861 = PC + 1;
	cppVar_46861 = (cppVar_46861 & cppMask_un_16_);
	cppVar_46862 = ROM.rd(cppVar_46861);
	cppVar_46863 = (cppVar_46862 >> 3) & cppMask_un_5_;
	cppVar_46864 = (cppVar_46863 << 3) | 0;
	cppVar_46864 = (cppVar_46864 & cppMask_un_8_);
	cppVar_46856 = cppVar_46864;
	} else {
	cppVar_46865 = PC + 1;
	cppVar_46865 = (cppVar_46865 & cppMask_un_16_);
	cppVar_46866 = ROM.rd(cppVar_46865);
	cppVar_46867 = (cppVar_46866 >> 3) & cppMask_un_5_;
	cppVar_46868 = (cppVar_46867 & cppMask_un_5_);
	cppVar_46869 = cppVar_46868 + 32;
	cppVar_46869 = (cppVar_46869 & cppMask_un_8_);
	cppVar_46856 = cppVar_46869;
	}
	cppVar_46871 = (cppVar_46856 == 129);
	if (cppVar_46871) {
	cppVar_46855 = SP;
	} else {
	cppVar_46874 = PC + 1;
	cppVar_46874 = (cppVar_46874 & cppMask_un_16_);
	cppVar_46875 = ROM.rd(cppVar_46874);
	cppVar_46876 = (cppVar_46875 >> 7) & cppMask_un_1_;
	cppVar_46877 = (cppVar_46876 == 1);
	if (cppVar_46877) {
	cppVar_46878 = PC + 1;
	cppVar_46878 = (cppVar_46878 & cppMask_un_16_);
	cppVar_46879 = ROM.rd(cppVar_46878);
	cppVar_46880 = (cppVar_46879 >> 3) & cppMask_un_5_;
	cppVar_46881 = (cppVar_46880 << 3) | 0;
	cppVar_46881 = (cppVar_46881 & cppMask_un_8_);
	cppVar_46873 = cppVar_46881;
	} else {
	cppVar_46882 = PC + 1;
	cppVar_46882 = (cppVar_46882 & cppMask_un_16_);
	cppVar_46883 = ROM.rd(cppVar_46882);
	cppVar_46884 = (cppVar_46883 >> 3) & cppMask_un_5_;
	cppVar_46885 = (cppVar_46884 & cppMask_un_5_);
	cppVar_46886 = cppVar_46885 + 32;
	cppVar_46886 = (cppVar_46886 & cppMask_un_8_);
	cppVar_46873 = cppVar_46886;
	}
	cppVar_46888 = (cppVar_46873 == 130);
	if (cppVar_46888) {
	cppVar_46872 = DPL;
	} else {
	cppVar_46891 = PC + 1;
	cppVar_46891 = (cppVar_46891 & cppMask_un_16_);
	cppVar_46892 = ROM.rd(cppVar_46891);
	cppVar_46893 = (cppVar_46892 >> 7) & cppMask_un_1_;
	cppVar_46894 = (cppVar_46893 == 1);
	if (cppVar_46894) {
	cppVar_46895 = PC + 1;
	cppVar_46895 = (cppVar_46895 & cppMask_un_16_);
	cppVar_46896 = ROM.rd(cppVar_46895);
	cppVar_46897 = (cppVar_46896 >> 3) & cppMask_un_5_;
	cppVar_46898 = (cppVar_46897 << 3) | 0;
	cppVar_46898 = (cppVar_46898 & cppMask_un_8_);
	cppVar_46890 = cppVar_46898;
	} else {
	cppVar_46899 = PC + 1;
	cppVar_46899 = (cppVar_46899 & cppMask_un_16_);
	cppVar_46900 = ROM.rd(cppVar_46899);
	cppVar_46901 = (cppVar_46900 >> 3) & cppMask_un_5_;
	cppVar_46902 = (cppVar_46901 & cppMask_un_5_);
	cppVar_46903 = cppVar_46902 + 32;
	cppVar_46903 = (cppVar_46903 & cppMask_un_8_);
	cppVar_46890 = cppVar_46903;
	}
	cppVar_46905 = (cppVar_46890 == 131);
	if (cppVar_46905) {
	cppVar_46889 = DPH;
	} else {
	cppVar_46908 = PC + 1;
	cppVar_46908 = (cppVar_46908 & cppMask_un_16_);
	cppVar_46909 = ROM.rd(cppVar_46908);
	cppVar_46910 = (cppVar_46909 >> 7) & cppMask_un_1_;
	cppVar_46911 = (cppVar_46910 == 1);
	if (cppVar_46911) {
	cppVar_46912 = PC + 1;
	cppVar_46912 = (cppVar_46912 & cppMask_un_16_);
	cppVar_46913 = ROM.rd(cppVar_46912);
	cppVar_46914 = (cppVar_46913 >> 3) & cppMask_un_5_;
	cppVar_46915 = (cppVar_46914 << 3) | 0;
	cppVar_46915 = (cppVar_46915 & cppMask_un_8_);
	cppVar_46907 = cppVar_46915;
	} else {
	cppVar_46916 = PC + 1;
	cppVar_46916 = (cppVar_46916 & cppMask_un_16_);
	cppVar_46917 = ROM.rd(cppVar_46916);
	cppVar_46918 = (cppVar_46917 >> 3) & cppMask_un_5_;
	cppVar_46919 = (cppVar_46918 & cppMask_un_5_);
	cppVar_46920 = cppVar_46919 + 32;
	cppVar_46920 = (cppVar_46920 & cppMask_un_8_);
	cppVar_46907 = cppVar_46920;
	}
	cppVar_46922 = (cppVar_46907 == 135);
	if (cppVar_46922) {
	cppVar_46906 = PCON;
	} else {
	cppVar_46925 = PC + 1;
	cppVar_46925 = (cppVar_46925 & cppMask_un_16_);
	cppVar_46926 = ROM.rd(cppVar_46925);
	cppVar_46927 = (cppVar_46926 >> 7) & cppMask_un_1_;
	cppVar_46928 = (cppVar_46927 == 1);
	if (cppVar_46928) {
	cppVar_46929 = PC + 1;
	cppVar_46929 = (cppVar_46929 & cppMask_un_16_);
	cppVar_46930 = ROM.rd(cppVar_46929);
	cppVar_46931 = (cppVar_46930 >> 3) & cppMask_un_5_;
	cppVar_46932 = (cppVar_46931 << 3) | 0;
	cppVar_46932 = (cppVar_46932 & cppMask_un_8_);
	cppVar_46924 = cppVar_46932;
	} else {
	cppVar_46933 = PC + 1;
	cppVar_46933 = (cppVar_46933 & cppMask_un_16_);
	cppVar_46934 = ROM.rd(cppVar_46933);
	cppVar_46935 = (cppVar_46934 >> 3) & cppMask_un_5_;
	cppVar_46936 = (cppVar_46935 & cppMask_un_5_);
	cppVar_46937 = cppVar_46936 + 32;
	cppVar_46937 = (cppVar_46937 & cppMask_un_8_);
	cppVar_46924 = cppVar_46937;
	}
	cppVar_46939 = (cppVar_46924 == 136);
	if (cppVar_46939) {
	cppVar_46923 = TCON;
	} else {
	cppVar_46942 = PC + 1;
	cppVar_46942 = (cppVar_46942 & cppMask_un_16_);
	cppVar_46943 = ROM.rd(cppVar_46942);
	cppVar_46944 = (cppVar_46943 >> 7) & cppMask_un_1_;
	cppVar_46945 = (cppVar_46944 == 1);
	if (cppVar_46945) {
	cppVar_46946 = PC + 1;
	cppVar_46946 = (cppVar_46946 & cppMask_un_16_);
	cppVar_46947 = ROM.rd(cppVar_46946);
	cppVar_46948 = (cppVar_46947 >> 3) & cppMask_un_5_;
	cppVar_46949 = (cppVar_46948 << 3) | 0;
	cppVar_46949 = (cppVar_46949 & cppMask_un_8_);
	cppVar_46941 = cppVar_46949;
	} else {
	cppVar_46950 = PC + 1;
	cppVar_46950 = (cppVar_46950 & cppMask_un_16_);
	cppVar_46951 = ROM.rd(cppVar_46950);
	cppVar_46952 = (cppVar_46951 >> 3) & cppMask_un_5_;
	cppVar_46953 = (cppVar_46952 & cppMask_un_5_);
	cppVar_46954 = cppVar_46953 + 32;
	cppVar_46954 = (cppVar_46954 & cppMask_un_8_);
	cppVar_46941 = cppVar_46954;
	}
	cppVar_46956 = (cppVar_46941 == 137);
	if (cppVar_46956) {
	cppVar_46940 = TMOD;
	} else {
	cppVar_46959 = PC + 1;
	cppVar_46959 = (cppVar_46959 & cppMask_un_16_);
	cppVar_46960 = ROM.rd(cppVar_46959);
	cppVar_46961 = (cppVar_46960 >> 7) & cppMask_un_1_;
	cppVar_46962 = (cppVar_46961 == 1);
	if (cppVar_46962) {
	cppVar_46963 = PC + 1;
	cppVar_46963 = (cppVar_46963 & cppMask_un_16_);
	cppVar_46964 = ROM.rd(cppVar_46963);
	cppVar_46965 = (cppVar_46964 >> 3) & cppMask_un_5_;
	cppVar_46966 = (cppVar_46965 << 3) | 0;
	cppVar_46966 = (cppVar_46966 & cppMask_un_8_);
	cppVar_46958 = cppVar_46966;
	} else {
	cppVar_46967 = PC + 1;
	cppVar_46967 = (cppVar_46967 & cppMask_un_16_);
	cppVar_46968 = ROM.rd(cppVar_46967);
	cppVar_46969 = (cppVar_46968 >> 3) & cppMask_un_5_;
	cppVar_46970 = (cppVar_46969 & cppMask_un_5_);
	cppVar_46971 = cppVar_46970 + 32;
	cppVar_46971 = (cppVar_46971 & cppMask_un_8_);
	cppVar_46958 = cppVar_46971;
	}
	cppVar_46973 = (cppVar_46958 == 138);
	if (cppVar_46973) {
	cppVar_46957 = TL0;
	} else {
	cppVar_46976 = PC + 1;
	cppVar_46976 = (cppVar_46976 & cppMask_un_16_);
	cppVar_46977 = ROM.rd(cppVar_46976);
	cppVar_46978 = (cppVar_46977 >> 7) & cppMask_un_1_;
	cppVar_46979 = (cppVar_46978 == 1);
	if (cppVar_46979) {
	cppVar_46980 = PC + 1;
	cppVar_46980 = (cppVar_46980 & cppMask_un_16_);
	cppVar_46981 = ROM.rd(cppVar_46980);
	cppVar_46982 = (cppVar_46981 >> 3) & cppMask_un_5_;
	cppVar_46983 = (cppVar_46982 << 3) | 0;
	cppVar_46983 = (cppVar_46983 & cppMask_un_8_);
	cppVar_46975 = cppVar_46983;
	} else {
	cppVar_46984 = PC + 1;
	cppVar_46984 = (cppVar_46984 & cppMask_un_16_);
	cppVar_46985 = ROM.rd(cppVar_46984);
	cppVar_46986 = (cppVar_46985 >> 3) & cppMask_un_5_;
	cppVar_46987 = (cppVar_46986 & cppMask_un_5_);
	cppVar_46988 = cppVar_46987 + 32;
	cppVar_46988 = (cppVar_46988 & cppMask_un_8_);
	cppVar_46975 = cppVar_46988;
	}
	cppVar_46990 = (cppVar_46975 == 140);
	if (cppVar_46990) {
	cppVar_46974 = TH0;
	} else {
	cppVar_46993 = PC + 1;
	cppVar_46993 = (cppVar_46993 & cppMask_un_16_);
	cppVar_46994 = ROM.rd(cppVar_46993);
	cppVar_46995 = (cppVar_46994 >> 7) & cppMask_un_1_;
	cppVar_46996 = (cppVar_46995 == 1);
	if (cppVar_46996) {
	cppVar_46997 = PC + 1;
	cppVar_46997 = (cppVar_46997 & cppMask_un_16_);
	cppVar_46998 = ROM.rd(cppVar_46997);
	cppVar_46999 = (cppVar_46998 >> 3) & cppMask_un_5_;
	cppVar_47000 = (cppVar_46999 << 3) | 0;
	cppVar_47000 = (cppVar_47000 & cppMask_un_8_);
	cppVar_46992 = cppVar_47000;
	} else {
	cppVar_47001 = PC + 1;
	cppVar_47001 = (cppVar_47001 & cppMask_un_16_);
	cppVar_47002 = ROM.rd(cppVar_47001);
	cppVar_47003 = (cppVar_47002 >> 3) & cppMask_un_5_;
	cppVar_47004 = (cppVar_47003 & cppMask_un_5_);
	cppVar_47005 = cppVar_47004 + 32;
	cppVar_47005 = (cppVar_47005 & cppMask_un_8_);
	cppVar_46992 = cppVar_47005;
	}
	cppVar_47007 = (cppVar_46992 == 139);
	if (cppVar_47007) {
	cppVar_46991 = TL1;
	} else {
	cppVar_47010 = PC + 1;
	cppVar_47010 = (cppVar_47010 & cppMask_un_16_);
	cppVar_47011 = ROM.rd(cppVar_47010);
	cppVar_47012 = (cppVar_47011 >> 7) & cppMask_un_1_;
	cppVar_47013 = (cppVar_47012 == 1);
	if (cppVar_47013) {
	cppVar_47014 = PC + 1;
	cppVar_47014 = (cppVar_47014 & cppMask_un_16_);
	cppVar_47015 = ROM.rd(cppVar_47014);
	cppVar_47016 = (cppVar_47015 >> 3) & cppMask_un_5_;
	cppVar_47017 = (cppVar_47016 << 3) | 0;
	cppVar_47017 = (cppVar_47017 & cppMask_un_8_);
	cppVar_47009 = cppVar_47017;
	} else {
	cppVar_47018 = PC + 1;
	cppVar_47018 = (cppVar_47018 & cppMask_un_16_);
	cppVar_47019 = ROM.rd(cppVar_47018);
	cppVar_47020 = (cppVar_47019 >> 3) & cppMask_un_5_;
	cppVar_47021 = (cppVar_47020 & cppMask_un_5_);
	cppVar_47022 = cppVar_47021 + 32;
	cppVar_47022 = (cppVar_47022 & cppMask_un_8_);
	cppVar_47009 = cppVar_47022;
	}
	cppVar_47024 = (cppVar_47009 == 141);
	if (cppVar_47024) {
	cppVar_47008 = TH1;
	} else {
	cppVar_47027 = PC + 1;
	cppVar_47027 = (cppVar_47027 & cppMask_un_16_);
	cppVar_47028 = ROM.rd(cppVar_47027);
	cppVar_47029 = (cppVar_47028 >> 7) & cppMask_un_1_;
	cppVar_47030 = (cppVar_47029 == 1);
	if (cppVar_47030) {
	cppVar_47031 = PC + 1;
	cppVar_47031 = (cppVar_47031 & cppMask_un_16_);
	cppVar_47032 = ROM.rd(cppVar_47031);
	cppVar_47033 = (cppVar_47032 >> 3) & cppMask_un_5_;
	cppVar_47034 = (cppVar_47033 << 3) | 0;
	cppVar_47034 = (cppVar_47034 & cppMask_un_8_);
	cppVar_47026 = cppVar_47034;
	} else {
	cppVar_47035 = PC + 1;
	cppVar_47035 = (cppVar_47035 & cppMask_un_16_);
	cppVar_47036 = ROM.rd(cppVar_47035);
	cppVar_47037 = (cppVar_47036 >> 3) & cppMask_un_5_;
	cppVar_47038 = (cppVar_47037 & cppMask_un_5_);
	cppVar_47039 = cppVar_47038 + 32;
	cppVar_47039 = (cppVar_47039 & cppMask_un_8_);
	cppVar_47026 = cppVar_47039;
	}
	cppVar_47041 = (cppVar_47026 == 144);
	if (cppVar_47041) {
	cppVar_47025 = P1;
	} else {
	cppVar_47044 = PC + 1;
	cppVar_47044 = (cppVar_47044 & cppMask_un_16_);
	cppVar_47045 = ROM.rd(cppVar_47044);
	cppVar_47046 = (cppVar_47045 >> 7) & cppMask_un_1_;
	cppVar_47047 = (cppVar_47046 == 1);
	if (cppVar_47047) {
	cppVar_47048 = PC + 1;
	cppVar_47048 = (cppVar_47048 & cppMask_un_16_);
	cppVar_47049 = ROM.rd(cppVar_47048);
	cppVar_47050 = (cppVar_47049 >> 3) & cppMask_un_5_;
	cppVar_47051 = (cppVar_47050 << 3) | 0;
	cppVar_47051 = (cppVar_47051 & cppMask_un_8_);
	cppVar_47043 = cppVar_47051;
	} else {
	cppVar_47052 = PC + 1;
	cppVar_47052 = (cppVar_47052 & cppMask_un_16_);
	cppVar_47053 = ROM.rd(cppVar_47052);
	cppVar_47054 = (cppVar_47053 >> 3) & cppMask_un_5_;
	cppVar_47055 = (cppVar_47054 & cppMask_un_5_);
	cppVar_47056 = cppVar_47055 + 32;
	cppVar_47056 = (cppVar_47056 & cppMask_un_8_);
	cppVar_47043 = cppVar_47056;
	}
	cppVar_47058 = (cppVar_47043 == 152);
	if (cppVar_47058) {
	cppVar_47042 = SCON;
	} else {
	cppVar_47061 = PC + 1;
	cppVar_47061 = (cppVar_47061 & cppMask_un_16_);
	cppVar_47062 = ROM.rd(cppVar_47061);
	cppVar_47063 = (cppVar_47062 >> 7) & cppMask_un_1_;
	cppVar_47064 = (cppVar_47063 == 1);
	if (cppVar_47064) {
	cppVar_47065 = PC + 1;
	cppVar_47065 = (cppVar_47065 & cppMask_un_16_);
	cppVar_47066 = ROM.rd(cppVar_47065);
	cppVar_47067 = (cppVar_47066 >> 3) & cppMask_un_5_;
	cppVar_47068 = (cppVar_47067 << 3) | 0;
	cppVar_47068 = (cppVar_47068 & cppMask_un_8_);
	cppVar_47060 = cppVar_47068;
	} else {
	cppVar_47069 = PC + 1;
	cppVar_47069 = (cppVar_47069 & cppMask_un_16_);
	cppVar_47070 = ROM.rd(cppVar_47069);
	cppVar_47071 = (cppVar_47070 >> 3) & cppMask_un_5_;
	cppVar_47072 = (cppVar_47071 & cppMask_un_5_);
	cppVar_47073 = cppVar_47072 + 32;
	cppVar_47073 = (cppVar_47073 & cppMask_un_8_);
	cppVar_47060 = cppVar_47073;
	}
	cppVar_47075 = (cppVar_47060 == 153);
	if (cppVar_47075) {
	cppVar_47059 = SBUF;
	} else {
	cppVar_47078 = PC + 1;
	cppVar_47078 = (cppVar_47078 & cppMask_un_16_);
	cppVar_47079 = ROM.rd(cppVar_47078);
	cppVar_47080 = (cppVar_47079 >> 7) & cppMask_un_1_;
	cppVar_47081 = (cppVar_47080 == 1);
	if (cppVar_47081) {
	cppVar_47082 = PC + 1;
	cppVar_47082 = (cppVar_47082 & cppMask_un_16_);
	cppVar_47083 = ROM.rd(cppVar_47082);
	cppVar_47084 = (cppVar_47083 >> 3) & cppMask_un_5_;
	cppVar_47085 = (cppVar_47084 << 3) | 0;
	cppVar_47085 = (cppVar_47085 & cppMask_un_8_);
	cppVar_47077 = cppVar_47085;
	} else {
	cppVar_47086 = PC + 1;
	cppVar_47086 = (cppVar_47086 & cppMask_un_16_);
	cppVar_47087 = ROM.rd(cppVar_47086);
	cppVar_47088 = (cppVar_47087 >> 3) & cppMask_un_5_;
	cppVar_47089 = (cppVar_47088 & cppMask_un_5_);
	cppVar_47090 = cppVar_47089 + 32;
	cppVar_47090 = (cppVar_47090 & cppMask_un_8_);
	cppVar_47077 = cppVar_47090;
	}
	cppVar_47092 = (cppVar_47077 == 160);
	if (cppVar_47092) {
	cppVar_47076 = P2;
	} else {
	cppVar_47095 = PC + 1;
	cppVar_47095 = (cppVar_47095 & cppMask_un_16_);
	cppVar_47096 = ROM.rd(cppVar_47095);
	cppVar_47097 = (cppVar_47096 >> 7) & cppMask_un_1_;
	cppVar_47098 = (cppVar_47097 == 1);
	if (cppVar_47098) {
	cppVar_47099 = PC + 1;
	cppVar_47099 = (cppVar_47099 & cppMask_un_16_);
	cppVar_47100 = ROM.rd(cppVar_47099);
	cppVar_47101 = (cppVar_47100 >> 3) & cppMask_un_5_;
	cppVar_47102 = (cppVar_47101 << 3) | 0;
	cppVar_47102 = (cppVar_47102 & cppMask_un_8_);
	cppVar_47094 = cppVar_47102;
	} else {
	cppVar_47103 = PC + 1;
	cppVar_47103 = (cppVar_47103 & cppMask_un_16_);
	cppVar_47104 = ROM.rd(cppVar_47103);
	cppVar_47105 = (cppVar_47104 >> 3) & cppMask_un_5_;
	cppVar_47106 = (cppVar_47105 & cppMask_un_5_);
	cppVar_47107 = cppVar_47106 + 32;
	cppVar_47107 = (cppVar_47107 & cppMask_un_8_);
	cppVar_47094 = cppVar_47107;
	}
	cppVar_47109 = (cppVar_47094 == 168);
	if (cppVar_47109) {
	cppVar_47093 = IE;
	} else {
	cppVar_47112 = PC + 1;
	cppVar_47112 = (cppVar_47112 & cppMask_un_16_);
	cppVar_47113 = ROM.rd(cppVar_47112);
	cppVar_47114 = (cppVar_47113 >> 7) & cppMask_un_1_;
	cppVar_47115 = (cppVar_47114 == 1);
	if (cppVar_47115) {
	cppVar_47116 = PC + 1;
	cppVar_47116 = (cppVar_47116 & cppMask_un_16_);
	cppVar_47117 = ROM.rd(cppVar_47116);
	cppVar_47118 = (cppVar_47117 >> 3) & cppMask_un_5_;
	cppVar_47119 = (cppVar_47118 << 3) | 0;
	cppVar_47119 = (cppVar_47119 & cppMask_un_8_);
	cppVar_47111 = cppVar_47119;
	} else {
	cppVar_47120 = PC + 1;
	cppVar_47120 = (cppVar_47120 & cppMask_un_16_);
	cppVar_47121 = ROM.rd(cppVar_47120);
	cppVar_47122 = (cppVar_47121 >> 3) & cppMask_un_5_;
	cppVar_47123 = (cppVar_47122 & cppMask_un_5_);
	cppVar_47124 = cppVar_47123 + 32;
	cppVar_47124 = (cppVar_47124 & cppMask_un_8_);
	cppVar_47111 = cppVar_47124;
	}
	cppVar_47126 = (cppVar_47111 == 176);
	if (cppVar_47126) {
	cppVar_47110 = P3;
	} else {
	cppVar_47129 = PC + 1;
	cppVar_47129 = (cppVar_47129 & cppMask_un_16_);
	cppVar_47130 = ROM.rd(cppVar_47129);
	cppVar_47131 = (cppVar_47130 >> 7) & cppMask_un_1_;
	cppVar_47132 = (cppVar_47131 == 1);
	if (cppVar_47132) {
	cppVar_47133 = PC + 1;
	cppVar_47133 = (cppVar_47133 & cppMask_un_16_);
	cppVar_47134 = ROM.rd(cppVar_47133);
	cppVar_47135 = (cppVar_47134 >> 3) & cppMask_un_5_;
	cppVar_47136 = (cppVar_47135 << 3) | 0;
	cppVar_47136 = (cppVar_47136 & cppMask_un_8_);
	cppVar_47128 = cppVar_47136;
	} else {
	cppVar_47137 = PC + 1;
	cppVar_47137 = (cppVar_47137 & cppMask_un_16_);
	cppVar_47138 = ROM.rd(cppVar_47137);
	cppVar_47139 = (cppVar_47138 >> 3) & cppMask_un_5_;
	cppVar_47140 = (cppVar_47139 & cppMask_un_5_);
	cppVar_47141 = cppVar_47140 + 32;
	cppVar_47141 = (cppVar_47141 & cppMask_un_8_);
	cppVar_47128 = cppVar_47141;
	}
	cppVar_47143 = (cppVar_47128 == 184);
	if (cppVar_47143) {
	cppVar_47127 = IP;
	} else {
	cppVar_47146 = PC + 1;
	cppVar_47146 = (cppVar_47146 & cppMask_un_16_);
	cppVar_47147 = ROM.rd(cppVar_47146);
	cppVar_47148 = (cppVar_47147 >> 7) & cppMask_un_1_;
	cppVar_47149 = (cppVar_47148 == 1);
	if (cppVar_47149) {
	cppVar_47150 = PC + 1;
	cppVar_47150 = (cppVar_47150 & cppMask_un_16_);
	cppVar_47151 = ROM.rd(cppVar_47150);
	cppVar_47152 = (cppVar_47151 >> 3) & cppMask_un_5_;
	cppVar_47153 = (cppVar_47152 << 3) | 0;
	cppVar_47153 = (cppVar_47153 & cppMask_un_8_);
	cppVar_47145 = cppVar_47153;
	} else {
	cppVar_47154 = PC + 1;
	cppVar_47154 = (cppVar_47154 & cppMask_un_16_);
	cppVar_47155 = ROM.rd(cppVar_47154);
	cppVar_47156 = (cppVar_47155 >> 3) & cppMask_un_5_;
	cppVar_47157 = (cppVar_47156 & cppMask_un_5_);
	cppVar_47158 = cppVar_47157 + 32;
	cppVar_47158 = (cppVar_47158 & cppMask_un_8_);
	cppVar_47145 = cppVar_47158;
	}
	cppVar_47160 = (cppVar_47145 == 208);
	if (cppVar_47160) {
	cppVar_47144 = PSW;
	} else {
	cppVar_47163 = PC + 1;
	cppVar_47163 = (cppVar_47163 & cppMask_un_16_);
	cppVar_47164 = ROM.rd(cppVar_47163);
	cppVar_47165 = (cppVar_47164 >> 7) & cppMask_un_1_;
	cppVar_47166 = (cppVar_47165 == 1);
	if (cppVar_47166) {
	cppVar_47167 = PC + 1;
	cppVar_47167 = (cppVar_47167 & cppMask_un_16_);
	cppVar_47168 = ROM.rd(cppVar_47167);
	cppVar_47169 = (cppVar_47168 >> 3) & cppMask_un_5_;
	cppVar_47170 = (cppVar_47169 << 3) | 0;
	cppVar_47170 = (cppVar_47170 & cppMask_un_8_);
	cppVar_47162 = cppVar_47170;
	} else {
	cppVar_47171 = PC + 1;
	cppVar_47171 = (cppVar_47171 & cppMask_un_16_);
	cppVar_47172 = ROM.rd(cppVar_47171);
	cppVar_47173 = (cppVar_47172 >> 3) & cppMask_un_5_;
	cppVar_47174 = (cppVar_47173 & cppMask_un_5_);
	cppVar_47175 = cppVar_47174 + 32;
	cppVar_47175 = (cppVar_47175 & cppMask_un_8_);
	cppVar_47162 = cppVar_47175;
	}
	cppVar_47177 = (cppVar_47162 == 224);
	if (cppVar_47177) {
	cppVar_47161 = ACC;
	} else {
	cppVar_47180 = PC + 1;
	cppVar_47180 = (cppVar_47180 & cppMask_un_16_);
	cppVar_47181 = ROM.rd(cppVar_47180);
	cppVar_47182 = (cppVar_47181 >> 7) & cppMask_un_1_;
	cppVar_47183 = (cppVar_47182 == 1);
	if (cppVar_47183) {
	cppVar_47184 = PC + 1;
	cppVar_47184 = (cppVar_47184 & cppMask_un_16_);
	cppVar_47185 = ROM.rd(cppVar_47184);
	cppVar_47186 = (cppVar_47185 >> 3) & cppMask_un_5_;
	cppVar_47187 = (cppVar_47186 << 3) | 0;
	cppVar_47187 = (cppVar_47187 & cppMask_un_8_);
	cppVar_47179 = cppVar_47187;
	} else {
	cppVar_47188 = PC + 1;
	cppVar_47188 = (cppVar_47188 & cppMask_un_16_);
	cppVar_47189 = ROM.rd(cppVar_47188);
	cppVar_47190 = (cppVar_47189 >> 3) & cppMask_un_5_;
	cppVar_47191 = (cppVar_47190 & cppMask_un_5_);
	cppVar_47192 = cppVar_47191 + 32;
	cppVar_47192 = (cppVar_47192 & cppMask_un_8_);
	cppVar_47179 = cppVar_47192;
	}
	cppVar_47194 = (cppVar_47179 == 240);
	if (cppVar_47194) {
	cppVar_47178 = B;
	} else {
	cppVar_47178 = 0;
	}
	cppVar_47161 = cppVar_47178;
	}
	cppVar_47144 = cppVar_47161;
	}
	cppVar_47127 = cppVar_47144;
	}
	cppVar_47110 = cppVar_47127;
	}
	cppVar_47093 = cppVar_47110;
	}
	cppVar_47076 = cppVar_47093;
	}
	cppVar_47059 = cppVar_47076;
	}
	cppVar_47042 = cppVar_47059;
	}
	cppVar_47025 = cppVar_47042;
	}
	cppVar_47008 = cppVar_47025;
	}
	cppVar_46991 = cppVar_47008;
	}
	cppVar_46974 = cppVar_46991;
	}
	cppVar_46957 = cppVar_46974;
	}
	cppVar_46940 = cppVar_46957;
	}
	cppVar_46923 = cppVar_46940;
	}
	cppVar_46906 = cppVar_46923;
	}
	cppVar_46889 = cppVar_46906;
	}
	cppVar_46872 = cppVar_46889;
	}
	cppVar_46855 = cppVar_46872;
	}
	cppVar_46838 = cppVar_46855;
	}
	cppVar_46805 = cppVar_46838;
	}
	cppVar_47196 = cppVar_46804 & cppVar_46805;
	cppVar_47198 = 1;
	cppVar_47199 = PC + 1;
	cppVar_47199 = (cppVar_47199 & cppMask_un_16_);
	cppVar_47200 = ROM.rd(cppVar_47199);
	cppVar_47201 = (cppVar_47200 >> 0) & cppMask_un_3_;
	cppVar_47202 = (cppVar_47201 & cppMask_un_3_);
	cppVar_47203 = cppVar_47198 << static_cast<unsigned>(cppVar_47202);
	cppVar_47203 = (cppVar_47203 & cppMask_un_8_);
	cppVar_47204 = cppVar_47196 | cppVar_47203;
	cppVar_46777 = cppVar_47204;
	} else {
	cppVar_46777 = PSW;
	}
	cppVar_46773 = cppVar_46777;
	} else {
	cppVar_47206 = ROM.rd(PC);
	cppVar_47208 = (cppVar_47206 == 208);
	if (cppVar_47208) {
	cppVar_47211 = PC + 1;
	cppVar_47211 = (cppVar_47211 & cppMask_un_16_);
	cppVar_47212 = ROM.rd(cppVar_47211);
	cppVar_47214 = (cppVar_47212 == 208);
	if (cppVar_47214) {
	cppVar_47215 = IRAM.rd(SP);
	cppVar_47209 = cppVar_47215;
	} else {
	cppVar_47209 = PSW;
	}
	cppVar_47205 = cppVar_47209;
	} else {
	cppVar_47217 = ROM.rd(PC);
	cppVar_47219 = (cppVar_47217 == 245);
	cppVar_47220 = ROM.rd(PC);
	cppVar_47222 = (cppVar_47220 == 197);
	cppVar_47223 = cppVar_47219 || cppVar_47222;
	if (cppVar_47223) {
	cppVar_47226 = PC + 1;
	cppVar_47226 = (cppVar_47226 & cppMask_un_16_);
	cppVar_47227 = ROM.rd(cppVar_47226);
	cppVar_47229 = (cppVar_47227 == 208);
	if (cppVar_47229) {
	cppVar_47224 = ACC;
	} else {
	cppVar_47224 = PSW;
	}
	cppVar_47216 = cppVar_47224;
	} else {
	cppVar_47231 = ROM.rd(PC);
	cppVar_47233 = (cppVar_47231 == 195);
	if (cppVar_47233) {
	cppVar_47235 = (PSW >> 0) & cppMask_un_7_;
	cppVar_47236 = (0 << 7) | cppVar_47235;
	cppVar_47236 = (cppVar_47236 & cppMask_un_8_);
	cppVar_47230 = cppVar_47236;
	} else {
	cppVar_47238 = ROM.rd(PC);
	cppVar_47240 = (cppVar_47238 == 191);
	if (cppVar_47240) {
	cppVar_47243 = (PSW >> 3) & cppMask_un_2_;
	cppVar_47245 = (cppVar_47243 << 3) | 7;
	cppVar_47245 = (cppVar_47245 & cppMask_un_5_);
	cppVar_47246 = (0 << 5) | cppVar_47245;
	cppVar_47246 = (cppVar_47246 & cppMask_un_8_);
	cppVar_47247 = IRAM.rd(cppVar_47246);
	cppVar_47249 = PC + 1;
	cppVar_47249 = (cppVar_47249 & cppMask_un_16_);
	cppVar_47250 = ROM.rd(cppVar_47249);
	cppVar_47251 = cppVar_47247 < cppVar_47250;
	if (cppVar_47251) {
	cppVar_47241 = 1;
	} else {
	cppVar_47241 = 0;
	}
	cppVar_47254 = (PSW >> 0) & cppMask_un_7_;
	cppVar_47255 = (cppVar_47241 << 7) | cppVar_47254;
	cppVar_47255 = (cppVar_47255 & cppMask_un_8_);
	cppVar_47237 = cppVar_47255;
	} else {
	cppVar_47257 = ROM.rd(PC);
	cppVar_47259 = (cppVar_47257 == 190);
	if (cppVar_47259) {
	cppVar_47262 = (PSW >> 3) & cppMask_un_2_;
	cppVar_47264 = (cppVar_47262 << 3) | 6;
	cppVar_47264 = (cppVar_47264 & cppMask_un_5_);
	cppVar_47265 = (0 << 5) | cppVar_47264;
	cppVar_47265 = (cppVar_47265 & cppMask_un_8_);
	cppVar_47266 = IRAM.rd(cppVar_47265);
	cppVar_47268 = PC + 1;
	cppVar_47268 = (cppVar_47268 & cppMask_un_16_);
	cppVar_47269 = ROM.rd(cppVar_47268);
	cppVar_47270 = cppVar_47266 < cppVar_47269;
	if (cppVar_47270) {
	cppVar_47260 = 1;
	} else {
	cppVar_47260 = 0;
	}
	cppVar_47273 = (PSW >> 0) & cppMask_un_7_;
	cppVar_47274 = (cppVar_47260 << 7) | cppVar_47273;
	cppVar_47274 = (cppVar_47274 & cppMask_un_8_);
	cppVar_47256 = cppVar_47274;
	} else {
	cppVar_47276 = ROM.rd(PC);
	cppVar_47278 = (cppVar_47276 == 189);
	if (cppVar_47278) {
	cppVar_47281 = (PSW >> 3) & cppMask_un_2_;
	cppVar_47283 = (cppVar_47281 << 3) | 5;
	cppVar_47283 = (cppVar_47283 & cppMask_un_5_);
	cppVar_47284 = (0 << 5) | cppVar_47283;
	cppVar_47284 = (cppVar_47284 & cppMask_un_8_);
	cppVar_47285 = IRAM.rd(cppVar_47284);
	cppVar_47287 = PC + 1;
	cppVar_47287 = (cppVar_47287 & cppMask_un_16_);
	cppVar_47288 = ROM.rd(cppVar_47287);
	cppVar_47289 = cppVar_47285 < cppVar_47288;
	if (cppVar_47289) {
	cppVar_47279 = 1;
	} else {
	cppVar_47279 = 0;
	}
	cppVar_47292 = (PSW >> 0) & cppMask_un_7_;
	cppVar_47293 = (cppVar_47279 << 7) | cppVar_47292;
	cppVar_47293 = (cppVar_47293 & cppMask_un_8_);
	cppVar_47275 = cppVar_47293;
	} else {
	cppVar_47295 = ROM.rd(PC);
	cppVar_47297 = (cppVar_47295 == 188);
	if (cppVar_47297) {
	cppVar_47300 = (PSW >> 3) & cppMask_un_2_;
	cppVar_47302 = (cppVar_47300 << 3) | 4;
	cppVar_47302 = (cppVar_47302 & cppMask_un_5_);
	cppVar_47303 = (0 << 5) | cppVar_47302;
	cppVar_47303 = (cppVar_47303 & cppMask_un_8_);
	cppVar_47304 = IRAM.rd(cppVar_47303);
	cppVar_47306 = PC + 1;
	cppVar_47306 = (cppVar_47306 & cppMask_un_16_);
	cppVar_47307 = ROM.rd(cppVar_47306);
	cppVar_47308 = cppVar_47304 < cppVar_47307;
	if (cppVar_47308) {
	cppVar_47298 = 1;
	} else {
	cppVar_47298 = 0;
	}
	cppVar_47311 = (PSW >> 0) & cppMask_un_7_;
	cppVar_47312 = (cppVar_47298 << 7) | cppVar_47311;
	cppVar_47312 = (cppVar_47312 & cppMask_un_8_);
	cppVar_47294 = cppVar_47312;
	} else {
	cppVar_47314 = ROM.rd(PC);
	cppVar_47316 = (cppVar_47314 == 187);
	if (cppVar_47316) {
	cppVar_47319 = (PSW >> 3) & cppMask_un_2_;
	cppVar_47321 = (cppVar_47319 << 3) | 3;
	cppVar_47321 = (cppVar_47321 & cppMask_un_5_);
	cppVar_47322 = (0 << 5) | cppVar_47321;
	cppVar_47322 = (cppVar_47322 & cppMask_un_8_);
	cppVar_47323 = IRAM.rd(cppVar_47322);
	cppVar_47325 = PC + 1;
	cppVar_47325 = (cppVar_47325 & cppMask_un_16_);
	cppVar_47326 = ROM.rd(cppVar_47325);
	cppVar_47327 = cppVar_47323 < cppVar_47326;
	if (cppVar_47327) {
	cppVar_47317 = 1;
	} else {
	cppVar_47317 = 0;
	}
	cppVar_47330 = (PSW >> 0) & cppMask_un_7_;
	cppVar_47331 = (cppVar_47317 << 7) | cppVar_47330;
	cppVar_47331 = (cppVar_47331 & cppMask_un_8_);
	cppVar_47313 = cppVar_47331;
	} else {
	cppVar_47333 = ROM.rd(PC);
	cppVar_47335 = (cppVar_47333 == 186);
	if (cppVar_47335) {
	cppVar_47338 = (PSW >> 3) & cppMask_un_2_;
	cppVar_47340 = (cppVar_47338 << 3) | 2;
	cppVar_47340 = (cppVar_47340 & cppMask_un_5_);
	cppVar_47341 = (0 << 5) | cppVar_47340;
	cppVar_47341 = (cppVar_47341 & cppMask_un_8_);
	cppVar_47342 = IRAM.rd(cppVar_47341);
	cppVar_47344 = PC + 1;
	cppVar_47344 = (cppVar_47344 & cppMask_un_16_);
	cppVar_47345 = ROM.rd(cppVar_47344);
	cppVar_47346 = cppVar_47342 < cppVar_47345;
	if (cppVar_47346) {
	cppVar_47336 = 1;
	} else {
	cppVar_47336 = 0;
	}
	cppVar_47349 = (PSW >> 0) & cppMask_un_7_;
	cppVar_47350 = (cppVar_47336 << 7) | cppVar_47349;
	cppVar_47350 = (cppVar_47350 & cppMask_un_8_);
	cppVar_47332 = cppVar_47350;
	} else {
	cppVar_47352 = ROM.rd(PC);
	cppVar_47354 = (cppVar_47352 == 185);
	if (cppVar_47354) {
	cppVar_47357 = (PSW >> 3) & cppMask_un_2_;
	cppVar_47359 = (cppVar_47357 << 3) | 1;
	cppVar_47359 = (cppVar_47359 & cppMask_un_5_);
	cppVar_47360 = (0 << 5) | cppVar_47359;
	cppVar_47360 = (cppVar_47360 & cppMask_un_8_);
	cppVar_47361 = IRAM.rd(cppVar_47360);
	cppVar_47363 = PC + 1;
	cppVar_47363 = (cppVar_47363 & cppMask_un_16_);
	cppVar_47364 = ROM.rd(cppVar_47363);
	cppVar_47365 = cppVar_47361 < cppVar_47364;
	if (cppVar_47365) {
	cppVar_47355 = 1;
	} else {
	cppVar_47355 = 0;
	}
	cppVar_47368 = (PSW >> 0) & cppMask_un_7_;
	cppVar_47369 = (cppVar_47355 << 7) | cppVar_47368;
	cppVar_47369 = (cppVar_47369 & cppMask_un_8_);
	cppVar_47351 = cppVar_47369;
	} else {
	cppVar_47371 = ROM.rd(PC);
	cppVar_47373 = (cppVar_47371 == 184);
	if (cppVar_47373) {
	cppVar_47376 = (PSW >> 3) & cppMask_un_2_;
	cppVar_47378 = (cppVar_47376 << 3) | 0;
	cppVar_47378 = (cppVar_47378 & cppMask_un_5_);
	cppVar_47379 = (0 << 5) | cppVar_47378;
	cppVar_47379 = (cppVar_47379 & cppMask_un_8_);
	cppVar_47380 = IRAM.rd(cppVar_47379);
	cppVar_47382 = PC + 1;
	cppVar_47382 = (cppVar_47382 & cppMask_un_16_);
	cppVar_47383 = ROM.rd(cppVar_47382);
	cppVar_47384 = cppVar_47380 < cppVar_47383;
	if (cppVar_47384) {
	cppVar_47374 = 1;
	} else {
	cppVar_47374 = 0;
	}
	cppVar_47387 = (PSW >> 0) & cppMask_un_7_;
	cppVar_47388 = (cppVar_47374 << 7) | cppVar_47387;
	cppVar_47388 = (cppVar_47388 & cppMask_un_8_);
	cppVar_47370 = cppVar_47388;
	} else {
	cppVar_47390 = ROM.rd(PC);
	cppVar_47392 = (cppVar_47390 == 183);
	if (cppVar_47392) {
	cppVar_47395 = (PSW >> 3) & cppMask_un_2_;
	cppVar_47397 = (cppVar_47395 << 3) | 1;
	cppVar_47397 = (cppVar_47397 & cppMask_un_5_);
	cppVar_47398 = (0 << 5) | cppVar_47397;
	cppVar_47398 = (cppVar_47398 & cppMask_un_8_);
	cppVar_47399 = IRAM.rd(cppVar_47398);
	cppVar_47400 = IRAM.rd(cppVar_47399);
	cppVar_47402 = PC + 1;
	cppVar_47402 = (cppVar_47402 & cppMask_un_16_);
	cppVar_47403 = ROM.rd(cppVar_47402);
	cppVar_47404 = cppVar_47400 < cppVar_47403;
	if (cppVar_47404) {
	cppVar_47393 = 1;
	} else {
	cppVar_47393 = 0;
	}
	cppVar_47407 = (PSW >> 0) & cppMask_un_7_;
	cppVar_47408 = (cppVar_47393 << 7) | cppVar_47407;
	cppVar_47408 = (cppVar_47408 & cppMask_un_8_);
	cppVar_47389 = cppVar_47408;
	} else {
	cppVar_47410 = ROM.rd(PC);
	cppVar_47412 = (cppVar_47410 == 182);
	if (cppVar_47412) {
	cppVar_47415 = (PSW >> 3) & cppMask_un_2_;
	cppVar_47417 = (cppVar_47415 << 3) | 0;
	cppVar_47417 = (cppVar_47417 & cppMask_un_5_);
	cppVar_47418 = (0 << 5) | cppVar_47417;
	cppVar_47418 = (cppVar_47418 & cppMask_un_8_);
	cppVar_47419 = IRAM.rd(cppVar_47418);
	cppVar_47420 = IRAM.rd(cppVar_47419);
	cppVar_47422 = PC + 1;
	cppVar_47422 = (cppVar_47422 & cppMask_un_16_);
	cppVar_47423 = ROM.rd(cppVar_47422);
	cppVar_47424 = cppVar_47420 < cppVar_47423;
	if (cppVar_47424) {
	cppVar_47413 = 1;
	} else {
	cppVar_47413 = 0;
	}
	cppVar_47427 = (PSW >> 0) & cppMask_un_7_;
	cppVar_47428 = (cppVar_47413 << 7) | cppVar_47427;
	cppVar_47428 = (cppVar_47428 & cppMask_un_8_);
	cppVar_47409 = cppVar_47428;
	} else {
	cppVar_47430 = ROM.rd(PC);
	cppVar_47432 = (cppVar_47430 == 181);
	if (cppVar_47432) {
	cppVar_47436 = PC + 1;
	cppVar_47436 = (cppVar_47436 & cppMask_un_16_);
	cppVar_47437 = ROM.rd(cppVar_47436);
	cppVar_47438 = (cppVar_47437 >> 7) & cppMask_un_1_;
	cppVar_47440 = (cppVar_47438 == 0);
	if (cppVar_47440) {
	cppVar_47441 = PC + 1;
	cppVar_47441 = (cppVar_47441 & cppMask_un_16_);
	cppVar_47442 = ROM.rd(cppVar_47441);
	cppVar_47443 = IRAM.rd(cppVar_47442);
	cppVar_47434 = cppVar_47443;
	} else {
	cppVar_47445 = PC + 1;
	cppVar_47445 = (cppVar_47445 & cppMask_un_16_);
	cppVar_47446 = ROM.rd(cppVar_47445);
	cppVar_47448 = (cppVar_47446 == 128);
	if (cppVar_47448) {
	cppVar_47444 = P0;
	} else {
	cppVar_47450 = PC + 1;
	cppVar_47450 = (cppVar_47450 & cppMask_un_16_);
	cppVar_47451 = ROM.rd(cppVar_47450);
	cppVar_47453 = (cppVar_47451 == 129);
	if (cppVar_47453) {
	cppVar_47449 = SP;
	} else {
	cppVar_47455 = PC + 1;
	cppVar_47455 = (cppVar_47455 & cppMask_un_16_);
	cppVar_47456 = ROM.rd(cppVar_47455);
	cppVar_47458 = (cppVar_47456 == 130);
	if (cppVar_47458) {
	cppVar_47454 = DPL;
	} else {
	cppVar_47460 = PC + 1;
	cppVar_47460 = (cppVar_47460 & cppMask_un_16_);
	cppVar_47461 = ROM.rd(cppVar_47460);
	cppVar_47463 = (cppVar_47461 == 131);
	if (cppVar_47463) {
	cppVar_47459 = DPH;
	} else {
	cppVar_47465 = PC + 1;
	cppVar_47465 = (cppVar_47465 & cppMask_un_16_);
	cppVar_47466 = ROM.rd(cppVar_47465);
	cppVar_47468 = (cppVar_47466 == 135);
	if (cppVar_47468) {
	cppVar_47464 = PCON;
	} else {
	cppVar_47470 = PC + 1;
	cppVar_47470 = (cppVar_47470 & cppMask_un_16_);
	cppVar_47471 = ROM.rd(cppVar_47470);
	cppVar_47473 = (cppVar_47471 == 136);
	if (cppVar_47473) {
	cppVar_47469 = TCON;
	} else {
	cppVar_47475 = PC + 1;
	cppVar_47475 = (cppVar_47475 & cppMask_un_16_);
	cppVar_47476 = ROM.rd(cppVar_47475);
	cppVar_47478 = (cppVar_47476 == 137);
	if (cppVar_47478) {
	cppVar_47474 = TMOD;
	} else {
	cppVar_47480 = PC + 1;
	cppVar_47480 = (cppVar_47480 & cppMask_un_16_);
	cppVar_47481 = ROM.rd(cppVar_47480);
	cppVar_47483 = (cppVar_47481 == 138);
	if (cppVar_47483) {
	cppVar_47479 = TL0;
	} else {
	cppVar_47485 = PC + 1;
	cppVar_47485 = (cppVar_47485 & cppMask_un_16_);
	cppVar_47486 = ROM.rd(cppVar_47485);
	cppVar_47488 = (cppVar_47486 == 140);
	if (cppVar_47488) {
	cppVar_47484 = TH0;
	} else {
	cppVar_47490 = PC + 1;
	cppVar_47490 = (cppVar_47490 & cppMask_un_16_);
	cppVar_47491 = ROM.rd(cppVar_47490);
	cppVar_47493 = (cppVar_47491 == 139);
	if (cppVar_47493) {
	cppVar_47489 = TL1;
	} else {
	cppVar_47495 = PC + 1;
	cppVar_47495 = (cppVar_47495 & cppMask_un_16_);
	cppVar_47496 = ROM.rd(cppVar_47495);
	cppVar_47498 = (cppVar_47496 == 141);
	if (cppVar_47498) {
	cppVar_47494 = TH1;
	} else {
	cppVar_47500 = PC + 1;
	cppVar_47500 = (cppVar_47500 & cppMask_un_16_);
	cppVar_47501 = ROM.rd(cppVar_47500);
	cppVar_47503 = (cppVar_47501 == 144);
	if (cppVar_47503) {
	cppVar_47499 = P1;
	} else {
	cppVar_47505 = PC + 1;
	cppVar_47505 = (cppVar_47505 & cppMask_un_16_);
	cppVar_47506 = ROM.rd(cppVar_47505);
	cppVar_47508 = (cppVar_47506 == 152);
	if (cppVar_47508) {
	cppVar_47504 = SCON;
	} else {
	cppVar_47510 = PC + 1;
	cppVar_47510 = (cppVar_47510 & cppMask_un_16_);
	cppVar_47511 = ROM.rd(cppVar_47510);
	cppVar_47513 = (cppVar_47511 == 153);
	if (cppVar_47513) {
	cppVar_47509 = SBUF;
	} else {
	cppVar_47515 = PC + 1;
	cppVar_47515 = (cppVar_47515 & cppMask_un_16_);
	cppVar_47516 = ROM.rd(cppVar_47515);
	cppVar_47518 = (cppVar_47516 == 160);
	if (cppVar_47518) {
	cppVar_47514 = P2;
	} else {
	cppVar_47520 = PC + 1;
	cppVar_47520 = (cppVar_47520 & cppMask_un_16_);
	cppVar_47521 = ROM.rd(cppVar_47520);
	cppVar_47523 = (cppVar_47521 == 168);
	if (cppVar_47523) {
	cppVar_47519 = IE;
	} else {
	cppVar_47525 = PC + 1;
	cppVar_47525 = (cppVar_47525 & cppMask_un_16_);
	cppVar_47526 = ROM.rd(cppVar_47525);
	cppVar_47528 = (cppVar_47526 == 176);
	if (cppVar_47528) {
	cppVar_47524 = P3;
	} else {
	cppVar_47530 = PC + 1;
	cppVar_47530 = (cppVar_47530 & cppMask_un_16_);
	cppVar_47531 = ROM.rd(cppVar_47530);
	cppVar_47533 = (cppVar_47531 == 184);
	if (cppVar_47533) {
	cppVar_47529 = IP;
	} else {
	cppVar_47535 = PC + 1;
	cppVar_47535 = (cppVar_47535 & cppMask_un_16_);
	cppVar_47536 = ROM.rd(cppVar_47535);
	cppVar_47538 = (cppVar_47536 == 208);
	if (cppVar_47538) {
	cppVar_47534 = PSW;
	} else {
	cppVar_47540 = PC + 1;
	cppVar_47540 = (cppVar_47540 & cppMask_un_16_);
	cppVar_47541 = ROM.rd(cppVar_47540);
	cppVar_47543 = (cppVar_47541 == 224);
	if (cppVar_47543) {
	cppVar_47539 = ACC;
	} else {
	cppVar_47545 = PC + 1;
	cppVar_47545 = (cppVar_47545 & cppMask_un_16_);
	cppVar_47546 = ROM.rd(cppVar_47545);
	cppVar_47548 = (cppVar_47546 == 240);
	if (cppVar_47548) {
	cppVar_47544 = B;
	} else {
	cppVar_47544 = 0;
	}
	cppVar_47539 = cppVar_47544;
	}
	cppVar_47534 = cppVar_47539;
	}
	cppVar_47529 = cppVar_47534;
	}
	cppVar_47524 = cppVar_47529;
	}
	cppVar_47519 = cppVar_47524;
	}
	cppVar_47514 = cppVar_47519;
	}
	cppVar_47509 = cppVar_47514;
	}
	cppVar_47504 = cppVar_47509;
	}
	cppVar_47499 = cppVar_47504;
	}
	cppVar_47494 = cppVar_47499;
	}
	cppVar_47489 = cppVar_47494;
	}
	cppVar_47484 = cppVar_47489;
	}
	cppVar_47479 = cppVar_47484;
	}
	cppVar_47474 = cppVar_47479;
	}
	cppVar_47469 = cppVar_47474;
	}
	cppVar_47464 = cppVar_47469;
	}
	cppVar_47459 = cppVar_47464;
	}
	cppVar_47454 = cppVar_47459;
	}
	cppVar_47449 = cppVar_47454;
	}
	cppVar_47444 = cppVar_47449;
	}
	cppVar_47434 = cppVar_47444;
	}
	cppVar_47550 = ACC < cppVar_47434;
	if (cppVar_47550) {
	cppVar_47433 = 1;
	} else {
	cppVar_47433 = 0;
	}
	cppVar_47553 = (PSW >> 0) & cppMask_un_7_;
	cppVar_47554 = (cppVar_47433 << 7) | cppVar_47553;
	cppVar_47554 = (cppVar_47554 & cppMask_un_8_);
	cppVar_47429 = cppVar_47554;
	} else {
	cppVar_47556 = ROM.rd(PC);
	cppVar_47558 = (cppVar_47556 == 180);
	if (cppVar_47558) {
	cppVar_47561 = PC + 1;
	cppVar_47561 = (cppVar_47561 & cppMask_un_16_);
	cppVar_47562 = ROM.rd(cppVar_47561);
	cppVar_47563 = ACC < cppVar_47562;
	if (cppVar_47563) {
	cppVar_47559 = 1;
	} else {
	cppVar_47559 = 0;
	}
	cppVar_47566 = (PSW >> 0) & cppMask_un_7_;
	cppVar_47567 = (cppVar_47559 << 7) | cppVar_47566;
	cppVar_47567 = (cppVar_47567 & cppMask_un_8_);
	cppVar_47555 = cppVar_47567;
	} else {
	cppVar_47569 = ROM.rd(PC);
	cppVar_47571 = (cppVar_47569 == 179);
	if (cppVar_47571) {
	cppVar_47572 = (PSW >> 7) & cppMask_un_1_;
	cppVar_47573 = ~cppVar_47572;
	cppVar_47574 = (PSW >> 0) & cppMask_un_7_;
	cppVar_47575 = (cppVar_47573 << 7) | cppVar_47574;
	cppVar_47575 = (cppVar_47575 & cppMask_un_8_);
	cppVar_47568 = cppVar_47575;
	} else {
	cppVar_47577 = ROM.rd(PC);
	cppVar_47579 = (cppVar_47577 == 178);
	if (cppVar_47579) {
	cppVar_47583 = PC + 1;
	cppVar_47583 = (cppVar_47583 & cppMask_un_16_);
	cppVar_47584 = ROM.rd(cppVar_47583);
	cppVar_47585 = (cppVar_47584 >> 7) & cppMask_un_1_;
	cppVar_47587 = (cppVar_47585 == 1);
	if (cppVar_47587) {
	cppVar_47588 = PC + 1;
	cppVar_47588 = (cppVar_47588 & cppMask_un_16_);
	cppVar_47589 = ROM.rd(cppVar_47588);
	cppVar_47590 = (cppVar_47589 >> 3) & cppMask_un_5_;
	cppVar_47592 = (cppVar_47590 << 3) | 0;
	cppVar_47592 = (cppVar_47592 & cppMask_un_8_);
	cppVar_47581 = cppVar_47592;
	} else {
	cppVar_47593 = PC + 1;
	cppVar_47593 = (cppVar_47593 & cppMask_un_16_);
	cppVar_47594 = ROM.rd(cppVar_47593);
	cppVar_47595 = (cppVar_47594 >> 3) & cppMask_un_5_;
	cppVar_47596 = (cppVar_47595 & cppMask_un_5_);
	cppVar_47598 = cppVar_47596 + 32;
	cppVar_47598 = (cppVar_47598 & cppMask_un_8_);
	cppVar_47581 = cppVar_47598;
	}
	cppVar_47600 = (cppVar_47581 == 208);
	if (cppVar_47600) {
	cppVar_47602 = PC + 1;
	cppVar_47602 = (cppVar_47602 & cppMask_un_16_);
	cppVar_47603 = ROM.rd(cppVar_47602);
	cppVar_47604 = (cppVar_47603 >> 0) & cppMask_un_3_;
	cppVar_47605 = (cppVar_47604 & cppMask_un_3_);
	cppVar_47606 = 1 << static_cast<unsigned>(cppVar_47605);
	cppVar_47606 = (cppVar_47606 & cppMask_un_8_);
	cppVar_47607 = ~cppVar_47606;
	cppVar_47610 = PC + 1;
	cppVar_47610 = (cppVar_47610 & cppMask_un_16_);
	cppVar_47611 = ROM.rd(cppVar_47610);
	cppVar_47612 = (cppVar_47611 >> 7) & cppMask_un_1_;
	cppVar_47613 = (cppVar_47612 == 1);
	if (cppVar_47613) {
	cppVar_47614 = PC + 1;
	cppVar_47614 = (cppVar_47614 & cppMask_un_16_);
	cppVar_47615 = ROM.rd(cppVar_47614);
	cppVar_47616 = (cppVar_47615 >> 3) & cppMask_un_5_;
	cppVar_47617 = (cppVar_47616 << 3) | 0;
	cppVar_47617 = (cppVar_47617 & cppMask_un_8_);
	cppVar_47609 = cppVar_47617;
	} else {
	cppVar_47618 = PC + 1;
	cppVar_47618 = (cppVar_47618 & cppMask_un_16_);
	cppVar_47619 = ROM.rd(cppVar_47618);
	cppVar_47620 = (cppVar_47619 >> 3) & cppMask_un_5_;
	cppVar_47621 = (cppVar_47620 & cppMask_un_5_);
	cppVar_47622 = cppVar_47621 + 32;
	cppVar_47622 = (cppVar_47622 & cppMask_un_8_);
	cppVar_47609 = cppVar_47622;
	}
	cppVar_47623 = (cppVar_47609 >> 7) & cppMask_un_1_;
	cppVar_47625 = (cppVar_47623 == 0);
	if (cppVar_47625) {
	cppVar_47627 = PC + 1;
	cppVar_47627 = (cppVar_47627 & cppMask_un_16_);
	cppVar_47628 = ROM.rd(cppVar_47627);
	cppVar_47629 = (cppVar_47628 >> 7) & cppMask_un_1_;
	cppVar_47630 = (cppVar_47629 == 1);
	if (cppVar_47630) {
	cppVar_47631 = PC + 1;
	cppVar_47631 = (cppVar_47631 & cppMask_un_16_);
	cppVar_47632 = ROM.rd(cppVar_47631);
	cppVar_47633 = (cppVar_47632 >> 3) & cppMask_un_5_;
	cppVar_47634 = (cppVar_47633 << 3) | 0;
	cppVar_47634 = (cppVar_47634 & cppMask_un_8_);
	cppVar_47626 = cppVar_47634;
	} else {
	cppVar_47635 = PC + 1;
	cppVar_47635 = (cppVar_47635 & cppMask_un_16_);
	cppVar_47636 = ROM.rd(cppVar_47635);
	cppVar_47637 = (cppVar_47636 >> 3) & cppMask_un_5_;
	cppVar_47638 = (cppVar_47637 & cppMask_un_5_);
	cppVar_47639 = cppVar_47638 + 32;
	cppVar_47639 = (cppVar_47639 & cppMask_un_8_);
	cppVar_47626 = cppVar_47639;
	}
	cppVar_47640 = IRAM.rd(cppVar_47626);
	cppVar_47608 = cppVar_47640;
	} else {
	cppVar_47643 = PC + 1;
	cppVar_47643 = (cppVar_47643 & cppMask_un_16_);
	cppVar_47644 = ROM.rd(cppVar_47643);
	cppVar_47645 = (cppVar_47644 >> 7) & cppMask_un_1_;
	cppVar_47646 = (cppVar_47645 == 1);
	if (cppVar_47646) {
	cppVar_47647 = PC + 1;
	cppVar_47647 = (cppVar_47647 & cppMask_un_16_);
	cppVar_47648 = ROM.rd(cppVar_47647);
	cppVar_47649 = (cppVar_47648 >> 3) & cppMask_un_5_;
	cppVar_47650 = (cppVar_47649 << 3) | 0;
	cppVar_47650 = (cppVar_47650 & cppMask_un_8_);
	cppVar_47642 = cppVar_47650;
	} else {
	cppVar_47651 = PC + 1;
	cppVar_47651 = (cppVar_47651 & cppMask_un_16_);
	cppVar_47652 = ROM.rd(cppVar_47651);
	cppVar_47653 = (cppVar_47652 >> 3) & cppMask_un_5_;
	cppVar_47654 = (cppVar_47653 & cppMask_un_5_);
	cppVar_47655 = cppVar_47654 + 32;
	cppVar_47655 = (cppVar_47655 & cppMask_un_8_);
	cppVar_47642 = cppVar_47655;
	}
	cppVar_47657 = (cppVar_47642 == 128);
	if (cppVar_47657) {
	cppVar_47641 = P0;
	} else {
	cppVar_47660 = PC + 1;
	cppVar_47660 = (cppVar_47660 & cppMask_un_16_);
	cppVar_47661 = ROM.rd(cppVar_47660);
	cppVar_47662 = (cppVar_47661 >> 7) & cppMask_un_1_;
	cppVar_47663 = (cppVar_47662 == 1);
	if (cppVar_47663) {
	cppVar_47664 = PC + 1;
	cppVar_47664 = (cppVar_47664 & cppMask_un_16_);
	cppVar_47665 = ROM.rd(cppVar_47664);
	cppVar_47666 = (cppVar_47665 >> 3) & cppMask_un_5_;
	cppVar_47667 = (cppVar_47666 << 3) | 0;
	cppVar_47667 = (cppVar_47667 & cppMask_un_8_);
	cppVar_47659 = cppVar_47667;
	} else {
	cppVar_47668 = PC + 1;
	cppVar_47668 = (cppVar_47668 & cppMask_un_16_);
	cppVar_47669 = ROM.rd(cppVar_47668);
	cppVar_47670 = (cppVar_47669 >> 3) & cppMask_un_5_;
	cppVar_47671 = (cppVar_47670 & cppMask_un_5_);
	cppVar_47672 = cppVar_47671 + 32;
	cppVar_47672 = (cppVar_47672 & cppMask_un_8_);
	cppVar_47659 = cppVar_47672;
	}
	cppVar_47674 = (cppVar_47659 == 129);
	if (cppVar_47674) {
	cppVar_47658 = SP;
	} else {
	cppVar_47677 = PC + 1;
	cppVar_47677 = (cppVar_47677 & cppMask_un_16_);
	cppVar_47678 = ROM.rd(cppVar_47677);
	cppVar_47679 = (cppVar_47678 >> 7) & cppMask_un_1_;
	cppVar_47680 = (cppVar_47679 == 1);
	if (cppVar_47680) {
	cppVar_47681 = PC + 1;
	cppVar_47681 = (cppVar_47681 & cppMask_un_16_);
	cppVar_47682 = ROM.rd(cppVar_47681);
	cppVar_47683 = (cppVar_47682 >> 3) & cppMask_un_5_;
	cppVar_47684 = (cppVar_47683 << 3) | 0;
	cppVar_47684 = (cppVar_47684 & cppMask_un_8_);
	cppVar_47676 = cppVar_47684;
	} else {
	cppVar_47685 = PC + 1;
	cppVar_47685 = (cppVar_47685 & cppMask_un_16_);
	cppVar_47686 = ROM.rd(cppVar_47685);
	cppVar_47687 = (cppVar_47686 >> 3) & cppMask_un_5_;
	cppVar_47688 = (cppVar_47687 & cppMask_un_5_);
	cppVar_47689 = cppVar_47688 + 32;
	cppVar_47689 = (cppVar_47689 & cppMask_un_8_);
	cppVar_47676 = cppVar_47689;
	}
	cppVar_47691 = (cppVar_47676 == 130);
	if (cppVar_47691) {
	cppVar_47675 = DPL;
	} else {
	cppVar_47694 = PC + 1;
	cppVar_47694 = (cppVar_47694 & cppMask_un_16_);
	cppVar_47695 = ROM.rd(cppVar_47694);
	cppVar_47696 = (cppVar_47695 >> 7) & cppMask_un_1_;
	cppVar_47697 = (cppVar_47696 == 1);
	if (cppVar_47697) {
	cppVar_47698 = PC + 1;
	cppVar_47698 = (cppVar_47698 & cppMask_un_16_);
	cppVar_47699 = ROM.rd(cppVar_47698);
	cppVar_47700 = (cppVar_47699 >> 3) & cppMask_un_5_;
	cppVar_47701 = (cppVar_47700 << 3) | 0;
	cppVar_47701 = (cppVar_47701 & cppMask_un_8_);
	cppVar_47693 = cppVar_47701;
	} else {
	cppVar_47702 = PC + 1;
	cppVar_47702 = (cppVar_47702 & cppMask_un_16_);
	cppVar_47703 = ROM.rd(cppVar_47702);
	cppVar_47704 = (cppVar_47703 >> 3) & cppMask_un_5_;
	cppVar_47705 = (cppVar_47704 & cppMask_un_5_);
	cppVar_47706 = cppVar_47705 + 32;
	cppVar_47706 = (cppVar_47706 & cppMask_un_8_);
	cppVar_47693 = cppVar_47706;
	}
	cppVar_47708 = (cppVar_47693 == 131);
	if (cppVar_47708) {
	cppVar_47692 = DPH;
	} else {
	cppVar_47711 = PC + 1;
	cppVar_47711 = (cppVar_47711 & cppMask_un_16_);
	cppVar_47712 = ROM.rd(cppVar_47711);
	cppVar_47713 = (cppVar_47712 >> 7) & cppMask_un_1_;
	cppVar_47714 = (cppVar_47713 == 1);
	if (cppVar_47714) {
	cppVar_47715 = PC + 1;
	cppVar_47715 = (cppVar_47715 & cppMask_un_16_);
	cppVar_47716 = ROM.rd(cppVar_47715);
	cppVar_47717 = (cppVar_47716 >> 3) & cppMask_un_5_;
	cppVar_47718 = (cppVar_47717 << 3) | 0;
	cppVar_47718 = (cppVar_47718 & cppMask_un_8_);
	cppVar_47710 = cppVar_47718;
	} else {
	cppVar_47719 = PC + 1;
	cppVar_47719 = (cppVar_47719 & cppMask_un_16_);
	cppVar_47720 = ROM.rd(cppVar_47719);
	cppVar_47721 = (cppVar_47720 >> 3) & cppMask_un_5_;
	cppVar_47722 = (cppVar_47721 & cppMask_un_5_);
	cppVar_47723 = cppVar_47722 + 32;
	cppVar_47723 = (cppVar_47723 & cppMask_un_8_);
	cppVar_47710 = cppVar_47723;
	}
	cppVar_47725 = (cppVar_47710 == 135);
	if (cppVar_47725) {
	cppVar_47709 = PCON;
	} else {
	cppVar_47728 = PC + 1;
	cppVar_47728 = (cppVar_47728 & cppMask_un_16_);
	cppVar_47729 = ROM.rd(cppVar_47728);
	cppVar_47730 = (cppVar_47729 >> 7) & cppMask_un_1_;
	cppVar_47731 = (cppVar_47730 == 1);
	if (cppVar_47731) {
	cppVar_47732 = PC + 1;
	cppVar_47732 = (cppVar_47732 & cppMask_un_16_);
	cppVar_47733 = ROM.rd(cppVar_47732);
	cppVar_47734 = (cppVar_47733 >> 3) & cppMask_un_5_;
	cppVar_47735 = (cppVar_47734 << 3) | 0;
	cppVar_47735 = (cppVar_47735 & cppMask_un_8_);
	cppVar_47727 = cppVar_47735;
	} else {
	cppVar_47736 = PC + 1;
	cppVar_47736 = (cppVar_47736 & cppMask_un_16_);
	cppVar_47737 = ROM.rd(cppVar_47736);
	cppVar_47738 = (cppVar_47737 >> 3) & cppMask_un_5_;
	cppVar_47739 = (cppVar_47738 & cppMask_un_5_);
	cppVar_47740 = cppVar_47739 + 32;
	cppVar_47740 = (cppVar_47740 & cppMask_un_8_);
	cppVar_47727 = cppVar_47740;
	}
	cppVar_47742 = (cppVar_47727 == 136);
	if (cppVar_47742) {
	cppVar_47726 = TCON;
	} else {
	cppVar_47745 = PC + 1;
	cppVar_47745 = (cppVar_47745 & cppMask_un_16_);
	cppVar_47746 = ROM.rd(cppVar_47745);
	cppVar_47747 = (cppVar_47746 >> 7) & cppMask_un_1_;
	cppVar_47748 = (cppVar_47747 == 1);
	if (cppVar_47748) {
	cppVar_47749 = PC + 1;
	cppVar_47749 = (cppVar_47749 & cppMask_un_16_);
	cppVar_47750 = ROM.rd(cppVar_47749);
	cppVar_47751 = (cppVar_47750 >> 3) & cppMask_un_5_;
	cppVar_47752 = (cppVar_47751 << 3) | 0;
	cppVar_47752 = (cppVar_47752 & cppMask_un_8_);
	cppVar_47744 = cppVar_47752;
	} else {
	cppVar_47753 = PC + 1;
	cppVar_47753 = (cppVar_47753 & cppMask_un_16_);
	cppVar_47754 = ROM.rd(cppVar_47753);
	cppVar_47755 = (cppVar_47754 >> 3) & cppMask_un_5_;
	cppVar_47756 = (cppVar_47755 & cppMask_un_5_);
	cppVar_47757 = cppVar_47756 + 32;
	cppVar_47757 = (cppVar_47757 & cppMask_un_8_);
	cppVar_47744 = cppVar_47757;
	}
	cppVar_47759 = (cppVar_47744 == 137);
	if (cppVar_47759) {
	cppVar_47743 = TMOD;
	} else {
	cppVar_47762 = PC + 1;
	cppVar_47762 = (cppVar_47762 & cppMask_un_16_);
	cppVar_47763 = ROM.rd(cppVar_47762);
	cppVar_47764 = (cppVar_47763 >> 7) & cppMask_un_1_;
	cppVar_47765 = (cppVar_47764 == 1);
	if (cppVar_47765) {
	cppVar_47766 = PC + 1;
	cppVar_47766 = (cppVar_47766 & cppMask_un_16_);
	cppVar_47767 = ROM.rd(cppVar_47766);
	cppVar_47768 = (cppVar_47767 >> 3) & cppMask_un_5_;
	cppVar_47769 = (cppVar_47768 << 3) | 0;
	cppVar_47769 = (cppVar_47769 & cppMask_un_8_);
	cppVar_47761 = cppVar_47769;
	} else {
	cppVar_47770 = PC + 1;
	cppVar_47770 = (cppVar_47770 & cppMask_un_16_);
	cppVar_47771 = ROM.rd(cppVar_47770);
	cppVar_47772 = (cppVar_47771 >> 3) & cppMask_un_5_;
	cppVar_47773 = (cppVar_47772 & cppMask_un_5_);
	cppVar_47774 = cppVar_47773 + 32;
	cppVar_47774 = (cppVar_47774 & cppMask_un_8_);
	cppVar_47761 = cppVar_47774;
	}
	cppVar_47776 = (cppVar_47761 == 138);
	if (cppVar_47776) {
	cppVar_47760 = TL0;
	} else {
	cppVar_47779 = PC + 1;
	cppVar_47779 = (cppVar_47779 & cppMask_un_16_);
	cppVar_47780 = ROM.rd(cppVar_47779);
	cppVar_47781 = (cppVar_47780 >> 7) & cppMask_un_1_;
	cppVar_47782 = (cppVar_47781 == 1);
	if (cppVar_47782) {
	cppVar_47783 = PC + 1;
	cppVar_47783 = (cppVar_47783 & cppMask_un_16_);
	cppVar_47784 = ROM.rd(cppVar_47783);
	cppVar_47785 = (cppVar_47784 >> 3) & cppMask_un_5_;
	cppVar_47786 = (cppVar_47785 << 3) | 0;
	cppVar_47786 = (cppVar_47786 & cppMask_un_8_);
	cppVar_47778 = cppVar_47786;
	} else {
	cppVar_47787 = PC + 1;
	cppVar_47787 = (cppVar_47787 & cppMask_un_16_);
	cppVar_47788 = ROM.rd(cppVar_47787);
	cppVar_47789 = (cppVar_47788 >> 3) & cppMask_un_5_;
	cppVar_47790 = (cppVar_47789 & cppMask_un_5_);
	cppVar_47791 = cppVar_47790 + 32;
	cppVar_47791 = (cppVar_47791 & cppMask_un_8_);
	cppVar_47778 = cppVar_47791;
	}
	cppVar_47793 = (cppVar_47778 == 140);
	if (cppVar_47793) {
	cppVar_47777 = TH0;
	} else {
	cppVar_47796 = PC + 1;
	cppVar_47796 = (cppVar_47796 & cppMask_un_16_);
	cppVar_47797 = ROM.rd(cppVar_47796);
	cppVar_47798 = (cppVar_47797 >> 7) & cppMask_un_1_;
	cppVar_47799 = (cppVar_47798 == 1);
	if (cppVar_47799) {
	cppVar_47800 = PC + 1;
	cppVar_47800 = (cppVar_47800 & cppMask_un_16_);
	cppVar_47801 = ROM.rd(cppVar_47800);
	cppVar_47802 = (cppVar_47801 >> 3) & cppMask_un_5_;
	cppVar_47803 = (cppVar_47802 << 3) | 0;
	cppVar_47803 = (cppVar_47803 & cppMask_un_8_);
	cppVar_47795 = cppVar_47803;
	} else {
	cppVar_47804 = PC + 1;
	cppVar_47804 = (cppVar_47804 & cppMask_un_16_);
	cppVar_47805 = ROM.rd(cppVar_47804);
	cppVar_47806 = (cppVar_47805 >> 3) & cppMask_un_5_;
	cppVar_47807 = (cppVar_47806 & cppMask_un_5_);
	cppVar_47808 = cppVar_47807 + 32;
	cppVar_47808 = (cppVar_47808 & cppMask_un_8_);
	cppVar_47795 = cppVar_47808;
	}
	cppVar_47810 = (cppVar_47795 == 139);
	if (cppVar_47810) {
	cppVar_47794 = TL1;
	} else {
	cppVar_47813 = PC + 1;
	cppVar_47813 = (cppVar_47813 & cppMask_un_16_);
	cppVar_47814 = ROM.rd(cppVar_47813);
	cppVar_47815 = (cppVar_47814 >> 7) & cppMask_un_1_;
	cppVar_47816 = (cppVar_47815 == 1);
	if (cppVar_47816) {
	cppVar_47817 = PC + 1;
	cppVar_47817 = (cppVar_47817 & cppMask_un_16_);
	cppVar_47818 = ROM.rd(cppVar_47817);
	cppVar_47819 = (cppVar_47818 >> 3) & cppMask_un_5_;
	cppVar_47820 = (cppVar_47819 << 3) | 0;
	cppVar_47820 = (cppVar_47820 & cppMask_un_8_);
	cppVar_47812 = cppVar_47820;
	} else {
	cppVar_47821 = PC + 1;
	cppVar_47821 = (cppVar_47821 & cppMask_un_16_);
	cppVar_47822 = ROM.rd(cppVar_47821);
	cppVar_47823 = (cppVar_47822 >> 3) & cppMask_un_5_;
	cppVar_47824 = (cppVar_47823 & cppMask_un_5_);
	cppVar_47825 = cppVar_47824 + 32;
	cppVar_47825 = (cppVar_47825 & cppMask_un_8_);
	cppVar_47812 = cppVar_47825;
	}
	cppVar_47827 = (cppVar_47812 == 141);
	if (cppVar_47827) {
	cppVar_47811 = TH1;
	} else {
	cppVar_47830 = PC + 1;
	cppVar_47830 = (cppVar_47830 & cppMask_un_16_);
	cppVar_47831 = ROM.rd(cppVar_47830);
	cppVar_47832 = (cppVar_47831 >> 7) & cppMask_un_1_;
	cppVar_47833 = (cppVar_47832 == 1);
	if (cppVar_47833) {
	cppVar_47834 = PC + 1;
	cppVar_47834 = (cppVar_47834 & cppMask_un_16_);
	cppVar_47835 = ROM.rd(cppVar_47834);
	cppVar_47836 = (cppVar_47835 >> 3) & cppMask_un_5_;
	cppVar_47837 = (cppVar_47836 << 3) | 0;
	cppVar_47837 = (cppVar_47837 & cppMask_un_8_);
	cppVar_47829 = cppVar_47837;
	} else {
	cppVar_47838 = PC + 1;
	cppVar_47838 = (cppVar_47838 & cppMask_un_16_);
	cppVar_47839 = ROM.rd(cppVar_47838);
	cppVar_47840 = (cppVar_47839 >> 3) & cppMask_un_5_;
	cppVar_47841 = (cppVar_47840 & cppMask_un_5_);
	cppVar_47842 = cppVar_47841 + 32;
	cppVar_47842 = (cppVar_47842 & cppMask_un_8_);
	cppVar_47829 = cppVar_47842;
	}
	cppVar_47844 = (cppVar_47829 == 144);
	if (cppVar_47844) {
	cppVar_47828 = P1;
	} else {
	cppVar_47847 = PC + 1;
	cppVar_47847 = (cppVar_47847 & cppMask_un_16_);
	cppVar_47848 = ROM.rd(cppVar_47847);
	cppVar_47849 = (cppVar_47848 >> 7) & cppMask_un_1_;
	cppVar_47850 = (cppVar_47849 == 1);
	if (cppVar_47850) {
	cppVar_47851 = PC + 1;
	cppVar_47851 = (cppVar_47851 & cppMask_un_16_);
	cppVar_47852 = ROM.rd(cppVar_47851);
	cppVar_47853 = (cppVar_47852 >> 3) & cppMask_un_5_;
	cppVar_47854 = (cppVar_47853 << 3) | 0;
	cppVar_47854 = (cppVar_47854 & cppMask_un_8_);
	cppVar_47846 = cppVar_47854;
	} else {
	cppVar_47855 = PC + 1;
	cppVar_47855 = (cppVar_47855 & cppMask_un_16_);
	cppVar_47856 = ROM.rd(cppVar_47855);
	cppVar_47857 = (cppVar_47856 >> 3) & cppMask_un_5_;
	cppVar_47858 = (cppVar_47857 & cppMask_un_5_);
	cppVar_47859 = cppVar_47858 + 32;
	cppVar_47859 = (cppVar_47859 & cppMask_un_8_);
	cppVar_47846 = cppVar_47859;
	}
	cppVar_47861 = (cppVar_47846 == 152);
	if (cppVar_47861) {
	cppVar_47845 = SCON;
	} else {
	cppVar_47864 = PC + 1;
	cppVar_47864 = (cppVar_47864 & cppMask_un_16_);
	cppVar_47865 = ROM.rd(cppVar_47864);
	cppVar_47866 = (cppVar_47865 >> 7) & cppMask_un_1_;
	cppVar_47867 = (cppVar_47866 == 1);
	if (cppVar_47867) {
	cppVar_47868 = PC + 1;
	cppVar_47868 = (cppVar_47868 & cppMask_un_16_);
	cppVar_47869 = ROM.rd(cppVar_47868);
	cppVar_47870 = (cppVar_47869 >> 3) & cppMask_un_5_;
	cppVar_47871 = (cppVar_47870 << 3) | 0;
	cppVar_47871 = (cppVar_47871 & cppMask_un_8_);
	cppVar_47863 = cppVar_47871;
	} else {
	cppVar_47872 = PC + 1;
	cppVar_47872 = (cppVar_47872 & cppMask_un_16_);
	cppVar_47873 = ROM.rd(cppVar_47872);
	cppVar_47874 = (cppVar_47873 >> 3) & cppMask_un_5_;
	cppVar_47875 = (cppVar_47874 & cppMask_un_5_);
	cppVar_47876 = cppVar_47875 + 32;
	cppVar_47876 = (cppVar_47876 & cppMask_un_8_);
	cppVar_47863 = cppVar_47876;
	}
	cppVar_47878 = (cppVar_47863 == 153);
	if (cppVar_47878) {
	cppVar_47862 = SBUF;
	} else {
	cppVar_47881 = PC + 1;
	cppVar_47881 = (cppVar_47881 & cppMask_un_16_);
	cppVar_47882 = ROM.rd(cppVar_47881);
	cppVar_47883 = (cppVar_47882 >> 7) & cppMask_un_1_;
	cppVar_47884 = (cppVar_47883 == 1);
	if (cppVar_47884) {
	cppVar_47885 = PC + 1;
	cppVar_47885 = (cppVar_47885 & cppMask_un_16_);
	cppVar_47886 = ROM.rd(cppVar_47885);
	cppVar_47887 = (cppVar_47886 >> 3) & cppMask_un_5_;
	cppVar_47888 = (cppVar_47887 << 3) | 0;
	cppVar_47888 = (cppVar_47888 & cppMask_un_8_);
	cppVar_47880 = cppVar_47888;
	} else {
	cppVar_47889 = PC + 1;
	cppVar_47889 = (cppVar_47889 & cppMask_un_16_);
	cppVar_47890 = ROM.rd(cppVar_47889);
	cppVar_47891 = (cppVar_47890 >> 3) & cppMask_un_5_;
	cppVar_47892 = (cppVar_47891 & cppMask_un_5_);
	cppVar_47893 = cppVar_47892 + 32;
	cppVar_47893 = (cppVar_47893 & cppMask_un_8_);
	cppVar_47880 = cppVar_47893;
	}
	cppVar_47895 = (cppVar_47880 == 160);
	if (cppVar_47895) {
	cppVar_47879 = P2;
	} else {
	cppVar_47898 = PC + 1;
	cppVar_47898 = (cppVar_47898 & cppMask_un_16_);
	cppVar_47899 = ROM.rd(cppVar_47898);
	cppVar_47900 = (cppVar_47899 >> 7) & cppMask_un_1_;
	cppVar_47901 = (cppVar_47900 == 1);
	if (cppVar_47901) {
	cppVar_47902 = PC + 1;
	cppVar_47902 = (cppVar_47902 & cppMask_un_16_);
	cppVar_47903 = ROM.rd(cppVar_47902);
	cppVar_47904 = (cppVar_47903 >> 3) & cppMask_un_5_;
	cppVar_47905 = (cppVar_47904 << 3) | 0;
	cppVar_47905 = (cppVar_47905 & cppMask_un_8_);
	cppVar_47897 = cppVar_47905;
	} else {
	cppVar_47906 = PC + 1;
	cppVar_47906 = (cppVar_47906 & cppMask_un_16_);
	cppVar_47907 = ROM.rd(cppVar_47906);
	cppVar_47908 = (cppVar_47907 >> 3) & cppMask_un_5_;
	cppVar_47909 = (cppVar_47908 & cppMask_un_5_);
	cppVar_47910 = cppVar_47909 + 32;
	cppVar_47910 = (cppVar_47910 & cppMask_un_8_);
	cppVar_47897 = cppVar_47910;
	}
	cppVar_47912 = (cppVar_47897 == 168);
	if (cppVar_47912) {
	cppVar_47896 = IE;
	} else {
	cppVar_47915 = PC + 1;
	cppVar_47915 = (cppVar_47915 & cppMask_un_16_);
	cppVar_47916 = ROM.rd(cppVar_47915);
	cppVar_47917 = (cppVar_47916 >> 7) & cppMask_un_1_;
	cppVar_47918 = (cppVar_47917 == 1);
	if (cppVar_47918) {
	cppVar_47919 = PC + 1;
	cppVar_47919 = (cppVar_47919 & cppMask_un_16_);
	cppVar_47920 = ROM.rd(cppVar_47919);
	cppVar_47921 = (cppVar_47920 >> 3) & cppMask_un_5_;
	cppVar_47922 = (cppVar_47921 << 3) | 0;
	cppVar_47922 = (cppVar_47922 & cppMask_un_8_);
	cppVar_47914 = cppVar_47922;
	} else {
	cppVar_47923 = PC + 1;
	cppVar_47923 = (cppVar_47923 & cppMask_un_16_);
	cppVar_47924 = ROM.rd(cppVar_47923);
	cppVar_47925 = (cppVar_47924 >> 3) & cppMask_un_5_;
	cppVar_47926 = (cppVar_47925 & cppMask_un_5_);
	cppVar_47927 = cppVar_47926 + 32;
	cppVar_47927 = (cppVar_47927 & cppMask_un_8_);
	cppVar_47914 = cppVar_47927;
	}
	cppVar_47929 = (cppVar_47914 == 176);
	if (cppVar_47929) {
	cppVar_47913 = P3;
	} else {
	cppVar_47932 = PC + 1;
	cppVar_47932 = (cppVar_47932 & cppMask_un_16_);
	cppVar_47933 = ROM.rd(cppVar_47932);
	cppVar_47934 = (cppVar_47933 >> 7) & cppMask_un_1_;
	cppVar_47935 = (cppVar_47934 == 1);
	if (cppVar_47935) {
	cppVar_47936 = PC + 1;
	cppVar_47936 = (cppVar_47936 & cppMask_un_16_);
	cppVar_47937 = ROM.rd(cppVar_47936);
	cppVar_47938 = (cppVar_47937 >> 3) & cppMask_un_5_;
	cppVar_47939 = (cppVar_47938 << 3) | 0;
	cppVar_47939 = (cppVar_47939 & cppMask_un_8_);
	cppVar_47931 = cppVar_47939;
	} else {
	cppVar_47940 = PC + 1;
	cppVar_47940 = (cppVar_47940 & cppMask_un_16_);
	cppVar_47941 = ROM.rd(cppVar_47940);
	cppVar_47942 = (cppVar_47941 >> 3) & cppMask_un_5_;
	cppVar_47943 = (cppVar_47942 & cppMask_un_5_);
	cppVar_47944 = cppVar_47943 + 32;
	cppVar_47944 = (cppVar_47944 & cppMask_un_8_);
	cppVar_47931 = cppVar_47944;
	}
	cppVar_47946 = (cppVar_47931 == 184);
	if (cppVar_47946) {
	cppVar_47930 = IP;
	} else {
	cppVar_47949 = PC + 1;
	cppVar_47949 = (cppVar_47949 & cppMask_un_16_);
	cppVar_47950 = ROM.rd(cppVar_47949);
	cppVar_47951 = (cppVar_47950 >> 7) & cppMask_un_1_;
	cppVar_47952 = (cppVar_47951 == 1);
	if (cppVar_47952) {
	cppVar_47953 = PC + 1;
	cppVar_47953 = (cppVar_47953 & cppMask_un_16_);
	cppVar_47954 = ROM.rd(cppVar_47953);
	cppVar_47955 = (cppVar_47954 >> 3) & cppMask_un_5_;
	cppVar_47956 = (cppVar_47955 << 3) | 0;
	cppVar_47956 = (cppVar_47956 & cppMask_un_8_);
	cppVar_47948 = cppVar_47956;
	} else {
	cppVar_47957 = PC + 1;
	cppVar_47957 = (cppVar_47957 & cppMask_un_16_);
	cppVar_47958 = ROM.rd(cppVar_47957);
	cppVar_47959 = (cppVar_47958 >> 3) & cppMask_un_5_;
	cppVar_47960 = (cppVar_47959 & cppMask_un_5_);
	cppVar_47961 = cppVar_47960 + 32;
	cppVar_47961 = (cppVar_47961 & cppMask_un_8_);
	cppVar_47948 = cppVar_47961;
	}
	cppVar_47963 = (cppVar_47948 == 208);
	if (cppVar_47963) {
	cppVar_47947 = PSW;
	} else {
	cppVar_47966 = PC + 1;
	cppVar_47966 = (cppVar_47966 & cppMask_un_16_);
	cppVar_47967 = ROM.rd(cppVar_47966);
	cppVar_47968 = (cppVar_47967 >> 7) & cppMask_un_1_;
	cppVar_47969 = (cppVar_47968 == 1);
	if (cppVar_47969) {
	cppVar_47970 = PC + 1;
	cppVar_47970 = (cppVar_47970 & cppMask_un_16_);
	cppVar_47971 = ROM.rd(cppVar_47970);
	cppVar_47972 = (cppVar_47971 >> 3) & cppMask_un_5_;
	cppVar_47973 = (cppVar_47972 << 3) | 0;
	cppVar_47973 = (cppVar_47973 & cppMask_un_8_);
	cppVar_47965 = cppVar_47973;
	} else {
	cppVar_47974 = PC + 1;
	cppVar_47974 = (cppVar_47974 & cppMask_un_16_);
	cppVar_47975 = ROM.rd(cppVar_47974);
	cppVar_47976 = (cppVar_47975 >> 3) & cppMask_un_5_;
	cppVar_47977 = (cppVar_47976 & cppMask_un_5_);
	cppVar_47978 = cppVar_47977 + 32;
	cppVar_47978 = (cppVar_47978 & cppMask_un_8_);
	cppVar_47965 = cppVar_47978;
	}
	cppVar_47980 = (cppVar_47965 == 224);
	if (cppVar_47980) {
	cppVar_47964 = ACC;
	} else {
	cppVar_47983 = PC + 1;
	cppVar_47983 = (cppVar_47983 & cppMask_un_16_);
	cppVar_47984 = ROM.rd(cppVar_47983);
	cppVar_47985 = (cppVar_47984 >> 7) & cppMask_un_1_;
	cppVar_47986 = (cppVar_47985 == 1);
	if (cppVar_47986) {
	cppVar_47987 = PC + 1;
	cppVar_47987 = (cppVar_47987 & cppMask_un_16_);
	cppVar_47988 = ROM.rd(cppVar_47987);
	cppVar_47989 = (cppVar_47988 >> 3) & cppMask_un_5_;
	cppVar_47990 = (cppVar_47989 << 3) | 0;
	cppVar_47990 = (cppVar_47990 & cppMask_un_8_);
	cppVar_47982 = cppVar_47990;
	} else {
	cppVar_47991 = PC + 1;
	cppVar_47991 = (cppVar_47991 & cppMask_un_16_);
	cppVar_47992 = ROM.rd(cppVar_47991);
	cppVar_47993 = (cppVar_47992 >> 3) & cppMask_un_5_;
	cppVar_47994 = (cppVar_47993 & cppMask_un_5_);
	cppVar_47995 = cppVar_47994 + 32;
	cppVar_47995 = (cppVar_47995 & cppMask_un_8_);
	cppVar_47982 = cppVar_47995;
	}
	cppVar_47997 = (cppVar_47982 == 240);
	if (cppVar_47997) {
	cppVar_47981 = B;
	} else {
	cppVar_47981 = 0;
	}
	cppVar_47964 = cppVar_47981;
	}
	cppVar_47947 = cppVar_47964;
	}
	cppVar_47930 = cppVar_47947;
	}
	cppVar_47913 = cppVar_47930;
	}
	cppVar_47896 = cppVar_47913;
	}
	cppVar_47879 = cppVar_47896;
	}
	cppVar_47862 = cppVar_47879;
	}
	cppVar_47845 = cppVar_47862;
	}
	cppVar_47828 = cppVar_47845;
	}
	cppVar_47811 = cppVar_47828;
	}
	cppVar_47794 = cppVar_47811;
	}
	cppVar_47777 = cppVar_47794;
	}
	cppVar_47760 = cppVar_47777;
	}
	cppVar_47743 = cppVar_47760;
	}
	cppVar_47726 = cppVar_47743;
	}
	cppVar_47709 = cppVar_47726;
	}
	cppVar_47692 = cppVar_47709;
	}
	cppVar_47675 = cppVar_47692;
	}
	cppVar_47658 = cppVar_47675;
	}
	cppVar_47641 = cppVar_47658;
	}
	cppVar_47608 = cppVar_47641;
	}
	cppVar_47999 = cppVar_47607 & cppVar_47608;
	cppVar_48002 = PC + 1;
	cppVar_48002 = (cppVar_48002 & cppMask_un_16_);
	cppVar_48003 = ROM.rd(cppVar_48002);
	cppVar_48004 = (cppVar_48003 >> 7) & cppMask_un_1_;
	cppVar_48006 = (cppVar_48004 == 1);
	if (cppVar_48006) {
	cppVar_48007 = PC + 1;
	cppVar_48007 = (cppVar_48007 & cppMask_un_16_);
	cppVar_48008 = ROM.rd(cppVar_48007);
	cppVar_48009 = (cppVar_48008 >> 3) & cppMask_un_5_;
	cppVar_48011 = (cppVar_48009 << 3) | 0;
	cppVar_48011 = (cppVar_48011 & cppMask_un_8_);
	cppVar_48001 = cppVar_48011;
	} else {
	cppVar_48012 = PC + 1;
	cppVar_48012 = (cppVar_48012 & cppMask_un_16_);
	cppVar_48013 = ROM.rd(cppVar_48012);
	cppVar_48014 = (cppVar_48013 >> 3) & cppMask_un_5_;
	cppVar_48015 = (cppVar_48014 & cppMask_un_5_);
	cppVar_48017 = cppVar_48015 + 32;
	cppVar_48017 = (cppVar_48017 & cppMask_un_8_);
	cppVar_48001 = cppVar_48017;
	}
	cppVar_48018 = (cppVar_48001 >> 7) & cppMask_un_1_;
	cppVar_48020 = (cppVar_48018 == 0);
	if (cppVar_48020) {
	cppVar_48022 = PC + 1;
	cppVar_48022 = (cppVar_48022 & cppMask_un_16_);
	cppVar_48023 = ROM.rd(cppVar_48022);
	cppVar_48024 = (cppVar_48023 >> 7) & cppMask_un_1_;
	cppVar_48025 = (cppVar_48024 == 1);
	if (cppVar_48025) {
	cppVar_48026 = PC + 1;
	cppVar_48026 = (cppVar_48026 & cppMask_un_16_);
	cppVar_48027 = ROM.rd(cppVar_48026);
	cppVar_48028 = (cppVar_48027 >> 3) & cppMask_un_5_;
	cppVar_48029 = (cppVar_48028 << 3) | 0;
	cppVar_48029 = (cppVar_48029 & cppMask_un_8_);
	cppVar_48021 = cppVar_48029;
	} else {
	cppVar_48030 = PC + 1;
	cppVar_48030 = (cppVar_48030 & cppMask_un_16_);
	cppVar_48031 = ROM.rd(cppVar_48030);
	cppVar_48032 = (cppVar_48031 >> 3) & cppMask_un_5_;
	cppVar_48033 = (cppVar_48032 & cppMask_un_5_);
	cppVar_48034 = cppVar_48033 + 32;
	cppVar_48034 = (cppVar_48034 & cppMask_un_8_);
	cppVar_48021 = cppVar_48034;
	}
	cppVar_48035 = IRAM.rd(cppVar_48021);
	cppVar_48000 = cppVar_48035;
	} else {
	cppVar_48038 = PC + 1;
	cppVar_48038 = (cppVar_48038 & cppMask_un_16_);
	cppVar_48039 = ROM.rd(cppVar_48038);
	cppVar_48040 = (cppVar_48039 >> 7) & cppMask_un_1_;
	cppVar_48041 = (cppVar_48040 == 1);
	if (cppVar_48041) {
	cppVar_48042 = PC + 1;
	cppVar_48042 = (cppVar_48042 & cppMask_un_16_);
	cppVar_48043 = ROM.rd(cppVar_48042);
	cppVar_48044 = (cppVar_48043 >> 3) & cppMask_un_5_;
	cppVar_48045 = (cppVar_48044 << 3) | 0;
	cppVar_48045 = (cppVar_48045 & cppMask_un_8_);
	cppVar_48037 = cppVar_48045;
	} else {
	cppVar_48046 = PC + 1;
	cppVar_48046 = (cppVar_48046 & cppMask_un_16_);
	cppVar_48047 = ROM.rd(cppVar_48046);
	cppVar_48048 = (cppVar_48047 >> 3) & cppMask_un_5_;
	cppVar_48049 = (cppVar_48048 & cppMask_un_5_);
	cppVar_48050 = cppVar_48049 + 32;
	cppVar_48050 = (cppVar_48050 & cppMask_un_8_);
	cppVar_48037 = cppVar_48050;
	}
	cppVar_48052 = (cppVar_48037 == 128);
	if (cppVar_48052) {
	cppVar_48036 = P0;
	} else {
	cppVar_48055 = PC + 1;
	cppVar_48055 = (cppVar_48055 & cppMask_un_16_);
	cppVar_48056 = ROM.rd(cppVar_48055);
	cppVar_48057 = (cppVar_48056 >> 7) & cppMask_un_1_;
	cppVar_48058 = (cppVar_48057 == 1);
	if (cppVar_48058) {
	cppVar_48059 = PC + 1;
	cppVar_48059 = (cppVar_48059 & cppMask_un_16_);
	cppVar_48060 = ROM.rd(cppVar_48059);
	cppVar_48061 = (cppVar_48060 >> 3) & cppMask_un_5_;
	cppVar_48062 = (cppVar_48061 << 3) | 0;
	cppVar_48062 = (cppVar_48062 & cppMask_un_8_);
	cppVar_48054 = cppVar_48062;
	} else {
	cppVar_48063 = PC + 1;
	cppVar_48063 = (cppVar_48063 & cppMask_un_16_);
	cppVar_48064 = ROM.rd(cppVar_48063);
	cppVar_48065 = (cppVar_48064 >> 3) & cppMask_un_5_;
	cppVar_48066 = (cppVar_48065 & cppMask_un_5_);
	cppVar_48067 = cppVar_48066 + 32;
	cppVar_48067 = (cppVar_48067 & cppMask_un_8_);
	cppVar_48054 = cppVar_48067;
	}
	cppVar_48069 = (cppVar_48054 == 129);
	if (cppVar_48069) {
	cppVar_48053 = SP;
	} else {
	cppVar_48072 = PC + 1;
	cppVar_48072 = (cppVar_48072 & cppMask_un_16_);
	cppVar_48073 = ROM.rd(cppVar_48072);
	cppVar_48074 = (cppVar_48073 >> 7) & cppMask_un_1_;
	cppVar_48075 = (cppVar_48074 == 1);
	if (cppVar_48075) {
	cppVar_48076 = PC + 1;
	cppVar_48076 = (cppVar_48076 & cppMask_un_16_);
	cppVar_48077 = ROM.rd(cppVar_48076);
	cppVar_48078 = (cppVar_48077 >> 3) & cppMask_un_5_;
	cppVar_48079 = (cppVar_48078 << 3) | 0;
	cppVar_48079 = (cppVar_48079 & cppMask_un_8_);
	cppVar_48071 = cppVar_48079;
	} else {
	cppVar_48080 = PC + 1;
	cppVar_48080 = (cppVar_48080 & cppMask_un_16_);
	cppVar_48081 = ROM.rd(cppVar_48080);
	cppVar_48082 = (cppVar_48081 >> 3) & cppMask_un_5_;
	cppVar_48083 = (cppVar_48082 & cppMask_un_5_);
	cppVar_48084 = cppVar_48083 + 32;
	cppVar_48084 = (cppVar_48084 & cppMask_un_8_);
	cppVar_48071 = cppVar_48084;
	}
	cppVar_48086 = (cppVar_48071 == 130);
	if (cppVar_48086) {
	cppVar_48070 = DPL;
	} else {
	cppVar_48089 = PC + 1;
	cppVar_48089 = (cppVar_48089 & cppMask_un_16_);
	cppVar_48090 = ROM.rd(cppVar_48089);
	cppVar_48091 = (cppVar_48090 >> 7) & cppMask_un_1_;
	cppVar_48092 = (cppVar_48091 == 1);
	if (cppVar_48092) {
	cppVar_48093 = PC + 1;
	cppVar_48093 = (cppVar_48093 & cppMask_un_16_);
	cppVar_48094 = ROM.rd(cppVar_48093);
	cppVar_48095 = (cppVar_48094 >> 3) & cppMask_un_5_;
	cppVar_48096 = (cppVar_48095 << 3) | 0;
	cppVar_48096 = (cppVar_48096 & cppMask_un_8_);
	cppVar_48088 = cppVar_48096;
	} else {
	cppVar_48097 = PC + 1;
	cppVar_48097 = (cppVar_48097 & cppMask_un_16_);
	cppVar_48098 = ROM.rd(cppVar_48097);
	cppVar_48099 = (cppVar_48098 >> 3) & cppMask_un_5_;
	cppVar_48100 = (cppVar_48099 & cppMask_un_5_);
	cppVar_48101 = cppVar_48100 + 32;
	cppVar_48101 = (cppVar_48101 & cppMask_un_8_);
	cppVar_48088 = cppVar_48101;
	}
	cppVar_48103 = (cppVar_48088 == 131);
	if (cppVar_48103) {
	cppVar_48087 = DPH;
	} else {
	cppVar_48106 = PC + 1;
	cppVar_48106 = (cppVar_48106 & cppMask_un_16_);
	cppVar_48107 = ROM.rd(cppVar_48106);
	cppVar_48108 = (cppVar_48107 >> 7) & cppMask_un_1_;
	cppVar_48109 = (cppVar_48108 == 1);
	if (cppVar_48109) {
	cppVar_48110 = PC + 1;
	cppVar_48110 = (cppVar_48110 & cppMask_un_16_);
	cppVar_48111 = ROM.rd(cppVar_48110);
	cppVar_48112 = (cppVar_48111 >> 3) & cppMask_un_5_;
	cppVar_48113 = (cppVar_48112 << 3) | 0;
	cppVar_48113 = (cppVar_48113 & cppMask_un_8_);
	cppVar_48105 = cppVar_48113;
	} else {
	cppVar_48114 = PC + 1;
	cppVar_48114 = (cppVar_48114 & cppMask_un_16_);
	cppVar_48115 = ROM.rd(cppVar_48114);
	cppVar_48116 = (cppVar_48115 >> 3) & cppMask_un_5_;
	cppVar_48117 = (cppVar_48116 & cppMask_un_5_);
	cppVar_48118 = cppVar_48117 + 32;
	cppVar_48118 = (cppVar_48118 & cppMask_un_8_);
	cppVar_48105 = cppVar_48118;
	}
	cppVar_48120 = (cppVar_48105 == 135);
	if (cppVar_48120) {
	cppVar_48104 = PCON;
	} else {
	cppVar_48123 = PC + 1;
	cppVar_48123 = (cppVar_48123 & cppMask_un_16_);
	cppVar_48124 = ROM.rd(cppVar_48123);
	cppVar_48125 = (cppVar_48124 >> 7) & cppMask_un_1_;
	cppVar_48126 = (cppVar_48125 == 1);
	if (cppVar_48126) {
	cppVar_48127 = PC + 1;
	cppVar_48127 = (cppVar_48127 & cppMask_un_16_);
	cppVar_48128 = ROM.rd(cppVar_48127);
	cppVar_48129 = (cppVar_48128 >> 3) & cppMask_un_5_;
	cppVar_48130 = (cppVar_48129 << 3) | 0;
	cppVar_48130 = (cppVar_48130 & cppMask_un_8_);
	cppVar_48122 = cppVar_48130;
	} else {
	cppVar_48131 = PC + 1;
	cppVar_48131 = (cppVar_48131 & cppMask_un_16_);
	cppVar_48132 = ROM.rd(cppVar_48131);
	cppVar_48133 = (cppVar_48132 >> 3) & cppMask_un_5_;
	cppVar_48134 = (cppVar_48133 & cppMask_un_5_);
	cppVar_48135 = cppVar_48134 + 32;
	cppVar_48135 = (cppVar_48135 & cppMask_un_8_);
	cppVar_48122 = cppVar_48135;
	}
	cppVar_48137 = (cppVar_48122 == 136);
	if (cppVar_48137) {
	cppVar_48121 = TCON;
	} else {
	cppVar_48140 = PC + 1;
	cppVar_48140 = (cppVar_48140 & cppMask_un_16_);
	cppVar_48141 = ROM.rd(cppVar_48140);
	cppVar_48142 = (cppVar_48141 >> 7) & cppMask_un_1_;
	cppVar_48143 = (cppVar_48142 == 1);
	if (cppVar_48143) {
	cppVar_48144 = PC + 1;
	cppVar_48144 = (cppVar_48144 & cppMask_un_16_);
	cppVar_48145 = ROM.rd(cppVar_48144);
	cppVar_48146 = (cppVar_48145 >> 3) & cppMask_un_5_;
	cppVar_48147 = (cppVar_48146 << 3) | 0;
	cppVar_48147 = (cppVar_48147 & cppMask_un_8_);
	cppVar_48139 = cppVar_48147;
	} else {
	cppVar_48148 = PC + 1;
	cppVar_48148 = (cppVar_48148 & cppMask_un_16_);
	cppVar_48149 = ROM.rd(cppVar_48148);
	cppVar_48150 = (cppVar_48149 >> 3) & cppMask_un_5_;
	cppVar_48151 = (cppVar_48150 & cppMask_un_5_);
	cppVar_48152 = cppVar_48151 + 32;
	cppVar_48152 = (cppVar_48152 & cppMask_un_8_);
	cppVar_48139 = cppVar_48152;
	}
	cppVar_48154 = (cppVar_48139 == 137);
	if (cppVar_48154) {
	cppVar_48138 = TMOD;
	} else {
	cppVar_48157 = PC + 1;
	cppVar_48157 = (cppVar_48157 & cppMask_un_16_);
	cppVar_48158 = ROM.rd(cppVar_48157);
	cppVar_48159 = (cppVar_48158 >> 7) & cppMask_un_1_;
	cppVar_48160 = (cppVar_48159 == 1);
	if (cppVar_48160) {
	cppVar_48161 = PC + 1;
	cppVar_48161 = (cppVar_48161 & cppMask_un_16_);
	cppVar_48162 = ROM.rd(cppVar_48161);
	cppVar_48163 = (cppVar_48162 >> 3) & cppMask_un_5_;
	cppVar_48164 = (cppVar_48163 << 3) | 0;
	cppVar_48164 = (cppVar_48164 & cppMask_un_8_);
	cppVar_48156 = cppVar_48164;
	} else {
	cppVar_48165 = PC + 1;
	cppVar_48165 = (cppVar_48165 & cppMask_un_16_);
	cppVar_48166 = ROM.rd(cppVar_48165);
	cppVar_48167 = (cppVar_48166 >> 3) & cppMask_un_5_;
	cppVar_48168 = (cppVar_48167 & cppMask_un_5_);
	cppVar_48169 = cppVar_48168 + 32;
	cppVar_48169 = (cppVar_48169 & cppMask_un_8_);
	cppVar_48156 = cppVar_48169;
	}
	cppVar_48171 = (cppVar_48156 == 138);
	if (cppVar_48171) {
	cppVar_48155 = TL0;
	} else {
	cppVar_48174 = PC + 1;
	cppVar_48174 = (cppVar_48174 & cppMask_un_16_);
	cppVar_48175 = ROM.rd(cppVar_48174);
	cppVar_48176 = (cppVar_48175 >> 7) & cppMask_un_1_;
	cppVar_48177 = (cppVar_48176 == 1);
	if (cppVar_48177) {
	cppVar_48178 = PC + 1;
	cppVar_48178 = (cppVar_48178 & cppMask_un_16_);
	cppVar_48179 = ROM.rd(cppVar_48178);
	cppVar_48180 = (cppVar_48179 >> 3) & cppMask_un_5_;
	cppVar_48181 = (cppVar_48180 << 3) | 0;
	cppVar_48181 = (cppVar_48181 & cppMask_un_8_);
	cppVar_48173 = cppVar_48181;
	} else {
	cppVar_48182 = PC + 1;
	cppVar_48182 = (cppVar_48182 & cppMask_un_16_);
	cppVar_48183 = ROM.rd(cppVar_48182);
	cppVar_48184 = (cppVar_48183 >> 3) & cppMask_un_5_;
	cppVar_48185 = (cppVar_48184 & cppMask_un_5_);
	cppVar_48186 = cppVar_48185 + 32;
	cppVar_48186 = (cppVar_48186 & cppMask_un_8_);
	cppVar_48173 = cppVar_48186;
	}
	cppVar_48188 = (cppVar_48173 == 140);
	if (cppVar_48188) {
	cppVar_48172 = TH0;
	} else {
	cppVar_48191 = PC + 1;
	cppVar_48191 = (cppVar_48191 & cppMask_un_16_);
	cppVar_48192 = ROM.rd(cppVar_48191);
	cppVar_48193 = (cppVar_48192 >> 7) & cppMask_un_1_;
	cppVar_48194 = (cppVar_48193 == 1);
	if (cppVar_48194) {
	cppVar_48195 = PC + 1;
	cppVar_48195 = (cppVar_48195 & cppMask_un_16_);
	cppVar_48196 = ROM.rd(cppVar_48195);
	cppVar_48197 = (cppVar_48196 >> 3) & cppMask_un_5_;
	cppVar_48198 = (cppVar_48197 << 3) | 0;
	cppVar_48198 = (cppVar_48198 & cppMask_un_8_);
	cppVar_48190 = cppVar_48198;
	} else {
	cppVar_48199 = PC + 1;
	cppVar_48199 = (cppVar_48199 & cppMask_un_16_);
	cppVar_48200 = ROM.rd(cppVar_48199);
	cppVar_48201 = (cppVar_48200 >> 3) & cppMask_un_5_;
	cppVar_48202 = (cppVar_48201 & cppMask_un_5_);
	cppVar_48203 = cppVar_48202 + 32;
	cppVar_48203 = (cppVar_48203 & cppMask_un_8_);
	cppVar_48190 = cppVar_48203;
	}
	cppVar_48205 = (cppVar_48190 == 139);
	if (cppVar_48205) {
	cppVar_48189 = TL1;
	} else {
	cppVar_48208 = PC + 1;
	cppVar_48208 = (cppVar_48208 & cppMask_un_16_);
	cppVar_48209 = ROM.rd(cppVar_48208);
	cppVar_48210 = (cppVar_48209 >> 7) & cppMask_un_1_;
	cppVar_48211 = (cppVar_48210 == 1);
	if (cppVar_48211) {
	cppVar_48212 = PC + 1;
	cppVar_48212 = (cppVar_48212 & cppMask_un_16_);
	cppVar_48213 = ROM.rd(cppVar_48212);
	cppVar_48214 = (cppVar_48213 >> 3) & cppMask_un_5_;
	cppVar_48215 = (cppVar_48214 << 3) | 0;
	cppVar_48215 = (cppVar_48215 & cppMask_un_8_);
	cppVar_48207 = cppVar_48215;
	} else {
	cppVar_48216 = PC + 1;
	cppVar_48216 = (cppVar_48216 & cppMask_un_16_);
	cppVar_48217 = ROM.rd(cppVar_48216);
	cppVar_48218 = (cppVar_48217 >> 3) & cppMask_un_5_;
	cppVar_48219 = (cppVar_48218 & cppMask_un_5_);
	cppVar_48220 = cppVar_48219 + 32;
	cppVar_48220 = (cppVar_48220 & cppMask_un_8_);
	cppVar_48207 = cppVar_48220;
	}
	cppVar_48222 = (cppVar_48207 == 141);
	if (cppVar_48222) {
	cppVar_48206 = TH1;
	} else {
	cppVar_48225 = PC + 1;
	cppVar_48225 = (cppVar_48225 & cppMask_un_16_);
	cppVar_48226 = ROM.rd(cppVar_48225);
	cppVar_48227 = (cppVar_48226 >> 7) & cppMask_un_1_;
	cppVar_48228 = (cppVar_48227 == 1);
	if (cppVar_48228) {
	cppVar_48229 = PC + 1;
	cppVar_48229 = (cppVar_48229 & cppMask_un_16_);
	cppVar_48230 = ROM.rd(cppVar_48229);
	cppVar_48231 = (cppVar_48230 >> 3) & cppMask_un_5_;
	cppVar_48232 = (cppVar_48231 << 3) | 0;
	cppVar_48232 = (cppVar_48232 & cppMask_un_8_);
	cppVar_48224 = cppVar_48232;
	} else {
	cppVar_48233 = PC + 1;
	cppVar_48233 = (cppVar_48233 & cppMask_un_16_);
	cppVar_48234 = ROM.rd(cppVar_48233);
	cppVar_48235 = (cppVar_48234 >> 3) & cppMask_un_5_;
	cppVar_48236 = (cppVar_48235 & cppMask_un_5_);
	cppVar_48237 = cppVar_48236 + 32;
	cppVar_48237 = (cppVar_48237 & cppMask_un_8_);
	cppVar_48224 = cppVar_48237;
	}
	cppVar_48239 = (cppVar_48224 == 144);
	if (cppVar_48239) {
	cppVar_48223 = P1;
	} else {
	cppVar_48242 = PC + 1;
	cppVar_48242 = (cppVar_48242 & cppMask_un_16_);
	cppVar_48243 = ROM.rd(cppVar_48242);
	cppVar_48244 = (cppVar_48243 >> 7) & cppMask_un_1_;
	cppVar_48245 = (cppVar_48244 == 1);
	if (cppVar_48245) {
	cppVar_48246 = PC + 1;
	cppVar_48246 = (cppVar_48246 & cppMask_un_16_);
	cppVar_48247 = ROM.rd(cppVar_48246);
	cppVar_48248 = (cppVar_48247 >> 3) & cppMask_un_5_;
	cppVar_48249 = (cppVar_48248 << 3) | 0;
	cppVar_48249 = (cppVar_48249 & cppMask_un_8_);
	cppVar_48241 = cppVar_48249;
	} else {
	cppVar_48250 = PC + 1;
	cppVar_48250 = (cppVar_48250 & cppMask_un_16_);
	cppVar_48251 = ROM.rd(cppVar_48250);
	cppVar_48252 = (cppVar_48251 >> 3) & cppMask_un_5_;
	cppVar_48253 = (cppVar_48252 & cppMask_un_5_);
	cppVar_48254 = cppVar_48253 + 32;
	cppVar_48254 = (cppVar_48254 & cppMask_un_8_);
	cppVar_48241 = cppVar_48254;
	}
	cppVar_48256 = (cppVar_48241 == 152);
	if (cppVar_48256) {
	cppVar_48240 = SCON;
	} else {
	cppVar_48259 = PC + 1;
	cppVar_48259 = (cppVar_48259 & cppMask_un_16_);
	cppVar_48260 = ROM.rd(cppVar_48259);
	cppVar_48261 = (cppVar_48260 >> 7) & cppMask_un_1_;
	cppVar_48262 = (cppVar_48261 == 1);
	if (cppVar_48262) {
	cppVar_48263 = PC + 1;
	cppVar_48263 = (cppVar_48263 & cppMask_un_16_);
	cppVar_48264 = ROM.rd(cppVar_48263);
	cppVar_48265 = (cppVar_48264 >> 3) & cppMask_un_5_;
	cppVar_48266 = (cppVar_48265 << 3) | 0;
	cppVar_48266 = (cppVar_48266 & cppMask_un_8_);
	cppVar_48258 = cppVar_48266;
	} else {
	cppVar_48267 = PC + 1;
	cppVar_48267 = (cppVar_48267 & cppMask_un_16_);
	cppVar_48268 = ROM.rd(cppVar_48267);
	cppVar_48269 = (cppVar_48268 >> 3) & cppMask_un_5_;
	cppVar_48270 = (cppVar_48269 & cppMask_un_5_);
	cppVar_48271 = cppVar_48270 + 32;
	cppVar_48271 = (cppVar_48271 & cppMask_un_8_);
	cppVar_48258 = cppVar_48271;
	}
	cppVar_48273 = (cppVar_48258 == 153);
	if (cppVar_48273) {
	cppVar_48257 = SBUF;
	} else {
	cppVar_48276 = PC + 1;
	cppVar_48276 = (cppVar_48276 & cppMask_un_16_);
	cppVar_48277 = ROM.rd(cppVar_48276);
	cppVar_48278 = (cppVar_48277 >> 7) & cppMask_un_1_;
	cppVar_48279 = (cppVar_48278 == 1);
	if (cppVar_48279) {
	cppVar_48280 = PC + 1;
	cppVar_48280 = (cppVar_48280 & cppMask_un_16_);
	cppVar_48281 = ROM.rd(cppVar_48280);
	cppVar_48282 = (cppVar_48281 >> 3) & cppMask_un_5_;
	cppVar_48283 = (cppVar_48282 << 3) | 0;
	cppVar_48283 = (cppVar_48283 & cppMask_un_8_);
	cppVar_48275 = cppVar_48283;
	} else {
	cppVar_48284 = PC + 1;
	cppVar_48284 = (cppVar_48284 & cppMask_un_16_);
	cppVar_48285 = ROM.rd(cppVar_48284);
	cppVar_48286 = (cppVar_48285 >> 3) & cppMask_un_5_;
	cppVar_48287 = (cppVar_48286 & cppMask_un_5_);
	cppVar_48288 = cppVar_48287 + 32;
	cppVar_48288 = (cppVar_48288 & cppMask_un_8_);
	cppVar_48275 = cppVar_48288;
	}
	cppVar_48290 = (cppVar_48275 == 160);
	if (cppVar_48290) {
	cppVar_48274 = P2;
	} else {
	cppVar_48293 = PC + 1;
	cppVar_48293 = (cppVar_48293 & cppMask_un_16_);
	cppVar_48294 = ROM.rd(cppVar_48293);
	cppVar_48295 = (cppVar_48294 >> 7) & cppMask_un_1_;
	cppVar_48296 = (cppVar_48295 == 1);
	if (cppVar_48296) {
	cppVar_48297 = PC + 1;
	cppVar_48297 = (cppVar_48297 & cppMask_un_16_);
	cppVar_48298 = ROM.rd(cppVar_48297);
	cppVar_48299 = (cppVar_48298 >> 3) & cppMask_un_5_;
	cppVar_48300 = (cppVar_48299 << 3) | 0;
	cppVar_48300 = (cppVar_48300 & cppMask_un_8_);
	cppVar_48292 = cppVar_48300;
	} else {
	cppVar_48301 = PC + 1;
	cppVar_48301 = (cppVar_48301 & cppMask_un_16_);
	cppVar_48302 = ROM.rd(cppVar_48301);
	cppVar_48303 = (cppVar_48302 >> 3) & cppMask_un_5_;
	cppVar_48304 = (cppVar_48303 & cppMask_un_5_);
	cppVar_48305 = cppVar_48304 + 32;
	cppVar_48305 = (cppVar_48305 & cppMask_un_8_);
	cppVar_48292 = cppVar_48305;
	}
	cppVar_48307 = (cppVar_48292 == 168);
	if (cppVar_48307) {
	cppVar_48291 = IE;
	} else {
	cppVar_48310 = PC + 1;
	cppVar_48310 = (cppVar_48310 & cppMask_un_16_);
	cppVar_48311 = ROM.rd(cppVar_48310);
	cppVar_48312 = (cppVar_48311 >> 7) & cppMask_un_1_;
	cppVar_48313 = (cppVar_48312 == 1);
	if (cppVar_48313) {
	cppVar_48314 = PC + 1;
	cppVar_48314 = (cppVar_48314 & cppMask_un_16_);
	cppVar_48315 = ROM.rd(cppVar_48314);
	cppVar_48316 = (cppVar_48315 >> 3) & cppMask_un_5_;
	cppVar_48317 = (cppVar_48316 << 3) | 0;
	cppVar_48317 = (cppVar_48317 & cppMask_un_8_);
	cppVar_48309 = cppVar_48317;
	} else {
	cppVar_48318 = PC + 1;
	cppVar_48318 = (cppVar_48318 & cppMask_un_16_);
	cppVar_48319 = ROM.rd(cppVar_48318);
	cppVar_48320 = (cppVar_48319 >> 3) & cppMask_un_5_;
	cppVar_48321 = (cppVar_48320 & cppMask_un_5_);
	cppVar_48322 = cppVar_48321 + 32;
	cppVar_48322 = (cppVar_48322 & cppMask_un_8_);
	cppVar_48309 = cppVar_48322;
	}
	cppVar_48324 = (cppVar_48309 == 176);
	if (cppVar_48324) {
	cppVar_48308 = P3;
	} else {
	cppVar_48327 = PC + 1;
	cppVar_48327 = (cppVar_48327 & cppMask_un_16_);
	cppVar_48328 = ROM.rd(cppVar_48327);
	cppVar_48329 = (cppVar_48328 >> 7) & cppMask_un_1_;
	cppVar_48330 = (cppVar_48329 == 1);
	if (cppVar_48330) {
	cppVar_48331 = PC + 1;
	cppVar_48331 = (cppVar_48331 & cppMask_un_16_);
	cppVar_48332 = ROM.rd(cppVar_48331);
	cppVar_48333 = (cppVar_48332 >> 3) & cppMask_un_5_;
	cppVar_48334 = (cppVar_48333 << 3) | 0;
	cppVar_48334 = (cppVar_48334 & cppMask_un_8_);
	cppVar_48326 = cppVar_48334;
	} else {
	cppVar_48335 = PC + 1;
	cppVar_48335 = (cppVar_48335 & cppMask_un_16_);
	cppVar_48336 = ROM.rd(cppVar_48335);
	cppVar_48337 = (cppVar_48336 >> 3) & cppMask_un_5_;
	cppVar_48338 = (cppVar_48337 & cppMask_un_5_);
	cppVar_48339 = cppVar_48338 + 32;
	cppVar_48339 = (cppVar_48339 & cppMask_un_8_);
	cppVar_48326 = cppVar_48339;
	}
	cppVar_48341 = (cppVar_48326 == 184);
	if (cppVar_48341) {
	cppVar_48325 = IP;
	} else {
	cppVar_48344 = PC + 1;
	cppVar_48344 = (cppVar_48344 & cppMask_un_16_);
	cppVar_48345 = ROM.rd(cppVar_48344);
	cppVar_48346 = (cppVar_48345 >> 7) & cppMask_un_1_;
	cppVar_48347 = (cppVar_48346 == 1);
	if (cppVar_48347) {
	cppVar_48348 = PC + 1;
	cppVar_48348 = (cppVar_48348 & cppMask_un_16_);
	cppVar_48349 = ROM.rd(cppVar_48348);
	cppVar_48350 = (cppVar_48349 >> 3) & cppMask_un_5_;
	cppVar_48351 = (cppVar_48350 << 3) | 0;
	cppVar_48351 = (cppVar_48351 & cppMask_un_8_);
	cppVar_48343 = cppVar_48351;
	} else {
	cppVar_48352 = PC + 1;
	cppVar_48352 = (cppVar_48352 & cppMask_un_16_);
	cppVar_48353 = ROM.rd(cppVar_48352);
	cppVar_48354 = (cppVar_48353 >> 3) & cppMask_un_5_;
	cppVar_48355 = (cppVar_48354 & cppMask_un_5_);
	cppVar_48356 = cppVar_48355 + 32;
	cppVar_48356 = (cppVar_48356 & cppMask_un_8_);
	cppVar_48343 = cppVar_48356;
	}
	cppVar_48358 = (cppVar_48343 == 208);
	if (cppVar_48358) {
	cppVar_48342 = PSW;
	} else {
	cppVar_48361 = PC + 1;
	cppVar_48361 = (cppVar_48361 & cppMask_un_16_);
	cppVar_48362 = ROM.rd(cppVar_48361);
	cppVar_48363 = (cppVar_48362 >> 7) & cppMask_un_1_;
	cppVar_48364 = (cppVar_48363 == 1);
	if (cppVar_48364) {
	cppVar_48365 = PC + 1;
	cppVar_48365 = (cppVar_48365 & cppMask_un_16_);
	cppVar_48366 = ROM.rd(cppVar_48365);
	cppVar_48367 = (cppVar_48366 >> 3) & cppMask_un_5_;
	cppVar_48368 = (cppVar_48367 << 3) | 0;
	cppVar_48368 = (cppVar_48368 & cppMask_un_8_);
	cppVar_48360 = cppVar_48368;
	} else {
	cppVar_48369 = PC + 1;
	cppVar_48369 = (cppVar_48369 & cppMask_un_16_);
	cppVar_48370 = ROM.rd(cppVar_48369);
	cppVar_48371 = (cppVar_48370 >> 3) & cppMask_un_5_;
	cppVar_48372 = (cppVar_48371 & cppMask_un_5_);
	cppVar_48373 = cppVar_48372 + 32;
	cppVar_48373 = (cppVar_48373 & cppMask_un_8_);
	cppVar_48360 = cppVar_48373;
	}
	cppVar_48375 = (cppVar_48360 == 224);
	if (cppVar_48375) {
	cppVar_48359 = ACC;
	} else {
	cppVar_48378 = PC + 1;
	cppVar_48378 = (cppVar_48378 & cppMask_un_16_);
	cppVar_48379 = ROM.rd(cppVar_48378);
	cppVar_48380 = (cppVar_48379 >> 7) & cppMask_un_1_;
	cppVar_48381 = (cppVar_48380 == 1);
	if (cppVar_48381) {
	cppVar_48382 = PC + 1;
	cppVar_48382 = (cppVar_48382 & cppMask_un_16_);
	cppVar_48383 = ROM.rd(cppVar_48382);
	cppVar_48384 = (cppVar_48383 >> 3) & cppMask_un_5_;
	cppVar_48385 = (cppVar_48384 << 3) | 0;
	cppVar_48385 = (cppVar_48385 & cppMask_un_8_);
	cppVar_48377 = cppVar_48385;
	} else {
	cppVar_48386 = PC + 1;
	cppVar_48386 = (cppVar_48386 & cppMask_un_16_);
	cppVar_48387 = ROM.rd(cppVar_48386);
	cppVar_48388 = (cppVar_48387 >> 3) & cppMask_un_5_;
	cppVar_48389 = (cppVar_48388 & cppMask_un_5_);
	cppVar_48390 = cppVar_48389 + 32;
	cppVar_48390 = (cppVar_48390 & cppMask_un_8_);
	cppVar_48377 = cppVar_48390;
	}
	cppVar_48392 = (cppVar_48377 == 240);
	if (cppVar_48392) {
	cppVar_48376 = B;
	} else {
	cppVar_48376 = 0;
	}
	cppVar_48359 = cppVar_48376;
	}
	cppVar_48342 = cppVar_48359;
	}
	cppVar_48325 = cppVar_48342;
	}
	cppVar_48308 = cppVar_48325;
	}
	cppVar_48291 = cppVar_48308;
	}
	cppVar_48274 = cppVar_48291;
	}
	cppVar_48257 = cppVar_48274;
	}
	cppVar_48240 = cppVar_48257;
	}
	cppVar_48223 = cppVar_48240;
	}
	cppVar_48206 = cppVar_48223;
	}
	cppVar_48189 = cppVar_48206;
	}
	cppVar_48172 = cppVar_48189;
	}
	cppVar_48155 = cppVar_48172;
	}
	cppVar_48138 = cppVar_48155;
	}
	cppVar_48121 = cppVar_48138;
	}
	cppVar_48104 = cppVar_48121;
	}
	cppVar_48087 = cppVar_48104;
	}
	cppVar_48070 = cppVar_48087;
	}
	cppVar_48053 = cppVar_48070;
	}
	cppVar_48036 = cppVar_48053;
	}
	cppVar_48000 = cppVar_48036;
	}
	cppVar_48394 = PC + 1;
	cppVar_48394 = (cppVar_48394 & cppMask_un_16_);
	cppVar_48395 = ROM.rd(cppVar_48394);
	cppVar_48396 = (cppVar_48395 >> 0) & cppMask_un_3_;
	cppVar_48397 = (cppVar_48000 >> static_cast<unsigned>(cppVar_48396)) & 0x1;
	cppVar_48398 = ~cppVar_48397;
	cppVar_48399 = (cppVar_48398 & cppMask_un_1_);
	cppVar_48400 = PC + 1;
	cppVar_48400 = (cppVar_48400 & cppMask_un_16_);
	cppVar_48401 = ROM.rd(cppVar_48400);
	cppVar_48402 = (cppVar_48401 >> 0) & cppMask_un_3_;
	cppVar_48403 = (cppVar_48402 & cppMask_un_3_);
	cppVar_48404 = cppVar_48399 << static_cast<unsigned>(cppVar_48403);
	cppVar_48404 = (cppVar_48404 & cppMask_un_8_);
	cppVar_48405 = cppVar_47999 | cppVar_48404;
	cppVar_47580 = cppVar_48405;
	} else {
	cppVar_47580 = PSW;
	}
	cppVar_47576 = cppVar_47580;
	} else {
	cppVar_48407 = ROM.rd(PC);
	cppVar_48409 = (cppVar_48407 == 176);
	if (cppVar_48409) {
	cppVar_48410 = (PSW >> 7) & cppMask_un_1_;
	cppVar_48414 = PC + 1;
	cppVar_48414 = (cppVar_48414 & cppMask_un_16_);
	cppVar_48415 = ROM.rd(cppVar_48414);
	cppVar_48416 = (cppVar_48415 >> 7) & cppMask_un_1_;
	cppVar_48418 = (cppVar_48416 == 1);
	if (cppVar_48418) {
	cppVar_48419 = PC + 1;
	cppVar_48419 = (cppVar_48419 & cppMask_un_16_);
	cppVar_48420 = ROM.rd(cppVar_48419);
	cppVar_48421 = (cppVar_48420 >> 3) & cppMask_un_5_;
	cppVar_48423 = (cppVar_48421 << 3) | 0;
	cppVar_48423 = (cppVar_48423 & cppMask_un_8_);
	cppVar_48412 = cppVar_48423;
	} else {
	cppVar_48424 = PC + 1;
	cppVar_48424 = (cppVar_48424 & cppMask_un_16_);
	cppVar_48425 = ROM.rd(cppVar_48424);
	cppVar_48426 = (cppVar_48425 >> 3) & cppMask_un_5_;
	cppVar_48427 = (cppVar_48426 & cppMask_un_5_);
	cppVar_48429 = cppVar_48427 + 32;
	cppVar_48429 = (cppVar_48429 & cppMask_un_8_);
	cppVar_48412 = cppVar_48429;
	}
	cppVar_48430 = (cppVar_48412 >> 7) & cppMask_un_1_;
	cppVar_48432 = (cppVar_48430 == 0);
	if (cppVar_48432) {
	cppVar_48434 = PC + 1;
	cppVar_48434 = (cppVar_48434 & cppMask_un_16_);
	cppVar_48435 = ROM.rd(cppVar_48434);
	cppVar_48436 = (cppVar_48435 >> 7) & cppMask_un_1_;
	cppVar_48437 = (cppVar_48436 == 1);
	if (cppVar_48437) {
	cppVar_48438 = PC + 1;
	cppVar_48438 = (cppVar_48438 & cppMask_un_16_);
	cppVar_48439 = ROM.rd(cppVar_48438);
	cppVar_48440 = (cppVar_48439 >> 3) & cppMask_un_5_;
	cppVar_48441 = (cppVar_48440 << 3) | 0;
	cppVar_48441 = (cppVar_48441 & cppMask_un_8_);
	cppVar_48433 = cppVar_48441;
	} else {
	cppVar_48442 = PC + 1;
	cppVar_48442 = (cppVar_48442 & cppMask_un_16_);
	cppVar_48443 = ROM.rd(cppVar_48442);
	cppVar_48444 = (cppVar_48443 >> 3) & cppMask_un_5_;
	cppVar_48445 = (cppVar_48444 & cppMask_un_5_);
	cppVar_48446 = cppVar_48445 + 32;
	cppVar_48446 = (cppVar_48446 & cppMask_un_8_);
	cppVar_48433 = cppVar_48446;
	}
	cppVar_48447 = IRAM.rd(cppVar_48433);
	cppVar_48411 = cppVar_48447;
	} else {
	cppVar_48450 = PC + 1;
	cppVar_48450 = (cppVar_48450 & cppMask_un_16_);
	cppVar_48451 = ROM.rd(cppVar_48450);
	cppVar_48452 = (cppVar_48451 >> 7) & cppMask_un_1_;
	cppVar_48453 = (cppVar_48452 == 1);
	if (cppVar_48453) {
	cppVar_48454 = PC + 1;
	cppVar_48454 = (cppVar_48454 & cppMask_un_16_);
	cppVar_48455 = ROM.rd(cppVar_48454);
	cppVar_48456 = (cppVar_48455 >> 3) & cppMask_un_5_;
	cppVar_48457 = (cppVar_48456 << 3) | 0;
	cppVar_48457 = (cppVar_48457 & cppMask_un_8_);
	cppVar_48449 = cppVar_48457;
	} else {
	cppVar_48458 = PC + 1;
	cppVar_48458 = (cppVar_48458 & cppMask_un_16_);
	cppVar_48459 = ROM.rd(cppVar_48458);
	cppVar_48460 = (cppVar_48459 >> 3) & cppMask_un_5_;
	cppVar_48461 = (cppVar_48460 & cppMask_un_5_);
	cppVar_48462 = cppVar_48461 + 32;
	cppVar_48462 = (cppVar_48462 & cppMask_un_8_);
	cppVar_48449 = cppVar_48462;
	}
	cppVar_48464 = (cppVar_48449 == 128);
	if (cppVar_48464) {
	cppVar_48448 = P0;
	} else {
	cppVar_48467 = PC + 1;
	cppVar_48467 = (cppVar_48467 & cppMask_un_16_);
	cppVar_48468 = ROM.rd(cppVar_48467);
	cppVar_48469 = (cppVar_48468 >> 7) & cppMask_un_1_;
	cppVar_48470 = (cppVar_48469 == 1);
	if (cppVar_48470) {
	cppVar_48471 = PC + 1;
	cppVar_48471 = (cppVar_48471 & cppMask_un_16_);
	cppVar_48472 = ROM.rd(cppVar_48471);
	cppVar_48473 = (cppVar_48472 >> 3) & cppMask_un_5_;
	cppVar_48474 = (cppVar_48473 << 3) | 0;
	cppVar_48474 = (cppVar_48474 & cppMask_un_8_);
	cppVar_48466 = cppVar_48474;
	} else {
	cppVar_48475 = PC + 1;
	cppVar_48475 = (cppVar_48475 & cppMask_un_16_);
	cppVar_48476 = ROM.rd(cppVar_48475);
	cppVar_48477 = (cppVar_48476 >> 3) & cppMask_un_5_;
	cppVar_48478 = (cppVar_48477 & cppMask_un_5_);
	cppVar_48479 = cppVar_48478 + 32;
	cppVar_48479 = (cppVar_48479 & cppMask_un_8_);
	cppVar_48466 = cppVar_48479;
	}
	cppVar_48481 = (cppVar_48466 == 129);
	if (cppVar_48481) {
	cppVar_48465 = SP;
	} else {
	cppVar_48484 = PC + 1;
	cppVar_48484 = (cppVar_48484 & cppMask_un_16_);
	cppVar_48485 = ROM.rd(cppVar_48484);
	cppVar_48486 = (cppVar_48485 >> 7) & cppMask_un_1_;
	cppVar_48487 = (cppVar_48486 == 1);
	if (cppVar_48487) {
	cppVar_48488 = PC + 1;
	cppVar_48488 = (cppVar_48488 & cppMask_un_16_);
	cppVar_48489 = ROM.rd(cppVar_48488);
	cppVar_48490 = (cppVar_48489 >> 3) & cppMask_un_5_;
	cppVar_48491 = (cppVar_48490 << 3) | 0;
	cppVar_48491 = (cppVar_48491 & cppMask_un_8_);
	cppVar_48483 = cppVar_48491;
	} else {
	cppVar_48492 = PC + 1;
	cppVar_48492 = (cppVar_48492 & cppMask_un_16_);
	cppVar_48493 = ROM.rd(cppVar_48492);
	cppVar_48494 = (cppVar_48493 >> 3) & cppMask_un_5_;
	cppVar_48495 = (cppVar_48494 & cppMask_un_5_);
	cppVar_48496 = cppVar_48495 + 32;
	cppVar_48496 = (cppVar_48496 & cppMask_un_8_);
	cppVar_48483 = cppVar_48496;
	}
	cppVar_48498 = (cppVar_48483 == 130);
	if (cppVar_48498) {
	cppVar_48482 = DPL;
	} else {
	cppVar_48501 = PC + 1;
	cppVar_48501 = (cppVar_48501 & cppMask_un_16_);
	cppVar_48502 = ROM.rd(cppVar_48501);
	cppVar_48503 = (cppVar_48502 >> 7) & cppMask_un_1_;
	cppVar_48504 = (cppVar_48503 == 1);
	if (cppVar_48504) {
	cppVar_48505 = PC + 1;
	cppVar_48505 = (cppVar_48505 & cppMask_un_16_);
	cppVar_48506 = ROM.rd(cppVar_48505);
	cppVar_48507 = (cppVar_48506 >> 3) & cppMask_un_5_;
	cppVar_48508 = (cppVar_48507 << 3) | 0;
	cppVar_48508 = (cppVar_48508 & cppMask_un_8_);
	cppVar_48500 = cppVar_48508;
	} else {
	cppVar_48509 = PC + 1;
	cppVar_48509 = (cppVar_48509 & cppMask_un_16_);
	cppVar_48510 = ROM.rd(cppVar_48509);
	cppVar_48511 = (cppVar_48510 >> 3) & cppMask_un_5_;
	cppVar_48512 = (cppVar_48511 & cppMask_un_5_);
	cppVar_48513 = cppVar_48512 + 32;
	cppVar_48513 = (cppVar_48513 & cppMask_un_8_);
	cppVar_48500 = cppVar_48513;
	}
	cppVar_48515 = (cppVar_48500 == 131);
	if (cppVar_48515) {
	cppVar_48499 = DPH;
	} else {
	cppVar_48518 = PC + 1;
	cppVar_48518 = (cppVar_48518 & cppMask_un_16_);
	cppVar_48519 = ROM.rd(cppVar_48518);
	cppVar_48520 = (cppVar_48519 >> 7) & cppMask_un_1_;
	cppVar_48521 = (cppVar_48520 == 1);
	if (cppVar_48521) {
	cppVar_48522 = PC + 1;
	cppVar_48522 = (cppVar_48522 & cppMask_un_16_);
	cppVar_48523 = ROM.rd(cppVar_48522);
	cppVar_48524 = (cppVar_48523 >> 3) & cppMask_un_5_;
	cppVar_48525 = (cppVar_48524 << 3) | 0;
	cppVar_48525 = (cppVar_48525 & cppMask_un_8_);
	cppVar_48517 = cppVar_48525;
	} else {
	cppVar_48526 = PC + 1;
	cppVar_48526 = (cppVar_48526 & cppMask_un_16_);
	cppVar_48527 = ROM.rd(cppVar_48526);
	cppVar_48528 = (cppVar_48527 >> 3) & cppMask_un_5_;
	cppVar_48529 = (cppVar_48528 & cppMask_un_5_);
	cppVar_48530 = cppVar_48529 + 32;
	cppVar_48530 = (cppVar_48530 & cppMask_un_8_);
	cppVar_48517 = cppVar_48530;
	}
	cppVar_48532 = (cppVar_48517 == 135);
	if (cppVar_48532) {
	cppVar_48516 = PCON;
	} else {
	cppVar_48535 = PC + 1;
	cppVar_48535 = (cppVar_48535 & cppMask_un_16_);
	cppVar_48536 = ROM.rd(cppVar_48535);
	cppVar_48537 = (cppVar_48536 >> 7) & cppMask_un_1_;
	cppVar_48538 = (cppVar_48537 == 1);
	if (cppVar_48538) {
	cppVar_48539 = PC + 1;
	cppVar_48539 = (cppVar_48539 & cppMask_un_16_);
	cppVar_48540 = ROM.rd(cppVar_48539);
	cppVar_48541 = (cppVar_48540 >> 3) & cppMask_un_5_;
	cppVar_48542 = (cppVar_48541 << 3) | 0;
	cppVar_48542 = (cppVar_48542 & cppMask_un_8_);
	cppVar_48534 = cppVar_48542;
	} else {
	cppVar_48543 = PC + 1;
	cppVar_48543 = (cppVar_48543 & cppMask_un_16_);
	cppVar_48544 = ROM.rd(cppVar_48543);
	cppVar_48545 = (cppVar_48544 >> 3) & cppMask_un_5_;
	cppVar_48546 = (cppVar_48545 & cppMask_un_5_);
	cppVar_48547 = cppVar_48546 + 32;
	cppVar_48547 = (cppVar_48547 & cppMask_un_8_);
	cppVar_48534 = cppVar_48547;
	}
	cppVar_48549 = (cppVar_48534 == 136);
	if (cppVar_48549) {
	cppVar_48533 = TCON;
	} else {
	cppVar_48552 = PC + 1;
	cppVar_48552 = (cppVar_48552 & cppMask_un_16_);
	cppVar_48553 = ROM.rd(cppVar_48552);
	cppVar_48554 = (cppVar_48553 >> 7) & cppMask_un_1_;
	cppVar_48555 = (cppVar_48554 == 1);
	if (cppVar_48555) {
	cppVar_48556 = PC + 1;
	cppVar_48556 = (cppVar_48556 & cppMask_un_16_);
	cppVar_48557 = ROM.rd(cppVar_48556);
	cppVar_48558 = (cppVar_48557 >> 3) & cppMask_un_5_;
	cppVar_48559 = (cppVar_48558 << 3) | 0;
	cppVar_48559 = (cppVar_48559 & cppMask_un_8_);
	cppVar_48551 = cppVar_48559;
	} else {
	cppVar_48560 = PC + 1;
	cppVar_48560 = (cppVar_48560 & cppMask_un_16_);
	cppVar_48561 = ROM.rd(cppVar_48560);
	cppVar_48562 = (cppVar_48561 >> 3) & cppMask_un_5_;
	cppVar_48563 = (cppVar_48562 & cppMask_un_5_);
	cppVar_48564 = cppVar_48563 + 32;
	cppVar_48564 = (cppVar_48564 & cppMask_un_8_);
	cppVar_48551 = cppVar_48564;
	}
	cppVar_48566 = (cppVar_48551 == 137);
	if (cppVar_48566) {
	cppVar_48550 = TMOD;
	} else {
	cppVar_48569 = PC + 1;
	cppVar_48569 = (cppVar_48569 & cppMask_un_16_);
	cppVar_48570 = ROM.rd(cppVar_48569);
	cppVar_48571 = (cppVar_48570 >> 7) & cppMask_un_1_;
	cppVar_48572 = (cppVar_48571 == 1);
	if (cppVar_48572) {
	cppVar_48573 = PC + 1;
	cppVar_48573 = (cppVar_48573 & cppMask_un_16_);
	cppVar_48574 = ROM.rd(cppVar_48573);
	cppVar_48575 = (cppVar_48574 >> 3) & cppMask_un_5_;
	cppVar_48576 = (cppVar_48575 << 3) | 0;
	cppVar_48576 = (cppVar_48576 & cppMask_un_8_);
	cppVar_48568 = cppVar_48576;
	} else {
	cppVar_48577 = PC + 1;
	cppVar_48577 = (cppVar_48577 & cppMask_un_16_);
	cppVar_48578 = ROM.rd(cppVar_48577);
	cppVar_48579 = (cppVar_48578 >> 3) & cppMask_un_5_;
	cppVar_48580 = (cppVar_48579 & cppMask_un_5_);
	cppVar_48581 = cppVar_48580 + 32;
	cppVar_48581 = (cppVar_48581 & cppMask_un_8_);
	cppVar_48568 = cppVar_48581;
	}
	cppVar_48583 = (cppVar_48568 == 138);
	if (cppVar_48583) {
	cppVar_48567 = TL0;
	} else {
	cppVar_48586 = PC + 1;
	cppVar_48586 = (cppVar_48586 & cppMask_un_16_);
	cppVar_48587 = ROM.rd(cppVar_48586);
	cppVar_48588 = (cppVar_48587 >> 7) & cppMask_un_1_;
	cppVar_48589 = (cppVar_48588 == 1);
	if (cppVar_48589) {
	cppVar_48590 = PC + 1;
	cppVar_48590 = (cppVar_48590 & cppMask_un_16_);
	cppVar_48591 = ROM.rd(cppVar_48590);
	cppVar_48592 = (cppVar_48591 >> 3) & cppMask_un_5_;
	cppVar_48593 = (cppVar_48592 << 3) | 0;
	cppVar_48593 = (cppVar_48593 & cppMask_un_8_);
	cppVar_48585 = cppVar_48593;
	} else {
	cppVar_48594 = PC + 1;
	cppVar_48594 = (cppVar_48594 & cppMask_un_16_);
	cppVar_48595 = ROM.rd(cppVar_48594);
	cppVar_48596 = (cppVar_48595 >> 3) & cppMask_un_5_;
	cppVar_48597 = (cppVar_48596 & cppMask_un_5_);
	cppVar_48598 = cppVar_48597 + 32;
	cppVar_48598 = (cppVar_48598 & cppMask_un_8_);
	cppVar_48585 = cppVar_48598;
	}
	cppVar_48600 = (cppVar_48585 == 140);
	if (cppVar_48600) {
	cppVar_48584 = TH0;
	} else {
	cppVar_48603 = PC + 1;
	cppVar_48603 = (cppVar_48603 & cppMask_un_16_);
	cppVar_48604 = ROM.rd(cppVar_48603);
	cppVar_48605 = (cppVar_48604 >> 7) & cppMask_un_1_;
	cppVar_48606 = (cppVar_48605 == 1);
	if (cppVar_48606) {
	cppVar_48607 = PC + 1;
	cppVar_48607 = (cppVar_48607 & cppMask_un_16_);
	cppVar_48608 = ROM.rd(cppVar_48607);
	cppVar_48609 = (cppVar_48608 >> 3) & cppMask_un_5_;
	cppVar_48610 = (cppVar_48609 << 3) | 0;
	cppVar_48610 = (cppVar_48610 & cppMask_un_8_);
	cppVar_48602 = cppVar_48610;
	} else {
	cppVar_48611 = PC + 1;
	cppVar_48611 = (cppVar_48611 & cppMask_un_16_);
	cppVar_48612 = ROM.rd(cppVar_48611);
	cppVar_48613 = (cppVar_48612 >> 3) & cppMask_un_5_;
	cppVar_48614 = (cppVar_48613 & cppMask_un_5_);
	cppVar_48615 = cppVar_48614 + 32;
	cppVar_48615 = (cppVar_48615 & cppMask_un_8_);
	cppVar_48602 = cppVar_48615;
	}
	cppVar_48617 = (cppVar_48602 == 139);
	if (cppVar_48617) {
	cppVar_48601 = TL1;
	} else {
	cppVar_48620 = PC + 1;
	cppVar_48620 = (cppVar_48620 & cppMask_un_16_);
	cppVar_48621 = ROM.rd(cppVar_48620);
	cppVar_48622 = (cppVar_48621 >> 7) & cppMask_un_1_;
	cppVar_48623 = (cppVar_48622 == 1);
	if (cppVar_48623) {
	cppVar_48624 = PC + 1;
	cppVar_48624 = (cppVar_48624 & cppMask_un_16_);
	cppVar_48625 = ROM.rd(cppVar_48624);
	cppVar_48626 = (cppVar_48625 >> 3) & cppMask_un_5_;
	cppVar_48627 = (cppVar_48626 << 3) | 0;
	cppVar_48627 = (cppVar_48627 & cppMask_un_8_);
	cppVar_48619 = cppVar_48627;
	} else {
	cppVar_48628 = PC + 1;
	cppVar_48628 = (cppVar_48628 & cppMask_un_16_);
	cppVar_48629 = ROM.rd(cppVar_48628);
	cppVar_48630 = (cppVar_48629 >> 3) & cppMask_un_5_;
	cppVar_48631 = (cppVar_48630 & cppMask_un_5_);
	cppVar_48632 = cppVar_48631 + 32;
	cppVar_48632 = (cppVar_48632 & cppMask_un_8_);
	cppVar_48619 = cppVar_48632;
	}
	cppVar_48634 = (cppVar_48619 == 141);
	if (cppVar_48634) {
	cppVar_48618 = TH1;
	} else {
	cppVar_48637 = PC + 1;
	cppVar_48637 = (cppVar_48637 & cppMask_un_16_);
	cppVar_48638 = ROM.rd(cppVar_48637);
	cppVar_48639 = (cppVar_48638 >> 7) & cppMask_un_1_;
	cppVar_48640 = (cppVar_48639 == 1);
	if (cppVar_48640) {
	cppVar_48641 = PC + 1;
	cppVar_48641 = (cppVar_48641 & cppMask_un_16_);
	cppVar_48642 = ROM.rd(cppVar_48641);
	cppVar_48643 = (cppVar_48642 >> 3) & cppMask_un_5_;
	cppVar_48644 = (cppVar_48643 << 3) | 0;
	cppVar_48644 = (cppVar_48644 & cppMask_un_8_);
	cppVar_48636 = cppVar_48644;
	} else {
	cppVar_48645 = PC + 1;
	cppVar_48645 = (cppVar_48645 & cppMask_un_16_);
	cppVar_48646 = ROM.rd(cppVar_48645);
	cppVar_48647 = (cppVar_48646 >> 3) & cppMask_un_5_;
	cppVar_48648 = (cppVar_48647 & cppMask_un_5_);
	cppVar_48649 = cppVar_48648 + 32;
	cppVar_48649 = (cppVar_48649 & cppMask_un_8_);
	cppVar_48636 = cppVar_48649;
	}
	cppVar_48651 = (cppVar_48636 == 144);
	if (cppVar_48651) {
	cppVar_48635 = P1;
	} else {
	cppVar_48654 = PC + 1;
	cppVar_48654 = (cppVar_48654 & cppMask_un_16_);
	cppVar_48655 = ROM.rd(cppVar_48654);
	cppVar_48656 = (cppVar_48655 >> 7) & cppMask_un_1_;
	cppVar_48657 = (cppVar_48656 == 1);
	if (cppVar_48657) {
	cppVar_48658 = PC + 1;
	cppVar_48658 = (cppVar_48658 & cppMask_un_16_);
	cppVar_48659 = ROM.rd(cppVar_48658);
	cppVar_48660 = (cppVar_48659 >> 3) & cppMask_un_5_;
	cppVar_48661 = (cppVar_48660 << 3) | 0;
	cppVar_48661 = (cppVar_48661 & cppMask_un_8_);
	cppVar_48653 = cppVar_48661;
	} else {
	cppVar_48662 = PC + 1;
	cppVar_48662 = (cppVar_48662 & cppMask_un_16_);
	cppVar_48663 = ROM.rd(cppVar_48662);
	cppVar_48664 = (cppVar_48663 >> 3) & cppMask_un_5_;
	cppVar_48665 = (cppVar_48664 & cppMask_un_5_);
	cppVar_48666 = cppVar_48665 + 32;
	cppVar_48666 = (cppVar_48666 & cppMask_un_8_);
	cppVar_48653 = cppVar_48666;
	}
	cppVar_48668 = (cppVar_48653 == 152);
	if (cppVar_48668) {
	cppVar_48652 = SCON;
	} else {
	cppVar_48671 = PC + 1;
	cppVar_48671 = (cppVar_48671 & cppMask_un_16_);
	cppVar_48672 = ROM.rd(cppVar_48671);
	cppVar_48673 = (cppVar_48672 >> 7) & cppMask_un_1_;
	cppVar_48674 = (cppVar_48673 == 1);
	if (cppVar_48674) {
	cppVar_48675 = PC + 1;
	cppVar_48675 = (cppVar_48675 & cppMask_un_16_);
	cppVar_48676 = ROM.rd(cppVar_48675);
	cppVar_48677 = (cppVar_48676 >> 3) & cppMask_un_5_;
	cppVar_48678 = (cppVar_48677 << 3) | 0;
	cppVar_48678 = (cppVar_48678 & cppMask_un_8_);
	cppVar_48670 = cppVar_48678;
	} else {
	cppVar_48679 = PC + 1;
	cppVar_48679 = (cppVar_48679 & cppMask_un_16_);
	cppVar_48680 = ROM.rd(cppVar_48679);
	cppVar_48681 = (cppVar_48680 >> 3) & cppMask_un_5_;
	cppVar_48682 = (cppVar_48681 & cppMask_un_5_);
	cppVar_48683 = cppVar_48682 + 32;
	cppVar_48683 = (cppVar_48683 & cppMask_un_8_);
	cppVar_48670 = cppVar_48683;
	}
	cppVar_48685 = (cppVar_48670 == 153);
	if (cppVar_48685) {
	cppVar_48669 = SBUF;
	} else {
	cppVar_48688 = PC + 1;
	cppVar_48688 = (cppVar_48688 & cppMask_un_16_);
	cppVar_48689 = ROM.rd(cppVar_48688);
	cppVar_48690 = (cppVar_48689 >> 7) & cppMask_un_1_;
	cppVar_48691 = (cppVar_48690 == 1);
	if (cppVar_48691) {
	cppVar_48692 = PC + 1;
	cppVar_48692 = (cppVar_48692 & cppMask_un_16_);
	cppVar_48693 = ROM.rd(cppVar_48692);
	cppVar_48694 = (cppVar_48693 >> 3) & cppMask_un_5_;
	cppVar_48695 = (cppVar_48694 << 3) | 0;
	cppVar_48695 = (cppVar_48695 & cppMask_un_8_);
	cppVar_48687 = cppVar_48695;
	} else {
	cppVar_48696 = PC + 1;
	cppVar_48696 = (cppVar_48696 & cppMask_un_16_);
	cppVar_48697 = ROM.rd(cppVar_48696);
	cppVar_48698 = (cppVar_48697 >> 3) & cppMask_un_5_;
	cppVar_48699 = (cppVar_48698 & cppMask_un_5_);
	cppVar_48700 = cppVar_48699 + 32;
	cppVar_48700 = (cppVar_48700 & cppMask_un_8_);
	cppVar_48687 = cppVar_48700;
	}
	cppVar_48702 = (cppVar_48687 == 160);
	if (cppVar_48702) {
	cppVar_48686 = P2;
	} else {
	cppVar_48705 = PC + 1;
	cppVar_48705 = (cppVar_48705 & cppMask_un_16_);
	cppVar_48706 = ROM.rd(cppVar_48705);
	cppVar_48707 = (cppVar_48706 >> 7) & cppMask_un_1_;
	cppVar_48708 = (cppVar_48707 == 1);
	if (cppVar_48708) {
	cppVar_48709 = PC + 1;
	cppVar_48709 = (cppVar_48709 & cppMask_un_16_);
	cppVar_48710 = ROM.rd(cppVar_48709);
	cppVar_48711 = (cppVar_48710 >> 3) & cppMask_un_5_;
	cppVar_48712 = (cppVar_48711 << 3) | 0;
	cppVar_48712 = (cppVar_48712 & cppMask_un_8_);
	cppVar_48704 = cppVar_48712;
	} else {
	cppVar_48713 = PC + 1;
	cppVar_48713 = (cppVar_48713 & cppMask_un_16_);
	cppVar_48714 = ROM.rd(cppVar_48713);
	cppVar_48715 = (cppVar_48714 >> 3) & cppMask_un_5_;
	cppVar_48716 = (cppVar_48715 & cppMask_un_5_);
	cppVar_48717 = cppVar_48716 + 32;
	cppVar_48717 = (cppVar_48717 & cppMask_un_8_);
	cppVar_48704 = cppVar_48717;
	}
	cppVar_48719 = (cppVar_48704 == 168);
	if (cppVar_48719) {
	cppVar_48703 = IE;
	} else {
	cppVar_48722 = PC + 1;
	cppVar_48722 = (cppVar_48722 & cppMask_un_16_);
	cppVar_48723 = ROM.rd(cppVar_48722);
	cppVar_48724 = (cppVar_48723 >> 7) & cppMask_un_1_;
	cppVar_48725 = (cppVar_48724 == 1);
	if (cppVar_48725) {
	cppVar_48726 = PC + 1;
	cppVar_48726 = (cppVar_48726 & cppMask_un_16_);
	cppVar_48727 = ROM.rd(cppVar_48726);
	cppVar_48728 = (cppVar_48727 >> 3) & cppMask_un_5_;
	cppVar_48729 = (cppVar_48728 << 3) | 0;
	cppVar_48729 = (cppVar_48729 & cppMask_un_8_);
	cppVar_48721 = cppVar_48729;
	} else {
	cppVar_48730 = PC + 1;
	cppVar_48730 = (cppVar_48730 & cppMask_un_16_);
	cppVar_48731 = ROM.rd(cppVar_48730);
	cppVar_48732 = (cppVar_48731 >> 3) & cppMask_un_5_;
	cppVar_48733 = (cppVar_48732 & cppMask_un_5_);
	cppVar_48734 = cppVar_48733 + 32;
	cppVar_48734 = (cppVar_48734 & cppMask_un_8_);
	cppVar_48721 = cppVar_48734;
	}
	cppVar_48736 = (cppVar_48721 == 176);
	if (cppVar_48736) {
	cppVar_48720 = P3;
	} else {
	cppVar_48739 = PC + 1;
	cppVar_48739 = (cppVar_48739 & cppMask_un_16_);
	cppVar_48740 = ROM.rd(cppVar_48739);
	cppVar_48741 = (cppVar_48740 >> 7) & cppMask_un_1_;
	cppVar_48742 = (cppVar_48741 == 1);
	if (cppVar_48742) {
	cppVar_48743 = PC + 1;
	cppVar_48743 = (cppVar_48743 & cppMask_un_16_);
	cppVar_48744 = ROM.rd(cppVar_48743);
	cppVar_48745 = (cppVar_48744 >> 3) & cppMask_un_5_;
	cppVar_48746 = (cppVar_48745 << 3) | 0;
	cppVar_48746 = (cppVar_48746 & cppMask_un_8_);
	cppVar_48738 = cppVar_48746;
	} else {
	cppVar_48747 = PC + 1;
	cppVar_48747 = (cppVar_48747 & cppMask_un_16_);
	cppVar_48748 = ROM.rd(cppVar_48747);
	cppVar_48749 = (cppVar_48748 >> 3) & cppMask_un_5_;
	cppVar_48750 = (cppVar_48749 & cppMask_un_5_);
	cppVar_48751 = cppVar_48750 + 32;
	cppVar_48751 = (cppVar_48751 & cppMask_un_8_);
	cppVar_48738 = cppVar_48751;
	}
	cppVar_48753 = (cppVar_48738 == 184);
	if (cppVar_48753) {
	cppVar_48737 = IP;
	} else {
	cppVar_48756 = PC + 1;
	cppVar_48756 = (cppVar_48756 & cppMask_un_16_);
	cppVar_48757 = ROM.rd(cppVar_48756);
	cppVar_48758 = (cppVar_48757 >> 7) & cppMask_un_1_;
	cppVar_48759 = (cppVar_48758 == 1);
	if (cppVar_48759) {
	cppVar_48760 = PC + 1;
	cppVar_48760 = (cppVar_48760 & cppMask_un_16_);
	cppVar_48761 = ROM.rd(cppVar_48760);
	cppVar_48762 = (cppVar_48761 >> 3) & cppMask_un_5_;
	cppVar_48763 = (cppVar_48762 << 3) | 0;
	cppVar_48763 = (cppVar_48763 & cppMask_un_8_);
	cppVar_48755 = cppVar_48763;
	} else {
	cppVar_48764 = PC + 1;
	cppVar_48764 = (cppVar_48764 & cppMask_un_16_);
	cppVar_48765 = ROM.rd(cppVar_48764);
	cppVar_48766 = (cppVar_48765 >> 3) & cppMask_un_5_;
	cppVar_48767 = (cppVar_48766 & cppMask_un_5_);
	cppVar_48768 = cppVar_48767 + 32;
	cppVar_48768 = (cppVar_48768 & cppMask_un_8_);
	cppVar_48755 = cppVar_48768;
	}
	cppVar_48770 = (cppVar_48755 == 208);
	if (cppVar_48770) {
	cppVar_48754 = PSW;
	} else {
	cppVar_48773 = PC + 1;
	cppVar_48773 = (cppVar_48773 & cppMask_un_16_);
	cppVar_48774 = ROM.rd(cppVar_48773);
	cppVar_48775 = (cppVar_48774 >> 7) & cppMask_un_1_;
	cppVar_48776 = (cppVar_48775 == 1);
	if (cppVar_48776) {
	cppVar_48777 = PC + 1;
	cppVar_48777 = (cppVar_48777 & cppMask_un_16_);
	cppVar_48778 = ROM.rd(cppVar_48777);
	cppVar_48779 = (cppVar_48778 >> 3) & cppMask_un_5_;
	cppVar_48780 = (cppVar_48779 << 3) | 0;
	cppVar_48780 = (cppVar_48780 & cppMask_un_8_);
	cppVar_48772 = cppVar_48780;
	} else {
	cppVar_48781 = PC + 1;
	cppVar_48781 = (cppVar_48781 & cppMask_un_16_);
	cppVar_48782 = ROM.rd(cppVar_48781);
	cppVar_48783 = (cppVar_48782 >> 3) & cppMask_un_5_;
	cppVar_48784 = (cppVar_48783 & cppMask_un_5_);
	cppVar_48785 = cppVar_48784 + 32;
	cppVar_48785 = (cppVar_48785 & cppMask_un_8_);
	cppVar_48772 = cppVar_48785;
	}
	cppVar_48787 = (cppVar_48772 == 224);
	if (cppVar_48787) {
	cppVar_48771 = ACC;
	} else {
	cppVar_48790 = PC + 1;
	cppVar_48790 = (cppVar_48790 & cppMask_un_16_);
	cppVar_48791 = ROM.rd(cppVar_48790);
	cppVar_48792 = (cppVar_48791 >> 7) & cppMask_un_1_;
	cppVar_48793 = (cppVar_48792 == 1);
	if (cppVar_48793) {
	cppVar_48794 = PC + 1;
	cppVar_48794 = (cppVar_48794 & cppMask_un_16_);
	cppVar_48795 = ROM.rd(cppVar_48794);
	cppVar_48796 = (cppVar_48795 >> 3) & cppMask_un_5_;
	cppVar_48797 = (cppVar_48796 << 3) | 0;
	cppVar_48797 = (cppVar_48797 & cppMask_un_8_);
	cppVar_48789 = cppVar_48797;
	} else {
	cppVar_48798 = PC + 1;
	cppVar_48798 = (cppVar_48798 & cppMask_un_16_);
	cppVar_48799 = ROM.rd(cppVar_48798);
	cppVar_48800 = (cppVar_48799 >> 3) & cppMask_un_5_;
	cppVar_48801 = (cppVar_48800 & cppMask_un_5_);
	cppVar_48802 = cppVar_48801 + 32;
	cppVar_48802 = (cppVar_48802 & cppMask_un_8_);
	cppVar_48789 = cppVar_48802;
	}
	cppVar_48804 = (cppVar_48789 == 240);
	if (cppVar_48804) {
	cppVar_48788 = B;
	} else {
	cppVar_48788 = 0;
	}
	cppVar_48771 = cppVar_48788;
	}
	cppVar_48754 = cppVar_48771;
	}
	cppVar_48737 = cppVar_48754;
	}
	cppVar_48720 = cppVar_48737;
	}
	cppVar_48703 = cppVar_48720;
	}
	cppVar_48686 = cppVar_48703;
	}
	cppVar_48669 = cppVar_48686;
	}
	cppVar_48652 = cppVar_48669;
	}
	cppVar_48635 = cppVar_48652;
	}
	cppVar_48618 = cppVar_48635;
	}
	cppVar_48601 = cppVar_48618;
	}
	cppVar_48584 = cppVar_48601;
	}
	cppVar_48567 = cppVar_48584;
	}
	cppVar_48550 = cppVar_48567;
	}
	cppVar_48533 = cppVar_48550;
	}
	cppVar_48516 = cppVar_48533;
	}
	cppVar_48499 = cppVar_48516;
	}
	cppVar_48482 = cppVar_48499;
	}
	cppVar_48465 = cppVar_48482;
	}
	cppVar_48448 = cppVar_48465;
	}
	cppVar_48411 = cppVar_48448;
	}
	cppVar_48806 = PC + 1;
	cppVar_48806 = (cppVar_48806 & cppMask_un_16_);
	cppVar_48807 = ROM.rd(cppVar_48806);
	cppVar_48808 = (cppVar_48807 >> 0) & cppMask_un_3_;
	cppVar_48809 = (cppVar_48411 >> static_cast<unsigned>(cppVar_48808)) & 0x1;
	cppVar_48810 = ~cppVar_48809;
	cppVar_48811 = cppVar_48410 & cppVar_48810;
	cppVar_48812 = (PSW >> 0) & cppMask_un_7_;
	cppVar_48813 = (cppVar_48811 << 7) | cppVar_48812;
	cppVar_48813 = (cppVar_48813 & cppMask_un_8_);
	cppVar_48406 = cppVar_48813;
	} else {
	cppVar_48815 = ROM.rd(PC);
	cppVar_48817 = (cppVar_48815 == 164);
	if (cppVar_48817) {
	cppVar_48819 = (PSW >> 3) & cppMask_un_4_;
	cppVar_48821 = (ACC & cppMask_un_8_);
	cppVar_48822 = (B & cppMask_un_8_);
	cppVar_48823 = cppVar_48821 * cppVar_48822;
	cppVar_48823 = (cppVar_48823 & cppMask_un_16_);
	cppVar_48824 = (cppVar_48823 >> 8) & cppMask_un_8_;
	cppVar_48826 = (cppVar_48824 != 0);
	if (cppVar_48826) {
	cppVar_48820 = 1;
	} else {
	cppVar_48820 = 0;
	}
	cppVar_48829 = (PSW >> 0) & cppMask_un_2_;
	cppVar_48830 = (cppVar_48820 << 2) | cppVar_48829;
	cppVar_48830 = (cppVar_48830 & cppMask_un_3_);
	cppVar_48831 = (cppVar_48819 << 3) | cppVar_48830;
	cppVar_48831 = (cppVar_48831 & cppMask_un_7_);
	cppVar_48832 = (0 << 7) | cppVar_48831;
	cppVar_48832 = (cppVar_48832 & cppMask_un_8_);
	cppVar_48814 = cppVar_48832;
	} else {
	cppVar_48834 = ROM.rd(PC);
	cppVar_48836 = (cppVar_48834 == 162);
	if (cppVar_48836) {
	cppVar_48840 = PC + 1;
	cppVar_48840 = (cppVar_48840 & cppMask_un_16_);
	cppVar_48841 = ROM.rd(cppVar_48840);
	cppVar_48842 = (cppVar_48841 >> 7) & cppMask_un_1_;
	cppVar_48844 = (cppVar_48842 == 1);
	if (cppVar_48844) {
	cppVar_48845 = PC + 1;
	cppVar_48845 = (cppVar_48845 & cppMask_un_16_);
	cppVar_48846 = ROM.rd(cppVar_48845);
	cppVar_48847 = (cppVar_48846 >> 3) & cppMask_un_5_;
	cppVar_48849 = (cppVar_48847 << 3) | 0;
	cppVar_48849 = (cppVar_48849 & cppMask_un_8_);
	cppVar_48838 = cppVar_48849;
	} else {
	cppVar_48850 = PC + 1;
	cppVar_48850 = (cppVar_48850 & cppMask_un_16_);
	cppVar_48851 = ROM.rd(cppVar_48850);
	cppVar_48852 = (cppVar_48851 >> 3) & cppMask_un_5_;
	cppVar_48853 = (cppVar_48852 & cppMask_un_5_);
	cppVar_48855 = cppVar_48853 + 32;
	cppVar_48855 = (cppVar_48855 & cppMask_un_8_);
	cppVar_48838 = cppVar_48855;
	}
	cppVar_48856 = (cppVar_48838 >> 7) & cppMask_un_1_;
	cppVar_48858 = (cppVar_48856 == 0);
	if (cppVar_48858) {
	cppVar_48860 = PC + 1;
	cppVar_48860 = (cppVar_48860 & cppMask_un_16_);
	cppVar_48861 = ROM.rd(cppVar_48860);
	cppVar_48862 = (cppVar_48861 >> 7) & cppMask_un_1_;
	cppVar_48863 = (cppVar_48862 == 1);
	if (cppVar_48863) {
	cppVar_48864 = PC + 1;
	cppVar_48864 = (cppVar_48864 & cppMask_un_16_);
	cppVar_48865 = ROM.rd(cppVar_48864);
	cppVar_48866 = (cppVar_48865 >> 3) & cppMask_un_5_;
	cppVar_48867 = (cppVar_48866 << 3) | 0;
	cppVar_48867 = (cppVar_48867 & cppMask_un_8_);
	cppVar_48859 = cppVar_48867;
	} else {
	cppVar_48868 = PC + 1;
	cppVar_48868 = (cppVar_48868 & cppMask_un_16_);
	cppVar_48869 = ROM.rd(cppVar_48868);
	cppVar_48870 = (cppVar_48869 >> 3) & cppMask_un_5_;
	cppVar_48871 = (cppVar_48870 & cppMask_un_5_);
	cppVar_48872 = cppVar_48871 + 32;
	cppVar_48872 = (cppVar_48872 & cppMask_un_8_);
	cppVar_48859 = cppVar_48872;
	}
	cppVar_48873 = IRAM.rd(cppVar_48859);
	cppVar_48837 = cppVar_48873;
	} else {
	cppVar_48876 = PC + 1;
	cppVar_48876 = (cppVar_48876 & cppMask_un_16_);
	cppVar_48877 = ROM.rd(cppVar_48876);
	cppVar_48878 = (cppVar_48877 >> 7) & cppMask_un_1_;
	cppVar_48879 = (cppVar_48878 == 1);
	if (cppVar_48879) {
	cppVar_48880 = PC + 1;
	cppVar_48880 = (cppVar_48880 & cppMask_un_16_);
	cppVar_48881 = ROM.rd(cppVar_48880);
	cppVar_48882 = (cppVar_48881 >> 3) & cppMask_un_5_;
	cppVar_48883 = (cppVar_48882 << 3) | 0;
	cppVar_48883 = (cppVar_48883 & cppMask_un_8_);
	cppVar_48875 = cppVar_48883;
	} else {
	cppVar_48884 = PC + 1;
	cppVar_48884 = (cppVar_48884 & cppMask_un_16_);
	cppVar_48885 = ROM.rd(cppVar_48884);
	cppVar_48886 = (cppVar_48885 >> 3) & cppMask_un_5_;
	cppVar_48887 = (cppVar_48886 & cppMask_un_5_);
	cppVar_48888 = cppVar_48887 + 32;
	cppVar_48888 = (cppVar_48888 & cppMask_un_8_);
	cppVar_48875 = cppVar_48888;
	}
	cppVar_48890 = (cppVar_48875 == 128);
	if (cppVar_48890) {
	cppVar_48874 = P0;
	} else {
	cppVar_48893 = PC + 1;
	cppVar_48893 = (cppVar_48893 & cppMask_un_16_);
	cppVar_48894 = ROM.rd(cppVar_48893);
	cppVar_48895 = (cppVar_48894 >> 7) & cppMask_un_1_;
	cppVar_48896 = (cppVar_48895 == 1);
	if (cppVar_48896) {
	cppVar_48897 = PC + 1;
	cppVar_48897 = (cppVar_48897 & cppMask_un_16_);
	cppVar_48898 = ROM.rd(cppVar_48897);
	cppVar_48899 = (cppVar_48898 >> 3) & cppMask_un_5_;
	cppVar_48900 = (cppVar_48899 << 3) | 0;
	cppVar_48900 = (cppVar_48900 & cppMask_un_8_);
	cppVar_48892 = cppVar_48900;
	} else {
	cppVar_48901 = PC + 1;
	cppVar_48901 = (cppVar_48901 & cppMask_un_16_);
	cppVar_48902 = ROM.rd(cppVar_48901);
	cppVar_48903 = (cppVar_48902 >> 3) & cppMask_un_5_;
	cppVar_48904 = (cppVar_48903 & cppMask_un_5_);
	cppVar_48905 = cppVar_48904 + 32;
	cppVar_48905 = (cppVar_48905 & cppMask_un_8_);
	cppVar_48892 = cppVar_48905;
	}
	cppVar_48907 = (cppVar_48892 == 129);
	if (cppVar_48907) {
	cppVar_48891 = SP;
	} else {
	cppVar_48910 = PC + 1;
	cppVar_48910 = (cppVar_48910 & cppMask_un_16_);
	cppVar_48911 = ROM.rd(cppVar_48910);
	cppVar_48912 = (cppVar_48911 >> 7) & cppMask_un_1_;
	cppVar_48913 = (cppVar_48912 == 1);
	if (cppVar_48913) {
	cppVar_48914 = PC + 1;
	cppVar_48914 = (cppVar_48914 & cppMask_un_16_);
	cppVar_48915 = ROM.rd(cppVar_48914);
	cppVar_48916 = (cppVar_48915 >> 3) & cppMask_un_5_;
	cppVar_48917 = (cppVar_48916 << 3) | 0;
	cppVar_48917 = (cppVar_48917 & cppMask_un_8_);
	cppVar_48909 = cppVar_48917;
	} else {
	cppVar_48918 = PC + 1;
	cppVar_48918 = (cppVar_48918 & cppMask_un_16_);
	cppVar_48919 = ROM.rd(cppVar_48918);
	cppVar_48920 = (cppVar_48919 >> 3) & cppMask_un_5_;
	cppVar_48921 = (cppVar_48920 & cppMask_un_5_);
	cppVar_48922 = cppVar_48921 + 32;
	cppVar_48922 = (cppVar_48922 & cppMask_un_8_);
	cppVar_48909 = cppVar_48922;
	}
	cppVar_48924 = (cppVar_48909 == 130);
	if (cppVar_48924) {
	cppVar_48908 = DPL;
	} else {
	cppVar_48927 = PC + 1;
	cppVar_48927 = (cppVar_48927 & cppMask_un_16_);
	cppVar_48928 = ROM.rd(cppVar_48927);
	cppVar_48929 = (cppVar_48928 >> 7) & cppMask_un_1_;
	cppVar_48930 = (cppVar_48929 == 1);
	if (cppVar_48930) {
	cppVar_48931 = PC + 1;
	cppVar_48931 = (cppVar_48931 & cppMask_un_16_);
	cppVar_48932 = ROM.rd(cppVar_48931);
	cppVar_48933 = (cppVar_48932 >> 3) & cppMask_un_5_;
	cppVar_48934 = (cppVar_48933 << 3) | 0;
	cppVar_48934 = (cppVar_48934 & cppMask_un_8_);
	cppVar_48926 = cppVar_48934;
	} else {
	cppVar_48935 = PC + 1;
	cppVar_48935 = (cppVar_48935 & cppMask_un_16_);
	cppVar_48936 = ROM.rd(cppVar_48935);
	cppVar_48937 = (cppVar_48936 >> 3) & cppMask_un_5_;
	cppVar_48938 = (cppVar_48937 & cppMask_un_5_);
	cppVar_48939 = cppVar_48938 + 32;
	cppVar_48939 = (cppVar_48939 & cppMask_un_8_);
	cppVar_48926 = cppVar_48939;
	}
	cppVar_48941 = (cppVar_48926 == 131);
	if (cppVar_48941) {
	cppVar_48925 = DPH;
	} else {
	cppVar_48944 = PC + 1;
	cppVar_48944 = (cppVar_48944 & cppMask_un_16_);
	cppVar_48945 = ROM.rd(cppVar_48944);
	cppVar_48946 = (cppVar_48945 >> 7) & cppMask_un_1_;
	cppVar_48947 = (cppVar_48946 == 1);
	if (cppVar_48947) {
	cppVar_48948 = PC + 1;
	cppVar_48948 = (cppVar_48948 & cppMask_un_16_);
	cppVar_48949 = ROM.rd(cppVar_48948);
	cppVar_48950 = (cppVar_48949 >> 3) & cppMask_un_5_;
	cppVar_48951 = (cppVar_48950 << 3) | 0;
	cppVar_48951 = (cppVar_48951 & cppMask_un_8_);
	cppVar_48943 = cppVar_48951;
	} else {
	cppVar_48952 = PC + 1;
	cppVar_48952 = (cppVar_48952 & cppMask_un_16_);
	cppVar_48953 = ROM.rd(cppVar_48952);
	cppVar_48954 = (cppVar_48953 >> 3) & cppMask_un_5_;
	cppVar_48955 = (cppVar_48954 & cppMask_un_5_);
	cppVar_48956 = cppVar_48955 + 32;
	cppVar_48956 = (cppVar_48956 & cppMask_un_8_);
	cppVar_48943 = cppVar_48956;
	}
	cppVar_48958 = (cppVar_48943 == 135);
	if (cppVar_48958) {
	cppVar_48942 = PCON;
	} else {
	cppVar_48961 = PC + 1;
	cppVar_48961 = (cppVar_48961 & cppMask_un_16_);
	cppVar_48962 = ROM.rd(cppVar_48961);
	cppVar_48963 = (cppVar_48962 >> 7) & cppMask_un_1_;
	cppVar_48964 = (cppVar_48963 == 1);
	if (cppVar_48964) {
	cppVar_48965 = PC + 1;
	cppVar_48965 = (cppVar_48965 & cppMask_un_16_);
	cppVar_48966 = ROM.rd(cppVar_48965);
	cppVar_48967 = (cppVar_48966 >> 3) & cppMask_un_5_;
	cppVar_48968 = (cppVar_48967 << 3) | 0;
	cppVar_48968 = (cppVar_48968 & cppMask_un_8_);
	cppVar_48960 = cppVar_48968;
	} else {
	cppVar_48969 = PC + 1;
	cppVar_48969 = (cppVar_48969 & cppMask_un_16_);
	cppVar_48970 = ROM.rd(cppVar_48969);
	cppVar_48971 = (cppVar_48970 >> 3) & cppMask_un_5_;
	cppVar_48972 = (cppVar_48971 & cppMask_un_5_);
	cppVar_48973 = cppVar_48972 + 32;
	cppVar_48973 = (cppVar_48973 & cppMask_un_8_);
	cppVar_48960 = cppVar_48973;
	}
	cppVar_48975 = (cppVar_48960 == 136);
	if (cppVar_48975) {
	cppVar_48959 = TCON;
	} else {
	cppVar_48978 = PC + 1;
	cppVar_48978 = (cppVar_48978 & cppMask_un_16_);
	cppVar_48979 = ROM.rd(cppVar_48978);
	cppVar_48980 = (cppVar_48979 >> 7) & cppMask_un_1_;
	cppVar_48981 = (cppVar_48980 == 1);
	if (cppVar_48981) {
	cppVar_48982 = PC + 1;
	cppVar_48982 = (cppVar_48982 & cppMask_un_16_);
	cppVar_48983 = ROM.rd(cppVar_48982);
	cppVar_48984 = (cppVar_48983 >> 3) & cppMask_un_5_;
	cppVar_48985 = (cppVar_48984 << 3) | 0;
	cppVar_48985 = (cppVar_48985 & cppMask_un_8_);
	cppVar_48977 = cppVar_48985;
	} else {
	cppVar_48986 = PC + 1;
	cppVar_48986 = (cppVar_48986 & cppMask_un_16_);
	cppVar_48987 = ROM.rd(cppVar_48986);
	cppVar_48988 = (cppVar_48987 >> 3) & cppMask_un_5_;
	cppVar_48989 = (cppVar_48988 & cppMask_un_5_);
	cppVar_48990 = cppVar_48989 + 32;
	cppVar_48990 = (cppVar_48990 & cppMask_un_8_);
	cppVar_48977 = cppVar_48990;
	}
	cppVar_48992 = (cppVar_48977 == 137);
	if (cppVar_48992) {
	cppVar_48976 = TMOD;
	} else {
	cppVar_48995 = PC + 1;
	cppVar_48995 = (cppVar_48995 & cppMask_un_16_);
	cppVar_48996 = ROM.rd(cppVar_48995);
	cppVar_48997 = (cppVar_48996 >> 7) & cppMask_un_1_;
	cppVar_48998 = (cppVar_48997 == 1);
	if (cppVar_48998) {
	cppVar_48999 = PC + 1;
	cppVar_48999 = (cppVar_48999 & cppMask_un_16_);
	cppVar_49000 = ROM.rd(cppVar_48999);
	cppVar_49001 = (cppVar_49000 >> 3) & cppMask_un_5_;
	cppVar_49002 = (cppVar_49001 << 3) | 0;
	cppVar_49002 = (cppVar_49002 & cppMask_un_8_);
	cppVar_48994 = cppVar_49002;
	} else {
	cppVar_49003 = PC + 1;
	cppVar_49003 = (cppVar_49003 & cppMask_un_16_);
	cppVar_49004 = ROM.rd(cppVar_49003);
	cppVar_49005 = (cppVar_49004 >> 3) & cppMask_un_5_;
	cppVar_49006 = (cppVar_49005 & cppMask_un_5_);
	cppVar_49007 = cppVar_49006 + 32;
	cppVar_49007 = (cppVar_49007 & cppMask_un_8_);
	cppVar_48994 = cppVar_49007;
	}
	cppVar_49009 = (cppVar_48994 == 138);
	if (cppVar_49009) {
	cppVar_48993 = TL0;
	} else {
	cppVar_49012 = PC + 1;
	cppVar_49012 = (cppVar_49012 & cppMask_un_16_);
	cppVar_49013 = ROM.rd(cppVar_49012);
	cppVar_49014 = (cppVar_49013 >> 7) & cppMask_un_1_;
	cppVar_49015 = (cppVar_49014 == 1);
	if (cppVar_49015) {
	cppVar_49016 = PC + 1;
	cppVar_49016 = (cppVar_49016 & cppMask_un_16_);
	cppVar_49017 = ROM.rd(cppVar_49016);
	cppVar_49018 = (cppVar_49017 >> 3) & cppMask_un_5_;
	cppVar_49019 = (cppVar_49018 << 3) | 0;
	cppVar_49019 = (cppVar_49019 & cppMask_un_8_);
	cppVar_49011 = cppVar_49019;
	} else {
	cppVar_49020 = PC + 1;
	cppVar_49020 = (cppVar_49020 & cppMask_un_16_);
	cppVar_49021 = ROM.rd(cppVar_49020);
	cppVar_49022 = (cppVar_49021 >> 3) & cppMask_un_5_;
	cppVar_49023 = (cppVar_49022 & cppMask_un_5_);
	cppVar_49024 = cppVar_49023 + 32;
	cppVar_49024 = (cppVar_49024 & cppMask_un_8_);
	cppVar_49011 = cppVar_49024;
	}
	cppVar_49026 = (cppVar_49011 == 140);
	if (cppVar_49026) {
	cppVar_49010 = TH0;
	} else {
	cppVar_49029 = PC + 1;
	cppVar_49029 = (cppVar_49029 & cppMask_un_16_);
	cppVar_49030 = ROM.rd(cppVar_49029);
	cppVar_49031 = (cppVar_49030 >> 7) & cppMask_un_1_;
	cppVar_49032 = (cppVar_49031 == 1);
	if (cppVar_49032) {
	cppVar_49033 = PC + 1;
	cppVar_49033 = (cppVar_49033 & cppMask_un_16_);
	cppVar_49034 = ROM.rd(cppVar_49033);
	cppVar_49035 = (cppVar_49034 >> 3) & cppMask_un_5_;
	cppVar_49036 = (cppVar_49035 << 3) | 0;
	cppVar_49036 = (cppVar_49036 & cppMask_un_8_);
	cppVar_49028 = cppVar_49036;
	} else {
	cppVar_49037 = PC + 1;
	cppVar_49037 = (cppVar_49037 & cppMask_un_16_);
	cppVar_49038 = ROM.rd(cppVar_49037);
	cppVar_49039 = (cppVar_49038 >> 3) & cppMask_un_5_;
	cppVar_49040 = (cppVar_49039 & cppMask_un_5_);
	cppVar_49041 = cppVar_49040 + 32;
	cppVar_49041 = (cppVar_49041 & cppMask_un_8_);
	cppVar_49028 = cppVar_49041;
	}
	cppVar_49043 = (cppVar_49028 == 139);
	if (cppVar_49043) {
	cppVar_49027 = TL1;
	} else {
	cppVar_49046 = PC + 1;
	cppVar_49046 = (cppVar_49046 & cppMask_un_16_);
	cppVar_49047 = ROM.rd(cppVar_49046);
	cppVar_49048 = (cppVar_49047 >> 7) & cppMask_un_1_;
	cppVar_49049 = (cppVar_49048 == 1);
	if (cppVar_49049) {
	cppVar_49050 = PC + 1;
	cppVar_49050 = (cppVar_49050 & cppMask_un_16_);
	cppVar_49051 = ROM.rd(cppVar_49050);
	cppVar_49052 = (cppVar_49051 >> 3) & cppMask_un_5_;
	cppVar_49053 = (cppVar_49052 << 3) | 0;
	cppVar_49053 = (cppVar_49053 & cppMask_un_8_);
	cppVar_49045 = cppVar_49053;
	} else {
	cppVar_49054 = PC + 1;
	cppVar_49054 = (cppVar_49054 & cppMask_un_16_);
	cppVar_49055 = ROM.rd(cppVar_49054);
	cppVar_49056 = (cppVar_49055 >> 3) & cppMask_un_5_;
	cppVar_49057 = (cppVar_49056 & cppMask_un_5_);
	cppVar_49058 = cppVar_49057 + 32;
	cppVar_49058 = (cppVar_49058 & cppMask_un_8_);
	cppVar_49045 = cppVar_49058;
	}
	cppVar_49060 = (cppVar_49045 == 141);
	if (cppVar_49060) {
	cppVar_49044 = TH1;
	} else {
	cppVar_49063 = PC + 1;
	cppVar_49063 = (cppVar_49063 & cppMask_un_16_);
	cppVar_49064 = ROM.rd(cppVar_49063);
	cppVar_49065 = (cppVar_49064 >> 7) & cppMask_un_1_;
	cppVar_49066 = (cppVar_49065 == 1);
	if (cppVar_49066) {
	cppVar_49067 = PC + 1;
	cppVar_49067 = (cppVar_49067 & cppMask_un_16_);
	cppVar_49068 = ROM.rd(cppVar_49067);
	cppVar_49069 = (cppVar_49068 >> 3) & cppMask_un_5_;
	cppVar_49070 = (cppVar_49069 << 3) | 0;
	cppVar_49070 = (cppVar_49070 & cppMask_un_8_);
	cppVar_49062 = cppVar_49070;
	} else {
	cppVar_49071 = PC + 1;
	cppVar_49071 = (cppVar_49071 & cppMask_un_16_);
	cppVar_49072 = ROM.rd(cppVar_49071);
	cppVar_49073 = (cppVar_49072 >> 3) & cppMask_un_5_;
	cppVar_49074 = (cppVar_49073 & cppMask_un_5_);
	cppVar_49075 = cppVar_49074 + 32;
	cppVar_49075 = (cppVar_49075 & cppMask_un_8_);
	cppVar_49062 = cppVar_49075;
	}
	cppVar_49077 = (cppVar_49062 == 144);
	if (cppVar_49077) {
	cppVar_49061 = P1;
	} else {
	cppVar_49080 = PC + 1;
	cppVar_49080 = (cppVar_49080 & cppMask_un_16_);
	cppVar_49081 = ROM.rd(cppVar_49080);
	cppVar_49082 = (cppVar_49081 >> 7) & cppMask_un_1_;
	cppVar_49083 = (cppVar_49082 == 1);
	if (cppVar_49083) {
	cppVar_49084 = PC + 1;
	cppVar_49084 = (cppVar_49084 & cppMask_un_16_);
	cppVar_49085 = ROM.rd(cppVar_49084);
	cppVar_49086 = (cppVar_49085 >> 3) & cppMask_un_5_;
	cppVar_49087 = (cppVar_49086 << 3) | 0;
	cppVar_49087 = (cppVar_49087 & cppMask_un_8_);
	cppVar_49079 = cppVar_49087;
	} else {
	cppVar_49088 = PC + 1;
	cppVar_49088 = (cppVar_49088 & cppMask_un_16_);
	cppVar_49089 = ROM.rd(cppVar_49088);
	cppVar_49090 = (cppVar_49089 >> 3) & cppMask_un_5_;
	cppVar_49091 = (cppVar_49090 & cppMask_un_5_);
	cppVar_49092 = cppVar_49091 + 32;
	cppVar_49092 = (cppVar_49092 & cppMask_un_8_);
	cppVar_49079 = cppVar_49092;
	}
	cppVar_49094 = (cppVar_49079 == 152);
	if (cppVar_49094) {
	cppVar_49078 = SCON;
	} else {
	cppVar_49097 = PC + 1;
	cppVar_49097 = (cppVar_49097 & cppMask_un_16_);
	cppVar_49098 = ROM.rd(cppVar_49097);
	cppVar_49099 = (cppVar_49098 >> 7) & cppMask_un_1_;
	cppVar_49100 = (cppVar_49099 == 1);
	if (cppVar_49100) {
	cppVar_49101 = PC + 1;
	cppVar_49101 = (cppVar_49101 & cppMask_un_16_);
	cppVar_49102 = ROM.rd(cppVar_49101);
	cppVar_49103 = (cppVar_49102 >> 3) & cppMask_un_5_;
	cppVar_49104 = (cppVar_49103 << 3) | 0;
	cppVar_49104 = (cppVar_49104 & cppMask_un_8_);
	cppVar_49096 = cppVar_49104;
	} else {
	cppVar_49105 = PC + 1;
	cppVar_49105 = (cppVar_49105 & cppMask_un_16_);
	cppVar_49106 = ROM.rd(cppVar_49105);
	cppVar_49107 = (cppVar_49106 >> 3) & cppMask_un_5_;
	cppVar_49108 = (cppVar_49107 & cppMask_un_5_);
	cppVar_49109 = cppVar_49108 + 32;
	cppVar_49109 = (cppVar_49109 & cppMask_un_8_);
	cppVar_49096 = cppVar_49109;
	}
	cppVar_49111 = (cppVar_49096 == 153);
	if (cppVar_49111) {
	cppVar_49095 = SBUF;
	} else {
	cppVar_49114 = PC + 1;
	cppVar_49114 = (cppVar_49114 & cppMask_un_16_);
	cppVar_49115 = ROM.rd(cppVar_49114);
	cppVar_49116 = (cppVar_49115 >> 7) & cppMask_un_1_;
	cppVar_49117 = (cppVar_49116 == 1);
	if (cppVar_49117) {
	cppVar_49118 = PC + 1;
	cppVar_49118 = (cppVar_49118 & cppMask_un_16_);
	cppVar_49119 = ROM.rd(cppVar_49118);
	cppVar_49120 = (cppVar_49119 >> 3) & cppMask_un_5_;
	cppVar_49121 = (cppVar_49120 << 3) | 0;
	cppVar_49121 = (cppVar_49121 & cppMask_un_8_);
	cppVar_49113 = cppVar_49121;
	} else {
	cppVar_49122 = PC + 1;
	cppVar_49122 = (cppVar_49122 & cppMask_un_16_);
	cppVar_49123 = ROM.rd(cppVar_49122);
	cppVar_49124 = (cppVar_49123 >> 3) & cppMask_un_5_;
	cppVar_49125 = (cppVar_49124 & cppMask_un_5_);
	cppVar_49126 = cppVar_49125 + 32;
	cppVar_49126 = (cppVar_49126 & cppMask_un_8_);
	cppVar_49113 = cppVar_49126;
	}
	cppVar_49128 = (cppVar_49113 == 160);
	if (cppVar_49128) {
	cppVar_49112 = P2;
	} else {
	cppVar_49131 = PC + 1;
	cppVar_49131 = (cppVar_49131 & cppMask_un_16_);
	cppVar_49132 = ROM.rd(cppVar_49131);
	cppVar_49133 = (cppVar_49132 >> 7) & cppMask_un_1_;
	cppVar_49134 = (cppVar_49133 == 1);
	if (cppVar_49134) {
	cppVar_49135 = PC + 1;
	cppVar_49135 = (cppVar_49135 & cppMask_un_16_);
	cppVar_49136 = ROM.rd(cppVar_49135);
	cppVar_49137 = (cppVar_49136 >> 3) & cppMask_un_5_;
	cppVar_49138 = (cppVar_49137 << 3) | 0;
	cppVar_49138 = (cppVar_49138 & cppMask_un_8_);
	cppVar_49130 = cppVar_49138;
	} else {
	cppVar_49139 = PC + 1;
	cppVar_49139 = (cppVar_49139 & cppMask_un_16_);
	cppVar_49140 = ROM.rd(cppVar_49139);
	cppVar_49141 = (cppVar_49140 >> 3) & cppMask_un_5_;
	cppVar_49142 = (cppVar_49141 & cppMask_un_5_);
	cppVar_49143 = cppVar_49142 + 32;
	cppVar_49143 = (cppVar_49143 & cppMask_un_8_);
	cppVar_49130 = cppVar_49143;
	}
	cppVar_49145 = (cppVar_49130 == 168);
	if (cppVar_49145) {
	cppVar_49129 = IE;
	} else {
	cppVar_49148 = PC + 1;
	cppVar_49148 = (cppVar_49148 & cppMask_un_16_);
	cppVar_49149 = ROM.rd(cppVar_49148);
	cppVar_49150 = (cppVar_49149 >> 7) & cppMask_un_1_;
	cppVar_49151 = (cppVar_49150 == 1);
	if (cppVar_49151) {
	cppVar_49152 = PC + 1;
	cppVar_49152 = (cppVar_49152 & cppMask_un_16_);
	cppVar_49153 = ROM.rd(cppVar_49152);
	cppVar_49154 = (cppVar_49153 >> 3) & cppMask_un_5_;
	cppVar_49155 = (cppVar_49154 << 3) | 0;
	cppVar_49155 = (cppVar_49155 & cppMask_un_8_);
	cppVar_49147 = cppVar_49155;
	} else {
	cppVar_49156 = PC + 1;
	cppVar_49156 = (cppVar_49156 & cppMask_un_16_);
	cppVar_49157 = ROM.rd(cppVar_49156);
	cppVar_49158 = (cppVar_49157 >> 3) & cppMask_un_5_;
	cppVar_49159 = (cppVar_49158 & cppMask_un_5_);
	cppVar_49160 = cppVar_49159 + 32;
	cppVar_49160 = (cppVar_49160 & cppMask_un_8_);
	cppVar_49147 = cppVar_49160;
	}
	cppVar_49162 = (cppVar_49147 == 176);
	if (cppVar_49162) {
	cppVar_49146 = P3;
	} else {
	cppVar_49165 = PC + 1;
	cppVar_49165 = (cppVar_49165 & cppMask_un_16_);
	cppVar_49166 = ROM.rd(cppVar_49165);
	cppVar_49167 = (cppVar_49166 >> 7) & cppMask_un_1_;
	cppVar_49168 = (cppVar_49167 == 1);
	if (cppVar_49168) {
	cppVar_49169 = PC + 1;
	cppVar_49169 = (cppVar_49169 & cppMask_un_16_);
	cppVar_49170 = ROM.rd(cppVar_49169);
	cppVar_49171 = (cppVar_49170 >> 3) & cppMask_un_5_;
	cppVar_49172 = (cppVar_49171 << 3) | 0;
	cppVar_49172 = (cppVar_49172 & cppMask_un_8_);
	cppVar_49164 = cppVar_49172;
	} else {
	cppVar_49173 = PC + 1;
	cppVar_49173 = (cppVar_49173 & cppMask_un_16_);
	cppVar_49174 = ROM.rd(cppVar_49173);
	cppVar_49175 = (cppVar_49174 >> 3) & cppMask_un_5_;
	cppVar_49176 = (cppVar_49175 & cppMask_un_5_);
	cppVar_49177 = cppVar_49176 + 32;
	cppVar_49177 = (cppVar_49177 & cppMask_un_8_);
	cppVar_49164 = cppVar_49177;
	}
	cppVar_49179 = (cppVar_49164 == 184);
	if (cppVar_49179) {
	cppVar_49163 = IP;
	} else {
	cppVar_49182 = PC + 1;
	cppVar_49182 = (cppVar_49182 & cppMask_un_16_);
	cppVar_49183 = ROM.rd(cppVar_49182);
	cppVar_49184 = (cppVar_49183 >> 7) & cppMask_un_1_;
	cppVar_49185 = (cppVar_49184 == 1);
	if (cppVar_49185) {
	cppVar_49186 = PC + 1;
	cppVar_49186 = (cppVar_49186 & cppMask_un_16_);
	cppVar_49187 = ROM.rd(cppVar_49186);
	cppVar_49188 = (cppVar_49187 >> 3) & cppMask_un_5_;
	cppVar_49189 = (cppVar_49188 << 3) | 0;
	cppVar_49189 = (cppVar_49189 & cppMask_un_8_);
	cppVar_49181 = cppVar_49189;
	} else {
	cppVar_49190 = PC + 1;
	cppVar_49190 = (cppVar_49190 & cppMask_un_16_);
	cppVar_49191 = ROM.rd(cppVar_49190);
	cppVar_49192 = (cppVar_49191 >> 3) & cppMask_un_5_;
	cppVar_49193 = (cppVar_49192 & cppMask_un_5_);
	cppVar_49194 = cppVar_49193 + 32;
	cppVar_49194 = (cppVar_49194 & cppMask_un_8_);
	cppVar_49181 = cppVar_49194;
	}
	cppVar_49196 = (cppVar_49181 == 208);
	if (cppVar_49196) {
	cppVar_49180 = PSW;
	} else {
	cppVar_49199 = PC + 1;
	cppVar_49199 = (cppVar_49199 & cppMask_un_16_);
	cppVar_49200 = ROM.rd(cppVar_49199);
	cppVar_49201 = (cppVar_49200 >> 7) & cppMask_un_1_;
	cppVar_49202 = (cppVar_49201 == 1);
	if (cppVar_49202) {
	cppVar_49203 = PC + 1;
	cppVar_49203 = (cppVar_49203 & cppMask_un_16_);
	cppVar_49204 = ROM.rd(cppVar_49203);
	cppVar_49205 = (cppVar_49204 >> 3) & cppMask_un_5_;
	cppVar_49206 = (cppVar_49205 << 3) | 0;
	cppVar_49206 = (cppVar_49206 & cppMask_un_8_);
	cppVar_49198 = cppVar_49206;
	} else {
	cppVar_49207 = PC + 1;
	cppVar_49207 = (cppVar_49207 & cppMask_un_16_);
	cppVar_49208 = ROM.rd(cppVar_49207);
	cppVar_49209 = (cppVar_49208 >> 3) & cppMask_un_5_;
	cppVar_49210 = (cppVar_49209 & cppMask_un_5_);
	cppVar_49211 = cppVar_49210 + 32;
	cppVar_49211 = (cppVar_49211 & cppMask_un_8_);
	cppVar_49198 = cppVar_49211;
	}
	cppVar_49213 = (cppVar_49198 == 224);
	if (cppVar_49213) {
	cppVar_49197 = ACC;
	} else {
	cppVar_49216 = PC + 1;
	cppVar_49216 = (cppVar_49216 & cppMask_un_16_);
	cppVar_49217 = ROM.rd(cppVar_49216);
	cppVar_49218 = (cppVar_49217 >> 7) & cppMask_un_1_;
	cppVar_49219 = (cppVar_49218 == 1);
	if (cppVar_49219) {
	cppVar_49220 = PC + 1;
	cppVar_49220 = (cppVar_49220 & cppMask_un_16_);
	cppVar_49221 = ROM.rd(cppVar_49220);
	cppVar_49222 = (cppVar_49221 >> 3) & cppMask_un_5_;
	cppVar_49223 = (cppVar_49222 << 3) | 0;
	cppVar_49223 = (cppVar_49223 & cppMask_un_8_);
	cppVar_49215 = cppVar_49223;
	} else {
	cppVar_49224 = PC + 1;
	cppVar_49224 = (cppVar_49224 & cppMask_un_16_);
	cppVar_49225 = ROM.rd(cppVar_49224);
	cppVar_49226 = (cppVar_49225 >> 3) & cppMask_un_5_;
	cppVar_49227 = (cppVar_49226 & cppMask_un_5_);
	cppVar_49228 = cppVar_49227 + 32;
	cppVar_49228 = (cppVar_49228 & cppMask_un_8_);
	cppVar_49215 = cppVar_49228;
	}
	cppVar_49230 = (cppVar_49215 == 240);
	if (cppVar_49230) {
	cppVar_49214 = B;
	} else {
	cppVar_49214 = 0;
	}
	cppVar_49197 = cppVar_49214;
	}
	cppVar_49180 = cppVar_49197;
	}
	cppVar_49163 = cppVar_49180;
	}
	cppVar_49146 = cppVar_49163;
	}
	cppVar_49129 = cppVar_49146;
	}
	cppVar_49112 = cppVar_49129;
	}
	cppVar_49095 = cppVar_49112;
	}
	cppVar_49078 = cppVar_49095;
	}
	cppVar_49061 = cppVar_49078;
	}
	cppVar_49044 = cppVar_49061;
	}
	cppVar_49027 = cppVar_49044;
	}
	cppVar_49010 = cppVar_49027;
	}
	cppVar_48993 = cppVar_49010;
	}
	cppVar_48976 = cppVar_48993;
	}
	cppVar_48959 = cppVar_48976;
	}
	cppVar_48942 = cppVar_48959;
	}
	cppVar_48925 = cppVar_48942;
	}
	cppVar_48908 = cppVar_48925;
	}
	cppVar_48891 = cppVar_48908;
	}
	cppVar_48874 = cppVar_48891;
	}
	cppVar_48837 = cppVar_48874;
	}
	cppVar_49232 = PC + 1;
	cppVar_49232 = (cppVar_49232 & cppMask_un_16_);
	cppVar_49233 = ROM.rd(cppVar_49232);
	cppVar_49234 = (cppVar_49233 >> 0) & cppMask_un_3_;
	cppVar_49235 = (cppVar_48837 >> static_cast<unsigned>(cppVar_49234)) & 0x1;
	cppVar_49236 = (PSW >> 0) & cppMask_un_7_;
	cppVar_49237 = (cppVar_49235 << 7) | cppVar_49236;
	cppVar_49237 = (cppVar_49237 & cppMask_un_8_);
	cppVar_48833 = cppVar_49237;
	} else {
	cppVar_49239 = ROM.rd(PC);
	cppVar_49241 = (cppVar_49239 == 160);
	if (cppVar_49241) {
	cppVar_49242 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49246 = PC + 1;
	cppVar_49246 = (cppVar_49246 & cppMask_un_16_);
	cppVar_49247 = ROM.rd(cppVar_49246);
	cppVar_49248 = (cppVar_49247 >> 7) & cppMask_un_1_;
	cppVar_49250 = (cppVar_49248 == 1);
	if (cppVar_49250) {
	cppVar_49251 = PC + 1;
	cppVar_49251 = (cppVar_49251 & cppMask_un_16_);
	cppVar_49252 = ROM.rd(cppVar_49251);
	cppVar_49253 = (cppVar_49252 >> 3) & cppMask_un_5_;
	cppVar_49255 = (cppVar_49253 << 3) | 0;
	cppVar_49255 = (cppVar_49255 & cppMask_un_8_);
	cppVar_49244 = cppVar_49255;
	} else {
	cppVar_49256 = PC + 1;
	cppVar_49256 = (cppVar_49256 & cppMask_un_16_);
	cppVar_49257 = ROM.rd(cppVar_49256);
	cppVar_49258 = (cppVar_49257 >> 3) & cppMask_un_5_;
	cppVar_49259 = (cppVar_49258 & cppMask_un_5_);
	cppVar_49261 = cppVar_49259 + 32;
	cppVar_49261 = (cppVar_49261 & cppMask_un_8_);
	cppVar_49244 = cppVar_49261;
	}
	cppVar_49262 = (cppVar_49244 >> 7) & cppMask_un_1_;
	cppVar_49264 = (cppVar_49262 == 0);
	if (cppVar_49264) {
	cppVar_49266 = PC + 1;
	cppVar_49266 = (cppVar_49266 & cppMask_un_16_);
	cppVar_49267 = ROM.rd(cppVar_49266);
	cppVar_49268 = (cppVar_49267 >> 7) & cppMask_un_1_;
	cppVar_49269 = (cppVar_49268 == 1);
	if (cppVar_49269) {
	cppVar_49270 = PC + 1;
	cppVar_49270 = (cppVar_49270 & cppMask_un_16_);
	cppVar_49271 = ROM.rd(cppVar_49270);
	cppVar_49272 = (cppVar_49271 >> 3) & cppMask_un_5_;
	cppVar_49273 = (cppVar_49272 << 3) | 0;
	cppVar_49273 = (cppVar_49273 & cppMask_un_8_);
	cppVar_49265 = cppVar_49273;
	} else {
	cppVar_49274 = PC + 1;
	cppVar_49274 = (cppVar_49274 & cppMask_un_16_);
	cppVar_49275 = ROM.rd(cppVar_49274);
	cppVar_49276 = (cppVar_49275 >> 3) & cppMask_un_5_;
	cppVar_49277 = (cppVar_49276 & cppMask_un_5_);
	cppVar_49278 = cppVar_49277 + 32;
	cppVar_49278 = (cppVar_49278 & cppMask_un_8_);
	cppVar_49265 = cppVar_49278;
	}
	cppVar_49279 = IRAM.rd(cppVar_49265);
	cppVar_49243 = cppVar_49279;
	} else {
	cppVar_49282 = PC + 1;
	cppVar_49282 = (cppVar_49282 & cppMask_un_16_);
	cppVar_49283 = ROM.rd(cppVar_49282);
	cppVar_49284 = (cppVar_49283 >> 7) & cppMask_un_1_;
	cppVar_49285 = (cppVar_49284 == 1);
	if (cppVar_49285) {
	cppVar_49286 = PC + 1;
	cppVar_49286 = (cppVar_49286 & cppMask_un_16_);
	cppVar_49287 = ROM.rd(cppVar_49286);
	cppVar_49288 = (cppVar_49287 >> 3) & cppMask_un_5_;
	cppVar_49289 = (cppVar_49288 << 3) | 0;
	cppVar_49289 = (cppVar_49289 & cppMask_un_8_);
	cppVar_49281 = cppVar_49289;
	} else {
	cppVar_49290 = PC + 1;
	cppVar_49290 = (cppVar_49290 & cppMask_un_16_);
	cppVar_49291 = ROM.rd(cppVar_49290);
	cppVar_49292 = (cppVar_49291 >> 3) & cppMask_un_5_;
	cppVar_49293 = (cppVar_49292 & cppMask_un_5_);
	cppVar_49294 = cppVar_49293 + 32;
	cppVar_49294 = (cppVar_49294 & cppMask_un_8_);
	cppVar_49281 = cppVar_49294;
	}
	cppVar_49296 = (cppVar_49281 == 128);
	if (cppVar_49296) {
	cppVar_49280 = P0;
	} else {
	cppVar_49299 = PC + 1;
	cppVar_49299 = (cppVar_49299 & cppMask_un_16_);
	cppVar_49300 = ROM.rd(cppVar_49299);
	cppVar_49301 = (cppVar_49300 >> 7) & cppMask_un_1_;
	cppVar_49302 = (cppVar_49301 == 1);
	if (cppVar_49302) {
	cppVar_49303 = PC + 1;
	cppVar_49303 = (cppVar_49303 & cppMask_un_16_);
	cppVar_49304 = ROM.rd(cppVar_49303);
	cppVar_49305 = (cppVar_49304 >> 3) & cppMask_un_5_;
	cppVar_49306 = (cppVar_49305 << 3) | 0;
	cppVar_49306 = (cppVar_49306 & cppMask_un_8_);
	cppVar_49298 = cppVar_49306;
	} else {
	cppVar_49307 = PC + 1;
	cppVar_49307 = (cppVar_49307 & cppMask_un_16_);
	cppVar_49308 = ROM.rd(cppVar_49307);
	cppVar_49309 = (cppVar_49308 >> 3) & cppMask_un_5_;
	cppVar_49310 = (cppVar_49309 & cppMask_un_5_);
	cppVar_49311 = cppVar_49310 + 32;
	cppVar_49311 = (cppVar_49311 & cppMask_un_8_);
	cppVar_49298 = cppVar_49311;
	}
	cppVar_49313 = (cppVar_49298 == 129);
	if (cppVar_49313) {
	cppVar_49297 = SP;
	} else {
	cppVar_49316 = PC + 1;
	cppVar_49316 = (cppVar_49316 & cppMask_un_16_);
	cppVar_49317 = ROM.rd(cppVar_49316);
	cppVar_49318 = (cppVar_49317 >> 7) & cppMask_un_1_;
	cppVar_49319 = (cppVar_49318 == 1);
	if (cppVar_49319) {
	cppVar_49320 = PC + 1;
	cppVar_49320 = (cppVar_49320 & cppMask_un_16_);
	cppVar_49321 = ROM.rd(cppVar_49320);
	cppVar_49322 = (cppVar_49321 >> 3) & cppMask_un_5_;
	cppVar_49323 = (cppVar_49322 << 3) | 0;
	cppVar_49323 = (cppVar_49323 & cppMask_un_8_);
	cppVar_49315 = cppVar_49323;
	} else {
	cppVar_49324 = PC + 1;
	cppVar_49324 = (cppVar_49324 & cppMask_un_16_);
	cppVar_49325 = ROM.rd(cppVar_49324);
	cppVar_49326 = (cppVar_49325 >> 3) & cppMask_un_5_;
	cppVar_49327 = (cppVar_49326 & cppMask_un_5_);
	cppVar_49328 = cppVar_49327 + 32;
	cppVar_49328 = (cppVar_49328 & cppMask_un_8_);
	cppVar_49315 = cppVar_49328;
	}
	cppVar_49330 = (cppVar_49315 == 130);
	if (cppVar_49330) {
	cppVar_49314 = DPL;
	} else {
	cppVar_49333 = PC + 1;
	cppVar_49333 = (cppVar_49333 & cppMask_un_16_);
	cppVar_49334 = ROM.rd(cppVar_49333);
	cppVar_49335 = (cppVar_49334 >> 7) & cppMask_un_1_;
	cppVar_49336 = (cppVar_49335 == 1);
	if (cppVar_49336) {
	cppVar_49337 = PC + 1;
	cppVar_49337 = (cppVar_49337 & cppMask_un_16_);
	cppVar_49338 = ROM.rd(cppVar_49337);
	cppVar_49339 = (cppVar_49338 >> 3) & cppMask_un_5_;
	cppVar_49340 = (cppVar_49339 << 3) | 0;
	cppVar_49340 = (cppVar_49340 & cppMask_un_8_);
	cppVar_49332 = cppVar_49340;
	} else {
	cppVar_49341 = PC + 1;
	cppVar_49341 = (cppVar_49341 & cppMask_un_16_);
	cppVar_49342 = ROM.rd(cppVar_49341);
	cppVar_49343 = (cppVar_49342 >> 3) & cppMask_un_5_;
	cppVar_49344 = (cppVar_49343 & cppMask_un_5_);
	cppVar_49345 = cppVar_49344 + 32;
	cppVar_49345 = (cppVar_49345 & cppMask_un_8_);
	cppVar_49332 = cppVar_49345;
	}
	cppVar_49347 = (cppVar_49332 == 131);
	if (cppVar_49347) {
	cppVar_49331 = DPH;
	} else {
	cppVar_49350 = PC + 1;
	cppVar_49350 = (cppVar_49350 & cppMask_un_16_);
	cppVar_49351 = ROM.rd(cppVar_49350);
	cppVar_49352 = (cppVar_49351 >> 7) & cppMask_un_1_;
	cppVar_49353 = (cppVar_49352 == 1);
	if (cppVar_49353) {
	cppVar_49354 = PC + 1;
	cppVar_49354 = (cppVar_49354 & cppMask_un_16_);
	cppVar_49355 = ROM.rd(cppVar_49354);
	cppVar_49356 = (cppVar_49355 >> 3) & cppMask_un_5_;
	cppVar_49357 = (cppVar_49356 << 3) | 0;
	cppVar_49357 = (cppVar_49357 & cppMask_un_8_);
	cppVar_49349 = cppVar_49357;
	} else {
	cppVar_49358 = PC + 1;
	cppVar_49358 = (cppVar_49358 & cppMask_un_16_);
	cppVar_49359 = ROM.rd(cppVar_49358);
	cppVar_49360 = (cppVar_49359 >> 3) & cppMask_un_5_;
	cppVar_49361 = (cppVar_49360 & cppMask_un_5_);
	cppVar_49362 = cppVar_49361 + 32;
	cppVar_49362 = (cppVar_49362 & cppMask_un_8_);
	cppVar_49349 = cppVar_49362;
	}
	cppVar_49364 = (cppVar_49349 == 135);
	if (cppVar_49364) {
	cppVar_49348 = PCON;
	} else {
	cppVar_49367 = PC + 1;
	cppVar_49367 = (cppVar_49367 & cppMask_un_16_);
	cppVar_49368 = ROM.rd(cppVar_49367);
	cppVar_49369 = (cppVar_49368 >> 7) & cppMask_un_1_;
	cppVar_49370 = (cppVar_49369 == 1);
	if (cppVar_49370) {
	cppVar_49371 = PC + 1;
	cppVar_49371 = (cppVar_49371 & cppMask_un_16_);
	cppVar_49372 = ROM.rd(cppVar_49371);
	cppVar_49373 = (cppVar_49372 >> 3) & cppMask_un_5_;
	cppVar_49374 = (cppVar_49373 << 3) | 0;
	cppVar_49374 = (cppVar_49374 & cppMask_un_8_);
	cppVar_49366 = cppVar_49374;
	} else {
	cppVar_49375 = PC + 1;
	cppVar_49375 = (cppVar_49375 & cppMask_un_16_);
	cppVar_49376 = ROM.rd(cppVar_49375);
	cppVar_49377 = (cppVar_49376 >> 3) & cppMask_un_5_;
	cppVar_49378 = (cppVar_49377 & cppMask_un_5_);
	cppVar_49379 = cppVar_49378 + 32;
	cppVar_49379 = (cppVar_49379 & cppMask_un_8_);
	cppVar_49366 = cppVar_49379;
	}
	cppVar_49381 = (cppVar_49366 == 136);
	if (cppVar_49381) {
	cppVar_49365 = TCON;
	} else {
	cppVar_49384 = PC + 1;
	cppVar_49384 = (cppVar_49384 & cppMask_un_16_);
	cppVar_49385 = ROM.rd(cppVar_49384);
	cppVar_49386 = (cppVar_49385 >> 7) & cppMask_un_1_;
	cppVar_49387 = (cppVar_49386 == 1);
	if (cppVar_49387) {
	cppVar_49388 = PC + 1;
	cppVar_49388 = (cppVar_49388 & cppMask_un_16_);
	cppVar_49389 = ROM.rd(cppVar_49388);
	cppVar_49390 = (cppVar_49389 >> 3) & cppMask_un_5_;
	cppVar_49391 = (cppVar_49390 << 3) | 0;
	cppVar_49391 = (cppVar_49391 & cppMask_un_8_);
	cppVar_49383 = cppVar_49391;
	} else {
	cppVar_49392 = PC + 1;
	cppVar_49392 = (cppVar_49392 & cppMask_un_16_);
	cppVar_49393 = ROM.rd(cppVar_49392);
	cppVar_49394 = (cppVar_49393 >> 3) & cppMask_un_5_;
	cppVar_49395 = (cppVar_49394 & cppMask_un_5_);
	cppVar_49396 = cppVar_49395 + 32;
	cppVar_49396 = (cppVar_49396 & cppMask_un_8_);
	cppVar_49383 = cppVar_49396;
	}
	cppVar_49398 = (cppVar_49383 == 137);
	if (cppVar_49398) {
	cppVar_49382 = TMOD;
	} else {
	cppVar_49401 = PC + 1;
	cppVar_49401 = (cppVar_49401 & cppMask_un_16_);
	cppVar_49402 = ROM.rd(cppVar_49401);
	cppVar_49403 = (cppVar_49402 >> 7) & cppMask_un_1_;
	cppVar_49404 = (cppVar_49403 == 1);
	if (cppVar_49404) {
	cppVar_49405 = PC + 1;
	cppVar_49405 = (cppVar_49405 & cppMask_un_16_);
	cppVar_49406 = ROM.rd(cppVar_49405);
	cppVar_49407 = (cppVar_49406 >> 3) & cppMask_un_5_;
	cppVar_49408 = (cppVar_49407 << 3) | 0;
	cppVar_49408 = (cppVar_49408 & cppMask_un_8_);
	cppVar_49400 = cppVar_49408;
	} else {
	cppVar_49409 = PC + 1;
	cppVar_49409 = (cppVar_49409 & cppMask_un_16_);
	cppVar_49410 = ROM.rd(cppVar_49409);
	cppVar_49411 = (cppVar_49410 >> 3) & cppMask_un_5_;
	cppVar_49412 = (cppVar_49411 & cppMask_un_5_);
	cppVar_49413 = cppVar_49412 + 32;
	cppVar_49413 = (cppVar_49413 & cppMask_un_8_);
	cppVar_49400 = cppVar_49413;
	}
	cppVar_49415 = (cppVar_49400 == 138);
	if (cppVar_49415) {
	cppVar_49399 = TL0;
	} else {
	cppVar_49418 = PC + 1;
	cppVar_49418 = (cppVar_49418 & cppMask_un_16_);
	cppVar_49419 = ROM.rd(cppVar_49418);
	cppVar_49420 = (cppVar_49419 >> 7) & cppMask_un_1_;
	cppVar_49421 = (cppVar_49420 == 1);
	if (cppVar_49421) {
	cppVar_49422 = PC + 1;
	cppVar_49422 = (cppVar_49422 & cppMask_un_16_);
	cppVar_49423 = ROM.rd(cppVar_49422);
	cppVar_49424 = (cppVar_49423 >> 3) & cppMask_un_5_;
	cppVar_49425 = (cppVar_49424 << 3) | 0;
	cppVar_49425 = (cppVar_49425 & cppMask_un_8_);
	cppVar_49417 = cppVar_49425;
	} else {
	cppVar_49426 = PC + 1;
	cppVar_49426 = (cppVar_49426 & cppMask_un_16_);
	cppVar_49427 = ROM.rd(cppVar_49426);
	cppVar_49428 = (cppVar_49427 >> 3) & cppMask_un_5_;
	cppVar_49429 = (cppVar_49428 & cppMask_un_5_);
	cppVar_49430 = cppVar_49429 + 32;
	cppVar_49430 = (cppVar_49430 & cppMask_un_8_);
	cppVar_49417 = cppVar_49430;
	}
	cppVar_49432 = (cppVar_49417 == 140);
	if (cppVar_49432) {
	cppVar_49416 = TH0;
	} else {
	cppVar_49435 = PC + 1;
	cppVar_49435 = (cppVar_49435 & cppMask_un_16_);
	cppVar_49436 = ROM.rd(cppVar_49435);
	cppVar_49437 = (cppVar_49436 >> 7) & cppMask_un_1_;
	cppVar_49438 = (cppVar_49437 == 1);
	if (cppVar_49438) {
	cppVar_49439 = PC + 1;
	cppVar_49439 = (cppVar_49439 & cppMask_un_16_);
	cppVar_49440 = ROM.rd(cppVar_49439);
	cppVar_49441 = (cppVar_49440 >> 3) & cppMask_un_5_;
	cppVar_49442 = (cppVar_49441 << 3) | 0;
	cppVar_49442 = (cppVar_49442 & cppMask_un_8_);
	cppVar_49434 = cppVar_49442;
	} else {
	cppVar_49443 = PC + 1;
	cppVar_49443 = (cppVar_49443 & cppMask_un_16_);
	cppVar_49444 = ROM.rd(cppVar_49443);
	cppVar_49445 = (cppVar_49444 >> 3) & cppMask_un_5_;
	cppVar_49446 = (cppVar_49445 & cppMask_un_5_);
	cppVar_49447 = cppVar_49446 + 32;
	cppVar_49447 = (cppVar_49447 & cppMask_un_8_);
	cppVar_49434 = cppVar_49447;
	}
	cppVar_49449 = (cppVar_49434 == 139);
	if (cppVar_49449) {
	cppVar_49433 = TL1;
	} else {
	cppVar_49452 = PC + 1;
	cppVar_49452 = (cppVar_49452 & cppMask_un_16_);
	cppVar_49453 = ROM.rd(cppVar_49452);
	cppVar_49454 = (cppVar_49453 >> 7) & cppMask_un_1_;
	cppVar_49455 = (cppVar_49454 == 1);
	if (cppVar_49455) {
	cppVar_49456 = PC + 1;
	cppVar_49456 = (cppVar_49456 & cppMask_un_16_);
	cppVar_49457 = ROM.rd(cppVar_49456);
	cppVar_49458 = (cppVar_49457 >> 3) & cppMask_un_5_;
	cppVar_49459 = (cppVar_49458 << 3) | 0;
	cppVar_49459 = (cppVar_49459 & cppMask_un_8_);
	cppVar_49451 = cppVar_49459;
	} else {
	cppVar_49460 = PC + 1;
	cppVar_49460 = (cppVar_49460 & cppMask_un_16_);
	cppVar_49461 = ROM.rd(cppVar_49460);
	cppVar_49462 = (cppVar_49461 >> 3) & cppMask_un_5_;
	cppVar_49463 = (cppVar_49462 & cppMask_un_5_);
	cppVar_49464 = cppVar_49463 + 32;
	cppVar_49464 = (cppVar_49464 & cppMask_un_8_);
	cppVar_49451 = cppVar_49464;
	}
	cppVar_49466 = (cppVar_49451 == 141);
	if (cppVar_49466) {
	cppVar_49450 = TH1;
	} else {
	cppVar_49469 = PC + 1;
	cppVar_49469 = (cppVar_49469 & cppMask_un_16_);
	cppVar_49470 = ROM.rd(cppVar_49469);
	cppVar_49471 = (cppVar_49470 >> 7) & cppMask_un_1_;
	cppVar_49472 = (cppVar_49471 == 1);
	if (cppVar_49472) {
	cppVar_49473 = PC + 1;
	cppVar_49473 = (cppVar_49473 & cppMask_un_16_);
	cppVar_49474 = ROM.rd(cppVar_49473);
	cppVar_49475 = (cppVar_49474 >> 3) & cppMask_un_5_;
	cppVar_49476 = (cppVar_49475 << 3) | 0;
	cppVar_49476 = (cppVar_49476 & cppMask_un_8_);
	cppVar_49468 = cppVar_49476;
	} else {
	cppVar_49477 = PC + 1;
	cppVar_49477 = (cppVar_49477 & cppMask_un_16_);
	cppVar_49478 = ROM.rd(cppVar_49477);
	cppVar_49479 = (cppVar_49478 >> 3) & cppMask_un_5_;
	cppVar_49480 = (cppVar_49479 & cppMask_un_5_);
	cppVar_49481 = cppVar_49480 + 32;
	cppVar_49481 = (cppVar_49481 & cppMask_un_8_);
	cppVar_49468 = cppVar_49481;
	}
	cppVar_49483 = (cppVar_49468 == 144);
	if (cppVar_49483) {
	cppVar_49467 = P1;
	} else {
	cppVar_49486 = PC + 1;
	cppVar_49486 = (cppVar_49486 & cppMask_un_16_);
	cppVar_49487 = ROM.rd(cppVar_49486);
	cppVar_49488 = (cppVar_49487 >> 7) & cppMask_un_1_;
	cppVar_49489 = (cppVar_49488 == 1);
	if (cppVar_49489) {
	cppVar_49490 = PC + 1;
	cppVar_49490 = (cppVar_49490 & cppMask_un_16_);
	cppVar_49491 = ROM.rd(cppVar_49490);
	cppVar_49492 = (cppVar_49491 >> 3) & cppMask_un_5_;
	cppVar_49493 = (cppVar_49492 << 3) | 0;
	cppVar_49493 = (cppVar_49493 & cppMask_un_8_);
	cppVar_49485 = cppVar_49493;
	} else {
	cppVar_49494 = PC + 1;
	cppVar_49494 = (cppVar_49494 & cppMask_un_16_);
	cppVar_49495 = ROM.rd(cppVar_49494);
	cppVar_49496 = (cppVar_49495 >> 3) & cppMask_un_5_;
	cppVar_49497 = (cppVar_49496 & cppMask_un_5_);
	cppVar_49498 = cppVar_49497 + 32;
	cppVar_49498 = (cppVar_49498 & cppMask_un_8_);
	cppVar_49485 = cppVar_49498;
	}
	cppVar_49500 = (cppVar_49485 == 152);
	if (cppVar_49500) {
	cppVar_49484 = SCON;
	} else {
	cppVar_49503 = PC + 1;
	cppVar_49503 = (cppVar_49503 & cppMask_un_16_);
	cppVar_49504 = ROM.rd(cppVar_49503);
	cppVar_49505 = (cppVar_49504 >> 7) & cppMask_un_1_;
	cppVar_49506 = (cppVar_49505 == 1);
	if (cppVar_49506) {
	cppVar_49507 = PC + 1;
	cppVar_49507 = (cppVar_49507 & cppMask_un_16_);
	cppVar_49508 = ROM.rd(cppVar_49507);
	cppVar_49509 = (cppVar_49508 >> 3) & cppMask_un_5_;
	cppVar_49510 = (cppVar_49509 << 3) | 0;
	cppVar_49510 = (cppVar_49510 & cppMask_un_8_);
	cppVar_49502 = cppVar_49510;
	} else {
	cppVar_49511 = PC + 1;
	cppVar_49511 = (cppVar_49511 & cppMask_un_16_);
	cppVar_49512 = ROM.rd(cppVar_49511);
	cppVar_49513 = (cppVar_49512 >> 3) & cppMask_un_5_;
	cppVar_49514 = (cppVar_49513 & cppMask_un_5_);
	cppVar_49515 = cppVar_49514 + 32;
	cppVar_49515 = (cppVar_49515 & cppMask_un_8_);
	cppVar_49502 = cppVar_49515;
	}
	cppVar_49517 = (cppVar_49502 == 153);
	if (cppVar_49517) {
	cppVar_49501 = SBUF;
	} else {
	cppVar_49520 = PC + 1;
	cppVar_49520 = (cppVar_49520 & cppMask_un_16_);
	cppVar_49521 = ROM.rd(cppVar_49520);
	cppVar_49522 = (cppVar_49521 >> 7) & cppMask_un_1_;
	cppVar_49523 = (cppVar_49522 == 1);
	if (cppVar_49523) {
	cppVar_49524 = PC + 1;
	cppVar_49524 = (cppVar_49524 & cppMask_un_16_);
	cppVar_49525 = ROM.rd(cppVar_49524);
	cppVar_49526 = (cppVar_49525 >> 3) & cppMask_un_5_;
	cppVar_49527 = (cppVar_49526 << 3) | 0;
	cppVar_49527 = (cppVar_49527 & cppMask_un_8_);
	cppVar_49519 = cppVar_49527;
	} else {
	cppVar_49528 = PC + 1;
	cppVar_49528 = (cppVar_49528 & cppMask_un_16_);
	cppVar_49529 = ROM.rd(cppVar_49528);
	cppVar_49530 = (cppVar_49529 >> 3) & cppMask_un_5_;
	cppVar_49531 = (cppVar_49530 & cppMask_un_5_);
	cppVar_49532 = cppVar_49531 + 32;
	cppVar_49532 = (cppVar_49532 & cppMask_un_8_);
	cppVar_49519 = cppVar_49532;
	}
	cppVar_49534 = (cppVar_49519 == 160);
	if (cppVar_49534) {
	cppVar_49518 = P2;
	} else {
	cppVar_49537 = PC + 1;
	cppVar_49537 = (cppVar_49537 & cppMask_un_16_);
	cppVar_49538 = ROM.rd(cppVar_49537);
	cppVar_49539 = (cppVar_49538 >> 7) & cppMask_un_1_;
	cppVar_49540 = (cppVar_49539 == 1);
	if (cppVar_49540) {
	cppVar_49541 = PC + 1;
	cppVar_49541 = (cppVar_49541 & cppMask_un_16_);
	cppVar_49542 = ROM.rd(cppVar_49541);
	cppVar_49543 = (cppVar_49542 >> 3) & cppMask_un_5_;
	cppVar_49544 = (cppVar_49543 << 3) | 0;
	cppVar_49544 = (cppVar_49544 & cppMask_un_8_);
	cppVar_49536 = cppVar_49544;
	} else {
	cppVar_49545 = PC + 1;
	cppVar_49545 = (cppVar_49545 & cppMask_un_16_);
	cppVar_49546 = ROM.rd(cppVar_49545);
	cppVar_49547 = (cppVar_49546 >> 3) & cppMask_un_5_;
	cppVar_49548 = (cppVar_49547 & cppMask_un_5_);
	cppVar_49549 = cppVar_49548 + 32;
	cppVar_49549 = (cppVar_49549 & cppMask_un_8_);
	cppVar_49536 = cppVar_49549;
	}
	cppVar_49551 = (cppVar_49536 == 168);
	if (cppVar_49551) {
	cppVar_49535 = IE;
	} else {
	cppVar_49554 = PC + 1;
	cppVar_49554 = (cppVar_49554 & cppMask_un_16_);
	cppVar_49555 = ROM.rd(cppVar_49554);
	cppVar_49556 = (cppVar_49555 >> 7) & cppMask_un_1_;
	cppVar_49557 = (cppVar_49556 == 1);
	if (cppVar_49557) {
	cppVar_49558 = PC + 1;
	cppVar_49558 = (cppVar_49558 & cppMask_un_16_);
	cppVar_49559 = ROM.rd(cppVar_49558);
	cppVar_49560 = (cppVar_49559 >> 3) & cppMask_un_5_;
	cppVar_49561 = (cppVar_49560 << 3) | 0;
	cppVar_49561 = (cppVar_49561 & cppMask_un_8_);
	cppVar_49553 = cppVar_49561;
	} else {
	cppVar_49562 = PC + 1;
	cppVar_49562 = (cppVar_49562 & cppMask_un_16_);
	cppVar_49563 = ROM.rd(cppVar_49562);
	cppVar_49564 = (cppVar_49563 >> 3) & cppMask_un_5_;
	cppVar_49565 = (cppVar_49564 & cppMask_un_5_);
	cppVar_49566 = cppVar_49565 + 32;
	cppVar_49566 = (cppVar_49566 & cppMask_un_8_);
	cppVar_49553 = cppVar_49566;
	}
	cppVar_49568 = (cppVar_49553 == 176);
	if (cppVar_49568) {
	cppVar_49552 = P3;
	} else {
	cppVar_49571 = PC + 1;
	cppVar_49571 = (cppVar_49571 & cppMask_un_16_);
	cppVar_49572 = ROM.rd(cppVar_49571);
	cppVar_49573 = (cppVar_49572 >> 7) & cppMask_un_1_;
	cppVar_49574 = (cppVar_49573 == 1);
	if (cppVar_49574) {
	cppVar_49575 = PC + 1;
	cppVar_49575 = (cppVar_49575 & cppMask_un_16_);
	cppVar_49576 = ROM.rd(cppVar_49575);
	cppVar_49577 = (cppVar_49576 >> 3) & cppMask_un_5_;
	cppVar_49578 = (cppVar_49577 << 3) | 0;
	cppVar_49578 = (cppVar_49578 & cppMask_un_8_);
	cppVar_49570 = cppVar_49578;
	} else {
	cppVar_49579 = PC + 1;
	cppVar_49579 = (cppVar_49579 & cppMask_un_16_);
	cppVar_49580 = ROM.rd(cppVar_49579);
	cppVar_49581 = (cppVar_49580 >> 3) & cppMask_un_5_;
	cppVar_49582 = (cppVar_49581 & cppMask_un_5_);
	cppVar_49583 = cppVar_49582 + 32;
	cppVar_49583 = (cppVar_49583 & cppMask_un_8_);
	cppVar_49570 = cppVar_49583;
	}
	cppVar_49585 = (cppVar_49570 == 184);
	if (cppVar_49585) {
	cppVar_49569 = IP;
	} else {
	cppVar_49588 = PC + 1;
	cppVar_49588 = (cppVar_49588 & cppMask_un_16_);
	cppVar_49589 = ROM.rd(cppVar_49588);
	cppVar_49590 = (cppVar_49589 >> 7) & cppMask_un_1_;
	cppVar_49591 = (cppVar_49590 == 1);
	if (cppVar_49591) {
	cppVar_49592 = PC + 1;
	cppVar_49592 = (cppVar_49592 & cppMask_un_16_);
	cppVar_49593 = ROM.rd(cppVar_49592);
	cppVar_49594 = (cppVar_49593 >> 3) & cppMask_un_5_;
	cppVar_49595 = (cppVar_49594 << 3) | 0;
	cppVar_49595 = (cppVar_49595 & cppMask_un_8_);
	cppVar_49587 = cppVar_49595;
	} else {
	cppVar_49596 = PC + 1;
	cppVar_49596 = (cppVar_49596 & cppMask_un_16_);
	cppVar_49597 = ROM.rd(cppVar_49596);
	cppVar_49598 = (cppVar_49597 >> 3) & cppMask_un_5_;
	cppVar_49599 = (cppVar_49598 & cppMask_un_5_);
	cppVar_49600 = cppVar_49599 + 32;
	cppVar_49600 = (cppVar_49600 & cppMask_un_8_);
	cppVar_49587 = cppVar_49600;
	}
	cppVar_49602 = (cppVar_49587 == 208);
	if (cppVar_49602) {
	cppVar_49586 = PSW;
	} else {
	cppVar_49605 = PC + 1;
	cppVar_49605 = (cppVar_49605 & cppMask_un_16_);
	cppVar_49606 = ROM.rd(cppVar_49605);
	cppVar_49607 = (cppVar_49606 >> 7) & cppMask_un_1_;
	cppVar_49608 = (cppVar_49607 == 1);
	if (cppVar_49608) {
	cppVar_49609 = PC + 1;
	cppVar_49609 = (cppVar_49609 & cppMask_un_16_);
	cppVar_49610 = ROM.rd(cppVar_49609);
	cppVar_49611 = (cppVar_49610 >> 3) & cppMask_un_5_;
	cppVar_49612 = (cppVar_49611 << 3) | 0;
	cppVar_49612 = (cppVar_49612 & cppMask_un_8_);
	cppVar_49604 = cppVar_49612;
	} else {
	cppVar_49613 = PC + 1;
	cppVar_49613 = (cppVar_49613 & cppMask_un_16_);
	cppVar_49614 = ROM.rd(cppVar_49613);
	cppVar_49615 = (cppVar_49614 >> 3) & cppMask_un_5_;
	cppVar_49616 = (cppVar_49615 & cppMask_un_5_);
	cppVar_49617 = cppVar_49616 + 32;
	cppVar_49617 = (cppVar_49617 & cppMask_un_8_);
	cppVar_49604 = cppVar_49617;
	}
	cppVar_49619 = (cppVar_49604 == 224);
	if (cppVar_49619) {
	cppVar_49603 = ACC;
	} else {
	cppVar_49622 = PC + 1;
	cppVar_49622 = (cppVar_49622 & cppMask_un_16_);
	cppVar_49623 = ROM.rd(cppVar_49622);
	cppVar_49624 = (cppVar_49623 >> 7) & cppMask_un_1_;
	cppVar_49625 = (cppVar_49624 == 1);
	if (cppVar_49625) {
	cppVar_49626 = PC + 1;
	cppVar_49626 = (cppVar_49626 & cppMask_un_16_);
	cppVar_49627 = ROM.rd(cppVar_49626);
	cppVar_49628 = (cppVar_49627 >> 3) & cppMask_un_5_;
	cppVar_49629 = (cppVar_49628 << 3) | 0;
	cppVar_49629 = (cppVar_49629 & cppMask_un_8_);
	cppVar_49621 = cppVar_49629;
	} else {
	cppVar_49630 = PC + 1;
	cppVar_49630 = (cppVar_49630 & cppMask_un_16_);
	cppVar_49631 = ROM.rd(cppVar_49630);
	cppVar_49632 = (cppVar_49631 >> 3) & cppMask_un_5_;
	cppVar_49633 = (cppVar_49632 & cppMask_un_5_);
	cppVar_49634 = cppVar_49633 + 32;
	cppVar_49634 = (cppVar_49634 & cppMask_un_8_);
	cppVar_49621 = cppVar_49634;
	}
	cppVar_49636 = (cppVar_49621 == 240);
	if (cppVar_49636) {
	cppVar_49620 = B;
	} else {
	cppVar_49620 = 0;
	}
	cppVar_49603 = cppVar_49620;
	}
	cppVar_49586 = cppVar_49603;
	}
	cppVar_49569 = cppVar_49586;
	}
	cppVar_49552 = cppVar_49569;
	}
	cppVar_49535 = cppVar_49552;
	}
	cppVar_49518 = cppVar_49535;
	}
	cppVar_49501 = cppVar_49518;
	}
	cppVar_49484 = cppVar_49501;
	}
	cppVar_49467 = cppVar_49484;
	}
	cppVar_49450 = cppVar_49467;
	}
	cppVar_49433 = cppVar_49450;
	}
	cppVar_49416 = cppVar_49433;
	}
	cppVar_49399 = cppVar_49416;
	}
	cppVar_49382 = cppVar_49399;
	}
	cppVar_49365 = cppVar_49382;
	}
	cppVar_49348 = cppVar_49365;
	}
	cppVar_49331 = cppVar_49348;
	}
	cppVar_49314 = cppVar_49331;
	}
	cppVar_49297 = cppVar_49314;
	}
	cppVar_49280 = cppVar_49297;
	}
	cppVar_49243 = cppVar_49280;
	}
	cppVar_49638 = PC + 1;
	cppVar_49638 = (cppVar_49638 & cppMask_un_16_);
	cppVar_49639 = ROM.rd(cppVar_49638);
	cppVar_49640 = (cppVar_49639 >> 0) & cppMask_un_3_;
	cppVar_49641 = (cppVar_49243 >> static_cast<unsigned>(cppVar_49640)) & 0x1;
	cppVar_49642 = ~cppVar_49641;
	cppVar_49643 = cppVar_49242 | cppVar_49642;
	cppVar_49644 = (PSW >> 0) & cppMask_un_7_;
	cppVar_49645 = (cppVar_49643 << 7) | cppVar_49644;
	cppVar_49645 = (cppVar_49645 & cppMask_un_8_);
	cppVar_49238 = cppVar_49645;
	} else {
	cppVar_49647 = ROM.rd(PC);
	cppVar_49649 = (cppVar_49647 == 159);
	if (cppVar_49649) {
	cppVar_49652 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49654 = (cppVar_49652 << 3) | 7;
	cppVar_49654 = (cppVar_49654 & cppMask_un_5_);
	cppVar_49655 = (0 << 5) | cppVar_49654;
	cppVar_49655 = (cppVar_49655 & cppMask_un_8_);
	cppVar_49656 = IRAM.rd(cppVar_49655);
	cppVar_49657 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49658 = (cppVar_49657 & cppMask_un_1_);
	cppVar_49659 = cppVar_49656 + cppVar_49658;
	cppVar_49659 = (cppVar_49659 & cppMask_un_8_);
	cppVar_49660 = ACC < cppVar_49659;
	if (cppVar_49660) {
	cppVar_49650 = 1;
	} else {
	cppVar_49650 = 0;
	}
	cppVar_49664 = (ACC >> 0) & cppMask_un_4_;
	cppVar_49665 = (cppVar_49664 & cppMask_un_4_);
	cppVar_49666 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49667 = (cppVar_49666 << 3) | 7;
	cppVar_49667 = (cppVar_49667 & cppMask_un_5_);
	cppVar_49668 = (0 << 5) | cppVar_49667;
	cppVar_49668 = (cppVar_49668 & cppMask_un_8_);
	cppVar_49669 = IRAM.rd(cppVar_49668);
	cppVar_49670 = (cppVar_49669 >> 0) & cppMask_un_4_;
	cppVar_49671 = (cppVar_49670 & cppMask_un_4_);
	cppVar_49672 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49673 = (cppVar_49672 & cppMask_un_1_);
	cppVar_49674 = cppVar_49671 + cppVar_49673;
	cppVar_49674 = (cppVar_49674 & cppMask_un_5_);
	cppVar_49675 = cppVar_49665 < cppVar_49674;
	if (cppVar_49675) {
	cppVar_49663 = 1;
	} else {
	cppVar_49663 = 0;
	}
	cppVar_49678 = (PSW >> 3) & cppMask_un_3_;
	cppVar_49680 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_49681 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49682 = (cppVar_49681 << 3) | 7;
	cppVar_49682 = (cppVar_49682 & cppMask_un_5_);
	cppVar_49683 = (0 << 5) | cppVar_49682;
	cppVar_49683 = (cppVar_49683 & cppMask_un_8_);
	cppVar_49684 = IRAM.rd(cppVar_49683);
	cppVar_49685 = ((cppVar_49684 & cppMask_bit_8_) ? (cppVar_49684 | cppMask_sign_8_) : cppVar_49684);
	cppVar_49686 = cppVar_49680 - cppVar_49685;
	cppVar_49686 = (cppVar_49686 & cppMask_un_9_);
	cppVar_49687 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49688 = ((cppVar_49687 & cppMask_bit_1_) ? (cppVar_49687 | cppMask_sign_1_) : cppVar_49687);
	cppVar_49689 = cppVar_49686 + cppVar_49688;
	cppVar_49689 = (cppVar_49689 & cppMask_un_9_);
	cppVar_49690 = (cppVar_49689 >> 8) & cppMask_un_1_;
	cppVar_49691 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_49692 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49693 = (cppVar_49692 << 3) | 7;
	cppVar_49693 = (cppVar_49693 & cppMask_un_5_);
	cppVar_49694 = (0 << 5) | cppVar_49693;
	cppVar_49694 = (cppVar_49694 & cppMask_un_8_);
	cppVar_49695 = IRAM.rd(cppVar_49694);
	cppVar_49696 = ((cppVar_49695 & cppMask_bit_8_) ? (cppVar_49695 | cppMask_sign_8_) : cppVar_49695);
	cppVar_49697 = cppVar_49691 - cppVar_49696;
	cppVar_49697 = (cppVar_49697 & cppMask_un_9_);
	cppVar_49698 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49699 = ((cppVar_49698 & cppMask_bit_1_) ? (cppVar_49698 | cppMask_sign_1_) : cppVar_49698);
	cppVar_49700 = cppVar_49697 + cppVar_49699;
	cppVar_49700 = (cppVar_49700 & cppMask_un_9_);
	cppVar_49701 = (cppVar_49700 >> 7) & cppMask_un_1_;
	cppVar_49702 = (cppVar_49690 != cppVar_49701);
	if (cppVar_49702) {
	cppVar_49679 = 1;
	} else {
	cppVar_49679 = 0;
	}
	cppVar_49705 = (PSW >> 0) & cppMask_un_2_;
	cppVar_49706 = (cppVar_49679 << 2) | cppVar_49705;
	cppVar_49706 = (cppVar_49706 & cppMask_un_3_);
	cppVar_49707 = (cppVar_49678 << 3) | cppVar_49706;
	cppVar_49707 = (cppVar_49707 & cppMask_un_6_);
	cppVar_49708 = (cppVar_49663 << 6) | cppVar_49707;
	cppVar_49708 = (cppVar_49708 & cppMask_un_7_);
	cppVar_49709 = (cppVar_49650 << 7) | cppVar_49708;
	cppVar_49709 = (cppVar_49709 & cppMask_un_8_);
	cppVar_49646 = cppVar_49709;
	} else {
	cppVar_49711 = ROM.rd(PC);
	cppVar_49713 = (cppVar_49711 == 158);
	if (cppVar_49713) {
	cppVar_49716 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49718 = (cppVar_49716 << 3) | 6;
	cppVar_49718 = (cppVar_49718 & cppMask_un_5_);
	cppVar_49719 = (0 << 5) | cppVar_49718;
	cppVar_49719 = (cppVar_49719 & cppMask_un_8_);
	cppVar_49720 = IRAM.rd(cppVar_49719);
	cppVar_49721 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49722 = (cppVar_49721 & cppMask_un_1_);
	cppVar_49723 = cppVar_49720 + cppVar_49722;
	cppVar_49723 = (cppVar_49723 & cppMask_un_8_);
	cppVar_49724 = ACC < cppVar_49723;
	if (cppVar_49724) {
	cppVar_49714 = 1;
	} else {
	cppVar_49714 = 0;
	}
	cppVar_49728 = (ACC >> 0) & cppMask_un_4_;
	cppVar_49729 = (cppVar_49728 & cppMask_un_4_);
	cppVar_49730 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49731 = (cppVar_49730 << 3) | 6;
	cppVar_49731 = (cppVar_49731 & cppMask_un_5_);
	cppVar_49732 = (0 << 5) | cppVar_49731;
	cppVar_49732 = (cppVar_49732 & cppMask_un_8_);
	cppVar_49733 = IRAM.rd(cppVar_49732);
	cppVar_49734 = (cppVar_49733 >> 0) & cppMask_un_4_;
	cppVar_49735 = (cppVar_49734 & cppMask_un_4_);
	cppVar_49736 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49737 = (cppVar_49736 & cppMask_un_1_);
	cppVar_49738 = cppVar_49735 + cppVar_49737;
	cppVar_49738 = (cppVar_49738 & cppMask_un_5_);
	cppVar_49739 = cppVar_49729 < cppVar_49738;
	if (cppVar_49739) {
	cppVar_49727 = 1;
	} else {
	cppVar_49727 = 0;
	}
	cppVar_49742 = (PSW >> 3) & cppMask_un_3_;
	cppVar_49744 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_49745 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49746 = (cppVar_49745 << 3) | 6;
	cppVar_49746 = (cppVar_49746 & cppMask_un_5_);
	cppVar_49747 = (0 << 5) | cppVar_49746;
	cppVar_49747 = (cppVar_49747 & cppMask_un_8_);
	cppVar_49748 = IRAM.rd(cppVar_49747);
	cppVar_49749 = ((cppVar_49748 & cppMask_bit_8_) ? (cppVar_49748 | cppMask_sign_8_) : cppVar_49748);
	cppVar_49750 = cppVar_49744 - cppVar_49749;
	cppVar_49750 = (cppVar_49750 & cppMask_un_9_);
	cppVar_49751 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49752 = ((cppVar_49751 & cppMask_bit_1_) ? (cppVar_49751 | cppMask_sign_1_) : cppVar_49751);
	cppVar_49753 = cppVar_49750 + cppVar_49752;
	cppVar_49753 = (cppVar_49753 & cppMask_un_9_);
	cppVar_49754 = (cppVar_49753 >> 8) & cppMask_un_1_;
	cppVar_49755 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_49756 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49757 = (cppVar_49756 << 3) | 6;
	cppVar_49757 = (cppVar_49757 & cppMask_un_5_);
	cppVar_49758 = (0 << 5) | cppVar_49757;
	cppVar_49758 = (cppVar_49758 & cppMask_un_8_);
	cppVar_49759 = IRAM.rd(cppVar_49758);
	cppVar_49760 = ((cppVar_49759 & cppMask_bit_8_) ? (cppVar_49759 | cppMask_sign_8_) : cppVar_49759);
	cppVar_49761 = cppVar_49755 - cppVar_49760;
	cppVar_49761 = (cppVar_49761 & cppMask_un_9_);
	cppVar_49762 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49763 = ((cppVar_49762 & cppMask_bit_1_) ? (cppVar_49762 | cppMask_sign_1_) : cppVar_49762);
	cppVar_49764 = cppVar_49761 + cppVar_49763;
	cppVar_49764 = (cppVar_49764 & cppMask_un_9_);
	cppVar_49765 = (cppVar_49764 >> 7) & cppMask_un_1_;
	cppVar_49766 = (cppVar_49754 != cppVar_49765);
	if (cppVar_49766) {
	cppVar_49743 = 1;
	} else {
	cppVar_49743 = 0;
	}
	cppVar_49769 = (PSW >> 0) & cppMask_un_2_;
	cppVar_49770 = (cppVar_49743 << 2) | cppVar_49769;
	cppVar_49770 = (cppVar_49770 & cppMask_un_3_);
	cppVar_49771 = (cppVar_49742 << 3) | cppVar_49770;
	cppVar_49771 = (cppVar_49771 & cppMask_un_6_);
	cppVar_49772 = (cppVar_49727 << 6) | cppVar_49771;
	cppVar_49772 = (cppVar_49772 & cppMask_un_7_);
	cppVar_49773 = (cppVar_49714 << 7) | cppVar_49772;
	cppVar_49773 = (cppVar_49773 & cppMask_un_8_);
	cppVar_49710 = cppVar_49773;
	} else {
	cppVar_49775 = ROM.rd(PC);
	cppVar_49777 = (cppVar_49775 == 157);
	if (cppVar_49777) {
	cppVar_49780 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49782 = (cppVar_49780 << 3) | 5;
	cppVar_49782 = (cppVar_49782 & cppMask_un_5_);
	cppVar_49783 = (0 << 5) | cppVar_49782;
	cppVar_49783 = (cppVar_49783 & cppMask_un_8_);
	cppVar_49784 = IRAM.rd(cppVar_49783);
	cppVar_49785 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49786 = (cppVar_49785 & cppMask_un_1_);
	cppVar_49787 = cppVar_49784 + cppVar_49786;
	cppVar_49787 = (cppVar_49787 & cppMask_un_8_);
	cppVar_49788 = ACC < cppVar_49787;
	if (cppVar_49788) {
	cppVar_49778 = 1;
	} else {
	cppVar_49778 = 0;
	}
	cppVar_49792 = (ACC >> 0) & cppMask_un_4_;
	cppVar_49793 = (cppVar_49792 & cppMask_un_4_);
	cppVar_49794 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49795 = (cppVar_49794 << 3) | 5;
	cppVar_49795 = (cppVar_49795 & cppMask_un_5_);
	cppVar_49796 = (0 << 5) | cppVar_49795;
	cppVar_49796 = (cppVar_49796 & cppMask_un_8_);
	cppVar_49797 = IRAM.rd(cppVar_49796);
	cppVar_49798 = (cppVar_49797 >> 0) & cppMask_un_4_;
	cppVar_49799 = (cppVar_49798 & cppMask_un_4_);
	cppVar_49800 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49801 = (cppVar_49800 & cppMask_un_1_);
	cppVar_49802 = cppVar_49799 + cppVar_49801;
	cppVar_49802 = (cppVar_49802 & cppMask_un_5_);
	cppVar_49803 = cppVar_49793 < cppVar_49802;
	if (cppVar_49803) {
	cppVar_49791 = 1;
	} else {
	cppVar_49791 = 0;
	}
	cppVar_49806 = (PSW >> 3) & cppMask_un_3_;
	cppVar_49808 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_49809 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49810 = (cppVar_49809 << 3) | 5;
	cppVar_49810 = (cppVar_49810 & cppMask_un_5_);
	cppVar_49811 = (0 << 5) | cppVar_49810;
	cppVar_49811 = (cppVar_49811 & cppMask_un_8_);
	cppVar_49812 = IRAM.rd(cppVar_49811);
	cppVar_49813 = ((cppVar_49812 & cppMask_bit_8_) ? (cppVar_49812 | cppMask_sign_8_) : cppVar_49812);
	cppVar_49814 = cppVar_49808 - cppVar_49813;
	cppVar_49814 = (cppVar_49814 & cppMask_un_9_);
	cppVar_49815 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49816 = ((cppVar_49815 & cppMask_bit_1_) ? (cppVar_49815 | cppMask_sign_1_) : cppVar_49815);
	cppVar_49817 = cppVar_49814 + cppVar_49816;
	cppVar_49817 = (cppVar_49817 & cppMask_un_9_);
	cppVar_49818 = (cppVar_49817 >> 8) & cppMask_un_1_;
	cppVar_49819 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_49820 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49821 = (cppVar_49820 << 3) | 5;
	cppVar_49821 = (cppVar_49821 & cppMask_un_5_);
	cppVar_49822 = (0 << 5) | cppVar_49821;
	cppVar_49822 = (cppVar_49822 & cppMask_un_8_);
	cppVar_49823 = IRAM.rd(cppVar_49822);
	cppVar_49824 = ((cppVar_49823 & cppMask_bit_8_) ? (cppVar_49823 | cppMask_sign_8_) : cppVar_49823);
	cppVar_49825 = cppVar_49819 - cppVar_49824;
	cppVar_49825 = (cppVar_49825 & cppMask_un_9_);
	cppVar_49826 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49827 = ((cppVar_49826 & cppMask_bit_1_) ? (cppVar_49826 | cppMask_sign_1_) : cppVar_49826);
	cppVar_49828 = cppVar_49825 + cppVar_49827;
	cppVar_49828 = (cppVar_49828 & cppMask_un_9_);
	cppVar_49829 = (cppVar_49828 >> 7) & cppMask_un_1_;
	cppVar_49830 = (cppVar_49818 != cppVar_49829);
	if (cppVar_49830) {
	cppVar_49807 = 1;
	} else {
	cppVar_49807 = 0;
	}
	cppVar_49833 = (PSW >> 0) & cppMask_un_2_;
	cppVar_49834 = (cppVar_49807 << 2) | cppVar_49833;
	cppVar_49834 = (cppVar_49834 & cppMask_un_3_);
	cppVar_49835 = (cppVar_49806 << 3) | cppVar_49834;
	cppVar_49835 = (cppVar_49835 & cppMask_un_6_);
	cppVar_49836 = (cppVar_49791 << 6) | cppVar_49835;
	cppVar_49836 = (cppVar_49836 & cppMask_un_7_);
	cppVar_49837 = (cppVar_49778 << 7) | cppVar_49836;
	cppVar_49837 = (cppVar_49837 & cppMask_un_8_);
	cppVar_49774 = cppVar_49837;
	} else {
	cppVar_49839 = ROM.rd(PC);
	cppVar_49841 = (cppVar_49839 == 156);
	if (cppVar_49841) {
	cppVar_49844 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49846 = (cppVar_49844 << 3) | 4;
	cppVar_49846 = (cppVar_49846 & cppMask_un_5_);
	cppVar_49847 = (0 << 5) | cppVar_49846;
	cppVar_49847 = (cppVar_49847 & cppMask_un_8_);
	cppVar_49848 = IRAM.rd(cppVar_49847);
	cppVar_49849 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49850 = (cppVar_49849 & cppMask_un_1_);
	cppVar_49851 = cppVar_49848 + cppVar_49850;
	cppVar_49851 = (cppVar_49851 & cppMask_un_8_);
	cppVar_49852 = ACC < cppVar_49851;
	if (cppVar_49852) {
	cppVar_49842 = 1;
	} else {
	cppVar_49842 = 0;
	}
	cppVar_49856 = (ACC >> 0) & cppMask_un_4_;
	cppVar_49857 = (cppVar_49856 & cppMask_un_4_);
	cppVar_49858 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49859 = (cppVar_49858 << 3) | 4;
	cppVar_49859 = (cppVar_49859 & cppMask_un_5_);
	cppVar_49860 = (0 << 5) | cppVar_49859;
	cppVar_49860 = (cppVar_49860 & cppMask_un_8_);
	cppVar_49861 = IRAM.rd(cppVar_49860);
	cppVar_49862 = (cppVar_49861 >> 0) & cppMask_un_4_;
	cppVar_49863 = (cppVar_49862 & cppMask_un_4_);
	cppVar_49864 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49865 = (cppVar_49864 & cppMask_un_1_);
	cppVar_49866 = cppVar_49863 + cppVar_49865;
	cppVar_49866 = (cppVar_49866 & cppMask_un_5_);
	cppVar_49867 = cppVar_49857 < cppVar_49866;
	if (cppVar_49867) {
	cppVar_49855 = 1;
	} else {
	cppVar_49855 = 0;
	}
	cppVar_49870 = (PSW >> 3) & cppMask_un_3_;
	cppVar_49872 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_49873 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49874 = (cppVar_49873 << 3) | 4;
	cppVar_49874 = (cppVar_49874 & cppMask_un_5_);
	cppVar_49875 = (0 << 5) | cppVar_49874;
	cppVar_49875 = (cppVar_49875 & cppMask_un_8_);
	cppVar_49876 = IRAM.rd(cppVar_49875);
	cppVar_49877 = ((cppVar_49876 & cppMask_bit_8_) ? (cppVar_49876 | cppMask_sign_8_) : cppVar_49876);
	cppVar_49878 = cppVar_49872 - cppVar_49877;
	cppVar_49878 = (cppVar_49878 & cppMask_un_9_);
	cppVar_49879 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49880 = ((cppVar_49879 & cppMask_bit_1_) ? (cppVar_49879 | cppMask_sign_1_) : cppVar_49879);
	cppVar_49881 = cppVar_49878 + cppVar_49880;
	cppVar_49881 = (cppVar_49881 & cppMask_un_9_);
	cppVar_49882 = (cppVar_49881 >> 8) & cppMask_un_1_;
	cppVar_49883 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_49884 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49885 = (cppVar_49884 << 3) | 4;
	cppVar_49885 = (cppVar_49885 & cppMask_un_5_);
	cppVar_49886 = (0 << 5) | cppVar_49885;
	cppVar_49886 = (cppVar_49886 & cppMask_un_8_);
	cppVar_49887 = IRAM.rd(cppVar_49886);
	cppVar_49888 = ((cppVar_49887 & cppMask_bit_8_) ? (cppVar_49887 | cppMask_sign_8_) : cppVar_49887);
	cppVar_49889 = cppVar_49883 - cppVar_49888;
	cppVar_49889 = (cppVar_49889 & cppMask_un_9_);
	cppVar_49890 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49891 = ((cppVar_49890 & cppMask_bit_1_) ? (cppVar_49890 | cppMask_sign_1_) : cppVar_49890);
	cppVar_49892 = cppVar_49889 + cppVar_49891;
	cppVar_49892 = (cppVar_49892 & cppMask_un_9_);
	cppVar_49893 = (cppVar_49892 >> 7) & cppMask_un_1_;
	cppVar_49894 = (cppVar_49882 != cppVar_49893);
	if (cppVar_49894) {
	cppVar_49871 = 1;
	} else {
	cppVar_49871 = 0;
	}
	cppVar_49897 = (PSW >> 0) & cppMask_un_2_;
	cppVar_49898 = (cppVar_49871 << 2) | cppVar_49897;
	cppVar_49898 = (cppVar_49898 & cppMask_un_3_);
	cppVar_49899 = (cppVar_49870 << 3) | cppVar_49898;
	cppVar_49899 = (cppVar_49899 & cppMask_un_6_);
	cppVar_49900 = (cppVar_49855 << 6) | cppVar_49899;
	cppVar_49900 = (cppVar_49900 & cppMask_un_7_);
	cppVar_49901 = (cppVar_49842 << 7) | cppVar_49900;
	cppVar_49901 = (cppVar_49901 & cppMask_un_8_);
	cppVar_49838 = cppVar_49901;
	} else {
	cppVar_49903 = ROM.rd(PC);
	cppVar_49905 = (cppVar_49903 == 155);
	if (cppVar_49905) {
	cppVar_49908 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49910 = (cppVar_49908 << 3) | 3;
	cppVar_49910 = (cppVar_49910 & cppMask_un_5_);
	cppVar_49911 = (0 << 5) | cppVar_49910;
	cppVar_49911 = (cppVar_49911 & cppMask_un_8_);
	cppVar_49912 = IRAM.rd(cppVar_49911);
	cppVar_49913 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49914 = (cppVar_49913 & cppMask_un_1_);
	cppVar_49915 = cppVar_49912 + cppVar_49914;
	cppVar_49915 = (cppVar_49915 & cppMask_un_8_);
	cppVar_49916 = ACC < cppVar_49915;
	if (cppVar_49916) {
	cppVar_49906 = 1;
	} else {
	cppVar_49906 = 0;
	}
	cppVar_49920 = (ACC >> 0) & cppMask_un_4_;
	cppVar_49921 = (cppVar_49920 & cppMask_un_4_);
	cppVar_49922 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49923 = (cppVar_49922 << 3) | 3;
	cppVar_49923 = (cppVar_49923 & cppMask_un_5_);
	cppVar_49924 = (0 << 5) | cppVar_49923;
	cppVar_49924 = (cppVar_49924 & cppMask_un_8_);
	cppVar_49925 = IRAM.rd(cppVar_49924);
	cppVar_49926 = (cppVar_49925 >> 0) & cppMask_un_4_;
	cppVar_49927 = (cppVar_49926 & cppMask_un_4_);
	cppVar_49928 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49929 = (cppVar_49928 & cppMask_un_1_);
	cppVar_49930 = cppVar_49927 + cppVar_49929;
	cppVar_49930 = (cppVar_49930 & cppMask_un_5_);
	cppVar_49931 = cppVar_49921 < cppVar_49930;
	if (cppVar_49931) {
	cppVar_49919 = 1;
	} else {
	cppVar_49919 = 0;
	}
	cppVar_49934 = (PSW >> 3) & cppMask_un_3_;
	cppVar_49936 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_49937 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49938 = (cppVar_49937 << 3) | 3;
	cppVar_49938 = (cppVar_49938 & cppMask_un_5_);
	cppVar_49939 = (0 << 5) | cppVar_49938;
	cppVar_49939 = (cppVar_49939 & cppMask_un_8_);
	cppVar_49940 = IRAM.rd(cppVar_49939);
	cppVar_49941 = ((cppVar_49940 & cppMask_bit_8_) ? (cppVar_49940 | cppMask_sign_8_) : cppVar_49940);
	cppVar_49942 = cppVar_49936 - cppVar_49941;
	cppVar_49942 = (cppVar_49942 & cppMask_un_9_);
	cppVar_49943 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49944 = ((cppVar_49943 & cppMask_bit_1_) ? (cppVar_49943 | cppMask_sign_1_) : cppVar_49943);
	cppVar_49945 = cppVar_49942 + cppVar_49944;
	cppVar_49945 = (cppVar_49945 & cppMask_un_9_);
	cppVar_49946 = (cppVar_49945 >> 8) & cppMask_un_1_;
	cppVar_49947 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_49948 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49949 = (cppVar_49948 << 3) | 3;
	cppVar_49949 = (cppVar_49949 & cppMask_un_5_);
	cppVar_49950 = (0 << 5) | cppVar_49949;
	cppVar_49950 = (cppVar_49950 & cppMask_un_8_);
	cppVar_49951 = IRAM.rd(cppVar_49950);
	cppVar_49952 = ((cppVar_49951 & cppMask_bit_8_) ? (cppVar_49951 | cppMask_sign_8_) : cppVar_49951);
	cppVar_49953 = cppVar_49947 - cppVar_49952;
	cppVar_49953 = (cppVar_49953 & cppMask_un_9_);
	cppVar_49954 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49955 = ((cppVar_49954 & cppMask_bit_1_) ? (cppVar_49954 | cppMask_sign_1_) : cppVar_49954);
	cppVar_49956 = cppVar_49953 + cppVar_49955;
	cppVar_49956 = (cppVar_49956 & cppMask_un_9_);
	cppVar_49957 = (cppVar_49956 >> 7) & cppMask_un_1_;
	cppVar_49958 = (cppVar_49946 != cppVar_49957);
	if (cppVar_49958) {
	cppVar_49935 = 1;
	} else {
	cppVar_49935 = 0;
	}
	cppVar_49961 = (PSW >> 0) & cppMask_un_2_;
	cppVar_49962 = (cppVar_49935 << 2) | cppVar_49961;
	cppVar_49962 = (cppVar_49962 & cppMask_un_3_);
	cppVar_49963 = (cppVar_49934 << 3) | cppVar_49962;
	cppVar_49963 = (cppVar_49963 & cppMask_un_6_);
	cppVar_49964 = (cppVar_49919 << 6) | cppVar_49963;
	cppVar_49964 = (cppVar_49964 & cppMask_un_7_);
	cppVar_49965 = (cppVar_49906 << 7) | cppVar_49964;
	cppVar_49965 = (cppVar_49965 & cppMask_un_8_);
	cppVar_49902 = cppVar_49965;
	} else {
	cppVar_49967 = ROM.rd(PC);
	cppVar_49969 = (cppVar_49967 == 154);
	if (cppVar_49969) {
	cppVar_49972 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49974 = (cppVar_49972 << 3) | 2;
	cppVar_49974 = (cppVar_49974 & cppMask_un_5_);
	cppVar_49975 = (0 << 5) | cppVar_49974;
	cppVar_49975 = (cppVar_49975 & cppMask_un_8_);
	cppVar_49976 = IRAM.rd(cppVar_49975);
	cppVar_49977 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49978 = (cppVar_49977 & cppMask_un_1_);
	cppVar_49979 = cppVar_49976 + cppVar_49978;
	cppVar_49979 = (cppVar_49979 & cppMask_un_8_);
	cppVar_49980 = ACC < cppVar_49979;
	if (cppVar_49980) {
	cppVar_49970 = 1;
	} else {
	cppVar_49970 = 0;
	}
	cppVar_49984 = (ACC >> 0) & cppMask_un_4_;
	cppVar_49985 = (cppVar_49984 & cppMask_un_4_);
	cppVar_49986 = (PSW >> 3) & cppMask_un_2_;
	cppVar_49987 = (cppVar_49986 << 3) | 2;
	cppVar_49987 = (cppVar_49987 & cppMask_un_5_);
	cppVar_49988 = (0 << 5) | cppVar_49987;
	cppVar_49988 = (cppVar_49988 & cppMask_un_8_);
	cppVar_49989 = IRAM.rd(cppVar_49988);
	cppVar_49990 = (cppVar_49989 >> 0) & cppMask_un_4_;
	cppVar_49991 = (cppVar_49990 & cppMask_un_4_);
	cppVar_49992 = (PSW >> 7) & cppMask_un_1_;
	cppVar_49993 = (cppVar_49992 & cppMask_un_1_);
	cppVar_49994 = cppVar_49991 + cppVar_49993;
	cppVar_49994 = (cppVar_49994 & cppMask_un_5_);
	cppVar_49995 = cppVar_49985 < cppVar_49994;
	if (cppVar_49995) {
	cppVar_49983 = 1;
	} else {
	cppVar_49983 = 0;
	}
	cppVar_49998 = (PSW >> 3) & cppMask_un_3_;
	cppVar_50000 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_50001 = (PSW >> 3) & cppMask_un_2_;
	cppVar_50002 = (cppVar_50001 << 3) | 2;
	cppVar_50002 = (cppVar_50002 & cppMask_un_5_);
	cppVar_50003 = (0 << 5) | cppVar_50002;
	cppVar_50003 = (cppVar_50003 & cppMask_un_8_);
	cppVar_50004 = IRAM.rd(cppVar_50003);
	cppVar_50005 = ((cppVar_50004 & cppMask_bit_8_) ? (cppVar_50004 | cppMask_sign_8_) : cppVar_50004);
	cppVar_50006 = cppVar_50000 - cppVar_50005;
	cppVar_50006 = (cppVar_50006 & cppMask_un_9_);
	cppVar_50007 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50008 = ((cppVar_50007 & cppMask_bit_1_) ? (cppVar_50007 | cppMask_sign_1_) : cppVar_50007);
	cppVar_50009 = cppVar_50006 + cppVar_50008;
	cppVar_50009 = (cppVar_50009 & cppMask_un_9_);
	cppVar_50010 = (cppVar_50009 >> 8) & cppMask_un_1_;
	cppVar_50011 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_50012 = (PSW >> 3) & cppMask_un_2_;
	cppVar_50013 = (cppVar_50012 << 3) | 2;
	cppVar_50013 = (cppVar_50013 & cppMask_un_5_);
	cppVar_50014 = (0 << 5) | cppVar_50013;
	cppVar_50014 = (cppVar_50014 & cppMask_un_8_);
	cppVar_50015 = IRAM.rd(cppVar_50014);
	cppVar_50016 = ((cppVar_50015 & cppMask_bit_8_) ? (cppVar_50015 | cppMask_sign_8_) : cppVar_50015);
	cppVar_50017 = cppVar_50011 - cppVar_50016;
	cppVar_50017 = (cppVar_50017 & cppMask_un_9_);
	cppVar_50018 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50019 = ((cppVar_50018 & cppMask_bit_1_) ? (cppVar_50018 | cppMask_sign_1_) : cppVar_50018);
	cppVar_50020 = cppVar_50017 + cppVar_50019;
	cppVar_50020 = (cppVar_50020 & cppMask_un_9_);
	cppVar_50021 = (cppVar_50020 >> 7) & cppMask_un_1_;
	cppVar_50022 = (cppVar_50010 != cppVar_50021);
	if (cppVar_50022) {
	cppVar_49999 = 1;
	} else {
	cppVar_49999 = 0;
	}
	cppVar_50025 = (PSW >> 0) & cppMask_un_2_;
	cppVar_50026 = (cppVar_49999 << 2) | cppVar_50025;
	cppVar_50026 = (cppVar_50026 & cppMask_un_3_);
	cppVar_50027 = (cppVar_49998 << 3) | cppVar_50026;
	cppVar_50027 = (cppVar_50027 & cppMask_un_6_);
	cppVar_50028 = (cppVar_49983 << 6) | cppVar_50027;
	cppVar_50028 = (cppVar_50028 & cppMask_un_7_);
	cppVar_50029 = (cppVar_49970 << 7) | cppVar_50028;
	cppVar_50029 = (cppVar_50029 & cppMask_un_8_);
	cppVar_49966 = cppVar_50029;
	} else {
	cppVar_50031 = ROM.rd(PC);
	cppVar_50033 = (cppVar_50031 == 153);
	if (cppVar_50033) {
	cppVar_50036 = (PSW >> 3) & cppMask_un_2_;
	cppVar_50038 = (cppVar_50036 << 3) | 1;
	cppVar_50038 = (cppVar_50038 & cppMask_un_5_);
	cppVar_50039 = (0 << 5) | cppVar_50038;
	cppVar_50039 = (cppVar_50039 & cppMask_un_8_);
	cppVar_50040 = IRAM.rd(cppVar_50039);
	cppVar_50041 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50042 = (cppVar_50041 & cppMask_un_1_);
	cppVar_50043 = cppVar_50040 + cppVar_50042;
	cppVar_50043 = (cppVar_50043 & cppMask_un_8_);
	cppVar_50044 = ACC < cppVar_50043;
	if (cppVar_50044) {
	cppVar_50034 = 1;
	} else {
	cppVar_50034 = 0;
	}
	cppVar_50048 = (ACC >> 0) & cppMask_un_4_;
	cppVar_50049 = (cppVar_50048 & cppMask_un_4_);
	cppVar_50050 = (PSW >> 3) & cppMask_un_2_;
	cppVar_50051 = (cppVar_50050 << 3) | 1;
	cppVar_50051 = (cppVar_50051 & cppMask_un_5_);
	cppVar_50052 = (0 << 5) | cppVar_50051;
	cppVar_50052 = (cppVar_50052 & cppMask_un_8_);
	cppVar_50053 = IRAM.rd(cppVar_50052);
	cppVar_50054 = (cppVar_50053 >> 0) & cppMask_un_4_;
	cppVar_50055 = (cppVar_50054 & cppMask_un_4_);
	cppVar_50056 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50057 = (cppVar_50056 & cppMask_un_1_);
	cppVar_50058 = cppVar_50055 + cppVar_50057;
	cppVar_50058 = (cppVar_50058 & cppMask_un_5_);
	cppVar_50059 = cppVar_50049 < cppVar_50058;
	if (cppVar_50059) {
	cppVar_50047 = 1;
	} else {
	cppVar_50047 = 0;
	}
	cppVar_50062 = (PSW >> 3) & cppMask_un_3_;
	cppVar_50064 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_50065 = (PSW >> 3) & cppMask_un_2_;
	cppVar_50066 = (cppVar_50065 << 3) | 1;
	cppVar_50066 = (cppVar_50066 & cppMask_un_5_);
	cppVar_50067 = (0 << 5) | cppVar_50066;
	cppVar_50067 = (cppVar_50067 & cppMask_un_8_);
	cppVar_50068 = IRAM.rd(cppVar_50067);
	cppVar_50069 = ((cppVar_50068 & cppMask_bit_8_) ? (cppVar_50068 | cppMask_sign_8_) : cppVar_50068);
	cppVar_50070 = cppVar_50064 - cppVar_50069;
	cppVar_50070 = (cppVar_50070 & cppMask_un_9_);
	cppVar_50071 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50072 = ((cppVar_50071 & cppMask_bit_1_) ? (cppVar_50071 | cppMask_sign_1_) : cppVar_50071);
	cppVar_50073 = cppVar_50070 + cppVar_50072;
	cppVar_50073 = (cppVar_50073 & cppMask_un_9_);
	cppVar_50074 = (cppVar_50073 >> 8) & cppMask_un_1_;
	cppVar_50075 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_50076 = (PSW >> 3) & cppMask_un_2_;
	cppVar_50077 = (cppVar_50076 << 3) | 1;
	cppVar_50077 = (cppVar_50077 & cppMask_un_5_);
	cppVar_50078 = (0 << 5) | cppVar_50077;
	cppVar_50078 = (cppVar_50078 & cppMask_un_8_);
	cppVar_50079 = IRAM.rd(cppVar_50078);
	cppVar_50080 = ((cppVar_50079 & cppMask_bit_8_) ? (cppVar_50079 | cppMask_sign_8_) : cppVar_50079);
	cppVar_50081 = cppVar_50075 - cppVar_50080;
	cppVar_50081 = (cppVar_50081 & cppMask_un_9_);
	cppVar_50082 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50083 = ((cppVar_50082 & cppMask_bit_1_) ? (cppVar_50082 | cppMask_sign_1_) : cppVar_50082);
	cppVar_50084 = cppVar_50081 + cppVar_50083;
	cppVar_50084 = (cppVar_50084 & cppMask_un_9_);
	cppVar_50085 = (cppVar_50084 >> 7) & cppMask_un_1_;
	cppVar_50086 = (cppVar_50074 != cppVar_50085);
	if (cppVar_50086) {
	cppVar_50063 = 1;
	} else {
	cppVar_50063 = 0;
	}
	cppVar_50089 = (PSW >> 0) & cppMask_un_2_;
	cppVar_50090 = (cppVar_50063 << 2) | cppVar_50089;
	cppVar_50090 = (cppVar_50090 & cppMask_un_3_);
	cppVar_50091 = (cppVar_50062 << 3) | cppVar_50090;
	cppVar_50091 = (cppVar_50091 & cppMask_un_6_);
	cppVar_50092 = (cppVar_50047 << 6) | cppVar_50091;
	cppVar_50092 = (cppVar_50092 & cppMask_un_7_);
	cppVar_50093 = (cppVar_50034 << 7) | cppVar_50092;
	cppVar_50093 = (cppVar_50093 & cppMask_un_8_);
	cppVar_50030 = cppVar_50093;
	} else {
	cppVar_50095 = ROM.rd(PC);
	cppVar_50097 = (cppVar_50095 == 152);
	if (cppVar_50097) {
	cppVar_50100 = (PSW >> 3) & cppMask_un_2_;
	cppVar_50102 = (cppVar_50100 << 3) | 0;
	cppVar_50102 = (cppVar_50102 & cppMask_un_5_);
	cppVar_50103 = (0 << 5) | cppVar_50102;
	cppVar_50103 = (cppVar_50103 & cppMask_un_8_);
	cppVar_50104 = IRAM.rd(cppVar_50103);
	cppVar_50105 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50106 = (cppVar_50105 & cppMask_un_1_);
	cppVar_50107 = cppVar_50104 + cppVar_50106;
	cppVar_50107 = (cppVar_50107 & cppMask_un_8_);
	cppVar_50108 = ACC < cppVar_50107;
	if (cppVar_50108) {
	cppVar_50098 = 1;
	} else {
	cppVar_50098 = 0;
	}
	cppVar_50112 = (ACC >> 0) & cppMask_un_4_;
	cppVar_50113 = (cppVar_50112 & cppMask_un_4_);
	cppVar_50114 = (PSW >> 3) & cppMask_un_2_;
	cppVar_50115 = (cppVar_50114 << 3) | 0;
	cppVar_50115 = (cppVar_50115 & cppMask_un_5_);
	cppVar_50116 = (0 << 5) | cppVar_50115;
	cppVar_50116 = (cppVar_50116 & cppMask_un_8_);
	cppVar_50117 = IRAM.rd(cppVar_50116);
	cppVar_50118 = (cppVar_50117 >> 0) & cppMask_un_4_;
	cppVar_50119 = (cppVar_50118 & cppMask_un_4_);
	cppVar_50120 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50121 = (cppVar_50120 & cppMask_un_1_);
	cppVar_50122 = cppVar_50119 + cppVar_50121;
	cppVar_50122 = (cppVar_50122 & cppMask_un_5_);
	cppVar_50123 = cppVar_50113 < cppVar_50122;
	if (cppVar_50123) {
	cppVar_50111 = 1;
	} else {
	cppVar_50111 = 0;
	}
	cppVar_50126 = (PSW >> 3) & cppMask_un_3_;
	cppVar_50128 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_50129 = (PSW >> 3) & cppMask_un_2_;
	cppVar_50130 = (cppVar_50129 << 3) | 0;
	cppVar_50130 = (cppVar_50130 & cppMask_un_5_);
	cppVar_50131 = (0 << 5) | cppVar_50130;
	cppVar_50131 = (cppVar_50131 & cppMask_un_8_);
	cppVar_50132 = IRAM.rd(cppVar_50131);
	cppVar_50133 = ((cppVar_50132 & cppMask_bit_8_) ? (cppVar_50132 | cppMask_sign_8_) : cppVar_50132);
	cppVar_50134 = cppVar_50128 - cppVar_50133;
	cppVar_50134 = (cppVar_50134 & cppMask_un_9_);
	cppVar_50135 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50136 = ((cppVar_50135 & cppMask_bit_1_) ? (cppVar_50135 | cppMask_sign_1_) : cppVar_50135);
	cppVar_50137 = cppVar_50134 + cppVar_50136;
	cppVar_50137 = (cppVar_50137 & cppMask_un_9_);
	cppVar_50138 = (cppVar_50137 >> 8) & cppMask_un_1_;
	cppVar_50139 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_50140 = (PSW >> 3) & cppMask_un_2_;
	cppVar_50141 = (cppVar_50140 << 3) | 0;
	cppVar_50141 = (cppVar_50141 & cppMask_un_5_);
	cppVar_50142 = (0 << 5) | cppVar_50141;
	cppVar_50142 = (cppVar_50142 & cppMask_un_8_);
	cppVar_50143 = IRAM.rd(cppVar_50142);
	cppVar_50144 = ((cppVar_50143 & cppMask_bit_8_) ? (cppVar_50143 | cppMask_sign_8_) : cppVar_50143);
	cppVar_50145 = cppVar_50139 - cppVar_50144;
	cppVar_50145 = (cppVar_50145 & cppMask_un_9_);
	cppVar_50146 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50147 = ((cppVar_50146 & cppMask_bit_1_) ? (cppVar_50146 | cppMask_sign_1_) : cppVar_50146);
	cppVar_50148 = cppVar_50145 + cppVar_50147;
	cppVar_50148 = (cppVar_50148 & cppMask_un_9_);
	cppVar_50149 = (cppVar_50148 >> 7) & cppMask_un_1_;
	cppVar_50150 = (cppVar_50138 != cppVar_50149);
	if (cppVar_50150) {
	cppVar_50127 = 1;
	} else {
	cppVar_50127 = 0;
	}
	cppVar_50153 = (PSW >> 0) & cppMask_un_2_;
	cppVar_50154 = (cppVar_50127 << 2) | cppVar_50153;
	cppVar_50154 = (cppVar_50154 & cppMask_un_3_);
	cppVar_50155 = (cppVar_50126 << 3) | cppVar_50154;
	cppVar_50155 = (cppVar_50155 & cppMask_un_6_);
	cppVar_50156 = (cppVar_50111 << 6) | cppVar_50155;
	cppVar_50156 = (cppVar_50156 & cppMask_un_7_);
	cppVar_50157 = (cppVar_50098 << 7) | cppVar_50156;
	cppVar_50157 = (cppVar_50157 & cppMask_un_8_);
	cppVar_50094 = cppVar_50157;
	} else {
	cppVar_50159 = ROM.rd(PC);
	cppVar_50161 = (cppVar_50159 == 151);
	if (cppVar_50161) {
	cppVar_50163 = (ACC & cppMask_un_8_);
	cppVar_50165 = (PSW >> 3) & cppMask_un_2_;
	cppVar_50167 = (cppVar_50165 << 3) | 1;
	cppVar_50167 = (cppVar_50167 & cppMask_un_5_);
	cppVar_50168 = (0 << 5) | cppVar_50167;
	cppVar_50168 = (cppVar_50168 & cppMask_un_8_);
	cppVar_50169 = IRAM.rd(cppVar_50168);
	cppVar_50170 = IRAM.rd(cppVar_50169);
	cppVar_50171 = (cppVar_50170 & cppMask_un_8_);
	cppVar_50172 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50173 = ((cppVar_50172 & cppMask_bit_1_) ? (cppVar_50172 | cppMask_sign_1_) : cppVar_50172);
	cppVar_50174 = cppVar_50171 + cppVar_50173;
	cppVar_50174 = (cppVar_50174 & cppMask_un_9_);
	cppVar_50175 = cppVar_50163 < cppVar_50174;
	if (cppVar_50175) {
	cppVar_50162 = 1;
	} else {
	cppVar_50162 = 0;
	}
	cppVar_50179 = (ACC >> 0) & cppMask_un_4_;
	cppVar_50180 = (cppVar_50179 & cppMask_un_4_);
	cppVar_50181 = (PSW >> 3) & cppMask_un_2_;
	cppVar_50182 = (cppVar_50181 << 3) | 1;
	cppVar_50182 = (cppVar_50182 & cppMask_un_5_);
	cppVar_50183 = (0 << 5) | cppVar_50182;
	cppVar_50183 = (cppVar_50183 & cppMask_un_8_);
	cppVar_50184 = IRAM.rd(cppVar_50183);
	cppVar_50185 = IRAM.rd(cppVar_50184);
	cppVar_50186 = (cppVar_50185 >> 0) & cppMask_un_4_;
	cppVar_50187 = (cppVar_50186 & cppMask_un_4_);
	cppVar_50188 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50189 = (cppVar_50188 & cppMask_un_1_);
	cppVar_50190 = cppVar_50187 + cppVar_50189;
	cppVar_50190 = (cppVar_50190 & cppMask_un_5_);
	cppVar_50191 = cppVar_50180 < cppVar_50190;
	if (cppVar_50191) {
	cppVar_50178 = 1;
	} else {
	cppVar_50178 = 0;
	}
	cppVar_50194 = (PSW >> 3) & cppMask_un_3_;
	cppVar_50196 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_50197 = (PSW >> 3) & cppMask_un_2_;
	cppVar_50198 = (cppVar_50197 << 3) | 1;
	cppVar_50198 = (cppVar_50198 & cppMask_un_5_);
	cppVar_50199 = (0 << 5) | cppVar_50198;
	cppVar_50199 = (cppVar_50199 & cppMask_un_8_);
	cppVar_50200 = IRAM.rd(cppVar_50199);
	cppVar_50201 = IRAM.rd(cppVar_50200);
	cppVar_50202 = ((cppVar_50201 & cppMask_bit_8_) ? (cppVar_50201 | cppMask_sign_8_) : cppVar_50201);
	cppVar_50203 = cppVar_50196 - cppVar_50202;
	cppVar_50203 = (cppVar_50203 & cppMask_un_9_);
	cppVar_50204 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50205 = ((cppVar_50204 & cppMask_bit_1_) ? (cppVar_50204 | cppMask_sign_1_) : cppVar_50204);
	cppVar_50206 = cppVar_50203 + cppVar_50205;
	cppVar_50206 = (cppVar_50206 & cppMask_un_9_);
	cppVar_50207 = (cppVar_50206 >> 8) & cppMask_un_1_;
	cppVar_50208 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_50209 = (PSW >> 3) & cppMask_un_2_;
	cppVar_50210 = (cppVar_50209 << 3) | 1;
	cppVar_50210 = (cppVar_50210 & cppMask_un_5_);
	cppVar_50211 = (0 << 5) | cppVar_50210;
	cppVar_50211 = (cppVar_50211 & cppMask_un_8_);
	cppVar_50212 = IRAM.rd(cppVar_50211);
	cppVar_50213 = IRAM.rd(cppVar_50212);
	cppVar_50214 = ((cppVar_50213 & cppMask_bit_8_) ? (cppVar_50213 | cppMask_sign_8_) : cppVar_50213);
	cppVar_50215 = cppVar_50208 - cppVar_50214;
	cppVar_50215 = (cppVar_50215 & cppMask_un_9_);
	cppVar_50216 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50217 = ((cppVar_50216 & cppMask_bit_1_) ? (cppVar_50216 | cppMask_sign_1_) : cppVar_50216);
	cppVar_50218 = cppVar_50215 + cppVar_50217;
	cppVar_50218 = (cppVar_50218 & cppMask_un_9_);
	cppVar_50219 = (cppVar_50218 >> 7) & cppMask_un_1_;
	cppVar_50220 = (cppVar_50207 != cppVar_50219);
	if (cppVar_50220) {
	cppVar_50195 = 1;
	} else {
	cppVar_50195 = 0;
	}
	cppVar_50223 = (PSW >> 0) & cppMask_un_2_;
	cppVar_50224 = (cppVar_50195 << 2) | cppVar_50223;
	cppVar_50224 = (cppVar_50224 & cppMask_un_3_);
	cppVar_50225 = (cppVar_50194 << 3) | cppVar_50224;
	cppVar_50225 = (cppVar_50225 & cppMask_un_6_);
	cppVar_50226 = (cppVar_50178 << 6) | cppVar_50225;
	cppVar_50226 = (cppVar_50226 & cppMask_un_7_);
	cppVar_50227 = (cppVar_50162 << 7) | cppVar_50226;
	cppVar_50227 = (cppVar_50227 & cppMask_un_8_);
	cppVar_50158 = cppVar_50227;
	} else {
	cppVar_50229 = ROM.rd(PC);
	cppVar_50231 = (cppVar_50229 == 150);
	if (cppVar_50231) {
	cppVar_50233 = (ACC & cppMask_un_8_);
	cppVar_50235 = (PSW >> 3) & cppMask_un_2_;
	cppVar_50237 = (cppVar_50235 << 3) | 0;
	cppVar_50237 = (cppVar_50237 & cppMask_un_5_);
	cppVar_50238 = (0 << 5) | cppVar_50237;
	cppVar_50238 = (cppVar_50238 & cppMask_un_8_);
	cppVar_50239 = IRAM.rd(cppVar_50238);
	cppVar_50240 = IRAM.rd(cppVar_50239);
	cppVar_50241 = (cppVar_50240 & cppMask_un_8_);
	cppVar_50242 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50243 = ((cppVar_50242 & cppMask_bit_1_) ? (cppVar_50242 | cppMask_sign_1_) : cppVar_50242);
	cppVar_50244 = cppVar_50241 + cppVar_50243;
	cppVar_50244 = (cppVar_50244 & cppMask_un_9_);
	cppVar_50245 = cppVar_50233 < cppVar_50244;
	if (cppVar_50245) {
	cppVar_50232 = 1;
	} else {
	cppVar_50232 = 0;
	}
	cppVar_50249 = (ACC >> 0) & cppMask_un_4_;
	cppVar_50250 = (cppVar_50249 & cppMask_un_4_);
	cppVar_50251 = (PSW >> 3) & cppMask_un_2_;
	cppVar_50252 = (cppVar_50251 << 3) | 0;
	cppVar_50252 = (cppVar_50252 & cppMask_un_5_);
	cppVar_50253 = (0 << 5) | cppVar_50252;
	cppVar_50253 = (cppVar_50253 & cppMask_un_8_);
	cppVar_50254 = IRAM.rd(cppVar_50253);
	cppVar_50255 = IRAM.rd(cppVar_50254);
	cppVar_50256 = (cppVar_50255 >> 0) & cppMask_un_4_;
	cppVar_50257 = (cppVar_50256 & cppMask_un_4_);
	cppVar_50258 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50259 = (cppVar_50258 & cppMask_un_1_);
	cppVar_50260 = cppVar_50257 + cppVar_50259;
	cppVar_50260 = (cppVar_50260 & cppMask_un_5_);
	cppVar_50261 = cppVar_50250 < cppVar_50260;
	if (cppVar_50261) {
	cppVar_50248 = 1;
	} else {
	cppVar_50248 = 0;
	}
	cppVar_50264 = (PSW >> 3) & cppMask_un_3_;
	cppVar_50266 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_50267 = (PSW >> 3) & cppMask_un_2_;
	cppVar_50268 = (cppVar_50267 << 3) | 0;
	cppVar_50268 = (cppVar_50268 & cppMask_un_5_);
	cppVar_50269 = (0 << 5) | cppVar_50268;
	cppVar_50269 = (cppVar_50269 & cppMask_un_8_);
	cppVar_50270 = IRAM.rd(cppVar_50269);
	cppVar_50271 = IRAM.rd(cppVar_50270);
	cppVar_50272 = ((cppVar_50271 & cppMask_bit_8_) ? (cppVar_50271 | cppMask_sign_8_) : cppVar_50271);
	cppVar_50273 = cppVar_50266 - cppVar_50272;
	cppVar_50273 = (cppVar_50273 & cppMask_un_9_);
	cppVar_50274 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50275 = ((cppVar_50274 & cppMask_bit_1_) ? (cppVar_50274 | cppMask_sign_1_) : cppVar_50274);
	cppVar_50276 = cppVar_50273 + cppVar_50275;
	cppVar_50276 = (cppVar_50276 & cppMask_un_9_);
	cppVar_50277 = (cppVar_50276 >> 8) & cppMask_un_1_;
	cppVar_50278 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_50279 = (PSW >> 3) & cppMask_un_2_;
	cppVar_50280 = (cppVar_50279 << 3) | 0;
	cppVar_50280 = (cppVar_50280 & cppMask_un_5_);
	cppVar_50281 = (0 << 5) | cppVar_50280;
	cppVar_50281 = (cppVar_50281 & cppMask_un_8_);
	cppVar_50282 = IRAM.rd(cppVar_50281);
	cppVar_50283 = IRAM.rd(cppVar_50282);
	cppVar_50284 = ((cppVar_50283 & cppMask_bit_8_) ? (cppVar_50283 | cppMask_sign_8_) : cppVar_50283);
	cppVar_50285 = cppVar_50278 - cppVar_50284;
	cppVar_50285 = (cppVar_50285 & cppMask_un_9_);
	cppVar_50286 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50287 = ((cppVar_50286 & cppMask_bit_1_) ? (cppVar_50286 | cppMask_sign_1_) : cppVar_50286);
	cppVar_50288 = cppVar_50285 + cppVar_50287;
	cppVar_50288 = (cppVar_50288 & cppMask_un_9_);
	cppVar_50289 = (cppVar_50288 >> 7) & cppMask_un_1_;
	cppVar_50290 = (cppVar_50277 != cppVar_50289);
	if (cppVar_50290) {
	cppVar_50265 = 1;
	} else {
	cppVar_50265 = 0;
	}
	cppVar_50293 = (PSW >> 0) & cppMask_un_2_;
	cppVar_50294 = (cppVar_50265 << 2) | cppVar_50293;
	cppVar_50294 = (cppVar_50294 & cppMask_un_3_);
	cppVar_50295 = (cppVar_50264 << 3) | cppVar_50294;
	cppVar_50295 = (cppVar_50295 & cppMask_un_6_);
	cppVar_50296 = (cppVar_50248 << 6) | cppVar_50295;
	cppVar_50296 = (cppVar_50296 & cppMask_un_7_);
	cppVar_50297 = (cppVar_50232 << 7) | cppVar_50296;
	cppVar_50297 = (cppVar_50297 & cppMask_un_8_);
	cppVar_50228 = cppVar_50297;
	} else {
	cppVar_50299 = ROM.rd(PC);
	cppVar_50301 = (cppVar_50299 == 149);
	if (cppVar_50301) {
	cppVar_50305 = PC + 1;
	cppVar_50305 = (cppVar_50305 & cppMask_un_16_);
	cppVar_50306 = ROM.rd(cppVar_50305);
	cppVar_50307 = (cppVar_50306 >> 7) & cppMask_un_1_;
	cppVar_50309 = (cppVar_50307 == 0);
	if (cppVar_50309) {
	cppVar_50310 = PC + 1;
	cppVar_50310 = (cppVar_50310 & cppMask_un_16_);
	cppVar_50311 = ROM.rd(cppVar_50310);
	cppVar_50312 = IRAM.rd(cppVar_50311);
	cppVar_50303 = cppVar_50312;
	} else {
	cppVar_50314 = PC + 1;
	cppVar_50314 = (cppVar_50314 & cppMask_un_16_);
	cppVar_50315 = ROM.rd(cppVar_50314);
	cppVar_50317 = (cppVar_50315 == 128);
	if (cppVar_50317) {
	cppVar_50313 = P0;
	} else {
	cppVar_50319 = PC + 1;
	cppVar_50319 = (cppVar_50319 & cppMask_un_16_);
	cppVar_50320 = ROM.rd(cppVar_50319);
	cppVar_50322 = (cppVar_50320 == 129);
	if (cppVar_50322) {
	cppVar_50318 = SP;
	} else {
	cppVar_50324 = PC + 1;
	cppVar_50324 = (cppVar_50324 & cppMask_un_16_);
	cppVar_50325 = ROM.rd(cppVar_50324);
	cppVar_50327 = (cppVar_50325 == 130);
	if (cppVar_50327) {
	cppVar_50323 = DPL;
	} else {
	cppVar_50329 = PC + 1;
	cppVar_50329 = (cppVar_50329 & cppMask_un_16_);
	cppVar_50330 = ROM.rd(cppVar_50329);
	cppVar_50332 = (cppVar_50330 == 131);
	if (cppVar_50332) {
	cppVar_50328 = DPH;
	} else {
	cppVar_50334 = PC + 1;
	cppVar_50334 = (cppVar_50334 & cppMask_un_16_);
	cppVar_50335 = ROM.rd(cppVar_50334);
	cppVar_50337 = (cppVar_50335 == 135);
	if (cppVar_50337) {
	cppVar_50333 = PCON;
	} else {
	cppVar_50339 = PC + 1;
	cppVar_50339 = (cppVar_50339 & cppMask_un_16_);
	cppVar_50340 = ROM.rd(cppVar_50339);
	cppVar_50342 = (cppVar_50340 == 136);
	if (cppVar_50342) {
	cppVar_50338 = TCON;
	} else {
	cppVar_50344 = PC + 1;
	cppVar_50344 = (cppVar_50344 & cppMask_un_16_);
	cppVar_50345 = ROM.rd(cppVar_50344);
	cppVar_50347 = (cppVar_50345 == 137);
	if (cppVar_50347) {
	cppVar_50343 = TMOD;
	} else {
	cppVar_50349 = PC + 1;
	cppVar_50349 = (cppVar_50349 & cppMask_un_16_);
	cppVar_50350 = ROM.rd(cppVar_50349);
	cppVar_50352 = (cppVar_50350 == 138);
	if (cppVar_50352) {
	cppVar_50348 = TL0;
	} else {
	cppVar_50354 = PC + 1;
	cppVar_50354 = (cppVar_50354 & cppMask_un_16_);
	cppVar_50355 = ROM.rd(cppVar_50354);
	cppVar_50357 = (cppVar_50355 == 140);
	if (cppVar_50357) {
	cppVar_50353 = TH0;
	} else {
	cppVar_50359 = PC + 1;
	cppVar_50359 = (cppVar_50359 & cppMask_un_16_);
	cppVar_50360 = ROM.rd(cppVar_50359);
	cppVar_50362 = (cppVar_50360 == 139);
	if (cppVar_50362) {
	cppVar_50358 = TL1;
	} else {
	cppVar_50364 = PC + 1;
	cppVar_50364 = (cppVar_50364 & cppMask_un_16_);
	cppVar_50365 = ROM.rd(cppVar_50364);
	cppVar_50367 = (cppVar_50365 == 141);
	if (cppVar_50367) {
	cppVar_50363 = TH1;
	} else {
	cppVar_50369 = PC + 1;
	cppVar_50369 = (cppVar_50369 & cppMask_un_16_);
	cppVar_50370 = ROM.rd(cppVar_50369);
	cppVar_50372 = (cppVar_50370 == 144);
	if (cppVar_50372) {
	cppVar_50368 = P1;
	} else {
	cppVar_50374 = PC + 1;
	cppVar_50374 = (cppVar_50374 & cppMask_un_16_);
	cppVar_50375 = ROM.rd(cppVar_50374);
	cppVar_50377 = (cppVar_50375 == 152);
	if (cppVar_50377) {
	cppVar_50373 = SCON;
	} else {
	cppVar_50379 = PC + 1;
	cppVar_50379 = (cppVar_50379 & cppMask_un_16_);
	cppVar_50380 = ROM.rd(cppVar_50379);
	cppVar_50382 = (cppVar_50380 == 153);
	if (cppVar_50382) {
	cppVar_50378 = SBUF;
	} else {
	cppVar_50384 = PC + 1;
	cppVar_50384 = (cppVar_50384 & cppMask_un_16_);
	cppVar_50385 = ROM.rd(cppVar_50384);
	cppVar_50387 = (cppVar_50385 == 160);
	if (cppVar_50387) {
	cppVar_50383 = P2;
	} else {
	cppVar_50389 = PC + 1;
	cppVar_50389 = (cppVar_50389 & cppMask_un_16_);
	cppVar_50390 = ROM.rd(cppVar_50389);
	cppVar_50392 = (cppVar_50390 == 168);
	if (cppVar_50392) {
	cppVar_50388 = IE;
	} else {
	cppVar_50394 = PC + 1;
	cppVar_50394 = (cppVar_50394 & cppMask_un_16_);
	cppVar_50395 = ROM.rd(cppVar_50394);
	cppVar_50397 = (cppVar_50395 == 176);
	if (cppVar_50397) {
	cppVar_50393 = P3;
	} else {
	cppVar_50399 = PC + 1;
	cppVar_50399 = (cppVar_50399 & cppMask_un_16_);
	cppVar_50400 = ROM.rd(cppVar_50399);
	cppVar_50402 = (cppVar_50400 == 184);
	if (cppVar_50402) {
	cppVar_50398 = IP;
	} else {
	cppVar_50404 = PC + 1;
	cppVar_50404 = (cppVar_50404 & cppMask_un_16_);
	cppVar_50405 = ROM.rd(cppVar_50404);
	cppVar_50407 = (cppVar_50405 == 208);
	if (cppVar_50407) {
	cppVar_50403 = PSW;
	} else {
	cppVar_50409 = PC + 1;
	cppVar_50409 = (cppVar_50409 & cppMask_un_16_);
	cppVar_50410 = ROM.rd(cppVar_50409);
	cppVar_50412 = (cppVar_50410 == 224);
	if (cppVar_50412) {
	cppVar_50408 = ACC;
	} else {
	cppVar_50414 = PC + 1;
	cppVar_50414 = (cppVar_50414 & cppMask_un_16_);
	cppVar_50415 = ROM.rd(cppVar_50414);
	cppVar_50417 = (cppVar_50415 == 240);
	if (cppVar_50417) {
	cppVar_50413 = B;
	} else {
	cppVar_50413 = 0;
	}
	cppVar_50408 = cppVar_50413;
	}
	cppVar_50403 = cppVar_50408;
	}
	cppVar_50398 = cppVar_50403;
	}
	cppVar_50393 = cppVar_50398;
	}
	cppVar_50388 = cppVar_50393;
	}
	cppVar_50383 = cppVar_50388;
	}
	cppVar_50378 = cppVar_50383;
	}
	cppVar_50373 = cppVar_50378;
	}
	cppVar_50368 = cppVar_50373;
	}
	cppVar_50363 = cppVar_50368;
	}
	cppVar_50358 = cppVar_50363;
	}
	cppVar_50353 = cppVar_50358;
	}
	cppVar_50348 = cppVar_50353;
	}
	cppVar_50343 = cppVar_50348;
	}
	cppVar_50338 = cppVar_50343;
	}
	cppVar_50333 = cppVar_50338;
	}
	cppVar_50328 = cppVar_50333;
	}
	cppVar_50323 = cppVar_50328;
	}
	cppVar_50318 = cppVar_50323;
	}
	cppVar_50313 = cppVar_50318;
	}
	cppVar_50303 = cppVar_50313;
	}
	cppVar_50419 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50420 = (cppVar_50419 & cppMask_un_1_);
	cppVar_50421 = cppVar_50303 + cppVar_50420;
	cppVar_50421 = (cppVar_50421 & cppMask_un_8_);
	cppVar_50422 = ACC < cppVar_50421;
	if (cppVar_50422) {
	cppVar_50302 = 1;
	} else {
	cppVar_50302 = 0;
	}
	cppVar_50426 = (ACC >> 0) & cppMask_un_4_;
	cppVar_50427 = (cppVar_50426 & cppMask_un_4_);
	cppVar_50429 = PC + 1;
	cppVar_50429 = (cppVar_50429 & cppMask_un_16_);
	cppVar_50430 = ROM.rd(cppVar_50429);
	cppVar_50431 = (cppVar_50430 >> 7) & cppMask_un_1_;
	cppVar_50432 = (cppVar_50431 == 0);
	if (cppVar_50432) {
	cppVar_50433 = PC + 1;
	cppVar_50433 = (cppVar_50433 & cppMask_un_16_);
	cppVar_50434 = ROM.rd(cppVar_50433);
	cppVar_50435 = IRAM.rd(cppVar_50434);
	cppVar_50428 = cppVar_50435;
	} else {
	cppVar_50437 = PC + 1;
	cppVar_50437 = (cppVar_50437 & cppMask_un_16_);
	cppVar_50438 = ROM.rd(cppVar_50437);
	cppVar_50439 = (cppVar_50438 == 128);
	if (cppVar_50439) {
	cppVar_50436 = P0;
	} else {
	cppVar_50441 = PC + 1;
	cppVar_50441 = (cppVar_50441 & cppMask_un_16_);
	cppVar_50442 = ROM.rd(cppVar_50441);
	cppVar_50443 = (cppVar_50442 == 129);
	if (cppVar_50443) {
	cppVar_50440 = SP;
	} else {
	cppVar_50445 = PC + 1;
	cppVar_50445 = (cppVar_50445 & cppMask_un_16_);
	cppVar_50446 = ROM.rd(cppVar_50445);
	cppVar_50447 = (cppVar_50446 == 130);
	if (cppVar_50447) {
	cppVar_50444 = DPL;
	} else {
	cppVar_50449 = PC + 1;
	cppVar_50449 = (cppVar_50449 & cppMask_un_16_);
	cppVar_50450 = ROM.rd(cppVar_50449);
	cppVar_50451 = (cppVar_50450 == 131);
	if (cppVar_50451) {
	cppVar_50448 = DPH;
	} else {
	cppVar_50453 = PC + 1;
	cppVar_50453 = (cppVar_50453 & cppMask_un_16_);
	cppVar_50454 = ROM.rd(cppVar_50453);
	cppVar_50455 = (cppVar_50454 == 135);
	if (cppVar_50455) {
	cppVar_50452 = PCON;
	} else {
	cppVar_50457 = PC + 1;
	cppVar_50457 = (cppVar_50457 & cppMask_un_16_);
	cppVar_50458 = ROM.rd(cppVar_50457);
	cppVar_50459 = (cppVar_50458 == 136);
	if (cppVar_50459) {
	cppVar_50456 = TCON;
	} else {
	cppVar_50461 = PC + 1;
	cppVar_50461 = (cppVar_50461 & cppMask_un_16_);
	cppVar_50462 = ROM.rd(cppVar_50461);
	cppVar_50463 = (cppVar_50462 == 137);
	if (cppVar_50463) {
	cppVar_50460 = TMOD;
	} else {
	cppVar_50465 = PC + 1;
	cppVar_50465 = (cppVar_50465 & cppMask_un_16_);
	cppVar_50466 = ROM.rd(cppVar_50465);
	cppVar_50467 = (cppVar_50466 == 138);
	if (cppVar_50467) {
	cppVar_50464 = TL0;
	} else {
	cppVar_50469 = PC + 1;
	cppVar_50469 = (cppVar_50469 & cppMask_un_16_);
	cppVar_50470 = ROM.rd(cppVar_50469);
	cppVar_50471 = (cppVar_50470 == 140);
	if (cppVar_50471) {
	cppVar_50468 = TH0;
	} else {
	cppVar_50473 = PC + 1;
	cppVar_50473 = (cppVar_50473 & cppMask_un_16_);
	cppVar_50474 = ROM.rd(cppVar_50473);
	cppVar_50475 = (cppVar_50474 == 139);
	if (cppVar_50475) {
	cppVar_50472 = TL1;
	} else {
	cppVar_50477 = PC + 1;
	cppVar_50477 = (cppVar_50477 & cppMask_un_16_);
	cppVar_50478 = ROM.rd(cppVar_50477);
	cppVar_50479 = (cppVar_50478 == 141);
	if (cppVar_50479) {
	cppVar_50476 = TH1;
	} else {
	cppVar_50481 = PC + 1;
	cppVar_50481 = (cppVar_50481 & cppMask_un_16_);
	cppVar_50482 = ROM.rd(cppVar_50481);
	cppVar_50483 = (cppVar_50482 == 144);
	if (cppVar_50483) {
	cppVar_50480 = P1;
	} else {
	cppVar_50485 = PC + 1;
	cppVar_50485 = (cppVar_50485 & cppMask_un_16_);
	cppVar_50486 = ROM.rd(cppVar_50485);
	cppVar_50487 = (cppVar_50486 == 152);
	if (cppVar_50487) {
	cppVar_50484 = SCON;
	} else {
	cppVar_50489 = PC + 1;
	cppVar_50489 = (cppVar_50489 & cppMask_un_16_);
	cppVar_50490 = ROM.rd(cppVar_50489);
	cppVar_50491 = (cppVar_50490 == 153);
	if (cppVar_50491) {
	cppVar_50488 = SBUF;
	} else {
	cppVar_50493 = PC + 1;
	cppVar_50493 = (cppVar_50493 & cppMask_un_16_);
	cppVar_50494 = ROM.rd(cppVar_50493);
	cppVar_50495 = (cppVar_50494 == 160);
	if (cppVar_50495) {
	cppVar_50492 = P2;
	} else {
	cppVar_50497 = PC + 1;
	cppVar_50497 = (cppVar_50497 & cppMask_un_16_);
	cppVar_50498 = ROM.rd(cppVar_50497);
	cppVar_50499 = (cppVar_50498 == 168);
	if (cppVar_50499) {
	cppVar_50496 = IE;
	} else {
	cppVar_50501 = PC + 1;
	cppVar_50501 = (cppVar_50501 & cppMask_un_16_);
	cppVar_50502 = ROM.rd(cppVar_50501);
	cppVar_50503 = (cppVar_50502 == 176);
	if (cppVar_50503) {
	cppVar_50500 = P3;
	} else {
	cppVar_50505 = PC + 1;
	cppVar_50505 = (cppVar_50505 & cppMask_un_16_);
	cppVar_50506 = ROM.rd(cppVar_50505);
	cppVar_50507 = (cppVar_50506 == 184);
	if (cppVar_50507) {
	cppVar_50504 = IP;
	} else {
	cppVar_50509 = PC + 1;
	cppVar_50509 = (cppVar_50509 & cppMask_un_16_);
	cppVar_50510 = ROM.rd(cppVar_50509);
	cppVar_50511 = (cppVar_50510 == 208);
	if (cppVar_50511) {
	cppVar_50508 = PSW;
	} else {
	cppVar_50513 = PC + 1;
	cppVar_50513 = (cppVar_50513 & cppMask_un_16_);
	cppVar_50514 = ROM.rd(cppVar_50513);
	cppVar_50515 = (cppVar_50514 == 224);
	if (cppVar_50515) {
	cppVar_50512 = ACC;
	} else {
	cppVar_50517 = PC + 1;
	cppVar_50517 = (cppVar_50517 & cppMask_un_16_);
	cppVar_50518 = ROM.rd(cppVar_50517);
	cppVar_50519 = (cppVar_50518 == 240);
	if (cppVar_50519) {
	cppVar_50516 = B;
	} else {
	cppVar_50516 = 0;
	}
	cppVar_50512 = cppVar_50516;
	}
	cppVar_50508 = cppVar_50512;
	}
	cppVar_50504 = cppVar_50508;
	}
	cppVar_50500 = cppVar_50504;
	}
	cppVar_50496 = cppVar_50500;
	}
	cppVar_50492 = cppVar_50496;
	}
	cppVar_50488 = cppVar_50492;
	}
	cppVar_50484 = cppVar_50488;
	}
	cppVar_50480 = cppVar_50484;
	}
	cppVar_50476 = cppVar_50480;
	}
	cppVar_50472 = cppVar_50476;
	}
	cppVar_50468 = cppVar_50472;
	}
	cppVar_50464 = cppVar_50468;
	}
	cppVar_50460 = cppVar_50464;
	}
	cppVar_50456 = cppVar_50460;
	}
	cppVar_50452 = cppVar_50456;
	}
	cppVar_50448 = cppVar_50452;
	}
	cppVar_50444 = cppVar_50448;
	}
	cppVar_50440 = cppVar_50444;
	}
	cppVar_50436 = cppVar_50440;
	}
	cppVar_50428 = cppVar_50436;
	}
	cppVar_50520 = (cppVar_50428 >> 0) & cppMask_un_4_;
	cppVar_50521 = (cppVar_50520 & cppMask_un_4_);
	cppVar_50522 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50523 = (cppVar_50522 & cppMask_un_1_);
	cppVar_50524 = cppVar_50521 + cppVar_50523;
	cppVar_50524 = (cppVar_50524 & cppMask_un_5_);
	cppVar_50525 = cppVar_50427 < cppVar_50524;
	if (cppVar_50525) {
	cppVar_50425 = 1;
	} else {
	cppVar_50425 = 0;
	}
	cppVar_50528 = (PSW >> 3) & cppMask_un_3_;
	cppVar_50530 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_50532 = PC + 1;
	cppVar_50532 = (cppVar_50532 & cppMask_un_16_);
	cppVar_50533 = ROM.rd(cppVar_50532);
	cppVar_50534 = (cppVar_50533 >> 7) & cppMask_un_1_;
	cppVar_50535 = (cppVar_50534 == 0);
	if (cppVar_50535) {
	cppVar_50536 = PC + 1;
	cppVar_50536 = (cppVar_50536 & cppMask_un_16_);
	cppVar_50537 = ROM.rd(cppVar_50536);
	cppVar_50538 = IRAM.rd(cppVar_50537);
	cppVar_50531 = cppVar_50538;
	} else {
	cppVar_50540 = PC + 1;
	cppVar_50540 = (cppVar_50540 & cppMask_un_16_);
	cppVar_50541 = ROM.rd(cppVar_50540);
	cppVar_50542 = (cppVar_50541 == 128);
	if (cppVar_50542) {
	cppVar_50539 = P0;
	} else {
	cppVar_50544 = PC + 1;
	cppVar_50544 = (cppVar_50544 & cppMask_un_16_);
	cppVar_50545 = ROM.rd(cppVar_50544);
	cppVar_50546 = (cppVar_50545 == 129);
	if (cppVar_50546) {
	cppVar_50543 = SP;
	} else {
	cppVar_50548 = PC + 1;
	cppVar_50548 = (cppVar_50548 & cppMask_un_16_);
	cppVar_50549 = ROM.rd(cppVar_50548);
	cppVar_50550 = (cppVar_50549 == 130);
	if (cppVar_50550) {
	cppVar_50547 = DPL;
	} else {
	cppVar_50552 = PC + 1;
	cppVar_50552 = (cppVar_50552 & cppMask_un_16_);
	cppVar_50553 = ROM.rd(cppVar_50552);
	cppVar_50554 = (cppVar_50553 == 131);
	if (cppVar_50554) {
	cppVar_50551 = DPH;
	} else {
	cppVar_50556 = PC + 1;
	cppVar_50556 = (cppVar_50556 & cppMask_un_16_);
	cppVar_50557 = ROM.rd(cppVar_50556);
	cppVar_50558 = (cppVar_50557 == 135);
	if (cppVar_50558) {
	cppVar_50555 = PCON;
	} else {
	cppVar_50560 = PC + 1;
	cppVar_50560 = (cppVar_50560 & cppMask_un_16_);
	cppVar_50561 = ROM.rd(cppVar_50560);
	cppVar_50562 = (cppVar_50561 == 136);
	if (cppVar_50562) {
	cppVar_50559 = TCON;
	} else {
	cppVar_50564 = PC + 1;
	cppVar_50564 = (cppVar_50564 & cppMask_un_16_);
	cppVar_50565 = ROM.rd(cppVar_50564);
	cppVar_50566 = (cppVar_50565 == 137);
	if (cppVar_50566) {
	cppVar_50563 = TMOD;
	} else {
	cppVar_50568 = PC + 1;
	cppVar_50568 = (cppVar_50568 & cppMask_un_16_);
	cppVar_50569 = ROM.rd(cppVar_50568);
	cppVar_50570 = (cppVar_50569 == 138);
	if (cppVar_50570) {
	cppVar_50567 = TL0;
	} else {
	cppVar_50572 = PC + 1;
	cppVar_50572 = (cppVar_50572 & cppMask_un_16_);
	cppVar_50573 = ROM.rd(cppVar_50572);
	cppVar_50574 = (cppVar_50573 == 140);
	if (cppVar_50574) {
	cppVar_50571 = TH0;
	} else {
	cppVar_50576 = PC + 1;
	cppVar_50576 = (cppVar_50576 & cppMask_un_16_);
	cppVar_50577 = ROM.rd(cppVar_50576);
	cppVar_50578 = (cppVar_50577 == 139);
	if (cppVar_50578) {
	cppVar_50575 = TL1;
	} else {
	cppVar_50580 = PC + 1;
	cppVar_50580 = (cppVar_50580 & cppMask_un_16_);
	cppVar_50581 = ROM.rd(cppVar_50580);
	cppVar_50582 = (cppVar_50581 == 141);
	if (cppVar_50582) {
	cppVar_50579 = TH1;
	} else {
	cppVar_50584 = PC + 1;
	cppVar_50584 = (cppVar_50584 & cppMask_un_16_);
	cppVar_50585 = ROM.rd(cppVar_50584);
	cppVar_50586 = (cppVar_50585 == 144);
	if (cppVar_50586) {
	cppVar_50583 = P1;
	} else {
	cppVar_50588 = PC + 1;
	cppVar_50588 = (cppVar_50588 & cppMask_un_16_);
	cppVar_50589 = ROM.rd(cppVar_50588);
	cppVar_50590 = (cppVar_50589 == 152);
	if (cppVar_50590) {
	cppVar_50587 = SCON;
	} else {
	cppVar_50592 = PC + 1;
	cppVar_50592 = (cppVar_50592 & cppMask_un_16_);
	cppVar_50593 = ROM.rd(cppVar_50592);
	cppVar_50594 = (cppVar_50593 == 153);
	if (cppVar_50594) {
	cppVar_50591 = SBUF;
	} else {
	cppVar_50596 = PC + 1;
	cppVar_50596 = (cppVar_50596 & cppMask_un_16_);
	cppVar_50597 = ROM.rd(cppVar_50596);
	cppVar_50598 = (cppVar_50597 == 160);
	if (cppVar_50598) {
	cppVar_50595 = P2;
	} else {
	cppVar_50600 = PC + 1;
	cppVar_50600 = (cppVar_50600 & cppMask_un_16_);
	cppVar_50601 = ROM.rd(cppVar_50600);
	cppVar_50602 = (cppVar_50601 == 168);
	if (cppVar_50602) {
	cppVar_50599 = IE;
	} else {
	cppVar_50604 = PC + 1;
	cppVar_50604 = (cppVar_50604 & cppMask_un_16_);
	cppVar_50605 = ROM.rd(cppVar_50604);
	cppVar_50606 = (cppVar_50605 == 176);
	if (cppVar_50606) {
	cppVar_50603 = P3;
	} else {
	cppVar_50608 = PC + 1;
	cppVar_50608 = (cppVar_50608 & cppMask_un_16_);
	cppVar_50609 = ROM.rd(cppVar_50608);
	cppVar_50610 = (cppVar_50609 == 184);
	if (cppVar_50610) {
	cppVar_50607 = IP;
	} else {
	cppVar_50612 = PC + 1;
	cppVar_50612 = (cppVar_50612 & cppMask_un_16_);
	cppVar_50613 = ROM.rd(cppVar_50612);
	cppVar_50614 = (cppVar_50613 == 208);
	if (cppVar_50614) {
	cppVar_50611 = PSW;
	} else {
	cppVar_50616 = PC + 1;
	cppVar_50616 = (cppVar_50616 & cppMask_un_16_);
	cppVar_50617 = ROM.rd(cppVar_50616);
	cppVar_50618 = (cppVar_50617 == 224);
	if (cppVar_50618) {
	cppVar_50615 = ACC;
	} else {
	cppVar_50620 = PC + 1;
	cppVar_50620 = (cppVar_50620 & cppMask_un_16_);
	cppVar_50621 = ROM.rd(cppVar_50620);
	cppVar_50622 = (cppVar_50621 == 240);
	if (cppVar_50622) {
	cppVar_50619 = B;
	} else {
	cppVar_50619 = 0;
	}
	cppVar_50615 = cppVar_50619;
	}
	cppVar_50611 = cppVar_50615;
	}
	cppVar_50607 = cppVar_50611;
	}
	cppVar_50603 = cppVar_50607;
	}
	cppVar_50599 = cppVar_50603;
	}
	cppVar_50595 = cppVar_50599;
	}
	cppVar_50591 = cppVar_50595;
	}
	cppVar_50587 = cppVar_50591;
	}
	cppVar_50583 = cppVar_50587;
	}
	cppVar_50579 = cppVar_50583;
	}
	cppVar_50575 = cppVar_50579;
	}
	cppVar_50571 = cppVar_50575;
	}
	cppVar_50567 = cppVar_50571;
	}
	cppVar_50563 = cppVar_50567;
	}
	cppVar_50559 = cppVar_50563;
	}
	cppVar_50555 = cppVar_50559;
	}
	cppVar_50551 = cppVar_50555;
	}
	cppVar_50547 = cppVar_50551;
	}
	cppVar_50543 = cppVar_50547;
	}
	cppVar_50539 = cppVar_50543;
	}
	cppVar_50531 = cppVar_50539;
	}
	cppVar_50623 = ((cppVar_50531 & cppMask_bit_8_) ? (cppVar_50531 | cppMask_sign_8_) : cppVar_50531);
	cppVar_50624 = cppVar_50530 - cppVar_50623;
	cppVar_50624 = (cppVar_50624 & cppMask_un_9_);
	cppVar_50625 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50626 = ((cppVar_50625 & cppMask_bit_1_) ? (cppVar_50625 | cppMask_sign_1_) : cppVar_50625);
	cppVar_50627 = cppVar_50624 + cppVar_50626;
	cppVar_50627 = (cppVar_50627 & cppMask_un_9_);
	cppVar_50628 = (cppVar_50627 >> 8) & cppMask_un_1_;
	cppVar_50629 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_50631 = PC + 1;
	cppVar_50631 = (cppVar_50631 & cppMask_un_16_);
	cppVar_50632 = ROM.rd(cppVar_50631);
	cppVar_50633 = (cppVar_50632 >> 7) & cppMask_un_1_;
	cppVar_50634 = (cppVar_50633 == 0);
	if (cppVar_50634) {
	cppVar_50635 = PC + 1;
	cppVar_50635 = (cppVar_50635 & cppMask_un_16_);
	cppVar_50636 = ROM.rd(cppVar_50635);
	cppVar_50637 = IRAM.rd(cppVar_50636);
	cppVar_50630 = cppVar_50637;
	} else {
	cppVar_50639 = PC + 1;
	cppVar_50639 = (cppVar_50639 & cppMask_un_16_);
	cppVar_50640 = ROM.rd(cppVar_50639);
	cppVar_50641 = (cppVar_50640 == 128);
	if (cppVar_50641) {
	cppVar_50638 = P0;
	} else {
	cppVar_50643 = PC + 1;
	cppVar_50643 = (cppVar_50643 & cppMask_un_16_);
	cppVar_50644 = ROM.rd(cppVar_50643);
	cppVar_50645 = (cppVar_50644 == 129);
	if (cppVar_50645) {
	cppVar_50642 = SP;
	} else {
	cppVar_50647 = PC + 1;
	cppVar_50647 = (cppVar_50647 & cppMask_un_16_);
	cppVar_50648 = ROM.rd(cppVar_50647);
	cppVar_50649 = (cppVar_50648 == 130);
	if (cppVar_50649) {
	cppVar_50646 = DPL;
	} else {
	cppVar_50651 = PC + 1;
	cppVar_50651 = (cppVar_50651 & cppMask_un_16_);
	cppVar_50652 = ROM.rd(cppVar_50651);
	cppVar_50653 = (cppVar_50652 == 131);
	if (cppVar_50653) {
	cppVar_50650 = DPH;
	} else {
	cppVar_50655 = PC + 1;
	cppVar_50655 = (cppVar_50655 & cppMask_un_16_);
	cppVar_50656 = ROM.rd(cppVar_50655);
	cppVar_50657 = (cppVar_50656 == 135);
	if (cppVar_50657) {
	cppVar_50654 = PCON;
	} else {
	cppVar_50659 = PC + 1;
	cppVar_50659 = (cppVar_50659 & cppMask_un_16_);
	cppVar_50660 = ROM.rd(cppVar_50659);
	cppVar_50661 = (cppVar_50660 == 136);
	if (cppVar_50661) {
	cppVar_50658 = TCON;
	} else {
	cppVar_50663 = PC + 1;
	cppVar_50663 = (cppVar_50663 & cppMask_un_16_);
	cppVar_50664 = ROM.rd(cppVar_50663);
	cppVar_50665 = (cppVar_50664 == 137);
	if (cppVar_50665) {
	cppVar_50662 = TMOD;
	} else {
	cppVar_50667 = PC + 1;
	cppVar_50667 = (cppVar_50667 & cppMask_un_16_);
	cppVar_50668 = ROM.rd(cppVar_50667);
	cppVar_50669 = (cppVar_50668 == 138);
	if (cppVar_50669) {
	cppVar_50666 = TL0;
	} else {
	cppVar_50671 = PC + 1;
	cppVar_50671 = (cppVar_50671 & cppMask_un_16_);
	cppVar_50672 = ROM.rd(cppVar_50671);
	cppVar_50673 = (cppVar_50672 == 140);
	if (cppVar_50673) {
	cppVar_50670 = TH0;
	} else {
	cppVar_50675 = PC + 1;
	cppVar_50675 = (cppVar_50675 & cppMask_un_16_);
	cppVar_50676 = ROM.rd(cppVar_50675);
	cppVar_50677 = (cppVar_50676 == 139);
	if (cppVar_50677) {
	cppVar_50674 = TL1;
	} else {
	cppVar_50679 = PC + 1;
	cppVar_50679 = (cppVar_50679 & cppMask_un_16_);
	cppVar_50680 = ROM.rd(cppVar_50679);
	cppVar_50681 = (cppVar_50680 == 141);
	if (cppVar_50681) {
	cppVar_50678 = TH1;
	} else {
	cppVar_50683 = PC + 1;
	cppVar_50683 = (cppVar_50683 & cppMask_un_16_);
	cppVar_50684 = ROM.rd(cppVar_50683);
	cppVar_50685 = (cppVar_50684 == 144);
	if (cppVar_50685) {
	cppVar_50682 = P1;
	} else {
	cppVar_50687 = PC + 1;
	cppVar_50687 = (cppVar_50687 & cppMask_un_16_);
	cppVar_50688 = ROM.rd(cppVar_50687);
	cppVar_50689 = (cppVar_50688 == 152);
	if (cppVar_50689) {
	cppVar_50686 = SCON;
	} else {
	cppVar_50691 = PC + 1;
	cppVar_50691 = (cppVar_50691 & cppMask_un_16_);
	cppVar_50692 = ROM.rd(cppVar_50691);
	cppVar_50693 = (cppVar_50692 == 153);
	if (cppVar_50693) {
	cppVar_50690 = SBUF;
	} else {
	cppVar_50695 = PC + 1;
	cppVar_50695 = (cppVar_50695 & cppMask_un_16_);
	cppVar_50696 = ROM.rd(cppVar_50695);
	cppVar_50697 = (cppVar_50696 == 160);
	if (cppVar_50697) {
	cppVar_50694 = P2;
	} else {
	cppVar_50699 = PC + 1;
	cppVar_50699 = (cppVar_50699 & cppMask_un_16_);
	cppVar_50700 = ROM.rd(cppVar_50699);
	cppVar_50701 = (cppVar_50700 == 168);
	if (cppVar_50701) {
	cppVar_50698 = IE;
	} else {
	cppVar_50703 = PC + 1;
	cppVar_50703 = (cppVar_50703 & cppMask_un_16_);
	cppVar_50704 = ROM.rd(cppVar_50703);
	cppVar_50705 = (cppVar_50704 == 176);
	if (cppVar_50705) {
	cppVar_50702 = P3;
	} else {
	cppVar_50707 = PC + 1;
	cppVar_50707 = (cppVar_50707 & cppMask_un_16_);
	cppVar_50708 = ROM.rd(cppVar_50707);
	cppVar_50709 = (cppVar_50708 == 184);
	if (cppVar_50709) {
	cppVar_50706 = IP;
	} else {
	cppVar_50711 = PC + 1;
	cppVar_50711 = (cppVar_50711 & cppMask_un_16_);
	cppVar_50712 = ROM.rd(cppVar_50711);
	cppVar_50713 = (cppVar_50712 == 208);
	if (cppVar_50713) {
	cppVar_50710 = PSW;
	} else {
	cppVar_50715 = PC + 1;
	cppVar_50715 = (cppVar_50715 & cppMask_un_16_);
	cppVar_50716 = ROM.rd(cppVar_50715);
	cppVar_50717 = (cppVar_50716 == 224);
	if (cppVar_50717) {
	cppVar_50714 = ACC;
	} else {
	cppVar_50719 = PC + 1;
	cppVar_50719 = (cppVar_50719 & cppMask_un_16_);
	cppVar_50720 = ROM.rd(cppVar_50719);
	cppVar_50721 = (cppVar_50720 == 240);
	if (cppVar_50721) {
	cppVar_50718 = B;
	} else {
	cppVar_50718 = 0;
	}
	cppVar_50714 = cppVar_50718;
	}
	cppVar_50710 = cppVar_50714;
	}
	cppVar_50706 = cppVar_50710;
	}
	cppVar_50702 = cppVar_50706;
	}
	cppVar_50698 = cppVar_50702;
	}
	cppVar_50694 = cppVar_50698;
	}
	cppVar_50690 = cppVar_50694;
	}
	cppVar_50686 = cppVar_50690;
	}
	cppVar_50682 = cppVar_50686;
	}
	cppVar_50678 = cppVar_50682;
	}
	cppVar_50674 = cppVar_50678;
	}
	cppVar_50670 = cppVar_50674;
	}
	cppVar_50666 = cppVar_50670;
	}
	cppVar_50662 = cppVar_50666;
	}
	cppVar_50658 = cppVar_50662;
	}
	cppVar_50654 = cppVar_50658;
	}
	cppVar_50650 = cppVar_50654;
	}
	cppVar_50646 = cppVar_50650;
	}
	cppVar_50642 = cppVar_50646;
	}
	cppVar_50638 = cppVar_50642;
	}
	cppVar_50630 = cppVar_50638;
	}
	cppVar_50722 = ((cppVar_50630 & cppMask_bit_8_) ? (cppVar_50630 | cppMask_sign_8_) : cppVar_50630);
	cppVar_50723 = cppVar_50629 - cppVar_50722;
	cppVar_50723 = (cppVar_50723 & cppMask_un_9_);
	cppVar_50724 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50725 = ((cppVar_50724 & cppMask_bit_1_) ? (cppVar_50724 | cppMask_sign_1_) : cppVar_50724);
	cppVar_50726 = cppVar_50723 + cppVar_50725;
	cppVar_50726 = (cppVar_50726 & cppMask_un_9_);
	cppVar_50727 = (cppVar_50726 >> 7) & cppMask_un_1_;
	cppVar_50728 = (cppVar_50628 != cppVar_50727);
	if (cppVar_50728) {
	cppVar_50529 = 1;
	} else {
	cppVar_50529 = 0;
	}
	cppVar_50731 = (PSW >> 0) & cppMask_un_2_;
	cppVar_50732 = (cppVar_50529 << 2) | cppVar_50731;
	cppVar_50732 = (cppVar_50732 & cppMask_un_3_);
	cppVar_50733 = (cppVar_50528 << 3) | cppVar_50732;
	cppVar_50733 = (cppVar_50733 & cppMask_un_6_);
	cppVar_50734 = (cppVar_50425 << 6) | cppVar_50733;
	cppVar_50734 = (cppVar_50734 & cppMask_un_7_);
	cppVar_50735 = (cppVar_50302 << 7) | cppVar_50734;
	cppVar_50735 = (cppVar_50735 & cppMask_un_8_);
	cppVar_50298 = cppVar_50735;
	} else {
	cppVar_50737 = ROM.rd(PC);
	cppVar_50739 = (cppVar_50737 == 148);
	if (cppVar_50739) {
	cppVar_50742 = PC + 1;
	cppVar_50742 = (cppVar_50742 & cppMask_un_16_);
	cppVar_50743 = ROM.rd(cppVar_50742);
	cppVar_50744 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50745 = (cppVar_50744 & cppMask_un_1_);
	cppVar_50746 = cppVar_50743 + cppVar_50745;
	cppVar_50746 = (cppVar_50746 & cppMask_un_8_);
	cppVar_50747 = ACC < cppVar_50746;
	if (cppVar_50747) {
	cppVar_50740 = 1;
	} else {
	cppVar_50740 = 0;
	}
	cppVar_50751 = (ACC >> 0) & cppMask_un_4_;
	cppVar_50752 = (cppVar_50751 & cppMask_un_4_);
	cppVar_50753 = PC + 1;
	cppVar_50753 = (cppVar_50753 & cppMask_un_16_);
	cppVar_50754 = ROM.rd(cppVar_50753);
	cppVar_50755 = (cppVar_50754 >> 0) & cppMask_un_4_;
	cppVar_50756 = (cppVar_50755 & cppMask_un_4_);
	cppVar_50757 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50758 = (cppVar_50757 & cppMask_un_1_);
	cppVar_50759 = cppVar_50756 + cppVar_50758;
	cppVar_50759 = (cppVar_50759 & cppMask_un_5_);
	cppVar_50760 = cppVar_50752 < cppVar_50759;
	if (cppVar_50760) {
	cppVar_50750 = 1;
	} else {
	cppVar_50750 = 0;
	}
	cppVar_50763 = (PSW >> 3) & cppMask_un_3_;
	cppVar_50765 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_50766 = PC + 1;
	cppVar_50766 = (cppVar_50766 & cppMask_un_16_);
	cppVar_50767 = ROM.rd(cppVar_50766);
	cppVar_50768 = ((cppVar_50767 & cppMask_bit_8_) ? (cppVar_50767 | cppMask_sign_8_) : cppVar_50767);
	cppVar_50769 = cppVar_50765 - cppVar_50768;
	cppVar_50769 = (cppVar_50769 & cppMask_un_9_);
	cppVar_50770 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50771 = ((cppVar_50770 & cppMask_bit_1_) ? (cppVar_50770 | cppMask_sign_1_) : cppVar_50770);
	cppVar_50772 = cppVar_50769 + cppVar_50771;
	cppVar_50772 = (cppVar_50772 & cppMask_un_9_);
	cppVar_50773 = (cppVar_50772 >> 8) & cppMask_un_1_;
	cppVar_50774 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_50775 = PC + 1;
	cppVar_50775 = (cppVar_50775 & cppMask_un_16_);
	cppVar_50776 = ROM.rd(cppVar_50775);
	cppVar_50777 = ((cppVar_50776 & cppMask_bit_8_) ? (cppVar_50776 | cppMask_sign_8_) : cppVar_50776);
	cppVar_50778 = cppVar_50774 - cppVar_50777;
	cppVar_50778 = (cppVar_50778 & cppMask_un_9_);
	cppVar_50779 = (PSW >> 7) & cppMask_un_1_;
	cppVar_50780 = ((cppVar_50779 & cppMask_bit_1_) ? (cppVar_50779 | cppMask_sign_1_) : cppVar_50779);
	cppVar_50781 = cppVar_50778 + cppVar_50780;
	cppVar_50781 = (cppVar_50781 & cppMask_un_9_);
	cppVar_50782 = (cppVar_50781 >> 7) & cppMask_un_1_;
	cppVar_50783 = (cppVar_50773 != cppVar_50782);
	if (cppVar_50783) {
	cppVar_50764 = 1;
	} else {
	cppVar_50764 = 0;
	}
	cppVar_50786 = (PSW >> 0) & cppMask_un_2_;
	cppVar_50787 = (cppVar_50764 << 2) | cppVar_50786;
	cppVar_50787 = (cppVar_50787 & cppMask_un_3_);
	cppVar_50788 = (cppVar_50763 << 3) | cppVar_50787;
	cppVar_50788 = (cppVar_50788 & cppMask_un_6_);
	cppVar_50789 = (cppVar_50750 << 6) | cppVar_50788;
	cppVar_50789 = (cppVar_50789 & cppMask_un_7_);
	cppVar_50790 = (cppVar_50740 << 7) | cppVar_50789;
	cppVar_50790 = (cppVar_50790 & cppMask_un_8_);
	cppVar_50736 = cppVar_50790;
	} else {
	cppVar_50792 = ROM.rd(PC);
	cppVar_50794 = (cppVar_50792 == 146);
	if (cppVar_50794) {
	cppVar_50798 = PC + 1;
	cppVar_50798 = (cppVar_50798 & cppMask_un_16_);
	cppVar_50799 = ROM.rd(cppVar_50798);
	cppVar_50800 = (cppVar_50799 >> 7) & cppMask_un_1_;
	cppVar_50802 = (cppVar_50800 == 1);
	if (cppVar_50802) {
	cppVar_50803 = PC + 1;
	cppVar_50803 = (cppVar_50803 & cppMask_un_16_);
	cppVar_50804 = ROM.rd(cppVar_50803);
	cppVar_50805 = (cppVar_50804 >> 3) & cppMask_un_5_;
	cppVar_50807 = (cppVar_50805 << 3) | 0;
	cppVar_50807 = (cppVar_50807 & cppMask_un_8_);
	cppVar_50796 = cppVar_50807;
	} else {
	cppVar_50808 = PC + 1;
	cppVar_50808 = (cppVar_50808 & cppMask_un_16_);
	cppVar_50809 = ROM.rd(cppVar_50808);
	cppVar_50810 = (cppVar_50809 >> 3) & cppMask_un_5_;
	cppVar_50811 = (cppVar_50810 & cppMask_un_5_);
	cppVar_50813 = cppVar_50811 + 32;
	cppVar_50813 = (cppVar_50813 & cppMask_un_8_);
	cppVar_50796 = cppVar_50813;
	}
	cppVar_50815 = (cppVar_50796 == 208);
	if (cppVar_50815) {
	cppVar_50817 = PC + 1;
	cppVar_50817 = (cppVar_50817 & cppMask_un_16_);
	cppVar_50818 = ROM.rd(cppVar_50817);
	cppVar_50819 = (cppVar_50818 >> 0) & cppMask_un_3_;
	cppVar_50820 = (cppVar_50819 & cppMask_un_3_);
	cppVar_50821 = 1 << static_cast<unsigned>(cppVar_50820);
	cppVar_50821 = (cppVar_50821 & cppMask_un_8_);
	cppVar_50822 = ~cppVar_50821;
	cppVar_50825 = PC + 1;
	cppVar_50825 = (cppVar_50825 & cppMask_un_16_);
	cppVar_50826 = ROM.rd(cppVar_50825);
	cppVar_50827 = (cppVar_50826 >> 7) & cppMask_un_1_;
	cppVar_50828 = (cppVar_50827 == 1);
	if (cppVar_50828) {
	cppVar_50829 = PC + 1;
	cppVar_50829 = (cppVar_50829 & cppMask_un_16_);
	cppVar_50830 = ROM.rd(cppVar_50829);
	cppVar_50831 = (cppVar_50830 >> 3) & cppMask_un_5_;
	cppVar_50832 = (cppVar_50831 << 3) | 0;
	cppVar_50832 = (cppVar_50832 & cppMask_un_8_);
	cppVar_50824 = cppVar_50832;
	} else {
	cppVar_50833 = PC + 1;
	cppVar_50833 = (cppVar_50833 & cppMask_un_16_);
	cppVar_50834 = ROM.rd(cppVar_50833);
	cppVar_50835 = (cppVar_50834 >> 3) & cppMask_un_5_;
	cppVar_50836 = (cppVar_50835 & cppMask_un_5_);
	cppVar_50837 = cppVar_50836 + 32;
	cppVar_50837 = (cppVar_50837 & cppMask_un_8_);
	cppVar_50824 = cppVar_50837;
	}
	cppVar_50838 = (cppVar_50824 >> 7) & cppMask_un_1_;
	cppVar_50840 = (cppVar_50838 == 0);
	if (cppVar_50840) {
	cppVar_50842 = PC + 1;
	cppVar_50842 = (cppVar_50842 & cppMask_un_16_);
	cppVar_50843 = ROM.rd(cppVar_50842);
	cppVar_50844 = (cppVar_50843 >> 7) & cppMask_un_1_;
	cppVar_50845 = (cppVar_50844 == 1);
	if (cppVar_50845) {
	cppVar_50846 = PC + 1;
	cppVar_50846 = (cppVar_50846 & cppMask_un_16_);
	cppVar_50847 = ROM.rd(cppVar_50846);
	cppVar_50848 = (cppVar_50847 >> 3) & cppMask_un_5_;
	cppVar_50849 = (cppVar_50848 << 3) | 0;
	cppVar_50849 = (cppVar_50849 & cppMask_un_8_);
	cppVar_50841 = cppVar_50849;
	} else {
	cppVar_50850 = PC + 1;
	cppVar_50850 = (cppVar_50850 & cppMask_un_16_);
	cppVar_50851 = ROM.rd(cppVar_50850);
	cppVar_50852 = (cppVar_50851 >> 3) & cppMask_un_5_;
	cppVar_50853 = (cppVar_50852 & cppMask_un_5_);
	cppVar_50854 = cppVar_50853 + 32;
	cppVar_50854 = (cppVar_50854 & cppMask_un_8_);
	cppVar_50841 = cppVar_50854;
	}
	cppVar_50855 = IRAM.rd(cppVar_50841);
	cppVar_50823 = cppVar_50855;
	} else {
	cppVar_50858 = PC + 1;
	cppVar_50858 = (cppVar_50858 & cppMask_un_16_);
	cppVar_50859 = ROM.rd(cppVar_50858);
	cppVar_50860 = (cppVar_50859 >> 7) & cppMask_un_1_;
	cppVar_50861 = (cppVar_50860 == 1);
	if (cppVar_50861) {
	cppVar_50862 = PC + 1;
	cppVar_50862 = (cppVar_50862 & cppMask_un_16_);
	cppVar_50863 = ROM.rd(cppVar_50862);
	cppVar_50864 = (cppVar_50863 >> 3) & cppMask_un_5_;
	cppVar_50865 = (cppVar_50864 << 3) | 0;
	cppVar_50865 = (cppVar_50865 & cppMask_un_8_);
	cppVar_50857 = cppVar_50865;
	} else {
	cppVar_50866 = PC + 1;
	cppVar_50866 = (cppVar_50866 & cppMask_un_16_);
	cppVar_50867 = ROM.rd(cppVar_50866);
	cppVar_50868 = (cppVar_50867 >> 3) & cppMask_un_5_;
	cppVar_50869 = (cppVar_50868 & cppMask_un_5_);
	cppVar_50870 = cppVar_50869 + 32;
	cppVar_50870 = (cppVar_50870 & cppMask_un_8_);
	cppVar_50857 = cppVar_50870;
	}
	cppVar_50872 = (cppVar_50857 == 128);
	if (cppVar_50872) {
	cppVar_50856 = P0;
	} else {
	cppVar_50875 = PC + 1;
	cppVar_50875 = (cppVar_50875 & cppMask_un_16_);
	cppVar_50876 = ROM.rd(cppVar_50875);
	cppVar_50877 = (cppVar_50876 >> 7) & cppMask_un_1_;
	cppVar_50878 = (cppVar_50877 == 1);
	if (cppVar_50878) {
	cppVar_50879 = PC + 1;
	cppVar_50879 = (cppVar_50879 & cppMask_un_16_);
	cppVar_50880 = ROM.rd(cppVar_50879);
	cppVar_50881 = (cppVar_50880 >> 3) & cppMask_un_5_;
	cppVar_50882 = (cppVar_50881 << 3) | 0;
	cppVar_50882 = (cppVar_50882 & cppMask_un_8_);
	cppVar_50874 = cppVar_50882;
	} else {
	cppVar_50883 = PC + 1;
	cppVar_50883 = (cppVar_50883 & cppMask_un_16_);
	cppVar_50884 = ROM.rd(cppVar_50883);
	cppVar_50885 = (cppVar_50884 >> 3) & cppMask_un_5_;
	cppVar_50886 = (cppVar_50885 & cppMask_un_5_);
	cppVar_50887 = cppVar_50886 + 32;
	cppVar_50887 = (cppVar_50887 & cppMask_un_8_);
	cppVar_50874 = cppVar_50887;
	}
	cppVar_50889 = (cppVar_50874 == 129);
	if (cppVar_50889) {
	cppVar_50873 = SP;
	} else {
	cppVar_50892 = PC + 1;
	cppVar_50892 = (cppVar_50892 & cppMask_un_16_);
	cppVar_50893 = ROM.rd(cppVar_50892);
	cppVar_50894 = (cppVar_50893 >> 7) & cppMask_un_1_;
	cppVar_50895 = (cppVar_50894 == 1);
	if (cppVar_50895) {
	cppVar_50896 = PC + 1;
	cppVar_50896 = (cppVar_50896 & cppMask_un_16_);
	cppVar_50897 = ROM.rd(cppVar_50896);
	cppVar_50898 = (cppVar_50897 >> 3) & cppMask_un_5_;
	cppVar_50899 = (cppVar_50898 << 3) | 0;
	cppVar_50899 = (cppVar_50899 & cppMask_un_8_);
	cppVar_50891 = cppVar_50899;
	} else {
	cppVar_50900 = PC + 1;
	cppVar_50900 = (cppVar_50900 & cppMask_un_16_);
	cppVar_50901 = ROM.rd(cppVar_50900);
	cppVar_50902 = (cppVar_50901 >> 3) & cppMask_un_5_;
	cppVar_50903 = (cppVar_50902 & cppMask_un_5_);
	cppVar_50904 = cppVar_50903 + 32;
	cppVar_50904 = (cppVar_50904 & cppMask_un_8_);
	cppVar_50891 = cppVar_50904;
	}
	cppVar_50906 = (cppVar_50891 == 130);
	if (cppVar_50906) {
	cppVar_50890 = DPL;
	} else {
	cppVar_50909 = PC + 1;
	cppVar_50909 = (cppVar_50909 & cppMask_un_16_);
	cppVar_50910 = ROM.rd(cppVar_50909);
	cppVar_50911 = (cppVar_50910 >> 7) & cppMask_un_1_;
	cppVar_50912 = (cppVar_50911 == 1);
	if (cppVar_50912) {
	cppVar_50913 = PC + 1;
	cppVar_50913 = (cppVar_50913 & cppMask_un_16_);
	cppVar_50914 = ROM.rd(cppVar_50913);
	cppVar_50915 = (cppVar_50914 >> 3) & cppMask_un_5_;
	cppVar_50916 = (cppVar_50915 << 3) | 0;
	cppVar_50916 = (cppVar_50916 & cppMask_un_8_);
	cppVar_50908 = cppVar_50916;
	} else {
	cppVar_50917 = PC + 1;
	cppVar_50917 = (cppVar_50917 & cppMask_un_16_);
	cppVar_50918 = ROM.rd(cppVar_50917);
	cppVar_50919 = (cppVar_50918 >> 3) & cppMask_un_5_;
	cppVar_50920 = (cppVar_50919 & cppMask_un_5_);
	cppVar_50921 = cppVar_50920 + 32;
	cppVar_50921 = (cppVar_50921 & cppMask_un_8_);
	cppVar_50908 = cppVar_50921;
	}
	cppVar_50923 = (cppVar_50908 == 131);
	if (cppVar_50923) {
	cppVar_50907 = DPH;
	} else {
	cppVar_50926 = PC + 1;
	cppVar_50926 = (cppVar_50926 & cppMask_un_16_);
	cppVar_50927 = ROM.rd(cppVar_50926);
	cppVar_50928 = (cppVar_50927 >> 7) & cppMask_un_1_;
	cppVar_50929 = (cppVar_50928 == 1);
	if (cppVar_50929) {
	cppVar_50930 = PC + 1;
	cppVar_50930 = (cppVar_50930 & cppMask_un_16_);
	cppVar_50931 = ROM.rd(cppVar_50930);
	cppVar_50932 = (cppVar_50931 >> 3) & cppMask_un_5_;
	cppVar_50933 = (cppVar_50932 << 3) | 0;
	cppVar_50933 = (cppVar_50933 & cppMask_un_8_);
	cppVar_50925 = cppVar_50933;
	} else {
	cppVar_50934 = PC + 1;
	cppVar_50934 = (cppVar_50934 & cppMask_un_16_);
	cppVar_50935 = ROM.rd(cppVar_50934);
	cppVar_50936 = (cppVar_50935 >> 3) & cppMask_un_5_;
	cppVar_50937 = (cppVar_50936 & cppMask_un_5_);
	cppVar_50938 = cppVar_50937 + 32;
	cppVar_50938 = (cppVar_50938 & cppMask_un_8_);
	cppVar_50925 = cppVar_50938;
	}
	cppVar_50940 = (cppVar_50925 == 135);
	if (cppVar_50940) {
	cppVar_50924 = PCON;
	} else {
	cppVar_50943 = PC + 1;
	cppVar_50943 = (cppVar_50943 & cppMask_un_16_);
	cppVar_50944 = ROM.rd(cppVar_50943);
	cppVar_50945 = (cppVar_50944 >> 7) & cppMask_un_1_;
	cppVar_50946 = (cppVar_50945 == 1);
	if (cppVar_50946) {
	cppVar_50947 = PC + 1;
	cppVar_50947 = (cppVar_50947 & cppMask_un_16_);
	cppVar_50948 = ROM.rd(cppVar_50947);
	cppVar_50949 = (cppVar_50948 >> 3) & cppMask_un_5_;
	cppVar_50950 = (cppVar_50949 << 3) | 0;
	cppVar_50950 = (cppVar_50950 & cppMask_un_8_);
	cppVar_50942 = cppVar_50950;
	} else {
	cppVar_50951 = PC + 1;
	cppVar_50951 = (cppVar_50951 & cppMask_un_16_);
	cppVar_50952 = ROM.rd(cppVar_50951);
	cppVar_50953 = (cppVar_50952 >> 3) & cppMask_un_5_;
	cppVar_50954 = (cppVar_50953 & cppMask_un_5_);
	cppVar_50955 = cppVar_50954 + 32;
	cppVar_50955 = (cppVar_50955 & cppMask_un_8_);
	cppVar_50942 = cppVar_50955;
	}
	cppVar_50957 = (cppVar_50942 == 136);
	if (cppVar_50957) {
	cppVar_50941 = TCON;
	} else {
	cppVar_50960 = PC + 1;
	cppVar_50960 = (cppVar_50960 & cppMask_un_16_);
	cppVar_50961 = ROM.rd(cppVar_50960);
	cppVar_50962 = (cppVar_50961 >> 7) & cppMask_un_1_;
	cppVar_50963 = (cppVar_50962 == 1);
	if (cppVar_50963) {
	cppVar_50964 = PC + 1;
	cppVar_50964 = (cppVar_50964 & cppMask_un_16_);
	cppVar_50965 = ROM.rd(cppVar_50964);
	cppVar_50966 = (cppVar_50965 >> 3) & cppMask_un_5_;
	cppVar_50967 = (cppVar_50966 << 3) | 0;
	cppVar_50967 = (cppVar_50967 & cppMask_un_8_);
	cppVar_50959 = cppVar_50967;
	} else {
	cppVar_50968 = PC + 1;
	cppVar_50968 = (cppVar_50968 & cppMask_un_16_);
	cppVar_50969 = ROM.rd(cppVar_50968);
	cppVar_50970 = (cppVar_50969 >> 3) & cppMask_un_5_;
	cppVar_50971 = (cppVar_50970 & cppMask_un_5_);
	cppVar_50972 = cppVar_50971 + 32;
	cppVar_50972 = (cppVar_50972 & cppMask_un_8_);
	cppVar_50959 = cppVar_50972;
	}
	cppVar_50974 = (cppVar_50959 == 137);
	if (cppVar_50974) {
	cppVar_50958 = TMOD;
	} else {
	cppVar_50977 = PC + 1;
	cppVar_50977 = (cppVar_50977 & cppMask_un_16_);
	cppVar_50978 = ROM.rd(cppVar_50977);
	cppVar_50979 = (cppVar_50978 >> 7) & cppMask_un_1_;
	cppVar_50980 = (cppVar_50979 == 1);
	if (cppVar_50980) {
	cppVar_50981 = PC + 1;
	cppVar_50981 = (cppVar_50981 & cppMask_un_16_);
	cppVar_50982 = ROM.rd(cppVar_50981);
	cppVar_50983 = (cppVar_50982 >> 3) & cppMask_un_5_;
	cppVar_50984 = (cppVar_50983 << 3) | 0;
	cppVar_50984 = (cppVar_50984 & cppMask_un_8_);
	cppVar_50976 = cppVar_50984;
	} else {
	cppVar_50985 = PC + 1;
	cppVar_50985 = (cppVar_50985 & cppMask_un_16_);
	cppVar_50986 = ROM.rd(cppVar_50985);
	cppVar_50987 = (cppVar_50986 >> 3) & cppMask_un_5_;
	cppVar_50988 = (cppVar_50987 & cppMask_un_5_);
	cppVar_50989 = cppVar_50988 + 32;
	cppVar_50989 = (cppVar_50989 & cppMask_un_8_);
	cppVar_50976 = cppVar_50989;
	}
	cppVar_50991 = (cppVar_50976 == 138);
	if (cppVar_50991) {
	cppVar_50975 = TL0;
	} else {
	cppVar_50994 = PC + 1;
	cppVar_50994 = (cppVar_50994 & cppMask_un_16_);
	cppVar_50995 = ROM.rd(cppVar_50994);
	cppVar_50996 = (cppVar_50995 >> 7) & cppMask_un_1_;
	cppVar_50997 = (cppVar_50996 == 1);
	if (cppVar_50997) {
	cppVar_50998 = PC + 1;
	cppVar_50998 = (cppVar_50998 & cppMask_un_16_);
	cppVar_50999 = ROM.rd(cppVar_50998);
	cppVar_51000 = (cppVar_50999 >> 3) & cppMask_un_5_;
	cppVar_51001 = (cppVar_51000 << 3) | 0;
	cppVar_51001 = (cppVar_51001 & cppMask_un_8_);
	cppVar_50993 = cppVar_51001;
	} else {
	cppVar_51002 = PC + 1;
	cppVar_51002 = (cppVar_51002 & cppMask_un_16_);
	cppVar_51003 = ROM.rd(cppVar_51002);
	cppVar_51004 = (cppVar_51003 >> 3) & cppMask_un_5_;
	cppVar_51005 = (cppVar_51004 & cppMask_un_5_);
	cppVar_51006 = cppVar_51005 + 32;
	cppVar_51006 = (cppVar_51006 & cppMask_un_8_);
	cppVar_50993 = cppVar_51006;
	}
	cppVar_51008 = (cppVar_50993 == 140);
	if (cppVar_51008) {
	cppVar_50992 = TH0;
	} else {
	cppVar_51011 = PC + 1;
	cppVar_51011 = (cppVar_51011 & cppMask_un_16_);
	cppVar_51012 = ROM.rd(cppVar_51011);
	cppVar_51013 = (cppVar_51012 >> 7) & cppMask_un_1_;
	cppVar_51014 = (cppVar_51013 == 1);
	if (cppVar_51014) {
	cppVar_51015 = PC + 1;
	cppVar_51015 = (cppVar_51015 & cppMask_un_16_);
	cppVar_51016 = ROM.rd(cppVar_51015);
	cppVar_51017 = (cppVar_51016 >> 3) & cppMask_un_5_;
	cppVar_51018 = (cppVar_51017 << 3) | 0;
	cppVar_51018 = (cppVar_51018 & cppMask_un_8_);
	cppVar_51010 = cppVar_51018;
	} else {
	cppVar_51019 = PC + 1;
	cppVar_51019 = (cppVar_51019 & cppMask_un_16_);
	cppVar_51020 = ROM.rd(cppVar_51019);
	cppVar_51021 = (cppVar_51020 >> 3) & cppMask_un_5_;
	cppVar_51022 = (cppVar_51021 & cppMask_un_5_);
	cppVar_51023 = cppVar_51022 + 32;
	cppVar_51023 = (cppVar_51023 & cppMask_un_8_);
	cppVar_51010 = cppVar_51023;
	}
	cppVar_51025 = (cppVar_51010 == 139);
	if (cppVar_51025) {
	cppVar_51009 = TL1;
	} else {
	cppVar_51028 = PC + 1;
	cppVar_51028 = (cppVar_51028 & cppMask_un_16_);
	cppVar_51029 = ROM.rd(cppVar_51028);
	cppVar_51030 = (cppVar_51029 >> 7) & cppMask_un_1_;
	cppVar_51031 = (cppVar_51030 == 1);
	if (cppVar_51031) {
	cppVar_51032 = PC + 1;
	cppVar_51032 = (cppVar_51032 & cppMask_un_16_);
	cppVar_51033 = ROM.rd(cppVar_51032);
	cppVar_51034 = (cppVar_51033 >> 3) & cppMask_un_5_;
	cppVar_51035 = (cppVar_51034 << 3) | 0;
	cppVar_51035 = (cppVar_51035 & cppMask_un_8_);
	cppVar_51027 = cppVar_51035;
	} else {
	cppVar_51036 = PC + 1;
	cppVar_51036 = (cppVar_51036 & cppMask_un_16_);
	cppVar_51037 = ROM.rd(cppVar_51036);
	cppVar_51038 = (cppVar_51037 >> 3) & cppMask_un_5_;
	cppVar_51039 = (cppVar_51038 & cppMask_un_5_);
	cppVar_51040 = cppVar_51039 + 32;
	cppVar_51040 = (cppVar_51040 & cppMask_un_8_);
	cppVar_51027 = cppVar_51040;
	}
	cppVar_51042 = (cppVar_51027 == 141);
	if (cppVar_51042) {
	cppVar_51026 = TH1;
	} else {
	cppVar_51045 = PC + 1;
	cppVar_51045 = (cppVar_51045 & cppMask_un_16_);
	cppVar_51046 = ROM.rd(cppVar_51045);
	cppVar_51047 = (cppVar_51046 >> 7) & cppMask_un_1_;
	cppVar_51048 = (cppVar_51047 == 1);
	if (cppVar_51048) {
	cppVar_51049 = PC + 1;
	cppVar_51049 = (cppVar_51049 & cppMask_un_16_);
	cppVar_51050 = ROM.rd(cppVar_51049);
	cppVar_51051 = (cppVar_51050 >> 3) & cppMask_un_5_;
	cppVar_51052 = (cppVar_51051 << 3) | 0;
	cppVar_51052 = (cppVar_51052 & cppMask_un_8_);
	cppVar_51044 = cppVar_51052;
	} else {
	cppVar_51053 = PC + 1;
	cppVar_51053 = (cppVar_51053 & cppMask_un_16_);
	cppVar_51054 = ROM.rd(cppVar_51053);
	cppVar_51055 = (cppVar_51054 >> 3) & cppMask_un_5_;
	cppVar_51056 = (cppVar_51055 & cppMask_un_5_);
	cppVar_51057 = cppVar_51056 + 32;
	cppVar_51057 = (cppVar_51057 & cppMask_un_8_);
	cppVar_51044 = cppVar_51057;
	}
	cppVar_51059 = (cppVar_51044 == 144);
	if (cppVar_51059) {
	cppVar_51043 = P1;
	} else {
	cppVar_51062 = PC + 1;
	cppVar_51062 = (cppVar_51062 & cppMask_un_16_);
	cppVar_51063 = ROM.rd(cppVar_51062);
	cppVar_51064 = (cppVar_51063 >> 7) & cppMask_un_1_;
	cppVar_51065 = (cppVar_51064 == 1);
	if (cppVar_51065) {
	cppVar_51066 = PC + 1;
	cppVar_51066 = (cppVar_51066 & cppMask_un_16_);
	cppVar_51067 = ROM.rd(cppVar_51066);
	cppVar_51068 = (cppVar_51067 >> 3) & cppMask_un_5_;
	cppVar_51069 = (cppVar_51068 << 3) | 0;
	cppVar_51069 = (cppVar_51069 & cppMask_un_8_);
	cppVar_51061 = cppVar_51069;
	} else {
	cppVar_51070 = PC + 1;
	cppVar_51070 = (cppVar_51070 & cppMask_un_16_);
	cppVar_51071 = ROM.rd(cppVar_51070);
	cppVar_51072 = (cppVar_51071 >> 3) & cppMask_un_5_;
	cppVar_51073 = (cppVar_51072 & cppMask_un_5_);
	cppVar_51074 = cppVar_51073 + 32;
	cppVar_51074 = (cppVar_51074 & cppMask_un_8_);
	cppVar_51061 = cppVar_51074;
	}
	cppVar_51076 = (cppVar_51061 == 152);
	if (cppVar_51076) {
	cppVar_51060 = SCON;
	} else {
	cppVar_51079 = PC + 1;
	cppVar_51079 = (cppVar_51079 & cppMask_un_16_);
	cppVar_51080 = ROM.rd(cppVar_51079);
	cppVar_51081 = (cppVar_51080 >> 7) & cppMask_un_1_;
	cppVar_51082 = (cppVar_51081 == 1);
	if (cppVar_51082) {
	cppVar_51083 = PC + 1;
	cppVar_51083 = (cppVar_51083 & cppMask_un_16_);
	cppVar_51084 = ROM.rd(cppVar_51083);
	cppVar_51085 = (cppVar_51084 >> 3) & cppMask_un_5_;
	cppVar_51086 = (cppVar_51085 << 3) | 0;
	cppVar_51086 = (cppVar_51086 & cppMask_un_8_);
	cppVar_51078 = cppVar_51086;
	} else {
	cppVar_51087 = PC + 1;
	cppVar_51087 = (cppVar_51087 & cppMask_un_16_);
	cppVar_51088 = ROM.rd(cppVar_51087);
	cppVar_51089 = (cppVar_51088 >> 3) & cppMask_un_5_;
	cppVar_51090 = (cppVar_51089 & cppMask_un_5_);
	cppVar_51091 = cppVar_51090 + 32;
	cppVar_51091 = (cppVar_51091 & cppMask_un_8_);
	cppVar_51078 = cppVar_51091;
	}
	cppVar_51093 = (cppVar_51078 == 153);
	if (cppVar_51093) {
	cppVar_51077 = SBUF;
	} else {
	cppVar_51096 = PC + 1;
	cppVar_51096 = (cppVar_51096 & cppMask_un_16_);
	cppVar_51097 = ROM.rd(cppVar_51096);
	cppVar_51098 = (cppVar_51097 >> 7) & cppMask_un_1_;
	cppVar_51099 = (cppVar_51098 == 1);
	if (cppVar_51099) {
	cppVar_51100 = PC + 1;
	cppVar_51100 = (cppVar_51100 & cppMask_un_16_);
	cppVar_51101 = ROM.rd(cppVar_51100);
	cppVar_51102 = (cppVar_51101 >> 3) & cppMask_un_5_;
	cppVar_51103 = (cppVar_51102 << 3) | 0;
	cppVar_51103 = (cppVar_51103 & cppMask_un_8_);
	cppVar_51095 = cppVar_51103;
	} else {
	cppVar_51104 = PC + 1;
	cppVar_51104 = (cppVar_51104 & cppMask_un_16_);
	cppVar_51105 = ROM.rd(cppVar_51104);
	cppVar_51106 = (cppVar_51105 >> 3) & cppMask_un_5_;
	cppVar_51107 = (cppVar_51106 & cppMask_un_5_);
	cppVar_51108 = cppVar_51107 + 32;
	cppVar_51108 = (cppVar_51108 & cppMask_un_8_);
	cppVar_51095 = cppVar_51108;
	}
	cppVar_51110 = (cppVar_51095 == 160);
	if (cppVar_51110) {
	cppVar_51094 = P2;
	} else {
	cppVar_51113 = PC + 1;
	cppVar_51113 = (cppVar_51113 & cppMask_un_16_);
	cppVar_51114 = ROM.rd(cppVar_51113);
	cppVar_51115 = (cppVar_51114 >> 7) & cppMask_un_1_;
	cppVar_51116 = (cppVar_51115 == 1);
	if (cppVar_51116) {
	cppVar_51117 = PC + 1;
	cppVar_51117 = (cppVar_51117 & cppMask_un_16_);
	cppVar_51118 = ROM.rd(cppVar_51117);
	cppVar_51119 = (cppVar_51118 >> 3) & cppMask_un_5_;
	cppVar_51120 = (cppVar_51119 << 3) | 0;
	cppVar_51120 = (cppVar_51120 & cppMask_un_8_);
	cppVar_51112 = cppVar_51120;
	} else {
	cppVar_51121 = PC + 1;
	cppVar_51121 = (cppVar_51121 & cppMask_un_16_);
	cppVar_51122 = ROM.rd(cppVar_51121);
	cppVar_51123 = (cppVar_51122 >> 3) & cppMask_un_5_;
	cppVar_51124 = (cppVar_51123 & cppMask_un_5_);
	cppVar_51125 = cppVar_51124 + 32;
	cppVar_51125 = (cppVar_51125 & cppMask_un_8_);
	cppVar_51112 = cppVar_51125;
	}
	cppVar_51127 = (cppVar_51112 == 168);
	if (cppVar_51127) {
	cppVar_51111 = IE;
	} else {
	cppVar_51130 = PC + 1;
	cppVar_51130 = (cppVar_51130 & cppMask_un_16_);
	cppVar_51131 = ROM.rd(cppVar_51130);
	cppVar_51132 = (cppVar_51131 >> 7) & cppMask_un_1_;
	cppVar_51133 = (cppVar_51132 == 1);
	if (cppVar_51133) {
	cppVar_51134 = PC + 1;
	cppVar_51134 = (cppVar_51134 & cppMask_un_16_);
	cppVar_51135 = ROM.rd(cppVar_51134);
	cppVar_51136 = (cppVar_51135 >> 3) & cppMask_un_5_;
	cppVar_51137 = (cppVar_51136 << 3) | 0;
	cppVar_51137 = (cppVar_51137 & cppMask_un_8_);
	cppVar_51129 = cppVar_51137;
	} else {
	cppVar_51138 = PC + 1;
	cppVar_51138 = (cppVar_51138 & cppMask_un_16_);
	cppVar_51139 = ROM.rd(cppVar_51138);
	cppVar_51140 = (cppVar_51139 >> 3) & cppMask_un_5_;
	cppVar_51141 = (cppVar_51140 & cppMask_un_5_);
	cppVar_51142 = cppVar_51141 + 32;
	cppVar_51142 = (cppVar_51142 & cppMask_un_8_);
	cppVar_51129 = cppVar_51142;
	}
	cppVar_51144 = (cppVar_51129 == 176);
	if (cppVar_51144) {
	cppVar_51128 = P3;
	} else {
	cppVar_51147 = PC + 1;
	cppVar_51147 = (cppVar_51147 & cppMask_un_16_);
	cppVar_51148 = ROM.rd(cppVar_51147);
	cppVar_51149 = (cppVar_51148 >> 7) & cppMask_un_1_;
	cppVar_51150 = (cppVar_51149 == 1);
	if (cppVar_51150) {
	cppVar_51151 = PC + 1;
	cppVar_51151 = (cppVar_51151 & cppMask_un_16_);
	cppVar_51152 = ROM.rd(cppVar_51151);
	cppVar_51153 = (cppVar_51152 >> 3) & cppMask_un_5_;
	cppVar_51154 = (cppVar_51153 << 3) | 0;
	cppVar_51154 = (cppVar_51154 & cppMask_un_8_);
	cppVar_51146 = cppVar_51154;
	} else {
	cppVar_51155 = PC + 1;
	cppVar_51155 = (cppVar_51155 & cppMask_un_16_);
	cppVar_51156 = ROM.rd(cppVar_51155);
	cppVar_51157 = (cppVar_51156 >> 3) & cppMask_un_5_;
	cppVar_51158 = (cppVar_51157 & cppMask_un_5_);
	cppVar_51159 = cppVar_51158 + 32;
	cppVar_51159 = (cppVar_51159 & cppMask_un_8_);
	cppVar_51146 = cppVar_51159;
	}
	cppVar_51161 = (cppVar_51146 == 184);
	if (cppVar_51161) {
	cppVar_51145 = IP;
	} else {
	cppVar_51164 = PC + 1;
	cppVar_51164 = (cppVar_51164 & cppMask_un_16_);
	cppVar_51165 = ROM.rd(cppVar_51164);
	cppVar_51166 = (cppVar_51165 >> 7) & cppMask_un_1_;
	cppVar_51167 = (cppVar_51166 == 1);
	if (cppVar_51167) {
	cppVar_51168 = PC + 1;
	cppVar_51168 = (cppVar_51168 & cppMask_un_16_);
	cppVar_51169 = ROM.rd(cppVar_51168);
	cppVar_51170 = (cppVar_51169 >> 3) & cppMask_un_5_;
	cppVar_51171 = (cppVar_51170 << 3) | 0;
	cppVar_51171 = (cppVar_51171 & cppMask_un_8_);
	cppVar_51163 = cppVar_51171;
	} else {
	cppVar_51172 = PC + 1;
	cppVar_51172 = (cppVar_51172 & cppMask_un_16_);
	cppVar_51173 = ROM.rd(cppVar_51172);
	cppVar_51174 = (cppVar_51173 >> 3) & cppMask_un_5_;
	cppVar_51175 = (cppVar_51174 & cppMask_un_5_);
	cppVar_51176 = cppVar_51175 + 32;
	cppVar_51176 = (cppVar_51176 & cppMask_un_8_);
	cppVar_51163 = cppVar_51176;
	}
	cppVar_51178 = (cppVar_51163 == 208);
	if (cppVar_51178) {
	cppVar_51162 = PSW;
	} else {
	cppVar_51181 = PC + 1;
	cppVar_51181 = (cppVar_51181 & cppMask_un_16_);
	cppVar_51182 = ROM.rd(cppVar_51181);
	cppVar_51183 = (cppVar_51182 >> 7) & cppMask_un_1_;
	cppVar_51184 = (cppVar_51183 == 1);
	if (cppVar_51184) {
	cppVar_51185 = PC + 1;
	cppVar_51185 = (cppVar_51185 & cppMask_un_16_);
	cppVar_51186 = ROM.rd(cppVar_51185);
	cppVar_51187 = (cppVar_51186 >> 3) & cppMask_un_5_;
	cppVar_51188 = (cppVar_51187 << 3) | 0;
	cppVar_51188 = (cppVar_51188 & cppMask_un_8_);
	cppVar_51180 = cppVar_51188;
	} else {
	cppVar_51189 = PC + 1;
	cppVar_51189 = (cppVar_51189 & cppMask_un_16_);
	cppVar_51190 = ROM.rd(cppVar_51189);
	cppVar_51191 = (cppVar_51190 >> 3) & cppMask_un_5_;
	cppVar_51192 = (cppVar_51191 & cppMask_un_5_);
	cppVar_51193 = cppVar_51192 + 32;
	cppVar_51193 = (cppVar_51193 & cppMask_un_8_);
	cppVar_51180 = cppVar_51193;
	}
	cppVar_51195 = (cppVar_51180 == 224);
	if (cppVar_51195) {
	cppVar_51179 = ACC;
	} else {
	cppVar_51198 = PC + 1;
	cppVar_51198 = (cppVar_51198 & cppMask_un_16_);
	cppVar_51199 = ROM.rd(cppVar_51198);
	cppVar_51200 = (cppVar_51199 >> 7) & cppMask_un_1_;
	cppVar_51201 = (cppVar_51200 == 1);
	if (cppVar_51201) {
	cppVar_51202 = PC + 1;
	cppVar_51202 = (cppVar_51202 & cppMask_un_16_);
	cppVar_51203 = ROM.rd(cppVar_51202);
	cppVar_51204 = (cppVar_51203 >> 3) & cppMask_un_5_;
	cppVar_51205 = (cppVar_51204 << 3) | 0;
	cppVar_51205 = (cppVar_51205 & cppMask_un_8_);
	cppVar_51197 = cppVar_51205;
	} else {
	cppVar_51206 = PC + 1;
	cppVar_51206 = (cppVar_51206 & cppMask_un_16_);
	cppVar_51207 = ROM.rd(cppVar_51206);
	cppVar_51208 = (cppVar_51207 >> 3) & cppMask_un_5_;
	cppVar_51209 = (cppVar_51208 & cppMask_un_5_);
	cppVar_51210 = cppVar_51209 + 32;
	cppVar_51210 = (cppVar_51210 & cppMask_un_8_);
	cppVar_51197 = cppVar_51210;
	}
	cppVar_51212 = (cppVar_51197 == 240);
	if (cppVar_51212) {
	cppVar_51196 = B;
	} else {
	cppVar_51196 = 0;
	}
	cppVar_51179 = cppVar_51196;
	}
	cppVar_51162 = cppVar_51179;
	}
	cppVar_51145 = cppVar_51162;
	}
	cppVar_51128 = cppVar_51145;
	}
	cppVar_51111 = cppVar_51128;
	}
	cppVar_51094 = cppVar_51111;
	}
	cppVar_51077 = cppVar_51094;
	}
	cppVar_51060 = cppVar_51077;
	}
	cppVar_51043 = cppVar_51060;
	}
	cppVar_51026 = cppVar_51043;
	}
	cppVar_51009 = cppVar_51026;
	}
	cppVar_50992 = cppVar_51009;
	}
	cppVar_50975 = cppVar_50992;
	}
	cppVar_50958 = cppVar_50975;
	}
	cppVar_50941 = cppVar_50958;
	}
	cppVar_50924 = cppVar_50941;
	}
	cppVar_50907 = cppVar_50924;
	}
	cppVar_50890 = cppVar_50907;
	}
	cppVar_50873 = cppVar_50890;
	}
	cppVar_50856 = cppVar_50873;
	}
	cppVar_50823 = cppVar_50856;
	}
	cppVar_51214 = cppVar_50822 & cppVar_50823;
	cppVar_51215 = (PSW >> 7) & cppMask_un_1_;
	cppVar_51216 = (cppVar_51215 & cppMask_un_1_);
	cppVar_51217 = PC + 1;
	cppVar_51217 = (cppVar_51217 & cppMask_un_16_);
	cppVar_51218 = ROM.rd(cppVar_51217);
	cppVar_51219 = (cppVar_51218 >> 0) & cppMask_un_3_;
	cppVar_51220 = (cppVar_51219 & cppMask_un_3_);
	cppVar_51221 = cppVar_51216 << static_cast<unsigned>(cppVar_51220);
	cppVar_51221 = (cppVar_51221 & cppMask_un_8_);
	cppVar_51222 = cppVar_51214 | cppVar_51221;
	cppVar_50795 = cppVar_51222;
	} else {
	cppVar_50795 = PSW;
	}
	cppVar_50791 = cppVar_50795;
	} else {
	cppVar_51224 = ROM.rd(PC);
	cppVar_51226 = (cppVar_51224 == 143);
	if (cppVar_51226) {
	cppVar_51229 = PC + 1;
	cppVar_51229 = (cppVar_51229 & cppMask_un_16_);
	cppVar_51230 = ROM.rd(cppVar_51229);
	cppVar_51232 = (cppVar_51230 == 208);
	if (cppVar_51232) {
	cppVar_51235 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51237 = (cppVar_51235 << 3) | 7;
	cppVar_51237 = (cppVar_51237 & cppMask_un_5_);
	cppVar_51238 = (0 << 5) | cppVar_51237;
	cppVar_51238 = (cppVar_51238 & cppMask_un_8_);
	cppVar_51239 = (cppVar_51238 >> 7) & cppMask_un_1_;
	cppVar_51241 = (cppVar_51239 == 0);
	if (cppVar_51241) {
	cppVar_51242 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51243 = (cppVar_51242 << 3) | 7;
	cppVar_51243 = (cppVar_51243 & cppMask_un_5_);
	cppVar_51244 = (0 << 5) | cppVar_51243;
	cppVar_51244 = (cppVar_51244 & cppMask_un_8_);
	cppVar_51245 = IRAM.rd(cppVar_51244);
	cppVar_51233 = cppVar_51245;
	} else {
	cppVar_51247 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51248 = (cppVar_51247 << 3) | 7;
	cppVar_51248 = (cppVar_51248 & cppMask_un_5_);
	cppVar_51249 = (0 << 5) | cppVar_51248;
	cppVar_51249 = (cppVar_51249 & cppMask_un_8_);
	cppVar_51251 = (cppVar_51249 == 128);
	if (cppVar_51251) {
	cppVar_51246 = P0;
	} else {
	cppVar_51253 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51254 = (cppVar_51253 << 3) | 7;
	cppVar_51254 = (cppVar_51254 & cppMask_un_5_);
	cppVar_51255 = (0 << 5) | cppVar_51254;
	cppVar_51255 = (cppVar_51255 & cppMask_un_8_);
	cppVar_51257 = (cppVar_51255 == 129);
	if (cppVar_51257) {
	cppVar_51252 = SP;
	} else {
	cppVar_51259 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51260 = (cppVar_51259 << 3) | 7;
	cppVar_51260 = (cppVar_51260 & cppMask_un_5_);
	cppVar_51261 = (0 << 5) | cppVar_51260;
	cppVar_51261 = (cppVar_51261 & cppMask_un_8_);
	cppVar_51263 = (cppVar_51261 == 130);
	if (cppVar_51263) {
	cppVar_51258 = DPL;
	} else {
	cppVar_51265 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51266 = (cppVar_51265 << 3) | 7;
	cppVar_51266 = (cppVar_51266 & cppMask_un_5_);
	cppVar_51267 = (0 << 5) | cppVar_51266;
	cppVar_51267 = (cppVar_51267 & cppMask_un_8_);
	cppVar_51269 = (cppVar_51267 == 131);
	if (cppVar_51269) {
	cppVar_51264 = DPH;
	} else {
	cppVar_51271 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51272 = (cppVar_51271 << 3) | 7;
	cppVar_51272 = (cppVar_51272 & cppMask_un_5_);
	cppVar_51273 = (0 << 5) | cppVar_51272;
	cppVar_51273 = (cppVar_51273 & cppMask_un_8_);
	cppVar_51275 = (cppVar_51273 == 135);
	if (cppVar_51275) {
	cppVar_51270 = PCON;
	} else {
	cppVar_51277 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51278 = (cppVar_51277 << 3) | 7;
	cppVar_51278 = (cppVar_51278 & cppMask_un_5_);
	cppVar_51279 = (0 << 5) | cppVar_51278;
	cppVar_51279 = (cppVar_51279 & cppMask_un_8_);
	cppVar_51281 = (cppVar_51279 == 136);
	if (cppVar_51281) {
	cppVar_51276 = TCON;
	} else {
	cppVar_51283 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51284 = (cppVar_51283 << 3) | 7;
	cppVar_51284 = (cppVar_51284 & cppMask_un_5_);
	cppVar_51285 = (0 << 5) | cppVar_51284;
	cppVar_51285 = (cppVar_51285 & cppMask_un_8_);
	cppVar_51287 = (cppVar_51285 == 137);
	if (cppVar_51287) {
	cppVar_51282 = TMOD;
	} else {
	cppVar_51289 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51290 = (cppVar_51289 << 3) | 7;
	cppVar_51290 = (cppVar_51290 & cppMask_un_5_);
	cppVar_51291 = (0 << 5) | cppVar_51290;
	cppVar_51291 = (cppVar_51291 & cppMask_un_8_);
	cppVar_51293 = (cppVar_51291 == 138);
	if (cppVar_51293) {
	cppVar_51288 = TL0;
	} else {
	cppVar_51295 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51296 = (cppVar_51295 << 3) | 7;
	cppVar_51296 = (cppVar_51296 & cppMask_un_5_);
	cppVar_51297 = (0 << 5) | cppVar_51296;
	cppVar_51297 = (cppVar_51297 & cppMask_un_8_);
	cppVar_51299 = (cppVar_51297 == 140);
	if (cppVar_51299) {
	cppVar_51294 = TH0;
	} else {
	cppVar_51301 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51302 = (cppVar_51301 << 3) | 7;
	cppVar_51302 = (cppVar_51302 & cppMask_un_5_);
	cppVar_51303 = (0 << 5) | cppVar_51302;
	cppVar_51303 = (cppVar_51303 & cppMask_un_8_);
	cppVar_51305 = (cppVar_51303 == 139);
	if (cppVar_51305) {
	cppVar_51300 = TL1;
	} else {
	cppVar_51307 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51308 = (cppVar_51307 << 3) | 7;
	cppVar_51308 = (cppVar_51308 & cppMask_un_5_);
	cppVar_51309 = (0 << 5) | cppVar_51308;
	cppVar_51309 = (cppVar_51309 & cppMask_un_8_);
	cppVar_51311 = (cppVar_51309 == 141);
	if (cppVar_51311) {
	cppVar_51306 = TH1;
	} else {
	cppVar_51313 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51314 = (cppVar_51313 << 3) | 7;
	cppVar_51314 = (cppVar_51314 & cppMask_un_5_);
	cppVar_51315 = (0 << 5) | cppVar_51314;
	cppVar_51315 = (cppVar_51315 & cppMask_un_8_);
	cppVar_51317 = (cppVar_51315 == 144);
	if (cppVar_51317) {
	cppVar_51312 = P1;
	} else {
	cppVar_51319 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51320 = (cppVar_51319 << 3) | 7;
	cppVar_51320 = (cppVar_51320 & cppMask_un_5_);
	cppVar_51321 = (0 << 5) | cppVar_51320;
	cppVar_51321 = (cppVar_51321 & cppMask_un_8_);
	cppVar_51323 = (cppVar_51321 == 152);
	if (cppVar_51323) {
	cppVar_51318 = SCON;
	} else {
	cppVar_51325 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51326 = (cppVar_51325 << 3) | 7;
	cppVar_51326 = (cppVar_51326 & cppMask_un_5_);
	cppVar_51327 = (0 << 5) | cppVar_51326;
	cppVar_51327 = (cppVar_51327 & cppMask_un_8_);
	cppVar_51329 = (cppVar_51327 == 153);
	if (cppVar_51329) {
	cppVar_51324 = SBUF;
	} else {
	cppVar_51331 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51332 = (cppVar_51331 << 3) | 7;
	cppVar_51332 = (cppVar_51332 & cppMask_un_5_);
	cppVar_51333 = (0 << 5) | cppVar_51332;
	cppVar_51333 = (cppVar_51333 & cppMask_un_8_);
	cppVar_51335 = (cppVar_51333 == 160);
	if (cppVar_51335) {
	cppVar_51330 = P2;
	} else {
	cppVar_51337 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51338 = (cppVar_51337 << 3) | 7;
	cppVar_51338 = (cppVar_51338 & cppMask_un_5_);
	cppVar_51339 = (0 << 5) | cppVar_51338;
	cppVar_51339 = (cppVar_51339 & cppMask_un_8_);
	cppVar_51341 = (cppVar_51339 == 168);
	if (cppVar_51341) {
	cppVar_51336 = IE;
	} else {
	cppVar_51343 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51344 = (cppVar_51343 << 3) | 7;
	cppVar_51344 = (cppVar_51344 & cppMask_un_5_);
	cppVar_51345 = (0 << 5) | cppVar_51344;
	cppVar_51345 = (cppVar_51345 & cppMask_un_8_);
	cppVar_51347 = (cppVar_51345 == 176);
	if (cppVar_51347) {
	cppVar_51342 = P3;
	} else {
	cppVar_51349 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51350 = (cppVar_51349 << 3) | 7;
	cppVar_51350 = (cppVar_51350 & cppMask_un_5_);
	cppVar_51351 = (0 << 5) | cppVar_51350;
	cppVar_51351 = (cppVar_51351 & cppMask_un_8_);
	cppVar_51353 = (cppVar_51351 == 184);
	if (cppVar_51353) {
	cppVar_51348 = IP;
	} else {
	cppVar_51355 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51356 = (cppVar_51355 << 3) | 7;
	cppVar_51356 = (cppVar_51356 & cppMask_un_5_);
	cppVar_51357 = (0 << 5) | cppVar_51356;
	cppVar_51357 = (cppVar_51357 & cppMask_un_8_);
	cppVar_51359 = (cppVar_51357 == 208);
	if (cppVar_51359) {
	cppVar_51354 = PSW;
	} else {
	cppVar_51361 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51362 = (cppVar_51361 << 3) | 7;
	cppVar_51362 = (cppVar_51362 & cppMask_un_5_);
	cppVar_51363 = (0 << 5) | cppVar_51362;
	cppVar_51363 = (cppVar_51363 & cppMask_un_8_);
	cppVar_51365 = (cppVar_51363 == 224);
	if (cppVar_51365) {
	cppVar_51360 = ACC;
	} else {
	cppVar_51367 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51368 = (cppVar_51367 << 3) | 7;
	cppVar_51368 = (cppVar_51368 & cppMask_un_5_);
	cppVar_51369 = (0 << 5) | cppVar_51368;
	cppVar_51369 = (cppVar_51369 & cppMask_un_8_);
	cppVar_51371 = (cppVar_51369 == 240);
	if (cppVar_51371) {
	cppVar_51366 = B;
	} else {
	cppVar_51366 = 0;
	}
	cppVar_51360 = cppVar_51366;
	}
	cppVar_51354 = cppVar_51360;
	}
	cppVar_51348 = cppVar_51354;
	}
	cppVar_51342 = cppVar_51348;
	}
	cppVar_51336 = cppVar_51342;
	}
	cppVar_51330 = cppVar_51336;
	}
	cppVar_51324 = cppVar_51330;
	}
	cppVar_51318 = cppVar_51324;
	}
	cppVar_51312 = cppVar_51318;
	}
	cppVar_51306 = cppVar_51312;
	}
	cppVar_51300 = cppVar_51306;
	}
	cppVar_51294 = cppVar_51300;
	}
	cppVar_51288 = cppVar_51294;
	}
	cppVar_51282 = cppVar_51288;
	}
	cppVar_51276 = cppVar_51282;
	}
	cppVar_51270 = cppVar_51276;
	}
	cppVar_51264 = cppVar_51270;
	}
	cppVar_51258 = cppVar_51264;
	}
	cppVar_51252 = cppVar_51258;
	}
	cppVar_51246 = cppVar_51252;
	}
	cppVar_51233 = cppVar_51246;
	}
	cppVar_51227 = cppVar_51233;
	} else {
	cppVar_51227 = PSW;
	}
	cppVar_51223 = cppVar_51227;
	} else {
	cppVar_51374 = ROM.rd(PC);
	cppVar_51376 = (cppVar_51374 == 142);
	if (cppVar_51376) {
	cppVar_51379 = PC + 1;
	cppVar_51379 = (cppVar_51379 & cppMask_un_16_);
	cppVar_51380 = ROM.rd(cppVar_51379);
	cppVar_51382 = (cppVar_51380 == 208);
	if (cppVar_51382) {
	cppVar_51385 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51387 = (cppVar_51385 << 3) | 6;
	cppVar_51387 = (cppVar_51387 & cppMask_un_5_);
	cppVar_51388 = (0 << 5) | cppVar_51387;
	cppVar_51388 = (cppVar_51388 & cppMask_un_8_);
	cppVar_51389 = (cppVar_51388 >> 7) & cppMask_un_1_;
	cppVar_51391 = (cppVar_51389 == 0);
	if (cppVar_51391) {
	cppVar_51392 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51393 = (cppVar_51392 << 3) | 6;
	cppVar_51393 = (cppVar_51393 & cppMask_un_5_);
	cppVar_51394 = (0 << 5) | cppVar_51393;
	cppVar_51394 = (cppVar_51394 & cppMask_un_8_);
	cppVar_51395 = IRAM.rd(cppVar_51394);
	cppVar_51383 = cppVar_51395;
	} else {
	cppVar_51397 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51398 = (cppVar_51397 << 3) | 6;
	cppVar_51398 = (cppVar_51398 & cppMask_un_5_);
	cppVar_51399 = (0 << 5) | cppVar_51398;
	cppVar_51399 = (cppVar_51399 & cppMask_un_8_);
	cppVar_51401 = (cppVar_51399 == 128);
	if (cppVar_51401) {
	cppVar_51396 = P0;
	} else {
	cppVar_51403 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51404 = (cppVar_51403 << 3) | 6;
	cppVar_51404 = (cppVar_51404 & cppMask_un_5_);
	cppVar_51405 = (0 << 5) | cppVar_51404;
	cppVar_51405 = (cppVar_51405 & cppMask_un_8_);
	cppVar_51407 = (cppVar_51405 == 129);
	if (cppVar_51407) {
	cppVar_51402 = SP;
	} else {
	cppVar_51409 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51410 = (cppVar_51409 << 3) | 6;
	cppVar_51410 = (cppVar_51410 & cppMask_un_5_);
	cppVar_51411 = (0 << 5) | cppVar_51410;
	cppVar_51411 = (cppVar_51411 & cppMask_un_8_);
	cppVar_51413 = (cppVar_51411 == 130);
	if (cppVar_51413) {
	cppVar_51408 = DPL;
	} else {
	cppVar_51415 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51416 = (cppVar_51415 << 3) | 6;
	cppVar_51416 = (cppVar_51416 & cppMask_un_5_);
	cppVar_51417 = (0 << 5) | cppVar_51416;
	cppVar_51417 = (cppVar_51417 & cppMask_un_8_);
	cppVar_51419 = (cppVar_51417 == 131);
	if (cppVar_51419) {
	cppVar_51414 = DPH;
	} else {
	cppVar_51421 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51422 = (cppVar_51421 << 3) | 6;
	cppVar_51422 = (cppVar_51422 & cppMask_un_5_);
	cppVar_51423 = (0 << 5) | cppVar_51422;
	cppVar_51423 = (cppVar_51423 & cppMask_un_8_);
	cppVar_51425 = (cppVar_51423 == 135);
	if (cppVar_51425) {
	cppVar_51420 = PCON;
	} else {
	cppVar_51427 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51428 = (cppVar_51427 << 3) | 6;
	cppVar_51428 = (cppVar_51428 & cppMask_un_5_);
	cppVar_51429 = (0 << 5) | cppVar_51428;
	cppVar_51429 = (cppVar_51429 & cppMask_un_8_);
	cppVar_51431 = (cppVar_51429 == 136);
	if (cppVar_51431) {
	cppVar_51426 = TCON;
	} else {
	cppVar_51433 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51434 = (cppVar_51433 << 3) | 6;
	cppVar_51434 = (cppVar_51434 & cppMask_un_5_);
	cppVar_51435 = (0 << 5) | cppVar_51434;
	cppVar_51435 = (cppVar_51435 & cppMask_un_8_);
	cppVar_51437 = (cppVar_51435 == 137);
	if (cppVar_51437) {
	cppVar_51432 = TMOD;
	} else {
	cppVar_51439 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51440 = (cppVar_51439 << 3) | 6;
	cppVar_51440 = (cppVar_51440 & cppMask_un_5_);
	cppVar_51441 = (0 << 5) | cppVar_51440;
	cppVar_51441 = (cppVar_51441 & cppMask_un_8_);
	cppVar_51443 = (cppVar_51441 == 138);
	if (cppVar_51443) {
	cppVar_51438 = TL0;
	} else {
	cppVar_51445 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51446 = (cppVar_51445 << 3) | 6;
	cppVar_51446 = (cppVar_51446 & cppMask_un_5_);
	cppVar_51447 = (0 << 5) | cppVar_51446;
	cppVar_51447 = (cppVar_51447 & cppMask_un_8_);
	cppVar_51449 = (cppVar_51447 == 140);
	if (cppVar_51449) {
	cppVar_51444 = TH0;
	} else {
	cppVar_51451 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51452 = (cppVar_51451 << 3) | 6;
	cppVar_51452 = (cppVar_51452 & cppMask_un_5_);
	cppVar_51453 = (0 << 5) | cppVar_51452;
	cppVar_51453 = (cppVar_51453 & cppMask_un_8_);
	cppVar_51455 = (cppVar_51453 == 139);
	if (cppVar_51455) {
	cppVar_51450 = TL1;
	} else {
	cppVar_51457 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51458 = (cppVar_51457 << 3) | 6;
	cppVar_51458 = (cppVar_51458 & cppMask_un_5_);
	cppVar_51459 = (0 << 5) | cppVar_51458;
	cppVar_51459 = (cppVar_51459 & cppMask_un_8_);
	cppVar_51461 = (cppVar_51459 == 141);
	if (cppVar_51461) {
	cppVar_51456 = TH1;
	} else {
	cppVar_51463 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51464 = (cppVar_51463 << 3) | 6;
	cppVar_51464 = (cppVar_51464 & cppMask_un_5_);
	cppVar_51465 = (0 << 5) | cppVar_51464;
	cppVar_51465 = (cppVar_51465 & cppMask_un_8_);
	cppVar_51467 = (cppVar_51465 == 144);
	if (cppVar_51467) {
	cppVar_51462 = P1;
	} else {
	cppVar_51469 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51470 = (cppVar_51469 << 3) | 6;
	cppVar_51470 = (cppVar_51470 & cppMask_un_5_);
	cppVar_51471 = (0 << 5) | cppVar_51470;
	cppVar_51471 = (cppVar_51471 & cppMask_un_8_);
	cppVar_51473 = (cppVar_51471 == 152);
	if (cppVar_51473) {
	cppVar_51468 = SCON;
	} else {
	cppVar_51475 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51476 = (cppVar_51475 << 3) | 6;
	cppVar_51476 = (cppVar_51476 & cppMask_un_5_);
	cppVar_51477 = (0 << 5) | cppVar_51476;
	cppVar_51477 = (cppVar_51477 & cppMask_un_8_);
	cppVar_51479 = (cppVar_51477 == 153);
	if (cppVar_51479) {
	cppVar_51474 = SBUF;
	} else {
	cppVar_51481 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51482 = (cppVar_51481 << 3) | 6;
	cppVar_51482 = (cppVar_51482 & cppMask_un_5_);
	cppVar_51483 = (0 << 5) | cppVar_51482;
	cppVar_51483 = (cppVar_51483 & cppMask_un_8_);
	cppVar_51485 = (cppVar_51483 == 160);
	if (cppVar_51485) {
	cppVar_51480 = P2;
	} else {
	cppVar_51487 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51488 = (cppVar_51487 << 3) | 6;
	cppVar_51488 = (cppVar_51488 & cppMask_un_5_);
	cppVar_51489 = (0 << 5) | cppVar_51488;
	cppVar_51489 = (cppVar_51489 & cppMask_un_8_);
	cppVar_51491 = (cppVar_51489 == 168);
	if (cppVar_51491) {
	cppVar_51486 = IE;
	} else {
	cppVar_51493 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51494 = (cppVar_51493 << 3) | 6;
	cppVar_51494 = (cppVar_51494 & cppMask_un_5_);
	cppVar_51495 = (0 << 5) | cppVar_51494;
	cppVar_51495 = (cppVar_51495 & cppMask_un_8_);
	cppVar_51497 = (cppVar_51495 == 176);
	if (cppVar_51497) {
	cppVar_51492 = P3;
	} else {
	cppVar_51499 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51500 = (cppVar_51499 << 3) | 6;
	cppVar_51500 = (cppVar_51500 & cppMask_un_5_);
	cppVar_51501 = (0 << 5) | cppVar_51500;
	cppVar_51501 = (cppVar_51501 & cppMask_un_8_);
	cppVar_51503 = (cppVar_51501 == 184);
	if (cppVar_51503) {
	cppVar_51498 = IP;
	} else {
	cppVar_51505 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51506 = (cppVar_51505 << 3) | 6;
	cppVar_51506 = (cppVar_51506 & cppMask_un_5_);
	cppVar_51507 = (0 << 5) | cppVar_51506;
	cppVar_51507 = (cppVar_51507 & cppMask_un_8_);
	cppVar_51509 = (cppVar_51507 == 208);
	if (cppVar_51509) {
	cppVar_51504 = PSW;
	} else {
	cppVar_51511 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51512 = (cppVar_51511 << 3) | 6;
	cppVar_51512 = (cppVar_51512 & cppMask_un_5_);
	cppVar_51513 = (0 << 5) | cppVar_51512;
	cppVar_51513 = (cppVar_51513 & cppMask_un_8_);
	cppVar_51515 = (cppVar_51513 == 224);
	if (cppVar_51515) {
	cppVar_51510 = ACC;
	} else {
	cppVar_51517 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51518 = (cppVar_51517 << 3) | 6;
	cppVar_51518 = (cppVar_51518 & cppMask_un_5_);
	cppVar_51519 = (0 << 5) | cppVar_51518;
	cppVar_51519 = (cppVar_51519 & cppMask_un_8_);
	cppVar_51521 = (cppVar_51519 == 240);
	if (cppVar_51521) {
	cppVar_51516 = B;
	} else {
	cppVar_51516 = 0;
	}
	cppVar_51510 = cppVar_51516;
	}
	cppVar_51504 = cppVar_51510;
	}
	cppVar_51498 = cppVar_51504;
	}
	cppVar_51492 = cppVar_51498;
	}
	cppVar_51486 = cppVar_51492;
	}
	cppVar_51480 = cppVar_51486;
	}
	cppVar_51474 = cppVar_51480;
	}
	cppVar_51468 = cppVar_51474;
	}
	cppVar_51462 = cppVar_51468;
	}
	cppVar_51456 = cppVar_51462;
	}
	cppVar_51450 = cppVar_51456;
	}
	cppVar_51444 = cppVar_51450;
	}
	cppVar_51438 = cppVar_51444;
	}
	cppVar_51432 = cppVar_51438;
	}
	cppVar_51426 = cppVar_51432;
	}
	cppVar_51420 = cppVar_51426;
	}
	cppVar_51414 = cppVar_51420;
	}
	cppVar_51408 = cppVar_51414;
	}
	cppVar_51402 = cppVar_51408;
	}
	cppVar_51396 = cppVar_51402;
	}
	cppVar_51383 = cppVar_51396;
	}
	cppVar_51377 = cppVar_51383;
	} else {
	cppVar_51377 = PSW;
	}
	cppVar_51373 = cppVar_51377;
	} else {
	cppVar_51524 = ROM.rd(PC);
	cppVar_51526 = (cppVar_51524 == 141);
	if (cppVar_51526) {
	cppVar_51529 = PC + 1;
	cppVar_51529 = (cppVar_51529 & cppMask_un_16_);
	cppVar_51530 = ROM.rd(cppVar_51529);
	cppVar_51532 = (cppVar_51530 == 208);
	if (cppVar_51532) {
	cppVar_51535 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51537 = (cppVar_51535 << 3) | 5;
	cppVar_51537 = (cppVar_51537 & cppMask_un_5_);
	cppVar_51538 = (0 << 5) | cppVar_51537;
	cppVar_51538 = (cppVar_51538 & cppMask_un_8_);
	cppVar_51539 = (cppVar_51538 >> 7) & cppMask_un_1_;
	cppVar_51541 = (cppVar_51539 == 0);
	if (cppVar_51541) {
	cppVar_51542 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51543 = (cppVar_51542 << 3) | 5;
	cppVar_51543 = (cppVar_51543 & cppMask_un_5_);
	cppVar_51544 = (0 << 5) | cppVar_51543;
	cppVar_51544 = (cppVar_51544 & cppMask_un_8_);
	cppVar_51545 = IRAM.rd(cppVar_51544);
	cppVar_51533 = cppVar_51545;
	} else {
	cppVar_51547 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51548 = (cppVar_51547 << 3) | 5;
	cppVar_51548 = (cppVar_51548 & cppMask_un_5_);
	cppVar_51549 = (0 << 5) | cppVar_51548;
	cppVar_51549 = (cppVar_51549 & cppMask_un_8_);
	cppVar_51551 = (cppVar_51549 == 128);
	if (cppVar_51551) {
	cppVar_51546 = P0;
	} else {
	cppVar_51553 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51554 = (cppVar_51553 << 3) | 5;
	cppVar_51554 = (cppVar_51554 & cppMask_un_5_);
	cppVar_51555 = (0 << 5) | cppVar_51554;
	cppVar_51555 = (cppVar_51555 & cppMask_un_8_);
	cppVar_51557 = (cppVar_51555 == 129);
	if (cppVar_51557) {
	cppVar_51552 = SP;
	} else {
	cppVar_51559 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51560 = (cppVar_51559 << 3) | 5;
	cppVar_51560 = (cppVar_51560 & cppMask_un_5_);
	cppVar_51561 = (0 << 5) | cppVar_51560;
	cppVar_51561 = (cppVar_51561 & cppMask_un_8_);
	cppVar_51563 = (cppVar_51561 == 130);
	if (cppVar_51563) {
	cppVar_51558 = DPL;
	} else {
	cppVar_51565 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51566 = (cppVar_51565 << 3) | 5;
	cppVar_51566 = (cppVar_51566 & cppMask_un_5_);
	cppVar_51567 = (0 << 5) | cppVar_51566;
	cppVar_51567 = (cppVar_51567 & cppMask_un_8_);
	cppVar_51569 = (cppVar_51567 == 131);
	if (cppVar_51569) {
	cppVar_51564 = DPH;
	} else {
	cppVar_51571 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51572 = (cppVar_51571 << 3) | 5;
	cppVar_51572 = (cppVar_51572 & cppMask_un_5_);
	cppVar_51573 = (0 << 5) | cppVar_51572;
	cppVar_51573 = (cppVar_51573 & cppMask_un_8_);
	cppVar_51575 = (cppVar_51573 == 135);
	if (cppVar_51575) {
	cppVar_51570 = PCON;
	} else {
	cppVar_51577 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51578 = (cppVar_51577 << 3) | 5;
	cppVar_51578 = (cppVar_51578 & cppMask_un_5_);
	cppVar_51579 = (0 << 5) | cppVar_51578;
	cppVar_51579 = (cppVar_51579 & cppMask_un_8_);
	cppVar_51581 = (cppVar_51579 == 136);
	if (cppVar_51581) {
	cppVar_51576 = TCON;
	} else {
	cppVar_51583 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51584 = (cppVar_51583 << 3) | 5;
	cppVar_51584 = (cppVar_51584 & cppMask_un_5_);
	cppVar_51585 = (0 << 5) | cppVar_51584;
	cppVar_51585 = (cppVar_51585 & cppMask_un_8_);
	cppVar_51587 = (cppVar_51585 == 137);
	if (cppVar_51587) {
	cppVar_51582 = TMOD;
	} else {
	cppVar_51589 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51590 = (cppVar_51589 << 3) | 5;
	cppVar_51590 = (cppVar_51590 & cppMask_un_5_);
	cppVar_51591 = (0 << 5) | cppVar_51590;
	cppVar_51591 = (cppVar_51591 & cppMask_un_8_);
	cppVar_51593 = (cppVar_51591 == 138);
	if (cppVar_51593) {
	cppVar_51588 = TL0;
	} else {
	cppVar_51595 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51596 = (cppVar_51595 << 3) | 5;
	cppVar_51596 = (cppVar_51596 & cppMask_un_5_);
	cppVar_51597 = (0 << 5) | cppVar_51596;
	cppVar_51597 = (cppVar_51597 & cppMask_un_8_);
	cppVar_51599 = (cppVar_51597 == 140);
	if (cppVar_51599) {
	cppVar_51594 = TH0;
	} else {
	cppVar_51601 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51602 = (cppVar_51601 << 3) | 5;
	cppVar_51602 = (cppVar_51602 & cppMask_un_5_);
	cppVar_51603 = (0 << 5) | cppVar_51602;
	cppVar_51603 = (cppVar_51603 & cppMask_un_8_);
	cppVar_51605 = (cppVar_51603 == 139);
	if (cppVar_51605) {
	cppVar_51600 = TL1;
	} else {
	cppVar_51607 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51608 = (cppVar_51607 << 3) | 5;
	cppVar_51608 = (cppVar_51608 & cppMask_un_5_);
	cppVar_51609 = (0 << 5) | cppVar_51608;
	cppVar_51609 = (cppVar_51609 & cppMask_un_8_);
	cppVar_51611 = (cppVar_51609 == 141);
	if (cppVar_51611) {
	cppVar_51606 = TH1;
	} else {
	cppVar_51613 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51614 = (cppVar_51613 << 3) | 5;
	cppVar_51614 = (cppVar_51614 & cppMask_un_5_);
	cppVar_51615 = (0 << 5) | cppVar_51614;
	cppVar_51615 = (cppVar_51615 & cppMask_un_8_);
	cppVar_51617 = (cppVar_51615 == 144);
	if (cppVar_51617) {
	cppVar_51612 = P1;
	} else {
	cppVar_51619 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51620 = (cppVar_51619 << 3) | 5;
	cppVar_51620 = (cppVar_51620 & cppMask_un_5_);
	cppVar_51621 = (0 << 5) | cppVar_51620;
	cppVar_51621 = (cppVar_51621 & cppMask_un_8_);
	cppVar_51623 = (cppVar_51621 == 152);
	if (cppVar_51623) {
	cppVar_51618 = SCON;
	} else {
	cppVar_51625 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51626 = (cppVar_51625 << 3) | 5;
	cppVar_51626 = (cppVar_51626 & cppMask_un_5_);
	cppVar_51627 = (0 << 5) | cppVar_51626;
	cppVar_51627 = (cppVar_51627 & cppMask_un_8_);
	cppVar_51629 = (cppVar_51627 == 153);
	if (cppVar_51629) {
	cppVar_51624 = SBUF;
	} else {
	cppVar_51631 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51632 = (cppVar_51631 << 3) | 5;
	cppVar_51632 = (cppVar_51632 & cppMask_un_5_);
	cppVar_51633 = (0 << 5) | cppVar_51632;
	cppVar_51633 = (cppVar_51633 & cppMask_un_8_);
	cppVar_51635 = (cppVar_51633 == 160);
	if (cppVar_51635) {
	cppVar_51630 = P2;
	} else {
	cppVar_51637 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51638 = (cppVar_51637 << 3) | 5;
	cppVar_51638 = (cppVar_51638 & cppMask_un_5_);
	cppVar_51639 = (0 << 5) | cppVar_51638;
	cppVar_51639 = (cppVar_51639 & cppMask_un_8_);
	cppVar_51641 = (cppVar_51639 == 168);
	if (cppVar_51641) {
	cppVar_51636 = IE;
	} else {
	cppVar_51643 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51644 = (cppVar_51643 << 3) | 5;
	cppVar_51644 = (cppVar_51644 & cppMask_un_5_);
	cppVar_51645 = (0 << 5) | cppVar_51644;
	cppVar_51645 = (cppVar_51645 & cppMask_un_8_);
	cppVar_51647 = (cppVar_51645 == 176);
	if (cppVar_51647) {
	cppVar_51642 = P3;
	} else {
	cppVar_51649 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51650 = (cppVar_51649 << 3) | 5;
	cppVar_51650 = (cppVar_51650 & cppMask_un_5_);
	cppVar_51651 = (0 << 5) | cppVar_51650;
	cppVar_51651 = (cppVar_51651 & cppMask_un_8_);
	cppVar_51653 = (cppVar_51651 == 184);
	if (cppVar_51653) {
	cppVar_51648 = IP;
	} else {
	cppVar_51655 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51656 = (cppVar_51655 << 3) | 5;
	cppVar_51656 = (cppVar_51656 & cppMask_un_5_);
	cppVar_51657 = (0 << 5) | cppVar_51656;
	cppVar_51657 = (cppVar_51657 & cppMask_un_8_);
	cppVar_51659 = (cppVar_51657 == 208);
	if (cppVar_51659) {
	cppVar_51654 = PSW;
	} else {
	cppVar_51661 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51662 = (cppVar_51661 << 3) | 5;
	cppVar_51662 = (cppVar_51662 & cppMask_un_5_);
	cppVar_51663 = (0 << 5) | cppVar_51662;
	cppVar_51663 = (cppVar_51663 & cppMask_un_8_);
	cppVar_51665 = (cppVar_51663 == 224);
	if (cppVar_51665) {
	cppVar_51660 = ACC;
	} else {
	cppVar_51667 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51668 = (cppVar_51667 << 3) | 5;
	cppVar_51668 = (cppVar_51668 & cppMask_un_5_);
	cppVar_51669 = (0 << 5) | cppVar_51668;
	cppVar_51669 = (cppVar_51669 & cppMask_un_8_);
	cppVar_51671 = (cppVar_51669 == 240);
	if (cppVar_51671) {
	cppVar_51666 = B;
	} else {
	cppVar_51666 = 0;
	}
	cppVar_51660 = cppVar_51666;
	}
	cppVar_51654 = cppVar_51660;
	}
	cppVar_51648 = cppVar_51654;
	}
	cppVar_51642 = cppVar_51648;
	}
	cppVar_51636 = cppVar_51642;
	}
	cppVar_51630 = cppVar_51636;
	}
	cppVar_51624 = cppVar_51630;
	}
	cppVar_51618 = cppVar_51624;
	}
	cppVar_51612 = cppVar_51618;
	}
	cppVar_51606 = cppVar_51612;
	}
	cppVar_51600 = cppVar_51606;
	}
	cppVar_51594 = cppVar_51600;
	}
	cppVar_51588 = cppVar_51594;
	}
	cppVar_51582 = cppVar_51588;
	}
	cppVar_51576 = cppVar_51582;
	}
	cppVar_51570 = cppVar_51576;
	}
	cppVar_51564 = cppVar_51570;
	}
	cppVar_51558 = cppVar_51564;
	}
	cppVar_51552 = cppVar_51558;
	}
	cppVar_51546 = cppVar_51552;
	}
	cppVar_51533 = cppVar_51546;
	}
	cppVar_51527 = cppVar_51533;
	} else {
	cppVar_51527 = PSW;
	}
	cppVar_51523 = cppVar_51527;
	} else {
	cppVar_51674 = ROM.rd(PC);
	cppVar_51676 = (cppVar_51674 == 140);
	if (cppVar_51676) {
	cppVar_51679 = PC + 1;
	cppVar_51679 = (cppVar_51679 & cppMask_un_16_);
	cppVar_51680 = ROM.rd(cppVar_51679);
	cppVar_51682 = (cppVar_51680 == 208);
	if (cppVar_51682) {
	cppVar_51685 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51687 = (cppVar_51685 << 3) | 4;
	cppVar_51687 = (cppVar_51687 & cppMask_un_5_);
	cppVar_51688 = (0 << 5) | cppVar_51687;
	cppVar_51688 = (cppVar_51688 & cppMask_un_8_);
	cppVar_51689 = (cppVar_51688 >> 7) & cppMask_un_1_;
	cppVar_51691 = (cppVar_51689 == 0);
	if (cppVar_51691) {
	cppVar_51692 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51693 = (cppVar_51692 << 3) | 4;
	cppVar_51693 = (cppVar_51693 & cppMask_un_5_);
	cppVar_51694 = (0 << 5) | cppVar_51693;
	cppVar_51694 = (cppVar_51694 & cppMask_un_8_);
	cppVar_51695 = IRAM.rd(cppVar_51694);
	cppVar_51683 = cppVar_51695;
	} else {
	cppVar_51697 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51698 = (cppVar_51697 << 3) | 4;
	cppVar_51698 = (cppVar_51698 & cppMask_un_5_);
	cppVar_51699 = (0 << 5) | cppVar_51698;
	cppVar_51699 = (cppVar_51699 & cppMask_un_8_);
	cppVar_51701 = (cppVar_51699 == 128);
	if (cppVar_51701) {
	cppVar_51696 = P0;
	} else {
	cppVar_51703 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51704 = (cppVar_51703 << 3) | 4;
	cppVar_51704 = (cppVar_51704 & cppMask_un_5_);
	cppVar_51705 = (0 << 5) | cppVar_51704;
	cppVar_51705 = (cppVar_51705 & cppMask_un_8_);
	cppVar_51707 = (cppVar_51705 == 129);
	if (cppVar_51707) {
	cppVar_51702 = SP;
	} else {
	cppVar_51709 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51710 = (cppVar_51709 << 3) | 4;
	cppVar_51710 = (cppVar_51710 & cppMask_un_5_);
	cppVar_51711 = (0 << 5) | cppVar_51710;
	cppVar_51711 = (cppVar_51711 & cppMask_un_8_);
	cppVar_51713 = (cppVar_51711 == 130);
	if (cppVar_51713) {
	cppVar_51708 = DPL;
	} else {
	cppVar_51715 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51716 = (cppVar_51715 << 3) | 4;
	cppVar_51716 = (cppVar_51716 & cppMask_un_5_);
	cppVar_51717 = (0 << 5) | cppVar_51716;
	cppVar_51717 = (cppVar_51717 & cppMask_un_8_);
	cppVar_51719 = (cppVar_51717 == 131);
	if (cppVar_51719) {
	cppVar_51714 = DPH;
	} else {
	cppVar_51721 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51722 = (cppVar_51721 << 3) | 4;
	cppVar_51722 = (cppVar_51722 & cppMask_un_5_);
	cppVar_51723 = (0 << 5) | cppVar_51722;
	cppVar_51723 = (cppVar_51723 & cppMask_un_8_);
	cppVar_51725 = (cppVar_51723 == 135);
	if (cppVar_51725) {
	cppVar_51720 = PCON;
	} else {
	cppVar_51727 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51728 = (cppVar_51727 << 3) | 4;
	cppVar_51728 = (cppVar_51728 & cppMask_un_5_);
	cppVar_51729 = (0 << 5) | cppVar_51728;
	cppVar_51729 = (cppVar_51729 & cppMask_un_8_);
	cppVar_51731 = (cppVar_51729 == 136);
	if (cppVar_51731) {
	cppVar_51726 = TCON;
	} else {
	cppVar_51733 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51734 = (cppVar_51733 << 3) | 4;
	cppVar_51734 = (cppVar_51734 & cppMask_un_5_);
	cppVar_51735 = (0 << 5) | cppVar_51734;
	cppVar_51735 = (cppVar_51735 & cppMask_un_8_);
	cppVar_51737 = (cppVar_51735 == 137);
	if (cppVar_51737) {
	cppVar_51732 = TMOD;
	} else {
	cppVar_51739 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51740 = (cppVar_51739 << 3) | 4;
	cppVar_51740 = (cppVar_51740 & cppMask_un_5_);
	cppVar_51741 = (0 << 5) | cppVar_51740;
	cppVar_51741 = (cppVar_51741 & cppMask_un_8_);
	cppVar_51743 = (cppVar_51741 == 138);
	if (cppVar_51743) {
	cppVar_51738 = TL0;
	} else {
	cppVar_51745 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51746 = (cppVar_51745 << 3) | 4;
	cppVar_51746 = (cppVar_51746 & cppMask_un_5_);
	cppVar_51747 = (0 << 5) | cppVar_51746;
	cppVar_51747 = (cppVar_51747 & cppMask_un_8_);
	cppVar_51749 = (cppVar_51747 == 140);
	if (cppVar_51749) {
	cppVar_51744 = TH0;
	} else {
	cppVar_51751 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51752 = (cppVar_51751 << 3) | 4;
	cppVar_51752 = (cppVar_51752 & cppMask_un_5_);
	cppVar_51753 = (0 << 5) | cppVar_51752;
	cppVar_51753 = (cppVar_51753 & cppMask_un_8_);
	cppVar_51755 = (cppVar_51753 == 139);
	if (cppVar_51755) {
	cppVar_51750 = TL1;
	} else {
	cppVar_51757 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51758 = (cppVar_51757 << 3) | 4;
	cppVar_51758 = (cppVar_51758 & cppMask_un_5_);
	cppVar_51759 = (0 << 5) | cppVar_51758;
	cppVar_51759 = (cppVar_51759 & cppMask_un_8_);
	cppVar_51761 = (cppVar_51759 == 141);
	if (cppVar_51761) {
	cppVar_51756 = TH1;
	} else {
	cppVar_51763 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51764 = (cppVar_51763 << 3) | 4;
	cppVar_51764 = (cppVar_51764 & cppMask_un_5_);
	cppVar_51765 = (0 << 5) | cppVar_51764;
	cppVar_51765 = (cppVar_51765 & cppMask_un_8_);
	cppVar_51767 = (cppVar_51765 == 144);
	if (cppVar_51767) {
	cppVar_51762 = P1;
	} else {
	cppVar_51769 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51770 = (cppVar_51769 << 3) | 4;
	cppVar_51770 = (cppVar_51770 & cppMask_un_5_);
	cppVar_51771 = (0 << 5) | cppVar_51770;
	cppVar_51771 = (cppVar_51771 & cppMask_un_8_);
	cppVar_51773 = (cppVar_51771 == 152);
	if (cppVar_51773) {
	cppVar_51768 = SCON;
	} else {
	cppVar_51775 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51776 = (cppVar_51775 << 3) | 4;
	cppVar_51776 = (cppVar_51776 & cppMask_un_5_);
	cppVar_51777 = (0 << 5) | cppVar_51776;
	cppVar_51777 = (cppVar_51777 & cppMask_un_8_);
	cppVar_51779 = (cppVar_51777 == 153);
	if (cppVar_51779) {
	cppVar_51774 = SBUF;
	} else {
	cppVar_51781 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51782 = (cppVar_51781 << 3) | 4;
	cppVar_51782 = (cppVar_51782 & cppMask_un_5_);
	cppVar_51783 = (0 << 5) | cppVar_51782;
	cppVar_51783 = (cppVar_51783 & cppMask_un_8_);
	cppVar_51785 = (cppVar_51783 == 160);
	if (cppVar_51785) {
	cppVar_51780 = P2;
	} else {
	cppVar_51787 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51788 = (cppVar_51787 << 3) | 4;
	cppVar_51788 = (cppVar_51788 & cppMask_un_5_);
	cppVar_51789 = (0 << 5) | cppVar_51788;
	cppVar_51789 = (cppVar_51789 & cppMask_un_8_);
	cppVar_51791 = (cppVar_51789 == 168);
	if (cppVar_51791) {
	cppVar_51786 = IE;
	} else {
	cppVar_51793 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51794 = (cppVar_51793 << 3) | 4;
	cppVar_51794 = (cppVar_51794 & cppMask_un_5_);
	cppVar_51795 = (0 << 5) | cppVar_51794;
	cppVar_51795 = (cppVar_51795 & cppMask_un_8_);
	cppVar_51797 = (cppVar_51795 == 176);
	if (cppVar_51797) {
	cppVar_51792 = P3;
	} else {
	cppVar_51799 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51800 = (cppVar_51799 << 3) | 4;
	cppVar_51800 = (cppVar_51800 & cppMask_un_5_);
	cppVar_51801 = (0 << 5) | cppVar_51800;
	cppVar_51801 = (cppVar_51801 & cppMask_un_8_);
	cppVar_51803 = (cppVar_51801 == 184);
	if (cppVar_51803) {
	cppVar_51798 = IP;
	} else {
	cppVar_51805 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51806 = (cppVar_51805 << 3) | 4;
	cppVar_51806 = (cppVar_51806 & cppMask_un_5_);
	cppVar_51807 = (0 << 5) | cppVar_51806;
	cppVar_51807 = (cppVar_51807 & cppMask_un_8_);
	cppVar_51809 = (cppVar_51807 == 208);
	if (cppVar_51809) {
	cppVar_51804 = PSW;
	} else {
	cppVar_51811 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51812 = (cppVar_51811 << 3) | 4;
	cppVar_51812 = (cppVar_51812 & cppMask_un_5_);
	cppVar_51813 = (0 << 5) | cppVar_51812;
	cppVar_51813 = (cppVar_51813 & cppMask_un_8_);
	cppVar_51815 = (cppVar_51813 == 224);
	if (cppVar_51815) {
	cppVar_51810 = ACC;
	} else {
	cppVar_51817 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51818 = (cppVar_51817 << 3) | 4;
	cppVar_51818 = (cppVar_51818 & cppMask_un_5_);
	cppVar_51819 = (0 << 5) | cppVar_51818;
	cppVar_51819 = (cppVar_51819 & cppMask_un_8_);
	cppVar_51821 = (cppVar_51819 == 240);
	if (cppVar_51821) {
	cppVar_51816 = B;
	} else {
	cppVar_51816 = 0;
	}
	cppVar_51810 = cppVar_51816;
	}
	cppVar_51804 = cppVar_51810;
	}
	cppVar_51798 = cppVar_51804;
	}
	cppVar_51792 = cppVar_51798;
	}
	cppVar_51786 = cppVar_51792;
	}
	cppVar_51780 = cppVar_51786;
	}
	cppVar_51774 = cppVar_51780;
	}
	cppVar_51768 = cppVar_51774;
	}
	cppVar_51762 = cppVar_51768;
	}
	cppVar_51756 = cppVar_51762;
	}
	cppVar_51750 = cppVar_51756;
	}
	cppVar_51744 = cppVar_51750;
	}
	cppVar_51738 = cppVar_51744;
	}
	cppVar_51732 = cppVar_51738;
	}
	cppVar_51726 = cppVar_51732;
	}
	cppVar_51720 = cppVar_51726;
	}
	cppVar_51714 = cppVar_51720;
	}
	cppVar_51708 = cppVar_51714;
	}
	cppVar_51702 = cppVar_51708;
	}
	cppVar_51696 = cppVar_51702;
	}
	cppVar_51683 = cppVar_51696;
	}
	cppVar_51677 = cppVar_51683;
	} else {
	cppVar_51677 = PSW;
	}
	cppVar_51673 = cppVar_51677;
	} else {
	cppVar_51824 = ROM.rd(PC);
	cppVar_51826 = (cppVar_51824 == 139);
	if (cppVar_51826) {
	cppVar_51829 = PC + 1;
	cppVar_51829 = (cppVar_51829 & cppMask_un_16_);
	cppVar_51830 = ROM.rd(cppVar_51829);
	cppVar_51832 = (cppVar_51830 == 208);
	if (cppVar_51832) {
	cppVar_51835 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51837 = (cppVar_51835 << 3) | 3;
	cppVar_51837 = (cppVar_51837 & cppMask_un_5_);
	cppVar_51838 = (0 << 5) | cppVar_51837;
	cppVar_51838 = (cppVar_51838 & cppMask_un_8_);
	cppVar_51839 = (cppVar_51838 >> 7) & cppMask_un_1_;
	cppVar_51841 = (cppVar_51839 == 0);
	if (cppVar_51841) {
	cppVar_51842 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51843 = (cppVar_51842 << 3) | 3;
	cppVar_51843 = (cppVar_51843 & cppMask_un_5_);
	cppVar_51844 = (0 << 5) | cppVar_51843;
	cppVar_51844 = (cppVar_51844 & cppMask_un_8_);
	cppVar_51845 = IRAM.rd(cppVar_51844);
	cppVar_51833 = cppVar_51845;
	} else {
	cppVar_51847 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51848 = (cppVar_51847 << 3) | 3;
	cppVar_51848 = (cppVar_51848 & cppMask_un_5_);
	cppVar_51849 = (0 << 5) | cppVar_51848;
	cppVar_51849 = (cppVar_51849 & cppMask_un_8_);
	cppVar_51851 = (cppVar_51849 == 128);
	if (cppVar_51851) {
	cppVar_51846 = P0;
	} else {
	cppVar_51853 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51854 = (cppVar_51853 << 3) | 3;
	cppVar_51854 = (cppVar_51854 & cppMask_un_5_);
	cppVar_51855 = (0 << 5) | cppVar_51854;
	cppVar_51855 = (cppVar_51855 & cppMask_un_8_);
	cppVar_51857 = (cppVar_51855 == 129);
	if (cppVar_51857) {
	cppVar_51852 = SP;
	} else {
	cppVar_51859 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51860 = (cppVar_51859 << 3) | 3;
	cppVar_51860 = (cppVar_51860 & cppMask_un_5_);
	cppVar_51861 = (0 << 5) | cppVar_51860;
	cppVar_51861 = (cppVar_51861 & cppMask_un_8_);
	cppVar_51863 = (cppVar_51861 == 130);
	if (cppVar_51863) {
	cppVar_51858 = DPL;
	} else {
	cppVar_51865 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51866 = (cppVar_51865 << 3) | 3;
	cppVar_51866 = (cppVar_51866 & cppMask_un_5_);
	cppVar_51867 = (0 << 5) | cppVar_51866;
	cppVar_51867 = (cppVar_51867 & cppMask_un_8_);
	cppVar_51869 = (cppVar_51867 == 131);
	if (cppVar_51869) {
	cppVar_51864 = DPH;
	} else {
	cppVar_51871 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51872 = (cppVar_51871 << 3) | 3;
	cppVar_51872 = (cppVar_51872 & cppMask_un_5_);
	cppVar_51873 = (0 << 5) | cppVar_51872;
	cppVar_51873 = (cppVar_51873 & cppMask_un_8_);
	cppVar_51875 = (cppVar_51873 == 135);
	if (cppVar_51875) {
	cppVar_51870 = PCON;
	} else {
	cppVar_51877 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51878 = (cppVar_51877 << 3) | 3;
	cppVar_51878 = (cppVar_51878 & cppMask_un_5_);
	cppVar_51879 = (0 << 5) | cppVar_51878;
	cppVar_51879 = (cppVar_51879 & cppMask_un_8_);
	cppVar_51881 = (cppVar_51879 == 136);
	if (cppVar_51881) {
	cppVar_51876 = TCON;
	} else {
	cppVar_51883 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51884 = (cppVar_51883 << 3) | 3;
	cppVar_51884 = (cppVar_51884 & cppMask_un_5_);
	cppVar_51885 = (0 << 5) | cppVar_51884;
	cppVar_51885 = (cppVar_51885 & cppMask_un_8_);
	cppVar_51887 = (cppVar_51885 == 137);
	if (cppVar_51887) {
	cppVar_51882 = TMOD;
	} else {
	cppVar_51889 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51890 = (cppVar_51889 << 3) | 3;
	cppVar_51890 = (cppVar_51890 & cppMask_un_5_);
	cppVar_51891 = (0 << 5) | cppVar_51890;
	cppVar_51891 = (cppVar_51891 & cppMask_un_8_);
	cppVar_51893 = (cppVar_51891 == 138);
	if (cppVar_51893) {
	cppVar_51888 = TL0;
	} else {
	cppVar_51895 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51896 = (cppVar_51895 << 3) | 3;
	cppVar_51896 = (cppVar_51896 & cppMask_un_5_);
	cppVar_51897 = (0 << 5) | cppVar_51896;
	cppVar_51897 = (cppVar_51897 & cppMask_un_8_);
	cppVar_51899 = (cppVar_51897 == 140);
	if (cppVar_51899) {
	cppVar_51894 = TH0;
	} else {
	cppVar_51901 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51902 = (cppVar_51901 << 3) | 3;
	cppVar_51902 = (cppVar_51902 & cppMask_un_5_);
	cppVar_51903 = (0 << 5) | cppVar_51902;
	cppVar_51903 = (cppVar_51903 & cppMask_un_8_);
	cppVar_51905 = (cppVar_51903 == 139);
	if (cppVar_51905) {
	cppVar_51900 = TL1;
	} else {
	cppVar_51907 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51908 = (cppVar_51907 << 3) | 3;
	cppVar_51908 = (cppVar_51908 & cppMask_un_5_);
	cppVar_51909 = (0 << 5) | cppVar_51908;
	cppVar_51909 = (cppVar_51909 & cppMask_un_8_);
	cppVar_51911 = (cppVar_51909 == 141);
	if (cppVar_51911) {
	cppVar_51906 = TH1;
	} else {
	cppVar_51913 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51914 = (cppVar_51913 << 3) | 3;
	cppVar_51914 = (cppVar_51914 & cppMask_un_5_);
	cppVar_51915 = (0 << 5) | cppVar_51914;
	cppVar_51915 = (cppVar_51915 & cppMask_un_8_);
	cppVar_51917 = (cppVar_51915 == 144);
	if (cppVar_51917) {
	cppVar_51912 = P1;
	} else {
	cppVar_51919 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51920 = (cppVar_51919 << 3) | 3;
	cppVar_51920 = (cppVar_51920 & cppMask_un_5_);
	cppVar_51921 = (0 << 5) | cppVar_51920;
	cppVar_51921 = (cppVar_51921 & cppMask_un_8_);
	cppVar_51923 = (cppVar_51921 == 152);
	if (cppVar_51923) {
	cppVar_51918 = SCON;
	} else {
	cppVar_51925 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51926 = (cppVar_51925 << 3) | 3;
	cppVar_51926 = (cppVar_51926 & cppMask_un_5_);
	cppVar_51927 = (0 << 5) | cppVar_51926;
	cppVar_51927 = (cppVar_51927 & cppMask_un_8_);
	cppVar_51929 = (cppVar_51927 == 153);
	if (cppVar_51929) {
	cppVar_51924 = SBUF;
	} else {
	cppVar_51931 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51932 = (cppVar_51931 << 3) | 3;
	cppVar_51932 = (cppVar_51932 & cppMask_un_5_);
	cppVar_51933 = (0 << 5) | cppVar_51932;
	cppVar_51933 = (cppVar_51933 & cppMask_un_8_);
	cppVar_51935 = (cppVar_51933 == 160);
	if (cppVar_51935) {
	cppVar_51930 = P2;
	} else {
	cppVar_51937 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51938 = (cppVar_51937 << 3) | 3;
	cppVar_51938 = (cppVar_51938 & cppMask_un_5_);
	cppVar_51939 = (0 << 5) | cppVar_51938;
	cppVar_51939 = (cppVar_51939 & cppMask_un_8_);
	cppVar_51941 = (cppVar_51939 == 168);
	if (cppVar_51941) {
	cppVar_51936 = IE;
	} else {
	cppVar_51943 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51944 = (cppVar_51943 << 3) | 3;
	cppVar_51944 = (cppVar_51944 & cppMask_un_5_);
	cppVar_51945 = (0 << 5) | cppVar_51944;
	cppVar_51945 = (cppVar_51945 & cppMask_un_8_);
	cppVar_51947 = (cppVar_51945 == 176);
	if (cppVar_51947) {
	cppVar_51942 = P3;
	} else {
	cppVar_51949 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51950 = (cppVar_51949 << 3) | 3;
	cppVar_51950 = (cppVar_51950 & cppMask_un_5_);
	cppVar_51951 = (0 << 5) | cppVar_51950;
	cppVar_51951 = (cppVar_51951 & cppMask_un_8_);
	cppVar_51953 = (cppVar_51951 == 184);
	if (cppVar_51953) {
	cppVar_51948 = IP;
	} else {
	cppVar_51955 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51956 = (cppVar_51955 << 3) | 3;
	cppVar_51956 = (cppVar_51956 & cppMask_un_5_);
	cppVar_51957 = (0 << 5) | cppVar_51956;
	cppVar_51957 = (cppVar_51957 & cppMask_un_8_);
	cppVar_51959 = (cppVar_51957 == 208);
	if (cppVar_51959) {
	cppVar_51954 = PSW;
	} else {
	cppVar_51961 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51962 = (cppVar_51961 << 3) | 3;
	cppVar_51962 = (cppVar_51962 & cppMask_un_5_);
	cppVar_51963 = (0 << 5) | cppVar_51962;
	cppVar_51963 = (cppVar_51963 & cppMask_un_8_);
	cppVar_51965 = (cppVar_51963 == 224);
	if (cppVar_51965) {
	cppVar_51960 = ACC;
	} else {
	cppVar_51967 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51968 = (cppVar_51967 << 3) | 3;
	cppVar_51968 = (cppVar_51968 & cppMask_un_5_);
	cppVar_51969 = (0 << 5) | cppVar_51968;
	cppVar_51969 = (cppVar_51969 & cppMask_un_8_);
	cppVar_51971 = (cppVar_51969 == 240);
	if (cppVar_51971) {
	cppVar_51966 = B;
	} else {
	cppVar_51966 = 0;
	}
	cppVar_51960 = cppVar_51966;
	}
	cppVar_51954 = cppVar_51960;
	}
	cppVar_51948 = cppVar_51954;
	}
	cppVar_51942 = cppVar_51948;
	}
	cppVar_51936 = cppVar_51942;
	}
	cppVar_51930 = cppVar_51936;
	}
	cppVar_51924 = cppVar_51930;
	}
	cppVar_51918 = cppVar_51924;
	}
	cppVar_51912 = cppVar_51918;
	}
	cppVar_51906 = cppVar_51912;
	}
	cppVar_51900 = cppVar_51906;
	}
	cppVar_51894 = cppVar_51900;
	}
	cppVar_51888 = cppVar_51894;
	}
	cppVar_51882 = cppVar_51888;
	}
	cppVar_51876 = cppVar_51882;
	}
	cppVar_51870 = cppVar_51876;
	}
	cppVar_51864 = cppVar_51870;
	}
	cppVar_51858 = cppVar_51864;
	}
	cppVar_51852 = cppVar_51858;
	}
	cppVar_51846 = cppVar_51852;
	}
	cppVar_51833 = cppVar_51846;
	}
	cppVar_51827 = cppVar_51833;
	} else {
	cppVar_51827 = PSW;
	}
	cppVar_51823 = cppVar_51827;
	} else {
	cppVar_51974 = ROM.rd(PC);
	cppVar_51976 = (cppVar_51974 == 138);
	if (cppVar_51976) {
	cppVar_51979 = PC + 1;
	cppVar_51979 = (cppVar_51979 & cppMask_un_16_);
	cppVar_51980 = ROM.rd(cppVar_51979);
	cppVar_51982 = (cppVar_51980 == 208);
	if (cppVar_51982) {
	cppVar_51985 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51987 = (cppVar_51985 << 3) | 2;
	cppVar_51987 = (cppVar_51987 & cppMask_un_5_);
	cppVar_51988 = (0 << 5) | cppVar_51987;
	cppVar_51988 = (cppVar_51988 & cppMask_un_8_);
	cppVar_51989 = (cppVar_51988 >> 7) & cppMask_un_1_;
	cppVar_51991 = (cppVar_51989 == 0);
	if (cppVar_51991) {
	cppVar_51992 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51993 = (cppVar_51992 << 3) | 2;
	cppVar_51993 = (cppVar_51993 & cppMask_un_5_);
	cppVar_51994 = (0 << 5) | cppVar_51993;
	cppVar_51994 = (cppVar_51994 & cppMask_un_8_);
	cppVar_51995 = IRAM.rd(cppVar_51994);
	cppVar_51983 = cppVar_51995;
	} else {
	cppVar_51997 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51998 = (cppVar_51997 << 3) | 2;
	cppVar_51998 = (cppVar_51998 & cppMask_un_5_);
	cppVar_51999 = (0 << 5) | cppVar_51998;
	cppVar_51999 = (cppVar_51999 & cppMask_un_8_);
	cppVar_52001 = (cppVar_51999 == 128);
	if (cppVar_52001) {
	cppVar_51996 = P0;
	} else {
	cppVar_52003 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52004 = (cppVar_52003 << 3) | 2;
	cppVar_52004 = (cppVar_52004 & cppMask_un_5_);
	cppVar_52005 = (0 << 5) | cppVar_52004;
	cppVar_52005 = (cppVar_52005 & cppMask_un_8_);
	cppVar_52007 = (cppVar_52005 == 129);
	if (cppVar_52007) {
	cppVar_52002 = SP;
	} else {
	cppVar_52009 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52010 = (cppVar_52009 << 3) | 2;
	cppVar_52010 = (cppVar_52010 & cppMask_un_5_);
	cppVar_52011 = (0 << 5) | cppVar_52010;
	cppVar_52011 = (cppVar_52011 & cppMask_un_8_);
	cppVar_52013 = (cppVar_52011 == 130);
	if (cppVar_52013) {
	cppVar_52008 = DPL;
	} else {
	cppVar_52015 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52016 = (cppVar_52015 << 3) | 2;
	cppVar_52016 = (cppVar_52016 & cppMask_un_5_);
	cppVar_52017 = (0 << 5) | cppVar_52016;
	cppVar_52017 = (cppVar_52017 & cppMask_un_8_);
	cppVar_52019 = (cppVar_52017 == 131);
	if (cppVar_52019) {
	cppVar_52014 = DPH;
	} else {
	cppVar_52021 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52022 = (cppVar_52021 << 3) | 2;
	cppVar_52022 = (cppVar_52022 & cppMask_un_5_);
	cppVar_52023 = (0 << 5) | cppVar_52022;
	cppVar_52023 = (cppVar_52023 & cppMask_un_8_);
	cppVar_52025 = (cppVar_52023 == 135);
	if (cppVar_52025) {
	cppVar_52020 = PCON;
	} else {
	cppVar_52027 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52028 = (cppVar_52027 << 3) | 2;
	cppVar_52028 = (cppVar_52028 & cppMask_un_5_);
	cppVar_52029 = (0 << 5) | cppVar_52028;
	cppVar_52029 = (cppVar_52029 & cppMask_un_8_);
	cppVar_52031 = (cppVar_52029 == 136);
	if (cppVar_52031) {
	cppVar_52026 = TCON;
	} else {
	cppVar_52033 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52034 = (cppVar_52033 << 3) | 2;
	cppVar_52034 = (cppVar_52034 & cppMask_un_5_);
	cppVar_52035 = (0 << 5) | cppVar_52034;
	cppVar_52035 = (cppVar_52035 & cppMask_un_8_);
	cppVar_52037 = (cppVar_52035 == 137);
	if (cppVar_52037) {
	cppVar_52032 = TMOD;
	} else {
	cppVar_52039 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52040 = (cppVar_52039 << 3) | 2;
	cppVar_52040 = (cppVar_52040 & cppMask_un_5_);
	cppVar_52041 = (0 << 5) | cppVar_52040;
	cppVar_52041 = (cppVar_52041 & cppMask_un_8_);
	cppVar_52043 = (cppVar_52041 == 138);
	if (cppVar_52043) {
	cppVar_52038 = TL0;
	} else {
	cppVar_52045 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52046 = (cppVar_52045 << 3) | 2;
	cppVar_52046 = (cppVar_52046 & cppMask_un_5_);
	cppVar_52047 = (0 << 5) | cppVar_52046;
	cppVar_52047 = (cppVar_52047 & cppMask_un_8_);
	cppVar_52049 = (cppVar_52047 == 140);
	if (cppVar_52049) {
	cppVar_52044 = TH0;
	} else {
	cppVar_52051 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52052 = (cppVar_52051 << 3) | 2;
	cppVar_52052 = (cppVar_52052 & cppMask_un_5_);
	cppVar_52053 = (0 << 5) | cppVar_52052;
	cppVar_52053 = (cppVar_52053 & cppMask_un_8_);
	cppVar_52055 = (cppVar_52053 == 139);
	if (cppVar_52055) {
	cppVar_52050 = TL1;
	} else {
	cppVar_52057 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52058 = (cppVar_52057 << 3) | 2;
	cppVar_52058 = (cppVar_52058 & cppMask_un_5_);
	cppVar_52059 = (0 << 5) | cppVar_52058;
	cppVar_52059 = (cppVar_52059 & cppMask_un_8_);
	cppVar_52061 = (cppVar_52059 == 141);
	if (cppVar_52061) {
	cppVar_52056 = TH1;
	} else {
	cppVar_52063 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52064 = (cppVar_52063 << 3) | 2;
	cppVar_52064 = (cppVar_52064 & cppMask_un_5_);
	cppVar_52065 = (0 << 5) | cppVar_52064;
	cppVar_52065 = (cppVar_52065 & cppMask_un_8_);
	cppVar_52067 = (cppVar_52065 == 144);
	if (cppVar_52067) {
	cppVar_52062 = P1;
	} else {
	cppVar_52069 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52070 = (cppVar_52069 << 3) | 2;
	cppVar_52070 = (cppVar_52070 & cppMask_un_5_);
	cppVar_52071 = (0 << 5) | cppVar_52070;
	cppVar_52071 = (cppVar_52071 & cppMask_un_8_);
	cppVar_52073 = (cppVar_52071 == 152);
	if (cppVar_52073) {
	cppVar_52068 = SCON;
	} else {
	cppVar_52075 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52076 = (cppVar_52075 << 3) | 2;
	cppVar_52076 = (cppVar_52076 & cppMask_un_5_);
	cppVar_52077 = (0 << 5) | cppVar_52076;
	cppVar_52077 = (cppVar_52077 & cppMask_un_8_);
	cppVar_52079 = (cppVar_52077 == 153);
	if (cppVar_52079) {
	cppVar_52074 = SBUF;
	} else {
	cppVar_52081 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52082 = (cppVar_52081 << 3) | 2;
	cppVar_52082 = (cppVar_52082 & cppMask_un_5_);
	cppVar_52083 = (0 << 5) | cppVar_52082;
	cppVar_52083 = (cppVar_52083 & cppMask_un_8_);
	cppVar_52085 = (cppVar_52083 == 160);
	if (cppVar_52085) {
	cppVar_52080 = P2;
	} else {
	cppVar_52087 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52088 = (cppVar_52087 << 3) | 2;
	cppVar_52088 = (cppVar_52088 & cppMask_un_5_);
	cppVar_52089 = (0 << 5) | cppVar_52088;
	cppVar_52089 = (cppVar_52089 & cppMask_un_8_);
	cppVar_52091 = (cppVar_52089 == 168);
	if (cppVar_52091) {
	cppVar_52086 = IE;
	} else {
	cppVar_52093 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52094 = (cppVar_52093 << 3) | 2;
	cppVar_52094 = (cppVar_52094 & cppMask_un_5_);
	cppVar_52095 = (0 << 5) | cppVar_52094;
	cppVar_52095 = (cppVar_52095 & cppMask_un_8_);
	cppVar_52097 = (cppVar_52095 == 176);
	if (cppVar_52097) {
	cppVar_52092 = P3;
	} else {
	cppVar_52099 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52100 = (cppVar_52099 << 3) | 2;
	cppVar_52100 = (cppVar_52100 & cppMask_un_5_);
	cppVar_52101 = (0 << 5) | cppVar_52100;
	cppVar_52101 = (cppVar_52101 & cppMask_un_8_);
	cppVar_52103 = (cppVar_52101 == 184);
	if (cppVar_52103) {
	cppVar_52098 = IP;
	} else {
	cppVar_52105 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52106 = (cppVar_52105 << 3) | 2;
	cppVar_52106 = (cppVar_52106 & cppMask_un_5_);
	cppVar_52107 = (0 << 5) | cppVar_52106;
	cppVar_52107 = (cppVar_52107 & cppMask_un_8_);
	cppVar_52109 = (cppVar_52107 == 208);
	if (cppVar_52109) {
	cppVar_52104 = PSW;
	} else {
	cppVar_52111 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52112 = (cppVar_52111 << 3) | 2;
	cppVar_52112 = (cppVar_52112 & cppMask_un_5_);
	cppVar_52113 = (0 << 5) | cppVar_52112;
	cppVar_52113 = (cppVar_52113 & cppMask_un_8_);
	cppVar_52115 = (cppVar_52113 == 224);
	if (cppVar_52115) {
	cppVar_52110 = ACC;
	} else {
	cppVar_52117 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52118 = (cppVar_52117 << 3) | 2;
	cppVar_52118 = (cppVar_52118 & cppMask_un_5_);
	cppVar_52119 = (0 << 5) | cppVar_52118;
	cppVar_52119 = (cppVar_52119 & cppMask_un_8_);
	cppVar_52121 = (cppVar_52119 == 240);
	if (cppVar_52121) {
	cppVar_52116 = B;
	} else {
	cppVar_52116 = 0;
	}
	cppVar_52110 = cppVar_52116;
	}
	cppVar_52104 = cppVar_52110;
	}
	cppVar_52098 = cppVar_52104;
	}
	cppVar_52092 = cppVar_52098;
	}
	cppVar_52086 = cppVar_52092;
	}
	cppVar_52080 = cppVar_52086;
	}
	cppVar_52074 = cppVar_52080;
	}
	cppVar_52068 = cppVar_52074;
	}
	cppVar_52062 = cppVar_52068;
	}
	cppVar_52056 = cppVar_52062;
	}
	cppVar_52050 = cppVar_52056;
	}
	cppVar_52044 = cppVar_52050;
	}
	cppVar_52038 = cppVar_52044;
	}
	cppVar_52032 = cppVar_52038;
	}
	cppVar_52026 = cppVar_52032;
	}
	cppVar_52020 = cppVar_52026;
	}
	cppVar_52014 = cppVar_52020;
	}
	cppVar_52008 = cppVar_52014;
	}
	cppVar_52002 = cppVar_52008;
	}
	cppVar_51996 = cppVar_52002;
	}
	cppVar_51983 = cppVar_51996;
	}
	cppVar_51977 = cppVar_51983;
	} else {
	cppVar_51977 = PSW;
	}
	cppVar_51973 = cppVar_51977;
	} else {
	cppVar_52124 = ROM.rd(PC);
	cppVar_52126 = (cppVar_52124 == 137);
	if (cppVar_52126) {
	cppVar_52129 = PC + 1;
	cppVar_52129 = (cppVar_52129 & cppMask_un_16_);
	cppVar_52130 = ROM.rd(cppVar_52129);
	cppVar_52132 = (cppVar_52130 == 208);
	if (cppVar_52132) {
	cppVar_52135 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52137 = (cppVar_52135 << 3) | 1;
	cppVar_52137 = (cppVar_52137 & cppMask_un_5_);
	cppVar_52138 = (0 << 5) | cppVar_52137;
	cppVar_52138 = (cppVar_52138 & cppMask_un_8_);
	cppVar_52139 = (cppVar_52138 >> 7) & cppMask_un_1_;
	cppVar_52141 = (cppVar_52139 == 0);
	if (cppVar_52141) {
	cppVar_52142 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52143 = (cppVar_52142 << 3) | 1;
	cppVar_52143 = (cppVar_52143 & cppMask_un_5_);
	cppVar_52144 = (0 << 5) | cppVar_52143;
	cppVar_52144 = (cppVar_52144 & cppMask_un_8_);
	cppVar_52145 = IRAM.rd(cppVar_52144);
	cppVar_52133 = cppVar_52145;
	} else {
	cppVar_52147 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52148 = (cppVar_52147 << 3) | 1;
	cppVar_52148 = (cppVar_52148 & cppMask_un_5_);
	cppVar_52149 = (0 << 5) | cppVar_52148;
	cppVar_52149 = (cppVar_52149 & cppMask_un_8_);
	cppVar_52151 = (cppVar_52149 == 128);
	if (cppVar_52151) {
	cppVar_52146 = P0;
	} else {
	cppVar_52153 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52154 = (cppVar_52153 << 3) | 1;
	cppVar_52154 = (cppVar_52154 & cppMask_un_5_);
	cppVar_52155 = (0 << 5) | cppVar_52154;
	cppVar_52155 = (cppVar_52155 & cppMask_un_8_);
	cppVar_52157 = (cppVar_52155 == 129);
	if (cppVar_52157) {
	cppVar_52152 = SP;
	} else {
	cppVar_52159 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52160 = (cppVar_52159 << 3) | 1;
	cppVar_52160 = (cppVar_52160 & cppMask_un_5_);
	cppVar_52161 = (0 << 5) | cppVar_52160;
	cppVar_52161 = (cppVar_52161 & cppMask_un_8_);
	cppVar_52163 = (cppVar_52161 == 130);
	if (cppVar_52163) {
	cppVar_52158 = DPL;
	} else {
	cppVar_52165 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52166 = (cppVar_52165 << 3) | 1;
	cppVar_52166 = (cppVar_52166 & cppMask_un_5_);
	cppVar_52167 = (0 << 5) | cppVar_52166;
	cppVar_52167 = (cppVar_52167 & cppMask_un_8_);
	cppVar_52169 = (cppVar_52167 == 131);
	if (cppVar_52169) {
	cppVar_52164 = DPH;
	} else {
	cppVar_52171 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52172 = (cppVar_52171 << 3) | 1;
	cppVar_52172 = (cppVar_52172 & cppMask_un_5_);
	cppVar_52173 = (0 << 5) | cppVar_52172;
	cppVar_52173 = (cppVar_52173 & cppMask_un_8_);
	cppVar_52175 = (cppVar_52173 == 135);
	if (cppVar_52175) {
	cppVar_52170 = PCON;
	} else {
	cppVar_52177 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52178 = (cppVar_52177 << 3) | 1;
	cppVar_52178 = (cppVar_52178 & cppMask_un_5_);
	cppVar_52179 = (0 << 5) | cppVar_52178;
	cppVar_52179 = (cppVar_52179 & cppMask_un_8_);
	cppVar_52181 = (cppVar_52179 == 136);
	if (cppVar_52181) {
	cppVar_52176 = TCON;
	} else {
	cppVar_52183 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52184 = (cppVar_52183 << 3) | 1;
	cppVar_52184 = (cppVar_52184 & cppMask_un_5_);
	cppVar_52185 = (0 << 5) | cppVar_52184;
	cppVar_52185 = (cppVar_52185 & cppMask_un_8_);
	cppVar_52187 = (cppVar_52185 == 137);
	if (cppVar_52187) {
	cppVar_52182 = TMOD;
	} else {
	cppVar_52189 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52190 = (cppVar_52189 << 3) | 1;
	cppVar_52190 = (cppVar_52190 & cppMask_un_5_);
	cppVar_52191 = (0 << 5) | cppVar_52190;
	cppVar_52191 = (cppVar_52191 & cppMask_un_8_);
	cppVar_52193 = (cppVar_52191 == 138);
	if (cppVar_52193) {
	cppVar_52188 = TL0;
	} else {
	cppVar_52195 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52196 = (cppVar_52195 << 3) | 1;
	cppVar_52196 = (cppVar_52196 & cppMask_un_5_);
	cppVar_52197 = (0 << 5) | cppVar_52196;
	cppVar_52197 = (cppVar_52197 & cppMask_un_8_);
	cppVar_52199 = (cppVar_52197 == 140);
	if (cppVar_52199) {
	cppVar_52194 = TH0;
	} else {
	cppVar_52201 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52202 = (cppVar_52201 << 3) | 1;
	cppVar_52202 = (cppVar_52202 & cppMask_un_5_);
	cppVar_52203 = (0 << 5) | cppVar_52202;
	cppVar_52203 = (cppVar_52203 & cppMask_un_8_);
	cppVar_52205 = (cppVar_52203 == 139);
	if (cppVar_52205) {
	cppVar_52200 = TL1;
	} else {
	cppVar_52207 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52208 = (cppVar_52207 << 3) | 1;
	cppVar_52208 = (cppVar_52208 & cppMask_un_5_);
	cppVar_52209 = (0 << 5) | cppVar_52208;
	cppVar_52209 = (cppVar_52209 & cppMask_un_8_);
	cppVar_52211 = (cppVar_52209 == 141);
	if (cppVar_52211) {
	cppVar_52206 = TH1;
	} else {
	cppVar_52213 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52214 = (cppVar_52213 << 3) | 1;
	cppVar_52214 = (cppVar_52214 & cppMask_un_5_);
	cppVar_52215 = (0 << 5) | cppVar_52214;
	cppVar_52215 = (cppVar_52215 & cppMask_un_8_);
	cppVar_52217 = (cppVar_52215 == 144);
	if (cppVar_52217) {
	cppVar_52212 = P1;
	} else {
	cppVar_52219 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52220 = (cppVar_52219 << 3) | 1;
	cppVar_52220 = (cppVar_52220 & cppMask_un_5_);
	cppVar_52221 = (0 << 5) | cppVar_52220;
	cppVar_52221 = (cppVar_52221 & cppMask_un_8_);
	cppVar_52223 = (cppVar_52221 == 152);
	if (cppVar_52223) {
	cppVar_52218 = SCON;
	} else {
	cppVar_52225 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52226 = (cppVar_52225 << 3) | 1;
	cppVar_52226 = (cppVar_52226 & cppMask_un_5_);
	cppVar_52227 = (0 << 5) | cppVar_52226;
	cppVar_52227 = (cppVar_52227 & cppMask_un_8_);
	cppVar_52229 = (cppVar_52227 == 153);
	if (cppVar_52229) {
	cppVar_52224 = SBUF;
	} else {
	cppVar_52231 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52232 = (cppVar_52231 << 3) | 1;
	cppVar_52232 = (cppVar_52232 & cppMask_un_5_);
	cppVar_52233 = (0 << 5) | cppVar_52232;
	cppVar_52233 = (cppVar_52233 & cppMask_un_8_);
	cppVar_52235 = (cppVar_52233 == 160);
	if (cppVar_52235) {
	cppVar_52230 = P2;
	} else {
	cppVar_52237 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52238 = (cppVar_52237 << 3) | 1;
	cppVar_52238 = (cppVar_52238 & cppMask_un_5_);
	cppVar_52239 = (0 << 5) | cppVar_52238;
	cppVar_52239 = (cppVar_52239 & cppMask_un_8_);
	cppVar_52241 = (cppVar_52239 == 168);
	if (cppVar_52241) {
	cppVar_52236 = IE;
	} else {
	cppVar_52243 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52244 = (cppVar_52243 << 3) | 1;
	cppVar_52244 = (cppVar_52244 & cppMask_un_5_);
	cppVar_52245 = (0 << 5) | cppVar_52244;
	cppVar_52245 = (cppVar_52245 & cppMask_un_8_);
	cppVar_52247 = (cppVar_52245 == 176);
	if (cppVar_52247) {
	cppVar_52242 = P3;
	} else {
	cppVar_52249 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52250 = (cppVar_52249 << 3) | 1;
	cppVar_52250 = (cppVar_52250 & cppMask_un_5_);
	cppVar_52251 = (0 << 5) | cppVar_52250;
	cppVar_52251 = (cppVar_52251 & cppMask_un_8_);
	cppVar_52253 = (cppVar_52251 == 184);
	if (cppVar_52253) {
	cppVar_52248 = IP;
	} else {
	cppVar_52255 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52256 = (cppVar_52255 << 3) | 1;
	cppVar_52256 = (cppVar_52256 & cppMask_un_5_);
	cppVar_52257 = (0 << 5) | cppVar_52256;
	cppVar_52257 = (cppVar_52257 & cppMask_un_8_);
	cppVar_52259 = (cppVar_52257 == 208);
	if (cppVar_52259) {
	cppVar_52254 = PSW;
	} else {
	cppVar_52261 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52262 = (cppVar_52261 << 3) | 1;
	cppVar_52262 = (cppVar_52262 & cppMask_un_5_);
	cppVar_52263 = (0 << 5) | cppVar_52262;
	cppVar_52263 = (cppVar_52263 & cppMask_un_8_);
	cppVar_52265 = (cppVar_52263 == 224);
	if (cppVar_52265) {
	cppVar_52260 = ACC;
	} else {
	cppVar_52267 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52268 = (cppVar_52267 << 3) | 1;
	cppVar_52268 = (cppVar_52268 & cppMask_un_5_);
	cppVar_52269 = (0 << 5) | cppVar_52268;
	cppVar_52269 = (cppVar_52269 & cppMask_un_8_);
	cppVar_52271 = (cppVar_52269 == 240);
	if (cppVar_52271) {
	cppVar_52266 = B;
	} else {
	cppVar_52266 = 0;
	}
	cppVar_52260 = cppVar_52266;
	}
	cppVar_52254 = cppVar_52260;
	}
	cppVar_52248 = cppVar_52254;
	}
	cppVar_52242 = cppVar_52248;
	}
	cppVar_52236 = cppVar_52242;
	}
	cppVar_52230 = cppVar_52236;
	}
	cppVar_52224 = cppVar_52230;
	}
	cppVar_52218 = cppVar_52224;
	}
	cppVar_52212 = cppVar_52218;
	}
	cppVar_52206 = cppVar_52212;
	}
	cppVar_52200 = cppVar_52206;
	}
	cppVar_52194 = cppVar_52200;
	}
	cppVar_52188 = cppVar_52194;
	}
	cppVar_52182 = cppVar_52188;
	}
	cppVar_52176 = cppVar_52182;
	}
	cppVar_52170 = cppVar_52176;
	}
	cppVar_52164 = cppVar_52170;
	}
	cppVar_52158 = cppVar_52164;
	}
	cppVar_52152 = cppVar_52158;
	}
	cppVar_52146 = cppVar_52152;
	}
	cppVar_52133 = cppVar_52146;
	}
	cppVar_52127 = cppVar_52133;
	} else {
	cppVar_52127 = PSW;
	}
	cppVar_52123 = cppVar_52127;
	} else {
	cppVar_52274 = ROM.rd(PC);
	cppVar_52276 = (cppVar_52274 == 136);
	if (cppVar_52276) {
	cppVar_52279 = PC + 1;
	cppVar_52279 = (cppVar_52279 & cppMask_un_16_);
	cppVar_52280 = ROM.rd(cppVar_52279);
	cppVar_52282 = (cppVar_52280 == 208);
	if (cppVar_52282) {
	cppVar_52285 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52287 = (cppVar_52285 << 3) | 0;
	cppVar_52287 = (cppVar_52287 & cppMask_un_5_);
	cppVar_52288 = (0 << 5) | cppVar_52287;
	cppVar_52288 = (cppVar_52288 & cppMask_un_8_);
	cppVar_52289 = (cppVar_52288 >> 7) & cppMask_un_1_;
	cppVar_52291 = (cppVar_52289 == 0);
	if (cppVar_52291) {
	cppVar_52292 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52293 = (cppVar_52292 << 3) | 0;
	cppVar_52293 = (cppVar_52293 & cppMask_un_5_);
	cppVar_52294 = (0 << 5) | cppVar_52293;
	cppVar_52294 = (cppVar_52294 & cppMask_un_8_);
	cppVar_52295 = IRAM.rd(cppVar_52294);
	cppVar_52283 = cppVar_52295;
	} else {
	cppVar_52297 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52298 = (cppVar_52297 << 3) | 0;
	cppVar_52298 = (cppVar_52298 & cppMask_un_5_);
	cppVar_52299 = (0 << 5) | cppVar_52298;
	cppVar_52299 = (cppVar_52299 & cppMask_un_8_);
	cppVar_52301 = (cppVar_52299 == 128);
	if (cppVar_52301) {
	cppVar_52296 = P0;
	} else {
	cppVar_52303 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52304 = (cppVar_52303 << 3) | 0;
	cppVar_52304 = (cppVar_52304 & cppMask_un_5_);
	cppVar_52305 = (0 << 5) | cppVar_52304;
	cppVar_52305 = (cppVar_52305 & cppMask_un_8_);
	cppVar_52307 = (cppVar_52305 == 129);
	if (cppVar_52307) {
	cppVar_52302 = SP;
	} else {
	cppVar_52309 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52310 = (cppVar_52309 << 3) | 0;
	cppVar_52310 = (cppVar_52310 & cppMask_un_5_);
	cppVar_52311 = (0 << 5) | cppVar_52310;
	cppVar_52311 = (cppVar_52311 & cppMask_un_8_);
	cppVar_52313 = (cppVar_52311 == 130);
	if (cppVar_52313) {
	cppVar_52308 = DPL;
	} else {
	cppVar_52315 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52316 = (cppVar_52315 << 3) | 0;
	cppVar_52316 = (cppVar_52316 & cppMask_un_5_);
	cppVar_52317 = (0 << 5) | cppVar_52316;
	cppVar_52317 = (cppVar_52317 & cppMask_un_8_);
	cppVar_52319 = (cppVar_52317 == 131);
	if (cppVar_52319) {
	cppVar_52314 = DPH;
	} else {
	cppVar_52321 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52322 = (cppVar_52321 << 3) | 0;
	cppVar_52322 = (cppVar_52322 & cppMask_un_5_);
	cppVar_52323 = (0 << 5) | cppVar_52322;
	cppVar_52323 = (cppVar_52323 & cppMask_un_8_);
	cppVar_52325 = (cppVar_52323 == 135);
	if (cppVar_52325) {
	cppVar_52320 = PCON;
	} else {
	cppVar_52327 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52328 = (cppVar_52327 << 3) | 0;
	cppVar_52328 = (cppVar_52328 & cppMask_un_5_);
	cppVar_52329 = (0 << 5) | cppVar_52328;
	cppVar_52329 = (cppVar_52329 & cppMask_un_8_);
	cppVar_52331 = (cppVar_52329 == 136);
	if (cppVar_52331) {
	cppVar_52326 = TCON;
	} else {
	cppVar_52333 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52334 = (cppVar_52333 << 3) | 0;
	cppVar_52334 = (cppVar_52334 & cppMask_un_5_);
	cppVar_52335 = (0 << 5) | cppVar_52334;
	cppVar_52335 = (cppVar_52335 & cppMask_un_8_);
	cppVar_52337 = (cppVar_52335 == 137);
	if (cppVar_52337) {
	cppVar_52332 = TMOD;
	} else {
	cppVar_52339 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52340 = (cppVar_52339 << 3) | 0;
	cppVar_52340 = (cppVar_52340 & cppMask_un_5_);
	cppVar_52341 = (0 << 5) | cppVar_52340;
	cppVar_52341 = (cppVar_52341 & cppMask_un_8_);
	cppVar_52343 = (cppVar_52341 == 138);
	if (cppVar_52343) {
	cppVar_52338 = TL0;
	} else {
	cppVar_52345 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52346 = (cppVar_52345 << 3) | 0;
	cppVar_52346 = (cppVar_52346 & cppMask_un_5_);
	cppVar_52347 = (0 << 5) | cppVar_52346;
	cppVar_52347 = (cppVar_52347 & cppMask_un_8_);
	cppVar_52349 = (cppVar_52347 == 140);
	if (cppVar_52349) {
	cppVar_52344 = TH0;
	} else {
	cppVar_52351 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52352 = (cppVar_52351 << 3) | 0;
	cppVar_52352 = (cppVar_52352 & cppMask_un_5_);
	cppVar_52353 = (0 << 5) | cppVar_52352;
	cppVar_52353 = (cppVar_52353 & cppMask_un_8_);
	cppVar_52355 = (cppVar_52353 == 139);
	if (cppVar_52355) {
	cppVar_52350 = TL1;
	} else {
	cppVar_52357 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52358 = (cppVar_52357 << 3) | 0;
	cppVar_52358 = (cppVar_52358 & cppMask_un_5_);
	cppVar_52359 = (0 << 5) | cppVar_52358;
	cppVar_52359 = (cppVar_52359 & cppMask_un_8_);
	cppVar_52361 = (cppVar_52359 == 141);
	if (cppVar_52361) {
	cppVar_52356 = TH1;
	} else {
	cppVar_52363 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52364 = (cppVar_52363 << 3) | 0;
	cppVar_52364 = (cppVar_52364 & cppMask_un_5_);
	cppVar_52365 = (0 << 5) | cppVar_52364;
	cppVar_52365 = (cppVar_52365 & cppMask_un_8_);
	cppVar_52367 = (cppVar_52365 == 144);
	if (cppVar_52367) {
	cppVar_52362 = P1;
	} else {
	cppVar_52369 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52370 = (cppVar_52369 << 3) | 0;
	cppVar_52370 = (cppVar_52370 & cppMask_un_5_);
	cppVar_52371 = (0 << 5) | cppVar_52370;
	cppVar_52371 = (cppVar_52371 & cppMask_un_8_);
	cppVar_52373 = (cppVar_52371 == 152);
	if (cppVar_52373) {
	cppVar_52368 = SCON;
	} else {
	cppVar_52375 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52376 = (cppVar_52375 << 3) | 0;
	cppVar_52376 = (cppVar_52376 & cppMask_un_5_);
	cppVar_52377 = (0 << 5) | cppVar_52376;
	cppVar_52377 = (cppVar_52377 & cppMask_un_8_);
	cppVar_52379 = (cppVar_52377 == 153);
	if (cppVar_52379) {
	cppVar_52374 = SBUF;
	} else {
	cppVar_52381 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52382 = (cppVar_52381 << 3) | 0;
	cppVar_52382 = (cppVar_52382 & cppMask_un_5_);
	cppVar_52383 = (0 << 5) | cppVar_52382;
	cppVar_52383 = (cppVar_52383 & cppMask_un_8_);
	cppVar_52385 = (cppVar_52383 == 160);
	if (cppVar_52385) {
	cppVar_52380 = P2;
	} else {
	cppVar_52387 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52388 = (cppVar_52387 << 3) | 0;
	cppVar_52388 = (cppVar_52388 & cppMask_un_5_);
	cppVar_52389 = (0 << 5) | cppVar_52388;
	cppVar_52389 = (cppVar_52389 & cppMask_un_8_);
	cppVar_52391 = (cppVar_52389 == 168);
	if (cppVar_52391) {
	cppVar_52386 = IE;
	} else {
	cppVar_52393 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52394 = (cppVar_52393 << 3) | 0;
	cppVar_52394 = (cppVar_52394 & cppMask_un_5_);
	cppVar_52395 = (0 << 5) | cppVar_52394;
	cppVar_52395 = (cppVar_52395 & cppMask_un_8_);
	cppVar_52397 = (cppVar_52395 == 176);
	if (cppVar_52397) {
	cppVar_52392 = P3;
	} else {
	cppVar_52399 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52400 = (cppVar_52399 << 3) | 0;
	cppVar_52400 = (cppVar_52400 & cppMask_un_5_);
	cppVar_52401 = (0 << 5) | cppVar_52400;
	cppVar_52401 = (cppVar_52401 & cppMask_un_8_);
	cppVar_52403 = (cppVar_52401 == 184);
	if (cppVar_52403) {
	cppVar_52398 = IP;
	} else {
	cppVar_52405 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52406 = (cppVar_52405 << 3) | 0;
	cppVar_52406 = (cppVar_52406 & cppMask_un_5_);
	cppVar_52407 = (0 << 5) | cppVar_52406;
	cppVar_52407 = (cppVar_52407 & cppMask_un_8_);
	cppVar_52409 = (cppVar_52407 == 208);
	if (cppVar_52409) {
	cppVar_52404 = PSW;
	} else {
	cppVar_52411 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52412 = (cppVar_52411 << 3) | 0;
	cppVar_52412 = (cppVar_52412 & cppMask_un_5_);
	cppVar_52413 = (0 << 5) | cppVar_52412;
	cppVar_52413 = (cppVar_52413 & cppMask_un_8_);
	cppVar_52415 = (cppVar_52413 == 224);
	if (cppVar_52415) {
	cppVar_52410 = ACC;
	} else {
	cppVar_52417 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52418 = (cppVar_52417 << 3) | 0;
	cppVar_52418 = (cppVar_52418 & cppMask_un_5_);
	cppVar_52419 = (0 << 5) | cppVar_52418;
	cppVar_52419 = (cppVar_52419 & cppMask_un_8_);
	cppVar_52421 = (cppVar_52419 == 240);
	if (cppVar_52421) {
	cppVar_52416 = B;
	} else {
	cppVar_52416 = 0;
	}
	cppVar_52410 = cppVar_52416;
	}
	cppVar_52404 = cppVar_52410;
	}
	cppVar_52398 = cppVar_52404;
	}
	cppVar_52392 = cppVar_52398;
	}
	cppVar_52386 = cppVar_52392;
	}
	cppVar_52380 = cppVar_52386;
	}
	cppVar_52374 = cppVar_52380;
	}
	cppVar_52368 = cppVar_52374;
	}
	cppVar_52362 = cppVar_52368;
	}
	cppVar_52356 = cppVar_52362;
	}
	cppVar_52350 = cppVar_52356;
	}
	cppVar_52344 = cppVar_52350;
	}
	cppVar_52338 = cppVar_52344;
	}
	cppVar_52332 = cppVar_52338;
	}
	cppVar_52326 = cppVar_52332;
	}
	cppVar_52320 = cppVar_52326;
	}
	cppVar_52314 = cppVar_52320;
	}
	cppVar_52308 = cppVar_52314;
	}
	cppVar_52302 = cppVar_52308;
	}
	cppVar_52296 = cppVar_52302;
	}
	cppVar_52283 = cppVar_52296;
	}
	cppVar_52277 = cppVar_52283;
	} else {
	cppVar_52277 = PSW;
	}
	cppVar_52273 = cppVar_52277;
	} else {
	cppVar_52424 = ROM.rd(PC);
	cppVar_52426 = (cppVar_52424 == 135);
	if (cppVar_52426) {
	cppVar_52429 = PC + 1;
	cppVar_52429 = (cppVar_52429 & cppMask_un_16_);
	cppVar_52430 = ROM.rd(cppVar_52429);
	cppVar_52432 = (cppVar_52430 == 208);
	if (cppVar_52432) {
	cppVar_52434 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52436 = (cppVar_52434 << 3) | 1;
	cppVar_52436 = (cppVar_52436 & cppMask_un_5_);
	cppVar_52437 = (0 << 5) | cppVar_52436;
	cppVar_52437 = (cppVar_52437 & cppMask_un_8_);
	cppVar_52438 = IRAM.rd(cppVar_52437);
	cppVar_52439 = IRAM.rd(cppVar_52438);
	cppVar_52427 = cppVar_52439;
	} else {
	cppVar_52427 = PSW;
	}
	cppVar_52423 = cppVar_52427;
	} else {
	cppVar_52441 = ROM.rd(PC);
	cppVar_52443 = (cppVar_52441 == 134);
	if (cppVar_52443) {
	cppVar_52446 = PC + 1;
	cppVar_52446 = (cppVar_52446 & cppMask_un_16_);
	cppVar_52447 = ROM.rd(cppVar_52446);
	cppVar_52449 = (cppVar_52447 == 208);
	if (cppVar_52449) {
	cppVar_52451 = (PSW >> 3) & cppMask_un_2_;
	cppVar_52453 = (cppVar_52451 << 3) | 0;
	cppVar_52453 = (cppVar_52453 & cppMask_un_5_);
	cppVar_52454 = (0 << 5) | cppVar_52453;
	cppVar_52454 = (cppVar_52454 & cppMask_un_8_);
	cppVar_52455 = IRAM.rd(cppVar_52454);
	cppVar_52456 = IRAM.rd(cppVar_52455);
	cppVar_52444 = cppVar_52456;
	} else {
	cppVar_52444 = PSW;
	}
	cppVar_52440 = cppVar_52444;
	} else {
	cppVar_52458 = ROM.rd(PC);
	cppVar_52460 = (cppVar_52458 == 133);
	if (cppVar_52460) {
	cppVar_52463 = PC + 2;
	cppVar_52463 = (cppVar_52463 & cppMask_un_16_);
	cppVar_52464 = ROM.rd(cppVar_52463);
	cppVar_52466 = (cppVar_52464 == 208);
	if (cppVar_52466) {
	cppVar_52469 = PC + 1;
	cppVar_52469 = (cppVar_52469 & cppMask_un_16_);
	cppVar_52470 = ROM.rd(cppVar_52469);
	cppVar_52471 = (cppVar_52470 >> 7) & cppMask_un_1_;
	cppVar_52473 = (cppVar_52471 == 0);
	if (cppVar_52473) {
	cppVar_52474 = PC + 1;
	cppVar_52474 = (cppVar_52474 & cppMask_un_16_);
	cppVar_52475 = ROM.rd(cppVar_52474);
	cppVar_52476 = IRAM.rd(cppVar_52475);
	cppVar_52467 = cppVar_52476;
	} else {
	cppVar_52478 = PC + 1;
	cppVar_52478 = (cppVar_52478 & cppMask_un_16_);
	cppVar_52479 = ROM.rd(cppVar_52478);
	cppVar_52481 = (cppVar_52479 == 128);
	if (cppVar_52481) {
	cppVar_52477 = P0;
	} else {
	cppVar_52483 = PC + 1;
	cppVar_52483 = (cppVar_52483 & cppMask_un_16_);
	cppVar_52484 = ROM.rd(cppVar_52483);
	cppVar_52486 = (cppVar_52484 == 129);
	if (cppVar_52486) {
	cppVar_52482 = SP;
	} else {
	cppVar_52488 = PC + 1;
	cppVar_52488 = (cppVar_52488 & cppMask_un_16_);
	cppVar_52489 = ROM.rd(cppVar_52488);
	cppVar_52491 = (cppVar_52489 == 130);
	if (cppVar_52491) {
	cppVar_52487 = DPL;
	} else {
	cppVar_52493 = PC + 1;
	cppVar_52493 = (cppVar_52493 & cppMask_un_16_);
	cppVar_52494 = ROM.rd(cppVar_52493);
	cppVar_52496 = (cppVar_52494 == 131);
	if (cppVar_52496) {
	cppVar_52492 = DPH;
	} else {
	cppVar_52498 = PC + 1;
	cppVar_52498 = (cppVar_52498 & cppMask_un_16_);
	cppVar_52499 = ROM.rd(cppVar_52498);
	cppVar_52501 = (cppVar_52499 == 135);
	if (cppVar_52501) {
	cppVar_52497 = PCON;
	} else {
	cppVar_52503 = PC + 1;
	cppVar_52503 = (cppVar_52503 & cppMask_un_16_);
	cppVar_52504 = ROM.rd(cppVar_52503);
	cppVar_52506 = (cppVar_52504 == 136);
	if (cppVar_52506) {
	cppVar_52502 = TCON;
	} else {
	cppVar_52508 = PC + 1;
	cppVar_52508 = (cppVar_52508 & cppMask_un_16_);
	cppVar_52509 = ROM.rd(cppVar_52508);
	cppVar_52511 = (cppVar_52509 == 137);
	if (cppVar_52511) {
	cppVar_52507 = TMOD;
	} else {
	cppVar_52513 = PC + 1;
	cppVar_52513 = (cppVar_52513 & cppMask_un_16_);
	cppVar_52514 = ROM.rd(cppVar_52513);
	cppVar_52516 = (cppVar_52514 == 138);
	if (cppVar_52516) {
	cppVar_52512 = TL0;
	} else {
	cppVar_52518 = PC + 1;
	cppVar_52518 = (cppVar_52518 & cppMask_un_16_);
	cppVar_52519 = ROM.rd(cppVar_52518);
	cppVar_52521 = (cppVar_52519 == 140);
	if (cppVar_52521) {
	cppVar_52517 = TH0;
	} else {
	cppVar_52523 = PC + 1;
	cppVar_52523 = (cppVar_52523 & cppMask_un_16_);
	cppVar_52524 = ROM.rd(cppVar_52523);
	cppVar_52526 = (cppVar_52524 == 139);
	if (cppVar_52526) {
	cppVar_52522 = TL1;
	} else {
	cppVar_52528 = PC + 1;
	cppVar_52528 = (cppVar_52528 & cppMask_un_16_);
	cppVar_52529 = ROM.rd(cppVar_52528);
	cppVar_52531 = (cppVar_52529 == 141);
	if (cppVar_52531) {
	cppVar_52527 = TH1;
	} else {
	cppVar_52533 = PC + 1;
	cppVar_52533 = (cppVar_52533 & cppMask_un_16_);
	cppVar_52534 = ROM.rd(cppVar_52533);
	cppVar_52536 = (cppVar_52534 == 144);
	if (cppVar_52536) {
	cppVar_52532 = P1;
	} else {
	cppVar_52538 = PC + 1;
	cppVar_52538 = (cppVar_52538 & cppMask_un_16_);
	cppVar_52539 = ROM.rd(cppVar_52538);
	cppVar_52541 = (cppVar_52539 == 152);
	if (cppVar_52541) {
	cppVar_52537 = SCON;
	} else {
	cppVar_52543 = PC + 1;
	cppVar_52543 = (cppVar_52543 & cppMask_un_16_);
	cppVar_52544 = ROM.rd(cppVar_52543);
	cppVar_52546 = (cppVar_52544 == 153);
	if (cppVar_52546) {
	cppVar_52542 = SBUF;
	} else {
	cppVar_52548 = PC + 1;
	cppVar_52548 = (cppVar_52548 & cppMask_un_16_);
	cppVar_52549 = ROM.rd(cppVar_52548);
	cppVar_52551 = (cppVar_52549 == 160);
	if (cppVar_52551) {
	cppVar_52547 = P2;
	} else {
	cppVar_52553 = PC + 1;
	cppVar_52553 = (cppVar_52553 & cppMask_un_16_);
	cppVar_52554 = ROM.rd(cppVar_52553);
	cppVar_52556 = (cppVar_52554 == 168);
	if (cppVar_52556) {
	cppVar_52552 = IE;
	} else {
	cppVar_52558 = PC + 1;
	cppVar_52558 = (cppVar_52558 & cppMask_un_16_);
	cppVar_52559 = ROM.rd(cppVar_52558);
	cppVar_52561 = (cppVar_52559 == 176);
	if (cppVar_52561) {
	cppVar_52557 = P3;
	} else {
	cppVar_52563 = PC + 1;
	cppVar_52563 = (cppVar_52563 & cppMask_un_16_);
	cppVar_52564 = ROM.rd(cppVar_52563);
	cppVar_52566 = (cppVar_52564 == 184);
	if (cppVar_52566) {
	cppVar_52562 = IP;
	} else {
	cppVar_52568 = PC + 1;
	cppVar_52568 = (cppVar_52568 & cppMask_un_16_);
	cppVar_52569 = ROM.rd(cppVar_52568);
	cppVar_52571 = (cppVar_52569 == 208);
	if (cppVar_52571) {
	cppVar_52567 = PSW;
	} else {
	cppVar_52573 = PC + 1;
	cppVar_52573 = (cppVar_52573 & cppMask_un_16_);
	cppVar_52574 = ROM.rd(cppVar_52573);
	cppVar_52576 = (cppVar_52574 == 224);
	if (cppVar_52576) {
	cppVar_52572 = ACC;
	} else {
	cppVar_52578 = PC + 1;
	cppVar_52578 = (cppVar_52578 & cppMask_un_16_);
	cppVar_52579 = ROM.rd(cppVar_52578);
	cppVar_52581 = (cppVar_52579 == 240);
	if (cppVar_52581) {
	cppVar_52577 = B;
	} else {
	cppVar_52577 = 0;
	}
	cppVar_52572 = cppVar_52577;
	}
	cppVar_52567 = cppVar_52572;
	}
	cppVar_52562 = cppVar_52567;
	}
	cppVar_52557 = cppVar_52562;
	}
	cppVar_52552 = cppVar_52557;
	}
	cppVar_52547 = cppVar_52552;
	}
	cppVar_52542 = cppVar_52547;
	}
	cppVar_52537 = cppVar_52542;
	}
	cppVar_52532 = cppVar_52537;
	}
	cppVar_52527 = cppVar_52532;
	}
	cppVar_52522 = cppVar_52527;
	}
	cppVar_52517 = cppVar_52522;
	}
	cppVar_52512 = cppVar_52517;
	}
	cppVar_52507 = cppVar_52512;
	}
	cppVar_52502 = cppVar_52507;
	}
	cppVar_52497 = cppVar_52502;
	}
	cppVar_52492 = cppVar_52497;
	}
	cppVar_52487 = cppVar_52492;
	}
	cppVar_52482 = cppVar_52487;
	}
	cppVar_52477 = cppVar_52482;
	}
	cppVar_52467 = cppVar_52477;
	}
	cppVar_52461 = cppVar_52467;
	} else {
	cppVar_52461 = PSW;
	}
	cppVar_52457 = cppVar_52461;
	} else {
	cppVar_52584 = ROM.rd(PC);
	cppVar_52586 = (cppVar_52584 == 132);
	if (cppVar_52586) {
	cppVar_52588 = (PSW >> 3) & cppMask_un_4_;
	cppVar_52591 = (B == 0);
	if (cppVar_52591) {
	cppVar_52589 = 1;
	} else {
	cppVar_52589 = 0;
	}
	cppVar_52594 = (PSW >> 0) & cppMask_un_2_;
	cppVar_52595 = (cppVar_52589 << 2) | cppVar_52594;
	cppVar_52595 = (cppVar_52595 & cppMask_un_3_);
	cppVar_52596 = (cppVar_52588 << 3) | cppVar_52595;
	cppVar_52596 = (cppVar_52596 & cppMask_un_7_);
	cppVar_52597 = (0 << 7) | cppVar_52596;
	cppVar_52597 = (cppVar_52597 & cppMask_un_8_);
	cppVar_52583 = cppVar_52597;
	} else {
	cppVar_52599 = ROM.rd(PC);
	cppVar_52601 = (cppVar_52599 == 130);
	if (cppVar_52601) {
	cppVar_52602 = (PSW >> 7) & cppMask_un_1_;
	cppVar_52606 = PC + 1;
	cppVar_52606 = (cppVar_52606 & cppMask_un_16_);
	cppVar_52607 = ROM.rd(cppVar_52606);
	cppVar_52608 = (cppVar_52607 >> 7) & cppMask_un_1_;
	cppVar_52610 = (cppVar_52608 == 1);
	if (cppVar_52610) {
	cppVar_52611 = PC + 1;
	cppVar_52611 = (cppVar_52611 & cppMask_un_16_);
	cppVar_52612 = ROM.rd(cppVar_52611);
	cppVar_52613 = (cppVar_52612 >> 3) & cppMask_un_5_;
	cppVar_52615 = (cppVar_52613 << 3) | 0;
	cppVar_52615 = (cppVar_52615 & cppMask_un_8_);
	cppVar_52604 = cppVar_52615;
	} else {
	cppVar_52616 = PC + 1;
	cppVar_52616 = (cppVar_52616 & cppMask_un_16_);
	cppVar_52617 = ROM.rd(cppVar_52616);
	cppVar_52618 = (cppVar_52617 >> 3) & cppMask_un_5_;
	cppVar_52619 = (cppVar_52618 & cppMask_un_5_);
	cppVar_52621 = cppVar_52619 + 32;
	cppVar_52621 = (cppVar_52621 & cppMask_un_8_);
	cppVar_52604 = cppVar_52621;
	}
	cppVar_52622 = (cppVar_52604 >> 7) & cppMask_un_1_;
	cppVar_52624 = (cppVar_52622 == 0);
	if (cppVar_52624) {
	cppVar_52626 = PC + 1;
	cppVar_52626 = (cppVar_52626 & cppMask_un_16_);
	cppVar_52627 = ROM.rd(cppVar_52626);
	cppVar_52628 = (cppVar_52627 >> 7) & cppMask_un_1_;
	cppVar_52629 = (cppVar_52628 == 1);
	if (cppVar_52629) {
	cppVar_52630 = PC + 1;
	cppVar_52630 = (cppVar_52630 & cppMask_un_16_);
	cppVar_52631 = ROM.rd(cppVar_52630);
	cppVar_52632 = (cppVar_52631 >> 3) & cppMask_un_5_;
	cppVar_52633 = (cppVar_52632 << 3) | 0;
	cppVar_52633 = (cppVar_52633 & cppMask_un_8_);
	cppVar_52625 = cppVar_52633;
	} else {
	cppVar_52634 = PC + 1;
	cppVar_52634 = (cppVar_52634 & cppMask_un_16_);
	cppVar_52635 = ROM.rd(cppVar_52634);
	cppVar_52636 = (cppVar_52635 >> 3) & cppMask_un_5_;
	cppVar_52637 = (cppVar_52636 & cppMask_un_5_);
	cppVar_52638 = cppVar_52637 + 32;
	cppVar_52638 = (cppVar_52638 & cppMask_un_8_);
	cppVar_52625 = cppVar_52638;
	}
	cppVar_52639 = IRAM.rd(cppVar_52625);
	cppVar_52603 = cppVar_52639;
	} else {
	cppVar_52642 = PC + 1;
	cppVar_52642 = (cppVar_52642 & cppMask_un_16_);
	cppVar_52643 = ROM.rd(cppVar_52642);
	cppVar_52644 = (cppVar_52643 >> 7) & cppMask_un_1_;
	cppVar_52645 = (cppVar_52644 == 1);
	if (cppVar_52645) {
	cppVar_52646 = PC + 1;
	cppVar_52646 = (cppVar_52646 & cppMask_un_16_);
	cppVar_52647 = ROM.rd(cppVar_52646);
	cppVar_52648 = (cppVar_52647 >> 3) & cppMask_un_5_;
	cppVar_52649 = (cppVar_52648 << 3) | 0;
	cppVar_52649 = (cppVar_52649 & cppMask_un_8_);
	cppVar_52641 = cppVar_52649;
	} else {
	cppVar_52650 = PC + 1;
	cppVar_52650 = (cppVar_52650 & cppMask_un_16_);
	cppVar_52651 = ROM.rd(cppVar_52650);
	cppVar_52652 = (cppVar_52651 >> 3) & cppMask_un_5_;
	cppVar_52653 = (cppVar_52652 & cppMask_un_5_);
	cppVar_52654 = cppVar_52653 + 32;
	cppVar_52654 = (cppVar_52654 & cppMask_un_8_);
	cppVar_52641 = cppVar_52654;
	}
	cppVar_52656 = (cppVar_52641 == 128);
	if (cppVar_52656) {
	cppVar_52640 = P0;
	} else {
	cppVar_52659 = PC + 1;
	cppVar_52659 = (cppVar_52659 & cppMask_un_16_);
	cppVar_52660 = ROM.rd(cppVar_52659);
	cppVar_52661 = (cppVar_52660 >> 7) & cppMask_un_1_;
	cppVar_52662 = (cppVar_52661 == 1);
	if (cppVar_52662) {
	cppVar_52663 = PC + 1;
	cppVar_52663 = (cppVar_52663 & cppMask_un_16_);
	cppVar_52664 = ROM.rd(cppVar_52663);
	cppVar_52665 = (cppVar_52664 >> 3) & cppMask_un_5_;
	cppVar_52666 = (cppVar_52665 << 3) | 0;
	cppVar_52666 = (cppVar_52666 & cppMask_un_8_);
	cppVar_52658 = cppVar_52666;
	} else {
	cppVar_52667 = PC + 1;
	cppVar_52667 = (cppVar_52667 & cppMask_un_16_);
	cppVar_52668 = ROM.rd(cppVar_52667);
	cppVar_52669 = (cppVar_52668 >> 3) & cppMask_un_5_;
	cppVar_52670 = (cppVar_52669 & cppMask_un_5_);
	cppVar_52671 = cppVar_52670 + 32;
	cppVar_52671 = (cppVar_52671 & cppMask_un_8_);
	cppVar_52658 = cppVar_52671;
	}
	cppVar_52673 = (cppVar_52658 == 129);
	if (cppVar_52673) {
	cppVar_52657 = SP;
	} else {
	cppVar_52676 = PC + 1;
	cppVar_52676 = (cppVar_52676 & cppMask_un_16_);
	cppVar_52677 = ROM.rd(cppVar_52676);
	cppVar_52678 = (cppVar_52677 >> 7) & cppMask_un_1_;
	cppVar_52679 = (cppVar_52678 == 1);
	if (cppVar_52679) {
	cppVar_52680 = PC + 1;
	cppVar_52680 = (cppVar_52680 & cppMask_un_16_);
	cppVar_52681 = ROM.rd(cppVar_52680);
	cppVar_52682 = (cppVar_52681 >> 3) & cppMask_un_5_;
	cppVar_52683 = (cppVar_52682 << 3) | 0;
	cppVar_52683 = (cppVar_52683 & cppMask_un_8_);
	cppVar_52675 = cppVar_52683;
	} else {
	cppVar_52684 = PC + 1;
	cppVar_52684 = (cppVar_52684 & cppMask_un_16_);
	cppVar_52685 = ROM.rd(cppVar_52684);
	cppVar_52686 = (cppVar_52685 >> 3) & cppMask_un_5_;
	cppVar_52687 = (cppVar_52686 & cppMask_un_5_);
	cppVar_52688 = cppVar_52687 + 32;
	cppVar_52688 = (cppVar_52688 & cppMask_un_8_);
	cppVar_52675 = cppVar_52688;
	}
	cppVar_52690 = (cppVar_52675 == 130);
	if (cppVar_52690) {
	cppVar_52674 = DPL;
	} else {
	cppVar_52693 = PC + 1;
	cppVar_52693 = (cppVar_52693 & cppMask_un_16_);
	cppVar_52694 = ROM.rd(cppVar_52693);
	cppVar_52695 = (cppVar_52694 >> 7) & cppMask_un_1_;
	cppVar_52696 = (cppVar_52695 == 1);
	if (cppVar_52696) {
	cppVar_52697 = PC + 1;
	cppVar_52697 = (cppVar_52697 & cppMask_un_16_);
	cppVar_52698 = ROM.rd(cppVar_52697);
	cppVar_52699 = (cppVar_52698 >> 3) & cppMask_un_5_;
	cppVar_52700 = (cppVar_52699 << 3) | 0;
	cppVar_52700 = (cppVar_52700 & cppMask_un_8_);
	cppVar_52692 = cppVar_52700;
	} else {
	cppVar_52701 = PC + 1;
	cppVar_52701 = (cppVar_52701 & cppMask_un_16_);
	cppVar_52702 = ROM.rd(cppVar_52701);
	cppVar_52703 = (cppVar_52702 >> 3) & cppMask_un_5_;
	cppVar_52704 = (cppVar_52703 & cppMask_un_5_);
	cppVar_52705 = cppVar_52704 + 32;
	cppVar_52705 = (cppVar_52705 & cppMask_un_8_);
	cppVar_52692 = cppVar_52705;
	}
	cppVar_52707 = (cppVar_52692 == 131);
	if (cppVar_52707) {
	cppVar_52691 = DPH;
	} else {
	cppVar_52710 = PC + 1;
	cppVar_52710 = (cppVar_52710 & cppMask_un_16_);
	cppVar_52711 = ROM.rd(cppVar_52710);
	cppVar_52712 = (cppVar_52711 >> 7) & cppMask_un_1_;
	cppVar_52713 = (cppVar_52712 == 1);
	if (cppVar_52713) {
	cppVar_52714 = PC + 1;
	cppVar_52714 = (cppVar_52714 & cppMask_un_16_);
	cppVar_52715 = ROM.rd(cppVar_52714);
	cppVar_52716 = (cppVar_52715 >> 3) & cppMask_un_5_;
	cppVar_52717 = (cppVar_52716 << 3) | 0;
	cppVar_52717 = (cppVar_52717 & cppMask_un_8_);
	cppVar_52709 = cppVar_52717;
	} else {
	cppVar_52718 = PC + 1;
	cppVar_52718 = (cppVar_52718 & cppMask_un_16_);
	cppVar_52719 = ROM.rd(cppVar_52718);
	cppVar_52720 = (cppVar_52719 >> 3) & cppMask_un_5_;
	cppVar_52721 = (cppVar_52720 & cppMask_un_5_);
	cppVar_52722 = cppVar_52721 + 32;
	cppVar_52722 = (cppVar_52722 & cppMask_un_8_);
	cppVar_52709 = cppVar_52722;
	}
	cppVar_52724 = (cppVar_52709 == 135);
	if (cppVar_52724) {
	cppVar_52708 = PCON;
	} else {
	cppVar_52727 = PC + 1;
	cppVar_52727 = (cppVar_52727 & cppMask_un_16_);
	cppVar_52728 = ROM.rd(cppVar_52727);
	cppVar_52729 = (cppVar_52728 >> 7) & cppMask_un_1_;
	cppVar_52730 = (cppVar_52729 == 1);
	if (cppVar_52730) {
	cppVar_52731 = PC + 1;
	cppVar_52731 = (cppVar_52731 & cppMask_un_16_);
	cppVar_52732 = ROM.rd(cppVar_52731);
	cppVar_52733 = (cppVar_52732 >> 3) & cppMask_un_5_;
	cppVar_52734 = (cppVar_52733 << 3) | 0;
	cppVar_52734 = (cppVar_52734 & cppMask_un_8_);
	cppVar_52726 = cppVar_52734;
	} else {
	cppVar_52735 = PC + 1;
	cppVar_52735 = (cppVar_52735 & cppMask_un_16_);
	cppVar_52736 = ROM.rd(cppVar_52735);
	cppVar_52737 = (cppVar_52736 >> 3) & cppMask_un_5_;
	cppVar_52738 = (cppVar_52737 & cppMask_un_5_);
	cppVar_52739 = cppVar_52738 + 32;
	cppVar_52739 = (cppVar_52739 & cppMask_un_8_);
	cppVar_52726 = cppVar_52739;
	}
	cppVar_52741 = (cppVar_52726 == 136);
	if (cppVar_52741) {
	cppVar_52725 = TCON;
	} else {
	cppVar_52744 = PC + 1;
	cppVar_52744 = (cppVar_52744 & cppMask_un_16_);
	cppVar_52745 = ROM.rd(cppVar_52744);
	cppVar_52746 = (cppVar_52745 >> 7) & cppMask_un_1_;
	cppVar_52747 = (cppVar_52746 == 1);
	if (cppVar_52747) {
	cppVar_52748 = PC + 1;
	cppVar_52748 = (cppVar_52748 & cppMask_un_16_);
	cppVar_52749 = ROM.rd(cppVar_52748);
	cppVar_52750 = (cppVar_52749 >> 3) & cppMask_un_5_;
	cppVar_52751 = (cppVar_52750 << 3) | 0;
	cppVar_52751 = (cppVar_52751 & cppMask_un_8_);
	cppVar_52743 = cppVar_52751;
	} else {
	cppVar_52752 = PC + 1;
	cppVar_52752 = (cppVar_52752 & cppMask_un_16_);
	cppVar_52753 = ROM.rd(cppVar_52752);
	cppVar_52754 = (cppVar_52753 >> 3) & cppMask_un_5_;
	cppVar_52755 = (cppVar_52754 & cppMask_un_5_);
	cppVar_52756 = cppVar_52755 + 32;
	cppVar_52756 = (cppVar_52756 & cppMask_un_8_);
	cppVar_52743 = cppVar_52756;
	}
	cppVar_52758 = (cppVar_52743 == 137);
	if (cppVar_52758) {
	cppVar_52742 = TMOD;
	} else {
	cppVar_52761 = PC + 1;
	cppVar_52761 = (cppVar_52761 & cppMask_un_16_);
	cppVar_52762 = ROM.rd(cppVar_52761);
	cppVar_52763 = (cppVar_52762 >> 7) & cppMask_un_1_;
	cppVar_52764 = (cppVar_52763 == 1);
	if (cppVar_52764) {
	cppVar_52765 = PC + 1;
	cppVar_52765 = (cppVar_52765 & cppMask_un_16_);
	cppVar_52766 = ROM.rd(cppVar_52765);
	cppVar_52767 = (cppVar_52766 >> 3) & cppMask_un_5_;
	cppVar_52768 = (cppVar_52767 << 3) | 0;
	cppVar_52768 = (cppVar_52768 & cppMask_un_8_);
	cppVar_52760 = cppVar_52768;
	} else {
	cppVar_52769 = PC + 1;
	cppVar_52769 = (cppVar_52769 & cppMask_un_16_);
	cppVar_52770 = ROM.rd(cppVar_52769);
	cppVar_52771 = (cppVar_52770 >> 3) & cppMask_un_5_;
	cppVar_52772 = (cppVar_52771 & cppMask_un_5_);
	cppVar_52773 = cppVar_52772 + 32;
	cppVar_52773 = (cppVar_52773 & cppMask_un_8_);
	cppVar_52760 = cppVar_52773;
	}
	cppVar_52775 = (cppVar_52760 == 138);
	if (cppVar_52775) {
	cppVar_52759 = TL0;
	} else {
	cppVar_52778 = PC + 1;
	cppVar_52778 = (cppVar_52778 & cppMask_un_16_);
	cppVar_52779 = ROM.rd(cppVar_52778);
	cppVar_52780 = (cppVar_52779 >> 7) & cppMask_un_1_;
	cppVar_52781 = (cppVar_52780 == 1);
	if (cppVar_52781) {
	cppVar_52782 = PC + 1;
	cppVar_52782 = (cppVar_52782 & cppMask_un_16_);
	cppVar_52783 = ROM.rd(cppVar_52782);
	cppVar_52784 = (cppVar_52783 >> 3) & cppMask_un_5_;
	cppVar_52785 = (cppVar_52784 << 3) | 0;
	cppVar_52785 = (cppVar_52785 & cppMask_un_8_);
	cppVar_52777 = cppVar_52785;
	} else {
	cppVar_52786 = PC + 1;
	cppVar_52786 = (cppVar_52786 & cppMask_un_16_);
	cppVar_52787 = ROM.rd(cppVar_52786);
	cppVar_52788 = (cppVar_52787 >> 3) & cppMask_un_5_;
	cppVar_52789 = (cppVar_52788 & cppMask_un_5_);
	cppVar_52790 = cppVar_52789 + 32;
	cppVar_52790 = (cppVar_52790 & cppMask_un_8_);
	cppVar_52777 = cppVar_52790;
	}
	cppVar_52792 = (cppVar_52777 == 140);
	if (cppVar_52792) {
	cppVar_52776 = TH0;
	} else {
	cppVar_52795 = PC + 1;
	cppVar_52795 = (cppVar_52795 & cppMask_un_16_);
	cppVar_52796 = ROM.rd(cppVar_52795);
	cppVar_52797 = (cppVar_52796 >> 7) & cppMask_un_1_;
	cppVar_52798 = (cppVar_52797 == 1);
	if (cppVar_52798) {
	cppVar_52799 = PC + 1;
	cppVar_52799 = (cppVar_52799 & cppMask_un_16_);
	cppVar_52800 = ROM.rd(cppVar_52799);
	cppVar_52801 = (cppVar_52800 >> 3) & cppMask_un_5_;
	cppVar_52802 = (cppVar_52801 << 3) | 0;
	cppVar_52802 = (cppVar_52802 & cppMask_un_8_);
	cppVar_52794 = cppVar_52802;
	} else {
	cppVar_52803 = PC + 1;
	cppVar_52803 = (cppVar_52803 & cppMask_un_16_);
	cppVar_52804 = ROM.rd(cppVar_52803);
	cppVar_52805 = (cppVar_52804 >> 3) & cppMask_un_5_;
	cppVar_52806 = (cppVar_52805 & cppMask_un_5_);
	cppVar_52807 = cppVar_52806 + 32;
	cppVar_52807 = (cppVar_52807 & cppMask_un_8_);
	cppVar_52794 = cppVar_52807;
	}
	cppVar_52809 = (cppVar_52794 == 139);
	if (cppVar_52809) {
	cppVar_52793 = TL1;
	} else {
	cppVar_52812 = PC + 1;
	cppVar_52812 = (cppVar_52812 & cppMask_un_16_);
	cppVar_52813 = ROM.rd(cppVar_52812);
	cppVar_52814 = (cppVar_52813 >> 7) & cppMask_un_1_;
	cppVar_52815 = (cppVar_52814 == 1);
	if (cppVar_52815) {
	cppVar_52816 = PC + 1;
	cppVar_52816 = (cppVar_52816 & cppMask_un_16_);
	cppVar_52817 = ROM.rd(cppVar_52816);
	cppVar_52818 = (cppVar_52817 >> 3) & cppMask_un_5_;
	cppVar_52819 = (cppVar_52818 << 3) | 0;
	cppVar_52819 = (cppVar_52819 & cppMask_un_8_);
	cppVar_52811 = cppVar_52819;
	} else {
	cppVar_52820 = PC + 1;
	cppVar_52820 = (cppVar_52820 & cppMask_un_16_);
	cppVar_52821 = ROM.rd(cppVar_52820);
	cppVar_52822 = (cppVar_52821 >> 3) & cppMask_un_5_;
	cppVar_52823 = (cppVar_52822 & cppMask_un_5_);
	cppVar_52824 = cppVar_52823 + 32;
	cppVar_52824 = (cppVar_52824 & cppMask_un_8_);
	cppVar_52811 = cppVar_52824;
	}
	cppVar_52826 = (cppVar_52811 == 141);
	if (cppVar_52826) {
	cppVar_52810 = TH1;
	} else {
	cppVar_52829 = PC + 1;
	cppVar_52829 = (cppVar_52829 & cppMask_un_16_);
	cppVar_52830 = ROM.rd(cppVar_52829);
	cppVar_52831 = (cppVar_52830 >> 7) & cppMask_un_1_;
	cppVar_52832 = (cppVar_52831 == 1);
	if (cppVar_52832) {
	cppVar_52833 = PC + 1;
	cppVar_52833 = (cppVar_52833 & cppMask_un_16_);
	cppVar_52834 = ROM.rd(cppVar_52833);
	cppVar_52835 = (cppVar_52834 >> 3) & cppMask_un_5_;
	cppVar_52836 = (cppVar_52835 << 3) | 0;
	cppVar_52836 = (cppVar_52836 & cppMask_un_8_);
	cppVar_52828 = cppVar_52836;
	} else {
	cppVar_52837 = PC + 1;
	cppVar_52837 = (cppVar_52837 & cppMask_un_16_);
	cppVar_52838 = ROM.rd(cppVar_52837);
	cppVar_52839 = (cppVar_52838 >> 3) & cppMask_un_5_;
	cppVar_52840 = (cppVar_52839 & cppMask_un_5_);
	cppVar_52841 = cppVar_52840 + 32;
	cppVar_52841 = (cppVar_52841 & cppMask_un_8_);
	cppVar_52828 = cppVar_52841;
	}
	cppVar_52843 = (cppVar_52828 == 144);
	if (cppVar_52843) {
	cppVar_52827 = P1;
	} else {
	cppVar_52846 = PC + 1;
	cppVar_52846 = (cppVar_52846 & cppMask_un_16_);
	cppVar_52847 = ROM.rd(cppVar_52846);
	cppVar_52848 = (cppVar_52847 >> 7) & cppMask_un_1_;
	cppVar_52849 = (cppVar_52848 == 1);
	if (cppVar_52849) {
	cppVar_52850 = PC + 1;
	cppVar_52850 = (cppVar_52850 & cppMask_un_16_);
	cppVar_52851 = ROM.rd(cppVar_52850);
	cppVar_52852 = (cppVar_52851 >> 3) & cppMask_un_5_;
	cppVar_52853 = (cppVar_52852 << 3) | 0;
	cppVar_52853 = (cppVar_52853 & cppMask_un_8_);
	cppVar_52845 = cppVar_52853;
	} else {
	cppVar_52854 = PC + 1;
	cppVar_52854 = (cppVar_52854 & cppMask_un_16_);
	cppVar_52855 = ROM.rd(cppVar_52854);
	cppVar_52856 = (cppVar_52855 >> 3) & cppMask_un_5_;
	cppVar_52857 = (cppVar_52856 & cppMask_un_5_);
	cppVar_52858 = cppVar_52857 + 32;
	cppVar_52858 = (cppVar_52858 & cppMask_un_8_);
	cppVar_52845 = cppVar_52858;
	}
	cppVar_52860 = (cppVar_52845 == 152);
	if (cppVar_52860) {
	cppVar_52844 = SCON;
	} else {
	cppVar_52863 = PC + 1;
	cppVar_52863 = (cppVar_52863 & cppMask_un_16_);
	cppVar_52864 = ROM.rd(cppVar_52863);
	cppVar_52865 = (cppVar_52864 >> 7) & cppMask_un_1_;
	cppVar_52866 = (cppVar_52865 == 1);
	if (cppVar_52866) {
	cppVar_52867 = PC + 1;
	cppVar_52867 = (cppVar_52867 & cppMask_un_16_);
	cppVar_52868 = ROM.rd(cppVar_52867);
	cppVar_52869 = (cppVar_52868 >> 3) & cppMask_un_5_;
	cppVar_52870 = (cppVar_52869 << 3) | 0;
	cppVar_52870 = (cppVar_52870 & cppMask_un_8_);
	cppVar_52862 = cppVar_52870;
	} else {
	cppVar_52871 = PC + 1;
	cppVar_52871 = (cppVar_52871 & cppMask_un_16_);
	cppVar_52872 = ROM.rd(cppVar_52871);
	cppVar_52873 = (cppVar_52872 >> 3) & cppMask_un_5_;
	cppVar_52874 = (cppVar_52873 & cppMask_un_5_);
	cppVar_52875 = cppVar_52874 + 32;
	cppVar_52875 = (cppVar_52875 & cppMask_un_8_);
	cppVar_52862 = cppVar_52875;
	}
	cppVar_52877 = (cppVar_52862 == 153);
	if (cppVar_52877) {
	cppVar_52861 = SBUF;
	} else {
	cppVar_52880 = PC + 1;
	cppVar_52880 = (cppVar_52880 & cppMask_un_16_);
	cppVar_52881 = ROM.rd(cppVar_52880);
	cppVar_52882 = (cppVar_52881 >> 7) & cppMask_un_1_;
	cppVar_52883 = (cppVar_52882 == 1);
	if (cppVar_52883) {
	cppVar_52884 = PC + 1;
	cppVar_52884 = (cppVar_52884 & cppMask_un_16_);
	cppVar_52885 = ROM.rd(cppVar_52884);
	cppVar_52886 = (cppVar_52885 >> 3) & cppMask_un_5_;
	cppVar_52887 = (cppVar_52886 << 3) | 0;
	cppVar_52887 = (cppVar_52887 & cppMask_un_8_);
	cppVar_52879 = cppVar_52887;
	} else {
	cppVar_52888 = PC + 1;
	cppVar_52888 = (cppVar_52888 & cppMask_un_16_);
	cppVar_52889 = ROM.rd(cppVar_52888);
	cppVar_52890 = (cppVar_52889 >> 3) & cppMask_un_5_;
	cppVar_52891 = (cppVar_52890 & cppMask_un_5_);
	cppVar_52892 = cppVar_52891 + 32;
	cppVar_52892 = (cppVar_52892 & cppMask_un_8_);
	cppVar_52879 = cppVar_52892;
	}
	cppVar_52894 = (cppVar_52879 == 160);
	if (cppVar_52894) {
	cppVar_52878 = P2;
	} else {
	cppVar_52897 = PC + 1;
	cppVar_52897 = (cppVar_52897 & cppMask_un_16_);
	cppVar_52898 = ROM.rd(cppVar_52897);
	cppVar_52899 = (cppVar_52898 >> 7) & cppMask_un_1_;
	cppVar_52900 = (cppVar_52899 == 1);
	if (cppVar_52900) {
	cppVar_52901 = PC + 1;
	cppVar_52901 = (cppVar_52901 & cppMask_un_16_);
	cppVar_52902 = ROM.rd(cppVar_52901);
	cppVar_52903 = (cppVar_52902 >> 3) & cppMask_un_5_;
	cppVar_52904 = (cppVar_52903 << 3) | 0;
	cppVar_52904 = (cppVar_52904 & cppMask_un_8_);
	cppVar_52896 = cppVar_52904;
	} else {
	cppVar_52905 = PC + 1;
	cppVar_52905 = (cppVar_52905 & cppMask_un_16_);
	cppVar_52906 = ROM.rd(cppVar_52905);
	cppVar_52907 = (cppVar_52906 >> 3) & cppMask_un_5_;
	cppVar_52908 = (cppVar_52907 & cppMask_un_5_);
	cppVar_52909 = cppVar_52908 + 32;
	cppVar_52909 = (cppVar_52909 & cppMask_un_8_);
	cppVar_52896 = cppVar_52909;
	}
	cppVar_52911 = (cppVar_52896 == 168);
	if (cppVar_52911) {
	cppVar_52895 = IE;
	} else {
	cppVar_52914 = PC + 1;
	cppVar_52914 = (cppVar_52914 & cppMask_un_16_);
	cppVar_52915 = ROM.rd(cppVar_52914);
	cppVar_52916 = (cppVar_52915 >> 7) & cppMask_un_1_;
	cppVar_52917 = (cppVar_52916 == 1);
	if (cppVar_52917) {
	cppVar_52918 = PC + 1;
	cppVar_52918 = (cppVar_52918 & cppMask_un_16_);
	cppVar_52919 = ROM.rd(cppVar_52918);
	cppVar_52920 = (cppVar_52919 >> 3) & cppMask_un_5_;
	cppVar_52921 = (cppVar_52920 << 3) | 0;
	cppVar_52921 = (cppVar_52921 & cppMask_un_8_);
	cppVar_52913 = cppVar_52921;
	} else {
	cppVar_52922 = PC + 1;
	cppVar_52922 = (cppVar_52922 & cppMask_un_16_);
	cppVar_52923 = ROM.rd(cppVar_52922);
	cppVar_52924 = (cppVar_52923 >> 3) & cppMask_un_5_;
	cppVar_52925 = (cppVar_52924 & cppMask_un_5_);
	cppVar_52926 = cppVar_52925 + 32;
	cppVar_52926 = (cppVar_52926 & cppMask_un_8_);
	cppVar_52913 = cppVar_52926;
	}
	cppVar_52928 = (cppVar_52913 == 176);
	if (cppVar_52928) {
	cppVar_52912 = P3;
	} else {
	cppVar_52931 = PC + 1;
	cppVar_52931 = (cppVar_52931 & cppMask_un_16_);
	cppVar_52932 = ROM.rd(cppVar_52931);
	cppVar_52933 = (cppVar_52932 >> 7) & cppMask_un_1_;
	cppVar_52934 = (cppVar_52933 == 1);
	if (cppVar_52934) {
	cppVar_52935 = PC + 1;
	cppVar_52935 = (cppVar_52935 & cppMask_un_16_);
	cppVar_52936 = ROM.rd(cppVar_52935);
	cppVar_52937 = (cppVar_52936 >> 3) & cppMask_un_5_;
	cppVar_52938 = (cppVar_52937 << 3) | 0;
	cppVar_52938 = (cppVar_52938 & cppMask_un_8_);
	cppVar_52930 = cppVar_52938;
	} else {
	cppVar_52939 = PC + 1;
	cppVar_52939 = (cppVar_52939 & cppMask_un_16_);
	cppVar_52940 = ROM.rd(cppVar_52939);
	cppVar_52941 = (cppVar_52940 >> 3) & cppMask_un_5_;
	cppVar_52942 = (cppVar_52941 & cppMask_un_5_);
	cppVar_52943 = cppVar_52942 + 32;
	cppVar_52943 = (cppVar_52943 & cppMask_un_8_);
	cppVar_52930 = cppVar_52943;
	}
	cppVar_52945 = (cppVar_52930 == 184);
	if (cppVar_52945) {
	cppVar_52929 = IP;
	} else {
	cppVar_52948 = PC + 1;
	cppVar_52948 = (cppVar_52948 & cppMask_un_16_);
	cppVar_52949 = ROM.rd(cppVar_52948);
	cppVar_52950 = (cppVar_52949 >> 7) & cppMask_un_1_;
	cppVar_52951 = (cppVar_52950 == 1);
	if (cppVar_52951) {
	cppVar_52952 = PC + 1;
	cppVar_52952 = (cppVar_52952 & cppMask_un_16_);
	cppVar_52953 = ROM.rd(cppVar_52952);
	cppVar_52954 = (cppVar_52953 >> 3) & cppMask_un_5_;
	cppVar_52955 = (cppVar_52954 << 3) | 0;
	cppVar_52955 = (cppVar_52955 & cppMask_un_8_);
	cppVar_52947 = cppVar_52955;
	} else {
	cppVar_52956 = PC + 1;
	cppVar_52956 = (cppVar_52956 & cppMask_un_16_);
	cppVar_52957 = ROM.rd(cppVar_52956);
	cppVar_52958 = (cppVar_52957 >> 3) & cppMask_un_5_;
	cppVar_52959 = (cppVar_52958 & cppMask_un_5_);
	cppVar_52960 = cppVar_52959 + 32;
	cppVar_52960 = (cppVar_52960 & cppMask_un_8_);
	cppVar_52947 = cppVar_52960;
	}
	cppVar_52962 = (cppVar_52947 == 208);
	if (cppVar_52962) {
	cppVar_52946 = PSW;
	} else {
	cppVar_52965 = PC + 1;
	cppVar_52965 = (cppVar_52965 & cppMask_un_16_);
	cppVar_52966 = ROM.rd(cppVar_52965);
	cppVar_52967 = (cppVar_52966 >> 7) & cppMask_un_1_;
	cppVar_52968 = (cppVar_52967 == 1);
	if (cppVar_52968) {
	cppVar_52969 = PC + 1;
	cppVar_52969 = (cppVar_52969 & cppMask_un_16_);
	cppVar_52970 = ROM.rd(cppVar_52969);
	cppVar_52971 = (cppVar_52970 >> 3) & cppMask_un_5_;
	cppVar_52972 = (cppVar_52971 << 3) | 0;
	cppVar_52972 = (cppVar_52972 & cppMask_un_8_);
	cppVar_52964 = cppVar_52972;
	} else {
	cppVar_52973 = PC + 1;
	cppVar_52973 = (cppVar_52973 & cppMask_un_16_);
	cppVar_52974 = ROM.rd(cppVar_52973);
	cppVar_52975 = (cppVar_52974 >> 3) & cppMask_un_5_;
	cppVar_52976 = (cppVar_52975 & cppMask_un_5_);
	cppVar_52977 = cppVar_52976 + 32;
	cppVar_52977 = (cppVar_52977 & cppMask_un_8_);
	cppVar_52964 = cppVar_52977;
	}
	cppVar_52979 = (cppVar_52964 == 224);
	if (cppVar_52979) {
	cppVar_52963 = ACC;
	} else {
	cppVar_52982 = PC + 1;
	cppVar_52982 = (cppVar_52982 & cppMask_un_16_);
	cppVar_52983 = ROM.rd(cppVar_52982);
	cppVar_52984 = (cppVar_52983 >> 7) & cppMask_un_1_;
	cppVar_52985 = (cppVar_52984 == 1);
	if (cppVar_52985) {
	cppVar_52986 = PC + 1;
	cppVar_52986 = (cppVar_52986 & cppMask_un_16_);
	cppVar_52987 = ROM.rd(cppVar_52986);
	cppVar_52988 = (cppVar_52987 >> 3) & cppMask_un_5_;
	cppVar_52989 = (cppVar_52988 << 3) | 0;
	cppVar_52989 = (cppVar_52989 & cppMask_un_8_);
	cppVar_52981 = cppVar_52989;
	} else {
	cppVar_52990 = PC + 1;
	cppVar_52990 = (cppVar_52990 & cppMask_un_16_);
	cppVar_52991 = ROM.rd(cppVar_52990);
	cppVar_52992 = (cppVar_52991 >> 3) & cppMask_un_5_;
	cppVar_52993 = (cppVar_52992 & cppMask_un_5_);
	cppVar_52994 = cppVar_52993 + 32;
	cppVar_52994 = (cppVar_52994 & cppMask_un_8_);
	cppVar_52981 = cppVar_52994;
	}
	cppVar_52996 = (cppVar_52981 == 240);
	if (cppVar_52996) {
	cppVar_52980 = B;
	} else {
	cppVar_52980 = 0;
	}
	cppVar_52963 = cppVar_52980;
	}
	cppVar_52946 = cppVar_52963;
	}
	cppVar_52929 = cppVar_52946;
	}
	cppVar_52912 = cppVar_52929;
	}
	cppVar_52895 = cppVar_52912;
	}
	cppVar_52878 = cppVar_52895;
	}
	cppVar_52861 = cppVar_52878;
	}
	cppVar_52844 = cppVar_52861;
	}
	cppVar_52827 = cppVar_52844;
	}
	cppVar_52810 = cppVar_52827;
	}
	cppVar_52793 = cppVar_52810;
	}
	cppVar_52776 = cppVar_52793;
	}
	cppVar_52759 = cppVar_52776;
	}
	cppVar_52742 = cppVar_52759;
	}
	cppVar_52725 = cppVar_52742;
	}
	cppVar_52708 = cppVar_52725;
	}
	cppVar_52691 = cppVar_52708;
	}
	cppVar_52674 = cppVar_52691;
	}
	cppVar_52657 = cppVar_52674;
	}
	cppVar_52640 = cppVar_52657;
	}
	cppVar_52603 = cppVar_52640;
	}
	cppVar_52998 = PC + 1;
	cppVar_52998 = (cppVar_52998 & cppMask_un_16_);
	cppVar_52999 = ROM.rd(cppVar_52998);
	cppVar_53000 = (cppVar_52999 >> 0) & cppMask_un_3_;
	cppVar_53001 = (cppVar_52603 >> static_cast<unsigned>(cppVar_53000)) & 0x1;
	cppVar_53002 = cppVar_52602 & cppVar_53001;
	cppVar_53003 = (PSW >> 0) & cppMask_un_7_;
	cppVar_53004 = (cppVar_53002 << 7) | cppVar_53003;
	cppVar_53004 = (cppVar_53004 & cppMask_un_8_);
	cppVar_52598 = cppVar_53004;
	} else {
	cppVar_53006 = ROM.rd(PC);
	cppVar_53008 = (cppVar_53006 == 117);
	if (cppVar_53008) {
	cppVar_53011 = PC + 1;
	cppVar_53011 = (cppVar_53011 & cppMask_un_16_);
	cppVar_53012 = ROM.rd(cppVar_53011);
	cppVar_53014 = (cppVar_53012 == 208);
	if (cppVar_53014) {
	cppVar_53016 = PC + 2;
	cppVar_53016 = (cppVar_53016 & cppMask_un_16_);
	cppVar_53017 = ROM.rd(cppVar_53016);
	cppVar_53009 = cppVar_53017;
	} else {
	cppVar_53009 = PSW;
	}
	cppVar_53005 = cppVar_53009;
	} else {
	cppVar_53019 = ROM.rd(PC);
	cppVar_53021 = (cppVar_53019 == 114);
	if (cppVar_53021) {
	cppVar_53022 = (PSW >> 7) & cppMask_un_1_;
	cppVar_53026 = PC + 1;
	cppVar_53026 = (cppVar_53026 & cppMask_un_16_);
	cppVar_53027 = ROM.rd(cppVar_53026);
	cppVar_53028 = (cppVar_53027 >> 7) & cppMask_un_1_;
	cppVar_53030 = (cppVar_53028 == 1);
	if (cppVar_53030) {
	cppVar_53031 = PC + 1;
	cppVar_53031 = (cppVar_53031 & cppMask_un_16_);
	cppVar_53032 = ROM.rd(cppVar_53031);
	cppVar_53033 = (cppVar_53032 >> 3) & cppMask_un_5_;
	cppVar_53035 = (cppVar_53033 << 3) | 0;
	cppVar_53035 = (cppVar_53035 & cppMask_un_8_);
	cppVar_53024 = cppVar_53035;
	} else {
	cppVar_53036 = PC + 1;
	cppVar_53036 = (cppVar_53036 & cppMask_un_16_);
	cppVar_53037 = ROM.rd(cppVar_53036);
	cppVar_53038 = (cppVar_53037 >> 3) & cppMask_un_5_;
	cppVar_53039 = (cppVar_53038 & cppMask_un_5_);
	cppVar_53041 = cppVar_53039 + 32;
	cppVar_53041 = (cppVar_53041 & cppMask_un_8_);
	cppVar_53024 = cppVar_53041;
	}
	cppVar_53042 = (cppVar_53024 >> 7) & cppMask_un_1_;
	cppVar_53044 = (cppVar_53042 == 0);
	if (cppVar_53044) {
	cppVar_53046 = PC + 1;
	cppVar_53046 = (cppVar_53046 & cppMask_un_16_);
	cppVar_53047 = ROM.rd(cppVar_53046);
	cppVar_53048 = (cppVar_53047 >> 7) & cppMask_un_1_;
	cppVar_53049 = (cppVar_53048 == 1);
	if (cppVar_53049) {
	cppVar_53050 = PC + 1;
	cppVar_53050 = (cppVar_53050 & cppMask_un_16_);
	cppVar_53051 = ROM.rd(cppVar_53050);
	cppVar_53052 = (cppVar_53051 >> 3) & cppMask_un_5_;
	cppVar_53053 = (cppVar_53052 << 3) | 0;
	cppVar_53053 = (cppVar_53053 & cppMask_un_8_);
	cppVar_53045 = cppVar_53053;
	} else {
	cppVar_53054 = PC + 1;
	cppVar_53054 = (cppVar_53054 & cppMask_un_16_);
	cppVar_53055 = ROM.rd(cppVar_53054);
	cppVar_53056 = (cppVar_53055 >> 3) & cppMask_un_5_;
	cppVar_53057 = (cppVar_53056 & cppMask_un_5_);
	cppVar_53058 = cppVar_53057 + 32;
	cppVar_53058 = (cppVar_53058 & cppMask_un_8_);
	cppVar_53045 = cppVar_53058;
	}
	cppVar_53059 = IRAM.rd(cppVar_53045);
	cppVar_53023 = cppVar_53059;
	} else {
	cppVar_53062 = PC + 1;
	cppVar_53062 = (cppVar_53062 & cppMask_un_16_);
	cppVar_53063 = ROM.rd(cppVar_53062);
	cppVar_53064 = (cppVar_53063 >> 7) & cppMask_un_1_;
	cppVar_53065 = (cppVar_53064 == 1);
	if (cppVar_53065) {
	cppVar_53066 = PC + 1;
	cppVar_53066 = (cppVar_53066 & cppMask_un_16_);
	cppVar_53067 = ROM.rd(cppVar_53066);
	cppVar_53068 = (cppVar_53067 >> 3) & cppMask_un_5_;
	cppVar_53069 = (cppVar_53068 << 3) | 0;
	cppVar_53069 = (cppVar_53069 & cppMask_un_8_);
	cppVar_53061 = cppVar_53069;
	} else {
	cppVar_53070 = PC + 1;
	cppVar_53070 = (cppVar_53070 & cppMask_un_16_);
	cppVar_53071 = ROM.rd(cppVar_53070);
	cppVar_53072 = (cppVar_53071 >> 3) & cppMask_un_5_;
	cppVar_53073 = (cppVar_53072 & cppMask_un_5_);
	cppVar_53074 = cppVar_53073 + 32;
	cppVar_53074 = (cppVar_53074 & cppMask_un_8_);
	cppVar_53061 = cppVar_53074;
	}
	cppVar_53076 = (cppVar_53061 == 128);
	if (cppVar_53076) {
	cppVar_53060 = P0;
	} else {
	cppVar_53079 = PC + 1;
	cppVar_53079 = (cppVar_53079 & cppMask_un_16_);
	cppVar_53080 = ROM.rd(cppVar_53079);
	cppVar_53081 = (cppVar_53080 >> 7) & cppMask_un_1_;
	cppVar_53082 = (cppVar_53081 == 1);
	if (cppVar_53082) {
	cppVar_53083 = PC + 1;
	cppVar_53083 = (cppVar_53083 & cppMask_un_16_);
	cppVar_53084 = ROM.rd(cppVar_53083);
	cppVar_53085 = (cppVar_53084 >> 3) & cppMask_un_5_;
	cppVar_53086 = (cppVar_53085 << 3) | 0;
	cppVar_53086 = (cppVar_53086 & cppMask_un_8_);
	cppVar_53078 = cppVar_53086;
	} else {
	cppVar_53087 = PC + 1;
	cppVar_53087 = (cppVar_53087 & cppMask_un_16_);
	cppVar_53088 = ROM.rd(cppVar_53087);
	cppVar_53089 = (cppVar_53088 >> 3) & cppMask_un_5_;
	cppVar_53090 = (cppVar_53089 & cppMask_un_5_);
	cppVar_53091 = cppVar_53090 + 32;
	cppVar_53091 = (cppVar_53091 & cppMask_un_8_);
	cppVar_53078 = cppVar_53091;
	}
	cppVar_53093 = (cppVar_53078 == 129);
	if (cppVar_53093) {
	cppVar_53077 = SP;
	} else {
	cppVar_53096 = PC + 1;
	cppVar_53096 = (cppVar_53096 & cppMask_un_16_);
	cppVar_53097 = ROM.rd(cppVar_53096);
	cppVar_53098 = (cppVar_53097 >> 7) & cppMask_un_1_;
	cppVar_53099 = (cppVar_53098 == 1);
	if (cppVar_53099) {
	cppVar_53100 = PC + 1;
	cppVar_53100 = (cppVar_53100 & cppMask_un_16_);
	cppVar_53101 = ROM.rd(cppVar_53100);
	cppVar_53102 = (cppVar_53101 >> 3) & cppMask_un_5_;
	cppVar_53103 = (cppVar_53102 << 3) | 0;
	cppVar_53103 = (cppVar_53103 & cppMask_un_8_);
	cppVar_53095 = cppVar_53103;
	} else {
	cppVar_53104 = PC + 1;
	cppVar_53104 = (cppVar_53104 & cppMask_un_16_);
	cppVar_53105 = ROM.rd(cppVar_53104);
	cppVar_53106 = (cppVar_53105 >> 3) & cppMask_un_5_;
	cppVar_53107 = (cppVar_53106 & cppMask_un_5_);
	cppVar_53108 = cppVar_53107 + 32;
	cppVar_53108 = (cppVar_53108 & cppMask_un_8_);
	cppVar_53095 = cppVar_53108;
	}
	cppVar_53110 = (cppVar_53095 == 130);
	if (cppVar_53110) {
	cppVar_53094 = DPL;
	} else {
	cppVar_53113 = PC + 1;
	cppVar_53113 = (cppVar_53113 & cppMask_un_16_);
	cppVar_53114 = ROM.rd(cppVar_53113);
	cppVar_53115 = (cppVar_53114 >> 7) & cppMask_un_1_;
	cppVar_53116 = (cppVar_53115 == 1);
	if (cppVar_53116) {
	cppVar_53117 = PC + 1;
	cppVar_53117 = (cppVar_53117 & cppMask_un_16_);
	cppVar_53118 = ROM.rd(cppVar_53117);
	cppVar_53119 = (cppVar_53118 >> 3) & cppMask_un_5_;
	cppVar_53120 = (cppVar_53119 << 3) | 0;
	cppVar_53120 = (cppVar_53120 & cppMask_un_8_);
	cppVar_53112 = cppVar_53120;
	} else {
	cppVar_53121 = PC + 1;
	cppVar_53121 = (cppVar_53121 & cppMask_un_16_);
	cppVar_53122 = ROM.rd(cppVar_53121);
	cppVar_53123 = (cppVar_53122 >> 3) & cppMask_un_5_;
	cppVar_53124 = (cppVar_53123 & cppMask_un_5_);
	cppVar_53125 = cppVar_53124 + 32;
	cppVar_53125 = (cppVar_53125 & cppMask_un_8_);
	cppVar_53112 = cppVar_53125;
	}
	cppVar_53127 = (cppVar_53112 == 131);
	if (cppVar_53127) {
	cppVar_53111 = DPH;
	} else {
	cppVar_53130 = PC + 1;
	cppVar_53130 = (cppVar_53130 & cppMask_un_16_);
	cppVar_53131 = ROM.rd(cppVar_53130);
	cppVar_53132 = (cppVar_53131 >> 7) & cppMask_un_1_;
	cppVar_53133 = (cppVar_53132 == 1);
	if (cppVar_53133) {
	cppVar_53134 = PC + 1;
	cppVar_53134 = (cppVar_53134 & cppMask_un_16_);
	cppVar_53135 = ROM.rd(cppVar_53134);
	cppVar_53136 = (cppVar_53135 >> 3) & cppMask_un_5_;
	cppVar_53137 = (cppVar_53136 << 3) | 0;
	cppVar_53137 = (cppVar_53137 & cppMask_un_8_);
	cppVar_53129 = cppVar_53137;
	} else {
	cppVar_53138 = PC + 1;
	cppVar_53138 = (cppVar_53138 & cppMask_un_16_);
	cppVar_53139 = ROM.rd(cppVar_53138);
	cppVar_53140 = (cppVar_53139 >> 3) & cppMask_un_5_;
	cppVar_53141 = (cppVar_53140 & cppMask_un_5_);
	cppVar_53142 = cppVar_53141 + 32;
	cppVar_53142 = (cppVar_53142 & cppMask_un_8_);
	cppVar_53129 = cppVar_53142;
	}
	cppVar_53144 = (cppVar_53129 == 135);
	if (cppVar_53144) {
	cppVar_53128 = PCON;
	} else {
	cppVar_53147 = PC + 1;
	cppVar_53147 = (cppVar_53147 & cppMask_un_16_);
	cppVar_53148 = ROM.rd(cppVar_53147);
	cppVar_53149 = (cppVar_53148 >> 7) & cppMask_un_1_;
	cppVar_53150 = (cppVar_53149 == 1);
	if (cppVar_53150) {
	cppVar_53151 = PC + 1;
	cppVar_53151 = (cppVar_53151 & cppMask_un_16_);
	cppVar_53152 = ROM.rd(cppVar_53151);
	cppVar_53153 = (cppVar_53152 >> 3) & cppMask_un_5_;
	cppVar_53154 = (cppVar_53153 << 3) | 0;
	cppVar_53154 = (cppVar_53154 & cppMask_un_8_);
	cppVar_53146 = cppVar_53154;
	} else {
	cppVar_53155 = PC + 1;
	cppVar_53155 = (cppVar_53155 & cppMask_un_16_);
	cppVar_53156 = ROM.rd(cppVar_53155);
	cppVar_53157 = (cppVar_53156 >> 3) & cppMask_un_5_;
	cppVar_53158 = (cppVar_53157 & cppMask_un_5_);
	cppVar_53159 = cppVar_53158 + 32;
	cppVar_53159 = (cppVar_53159 & cppMask_un_8_);
	cppVar_53146 = cppVar_53159;
	}
	cppVar_53161 = (cppVar_53146 == 136);
	if (cppVar_53161) {
	cppVar_53145 = TCON;
	} else {
	cppVar_53164 = PC + 1;
	cppVar_53164 = (cppVar_53164 & cppMask_un_16_);
	cppVar_53165 = ROM.rd(cppVar_53164);
	cppVar_53166 = (cppVar_53165 >> 7) & cppMask_un_1_;
	cppVar_53167 = (cppVar_53166 == 1);
	if (cppVar_53167) {
	cppVar_53168 = PC + 1;
	cppVar_53168 = (cppVar_53168 & cppMask_un_16_);
	cppVar_53169 = ROM.rd(cppVar_53168);
	cppVar_53170 = (cppVar_53169 >> 3) & cppMask_un_5_;
	cppVar_53171 = (cppVar_53170 << 3) | 0;
	cppVar_53171 = (cppVar_53171 & cppMask_un_8_);
	cppVar_53163 = cppVar_53171;
	} else {
	cppVar_53172 = PC + 1;
	cppVar_53172 = (cppVar_53172 & cppMask_un_16_);
	cppVar_53173 = ROM.rd(cppVar_53172);
	cppVar_53174 = (cppVar_53173 >> 3) & cppMask_un_5_;
	cppVar_53175 = (cppVar_53174 & cppMask_un_5_);
	cppVar_53176 = cppVar_53175 + 32;
	cppVar_53176 = (cppVar_53176 & cppMask_un_8_);
	cppVar_53163 = cppVar_53176;
	}
	cppVar_53178 = (cppVar_53163 == 137);
	if (cppVar_53178) {
	cppVar_53162 = TMOD;
	} else {
	cppVar_53181 = PC + 1;
	cppVar_53181 = (cppVar_53181 & cppMask_un_16_);
	cppVar_53182 = ROM.rd(cppVar_53181);
	cppVar_53183 = (cppVar_53182 >> 7) & cppMask_un_1_;
	cppVar_53184 = (cppVar_53183 == 1);
	if (cppVar_53184) {
	cppVar_53185 = PC + 1;
	cppVar_53185 = (cppVar_53185 & cppMask_un_16_);
	cppVar_53186 = ROM.rd(cppVar_53185);
	cppVar_53187 = (cppVar_53186 >> 3) & cppMask_un_5_;
	cppVar_53188 = (cppVar_53187 << 3) | 0;
	cppVar_53188 = (cppVar_53188 & cppMask_un_8_);
	cppVar_53180 = cppVar_53188;
	} else {
	cppVar_53189 = PC + 1;
	cppVar_53189 = (cppVar_53189 & cppMask_un_16_);
	cppVar_53190 = ROM.rd(cppVar_53189);
	cppVar_53191 = (cppVar_53190 >> 3) & cppMask_un_5_;
	cppVar_53192 = (cppVar_53191 & cppMask_un_5_);
	cppVar_53193 = cppVar_53192 + 32;
	cppVar_53193 = (cppVar_53193 & cppMask_un_8_);
	cppVar_53180 = cppVar_53193;
	}
	cppVar_53195 = (cppVar_53180 == 138);
	if (cppVar_53195) {
	cppVar_53179 = TL0;
	} else {
	cppVar_53198 = PC + 1;
	cppVar_53198 = (cppVar_53198 & cppMask_un_16_);
	cppVar_53199 = ROM.rd(cppVar_53198);
	cppVar_53200 = (cppVar_53199 >> 7) & cppMask_un_1_;
	cppVar_53201 = (cppVar_53200 == 1);
	if (cppVar_53201) {
	cppVar_53202 = PC + 1;
	cppVar_53202 = (cppVar_53202 & cppMask_un_16_);
	cppVar_53203 = ROM.rd(cppVar_53202);
	cppVar_53204 = (cppVar_53203 >> 3) & cppMask_un_5_;
	cppVar_53205 = (cppVar_53204 << 3) | 0;
	cppVar_53205 = (cppVar_53205 & cppMask_un_8_);
	cppVar_53197 = cppVar_53205;
	} else {
	cppVar_53206 = PC + 1;
	cppVar_53206 = (cppVar_53206 & cppMask_un_16_);
	cppVar_53207 = ROM.rd(cppVar_53206);
	cppVar_53208 = (cppVar_53207 >> 3) & cppMask_un_5_;
	cppVar_53209 = (cppVar_53208 & cppMask_un_5_);
	cppVar_53210 = cppVar_53209 + 32;
	cppVar_53210 = (cppVar_53210 & cppMask_un_8_);
	cppVar_53197 = cppVar_53210;
	}
	cppVar_53212 = (cppVar_53197 == 140);
	if (cppVar_53212) {
	cppVar_53196 = TH0;
	} else {
	cppVar_53215 = PC + 1;
	cppVar_53215 = (cppVar_53215 & cppMask_un_16_);
	cppVar_53216 = ROM.rd(cppVar_53215);
	cppVar_53217 = (cppVar_53216 >> 7) & cppMask_un_1_;
	cppVar_53218 = (cppVar_53217 == 1);
	if (cppVar_53218) {
	cppVar_53219 = PC + 1;
	cppVar_53219 = (cppVar_53219 & cppMask_un_16_);
	cppVar_53220 = ROM.rd(cppVar_53219);
	cppVar_53221 = (cppVar_53220 >> 3) & cppMask_un_5_;
	cppVar_53222 = (cppVar_53221 << 3) | 0;
	cppVar_53222 = (cppVar_53222 & cppMask_un_8_);
	cppVar_53214 = cppVar_53222;
	} else {
	cppVar_53223 = PC + 1;
	cppVar_53223 = (cppVar_53223 & cppMask_un_16_);
	cppVar_53224 = ROM.rd(cppVar_53223);
	cppVar_53225 = (cppVar_53224 >> 3) & cppMask_un_5_;
	cppVar_53226 = (cppVar_53225 & cppMask_un_5_);
	cppVar_53227 = cppVar_53226 + 32;
	cppVar_53227 = (cppVar_53227 & cppMask_un_8_);
	cppVar_53214 = cppVar_53227;
	}
	cppVar_53229 = (cppVar_53214 == 139);
	if (cppVar_53229) {
	cppVar_53213 = TL1;
	} else {
	cppVar_53232 = PC + 1;
	cppVar_53232 = (cppVar_53232 & cppMask_un_16_);
	cppVar_53233 = ROM.rd(cppVar_53232);
	cppVar_53234 = (cppVar_53233 >> 7) & cppMask_un_1_;
	cppVar_53235 = (cppVar_53234 == 1);
	if (cppVar_53235) {
	cppVar_53236 = PC + 1;
	cppVar_53236 = (cppVar_53236 & cppMask_un_16_);
	cppVar_53237 = ROM.rd(cppVar_53236);
	cppVar_53238 = (cppVar_53237 >> 3) & cppMask_un_5_;
	cppVar_53239 = (cppVar_53238 << 3) | 0;
	cppVar_53239 = (cppVar_53239 & cppMask_un_8_);
	cppVar_53231 = cppVar_53239;
	} else {
	cppVar_53240 = PC + 1;
	cppVar_53240 = (cppVar_53240 & cppMask_un_16_);
	cppVar_53241 = ROM.rd(cppVar_53240);
	cppVar_53242 = (cppVar_53241 >> 3) & cppMask_un_5_;
	cppVar_53243 = (cppVar_53242 & cppMask_un_5_);
	cppVar_53244 = cppVar_53243 + 32;
	cppVar_53244 = (cppVar_53244 & cppMask_un_8_);
	cppVar_53231 = cppVar_53244;
	}
	cppVar_53246 = (cppVar_53231 == 141);
	if (cppVar_53246) {
	cppVar_53230 = TH1;
	} else {
	cppVar_53249 = PC + 1;
	cppVar_53249 = (cppVar_53249 & cppMask_un_16_);
	cppVar_53250 = ROM.rd(cppVar_53249);
	cppVar_53251 = (cppVar_53250 >> 7) & cppMask_un_1_;
	cppVar_53252 = (cppVar_53251 == 1);
	if (cppVar_53252) {
	cppVar_53253 = PC + 1;
	cppVar_53253 = (cppVar_53253 & cppMask_un_16_);
	cppVar_53254 = ROM.rd(cppVar_53253);
	cppVar_53255 = (cppVar_53254 >> 3) & cppMask_un_5_;
	cppVar_53256 = (cppVar_53255 << 3) | 0;
	cppVar_53256 = (cppVar_53256 & cppMask_un_8_);
	cppVar_53248 = cppVar_53256;
	} else {
	cppVar_53257 = PC + 1;
	cppVar_53257 = (cppVar_53257 & cppMask_un_16_);
	cppVar_53258 = ROM.rd(cppVar_53257);
	cppVar_53259 = (cppVar_53258 >> 3) & cppMask_un_5_;
	cppVar_53260 = (cppVar_53259 & cppMask_un_5_);
	cppVar_53261 = cppVar_53260 + 32;
	cppVar_53261 = (cppVar_53261 & cppMask_un_8_);
	cppVar_53248 = cppVar_53261;
	}
	cppVar_53263 = (cppVar_53248 == 144);
	if (cppVar_53263) {
	cppVar_53247 = P1;
	} else {
	cppVar_53266 = PC + 1;
	cppVar_53266 = (cppVar_53266 & cppMask_un_16_);
	cppVar_53267 = ROM.rd(cppVar_53266);
	cppVar_53268 = (cppVar_53267 >> 7) & cppMask_un_1_;
	cppVar_53269 = (cppVar_53268 == 1);
	if (cppVar_53269) {
	cppVar_53270 = PC + 1;
	cppVar_53270 = (cppVar_53270 & cppMask_un_16_);
	cppVar_53271 = ROM.rd(cppVar_53270);
	cppVar_53272 = (cppVar_53271 >> 3) & cppMask_un_5_;
	cppVar_53273 = (cppVar_53272 << 3) | 0;
	cppVar_53273 = (cppVar_53273 & cppMask_un_8_);
	cppVar_53265 = cppVar_53273;
	} else {
	cppVar_53274 = PC + 1;
	cppVar_53274 = (cppVar_53274 & cppMask_un_16_);
	cppVar_53275 = ROM.rd(cppVar_53274);
	cppVar_53276 = (cppVar_53275 >> 3) & cppMask_un_5_;
	cppVar_53277 = (cppVar_53276 & cppMask_un_5_);
	cppVar_53278 = cppVar_53277 + 32;
	cppVar_53278 = (cppVar_53278 & cppMask_un_8_);
	cppVar_53265 = cppVar_53278;
	}
	cppVar_53280 = (cppVar_53265 == 152);
	if (cppVar_53280) {
	cppVar_53264 = SCON;
	} else {
	cppVar_53283 = PC + 1;
	cppVar_53283 = (cppVar_53283 & cppMask_un_16_);
	cppVar_53284 = ROM.rd(cppVar_53283);
	cppVar_53285 = (cppVar_53284 >> 7) & cppMask_un_1_;
	cppVar_53286 = (cppVar_53285 == 1);
	if (cppVar_53286) {
	cppVar_53287 = PC + 1;
	cppVar_53287 = (cppVar_53287 & cppMask_un_16_);
	cppVar_53288 = ROM.rd(cppVar_53287);
	cppVar_53289 = (cppVar_53288 >> 3) & cppMask_un_5_;
	cppVar_53290 = (cppVar_53289 << 3) | 0;
	cppVar_53290 = (cppVar_53290 & cppMask_un_8_);
	cppVar_53282 = cppVar_53290;
	} else {
	cppVar_53291 = PC + 1;
	cppVar_53291 = (cppVar_53291 & cppMask_un_16_);
	cppVar_53292 = ROM.rd(cppVar_53291);
	cppVar_53293 = (cppVar_53292 >> 3) & cppMask_un_5_;
	cppVar_53294 = (cppVar_53293 & cppMask_un_5_);
	cppVar_53295 = cppVar_53294 + 32;
	cppVar_53295 = (cppVar_53295 & cppMask_un_8_);
	cppVar_53282 = cppVar_53295;
	}
	cppVar_53297 = (cppVar_53282 == 153);
	if (cppVar_53297) {
	cppVar_53281 = SBUF;
	} else {
	cppVar_53300 = PC + 1;
	cppVar_53300 = (cppVar_53300 & cppMask_un_16_);
	cppVar_53301 = ROM.rd(cppVar_53300);
	cppVar_53302 = (cppVar_53301 >> 7) & cppMask_un_1_;
	cppVar_53303 = (cppVar_53302 == 1);
	if (cppVar_53303) {
	cppVar_53304 = PC + 1;
	cppVar_53304 = (cppVar_53304 & cppMask_un_16_);
	cppVar_53305 = ROM.rd(cppVar_53304);
	cppVar_53306 = (cppVar_53305 >> 3) & cppMask_un_5_;
	cppVar_53307 = (cppVar_53306 << 3) | 0;
	cppVar_53307 = (cppVar_53307 & cppMask_un_8_);
	cppVar_53299 = cppVar_53307;
	} else {
	cppVar_53308 = PC + 1;
	cppVar_53308 = (cppVar_53308 & cppMask_un_16_);
	cppVar_53309 = ROM.rd(cppVar_53308);
	cppVar_53310 = (cppVar_53309 >> 3) & cppMask_un_5_;
	cppVar_53311 = (cppVar_53310 & cppMask_un_5_);
	cppVar_53312 = cppVar_53311 + 32;
	cppVar_53312 = (cppVar_53312 & cppMask_un_8_);
	cppVar_53299 = cppVar_53312;
	}
	cppVar_53314 = (cppVar_53299 == 160);
	if (cppVar_53314) {
	cppVar_53298 = P2;
	} else {
	cppVar_53317 = PC + 1;
	cppVar_53317 = (cppVar_53317 & cppMask_un_16_);
	cppVar_53318 = ROM.rd(cppVar_53317);
	cppVar_53319 = (cppVar_53318 >> 7) & cppMask_un_1_;
	cppVar_53320 = (cppVar_53319 == 1);
	if (cppVar_53320) {
	cppVar_53321 = PC + 1;
	cppVar_53321 = (cppVar_53321 & cppMask_un_16_);
	cppVar_53322 = ROM.rd(cppVar_53321);
	cppVar_53323 = (cppVar_53322 >> 3) & cppMask_un_5_;
	cppVar_53324 = (cppVar_53323 << 3) | 0;
	cppVar_53324 = (cppVar_53324 & cppMask_un_8_);
	cppVar_53316 = cppVar_53324;
	} else {
	cppVar_53325 = PC + 1;
	cppVar_53325 = (cppVar_53325 & cppMask_un_16_);
	cppVar_53326 = ROM.rd(cppVar_53325);
	cppVar_53327 = (cppVar_53326 >> 3) & cppMask_un_5_;
	cppVar_53328 = (cppVar_53327 & cppMask_un_5_);
	cppVar_53329 = cppVar_53328 + 32;
	cppVar_53329 = (cppVar_53329 & cppMask_un_8_);
	cppVar_53316 = cppVar_53329;
	}
	cppVar_53331 = (cppVar_53316 == 168);
	if (cppVar_53331) {
	cppVar_53315 = IE;
	} else {
	cppVar_53334 = PC + 1;
	cppVar_53334 = (cppVar_53334 & cppMask_un_16_);
	cppVar_53335 = ROM.rd(cppVar_53334);
	cppVar_53336 = (cppVar_53335 >> 7) & cppMask_un_1_;
	cppVar_53337 = (cppVar_53336 == 1);
	if (cppVar_53337) {
	cppVar_53338 = PC + 1;
	cppVar_53338 = (cppVar_53338 & cppMask_un_16_);
	cppVar_53339 = ROM.rd(cppVar_53338);
	cppVar_53340 = (cppVar_53339 >> 3) & cppMask_un_5_;
	cppVar_53341 = (cppVar_53340 << 3) | 0;
	cppVar_53341 = (cppVar_53341 & cppMask_un_8_);
	cppVar_53333 = cppVar_53341;
	} else {
	cppVar_53342 = PC + 1;
	cppVar_53342 = (cppVar_53342 & cppMask_un_16_);
	cppVar_53343 = ROM.rd(cppVar_53342);
	cppVar_53344 = (cppVar_53343 >> 3) & cppMask_un_5_;
	cppVar_53345 = (cppVar_53344 & cppMask_un_5_);
	cppVar_53346 = cppVar_53345 + 32;
	cppVar_53346 = (cppVar_53346 & cppMask_un_8_);
	cppVar_53333 = cppVar_53346;
	}
	cppVar_53348 = (cppVar_53333 == 176);
	if (cppVar_53348) {
	cppVar_53332 = P3;
	} else {
	cppVar_53351 = PC + 1;
	cppVar_53351 = (cppVar_53351 & cppMask_un_16_);
	cppVar_53352 = ROM.rd(cppVar_53351);
	cppVar_53353 = (cppVar_53352 >> 7) & cppMask_un_1_;
	cppVar_53354 = (cppVar_53353 == 1);
	if (cppVar_53354) {
	cppVar_53355 = PC + 1;
	cppVar_53355 = (cppVar_53355 & cppMask_un_16_);
	cppVar_53356 = ROM.rd(cppVar_53355);
	cppVar_53357 = (cppVar_53356 >> 3) & cppMask_un_5_;
	cppVar_53358 = (cppVar_53357 << 3) | 0;
	cppVar_53358 = (cppVar_53358 & cppMask_un_8_);
	cppVar_53350 = cppVar_53358;
	} else {
	cppVar_53359 = PC + 1;
	cppVar_53359 = (cppVar_53359 & cppMask_un_16_);
	cppVar_53360 = ROM.rd(cppVar_53359);
	cppVar_53361 = (cppVar_53360 >> 3) & cppMask_un_5_;
	cppVar_53362 = (cppVar_53361 & cppMask_un_5_);
	cppVar_53363 = cppVar_53362 + 32;
	cppVar_53363 = (cppVar_53363 & cppMask_un_8_);
	cppVar_53350 = cppVar_53363;
	}
	cppVar_53365 = (cppVar_53350 == 184);
	if (cppVar_53365) {
	cppVar_53349 = IP;
	} else {
	cppVar_53368 = PC + 1;
	cppVar_53368 = (cppVar_53368 & cppMask_un_16_);
	cppVar_53369 = ROM.rd(cppVar_53368);
	cppVar_53370 = (cppVar_53369 >> 7) & cppMask_un_1_;
	cppVar_53371 = (cppVar_53370 == 1);
	if (cppVar_53371) {
	cppVar_53372 = PC + 1;
	cppVar_53372 = (cppVar_53372 & cppMask_un_16_);
	cppVar_53373 = ROM.rd(cppVar_53372);
	cppVar_53374 = (cppVar_53373 >> 3) & cppMask_un_5_;
	cppVar_53375 = (cppVar_53374 << 3) | 0;
	cppVar_53375 = (cppVar_53375 & cppMask_un_8_);
	cppVar_53367 = cppVar_53375;
	} else {
	cppVar_53376 = PC + 1;
	cppVar_53376 = (cppVar_53376 & cppMask_un_16_);
	cppVar_53377 = ROM.rd(cppVar_53376);
	cppVar_53378 = (cppVar_53377 >> 3) & cppMask_un_5_;
	cppVar_53379 = (cppVar_53378 & cppMask_un_5_);
	cppVar_53380 = cppVar_53379 + 32;
	cppVar_53380 = (cppVar_53380 & cppMask_un_8_);
	cppVar_53367 = cppVar_53380;
	}
	cppVar_53382 = (cppVar_53367 == 208);
	if (cppVar_53382) {
	cppVar_53366 = PSW;
	} else {
	cppVar_53385 = PC + 1;
	cppVar_53385 = (cppVar_53385 & cppMask_un_16_);
	cppVar_53386 = ROM.rd(cppVar_53385);
	cppVar_53387 = (cppVar_53386 >> 7) & cppMask_un_1_;
	cppVar_53388 = (cppVar_53387 == 1);
	if (cppVar_53388) {
	cppVar_53389 = PC + 1;
	cppVar_53389 = (cppVar_53389 & cppMask_un_16_);
	cppVar_53390 = ROM.rd(cppVar_53389);
	cppVar_53391 = (cppVar_53390 >> 3) & cppMask_un_5_;
	cppVar_53392 = (cppVar_53391 << 3) | 0;
	cppVar_53392 = (cppVar_53392 & cppMask_un_8_);
	cppVar_53384 = cppVar_53392;
	} else {
	cppVar_53393 = PC + 1;
	cppVar_53393 = (cppVar_53393 & cppMask_un_16_);
	cppVar_53394 = ROM.rd(cppVar_53393);
	cppVar_53395 = (cppVar_53394 >> 3) & cppMask_un_5_;
	cppVar_53396 = (cppVar_53395 & cppMask_un_5_);
	cppVar_53397 = cppVar_53396 + 32;
	cppVar_53397 = (cppVar_53397 & cppMask_un_8_);
	cppVar_53384 = cppVar_53397;
	}
	cppVar_53399 = (cppVar_53384 == 224);
	if (cppVar_53399) {
	cppVar_53383 = ACC;
	} else {
	cppVar_53402 = PC + 1;
	cppVar_53402 = (cppVar_53402 & cppMask_un_16_);
	cppVar_53403 = ROM.rd(cppVar_53402);
	cppVar_53404 = (cppVar_53403 >> 7) & cppMask_un_1_;
	cppVar_53405 = (cppVar_53404 == 1);
	if (cppVar_53405) {
	cppVar_53406 = PC + 1;
	cppVar_53406 = (cppVar_53406 & cppMask_un_16_);
	cppVar_53407 = ROM.rd(cppVar_53406);
	cppVar_53408 = (cppVar_53407 >> 3) & cppMask_un_5_;
	cppVar_53409 = (cppVar_53408 << 3) | 0;
	cppVar_53409 = (cppVar_53409 & cppMask_un_8_);
	cppVar_53401 = cppVar_53409;
	} else {
	cppVar_53410 = PC + 1;
	cppVar_53410 = (cppVar_53410 & cppMask_un_16_);
	cppVar_53411 = ROM.rd(cppVar_53410);
	cppVar_53412 = (cppVar_53411 >> 3) & cppMask_un_5_;
	cppVar_53413 = (cppVar_53412 & cppMask_un_5_);
	cppVar_53414 = cppVar_53413 + 32;
	cppVar_53414 = (cppVar_53414 & cppMask_un_8_);
	cppVar_53401 = cppVar_53414;
	}
	cppVar_53416 = (cppVar_53401 == 240);
	if (cppVar_53416) {
	cppVar_53400 = B;
	} else {
	cppVar_53400 = 0;
	}
	cppVar_53383 = cppVar_53400;
	}
	cppVar_53366 = cppVar_53383;
	}
	cppVar_53349 = cppVar_53366;
	}
	cppVar_53332 = cppVar_53349;
	}
	cppVar_53315 = cppVar_53332;
	}
	cppVar_53298 = cppVar_53315;
	}
	cppVar_53281 = cppVar_53298;
	}
	cppVar_53264 = cppVar_53281;
	}
	cppVar_53247 = cppVar_53264;
	}
	cppVar_53230 = cppVar_53247;
	}
	cppVar_53213 = cppVar_53230;
	}
	cppVar_53196 = cppVar_53213;
	}
	cppVar_53179 = cppVar_53196;
	}
	cppVar_53162 = cppVar_53179;
	}
	cppVar_53145 = cppVar_53162;
	}
	cppVar_53128 = cppVar_53145;
	}
	cppVar_53111 = cppVar_53128;
	}
	cppVar_53094 = cppVar_53111;
	}
	cppVar_53077 = cppVar_53094;
	}
	cppVar_53060 = cppVar_53077;
	}
	cppVar_53023 = cppVar_53060;
	}
	cppVar_53418 = PC + 1;
	cppVar_53418 = (cppVar_53418 & cppMask_un_16_);
	cppVar_53419 = ROM.rd(cppVar_53418);
	cppVar_53420 = (cppVar_53419 >> 0) & cppMask_un_3_;
	cppVar_53421 = (cppVar_53023 >> static_cast<unsigned>(cppVar_53420)) & 0x1;
	cppVar_53422 = cppVar_53022 | cppVar_53421;
	cppVar_53423 = (PSW >> 0) & cppMask_un_7_;
	cppVar_53424 = (cppVar_53422 << 7) | cppVar_53423;
	cppVar_53424 = (cppVar_53424 & cppMask_un_8_);
	cppVar_53018 = cppVar_53424;
	} else {
	cppVar_53426 = ROM.rd(PC);
	cppVar_53428 = (cppVar_53426 == 99);
	if (cppVar_53428) {
	cppVar_53431 = PC + 1;
	cppVar_53431 = (cppVar_53431 & cppMask_un_16_);
	cppVar_53432 = ROM.rd(cppVar_53431);
	cppVar_53434 = (cppVar_53432 == 208);
	if (cppVar_53434) {
	cppVar_53436 = PC + 1;
	cppVar_53436 = (cppVar_53436 & cppMask_un_16_);
	cppVar_53437 = ROM.rd(cppVar_53436);
	cppVar_53438 = (cppVar_53437 >> 7) & cppMask_un_1_;
	cppVar_53440 = (cppVar_53438 == 0);
	if (cppVar_53440) {
	cppVar_53441 = PC + 1;
	cppVar_53441 = (cppVar_53441 & cppMask_un_16_);
	cppVar_53442 = ROM.rd(cppVar_53441);
	cppVar_53443 = IRAM.rd(cppVar_53442);
	cppVar_53435 = cppVar_53443;
	} else {
	cppVar_53445 = PC + 1;
	cppVar_53445 = (cppVar_53445 & cppMask_un_16_);
	cppVar_53446 = ROM.rd(cppVar_53445);
	cppVar_53448 = (cppVar_53446 == 128);
	if (cppVar_53448) {
	cppVar_53444 = P0;
	} else {
	cppVar_53450 = PC + 1;
	cppVar_53450 = (cppVar_53450 & cppMask_un_16_);
	cppVar_53451 = ROM.rd(cppVar_53450);
	cppVar_53453 = (cppVar_53451 == 129);
	if (cppVar_53453) {
	cppVar_53449 = SP;
	} else {
	cppVar_53455 = PC + 1;
	cppVar_53455 = (cppVar_53455 & cppMask_un_16_);
	cppVar_53456 = ROM.rd(cppVar_53455);
	cppVar_53458 = (cppVar_53456 == 130);
	if (cppVar_53458) {
	cppVar_53454 = DPL;
	} else {
	cppVar_53460 = PC + 1;
	cppVar_53460 = (cppVar_53460 & cppMask_un_16_);
	cppVar_53461 = ROM.rd(cppVar_53460);
	cppVar_53463 = (cppVar_53461 == 131);
	if (cppVar_53463) {
	cppVar_53459 = DPH;
	} else {
	cppVar_53465 = PC + 1;
	cppVar_53465 = (cppVar_53465 & cppMask_un_16_);
	cppVar_53466 = ROM.rd(cppVar_53465);
	cppVar_53468 = (cppVar_53466 == 135);
	if (cppVar_53468) {
	cppVar_53464 = PCON;
	} else {
	cppVar_53470 = PC + 1;
	cppVar_53470 = (cppVar_53470 & cppMask_un_16_);
	cppVar_53471 = ROM.rd(cppVar_53470);
	cppVar_53473 = (cppVar_53471 == 136);
	if (cppVar_53473) {
	cppVar_53469 = TCON;
	} else {
	cppVar_53475 = PC + 1;
	cppVar_53475 = (cppVar_53475 & cppMask_un_16_);
	cppVar_53476 = ROM.rd(cppVar_53475);
	cppVar_53478 = (cppVar_53476 == 137);
	if (cppVar_53478) {
	cppVar_53474 = TMOD;
	} else {
	cppVar_53480 = PC + 1;
	cppVar_53480 = (cppVar_53480 & cppMask_un_16_);
	cppVar_53481 = ROM.rd(cppVar_53480);
	cppVar_53483 = (cppVar_53481 == 138);
	if (cppVar_53483) {
	cppVar_53479 = TL0;
	} else {
	cppVar_53485 = PC + 1;
	cppVar_53485 = (cppVar_53485 & cppMask_un_16_);
	cppVar_53486 = ROM.rd(cppVar_53485);
	cppVar_53488 = (cppVar_53486 == 140);
	if (cppVar_53488) {
	cppVar_53484 = TH0;
	} else {
	cppVar_53490 = PC + 1;
	cppVar_53490 = (cppVar_53490 & cppMask_un_16_);
	cppVar_53491 = ROM.rd(cppVar_53490);
	cppVar_53493 = (cppVar_53491 == 139);
	if (cppVar_53493) {
	cppVar_53489 = TL1;
	} else {
	cppVar_53495 = PC + 1;
	cppVar_53495 = (cppVar_53495 & cppMask_un_16_);
	cppVar_53496 = ROM.rd(cppVar_53495);
	cppVar_53498 = (cppVar_53496 == 141);
	if (cppVar_53498) {
	cppVar_53494 = TH1;
	} else {
	cppVar_53500 = PC + 1;
	cppVar_53500 = (cppVar_53500 & cppMask_un_16_);
	cppVar_53501 = ROM.rd(cppVar_53500);
	cppVar_53503 = (cppVar_53501 == 144);
	if (cppVar_53503) {
	cppVar_53499 = P1;
	} else {
	cppVar_53505 = PC + 1;
	cppVar_53505 = (cppVar_53505 & cppMask_un_16_);
	cppVar_53506 = ROM.rd(cppVar_53505);
	cppVar_53508 = (cppVar_53506 == 152);
	if (cppVar_53508) {
	cppVar_53504 = SCON;
	} else {
	cppVar_53510 = PC + 1;
	cppVar_53510 = (cppVar_53510 & cppMask_un_16_);
	cppVar_53511 = ROM.rd(cppVar_53510);
	cppVar_53513 = (cppVar_53511 == 153);
	if (cppVar_53513) {
	cppVar_53509 = SBUF;
	} else {
	cppVar_53515 = PC + 1;
	cppVar_53515 = (cppVar_53515 & cppMask_un_16_);
	cppVar_53516 = ROM.rd(cppVar_53515);
	cppVar_53518 = (cppVar_53516 == 160);
	if (cppVar_53518) {
	cppVar_53514 = P2;
	} else {
	cppVar_53520 = PC + 1;
	cppVar_53520 = (cppVar_53520 & cppMask_un_16_);
	cppVar_53521 = ROM.rd(cppVar_53520);
	cppVar_53523 = (cppVar_53521 == 168);
	if (cppVar_53523) {
	cppVar_53519 = IE;
	} else {
	cppVar_53525 = PC + 1;
	cppVar_53525 = (cppVar_53525 & cppMask_un_16_);
	cppVar_53526 = ROM.rd(cppVar_53525);
	cppVar_53528 = (cppVar_53526 == 176);
	if (cppVar_53528) {
	cppVar_53524 = P3;
	} else {
	cppVar_53530 = PC + 1;
	cppVar_53530 = (cppVar_53530 & cppMask_un_16_);
	cppVar_53531 = ROM.rd(cppVar_53530);
	cppVar_53533 = (cppVar_53531 == 184);
	if (cppVar_53533) {
	cppVar_53529 = IP;
	} else {
	cppVar_53535 = PC + 1;
	cppVar_53535 = (cppVar_53535 & cppMask_un_16_);
	cppVar_53536 = ROM.rd(cppVar_53535);
	cppVar_53538 = (cppVar_53536 == 208);
	if (cppVar_53538) {
	cppVar_53534 = PSW;
	} else {
	cppVar_53540 = PC + 1;
	cppVar_53540 = (cppVar_53540 & cppMask_un_16_);
	cppVar_53541 = ROM.rd(cppVar_53540);
	cppVar_53543 = (cppVar_53541 == 224);
	if (cppVar_53543) {
	cppVar_53539 = ACC;
	} else {
	cppVar_53545 = PC + 1;
	cppVar_53545 = (cppVar_53545 & cppMask_un_16_);
	cppVar_53546 = ROM.rd(cppVar_53545);
	cppVar_53548 = (cppVar_53546 == 240);
	if (cppVar_53548) {
	cppVar_53544 = B;
	} else {
	cppVar_53544 = 0;
	}
	cppVar_53539 = cppVar_53544;
	}
	cppVar_53534 = cppVar_53539;
	}
	cppVar_53529 = cppVar_53534;
	}
	cppVar_53524 = cppVar_53529;
	}
	cppVar_53519 = cppVar_53524;
	}
	cppVar_53514 = cppVar_53519;
	}
	cppVar_53509 = cppVar_53514;
	}
	cppVar_53504 = cppVar_53509;
	}
	cppVar_53499 = cppVar_53504;
	}
	cppVar_53494 = cppVar_53499;
	}
	cppVar_53489 = cppVar_53494;
	}
	cppVar_53484 = cppVar_53489;
	}
	cppVar_53479 = cppVar_53484;
	}
	cppVar_53474 = cppVar_53479;
	}
	cppVar_53469 = cppVar_53474;
	}
	cppVar_53464 = cppVar_53469;
	}
	cppVar_53459 = cppVar_53464;
	}
	cppVar_53454 = cppVar_53459;
	}
	cppVar_53449 = cppVar_53454;
	}
	cppVar_53444 = cppVar_53449;
	}
	cppVar_53435 = cppVar_53444;
	}
	cppVar_53551 = PC + 2;
	cppVar_53551 = (cppVar_53551 & cppMask_un_16_);
	cppVar_53552 = ROM.rd(cppVar_53551);
	cppVar_53553 = cppVar_53435 ^ cppVar_53552;
	cppVar_53429 = cppVar_53553;
	} else {
	cppVar_53429 = PSW;
	}
	cppVar_53425 = cppVar_53429;
	} else {
	cppVar_53555 = ROM.rd(PC);
	cppVar_53557 = (cppVar_53555 == 98);
	if (cppVar_53557) {
	cppVar_53560 = PC + 1;
	cppVar_53560 = (cppVar_53560 & cppMask_un_16_);
	cppVar_53561 = ROM.rd(cppVar_53560);
	cppVar_53563 = (cppVar_53561 == 208);
	if (cppVar_53563) {
	cppVar_53565 = PC + 1;
	cppVar_53565 = (cppVar_53565 & cppMask_un_16_);
	cppVar_53566 = ROM.rd(cppVar_53565);
	cppVar_53567 = (cppVar_53566 >> 7) & cppMask_un_1_;
	cppVar_53569 = (cppVar_53567 == 0);
	if (cppVar_53569) {
	cppVar_53570 = PC + 1;
	cppVar_53570 = (cppVar_53570 & cppMask_un_16_);
	cppVar_53571 = ROM.rd(cppVar_53570);
	cppVar_53572 = IRAM.rd(cppVar_53571);
	cppVar_53564 = cppVar_53572;
	} else {
	cppVar_53574 = PC + 1;
	cppVar_53574 = (cppVar_53574 & cppMask_un_16_);
	cppVar_53575 = ROM.rd(cppVar_53574);
	cppVar_53577 = (cppVar_53575 == 128);
	if (cppVar_53577) {
	cppVar_53573 = P0;
	} else {
	cppVar_53579 = PC + 1;
	cppVar_53579 = (cppVar_53579 & cppMask_un_16_);
	cppVar_53580 = ROM.rd(cppVar_53579);
	cppVar_53582 = (cppVar_53580 == 129);
	if (cppVar_53582) {
	cppVar_53578 = SP;
	} else {
	cppVar_53584 = PC + 1;
	cppVar_53584 = (cppVar_53584 & cppMask_un_16_);
	cppVar_53585 = ROM.rd(cppVar_53584);
	cppVar_53587 = (cppVar_53585 == 130);
	if (cppVar_53587) {
	cppVar_53583 = DPL;
	} else {
	cppVar_53589 = PC + 1;
	cppVar_53589 = (cppVar_53589 & cppMask_un_16_);
	cppVar_53590 = ROM.rd(cppVar_53589);
	cppVar_53592 = (cppVar_53590 == 131);
	if (cppVar_53592) {
	cppVar_53588 = DPH;
	} else {
	cppVar_53594 = PC + 1;
	cppVar_53594 = (cppVar_53594 & cppMask_un_16_);
	cppVar_53595 = ROM.rd(cppVar_53594);
	cppVar_53597 = (cppVar_53595 == 135);
	if (cppVar_53597) {
	cppVar_53593 = PCON;
	} else {
	cppVar_53599 = PC + 1;
	cppVar_53599 = (cppVar_53599 & cppMask_un_16_);
	cppVar_53600 = ROM.rd(cppVar_53599);
	cppVar_53602 = (cppVar_53600 == 136);
	if (cppVar_53602) {
	cppVar_53598 = TCON;
	} else {
	cppVar_53604 = PC + 1;
	cppVar_53604 = (cppVar_53604 & cppMask_un_16_);
	cppVar_53605 = ROM.rd(cppVar_53604);
	cppVar_53607 = (cppVar_53605 == 137);
	if (cppVar_53607) {
	cppVar_53603 = TMOD;
	} else {
	cppVar_53609 = PC + 1;
	cppVar_53609 = (cppVar_53609 & cppMask_un_16_);
	cppVar_53610 = ROM.rd(cppVar_53609);
	cppVar_53612 = (cppVar_53610 == 138);
	if (cppVar_53612) {
	cppVar_53608 = TL0;
	} else {
	cppVar_53614 = PC + 1;
	cppVar_53614 = (cppVar_53614 & cppMask_un_16_);
	cppVar_53615 = ROM.rd(cppVar_53614);
	cppVar_53617 = (cppVar_53615 == 140);
	if (cppVar_53617) {
	cppVar_53613 = TH0;
	} else {
	cppVar_53619 = PC + 1;
	cppVar_53619 = (cppVar_53619 & cppMask_un_16_);
	cppVar_53620 = ROM.rd(cppVar_53619);
	cppVar_53622 = (cppVar_53620 == 139);
	if (cppVar_53622) {
	cppVar_53618 = TL1;
	} else {
	cppVar_53624 = PC + 1;
	cppVar_53624 = (cppVar_53624 & cppMask_un_16_);
	cppVar_53625 = ROM.rd(cppVar_53624);
	cppVar_53627 = (cppVar_53625 == 141);
	if (cppVar_53627) {
	cppVar_53623 = TH1;
	} else {
	cppVar_53629 = PC + 1;
	cppVar_53629 = (cppVar_53629 & cppMask_un_16_);
	cppVar_53630 = ROM.rd(cppVar_53629);
	cppVar_53632 = (cppVar_53630 == 144);
	if (cppVar_53632) {
	cppVar_53628 = P1;
	} else {
	cppVar_53634 = PC + 1;
	cppVar_53634 = (cppVar_53634 & cppMask_un_16_);
	cppVar_53635 = ROM.rd(cppVar_53634);
	cppVar_53637 = (cppVar_53635 == 152);
	if (cppVar_53637) {
	cppVar_53633 = SCON;
	} else {
	cppVar_53639 = PC + 1;
	cppVar_53639 = (cppVar_53639 & cppMask_un_16_);
	cppVar_53640 = ROM.rd(cppVar_53639);
	cppVar_53642 = (cppVar_53640 == 153);
	if (cppVar_53642) {
	cppVar_53638 = SBUF;
	} else {
	cppVar_53644 = PC + 1;
	cppVar_53644 = (cppVar_53644 & cppMask_un_16_);
	cppVar_53645 = ROM.rd(cppVar_53644);
	cppVar_53647 = (cppVar_53645 == 160);
	if (cppVar_53647) {
	cppVar_53643 = P2;
	} else {
	cppVar_53649 = PC + 1;
	cppVar_53649 = (cppVar_53649 & cppMask_un_16_);
	cppVar_53650 = ROM.rd(cppVar_53649);
	cppVar_53652 = (cppVar_53650 == 168);
	if (cppVar_53652) {
	cppVar_53648 = IE;
	} else {
	cppVar_53654 = PC + 1;
	cppVar_53654 = (cppVar_53654 & cppMask_un_16_);
	cppVar_53655 = ROM.rd(cppVar_53654);
	cppVar_53657 = (cppVar_53655 == 176);
	if (cppVar_53657) {
	cppVar_53653 = P3;
	} else {
	cppVar_53659 = PC + 1;
	cppVar_53659 = (cppVar_53659 & cppMask_un_16_);
	cppVar_53660 = ROM.rd(cppVar_53659);
	cppVar_53662 = (cppVar_53660 == 184);
	if (cppVar_53662) {
	cppVar_53658 = IP;
	} else {
	cppVar_53664 = PC + 1;
	cppVar_53664 = (cppVar_53664 & cppMask_un_16_);
	cppVar_53665 = ROM.rd(cppVar_53664);
	cppVar_53667 = (cppVar_53665 == 208);
	if (cppVar_53667) {
	cppVar_53663 = PSW;
	} else {
	cppVar_53669 = PC + 1;
	cppVar_53669 = (cppVar_53669 & cppMask_un_16_);
	cppVar_53670 = ROM.rd(cppVar_53669);
	cppVar_53672 = (cppVar_53670 == 224);
	if (cppVar_53672) {
	cppVar_53668 = ACC;
	} else {
	cppVar_53674 = PC + 1;
	cppVar_53674 = (cppVar_53674 & cppMask_un_16_);
	cppVar_53675 = ROM.rd(cppVar_53674);
	cppVar_53677 = (cppVar_53675 == 240);
	if (cppVar_53677) {
	cppVar_53673 = B;
	} else {
	cppVar_53673 = 0;
	}
	cppVar_53668 = cppVar_53673;
	}
	cppVar_53663 = cppVar_53668;
	}
	cppVar_53658 = cppVar_53663;
	}
	cppVar_53653 = cppVar_53658;
	}
	cppVar_53648 = cppVar_53653;
	}
	cppVar_53643 = cppVar_53648;
	}
	cppVar_53638 = cppVar_53643;
	}
	cppVar_53633 = cppVar_53638;
	}
	cppVar_53628 = cppVar_53633;
	}
	cppVar_53623 = cppVar_53628;
	}
	cppVar_53618 = cppVar_53623;
	}
	cppVar_53613 = cppVar_53618;
	}
	cppVar_53608 = cppVar_53613;
	}
	cppVar_53603 = cppVar_53608;
	}
	cppVar_53598 = cppVar_53603;
	}
	cppVar_53593 = cppVar_53598;
	}
	cppVar_53588 = cppVar_53593;
	}
	cppVar_53583 = cppVar_53588;
	}
	cppVar_53578 = cppVar_53583;
	}
	cppVar_53573 = cppVar_53578;
	}
	cppVar_53564 = cppVar_53573;
	}
	cppVar_53679 = cppVar_53564 ^ ACC;
	cppVar_53558 = cppVar_53679;
	} else {
	cppVar_53558 = PSW;
	}
	cppVar_53554 = cppVar_53558;
	} else {
	cppVar_53681 = ROM.rd(PC);
	cppVar_53683 = (cppVar_53681 == 83);
	if (cppVar_53683) {
	cppVar_53686 = PC + 1;
	cppVar_53686 = (cppVar_53686 & cppMask_un_16_);
	cppVar_53687 = ROM.rd(cppVar_53686);
	cppVar_53689 = (cppVar_53687 == 208);
	if (cppVar_53689) {
	cppVar_53691 = PC + 1;
	cppVar_53691 = (cppVar_53691 & cppMask_un_16_);
	cppVar_53692 = ROM.rd(cppVar_53691);
	cppVar_53693 = (cppVar_53692 >> 7) & cppMask_un_1_;
	cppVar_53695 = (cppVar_53693 == 0);
	if (cppVar_53695) {
	cppVar_53696 = PC + 1;
	cppVar_53696 = (cppVar_53696 & cppMask_un_16_);
	cppVar_53697 = ROM.rd(cppVar_53696);
	cppVar_53698 = IRAM.rd(cppVar_53697);
	cppVar_53690 = cppVar_53698;
	} else {
	cppVar_53700 = PC + 1;
	cppVar_53700 = (cppVar_53700 & cppMask_un_16_);
	cppVar_53701 = ROM.rd(cppVar_53700);
	cppVar_53703 = (cppVar_53701 == 128);
	if (cppVar_53703) {
	cppVar_53699 = P0;
	} else {
	cppVar_53705 = PC + 1;
	cppVar_53705 = (cppVar_53705 & cppMask_un_16_);
	cppVar_53706 = ROM.rd(cppVar_53705);
	cppVar_53708 = (cppVar_53706 == 129);
	if (cppVar_53708) {
	cppVar_53704 = SP;
	} else {
	cppVar_53710 = PC + 1;
	cppVar_53710 = (cppVar_53710 & cppMask_un_16_);
	cppVar_53711 = ROM.rd(cppVar_53710);
	cppVar_53713 = (cppVar_53711 == 130);
	if (cppVar_53713) {
	cppVar_53709 = DPL;
	} else {
	cppVar_53715 = PC + 1;
	cppVar_53715 = (cppVar_53715 & cppMask_un_16_);
	cppVar_53716 = ROM.rd(cppVar_53715);
	cppVar_53718 = (cppVar_53716 == 131);
	if (cppVar_53718) {
	cppVar_53714 = DPH;
	} else {
	cppVar_53720 = PC + 1;
	cppVar_53720 = (cppVar_53720 & cppMask_un_16_);
	cppVar_53721 = ROM.rd(cppVar_53720);
	cppVar_53723 = (cppVar_53721 == 135);
	if (cppVar_53723) {
	cppVar_53719 = PCON;
	} else {
	cppVar_53725 = PC + 1;
	cppVar_53725 = (cppVar_53725 & cppMask_un_16_);
	cppVar_53726 = ROM.rd(cppVar_53725);
	cppVar_53728 = (cppVar_53726 == 136);
	if (cppVar_53728) {
	cppVar_53724 = TCON;
	} else {
	cppVar_53730 = PC + 1;
	cppVar_53730 = (cppVar_53730 & cppMask_un_16_);
	cppVar_53731 = ROM.rd(cppVar_53730);
	cppVar_53733 = (cppVar_53731 == 137);
	if (cppVar_53733) {
	cppVar_53729 = TMOD;
	} else {
	cppVar_53735 = PC + 1;
	cppVar_53735 = (cppVar_53735 & cppMask_un_16_);
	cppVar_53736 = ROM.rd(cppVar_53735);
	cppVar_53738 = (cppVar_53736 == 138);
	if (cppVar_53738) {
	cppVar_53734 = TL0;
	} else {
	cppVar_53740 = PC + 1;
	cppVar_53740 = (cppVar_53740 & cppMask_un_16_);
	cppVar_53741 = ROM.rd(cppVar_53740);
	cppVar_53743 = (cppVar_53741 == 140);
	if (cppVar_53743) {
	cppVar_53739 = TH0;
	} else {
	cppVar_53745 = PC + 1;
	cppVar_53745 = (cppVar_53745 & cppMask_un_16_);
	cppVar_53746 = ROM.rd(cppVar_53745);
	cppVar_53748 = (cppVar_53746 == 139);
	if (cppVar_53748) {
	cppVar_53744 = TL1;
	} else {
	cppVar_53750 = PC + 1;
	cppVar_53750 = (cppVar_53750 & cppMask_un_16_);
	cppVar_53751 = ROM.rd(cppVar_53750);
	cppVar_53753 = (cppVar_53751 == 141);
	if (cppVar_53753) {
	cppVar_53749 = TH1;
	} else {
	cppVar_53755 = PC + 1;
	cppVar_53755 = (cppVar_53755 & cppMask_un_16_);
	cppVar_53756 = ROM.rd(cppVar_53755);
	cppVar_53758 = (cppVar_53756 == 144);
	if (cppVar_53758) {
	cppVar_53754 = P1;
	} else {
	cppVar_53760 = PC + 1;
	cppVar_53760 = (cppVar_53760 & cppMask_un_16_);
	cppVar_53761 = ROM.rd(cppVar_53760);
	cppVar_53763 = (cppVar_53761 == 152);
	if (cppVar_53763) {
	cppVar_53759 = SCON;
	} else {
	cppVar_53765 = PC + 1;
	cppVar_53765 = (cppVar_53765 & cppMask_un_16_);
	cppVar_53766 = ROM.rd(cppVar_53765);
	cppVar_53768 = (cppVar_53766 == 153);
	if (cppVar_53768) {
	cppVar_53764 = SBUF;
	} else {
	cppVar_53770 = PC + 1;
	cppVar_53770 = (cppVar_53770 & cppMask_un_16_);
	cppVar_53771 = ROM.rd(cppVar_53770);
	cppVar_53773 = (cppVar_53771 == 160);
	if (cppVar_53773) {
	cppVar_53769 = P2;
	} else {
	cppVar_53775 = PC + 1;
	cppVar_53775 = (cppVar_53775 & cppMask_un_16_);
	cppVar_53776 = ROM.rd(cppVar_53775);
	cppVar_53778 = (cppVar_53776 == 168);
	if (cppVar_53778) {
	cppVar_53774 = IE;
	} else {
	cppVar_53780 = PC + 1;
	cppVar_53780 = (cppVar_53780 & cppMask_un_16_);
	cppVar_53781 = ROM.rd(cppVar_53780);
	cppVar_53783 = (cppVar_53781 == 176);
	if (cppVar_53783) {
	cppVar_53779 = P3;
	} else {
	cppVar_53785 = PC + 1;
	cppVar_53785 = (cppVar_53785 & cppMask_un_16_);
	cppVar_53786 = ROM.rd(cppVar_53785);
	cppVar_53788 = (cppVar_53786 == 184);
	if (cppVar_53788) {
	cppVar_53784 = IP;
	} else {
	cppVar_53790 = PC + 1;
	cppVar_53790 = (cppVar_53790 & cppMask_un_16_);
	cppVar_53791 = ROM.rd(cppVar_53790);
	cppVar_53793 = (cppVar_53791 == 208);
	if (cppVar_53793) {
	cppVar_53789 = PSW;
	} else {
	cppVar_53795 = PC + 1;
	cppVar_53795 = (cppVar_53795 & cppMask_un_16_);
	cppVar_53796 = ROM.rd(cppVar_53795);
	cppVar_53798 = (cppVar_53796 == 224);
	if (cppVar_53798) {
	cppVar_53794 = ACC;
	} else {
	cppVar_53800 = PC + 1;
	cppVar_53800 = (cppVar_53800 & cppMask_un_16_);
	cppVar_53801 = ROM.rd(cppVar_53800);
	cppVar_53803 = (cppVar_53801 == 240);
	if (cppVar_53803) {
	cppVar_53799 = B;
	} else {
	cppVar_53799 = 0;
	}
	cppVar_53794 = cppVar_53799;
	}
	cppVar_53789 = cppVar_53794;
	}
	cppVar_53784 = cppVar_53789;
	}
	cppVar_53779 = cppVar_53784;
	}
	cppVar_53774 = cppVar_53779;
	}
	cppVar_53769 = cppVar_53774;
	}
	cppVar_53764 = cppVar_53769;
	}
	cppVar_53759 = cppVar_53764;
	}
	cppVar_53754 = cppVar_53759;
	}
	cppVar_53749 = cppVar_53754;
	}
	cppVar_53744 = cppVar_53749;
	}
	cppVar_53739 = cppVar_53744;
	}
	cppVar_53734 = cppVar_53739;
	}
	cppVar_53729 = cppVar_53734;
	}
	cppVar_53724 = cppVar_53729;
	}
	cppVar_53719 = cppVar_53724;
	}
	cppVar_53714 = cppVar_53719;
	}
	cppVar_53709 = cppVar_53714;
	}
	cppVar_53704 = cppVar_53709;
	}
	cppVar_53699 = cppVar_53704;
	}
	cppVar_53690 = cppVar_53699;
	}
	cppVar_53806 = PC + 2;
	cppVar_53806 = (cppVar_53806 & cppMask_un_16_);
	cppVar_53807 = ROM.rd(cppVar_53806);
	cppVar_53808 = cppVar_53690 & cppVar_53807;
	cppVar_53684 = cppVar_53808;
	} else {
	cppVar_53684 = PSW;
	}
	cppVar_53680 = cppVar_53684;
	} else {
	cppVar_53810 = ROM.rd(PC);
	cppVar_53812 = (cppVar_53810 == 82);
	if (cppVar_53812) {
	cppVar_53815 = PC + 1;
	cppVar_53815 = (cppVar_53815 & cppMask_un_16_);
	cppVar_53816 = ROM.rd(cppVar_53815);
	cppVar_53818 = (cppVar_53816 == 208);
	if (cppVar_53818) {
	cppVar_53820 = PC + 1;
	cppVar_53820 = (cppVar_53820 & cppMask_un_16_);
	cppVar_53821 = ROM.rd(cppVar_53820);
	cppVar_53822 = (cppVar_53821 >> 7) & cppMask_un_1_;
	cppVar_53824 = (cppVar_53822 == 0);
	if (cppVar_53824) {
	cppVar_53825 = PC + 1;
	cppVar_53825 = (cppVar_53825 & cppMask_un_16_);
	cppVar_53826 = ROM.rd(cppVar_53825);
	cppVar_53827 = IRAM.rd(cppVar_53826);
	cppVar_53819 = cppVar_53827;
	} else {
	cppVar_53829 = PC + 1;
	cppVar_53829 = (cppVar_53829 & cppMask_un_16_);
	cppVar_53830 = ROM.rd(cppVar_53829);
	cppVar_53832 = (cppVar_53830 == 128);
	if (cppVar_53832) {
	cppVar_53828 = P0;
	} else {
	cppVar_53834 = PC + 1;
	cppVar_53834 = (cppVar_53834 & cppMask_un_16_);
	cppVar_53835 = ROM.rd(cppVar_53834);
	cppVar_53837 = (cppVar_53835 == 129);
	if (cppVar_53837) {
	cppVar_53833 = SP;
	} else {
	cppVar_53839 = PC + 1;
	cppVar_53839 = (cppVar_53839 & cppMask_un_16_);
	cppVar_53840 = ROM.rd(cppVar_53839);
	cppVar_53842 = (cppVar_53840 == 130);
	if (cppVar_53842) {
	cppVar_53838 = DPL;
	} else {
	cppVar_53844 = PC + 1;
	cppVar_53844 = (cppVar_53844 & cppMask_un_16_);
	cppVar_53845 = ROM.rd(cppVar_53844);
	cppVar_53847 = (cppVar_53845 == 131);
	if (cppVar_53847) {
	cppVar_53843 = DPH;
	} else {
	cppVar_53849 = PC + 1;
	cppVar_53849 = (cppVar_53849 & cppMask_un_16_);
	cppVar_53850 = ROM.rd(cppVar_53849);
	cppVar_53852 = (cppVar_53850 == 135);
	if (cppVar_53852) {
	cppVar_53848 = PCON;
	} else {
	cppVar_53854 = PC + 1;
	cppVar_53854 = (cppVar_53854 & cppMask_un_16_);
	cppVar_53855 = ROM.rd(cppVar_53854);
	cppVar_53857 = (cppVar_53855 == 136);
	if (cppVar_53857) {
	cppVar_53853 = TCON;
	} else {
	cppVar_53859 = PC + 1;
	cppVar_53859 = (cppVar_53859 & cppMask_un_16_);
	cppVar_53860 = ROM.rd(cppVar_53859);
	cppVar_53862 = (cppVar_53860 == 137);
	if (cppVar_53862) {
	cppVar_53858 = TMOD;
	} else {
	cppVar_53864 = PC + 1;
	cppVar_53864 = (cppVar_53864 & cppMask_un_16_);
	cppVar_53865 = ROM.rd(cppVar_53864);
	cppVar_53867 = (cppVar_53865 == 138);
	if (cppVar_53867) {
	cppVar_53863 = TL0;
	} else {
	cppVar_53869 = PC + 1;
	cppVar_53869 = (cppVar_53869 & cppMask_un_16_);
	cppVar_53870 = ROM.rd(cppVar_53869);
	cppVar_53872 = (cppVar_53870 == 140);
	if (cppVar_53872) {
	cppVar_53868 = TH0;
	} else {
	cppVar_53874 = PC + 1;
	cppVar_53874 = (cppVar_53874 & cppMask_un_16_);
	cppVar_53875 = ROM.rd(cppVar_53874);
	cppVar_53877 = (cppVar_53875 == 139);
	if (cppVar_53877) {
	cppVar_53873 = TL1;
	} else {
	cppVar_53879 = PC + 1;
	cppVar_53879 = (cppVar_53879 & cppMask_un_16_);
	cppVar_53880 = ROM.rd(cppVar_53879);
	cppVar_53882 = (cppVar_53880 == 141);
	if (cppVar_53882) {
	cppVar_53878 = TH1;
	} else {
	cppVar_53884 = PC + 1;
	cppVar_53884 = (cppVar_53884 & cppMask_un_16_);
	cppVar_53885 = ROM.rd(cppVar_53884);
	cppVar_53887 = (cppVar_53885 == 144);
	if (cppVar_53887) {
	cppVar_53883 = P1;
	} else {
	cppVar_53889 = PC + 1;
	cppVar_53889 = (cppVar_53889 & cppMask_un_16_);
	cppVar_53890 = ROM.rd(cppVar_53889);
	cppVar_53892 = (cppVar_53890 == 152);
	if (cppVar_53892) {
	cppVar_53888 = SCON;
	} else {
	cppVar_53894 = PC + 1;
	cppVar_53894 = (cppVar_53894 & cppMask_un_16_);
	cppVar_53895 = ROM.rd(cppVar_53894);
	cppVar_53897 = (cppVar_53895 == 153);
	if (cppVar_53897) {
	cppVar_53893 = SBUF;
	} else {
	cppVar_53899 = PC + 1;
	cppVar_53899 = (cppVar_53899 & cppMask_un_16_);
	cppVar_53900 = ROM.rd(cppVar_53899);
	cppVar_53902 = (cppVar_53900 == 160);
	if (cppVar_53902) {
	cppVar_53898 = P2;
	} else {
	cppVar_53904 = PC + 1;
	cppVar_53904 = (cppVar_53904 & cppMask_un_16_);
	cppVar_53905 = ROM.rd(cppVar_53904);
	cppVar_53907 = (cppVar_53905 == 168);
	if (cppVar_53907) {
	cppVar_53903 = IE;
	} else {
	cppVar_53909 = PC + 1;
	cppVar_53909 = (cppVar_53909 & cppMask_un_16_);
	cppVar_53910 = ROM.rd(cppVar_53909);
	cppVar_53912 = (cppVar_53910 == 176);
	if (cppVar_53912) {
	cppVar_53908 = P3;
	} else {
	cppVar_53914 = PC + 1;
	cppVar_53914 = (cppVar_53914 & cppMask_un_16_);
	cppVar_53915 = ROM.rd(cppVar_53914);
	cppVar_53917 = (cppVar_53915 == 184);
	if (cppVar_53917) {
	cppVar_53913 = IP;
	} else {
	cppVar_53919 = PC + 1;
	cppVar_53919 = (cppVar_53919 & cppMask_un_16_);
	cppVar_53920 = ROM.rd(cppVar_53919);
	cppVar_53922 = (cppVar_53920 == 208);
	if (cppVar_53922) {
	cppVar_53918 = PSW;
	} else {
	cppVar_53924 = PC + 1;
	cppVar_53924 = (cppVar_53924 & cppMask_un_16_);
	cppVar_53925 = ROM.rd(cppVar_53924);
	cppVar_53927 = (cppVar_53925 == 224);
	if (cppVar_53927) {
	cppVar_53923 = ACC;
	} else {
	cppVar_53929 = PC + 1;
	cppVar_53929 = (cppVar_53929 & cppMask_un_16_);
	cppVar_53930 = ROM.rd(cppVar_53929);
	cppVar_53932 = (cppVar_53930 == 240);
	if (cppVar_53932) {
	cppVar_53928 = B;
	} else {
	cppVar_53928 = 0;
	}
	cppVar_53923 = cppVar_53928;
	}
	cppVar_53918 = cppVar_53923;
	}
	cppVar_53913 = cppVar_53918;
	}
	cppVar_53908 = cppVar_53913;
	}
	cppVar_53903 = cppVar_53908;
	}
	cppVar_53898 = cppVar_53903;
	}
	cppVar_53893 = cppVar_53898;
	}
	cppVar_53888 = cppVar_53893;
	}
	cppVar_53883 = cppVar_53888;
	}
	cppVar_53878 = cppVar_53883;
	}
	cppVar_53873 = cppVar_53878;
	}
	cppVar_53868 = cppVar_53873;
	}
	cppVar_53863 = cppVar_53868;
	}
	cppVar_53858 = cppVar_53863;
	}
	cppVar_53853 = cppVar_53858;
	}
	cppVar_53848 = cppVar_53853;
	}
	cppVar_53843 = cppVar_53848;
	}
	cppVar_53838 = cppVar_53843;
	}
	cppVar_53833 = cppVar_53838;
	}
	cppVar_53828 = cppVar_53833;
	}
	cppVar_53819 = cppVar_53828;
	}
	cppVar_53934 = cppVar_53819 & ACC;
	cppVar_53813 = cppVar_53934;
	} else {
	cppVar_53813 = PSW;
	}
	cppVar_53809 = cppVar_53813;
	} else {
	cppVar_53936 = ROM.rd(PC);
	cppVar_53938 = (cppVar_53936 == 67);
	if (cppVar_53938) {
	cppVar_53941 = PC + 1;
	cppVar_53941 = (cppVar_53941 & cppMask_un_16_);
	cppVar_53942 = ROM.rd(cppVar_53941);
	cppVar_53944 = (cppVar_53942 == 208);
	if (cppVar_53944) {
	cppVar_53946 = PC + 1;
	cppVar_53946 = (cppVar_53946 & cppMask_un_16_);
	cppVar_53947 = ROM.rd(cppVar_53946);
	cppVar_53948 = (cppVar_53947 >> 7) & cppMask_un_1_;
	cppVar_53950 = (cppVar_53948 == 0);
	if (cppVar_53950) {
	cppVar_53951 = PC + 1;
	cppVar_53951 = (cppVar_53951 & cppMask_un_16_);
	cppVar_53952 = ROM.rd(cppVar_53951);
	cppVar_53953 = IRAM.rd(cppVar_53952);
	cppVar_53945 = cppVar_53953;
	} else {
	cppVar_53955 = PC + 1;
	cppVar_53955 = (cppVar_53955 & cppMask_un_16_);
	cppVar_53956 = ROM.rd(cppVar_53955);
	cppVar_53958 = (cppVar_53956 == 128);
	if (cppVar_53958) {
	cppVar_53954 = P0;
	} else {
	cppVar_53960 = PC + 1;
	cppVar_53960 = (cppVar_53960 & cppMask_un_16_);
	cppVar_53961 = ROM.rd(cppVar_53960);
	cppVar_53963 = (cppVar_53961 == 129);
	if (cppVar_53963) {
	cppVar_53959 = SP;
	} else {
	cppVar_53965 = PC + 1;
	cppVar_53965 = (cppVar_53965 & cppMask_un_16_);
	cppVar_53966 = ROM.rd(cppVar_53965);
	cppVar_53968 = (cppVar_53966 == 130);
	if (cppVar_53968) {
	cppVar_53964 = DPL;
	} else {
	cppVar_53970 = PC + 1;
	cppVar_53970 = (cppVar_53970 & cppMask_un_16_);
	cppVar_53971 = ROM.rd(cppVar_53970);
	cppVar_53973 = (cppVar_53971 == 131);
	if (cppVar_53973) {
	cppVar_53969 = DPH;
	} else {
	cppVar_53975 = PC + 1;
	cppVar_53975 = (cppVar_53975 & cppMask_un_16_);
	cppVar_53976 = ROM.rd(cppVar_53975);
	cppVar_53978 = (cppVar_53976 == 135);
	if (cppVar_53978) {
	cppVar_53974 = PCON;
	} else {
	cppVar_53980 = PC + 1;
	cppVar_53980 = (cppVar_53980 & cppMask_un_16_);
	cppVar_53981 = ROM.rd(cppVar_53980);
	cppVar_53983 = (cppVar_53981 == 136);
	if (cppVar_53983) {
	cppVar_53979 = TCON;
	} else {
	cppVar_53985 = PC + 1;
	cppVar_53985 = (cppVar_53985 & cppMask_un_16_);
	cppVar_53986 = ROM.rd(cppVar_53985);
	cppVar_53988 = (cppVar_53986 == 137);
	if (cppVar_53988) {
	cppVar_53984 = TMOD;
	} else {
	cppVar_53990 = PC + 1;
	cppVar_53990 = (cppVar_53990 & cppMask_un_16_);
	cppVar_53991 = ROM.rd(cppVar_53990);
	cppVar_53993 = (cppVar_53991 == 138);
	if (cppVar_53993) {
	cppVar_53989 = TL0;
	} else {
	cppVar_53995 = PC + 1;
	cppVar_53995 = (cppVar_53995 & cppMask_un_16_);
	cppVar_53996 = ROM.rd(cppVar_53995);
	cppVar_53998 = (cppVar_53996 == 140);
	if (cppVar_53998) {
	cppVar_53994 = TH0;
	} else {
	cppVar_54000 = PC + 1;
	cppVar_54000 = (cppVar_54000 & cppMask_un_16_);
	cppVar_54001 = ROM.rd(cppVar_54000);
	cppVar_54003 = (cppVar_54001 == 139);
	if (cppVar_54003) {
	cppVar_53999 = TL1;
	} else {
	cppVar_54005 = PC + 1;
	cppVar_54005 = (cppVar_54005 & cppMask_un_16_);
	cppVar_54006 = ROM.rd(cppVar_54005);
	cppVar_54008 = (cppVar_54006 == 141);
	if (cppVar_54008) {
	cppVar_54004 = TH1;
	} else {
	cppVar_54010 = PC + 1;
	cppVar_54010 = (cppVar_54010 & cppMask_un_16_);
	cppVar_54011 = ROM.rd(cppVar_54010);
	cppVar_54013 = (cppVar_54011 == 144);
	if (cppVar_54013) {
	cppVar_54009 = P1;
	} else {
	cppVar_54015 = PC + 1;
	cppVar_54015 = (cppVar_54015 & cppMask_un_16_);
	cppVar_54016 = ROM.rd(cppVar_54015);
	cppVar_54018 = (cppVar_54016 == 152);
	if (cppVar_54018) {
	cppVar_54014 = SCON;
	} else {
	cppVar_54020 = PC + 1;
	cppVar_54020 = (cppVar_54020 & cppMask_un_16_);
	cppVar_54021 = ROM.rd(cppVar_54020);
	cppVar_54023 = (cppVar_54021 == 153);
	if (cppVar_54023) {
	cppVar_54019 = SBUF;
	} else {
	cppVar_54025 = PC + 1;
	cppVar_54025 = (cppVar_54025 & cppMask_un_16_);
	cppVar_54026 = ROM.rd(cppVar_54025);
	cppVar_54028 = (cppVar_54026 == 160);
	if (cppVar_54028) {
	cppVar_54024 = P2;
	} else {
	cppVar_54030 = PC + 1;
	cppVar_54030 = (cppVar_54030 & cppMask_un_16_);
	cppVar_54031 = ROM.rd(cppVar_54030);
	cppVar_54033 = (cppVar_54031 == 168);
	if (cppVar_54033) {
	cppVar_54029 = IE;
	} else {
	cppVar_54035 = PC + 1;
	cppVar_54035 = (cppVar_54035 & cppMask_un_16_);
	cppVar_54036 = ROM.rd(cppVar_54035);
	cppVar_54038 = (cppVar_54036 == 176);
	if (cppVar_54038) {
	cppVar_54034 = P3;
	} else {
	cppVar_54040 = PC + 1;
	cppVar_54040 = (cppVar_54040 & cppMask_un_16_);
	cppVar_54041 = ROM.rd(cppVar_54040);
	cppVar_54043 = (cppVar_54041 == 184);
	if (cppVar_54043) {
	cppVar_54039 = IP;
	} else {
	cppVar_54045 = PC + 1;
	cppVar_54045 = (cppVar_54045 & cppMask_un_16_);
	cppVar_54046 = ROM.rd(cppVar_54045);
	cppVar_54048 = (cppVar_54046 == 208);
	if (cppVar_54048) {
	cppVar_54044 = PSW;
	} else {
	cppVar_54050 = PC + 1;
	cppVar_54050 = (cppVar_54050 & cppMask_un_16_);
	cppVar_54051 = ROM.rd(cppVar_54050);
	cppVar_54053 = (cppVar_54051 == 224);
	if (cppVar_54053) {
	cppVar_54049 = ACC;
	} else {
	cppVar_54055 = PC + 1;
	cppVar_54055 = (cppVar_54055 & cppMask_un_16_);
	cppVar_54056 = ROM.rd(cppVar_54055);
	cppVar_54058 = (cppVar_54056 == 240);
	if (cppVar_54058) {
	cppVar_54054 = B;
	} else {
	cppVar_54054 = 0;
	}
	cppVar_54049 = cppVar_54054;
	}
	cppVar_54044 = cppVar_54049;
	}
	cppVar_54039 = cppVar_54044;
	}
	cppVar_54034 = cppVar_54039;
	}
	cppVar_54029 = cppVar_54034;
	}
	cppVar_54024 = cppVar_54029;
	}
	cppVar_54019 = cppVar_54024;
	}
	cppVar_54014 = cppVar_54019;
	}
	cppVar_54009 = cppVar_54014;
	}
	cppVar_54004 = cppVar_54009;
	}
	cppVar_53999 = cppVar_54004;
	}
	cppVar_53994 = cppVar_53999;
	}
	cppVar_53989 = cppVar_53994;
	}
	cppVar_53984 = cppVar_53989;
	}
	cppVar_53979 = cppVar_53984;
	}
	cppVar_53974 = cppVar_53979;
	}
	cppVar_53969 = cppVar_53974;
	}
	cppVar_53964 = cppVar_53969;
	}
	cppVar_53959 = cppVar_53964;
	}
	cppVar_53954 = cppVar_53959;
	}
	cppVar_53945 = cppVar_53954;
	}
	cppVar_54061 = PC + 2;
	cppVar_54061 = (cppVar_54061 & cppMask_un_16_);
	cppVar_54062 = ROM.rd(cppVar_54061);
	cppVar_54063 = cppVar_53945 | cppVar_54062;
	cppVar_53939 = cppVar_54063;
	} else {
	cppVar_53939 = PSW;
	}
	cppVar_53935 = cppVar_53939;
	} else {
	cppVar_54065 = ROM.rd(PC);
	cppVar_54067 = (cppVar_54065 == 66);
	if (cppVar_54067) {
	cppVar_54070 = PC + 1;
	cppVar_54070 = (cppVar_54070 & cppMask_un_16_);
	cppVar_54071 = ROM.rd(cppVar_54070);
	cppVar_54073 = (cppVar_54071 == 208);
	if (cppVar_54073) {
	cppVar_54075 = PC + 1;
	cppVar_54075 = (cppVar_54075 & cppMask_un_16_);
	cppVar_54076 = ROM.rd(cppVar_54075);
	cppVar_54077 = (cppVar_54076 >> 7) & cppMask_un_1_;
	cppVar_54079 = (cppVar_54077 == 0);
	if (cppVar_54079) {
	cppVar_54080 = PC + 1;
	cppVar_54080 = (cppVar_54080 & cppMask_un_16_);
	cppVar_54081 = ROM.rd(cppVar_54080);
	cppVar_54082 = IRAM.rd(cppVar_54081);
	cppVar_54074 = cppVar_54082;
	} else {
	cppVar_54084 = PC + 1;
	cppVar_54084 = (cppVar_54084 & cppMask_un_16_);
	cppVar_54085 = ROM.rd(cppVar_54084);
	cppVar_54087 = (cppVar_54085 == 128);
	if (cppVar_54087) {
	cppVar_54083 = P0;
	} else {
	cppVar_54089 = PC + 1;
	cppVar_54089 = (cppVar_54089 & cppMask_un_16_);
	cppVar_54090 = ROM.rd(cppVar_54089);
	cppVar_54092 = (cppVar_54090 == 129);
	if (cppVar_54092) {
	cppVar_54088 = SP;
	} else {
	cppVar_54094 = PC + 1;
	cppVar_54094 = (cppVar_54094 & cppMask_un_16_);
	cppVar_54095 = ROM.rd(cppVar_54094);
	cppVar_54097 = (cppVar_54095 == 130);
	if (cppVar_54097) {
	cppVar_54093 = DPL;
	} else {
	cppVar_54099 = PC + 1;
	cppVar_54099 = (cppVar_54099 & cppMask_un_16_);
	cppVar_54100 = ROM.rd(cppVar_54099);
	cppVar_54102 = (cppVar_54100 == 131);
	if (cppVar_54102) {
	cppVar_54098 = DPH;
	} else {
	cppVar_54104 = PC + 1;
	cppVar_54104 = (cppVar_54104 & cppMask_un_16_);
	cppVar_54105 = ROM.rd(cppVar_54104);
	cppVar_54107 = (cppVar_54105 == 135);
	if (cppVar_54107) {
	cppVar_54103 = PCON;
	} else {
	cppVar_54109 = PC + 1;
	cppVar_54109 = (cppVar_54109 & cppMask_un_16_);
	cppVar_54110 = ROM.rd(cppVar_54109);
	cppVar_54112 = (cppVar_54110 == 136);
	if (cppVar_54112) {
	cppVar_54108 = TCON;
	} else {
	cppVar_54114 = PC + 1;
	cppVar_54114 = (cppVar_54114 & cppMask_un_16_);
	cppVar_54115 = ROM.rd(cppVar_54114);
	cppVar_54117 = (cppVar_54115 == 137);
	if (cppVar_54117) {
	cppVar_54113 = TMOD;
	} else {
	cppVar_54119 = PC + 1;
	cppVar_54119 = (cppVar_54119 & cppMask_un_16_);
	cppVar_54120 = ROM.rd(cppVar_54119);
	cppVar_54122 = (cppVar_54120 == 138);
	if (cppVar_54122) {
	cppVar_54118 = TL0;
	} else {
	cppVar_54124 = PC + 1;
	cppVar_54124 = (cppVar_54124 & cppMask_un_16_);
	cppVar_54125 = ROM.rd(cppVar_54124);
	cppVar_54127 = (cppVar_54125 == 140);
	if (cppVar_54127) {
	cppVar_54123 = TH0;
	} else {
	cppVar_54129 = PC + 1;
	cppVar_54129 = (cppVar_54129 & cppMask_un_16_);
	cppVar_54130 = ROM.rd(cppVar_54129);
	cppVar_54132 = (cppVar_54130 == 139);
	if (cppVar_54132) {
	cppVar_54128 = TL1;
	} else {
	cppVar_54134 = PC + 1;
	cppVar_54134 = (cppVar_54134 & cppMask_un_16_);
	cppVar_54135 = ROM.rd(cppVar_54134);
	cppVar_54137 = (cppVar_54135 == 141);
	if (cppVar_54137) {
	cppVar_54133 = TH1;
	} else {
	cppVar_54139 = PC + 1;
	cppVar_54139 = (cppVar_54139 & cppMask_un_16_);
	cppVar_54140 = ROM.rd(cppVar_54139);
	cppVar_54142 = (cppVar_54140 == 144);
	if (cppVar_54142) {
	cppVar_54138 = P1;
	} else {
	cppVar_54144 = PC + 1;
	cppVar_54144 = (cppVar_54144 & cppMask_un_16_);
	cppVar_54145 = ROM.rd(cppVar_54144);
	cppVar_54147 = (cppVar_54145 == 152);
	if (cppVar_54147) {
	cppVar_54143 = SCON;
	} else {
	cppVar_54149 = PC + 1;
	cppVar_54149 = (cppVar_54149 & cppMask_un_16_);
	cppVar_54150 = ROM.rd(cppVar_54149);
	cppVar_54152 = (cppVar_54150 == 153);
	if (cppVar_54152) {
	cppVar_54148 = SBUF;
	} else {
	cppVar_54154 = PC + 1;
	cppVar_54154 = (cppVar_54154 & cppMask_un_16_);
	cppVar_54155 = ROM.rd(cppVar_54154);
	cppVar_54157 = (cppVar_54155 == 160);
	if (cppVar_54157) {
	cppVar_54153 = P2;
	} else {
	cppVar_54159 = PC + 1;
	cppVar_54159 = (cppVar_54159 & cppMask_un_16_);
	cppVar_54160 = ROM.rd(cppVar_54159);
	cppVar_54162 = (cppVar_54160 == 168);
	if (cppVar_54162) {
	cppVar_54158 = IE;
	} else {
	cppVar_54164 = PC + 1;
	cppVar_54164 = (cppVar_54164 & cppMask_un_16_);
	cppVar_54165 = ROM.rd(cppVar_54164);
	cppVar_54167 = (cppVar_54165 == 176);
	if (cppVar_54167) {
	cppVar_54163 = P3;
	} else {
	cppVar_54169 = PC + 1;
	cppVar_54169 = (cppVar_54169 & cppMask_un_16_);
	cppVar_54170 = ROM.rd(cppVar_54169);
	cppVar_54172 = (cppVar_54170 == 184);
	if (cppVar_54172) {
	cppVar_54168 = IP;
	} else {
	cppVar_54174 = PC + 1;
	cppVar_54174 = (cppVar_54174 & cppMask_un_16_);
	cppVar_54175 = ROM.rd(cppVar_54174);
	cppVar_54177 = (cppVar_54175 == 208);
	if (cppVar_54177) {
	cppVar_54173 = PSW;
	} else {
	cppVar_54179 = PC + 1;
	cppVar_54179 = (cppVar_54179 & cppMask_un_16_);
	cppVar_54180 = ROM.rd(cppVar_54179);
	cppVar_54182 = (cppVar_54180 == 224);
	if (cppVar_54182) {
	cppVar_54178 = ACC;
	} else {
	cppVar_54184 = PC + 1;
	cppVar_54184 = (cppVar_54184 & cppMask_un_16_);
	cppVar_54185 = ROM.rd(cppVar_54184);
	cppVar_54187 = (cppVar_54185 == 240);
	if (cppVar_54187) {
	cppVar_54183 = B;
	} else {
	cppVar_54183 = 0;
	}
	cppVar_54178 = cppVar_54183;
	}
	cppVar_54173 = cppVar_54178;
	}
	cppVar_54168 = cppVar_54173;
	}
	cppVar_54163 = cppVar_54168;
	}
	cppVar_54158 = cppVar_54163;
	}
	cppVar_54153 = cppVar_54158;
	}
	cppVar_54148 = cppVar_54153;
	}
	cppVar_54143 = cppVar_54148;
	}
	cppVar_54138 = cppVar_54143;
	}
	cppVar_54133 = cppVar_54138;
	}
	cppVar_54128 = cppVar_54133;
	}
	cppVar_54123 = cppVar_54128;
	}
	cppVar_54118 = cppVar_54123;
	}
	cppVar_54113 = cppVar_54118;
	}
	cppVar_54108 = cppVar_54113;
	}
	cppVar_54103 = cppVar_54108;
	}
	cppVar_54098 = cppVar_54103;
	}
	cppVar_54093 = cppVar_54098;
	}
	cppVar_54088 = cppVar_54093;
	}
	cppVar_54083 = cppVar_54088;
	}
	cppVar_54074 = cppVar_54083;
	}
	cppVar_54189 = cppVar_54074 | ACC;
	cppVar_54068 = cppVar_54189;
	} else {
	cppVar_54068 = PSW;
	}
	cppVar_54064 = cppVar_54068;
	} else {
	cppVar_54191 = ROM.rd(PC);
	cppVar_54193 = (cppVar_54191 == 63);
	if (cppVar_54193) {
	cppVar_54194 = (ACC & cppMask_un_8_);
	cppVar_54196 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54198 = (cppVar_54196 << 3) | 7;
	cppVar_54198 = (cppVar_54198 & cppMask_un_5_);
	cppVar_54199 = (0 << 5) | cppVar_54198;
	cppVar_54199 = (cppVar_54199 & cppMask_un_8_);
	cppVar_54200 = IRAM.rd(cppVar_54199);
	cppVar_54201 = (cppVar_54200 & cppMask_un_8_);
	cppVar_54202 = cppVar_54194 + cppVar_54201;
	cppVar_54202 = (cppVar_54202 & cppMask_un_9_);
	cppVar_54203 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54204 = (cppVar_54203 & cppMask_un_1_);
	cppVar_54205 = cppVar_54202 + cppVar_54204;
	cppVar_54205 = (cppVar_54205 & cppMask_un_9_);
	cppVar_54206 = (cppVar_54205 >> 8) & cppMask_un_1_;
	cppVar_54207 = (ACC >> 0) & cppMask_un_4_;
	cppVar_54208 = (cppVar_54207 & cppMask_un_4_);
	cppVar_54209 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54210 = (cppVar_54209 << 3) | 7;
	cppVar_54210 = (cppVar_54210 & cppMask_un_5_);
	cppVar_54211 = (0 << 5) | cppVar_54210;
	cppVar_54211 = (cppVar_54211 & cppMask_un_8_);
	cppVar_54212 = IRAM.rd(cppVar_54211);
	cppVar_54213 = (cppVar_54212 >> 0) & cppMask_un_4_;
	cppVar_54214 = (cppVar_54213 & cppMask_un_4_);
	cppVar_54215 = cppVar_54208 + cppVar_54214;
	cppVar_54215 = (cppVar_54215 & cppMask_un_5_);
	cppVar_54216 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54217 = (cppVar_54216 & cppMask_un_1_);
	cppVar_54218 = cppVar_54215 + cppVar_54217;
	cppVar_54218 = (cppVar_54218 & cppMask_un_5_);
	cppVar_54219 = (cppVar_54218 >> 4) & cppMask_un_1_;
	cppVar_54220 = (PSW >> 3) & cppMask_un_3_;
	cppVar_54222 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54223 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54224 = (cppVar_54223 << 3) | 7;
	cppVar_54224 = (cppVar_54224 & cppMask_un_5_);
	cppVar_54225 = (0 << 5) | cppVar_54224;
	cppVar_54225 = (cppVar_54225 & cppMask_un_8_);
	cppVar_54226 = IRAM.rd(cppVar_54225);
	cppVar_54227 = ((cppVar_54226 & cppMask_bit_8_) ? (cppVar_54226 | cppMask_sign_8_) : cppVar_54226);
	cppVar_54228 = cppVar_54222 + cppVar_54227;
	cppVar_54228 = (cppVar_54228 & cppMask_un_9_);
	cppVar_54229 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54230 = (cppVar_54229 & cppMask_un_1_);
	cppVar_54231 = cppVar_54228 + cppVar_54230;
	cppVar_54231 = (cppVar_54231 & cppMask_un_9_);
	cppVar_54232 = (cppVar_54231 >> 8) & cppMask_un_1_;
	cppVar_54233 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54234 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54235 = (cppVar_54234 << 3) | 7;
	cppVar_54235 = (cppVar_54235 & cppMask_un_5_);
	cppVar_54236 = (0 << 5) | cppVar_54235;
	cppVar_54236 = (cppVar_54236 & cppMask_un_8_);
	cppVar_54237 = IRAM.rd(cppVar_54236);
	cppVar_54238 = ((cppVar_54237 & cppMask_bit_8_) ? (cppVar_54237 | cppMask_sign_8_) : cppVar_54237);
	cppVar_54239 = cppVar_54233 + cppVar_54238;
	cppVar_54239 = (cppVar_54239 & cppMask_un_9_);
	cppVar_54240 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54241 = (cppVar_54240 & cppMask_un_1_);
	cppVar_54242 = cppVar_54239 + cppVar_54241;
	cppVar_54242 = (cppVar_54242 & cppMask_un_9_);
	cppVar_54243 = (cppVar_54242 >> 7) & cppMask_un_1_;
	cppVar_54244 = (cppVar_54232 != cppVar_54243);
	if (cppVar_54244) {
	cppVar_54221 = 1;
	} else {
	cppVar_54221 = 0;
	}
	cppVar_54247 = (PSW >> 0) & cppMask_un_2_;
	cppVar_54248 = (cppVar_54221 << 2) | cppVar_54247;
	cppVar_54248 = (cppVar_54248 & cppMask_un_3_);
	cppVar_54249 = (cppVar_54220 << 3) | cppVar_54248;
	cppVar_54249 = (cppVar_54249 & cppMask_un_6_);
	cppVar_54250 = (cppVar_54219 << 6) | cppVar_54249;
	cppVar_54250 = (cppVar_54250 & cppMask_un_7_);
	cppVar_54251 = (cppVar_54206 << 7) | cppVar_54250;
	cppVar_54251 = (cppVar_54251 & cppMask_un_8_);
	cppVar_54190 = cppVar_54251;
	} else {
	cppVar_54253 = ROM.rd(PC);
	cppVar_54255 = (cppVar_54253 == 62);
	if (cppVar_54255) {
	cppVar_54256 = (ACC & cppMask_un_8_);
	cppVar_54258 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54260 = (cppVar_54258 << 3) | 6;
	cppVar_54260 = (cppVar_54260 & cppMask_un_5_);
	cppVar_54261 = (0 << 5) | cppVar_54260;
	cppVar_54261 = (cppVar_54261 & cppMask_un_8_);
	cppVar_54262 = IRAM.rd(cppVar_54261);
	cppVar_54263 = (cppVar_54262 & cppMask_un_8_);
	cppVar_54264 = cppVar_54256 + cppVar_54263;
	cppVar_54264 = (cppVar_54264 & cppMask_un_9_);
	cppVar_54265 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54266 = (cppVar_54265 & cppMask_un_1_);
	cppVar_54267 = cppVar_54264 + cppVar_54266;
	cppVar_54267 = (cppVar_54267 & cppMask_un_9_);
	cppVar_54268 = (cppVar_54267 >> 8) & cppMask_un_1_;
	cppVar_54269 = (ACC >> 0) & cppMask_un_4_;
	cppVar_54270 = (cppVar_54269 & cppMask_un_4_);
	cppVar_54271 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54272 = (cppVar_54271 << 3) | 6;
	cppVar_54272 = (cppVar_54272 & cppMask_un_5_);
	cppVar_54273 = (0 << 5) | cppVar_54272;
	cppVar_54273 = (cppVar_54273 & cppMask_un_8_);
	cppVar_54274 = IRAM.rd(cppVar_54273);
	cppVar_54275 = (cppVar_54274 >> 0) & cppMask_un_4_;
	cppVar_54276 = (cppVar_54275 & cppMask_un_4_);
	cppVar_54277 = cppVar_54270 + cppVar_54276;
	cppVar_54277 = (cppVar_54277 & cppMask_un_5_);
	cppVar_54278 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54279 = (cppVar_54278 & cppMask_un_1_);
	cppVar_54280 = cppVar_54277 + cppVar_54279;
	cppVar_54280 = (cppVar_54280 & cppMask_un_5_);
	cppVar_54281 = (cppVar_54280 >> 4) & cppMask_un_1_;
	cppVar_54282 = (PSW >> 3) & cppMask_un_3_;
	cppVar_54284 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54285 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54286 = (cppVar_54285 << 3) | 6;
	cppVar_54286 = (cppVar_54286 & cppMask_un_5_);
	cppVar_54287 = (0 << 5) | cppVar_54286;
	cppVar_54287 = (cppVar_54287 & cppMask_un_8_);
	cppVar_54288 = IRAM.rd(cppVar_54287);
	cppVar_54289 = ((cppVar_54288 & cppMask_bit_8_) ? (cppVar_54288 | cppMask_sign_8_) : cppVar_54288);
	cppVar_54290 = cppVar_54284 + cppVar_54289;
	cppVar_54290 = (cppVar_54290 & cppMask_un_9_);
	cppVar_54291 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54292 = (cppVar_54291 & cppMask_un_1_);
	cppVar_54293 = cppVar_54290 + cppVar_54292;
	cppVar_54293 = (cppVar_54293 & cppMask_un_9_);
	cppVar_54294 = (cppVar_54293 >> 8) & cppMask_un_1_;
	cppVar_54295 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54296 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54297 = (cppVar_54296 << 3) | 6;
	cppVar_54297 = (cppVar_54297 & cppMask_un_5_);
	cppVar_54298 = (0 << 5) | cppVar_54297;
	cppVar_54298 = (cppVar_54298 & cppMask_un_8_);
	cppVar_54299 = IRAM.rd(cppVar_54298);
	cppVar_54300 = ((cppVar_54299 & cppMask_bit_8_) ? (cppVar_54299 | cppMask_sign_8_) : cppVar_54299);
	cppVar_54301 = cppVar_54295 + cppVar_54300;
	cppVar_54301 = (cppVar_54301 & cppMask_un_9_);
	cppVar_54302 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54303 = (cppVar_54302 & cppMask_un_1_);
	cppVar_54304 = cppVar_54301 + cppVar_54303;
	cppVar_54304 = (cppVar_54304 & cppMask_un_9_);
	cppVar_54305 = (cppVar_54304 >> 7) & cppMask_un_1_;
	cppVar_54306 = (cppVar_54294 != cppVar_54305);
	if (cppVar_54306) {
	cppVar_54283 = 1;
	} else {
	cppVar_54283 = 0;
	}
	cppVar_54309 = (PSW >> 0) & cppMask_un_2_;
	cppVar_54310 = (cppVar_54283 << 2) | cppVar_54309;
	cppVar_54310 = (cppVar_54310 & cppMask_un_3_);
	cppVar_54311 = (cppVar_54282 << 3) | cppVar_54310;
	cppVar_54311 = (cppVar_54311 & cppMask_un_6_);
	cppVar_54312 = (cppVar_54281 << 6) | cppVar_54311;
	cppVar_54312 = (cppVar_54312 & cppMask_un_7_);
	cppVar_54313 = (cppVar_54268 << 7) | cppVar_54312;
	cppVar_54313 = (cppVar_54313 & cppMask_un_8_);
	cppVar_54252 = cppVar_54313;
	} else {
	cppVar_54315 = ROM.rd(PC);
	cppVar_54317 = (cppVar_54315 == 61);
	if (cppVar_54317) {
	cppVar_54318 = (ACC & cppMask_un_8_);
	cppVar_54320 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54322 = (cppVar_54320 << 3) | 5;
	cppVar_54322 = (cppVar_54322 & cppMask_un_5_);
	cppVar_54323 = (0 << 5) | cppVar_54322;
	cppVar_54323 = (cppVar_54323 & cppMask_un_8_);
	cppVar_54324 = IRAM.rd(cppVar_54323);
	cppVar_54325 = (cppVar_54324 & cppMask_un_8_);
	cppVar_54326 = cppVar_54318 + cppVar_54325;
	cppVar_54326 = (cppVar_54326 & cppMask_un_9_);
	cppVar_54327 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54328 = (cppVar_54327 & cppMask_un_1_);
	cppVar_54329 = cppVar_54326 + cppVar_54328;
	cppVar_54329 = (cppVar_54329 & cppMask_un_9_);
	cppVar_54330 = (cppVar_54329 >> 8) & cppMask_un_1_;
	cppVar_54331 = (ACC >> 0) & cppMask_un_4_;
	cppVar_54332 = (cppVar_54331 & cppMask_un_4_);
	cppVar_54333 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54334 = (cppVar_54333 << 3) | 5;
	cppVar_54334 = (cppVar_54334 & cppMask_un_5_);
	cppVar_54335 = (0 << 5) | cppVar_54334;
	cppVar_54335 = (cppVar_54335 & cppMask_un_8_);
	cppVar_54336 = IRAM.rd(cppVar_54335);
	cppVar_54337 = (cppVar_54336 >> 0) & cppMask_un_4_;
	cppVar_54338 = (cppVar_54337 & cppMask_un_4_);
	cppVar_54339 = cppVar_54332 + cppVar_54338;
	cppVar_54339 = (cppVar_54339 & cppMask_un_5_);
	cppVar_54340 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54341 = (cppVar_54340 & cppMask_un_1_);
	cppVar_54342 = cppVar_54339 + cppVar_54341;
	cppVar_54342 = (cppVar_54342 & cppMask_un_5_);
	cppVar_54343 = (cppVar_54342 >> 4) & cppMask_un_1_;
	cppVar_54344 = (PSW >> 3) & cppMask_un_3_;
	cppVar_54346 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54347 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54348 = (cppVar_54347 << 3) | 5;
	cppVar_54348 = (cppVar_54348 & cppMask_un_5_);
	cppVar_54349 = (0 << 5) | cppVar_54348;
	cppVar_54349 = (cppVar_54349 & cppMask_un_8_);
	cppVar_54350 = IRAM.rd(cppVar_54349);
	cppVar_54351 = ((cppVar_54350 & cppMask_bit_8_) ? (cppVar_54350 | cppMask_sign_8_) : cppVar_54350);
	cppVar_54352 = cppVar_54346 + cppVar_54351;
	cppVar_54352 = (cppVar_54352 & cppMask_un_9_);
	cppVar_54353 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54354 = (cppVar_54353 & cppMask_un_1_);
	cppVar_54355 = cppVar_54352 + cppVar_54354;
	cppVar_54355 = (cppVar_54355 & cppMask_un_9_);
	cppVar_54356 = (cppVar_54355 >> 8) & cppMask_un_1_;
	cppVar_54357 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54358 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54359 = (cppVar_54358 << 3) | 5;
	cppVar_54359 = (cppVar_54359 & cppMask_un_5_);
	cppVar_54360 = (0 << 5) | cppVar_54359;
	cppVar_54360 = (cppVar_54360 & cppMask_un_8_);
	cppVar_54361 = IRAM.rd(cppVar_54360);
	cppVar_54362 = ((cppVar_54361 & cppMask_bit_8_) ? (cppVar_54361 | cppMask_sign_8_) : cppVar_54361);
	cppVar_54363 = cppVar_54357 + cppVar_54362;
	cppVar_54363 = (cppVar_54363 & cppMask_un_9_);
	cppVar_54364 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54365 = (cppVar_54364 & cppMask_un_1_);
	cppVar_54366 = cppVar_54363 + cppVar_54365;
	cppVar_54366 = (cppVar_54366 & cppMask_un_9_);
	cppVar_54367 = (cppVar_54366 >> 7) & cppMask_un_1_;
	cppVar_54368 = (cppVar_54356 != cppVar_54367);
	if (cppVar_54368) {
	cppVar_54345 = 1;
	} else {
	cppVar_54345 = 0;
	}
	cppVar_54371 = (PSW >> 0) & cppMask_un_2_;
	cppVar_54372 = (cppVar_54345 << 2) | cppVar_54371;
	cppVar_54372 = (cppVar_54372 & cppMask_un_3_);
	cppVar_54373 = (cppVar_54344 << 3) | cppVar_54372;
	cppVar_54373 = (cppVar_54373 & cppMask_un_6_);
	cppVar_54374 = (cppVar_54343 << 6) | cppVar_54373;
	cppVar_54374 = (cppVar_54374 & cppMask_un_7_);
	cppVar_54375 = (cppVar_54330 << 7) | cppVar_54374;
	cppVar_54375 = (cppVar_54375 & cppMask_un_8_);
	cppVar_54314 = cppVar_54375;
	} else {
	cppVar_54377 = ROM.rd(PC);
	cppVar_54379 = (cppVar_54377 == 60);
	if (cppVar_54379) {
	cppVar_54380 = (ACC & cppMask_un_8_);
	cppVar_54382 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54384 = (cppVar_54382 << 3) | 4;
	cppVar_54384 = (cppVar_54384 & cppMask_un_5_);
	cppVar_54385 = (0 << 5) | cppVar_54384;
	cppVar_54385 = (cppVar_54385 & cppMask_un_8_);
	cppVar_54386 = IRAM.rd(cppVar_54385);
	cppVar_54387 = (cppVar_54386 & cppMask_un_8_);
	cppVar_54388 = cppVar_54380 + cppVar_54387;
	cppVar_54388 = (cppVar_54388 & cppMask_un_9_);
	cppVar_54389 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54390 = (cppVar_54389 & cppMask_un_1_);
	cppVar_54391 = cppVar_54388 + cppVar_54390;
	cppVar_54391 = (cppVar_54391 & cppMask_un_9_);
	cppVar_54392 = (cppVar_54391 >> 8) & cppMask_un_1_;
	cppVar_54393 = (ACC >> 0) & cppMask_un_4_;
	cppVar_54394 = (cppVar_54393 & cppMask_un_4_);
	cppVar_54395 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54396 = (cppVar_54395 << 3) | 4;
	cppVar_54396 = (cppVar_54396 & cppMask_un_5_);
	cppVar_54397 = (0 << 5) | cppVar_54396;
	cppVar_54397 = (cppVar_54397 & cppMask_un_8_);
	cppVar_54398 = IRAM.rd(cppVar_54397);
	cppVar_54399 = (cppVar_54398 >> 0) & cppMask_un_4_;
	cppVar_54400 = (cppVar_54399 & cppMask_un_4_);
	cppVar_54401 = cppVar_54394 + cppVar_54400;
	cppVar_54401 = (cppVar_54401 & cppMask_un_5_);
	cppVar_54402 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54403 = (cppVar_54402 & cppMask_un_1_);
	cppVar_54404 = cppVar_54401 + cppVar_54403;
	cppVar_54404 = (cppVar_54404 & cppMask_un_5_);
	cppVar_54405 = (cppVar_54404 >> 4) & cppMask_un_1_;
	cppVar_54406 = (PSW >> 3) & cppMask_un_3_;
	cppVar_54408 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54409 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54410 = (cppVar_54409 << 3) | 4;
	cppVar_54410 = (cppVar_54410 & cppMask_un_5_);
	cppVar_54411 = (0 << 5) | cppVar_54410;
	cppVar_54411 = (cppVar_54411 & cppMask_un_8_);
	cppVar_54412 = IRAM.rd(cppVar_54411);
	cppVar_54413 = ((cppVar_54412 & cppMask_bit_8_) ? (cppVar_54412 | cppMask_sign_8_) : cppVar_54412);
	cppVar_54414 = cppVar_54408 + cppVar_54413;
	cppVar_54414 = (cppVar_54414 & cppMask_un_9_);
	cppVar_54415 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54416 = (cppVar_54415 & cppMask_un_1_);
	cppVar_54417 = cppVar_54414 + cppVar_54416;
	cppVar_54417 = (cppVar_54417 & cppMask_un_9_);
	cppVar_54418 = (cppVar_54417 >> 8) & cppMask_un_1_;
	cppVar_54419 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54420 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54421 = (cppVar_54420 << 3) | 4;
	cppVar_54421 = (cppVar_54421 & cppMask_un_5_);
	cppVar_54422 = (0 << 5) | cppVar_54421;
	cppVar_54422 = (cppVar_54422 & cppMask_un_8_);
	cppVar_54423 = IRAM.rd(cppVar_54422);
	cppVar_54424 = ((cppVar_54423 & cppMask_bit_8_) ? (cppVar_54423 | cppMask_sign_8_) : cppVar_54423);
	cppVar_54425 = cppVar_54419 + cppVar_54424;
	cppVar_54425 = (cppVar_54425 & cppMask_un_9_);
	cppVar_54426 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54427 = (cppVar_54426 & cppMask_un_1_);
	cppVar_54428 = cppVar_54425 + cppVar_54427;
	cppVar_54428 = (cppVar_54428 & cppMask_un_9_);
	cppVar_54429 = (cppVar_54428 >> 7) & cppMask_un_1_;
	cppVar_54430 = (cppVar_54418 != cppVar_54429);
	if (cppVar_54430) {
	cppVar_54407 = 1;
	} else {
	cppVar_54407 = 0;
	}
	cppVar_54433 = (PSW >> 0) & cppMask_un_2_;
	cppVar_54434 = (cppVar_54407 << 2) | cppVar_54433;
	cppVar_54434 = (cppVar_54434 & cppMask_un_3_);
	cppVar_54435 = (cppVar_54406 << 3) | cppVar_54434;
	cppVar_54435 = (cppVar_54435 & cppMask_un_6_);
	cppVar_54436 = (cppVar_54405 << 6) | cppVar_54435;
	cppVar_54436 = (cppVar_54436 & cppMask_un_7_);
	cppVar_54437 = (cppVar_54392 << 7) | cppVar_54436;
	cppVar_54437 = (cppVar_54437 & cppMask_un_8_);
	cppVar_54376 = cppVar_54437;
	} else {
	cppVar_54439 = ROM.rd(PC);
	cppVar_54441 = (cppVar_54439 == 59);
	if (cppVar_54441) {
	cppVar_54442 = (ACC & cppMask_un_8_);
	cppVar_54444 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54446 = (cppVar_54444 << 3) | 3;
	cppVar_54446 = (cppVar_54446 & cppMask_un_5_);
	cppVar_54447 = (0 << 5) | cppVar_54446;
	cppVar_54447 = (cppVar_54447 & cppMask_un_8_);
	cppVar_54448 = IRAM.rd(cppVar_54447);
	cppVar_54449 = (cppVar_54448 & cppMask_un_8_);
	cppVar_54450 = cppVar_54442 + cppVar_54449;
	cppVar_54450 = (cppVar_54450 & cppMask_un_9_);
	cppVar_54451 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54452 = (cppVar_54451 & cppMask_un_1_);
	cppVar_54453 = cppVar_54450 + cppVar_54452;
	cppVar_54453 = (cppVar_54453 & cppMask_un_9_);
	cppVar_54454 = (cppVar_54453 >> 8) & cppMask_un_1_;
	cppVar_54455 = (ACC >> 0) & cppMask_un_4_;
	cppVar_54456 = (cppVar_54455 & cppMask_un_4_);
	cppVar_54457 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54458 = (cppVar_54457 << 3) | 3;
	cppVar_54458 = (cppVar_54458 & cppMask_un_5_);
	cppVar_54459 = (0 << 5) | cppVar_54458;
	cppVar_54459 = (cppVar_54459 & cppMask_un_8_);
	cppVar_54460 = IRAM.rd(cppVar_54459);
	cppVar_54461 = (cppVar_54460 >> 0) & cppMask_un_4_;
	cppVar_54462 = (cppVar_54461 & cppMask_un_4_);
	cppVar_54463 = cppVar_54456 + cppVar_54462;
	cppVar_54463 = (cppVar_54463 & cppMask_un_5_);
	cppVar_54464 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54465 = (cppVar_54464 & cppMask_un_1_);
	cppVar_54466 = cppVar_54463 + cppVar_54465;
	cppVar_54466 = (cppVar_54466 & cppMask_un_5_);
	cppVar_54467 = (cppVar_54466 >> 4) & cppMask_un_1_;
	cppVar_54468 = (PSW >> 3) & cppMask_un_3_;
	cppVar_54470 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54471 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54472 = (cppVar_54471 << 3) | 3;
	cppVar_54472 = (cppVar_54472 & cppMask_un_5_);
	cppVar_54473 = (0 << 5) | cppVar_54472;
	cppVar_54473 = (cppVar_54473 & cppMask_un_8_);
	cppVar_54474 = IRAM.rd(cppVar_54473);
	cppVar_54475 = ((cppVar_54474 & cppMask_bit_8_) ? (cppVar_54474 | cppMask_sign_8_) : cppVar_54474);
	cppVar_54476 = cppVar_54470 + cppVar_54475;
	cppVar_54476 = (cppVar_54476 & cppMask_un_9_);
	cppVar_54477 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54478 = (cppVar_54477 & cppMask_un_1_);
	cppVar_54479 = cppVar_54476 + cppVar_54478;
	cppVar_54479 = (cppVar_54479 & cppMask_un_9_);
	cppVar_54480 = (cppVar_54479 >> 8) & cppMask_un_1_;
	cppVar_54481 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54482 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54483 = (cppVar_54482 << 3) | 3;
	cppVar_54483 = (cppVar_54483 & cppMask_un_5_);
	cppVar_54484 = (0 << 5) | cppVar_54483;
	cppVar_54484 = (cppVar_54484 & cppMask_un_8_);
	cppVar_54485 = IRAM.rd(cppVar_54484);
	cppVar_54486 = ((cppVar_54485 & cppMask_bit_8_) ? (cppVar_54485 | cppMask_sign_8_) : cppVar_54485);
	cppVar_54487 = cppVar_54481 + cppVar_54486;
	cppVar_54487 = (cppVar_54487 & cppMask_un_9_);
	cppVar_54488 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54489 = (cppVar_54488 & cppMask_un_1_);
	cppVar_54490 = cppVar_54487 + cppVar_54489;
	cppVar_54490 = (cppVar_54490 & cppMask_un_9_);
	cppVar_54491 = (cppVar_54490 >> 7) & cppMask_un_1_;
	cppVar_54492 = (cppVar_54480 != cppVar_54491);
	if (cppVar_54492) {
	cppVar_54469 = 1;
	} else {
	cppVar_54469 = 0;
	}
	cppVar_54495 = (PSW >> 0) & cppMask_un_2_;
	cppVar_54496 = (cppVar_54469 << 2) | cppVar_54495;
	cppVar_54496 = (cppVar_54496 & cppMask_un_3_);
	cppVar_54497 = (cppVar_54468 << 3) | cppVar_54496;
	cppVar_54497 = (cppVar_54497 & cppMask_un_6_);
	cppVar_54498 = (cppVar_54467 << 6) | cppVar_54497;
	cppVar_54498 = (cppVar_54498 & cppMask_un_7_);
	cppVar_54499 = (cppVar_54454 << 7) | cppVar_54498;
	cppVar_54499 = (cppVar_54499 & cppMask_un_8_);
	cppVar_54438 = cppVar_54499;
	} else {
	cppVar_54501 = ROM.rd(PC);
	cppVar_54503 = (cppVar_54501 == 58);
	if (cppVar_54503) {
	cppVar_54504 = (ACC & cppMask_un_8_);
	cppVar_54506 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54508 = (cppVar_54506 << 3) | 2;
	cppVar_54508 = (cppVar_54508 & cppMask_un_5_);
	cppVar_54509 = (0 << 5) | cppVar_54508;
	cppVar_54509 = (cppVar_54509 & cppMask_un_8_);
	cppVar_54510 = IRAM.rd(cppVar_54509);
	cppVar_54511 = (cppVar_54510 & cppMask_un_8_);
	cppVar_54512 = cppVar_54504 + cppVar_54511;
	cppVar_54512 = (cppVar_54512 & cppMask_un_9_);
	cppVar_54513 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54514 = (cppVar_54513 & cppMask_un_1_);
	cppVar_54515 = cppVar_54512 + cppVar_54514;
	cppVar_54515 = (cppVar_54515 & cppMask_un_9_);
	cppVar_54516 = (cppVar_54515 >> 8) & cppMask_un_1_;
	cppVar_54517 = (ACC >> 0) & cppMask_un_4_;
	cppVar_54518 = (cppVar_54517 & cppMask_un_4_);
	cppVar_54519 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54520 = (cppVar_54519 << 3) | 2;
	cppVar_54520 = (cppVar_54520 & cppMask_un_5_);
	cppVar_54521 = (0 << 5) | cppVar_54520;
	cppVar_54521 = (cppVar_54521 & cppMask_un_8_);
	cppVar_54522 = IRAM.rd(cppVar_54521);
	cppVar_54523 = (cppVar_54522 >> 0) & cppMask_un_4_;
	cppVar_54524 = (cppVar_54523 & cppMask_un_4_);
	cppVar_54525 = cppVar_54518 + cppVar_54524;
	cppVar_54525 = (cppVar_54525 & cppMask_un_5_);
	cppVar_54526 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54527 = (cppVar_54526 & cppMask_un_1_);
	cppVar_54528 = cppVar_54525 + cppVar_54527;
	cppVar_54528 = (cppVar_54528 & cppMask_un_5_);
	cppVar_54529 = (cppVar_54528 >> 4) & cppMask_un_1_;
	cppVar_54530 = (PSW >> 3) & cppMask_un_3_;
	cppVar_54532 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54533 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54534 = (cppVar_54533 << 3) | 2;
	cppVar_54534 = (cppVar_54534 & cppMask_un_5_);
	cppVar_54535 = (0 << 5) | cppVar_54534;
	cppVar_54535 = (cppVar_54535 & cppMask_un_8_);
	cppVar_54536 = IRAM.rd(cppVar_54535);
	cppVar_54537 = ((cppVar_54536 & cppMask_bit_8_) ? (cppVar_54536 | cppMask_sign_8_) : cppVar_54536);
	cppVar_54538 = cppVar_54532 + cppVar_54537;
	cppVar_54538 = (cppVar_54538 & cppMask_un_9_);
	cppVar_54539 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54540 = (cppVar_54539 & cppMask_un_1_);
	cppVar_54541 = cppVar_54538 + cppVar_54540;
	cppVar_54541 = (cppVar_54541 & cppMask_un_9_);
	cppVar_54542 = (cppVar_54541 >> 8) & cppMask_un_1_;
	cppVar_54543 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54544 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54545 = (cppVar_54544 << 3) | 2;
	cppVar_54545 = (cppVar_54545 & cppMask_un_5_);
	cppVar_54546 = (0 << 5) | cppVar_54545;
	cppVar_54546 = (cppVar_54546 & cppMask_un_8_);
	cppVar_54547 = IRAM.rd(cppVar_54546);
	cppVar_54548 = ((cppVar_54547 & cppMask_bit_8_) ? (cppVar_54547 | cppMask_sign_8_) : cppVar_54547);
	cppVar_54549 = cppVar_54543 + cppVar_54548;
	cppVar_54549 = (cppVar_54549 & cppMask_un_9_);
	cppVar_54550 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54551 = (cppVar_54550 & cppMask_un_1_);
	cppVar_54552 = cppVar_54549 + cppVar_54551;
	cppVar_54552 = (cppVar_54552 & cppMask_un_9_);
	cppVar_54553 = (cppVar_54552 >> 7) & cppMask_un_1_;
	cppVar_54554 = (cppVar_54542 != cppVar_54553);
	if (cppVar_54554) {
	cppVar_54531 = 1;
	} else {
	cppVar_54531 = 0;
	}
	cppVar_54557 = (PSW >> 0) & cppMask_un_2_;
	cppVar_54558 = (cppVar_54531 << 2) | cppVar_54557;
	cppVar_54558 = (cppVar_54558 & cppMask_un_3_);
	cppVar_54559 = (cppVar_54530 << 3) | cppVar_54558;
	cppVar_54559 = (cppVar_54559 & cppMask_un_6_);
	cppVar_54560 = (cppVar_54529 << 6) | cppVar_54559;
	cppVar_54560 = (cppVar_54560 & cppMask_un_7_);
	cppVar_54561 = (cppVar_54516 << 7) | cppVar_54560;
	cppVar_54561 = (cppVar_54561 & cppMask_un_8_);
	cppVar_54500 = cppVar_54561;
	} else {
	cppVar_54563 = ROM.rd(PC);
	cppVar_54565 = (cppVar_54563 == 57);
	if (cppVar_54565) {
	cppVar_54566 = (ACC & cppMask_un_8_);
	cppVar_54568 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54570 = (cppVar_54568 << 3) | 1;
	cppVar_54570 = (cppVar_54570 & cppMask_un_5_);
	cppVar_54571 = (0 << 5) | cppVar_54570;
	cppVar_54571 = (cppVar_54571 & cppMask_un_8_);
	cppVar_54572 = IRAM.rd(cppVar_54571);
	cppVar_54573 = (cppVar_54572 & cppMask_un_8_);
	cppVar_54574 = cppVar_54566 + cppVar_54573;
	cppVar_54574 = (cppVar_54574 & cppMask_un_9_);
	cppVar_54575 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54576 = (cppVar_54575 & cppMask_un_1_);
	cppVar_54577 = cppVar_54574 + cppVar_54576;
	cppVar_54577 = (cppVar_54577 & cppMask_un_9_);
	cppVar_54578 = (cppVar_54577 >> 8) & cppMask_un_1_;
	cppVar_54579 = (ACC >> 0) & cppMask_un_4_;
	cppVar_54580 = (cppVar_54579 & cppMask_un_4_);
	cppVar_54581 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54582 = (cppVar_54581 << 3) | 1;
	cppVar_54582 = (cppVar_54582 & cppMask_un_5_);
	cppVar_54583 = (0 << 5) | cppVar_54582;
	cppVar_54583 = (cppVar_54583 & cppMask_un_8_);
	cppVar_54584 = IRAM.rd(cppVar_54583);
	cppVar_54585 = (cppVar_54584 >> 0) & cppMask_un_4_;
	cppVar_54586 = (cppVar_54585 & cppMask_un_4_);
	cppVar_54587 = cppVar_54580 + cppVar_54586;
	cppVar_54587 = (cppVar_54587 & cppMask_un_5_);
	cppVar_54588 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54589 = (cppVar_54588 & cppMask_un_1_);
	cppVar_54590 = cppVar_54587 + cppVar_54589;
	cppVar_54590 = (cppVar_54590 & cppMask_un_5_);
	cppVar_54591 = (cppVar_54590 >> 4) & cppMask_un_1_;
	cppVar_54592 = (PSW >> 3) & cppMask_un_3_;
	cppVar_54594 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54595 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54596 = (cppVar_54595 << 3) | 1;
	cppVar_54596 = (cppVar_54596 & cppMask_un_5_);
	cppVar_54597 = (0 << 5) | cppVar_54596;
	cppVar_54597 = (cppVar_54597 & cppMask_un_8_);
	cppVar_54598 = IRAM.rd(cppVar_54597);
	cppVar_54599 = ((cppVar_54598 & cppMask_bit_8_) ? (cppVar_54598 | cppMask_sign_8_) : cppVar_54598);
	cppVar_54600 = cppVar_54594 + cppVar_54599;
	cppVar_54600 = (cppVar_54600 & cppMask_un_9_);
	cppVar_54601 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54602 = (cppVar_54601 & cppMask_un_1_);
	cppVar_54603 = cppVar_54600 + cppVar_54602;
	cppVar_54603 = (cppVar_54603 & cppMask_un_9_);
	cppVar_54604 = (cppVar_54603 >> 8) & cppMask_un_1_;
	cppVar_54605 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54606 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54607 = (cppVar_54606 << 3) | 1;
	cppVar_54607 = (cppVar_54607 & cppMask_un_5_);
	cppVar_54608 = (0 << 5) | cppVar_54607;
	cppVar_54608 = (cppVar_54608 & cppMask_un_8_);
	cppVar_54609 = IRAM.rd(cppVar_54608);
	cppVar_54610 = ((cppVar_54609 & cppMask_bit_8_) ? (cppVar_54609 | cppMask_sign_8_) : cppVar_54609);
	cppVar_54611 = cppVar_54605 + cppVar_54610;
	cppVar_54611 = (cppVar_54611 & cppMask_un_9_);
	cppVar_54612 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54613 = (cppVar_54612 & cppMask_un_1_);
	cppVar_54614 = cppVar_54611 + cppVar_54613;
	cppVar_54614 = (cppVar_54614 & cppMask_un_9_);
	cppVar_54615 = (cppVar_54614 >> 7) & cppMask_un_1_;
	cppVar_54616 = (cppVar_54604 != cppVar_54615);
	if (cppVar_54616) {
	cppVar_54593 = 1;
	} else {
	cppVar_54593 = 0;
	}
	cppVar_54619 = (PSW >> 0) & cppMask_un_2_;
	cppVar_54620 = (cppVar_54593 << 2) | cppVar_54619;
	cppVar_54620 = (cppVar_54620 & cppMask_un_3_);
	cppVar_54621 = (cppVar_54592 << 3) | cppVar_54620;
	cppVar_54621 = (cppVar_54621 & cppMask_un_6_);
	cppVar_54622 = (cppVar_54591 << 6) | cppVar_54621;
	cppVar_54622 = (cppVar_54622 & cppMask_un_7_);
	cppVar_54623 = (cppVar_54578 << 7) | cppVar_54622;
	cppVar_54623 = (cppVar_54623 & cppMask_un_8_);
	cppVar_54562 = cppVar_54623;
	} else {
	cppVar_54625 = ROM.rd(PC);
	cppVar_54627 = (cppVar_54625 == 56);
	if (cppVar_54627) {
	cppVar_54628 = (ACC & cppMask_un_8_);
	cppVar_54630 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54632 = (cppVar_54630 << 3) | 0;
	cppVar_54632 = (cppVar_54632 & cppMask_un_5_);
	cppVar_54633 = (0 << 5) | cppVar_54632;
	cppVar_54633 = (cppVar_54633 & cppMask_un_8_);
	cppVar_54634 = IRAM.rd(cppVar_54633);
	cppVar_54635 = (cppVar_54634 & cppMask_un_8_);
	cppVar_54636 = cppVar_54628 + cppVar_54635;
	cppVar_54636 = (cppVar_54636 & cppMask_un_9_);
	cppVar_54637 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54638 = (cppVar_54637 & cppMask_un_1_);
	cppVar_54639 = cppVar_54636 + cppVar_54638;
	cppVar_54639 = (cppVar_54639 & cppMask_un_9_);
	cppVar_54640 = (cppVar_54639 >> 8) & cppMask_un_1_;
	cppVar_54641 = (ACC >> 0) & cppMask_un_4_;
	cppVar_54642 = (cppVar_54641 & cppMask_un_4_);
	cppVar_54643 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54644 = (cppVar_54643 << 3) | 0;
	cppVar_54644 = (cppVar_54644 & cppMask_un_5_);
	cppVar_54645 = (0 << 5) | cppVar_54644;
	cppVar_54645 = (cppVar_54645 & cppMask_un_8_);
	cppVar_54646 = IRAM.rd(cppVar_54645);
	cppVar_54647 = (cppVar_54646 >> 0) & cppMask_un_4_;
	cppVar_54648 = (cppVar_54647 & cppMask_un_4_);
	cppVar_54649 = cppVar_54642 + cppVar_54648;
	cppVar_54649 = (cppVar_54649 & cppMask_un_5_);
	cppVar_54650 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54651 = (cppVar_54650 & cppMask_un_1_);
	cppVar_54652 = cppVar_54649 + cppVar_54651;
	cppVar_54652 = (cppVar_54652 & cppMask_un_5_);
	cppVar_54653 = (cppVar_54652 >> 4) & cppMask_un_1_;
	cppVar_54654 = (PSW >> 3) & cppMask_un_3_;
	cppVar_54656 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54657 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54658 = (cppVar_54657 << 3) | 0;
	cppVar_54658 = (cppVar_54658 & cppMask_un_5_);
	cppVar_54659 = (0 << 5) | cppVar_54658;
	cppVar_54659 = (cppVar_54659 & cppMask_un_8_);
	cppVar_54660 = IRAM.rd(cppVar_54659);
	cppVar_54661 = ((cppVar_54660 & cppMask_bit_8_) ? (cppVar_54660 | cppMask_sign_8_) : cppVar_54660);
	cppVar_54662 = cppVar_54656 + cppVar_54661;
	cppVar_54662 = (cppVar_54662 & cppMask_un_9_);
	cppVar_54663 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54664 = (cppVar_54663 & cppMask_un_1_);
	cppVar_54665 = cppVar_54662 + cppVar_54664;
	cppVar_54665 = (cppVar_54665 & cppMask_un_9_);
	cppVar_54666 = (cppVar_54665 >> 8) & cppMask_un_1_;
	cppVar_54667 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54668 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54669 = (cppVar_54668 << 3) | 0;
	cppVar_54669 = (cppVar_54669 & cppMask_un_5_);
	cppVar_54670 = (0 << 5) | cppVar_54669;
	cppVar_54670 = (cppVar_54670 & cppMask_un_8_);
	cppVar_54671 = IRAM.rd(cppVar_54670);
	cppVar_54672 = ((cppVar_54671 & cppMask_bit_8_) ? (cppVar_54671 | cppMask_sign_8_) : cppVar_54671);
	cppVar_54673 = cppVar_54667 + cppVar_54672;
	cppVar_54673 = (cppVar_54673 & cppMask_un_9_);
	cppVar_54674 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54675 = (cppVar_54674 & cppMask_un_1_);
	cppVar_54676 = cppVar_54673 + cppVar_54675;
	cppVar_54676 = (cppVar_54676 & cppMask_un_9_);
	cppVar_54677 = (cppVar_54676 >> 7) & cppMask_un_1_;
	cppVar_54678 = (cppVar_54666 != cppVar_54677);
	if (cppVar_54678) {
	cppVar_54655 = 1;
	} else {
	cppVar_54655 = 0;
	}
	cppVar_54681 = (PSW >> 0) & cppMask_un_2_;
	cppVar_54682 = (cppVar_54655 << 2) | cppVar_54681;
	cppVar_54682 = (cppVar_54682 & cppMask_un_3_);
	cppVar_54683 = (cppVar_54654 << 3) | cppVar_54682;
	cppVar_54683 = (cppVar_54683 & cppMask_un_6_);
	cppVar_54684 = (cppVar_54653 << 6) | cppVar_54683;
	cppVar_54684 = (cppVar_54684 & cppMask_un_7_);
	cppVar_54685 = (cppVar_54640 << 7) | cppVar_54684;
	cppVar_54685 = (cppVar_54685 & cppMask_un_8_);
	cppVar_54624 = cppVar_54685;
	} else {
	cppVar_54687 = ROM.rd(PC);
	cppVar_54689 = (cppVar_54687 == 55);
	if (cppVar_54689) {
	cppVar_54690 = (ACC & cppMask_un_8_);
	cppVar_54692 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54694 = (cppVar_54692 << 3) | 1;
	cppVar_54694 = (cppVar_54694 & cppMask_un_5_);
	cppVar_54695 = (0 << 5) | cppVar_54694;
	cppVar_54695 = (cppVar_54695 & cppMask_un_8_);
	cppVar_54696 = IRAM.rd(cppVar_54695);
	cppVar_54697 = IRAM.rd(cppVar_54696);
	cppVar_54698 = (cppVar_54697 & cppMask_un_8_);
	cppVar_54699 = cppVar_54690 + cppVar_54698;
	cppVar_54699 = (cppVar_54699 & cppMask_un_9_);
	cppVar_54700 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54701 = (cppVar_54700 & cppMask_un_1_);
	cppVar_54702 = cppVar_54699 + cppVar_54701;
	cppVar_54702 = (cppVar_54702 & cppMask_un_9_);
	cppVar_54703 = (cppVar_54702 >> 8) & cppMask_un_1_;
	cppVar_54704 = (ACC >> 0) & cppMask_un_4_;
	cppVar_54705 = (cppVar_54704 & cppMask_un_4_);
	cppVar_54706 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54707 = (cppVar_54706 << 3) | 1;
	cppVar_54707 = (cppVar_54707 & cppMask_un_5_);
	cppVar_54708 = (0 << 5) | cppVar_54707;
	cppVar_54708 = (cppVar_54708 & cppMask_un_8_);
	cppVar_54709 = IRAM.rd(cppVar_54708);
	cppVar_54710 = IRAM.rd(cppVar_54709);
	cppVar_54711 = (cppVar_54710 >> 0) & cppMask_un_4_;
	cppVar_54712 = (cppVar_54711 & cppMask_un_4_);
	cppVar_54713 = cppVar_54705 + cppVar_54712;
	cppVar_54713 = (cppVar_54713 & cppMask_un_5_);
	cppVar_54714 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54715 = (cppVar_54714 & cppMask_un_1_);
	cppVar_54716 = cppVar_54713 + cppVar_54715;
	cppVar_54716 = (cppVar_54716 & cppMask_un_5_);
	cppVar_54717 = (cppVar_54716 >> 4) & cppMask_un_1_;
	cppVar_54718 = (PSW >> 3) & cppMask_un_3_;
	cppVar_54720 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54721 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54722 = (cppVar_54721 << 3) | 1;
	cppVar_54722 = (cppVar_54722 & cppMask_un_5_);
	cppVar_54723 = (0 << 5) | cppVar_54722;
	cppVar_54723 = (cppVar_54723 & cppMask_un_8_);
	cppVar_54724 = IRAM.rd(cppVar_54723);
	cppVar_54725 = IRAM.rd(cppVar_54724);
	cppVar_54726 = ((cppVar_54725 & cppMask_bit_8_) ? (cppVar_54725 | cppMask_sign_8_) : cppVar_54725);
	cppVar_54727 = cppVar_54720 + cppVar_54726;
	cppVar_54727 = (cppVar_54727 & cppMask_un_9_);
	cppVar_54728 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54729 = (cppVar_54728 & cppMask_un_1_);
	cppVar_54730 = cppVar_54727 + cppVar_54729;
	cppVar_54730 = (cppVar_54730 & cppMask_un_9_);
	cppVar_54731 = (cppVar_54730 >> 8) & cppMask_un_1_;
	cppVar_54732 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54733 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54734 = (cppVar_54733 << 3) | 1;
	cppVar_54734 = (cppVar_54734 & cppMask_un_5_);
	cppVar_54735 = (0 << 5) | cppVar_54734;
	cppVar_54735 = (cppVar_54735 & cppMask_un_8_);
	cppVar_54736 = IRAM.rd(cppVar_54735);
	cppVar_54737 = IRAM.rd(cppVar_54736);
	cppVar_54738 = ((cppVar_54737 & cppMask_bit_8_) ? (cppVar_54737 | cppMask_sign_8_) : cppVar_54737);
	cppVar_54739 = cppVar_54732 + cppVar_54738;
	cppVar_54739 = (cppVar_54739 & cppMask_un_9_);
	cppVar_54740 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54741 = (cppVar_54740 & cppMask_un_1_);
	cppVar_54742 = cppVar_54739 + cppVar_54741;
	cppVar_54742 = (cppVar_54742 & cppMask_un_9_);
	cppVar_54743 = (cppVar_54742 >> 7) & cppMask_un_1_;
	cppVar_54744 = (cppVar_54731 != cppVar_54743);
	if (cppVar_54744) {
	cppVar_54719 = 1;
	} else {
	cppVar_54719 = 0;
	}
	cppVar_54747 = (PSW >> 0) & cppMask_un_2_;
	cppVar_54748 = (cppVar_54719 << 2) | cppVar_54747;
	cppVar_54748 = (cppVar_54748 & cppMask_un_3_);
	cppVar_54749 = (cppVar_54718 << 3) | cppVar_54748;
	cppVar_54749 = (cppVar_54749 & cppMask_un_6_);
	cppVar_54750 = (cppVar_54717 << 6) | cppVar_54749;
	cppVar_54750 = (cppVar_54750 & cppMask_un_7_);
	cppVar_54751 = (cppVar_54703 << 7) | cppVar_54750;
	cppVar_54751 = (cppVar_54751 & cppMask_un_8_);
	cppVar_54686 = cppVar_54751;
	} else {
	cppVar_54753 = ROM.rd(PC);
	cppVar_54755 = (cppVar_54753 == 54);
	if (cppVar_54755) {
	cppVar_54756 = (ACC & cppMask_un_8_);
	cppVar_54758 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54760 = (cppVar_54758 << 3) | 0;
	cppVar_54760 = (cppVar_54760 & cppMask_un_5_);
	cppVar_54761 = (0 << 5) | cppVar_54760;
	cppVar_54761 = (cppVar_54761 & cppMask_un_8_);
	cppVar_54762 = IRAM.rd(cppVar_54761);
	cppVar_54763 = IRAM.rd(cppVar_54762);
	cppVar_54764 = (cppVar_54763 & cppMask_un_8_);
	cppVar_54765 = cppVar_54756 + cppVar_54764;
	cppVar_54765 = (cppVar_54765 & cppMask_un_9_);
	cppVar_54766 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54767 = (cppVar_54766 & cppMask_un_1_);
	cppVar_54768 = cppVar_54765 + cppVar_54767;
	cppVar_54768 = (cppVar_54768 & cppMask_un_9_);
	cppVar_54769 = (cppVar_54768 >> 8) & cppMask_un_1_;
	cppVar_54770 = (ACC >> 0) & cppMask_un_4_;
	cppVar_54771 = (cppVar_54770 & cppMask_un_4_);
	cppVar_54772 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54773 = (cppVar_54772 << 3) | 0;
	cppVar_54773 = (cppVar_54773 & cppMask_un_5_);
	cppVar_54774 = (0 << 5) | cppVar_54773;
	cppVar_54774 = (cppVar_54774 & cppMask_un_8_);
	cppVar_54775 = IRAM.rd(cppVar_54774);
	cppVar_54776 = IRAM.rd(cppVar_54775);
	cppVar_54777 = (cppVar_54776 >> 0) & cppMask_un_4_;
	cppVar_54778 = (cppVar_54777 & cppMask_un_4_);
	cppVar_54779 = cppVar_54771 + cppVar_54778;
	cppVar_54779 = (cppVar_54779 & cppMask_un_5_);
	cppVar_54780 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54781 = (cppVar_54780 & cppMask_un_1_);
	cppVar_54782 = cppVar_54779 + cppVar_54781;
	cppVar_54782 = (cppVar_54782 & cppMask_un_5_);
	cppVar_54783 = (cppVar_54782 >> 4) & cppMask_un_1_;
	cppVar_54784 = (PSW >> 3) & cppMask_un_3_;
	cppVar_54786 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54787 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54788 = (cppVar_54787 << 3) | 0;
	cppVar_54788 = (cppVar_54788 & cppMask_un_5_);
	cppVar_54789 = (0 << 5) | cppVar_54788;
	cppVar_54789 = (cppVar_54789 & cppMask_un_8_);
	cppVar_54790 = IRAM.rd(cppVar_54789);
	cppVar_54791 = IRAM.rd(cppVar_54790);
	cppVar_54792 = ((cppVar_54791 & cppMask_bit_8_) ? (cppVar_54791 | cppMask_sign_8_) : cppVar_54791);
	cppVar_54793 = cppVar_54786 + cppVar_54792;
	cppVar_54793 = (cppVar_54793 & cppMask_un_9_);
	cppVar_54794 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54795 = (cppVar_54794 & cppMask_un_1_);
	cppVar_54796 = cppVar_54793 + cppVar_54795;
	cppVar_54796 = (cppVar_54796 & cppMask_un_9_);
	cppVar_54797 = (cppVar_54796 >> 8) & cppMask_un_1_;
	cppVar_54798 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_54799 = (PSW >> 3) & cppMask_un_2_;
	cppVar_54800 = (cppVar_54799 << 3) | 0;
	cppVar_54800 = (cppVar_54800 & cppMask_un_5_);
	cppVar_54801 = (0 << 5) | cppVar_54800;
	cppVar_54801 = (cppVar_54801 & cppMask_un_8_);
	cppVar_54802 = IRAM.rd(cppVar_54801);
	cppVar_54803 = IRAM.rd(cppVar_54802);
	cppVar_54804 = ((cppVar_54803 & cppMask_bit_8_) ? (cppVar_54803 | cppMask_sign_8_) : cppVar_54803);
	cppVar_54805 = cppVar_54798 + cppVar_54804;
	cppVar_54805 = (cppVar_54805 & cppMask_un_9_);
	cppVar_54806 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54807 = (cppVar_54806 & cppMask_un_1_);
	cppVar_54808 = cppVar_54805 + cppVar_54807;
	cppVar_54808 = (cppVar_54808 & cppMask_un_9_);
	cppVar_54809 = (cppVar_54808 >> 7) & cppMask_un_1_;
	cppVar_54810 = (cppVar_54797 != cppVar_54809);
	if (cppVar_54810) {
	cppVar_54785 = 1;
	} else {
	cppVar_54785 = 0;
	}
	cppVar_54813 = (PSW >> 0) & cppMask_un_2_;
	cppVar_54814 = (cppVar_54785 << 2) | cppVar_54813;
	cppVar_54814 = (cppVar_54814 & cppMask_un_3_);
	cppVar_54815 = (cppVar_54784 << 3) | cppVar_54814;
	cppVar_54815 = (cppVar_54815 & cppMask_un_6_);
	cppVar_54816 = (cppVar_54783 << 6) | cppVar_54815;
	cppVar_54816 = (cppVar_54816 & cppMask_un_7_);
	cppVar_54817 = (cppVar_54769 << 7) | cppVar_54816;
	cppVar_54817 = (cppVar_54817 & cppMask_un_8_);
	cppVar_54752 = cppVar_54817;
	} else {
	cppVar_54819 = ROM.rd(PC);
	cppVar_54821 = (cppVar_54819 == 53);
	if (cppVar_54821) {
	cppVar_54822 = (ACC & cppMask_un_8_);
	cppVar_54825 = PC + 1;
	cppVar_54825 = (cppVar_54825 & cppMask_un_16_);
	cppVar_54826 = ROM.rd(cppVar_54825);
	cppVar_54827 = (cppVar_54826 >> 7) & cppMask_un_1_;
	cppVar_54829 = (cppVar_54827 == 0);
	if (cppVar_54829) {
	cppVar_54830 = PC + 1;
	cppVar_54830 = (cppVar_54830 & cppMask_un_16_);
	cppVar_54831 = ROM.rd(cppVar_54830);
	cppVar_54832 = IRAM.rd(cppVar_54831);
	cppVar_54823 = cppVar_54832;
	} else {
	cppVar_54834 = PC + 1;
	cppVar_54834 = (cppVar_54834 & cppMask_un_16_);
	cppVar_54835 = ROM.rd(cppVar_54834);
	cppVar_54837 = (cppVar_54835 == 128);
	if (cppVar_54837) {
	cppVar_54833 = P0;
	} else {
	cppVar_54839 = PC + 1;
	cppVar_54839 = (cppVar_54839 & cppMask_un_16_);
	cppVar_54840 = ROM.rd(cppVar_54839);
	cppVar_54842 = (cppVar_54840 == 129);
	if (cppVar_54842) {
	cppVar_54838 = SP;
	} else {
	cppVar_54844 = PC + 1;
	cppVar_54844 = (cppVar_54844 & cppMask_un_16_);
	cppVar_54845 = ROM.rd(cppVar_54844);
	cppVar_54847 = (cppVar_54845 == 130);
	if (cppVar_54847) {
	cppVar_54843 = DPL;
	} else {
	cppVar_54849 = PC + 1;
	cppVar_54849 = (cppVar_54849 & cppMask_un_16_);
	cppVar_54850 = ROM.rd(cppVar_54849);
	cppVar_54852 = (cppVar_54850 == 131);
	if (cppVar_54852) {
	cppVar_54848 = DPH;
	} else {
	cppVar_54854 = PC + 1;
	cppVar_54854 = (cppVar_54854 & cppMask_un_16_);
	cppVar_54855 = ROM.rd(cppVar_54854);
	cppVar_54857 = (cppVar_54855 == 135);
	if (cppVar_54857) {
	cppVar_54853 = PCON;
	} else {
	cppVar_54859 = PC + 1;
	cppVar_54859 = (cppVar_54859 & cppMask_un_16_);
	cppVar_54860 = ROM.rd(cppVar_54859);
	cppVar_54862 = (cppVar_54860 == 136);
	if (cppVar_54862) {
	cppVar_54858 = TCON;
	} else {
	cppVar_54864 = PC + 1;
	cppVar_54864 = (cppVar_54864 & cppMask_un_16_);
	cppVar_54865 = ROM.rd(cppVar_54864);
	cppVar_54867 = (cppVar_54865 == 137);
	if (cppVar_54867) {
	cppVar_54863 = TMOD;
	} else {
	cppVar_54869 = PC + 1;
	cppVar_54869 = (cppVar_54869 & cppMask_un_16_);
	cppVar_54870 = ROM.rd(cppVar_54869);
	cppVar_54872 = (cppVar_54870 == 138);
	if (cppVar_54872) {
	cppVar_54868 = TL0;
	} else {
	cppVar_54874 = PC + 1;
	cppVar_54874 = (cppVar_54874 & cppMask_un_16_);
	cppVar_54875 = ROM.rd(cppVar_54874);
	cppVar_54877 = (cppVar_54875 == 140);
	if (cppVar_54877) {
	cppVar_54873 = TH0;
	} else {
	cppVar_54879 = PC + 1;
	cppVar_54879 = (cppVar_54879 & cppMask_un_16_);
	cppVar_54880 = ROM.rd(cppVar_54879);
	cppVar_54882 = (cppVar_54880 == 139);
	if (cppVar_54882) {
	cppVar_54878 = TL1;
	} else {
	cppVar_54884 = PC + 1;
	cppVar_54884 = (cppVar_54884 & cppMask_un_16_);
	cppVar_54885 = ROM.rd(cppVar_54884);
	cppVar_54887 = (cppVar_54885 == 141);
	if (cppVar_54887) {
	cppVar_54883 = TH1;
	} else {
	cppVar_54889 = PC + 1;
	cppVar_54889 = (cppVar_54889 & cppMask_un_16_);
	cppVar_54890 = ROM.rd(cppVar_54889);
	cppVar_54892 = (cppVar_54890 == 144);
	if (cppVar_54892) {
	cppVar_54888 = P1;
	} else {
	cppVar_54894 = PC + 1;
	cppVar_54894 = (cppVar_54894 & cppMask_un_16_);
	cppVar_54895 = ROM.rd(cppVar_54894);
	cppVar_54897 = (cppVar_54895 == 152);
	if (cppVar_54897) {
	cppVar_54893 = SCON;
	} else {
	cppVar_54899 = PC + 1;
	cppVar_54899 = (cppVar_54899 & cppMask_un_16_);
	cppVar_54900 = ROM.rd(cppVar_54899);
	cppVar_54902 = (cppVar_54900 == 153);
	if (cppVar_54902) {
	cppVar_54898 = SBUF;
	} else {
	cppVar_54904 = PC + 1;
	cppVar_54904 = (cppVar_54904 & cppMask_un_16_);
	cppVar_54905 = ROM.rd(cppVar_54904);
	cppVar_54907 = (cppVar_54905 == 160);
	if (cppVar_54907) {
	cppVar_54903 = P2;
	} else {
	cppVar_54909 = PC + 1;
	cppVar_54909 = (cppVar_54909 & cppMask_un_16_);
	cppVar_54910 = ROM.rd(cppVar_54909);
	cppVar_54912 = (cppVar_54910 == 168);
	if (cppVar_54912) {
	cppVar_54908 = IE;
	} else {
	cppVar_54914 = PC + 1;
	cppVar_54914 = (cppVar_54914 & cppMask_un_16_);
	cppVar_54915 = ROM.rd(cppVar_54914);
	cppVar_54917 = (cppVar_54915 == 176);
	if (cppVar_54917) {
	cppVar_54913 = P3;
	} else {
	cppVar_54919 = PC + 1;
	cppVar_54919 = (cppVar_54919 & cppMask_un_16_);
	cppVar_54920 = ROM.rd(cppVar_54919);
	cppVar_54922 = (cppVar_54920 == 184);
	if (cppVar_54922) {
	cppVar_54918 = IP;
	} else {
	cppVar_54924 = PC + 1;
	cppVar_54924 = (cppVar_54924 & cppMask_un_16_);
	cppVar_54925 = ROM.rd(cppVar_54924);
	cppVar_54927 = (cppVar_54925 == 208);
	if (cppVar_54927) {
	cppVar_54923 = PSW;
	} else {
	cppVar_54929 = PC + 1;
	cppVar_54929 = (cppVar_54929 & cppMask_un_16_);
	cppVar_54930 = ROM.rd(cppVar_54929);
	cppVar_54932 = (cppVar_54930 == 224);
	if (cppVar_54932) {
	cppVar_54928 = ACC;
	} else {
	cppVar_54934 = PC + 1;
	cppVar_54934 = (cppVar_54934 & cppMask_un_16_);
	cppVar_54935 = ROM.rd(cppVar_54934);
	cppVar_54937 = (cppVar_54935 == 240);
	if (cppVar_54937) {
	cppVar_54933 = B;
	} else {
	cppVar_54933 = 0;
	}
	cppVar_54928 = cppVar_54933;
	}
	cppVar_54923 = cppVar_54928;
	}
	cppVar_54918 = cppVar_54923;
	}
	cppVar_54913 = cppVar_54918;
	}
	cppVar_54908 = cppVar_54913;
	}
	cppVar_54903 = cppVar_54908;
	}
	cppVar_54898 = cppVar_54903;
	}
	cppVar_54893 = cppVar_54898;
	}
	cppVar_54888 = cppVar_54893;
	}
	cppVar_54883 = cppVar_54888;
	}
	cppVar_54878 = cppVar_54883;
	}
	cppVar_54873 = cppVar_54878;
	}
	cppVar_54868 = cppVar_54873;
	}
	cppVar_54863 = cppVar_54868;
	}
	cppVar_54858 = cppVar_54863;
	}
	cppVar_54853 = cppVar_54858;
	}
	cppVar_54848 = cppVar_54853;
	}
	cppVar_54843 = cppVar_54848;
	}
	cppVar_54838 = cppVar_54843;
	}
	cppVar_54833 = cppVar_54838;
	}
	cppVar_54823 = cppVar_54833;
	}
	cppVar_54939 = (cppVar_54823 & cppMask_un_8_);
	cppVar_54940 = cppVar_54822 + cppVar_54939;
	cppVar_54940 = (cppVar_54940 & cppMask_un_9_);
	cppVar_54941 = (PSW >> 7) & cppMask_un_1_;
	cppVar_54942 = (cppVar_54941 & cppMask_un_1_);
	cppVar_54943 = cppVar_54940 + cppVar_54942;
	cppVar_54943 = (cppVar_54943 & cppMask_un_9_);
	cppVar_54944 = (cppVar_54943 >> 8) & cppMask_un_1_;
	cppVar_54945 = (ACC >> 0) & cppMask_un_4_;
	cppVar_54946 = (cppVar_54945 & cppMask_un_4_);
	cppVar_54948 = PC + 1;
	cppVar_54948 = (cppVar_54948 & cppMask_un_16_);
	cppVar_54949 = ROM.rd(cppVar_54948);
	cppVar_54950 = (cppVar_54949 >> 7) & cppMask_un_1_;
	cppVar_54951 = (cppVar_54950 == 0);
	if (cppVar_54951) {
	cppVar_54952 = PC + 1;
	cppVar_54952 = (cppVar_54952 & cppMask_un_16_);
	cppVar_54953 = ROM.rd(cppVar_54952);
	cppVar_54954 = IRAM.rd(cppVar_54953);
	cppVar_54947 = cppVar_54954;
	} else {
	cppVar_54956 = PC + 1;
	cppVar_54956 = (cppVar_54956 & cppMask_un_16_);
	cppVar_54957 = ROM.rd(cppVar_54956);
	cppVar_54958 = (cppVar_54957 == 128);
	if (cppVar_54958) {
	cppVar_54955 = P0;
	} else {
	cppVar_54960 = PC + 1;
	cppVar_54960 = (cppVar_54960 & cppMask_un_16_);
	cppVar_54961 = ROM.rd(cppVar_54960);
	cppVar_54962 = (cppVar_54961 == 129);
	if (cppVar_54962) {
	cppVar_54959 = SP;
	} else {
	cppVar_54964 = PC + 1;
	cppVar_54964 = (cppVar_54964 & cppMask_un_16_);
	cppVar_54965 = ROM.rd(cppVar_54964);
	cppVar_54966 = (cppVar_54965 == 130);
	if (cppVar_54966) {
	cppVar_54963 = DPL;
	} else {
	cppVar_54968 = PC + 1;
	cppVar_54968 = (cppVar_54968 & cppMask_un_16_);
	cppVar_54969 = ROM.rd(cppVar_54968);
	cppVar_54970 = (cppVar_54969 == 131);
	if (cppVar_54970) {
	cppVar_54967 = DPH;
	} else {
	cppVar_54972 = PC + 1;
	cppVar_54972 = (cppVar_54972 & cppMask_un_16_);
	cppVar_54973 = ROM.rd(cppVar_54972);
	cppVar_54974 = (cppVar_54973 == 135);
	if (cppVar_54974) {
	cppVar_54971 = PCON;
	} else {
	cppVar_54976 = PC + 1;
	cppVar_54976 = (cppVar_54976 & cppMask_un_16_);
	cppVar_54977 = ROM.rd(cppVar_54976);
	cppVar_54978 = (cppVar_54977 == 136);
	if (cppVar_54978) {
	cppVar_54975 = TCON;
	} else {
	cppVar_54980 = PC + 1;
	cppVar_54980 = (cppVar_54980 & cppMask_un_16_);
	cppVar_54981 = ROM.rd(cppVar_54980);
	cppVar_54982 = (cppVar_54981 == 137);
	if (cppVar_54982) {
	cppVar_54979 = TMOD;
	} else {
	cppVar_54984 = PC + 1;
	cppVar_54984 = (cppVar_54984 & cppMask_un_16_);
	cppVar_54985 = ROM.rd(cppVar_54984);
	cppVar_54986 = (cppVar_54985 == 138);
	if (cppVar_54986) {
	cppVar_54983 = TL0;
	} else {
	cppVar_54988 = PC + 1;
	cppVar_54988 = (cppVar_54988 & cppMask_un_16_);
	cppVar_54989 = ROM.rd(cppVar_54988);
	cppVar_54990 = (cppVar_54989 == 140);
	if (cppVar_54990) {
	cppVar_54987 = TH0;
	} else {
	cppVar_54992 = PC + 1;
	cppVar_54992 = (cppVar_54992 & cppMask_un_16_);
	cppVar_54993 = ROM.rd(cppVar_54992);
	cppVar_54994 = (cppVar_54993 == 139);
	if (cppVar_54994) {
	cppVar_54991 = TL1;
	} else {
	cppVar_54996 = PC + 1;
	cppVar_54996 = (cppVar_54996 & cppMask_un_16_);
	cppVar_54997 = ROM.rd(cppVar_54996);
	cppVar_54998 = (cppVar_54997 == 141);
	if (cppVar_54998) {
	cppVar_54995 = TH1;
	} else {
	cppVar_55000 = PC + 1;
	cppVar_55000 = (cppVar_55000 & cppMask_un_16_);
	cppVar_55001 = ROM.rd(cppVar_55000);
	cppVar_55002 = (cppVar_55001 == 144);
	if (cppVar_55002) {
	cppVar_54999 = P1;
	} else {
	cppVar_55004 = PC + 1;
	cppVar_55004 = (cppVar_55004 & cppMask_un_16_);
	cppVar_55005 = ROM.rd(cppVar_55004);
	cppVar_55006 = (cppVar_55005 == 152);
	if (cppVar_55006) {
	cppVar_55003 = SCON;
	} else {
	cppVar_55008 = PC + 1;
	cppVar_55008 = (cppVar_55008 & cppMask_un_16_);
	cppVar_55009 = ROM.rd(cppVar_55008);
	cppVar_55010 = (cppVar_55009 == 153);
	if (cppVar_55010) {
	cppVar_55007 = SBUF;
	} else {
	cppVar_55012 = PC + 1;
	cppVar_55012 = (cppVar_55012 & cppMask_un_16_);
	cppVar_55013 = ROM.rd(cppVar_55012);
	cppVar_55014 = (cppVar_55013 == 160);
	if (cppVar_55014) {
	cppVar_55011 = P2;
	} else {
	cppVar_55016 = PC + 1;
	cppVar_55016 = (cppVar_55016 & cppMask_un_16_);
	cppVar_55017 = ROM.rd(cppVar_55016);
	cppVar_55018 = (cppVar_55017 == 168);
	if (cppVar_55018) {
	cppVar_55015 = IE;
	} else {
	cppVar_55020 = PC + 1;
	cppVar_55020 = (cppVar_55020 & cppMask_un_16_);
	cppVar_55021 = ROM.rd(cppVar_55020);
	cppVar_55022 = (cppVar_55021 == 176);
	if (cppVar_55022) {
	cppVar_55019 = P3;
	} else {
	cppVar_55024 = PC + 1;
	cppVar_55024 = (cppVar_55024 & cppMask_un_16_);
	cppVar_55025 = ROM.rd(cppVar_55024);
	cppVar_55026 = (cppVar_55025 == 184);
	if (cppVar_55026) {
	cppVar_55023 = IP;
	} else {
	cppVar_55028 = PC + 1;
	cppVar_55028 = (cppVar_55028 & cppMask_un_16_);
	cppVar_55029 = ROM.rd(cppVar_55028);
	cppVar_55030 = (cppVar_55029 == 208);
	if (cppVar_55030) {
	cppVar_55027 = PSW;
	} else {
	cppVar_55032 = PC + 1;
	cppVar_55032 = (cppVar_55032 & cppMask_un_16_);
	cppVar_55033 = ROM.rd(cppVar_55032);
	cppVar_55034 = (cppVar_55033 == 224);
	if (cppVar_55034) {
	cppVar_55031 = ACC;
	} else {
	cppVar_55036 = PC + 1;
	cppVar_55036 = (cppVar_55036 & cppMask_un_16_);
	cppVar_55037 = ROM.rd(cppVar_55036);
	cppVar_55038 = (cppVar_55037 == 240);
	if (cppVar_55038) {
	cppVar_55035 = B;
	} else {
	cppVar_55035 = 0;
	}
	cppVar_55031 = cppVar_55035;
	}
	cppVar_55027 = cppVar_55031;
	}
	cppVar_55023 = cppVar_55027;
	}
	cppVar_55019 = cppVar_55023;
	}
	cppVar_55015 = cppVar_55019;
	}
	cppVar_55011 = cppVar_55015;
	}
	cppVar_55007 = cppVar_55011;
	}
	cppVar_55003 = cppVar_55007;
	}
	cppVar_54999 = cppVar_55003;
	}
	cppVar_54995 = cppVar_54999;
	}
	cppVar_54991 = cppVar_54995;
	}
	cppVar_54987 = cppVar_54991;
	}
	cppVar_54983 = cppVar_54987;
	}
	cppVar_54979 = cppVar_54983;
	}
	cppVar_54975 = cppVar_54979;
	}
	cppVar_54971 = cppVar_54975;
	}
	cppVar_54967 = cppVar_54971;
	}
	cppVar_54963 = cppVar_54967;
	}
	cppVar_54959 = cppVar_54963;
	}
	cppVar_54955 = cppVar_54959;
	}
	cppVar_54947 = cppVar_54955;
	}
	cppVar_55039 = (cppVar_54947 >> 0) & cppMask_un_4_;
	cppVar_55040 = (cppVar_55039 & cppMask_un_4_);
	cppVar_55041 = cppVar_54946 + cppVar_55040;
	cppVar_55041 = (cppVar_55041 & cppMask_un_5_);
	cppVar_55042 = (PSW >> 7) & cppMask_un_1_;
	cppVar_55043 = (cppVar_55042 & cppMask_un_1_);
	cppVar_55044 = cppVar_55041 + cppVar_55043;
	cppVar_55044 = (cppVar_55044 & cppMask_un_5_);
	cppVar_55045 = (cppVar_55044 >> 4) & cppMask_un_1_;
	cppVar_55046 = (PSW >> 3) & cppMask_un_3_;
	cppVar_55048 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55050 = PC + 1;
	cppVar_55050 = (cppVar_55050 & cppMask_un_16_);
	cppVar_55051 = ROM.rd(cppVar_55050);
	cppVar_55052 = (cppVar_55051 >> 7) & cppMask_un_1_;
	cppVar_55053 = (cppVar_55052 == 0);
	if (cppVar_55053) {
	cppVar_55054 = PC + 1;
	cppVar_55054 = (cppVar_55054 & cppMask_un_16_);
	cppVar_55055 = ROM.rd(cppVar_55054);
	cppVar_55056 = IRAM.rd(cppVar_55055);
	cppVar_55049 = cppVar_55056;
	} else {
	cppVar_55058 = PC + 1;
	cppVar_55058 = (cppVar_55058 & cppMask_un_16_);
	cppVar_55059 = ROM.rd(cppVar_55058);
	cppVar_55060 = (cppVar_55059 == 128);
	if (cppVar_55060) {
	cppVar_55057 = P0;
	} else {
	cppVar_55062 = PC + 1;
	cppVar_55062 = (cppVar_55062 & cppMask_un_16_);
	cppVar_55063 = ROM.rd(cppVar_55062);
	cppVar_55064 = (cppVar_55063 == 129);
	if (cppVar_55064) {
	cppVar_55061 = SP;
	} else {
	cppVar_55066 = PC + 1;
	cppVar_55066 = (cppVar_55066 & cppMask_un_16_);
	cppVar_55067 = ROM.rd(cppVar_55066);
	cppVar_55068 = (cppVar_55067 == 130);
	if (cppVar_55068) {
	cppVar_55065 = DPL;
	} else {
	cppVar_55070 = PC + 1;
	cppVar_55070 = (cppVar_55070 & cppMask_un_16_);
	cppVar_55071 = ROM.rd(cppVar_55070);
	cppVar_55072 = (cppVar_55071 == 131);
	if (cppVar_55072) {
	cppVar_55069 = DPH;
	} else {
	cppVar_55074 = PC + 1;
	cppVar_55074 = (cppVar_55074 & cppMask_un_16_);
	cppVar_55075 = ROM.rd(cppVar_55074);
	cppVar_55076 = (cppVar_55075 == 135);
	if (cppVar_55076) {
	cppVar_55073 = PCON;
	} else {
	cppVar_55078 = PC + 1;
	cppVar_55078 = (cppVar_55078 & cppMask_un_16_);
	cppVar_55079 = ROM.rd(cppVar_55078);
	cppVar_55080 = (cppVar_55079 == 136);
	if (cppVar_55080) {
	cppVar_55077 = TCON;
	} else {
	cppVar_55082 = PC + 1;
	cppVar_55082 = (cppVar_55082 & cppMask_un_16_);
	cppVar_55083 = ROM.rd(cppVar_55082);
	cppVar_55084 = (cppVar_55083 == 137);
	if (cppVar_55084) {
	cppVar_55081 = TMOD;
	} else {
	cppVar_55086 = PC + 1;
	cppVar_55086 = (cppVar_55086 & cppMask_un_16_);
	cppVar_55087 = ROM.rd(cppVar_55086);
	cppVar_55088 = (cppVar_55087 == 138);
	if (cppVar_55088) {
	cppVar_55085 = TL0;
	} else {
	cppVar_55090 = PC + 1;
	cppVar_55090 = (cppVar_55090 & cppMask_un_16_);
	cppVar_55091 = ROM.rd(cppVar_55090);
	cppVar_55092 = (cppVar_55091 == 140);
	if (cppVar_55092) {
	cppVar_55089 = TH0;
	} else {
	cppVar_55094 = PC + 1;
	cppVar_55094 = (cppVar_55094 & cppMask_un_16_);
	cppVar_55095 = ROM.rd(cppVar_55094);
	cppVar_55096 = (cppVar_55095 == 139);
	if (cppVar_55096) {
	cppVar_55093 = TL1;
	} else {
	cppVar_55098 = PC + 1;
	cppVar_55098 = (cppVar_55098 & cppMask_un_16_);
	cppVar_55099 = ROM.rd(cppVar_55098);
	cppVar_55100 = (cppVar_55099 == 141);
	if (cppVar_55100) {
	cppVar_55097 = TH1;
	} else {
	cppVar_55102 = PC + 1;
	cppVar_55102 = (cppVar_55102 & cppMask_un_16_);
	cppVar_55103 = ROM.rd(cppVar_55102);
	cppVar_55104 = (cppVar_55103 == 144);
	if (cppVar_55104) {
	cppVar_55101 = P1;
	} else {
	cppVar_55106 = PC + 1;
	cppVar_55106 = (cppVar_55106 & cppMask_un_16_);
	cppVar_55107 = ROM.rd(cppVar_55106);
	cppVar_55108 = (cppVar_55107 == 152);
	if (cppVar_55108) {
	cppVar_55105 = SCON;
	} else {
	cppVar_55110 = PC + 1;
	cppVar_55110 = (cppVar_55110 & cppMask_un_16_);
	cppVar_55111 = ROM.rd(cppVar_55110);
	cppVar_55112 = (cppVar_55111 == 153);
	if (cppVar_55112) {
	cppVar_55109 = SBUF;
	} else {
	cppVar_55114 = PC + 1;
	cppVar_55114 = (cppVar_55114 & cppMask_un_16_);
	cppVar_55115 = ROM.rd(cppVar_55114);
	cppVar_55116 = (cppVar_55115 == 160);
	if (cppVar_55116) {
	cppVar_55113 = P2;
	} else {
	cppVar_55118 = PC + 1;
	cppVar_55118 = (cppVar_55118 & cppMask_un_16_);
	cppVar_55119 = ROM.rd(cppVar_55118);
	cppVar_55120 = (cppVar_55119 == 168);
	if (cppVar_55120) {
	cppVar_55117 = IE;
	} else {
	cppVar_55122 = PC + 1;
	cppVar_55122 = (cppVar_55122 & cppMask_un_16_);
	cppVar_55123 = ROM.rd(cppVar_55122);
	cppVar_55124 = (cppVar_55123 == 176);
	if (cppVar_55124) {
	cppVar_55121 = P3;
	} else {
	cppVar_55126 = PC + 1;
	cppVar_55126 = (cppVar_55126 & cppMask_un_16_);
	cppVar_55127 = ROM.rd(cppVar_55126);
	cppVar_55128 = (cppVar_55127 == 184);
	if (cppVar_55128) {
	cppVar_55125 = IP;
	} else {
	cppVar_55130 = PC + 1;
	cppVar_55130 = (cppVar_55130 & cppMask_un_16_);
	cppVar_55131 = ROM.rd(cppVar_55130);
	cppVar_55132 = (cppVar_55131 == 208);
	if (cppVar_55132) {
	cppVar_55129 = PSW;
	} else {
	cppVar_55134 = PC + 1;
	cppVar_55134 = (cppVar_55134 & cppMask_un_16_);
	cppVar_55135 = ROM.rd(cppVar_55134);
	cppVar_55136 = (cppVar_55135 == 224);
	if (cppVar_55136) {
	cppVar_55133 = ACC;
	} else {
	cppVar_55138 = PC + 1;
	cppVar_55138 = (cppVar_55138 & cppMask_un_16_);
	cppVar_55139 = ROM.rd(cppVar_55138);
	cppVar_55140 = (cppVar_55139 == 240);
	if (cppVar_55140) {
	cppVar_55137 = B;
	} else {
	cppVar_55137 = 0;
	}
	cppVar_55133 = cppVar_55137;
	}
	cppVar_55129 = cppVar_55133;
	}
	cppVar_55125 = cppVar_55129;
	}
	cppVar_55121 = cppVar_55125;
	}
	cppVar_55117 = cppVar_55121;
	}
	cppVar_55113 = cppVar_55117;
	}
	cppVar_55109 = cppVar_55113;
	}
	cppVar_55105 = cppVar_55109;
	}
	cppVar_55101 = cppVar_55105;
	}
	cppVar_55097 = cppVar_55101;
	}
	cppVar_55093 = cppVar_55097;
	}
	cppVar_55089 = cppVar_55093;
	}
	cppVar_55085 = cppVar_55089;
	}
	cppVar_55081 = cppVar_55085;
	}
	cppVar_55077 = cppVar_55081;
	}
	cppVar_55073 = cppVar_55077;
	}
	cppVar_55069 = cppVar_55073;
	}
	cppVar_55065 = cppVar_55069;
	}
	cppVar_55061 = cppVar_55065;
	}
	cppVar_55057 = cppVar_55061;
	}
	cppVar_55049 = cppVar_55057;
	}
	cppVar_55141 = ((cppVar_55049 & cppMask_bit_8_) ? (cppVar_55049 | cppMask_sign_8_) : cppVar_55049);
	cppVar_55142 = cppVar_55048 + cppVar_55141;
	cppVar_55142 = (cppVar_55142 & cppMask_un_9_);
	cppVar_55143 = (PSW >> 7) & cppMask_un_1_;
	cppVar_55144 = (cppVar_55143 & cppMask_un_1_);
	cppVar_55145 = cppVar_55142 + cppVar_55144;
	cppVar_55145 = (cppVar_55145 & cppMask_un_9_);
	cppVar_55146 = (cppVar_55145 >> 8) & cppMask_un_1_;
	cppVar_55147 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55149 = PC + 1;
	cppVar_55149 = (cppVar_55149 & cppMask_un_16_);
	cppVar_55150 = ROM.rd(cppVar_55149);
	cppVar_55151 = (cppVar_55150 >> 7) & cppMask_un_1_;
	cppVar_55152 = (cppVar_55151 == 0);
	if (cppVar_55152) {
	cppVar_55153 = PC + 1;
	cppVar_55153 = (cppVar_55153 & cppMask_un_16_);
	cppVar_55154 = ROM.rd(cppVar_55153);
	cppVar_55155 = IRAM.rd(cppVar_55154);
	cppVar_55148 = cppVar_55155;
	} else {
	cppVar_55157 = PC + 1;
	cppVar_55157 = (cppVar_55157 & cppMask_un_16_);
	cppVar_55158 = ROM.rd(cppVar_55157);
	cppVar_55159 = (cppVar_55158 == 128);
	if (cppVar_55159) {
	cppVar_55156 = P0;
	} else {
	cppVar_55161 = PC + 1;
	cppVar_55161 = (cppVar_55161 & cppMask_un_16_);
	cppVar_55162 = ROM.rd(cppVar_55161);
	cppVar_55163 = (cppVar_55162 == 129);
	if (cppVar_55163) {
	cppVar_55160 = SP;
	} else {
	cppVar_55165 = PC + 1;
	cppVar_55165 = (cppVar_55165 & cppMask_un_16_);
	cppVar_55166 = ROM.rd(cppVar_55165);
	cppVar_55167 = (cppVar_55166 == 130);
	if (cppVar_55167) {
	cppVar_55164 = DPL;
	} else {
	cppVar_55169 = PC + 1;
	cppVar_55169 = (cppVar_55169 & cppMask_un_16_);
	cppVar_55170 = ROM.rd(cppVar_55169);
	cppVar_55171 = (cppVar_55170 == 131);
	if (cppVar_55171) {
	cppVar_55168 = DPH;
	} else {
	cppVar_55173 = PC + 1;
	cppVar_55173 = (cppVar_55173 & cppMask_un_16_);
	cppVar_55174 = ROM.rd(cppVar_55173);
	cppVar_55175 = (cppVar_55174 == 135);
	if (cppVar_55175) {
	cppVar_55172 = PCON;
	} else {
	cppVar_55177 = PC + 1;
	cppVar_55177 = (cppVar_55177 & cppMask_un_16_);
	cppVar_55178 = ROM.rd(cppVar_55177);
	cppVar_55179 = (cppVar_55178 == 136);
	if (cppVar_55179) {
	cppVar_55176 = TCON;
	} else {
	cppVar_55181 = PC + 1;
	cppVar_55181 = (cppVar_55181 & cppMask_un_16_);
	cppVar_55182 = ROM.rd(cppVar_55181);
	cppVar_55183 = (cppVar_55182 == 137);
	if (cppVar_55183) {
	cppVar_55180 = TMOD;
	} else {
	cppVar_55185 = PC + 1;
	cppVar_55185 = (cppVar_55185 & cppMask_un_16_);
	cppVar_55186 = ROM.rd(cppVar_55185);
	cppVar_55187 = (cppVar_55186 == 138);
	if (cppVar_55187) {
	cppVar_55184 = TL0;
	} else {
	cppVar_55189 = PC + 1;
	cppVar_55189 = (cppVar_55189 & cppMask_un_16_);
	cppVar_55190 = ROM.rd(cppVar_55189);
	cppVar_55191 = (cppVar_55190 == 140);
	if (cppVar_55191) {
	cppVar_55188 = TH0;
	} else {
	cppVar_55193 = PC + 1;
	cppVar_55193 = (cppVar_55193 & cppMask_un_16_);
	cppVar_55194 = ROM.rd(cppVar_55193);
	cppVar_55195 = (cppVar_55194 == 139);
	if (cppVar_55195) {
	cppVar_55192 = TL1;
	} else {
	cppVar_55197 = PC + 1;
	cppVar_55197 = (cppVar_55197 & cppMask_un_16_);
	cppVar_55198 = ROM.rd(cppVar_55197);
	cppVar_55199 = (cppVar_55198 == 141);
	if (cppVar_55199) {
	cppVar_55196 = TH1;
	} else {
	cppVar_55201 = PC + 1;
	cppVar_55201 = (cppVar_55201 & cppMask_un_16_);
	cppVar_55202 = ROM.rd(cppVar_55201);
	cppVar_55203 = (cppVar_55202 == 144);
	if (cppVar_55203) {
	cppVar_55200 = P1;
	} else {
	cppVar_55205 = PC + 1;
	cppVar_55205 = (cppVar_55205 & cppMask_un_16_);
	cppVar_55206 = ROM.rd(cppVar_55205);
	cppVar_55207 = (cppVar_55206 == 152);
	if (cppVar_55207) {
	cppVar_55204 = SCON;
	} else {
	cppVar_55209 = PC + 1;
	cppVar_55209 = (cppVar_55209 & cppMask_un_16_);
	cppVar_55210 = ROM.rd(cppVar_55209);
	cppVar_55211 = (cppVar_55210 == 153);
	if (cppVar_55211) {
	cppVar_55208 = SBUF;
	} else {
	cppVar_55213 = PC + 1;
	cppVar_55213 = (cppVar_55213 & cppMask_un_16_);
	cppVar_55214 = ROM.rd(cppVar_55213);
	cppVar_55215 = (cppVar_55214 == 160);
	if (cppVar_55215) {
	cppVar_55212 = P2;
	} else {
	cppVar_55217 = PC + 1;
	cppVar_55217 = (cppVar_55217 & cppMask_un_16_);
	cppVar_55218 = ROM.rd(cppVar_55217);
	cppVar_55219 = (cppVar_55218 == 168);
	if (cppVar_55219) {
	cppVar_55216 = IE;
	} else {
	cppVar_55221 = PC + 1;
	cppVar_55221 = (cppVar_55221 & cppMask_un_16_);
	cppVar_55222 = ROM.rd(cppVar_55221);
	cppVar_55223 = (cppVar_55222 == 176);
	if (cppVar_55223) {
	cppVar_55220 = P3;
	} else {
	cppVar_55225 = PC + 1;
	cppVar_55225 = (cppVar_55225 & cppMask_un_16_);
	cppVar_55226 = ROM.rd(cppVar_55225);
	cppVar_55227 = (cppVar_55226 == 184);
	if (cppVar_55227) {
	cppVar_55224 = IP;
	} else {
	cppVar_55229 = PC + 1;
	cppVar_55229 = (cppVar_55229 & cppMask_un_16_);
	cppVar_55230 = ROM.rd(cppVar_55229);
	cppVar_55231 = (cppVar_55230 == 208);
	if (cppVar_55231) {
	cppVar_55228 = PSW;
	} else {
	cppVar_55233 = PC + 1;
	cppVar_55233 = (cppVar_55233 & cppMask_un_16_);
	cppVar_55234 = ROM.rd(cppVar_55233);
	cppVar_55235 = (cppVar_55234 == 224);
	if (cppVar_55235) {
	cppVar_55232 = ACC;
	} else {
	cppVar_55237 = PC + 1;
	cppVar_55237 = (cppVar_55237 & cppMask_un_16_);
	cppVar_55238 = ROM.rd(cppVar_55237);
	cppVar_55239 = (cppVar_55238 == 240);
	if (cppVar_55239) {
	cppVar_55236 = B;
	} else {
	cppVar_55236 = 0;
	}
	cppVar_55232 = cppVar_55236;
	}
	cppVar_55228 = cppVar_55232;
	}
	cppVar_55224 = cppVar_55228;
	}
	cppVar_55220 = cppVar_55224;
	}
	cppVar_55216 = cppVar_55220;
	}
	cppVar_55212 = cppVar_55216;
	}
	cppVar_55208 = cppVar_55212;
	}
	cppVar_55204 = cppVar_55208;
	}
	cppVar_55200 = cppVar_55204;
	}
	cppVar_55196 = cppVar_55200;
	}
	cppVar_55192 = cppVar_55196;
	}
	cppVar_55188 = cppVar_55192;
	}
	cppVar_55184 = cppVar_55188;
	}
	cppVar_55180 = cppVar_55184;
	}
	cppVar_55176 = cppVar_55180;
	}
	cppVar_55172 = cppVar_55176;
	}
	cppVar_55168 = cppVar_55172;
	}
	cppVar_55164 = cppVar_55168;
	}
	cppVar_55160 = cppVar_55164;
	}
	cppVar_55156 = cppVar_55160;
	}
	cppVar_55148 = cppVar_55156;
	}
	cppVar_55240 = ((cppVar_55148 & cppMask_bit_8_) ? (cppVar_55148 | cppMask_sign_8_) : cppVar_55148);
	cppVar_55241 = cppVar_55147 + cppVar_55240;
	cppVar_55241 = (cppVar_55241 & cppMask_un_9_);
	cppVar_55242 = (PSW >> 7) & cppMask_un_1_;
	cppVar_55243 = (cppVar_55242 & cppMask_un_1_);
	cppVar_55244 = cppVar_55241 + cppVar_55243;
	cppVar_55244 = (cppVar_55244 & cppMask_un_9_);
	cppVar_55245 = (cppVar_55244 >> 7) & cppMask_un_1_;
	cppVar_55246 = (cppVar_55146 != cppVar_55245);
	if (cppVar_55246) {
	cppVar_55047 = 1;
	} else {
	cppVar_55047 = 0;
	}
	cppVar_55249 = (PSW >> 0) & cppMask_un_2_;
	cppVar_55250 = (cppVar_55047 << 2) | cppVar_55249;
	cppVar_55250 = (cppVar_55250 & cppMask_un_3_);
	cppVar_55251 = (cppVar_55046 << 3) | cppVar_55250;
	cppVar_55251 = (cppVar_55251 & cppMask_un_6_);
	cppVar_55252 = (cppVar_55045 << 6) | cppVar_55251;
	cppVar_55252 = (cppVar_55252 & cppMask_un_7_);
	cppVar_55253 = (cppVar_54944 << 7) | cppVar_55252;
	cppVar_55253 = (cppVar_55253 & cppMask_un_8_);
	cppVar_54818 = cppVar_55253;
	} else {
	cppVar_55255 = ROM.rd(PC);
	cppVar_55257 = (cppVar_55255 == 52);
	if (cppVar_55257) {
	cppVar_55258 = (ACC & cppMask_un_8_);
	cppVar_55260 = PC + 1;
	cppVar_55260 = (cppVar_55260 & cppMask_un_16_);
	cppVar_55261 = ROM.rd(cppVar_55260);
	cppVar_55262 = (cppVar_55261 & cppMask_un_8_);
	cppVar_55263 = cppVar_55258 + cppVar_55262;
	cppVar_55263 = (cppVar_55263 & cppMask_un_9_);
	cppVar_55264 = (PSW >> 7) & cppMask_un_1_;
	cppVar_55265 = (cppVar_55264 & cppMask_un_1_);
	cppVar_55266 = cppVar_55263 + cppVar_55265;
	cppVar_55266 = (cppVar_55266 & cppMask_un_9_);
	cppVar_55267 = (cppVar_55266 >> 8) & cppMask_un_1_;
	cppVar_55268 = (ACC >> 0) & cppMask_un_4_;
	cppVar_55269 = (cppVar_55268 & cppMask_un_4_);
	cppVar_55270 = PC + 1;
	cppVar_55270 = (cppVar_55270 & cppMask_un_16_);
	cppVar_55271 = ROM.rd(cppVar_55270);
	cppVar_55272 = (cppVar_55271 >> 0) & cppMask_un_4_;
	cppVar_55273 = (cppVar_55272 & cppMask_un_4_);
	cppVar_55274 = cppVar_55269 + cppVar_55273;
	cppVar_55274 = (cppVar_55274 & cppMask_un_5_);
	cppVar_55275 = (PSW >> 7) & cppMask_un_1_;
	cppVar_55276 = (cppVar_55275 & cppMask_un_1_);
	cppVar_55277 = cppVar_55274 + cppVar_55276;
	cppVar_55277 = (cppVar_55277 & cppMask_un_5_);
	cppVar_55278 = (cppVar_55277 >> 4) & cppMask_un_1_;
	cppVar_55279 = (PSW >> 3) & cppMask_un_3_;
	cppVar_55281 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55282 = PC + 1;
	cppVar_55282 = (cppVar_55282 & cppMask_un_16_);
	cppVar_55283 = ROM.rd(cppVar_55282);
	cppVar_55284 = ((cppVar_55283 & cppMask_bit_8_) ? (cppVar_55283 | cppMask_sign_8_) : cppVar_55283);
	cppVar_55285 = cppVar_55281 + cppVar_55284;
	cppVar_55285 = (cppVar_55285 & cppMask_un_9_);
	cppVar_55286 = (PSW >> 7) & cppMask_un_1_;
	cppVar_55287 = (cppVar_55286 & cppMask_un_1_);
	cppVar_55288 = cppVar_55285 + cppVar_55287;
	cppVar_55288 = (cppVar_55288 & cppMask_un_9_);
	cppVar_55289 = (cppVar_55288 >> 8) & cppMask_un_1_;
	cppVar_55290 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55291 = PC + 1;
	cppVar_55291 = (cppVar_55291 & cppMask_un_16_);
	cppVar_55292 = ROM.rd(cppVar_55291);
	cppVar_55293 = ((cppVar_55292 & cppMask_bit_8_) ? (cppVar_55292 | cppMask_sign_8_) : cppVar_55292);
	cppVar_55294 = cppVar_55290 + cppVar_55293;
	cppVar_55294 = (cppVar_55294 & cppMask_un_9_);
	cppVar_55295 = (PSW >> 7) & cppMask_un_1_;
	cppVar_55296 = (cppVar_55295 & cppMask_un_1_);
	cppVar_55297 = cppVar_55294 + cppVar_55296;
	cppVar_55297 = (cppVar_55297 & cppMask_un_9_);
	cppVar_55298 = (cppVar_55297 >> 7) & cppMask_un_1_;
	cppVar_55299 = (cppVar_55289 != cppVar_55298);
	if (cppVar_55299) {
	cppVar_55280 = 1;
	} else {
	cppVar_55280 = 0;
	}
	cppVar_55302 = (PSW >> 0) & cppMask_un_2_;
	cppVar_55303 = (cppVar_55280 << 2) | cppVar_55302;
	cppVar_55303 = (cppVar_55303 & cppMask_un_3_);
	cppVar_55304 = (cppVar_55279 << 3) | cppVar_55303;
	cppVar_55304 = (cppVar_55304 & cppMask_un_6_);
	cppVar_55305 = (cppVar_55278 << 6) | cppVar_55304;
	cppVar_55305 = (cppVar_55305 & cppMask_un_7_);
	cppVar_55306 = (cppVar_55267 << 7) | cppVar_55305;
	cppVar_55306 = (cppVar_55306 & cppMask_un_8_);
	cppVar_55254 = cppVar_55306;
	} else {
	cppVar_55308 = ROM.rd(PC);
	cppVar_55310 = (cppVar_55308 == 51);
	if (cppVar_55310) {
	cppVar_55311 = (ACC >> 7) & cppMask_un_1_;
	cppVar_55312 = (PSW >> 6) & cppMask_un_1_;
	cppVar_55313 = (PSW >> 3) & cppMask_un_3_;
	cppVar_55314 = (PSW >> 2) & cppMask_un_1_;
	cppVar_55315 = (PSW >> 0) & cppMask_un_2_;
	cppVar_55316 = (cppVar_55314 << 2) | cppVar_55315;
	cppVar_55316 = (cppVar_55316 & cppMask_un_3_);
	cppVar_55317 = (cppVar_55313 << 3) | cppVar_55316;
	cppVar_55317 = (cppVar_55317 & cppMask_un_6_);
	cppVar_55318 = (cppVar_55312 << 6) | cppVar_55317;
	cppVar_55318 = (cppVar_55318 & cppMask_un_7_);
	cppVar_55319 = (cppVar_55311 << 7) | cppVar_55318;
	cppVar_55319 = (cppVar_55319 & cppMask_un_8_);
	cppVar_55307 = cppVar_55319;
	} else {
	cppVar_55321 = ROM.rd(PC);
	cppVar_55323 = (cppVar_55321 == 47);
	if (cppVar_55323) {
	cppVar_55324 = (ACC & cppMask_un_8_);
	cppVar_55326 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55328 = (cppVar_55326 << 3) | 7;
	cppVar_55328 = (cppVar_55328 & cppMask_un_5_);
	cppVar_55329 = (0 << 5) | cppVar_55328;
	cppVar_55329 = (cppVar_55329 & cppMask_un_8_);
	cppVar_55330 = IRAM.rd(cppVar_55329);
	cppVar_55331 = (cppVar_55330 & cppMask_un_8_);
	cppVar_55332 = cppVar_55324 + cppVar_55331;
	cppVar_55332 = (cppVar_55332 & cppMask_un_9_);
	cppVar_55334 = 0;
	cppVar_55335 = cppVar_55332 + cppVar_55334;
	cppVar_55335 = (cppVar_55335 & cppMask_un_9_);
	cppVar_55336 = (cppVar_55335 >> 8) & cppMask_un_1_;
	cppVar_55337 = (ACC >> 0) & cppMask_un_4_;
	cppVar_55338 = (cppVar_55337 & cppMask_un_4_);
	cppVar_55339 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55340 = (cppVar_55339 << 3) | 7;
	cppVar_55340 = (cppVar_55340 & cppMask_un_5_);
	cppVar_55341 = (0 << 5) | cppVar_55340;
	cppVar_55341 = (cppVar_55341 & cppMask_un_8_);
	cppVar_55342 = IRAM.rd(cppVar_55341);
	cppVar_55343 = (cppVar_55342 >> 0) & cppMask_un_4_;
	cppVar_55344 = (cppVar_55343 & cppMask_un_4_);
	cppVar_55345 = cppVar_55338 + cppVar_55344;
	cppVar_55345 = (cppVar_55345 & cppMask_un_5_);
	cppVar_55346 = 0;
	cppVar_55347 = cppVar_55345 + cppVar_55346;
	cppVar_55347 = (cppVar_55347 & cppMask_un_5_);
	cppVar_55348 = (cppVar_55347 >> 4) & cppMask_un_1_;
	cppVar_55349 = (PSW >> 3) & cppMask_un_3_;
	cppVar_55351 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55352 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55353 = (cppVar_55352 << 3) | 7;
	cppVar_55353 = (cppVar_55353 & cppMask_un_5_);
	cppVar_55354 = (0 << 5) | cppVar_55353;
	cppVar_55354 = (cppVar_55354 & cppMask_un_8_);
	cppVar_55355 = IRAM.rd(cppVar_55354);
	cppVar_55356 = ((cppVar_55355 & cppMask_bit_8_) ? (cppVar_55355 | cppMask_sign_8_) : cppVar_55355);
	cppVar_55357 = cppVar_55351 + cppVar_55356;
	cppVar_55357 = (cppVar_55357 & cppMask_un_9_);
	cppVar_55358 = 0;
	cppVar_55359 = cppVar_55357 + cppVar_55358;
	cppVar_55359 = (cppVar_55359 & cppMask_un_9_);
	cppVar_55360 = (cppVar_55359 >> 8) & cppMask_un_1_;
	cppVar_55361 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55362 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55363 = (cppVar_55362 << 3) | 7;
	cppVar_55363 = (cppVar_55363 & cppMask_un_5_);
	cppVar_55364 = (0 << 5) | cppVar_55363;
	cppVar_55364 = (cppVar_55364 & cppMask_un_8_);
	cppVar_55365 = IRAM.rd(cppVar_55364);
	cppVar_55366 = ((cppVar_55365 & cppMask_bit_8_) ? (cppVar_55365 | cppMask_sign_8_) : cppVar_55365);
	cppVar_55367 = cppVar_55361 + cppVar_55366;
	cppVar_55367 = (cppVar_55367 & cppMask_un_9_);
	cppVar_55368 = 0;
	cppVar_55369 = cppVar_55367 + cppVar_55368;
	cppVar_55369 = (cppVar_55369 & cppMask_un_9_);
	cppVar_55370 = (cppVar_55369 >> 7) & cppMask_un_1_;
	cppVar_55371 = (cppVar_55360 != cppVar_55370);
	if (cppVar_55371) {
	cppVar_55350 = 1;
	} else {
	cppVar_55350 = 0;
	}
	cppVar_55374 = (PSW >> 0) & cppMask_un_2_;
	cppVar_55375 = (cppVar_55350 << 2) | cppVar_55374;
	cppVar_55375 = (cppVar_55375 & cppMask_un_3_);
	cppVar_55376 = (cppVar_55349 << 3) | cppVar_55375;
	cppVar_55376 = (cppVar_55376 & cppMask_un_6_);
	cppVar_55377 = (cppVar_55348 << 6) | cppVar_55376;
	cppVar_55377 = (cppVar_55377 & cppMask_un_7_);
	cppVar_55378 = (cppVar_55336 << 7) | cppVar_55377;
	cppVar_55378 = (cppVar_55378 & cppMask_un_8_);
	cppVar_55320 = cppVar_55378;
	} else {
	cppVar_55380 = ROM.rd(PC);
	cppVar_55382 = (cppVar_55380 == 46);
	if (cppVar_55382) {
	cppVar_55383 = (ACC & cppMask_un_8_);
	cppVar_55385 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55387 = (cppVar_55385 << 3) | 6;
	cppVar_55387 = (cppVar_55387 & cppMask_un_5_);
	cppVar_55388 = (0 << 5) | cppVar_55387;
	cppVar_55388 = (cppVar_55388 & cppMask_un_8_);
	cppVar_55389 = IRAM.rd(cppVar_55388);
	cppVar_55390 = (cppVar_55389 & cppMask_un_8_);
	cppVar_55391 = cppVar_55383 + cppVar_55390;
	cppVar_55391 = (cppVar_55391 & cppMask_un_9_);
	cppVar_55393 = 0;
	cppVar_55394 = cppVar_55391 + cppVar_55393;
	cppVar_55394 = (cppVar_55394 & cppMask_un_9_);
	cppVar_55395 = (cppVar_55394 >> 8) & cppMask_un_1_;
	cppVar_55396 = (ACC >> 0) & cppMask_un_4_;
	cppVar_55397 = (cppVar_55396 & cppMask_un_4_);
	cppVar_55398 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55399 = (cppVar_55398 << 3) | 6;
	cppVar_55399 = (cppVar_55399 & cppMask_un_5_);
	cppVar_55400 = (0 << 5) | cppVar_55399;
	cppVar_55400 = (cppVar_55400 & cppMask_un_8_);
	cppVar_55401 = IRAM.rd(cppVar_55400);
	cppVar_55402 = (cppVar_55401 >> 0) & cppMask_un_4_;
	cppVar_55403 = (cppVar_55402 & cppMask_un_4_);
	cppVar_55404 = cppVar_55397 + cppVar_55403;
	cppVar_55404 = (cppVar_55404 & cppMask_un_5_);
	cppVar_55405 = 0;
	cppVar_55406 = cppVar_55404 + cppVar_55405;
	cppVar_55406 = (cppVar_55406 & cppMask_un_5_);
	cppVar_55407 = (cppVar_55406 >> 4) & cppMask_un_1_;
	cppVar_55408 = (PSW >> 3) & cppMask_un_3_;
	cppVar_55410 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55411 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55412 = (cppVar_55411 << 3) | 6;
	cppVar_55412 = (cppVar_55412 & cppMask_un_5_);
	cppVar_55413 = (0 << 5) | cppVar_55412;
	cppVar_55413 = (cppVar_55413 & cppMask_un_8_);
	cppVar_55414 = IRAM.rd(cppVar_55413);
	cppVar_55415 = ((cppVar_55414 & cppMask_bit_8_) ? (cppVar_55414 | cppMask_sign_8_) : cppVar_55414);
	cppVar_55416 = cppVar_55410 + cppVar_55415;
	cppVar_55416 = (cppVar_55416 & cppMask_un_9_);
	cppVar_55417 = 0;
	cppVar_55418 = cppVar_55416 + cppVar_55417;
	cppVar_55418 = (cppVar_55418 & cppMask_un_9_);
	cppVar_55419 = (cppVar_55418 >> 8) & cppMask_un_1_;
	cppVar_55420 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55421 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55422 = (cppVar_55421 << 3) | 6;
	cppVar_55422 = (cppVar_55422 & cppMask_un_5_);
	cppVar_55423 = (0 << 5) | cppVar_55422;
	cppVar_55423 = (cppVar_55423 & cppMask_un_8_);
	cppVar_55424 = IRAM.rd(cppVar_55423);
	cppVar_55425 = ((cppVar_55424 & cppMask_bit_8_) ? (cppVar_55424 | cppMask_sign_8_) : cppVar_55424);
	cppVar_55426 = cppVar_55420 + cppVar_55425;
	cppVar_55426 = (cppVar_55426 & cppMask_un_9_);
	cppVar_55427 = 0;
	cppVar_55428 = cppVar_55426 + cppVar_55427;
	cppVar_55428 = (cppVar_55428 & cppMask_un_9_);
	cppVar_55429 = (cppVar_55428 >> 7) & cppMask_un_1_;
	cppVar_55430 = (cppVar_55419 != cppVar_55429);
	if (cppVar_55430) {
	cppVar_55409 = 1;
	} else {
	cppVar_55409 = 0;
	}
	cppVar_55433 = (PSW >> 0) & cppMask_un_2_;
	cppVar_55434 = (cppVar_55409 << 2) | cppVar_55433;
	cppVar_55434 = (cppVar_55434 & cppMask_un_3_);
	cppVar_55435 = (cppVar_55408 << 3) | cppVar_55434;
	cppVar_55435 = (cppVar_55435 & cppMask_un_6_);
	cppVar_55436 = (cppVar_55407 << 6) | cppVar_55435;
	cppVar_55436 = (cppVar_55436 & cppMask_un_7_);
	cppVar_55437 = (cppVar_55395 << 7) | cppVar_55436;
	cppVar_55437 = (cppVar_55437 & cppMask_un_8_);
	cppVar_55379 = cppVar_55437;
	} else {
	cppVar_55439 = ROM.rd(PC);
	cppVar_55441 = (cppVar_55439 == 45);
	if (cppVar_55441) {
	cppVar_55442 = (ACC & cppMask_un_8_);
	cppVar_55444 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55446 = (cppVar_55444 << 3) | 5;
	cppVar_55446 = (cppVar_55446 & cppMask_un_5_);
	cppVar_55447 = (0 << 5) | cppVar_55446;
	cppVar_55447 = (cppVar_55447 & cppMask_un_8_);
	cppVar_55448 = IRAM.rd(cppVar_55447);
	cppVar_55449 = (cppVar_55448 & cppMask_un_8_);
	cppVar_55450 = cppVar_55442 + cppVar_55449;
	cppVar_55450 = (cppVar_55450 & cppMask_un_9_);
	cppVar_55452 = 0;
	cppVar_55453 = cppVar_55450 + cppVar_55452;
	cppVar_55453 = (cppVar_55453 & cppMask_un_9_);
	cppVar_55454 = (cppVar_55453 >> 8) & cppMask_un_1_;
	cppVar_55455 = (ACC >> 0) & cppMask_un_4_;
	cppVar_55456 = (cppVar_55455 & cppMask_un_4_);
	cppVar_55457 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55458 = (cppVar_55457 << 3) | 5;
	cppVar_55458 = (cppVar_55458 & cppMask_un_5_);
	cppVar_55459 = (0 << 5) | cppVar_55458;
	cppVar_55459 = (cppVar_55459 & cppMask_un_8_);
	cppVar_55460 = IRAM.rd(cppVar_55459);
	cppVar_55461 = (cppVar_55460 >> 0) & cppMask_un_4_;
	cppVar_55462 = (cppVar_55461 & cppMask_un_4_);
	cppVar_55463 = cppVar_55456 + cppVar_55462;
	cppVar_55463 = (cppVar_55463 & cppMask_un_5_);
	cppVar_55464 = 0;
	cppVar_55465 = cppVar_55463 + cppVar_55464;
	cppVar_55465 = (cppVar_55465 & cppMask_un_5_);
	cppVar_55466 = (cppVar_55465 >> 4) & cppMask_un_1_;
	cppVar_55467 = (PSW >> 3) & cppMask_un_3_;
	cppVar_55469 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55470 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55471 = (cppVar_55470 << 3) | 5;
	cppVar_55471 = (cppVar_55471 & cppMask_un_5_);
	cppVar_55472 = (0 << 5) | cppVar_55471;
	cppVar_55472 = (cppVar_55472 & cppMask_un_8_);
	cppVar_55473 = IRAM.rd(cppVar_55472);
	cppVar_55474 = ((cppVar_55473 & cppMask_bit_8_) ? (cppVar_55473 | cppMask_sign_8_) : cppVar_55473);
	cppVar_55475 = cppVar_55469 + cppVar_55474;
	cppVar_55475 = (cppVar_55475 & cppMask_un_9_);
	cppVar_55476 = 0;
	cppVar_55477 = cppVar_55475 + cppVar_55476;
	cppVar_55477 = (cppVar_55477 & cppMask_un_9_);
	cppVar_55478 = (cppVar_55477 >> 8) & cppMask_un_1_;
	cppVar_55479 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55480 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55481 = (cppVar_55480 << 3) | 5;
	cppVar_55481 = (cppVar_55481 & cppMask_un_5_);
	cppVar_55482 = (0 << 5) | cppVar_55481;
	cppVar_55482 = (cppVar_55482 & cppMask_un_8_);
	cppVar_55483 = IRAM.rd(cppVar_55482);
	cppVar_55484 = ((cppVar_55483 & cppMask_bit_8_) ? (cppVar_55483 | cppMask_sign_8_) : cppVar_55483);
	cppVar_55485 = cppVar_55479 + cppVar_55484;
	cppVar_55485 = (cppVar_55485 & cppMask_un_9_);
	cppVar_55486 = 0;
	cppVar_55487 = cppVar_55485 + cppVar_55486;
	cppVar_55487 = (cppVar_55487 & cppMask_un_9_);
	cppVar_55488 = (cppVar_55487 >> 7) & cppMask_un_1_;
	cppVar_55489 = (cppVar_55478 != cppVar_55488);
	if (cppVar_55489) {
	cppVar_55468 = 1;
	} else {
	cppVar_55468 = 0;
	}
	cppVar_55492 = (PSW >> 0) & cppMask_un_2_;
	cppVar_55493 = (cppVar_55468 << 2) | cppVar_55492;
	cppVar_55493 = (cppVar_55493 & cppMask_un_3_);
	cppVar_55494 = (cppVar_55467 << 3) | cppVar_55493;
	cppVar_55494 = (cppVar_55494 & cppMask_un_6_);
	cppVar_55495 = (cppVar_55466 << 6) | cppVar_55494;
	cppVar_55495 = (cppVar_55495 & cppMask_un_7_);
	cppVar_55496 = (cppVar_55454 << 7) | cppVar_55495;
	cppVar_55496 = (cppVar_55496 & cppMask_un_8_);
	cppVar_55438 = cppVar_55496;
	} else {
	cppVar_55498 = ROM.rd(PC);
	cppVar_55500 = (cppVar_55498 == 44);
	if (cppVar_55500) {
	cppVar_55501 = (ACC & cppMask_un_8_);
	cppVar_55503 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55505 = (cppVar_55503 << 3) | 4;
	cppVar_55505 = (cppVar_55505 & cppMask_un_5_);
	cppVar_55506 = (0 << 5) | cppVar_55505;
	cppVar_55506 = (cppVar_55506 & cppMask_un_8_);
	cppVar_55507 = IRAM.rd(cppVar_55506);
	cppVar_55508 = (cppVar_55507 & cppMask_un_8_);
	cppVar_55509 = cppVar_55501 + cppVar_55508;
	cppVar_55509 = (cppVar_55509 & cppMask_un_9_);
	cppVar_55511 = 0;
	cppVar_55512 = cppVar_55509 + cppVar_55511;
	cppVar_55512 = (cppVar_55512 & cppMask_un_9_);
	cppVar_55513 = (cppVar_55512 >> 8) & cppMask_un_1_;
	cppVar_55514 = (ACC >> 0) & cppMask_un_4_;
	cppVar_55515 = (cppVar_55514 & cppMask_un_4_);
	cppVar_55516 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55517 = (cppVar_55516 << 3) | 4;
	cppVar_55517 = (cppVar_55517 & cppMask_un_5_);
	cppVar_55518 = (0 << 5) | cppVar_55517;
	cppVar_55518 = (cppVar_55518 & cppMask_un_8_);
	cppVar_55519 = IRAM.rd(cppVar_55518);
	cppVar_55520 = (cppVar_55519 >> 0) & cppMask_un_4_;
	cppVar_55521 = (cppVar_55520 & cppMask_un_4_);
	cppVar_55522 = cppVar_55515 + cppVar_55521;
	cppVar_55522 = (cppVar_55522 & cppMask_un_5_);
	cppVar_55523 = 0;
	cppVar_55524 = cppVar_55522 + cppVar_55523;
	cppVar_55524 = (cppVar_55524 & cppMask_un_5_);
	cppVar_55525 = (cppVar_55524 >> 4) & cppMask_un_1_;
	cppVar_55526 = (PSW >> 3) & cppMask_un_3_;
	cppVar_55528 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55529 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55530 = (cppVar_55529 << 3) | 4;
	cppVar_55530 = (cppVar_55530 & cppMask_un_5_);
	cppVar_55531 = (0 << 5) | cppVar_55530;
	cppVar_55531 = (cppVar_55531 & cppMask_un_8_);
	cppVar_55532 = IRAM.rd(cppVar_55531);
	cppVar_55533 = ((cppVar_55532 & cppMask_bit_8_) ? (cppVar_55532 | cppMask_sign_8_) : cppVar_55532);
	cppVar_55534 = cppVar_55528 + cppVar_55533;
	cppVar_55534 = (cppVar_55534 & cppMask_un_9_);
	cppVar_55535 = 0;
	cppVar_55536 = cppVar_55534 + cppVar_55535;
	cppVar_55536 = (cppVar_55536 & cppMask_un_9_);
	cppVar_55537 = (cppVar_55536 >> 8) & cppMask_un_1_;
	cppVar_55538 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55539 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55540 = (cppVar_55539 << 3) | 4;
	cppVar_55540 = (cppVar_55540 & cppMask_un_5_);
	cppVar_55541 = (0 << 5) | cppVar_55540;
	cppVar_55541 = (cppVar_55541 & cppMask_un_8_);
	cppVar_55542 = IRAM.rd(cppVar_55541);
	cppVar_55543 = ((cppVar_55542 & cppMask_bit_8_) ? (cppVar_55542 | cppMask_sign_8_) : cppVar_55542);
	cppVar_55544 = cppVar_55538 + cppVar_55543;
	cppVar_55544 = (cppVar_55544 & cppMask_un_9_);
	cppVar_55545 = 0;
	cppVar_55546 = cppVar_55544 + cppVar_55545;
	cppVar_55546 = (cppVar_55546 & cppMask_un_9_);
	cppVar_55547 = (cppVar_55546 >> 7) & cppMask_un_1_;
	cppVar_55548 = (cppVar_55537 != cppVar_55547);
	if (cppVar_55548) {
	cppVar_55527 = 1;
	} else {
	cppVar_55527 = 0;
	}
	cppVar_55551 = (PSW >> 0) & cppMask_un_2_;
	cppVar_55552 = (cppVar_55527 << 2) | cppVar_55551;
	cppVar_55552 = (cppVar_55552 & cppMask_un_3_);
	cppVar_55553 = (cppVar_55526 << 3) | cppVar_55552;
	cppVar_55553 = (cppVar_55553 & cppMask_un_6_);
	cppVar_55554 = (cppVar_55525 << 6) | cppVar_55553;
	cppVar_55554 = (cppVar_55554 & cppMask_un_7_);
	cppVar_55555 = (cppVar_55513 << 7) | cppVar_55554;
	cppVar_55555 = (cppVar_55555 & cppMask_un_8_);
	cppVar_55497 = cppVar_55555;
	} else {
	cppVar_55557 = ROM.rd(PC);
	cppVar_55559 = (cppVar_55557 == 43);
	if (cppVar_55559) {
	cppVar_55560 = (ACC & cppMask_un_8_);
	cppVar_55562 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55564 = (cppVar_55562 << 3) | 3;
	cppVar_55564 = (cppVar_55564 & cppMask_un_5_);
	cppVar_55565 = (0 << 5) | cppVar_55564;
	cppVar_55565 = (cppVar_55565 & cppMask_un_8_);
	cppVar_55566 = IRAM.rd(cppVar_55565);
	cppVar_55567 = (cppVar_55566 & cppMask_un_8_);
	cppVar_55568 = cppVar_55560 + cppVar_55567;
	cppVar_55568 = (cppVar_55568 & cppMask_un_9_);
	cppVar_55570 = 0;
	cppVar_55571 = cppVar_55568 + cppVar_55570;
	cppVar_55571 = (cppVar_55571 & cppMask_un_9_);
	cppVar_55572 = (cppVar_55571 >> 8) & cppMask_un_1_;
	cppVar_55573 = (ACC >> 0) & cppMask_un_4_;
	cppVar_55574 = (cppVar_55573 & cppMask_un_4_);
	cppVar_55575 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55576 = (cppVar_55575 << 3) | 3;
	cppVar_55576 = (cppVar_55576 & cppMask_un_5_);
	cppVar_55577 = (0 << 5) | cppVar_55576;
	cppVar_55577 = (cppVar_55577 & cppMask_un_8_);
	cppVar_55578 = IRAM.rd(cppVar_55577);
	cppVar_55579 = (cppVar_55578 >> 0) & cppMask_un_4_;
	cppVar_55580 = (cppVar_55579 & cppMask_un_4_);
	cppVar_55581 = cppVar_55574 + cppVar_55580;
	cppVar_55581 = (cppVar_55581 & cppMask_un_5_);
	cppVar_55582 = 0;
	cppVar_55583 = cppVar_55581 + cppVar_55582;
	cppVar_55583 = (cppVar_55583 & cppMask_un_5_);
	cppVar_55584 = (cppVar_55583 >> 4) & cppMask_un_1_;
	cppVar_55585 = (PSW >> 3) & cppMask_un_3_;
	cppVar_55587 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55588 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55589 = (cppVar_55588 << 3) | 3;
	cppVar_55589 = (cppVar_55589 & cppMask_un_5_);
	cppVar_55590 = (0 << 5) | cppVar_55589;
	cppVar_55590 = (cppVar_55590 & cppMask_un_8_);
	cppVar_55591 = IRAM.rd(cppVar_55590);
	cppVar_55592 = ((cppVar_55591 & cppMask_bit_8_) ? (cppVar_55591 | cppMask_sign_8_) : cppVar_55591);
	cppVar_55593 = cppVar_55587 + cppVar_55592;
	cppVar_55593 = (cppVar_55593 & cppMask_un_9_);
	cppVar_55594 = 0;
	cppVar_55595 = cppVar_55593 + cppVar_55594;
	cppVar_55595 = (cppVar_55595 & cppMask_un_9_);
	cppVar_55596 = (cppVar_55595 >> 8) & cppMask_un_1_;
	cppVar_55597 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55598 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55599 = (cppVar_55598 << 3) | 3;
	cppVar_55599 = (cppVar_55599 & cppMask_un_5_);
	cppVar_55600 = (0 << 5) | cppVar_55599;
	cppVar_55600 = (cppVar_55600 & cppMask_un_8_);
	cppVar_55601 = IRAM.rd(cppVar_55600);
	cppVar_55602 = ((cppVar_55601 & cppMask_bit_8_) ? (cppVar_55601 | cppMask_sign_8_) : cppVar_55601);
	cppVar_55603 = cppVar_55597 + cppVar_55602;
	cppVar_55603 = (cppVar_55603 & cppMask_un_9_);
	cppVar_55604 = 0;
	cppVar_55605 = cppVar_55603 + cppVar_55604;
	cppVar_55605 = (cppVar_55605 & cppMask_un_9_);
	cppVar_55606 = (cppVar_55605 >> 7) & cppMask_un_1_;
	cppVar_55607 = (cppVar_55596 != cppVar_55606);
	if (cppVar_55607) {
	cppVar_55586 = 1;
	} else {
	cppVar_55586 = 0;
	}
	cppVar_55610 = (PSW >> 0) & cppMask_un_2_;
	cppVar_55611 = (cppVar_55586 << 2) | cppVar_55610;
	cppVar_55611 = (cppVar_55611 & cppMask_un_3_);
	cppVar_55612 = (cppVar_55585 << 3) | cppVar_55611;
	cppVar_55612 = (cppVar_55612 & cppMask_un_6_);
	cppVar_55613 = (cppVar_55584 << 6) | cppVar_55612;
	cppVar_55613 = (cppVar_55613 & cppMask_un_7_);
	cppVar_55614 = (cppVar_55572 << 7) | cppVar_55613;
	cppVar_55614 = (cppVar_55614 & cppMask_un_8_);
	cppVar_55556 = cppVar_55614;
	} else {
	cppVar_55616 = ROM.rd(PC);
	cppVar_55618 = (cppVar_55616 == 42);
	if (cppVar_55618) {
	cppVar_55619 = (ACC & cppMask_un_8_);
	cppVar_55621 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55623 = (cppVar_55621 << 3) | 2;
	cppVar_55623 = (cppVar_55623 & cppMask_un_5_);
	cppVar_55624 = (0 << 5) | cppVar_55623;
	cppVar_55624 = (cppVar_55624 & cppMask_un_8_);
	cppVar_55625 = IRAM.rd(cppVar_55624);
	cppVar_55626 = (cppVar_55625 & cppMask_un_8_);
	cppVar_55627 = cppVar_55619 + cppVar_55626;
	cppVar_55627 = (cppVar_55627 & cppMask_un_9_);
	cppVar_55629 = 0;
	cppVar_55630 = cppVar_55627 + cppVar_55629;
	cppVar_55630 = (cppVar_55630 & cppMask_un_9_);
	cppVar_55631 = (cppVar_55630 >> 8) & cppMask_un_1_;
	cppVar_55632 = (ACC >> 0) & cppMask_un_4_;
	cppVar_55633 = (cppVar_55632 & cppMask_un_4_);
	cppVar_55634 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55635 = (cppVar_55634 << 3) | 2;
	cppVar_55635 = (cppVar_55635 & cppMask_un_5_);
	cppVar_55636 = (0 << 5) | cppVar_55635;
	cppVar_55636 = (cppVar_55636 & cppMask_un_8_);
	cppVar_55637 = IRAM.rd(cppVar_55636);
	cppVar_55638 = (cppVar_55637 >> 0) & cppMask_un_4_;
	cppVar_55639 = (cppVar_55638 & cppMask_un_4_);
	cppVar_55640 = cppVar_55633 + cppVar_55639;
	cppVar_55640 = (cppVar_55640 & cppMask_un_5_);
	cppVar_55641 = 0;
	cppVar_55642 = cppVar_55640 + cppVar_55641;
	cppVar_55642 = (cppVar_55642 & cppMask_un_5_);
	cppVar_55643 = (cppVar_55642 >> 4) & cppMask_un_1_;
	cppVar_55644 = (PSW >> 3) & cppMask_un_3_;
	cppVar_55646 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55647 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55648 = (cppVar_55647 << 3) | 2;
	cppVar_55648 = (cppVar_55648 & cppMask_un_5_);
	cppVar_55649 = (0 << 5) | cppVar_55648;
	cppVar_55649 = (cppVar_55649 & cppMask_un_8_);
	cppVar_55650 = IRAM.rd(cppVar_55649);
	cppVar_55651 = ((cppVar_55650 & cppMask_bit_8_) ? (cppVar_55650 | cppMask_sign_8_) : cppVar_55650);
	cppVar_55652 = cppVar_55646 + cppVar_55651;
	cppVar_55652 = (cppVar_55652 & cppMask_un_9_);
	cppVar_55653 = 0;
	cppVar_55654 = cppVar_55652 + cppVar_55653;
	cppVar_55654 = (cppVar_55654 & cppMask_un_9_);
	cppVar_55655 = (cppVar_55654 >> 8) & cppMask_un_1_;
	cppVar_55656 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55657 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55658 = (cppVar_55657 << 3) | 2;
	cppVar_55658 = (cppVar_55658 & cppMask_un_5_);
	cppVar_55659 = (0 << 5) | cppVar_55658;
	cppVar_55659 = (cppVar_55659 & cppMask_un_8_);
	cppVar_55660 = IRAM.rd(cppVar_55659);
	cppVar_55661 = ((cppVar_55660 & cppMask_bit_8_) ? (cppVar_55660 | cppMask_sign_8_) : cppVar_55660);
	cppVar_55662 = cppVar_55656 + cppVar_55661;
	cppVar_55662 = (cppVar_55662 & cppMask_un_9_);
	cppVar_55663 = 0;
	cppVar_55664 = cppVar_55662 + cppVar_55663;
	cppVar_55664 = (cppVar_55664 & cppMask_un_9_);
	cppVar_55665 = (cppVar_55664 >> 7) & cppMask_un_1_;
	cppVar_55666 = (cppVar_55655 != cppVar_55665);
	if (cppVar_55666) {
	cppVar_55645 = 1;
	} else {
	cppVar_55645 = 0;
	}
	cppVar_55669 = (PSW >> 0) & cppMask_un_2_;
	cppVar_55670 = (cppVar_55645 << 2) | cppVar_55669;
	cppVar_55670 = (cppVar_55670 & cppMask_un_3_);
	cppVar_55671 = (cppVar_55644 << 3) | cppVar_55670;
	cppVar_55671 = (cppVar_55671 & cppMask_un_6_);
	cppVar_55672 = (cppVar_55643 << 6) | cppVar_55671;
	cppVar_55672 = (cppVar_55672 & cppMask_un_7_);
	cppVar_55673 = (cppVar_55631 << 7) | cppVar_55672;
	cppVar_55673 = (cppVar_55673 & cppMask_un_8_);
	cppVar_55615 = cppVar_55673;
	} else {
	cppVar_55675 = ROM.rd(PC);
	cppVar_55677 = (cppVar_55675 == 41);
	if (cppVar_55677) {
	cppVar_55678 = (ACC & cppMask_un_8_);
	cppVar_55680 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55682 = (cppVar_55680 << 3) | 1;
	cppVar_55682 = (cppVar_55682 & cppMask_un_5_);
	cppVar_55683 = (0 << 5) | cppVar_55682;
	cppVar_55683 = (cppVar_55683 & cppMask_un_8_);
	cppVar_55684 = IRAM.rd(cppVar_55683);
	cppVar_55685 = (cppVar_55684 & cppMask_un_8_);
	cppVar_55686 = cppVar_55678 + cppVar_55685;
	cppVar_55686 = (cppVar_55686 & cppMask_un_9_);
	cppVar_55688 = 0;
	cppVar_55689 = cppVar_55686 + cppVar_55688;
	cppVar_55689 = (cppVar_55689 & cppMask_un_9_);
	cppVar_55690 = (cppVar_55689 >> 8) & cppMask_un_1_;
	cppVar_55691 = (ACC >> 0) & cppMask_un_4_;
	cppVar_55692 = (cppVar_55691 & cppMask_un_4_);
	cppVar_55693 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55694 = (cppVar_55693 << 3) | 1;
	cppVar_55694 = (cppVar_55694 & cppMask_un_5_);
	cppVar_55695 = (0 << 5) | cppVar_55694;
	cppVar_55695 = (cppVar_55695 & cppMask_un_8_);
	cppVar_55696 = IRAM.rd(cppVar_55695);
	cppVar_55697 = (cppVar_55696 >> 0) & cppMask_un_4_;
	cppVar_55698 = (cppVar_55697 & cppMask_un_4_);
	cppVar_55699 = cppVar_55692 + cppVar_55698;
	cppVar_55699 = (cppVar_55699 & cppMask_un_5_);
	cppVar_55700 = 0;
	cppVar_55701 = cppVar_55699 + cppVar_55700;
	cppVar_55701 = (cppVar_55701 & cppMask_un_5_);
	cppVar_55702 = (cppVar_55701 >> 4) & cppMask_un_1_;
	cppVar_55703 = (PSW >> 3) & cppMask_un_3_;
	cppVar_55705 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55706 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55707 = (cppVar_55706 << 3) | 1;
	cppVar_55707 = (cppVar_55707 & cppMask_un_5_);
	cppVar_55708 = (0 << 5) | cppVar_55707;
	cppVar_55708 = (cppVar_55708 & cppMask_un_8_);
	cppVar_55709 = IRAM.rd(cppVar_55708);
	cppVar_55710 = ((cppVar_55709 & cppMask_bit_8_) ? (cppVar_55709 | cppMask_sign_8_) : cppVar_55709);
	cppVar_55711 = cppVar_55705 + cppVar_55710;
	cppVar_55711 = (cppVar_55711 & cppMask_un_9_);
	cppVar_55712 = 0;
	cppVar_55713 = cppVar_55711 + cppVar_55712;
	cppVar_55713 = (cppVar_55713 & cppMask_un_9_);
	cppVar_55714 = (cppVar_55713 >> 8) & cppMask_un_1_;
	cppVar_55715 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55716 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55717 = (cppVar_55716 << 3) | 1;
	cppVar_55717 = (cppVar_55717 & cppMask_un_5_);
	cppVar_55718 = (0 << 5) | cppVar_55717;
	cppVar_55718 = (cppVar_55718 & cppMask_un_8_);
	cppVar_55719 = IRAM.rd(cppVar_55718);
	cppVar_55720 = ((cppVar_55719 & cppMask_bit_8_) ? (cppVar_55719 | cppMask_sign_8_) : cppVar_55719);
	cppVar_55721 = cppVar_55715 + cppVar_55720;
	cppVar_55721 = (cppVar_55721 & cppMask_un_9_);
	cppVar_55722 = 0;
	cppVar_55723 = cppVar_55721 + cppVar_55722;
	cppVar_55723 = (cppVar_55723 & cppMask_un_9_);
	cppVar_55724 = (cppVar_55723 >> 7) & cppMask_un_1_;
	cppVar_55725 = (cppVar_55714 != cppVar_55724);
	if (cppVar_55725) {
	cppVar_55704 = 1;
	} else {
	cppVar_55704 = 0;
	}
	cppVar_55728 = (PSW >> 0) & cppMask_un_2_;
	cppVar_55729 = (cppVar_55704 << 2) | cppVar_55728;
	cppVar_55729 = (cppVar_55729 & cppMask_un_3_);
	cppVar_55730 = (cppVar_55703 << 3) | cppVar_55729;
	cppVar_55730 = (cppVar_55730 & cppMask_un_6_);
	cppVar_55731 = (cppVar_55702 << 6) | cppVar_55730;
	cppVar_55731 = (cppVar_55731 & cppMask_un_7_);
	cppVar_55732 = (cppVar_55690 << 7) | cppVar_55731;
	cppVar_55732 = (cppVar_55732 & cppMask_un_8_);
	cppVar_55674 = cppVar_55732;
	} else {
	cppVar_55734 = ROM.rd(PC);
	cppVar_55736 = (cppVar_55734 == 40);
	if (cppVar_55736) {
	cppVar_55737 = (ACC & cppMask_un_8_);
	cppVar_55739 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55741 = (cppVar_55739 << 3) | 0;
	cppVar_55741 = (cppVar_55741 & cppMask_un_5_);
	cppVar_55742 = (0 << 5) | cppVar_55741;
	cppVar_55742 = (cppVar_55742 & cppMask_un_8_);
	cppVar_55743 = IRAM.rd(cppVar_55742);
	cppVar_55744 = (cppVar_55743 & cppMask_un_8_);
	cppVar_55745 = cppVar_55737 + cppVar_55744;
	cppVar_55745 = (cppVar_55745 & cppMask_un_9_);
	cppVar_55747 = 0;
	cppVar_55748 = cppVar_55745 + cppVar_55747;
	cppVar_55748 = (cppVar_55748 & cppMask_un_9_);
	cppVar_55749 = (cppVar_55748 >> 8) & cppMask_un_1_;
	cppVar_55750 = (ACC >> 0) & cppMask_un_4_;
	cppVar_55751 = (cppVar_55750 & cppMask_un_4_);
	cppVar_55752 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55753 = (cppVar_55752 << 3) | 0;
	cppVar_55753 = (cppVar_55753 & cppMask_un_5_);
	cppVar_55754 = (0 << 5) | cppVar_55753;
	cppVar_55754 = (cppVar_55754 & cppMask_un_8_);
	cppVar_55755 = IRAM.rd(cppVar_55754);
	cppVar_55756 = (cppVar_55755 >> 0) & cppMask_un_4_;
	cppVar_55757 = (cppVar_55756 & cppMask_un_4_);
	cppVar_55758 = cppVar_55751 + cppVar_55757;
	cppVar_55758 = (cppVar_55758 & cppMask_un_5_);
	cppVar_55759 = 0;
	cppVar_55760 = cppVar_55758 + cppVar_55759;
	cppVar_55760 = (cppVar_55760 & cppMask_un_5_);
	cppVar_55761 = (cppVar_55760 >> 4) & cppMask_un_1_;
	cppVar_55762 = (PSW >> 3) & cppMask_un_3_;
	cppVar_55764 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55765 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55766 = (cppVar_55765 << 3) | 0;
	cppVar_55766 = (cppVar_55766 & cppMask_un_5_);
	cppVar_55767 = (0 << 5) | cppVar_55766;
	cppVar_55767 = (cppVar_55767 & cppMask_un_8_);
	cppVar_55768 = IRAM.rd(cppVar_55767);
	cppVar_55769 = ((cppVar_55768 & cppMask_bit_8_) ? (cppVar_55768 | cppMask_sign_8_) : cppVar_55768);
	cppVar_55770 = cppVar_55764 + cppVar_55769;
	cppVar_55770 = (cppVar_55770 & cppMask_un_9_);
	cppVar_55771 = 0;
	cppVar_55772 = cppVar_55770 + cppVar_55771;
	cppVar_55772 = (cppVar_55772 & cppMask_un_9_);
	cppVar_55773 = (cppVar_55772 >> 8) & cppMask_un_1_;
	cppVar_55774 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55775 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55776 = (cppVar_55775 << 3) | 0;
	cppVar_55776 = (cppVar_55776 & cppMask_un_5_);
	cppVar_55777 = (0 << 5) | cppVar_55776;
	cppVar_55777 = (cppVar_55777 & cppMask_un_8_);
	cppVar_55778 = IRAM.rd(cppVar_55777);
	cppVar_55779 = ((cppVar_55778 & cppMask_bit_8_) ? (cppVar_55778 | cppMask_sign_8_) : cppVar_55778);
	cppVar_55780 = cppVar_55774 + cppVar_55779;
	cppVar_55780 = (cppVar_55780 & cppMask_un_9_);
	cppVar_55781 = 0;
	cppVar_55782 = cppVar_55780 + cppVar_55781;
	cppVar_55782 = (cppVar_55782 & cppMask_un_9_);
	cppVar_55783 = (cppVar_55782 >> 7) & cppMask_un_1_;
	cppVar_55784 = (cppVar_55773 != cppVar_55783);
	if (cppVar_55784) {
	cppVar_55763 = 1;
	} else {
	cppVar_55763 = 0;
	}
	cppVar_55787 = (PSW >> 0) & cppMask_un_2_;
	cppVar_55788 = (cppVar_55763 << 2) | cppVar_55787;
	cppVar_55788 = (cppVar_55788 & cppMask_un_3_);
	cppVar_55789 = (cppVar_55762 << 3) | cppVar_55788;
	cppVar_55789 = (cppVar_55789 & cppMask_un_6_);
	cppVar_55790 = (cppVar_55761 << 6) | cppVar_55789;
	cppVar_55790 = (cppVar_55790 & cppMask_un_7_);
	cppVar_55791 = (cppVar_55749 << 7) | cppVar_55790;
	cppVar_55791 = (cppVar_55791 & cppMask_un_8_);
	cppVar_55733 = cppVar_55791;
	} else {
	cppVar_55793 = ROM.rd(PC);
	cppVar_55795 = (cppVar_55793 == 39);
	if (cppVar_55795) {
	cppVar_55796 = (ACC & cppMask_un_8_);
	cppVar_55798 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55800 = (cppVar_55798 << 3) | 1;
	cppVar_55800 = (cppVar_55800 & cppMask_un_5_);
	cppVar_55801 = (0 << 5) | cppVar_55800;
	cppVar_55801 = (cppVar_55801 & cppMask_un_8_);
	cppVar_55802 = IRAM.rd(cppVar_55801);
	cppVar_55803 = IRAM.rd(cppVar_55802);
	cppVar_55804 = (cppVar_55803 & cppMask_un_8_);
	cppVar_55805 = cppVar_55796 + cppVar_55804;
	cppVar_55805 = (cppVar_55805 & cppMask_un_9_);
	cppVar_55807 = 0;
	cppVar_55808 = cppVar_55805 + cppVar_55807;
	cppVar_55808 = (cppVar_55808 & cppMask_un_9_);
	cppVar_55809 = (cppVar_55808 >> 8) & cppMask_un_1_;
	cppVar_55810 = (ACC >> 0) & cppMask_un_4_;
	cppVar_55811 = (cppVar_55810 & cppMask_un_4_);
	cppVar_55812 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55813 = (cppVar_55812 << 3) | 1;
	cppVar_55813 = (cppVar_55813 & cppMask_un_5_);
	cppVar_55814 = (0 << 5) | cppVar_55813;
	cppVar_55814 = (cppVar_55814 & cppMask_un_8_);
	cppVar_55815 = IRAM.rd(cppVar_55814);
	cppVar_55816 = IRAM.rd(cppVar_55815);
	cppVar_55817 = (cppVar_55816 >> 0) & cppMask_un_4_;
	cppVar_55818 = (cppVar_55817 & cppMask_un_4_);
	cppVar_55819 = cppVar_55811 + cppVar_55818;
	cppVar_55819 = (cppVar_55819 & cppMask_un_5_);
	cppVar_55820 = 0;
	cppVar_55821 = cppVar_55819 + cppVar_55820;
	cppVar_55821 = (cppVar_55821 & cppMask_un_5_);
	cppVar_55822 = (cppVar_55821 >> 4) & cppMask_un_1_;
	cppVar_55823 = (PSW >> 3) & cppMask_un_3_;
	cppVar_55825 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55826 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55827 = (cppVar_55826 << 3) | 1;
	cppVar_55827 = (cppVar_55827 & cppMask_un_5_);
	cppVar_55828 = (0 << 5) | cppVar_55827;
	cppVar_55828 = (cppVar_55828 & cppMask_un_8_);
	cppVar_55829 = IRAM.rd(cppVar_55828);
	cppVar_55830 = IRAM.rd(cppVar_55829);
	cppVar_55831 = ((cppVar_55830 & cppMask_bit_8_) ? (cppVar_55830 | cppMask_sign_8_) : cppVar_55830);
	cppVar_55832 = cppVar_55825 + cppVar_55831;
	cppVar_55832 = (cppVar_55832 & cppMask_un_9_);
	cppVar_55833 = 0;
	cppVar_55834 = cppVar_55832 + cppVar_55833;
	cppVar_55834 = (cppVar_55834 & cppMask_un_9_);
	cppVar_55835 = (cppVar_55834 >> 8) & cppMask_un_1_;
	cppVar_55836 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55837 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55838 = (cppVar_55837 << 3) | 1;
	cppVar_55838 = (cppVar_55838 & cppMask_un_5_);
	cppVar_55839 = (0 << 5) | cppVar_55838;
	cppVar_55839 = (cppVar_55839 & cppMask_un_8_);
	cppVar_55840 = IRAM.rd(cppVar_55839);
	cppVar_55841 = IRAM.rd(cppVar_55840);
	cppVar_55842 = ((cppVar_55841 & cppMask_bit_8_) ? (cppVar_55841 | cppMask_sign_8_) : cppVar_55841);
	cppVar_55843 = cppVar_55836 + cppVar_55842;
	cppVar_55843 = (cppVar_55843 & cppMask_un_9_);
	cppVar_55844 = 0;
	cppVar_55845 = cppVar_55843 + cppVar_55844;
	cppVar_55845 = (cppVar_55845 & cppMask_un_9_);
	cppVar_55846 = (cppVar_55845 >> 7) & cppMask_un_1_;
	cppVar_55847 = (cppVar_55835 != cppVar_55846);
	if (cppVar_55847) {
	cppVar_55824 = 1;
	} else {
	cppVar_55824 = 0;
	}
	cppVar_55850 = (PSW >> 0) & cppMask_un_2_;
	cppVar_55851 = (cppVar_55824 << 2) | cppVar_55850;
	cppVar_55851 = (cppVar_55851 & cppMask_un_3_);
	cppVar_55852 = (cppVar_55823 << 3) | cppVar_55851;
	cppVar_55852 = (cppVar_55852 & cppMask_un_6_);
	cppVar_55853 = (cppVar_55822 << 6) | cppVar_55852;
	cppVar_55853 = (cppVar_55853 & cppMask_un_7_);
	cppVar_55854 = (cppVar_55809 << 7) | cppVar_55853;
	cppVar_55854 = (cppVar_55854 & cppMask_un_8_);
	cppVar_55792 = cppVar_55854;
	} else {
	cppVar_55856 = ROM.rd(PC);
	cppVar_55858 = (cppVar_55856 == 38);
	if (cppVar_55858) {
	cppVar_55859 = (ACC & cppMask_un_8_);
	cppVar_55861 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55863 = (cppVar_55861 << 3) | 0;
	cppVar_55863 = (cppVar_55863 & cppMask_un_5_);
	cppVar_55864 = (0 << 5) | cppVar_55863;
	cppVar_55864 = (cppVar_55864 & cppMask_un_8_);
	cppVar_55865 = IRAM.rd(cppVar_55864);
	cppVar_55866 = IRAM.rd(cppVar_55865);
	cppVar_55867 = (cppVar_55866 & cppMask_un_8_);
	cppVar_55868 = cppVar_55859 + cppVar_55867;
	cppVar_55868 = (cppVar_55868 & cppMask_un_9_);
	cppVar_55870 = 0;
	cppVar_55871 = cppVar_55868 + cppVar_55870;
	cppVar_55871 = (cppVar_55871 & cppMask_un_9_);
	cppVar_55872 = (cppVar_55871 >> 8) & cppMask_un_1_;
	cppVar_55873 = (ACC >> 0) & cppMask_un_4_;
	cppVar_55874 = (cppVar_55873 & cppMask_un_4_);
	cppVar_55875 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55876 = (cppVar_55875 << 3) | 0;
	cppVar_55876 = (cppVar_55876 & cppMask_un_5_);
	cppVar_55877 = (0 << 5) | cppVar_55876;
	cppVar_55877 = (cppVar_55877 & cppMask_un_8_);
	cppVar_55878 = IRAM.rd(cppVar_55877);
	cppVar_55879 = IRAM.rd(cppVar_55878);
	cppVar_55880 = (cppVar_55879 >> 0) & cppMask_un_4_;
	cppVar_55881 = (cppVar_55880 & cppMask_un_4_);
	cppVar_55882 = cppVar_55874 + cppVar_55881;
	cppVar_55882 = (cppVar_55882 & cppMask_un_5_);
	cppVar_55883 = 0;
	cppVar_55884 = cppVar_55882 + cppVar_55883;
	cppVar_55884 = (cppVar_55884 & cppMask_un_5_);
	cppVar_55885 = (cppVar_55884 >> 4) & cppMask_un_1_;
	cppVar_55886 = (PSW >> 3) & cppMask_un_3_;
	cppVar_55888 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55889 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55890 = (cppVar_55889 << 3) | 0;
	cppVar_55890 = (cppVar_55890 & cppMask_un_5_);
	cppVar_55891 = (0 << 5) | cppVar_55890;
	cppVar_55891 = (cppVar_55891 & cppMask_un_8_);
	cppVar_55892 = IRAM.rd(cppVar_55891);
	cppVar_55893 = IRAM.rd(cppVar_55892);
	cppVar_55894 = ((cppVar_55893 & cppMask_bit_8_) ? (cppVar_55893 | cppMask_sign_8_) : cppVar_55893);
	cppVar_55895 = cppVar_55888 + cppVar_55894;
	cppVar_55895 = (cppVar_55895 & cppMask_un_9_);
	cppVar_55896 = 0;
	cppVar_55897 = cppVar_55895 + cppVar_55896;
	cppVar_55897 = (cppVar_55897 & cppMask_un_9_);
	cppVar_55898 = (cppVar_55897 >> 8) & cppMask_un_1_;
	cppVar_55899 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_55900 = (PSW >> 3) & cppMask_un_2_;
	cppVar_55901 = (cppVar_55900 << 3) | 0;
	cppVar_55901 = (cppVar_55901 & cppMask_un_5_);
	cppVar_55902 = (0 << 5) | cppVar_55901;
	cppVar_55902 = (cppVar_55902 & cppMask_un_8_);
	cppVar_55903 = IRAM.rd(cppVar_55902);
	cppVar_55904 = IRAM.rd(cppVar_55903);
	cppVar_55905 = ((cppVar_55904 & cppMask_bit_8_) ? (cppVar_55904 | cppMask_sign_8_) : cppVar_55904);
	cppVar_55906 = cppVar_55899 + cppVar_55905;
	cppVar_55906 = (cppVar_55906 & cppMask_un_9_);
	cppVar_55907 = 0;
	cppVar_55908 = cppVar_55906 + cppVar_55907;
	cppVar_55908 = (cppVar_55908 & cppMask_un_9_);
	cppVar_55909 = (cppVar_55908 >> 7) & cppMask_un_1_;
	cppVar_55910 = (cppVar_55898 != cppVar_55909);
	if (cppVar_55910) {
	cppVar_55887 = 1;
	} else {
	cppVar_55887 = 0;
	}
	cppVar_55913 = (PSW >> 0) & cppMask_un_2_;
	cppVar_55914 = (cppVar_55887 << 2) | cppVar_55913;
	cppVar_55914 = (cppVar_55914 & cppMask_un_3_);
	cppVar_55915 = (cppVar_55886 << 3) | cppVar_55914;
	cppVar_55915 = (cppVar_55915 & cppMask_un_6_);
	cppVar_55916 = (cppVar_55885 << 6) | cppVar_55915;
	cppVar_55916 = (cppVar_55916 & cppMask_un_7_);
	cppVar_55917 = (cppVar_55872 << 7) | cppVar_55916;
	cppVar_55917 = (cppVar_55917 & cppMask_un_8_);
	cppVar_55855 = cppVar_55917;
	} else {
	cppVar_55919 = ROM.rd(PC);
	cppVar_55921 = (cppVar_55919 == 37);
	if (cppVar_55921) {
	cppVar_55922 = (ACC & cppMask_un_8_);
	cppVar_55925 = PC + 1;
	cppVar_55925 = (cppVar_55925 & cppMask_un_16_);
	cppVar_55926 = ROM.rd(cppVar_55925);
	cppVar_55927 = (cppVar_55926 >> 7) & cppMask_un_1_;
	cppVar_55929 = (cppVar_55927 == 0);
	if (cppVar_55929) {
	cppVar_55930 = PC + 1;
	cppVar_55930 = (cppVar_55930 & cppMask_un_16_);
	cppVar_55931 = ROM.rd(cppVar_55930);
	cppVar_55932 = IRAM.rd(cppVar_55931);
	cppVar_55923 = cppVar_55932;
	} else {
	cppVar_55934 = PC + 1;
	cppVar_55934 = (cppVar_55934 & cppMask_un_16_);
	cppVar_55935 = ROM.rd(cppVar_55934);
	cppVar_55937 = (cppVar_55935 == 128);
	if (cppVar_55937) {
	cppVar_55933 = P0;
	} else {
	cppVar_55939 = PC + 1;
	cppVar_55939 = (cppVar_55939 & cppMask_un_16_);
	cppVar_55940 = ROM.rd(cppVar_55939);
	cppVar_55942 = (cppVar_55940 == 129);
	if (cppVar_55942) {
	cppVar_55938 = SP;
	} else {
	cppVar_55944 = PC + 1;
	cppVar_55944 = (cppVar_55944 & cppMask_un_16_);
	cppVar_55945 = ROM.rd(cppVar_55944);
	cppVar_55947 = (cppVar_55945 == 130);
	if (cppVar_55947) {
	cppVar_55943 = DPL;
	} else {
	cppVar_55949 = PC + 1;
	cppVar_55949 = (cppVar_55949 & cppMask_un_16_);
	cppVar_55950 = ROM.rd(cppVar_55949);
	cppVar_55952 = (cppVar_55950 == 131);
	if (cppVar_55952) {
	cppVar_55948 = DPH;
	} else {
	cppVar_55954 = PC + 1;
	cppVar_55954 = (cppVar_55954 & cppMask_un_16_);
	cppVar_55955 = ROM.rd(cppVar_55954);
	cppVar_55957 = (cppVar_55955 == 135);
	if (cppVar_55957) {
	cppVar_55953 = PCON;
	} else {
	cppVar_55959 = PC + 1;
	cppVar_55959 = (cppVar_55959 & cppMask_un_16_);
	cppVar_55960 = ROM.rd(cppVar_55959);
	cppVar_55962 = (cppVar_55960 == 136);
	if (cppVar_55962) {
	cppVar_55958 = TCON;
	} else {
	cppVar_55964 = PC + 1;
	cppVar_55964 = (cppVar_55964 & cppMask_un_16_);
	cppVar_55965 = ROM.rd(cppVar_55964);
	cppVar_55967 = (cppVar_55965 == 137);
	if (cppVar_55967) {
	cppVar_55963 = TMOD;
	} else {
	cppVar_55969 = PC + 1;
	cppVar_55969 = (cppVar_55969 & cppMask_un_16_);
	cppVar_55970 = ROM.rd(cppVar_55969);
	cppVar_55972 = (cppVar_55970 == 138);
	if (cppVar_55972) {
	cppVar_55968 = TL0;
	} else {
	cppVar_55974 = PC + 1;
	cppVar_55974 = (cppVar_55974 & cppMask_un_16_);
	cppVar_55975 = ROM.rd(cppVar_55974);
	cppVar_55977 = (cppVar_55975 == 140);
	if (cppVar_55977) {
	cppVar_55973 = TH0;
	} else {
	cppVar_55979 = PC + 1;
	cppVar_55979 = (cppVar_55979 & cppMask_un_16_);
	cppVar_55980 = ROM.rd(cppVar_55979);
	cppVar_55982 = (cppVar_55980 == 139);
	if (cppVar_55982) {
	cppVar_55978 = TL1;
	} else {
	cppVar_55984 = PC + 1;
	cppVar_55984 = (cppVar_55984 & cppMask_un_16_);
	cppVar_55985 = ROM.rd(cppVar_55984);
	cppVar_55987 = (cppVar_55985 == 141);
	if (cppVar_55987) {
	cppVar_55983 = TH1;
	} else {
	cppVar_55989 = PC + 1;
	cppVar_55989 = (cppVar_55989 & cppMask_un_16_);
	cppVar_55990 = ROM.rd(cppVar_55989);
	cppVar_55992 = (cppVar_55990 == 144);
	if (cppVar_55992) {
	cppVar_55988 = P1;
	} else {
	cppVar_55994 = PC + 1;
	cppVar_55994 = (cppVar_55994 & cppMask_un_16_);
	cppVar_55995 = ROM.rd(cppVar_55994);
	cppVar_55997 = (cppVar_55995 == 152);
	if (cppVar_55997) {
	cppVar_55993 = SCON;
	} else {
	cppVar_55999 = PC + 1;
	cppVar_55999 = (cppVar_55999 & cppMask_un_16_);
	cppVar_56000 = ROM.rd(cppVar_55999);
	cppVar_56002 = (cppVar_56000 == 153);
	if (cppVar_56002) {
	cppVar_55998 = SBUF;
	} else {
	cppVar_56004 = PC + 1;
	cppVar_56004 = (cppVar_56004 & cppMask_un_16_);
	cppVar_56005 = ROM.rd(cppVar_56004);
	cppVar_56007 = (cppVar_56005 == 160);
	if (cppVar_56007) {
	cppVar_56003 = P2;
	} else {
	cppVar_56009 = PC + 1;
	cppVar_56009 = (cppVar_56009 & cppMask_un_16_);
	cppVar_56010 = ROM.rd(cppVar_56009);
	cppVar_56012 = (cppVar_56010 == 168);
	if (cppVar_56012) {
	cppVar_56008 = IE;
	} else {
	cppVar_56014 = PC + 1;
	cppVar_56014 = (cppVar_56014 & cppMask_un_16_);
	cppVar_56015 = ROM.rd(cppVar_56014);
	cppVar_56017 = (cppVar_56015 == 176);
	if (cppVar_56017) {
	cppVar_56013 = P3;
	} else {
	cppVar_56019 = PC + 1;
	cppVar_56019 = (cppVar_56019 & cppMask_un_16_);
	cppVar_56020 = ROM.rd(cppVar_56019);
	cppVar_56022 = (cppVar_56020 == 184);
	if (cppVar_56022) {
	cppVar_56018 = IP;
	} else {
	cppVar_56024 = PC + 1;
	cppVar_56024 = (cppVar_56024 & cppMask_un_16_);
	cppVar_56025 = ROM.rd(cppVar_56024);
	cppVar_56027 = (cppVar_56025 == 208);
	if (cppVar_56027) {
	cppVar_56023 = PSW;
	} else {
	cppVar_56029 = PC + 1;
	cppVar_56029 = (cppVar_56029 & cppMask_un_16_);
	cppVar_56030 = ROM.rd(cppVar_56029);
	cppVar_56032 = (cppVar_56030 == 224);
	if (cppVar_56032) {
	cppVar_56028 = ACC;
	} else {
	cppVar_56034 = PC + 1;
	cppVar_56034 = (cppVar_56034 & cppMask_un_16_);
	cppVar_56035 = ROM.rd(cppVar_56034);
	cppVar_56037 = (cppVar_56035 == 240);
	if (cppVar_56037) {
	cppVar_56033 = B;
	} else {
	cppVar_56033 = 0;
	}
	cppVar_56028 = cppVar_56033;
	}
	cppVar_56023 = cppVar_56028;
	}
	cppVar_56018 = cppVar_56023;
	}
	cppVar_56013 = cppVar_56018;
	}
	cppVar_56008 = cppVar_56013;
	}
	cppVar_56003 = cppVar_56008;
	}
	cppVar_55998 = cppVar_56003;
	}
	cppVar_55993 = cppVar_55998;
	}
	cppVar_55988 = cppVar_55993;
	}
	cppVar_55983 = cppVar_55988;
	}
	cppVar_55978 = cppVar_55983;
	}
	cppVar_55973 = cppVar_55978;
	}
	cppVar_55968 = cppVar_55973;
	}
	cppVar_55963 = cppVar_55968;
	}
	cppVar_55958 = cppVar_55963;
	}
	cppVar_55953 = cppVar_55958;
	}
	cppVar_55948 = cppVar_55953;
	}
	cppVar_55943 = cppVar_55948;
	}
	cppVar_55938 = cppVar_55943;
	}
	cppVar_55933 = cppVar_55938;
	}
	cppVar_55923 = cppVar_55933;
	}
	cppVar_56039 = (cppVar_55923 & cppMask_un_8_);
	cppVar_56040 = cppVar_55922 + cppVar_56039;
	cppVar_56040 = (cppVar_56040 & cppMask_un_9_);
	cppVar_56042 = 0;
	cppVar_56043 = cppVar_56040 + cppVar_56042;
	cppVar_56043 = (cppVar_56043 & cppMask_un_9_);
	cppVar_56044 = (cppVar_56043 >> 8) & cppMask_un_1_;
	cppVar_56045 = (ACC >> 0) & cppMask_un_4_;
	cppVar_56046 = (cppVar_56045 & cppMask_un_4_);
	cppVar_56048 = PC + 1;
	cppVar_56048 = (cppVar_56048 & cppMask_un_16_);
	cppVar_56049 = ROM.rd(cppVar_56048);
	cppVar_56050 = (cppVar_56049 >> 7) & cppMask_un_1_;
	cppVar_56051 = (cppVar_56050 == 0);
	if (cppVar_56051) {
	cppVar_56052 = PC + 1;
	cppVar_56052 = (cppVar_56052 & cppMask_un_16_);
	cppVar_56053 = ROM.rd(cppVar_56052);
	cppVar_56054 = IRAM.rd(cppVar_56053);
	cppVar_56047 = cppVar_56054;
	} else {
	cppVar_56056 = PC + 1;
	cppVar_56056 = (cppVar_56056 & cppMask_un_16_);
	cppVar_56057 = ROM.rd(cppVar_56056);
	cppVar_56058 = (cppVar_56057 == 128);
	if (cppVar_56058) {
	cppVar_56055 = P0;
	} else {
	cppVar_56060 = PC + 1;
	cppVar_56060 = (cppVar_56060 & cppMask_un_16_);
	cppVar_56061 = ROM.rd(cppVar_56060);
	cppVar_56062 = (cppVar_56061 == 129);
	if (cppVar_56062) {
	cppVar_56059 = SP;
	} else {
	cppVar_56064 = PC + 1;
	cppVar_56064 = (cppVar_56064 & cppMask_un_16_);
	cppVar_56065 = ROM.rd(cppVar_56064);
	cppVar_56066 = (cppVar_56065 == 130);
	if (cppVar_56066) {
	cppVar_56063 = DPL;
	} else {
	cppVar_56068 = PC + 1;
	cppVar_56068 = (cppVar_56068 & cppMask_un_16_);
	cppVar_56069 = ROM.rd(cppVar_56068);
	cppVar_56070 = (cppVar_56069 == 131);
	if (cppVar_56070) {
	cppVar_56067 = DPH;
	} else {
	cppVar_56072 = PC + 1;
	cppVar_56072 = (cppVar_56072 & cppMask_un_16_);
	cppVar_56073 = ROM.rd(cppVar_56072);
	cppVar_56074 = (cppVar_56073 == 135);
	if (cppVar_56074) {
	cppVar_56071 = PCON;
	} else {
	cppVar_56076 = PC + 1;
	cppVar_56076 = (cppVar_56076 & cppMask_un_16_);
	cppVar_56077 = ROM.rd(cppVar_56076);
	cppVar_56078 = (cppVar_56077 == 136);
	if (cppVar_56078) {
	cppVar_56075 = TCON;
	} else {
	cppVar_56080 = PC + 1;
	cppVar_56080 = (cppVar_56080 & cppMask_un_16_);
	cppVar_56081 = ROM.rd(cppVar_56080);
	cppVar_56082 = (cppVar_56081 == 137);
	if (cppVar_56082) {
	cppVar_56079 = TMOD;
	} else {
	cppVar_56084 = PC + 1;
	cppVar_56084 = (cppVar_56084 & cppMask_un_16_);
	cppVar_56085 = ROM.rd(cppVar_56084);
	cppVar_56086 = (cppVar_56085 == 138);
	if (cppVar_56086) {
	cppVar_56083 = TL0;
	} else {
	cppVar_56088 = PC + 1;
	cppVar_56088 = (cppVar_56088 & cppMask_un_16_);
	cppVar_56089 = ROM.rd(cppVar_56088);
	cppVar_56090 = (cppVar_56089 == 140);
	if (cppVar_56090) {
	cppVar_56087 = TH0;
	} else {
	cppVar_56092 = PC + 1;
	cppVar_56092 = (cppVar_56092 & cppMask_un_16_);
	cppVar_56093 = ROM.rd(cppVar_56092);
	cppVar_56094 = (cppVar_56093 == 139);
	if (cppVar_56094) {
	cppVar_56091 = TL1;
	} else {
	cppVar_56096 = PC + 1;
	cppVar_56096 = (cppVar_56096 & cppMask_un_16_);
	cppVar_56097 = ROM.rd(cppVar_56096);
	cppVar_56098 = (cppVar_56097 == 141);
	if (cppVar_56098) {
	cppVar_56095 = TH1;
	} else {
	cppVar_56100 = PC + 1;
	cppVar_56100 = (cppVar_56100 & cppMask_un_16_);
	cppVar_56101 = ROM.rd(cppVar_56100);
	cppVar_56102 = (cppVar_56101 == 144);
	if (cppVar_56102) {
	cppVar_56099 = P1;
	} else {
	cppVar_56104 = PC + 1;
	cppVar_56104 = (cppVar_56104 & cppMask_un_16_);
	cppVar_56105 = ROM.rd(cppVar_56104);
	cppVar_56106 = (cppVar_56105 == 152);
	if (cppVar_56106) {
	cppVar_56103 = SCON;
	} else {
	cppVar_56108 = PC + 1;
	cppVar_56108 = (cppVar_56108 & cppMask_un_16_);
	cppVar_56109 = ROM.rd(cppVar_56108);
	cppVar_56110 = (cppVar_56109 == 153);
	if (cppVar_56110) {
	cppVar_56107 = SBUF;
	} else {
	cppVar_56112 = PC + 1;
	cppVar_56112 = (cppVar_56112 & cppMask_un_16_);
	cppVar_56113 = ROM.rd(cppVar_56112);
	cppVar_56114 = (cppVar_56113 == 160);
	if (cppVar_56114) {
	cppVar_56111 = P2;
	} else {
	cppVar_56116 = PC + 1;
	cppVar_56116 = (cppVar_56116 & cppMask_un_16_);
	cppVar_56117 = ROM.rd(cppVar_56116);
	cppVar_56118 = (cppVar_56117 == 168);
	if (cppVar_56118) {
	cppVar_56115 = IE;
	} else {
	cppVar_56120 = PC + 1;
	cppVar_56120 = (cppVar_56120 & cppMask_un_16_);
	cppVar_56121 = ROM.rd(cppVar_56120);
	cppVar_56122 = (cppVar_56121 == 176);
	if (cppVar_56122) {
	cppVar_56119 = P3;
	} else {
	cppVar_56124 = PC + 1;
	cppVar_56124 = (cppVar_56124 & cppMask_un_16_);
	cppVar_56125 = ROM.rd(cppVar_56124);
	cppVar_56126 = (cppVar_56125 == 184);
	if (cppVar_56126) {
	cppVar_56123 = IP;
	} else {
	cppVar_56128 = PC + 1;
	cppVar_56128 = (cppVar_56128 & cppMask_un_16_);
	cppVar_56129 = ROM.rd(cppVar_56128);
	cppVar_56130 = (cppVar_56129 == 208);
	if (cppVar_56130) {
	cppVar_56127 = PSW;
	} else {
	cppVar_56132 = PC + 1;
	cppVar_56132 = (cppVar_56132 & cppMask_un_16_);
	cppVar_56133 = ROM.rd(cppVar_56132);
	cppVar_56134 = (cppVar_56133 == 224);
	if (cppVar_56134) {
	cppVar_56131 = ACC;
	} else {
	cppVar_56136 = PC + 1;
	cppVar_56136 = (cppVar_56136 & cppMask_un_16_);
	cppVar_56137 = ROM.rd(cppVar_56136);
	cppVar_56138 = (cppVar_56137 == 240);
	if (cppVar_56138) {
	cppVar_56135 = B;
	} else {
	cppVar_56135 = 0;
	}
	cppVar_56131 = cppVar_56135;
	}
	cppVar_56127 = cppVar_56131;
	}
	cppVar_56123 = cppVar_56127;
	}
	cppVar_56119 = cppVar_56123;
	}
	cppVar_56115 = cppVar_56119;
	}
	cppVar_56111 = cppVar_56115;
	}
	cppVar_56107 = cppVar_56111;
	}
	cppVar_56103 = cppVar_56107;
	}
	cppVar_56099 = cppVar_56103;
	}
	cppVar_56095 = cppVar_56099;
	}
	cppVar_56091 = cppVar_56095;
	}
	cppVar_56087 = cppVar_56091;
	}
	cppVar_56083 = cppVar_56087;
	}
	cppVar_56079 = cppVar_56083;
	}
	cppVar_56075 = cppVar_56079;
	}
	cppVar_56071 = cppVar_56075;
	}
	cppVar_56067 = cppVar_56071;
	}
	cppVar_56063 = cppVar_56067;
	}
	cppVar_56059 = cppVar_56063;
	}
	cppVar_56055 = cppVar_56059;
	}
	cppVar_56047 = cppVar_56055;
	}
	cppVar_56139 = (cppVar_56047 >> 0) & cppMask_un_4_;
	cppVar_56140 = (cppVar_56139 & cppMask_un_4_);
	cppVar_56141 = cppVar_56046 + cppVar_56140;
	cppVar_56141 = (cppVar_56141 & cppMask_un_5_);
	cppVar_56142 = 0;
	cppVar_56143 = cppVar_56141 + cppVar_56142;
	cppVar_56143 = (cppVar_56143 & cppMask_un_5_);
	cppVar_56144 = (cppVar_56143 >> 4) & cppMask_un_1_;
	cppVar_56145 = (PSW >> 3) & cppMask_un_3_;
	cppVar_56147 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_56149 = PC + 1;
	cppVar_56149 = (cppVar_56149 & cppMask_un_16_);
	cppVar_56150 = ROM.rd(cppVar_56149);
	cppVar_56151 = (cppVar_56150 >> 7) & cppMask_un_1_;
	cppVar_56152 = (cppVar_56151 == 0);
	if (cppVar_56152) {
	cppVar_56153 = PC + 1;
	cppVar_56153 = (cppVar_56153 & cppMask_un_16_);
	cppVar_56154 = ROM.rd(cppVar_56153);
	cppVar_56155 = IRAM.rd(cppVar_56154);
	cppVar_56148 = cppVar_56155;
	} else {
	cppVar_56157 = PC + 1;
	cppVar_56157 = (cppVar_56157 & cppMask_un_16_);
	cppVar_56158 = ROM.rd(cppVar_56157);
	cppVar_56159 = (cppVar_56158 == 128);
	if (cppVar_56159) {
	cppVar_56156 = P0;
	} else {
	cppVar_56161 = PC + 1;
	cppVar_56161 = (cppVar_56161 & cppMask_un_16_);
	cppVar_56162 = ROM.rd(cppVar_56161);
	cppVar_56163 = (cppVar_56162 == 129);
	if (cppVar_56163) {
	cppVar_56160 = SP;
	} else {
	cppVar_56165 = PC + 1;
	cppVar_56165 = (cppVar_56165 & cppMask_un_16_);
	cppVar_56166 = ROM.rd(cppVar_56165);
	cppVar_56167 = (cppVar_56166 == 130);
	if (cppVar_56167) {
	cppVar_56164 = DPL;
	} else {
	cppVar_56169 = PC + 1;
	cppVar_56169 = (cppVar_56169 & cppMask_un_16_);
	cppVar_56170 = ROM.rd(cppVar_56169);
	cppVar_56171 = (cppVar_56170 == 131);
	if (cppVar_56171) {
	cppVar_56168 = DPH;
	} else {
	cppVar_56173 = PC + 1;
	cppVar_56173 = (cppVar_56173 & cppMask_un_16_);
	cppVar_56174 = ROM.rd(cppVar_56173);
	cppVar_56175 = (cppVar_56174 == 135);
	if (cppVar_56175) {
	cppVar_56172 = PCON;
	} else {
	cppVar_56177 = PC + 1;
	cppVar_56177 = (cppVar_56177 & cppMask_un_16_);
	cppVar_56178 = ROM.rd(cppVar_56177);
	cppVar_56179 = (cppVar_56178 == 136);
	if (cppVar_56179) {
	cppVar_56176 = TCON;
	} else {
	cppVar_56181 = PC + 1;
	cppVar_56181 = (cppVar_56181 & cppMask_un_16_);
	cppVar_56182 = ROM.rd(cppVar_56181);
	cppVar_56183 = (cppVar_56182 == 137);
	if (cppVar_56183) {
	cppVar_56180 = TMOD;
	} else {
	cppVar_56185 = PC + 1;
	cppVar_56185 = (cppVar_56185 & cppMask_un_16_);
	cppVar_56186 = ROM.rd(cppVar_56185);
	cppVar_56187 = (cppVar_56186 == 138);
	if (cppVar_56187) {
	cppVar_56184 = TL0;
	} else {
	cppVar_56189 = PC + 1;
	cppVar_56189 = (cppVar_56189 & cppMask_un_16_);
	cppVar_56190 = ROM.rd(cppVar_56189);
	cppVar_56191 = (cppVar_56190 == 140);
	if (cppVar_56191) {
	cppVar_56188 = TH0;
	} else {
	cppVar_56193 = PC + 1;
	cppVar_56193 = (cppVar_56193 & cppMask_un_16_);
	cppVar_56194 = ROM.rd(cppVar_56193);
	cppVar_56195 = (cppVar_56194 == 139);
	if (cppVar_56195) {
	cppVar_56192 = TL1;
	} else {
	cppVar_56197 = PC + 1;
	cppVar_56197 = (cppVar_56197 & cppMask_un_16_);
	cppVar_56198 = ROM.rd(cppVar_56197);
	cppVar_56199 = (cppVar_56198 == 141);
	if (cppVar_56199) {
	cppVar_56196 = TH1;
	} else {
	cppVar_56201 = PC + 1;
	cppVar_56201 = (cppVar_56201 & cppMask_un_16_);
	cppVar_56202 = ROM.rd(cppVar_56201);
	cppVar_56203 = (cppVar_56202 == 144);
	if (cppVar_56203) {
	cppVar_56200 = P1;
	} else {
	cppVar_56205 = PC + 1;
	cppVar_56205 = (cppVar_56205 & cppMask_un_16_);
	cppVar_56206 = ROM.rd(cppVar_56205);
	cppVar_56207 = (cppVar_56206 == 152);
	if (cppVar_56207) {
	cppVar_56204 = SCON;
	} else {
	cppVar_56209 = PC + 1;
	cppVar_56209 = (cppVar_56209 & cppMask_un_16_);
	cppVar_56210 = ROM.rd(cppVar_56209);
	cppVar_56211 = (cppVar_56210 == 153);
	if (cppVar_56211) {
	cppVar_56208 = SBUF;
	} else {
	cppVar_56213 = PC + 1;
	cppVar_56213 = (cppVar_56213 & cppMask_un_16_);
	cppVar_56214 = ROM.rd(cppVar_56213);
	cppVar_56215 = (cppVar_56214 == 160);
	if (cppVar_56215) {
	cppVar_56212 = P2;
	} else {
	cppVar_56217 = PC + 1;
	cppVar_56217 = (cppVar_56217 & cppMask_un_16_);
	cppVar_56218 = ROM.rd(cppVar_56217);
	cppVar_56219 = (cppVar_56218 == 168);
	if (cppVar_56219) {
	cppVar_56216 = IE;
	} else {
	cppVar_56221 = PC + 1;
	cppVar_56221 = (cppVar_56221 & cppMask_un_16_);
	cppVar_56222 = ROM.rd(cppVar_56221);
	cppVar_56223 = (cppVar_56222 == 176);
	if (cppVar_56223) {
	cppVar_56220 = P3;
	} else {
	cppVar_56225 = PC + 1;
	cppVar_56225 = (cppVar_56225 & cppMask_un_16_);
	cppVar_56226 = ROM.rd(cppVar_56225);
	cppVar_56227 = (cppVar_56226 == 184);
	if (cppVar_56227) {
	cppVar_56224 = IP;
	} else {
	cppVar_56229 = PC + 1;
	cppVar_56229 = (cppVar_56229 & cppMask_un_16_);
	cppVar_56230 = ROM.rd(cppVar_56229);
	cppVar_56231 = (cppVar_56230 == 208);
	if (cppVar_56231) {
	cppVar_56228 = PSW;
	} else {
	cppVar_56233 = PC + 1;
	cppVar_56233 = (cppVar_56233 & cppMask_un_16_);
	cppVar_56234 = ROM.rd(cppVar_56233);
	cppVar_56235 = (cppVar_56234 == 224);
	if (cppVar_56235) {
	cppVar_56232 = ACC;
	} else {
	cppVar_56237 = PC + 1;
	cppVar_56237 = (cppVar_56237 & cppMask_un_16_);
	cppVar_56238 = ROM.rd(cppVar_56237);
	cppVar_56239 = (cppVar_56238 == 240);
	if (cppVar_56239) {
	cppVar_56236 = B;
	} else {
	cppVar_56236 = 0;
	}
	cppVar_56232 = cppVar_56236;
	}
	cppVar_56228 = cppVar_56232;
	}
	cppVar_56224 = cppVar_56228;
	}
	cppVar_56220 = cppVar_56224;
	}
	cppVar_56216 = cppVar_56220;
	}
	cppVar_56212 = cppVar_56216;
	}
	cppVar_56208 = cppVar_56212;
	}
	cppVar_56204 = cppVar_56208;
	}
	cppVar_56200 = cppVar_56204;
	}
	cppVar_56196 = cppVar_56200;
	}
	cppVar_56192 = cppVar_56196;
	}
	cppVar_56188 = cppVar_56192;
	}
	cppVar_56184 = cppVar_56188;
	}
	cppVar_56180 = cppVar_56184;
	}
	cppVar_56176 = cppVar_56180;
	}
	cppVar_56172 = cppVar_56176;
	}
	cppVar_56168 = cppVar_56172;
	}
	cppVar_56164 = cppVar_56168;
	}
	cppVar_56160 = cppVar_56164;
	}
	cppVar_56156 = cppVar_56160;
	}
	cppVar_56148 = cppVar_56156;
	}
	cppVar_56240 = ((cppVar_56148 & cppMask_bit_8_) ? (cppVar_56148 | cppMask_sign_8_) : cppVar_56148);
	cppVar_56241 = cppVar_56147 + cppVar_56240;
	cppVar_56241 = (cppVar_56241 & cppMask_un_9_);
	cppVar_56242 = 0;
	cppVar_56243 = cppVar_56241 + cppVar_56242;
	cppVar_56243 = (cppVar_56243 & cppMask_un_9_);
	cppVar_56244 = (cppVar_56243 >> 8) & cppMask_un_1_;
	cppVar_56245 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_56247 = PC + 1;
	cppVar_56247 = (cppVar_56247 & cppMask_un_16_);
	cppVar_56248 = ROM.rd(cppVar_56247);
	cppVar_56249 = (cppVar_56248 >> 7) & cppMask_un_1_;
	cppVar_56250 = (cppVar_56249 == 0);
	if (cppVar_56250) {
	cppVar_56251 = PC + 1;
	cppVar_56251 = (cppVar_56251 & cppMask_un_16_);
	cppVar_56252 = ROM.rd(cppVar_56251);
	cppVar_56253 = IRAM.rd(cppVar_56252);
	cppVar_56246 = cppVar_56253;
	} else {
	cppVar_56255 = PC + 1;
	cppVar_56255 = (cppVar_56255 & cppMask_un_16_);
	cppVar_56256 = ROM.rd(cppVar_56255);
	cppVar_56257 = (cppVar_56256 == 128);
	if (cppVar_56257) {
	cppVar_56254 = P0;
	} else {
	cppVar_56259 = PC + 1;
	cppVar_56259 = (cppVar_56259 & cppMask_un_16_);
	cppVar_56260 = ROM.rd(cppVar_56259);
	cppVar_56261 = (cppVar_56260 == 129);
	if (cppVar_56261) {
	cppVar_56258 = SP;
	} else {
	cppVar_56263 = PC + 1;
	cppVar_56263 = (cppVar_56263 & cppMask_un_16_);
	cppVar_56264 = ROM.rd(cppVar_56263);
	cppVar_56265 = (cppVar_56264 == 130);
	if (cppVar_56265) {
	cppVar_56262 = DPL;
	} else {
	cppVar_56267 = PC + 1;
	cppVar_56267 = (cppVar_56267 & cppMask_un_16_);
	cppVar_56268 = ROM.rd(cppVar_56267);
	cppVar_56269 = (cppVar_56268 == 131);
	if (cppVar_56269) {
	cppVar_56266 = DPH;
	} else {
	cppVar_56271 = PC + 1;
	cppVar_56271 = (cppVar_56271 & cppMask_un_16_);
	cppVar_56272 = ROM.rd(cppVar_56271);
	cppVar_56273 = (cppVar_56272 == 135);
	if (cppVar_56273) {
	cppVar_56270 = PCON;
	} else {
	cppVar_56275 = PC + 1;
	cppVar_56275 = (cppVar_56275 & cppMask_un_16_);
	cppVar_56276 = ROM.rd(cppVar_56275);
	cppVar_56277 = (cppVar_56276 == 136);
	if (cppVar_56277) {
	cppVar_56274 = TCON;
	} else {
	cppVar_56279 = PC + 1;
	cppVar_56279 = (cppVar_56279 & cppMask_un_16_);
	cppVar_56280 = ROM.rd(cppVar_56279);
	cppVar_56281 = (cppVar_56280 == 137);
	if (cppVar_56281) {
	cppVar_56278 = TMOD;
	} else {
	cppVar_56283 = PC + 1;
	cppVar_56283 = (cppVar_56283 & cppMask_un_16_);
	cppVar_56284 = ROM.rd(cppVar_56283);
	cppVar_56285 = (cppVar_56284 == 138);
	if (cppVar_56285) {
	cppVar_56282 = TL0;
	} else {
	cppVar_56287 = PC + 1;
	cppVar_56287 = (cppVar_56287 & cppMask_un_16_);
	cppVar_56288 = ROM.rd(cppVar_56287);
	cppVar_56289 = (cppVar_56288 == 140);
	if (cppVar_56289) {
	cppVar_56286 = TH0;
	} else {
	cppVar_56291 = PC + 1;
	cppVar_56291 = (cppVar_56291 & cppMask_un_16_);
	cppVar_56292 = ROM.rd(cppVar_56291);
	cppVar_56293 = (cppVar_56292 == 139);
	if (cppVar_56293) {
	cppVar_56290 = TL1;
	} else {
	cppVar_56295 = PC + 1;
	cppVar_56295 = (cppVar_56295 & cppMask_un_16_);
	cppVar_56296 = ROM.rd(cppVar_56295);
	cppVar_56297 = (cppVar_56296 == 141);
	if (cppVar_56297) {
	cppVar_56294 = TH1;
	} else {
	cppVar_56299 = PC + 1;
	cppVar_56299 = (cppVar_56299 & cppMask_un_16_);
	cppVar_56300 = ROM.rd(cppVar_56299);
	cppVar_56301 = (cppVar_56300 == 144);
	if (cppVar_56301) {
	cppVar_56298 = P1;
	} else {
	cppVar_56303 = PC + 1;
	cppVar_56303 = (cppVar_56303 & cppMask_un_16_);
	cppVar_56304 = ROM.rd(cppVar_56303);
	cppVar_56305 = (cppVar_56304 == 152);
	if (cppVar_56305) {
	cppVar_56302 = SCON;
	} else {
	cppVar_56307 = PC + 1;
	cppVar_56307 = (cppVar_56307 & cppMask_un_16_);
	cppVar_56308 = ROM.rd(cppVar_56307);
	cppVar_56309 = (cppVar_56308 == 153);
	if (cppVar_56309) {
	cppVar_56306 = SBUF;
	} else {
	cppVar_56311 = PC + 1;
	cppVar_56311 = (cppVar_56311 & cppMask_un_16_);
	cppVar_56312 = ROM.rd(cppVar_56311);
	cppVar_56313 = (cppVar_56312 == 160);
	if (cppVar_56313) {
	cppVar_56310 = P2;
	} else {
	cppVar_56315 = PC + 1;
	cppVar_56315 = (cppVar_56315 & cppMask_un_16_);
	cppVar_56316 = ROM.rd(cppVar_56315);
	cppVar_56317 = (cppVar_56316 == 168);
	if (cppVar_56317) {
	cppVar_56314 = IE;
	} else {
	cppVar_56319 = PC + 1;
	cppVar_56319 = (cppVar_56319 & cppMask_un_16_);
	cppVar_56320 = ROM.rd(cppVar_56319);
	cppVar_56321 = (cppVar_56320 == 176);
	if (cppVar_56321) {
	cppVar_56318 = P3;
	} else {
	cppVar_56323 = PC + 1;
	cppVar_56323 = (cppVar_56323 & cppMask_un_16_);
	cppVar_56324 = ROM.rd(cppVar_56323);
	cppVar_56325 = (cppVar_56324 == 184);
	if (cppVar_56325) {
	cppVar_56322 = IP;
	} else {
	cppVar_56327 = PC + 1;
	cppVar_56327 = (cppVar_56327 & cppMask_un_16_);
	cppVar_56328 = ROM.rd(cppVar_56327);
	cppVar_56329 = (cppVar_56328 == 208);
	if (cppVar_56329) {
	cppVar_56326 = PSW;
	} else {
	cppVar_56331 = PC + 1;
	cppVar_56331 = (cppVar_56331 & cppMask_un_16_);
	cppVar_56332 = ROM.rd(cppVar_56331);
	cppVar_56333 = (cppVar_56332 == 224);
	if (cppVar_56333) {
	cppVar_56330 = ACC;
	} else {
	cppVar_56335 = PC + 1;
	cppVar_56335 = (cppVar_56335 & cppMask_un_16_);
	cppVar_56336 = ROM.rd(cppVar_56335);
	cppVar_56337 = (cppVar_56336 == 240);
	if (cppVar_56337) {
	cppVar_56334 = B;
	} else {
	cppVar_56334 = 0;
	}
	cppVar_56330 = cppVar_56334;
	}
	cppVar_56326 = cppVar_56330;
	}
	cppVar_56322 = cppVar_56326;
	}
	cppVar_56318 = cppVar_56322;
	}
	cppVar_56314 = cppVar_56318;
	}
	cppVar_56310 = cppVar_56314;
	}
	cppVar_56306 = cppVar_56310;
	}
	cppVar_56302 = cppVar_56306;
	}
	cppVar_56298 = cppVar_56302;
	}
	cppVar_56294 = cppVar_56298;
	}
	cppVar_56290 = cppVar_56294;
	}
	cppVar_56286 = cppVar_56290;
	}
	cppVar_56282 = cppVar_56286;
	}
	cppVar_56278 = cppVar_56282;
	}
	cppVar_56274 = cppVar_56278;
	}
	cppVar_56270 = cppVar_56274;
	}
	cppVar_56266 = cppVar_56270;
	}
	cppVar_56262 = cppVar_56266;
	}
	cppVar_56258 = cppVar_56262;
	}
	cppVar_56254 = cppVar_56258;
	}
	cppVar_56246 = cppVar_56254;
	}
	cppVar_56338 = ((cppVar_56246 & cppMask_bit_8_) ? (cppVar_56246 | cppMask_sign_8_) : cppVar_56246);
	cppVar_56339 = cppVar_56245 + cppVar_56338;
	cppVar_56339 = (cppVar_56339 & cppMask_un_9_);
	cppVar_56340 = 0;
	cppVar_56341 = cppVar_56339 + cppVar_56340;
	cppVar_56341 = (cppVar_56341 & cppMask_un_9_);
	cppVar_56342 = (cppVar_56341 >> 7) & cppMask_un_1_;
	cppVar_56343 = (cppVar_56244 != cppVar_56342);
	if (cppVar_56343) {
	cppVar_56146 = 1;
	} else {
	cppVar_56146 = 0;
	}
	cppVar_56346 = (PSW >> 0) & cppMask_un_2_;
	cppVar_56347 = (cppVar_56146 << 2) | cppVar_56346;
	cppVar_56347 = (cppVar_56347 & cppMask_un_3_);
	cppVar_56348 = (cppVar_56145 << 3) | cppVar_56347;
	cppVar_56348 = (cppVar_56348 & cppMask_un_6_);
	cppVar_56349 = (cppVar_56144 << 6) | cppVar_56348;
	cppVar_56349 = (cppVar_56349 & cppMask_un_7_);
	cppVar_56350 = (cppVar_56044 << 7) | cppVar_56349;
	cppVar_56350 = (cppVar_56350 & cppMask_un_8_);
	cppVar_55918 = cppVar_56350;
	} else {
	cppVar_56352 = ROM.rd(PC);
	cppVar_56354 = (cppVar_56352 == 36);
	if (cppVar_56354) {
	cppVar_56355 = (ACC & cppMask_un_8_);
	cppVar_56357 = PC + 1;
	cppVar_56357 = (cppVar_56357 & cppMask_un_16_);
	cppVar_56358 = ROM.rd(cppVar_56357);
	cppVar_56359 = (cppVar_56358 & cppMask_un_8_);
	cppVar_56360 = cppVar_56355 + cppVar_56359;
	cppVar_56360 = (cppVar_56360 & cppMask_un_9_);
	cppVar_56362 = 0;
	cppVar_56363 = cppVar_56360 + cppVar_56362;
	cppVar_56363 = (cppVar_56363 & cppMask_un_9_);
	cppVar_56364 = (cppVar_56363 >> 8) & cppMask_un_1_;
	cppVar_56365 = (ACC >> 0) & cppMask_un_4_;
	cppVar_56366 = (cppVar_56365 & cppMask_un_4_);
	cppVar_56367 = PC + 1;
	cppVar_56367 = (cppVar_56367 & cppMask_un_16_);
	cppVar_56368 = ROM.rd(cppVar_56367);
	cppVar_56369 = (cppVar_56368 >> 0) & cppMask_un_4_;
	cppVar_56370 = (cppVar_56369 & cppMask_un_4_);
	cppVar_56371 = cppVar_56366 + cppVar_56370;
	cppVar_56371 = (cppVar_56371 & cppMask_un_5_);
	cppVar_56372 = 0;
	cppVar_56373 = cppVar_56371 + cppVar_56372;
	cppVar_56373 = (cppVar_56373 & cppMask_un_5_);
	cppVar_56374 = (cppVar_56373 >> 4) & cppMask_un_1_;
	cppVar_56375 = (PSW >> 3) & cppMask_un_3_;
	cppVar_56377 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_56378 = PC + 1;
	cppVar_56378 = (cppVar_56378 & cppMask_un_16_);
	cppVar_56379 = ROM.rd(cppVar_56378);
	cppVar_56380 = ((cppVar_56379 & cppMask_bit_8_) ? (cppVar_56379 | cppMask_sign_8_) : cppVar_56379);
	cppVar_56381 = cppVar_56377 + cppVar_56380;
	cppVar_56381 = (cppVar_56381 & cppMask_un_9_);
	cppVar_56382 = 0;
	cppVar_56383 = cppVar_56381 + cppVar_56382;
	cppVar_56383 = (cppVar_56383 & cppMask_un_9_);
	cppVar_56384 = (cppVar_56383 >> 8) & cppMask_un_1_;
	cppVar_56385 = ((ACC & cppMask_bit_8_) ? (ACC | cppMask_sign_8_) : ACC);
	cppVar_56386 = PC + 1;
	cppVar_56386 = (cppVar_56386 & cppMask_un_16_);
	cppVar_56387 = ROM.rd(cppVar_56386);
	cppVar_56388 = ((cppVar_56387 & cppMask_bit_8_) ? (cppVar_56387 | cppMask_sign_8_) : cppVar_56387);
	cppVar_56389 = cppVar_56385 + cppVar_56388;
	cppVar_56389 = (cppVar_56389 & cppMask_un_9_);
	cppVar_56390 = 0;
	cppVar_56391 = cppVar_56389 + cppVar_56390;
	cppVar_56391 = (cppVar_56391 & cppMask_un_9_);
	cppVar_56392 = (cppVar_56391 >> 7) & cppMask_un_1_;
	cppVar_56393 = (cppVar_56384 != cppVar_56392);
	if (cppVar_56393) {
	cppVar_56376 = 1;
	} else {
	cppVar_56376 = 0;
	}
	cppVar_56396 = (PSW >> 0) & cppMask_un_2_;
	cppVar_56397 = (cppVar_56376 << 2) | cppVar_56396;
	cppVar_56397 = (cppVar_56397 & cppMask_un_3_);
	cppVar_56398 = (cppVar_56375 << 3) | cppVar_56397;
	cppVar_56398 = (cppVar_56398 & cppMask_un_6_);
	cppVar_56399 = (cppVar_56374 << 6) | cppVar_56398;
	cppVar_56399 = (cppVar_56399 & cppMask_un_7_);
	cppVar_56400 = (cppVar_56364 << 7) | cppVar_56399;
	cppVar_56400 = (cppVar_56400 & cppMask_un_8_);
	cppVar_56351 = cppVar_56400;
	} else {
	cppVar_56402 = ROM.rd(PC);
	cppVar_56404 = (cppVar_56402 == 213);
	cppVar_56405 = ROM.rd(PC);
	cppVar_56407 = (cppVar_56405 == 21);
	cppVar_56408 = cppVar_56404 || cppVar_56407;
	if (cppVar_56408) {
	cppVar_56411 = PC + 1;
	cppVar_56411 = (cppVar_56411 & cppMask_un_16_);
	cppVar_56412 = ROM.rd(cppVar_56411);
	cppVar_56414 = (cppVar_56412 == 208);
	if (cppVar_56414) {
	cppVar_56416 = PC + 1;
	cppVar_56416 = (cppVar_56416 & cppMask_un_16_);
	cppVar_56417 = ROM.rd(cppVar_56416);
	cppVar_56418 = (cppVar_56417 >> 7) & cppMask_un_1_;
	cppVar_56420 = (cppVar_56418 == 0);
	if (cppVar_56420) {
	cppVar_56421 = PC + 1;
	cppVar_56421 = (cppVar_56421 & cppMask_un_16_);
	cppVar_56422 = ROM.rd(cppVar_56421);
	cppVar_56423 = IRAM.rd(cppVar_56422);
	cppVar_56415 = cppVar_56423;
	} else {
	cppVar_56425 = PC + 1;
	cppVar_56425 = (cppVar_56425 & cppMask_un_16_);
	cppVar_56426 = ROM.rd(cppVar_56425);
	cppVar_56428 = (cppVar_56426 == 128);
	if (cppVar_56428) {
	cppVar_56424 = P0;
	} else {
	cppVar_56430 = PC + 1;
	cppVar_56430 = (cppVar_56430 & cppMask_un_16_);
	cppVar_56431 = ROM.rd(cppVar_56430);
	cppVar_56433 = (cppVar_56431 == 129);
	if (cppVar_56433) {
	cppVar_56429 = SP;
	} else {
	cppVar_56435 = PC + 1;
	cppVar_56435 = (cppVar_56435 & cppMask_un_16_);
	cppVar_56436 = ROM.rd(cppVar_56435);
	cppVar_56438 = (cppVar_56436 == 130);
	if (cppVar_56438) {
	cppVar_56434 = DPL;
	} else {
	cppVar_56440 = PC + 1;
	cppVar_56440 = (cppVar_56440 & cppMask_un_16_);
	cppVar_56441 = ROM.rd(cppVar_56440);
	cppVar_56443 = (cppVar_56441 == 131);
	if (cppVar_56443) {
	cppVar_56439 = DPH;
	} else {
	cppVar_56445 = PC + 1;
	cppVar_56445 = (cppVar_56445 & cppMask_un_16_);
	cppVar_56446 = ROM.rd(cppVar_56445);
	cppVar_56448 = (cppVar_56446 == 135);
	if (cppVar_56448) {
	cppVar_56444 = PCON;
	} else {
	cppVar_56450 = PC + 1;
	cppVar_56450 = (cppVar_56450 & cppMask_un_16_);
	cppVar_56451 = ROM.rd(cppVar_56450);
	cppVar_56453 = (cppVar_56451 == 136);
	if (cppVar_56453) {
	cppVar_56449 = TCON;
	} else {
	cppVar_56455 = PC + 1;
	cppVar_56455 = (cppVar_56455 & cppMask_un_16_);
	cppVar_56456 = ROM.rd(cppVar_56455);
	cppVar_56458 = (cppVar_56456 == 137);
	if (cppVar_56458) {
	cppVar_56454 = TMOD;
	} else {
	cppVar_56460 = PC + 1;
	cppVar_56460 = (cppVar_56460 & cppMask_un_16_);
	cppVar_56461 = ROM.rd(cppVar_56460);
	cppVar_56463 = (cppVar_56461 == 138);
	if (cppVar_56463) {
	cppVar_56459 = TL0;
	} else {
	cppVar_56465 = PC + 1;
	cppVar_56465 = (cppVar_56465 & cppMask_un_16_);
	cppVar_56466 = ROM.rd(cppVar_56465);
	cppVar_56468 = (cppVar_56466 == 140);
	if (cppVar_56468) {
	cppVar_56464 = TH0;
	} else {
	cppVar_56470 = PC + 1;
	cppVar_56470 = (cppVar_56470 & cppMask_un_16_);
	cppVar_56471 = ROM.rd(cppVar_56470);
	cppVar_56473 = (cppVar_56471 == 139);
	if (cppVar_56473) {
	cppVar_56469 = TL1;
	} else {
	cppVar_56475 = PC + 1;
	cppVar_56475 = (cppVar_56475 & cppMask_un_16_);
	cppVar_56476 = ROM.rd(cppVar_56475);
	cppVar_56478 = (cppVar_56476 == 141);
	if (cppVar_56478) {
	cppVar_56474 = TH1;
	} else {
	cppVar_56480 = PC + 1;
	cppVar_56480 = (cppVar_56480 & cppMask_un_16_);
	cppVar_56481 = ROM.rd(cppVar_56480);
	cppVar_56483 = (cppVar_56481 == 144);
	if (cppVar_56483) {
	cppVar_56479 = P1;
	} else {
	cppVar_56485 = PC + 1;
	cppVar_56485 = (cppVar_56485 & cppMask_un_16_);
	cppVar_56486 = ROM.rd(cppVar_56485);
	cppVar_56488 = (cppVar_56486 == 152);
	if (cppVar_56488) {
	cppVar_56484 = SCON;
	} else {
	cppVar_56490 = PC + 1;
	cppVar_56490 = (cppVar_56490 & cppMask_un_16_);
	cppVar_56491 = ROM.rd(cppVar_56490);
	cppVar_56493 = (cppVar_56491 == 153);
	if (cppVar_56493) {
	cppVar_56489 = SBUF;
	} else {
	cppVar_56495 = PC + 1;
	cppVar_56495 = (cppVar_56495 & cppMask_un_16_);
	cppVar_56496 = ROM.rd(cppVar_56495);
	cppVar_56498 = (cppVar_56496 == 160);
	if (cppVar_56498) {
	cppVar_56494 = P2;
	} else {
	cppVar_56500 = PC + 1;
	cppVar_56500 = (cppVar_56500 & cppMask_un_16_);
	cppVar_56501 = ROM.rd(cppVar_56500);
	cppVar_56503 = (cppVar_56501 == 168);
	if (cppVar_56503) {
	cppVar_56499 = IE;
	} else {
	cppVar_56505 = PC + 1;
	cppVar_56505 = (cppVar_56505 & cppMask_un_16_);
	cppVar_56506 = ROM.rd(cppVar_56505);
	cppVar_56508 = (cppVar_56506 == 176);
	if (cppVar_56508) {
	cppVar_56504 = P3;
	} else {
	cppVar_56510 = PC + 1;
	cppVar_56510 = (cppVar_56510 & cppMask_un_16_);
	cppVar_56511 = ROM.rd(cppVar_56510);
	cppVar_56513 = (cppVar_56511 == 184);
	if (cppVar_56513) {
	cppVar_56509 = IP;
	} else {
	cppVar_56515 = PC + 1;
	cppVar_56515 = (cppVar_56515 & cppMask_un_16_);
	cppVar_56516 = ROM.rd(cppVar_56515);
	cppVar_56518 = (cppVar_56516 == 208);
	if (cppVar_56518) {
	cppVar_56514 = PSW;
	} else {
	cppVar_56520 = PC + 1;
	cppVar_56520 = (cppVar_56520 & cppMask_un_16_);
	cppVar_56521 = ROM.rd(cppVar_56520);
	cppVar_56523 = (cppVar_56521 == 224);
	if (cppVar_56523) {
	cppVar_56519 = ACC;
	} else {
	cppVar_56525 = PC + 1;
	cppVar_56525 = (cppVar_56525 & cppMask_un_16_);
	cppVar_56526 = ROM.rd(cppVar_56525);
	cppVar_56528 = (cppVar_56526 == 240);
	if (cppVar_56528) {
	cppVar_56524 = B;
	} else {
	cppVar_56524 = 0;
	}
	cppVar_56519 = cppVar_56524;
	}
	cppVar_56514 = cppVar_56519;
	}
	cppVar_56509 = cppVar_56514;
	}
	cppVar_56504 = cppVar_56509;
	}
	cppVar_56499 = cppVar_56504;
	}
	cppVar_56494 = cppVar_56499;
	}
	cppVar_56489 = cppVar_56494;
	}
	cppVar_56484 = cppVar_56489;
	}
	cppVar_56479 = cppVar_56484;
	}
	cppVar_56474 = cppVar_56479;
	}
	cppVar_56469 = cppVar_56474;
	}
	cppVar_56464 = cppVar_56469;
	}
	cppVar_56459 = cppVar_56464;
	}
	cppVar_56454 = cppVar_56459;
	}
	cppVar_56449 = cppVar_56454;
	}
	cppVar_56444 = cppVar_56449;
	}
	cppVar_56439 = cppVar_56444;
	}
	cppVar_56434 = cppVar_56439;
	}
	cppVar_56429 = cppVar_56434;
	}
	cppVar_56424 = cppVar_56429;
	}
	cppVar_56415 = cppVar_56424;
	}
	cppVar_56531 = cppVar_56415 - 1;
	cppVar_56531 = (cppVar_56531 & cppMask_un_8_);
	cppVar_56409 = cppVar_56531;
	} else {
	cppVar_56409 = PSW;
	}
	cppVar_56401 = cppVar_56409;
	} else {
	cppVar_56533 = ROM.rd(PC);
	cppVar_56535 = (cppVar_56533 == 19);
	if (cppVar_56535) {
	cppVar_56536 = (ACC >> 0) & cppMask_un_1_;
	cppVar_56537 = (PSW >> 6) & cppMask_un_1_;
	cppVar_56538 = (PSW >> 3) & cppMask_un_3_;
	cppVar_56539 = (PSW >> 2) & cppMask_un_1_;
	cppVar_56540 = (PSW >> 0) & cppMask_un_2_;
	cppVar_56541 = (cppVar_56539 << 2) | cppVar_56540;
	cppVar_56541 = (cppVar_56541 & cppMask_un_3_);
	cppVar_56542 = (cppVar_56538 << 3) | cppVar_56541;
	cppVar_56542 = (cppVar_56542 & cppMask_un_6_);
	cppVar_56543 = (cppVar_56537 << 6) | cppVar_56542;
	cppVar_56543 = (cppVar_56543 & cppMask_un_7_);
	cppVar_56544 = (cppVar_56536 << 7) | cppVar_56543;
	cppVar_56544 = (cppVar_56544 & cppMask_un_8_);
	cppVar_56532 = cppVar_56544;
	} else {
	cppVar_56546 = ROM.rd(PC);
	cppVar_56548 = (cppVar_56546 == 194);
	cppVar_56549 = ROM.rd(PC);
	cppVar_56551 = (cppVar_56549 == 16);
	cppVar_56552 = cppVar_56548 || cppVar_56551;
	if (cppVar_56552) {
	cppVar_56556 = PC + 1;
	cppVar_56556 = (cppVar_56556 & cppMask_un_16_);
	cppVar_56557 = ROM.rd(cppVar_56556);
	cppVar_56558 = (cppVar_56557 >> 7) & cppMask_un_1_;
	cppVar_56560 = (cppVar_56558 == 1);
	if (cppVar_56560) {
	cppVar_56561 = PC + 1;
	cppVar_56561 = (cppVar_56561 & cppMask_un_16_);
	cppVar_56562 = ROM.rd(cppVar_56561);
	cppVar_56563 = (cppVar_56562 >> 3) & cppMask_un_5_;
	cppVar_56565 = (cppVar_56563 << 3) | 0;
	cppVar_56565 = (cppVar_56565 & cppMask_un_8_);
	cppVar_56554 = cppVar_56565;
	} else {
	cppVar_56566 = PC + 1;
	cppVar_56566 = (cppVar_56566 & cppMask_un_16_);
	cppVar_56567 = ROM.rd(cppVar_56566);
	cppVar_56568 = (cppVar_56567 >> 3) & cppMask_un_5_;
	cppVar_56569 = (cppVar_56568 & cppMask_un_5_);
	cppVar_56571 = cppVar_56569 + 32;
	cppVar_56571 = (cppVar_56571 & cppMask_un_8_);
	cppVar_56554 = cppVar_56571;
	}
	cppVar_56573 = (cppVar_56554 == 208);
	if (cppVar_56573) {
	cppVar_56575 = PC + 1;
	cppVar_56575 = (cppVar_56575 & cppMask_un_16_);
	cppVar_56576 = ROM.rd(cppVar_56575);
	cppVar_56577 = (cppVar_56576 >> 0) & cppMask_un_3_;
	cppVar_56578 = (cppVar_56577 & cppMask_un_3_);
	cppVar_56579 = 1 << static_cast<unsigned>(cppVar_56578);
	cppVar_56579 = (cppVar_56579 & cppMask_un_8_);
	cppVar_56580 = ~cppVar_56579;
	cppVar_56583 = PC + 1;
	cppVar_56583 = (cppVar_56583 & cppMask_un_16_);
	cppVar_56584 = ROM.rd(cppVar_56583);
	cppVar_56585 = (cppVar_56584 >> 7) & cppMask_un_1_;
	cppVar_56586 = (cppVar_56585 == 1);
	if (cppVar_56586) {
	cppVar_56587 = PC + 1;
	cppVar_56587 = (cppVar_56587 & cppMask_un_16_);
	cppVar_56588 = ROM.rd(cppVar_56587);
	cppVar_56589 = (cppVar_56588 >> 3) & cppMask_un_5_;
	cppVar_56590 = (cppVar_56589 << 3) | 0;
	cppVar_56590 = (cppVar_56590 & cppMask_un_8_);
	cppVar_56582 = cppVar_56590;
	} else {
	cppVar_56591 = PC + 1;
	cppVar_56591 = (cppVar_56591 & cppMask_un_16_);
	cppVar_56592 = ROM.rd(cppVar_56591);
	cppVar_56593 = (cppVar_56592 >> 3) & cppMask_un_5_;
	cppVar_56594 = (cppVar_56593 & cppMask_un_5_);
	cppVar_56595 = cppVar_56594 + 32;
	cppVar_56595 = (cppVar_56595 & cppMask_un_8_);
	cppVar_56582 = cppVar_56595;
	}
	cppVar_56596 = (cppVar_56582 >> 7) & cppMask_un_1_;
	cppVar_56598 = (cppVar_56596 == 0);
	if (cppVar_56598) {
	cppVar_56600 = PC + 1;
	cppVar_56600 = (cppVar_56600 & cppMask_un_16_);
	cppVar_56601 = ROM.rd(cppVar_56600);
	cppVar_56602 = (cppVar_56601 >> 7) & cppMask_un_1_;
	cppVar_56603 = (cppVar_56602 == 1);
	if (cppVar_56603) {
	cppVar_56604 = PC + 1;
	cppVar_56604 = (cppVar_56604 & cppMask_un_16_);
	cppVar_56605 = ROM.rd(cppVar_56604);
	cppVar_56606 = (cppVar_56605 >> 3) & cppMask_un_5_;
	cppVar_56607 = (cppVar_56606 << 3) | 0;
	cppVar_56607 = (cppVar_56607 & cppMask_un_8_);
	cppVar_56599 = cppVar_56607;
	} else {
	cppVar_56608 = PC + 1;
	cppVar_56608 = (cppVar_56608 & cppMask_un_16_);
	cppVar_56609 = ROM.rd(cppVar_56608);
	cppVar_56610 = (cppVar_56609 >> 3) & cppMask_un_5_;
	cppVar_56611 = (cppVar_56610 & cppMask_un_5_);
	cppVar_56612 = cppVar_56611 + 32;
	cppVar_56612 = (cppVar_56612 & cppMask_un_8_);
	cppVar_56599 = cppVar_56612;
	}
	cppVar_56613 = IRAM.rd(cppVar_56599);
	cppVar_56581 = cppVar_56613;
	} else {
	cppVar_56616 = PC + 1;
	cppVar_56616 = (cppVar_56616 & cppMask_un_16_);
	cppVar_56617 = ROM.rd(cppVar_56616);
	cppVar_56618 = (cppVar_56617 >> 7) & cppMask_un_1_;
	cppVar_56619 = (cppVar_56618 == 1);
	if (cppVar_56619) {
	cppVar_56620 = PC + 1;
	cppVar_56620 = (cppVar_56620 & cppMask_un_16_);
	cppVar_56621 = ROM.rd(cppVar_56620);
	cppVar_56622 = (cppVar_56621 >> 3) & cppMask_un_5_;
	cppVar_56623 = (cppVar_56622 << 3) | 0;
	cppVar_56623 = (cppVar_56623 & cppMask_un_8_);
	cppVar_56615 = cppVar_56623;
	} else {
	cppVar_56624 = PC + 1;
	cppVar_56624 = (cppVar_56624 & cppMask_un_16_);
	cppVar_56625 = ROM.rd(cppVar_56624);
	cppVar_56626 = (cppVar_56625 >> 3) & cppMask_un_5_;
	cppVar_56627 = (cppVar_56626 & cppMask_un_5_);
	cppVar_56628 = cppVar_56627 + 32;
	cppVar_56628 = (cppVar_56628 & cppMask_un_8_);
	cppVar_56615 = cppVar_56628;
	}
	cppVar_56630 = (cppVar_56615 == 128);
	if (cppVar_56630) {
	cppVar_56614 = P0;
	} else {
	cppVar_56633 = PC + 1;
	cppVar_56633 = (cppVar_56633 & cppMask_un_16_);
	cppVar_56634 = ROM.rd(cppVar_56633);
	cppVar_56635 = (cppVar_56634 >> 7) & cppMask_un_1_;
	cppVar_56636 = (cppVar_56635 == 1);
	if (cppVar_56636) {
	cppVar_56637 = PC + 1;
	cppVar_56637 = (cppVar_56637 & cppMask_un_16_);
	cppVar_56638 = ROM.rd(cppVar_56637);
	cppVar_56639 = (cppVar_56638 >> 3) & cppMask_un_5_;
	cppVar_56640 = (cppVar_56639 << 3) | 0;
	cppVar_56640 = (cppVar_56640 & cppMask_un_8_);
	cppVar_56632 = cppVar_56640;
	} else {
	cppVar_56641 = PC + 1;
	cppVar_56641 = (cppVar_56641 & cppMask_un_16_);
	cppVar_56642 = ROM.rd(cppVar_56641);
	cppVar_56643 = (cppVar_56642 >> 3) & cppMask_un_5_;
	cppVar_56644 = (cppVar_56643 & cppMask_un_5_);
	cppVar_56645 = cppVar_56644 + 32;
	cppVar_56645 = (cppVar_56645 & cppMask_un_8_);
	cppVar_56632 = cppVar_56645;
	}
	cppVar_56647 = (cppVar_56632 == 129);
	if (cppVar_56647) {
	cppVar_56631 = SP;
	} else {
	cppVar_56650 = PC + 1;
	cppVar_56650 = (cppVar_56650 & cppMask_un_16_);
	cppVar_56651 = ROM.rd(cppVar_56650);
	cppVar_56652 = (cppVar_56651 >> 7) & cppMask_un_1_;
	cppVar_56653 = (cppVar_56652 == 1);
	if (cppVar_56653) {
	cppVar_56654 = PC + 1;
	cppVar_56654 = (cppVar_56654 & cppMask_un_16_);
	cppVar_56655 = ROM.rd(cppVar_56654);
	cppVar_56656 = (cppVar_56655 >> 3) & cppMask_un_5_;
	cppVar_56657 = (cppVar_56656 << 3) | 0;
	cppVar_56657 = (cppVar_56657 & cppMask_un_8_);
	cppVar_56649 = cppVar_56657;
	} else {
	cppVar_56658 = PC + 1;
	cppVar_56658 = (cppVar_56658 & cppMask_un_16_);
	cppVar_56659 = ROM.rd(cppVar_56658);
	cppVar_56660 = (cppVar_56659 >> 3) & cppMask_un_5_;
	cppVar_56661 = (cppVar_56660 & cppMask_un_5_);
	cppVar_56662 = cppVar_56661 + 32;
	cppVar_56662 = (cppVar_56662 & cppMask_un_8_);
	cppVar_56649 = cppVar_56662;
	}
	cppVar_56664 = (cppVar_56649 == 130);
	if (cppVar_56664) {
	cppVar_56648 = DPL;
	} else {
	cppVar_56667 = PC + 1;
	cppVar_56667 = (cppVar_56667 & cppMask_un_16_);
	cppVar_56668 = ROM.rd(cppVar_56667);
	cppVar_56669 = (cppVar_56668 >> 7) & cppMask_un_1_;
	cppVar_56670 = (cppVar_56669 == 1);
	if (cppVar_56670) {
	cppVar_56671 = PC + 1;
	cppVar_56671 = (cppVar_56671 & cppMask_un_16_);
	cppVar_56672 = ROM.rd(cppVar_56671);
	cppVar_56673 = (cppVar_56672 >> 3) & cppMask_un_5_;
	cppVar_56674 = (cppVar_56673 << 3) | 0;
	cppVar_56674 = (cppVar_56674 & cppMask_un_8_);
	cppVar_56666 = cppVar_56674;
	} else {
	cppVar_56675 = PC + 1;
	cppVar_56675 = (cppVar_56675 & cppMask_un_16_);
	cppVar_56676 = ROM.rd(cppVar_56675);
	cppVar_56677 = (cppVar_56676 >> 3) & cppMask_un_5_;
	cppVar_56678 = (cppVar_56677 & cppMask_un_5_);
	cppVar_56679 = cppVar_56678 + 32;
	cppVar_56679 = (cppVar_56679 & cppMask_un_8_);
	cppVar_56666 = cppVar_56679;
	}
	cppVar_56681 = (cppVar_56666 == 131);
	if (cppVar_56681) {
	cppVar_56665 = DPH;
	} else {
	cppVar_56684 = PC + 1;
	cppVar_56684 = (cppVar_56684 & cppMask_un_16_);
	cppVar_56685 = ROM.rd(cppVar_56684);
	cppVar_56686 = (cppVar_56685 >> 7) & cppMask_un_1_;
	cppVar_56687 = (cppVar_56686 == 1);
	if (cppVar_56687) {
	cppVar_56688 = PC + 1;
	cppVar_56688 = (cppVar_56688 & cppMask_un_16_);
	cppVar_56689 = ROM.rd(cppVar_56688);
	cppVar_56690 = (cppVar_56689 >> 3) & cppMask_un_5_;
	cppVar_56691 = (cppVar_56690 << 3) | 0;
	cppVar_56691 = (cppVar_56691 & cppMask_un_8_);
	cppVar_56683 = cppVar_56691;
	} else {
	cppVar_56692 = PC + 1;
	cppVar_56692 = (cppVar_56692 & cppMask_un_16_);
	cppVar_56693 = ROM.rd(cppVar_56692);
	cppVar_56694 = (cppVar_56693 >> 3) & cppMask_un_5_;
	cppVar_56695 = (cppVar_56694 & cppMask_un_5_);
	cppVar_56696 = cppVar_56695 + 32;
	cppVar_56696 = (cppVar_56696 & cppMask_un_8_);
	cppVar_56683 = cppVar_56696;
	}
	cppVar_56698 = (cppVar_56683 == 135);
	if (cppVar_56698) {
	cppVar_56682 = PCON;
	} else {
	cppVar_56701 = PC + 1;
	cppVar_56701 = (cppVar_56701 & cppMask_un_16_);
	cppVar_56702 = ROM.rd(cppVar_56701);
	cppVar_56703 = (cppVar_56702 >> 7) & cppMask_un_1_;
	cppVar_56704 = (cppVar_56703 == 1);
	if (cppVar_56704) {
	cppVar_56705 = PC + 1;
	cppVar_56705 = (cppVar_56705 & cppMask_un_16_);
	cppVar_56706 = ROM.rd(cppVar_56705);
	cppVar_56707 = (cppVar_56706 >> 3) & cppMask_un_5_;
	cppVar_56708 = (cppVar_56707 << 3) | 0;
	cppVar_56708 = (cppVar_56708 & cppMask_un_8_);
	cppVar_56700 = cppVar_56708;
	} else {
	cppVar_56709 = PC + 1;
	cppVar_56709 = (cppVar_56709 & cppMask_un_16_);
	cppVar_56710 = ROM.rd(cppVar_56709);
	cppVar_56711 = (cppVar_56710 >> 3) & cppMask_un_5_;
	cppVar_56712 = (cppVar_56711 & cppMask_un_5_);
	cppVar_56713 = cppVar_56712 + 32;
	cppVar_56713 = (cppVar_56713 & cppMask_un_8_);
	cppVar_56700 = cppVar_56713;
	}
	cppVar_56715 = (cppVar_56700 == 136);
	if (cppVar_56715) {
	cppVar_56699 = TCON;
	} else {
	cppVar_56718 = PC + 1;
	cppVar_56718 = (cppVar_56718 & cppMask_un_16_);
	cppVar_56719 = ROM.rd(cppVar_56718);
	cppVar_56720 = (cppVar_56719 >> 7) & cppMask_un_1_;
	cppVar_56721 = (cppVar_56720 == 1);
	if (cppVar_56721) {
	cppVar_56722 = PC + 1;
	cppVar_56722 = (cppVar_56722 & cppMask_un_16_);
	cppVar_56723 = ROM.rd(cppVar_56722);
	cppVar_56724 = (cppVar_56723 >> 3) & cppMask_un_5_;
	cppVar_56725 = (cppVar_56724 << 3) | 0;
	cppVar_56725 = (cppVar_56725 & cppMask_un_8_);
	cppVar_56717 = cppVar_56725;
	} else {
	cppVar_56726 = PC + 1;
	cppVar_56726 = (cppVar_56726 & cppMask_un_16_);
	cppVar_56727 = ROM.rd(cppVar_56726);
	cppVar_56728 = (cppVar_56727 >> 3) & cppMask_un_5_;
	cppVar_56729 = (cppVar_56728 & cppMask_un_5_);
	cppVar_56730 = cppVar_56729 + 32;
	cppVar_56730 = (cppVar_56730 & cppMask_un_8_);
	cppVar_56717 = cppVar_56730;
	}
	cppVar_56732 = (cppVar_56717 == 137);
	if (cppVar_56732) {
	cppVar_56716 = TMOD;
	} else {
	cppVar_56735 = PC + 1;
	cppVar_56735 = (cppVar_56735 & cppMask_un_16_);
	cppVar_56736 = ROM.rd(cppVar_56735);
	cppVar_56737 = (cppVar_56736 >> 7) & cppMask_un_1_;
	cppVar_56738 = (cppVar_56737 == 1);
	if (cppVar_56738) {
	cppVar_56739 = PC + 1;
	cppVar_56739 = (cppVar_56739 & cppMask_un_16_);
	cppVar_56740 = ROM.rd(cppVar_56739);
	cppVar_56741 = (cppVar_56740 >> 3) & cppMask_un_5_;
	cppVar_56742 = (cppVar_56741 << 3) | 0;
	cppVar_56742 = (cppVar_56742 & cppMask_un_8_);
	cppVar_56734 = cppVar_56742;
	} else {
	cppVar_56743 = PC + 1;
	cppVar_56743 = (cppVar_56743 & cppMask_un_16_);
	cppVar_56744 = ROM.rd(cppVar_56743);
	cppVar_56745 = (cppVar_56744 >> 3) & cppMask_un_5_;
	cppVar_56746 = (cppVar_56745 & cppMask_un_5_);
	cppVar_56747 = cppVar_56746 + 32;
	cppVar_56747 = (cppVar_56747 & cppMask_un_8_);
	cppVar_56734 = cppVar_56747;
	}
	cppVar_56749 = (cppVar_56734 == 138);
	if (cppVar_56749) {
	cppVar_56733 = TL0;
	} else {
	cppVar_56752 = PC + 1;
	cppVar_56752 = (cppVar_56752 & cppMask_un_16_);
	cppVar_56753 = ROM.rd(cppVar_56752);
	cppVar_56754 = (cppVar_56753 >> 7) & cppMask_un_1_;
	cppVar_56755 = (cppVar_56754 == 1);
	if (cppVar_56755) {
	cppVar_56756 = PC + 1;
	cppVar_56756 = (cppVar_56756 & cppMask_un_16_);
	cppVar_56757 = ROM.rd(cppVar_56756);
	cppVar_56758 = (cppVar_56757 >> 3) & cppMask_un_5_;
	cppVar_56759 = (cppVar_56758 << 3) | 0;
	cppVar_56759 = (cppVar_56759 & cppMask_un_8_);
	cppVar_56751 = cppVar_56759;
	} else {
	cppVar_56760 = PC + 1;
	cppVar_56760 = (cppVar_56760 & cppMask_un_16_);
	cppVar_56761 = ROM.rd(cppVar_56760);
	cppVar_56762 = (cppVar_56761 >> 3) & cppMask_un_5_;
	cppVar_56763 = (cppVar_56762 & cppMask_un_5_);
	cppVar_56764 = cppVar_56763 + 32;
	cppVar_56764 = (cppVar_56764 & cppMask_un_8_);
	cppVar_56751 = cppVar_56764;
	}
	cppVar_56766 = (cppVar_56751 == 140);
	if (cppVar_56766) {
	cppVar_56750 = TH0;
	} else {
	cppVar_56769 = PC + 1;
	cppVar_56769 = (cppVar_56769 & cppMask_un_16_);
	cppVar_56770 = ROM.rd(cppVar_56769);
	cppVar_56771 = (cppVar_56770 >> 7) & cppMask_un_1_;
	cppVar_56772 = (cppVar_56771 == 1);
	if (cppVar_56772) {
	cppVar_56773 = PC + 1;
	cppVar_56773 = (cppVar_56773 & cppMask_un_16_);
	cppVar_56774 = ROM.rd(cppVar_56773);
	cppVar_56775 = (cppVar_56774 >> 3) & cppMask_un_5_;
	cppVar_56776 = (cppVar_56775 << 3) | 0;
	cppVar_56776 = (cppVar_56776 & cppMask_un_8_);
	cppVar_56768 = cppVar_56776;
	} else {
	cppVar_56777 = PC + 1;
	cppVar_56777 = (cppVar_56777 & cppMask_un_16_);
	cppVar_56778 = ROM.rd(cppVar_56777);
	cppVar_56779 = (cppVar_56778 >> 3) & cppMask_un_5_;
	cppVar_56780 = (cppVar_56779 & cppMask_un_5_);
	cppVar_56781 = cppVar_56780 + 32;
	cppVar_56781 = (cppVar_56781 & cppMask_un_8_);
	cppVar_56768 = cppVar_56781;
	}
	cppVar_56783 = (cppVar_56768 == 139);
	if (cppVar_56783) {
	cppVar_56767 = TL1;
	} else {
	cppVar_56786 = PC + 1;
	cppVar_56786 = (cppVar_56786 & cppMask_un_16_);
	cppVar_56787 = ROM.rd(cppVar_56786);
	cppVar_56788 = (cppVar_56787 >> 7) & cppMask_un_1_;
	cppVar_56789 = (cppVar_56788 == 1);
	if (cppVar_56789) {
	cppVar_56790 = PC + 1;
	cppVar_56790 = (cppVar_56790 & cppMask_un_16_);
	cppVar_56791 = ROM.rd(cppVar_56790);
	cppVar_56792 = (cppVar_56791 >> 3) & cppMask_un_5_;
	cppVar_56793 = (cppVar_56792 << 3) | 0;
	cppVar_56793 = (cppVar_56793 & cppMask_un_8_);
	cppVar_56785 = cppVar_56793;
	} else {
	cppVar_56794 = PC + 1;
	cppVar_56794 = (cppVar_56794 & cppMask_un_16_);
	cppVar_56795 = ROM.rd(cppVar_56794);
	cppVar_56796 = (cppVar_56795 >> 3) & cppMask_un_5_;
	cppVar_56797 = (cppVar_56796 & cppMask_un_5_);
	cppVar_56798 = cppVar_56797 + 32;
	cppVar_56798 = (cppVar_56798 & cppMask_un_8_);
	cppVar_56785 = cppVar_56798;
	}
	cppVar_56800 = (cppVar_56785 == 141);
	if (cppVar_56800) {
	cppVar_56784 = TH1;
	} else {
	cppVar_56803 = PC + 1;
	cppVar_56803 = (cppVar_56803 & cppMask_un_16_);
	cppVar_56804 = ROM.rd(cppVar_56803);
	cppVar_56805 = (cppVar_56804 >> 7) & cppMask_un_1_;
	cppVar_56806 = (cppVar_56805 == 1);
	if (cppVar_56806) {
	cppVar_56807 = PC + 1;
	cppVar_56807 = (cppVar_56807 & cppMask_un_16_);
	cppVar_56808 = ROM.rd(cppVar_56807);
	cppVar_56809 = (cppVar_56808 >> 3) & cppMask_un_5_;
	cppVar_56810 = (cppVar_56809 << 3) | 0;
	cppVar_56810 = (cppVar_56810 & cppMask_un_8_);
	cppVar_56802 = cppVar_56810;
	} else {
	cppVar_56811 = PC + 1;
	cppVar_56811 = (cppVar_56811 & cppMask_un_16_);
	cppVar_56812 = ROM.rd(cppVar_56811);
	cppVar_56813 = (cppVar_56812 >> 3) & cppMask_un_5_;
	cppVar_56814 = (cppVar_56813 & cppMask_un_5_);
	cppVar_56815 = cppVar_56814 + 32;
	cppVar_56815 = (cppVar_56815 & cppMask_un_8_);
	cppVar_56802 = cppVar_56815;
	}
	cppVar_56817 = (cppVar_56802 == 144);
	if (cppVar_56817) {
	cppVar_56801 = P1;
	} else {
	cppVar_56820 = PC + 1;
	cppVar_56820 = (cppVar_56820 & cppMask_un_16_);
	cppVar_56821 = ROM.rd(cppVar_56820);
	cppVar_56822 = (cppVar_56821 >> 7) & cppMask_un_1_;
	cppVar_56823 = (cppVar_56822 == 1);
	if (cppVar_56823) {
	cppVar_56824 = PC + 1;
	cppVar_56824 = (cppVar_56824 & cppMask_un_16_);
	cppVar_56825 = ROM.rd(cppVar_56824);
	cppVar_56826 = (cppVar_56825 >> 3) & cppMask_un_5_;
	cppVar_56827 = (cppVar_56826 << 3) | 0;
	cppVar_56827 = (cppVar_56827 & cppMask_un_8_);
	cppVar_56819 = cppVar_56827;
	} else {
	cppVar_56828 = PC + 1;
	cppVar_56828 = (cppVar_56828 & cppMask_un_16_);
	cppVar_56829 = ROM.rd(cppVar_56828);
	cppVar_56830 = (cppVar_56829 >> 3) & cppMask_un_5_;
	cppVar_56831 = (cppVar_56830 & cppMask_un_5_);
	cppVar_56832 = cppVar_56831 + 32;
	cppVar_56832 = (cppVar_56832 & cppMask_un_8_);
	cppVar_56819 = cppVar_56832;
	}
	cppVar_56834 = (cppVar_56819 == 152);
	if (cppVar_56834) {
	cppVar_56818 = SCON;
	} else {
	cppVar_56837 = PC + 1;
	cppVar_56837 = (cppVar_56837 & cppMask_un_16_);
	cppVar_56838 = ROM.rd(cppVar_56837);
	cppVar_56839 = (cppVar_56838 >> 7) & cppMask_un_1_;
	cppVar_56840 = (cppVar_56839 == 1);
	if (cppVar_56840) {
	cppVar_56841 = PC + 1;
	cppVar_56841 = (cppVar_56841 & cppMask_un_16_);
	cppVar_56842 = ROM.rd(cppVar_56841);
	cppVar_56843 = (cppVar_56842 >> 3) & cppMask_un_5_;
	cppVar_56844 = (cppVar_56843 << 3) | 0;
	cppVar_56844 = (cppVar_56844 & cppMask_un_8_);
	cppVar_56836 = cppVar_56844;
	} else {
	cppVar_56845 = PC + 1;
	cppVar_56845 = (cppVar_56845 & cppMask_un_16_);
	cppVar_56846 = ROM.rd(cppVar_56845);
	cppVar_56847 = (cppVar_56846 >> 3) & cppMask_un_5_;
	cppVar_56848 = (cppVar_56847 & cppMask_un_5_);
	cppVar_56849 = cppVar_56848 + 32;
	cppVar_56849 = (cppVar_56849 & cppMask_un_8_);
	cppVar_56836 = cppVar_56849;
	}
	cppVar_56851 = (cppVar_56836 == 153);
	if (cppVar_56851) {
	cppVar_56835 = SBUF;
	} else {
	cppVar_56854 = PC + 1;
	cppVar_56854 = (cppVar_56854 & cppMask_un_16_);
	cppVar_56855 = ROM.rd(cppVar_56854);
	cppVar_56856 = (cppVar_56855 >> 7) & cppMask_un_1_;
	cppVar_56857 = (cppVar_56856 == 1);
	if (cppVar_56857) {
	cppVar_56858 = PC + 1;
	cppVar_56858 = (cppVar_56858 & cppMask_un_16_);
	cppVar_56859 = ROM.rd(cppVar_56858);
	cppVar_56860 = (cppVar_56859 >> 3) & cppMask_un_5_;
	cppVar_56861 = (cppVar_56860 << 3) | 0;
	cppVar_56861 = (cppVar_56861 & cppMask_un_8_);
	cppVar_56853 = cppVar_56861;
	} else {
	cppVar_56862 = PC + 1;
	cppVar_56862 = (cppVar_56862 & cppMask_un_16_);
	cppVar_56863 = ROM.rd(cppVar_56862);
	cppVar_56864 = (cppVar_56863 >> 3) & cppMask_un_5_;
	cppVar_56865 = (cppVar_56864 & cppMask_un_5_);
	cppVar_56866 = cppVar_56865 + 32;
	cppVar_56866 = (cppVar_56866 & cppMask_un_8_);
	cppVar_56853 = cppVar_56866;
	}
	cppVar_56868 = (cppVar_56853 == 160);
	if (cppVar_56868) {
	cppVar_56852 = P2;
	} else {
	cppVar_56871 = PC + 1;
	cppVar_56871 = (cppVar_56871 & cppMask_un_16_);
	cppVar_56872 = ROM.rd(cppVar_56871);
	cppVar_56873 = (cppVar_56872 >> 7) & cppMask_un_1_;
	cppVar_56874 = (cppVar_56873 == 1);
	if (cppVar_56874) {
	cppVar_56875 = PC + 1;
	cppVar_56875 = (cppVar_56875 & cppMask_un_16_);
	cppVar_56876 = ROM.rd(cppVar_56875);
	cppVar_56877 = (cppVar_56876 >> 3) & cppMask_un_5_;
	cppVar_56878 = (cppVar_56877 << 3) | 0;
	cppVar_56878 = (cppVar_56878 & cppMask_un_8_);
	cppVar_56870 = cppVar_56878;
	} else {
	cppVar_56879 = PC + 1;
	cppVar_56879 = (cppVar_56879 & cppMask_un_16_);
	cppVar_56880 = ROM.rd(cppVar_56879);
	cppVar_56881 = (cppVar_56880 >> 3) & cppMask_un_5_;
	cppVar_56882 = (cppVar_56881 & cppMask_un_5_);
	cppVar_56883 = cppVar_56882 + 32;
	cppVar_56883 = (cppVar_56883 & cppMask_un_8_);
	cppVar_56870 = cppVar_56883;
	}
	cppVar_56885 = (cppVar_56870 == 168);
	if (cppVar_56885) {
	cppVar_56869 = IE;
	} else {
	cppVar_56888 = PC + 1;
	cppVar_56888 = (cppVar_56888 & cppMask_un_16_);
	cppVar_56889 = ROM.rd(cppVar_56888);
	cppVar_56890 = (cppVar_56889 >> 7) & cppMask_un_1_;
	cppVar_56891 = (cppVar_56890 == 1);
	if (cppVar_56891) {
	cppVar_56892 = PC + 1;
	cppVar_56892 = (cppVar_56892 & cppMask_un_16_);
	cppVar_56893 = ROM.rd(cppVar_56892);
	cppVar_56894 = (cppVar_56893 >> 3) & cppMask_un_5_;
	cppVar_56895 = (cppVar_56894 << 3) | 0;
	cppVar_56895 = (cppVar_56895 & cppMask_un_8_);
	cppVar_56887 = cppVar_56895;
	} else {
	cppVar_56896 = PC + 1;
	cppVar_56896 = (cppVar_56896 & cppMask_un_16_);
	cppVar_56897 = ROM.rd(cppVar_56896);
	cppVar_56898 = (cppVar_56897 >> 3) & cppMask_un_5_;
	cppVar_56899 = (cppVar_56898 & cppMask_un_5_);
	cppVar_56900 = cppVar_56899 + 32;
	cppVar_56900 = (cppVar_56900 & cppMask_un_8_);
	cppVar_56887 = cppVar_56900;
	}
	cppVar_56902 = (cppVar_56887 == 176);
	if (cppVar_56902) {
	cppVar_56886 = P3;
	} else {
	cppVar_56905 = PC + 1;
	cppVar_56905 = (cppVar_56905 & cppMask_un_16_);
	cppVar_56906 = ROM.rd(cppVar_56905);
	cppVar_56907 = (cppVar_56906 >> 7) & cppMask_un_1_;
	cppVar_56908 = (cppVar_56907 == 1);
	if (cppVar_56908) {
	cppVar_56909 = PC + 1;
	cppVar_56909 = (cppVar_56909 & cppMask_un_16_);
	cppVar_56910 = ROM.rd(cppVar_56909);
	cppVar_56911 = (cppVar_56910 >> 3) & cppMask_un_5_;
	cppVar_56912 = (cppVar_56911 << 3) | 0;
	cppVar_56912 = (cppVar_56912 & cppMask_un_8_);
	cppVar_56904 = cppVar_56912;
	} else {
	cppVar_56913 = PC + 1;
	cppVar_56913 = (cppVar_56913 & cppMask_un_16_);
	cppVar_56914 = ROM.rd(cppVar_56913);
	cppVar_56915 = (cppVar_56914 >> 3) & cppMask_un_5_;
	cppVar_56916 = (cppVar_56915 & cppMask_un_5_);
	cppVar_56917 = cppVar_56916 + 32;
	cppVar_56917 = (cppVar_56917 & cppMask_un_8_);
	cppVar_56904 = cppVar_56917;
	}
	cppVar_56919 = (cppVar_56904 == 184);
	if (cppVar_56919) {
	cppVar_56903 = IP;
	} else {
	cppVar_56922 = PC + 1;
	cppVar_56922 = (cppVar_56922 & cppMask_un_16_);
	cppVar_56923 = ROM.rd(cppVar_56922);
	cppVar_56924 = (cppVar_56923 >> 7) & cppMask_un_1_;
	cppVar_56925 = (cppVar_56924 == 1);
	if (cppVar_56925) {
	cppVar_56926 = PC + 1;
	cppVar_56926 = (cppVar_56926 & cppMask_un_16_);
	cppVar_56927 = ROM.rd(cppVar_56926);
	cppVar_56928 = (cppVar_56927 >> 3) & cppMask_un_5_;
	cppVar_56929 = (cppVar_56928 << 3) | 0;
	cppVar_56929 = (cppVar_56929 & cppMask_un_8_);
	cppVar_56921 = cppVar_56929;
	} else {
	cppVar_56930 = PC + 1;
	cppVar_56930 = (cppVar_56930 & cppMask_un_16_);
	cppVar_56931 = ROM.rd(cppVar_56930);
	cppVar_56932 = (cppVar_56931 >> 3) & cppMask_un_5_;
	cppVar_56933 = (cppVar_56932 & cppMask_un_5_);
	cppVar_56934 = cppVar_56933 + 32;
	cppVar_56934 = (cppVar_56934 & cppMask_un_8_);
	cppVar_56921 = cppVar_56934;
	}
	cppVar_56936 = (cppVar_56921 == 208);
	if (cppVar_56936) {
	cppVar_56920 = PSW;
	} else {
	cppVar_56939 = PC + 1;
	cppVar_56939 = (cppVar_56939 & cppMask_un_16_);
	cppVar_56940 = ROM.rd(cppVar_56939);
	cppVar_56941 = (cppVar_56940 >> 7) & cppMask_un_1_;
	cppVar_56942 = (cppVar_56941 == 1);
	if (cppVar_56942) {
	cppVar_56943 = PC + 1;
	cppVar_56943 = (cppVar_56943 & cppMask_un_16_);
	cppVar_56944 = ROM.rd(cppVar_56943);
	cppVar_56945 = (cppVar_56944 >> 3) & cppMask_un_5_;
	cppVar_56946 = (cppVar_56945 << 3) | 0;
	cppVar_56946 = (cppVar_56946 & cppMask_un_8_);
	cppVar_56938 = cppVar_56946;
	} else {
	cppVar_56947 = PC + 1;
	cppVar_56947 = (cppVar_56947 & cppMask_un_16_);
	cppVar_56948 = ROM.rd(cppVar_56947);
	cppVar_56949 = (cppVar_56948 >> 3) & cppMask_un_5_;
	cppVar_56950 = (cppVar_56949 & cppMask_un_5_);
	cppVar_56951 = cppVar_56950 + 32;
	cppVar_56951 = (cppVar_56951 & cppMask_un_8_);
	cppVar_56938 = cppVar_56951;
	}
	cppVar_56953 = (cppVar_56938 == 224);
	if (cppVar_56953) {
	cppVar_56937 = ACC;
	} else {
	cppVar_56956 = PC + 1;
	cppVar_56956 = (cppVar_56956 & cppMask_un_16_);
	cppVar_56957 = ROM.rd(cppVar_56956);
	cppVar_56958 = (cppVar_56957 >> 7) & cppMask_un_1_;
	cppVar_56959 = (cppVar_56958 == 1);
	if (cppVar_56959) {
	cppVar_56960 = PC + 1;
	cppVar_56960 = (cppVar_56960 & cppMask_un_16_);
	cppVar_56961 = ROM.rd(cppVar_56960);
	cppVar_56962 = (cppVar_56961 >> 3) & cppMask_un_5_;
	cppVar_56963 = (cppVar_56962 << 3) | 0;
	cppVar_56963 = (cppVar_56963 & cppMask_un_8_);
	cppVar_56955 = cppVar_56963;
	} else {
	cppVar_56964 = PC + 1;
	cppVar_56964 = (cppVar_56964 & cppMask_un_16_);
	cppVar_56965 = ROM.rd(cppVar_56964);
	cppVar_56966 = (cppVar_56965 >> 3) & cppMask_un_5_;
	cppVar_56967 = (cppVar_56966 & cppMask_un_5_);
	cppVar_56968 = cppVar_56967 + 32;
	cppVar_56968 = (cppVar_56968 & cppMask_un_8_);
	cppVar_56955 = cppVar_56968;
	}
	cppVar_56970 = (cppVar_56955 == 240);
	if (cppVar_56970) {
	cppVar_56954 = B;
	} else {
	cppVar_56954 = 0;
	}
	cppVar_56937 = cppVar_56954;
	}
	cppVar_56920 = cppVar_56937;
	}
	cppVar_56903 = cppVar_56920;
	}
	cppVar_56886 = cppVar_56903;
	}
	cppVar_56869 = cppVar_56886;
	}
	cppVar_56852 = cppVar_56869;
	}
	cppVar_56835 = cppVar_56852;
	}
	cppVar_56818 = cppVar_56835;
	}
	cppVar_56801 = cppVar_56818;
	}
	cppVar_56784 = cppVar_56801;
	}
	cppVar_56767 = cppVar_56784;
	}
	cppVar_56750 = cppVar_56767;
	}
	cppVar_56733 = cppVar_56750;
	}
	cppVar_56716 = cppVar_56733;
	}
	cppVar_56699 = cppVar_56716;
	}
	cppVar_56682 = cppVar_56699;
	}
	cppVar_56665 = cppVar_56682;
	}
	cppVar_56648 = cppVar_56665;
	}
	cppVar_56631 = cppVar_56648;
	}
	cppVar_56614 = cppVar_56631;
	}
	cppVar_56581 = cppVar_56614;
	}
	cppVar_56972 = cppVar_56580 & cppVar_56581;
	cppVar_56974 = 0;
	cppVar_56975 = PC + 1;
	cppVar_56975 = (cppVar_56975 & cppMask_un_16_);
	cppVar_56976 = ROM.rd(cppVar_56975);
	cppVar_56977 = (cppVar_56976 >> 0) & cppMask_un_3_;
	cppVar_56978 = (cppVar_56977 & cppMask_un_3_);
	cppVar_56979 = cppVar_56974 << static_cast<unsigned>(cppVar_56978);
	cppVar_56979 = (cppVar_56979 & cppMask_un_8_);
	cppVar_56980 = cppVar_56972 | cppVar_56979;
	cppVar_56553 = cppVar_56980;
	} else {
	cppVar_56553 = PSW;
	}
	cppVar_56545 = cppVar_56553;
	} else {
	cppVar_56982 = ROM.rd(PC);
	cppVar_56984 = (cppVar_56982 == 5);
	if (cppVar_56984) {
	cppVar_56987 = PC + 1;
	cppVar_56987 = (cppVar_56987 & cppMask_un_16_);
	cppVar_56988 = ROM.rd(cppVar_56987);
	cppVar_56990 = (cppVar_56988 == 208);
	if (cppVar_56990) {
	cppVar_56992 = PC + 1;
	cppVar_56992 = (cppVar_56992 & cppMask_un_16_);
	cppVar_56993 = ROM.rd(cppVar_56992);
	cppVar_56994 = (cppVar_56993 >> 7) & cppMask_un_1_;
	cppVar_56996 = (cppVar_56994 == 0);
	if (cppVar_56996) {
	cppVar_56997 = PC + 1;
	cppVar_56997 = (cppVar_56997 & cppMask_un_16_);
	cppVar_56998 = ROM.rd(cppVar_56997);
	cppVar_56999 = IRAM.rd(cppVar_56998);
	cppVar_56991 = cppVar_56999;
	} else {
	cppVar_57001 = PC + 1;
	cppVar_57001 = (cppVar_57001 & cppMask_un_16_);
	cppVar_57002 = ROM.rd(cppVar_57001);
	cppVar_57004 = (cppVar_57002 == 128);
	if (cppVar_57004) {
	cppVar_57000 = P0;
	} else {
	cppVar_57006 = PC + 1;
	cppVar_57006 = (cppVar_57006 & cppMask_un_16_);
	cppVar_57007 = ROM.rd(cppVar_57006);
	cppVar_57009 = (cppVar_57007 == 129);
	if (cppVar_57009) {
	cppVar_57005 = SP;
	} else {
	cppVar_57011 = PC + 1;
	cppVar_57011 = (cppVar_57011 & cppMask_un_16_);
	cppVar_57012 = ROM.rd(cppVar_57011);
	cppVar_57014 = (cppVar_57012 == 130);
	if (cppVar_57014) {
	cppVar_57010 = DPL;
	} else {
	cppVar_57016 = PC + 1;
	cppVar_57016 = (cppVar_57016 & cppMask_un_16_);
	cppVar_57017 = ROM.rd(cppVar_57016);
	cppVar_57019 = (cppVar_57017 == 131);
	if (cppVar_57019) {
	cppVar_57015 = DPH;
	} else {
	cppVar_57021 = PC + 1;
	cppVar_57021 = (cppVar_57021 & cppMask_un_16_);
	cppVar_57022 = ROM.rd(cppVar_57021);
	cppVar_57024 = (cppVar_57022 == 135);
	if (cppVar_57024) {
	cppVar_57020 = PCON;
	} else {
	cppVar_57026 = PC + 1;
	cppVar_57026 = (cppVar_57026 & cppMask_un_16_);
	cppVar_57027 = ROM.rd(cppVar_57026);
	cppVar_57029 = (cppVar_57027 == 136);
	if (cppVar_57029) {
	cppVar_57025 = TCON;
	} else {
	cppVar_57031 = PC + 1;
	cppVar_57031 = (cppVar_57031 & cppMask_un_16_);
	cppVar_57032 = ROM.rd(cppVar_57031);
	cppVar_57034 = (cppVar_57032 == 137);
	if (cppVar_57034) {
	cppVar_57030 = TMOD;
	} else {
	cppVar_57036 = PC + 1;
	cppVar_57036 = (cppVar_57036 & cppMask_un_16_);
	cppVar_57037 = ROM.rd(cppVar_57036);
	cppVar_57039 = (cppVar_57037 == 138);
	if (cppVar_57039) {
	cppVar_57035 = TL0;
	} else {
	cppVar_57041 = PC + 1;
	cppVar_57041 = (cppVar_57041 & cppMask_un_16_);
	cppVar_57042 = ROM.rd(cppVar_57041);
	cppVar_57044 = (cppVar_57042 == 140);
	if (cppVar_57044) {
	cppVar_57040 = TH0;
	} else {
	cppVar_57046 = PC + 1;
	cppVar_57046 = (cppVar_57046 & cppMask_un_16_);
	cppVar_57047 = ROM.rd(cppVar_57046);
	cppVar_57049 = (cppVar_57047 == 139);
	if (cppVar_57049) {
	cppVar_57045 = TL1;
	} else {
	cppVar_57051 = PC + 1;
	cppVar_57051 = (cppVar_57051 & cppMask_un_16_);
	cppVar_57052 = ROM.rd(cppVar_57051);
	cppVar_57054 = (cppVar_57052 == 141);
	if (cppVar_57054) {
	cppVar_57050 = TH1;
	} else {
	cppVar_57056 = PC + 1;
	cppVar_57056 = (cppVar_57056 & cppMask_un_16_);
	cppVar_57057 = ROM.rd(cppVar_57056);
	cppVar_57059 = (cppVar_57057 == 144);
	if (cppVar_57059) {
	cppVar_57055 = P1;
	} else {
	cppVar_57061 = PC + 1;
	cppVar_57061 = (cppVar_57061 & cppMask_un_16_);
	cppVar_57062 = ROM.rd(cppVar_57061);
	cppVar_57064 = (cppVar_57062 == 152);
	if (cppVar_57064) {
	cppVar_57060 = SCON;
	} else {
	cppVar_57066 = PC + 1;
	cppVar_57066 = (cppVar_57066 & cppMask_un_16_);
	cppVar_57067 = ROM.rd(cppVar_57066);
	cppVar_57069 = (cppVar_57067 == 153);
	if (cppVar_57069) {
	cppVar_57065 = SBUF;
	} else {
	cppVar_57071 = PC + 1;
	cppVar_57071 = (cppVar_57071 & cppMask_un_16_);
	cppVar_57072 = ROM.rd(cppVar_57071);
	cppVar_57074 = (cppVar_57072 == 160);
	if (cppVar_57074) {
	cppVar_57070 = P2;
	} else {
	cppVar_57076 = PC + 1;
	cppVar_57076 = (cppVar_57076 & cppMask_un_16_);
	cppVar_57077 = ROM.rd(cppVar_57076);
	cppVar_57079 = (cppVar_57077 == 168);
	if (cppVar_57079) {
	cppVar_57075 = IE;
	} else {
	cppVar_57081 = PC + 1;
	cppVar_57081 = (cppVar_57081 & cppMask_un_16_);
	cppVar_57082 = ROM.rd(cppVar_57081);
	cppVar_57084 = (cppVar_57082 == 176);
	if (cppVar_57084) {
	cppVar_57080 = P3;
	} else {
	cppVar_57086 = PC + 1;
	cppVar_57086 = (cppVar_57086 & cppMask_un_16_);
	cppVar_57087 = ROM.rd(cppVar_57086);
	cppVar_57089 = (cppVar_57087 == 184);
	if (cppVar_57089) {
	cppVar_57085 = IP;
	} else {
	cppVar_57091 = PC + 1;
	cppVar_57091 = (cppVar_57091 & cppMask_un_16_);
	cppVar_57092 = ROM.rd(cppVar_57091);
	cppVar_57094 = (cppVar_57092 == 208);
	if (cppVar_57094) {
	cppVar_57090 = PSW;
	} else {
	cppVar_57096 = PC + 1;
	cppVar_57096 = (cppVar_57096 & cppMask_un_16_);
	cppVar_57097 = ROM.rd(cppVar_57096);
	cppVar_57099 = (cppVar_57097 == 224);
	if (cppVar_57099) {
	cppVar_57095 = ACC;
	} else {
	cppVar_57101 = PC + 1;
	cppVar_57101 = (cppVar_57101 & cppMask_un_16_);
	cppVar_57102 = ROM.rd(cppVar_57101);
	cppVar_57104 = (cppVar_57102 == 240);
	if (cppVar_57104) {
	cppVar_57100 = B;
	} else {
	cppVar_57100 = 0;
	}
	cppVar_57095 = cppVar_57100;
	}
	cppVar_57090 = cppVar_57095;
	}
	cppVar_57085 = cppVar_57090;
	}
	cppVar_57080 = cppVar_57085;
	}
	cppVar_57075 = cppVar_57080;
	}
	cppVar_57070 = cppVar_57075;
	}
	cppVar_57065 = cppVar_57070;
	}
	cppVar_57060 = cppVar_57065;
	}
	cppVar_57055 = cppVar_57060;
	}
	cppVar_57050 = cppVar_57055;
	}
	cppVar_57045 = cppVar_57050;
	}
	cppVar_57040 = cppVar_57045;
	}
	cppVar_57035 = cppVar_57040;
	}
	cppVar_57030 = cppVar_57035;
	}
	cppVar_57025 = cppVar_57030;
	}
	cppVar_57020 = cppVar_57025;
	}
	cppVar_57015 = cppVar_57020;
	}
	cppVar_57010 = cppVar_57015;
	}
	cppVar_57005 = cppVar_57010;
	}
	cppVar_57000 = cppVar_57005;
	}
	cppVar_56991 = cppVar_57000;
	}
	cppVar_57107 = cppVar_56991 + 1;
	cppVar_57107 = (cppVar_57107 & cppMask_un_8_);
	cppVar_56985 = cppVar_57107;
	} else {
	cppVar_56985 = PSW;
	}
	cppVar_56981 = cppVar_56985;
	} else {
	cppVar_56981 = PSW;
	}
	cppVar_56545 = cppVar_56981;
	}
	cppVar_56532 = cppVar_56545;
	}
	cppVar_56401 = cppVar_56532;
	}
	cppVar_56351 = cppVar_56401;
	}
	cppVar_55918 = cppVar_56351;
	}
	cppVar_55855 = cppVar_55918;
	}
	cppVar_55792 = cppVar_55855;
	}
	cppVar_55733 = cppVar_55792;
	}
	cppVar_55674 = cppVar_55733;
	}
	cppVar_55615 = cppVar_55674;
	}
	cppVar_55556 = cppVar_55615;
	}
	cppVar_55497 = cppVar_55556;
	}
	cppVar_55438 = cppVar_55497;
	}
	cppVar_55379 = cppVar_55438;
	}
	cppVar_55320 = cppVar_55379;
	}
	cppVar_55307 = cppVar_55320;
	}
	cppVar_55254 = cppVar_55307;
	}
	cppVar_54818 = cppVar_55254;
	}
	cppVar_54752 = cppVar_54818;
	}
	cppVar_54686 = cppVar_54752;
	}
	cppVar_54624 = cppVar_54686;
	}
	cppVar_54562 = cppVar_54624;
	}
	cppVar_54500 = cppVar_54562;
	}
	cppVar_54438 = cppVar_54500;
	}
	cppVar_54376 = cppVar_54438;
	}
	cppVar_54314 = cppVar_54376;
	}
	cppVar_54252 = cppVar_54314;
	}
	cppVar_54190 = cppVar_54252;
	}
	cppVar_54064 = cppVar_54190;
	}
	cppVar_53935 = cppVar_54064;
	}
	cppVar_53809 = cppVar_53935;
	}
	cppVar_53680 = cppVar_53809;
	}
	cppVar_53554 = cppVar_53680;
	}
	cppVar_53425 = cppVar_53554;
	}
	cppVar_53018 = cppVar_53425;
	}
	cppVar_53005 = cppVar_53018;
	}
	cppVar_52598 = cppVar_53005;
	}
	cppVar_52583 = cppVar_52598;
	}
	cppVar_52457 = cppVar_52583;
	}
	cppVar_52440 = cppVar_52457;
	}
	cppVar_52423 = cppVar_52440;
	}
	cppVar_52273 = cppVar_52423;
	}
	cppVar_52123 = cppVar_52273;
	}
	cppVar_51973 = cppVar_52123;
	}
	cppVar_51823 = cppVar_51973;
	}
	cppVar_51673 = cppVar_51823;
	}
	cppVar_51523 = cppVar_51673;
	}
	cppVar_51373 = cppVar_51523;
	}
	cppVar_51223 = cppVar_51373;
	}
	cppVar_50791 = cppVar_51223;
	}
	cppVar_50736 = cppVar_50791;
	}
	cppVar_50298 = cppVar_50736;
	}
	cppVar_50228 = cppVar_50298;
	}
	cppVar_50158 = cppVar_50228;
	}
	cppVar_50094 = cppVar_50158;
	}
	cppVar_50030 = cppVar_50094;
	}
	cppVar_49966 = cppVar_50030;
	}
	cppVar_49902 = cppVar_49966;
	}
	cppVar_49838 = cppVar_49902;
	}
	cppVar_49774 = cppVar_49838;
	}
	cppVar_49710 = cppVar_49774;
	}
	cppVar_49646 = cppVar_49710;
	}
	cppVar_49238 = cppVar_49646;
	}
	cppVar_48833 = cppVar_49238;
	}
	cppVar_48814 = cppVar_48833;
	}
	cppVar_48406 = cppVar_48814;
	}
	cppVar_47576 = cppVar_48406;
	}
	cppVar_47568 = cppVar_47576;
	}
	cppVar_47555 = cppVar_47568;
	}
	cppVar_47429 = cppVar_47555;
	}
	cppVar_47409 = cppVar_47429;
	}
	cppVar_47389 = cppVar_47409;
	}
	cppVar_47370 = cppVar_47389;
	}
	cppVar_47351 = cppVar_47370;
	}
	cppVar_47332 = cppVar_47351;
	}
	cppVar_47313 = cppVar_47332;
	}
	cppVar_47294 = cppVar_47313;
	}
	cppVar_47275 = cppVar_47294;
	}
	cppVar_47256 = cppVar_47275;
	}
	cppVar_47237 = cppVar_47256;
	}
	cppVar_47230 = cppVar_47237;
	}
	cppVar_47216 = cppVar_47230;
	}
	cppVar_47205 = cppVar_47216;
	}
	cppVar_46773 = cppVar_47205;
	}
	cppVar_46766 = cppVar_46773;
	}
	cppVar_46695 = cppVar_46766;
	}
	return cppVar_46695;
}
