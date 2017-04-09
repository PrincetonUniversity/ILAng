#include "common.hpp"
#include "model_oc8051_class.hpp"

BIT_VEC model_oc8051::cppUpdateFun_TCON()
{
	BIT_VEC cppVar_67875;
	BIT_VEC cppVar_67876;
	bool cppVar_67877;
	BIT_VEC cppVar_67880;
	BIT_VEC cppVar_67881;
	BIT_VEC cppVar_67882;
	BIT_VEC cppVar_67883;
	BIT_VEC cppVar_67884;
	bool cppVar_67885;
	BIT_VEC cppVar_67886;
	BIT_VEC cppVar_67887;
	BIT_VEC cppVar_67888;
	BIT_VEC cppVar_67889;
	BIT_VEC cppVar_67890;
	BIT_VEC cppVar_67891;
	BIT_VEC cppVar_67892;
	BIT_VEC cppVar_67893;
	BIT_VEC cppVar_67894;
	BIT_VEC cppVar_67895;
	BIT_VEC cppVar_67896;
	BIT_VEC cppVar_67879;
	BIT_VEC cppVar_67897;
	bool cppVar_67898;
	BIT_VEC cppVar_67899;
	BIT_VEC cppVar_67900;
	BIT_VEC cppVar_67901;
	BIT_VEC cppVar_67902;
	BIT_VEC cppVar_67903;
	BIT_VEC cppVar_67904;
	BIT_VEC cppVar_67905;
	BIT_VEC cppVar_67908;
	BIT_VEC cppVar_67909;
	BIT_VEC cppVar_67910;
	bool cppVar_67911;
	BIT_VEC cppVar_67912;
	BIT_VEC cppVar_67913;
	BIT_VEC cppVar_67914;
	BIT_VEC cppVar_67915;
	BIT_VEC cppVar_67916;
	BIT_VEC cppVar_67917;
	BIT_VEC cppVar_67918;
	BIT_VEC cppVar_67919;
	BIT_VEC cppVar_67920;
	BIT_VEC cppVar_67907;
	BIT_VEC cppVar_67921;
	BIT_VEC cppVar_67922;
	bool cppVar_67923;
	BIT_VEC cppVar_67925;
	BIT_VEC cppVar_67926;
	BIT_VEC cppVar_67927;
	bool cppVar_67928;
	BIT_VEC cppVar_67929;
	BIT_VEC cppVar_67930;
	BIT_VEC cppVar_67931;
	BIT_VEC cppVar_67932;
	BIT_VEC cppVar_67933;
	BIT_VEC cppVar_67934;
	BIT_VEC cppVar_67935;
	BIT_VEC cppVar_67936;
	BIT_VEC cppVar_67937;
	BIT_VEC cppVar_67924;
	BIT_VEC cppVar_67938;
	BIT_VEC cppVar_67941;
	BIT_VEC cppVar_67942;
	BIT_VEC cppVar_67943;
	bool cppVar_67944;
	BIT_VEC cppVar_67945;
	BIT_VEC cppVar_67946;
	BIT_VEC cppVar_67947;
	BIT_VEC cppVar_67948;
	BIT_VEC cppVar_67949;
	BIT_VEC cppVar_67950;
	BIT_VEC cppVar_67951;
	BIT_VEC cppVar_67952;
	BIT_VEC cppVar_67953;
	BIT_VEC cppVar_67940;
	BIT_VEC cppVar_67954;
	bool cppVar_67955;
	BIT_VEC cppVar_67958;
	BIT_VEC cppVar_67959;
	BIT_VEC cppVar_67960;
	bool cppVar_67961;
	BIT_VEC cppVar_67962;
	BIT_VEC cppVar_67963;
	BIT_VEC cppVar_67964;
	BIT_VEC cppVar_67965;
	BIT_VEC cppVar_67966;
	BIT_VEC cppVar_67967;
	BIT_VEC cppVar_67968;
	BIT_VEC cppVar_67969;
	BIT_VEC cppVar_67970;
	BIT_VEC cppVar_67957;
	BIT_VEC cppVar_67971;
	bool cppVar_67972;
	BIT_VEC cppVar_67975;
	BIT_VEC cppVar_67976;
	BIT_VEC cppVar_67977;
	bool cppVar_67978;
	BIT_VEC cppVar_67979;
	BIT_VEC cppVar_67980;
	BIT_VEC cppVar_67981;
	BIT_VEC cppVar_67982;
	BIT_VEC cppVar_67983;
	BIT_VEC cppVar_67984;
	BIT_VEC cppVar_67985;
	BIT_VEC cppVar_67986;
	BIT_VEC cppVar_67987;
	BIT_VEC cppVar_67974;
	BIT_VEC cppVar_67988;
	bool cppVar_67989;
	BIT_VEC cppVar_67992;
	BIT_VEC cppVar_67993;
	BIT_VEC cppVar_67994;
	bool cppVar_67995;
	BIT_VEC cppVar_67996;
	BIT_VEC cppVar_67997;
	BIT_VEC cppVar_67998;
	BIT_VEC cppVar_67999;
	BIT_VEC cppVar_68000;
	BIT_VEC cppVar_68001;
	BIT_VEC cppVar_68002;
	BIT_VEC cppVar_68003;
	BIT_VEC cppVar_68004;
	BIT_VEC cppVar_67991;
	BIT_VEC cppVar_68005;
	bool cppVar_68006;
	BIT_VEC cppVar_68009;
	BIT_VEC cppVar_68010;
	BIT_VEC cppVar_68011;
	bool cppVar_68012;
	BIT_VEC cppVar_68013;
	BIT_VEC cppVar_68014;
	BIT_VEC cppVar_68015;
	BIT_VEC cppVar_68016;
	BIT_VEC cppVar_68017;
	BIT_VEC cppVar_68018;
	BIT_VEC cppVar_68019;
	BIT_VEC cppVar_68020;
	BIT_VEC cppVar_68021;
	BIT_VEC cppVar_68008;
	BIT_VEC cppVar_68022;
	bool cppVar_68023;
	BIT_VEC cppVar_68026;
	BIT_VEC cppVar_68027;
	BIT_VEC cppVar_68028;
	bool cppVar_68029;
	BIT_VEC cppVar_68030;
	BIT_VEC cppVar_68031;
	BIT_VEC cppVar_68032;
	BIT_VEC cppVar_68033;
	BIT_VEC cppVar_68034;
	BIT_VEC cppVar_68035;
	BIT_VEC cppVar_68036;
	BIT_VEC cppVar_68037;
	BIT_VEC cppVar_68038;
	BIT_VEC cppVar_68025;
	BIT_VEC cppVar_68039;
	bool cppVar_68040;
	BIT_VEC cppVar_68043;
	BIT_VEC cppVar_68044;
	BIT_VEC cppVar_68045;
	bool cppVar_68046;
	BIT_VEC cppVar_68047;
	BIT_VEC cppVar_68048;
	BIT_VEC cppVar_68049;
	BIT_VEC cppVar_68050;
	BIT_VEC cppVar_68051;
	BIT_VEC cppVar_68052;
	BIT_VEC cppVar_68053;
	BIT_VEC cppVar_68054;
	BIT_VEC cppVar_68055;
	BIT_VEC cppVar_68042;
	BIT_VEC cppVar_68056;
	bool cppVar_68057;
	BIT_VEC cppVar_68060;
	BIT_VEC cppVar_68061;
	BIT_VEC cppVar_68062;
	bool cppVar_68063;
	BIT_VEC cppVar_68064;
	BIT_VEC cppVar_68065;
	BIT_VEC cppVar_68066;
	BIT_VEC cppVar_68067;
	BIT_VEC cppVar_68068;
	BIT_VEC cppVar_68069;
	BIT_VEC cppVar_68070;
	BIT_VEC cppVar_68071;
	BIT_VEC cppVar_68072;
	BIT_VEC cppVar_68059;
	BIT_VEC cppVar_68073;
	bool cppVar_68074;
	BIT_VEC cppVar_68077;
	BIT_VEC cppVar_68078;
	BIT_VEC cppVar_68079;
	bool cppVar_68080;
	BIT_VEC cppVar_68081;
	BIT_VEC cppVar_68082;
	BIT_VEC cppVar_68083;
	BIT_VEC cppVar_68084;
	BIT_VEC cppVar_68085;
	BIT_VEC cppVar_68086;
	BIT_VEC cppVar_68087;
	BIT_VEC cppVar_68088;
	BIT_VEC cppVar_68089;
	BIT_VEC cppVar_68076;
	BIT_VEC cppVar_68090;
	bool cppVar_68091;
	BIT_VEC cppVar_68094;
	BIT_VEC cppVar_68095;
	BIT_VEC cppVar_68096;
	bool cppVar_68097;
	BIT_VEC cppVar_68098;
	BIT_VEC cppVar_68099;
	BIT_VEC cppVar_68100;
	BIT_VEC cppVar_68101;
	BIT_VEC cppVar_68102;
	BIT_VEC cppVar_68103;
	BIT_VEC cppVar_68104;
	BIT_VEC cppVar_68105;
	BIT_VEC cppVar_68106;
	BIT_VEC cppVar_68093;
	BIT_VEC cppVar_68107;
	bool cppVar_68108;
	BIT_VEC cppVar_68111;
	BIT_VEC cppVar_68112;
	BIT_VEC cppVar_68113;
	bool cppVar_68114;
	BIT_VEC cppVar_68115;
	BIT_VEC cppVar_68116;
	BIT_VEC cppVar_68117;
	BIT_VEC cppVar_68118;
	BIT_VEC cppVar_68119;
	BIT_VEC cppVar_68120;
	BIT_VEC cppVar_68121;
	BIT_VEC cppVar_68122;
	BIT_VEC cppVar_68123;
	BIT_VEC cppVar_68110;
	BIT_VEC cppVar_68124;
	bool cppVar_68125;
	BIT_VEC cppVar_68128;
	BIT_VEC cppVar_68129;
	BIT_VEC cppVar_68130;
	bool cppVar_68131;
	BIT_VEC cppVar_68132;
	BIT_VEC cppVar_68133;
	BIT_VEC cppVar_68134;
	BIT_VEC cppVar_68135;
	BIT_VEC cppVar_68136;
	BIT_VEC cppVar_68137;
	BIT_VEC cppVar_68138;
	BIT_VEC cppVar_68139;
	BIT_VEC cppVar_68140;
	BIT_VEC cppVar_68127;
	BIT_VEC cppVar_68141;
	bool cppVar_68142;
	BIT_VEC cppVar_68145;
	BIT_VEC cppVar_68146;
	BIT_VEC cppVar_68147;
	bool cppVar_68148;
	BIT_VEC cppVar_68149;
	BIT_VEC cppVar_68150;
	BIT_VEC cppVar_68151;
	BIT_VEC cppVar_68152;
	BIT_VEC cppVar_68153;
	BIT_VEC cppVar_68154;
	BIT_VEC cppVar_68155;
	BIT_VEC cppVar_68156;
	BIT_VEC cppVar_68157;
	BIT_VEC cppVar_68144;
	BIT_VEC cppVar_68158;
	bool cppVar_68159;
	BIT_VEC cppVar_68162;
	BIT_VEC cppVar_68163;
	BIT_VEC cppVar_68164;
	bool cppVar_68165;
	BIT_VEC cppVar_68166;
	BIT_VEC cppVar_68167;
	BIT_VEC cppVar_68168;
	BIT_VEC cppVar_68169;
	BIT_VEC cppVar_68170;
	BIT_VEC cppVar_68171;
	BIT_VEC cppVar_68172;
	BIT_VEC cppVar_68173;
	BIT_VEC cppVar_68174;
	BIT_VEC cppVar_68161;
	BIT_VEC cppVar_68175;
	bool cppVar_68176;
	BIT_VEC cppVar_68179;
	BIT_VEC cppVar_68180;
	BIT_VEC cppVar_68181;
	bool cppVar_68182;
	BIT_VEC cppVar_68183;
	BIT_VEC cppVar_68184;
	BIT_VEC cppVar_68185;
	BIT_VEC cppVar_68186;
	BIT_VEC cppVar_68187;
	BIT_VEC cppVar_68188;
	BIT_VEC cppVar_68189;
	BIT_VEC cppVar_68190;
	BIT_VEC cppVar_68191;
	BIT_VEC cppVar_68178;
	BIT_VEC cppVar_68192;
	bool cppVar_68193;
	BIT_VEC cppVar_68196;
	BIT_VEC cppVar_68197;
	BIT_VEC cppVar_68198;
	bool cppVar_68199;
	BIT_VEC cppVar_68200;
	BIT_VEC cppVar_68201;
	BIT_VEC cppVar_68202;
	BIT_VEC cppVar_68203;
	BIT_VEC cppVar_68204;
	BIT_VEC cppVar_68205;
	BIT_VEC cppVar_68206;
	BIT_VEC cppVar_68207;
	BIT_VEC cppVar_68208;
	BIT_VEC cppVar_68195;
	BIT_VEC cppVar_68209;
	bool cppVar_68210;
	BIT_VEC cppVar_68213;
	BIT_VEC cppVar_68214;
	BIT_VEC cppVar_68215;
	bool cppVar_68216;
	BIT_VEC cppVar_68217;
	BIT_VEC cppVar_68218;
	BIT_VEC cppVar_68219;
	BIT_VEC cppVar_68220;
	BIT_VEC cppVar_68221;
	BIT_VEC cppVar_68222;
	BIT_VEC cppVar_68223;
	BIT_VEC cppVar_68224;
	BIT_VEC cppVar_68225;
	BIT_VEC cppVar_68212;
	BIT_VEC cppVar_68226;
	bool cppVar_68227;
	BIT_VEC cppVar_68230;
	BIT_VEC cppVar_68231;
	BIT_VEC cppVar_68232;
	bool cppVar_68233;
	BIT_VEC cppVar_68234;
	BIT_VEC cppVar_68235;
	BIT_VEC cppVar_68236;
	BIT_VEC cppVar_68237;
	BIT_VEC cppVar_68238;
	BIT_VEC cppVar_68239;
	BIT_VEC cppVar_68240;
	BIT_VEC cppVar_68241;
	BIT_VEC cppVar_68242;
	BIT_VEC cppVar_68229;
	BIT_VEC cppVar_68243;
	bool cppVar_68244;
	BIT_VEC cppVar_68247;
	BIT_VEC cppVar_68248;
	BIT_VEC cppVar_68249;
	bool cppVar_68250;
	BIT_VEC cppVar_68251;
	BIT_VEC cppVar_68252;
	BIT_VEC cppVar_68253;
	BIT_VEC cppVar_68254;
	BIT_VEC cppVar_68255;
	BIT_VEC cppVar_68256;
	BIT_VEC cppVar_68257;
	BIT_VEC cppVar_68258;
	BIT_VEC cppVar_68259;
	BIT_VEC cppVar_68246;
	BIT_VEC cppVar_68260;
	bool cppVar_68261;
	BIT_VEC cppVar_68264;
	BIT_VEC cppVar_68265;
	BIT_VEC cppVar_68266;
	bool cppVar_68267;
	BIT_VEC cppVar_68268;
	BIT_VEC cppVar_68269;
	BIT_VEC cppVar_68270;
	BIT_VEC cppVar_68271;
	BIT_VEC cppVar_68272;
	BIT_VEC cppVar_68273;
	BIT_VEC cppVar_68274;
	BIT_VEC cppVar_68275;
	BIT_VEC cppVar_68276;
	BIT_VEC cppVar_68263;
	BIT_VEC cppVar_68277;
	bool cppVar_68278;
	BIT_VEC cppVar_68281;
	BIT_VEC cppVar_68282;
	BIT_VEC cppVar_68283;
	bool cppVar_68284;
	BIT_VEC cppVar_68285;
	BIT_VEC cppVar_68286;
	BIT_VEC cppVar_68287;
	BIT_VEC cppVar_68288;
	BIT_VEC cppVar_68289;
	BIT_VEC cppVar_68290;
	BIT_VEC cppVar_68291;
	BIT_VEC cppVar_68292;
	BIT_VEC cppVar_68293;
	BIT_VEC cppVar_68280;
	BIT_VEC cppVar_68294;
	bool cppVar_68295;
	BIT_VEC cppVar_68296;
	BIT_VEC cppVar_68279;
	BIT_VEC cppVar_68262;
	BIT_VEC cppVar_68245;
	BIT_VEC cppVar_68228;
	BIT_VEC cppVar_68211;
	BIT_VEC cppVar_68194;
	BIT_VEC cppVar_68177;
	BIT_VEC cppVar_68160;
	BIT_VEC cppVar_68143;
	BIT_VEC cppVar_68126;
	BIT_VEC cppVar_68109;
	BIT_VEC cppVar_68092;
	BIT_VEC cppVar_68075;
	BIT_VEC cppVar_68058;
	BIT_VEC cppVar_68041;
	BIT_VEC cppVar_68024;
	BIT_VEC cppVar_68007;
	BIT_VEC cppVar_67990;
	BIT_VEC cppVar_67973;
	BIT_VEC cppVar_67956;
	BIT_VEC cppVar_67939;
	BIT_VEC cppVar_67906;
	BIT_VEC cppVar_68297;
	BIT_VEC cppVar_68298;
	BIT_VEC cppVar_68299;
	BIT_VEC cppVar_68300;
	BIT_VEC cppVar_68301;
	BIT_VEC cppVar_68302;
	BIT_VEC cppVar_68303;
	BIT_VEC cppVar_68304;
	BIT_VEC cppVar_68305;
	BIT_VEC cppVar_67878;
	BIT_VEC cppVar_68307;
	BIT_VEC cppVar_68308;
	bool cppVar_68309;
	BIT_VEC cppVar_68311;
	BIT_VEC cppVar_68312;
	BIT_VEC cppVar_68313;
	BIT_VEC cppVar_68314;
	bool cppVar_68315;
	BIT_VEC cppVar_68316;
	BIT_VEC cppVar_68310;
	BIT_VEC cppVar_68318;
	BIT_VEC cppVar_68319;
	bool cppVar_68320;
	BIT_VEC cppVar_68321;
	BIT_VEC cppVar_68322;
	bool cppVar_68323;
	bool cppVar_68324;
	BIT_VEC cppVar_68326;
	BIT_VEC cppVar_68327;
	BIT_VEC cppVar_68328;
	BIT_VEC cppVar_68329;
	bool cppVar_68330;
	BIT_VEC cppVar_68325;
	BIT_VEC cppVar_68332;
	BIT_VEC cppVar_68333;
	bool cppVar_68334;
	BIT_VEC cppVar_68337;
	BIT_VEC cppVar_68338;
	BIT_VEC cppVar_68339;
	BIT_VEC cppVar_68340;
	BIT_VEC cppVar_68341;
	bool cppVar_68342;
	BIT_VEC cppVar_68343;
	BIT_VEC cppVar_68344;
	BIT_VEC cppVar_68345;
	BIT_VEC cppVar_68346;
	BIT_VEC cppVar_68347;
	BIT_VEC cppVar_68348;
	BIT_VEC cppVar_68349;
	BIT_VEC cppVar_68350;
	BIT_VEC cppVar_68351;
	BIT_VEC cppVar_68352;
	BIT_VEC cppVar_68353;
	BIT_VEC cppVar_68336;
	BIT_VEC cppVar_68354;
	bool cppVar_68355;
	BIT_VEC cppVar_68356;
	BIT_VEC cppVar_68357;
	BIT_VEC cppVar_68358;
	BIT_VEC cppVar_68359;
	BIT_VEC cppVar_68360;
	BIT_VEC cppVar_68361;
	BIT_VEC cppVar_68362;
	BIT_VEC cppVar_68365;
	BIT_VEC cppVar_68366;
	BIT_VEC cppVar_68367;
	bool cppVar_68368;
	BIT_VEC cppVar_68369;
	BIT_VEC cppVar_68370;
	BIT_VEC cppVar_68371;
	BIT_VEC cppVar_68372;
	BIT_VEC cppVar_68373;
	BIT_VEC cppVar_68374;
	BIT_VEC cppVar_68375;
	BIT_VEC cppVar_68376;
	BIT_VEC cppVar_68377;
	BIT_VEC cppVar_68364;
	BIT_VEC cppVar_68378;
	BIT_VEC cppVar_68379;
	bool cppVar_68380;
	BIT_VEC cppVar_68382;
	BIT_VEC cppVar_68383;
	BIT_VEC cppVar_68384;
	bool cppVar_68385;
	BIT_VEC cppVar_68386;
	BIT_VEC cppVar_68387;
	BIT_VEC cppVar_68388;
	BIT_VEC cppVar_68389;
	BIT_VEC cppVar_68390;
	BIT_VEC cppVar_68391;
	BIT_VEC cppVar_68392;
	BIT_VEC cppVar_68393;
	BIT_VEC cppVar_68394;
	BIT_VEC cppVar_68381;
	BIT_VEC cppVar_68395;
	BIT_VEC cppVar_68398;
	BIT_VEC cppVar_68399;
	BIT_VEC cppVar_68400;
	bool cppVar_68401;
	BIT_VEC cppVar_68402;
	BIT_VEC cppVar_68403;
	BIT_VEC cppVar_68404;
	BIT_VEC cppVar_68405;
	BIT_VEC cppVar_68406;
	BIT_VEC cppVar_68407;
	BIT_VEC cppVar_68408;
	BIT_VEC cppVar_68409;
	BIT_VEC cppVar_68410;
	BIT_VEC cppVar_68397;
	BIT_VEC cppVar_68411;
	bool cppVar_68412;
	BIT_VEC cppVar_68415;
	BIT_VEC cppVar_68416;
	BIT_VEC cppVar_68417;
	bool cppVar_68418;
	BIT_VEC cppVar_68419;
	BIT_VEC cppVar_68420;
	BIT_VEC cppVar_68421;
	BIT_VEC cppVar_68422;
	BIT_VEC cppVar_68423;
	BIT_VEC cppVar_68424;
	BIT_VEC cppVar_68425;
	BIT_VEC cppVar_68426;
	BIT_VEC cppVar_68427;
	BIT_VEC cppVar_68414;
	BIT_VEC cppVar_68428;
	bool cppVar_68429;
	BIT_VEC cppVar_68432;
	BIT_VEC cppVar_68433;
	BIT_VEC cppVar_68434;
	bool cppVar_68435;
	BIT_VEC cppVar_68436;
	BIT_VEC cppVar_68437;
	BIT_VEC cppVar_68438;
	BIT_VEC cppVar_68439;
	BIT_VEC cppVar_68440;
	BIT_VEC cppVar_68441;
	BIT_VEC cppVar_68442;
	BIT_VEC cppVar_68443;
	BIT_VEC cppVar_68444;
	BIT_VEC cppVar_68431;
	BIT_VEC cppVar_68445;
	bool cppVar_68446;
	BIT_VEC cppVar_68449;
	BIT_VEC cppVar_68450;
	BIT_VEC cppVar_68451;
	bool cppVar_68452;
	BIT_VEC cppVar_68453;
	BIT_VEC cppVar_68454;
	BIT_VEC cppVar_68455;
	BIT_VEC cppVar_68456;
	BIT_VEC cppVar_68457;
	BIT_VEC cppVar_68458;
	BIT_VEC cppVar_68459;
	BIT_VEC cppVar_68460;
	BIT_VEC cppVar_68461;
	BIT_VEC cppVar_68448;
	BIT_VEC cppVar_68462;
	bool cppVar_68463;
	BIT_VEC cppVar_68466;
	BIT_VEC cppVar_68467;
	BIT_VEC cppVar_68468;
	bool cppVar_68469;
	BIT_VEC cppVar_68470;
	BIT_VEC cppVar_68471;
	BIT_VEC cppVar_68472;
	BIT_VEC cppVar_68473;
	BIT_VEC cppVar_68474;
	BIT_VEC cppVar_68475;
	BIT_VEC cppVar_68476;
	BIT_VEC cppVar_68477;
	BIT_VEC cppVar_68478;
	BIT_VEC cppVar_68465;
	BIT_VEC cppVar_68479;
	bool cppVar_68480;
	BIT_VEC cppVar_68483;
	BIT_VEC cppVar_68484;
	BIT_VEC cppVar_68485;
	bool cppVar_68486;
	BIT_VEC cppVar_68487;
	BIT_VEC cppVar_68488;
	BIT_VEC cppVar_68489;
	BIT_VEC cppVar_68490;
	BIT_VEC cppVar_68491;
	BIT_VEC cppVar_68492;
	BIT_VEC cppVar_68493;
	BIT_VEC cppVar_68494;
	BIT_VEC cppVar_68495;
	BIT_VEC cppVar_68482;
	BIT_VEC cppVar_68496;
	bool cppVar_68497;
	BIT_VEC cppVar_68500;
	BIT_VEC cppVar_68501;
	BIT_VEC cppVar_68502;
	bool cppVar_68503;
	BIT_VEC cppVar_68504;
	BIT_VEC cppVar_68505;
	BIT_VEC cppVar_68506;
	BIT_VEC cppVar_68507;
	BIT_VEC cppVar_68508;
	BIT_VEC cppVar_68509;
	BIT_VEC cppVar_68510;
	BIT_VEC cppVar_68511;
	BIT_VEC cppVar_68512;
	BIT_VEC cppVar_68499;
	BIT_VEC cppVar_68513;
	bool cppVar_68514;
	BIT_VEC cppVar_68517;
	BIT_VEC cppVar_68518;
	BIT_VEC cppVar_68519;
	bool cppVar_68520;
	BIT_VEC cppVar_68521;
	BIT_VEC cppVar_68522;
	BIT_VEC cppVar_68523;
	BIT_VEC cppVar_68524;
	BIT_VEC cppVar_68525;
	BIT_VEC cppVar_68526;
	BIT_VEC cppVar_68527;
	BIT_VEC cppVar_68528;
	BIT_VEC cppVar_68529;
	BIT_VEC cppVar_68516;
	BIT_VEC cppVar_68530;
	bool cppVar_68531;
	BIT_VEC cppVar_68534;
	BIT_VEC cppVar_68535;
	BIT_VEC cppVar_68536;
	bool cppVar_68537;
	BIT_VEC cppVar_68538;
	BIT_VEC cppVar_68539;
	BIT_VEC cppVar_68540;
	BIT_VEC cppVar_68541;
	BIT_VEC cppVar_68542;
	BIT_VEC cppVar_68543;
	BIT_VEC cppVar_68544;
	BIT_VEC cppVar_68545;
	BIT_VEC cppVar_68546;
	BIT_VEC cppVar_68533;
	BIT_VEC cppVar_68547;
	bool cppVar_68548;
	BIT_VEC cppVar_68551;
	BIT_VEC cppVar_68552;
	BIT_VEC cppVar_68553;
	bool cppVar_68554;
	BIT_VEC cppVar_68555;
	BIT_VEC cppVar_68556;
	BIT_VEC cppVar_68557;
	BIT_VEC cppVar_68558;
	BIT_VEC cppVar_68559;
	BIT_VEC cppVar_68560;
	BIT_VEC cppVar_68561;
	BIT_VEC cppVar_68562;
	BIT_VEC cppVar_68563;
	BIT_VEC cppVar_68550;
	BIT_VEC cppVar_68564;
	bool cppVar_68565;
	BIT_VEC cppVar_68568;
	BIT_VEC cppVar_68569;
	BIT_VEC cppVar_68570;
	bool cppVar_68571;
	BIT_VEC cppVar_68572;
	BIT_VEC cppVar_68573;
	BIT_VEC cppVar_68574;
	BIT_VEC cppVar_68575;
	BIT_VEC cppVar_68576;
	BIT_VEC cppVar_68577;
	BIT_VEC cppVar_68578;
	BIT_VEC cppVar_68579;
	BIT_VEC cppVar_68580;
	BIT_VEC cppVar_68567;
	BIT_VEC cppVar_68581;
	bool cppVar_68582;
	BIT_VEC cppVar_68585;
	BIT_VEC cppVar_68586;
	BIT_VEC cppVar_68587;
	bool cppVar_68588;
	BIT_VEC cppVar_68589;
	BIT_VEC cppVar_68590;
	BIT_VEC cppVar_68591;
	BIT_VEC cppVar_68592;
	BIT_VEC cppVar_68593;
	BIT_VEC cppVar_68594;
	BIT_VEC cppVar_68595;
	BIT_VEC cppVar_68596;
	BIT_VEC cppVar_68597;
	BIT_VEC cppVar_68584;
	BIT_VEC cppVar_68598;
	bool cppVar_68599;
	BIT_VEC cppVar_68602;
	BIT_VEC cppVar_68603;
	BIT_VEC cppVar_68604;
	bool cppVar_68605;
	BIT_VEC cppVar_68606;
	BIT_VEC cppVar_68607;
	BIT_VEC cppVar_68608;
	BIT_VEC cppVar_68609;
	BIT_VEC cppVar_68610;
	BIT_VEC cppVar_68611;
	BIT_VEC cppVar_68612;
	BIT_VEC cppVar_68613;
	BIT_VEC cppVar_68614;
	BIT_VEC cppVar_68601;
	BIT_VEC cppVar_68615;
	bool cppVar_68616;
	BIT_VEC cppVar_68619;
	BIT_VEC cppVar_68620;
	BIT_VEC cppVar_68621;
	bool cppVar_68622;
	BIT_VEC cppVar_68623;
	BIT_VEC cppVar_68624;
	BIT_VEC cppVar_68625;
	BIT_VEC cppVar_68626;
	BIT_VEC cppVar_68627;
	BIT_VEC cppVar_68628;
	BIT_VEC cppVar_68629;
	BIT_VEC cppVar_68630;
	BIT_VEC cppVar_68631;
	BIT_VEC cppVar_68618;
	BIT_VEC cppVar_68632;
	bool cppVar_68633;
	BIT_VEC cppVar_68636;
	BIT_VEC cppVar_68637;
	BIT_VEC cppVar_68638;
	bool cppVar_68639;
	BIT_VEC cppVar_68640;
	BIT_VEC cppVar_68641;
	BIT_VEC cppVar_68642;
	BIT_VEC cppVar_68643;
	BIT_VEC cppVar_68644;
	BIT_VEC cppVar_68645;
	BIT_VEC cppVar_68646;
	BIT_VEC cppVar_68647;
	BIT_VEC cppVar_68648;
	BIT_VEC cppVar_68635;
	BIT_VEC cppVar_68649;
	bool cppVar_68650;
	BIT_VEC cppVar_68653;
	BIT_VEC cppVar_68654;
	BIT_VEC cppVar_68655;
	bool cppVar_68656;
	BIT_VEC cppVar_68657;
	BIT_VEC cppVar_68658;
	BIT_VEC cppVar_68659;
	BIT_VEC cppVar_68660;
	BIT_VEC cppVar_68661;
	BIT_VEC cppVar_68662;
	BIT_VEC cppVar_68663;
	BIT_VEC cppVar_68664;
	BIT_VEC cppVar_68665;
	BIT_VEC cppVar_68652;
	BIT_VEC cppVar_68666;
	bool cppVar_68667;
	BIT_VEC cppVar_68670;
	BIT_VEC cppVar_68671;
	BIT_VEC cppVar_68672;
	bool cppVar_68673;
	BIT_VEC cppVar_68674;
	BIT_VEC cppVar_68675;
	BIT_VEC cppVar_68676;
	BIT_VEC cppVar_68677;
	BIT_VEC cppVar_68678;
	BIT_VEC cppVar_68679;
	BIT_VEC cppVar_68680;
	BIT_VEC cppVar_68681;
	BIT_VEC cppVar_68682;
	BIT_VEC cppVar_68669;
	BIT_VEC cppVar_68683;
	bool cppVar_68684;
	BIT_VEC cppVar_68687;
	BIT_VEC cppVar_68688;
	BIT_VEC cppVar_68689;
	bool cppVar_68690;
	BIT_VEC cppVar_68691;
	BIT_VEC cppVar_68692;
	BIT_VEC cppVar_68693;
	BIT_VEC cppVar_68694;
	BIT_VEC cppVar_68695;
	BIT_VEC cppVar_68696;
	BIT_VEC cppVar_68697;
	BIT_VEC cppVar_68698;
	BIT_VEC cppVar_68699;
	BIT_VEC cppVar_68686;
	BIT_VEC cppVar_68700;
	bool cppVar_68701;
	BIT_VEC cppVar_68704;
	BIT_VEC cppVar_68705;
	BIT_VEC cppVar_68706;
	bool cppVar_68707;
	BIT_VEC cppVar_68708;
	BIT_VEC cppVar_68709;
	BIT_VEC cppVar_68710;
	BIT_VEC cppVar_68711;
	BIT_VEC cppVar_68712;
	BIT_VEC cppVar_68713;
	BIT_VEC cppVar_68714;
	BIT_VEC cppVar_68715;
	BIT_VEC cppVar_68716;
	BIT_VEC cppVar_68703;
	BIT_VEC cppVar_68717;
	bool cppVar_68718;
	BIT_VEC cppVar_68721;
	BIT_VEC cppVar_68722;
	BIT_VEC cppVar_68723;
	bool cppVar_68724;
	BIT_VEC cppVar_68725;
	BIT_VEC cppVar_68726;
	BIT_VEC cppVar_68727;
	BIT_VEC cppVar_68728;
	BIT_VEC cppVar_68729;
	BIT_VEC cppVar_68730;
	BIT_VEC cppVar_68731;
	BIT_VEC cppVar_68732;
	BIT_VEC cppVar_68733;
	BIT_VEC cppVar_68720;
	BIT_VEC cppVar_68734;
	bool cppVar_68735;
	BIT_VEC cppVar_68738;
	BIT_VEC cppVar_68739;
	BIT_VEC cppVar_68740;
	bool cppVar_68741;
	BIT_VEC cppVar_68742;
	BIT_VEC cppVar_68743;
	BIT_VEC cppVar_68744;
	BIT_VEC cppVar_68745;
	BIT_VEC cppVar_68746;
	BIT_VEC cppVar_68747;
	BIT_VEC cppVar_68748;
	BIT_VEC cppVar_68749;
	BIT_VEC cppVar_68750;
	BIT_VEC cppVar_68737;
	BIT_VEC cppVar_68751;
	bool cppVar_68752;
	BIT_VEC cppVar_68753;
	BIT_VEC cppVar_68736;
	BIT_VEC cppVar_68719;
	BIT_VEC cppVar_68702;
	BIT_VEC cppVar_68685;
	BIT_VEC cppVar_68668;
	BIT_VEC cppVar_68651;
	BIT_VEC cppVar_68634;
	BIT_VEC cppVar_68617;
	BIT_VEC cppVar_68600;
	BIT_VEC cppVar_68583;
	BIT_VEC cppVar_68566;
	BIT_VEC cppVar_68549;
	BIT_VEC cppVar_68532;
	BIT_VEC cppVar_68515;
	BIT_VEC cppVar_68498;
	BIT_VEC cppVar_68481;
	BIT_VEC cppVar_68464;
	BIT_VEC cppVar_68447;
	BIT_VEC cppVar_68430;
	BIT_VEC cppVar_68413;
	BIT_VEC cppVar_68396;
	BIT_VEC cppVar_68363;
	BIT_VEC cppVar_68754;
	BIT_VEC cppVar_68757;
	BIT_VEC cppVar_68758;
	BIT_VEC cppVar_68759;
	BIT_VEC cppVar_68760;
	bool cppVar_68761;
	BIT_VEC cppVar_68762;
	BIT_VEC cppVar_68763;
	BIT_VEC cppVar_68764;
	BIT_VEC cppVar_68765;
	BIT_VEC cppVar_68766;
	BIT_VEC cppVar_68767;
	BIT_VEC cppVar_68768;
	BIT_VEC cppVar_68769;
	BIT_VEC cppVar_68770;
	BIT_VEC cppVar_68771;
	BIT_VEC cppVar_68772;
	BIT_VEC cppVar_68756;
	BIT_VEC cppVar_68773;
	BIT_VEC cppVar_68774;
	bool cppVar_68775;
	BIT_VEC cppVar_68777;
	BIT_VEC cppVar_68778;
	BIT_VEC cppVar_68779;
	bool cppVar_68780;
	BIT_VEC cppVar_68781;
	BIT_VEC cppVar_68782;
	BIT_VEC cppVar_68783;
	BIT_VEC cppVar_68784;
	BIT_VEC cppVar_68785;
	BIT_VEC cppVar_68786;
	BIT_VEC cppVar_68787;
	BIT_VEC cppVar_68788;
	BIT_VEC cppVar_68789;
	BIT_VEC cppVar_68776;
	BIT_VEC cppVar_68790;
	BIT_VEC cppVar_68793;
	BIT_VEC cppVar_68794;
	BIT_VEC cppVar_68795;
	bool cppVar_68796;
	BIT_VEC cppVar_68797;
	BIT_VEC cppVar_68798;
	BIT_VEC cppVar_68799;
	BIT_VEC cppVar_68800;
	BIT_VEC cppVar_68801;
	BIT_VEC cppVar_68802;
	BIT_VEC cppVar_68803;
	BIT_VEC cppVar_68804;
	BIT_VEC cppVar_68805;
	BIT_VEC cppVar_68792;
	BIT_VEC cppVar_68806;
	bool cppVar_68807;
	BIT_VEC cppVar_68810;
	BIT_VEC cppVar_68811;
	BIT_VEC cppVar_68812;
	bool cppVar_68813;
	BIT_VEC cppVar_68814;
	BIT_VEC cppVar_68815;
	BIT_VEC cppVar_68816;
	BIT_VEC cppVar_68817;
	BIT_VEC cppVar_68818;
	BIT_VEC cppVar_68819;
	BIT_VEC cppVar_68820;
	BIT_VEC cppVar_68821;
	BIT_VEC cppVar_68822;
	BIT_VEC cppVar_68809;
	BIT_VEC cppVar_68823;
	bool cppVar_68824;
	BIT_VEC cppVar_68827;
	BIT_VEC cppVar_68828;
	BIT_VEC cppVar_68829;
	bool cppVar_68830;
	BIT_VEC cppVar_68831;
	BIT_VEC cppVar_68832;
	BIT_VEC cppVar_68833;
	BIT_VEC cppVar_68834;
	BIT_VEC cppVar_68835;
	BIT_VEC cppVar_68836;
	BIT_VEC cppVar_68837;
	BIT_VEC cppVar_68838;
	BIT_VEC cppVar_68839;
	BIT_VEC cppVar_68826;
	BIT_VEC cppVar_68840;
	bool cppVar_68841;
	BIT_VEC cppVar_68844;
	BIT_VEC cppVar_68845;
	BIT_VEC cppVar_68846;
	bool cppVar_68847;
	BIT_VEC cppVar_68848;
	BIT_VEC cppVar_68849;
	BIT_VEC cppVar_68850;
	BIT_VEC cppVar_68851;
	BIT_VEC cppVar_68852;
	BIT_VEC cppVar_68853;
	BIT_VEC cppVar_68854;
	BIT_VEC cppVar_68855;
	BIT_VEC cppVar_68856;
	BIT_VEC cppVar_68843;
	BIT_VEC cppVar_68857;
	bool cppVar_68858;
	BIT_VEC cppVar_68861;
	BIT_VEC cppVar_68862;
	BIT_VEC cppVar_68863;
	bool cppVar_68864;
	BIT_VEC cppVar_68865;
	BIT_VEC cppVar_68866;
	BIT_VEC cppVar_68867;
	BIT_VEC cppVar_68868;
	BIT_VEC cppVar_68869;
	BIT_VEC cppVar_68870;
	BIT_VEC cppVar_68871;
	BIT_VEC cppVar_68872;
	BIT_VEC cppVar_68873;
	BIT_VEC cppVar_68860;
	BIT_VEC cppVar_68874;
	bool cppVar_68875;
	BIT_VEC cppVar_68878;
	BIT_VEC cppVar_68879;
	BIT_VEC cppVar_68880;
	bool cppVar_68881;
	BIT_VEC cppVar_68882;
	BIT_VEC cppVar_68883;
	BIT_VEC cppVar_68884;
	BIT_VEC cppVar_68885;
	BIT_VEC cppVar_68886;
	BIT_VEC cppVar_68887;
	BIT_VEC cppVar_68888;
	BIT_VEC cppVar_68889;
	BIT_VEC cppVar_68890;
	BIT_VEC cppVar_68877;
	BIT_VEC cppVar_68891;
	bool cppVar_68892;
	BIT_VEC cppVar_68895;
	BIT_VEC cppVar_68896;
	BIT_VEC cppVar_68897;
	bool cppVar_68898;
	BIT_VEC cppVar_68899;
	BIT_VEC cppVar_68900;
	BIT_VEC cppVar_68901;
	BIT_VEC cppVar_68902;
	BIT_VEC cppVar_68903;
	BIT_VEC cppVar_68904;
	BIT_VEC cppVar_68905;
	BIT_VEC cppVar_68906;
	BIT_VEC cppVar_68907;
	BIT_VEC cppVar_68894;
	BIT_VEC cppVar_68908;
	bool cppVar_68909;
	BIT_VEC cppVar_68912;
	BIT_VEC cppVar_68913;
	BIT_VEC cppVar_68914;
	bool cppVar_68915;
	BIT_VEC cppVar_68916;
	BIT_VEC cppVar_68917;
	BIT_VEC cppVar_68918;
	BIT_VEC cppVar_68919;
	BIT_VEC cppVar_68920;
	BIT_VEC cppVar_68921;
	BIT_VEC cppVar_68922;
	BIT_VEC cppVar_68923;
	BIT_VEC cppVar_68924;
	BIT_VEC cppVar_68911;
	BIT_VEC cppVar_68925;
	bool cppVar_68926;
	BIT_VEC cppVar_68929;
	BIT_VEC cppVar_68930;
	BIT_VEC cppVar_68931;
	bool cppVar_68932;
	BIT_VEC cppVar_68933;
	BIT_VEC cppVar_68934;
	BIT_VEC cppVar_68935;
	BIT_VEC cppVar_68936;
	BIT_VEC cppVar_68937;
	BIT_VEC cppVar_68938;
	BIT_VEC cppVar_68939;
	BIT_VEC cppVar_68940;
	BIT_VEC cppVar_68941;
	BIT_VEC cppVar_68928;
	BIT_VEC cppVar_68942;
	bool cppVar_68943;
	BIT_VEC cppVar_68946;
	BIT_VEC cppVar_68947;
	BIT_VEC cppVar_68948;
	bool cppVar_68949;
	BIT_VEC cppVar_68950;
	BIT_VEC cppVar_68951;
	BIT_VEC cppVar_68952;
	BIT_VEC cppVar_68953;
	BIT_VEC cppVar_68954;
	BIT_VEC cppVar_68955;
	BIT_VEC cppVar_68956;
	BIT_VEC cppVar_68957;
	BIT_VEC cppVar_68958;
	BIT_VEC cppVar_68945;
	BIT_VEC cppVar_68959;
	bool cppVar_68960;
	BIT_VEC cppVar_68963;
	BIT_VEC cppVar_68964;
	BIT_VEC cppVar_68965;
	bool cppVar_68966;
	BIT_VEC cppVar_68967;
	BIT_VEC cppVar_68968;
	BIT_VEC cppVar_68969;
	BIT_VEC cppVar_68970;
	BIT_VEC cppVar_68971;
	BIT_VEC cppVar_68972;
	BIT_VEC cppVar_68973;
	BIT_VEC cppVar_68974;
	BIT_VEC cppVar_68975;
	BIT_VEC cppVar_68962;
	BIT_VEC cppVar_68976;
	bool cppVar_68977;
	BIT_VEC cppVar_68980;
	BIT_VEC cppVar_68981;
	BIT_VEC cppVar_68982;
	bool cppVar_68983;
	BIT_VEC cppVar_68984;
	BIT_VEC cppVar_68985;
	BIT_VEC cppVar_68986;
	BIT_VEC cppVar_68987;
	BIT_VEC cppVar_68988;
	BIT_VEC cppVar_68989;
	BIT_VEC cppVar_68990;
	BIT_VEC cppVar_68991;
	BIT_VEC cppVar_68992;
	BIT_VEC cppVar_68979;
	BIT_VEC cppVar_68993;
	bool cppVar_68994;
	BIT_VEC cppVar_68997;
	BIT_VEC cppVar_68998;
	BIT_VEC cppVar_68999;
	bool cppVar_69000;
	BIT_VEC cppVar_69001;
	BIT_VEC cppVar_69002;
	BIT_VEC cppVar_69003;
	BIT_VEC cppVar_69004;
	BIT_VEC cppVar_69005;
	BIT_VEC cppVar_69006;
	BIT_VEC cppVar_69007;
	BIT_VEC cppVar_69008;
	BIT_VEC cppVar_69009;
	BIT_VEC cppVar_68996;
	BIT_VEC cppVar_69010;
	bool cppVar_69011;
	BIT_VEC cppVar_69014;
	BIT_VEC cppVar_69015;
	BIT_VEC cppVar_69016;
	bool cppVar_69017;
	BIT_VEC cppVar_69018;
	BIT_VEC cppVar_69019;
	BIT_VEC cppVar_69020;
	BIT_VEC cppVar_69021;
	BIT_VEC cppVar_69022;
	BIT_VEC cppVar_69023;
	BIT_VEC cppVar_69024;
	BIT_VEC cppVar_69025;
	BIT_VEC cppVar_69026;
	BIT_VEC cppVar_69013;
	BIT_VEC cppVar_69027;
	bool cppVar_69028;
	BIT_VEC cppVar_69031;
	BIT_VEC cppVar_69032;
	BIT_VEC cppVar_69033;
	bool cppVar_69034;
	BIT_VEC cppVar_69035;
	BIT_VEC cppVar_69036;
	BIT_VEC cppVar_69037;
	BIT_VEC cppVar_69038;
	BIT_VEC cppVar_69039;
	BIT_VEC cppVar_69040;
	BIT_VEC cppVar_69041;
	BIT_VEC cppVar_69042;
	BIT_VEC cppVar_69043;
	BIT_VEC cppVar_69030;
	BIT_VEC cppVar_69044;
	bool cppVar_69045;
	BIT_VEC cppVar_69048;
	BIT_VEC cppVar_69049;
	BIT_VEC cppVar_69050;
	bool cppVar_69051;
	BIT_VEC cppVar_69052;
	BIT_VEC cppVar_69053;
	BIT_VEC cppVar_69054;
	BIT_VEC cppVar_69055;
	BIT_VEC cppVar_69056;
	BIT_VEC cppVar_69057;
	BIT_VEC cppVar_69058;
	BIT_VEC cppVar_69059;
	BIT_VEC cppVar_69060;
	BIT_VEC cppVar_69047;
	BIT_VEC cppVar_69061;
	bool cppVar_69062;
	BIT_VEC cppVar_69065;
	BIT_VEC cppVar_69066;
	BIT_VEC cppVar_69067;
	bool cppVar_69068;
	BIT_VEC cppVar_69069;
	BIT_VEC cppVar_69070;
	BIT_VEC cppVar_69071;
	BIT_VEC cppVar_69072;
	BIT_VEC cppVar_69073;
	BIT_VEC cppVar_69074;
	BIT_VEC cppVar_69075;
	BIT_VEC cppVar_69076;
	BIT_VEC cppVar_69077;
	BIT_VEC cppVar_69064;
	BIT_VEC cppVar_69078;
	bool cppVar_69079;
	BIT_VEC cppVar_69082;
	BIT_VEC cppVar_69083;
	BIT_VEC cppVar_69084;
	bool cppVar_69085;
	BIT_VEC cppVar_69086;
	BIT_VEC cppVar_69087;
	BIT_VEC cppVar_69088;
	BIT_VEC cppVar_69089;
	BIT_VEC cppVar_69090;
	BIT_VEC cppVar_69091;
	BIT_VEC cppVar_69092;
	BIT_VEC cppVar_69093;
	BIT_VEC cppVar_69094;
	BIT_VEC cppVar_69081;
	BIT_VEC cppVar_69095;
	bool cppVar_69096;
	BIT_VEC cppVar_69099;
	BIT_VEC cppVar_69100;
	BIT_VEC cppVar_69101;
	bool cppVar_69102;
	BIT_VEC cppVar_69103;
	BIT_VEC cppVar_69104;
	BIT_VEC cppVar_69105;
	BIT_VEC cppVar_69106;
	BIT_VEC cppVar_69107;
	BIT_VEC cppVar_69108;
	BIT_VEC cppVar_69109;
	BIT_VEC cppVar_69110;
	BIT_VEC cppVar_69111;
	BIT_VEC cppVar_69098;
	BIT_VEC cppVar_69112;
	bool cppVar_69113;
	BIT_VEC cppVar_69116;
	BIT_VEC cppVar_69117;
	BIT_VEC cppVar_69118;
	bool cppVar_69119;
	BIT_VEC cppVar_69120;
	BIT_VEC cppVar_69121;
	BIT_VEC cppVar_69122;
	BIT_VEC cppVar_69123;
	BIT_VEC cppVar_69124;
	BIT_VEC cppVar_69125;
	BIT_VEC cppVar_69126;
	BIT_VEC cppVar_69127;
	BIT_VEC cppVar_69128;
	BIT_VEC cppVar_69115;
	BIT_VEC cppVar_69129;
	bool cppVar_69130;
	BIT_VEC cppVar_69133;
	BIT_VEC cppVar_69134;
	BIT_VEC cppVar_69135;
	bool cppVar_69136;
	BIT_VEC cppVar_69137;
	BIT_VEC cppVar_69138;
	BIT_VEC cppVar_69139;
	BIT_VEC cppVar_69140;
	BIT_VEC cppVar_69141;
	BIT_VEC cppVar_69142;
	BIT_VEC cppVar_69143;
	BIT_VEC cppVar_69144;
	BIT_VEC cppVar_69145;
	BIT_VEC cppVar_69132;
	BIT_VEC cppVar_69146;
	bool cppVar_69147;
	BIT_VEC cppVar_69148;
	BIT_VEC cppVar_69131;
	BIT_VEC cppVar_69114;
	BIT_VEC cppVar_69097;
	BIT_VEC cppVar_69080;
	BIT_VEC cppVar_69063;
	BIT_VEC cppVar_69046;
	BIT_VEC cppVar_69029;
	BIT_VEC cppVar_69012;
	BIT_VEC cppVar_68995;
	BIT_VEC cppVar_68978;
	BIT_VEC cppVar_68961;
	BIT_VEC cppVar_68944;
	BIT_VEC cppVar_68927;
	BIT_VEC cppVar_68910;
	BIT_VEC cppVar_68893;
	BIT_VEC cppVar_68876;
	BIT_VEC cppVar_68859;
	BIT_VEC cppVar_68842;
	BIT_VEC cppVar_68825;
	BIT_VEC cppVar_68808;
	BIT_VEC cppVar_68791;
	BIT_VEC cppVar_68755;
	BIT_VEC cppVar_69149;
	BIT_VEC cppVar_69150;
	BIT_VEC cppVar_69151;
	BIT_VEC cppVar_69152;
	BIT_VEC cppVar_69153;
	BIT_VEC cppVar_69154;
	BIT_VEC cppVar_69155;
	BIT_VEC cppVar_69156;
	BIT_VEC cppVar_69157;
	BIT_VEC cppVar_69158;
	BIT_VEC cppVar_69159;
	BIT_VEC cppVar_69160;
	BIT_VEC cppVar_68335;
	BIT_VEC cppVar_69162;
	BIT_VEC cppVar_69163;
	bool cppVar_69164;
	BIT_VEC cppVar_69167;
	BIT_VEC cppVar_69168;
	BIT_VEC cppVar_69169;
	BIT_VEC cppVar_69170;
	BIT_VEC cppVar_69171;
	bool cppVar_69172;
	BIT_VEC cppVar_69173;
	BIT_VEC cppVar_69174;
	BIT_VEC cppVar_69175;
	BIT_VEC cppVar_69176;
	BIT_VEC cppVar_69177;
	BIT_VEC cppVar_69178;
	BIT_VEC cppVar_69179;
	BIT_VEC cppVar_69180;
	BIT_VEC cppVar_69181;
	BIT_VEC cppVar_69182;
	BIT_VEC cppVar_69183;
	BIT_VEC cppVar_69166;
	BIT_VEC cppVar_69184;
	bool cppVar_69185;
	BIT_VEC cppVar_69186;
	BIT_VEC cppVar_69187;
	BIT_VEC cppVar_69188;
	BIT_VEC cppVar_69189;
	BIT_VEC cppVar_69190;
	BIT_VEC cppVar_69191;
	BIT_VEC cppVar_69192;
	BIT_VEC cppVar_69195;
	BIT_VEC cppVar_69196;
	BIT_VEC cppVar_69197;
	bool cppVar_69198;
	BIT_VEC cppVar_69199;
	BIT_VEC cppVar_69200;
	BIT_VEC cppVar_69201;
	BIT_VEC cppVar_69202;
	BIT_VEC cppVar_69203;
	BIT_VEC cppVar_69204;
	BIT_VEC cppVar_69205;
	BIT_VEC cppVar_69206;
	BIT_VEC cppVar_69207;
	BIT_VEC cppVar_69194;
	BIT_VEC cppVar_69208;
	BIT_VEC cppVar_69209;
	bool cppVar_69210;
	BIT_VEC cppVar_69212;
	BIT_VEC cppVar_69213;
	BIT_VEC cppVar_69214;
	bool cppVar_69215;
	BIT_VEC cppVar_69216;
	BIT_VEC cppVar_69217;
	BIT_VEC cppVar_69218;
	BIT_VEC cppVar_69219;
	BIT_VEC cppVar_69220;
	BIT_VEC cppVar_69221;
	BIT_VEC cppVar_69222;
	BIT_VEC cppVar_69223;
	BIT_VEC cppVar_69224;
	BIT_VEC cppVar_69211;
	BIT_VEC cppVar_69225;
	BIT_VEC cppVar_69228;
	BIT_VEC cppVar_69229;
	BIT_VEC cppVar_69230;
	bool cppVar_69231;
	BIT_VEC cppVar_69232;
	BIT_VEC cppVar_69233;
	BIT_VEC cppVar_69234;
	BIT_VEC cppVar_69235;
	BIT_VEC cppVar_69236;
	BIT_VEC cppVar_69237;
	BIT_VEC cppVar_69238;
	BIT_VEC cppVar_69239;
	BIT_VEC cppVar_69240;
	BIT_VEC cppVar_69227;
	BIT_VEC cppVar_69241;
	bool cppVar_69242;
	BIT_VEC cppVar_69245;
	BIT_VEC cppVar_69246;
	BIT_VEC cppVar_69247;
	bool cppVar_69248;
	BIT_VEC cppVar_69249;
	BIT_VEC cppVar_69250;
	BIT_VEC cppVar_69251;
	BIT_VEC cppVar_69252;
	BIT_VEC cppVar_69253;
	BIT_VEC cppVar_69254;
	BIT_VEC cppVar_69255;
	BIT_VEC cppVar_69256;
	BIT_VEC cppVar_69257;
	BIT_VEC cppVar_69244;
	BIT_VEC cppVar_69258;
	bool cppVar_69259;
	BIT_VEC cppVar_69262;
	BIT_VEC cppVar_69263;
	BIT_VEC cppVar_69264;
	bool cppVar_69265;
	BIT_VEC cppVar_69266;
	BIT_VEC cppVar_69267;
	BIT_VEC cppVar_69268;
	BIT_VEC cppVar_69269;
	BIT_VEC cppVar_69270;
	BIT_VEC cppVar_69271;
	BIT_VEC cppVar_69272;
	BIT_VEC cppVar_69273;
	BIT_VEC cppVar_69274;
	BIT_VEC cppVar_69261;
	BIT_VEC cppVar_69275;
	bool cppVar_69276;
	BIT_VEC cppVar_69279;
	BIT_VEC cppVar_69280;
	BIT_VEC cppVar_69281;
	bool cppVar_69282;
	BIT_VEC cppVar_69283;
	BIT_VEC cppVar_69284;
	BIT_VEC cppVar_69285;
	BIT_VEC cppVar_69286;
	BIT_VEC cppVar_69287;
	BIT_VEC cppVar_69288;
	BIT_VEC cppVar_69289;
	BIT_VEC cppVar_69290;
	BIT_VEC cppVar_69291;
	BIT_VEC cppVar_69278;
	BIT_VEC cppVar_69292;
	bool cppVar_69293;
	BIT_VEC cppVar_69296;
	BIT_VEC cppVar_69297;
	BIT_VEC cppVar_69298;
	bool cppVar_69299;
	BIT_VEC cppVar_69300;
	BIT_VEC cppVar_69301;
	BIT_VEC cppVar_69302;
	BIT_VEC cppVar_69303;
	BIT_VEC cppVar_69304;
	BIT_VEC cppVar_69305;
	BIT_VEC cppVar_69306;
	BIT_VEC cppVar_69307;
	BIT_VEC cppVar_69308;
	BIT_VEC cppVar_69295;
	BIT_VEC cppVar_69309;
	bool cppVar_69310;
	BIT_VEC cppVar_69313;
	BIT_VEC cppVar_69314;
	BIT_VEC cppVar_69315;
	bool cppVar_69316;
	BIT_VEC cppVar_69317;
	BIT_VEC cppVar_69318;
	BIT_VEC cppVar_69319;
	BIT_VEC cppVar_69320;
	BIT_VEC cppVar_69321;
	BIT_VEC cppVar_69322;
	BIT_VEC cppVar_69323;
	BIT_VEC cppVar_69324;
	BIT_VEC cppVar_69325;
	BIT_VEC cppVar_69312;
	BIT_VEC cppVar_69326;
	bool cppVar_69327;
	BIT_VEC cppVar_69330;
	BIT_VEC cppVar_69331;
	BIT_VEC cppVar_69332;
	bool cppVar_69333;
	BIT_VEC cppVar_69334;
	BIT_VEC cppVar_69335;
	BIT_VEC cppVar_69336;
	BIT_VEC cppVar_69337;
	BIT_VEC cppVar_69338;
	BIT_VEC cppVar_69339;
	BIT_VEC cppVar_69340;
	BIT_VEC cppVar_69341;
	BIT_VEC cppVar_69342;
	BIT_VEC cppVar_69329;
	BIT_VEC cppVar_69343;
	bool cppVar_69344;
	BIT_VEC cppVar_69347;
	BIT_VEC cppVar_69348;
	BIT_VEC cppVar_69349;
	bool cppVar_69350;
	BIT_VEC cppVar_69351;
	BIT_VEC cppVar_69352;
	BIT_VEC cppVar_69353;
	BIT_VEC cppVar_69354;
	BIT_VEC cppVar_69355;
	BIT_VEC cppVar_69356;
	BIT_VEC cppVar_69357;
	BIT_VEC cppVar_69358;
	BIT_VEC cppVar_69359;
	BIT_VEC cppVar_69346;
	BIT_VEC cppVar_69360;
	bool cppVar_69361;
	BIT_VEC cppVar_69364;
	BIT_VEC cppVar_69365;
	BIT_VEC cppVar_69366;
	bool cppVar_69367;
	BIT_VEC cppVar_69368;
	BIT_VEC cppVar_69369;
	BIT_VEC cppVar_69370;
	BIT_VEC cppVar_69371;
	BIT_VEC cppVar_69372;
	BIT_VEC cppVar_69373;
	BIT_VEC cppVar_69374;
	BIT_VEC cppVar_69375;
	BIT_VEC cppVar_69376;
	BIT_VEC cppVar_69363;
	BIT_VEC cppVar_69377;
	bool cppVar_69378;
	BIT_VEC cppVar_69381;
	BIT_VEC cppVar_69382;
	BIT_VEC cppVar_69383;
	bool cppVar_69384;
	BIT_VEC cppVar_69385;
	BIT_VEC cppVar_69386;
	BIT_VEC cppVar_69387;
	BIT_VEC cppVar_69388;
	BIT_VEC cppVar_69389;
	BIT_VEC cppVar_69390;
	BIT_VEC cppVar_69391;
	BIT_VEC cppVar_69392;
	BIT_VEC cppVar_69393;
	BIT_VEC cppVar_69380;
	BIT_VEC cppVar_69394;
	bool cppVar_69395;
	BIT_VEC cppVar_69398;
	BIT_VEC cppVar_69399;
	BIT_VEC cppVar_69400;
	bool cppVar_69401;
	BIT_VEC cppVar_69402;
	BIT_VEC cppVar_69403;
	BIT_VEC cppVar_69404;
	BIT_VEC cppVar_69405;
	BIT_VEC cppVar_69406;
	BIT_VEC cppVar_69407;
	BIT_VEC cppVar_69408;
	BIT_VEC cppVar_69409;
	BIT_VEC cppVar_69410;
	BIT_VEC cppVar_69397;
	BIT_VEC cppVar_69411;
	bool cppVar_69412;
	BIT_VEC cppVar_69415;
	BIT_VEC cppVar_69416;
	BIT_VEC cppVar_69417;
	bool cppVar_69418;
	BIT_VEC cppVar_69419;
	BIT_VEC cppVar_69420;
	BIT_VEC cppVar_69421;
	BIT_VEC cppVar_69422;
	BIT_VEC cppVar_69423;
	BIT_VEC cppVar_69424;
	BIT_VEC cppVar_69425;
	BIT_VEC cppVar_69426;
	BIT_VEC cppVar_69427;
	BIT_VEC cppVar_69414;
	BIT_VEC cppVar_69428;
	bool cppVar_69429;
	BIT_VEC cppVar_69432;
	BIT_VEC cppVar_69433;
	BIT_VEC cppVar_69434;
	bool cppVar_69435;
	BIT_VEC cppVar_69436;
	BIT_VEC cppVar_69437;
	BIT_VEC cppVar_69438;
	BIT_VEC cppVar_69439;
	BIT_VEC cppVar_69440;
	BIT_VEC cppVar_69441;
	BIT_VEC cppVar_69442;
	BIT_VEC cppVar_69443;
	BIT_VEC cppVar_69444;
	BIT_VEC cppVar_69431;
	BIT_VEC cppVar_69445;
	bool cppVar_69446;
	BIT_VEC cppVar_69449;
	BIT_VEC cppVar_69450;
	BIT_VEC cppVar_69451;
	bool cppVar_69452;
	BIT_VEC cppVar_69453;
	BIT_VEC cppVar_69454;
	BIT_VEC cppVar_69455;
	BIT_VEC cppVar_69456;
	BIT_VEC cppVar_69457;
	BIT_VEC cppVar_69458;
	BIT_VEC cppVar_69459;
	BIT_VEC cppVar_69460;
	BIT_VEC cppVar_69461;
	BIT_VEC cppVar_69448;
	BIT_VEC cppVar_69462;
	bool cppVar_69463;
	BIT_VEC cppVar_69466;
	BIT_VEC cppVar_69467;
	BIT_VEC cppVar_69468;
	bool cppVar_69469;
	BIT_VEC cppVar_69470;
	BIT_VEC cppVar_69471;
	BIT_VEC cppVar_69472;
	BIT_VEC cppVar_69473;
	BIT_VEC cppVar_69474;
	BIT_VEC cppVar_69475;
	BIT_VEC cppVar_69476;
	BIT_VEC cppVar_69477;
	BIT_VEC cppVar_69478;
	BIT_VEC cppVar_69465;
	BIT_VEC cppVar_69479;
	bool cppVar_69480;
	BIT_VEC cppVar_69483;
	BIT_VEC cppVar_69484;
	BIT_VEC cppVar_69485;
	bool cppVar_69486;
	BIT_VEC cppVar_69487;
	BIT_VEC cppVar_69488;
	BIT_VEC cppVar_69489;
	BIT_VEC cppVar_69490;
	BIT_VEC cppVar_69491;
	BIT_VEC cppVar_69492;
	BIT_VEC cppVar_69493;
	BIT_VEC cppVar_69494;
	BIT_VEC cppVar_69495;
	BIT_VEC cppVar_69482;
	BIT_VEC cppVar_69496;
	bool cppVar_69497;
	BIT_VEC cppVar_69500;
	BIT_VEC cppVar_69501;
	BIT_VEC cppVar_69502;
	bool cppVar_69503;
	BIT_VEC cppVar_69504;
	BIT_VEC cppVar_69505;
	BIT_VEC cppVar_69506;
	BIT_VEC cppVar_69507;
	BIT_VEC cppVar_69508;
	BIT_VEC cppVar_69509;
	BIT_VEC cppVar_69510;
	BIT_VEC cppVar_69511;
	BIT_VEC cppVar_69512;
	BIT_VEC cppVar_69499;
	BIT_VEC cppVar_69513;
	bool cppVar_69514;
	BIT_VEC cppVar_69517;
	BIT_VEC cppVar_69518;
	BIT_VEC cppVar_69519;
	bool cppVar_69520;
	BIT_VEC cppVar_69521;
	BIT_VEC cppVar_69522;
	BIT_VEC cppVar_69523;
	BIT_VEC cppVar_69524;
	BIT_VEC cppVar_69525;
	BIT_VEC cppVar_69526;
	BIT_VEC cppVar_69527;
	BIT_VEC cppVar_69528;
	BIT_VEC cppVar_69529;
	BIT_VEC cppVar_69516;
	BIT_VEC cppVar_69530;
	bool cppVar_69531;
	BIT_VEC cppVar_69534;
	BIT_VEC cppVar_69535;
	BIT_VEC cppVar_69536;
	bool cppVar_69537;
	BIT_VEC cppVar_69538;
	BIT_VEC cppVar_69539;
	BIT_VEC cppVar_69540;
	BIT_VEC cppVar_69541;
	BIT_VEC cppVar_69542;
	BIT_VEC cppVar_69543;
	BIT_VEC cppVar_69544;
	BIT_VEC cppVar_69545;
	BIT_VEC cppVar_69546;
	BIT_VEC cppVar_69533;
	BIT_VEC cppVar_69547;
	bool cppVar_69548;
	BIT_VEC cppVar_69551;
	BIT_VEC cppVar_69552;
	BIT_VEC cppVar_69553;
	bool cppVar_69554;
	BIT_VEC cppVar_69555;
	BIT_VEC cppVar_69556;
	BIT_VEC cppVar_69557;
	BIT_VEC cppVar_69558;
	BIT_VEC cppVar_69559;
	BIT_VEC cppVar_69560;
	BIT_VEC cppVar_69561;
	BIT_VEC cppVar_69562;
	BIT_VEC cppVar_69563;
	BIT_VEC cppVar_69550;
	BIT_VEC cppVar_69564;
	bool cppVar_69565;
	BIT_VEC cppVar_69568;
	BIT_VEC cppVar_69569;
	BIT_VEC cppVar_69570;
	bool cppVar_69571;
	BIT_VEC cppVar_69572;
	BIT_VEC cppVar_69573;
	BIT_VEC cppVar_69574;
	BIT_VEC cppVar_69575;
	BIT_VEC cppVar_69576;
	BIT_VEC cppVar_69577;
	BIT_VEC cppVar_69578;
	BIT_VEC cppVar_69579;
	BIT_VEC cppVar_69580;
	BIT_VEC cppVar_69567;
	BIT_VEC cppVar_69581;
	bool cppVar_69582;
	BIT_VEC cppVar_69583;
	BIT_VEC cppVar_69566;
	BIT_VEC cppVar_69549;
	BIT_VEC cppVar_69532;
	BIT_VEC cppVar_69515;
	BIT_VEC cppVar_69498;
	BIT_VEC cppVar_69481;
	BIT_VEC cppVar_69464;
	BIT_VEC cppVar_69447;
	BIT_VEC cppVar_69430;
	BIT_VEC cppVar_69413;
	BIT_VEC cppVar_69396;
	BIT_VEC cppVar_69379;
	BIT_VEC cppVar_69362;
	BIT_VEC cppVar_69345;
	BIT_VEC cppVar_69328;
	BIT_VEC cppVar_69311;
	BIT_VEC cppVar_69294;
	BIT_VEC cppVar_69277;
	BIT_VEC cppVar_69260;
	BIT_VEC cppVar_69243;
	BIT_VEC cppVar_69226;
	BIT_VEC cppVar_69193;
	BIT_VEC cppVar_69584;
	BIT_VEC cppVar_69585;
	BIT_VEC cppVar_69586;
	BIT_VEC cppVar_69587;
	BIT_VEC cppVar_69588;
	BIT_VEC cppVar_69589;
	BIT_VEC cppVar_69590;
	BIT_VEC cppVar_69591;
	BIT_VEC cppVar_69592;
	BIT_VEC cppVar_69165;
	BIT_VEC cppVar_69594;
	BIT_VEC cppVar_69595;
	bool cppVar_69596;
	BIT_VEC cppVar_69598;
	BIT_VEC cppVar_69599;
	BIT_VEC cppVar_69600;
	BIT_VEC cppVar_69601;
	bool cppVar_69602;
	BIT_VEC cppVar_69604;
	BIT_VEC cppVar_69605;
	BIT_VEC cppVar_69606;
	BIT_VEC cppVar_69607;
	BIT_VEC cppVar_69608;
	BIT_VEC cppVar_69609;
	BIT_VEC cppVar_69610;
	bool cppVar_69611;
	BIT_VEC cppVar_69612;
	BIT_VEC cppVar_69613;
	BIT_VEC cppVar_69614;
	BIT_VEC cppVar_69615;
	BIT_VEC cppVar_69617;
	BIT_VEC cppVar_69618;
	BIT_VEC cppVar_69619;
	BIT_VEC cppVar_69620;
	bool cppVar_69621;
	BIT_VEC cppVar_69623;
	BIT_VEC cppVar_69624;
	BIT_VEC cppVar_69625;
	BIT_VEC cppVar_69626;
	bool cppVar_69627;
	BIT_VEC cppVar_69629;
	BIT_VEC cppVar_69630;
	BIT_VEC cppVar_69631;
	BIT_VEC cppVar_69632;
	bool cppVar_69633;
	BIT_VEC cppVar_69635;
	BIT_VEC cppVar_69636;
	BIT_VEC cppVar_69637;
	BIT_VEC cppVar_69638;
	bool cppVar_69639;
	BIT_VEC cppVar_69641;
	BIT_VEC cppVar_69642;
	BIT_VEC cppVar_69643;
	BIT_VEC cppVar_69644;
	bool cppVar_69645;
	BIT_VEC cppVar_69647;
	BIT_VEC cppVar_69648;
	BIT_VEC cppVar_69649;
	BIT_VEC cppVar_69650;
	bool cppVar_69651;
	BIT_VEC cppVar_69653;
	BIT_VEC cppVar_69654;
	BIT_VEC cppVar_69655;
	BIT_VEC cppVar_69656;
	bool cppVar_69657;
	BIT_VEC cppVar_69659;
	BIT_VEC cppVar_69660;
	BIT_VEC cppVar_69661;
	BIT_VEC cppVar_69662;
	bool cppVar_69663;
	BIT_VEC cppVar_69665;
	BIT_VEC cppVar_69666;
	BIT_VEC cppVar_69667;
	BIT_VEC cppVar_69668;
	bool cppVar_69669;
	BIT_VEC cppVar_69671;
	BIT_VEC cppVar_69672;
	BIT_VEC cppVar_69673;
	BIT_VEC cppVar_69674;
	bool cppVar_69675;
	BIT_VEC cppVar_69677;
	BIT_VEC cppVar_69678;
	BIT_VEC cppVar_69679;
	BIT_VEC cppVar_69680;
	bool cppVar_69681;
	BIT_VEC cppVar_69683;
	BIT_VEC cppVar_69684;
	BIT_VEC cppVar_69685;
	BIT_VEC cppVar_69686;
	bool cppVar_69687;
	BIT_VEC cppVar_69689;
	BIT_VEC cppVar_69690;
	BIT_VEC cppVar_69691;
	BIT_VEC cppVar_69692;
	bool cppVar_69693;
	BIT_VEC cppVar_69695;
	BIT_VEC cppVar_69696;
	BIT_VEC cppVar_69697;
	BIT_VEC cppVar_69698;
	bool cppVar_69699;
	BIT_VEC cppVar_69701;
	BIT_VEC cppVar_69702;
	BIT_VEC cppVar_69703;
	BIT_VEC cppVar_69704;
	bool cppVar_69705;
	BIT_VEC cppVar_69707;
	BIT_VEC cppVar_69708;
	BIT_VEC cppVar_69709;
	BIT_VEC cppVar_69710;
	bool cppVar_69711;
	BIT_VEC cppVar_69713;
	BIT_VEC cppVar_69714;
	BIT_VEC cppVar_69715;
	BIT_VEC cppVar_69716;
	bool cppVar_69717;
	BIT_VEC cppVar_69719;
	BIT_VEC cppVar_69720;
	BIT_VEC cppVar_69721;
	BIT_VEC cppVar_69722;
	bool cppVar_69723;
	BIT_VEC cppVar_69725;
	BIT_VEC cppVar_69726;
	BIT_VEC cppVar_69727;
	BIT_VEC cppVar_69728;
	bool cppVar_69729;
	BIT_VEC cppVar_69731;
	BIT_VEC cppVar_69732;
	BIT_VEC cppVar_69733;
	BIT_VEC cppVar_69734;
	bool cppVar_69735;
	BIT_VEC cppVar_69737;
	BIT_VEC cppVar_69738;
	BIT_VEC cppVar_69739;
	BIT_VEC cppVar_69740;
	bool cppVar_69741;
	BIT_VEC cppVar_69742;
	BIT_VEC cppVar_69736;
	BIT_VEC cppVar_69730;
	BIT_VEC cppVar_69724;
	BIT_VEC cppVar_69718;
	BIT_VEC cppVar_69712;
	BIT_VEC cppVar_69706;
	BIT_VEC cppVar_69700;
	BIT_VEC cppVar_69694;
	BIT_VEC cppVar_69688;
	BIT_VEC cppVar_69682;
	BIT_VEC cppVar_69676;
	BIT_VEC cppVar_69670;
	BIT_VEC cppVar_69664;
	BIT_VEC cppVar_69658;
	BIT_VEC cppVar_69652;
	BIT_VEC cppVar_69646;
	BIT_VEC cppVar_69640;
	BIT_VEC cppVar_69634;
	BIT_VEC cppVar_69628;
	BIT_VEC cppVar_69622;
	BIT_VEC cppVar_69616;
	BIT_VEC cppVar_69603;
	BIT_VEC cppVar_69597;
	BIT_VEC cppVar_69744;
	BIT_VEC cppVar_69745;
	bool cppVar_69746;
	BIT_VEC cppVar_69748;
	BIT_VEC cppVar_69749;
	BIT_VEC cppVar_69750;
	BIT_VEC cppVar_69751;
	bool cppVar_69752;
	BIT_VEC cppVar_69754;
	BIT_VEC cppVar_69755;
	BIT_VEC cppVar_69756;
	BIT_VEC cppVar_69757;
	BIT_VEC cppVar_69758;
	BIT_VEC cppVar_69759;
	BIT_VEC cppVar_69760;
	bool cppVar_69761;
	BIT_VEC cppVar_69762;
	BIT_VEC cppVar_69763;
	BIT_VEC cppVar_69764;
	BIT_VEC cppVar_69765;
	BIT_VEC cppVar_69767;
	BIT_VEC cppVar_69768;
	BIT_VEC cppVar_69769;
	BIT_VEC cppVar_69770;
	bool cppVar_69771;
	BIT_VEC cppVar_69773;
	BIT_VEC cppVar_69774;
	BIT_VEC cppVar_69775;
	BIT_VEC cppVar_69776;
	bool cppVar_69777;
	BIT_VEC cppVar_69779;
	BIT_VEC cppVar_69780;
	BIT_VEC cppVar_69781;
	BIT_VEC cppVar_69782;
	bool cppVar_69783;
	BIT_VEC cppVar_69785;
	BIT_VEC cppVar_69786;
	BIT_VEC cppVar_69787;
	BIT_VEC cppVar_69788;
	bool cppVar_69789;
	BIT_VEC cppVar_69791;
	BIT_VEC cppVar_69792;
	BIT_VEC cppVar_69793;
	BIT_VEC cppVar_69794;
	bool cppVar_69795;
	BIT_VEC cppVar_69797;
	BIT_VEC cppVar_69798;
	BIT_VEC cppVar_69799;
	BIT_VEC cppVar_69800;
	bool cppVar_69801;
	BIT_VEC cppVar_69803;
	BIT_VEC cppVar_69804;
	BIT_VEC cppVar_69805;
	BIT_VEC cppVar_69806;
	bool cppVar_69807;
	BIT_VEC cppVar_69809;
	BIT_VEC cppVar_69810;
	BIT_VEC cppVar_69811;
	BIT_VEC cppVar_69812;
	bool cppVar_69813;
	BIT_VEC cppVar_69815;
	BIT_VEC cppVar_69816;
	BIT_VEC cppVar_69817;
	BIT_VEC cppVar_69818;
	bool cppVar_69819;
	BIT_VEC cppVar_69821;
	BIT_VEC cppVar_69822;
	BIT_VEC cppVar_69823;
	BIT_VEC cppVar_69824;
	bool cppVar_69825;
	BIT_VEC cppVar_69827;
	BIT_VEC cppVar_69828;
	BIT_VEC cppVar_69829;
	BIT_VEC cppVar_69830;
	bool cppVar_69831;
	BIT_VEC cppVar_69833;
	BIT_VEC cppVar_69834;
	BIT_VEC cppVar_69835;
	BIT_VEC cppVar_69836;
	bool cppVar_69837;
	BIT_VEC cppVar_69839;
	BIT_VEC cppVar_69840;
	BIT_VEC cppVar_69841;
	BIT_VEC cppVar_69842;
	bool cppVar_69843;
	BIT_VEC cppVar_69845;
	BIT_VEC cppVar_69846;
	BIT_VEC cppVar_69847;
	BIT_VEC cppVar_69848;
	bool cppVar_69849;
	BIT_VEC cppVar_69851;
	BIT_VEC cppVar_69852;
	BIT_VEC cppVar_69853;
	BIT_VEC cppVar_69854;
	bool cppVar_69855;
	BIT_VEC cppVar_69857;
	BIT_VEC cppVar_69858;
	BIT_VEC cppVar_69859;
	BIT_VEC cppVar_69860;
	bool cppVar_69861;
	BIT_VEC cppVar_69863;
	BIT_VEC cppVar_69864;
	BIT_VEC cppVar_69865;
	BIT_VEC cppVar_69866;
	bool cppVar_69867;
	BIT_VEC cppVar_69869;
	BIT_VEC cppVar_69870;
	BIT_VEC cppVar_69871;
	BIT_VEC cppVar_69872;
	bool cppVar_69873;
	BIT_VEC cppVar_69875;
	BIT_VEC cppVar_69876;
	BIT_VEC cppVar_69877;
	BIT_VEC cppVar_69878;
	bool cppVar_69879;
	BIT_VEC cppVar_69881;
	BIT_VEC cppVar_69882;
	BIT_VEC cppVar_69883;
	BIT_VEC cppVar_69884;
	bool cppVar_69885;
	BIT_VEC cppVar_69887;
	BIT_VEC cppVar_69888;
	BIT_VEC cppVar_69889;
	BIT_VEC cppVar_69890;
	bool cppVar_69891;
	BIT_VEC cppVar_69892;
	BIT_VEC cppVar_69886;
	BIT_VEC cppVar_69880;
	BIT_VEC cppVar_69874;
	BIT_VEC cppVar_69868;
	BIT_VEC cppVar_69862;
	BIT_VEC cppVar_69856;
	BIT_VEC cppVar_69850;
	BIT_VEC cppVar_69844;
	BIT_VEC cppVar_69838;
	BIT_VEC cppVar_69832;
	BIT_VEC cppVar_69826;
	BIT_VEC cppVar_69820;
	BIT_VEC cppVar_69814;
	BIT_VEC cppVar_69808;
	BIT_VEC cppVar_69802;
	BIT_VEC cppVar_69796;
	BIT_VEC cppVar_69790;
	BIT_VEC cppVar_69784;
	BIT_VEC cppVar_69778;
	BIT_VEC cppVar_69772;
	BIT_VEC cppVar_69766;
	BIT_VEC cppVar_69753;
	BIT_VEC cppVar_69747;
	BIT_VEC cppVar_69894;
	BIT_VEC cppVar_69895;
	bool cppVar_69896;
	BIT_VEC cppVar_69898;
	BIT_VEC cppVar_69899;
	BIT_VEC cppVar_69900;
	BIT_VEC cppVar_69901;
	bool cppVar_69902;
	BIT_VEC cppVar_69904;
	BIT_VEC cppVar_69905;
	BIT_VEC cppVar_69906;
	BIT_VEC cppVar_69907;
	BIT_VEC cppVar_69908;
	BIT_VEC cppVar_69909;
	BIT_VEC cppVar_69910;
	bool cppVar_69911;
	BIT_VEC cppVar_69912;
	BIT_VEC cppVar_69913;
	BIT_VEC cppVar_69914;
	BIT_VEC cppVar_69915;
	BIT_VEC cppVar_69917;
	BIT_VEC cppVar_69918;
	BIT_VEC cppVar_69919;
	BIT_VEC cppVar_69920;
	bool cppVar_69921;
	BIT_VEC cppVar_69923;
	BIT_VEC cppVar_69924;
	BIT_VEC cppVar_69925;
	BIT_VEC cppVar_69926;
	bool cppVar_69927;
	BIT_VEC cppVar_69929;
	BIT_VEC cppVar_69930;
	BIT_VEC cppVar_69931;
	BIT_VEC cppVar_69932;
	bool cppVar_69933;
	BIT_VEC cppVar_69935;
	BIT_VEC cppVar_69936;
	BIT_VEC cppVar_69937;
	BIT_VEC cppVar_69938;
	bool cppVar_69939;
	BIT_VEC cppVar_69941;
	BIT_VEC cppVar_69942;
	BIT_VEC cppVar_69943;
	BIT_VEC cppVar_69944;
	bool cppVar_69945;
	BIT_VEC cppVar_69947;
	BIT_VEC cppVar_69948;
	BIT_VEC cppVar_69949;
	BIT_VEC cppVar_69950;
	bool cppVar_69951;
	BIT_VEC cppVar_69953;
	BIT_VEC cppVar_69954;
	BIT_VEC cppVar_69955;
	BIT_VEC cppVar_69956;
	bool cppVar_69957;
	BIT_VEC cppVar_69959;
	BIT_VEC cppVar_69960;
	BIT_VEC cppVar_69961;
	BIT_VEC cppVar_69962;
	bool cppVar_69963;
	BIT_VEC cppVar_69965;
	BIT_VEC cppVar_69966;
	BIT_VEC cppVar_69967;
	BIT_VEC cppVar_69968;
	bool cppVar_69969;
	BIT_VEC cppVar_69971;
	BIT_VEC cppVar_69972;
	BIT_VEC cppVar_69973;
	BIT_VEC cppVar_69974;
	bool cppVar_69975;
	BIT_VEC cppVar_69977;
	BIT_VEC cppVar_69978;
	BIT_VEC cppVar_69979;
	BIT_VEC cppVar_69980;
	bool cppVar_69981;
	BIT_VEC cppVar_69983;
	BIT_VEC cppVar_69984;
	BIT_VEC cppVar_69985;
	BIT_VEC cppVar_69986;
	bool cppVar_69987;
	BIT_VEC cppVar_69989;
	BIT_VEC cppVar_69990;
	BIT_VEC cppVar_69991;
	BIT_VEC cppVar_69992;
	bool cppVar_69993;
	BIT_VEC cppVar_69995;
	BIT_VEC cppVar_69996;
	BIT_VEC cppVar_69997;
	BIT_VEC cppVar_69998;
	bool cppVar_69999;
	BIT_VEC cppVar_70001;
	BIT_VEC cppVar_70002;
	BIT_VEC cppVar_70003;
	BIT_VEC cppVar_70004;
	bool cppVar_70005;
	BIT_VEC cppVar_70007;
	BIT_VEC cppVar_70008;
	BIT_VEC cppVar_70009;
	BIT_VEC cppVar_70010;
	bool cppVar_70011;
	BIT_VEC cppVar_70013;
	BIT_VEC cppVar_70014;
	BIT_VEC cppVar_70015;
	BIT_VEC cppVar_70016;
	bool cppVar_70017;
	BIT_VEC cppVar_70019;
	BIT_VEC cppVar_70020;
	BIT_VEC cppVar_70021;
	BIT_VEC cppVar_70022;
	bool cppVar_70023;
	BIT_VEC cppVar_70025;
	BIT_VEC cppVar_70026;
	BIT_VEC cppVar_70027;
	BIT_VEC cppVar_70028;
	bool cppVar_70029;
	BIT_VEC cppVar_70031;
	BIT_VEC cppVar_70032;
	BIT_VEC cppVar_70033;
	BIT_VEC cppVar_70034;
	bool cppVar_70035;
	BIT_VEC cppVar_70037;
	BIT_VEC cppVar_70038;
	BIT_VEC cppVar_70039;
	BIT_VEC cppVar_70040;
	bool cppVar_70041;
	BIT_VEC cppVar_70042;
	BIT_VEC cppVar_70036;
	BIT_VEC cppVar_70030;
	BIT_VEC cppVar_70024;
	BIT_VEC cppVar_70018;
	BIT_VEC cppVar_70012;
	BIT_VEC cppVar_70006;
	BIT_VEC cppVar_70000;
	BIT_VEC cppVar_69994;
	BIT_VEC cppVar_69988;
	BIT_VEC cppVar_69982;
	BIT_VEC cppVar_69976;
	BIT_VEC cppVar_69970;
	BIT_VEC cppVar_69964;
	BIT_VEC cppVar_69958;
	BIT_VEC cppVar_69952;
	BIT_VEC cppVar_69946;
	BIT_VEC cppVar_69940;
	BIT_VEC cppVar_69934;
	BIT_VEC cppVar_69928;
	BIT_VEC cppVar_69922;
	BIT_VEC cppVar_69916;
	BIT_VEC cppVar_69903;
	BIT_VEC cppVar_69897;
	BIT_VEC cppVar_70044;
	BIT_VEC cppVar_70045;
	bool cppVar_70046;
	BIT_VEC cppVar_70048;
	BIT_VEC cppVar_70049;
	BIT_VEC cppVar_70050;
	BIT_VEC cppVar_70051;
	bool cppVar_70052;
	BIT_VEC cppVar_70054;
	BIT_VEC cppVar_70055;
	BIT_VEC cppVar_70056;
	BIT_VEC cppVar_70057;
	BIT_VEC cppVar_70058;
	BIT_VEC cppVar_70059;
	BIT_VEC cppVar_70060;
	bool cppVar_70061;
	BIT_VEC cppVar_70062;
	BIT_VEC cppVar_70063;
	BIT_VEC cppVar_70064;
	BIT_VEC cppVar_70065;
	BIT_VEC cppVar_70067;
	BIT_VEC cppVar_70068;
	BIT_VEC cppVar_70069;
	BIT_VEC cppVar_70070;
	bool cppVar_70071;
	BIT_VEC cppVar_70073;
	BIT_VEC cppVar_70074;
	BIT_VEC cppVar_70075;
	BIT_VEC cppVar_70076;
	bool cppVar_70077;
	BIT_VEC cppVar_70079;
	BIT_VEC cppVar_70080;
	BIT_VEC cppVar_70081;
	BIT_VEC cppVar_70082;
	bool cppVar_70083;
	BIT_VEC cppVar_70085;
	BIT_VEC cppVar_70086;
	BIT_VEC cppVar_70087;
	BIT_VEC cppVar_70088;
	bool cppVar_70089;
	BIT_VEC cppVar_70091;
	BIT_VEC cppVar_70092;
	BIT_VEC cppVar_70093;
	BIT_VEC cppVar_70094;
	bool cppVar_70095;
	BIT_VEC cppVar_70097;
	BIT_VEC cppVar_70098;
	BIT_VEC cppVar_70099;
	BIT_VEC cppVar_70100;
	bool cppVar_70101;
	BIT_VEC cppVar_70103;
	BIT_VEC cppVar_70104;
	BIT_VEC cppVar_70105;
	BIT_VEC cppVar_70106;
	bool cppVar_70107;
	BIT_VEC cppVar_70109;
	BIT_VEC cppVar_70110;
	BIT_VEC cppVar_70111;
	BIT_VEC cppVar_70112;
	bool cppVar_70113;
	BIT_VEC cppVar_70115;
	BIT_VEC cppVar_70116;
	BIT_VEC cppVar_70117;
	BIT_VEC cppVar_70118;
	bool cppVar_70119;
	BIT_VEC cppVar_70121;
	BIT_VEC cppVar_70122;
	BIT_VEC cppVar_70123;
	BIT_VEC cppVar_70124;
	bool cppVar_70125;
	BIT_VEC cppVar_70127;
	BIT_VEC cppVar_70128;
	BIT_VEC cppVar_70129;
	BIT_VEC cppVar_70130;
	bool cppVar_70131;
	BIT_VEC cppVar_70133;
	BIT_VEC cppVar_70134;
	BIT_VEC cppVar_70135;
	BIT_VEC cppVar_70136;
	bool cppVar_70137;
	BIT_VEC cppVar_70139;
	BIT_VEC cppVar_70140;
	BIT_VEC cppVar_70141;
	BIT_VEC cppVar_70142;
	bool cppVar_70143;
	BIT_VEC cppVar_70145;
	BIT_VEC cppVar_70146;
	BIT_VEC cppVar_70147;
	BIT_VEC cppVar_70148;
	bool cppVar_70149;
	BIT_VEC cppVar_70151;
	BIT_VEC cppVar_70152;
	BIT_VEC cppVar_70153;
	BIT_VEC cppVar_70154;
	bool cppVar_70155;
	BIT_VEC cppVar_70157;
	BIT_VEC cppVar_70158;
	BIT_VEC cppVar_70159;
	BIT_VEC cppVar_70160;
	bool cppVar_70161;
	BIT_VEC cppVar_70163;
	BIT_VEC cppVar_70164;
	BIT_VEC cppVar_70165;
	BIT_VEC cppVar_70166;
	bool cppVar_70167;
	BIT_VEC cppVar_70169;
	BIT_VEC cppVar_70170;
	BIT_VEC cppVar_70171;
	BIT_VEC cppVar_70172;
	bool cppVar_70173;
	BIT_VEC cppVar_70175;
	BIT_VEC cppVar_70176;
	BIT_VEC cppVar_70177;
	BIT_VEC cppVar_70178;
	bool cppVar_70179;
	BIT_VEC cppVar_70181;
	BIT_VEC cppVar_70182;
	BIT_VEC cppVar_70183;
	BIT_VEC cppVar_70184;
	bool cppVar_70185;
	BIT_VEC cppVar_70187;
	BIT_VEC cppVar_70188;
	BIT_VEC cppVar_70189;
	BIT_VEC cppVar_70190;
	bool cppVar_70191;
	BIT_VEC cppVar_70192;
	BIT_VEC cppVar_70186;
	BIT_VEC cppVar_70180;
	BIT_VEC cppVar_70174;
	BIT_VEC cppVar_70168;
	BIT_VEC cppVar_70162;
	BIT_VEC cppVar_70156;
	BIT_VEC cppVar_70150;
	BIT_VEC cppVar_70144;
	BIT_VEC cppVar_70138;
	BIT_VEC cppVar_70132;
	BIT_VEC cppVar_70126;
	BIT_VEC cppVar_70120;
	BIT_VEC cppVar_70114;
	BIT_VEC cppVar_70108;
	BIT_VEC cppVar_70102;
	BIT_VEC cppVar_70096;
	BIT_VEC cppVar_70090;
	BIT_VEC cppVar_70084;
	BIT_VEC cppVar_70078;
	BIT_VEC cppVar_70072;
	BIT_VEC cppVar_70066;
	BIT_VEC cppVar_70053;
	BIT_VEC cppVar_70047;
	BIT_VEC cppVar_70194;
	BIT_VEC cppVar_70195;
	bool cppVar_70196;
	BIT_VEC cppVar_70198;
	BIT_VEC cppVar_70199;
	BIT_VEC cppVar_70200;
	BIT_VEC cppVar_70201;
	bool cppVar_70202;
	BIT_VEC cppVar_70204;
	BIT_VEC cppVar_70205;
	BIT_VEC cppVar_70206;
	BIT_VEC cppVar_70207;
	BIT_VEC cppVar_70208;
	BIT_VEC cppVar_70209;
	BIT_VEC cppVar_70210;
	bool cppVar_70211;
	BIT_VEC cppVar_70212;
	BIT_VEC cppVar_70213;
	BIT_VEC cppVar_70214;
	BIT_VEC cppVar_70215;
	BIT_VEC cppVar_70217;
	BIT_VEC cppVar_70218;
	BIT_VEC cppVar_70219;
	BIT_VEC cppVar_70220;
	bool cppVar_70221;
	BIT_VEC cppVar_70223;
	BIT_VEC cppVar_70224;
	BIT_VEC cppVar_70225;
	BIT_VEC cppVar_70226;
	bool cppVar_70227;
	BIT_VEC cppVar_70229;
	BIT_VEC cppVar_70230;
	BIT_VEC cppVar_70231;
	BIT_VEC cppVar_70232;
	bool cppVar_70233;
	BIT_VEC cppVar_70235;
	BIT_VEC cppVar_70236;
	BIT_VEC cppVar_70237;
	BIT_VEC cppVar_70238;
	bool cppVar_70239;
	BIT_VEC cppVar_70241;
	BIT_VEC cppVar_70242;
	BIT_VEC cppVar_70243;
	BIT_VEC cppVar_70244;
	bool cppVar_70245;
	BIT_VEC cppVar_70247;
	BIT_VEC cppVar_70248;
	BIT_VEC cppVar_70249;
	BIT_VEC cppVar_70250;
	bool cppVar_70251;
	BIT_VEC cppVar_70253;
	BIT_VEC cppVar_70254;
	BIT_VEC cppVar_70255;
	BIT_VEC cppVar_70256;
	bool cppVar_70257;
	BIT_VEC cppVar_70259;
	BIT_VEC cppVar_70260;
	BIT_VEC cppVar_70261;
	BIT_VEC cppVar_70262;
	bool cppVar_70263;
	BIT_VEC cppVar_70265;
	BIT_VEC cppVar_70266;
	BIT_VEC cppVar_70267;
	BIT_VEC cppVar_70268;
	bool cppVar_70269;
	BIT_VEC cppVar_70271;
	BIT_VEC cppVar_70272;
	BIT_VEC cppVar_70273;
	BIT_VEC cppVar_70274;
	bool cppVar_70275;
	BIT_VEC cppVar_70277;
	BIT_VEC cppVar_70278;
	BIT_VEC cppVar_70279;
	BIT_VEC cppVar_70280;
	bool cppVar_70281;
	BIT_VEC cppVar_70283;
	BIT_VEC cppVar_70284;
	BIT_VEC cppVar_70285;
	BIT_VEC cppVar_70286;
	bool cppVar_70287;
	BIT_VEC cppVar_70289;
	BIT_VEC cppVar_70290;
	BIT_VEC cppVar_70291;
	BIT_VEC cppVar_70292;
	bool cppVar_70293;
	BIT_VEC cppVar_70295;
	BIT_VEC cppVar_70296;
	BIT_VEC cppVar_70297;
	BIT_VEC cppVar_70298;
	bool cppVar_70299;
	BIT_VEC cppVar_70301;
	BIT_VEC cppVar_70302;
	BIT_VEC cppVar_70303;
	BIT_VEC cppVar_70304;
	bool cppVar_70305;
	BIT_VEC cppVar_70307;
	BIT_VEC cppVar_70308;
	BIT_VEC cppVar_70309;
	BIT_VEC cppVar_70310;
	bool cppVar_70311;
	BIT_VEC cppVar_70313;
	BIT_VEC cppVar_70314;
	BIT_VEC cppVar_70315;
	BIT_VEC cppVar_70316;
	bool cppVar_70317;
	BIT_VEC cppVar_70319;
	BIT_VEC cppVar_70320;
	BIT_VEC cppVar_70321;
	BIT_VEC cppVar_70322;
	bool cppVar_70323;
	BIT_VEC cppVar_70325;
	BIT_VEC cppVar_70326;
	BIT_VEC cppVar_70327;
	BIT_VEC cppVar_70328;
	bool cppVar_70329;
	BIT_VEC cppVar_70331;
	BIT_VEC cppVar_70332;
	BIT_VEC cppVar_70333;
	BIT_VEC cppVar_70334;
	bool cppVar_70335;
	BIT_VEC cppVar_70337;
	BIT_VEC cppVar_70338;
	BIT_VEC cppVar_70339;
	BIT_VEC cppVar_70340;
	bool cppVar_70341;
	BIT_VEC cppVar_70342;
	BIT_VEC cppVar_70336;
	BIT_VEC cppVar_70330;
	BIT_VEC cppVar_70324;
	BIT_VEC cppVar_70318;
	BIT_VEC cppVar_70312;
	BIT_VEC cppVar_70306;
	BIT_VEC cppVar_70300;
	BIT_VEC cppVar_70294;
	BIT_VEC cppVar_70288;
	BIT_VEC cppVar_70282;
	BIT_VEC cppVar_70276;
	BIT_VEC cppVar_70270;
	BIT_VEC cppVar_70264;
	BIT_VEC cppVar_70258;
	BIT_VEC cppVar_70252;
	BIT_VEC cppVar_70246;
	BIT_VEC cppVar_70240;
	BIT_VEC cppVar_70234;
	BIT_VEC cppVar_70228;
	BIT_VEC cppVar_70222;
	BIT_VEC cppVar_70216;
	BIT_VEC cppVar_70203;
	BIT_VEC cppVar_70197;
	BIT_VEC cppVar_70344;
	BIT_VEC cppVar_70345;
	bool cppVar_70346;
	BIT_VEC cppVar_70348;
	BIT_VEC cppVar_70349;
	BIT_VEC cppVar_70350;
	BIT_VEC cppVar_70351;
	bool cppVar_70352;
	BIT_VEC cppVar_70354;
	BIT_VEC cppVar_70355;
	BIT_VEC cppVar_70356;
	BIT_VEC cppVar_70357;
	BIT_VEC cppVar_70358;
	BIT_VEC cppVar_70359;
	BIT_VEC cppVar_70360;
	bool cppVar_70361;
	BIT_VEC cppVar_70362;
	BIT_VEC cppVar_70363;
	BIT_VEC cppVar_70364;
	BIT_VEC cppVar_70365;
	BIT_VEC cppVar_70367;
	BIT_VEC cppVar_70368;
	BIT_VEC cppVar_70369;
	BIT_VEC cppVar_70370;
	bool cppVar_70371;
	BIT_VEC cppVar_70373;
	BIT_VEC cppVar_70374;
	BIT_VEC cppVar_70375;
	BIT_VEC cppVar_70376;
	bool cppVar_70377;
	BIT_VEC cppVar_70379;
	BIT_VEC cppVar_70380;
	BIT_VEC cppVar_70381;
	BIT_VEC cppVar_70382;
	bool cppVar_70383;
	BIT_VEC cppVar_70385;
	BIT_VEC cppVar_70386;
	BIT_VEC cppVar_70387;
	BIT_VEC cppVar_70388;
	bool cppVar_70389;
	BIT_VEC cppVar_70391;
	BIT_VEC cppVar_70392;
	BIT_VEC cppVar_70393;
	BIT_VEC cppVar_70394;
	bool cppVar_70395;
	BIT_VEC cppVar_70397;
	BIT_VEC cppVar_70398;
	BIT_VEC cppVar_70399;
	BIT_VEC cppVar_70400;
	bool cppVar_70401;
	BIT_VEC cppVar_70403;
	BIT_VEC cppVar_70404;
	BIT_VEC cppVar_70405;
	BIT_VEC cppVar_70406;
	bool cppVar_70407;
	BIT_VEC cppVar_70409;
	BIT_VEC cppVar_70410;
	BIT_VEC cppVar_70411;
	BIT_VEC cppVar_70412;
	bool cppVar_70413;
	BIT_VEC cppVar_70415;
	BIT_VEC cppVar_70416;
	BIT_VEC cppVar_70417;
	BIT_VEC cppVar_70418;
	bool cppVar_70419;
	BIT_VEC cppVar_70421;
	BIT_VEC cppVar_70422;
	BIT_VEC cppVar_70423;
	BIT_VEC cppVar_70424;
	bool cppVar_70425;
	BIT_VEC cppVar_70427;
	BIT_VEC cppVar_70428;
	BIT_VEC cppVar_70429;
	BIT_VEC cppVar_70430;
	bool cppVar_70431;
	BIT_VEC cppVar_70433;
	BIT_VEC cppVar_70434;
	BIT_VEC cppVar_70435;
	BIT_VEC cppVar_70436;
	bool cppVar_70437;
	BIT_VEC cppVar_70439;
	BIT_VEC cppVar_70440;
	BIT_VEC cppVar_70441;
	BIT_VEC cppVar_70442;
	bool cppVar_70443;
	BIT_VEC cppVar_70445;
	BIT_VEC cppVar_70446;
	BIT_VEC cppVar_70447;
	BIT_VEC cppVar_70448;
	bool cppVar_70449;
	BIT_VEC cppVar_70451;
	BIT_VEC cppVar_70452;
	BIT_VEC cppVar_70453;
	BIT_VEC cppVar_70454;
	bool cppVar_70455;
	BIT_VEC cppVar_70457;
	BIT_VEC cppVar_70458;
	BIT_VEC cppVar_70459;
	BIT_VEC cppVar_70460;
	bool cppVar_70461;
	BIT_VEC cppVar_70463;
	BIT_VEC cppVar_70464;
	BIT_VEC cppVar_70465;
	BIT_VEC cppVar_70466;
	bool cppVar_70467;
	BIT_VEC cppVar_70469;
	BIT_VEC cppVar_70470;
	BIT_VEC cppVar_70471;
	BIT_VEC cppVar_70472;
	bool cppVar_70473;
	BIT_VEC cppVar_70475;
	BIT_VEC cppVar_70476;
	BIT_VEC cppVar_70477;
	BIT_VEC cppVar_70478;
	bool cppVar_70479;
	BIT_VEC cppVar_70481;
	BIT_VEC cppVar_70482;
	BIT_VEC cppVar_70483;
	BIT_VEC cppVar_70484;
	bool cppVar_70485;
	BIT_VEC cppVar_70487;
	BIT_VEC cppVar_70488;
	BIT_VEC cppVar_70489;
	BIT_VEC cppVar_70490;
	bool cppVar_70491;
	BIT_VEC cppVar_70492;
	BIT_VEC cppVar_70486;
	BIT_VEC cppVar_70480;
	BIT_VEC cppVar_70474;
	BIT_VEC cppVar_70468;
	BIT_VEC cppVar_70462;
	BIT_VEC cppVar_70456;
	BIT_VEC cppVar_70450;
	BIT_VEC cppVar_70444;
	BIT_VEC cppVar_70438;
	BIT_VEC cppVar_70432;
	BIT_VEC cppVar_70426;
	BIT_VEC cppVar_70420;
	BIT_VEC cppVar_70414;
	BIT_VEC cppVar_70408;
	BIT_VEC cppVar_70402;
	BIT_VEC cppVar_70396;
	BIT_VEC cppVar_70390;
	BIT_VEC cppVar_70384;
	BIT_VEC cppVar_70378;
	BIT_VEC cppVar_70372;
	BIT_VEC cppVar_70366;
	BIT_VEC cppVar_70353;
	BIT_VEC cppVar_70347;
	BIT_VEC cppVar_70494;
	BIT_VEC cppVar_70495;
	bool cppVar_70496;
	BIT_VEC cppVar_70498;
	BIT_VEC cppVar_70499;
	BIT_VEC cppVar_70500;
	BIT_VEC cppVar_70501;
	bool cppVar_70502;
	BIT_VEC cppVar_70504;
	BIT_VEC cppVar_70505;
	BIT_VEC cppVar_70506;
	BIT_VEC cppVar_70507;
	BIT_VEC cppVar_70508;
	BIT_VEC cppVar_70509;
	BIT_VEC cppVar_70510;
	bool cppVar_70511;
	BIT_VEC cppVar_70512;
	BIT_VEC cppVar_70513;
	BIT_VEC cppVar_70514;
	BIT_VEC cppVar_70515;
	BIT_VEC cppVar_70517;
	BIT_VEC cppVar_70518;
	BIT_VEC cppVar_70519;
	BIT_VEC cppVar_70520;
	bool cppVar_70521;
	BIT_VEC cppVar_70523;
	BIT_VEC cppVar_70524;
	BIT_VEC cppVar_70525;
	BIT_VEC cppVar_70526;
	bool cppVar_70527;
	BIT_VEC cppVar_70529;
	BIT_VEC cppVar_70530;
	BIT_VEC cppVar_70531;
	BIT_VEC cppVar_70532;
	bool cppVar_70533;
	BIT_VEC cppVar_70535;
	BIT_VEC cppVar_70536;
	BIT_VEC cppVar_70537;
	BIT_VEC cppVar_70538;
	bool cppVar_70539;
	BIT_VEC cppVar_70541;
	BIT_VEC cppVar_70542;
	BIT_VEC cppVar_70543;
	BIT_VEC cppVar_70544;
	bool cppVar_70545;
	BIT_VEC cppVar_70547;
	BIT_VEC cppVar_70548;
	BIT_VEC cppVar_70549;
	BIT_VEC cppVar_70550;
	bool cppVar_70551;
	BIT_VEC cppVar_70553;
	BIT_VEC cppVar_70554;
	BIT_VEC cppVar_70555;
	BIT_VEC cppVar_70556;
	bool cppVar_70557;
	BIT_VEC cppVar_70559;
	BIT_VEC cppVar_70560;
	BIT_VEC cppVar_70561;
	BIT_VEC cppVar_70562;
	bool cppVar_70563;
	BIT_VEC cppVar_70565;
	BIT_VEC cppVar_70566;
	BIT_VEC cppVar_70567;
	BIT_VEC cppVar_70568;
	bool cppVar_70569;
	BIT_VEC cppVar_70571;
	BIT_VEC cppVar_70572;
	BIT_VEC cppVar_70573;
	BIT_VEC cppVar_70574;
	bool cppVar_70575;
	BIT_VEC cppVar_70577;
	BIT_VEC cppVar_70578;
	BIT_VEC cppVar_70579;
	BIT_VEC cppVar_70580;
	bool cppVar_70581;
	BIT_VEC cppVar_70583;
	BIT_VEC cppVar_70584;
	BIT_VEC cppVar_70585;
	BIT_VEC cppVar_70586;
	bool cppVar_70587;
	BIT_VEC cppVar_70589;
	BIT_VEC cppVar_70590;
	BIT_VEC cppVar_70591;
	BIT_VEC cppVar_70592;
	bool cppVar_70593;
	BIT_VEC cppVar_70595;
	BIT_VEC cppVar_70596;
	BIT_VEC cppVar_70597;
	BIT_VEC cppVar_70598;
	bool cppVar_70599;
	BIT_VEC cppVar_70601;
	BIT_VEC cppVar_70602;
	BIT_VEC cppVar_70603;
	BIT_VEC cppVar_70604;
	bool cppVar_70605;
	BIT_VEC cppVar_70607;
	BIT_VEC cppVar_70608;
	BIT_VEC cppVar_70609;
	BIT_VEC cppVar_70610;
	bool cppVar_70611;
	BIT_VEC cppVar_70613;
	BIT_VEC cppVar_70614;
	BIT_VEC cppVar_70615;
	BIT_VEC cppVar_70616;
	bool cppVar_70617;
	BIT_VEC cppVar_70619;
	BIT_VEC cppVar_70620;
	BIT_VEC cppVar_70621;
	BIT_VEC cppVar_70622;
	bool cppVar_70623;
	BIT_VEC cppVar_70625;
	BIT_VEC cppVar_70626;
	BIT_VEC cppVar_70627;
	BIT_VEC cppVar_70628;
	bool cppVar_70629;
	BIT_VEC cppVar_70631;
	BIT_VEC cppVar_70632;
	BIT_VEC cppVar_70633;
	BIT_VEC cppVar_70634;
	bool cppVar_70635;
	BIT_VEC cppVar_70637;
	BIT_VEC cppVar_70638;
	BIT_VEC cppVar_70639;
	BIT_VEC cppVar_70640;
	bool cppVar_70641;
	BIT_VEC cppVar_70642;
	BIT_VEC cppVar_70636;
	BIT_VEC cppVar_70630;
	BIT_VEC cppVar_70624;
	BIT_VEC cppVar_70618;
	BIT_VEC cppVar_70612;
	BIT_VEC cppVar_70606;
	BIT_VEC cppVar_70600;
	BIT_VEC cppVar_70594;
	BIT_VEC cppVar_70588;
	BIT_VEC cppVar_70582;
	BIT_VEC cppVar_70576;
	BIT_VEC cppVar_70570;
	BIT_VEC cppVar_70564;
	BIT_VEC cppVar_70558;
	BIT_VEC cppVar_70552;
	BIT_VEC cppVar_70546;
	BIT_VEC cppVar_70540;
	BIT_VEC cppVar_70534;
	BIT_VEC cppVar_70528;
	BIT_VEC cppVar_70522;
	BIT_VEC cppVar_70516;
	BIT_VEC cppVar_70503;
	BIT_VEC cppVar_70497;
	BIT_VEC cppVar_70644;
	BIT_VEC cppVar_70645;
	bool cppVar_70646;
	BIT_VEC cppVar_70648;
	BIT_VEC cppVar_70649;
	BIT_VEC cppVar_70650;
	BIT_VEC cppVar_70651;
	bool cppVar_70652;
	BIT_VEC cppVar_70654;
	BIT_VEC cppVar_70655;
	BIT_VEC cppVar_70656;
	BIT_VEC cppVar_70657;
	BIT_VEC cppVar_70658;
	BIT_VEC cppVar_70659;
	BIT_VEC cppVar_70660;
	bool cppVar_70661;
	BIT_VEC cppVar_70662;
	BIT_VEC cppVar_70663;
	BIT_VEC cppVar_70664;
	BIT_VEC cppVar_70665;
	BIT_VEC cppVar_70667;
	BIT_VEC cppVar_70668;
	BIT_VEC cppVar_70669;
	BIT_VEC cppVar_70670;
	bool cppVar_70671;
	BIT_VEC cppVar_70673;
	BIT_VEC cppVar_70674;
	BIT_VEC cppVar_70675;
	BIT_VEC cppVar_70676;
	bool cppVar_70677;
	BIT_VEC cppVar_70679;
	BIT_VEC cppVar_70680;
	BIT_VEC cppVar_70681;
	BIT_VEC cppVar_70682;
	bool cppVar_70683;
	BIT_VEC cppVar_70685;
	BIT_VEC cppVar_70686;
	BIT_VEC cppVar_70687;
	BIT_VEC cppVar_70688;
	bool cppVar_70689;
	BIT_VEC cppVar_70691;
	BIT_VEC cppVar_70692;
	BIT_VEC cppVar_70693;
	BIT_VEC cppVar_70694;
	bool cppVar_70695;
	BIT_VEC cppVar_70697;
	BIT_VEC cppVar_70698;
	BIT_VEC cppVar_70699;
	BIT_VEC cppVar_70700;
	bool cppVar_70701;
	BIT_VEC cppVar_70703;
	BIT_VEC cppVar_70704;
	BIT_VEC cppVar_70705;
	BIT_VEC cppVar_70706;
	bool cppVar_70707;
	BIT_VEC cppVar_70709;
	BIT_VEC cppVar_70710;
	BIT_VEC cppVar_70711;
	BIT_VEC cppVar_70712;
	bool cppVar_70713;
	BIT_VEC cppVar_70715;
	BIT_VEC cppVar_70716;
	BIT_VEC cppVar_70717;
	BIT_VEC cppVar_70718;
	bool cppVar_70719;
	BIT_VEC cppVar_70721;
	BIT_VEC cppVar_70722;
	BIT_VEC cppVar_70723;
	BIT_VEC cppVar_70724;
	bool cppVar_70725;
	BIT_VEC cppVar_70727;
	BIT_VEC cppVar_70728;
	BIT_VEC cppVar_70729;
	BIT_VEC cppVar_70730;
	bool cppVar_70731;
	BIT_VEC cppVar_70733;
	BIT_VEC cppVar_70734;
	BIT_VEC cppVar_70735;
	BIT_VEC cppVar_70736;
	bool cppVar_70737;
	BIT_VEC cppVar_70739;
	BIT_VEC cppVar_70740;
	BIT_VEC cppVar_70741;
	BIT_VEC cppVar_70742;
	bool cppVar_70743;
	BIT_VEC cppVar_70745;
	BIT_VEC cppVar_70746;
	BIT_VEC cppVar_70747;
	BIT_VEC cppVar_70748;
	bool cppVar_70749;
	BIT_VEC cppVar_70751;
	BIT_VEC cppVar_70752;
	BIT_VEC cppVar_70753;
	BIT_VEC cppVar_70754;
	bool cppVar_70755;
	BIT_VEC cppVar_70757;
	BIT_VEC cppVar_70758;
	BIT_VEC cppVar_70759;
	BIT_VEC cppVar_70760;
	bool cppVar_70761;
	BIT_VEC cppVar_70763;
	BIT_VEC cppVar_70764;
	BIT_VEC cppVar_70765;
	BIT_VEC cppVar_70766;
	bool cppVar_70767;
	BIT_VEC cppVar_70769;
	BIT_VEC cppVar_70770;
	BIT_VEC cppVar_70771;
	BIT_VEC cppVar_70772;
	bool cppVar_70773;
	BIT_VEC cppVar_70775;
	BIT_VEC cppVar_70776;
	BIT_VEC cppVar_70777;
	BIT_VEC cppVar_70778;
	bool cppVar_70779;
	BIT_VEC cppVar_70781;
	BIT_VEC cppVar_70782;
	BIT_VEC cppVar_70783;
	BIT_VEC cppVar_70784;
	bool cppVar_70785;
	BIT_VEC cppVar_70787;
	BIT_VEC cppVar_70788;
	BIT_VEC cppVar_70789;
	BIT_VEC cppVar_70790;
	bool cppVar_70791;
	BIT_VEC cppVar_70792;
	BIT_VEC cppVar_70786;
	BIT_VEC cppVar_70780;
	BIT_VEC cppVar_70774;
	BIT_VEC cppVar_70768;
	BIT_VEC cppVar_70762;
	BIT_VEC cppVar_70756;
	BIT_VEC cppVar_70750;
	BIT_VEC cppVar_70744;
	BIT_VEC cppVar_70738;
	BIT_VEC cppVar_70732;
	BIT_VEC cppVar_70726;
	BIT_VEC cppVar_70720;
	BIT_VEC cppVar_70714;
	BIT_VEC cppVar_70708;
	BIT_VEC cppVar_70702;
	BIT_VEC cppVar_70696;
	BIT_VEC cppVar_70690;
	BIT_VEC cppVar_70684;
	BIT_VEC cppVar_70678;
	BIT_VEC cppVar_70672;
	BIT_VEC cppVar_70666;
	BIT_VEC cppVar_70653;
	BIT_VEC cppVar_70647;
	BIT_VEC cppVar_70794;
	BIT_VEC cppVar_70795;
	bool cppVar_70796;
	BIT_VEC cppVar_70798;
	BIT_VEC cppVar_70799;
	BIT_VEC cppVar_70800;
	BIT_VEC cppVar_70801;
	bool cppVar_70802;
	BIT_VEC cppVar_70803;
	BIT_VEC cppVar_70804;
	BIT_VEC cppVar_70805;
	BIT_VEC cppVar_70806;
	BIT_VEC cppVar_70807;
	BIT_VEC cppVar_70808;
	BIT_VEC cppVar_70809;
	BIT_VEC cppVar_70797;
	BIT_VEC cppVar_70811;
	BIT_VEC cppVar_70812;
	bool cppVar_70813;
	BIT_VEC cppVar_70815;
	BIT_VEC cppVar_70816;
	BIT_VEC cppVar_70817;
	BIT_VEC cppVar_70818;
	bool cppVar_70819;
	BIT_VEC cppVar_70820;
	BIT_VEC cppVar_70821;
	BIT_VEC cppVar_70822;
	BIT_VEC cppVar_70823;
	BIT_VEC cppVar_70824;
	BIT_VEC cppVar_70825;
	BIT_VEC cppVar_70826;
	BIT_VEC cppVar_70814;
	BIT_VEC cppVar_70828;
	BIT_VEC cppVar_70829;
	bool cppVar_70830;
	BIT_VEC cppVar_70832;
	BIT_VEC cppVar_70833;
	BIT_VEC cppVar_70834;
	BIT_VEC cppVar_70835;
	bool cppVar_70836;
	BIT_VEC cppVar_70838;
	BIT_VEC cppVar_70839;
	BIT_VEC cppVar_70840;
	BIT_VEC cppVar_70841;
	BIT_VEC cppVar_70842;
	bool cppVar_70843;
	BIT_VEC cppVar_70844;
	BIT_VEC cppVar_70845;
	BIT_VEC cppVar_70846;
	BIT_VEC cppVar_70848;
	BIT_VEC cppVar_70849;
	BIT_VEC cppVar_70850;
	bool cppVar_70851;
	BIT_VEC cppVar_70853;
	BIT_VEC cppVar_70854;
	BIT_VEC cppVar_70855;
	bool cppVar_70856;
	BIT_VEC cppVar_70858;
	BIT_VEC cppVar_70859;
	BIT_VEC cppVar_70860;
	bool cppVar_70861;
	BIT_VEC cppVar_70863;
	BIT_VEC cppVar_70864;
	BIT_VEC cppVar_70865;
	bool cppVar_70866;
	BIT_VEC cppVar_70868;
	BIT_VEC cppVar_70869;
	BIT_VEC cppVar_70870;
	bool cppVar_70871;
	BIT_VEC cppVar_70873;
	BIT_VEC cppVar_70874;
	BIT_VEC cppVar_70875;
	bool cppVar_70876;
	BIT_VEC cppVar_70878;
	BIT_VEC cppVar_70879;
	BIT_VEC cppVar_70880;
	bool cppVar_70881;
	BIT_VEC cppVar_70883;
	BIT_VEC cppVar_70884;
	BIT_VEC cppVar_70885;
	bool cppVar_70886;
	BIT_VEC cppVar_70888;
	BIT_VEC cppVar_70889;
	BIT_VEC cppVar_70890;
	bool cppVar_70891;
	BIT_VEC cppVar_70893;
	BIT_VEC cppVar_70894;
	BIT_VEC cppVar_70895;
	bool cppVar_70896;
	BIT_VEC cppVar_70898;
	BIT_VEC cppVar_70899;
	BIT_VEC cppVar_70900;
	bool cppVar_70901;
	BIT_VEC cppVar_70903;
	BIT_VEC cppVar_70904;
	BIT_VEC cppVar_70905;
	bool cppVar_70906;
	BIT_VEC cppVar_70908;
	BIT_VEC cppVar_70909;
	BIT_VEC cppVar_70910;
	bool cppVar_70911;
	BIT_VEC cppVar_70913;
	BIT_VEC cppVar_70914;
	BIT_VEC cppVar_70915;
	bool cppVar_70916;
	BIT_VEC cppVar_70918;
	BIT_VEC cppVar_70919;
	BIT_VEC cppVar_70920;
	bool cppVar_70921;
	BIT_VEC cppVar_70923;
	BIT_VEC cppVar_70924;
	BIT_VEC cppVar_70925;
	bool cppVar_70926;
	BIT_VEC cppVar_70928;
	BIT_VEC cppVar_70929;
	BIT_VEC cppVar_70930;
	bool cppVar_70931;
	BIT_VEC cppVar_70933;
	BIT_VEC cppVar_70934;
	BIT_VEC cppVar_70935;
	bool cppVar_70936;
	BIT_VEC cppVar_70938;
	BIT_VEC cppVar_70939;
	BIT_VEC cppVar_70940;
	bool cppVar_70941;
	BIT_VEC cppVar_70943;
	BIT_VEC cppVar_70944;
	BIT_VEC cppVar_70945;
	bool cppVar_70946;
	BIT_VEC cppVar_70948;
	BIT_VEC cppVar_70949;
	BIT_VEC cppVar_70950;
	bool cppVar_70951;
	BIT_VEC cppVar_70952;
	BIT_VEC cppVar_70947;
	BIT_VEC cppVar_70942;
	BIT_VEC cppVar_70937;
	BIT_VEC cppVar_70932;
	BIT_VEC cppVar_70927;
	BIT_VEC cppVar_70922;
	BIT_VEC cppVar_70917;
	BIT_VEC cppVar_70912;
	BIT_VEC cppVar_70907;
	BIT_VEC cppVar_70902;
	BIT_VEC cppVar_70897;
	BIT_VEC cppVar_70892;
	BIT_VEC cppVar_70887;
	BIT_VEC cppVar_70882;
	BIT_VEC cppVar_70877;
	BIT_VEC cppVar_70872;
	BIT_VEC cppVar_70867;
	BIT_VEC cppVar_70862;
	BIT_VEC cppVar_70857;
	BIT_VEC cppVar_70852;
	BIT_VEC cppVar_70847;
	BIT_VEC cppVar_70837;
	BIT_VEC cppVar_70831;
	BIT_VEC cppVar_70954;
	BIT_VEC cppVar_70955;
	bool cppVar_70956;
	BIT_VEC cppVar_70958;
	BIT_VEC cppVar_70959;
	BIT_VEC cppVar_70960;
	BIT_VEC cppVar_70961;
	bool cppVar_70962;
	BIT_VEC cppVar_70963;
	BIT_VEC cppVar_70964;
	BIT_VEC cppVar_70965;
	BIT_VEC cppVar_70957;
	BIT_VEC cppVar_70967;
	BIT_VEC cppVar_70968;
	bool cppVar_70969;
	BIT_VEC cppVar_70971;
	BIT_VEC cppVar_70972;
	BIT_VEC cppVar_70973;
	BIT_VEC cppVar_70974;
	bool cppVar_70975;
	BIT_VEC cppVar_70977;
	BIT_VEC cppVar_70978;
	BIT_VEC cppVar_70979;
	BIT_VEC cppVar_70980;
	bool cppVar_70981;
	BIT_VEC cppVar_70982;
	BIT_VEC cppVar_70983;
	BIT_VEC cppVar_70984;
	BIT_VEC cppVar_70986;
	BIT_VEC cppVar_70987;
	BIT_VEC cppVar_70988;
	bool cppVar_70989;
	BIT_VEC cppVar_70991;
	BIT_VEC cppVar_70992;
	BIT_VEC cppVar_70993;
	bool cppVar_70994;
	BIT_VEC cppVar_70996;
	BIT_VEC cppVar_70997;
	BIT_VEC cppVar_70998;
	bool cppVar_70999;
	BIT_VEC cppVar_71001;
	BIT_VEC cppVar_71002;
	BIT_VEC cppVar_71003;
	bool cppVar_71004;
	BIT_VEC cppVar_71006;
	BIT_VEC cppVar_71007;
	BIT_VEC cppVar_71008;
	bool cppVar_71009;
	BIT_VEC cppVar_71011;
	BIT_VEC cppVar_71012;
	BIT_VEC cppVar_71013;
	bool cppVar_71014;
	BIT_VEC cppVar_71016;
	BIT_VEC cppVar_71017;
	BIT_VEC cppVar_71018;
	bool cppVar_71019;
	BIT_VEC cppVar_71021;
	BIT_VEC cppVar_71022;
	BIT_VEC cppVar_71023;
	bool cppVar_71024;
	BIT_VEC cppVar_71026;
	BIT_VEC cppVar_71027;
	BIT_VEC cppVar_71028;
	bool cppVar_71029;
	BIT_VEC cppVar_71031;
	BIT_VEC cppVar_71032;
	BIT_VEC cppVar_71033;
	bool cppVar_71034;
	BIT_VEC cppVar_71036;
	BIT_VEC cppVar_71037;
	BIT_VEC cppVar_71038;
	bool cppVar_71039;
	BIT_VEC cppVar_71041;
	BIT_VEC cppVar_71042;
	BIT_VEC cppVar_71043;
	bool cppVar_71044;
	BIT_VEC cppVar_71046;
	BIT_VEC cppVar_71047;
	BIT_VEC cppVar_71048;
	bool cppVar_71049;
	BIT_VEC cppVar_71051;
	BIT_VEC cppVar_71052;
	BIT_VEC cppVar_71053;
	bool cppVar_71054;
	BIT_VEC cppVar_71056;
	BIT_VEC cppVar_71057;
	BIT_VEC cppVar_71058;
	bool cppVar_71059;
	BIT_VEC cppVar_71061;
	BIT_VEC cppVar_71062;
	BIT_VEC cppVar_71063;
	bool cppVar_71064;
	BIT_VEC cppVar_71066;
	BIT_VEC cppVar_71067;
	BIT_VEC cppVar_71068;
	bool cppVar_71069;
	BIT_VEC cppVar_71071;
	BIT_VEC cppVar_71072;
	BIT_VEC cppVar_71073;
	bool cppVar_71074;
	BIT_VEC cppVar_71076;
	BIT_VEC cppVar_71077;
	BIT_VEC cppVar_71078;
	bool cppVar_71079;
	BIT_VEC cppVar_71081;
	BIT_VEC cppVar_71082;
	BIT_VEC cppVar_71083;
	bool cppVar_71084;
	BIT_VEC cppVar_71086;
	BIT_VEC cppVar_71087;
	BIT_VEC cppVar_71088;
	bool cppVar_71089;
	BIT_VEC cppVar_71090;
	BIT_VEC cppVar_71085;
	BIT_VEC cppVar_71080;
	BIT_VEC cppVar_71075;
	BIT_VEC cppVar_71070;
	BIT_VEC cppVar_71065;
	BIT_VEC cppVar_71060;
	BIT_VEC cppVar_71055;
	BIT_VEC cppVar_71050;
	BIT_VEC cppVar_71045;
	BIT_VEC cppVar_71040;
	BIT_VEC cppVar_71035;
	BIT_VEC cppVar_71030;
	BIT_VEC cppVar_71025;
	BIT_VEC cppVar_71020;
	BIT_VEC cppVar_71015;
	BIT_VEC cppVar_71010;
	BIT_VEC cppVar_71005;
	BIT_VEC cppVar_71000;
	BIT_VEC cppVar_70995;
	BIT_VEC cppVar_70990;
	BIT_VEC cppVar_70985;
	BIT_VEC cppVar_70976;
	BIT_VEC cppVar_71091;
	BIT_VEC cppVar_71092;
	BIT_VEC cppVar_71093;
	BIT_VEC cppVar_71094;
	BIT_VEC cppVar_70970;
	BIT_VEC cppVar_71096;
	BIT_VEC cppVar_71097;
	bool cppVar_71098;
	BIT_VEC cppVar_71100;
	BIT_VEC cppVar_71101;
	BIT_VEC cppVar_71102;
	BIT_VEC cppVar_71103;
	bool cppVar_71104;
	BIT_VEC cppVar_71106;
	BIT_VEC cppVar_71107;
	BIT_VEC cppVar_71108;
	BIT_VEC cppVar_71109;
	bool cppVar_71110;
	BIT_VEC cppVar_71111;
	BIT_VEC cppVar_71112;
	BIT_VEC cppVar_71113;
	BIT_VEC cppVar_71115;
	BIT_VEC cppVar_71116;
	BIT_VEC cppVar_71117;
	bool cppVar_71118;
	BIT_VEC cppVar_71120;
	BIT_VEC cppVar_71121;
	BIT_VEC cppVar_71122;
	bool cppVar_71123;
	BIT_VEC cppVar_71125;
	BIT_VEC cppVar_71126;
	BIT_VEC cppVar_71127;
	bool cppVar_71128;
	BIT_VEC cppVar_71130;
	BIT_VEC cppVar_71131;
	BIT_VEC cppVar_71132;
	bool cppVar_71133;
	BIT_VEC cppVar_71135;
	BIT_VEC cppVar_71136;
	BIT_VEC cppVar_71137;
	bool cppVar_71138;
	BIT_VEC cppVar_71140;
	BIT_VEC cppVar_71141;
	BIT_VEC cppVar_71142;
	bool cppVar_71143;
	BIT_VEC cppVar_71145;
	BIT_VEC cppVar_71146;
	BIT_VEC cppVar_71147;
	bool cppVar_71148;
	BIT_VEC cppVar_71150;
	BIT_VEC cppVar_71151;
	BIT_VEC cppVar_71152;
	bool cppVar_71153;
	BIT_VEC cppVar_71155;
	BIT_VEC cppVar_71156;
	BIT_VEC cppVar_71157;
	bool cppVar_71158;
	BIT_VEC cppVar_71160;
	BIT_VEC cppVar_71161;
	BIT_VEC cppVar_71162;
	bool cppVar_71163;
	BIT_VEC cppVar_71165;
	BIT_VEC cppVar_71166;
	BIT_VEC cppVar_71167;
	bool cppVar_71168;
	BIT_VEC cppVar_71170;
	BIT_VEC cppVar_71171;
	BIT_VEC cppVar_71172;
	bool cppVar_71173;
	BIT_VEC cppVar_71175;
	BIT_VEC cppVar_71176;
	BIT_VEC cppVar_71177;
	bool cppVar_71178;
	BIT_VEC cppVar_71180;
	BIT_VEC cppVar_71181;
	BIT_VEC cppVar_71182;
	bool cppVar_71183;
	BIT_VEC cppVar_71185;
	BIT_VEC cppVar_71186;
	BIT_VEC cppVar_71187;
	bool cppVar_71188;
	BIT_VEC cppVar_71190;
	BIT_VEC cppVar_71191;
	BIT_VEC cppVar_71192;
	bool cppVar_71193;
	BIT_VEC cppVar_71195;
	BIT_VEC cppVar_71196;
	BIT_VEC cppVar_71197;
	bool cppVar_71198;
	BIT_VEC cppVar_71200;
	BIT_VEC cppVar_71201;
	BIT_VEC cppVar_71202;
	bool cppVar_71203;
	BIT_VEC cppVar_71205;
	BIT_VEC cppVar_71206;
	BIT_VEC cppVar_71207;
	bool cppVar_71208;
	BIT_VEC cppVar_71210;
	BIT_VEC cppVar_71211;
	BIT_VEC cppVar_71212;
	bool cppVar_71213;
	BIT_VEC cppVar_71215;
	BIT_VEC cppVar_71216;
	BIT_VEC cppVar_71217;
	bool cppVar_71218;
	BIT_VEC cppVar_71219;
	BIT_VEC cppVar_71214;
	BIT_VEC cppVar_71209;
	BIT_VEC cppVar_71204;
	BIT_VEC cppVar_71199;
	BIT_VEC cppVar_71194;
	BIT_VEC cppVar_71189;
	BIT_VEC cppVar_71184;
	BIT_VEC cppVar_71179;
	BIT_VEC cppVar_71174;
	BIT_VEC cppVar_71169;
	BIT_VEC cppVar_71164;
	BIT_VEC cppVar_71159;
	BIT_VEC cppVar_71154;
	BIT_VEC cppVar_71149;
	BIT_VEC cppVar_71144;
	BIT_VEC cppVar_71139;
	BIT_VEC cppVar_71134;
	BIT_VEC cppVar_71129;
	BIT_VEC cppVar_71124;
	BIT_VEC cppVar_71119;
	BIT_VEC cppVar_71114;
	BIT_VEC cppVar_71105;
	BIT_VEC cppVar_71220;
	BIT_VEC cppVar_71099;
	BIT_VEC cppVar_71222;
	BIT_VEC cppVar_71223;
	bool cppVar_71224;
	BIT_VEC cppVar_71226;
	BIT_VEC cppVar_71227;
	BIT_VEC cppVar_71228;
	BIT_VEC cppVar_71229;
	bool cppVar_71230;
	BIT_VEC cppVar_71232;
	BIT_VEC cppVar_71233;
	BIT_VEC cppVar_71234;
	BIT_VEC cppVar_71235;
	bool cppVar_71236;
	BIT_VEC cppVar_71237;
	BIT_VEC cppVar_71238;
	BIT_VEC cppVar_71239;
	BIT_VEC cppVar_71241;
	BIT_VEC cppVar_71242;
	BIT_VEC cppVar_71243;
	bool cppVar_71244;
	BIT_VEC cppVar_71246;
	BIT_VEC cppVar_71247;
	BIT_VEC cppVar_71248;
	bool cppVar_71249;
	BIT_VEC cppVar_71251;
	BIT_VEC cppVar_71252;
	BIT_VEC cppVar_71253;
	bool cppVar_71254;
	BIT_VEC cppVar_71256;
	BIT_VEC cppVar_71257;
	BIT_VEC cppVar_71258;
	bool cppVar_71259;
	BIT_VEC cppVar_71261;
	BIT_VEC cppVar_71262;
	BIT_VEC cppVar_71263;
	bool cppVar_71264;
	BIT_VEC cppVar_71266;
	BIT_VEC cppVar_71267;
	BIT_VEC cppVar_71268;
	bool cppVar_71269;
	BIT_VEC cppVar_71271;
	BIT_VEC cppVar_71272;
	BIT_VEC cppVar_71273;
	bool cppVar_71274;
	BIT_VEC cppVar_71276;
	BIT_VEC cppVar_71277;
	BIT_VEC cppVar_71278;
	bool cppVar_71279;
	BIT_VEC cppVar_71281;
	BIT_VEC cppVar_71282;
	BIT_VEC cppVar_71283;
	bool cppVar_71284;
	BIT_VEC cppVar_71286;
	BIT_VEC cppVar_71287;
	BIT_VEC cppVar_71288;
	bool cppVar_71289;
	BIT_VEC cppVar_71291;
	BIT_VEC cppVar_71292;
	BIT_VEC cppVar_71293;
	bool cppVar_71294;
	BIT_VEC cppVar_71296;
	BIT_VEC cppVar_71297;
	BIT_VEC cppVar_71298;
	bool cppVar_71299;
	BIT_VEC cppVar_71301;
	BIT_VEC cppVar_71302;
	BIT_VEC cppVar_71303;
	bool cppVar_71304;
	BIT_VEC cppVar_71306;
	BIT_VEC cppVar_71307;
	BIT_VEC cppVar_71308;
	bool cppVar_71309;
	BIT_VEC cppVar_71311;
	BIT_VEC cppVar_71312;
	BIT_VEC cppVar_71313;
	bool cppVar_71314;
	BIT_VEC cppVar_71316;
	BIT_VEC cppVar_71317;
	BIT_VEC cppVar_71318;
	bool cppVar_71319;
	BIT_VEC cppVar_71321;
	BIT_VEC cppVar_71322;
	BIT_VEC cppVar_71323;
	bool cppVar_71324;
	BIT_VEC cppVar_71326;
	BIT_VEC cppVar_71327;
	BIT_VEC cppVar_71328;
	bool cppVar_71329;
	BIT_VEC cppVar_71331;
	BIT_VEC cppVar_71332;
	BIT_VEC cppVar_71333;
	bool cppVar_71334;
	BIT_VEC cppVar_71336;
	BIT_VEC cppVar_71337;
	BIT_VEC cppVar_71338;
	bool cppVar_71339;
	BIT_VEC cppVar_71341;
	BIT_VEC cppVar_71342;
	BIT_VEC cppVar_71343;
	bool cppVar_71344;
	BIT_VEC cppVar_71345;
	BIT_VEC cppVar_71340;
	BIT_VEC cppVar_71335;
	BIT_VEC cppVar_71330;
	BIT_VEC cppVar_71325;
	BIT_VEC cppVar_71320;
	BIT_VEC cppVar_71315;
	BIT_VEC cppVar_71310;
	BIT_VEC cppVar_71305;
	BIT_VEC cppVar_71300;
	BIT_VEC cppVar_71295;
	BIT_VEC cppVar_71290;
	BIT_VEC cppVar_71285;
	BIT_VEC cppVar_71280;
	BIT_VEC cppVar_71275;
	BIT_VEC cppVar_71270;
	BIT_VEC cppVar_71265;
	BIT_VEC cppVar_71260;
	BIT_VEC cppVar_71255;
	BIT_VEC cppVar_71250;
	BIT_VEC cppVar_71245;
	BIT_VEC cppVar_71240;
	BIT_VEC cppVar_71231;
	BIT_VEC cppVar_71346;
	BIT_VEC cppVar_71347;
	BIT_VEC cppVar_71348;
	BIT_VEC cppVar_71349;
	BIT_VEC cppVar_71225;
	BIT_VEC cppVar_71351;
	BIT_VEC cppVar_71352;
	bool cppVar_71353;
	BIT_VEC cppVar_71355;
	BIT_VEC cppVar_71356;
	BIT_VEC cppVar_71357;
	BIT_VEC cppVar_71358;
	bool cppVar_71359;
	BIT_VEC cppVar_71361;
	BIT_VEC cppVar_71362;
	BIT_VEC cppVar_71363;
	BIT_VEC cppVar_71364;
	bool cppVar_71365;
	BIT_VEC cppVar_71366;
	BIT_VEC cppVar_71367;
	BIT_VEC cppVar_71368;
	BIT_VEC cppVar_71370;
	BIT_VEC cppVar_71371;
	BIT_VEC cppVar_71372;
	bool cppVar_71373;
	BIT_VEC cppVar_71375;
	BIT_VEC cppVar_71376;
	BIT_VEC cppVar_71377;
	bool cppVar_71378;
	BIT_VEC cppVar_71380;
	BIT_VEC cppVar_71381;
	BIT_VEC cppVar_71382;
	bool cppVar_71383;
	BIT_VEC cppVar_71385;
	BIT_VEC cppVar_71386;
	BIT_VEC cppVar_71387;
	bool cppVar_71388;
	BIT_VEC cppVar_71390;
	BIT_VEC cppVar_71391;
	BIT_VEC cppVar_71392;
	bool cppVar_71393;
	BIT_VEC cppVar_71395;
	BIT_VEC cppVar_71396;
	BIT_VEC cppVar_71397;
	bool cppVar_71398;
	BIT_VEC cppVar_71400;
	BIT_VEC cppVar_71401;
	BIT_VEC cppVar_71402;
	bool cppVar_71403;
	BIT_VEC cppVar_71405;
	BIT_VEC cppVar_71406;
	BIT_VEC cppVar_71407;
	bool cppVar_71408;
	BIT_VEC cppVar_71410;
	BIT_VEC cppVar_71411;
	BIT_VEC cppVar_71412;
	bool cppVar_71413;
	BIT_VEC cppVar_71415;
	BIT_VEC cppVar_71416;
	BIT_VEC cppVar_71417;
	bool cppVar_71418;
	BIT_VEC cppVar_71420;
	BIT_VEC cppVar_71421;
	BIT_VEC cppVar_71422;
	bool cppVar_71423;
	BIT_VEC cppVar_71425;
	BIT_VEC cppVar_71426;
	BIT_VEC cppVar_71427;
	bool cppVar_71428;
	BIT_VEC cppVar_71430;
	BIT_VEC cppVar_71431;
	BIT_VEC cppVar_71432;
	bool cppVar_71433;
	BIT_VEC cppVar_71435;
	BIT_VEC cppVar_71436;
	BIT_VEC cppVar_71437;
	bool cppVar_71438;
	BIT_VEC cppVar_71440;
	BIT_VEC cppVar_71441;
	BIT_VEC cppVar_71442;
	bool cppVar_71443;
	BIT_VEC cppVar_71445;
	BIT_VEC cppVar_71446;
	BIT_VEC cppVar_71447;
	bool cppVar_71448;
	BIT_VEC cppVar_71450;
	BIT_VEC cppVar_71451;
	BIT_VEC cppVar_71452;
	bool cppVar_71453;
	BIT_VEC cppVar_71455;
	BIT_VEC cppVar_71456;
	BIT_VEC cppVar_71457;
	bool cppVar_71458;
	BIT_VEC cppVar_71460;
	BIT_VEC cppVar_71461;
	BIT_VEC cppVar_71462;
	bool cppVar_71463;
	BIT_VEC cppVar_71465;
	BIT_VEC cppVar_71466;
	BIT_VEC cppVar_71467;
	bool cppVar_71468;
	BIT_VEC cppVar_71470;
	BIT_VEC cppVar_71471;
	BIT_VEC cppVar_71472;
	bool cppVar_71473;
	BIT_VEC cppVar_71474;
	BIT_VEC cppVar_71469;
	BIT_VEC cppVar_71464;
	BIT_VEC cppVar_71459;
	BIT_VEC cppVar_71454;
	BIT_VEC cppVar_71449;
	BIT_VEC cppVar_71444;
	BIT_VEC cppVar_71439;
	BIT_VEC cppVar_71434;
	BIT_VEC cppVar_71429;
	BIT_VEC cppVar_71424;
	BIT_VEC cppVar_71419;
	BIT_VEC cppVar_71414;
	BIT_VEC cppVar_71409;
	BIT_VEC cppVar_71404;
	BIT_VEC cppVar_71399;
	BIT_VEC cppVar_71394;
	BIT_VEC cppVar_71389;
	BIT_VEC cppVar_71384;
	BIT_VEC cppVar_71379;
	BIT_VEC cppVar_71374;
	BIT_VEC cppVar_71369;
	BIT_VEC cppVar_71360;
	BIT_VEC cppVar_71475;
	BIT_VEC cppVar_71354;
	BIT_VEC cppVar_71477;
	BIT_VEC cppVar_71478;
	bool cppVar_71479;
	BIT_VEC cppVar_71481;
	BIT_VEC cppVar_71482;
	BIT_VEC cppVar_71483;
	BIT_VEC cppVar_71484;
	bool cppVar_71485;
	BIT_VEC cppVar_71487;
	BIT_VEC cppVar_71488;
	BIT_VEC cppVar_71489;
	BIT_VEC cppVar_71490;
	bool cppVar_71491;
	BIT_VEC cppVar_71492;
	BIT_VEC cppVar_71493;
	BIT_VEC cppVar_71494;
	BIT_VEC cppVar_71496;
	BIT_VEC cppVar_71497;
	BIT_VEC cppVar_71498;
	bool cppVar_71499;
	BIT_VEC cppVar_71501;
	BIT_VEC cppVar_71502;
	BIT_VEC cppVar_71503;
	bool cppVar_71504;
	BIT_VEC cppVar_71506;
	BIT_VEC cppVar_71507;
	BIT_VEC cppVar_71508;
	bool cppVar_71509;
	BIT_VEC cppVar_71511;
	BIT_VEC cppVar_71512;
	BIT_VEC cppVar_71513;
	bool cppVar_71514;
	BIT_VEC cppVar_71516;
	BIT_VEC cppVar_71517;
	BIT_VEC cppVar_71518;
	bool cppVar_71519;
	BIT_VEC cppVar_71521;
	BIT_VEC cppVar_71522;
	BIT_VEC cppVar_71523;
	bool cppVar_71524;
	BIT_VEC cppVar_71526;
	BIT_VEC cppVar_71527;
	BIT_VEC cppVar_71528;
	bool cppVar_71529;
	BIT_VEC cppVar_71531;
	BIT_VEC cppVar_71532;
	BIT_VEC cppVar_71533;
	bool cppVar_71534;
	BIT_VEC cppVar_71536;
	BIT_VEC cppVar_71537;
	BIT_VEC cppVar_71538;
	bool cppVar_71539;
	BIT_VEC cppVar_71541;
	BIT_VEC cppVar_71542;
	BIT_VEC cppVar_71543;
	bool cppVar_71544;
	BIT_VEC cppVar_71546;
	BIT_VEC cppVar_71547;
	BIT_VEC cppVar_71548;
	bool cppVar_71549;
	BIT_VEC cppVar_71551;
	BIT_VEC cppVar_71552;
	BIT_VEC cppVar_71553;
	bool cppVar_71554;
	BIT_VEC cppVar_71556;
	BIT_VEC cppVar_71557;
	BIT_VEC cppVar_71558;
	bool cppVar_71559;
	BIT_VEC cppVar_71561;
	BIT_VEC cppVar_71562;
	BIT_VEC cppVar_71563;
	bool cppVar_71564;
	BIT_VEC cppVar_71566;
	BIT_VEC cppVar_71567;
	BIT_VEC cppVar_71568;
	bool cppVar_71569;
	BIT_VEC cppVar_71571;
	BIT_VEC cppVar_71572;
	BIT_VEC cppVar_71573;
	bool cppVar_71574;
	BIT_VEC cppVar_71576;
	BIT_VEC cppVar_71577;
	BIT_VEC cppVar_71578;
	bool cppVar_71579;
	BIT_VEC cppVar_71581;
	BIT_VEC cppVar_71582;
	BIT_VEC cppVar_71583;
	bool cppVar_71584;
	BIT_VEC cppVar_71586;
	BIT_VEC cppVar_71587;
	BIT_VEC cppVar_71588;
	bool cppVar_71589;
	BIT_VEC cppVar_71591;
	BIT_VEC cppVar_71592;
	BIT_VEC cppVar_71593;
	bool cppVar_71594;
	BIT_VEC cppVar_71596;
	BIT_VEC cppVar_71597;
	BIT_VEC cppVar_71598;
	bool cppVar_71599;
	BIT_VEC cppVar_71600;
	BIT_VEC cppVar_71595;
	BIT_VEC cppVar_71590;
	BIT_VEC cppVar_71585;
	BIT_VEC cppVar_71580;
	BIT_VEC cppVar_71575;
	BIT_VEC cppVar_71570;
	BIT_VEC cppVar_71565;
	BIT_VEC cppVar_71560;
	BIT_VEC cppVar_71555;
	BIT_VEC cppVar_71550;
	BIT_VEC cppVar_71545;
	BIT_VEC cppVar_71540;
	BIT_VEC cppVar_71535;
	BIT_VEC cppVar_71530;
	BIT_VEC cppVar_71525;
	BIT_VEC cppVar_71520;
	BIT_VEC cppVar_71515;
	BIT_VEC cppVar_71510;
	BIT_VEC cppVar_71505;
	BIT_VEC cppVar_71500;
	BIT_VEC cppVar_71495;
	BIT_VEC cppVar_71486;
	BIT_VEC cppVar_71601;
	BIT_VEC cppVar_71602;
	BIT_VEC cppVar_71603;
	BIT_VEC cppVar_71604;
	BIT_VEC cppVar_71480;
	BIT_VEC cppVar_71606;
	BIT_VEC cppVar_71607;
	bool cppVar_71608;
	BIT_VEC cppVar_71610;
	BIT_VEC cppVar_71611;
	BIT_VEC cppVar_71612;
	BIT_VEC cppVar_71613;
	bool cppVar_71614;
	BIT_VEC cppVar_71616;
	BIT_VEC cppVar_71617;
	BIT_VEC cppVar_71618;
	BIT_VEC cppVar_71619;
	bool cppVar_71620;
	BIT_VEC cppVar_71621;
	BIT_VEC cppVar_71622;
	BIT_VEC cppVar_71623;
	BIT_VEC cppVar_71625;
	BIT_VEC cppVar_71626;
	BIT_VEC cppVar_71627;
	bool cppVar_71628;
	BIT_VEC cppVar_71630;
	BIT_VEC cppVar_71631;
	BIT_VEC cppVar_71632;
	bool cppVar_71633;
	BIT_VEC cppVar_71635;
	BIT_VEC cppVar_71636;
	BIT_VEC cppVar_71637;
	bool cppVar_71638;
	BIT_VEC cppVar_71640;
	BIT_VEC cppVar_71641;
	BIT_VEC cppVar_71642;
	bool cppVar_71643;
	BIT_VEC cppVar_71645;
	BIT_VEC cppVar_71646;
	BIT_VEC cppVar_71647;
	bool cppVar_71648;
	BIT_VEC cppVar_71650;
	BIT_VEC cppVar_71651;
	BIT_VEC cppVar_71652;
	bool cppVar_71653;
	BIT_VEC cppVar_71655;
	BIT_VEC cppVar_71656;
	BIT_VEC cppVar_71657;
	bool cppVar_71658;
	BIT_VEC cppVar_71660;
	BIT_VEC cppVar_71661;
	BIT_VEC cppVar_71662;
	bool cppVar_71663;
	BIT_VEC cppVar_71665;
	BIT_VEC cppVar_71666;
	BIT_VEC cppVar_71667;
	bool cppVar_71668;
	BIT_VEC cppVar_71670;
	BIT_VEC cppVar_71671;
	BIT_VEC cppVar_71672;
	bool cppVar_71673;
	BIT_VEC cppVar_71675;
	BIT_VEC cppVar_71676;
	BIT_VEC cppVar_71677;
	bool cppVar_71678;
	BIT_VEC cppVar_71680;
	BIT_VEC cppVar_71681;
	BIT_VEC cppVar_71682;
	bool cppVar_71683;
	BIT_VEC cppVar_71685;
	BIT_VEC cppVar_71686;
	BIT_VEC cppVar_71687;
	bool cppVar_71688;
	BIT_VEC cppVar_71690;
	BIT_VEC cppVar_71691;
	BIT_VEC cppVar_71692;
	bool cppVar_71693;
	BIT_VEC cppVar_71695;
	BIT_VEC cppVar_71696;
	BIT_VEC cppVar_71697;
	bool cppVar_71698;
	BIT_VEC cppVar_71700;
	BIT_VEC cppVar_71701;
	BIT_VEC cppVar_71702;
	bool cppVar_71703;
	BIT_VEC cppVar_71705;
	BIT_VEC cppVar_71706;
	BIT_VEC cppVar_71707;
	bool cppVar_71708;
	BIT_VEC cppVar_71710;
	BIT_VEC cppVar_71711;
	BIT_VEC cppVar_71712;
	bool cppVar_71713;
	BIT_VEC cppVar_71715;
	BIT_VEC cppVar_71716;
	BIT_VEC cppVar_71717;
	bool cppVar_71718;
	BIT_VEC cppVar_71720;
	BIT_VEC cppVar_71721;
	BIT_VEC cppVar_71722;
	bool cppVar_71723;
	BIT_VEC cppVar_71725;
	BIT_VEC cppVar_71726;
	BIT_VEC cppVar_71727;
	bool cppVar_71728;
	BIT_VEC cppVar_71729;
	BIT_VEC cppVar_71724;
	BIT_VEC cppVar_71719;
	BIT_VEC cppVar_71714;
	BIT_VEC cppVar_71709;
	BIT_VEC cppVar_71704;
	BIT_VEC cppVar_71699;
	BIT_VEC cppVar_71694;
	BIT_VEC cppVar_71689;
	BIT_VEC cppVar_71684;
	BIT_VEC cppVar_71679;
	BIT_VEC cppVar_71674;
	BIT_VEC cppVar_71669;
	BIT_VEC cppVar_71664;
	BIT_VEC cppVar_71659;
	BIT_VEC cppVar_71654;
	BIT_VEC cppVar_71649;
	BIT_VEC cppVar_71644;
	BIT_VEC cppVar_71639;
	BIT_VEC cppVar_71634;
	BIT_VEC cppVar_71629;
	BIT_VEC cppVar_71624;
	BIT_VEC cppVar_71615;
	BIT_VEC cppVar_71730;
	BIT_VEC cppVar_71609;
	BIT_VEC cppVar_71732;
	BIT_VEC cppVar_71733;
	bool cppVar_71734;
	BIT_VEC cppVar_71735;
	BIT_VEC cppVar_71736;
	bool cppVar_71737;
	bool cppVar_71738;
	BIT_VEC cppVar_71740;
	BIT_VEC cppVar_71741;
	BIT_VEC cppVar_71742;
	BIT_VEC cppVar_71743;
	bool cppVar_71744;
	BIT_VEC cppVar_71746;
	BIT_VEC cppVar_71747;
	BIT_VEC cppVar_71748;
	BIT_VEC cppVar_71749;
	bool cppVar_71750;
	BIT_VEC cppVar_71751;
	BIT_VEC cppVar_71752;
	BIT_VEC cppVar_71753;
	BIT_VEC cppVar_71755;
	BIT_VEC cppVar_71756;
	BIT_VEC cppVar_71757;
	bool cppVar_71758;
	BIT_VEC cppVar_71760;
	BIT_VEC cppVar_71761;
	BIT_VEC cppVar_71762;
	bool cppVar_71763;
	BIT_VEC cppVar_71765;
	BIT_VEC cppVar_71766;
	BIT_VEC cppVar_71767;
	bool cppVar_71768;
	BIT_VEC cppVar_71770;
	BIT_VEC cppVar_71771;
	BIT_VEC cppVar_71772;
	bool cppVar_71773;
	BIT_VEC cppVar_71775;
	BIT_VEC cppVar_71776;
	BIT_VEC cppVar_71777;
	bool cppVar_71778;
	BIT_VEC cppVar_71780;
	BIT_VEC cppVar_71781;
	BIT_VEC cppVar_71782;
	bool cppVar_71783;
	BIT_VEC cppVar_71785;
	BIT_VEC cppVar_71786;
	BIT_VEC cppVar_71787;
	bool cppVar_71788;
	BIT_VEC cppVar_71790;
	BIT_VEC cppVar_71791;
	BIT_VEC cppVar_71792;
	bool cppVar_71793;
	BIT_VEC cppVar_71795;
	BIT_VEC cppVar_71796;
	BIT_VEC cppVar_71797;
	bool cppVar_71798;
	BIT_VEC cppVar_71800;
	BIT_VEC cppVar_71801;
	BIT_VEC cppVar_71802;
	bool cppVar_71803;
	BIT_VEC cppVar_71805;
	BIT_VEC cppVar_71806;
	BIT_VEC cppVar_71807;
	bool cppVar_71808;
	BIT_VEC cppVar_71810;
	BIT_VEC cppVar_71811;
	BIT_VEC cppVar_71812;
	bool cppVar_71813;
	BIT_VEC cppVar_71815;
	BIT_VEC cppVar_71816;
	BIT_VEC cppVar_71817;
	bool cppVar_71818;
	BIT_VEC cppVar_71820;
	BIT_VEC cppVar_71821;
	BIT_VEC cppVar_71822;
	bool cppVar_71823;
	BIT_VEC cppVar_71825;
	BIT_VEC cppVar_71826;
	BIT_VEC cppVar_71827;
	bool cppVar_71828;
	BIT_VEC cppVar_71830;
	BIT_VEC cppVar_71831;
	BIT_VEC cppVar_71832;
	bool cppVar_71833;
	BIT_VEC cppVar_71835;
	BIT_VEC cppVar_71836;
	BIT_VEC cppVar_71837;
	bool cppVar_71838;
	BIT_VEC cppVar_71840;
	BIT_VEC cppVar_71841;
	BIT_VEC cppVar_71842;
	bool cppVar_71843;
	BIT_VEC cppVar_71845;
	BIT_VEC cppVar_71846;
	BIT_VEC cppVar_71847;
	bool cppVar_71848;
	BIT_VEC cppVar_71850;
	BIT_VEC cppVar_71851;
	BIT_VEC cppVar_71852;
	bool cppVar_71853;
	BIT_VEC cppVar_71855;
	BIT_VEC cppVar_71856;
	BIT_VEC cppVar_71857;
	bool cppVar_71858;
	BIT_VEC cppVar_71859;
	BIT_VEC cppVar_71854;
	BIT_VEC cppVar_71849;
	BIT_VEC cppVar_71844;
	BIT_VEC cppVar_71839;
	BIT_VEC cppVar_71834;
	BIT_VEC cppVar_71829;
	BIT_VEC cppVar_71824;
	BIT_VEC cppVar_71819;
	BIT_VEC cppVar_71814;
	BIT_VEC cppVar_71809;
	BIT_VEC cppVar_71804;
	BIT_VEC cppVar_71799;
	BIT_VEC cppVar_71794;
	BIT_VEC cppVar_71789;
	BIT_VEC cppVar_71784;
	BIT_VEC cppVar_71779;
	BIT_VEC cppVar_71774;
	BIT_VEC cppVar_71769;
	BIT_VEC cppVar_71764;
	BIT_VEC cppVar_71759;
	BIT_VEC cppVar_71754;
	BIT_VEC cppVar_71745;
	BIT_VEC cppVar_71860;
	BIT_VEC cppVar_71861;
	BIT_VEC cppVar_71739;
	BIT_VEC cppVar_71863;
	BIT_VEC cppVar_71864;
	bool cppVar_71865;
	BIT_VEC cppVar_71866;
	BIT_VEC cppVar_71867;
	bool cppVar_71868;
	bool cppVar_71869;
	BIT_VEC cppVar_71872;
	BIT_VEC cppVar_71873;
	BIT_VEC cppVar_71874;
	BIT_VEC cppVar_71875;
	BIT_VEC cppVar_71876;
	bool cppVar_71877;
	BIT_VEC cppVar_71878;
	BIT_VEC cppVar_71879;
	BIT_VEC cppVar_71880;
	BIT_VEC cppVar_71881;
	BIT_VEC cppVar_71882;
	BIT_VEC cppVar_71883;
	BIT_VEC cppVar_71884;
	BIT_VEC cppVar_71885;
	BIT_VEC cppVar_71886;
	BIT_VEC cppVar_71887;
	BIT_VEC cppVar_71888;
	BIT_VEC cppVar_71871;
	BIT_VEC cppVar_71889;
	bool cppVar_71890;
	BIT_VEC cppVar_71891;
	BIT_VEC cppVar_71892;
	BIT_VEC cppVar_71893;
	BIT_VEC cppVar_71894;
	BIT_VEC cppVar_71895;
	BIT_VEC cppVar_71896;
	BIT_VEC cppVar_71897;
	BIT_VEC cppVar_71900;
	BIT_VEC cppVar_71901;
	BIT_VEC cppVar_71902;
	bool cppVar_71903;
	BIT_VEC cppVar_71904;
	BIT_VEC cppVar_71905;
	BIT_VEC cppVar_71906;
	BIT_VEC cppVar_71907;
	BIT_VEC cppVar_71908;
	BIT_VEC cppVar_71909;
	BIT_VEC cppVar_71910;
	BIT_VEC cppVar_71911;
	BIT_VEC cppVar_71912;
	BIT_VEC cppVar_71899;
	BIT_VEC cppVar_71913;
	BIT_VEC cppVar_71914;
	bool cppVar_71915;
	BIT_VEC cppVar_71917;
	BIT_VEC cppVar_71918;
	BIT_VEC cppVar_71919;
	bool cppVar_71920;
	BIT_VEC cppVar_71921;
	BIT_VEC cppVar_71922;
	BIT_VEC cppVar_71923;
	BIT_VEC cppVar_71924;
	BIT_VEC cppVar_71925;
	BIT_VEC cppVar_71926;
	BIT_VEC cppVar_71927;
	BIT_VEC cppVar_71928;
	BIT_VEC cppVar_71929;
	BIT_VEC cppVar_71916;
	BIT_VEC cppVar_71930;
	BIT_VEC cppVar_71933;
	BIT_VEC cppVar_71934;
	BIT_VEC cppVar_71935;
	bool cppVar_71936;
	BIT_VEC cppVar_71937;
	BIT_VEC cppVar_71938;
	BIT_VEC cppVar_71939;
	BIT_VEC cppVar_71940;
	BIT_VEC cppVar_71941;
	BIT_VEC cppVar_71942;
	BIT_VEC cppVar_71943;
	BIT_VEC cppVar_71944;
	BIT_VEC cppVar_71945;
	BIT_VEC cppVar_71932;
	BIT_VEC cppVar_71946;
	bool cppVar_71947;
	BIT_VEC cppVar_71950;
	BIT_VEC cppVar_71951;
	BIT_VEC cppVar_71952;
	bool cppVar_71953;
	BIT_VEC cppVar_71954;
	BIT_VEC cppVar_71955;
	BIT_VEC cppVar_71956;
	BIT_VEC cppVar_71957;
	BIT_VEC cppVar_71958;
	BIT_VEC cppVar_71959;
	BIT_VEC cppVar_71960;
	BIT_VEC cppVar_71961;
	BIT_VEC cppVar_71962;
	BIT_VEC cppVar_71949;
	BIT_VEC cppVar_71963;
	bool cppVar_71964;
	BIT_VEC cppVar_71967;
	BIT_VEC cppVar_71968;
	BIT_VEC cppVar_71969;
	bool cppVar_71970;
	BIT_VEC cppVar_71971;
	BIT_VEC cppVar_71972;
	BIT_VEC cppVar_71973;
	BIT_VEC cppVar_71974;
	BIT_VEC cppVar_71975;
	BIT_VEC cppVar_71976;
	BIT_VEC cppVar_71977;
	BIT_VEC cppVar_71978;
	BIT_VEC cppVar_71979;
	BIT_VEC cppVar_71966;
	BIT_VEC cppVar_71980;
	bool cppVar_71981;
	BIT_VEC cppVar_71984;
	BIT_VEC cppVar_71985;
	BIT_VEC cppVar_71986;
	bool cppVar_71987;
	BIT_VEC cppVar_71988;
	BIT_VEC cppVar_71989;
	BIT_VEC cppVar_71990;
	BIT_VEC cppVar_71991;
	BIT_VEC cppVar_71992;
	BIT_VEC cppVar_71993;
	BIT_VEC cppVar_71994;
	BIT_VEC cppVar_71995;
	BIT_VEC cppVar_71996;
	BIT_VEC cppVar_71983;
	BIT_VEC cppVar_71997;
	bool cppVar_71998;
	BIT_VEC cppVar_72001;
	BIT_VEC cppVar_72002;
	BIT_VEC cppVar_72003;
	bool cppVar_72004;
	BIT_VEC cppVar_72005;
	BIT_VEC cppVar_72006;
	BIT_VEC cppVar_72007;
	BIT_VEC cppVar_72008;
	BIT_VEC cppVar_72009;
	BIT_VEC cppVar_72010;
	BIT_VEC cppVar_72011;
	BIT_VEC cppVar_72012;
	BIT_VEC cppVar_72013;
	BIT_VEC cppVar_72000;
	BIT_VEC cppVar_72014;
	bool cppVar_72015;
	BIT_VEC cppVar_72018;
	BIT_VEC cppVar_72019;
	BIT_VEC cppVar_72020;
	bool cppVar_72021;
	BIT_VEC cppVar_72022;
	BIT_VEC cppVar_72023;
	BIT_VEC cppVar_72024;
	BIT_VEC cppVar_72025;
	BIT_VEC cppVar_72026;
	BIT_VEC cppVar_72027;
	BIT_VEC cppVar_72028;
	BIT_VEC cppVar_72029;
	BIT_VEC cppVar_72030;
	BIT_VEC cppVar_72017;
	BIT_VEC cppVar_72031;
	bool cppVar_72032;
	BIT_VEC cppVar_72035;
	BIT_VEC cppVar_72036;
	BIT_VEC cppVar_72037;
	bool cppVar_72038;
	BIT_VEC cppVar_72039;
	BIT_VEC cppVar_72040;
	BIT_VEC cppVar_72041;
	BIT_VEC cppVar_72042;
	BIT_VEC cppVar_72043;
	BIT_VEC cppVar_72044;
	BIT_VEC cppVar_72045;
	BIT_VEC cppVar_72046;
	BIT_VEC cppVar_72047;
	BIT_VEC cppVar_72034;
	BIT_VEC cppVar_72048;
	bool cppVar_72049;
	BIT_VEC cppVar_72052;
	BIT_VEC cppVar_72053;
	BIT_VEC cppVar_72054;
	bool cppVar_72055;
	BIT_VEC cppVar_72056;
	BIT_VEC cppVar_72057;
	BIT_VEC cppVar_72058;
	BIT_VEC cppVar_72059;
	BIT_VEC cppVar_72060;
	BIT_VEC cppVar_72061;
	BIT_VEC cppVar_72062;
	BIT_VEC cppVar_72063;
	BIT_VEC cppVar_72064;
	BIT_VEC cppVar_72051;
	BIT_VEC cppVar_72065;
	bool cppVar_72066;
	BIT_VEC cppVar_72069;
	BIT_VEC cppVar_72070;
	BIT_VEC cppVar_72071;
	bool cppVar_72072;
	BIT_VEC cppVar_72073;
	BIT_VEC cppVar_72074;
	BIT_VEC cppVar_72075;
	BIT_VEC cppVar_72076;
	BIT_VEC cppVar_72077;
	BIT_VEC cppVar_72078;
	BIT_VEC cppVar_72079;
	BIT_VEC cppVar_72080;
	BIT_VEC cppVar_72081;
	BIT_VEC cppVar_72068;
	BIT_VEC cppVar_72082;
	bool cppVar_72083;
	BIT_VEC cppVar_72086;
	BIT_VEC cppVar_72087;
	BIT_VEC cppVar_72088;
	bool cppVar_72089;
	BIT_VEC cppVar_72090;
	BIT_VEC cppVar_72091;
	BIT_VEC cppVar_72092;
	BIT_VEC cppVar_72093;
	BIT_VEC cppVar_72094;
	BIT_VEC cppVar_72095;
	BIT_VEC cppVar_72096;
	BIT_VEC cppVar_72097;
	BIT_VEC cppVar_72098;
	BIT_VEC cppVar_72085;
	BIT_VEC cppVar_72099;
	bool cppVar_72100;
	BIT_VEC cppVar_72103;
	BIT_VEC cppVar_72104;
	BIT_VEC cppVar_72105;
	bool cppVar_72106;
	BIT_VEC cppVar_72107;
	BIT_VEC cppVar_72108;
	BIT_VEC cppVar_72109;
	BIT_VEC cppVar_72110;
	BIT_VEC cppVar_72111;
	BIT_VEC cppVar_72112;
	BIT_VEC cppVar_72113;
	BIT_VEC cppVar_72114;
	BIT_VEC cppVar_72115;
	BIT_VEC cppVar_72102;
	BIT_VEC cppVar_72116;
	bool cppVar_72117;
	BIT_VEC cppVar_72120;
	BIT_VEC cppVar_72121;
	BIT_VEC cppVar_72122;
	bool cppVar_72123;
	BIT_VEC cppVar_72124;
	BIT_VEC cppVar_72125;
	BIT_VEC cppVar_72126;
	BIT_VEC cppVar_72127;
	BIT_VEC cppVar_72128;
	BIT_VEC cppVar_72129;
	BIT_VEC cppVar_72130;
	BIT_VEC cppVar_72131;
	BIT_VEC cppVar_72132;
	BIT_VEC cppVar_72119;
	BIT_VEC cppVar_72133;
	bool cppVar_72134;
	BIT_VEC cppVar_72137;
	BIT_VEC cppVar_72138;
	BIT_VEC cppVar_72139;
	bool cppVar_72140;
	BIT_VEC cppVar_72141;
	BIT_VEC cppVar_72142;
	BIT_VEC cppVar_72143;
	BIT_VEC cppVar_72144;
	BIT_VEC cppVar_72145;
	BIT_VEC cppVar_72146;
	BIT_VEC cppVar_72147;
	BIT_VEC cppVar_72148;
	BIT_VEC cppVar_72149;
	BIT_VEC cppVar_72136;
	BIT_VEC cppVar_72150;
	bool cppVar_72151;
	BIT_VEC cppVar_72154;
	BIT_VEC cppVar_72155;
	BIT_VEC cppVar_72156;
	bool cppVar_72157;
	BIT_VEC cppVar_72158;
	BIT_VEC cppVar_72159;
	BIT_VEC cppVar_72160;
	BIT_VEC cppVar_72161;
	BIT_VEC cppVar_72162;
	BIT_VEC cppVar_72163;
	BIT_VEC cppVar_72164;
	BIT_VEC cppVar_72165;
	BIT_VEC cppVar_72166;
	BIT_VEC cppVar_72153;
	BIT_VEC cppVar_72167;
	bool cppVar_72168;
	BIT_VEC cppVar_72171;
	BIT_VEC cppVar_72172;
	BIT_VEC cppVar_72173;
	bool cppVar_72174;
	BIT_VEC cppVar_72175;
	BIT_VEC cppVar_72176;
	BIT_VEC cppVar_72177;
	BIT_VEC cppVar_72178;
	BIT_VEC cppVar_72179;
	BIT_VEC cppVar_72180;
	BIT_VEC cppVar_72181;
	BIT_VEC cppVar_72182;
	BIT_VEC cppVar_72183;
	BIT_VEC cppVar_72170;
	BIT_VEC cppVar_72184;
	bool cppVar_72185;
	BIT_VEC cppVar_72188;
	BIT_VEC cppVar_72189;
	BIT_VEC cppVar_72190;
	bool cppVar_72191;
	BIT_VEC cppVar_72192;
	BIT_VEC cppVar_72193;
	BIT_VEC cppVar_72194;
	BIT_VEC cppVar_72195;
	BIT_VEC cppVar_72196;
	BIT_VEC cppVar_72197;
	BIT_VEC cppVar_72198;
	BIT_VEC cppVar_72199;
	BIT_VEC cppVar_72200;
	BIT_VEC cppVar_72187;
	BIT_VEC cppVar_72201;
	bool cppVar_72202;
	BIT_VEC cppVar_72205;
	BIT_VEC cppVar_72206;
	BIT_VEC cppVar_72207;
	bool cppVar_72208;
	BIT_VEC cppVar_72209;
	BIT_VEC cppVar_72210;
	BIT_VEC cppVar_72211;
	BIT_VEC cppVar_72212;
	BIT_VEC cppVar_72213;
	BIT_VEC cppVar_72214;
	BIT_VEC cppVar_72215;
	BIT_VEC cppVar_72216;
	BIT_VEC cppVar_72217;
	BIT_VEC cppVar_72204;
	BIT_VEC cppVar_72218;
	bool cppVar_72219;
	BIT_VEC cppVar_72222;
	BIT_VEC cppVar_72223;
	BIT_VEC cppVar_72224;
	bool cppVar_72225;
	BIT_VEC cppVar_72226;
	BIT_VEC cppVar_72227;
	BIT_VEC cppVar_72228;
	BIT_VEC cppVar_72229;
	BIT_VEC cppVar_72230;
	BIT_VEC cppVar_72231;
	BIT_VEC cppVar_72232;
	BIT_VEC cppVar_72233;
	BIT_VEC cppVar_72234;
	BIT_VEC cppVar_72221;
	BIT_VEC cppVar_72235;
	bool cppVar_72236;
	BIT_VEC cppVar_72239;
	BIT_VEC cppVar_72240;
	BIT_VEC cppVar_72241;
	bool cppVar_72242;
	BIT_VEC cppVar_72243;
	BIT_VEC cppVar_72244;
	BIT_VEC cppVar_72245;
	BIT_VEC cppVar_72246;
	BIT_VEC cppVar_72247;
	BIT_VEC cppVar_72248;
	BIT_VEC cppVar_72249;
	BIT_VEC cppVar_72250;
	BIT_VEC cppVar_72251;
	BIT_VEC cppVar_72238;
	BIT_VEC cppVar_72252;
	bool cppVar_72253;
	BIT_VEC cppVar_72256;
	BIT_VEC cppVar_72257;
	BIT_VEC cppVar_72258;
	bool cppVar_72259;
	BIT_VEC cppVar_72260;
	BIT_VEC cppVar_72261;
	BIT_VEC cppVar_72262;
	BIT_VEC cppVar_72263;
	BIT_VEC cppVar_72264;
	BIT_VEC cppVar_72265;
	BIT_VEC cppVar_72266;
	BIT_VEC cppVar_72267;
	BIT_VEC cppVar_72268;
	BIT_VEC cppVar_72255;
	BIT_VEC cppVar_72269;
	bool cppVar_72270;
	BIT_VEC cppVar_72273;
	BIT_VEC cppVar_72274;
	BIT_VEC cppVar_72275;
	bool cppVar_72276;
	BIT_VEC cppVar_72277;
	BIT_VEC cppVar_72278;
	BIT_VEC cppVar_72279;
	BIT_VEC cppVar_72280;
	BIT_VEC cppVar_72281;
	BIT_VEC cppVar_72282;
	BIT_VEC cppVar_72283;
	BIT_VEC cppVar_72284;
	BIT_VEC cppVar_72285;
	BIT_VEC cppVar_72272;
	BIT_VEC cppVar_72286;
	bool cppVar_72287;
	BIT_VEC cppVar_72288;
	BIT_VEC cppVar_72271;
	BIT_VEC cppVar_72254;
	BIT_VEC cppVar_72237;
	BIT_VEC cppVar_72220;
	BIT_VEC cppVar_72203;
	BIT_VEC cppVar_72186;
	BIT_VEC cppVar_72169;
	BIT_VEC cppVar_72152;
	BIT_VEC cppVar_72135;
	BIT_VEC cppVar_72118;
	BIT_VEC cppVar_72101;
	BIT_VEC cppVar_72084;
	BIT_VEC cppVar_72067;
	BIT_VEC cppVar_72050;
	BIT_VEC cppVar_72033;
	BIT_VEC cppVar_72016;
	BIT_VEC cppVar_71999;
	BIT_VEC cppVar_71982;
	BIT_VEC cppVar_71965;
	BIT_VEC cppVar_71948;
	BIT_VEC cppVar_71931;
	BIT_VEC cppVar_71898;
	BIT_VEC cppVar_72289;
	BIT_VEC cppVar_72290;
	BIT_VEC cppVar_72291;
	BIT_VEC cppVar_72292;
	BIT_VEC cppVar_72293;
	BIT_VEC cppVar_72294;
	BIT_VEC cppVar_72295;
	BIT_VEC cppVar_72296;
	BIT_VEC cppVar_72297;
	BIT_VEC cppVar_71870;
	BIT_VEC cppVar_72299;
	BIT_VEC cppVar_72300;
	bool cppVar_72301;
	BIT_VEC cppVar_72303;
	BIT_VEC cppVar_72304;
	BIT_VEC cppVar_72305;
	BIT_VEC cppVar_72306;
	bool cppVar_72307;
	BIT_VEC cppVar_72309;
	BIT_VEC cppVar_72310;
	BIT_VEC cppVar_72311;
	BIT_VEC cppVar_72312;
	bool cppVar_72313;
	BIT_VEC cppVar_72314;
	BIT_VEC cppVar_72315;
	BIT_VEC cppVar_72316;
	BIT_VEC cppVar_72318;
	BIT_VEC cppVar_72319;
	BIT_VEC cppVar_72320;
	bool cppVar_72321;
	BIT_VEC cppVar_72323;
	BIT_VEC cppVar_72324;
	BIT_VEC cppVar_72325;
	bool cppVar_72326;
	BIT_VEC cppVar_72328;
	BIT_VEC cppVar_72329;
	BIT_VEC cppVar_72330;
	bool cppVar_72331;
	BIT_VEC cppVar_72333;
	BIT_VEC cppVar_72334;
	BIT_VEC cppVar_72335;
	bool cppVar_72336;
	BIT_VEC cppVar_72338;
	BIT_VEC cppVar_72339;
	BIT_VEC cppVar_72340;
	bool cppVar_72341;
	BIT_VEC cppVar_72343;
	BIT_VEC cppVar_72344;
	BIT_VEC cppVar_72345;
	bool cppVar_72346;
	BIT_VEC cppVar_72348;
	BIT_VEC cppVar_72349;
	BIT_VEC cppVar_72350;
	bool cppVar_72351;
	BIT_VEC cppVar_72353;
	BIT_VEC cppVar_72354;
	BIT_VEC cppVar_72355;
	bool cppVar_72356;
	BIT_VEC cppVar_72358;
	BIT_VEC cppVar_72359;
	BIT_VEC cppVar_72360;
	bool cppVar_72361;
	BIT_VEC cppVar_72363;
	BIT_VEC cppVar_72364;
	BIT_VEC cppVar_72365;
	bool cppVar_72366;
	BIT_VEC cppVar_72368;
	BIT_VEC cppVar_72369;
	BIT_VEC cppVar_72370;
	bool cppVar_72371;
	BIT_VEC cppVar_72373;
	BIT_VEC cppVar_72374;
	BIT_VEC cppVar_72375;
	bool cppVar_72376;
	BIT_VEC cppVar_72378;
	BIT_VEC cppVar_72379;
	BIT_VEC cppVar_72380;
	bool cppVar_72381;
	BIT_VEC cppVar_72383;
	BIT_VEC cppVar_72384;
	BIT_VEC cppVar_72385;
	bool cppVar_72386;
	BIT_VEC cppVar_72388;
	BIT_VEC cppVar_72389;
	BIT_VEC cppVar_72390;
	bool cppVar_72391;
	BIT_VEC cppVar_72393;
	BIT_VEC cppVar_72394;
	BIT_VEC cppVar_72395;
	bool cppVar_72396;
	BIT_VEC cppVar_72398;
	BIT_VEC cppVar_72399;
	BIT_VEC cppVar_72400;
	bool cppVar_72401;
	BIT_VEC cppVar_72403;
	BIT_VEC cppVar_72404;
	BIT_VEC cppVar_72405;
	bool cppVar_72406;
	BIT_VEC cppVar_72408;
	BIT_VEC cppVar_72409;
	BIT_VEC cppVar_72410;
	bool cppVar_72411;
	BIT_VEC cppVar_72413;
	BIT_VEC cppVar_72414;
	BIT_VEC cppVar_72415;
	bool cppVar_72416;
	BIT_VEC cppVar_72418;
	BIT_VEC cppVar_72419;
	BIT_VEC cppVar_72420;
	bool cppVar_72421;
	BIT_VEC cppVar_72422;
	BIT_VEC cppVar_72417;
	BIT_VEC cppVar_72412;
	BIT_VEC cppVar_72407;
	BIT_VEC cppVar_72402;
	BIT_VEC cppVar_72397;
	BIT_VEC cppVar_72392;
	BIT_VEC cppVar_72387;
	BIT_VEC cppVar_72382;
	BIT_VEC cppVar_72377;
	BIT_VEC cppVar_72372;
	BIT_VEC cppVar_72367;
	BIT_VEC cppVar_72362;
	BIT_VEC cppVar_72357;
	BIT_VEC cppVar_72352;
	BIT_VEC cppVar_72347;
	BIT_VEC cppVar_72342;
	BIT_VEC cppVar_72337;
	BIT_VEC cppVar_72332;
	BIT_VEC cppVar_72327;
	BIT_VEC cppVar_72322;
	BIT_VEC cppVar_72317;
	BIT_VEC cppVar_72308;
	BIT_VEC cppVar_72423;
	BIT_VEC cppVar_72424;
	BIT_VEC cppVar_72302;
	BIT_VEC cppVar_72298;
	BIT_VEC cppVar_71862;
	BIT_VEC cppVar_71731;
	BIT_VEC cppVar_71605;
	BIT_VEC cppVar_71476;
	BIT_VEC cppVar_71350;
	BIT_VEC cppVar_71221;
	BIT_VEC cppVar_71095;
	BIT_VEC cppVar_70966;
	BIT_VEC cppVar_70953;
	BIT_VEC cppVar_70827;
	BIT_VEC cppVar_70810;
	BIT_VEC cppVar_70793;
	BIT_VEC cppVar_70643;
	BIT_VEC cppVar_70493;
	BIT_VEC cppVar_70343;
	BIT_VEC cppVar_70193;
	BIT_VEC cppVar_70043;
	BIT_VEC cppVar_69893;
	BIT_VEC cppVar_69743;
	BIT_VEC cppVar_69593;
	BIT_VEC cppVar_69161;
	BIT_VEC cppVar_68331;
	BIT_VEC cppVar_68317;
	BIT_VEC cppVar_68306;
	BIT_VEC cppVar_67874;
	cppVar_67875 = ROM.rd(PC);
	cppVar_67877 = (cppVar_67875 == 210);
	if (cppVar_67877) {
	cppVar_67881 = PC + 1;
	cppVar_67881 = (cppVar_67881 & cppMask_un_16_);
	cppVar_67882 = ROM.rd(cppVar_67881);
	cppVar_67883 = (cppVar_67882 >> 7) & cppMask_un_1_;
	cppVar_67885 = (cppVar_67883 == 1);
	if (cppVar_67885) {
	cppVar_67886 = PC + 1;
	cppVar_67886 = (cppVar_67886 & cppMask_un_16_);
	cppVar_67887 = ROM.rd(cppVar_67886);
	cppVar_67888 = (cppVar_67887 >> 3) & cppMask_un_5_;
	cppVar_67890 = (cppVar_67888 << 3) | 0;
	cppVar_67890 = (cppVar_67890 & cppMask_un_8_);
	cppVar_67879 = cppVar_67890;
	} else {
	cppVar_67891 = PC + 1;
	cppVar_67891 = (cppVar_67891 & cppMask_un_16_);
	cppVar_67892 = ROM.rd(cppVar_67891);
	cppVar_67893 = (cppVar_67892 >> 3) & cppMask_un_5_;
	cppVar_67894 = (cppVar_67893 & cppMask_un_5_);
	cppVar_67896 = cppVar_67894 + 32;
	cppVar_67896 = (cppVar_67896 & cppMask_un_8_);
	cppVar_67879 = cppVar_67896;
	}
	cppVar_67898 = (cppVar_67879 == 136);
	if (cppVar_67898) {
	cppVar_67900 = PC + 1;
	cppVar_67900 = (cppVar_67900 & cppMask_un_16_);
	cppVar_67901 = ROM.rd(cppVar_67900);
	cppVar_67902 = (cppVar_67901 >> 0) & cppMask_un_3_;
	cppVar_67903 = (cppVar_67902 & cppMask_un_3_);
	cppVar_67904 = 1 << static_cast<unsigned>(cppVar_67903);
	cppVar_67904 = (cppVar_67904 & cppMask_un_8_);
	cppVar_67905 = ~cppVar_67904;
	cppVar_67908 = PC + 1;
	cppVar_67908 = (cppVar_67908 & cppMask_un_16_);
	cppVar_67909 = ROM.rd(cppVar_67908);
	cppVar_67910 = (cppVar_67909 >> 7) & cppMask_un_1_;
	cppVar_67911 = (cppVar_67910 == 1);
	if (cppVar_67911) {
	cppVar_67912 = PC + 1;
	cppVar_67912 = (cppVar_67912 & cppMask_un_16_);
	cppVar_67913 = ROM.rd(cppVar_67912);
	cppVar_67914 = (cppVar_67913 >> 3) & cppMask_un_5_;
	cppVar_67915 = (cppVar_67914 << 3) | 0;
	cppVar_67915 = (cppVar_67915 & cppMask_un_8_);
	cppVar_67907 = cppVar_67915;
	} else {
	cppVar_67916 = PC + 1;
	cppVar_67916 = (cppVar_67916 & cppMask_un_16_);
	cppVar_67917 = ROM.rd(cppVar_67916);
	cppVar_67918 = (cppVar_67917 >> 3) & cppMask_un_5_;
	cppVar_67919 = (cppVar_67918 & cppMask_un_5_);
	cppVar_67920 = cppVar_67919 + 32;
	cppVar_67920 = (cppVar_67920 & cppMask_un_8_);
	cppVar_67907 = cppVar_67920;
	}
	cppVar_67921 = (cppVar_67907 >> 7) & cppMask_un_1_;
	cppVar_67923 = (cppVar_67921 == 0);
	if (cppVar_67923) {
	cppVar_67925 = PC + 1;
	cppVar_67925 = (cppVar_67925 & cppMask_un_16_);
	cppVar_67926 = ROM.rd(cppVar_67925);
	cppVar_67927 = (cppVar_67926 >> 7) & cppMask_un_1_;
	cppVar_67928 = (cppVar_67927 == 1);
	if (cppVar_67928) {
	cppVar_67929 = PC + 1;
	cppVar_67929 = (cppVar_67929 & cppMask_un_16_);
	cppVar_67930 = ROM.rd(cppVar_67929);
	cppVar_67931 = (cppVar_67930 >> 3) & cppMask_un_5_;
	cppVar_67932 = (cppVar_67931 << 3) | 0;
	cppVar_67932 = (cppVar_67932 & cppMask_un_8_);
	cppVar_67924 = cppVar_67932;
	} else {
	cppVar_67933 = PC + 1;
	cppVar_67933 = (cppVar_67933 & cppMask_un_16_);
	cppVar_67934 = ROM.rd(cppVar_67933);
	cppVar_67935 = (cppVar_67934 >> 3) & cppMask_un_5_;
	cppVar_67936 = (cppVar_67935 & cppMask_un_5_);
	cppVar_67937 = cppVar_67936 + 32;
	cppVar_67937 = (cppVar_67937 & cppMask_un_8_);
	cppVar_67924 = cppVar_67937;
	}
	cppVar_67938 = IRAM.rd(cppVar_67924);
	cppVar_67906 = cppVar_67938;
	} else {
	cppVar_67941 = PC + 1;
	cppVar_67941 = (cppVar_67941 & cppMask_un_16_);
	cppVar_67942 = ROM.rd(cppVar_67941);
	cppVar_67943 = (cppVar_67942 >> 7) & cppMask_un_1_;
	cppVar_67944 = (cppVar_67943 == 1);
	if (cppVar_67944) {
	cppVar_67945 = PC + 1;
	cppVar_67945 = (cppVar_67945 & cppMask_un_16_);
	cppVar_67946 = ROM.rd(cppVar_67945);
	cppVar_67947 = (cppVar_67946 >> 3) & cppMask_un_5_;
	cppVar_67948 = (cppVar_67947 << 3) | 0;
	cppVar_67948 = (cppVar_67948 & cppMask_un_8_);
	cppVar_67940 = cppVar_67948;
	} else {
	cppVar_67949 = PC + 1;
	cppVar_67949 = (cppVar_67949 & cppMask_un_16_);
	cppVar_67950 = ROM.rd(cppVar_67949);
	cppVar_67951 = (cppVar_67950 >> 3) & cppMask_un_5_;
	cppVar_67952 = (cppVar_67951 & cppMask_un_5_);
	cppVar_67953 = cppVar_67952 + 32;
	cppVar_67953 = (cppVar_67953 & cppMask_un_8_);
	cppVar_67940 = cppVar_67953;
	}
	cppVar_67955 = (cppVar_67940 == 128);
	if (cppVar_67955) {
	cppVar_67939 = P0;
	} else {
	cppVar_67958 = PC + 1;
	cppVar_67958 = (cppVar_67958 & cppMask_un_16_);
	cppVar_67959 = ROM.rd(cppVar_67958);
	cppVar_67960 = (cppVar_67959 >> 7) & cppMask_un_1_;
	cppVar_67961 = (cppVar_67960 == 1);
	if (cppVar_67961) {
	cppVar_67962 = PC + 1;
	cppVar_67962 = (cppVar_67962 & cppMask_un_16_);
	cppVar_67963 = ROM.rd(cppVar_67962);
	cppVar_67964 = (cppVar_67963 >> 3) & cppMask_un_5_;
	cppVar_67965 = (cppVar_67964 << 3) | 0;
	cppVar_67965 = (cppVar_67965 & cppMask_un_8_);
	cppVar_67957 = cppVar_67965;
	} else {
	cppVar_67966 = PC + 1;
	cppVar_67966 = (cppVar_67966 & cppMask_un_16_);
	cppVar_67967 = ROM.rd(cppVar_67966);
	cppVar_67968 = (cppVar_67967 >> 3) & cppMask_un_5_;
	cppVar_67969 = (cppVar_67968 & cppMask_un_5_);
	cppVar_67970 = cppVar_67969 + 32;
	cppVar_67970 = (cppVar_67970 & cppMask_un_8_);
	cppVar_67957 = cppVar_67970;
	}
	cppVar_67972 = (cppVar_67957 == 129);
	if (cppVar_67972) {
	cppVar_67956 = SP;
	} else {
	cppVar_67975 = PC + 1;
	cppVar_67975 = (cppVar_67975 & cppMask_un_16_);
	cppVar_67976 = ROM.rd(cppVar_67975);
	cppVar_67977 = (cppVar_67976 >> 7) & cppMask_un_1_;
	cppVar_67978 = (cppVar_67977 == 1);
	if (cppVar_67978) {
	cppVar_67979 = PC + 1;
	cppVar_67979 = (cppVar_67979 & cppMask_un_16_);
	cppVar_67980 = ROM.rd(cppVar_67979);
	cppVar_67981 = (cppVar_67980 >> 3) & cppMask_un_5_;
	cppVar_67982 = (cppVar_67981 << 3) | 0;
	cppVar_67982 = (cppVar_67982 & cppMask_un_8_);
	cppVar_67974 = cppVar_67982;
	} else {
	cppVar_67983 = PC + 1;
	cppVar_67983 = (cppVar_67983 & cppMask_un_16_);
	cppVar_67984 = ROM.rd(cppVar_67983);
	cppVar_67985 = (cppVar_67984 >> 3) & cppMask_un_5_;
	cppVar_67986 = (cppVar_67985 & cppMask_un_5_);
	cppVar_67987 = cppVar_67986 + 32;
	cppVar_67987 = (cppVar_67987 & cppMask_un_8_);
	cppVar_67974 = cppVar_67987;
	}
	cppVar_67989 = (cppVar_67974 == 130);
	if (cppVar_67989) {
	cppVar_67973 = DPL;
	} else {
	cppVar_67992 = PC + 1;
	cppVar_67992 = (cppVar_67992 & cppMask_un_16_);
	cppVar_67993 = ROM.rd(cppVar_67992);
	cppVar_67994 = (cppVar_67993 >> 7) & cppMask_un_1_;
	cppVar_67995 = (cppVar_67994 == 1);
	if (cppVar_67995) {
	cppVar_67996 = PC + 1;
	cppVar_67996 = (cppVar_67996 & cppMask_un_16_);
	cppVar_67997 = ROM.rd(cppVar_67996);
	cppVar_67998 = (cppVar_67997 >> 3) & cppMask_un_5_;
	cppVar_67999 = (cppVar_67998 << 3) | 0;
	cppVar_67999 = (cppVar_67999 & cppMask_un_8_);
	cppVar_67991 = cppVar_67999;
	} else {
	cppVar_68000 = PC + 1;
	cppVar_68000 = (cppVar_68000 & cppMask_un_16_);
	cppVar_68001 = ROM.rd(cppVar_68000);
	cppVar_68002 = (cppVar_68001 >> 3) & cppMask_un_5_;
	cppVar_68003 = (cppVar_68002 & cppMask_un_5_);
	cppVar_68004 = cppVar_68003 + 32;
	cppVar_68004 = (cppVar_68004 & cppMask_un_8_);
	cppVar_67991 = cppVar_68004;
	}
	cppVar_68006 = (cppVar_67991 == 131);
	if (cppVar_68006) {
	cppVar_67990 = DPH;
	} else {
	cppVar_68009 = PC + 1;
	cppVar_68009 = (cppVar_68009 & cppMask_un_16_);
	cppVar_68010 = ROM.rd(cppVar_68009);
	cppVar_68011 = (cppVar_68010 >> 7) & cppMask_un_1_;
	cppVar_68012 = (cppVar_68011 == 1);
	if (cppVar_68012) {
	cppVar_68013 = PC + 1;
	cppVar_68013 = (cppVar_68013 & cppMask_un_16_);
	cppVar_68014 = ROM.rd(cppVar_68013);
	cppVar_68015 = (cppVar_68014 >> 3) & cppMask_un_5_;
	cppVar_68016 = (cppVar_68015 << 3) | 0;
	cppVar_68016 = (cppVar_68016 & cppMask_un_8_);
	cppVar_68008 = cppVar_68016;
	} else {
	cppVar_68017 = PC + 1;
	cppVar_68017 = (cppVar_68017 & cppMask_un_16_);
	cppVar_68018 = ROM.rd(cppVar_68017);
	cppVar_68019 = (cppVar_68018 >> 3) & cppMask_un_5_;
	cppVar_68020 = (cppVar_68019 & cppMask_un_5_);
	cppVar_68021 = cppVar_68020 + 32;
	cppVar_68021 = (cppVar_68021 & cppMask_un_8_);
	cppVar_68008 = cppVar_68021;
	}
	cppVar_68023 = (cppVar_68008 == 135);
	if (cppVar_68023) {
	cppVar_68007 = PCON;
	} else {
	cppVar_68026 = PC + 1;
	cppVar_68026 = (cppVar_68026 & cppMask_un_16_);
	cppVar_68027 = ROM.rd(cppVar_68026);
	cppVar_68028 = (cppVar_68027 >> 7) & cppMask_un_1_;
	cppVar_68029 = (cppVar_68028 == 1);
	if (cppVar_68029) {
	cppVar_68030 = PC + 1;
	cppVar_68030 = (cppVar_68030 & cppMask_un_16_);
	cppVar_68031 = ROM.rd(cppVar_68030);
	cppVar_68032 = (cppVar_68031 >> 3) & cppMask_un_5_;
	cppVar_68033 = (cppVar_68032 << 3) | 0;
	cppVar_68033 = (cppVar_68033 & cppMask_un_8_);
	cppVar_68025 = cppVar_68033;
	} else {
	cppVar_68034 = PC + 1;
	cppVar_68034 = (cppVar_68034 & cppMask_un_16_);
	cppVar_68035 = ROM.rd(cppVar_68034);
	cppVar_68036 = (cppVar_68035 >> 3) & cppMask_un_5_;
	cppVar_68037 = (cppVar_68036 & cppMask_un_5_);
	cppVar_68038 = cppVar_68037 + 32;
	cppVar_68038 = (cppVar_68038 & cppMask_un_8_);
	cppVar_68025 = cppVar_68038;
	}
	cppVar_68040 = (cppVar_68025 == 136);
	if (cppVar_68040) {
	cppVar_68024 = TCON;
	} else {
	cppVar_68043 = PC + 1;
	cppVar_68043 = (cppVar_68043 & cppMask_un_16_);
	cppVar_68044 = ROM.rd(cppVar_68043);
	cppVar_68045 = (cppVar_68044 >> 7) & cppMask_un_1_;
	cppVar_68046 = (cppVar_68045 == 1);
	if (cppVar_68046) {
	cppVar_68047 = PC + 1;
	cppVar_68047 = (cppVar_68047 & cppMask_un_16_);
	cppVar_68048 = ROM.rd(cppVar_68047);
	cppVar_68049 = (cppVar_68048 >> 3) & cppMask_un_5_;
	cppVar_68050 = (cppVar_68049 << 3) | 0;
	cppVar_68050 = (cppVar_68050 & cppMask_un_8_);
	cppVar_68042 = cppVar_68050;
	} else {
	cppVar_68051 = PC + 1;
	cppVar_68051 = (cppVar_68051 & cppMask_un_16_);
	cppVar_68052 = ROM.rd(cppVar_68051);
	cppVar_68053 = (cppVar_68052 >> 3) & cppMask_un_5_;
	cppVar_68054 = (cppVar_68053 & cppMask_un_5_);
	cppVar_68055 = cppVar_68054 + 32;
	cppVar_68055 = (cppVar_68055 & cppMask_un_8_);
	cppVar_68042 = cppVar_68055;
	}
	cppVar_68057 = (cppVar_68042 == 137);
	if (cppVar_68057) {
	cppVar_68041 = TMOD;
	} else {
	cppVar_68060 = PC + 1;
	cppVar_68060 = (cppVar_68060 & cppMask_un_16_);
	cppVar_68061 = ROM.rd(cppVar_68060);
	cppVar_68062 = (cppVar_68061 >> 7) & cppMask_un_1_;
	cppVar_68063 = (cppVar_68062 == 1);
	if (cppVar_68063) {
	cppVar_68064 = PC + 1;
	cppVar_68064 = (cppVar_68064 & cppMask_un_16_);
	cppVar_68065 = ROM.rd(cppVar_68064);
	cppVar_68066 = (cppVar_68065 >> 3) & cppMask_un_5_;
	cppVar_68067 = (cppVar_68066 << 3) | 0;
	cppVar_68067 = (cppVar_68067 & cppMask_un_8_);
	cppVar_68059 = cppVar_68067;
	} else {
	cppVar_68068 = PC + 1;
	cppVar_68068 = (cppVar_68068 & cppMask_un_16_);
	cppVar_68069 = ROM.rd(cppVar_68068);
	cppVar_68070 = (cppVar_68069 >> 3) & cppMask_un_5_;
	cppVar_68071 = (cppVar_68070 & cppMask_un_5_);
	cppVar_68072 = cppVar_68071 + 32;
	cppVar_68072 = (cppVar_68072 & cppMask_un_8_);
	cppVar_68059 = cppVar_68072;
	}
	cppVar_68074 = (cppVar_68059 == 138);
	if (cppVar_68074) {
	cppVar_68058 = TL0;
	} else {
	cppVar_68077 = PC + 1;
	cppVar_68077 = (cppVar_68077 & cppMask_un_16_);
	cppVar_68078 = ROM.rd(cppVar_68077);
	cppVar_68079 = (cppVar_68078 >> 7) & cppMask_un_1_;
	cppVar_68080 = (cppVar_68079 == 1);
	if (cppVar_68080) {
	cppVar_68081 = PC + 1;
	cppVar_68081 = (cppVar_68081 & cppMask_un_16_);
	cppVar_68082 = ROM.rd(cppVar_68081);
	cppVar_68083 = (cppVar_68082 >> 3) & cppMask_un_5_;
	cppVar_68084 = (cppVar_68083 << 3) | 0;
	cppVar_68084 = (cppVar_68084 & cppMask_un_8_);
	cppVar_68076 = cppVar_68084;
	} else {
	cppVar_68085 = PC + 1;
	cppVar_68085 = (cppVar_68085 & cppMask_un_16_);
	cppVar_68086 = ROM.rd(cppVar_68085);
	cppVar_68087 = (cppVar_68086 >> 3) & cppMask_un_5_;
	cppVar_68088 = (cppVar_68087 & cppMask_un_5_);
	cppVar_68089 = cppVar_68088 + 32;
	cppVar_68089 = (cppVar_68089 & cppMask_un_8_);
	cppVar_68076 = cppVar_68089;
	}
	cppVar_68091 = (cppVar_68076 == 140);
	if (cppVar_68091) {
	cppVar_68075 = TH0;
	} else {
	cppVar_68094 = PC + 1;
	cppVar_68094 = (cppVar_68094 & cppMask_un_16_);
	cppVar_68095 = ROM.rd(cppVar_68094);
	cppVar_68096 = (cppVar_68095 >> 7) & cppMask_un_1_;
	cppVar_68097 = (cppVar_68096 == 1);
	if (cppVar_68097) {
	cppVar_68098 = PC + 1;
	cppVar_68098 = (cppVar_68098 & cppMask_un_16_);
	cppVar_68099 = ROM.rd(cppVar_68098);
	cppVar_68100 = (cppVar_68099 >> 3) & cppMask_un_5_;
	cppVar_68101 = (cppVar_68100 << 3) | 0;
	cppVar_68101 = (cppVar_68101 & cppMask_un_8_);
	cppVar_68093 = cppVar_68101;
	} else {
	cppVar_68102 = PC + 1;
	cppVar_68102 = (cppVar_68102 & cppMask_un_16_);
	cppVar_68103 = ROM.rd(cppVar_68102);
	cppVar_68104 = (cppVar_68103 >> 3) & cppMask_un_5_;
	cppVar_68105 = (cppVar_68104 & cppMask_un_5_);
	cppVar_68106 = cppVar_68105 + 32;
	cppVar_68106 = (cppVar_68106 & cppMask_un_8_);
	cppVar_68093 = cppVar_68106;
	}
	cppVar_68108 = (cppVar_68093 == 139);
	if (cppVar_68108) {
	cppVar_68092 = TL1;
	} else {
	cppVar_68111 = PC + 1;
	cppVar_68111 = (cppVar_68111 & cppMask_un_16_);
	cppVar_68112 = ROM.rd(cppVar_68111);
	cppVar_68113 = (cppVar_68112 >> 7) & cppMask_un_1_;
	cppVar_68114 = (cppVar_68113 == 1);
	if (cppVar_68114) {
	cppVar_68115 = PC + 1;
	cppVar_68115 = (cppVar_68115 & cppMask_un_16_);
	cppVar_68116 = ROM.rd(cppVar_68115);
	cppVar_68117 = (cppVar_68116 >> 3) & cppMask_un_5_;
	cppVar_68118 = (cppVar_68117 << 3) | 0;
	cppVar_68118 = (cppVar_68118 & cppMask_un_8_);
	cppVar_68110 = cppVar_68118;
	} else {
	cppVar_68119 = PC + 1;
	cppVar_68119 = (cppVar_68119 & cppMask_un_16_);
	cppVar_68120 = ROM.rd(cppVar_68119);
	cppVar_68121 = (cppVar_68120 >> 3) & cppMask_un_5_;
	cppVar_68122 = (cppVar_68121 & cppMask_un_5_);
	cppVar_68123 = cppVar_68122 + 32;
	cppVar_68123 = (cppVar_68123 & cppMask_un_8_);
	cppVar_68110 = cppVar_68123;
	}
	cppVar_68125 = (cppVar_68110 == 141);
	if (cppVar_68125) {
	cppVar_68109 = TH1;
	} else {
	cppVar_68128 = PC + 1;
	cppVar_68128 = (cppVar_68128 & cppMask_un_16_);
	cppVar_68129 = ROM.rd(cppVar_68128);
	cppVar_68130 = (cppVar_68129 >> 7) & cppMask_un_1_;
	cppVar_68131 = (cppVar_68130 == 1);
	if (cppVar_68131) {
	cppVar_68132 = PC + 1;
	cppVar_68132 = (cppVar_68132 & cppMask_un_16_);
	cppVar_68133 = ROM.rd(cppVar_68132);
	cppVar_68134 = (cppVar_68133 >> 3) & cppMask_un_5_;
	cppVar_68135 = (cppVar_68134 << 3) | 0;
	cppVar_68135 = (cppVar_68135 & cppMask_un_8_);
	cppVar_68127 = cppVar_68135;
	} else {
	cppVar_68136 = PC + 1;
	cppVar_68136 = (cppVar_68136 & cppMask_un_16_);
	cppVar_68137 = ROM.rd(cppVar_68136);
	cppVar_68138 = (cppVar_68137 >> 3) & cppMask_un_5_;
	cppVar_68139 = (cppVar_68138 & cppMask_un_5_);
	cppVar_68140 = cppVar_68139 + 32;
	cppVar_68140 = (cppVar_68140 & cppMask_un_8_);
	cppVar_68127 = cppVar_68140;
	}
	cppVar_68142 = (cppVar_68127 == 144);
	if (cppVar_68142) {
	cppVar_68126 = P1;
	} else {
	cppVar_68145 = PC + 1;
	cppVar_68145 = (cppVar_68145 & cppMask_un_16_);
	cppVar_68146 = ROM.rd(cppVar_68145);
	cppVar_68147 = (cppVar_68146 >> 7) & cppMask_un_1_;
	cppVar_68148 = (cppVar_68147 == 1);
	if (cppVar_68148) {
	cppVar_68149 = PC + 1;
	cppVar_68149 = (cppVar_68149 & cppMask_un_16_);
	cppVar_68150 = ROM.rd(cppVar_68149);
	cppVar_68151 = (cppVar_68150 >> 3) & cppMask_un_5_;
	cppVar_68152 = (cppVar_68151 << 3) | 0;
	cppVar_68152 = (cppVar_68152 & cppMask_un_8_);
	cppVar_68144 = cppVar_68152;
	} else {
	cppVar_68153 = PC + 1;
	cppVar_68153 = (cppVar_68153 & cppMask_un_16_);
	cppVar_68154 = ROM.rd(cppVar_68153);
	cppVar_68155 = (cppVar_68154 >> 3) & cppMask_un_5_;
	cppVar_68156 = (cppVar_68155 & cppMask_un_5_);
	cppVar_68157 = cppVar_68156 + 32;
	cppVar_68157 = (cppVar_68157 & cppMask_un_8_);
	cppVar_68144 = cppVar_68157;
	}
	cppVar_68159 = (cppVar_68144 == 152);
	if (cppVar_68159) {
	cppVar_68143 = SCON;
	} else {
	cppVar_68162 = PC + 1;
	cppVar_68162 = (cppVar_68162 & cppMask_un_16_);
	cppVar_68163 = ROM.rd(cppVar_68162);
	cppVar_68164 = (cppVar_68163 >> 7) & cppMask_un_1_;
	cppVar_68165 = (cppVar_68164 == 1);
	if (cppVar_68165) {
	cppVar_68166 = PC + 1;
	cppVar_68166 = (cppVar_68166 & cppMask_un_16_);
	cppVar_68167 = ROM.rd(cppVar_68166);
	cppVar_68168 = (cppVar_68167 >> 3) & cppMask_un_5_;
	cppVar_68169 = (cppVar_68168 << 3) | 0;
	cppVar_68169 = (cppVar_68169 & cppMask_un_8_);
	cppVar_68161 = cppVar_68169;
	} else {
	cppVar_68170 = PC + 1;
	cppVar_68170 = (cppVar_68170 & cppMask_un_16_);
	cppVar_68171 = ROM.rd(cppVar_68170);
	cppVar_68172 = (cppVar_68171 >> 3) & cppMask_un_5_;
	cppVar_68173 = (cppVar_68172 & cppMask_un_5_);
	cppVar_68174 = cppVar_68173 + 32;
	cppVar_68174 = (cppVar_68174 & cppMask_un_8_);
	cppVar_68161 = cppVar_68174;
	}
	cppVar_68176 = (cppVar_68161 == 153);
	if (cppVar_68176) {
	cppVar_68160 = SBUF;
	} else {
	cppVar_68179 = PC + 1;
	cppVar_68179 = (cppVar_68179 & cppMask_un_16_);
	cppVar_68180 = ROM.rd(cppVar_68179);
	cppVar_68181 = (cppVar_68180 >> 7) & cppMask_un_1_;
	cppVar_68182 = (cppVar_68181 == 1);
	if (cppVar_68182) {
	cppVar_68183 = PC + 1;
	cppVar_68183 = (cppVar_68183 & cppMask_un_16_);
	cppVar_68184 = ROM.rd(cppVar_68183);
	cppVar_68185 = (cppVar_68184 >> 3) & cppMask_un_5_;
	cppVar_68186 = (cppVar_68185 << 3) | 0;
	cppVar_68186 = (cppVar_68186 & cppMask_un_8_);
	cppVar_68178 = cppVar_68186;
	} else {
	cppVar_68187 = PC + 1;
	cppVar_68187 = (cppVar_68187 & cppMask_un_16_);
	cppVar_68188 = ROM.rd(cppVar_68187);
	cppVar_68189 = (cppVar_68188 >> 3) & cppMask_un_5_;
	cppVar_68190 = (cppVar_68189 & cppMask_un_5_);
	cppVar_68191 = cppVar_68190 + 32;
	cppVar_68191 = (cppVar_68191 & cppMask_un_8_);
	cppVar_68178 = cppVar_68191;
	}
	cppVar_68193 = (cppVar_68178 == 160);
	if (cppVar_68193) {
	cppVar_68177 = P2;
	} else {
	cppVar_68196 = PC + 1;
	cppVar_68196 = (cppVar_68196 & cppMask_un_16_);
	cppVar_68197 = ROM.rd(cppVar_68196);
	cppVar_68198 = (cppVar_68197 >> 7) & cppMask_un_1_;
	cppVar_68199 = (cppVar_68198 == 1);
	if (cppVar_68199) {
	cppVar_68200 = PC + 1;
	cppVar_68200 = (cppVar_68200 & cppMask_un_16_);
	cppVar_68201 = ROM.rd(cppVar_68200);
	cppVar_68202 = (cppVar_68201 >> 3) & cppMask_un_5_;
	cppVar_68203 = (cppVar_68202 << 3) | 0;
	cppVar_68203 = (cppVar_68203 & cppMask_un_8_);
	cppVar_68195 = cppVar_68203;
	} else {
	cppVar_68204 = PC + 1;
	cppVar_68204 = (cppVar_68204 & cppMask_un_16_);
	cppVar_68205 = ROM.rd(cppVar_68204);
	cppVar_68206 = (cppVar_68205 >> 3) & cppMask_un_5_;
	cppVar_68207 = (cppVar_68206 & cppMask_un_5_);
	cppVar_68208 = cppVar_68207 + 32;
	cppVar_68208 = (cppVar_68208 & cppMask_un_8_);
	cppVar_68195 = cppVar_68208;
	}
	cppVar_68210 = (cppVar_68195 == 168);
	if (cppVar_68210) {
	cppVar_68194 = IE;
	} else {
	cppVar_68213 = PC + 1;
	cppVar_68213 = (cppVar_68213 & cppMask_un_16_);
	cppVar_68214 = ROM.rd(cppVar_68213);
	cppVar_68215 = (cppVar_68214 >> 7) & cppMask_un_1_;
	cppVar_68216 = (cppVar_68215 == 1);
	if (cppVar_68216) {
	cppVar_68217 = PC + 1;
	cppVar_68217 = (cppVar_68217 & cppMask_un_16_);
	cppVar_68218 = ROM.rd(cppVar_68217);
	cppVar_68219 = (cppVar_68218 >> 3) & cppMask_un_5_;
	cppVar_68220 = (cppVar_68219 << 3) | 0;
	cppVar_68220 = (cppVar_68220 & cppMask_un_8_);
	cppVar_68212 = cppVar_68220;
	} else {
	cppVar_68221 = PC + 1;
	cppVar_68221 = (cppVar_68221 & cppMask_un_16_);
	cppVar_68222 = ROM.rd(cppVar_68221);
	cppVar_68223 = (cppVar_68222 >> 3) & cppMask_un_5_;
	cppVar_68224 = (cppVar_68223 & cppMask_un_5_);
	cppVar_68225 = cppVar_68224 + 32;
	cppVar_68225 = (cppVar_68225 & cppMask_un_8_);
	cppVar_68212 = cppVar_68225;
	}
	cppVar_68227 = (cppVar_68212 == 176);
	if (cppVar_68227) {
	cppVar_68211 = P3;
	} else {
	cppVar_68230 = PC + 1;
	cppVar_68230 = (cppVar_68230 & cppMask_un_16_);
	cppVar_68231 = ROM.rd(cppVar_68230);
	cppVar_68232 = (cppVar_68231 >> 7) & cppMask_un_1_;
	cppVar_68233 = (cppVar_68232 == 1);
	if (cppVar_68233) {
	cppVar_68234 = PC + 1;
	cppVar_68234 = (cppVar_68234 & cppMask_un_16_);
	cppVar_68235 = ROM.rd(cppVar_68234);
	cppVar_68236 = (cppVar_68235 >> 3) & cppMask_un_5_;
	cppVar_68237 = (cppVar_68236 << 3) | 0;
	cppVar_68237 = (cppVar_68237 & cppMask_un_8_);
	cppVar_68229 = cppVar_68237;
	} else {
	cppVar_68238 = PC + 1;
	cppVar_68238 = (cppVar_68238 & cppMask_un_16_);
	cppVar_68239 = ROM.rd(cppVar_68238);
	cppVar_68240 = (cppVar_68239 >> 3) & cppMask_un_5_;
	cppVar_68241 = (cppVar_68240 & cppMask_un_5_);
	cppVar_68242 = cppVar_68241 + 32;
	cppVar_68242 = (cppVar_68242 & cppMask_un_8_);
	cppVar_68229 = cppVar_68242;
	}
	cppVar_68244 = (cppVar_68229 == 184);
	if (cppVar_68244) {
	cppVar_68228 = IP;
	} else {
	cppVar_68247 = PC + 1;
	cppVar_68247 = (cppVar_68247 & cppMask_un_16_);
	cppVar_68248 = ROM.rd(cppVar_68247);
	cppVar_68249 = (cppVar_68248 >> 7) & cppMask_un_1_;
	cppVar_68250 = (cppVar_68249 == 1);
	if (cppVar_68250) {
	cppVar_68251 = PC + 1;
	cppVar_68251 = (cppVar_68251 & cppMask_un_16_);
	cppVar_68252 = ROM.rd(cppVar_68251);
	cppVar_68253 = (cppVar_68252 >> 3) & cppMask_un_5_;
	cppVar_68254 = (cppVar_68253 << 3) | 0;
	cppVar_68254 = (cppVar_68254 & cppMask_un_8_);
	cppVar_68246 = cppVar_68254;
	} else {
	cppVar_68255 = PC + 1;
	cppVar_68255 = (cppVar_68255 & cppMask_un_16_);
	cppVar_68256 = ROM.rd(cppVar_68255);
	cppVar_68257 = (cppVar_68256 >> 3) & cppMask_un_5_;
	cppVar_68258 = (cppVar_68257 & cppMask_un_5_);
	cppVar_68259 = cppVar_68258 + 32;
	cppVar_68259 = (cppVar_68259 & cppMask_un_8_);
	cppVar_68246 = cppVar_68259;
	}
	cppVar_68261 = (cppVar_68246 == 208);
	if (cppVar_68261) {
	cppVar_68245 = PSW;
	} else {
	cppVar_68264 = PC + 1;
	cppVar_68264 = (cppVar_68264 & cppMask_un_16_);
	cppVar_68265 = ROM.rd(cppVar_68264);
	cppVar_68266 = (cppVar_68265 >> 7) & cppMask_un_1_;
	cppVar_68267 = (cppVar_68266 == 1);
	if (cppVar_68267) {
	cppVar_68268 = PC + 1;
	cppVar_68268 = (cppVar_68268 & cppMask_un_16_);
	cppVar_68269 = ROM.rd(cppVar_68268);
	cppVar_68270 = (cppVar_68269 >> 3) & cppMask_un_5_;
	cppVar_68271 = (cppVar_68270 << 3) | 0;
	cppVar_68271 = (cppVar_68271 & cppMask_un_8_);
	cppVar_68263 = cppVar_68271;
	} else {
	cppVar_68272 = PC + 1;
	cppVar_68272 = (cppVar_68272 & cppMask_un_16_);
	cppVar_68273 = ROM.rd(cppVar_68272);
	cppVar_68274 = (cppVar_68273 >> 3) & cppMask_un_5_;
	cppVar_68275 = (cppVar_68274 & cppMask_un_5_);
	cppVar_68276 = cppVar_68275 + 32;
	cppVar_68276 = (cppVar_68276 & cppMask_un_8_);
	cppVar_68263 = cppVar_68276;
	}
	cppVar_68278 = (cppVar_68263 == 224);
	if (cppVar_68278) {
	cppVar_68262 = ACC;
	} else {
	cppVar_68281 = PC + 1;
	cppVar_68281 = (cppVar_68281 & cppMask_un_16_);
	cppVar_68282 = ROM.rd(cppVar_68281);
	cppVar_68283 = (cppVar_68282 >> 7) & cppMask_un_1_;
	cppVar_68284 = (cppVar_68283 == 1);
	if (cppVar_68284) {
	cppVar_68285 = PC + 1;
	cppVar_68285 = (cppVar_68285 & cppMask_un_16_);
	cppVar_68286 = ROM.rd(cppVar_68285);
	cppVar_68287 = (cppVar_68286 >> 3) & cppMask_un_5_;
	cppVar_68288 = (cppVar_68287 << 3) | 0;
	cppVar_68288 = (cppVar_68288 & cppMask_un_8_);
	cppVar_68280 = cppVar_68288;
	} else {
	cppVar_68289 = PC + 1;
	cppVar_68289 = (cppVar_68289 & cppMask_un_16_);
	cppVar_68290 = ROM.rd(cppVar_68289);
	cppVar_68291 = (cppVar_68290 >> 3) & cppMask_un_5_;
	cppVar_68292 = (cppVar_68291 & cppMask_un_5_);
	cppVar_68293 = cppVar_68292 + 32;
	cppVar_68293 = (cppVar_68293 & cppMask_un_8_);
	cppVar_68280 = cppVar_68293;
	}
	cppVar_68295 = (cppVar_68280 == 240);
	if (cppVar_68295) {
	cppVar_68279 = B;
	} else {
	cppVar_68279 = 0;
	}
	cppVar_68262 = cppVar_68279;
	}
	cppVar_68245 = cppVar_68262;
	}
	cppVar_68228 = cppVar_68245;
	}
	cppVar_68211 = cppVar_68228;
	}
	cppVar_68194 = cppVar_68211;
	}
	cppVar_68177 = cppVar_68194;
	}
	cppVar_68160 = cppVar_68177;
	}
	cppVar_68143 = cppVar_68160;
	}
	cppVar_68126 = cppVar_68143;
	}
	cppVar_68109 = cppVar_68126;
	}
	cppVar_68092 = cppVar_68109;
	}
	cppVar_68075 = cppVar_68092;
	}
	cppVar_68058 = cppVar_68075;
	}
	cppVar_68041 = cppVar_68058;
	}
	cppVar_68024 = cppVar_68041;
	}
	cppVar_68007 = cppVar_68024;
	}
	cppVar_67990 = cppVar_68007;
	}
	cppVar_67973 = cppVar_67990;
	}
	cppVar_67956 = cppVar_67973;
	}
	cppVar_67939 = cppVar_67956;
	}
	cppVar_67906 = cppVar_67939;
	}
	cppVar_68297 = cppVar_67905 & cppVar_67906;
	cppVar_68299 = 1;
	cppVar_68300 = PC + 1;
	cppVar_68300 = (cppVar_68300 & cppMask_un_16_);
	cppVar_68301 = ROM.rd(cppVar_68300);
	cppVar_68302 = (cppVar_68301 >> 0) & cppMask_un_3_;
	cppVar_68303 = (cppVar_68302 & cppMask_un_3_);
	cppVar_68304 = cppVar_68299 << static_cast<unsigned>(cppVar_68303);
	cppVar_68304 = (cppVar_68304 & cppMask_un_8_);
	cppVar_68305 = cppVar_68297 | cppVar_68304;
	cppVar_67878 = cppVar_68305;
	} else {
	cppVar_67878 = TCON;
	}
	cppVar_67874 = cppVar_67878;
	} else {
	cppVar_68307 = ROM.rd(PC);
	cppVar_68309 = (cppVar_68307 == 208);
	if (cppVar_68309) {
	cppVar_68312 = PC + 1;
	cppVar_68312 = (cppVar_68312 & cppMask_un_16_);
	cppVar_68313 = ROM.rd(cppVar_68312);
	cppVar_68315 = (cppVar_68313 == 136);
	if (cppVar_68315) {
	cppVar_68316 = IRAM.rd(SP);
	cppVar_68310 = cppVar_68316;
	} else {
	cppVar_68310 = TCON;
	}
	cppVar_68306 = cppVar_68310;
	} else {
	cppVar_68318 = ROM.rd(PC);
	cppVar_68320 = (cppVar_68318 == 245);
	cppVar_68321 = ROM.rd(PC);
	cppVar_68323 = (cppVar_68321 == 197);
	cppVar_68324 = cppVar_68320 || cppVar_68323;
	if (cppVar_68324) {
	cppVar_68327 = PC + 1;
	cppVar_68327 = (cppVar_68327 & cppMask_un_16_);
	cppVar_68328 = ROM.rd(cppVar_68327);
	cppVar_68330 = (cppVar_68328 == 136);
	if (cppVar_68330) {
	cppVar_68325 = ACC;
	} else {
	cppVar_68325 = TCON;
	}
	cppVar_68317 = cppVar_68325;
	} else {
	cppVar_68332 = ROM.rd(PC);
	cppVar_68334 = (cppVar_68332 == 178);
	if (cppVar_68334) {
	cppVar_68338 = PC + 1;
	cppVar_68338 = (cppVar_68338 & cppMask_un_16_);
	cppVar_68339 = ROM.rd(cppVar_68338);
	cppVar_68340 = (cppVar_68339 >> 7) & cppMask_un_1_;
	cppVar_68342 = (cppVar_68340 == 1);
	if (cppVar_68342) {
	cppVar_68343 = PC + 1;
	cppVar_68343 = (cppVar_68343 & cppMask_un_16_);
	cppVar_68344 = ROM.rd(cppVar_68343);
	cppVar_68345 = (cppVar_68344 >> 3) & cppMask_un_5_;
	cppVar_68347 = (cppVar_68345 << 3) | 0;
	cppVar_68347 = (cppVar_68347 & cppMask_un_8_);
	cppVar_68336 = cppVar_68347;
	} else {
	cppVar_68348 = PC + 1;
	cppVar_68348 = (cppVar_68348 & cppMask_un_16_);
	cppVar_68349 = ROM.rd(cppVar_68348);
	cppVar_68350 = (cppVar_68349 >> 3) & cppMask_un_5_;
	cppVar_68351 = (cppVar_68350 & cppMask_un_5_);
	cppVar_68353 = cppVar_68351 + 32;
	cppVar_68353 = (cppVar_68353 & cppMask_un_8_);
	cppVar_68336 = cppVar_68353;
	}
	cppVar_68355 = (cppVar_68336 == 136);
	if (cppVar_68355) {
	cppVar_68357 = PC + 1;
	cppVar_68357 = (cppVar_68357 & cppMask_un_16_);
	cppVar_68358 = ROM.rd(cppVar_68357);
	cppVar_68359 = (cppVar_68358 >> 0) & cppMask_un_3_;
	cppVar_68360 = (cppVar_68359 & cppMask_un_3_);
	cppVar_68361 = 1 << static_cast<unsigned>(cppVar_68360);
	cppVar_68361 = (cppVar_68361 & cppMask_un_8_);
	cppVar_68362 = ~cppVar_68361;
	cppVar_68365 = PC + 1;
	cppVar_68365 = (cppVar_68365 & cppMask_un_16_);
	cppVar_68366 = ROM.rd(cppVar_68365);
	cppVar_68367 = (cppVar_68366 >> 7) & cppMask_un_1_;
	cppVar_68368 = (cppVar_68367 == 1);
	if (cppVar_68368) {
	cppVar_68369 = PC + 1;
	cppVar_68369 = (cppVar_68369 & cppMask_un_16_);
	cppVar_68370 = ROM.rd(cppVar_68369);
	cppVar_68371 = (cppVar_68370 >> 3) & cppMask_un_5_;
	cppVar_68372 = (cppVar_68371 << 3) | 0;
	cppVar_68372 = (cppVar_68372 & cppMask_un_8_);
	cppVar_68364 = cppVar_68372;
	} else {
	cppVar_68373 = PC + 1;
	cppVar_68373 = (cppVar_68373 & cppMask_un_16_);
	cppVar_68374 = ROM.rd(cppVar_68373);
	cppVar_68375 = (cppVar_68374 >> 3) & cppMask_un_5_;
	cppVar_68376 = (cppVar_68375 & cppMask_un_5_);
	cppVar_68377 = cppVar_68376 + 32;
	cppVar_68377 = (cppVar_68377 & cppMask_un_8_);
	cppVar_68364 = cppVar_68377;
	}
	cppVar_68378 = (cppVar_68364 >> 7) & cppMask_un_1_;
	cppVar_68380 = (cppVar_68378 == 0);
	if (cppVar_68380) {
	cppVar_68382 = PC + 1;
	cppVar_68382 = (cppVar_68382 & cppMask_un_16_);
	cppVar_68383 = ROM.rd(cppVar_68382);
	cppVar_68384 = (cppVar_68383 >> 7) & cppMask_un_1_;
	cppVar_68385 = (cppVar_68384 == 1);
	if (cppVar_68385) {
	cppVar_68386 = PC + 1;
	cppVar_68386 = (cppVar_68386 & cppMask_un_16_);
	cppVar_68387 = ROM.rd(cppVar_68386);
	cppVar_68388 = (cppVar_68387 >> 3) & cppMask_un_5_;
	cppVar_68389 = (cppVar_68388 << 3) | 0;
	cppVar_68389 = (cppVar_68389 & cppMask_un_8_);
	cppVar_68381 = cppVar_68389;
	} else {
	cppVar_68390 = PC + 1;
	cppVar_68390 = (cppVar_68390 & cppMask_un_16_);
	cppVar_68391 = ROM.rd(cppVar_68390);
	cppVar_68392 = (cppVar_68391 >> 3) & cppMask_un_5_;
	cppVar_68393 = (cppVar_68392 & cppMask_un_5_);
	cppVar_68394 = cppVar_68393 + 32;
	cppVar_68394 = (cppVar_68394 & cppMask_un_8_);
	cppVar_68381 = cppVar_68394;
	}
	cppVar_68395 = IRAM.rd(cppVar_68381);
	cppVar_68363 = cppVar_68395;
	} else {
	cppVar_68398 = PC + 1;
	cppVar_68398 = (cppVar_68398 & cppMask_un_16_);
	cppVar_68399 = ROM.rd(cppVar_68398);
	cppVar_68400 = (cppVar_68399 >> 7) & cppMask_un_1_;
	cppVar_68401 = (cppVar_68400 == 1);
	if (cppVar_68401) {
	cppVar_68402 = PC + 1;
	cppVar_68402 = (cppVar_68402 & cppMask_un_16_);
	cppVar_68403 = ROM.rd(cppVar_68402);
	cppVar_68404 = (cppVar_68403 >> 3) & cppMask_un_5_;
	cppVar_68405 = (cppVar_68404 << 3) | 0;
	cppVar_68405 = (cppVar_68405 & cppMask_un_8_);
	cppVar_68397 = cppVar_68405;
	} else {
	cppVar_68406 = PC + 1;
	cppVar_68406 = (cppVar_68406 & cppMask_un_16_);
	cppVar_68407 = ROM.rd(cppVar_68406);
	cppVar_68408 = (cppVar_68407 >> 3) & cppMask_un_5_;
	cppVar_68409 = (cppVar_68408 & cppMask_un_5_);
	cppVar_68410 = cppVar_68409 + 32;
	cppVar_68410 = (cppVar_68410 & cppMask_un_8_);
	cppVar_68397 = cppVar_68410;
	}
	cppVar_68412 = (cppVar_68397 == 128);
	if (cppVar_68412) {
	cppVar_68396 = P0;
	} else {
	cppVar_68415 = PC + 1;
	cppVar_68415 = (cppVar_68415 & cppMask_un_16_);
	cppVar_68416 = ROM.rd(cppVar_68415);
	cppVar_68417 = (cppVar_68416 >> 7) & cppMask_un_1_;
	cppVar_68418 = (cppVar_68417 == 1);
	if (cppVar_68418) {
	cppVar_68419 = PC + 1;
	cppVar_68419 = (cppVar_68419 & cppMask_un_16_);
	cppVar_68420 = ROM.rd(cppVar_68419);
	cppVar_68421 = (cppVar_68420 >> 3) & cppMask_un_5_;
	cppVar_68422 = (cppVar_68421 << 3) | 0;
	cppVar_68422 = (cppVar_68422 & cppMask_un_8_);
	cppVar_68414 = cppVar_68422;
	} else {
	cppVar_68423 = PC + 1;
	cppVar_68423 = (cppVar_68423 & cppMask_un_16_);
	cppVar_68424 = ROM.rd(cppVar_68423);
	cppVar_68425 = (cppVar_68424 >> 3) & cppMask_un_5_;
	cppVar_68426 = (cppVar_68425 & cppMask_un_5_);
	cppVar_68427 = cppVar_68426 + 32;
	cppVar_68427 = (cppVar_68427 & cppMask_un_8_);
	cppVar_68414 = cppVar_68427;
	}
	cppVar_68429 = (cppVar_68414 == 129);
	if (cppVar_68429) {
	cppVar_68413 = SP;
	} else {
	cppVar_68432 = PC + 1;
	cppVar_68432 = (cppVar_68432 & cppMask_un_16_);
	cppVar_68433 = ROM.rd(cppVar_68432);
	cppVar_68434 = (cppVar_68433 >> 7) & cppMask_un_1_;
	cppVar_68435 = (cppVar_68434 == 1);
	if (cppVar_68435) {
	cppVar_68436 = PC + 1;
	cppVar_68436 = (cppVar_68436 & cppMask_un_16_);
	cppVar_68437 = ROM.rd(cppVar_68436);
	cppVar_68438 = (cppVar_68437 >> 3) & cppMask_un_5_;
	cppVar_68439 = (cppVar_68438 << 3) | 0;
	cppVar_68439 = (cppVar_68439 & cppMask_un_8_);
	cppVar_68431 = cppVar_68439;
	} else {
	cppVar_68440 = PC + 1;
	cppVar_68440 = (cppVar_68440 & cppMask_un_16_);
	cppVar_68441 = ROM.rd(cppVar_68440);
	cppVar_68442 = (cppVar_68441 >> 3) & cppMask_un_5_;
	cppVar_68443 = (cppVar_68442 & cppMask_un_5_);
	cppVar_68444 = cppVar_68443 + 32;
	cppVar_68444 = (cppVar_68444 & cppMask_un_8_);
	cppVar_68431 = cppVar_68444;
	}
	cppVar_68446 = (cppVar_68431 == 130);
	if (cppVar_68446) {
	cppVar_68430 = DPL;
	} else {
	cppVar_68449 = PC + 1;
	cppVar_68449 = (cppVar_68449 & cppMask_un_16_);
	cppVar_68450 = ROM.rd(cppVar_68449);
	cppVar_68451 = (cppVar_68450 >> 7) & cppMask_un_1_;
	cppVar_68452 = (cppVar_68451 == 1);
	if (cppVar_68452) {
	cppVar_68453 = PC + 1;
	cppVar_68453 = (cppVar_68453 & cppMask_un_16_);
	cppVar_68454 = ROM.rd(cppVar_68453);
	cppVar_68455 = (cppVar_68454 >> 3) & cppMask_un_5_;
	cppVar_68456 = (cppVar_68455 << 3) | 0;
	cppVar_68456 = (cppVar_68456 & cppMask_un_8_);
	cppVar_68448 = cppVar_68456;
	} else {
	cppVar_68457 = PC + 1;
	cppVar_68457 = (cppVar_68457 & cppMask_un_16_);
	cppVar_68458 = ROM.rd(cppVar_68457);
	cppVar_68459 = (cppVar_68458 >> 3) & cppMask_un_5_;
	cppVar_68460 = (cppVar_68459 & cppMask_un_5_);
	cppVar_68461 = cppVar_68460 + 32;
	cppVar_68461 = (cppVar_68461 & cppMask_un_8_);
	cppVar_68448 = cppVar_68461;
	}
	cppVar_68463 = (cppVar_68448 == 131);
	if (cppVar_68463) {
	cppVar_68447 = DPH;
	} else {
	cppVar_68466 = PC + 1;
	cppVar_68466 = (cppVar_68466 & cppMask_un_16_);
	cppVar_68467 = ROM.rd(cppVar_68466);
	cppVar_68468 = (cppVar_68467 >> 7) & cppMask_un_1_;
	cppVar_68469 = (cppVar_68468 == 1);
	if (cppVar_68469) {
	cppVar_68470 = PC + 1;
	cppVar_68470 = (cppVar_68470 & cppMask_un_16_);
	cppVar_68471 = ROM.rd(cppVar_68470);
	cppVar_68472 = (cppVar_68471 >> 3) & cppMask_un_5_;
	cppVar_68473 = (cppVar_68472 << 3) | 0;
	cppVar_68473 = (cppVar_68473 & cppMask_un_8_);
	cppVar_68465 = cppVar_68473;
	} else {
	cppVar_68474 = PC + 1;
	cppVar_68474 = (cppVar_68474 & cppMask_un_16_);
	cppVar_68475 = ROM.rd(cppVar_68474);
	cppVar_68476 = (cppVar_68475 >> 3) & cppMask_un_5_;
	cppVar_68477 = (cppVar_68476 & cppMask_un_5_);
	cppVar_68478 = cppVar_68477 + 32;
	cppVar_68478 = (cppVar_68478 & cppMask_un_8_);
	cppVar_68465 = cppVar_68478;
	}
	cppVar_68480 = (cppVar_68465 == 135);
	if (cppVar_68480) {
	cppVar_68464 = PCON;
	} else {
	cppVar_68483 = PC + 1;
	cppVar_68483 = (cppVar_68483 & cppMask_un_16_);
	cppVar_68484 = ROM.rd(cppVar_68483);
	cppVar_68485 = (cppVar_68484 >> 7) & cppMask_un_1_;
	cppVar_68486 = (cppVar_68485 == 1);
	if (cppVar_68486) {
	cppVar_68487 = PC + 1;
	cppVar_68487 = (cppVar_68487 & cppMask_un_16_);
	cppVar_68488 = ROM.rd(cppVar_68487);
	cppVar_68489 = (cppVar_68488 >> 3) & cppMask_un_5_;
	cppVar_68490 = (cppVar_68489 << 3) | 0;
	cppVar_68490 = (cppVar_68490 & cppMask_un_8_);
	cppVar_68482 = cppVar_68490;
	} else {
	cppVar_68491 = PC + 1;
	cppVar_68491 = (cppVar_68491 & cppMask_un_16_);
	cppVar_68492 = ROM.rd(cppVar_68491);
	cppVar_68493 = (cppVar_68492 >> 3) & cppMask_un_5_;
	cppVar_68494 = (cppVar_68493 & cppMask_un_5_);
	cppVar_68495 = cppVar_68494 + 32;
	cppVar_68495 = (cppVar_68495 & cppMask_un_8_);
	cppVar_68482 = cppVar_68495;
	}
	cppVar_68497 = (cppVar_68482 == 136);
	if (cppVar_68497) {
	cppVar_68481 = TCON;
	} else {
	cppVar_68500 = PC + 1;
	cppVar_68500 = (cppVar_68500 & cppMask_un_16_);
	cppVar_68501 = ROM.rd(cppVar_68500);
	cppVar_68502 = (cppVar_68501 >> 7) & cppMask_un_1_;
	cppVar_68503 = (cppVar_68502 == 1);
	if (cppVar_68503) {
	cppVar_68504 = PC + 1;
	cppVar_68504 = (cppVar_68504 & cppMask_un_16_);
	cppVar_68505 = ROM.rd(cppVar_68504);
	cppVar_68506 = (cppVar_68505 >> 3) & cppMask_un_5_;
	cppVar_68507 = (cppVar_68506 << 3) | 0;
	cppVar_68507 = (cppVar_68507 & cppMask_un_8_);
	cppVar_68499 = cppVar_68507;
	} else {
	cppVar_68508 = PC + 1;
	cppVar_68508 = (cppVar_68508 & cppMask_un_16_);
	cppVar_68509 = ROM.rd(cppVar_68508);
	cppVar_68510 = (cppVar_68509 >> 3) & cppMask_un_5_;
	cppVar_68511 = (cppVar_68510 & cppMask_un_5_);
	cppVar_68512 = cppVar_68511 + 32;
	cppVar_68512 = (cppVar_68512 & cppMask_un_8_);
	cppVar_68499 = cppVar_68512;
	}
	cppVar_68514 = (cppVar_68499 == 137);
	if (cppVar_68514) {
	cppVar_68498 = TMOD;
	} else {
	cppVar_68517 = PC + 1;
	cppVar_68517 = (cppVar_68517 & cppMask_un_16_);
	cppVar_68518 = ROM.rd(cppVar_68517);
	cppVar_68519 = (cppVar_68518 >> 7) & cppMask_un_1_;
	cppVar_68520 = (cppVar_68519 == 1);
	if (cppVar_68520) {
	cppVar_68521 = PC + 1;
	cppVar_68521 = (cppVar_68521 & cppMask_un_16_);
	cppVar_68522 = ROM.rd(cppVar_68521);
	cppVar_68523 = (cppVar_68522 >> 3) & cppMask_un_5_;
	cppVar_68524 = (cppVar_68523 << 3) | 0;
	cppVar_68524 = (cppVar_68524 & cppMask_un_8_);
	cppVar_68516 = cppVar_68524;
	} else {
	cppVar_68525 = PC + 1;
	cppVar_68525 = (cppVar_68525 & cppMask_un_16_);
	cppVar_68526 = ROM.rd(cppVar_68525);
	cppVar_68527 = (cppVar_68526 >> 3) & cppMask_un_5_;
	cppVar_68528 = (cppVar_68527 & cppMask_un_5_);
	cppVar_68529 = cppVar_68528 + 32;
	cppVar_68529 = (cppVar_68529 & cppMask_un_8_);
	cppVar_68516 = cppVar_68529;
	}
	cppVar_68531 = (cppVar_68516 == 138);
	if (cppVar_68531) {
	cppVar_68515 = TL0;
	} else {
	cppVar_68534 = PC + 1;
	cppVar_68534 = (cppVar_68534 & cppMask_un_16_);
	cppVar_68535 = ROM.rd(cppVar_68534);
	cppVar_68536 = (cppVar_68535 >> 7) & cppMask_un_1_;
	cppVar_68537 = (cppVar_68536 == 1);
	if (cppVar_68537) {
	cppVar_68538 = PC + 1;
	cppVar_68538 = (cppVar_68538 & cppMask_un_16_);
	cppVar_68539 = ROM.rd(cppVar_68538);
	cppVar_68540 = (cppVar_68539 >> 3) & cppMask_un_5_;
	cppVar_68541 = (cppVar_68540 << 3) | 0;
	cppVar_68541 = (cppVar_68541 & cppMask_un_8_);
	cppVar_68533 = cppVar_68541;
	} else {
	cppVar_68542 = PC + 1;
	cppVar_68542 = (cppVar_68542 & cppMask_un_16_);
	cppVar_68543 = ROM.rd(cppVar_68542);
	cppVar_68544 = (cppVar_68543 >> 3) & cppMask_un_5_;
	cppVar_68545 = (cppVar_68544 & cppMask_un_5_);
	cppVar_68546 = cppVar_68545 + 32;
	cppVar_68546 = (cppVar_68546 & cppMask_un_8_);
	cppVar_68533 = cppVar_68546;
	}
	cppVar_68548 = (cppVar_68533 == 140);
	if (cppVar_68548) {
	cppVar_68532 = TH0;
	} else {
	cppVar_68551 = PC + 1;
	cppVar_68551 = (cppVar_68551 & cppMask_un_16_);
	cppVar_68552 = ROM.rd(cppVar_68551);
	cppVar_68553 = (cppVar_68552 >> 7) & cppMask_un_1_;
	cppVar_68554 = (cppVar_68553 == 1);
	if (cppVar_68554) {
	cppVar_68555 = PC + 1;
	cppVar_68555 = (cppVar_68555 & cppMask_un_16_);
	cppVar_68556 = ROM.rd(cppVar_68555);
	cppVar_68557 = (cppVar_68556 >> 3) & cppMask_un_5_;
	cppVar_68558 = (cppVar_68557 << 3) | 0;
	cppVar_68558 = (cppVar_68558 & cppMask_un_8_);
	cppVar_68550 = cppVar_68558;
	} else {
	cppVar_68559 = PC + 1;
	cppVar_68559 = (cppVar_68559 & cppMask_un_16_);
	cppVar_68560 = ROM.rd(cppVar_68559);
	cppVar_68561 = (cppVar_68560 >> 3) & cppMask_un_5_;
	cppVar_68562 = (cppVar_68561 & cppMask_un_5_);
	cppVar_68563 = cppVar_68562 + 32;
	cppVar_68563 = (cppVar_68563 & cppMask_un_8_);
	cppVar_68550 = cppVar_68563;
	}
	cppVar_68565 = (cppVar_68550 == 139);
	if (cppVar_68565) {
	cppVar_68549 = TL1;
	} else {
	cppVar_68568 = PC + 1;
	cppVar_68568 = (cppVar_68568 & cppMask_un_16_);
	cppVar_68569 = ROM.rd(cppVar_68568);
	cppVar_68570 = (cppVar_68569 >> 7) & cppMask_un_1_;
	cppVar_68571 = (cppVar_68570 == 1);
	if (cppVar_68571) {
	cppVar_68572 = PC + 1;
	cppVar_68572 = (cppVar_68572 & cppMask_un_16_);
	cppVar_68573 = ROM.rd(cppVar_68572);
	cppVar_68574 = (cppVar_68573 >> 3) & cppMask_un_5_;
	cppVar_68575 = (cppVar_68574 << 3) | 0;
	cppVar_68575 = (cppVar_68575 & cppMask_un_8_);
	cppVar_68567 = cppVar_68575;
	} else {
	cppVar_68576 = PC + 1;
	cppVar_68576 = (cppVar_68576 & cppMask_un_16_);
	cppVar_68577 = ROM.rd(cppVar_68576);
	cppVar_68578 = (cppVar_68577 >> 3) & cppMask_un_5_;
	cppVar_68579 = (cppVar_68578 & cppMask_un_5_);
	cppVar_68580 = cppVar_68579 + 32;
	cppVar_68580 = (cppVar_68580 & cppMask_un_8_);
	cppVar_68567 = cppVar_68580;
	}
	cppVar_68582 = (cppVar_68567 == 141);
	if (cppVar_68582) {
	cppVar_68566 = TH1;
	} else {
	cppVar_68585 = PC + 1;
	cppVar_68585 = (cppVar_68585 & cppMask_un_16_);
	cppVar_68586 = ROM.rd(cppVar_68585);
	cppVar_68587 = (cppVar_68586 >> 7) & cppMask_un_1_;
	cppVar_68588 = (cppVar_68587 == 1);
	if (cppVar_68588) {
	cppVar_68589 = PC + 1;
	cppVar_68589 = (cppVar_68589 & cppMask_un_16_);
	cppVar_68590 = ROM.rd(cppVar_68589);
	cppVar_68591 = (cppVar_68590 >> 3) & cppMask_un_5_;
	cppVar_68592 = (cppVar_68591 << 3) | 0;
	cppVar_68592 = (cppVar_68592 & cppMask_un_8_);
	cppVar_68584 = cppVar_68592;
	} else {
	cppVar_68593 = PC + 1;
	cppVar_68593 = (cppVar_68593 & cppMask_un_16_);
	cppVar_68594 = ROM.rd(cppVar_68593);
	cppVar_68595 = (cppVar_68594 >> 3) & cppMask_un_5_;
	cppVar_68596 = (cppVar_68595 & cppMask_un_5_);
	cppVar_68597 = cppVar_68596 + 32;
	cppVar_68597 = (cppVar_68597 & cppMask_un_8_);
	cppVar_68584 = cppVar_68597;
	}
	cppVar_68599 = (cppVar_68584 == 144);
	if (cppVar_68599) {
	cppVar_68583 = P1;
	} else {
	cppVar_68602 = PC + 1;
	cppVar_68602 = (cppVar_68602 & cppMask_un_16_);
	cppVar_68603 = ROM.rd(cppVar_68602);
	cppVar_68604 = (cppVar_68603 >> 7) & cppMask_un_1_;
	cppVar_68605 = (cppVar_68604 == 1);
	if (cppVar_68605) {
	cppVar_68606 = PC + 1;
	cppVar_68606 = (cppVar_68606 & cppMask_un_16_);
	cppVar_68607 = ROM.rd(cppVar_68606);
	cppVar_68608 = (cppVar_68607 >> 3) & cppMask_un_5_;
	cppVar_68609 = (cppVar_68608 << 3) | 0;
	cppVar_68609 = (cppVar_68609 & cppMask_un_8_);
	cppVar_68601 = cppVar_68609;
	} else {
	cppVar_68610 = PC + 1;
	cppVar_68610 = (cppVar_68610 & cppMask_un_16_);
	cppVar_68611 = ROM.rd(cppVar_68610);
	cppVar_68612 = (cppVar_68611 >> 3) & cppMask_un_5_;
	cppVar_68613 = (cppVar_68612 & cppMask_un_5_);
	cppVar_68614 = cppVar_68613 + 32;
	cppVar_68614 = (cppVar_68614 & cppMask_un_8_);
	cppVar_68601 = cppVar_68614;
	}
	cppVar_68616 = (cppVar_68601 == 152);
	if (cppVar_68616) {
	cppVar_68600 = SCON;
	} else {
	cppVar_68619 = PC + 1;
	cppVar_68619 = (cppVar_68619 & cppMask_un_16_);
	cppVar_68620 = ROM.rd(cppVar_68619);
	cppVar_68621 = (cppVar_68620 >> 7) & cppMask_un_1_;
	cppVar_68622 = (cppVar_68621 == 1);
	if (cppVar_68622) {
	cppVar_68623 = PC + 1;
	cppVar_68623 = (cppVar_68623 & cppMask_un_16_);
	cppVar_68624 = ROM.rd(cppVar_68623);
	cppVar_68625 = (cppVar_68624 >> 3) & cppMask_un_5_;
	cppVar_68626 = (cppVar_68625 << 3) | 0;
	cppVar_68626 = (cppVar_68626 & cppMask_un_8_);
	cppVar_68618 = cppVar_68626;
	} else {
	cppVar_68627 = PC + 1;
	cppVar_68627 = (cppVar_68627 & cppMask_un_16_);
	cppVar_68628 = ROM.rd(cppVar_68627);
	cppVar_68629 = (cppVar_68628 >> 3) & cppMask_un_5_;
	cppVar_68630 = (cppVar_68629 & cppMask_un_5_);
	cppVar_68631 = cppVar_68630 + 32;
	cppVar_68631 = (cppVar_68631 & cppMask_un_8_);
	cppVar_68618 = cppVar_68631;
	}
	cppVar_68633 = (cppVar_68618 == 153);
	if (cppVar_68633) {
	cppVar_68617 = SBUF;
	} else {
	cppVar_68636 = PC + 1;
	cppVar_68636 = (cppVar_68636 & cppMask_un_16_);
	cppVar_68637 = ROM.rd(cppVar_68636);
	cppVar_68638 = (cppVar_68637 >> 7) & cppMask_un_1_;
	cppVar_68639 = (cppVar_68638 == 1);
	if (cppVar_68639) {
	cppVar_68640 = PC + 1;
	cppVar_68640 = (cppVar_68640 & cppMask_un_16_);
	cppVar_68641 = ROM.rd(cppVar_68640);
	cppVar_68642 = (cppVar_68641 >> 3) & cppMask_un_5_;
	cppVar_68643 = (cppVar_68642 << 3) | 0;
	cppVar_68643 = (cppVar_68643 & cppMask_un_8_);
	cppVar_68635 = cppVar_68643;
	} else {
	cppVar_68644 = PC + 1;
	cppVar_68644 = (cppVar_68644 & cppMask_un_16_);
	cppVar_68645 = ROM.rd(cppVar_68644);
	cppVar_68646 = (cppVar_68645 >> 3) & cppMask_un_5_;
	cppVar_68647 = (cppVar_68646 & cppMask_un_5_);
	cppVar_68648 = cppVar_68647 + 32;
	cppVar_68648 = (cppVar_68648 & cppMask_un_8_);
	cppVar_68635 = cppVar_68648;
	}
	cppVar_68650 = (cppVar_68635 == 160);
	if (cppVar_68650) {
	cppVar_68634 = P2;
	} else {
	cppVar_68653 = PC + 1;
	cppVar_68653 = (cppVar_68653 & cppMask_un_16_);
	cppVar_68654 = ROM.rd(cppVar_68653);
	cppVar_68655 = (cppVar_68654 >> 7) & cppMask_un_1_;
	cppVar_68656 = (cppVar_68655 == 1);
	if (cppVar_68656) {
	cppVar_68657 = PC + 1;
	cppVar_68657 = (cppVar_68657 & cppMask_un_16_);
	cppVar_68658 = ROM.rd(cppVar_68657);
	cppVar_68659 = (cppVar_68658 >> 3) & cppMask_un_5_;
	cppVar_68660 = (cppVar_68659 << 3) | 0;
	cppVar_68660 = (cppVar_68660 & cppMask_un_8_);
	cppVar_68652 = cppVar_68660;
	} else {
	cppVar_68661 = PC + 1;
	cppVar_68661 = (cppVar_68661 & cppMask_un_16_);
	cppVar_68662 = ROM.rd(cppVar_68661);
	cppVar_68663 = (cppVar_68662 >> 3) & cppMask_un_5_;
	cppVar_68664 = (cppVar_68663 & cppMask_un_5_);
	cppVar_68665 = cppVar_68664 + 32;
	cppVar_68665 = (cppVar_68665 & cppMask_un_8_);
	cppVar_68652 = cppVar_68665;
	}
	cppVar_68667 = (cppVar_68652 == 168);
	if (cppVar_68667) {
	cppVar_68651 = IE;
	} else {
	cppVar_68670 = PC + 1;
	cppVar_68670 = (cppVar_68670 & cppMask_un_16_);
	cppVar_68671 = ROM.rd(cppVar_68670);
	cppVar_68672 = (cppVar_68671 >> 7) & cppMask_un_1_;
	cppVar_68673 = (cppVar_68672 == 1);
	if (cppVar_68673) {
	cppVar_68674 = PC + 1;
	cppVar_68674 = (cppVar_68674 & cppMask_un_16_);
	cppVar_68675 = ROM.rd(cppVar_68674);
	cppVar_68676 = (cppVar_68675 >> 3) & cppMask_un_5_;
	cppVar_68677 = (cppVar_68676 << 3) | 0;
	cppVar_68677 = (cppVar_68677 & cppMask_un_8_);
	cppVar_68669 = cppVar_68677;
	} else {
	cppVar_68678 = PC + 1;
	cppVar_68678 = (cppVar_68678 & cppMask_un_16_);
	cppVar_68679 = ROM.rd(cppVar_68678);
	cppVar_68680 = (cppVar_68679 >> 3) & cppMask_un_5_;
	cppVar_68681 = (cppVar_68680 & cppMask_un_5_);
	cppVar_68682 = cppVar_68681 + 32;
	cppVar_68682 = (cppVar_68682 & cppMask_un_8_);
	cppVar_68669 = cppVar_68682;
	}
	cppVar_68684 = (cppVar_68669 == 176);
	if (cppVar_68684) {
	cppVar_68668 = P3;
	} else {
	cppVar_68687 = PC + 1;
	cppVar_68687 = (cppVar_68687 & cppMask_un_16_);
	cppVar_68688 = ROM.rd(cppVar_68687);
	cppVar_68689 = (cppVar_68688 >> 7) & cppMask_un_1_;
	cppVar_68690 = (cppVar_68689 == 1);
	if (cppVar_68690) {
	cppVar_68691 = PC + 1;
	cppVar_68691 = (cppVar_68691 & cppMask_un_16_);
	cppVar_68692 = ROM.rd(cppVar_68691);
	cppVar_68693 = (cppVar_68692 >> 3) & cppMask_un_5_;
	cppVar_68694 = (cppVar_68693 << 3) | 0;
	cppVar_68694 = (cppVar_68694 & cppMask_un_8_);
	cppVar_68686 = cppVar_68694;
	} else {
	cppVar_68695 = PC + 1;
	cppVar_68695 = (cppVar_68695 & cppMask_un_16_);
	cppVar_68696 = ROM.rd(cppVar_68695);
	cppVar_68697 = (cppVar_68696 >> 3) & cppMask_un_5_;
	cppVar_68698 = (cppVar_68697 & cppMask_un_5_);
	cppVar_68699 = cppVar_68698 + 32;
	cppVar_68699 = (cppVar_68699 & cppMask_un_8_);
	cppVar_68686 = cppVar_68699;
	}
	cppVar_68701 = (cppVar_68686 == 184);
	if (cppVar_68701) {
	cppVar_68685 = IP;
	} else {
	cppVar_68704 = PC + 1;
	cppVar_68704 = (cppVar_68704 & cppMask_un_16_);
	cppVar_68705 = ROM.rd(cppVar_68704);
	cppVar_68706 = (cppVar_68705 >> 7) & cppMask_un_1_;
	cppVar_68707 = (cppVar_68706 == 1);
	if (cppVar_68707) {
	cppVar_68708 = PC + 1;
	cppVar_68708 = (cppVar_68708 & cppMask_un_16_);
	cppVar_68709 = ROM.rd(cppVar_68708);
	cppVar_68710 = (cppVar_68709 >> 3) & cppMask_un_5_;
	cppVar_68711 = (cppVar_68710 << 3) | 0;
	cppVar_68711 = (cppVar_68711 & cppMask_un_8_);
	cppVar_68703 = cppVar_68711;
	} else {
	cppVar_68712 = PC + 1;
	cppVar_68712 = (cppVar_68712 & cppMask_un_16_);
	cppVar_68713 = ROM.rd(cppVar_68712);
	cppVar_68714 = (cppVar_68713 >> 3) & cppMask_un_5_;
	cppVar_68715 = (cppVar_68714 & cppMask_un_5_);
	cppVar_68716 = cppVar_68715 + 32;
	cppVar_68716 = (cppVar_68716 & cppMask_un_8_);
	cppVar_68703 = cppVar_68716;
	}
	cppVar_68718 = (cppVar_68703 == 208);
	if (cppVar_68718) {
	cppVar_68702 = PSW;
	} else {
	cppVar_68721 = PC + 1;
	cppVar_68721 = (cppVar_68721 & cppMask_un_16_);
	cppVar_68722 = ROM.rd(cppVar_68721);
	cppVar_68723 = (cppVar_68722 >> 7) & cppMask_un_1_;
	cppVar_68724 = (cppVar_68723 == 1);
	if (cppVar_68724) {
	cppVar_68725 = PC + 1;
	cppVar_68725 = (cppVar_68725 & cppMask_un_16_);
	cppVar_68726 = ROM.rd(cppVar_68725);
	cppVar_68727 = (cppVar_68726 >> 3) & cppMask_un_5_;
	cppVar_68728 = (cppVar_68727 << 3) | 0;
	cppVar_68728 = (cppVar_68728 & cppMask_un_8_);
	cppVar_68720 = cppVar_68728;
	} else {
	cppVar_68729 = PC + 1;
	cppVar_68729 = (cppVar_68729 & cppMask_un_16_);
	cppVar_68730 = ROM.rd(cppVar_68729);
	cppVar_68731 = (cppVar_68730 >> 3) & cppMask_un_5_;
	cppVar_68732 = (cppVar_68731 & cppMask_un_5_);
	cppVar_68733 = cppVar_68732 + 32;
	cppVar_68733 = (cppVar_68733 & cppMask_un_8_);
	cppVar_68720 = cppVar_68733;
	}
	cppVar_68735 = (cppVar_68720 == 224);
	if (cppVar_68735) {
	cppVar_68719 = ACC;
	} else {
	cppVar_68738 = PC + 1;
	cppVar_68738 = (cppVar_68738 & cppMask_un_16_);
	cppVar_68739 = ROM.rd(cppVar_68738);
	cppVar_68740 = (cppVar_68739 >> 7) & cppMask_un_1_;
	cppVar_68741 = (cppVar_68740 == 1);
	if (cppVar_68741) {
	cppVar_68742 = PC + 1;
	cppVar_68742 = (cppVar_68742 & cppMask_un_16_);
	cppVar_68743 = ROM.rd(cppVar_68742);
	cppVar_68744 = (cppVar_68743 >> 3) & cppMask_un_5_;
	cppVar_68745 = (cppVar_68744 << 3) | 0;
	cppVar_68745 = (cppVar_68745 & cppMask_un_8_);
	cppVar_68737 = cppVar_68745;
	} else {
	cppVar_68746 = PC + 1;
	cppVar_68746 = (cppVar_68746 & cppMask_un_16_);
	cppVar_68747 = ROM.rd(cppVar_68746);
	cppVar_68748 = (cppVar_68747 >> 3) & cppMask_un_5_;
	cppVar_68749 = (cppVar_68748 & cppMask_un_5_);
	cppVar_68750 = cppVar_68749 + 32;
	cppVar_68750 = (cppVar_68750 & cppMask_un_8_);
	cppVar_68737 = cppVar_68750;
	}
	cppVar_68752 = (cppVar_68737 == 240);
	if (cppVar_68752) {
	cppVar_68736 = B;
	} else {
	cppVar_68736 = 0;
	}
	cppVar_68719 = cppVar_68736;
	}
	cppVar_68702 = cppVar_68719;
	}
	cppVar_68685 = cppVar_68702;
	}
	cppVar_68668 = cppVar_68685;
	}
	cppVar_68651 = cppVar_68668;
	}
	cppVar_68634 = cppVar_68651;
	}
	cppVar_68617 = cppVar_68634;
	}
	cppVar_68600 = cppVar_68617;
	}
	cppVar_68583 = cppVar_68600;
	}
	cppVar_68566 = cppVar_68583;
	}
	cppVar_68549 = cppVar_68566;
	}
	cppVar_68532 = cppVar_68549;
	}
	cppVar_68515 = cppVar_68532;
	}
	cppVar_68498 = cppVar_68515;
	}
	cppVar_68481 = cppVar_68498;
	}
	cppVar_68464 = cppVar_68481;
	}
	cppVar_68447 = cppVar_68464;
	}
	cppVar_68430 = cppVar_68447;
	}
	cppVar_68413 = cppVar_68430;
	}
	cppVar_68396 = cppVar_68413;
	}
	cppVar_68363 = cppVar_68396;
	}
	cppVar_68754 = cppVar_68362 & cppVar_68363;
	cppVar_68757 = PC + 1;
	cppVar_68757 = (cppVar_68757 & cppMask_un_16_);
	cppVar_68758 = ROM.rd(cppVar_68757);
	cppVar_68759 = (cppVar_68758 >> 7) & cppMask_un_1_;
	cppVar_68761 = (cppVar_68759 == 1);
	if (cppVar_68761) {
	cppVar_68762 = PC + 1;
	cppVar_68762 = (cppVar_68762 & cppMask_un_16_);
	cppVar_68763 = ROM.rd(cppVar_68762);
	cppVar_68764 = (cppVar_68763 >> 3) & cppMask_un_5_;
	cppVar_68766 = (cppVar_68764 << 3) | 0;
	cppVar_68766 = (cppVar_68766 & cppMask_un_8_);
	cppVar_68756 = cppVar_68766;
	} else {
	cppVar_68767 = PC + 1;
	cppVar_68767 = (cppVar_68767 & cppMask_un_16_);
	cppVar_68768 = ROM.rd(cppVar_68767);
	cppVar_68769 = (cppVar_68768 >> 3) & cppMask_un_5_;
	cppVar_68770 = (cppVar_68769 & cppMask_un_5_);
	cppVar_68772 = cppVar_68770 + 32;
	cppVar_68772 = (cppVar_68772 & cppMask_un_8_);
	cppVar_68756 = cppVar_68772;
	}
	cppVar_68773 = (cppVar_68756 >> 7) & cppMask_un_1_;
	cppVar_68775 = (cppVar_68773 == 0);
	if (cppVar_68775) {
	cppVar_68777 = PC + 1;
	cppVar_68777 = (cppVar_68777 & cppMask_un_16_);
	cppVar_68778 = ROM.rd(cppVar_68777);
	cppVar_68779 = (cppVar_68778 >> 7) & cppMask_un_1_;
	cppVar_68780 = (cppVar_68779 == 1);
	if (cppVar_68780) {
	cppVar_68781 = PC + 1;
	cppVar_68781 = (cppVar_68781 & cppMask_un_16_);
	cppVar_68782 = ROM.rd(cppVar_68781);
	cppVar_68783 = (cppVar_68782 >> 3) & cppMask_un_5_;
	cppVar_68784 = (cppVar_68783 << 3) | 0;
	cppVar_68784 = (cppVar_68784 & cppMask_un_8_);
	cppVar_68776 = cppVar_68784;
	} else {
	cppVar_68785 = PC + 1;
	cppVar_68785 = (cppVar_68785 & cppMask_un_16_);
	cppVar_68786 = ROM.rd(cppVar_68785);
	cppVar_68787 = (cppVar_68786 >> 3) & cppMask_un_5_;
	cppVar_68788 = (cppVar_68787 & cppMask_un_5_);
	cppVar_68789 = cppVar_68788 + 32;
	cppVar_68789 = (cppVar_68789 & cppMask_un_8_);
	cppVar_68776 = cppVar_68789;
	}
	cppVar_68790 = IRAM.rd(cppVar_68776);
	cppVar_68755 = cppVar_68790;
	} else {
	cppVar_68793 = PC + 1;
	cppVar_68793 = (cppVar_68793 & cppMask_un_16_);
	cppVar_68794 = ROM.rd(cppVar_68793);
	cppVar_68795 = (cppVar_68794 >> 7) & cppMask_un_1_;
	cppVar_68796 = (cppVar_68795 == 1);
	if (cppVar_68796) {
	cppVar_68797 = PC + 1;
	cppVar_68797 = (cppVar_68797 & cppMask_un_16_);
	cppVar_68798 = ROM.rd(cppVar_68797);
	cppVar_68799 = (cppVar_68798 >> 3) & cppMask_un_5_;
	cppVar_68800 = (cppVar_68799 << 3) | 0;
	cppVar_68800 = (cppVar_68800 & cppMask_un_8_);
	cppVar_68792 = cppVar_68800;
	} else {
	cppVar_68801 = PC + 1;
	cppVar_68801 = (cppVar_68801 & cppMask_un_16_);
	cppVar_68802 = ROM.rd(cppVar_68801);
	cppVar_68803 = (cppVar_68802 >> 3) & cppMask_un_5_;
	cppVar_68804 = (cppVar_68803 & cppMask_un_5_);
	cppVar_68805 = cppVar_68804 + 32;
	cppVar_68805 = (cppVar_68805 & cppMask_un_8_);
	cppVar_68792 = cppVar_68805;
	}
	cppVar_68807 = (cppVar_68792 == 128);
	if (cppVar_68807) {
	cppVar_68791 = P0;
	} else {
	cppVar_68810 = PC + 1;
	cppVar_68810 = (cppVar_68810 & cppMask_un_16_);
	cppVar_68811 = ROM.rd(cppVar_68810);
	cppVar_68812 = (cppVar_68811 >> 7) & cppMask_un_1_;
	cppVar_68813 = (cppVar_68812 == 1);
	if (cppVar_68813) {
	cppVar_68814 = PC + 1;
	cppVar_68814 = (cppVar_68814 & cppMask_un_16_);
	cppVar_68815 = ROM.rd(cppVar_68814);
	cppVar_68816 = (cppVar_68815 >> 3) & cppMask_un_5_;
	cppVar_68817 = (cppVar_68816 << 3) | 0;
	cppVar_68817 = (cppVar_68817 & cppMask_un_8_);
	cppVar_68809 = cppVar_68817;
	} else {
	cppVar_68818 = PC + 1;
	cppVar_68818 = (cppVar_68818 & cppMask_un_16_);
	cppVar_68819 = ROM.rd(cppVar_68818);
	cppVar_68820 = (cppVar_68819 >> 3) & cppMask_un_5_;
	cppVar_68821 = (cppVar_68820 & cppMask_un_5_);
	cppVar_68822 = cppVar_68821 + 32;
	cppVar_68822 = (cppVar_68822 & cppMask_un_8_);
	cppVar_68809 = cppVar_68822;
	}
	cppVar_68824 = (cppVar_68809 == 129);
	if (cppVar_68824) {
	cppVar_68808 = SP;
	} else {
	cppVar_68827 = PC + 1;
	cppVar_68827 = (cppVar_68827 & cppMask_un_16_);
	cppVar_68828 = ROM.rd(cppVar_68827);
	cppVar_68829 = (cppVar_68828 >> 7) & cppMask_un_1_;
	cppVar_68830 = (cppVar_68829 == 1);
	if (cppVar_68830) {
	cppVar_68831 = PC + 1;
	cppVar_68831 = (cppVar_68831 & cppMask_un_16_);
	cppVar_68832 = ROM.rd(cppVar_68831);
	cppVar_68833 = (cppVar_68832 >> 3) & cppMask_un_5_;
	cppVar_68834 = (cppVar_68833 << 3) | 0;
	cppVar_68834 = (cppVar_68834 & cppMask_un_8_);
	cppVar_68826 = cppVar_68834;
	} else {
	cppVar_68835 = PC + 1;
	cppVar_68835 = (cppVar_68835 & cppMask_un_16_);
	cppVar_68836 = ROM.rd(cppVar_68835);
	cppVar_68837 = (cppVar_68836 >> 3) & cppMask_un_5_;
	cppVar_68838 = (cppVar_68837 & cppMask_un_5_);
	cppVar_68839 = cppVar_68838 + 32;
	cppVar_68839 = (cppVar_68839 & cppMask_un_8_);
	cppVar_68826 = cppVar_68839;
	}
	cppVar_68841 = (cppVar_68826 == 130);
	if (cppVar_68841) {
	cppVar_68825 = DPL;
	} else {
	cppVar_68844 = PC + 1;
	cppVar_68844 = (cppVar_68844 & cppMask_un_16_);
	cppVar_68845 = ROM.rd(cppVar_68844);
	cppVar_68846 = (cppVar_68845 >> 7) & cppMask_un_1_;
	cppVar_68847 = (cppVar_68846 == 1);
	if (cppVar_68847) {
	cppVar_68848 = PC + 1;
	cppVar_68848 = (cppVar_68848 & cppMask_un_16_);
	cppVar_68849 = ROM.rd(cppVar_68848);
	cppVar_68850 = (cppVar_68849 >> 3) & cppMask_un_5_;
	cppVar_68851 = (cppVar_68850 << 3) | 0;
	cppVar_68851 = (cppVar_68851 & cppMask_un_8_);
	cppVar_68843 = cppVar_68851;
	} else {
	cppVar_68852 = PC + 1;
	cppVar_68852 = (cppVar_68852 & cppMask_un_16_);
	cppVar_68853 = ROM.rd(cppVar_68852);
	cppVar_68854 = (cppVar_68853 >> 3) & cppMask_un_5_;
	cppVar_68855 = (cppVar_68854 & cppMask_un_5_);
	cppVar_68856 = cppVar_68855 + 32;
	cppVar_68856 = (cppVar_68856 & cppMask_un_8_);
	cppVar_68843 = cppVar_68856;
	}
	cppVar_68858 = (cppVar_68843 == 131);
	if (cppVar_68858) {
	cppVar_68842 = DPH;
	} else {
	cppVar_68861 = PC + 1;
	cppVar_68861 = (cppVar_68861 & cppMask_un_16_);
	cppVar_68862 = ROM.rd(cppVar_68861);
	cppVar_68863 = (cppVar_68862 >> 7) & cppMask_un_1_;
	cppVar_68864 = (cppVar_68863 == 1);
	if (cppVar_68864) {
	cppVar_68865 = PC + 1;
	cppVar_68865 = (cppVar_68865 & cppMask_un_16_);
	cppVar_68866 = ROM.rd(cppVar_68865);
	cppVar_68867 = (cppVar_68866 >> 3) & cppMask_un_5_;
	cppVar_68868 = (cppVar_68867 << 3) | 0;
	cppVar_68868 = (cppVar_68868 & cppMask_un_8_);
	cppVar_68860 = cppVar_68868;
	} else {
	cppVar_68869 = PC + 1;
	cppVar_68869 = (cppVar_68869 & cppMask_un_16_);
	cppVar_68870 = ROM.rd(cppVar_68869);
	cppVar_68871 = (cppVar_68870 >> 3) & cppMask_un_5_;
	cppVar_68872 = (cppVar_68871 & cppMask_un_5_);
	cppVar_68873 = cppVar_68872 + 32;
	cppVar_68873 = (cppVar_68873 & cppMask_un_8_);
	cppVar_68860 = cppVar_68873;
	}
	cppVar_68875 = (cppVar_68860 == 135);
	if (cppVar_68875) {
	cppVar_68859 = PCON;
	} else {
	cppVar_68878 = PC + 1;
	cppVar_68878 = (cppVar_68878 & cppMask_un_16_);
	cppVar_68879 = ROM.rd(cppVar_68878);
	cppVar_68880 = (cppVar_68879 >> 7) & cppMask_un_1_;
	cppVar_68881 = (cppVar_68880 == 1);
	if (cppVar_68881) {
	cppVar_68882 = PC + 1;
	cppVar_68882 = (cppVar_68882 & cppMask_un_16_);
	cppVar_68883 = ROM.rd(cppVar_68882);
	cppVar_68884 = (cppVar_68883 >> 3) & cppMask_un_5_;
	cppVar_68885 = (cppVar_68884 << 3) | 0;
	cppVar_68885 = (cppVar_68885 & cppMask_un_8_);
	cppVar_68877 = cppVar_68885;
	} else {
	cppVar_68886 = PC + 1;
	cppVar_68886 = (cppVar_68886 & cppMask_un_16_);
	cppVar_68887 = ROM.rd(cppVar_68886);
	cppVar_68888 = (cppVar_68887 >> 3) & cppMask_un_5_;
	cppVar_68889 = (cppVar_68888 & cppMask_un_5_);
	cppVar_68890 = cppVar_68889 + 32;
	cppVar_68890 = (cppVar_68890 & cppMask_un_8_);
	cppVar_68877 = cppVar_68890;
	}
	cppVar_68892 = (cppVar_68877 == 136);
	if (cppVar_68892) {
	cppVar_68876 = TCON;
	} else {
	cppVar_68895 = PC + 1;
	cppVar_68895 = (cppVar_68895 & cppMask_un_16_);
	cppVar_68896 = ROM.rd(cppVar_68895);
	cppVar_68897 = (cppVar_68896 >> 7) & cppMask_un_1_;
	cppVar_68898 = (cppVar_68897 == 1);
	if (cppVar_68898) {
	cppVar_68899 = PC + 1;
	cppVar_68899 = (cppVar_68899 & cppMask_un_16_);
	cppVar_68900 = ROM.rd(cppVar_68899);
	cppVar_68901 = (cppVar_68900 >> 3) & cppMask_un_5_;
	cppVar_68902 = (cppVar_68901 << 3) | 0;
	cppVar_68902 = (cppVar_68902 & cppMask_un_8_);
	cppVar_68894 = cppVar_68902;
	} else {
	cppVar_68903 = PC + 1;
	cppVar_68903 = (cppVar_68903 & cppMask_un_16_);
	cppVar_68904 = ROM.rd(cppVar_68903);
	cppVar_68905 = (cppVar_68904 >> 3) & cppMask_un_5_;
	cppVar_68906 = (cppVar_68905 & cppMask_un_5_);
	cppVar_68907 = cppVar_68906 + 32;
	cppVar_68907 = (cppVar_68907 & cppMask_un_8_);
	cppVar_68894 = cppVar_68907;
	}
	cppVar_68909 = (cppVar_68894 == 137);
	if (cppVar_68909) {
	cppVar_68893 = TMOD;
	} else {
	cppVar_68912 = PC + 1;
	cppVar_68912 = (cppVar_68912 & cppMask_un_16_);
	cppVar_68913 = ROM.rd(cppVar_68912);
	cppVar_68914 = (cppVar_68913 >> 7) & cppMask_un_1_;
	cppVar_68915 = (cppVar_68914 == 1);
	if (cppVar_68915) {
	cppVar_68916 = PC + 1;
	cppVar_68916 = (cppVar_68916 & cppMask_un_16_);
	cppVar_68917 = ROM.rd(cppVar_68916);
	cppVar_68918 = (cppVar_68917 >> 3) & cppMask_un_5_;
	cppVar_68919 = (cppVar_68918 << 3) | 0;
	cppVar_68919 = (cppVar_68919 & cppMask_un_8_);
	cppVar_68911 = cppVar_68919;
	} else {
	cppVar_68920 = PC + 1;
	cppVar_68920 = (cppVar_68920 & cppMask_un_16_);
	cppVar_68921 = ROM.rd(cppVar_68920);
	cppVar_68922 = (cppVar_68921 >> 3) & cppMask_un_5_;
	cppVar_68923 = (cppVar_68922 & cppMask_un_5_);
	cppVar_68924 = cppVar_68923 + 32;
	cppVar_68924 = (cppVar_68924 & cppMask_un_8_);
	cppVar_68911 = cppVar_68924;
	}
	cppVar_68926 = (cppVar_68911 == 138);
	if (cppVar_68926) {
	cppVar_68910 = TL0;
	} else {
	cppVar_68929 = PC + 1;
	cppVar_68929 = (cppVar_68929 & cppMask_un_16_);
	cppVar_68930 = ROM.rd(cppVar_68929);
	cppVar_68931 = (cppVar_68930 >> 7) & cppMask_un_1_;
	cppVar_68932 = (cppVar_68931 == 1);
	if (cppVar_68932) {
	cppVar_68933 = PC + 1;
	cppVar_68933 = (cppVar_68933 & cppMask_un_16_);
	cppVar_68934 = ROM.rd(cppVar_68933);
	cppVar_68935 = (cppVar_68934 >> 3) & cppMask_un_5_;
	cppVar_68936 = (cppVar_68935 << 3) | 0;
	cppVar_68936 = (cppVar_68936 & cppMask_un_8_);
	cppVar_68928 = cppVar_68936;
	} else {
	cppVar_68937 = PC + 1;
	cppVar_68937 = (cppVar_68937 & cppMask_un_16_);
	cppVar_68938 = ROM.rd(cppVar_68937);
	cppVar_68939 = (cppVar_68938 >> 3) & cppMask_un_5_;
	cppVar_68940 = (cppVar_68939 & cppMask_un_5_);
	cppVar_68941 = cppVar_68940 + 32;
	cppVar_68941 = (cppVar_68941 & cppMask_un_8_);
	cppVar_68928 = cppVar_68941;
	}
	cppVar_68943 = (cppVar_68928 == 140);
	if (cppVar_68943) {
	cppVar_68927 = TH0;
	} else {
	cppVar_68946 = PC + 1;
	cppVar_68946 = (cppVar_68946 & cppMask_un_16_);
	cppVar_68947 = ROM.rd(cppVar_68946);
	cppVar_68948 = (cppVar_68947 >> 7) & cppMask_un_1_;
	cppVar_68949 = (cppVar_68948 == 1);
	if (cppVar_68949) {
	cppVar_68950 = PC + 1;
	cppVar_68950 = (cppVar_68950 & cppMask_un_16_);
	cppVar_68951 = ROM.rd(cppVar_68950);
	cppVar_68952 = (cppVar_68951 >> 3) & cppMask_un_5_;
	cppVar_68953 = (cppVar_68952 << 3) | 0;
	cppVar_68953 = (cppVar_68953 & cppMask_un_8_);
	cppVar_68945 = cppVar_68953;
	} else {
	cppVar_68954 = PC + 1;
	cppVar_68954 = (cppVar_68954 & cppMask_un_16_);
	cppVar_68955 = ROM.rd(cppVar_68954);
	cppVar_68956 = (cppVar_68955 >> 3) & cppMask_un_5_;
	cppVar_68957 = (cppVar_68956 & cppMask_un_5_);
	cppVar_68958 = cppVar_68957 + 32;
	cppVar_68958 = (cppVar_68958 & cppMask_un_8_);
	cppVar_68945 = cppVar_68958;
	}
	cppVar_68960 = (cppVar_68945 == 139);
	if (cppVar_68960) {
	cppVar_68944 = TL1;
	} else {
	cppVar_68963 = PC + 1;
	cppVar_68963 = (cppVar_68963 & cppMask_un_16_);
	cppVar_68964 = ROM.rd(cppVar_68963);
	cppVar_68965 = (cppVar_68964 >> 7) & cppMask_un_1_;
	cppVar_68966 = (cppVar_68965 == 1);
	if (cppVar_68966) {
	cppVar_68967 = PC + 1;
	cppVar_68967 = (cppVar_68967 & cppMask_un_16_);
	cppVar_68968 = ROM.rd(cppVar_68967);
	cppVar_68969 = (cppVar_68968 >> 3) & cppMask_un_5_;
	cppVar_68970 = (cppVar_68969 << 3) | 0;
	cppVar_68970 = (cppVar_68970 & cppMask_un_8_);
	cppVar_68962 = cppVar_68970;
	} else {
	cppVar_68971 = PC + 1;
	cppVar_68971 = (cppVar_68971 & cppMask_un_16_);
	cppVar_68972 = ROM.rd(cppVar_68971);
	cppVar_68973 = (cppVar_68972 >> 3) & cppMask_un_5_;
	cppVar_68974 = (cppVar_68973 & cppMask_un_5_);
	cppVar_68975 = cppVar_68974 + 32;
	cppVar_68975 = (cppVar_68975 & cppMask_un_8_);
	cppVar_68962 = cppVar_68975;
	}
	cppVar_68977 = (cppVar_68962 == 141);
	if (cppVar_68977) {
	cppVar_68961 = TH1;
	} else {
	cppVar_68980 = PC + 1;
	cppVar_68980 = (cppVar_68980 & cppMask_un_16_);
	cppVar_68981 = ROM.rd(cppVar_68980);
	cppVar_68982 = (cppVar_68981 >> 7) & cppMask_un_1_;
	cppVar_68983 = (cppVar_68982 == 1);
	if (cppVar_68983) {
	cppVar_68984 = PC + 1;
	cppVar_68984 = (cppVar_68984 & cppMask_un_16_);
	cppVar_68985 = ROM.rd(cppVar_68984);
	cppVar_68986 = (cppVar_68985 >> 3) & cppMask_un_5_;
	cppVar_68987 = (cppVar_68986 << 3) | 0;
	cppVar_68987 = (cppVar_68987 & cppMask_un_8_);
	cppVar_68979 = cppVar_68987;
	} else {
	cppVar_68988 = PC + 1;
	cppVar_68988 = (cppVar_68988 & cppMask_un_16_);
	cppVar_68989 = ROM.rd(cppVar_68988);
	cppVar_68990 = (cppVar_68989 >> 3) & cppMask_un_5_;
	cppVar_68991 = (cppVar_68990 & cppMask_un_5_);
	cppVar_68992 = cppVar_68991 + 32;
	cppVar_68992 = (cppVar_68992 & cppMask_un_8_);
	cppVar_68979 = cppVar_68992;
	}
	cppVar_68994 = (cppVar_68979 == 144);
	if (cppVar_68994) {
	cppVar_68978 = P1;
	} else {
	cppVar_68997 = PC + 1;
	cppVar_68997 = (cppVar_68997 & cppMask_un_16_);
	cppVar_68998 = ROM.rd(cppVar_68997);
	cppVar_68999 = (cppVar_68998 >> 7) & cppMask_un_1_;
	cppVar_69000 = (cppVar_68999 == 1);
	if (cppVar_69000) {
	cppVar_69001 = PC + 1;
	cppVar_69001 = (cppVar_69001 & cppMask_un_16_);
	cppVar_69002 = ROM.rd(cppVar_69001);
	cppVar_69003 = (cppVar_69002 >> 3) & cppMask_un_5_;
	cppVar_69004 = (cppVar_69003 << 3) | 0;
	cppVar_69004 = (cppVar_69004 & cppMask_un_8_);
	cppVar_68996 = cppVar_69004;
	} else {
	cppVar_69005 = PC + 1;
	cppVar_69005 = (cppVar_69005 & cppMask_un_16_);
	cppVar_69006 = ROM.rd(cppVar_69005);
	cppVar_69007 = (cppVar_69006 >> 3) & cppMask_un_5_;
	cppVar_69008 = (cppVar_69007 & cppMask_un_5_);
	cppVar_69009 = cppVar_69008 + 32;
	cppVar_69009 = (cppVar_69009 & cppMask_un_8_);
	cppVar_68996 = cppVar_69009;
	}
	cppVar_69011 = (cppVar_68996 == 152);
	if (cppVar_69011) {
	cppVar_68995 = SCON;
	} else {
	cppVar_69014 = PC + 1;
	cppVar_69014 = (cppVar_69014 & cppMask_un_16_);
	cppVar_69015 = ROM.rd(cppVar_69014);
	cppVar_69016 = (cppVar_69015 >> 7) & cppMask_un_1_;
	cppVar_69017 = (cppVar_69016 == 1);
	if (cppVar_69017) {
	cppVar_69018 = PC + 1;
	cppVar_69018 = (cppVar_69018 & cppMask_un_16_);
	cppVar_69019 = ROM.rd(cppVar_69018);
	cppVar_69020 = (cppVar_69019 >> 3) & cppMask_un_5_;
	cppVar_69021 = (cppVar_69020 << 3) | 0;
	cppVar_69021 = (cppVar_69021 & cppMask_un_8_);
	cppVar_69013 = cppVar_69021;
	} else {
	cppVar_69022 = PC + 1;
	cppVar_69022 = (cppVar_69022 & cppMask_un_16_);
	cppVar_69023 = ROM.rd(cppVar_69022);
	cppVar_69024 = (cppVar_69023 >> 3) & cppMask_un_5_;
	cppVar_69025 = (cppVar_69024 & cppMask_un_5_);
	cppVar_69026 = cppVar_69025 + 32;
	cppVar_69026 = (cppVar_69026 & cppMask_un_8_);
	cppVar_69013 = cppVar_69026;
	}
	cppVar_69028 = (cppVar_69013 == 153);
	if (cppVar_69028) {
	cppVar_69012 = SBUF;
	} else {
	cppVar_69031 = PC + 1;
	cppVar_69031 = (cppVar_69031 & cppMask_un_16_);
	cppVar_69032 = ROM.rd(cppVar_69031);
	cppVar_69033 = (cppVar_69032 >> 7) & cppMask_un_1_;
	cppVar_69034 = (cppVar_69033 == 1);
	if (cppVar_69034) {
	cppVar_69035 = PC + 1;
	cppVar_69035 = (cppVar_69035 & cppMask_un_16_);
	cppVar_69036 = ROM.rd(cppVar_69035);
	cppVar_69037 = (cppVar_69036 >> 3) & cppMask_un_5_;
	cppVar_69038 = (cppVar_69037 << 3) | 0;
	cppVar_69038 = (cppVar_69038 & cppMask_un_8_);
	cppVar_69030 = cppVar_69038;
	} else {
	cppVar_69039 = PC + 1;
	cppVar_69039 = (cppVar_69039 & cppMask_un_16_);
	cppVar_69040 = ROM.rd(cppVar_69039);
	cppVar_69041 = (cppVar_69040 >> 3) & cppMask_un_5_;
	cppVar_69042 = (cppVar_69041 & cppMask_un_5_);
	cppVar_69043 = cppVar_69042 + 32;
	cppVar_69043 = (cppVar_69043 & cppMask_un_8_);
	cppVar_69030 = cppVar_69043;
	}
	cppVar_69045 = (cppVar_69030 == 160);
	if (cppVar_69045) {
	cppVar_69029 = P2;
	} else {
	cppVar_69048 = PC + 1;
	cppVar_69048 = (cppVar_69048 & cppMask_un_16_);
	cppVar_69049 = ROM.rd(cppVar_69048);
	cppVar_69050 = (cppVar_69049 >> 7) & cppMask_un_1_;
	cppVar_69051 = (cppVar_69050 == 1);
	if (cppVar_69051) {
	cppVar_69052 = PC + 1;
	cppVar_69052 = (cppVar_69052 & cppMask_un_16_);
	cppVar_69053 = ROM.rd(cppVar_69052);
	cppVar_69054 = (cppVar_69053 >> 3) & cppMask_un_5_;
	cppVar_69055 = (cppVar_69054 << 3) | 0;
	cppVar_69055 = (cppVar_69055 & cppMask_un_8_);
	cppVar_69047 = cppVar_69055;
	} else {
	cppVar_69056 = PC + 1;
	cppVar_69056 = (cppVar_69056 & cppMask_un_16_);
	cppVar_69057 = ROM.rd(cppVar_69056);
	cppVar_69058 = (cppVar_69057 >> 3) & cppMask_un_5_;
	cppVar_69059 = (cppVar_69058 & cppMask_un_5_);
	cppVar_69060 = cppVar_69059 + 32;
	cppVar_69060 = (cppVar_69060 & cppMask_un_8_);
	cppVar_69047 = cppVar_69060;
	}
	cppVar_69062 = (cppVar_69047 == 168);
	if (cppVar_69062) {
	cppVar_69046 = IE;
	} else {
	cppVar_69065 = PC + 1;
	cppVar_69065 = (cppVar_69065 & cppMask_un_16_);
	cppVar_69066 = ROM.rd(cppVar_69065);
	cppVar_69067 = (cppVar_69066 >> 7) & cppMask_un_1_;
	cppVar_69068 = (cppVar_69067 == 1);
	if (cppVar_69068) {
	cppVar_69069 = PC + 1;
	cppVar_69069 = (cppVar_69069 & cppMask_un_16_);
	cppVar_69070 = ROM.rd(cppVar_69069);
	cppVar_69071 = (cppVar_69070 >> 3) & cppMask_un_5_;
	cppVar_69072 = (cppVar_69071 << 3) | 0;
	cppVar_69072 = (cppVar_69072 & cppMask_un_8_);
	cppVar_69064 = cppVar_69072;
	} else {
	cppVar_69073 = PC + 1;
	cppVar_69073 = (cppVar_69073 & cppMask_un_16_);
	cppVar_69074 = ROM.rd(cppVar_69073);
	cppVar_69075 = (cppVar_69074 >> 3) & cppMask_un_5_;
	cppVar_69076 = (cppVar_69075 & cppMask_un_5_);
	cppVar_69077 = cppVar_69076 + 32;
	cppVar_69077 = (cppVar_69077 & cppMask_un_8_);
	cppVar_69064 = cppVar_69077;
	}
	cppVar_69079 = (cppVar_69064 == 176);
	if (cppVar_69079) {
	cppVar_69063 = P3;
	} else {
	cppVar_69082 = PC + 1;
	cppVar_69082 = (cppVar_69082 & cppMask_un_16_);
	cppVar_69083 = ROM.rd(cppVar_69082);
	cppVar_69084 = (cppVar_69083 >> 7) & cppMask_un_1_;
	cppVar_69085 = (cppVar_69084 == 1);
	if (cppVar_69085) {
	cppVar_69086 = PC + 1;
	cppVar_69086 = (cppVar_69086 & cppMask_un_16_);
	cppVar_69087 = ROM.rd(cppVar_69086);
	cppVar_69088 = (cppVar_69087 >> 3) & cppMask_un_5_;
	cppVar_69089 = (cppVar_69088 << 3) | 0;
	cppVar_69089 = (cppVar_69089 & cppMask_un_8_);
	cppVar_69081 = cppVar_69089;
	} else {
	cppVar_69090 = PC + 1;
	cppVar_69090 = (cppVar_69090 & cppMask_un_16_);
	cppVar_69091 = ROM.rd(cppVar_69090);
	cppVar_69092 = (cppVar_69091 >> 3) & cppMask_un_5_;
	cppVar_69093 = (cppVar_69092 & cppMask_un_5_);
	cppVar_69094 = cppVar_69093 + 32;
	cppVar_69094 = (cppVar_69094 & cppMask_un_8_);
	cppVar_69081 = cppVar_69094;
	}
	cppVar_69096 = (cppVar_69081 == 184);
	if (cppVar_69096) {
	cppVar_69080 = IP;
	} else {
	cppVar_69099 = PC + 1;
	cppVar_69099 = (cppVar_69099 & cppMask_un_16_);
	cppVar_69100 = ROM.rd(cppVar_69099);
	cppVar_69101 = (cppVar_69100 >> 7) & cppMask_un_1_;
	cppVar_69102 = (cppVar_69101 == 1);
	if (cppVar_69102) {
	cppVar_69103 = PC + 1;
	cppVar_69103 = (cppVar_69103 & cppMask_un_16_);
	cppVar_69104 = ROM.rd(cppVar_69103);
	cppVar_69105 = (cppVar_69104 >> 3) & cppMask_un_5_;
	cppVar_69106 = (cppVar_69105 << 3) | 0;
	cppVar_69106 = (cppVar_69106 & cppMask_un_8_);
	cppVar_69098 = cppVar_69106;
	} else {
	cppVar_69107 = PC + 1;
	cppVar_69107 = (cppVar_69107 & cppMask_un_16_);
	cppVar_69108 = ROM.rd(cppVar_69107);
	cppVar_69109 = (cppVar_69108 >> 3) & cppMask_un_5_;
	cppVar_69110 = (cppVar_69109 & cppMask_un_5_);
	cppVar_69111 = cppVar_69110 + 32;
	cppVar_69111 = (cppVar_69111 & cppMask_un_8_);
	cppVar_69098 = cppVar_69111;
	}
	cppVar_69113 = (cppVar_69098 == 208);
	if (cppVar_69113) {
	cppVar_69097 = PSW;
	} else {
	cppVar_69116 = PC + 1;
	cppVar_69116 = (cppVar_69116 & cppMask_un_16_);
	cppVar_69117 = ROM.rd(cppVar_69116);
	cppVar_69118 = (cppVar_69117 >> 7) & cppMask_un_1_;
	cppVar_69119 = (cppVar_69118 == 1);
	if (cppVar_69119) {
	cppVar_69120 = PC + 1;
	cppVar_69120 = (cppVar_69120 & cppMask_un_16_);
	cppVar_69121 = ROM.rd(cppVar_69120);
	cppVar_69122 = (cppVar_69121 >> 3) & cppMask_un_5_;
	cppVar_69123 = (cppVar_69122 << 3) | 0;
	cppVar_69123 = (cppVar_69123 & cppMask_un_8_);
	cppVar_69115 = cppVar_69123;
	} else {
	cppVar_69124 = PC + 1;
	cppVar_69124 = (cppVar_69124 & cppMask_un_16_);
	cppVar_69125 = ROM.rd(cppVar_69124);
	cppVar_69126 = (cppVar_69125 >> 3) & cppMask_un_5_;
	cppVar_69127 = (cppVar_69126 & cppMask_un_5_);
	cppVar_69128 = cppVar_69127 + 32;
	cppVar_69128 = (cppVar_69128 & cppMask_un_8_);
	cppVar_69115 = cppVar_69128;
	}
	cppVar_69130 = (cppVar_69115 == 224);
	if (cppVar_69130) {
	cppVar_69114 = ACC;
	} else {
	cppVar_69133 = PC + 1;
	cppVar_69133 = (cppVar_69133 & cppMask_un_16_);
	cppVar_69134 = ROM.rd(cppVar_69133);
	cppVar_69135 = (cppVar_69134 >> 7) & cppMask_un_1_;
	cppVar_69136 = (cppVar_69135 == 1);
	if (cppVar_69136) {
	cppVar_69137 = PC + 1;
	cppVar_69137 = (cppVar_69137 & cppMask_un_16_);
	cppVar_69138 = ROM.rd(cppVar_69137);
	cppVar_69139 = (cppVar_69138 >> 3) & cppMask_un_5_;
	cppVar_69140 = (cppVar_69139 << 3) | 0;
	cppVar_69140 = (cppVar_69140 & cppMask_un_8_);
	cppVar_69132 = cppVar_69140;
	} else {
	cppVar_69141 = PC + 1;
	cppVar_69141 = (cppVar_69141 & cppMask_un_16_);
	cppVar_69142 = ROM.rd(cppVar_69141);
	cppVar_69143 = (cppVar_69142 >> 3) & cppMask_un_5_;
	cppVar_69144 = (cppVar_69143 & cppMask_un_5_);
	cppVar_69145 = cppVar_69144 + 32;
	cppVar_69145 = (cppVar_69145 & cppMask_un_8_);
	cppVar_69132 = cppVar_69145;
	}
	cppVar_69147 = (cppVar_69132 == 240);
	if (cppVar_69147) {
	cppVar_69131 = B;
	} else {
	cppVar_69131 = 0;
	}
	cppVar_69114 = cppVar_69131;
	}
	cppVar_69097 = cppVar_69114;
	}
	cppVar_69080 = cppVar_69097;
	}
	cppVar_69063 = cppVar_69080;
	}
	cppVar_69046 = cppVar_69063;
	}
	cppVar_69029 = cppVar_69046;
	}
	cppVar_69012 = cppVar_69029;
	}
	cppVar_68995 = cppVar_69012;
	}
	cppVar_68978 = cppVar_68995;
	}
	cppVar_68961 = cppVar_68978;
	}
	cppVar_68944 = cppVar_68961;
	}
	cppVar_68927 = cppVar_68944;
	}
	cppVar_68910 = cppVar_68927;
	}
	cppVar_68893 = cppVar_68910;
	}
	cppVar_68876 = cppVar_68893;
	}
	cppVar_68859 = cppVar_68876;
	}
	cppVar_68842 = cppVar_68859;
	}
	cppVar_68825 = cppVar_68842;
	}
	cppVar_68808 = cppVar_68825;
	}
	cppVar_68791 = cppVar_68808;
	}
	cppVar_68755 = cppVar_68791;
	}
	cppVar_69149 = PC + 1;
	cppVar_69149 = (cppVar_69149 & cppMask_un_16_);
	cppVar_69150 = ROM.rd(cppVar_69149);
	cppVar_69151 = (cppVar_69150 >> 0) & cppMask_un_3_;
	cppVar_69152 = (cppVar_68755 >> static_cast<unsigned>(cppVar_69151)) & 0x1;
	cppVar_69153 = ~cppVar_69152;
	cppVar_69154 = (cppVar_69153 & cppMask_un_1_);
	cppVar_69155 = PC + 1;
	cppVar_69155 = (cppVar_69155 & cppMask_un_16_);
	cppVar_69156 = ROM.rd(cppVar_69155);
	cppVar_69157 = (cppVar_69156 >> 0) & cppMask_un_3_;
	cppVar_69158 = (cppVar_69157 & cppMask_un_3_);
	cppVar_69159 = cppVar_69154 << static_cast<unsigned>(cppVar_69158);
	cppVar_69159 = (cppVar_69159 & cppMask_un_8_);
	cppVar_69160 = cppVar_68754 | cppVar_69159;
	cppVar_68335 = cppVar_69160;
	} else {
	cppVar_68335 = TCON;
	}
	cppVar_68331 = cppVar_68335;
	} else {
	cppVar_69162 = ROM.rd(PC);
	cppVar_69164 = (cppVar_69162 == 146);
	if (cppVar_69164) {
	cppVar_69168 = PC + 1;
	cppVar_69168 = (cppVar_69168 & cppMask_un_16_);
	cppVar_69169 = ROM.rd(cppVar_69168);
	cppVar_69170 = (cppVar_69169 >> 7) & cppMask_un_1_;
	cppVar_69172 = (cppVar_69170 == 1);
	if (cppVar_69172) {
	cppVar_69173 = PC + 1;
	cppVar_69173 = (cppVar_69173 & cppMask_un_16_);
	cppVar_69174 = ROM.rd(cppVar_69173);
	cppVar_69175 = (cppVar_69174 >> 3) & cppMask_un_5_;
	cppVar_69177 = (cppVar_69175 << 3) | 0;
	cppVar_69177 = (cppVar_69177 & cppMask_un_8_);
	cppVar_69166 = cppVar_69177;
	} else {
	cppVar_69178 = PC + 1;
	cppVar_69178 = (cppVar_69178 & cppMask_un_16_);
	cppVar_69179 = ROM.rd(cppVar_69178);
	cppVar_69180 = (cppVar_69179 >> 3) & cppMask_un_5_;
	cppVar_69181 = (cppVar_69180 & cppMask_un_5_);
	cppVar_69183 = cppVar_69181 + 32;
	cppVar_69183 = (cppVar_69183 & cppMask_un_8_);
	cppVar_69166 = cppVar_69183;
	}
	cppVar_69185 = (cppVar_69166 == 136);
	if (cppVar_69185) {
	cppVar_69187 = PC + 1;
	cppVar_69187 = (cppVar_69187 & cppMask_un_16_);
	cppVar_69188 = ROM.rd(cppVar_69187);
	cppVar_69189 = (cppVar_69188 >> 0) & cppMask_un_3_;
	cppVar_69190 = (cppVar_69189 & cppMask_un_3_);
	cppVar_69191 = 1 << static_cast<unsigned>(cppVar_69190);
	cppVar_69191 = (cppVar_69191 & cppMask_un_8_);
	cppVar_69192 = ~cppVar_69191;
	cppVar_69195 = PC + 1;
	cppVar_69195 = (cppVar_69195 & cppMask_un_16_);
	cppVar_69196 = ROM.rd(cppVar_69195);
	cppVar_69197 = (cppVar_69196 >> 7) & cppMask_un_1_;
	cppVar_69198 = (cppVar_69197 == 1);
	if (cppVar_69198) {
	cppVar_69199 = PC + 1;
	cppVar_69199 = (cppVar_69199 & cppMask_un_16_);
	cppVar_69200 = ROM.rd(cppVar_69199);
	cppVar_69201 = (cppVar_69200 >> 3) & cppMask_un_5_;
	cppVar_69202 = (cppVar_69201 << 3) | 0;
	cppVar_69202 = (cppVar_69202 & cppMask_un_8_);
	cppVar_69194 = cppVar_69202;
	} else {
	cppVar_69203 = PC + 1;
	cppVar_69203 = (cppVar_69203 & cppMask_un_16_);
	cppVar_69204 = ROM.rd(cppVar_69203);
	cppVar_69205 = (cppVar_69204 >> 3) & cppMask_un_5_;
	cppVar_69206 = (cppVar_69205 & cppMask_un_5_);
	cppVar_69207 = cppVar_69206 + 32;
	cppVar_69207 = (cppVar_69207 & cppMask_un_8_);
	cppVar_69194 = cppVar_69207;
	}
	cppVar_69208 = (cppVar_69194 >> 7) & cppMask_un_1_;
	cppVar_69210 = (cppVar_69208 == 0);
	if (cppVar_69210) {
	cppVar_69212 = PC + 1;
	cppVar_69212 = (cppVar_69212 & cppMask_un_16_);
	cppVar_69213 = ROM.rd(cppVar_69212);
	cppVar_69214 = (cppVar_69213 >> 7) & cppMask_un_1_;
	cppVar_69215 = (cppVar_69214 == 1);
	if (cppVar_69215) {
	cppVar_69216 = PC + 1;
	cppVar_69216 = (cppVar_69216 & cppMask_un_16_);
	cppVar_69217 = ROM.rd(cppVar_69216);
	cppVar_69218 = (cppVar_69217 >> 3) & cppMask_un_5_;
	cppVar_69219 = (cppVar_69218 << 3) | 0;
	cppVar_69219 = (cppVar_69219 & cppMask_un_8_);
	cppVar_69211 = cppVar_69219;
	} else {
	cppVar_69220 = PC + 1;
	cppVar_69220 = (cppVar_69220 & cppMask_un_16_);
	cppVar_69221 = ROM.rd(cppVar_69220);
	cppVar_69222 = (cppVar_69221 >> 3) & cppMask_un_5_;
	cppVar_69223 = (cppVar_69222 & cppMask_un_5_);
	cppVar_69224 = cppVar_69223 + 32;
	cppVar_69224 = (cppVar_69224 & cppMask_un_8_);
	cppVar_69211 = cppVar_69224;
	}
	cppVar_69225 = IRAM.rd(cppVar_69211);
	cppVar_69193 = cppVar_69225;
	} else {
	cppVar_69228 = PC + 1;
	cppVar_69228 = (cppVar_69228 & cppMask_un_16_);
	cppVar_69229 = ROM.rd(cppVar_69228);
	cppVar_69230 = (cppVar_69229 >> 7) & cppMask_un_1_;
	cppVar_69231 = (cppVar_69230 == 1);
	if (cppVar_69231) {
	cppVar_69232 = PC + 1;
	cppVar_69232 = (cppVar_69232 & cppMask_un_16_);
	cppVar_69233 = ROM.rd(cppVar_69232);
	cppVar_69234 = (cppVar_69233 >> 3) & cppMask_un_5_;
	cppVar_69235 = (cppVar_69234 << 3) | 0;
	cppVar_69235 = (cppVar_69235 & cppMask_un_8_);
	cppVar_69227 = cppVar_69235;
	} else {
	cppVar_69236 = PC + 1;
	cppVar_69236 = (cppVar_69236 & cppMask_un_16_);
	cppVar_69237 = ROM.rd(cppVar_69236);
	cppVar_69238 = (cppVar_69237 >> 3) & cppMask_un_5_;
	cppVar_69239 = (cppVar_69238 & cppMask_un_5_);
	cppVar_69240 = cppVar_69239 + 32;
	cppVar_69240 = (cppVar_69240 & cppMask_un_8_);
	cppVar_69227 = cppVar_69240;
	}
	cppVar_69242 = (cppVar_69227 == 128);
	if (cppVar_69242) {
	cppVar_69226 = P0;
	} else {
	cppVar_69245 = PC + 1;
	cppVar_69245 = (cppVar_69245 & cppMask_un_16_);
	cppVar_69246 = ROM.rd(cppVar_69245);
	cppVar_69247 = (cppVar_69246 >> 7) & cppMask_un_1_;
	cppVar_69248 = (cppVar_69247 == 1);
	if (cppVar_69248) {
	cppVar_69249 = PC + 1;
	cppVar_69249 = (cppVar_69249 & cppMask_un_16_);
	cppVar_69250 = ROM.rd(cppVar_69249);
	cppVar_69251 = (cppVar_69250 >> 3) & cppMask_un_5_;
	cppVar_69252 = (cppVar_69251 << 3) | 0;
	cppVar_69252 = (cppVar_69252 & cppMask_un_8_);
	cppVar_69244 = cppVar_69252;
	} else {
	cppVar_69253 = PC + 1;
	cppVar_69253 = (cppVar_69253 & cppMask_un_16_);
	cppVar_69254 = ROM.rd(cppVar_69253);
	cppVar_69255 = (cppVar_69254 >> 3) & cppMask_un_5_;
	cppVar_69256 = (cppVar_69255 & cppMask_un_5_);
	cppVar_69257 = cppVar_69256 + 32;
	cppVar_69257 = (cppVar_69257 & cppMask_un_8_);
	cppVar_69244 = cppVar_69257;
	}
	cppVar_69259 = (cppVar_69244 == 129);
	if (cppVar_69259) {
	cppVar_69243 = SP;
	} else {
	cppVar_69262 = PC + 1;
	cppVar_69262 = (cppVar_69262 & cppMask_un_16_);
	cppVar_69263 = ROM.rd(cppVar_69262);
	cppVar_69264 = (cppVar_69263 >> 7) & cppMask_un_1_;
	cppVar_69265 = (cppVar_69264 == 1);
	if (cppVar_69265) {
	cppVar_69266 = PC + 1;
	cppVar_69266 = (cppVar_69266 & cppMask_un_16_);
	cppVar_69267 = ROM.rd(cppVar_69266);
	cppVar_69268 = (cppVar_69267 >> 3) & cppMask_un_5_;
	cppVar_69269 = (cppVar_69268 << 3) | 0;
	cppVar_69269 = (cppVar_69269 & cppMask_un_8_);
	cppVar_69261 = cppVar_69269;
	} else {
	cppVar_69270 = PC + 1;
	cppVar_69270 = (cppVar_69270 & cppMask_un_16_);
	cppVar_69271 = ROM.rd(cppVar_69270);
	cppVar_69272 = (cppVar_69271 >> 3) & cppMask_un_5_;
	cppVar_69273 = (cppVar_69272 & cppMask_un_5_);
	cppVar_69274 = cppVar_69273 + 32;
	cppVar_69274 = (cppVar_69274 & cppMask_un_8_);
	cppVar_69261 = cppVar_69274;
	}
	cppVar_69276 = (cppVar_69261 == 130);
	if (cppVar_69276) {
	cppVar_69260 = DPL;
	} else {
	cppVar_69279 = PC + 1;
	cppVar_69279 = (cppVar_69279 & cppMask_un_16_);
	cppVar_69280 = ROM.rd(cppVar_69279);
	cppVar_69281 = (cppVar_69280 >> 7) & cppMask_un_1_;
	cppVar_69282 = (cppVar_69281 == 1);
	if (cppVar_69282) {
	cppVar_69283 = PC + 1;
	cppVar_69283 = (cppVar_69283 & cppMask_un_16_);
	cppVar_69284 = ROM.rd(cppVar_69283);
	cppVar_69285 = (cppVar_69284 >> 3) & cppMask_un_5_;
	cppVar_69286 = (cppVar_69285 << 3) | 0;
	cppVar_69286 = (cppVar_69286 & cppMask_un_8_);
	cppVar_69278 = cppVar_69286;
	} else {
	cppVar_69287 = PC + 1;
	cppVar_69287 = (cppVar_69287 & cppMask_un_16_);
	cppVar_69288 = ROM.rd(cppVar_69287);
	cppVar_69289 = (cppVar_69288 >> 3) & cppMask_un_5_;
	cppVar_69290 = (cppVar_69289 & cppMask_un_5_);
	cppVar_69291 = cppVar_69290 + 32;
	cppVar_69291 = (cppVar_69291 & cppMask_un_8_);
	cppVar_69278 = cppVar_69291;
	}
	cppVar_69293 = (cppVar_69278 == 131);
	if (cppVar_69293) {
	cppVar_69277 = DPH;
	} else {
	cppVar_69296 = PC + 1;
	cppVar_69296 = (cppVar_69296 & cppMask_un_16_);
	cppVar_69297 = ROM.rd(cppVar_69296);
	cppVar_69298 = (cppVar_69297 >> 7) & cppMask_un_1_;
	cppVar_69299 = (cppVar_69298 == 1);
	if (cppVar_69299) {
	cppVar_69300 = PC + 1;
	cppVar_69300 = (cppVar_69300 & cppMask_un_16_);
	cppVar_69301 = ROM.rd(cppVar_69300);
	cppVar_69302 = (cppVar_69301 >> 3) & cppMask_un_5_;
	cppVar_69303 = (cppVar_69302 << 3) | 0;
	cppVar_69303 = (cppVar_69303 & cppMask_un_8_);
	cppVar_69295 = cppVar_69303;
	} else {
	cppVar_69304 = PC + 1;
	cppVar_69304 = (cppVar_69304 & cppMask_un_16_);
	cppVar_69305 = ROM.rd(cppVar_69304);
	cppVar_69306 = (cppVar_69305 >> 3) & cppMask_un_5_;
	cppVar_69307 = (cppVar_69306 & cppMask_un_5_);
	cppVar_69308 = cppVar_69307 + 32;
	cppVar_69308 = (cppVar_69308 & cppMask_un_8_);
	cppVar_69295 = cppVar_69308;
	}
	cppVar_69310 = (cppVar_69295 == 135);
	if (cppVar_69310) {
	cppVar_69294 = PCON;
	} else {
	cppVar_69313 = PC + 1;
	cppVar_69313 = (cppVar_69313 & cppMask_un_16_);
	cppVar_69314 = ROM.rd(cppVar_69313);
	cppVar_69315 = (cppVar_69314 >> 7) & cppMask_un_1_;
	cppVar_69316 = (cppVar_69315 == 1);
	if (cppVar_69316) {
	cppVar_69317 = PC + 1;
	cppVar_69317 = (cppVar_69317 & cppMask_un_16_);
	cppVar_69318 = ROM.rd(cppVar_69317);
	cppVar_69319 = (cppVar_69318 >> 3) & cppMask_un_5_;
	cppVar_69320 = (cppVar_69319 << 3) | 0;
	cppVar_69320 = (cppVar_69320 & cppMask_un_8_);
	cppVar_69312 = cppVar_69320;
	} else {
	cppVar_69321 = PC + 1;
	cppVar_69321 = (cppVar_69321 & cppMask_un_16_);
	cppVar_69322 = ROM.rd(cppVar_69321);
	cppVar_69323 = (cppVar_69322 >> 3) & cppMask_un_5_;
	cppVar_69324 = (cppVar_69323 & cppMask_un_5_);
	cppVar_69325 = cppVar_69324 + 32;
	cppVar_69325 = (cppVar_69325 & cppMask_un_8_);
	cppVar_69312 = cppVar_69325;
	}
	cppVar_69327 = (cppVar_69312 == 136);
	if (cppVar_69327) {
	cppVar_69311 = TCON;
	} else {
	cppVar_69330 = PC + 1;
	cppVar_69330 = (cppVar_69330 & cppMask_un_16_);
	cppVar_69331 = ROM.rd(cppVar_69330);
	cppVar_69332 = (cppVar_69331 >> 7) & cppMask_un_1_;
	cppVar_69333 = (cppVar_69332 == 1);
	if (cppVar_69333) {
	cppVar_69334 = PC + 1;
	cppVar_69334 = (cppVar_69334 & cppMask_un_16_);
	cppVar_69335 = ROM.rd(cppVar_69334);
	cppVar_69336 = (cppVar_69335 >> 3) & cppMask_un_5_;
	cppVar_69337 = (cppVar_69336 << 3) | 0;
	cppVar_69337 = (cppVar_69337 & cppMask_un_8_);
	cppVar_69329 = cppVar_69337;
	} else {
	cppVar_69338 = PC + 1;
	cppVar_69338 = (cppVar_69338 & cppMask_un_16_);
	cppVar_69339 = ROM.rd(cppVar_69338);
	cppVar_69340 = (cppVar_69339 >> 3) & cppMask_un_5_;
	cppVar_69341 = (cppVar_69340 & cppMask_un_5_);
	cppVar_69342 = cppVar_69341 + 32;
	cppVar_69342 = (cppVar_69342 & cppMask_un_8_);
	cppVar_69329 = cppVar_69342;
	}
	cppVar_69344 = (cppVar_69329 == 137);
	if (cppVar_69344) {
	cppVar_69328 = TMOD;
	} else {
	cppVar_69347 = PC + 1;
	cppVar_69347 = (cppVar_69347 & cppMask_un_16_);
	cppVar_69348 = ROM.rd(cppVar_69347);
	cppVar_69349 = (cppVar_69348 >> 7) & cppMask_un_1_;
	cppVar_69350 = (cppVar_69349 == 1);
	if (cppVar_69350) {
	cppVar_69351 = PC + 1;
	cppVar_69351 = (cppVar_69351 & cppMask_un_16_);
	cppVar_69352 = ROM.rd(cppVar_69351);
	cppVar_69353 = (cppVar_69352 >> 3) & cppMask_un_5_;
	cppVar_69354 = (cppVar_69353 << 3) | 0;
	cppVar_69354 = (cppVar_69354 & cppMask_un_8_);
	cppVar_69346 = cppVar_69354;
	} else {
	cppVar_69355 = PC + 1;
	cppVar_69355 = (cppVar_69355 & cppMask_un_16_);
	cppVar_69356 = ROM.rd(cppVar_69355);
	cppVar_69357 = (cppVar_69356 >> 3) & cppMask_un_5_;
	cppVar_69358 = (cppVar_69357 & cppMask_un_5_);
	cppVar_69359 = cppVar_69358 + 32;
	cppVar_69359 = (cppVar_69359 & cppMask_un_8_);
	cppVar_69346 = cppVar_69359;
	}
	cppVar_69361 = (cppVar_69346 == 138);
	if (cppVar_69361) {
	cppVar_69345 = TL0;
	} else {
	cppVar_69364 = PC + 1;
	cppVar_69364 = (cppVar_69364 & cppMask_un_16_);
	cppVar_69365 = ROM.rd(cppVar_69364);
	cppVar_69366 = (cppVar_69365 >> 7) & cppMask_un_1_;
	cppVar_69367 = (cppVar_69366 == 1);
	if (cppVar_69367) {
	cppVar_69368 = PC + 1;
	cppVar_69368 = (cppVar_69368 & cppMask_un_16_);
	cppVar_69369 = ROM.rd(cppVar_69368);
	cppVar_69370 = (cppVar_69369 >> 3) & cppMask_un_5_;
	cppVar_69371 = (cppVar_69370 << 3) | 0;
	cppVar_69371 = (cppVar_69371 & cppMask_un_8_);
	cppVar_69363 = cppVar_69371;
	} else {
	cppVar_69372 = PC + 1;
	cppVar_69372 = (cppVar_69372 & cppMask_un_16_);
	cppVar_69373 = ROM.rd(cppVar_69372);
	cppVar_69374 = (cppVar_69373 >> 3) & cppMask_un_5_;
	cppVar_69375 = (cppVar_69374 & cppMask_un_5_);
	cppVar_69376 = cppVar_69375 + 32;
	cppVar_69376 = (cppVar_69376 & cppMask_un_8_);
	cppVar_69363 = cppVar_69376;
	}
	cppVar_69378 = (cppVar_69363 == 140);
	if (cppVar_69378) {
	cppVar_69362 = TH0;
	} else {
	cppVar_69381 = PC + 1;
	cppVar_69381 = (cppVar_69381 & cppMask_un_16_);
	cppVar_69382 = ROM.rd(cppVar_69381);
	cppVar_69383 = (cppVar_69382 >> 7) & cppMask_un_1_;
	cppVar_69384 = (cppVar_69383 == 1);
	if (cppVar_69384) {
	cppVar_69385 = PC + 1;
	cppVar_69385 = (cppVar_69385 & cppMask_un_16_);
	cppVar_69386 = ROM.rd(cppVar_69385);
	cppVar_69387 = (cppVar_69386 >> 3) & cppMask_un_5_;
	cppVar_69388 = (cppVar_69387 << 3) | 0;
	cppVar_69388 = (cppVar_69388 & cppMask_un_8_);
	cppVar_69380 = cppVar_69388;
	} else {
	cppVar_69389 = PC + 1;
	cppVar_69389 = (cppVar_69389 & cppMask_un_16_);
	cppVar_69390 = ROM.rd(cppVar_69389);
	cppVar_69391 = (cppVar_69390 >> 3) & cppMask_un_5_;
	cppVar_69392 = (cppVar_69391 & cppMask_un_5_);
	cppVar_69393 = cppVar_69392 + 32;
	cppVar_69393 = (cppVar_69393 & cppMask_un_8_);
	cppVar_69380 = cppVar_69393;
	}
	cppVar_69395 = (cppVar_69380 == 139);
	if (cppVar_69395) {
	cppVar_69379 = TL1;
	} else {
	cppVar_69398 = PC + 1;
	cppVar_69398 = (cppVar_69398 & cppMask_un_16_);
	cppVar_69399 = ROM.rd(cppVar_69398);
	cppVar_69400 = (cppVar_69399 >> 7) & cppMask_un_1_;
	cppVar_69401 = (cppVar_69400 == 1);
	if (cppVar_69401) {
	cppVar_69402 = PC + 1;
	cppVar_69402 = (cppVar_69402 & cppMask_un_16_);
	cppVar_69403 = ROM.rd(cppVar_69402);
	cppVar_69404 = (cppVar_69403 >> 3) & cppMask_un_5_;
	cppVar_69405 = (cppVar_69404 << 3) | 0;
	cppVar_69405 = (cppVar_69405 & cppMask_un_8_);
	cppVar_69397 = cppVar_69405;
	} else {
	cppVar_69406 = PC + 1;
	cppVar_69406 = (cppVar_69406 & cppMask_un_16_);
	cppVar_69407 = ROM.rd(cppVar_69406);
	cppVar_69408 = (cppVar_69407 >> 3) & cppMask_un_5_;
	cppVar_69409 = (cppVar_69408 & cppMask_un_5_);
	cppVar_69410 = cppVar_69409 + 32;
	cppVar_69410 = (cppVar_69410 & cppMask_un_8_);
	cppVar_69397 = cppVar_69410;
	}
	cppVar_69412 = (cppVar_69397 == 141);
	if (cppVar_69412) {
	cppVar_69396 = TH1;
	} else {
	cppVar_69415 = PC + 1;
	cppVar_69415 = (cppVar_69415 & cppMask_un_16_);
	cppVar_69416 = ROM.rd(cppVar_69415);
	cppVar_69417 = (cppVar_69416 >> 7) & cppMask_un_1_;
	cppVar_69418 = (cppVar_69417 == 1);
	if (cppVar_69418) {
	cppVar_69419 = PC + 1;
	cppVar_69419 = (cppVar_69419 & cppMask_un_16_);
	cppVar_69420 = ROM.rd(cppVar_69419);
	cppVar_69421 = (cppVar_69420 >> 3) & cppMask_un_5_;
	cppVar_69422 = (cppVar_69421 << 3) | 0;
	cppVar_69422 = (cppVar_69422 & cppMask_un_8_);
	cppVar_69414 = cppVar_69422;
	} else {
	cppVar_69423 = PC + 1;
	cppVar_69423 = (cppVar_69423 & cppMask_un_16_);
	cppVar_69424 = ROM.rd(cppVar_69423);
	cppVar_69425 = (cppVar_69424 >> 3) & cppMask_un_5_;
	cppVar_69426 = (cppVar_69425 & cppMask_un_5_);
	cppVar_69427 = cppVar_69426 + 32;
	cppVar_69427 = (cppVar_69427 & cppMask_un_8_);
	cppVar_69414 = cppVar_69427;
	}
	cppVar_69429 = (cppVar_69414 == 144);
	if (cppVar_69429) {
	cppVar_69413 = P1;
	} else {
	cppVar_69432 = PC + 1;
	cppVar_69432 = (cppVar_69432 & cppMask_un_16_);
	cppVar_69433 = ROM.rd(cppVar_69432);
	cppVar_69434 = (cppVar_69433 >> 7) & cppMask_un_1_;
	cppVar_69435 = (cppVar_69434 == 1);
	if (cppVar_69435) {
	cppVar_69436 = PC + 1;
	cppVar_69436 = (cppVar_69436 & cppMask_un_16_);
	cppVar_69437 = ROM.rd(cppVar_69436);
	cppVar_69438 = (cppVar_69437 >> 3) & cppMask_un_5_;
	cppVar_69439 = (cppVar_69438 << 3) | 0;
	cppVar_69439 = (cppVar_69439 & cppMask_un_8_);
	cppVar_69431 = cppVar_69439;
	} else {
	cppVar_69440 = PC + 1;
	cppVar_69440 = (cppVar_69440 & cppMask_un_16_);
	cppVar_69441 = ROM.rd(cppVar_69440);
	cppVar_69442 = (cppVar_69441 >> 3) & cppMask_un_5_;
	cppVar_69443 = (cppVar_69442 & cppMask_un_5_);
	cppVar_69444 = cppVar_69443 + 32;
	cppVar_69444 = (cppVar_69444 & cppMask_un_8_);
	cppVar_69431 = cppVar_69444;
	}
	cppVar_69446 = (cppVar_69431 == 152);
	if (cppVar_69446) {
	cppVar_69430 = SCON;
	} else {
	cppVar_69449 = PC + 1;
	cppVar_69449 = (cppVar_69449 & cppMask_un_16_);
	cppVar_69450 = ROM.rd(cppVar_69449);
	cppVar_69451 = (cppVar_69450 >> 7) & cppMask_un_1_;
	cppVar_69452 = (cppVar_69451 == 1);
	if (cppVar_69452) {
	cppVar_69453 = PC + 1;
	cppVar_69453 = (cppVar_69453 & cppMask_un_16_);
	cppVar_69454 = ROM.rd(cppVar_69453);
	cppVar_69455 = (cppVar_69454 >> 3) & cppMask_un_5_;
	cppVar_69456 = (cppVar_69455 << 3) | 0;
	cppVar_69456 = (cppVar_69456 & cppMask_un_8_);
	cppVar_69448 = cppVar_69456;
	} else {
	cppVar_69457 = PC + 1;
	cppVar_69457 = (cppVar_69457 & cppMask_un_16_);
	cppVar_69458 = ROM.rd(cppVar_69457);
	cppVar_69459 = (cppVar_69458 >> 3) & cppMask_un_5_;
	cppVar_69460 = (cppVar_69459 & cppMask_un_5_);
	cppVar_69461 = cppVar_69460 + 32;
	cppVar_69461 = (cppVar_69461 & cppMask_un_8_);
	cppVar_69448 = cppVar_69461;
	}
	cppVar_69463 = (cppVar_69448 == 153);
	if (cppVar_69463) {
	cppVar_69447 = SBUF;
	} else {
	cppVar_69466 = PC + 1;
	cppVar_69466 = (cppVar_69466 & cppMask_un_16_);
	cppVar_69467 = ROM.rd(cppVar_69466);
	cppVar_69468 = (cppVar_69467 >> 7) & cppMask_un_1_;
	cppVar_69469 = (cppVar_69468 == 1);
	if (cppVar_69469) {
	cppVar_69470 = PC + 1;
	cppVar_69470 = (cppVar_69470 & cppMask_un_16_);
	cppVar_69471 = ROM.rd(cppVar_69470);
	cppVar_69472 = (cppVar_69471 >> 3) & cppMask_un_5_;
	cppVar_69473 = (cppVar_69472 << 3) | 0;
	cppVar_69473 = (cppVar_69473 & cppMask_un_8_);
	cppVar_69465 = cppVar_69473;
	} else {
	cppVar_69474 = PC + 1;
	cppVar_69474 = (cppVar_69474 & cppMask_un_16_);
	cppVar_69475 = ROM.rd(cppVar_69474);
	cppVar_69476 = (cppVar_69475 >> 3) & cppMask_un_5_;
	cppVar_69477 = (cppVar_69476 & cppMask_un_5_);
	cppVar_69478 = cppVar_69477 + 32;
	cppVar_69478 = (cppVar_69478 & cppMask_un_8_);
	cppVar_69465 = cppVar_69478;
	}
	cppVar_69480 = (cppVar_69465 == 160);
	if (cppVar_69480) {
	cppVar_69464 = P2;
	} else {
	cppVar_69483 = PC + 1;
	cppVar_69483 = (cppVar_69483 & cppMask_un_16_);
	cppVar_69484 = ROM.rd(cppVar_69483);
	cppVar_69485 = (cppVar_69484 >> 7) & cppMask_un_1_;
	cppVar_69486 = (cppVar_69485 == 1);
	if (cppVar_69486) {
	cppVar_69487 = PC + 1;
	cppVar_69487 = (cppVar_69487 & cppMask_un_16_);
	cppVar_69488 = ROM.rd(cppVar_69487);
	cppVar_69489 = (cppVar_69488 >> 3) & cppMask_un_5_;
	cppVar_69490 = (cppVar_69489 << 3) | 0;
	cppVar_69490 = (cppVar_69490 & cppMask_un_8_);
	cppVar_69482 = cppVar_69490;
	} else {
	cppVar_69491 = PC + 1;
	cppVar_69491 = (cppVar_69491 & cppMask_un_16_);
	cppVar_69492 = ROM.rd(cppVar_69491);
	cppVar_69493 = (cppVar_69492 >> 3) & cppMask_un_5_;
	cppVar_69494 = (cppVar_69493 & cppMask_un_5_);
	cppVar_69495 = cppVar_69494 + 32;
	cppVar_69495 = (cppVar_69495 & cppMask_un_8_);
	cppVar_69482 = cppVar_69495;
	}
	cppVar_69497 = (cppVar_69482 == 168);
	if (cppVar_69497) {
	cppVar_69481 = IE;
	} else {
	cppVar_69500 = PC + 1;
	cppVar_69500 = (cppVar_69500 & cppMask_un_16_);
	cppVar_69501 = ROM.rd(cppVar_69500);
	cppVar_69502 = (cppVar_69501 >> 7) & cppMask_un_1_;
	cppVar_69503 = (cppVar_69502 == 1);
	if (cppVar_69503) {
	cppVar_69504 = PC + 1;
	cppVar_69504 = (cppVar_69504 & cppMask_un_16_);
	cppVar_69505 = ROM.rd(cppVar_69504);
	cppVar_69506 = (cppVar_69505 >> 3) & cppMask_un_5_;
	cppVar_69507 = (cppVar_69506 << 3) | 0;
	cppVar_69507 = (cppVar_69507 & cppMask_un_8_);
	cppVar_69499 = cppVar_69507;
	} else {
	cppVar_69508 = PC + 1;
	cppVar_69508 = (cppVar_69508 & cppMask_un_16_);
	cppVar_69509 = ROM.rd(cppVar_69508);
	cppVar_69510 = (cppVar_69509 >> 3) & cppMask_un_5_;
	cppVar_69511 = (cppVar_69510 & cppMask_un_5_);
	cppVar_69512 = cppVar_69511 + 32;
	cppVar_69512 = (cppVar_69512 & cppMask_un_8_);
	cppVar_69499 = cppVar_69512;
	}
	cppVar_69514 = (cppVar_69499 == 176);
	if (cppVar_69514) {
	cppVar_69498 = P3;
	} else {
	cppVar_69517 = PC + 1;
	cppVar_69517 = (cppVar_69517 & cppMask_un_16_);
	cppVar_69518 = ROM.rd(cppVar_69517);
	cppVar_69519 = (cppVar_69518 >> 7) & cppMask_un_1_;
	cppVar_69520 = (cppVar_69519 == 1);
	if (cppVar_69520) {
	cppVar_69521 = PC + 1;
	cppVar_69521 = (cppVar_69521 & cppMask_un_16_);
	cppVar_69522 = ROM.rd(cppVar_69521);
	cppVar_69523 = (cppVar_69522 >> 3) & cppMask_un_5_;
	cppVar_69524 = (cppVar_69523 << 3) | 0;
	cppVar_69524 = (cppVar_69524 & cppMask_un_8_);
	cppVar_69516 = cppVar_69524;
	} else {
	cppVar_69525 = PC + 1;
	cppVar_69525 = (cppVar_69525 & cppMask_un_16_);
	cppVar_69526 = ROM.rd(cppVar_69525);
	cppVar_69527 = (cppVar_69526 >> 3) & cppMask_un_5_;
	cppVar_69528 = (cppVar_69527 & cppMask_un_5_);
	cppVar_69529 = cppVar_69528 + 32;
	cppVar_69529 = (cppVar_69529 & cppMask_un_8_);
	cppVar_69516 = cppVar_69529;
	}
	cppVar_69531 = (cppVar_69516 == 184);
	if (cppVar_69531) {
	cppVar_69515 = IP;
	} else {
	cppVar_69534 = PC + 1;
	cppVar_69534 = (cppVar_69534 & cppMask_un_16_);
	cppVar_69535 = ROM.rd(cppVar_69534);
	cppVar_69536 = (cppVar_69535 >> 7) & cppMask_un_1_;
	cppVar_69537 = (cppVar_69536 == 1);
	if (cppVar_69537) {
	cppVar_69538 = PC + 1;
	cppVar_69538 = (cppVar_69538 & cppMask_un_16_);
	cppVar_69539 = ROM.rd(cppVar_69538);
	cppVar_69540 = (cppVar_69539 >> 3) & cppMask_un_5_;
	cppVar_69541 = (cppVar_69540 << 3) | 0;
	cppVar_69541 = (cppVar_69541 & cppMask_un_8_);
	cppVar_69533 = cppVar_69541;
	} else {
	cppVar_69542 = PC + 1;
	cppVar_69542 = (cppVar_69542 & cppMask_un_16_);
	cppVar_69543 = ROM.rd(cppVar_69542);
	cppVar_69544 = (cppVar_69543 >> 3) & cppMask_un_5_;
	cppVar_69545 = (cppVar_69544 & cppMask_un_5_);
	cppVar_69546 = cppVar_69545 + 32;
	cppVar_69546 = (cppVar_69546 & cppMask_un_8_);
	cppVar_69533 = cppVar_69546;
	}
	cppVar_69548 = (cppVar_69533 == 208);
	if (cppVar_69548) {
	cppVar_69532 = PSW;
	} else {
	cppVar_69551 = PC + 1;
	cppVar_69551 = (cppVar_69551 & cppMask_un_16_);
	cppVar_69552 = ROM.rd(cppVar_69551);
	cppVar_69553 = (cppVar_69552 >> 7) & cppMask_un_1_;
	cppVar_69554 = (cppVar_69553 == 1);
	if (cppVar_69554) {
	cppVar_69555 = PC + 1;
	cppVar_69555 = (cppVar_69555 & cppMask_un_16_);
	cppVar_69556 = ROM.rd(cppVar_69555);
	cppVar_69557 = (cppVar_69556 >> 3) & cppMask_un_5_;
	cppVar_69558 = (cppVar_69557 << 3) | 0;
	cppVar_69558 = (cppVar_69558 & cppMask_un_8_);
	cppVar_69550 = cppVar_69558;
	} else {
	cppVar_69559 = PC + 1;
	cppVar_69559 = (cppVar_69559 & cppMask_un_16_);
	cppVar_69560 = ROM.rd(cppVar_69559);
	cppVar_69561 = (cppVar_69560 >> 3) & cppMask_un_5_;
	cppVar_69562 = (cppVar_69561 & cppMask_un_5_);
	cppVar_69563 = cppVar_69562 + 32;
	cppVar_69563 = (cppVar_69563 & cppMask_un_8_);
	cppVar_69550 = cppVar_69563;
	}
	cppVar_69565 = (cppVar_69550 == 224);
	if (cppVar_69565) {
	cppVar_69549 = ACC;
	} else {
	cppVar_69568 = PC + 1;
	cppVar_69568 = (cppVar_69568 & cppMask_un_16_);
	cppVar_69569 = ROM.rd(cppVar_69568);
	cppVar_69570 = (cppVar_69569 >> 7) & cppMask_un_1_;
	cppVar_69571 = (cppVar_69570 == 1);
	if (cppVar_69571) {
	cppVar_69572 = PC + 1;
	cppVar_69572 = (cppVar_69572 & cppMask_un_16_);
	cppVar_69573 = ROM.rd(cppVar_69572);
	cppVar_69574 = (cppVar_69573 >> 3) & cppMask_un_5_;
	cppVar_69575 = (cppVar_69574 << 3) | 0;
	cppVar_69575 = (cppVar_69575 & cppMask_un_8_);
	cppVar_69567 = cppVar_69575;
	} else {
	cppVar_69576 = PC + 1;
	cppVar_69576 = (cppVar_69576 & cppMask_un_16_);
	cppVar_69577 = ROM.rd(cppVar_69576);
	cppVar_69578 = (cppVar_69577 >> 3) & cppMask_un_5_;
	cppVar_69579 = (cppVar_69578 & cppMask_un_5_);
	cppVar_69580 = cppVar_69579 + 32;
	cppVar_69580 = (cppVar_69580 & cppMask_un_8_);
	cppVar_69567 = cppVar_69580;
	}
	cppVar_69582 = (cppVar_69567 == 240);
	if (cppVar_69582) {
	cppVar_69566 = B;
	} else {
	cppVar_69566 = 0;
	}
	cppVar_69549 = cppVar_69566;
	}
	cppVar_69532 = cppVar_69549;
	}
	cppVar_69515 = cppVar_69532;
	}
	cppVar_69498 = cppVar_69515;
	}
	cppVar_69481 = cppVar_69498;
	}
	cppVar_69464 = cppVar_69481;
	}
	cppVar_69447 = cppVar_69464;
	}
	cppVar_69430 = cppVar_69447;
	}
	cppVar_69413 = cppVar_69430;
	}
	cppVar_69396 = cppVar_69413;
	}
	cppVar_69379 = cppVar_69396;
	}
	cppVar_69362 = cppVar_69379;
	}
	cppVar_69345 = cppVar_69362;
	}
	cppVar_69328 = cppVar_69345;
	}
	cppVar_69311 = cppVar_69328;
	}
	cppVar_69294 = cppVar_69311;
	}
	cppVar_69277 = cppVar_69294;
	}
	cppVar_69260 = cppVar_69277;
	}
	cppVar_69243 = cppVar_69260;
	}
	cppVar_69226 = cppVar_69243;
	}
	cppVar_69193 = cppVar_69226;
	}
	cppVar_69584 = cppVar_69192 & cppVar_69193;
	cppVar_69585 = (PSW >> 7) & cppMask_un_1_;
	cppVar_69586 = (cppVar_69585 & cppMask_un_1_);
	cppVar_69587 = PC + 1;
	cppVar_69587 = (cppVar_69587 & cppMask_un_16_);
	cppVar_69588 = ROM.rd(cppVar_69587);
	cppVar_69589 = (cppVar_69588 >> 0) & cppMask_un_3_;
	cppVar_69590 = (cppVar_69589 & cppMask_un_3_);
	cppVar_69591 = cppVar_69586 << static_cast<unsigned>(cppVar_69590);
	cppVar_69591 = (cppVar_69591 & cppMask_un_8_);
	cppVar_69592 = cppVar_69584 | cppVar_69591;
	cppVar_69165 = cppVar_69592;
	} else {
	cppVar_69165 = TCON;
	}
	cppVar_69161 = cppVar_69165;
	} else {
	cppVar_69594 = ROM.rd(PC);
	cppVar_69596 = (cppVar_69594 == 143);
	if (cppVar_69596) {
	cppVar_69599 = PC + 1;
	cppVar_69599 = (cppVar_69599 & cppMask_un_16_);
	cppVar_69600 = ROM.rd(cppVar_69599);
	cppVar_69602 = (cppVar_69600 == 136);
	if (cppVar_69602) {
	cppVar_69605 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69607 = (cppVar_69605 << 3) | 7;
	cppVar_69607 = (cppVar_69607 & cppMask_un_5_);
	cppVar_69608 = (0 << 5) | cppVar_69607;
	cppVar_69608 = (cppVar_69608 & cppMask_un_8_);
	cppVar_69609 = (cppVar_69608 >> 7) & cppMask_un_1_;
	cppVar_69611 = (cppVar_69609 == 0);
	if (cppVar_69611) {
	cppVar_69612 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69613 = (cppVar_69612 << 3) | 7;
	cppVar_69613 = (cppVar_69613 & cppMask_un_5_);
	cppVar_69614 = (0 << 5) | cppVar_69613;
	cppVar_69614 = (cppVar_69614 & cppMask_un_8_);
	cppVar_69615 = IRAM.rd(cppVar_69614);
	cppVar_69603 = cppVar_69615;
	} else {
	cppVar_69617 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69618 = (cppVar_69617 << 3) | 7;
	cppVar_69618 = (cppVar_69618 & cppMask_un_5_);
	cppVar_69619 = (0 << 5) | cppVar_69618;
	cppVar_69619 = (cppVar_69619 & cppMask_un_8_);
	cppVar_69621 = (cppVar_69619 == 128);
	if (cppVar_69621) {
	cppVar_69616 = P0;
	} else {
	cppVar_69623 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69624 = (cppVar_69623 << 3) | 7;
	cppVar_69624 = (cppVar_69624 & cppMask_un_5_);
	cppVar_69625 = (0 << 5) | cppVar_69624;
	cppVar_69625 = (cppVar_69625 & cppMask_un_8_);
	cppVar_69627 = (cppVar_69625 == 129);
	if (cppVar_69627) {
	cppVar_69622 = SP;
	} else {
	cppVar_69629 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69630 = (cppVar_69629 << 3) | 7;
	cppVar_69630 = (cppVar_69630 & cppMask_un_5_);
	cppVar_69631 = (0 << 5) | cppVar_69630;
	cppVar_69631 = (cppVar_69631 & cppMask_un_8_);
	cppVar_69633 = (cppVar_69631 == 130);
	if (cppVar_69633) {
	cppVar_69628 = DPL;
	} else {
	cppVar_69635 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69636 = (cppVar_69635 << 3) | 7;
	cppVar_69636 = (cppVar_69636 & cppMask_un_5_);
	cppVar_69637 = (0 << 5) | cppVar_69636;
	cppVar_69637 = (cppVar_69637 & cppMask_un_8_);
	cppVar_69639 = (cppVar_69637 == 131);
	if (cppVar_69639) {
	cppVar_69634 = DPH;
	} else {
	cppVar_69641 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69642 = (cppVar_69641 << 3) | 7;
	cppVar_69642 = (cppVar_69642 & cppMask_un_5_);
	cppVar_69643 = (0 << 5) | cppVar_69642;
	cppVar_69643 = (cppVar_69643 & cppMask_un_8_);
	cppVar_69645 = (cppVar_69643 == 135);
	if (cppVar_69645) {
	cppVar_69640 = PCON;
	} else {
	cppVar_69647 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69648 = (cppVar_69647 << 3) | 7;
	cppVar_69648 = (cppVar_69648 & cppMask_un_5_);
	cppVar_69649 = (0 << 5) | cppVar_69648;
	cppVar_69649 = (cppVar_69649 & cppMask_un_8_);
	cppVar_69651 = (cppVar_69649 == 136);
	if (cppVar_69651) {
	cppVar_69646 = TCON;
	} else {
	cppVar_69653 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69654 = (cppVar_69653 << 3) | 7;
	cppVar_69654 = (cppVar_69654 & cppMask_un_5_);
	cppVar_69655 = (0 << 5) | cppVar_69654;
	cppVar_69655 = (cppVar_69655 & cppMask_un_8_);
	cppVar_69657 = (cppVar_69655 == 137);
	if (cppVar_69657) {
	cppVar_69652 = TMOD;
	} else {
	cppVar_69659 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69660 = (cppVar_69659 << 3) | 7;
	cppVar_69660 = (cppVar_69660 & cppMask_un_5_);
	cppVar_69661 = (0 << 5) | cppVar_69660;
	cppVar_69661 = (cppVar_69661 & cppMask_un_8_);
	cppVar_69663 = (cppVar_69661 == 138);
	if (cppVar_69663) {
	cppVar_69658 = TL0;
	} else {
	cppVar_69665 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69666 = (cppVar_69665 << 3) | 7;
	cppVar_69666 = (cppVar_69666 & cppMask_un_5_);
	cppVar_69667 = (0 << 5) | cppVar_69666;
	cppVar_69667 = (cppVar_69667 & cppMask_un_8_);
	cppVar_69669 = (cppVar_69667 == 140);
	if (cppVar_69669) {
	cppVar_69664 = TH0;
	} else {
	cppVar_69671 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69672 = (cppVar_69671 << 3) | 7;
	cppVar_69672 = (cppVar_69672 & cppMask_un_5_);
	cppVar_69673 = (0 << 5) | cppVar_69672;
	cppVar_69673 = (cppVar_69673 & cppMask_un_8_);
	cppVar_69675 = (cppVar_69673 == 139);
	if (cppVar_69675) {
	cppVar_69670 = TL1;
	} else {
	cppVar_69677 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69678 = (cppVar_69677 << 3) | 7;
	cppVar_69678 = (cppVar_69678 & cppMask_un_5_);
	cppVar_69679 = (0 << 5) | cppVar_69678;
	cppVar_69679 = (cppVar_69679 & cppMask_un_8_);
	cppVar_69681 = (cppVar_69679 == 141);
	if (cppVar_69681) {
	cppVar_69676 = TH1;
	} else {
	cppVar_69683 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69684 = (cppVar_69683 << 3) | 7;
	cppVar_69684 = (cppVar_69684 & cppMask_un_5_);
	cppVar_69685 = (0 << 5) | cppVar_69684;
	cppVar_69685 = (cppVar_69685 & cppMask_un_8_);
	cppVar_69687 = (cppVar_69685 == 144);
	if (cppVar_69687) {
	cppVar_69682 = P1;
	} else {
	cppVar_69689 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69690 = (cppVar_69689 << 3) | 7;
	cppVar_69690 = (cppVar_69690 & cppMask_un_5_);
	cppVar_69691 = (0 << 5) | cppVar_69690;
	cppVar_69691 = (cppVar_69691 & cppMask_un_8_);
	cppVar_69693 = (cppVar_69691 == 152);
	if (cppVar_69693) {
	cppVar_69688 = SCON;
	} else {
	cppVar_69695 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69696 = (cppVar_69695 << 3) | 7;
	cppVar_69696 = (cppVar_69696 & cppMask_un_5_);
	cppVar_69697 = (0 << 5) | cppVar_69696;
	cppVar_69697 = (cppVar_69697 & cppMask_un_8_);
	cppVar_69699 = (cppVar_69697 == 153);
	if (cppVar_69699) {
	cppVar_69694 = SBUF;
	} else {
	cppVar_69701 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69702 = (cppVar_69701 << 3) | 7;
	cppVar_69702 = (cppVar_69702 & cppMask_un_5_);
	cppVar_69703 = (0 << 5) | cppVar_69702;
	cppVar_69703 = (cppVar_69703 & cppMask_un_8_);
	cppVar_69705 = (cppVar_69703 == 160);
	if (cppVar_69705) {
	cppVar_69700 = P2;
	} else {
	cppVar_69707 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69708 = (cppVar_69707 << 3) | 7;
	cppVar_69708 = (cppVar_69708 & cppMask_un_5_);
	cppVar_69709 = (0 << 5) | cppVar_69708;
	cppVar_69709 = (cppVar_69709 & cppMask_un_8_);
	cppVar_69711 = (cppVar_69709 == 168);
	if (cppVar_69711) {
	cppVar_69706 = IE;
	} else {
	cppVar_69713 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69714 = (cppVar_69713 << 3) | 7;
	cppVar_69714 = (cppVar_69714 & cppMask_un_5_);
	cppVar_69715 = (0 << 5) | cppVar_69714;
	cppVar_69715 = (cppVar_69715 & cppMask_un_8_);
	cppVar_69717 = (cppVar_69715 == 176);
	if (cppVar_69717) {
	cppVar_69712 = P3;
	} else {
	cppVar_69719 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69720 = (cppVar_69719 << 3) | 7;
	cppVar_69720 = (cppVar_69720 & cppMask_un_5_);
	cppVar_69721 = (0 << 5) | cppVar_69720;
	cppVar_69721 = (cppVar_69721 & cppMask_un_8_);
	cppVar_69723 = (cppVar_69721 == 184);
	if (cppVar_69723) {
	cppVar_69718 = IP;
	} else {
	cppVar_69725 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69726 = (cppVar_69725 << 3) | 7;
	cppVar_69726 = (cppVar_69726 & cppMask_un_5_);
	cppVar_69727 = (0 << 5) | cppVar_69726;
	cppVar_69727 = (cppVar_69727 & cppMask_un_8_);
	cppVar_69729 = (cppVar_69727 == 208);
	if (cppVar_69729) {
	cppVar_69724 = PSW;
	} else {
	cppVar_69731 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69732 = (cppVar_69731 << 3) | 7;
	cppVar_69732 = (cppVar_69732 & cppMask_un_5_);
	cppVar_69733 = (0 << 5) | cppVar_69732;
	cppVar_69733 = (cppVar_69733 & cppMask_un_8_);
	cppVar_69735 = (cppVar_69733 == 224);
	if (cppVar_69735) {
	cppVar_69730 = ACC;
	} else {
	cppVar_69737 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69738 = (cppVar_69737 << 3) | 7;
	cppVar_69738 = (cppVar_69738 & cppMask_un_5_);
	cppVar_69739 = (0 << 5) | cppVar_69738;
	cppVar_69739 = (cppVar_69739 & cppMask_un_8_);
	cppVar_69741 = (cppVar_69739 == 240);
	if (cppVar_69741) {
	cppVar_69736 = B;
	} else {
	cppVar_69736 = 0;
	}
	cppVar_69730 = cppVar_69736;
	}
	cppVar_69724 = cppVar_69730;
	}
	cppVar_69718 = cppVar_69724;
	}
	cppVar_69712 = cppVar_69718;
	}
	cppVar_69706 = cppVar_69712;
	}
	cppVar_69700 = cppVar_69706;
	}
	cppVar_69694 = cppVar_69700;
	}
	cppVar_69688 = cppVar_69694;
	}
	cppVar_69682 = cppVar_69688;
	}
	cppVar_69676 = cppVar_69682;
	}
	cppVar_69670 = cppVar_69676;
	}
	cppVar_69664 = cppVar_69670;
	}
	cppVar_69658 = cppVar_69664;
	}
	cppVar_69652 = cppVar_69658;
	}
	cppVar_69646 = cppVar_69652;
	}
	cppVar_69640 = cppVar_69646;
	}
	cppVar_69634 = cppVar_69640;
	}
	cppVar_69628 = cppVar_69634;
	}
	cppVar_69622 = cppVar_69628;
	}
	cppVar_69616 = cppVar_69622;
	}
	cppVar_69603 = cppVar_69616;
	}
	cppVar_69597 = cppVar_69603;
	} else {
	cppVar_69597 = TCON;
	}
	cppVar_69593 = cppVar_69597;
	} else {
	cppVar_69744 = ROM.rd(PC);
	cppVar_69746 = (cppVar_69744 == 142);
	if (cppVar_69746) {
	cppVar_69749 = PC + 1;
	cppVar_69749 = (cppVar_69749 & cppMask_un_16_);
	cppVar_69750 = ROM.rd(cppVar_69749);
	cppVar_69752 = (cppVar_69750 == 136);
	if (cppVar_69752) {
	cppVar_69755 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69757 = (cppVar_69755 << 3) | 6;
	cppVar_69757 = (cppVar_69757 & cppMask_un_5_);
	cppVar_69758 = (0 << 5) | cppVar_69757;
	cppVar_69758 = (cppVar_69758 & cppMask_un_8_);
	cppVar_69759 = (cppVar_69758 >> 7) & cppMask_un_1_;
	cppVar_69761 = (cppVar_69759 == 0);
	if (cppVar_69761) {
	cppVar_69762 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69763 = (cppVar_69762 << 3) | 6;
	cppVar_69763 = (cppVar_69763 & cppMask_un_5_);
	cppVar_69764 = (0 << 5) | cppVar_69763;
	cppVar_69764 = (cppVar_69764 & cppMask_un_8_);
	cppVar_69765 = IRAM.rd(cppVar_69764);
	cppVar_69753 = cppVar_69765;
	} else {
	cppVar_69767 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69768 = (cppVar_69767 << 3) | 6;
	cppVar_69768 = (cppVar_69768 & cppMask_un_5_);
	cppVar_69769 = (0 << 5) | cppVar_69768;
	cppVar_69769 = (cppVar_69769 & cppMask_un_8_);
	cppVar_69771 = (cppVar_69769 == 128);
	if (cppVar_69771) {
	cppVar_69766 = P0;
	} else {
	cppVar_69773 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69774 = (cppVar_69773 << 3) | 6;
	cppVar_69774 = (cppVar_69774 & cppMask_un_5_);
	cppVar_69775 = (0 << 5) | cppVar_69774;
	cppVar_69775 = (cppVar_69775 & cppMask_un_8_);
	cppVar_69777 = (cppVar_69775 == 129);
	if (cppVar_69777) {
	cppVar_69772 = SP;
	} else {
	cppVar_69779 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69780 = (cppVar_69779 << 3) | 6;
	cppVar_69780 = (cppVar_69780 & cppMask_un_5_);
	cppVar_69781 = (0 << 5) | cppVar_69780;
	cppVar_69781 = (cppVar_69781 & cppMask_un_8_);
	cppVar_69783 = (cppVar_69781 == 130);
	if (cppVar_69783) {
	cppVar_69778 = DPL;
	} else {
	cppVar_69785 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69786 = (cppVar_69785 << 3) | 6;
	cppVar_69786 = (cppVar_69786 & cppMask_un_5_);
	cppVar_69787 = (0 << 5) | cppVar_69786;
	cppVar_69787 = (cppVar_69787 & cppMask_un_8_);
	cppVar_69789 = (cppVar_69787 == 131);
	if (cppVar_69789) {
	cppVar_69784 = DPH;
	} else {
	cppVar_69791 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69792 = (cppVar_69791 << 3) | 6;
	cppVar_69792 = (cppVar_69792 & cppMask_un_5_);
	cppVar_69793 = (0 << 5) | cppVar_69792;
	cppVar_69793 = (cppVar_69793 & cppMask_un_8_);
	cppVar_69795 = (cppVar_69793 == 135);
	if (cppVar_69795) {
	cppVar_69790 = PCON;
	} else {
	cppVar_69797 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69798 = (cppVar_69797 << 3) | 6;
	cppVar_69798 = (cppVar_69798 & cppMask_un_5_);
	cppVar_69799 = (0 << 5) | cppVar_69798;
	cppVar_69799 = (cppVar_69799 & cppMask_un_8_);
	cppVar_69801 = (cppVar_69799 == 136);
	if (cppVar_69801) {
	cppVar_69796 = TCON;
	} else {
	cppVar_69803 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69804 = (cppVar_69803 << 3) | 6;
	cppVar_69804 = (cppVar_69804 & cppMask_un_5_);
	cppVar_69805 = (0 << 5) | cppVar_69804;
	cppVar_69805 = (cppVar_69805 & cppMask_un_8_);
	cppVar_69807 = (cppVar_69805 == 137);
	if (cppVar_69807) {
	cppVar_69802 = TMOD;
	} else {
	cppVar_69809 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69810 = (cppVar_69809 << 3) | 6;
	cppVar_69810 = (cppVar_69810 & cppMask_un_5_);
	cppVar_69811 = (0 << 5) | cppVar_69810;
	cppVar_69811 = (cppVar_69811 & cppMask_un_8_);
	cppVar_69813 = (cppVar_69811 == 138);
	if (cppVar_69813) {
	cppVar_69808 = TL0;
	} else {
	cppVar_69815 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69816 = (cppVar_69815 << 3) | 6;
	cppVar_69816 = (cppVar_69816 & cppMask_un_5_);
	cppVar_69817 = (0 << 5) | cppVar_69816;
	cppVar_69817 = (cppVar_69817 & cppMask_un_8_);
	cppVar_69819 = (cppVar_69817 == 140);
	if (cppVar_69819) {
	cppVar_69814 = TH0;
	} else {
	cppVar_69821 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69822 = (cppVar_69821 << 3) | 6;
	cppVar_69822 = (cppVar_69822 & cppMask_un_5_);
	cppVar_69823 = (0 << 5) | cppVar_69822;
	cppVar_69823 = (cppVar_69823 & cppMask_un_8_);
	cppVar_69825 = (cppVar_69823 == 139);
	if (cppVar_69825) {
	cppVar_69820 = TL1;
	} else {
	cppVar_69827 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69828 = (cppVar_69827 << 3) | 6;
	cppVar_69828 = (cppVar_69828 & cppMask_un_5_);
	cppVar_69829 = (0 << 5) | cppVar_69828;
	cppVar_69829 = (cppVar_69829 & cppMask_un_8_);
	cppVar_69831 = (cppVar_69829 == 141);
	if (cppVar_69831) {
	cppVar_69826 = TH1;
	} else {
	cppVar_69833 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69834 = (cppVar_69833 << 3) | 6;
	cppVar_69834 = (cppVar_69834 & cppMask_un_5_);
	cppVar_69835 = (0 << 5) | cppVar_69834;
	cppVar_69835 = (cppVar_69835 & cppMask_un_8_);
	cppVar_69837 = (cppVar_69835 == 144);
	if (cppVar_69837) {
	cppVar_69832 = P1;
	} else {
	cppVar_69839 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69840 = (cppVar_69839 << 3) | 6;
	cppVar_69840 = (cppVar_69840 & cppMask_un_5_);
	cppVar_69841 = (0 << 5) | cppVar_69840;
	cppVar_69841 = (cppVar_69841 & cppMask_un_8_);
	cppVar_69843 = (cppVar_69841 == 152);
	if (cppVar_69843) {
	cppVar_69838 = SCON;
	} else {
	cppVar_69845 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69846 = (cppVar_69845 << 3) | 6;
	cppVar_69846 = (cppVar_69846 & cppMask_un_5_);
	cppVar_69847 = (0 << 5) | cppVar_69846;
	cppVar_69847 = (cppVar_69847 & cppMask_un_8_);
	cppVar_69849 = (cppVar_69847 == 153);
	if (cppVar_69849) {
	cppVar_69844 = SBUF;
	} else {
	cppVar_69851 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69852 = (cppVar_69851 << 3) | 6;
	cppVar_69852 = (cppVar_69852 & cppMask_un_5_);
	cppVar_69853 = (0 << 5) | cppVar_69852;
	cppVar_69853 = (cppVar_69853 & cppMask_un_8_);
	cppVar_69855 = (cppVar_69853 == 160);
	if (cppVar_69855) {
	cppVar_69850 = P2;
	} else {
	cppVar_69857 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69858 = (cppVar_69857 << 3) | 6;
	cppVar_69858 = (cppVar_69858 & cppMask_un_5_);
	cppVar_69859 = (0 << 5) | cppVar_69858;
	cppVar_69859 = (cppVar_69859 & cppMask_un_8_);
	cppVar_69861 = (cppVar_69859 == 168);
	if (cppVar_69861) {
	cppVar_69856 = IE;
	} else {
	cppVar_69863 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69864 = (cppVar_69863 << 3) | 6;
	cppVar_69864 = (cppVar_69864 & cppMask_un_5_);
	cppVar_69865 = (0 << 5) | cppVar_69864;
	cppVar_69865 = (cppVar_69865 & cppMask_un_8_);
	cppVar_69867 = (cppVar_69865 == 176);
	if (cppVar_69867) {
	cppVar_69862 = P3;
	} else {
	cppVar_69869 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69870 = (cppVar_69869 << 3) | 6;
	cppVar_69870 = (cppVar_69870 & cppMask_un_5_);
	cppVar_69871 = (0 << 5) | cppVar_69870;
	cppVar_69871 = (cppVar_69871 & cppMask_un_8_);
	cppVar_69873 = (cppVar_69871 == 184);
	if (cppVar_69873) {
	cppVar_69868 = IP;
	} else {
	cppVar_69875 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69876 = (cppVar_69875 << 3) | 6;
	cppVar_69876 = (cppVar_69876 & cppMask_un_5_);
	cppVar_69877 = (0 << 5) | cppVar_69876;
	cppVar_69877 = (cppVar_69877 & cppMask_un_8_);
	cppVar_69879 = (cppVar_69877 == 208);
	if (cppVar_69879) {
	cppVar_69874 = PSW;
	} else {
	cppVar_69881 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69882 = (cppVar_69881 << 3) | 6;
	cppVar_69882 = (cppVar_69882 & cppMask_un_5_);
	cppVar_69883 = (0 << 5) | cppVar_69882;
	cppVar_69883 = (cppVar_69883 & cppMask_un_8_);
	cppVar_69885 = (cppVar_69883 == 224);
	if (cppVar_69885) {
	cppVar_69880 = ACC;
	} else {
	cppVar_69887 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69888 = (cppVar_69887 << 3) | 6;
	cppVar_69888 = (cppVar_69888 & cppMask_un_5_);
	cppVar_69889 = (0 << 5) | cppVar_69888;
	cppVar_69889 = (cppVar_69889 & cppMask_un_8_);
	cppVar_69891 = (cppVar_69889 == 240);
	if (cppVar_69891) {
	cppVar_69886 = B;
	} else {
	cppVar_69886 = 0;
	}
	cppVar_69880 = cppVar_69886;
	}
	cppVar_69874 = cppVar_69880;
	}
	cppVar_69868 = cppVar_69874;
	}
	cppVar_69862 = cppVar_69868;
	}
	cppVar_69856 = cppVar_69862;
	}
	cppVar_69850 = cppVar_69856;
	}
	cppVar_69844 = cppVar_69850;
	}
	cppVar_69838 = cppVar_69844;
	}
	cppVar_69832 = cppVar_69838;
	}
	cppVar_69826 = cppVar_69832;
	}
	cppVar_69820 = cppVar_69826;
	}
	cppVar_69814 = cppVar_69820;
	}
	cppVar_69808 = cppVar_69814;
	}
	cppVar_69802 = cppVar_69808;
	}
	cppVar_69796 = cppVar_69802;
	}
	cppVar_69790 = cppVar_69796;
	}
	cppVar_69784 = cppVar_69790;
	}
	cppVar_69778 = cppVar_69784;
	}
	cppVar_69772 = cppVar_69778;
	}
	cppVar_69766 = cppVar_69772;
	}
	cppVar_69753 = cppVar_69766;
	}
	cppVar_69747 = cppVar_69753;
	} else {
	cppVar_69747 = TCON;
	}
	cppVar_69743 = cppVar_69747;
	} else {
	cppVar_69894 = ROM.rd(PC);
	cppVar_69896 = (cppVar_69894 == 141);
	if (cppVar_69896) {
	cppVar_69899 = PC + 1;
	cppVar_69899 = (cppVar_69899 & cppMask_un_16_);
	cppVar_69900 = ROM.rd(cppVar_69899);
	cppVar_69902 = (cppVar_69900 == 136);
	if (cppVar_69902) {
	cppVar_69905 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69907 = (cppVar_69905 << 3) | 5;
	cppVar_69907 = (cppVar_69907 & cppMask_un_5_);
	cppVar_69908 = (0 << 5) | cppVar_69907;
	cppVar_69908 = (cppVar_69908 & cppMask_un_8_);
	cppVar_69909 = (cppVar_69908 >> 7) & cppMask_un_1_;
	cppVar_69911 = (cppVar_69909 == 0);
	if (cppVar_69911) {
	cppVar_69912 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69913 = (cppVar_69912 << 3) | 5;
	cppVar_69913 = (cppVar_69913 & cppMask_un_5_);
	cppVar_69914 = (0 << 5) | cppVar_69913;
	cppVar_69914 = (cppVar_69914 & cppMask_un_8_);
	cppVar_69915 = IRAM.rd(cppVar_69914);
	cppVar_69903 = cppVar_69915;
	} else {
	cppVar_69917 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69918 = (cppVar_69917 << 3) | 5;
	cppVar_69918 = (cppVar_69918 & cppMask_un_5_);
	cppVar_69919 = (0 << 5) | cppVar_69918;
	cppVar_69919 = (cppVar_69919 & cppMask_un_8_);
	cppVar_69921 = (cppVar_69919 == 128);
	if (cppVar_69921) {
	cppVar_69916 = P0;
	} else {
	cppVar_69923 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69924 = (cppVar_69923 << 3) | 5;
	cppVar_69924 = (cppVar_69924 & cppMask_un_5_);
	cppVar_69925 = (0 << 5) | cppVar_69924;
	cppVar_69925 = (cppVar_69925 & cppMask_un_8_);
	cppVar_69927 = (cppVar_69925 == 129);
	if (cppVar_69927) {
	cppVar_69922 = SP;
	} else {
	cppVar_69929 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69930 = (cppVar_69929 << 3) | 5;
	cppVar_69930 = (cppVar_69930 & cppMask_un_5_);
	cppVar_69931 = (0 << 5) | cppVar_69930;
	cppVar_69931 = (cppVar_69931 & cppMask_un_8_);
	cppVar_69933 = (cppVar_69931 == 130);
	if (cppVar_69933) {
	cppVar_69928 = DPL;
	} else {
	cppVar_69935 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69936 = (cppVar_69935 << 3) | 5;
	cppVar_69936 = (cppVar_69936 & cppMask_un_5_);
	cppVar_69937 = (0 << 5) | cppVar_69936;
	cppVar_69937 = (cppVar_69937 & cppMask_un_8_);
	cppVar_69939 = (cppVar_69937 == 131);
	if (cppVar_69939) {
	cppVar_69934 = DPH;
	} else {
	cppVar_69941 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69942 = (cppVar_69941 << 3) | 5;
	cppVar_69942 = (cppVar_69942 & cppMask_un_5_);
	cppVar_69943 = (0 << 5) | cppVar_69942;
	cppVar_69943 = (cppVar_69943 & cppMask_un_8_);
	cppVar_69945 = (cppVar_69943 == 135);
	if (cppVar_69945) {
	cppVar_69940 = PCON;
	} else {
	cppVar_69947 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69948 = (cppVar_69947 << 3) | 5;
	cppVar_69948 = (cppVar_69948 & cppMask_un_5_);
	cppVar_69949 = (0 << 5) | cppVar_69948;
	cppVar_69949 = (cppVar_69949 & cppMask_un_8_);
	cppVar_69951 = (cppVar_69949 == 136);
	if (cppVar_69951) {
	cppVar_69946 = TCON;
	} else {
	cppVar_69953 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69954 = (cppVar_69953 << 3) | 5;
	cppVar_69954 = (cppVar_69954 & cppMask_un_5_);
	cppVar_69955 = (0 << 5) | cppVar_69954;
	cppVar_69955 = (cppVar_69955 & cppMask_un_8_);
	cppVar_69957 = (cppVar_69955 == 137);
	if (cppVar_69957) {
	cppVar_69952 = TMOD;
	} else {
	cppVar_69959 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69960 = (cppVar_69959 << 3) | 5;
	cppVar_69960 = (cppVar_69960 & cppMask_un_5_);
	cppVar_69961 = (0 << 5) | cppVar_69960;
	cppVar_69961 = (cppVar_69961 & cppMask_un_8_);
	cppVar_69963 = (cppVar_69961 == 138);
	if (cppVar_69963) {
	cppVar_69958 = TL0;
	} else {
	cppVar_69965 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69966 = (cppVar_69965 << 3) | 5;
	cppVar_69966 = (cppVar_69966 & cppMask_un_5_);
	cppVar_69967 = (0 << 5) | cppVar_69966;
	cppVar_69967 = (cppVar_69967 & cppMask_un_8_);
	cppVar_69969 = (cppVar_69967 == 140);
	if (cppVar_69969) {
	cppVar_69964 = TH0;
	} else {
	cppVar_69971 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69972 = (cppVar_69971 << 3) | 5;
	cppVar_69972 = (cppVar_69972 & cppMask_un_5_);
	cppVar_69973 = (0 << 5) | cppVar_69972;
	cppVar_69973 = (cppVar_69973 & cppMask_un_8_);
	cppVar_69975 = (cppVar_69973 == 139);
	if (cppVar_69975) {
	cppVar_69970 = TL1;
	} else {
	cppVar_69977 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69978 = (cppVar_69977 << 3) | 5;
	cppVar_69978 = (cppVar_69978 & cppMask_un_5_);
	cppVar_69979 = (0 << 5) | cppVar_69978;
	cppVar_69979 = (cppVar_69979 & cppMask_un_8_);
	cppVar_69981 = (cppVar_69979 == 141);
	if (cppVar_69981) {
	cppVar_69976 = TH1;
	} else {
	cppVar_69983 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69984 = (cppVar_69983 << 3) | 5;
	cppVar_69984 = (cppVar_69984 & cppMask_un_5_);
	cppVar_69985 = (0 << 5) | cppVar_69984;
	cppVar_69985 = (cppVar_69985 & cppMask_un_8_);
	cppVar_69987 = (cppVar_69985 == 144);
	if (cppVar_69987) {
	cppVar_69982 = P1;
	} else {
	cppVar_69989 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69990 = (cppVar_69989 << 3) | 5;
	cppVar_69990 = (cppVar_69990 & cppMask_un_5_);
	cppVar_69991 = (0 << 5) | cppVar_69990;
	cppVar_69991 = (cppVar_69991 & cppMask_un_8_);
	cppVar_69993 = (cppVar_69991 == 152);
	if (cppVar_69993) {
	cppVar_69988 = SCON;
	} else {
	cppVar_69995 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69996 = (cppVar_69995 << 3) | 5;
	cppVar_69996 = (cppVar_69996 & cppMask_un_5_);
	cppVar_69997 = (0 << 5) | cppVar_69996;
	cppVar_69997 = (cppVar_69997 & cppMask_un_8_);
	cppVar_69999 = (cppVar_69997 == 153);
	if (cppVar_69999) {
	cppVar_69994 = SBUF;
	} else {
	cppVar_70001 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70002 = (cppVar_70001 << 3) | 5;
	cppVar_70002 = (cppVar_70002 & cppMask_un_5_);
	cppVar_70003 = (0 << 5) | cppVar_70002;
	cppVar_70003 = (cppVar_70003 & cppMask_un_8_);
	cppVar_70005 = (cppVar_70003 == 160);
	if (cppVar_70005) {
	cppVar_70000 = P2;
	} else {
	cppVar_70007 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70008 = (cppVar_70007 << 3) | 5;
	cppVar_70008 = (cppVar_70008 & cppMask_un_5_);
	cppVar_70009 = (0 << 5) | cppVar_70008;
	cppVar_70009 = (cppVar_70009 & cppMask_un_8_);
	cppVar_70011 = (cppVar_70009 == 168);
	if (cppVar_70011) {
	cppVar_70006 = IE;
	} else {
	cppVar_70013 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70014 = (cppVar_70013 << 3) | 5;
	cppVar_70014 = (cppVar_70014 & cppMask_un_5_);
	cppVar_70015 = (0 << 5) | cppVar_70014;
	cppVar_70015 = (cppVar_70015 & cppMask_un_8_);
	cppVar_70017 = (cppVar_70015 == 176);
	if (cppVar_70017) {
	cppVar_70012 = P3;
	} else {
	cppVar_70019 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70020 = (cppVar_70019 << 3) | 5;
	cppVar_70020 = (cppVar_70020 & cppMask_un_5_);
	cppVar_70021 = (0 << 5) | cppVar_70020;
	cppVar_70021 = (cppVar_70021 & cppMask_un_8_);
	cppVar_70023 = (cppVar_70021 == 184);
	if (cppVar_70023) {
	cppVar_70018 = IP;
	} else {
	cppVar_70025 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70026 = (cppVar_70025 << 3) | 5;
	cppVar_70026 = (cppVar_70026 & cppMask_un_5_);
	cppVar_70027 = (0 << 5) | cppVar_70026;
	cppVar_70027 = (cppVar_70027 & cppMask_un_8_);
	cppVar_70029 = (cppVar_70027 == 208);
	if (cppVar_70029) {
	cppVar_70024 = PSW;
	} else {
	cppVar_70031 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70032 = (cppVar_70031 << 3) | 5;
	cppVar_70032 = (cppVar_70032 & cppMask_un_5_);
	cppVar_70033 = (0 << 5) | cppVar_70032;
	cppVar_70033 = (cppVar_70033 & cppMask_un_8_);
	cppVar_70035 = (cppVar_70033 == 224);
	if (cppVar_70035) {
	cppVar_70030 = ACC;
	} else {
	cppVar_70037 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70038 = (cppVar_70037 << 3) | 5;
	cppVar_70038 = (cppVar_70038 & cppMask_un_5_);
	cppVar_70039 = (0 << 5) | cppVar_70038;
	cppVar_70039 = (cppVar_70039 & cppMask_un_8_);
	cppVar_70041 = (cppVar_70039 == 240);
	if (cppVar_70041) {
	cppVar_70036 = B;
	} else {
	cppVar_70036 = 0;
	}
	cppVar_70030 = cppVar_70036;
	}
	cppVar_70024 = cppVar_70030;
	}
	cppVar_70018 = cppVar_70024;
	}
	cppVar_70012 = cppVar_70018;
	}
	cppVar_70006 = cppVar_70012;
	}
	cppVar_70000 = cppVar_70006;
	}
	cppVar_69994 = cppVar_70000;
	}
	cppVar_69988 = cppVar_69994;
	}
	cppVar_69982 = cppVar_69988;
	}
	cppVar_69976 = cppVar_69982;
	}
	cppVar_69970 = cppVar_69976;
	}
	cppVar_69964 = cppVar_69970;
	}
	cppVar_69958 = cppVar_69964;
	}
	cppVar_69952 = cppVar_69958;
	}
	cppVar_69946 = cppVar_69952;
	}
	cppVar_69940 = cppVar_69946;
	}
	cppVar_69934 = cppVar_69940;
	}
	cppVar_69928 = cppVar_69934;
	}
	cppVar_69922 = cppVar_69928;
	}
	cppVar_69916 = cppVar_69922;
	}
	cppVar_69903 = cppVar_69916;
	}
	cppVar_69897 = cppVar_69903;
	} else {
	cppVar_69897 = TCON;
	}
	cppVar_69893 = cppVar_69897;
	} else {
	cppVar_70044 = ROM.rd(PC);
	cppVar_70046 = (cppVar_70044 == 140);
	if (cppVar_70046) {
	cppVar_70049 = PC + 1;
	cppVar_70049 = (cppVar_70049 & cppMask_un_16_);
	cppVar_70050 = ROM.rd(cppVar_70049);
	cppVar_70052 = (cppVar_70050 == 136);
	if (cppVar_70052) {
	cppVar_70055 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70057 = (cppVar_70055 << 3) | 4;
	cppVar_70057 = (cppVar_70057 & cppMask_un_5_);
	cppVar_70058 = (0 << 5) | cppVar_70057;
	cppVar_70058 = (cppVar_70058 & cppMask_un_8_);
	cppVar_70059 = (cppVar_70058 >> 7) & cppMask_un_1_;
	cppVar_70061 = (cppVar_70059 == 0);
	if (cppVar_70061) {
	cppVar_70062 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70063 = (cppVar_70062 << 3) | 4;
	cppVar_70063 = (cppVar_70063 & cppMask_un_5_);
	cppVar_70064 = (0 << 5) | cppVar_70063;
	cppVar_70064 = (cppVar_70064 & cppMask_un_8_);
	cppVar_70065 = IRAM.rd(cppVar_70064);
	cppVar_70053 = cppVar_70065;
	} else {
	cppVar_70067 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70068 = (cppVar_70067 << 3) | 4;
	cppVar_70068 = (cppVar_70068 & cppMask_un_5_);
	cppVar_70069 = (0 << 5) | cppVar_70068;
	cppVar_70069 = (cppVar_70069 & cppMask_un_8_);
	cppVar_70071 = (cppVar_70069 == 128);
	if (cppVar_70071) {
	cppVar_70066 = P0;
	} else {
	cppVar_70073 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70074 = (cppVar_70073 << 3) | 4;
	cppVar_70074 = (cppVar_70074 & cppMask_un_5_);
	cppVar_70075 = (0 << 5) | cppVar_70074;
	cppVar_70075 = (cppVar_70075 & cppMask_un_8_);
	cppVar_70077 = (cppVar_70075 == 129);
	if (cppVar_70077) {
	cppVar_70072 = SP;
	} else {
	cppVar_70079 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70080 = (cppVar_70079 << 3) | 4;
	cppVar_70080 = (cppVar_70080 & cppMask_un_5_);
	cppVar_70081 = (0 << 5) | cppVar_70080;
	cppVar_70081 = (cppVar_70081 & cppMask_un_8_);
	cppVar_70083 = (cppVar_70081 == 130);
	if (cppVar_70083) {
	cppVar_70078 = DPL;
	} else {
	cppVar_70085 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70086 = (cppVar_70085 << 3) | 4;
	cppVar_70086 = (cppVar_70086 & cppMask_un_5_);
	cppVar_70087 = (0 << 5) | cppVar_70086;
	cppVar_70087 = (cppVar_70087 & cppMask_un_8_);
	cppVar_70089 = (cppVar_70087 == 131);
	if (cppVar_70089) {
	cppVar_70084 = DPH;
	} else {
	cppVar_70091 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70092 = (cppVar_70091 << 3) | 4;
	cppVar_70092 = (cppVar_70092 & cppMask_un_5_);
	cppVar_70093 = (0 << 5) | cppVar_70092;
	cppVar_70093 = (cppVar_70093 & cppMask_un_8_);
	cppVar_70095 = (cppVar_70093 == 135);
	if (cppVar_70095) {
	cppVar_70090 = PCON;
	} else {
	cppVar_70097 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70098 = (cppVar_70097 << 3) | 4;
	cppVar_70098 = (cppVar_70098 & cppMask_un_5_);
	cppVar_70099 = (0 << 5) | cppVar_70098;
	cppVar_70099 = (cppVar_70099 & cppMask_un_8_);
	cppVar_70101 = (cppVar_70099 == 136);
	if (cppVar_70101) {
	cppVar_70096 = TCON;
	} else {
	cppVar_70103 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70104 = (cppVar_70103 << 3) | 4;
	cppVar_70104 = (cppVar_70104 & cppMask_un_5_);
	cppVar_70105 = (0 << 5) | cppVar_70104;
	cppVar_70105 = (cppVar_70105 & cppMask_un_8_);
	cppVar_70107 = (cppVar_70105 == 137);
	if (cppVar_70107) {
	cppVar_70102 = TMOD;
	} else {
	cppVar_70109 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70110 = (cppVar_70109 << 3) | 4;
	cppVar_70110 = (cppVar_70110 & cppMask_un_5_);
	cppVar_70111 = (0 << 5) | cppVar_70110;
	cppVar_70111 = (cppVar_70111 & cppMask_un_8_);
	cppVar_70113 = (cppVar_70111 == 138);
	if (cppVar_70113) {
	cppVar_70108 = TL0;
	} else {
	cppVar_70115 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70116 = (cppVar_70115 << 3) | 4;
	cppVar_70116 = (cppVar_70116 & cppMask_un_5_);
	cppVar_70117 = (0 << 5) | cppVar_70116;
	cppVar_70117 = (cppVar_70117 & cppMask_un_8_);
	cppVar_70119 = (cppVar_70117 == 140);
	if (cppVar_70119) {
	cppVar_70114 = TH0;
	} else {
	cppVar_70121 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70122 = (cppVar_70121 << 3) | 4;
	cppVar_70122 = (cppVar_70122 & cppMask_un_5_);
	cppVar_70123 = (0 << 5) | cppVar_70122;
	cppVar_70123 = (cppVar_70123 & cppMask_un_8_);
	cppVar_70125 = (cppVar_70123 == 139);
	if (cppVar_70125) {
	cppVar_70120 = TL1;
	} else {
	cppVar_70127 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70128 = (cppVar_70127 << 3) | 4;
	cppVar_70128 = (cppVar_70128 & cppMask_un_5_);
	cppVar_70129 = (0 << 5) | cppVar_70128;
	cppVar_70129 = (cppVar_70129 & cppMask_un_8_);
	cppVar_70131 = (cppVar_70129 == 141);
	if (cppVar_70131) {
	cppVar_70126 = TH1;
	} else {
	cppVar_70133 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70134 = (cppVar_70133 << 3) | 4;
	cppVar_70134 = (cppVar_70134 & cppMask_un_5_);
	cppVar_70135 = (0 << 5) | cppVar_70134;
	cppVar_70135 = (cppVar_70135 & cppMask_un_8_);
	cppVar_70137 = (cppVar_70135 == 144);
	if (cppVar_70137) {
	cppVar_70132 = P1;
	} else {
	cppVar_70139 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70140 = (cppVar_70139 << 3) | 4;
	cppVar_70140 = (cppVar_70140 & cppMask_un_5_);
	cppVar_70141 = (0 << 5) | cppVar_70140;
	cppVar_70141 = (cppVar_70141 & cppMask_un_8_);
	cppVar_70143 = (cppVar_70141 == 152);
	if (cppVar_70143) {
	cppVar_70138 = SCON;
	} else {
	cppVar_70145 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70146 = (cppVar_70145 << 3) | 4;
	cppVar_70146 = (cppVar_70146 & cppMask_un_5_);
	cppVar_70147 = (0 << 5) | cppVar_70146;
	cppVar_70147 = (cppVar_70147 & cppMask_un_8_);
	cppVar_70149 = (cppVar_70147 == 153);
	if (cppVar_70149) {
	cppVar_70144 = SBUF;
	} else {
	cppVar_70151 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70152 = (cppVar_70151 << 3) | 4;
	cppVar_70152 = (cppVar_70152 & cppMask_un_5_);
	cppVar_70153 = (0 << 5) | cppVar_70152;
	cppVar_70153 = (cppVar_70153 & cppMask_un_8_);
	cppVar_70155 = (cppVar_70153 == 160);
	if (cppVar_70155) {
	cppVar_70150 = P2;
	} else {
	cppVar_70157 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70158 = (cppVar_70157 << 3) | 4;
	cppVar_70158 = (cppVar_70158 & cppMask_un_5_);
	cppVar_70159 = (0 << 5) | cppVar_70158;
	cppVar_70159 = (cppVar_70159 & cppMask_un_8_);
	cppVar_70161 = (cppVar_70159 == 168);
	if (cppVar_70161) {
	cppVar_70156 = IE;
	} else {
	cppVar_70163 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70164 = (cppVar_70163 << 3) | 4;
	cppVar_70164 = (cppVar_70164 & cppMask_un_5_);
	cppVar_70165 = (0 << 5) | cppVar_70164;
	cppVar_70165 = (cppVar_70165 & cppMask_un_8_);
	cppVar_70167 = (cppVar_70165 == 176);
	if (cppVar_70167) {
	cppVar_70162 = P3;
	} else {
	cppVar_70169 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70170 = (cppVar_70169 << 3) | 4;
	cppVar_70170 = (cppVar_70170 & cppMask_un_5_);
	cppVar_70171 = (0 << 5) | cppVar_70170;
	cppVar_70171 = (cppVar_70171 & cppMask_un_8_);
	cppVar_70173 = (cppVar_70171 == 184);
	if (cppVar_70173) {
	cppVar_70168 = IP;
	} else {
	cppVar_70175 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70176 = (cppVar_70175 << 3) | 4;
	cppVar_70176 = (cppVar_70176 & cppMask_un_5_);
	cppVar_70177 = (0 << 5) | cppVar_70176;
	cppVar_70177 = (cppVar_70177 & cppMask_un_8_);
	cppVar_70179 = (cppVar_70177 == 208);
	if (cppVar_70179) {
	cppVar_70174 = PSW;
	} else {
	cppVar_70181 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70182 = (cppVar_70181 << 3) | 4;
	cppVar_70182 = (cppVar_70182 & cppMask_un_5_);
	cppVar_70183 = (0 << 5) | cppVar_70182;
	cppVar_70183 = (cppVar_70183 & cppMask_un_8_);
	cppVar_70185 = (cppVar_70183 == 224);
	if (cppVar_70185) {
	cppVar_70180 = ACC;
	} else {
	cppVar_70187 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70188 = (cppVar_70187 << 3) | 4;
	cppVar_70188 = (cppVar_70188 & cppMask_un_5_);
	cppVar_70189 = (0 << 5) | cppVar_70188;
	cppVar_70189 = (cppVar_70189 & cppMask_un_8_);
	cppVar_70191 = (cppVar_70189 == 240);
	if (cppVar_70191) {
	cppVar_70186 = B;
	} else {
	cppVar_70186 = 0;
	}
	cppVar_70180 = cppVar_70186;
	}
	cppVar_70174 = cppVar_70180;
	}
	cppVar_70168 = cppVar_70174;
	}
	cppVar_70162 = cppVar_70168;
	}
	cppVar_70156 = cppVar_70162;
	}
	cppVar_70150 = cppVar_70156;
	}
	cppVar_70144 = cppVar_70150;
	}
	cppVar_70138 = cppVar_70144;
	}
	cppVar_70132 = cppVar_70138;
	}
	cppVar_70126 = cppVar_70132;
	}
	cppVar_70120 = cppVar_70126;
	}
	cppVar_70114 = cppVar_70120;
	}
	cppVar_70108 = cppVar_70114;
	}
	cppVar_70102 = cppVar_70108;
	}
	cppVar_70096 = cppVar_70102;
	}
	cppVar_70090 = cppVar_70096;
	}
	cppVar_70084 = cppVar_70090;
	}
	cppVar_70078 = cppVar_70084;
	}
	cppVar_70072 = cppVar_70078;
	}
	cppVar_70066 = cppVar_70072;
	}
	cppVar_70053 = cppVar_70066;
	}
	cppVar_70047 = cppVar_70053;
	} else {
	cppVar_70047 = TCON;
	}
	cppVar_70043 = cppVar_70047;
	} else {
	cppVar_70194 = ROM.rd(PC);
	cppVar_70196 = (cppVar_70194 == 139);
	if (cppVar_70196) {
	cppVar_70199 = PC + 1;
	cppVar_70199 = (cppVar_70199 & cppMask_un_16_);
	cppVar_70200 = ROM.rd(cppVar_70199);
	cppVar_70202 = (cppVar_70200 == 136);
	if (cppVar_70202) {
	cppVar_70205 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70207 = (cppVar_70205 << 3) | 3;
	cppVar_70207 = (cppVar_70207 & cppMask_un_5_);
	cppVar_70208 = (0 << 5) | cppVar_70207;
	cppVar_70208 = (cppVar_70208 & cppMask_un_8_);
	cppVar_70209 = (cppVar_70208 >> 7) & cppMask_un_1_;
	cppVar_70211 = (cppVar_70209 == 0);
	if (cppVar_70211) {
	cppVar_70212 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70213 = (cppVar_70212 << 3) | 3;
	cppVar_70213 = (cppVar_70213 & cppMask_un_5_);
	cppVar_70214 = (0 << 5) | cppVar_70213;
	cppVar_70214 = (cppVar_70214 & cppMask_un_8_);
	cppVar_70215 = IRAM.rd(cppVar_70214);
	cppVar_70203 = cppVar_70215;
	} else {
	cppVar_70217 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70218 = (cppVar_70217 << 3) | 3;
	cppVar_70218 = (cppVar_70218 & cppMask_un_5_);
	cppVar_70219 = (0 << 5) | cppVar_70218;
	cppVar_70219 = (cppVar_70219 & cppMask_un_8_);
	cppVar_70221 = (cppVar_70219 == 128);
	if (cppVar_70221) {
	cppVar_70216 = P0;
	} else {
	cppVar_70223 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70224 = (cppVar_70223 << 3) | 3;
	cppVar_70224 = (cppVar_70224 & cppMask_un_5_);
	cppVar_70225 = (0 << 5) | cppVar_70224;
	cppVar_70225 = (cppVar_70225 & cppMask_un_8_);
	cppVar_70227 = (cppVar_70225 == 129);
	if (cppVar_70227) {
	cppVar_70222 = SP;
	} else {
	cppVar_70229 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70230 = (cppVar_70229 << 3) | 3;
	cppVar_70230 = (cppVar_70230 & cppMask_un_5_);
	cppVar_70231 = (0 << 5) | cppVar_70230;
	cppVar_70231 = (cppVar_70231 & cppMask_un_8_);
	cppVar_70233 = (cppVar_70231 == 130);
	if (cppVar_70233) {
	cppVar_70228 = DPL;
	} else {
	cppVar_70235 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70236 = (cppVar_70235 << 3) | 3;
	cppVar_70236 = (cppVar_70236 & cppMask_un_5_);
	cppVar_70237 = (0 << 5) | cppVar_70236;
	cppVar_70237 = (cppVar_70237 & cppMask_un_8_);
	cppVar_70239 = (cppVar_70237 == 131);
	if (cppVar_70239) {
	cppVar_70234 = DPH;
	} else {
	cppVar_70241 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70242 = (cppVar_70241 << 3) | 3;
	cppVar_70242 = (cppVar_70242 & cppMask_un_5_);
	cppVar_70243 = (0 << 5) | cppVar_70242;
	cppVar_70243 = (cppVar_70243 & cppMask_un_8_);
	cppVar_70245 = (cppVar_70243 == 135);
	if (cppVar_70245) {
	cppVar_70240 = PCON;
	} else {
	cppVar_70247 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70248 = (cppVar_70247 << 3) | 3;
	cppVar_70248 = (cppVar_70248 & cppMask_un_5_);
	cppVar_70249 = (0 << 5) | cppVar_70248;
	cppVar_70249 = (cppVar_70249 & cppMask_un_8_);
	cppVar_70251 = (cppVar_70249 == 136);
	if (cppVar_70251) {
	cppVar_70246 = TCON;
	} else {
	cppVar_70253 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70254 = (cppVar_70253 << 3) | 3;
	cppVar_70254 = (cppVar_70254 & cppMask_un_5_);
	cppVar_70255 = (0 << 5) | cppVar_70254;
	cppVar_70255 = (cppVar_70255 & cppMask_un_8_);
	cppVar_70257 = (cppVar_70255 == 137);
	if (cppVar_70257) {
	cppVar_70252 = TMOD;
	} else {
	cppVar_70259 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70260 = (cppVar_70259 << 3) | 3;
	cppVar_70260 = (cppVar_70260 & cppMask_un_5_);
	cppVar_70261 = (0 << 5) | cppVar_70260;
	cppVar_70261 = (cppVar_70261 & cppMask_un_8_);
	cppVar_70263 = (cppVar_70261 == 138);
	if (cppVar_70263) {
	cppVar_70258 = TL0;
	} else {
	cppVar_70265 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70266 = (cppVar_70265 << 3) | 3;
	cppVar_70266 = (cppVar_70266 & cppMask_un_5_);
	cppVar_70267 = (0 << 5) | cppVar_70266;
	cppVar_70267 = (cppVar_70267 & cppMask_un_8_);
	cppVar_70269 = (cppVar_70267 == 140);
	if (cppVar_70269) {
	cppVar_70264 = TH0;
	} else {
	cppVar_70271 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70272 = (cppVar_70271 << 3) | 3;
	cppVar_70272 = (cppVar_70272 & cppMask_un_5_);
	cppVar_70273 = (0 << 5) | cppVar_70272;
	cppVar_70273 = (cppVar_70273 & cppMask_un_8_);
	cppVar_70275 = (cppVar_70273 == 139);
	if (cppVar_70275) {
	cppVar_70270 = TL1;
	} else {
	cppVar_70277 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70278 = (cppVar_70277 << 3) | 3;
	cppVar_70278 = (cppVar_70278 & cppMask_un_5_);
	cppVar_70279 = (0 << 5) | cppVar_70278;
	cppVar_70279 = (cppVar_70279 & cppMask_un_8_);
	cppVar_70281 = (cppVar_70279 == 141);
	if (cppVar_70281) {
	cppVar_70276 = TH1;
	} else {
	cppVar_70283 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70284 = (cppVar_70283 << 3) | 3;
	cppVar_70284 = (cppVar_70284 & cppMask_un_5_);
	cppVar_70285 = (0 << 5) | cppVar_70284;
	cppVar_70285 = (cppVar_70285 & cppMask_un_8_);
	cppVar_70287 = (cppVar_70285 == 144);
	if (cppVar_70287) {
	cppVar_70282 = P1;
	} else {
	cppVar_70289 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70290 = (cppVar_70289 << 3) | 3;
	cppVar_70290 = (cppVar_70290 & cppMask_un_5_);
	cppVar_70291 = (0 << 5) | cppVar_70290;
	cppVar_70291 = (cppVar_70291 & cppMask_un_8_);
	cppVar_70293 = (cppVar_70291 == 152);
	if (cppVar_70293) {
	cppVar_70288 = SCON;
	} else {
	cppVar_70295 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70296 = (cppVar_70295 << 3) | 3;
	cppVar_70296 = (cppVar_70296 & cppMask_un_5_);
	cppVar_70297 = (0 << 5) | cppVar_70296;
	cppVar_70297 = (cppVar_70297 & cppMask_un_8_);
	cppVar_70299 = (cppVar_70297 == 153);
	if (cppVar_70299) {
	cppVar_70294 = SBUF;
	} else {
	cppVar_70301 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70302 = (cppVar_70301 << 3) | 3;
	cppVar_70302 = (cppVar_70302 & cppMask_un_5_);
	cppVar_70303 = (0 << 5) | cppVar_70302;
	cppVar_70303 = (cppVar_70303 & cppMask_un_8_);
	cppVar_70305 = (cppVar_70303 == 160);
	if (cppVar_70305) {
	cppVar_70300 = P2;
	} else {
	cppVar_70307 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70308 = (cppVar_70307 << 3) | 3;
	cppVar_70308 = (cppVar_70308 & cppMask_un_5_);
	cppVar_70309 = (0 << 5) | cppVar_70308;
	cppVar_70309 = (cppVar_70309 & cppMask_un_8_);
	cppVar_70311 = (cppVar_70309 == 168);
	if (cppVar_70311) {
	cppVar_70306 = IE;
	} else {
	cppVar_70313 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70314 = (cppVar_70313 << 3) | 3;
	cppVar_70314 = (cppVar_70314 & cppMask_un_5_);
	cppVar_70315 = (0 << 5) | cppVar_70314;
	cppVar_70315 = (cppVar_70315 & cppMask_un_8_);
	cppVar_70317 = (cppVar_70315 == 176);
	if (cppVar_70317) {
	cppVar_70312 = P3;
	} else {
	cppVar_70319 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70320 = (cppVar_70319 << 3) | 3;
	cppVar_70320 = (cppVar_70320 & cppMask_un_5_);
	cppVar_70321 = (0 << 5) | cppVar_70320;
	cppVar_70321 = (cppVar_70321 & cppMask_un_8_);
	cppVar_70323 = (cppVar_70321 == 184);
	if (cppVar_70323) {
	cppVar_70318 = IP;
	} else {
	cppVar_70325 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70326 = (cppVar_70325 << 3) | 3;
	cppVar_70326 = (cppVar_70326 & cppMask_un_5_);
	cppVar_70327 = (0 << 5) | cppVar_70326;
	cppVar_70327 = (cppVar_70327 & cppMask_un_8_);
	cppVar_70329 = (cppVar_70327 == 208);
	if (cppVar_70329) {
	cppVar_70324 = PSW;
	} else {
	cppVar_70331 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70332 = (cppVar_70331 << 3) | 3;
	cppVar_70332 = (cppVar_70332 & cppMask_un_5_);
	cppVar_70333 = (0 << 5) | cppVar_70332;
	cppVar_70333 = (cppVar_70333 & cppMask_un_8_);
	cppVar_70335 = (cppVar_70333 == 224);
	if (cppVar_70335) {
	cppVar_70330 = ACC;
	} else {
	cppVar_70337 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70338 = (cppVar_70337 << 3) | 3;
	cppVar_70338 = (cppVar_70338 & cppMask_un_5_);
	cppVar_70339 = (0 << 5) | cppVar_70338;
	cppVar_70339 = (cppVar_70339 & cppMask_un_8_);
	cppVar_70341 = (cppVar_70339 == 240);
	if (cppVar_70341) {
	cppVar_70336 = B;
	} else {
	cppVar_70336 = 0;
	}
	cppVar_70330 = cppVar_70336;
	}
	cppVar_70324 = cppVar_70330;
	}
	cppVar_70318 = cppVar_70324;
	}
	cppVar_70312 = cppVar_70318;
	}
	cppVar_70306 = cppVar_70312;
	}
	cppVar_70300 = cppVar_70306;
	}
	cppVar_70294 = cppVar_70300;
	}
	cppVar_70288 = cppVar_70294;
	}
	cppVar_70282 = cppVar_70288;
	}
	cppVar_70276 = cppVar_70282;
	}
	cppVar_70270 = cppVar_70276;
	}
	cppVar_70264 = cppVar_70270;
	}
	cppVar_70258 = cppVar_70264;
	}
	cppVar_70252 = cppVar_70258;
	}
	cppVar_70246 = cppVar_70252;
	}
	cppVar_70240 = cppVar_70246;
	}
	cppVar_70234 = cppVar_70240;
	}
	cppVar_70228 = cppVar_70234;
	}
	cppVar_70222 = cppVar_70228;
	}
	cppVar_70216 = cppVar_70222;
	}
	cppVar_70203 = cppVar_70216;
	}
	cppVar_70197 = cppVar_70203;
	} else {
	cppVar_70197 = TCON;
	}
	cppVar_70193 = cppVar_70197;
	} else {
	cppVar_70344 = ROM.rd(PC);
	cppVar_70346 = (cppVar_70344 == 138);
	if (cppVar_70346) {
	cppVar_70349 = PC + 1;
	cppVar_70349 = (cppVar_70349 & cppMask_un_16_);
	cppVar_70350 = ROM.rd(cppVar_70349);
	cppVar_70352 = (cppVar_70350 == 136);
	if (cppVar_70352) {
	cppVar_70355 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70357 = (cppVar_70355 << 3) | 2;
	cppVar_70357 = (cppVar_70357 & cppMask_un_5_);
	cppVar_70358 = (0 << 5) | cppVar_70357;
	cppVar_70358 = (cppVar_70358 & cppMask_un_8_);
	cppVar_70359 = (cppVar_70358 >> 7) & cppMask_un_1_;
	cppVar_70361 = (cppVar_70359 == 0);
	if (cppVar_70361) {
	cppVar_70362 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70363 = (cppVar_70362 << 3) | 2;
	cppVar_70363 = (cppVar_70363 & cppMask_un_5_);
	cppVar_70364 = (0 << 5) | cppVar_70363;
	cppVar_70364 = (cppVar_70364 & cppMask_un_8_);
	cppVar_70365 = IRAM.rd(cppVar_70364);
	cppVar_70353 = cppVar_70365;
	} else {
	cppVar_70367 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70368 = (cppVar_70367 << 3) | 2;
	cppVar_70368 = (cppVar_70368 & cppMask_un_5_);
	cppVar_70369 = (0 << 5) | cppVar_70368;
	cppVar_70369 = (cppVar_70369 & cppMask_un_8_);
	cppVar_70371 = (cppVar_70369 == 128);
	if (cppVar_70371) {
	cppVar_70366 = P0;
	} else {
	cppVar_70373 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70374 = (cppVar_70373 << 3) | 2;
	cppVar_70374 = (cppVar_70374 & cppMask_un_5_);
	cppVar_70375 = (0 << 5) | cppVar_70374;
	cppVar_70375 = (cppVar_70375 & cppMask_un_8_);
	cppVar_70377 = (cppVar_70375 == 129);
	if (cppVar_70377) {
	cppVar_70372 = SP;
	} else {
	cppVar_70379 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70380 = (cppVar_70379 << 3) | 2;
	cppVar_70380 = (cppVar_70380 & cppMask_un_5_);
	cppVar_70381 = (0 << 5) | cppVar_70380;
	cppVar_70381 = (cppVar_70381 & cppMask_un_8_);
	cppVar_70383 = (cppVar_70381 == 130);
	if (cppVar_70383) {
	cppVar_70378 = DPL;
	} else {
	cppVar_70385 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70386 = (cppVar_70385 << 3) | 2;
	cppVar_70386 = (cppVar_70386 & cppMask_un_5_);
	cppVar_70387 = (0 << 5) | cppVar_70386;
	cppVar_70387 = (cppVar_70387 & cppMask_un_8_);
	cppVar_70389 = (cppVar_70387 == 131);
	if (cppVar_70389) {
	cppVar_70384 = DPH;
	} else {
	cppVar_70391 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70392 = (cppVar_70391 << 3) | 2;
	cppVar_70392 = (cppVar_70392 & cppMask_un_5_);
	cppVar_70393 = (0 << 5) | cppVar_70392;
	cppVar_70393 = (cppVar_70393 & cppMask_un_8_);
	cppVar_70395 = (cppVar_70393 == 135);
	if (cppVar_70395) {
	cppVar_70390 = PCON;
	} else {
	cppVar_70397 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70398 = (cppVar_70397 << 3) | 2;
	cppVar_70398 = (cppVar_70398 & cppMask_un_5_);
	cppVar_70399 = (0 << 5) | cppVar_70398;
	cppVar_70399 = (cppVar_70399 & cppMask_un_8_);
	cppVar_70401 = (cppVar_70399 == 136);
	if (cppVar_70401) {
	cppVar_70396 = TCON;
	} else {
	cppVar_70403 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70404 = (cppVar_70403 << 3) | 2;
	cppVar_70404 = (cppVar_70404 & cppMask_un_5_);
	cppVar_70405 = (0 << 5) | cppVar_70404;
	cppVar_70405 = (cppVar_70405 & cppMask_un_8_);
	cppVar_70407 = (cppVar_70405 == 137);
	if (cppVar_70407) {
	cppVar_70402 = TMOD;
	} else {
	cppVar_70409 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70410 = (cppVar_70409 << 3) | 2;
	cppVar_70410 = (cppVar_70410 & cppMask_un_5_);
	cppVar_70411 = (0 << 5) | cppVar_70410;
	cppVar_70411 = (cppVar_70411 & cppMask_un_8_);
	cppVar_70413 = (cppVar_70411 == 138);
	if (cppVar_70413) {
	cppVar_70408 = TL0;
	} else {
	cppVar_70415 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70416 = (cppVar_70415 << 3) | 2;
	cppVar_70416 = (cppVar_70416 & cppMask_un_5_);
	cppVar_70417 = (0 << 5) | cppVar_70416;
	cppVar_70417 = (cppVar_70417 & cppMask_un_8_);
	cppVar_70419 = (cppVar_70417 == 140);
	if (cppVar_70419) {
	cppVar_70414 = TH0;
	} else {
	cppVar_70421 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70422 = (cppVar_70421 << 3) | 2;
	cppVar_70422 = (cppVar_70422 & cppMask_un_5_);
	cppVar_70423 = (0 << 5) | cppVar_70422;
	cppVar_70423 = (cppVar_70423 & cppMask_un_8_);
	cppVar_70425 = (cppVar_70423 == 139);
	if (cppVar_70425) {
	cppVar_70420 = TL1;
	} else {
	cppVar_70427 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70428 = (cppVar_70427 << 3) | 2;
	cppVar_70428 = (cppVar_70428 & cppMask_un_5_);
	cppVar_70429 = (0 << 5) | cppVar_70428;
	cppVar_70429 = (cppVar_70429 & cppMask_un_8_);
	cppVar_70431 = (cppVar_70429 == 141);
	if (cppVar_70431) {
	cppVar_70426 = TH1;
	} else {
	cppVar_70433 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70434 = (cppVar_70433 << 3) | 2;
	cppVar_70434 = (cppVar_70434 & cppMask_un_5_);
	cppVar_70435 = (0 << 5) | cppVar_70434;
	cppVar_70435 = (cppVar_70435 & cppMask_un_8_);
	cppVar_70437 = (cppVar_70435 == 144);
	if (cppVar_70437) {
	cppVar_70432 = P1;
	} else {
	cppVar_70439 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70440 = (cppVar_70439 << 3) | 2;
	cppVar_70440 = (cppVar_70440 & cppMask_un_5_);
	cppVar_70441 = (0 << 5) | cppVar_70440;
	cppVar_70441 = (cppVar_70441 & cppMask_un_8_);
	cppVar_70443 = (cppVar_70441 == 152);
	if (cppVar_70443) {
	cppVar_70438 = SCON;
	} else {
	cppVar_70445 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70446 = (cppVar_70445 << 3) | 2;
	cppVar_70446 = (cppVar_70446 & cppMask_un_5_);
	cppVar_70447 = (0 << 5) | cppVar_70446;
	cppVar_70447 = (cppVar_70447 & cppMask_un_8_);
	cppVar_70449 = (cppVar_70447 == 153);
	if (cppVar_70449) {
	cppVar_70444 = SBUF;
	} else {
	cppVar_70451 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70452 = (cppVar_70451 << 3) | 2;
	cppVar_70452 = (cppVar_70452 & cppMask_un_5_);
	cppVar_70453 = (0 << 5) | cppVar_70452;
	cppVar_70453 = (cppVar_70453 & cppMask_un_8_);
	cppVar_70455 = (cppVar_70453 == 160);
	if (cppVar_70455) {
	cppVar_70450 = P2;
	} else {
	cppVar_70457 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70458 = (cppVar_70457 << 3) | 2;
	cppVar_70458 = (cppVar_70458 & cppMask_un_5_);
	cppVar_70459 = (0 << 5) | cppVar_70458;
	cppVar_70459 = (cppVar_70459 & cppMask_un_8_);
	cppVar_70461 = (cppVar_70459 == 168);
	if (cppVar_70461) {
	cppVar_70456 = IE;
	} else {
	cppVar_70463 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70464 = (cppVar_70463 << 3) | 2;
	cppVar_70464 = (cppVar_70464 & cppMask_un_5_);
	cppVar_70465 = (0 << 5) | cppVar_70464;
	cppVar_70465 = (cppVar_70465 & cppMask_un_8_);
	cppVar_70467 = (cppVar_70465 == 176);
	if (cppVar_70467) {
	cppVar_70462 = P3;
	} else {
	cppVar_70469 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70470 = (cppVar_70469 << 3) | 2;
	cppVar_70470 = (cppVar_70470 & cppMask_un_5_);
	cppVar_70471 = (0 << 5) | cppVar_70470;
	cppVar_70471 = (cppVar_70471 & cppMask_un_8_);
	cppVar_70473 = (cppVar_70471 == 184);
	if (cppVar_70473) {
	cppVar_70468 = IP;
	} else {
	cppVar_70475 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70476 = (cppVar_70475 << 3) | 2;
	cppVar_70476 = (cppVar_70476 & cppMask_un_5_);
	cppVar_70477 = (0 << 5) | cppVar_70476;
	cppVar_70477 = (cppVar_70477 & cppMask_un_8_);
	cppVar_70479 = (cppVar_70477 == 208);
	if (cppVar_70479) {
	cppVar_70474 = PSW;
	} else {
	cppVar_70481 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70482 = (cppVar_70481 << 3) | 2;
	cppVar_70482 = (cppVar_70482 & cppMask_un_5_);
	cppVar_70483 = (0 << 5) | cppVar_70482;
	cppVar_70483 = (cppVar_70483 & cppMask_un_8_);
	cppVar_70485 = (cppVar_70483 == 224);
	if (cppVar_70485) {
	cppVar_70480 = ACC;
	} else {
	cppVar_70487 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70488 = (cppVar_70487 << 3) | 2;
	cppVar_70488 = (cppVar_70488 & cppMask_un_5_);
	cppVar_70489 = (0 << 5) | cppVar_70488;
	cppVar_70489 = (cppVar_70489 & cppMask_un_8_);
	cppVar_70491 = (cppVar_70489 == 240);
	if (cppVar_70491) {
	cppVar_70486 = B;
	} else {
	cppVar_70486 = 0;
	}
	cppVar_70480 = cppVar_70486;
	}
	cppVar_70474 = cppVar_70480;
	}
	cppVar_70468 = cppVar_70474;
	}
	cppVar_70462 = cppVar_70468;
	}
	cppVar_70456 = cppVar_70462;
	}
	cppVar_70450 = cppVar_70456;
	}
	cppVar_70444 = cppVar_70450;
	}
	cppVar_70438 = cppVar_70444;
	}
	cppVar_70432 = cppVar_70438;
	}
	cppVar_70426 = cppVar_70432;
	}
	cppVar_70420 = cppVar_70426;
	}
	cppVar_70414 = cppVar_70420;
	}
	cppVar_70408 = cppVar_70414;
	}
	cppVar_70402 = cppVar_70408;
	}
	cppVar_70396 = cppVar_70402;
	}
	cppVar_70390 = cppVar_70396;
	}
	cppVar_70384 = cppVar_70390;
	}
	cppVar_70378 = cppVar_70384;
	}
	cppVar_70372 = cppVar_70378;
	}
	cppVar_70366 = cppVar_70372;
	}
	cppVar_70353 = cppVar_70366;
	}
	cppVar_70347 = cppVar_70353;
	} else {
	cppVar_70347 = TCON;
	}
	cppVar_70343 = cppVar_70347;
	} else {
	cppVar_70494 = ROM.rd(PC);
	cppVar_70496 = (cppVar_70494 == 137);
	if (cppVar_70496) {
	cppVar_70499 = PC + 1;
	cppVar_70499 = (cppVar_70499 & cppMask_un_16_);
	cppVar_70500 = ROM.rd(cppVar_70499);
	cppVar_70502 = (cppVar_70500 == 136);
	if (cppVar_70502) {
	cppVar_70505 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70507 = (cppVar_70505 << 3) | 1;
	cppVar_70507 = (cppVar_70507 & cppMask_un_5_);
	cppVar_70508 = (0 << 5) | cppVar_70507;
	cppVar_70508 = (cppVar_70508 & cppMask_un_8_);
	cppVar_70509 = (cppVar_70508 >> 7) & cppMask_un_1_;
	cppVar_70511 = (cppVar_70509 == 0);
	if (cppVar_70511) {
	cppVar_70512 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70513 = (cppVar_70512 << 3) | 1;
	cppVar_70513 = (cppVar_70513 & cppMask_un_5_);
	cppVar_70514 = (0 << 5) | cppVar_70513;
	cppVar_70514 = (cppVar_70514 & cppMask_un_8_);
	cppVar_70515 = IRAM.rd(cppVar_70514);
	cppVar_70503 = cppVar_70515;
	} else {
	cppVar_70517 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70518 = (cppVar_70517 << 3) | 1;
	cppVar_70518 = (cppVar_70518 & cppMask_un_5_);
	cppVar_70519 = (0 << 5) | cppVar_70518;
	cppVar_70519 = (cppVar_70519 & cppMask_un_8_);
	cppVar_70521 = (cppVar_70519 == 128);
	if (cppVar_70521) {
	cppVar_70516 = P0;
	} else {
	cppVar_70523 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70524 = (cppVar_70523 << 3) | 1;
	cppVar_70524 = (cppVar_70524 & cppMask_un_5_);
	cppVar_70525 = (0 << 5) | cppVar_70524;
	cppVar_70525 = (cppVar_70525 & cppMask_un_8_);
	cppVar_70527 = (cppVar_70525 == 129);
	if (cppVar_70527) {
	cppVar_70522 = SP;
	} else {
	cppVar_70529 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70530 = (cppVar_70529 << 3) | 1;
	cppVar_70530 = (cppVar_70530 & cppMask_un_5_);
	cppVar_70531 = (0 << 5) | cppVar_70530;
	cppVar_70531 = (cppVar_70531 & cppMask_un_8_);
	cppVar_70533 = (cppVar_70531 == 130);
	if (cppVar_70533) {
	cppVar_70528 = DPL;
	} else {
	cppVar_70535 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70536 = (cppVar_70535 << 3) | 1;
	cppVar_70536 = (cppVar_70536 & cppMask_un_5_);
	cppVar_70537 = (0 << 5) | cppVar_70536;
	cppVar_70537 = (cppVar_70537 & cppMask_un_8_);
	cppVar_70539 = (cppVar_70537 == 131);
	if (cppVar_70539) {
	cppVar_70534 = DPH;
	} else {
	cppVar_70541 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70542 = (cppVar_70541 << 3) | 1;
	cppVar_70542 = (cppVar_70542 & cppMask_un_5_);
	cppVar_70543 = (0 << 5) | cppVar_70542;
	cppVar_70543 = (cppVar_70543 & cppMask_un_8_);
	cppVar_70545 = (cppVar_70543 == 135);
	if (cppVar_70545) {
	cppVar_70540 = PCON;
	} else {
	cppVar_70547 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70548 = (cppVar_70547 << 3) | 1;
	cppVar_70548 = (cppVar_70548 & cppMask_un_5_);
	cppVar_70549 = (0 << 5) | cppVar_70548;
	cppVar_70549 = (cppVar_70549 & cppMask_un_8_);
	cppVar_70551 = (cppVar_70549 == 136);
	if (cppVar_70551) {
	cppVar_70546 = TCON;
	} else {
	cppVar_70553 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70554 = (cppVar_70553 << 3) | 1;
	cppVar_70554 = (cppVar_70554 & cppMask_un_5_);
	cppVar_70555 = (0 << 5) | cppVar_70554;
	cppVar_70555 = (cppVar_70555 & cppMask_un_8_);
	cppVar_70557 = (cppVar_70555 == 137);
	if (cppVar_70557) {
	cppVar_70552 = TMOD;
	} else {
	cppVar_70559 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70560 = (cppVar_70559 << 3) | 1;
	cppVar_70560 = (cppVar_70560 & cppMask_un_5_);
	cppVar_70561 = (0 << 5) | cppVar_70560;
	cppVar_70561 = (cppVar_70561 & cppMask_un_8_);
	cppVar_70563 = (cppVar_70561 == 138);
	if (cppVar_70563) {
	cppVar_70558 = TL0;
	} else {
	cppVar_70565 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70566 = (cppVar_70565 << 3) | 1;
	cppVar_70566 = (cppVar_70566 & cppMask_un_5_);
	cppVar_70567 = (0 << 5) | cppVar_70566;
	cppVar_70567 = (cppVar_70567 & cppMask_un_8_);
	cppVar_70569 = (cppVar_70567 == 140);
	if (cppVar_70569) {
	cppVar_70564 = TH0;
	} else {
	cppVar_70571 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70572 = (cppVar_70571 << 3) | 1;
	cppVar_70572 = (cppVar_70572 & cppMask_un_5_);
	cppVar_70573 = (0 << 5) | cppVar_70572;
	cppVar_70573 = (cppVar_70573 & cppMask_un_8_);
	cppVar_70575 = (cppVar_70573 == 139);
	if (cppVar_70575) {
	cppVar_70570 = TL1;
	} else {
	cppVar_70577 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70578 = (cppVar_70577 << 3) | 1;
	cppVar_70578 = (cppVar_70578 & cppMask_un_5_);
	cppVar_70579 = (0 << 5) | cppVar_70578;
	cppVar_70579 = (cppVar_70579 & cppMask_un_8_);
	cppVar_70581 = (cppVar_70579 == 141);
	if (cppVar_70581) {
	cppVar_70576 = TH1;
	} else {
	cppVar_70583 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70584 = (cppVar_70583 << 3) | 1;
	cppVar_70584 = (cppVar_70584 & cppMask_un_5_);
	cppVar_70585 = (0 << 5) | cppVar_70584;
	cppVar_70585 = (cppVar_70585 & cppMask_un_8_);
	cppVar_70587 = (cppVar_70585 == 144);
	if (cppVar_70587) {
	cppVar_70582 = P1;
	} else {
	cppVar_70589 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70590 = (cppVar_70589 << 3) | 1;
	cppVar_70590 = (cppVar_70590 & cppMask_un_5_);
	cppVar_70591 = (0 << 5) | cppVar_70590;
	cppVar_70591 = (cppVar_70591 & cppMask_un_8_);
	cppVar_70593 = (cppVar_70591 == 152);
	if (cppVar_70593) {
	cppVar_70588 = SCON;
	} else {
	cppVar_70595 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70596 = (cppVar_70595 << 3) | 1;
	cppVar_70596 = (cppVar_70596 & cppMask_un_5_);
	cppVar_70597 = (0 << 5) | cppVar_70596;
	cppVar_70597 = (cppVar_70597 & cppMask_un_8_);
	cppVar_70599 = (cppVar_70597 == 153);
	if (cppVar_70599) {
	cppVar_70594 = SBUF;
	} else {
	cppVar_70601 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70602 = (cppVar_70601 << 3) | 1;
	cppVar_70602 = (cppVar_70602 & cppMask_un_5_);
	cppVar_70603 = (0 << 5) | cppVar_70602;
	cppVar_70603 = (cppVar_70603 & cppMask_un_8_);
	cppVar_70605 = (cppVar_70603 == 160);
	if (cppVar_70605) {
	cppVar_70600 = P2;
	} else {
	cppVar_70607 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70608 = (cppVar_70607 << 3) | 1;
	cppVar_70608 = (cppVar_70608 & cppMask_un_5_);
	cppVar_70609 = (0 << 5) | cppVar_70608;
	cppVar_70609 = (cppVar_70609 & cppMask_un_8_);
	cppVar_70611 = (cppVar_70609 == 168);
	if (cppVar_70611) {
	cppVar_70606 = IE;
	} else {
	cppVar_70613 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70614 = (cppVar_70613 << 3) | 1;
	cppVar_70614 = (cppVar_70614 & cppMask_un_5_);
	cppVar_70615 = (0 << 5) | cppVar_70614;
	cppVar_70615 = (cppVar_70615 & cppMask_un_8_);
	cppVar_70617 = (cppVar_70615 == 176);
	if (cppVar_70617) {
	cppVar_70612 = P3;
	} else {
	cppVar_70619 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70620 = (cppVar_70619 << 3) | 1;
	cppVar_70620 = (cppVar_70620 & cppMask_un_5_);
	cppVar_70621 = (0 << 5) | cppVar_70620;
	cppVar_70621 = (cppVar_70621 & cppMask_un_8_);
	cppVar_70623 = (cppVar_70621 == 184);
	if (cppVar_70623) {
	cppVar_70618 = IP;
	} else {
	cppVar_70625 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70626 = (cppVar_70625 << 3) | 1;
	cppVar_70626 = (cppVar_70626 & cppMask_un_5_);
	cppVar_70627 = (0 << 5) | cppVar_70626;
	cppVar_70627 = (cppVar_70627 & cppMask_un_8_);
	cppVar_70629 = (cppVar_70627 == 208);
	if (cppVar_70629) {
	cppVar_70624 = PSW;
	} else {
	cppVar_70631 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70632 = (cppVar_70631 << 3) | 1;
	cppVar_70632 = (cppVar_70632 & cppMask_un_5_);
	cppVar_70633 = (0 << 5) | cppVar_70632;
	cppVar_70633 = (cppVar_70633 & cppMask_un_8_);
	cppVar_70635 = (cppVar_70633 == 224);
	if (cppVar_70635) {
	cppVar_70630 = ACC;
	} else {
	cppVar_70637 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70638 = (cppVar_70637 << 3) | 1;
	cppVar_70638 = (cppVar_70638 & cppMask_un_5_);
	cppVar_70639 = (0 << 5) | cppVar_70638;
	cppVar_70639 = (cppVar_70639 & cppMask_un_8_);
	cppVar_70641 = (cppVar_70639 == 240);
	if (cppVar_70641) {
	cppVar_70636 = B;
	} else {
	cppVar_70636 = 0;
	}
	cppVar_70630 = cppVar_70636;
	}
	cppVar_70624 = cppVar_70630;
	}
	cppVar_70618 = cppVar_70624;
	}
	cppVar_70612 = cppVar_70618;
	}
	cppVar_70606 = cppVar_70612;
	}
	cppVar_70600 = cppVar_70606;
	}
	cppVar_70594 = cppVar_70600;
	}
	cppVar_70588 = cppVar_70594;
	}
	cppVar_70582 = cppVar_70588;
	}
	cppVar_70576 = cppVar_70582;
	}
	cppVar_70570 = cppVar_70576;
	}
	cppVar_70564 = cppVar_70570;
	}
	cppVar_70558 = cppVar_70564;
	}
	cppVar_70552 = cppVar_70558;
	}
	cppVar_70546 = cppVar_70552;
	}
	cppVar_70540 = cppVar_70546;
	}
	cppVar_70534 = cppVar_70540;
	}
	cppVar_70528 = cppVar_70534;
	}
	cppVar_70522 = cppVar_70528;
	}
	cppVar_70516 = cppVar_70522;
	}
	cppVar_70503 = cppVar_70516;
	}
	cppVar_70497 = cppVar_70503;
	} else {
	cppVar_70497 = TCON;
	}
	cppVar_70493 = cppVar_70497;
	} else {
	cppVar_70644 = ROM.rd(PC);
	cppVar_70646 = (cppVar_70644 == 136);
	if (cppVar_70646) {
	cppVar_70649 = PC + 1;
	cppVar_70649 = (cppVar_70649 & cppMask_un_16_);
	cppVar_70650 = ROM.rd(cppVar_70649);
	cppVar_70652 = (cppVar_70650 == 136);
	if (cppVar_70652) {
	cppVar_70655 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70657 = (cppVar_70655 << 3) | 0;
	cppVar_70657 = (cppVar_70657 & cppMask_un_5_);
	cppVar_70658 = (0 << 5) | cppVar_70657;
	cppVar_70658 = (cppVar_70658 & cppMask_un_8_);
	cppVar_70659 = (cppVar_70658 >> 7) & cppMask_un_1_;
	cppVar_70661 = (cppVar_70659 == 0);
	if (cppVar_70661) {
	cppVar_70662 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70663 = (cppVar_70662 << 3) | 0;
	cppVar_70663 = (cppVar_70663 & cppMask_un_5_);
	cppVar_70664 = (0 << 5) | cppVar_70663;
	cppVar_70664 = (cppVar_70664 & cppMask_un_8_);
	cppVar_70665 = IRAM.rd(cppVar_70664);
	cppVar_70653 = cppVar_70665;
	} else {
	cppVar_70667 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70668 = (cppVar_70667 << 3) | 0;
	cppVar_70668 = (cppVar_70668 & cppMask_un_5_);
	cppVar_70669 = (0 << 5) | cppVar_70668;
	cppVar_70669 = (cppVar_70669 & cppMask_un_8_);
	cppVar_70671 = (cppVar_70669 == 128);
	if (cppVar_70671) {
	cppVar_70666 = P0;
	} else {
	cppVar_70673 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70674 = (cppVar_70673 << 3) | 0;
	cppVar_70674 = (cppVar_70674 & cppMask_un_5_);
	cppVar_70675 = (0 << 5) | cppVar_70674;
	cppVar_70675 = (cppVar_70675 & cppMask_un_8_);
	cppVar_70677 = (cppVar_70675 == 129);
	if (cppVar_70677) {
	cppVar_70672 = SP;
	} else {
	cppVar_70679 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70680 = (cppVar_70679 << 3) | 0;
	cppVar_70680 = (cppVar_70680 & cppMask_un_5_);
	cppVar_70681 = (0 << 5) | cppVar_70680;
	cppVar_70681 = (cppVar_70681 & cppMask_un_8_);
	cppVar_70683 = (cppVar_70681 == 130);
	if (cppVar_70683) {
	cppVar_70678 = DPL;
	} else {
	cppVar_70685 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70686 = (cppVar_70685 << 3) | 0;
	cppVar_70686 = (cppVar_70686 & cppMask_un_5_);
	cppVar_70687 = (0 << 5) | cppVar_70686;
	cppVar_70687 = (cppVar_70687 & cppMask_un_8_);
	cppVar_70689 = (cppVar_70687 == 131);
	if (cppVar_70689) {
	cppVar_70684 = DPH;
	} else {
	cppVar_70691 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70692 = (cppVar_70691 << 3) | 0;
	cppVar_70692 = (cppVar_70692 & cppMask_un_5_);
	cppVar_70693 = (0 << 5) | cppVar_70692;
	cppVar_70693 = (cppVar_70693 & cppMask_un_8_);
	cppVar_70695 = (cppVar_70693 == 135);
	if (cppVar_70695) {
	cppVar_70690 = PCON;
	} else {
	cppVar_70697 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70698 = (cppVar_70697 << 3) | 0;
	cppVar_70698 = (cppVar_70698 & cppMask_un_5_);
	cppVar_70699 = (0 << 5) | cppVar_70698;
	cppVar_70699 = (cppVar_70699 & cppMask_un_8_);
	cppVar_70701 = (cppVar_70699 == 136);
	if (cppVar_70701) {
	cppVar_70696 = TCON;
	} else {
	cppVar_70703 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70704 = (cppVar_70703 << 3) | 0;
	cppVar_70704 = (cppVar_70704 & cppMask_un_5_);
	cppVar_70705 = (0 << 5) | cppVar_70704;
	cppVar_70705 = (cppVar_70705 & cppMask_un_8_);
	cppVar_70707 = (cppVar_70705 == 137);
	if (cppVar_70707) {
	cppVar_70702 = TMOD;
	} else {
	cppVar_70709 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70710 = (cppVar_70709 << 3) | 0;
	cppVar_70710 = (cppVar_70710 & cppMask_un_5_);
	cppVar_70711 = (0 << 5) | cppVar_70710;
	cppVar_70711 = (cppVar_70711 & cppMask_un_8_);
	cppVar_70713 = (cppVar_70711 == 138);
	if (cppVar_70713) {
	cppVar_70708 = TL0;
	} else {
	cppVar_70715 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70716 = (cppVar_70715 << 3) | 0;
	cppVar_70716 = (cppVar_70716 & cppMask_un_5_);
	cppVar_70717 = (0 << 5) | cppVar_70716;
	cppVar_70717 = (cppVar_70717 & cppMask_un_8_);
	cppVar_70719 = (cppVar_70717 == 140);
	if (cppVar_70719) {
	cppVar_70714 = TH0;
	} else {
	cppVar_70721 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70722 = (cppVar_70721 << 3) | 0;
	cppVar_70722 = (cppVar_70722 & cppMask_un_5_);
	cppVar_70723 = (0 << 5) | cppVar_70722;
	cppVar_70723 = (cppVar_70723 & cppMask_un_8_);
	cppVar_70725 = (cppVar_70723 == 139);
	if (cppVar_70725) {
	cppVar_70720 = TL1;
	} else {
	cppVar_70727 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70728 = (cppVar_70727 << 3) | 0;
	cppVar_70728 = (cppVar_70728 & cppMask_un_5_);
	cppVar_70729 = (0 << 5) | cppVar_70728;
	cppVar_70729 = (cppVar_70729 & cppMask_un_8_);
	cppVar_70731 = (cppVar_70729 == 141);
	if (cppVar_70731) {
	cppVar_70726 = TH1;
	} else {
	cppVar_70733 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70734 = (cppVar_70733 << 3) | 0;
	cppVar_70734 = (cppVar_70734 & cppMask_un_5_);
	cppVar_70735 = (0 << 5) | cppVar_70734;
	cppVar_70735 = (cppVar_70735 & cppMask_un_8_);
	cppVar_70737 = (cppVar_70735 == 144);
	if (cppVar_70737) {
	cppVar_70732 = P1;
	} else {
	cppVar_70739 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70740 = (cppVar_70739 << 3) | 0;
	cppVar_70740 = (cppVar_70740 & cppMask_un_5_);
	cppVar_70741 = (0 << 5) | cppVar_70740;
	cppVar_70741 = (cppVar_70741 & cppMask_un_8_);
	cppVar_70743 = (cppVar_70741 == 152);
	if (cppVar_70743) {
	cppVar_70738 = SCON;
	} else {
	cppVar_70745 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70746 = (cppVar_70745 << 3) | 0;
	cppVar_70746 = (cppVar_70746 & cppMask_un_5_);
	cppVar_70747 = (0 << 5) | cppVar_70746;
	cppVar_70747 = (cppVar_70747 & cppMask_un_8_);
	cppVar_70749 = (cppVar_70747 == 153);
	if (cppVar_70749) {
	cppVar_70744 = SBUF;
	} else {
	cppVar_70751 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70752 = (cppVar_70751 << 3) | 0;
	cppVar_70752 = (cppVar_70752 & cppMask_un_5_);
	cppVar_70753 = (0 << 5) | cppVar_70752;
	cppVar_70753 = (cppVar_70753 & cppMask_un_8_);
	cppVar_70755 = (cppVar_70753 == 160);
	if (cppVar_70755) {
	cppVar_70750 = P2;
	} else {
	cppVar_70757 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70758 = (cppVar_70757 << 3) | 0;
	cppVar_70758 = (cppVar_70758 & cppMask_un_5_);
	cppVar_70759 = (0 << 5) | cppVar_70758;
	cppVar_70759 = (cppVar_70759 & cppMask_un_8_);
	cppVar_70761 = (cppVar_70759 == 168);
	if (cppVar_70761) {
	cppVar_70756 = IE;
	} else {
	cppVar_70763 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70764 = (cppVar_70763 << 3) | 0;
	cppVar_70764 = (cppVar_70764 & cppMask_un_5_);
	cppVar_70765 = (0 << 5) | cppVar_70764;
	cppVar_70765 = (cppVar_70765 & cppMask_un_8_);
	cppVar_70767 = (cppVar_70765 == 176);
	if (cppVar_70767) {
	cppVar_70762 = P3;
	} else {
	cppVar_70769 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70770 = (cppVar_70769 << 3) | 0;
	cppVar_70770 = (cppVar_70770 & cppMask_un_5_);
	cppVar_70771 = (0 << 5) | cppVar_70770;
	cppVar_70771 = (cppVar_70771 & cppMask_un_8_);
	cppVar_70773 = (cppVar_70771 == 184);
	if (cppVar_70773) {
	cppVar_70768 = IP;
	} else {
	cppVar_70775 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70776 = (cppVar_70775 << 3) | 0;
	cppVar_70776 = (cppVar_70776 & cppMask_un_5_);
	cppVar_70777 = (0 << 5) | cppVar_70776;
	cppVar_70777 = (cppVar_70777 & cppMask_un_8_);
	cppVar_70779 = (cppVar_70777 == 208);
	if (cppVar_70779) {
	cppVar_70774 = PSW;
	} else {
	cppVar_70781 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70782 = (cppVar_70781 << 3) | 0;
	cppVar_70782 = (cppVar_70782 & cppMask_un_5_);
	cppVar_70783 = (0 << 5) | cppVar_70782;
	cppVar_70783 = (cppVar_70783 & cppMask_un_8_);
	cppVar_70785 = (cppVar_70783 == 224);
	if (cppVar_70785) {
	cppVar_70780 = ACC;
	} else {
	cppVar_70787 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70788 = (cppVar_70787 << 3) | 0;
	cppVar_70788 = (cppVar_70788 & cppMask_un_5_);
	cppVar_70789 = (0 << 5) | cppVar_70788;
	cppVar_70789 = (cppVar_70789 & cppMask_un_8_);
	cppVar_70791 = (cppVar_70789 == 240);
	if (cppVar_70791) {
	cppVar_70786 = B;
	} else {
	cppVar_70786 = 0;
	}
	cppVar_70780 = cppVar_70786;
	}
	cppVar_70774 = cppVar_70780;
	}
	cppVar_70768 = cppVar_70774;
	}
	cppVar_70762 = cppVar_70768;
	}
	cppVar_70756 = cppVar_70762;
	}
	cppVar_70750 = cppVar_70756;
	}
	cppVar_70744 = cppVar_70750;
	}
	cppVar_70738 = cppVar_70744;
	}
	cppVar_70732 = cppVar_70738;
	}
	cppVar_70726 = cppVar_70732;
	}
	cppVar_70720 = cppVar_70726;
	}
	cppVar_70714 = cppVar_70720;
	}
	cppVar_70708 = cppVar_70714;
	}
	cppVar_70702 = cppVar_70708;
	}
	cppVar_70696 = cppVar_70702;
	}
	cppVar_70690 = cppVar_70696;
	}
	cppVar_70684 = cppVar_70690;
	}
	cppVar_70678 = cppVar_70684;
	}
	cppVar_70672 = cppVar_70678;
	}
	cppVar_70666 = cppVar_70672;
	}
	cppVar_70653 = cppVar_70666;
	}
	cppVar_70647 = cppVar_70653;
	} else {
	cppVar_70647 = TCON;
	}
	cppVar_70643 = cppVar_70647;
	} else {
	cppVar_70794 = ROM.rd(PC);
	cppVar_70796 = (cppVar_70794 == 135);
	if (cppVar_70796) {
	cppVar_70799 = PC + 1;
	cppVar_70799 = (cppVar_70799 & cppMask_un_16_);
	cppVar_70800 = ROM.rd(cppVar_70799);
	cppVar_70802 = (cppVar_70800 == 136);
	if (cppVar_70802) {
	cppVar_70804 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70806 = (cppVar_70804 << 3) | 1;
	cppVar_70806 = (cppVar_70806 & cppMask_un_5_);
	cppVar_70807 = (0 << 5) | cppVar_70806;
	cppVar_70807 = (cppVar_70807 & cppMask_un_8_);
	cppVar_70808 = IRAM.rd(cppVar_70807);
	cppVar_70809 = IRAM.rd(cppVar_70808);
	cppVar_70797 = cppVar_70809;
	} else {
	cppVar_70797 = TCON;
	}
	cppVar_70793 = cppVar_70797;
	} else {
	cppVar_70811 = ROM.rd(PC);
	cppVar_70813 = (cppVar_70811 == 134);
	if (cppVar_70813) {
	cppVar_70816 = PC + 1;
	cppVar_70816 = (cppVar_70816 & cppMask_un_16_);
	cppVar_70817 = ROM.rd(cppVar_70816);
	cppVar_70819 = (cppVar_70817 == 136);
	if (cppVar_70819) {
	cppVar_70821 = (PSW >> 3) & cppMask_un_2_;
	cppVar_70823 = (cppVar_70821 << 3) | 0;
	cppVar_70823 = (cppVar_70823 & cppMask_un_5_);
	cppVar_70824 = (0 << 5) | cppVar_70823;
	cppVar_70824 = (cppVar_70824 & cppMask_un_8_);
	cppVar_70825 = IRAM.rd(cppVar_70824);
	cppVar_70826 = IRAM.rd(cppVar_70825);
	cppVar_70814 = cppVar_70826;
	} else {
	cppVar_70814 = TCON;
	}
	cppVar_70810 = cppVar_70814;
	} else {
	cppVar_70828 = ROM.rd(PC);
	cppVar_70830 = (cppVar_70828 == 133);
	if (cppVar_70830) {
	cppVar_70833 = PC + 2;
	cppVar_70833 = (cppVar_70833 & cppMask_un_16_);
	cppVar_70834 = ROM.rd(cppVar_70833);
	cppVar_70836 = (cppVar_70834 == 136);
	if (cppVar_70836) {
	cppVar_70839 = PC + 1;
	cppVar_70839 = (cppVar_70839 & cppMask_un_16_);
	cppVar_70840 = ROM.rd(cppVar_70839);
	cppVar_70841 = (cppVar_70840 >> 7) & cppMask_un_1_;
	cppVar_70843 = (cppVar_70841 == 0);
	if (cppVar_70843) {
	cppVar_70844 = PC + 1;
	cppVar_70844 = (cppVar_70844 & cppMask_un_16_);
	cppVar_70845 = ROM.rd(cppVar_70844);
	cppVar_70846 = IRAM.rd(cppVar_70845);
	cppVar_70837 = cppVar_70846;
	} else {
	cppVar_70848 = PC + 1;
	cppVar_70848 = (cppVar_70848 & cppMask_un_16_);
	cppVar_70849 = ROM.rd(cppVar_70848);
	cppVar_70851 = (cppVar_70849 == 128);
	if (cppVar_70851) {
	cppVar_70847 = P0;
	} else {
	cppVar_70853 = PC + 1;
	cppVar_70853 = (cppVar_70853 & cppMask_un_16_);
	cppVar_70854 = ROM.rd(cppVar_70853);
	cppVar_70856 = (cppVar_70854 == 129);
	if (cppVar_70856) {
	cppVar_70852 = SP;
	} else {
	cppVar_70858 = PC + 1;
	cppVar_70858 = (cppVar_70858 & cppMask_un_16_);
	cppVar_70859 = ROM.rd(cppVar_70858);
	cppVar_70861 = (cppVar_70859 == 130);
	if (cppVar_70861) {
	cppVar_70857 = DPL;
	} else {
	cppVar_70863 = PC + 1;
	cppVar_70863 = (cppVar_70863 & cppMask_un_16_);
	cppVar_70864 = ROM.rd(cppVar_70863);
	cppVar_70866 = (cppVar_70864 == 131);
	if (cppVar_70866) {
	cppVar_70862 = DPH;
	} else {
	cppVar_70868 = PC + 1;
	cppVar_70868 = (cppVar_70868 & cppMask_un_16_);
	cppVar_70869 = ROM.rd(cppVar_70868);
	cppVar_70871 = (cppVar_70869 == 135);
	if (cppVar_70871) {
	cppVar_70867 = PCON;
	} else {
	cppVar_70873 = PC + 1;
	cppVar_70873 = (cppVar_70873 & cppMask_un_16_);
	cppVar_70874 = ROM.rd(cppVar_70873);
	cppVar_70876 = (cppVar_70874 == 136);
	if (cppVar_70876) {
	cppVar_70872 = TCON;
	} else {
	cppVar_70878 = PC + 1;
	cppVar_70878 = (cppVar_70878 & cppMask_un_16_);
	cppVar_70879 = ROM.rd(cppVar_70878);
	cppVar_70881 = (cppVar_70879 == 137);
	if (cppVar_70881) {
	cppVar_70877 = TMOD;
	} else {
	cppVar_70883 = PC + 1;
	cppVar_70883 = (cppVar_70883 & cppMask_un_16_);
	cppVar_70884 = ROM.rd(cppVar_70883);
	cppVar_70886 = (cppVar_70884 == 138);
	if (cppVar_70886) {
	cppVar_70882 = TL0;
	} else {
	cppVar_70888 = PC + 1;
	cppVar_70888 = (cppVar_70888 & cppMask_un_16_);
	cppVar_70889 = ROM.rd(cppVar_70888);
	cppVar_70891 = (cppVar_70889 == 140);
	if (cppVar_70891) {
	cppVar_70887 = TH0;
	} else {
	cppVar_70893 = PC + 1;
	cppVar_70893 = (cppVar_70893 & cppMask_un_16_);
	cppVar_70894 = ROM.rd(cppVar_70893);
	cppVar_70896 = (cppVar_70894 == 139);
	if (cppVar_70896) {
	cppVar_70892 = TL1;
	} else {
	cppVar_70898 = PC + 1;
	cppVar_70898 = (cppVar_70898 & cppMask_un_16_);
	cppVar_70899 = ROM.rd(cppVar_70898);
	cppVar_70901 = (cppVar_70899 == 141);
	if (cppVar_70901) {
	cppVar_70897 = TH1;
	} else {
	cppVar_70903 = PC + 1;
	cppVar_70903 = (cppVar_70903 & cppMask_un_16_);
	cppVar_70904 = ROM.rd(cppVar_70903);
	cppVar_70906 = (cppVar_70904 == 144);
	if (cppVar_70906) {
	cppVar_70902 = P1;
	} else {
	cppVar_70908 = PC + 1;
	cppVar_70908 = (cppVar_70908 & cppMask_un_16_);
	cppVar_70909 = ROM.rd(cppVar_70908);
	cppVar_70911 = (cppVar_70909 == 152);
	if (cppVar_70911) {
	cppVar_70907 = SCON;
	} else {
	cppVar_70913 = PC + 1;
	cppVar_70913 = (cppVar_70913 & cppMask_un_16_);
	cppVar_70914 = ROM.rd(cppVar_70913);
	cppVar_70916 = (cppVar_70914 == 153);
	if (cppVar_70916) {
	cppVar_70912 = SBUF;
	} else {
	cppVar_70918 = PC + 1;
	cppVar_70918 = (cppVar_70918 & cppMask_un_16_);
	cppVar_70919 = ROM.rd(cppVar_70918);
	cppVar_70921 = (cppVar_70919 == 160);
	if (cppVar_70921) {
	cppVar_70917 = P2;
	} else {
	cppVar_70923 = PC + 1;
	cppVar_70923 = (cppVar_70923 & cppMask_un_16_);
	cppVar_70924 = ROM.rd(cppVar_70923);
	cppVar_70926 = (cppVar_70924 == 168);
	if (cppVar_70926) {
	cppVar_70922 = IE;
	} else {
	cppVar_70928 = PC + 1;
	cppVar_70928 = (cppVar_70928 & cppMask_un_16_);
	cppVar_70929 = ROM.rd(cppVar_70928);
	cppVar_70931 = (cppVar_70929 == 176);
	if (cppVar_70931) {
	cppVar_70927 = P3;
	} else {
	cppVar_70933 = PC + 1;
	cppVar_70933 = (cppVar_70933 & cppMask_un_16_);
	cppVar_70934 = ROM.rd(cppVar_70933);
	cppVar_70936 = (cppVar_70934 == 184);
	if (cppVar_70936) {
	cppVar_70932 = IP;
	} else {
	cppVar_70938 = PC + 1;
	cppVar_70938 = (cppVar_70938 & cppMask_un_16_);
	cppVar_70939 = ROM.rd(cppVar_70938);
	cppVar_70941 = (cppVar_70939 == 208);
	if (cppVar_70941) {
	cppVar_70937 = PSW;
	} else {
	cppVar_70943 = PC + 1;
	cppVar_70943 = (cppVar_70943 & cppMask_un_16_);
	cppVar_70944 = ROM.rd(cppVar_70943);
	cppVar_70946 = (cppVar_70944 == 224);
	if (cppVar_70946) {
	cppVar_70942 = ACC;
	} else {
	cppVar_70948 = PC + 1;
	cppVar_70948 = (cppVar_70948 & cppMask_un_16_);
	cppVar_70949 = ROM.rd(cppVar_70948);
	cppVar_70951 = (cppVar_70949 == 240);
	if (cppVar_70951) {
	cppVar_70947 = B;
	} else {
	cppVar_70947 = 0;
	}
	cppVar_70942 = cppVar_70947;
	}
	cppVar_70937 = cppVar_70942;
	}
	cppVar_70932 = cppVar_70937;
	}
	cppVar_70927 = cppVar_70932;
	}
	cppVar_70922 = cppVar_70927;
	}
	cppVar_70917 = cppVar_70922;
	}
	cppVar_70912 = cppVar_70917;
	}
	cppVar_70907 = cppVar_70912;
	}
	cppVar_70902 = cppVar_70907;
	}
	cppVar_70897 = cppVar_70902;
	}
	cppVar_70892 = cppVar_70897;
	}
	cppVar_70887 = cppVar_70892;
	}
	cppVar_70882 = cppVar_70887;
	}
	cppVar_70877 = cppVar_70882;
	}
	cppVar_70872 = cppVar_70877;
	}
	cppVar_70867 = cppVar_70872;
	}
	cppVar_70862 = cppVar_70867;
	}
	cppVar_70857 = cppVar_70862;
	}
	cppVar_70852 = cppVar_70857;
	}
	cppVar_70847 = cppVar_70852;
	}
	cppVar_70837 = cppVar_70847;
	}
	cppVar_70831 = cppVar_70837;
	} else {
	cppVar_70831 = TCON;
	}
	cppVar_70827 = cppVar_70831;
	} else {
	cppVar_70954 = ROM.rd(PC);
	cppVar_70956 = (cppVar_70954 == 117);
	if (cppVar_70956) {
	cppVar_70959 = PC + 1;
	cppVar_70959 = (cppVar_70959 & cppMask_un_16_);
	cppVar_70960 = ROM.rd(cppVar_70959);
	cppVar_70962 = (cppVar_70960 == 136);
	if (cppVar_70962) {
	cppVar_70964 = PC + 2;
	cppVar_70964 = (cppVar_70964 & cppMask_un_16_);
	cppVar_70965 = ROM.rd(cppVar_70964);
	cppVar_70957 = cppVar_70965;
	} else {
	cppVar_70957 = TCON;
	}
	cppVar_70953 = cppVar_70957;
	} else {
	cppVar_70967 = ROM.rd(PC);
	cppVar_70969 = (cppVar_70967 == 99);
	if (cppVar_70969) {
	cppVar_70972 = PC + 1;
	cppVar_70972 = (cppVar_70972 & cppMask_un_16_);
	cppVar_70973 = ROM.rd(cppVar_70972);
	cppVar_70975 = (cppVar_70973 == 136);
	if (cppVar_70975) {
	cppVar_70977 = PC + 1;
	cppVar_70977 = (cppVar_70977 & cppMask_un_16_);
	cppVar_70978 = ROM.rd(cppVar_70977);
	cppVar_70979 = (cppVar_70978 >> 7) & cppMask_un_1_;
	cppVar_70981 = (cppVar_70979 == 0);
	if (cppVar_70981) {
	cppVar_70982 = PC + 1;
	cppVar_70982 = (cppVar_70982 & cppMask_un_16_);
	cppVar_70983 = ROM.rd(cppVar_70982);
	cppVar_70984 = IRAM.rd(cppVar_70983);
	cppVar_70976 = cppVar_70984;
	} else {
	cppVar_70986 = PC + 1;
	cppVar_70986 = (cppVar_70986 & cppMask_un_16_);
	cppVar_70987 = ROM.rd(cppVar_70986);
	cppVar_70989 = (cppVar_70987 == 128);
	if (cppVar_70989) {
	cppVar_70985 = P0;
	} else {
	cppVar_70991 = PC + 1;
	cppVar_70991 = (cppVar_70991 & cppMask_un_16_);
	cppVar_70992 = ROM.rd(cppVar_70991);
	cppVar_70994 = (cppVar_70992 == 129);
	if (cppVar_70994) {
	cppVar_70990 = SP;
	} else {
	cppVar_70996 = PC + 1;
	cppVar_70996 = (cppVar_70996 & cppMask_un_16_);
	cppVar_70997 = ROM.rd(cppVar_70996);
	cppVar_70999 = (cppVar_70997 == 130);
	if (cppVar_70999) {
	cppVar_70995 = DPL;
	} else {
	cppVar_71001 = PC + 1;
	cppVar_71001 = (cppVar_71001 & cppMask_un_16_);
	cppVar_71002 = ROM.rd(cppVar_71001);
	cppVar_71004 = (cppVar_71002 == 131);
	if (cppVar_71004) {
	cppVar_71000 = DPH;
	} else {
	cppVar_71006 = PC + 1;
	cppVar_71006 = (cppVar_71006 & cppMask_un_16_);
	cppVar_71007 = ROM.rd(cppVar_71006);
	cppVar_71009 = (cppVar_71007 == 135);
	if (cppVar_71009) {
	cppVar_71005 = PCON;
	} else {
	cppVar_71011 = PC + 1;
	cppVar_71011 = (cppVar_71011 & cppMask_un_16_);
	cppVar_71012 = ROM.rd(cppVar_71011);
	cppVar_71014 = (cppVar_71012 == 136);
	if (cppVar_71014) {
	cppVar_71010 = TCON;
	} else {
	cppVar_71016 = PC + 1;
	cppVar_71016 = (cppVar_71016 & cppMask_un_16_);
	cppVar_71017 = ROM.rd(cppVar_71016);
	cppVar_71019 = (cppVar_71017 == 137);
	if (cppVar_71019) {
	cppVar_71015 = TMOD;
	} else {
	cppVar_71021 = PC + 1;
	cppVar_71021 = (cppVar_71021 & cppMask_un_16_);
	cppVar_71022 = ROM.rd(cppVar_71021);
	cppVar_71024 = (cppVar_71022 == 138);
	if (cppVar_71024) {
	cppVar_71020 = TL0;
	} else {
	cppVar_71026 = PC + 1;
	cppVar_71026 = (cppVar_71026 & cppMask_un_16_);
	cppVar_71027 = ROM.rd(cppVar_71026);
	cppVar_71029 = (cppVar_71027 == 140);
	if (cppVar_71029) {
	cppVar_71025 = TH0;
	} else {
	cppVar_71031 = PC + 1;
	cppVar_71031 = (cppVar_71031 & cppMask_un_16_);
	cppVar_71032 = ROM.rd(cppVar_71031);
	cppVar_71034 = (cppVar_71032 == 139);
	if (cppVar_71034) {
	cppVar_71030 = TL1;
	} else {
	cppVar_71036 = PC + 1;
	cppVar_71036 = (cppVar_71036 & cppMask_un_16_);
	cppVar_71037 = ROM.rd(cppVar_71036);
	cppVar_71039 = (cppVar_71037 == 141);
	if (cppVar_71039) {
	cppVar_71035 = TH1;
	} else {
	cppVar_71041 = PC + 1;
	cppVar_71041 = (cppVar_71041 & cppMask_un_16_);
	cppVar_71042 = ROM.rd(cppVar_71041);
	cppVar_71044 = (cppVar_71042 == 144);
	if (cppVar_71044) {
	cppVar_71040 = P1;
	} else {
	cppVar_71046 = PC + 1;
	cppVar_71046 = (cppVar_71046 & cppMask_un_16_);
	cppVar_71047 = ROM.rd(cppVar_71046);
	cppVar_71049 = (cppVar_71047 == 152);
	if (cppVar_71049) {
	cppVar_71045 = SCON;
	} else {
	cppVar_71051 = PC + 1;
	cppVar_71051 = (cppVar_71051 & cppMask_un_16_);
	cppVar_71052 = ROM.rd(cppVar_71051);
	cppVar_71054 = (cppVar_71052 == 153);
	if (cppVar_71054) {
	cppVar_71050 = SBUF;
	} else {
	cppVar_71056 = PC + 1;
	cppVar_71056 = (cppVar_71056 & cppMask_un_16_);
	cppVar_71057 = ROM.rd(cppVar_71056);
	cppVar_71059 = (cppVar_71057 == 160);
	if (cppVar_71059) {
	cppVar_71055 = P2;
	} else {
	cppVar_71061 = PC + 1;
	cppVar_71061 = (cppVar_71061 & cppMask_un_16_);
	cppVar_71062 = ROM.rd(cppVar_71061);
	cppVar_71064 = (cppVar_71062 == 168);
	if (cppVar_71064) {
	cppVar_71060 = IE;
	} else {
	cppVar_71066 = PC + 1;
	cppVar_71066 = (cppVar_71066 & cppMask_un_16_);
	cppVar_71067 = ROM.rd(cppVar_71066);
	cppVar_71069 = (cppVar_71067 == 176);
	if (cppVar_71069) {
	cppVar_71065 = P3;
	} else {
	cppVar_71071 = PC + 1;
	cppVar_71071 = (cppVar_71071 & cppMask_un_16_);
	cppVar_71072 = ROM.rd(cppVar_71071);
	cppVar_71074 = (cppVar_71072 == 184);
	if (cppVar_71074) {
	cppVar_71070 = IP;
	} else {
	cppVar_71076 = PC + 1;
	cppVar_71076 = (cppVar_71076 & cppMask_un_16_);
	cppVar_71077 = ROM.rd(cppVar_71076);
	cppVar_71079 = (cppVar_71077 == 208);
	if (cppVar_71079) {
	cppVar_71075 = PSW;
	} else {
	cppVar_71081 = PC + 1;
	cppVar_71081 = (cppVar_71081 & cppMask_un_16_);
	cppVar_71082 = ROM.rd(cppVar_71081);
	cppVar_71084 = (cppVar_71082 == 224);
	if (cppVar_71084) {
	cppVar_71080 = ACC;
	} else {
	cppVar_71086 = PC + 1;
	cppVar_71086 = (cppVar_71086 & cppMask_un_16_);
	cppVar_71087 = ROM.rd(cppVar_71086);
	cppVar_71089 = (cppVar_71087 == 240);
	if (cppVar_71089) {
	cppVar_71085 = B;
	} else {
	cppVar_71085 = 0;
	}
	cppVar_71080 = cppVar_71085;
	}
	cppVar_71075 = cppVar_71080;
	}
	cppVar_71070 = cppVar_71075;
	}
	cppVar_71065 = cppVar_71070;
	}
	cppVar_71060 = cppVar_71065;
	}
	cppVar_71055 = cppVar_71060;
	}
	cppVar_71050 = cppVar_71055;
	}
	cppVar_71045 = cppVar_71050;
	}
	cppVar_71040 = cppVar_71045;
	}
	cppVar_71035 = cppVar_71040;
	}
	cppVar_71030 = cppVar_71035;
	}
	cppVar_71025 = cppVar_71030;
	}
	cppVar_71020 = cppVar_71025;
	}
	cppVar_71015 = cppVar_71020;
	}
	cppVar_71010 = cppVar_71015;
	}
	cppVar_71005 = cppVar_71010;
	}
	cppVar_71000 = cppVar_71005;
	}
	cppVar_70995 = cppVar_71000;
	}
	cppVar_70990 = cppVar_70995;
	}
	cppVar_70985 = cppVar_70990;
	}
	cppVar_70976 = cppVar_70985;
	}
	cppVar_71092 = PC + 2;
	cppVar_71092 = (cppVar_71092 & cppMask_un_16_);
	cppVar_71093 = ROM.rd(cppVar_71092);
	cppVar_71094 = cppVar_70976 ^ cppVar_71093;
	cppVar_70970 = cppVar_71094;
	} else {
	cppVar_70970 = TCON;
	}
	cppVar_70966 = cppVar_70970;
	} else {
	cppVar_71096 = ROM.rd(PC);
	cppVar_71098 = (cppVar_71096 == 98);
	if (cppVar_71098) {
	cppVar_71101 = PC + 1;
	cppVar_71101 = (cppVar_71101 & cppMask_un_16_);
	cppVar_71102 = ROM.rd(cppVar_71101);
	cppVar_71104 = (cppVar_71102 == 136);
	if (cppVar_71104) {
	cppVar_71106 = PC + 1;
	cppVar_71106 = (cppVar_71106 & cppMask_un_16_);
	cppVar_71107 = ROM.rd(cppVar_71106);
	cppVar_71108 = (cppVar_71107 >> 7) & cppMask_un_1_;
	cppVar_71110 = (cppVar_71108 == 0);
	if (cppVar_71110) {
	cppVar_71111 = PC + 1;
	cppVar_71111 = (cppVar_71111 & cppMask_un_16_);
	cppVar_71112 = ROM.rd(cppVar_71111);
	cppVar_71113 = IRAM.rd(cppVar_71112);
	cppVar_71105 = cppVar_71113;
	} else {
	cppVar_71115 = PC + 1;
	cppVar_71115 = (cppVar_71115 & cppMask_un_16_);
	cppVar_71116 = ROM.rd(cppVar_71115);
	cppVar_71118 = (cppVar_71116 == 128);
	if (cppVar_71118) {
	cppVar_71114 = P0;
	} else {
	cppVar_71120 = PC + 1;
	cppVar_71120 = (cppVar_71120 & cppMask_un_16_);
	cppVar_71121 = ROM.rd(cppVar_71120);
	cppVar_71123 = (cppVar_71121 == 129);
	if (cppVar_71123) {
	cppVar_71119 = SP;
	} else {
	cppVar_71125 = PC + 1;
	cppVar_71125 = (cppVar_71125 & cppMask_un_16_);
	cppVar_71126 = ROM.rd(cppVar_71125);
	cppVar_71128 = (cppVar_71126 == 130);
	if (cppVar_71128) {
	cppVar_71124 = DPL;
	} else {
	cppVar_71130 = PC + 1;
	cppVar_71130 = (cppVar_71130 & cppMask_un_16_);
	cppVar_71131 = ROM.rd(cppVar_71130);
	cppVar_71133 = (cppVar_71131 == 131);
	if (cppVar_71133) {
	cppVar_71129 = DPH;
	} else {
	cppVar_71135 = PC + 1;
	cppVar_71135 = (cppVar_71135 & cppMask_un_16_);
	cppVar_71136 = ROM.rd(cppVar_71135);
	cppVar_71138 = (cppVar_71136 == 135);
	if (cppVar_71138) {
	cppVar_71134 = PCON;
	} else {
	cppVar_71140 = PC + 1;
	cppVar_71140 = (cppVar_71140 & cppMask_un_16_);
	cppVar_71141 = ROM.rd(cppVar_71140);
	cppVar_71143 = (cppVar_71141 == 136);
	if (cppVar_71143) {
	cppVar_71139 = TCON;
	} else {
	cppVar_71145 = PC + 1;
	cppVar_71145 = (cppVar_71145 & cppMask_un_16_);
	cppVar_71146 = ROM.rd(cppVar_71145);
	cppVar_71148 = (cppVar_71146 == 137);
	if (cppVar_71148) {
	cppVar_71144 = TMOD;
	} else {
	cppVar_71150 = PC + 1;
	cppVar_71150 = (cppVar_71150 & cppMask_un_16_);
	cppVar_71151 = ROM.rd(cppVar_71150);
	cppVar_71153 = (cppVar_71151 == 138);
	if (cppVar_71153) {
	cppVar_71149 = TL0;
	} else {
	cppVar_71155 = PC + 1;
	cppVar_71155 = (cppVar_71155 & cppMask_un_16_);
	cppVar_71156 = ROM.rd(cppVar_71155);
	cppVar_71158 = (cppVar_71156 == 140);
	if (cppVar_71158) {
	cppVar_71154 = TH0;
	} else {
	cppVar_71160 = PC + 1;
	cppVar_71160 = (cppVar_71160 & cppMask_un_16_);
	cppVar_71161 = ROM.rd(cppVar_71160);
	cppVar_71163 = (cppVar_71161 == 139);
	if (cppVar_71163) {
	cppVar_71159 = TL1;
	} else {
	cppVar_71165 = PC + 1;
	cppVar_71165 = (cppVar_71165 & cppMask_un_16_);
	cppVar_71166 = ROM.rd(cppVar_71165);
	cppVar_71168 = (cppVar_71166 == 141);
	if (cppVar_71168) {
	cppVar_71164 = TH1;
	} else {
	cppVar_71170 = PC + 1;
	cppVar_71170 = (cppVar_71170 & cppMask_un_16_);
	cppVar_71171 = ROM.rd(cppVar_71170);
	cppVar_71173 = (cppVar_71171 == 144);
	if (cppVar_71173) {
	cppVar_71169 = P1;
	} else {
	cppVar_71175 = PC + 1;
	cppVar_71175 = (cppVar_71175 & cppMask_un_16_);
	cppVar_71176 = ROM.rd(cppVar_71175);
	cppVar_71178 = (cppVar_71176 == 152);
	if (cppVar_71178) {
	cppVar_71174 = SCON;
	} else {
	cppVar_71180 = PC + 1;
	cppVar_71180 = (cppVar_71180 & cppMask_un_16_);
	cppVar_71181 = ROM.rd(cppVar_71180);
	cppVar_71183 = (cppVar_71181 == 153);
	if (cppVar_71183) {
	cppVar_71179 = SBUF;
	} else {
	cppVar_71185 = PC + 1;
	cppVar_71185 = (cppVar_71185 & cppMask_un_16_);
	cppVar_71186 = ROM.rd(cppVar_71185);
	cppVar_71188 = (cppVar_71186 == 160);
	if (cppVar_71188) {
	cppVar_71184 = P2;
	} else {
	cppVar_71190 = PC + 1;
	cppVar_71190 = (cppVar_71190 & cppMask_un_16_);
	cppVar_71191 = ROM.rd(cppVar_71190);
	cppVar_71193 = (cppVar_71191 == 168);
	if (cppVar_71193) {
	cppVar_71189 = IE;
	} else {
	cppVar_71195 = PC + 1;
	cppVar_71195 = (cppVar_71195 & cppMask_un_16_);
	cppVar_71196 = ROM.rd(cppVar_71195);
	cppVar_71198 = (cppVar_71196 == 176);
	if (cppVar_71198) {
	cppVar_71194 = P3;
	} else {
	cppVar_71200 = PC + 1;
	cppVar_71200 = (cppVar_71200 & cppMask_un_16_);
	cppVar_71201 = ROM.rd(cppVar_71200);
	cppVar_71203 = (cppVar_71201 == 184);
	if (cppVar_71203) {
	cppVar_71199 = IP;
	} else {
	cppVar_71205 = PC + 1;
	cppVar_71205 = (cppVar_71205 & cppMask_un_16_);
	cppVar_71206 = ROM.rd(cppVar_71205);
	cppVar_71208 = (cppVar_71206 == 208);
	if (cppVar_71208) {
	cppVar_71204 = PSW;
	} else {
	cppVar_71210 = PC + 1;
	cppVar_71210 = (cppVar_71210 & cppMask_un_16_);
	cppVar_71211 = ROM.rd(cppVar_71210);
	cppVar_71213 = (cppVar_71211 == 224);
	if (cppVar_71213) {
	cppVar_71209 = ACC;
	} else {
	cppVar_71215 = PC + 1;
	cppVar_71215 = (cppVar_71215 & cppMask_un_16_);
	cppVar_71216 = ROM.rd(cppVar_71215);
	cppVar_71218 = (cppVar_71216 == 240);
	if (cppVar_71218) {
	cppVar_71214 = B;
	} else {
	cppVar_71214 = 0;
	}
	cppVar_71209 = cppVar_71214;
	}
	cppVar_71204 = cppVar_71209;
	}
	cppVar_71199 = cppVar_71204;
	}
	cppVar_71194 = cppVar_71199;
	}
	cppVar_71189 = cppVar_71194;
	}
	cppVar_71184 = cppVar_71189;
	}
	cppVar_71179 = cppVar_71184;
	}
	cppVar_71174 = cppVar_71179;
	}
	cppVar_71169 = cppVar_71174;
	}
	cppVar_71164 = cppVar_71169;
	}
	cppVar_71159 = cppVar_71164;
	}
	cppVar_71154 = cppVar_71159;
	}
	cppVar_71149 = cppVar_71154;
	}
	cppVar_71144 = cppVar_71149;
	}
	cppVar_71139 = cppVar_71144;
	}
	cppVar_71134 = cppVar_71139;
	}
	cppVar_71129 = cppVar_71134;
	}
	cppVar_71124 = cppVar_71129;
	}
	cppVar_71119 = cppVar_71124;
	}
	cppVar_71114 = cppVar_71119;
	}
	cppVar_71105 = cppVar_71114;
	}
	cppVar_71220 = cppVar_71105 ^ ACC;
	cppVar_71099 = cppVar_71220;
	} else {
	cppVar_71099 = TCON;
	}
	cppVar_71095 = cppVar_71099;
	} else {
	cppVar_71222 = ROM.rd(PC);
	cppVar_71224 = (cppVar_71222 == 83);
	if (cppVar_71224) {
	cppVar_71227 = PC + 1;
	cppVar_71227 = (cppVar_71227 & cppMask_un_16_);
	cppVar_71228 = ROM.rd(cppVar_71227);
	cppVar_71230 = (cppVar_71228 == 136);
	if (cppVar_71230) {
	cppVar_71232 = PC + 1;
	cppVar_71232 = (cppVar_71232 & cppMask_un_16_);
	cppVar_71233 = ROM.rd(cppVar_71232);
	cppVar_71234 = (cppVar_71233 >> 7) & cppMask_un_1_;
	cppVar_71236 = (cppVar_71234 == 0);
	if (cppVar_71236) {
	cppVar_71237 = PC + 1;
	cppVar_71237 = (cppVar_71237 & cppMask_un_16_);
	cppVar_71238 = ROM.rd(cppVar_71237);
	cppVar_71239 = IRAM.rd(cppVar_71238);
	cppVar_71231 = cppVar_71239;
	} else {
	cppVar_71241 = PC + 1;
	cppVar_71241 = (cppVar_71241 & cppMask_un_16_);
	cppVar_71242 = ROM.rd(cppVar_71241);
	cppVar_71244 = (cppVar_71242 == 128);
	if (cppVar_71244) {
	cppVar_71240 = P0;
	} else {
	cppVar_71246 = PC + 1;
	cppVar_71246 = (cppVar_71246 & cppMask_un_16_);
	cppVar_71247 = ROM.rd(cppVar_71246);
	cppVar_71249 = (cppVar_71247 == 129);
	if (cppVar_71249) {
	cppVar_71245 = SP;
	} else {
	cppVar_71251 = PC + 1;
	cppVar_71251 = (cppVar_71251 & cppMask_un_16_);
	cppVar_71252 = ROM.rd(cppVar_71251);
	cppVar_71254 = (cppVar_71252 == 130);
	if (cppVar_71254) {
	cppVar_71250 = DPL;
	} else {
	cppVar_71256 = PC + 1;
	cppVar_71256 = (cppVar_71256 & cppMask_un_16_);
	cppVar_71257 = ROM.rd(cppVar_71256);
	cppVar_71259 = (cppVar_71257 == 131);
	if (cppVar_71259) {
	cppVar_71255 = DPH;
	} else {
	cppVar_71261 = PC + 1;
	cppVar_71261 = (cppVar_71261 & cppMask_un_16_);
	cppVar_71262 = ROM.rd(cppVar_71261);
	cppVar_71264 = (cppVar_71262 == 135);
	if (cppVar_71264) {
	cppVar_71260 = PCON;
	} else {
	cppVar_71266 = PC + 1;
	cppVar_71266 = (cppVar_71266 & cppMask_un_16_);
	cppVar_71267 = ROM.rd(cppVar_71266);
	cppVar_71269 = (cppVar_71267 == 136);
	if (cppVar_71269) {
	cppVar_71265 = TCON;
	} else {
	cppVar_71271 = PC + 1;
	cppVar_71271 = (cppVar_71271 & cppMask_un_16_);
	cppVar_71272 = ROM.rd(cppVar_71271);
	cppVar_71274 = (cppVar_71272 == 137);
	if (cppVar_71274) {
	cppVar_71270 = TMOD;
	} else {
	cppVar_71276 = PC + 1;
	cppVar_71276 = (cppVar_71276 & cppMask_un_16_);
	cppVar_71277 = ROM.rd(cppVar_71276);
	cppVar_71279 = (cppVar_71277 == 138);
	if (cppVar_71279) {
	cppVar_71275 = TL0;
	} else {
	cppVar_71281 = PC + 1;
	cppVar_71281 = (cppVar_71281 & cppMask_un_16_);
	cppVar_71282 = ROM.rd(cppVar_71281);
	cppVar_71284 = (cppVar_71282 == 140);
	if (cppVar_71284) {
	cppVar_71280 = TH0;
	} else {
	cppVar_71286 = PC + 1;
	cppVar_71286 = (cppVar_71286 & cppMask_un_16_);
	cppVar_71287 = ROM.rd(cppVar_71286);
	cppVar_71289 = (cppVar_71287 == 139);
	if (cppVar_71289) {
	cppVar_71285 = TL1;
	} else {
	cppVar_71291 = PC + 1;
	cppVar_71291 = (cppVar_71291 & cppMask_un_16_);
	cppVar_71292 = ROM.rd(cppVar_71291);
	cppVar_71294 = (cppVar_71292 == 141);
	if (cppVar_71294) {
	cppVar_71290 = TH1;
	} else {
	cppVar_71296 = PC + 1;
	cppVar_71296 = (cppVar_71296 & cppMask_un_16_);
	cppVar_71297 = ROM.rd(cppVar_71296);
	cppVar_71299 = (cppVar_71297 == 144);
	if (cppVar_71299) {
	cppVar_71295 = P1;
	} else {
	cppVar_71301 = PC + 1;
	cppVar_71301 = (cppVar_71301 & cppMask_un_16_);
	cppVar_71302 = ROM.rd(cppVar_71301);
	cppVar_71304 = (cppVar_71302 == 152);
	if (cppVar_71304) {
	cppVar_71300 = SCON;
	} else {
	cppVar_71306 = PC + 1;
	cppVar_71306 = (cppVar_71306 & cppMask_un_16_);
	cppVar_71307 = ROM.rd(cppVar_71306);
	cppVar_71309 = (cppVar_71307 == 153);
	if (cppVar_71309) {
	cppVar_71305 = SBUF;
	} else {
	cppVar_71311 = PC + 1;
	cppVar_71311 = (cppVar_71311 & cppMask_un_16_);
	cppVar_71312 = ROM.rd(cppVar_71311);
	cppVar_71314 = (cppVar_71312 == 160);
	if (cppVar_71314) {
	cppVar_71310 = P2;
	} else {
	cppVar_71316 = PC + 1;
	cppVar_71316 = (cppVar_71316 & cppMask_un_16_);
	cppVar_71317 = ROM.rd(cppVar_71316);
	cppVar_71319 = (cppVar_71317 == 168);
	if (cppVar_71319) {
	cppVar_71315 = IE;
	} else {
	cppVar_71321 = PC + 1;
	cppVar_71321 = (cppVar_71321 & cppMask_un_16_);
	cppVar_71322 = ROM.rd(cppVar_71321);
	cppVar_71324 = (cppVar_71322 == 176);
	if (cppVar_71324) {
	cppVar_71320 = P3;
	} else {
	cppVar_71326 = PC + 1;
	cppVar_71326 = (cppVar_71326 & cppMask_un_16_);
	cppVar_71327 = ROM.rd(cppVar_71326);
	cppVar_71329 = (cppVar_71327 == 184);
	if (cppVar_71329) {
	cppVar_71325 = IP;
	} else {
	cppVar_71331 = PC + 1;
	cppVar_71331 = (cppVar_71331 & cppMask_un_16_);
	cppVar_71332 = ROM.rd(cppVar_71331);
	cppVar_71334 = (cppVar_71332 == 208);
	if (cppVar_71334) {
	cppVar_71330 = PSW;
	} else {
	cppVar_71336 = PC + 1;
	cppVar_71336 = (cppVar_71336 & cppMask_un_16_);
	cppVar_71337 = ROM.rd(cppVar_71336);
	cppVar_71339 = (cppVar_71337 == 224);
	if (cppVar_71339) {
	cppVar_71335 = ACC;
	} else {
	cppVar_71341 = PC + 1;
	cppVar_71341 = (cppVar_71341 & cppMask_un_16_);
	cppVar_71342 = ROM.rd(cppVar_71341);
	cppVar_71344 = (cppVar_71342 == 240);
	if (cppVar_71344) {
	cppVar_71340 = B;
	} else {
	cppVar_71340 = 0;
	}
	cppVar_71335 = cppVar_71340;
	}
	cppVar_71330 = cppVar_71335;
	}
	cppVar_71325 = cppVar_71330;
	}
	cppVar_71320 = cppVar_71325;
	}
	cppVar_71315 = cppVar_71320;
	}
	cppVar_71310 = cppVar_71315;
	}
	cppVar_71305 = cppVar_71310;
	}
	cppVar_71300 = cppVar_71305;
	}
	cppVar_71295 = cppVar_71300;
	}
	cppVar_71290 = cppVar_71295;
	}
	cppVar_71285 = cppVar_71290;
	}
	cppVar_71280 = cppVar_71285;
	}
	cppVar_71275 = cppVar_71280;
	}
	cppVar_71270 = cppVar_71275;
	}
	cppVar_71265 = cppVar_71270;
	}
	cppVar_71260 = cppVar_71265;
	}
	cppVar_71255 = cppVar_71260;
	}
	cppVar_71250 = cppVar_71255;
	}
	cppVar_71245 = cppVar_71250;
	}
	cppVar_71240 = cppVar_71245;
	}
	cppVar_71231 = cppVar_71240;
	}
	cppVar_71347 = PC + 2;
	cppVar_71347 = (cppVar_71347 & cppMask_un_16_);
	cppVar_71348 = ROM.rd(cppVar_71347);
	cppVar_71349 = cppVar_71231 & cppVar_71348;
	cppVar_71225 = cppVar_71349;
	} else {
	cppVar_71225 = TCON;
	}
	cppVar_71221 = cppVar_71225;
	} else {
	cppVar_71351 = ROM.rd(PC);
	cppVar_71353 = (cppVar_71351 == 82);
	if (cppVar_71353) {
	cppVar_71356 = PC + 1;
	cppVar_71356 = (cppVar_71356 & cppMask_un_16_);
	cppVar_71357 = ROM.rd(cppVar_71356);
	cppVar_71359 = (cppVar_71357 == 136);
	if (cppVar_71359) {
	cppVar_71361 = PC + 1;
	cppVar_71361 = (cppVar_71361 & cppMask_un_16_);
	cppVar_71362 = ROM.rd(cppVar_71361);
	cppVar_71363 = (cppVar_71362 >> 7) & cppMask_un_1_;
	cppVar_71365 = (cppVar_71363 == 0);
	if (cppVar_71365) {
	cppVar_71366 = PC + 1;
	cppVar_71366 = (cppVar_71366 & cppMask_un_16_);
	cppVar_71367 = ROM.rd(cppVar_71366);
	cppVar_71368 = IRAM.rd(cppVar_71367);
	cppVar_71360 = cppVar_71368;
	} else {
	cppVar_71370 = PC + 1;
	cppVar_71370 = (cppVar_71370 & cppMask_un_16_);
	cppVar_71371 = ROM.rd(cppVar_71370);
	cppVar_71373 = (cppVar_71371 == 128);
	if (cppVar_71373) {
	cppVar_71369 = P0;
	} else {
	cppVar_71375 = PC + 1;
	cppVar_71375 = (cppVar_71375 & cppMask_un_16_);
	cppVar_71376 = ROM.rd(cppVar_71375);
	cppVar_71378 = (cppVar_71376 == 129);
	if (cppVar_71378) {
	cppVar_71374 = SP;
	} else {
	cppVar_71380 = PC + 1;
	cppVar_71380 = (cppVar_71380 & cppMask_un_16_);
	cppVar_71381 = ROM.rd(cppVar_71380);
	cppVar_71383 = (cppVar_71381 == 130);
	if (cppVar_71383) {
	cppVar_71379 = DPL;
	} else {
	cppVar_71385 = PC + 1;
	cppVar_71385 = (cppVar_71385 & cppMask_un_16_);
	cppVar_71386 = ROM.rd(cppVar_71385);
	cppVar_71388 = (cppVar_71386 == 131);
	if (cppVar_71388) {
	cppVar_71384 = DPH;
	} else {
	cppVar_71390 = PC + 1;
	cppVar_71390 = (cppVar_71390 & cppMask_un_16_);
	cppVar_71391 = ROM.rd(cppVar_71390);
	cppVar_71393 = (cppVar_71391 == 135);
	if (cppVar_71393) {
	cppVar_71389 = PCON;
	} else {
	cppVar_71395 = PC + 1;
	cppVar_71395 = (cppVar_71395 & cppMask_un_16_);
	cppVar_71396 = ROM.rd(cppVar_71395);
	cppVar_71398 = (cppVar_71396 == 136);
	if (cppVar_71398) {
	cppVar_71394 = TCON;
	} else {
	cppVar_71400 = PC + 1;
	cppVar_71400 = (cppVar_71400 & cppMask_un_16_);
	cppVar_71401 = ROM.rd(cppVar_71400);
	cppVar_71403 = (cppVar_71401 == 137);
	if (cppVar_71403) {
	cppVar_71399 = TMOD;
	} else {
	cppVar_71405 = PC + 1;
	cppVar_71405 = (cppVar_71405 & cppMask_un_16_);
	cppVar_71406 = ROM.rd(cppVar_71405);
	cppVar_71408 = (cppVar_71406 == 138);
	if (cppVar_71408) {
	cppVar_71404 = TL0;
	} else {
	cppVar_71410 = PC + 1;
	cppVar_71410 = (cppVar_71410 & cppMask_un_16_);
	cppVar_71411 = ROM.rd(cppVar_71410);
	cppVar_71413 = (cppVar_71411 == 140);
	if (cppVar_71413) {
	cppVar_71409 = TH0;
	} else {
	cppVar_71415 = PC + 1;
	cppVar_71415 = (cppVar_71415 & cppMask_un_16_);
	cppVar_71416 = ROM.rd(cppVar_71415);
	cppVar_71418 = (cppVar_71416 == 139);
	if (cppVar_71418) {
	cppVar_71414 = TL1;
	} else {
	cppVar_71420 = PC + 1;
	cppVar_71420 = (cppVar_71420 & cppMask_un_16_);
	cppVar_71421 = ROM.rd(cppVar_71420);
	cppVar_71423 = (cppVar_71421 == 141);
	if (cppVar_71423) {
	cppVar_71419 = TH1;
	} else {
	cppVar_71425 = PC + 1;
	cppVar_71425 = (cppVar_71425 & cppMask_un_16_);
	cppVar_71426 = ROM.rd(cppVar_71425);
	cppVar_71428 = (cppVar_71426 == 144);
	if (cppVar_71428) {
	cppVar_71424 = P1;
	} else {
	cppVar_71430 = PC + 1;
	cppVar_71430 = (cppVar_71430 & cppMask_un_16_);
	cppVar_71431 = ROM.rd(cppVar_71430);
	cppVar_71433 = (cppVar_71431 == 152);
	if (cppVar_71433) {
	cppVar_71429 = SCON;
	} else {
	cppVar_71435 = PC + 1;
	cppVar_71435 = (cppVar_71435 & cppMask_un_16_);
	cppVar_71436 = ROM.rd(cppVar_71435);
	cppVar_71438 = (cppVar_71436 == 153);
	if (cppVar_71438) {
	cppVar_71434 = SBUF;
	} else {
	cppVar_71440 = PC + 1;
	cppVar_71440 = (cppVar_71440 & cppMask_un_16_);
	cppVar_71441 = ROM.rd(cppVar_71440);
	cppVar_71443 = (cppVar_71441 == 160);
	if (cppVar_71443) {
	cppVar_71439 = P2;
	} else {
	cppVar_71445 = PC + 1;
	cppVar_71445 = (cppVar_71445 & cppMask_un_16_);
	cppVar_71446 = ROM.rd(cppVar_71445);
	cppVar_71448 = (cppVar_71446 == 168);
	if (cppVar_71448) {
	cppVar_71444 = IE;
	} else {
	cppVar_71450 = PC + 1;
	cppVar_71450 = (cppVar_71450 & cppMask_un_16_);
	cppVar_71451 = ROM.rd(cppVar_71450);
	cppVar_71453 = (cppVar_71451 == 176);
	if (cppVar_71453) {
	cppVar_71449 = P3;
	} else {
	cppVar_71455 = PC + 1;
	cppVar_71455 = (cppVar_71455 & cppMask_un_16_);
	cppVar_71456 = ROM.rd(cppVar_71455);
	cppVar_71458 = (cppVar_71456 == 184);
	if (cppVar_71458) {
	cppVar_71454 = IP;
	} else {
	cppVar_71460 = PC + 1;
	cppVar_71460 = (cppVar_71460 & cppMask_un_16_);
	cppVar_71461 = ROM.rd(cppVar_71460);
	cppVar_71463 = (cppVar_71461 == 208);
	if (cppVar_71463) {
	cppVar_71459 = PSW;
	} else {
	cppVar_71465 = PC + 1;
	cppVar_71465 = (cppVar_71465 & cppMask_un_16_);
	cppVar_71466 = ROM.rd(cppVar_71465);
	cppVar_71468 = (cppVar_71466 == 224);
	if (cppVar_71468) {
	cppVar_71464 = ACC;
	} else {
	cppVar_71470 = PC + 1;
	cppVar_71470 = (cppVar_71470 & cppMask_un_16_);
	cppVar_71471 = ROM.rd(cppVar_71470);
	cppVar_71473 = (cppVar_71471 == 240);
	if (cppVar_71473) {
	cppVar_71469 = B;
	} else {
	cppVar_71469 = 0;
	}
	cppVar_71464 = cppVar_71469;
	}
	cppVar_71459 = cppVar_71464;
	}
	cppVar_71454 = cppVar_71459;
	}
	cppVar_71449 = cppVar_71454;
	}
	cppVar_71444 = cppVar_71449;
	}
	cppVar_71439 = cppVar_71444;
	}
	cppVar_71434 = cppVar_71439;
	}
	cppVar_71429 = cppVar_71434;
	}
	cppVar_71424 = cppVar_71429;
	}
	cppVar_71419 = cppVar_71424;
	}
	cppVar_71414 = cppVar_71419;
	}
	cppVar_71409 = cppVar_71414;
	}
	cppVar_71404 = cppVar_71409;
	}
	cppVar_71399 = cppVar_71404;
	}
	cppVar_71394 = cppVar_71399;
	}
	cppVar_71389 = cppVar_71394;
	}
	cppVar_71384 = cppVar_71389;
	}
	cppVar_71379 = cppVar_71384;
	}
	cppVar_71374 = cppVar_71379;
	}
	cppVar_71369 = cppVar_71374;
	}
	cppVar_71360 = cppVar_71369;
	}
	cppVar_71475 = cppVar_71360 & ACC;
	cppVar_71354 = cppVar_71475;
	} else {
	cppVar_71354 = TCON;
	}
	cppVar_71350 = cppVar_71354;
	} else {
	cppVar_71477 = ROM.rd(PC);
	cppVar_71479 = (cppVar_71477 == 67);
	if (cppVar_71479) {
	cppVar_71482 = PC + 1;
	cppVar_71482 = (cppVar_71482 & cppMask_un_16_);
	cppVar_71483 = ROM.rd(cppVar_71482);
	cppVar_71485 = (cppVar_71483 == 136);
	if (cppVar_71485) {
	cppVar_71487 = PC + 1;
	cppVar_71487 = (cppVar_71487 & cppMask_un_16_);
	cppVar_71488 = ROM.rd(cppVar_71487);
	cppVar_71489 = (cppVar_71488 >> 7) & cppMask_un_1_;
	cppVar_71491 = (cppVar_71489 == 0);
	if (cppVar_71491) {
	cppVar_71492 = PC + 1;
	cppVar_71492 = (cppVar_71492 & cppMask_un_16_);
	cppVar_71493 = ROM.rd(cppVar_71492);
	cppVar_71494 = IRAM.rd(cppVar_71493);
	cppVar_71486 = cppVar_71494;
	} else {
	cppVar_71496 = PC + 1;
	cppVar_71496 = (cppVar_71496 & cppMask_un_16_);
	cppVar_71497 = ROM.rd(cppVar_71496);
	cppVar_71499 = (cppVar_71497 == 128);
	if (cppVar_71499) {
	cppVar_71495 = P0;
	} else {
	cppVar_71501 = PC + 1;
	cppVar_71501 = (cppVar_71501 & cppMask_un_16_);
	cppVar_71502 = ROM.rd(cppVar_71501);
	cppVar_71504 = (cppVar_71502 == 129);
	if (cppVar_71504) {
	cppVar_71500 = SP;
	} else {
	cppVar_71506 = PC + 1;
	cppVar_71506 = (cppVar_71506 & cppMask_un_16_);
	cppVar_71507 = ROM.rd(cppVar_71506);
	cppVar_71509 = (cppVar_71507 == 130);
	if (cppVar_71509) {
	cppVar_71505 = DPL;
	} else {
	cppVar_71511 = PC + 1;
	cppVar_71511 = (cppVar_71511 & cppMask_un_16_);
	cppVar_71512 = ROM.rd(cppVar_71511);
	cppVar_71514 = (cppVar_71512 == 131);
	if (cppVar_71514) {
	cppVar_71510 = DPH;
	} else {
	cppVar_71516 = PC + 1;
	cppVar_71516 = (cppVar_71516 & cppMask_un_16_);
	cppVar_71517 = ROM.rd(cppVar_71516);
	cppVar_71519 = (cppVar_71517 == 135);
	if (cppVar_71519) {
	cppVar_71515 = PCON;
	} else {
	cppVar_71521 = PC + 1;
	cppVar_71521 = (cppVar_71521 & cppMask_un_16_);
	cppVar_71522 = ROM.rd(cppVar_71521);
	cppVar_71524 = (cppVar_71522 == 136);
	if (cppVar_71524) {
	cppVar_71520 = TCON;
	} else {
	cppVar_71526 = PC + 1;
	cppVar_71526 = (cppVar_71526 & cppMask_un_16_);
	cppVar_71527 = ROM.rd(cppVar_71526);
	cppVar_71529 = (cppVar_71527 == 137);
	if (cppVar_71529) {
	cppVar_71525 = TMOD;
	} else {
	cppVar_71531 = PC + 1;
	cppVar_71531 = (cppVar_71531 & cppMask_un_16_);
	cppVar_71532 = ROM.rd(cppVar_71531);
	cppVar_71534 = (cppVar_71532 == 138);
	if (cppVar_71534) {
	cppVar_71530 = TL0;
	} else {
	cppVar_71536 = PC + 1;
	cppVar_71536 = (cppVar_71536 & cppMask_un_16_);
	cppVar_71537 = ROM.rd(cppVar_71536);
	cppVar_71539 = (cppVar_71537 == 140);
	if (cppVar_71539) {
	cppVar_71535 = TH0;
	} else {
	cppVar_71541 = PC + 1;
	cppVar_71541 = (cppVar_71541 & cppMask_un_16_);
	cppVar_71542 = ROM.rd(cppVar_71541);
	cppVar_71544 = (cppVar_71542 == 139);
	if (cppVar_71544) {
	cppVar_71540 = TL1;
	} else {
	cppVar_71546 = PC + 1;
	cppVar_71546 = (cppVar_71546 & cppMask_un_16_);
	cppVar_71547 = ROM.rd(cppVar_71546);
	cppVar_71549 = (cppVar_71547 == 141);
	if (cppVar_71549) {
	cppVar_71545 = TH1;
	} else {
	cppVar_71551 = PC + 1;
	cppVar_71551 = (cppVar_71551 & cppMask_un_16_);
	cppVar_71552 = ROM.rd(cppVar_71551);
	cppVar_71554 = (cppVar_71552 == 144);
	if (cppVar_71554) {
	cppVar_71550 = P1;
	} else {
	cppVar_71556 = PC + 1;
	cppVar_71556 = (cppVar_71556 & cppMask_un_16_);
	cppVar_71557 = ROM.rd(cppVar_71556);
	cppVar_71559 = (cppVar_71557 == 152);
	if (cppVar_71559) {
	cppVar_71555 = SCON;
	} else {
	cppVar_71561 = PC + 1;
	cppVar_71561 = (cppVar_71561 & cppMask_un_16_);
	cppVar_71562 = ROM.rd(cppVar_71561);
	cppVar_71564 = (cppVar_71562 == 153);
	if (cppVar_71564) {
	cppVar_71560 = SBUF;
	} else {
	cppVar_71566 = PC + 1;
	cppVar_71566 = (cppVar_71566 & cppMask_un_16_);
	cppVar_71567 = ROM.rd(cppVar_71566);
	cppVar_71569 = (cppVar_71567 == 160);
	if (cppVar_71569) {
	cppVar_71565 = P2;
	} else {
	cppVar_71571 = PC + 1;
	cppVar_71571 = (cppVar_71571 & cppMask_un_16_);
	cppVar_71572 = ROM.rd(cppVar_71571);
	cppVar_71574 = (cppVar_71572 == 168);
	if (cppVar_71574) {
	cppVar_71570 = IE;
	} else {
	cppVar_71576 = PC + 1;
	cppVar_71576 = (cppVar_71576 & cppMask_un_16_);
	cppVar_71577 = ROM.rd(cppVar_71576);
	cppVar_71579 = (cppVar_71577 == 176);
	if (cppVar_71579) {
	cppVar_71575 = P3;
	} else {
	cppVar_71581 = PC + 1;
	cppVar_71581 = (cppVar_71581 & cppMask_un_16_);
	cppVar_71582 = ROM.rd(cppVar_71581);
	cppVar_71584 = (cppVar_71582 == 184);
	if (cppVar_71584) {
	cppVar_71580 = IP;
	} else {
	cppVar_71586 = PC + 1;
	cppVar_71586 = (cppVar_71586 & cppMask_un_16_);
	cppVar_71587 = ROM.rd(cppVar_71586);
	cppVar_71589 = (cppVar_71587 == 208);
	if (cppVar_71589) {
	cppVar_71585 = PSW;
	} else {
	cppVar_71591 = PC + 1;
	cppVar_71591 = (cppVar_71591 & cppMask_un_16_);
	cppVar_71592 = ROM.rd(cppVar_71591);
	cppVar_71594 = (cppVar_71592 == 224);
	if (cppVar_71594) {
	cppVar_71590 = ACC;
	} else {
	cppVar_71596 = PC + 1;
	cppVar_71596 = (cppVar_71596 & cppMask_un_16_);
	cppVar_71597 = ROM.rd(cppVar_71596);
	cppVar_71599 = (cppVar_71597 == 240);
	if (cppVar_71599) {
	cppVar_71595 = B;
	} else {
	cppVar_71595 = 0;
	}
	cppVar_71590 = cppVar_71595;
	}
	cppVar_71585 = cppVar_71590;
	}
	cppVar_71580 = cppVar_71585;
	}
	cppVar_71575 = cppVar_71580;
	}
	cppVar_71570 = cppVar_71575;
	}
	cppVar_71565 = cppVar_71570;
	}
	cppVar_71560 = cppVar_71565;
	}
	cppVar_71555 = cppVar_71560;
	}
	cppVar_71550 = cppVar_71555;
	}
	cppVar_71545 = cppVar_71550;
	}
	cppVar_71540 = cppVar_71545;
	}
	cppVar_71535 = cppVar_71540;
	}
	cppVar_71530 = cppVar_71535;
	}
	cppVar_71525 = cppVar_71530;
	}
	cppVar_71520 = cppVar_71525;
	}
	cppVar_71515 = cppVar_71520;
	}
	cppVar_71510 = cppVar_71515;
	}
	cppVar_71505 = cppVar_71510;
	}
	cppVar_71500 = cppVar_71505;
	}
	cppVar_71495 = cppVar_71500;
	}
	cppVar_71486 = cppVar_71495;
	}
	cppVar_71602 = PC + 2;
	cppVar_71602 = (cppVar_71602 & cppMask_un_16_);
	cppVar_71603 = ROM.rd(cppVar_71602);
	cppVar_71604 = cppVar_71486 | cppVar_71603;
	cppVar_71480 = cppVar_71604;
	} else {
	cppVar_71480 = TCON;
	}
	cppVar_71476 = cppVar_71480;
	} else {
	cppVar_71606 = ROM.rd(PC);
	cppVar_71608 = (cppVar_71606 == 66);
	if (cppVar_71608) {
	cppVar_71611 = PC + 1;
	cppVar_71611 = (cppVar_71611 & cppMask_un_16_);
	cppVar_71612 = ROM.rd(cppVar_71611);
	cppVar_71614 = (cppVar_71612 == 136);
	if (cppVar_71614) {
	cppVar_71616 = PC + 1;
	cppVar_71616 = (cppVar_71616 & cppMask_un_16_);
	cppVar_71617 = ROM.rd(cppVar_71616);
	cppVar_71618 = (cppVar_71617 >> 7) & cppMask_un_1_;
	cppVar_71620 = (cppVar_71618 == 0);
	if (cppVar_71620) {
	cppVar_71621 = PC + 1;
	cppVar_71621 = (cppVar_71621 & cppMask_un_16_);
	cppVar_71622 = ROM.rd(cppVar_71621);
	cppVar_71623 = IRAM.rd(cppVar_71622);
	cppVar_71615 = cppVar_71623;
	} else {
	cppVar_71625 = PC + 1;
	cppVar_71625 = (cppVar_71625 & cppMask_un_16_);
	cppVar_71626 = ROM.rd(cppVar_71625);
	cppVar_71628 = (cppVar_71626 == 128);
	if (cppVar_71628) {
	cppVar_71624 = P0;
	} else {
	cppVar_71630 = PC + 1;
	cppVar_71630 = (cppVar_71630 & cppMask_un_16_);
	cppVar_71631 = ROM.rd(cppVar_71630);
	cppVar_71633 = (cppVar_71631 == 129);
	if (cppVar_71633) {
	cppVar_71629 = SP;
	} else {
	cppVar_71635 = PC + 1;
	cppVar_71635 = (cppVar_71635 & cppMask_un_16_);
	cppVar_71636 = ROM.rd(cppVar_71635);
	cppVar_71638 = (cppVar_71636 == 130);
	if (cppVar_71638) {
	cppVar_71634 = DPL;
	} else {
	cppVar_71640 = PC + 1;
	cppVar_71640 = (cppVar_71640 & cppMask_un_16_);
	cppVar_71641 = ROM.rd(cppVar_71640);
	cppVar_71643 = (cppVar_71641 == 131);
	if (cppVar_71643) {
	cppVar_71639 = DPH;
	} else {
	cppVar_71645 = PC + 1;
	cppVar_71645 = (cppVar_71645 & cppMask_un_16_);
	cppVar_71646 = ROM.rd(cppVar_71645);
	cppVar_71648 = (cppVar_71646 == 135);
	if (cppVar_71648) {
	cppVar_71644 = PCON;
	} else {
	cppVar_71650 = PC + 1;
	cppVar_71650 = (cppVar_71650 & cppMask_un_16_);
	cppVar_71651 = ROM.rd(cppVar_71650);
	cppVar_71653 = (cppVar_71651 == 136);
	if (cppVar_71653) {
	cppVar_71649 = TCON;
	} else {
	cppVar_71655 = PC + 1;
	cppVar_71655 = (cppVar_71655 & cppMask_un_16_);
	cppVar_71656 = ROM.rd(cppVar_71655);
	cppVar_71658 = (cppVar_71656 == 137);
	if (cppVar_71658) {
	cppVar_71654 = TMOD;
	} else {
	cppVar_71660 = PC + 1;
	cppVar_71660 = (cppVar_71660 & cppMask_un_16_);
	cppVar_71661 = ROM.rd(cppVar_71660);
	cppVar_71663 = (cppVar_71661 == 138);
	if (cppVar_71663) {
	cppVar_71659 = TL0;
	} else {
	cppVar_71665 = PC + 1;
	cppVar_71665 = (cppVar_71665 & cppMask_un_16_);
	cppVar_71666 = ROM.rd(cppVar_71665);
	cppVar_71668 = (cppVar_71666 == 140);
	if (cppVar_71668) {
	cppVar_71664 = TH0;
	} else {
	cppVar_71670 = PC + 1;
	cppVar_71670 = (cppVar_71670 & cppMask_un_16_);
	cppVar_71671 = ROM.rd(cppVar_71670);
	cppVar_71673 = (cppVar_71671 == 139);
	if (cppVar_71673) {
	cppVar_71669 = TL1;
	} else {
	cppVar_71675 = PC + 1;
	cppVar_71675 = (cppVar_71675 & cppMask_un_16_);
	cppVar_71676 = ROM.rd(cppVar_71675);
	cppVar_71678 = (cppVar_71676 == 141);
	if (cppVar_71678) {
	cppVar_71674 = TH1;
	} else {
	cppVar_71680 = PC + 1;
	cppVar_71680 = (cppVar_71680 & cppMask_un_16_);
	cppVar_71681 = ROM.rd(cppVar_71680);
	cppVar_71683 = (cppVar_71681 == 144);
	if (cppVar_71683) {
	cppVar_71679 = P1;
	} else {
	cppVar_71685 = PC + 1;
	cppVar_71685 = (cppVar_71685 & cppMask_un_16_);
	cppVar_71686 = ROM.rd(cppVar_71685);
	cppVar_71688 = (cppVar_71686 == 152);
	if (cppVar_71688) {
	cppVar_71684 = SCON;
	} else {
	cppVar_71690 = PC + 1;
	cppVar_71690 = (cppVar_71690 & cppMask_un_16_);
	cppVar_71691 = ROM.rd(cppVar_71690);
	cppVar_71693 = (cppVar_71691 == 153);
	if (cppVar_71693) {
	cppVar_71689 = SBUF;
	} else {
	cppVar_71695 = PC + 1;
	cppVar_71695 = (cppVar_71695 & cppMask_un_16_);
	cppVar_71696 = ROM.rd(cppVar_71695);
	cppVar_71698 = (cppVar_71696 == 160);
	if (cppVar_71698) {
	cppVar_71694 = P2;
	} else {
	cppVar_71700 = PC + 1;
	cppVar_71700 = (cppVar_71700 & cppMask_un_16_);
	cppVar_71701 = ROM.rd(cppVar_71700);
	cppVar_71703 = (cppVar_71701 == 168);
	if (cppVar_71703) {
	cppVar_71699 = IE;
	} else {
	cppVar_71705 = PC + 1;
	cppVar_71705 = (cppVar_71705 & cppMask_un_16_);
	cppVar_71706 = ROM.rd(cppVar_71705);
	cppVar_71708 = (cppVar_71706 == 176);
	if (cppVar_71708) {
	cppVar_71704 = P3;
	} else {
	cppVar_71710 = PC + 1;
	cppVar_71710 = (cppVar_71710 & cppMask_un_16_);
	cppVar_71711 = ROM.rd(cppVar_71710);
	cppVar_71713 = (cppVar_71711 == 184);
	if (cppVar_71713) {
	cppVar_71709 = IP;
	} else {
	cppVar_71715 = PC + 1;
	cppVar_71715 = (cppVar_71715 & cppMask_un_16_);
	cppVar_71716 = ROM.rd(cppVar_71715);
	cppVar_71718 = (cppVar_71716 == 208);
	if (cppVar_71718) {
	cppVar_71714 = PSW;
	} else {
	cppVar_71720 = PC + 1;
	cppVar_71720 = (cppVar_71720 & cppMask_un_16_);
	cppVar_71721 = ROM.rd(cppVar_71720);
	cppVar_71723 = (cppVar_71721 == 224);
	if (cppVar_71723) {
	cppVar_71719 = ACC;
	} else {
	cppVar_71725 = PC + 1;
	cppVar_71725 = (cppVar_71725 & cppMask_un_16_);
	cppVar_71726 = ROM.rd(cppVar_71725);
	cppVar_71728 = (cppVar_71726 == 240);
	if (cppVar_71728) {
	cppVar_71724 = B;
	} else {
	cppVar_71724 = 0;
	}
	cppVar_71719 = cppVar_71724;
	}
	cppVar_71714 = cppVar_71719;
	}
	cppVar_71709 = cppVar_71714;
	}
	cppVar_71704 = cppVar_71709;
	}
	cppVar_71699 = cppVar_71704;
	}
	cppVar_71694 = cppVar_71699;
	}
	cppVar_71689 = cppVar_71694;
	}
	cppVar_71684 = cppVar_71689;
	}
	cppVar_71679 = cppVar_71684;
	}
	cppVar_71674 = cppVar_71679;
	}
	cppVar_71669 = cppVar_71674;
	}
	cppVar_71664 = cppVar_71669;
	}
	cppVar_71659 = cppVar_71664;
	}
	cppVar_71654 = cppVar_71659;
	}
	cppVar_71649 = cppVar_71654;
	}
	cppVar_71644 = cppVar_71649;
	}
	cppVar_71639 = cppVar_71644;
	}
	cppVar_71634 = cppVar_71639;
	}
	cppVar_71629 = cppVar_71634;
	}
	cppVar_71624 = cppVar_71629;
	}
	cppVar_71615 = cppVar_71624;
	}
	cppVar_71730 = cppVar_71615 | ACC;
	cppVar_71609 = cppVar_71730;
	} else {
	cppVar_71609 = TCON;
	}
	cppVar_71605 = cppVar_71609;
	} else {
	cppVar_71732 = ROM.rd(PC);
	cppVar_71734 = (cppVar_71732 == 213);
	cppVar_71735 = ROM.rd(PC);
	cppVar_71737 = (cppVar_71735 == 21);
	cppVar_71738 = cppVar_71734 || cppVar_71737;
	if (cppVar_71738) {
	cppVar_71741 = PC + 1;
	cppVar_71741 = (cppVar_71741 & cppMask_un_16_);
	cppVar_71742 = ROM.rd(cppVar_71741);
	cppVar_71744 = (cppVar_71742 == 136);
	if (cppVar_71744) {
	cppVar_71746 = PC + 1;
	cppVar_71746 = (cppVar_71746 & cppMask_un_16_);
	cppVar_71747 = ROM.rd(cppVar_71746);
	cppVar_71748 = (cppVar_71747 >> 7) & cppMask_un_1_;
	cppVar_71750 = (cppVar_71748 == 0);
	if (cppVar_71750) {
	cppVar_71751 = PC + 1;
	cppVar_71751 = (cppVar_71751 & cppMask_un_16_);
	cppVar_71752 = ROM.rd(cppVar_71751);
	cppVar_71753 = IRAM.rd(cppVar_71752);
	cppVar_71745 = cppVar_71753;
	} else {
	cppVar_71755 = PC + 1;
	cppVar_71755 = (cppVar_71755 & cppMask_un_16_);
	cppVar_71756 = ROM.rd(cppVar_71755);
	cppVar_71758 = (cppVar_71756 == 128);
	if (cppVar_71758) {
	cppVar_71754 = P0;
	} else {
	cppVar_71760 = PC + 1;
	cppVar_71760 = (cppVar_71760 & cppMask_un_16_);
	cppVar_71761 = ROM.rd(cppVar_71760);
	cppVar_71763 = (cppVar_71761 == 129);
	if (cppVar_71763) {
	cppVar_71759 = SP;
	} else {
	cppVar_71765 = PC + 1;
	cppVar_71765 = (cppVar_71765 & cppMask_un_16_);
	cppVar_71766 = ROM.rd(cppVar_71765);
	cppVar_71768 = (cppVar_71766 == 130);
	if (cppVar_71768) {
	cppVar_71764 = DPL;
	} else {
	cppVar_71770 = PC + 1;
	cppVar_71770 = (cppVar_71770 & cppMask_un_16_);
	cppVar_71771 = ROM.rd(cppVar_71770);
	cppVar_71773 = (cppVar_71771 == 131);
	if (cppVar_71773) {
	cppVar_71769 = DPH;
	} else {
	cppVar_71775 = PC + 1;
	cppVar_71775 = (cppVar_71775 & cppMask_un_16_);
	cppVar_71776 = ROM.rd(cppVar_71775);
	cppVar_71778 = (cppVar_71776 == 135);
	if (cppVar_71778) {
	cppVar_71774 = PCON;
	} else {
	cppVar_71780 = PC + 1;
	cppVar_71780 = (cppVar_71780 & cppMask_un_16_);
	cppVar_71781 = ROM.rd(cppVar_71780);
	cppVar_71783 = (cppVar_71781 == 136);
	if (cppVar_71783) {
	cppVar_71779 = TCON;
	} else {
	cppVar_71785 = PC + 1;
	cppVar_71785 = (cppVar_71785 & cppMask_un_16_);
	cppVar_71786 = ROM.rd(cppVar_71785);
	cppVar_71788 = (cppVar_71786 == 137);
	if (cppVar_71788) {
	cppVar_71784 = TMOD;
	} else {
	cppVar_71790 = PC + 1;
	cppVar_71790 = (cppVar_71790 & cppMask_un_16_);
	cppVar_71791 = ROM.rd(cppVar_71790);
	cppVar_71793 = (cppVar_71791 == 138);
	if (cppVar_71793) {
	cppVar_71789 = TL0;
	} else {
	cppVar_71795 = PC + 1;
	cppVar_71795 = (cppVar_71795 & cppMask_un_16_);
	cppVar_71796 = ROM.rd(cppVar_71795);
	cppVar_71798 = (cppVar_71796 == 140);
	if (cppVar_71798) {
	cppVar_71794 = TH0;
	} else {
	cppVar_71800 = PC + 1;
	cppVar_71800 = (cppVar_71800 & cppMask_un_16_);
	cppVar_71801 = ROM.rd(cppVar_71800);
	cppVar_71803 = (cppVar_71801 == 139);
	if (cppVar_71803) {
	cppVar_71799 = TL1;
	} else {
	cppVar_71805 = PC + 1;
	cppVar_71805 = (cppVar_71805 & cppMask_un_16_);
	cppVar_71806 = ROM.rd(cppVar_71805);
	cppVar_71808 = (cppVar_71806 == 141);
	if (cppVar_71808) {
	cppVar_71804 = TH1;
	} else {
	cppVar_71810 = PC + 1;
	cppVar_71810 = (cppVar_71810 & cppMask_un_16_);
	cppVar_71811 = ROM.rd(cppVar_71810);
	cppVar_71813 = (cppVar_71811 == 144);
	if (cppVar_71813) {
	cppVar_71809 = P1;
	} else {
	cppVar_71815 = PC + 1;
	cppVar_71815 = (cppVar_71815 & cppMask_un_16_);
	cppVar_71816 = ROM.rd(cppVar_71815);
	cppVar_71818 = (cppVar_71816 == 152);
	if (cppVar_71818) {
	cppVar_71814 = SCON;
	} else {
	cppVar_71820 = PC + 1;
	cppVar_71820 = (cppVar_71820 & cppMask_un_16_);
	cppVar_71821 = ROM.rd(cppVar_71820);
	cppVar_71823 = (cppVar_71821 == 153);
	if (cppVar_71823) {
	cppVar_71819 = SBUF;
	} else {
	cppVar_71825 = PC + 1;
	cppVar_71825 = (cppVar_71825 & cppMask_un_16_);
	cppVar_71826 = ROM.rd(cppVar_71825);
	cppVar_71828 = (cppVar_71826 == 160);
	if (cppVar_71828) {
	cppVar_71824 = P2;
	} else {
	cppVar_71830 = PC + 1;
	cppVar_71830 = (cppVar_71830 & cppMask_un_16_);
	cppVar_71831 = ROM.rd(cppVar_71830);
	cppVar_71833 = (cppVar_71831 == 168);
	if (cppVar_71833) {
	cppVar_71829 = IE;
	} else {
	cppVar_71835 = PC + 1;
	cppVar_71835 = (cppVar_71835 & cppMask_un_16_);
	cppVar_71836 = ROM.rd(cppVar_71835);
	cppVar_71838 = (cppVar_71836 == 176);
	if (cppVar_71838) {
	cppVar_71834 = P3;
	} else {
	cppVar_71840 = PC + 1;
	cppVar_71840 = (cppVar_71840 & cppMask_un_16_);
	cppVar_71841 = ROM.rd(cppVar_71840);
	cppVar_71843 = (cppVar_71841 == 184);
	if (cppVar_71843) {
	cppVar_71839 = IP;
	} else {
	cppVar_71845 = PC + 1;
	cppVar_71845 = (cppVar_71845 & cppMask_un_16_);
	cppVar_71846 = ROM.rd(cppVar_71845);
	cppVar_71848 = (cppVar_71846 == 208);
	if (cppVar_71848) {
	cppVar_71844 = PSW;
	} else {
	cppVar_71850 = PC + 1;
	cppVar_71850 = (cppVar_71850 & cppMask_un_16_);
	cppVar_71851 = ROM.rd(cppVar_71850);
	cppVar_71853 = (cppVar_71851 == 224);
	if (cppVar_71853) {
	cppVar_71849 = ACC;
	} else {
	cppVar_71855 = PC + 1;
	cppVar_71855 = (cppVar_71855 & cppMask_un_16_);
	cppVar_71856 = ROM.rd(cppVar_71855);
	cppVar_71858 = (cppVar_71856 == 240);
	if (cppVar_71858) {
	cppVar_71854 = B;
	} else {
	cppVar_71854 = 0;
	}
	cppVar_71849 = cppVar_71854;
	}
	cppVar_71844 = cppVar_71849;
	}
	cppVar_71839 = cppVar_71844;
	}
	cppVar_71834 = cppVar_71839;
	}
	cppVar_71829 = cppVar_71834;
	}
	cppVar_71824 = cppVar_71829;
	}
	cppVar_71819 = cppVar_71824;
	}
	cppVar_71814 = cppVar_71819;
	}
	cppVar_71809 = cppVar_71814;
	}
	cppVar_71804 = cppVar_71809;
	}
	cppVar_71799 = cppVar_71804;
	}
	cppVar_71794 = cppVar_71799;
	}
	cppVar_71789 = cppVar_71794;
	}
	cppVar_71784 = cppVar_71789;
	}
	cppVar_71779 = cppVar_71784;
	}
	cppVar_71774 = cppVar_71779;
	}
	cppVar_71769 = cppVar_71774;
	}
	cppVar_71764 = cppVar_71769;
	}
	cppVar_71759 = cppVar_71764;
	}
	cppVar_71754 = cppVar_71759;
	}
	cppVar_71745 = cppVar_71754;
	}
	cppVar_71861 = cppVar_71745 - 1;
	cppVar_71861 = (cppVar_71861 & cppMask_un_8_);
	cppVar_71739 = cppVar_71861;
	} else {
	cppVar_71739 = TCON;
	}
	cppVar_71731 = cppVar_71739;
	} else {
	cppVar_71863 = ROM.rd(PC);
	cppVar_71865 = (cppVar_71863 == 194);
	cppVar_71866 = ROM.rd(PC);
	cppVar_71868 = (cppVar_71866 == 16);
	cppVar_71869 = cppVar_71865 || cppVar_71868;
	if (cppVar_71869) {
	cppVar_71873 = PC + 1;
	cppVar_71873 = (cppVar_71873 & cppMask_un_16_);
	cppVar_71874 = ROM.rd(cppVar_71873);
	cppVar_71875 = (cppVar_71874 >> 7) & cppMask_un_1_;
	cppVar_71877 = (cppVar_71875 == 1);
	if (cppVar_71877) {
	cppVar_71878 = PC + 1;
	cppVar_71878 = (cppVar_71878 & cppMask_un_16_);
	cppVar_71879 = ROM.rd(cppVar_71878);
	cppVar_71880 = (cppVar_71879 >> 3) & cppMask_un_5_;
	cppVar_71882 = (cppVar_71880 << 3) | 0;
	cppVar_71882 = (cppVar_71882 & cppMask_un_8_);
	cppVar_71871 = cppVar_71882;
	} else {
	cppVar_71883 = PC + 1;
	cppVar_71883 = (cppVar_71883 & cppMask_un_16_);
	cppVar_71884 = ROM.rd(cppVar_71883);
	cppVar_71885 = (cppVar_71884 >> 3) & cppMask_un_5_;
	cppVar_71886 = (cppVar_71885 & cppMask_un_5_);
	cppVar_71888 = cppVar_71886 + 32;
	cppVar_71888 = (cppVar_71888 & cppMask_un_8_);
	cppVar_71871 = cppVar_71888;
	}
	cppVar_71890 = (cppVar_71871 == 136);
	if (cppVar_71890) {
	cppVar_71892 = PC + 1;
	cppVar_71892 = (cppVar_71892 & cppMask_un_16_);
	cppVar_71893 = ROM.rd(cppVar_71892);
	cppVar_71894 = (cppVar_71893 >> 0) & cppMask_un_3_;
	cppVar_71895 = (cppVar_71894 & cppMask_un_3_);
	cppVar_71896 = 1 << static_cast<unsigned>(cppVar_71895);
	cppVar_71896 = (cppVar_71896 & cppMask_un_8_);
	cppVar_71897 = ~cppVar_71896;
	cppVar_71900 = PC + 1;
	cppVar_71900 = (cppVar_71900 & cppMask_un_16_);
	cppVar_71901 = ROM.rd(cppVar_71900);
	cppVar_71902 = (cppVar_71901 >> 7) & cppMask_un_1_;
	cppVar_71903 = (cppVar_71902 == 1);
	if (cppVar_71903) {
	cppVar_71904 = PC + 1;
	cppVar_71904 = (cppVar_71904 & cppMask_un_16_);
	cppVar_71905 = ROM.rd(cppVar_71904);
	cppVar_71906 = (cppVar_71905 >> 3) & cppMask_un_5_;
	cppVar_71907 = (cppVar_71906 << 3) | 0;
	cppVar_71907 = (cppVar_71907 & cppMask_un_8_);
	cppVar_71899 = cppVar_71907;
	} else {
	cppVar_71908 = PC + 1;
	cppVar_71908 = (cppVar_71908 & cppMask_un_16_);
	cppVar_71909 = ROM.rd(cppVar_71908);
	cppVar_71910 = (cppVar_71909 >> 3) & cppMask_un_5_;
	cppVar_71911 = (cppVar_71910 & cppMask_un_5_);
	cppVar_71912 = cppVar_71911 + 32;
	cppVar_71912 = (cppVar_71912 & cppMask_un_8_);
	cppVar_71899 = cppVar_71912;
	}
	cppVar_71913 = (cppVar_71899 >> 7) & cppMask_un_1_;
	cppVar_71915 = (cppVar_71913 == 0);
	if (cppVar_71915) {
	cppVar_71917 = PC + 1;
	cppVar_71917 = (cppVar_71917 & cppMask_un_16_);
	cppVar_71918 = ROM.rd(cppVar_71917);
	cppVar_71919 = (cppVar_71918 >> 7) & cppMask_un_1_;
	cppVar_71920 = (cppVar_71919 == 1);
	if (cppVar_71920) {
	cppVar_71921 = PC + 1;
	cppVar_71921 = (cppVar_71921 & cppMask_un_16_);
	cppVar_71922 = ROM.rd(cppVar_71921);
	cppVar_71923 = (cppVar_71922 >> 3) & cppMask_un_5_;
	cppVar_71924 = (cppVar_71923 << 3) | 0;
	cppVar_71924 = (cppVar_71924 & cppMask_un_8_);
	cppVar_71916 = cppVar_71924;
	} else {
	cppVar_71925 = PC + 1;
	cppVar_71925 = (cppVar_71925 & cppMask_un_16_);
	cppVar_71926 = ROM.rd(cppVar_71925);
	cppVar_71927 = (cppVar_71926 >> 3) & cppMask_un_5_;
	cppVar_71928 = (cppVar_71927 & cppMask_un_5_);
	cppVar_71929 = cppVar_71928 + 32;
	cppVar_71929 = (cppVar_71929 & cppMask_un_8_);
	cppVar_71916 = cppVar_71929;
	}
	cppVar_71930 = IRAM.rd(cppVar_71916);
	cppVar_71898 = cppVar_71930;
	} else {
	cppVar_71933 = PC + 1;
	cppVar_71933 = (cppVar_71933 & cppMask_un_16_);
	cppVar_71934 = ROM.rd(cppVar_71933);
	cppVar_71935 = (cppVar_71934 >> 7) & cppMask_un_1_;
	cppVar_71936 = (cppVar_71935 == 1);
	if (cppVar_71936) {
	cppVar_71937 = PC + 1;
	cppVar_71937 = (cppVar_71937 & cppMask_un_16_);
	cppVar_71938 = ROM.rd(cppVar_71937);
	cppVar_71939 = (cppVar_71938 >> 3) & cppMask_un_5_;
	cppVar_71940 = (cppVar_71939 << 3) | 0;
	cppVar_71940 = (cppVar_71940 & cppMask_un_8_);
	cppVar_71932 = cppVar_71940;
	} else {
	cppVar_71941 = PC + 1;
	cppVar_71941 = (cppVar_71941 & cppMask_un_16_);
	cppVar_71942 = ROM.rd(cppVar_71941);
	cppVar_71943 = (cppVar_71942 >> 3) & cppMask_un_5_;
	cppVar_71944 = (cppVar_71943 & cppMask_un_5_);
	cppVar_71945 = cppVar_71944 + 32;
	cppVar_71945 = (cppVar_71945 & cppMask_un_8_);
	cppVar_71932 = cppVar_71945;
	}
	cppVar_71947 = (cppVar_71932 == 128);
	if (cppVar_71947) {
	cppVar_71931 = P0;
	} else {
	cppVar_71950 = PC + 1;
	cppVar_71950 = (cppVar_71950 & cppMask_un_16_);
	cppVar_71951 = ROM.rd(cppVar_71950);
	cppVar_71952 = (cppVar_71951 >> 7) & cppMask_un_1_;
	cppVar_71953 = (cppVar_71952 == 1);
	if (cppVar_71953) {
	cppVar_71954 = PC + 1;
	cppVar_71954 = (cppVar_71954 & cppMask_un_16_);
	cppVar_71955 = ROM.rd(cppVar_71954);
	cppVar_71956 = (cppVar_71955 >> 3) & cppMask_un_5_;
	cppVar_71957 = (cppVar_71956 << 3) | 0;
	cppVar_71957 = (cppVar_71957 & cppMask_un_8_);
	cppVar_71949 = cppVar_71957;
	} else {
	cppVar_71958 = PC + 1;
	cppVar_71958 = (cppVar_71958 & cppMask_un_16_);
	cppVar_71959 = ROM.rd(cppVar_71958);
	cppVar_71960 = (cppVar_71959 >> 3) & cppMask_un_5_;
	cppVar_71961 = (cppVar_71960 & cppMask_un_5_);
	cppVar_71962 = cppVar_71961 + 32;
	cppVar_71962 = (cppVar_71962 & cppMask_un_8_);
	cppVar_71949 = cppVar_71962;
	}
	cppVar_71964 = (cppVar_71949 == 129);
	if (cppVar_71964) {
	cppVar_71948 = SP;
	} else {
	cppVar_71967 = PC + 1;
	cppVar_71967 = (cppVar_71967 & cppMask_un_16_);
	cppVar_71968 = ROM.rd(cppVar_71967);
	cppVar_71969 = (cppVar_71968 >> 7) & cppMask_un_1_;
	cppVar_71970 = (cppVar_71969 == 1);
	if (cppVar_71970) {
	cppVar_71971 = PC + 1;
	cppVar_71971 = (cppVar_71971 & cppMask_un_16_);
	cppVar_71972 = ROM.rd(cppVar_71971);
	cppVar_71973 = (cppVar_71972 >> 3) & cppMask_un_5_;
	cppVar_71974 = (cppVar_71973 << 3) | 0;
	cppVar_71974 = (cppVar_71974 & cppMask_un_8_);
	cppVar_71966 = cppVar_71974;
	} else {
	cppVar_71975 = PC + 1;
	cppVar_71975 = (cppVar_71975 & cppMask_un_16_);
	cppVar_71976 = ROM.rd(cppVar_71975);
	cppVar_71977 = (cppVar_71976 >> 3) & cppMask_un_5_;
	cppVar_71978 = (cppVar_71977 & cppMask_un_5_);
	cppVar_71979 = cppVar_71978 + 32;
	cppVar_71979 = (cppVar_71979 & cppMask_un_8_);
	cppVar_71966 = cppVar_71979;
	}
	cppVar_71981 = (cppVar_71966 == 130);
	if (cppVar_71981) {
	cppVar_71965 = DPL;
	} else {
	cppVar_71984 = PC + 1;
	cppVar_71984 = (cppVar_71984 & cppMask_un_16_);
	cppVar_71985 = ROM.rd(cppVar_71984);
	cppVar_71986 = (cppVar_71985 >> 7) & cppMask_un_1_;
	cppVar_71987 = (cppVar_71986 == 1);
	if (cppVar_71987) {
	cppVar_71988 = PC + 1;
	cppVar_71988 = (cppVar_71988 & cppMask_un_16_);
	cppVar_71989 = ROM.rd(cppVar_71988);
	cppVar_71990 = (cppVar_71989 >> 3) & cppMask_un_5_;
	cppVar_71991 = (cppVar_71990 << 3) | 0;
	cppVar_71991 = (cppVar_71991 & cppMask_un_8_);
	cppVar_71983 = cppVar_71991;
	} else {
	cppVar_71992 = PC + 1;
	cppVar_71992 = (cppVar_71992 & cppMask_un_16_);
	cppVar_71993 = ROM.rd(cppVar_71992);
	cppVar_71994 = (cppVar_71993 >> 3) & cppMask_un_5_;
	cppVar_71995 = (cppVar_71994 & cppMask_un_5_);
	cppVar_71996 = cppVar_71995 + 32;
	cppVar_71996 = (cppVar_71996 & cppMask_un_8_);
	cppVar_71983 = cppVar_71996;
	}
	cppVar_71998 = (cppVar_71983 == 131);
	if (cppVar_71998) {
	cppVar_71982 = DPH;
	} else {
	cppVar_72001 = PC + 1;
	cppVar_72001 = (cppVar_72001 & cppMask_un_16_);
	cppVar_72002 = ROM.rd(cppVar_72001);
	cppVar_72003 = (cppVar_72002 >> 7) & cppMask_un_1_;
	cppVar_72004 = (cppVar_72003 == 1);
	if (cppVar_72004) {
	cppVar_72005 = PC + 1;
	cppVar_72005 = (cppVar_72005 & cppMask_un_16_);
	cppVar_72006 = ROM.rd(cppVar_72005);
	cppVar_72007 = (cppVar_72006 >> 3) & cppMask_un_5_;
	cppVar_72008 = (cppVar_72007 << 3) | 0;
	cppVar_72008 = (cppVar_72008 & cppMask_un_8_);
	cppVar_72000 = cppVar_72008;
	} else {
	cppVar_72009 = PC + 1;
	cppVar_72009 = (cppVar_72009 & cppMask_un_16_);
	cppVar_72010 = ROM.rd(cppVar_72009);
	cppVar_72011 = (cppVar_72010 >> 3) & cppMask_un_5_;
	cppVar_72012 = (cppVar_72011 & cppMask_un_5_);
	cppVar_72013 = cppVar_72012 + 32;
	cppVar_72013 = (cppVar_72013 & cppMask_un_8_);
	cppVar_72000 = cppVar_72013;
	}
	cppVar_72015 = (cppVar_72000 == 135);
	if (cppVar_72015) {
	cppVar_71999 = PCON;
	} else {
	cppVar_72018 = PC + 1;
	cppVar_72018 = (cppVar_72018 & cppMask_un_16_);
	cppVar_72019 = ROM.rd(cppVar_72018);
	cppVar_72020 = (cppVar_72019 >> 7) & cppMask_un_1_;
	cppVar_72021 = (cppVar_72020 == 1);
	if (cppVar_72021) {
	cppVar_72022 = PC + 1;
	cppVar_72022 = (cppVar_72022 & cppMask_un_16_);
	cppVar_72023 = ROM.rd(cppVar_72022);
	cppVar_72024 = (cppVar_72023 >> 3) & cppMask_un_5_;
	cppVar_72025 = (cppVar_72024 << 3) | 0;
	cppVar_72025 = (cppVar_72025 & cppMask_un_8_);
	cppVar_72017 = cppVar_72025;
	} else {
	cppVar_72026 = PC + 1;
	cppVar_72026 = (cppVar_72026 & cppMask_un_16_);
	cppVar_72027 = ROM.rd(cppVar_72026);
	cppVar_72028 = (cppVar_72027 >> 3) & cppMask_un_5_;
	cppVar_72029 = (cppVar_72028 & cppMask_un_5_);
	cppVar_72030 = cppVar_72029 + 32;
	cppVar_72030 = (cppVar_72030 & cppMask_un_8_);
	cppVar_72017 = cppVar_72030;
	}
	cppVar_72032 = (cppVar_72017 == 136);
	if (cppVar_72032) {
	cppVar_72016 = TCON;
	} else {
	cppVar_72035 = PC + 1;
	cppVar_72035 = (cppVar_72035 & cppMask_un_16_);
	cppVar_72036 = ROM.rd(cppVar_72035);
	cppVar_72037 = (cppVar_72036 >> 7) & cppMask_un_1_;
	cppVar_72038 = (cppVar_72037 == 1);
	if (cppVar_72038) {
	cppVar_72039 = PC + 1;
	cppVar_72039 = (cppVar_72039 & cppMask_un_16_);
	cppVar_72040 = ROM.rd(cppVar_72039);
	cppVar_72041 = (cppVar_72040 >> 3) & cppMask_un_5_;
	cppVar_72042 = (cppVar_72041 << 3) | 0;
	cppVar_72042 = (cppVar_72042 & cppMask_un_8_);
	cppVar_72034 = cppVar_72042;
	} else {
	cppVar_72043 = PC + 1;
	cppVar_72043 = (cppVar_72043 & cppMask_un_16_);
	cppVar_72044 = ROM.rd(cppVar_72043);
	cppVar_72045 = (cppVar_72044 >> 3) & cppMask_un_5_;
	cppVar_72046 = (cppVar_72045 & cppMask_un_5_);
	cppVar_72047 = cppVar_72046 + 32;
	cppVar_72047 = (cppVar_72047 & cppMask_un_8_);
	cppVar_72034 = cppVar_72047;
	}
	cppVar_72049 = (cppVar_72034 == 137);
	if (cppVar_72049) {
	cppVar_72033 = TMOD;
	} else {
	cppVar_72052 = PC + 1;
	cppVar_72052 = (cppVar_72052 & cppMask_un_16_);
	cppVar_72053 = ROM.rd(cppVar_72052);
	cppVar_72054 = (cppVar_72053 >> 7) & cppMask_un_1_;
	cppVar_72055 = (cppVar_72054 == 1);
	if (cppVar_72055) {
	cppVar_72056 = PC + 1;
	cppVar_72056 = (cppVar_72056 & cppMask_un_16_);
	cppVar_72057 = ROM.rd(cppVar_72056);
	cppVar_72058 = (cppVar_72057 >> 3) & cppMask_un_5_;
	cppVar_72059 = (cppVar_72058 << 3) | 0;
	cppVar_72059 = (cppVar_72059 & cppMask_un_8_);
	cppVar_72051 = cppVar_72059;
	} else {
	cppVar_72060 = PC + 1;
	cppVar_72060 = (cppVar_72060 & cppMask_un_16_);
	cppVar_72061 = ROM.rd(cppVar_72060);
	cppVar_72062 = (cppVar_72061 >> 3) & cppMask_un_5_;
	cppVar_72063 = (cppVar_72062 & cppMask_un_5_);
	cppVar_72064 = cppVar_72063 + 32;
	cppVar_72064 = (cppVar_72064 & cppMask_un_8_);
	cppVar_72051 = cppVar_72064;
	}
	cppVar_72066 = (cppVar_72051 == 138);
	if (cppVar_72066) {
	cppVar_72050 = TL0;
	} else {
	cppVar_72069 = PC + 1;
	cppVar_72069 = (cppVar_72069 & cppMask_un_16_);
	cppVar_72070 = ROM.rd(cppVar_72069);
	cppVar_72071 = (cppVar_72070 >> 7) & cppMask_un_1_;
	cppVar_72072 = (cppVar_72071 == 1);
	if (cppVar_72072) {
	cppVar_72073 = PC + 1;
	cppVar_72073 = (cppVar_72073 & cppMask_un_16_);
	cppVar_72074 = ROM.rd(cppVar_72073);
	cppVar_72075 = (cppVar_72074 >> 3) & cppMask_un_5_;
	cppVar_72076 = (cppVar_72075 << 3) | 0;
	cppVar_72076 = (cppVar_72076 & cppMask_un_8_);
	cppVar_72068 = cppVar_72076;
	} else {
	cppVar_72077 = PC + 1;
	cppVar_72077 = (cppVar_72077 & cppMask_un_16_);
	cppVar_72078 = ROM.rd(cppVar_72077);
	cppVar_72079 = (cppVar_72078 >> 3) & cppMask_un_5_;
	cppVar_72080 = (cppVar_72079 & cppMask_un_5_);
	cppVar_72081 = cppVar_72080 + 32;
	cppVar_72081 = (cppVar_72081 & cppMask_un_8_);
	cppVar_72068 = cppVar_72081;
	}
	cppVar_72083 = (cppVar_72068 == 140);
	if (cppVar_72083) {
	cppVar_72067 = TH0;
	} else {
	cppVar_72086 = PC + 1;
	cppVar_72086 = (cppVar_72086 & cppMask_un_16_);
	cppVar_72087 = ROM.rd(cppVar_72086);
	cppVar_72088 = (cppVar_72087 >> 7) & cppMask_un_1_;
	cppVar_72089 = (cppVar_72088 == 1);
	if (cppVar_72089) {
	cppVar_72090 = PC + 1;
	cppVar_72090 = (cppVar_72090 & cppMask_un_16_);
	cppVar_72091 = ROM.rd(cppVar_72090);
	cppVar_72092 = (cppVar_72091 >> 3) & cppMask_un_5_;
	cppVar_72093 = (cppVar_72092 << 3) | 0;
	cppVar_72093 = (cppVar_72093 & cppMask_un_8_);
	cppVar_72085 = cppVar_72093;
	} else {
	cppVar_72094 = PC + 1;
	cppVar_72094 = (cppVar_72094 & cppMask_un_16_);
	cppVar_72095 = ROM.rd(cppVar_72094);
	cppVar_72096 = (cppVar_72095 >> 3) & cppMask_un_5_;
	cppVar_72097 = (cppVar_72096 & cppMask_un_5_);
	cppVar_72098 = cppVar_72097 + 32;
	cppVar_72098 = (cppVar_72098 & cppMask_un_8_);
	cppVar_72085 = cppVar_72098;
	}
	cppVar_72100 = (cppVar_72085 == 139);
	if (cppVar_72100) {
	cppVar_72084 = TL1;
	} else {
	cppVar_72103 = PC + 1;
	cppVar_72103 = (cppVar_72103 & cppMask_un_16_);
	cppVar_72104 = ROM.rd(cppVar_72103);
	cppVar_72105 = (cppVar_72104 >> 7) & cppMask_un_1_;
	cppVar_72106 = (cppVar_72105 == 1);
	if (cppVar_72106) {
	cppVar_72107 = PC + 1;
	cppVar_72107 = (cppVar_72107 & cppMask_un_16_);
	cppVar_72108 = ROM.rd(cppVar_72107);
	cppVar_72109 = (cppVar_72108 >> 3) & cppMask_un_5_;
	cppVar_72110 = (cppVar_72109 << 3) | 0;
	cppVar_72110 = (cppVar_72110 & cppMask_un_8_);
	cppVar_72102 = cppVar_72110;
	} else {
	cppVar_72111 = PC + 1;
	cppVar_72111 = (cppVar_72111 & cppMask_un_16_);
	cppVar_72112 = ROM.rd(cppVar_72111);
	cppVar_72113 = (cppVar_72112 >> 3) & cppMask_un_5_;
	cppVar_72114 = (cppVar_72113 & cppMask_un_5_);
	cppVar_72115 = cppVar_72114 + 32;
	cppVar_72115 = (cppVar_72115 & cppMask_un_8_);
	cppVar_72102 = cppVar_72115;
	}
	cppVar_72117 = (cppVar_72102 == 141);
	if (cppVar_72117) {
	cppVar_72101 = TH1;
	} else {
	cppVar_72120 = PC + 1;
	cppVar_72120 = (cppVar_72120 & cppMask_un_16_);
	cppVar_72121 = ROM.rd(cppVar_72120);
	cppVar_72122 = (cppVar_72121 >> 7) & cppMask_un_1_;
	cppVar_72123 = (cppVar_72122 == 1);
	if (cppVar_72123) {
	cppVar_72124 = PC + 1;
	cppVar_72124 = (cppVar_72124 & cppMask_un_16_);
	cppVar_72125 = ROM.rd(cppVar_72124);
	cppVar_72126 = (cppVar_72125 >> 3) & cppMask_un_5_;
	cppVar_72127 = (cppVar_72126 << 3) | 0;
	cppVar_72127 = (cppVar_72127 & cppMask_un_8_);
	cppVar_72119 = cppVar_72127;
	} else {
	cppVar_72128 = PC + 1;
	cppVar_72128 = (cppVar_72128 & cppMask_un_16_);
	cppVar_72129 = ROM.rd(cppVar_72128);
	cppVar_72130 = (cppVar_72129 >> 3) & cppMask_un_5_;
	cppVar_72131 = (cppVar_72130 & cppMask_un_5_);
	cppVar_72132 = cppVar_72131 + 32;
	cppVar_72132 = (cppVar_72132 & cppMask_un_8_);
	cppVar_72119 = cppVar_72132;
	}
	cppVar_72134 = (cppVar_72119 == 144);
	if (cppVar_72134) {
	cppVar_72118 = P1;
	} else {
	cppVar_72137 = PC + 1;
	cppVar_72137 = (cppVar_72137 & cppMask_un_16_);
	cppVar_72138 = ROM.rd(cppVar_72137);
	cppVar_72139 = (cppVar_72138 >> 7) & cppMask_un_1_;
	cppVar_72140 = (cppVar_72139 == 1);
	if (cppVar_72140) {
	cppVar_72141 = PC + 1;
	cppVar_72141 = (cppVar_72141 & cppMask_un_16_);
	cppVar_72142 = ROM.rd(cppVar_72141);
	cppVar_72143 = (cppVar_72142 >> 3) & cppMask_un_5_;
	cppVar_72144 = (cppVar_72143 << 3) | 0;
	cppVar_72144 = (cppVar_72144 & cppMask_un_8_);
	cppVar_72136 = cppVar_72144;
	} else {
	cppVar_72145 = PC + 1;
	cppVar_72145 = (cppVar_72145 & cppMask_un_16_);
	cppVar_72146 = ROM.rd(cppVar_72145);
	cppVar_72147 = (cppVar_72146 >> 3) & cppMask_un_5_;
	cppVar_72148 = (cppVar_72147 & cppMask_un_5_);
	cppVar_72149 = cppVar_72148 + 32;
	cppVar_72149 = (cppVar_72149 & cppMask_un_8_);
	cppVar_72136 = cppVar_72149;
	}
	cppVar_72151 = (cppVar_72136 == 152);
	if (cppVar_72151) {
	cppVar_72135 = SCON;
	} else {
	cppVar_72154 = PC + 1;
	cppVar_72154 = (cppVar_72154 & cppMask_un_16_);
	cppVar_72155 = ROM.rd(cppVar_72154);
	cppVar_72156 = (cppVar_72155 >> 7) & cppMask_un_1_;
	cppVar_72157 = (cppVar_72156 == 1);
	if (cppVar_72157) {
	cppVar_72158 = PC + 1;
	cppVar_72158 = (cppVar_72158 & cppMask_un_16_);
	cppVar_72159 = ROM.rd(cppVar_72158);
	cppVar_72160 = (cppVar_72159 >> 3) & cppMask_un_5_;
	cppVar_72161 = (cppVar_72160 << 3) | 0;
	cppVar_72161 = (cppVar_72161 & cppMask_un_8_);
	cppVar_72153 = cppVar_72161;
	} else {
	cppVar_72162 = PC + 1;
	cppVar_72162 = (cppVar_72162 & cppMask_un_16_);
	cppVar_72163 = ROM.rd(cppVar_72162);
	cppVar_72164 = (cppVar_72163 >> 3) & cppMask_un_5_;
	cppVar_72165 = (cppVar_72164 & cppMask_un_5_);
	cppVar_72166 = cppVar_72165 + 32;
	cppVar_72166 = (cppVar_72166 & cppMask_un_8_);
	cppVar_72153 = cppVar_72166;
	}
	cppVar_72168 = (cppVar_72153 == 153);
	if (cppVar_72168) {
	cppVar_72152 = SBUF;
	} else {
	cppVar_72171 = PC + 1;
	cppVar_72171 = (cppVar_72171 & cppMask_un_16_);
	cppVar_72172 = ROM.rd(cppVar_72171);
	cppVar_72173 = (cppVar_72172 >> 7) & cppMask_un_1_;
	cppVar_72174 = (cppVar_72173 == 1);
	if (cppVar_72174) {
	cppVar_72175 = PC + 1;
	cppVar_72175 = (cppVar_72175 & cppMask_un_16_);
	cppVar_72176 = ROM.rd(cppVar_72175);
	cppVar_72177 = (cppVar_72176 >> 3) & cppMask_un_5_;
	cppVar_72178 = (cppVar_72177 << 3) | 0;
	cppVar_72178 = (cppVar_72178 & cppMask_un_8_);
	cppVar_72170 = cppVar_72178;
	} else {
	cppVar_72179 = PC + 1;
	cppVar_72179 = (cppVar_72179 & cppMask_un_16_);
	cppVar_72180 = ROM.rd(cppVar_72179);
	cppVar_72181 = (cppVar_72180 >> 3) & cppMask_un_5_;
	cppVar_72182 = (cppVar_72181 & cppMask_un_5_);
	cppVar_72183 = cppVar_72182 + 32;
	cppVar_72183 = (cppVar_72183 & cppMask_un_8_);
	cppVar_72170 = cppVar_72183;
	}
	cppVar_72185 = (cppVar_72170 == 160);
	if (cppVar_72185) {
	cppVar_72169 = P2;
	} else {
	cppVar_72188 = PC + 1;
	cppVar_72188 = (cppVar_72188 & cppMask_un_16_);
	cppVar_72189 = ROM.rd(cppVar_72188);
	cppVar_72190 = (cppVar_72189 >> 7) & cppMask_un_1_;
	cppVar_72191 = (cppVar_72190 == 1);
	if (cppVar_72191) {
	cppVar_72192 = PC + 1;
	cppVar_72192 = (cppVar_72192 & cppMask_un_16_);
	cppVar_72193 = ROM.rd(cppVar_72192);
	cppVar_72194 = (cppVar_72193 >> 3) & cppMask_un_5_;
	cppVar_72195 = (cppVar_72194 << 3) | 0;
	cppVar_72195 = (cppVar_72195 & cppMask_un_8_);
	cppVar_72187 = cppVar_72195;
	} else {
	cppVar_72196 = PC + 1;
	cppVar_72196 = (cppVar_72196 & cppMask_un_16_);
	cppVar_72197 = ROM.rd(cppVar_72196);
	cppVar_72198 = (cppVar_72197 >> 3) & cppMask_un_5_;
	cppVar_72199 = (cppVar_72198 & cppMask_un_5_);
	cppVar_72200 = cppVar_72199 + 32;
	cppVar_72200 = (cppVar_72200 & cppMask_un_8_);
	cppVar_72187 = cppVar_72200;
	}
	cppVar_72202 = (cppVar_72187 == 168);
	if (cppVar_72202) {
	cppVar_72186 = IE;
	} else {
	cppVar_72205 = PC + 1;
	cppVar_72205 = (cppVar_72205 & cppMask_un_16_);
	cppVar_72206 = ROM.rd(cppVar_72205);
	cppVar_72207 = (cppVar_72206 >> 7) & cppMask_un_1_;
	cppVar_72208 = (cppVar_72207 == 1);
	if (cppVar_72208) {
	cppVar_72209 = PC + 1;
	cppVar_72209 = (cppVar_72209 & cppMask_un_16_);
	cppVar_72210 = ROM.rd(cppVar_72209);
	cppVar_72211 = (cppVar_72210 >> 3) & cppMask_un_5_;
	cppVar_72212 = (cppVar_72211 << 3) | 0;
	cppVar_72212 = (cppVar_72212 & cppMask_un_8_);
	cppVar_72204 = cppVar_72212;
	} else {
	cppVar_72213 = PC + 1;
	cppVar_72213 = (cppVar_72213 & cppMask_un_16_);
	cppVar_72214 = ROM.rd(cppVar_72213);
	cppVar_72215 = (cppVar_72214 >> 3) & cppMask_un_5_;
	cppVar_72216 = (cppVar_72215 & cppMask_un_5_);
	cppVar_72217 = cppVar_72216 + 32;
	cppVar_72217 = (cppVar_72217 & cppMask_un_8_);
	cppVar_72204 = cppVar_72217;
	}
	cppVar_72219 = (cppVar_72204 == 176);
	if (cppVar_72219) {
	cppVar_72203 = P3;
	} else {
	cppVar_72222 = PC + 1;
	cppVar_72222 = (cppVar_72222 & cppMask_un_16_);
	cppVar_72223 = ROM.rd(cppVar_72222);
	cppVar_72224 = (cppVar_72223 >> 7) & cppMask_un_1_;
	cppVar_72225 = (cppVar_72224 == 1);
	if (cppVar_72225) {
	cppVar_72226 = PC + 1;
	cppVar_72226 = (cppVar_72226 & cppMask_un_16_);
	cppVar_72227 = ROM.rd(cppVar_72226);
	cppVar_72228 = (cppVar_72227 >> 3) & cppMask_un_5_;
	cppVar_72229 = (cppVar_72228 << 3) | 0;
	cppVar_72229 = (cppVar_72229 & cppMask_un_8_);
	cppVar_72221 = cppVar_72229;
	} else {
	cppVar_72230 = PC + 1;
	cppVar_72230 = (cppVar_72230 & cppMask_un_16_);
	cppVar_72231 = ROM.rd(cppVar_72230);
	cppVar_72232 = (cppVar_72231 >> 3) & cppMask_un_5_;
	cppVar_72233 = (cppVar_72232 & cppMask_un_5_);
	cppVar_72234 = cppVar_72233 + 32;
	cppVar_72234 = (cppVar_72234 & cppMask_un_8_);
	cppVar_72221 = cppVar_72234;
	}
	cppVar_72236 = (cppVar_72221 == 184);
	if (cppVar_72236) {
	cppVar_72220 = IP;
	} else {
	cppVar_72239 = PC + 1;
	cppVar_72239 = (cppVar_72239 & cppMask_un_16_);
	cppVar_72240 = ROM.rd(cppVar_72239);
	cppVar_72241 = (cppVar_72240 >> 7) & cppMask_un_1_;
	cppVar_72242 = (cppVar_72241 == 1);
	if (cppVar_72242) {
	cppVar_72243 = PC + 1;
	cppVar_72243 = (cppVar_72243 & cppMask_un_16_);
	cppVar_72244 = ROM.rd(cppVar_72243);
	cppVar_72245 = (cppVar_72244 >> 3) & cppMask_un_5_;
	cppVar_72246 = (cppVar_72245 << 3) | 0;
	cppVar_72246 = (cppVar_72246 & cppMask_un_8_);
	cppVar_72238 = cppVar_72246;
	} else {
	cppVar_72247 = PC + 1;
	cppVar_72247 = (cppVar_72247 & cppMask_un_16_);
	cppVar_72248 = ROM.rd(cppVar_72247);
	cppVar_72249 = (cppVar_72248 >> 3) & cppMask_un_5_;
	cppVar_72250 = (cppVar_72249 & cppMask_un_5_);
	cppVar_72251 = cppVar_72250 + 32;
	cppVar_72251 = (cppVar_72251 & cppMask_un_8_);
	cppVar_72238 = cppVar_72251;
	}
	cppVar_72253 = (cppVar_72238 == 208);
	if (cppVar_72253) {
	cppVar_72237 = PSW;
	} else {
	cppVar_72256 = PC + 1;
	cppVar_72256 = (cppVar_72256 & cppMask_un_16_);
	cppVar_72257 = ROM.rd(cppVar_72256);
	cppVar_72258 = (cppVar_72257 >> 7) & cppMask_un_1_;
	cppVar_72259 = (cppVar_72258 == 1);
	if (cppVar_72259) {
	cppVar_72260 = PC + 1;
	cppVar_72260 = (cppVar_72260 & cppMask_un_16_);
	cppVar_72261 = ROM.rd(cppVar_72260);
	cppVar_72262 = (cppVar_72261 >> 3) & cppMask_un_5_;
	cppVar_72263 = (cppVar_72262 << 3) | 0;
	cppVar_72263 = (cppVar_72263 & cppMask_un_8_);
	cppVar_72255 = cppVar_72263;
	} else {
	cppVar_72264 = PC + 1;
	cppVar_72264 = (cppVar_72264 & cppMask_un_16_);
	cppVar_72265 = ROM.rd(cppVar_72264);
	cppVar_72266 = (cppVar_72265 >> 3) & cppMask_un_5_;
	cppVar_72267 = (cppVar_72266 & cppMask_un_5_);
	cppVar_72268 = cppVar_72267 + 32;
	cppVar_72268 = (cppVar_72268 & cppMask_un_8_);
	cppVar_72255 = cppVar_72268;
	}
	cppVar_72270 = (cppVar_72255 == 224);
	if (cppVar_72270) {
	cppVar_72254 = ACC;
	} else {
	cppVar_72273 = PC + 1;
	cppVar_72273 = (cppVar_72273 & cppMask_un_16_);
	cppVar_72274 = ROM.rd(cppVar_72273);
	cppVar_72275 = (cppVar_72274 >> 7) & cppMask_un_1_;
	cppVar_72276 = (cppVar_72275 == 1);
	if (cppVar_72276) {
	cppVar_72277 = PC + 1;
	cppVar_72277 = (cppVar_72277 & cppMask_un_16_);
	cppVar_72278 = ROM.rd(cppVar_72277);
	cppVar_72279 = (cppVar_72278 >> 3) & cppMask_un_5_;
	cppVar_72280 = (cppVar_72279 << 3) | 0;
	cppVar_72280 = (cppVar_72280 & cppMask_un_8_);
	cppVar_72272 = cppVar_72280;
	} else {
	cppVar_72281 = PC + 1;
	cppVar_72281 = (cppVar_72281 & cppMask_un_16_);
	cppVar_72282 = ROM.rd(cppVar_72281);
	cppVar_72283 = (cppVar_72282 >> 3) & cppMask_un_5_;
	cppVar_72284 = (cppVar_72283 & cppMask_un_5_);
	cppVar_72285 = cppVar_72284 + 32;
	cppVar_72285 = (cppVar_72285 & cppMask_un_8_);
	cppVar_72272 = cppVar_72285;
	}
	cppVar_72287 = (cppVar_72272 == 240);
	if (cppVar_72287) {
	cppVar_72271 = B;
	} else {
	cppVar_72271 = 0;
	}
	cppVar_72254 = cppVar_72271;
	}
	cppVar_72237 = cppVar_72254;
	}
	cppVar_72220 = cppVar_72237;
	}
	cppVar_72203 = cppVar_72220;
	}
	cppVar_72186 = cppVar_72203;
	}
	cppVar_72169 = cppVar_72186;
	}
	cppVar_72152 = cppVar_72169;
	}
	cppVar_72135 = cppVar_72152;
	}
	cppVar_72118 = cppVar_72135;
	}
	cppVar_72101 = cppVar_72118;
	}
	cppVar_72084 = cppVar_72101;
	}
	cppVar_72067 = cppVar_72084;
	}
	cppVar_72050 = cppVar_72067;
	}
	cppVar_72033 = cppVar_72050;
	}
	cppVar_72016 = cppVar_72033;
	}
	cppVar_71999 = cppVar_72016;
	}
	cppVar_71982 = cppVar_71999;
	}
	cppVar_71965 = cppVar_71982;
	}
	cppVar_71948 = cppVar_71965;
	}
	cppVar_71931 = cppVar_71948;
	}
	cppVar_71898 = cppVar_71931;
	}
	cppVar_72289 = cppVar_71897 & cppVar_71898;
	cppVar_72291 = 0;
	cppVar_72292 = PC + 1;
	cppVar_72292 = (cppVar_72292 & cppMask_un_16_);
	cppVar_72293 = ROM.rd(cppVar_72292);
	cppVar_72294 = (cppVar_72293 >> 0) & cppMask_un_3_;
	cppVar_72295 = (cppVar_72294 & cppMask_un_3_);
	cppVar_72296 = cppVar_72291 << static_cast<unsigned>(cppVar_72295);
	cppVar_72296 = (cppVar_72296 & cppMask_un_8_);
	cppVar_72297 = cppVar_72289 | cppVar_72296;
	cppVar_71870 = cppVar_72297;
	} else {
	cppVar_71870 = TCON;
	}
	cppVar_71862 = cppVar_71870;
	} else {
	cppVar_72299 = ROM.rd(PC);
	cppVar_72301 = (cppVar_72299 == 5);
	if (cppVar_72301) {
	cppVar_72304 = PC + 1;
	cppVar_72304 = (cppVar_72304 & cppMask_un_16_);
	cppVar_72305 = ROM.rd(cppVar_72304);
	cppVar_72307 = (cppVar_72305 == 136);
	if (cppVar_72307) {
	cppVar_72309 = PC + 1;
	cppVar_72309 = (cppVar_72309 & cppMask_un_16_);
	cppVar_72310 = ROM.rd(cppVar_72309);
	cppVar_72311 = (cppVar_72310 >> 7) & cppMask_un_1_;
	cppVar_72313 = (cppVar_72311 == 0);
	if (cppVar_72313) {
	cppVar_72314 = PC + 1;
	cppVar_72314 = (cppVar_72314 & cppMask_un_16_);
	cppVar_72315 = ROM.rd(cppVar_72314);
	cppVar_72316 = IRAM.rd(cppVar_72315);
	cppVar_72308 = cppVar_72316;
	} else {
	cppVar_72318 = PC + 1;
	cppVar_72318 = (cppVar_72318 & cppMask_un_16_);
	cppVar_72319 = ROM.rd(cppVar_72318);
	cppVar_72321 = (cppVar_72319 == 128);
	if (cppVar_72321) {
	cppVar_72317 = P0;
	} else {
	cppVar_72323 = PC + 1;
	cppVar_72323 = (cppVar_72323 & cppMask_un_16_);
	cppVar_72324 = ROM.rd(cppVar_72323);
	cppVar_72326 = (cppVar_72324 == 129);
	if (cppVar_72326) {
	cppVar_72322 = SP;
	} else {
	cppVar_72328 = PC + 1;
	cppVar_72328 = (cppVar_72328 & cppMask_un_16_);
	cppVar_72329 = ROM.rd(cppVar_72328);
	cppVar_72331 = (cppVar_72329 == 130);
	if (cppVar_72331) {
	cppVar_72327 = DPL;
	} else {
	cppVar_72333 = PC + 1;
	cppVar_72333 = (cppVar_72333 & cppMask_un_16_);
	cppVar_72334 = ROM.rd(cppVar_72333);
	cppVar_72336 = (cppVar_72334 == 131);
	if (cppVar_72336) {
	cppVar_72332 = DPH;
	} else {
	cppVar_72338 = PC + 1;
	cppVar_72338 = (cppVar_72338 & cppMask_un_16_);
	cppVar_72339 = ROM.rd(cppVar_72338);
	cppVar_72341 = (cppVar_72339 == 135);
	if (cppVar_72341) {
	cppVar_72337 = PCON;
	} else {
	cppVar_72343 = PC + 1;
	cppVar_72343 = (cppVar_72343 & cppMask_un_16_);
	cppVar_72344 = ROM.rd(cppVar_72343);
	cppVar_72346 = (cppVar_72344 == 136);
	if (cppVar_72346) {
	cppVar_72342 = TCON;
	} else {
	cppVar_72348 = PC + 1;
	cppVar_72348 = (cppVar_72348 & cppMask_un_16_);
	cppVar_72349 = ROM.rd(cppVar_72348);
	cppVar_72351 = (cppVar_72349 == 137);
	if (cppVar_72351) {
	cppVar_72347 = TMOD;
	} else {
	cppVar_72353 = PC + 1;
	cppVar_72353 = (cppVar_72353 & cppMask_un_16_);
	cppVar_72354 = ROM.rd(cppVar_72353);
	cppVar_72356 = (cppVar_72354 == 138);
	if (cppVar_72356) {
	cppVar_72352 = TL0;
	} else {
	cppVar_72358 = PC + 1;
	cppVar_72358 = (cppVar_72358 & cppMask_un_16_);
	cppVar_72359 = ROM.rd(cppVar_72358);
	cppVar_72361 = (cppVar_72359 == 140);
	if (cppVar_72361) {
	cppVar_72357 = TH0;
	} else {
	cppVar_72363 = PC + 1;
	cppVar_72363 = (cppVar_72363 & cppMask_un_16_);
	cppVar_72364 = ROM.rd(cppVar_72363);
	cppVar_72366 = (cppVar_72364 == 139);
	if (cppVar_72366) {
	cppVar_72362 = TL1;
	} else {
	cppVar_72368 = PC + 1;
	cppVar_72368 = (cppVar_72368 & cppMask_un_16_);
	cppVar_72369 = ROM.rd(cppVar_72368);
	cppVar_72371 = (cppVar_72369 == 141);
	if (cppVar_72371) {
	cppVar_72367 = TH1;
	} else {
	cppVar_72373 = PC + 1;
	cppVar_72373 = (cppVar_72373 & cppMask_un_16_);
	cppVar_72374 = ROM.rd(cppVar_72373);
	cppVar_72376 = (cppVar_72374 == 144);
	if (cppVar_72376) {
	cppVar_72372 = P1;
	} else {
	cppVar_72378 = PC + 1;
	cppVar_72378 = (cppVar_72378 & cppMask_un_16_);
	cppVar_72379 = ROM.rd(cppVar_72378);
	cppVar_72381 = (cppVar_72379 == 152);
	if (cppVar_72381) {
	cppVar_72377 = SCON;
	} else {
	cppVar_72383 = PC + 1;
	cppVar_72383 = (cppVar_72383 & cppMask_un_16_);
	cppVar_72384 = ROM.rd(cppVar_72383);
	cppVar_72386 = (cppVar_72384 == 153);
	if (cppVar_72386) {
	cppVar_72382 = SBUF;
	} else {
	cppVar_72388 = PC + 1;
	cppVar_72388 = (cppVar_72388 & cppMask_un_16_);
	cppVar_72389 = ROM.rd(cppVar_72388);
	cppVar_72391 = (cppVar_72389 == 160);
	if (cppVar_72391) {
	cppVar_72387 = P2;
	} else {
	cppVar_72393 = PC + 1;
	cppVar_72393 = (cppVar_72393 & cppMask_un_16_);
	cppVar_72394 = ROM.rd(cppVar_72393);
	cppVar_72396 = (cppVar_72394 == 168);
	if (cppVar_72396) {
	cppVar_72392 = IE;
	} else {
	cppVar_72398 = PC + 1;
	cppVar_72398 = (cppVar_72398 & cppMask_un_16_);
	cppVar_72399 = ROM.rd(cppVar_72398);
	cppVar_72401 = (cppVar_72399 == 176);
	if (cppVar_72401) {
	cppVar_72397 = P3;
	} else {
	cppVar_72403 = PC + 1;
	cppVar_72403 = (cppVar_72403 & cppMask_un_16_);
	cppVar_72404 = ROM.rd(cppVar_72403);
	cppVar_72406 = (cppVar_72404 == 184);
	if (cppVar_72406) {
	cppVar_72402 = IP;
	} else {
	cppVar_72408 = PC + 1;
	cppVar_72408 = (cppVar_72408 & cppMask_un_16_);
	cppVar_72409 = ROM.rd(cppVar_72408);
	cppVar_72411 = (cppVar_72409 == 208);
	if (cppVar_72411) {
	cppVar_72407 = PSW;
	} else {
	cppVar_72413 = PC + 1;
	cppVar_72413 = (cppVar_72413 & cppMask_un_16_);
	cppVar_72414 = ROM.rd(cppVar_72413);
	cppVar_72416 = (cppVar_72414 == 224);
	if (cppVar_72416) {
	cppVar_72412 = ACC;
	} else {
	cppVar_72418 = PC + 1;
	cppVar_72418 = (cppVar_72418 & cppMask_un_16_);
	cppVar_72419 = ROM.rd(cppVar_72418);
	cppVar_72421 = (cppVar_72419 == 240);
	if (cppVar_72421) {
	cppVar_72417 = B;
	} else {
	cppVar_72417 = 0;
	}
	cppVar_72412 = cppVar_72417;
	}
	cppVar_72407 = cppVar_72412;
	}
	cppVar_72402 = cppVar_72407;
	}
	cppVar_72397 = cppVar_72402;
	}
	cppVar_72392 = cppVar_72397;
	}
	cppVar_72387 = cppVar_72392;
	}
	cppVar_72382 = cppVar_72387;
	}
	cppVar_72377 = cppVar_72382;
	}
	cppVar_72372 = cppVar_72377;
	}
	cppVar_72367 = cppVar_72372;
	}
	cppVar_72362 = cppVar_72367;
	}
	cppVar_72357 = cppVar_72362;
	}
	cppVar_72352 = cppVar_72357;
	}
	cppVar_72347 = cppVar_72352;
	}
	cppVar_72342 = cppVar_72347;
	}
	cppVar_72337 = cppVar_72342;
	}
	cppVar_72332 = cppVar_72337;
	}
	cppVar_72327 = cppVar_72332;
	}
	cppVar_72322 = cppVar_72327;
	}
	cppVar_72317 = cppVar_72322;
	}
	cppVar_72308 = cppVar_72317;
	}
	cppVar_72424 = cppVar_72308 + 1;
	cppVar_72424 = (cppVar_72424 & cppMask_un_8_);
	cppVar_72302 = cppVar_72424;
	} else {
	cppVar_72302 = TCON;
	}
	cppVar_72298 = cppVar_72302;
	} else {
	cppVar_72298 = TCON;
	}
	cppVar_71862 = cppVar_72298;
	}
	cppVar_71731 = cppVar_71862;
	}
	cppVar_71605 = cppVar_71731;
	}
	cppVar_71476 = cppVar_71605;
	}
	cppVar_71350 = cppVar_71476;
	}
	cppVar_71221 = cppVar_71350;
	}
	cppVar_71095 = cppVar_71221;
	}
	cppVar_70966 = cppVar_71095;
	}
	cppVar_70953 = cppVar_70966;
	}
	cppVar_70827 = cppVar_70953;
	}
	cppVar_70810 = cppVar_70827;
	}
	cppVar_70793 = cppVar_70810;
	}
	cppVar_70643 = cppVar_70793;
	}
	cppVar_70493 = cppVar_70643;
	}
	cppVar_70343 = cppVar_70493;
	}
	cppVar_70193 = cppVar_70343;
	}
	cppVar_70043 = cppVar_70193;
	}
	cppVar_69893 = cppVar_70043;
	}
	cppVar_69743 = cppVar_69893;
	}
	cppVar_69593 = cppVar_69743;
	}
	cppVar_69161 = cppVar_69593;
	}
	cppVar_68331 = cppVar_69161;
	}
	cppVar_68317 = cppVar_68331;
	}
	cppVar_68306 = cppVar_68317;
	}
	cppVar_67874 = cppVar_68306;
	}
	return cppVar_67874;
}
