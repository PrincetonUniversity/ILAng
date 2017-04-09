#include "common.hpp"
#include "model_oc8051_class.hpp"

BIT_VEC model_oc8051::cppUpdateFun_IP()
{
	BIT_VEC cppVar_17986;
	BIT_VEC cppVar_17987;
	bool cppVar_17988;
	BIT_VEC cppVar_17991;
	BIT_VEC cppVar_17992;
	BIT_VEC cppVar_17993;
	BIT_VEC cppVar_17994;
	BIT_VEC cppVar_17995;
	bool cppVar_17996;
	BIT_VEC cppVar_17997;
	BIT_VEC cppVar_17998;
	BIT_VEC cppVar_17999;
	BIT_VEC cppVar_18000;
	BIT_VEC cppVar_18001;
	BIT_VEC cppVar_18002;
	BIT_VEC cppVar_18003;
	BIT_VEC cppVar_18004;
	BIT_VEC cppVar_18005;
	BIT_VEC cppVar_18006;
	BIT_VEC cppVar_18007;
	BIT_VEC cppVar_17990;
	BIT_VEC cppVar_18008;
	bool cppVar_18009;
	BIT_VEC cppVar_18010;
	BIT_VEC cppVar_18011;
	BIT_VEC cppVar_18012;
	BIT_VEC cppVar_18013;
	BIT_VEC cppVar_18014;
	BIT_VEC cppVar_18015;
	BIT_VEC cppVar_18016;
	BIT_VEC cppVar_18019;
	BIT_VEC cppVar_18020;
	BIT_VEC cppVar_18021;
	bool cppVar_18022;
	BIT_VEC cppVar_18023;
	BIT_VEC cppVar_18024;
	BIT_VEC cppVar_18025;
	BIT_VEC cppVar_18026;
	BIT_VEC cppVar_18027;
	BIT_VEC cppVar_18028;
	BIT_VEC cppVar_18029;
	BIT_VEC cppVar_18030;
	BIT_VEC cppVar_18031;
	BIT_VEC cppVar_18018;
	BIT_VEC cppVar_18032;
	BIT_VEC cppVar_18033;
	bool cppVar_18034;
	BIT_VEC cppVar_18036;
	BIT_VEC cppVar_18037;
	BIT_VEC cppVar_18038;
	bool cppVar_18039;
	BIT_VEC cppVar_18040;
	BIT_VEC cppVar_18041;
	BIT_VEC cppVar_18042;
	BIT_VEC cppVar_18043;
	BIT_VEC cppVar_18044;
	BIT_VEC cppVar_18045;
	BIT_VEC cppVar_18046;
	BIT_VEC cppVar_18047;
	BIT_VEC cppVar_18048;
	BIT_VEC cppVar_18035;
	BIT_VEC cppVar_18049;
	BIT_VEC cppVar_18052;
	BIT_VEC cppVar_18053;
	BIT_VEC cppVar_18054;
	bool cppVar_18055;
	BIT_VEC cppVar_18056;
	BIT_VEC cppVar_18057;
	BIT_VEC cppVar_18058;
	BIT_VEC cppVar_18059;
	BIT_VEC cppVar_18060;
	BIT_VEC cppVar_18061;
	BIT_VEC cppVar_18062;
	BIT_VEC cppVar_18063;
	BIT_VEC cppVar_18064;
	BIT_VEC cppVar_18051;
	BIT_VEC cppVar_18065;
	bool cppVar_18066;
	BIT_VEC cppVar_18069;
	BIT_VEC cppVar_18070;
	BIT_VEC cppVar_18071;
	bool cppVar_18072;
	BIT_VEC cppVar_18073;
	BIT_VEC cppVar_18074;
	BIT_VEC cppVar_18075;
	BIT_VEC cppVar_18076;
	BIT_VEC cppVar_18077;
	BIT_VEC cppVar_18078;
	BIT_VEC cppVar_18079;
	BIT_VEC cppVar_18080;
	BIT_VEC cppVar_18081;
	BIT_VEC cppVar_18068;
	BIT_VEC cppVar_18082;
	bool cppVar_18083;
	BIT_VEC cppVar_18086;
	BIT_VEC cppVar_18087;
	BIT_VEC cppVar_18088;
	bool cppVar_18089;
	BIT_VEC cppVar_18090;
	BIT_VEC cppVar_18091;
	BIT_VEC cppVar_18092;
	BIT_VEC cppVar_18093;
	BIT_VEC cppVar_18094;
	BIT_VEC cppVar_18095;
	BIT_VEC cppVar_18096;
	BIT_VEC cppVar_18097;
	BIT_VEC cppVar_18098;
	BIT_VEC cppVar_18085;
	BIT_VEC cppVar_18099;
	bool cppVar_18100;
	BIT_VEC cppVar_18103;
	BIT_VEC cppVar_18104;
	BIT_VEC cppVar_18105;
	bool cppVar_18106;
	BIT_VEC cppVar_18107;
	BIT_VEC cppVar_18108;
	BIT_VEC cppVar_18109;
	BIT_VEC cppVar_18110;
	BIT_VEC cppVar_18111;
	BIT_VEC cppVar_18112;
	BIT_VEC cppVar_18113;
	BIT_VEC cppVar_18114;
	BIT_VEC cppVar_18115;
	BIT_VEC cppVar_18102;
	BIT_VEC cppVar_18116;
	bool cppVar_18117;
	BIT_VEC cppVar_18120;
	BIT_VEC cppVar_18121;
	BIT_VEC cppVar_18122;
	bool cppVar_18123;
	BIT_VEC cppVar_18124;
	BIT_VEC cppVar_18125;
	BIT_VEC cppVar_18126;
	BIT_VEC cppVar_18127;
	BIT_VEC cppVar_18128;
	BIT_VEC cppVar_18129;
	BIT_VEC cppVar_18130;
	BIT_VEC cppVar_18131;
	BIT_VEC cppVar_18132;
	BIT_VEC cppVar_18119;
	BIT_VEC cppVar_18133;
	bool cppVar_18134;
	BIT_VEC cppVar_18137;
	BIT_VEC cppVar_18138;
	BIT_VEC cppVar_18139;
	bool cppVar_18140;
	BIT_VEC cppVar_18141;
	BIT_VEC cppVar_18142;
	BIT_VEC cppVar_18143;
	BIT_VEC cppVar_18144;
	BIT_VEC cppVar_18145;
	BIT_VEC cppVar_18146;
	BIT_VEC cppVar_18147;
	BIT_VEC cppVar_18148;
	BIT_VEC cppVar_18149;
	BIT_VEC cppVar_18136;
	BIT_VEC cppVar_18150;
	bool cppVar_18151;
	BIT_VEC cppVar_18154;
	BIT_VEC cppVar_18155;
	BIT_VEC cppVar_18156;
	bool cppVar_18157;
	BIT_VEC cppVar_18158;
	BIT_VEC cppVar_18159;
	BIT_VEC cppVar_18160;
	BIT_VEC cppVar_18161;
	BIT_VEC cppVar_18162;
	BIT_VEC cppVar_18163;
	BIT_VEC cppVar_18164;
	BIT_VEC cppVar_18165;
	BIT_VEC cppVar_18166;
	BIT_VEC cppVar_18153;
	BIT_VEC cppVar_18167;
	bool cppVar_18168;
	BIT_VEC cppVar_18171;
	BIT_VEC cppVar_18172;
	BIT_VEC cppVar_18173;
	bool cppVar_18174;
	BIT_VEC cppVar_18175;
	BIT_VEC cppVar_18176;
	BIT_VEC cppVar_18177;
	BIT_VEC cppVar_18178;
	BIT_VEC cppVar_18179;
	BIT_VEC cppVar_18180;
	BIT_VEC cppVar_18181;
	BIT_VEC cppVar_18182;
	BIT_VEC cppVar_18183;
	BIT_VEC cppVar_18170;
	BIT_VEC cppVar_18184;
	bool cppVar_18185;
	BIT_VEC cppVar_18188;
	BIT_VEC cppVar_18189;
	BIT_VEC cppVar_18190;
	bool cppVar_18191;
	BIT_VEC cppVar_18192;
	BIT_VEC cppVar_18193;
	BIT_VEC cppVar_18194;
	BIT_VEC cppVar_18195;
	BIT_VEC cppVar_18196;
	BIT_VEC cppVar_18197;
	BIT_VEC cppVar_18198;
	BIT_VEC cppVar_18199;
	BIT_VEC cppVar_18200;
	BIT_VEC cppVar_18187;
	BIT_VEC cppVar_18201;
	bool cppVar_18202;
	BIT_VEC cppVar_18205;
	BIT_VEC cppVar_18206;
	BIT_VEC cppVar_18207;
	bool cppVar_18208;
	BIT_VEC cppVar_18209;
	BIT_VEC cppVar_18210;
	BIT_VEC cppVar_18211;
	BIT_VEC cppVar_18212;
	BIT_VEC cppVar_18213;
	BIT_VEC cppVar_18214;
	BIT_VEC cppVar_18215;
	BIT_VEC cppVar_18216;
	BIT_VEC cppVar_18217;
	BIT_VEC cppVar_18204;
	BIT_VEC cppVar_18218;
	bool cppVar_18219;
	BIT_VEC cppVar_18222;
	BIT_VEC cppVar_18223;
	BIT_VEC cppVar_18224;
	bool cppVar_18225;
	BIT_VEC cppVar_18226;
	BIT_VEC cppVar_18227;
	BIT_VEC cppVar_18228;
	BIT_VEC cppVar_18229;
	BIT_VEC cppVar_18230;
	BIT_VEC cppVar_18231;
	BIT_VEC cppVar_18232;
	BIT_VEC cppVar_18233;
	BIT_VEC cppVar_18234;
	BIT_VEC cppVar_18221;
	BIT_VEC cppVar_18235;
	bool cppVar_18236;
	BIT_VEC cppVar_18239;
	BIT_VEC cppVar_18240;
	BIT_VEC cppVar_18241;
	bool cppVar_18242;
	BIT_VEC cppVar_18243;
	BIT_VEC cppVar_18244;
	BIT_VEC cppVar_18245;
	BIT_VEC cppVar_18246;
	BIT_VEC cppVar_18247;
	BIT_VEC cppVar_18248;
	BIT_VEC cppVar_18249;
	BIT_VEC cppVar_18250;
	BIT_VEC cppVar_18251;
	BIT_VEC cppVar_18238;
	BIT_VEC cppVar_18252;
	bool cppVar_18253;
	BIT_VEC cppVar_18256;
	BIT_VEC cppVar_18257;
	BIT_VEC cppVar_18258;
	bool cppVar_18259;
	BIT_VEC cppVar_18260;
	BIT_VEC cppVar_18261;
	BIT_VEC cppVar_18262;
	BIT_VEC cppVar_18263;
	BIT_VEC cppVar_18264;
	BIT_VEC cppVar_18265;
	BIT_VEC cppVar_18266;
	BIT_VEC cppVar_18267;
	BIT_VEC cppVar_18268;
	BIT_VEC cppVar_18255;
	BIT_VEC cppVar_18269;
	bool cppVar_18270;
	BIT_VEC cppVar_18273;
	BIT_VEC cppVar_18274;
	BIT_VEC cppVar_18275;
	bool cppVar_18276;
	BIT_VEC cppVar_18277;
	BIT_VEC cppVar_18278;
	BIT_VEC cppVar_18279;
	BIT_VEC cppVar_18280;
	BIT_VEC cppVar_18281;
	BIT_VEC cppVar_18282;
	BIT_VEC cppVar_18283;
	BIT_VEC cppVar_18284;
	BIT_VEC cppVar_18285;
	BIT_VEC cppVar_18272;
	BIT_VEC cppVar_18286;
	bool cppVar_18287;
	BIT_VEC cppVar_18290;
	BIT_VEC cppVar_18291;
	BIT_VEC cppVar_18292;
	bool cppVar_18293;
	BIT_VEC cppVar_18294;
	BIT_VEC cppVar_18295;
	BIT_VEC cppVar_18296;
	BIT_VEC cppVar_18297;
	BIT_VEC cppVar_18298;
	BIT_VEC cppVar_18299;
	BIT_VEC cppVar_18300;
	BIT_VEC cppVar_18301;
	BIT_VEC cppVar_18302;
	BIT_VEC cppVar_18289;
	BIT_VEC cppVar_18303;
	bool cppVar_18304;
	BIT_VEC cppVar_18307;
	BIT_VEC cppVar_18308;
	BIT_VEC cppVar_18309;
	bool cppVar_18310;
	BIT_VEC cppVar_18311;
	BIT_VEC cppVar_18312;
	BIT_VEC cppVar_18313;
	BIT_VEC cppVar_18314;
	BIT_VEC cppVar_18315;
	BIT_VEC cppVar_18316;
	BIT_VEC cppVar_18317;
	BIT_VEC cppVar_18318;
	BIT_VEC cppVar_18319;
	BIT_VEC cppVar_18306;
	BIT_VEC cppVar_18320;
	bool cppVar_18321;
	BIT_VEC cppVar_18324;
	BIT_VEC cppVar_18325;
	BIT_VEC cppVar_18326;
	bool cppVar_18327;
	BIT_VEC cppVar_18328;
	BIT_VEC cppVar_18329;
	BIT_VEC cppVar_18330;
	BIT_VEC cppVar_18331;
	BIT_VEC cppVar_18332;
	BIT_VEC cppVar_18333;
	BIT_VEC cppVar_18334;
	BIT_VEC cppVar_18335;
	BIT_VEC cppVar_18336;
	BIT_VEC cppVar_18323;
	BIT_VEC cppVar_18337;
	bool cppVar_18338;
	BIT_VEC cppVar_18341;
	BIT_VEC cppVar_18342;
	BIT_VEC cppVar_18343;
	bool cppVar_18344;
	BIT_VEC cppVar_18345;
	BIT_VEC cppVar_18346;
	BIT_VEC cppVar_18347;
	BIT_VEC cppVar_18348;
	BIT_VEC cppVar_18349;
	BIT_VEC cppVar_18350;
	BIT_VEC cppVar_18351;
	BIT_VEC cppVar_18352;
	BIT_VEC cppVar_18353;
	BIT_VEC cppVar_18340;
	BIT_VEC cppVar_18354;
	bool cppVar_18355;
	BIT_VEC cppVar_18358;
	BIT_VEC cppVar_18359;
	BIT_VEC cppVar_18360;
	bool cppVar_18361;
	BIT_VEC cppVar_18362;
	BIT_VEC cppVar_18363;
	BIT_VEC cppVar_18364;
	BIT_VEC cppVar_18365;
	BIT_VEC cppVar_18366;
	BIT_VEC cppVar_18367;
	BIT_VEC cppVar_18368;
	BIT_VEC cppVar_18369;
	BIT_VEC cppVar_18370;
	BIT_VEC cppVar_18357;
	BIT_VEC cppVar_18371;
	bool cppVar_18372;
	BIT_VEC cppVar_18375;
	BIT_VEC cppVar_18376;
	BIT_VEC cppVar_18377;
	bool cppVar_18378;
	BIT_VEC cppVar_18379;
	BIT_VEC cppVar_18380;
	BIT_VEC cppVar_18381;
	BIT_VEC cppVar_18382;
	BIT_VEC cppVar_18383;
	BIT_VEC cppVar_18384;
	BIT_VEC cppVar_18385;
	BIT_VEC cppVar_18386;
	BIT_VEC cppVar_18387;
	BIT_VEC cppVar_18374;
	BIT_VEC cppVar_18388;
	bool cppVar_18389;
	BIT_VEC cppVar_18392;
	BIT_VEC cppVar_18393;
	BIT_VEC cppVar_18394;
	bool cppVar_18395;
	BIT_VEC cppVar_18396;
	BIT_VEC cppVar_18397;
	BIT_VEC cppVar_18398;
	BIT_VEC cppVar_18399;
	BIT_VEC cppVar_18400;
	BIT_VEC cppVar_18401;
	BIT_VEC cppVar_18402;
	BIT_VEC cppVar_18403;
	BIT_VEC cppVar_18404;
	BIT_VEC cppVar_18391;
	BIT_VEC cppVar_18405;
	bool cppVar_18406;
	BIT_VEC cppVar_18407;
	BIT_VEC cppVar_18390;
	BIT_VEC cppVar_18373;
	BIT_VEC cppVar_18356;
	BIT_VEC cppVar_18339;
	BIT_VEC cppVar_18322;
	BIT_VEC cppVar_18305;
	BIT_VEC cppVar_18288;
	BIT_VEC cppVar_18271;
	BIT_VEC cppVar_18254;
	BIT_VEC cppVar_18237;
	BIT_VEC cppVar_18220;
	BIT_VEC cppVar_18203;
	BIT_VEC cppVar_18186;
	BIT_VEC cppVar_18169;
	BIT_VEC cppVar_18152;
	BIT_VEC cppVar_18135;
	BIT_VEC cppVar_18118;
	BIT_VEC cppVar_18101;
	BIT_VEC cppVar_18084;
	BIT_VEC cppVar_18067;
	BIT_VEC cppVar_18050;
	BIT_VEC cppVar_18017;
	BIT_VEC cppVar_18408;
	BIT_VEC cppVar_18409;
	BIT_VEC cppVar_18410;
	BIT_VEC cppVar_18411;
	BIT_VEC cppVar_18412;
	BIT_VEC cppVar_18413;
	BIT_VEC cppVar_18414;
	BIT_VEC cppVar_18415;
	BIT_VEC cppVar_18416;
	BIT_VEC cppVar_17989;
	BIT_VEC cppVar_18418;
	BIT_VEC cppVar_18419;
	bool cppVar_18420;
	BIT_VEC cppVar_18422;
	BIT_VEC cppVar_18423;
	BIT_VEC cppVar_18424;
	BIT_VEC cppVar_18425;
	bool cppVar_18426;
	BIT_VEC cppVar_18427;
	BIT_VEC cppVar_18421;
	BIT_VEC cppVar_18429;
	BIT_VEC cppVar_18430;
	bool cppVar_18431;
	BIT_VEC cppVar_18432;
	BIT_VEC cppVar_18433;
	bool cppVar_18434;
	bool cppVar_18435;
	BIT_VEC cppVar_18437;
	BIT_VEC cppVar_18438;
	BIT_VEC cppVar_18439;
	BIT_VEC cppVar_18440;
	bool cppVar_18441;
	BIT_VEC cppVar_18436;
	BIT_VEC cppVar_18443;
	BIT_VEC cppVar_18444;
	bool cppVar_18445;
	BIT_VEC cppVar_18448;
	BIT_VEC cppVar_18449;
	BIT_VEC cppVar_18450;
	BIT_VEC cppVar_18451;
	BIT_VEC cppVar_18452;
	bool cppVar_18453;
	BIT_VEC cppVar_18454;
	BIT_VEC cppVar_18455;
	BIT_VEC cppVar_18456;
	BIT_VEC cppVar_18457;
	BIT_VEC cppVar_18458;
	BIT_VEC cppVar_18459;
	BIT_VEC cppVar_18460;
	BIT_VEC cppVar_18461;
	BIT_VEC cppVar_18462;
	BIT_VEC cppVar_18463;
	BIT_VEC cppVar_18464;
	BIT_VEC cppVar_18447;
	BIT_VEC cppVar_18465;
	bool cppVar_18466;
	BIT_VEC cppVar_18467;
	BIT_VEC cppVar_18468;
	BIT_VEC cppVar_18469;
	BIT_VEC cppVar_18470;
	BIT_VEC cppVar_18471;
	BIT_VEC cppVar_18472;
	BIT_VEC cppVar_18473;
	BIT_VEC cppVar_18476;
	BIT_VEC cppVar_18477;
	BIT_VEC cppVar_18478;
	bool cppVar_18479;
	BIT_VEC cppVar_18480;
	BIT_VEC cppVar_18481;
	BIT_VEC cppVar_18482;
	BIT_VEC cppVar_18483;
	BIT_VEC cppVar_18484;
	BIT_VEC cppVar_18485;
	BIT_VEC cppVar_18486;
	BIT_VEC cppVar_18487;
	BIT_VEC cppVar_18488;
	BIT_VEC cppVar_18475;
	BIT_VEC cppVar_18489;
	BIT_VEC cppVar_18490;
	bool cppVar_18491;
	BIT_VEC cppVar_18493;
	BIT_VEC cppVar_18494;
	BIT_VEC cppVar_18495;
	bool cppVar_18496;
	BIT_VEC cppVar_18497;
	BIT_VEC cppVar_18498;
	BIT_VEC cppVar_18499;
	BIT_VEC cppVar_18500;
	BIT_VEC cppVar_18501;
	BIT_VEC cppVar_18502;
	BIT_VEC cppVar_18503;
	BIT_VEC cppVar_18504;
	BIT_VEC cppVar_18505;
	BIT_VEC cppVar_18492;
	BIT_VEC cppVar_18506;
	BIT_VEC cppVar_18509;
	BIT_VEC cppVar_18510;
	BIT_VEC cppVar_18511;
	bool cppVar_18512;
	BIT_VEC cppVar_18513;
	BIT_VEC cppVar_18514;
	BIT_VEC cppVar_18515;
	BIT_VEC cppVar_18516;
	BIT_VEC cppVar_18517;
	BIT_VEC cppVar_18518;
	BIT_VEC cppVar_18519;
	BIT_VEC cppVar_18520;
	BIT_VEC cppVar_18521;
	BIT_VEC cppVar_18508;
	BIT_VEC cppVar_18522;
	bool cppVar_18523;
	BIT_VEC cppVar_18526;
	BIT_VEC cppVar_18527;
	BIT_VEC cppVar_18528;
	bool cppVar_18529;
	BIT_VEC cppVar_18530;
	BIT_VEC cppVar_18531;
	BIT_VEC cppVar_18532;
	BIT_VEC cppVar_18533;
	BIT_VEC cppVar_18534;
	BIT_VEC cppVar_18535;
	BIT_VEC cppVar_18536;
	BIT_VEC cppVar_18537;
	BIT_VEC cppVar_18538;
	BIT_VEC cppVar_18525;
	BIT_VEC cppVar_18539;
	bool cppVar_18540;
	BIT_VEC cppVar_18543;
	BIT_VEC cppVar_18544;
	BIT_VEC cppVar_18545;
	bool cppVar_18546;
	BIT_VEC cppVar_18547;
	BIT_VEC cppVar_18548;
	BIT_VEC cppVar_18549;
	BIT_VEC cppVar_18550;
	BIT_VEC cppVar_18551;
	BIT_VEC cppVar_18552;
	BIT_VEC cppVar_18553;
	BIT_VEC cppVar_18554;
	BIT_VEC cppVar_18555;
	BIT_VEC cppVar_18542;
	BIT_VEC cppVar_18556;
	bool cppVar_18557;
	BIT_VEC cppVar_18560;
	BIT_VEC cppVar_18561;
	BIT_VEC cppVar_18562;
	bool cppVar_18563;
	BIT_VEC cppVar_18564;
	BIT_VEC cppVar_18565;
	BIT_VEC cppVar_18566;
	BIT_VEC cppVar_18567;
	BIT_VEC cppVar_18568;
	BIT_VEC cppVar_18569;
	BIT_VEC cppVar_18570;
	BIT_VEC cppVar_18571;
	BIT_VEC cppVar_18572;
	BIT_VEC cppVar_18559;
	BIT_VEC cppVar_18573;
	bool cppVar_18574;
	BIT_VEC cppVar_18577;
	BIT_VEC cppVar_18578;
	BIT_VEC cppVar_18579;
	bool cppVar_18580;
	BIT_VEC cppVar_18581;
	BIT_VEC cppVar_18582;
	BIT_VEC cppVar_18583;
	BIT_VEC cppVar_18584;
	BIT_VEC cppVar_18585;
	BIT_VEC cppVar_18586;
	BIT_VEC cppVar_18587;
	BIT_VEC cppVar_18588;
	BIT_VEC cppVar_18589;
	BIT_VEC cppVar_18576;
	BIT_VEC cppVar_18590;
	bool cppVar_18591;
	BIT_VEC cppVar_18594;
	BIT_VEC cppVar_18595;
	BIT_VEC cppVar_18596;
	bool cppVar_18597;
	BIT_VEC cppVar_18598;
	BIT_VEC cppVar_18599;
	BIT_VEC cppVar_18600;
	BIT_VEC cppVar_18601;
	BIT_VEC cppVar_18602;
	BIT_VEC cppVar_18603;
	BIT_VEC cppVar_18604;
	BIT_VEC cppVar_18605;
	BIT_VEC cppVar_18606;
	BIT_VEC cppVar_18593;
	BIT_VEC cppVar_18607;
	bool cppVar_18608;
	BIT_VEC cppVar_18611;
	BIT_VEC cppVar_18612;
	BIT_VEC cppVar_18613;
	bool cppVar_18614;
	BIT_VEC cppVar_18615;
	BIT_VEC cppVar_18616;
	BIT_VEC cppVar_18617;
	BIT_VEC cppVar_18618;
	BIT_VEC cppVar_18619;
	BIT_VEC cppVar_18620;
	BIT_VEC cppVar_18621;
	BIT_VEC cppVar_18622;
	BIT_VEC cppVar_18623;
	BIT_VEC cppVar_18610;
	BIT_VEC cppVar_18624;
	bool cppVar_18625;
	BIT_VEC cppVar_18628;
	BIT_VEC cppVar_18629;
	BIT_VEC cppVar_18630;
	bool cppVar_18631;
	BIT_VEC cppVar_18632;
	BIT_VEC cppVar_18633;
	BIT_VEC cppVar_18634;
	BIT_VEC cppVar_18635;
	BIT_VEC cppVar_18636;
	BIT_VEC cppVar_18637;
	BIT_VEC cppVar_18638;
	BIT_VEC cppVar_18639;
	BIT_VEC cppVar_18640;
	BIT_VEC cppVar_18627;
	BIT_VEC cppVar_18641;
	bool cppVar_18642;
	BIT_VEC cppVar_18645;
	BIT_VEC cppVar_18646;
	BIT_VEC cppVar_18647;
	bool cppVar_18648;
	BIT_VEC cppVar_18649;
	BIT_VEC cppVar_18650;
	BIT_VEC cppVar_18651;
	BIT_VEC cppVar_18652;
	BIT_VEC cppVar_18653;
	BIT_VEC cppVar_18654;
	BIT_VEC cppVar_18655;
	BIT_VEC cppVar_18656;
	BIT_VEC cppVar_18657;
	BIT_VEC cppVar_18644;
	BIT_VEC cppVar_18658;
	bool cppVar_18659;
	BIT_VEC cppVar_18662;
	BIT_VEC cppVar_18663;
	BIT_VEC cppVar_18664;
	bool cppVar_18665;
	BIT_VEC cppVar_18666;
	BIT_VEC cppVar_18667;
	BIT_VEC cppVar_18668;
	BIT_VEC cppVar_18669;
	BIT_VEC cppVar_18670;
	BIT_VEC cppVar_18671;
	BIT_VEC cppVar_18672;
	BIT_VEC cppVar_18673;
	BIT_VEC cppVar_18674;
	BIT_VEC cppVar_18661;
	BIT_VEC cppVar_18675;
	bool cppVar_18676;
	BIT_VEC cppVar_18679;
	BIT_VEC cppVar_18680;
	BIT_VEC cppVar_18681;
	bool cppVar_18682;
	BIT_VEC cppVar_18683;
	BIT_VEC cppVar_18684;
	BIT_VEC cppVar_18685;
	BIT_VEC cppVar_18686;
	BIT_VEC cppVar_18687;
	BIT_VEC cppVar_18688;
	BIT_VEC cppVar_18689;
	BIT_VEC cppVar_18690;
	BIT_VEC cppVar_18691;
	BIT_VEC cppVar_18678;
	BIT_VEC cppVar_18692;
	bool cppVar_18693;
	BIT_VEC cppVar_18696;
	BIT_VEC cppVar_18697;
	BIT_VEC cppVar_18698;
	bool cppVar_18699;
	BIT_VEC cppVar_18700;
	BIT_VEC cppVar_18701;
	BIT_VEC cppVar_18702;
	BIT_VEC cppVar_18703;
	BIT_VEC cppVar_18704;
	BIT_VEC cppVar_18705;
	BIT_VEC cppVar_18706;
	BIT_VEC cppVar_18707;
	BIT_VEC cppVar_18708;
	BIT_VEC cppVar_18695;
	BIT_VEC cppVar_18709;
	bool cppVar_18710;
	BIT_VEC cppVar_18713;
	BIT_VEC cppVar_18714;
	BIT_VEC cppVar_18715;
	bool cppVar_18716;
	BIT_VEC cppVar_18717;
	BIT_VEC cppVar_18718;
	BIT_VEC cppVar_18719;
	BIT_VEC cppVar_18720;
	BIT_VEC cppVar_18721;
	BIT_VEC cppVar_18722;
	BIT_VEC cppVar_18723;
	BIT_VEC cppVar_18724;
	BIT_VEC cppVar_18725;
	BIT_VEC cppVar_18712;
	BIT_VEC cppVar_18726;
	bool cppVar_18727;
	BIT_VEC cppVar_18730;
	BIT_VEC cppVar_18731;
	BIT_VEC cppVar_18732;
	bool cppVar_18733;
	BIT_VEC cppVar_18734;
	BIT_VEC cppVar_18735;
	BIT_VEC cppVar_18736;
	BIT_VEC cppVar_18737;
	BIT_VEC cppVar_18738;
	BIT_VEC cppVar_18739;
	BIT_VEC cppVar_18740;
	BIT_VEC cppVar_18741;
	BIT_VEC cppVar_18742;
	BIT_VEC cppVar_18729;
	BIT_VEC cppVar_18743;
	bool cppVar_18744;
	BIT_VEC cppVar_18747;
	BIT_VEC cppVar_18748;
	BIT_VEC cppVar_18749;
	bool cppVar_18750;
	BIT_VEC cppVar_18751;
	BIT_VEC cppVar_18752;
	BIT_VEC cppVar_18753;
	BIT_VEC cppVar_18754;
	BIT_VEC cppVar_18755;
	BIT_VEC cppVar_18756;
	BIT_VEC cppVar_18757;
	BIT_VEC cppVar_18758;
	BIT_VEC cppVar_18759;
	BIT_VEC cppVar_18746;
	BIT_VEC cppVar_18760;
	bool cppVar_18761;
	BIT_VEC cppVar_18764;
	BIT_VEC cppVar_18765;
	BIT_VEC cppVar_18766;
	bool cppVar_18767;
	BIT_VEC cppVar_18768;
	BIT_VEC cppVar_18769;
	BIT_VEC cppVar_18770;
	BIT_VEC cppVar_18771;
	BIT_VEC cppVar_18772;
	BIT_VEC cppVar_18773;
	BIT_VEC cppVar_18774;
	BIT_VEC cppVar_18775;
	BIT_VEC cppVar_18776;
	BIT_VEC cppVar_18763;
	BIT_VEC cppVar_18777;
	bool cppVar_18778;
	BIT_VEC cppVar_18781;
	BIT_VEC cppVar_18782;
	BIT_VEC cppVar_18783;
	bool cppVar_18784;
	BIT_VEC cppVar_18785;
	BIT_VEC cppVar_18786;
	BIT_VEC cppVar_18787;
	BIT_VEC cppVar_18788;
	BIT_VEC cppVar_18789;
	BIT_VEC cppVar_18790;
	BIT_VEC cppVar_18791;
	BIT_VEC cppVar_18792;
	BIT_VEC cppVar_18793;
	BIT_VEC cppVar_18780;
	BIT_VEC cppVar_18794;
	bool cppVar_18795;
	BIT_VEC cppVar_18798;
	BIT_VEC cppVar_18799;
	BIT_VEC cppVar_18800;
	bool cppVar_18801;
	BIT_VEC cppVar_18802;
	BIT_VEC cppVar_18803;
	BIT_VEC cppVar_18804;
	BIT_VEC cppVar_18805;
	BIT_VEC cppVar_18806;
	BIT_VEC cppVar_18807;
	BIT_VEC cppVar_18808;
	BIT_VEC cppVar_18809;
	BIT_VEC cppVar_18810;
	BIT_VEC cppVar_18797;
	BIT_VEC cppVar_18811;
	bool cppVar_18812;
	BIT_VEC cppVar_18815;
	BIT_VEC cppVar_18816;
	BIT_VEC cppVar_18817;
	bool cppVar_18818;
	BIT_VEC cppVar_18819;
	BIT_VEC cppVar_18820;
	BIT_VEC cppVar_18821;
	BIT_VEC cppVar_18822;
	BIT_VEC cppVar_18823;
	BIT_VEC cppVar_18824;
	BIT_VEC cppVar_18825;
	BIT_VEC cppVar_18826;
	BIT_VEC cppVar_18827;
	BIT_VEC cppVar_18814;
	BIT_VEC cppVar_18828;
	bool cppVar_18829;
	BIT_VEC cppVar_18832;
	BIT_VEC cppVar_18833;
	BIT_VEC cppVar_18834;
	bool cppVar_18835;
	BIT_VEC cppVar_18836;
	BIT_VEC cppVar_18837;
	BIT_VEC cppVar_18838;
	BIT_VEC cppVar_18839;
	BIT_VEC cppVar_18840;
	BIT_VEC cppVar_18841;
	BIT_VEC cppVar_18842;
	BIT_VEC cppVar_18843;
	BIT_VEC cppVar_18844;
	BIT_VEC cppVar_18831;
	BIT_VEC cppVar_18845;
	bool cppVar_18846;
	BIT_VEC cppVar_18849;
	BIT_VEC cppVar_18850;
	BIT_VEC cppVar_18851;
	bool cppVar_18852;
	BIT_VEC cppVar_18853;
	BIT_VEC cppVar_18854;
	BIT_VEC cppVar_18855;
	BIT_VEC cppVar_18856;
	BIT_VEC cppVar_18857;
	BIT_VEC cppVar_18858;
	BIT_VEC cppVar_18859;
	BIT_VEC cppVar_18860;
	BIT_VEC cppVar_18861;
	BIT_VEC cppVar_18848;
	BIT_VEC cppVar_18862;
	bool cppVar_18863;
	BIT_VEC cppVar_18864;
	BIT_VEC cppVar_18847;
	BIT_VEC cppVar_18830;
	BIT_VEC cppVar_18813;
	BIT_VEC cppVar_18796;
	BIT_VEC cppVar_18779;
	BIT_VEC cppVar_18762;
	BIT_VEC cppVar_18745;
	BIT_VEC cppVar_18728;
	BIT_VEC cppVar_18711;
	BIT_VEC cppVar_18694;
	BIT_VEC cppVar_18677;
	BIT_VEC cppVar_18660;
	BIT_VEC cppVar_18643;
	BIT_VEC cppVar_18626;
	BIT_VEC cppVar_18609;
	BIT_VEC cppVar_18592;
	BIT_VEC cppVar_18575;
	BIT_VEC cppVar_18558;
	BIT_VEC cppVar_18541;
	BIT_VEC cppVar_18524;
	BIT_VEC cppVar_18507;
	BIT_VEC cppVar_18474;
	BIT_VEC cppVar_18865;
	BIT_VEC cppVar_18868;
	BIT_VEC cppVar_18869;
	BIT_VEC cppVar_18870;
	BIT_VEC cppVar_18871;
	bool cppVar_18872;
	BIT_VEC cppVar_18873;
	BIT_VEC cppVar_18874;
	BIT_VEC cppVar_18875;
	BIT_VEC cppVar_18876;
	BIT_VEC cppVar_18877;
	BIT_VEC cppVar_18878;
	BIT_VEC cppVar_18879;
	BIT_VEC cppVar_18880;
	BIT_VEC cppVar_18881;
	BIT_VEC cppVar_18882;
	BIT_VEC cppVar_18883;
	BIT_VEC cppVar_18867;
	BIT_VEC cppVar_18884;
	BIT_VEC cppVar_18885;
	bool cppVar_18886;
	BIT_VEC cppVar_18888;
	BIT_VEC cppVar_18889;
	BIT_VEC cppVar_18890;
	bool cppVar_18891;
	BIT_VEC cppVar_18892;
	BIT_VEC cppVar_18893;
	BIT_VEC cppVar_18894;
	BIT_VEC cppVar_18895;
	BIT_VEC cppVar_18896;
	BIT_VEC cppVar_18897;
	BIT_VEC cppVar_18898;
	BIT_VEC cppVar_18899;
	BIT_VEC cppVar_18900;
	BIT_VEC cppVar_18887;
	BIT_VEC cppVar_18901;
	BIT_VEC cppVar_18904;
	BIT_VEC cppVar_18905;
	BIT_VEC cppVar_18906;
	bool cppVar_18907;
	BIT_VEC cppVar_18908;
	BIT_VEC cppVar_18909;
	BIT_VEC cppVar_18910;
	BIT_VEC cppVar_18911;
	BIT_VEC cppVar_18912;
	BIT_VEC cppVar_18913;
	BIT_VEC cppVar_18914;
	BIT_VEC cppVar_18915;
	BIT_VEC cppVar_18916;
	BIT_VEC cppVar_18903;
	BIT_VEC cppVar_18917;
	bool cppVar_18918;
	BIT_VEC cppVar_18921;
	BIT_VEC cppVar_18922;
	BIT_VEC cppVar_18923;
	bool cppVar_18924;
	BIT_VEC cppVar_18925;
	BIT_VEC cppVar_18926;
	BIT_VEC cppVar_18927;
	BIT_VEC cppVar_18928;
	BIT_VEC cppVar_18929;
	BIT_VEC cppVar_18930;
	BIT_VEC cppVar_18931;
	BIT_VEC cppVar_18932;
	BIT_VEC cppVar_18933;
	BIT_VEC cppVar_18920;
	BIT_VEC cppVar_18934;
	bool cppVar_18935;
	BIT_VEC cppVar_18938;
	BIT_VEC cppVar_18939;
	BIT_VEC cppVar_18940;
	bool cppVar_18941;
	BIT_VEC cppVar_18942;
	BIT_VEC cppVar_18943;
	BIT_VEC cppVar_18944;
	BIT_VEC cppVar_18945;
	BIT_VEC cppVar_18946;
	BIT_VEC cppVar_18947;
	BIT_VEC cppVar_18948;
	BIT_VEC cppVar_18949;
	BIT_VEC cppVar_18950;
	BIT_VEC cppVar_18937;
	BIT_VEC cppVar_18951;
	bool cppVar_18952;
	BIT_VEC cppVar_18955;
	BIT_VEC cppVar_18956;
	BIT_VEC cppVar_18957;
	bool cppVar_18958;
	BIT_VEC cppVar_18959;
	BIT_VEC cppVar_18960;
	BIT_VEC cppVar_18961;
	BIT_VEC cppVar_18962;
	BIT_VEC cppVar_18963;
	BIT_VEC cppVar_18964;
	BIT_VEC cppVar_18965;
	BIT_VEC cppVar_18966;
	BIT_VEC cppVar_18967;
	BIT_VEC cppVar_18954;
	BIT_VEC cppVar_18968;
	bool cppVar_18969;
	BIT_VEC cppVar_18972;
	BIT_VEC cppVar_18973;
	BIT_VEC cppVar_18974;
	bool cppVar_18975;
	BIT_VEC cppVar_18976;
	BIT_VEC cppVar_18977;
	BIT_VEC cppVar_18978;
	BIT_VEC cppVar_18979;
	BIT_VEC cppVar_18980;
	BIT_VEC cppVar_18981;
	BIT_VEC cppVar_18982;
	BIT_VEC cppVar_18983;
	BIT_VEC cppVar_18984;
	BIT_VEC cppVar_18971;
	BIT_VEC cppVar_18985;
	bool cppVar_18986;
	BIT_VEC cppVar_18989;
	BIT_VEC cppVar_18990;
	BIT_VEC cppVar_18991;
	bool cppVar_18992;
	BIT_VEC cppVar_18993;
	BIT_VEC cppVar_18994;
	BIT_VEC cppVar_18995;
	BIT_VEC cppVar_18996;
	BIT_VEC cppVar_18997;
	BIT_VEC cppVar_18998;
	BIT_VEC cppVar_18999;
	BIT_VEC cppVar_19000;
	BIT_VEC cppVar_19001;
	BIT_VEC cppVar_18988;
	BIT_VEC cppVar_19002;
	bool cppVar_19003;
	BIT_VEC cppVar_19006;
	BIT_VEC cppVar_19007;
	BIT_VEC cppVar_19008;
	bool cppVar_19009;
	BIT_VEC cppVar_19010;
	BIT_VEC cppVar_19011;
	BIT_VEC cppVar_19012;
	BIT_VEC cppVar_19013;
	BIT_VEC cppVar_19014;
	BIT_VEC cppVar_19015;
	BIT_VEC cppVar_19016;
	BIT_VEC cppVar_19017;
	BIT_VEC cppVar_19018;
	BIT_VEC cppVar_19005;
	BIT_VEC cppVar_19019;
	bool cppVar_19020;
	BIT_VEC cppVar_19023;
	BIT_VEC cppVar_19024;
	BIT_VEC cppVar_19025;
	bool cppVar_19026;
	BIT_VEC cppVar_19027;
	BIT_VEC cppVar_19028;
	BIT_VEC cppVar_19029;
	BIT_VEC cppVar_19030;
	BIT_VEC cppVar_19031;
	BIT_VEC cppVar_19032;
	BIT_VEC cppVar_19033;
	BIT_VEC cppVar_19034;
	BIT_VEC cppVar_19035;
	BIT_VEC cppVar_19022;
	BIT_VEC cppVar_19036;
	bool cppVar_19037;
	BIT_VEC cppVar_19040;
	BIT_VEC cppVar_19041;
	BIT_VEC cppVar_19042;
	bool cppVar_19043;
	BIT_VEC cppVar_19044;
	BIT_VEC cppVar_19045;
	BIT_VEC cppVar_19046;
	BIT_VEC cppVar_19047;
	BIT_VEC cppVar_19048;
	BIT_VEC cppVar_19049;
	BIT_VEC cppVar_19050;
	BIT_VEC cppVar_19051;
	BIT_VEC cppVar_19052;
	BIT_VEC cppVar_19039;
	BIT_VEC cppVar_19053;
	bool cppVar_19054;
	BIT_VEC cppVar_19057;
	BIT_VEC cppVar_19058;
	BIT_VEC cppVar_19059;
	bool cppVar_19060;
	BIT_VEC cppVar_19061;
	BIT_VEC cppVar_19062;
	BIT_VEC cppVar_19063;
	BIT_VEC cppVar_19064;
	BIT_VEC cppVar_19065;
	BIT_VEC cppVar_19066;
	BIT_VEC cppVar_19067;
	BIT_VEC cppVar_19068;
	BIT_VEC cppVar_19069;
	BIT_VEC cppVar_19056;
	BIT_VEC cppVar_19070;
	bool cppVar_19071;
	BIT_VEC cppVar_19074;
	BIT_VEC cppVar_19075;
	BIT_VEC cppVar_19076;
	bool cppVar_19077;
	BIT_VEC cppVar_19078;
	BIT_VEC cppVar_19079;
	BIT_VEC cppVar_19080;
	BIT_VEC cppVar_19081;
	BIT_VEC cppVar_19082;
	BIT_VEC cppVar_19083;
	BIT_VEC cppVar_19084;
	BIT_VEC cppVar_19085;
	BIT_VEC cppVar_19086;
	BIT_VEC cppVar_19073;
	BIT_VEC cppVar_19087;
	bool cppVar_19088;
	BIT_VEC cppVar_19091;
	BIT_VEC cppVar_19092;
	BIT_VEC cppVar_19093;
	bool cppVar_19094;
	BIT_VEC cppVar_19095;
	BIT_VEC cppVar_19096;
	BIT_VEC cppVar_19097;
	BIT_VEC cppVar_19098;
	BIT_VEC cppVar_19099;
	BIT_VEC cppVar_19100;
	BIT_VEC cppVar_19101;
	BIT_VEC cppVar_19102;
	BIT_VEC cppVar_19103;
	BIT_VEC cppVar_19090;
	BIT_VEC cppVar_19104;
	bool cppVar_19105;
	BIT_VEC cppVar_19108;
	BIT_VEC cppVar_19109;
	BIT_VEC cppVar_19110;
	bool cppVar_19111;
	BIT_VEC cppVar_19112;
	BIT_VEC cppVar_19113;
	BIT_VEC cppVar_19114;
	BIT_VEC cppVar_19115;
	BIT_VEC cppVar_19116;
	BIT_VEC cppVar_19117;
	BIT_VEC cppVar_19118;
	BIT_VEC cppVar_19119;
	BIT_VEC cppVar_19120;
	BIT_VEC cppVar_19107;
	BIT_VEC cppVar_19121;
	bool cppVar_19122;
	BIT_VEC cppVar_19125;
	BIT_VEC cppVar_19126;
	BIT_VEC cppVar_19127;
	bool cppVar_19128;
	BIT_VEC cppVar_19129;
	BIT_VEC cppVar_19130;
	BIT_VEC cppVar_19131;
	BIT_VEC cppVar_19132;
	BIT_VEC cppVar_19133;
	BIT_VEC cppVar_19134;
	BIT_VEC cppVar_19135;
	BIT_VEC cppVar_19136;
	BIT_VEC cppVar_19137;
	BIT_VEC cppVar_19124;
	BIT_VEC cppVar_19138;
	bool cppVar_19139;
	BIT_VEC cppVar_19142;
	BIT_VEC cppVar_19143;
	BIT_VEC cppVar_19144;
	bool cppVar_19145;
	BIT_VEC cppVar_19146;
	BIT_VEC cppVar_19147;
	BIT_VEC cppVar_19148;
	BIT_VEC cppVar_19149;
	BIT_VEC cppVar_19150;
	BIT_VEC cppVar_19151;
	BIT_VEC cppVar_19152;
	BIT_VEC cppVar_19153;
	BIT_VEC cppVar_19154;
	BIT_VEC cppVar_19141;
	BIT_VEC cppVar_19155;
	bool cppVar_19156;
	BIT_VEC cppVar_19159;
	BIT_VEC cppVar_19160;
	BIT_VEC cppVar_19161;
	bool cppVar_19162;
	BIT_VEC cppVar_19163;
	BIT_VEC cppVar_19164;
	BIT_VEC cppVar_19165;
	BIT_VEC cppVar_19166;
	BIT_VEC cppVar_19167;
	BIT_VEC cppVar_19168;
	BIT_VEC cppVar_19169;
	BIT_VEC cppVar_19170;
	BIT_VEC cppVar_19171;
	BIT_VEC cppVar_19158;
	BIT_VEC cppVar_19172;
	bool cppVar_19173;
	BIT_VEC cppVar_19176;
	BIT_VEC cppVar_19177;
	BIT_VEC cppVar_19178;
	bool cppVar_19179;
	BIT_VEC cppVar_19180;
	BIT_VEC cppVar_19181;
	BIT_VEC cppVar_19182;
	BIT_VEC cppVar_19183;
	BIT_VEC cppVar_19184;
	BIT_VEC cppVar_19185;
	BIT_VEC cppVar_19186;
	BIT_VEC cppVar_19187;
	BIT_VEC cppVar_19188;
	BIT_VEC cppVar_19175;
	BIT_VEC cppVar_19189;
	bool cppVar_19190;
	BIT_VEC cppVar_19193;
	BIT_VEC cppVar_19194;
	BIT_VEC cppVar_19195;
	bool cppVar_19196;
	BIT_VEC cppVar_19197;
	BIT_VEC cppVar_19198;
	BIT_VEC cppVar_19199;
	BIT_VEC cppVar_19200;
	BIT_VEC cppVar_19201;
	BIT_VEC cppVar_19202;
	BIT_VEC cppVar_19203;
	BIT_VEC cppVar_19204;
	BIT_VEC cppVar_19205;
	BIT_VEC cppVar_19192;
	BIT_VEC cppVar_19206;
	bool cppVar_19207;
	BIT_VEC cppVar_19210;
	BIT_VEC cppVar_19211;
	BIT_VEC cppVar_19212;
	bool cppVar_19213;
	BIT_VEC cppVar_19214;
	BIT_VEC cppVar_19215;
	BIT_VEC cppVar_19216;
	BIT_VEC cppVar_19217;
	BIT_VEC cppVar_19218;
	BIT_VEC cppVar_19219;
	BIT_VEC cppVar_19220;
	BIT_VEC cppVar_19221;
	BIT_VEC cppVar_19222;
	BIT_VEC cppVar_19209;
	BIT_VEC cppVar_19223;
	bool cppVar_19224;
	BIT_VEC cppVar_19227;
	BIT_VEC cppVar_19228;
	BIT_VEC cppVar_19229;
	bool cppVar_19230;
	BIT_VEC cppVar_19231;
	BIT_VEC cppVar_19232;
	BIT_VEC cppVar_19233;
	BIT_VEC cppVar_19234;
	BIT_VEC cppVar_19235;
	BIT_VEC cppVar_19236;
	BIT_VEC cppVar_19237;
	BIT_VEC cppVar_19238;
	BIT_VEC cppVar_19239;
	BIT_VEC cppVar_19226;
	BIT_VEC cppVar_19240;
	bool cppVar_19241;
	BIT_VEC cppVar_19244;
	BIT_VEC cppVar_19245;
	BIT_VEC cppVar_19246;
	bool cppVar_19247;
	BIT_VEC cppVar_19248;
	BIT_VEC cppVar_19249;
	BIT_VEC cppVar_19250;
	BIT_VEC cppVar_19251;
	BIT_VEC cppVar_19252;
	BIT_VEC cppVar_19253;
	BIT_VEC cppVar_19254;
	BIT_VEC cppVar_19255;
	BIT_VEC cppVar_19256;
	BIT_VEC cppVar_19243;
	BIT_VEC cppVar_19257;
	bool cppVar_19258;
	BIT_VEC cppVar_19259;
	BIT_VEC cppVar_19242;
	BIT_VEC cppVar_19225;
	BIT_VEC cppVar_19208;
	BIT_VEC cppVar_19191;
	BIT_VEC cppVar_19174;
	BIT_VEC cppVar_19157;
	BIT_VEC cppVar_19140;
	BIT_VEC cppVar_19123;
	BIT_VEC cppVar_19106;
	BIT_VEC cppVar_19089;
	BIT_VEC cppVar_19072;
	BIT_VEC cppVar_19055;
	BIT_VEC cppVar_19038;
	BIT_VEC cppVar_19021;
	BIT_VEC cppVar_19004;
	BIT_VEC cppVar_18987;
	BIT_VEC cppVar_18970;
	BIT_VEC cppVar_18953;
	BIT_VEC cppVar_18936;
	BIT_VEC cppVar_18919;
	BIT_VEC cppVar_18902;
	BIT_VEC cppVar_18866;
	BIT_VEC cppVar_19260;
	BIT_VEC cppVar_19261;
	BIT_VEC cppVar_19262;
	BIT_VEC cppVar_19263;
	BIT_VEC cppVar_19264;
	BIT_VEC cppVar_19265;
	BIT_VEC cppVar_19266;
	BIT_VEC cppVar_19267;
	BIT_VEC cppVar_19268;
	BIT_VEC cppVar_19269;
	BIT_VEC cppVar_19270;
	BIT_VEC cppVar_19271;
	BIT_VEC cppVar_18446;
	BIT_VEC cppVar_19273;
	BIT_VEC cppVar_19274;
	bool cppVar_19275;
	BIT_VEC cppVar_19278;
	BIT_VEC cppVar_19279;
	BIT_VEC cppVar_19280;
	BIT_VEC cppVar_19281;
	BIT_VEC cppVar_19282;
	bool cppVar_19283;
	BIT_VEC cppVar_19284;
	BIT_VEC cppVar_19285;
	BIT_VEC cppVar_19286;
	BIT_VEC cppVar_19287;
	BIT_VEC cppVar_19288;
	BIT_VEC cppVar_19289;
	BIT_VEC cppVar_19290;
	BIT_VEC cppVar_19291;
	BIT_VEC cppVar_19292;
	BIT_VEC cppVar_19293;
	BIT_VEC cppVar_19294;
	BIT_VEC cppVar_19277;
	BIT_VEC cppVar_19295;
	bool cppVar_19296;
	BIT_VEC cppVar_19297;
	BIT_VEC cppVar_19298;
	BIT_VEC cppVar_19299;
	BIT_VEC cppVar_19300;
	BIT_VEC cppVar_19301;
	BIT_VEC cppVar_19302;
	BIT_VEC cppVar_19303;
	BIT_VEC cppVar_19306;
	BIT_VEC cppVar_19307;
	BIT_VEC cppVar_19308;
	bool cppVar_19309;
	BIT_VEC cppVar_19310;
	BIT_VEC cppVar_19311;
	BIT_VEC cppVar_19312;
	BIT_VEC cppVar_19313;
	BIT_VEC cppVar_19314;
	BIT_VEC cppVar_19315;
	BIT_VEC cppVar_19316;
	BIT_VEC cppVar_19317;
	BIT_VEC cppVar_19318;
	BIT_VEC cppVar_19305;
	BIT_VEC cppVar_19319;
	BIT_VEC cppVar_19320;
	bool cppVar_19321;
	BIT_VEC cppVar_19323;
	BIT_VEC cppVar_19324;
	BIT_VEC cppVar_19325;
	bool cppVar_19326;
	BIT_VEC cppVar_19327;
	BIT_VEC cppVar_19328;
	BIT_VEC cppVar_19329;
	BIT_VEC cppVar_19330;
	BIT_VEC cppVar_19331;
	BIT_VEC cppVar_19332;
	BIT_VEC cppVar_19333;
	BIT_VEC cppVar_19334;
	BIT_VEC cppVar_19335;
	BIT_VEC cppVar_19322;
	BIT_VEC cppVar_19336;
	BIT_VEC cppVar_19339;
	BIT_VEC cppVar_19340;
	BIT_VEC cppVar_19341;
	bool cppVar_19342;
	BIT_VEC cppVar_19343;
	BIT_VEC cppVar_19344;
	BIT_VEC cppVar_19345;
	BIT_VEC cppVar_19346;
	BIT_VEC cppVar_19347;
	BIT_VEC cppVar_19348;
	BIT_VEC cppVar_19349;
	BIT_VEC cppVar_19350;
	BIT_VEC cppVar_19351;
	BIT_VEC cppVar_19338;
	BIT_VEC cppVar_19352;
	bool cppVar_19353;
	BIT_VEC cppVar_19356;
	BIT_VEC cppVar_19357;
	BIT_VEC cppVar_19358;
	bool cppVar_19359;
	BIT_VEC cppVar_19360;
	BIT_VEC cppVar_19361;
	BIT_VEC cppVar_19362;
	BIT_VEC cppVar_19363;
	BIT_VEC cppVar_19364;
	BIT_VEC cppVar_19365;
	BIT_VEC cppVar_19366;
	BIT_VEC cppVar_19367;
	BIT_VEC cppVar_19368;
	BIT_VEC cppVar_19355;
	BIT_VEC cppVar_19369;
	bool cppVar_19370;
	BIT_VEC cppVar_19373;
	BIT_VEC cppVar_19374;
	BIT_VEC cppVar_19375;
	bool cppVar_19376;
	BIT_VEC cppVar_19377;
	BIT_VEC cppVar_19378;
	BIT_VEC cppVar_19379;
	BIT_VEC cppVar_19380;
	BIT_VEC cppVar_19381;
	BIT_VEC cppVar_19382;
	BIT_VEC cppVar_19383;
	BIT_VEC cppVar_19384;
	BIT_VEC cppVar_19385;
	BIT_VEC cppVar_19372;
	BIT_VEC cppVar_19386;
	bool cppVar_19387;
	BIT_VEC cppVar_19390;
	BIT_VEC cppVar_19391;
	BIT_VEC cppVar_19392;
	bool cppVar_19393;
	BIT_VEC cppVar_19394;
	BIT_VEC cppVar_19395;
	BIT_VEC cppVar_19396;
	BIT_VEC cppVar_19397;
	BIT_VEC cppVar_19398;
	BIT_VEC cppVar_19399;
	BIT_VEC cppVar_19400;
	BIT_VEC cppVar_19401;
	BIT_VEC cppVar_19402;
	BIT_VEC cppVar_19389;
	BIT_VEC cppVar_19403;
	bool cppVar_19404;
	BIT_VEC cppVar_19407;
	BIT_VEC cppVar_19408;
	BIT_VEC cppVar_19409;
	bool cppVar_19410;
	BIT_VEC cppVar_19411;
	BIT_VEC cppVar_19412;
	BIT_VEC cppVar_19413;
	BIT_VEC cppVar_19414;
	BIT_VEC cppVar_19415;
	BIT_VEC cppVar_19416;
	BIT_VEC cppVar_19417;
	BIT_VEC cppVar_19418;
	BIT_VEC cppVar_19419;
	BIT_VEC cppVar_19406;
	BIT_VEC cppVar_19420;
	bool cppVar_19421;
	BIT_VEC cppVar_19424;
	BIT_VEC cppVar_19425;
	BIT_VEC cppVar_19426;
	bool cppVar_19427;
	BIT_VEC cppVar_19428;
	BIT_VEC cppVar_19429;
	BIT_VEC cppVar_19430;
	BIT_VEC cppVar_19431;
	BIT_VEC cppVar_19432;
	BIT_VEC cppVar_19433;
	BIT_VEC cppVar_19434;
	BIT_VEC cppVar_19435;
	BIT_VEC cppVar_19436;
	BIT_VEC cppVar_19423;
	BIT_VEC cppVar_19437;
	bool cppVar_19438;
	BIT_VEC cppVar_19441;
	BIT_VEC cppVar_19442;
	BIT_VEC cppVar_19443;
	bool cppVar_19444;
	BIT_VEC cppVar_19445;
	BIT_VEC cppVar_19446;
	BIT_VEC cppVar_19447;
	BIT_VEC cppVar_19448;
	BIT_VEC cppVar_19449;
	BIT_VEC cppVar_19450;
	BIT_VEC cppVar_19451;
	BIT_VEC cppVar_19452;
	BIT_VEC cppVar_19453;
	BIT_VEC cppVar_19440;
	BIT_VEC cppVar_19454;
	bool cppVar_19455;
	BIT_VEC cppVar_19458;
	BIT_VEC cppVar_19459;
	BIT_VEC cppVar_19460;
	bool cppVar_19461;
	BIT_VEC cppVar_19462;
	BIT_VEC cppVar_19463;
	BIT_VEC cppVar_19464;
	BIT_VEC cppVar_19465;
	BIT_VEC cppVar_19466;
	BIT_VEC cppVar_19467;
	BIT_VEC cppVar_19468;
	BIT_VEC cppVar_19469;
	BIT_VEC cppVar_19470;
	BIT_VEC cppVar_19457;
	BIT_VEC cppVar_19471;
	bool cppVar_19472;
	BIT_VEC cppVar_19475;
	BIT_VEC cppVar_19476;
	BIT_VEC cppVar_19477;
	bool cppVar_19478;
	BIT_VEC cppVar_19479;
	BIT_VEC cppVar_19480;
	BIT_VEC cppVar_19481;
	BIT_VEC cppVar_19482;
	BIT_VEC cppVar_19483;
	BIT_VEC cppVar_19484;
	BIT_VEC cppVar_19485;
	BIT_VEC cppVar_19486;
	BIT_VEC cppVar_19487;
	BIT_VEC cppVar_19474;
	BIT_VEC cppVar_19488;
	bool cppVar_19489;
	BIT_VEC cppVar_19492;
	BIT_VEC cppVar_19493;
	BIT_VEC cppVar_19494;
	bool cppVar_19495;
	BIT_VEC cppVar_19496;
	BIT_VEC cppVar_19497;
	BIT_VEC cppVar_19498;
	BIT_VEC cppVar_19499;
	BIT_VEC cppVar_19500;
	BIT_VEC cppVar_19501;
	BIT_VEC cppVar_19502;
	BIT_VEC cppVar_19503;
	BIT_VEC cppVar_19504;
	BIT_VEC cppVar_19491;
	BIT_VEC cppVar_19505;
	bool cppVar_19506;
	BIT_VEC cppVar_19509;
	BIT_VEC cppVar_19510;
	BIT_VEC cppVar_19511;
	bool cppVar_19512;
	BIT_VEC cppVar_19513;
	BIT_VEC cppVar_19514;
	BIT_VEC cppVar_19515;
	BIT_VEC cppVar_19516;
	BIT_VEC cppVar_19517;
	BIT_VEC cppVar_19518;
	BIT_VEC cppVar_19519;
	BIT_VEC cppVar_19520;
	BIT_VEC cppVar_19521;
	BIT_VEC cppVar_19508;
	BIT_VEC cppVar_19522;
	bool cppVar_19523;
	BIT_VEC cppVar_19526;
	BIT_VEC cppVar_19527;
	BIT_VEC cppVar_19528;
	bool cppVar_19529;
	BIT_VEC cppVar_19530;
	BIT_VEC cppVar_19531;
	BIT_VEC cppVar_19532;
	BIT_VEC cppVar_19533;
	BIT_VEC cppVar_19534;
	BIT_VEC cppVar_19535;
	BIT_VEC cppVar_19536;
	BIT_VEC cppVar_19537;
	BIT_VEC cppVar_19538;
	BIT_VEC cppVar_19525;
	BIT_VEC cppVar_19539;
	bool cppVar_19540;
	BIT_VEC cppVar_19543;
	BIT_VEC cppVar_19544;
	BIT_VEC cppVar_19545;
	bool cppVar_19546;
	BIT_VEC cppVar_19547;
	BIT_VEC cppVar_19548;
	BIT_VEC cppVar_19549;
	BIT_VEC cppVar_19550;
	BIT_VEC cppVar_19551;
	BIT_VEC cppVar_19552;
	BIT_VEC cppVar_19553;
	BIT_VEC cppVar_19554;
	BIT_VEC cppVar_19555;
	BIT_VEC cppVar_19542;
	BIT_VEC cppVar_19556;
	bool cppVar_19557;
	BIT_VEC cppVar_19560;
	BIT_VEC cppVar_19561;
	BIT_VEC cppVar_19562;
	bool cppVar_19563;
	BIT_VEC cppVar_19564;
	BIT_VEC cppVar_19565;
	BIT_VEC cppVar_19566;
	BIT_VEC cppVar_19567;
	BIT_VEC cppVar_19568;
	BIT_VEC cppVar_19569;
	BIT_VEC cppVar_19570;
	BIT_VEC cppVar_19571;
	BIT_VEC cppVar_19572;
	BIT_VEC cppVar_19559;
	BIT_VEC cppVar_19573;
	bool cppVar_19574;
	BIT_VEC cppVar_19577;
	BIT_VEC cppVar_19578;
	BIT_VEC cppVar_19579;
	bool cppVar_19580;
	BIT_VEC cppVar_19581;
	BIT_VEC cppVar_19582;
	BIT_VEC cppVar_19583;
	BIT_VEC cppVar_19584;
	BIT_VEC cppVar_19585;
	BIT_VEC cppVar_19586;
	BIT_VEC cppVar_19587;
	BIT_VEC cppVar_19588;
	BIT_VEC cppVar_19589;
	BIT_VEC cppVar_19576;
	BIT_VEC cppVar_19590;
	bool cppVar_19591;
	BIT_VEC cppVar_19594;
	BIT_VEC cppVar_19595;
	BIT_VEC cppVar_19596;
	bool cppVar_19597;
	BIT_VEC cppVar_19598;
	BIT_VEC cppVar_19599;
	BIT_VEC cppVar_19600;
	BIT_VEC cppVar_19601;
	BIT_VEC cppVar_19602;
	BIT_VEC cppVar_19603;
	BIT_VEC cppVar_19604;
	BIT_VEC cppVar_19605;
	BIT_VEC cppVar_19606;
	BIT_VEC cppVar_19593;
	BIT_VEC cppVar_19607;
	bool cppVar_19608;
	BIT_VEC cppVar_19611;
	BIT_VEC cppVar_19612;
	BIT_VEC cppVar_19613;
	bool cppVar_19614;
	BIT_VEC cppVar_19615;
	BIT_VEC cppVar_19616;
	BIT_VEC cppVar_19617;
	BIT_VEC cppVar_19618;
	BIT_VEC cppVar_19619;
	BIT_VEC cppVar_19620;
	BIT_VEC cppVar_19621;
	BIT_VEC cppVar_19622;
	BIT_VEC cppVar_19623;
	BIT_VEC cppVar_19610;
	BIT_VEC cppVar_19624;
	bool cppVar_19625;
	BIT_VEC cppVar_19628;
	BIT_VEC cppVar_19629;
	BIT_VEC cppVar_19630;
	bool cppVar_19631;
	BIT_VEC cppVar_19632;
	BIT_VEC cppVar_19633;
	BIT_VEC cppVar_19634;
	BIT_VEC cppVar_19635;
	BIT_VEC cppVar_19636;
	BIT_VEC cppVar_19637;
	BIT_VEC cppVar_19638;
	BIT_VEC cppVar_19639;
	BIT_VEC cppVar_19640;
	BIT_VEC cppVar_19627;
	BIT_VEC cppVar_19641;
	bool cppVar_19642;
	BIT_VEC cppVar_19645;
	BIT_VEC cppVar_19646;
	BIT_VEC cppVar_19647;
	bool cppVar_19648;
	BIT_VEC cppVar_19649;
	BIT_VEC cppVar_19650;
	BIT_VEC cppVar_19651;
	BIT_VEC cppVar_19652;
	BIT_VEC cppVar_19653;
	BIT_VEC cppVar_19654;
	BIT_VEC cppVar_19655;
	BIT_VEC cppVar_19656;
	BIT_VEC cppVar_19657;
	BIT_VEC cppVar_19644;
	BIT_VEC cppVar_19658;
	bool cppVar_19659;
	BIT_VEC cppVar_19662;
	BIT_VEC cppVar_19663;
	BIT_VEC cppVar_19664;
	bool cppVar_19665;
	BIT_VEC cppVar_19666;
	BIT_VEC cppVar_19667;
	BIT_VEC cppVar_19668;
	BIT_VEC cppVar_19669;
	BIT_VEC cppVar_19670;
	BIT_VEC cppVar_19671;
	BIT_VEC cppVar_19672;
	BIT_VEC cppVar_19673;
	BIT_VEC cppVar_19674;
	BIT_VEC cppVar_19661;
	BIT_VEC cppVar_19675;
	bool cppVar_19676;
	BIT_VEC cppVar_19679;
	BIT_VEC cppVar_19680;
	BIT_VEC cppVar_19681;
	bool cppVar_19682;
	BIT_VEC cppVar_19683;
	BIT_VEC cppVar_19684;
	BIT_VEC cppVar_19685;
	BIT_VEC cppVar_19686;
	BIT_VEC cppVar_19687;
	BIT_VEC cppVar_19688;
	BIT_VEC cppVar_19689;
	BIT_VEC cppVar_19690;
	BIT_VEC cppVar_19691;
	BIT_VEC cppVar_19678;
	BIT_VEC cppVar_19692;
	bool cppVar_19693;
	BIT_VEC cppVar_19694;
	BIT_VEC cppVar_19677;
	BIT_VEC cppVar_19660;
	BIT_VEC cppVar_19643;
	BIT_VEC cppVar_19626;
	BIT_VEC cppVar_19609;
	BIT_VEC cppVar_19592;
	BIT_VEC cppVar_19575;
	BIT_VEC cppVar_19558;
	BIT_VEC cppVar_19541;
	BIT_VEC cppVar_19524;
	BIT_VEC cppVar_19507;
	BIT_VEC cppVar_19490;
	BIT_VEC cppVar_19473;
	BIT_VEC cppVar_19456;
	BIT_VEC cppVar_19439;
	BIT_VEC cppVar_19422;
	BIT_VEC cppVar_19405;
	BIT_VEC cppVar_19388;
	BIT_VEC cppVar_19371;
	BIT_VEC cppVar_19354;
	BIT_VEC cppVar_19337;
	BIT_VEC cppVar_19304;
	BIT_VEC cppVar_19695;
	BIT_VEC cppVar_19696;
	BIT_VEC cppVar_19697;
	BIT_VEC cppVar_19698;
	BIT_VEC cppVar_19699;
	BIT_VEC cppVar_19700;
	BIT_VEC cppVar_19701;
	BIT_VEC cppVar_19702;
	BIT_VEC cppVar_19703;
	BIT_VEC cppVar_19276;
	BIT_VEC cppVar_19705;
	BIT_VEC cppVar_19706;
	bool cppVar_19707;
	BIT_VEC cppVar_19709;
	BIT_VEC cppVar_19710;
	BIT_VEC cppVar_19711;
	BIT_VEC cppVar_19712;
	bool cppVar_19713;
	BIT_VEC cppVar_19715;
	BIT_VEC cppVar_19716;
	BIT_VEC cppVar_19717;
	BIT_VEC cppVar_19718;
	BIT_VEC cppVar_19719;
	BIT_VEC cppVar_19720;
	BIT_VEC cppVar_19721;
	bool cppVar_19722;
	BIT_VEC cppVar_19723;
	BIT_VEC cppVar_19724;
	BIT_VEC cppVar_19725;
	BIT_VEC cppVar_19726;
	BIT_VEC cppVar_19728;
	BIT_VEC cppVar_19729;
	BIT_VEC cppVar_19730;
	BIT_VEC cppVar_19731;
	bool cppVar_19732;
	BIT_VEC cppVar_19734;
	BIT_VEC cppVar_19735;
	BIT_VEC cppVar_19736;
	BIT_VEC cppVar_19737;
	bool cppVar_19738;
	BIT_VEC cppVar_19740;
	BIT_VEC cppVar_19741;
	BIT_VEC cppVar_19742;
	BIT_VEC cppVar_19743;
	bool cppVar_19744;
	BIT_VEC cppVar_19746;
	BIT_VEC cppVar_19747;
	BIT_VEC cppVar_19748;
	BIT_VEC cppVar_19749;
	bool cppVar_19750;
	BIT_VEC cppVar_19752;
	BIT_VEC cppVar_19753;
	BIT_VEC cppVar_19754;
	BIT_VEC cppVar_19755;
	bool cppVar_19756;
	BIT_VEC cppVar_19758;
	BIT_VEC cppVar_19759;
	BIT_VEC cppVar_19760;
	BIT_VEC cppVar_19761;
	bool cppVar_19762;
	BIT_VEC cppVar_19764;
	BIT_VEC cppVar_19765;
	BIT_VEC cppVar_19766;
	BIT_VEC cppVar_19767;
	bool cppVar_19768;
	BIT_VEC cppVar_19770;
	BIT_VEC cppVar_19771;
	BIT_VEC cppVar_19772;
	BIT_VEC cppVar_19773;
	bool cppVar_19774;
	BIT_VEC cppVar_19776;
	BIT_VEC cppVar_19777;
	BIT_VEC cppVar_19778;
	BIT_VEC cppVar_19779;
	bool cppVar_19780;
	BIT_VEC cppVar_19782;
	BIT_VEC cppVar_19783;
	BIT_VEC cppVar_19784;
	BIT_VEC cppVar_19785;
	bool cppVar_19786;
	BIT_VEC cppVar_19788;
	BIT_VEC cppVar_19789;
	BIT_VEC cppVar_19790;
	BIT_VEC cppVar_19791;
	bool cppVar_19792;
	BIT_VEC cppVar_19794;
	BIT_VEC cppVar_19795;
	BIT_VEC cppVar_19796;
	BIT_VEC cppVar_19797;
	bool cppVar_19798;
	BIT_VEC cppVar_19800;
	BIT_VEC cppVar_19801;
	BIT_VEC cppVar_19802;
	BIT_VEC cppVar_19803;
	bool cppVar_19804;
	BIT_VEC cppVar_19806;
	BIT_VEC cppVar_19807;
	BIT_VEC cppVar_19808;
	BIT_VEC cppVar_19809;
	bool cppVar_19810;
	BIT_VEC cppVar_19812;
	BIT_VEC cppVar_19813;
	BIT_VEC cppVar_19814;
	BIT_VEC cppVar_19815;
	bool cppVar_19816;
	BIT_VEC cppVar_19818;
	BIT_VEC cppVar_19819;
	BIT_VEC cppVar_19820;
	BIT_VEC cppVar_19821;
	bool cppVar_19822;
	BIT_VEC cppVar_19824;
	BIT_VEC cppVar_19825;
	BIT_VEC cppVar_19826;
	BIT_VEC cppVar_19827;
	bool cppVar_19828;
	BIT_VEC cppVar_19830;
	BIT_VEC cppVar_19831;
	BIT_VEC cppVar_19832;
	BIT_VEC cppVar_19833;
	bool cppVar_19834;
	BIT_VEC cppVar_19836;
	BIT_VEC cppVar_19837;
	BIT_VEC cppVar_19838;
	BIT_VEC cppVar_19839;
	bool cppVar_19840;
	BIT_VEC cppVar_19842;
	BIT_VEC cppVar_19843;
	BIT_VEC cppVar_19844;
	BIT_VEC cppVar_19845;
	bool cppVar_19846;
	BIT_VEC cppVar_19848;
	BIT_VEC cppVar_19849;
	BIT_VEC cppVar_19850;
	BIT_VEC cppVar_19851;
	bool cppVar_19852;
	BIT_VEC cppVar_19853;
	BIT_VEC cppVar_19847;
	BIT_VEC cppVar_19841;
	BIT_VEC cppVar_19835;
	BIT_VEC cppVar_19829;
	BIT_VEC cppVar_19823;
	BIT_VEC cppVar_19817;
	BIT_VEC cppVar_19811;
	BIT_VEC cppVar_19805;
	BIT_VEC cppVar_19799;
	BIT_VEC cppVar_19793;
	BIT_VEC cppVar_19787;
	BIT_VEC cppVar_19781;
	BIT_VEC cppVar_19775;
	BIT_VEC cppVar_19769;
	BIT_VEC cppVar_19763;
	BIT_VEC cppVar_19757;
	BIT_VEC cppVar_19751;
	BIT_VEC cppVar_19745;
	BIT_VEC cppVar_19739;
	BIT_VEC cppVar_19733;
	BIT_VEC cppVar_19727;
	BIT_VEC cppVar_19714;
	BIT_VEC cppVar_19708;
	BIT_VEC cppVar_19855;
	BIT_VEC cppVar_19856;
	bool cppVar_19857;
	BIT_VEC cppVar_19859;
	BIT_VEC cppVar_19860;
	BIT_VEC cppVar_19861;
	BIT_VEC cppVar_19862;
	bool cppVar_19863;
	BIT_VEC cppVar_19865;
	BIT_VEC cppVar_19866;
	BIT_VEC cppVar_19867;
	BIT_VEC cppVar_19868;
	BIT_VEC cppVar_19869;
	BIT_VEC cppVar_19870;
	BIT_VEC cppVar_19871;
	bool cppVar_19872;
	BIT_VEC cppVar_19873;
	BIT_VEC cppVar_19874;
	BIT_VEC cppVar_19875;
	BIT_VEC cppVar_19876;
	BIT_VEC cppVar_19878;
	BIT_VEC cppVar_19879;
	BIT_VEC cppVar_19880;
	BIT_VEC cppVar_19881;
	bool cppVar_19882;
	BIT_VEC cppVar_19884;
	BIT_VEC cppVar_19885;
	BIT_VEC cppVar_19886;
	BIT_VEC cppVar_19887;
	bool cppVar_19888;
	BIT_VEC cppVar_19890;
	BIT_VEC cppVar_19891;
	BIT_VEC cppVar_19892;
	BIT_VEC cppVar_19893;
	bool cppVar_19894;
	BIT_VEC cppVar_19896;
	BIT_VEC cppVar_19897;
	BIT_VEC cppVar_19898;
	BIT_VEC cppVar_19899;
	bool cppVar_19900;
	BIT_VEC cppVar_19902;
	BIT_VEC cppVar_19903;
	BIT_VEC cppVar_19904;
	BIT_VEC cppVar_19905;
	bool cppVar_19906;
	BIT_VEC cppVar_19908;
	BIT_VEC cppVar_19909;
	BIT_VEC cppVar_19910;
	BIT_VEC cppVar_19911;
	bool cppVar_19912;
	BIT_VEC cppVar_19914;
	BIT_VEC cppVar_19915;
	BIT_VEC cppVar_19916;
	BIT_VEC cppVar_19917;
	bool cppVar_19918;
	BIT_VEC cppVar_19920;
	BIT_VEC cppVar_19921;
	BIT_VEC cppVar_19922;
	BIT_VEC cppVar_19923;
	bool cppVar_19924;
	BIT_VEC cppVar_19926;
	BIT_VEC cppVar_19927;
	BIT_VEC cppVar_19928;
	BIT_VEC cppVar_19929;
	bool cppVar_19930;
	BIT_VEC cppVar_19932;
	BIT_VEC cppVar_19933;
	BIT_VEC cppVar_19934;
	BIT_VEC cppVar_19935;
	bool cppVar_19936;
	BIT_VEC cppVar_19938;
	BIT_VEC cppVar_19939;
	BIT_VEC cppVar_19940;
	BIT_VEC cppVar_19941;
	bool cppVar_19942;
	BIT_VEC cppVar_19944;
	BIT_VEC cppVar_19945;
	BIT_VEC cppVar_19946;
	BIT_VEC cppVar_19947;
	bool cppVar_19948;
	BIT_VEC cppVar_19950;
	BIT_VEC cppVar_19951;
	BIT_VEC cppVar_19952;
	BIT_VEC cppVar_19953;
	bool cppVar_19954;
	BIT_VEC cppVar_19956;
	BIT_VEC cppVar_19957;
	BIT_VEC cppVar_19958;
	BIT_VEC cppVar_19959;
	bool cppVar_19960;
	BIT_VEC cppVar_19962;
	BIT_VEC cppVar_19963;
	BIT_VEC cppVar_19964;
	BIT_VEC cppVar_19965;
	bool cppVar_19966;
	BIT_VEC cppVar_19968;
	BIT_VEC cppVar_19969;
	BIT_VEC cppVar_19970;
	BIT_VEC cppVar_19971;
	bool cppVar_19972;
	BIT_VEC cppVar_19974;
	BIT_VEC cppVar_19975;
	BIT_VEC cppVar_19976;
	BIT_VEC cppVar_19977;
	bool cppVar_19978;
	BIT_VEC cppVar_19980;
	BIT_VEC cppVar_19981;
	BIT_VEC cppVar_19982;
	BIT_VEC cppVar_19983;
	bool cppVar_19984;
	BIT_VEC cppVar_19986;
	BIT_VEC cppVar_19987;
	BIT_VEC cppVar_19988;
	BIT_VEC cppVar_19989;
	bool cppVar_19990;
	BIT_VEC cppVar_19992;
	BIT_VEC cppVar_19993;
	BIT_VEC cppVar_19994;
	BIT_VEC cppVar_19995;
	bool cppVar_19996;
	BIT_VEC cppVar_19998;
	BIT_VEC cppVar_19999;
	BIT_VEC cppVar_20000;
	BIT_VEC cppVar_20001;
	bool cppVar_20002;
	BIT_VEC cppVar_20003;
	BIT_VEC cppVar_19997;
	BIT_VEC cppVar_19991;
	BIT_VEC cppVar_19985;
	BIT_VEC cppVar_19979;
	BIT_VEC cppVar_19973;
	BIT_VEC cppVar_19967;
	BIT_VEC cppVar_19961;
	BIT_VEC cppVar_19955;
	BIT_VEC cppVar_19949;
	BIT_VEC cppVar_19943;
	BIT_VEC cppVar_19937;
	BIT_VEC cppVar_19931;
	BIT_VEC cppVar_19925;
	BIT_VEC cppVar_19919;
	BIT_VEC cppVar_19913;
	BIT_VEC cppVar_19907;
	BIT_VEC cppVar_19901;
	BIT_VEC cppVar_19895;
	BIT_VEC cppVar_19889;
	BIT_VEC cppVar_19883;
	BIT_VEC cppVar_19877;
	BIT_VEC cppVar_19864;
	BIT_VEC cppVar_19858;
	BIT_VEC cppVar_20005;
	BIT_VEC cppVar_20006;
	bool cppVar_20007;
	BIT_VEC cppVar_20009;
	BIT_VEC cppVar_20010;
	BIT_VEC cppVar_20011;
	BIT_VEC cppVar_20012;
	bool cppVar_20013;
	BIT_VEC cppVar_20015;
	BIT_VEC cppVar_20016;
	BIT_VEC cppVar_20017;
	BIT_VEC cppVar_20018;
	BIT_VEC cppVar_20019;
	BIT_VEC cppVar_20020;
	BIT_VEC cppVar_20021;
	bool cppVar_20022;
	BIT_VEC cppVar_20023;
	BIT_VEC cppVar_20024;
	BIT_VEC cppVar_20025;
	BIT_VEC cppVar_20026;
	BIT_VEC cppVar_20028;
	BIT_VEC cppVar_20029;
	BIT_VEC cppVar_20030;
	BIT_VEC cppVar_20031;
	bool cppVar_20032;
	BIT_VEC cppVar_20034;
	BIT_VEC cppVar_20035;
	BIT_VEC cppVar_20036;
	BIT_VEC cppVar_20037;
	bool cppVar_20038;
	BIT_VEC cppVar_20040;
	BIT_VEC cppVar_20041;
	BIT_VEC cppVar_20042;
	BIT_VEC cppVar_20043;
	bool cppVar_20044;
	BIT_VEC cppVar_20046;
	BIT_VEC cppVar_20047;
	BIT_VEC cppVar_20048;
	BIT_VEC cppVar_20049;
	bool cppVar_20050;
	BIT_VEC cppVar_20052;
	BIT_VEC cppVar_20053;
	BIT_VEC cppVar_20054;
	BIT_VEC cppVar_20055;
	bool cppVar_20056;
	BIT_VEC cppVar_20058;
	BIT_VEC cppVar_20059;
	BIT_VEC cppVar_20060;
	BIT_VEC cppVar_20061;
	bool cppVar_20062;
	BIT_VEC cppVar_20064;
	BIT_VEC cppVar_20065;
	BIT_VEC cppVar_20066;
	BIT_VEC cppVar_20067;
	bool cppVar_20068;
	BIT_VEC cppVar_20070;
	BIT_VEC cppVar_20071;
	BIT_VEC cppVar_20072;
	BIT_VEC cppVar_20073;
	bool cppVar_20074;
	BIT_VEC cppVar_20076;
	BIT_VEC cppVar_20077;
	BIT_VEC cppVar_20078;
	BIT_VEC cppVar_20079;
	bool cppVar_20080;
	BIT_VEC cppVar_20082;
	BIT_VEC cppVar_20083;
	BIT_VEC cppVar_20084;
	BIT_VEC cppVar_20085;
	bool cppVar_20086;
	BIT_VEC cppVar_20088;
	BIT_VEC cppVar_20089;
	BIT_VEC cppVar_20090;
	BIT_VEC cppVar_20091;
	bool cppVar_20092;
	BIT_VEC cppVar_20094;
	BIT_VEC cppVar_20095;
	BIT_VEC cppVar_20096;
	BIT_VEC cppVar_20097;
	bool cppVar_20098;
	BIT_VEC cppVar_20100;
	BIT_VEC cppVar_20101;
	BIT_VEC cppVar_20102;
	BIT_VEC cppVar_20103;
	bool cppVar_20104;
	BIT_VEC cppVar_20106;
	BIT_VEC cppVar_20107;
	BIT_VEC cppVar_20108;
	BIT_VEC cppVar_20109;
	bool cppVar_20110;
	BIT_VEC cppVar_20112;
	BIT_VEC cppVar_20113;
	BIT_VEC cppVar_20114;
	BIT_VEC cppVar_20115;
	bool cppVar_20116;
	BIT_VEC cppVar_20118;
	BIT_VEC cppVar_20119;
	BIT_VEC cppVar_20120;
	BIT_VEC cppVar_20121;
	bool cppVar_20122;
	BIT_VEC cppVar_20124;
	BIT_VEC cppVar_20125;
	BIT_VEC cppVar_20126;
	BIT_VEC cppVar_20127;
	bool cppVar_20128;
	BIT_VEC cppVar_20130;
	BIT_VEC cppVar_20131;
	BIT_VEC cppVar_20132;
	BIT_VEC cppVar_20133;
	bool cppVar_20134;
	BIT_VEC cppVar_20136;
	BIT_VEC cppVar_20137;
	BIT_VEC cppVar_20138;
	BIT_VEC cppVar_20139;
	bool cppVar_20140;
	BIT_VEC cppVar_20142;
	BIT_VEC cppVar_20143;
	BIT_VEC cppVar_20144;
	BIT_VEC cppVar_20145;
	bool cppVar_20146;
	BIT_VEC cppVar_20148;
	BIT_VEC cppVar_20149;
	BIT_VEC cppVar_20150;
	BIT_VEC cppVar_20151;
	bool cppVar_20152;
	BIT_VEC cppVar_20153;
	BIT_VEC cppVar_20147;
	BIT_VEC cppVar_20141;
	BIT_VEC cppVar_20135;
	BIT_VEC cppVar_20129;
	BIT_VEC cppVar_20123;
	BIT_VEC cppVar_20117;
	BIT_VEC cppVar_20111;
	BIT_VEC cppVar_20105;
	BIT_VEC cppVar_20099;
	BIT_VEC cppVar_20093;
	BIT_VEC cppVar_20087;
	BIT_VEC cppVar_20081;
	BIT_VEC cppVar_20075;
	BIT_VEC cppVar_20069;
	BIT_VEC cppVar_20063;
	BIT_VEC cppVar_20057;
	BIT_VEC cppVar_20051;
	BIT_VEC cppVar_20045;
	BIT_VEC cppVar_20039;
	BIT_VEC cppVar_20033;
	BIT_VEC cppVar_20027;
	BIT_VEC cppVar_20014;
	BIT_VEC cppVar_20008;
	BIT_VEC cppVar_20155;
	BIT_VEC cppVar_20156;
	bool cppVar_20157;
	BIT_VEC cppVar_20159;
	BIT_VEC cppVar_20160;
	BIT_VEC cppVar_20161;
	BIT_VEC cppVar_20162;
	bool cppVar_20163;
	BIT_VEC cppVar_20165;
	BIT_VEC cppVar_20166;
	BIT_VEC cppVar_20167;
	BIT_VEC cppVar_20168;
	BIT_VEC cppVar_20169;
	BIT_VEC cppVar_20170;
	BIT_VEC cppVar_20171;
	bool cppVar_20172;
	BIT_VEC cppVar_20173;
	BIT_VEC cppVar_20174;
	BIT_VEC cppVar_20175;
	BIT_VEC cppVar_20176;
	BIT_VEC cppVar_20178;
	BIT_VEC cppVar_20179;
	BIT_VEC cppVar_20180;
	BIT_VEC cppVar_20181;
	bool cppVar_20182;
	BIT_VEC cppVar_20184;
	BIT_VEC cppVar_20185;
	BIT_VEC cppVar_20186;
	BIT_VEC cppVar_20187;
	bool cppVar_20188;
	BIT_VEC cppVar_20190;
	BIT_VEC cppVar_20191;
	BIT_VEC cppVar_20192;
	BIT_VEC cppVar_20193;
	bool cppVar_20194;
	BIT_VEC cppVar_20196;
	BIT_VEC cppVar_20197;
	BIT_VEC cppVar_20198;
	BIT_VEC cppVar_20199;
	bool cppVar_20200;
	BIT_VEC cppVar_20202;
	BIT_VEC cppVar_20203;
	BIT_VEC cppVar_20204;
	BIT_VEC cppVar_20205;
	bool cppVar_20206;
	BIT_VEC cppVar_20208;
	BIT_VEC cppVar_20209;
	BIT_VEC cppVar_20210;
	BIT_VEC cppVar_20211;
	bool cppVar_20212;
	BIT_VEC cppVar_20214;
	BIT_VEC cppVar_20215;
	BIT_VEC cppVar_20216;
	BIT_VEC cppVar_20217;
	bool cppVar_20218;
	BIT_VEC cppVar_20220;
	BIT_VEC cppVar_20221;
	BIT_VEC cppVar_20222;
	BIT_VEC cppVar_20223;
	bool cppVar_20224;
	BIT_VEC cppVar_20226;
	BIT_VEC cppVar_20227;
	BIT_VEC cppVar_20228;
	BIT_VEC cppVar_20229;
	bool cppVar_20230;
	BIT_VEC cppVar_20232;
	BIT_VEC cppVar_20233;
	BIT_VEC cppVar_20234;
	BIT_VEC cppVar_20235;
	bool cppVar_20236;
	BIT_VEC cppVar_20238;
	BIT_VEC cppVar_20239;
	BIT_VEC cppVar_20240;
	BIT_VEC cppVar_20241;
	bool cppVar_20242;
	BIT_VEC cppVar_20244;
	BIT_VEC cppVar_20245;
	BIT_VEC cppVar_20246;
	BIT_VEC cppVar_20247;
	bool cppVar_20248;
	BIT_VEC cppVar_20250;
	BIT_VEC cppVar_20251;
	BIT_VEC cppVar_20252;
	BIT_VEC cppVar_20253;
	bool cppVar_20254;
	BIT_VEC cppVar_20256;
	BIT_VEC cppVar_20257;
	BIT_VEC cppVar_20258;
	BIT_VEC cppVar_20259;
	bool cppVar_20260;
	BIT_VEC cppVar_20262;
	BIT_VEC cppVar_20263;
	BIT_VEC cppVar_20264;
	BIT_VEC cppVar_20265;
	bool cppVar_20266;
	BIT_VEC cppVar_20268;
	BIT_VEC cppVar_20269;
	BIT_VEC cppVar_20270;
	BIT_VEC cppVar_20271;
	bool cppVar_20272;
	BIT_VEC cppVar_20274;
	BIT_VEC cppVar_20275;
	BIT_VEC cppVar_20276;
	BIT_VEC cppVar_20277;
	bool cppVar_20278;
	BIT_VEC cppVar_20280;
	BIT_VEC cppVar_20281;
	BIT_VEC cppVar_20282;
	BIT_VEC cppVar_20283;
	bool cppVar_20284;
	BIT_VEC cppVar_20286;
	BIT_VEC cppVar_20287;
	BIT_VEC cppVar_20288;
	BIT_VEC cppVar_20289;
	bool cppVar_20290;
	BIT_VEC cppVar_20292;
	BIT_VEC cppVar_20293;
	BIT_VEC cppVar_20294;
	BIT_VEC cppVar_20295;
	bool cppVar_20296;
	BIT_VEC cppVar_20298;
	BIT_VEC cppVar_20299;
	BIT_VEC cppVar_20300;
	BIT_VEC cppVar_20301;
	bool cppVar_20302;
	BIT_VEC cppVar_20303;
	BIT_VEC cppVar_20297;
	BIT_VEC cppVar_20291;
	BIT_VEC cppVar_20285;
	BIT_VEC cppVar_20279;
	BIT_VEC cppVar_20273;
	BIT_VEC cppVar_20267;
	BIT_VEC cppVar_20261;
	BIT_VEC cppVar_20255;
	BIT_VEC cppVar_20249;
	BIT_VEC cppVar_20243;
	BIT_VEC cppVar_20237;
	BIT_VEC cppVar_20231;
	BIT_VEC cppVar_20225;
	BIT_VEC cppVar_20219;
	BIT_VEC cppVar_20213;
	BIT_VEC cppVar_20207;
	BIT_VEC cppVar_20201;
	BIT_VEC cppVar_20195;
	BIT_VEC cppVar_20189;
	BIT_VEC cppVar_20183;
	BIT_VEC cppVar_20177;
	BIT_VEC cppVar_20164;
	BIT_VEC cppVar_20158;
	BIT_VEC cppVar_20305;
	BIT_VEC cppVar_20306;
	bool cppVar_20307;
	BIT_VEC cppVar_20309;
	BIT_VEC cppVar_20310;
	BIT_VEC cppVar_20311;
	BIT_VEC cppVar_20312;
	bool cppVar_20313;
	BIT_VEC cppVar_20315;
	BIT_VEC cppVar_20316;
	BIT_VEC cppVar_20317;
	BIT_VEC cppVar_20318;
	BIT_VEC cppVar_20319;
	BIT_VEC cppVar_20320;
	BIT_VEC cppVar_20321;
	bool cppVar_20322;
	BIT_VEC cppVar_20323;
	BIT_VEC cppVar_20324;
	BIT_VEC cppVar_20325;
	BIT_VEC cppVar_20326;
	BIT_VEC cppVar_20328;
	BIT_VEC cppVar_20329;
	BIT_VEC cppVar_20330;
	BIT_VEC cppVar_20331;
	bool cppVar_20332;
	BIT_VEC cppVar_20334;
	BIT_VEC cppVar_20335;
	BIT_VEC cppVar_20336;
	BIT_VEC cppVar_20337;
	bool cppVar_20338;
	BIT_VEC cppVar_20340;
	BIT_VEC cppVar_20341;
	BIT_VEC cppVar_20342;
	BIT_VEC cppVar_20343;
	bool cppVar_20344;
	BIT_VEC cppVar_20346;
	BIT_VEC cppVar_20347;
	BIT_VEC cppVar_20348;
	BIT_VEC cppVar_20349;
	bool cppVar_20350;
	BIT_VEC cppVar_20352;
	BIT_VEC cppVar_20353;
	BIT_VEC cppVar_20354;
	BIT_VEC cppVar_20355;
	bool cppVar_20356;
	BIT_VEC cppVar_20358;
	BIT_VEC cppVar_20359;
	BIT_VEC cppVar_20360;
	BIT_VEC cppVar_20361;
	bool cppVar_20362;
	BIT_VEC cppVar_20364;
	BIT_VEC cppVar_20365;
	BIT_VEC cppVar_20366;
	BIT_VEC cppVar_20367;
	bool cppVar_20368;
	BIT_VEC cppVar_20370;
	BIT_VEC cppVar_20371;
	BIT_VEC cppVar_20372;
	BIT_VEC cppVar_20373;
	bool cppVar_20374;
	BIT_VEC cppVar_20376;
	BIT_VEC cppVar_20377;
	BIT_VEC cppVar_20378;
	BIT_VEC cppVar_20379;
	bool cppVar_20380;
	BIT_VEC cppVar_20382;
	BIT_VEC cppVar_20383;
	BIT_VEC cppVar_20384;
	BIT_VEC cppVar_20385;
	bool cppVar_20386;
	BIT_VEC cppVar_20388;
	BIT_VEC cppVar_20389;
	BIT_VEC cppVar_20390;
	BIT_VEC cppVar_20391;
	bool cppVar_20392;
	BIT_VEC cppVar_20394;
	BIT_VEC cppVar_20395;
	BIT_VEC cppVar_20396;
	BIT_VEC cppVar_20397;
	bool cppVar_20398;
	BIT_VEC cppVar_20400;
	BIT_VEC cppVar_20401;
	BIT_VEC cppVar_20402;
	BIT_VEC cppVar_20403;
	bool cppVar_20404;
	BIT_VEC cppVar_20406;
	BIT_VEC cppVar_20407;
	BIT_VEC cppVar_20408;
	BIT_VEC cppVar_20409;
	bool cppVar_20410;
	BIT_VEC cppVar_20412;
	BIT_VEC cppVar_20413;
	BIT_VEC cppVar_20414;
	BIT_VEC cppVar_20415;
	bool cppVar_20416;
	BIT_VEC cppVar_20418;
	BIT_VEC cppVar_20419;
	BIT_VEC cppVar_20420;
	BIT_VEC cppVar_20421;
	bool cppVar_20422;
	BIT_VEC cppVar_20424;
	BIT_VEC cppVar_20425;
	BIT_VEC cppVar_20426;
	BIT_VEC cppVar_20427;
	bool cppVar_20428;
	BIT_VEC cppVar_20430;
	BIT_VEC cppVar_20431;
	BIT_VEC cppVar_20432;
	BIT_VEC cppVar_20433;
	bool cppVar_20434;
	BIT_VEC cppVar_20436;
	BIT_VEC cppVar_20437;
	BIT_VEC cppVar_20438;
	BIT_VEC cppVar_20439;
	bool cppVar_20440;
	BIT_VEC cppVar_20442;
	BIT_VEC cppVar_20443;
	BIT_VEC cppVar_20444;
	BIT_VEC cppVar_20445;
	bool cppVar_20446;
	BIT_VEC cppVar_20448;
	BIT_VEC cppVar_20449;
	BIT_VEC cppVar_20450;
	BIT_VEC cppVar_20451;
	bool cppVar_20452;
	BIT_VEC cppVar_20453;
	BIT_VEC cppVar_20447;
	BIT_VEC cppVar_20441;
	BIT_VEC cppVar_20435;
	BIT_VEC cppVar_20429;
	BIT_VEC cppVar_20423;
	BIT_VEC cppVar_20417;
	BIT_VEC cppVar_20411;
	BIT_VEC cppVar_20405;
	BIT_VEC cppVar_20399;
	BIT_VEC cppVar_20393;
	BIT_VEC cppVar_20387;
	BIT_VEC cppVar_20381;
	BIT_VEC cppVar_20375;
	BIT_VEC cppVar_20369;
	BIT_VEC cppVar_20363;
	BIT_VEC cppVar_20357;
	BIT_VEC cppVar_20351;
	BIT_VEC cppVar_20345;
	BIT_VEC cppVar_20339;
	BIT_VEC cppVar_20333;
	BIT_VEC cppVar_20327;
	BIT_VEC cppVar_20314;
	BIT_VEC cppVar_20308;
	BIT_VEC cppVar_20455;
	BIT_VEC cppVar_20456;
	bool cppVar_20457;
	BIT_VEC cppVar_20459;
	BIT_VEC cppVar_20460;
	BIT_VEC cppVar_20461;
	BIT_VEC cppVar_20462;
	bool cppVar_20463;
	BIT_VEC cppVar_20465;
	BIT_VEC cppVar_20466;
	BIT_VEC cppVar_20467;
	BIT_VEC cppVar_20468;
	BIT_VEC cppVar_20469;
	BIT_VEC cppVar_20470;
	BIT_VEC cppVar_20471;
	bool cppVar_20472;
	BIT_VEC cppVar_20473;
	BIT_VEC cppVar_20474;
	BIT_VEC cppVar_20475;
	BIT_VEC cppVar_20476;
	BIT_VEC cppVar_20478;
	BIT_VEC cppVar_20479;
	BIT_VEC cppVar_20480;
	BIT_VEC cppVar_20481;
	bool cppVar_20482;
	BIT_VEC cppVar_20484;
	BIT_VEC cppVar_20485;
	BIT_VEC cppVar_20486;
	BIT_VEC cppVar_20487;
	bool cppVar_20488;
	BIT_VEC cppVar_20490;
	BIT_VEC cppVar_20491;
	BIT_VEC cppVar_20492;
	BIT_VEC cppVar_20493;
	bool cppVar_20494;
	BIT_VEC cppVar_20496;
	BIT_VEC cppVar_20497;
	BIT_VEC cppVar_20498;
	BIT_VEC cppVar_20499;
	bool cppVar_20500;
	BIT_VEC cppVar_20502;
	BIT_VEC cppVar_20503;
	BIT_VEC cppVar_20504;
	BIT_VEC cppVar_20505;
	bool cppVar_20506;
	BIT_VEC cppVar_20508;
	BIT_VEC cppVar_20509;
	BIT_VEC cppVar_20510;
	BIT_VEC cppVar_20511;
	bool cppVar_20512;
	BIT_VEC cppVar_20514;
	BIT_VEC cppVar_20515;
	BIT_VEC cppVar_20516;
	BIT_VEC cppVar_20517;
	bool cppVar_20518;
	BIT_VEC cppVar_20520;
	BIT_VEC cppVar_20521;
	BIT_VEC cppVar_20522;
	BIT_VEC cppVar_20523;
	bool cppVar_20524;
	BIT_VEC cppVar_20526;
	BIT_VEC cppVar_20527;
	BIT_VEC cppVar_20528;
	BIT_VEC cppVar_20529;
	bool cppVar_20530;
	BIT_VEC cppVar_20532;
	BIT_VEC cppVar_20533;
	BIT_VEC cppVar_20534;
	BIT_VEC cppVar_20535;
	bool cppVar_20536;
	BIT_VEC cppVar_20538;
	BIT_VEC cppVar_20539;
	BIT_VEC cppVar_20540;
	BIT_VEC cppVar_20541;
	bool cppVar_20542;
	BIT_VEC cppVar_20544;
	BIT_VEC cppVar_20545;
	BIT_VEC cppVar_20546;
	BIT_VEC cppVar_20547;
	bool cppVar_20548;
	BIT_VEC cppVar_20550;
	BIT_VEC cppVar_20551;
	BIT_VEC cppVar_20552;
	BIT_VEC cppVar_20553;
	bool cppVar_20554;
	BIT_VEC cppVar_20556;
	BIT_VEC cppVar_20557;
	BIT_VEC cppVar_20558;
	BIT_VEC cppVar_20559;
	bool cppVar_20560;
	BIT_VEC cppVar_20562;
	BIT_VEC cppVar_20563;
	BIT_VEC cppVar_20564;
	BIT_VEC cppVar_20565;
	bool cppVar_20566;
	BIT_VEC cppVar_20568;
	BIT_VEC cppVar_20569;
	BIT_VEC cppVar_20570;
	BIT_VEC cppVar_20571;
	bool cppVar_20572;
	BIT_VEC cppVar_20574;
	BIT_VEC cppVar_20575;
	BIT_VEC cppVar_20576;
	BIT_VEC cppVar_20577;
	bool cppVar_20578;
	BIT_VEC cppVar_20580;
	BIT_VEC cppVar_20581;
	BIT_VEC cppVar_20582;
	BIT_VEC cppVar_20583;
	bool cppVar_20584;
	BIT_VEC cppVar_20586;
	BIT_VEC cppVar_20587;
	BIT_VEC cppVar_20588;
	BIT_VEC cppVar_20589;
	bool cppVar_20590;
	BIT_VEC cppVar_20592;
	BIT_VEC cppVar_20593;
	BIT_VEC cppVar_20594;
	BIT_VEC cppVar_20595;
	bool cppVar_20596;
	BIT_VEC cppVar_20598;
	BIT_VEC cppVar_20599;
	BIT_VEC cppVar_20600;
	BIT_VEC cppVar_20601;
	bool cppVar_20602;
	BIT_VEC cppVar_20603;
	BIT_VEC cppVar_20597;
	BIT_VEC cppVar_20591;
	BIT_VEC cppVar_20585;
	BIT_VEC cppVar_20579;
	BIT_VEC cppVar_20573;
	BIT_VEC cppVar_20567;
	BIT_VEC cppVar_20561;
	BIT_VEC cppVar_20555;
	BIT_VEC cppVar_20549;
	BIT_VEC cppVar_20543;
	BIT_VEC cppVar_20537;
	BIT_VEC cppVar_20531;
	BIT_VEC cppVar_20525;
	BIT_VEC cppVar_20519;
	BIT_VEC cppVar_20513;
	BIT_VEC cppVar_20507;
	BIT_VEC cppVar_20501;
	BIT_VEC cppVar_20495;
	BIT_VEC cppVar_20489;
	BIT_VEC cppVar_20483;
	BIT_VEC cppVar_20477;
	BIT_VEC cppVar_20464;
	BIT_VEC cppVar_20458;
	BIT_VEC cppVar_20605;
	BIT_VEC cppVar_20606;
	bool cppVar_20607;
	BIT_VEC cppVar_20609;
	BIT_VEC cppVar_20610;
	BIT_VEC cppVar_20611;
	BIT_VEC cppVar_20612;
	bool cppVar_20613;
	BIT_VEC cppVar_20615;
	BIT_VEC cppVar_20616;
	BIT_VEC cppVar_20617;
	BIT_VEC cppVar_20618;
	BIT_VEC cppVar_20619;
	BIT_VEC cppVar_20620;
	BIT_VEC cppVar_20621;
	bool cppVar_20622;
	BIT_VEC cppVar_20623;
	BIT_VEC cppVar_20624;
	BIT_VEC cppVar_20625;
	BIT_VEC cppVar_20626;
	BIT_VEC cppVar_20628;
	BIT_VEC cppVar_20629;
	BIT_VEC cppVar_20630;
	BIT_VEC cppVar_20631;
	bool cppVar_20632;
	BIT_VEC cppVar_20634;
	BIT_VEC cppVar_20635;
	BIT_VEC cppVar_20636;
	BIT_VEC cppVar_20637;
	bool cppVar_20638;
	BIT_VEC cppVar_20640;
	BIT_VEC cppVar_20641;
	BIT_VEC cppVar_20642;
	BIT_VEC cppVar_20643;
	bool cppVar_20644;
	BIT_VEC cppVar_20646;
	BIT_VEC cppVar_20647;
	BIT_VEC cppVar_20648;
	BIT_VEC cppVar_20649;
	bool cppVar_20650;
	BIT_VEC cppVar_20652;
	BIT_VEC cppVar_20653;
	BIT_VEC cppVar_20654;
	BIT_VEC cppVar_20655;
	bool cppVar_20656;
	BIT_VEC cppVar_20658;
	BIT_VEC cppVar_20659;
	BIT_VEC cppVar_20660;
	BIT_VEC cppVar_20661;
	bool cppVar_20662;
	BIT_VEC cppVar_20664;
	BIT_VEC cppVar_20665;
	BIT_VEC cppVar_20666;
	BIT_VEC cppVar_20667;
	bool cppVar_20668;
	BIT_VEC cppVar_20670;
	BIT_VEC cppVar_20671;
	BIT_VEC cppVar_20672;
	BIT_VEC cppVar_20673;
	bool cppVar_20674;
	BIT_VEC cppVar_20676;
	BIT_VEC cppVar_20677;
	BIT_VEC cppVar_20678;
	BIT_VEC cppVar_20679;
	bool cppVar_20680;
	BIT_VEC cppVar_20682;
	BIT_VEC cppVar_20683;
	BIT_VEC cppVar_20684;
	BIT_VEC cppVar_20685;
	bool cppVar_20686;
	BIT_VEC cppVar_20688;
	BIT_VEC cppVar_20689;
	BIT_VEC cppVar_20690;
	BIT_VEC cppVar_20691;
	bool cppVar_20692;
	BIT_VEC cppVar_20694;
	BIT_VEC cppVar_20695;
	BIT_VEC cppVar_20696;
	BIT_VEC cppVar_20697;
	bool cppVar_20698;
	BIT_VEC cppVar_20700;
	BIT_VEC cppVar_20701;
	BIT_VEC cppVar_20702;
	BIT_VEC cppVar_20703;
	bool cppVar_20704;
	BIT_VEC cppVar_20706;
	BIT_VEC cppVar_20707;
	BIT_VEC cppVar_20708;
	BIT_VEC cppVar_20709;
	bool cppVar_20710;
	BIT_VEC cppVar_20712;
	BIT_VEC cppVar_20713;
	BIT_VEC cppVar_20714;
	BIT_VEC cppVar_20715;
	bool cppVar_20716;
	BIT_VEC cppVar_20718;
	BIT_VEC cppVar_20719;
	BIT_VEC cppVar_20720;
	BIT_VEC cppVar_20721;
	bool cppVar_20722;
	BIT_VEC cppVar_20724;
	BIT_VEC cppVar_20725;
	BIT_VEC cppVar_20726;
	BIT_VEC cppVar_20727;
	bool cppVar_20728;
	BIT_VEC cppVar_20730;
	BIT_VEC cppVar_20731;
	BIT_VEC cppVar_20732;
	BIT_VEC cppVar_20733;
	bool cppVar_20734;
	BIT_VEC cppVar_20736;
	BIT_VEC cppVar_20737;
	BIT_VEC cppVar_20738;
	BIT_VEC cppVar_20739;
	bool cppVar_20740;
	BIT_VEC cppVar_20742;
	BIT_VEC cppVar_20743;
	BIT_VEC cppVar_20744;
	BIT_VEC cppVar_20745;
	bool cppVar_20746;
	BIT_VEC cppVar_20748;
	BIT_VEC cppVar_20749;
	BIT_VEC cppVar_20750;
	BIT_VEC cppVar_20751;
	bool cppVar_20752;
	BIT_VEC cppVar_20753;
	BIT_VEC cppVar_20747;
	BIT_VEC cppVar_20741;
	BIT_VEC cppVar_20735;
	BIT_VEC cppVar_20729;
	BIT_VEC cppVar_20723;
	BIT_VEC cppVar_20717;
	BIT_VEC cppVar_20711;
	BIT_VEC cppVar_20705;
	BIT_VEC cppVar_20699;
	BIT_VEC cppVar_20693;
	BIT_VEC cppVar_20687;
	BIT_VEC cppVar_20681;
	BIT_VEC cppVar_20675;
	BIT_VEC cppVar_20669;
	BIT_VEC cppVar_20663;
	BIT_VEC cppVar_20657;
	BIT_VEC cppVar_20651;
	BIT_VEC cppVar_20645;
	BIT_VEC cppVar_20639;
	BIT_VEC cppVar_20633;
	BIT_VEC cppVar_20627;
	BIT_VEC cppVar_20614;
	BIT_VEC cppVar_20608;
	BIT_VEC cppVar_20755;
	BIT_VEC cppVar_20756;
	bool cppVar_20757;
	BIT_VEC cppVar_20759;
	BIT_VEC cppVar_20760;
	BIT_VEC cppVar_20761;
	BIT_VEC cppVar_20762;
	bool cppVar_20763;
	BIT_VEC cppVar_20765;
	BIT_VEC cppVar_20766;
	BIT_VEC cppVar_20767;
	BIT_VEC cppVar_20768;
	BIT_VEC cppVar_20769;
	BIT_VEC cppVar_20770;
	BIT_VEC cppVar_20771;
	bool cppVar_20772;
	BIT_VEC cppVar_20773;
	BIT_VEC cppVar_20774;
	BIT_VEC cppVar_20775;
	BIT_VEC cppVar_20776;
	BIT_VEC cppVar_20778;
	BIT_VEC cppVar_20779;
	BIT_VEC cppVar_20780;
	BIT_VEC cppVar_20781;
	bool cppVar_20782;
	BIT_VEC cppVar_20784;
	BIT_VEC cppVar_20785;
	BIT_VEC cppVar_20786;
	BIT_VEC cppVar_20787;
	bool cppVar_20788;
	BIT_VEC cppVar_20790;
	BIT_VEC cppVar_20791;
	BIT_VEC cppVar_20792;
	BIT_VEC cppVar_20793;
	bool cppVar_20794;
	BIT_VEC cppVar_20796;
	BIT_VEC cppVar_20797;
	BIT_VEC cppVar_20798;
	BIT_VEC cppVar_20799;
	bool cppVar_20800;
	BIT_VEC cppVar_20802;
	BIT_VEC cppVar_20803;
	BIT_VEC cppVar_20804;
	BIT_VEC cppVar_20805;
	bool cppVar_20806;
	BIT_VEC cppVar_20808;
	BIT_VEC cppVar_20809;
	BIT_VEC cppVar_20810;
	BIT_VEC cppVar_20811;
	bool cppVar_20812;
	BIT_VEC cppVar_20814;
	BIT_VEC cppVar_20815;
	BIT_VEC cppVar_20816;
	BIT_VEC cppVar_20817;
	bool cppVar_20818;
	BIT_VEC cppVar_20820;
	BIT_VEC cppVar_20821;
	BIT_VEC cppVar_20822;
	BIT_VEC cppVar_20823;
	bool cppVar_20824;
	BIT_VEC cppVar_20826;
	BIT_VEC cppVar_20827;
	BIT_VEC cppVar_20828;
	BIT_VEC cppVar_20829;
	bool cppVar_20830;
	BIT_VEC cppVar_20832;
	BIT_VEC cppVar_20833;
	BIT_VEC cppVar_20834;
	BIT_VEC cppVar_20835;
	bool cppVar_20836;
	BIT_VEC cppVar_20838;
	BIT_VEC cppVar_20839;
	BIT_VEC cppVar_20840;
	BIT_VEC cppVar_20841;
	bool cppVar_20842;
	BIT_VEC cppVar_20844;
	BIT_VEC cppVar_20845;
	BIT_VEC cppVar_20846;
	BIT_VEC cppVar_20847;
	bool cppVar_20848;
	BIT_VEC cppVar_20850;
	BIT_VEC cppVar_20851;
	BIT_VEC cppVar_20852;
	BIT_VEC cppVar_20853;
	bool cppVar_20854;
	BIT_VEC cppVar_20856;
	BIT_VEC cppVar_20857;
	BIT_VEC cppVar_20858;
	BIT_VEC cppVar_20859;
	bool cppVar_20860;
	BIT_VEC cppVar_20862;
	BIT_VEC cppVar_20863;
	BIT_VEC cppVar_20864;
	BIT_VEC cppVar_20865;
	bool cppVar_20866;
	BIT_VEC cppVar_20868;
	BIT_VEC cppVar_20869;
	BIT_VEC cppVar_20870;
	BIT_VEC cppVar_20871;
	bool cppVar_20872;
	BIT_VEC cppVar_20874;
	BIT_VEC cppVar_20875;
	BIT_VEC cppVar_20876;
	BIT_VEC cppVar_20877;
	bool cppVar_20878;
	BIT_VEC cppVar_20880;
	BIT_VEC cppVar_20881;
	BIT_VEC cppVar_20882;
	BIT_VEC cppVar_20883;
	bool cppVar_20884;
	BIT_VEC cppVar_20886;
	BIT_VEC cppVar_20887;
	BIT_VEC cppVar_20888;
	BIT_VEC cppVar_20889;
	bool cppVar_20890;
	BIT_VEC cppVar_20892;
	BIT_VEC cppVar_20893;
	BIT_VEC cppVar_20894;
	BIT_VEC cppVar_20895;
	bool cppVar_20896;
	BIT_VEC cppVar_20898;
	BIT_VEC cppVar_20899;
	BIT_VEC cppVar_20900;
	BIT_VEC cppVar_20901;
	bool cppVar_20902;
	BIT_VEC cppVar_20903;
	BIT_VEC cppVar_20897;
	BIT_VEC cppVar_20891;
	BIT_VEC cppVar_20885;
	BIT_VEC cppVar_20879;
	BIT_VEC cppVar_20873;
	BIT_VEC cppVar_20867;
	BIT_VEC cppVar_20861;
	BIT_VEC cppVar_20855;
	BIT_VEC cppVar_20849;
	BIT_VEC cppVar_20843;
	BIT_VEC cppVar_20837;
	BIT_VEC cppVar_20831;
	BIT_VEC cppVar_20825;
	BIT_VEC cppVar_20819;
	BIT_VEC cppVar_20813;
	BIT_VEC cppVar_20807;
	BIT_VEC cppVar_20801;
	BIT_VEC cppVar_20795;
	BIT_VEC cppVar_20789;
	BIT_VEC cppVar_20783;
	BIT_VEC cppVar_20777;
	BIT_VEC cppVar_20764;
	BIT_VEC cppVar_20758;
	BIT_VEC cppVar_20905;
	BIT_VEC cppVar_20906;
	bool cppVar_20907;
	BIT_VEC cppVar_20909;
	BIT_VEC cppVar_20910;
	BIT_VEC cppVar_20911;
	BIT_VEC cppVar_20912;
	bool cppVar_20913;
	BIT_VEC cppVar_20914;
	BIT_VEC cppVar_20915;
	BIT_VEC cppVar_20916;
	BIT_VEC cppVar_20917;
	BIT_VEC cppVar_20918;
	BIT_VEC cppVar_20919;
	BIT_VEC cppVar_20920;
	BIT_VEC cppVar_20908;
	BIT_VEC cppVar_20922;
	BIT_VEC cppVar_20923;
	bool cppVar_20924;
	BIT_VEC cppVar_20926;
	BIT_VEC cppVar_20927;
	BIT_VEC cppVar_20928;
	BIT_VEC cppVar_20929;
	bool cppVar_20930;
	BIT_VEC cppVar_20931;
	BIT_VEC cppVar_20932;
	BIT_VEC cppVar_20933;
	BIT_VEC cppVar_20934;
	BIT_VEC cppVar_20935;
	BIT_VEC cppVar_20936;
	BIT_VEC cppVar_20937;
	BIT_VEC cppVar_20925;
	BIT_VEC cppVar_20939;
	BIT_VEC cppVar_20940;
	bool cppVar_20941;
	BIT_VEC cppVar_20943;
	BIT_VEC cppVar_20944;
	BIT_VEC cppVar_20945;
	BIT_VEC cppVar_20946;
	bool cppVar_20947;
	BIT_VEC cppVar_20949;
	BIT_VEC cppVar_20950;
	BIT_VEC cppVar_20951;
	BIT_VEC cppVar_20952;
	BIT_VEC cppVar_20953;
	bool cppVar_20954;
	BIT_VEC cppVar_20955;
	BIT_VEC cppVar_20956;
	BIT_VEC cppVar_20957;
	BIT_VEC cppVar_20959;
	BIT_VEC cppVar_20960;
	BIT_VEC cppVar_20961;
	bool cppVar_20962;
	BIT_VEC cppVar_20964;
	BIT_VEC cppVar_20965;
	BIT_VEC cppVar_20966;
	bool cppVar_20967;
	BIT_VEC cppVar_20969;
	BIT_VEC cppVar_20970;
	BIT_VEC cppVar_20971;
	bool cppVar_20972;
	BIT_VEC cppVar_20974;
	BIT_VEC cppVar_20975;
	BIT_VEC cppVar_20976;
	bool cppVar_20977;
	BIT_VEC cppVar_20979;
	BIT_VEC cppVar_20980;
	BIT_VEC cppVar_20981;
	bool cppVar_20982;
	BIT_VEC cppVar_20984;
	BIT_VEC cppVar_20985;
	BIT_VEC cppVar_20986;
	bool cppVar_20987;
	BIT_VEC cppVar_20989;
	BIT_VEC cppVar_20990;
	BIT_VEC cppVar_20991;
	bool cppVar_20992;
	BIT_VEC cppVar_20994;
	BIT_VEC cppVar_20995;
	BIT_VEC cppVar_20996;
	bool cppVar_20997;
	BIT_VEC cppVar_20999;
	BIT_VEC cppVar_21000;
	BIT_VEC cppVar_21001;
	bool cppVar_21002;
	BIT_VEC cppVar_21004;
	BIT_VEC cppVar_21005;
	BIT_VEC cppVar_21006;
	bool cppVar_21007;
	BIT_VEC cppVar_21009;
	BIT_VEC cppVar_21010;
	BIT_VEC cppVar_21011;
	bool cppVar_21012;
	BIT_VEC cppVar_21014;
	BIT_VEC cppVar_21015;
	BIT_VEC cppVar_21016;
	bool cppVar_21017;
	BIT_VEC cppVar_21019;
	BIT_VEC cppVar_21020;
	BIT_VEC cppVar_21021;
	bool cppVar_21022;
	BIT_VEC cppVar_21024;
	BIT_VEC cppVar_21025;
	BIT_VEC cppVar_21026;
	bool cppVar_21027;
	BIT_VEC cppVar_21029;
	BIT_VEC cppVar_21030;
	BIT_VEC cppVar_21031;
	bool cppVar_21032;
	BIT_VEC cppVar_21034;
	BIT_VEC cppVar_21035;
	BIT_VEC cppVar_21036;
	bool cppVar_21037;
	BIT_VEC cppVar_21039;
	BIT_VEC cppVar_21040;
	BIT_VEC cppVar_21041;
	bool cppVar_21042;
	BIT_VEC cppVar_21044;
	BIT_VEC cppVar_21045;
	BIT_VEC cppVar_21046;
	bool cppVar_21047;
	BIT_VEC cppVar_21049;
	BIT_VEC cppVar_21050;
	BIT_VEC cppVar_21051;
	bool cppVar_21052;
	BIT_VEC cppVar_21054;
	BIT_VEC cppVar_21055;
	BIT_VEC cppVar_21056;
	bool cppVar_21057;
	BIT_VEC cppVar_21059;
	BIT_VEC cppVar_21060;
	BIT_VEC cppVar_21061;
	bool cppVar_21062;
	BIT_VEC cppVar_21063;
	BIT_VEC cppVar_21058;
	BIT_VEC cppVar_21053;
	BIT_VEC cppVar_21048;
	BIT_VEC cppVar_21043;
	BIT_VEC cppVar_21038;
	BIT_VEC cppVar_21033;
	BIT_VEC cppVar_21028;
	BIT_VEC cppVar_21023;
	BIT_VEC cppVar_21018;
	BIT_VEC cppVar_21013;
	BIT_VEC cppVar_21008;
	BIT_VEC cppVar_21003;
	BIT_VEC cppVar_20998;
	BIT_VEC cppVar_20993;
	BIT_VEC cppVar_20988;
	BIT_VEC cppVar_20983;
	BIT_VEC cppVar_20978;
	BIT_VEC cppVar_20973;
	BIT_VEC cppVar_20968;
	BIT_VEC cppVar_20963;
	BIT_VEC cppVar_20958;
	BIT_VEC cppVar_20948;
	BIT_VEC cppVar_20942;
	BIT_VEC cppVar_21065;
	BIT_VEC cppVar_21066;
	bool cppVar_21067;
	BIT_VEC cppVar_21069;
	BIT_VEC cppVar_21070;
	BIT_VEC cppVar_21071;
	BIT_VEC cppVar_21072;
	bool cppVar_21073;
	BIT_VEC cppVar_21074;
	BIT_VEC cppVar_21075;
	BIT_VEC cppVar_21076;
	BIT_VEC cppVar_21068;
	BIT_VEC cppVar_21078;
	BIT_VEC cppVar_21079;
	bool cppVar_21080;
	BIT_VEC cppVar_21082;
	BIT_VEC cppVar_21083;
	BIT_VEC cppVar_21084;
	BIT_VEC cppVar_21085;
	bool cppVar_21086;
	BIT_VEC cppVar_21088;
	BIT_VEC cppVar_21089;
	BIT_VEC cppVar_21090;
	BIT_VEC cppVar_21091;
	bool cppVar_21092;
	BIT_VEC cppVar_21093;
	BIT_VEC cppVar_21094;
	BIT_VEC cppVar_21095;
	BIT_VEC cppVar_21097;
	BIT_VEC cppVar_21098;
	BIT_VEC cppVar_21099;
	bool cppVar_21100;
	BIT_VEC cppVar_21102;
	BIT_VEC cppVar_21103;
	BIT_VEC cppVar_21104;
	bool cppVar_21105;
	BIT_VEC cppVar_21107;
	BIT_VEC cppVar_21108;
	BIT_VEC cppVar_21109;
	bool cppVar_21110;
	BIT_VEC cppVar_21112;
	BIT_VEC cppVar_21113;
	BIT_VEC cppVar_21114;
	bool cppVar_21115;
	BIT_VEC cppVar_21117;
	BIT_VEC cppVar_21118;
	BIT_VEC cppVar_21119;
	bool cppVar_21120;
	BIT_VEC cppVar_21122;
	BIT_VEC cppVar_21123;
	BIT_VEC cppVar_21124;
	bool cppVar_21125;
	BIT_VEC cppVar_21127;
	BIT_VEC cppVar_21128;
	BIT_VEC cppVar_21129;
	bool cppVar_21130;
	BIT_VEC cppVar_21132;
	BIT_VEC cppVar_21133;
	BIT_VEC cppVar_21134;
	bool cppVar_21135;
	BIT_VEC cppVar_21137;
	BIT_VEC cppVar_21138;
	BIT_VEC cppVar_21139;
	bool cppVar_21140;
	BIT_VEC cppVar_21142;
	BIT_VEC cppVar_21143;
	BIT_VEC cppVar_21144;
	bool cppVar_21145;
	BIT_VEC cppVar_21147;
	BIT_VEC cppVar_21148;
	BIT_VEC cppVar_21149;
	bool cppVar_21150;
	BIT_VEC cppVar_21152;
	BIT_VEC cppVar_21153;
	BIT_VEC cppVar_21154;
	bool cppVar_21155;
	BIT_VEC cppVar_21157;
	BIT_VEC cppVar_21158;
	BIT_VEC cppVar_21159;
	bool cppVar_21160;
	BIT_VEC cppVar_21162;
	BIT_VEC cppVar_21163;
	BIT_VEC cppVar_21164;
	bool cppVar_21165;
	BIT_VEC cppVar_21167;
	BIT_VEC cppVar_21168;
	BIT_VEC cppVar_21169;
	bool cppVar_21170;
	BIT_VEC cppVar_21172;
	BIT_VEC cppVar_21173;
	BIT_VEC cppVar_21174;
	bool cppVar_21175;
	BIT_VEC cppVar_21177;
	BIT_VEC cppVar_21178;
	BIT_VEC cppVar_21179;
	bool cppVar_21180;
	BIT_VEC cppVar_21182;
	BIT_VEC cppVar_21183;
	BIT_VEC cppVar_21184;
	bool cppVar_21185;
	BIT_VEC cppVar_21187;
	BIT_VEC cppVar_21188;
	BIT_VEC cppVar_21189;
	bool cppVar_21190;
	BIT_VEC cppVar_21192;
	BIT_VEC cppVar_21193;
	BIT_VEC cppVar_21194;
	bool cppVar_21195;
	BIT_VEC cppVar_21197;
	BIT_VEC cppVar_21198;
	BIT_VEC cppVar_21199;
	bool cppVar_21200;
	BIT_VEC cppVar_21201;
	BIT_VEC cppVar_21196;
	BIT_VEC cppVar_21191;
	BIT_VEC cppVar_21186;
	BIT_VEC cppVar_21181;
	BIT_VEC cppVar_21176;
	BIT_VEC cppVar_21171;
	BIT_VEC cppVar_21166;
	BIT_VEC cppVar_21161;
	BIT_VEC cppVar_21156;
	BIT_VEC cppVar_21151;
	BIT_VEC cppVar_21146;
	BIT_VEC cppVar_21141;
	BIT_VEC cppVar_21136;
	BIT_VEC cppVar_21131;
	BIT_VEC cppVar_21126;
	BIT_VEC cppVar_21121;
	BIT_VEC cppVar_21116;
	BIT_VEC cppVar_21111;
	BIT_VEC cppVar_21106;
	BIT_VEC cppVar_21101;
	BIT_VEC cppVar_21096;
	BIT_VEC cppVar_21087;
	BIT_VEC cppVar_21202;
	BIT_VEC cppVar_21203;
	BIT_VEC cppVar_21204;
	BIT_VEC cppVar_21205;
	BIT_VEC cppVar_21081;
	BIT_VEC cppVar_21207;
	BIT_VEC cppVar_21208;
	bool cppVar_21209;
	BIT_VEC cppVar_21211;
	BIT_VEC cppVar_21212;
	BIT_VEC cppVar_21213;
	BIT_VEC cppVar_21214;
	bool cppVar_21215;
	BIT_VEC cppVar_21217;
	BIT_VEC cppVar_21218;
	BIT_VEC cppVar_21219;
	BIT_VEC cppVar_21220;
	bool cppVar_21221;
	BIT_VEC cppVar_21222;
	BIT_VEC cppVar_21223;
	BIT_VEC cppVar_21224;
	BIT_VEC cppVar_21226;
	BIT_VEC cppVar_21227;
	BIT_VEC cppVar_21228;
	bool cppVar_21229;
	BIT_VEC cppVar_21231;
	BIT_VEC cppVar_21232;
	BIT_VEC cppVar_21233;
	bool cppVar_21234;
	BIT_VEC cppVar_21236;
	BIT_VEC cppVar_21237;
	BIT_VEC cppVar_21238;
	bool cppVar_21239;
	BIT_VEC cppVar_21241;
	BIT_VEC cppVar_21242;
	BIT_VEC cppVar_21243;
	bool cppVar_21244;
	BIT_VEC cppVar_21246;
	BIT_VEC cppVar_21247;
	BIT_VEC cppVar_21248;
	bool cppVar_21249;
	BIT_VEC cppVar_21251;
	BIT_VEC cppVar_21252;
	BIT_VEC cppVar_21253;
	bool cppVar_21254;
	BIT_VEC cppVar_21256;
	BIT_VEC cppVar_21257;
	BIT_VEC cppVar_21258;
	bool cppVar_21259;
	BIT_VEC cppVar_21261;
	BIT_VEC cppVar_21262;
	BIT_VEC cppVar_21263;
	bool cppVar_21264;
	BIT_VEC cppVar_21266;
	BIT_VEC cppVar_21267;
	BIT_VEC cppVar_21268;
	bool cppVar_21269;
	BIT_VEC cppVar_21271;
	BIT_VEC cppVar_21272;
	BIT_VEC cppVar_21273;
	bool cppVar_21274;
	BIT_VEC cppVar_21276;
	BIT_VEC cppVar_21277;
	BIT_VEC cppVar_21278;
	bool cppVar_21279;
	BIT_VEC cppVar_21281;
	BIT_VEC cppVar_21282;
	BIT_VEC cppVar_21283;
	bool cppVar_21284;
	BIT_VEC cppVar_21286;
	BIT_VEC cppVar_21287;
	BIT_VEC cppVar_21288;
	bool cppVar_21289;
	BIT_VEC cppVar_21291;
	BIT_VEC cppVar_21292;
	BIT_VEC cppVar_21293;
	bool cppVar_21294;
	BIT_VEC cppVar_21296;
	BIT_VEC cppVar_21297;
	BIT_VEC cppVar_21298;
	bool cppVar_21299;
	BIT_VEC cppVar_21301;
	BIT_VEC cppVar_21302;
	BIT_VEC cppVar_21303;
	bool cppVar_21304;
	BIT_VEC cppVar_21306;
	BIT_VEC cppVar_21307;
	BIT_VEC cppVar_21308;
	bool cppVar_21309;
	BIT_VEC cppVar_21311;
	BIT_VEC cppVar_21312;
	BIT_VEC cppVar_21313;
	bool cppVar_21314;
	BIT_VEC cppVar_21316;
	BIT_VEC cppVar_21317;
	BIT_VEC cppVar_21318;
	bool cppVar_21319;
	BIT_VEC cppVar_21321;
	BIT_VEC cppVar_21322;
	BIT_VEC cppVar_21323;
	bool cppVar_21324;
	BIT_VEC cppVar_21326;
	BIT_VEC cppVar_21327;
	BIT_VEC cppVar_21328;
	bool cppVar_21329;
	BIT_VEC cppVar_21330;
	BIT_VEC cppVar_21325;
	BIT_VEC cppVar_21320;
	BIT_VEC cppVar_21315;
	BIT_VEC cppVar_21310;
	BIT_VEC cppVar_21305;
	BIT_VEC cppVar_21300;
	BIT_VEC cppVar_21295;
	BIT_VEC cppVar_21290;
	BIT_VEC cppVar_21285;
	BIT_VEC cppVar_21280;
	BIT_VEC cppVar_21275;
	BIT_VEC cppVar_21270;
	BIT_VEC cppVar_21265;
	BIT_VEC cppVar_21260;
	BIT_VEC cppVar_21255;
	BIT_VEC cppVar_21250;
	BIT_VEC cppVar_21245;
	BIT_VEC cppVar_21240;
	BIT_VEC cppVar_21235;
	BIT_VEC cppVar_21230;
	BIT_VEC cppVar_21225;
	BIT_VEC cppVar_21216;
	BIT_VEC cppVar_21331;
	BIT_VEC cppVar_21210;
	BIT_VEC cppVar_21333;
	BIT_VEC cppVar_21334;
	bool cppVar_21335;
	BIT_VEC cppVar_21337;
	BIT_VEC cppVar_21338;
	BIT_VEC cppVar_21339;
	BIT_VEC cppVar_21340;
	bool cppVar_21341;
	BIT_VEC cppVar_21343;
	BIT_VEC cppVar_21344;
	BIT_VEC cppVar_21345;
	BIT_VEC cppVar_21346;
	bool cppVar_21347;
	BIT_VEC cppVar_21348;
	BIT_VEC cppVar_21349;
	BIT_VEC cppVar_21350;
	BIT_VEC cppVar_21352;
	BIT_VEC cppVar_21353;
	BIT_VEC cppVar_21354;
	bool cppVar_21355;
	BIT_VEC cppVar_21357;
	BIT_VEC cppVar_21358;
	BIT_VEC cppVar_21359;
	bool cppVar_21360;
	BIT_VEC cppVar_21362;
	BIT_VEC cppVar_21363;
	BIT_VEC cppVar_21364;
	bool cppVar_21365;
	BIT_VEC cppVar_21367;
	BIT_VEC cppVar_21368;
	BIT_VEC cppVar_21369;
	bool cppVar_21370;
	BIT_VEC cppVar_21372;
	BIT_VEC cppVar_21373;
	BIT_VEC cppVar_21374;
	bool cppVar_21375;
	BIT_VEC cppVar_21377;
	BIT_VEC cppVar_21378;
	BIT_VEC cppVar_21379;
	bool cppVar_21380;
	BIT_VEC cppVar_21382;
	BIT_VEC cppVar_21383;
	BIT_VEC cppVar_21384;
	bool cppVar_21385;
	BIT_VEC cppVar_21387;
	BIT_VEC cppVar_21388;
	BIT_VEC cppVar_21389;
	bool cppVar_21390;
	BIT_VEC cppVar_21392;
	BIT_VEC cppVar_21393;
	BIT_VEC cppVar_21394;
	bool cppVar_21395;
	BIT_VEC cppVar_21397;
	BIT_VEC cppVar_21398;
	BIT_VEC cppVar_21399;
	bool cppVar_21400;
	BIT_VEC cppVar_21402;
	BIT_VEC cppVar_21403;
	BIT_VEC cppVar_21404;
	bool cppVar_21405;
	BIT_VEC cppVar_21407;
	BIT_VEC cppVar_21408;
	BIT_VEC cppVar_21409;
	bool cppVar_21410;
	BIT_VEC cppVar_21412;
	BIT_VEC cppVar_21413;
	BIT_VEC cppVar_21414;
	bool cppVar_21415;
	BIT_VEC cppVar_21417;
	BIT_VEC cppVar_21418;
	BIT_VEC cppVar_21419;
	bool cppVar_21420;
	BIT_VEC cppVar_21422;
	BIT_VEC cppVar_21423;
	BIT_VEC cppVar_21424;
	bool cppVar_21425;
	BIT_VEC cppVar_21427;
	BIT_VEC cppVar_21428;
	BIT_VEC cppVar_21429;
	bool cppVar_21430;
	BIT_VEC cppVar_21432;
	BIT_VEC cppVar_21433;
	BIT_VEC cppVar_21434;
	bool cppVar_21435;
	BIT_VEC cppVar_21437;
	BIT_VEC cppVar_21438;
	BIT_VEC cppVar_21439;
	bool cppVar_21440;
	BIT_VEC cppVar_21442;
	BIT_VEC cppVar_21443;
	BIT_VEC cppVar_21444;
	bool cppVar_21445;
	BIT_VEC cppVar_21447;
	BIT_VEC cppVar_21448;
	BIT_VEC cppVar_21449;
	bool cppVar_21450;
	BIT_VEC cppVar_21452;
	BIT_VEC cppVar_21453;
	BIT_VEC cppVar_21454;
	bool cppVar_21455;
	BIT_VEC cppVar_21456;
	BIT_VEC cppVar_21451;
	BIT_VEC cppVar_21446;
	BIT_VEC cppVar_21441;
	BIT_VEC cppVar_21436;
	BIT_VEC cppVar_21431;
	BIT_VEC cppVar_21426;
	BIT_VEC cppVar_21421;
	BIT_VEC cppVar_21416;
	BIT_VEC cppVar_21411;
	BIT_VEC cppVar_21406;
	BIT_VEC cppVar_21401;
	BIT_VEC cppVar_21396;
	BIT_VEC cppVar_21391;
	BIT_VEC cppVar_21386;
	BIT_VEC cppVar_21381;
	BIT_VEC cppVar_21376;
	BIT_VEC cppVar_21371;
	BIT_VEC cppVar_21366;
	BIT_VEC cppVar_21361;
	BIT_VEC cppVar_21356;
	BIT_VEC cppVar_21351;
	BIT_VEC cppVar_21342;
	BIT_VEC cppVar_21457;
	BIT_VEC cppVar_21458;
	BIT_VEC cppVar_21459;
	BIT_VEC cppVar_21460;
	BIT_VEC cppVar_21336;
	BIT_VEC cppVar_21462;
	BIT_VEC cppVar_21463;
	bool cppVar_21464;
	BIT_VEC cppVar_21466;
	BIT_VEC cppVar_21467;
	BIT_VEC cppVar_21468;
	BIT_VEC cppVar_21469;
	bool cppVar_21470;
	BIT_VEC cppVar_21472;
	BIT_VEC cppVar_21473;
	BIT_VEC cppVar_21474;
	BIT_VEC cppVar_21475;
	bool cppVar_21476;
	BIT_VEC cppVar_21477;
	BIT_VEC cppVar_21478;
	BIT_VEC cppVar_21479;
	BIT_VEC cppVar_21481;
	BIT_VEC cppVar_21482;
	BIT_VEC cppVar_21483;
	bool cppVar_21484;
	BIT_VEC cppVar_21486;
	BIT_VEC cppVar_21487;
	BIT_VEC cppVar_21488;
	bool cppVar_21489;
	BIT_VEC cppVar_21491;
	BIT_VEC cppVar_21492;
	BIT_VEC cppVar_21493;
	bool cppVar_21494;
	BIT_VEC cppVar_21496;
	BIT_VEC cppVar_21497;
	BIT_VEC cppVar_21498;
	bool cppVar_21499;
	BIT_VEC cppVar_21501;
	BIT_VEC cppVar_21502;
	BIT_VEC cppVar_21503;
	bool cppVar_21504;
	BIT_VEC cppVar_21506;
	BIT_VEC cppVar_21507;
	BIT_VEC cppVar_21508;
	bool cppVar_21509;
	BIT_VEC cppVar_21511;
	BIT_VEC cppVar_21512;
	BIT_VEC cppVar_21513;
	bool cppVar_21514;
	BIT_VEC cppVar_21516;
	BIT_VEC cppVar_21517;
	BIT_VEC cppVar_21518;
	bool cppVar_21519;
	BIT_VEC cppVar_21521;
	BIT_VEC cppVar_21522;
	BIT_VEC cppVar_21523;
	bool cppVar_21524;
	BIT_VEC cppVar_21526;
	BIT_VEC cppVar_21527;
	BIT_VEC cppVar_21528;
	bool cppVar_21529;
	BIT_VEC cppVar_21531;
	BIT_VEC cppVar_21532;
	BIT_VEC cppVar_21533;
	bool cppVar_21534;
	BIT_VEC cppVar_21536;
	BIT_VEC cppVar_21537;
	BIT_VEC cppVar_21538;
	bool cppVar_21539;
	BIT_VEC cppVar_21541;
	BIT_VEC cppVar_21542;
	BIT_VEC cppVar_21543;
	bool cppVar_21544;
	BIT_VEC cppVar_21546;
	BIT_VEC cppVar_21547;
	BIT_VEC cppVar_21548;
	bool cppVar_21549;
	BIT_VEC cppVar_21551;
	BIT_VEC cppVar_21552;
	BIT_VEC cppVar_21553;
	bool cppVar_21554;
	BIT_VEC cppVar_21556;
	BIT_VEC cppVar_21557;
	BIT_VEC cppVar_21558;
	bool cppVar_21559;
	BIT_VEC cppVar_21561;
	BIT_VEC cppVar_21562;
	BIT_VEC cppVar_21563;
	bool cppVar_21564;
	BIT_VEC cppVar_21566;
	BIT_VEC cppVar_21567;
	BIT_VEC cppVar_21568;
	bool cppVar_21569;
	BIT_VEC cppVar_21571;
	BIT_VEC cppVar_21572;
	BIT_VEC cppVar_21573;
	bool cppVar_21574;
	BIT_VEC cppVar_21576;
	BIT_VEC cppVar_21577;
	BIT_VEC cppVar_21578;
	bool cppVar_21579;
	BIT_VEC cppVar_21581;
	BIT_VEC cppVar_21582;
	BIT_VEC cppVar_21583;
	bool cppVar_21584;
	BIT_VEC cppVar_21585;
	BIT_VEC cppVar_21580;
	BIT_VEC cppVar_21575;
	BIT_VEC cppVar_21570;
	BIT_VEC cppVar_21565;
	BIT_VEC cppVar_21560;
	BIT_VEC cppVar_21555;
	BIT_VEC cppVar_21550;
	BIT_VEC cppVar_21545;
	BIT_VEC cppVar_21540;
	BIT_VEC cppVar_21535;
	BIT_VEC cppVar_21530;
	BIT_VEC cppVar_21525;
	BIT_VEC cppVar_21520;
	BIT_VEC cppVar_21515;
	BIT_VEC cppVar_21510;
	BIT_VEC cppVar_21505;
	BIT_VEC cppVar_21500;
	BIT_VEC cppVar_21495;
	BIT_VEC cppVar_21490;
	BIT_VEC cppVar_21485;
	BIT_VEC cppVar_21480;
	BIT_VEC cppVar_21471;
	BIT_VEC cppVar_21586;
	BIT_VEC cppVar_21465;
	BIT_VEC cppVar_21588;
	BIT_VEC cppVar_21589;
	bool cppVar_21590;
	BIT_VEC cppVar_21592;
	BIT_VEC cppVar_21593;
	BIT_VEC cppVar_21594;
	BIT_VEC cppVar_21595;
	bool cppVar_21596;
	BIT_VEC cppVar_21598;
	BIT_VEC cppVar_21599;
	BIT_VEC cppVar_21600;
	BIT_VEC cppVar_21601;
	bool cppVar_21602;
	BIT_VEC cppVar_21603;
	BIT_VEC cppVar_21604;
	BIT_VEC cppVar_21605;
	BIT_VEC cppVar_21607;
	BIT_VEC cppVar_21608;
	BIT_VEC cppVar_21609;
	bool cppVar_21610;
	BIT_VEC cppVar_21612;
	BIT_VEC cppVar_21613;
	BIT_VEC cppVar_21614;
	bool cppVar_21615;
	BIT_VEC cppVar_21617;
	BIT_VEC cppVar_21618;
	BIT_VEC cppVar_21619;
	bool cppVar_21620;
	BIT_VEC cppVar_21622;
	BIT_VEC cppVar_21623;
	BIT_VEC cppVar_21624;
	bool cppVar_21625;
	BIT_VEC cppVar_21627;
	BIT_VEC cppVar_21628;
	BIT_VEC cppVar_21629;
	bool cppVar_21630;
	BIT_VEC cppVar_21632;
	BIT_VEC cppVar_21633;
	BIT_VEC cppVar_21634;
	bool cppVar_21635;
	BIT_VEC cppVar_21637;
	BIT_VEC cppVar_21638;
	BIT_VEC cppVar_21639;
	bool cppVar_21640;
	BIT_VEC cppVar_21642;
	BIT_VEC cppVar_21643;
	BIT_VEC cppVar_21644;
	bool cppVar_21645;
	BIT_VEC cppVar_21647;
	BIT_VEC cppVar_21648;
	BIT_VEC cppVar_21649;
	bool cppVar_21650;
	BIT_VEC cppVar_21652;
	BIT_VEC cppVar_21653;
	BIT_VEC cppVar_21654;
	bool cppVar_21655;
	BIT_VEC cppVar_21657;
	BIT_VEC cppVar_21658;
	BIT_VEC cppVar_21659;
	bool cppVar_21660;
	BIT_VEC cppVar_21662;
	BIT_VEC cppVar_21663;
	BIT_VEC cppVar_21664;
	bool cppVar_21665;
	BIT_VEC cppVar_21667;
	BIT_VEC cppVar_21668;
	BIT_VEC cppVar_21669;
	bool cppVar_21670;
	BIT_VEC cppVar_21672;
	BIT_VEC cppVar_21673;
	BIT_VEC cppVar_21674;
	bool cppVar_21675;
	BIT_VEC cppVar_21677;
	BIT_VEC cppVar_21678;
	BIT_VEC cppVar_21679;
	bool cppVar_21680;
	BIT_VEC cppVar_21682;
	BIT_VEC cppVar_21683;
	BIT_VEC cppVar_21684;
	bool cppVar_21685;
	BIT_VEC cppVar_21687;
	BIT_VEC cppVar_21688;
	BIT_VEC cppVar_21689;
	bool cppVar_21690;
	BIT_VEC cppVar_21692;
	BIT_VEC cppVar_21693;
	BIT_VEC cppVar_21694;
	bool cppVar_21695;
	BIT_VEC cppVar_21697;
	BIT_VEC cppVar_21698;
	BIT_VEC cppVar_21699;
	bool cppVar_21700;
	BIT_VEC cppVar_21702;
	BIT_VEC cppVar_21703;
	BIT_VEC cppVar_21704;
	bool cppVar_21705;
	BIT_VEC cppVar_21707;
	BIT_VEC cppVar_21708;
	BIT_VEC cppVar_21709;
	bool cppVar_21710;
	BIT_VEC cppVar_21711;
	BIT_VEC cppVar_21706;
	BIT_VEC cppVar_21701;
	BIT_VEC cppVar_21696;
	BIT_VEC cppVar_21691;
	BIT_VEC cppVar_21686;
	BIT_VEC cppVar_21681;
	BIT_VEC cppVar_21676;
	BIT_VEC cppVar_21671;
	BIT_VEC cppVar_21666;
	BIT_VEC cppVar_21661;
	BIT_VEC cppVar_21656;
	BIT_VEC cppVar_21651;
	BIT_VEC cppVar_21646;
	BIT_VEC cppVar_21641;
	BIT_VEC cppVar_21636;
	BIT_VEC cppVar_21631;
	BIT_VEC cppVar_21626;
	BIT_VEC cppVar_21621;
	BIT_VEC cppVar_21616;
	BIT_VEC cppVar_21611;
	BIT_VEC cppVar_21606;
	BIT_VEC cppVar_21597;
	BIT_VEC cppVar_21712;
	BIT_VEC cppVar_21713;
	BIT_VEC cppVar_21714;
	BIT_VEC cppVar_21715;
	BIT_VEC cppVar_21591;
	BIT_VEC cppVar_21717;
	BIT_VEC cppVar_21718;
	bool cppVar_21719;
	BIT_VEC cppVar_21721;
	BIT_VEC cppVar_21722;
	BIT_VEC cppVar_21723;
	BIT_VEC cppVar_21724;
	bool cppVar_21725;
	BIT_VEC cppVar_21727;
	BIT_VEC cppVar_21728;
	BIT_VEC cppVar_21729;
	BIT_VEC cppVar_21730;
	bool cppVar_21731;
	BIT_VEC cppVar_21732;
	BIT_VEC cppVar_21733;
	BIT_VEC cppVar_21734;
	BIT_VEC cppVar_21736;
	BIT_VEC cppVar_21737;
	BIT_VEC cppVar_21738;
	bool cppVar_21739;
	BIT_VEC cppVar_21741;
	BIT_VEC cppVar_21742;
	BIT_VEC cppVar_21743;
	bool cppVar_21744;
	BIT_VEC cppVar_21746;
	BIT_VEC cppVar_21747;
	BIT_VEC cppVar_21748;
	bool cppVar_21749;
	BIT_VEC cppVar_21751;
	BIT_VEC cppVar_21752;
	BIT_VEC cppVar_21753;
	bool cppVar_21754;
	BIT_VEC cppVar_21756;
	BIT_VEC cppVar_21757;
	BIT_VEC cppVar_21758;
	bool cppVar_21759;
	BIT_VEC cppVar_21761;
	BIT_VEC cppVar_21762;
	BIT_VEC cppVar_21763;
	bool cppVar_21764;
	BIT_VEC cppVar_21766;
	BIT_VEC cppVar_21767;
	BIT_VEC cppVar_21768;
	bool cppVar_21769;
	BIT_VEC cppVar_21771;
	BIT_VEC cppVar_21772;
	BIT_VEC cppVar_21773;
	bool cppVar_21774;
	BIT_VEC cppVar_21776;
	BIT_VEC cppVar_21777;
	BIT_VEC cppVar_21778;
	bool cppVar_21779;
	BIT_VEC cppVar_21781;
	BIT_VEC cppVar_21782;
	BIT_VEC cppVar_21783;
	bool cppVar_21784;
	BIT_VEC cppVar_21786;
	BIT_VEC cppVar_21787;
	BIT_VEC cppVar_21788;
	bool cppVar_21789;
	BIT_VEC cppVar_21791;
	BIT_VEC cppVar_21792;
	BIT_VEC cppVar_21793;
	bool cppVar_21794;
	BIT_VEC cppVar_21796;
	BIT_VEC cppVar_21797;
	BIT_VEC cppVar_21798;
	bool cppVar_21799;
	BIT_VEC cppVar_21801;
	BIT_VEC cppVar_21802;
	BIT_VEC cppVar_21803;
	bool cppVar_21804;
	BIT_VEC cppVar_21806;
	BIT_VEC cppVar_21807;
	BIT_VEC cppVar_21808;
	bool cppVar_21809;
	BIT_VEC cppVar_21811;
	BIT_VEC cppVar_21812;
	BIT_VEC cppVar_21813;
	bool cppVar_21814;
	BIT_VEC cppVar_21816;
	BIT_VEC cppVar_21817;
	BIT_VEC cppVar_21818;
	bool cppVar_21819;
	BIT_VEC cppVar_21821;
	BIT_VEC cppVar_21822;
	BIT_VEC cppVar_21823;
	bool cppVar_21824;
	BIT_VEC cppVar_21826;
	BIT_VEC cppVar_21827;
	BIT_VEC cppVar_21828;
	bool cppVar_21829;
	BIT_VEC cppVar_21831;
	BIT_VEC cppVar_21832;
	BIT_VEC cppVar_21833;
	bool cppVar_21834;
	BIT_VEC cppVar_21836;
	BIT_VEC cppVar_21837;
	BIT_VEC cppVar_21838;
	bool cppVar_21839;
	BIT_VEC cppVar_21840;
	BIT_VEC cppVar_21835;
	BIT_VEC cppVar_21830;
	BIT_VEC cppVar_21825;
	BIT_VEC cppVar_21820;
	BIT_VEC cppVar_21815;
	BIT_VEC cppVar_21810;
	BIT_VEC cppVar_21805;
	BIT_VEC cppVar_21800;
	BIT_VEC cppVar_21795;
	BIT_VEC cppVar_21790;
	BIT_VEC cppVar_21785;
	BIT_VEC cppVar_21780;
	BIT_VEC cppVar_21775;
	BIT_VEC cppVar_21770;
	BIT_VEC cppVar_21765;
	BIT_VEC cppVar_21760;
	BIT_VEC cppVar_21755;
	BIT_VEC cppVar_21750;
	BIT_VEC cppVar_21745;
	BIT_VEC cppVar_21740;
	BIT_VEC cppVar_21735;
	BIT_VEC cppVar_21726;
	BIT_VEC cppVar_21841;
	BIT_VEC cppVar_21720;
	BIT_VEC cppVar_21843;
	BIT_VEC cppVar_21844;
	bool cppVar_21845;
	BIT_VEC cppVar_21846;
	BIT_VEC cppVar_21847;
	bool cppVar_21848;
	bool cppVar_21849;
	BIT_VEC cppVar_21851;
	BIT_VEC cppVar_21852;
	BIT_VEC cppVar_21853;
	BIT_VEC cppVar_21854;
	bool cppVar_21855;
	BIT_VEC cppVar_21857;
	BIT_VEC cppVar_21858;
	BIT_VEC cppVar_21859;
	BIT_VEC cppVar_21860;
	bool cppVar_21861;
	BIT_VEC cppVar_21862;
	BIT_VEC cppVar_21863;
	BIT_VEC cppVar_21864;
	BIT_VEC cppVar_21866;
	BIT_VEC cppVar_21867;
	BIT_VEC cppVar_21868;
	bool cppVar_21869;
	BIT_VEC cppVar_21871;
	BIT_VEC cppVar_21872;
	BIT_VEC cppVar_21873;
	bool cppVar_21874;
	BIT_VEC cppVar_21876;
	BIT_VEC cppVar_21877;
	BIT_VEC cppVar_21878;
	bool cppVar_21879;
	BIT_VEC cppVar_21881;
	BIT_VEC cppVar_21882;
	BIT_VEC cppVar_21883;
	bool cppVar_21884;
	BIT_VEC cppVar_21886;
	BIT_VEC cppVar_21887;
	BIT_VEC cppVar_21888;
	bool cppVar_21889;
	BIT_VEC cppVar_21891;
	BIT_VEC cppVar_21892;
	BIT_VEC cppVar_21893;
	bool cppVar_21894;
	BIT_VEC cppVar_21896;
	BIT_VEC cppVar_21897;
	BIT_VEC cppVar_21898;
	bool cppVar_21899;
	BIT_VEC cppVar_21901;
	BIT_VEC cppVar_21902;
	BIT_VEC cppVar_21903;
	bool cppVar_21904;
	BIT_VEC cppVar_21906;
	BIT_VEC cppVar_21907;
	BIT_VEC cppVar_21908;
	bool cppVar_21909;
	BIT_VEC cppVar_21911;
	BIT_VEC cppVar_21912;
	BIT_VEC cppVar_21913;
	bool cppVar_21914;
	BIT_VEC cppVar_21916;
	BIT_VEC cppVar_21917;
	BIT_VEC cppVar_21918;
	bool cppVar_21919;
	BIT_VEC cppVar_21921;
	BIT_VEC cppVar_21922;
	BIT_VEC cppVar_21923;
	bool cppVar_21924;
	BIT_VEC cppVar_21926;
	BIT_VEC cppVar_21927;
	BIT_VEC cppVar_21928;
	bool cppVar_21929;
	BIT_VEC cppVar_21931;
	BIT_VEC cppVar_21932;
	BIT_VEC cppVar_21933;
	bool cppVar_21934;
	BIT_VEC cppVar_21936;
	BIT_VEC cppVar_21937;
	BIT_VEC cppVar_21938;
	bool cppVar_21939;
	BIT_VEC cppVar_21941;
	BIT_VEC cppVar_21942;
	BIT_VEC cppVar_21943;
	bool cppVar_21944;
	BIT_VEC cppVar_21946;
	BIT_VEC cppVar_21947;
	BIT_VEC cppVar_21948;
	bool cppVar_21949;
	BIT_VEC cppVar_21951;
	BIT_VEC cppVar_21952;
	BIT_VEC cppVar_21953;
	bool cppVar_21954;
	BIT_VEC cppVar_21956;
	BIT_VEC cppVar_21957;
	BIT_VEC cppVar_21958;
	bool cppVar_21959;
	BIT_VEC cppVar_21961;
	BIT_VEC cppVar_21962;
	BIT_VEC cppVar_21963;
	bool cppVar_21964;
	BIT_VEC cppVar_21966;
	BIT_VEC cppVar_21967;
	BIT_VEC cppVar_21968;
	bool cppVar_21969;
	BIT_VEC cppVar_21970;
	BIT_VEC cppVar_21965;
	BIT_VEC cppVar_21960;
	BIT_VEC cppVar_21955;
	BIT_VEC cppVar_21950;
	BIT_VEC cppVar_21945;
	BIT_VEC cppVar_21940;
	BIT_VEC cppVar_21935;
	BIT_VEC cppVar_21930;
	BIT_VEC cppVar_21925;
	BIT_VEC cppVar_21920;
	BIT_VEC cppVar_21915;
	BIT_VEC cppVar_21910;
	BIT_VEC cppVar_21905;
	BIT_VEC cppVar_21900;
	BIT_VEC cppVar_21895;
	BIT_VEC cppVar_21890;
	BIT_VEC cppVar_21885;
	BIT_VEC cppVar_21880;
	BIT_VEC cppVar_21875;
	BIT_VEC cppVar_21870;
	BIT_VEC cppVar_21865;
	BIT_VEC cppVar_21856;
	BIT_VEC cppVar_21971;
	BIT_VEC cppVar_21972;
	BIT_VEC cppVar_21850;
	BIT_VEC cppVar_21974;
	BIT_VEC cppVar_21975;
	bool cppVar_21976;
	BIT_VEC cppVar_21977;
	BIT_VEC cppVar_21978;
	bool cppVar_21979;
	bool cppVar_21980;
	BIT_VEC cppVar_21983;
	BIT_VEC cppVar_21984;
	BIT_VEC cppVar_21985;
	BIT_VEC cppVar_21986;
	BIT_VEC cppVar_21987;
	bool cppVar_21988;
	BIT_VEC cppVar_21989;
	BIT_VEC cppVar_21990;
	BIT_VEC cppVar_21991;
	BIT_VEC cppVar_21992;
	BIT_VEC cppVar_21993;
	BIT_VEC cppVar_21994;
	BIT_VEC cppVar_21995;
	BIT_VEC cppVar_21996;
	BIT_VEC cppVar_21997;
	BIT_VEC cppVar_21998;
	BIT_VEC cppVar_21999;
	BIT_VEC cppVar_21982;
	BIT_VEC cppVar_22000;
	bool cppVar_22001;
	BIT_VEC cppVar_22002;
	BIT_VEC cppVar_22003;
	BIT_VEC cppVar_22004;
	BIT_VEC cppVar_22005;
	BIT_VEC cppVar_22006;
	BIT_VEC cppVar_22007;
	BIT_VEC cppVar_22008;
	BIT_VEC cppVar_22011;
	BIT_VEC cppVar_22012;
	BIT_VEC cppVar_22013;
	bool cppVar_22014;
	BIT_VEC cppVar_22015;
	BIT_VEC cppVar_22016;
	BIT_VEC cppVar_22017;
	BIT_VEC cppVar_22018;
	BIT_VEC cppVar_22019;
	BIT_VEC cppVar_22020;
	BIT_VEC cppVar_22021;
	BIT_VEC cppVar_22022;
	BIT_VEC cppVar_22023;
	BIT_VEC cppVar_22010;
	BIT_VEC cppVar_22024;
	BIT_VEC cppVar_22025;
	bool cppVar_22026;
	BIT_VEC cppVar_22028;
	BIT_VEC cppVar_22029;
	BIT_VEC cppVar_22030;
	bool cppVar_22031;
	BIT_VEC cppVar_22032;
	BIT_VEC cppVar_22033;
	BIT_VEC cppVar_22034;
	BIT_VEC cppVar_22035;
	BIT_VEC cppVar_22036;
	BIT_VEC cppVar_22037;
	BIT_VEC cppVar_22038;
	BIT_VEC cppVar_22039;
	BIT_VEC cppVar_22040;
	BIT_VEC cppVar_22027;
	BIT_VEC cppVar_22041;
	BIT_VEC cppVar_22044;
	BIT_VEC cppVar_22045;
	BIT_VEC cppVar_22046;
	bool cppVar_22047;
	BIT_VEC cppVar_22048;
	BIT_VEC cppVar_22049;
	BIT_VEC cppVar_22050;
	BIT_VEC cppVar_22051;
	BIT_VEC cppVar_22052;
	BIT_VEC cppVar_22053;
	BIT_VEC cppVar_22054;
	BIT_VEC cppVar_22055;
	BIT_VEC cppVar_22056;
	BIT_VEC cppVar_22043;
	BIT_VEC cppVar_22057;
	bool cppVar_22058;
	BIT_VEC cppVar_22061;
	BIT_VEC cppVar_22062;
	BIT_VEC cppVar_22063;
	bool cppVar_22064;
	BIT_VEC cppVar_22065;
	BIT_VEC cppVar_22066;
	BIT_VEC cppVar_22067;
	BIT_VEC cppVar_22068;
	BIT_VEC cppVar_22069;
	BIT_VEC cppVar_22070;
	BIT_VEC cppVar_22071;
	BIT_VEC cppVar_22072;
	BIT_VEC cppVar_22073;
	BIT_VEC cppVar_22060;
	BIT_VEC cppVar_22074;
	bool cppVar_22075;
	BIT_VEC cppVar_22078;
	BIT_VEC cppVar_22079;
	BIT_VEC cppVar_22080;
	bool cppVar_22081;
	BIT_VEC cppVar_22082;
	BIT_VEC cppVar_22083;
	BIT_VEC cppVar_22084;
	BIT_VEC cppVar_22085;
	BIT_VEC cppVar_22086;
	BIT_VEC cppVar_22087;
	BIT_VEC cppVar_22088;
	BIT_VEC cppVar_22089;
	BIT_VEC cppVar_22090;
	BIT_VEC cppVar_22077;
	BIT_VEC cppVar_22091;
	bool cppVar_22092;
	BIT_VEC cppVar_22095;
	BIT_VEC cppVar_22096;
	BIT_VEC cppVar_22097;
	bool cppVar_22098;
	BIT_VEC cppVar_22099;
	BIT_VEC cppVar_22100;
	BIT_VEC cppVar_22101;
	BIT_VEC cppVar_22102;
	BIT_VEC cppVar_22103;
	BIT_VEC cppVar_22104;
	BIT_VEC cppVar_22105;
	BIT_VEC cppVar_22106;
	BIT_VEC cppVar_22107;
	BIT_VEC cppVar_22094;
	BIT_VEC cppVar_22108;
	bool cppVar_22109;
	BIT_VEC cppVar_22112;
	BIT_VEC cppVar_22113;
	BIT_VEC cppVar_22114;
	bool cppVar_22115;
	BIT_VEC cppVar_22116;
	BIT_VEC cppVar_22117;
	BIT_VEC cppVar_22118;
	BIT_VEC cppVar_22119;
	BIT_VEC cppVar_22120;
	BIT_VEC cppVar_22121;
	BIT_VEC cppVar_22122;
	BIT_VEC cppVar_22123;
	BIT_VEC cppVar_22124;
	BIT_VEC cppVar_22111;
	BIT_VEC cppVar_22125;
	bool cppVar_22126;
	BIT_VEC cppVar_22129;
	BIT_VEC cppVar_22130;
	BIT_VEC cppVar_22131;
	bool cppVar_22132;
	BIT_VEC cppVar_22133;
	BIT_VEC cppVar_22134;
	BIT_VEC cppVar_22135;
	BIT_VEC cppVar_22136;
	BIT_VEC cppVar_22137;
	BIT_VEC cppVar_22138;
	BIT_VEC cppVar_22139;
	BIT_VEC cppVar_22140;
	BIT_VEC cppVar_22141;
	BIT_VEC cppVar_22128;
	BIT_VEC cppVar_22142;
	bool cppVar_22143;
	BIT_VEC cppVar_22146;
	BIT_VEC cppVar_22147;
	BIT_VEC cppVar_22148;
	bool cppVar_22149;
	BIT_VEC cppVar_22150;
	BIT_VEC cppVar_22151;
	BIT_VEC cppVar_22152;
	BIT_VEC cppVar_22153;
	BIT_VEC cppVar_22154;
	BIT_VEC cppVar_22155;
	BIT_VEC cppVar_22156;
	BIT_VEC cppVar_22157;
	BIT_VEC cppVar_22158;
	BIT_VEC cppVar_22145;
	BIT_VEC cppVar_22159;
	bool cppVar_22160;
	BIT_VEC cppVar_22163;
	BIT_VEC cppVar_22164;
	BIT_VEC cppVar_22165;
	bool cppVar_22166;
	BIT_VEC cppVar_22167;
	BIT_VEC cppVar_22168;
	BIT_VEC cppVar_22169;
	BIT_VEC cppVar_22170;
	BIT_VEC cppVar_22171;
	BIT_VEC cppVar_22172;
	BIT_VEC cppVar_22173;
	BIT_VEC cppVar_22174;
	BIT_VEC cppVar_22175;
	BIT_VEC cppVar_22162;
	BIT_VEC cppVar_22176;
	bool cppVar_22177;
	BIT_VEC cppVar_22180;
	BIT_VEC cppVar_22181;
	BIT_VEC cppVar_22182;
	bool cppVar_22183;
	BIT_VEC cppVar_22184;
	BIT_VEC cppVar_22185;
	BIT_VEC cppVar_22186;
	BIT_VEC cppVar_22187;
	BIT_VEC cppVar_22188;
	BIT_VEC cppVar_22189;
	BIT_VEC cppVar_22190;
	BIT_VEC cppVar_22191;
	BIT_VEC cppVar_22192;
	BIT_VEC cppVar_22179;
	BIT_VEC cppVar_22193;
	bool cppVar_22194;
	BIT_VEC cppVar_22197;
	BIT_VEC cppVar_22198;
	BIT_VEC cppVar_22199;
	bool cppVar_22200;
	BIT_VEC cppVar_22201;
	BIT_VEC cppVar_22202;
	BIT_VEC cppVar_22203;
	BIT_VEC cppVar_22204;
	BIT_VEC cppVar_22205;
	BIT_VEC cppVar_22206;
	BIT_VEC cppVar_22207;
	BIT_VEC cppVar_22208;
	BIT_VEC cppVar_22209;
	BIT_VEC cppVar_22196;
	BIT_VEC cppVar_22210;
	bool cppVar_22211;
	BIT_VEC cppVar_22214;
	BIT_VEC cppVar_22215;
	BIT_VEC cppVar_22216;
	bool cppVar_22217;
	BIT_VEC cppVar_22218;
	BIT_VEC cppVar_22219;
	BIT_VEC cppVar_22220;
	BIT_VEC cppVar_22221;
	BIT_VEC cppVar_22222;
	BIT_VEC cppVar_22223;
	BIT_VEC cppVar_22224;
	BIT_VEC cppVar_22225;
	BIT_VEC cppVar_22226;
	BIT_VEC cppVar_22213;
	BIT_VEC cppVar_22227;
	bool cppVar_22228;
	BIT_VEC cppVar_22231;
	BIT_VEC cppVar_22232;
	BIT_VEC cppVar_22233;
	bool cppVar_22234;
	BIT_VEC cppVar_22235;
	BIT_VEC cppVar_22236;
	BIT_VEC cppVar_22237;
	BIT_VEC cppVar_22238;
	BIT_VEC cppVar_22239;
	BIT_VEC cppVar_22240;
	BIT_VEC cppVar_22241;
	BIT_VEC cppVar_22242;
	BIT_VEC cppVar_22243;
	BIT_VEC cppVar_22230;
	BIT_VEC cppVar_22244;
	bool cppVar_22245;
	BIT_VEC cppVar_22248;
	BIT_VEC cppVar_22249;
	BIT_VEC cppVar_22250;
	bool cppVar_22251;
	BIT_VEC cppVar_22252;
	BIT_VEC cppVar_22253;
	BIT_VEC cppVar_22254;
	BIT_VEC cppVar_22255;
	BIT_VEC cppVar_22256;
	BIT_VEC cppVar_22257;
	BIT_VEC cppVar_22258;
	BIT_VEC cppVar_22259;
	BIT_VEC cppVar_22260;
	BIT_VEC cppVar_22247;
	BIT_VEC cppVar_22261;
	bool cppVar_22262;
	BIT_VEC cppVar_22265;
	BIT_VEC cppVar_22266;
	BIT_VEC cppVar_22267;
	bool cppVar_22268;
	BIT_VEC cppVar_22269;
	BIT_VEC cppVar_22270;
	BIT_VEC cppVar_22271;
	BIT_VEC cppVar_22272;
	BIT_VEC cppVar_22273;
	BIT_VEC cppVar_22274;
	BIT_VEC cppVar_22275;
	BIT_VEC cppVar_22276;
	BIT_VEC cppVar_22277;
	BIT_VEC cppVar_22264;
	BIT_VEC cppVar_22278;
	bool cppVar_22279;
	BIT_VEC cppVar_22282;
	BIT_VEC cppVar_22283;
	BIT_VEC cppVar_22284;
	bool cppVar_22285;
	BIT_VEC cppVar_22286;
	BIT_VEC cppVar_22287;
	BIT_VEC cppVar_22288;
	BIT_VEC cppVar_22289;
	BIT_VEC cppVar_22290;
	BIT_VEC cppVar_22291;
	BIT_VEC cppVar_22292;
	BIT_VEC cppVar_22293;
	BIT_VEC cppVar_22294;
	BIT_VEC cppVar_22281;
	BIT_VEC cppVar_22295;
	bool cppVar_22296;
	BIT_VEC cppVar_22299;
	BIT_VEC cppVar_22300;
	BIT_VEC cppVar_22301;
	bool cppVar_22302;
	BIT_VEC cppVar_22303;
	BIT_VEC cppVar_22304;
	BIT_VEC cppVar_22305;
	BIT_VEC cppVar_22306;
	BIT_VEC cppVar_22307;
	BIT_VEC cppVar_22308;
	BIT_VEC cppVar_22309;
	BIT_VEC cppVar_22310;
	BIT_VEC cppVar_22311;
	BIT_VEC cppVar_22298;
	BIT_VEC cppVar_22312;
	bool cppVar_22313;
	BIT_VEC cppVar_22316;
	BIT_VEC cppVar_22317;
	BIT_VEC cppVar_22318;
	bool cppVar_22319;
	BIT_VEC cppVar_22320;
	BIT_VEC cppVar_22321;
	BIT_VEC cppVar_22322;
	BIT_VEC cppVar_22323;
	BIT_VEC cppVar_22324;
	BIT_VEC cppVar_22325;
	BIT_VEC cppVar_22326;
	BIT_VEC cppVar_22327;
	BIT_VEC cppVar_22328;
	BIT_VEC cppVar_22315;
	BIT_VEC cppVar_22329;
	bool cppVar_22330;
	BIT_VEC cppVar_22333;
	BIT_VEC cppVar_22334;
	BIT_VEC cppVar_22335;
	bool cppVar_22336;
	BIT_VEC cppVar_22337;
	BIT_VEC cppVar_22338;
	BIT_VEC cppVar_22339;
	BIT_VEC cppVar_22340;
	BIT_VEC cppVar_22341;
	BIT_VEC cppVar_22342;
	BIT_VEC cppVar_22343;
	BIT_VEC cppVar_22344;
	BIT_VEC cppVar_22345;
	BIT_VEC cppVar_22332;
	BIT_VEC cppVar_22346;
	bool cppVar_22347;
	BIT_VEC cppVar_22350;
	BIT_VEC cppVar_22351;
	BIT_VEC cppVar_22352;
	bool cppVar_22353;
	BIT_VEC cppVar_22354;
	BIT_VEC cppVar_22355;
	BIT_VEC cppVar_22356;
	BIT_VEC cppVar_22357;
	BIT_VEC cppVar_22358;
	BIT_VEC cppVar_22359;
	BIT_VEC cppVar_22360;
	BIT_VEC cppVar_22361;
	BIT_VEC cppVar_22362;
	BIT_VEC cppVar_22349;
	BIT_VEC cppVar_22363;
	bool cppVar_22364;
	BIT_VEC cppVar_22367;
	BIT_VEC cppVar_22368;
	BIT_VEC cppVar_22369;
	bool cppVar_22370;
	BIT_VEC cppVar_22371;
	BIT_VEC cppVar_22372;
	BIT_VEC cppVar_22373;
	BIT_VEC cppVar_22374;
	BIT_VEC cppVar_22375;
	BIT_VEC cppVar_22376;
	BIT_VEC cppVar_22377;
	BIT_VEC cppVar_22378;
	BIT_VEC cppVar_22379;
	BIT_VEC cppVar_22366;
	BIT_VEC cppVar_22380;
	bool cppVar_22381;
	BIT_VEC cppVar_22384;
	BIT_VEC cppVar_22385;
	BIT_VEC cppVar_22386;
	bool cppVar_22387;
	BIT_VEC cppVar_22388;
	BIT_VEC cppVar_22389;
	BIT_VEC cppVar_22390;
	BIT_VEC cppVar_22391;
	BIT_VEC cppVar_22392;
	BIT_VEC cppVar_22393;
	BIT_VEC cppVar_22394;
	BIT_VEC cppVar_22395;
	BIT_VEC cppVar_22396;
	BIT_VEC cppVar_22383;
	BIT_VEC cppVar_22397;
	bool cppVar_22398;
	BIT_VEC cppVar_22399;
	BIT_VEC cppVar_22382;
	BIT_VEC cppVar_22365;
	BIT_VEC cppVar_22348;
	BIT_VEC cppVar_22331;
	BIT_VEC cppVar_22314;
	BIT_VEC cppVar_22297;
	BIT_VEC cppVar_22280;
	BIT_VEC cppVar_22263;
	BIT_VEC cppVar_22246;
	BIT_VEC cppVar_22229;
	BIT_VEC cppVar_22212;
	BIT_VEC cppVar_22195;
	BIT_VEC cppVar_22178;
	BIT_VEC cppVar_22161;
	BIT_VEC cppVar_22144;
	BIT_VEC cppVar_22127;
	BIT_VEC cppVar_22110;
	BIT_VEC cppVar_22093;
	BIT_VEC cppVar_22076;
	BIT_VEC cppVar_22059;
	BIT_VEC cppVar_22042;
	BIT_VEC cppVar_22009;
	BIT_VEC cppVar_22400;
	BIT_VEC cppVar_22401;
	BIT_VEC cppVar_22402;
	BIT_VEC cppVar_22403;
	BIT_VEC cppVar_22404;
	BIT_VEC cppVar_22405;
	BIT_VEC cppVar_22406;
	BIT_VEC cppVar_22407;
	BIT_VEC cppVar_22408;
	BIT_VEC cppVar_21981;
	BIT_VEC cppVar_22410;
	BIT_VEC cppVar_22411;
	bool cppVar_22412;
	BIT_VEC cppVar_22414;
	BIT_VEC cppVar_22415;
	BIT_VEC cppVar_22416;
	BIT_VEC cppVar_22417;
	bool cppVar_22418;
	BIT_VEC cppVar_22420;
	BIT_VEC cppVar_22421;
	BIT_VEC cppVar_22422;
	BIT_VEC cppVar_22423;
	bool cppVar_22424;
	BIT_VEC cppVar_22425;
	BIT_VEC cppVar_22426;
	BIT_VEC cppVar_22427;
	BIT_VEC cppVar_22429;
	BIT_VEC cppVar_22430;
	BIT_VEC cppVar_22431;
	bool cppVar_22432;
	BIT_VEC cppVar_22434;
	BIT_VEC cppVar_22435;
	BIT_VEC cppVar_22436;
	bool cppVar_22437;
	BIT_VEC cppVar_22439;
	BIT_VEC cppVar_22440;
	BIT_VEC cppVar_22441;
	bool cppVar_22442;
	BIT_VEC cppVar_22444;
	BIT_VEC cppVar_22445;
	BIT_VEC cppVar_22446;
	bool cppVar_22447;
	BIT_VEC cppVar_22449;
	BIT_VEC cppVar_22450;
	BIT_VEC cppVar_22451;
	bool cppVar_22452;
	BIT_VEC cppVar_22454;
	BIT_VEC cppVar_22455;
	BIT_VEC cppVar_22456;
	bool cppVar_22457;
	BIT_VEC cppVar_22459;
	BIT_VEC cppVar_22460;
	BIT_VEC cppVar_22461;
	bool cppVar_22462;
	BIT_VEC cppVar_22464;
	BIT_VEC cppVar_22465;
	BIT_VEC cppVar_22466;
	bool cppVar_22467;
	BIT_VEC cppVar_22469;
	BIT_VEC cppVar_22470;
	BIT_VEC cppVar_22471;
	bool cppVar_22472;
	BIT_VEC cppVar_22474;
	BIT_VEC cppVar_22475;
	BIT_VEC cppVar_22476;
	bool cppVar_22477;
	BIT_VEC cppVar_22479;
	BIT_VEC cppVar_22480;
	BIT_VEC cppVar_22481;
	bool cppVar_22482;
	BIT_VEC cppVar_22484;
	BIT_VEC cppVar_22485;
	BIT_VEC cppVar_22486;
	bool cppVar_22487;
	BIT_VEC cppVar_22489;
	BIT_VEC cppVar_22490;
	BIT_VEC cppVar_22491;
	bool cppVar_22492;
	BIT_VEC cppVar_22494;
	BIT_VEC cppVar_22495;
	BIT_VEC cppVar_22496;
	bool cppVar_22497;
	BIT_VEC cppVar_22499;
	BIT_VEC cppVar_22500;
	BIT_VEC cppVar_22501;
	bool cppVar_22502;
	BIT_VEC cppVar_22504;
	BIT_VEC cppVar_22505;
	BIT_VEC cppVar_22506;
	bool cppVar_22507;
	BIT_VEC cppVar_22509;
	BIT_VEC cppVar_22510;
	BIT_VEC cppVar_22511;
	bool cppVar_22512;
	BIT_VEC cppVar_22514;
	BIT_VEC cppVar_22515;
	BIT_VEC cppVar_22516;
	bool cppVar_22517;
	BIT_VEC cppVar_22519;
	BIT_VEC cppVar_22520;
	BIT_VEC cppVar_22521;
	bool cppVar_22522;
	BIT_VEC cppVar_22524;
	BIT_VEC cppVar_22525;
	BIT_VEC cppVar_22526;
	bool cppVar_22527;
	BIT_VEC cppVar_22529;
	BIT_VEC cppVar_22530;
	BIT_VEC cppVar_22531;
	bool cppVar_22532;
	BIT_VEC cppVar_22533;
	BIT_VEC cppVar_22528;
	BIT_VEC cppVar_22523;
	BIT_VEC cppVar_22518;
	BIT_VEC cppVar_22513;
	BIT_VEC cppVar_22508;
	BIT_VEC cppVar_22503;
	BIT_VEC cppVar_22498;
	BIT_VEC cppVar_22493;
	BIT_VEC cppVar_22488;
	BIT_VEC cppVar_22483;
	BIT_VEC cppVar_22478;
	BIT_VEC cppVar_22473;
	BIT_VEC cppVar_22468;
	BIT_VEC cppVar_22463;
	BIT_VEC cppVar_22458;
	BIT_VEC cppVar_22453;
	BIT_VEC cppVar_22448;
	BIT_VEC cppVar_22443;
	BIT_VEC cppVar_22438;
	BIT_VEC cppVar_22433;
	BIT_VEC cppVar_22428;
	BIT_VEC cppVar_22419;
	BIT_VEC cppVar_22534;
	BIT_VEC cppVar_22535;
	BIT_VEC cppVar_22413;
	BIT_VEC cppVar_22409;
	BIT_VEC cppVar_21973;
	BIT_VEC cppVar_21842;
	BIT_VEC cppVar_21716;
	BIT_VEC cppVar_21587;
	BIT_VEC cppVar_21461;
	BIT_VEC cppVar_21332;
	BIT_VEC cppVar_21206;
	BIT_VEC cppVar_21077;
	BIT_VEC cppVar_21064;
	BIT_VEC cppVar_20938;
	BIT_VEC cppVar_20921;
	BIT_VEC cppVar_20904;
	BIT_VEC cppVar_20754;
	BIT_VEC cppVar_20604;
	BIT_VEC cppVar_20454;
	BIT_VEC cppVar_20304;
	BIT_VEC cppVar_20154;
	BIT_VEC cppVar_20004;
	BIT_VEC cppVar_19854;
	BIT_VEC cppVar_19704;
	BIT_VEC cppVar_19272;
	BIT_VEC cppVar_18442;
	BIT_VEC cppVar_18428;
	BIT_VEC cppVar_18417;
	BIT_VEC cppVar_17985;
	cppVar_17986 = ROM.rd(PC);
	cppVar_17988 = (cppVar_17986 == 210);
	if (cppVar_17988) {
	cppVar_17992 = PC + 1;
	cppVar_17992 = (cppVar_17992 & cppMask_un_16_);
	cppVar_17993 = ROM.rd(cppVar_17992);
	cppVar_17994 = (cppVar_17993 >> 7) & cppMask_un_1_;
	cppVar_17996 = (cppVar_17994 == 1);
	if (cppVar_17996) {
	cppVar_17997 = PC + 1;
	cppVar_17997 = (cppVar_17997 & cppMask_un_16_);
	cppVar_17998 = ROM.rd(cppVar_17997);
	cppVar_17999 = (cppVar_17998 >> 3) & cppMask_un_5_;
	cppVar_18001 = (cppVar_17999 << 3) | 0;
	cppVar_18001 = (cppVar_18001 & cppMask_un_8_);
	cppVar_17990 = cppVar_18001;
	} else {
	cppVar_18002 = PC + 1;
	cppVar_18002 = (cppVar_18002 & cppMask_un_16_);
	cppVar_18003 = ROM.rd(cppVar_18002);
	cppVar_18004 = (cppVar_18003 >> 3) & cppMask_un_5_;
	cppVar_18005 = (cppVar_18004 & cppMask_un_5_);
	cppVar_18007 = cppVar_18005 + 32;
	cppVar_18007 = (cppVar_18007 & cppMask_un_8_);
	cppVar_17990 = cppVar_18007;
	}
	cppVar_18009 = (cppVar_17990 == 184);
	if (cppVar_18009) {
	cppVar_18011 = PC + 1;
	cppVar_18011 = (cppVar_18011 & cppMask_un_16_);
	cppVar_18012 = ROM.rd(cppVar_18011);
	cppVar_18013 = (cppVar_18012 >> 0) & cppMask_un_3_;
	cppVar_18014 = (cppVar_18013 & cppMask_un_3_);
	cppVar_18015 = 1 << static_cast<unsigned>(cppVar_18014);
	cppVar_18015 = (cppVar_18015 & cppMask_un_8_);
	cppVar_18016 = ~cppVar_18015;
	cppVar_18019 = PC + 1;
	cppVar_18019 = (cppVar_18019 & cppMask_un_16_);
	cppVar_18020 = ROM.rd(cppVar_18019);
	cppVar_18021 = (cppVar_18020 >> 7) & cppMask_un_1_;
	cppVar_18022 = (cppVar_18021 == 1);
	if (cppVar_18022) {
	cppVar_18023 = PC + 1;
	cppVar_18023 = (cppVar_18023 & cppMask_un_16_);
	cppVar_18024 = ROM.rd(cppVar_18023);
	cppVar_18025 = (cppVar_18024 >> 3) & cppMask_un_5_;
	cppVar_18026 = (cppVar_18025 << 3) | 0;
	cppVar_18026 = (cppVar_18026 & cppMask_un_8_);
	cppVar_18018 = cppVar_18026;
	} else {
	cppVar_18027 = PC + 1;
	cppVar_18027 = (cppVar_18027 & cppMask_un_16_);
	cppVar_18028 = ROM.rd(cppVar_18027);
	cppVar_18029 = (cppVar_18028 >> 3) & cppMask_un_5_;
	cppVar_18030 = (cppVar_18029 & cppMask_un_5_);
	cppVar_18031 = cppVar_18030 + 32;
	cppVar_18031 = (cppVar_18031 & cppMask_un_8_);
	cppVar_18018 = cppVar_18031;
	}
	cppVar_18032 = (cppVar_18018 >> 7) & cppMask_un_1_;
	cppVar_18034 = (cppVar_18032 == 0);
	if (cppVar_18034) {
	cppVar_18036 = PC + 1;
	cppVar_18036 = (cppVar_18036 & cppMask_un_16_);
	cppVar_18037 = ROM.rd(cppVar_18036);
	cppVar_18038 = (cppVar_18037 >> 7) & cppMask_un_1_;
	cppVar_18039 = (cppVar_18038 == 1);
	if (cppVar_18039) {
	cppVar_18040 = PC + 1;
	cppVar_18040 = (cppVar_18040 & cppMask_un_16_);
	cppVar_18041 = ROM.rd(cppVar_18040);
	cppVar_18042 = (cppVar_18041 >> 3) & cppMask_un_5_;
	cppVar_18043 = (cppVar_18042 << 3) | 0;
	cppVar_18043 = (cppVar_18043 & cppMask_un_8_);
	cppVar_18035 = cppVar_18043;
	} else {
	cppVar_18044 = PC + 1;
	cppVar_18044 = (cppVar_18044 & cppMask_un_16_);
	cppVar_18045 = ROM.rd(cppVar_18044);
	cppVar_18046 = (cppVar_18045 >> 3) & cppMask_un_5_;
	cppVar_18047 = (cppVar_18046 & cppMask_un_5_);
	cppVar_18048 = cppVar_18047 + 32;
	cppVar_18048 = (cppVar_18048 & cppMask_un_8_);
	cppVar_18035 = cppVar_18048;
	}
	cppVar_18049 = IRAM.rd(cppVar_18035);
	cppVar_18017 = cppVar_18049;
	} else {
	cppVar_18052 = PC + 1;
	cppVar_18052 = (cppVar_18052 & cppMask_un_16_);
	cppVar_18053 = ROM.rd(cppVar_18052);
	cppVar_18054 = (cppVar_18053 >> 7) & cppMask_un_1_;
	cppVar_18055 = (cppVar_18054 == 1);
	if (cppVar_18055) {
	cppVar_18056 = PC + 1;
	cppVar_18056 = (cppVar_18056 & cppMask_un_16_);
	cppVar_18057 = ROM.rd(cppVar_18056);
	cppVar_18058 = (cppVar_18057 >> 3) & cppMask_un_5_;
	cppVar_18059 = (cppVar_18058 << 3) | 0;
	cppVar_18059 = (cppVar_18059 & cppMask_un_8_);
	cppVar_18051 = cppVar_18059;
	} else {
	cppVar_18060 = PC + 1;
	cppVar_18060 = (cppVar_18060 & cppMask_un_16_);
	cppVar_18061 = ROM.rd(cppVar_18060);
	cppVar_18062 = (cppVar_18061 >> 3) & cppMask_un_5_;
	cppVar_18063 = (cppVar_18062 & cppMask_un_5_);
	cppVar_18064 = cppVar_18063 + 32;
	cppVar_18064 = (cppVar_18064 & cppMask_un_8_);
	cppVar_18051 = cppVar_18064;
	}
	cppVar_18066 = (cppVar_18051 == 128);
	if (cppVar_18066) {
	cppVar_18050 = P0;
	} else {
	cppVar_18069 = PC + 1;
	cppVar_18069 = (cppVar_18069 & cppMask_un_16_);
	cppVar_18070 = ROM.rd(cppVar_18069);
	cppVar_18071 = (cppVar_18070 >> 7) & cppMask_un_1_;
	cppVar_18072 = (cppVar_18071 == 1);
	if (cppVar_18072) {
	cppVar_18073 = PC + 1;
	cppVar_18073 = (cppVar_18073 & cppMask_un_16_);
	cppVar_18074 = ROM.rd(cppVar_18073);
	cppVar_18075 = (cppVar_18074 >> 3) & cppMask_un_5_;
	cppVar_18076 = (cppVar_18075 << 3) | 0;
	cppVar_18076 = (cppVar_18076 & cppMask_un_8_);
	cppVar_18068 = cppVar_18076;
	} else {
	cppVar_18077 = PC + 1;
	cppVar_18077 = (cppVar_18077 & cppMask_un_16_);
	cppVar_18078 = ROM.rd(cppVar_18077);
	cppVar_18079 = (cppVar_18078 >> 3) & cppMask_un_5_;
	cppVar_18080 = (cppVar_18079 & cppMask_un_5_);
	cppVar_18081 = cppVar_18080 + 32;
	cppVar_18081 = (cppVar_18081 & cppMask_un_8_);
	cppVar_18068 = cppVar_18081;
	}
	cppVar_18083 = (cppVar_18068 == 129);
	if (cppVar_18083) {
	cppVar_18067 = SP;
	} else {
	cppVar_18086 = PC + 1;
	cppVar_18086 = (cppVar_18086 & cppMask_un_16_);
	cppVar_18087 = ROM.rd(cppVar_18086);
	cppVar_18088 = (cppVar_18087 >> 7) & cppMask_un_1_;
	cppVar_18089 = (cppVar_18088 == 1);
	if (cppVar_18089) {
	cppVar_18090 = PC + 1;
	cppVar_18090 = (cppVar_18090 & cppMask_un_16_);
	cppVar_18091 = ROM.rd(cppVar_18090);
	cppVar_18092 = (cppVar_18091 >> 3) & cppMask_un_5_;
	cppVar_18093 = (cppVar_18092 << 3) | 0;
	cppVar_18093 = (cppVar_18093 & cppMask_un_8_);
	cppVar_18085 = cppVar_18093;
	} else {
	cppVar_18094 = PC + 1;
	cppVar_18094 = (cppVar_18094 & cppMask_un_16_);
	cppVar_18095 = ROM.rd(cppVar_18094);
	cppVar_18096 = (cppVar_18095 >> 3) & cppMask_un_5_;
	cppVar_18097 = (cppVar_18096 & cppMask_un_5_);
	cppVar_18098 = cppVar_18097 + 32;
	cppVar_18098 = (cppVar_18098 & cppMask_un_8_);
	cppVar_18085 = cppVar_18098;
	}
	cppVar_18100 = (cppVar_18085 == 130);
	if (cppVar_18100) {
	cppVar_18084 = DPL;
	} else {
	cppVar_18103 = PC + 1;
	cppVar_18103 = (cppVar_18103 & cppMask_un_16_);
	cppVar_18104 = ROM.rd(cppVar_18103);
	cppVar_18105 = (cppVar_18104 >> 7) & cppMask_un_1_;
	cppVar_18106 = (cppVar_18105 == 1);
	if (cppVar_18106) {
	cppVar_18107 = PC + 1;
	cppVar_18107 = (cppVar_18107 & cppMask_un_16_);
	cppVar_18108 = ROM.rd(cppVar_18107);
	cppVar_18109 = (cppVar_18108 >> 3) & cppMask_un_5_;
	cppVar_18110 = (cppVar_18109 << 3) | 0;
	cppVar_18110 = (cppVar_18110 & cppMask_un_8_);
	cppVar_18102 = cppVar_18110;
	} else {
	cppVar_18111 = PC + 1;
	cppVar_18111 = (cppVar_18111 & cppMask_un_16_);
	cppVar_18112 = ROM.rd(cppVar_18111);
	cppVar_18113 = (cppVar_18112 >> 3) & cppMask_un_5_;
	cppVar_18114 = (cppVar_18113 & cppMask_un_5_);
	cppVar_18115 = cppVar_18114 + 32;
	cppVar_18115 = (cppVar_18115 & cppMask_un_8_);
	cppVar_18102 = cppVar_18115;
	}
	cppVar_18117 = (cppVar_18102 == 131);
	if (cppVar_18117) {
	cppVar_18101 = DPH;
	} else {
	cppVar_18120 = PC + 1;
	cppVar_18120 = (cppVar_18120 & cppMask_un_16_);
	cppVar_18121 = ROM.rd(cppVar_18120);
	cppVar_18122 = (cppVar_18121 >> 7) & cppMask_un_1_;
	cppVar_18123 = (cppVar_18122 == 1);
	if (cppVar_18123) {
	cppVar_18124 = PC + 1;
	cppVar_18124 = (cppVar_18124 & cppMask_un_16_);
	cppVar_18125 = ROM.rd(cppVar_18124);
	cppVar_18126 = (cppVar_18125 >> 3) & cppMask_un_5_;
	cppVar_18127 = (cppVar_18126 << 3) | 0;
	cppVar_18127 = (cppVar_18127 & cppMask_un_8_);
	cppVar_18119 = cppVar_18127;
	} else {
	cppVar_18128 = PC + 1;
	cppVar_18128 = (cppVar_18128 & cppMask_un_16_);
	cppVar_18129 = ROM.rd(cppVar_18128);
	cppVar_18130 = (cppVar_18129 >> 3) & cppMask_un_5_;
	cppVar_18131 = (cppVar_18130 & cppMask_un_5_);
	cppVar_18132 = cppVar_18131 + 32;
	cppVar_18132 = (cppVar_18132 & cppMask_un_8_);
	cppVar_18119 = cppVar_18132;
	}
	cppVar_18134 = (cppVar_18119 == 135);
	if (cppVar_18134) {
	cppVar_18118 = PCON;
	} else {
	cppVar_18137 = PC + 1;
	cppVar_18137 = (cppVar_18137 & cppMask_un_16_);
	cppVar_18138 = ROM.rd(cppVar_18137);
	cppVar_18139 = (cppVar_18138 >> 7) & cppMask_un_1_;
	cppVar_18140 = (cppVar_18139 == 1);
	if (cppVar_18140) {
	cppVar_18141 = PC + 1;
	cppVar_18141 = (cppVar_18141 & cppMask_un_16_);
	cppVar_18142 = ROM.rd(cppVar_18141);
	cppVar_18143 = (cppVar_18142 >> 3) & cppMask_un_5_;
	cppVar_18144 = (cppVar_18143 << 3) | 0;
	cppVar_18144 = (cppVar_18144 & cppMask_un_8_);
	cppVar_18136 = cppVar_18144;
	} else {
	cppVar_18145 = PC + 1;
	cppVar_18145 = (cppVar_18145 & cppMask_un_16_);
	cppVar_18146 = ROM.rd(cppVar_18145);
	cppVar_18147 = (cppVar_18146 >> 3) & cppMask_un_5_;
	cppVar_18148 = (cppVar_18147 & cppMask_un_5_);
	cppVar_18149 = cppVar_18148 + 32;
	cppVar_18149 = (cppVar_18149 & cppMask_un_8_);
	cppVar_18136 = cppVar_18149;
	}
	cppVar_18151 = (cppVar_18136 == 136);
	if (cppVar_18151) {
	cppVar_18135 = TCON;
	} else {
	cppVar_18154 = PC + 1;
	cppVar_18154 = (cppVar_18154 & cppMask_un_16_);
	cppVar_18155 = ROM.rd(cppVar_18154);
	cppVar_18156 = (cppVar_18155 >> 7) & cppMask_un_1_;
	cppVar_18157 = (cppVar_18156 == 1);
	if (cppVar_18157) {
	cppVar_18158 = PC + 1;
	cppVar_18158 = (cppVar_18158 & cppMask_un_16_);
	cppVar_18159 = ROM.rd(cppVar_18158);
	cppVar_18160 = (cppVar_18159 >> 3) & cppMask_un_5_;
	cppVar_18161 = (cppVar_18160 << 3) | 0;
	cppVar_18161 = (cppVar_18161 & cppMask_un_8_);
	cppVar_18153 = cppVar_18161;
	} else {
	cppVar_18162 = PC + 1;
	cppVar_18162 = (cppVar_18162 & cppMask_un_16_);
	cppVar_18163 = ROM.rd(cppVar_18162);
	cppVar_18164 = (cppVar_18163 >> 3) & cppMask_un_5_;
	cppVar_18165 = (cppVar_18164 & cppMask_un_5_);
	cppVar_18166 = cppVar_18165 + 32;
	cppVar_18166 = (cppVar_18166 & cppMask_un_8_);
	cppVar_18153 = cppVar_18166;
	}
	cppVar_18168 = (cppVar_18153 == 137);
	if (cppVar_18168) {
	cppVar_18152 = TMOD;
	} else {
	cppVar_18171 = PC + 1;
	cppVar_18171 = (cppVar_18171 & cppMask_un_16_);
	cppVar_18172 = ROM.rd(cppVar_18171);
	cppVar_18173 = (cppVar_18172 >> 7) & cppMask_un_1_;
	cppVar_18174 = (cppVar_18173 == 1);
	if (cppVar_18174) {
	cppVar_18175 = PC + 1;
	cppVar_18175 = (cppVar_18175 & cppMask_un_16_);
	cppVar_18176 = ROM.rd(cppVar_18175);
	cppVar_18177 = (cppVar_18176 >> 3) & cppMask_un_5_;
	cppVar_18178 = (cppVar_18177 << 3) | 0;
	cppVar_18178 = (cppVar_18178 & cppMask_un_8_);
	cppVar_18170 = cppVar_18178;
	} else {
	cppVar_18179 = PC + 1;
	cppVar_18179 = (cppVar_18179 & cppMask_un_16_);
	cppVar_18180 = ROM.rd(cppVar_18179);
	cppVar_18181 = (cppVar_18180 >> 3) & cppMask_un_5_;
	cppVar_18182 = (cppVar_18181 & cppMask_un_5_);
	cppVar_18183 = cppVar_18182 + 32;
	cppVar_18183 = (cppVar_18183 & cppMask_un_8_);
	cppVar_18170 = cppVar_18183;
	}
	cppVar_18185 = (cppVar_18170 == 138);
	if (cppVar_18185) {
	cppVar_18169 = TL0;
	} else {
	cppVar_18188 = PC + 1;
	cppVar_18188 = (cppVar_18188 & cppMask_un_16_);
	cppVar_18189 = ROM.rd(cppVar_18188);
	cppVar_18190 = (cppVar_18189 >> 7) & cppMask_un_1_;
	cppVar_18191 = (cppVar_18190 == 1);
	if (cppVar_18191) {
	cppVar_18192 = PC + 1;
	cppVar_18192 = (cppVar_18192 & cppMask_un_16_);
	cppVar_18193 = ROM.rd(cppVar_18192);
	cppVar_18194 = (cppVar_18193 >> 3) & cppMask_un_5_;
	cppVar_18195 = (cppVar_18194 << 3) | 0;
	cppVar_18195 = (cppVar_18195 & cppMask_un_8_);
	cppVar_18187 = cppVar_18195;
	} else {
	cppVar_18196 = PC + 1;
	cppVar_18196 = (cppVar_18196 & cppMask_un_16_);
	cppVar_18197 = ROM.rd(cppVar_18196);
	cppVar_18198 = (cppVar_18197 >> 3) & cppMask_un_5_;
	cppVar_18199 = (cppVar_18198 & cppMask_un_5_);
	cppVar_18200 = cppVar_18199 + 32;
	cppVar_18200 = (cppVar_18200 & cppMask_un_8_);
	cppVar_18187 = cppVar_18200;
	}
	cppVar_18202 = (cppVar_18187 == 140);
	if (cppVar_18202) {
	cppVar_18186 = TH0;
	} else {
	cppVar_18205 = PC + 1;
	cppVar_18205 = (cppVar_18205 & cppMask_un_16_);
	cppVar_18206 = ROM.rd(cppVar_18205);
	cppVar_18207 = (cppVar_18206 >> 7) & cppMask_un_1_;
	cppVar_18208 = (cppVar_18207 == 1);
	if (cppVar_18208) {
	cppVar_18209 = PC + 1;
	cppVar_18209 = (cppVar_18209 & cppMask_un_16_);
	cppVar_18210 = ROM.rd(cppVar_18209);
	cppVar_18211 = (cppVar_18210 >> 3) & cppMask_un_5_;
	cppVar_18212 = (cppVar_18211 << 3) | 0;
	cppVar_18212 = (cppVar_18212 & cppMask_un_8_);
	cppVar_18204 = cppVar_18212;
	} else {
	cppVar_18213 = PC + 1;
	cppVar_18213 = (cppVar_18213 & cppMask_un_16_);
	cppVar_18214 = ROM.rd(cppVar_18213);
	cppVar_18215 = (cppVar_18214 >> 3) & cppMask_un_5_;
	cppVar_18216 = (cppVar_18215 & cppMask_un_5_);
	cppVar_18217 = cppVar_18216 + 32;
	cppVar_18217 = (cppVar_18217 & cppMask_un_8_);
	cppVar_18204 = cppVar_18217;
	}
	cppVar_18219 = (cppVar_18204 == 139);
	if (cppVar_18219) {
	cppVar_18203 = TL1;
	} else {
	cppVar_18222 = PC + 1;
	cppVar_18222 = (cppVar_18222 & cppMask_un_16_);
	cppVar_18223 = ROM.rd(cppVar_18222);
	cppVar_18224 = (cppVar_18223 >> 7) & cppMask_un_1_;
	cppVar_18225 = (cppVar_18224 == 1);
	if (cppVar_18225) {
	cppVar_18226 = PC + 1;
	cppVar_18226 = (cppVar_18226 & cppMask_un_16_);
	cppVar_18227 = ROM.rd(cppVar_18226);
	cppVar_18228 = (cppVar_18227 >> 3) & cppMask_un_5_;
	cppVar_18229 = (cppVar_18228 << 3) | 0;
	cppVar_18229 = (cppVar_18229 & cppMask_un_8_);
	cppVar_18221 = cppVar_18229;
	} else {
	cppVar_18230 = PC + 1;
	cppVar_18230 = (cppVar_18230 & cppMask_un_16_);
	cppVar_18231 = ROM.rd(cppVar_18230);
	cppVar_18232 = (cppVar_18231 >> 3) & cppMask_un_5_;
	cppVar_18233 = (cppVar_18232 & cppMask_un_5_);
	cppVar_18234 = cppVar_18233 + 32;
	cppVar_18234 = (cppVar_18234 & cppMask_un_8_);
	cppVar_18221 = cppVar_18234;
	}
	cppVar_18236 = (cppVar_18221 == 141);
	if (cppVar_18236) {
	cppVar_18220 = TH1;
	} else {
	cppVar_18239 = PC + 1;
	cppVar_18239 = (cppVar_18239 & cppMask_un_16_);
	cppVar_18240 = ROM.rd(cppVar_18239);
	cppVar_18241 = (cppVar_18240 >> 7) & cppMask_un_1_;
	cppVar_18242 = (cppVar_18241 == 1);
	if (cppVar_18242) {
	cppVar_18243 = PC + 1;
	cppVar_18243 = (cppVar_18243 & cppMask_un_16_);
	cppVar_18244 = ROM.rd(cppVar_18243);
	cppVar_18245 = (cppVar_18244 >> 3) & cppMask_un_5_;
	cppVar_18246 = (cppVar_18245 << 3) | 0;
	cppVar_18246 = (cppVar_18246 & cppMask_un_8_);
	cppVar_18238 = cppVar_18246;
	} else {
	cppVar_18247 = PC + 1;
	cppVar_18247 = (cppVar_18247 & cppMask_un_16_);
	cppVar_18248 = ROM.rd(cppVar_18247);
	cppVar_18249 = (cppVar_18248 >> 3) & cppMask_un_5_;
	cppVar_18250 = (cppVar_18249 & cppMask_un_5_);
	cppVar_18251 = cppVar_18250 + 32;
	cppVar_18251 = (cppVar_18251 & cppMask_un_8_);
	cppVar_18238 = cppVar_18251;
	}
	cppVar_18253 = (cppVar_18238 == 144);
	if (cppVar_18253) {
	cppVar_18237 = P1;
	} else {
	cppVar_18256 = PC + 1;
	cppVar_18256 = (cppVar_18256 & cppMask_un_16_);
	cppVar_18257 = ROM.rd(cppVar_18256);
	cppVar_18258 = (cppVar_18257 >> 7) & cppMask_un_1_;
	cppVar_18259 = (cppVar_18258 == 1);
	if (cppVar_18259) {
	cppVar_18260 = PC + 1;
	cppVar_18260 = (cppVar_18260 & cppMask_un_16_);
	cppVar_18261 = ROM.rd(cppVar_18260);
	cppVar_18262 = (cppVar_18261 >> 3) & cppMask_un_5_;
	cppVar_18263 = (cppVar_18262 << 3) | 0;
	cppVar_18263 = (cppVar_18263 & cppMask_un_8_);
	cppVar_18255 = cppVar_18263;
	} else {
	cppVar_18264 = PC + 1;
	cppVar_18264 = (cppVar_18264 & cppMask_un_16_);
	cppVar_18265 = ROM.rd(cppVar_18264);
	cppVar_18266 = (cppVar_18265 >> 3) & cppMask_un_5_;
	cppVar_18267 = (cppVar_18266 & cppMask_un_5_);
	cppVar_18268 = cppVar_18267 + 32;
	cppVar_18268 = (cppVar_18268 & cppMask_un_8_);
	cppVar_18255 = cppVar_18268;
	}
	cppVar_18270 = (cppVar_18255 == 152);
	if (cppVar_18270) {
	cppVar_18254 = SCON;
	} else {
	cppVar_18273 = PC + 1;
	cppVar_18273 = (cppVar_18273 & cppMask_un_16_);
	cppVar_18274 = ROM.rd(cppVar_18273);
	cppVar_18275 = (cppVar_18274 >> 7) & cppMask_un_1_;
	cppVar_18276 = (cppVar_18275 == 1);
	if (cppVar_18276) {
	cppVar_18277 = PC + 1;
	cppVar_18277 = (cppVar_18277 & cppMask_un_16_);
	cppVar_18278 = ROM.rd(cppVar_18277);
	cppVar_18279 = (cppVar_18278 >> 3) & cppMask_un_5_;
	cppVar_18280 = (cppVar_18279 << 3) | 0;
	cppVar_18280 = (cppVar_18280 & cppMask_un_8_);
	cppVar_18272 = cppVar_18280;
	} else {
	cppVar_18281 = PC + 1;
	cppVar_18281 = (cppVar_18281 & cppMask_un_16_);
	cppVar_18282 = ROM.rd(cppVar_18281);
	cppVar_18283 = (cppVar_18282 >> 3) & cppMask_un_5_;
	cppVar_18284 = (cppVar_18283 & cppMask_un_5_);
	cppVar_18285 = cppVar_18284 + 32;
	cppVar_18285 = (cppVar_18285 & cppMask_un_8_);
	cppVar_18272 = cppVar_18285;
	}
	cppVar_18287 = (cppVar_18272 == 153);
	if (cppVar_18287) {
	cppVar_18271 = SBUF;
	} else {
	cppVar_18290 = PC + 1;
	cppVar_18290 = (cppVar_18290 & cppMask_un_16_);
	cppVar_18291 = ROM.rd(cppVar_18290);
	cppVar_18292 = (cppVar_18291 >> 7) & cppMask_un_1_;
	cppVar_18293 = (cppVar_18292 == 1);
	if (cppVar_18293) {
	cppVar_18294 = PC + 1;
	cppVar_18294 = (cppVar_18294 & cppMask_un_16_);
	cppVar_18295 = ROM.rd(cppVar_18294);
	cppVar_18296 = (cppVar_18295 >> 3) & cppMask_un_5_;
	cppVar_18297 = (cppVar_18296 << 3) | 0;
	cppVar_18297 = (cppVar_18297 & cppMask_un_8_);
	cppVar_18289 = cppVar_18297;
	} else {
	cppVar_18298 = PC + 1;
	cppVar_18298 = (cppVar_18298 & cppMask_un_16_);
	cppVar_18299 = ROM.rd(cppVar_18298);
	cppVar_18300 = (cppVar_18299 >> 3) & cppMask_un_5_;
	cppVar_18301 = (cppVar_18300 & cppMask_un_5_);
	cppVar_18302 = cppVar_18301 + 32;
	cppVar_18302 = (cppVar_18302 & cppMask_un_8_);
	cppVar_18289 = cppVar_18302;
	}
	cppVar_18304 = (cppVar_18289 == 160);
	if (cppVar_18304) {
	cppVar_18288 = P2;
	} else {
	cppVar_18307 = PC + 1;
	cppVar_18307 = (cppVar_18307 & cppMask_un_16_);
	cppVar_18308 = ROM.rd(cppVar_18307);
	cppVar_18309 = (cppVar_18308 >> 7) & cppMask_un_1_;
	cppVar_18310 = (cppVar_18309 == 1);
	if (cppVar_18310) {
	cppVar_18311 = PC + 1;
	cppVar_18311 = (cppVar_18311 & cppMask_un_16_);
	cppVar_18312 = ROM.rd(cppVar_18311);
	cppVar_18313 = (cppVar_18312 >> 3) & cppMask_un_5_;
	cppVar_18314 = (cppVar_18313 << 3) | 0;
	cppVar_18314 = (cppVar_18314 & cppMask_un_8_);
	cppVar_18306 = cppVar_18314;
	} else {
	cppVar_18315 = PC + 1;
	cppVar_18315 = (cppVar_18315 & cppMask_un_16_);
	cppVar_18316 = ROM.rd(cppVar_18315);
	cppVar_18317 = (cppVar_18316 >> 3) & cppMask_un_5_;
	cppVar_18318 = (cppVar_18317 & cppMask_un_5_);
	cppVar_18319 = cppVar_18318 + 32;
	cppVar_18319 = (cppVar_18319 & cppMask_un_8_);
	cppVar_18306 = cppVar_18319;
	}
	cppVar_18321 = (cppVar_18306 == 168);
	if (cppVar_18321) {
	cppVar_18305 = IE;
	} else {
	cppVar_18324 = PC + 1;
	cppVar_18324 = (cppVar_18324 & cppMask_un_16_);
	cppVar_18325 = ROM.rd(cppVar_18324);
	cppVar_18326 = (cppVar_18325 >> 7) & cppMask_un_1_;
	cppVar_18327 = (cppVar_18326 == 1);
	if (cppVar_18327) {
	cppVar_18328 = PC + 1;
	cppVar_18328 = (cppVar_18328 & cppMask_un_16_);
	cppVar_18329 = ROM.rd(cppVar_18328);
	cppVar_18330 = (cppVar_18329 >> 3) & cppMask_un_5_;
	cppVar_18331 = (cppVar_18330 << 3) | 0;
	cppVar_18331 = (cppVar_18331 & cppMask_un_8_);
	cppVar_18323 = cppVar_18331;
	} else {
	cppVar_18332 = PC + 1;
	cppVar_18332 = (cppVar_18332 & cppMask_un_16_);
	cppVar_18333 = ROM.rd(cppVar_18332);
	cppVar_18334 = (cppVar_18333 >> 3) & cppMask_un_5_;
	cppVar_18335 = (cppVar_18334 & cppMask_un_5_);
	cppVar_18336 = cppVar_18335 + 32;
	cppVar_18336 = (cppVar_18336 & cppMask_un_8_);
	cppVar_18323 = cppVar_18336;
	}
	cppVar_18338 = (cppVar_18323 == 176);
	if (cppVar_18338) {
	cppVar_18322 = P3;
	} else {
	cppVar_18341 = PC + 1;
	cppVar_18341 = (cppVar_18341 & cppMask_un_16_);
	cppVar_18342 = ROM.rd(cppVar_18341);
	cppVar_18343 = (cppVar_18342 >> 7) & cppMask_un_1_;
	cppVar_18344 = (cppVar_18343 == 1);
	if (cppVar_18344) {
	cppVar_18345 = PC + 1;
	cppVar_18345 = (cppVar_18345 & cppMask_un_16_);
	cppVar_18346 = ROM.rd(cppVar_18345);
	cppVar_18347 = (cppVar_18346 >> 3) & cppMask_un_5_;
	cppVar_18348 = (cppVar_18347 << 3) | 0;
	cppVar_18348 = (cppVar_18348 & cppMask_un_8_);
	cppVar_18340 = cppVar_18348;
	} else {
	cppVar_18349 = PC + 1;
	cppVar_18349 = (cppVar_18349 & cppMask_un_16_);
	cppVar_18350 = ROM.rd(cppVar_18349);
	cppVar_18351 = (cppVar_18350 >> 3) & cppMask_un_5_;
	cppVar_18352 = (cppVar_18351 & cppMask_un_5_);
	cppVar_18353 = cppVar_18352 + 32;
	cppVar_18353 = (cppVar_18353 & cppMask_un_8_);
	cppVar_18340 = cppVar_18353;
	}
	cppVar_18355 = (cppVar_18340 == 184);
	if (cppVar_18355) {
	cppVar_18339 = IP;
	} else {
	cppVar_18358 = PC + 1;
	cppVar_18358 = (cppVar_18358 & cppMask_un_16_);
	cppVar_18359 = ROM.rd(cppVar_18358);
	cppVar_18360 = (cppVar_18359 >> 7) & cppMask_un_1_;
	cppVar_18361 = (cppVar_18360 == 1);
	if (cppVar_18361) {
	cppVar_18362 = PC + 1;
	cppVar_18362 = (cppVar_18362 & cppMask_un_16_);
	cppVar_18363 = ROM.rd(cppVar_18362);
	cppVar_18364 = (cppVar_18363 >> 3) & cppMask_un_5_;
	cppVar_18365 = (cppVar_18364 << 3) | 0;
	cppVar_18365 = (cppVar_18365 & cppMask_un_8_);
	cppVar_18357 = cppVar_18365;
	} else {
	cppVar_18366 = PC + 1;
	cppVar_18366 = (cppVar_18366 & cppMask_un_16_);
	cppVar_18367 = ROM.rd(cppVar_18366);
	cppVar_18368 = (cppVar_18367 >> 3) & cppMask_un_5_;
	cppVar_18369 = (cppVar_18368 & cppMask_un_5_);
	cppVar_18370 = cppVar_18369 + 32;
	cppVar_18370 = (cppVar_18370 & cppMask_un_8_);
	cppVar_18357 = cppVar_18370;
	}
	cppVar_18372 = (cppVar_18357 == 208);
	if (cppVar_18372) {
	cppVar_18356 = PSW;
	} else {
	cppVar_18375 = PC + 1;
	cppVar_18375 = (cppVar_18375 & cppMask_un_16_);
	cppVar_18376 = ROM.rd(cppVar_18375);
	cppVar_18377 = (cppVar_18376 >> 7) & cppMask_un_1_;
	cppVar_18378 = (cppVar_18377 == 1);
	if (cppVar_18378) {
	cppVar_18379 = PC + 1;
	cppVar_18379 = (cppVar_18379 & cppMask_un_16_);
	cppVar_18380 = ROM.rd(cppVar_18379);
	cppVar_18381 = (cppVar_18380 >> 3) & cppMask_un_5_;
	cppVar_18382 = (cppVar_18381 << 3) | 0;
	cppVar_18382 = (cppVar_18382 & cppMask_un_8_);
	cppVar_18374 = cppVar_18382;
	} else {
	cppVar_18383 = PC + 1;
	cppVar_18383 = (cppVar_18383 & cppMask_un_16_);
	cppVar_18384 = ROM.rd(cppVar_18383);
	cppVar_18385 = (cppVar_18384 >> 3) & cppMask_un_5_;
	cppVar_18386 = (cppVar_18385 & cppMask_un_5_);
	cppVar_18387 = cppVar_18386 + 32;
	cppVar_18387 = (cppVar_18387 & cppMask_un_8_);
	cppVar_18374 = cppVar_18387;
	}
	cppVar_18389 = (cppVar_18374 == 224);
	if (cppVar_18389) {
	cppVar_18373 = ACC;
	} else {
	cppVar_18392 = PC + 1;
	cppVar_18392 = (cppVar_18392 & cppMask_un_16_);
	cppVar_18393 = ROM.rd(cppVar_18392);
	cppVar_18394 = (cppVar_18393 >> 7) & cppMask_un_1_;
	cppVar_18395 = (cppVar_18394 == 1);
	if (cppVar_18395) {
	cppVar_18396 = PC + 1;
	cppVar_18396 = (cppVar_18396 & cppMask_un_16_);
	cppVar_18397 = ROM.rd(cppVar_18396);
	cppVar_18398 = (cppVar_18397 >> 3) & cppMask_un_5_;
	cppVar_18399 = (cppVar_18398 << 3) | 0;
	cppVar_18399 = (cppVar_18399 & cppMask_un_8_);
	cppVar_18391 = cppVar_18399;
	} else {
	cppVar_18400 = PC + 1;
	cppVar_18400 = (cppVar_18400 & cppMask_un_16_);
	cppVar_18401 = ROM.rd(cppVar_18400);
	cppVar_18402 = (cppVar_18401 >> 3) & cppMask_un_5_;
	cppVar_18403 = (cppVar_18402 & cppMask_un_5_);
	cppVar_18404 = cppVar_18403 + 32;
	cppVar_18404 = (cppVar_18404 & cppMask_un_8_);
	cppVar_18391 = cppVar_18404;
	}
	cppVar_18406 = (cppVar_18391 == 240);
	if (cppVar_18406) {
	cppVar_18390 = B;
	} else {
	cppVar_18390 = 0;
	}
	cppVar_18373 = cppVar_18390;
	}
	cppVar_18356 = cppVar_18373;
	}
	cppVar_18339 = cppVar_18356;
	}
	cppVar_18322 = cppVar_18339;
	}
	cppVar_18305 = cppVar_18322;
	}
	cppVar_18288 = cppVar_18305;
	}
	cppVar_18271 = cppVar_18288;
	}
	cppVar_18254 = cppVar_18271;
	}
	cppVar_18237 = cppVar_18254;
	}
	cppVar_18220 = cppVar_18237;
	}
	cppVar_18203 = cppVar_18220;
	}
	cppVar_18186 = cppVar_18203;
	}
	cppVar_18169 = cppVar_18186;
	}
	cppVar_18152 = cppVar_18169;
	}
	cppVar_18135 = cppVar_18152;
	}
	cppVar_18118 = cppVar_18135;
	}
	cppVar_18101 = cppVar_18118;
	}
	cppVar_18084 = cppVar_18101;
	}
	cppVar_18067 = cppVar_18084;
	}
	cppVar_18050 = cppVar_18067;
	}
	cppVar_18017 = cppVar_18050;
	}
	cppVar_18408 = cppVar_18016 & cppVar_18017;
	cppVar_18410 = 1;
	cppVar_18411 = PC + 1;
	cppVar_18411 = (cppVar_18411 & cppMask_un_16_);
	cppVar_18412 = ROM.rd(cppVar_18411);
	cppVar_18413 = (cppVar_18412 >> 0) & cppMask_un_3_;
	cppVar_18414 = (cppVar_18413 & cppMask_un_3_);
	cppVar_18415 = cppVar_18410 << static_cast<unsigned>(cppVar_18414);
	cppVar_18415 = (cppVar_18415 & cppMask_un_8_);
	cppVar_18416 = cppVar_18408 | cppVar_18415;
	cppVar_17989 = cppVar_18416;
	} else {
	cppVar_17989 = IP;
	}
	cppVar_17985 = cppVar_17989;
	} else {
	cppVar_18418 = ROM.rd(PC);
	cppVar_18420 = (cppVar_18418 == 208);
	if (cppVar_18420) {
	cppVar_18423 = PC + 1;
	cppVar_18423 = (cppVar_18423 & cppMask_un_16_);
	cppVar_18424 = ROM.rd(cppVar_18423);
	cppVar_18426 = (cppVar_18424 == 184);
	if (cppVar_18426) {
	cppVar_18427 = IRAM.rd(SP);
	cppVar_18421 = cppVar_18427;
	} else {
	cppVar_18421 = IP;
	}
	cppVar_18417 = cppVar_18421;
	} else {
	cppVar_18429 = ROM.rd(PC);
	cppVar_18431 = (cppVar_18429 == 245);
	cppVar_18432 = ROM.rd(PC);
	cppVar_18434 = (cppVar_18432 == 197);
	cppVar_18435 = cppVar_18431 || cppVar_18434;
	if (cppVar_18435) {
	cppVar_18438 = PC + 1;
	cppVar_18438 = (cppVar_18438 & cppMask_un_16_);
	cppVar_18439 = ROM.rd(cppVar_18438);
	cppVar_18441 = (cppVar_18439 == 184);
	if (cppVar_18441) {
	cppVar_18436 = ACC;
	} else {
	cppVar_18436 = IP;
	}
	cppVar_18428 = cppVar_18436;
	} else {
	cppVar_18443 = ROM.rd(PC);
	cppVar_18445 = (cppVar_18443 == 178);
	if (cppVar_18445) {
	cppVar_18449 = PC + 1;
	cppVar_18449 = (cppVar_18449 & cppMask_un_16_);
	cppVar_18450 = ROM.rd(cppVar_18449);
	cppVar_18451 = (cppVar_18450 >> 7) & cppMask_un_1_;
	cppVar_18453 = (cppVar_18451 == 1);
	if (cppVar_18453) {
	cppVar_18454 = PC + 1;
	cppVar_18454 = (cppVar_18454 & cppMask_un_16_);
	cppVar_18455 = ROM.rd(cppVar_18454);
	cppVar_18456 = (cppVar_18455 >> 3) & cppMask_un_5_;
	cppVar_18458 = (cppVar_18456 << 3) | 0;
	cppVar_18458 = (cppVar_18458 & cppMask_un_8_);
	cppVar_18447 = cppVar_18458;
	} else {
	cppVar_18459 = PC + 1;
	cppVar_18459 = (cppVar_18459 & cppMask_un_16_);
	cppVar_18460 = ROM.rd(cppVar_18459);
	cppVar_18461 = (cppVar_18460 >> 3) & cppMask_un_5_;
	cppVar_18462 = (cppVar_18461 & cppMask_un_5_);
	cppVar_18464 = cppVar_18462 + 32;
	cppVar_18464 = (cppVar_18464 & cppMask_un_8_);
	cppVar_18447 = cppVar_18464;
	}
	cppVar_18466 = (cppVar_18447 == 184);
	if (cppVar_18466) {
	cppVar_18468 = PC + 1;
	cppVar_18468 = (cppVar_18468 & cppMask_un_16_);
	cppVar_18469 = ROM.rd(cppVar_18468);
	cppVar_18470 = (cppVar_18469 >> 0) & cppMask_un_3_;
	cppVar_18471 = (cppVar_18470 & cppMask_un_3_);
	cppVar_18472 = 1 << static_cast<unsigned>(cppVar_18471);
	cppVar_18472 = (cppVar_18472 & cppMask_un_8_);
	cppVar_18473 = ~cppVar_18472;
	cppVar_18476 = PC + 1;
	cppVar_18476 = (cppVar_18476 & cppMask_un_16_);
	cppVar_18477 = ROM.rd(cppVar_18476);
	cppVar_18478 = (cppVar_18477 >> 7) & cppMask_un_1_;
	cppVar_18479 = (cppVar_18478 == 1);
	if (cppVar_18479) {
	cppVar_18480 = PC + 1;
	cppVar_18480 = (cppVar_18480 & cppMask_un_16_);
	cppVar_18481 = ROM.rd(cppVar_18480);
	cppVar_18482 = (cppVar_18481 >> 3) & cppMask_un_5_;
	cppVar_18483 = (cppVar_18482 << 3) | 0;
	cppVar_18483 = (cppVar_18483 & cppMask_un_8_);
	cppVar_18475 = cppVar_18483;
	} else {
	cppVar_18484 = PC + 1;
	cppVar_18484 = (cppVar_18484 & cppMask_un_16_);
	cppVar_18485 = ROM.rd(cppVar_18484);
	cppVar_18486 = (cppVar_18485 >> 3) & cppMask_un_5_;
	cppVar_18487 = (cppVar_18486 & cppMask_un_5_);
	cppVar_18488 = cppVar_18487 + 32;
	cppVar_18488 = (cppVar_18488 & cppMask_un_8_);
	cppVar_18475 = cppVar_18488;
	}
	cppVar_18489 = (cppVar_18475 >> 7) & cppMask_un_1_;
	cppVar_18491 = (cppVar_18489 == 0);
	if (cppVar_18491) {
	cppVar_18493 = PC + 1;
	cppVar_18493 = (cppVar_18493 & cppMask_un_16_);
	cppVar_18494 = ROM.rd(cppVar_18493);
	cppVar_18495 = (cppVar_18494 >> 7) & cppMask_un_1_;
	cppVar_18496 = (cppVar_18495 == 1);
	if (cppVar_18496) {
	cppVar_18497 = PC + 1;
	cppVar_18497 = (cppVar_18497 & cppMask_un_16_);
	cppVar_18498 = ROM.rd(cppVar_18497);
	cppVar_18499 = (cppVar_18498 >> 3) & cppMask_un_5_;
	cppVar_18500 = (cppVar_18499 << 3) | 0;
	cppVar_18500 = (cppVar_18500 & cppMask_un_8_);
	cppVar_18492 = cppVar_18500;
	} else {
	cppVar_18501 = PC + 1;
	cppVar_18501 = (cppVar_18501 & cppMask_un_16_);
	cppVar_18502 = ROM.rd(cppVar_18501);
	cppVar_18503 = (cppVar_18502 >> 3) & cppMask_un_5_;
	cppVar_18504 = (cppVar_18503 & cppMask_un_5_);
	cppVar_18505 = cppVar_18504 + 32;
	cppVar_18505 = (cppVar_18505 & cppMask_un_8_);
	cppVar_18492 = cppVar_18505;
	}
	cppVar_18506 = IRAM.rd(cppVar_18492);
	cppVar_18474 = cppVar_18506;
	} else {
	cppVar_18509 = PC + 1;
	cppVar_18509 = (cppVar_18509 & cppMask_un_16_);
	cppVar_18510 = ROM.rd(cppVar_18509);
	cppVar_18511 = (cppVar_18510 >> 7) & cppMask_un_1_;
	cppVar_18512 = (cppVar_18511 == 1);
	if (cppVar_18512) {
	cppVar_18513 = PC + 1;
	cppVar_18513 = (cppVar_18513 & cppMask_un_16_);
	cppVar_18514 = ROM.rd(cppVar_18513);
	cppVar_18515 = (cppVar_18514 >> 3) & cppMask_un_5_;
	cppVar_18516 = (cppVar_18515 << 3) | 0;
	cppVar_18516 = (cppVar_18516 & cppMask_un_8_);
	cppVar_18508 = cppVar_18516;
	} else {
	cppVar_18517 = PC + 1;
	cppVar_18517 = (cppVar_18517 & cppMask_un_16_);
	cppVar_18518 = ROM.rd(cppVar_18517);
	cppVar_18519 = (cppVar_18518 >> 3) & cppMask_un_5_;
	cppVar_18520 = (cppVar_18519 & cppMask_un_5_);
	cppVar_18521 = cppVar_18520 + 32;
	cppVar_18521 = (cppVar_18521 & cppMask_un_8_);
	cppVar_18508 = cppVar_18521;
	}
	cppVar_18523 = (cppVar_18508 == 128);
	if (cppVar_18523) {
	cppVar_18507 = P0;
	} else {
	cppVar_18526 = PC + 1;
	cppVar_18526 = (cppVar_18526 & cppMask_un_16_);
	cppVar_18527 = ROM.rd(cppVar_18526);
	cppVar_18528 = (cppVar_18527 >> 7) & cppMask_un_1_;
	cppVar_18529 = (cppVar_18528 == 1);
	if (cppVar_18529) {
	cppVar_18530 = PC + 1;
	cppVar_18530 = (cppVar_18530 & cppMask_un_16_);
	cppVar_18531 = ROM.rd(cppVar_18530);
	cppVar_18532 = (cppVar_18531 >> 3) & cppMask_un_5_;
	cppVar_18533 = (cppVar_18532 << 3) | 0;
	cppVar_18533 = (cppVar_18533 & cppMask_un_8_);
	cppVar_18525 = cppVar_18533;
	} else {
	cppVar_18534 = PC + 1;
	cppVar_18534 = (cppVar_18534 & cppMask_un_16_);
	cppVar_18535 = ROM.rd(cppVar_18534);
	cppVar_18536 = (cppVar_18535 >> 3) & cppMask_un_5_;
	cppVar_18537 = (cppVar_18536 & cppMask_un_5_);
	cppVar_18538 = cppVar_18537 + 32;
	cppVar_18538 = (cppVar_18538 & cppMask_un_8_);
	cppVar_18525 = cppVar_18538;
	}
	cppVar_18540 = (cppVar_18525 == 129);
	if (cppVar_18540) {
	cppVar_18524 = SP;
	} else {
	cppVar_18543 = PC + 1;
	cppVar_18543 = (cppVar_18543 & cppMask_un_16_);
	cppVar_18544 = ROM.rd(cppVar_18543);
	cppVar_18545 = (cppVar_18544 >> 7) & cppMask_un_1_;
	cppVar_18546 = (cppVar_18545 == 1);
	if (cppVar_18546) {
	cppVar_18547 = PC + 1;
	cppVar_18547 = (cppVar_18547 & cppMask_un_16_);
	cppVar_18548 = ROM.rd(cppVar_18547);
	cppVar_18549 = (cppVar_18548 >> 3) & cppMask_un_5_;
	cppVar_18550 = (cppVar_18549 << 3) | 0;
	cppVar_18550 = (cppVar_18550 & cppMask_un_8_);
	cppVar_18542 = cppVar_18550;
	} else {
	cppVar_18551 = PC + 1;
	cppVar_18551 = (cppVar_18551 & cppMask_un_16_);
	cppVar_18552 = ROM.rd(cppVar_18551);
	cppVar_18553 = (cppVar_18552 >> 3) & cppMask_un_5_;
	cppVar_18554 = (cppVar_18553 & cppMask_un_5_);
	cppVar_18555 = cppVar_18554 + 32;
	cppVar_18555 = (cppVar_18555 & cppMask_un_8_);
	cppVar_18542 = cppVar_18555;
	}
	cppVar_18557 = (cppVar_18542 == 130);
	if (cppVar_18557) {
	cppVar_18541 = DPL;
	} else {
	cppVar_18560 = PC + 1;
	cppVar_18560 = (cppVar_18560 & cppMask_un_16_);
	cppVar_18561 = ROM.rd(cppVar_18560);
	cppVar_18562 = (cppVar_18561 >> 7) & cppMask_un_1_;
	cppVar_18563 = (cppVar_18562 == 1);
	if (cppVar_18563) {
	cppVar_18564 = PC + 1;
	cppVar_18564 = (cppVar_18564 & cppMask_un_16_);
	cppVar_18565 = ROM.rd(cppVar_18564);
	cppVar_18566 = (cppVar_18565 >> 3) & cppMask_un_5_;
	cppVar_18567 = (cppVar_18566 << 3) | 0;
	cppVar_18567 = (cppVar_18567 & cppMask_un_8_);
	cppVar_18559 = cppVar_18567;
	} else {
	cppVar_18568 = PC + 1;
	cppVar_18568 = (cppVar_18568 & cppMask_un_16_);
	cppVar_18569 = ROM.rd(cppVar_18568);
	cppVar_18570 = (cppVar_18569 >> 3) & cppMask_un_5_;
	cppVar_18571 = (cppVar_18570 & cppMask_un_5_);
	cppVar_18572 = cppVar_18571 + 32;
	cppVar_18572 = (cppVar_18572 & cppMask_un_8_);
	cppVar_18559 = cppVar_18572;
	}
	cppVar_18574 = (cppVar_18559 == 131);
	if (cppVar_18574) {
	cppVar_18558 = DPH;
	} else {
	cppVar_18577 = PC + 1;
	cppVar_18577 = (cppVar_18577 & cppMask_un_16_);
	cppVar_18578 = ROM.rd(cppVar_18577);
	cppVar_18579 = (cppVar_18578 >> 7) & cppMask_un_1_;
	cppVar_18580 = (cppVar_18579 == 1);
	if (cppVar_18580) {
	cppVar_18581 = PC + 1;
	cppVar_18581 = (cppVar_18581 & cppMask_un_16_);
	cppVar_18582 = ROM.rd(cppVar_18581);
	cppVar_18583 = (cppVar_18582 >> 3) & cppMask_un_5_;
	cppVar_18584 = (cppVar_18583 << 3) | 0;
	cppVar_18584 = (cppVar_18584 & cppMask_un_8_);
	cppVar_18576 = cppVar_18584;
	} else {
	cppVar_18585 = PC + 1;
	cppVar_18585 = (cppVar_18585 & cppMask_un_16_);
	cppVar_18586 = ROM.rd(cppVar_18585);
	cppVar_18587 = (cppVar_18586 >> 3) & cppMask_un_5_;
	cppVar_18588 = (cppVar_18587 & cppMask_un_5_);
	cppVar_18589 = cppVar_18588 + 32;
	cppVar_18589 = (cppVar_18589 & cppMask_un_8_);
	cppVar_18576 = cppVar_18589;
	}
	cppVar_18591 = (cppVar_18576 == 135);
	if (cppVar_18591) {
	cppVar_18575 = PCON;
	} else {
	cppVar_18594 = PC + 1;
	cppVar_18594 = (cppVar_18594 & cppMask_un_16_);
	cppVar_18595 = ROM.rd(cppVar_18594);
	cppVar_18596 = (cppVar_18595 >> 7) & cppMask_un_1_;
	cppVar_18597 = (cppVar_18596 == 1);
	if (cppVar_18597) {
	cppVar_18598 = PC + 1;
	cppVar_18598 = (cppVar_18598 & cppMask_un_16_);
	cppVar_18599 = ROM.rd(cppVar_18598);
	cppVar_18600 = (cppVar_18599 >> 3) & cppMask_un_5_;
	cppVar_18601 = (cppVar_18600 << 3) | 0;
	cppVar_18601 = (cppVar_18601 & cppMask_un_8_);
	cppVar_18593 = cppVar_18601;
	} else {
	cppVar_18602 = PC + 1;
	cppVar_18602 = (cppVar_18602 & cppMask_un_16_);
	cppVar_18603 = ROM.rd(cppVar_18602);
	cppVar_18604 = (cppVar_18603 >> 3) & cppMask_un_5_;
	cppVar_18605 = (cppVar_18604 & cppMask_un_5_);
	cppVar_18606 = cppVar_18605 + 32;
	cppVar_18606 = (cppVar_18606 & cppMask_un_8_);
	cppVar_18593 = cppVar_18606;
	}
	cppVar_18608 = (cppVar_18593 == 136);
	if (cppVar_18608) {
	cppVar_18592 = TCON;
	} else {
	cppVar_18611 = PC + 1;
	cppVar_18611 = (cppVar_18611 & cppMask_un_16_);
	cppVar_18612 = ROM.rd(cppVar_18611);
	cppVar_18613 = (cppVar_18612 >> 7) & cppMask_un_1_;
	cppVar_18614 = (cppVar_18613 == 1);
	if (cppVar_18614) {
	cppVar_18615 = PC + 1;
	cppVar_18615 = (cppVar_18615 & cppMask_un_16_);
	cppVar_18616 = ROM.rd(cppVar_18615);
	cppVar_18617 = (cppVar_18616 >> 3) & cppMask_un_5_;
	cppVar_18618 = (cppVar_18617 << 3) | 0;
	cppVar_18618 = (cppVar_18618 & cppMask_un_8_);
	cppVar_18610 = cppVar_18618;
	} else {
	cppVar_18619 = PC + 1;
	cppVar_18619 = (cppVar_18619 & cppMask_un_16_);
	cppVar_18620 = ROM.rd(cppVar_18619);
	cppVar_18621 = (cppVar_18620 >> 3) & cppMask_un_5_;
	cppVar_18622 = (cppVar_18621 & cppMask_un_5_);
	cppVar_18623 = cppVar_18622 + 32;
	cppVar_18623 = (cppVar_18623 & cppMask_un_8_);
	cppVar_18610 = cppVar_18623;
	}
	cppVar_18625 = (cppVar_18610 == 137);
	if (cppVar_18625) {
	cppVar_18609 = TMOD;
	} else {
	cppVar_18628 = PC + 1;
	cppVar_18628 = (cppVar_18628 & cppMask_un_16_);
	cppVar_18629 = ROM.rd(cppVar_18628);
	cppVar_18630 = (cppVar_18629 >> 7) & cppMask_un_1_;
	cppVar_18631 = (cppVar_18630 == 1);
	if (cppVar_18631) {
	cppVar_18632 = PC + 1;
	cppVar_18632 = (cppVar_18632 & cppMask_un_16_);
	cppVar_18633 = ROM.rd(cppVar_18632);
	cppVar_18634 = (cppVar_18633 >> 3) & cppMask_un_5_;
	cppVar_18635 = (cppVar_18634 << 3) | 0;
	cppVar_18635 = (cppVar_18635 & cppMask_un_8_);
	cppVar_18627 = cppVar_18635;
	} else {
	cppVar_18636 = PC + 1;
	cppVar_18636 = (cppVar_18636 & cppMask_un_16_);
	cppVar_18637 = ROM.rd(cppVar_18636);
	cppVar_18638 = (cppVar_18637 >> 3) & cppMask_un_5_;
	cppVar_18639 = (cppVar_18638 & cppMask_un_5_);
	cppVar_18640 = cppVar_18639 + 32;
	cppVar_18640 = (cppVar_18640 & cppMask_un_8_);
	cppVar_18627 = cppVar_18640;
	}
	cppVar_18642 = (cppVar_18627 == 138);
	if (cppVar_18642) {
	cppVar_18626 = TL0;
	} else {
	cppVar_18645 = PC + 1;
	cppVar_18645 = (cppVar_18645 & cppMask_un_16_);
	cppVar_18646 = ROM.rd(cppVar_18645);
	cppVar_18647 = (cppVar_18646 >> 7) & cppMask_un_1_;
	cppVar_18648 = (cppVar_18647 == 1);
	if (cppVar_18648) {
	cppVar_18649 = PC + 1;
	cppVar_18649 = (cppVar_18649 & cppMask_un_16_);
	cppVar_18650 = ROM.rd(cppVar_18649);
	cppVar_18651 = (cppVar_18650 >> 3) & cppMask_un_5_;
	cppVar_18652 = (cppVar_18651 << 3) | 0;
	cppVar_18652 = (cppVar_18652 & cppMask_un_8_);
	cppVar_18644 = cppVar_18652;
	} else {
	cppVar_18653 = PC + 1;
	cppVar_18653 = (cppVar_18653 & cppMask_un_16_);
	cppVar_18654 = ROM.rd(cppVar_18653);
	cppVar_18655 = (cppVar_18654 >> 3) & cppMask_un_5_;
	cppVar_18656 = (cppVar_18655 & cppMask_un_5_);
	cppVar_18657 = cppVar_18656 + 32;
	cppVar_18657 = (cppVar_18657 & cppMask_un_8_);
	cppVar_18644 = cppVar_18657;
	}
	cppVar_18659 = (cppVar_18644 == 140);
	if (cppVar_18659) {
	cppVar_18643 = TH0;
	} else {
	cppVar_18662 = PC + 1;
	cppVar_18662 = (cppVar_18662 & cppMask_un_16_);
	cppVar_18663 = ROM.rd(cppVar_18662);
	cppVar_18664 = (cppVar_18663 >> 7) & cppMask_un_1_;
	cppVar_18665 = (cppVar_18664 == 1);
	if (cppVar_18665) {
	cppVar_18666 = PC + 1;
	cppVar_18666 = (cppVar_18666 & cppMask_un_16_);
	cppVar_18667 = ROM.rd(cppVar_18666);
	cppVar_18668 = (cppVar_18667 >> 3) & cppMask_un_5_;
	cppVar_18669 = (cppVar_18668 << 3) | 0;
	cppVar_18669 = (cppVar_18669 & cppMask_un_8_);
	cppVar_18661 = cppVar_18669;
	} else {
	cppVar_18670 = PC + 1;
	cppVar_18670 = (cppVar_18670 & cppMask_un_16_);
	cppVar_18671 = ROM.rd(cppVar_18670);
	cppVar_18672 = (cppVar_18671 >> 3) & cppMask_un_5_;
	cppVar_18673 = (cppVar_18672 & cppMask_un_5_);
	cppVar_18674 = cppVar_18673 + 32;
	cppVar_18674 = (cppVar_18674 & cppMask_un_8_);
	cppVar_18661 = cppVar_18674;
	}
	cppVar_18676 = (cppVar_18661 == 139);
	if (cppVar_18676) {
	cppVar_18660 = TL1;
	} else {
	cppVar_18679 = PC + 1;
	cppVar_18679 = (cppVar_18679 & cppMask_un_16_);
	cppVar_18680 = ROM.rd(cppVar_18679);
	cppVar_18681 = (cppVar_18680 >> 7) & cppMask_un_1_;
	cppVar_18682 = (cppVar_18681 == 1);
	if (cppVar_18682) {
	cppVar_18683 = PC + 1;
	cppVar_18683 = (cppVar_18683 & cppMask_un_16_);
	cppVar_18684 = ROM.rd(cppVar_18683);
	cppVar_18685 = (cppVar_18684 >> 3) & cppMask_un_5_;
	cppVar_18686 = (cppVar_18685 << 3) | 0;
	cppVar_18686 = (cppVar_18686 & cppMask_un_8_);
	cppVar_18678 = cppVar_18686;
	} else {
	cppVar_18687 = PC + 1;
	cppVar_18687 = (cppVar_18687 & cppMask_un_16_);
	cppVar_18688 = ROM.rd(cppVar_18687);
	cppVar_18689 = (cppVar_18688 >> 3) & cppMask_un_5_;
	cppVar_18690 = (cppVar_18689 & cppMask_un_5_);
	cppVar_18691 = cppVar_18690 + 32;
	cppVar_18691 = (cppVar_18691 & cppMask_un_8_);
	cppVar_18678 = cppVar_18691;
	}
	cppVar_18693 = (cppVar_18678 == 141);
	if (cppVar_18693) {
	cppVar_18677 = TH1;
	} else {
	cppVar_18696 = PC + 1;
	cppVar_18696 = (cppVar_18696 & cppMask_un_16_);
	cppVar_18697 = ROM.rd(cppVar_18696);
	cppVar_18698 = (cppVar_18697 >> 7) & cppMask_un_1_;
	cppVar_18699 = (cppVar_18698 == 1);
	if (cppVar_18699) {
	cppVar_18700 = PC + 1;
	cppVar_18700 = (cppVar_18700 & cppMask_un_16_);
	cppVar_18701 = ROM.rd(cppVar_18700);
	cppVar_18702 = (cppVar_18701 >> 3) & cppMask_un_5_;
	cppVar_18703 = (cppVar_18702 << 3) | 0;
	cppVar_18703 = (cppVar_18703 & cppMask_un_8_);
	cppVar_18695 = cppVar_18703;
	} else {
	cppVar_18704 = PC + 1;
	cppVar_18704 = (cppVar_18704 & cppMask_un_16_);
	cppVar_18705 = ROM.rd(cppVar_18704);
	cppVar_18706 = (cppVar_18705 >> 3) & cppMask_un_5_;
	cppVar_18707 = (cppVar_18706 & cppMask_un_5_);
	cppVar_18708 = cppVar_18707 + 32;
	cppVar_18708 = (cppVar_18708 & cppMask_un_8_);
	cppVar_18695 = cppVar_18708;
	}
	cppVar_18710 = (cppVar_18695 == 144);
	if (cppVar_18710) {
	cppVar_18694 = P1;
	} else {
	cppVar_18713 = PC + 1;
	cppVar_18713 = (cppVar_18713 & cppMask_un_16_);
	cppVar_18714 = ROM.rd(cppVar_18713);
	cppVar_18715 = (cppVar_18714 >> 7) & cppMask_un_1_;
	cppVar_18716 = (cppVar_18715 == 1);
	if (cppVar_18716) {
	cppVar_18717 = PC + 1;
	cppVar_18717 = (cppVar_18717 & cppMask_un_16_);
	cppVar_18718 = ROM.rd(cppVar_18717);
	cppVar_18719 = (cppVar_18718 >> 3) & cppMask_un_5_;
	cppVar_18720 = (cppVar_18719 << 3) | 0;
	cppVar_18720 = (cppVar_18720 & cppMask_un_8_);
	cppVar_18712 = cppVar_18720;
	} else {
	cppVar_18721 = PC + 1;
	cppVar_18721 = (cppVar_18721 & cppMask_un_16_);
	cppVar_18722 = ROM.rd(cppVar_18721);
	cppVar_18723 = (cppVar_18722 >> 3) & cppMask_un_5_;
	cppVar_18724 = (cppVar_18723 & cppMask_un_5_);
	cppVar_18725 = cppVar_18724 + 32;
	cppVar_18725 = (cppVar_18725 & cppMask_un_8_);
	cppVar_18712 = cppVar_18725;
	}
	cppVar_18727 = (cppVar_18712 == 152);
	if (cppVar_18727) {
	cppVar_18711 = SCON;
	} else {
	cppVar_18730 = PC + 1;
	cppVar_18730 = (cppVar_18730 & cppMask_un_16_);
	cppVar_18731 = ROM.rd(cppVar_18730);
	cppVar_18732 = (cppVar_18731 >> 7) & cppMask_un_1_;
	cppVar_18733 = (cppVar_18732 == 1);
	if (cppVar_18733) {
	cppVar_18734 = PC + 1;
	cppVar_18734 = (cppVar_18734 & cppMask_un_16_);
	cppVar_18735 = ROM.rd(cppVar_18734);
	cppVar_18736 = (cppVar_18735 >> 3) & cppMask_un_5_;
	cppVar_18737 = (cppVar_18736 << 3) | 0;
	cppVar_18737 = (cppVar_18737 & cppMask_un_8_);
	cppVar_18729 = cppVar_18737;
	} else {
	cppVar_18738 = PC + 1;
	cppVar_18738 = (cppVar_18738 & cppMask_un_16_);
	cppVar_18739 = ROM.rd(cppVar_18738);
	cppVar_18740 = (cppVar_18739 >> 3) & cppMask_un_5_;
	cppVar_18741 = (cppVar_18740 & cppMask_un_5_);
	cppVar_18742 = cppVar_18741 + 32;
	cppVar_18742 = (cppVar_18742 & cppMask_un_8_);
	cppVar_18729 = cppVar_18742;
	}
	cppVar_18744 = (cppVar_18729 == 153);
	if (cppVar_18744) {
	cppVar_18728 = SBUF;
	} else {
	cppVar_18747 = PC + 1;
	cppVar_18747 = (cppVar_18747 & cppMask_un_16_);
	cppVar_18748 = ROM.rd(cppVar_18747);
	cppVar_18749 = (cppVar_18748 >> 7) & cppMask_un_1_;
	cppVar_18750 = (cppVar_18749 == 1);
	if (cppVar_18750) {
	cppVar_18751 = PC + 1;
	cppVar_18751 = (cppVar_18751 & cppMask_un_16_);
	cppVar_18752 = ROM.rd(cppVar_18751);
	cppVar_18753 = (cppVar_18752 >> 3) & cppMask_un_5_;
	cppVar_18754 = (cppVar_18753 << 3) | 0;
	cppVar_18754 = (cppVar_18754 & cppMask_un_8_);
	cppVar_18746 = cppVar_18754;
	} else {
	cppVar_18755 = PC + 1;
	cppVar_18755 = (cppVar_18755 & cppMask_un_16_);
	cppVar_18756 = ROM.rd(cppVar_18755);
	cppVar_18757 = (cppVar_18756 >> 3) & cppMask_un_5_;
	cppVar_18758 = (cppVar_18757 & cppMask_un_5_);
	cppVar_18759 = cppVar_18758 + 32;
	cppVar_18759 = (cppVar_18759 & cppMask_un_8_);
	cppVar_18746 = cppVar_18759;
	}
	cppVar_18761 = (cppVar_18746 == 160);
	if (cppVar_18761) {
	cppVar_18745 = P2;
	} else {
	cppVar_18764 = PC + 1;
	cppVar_18764 = (cppVar_18764 & cppMask_un_16_);
	cppVar_18765 = ROM.rd(cppVar_18764);
	cppVar_18766 = (cppVar_18765 >> 7) & cppMask_un_1_;
	cppVar_18767 = (cppVar_18766 == 1);
	if (cppVar_18767) {
	cppVar_18768 = PC + 1;
	cppVar_18768 = (cppVar_18768 & cppMask_un_16_);
	cppVar_18769 = ROM.rd(cppVar_18768);
	cppVar_18770 = (cppVar_18769 >> 3) & cppMask_un_5_;
	cppVar_18771 = (cppVar_18770 << 3) | 0;
	cppVar_18771 = (cppVar_18771 & cppMask_un_8_);
	cppVar_18763 = cppVar_18771;
	} else {
	cppVar_18772 = PC + 1;
	cppVar_18772 = (cppVar_18772 & cppMask_un_16_);
	cppVar_18773 = ROM.rd(cppVar_18772);
	cppVar_18774 = (cppVar_18773 >> 3) & cppMask_un_5_;
	cppVar_18775 = (cppVar_18774 & cppMask_un_5_);
	cppVar_18776 = cppVar_18775 + 32;
	cppVar_18776 = (cppVar_18776 & cppMask_un_8_);
	cppVar_18763 = cppVar_18776;
	}
	cppVar_18778 = (cppVar_18763 == 168);
	if (cppVar_18778) {
	cppVar_18762 = IE;
	} else {
	cppVar_18781 = PC + 1;
	cppVar_18781 = (cppVar_18781 & cppMask_un_16_);
	cppVar_18782 = ROM.rd(cppVar_18781);
	cppVar_18783 = (cppVar_18782 >> 7) & cppMask_un_1_;
	cppVar_18784 = (cppVar_18783 == 1);
	if (cppVar_18784) {
	cppVar_18785 = PC + 1;
	cppVar_18785 = (cppVar_18785 & cppMask_un_16_);
	cppVar_18786 = ROM.rd(cppVar_18785);
	cppVar_18787 = (cppVar_18786 >> 3) & cppMask_un_5_;
	cppVar_18788 = (cppVar_18787 << 3) | 0;
	cppVar_18788 = (cppVar_18788 & cppMask_un_8_);
	cppVar_18780 = cppVar_18788;
	} else {
	cppVar_18789 = PC + 1;
	cppVar_18789 = (cppVar_18789 & cppMask_un_16_);
	cppVar_18790 = ROM.rd(cppVar_18789);
	cppVar_18791 = (cppVar_18790 >> 3) & cppMask_un_5_;
	cppVar_18792 = (cppVar_18791 & cppMask_un_5_);
	cppVar_18793 = cppVar_18792 + 32;
	cppVar_18793 = (cppVar_18793 & cppMask_un_8_);
	cppVar_18780 = cppVar_18793;
	}
	cppVar_18795 = (cppVar_18780 == 176);
	if (cppVar_18795) {
	cppVar_18779 = P3;
	} else {
	cppVar_18798 = PC + 1;
	cppVar_18798 = (cppVar_18798 & cppMask_un_16_);
	cppVar_18799 = ROM.rd(cppVar_18798);
	cppVar_18800 = (cppVar_18799 >> 7) & cppMask_un_1_;
	cppVar_18801 = (cppVar_18800 == 1);
	if (cppVar_18801) {
	cppVar_18802 = PC + 1;
	cppVar_18802 = (cppVar_18802 & cppMask_un_16_);
	cppVar_18803 = ROM.rd(cppVar_18802);
	cppVar_18804 = (cppVar_18803 >> 3) & cppMask_un_5_;
	cppVar_18805 = (cppVar_18804 << 3) | 0;
	cppVar_18805 = (cppVar_18805 & cppMask_un_8_);
	cppVar_18797 = cppVar_18805;
	} else {
	cppVar_18806 = PC + 1;
	cppVar_18806 = (cppVar_18806 & cppMask_un_16_);
	cppVar_18807 = ROM.rd(cppVar_18806);
	cppVar_18808 = (cppVar_18807 >> 3) & cppMask_un_5_;
	cppVar_18809 = (cppVar_18808 & cppMask_un_5_);
	cppVar_18810 = cppVar_18809 + 32;
	cppVar_18810 = (cppVar_18810 & cppMask_un_8_);
	cppVar_18797 = cppVar_18810;
	}
	cppVar_18812 = (cppVar_18797 == 184);
	if (cppVar_18812) {
	cppVar_18796 = IP;
	} else {
	cppVar_18815 = PC + 1;
	cppVar_18815 = (cppVar_18815 & cppMask_un_16_);
	cppVar_18816 = ROM.rd(cppVar_18815);
	cppVar_18817 = (cppVar_18816 >> 7) & cppMask_un_1_;
	cppVar_18818 = (cppVar_18817 == 1);
	if (cppVar_18818) {
	cppVar_18819 = PC + 1;
	cppVar_18819 = (cppVar_18819 & cppMask_un_16_);
	cppVar_18820 = ROM.rd(cppVar_18819);
	cppVar_18821 = (cppVar_18820 >> 3) & cppMask_un_5_;
	cppVar_18822 = (cppVar_18821 << 3) | 0;
	cppVar_18822 = (cppVar_18822 & cppMask_un_8_);
	cppVar_18814 = cppVar_18822;
	} else {
	cppVar_18823 = PC + 1;
	cppVar_18823 = (cppVar_18823 & cppMask_un_16_);
	cppVar_18824 = ROM.rd(cppVar_18823);
	cppVar_18825 = (cppVar_18824 >> 3) & cppMask_un_5_;
	cppVar_18826 = (cppVar_18825 & cppMask_un_5_);
	cppVar_18827 = cppVar_18826 + 32;
	cppVar_18827 = (cppVar_18827 & cppMask_un_8_);
	cppVar_18814 = cppVar_18827;
	}
	cppVar_18829 = (cppVar_18814 == 208);
	if (cppVar_18829) {
	cppVar_18813 = PSW;
	} else {
	cppVar_18832 = PC + 1;
	cppVar_18832 = (cppVar_18832 & cppMask_un_16_);
	cppVar_18833 = ROM.rd(cppVar_18832);
	cppVar_18834 = (cppVar_18833 >> 7) & cppMask_un_1_;
	cppVar_18835 = (cppVar_18834 == 1);
	if (cppVar_18835) {
	cppVar_18836 = PC + 1;
	cppVar_18836 = (cppVar_18836 & cppMask_un_16_);
	cppVar_18837 = ROM.rd(cppVar_18836);
	cppVar_18838 = (cppVar_18837 >> 3) & cppMask_un_5_;
	cppVar_18839 = (cppVar_18838 << 3) | 0;
	cppVar_18839 = (cppVar_18839 & cppMask_un_8_);
	cppVar_18831 = cppVar_18839;
	} else {
	cppVar_18840 = PC + 1;
	cppVar_18840 = (cppVar_18840 & cppMask_un_16_);
	cppVar_18841 = ROM.rd(cppVar_18840);
	cppVar_18842 = (cppVar_18841 >> 3) & cppMask_un_5_;
	cppVar_18843 = (cppVar_18842 & cppMask_un_5_);
	cppVar_18844 = cppVar_18843 + 32;
	cppVar_18844 = (cppVar_18844 & cppMask_un_8_);
	cppVar_18831 = cppVar_18844;
	}
	cppVar_18846 = (cppVar_18831 == 224);
	if (cppVar_18846) {
	cppVar_18830 = ACC;
	} else {
	cppVar_18849 = PC + 1;
	cppVar_18849 = (cppVar_18849 & cppMask_un_16_);
	cppVar_18850 = ROM.rd(cppVar_18849);
	cppVar_18851 = (cppVar_18850 >> 7) & cppMask_un_1_;
	cppVar_18852 = (cppVar_18851 == 1);
	if (cppVar_18852) {
	cppVar_18853 = PC + 1;
	cppVar_18853 = (cppVar_18853 & cppMask_un_16_);
	cppVar_18854 = ROM.rd(cppVar_18853);
	cppVar_18855 = (cppVar_18854 >> 3) & cppMask_un_5_;
	cppVar_18856 = (cppVar_18855 << 3) | 0;
	cppVar_18856 = (cppVar_18856 & cppMask_un_8_);
	cppVar_18848 = cppVar_18856;
	} else {
	cppVar_18857 = PC + 1;
	cppVar_18857 = (cppVar_18857 & cppMask_un_16_);
	cppVar_18858 = ROM.rd(cppVar_18857);
	cppVar_18859 = (cppVar_18858 >> 3) & cppMask_un_5_;
	cppVar_18860 = (cppVar_18859 & cppMask_un_5_);
	cppVar_18861 = cppVar_18860 + 32;
	cppVar_18861 = (cppVar_18861 & cppMask_un_8_);
	cppVar_18848 = cppVar_18861;
	}
	cppVar_18863 = (cppVar_18848 == 240);
	if (cppVar_18863) {
	cppVar_18847 = B;
	} else {
	cppVar_18847 = 0;
	}
	cppVar_18830 = cppVar_18847;
	}
	cppVar_18813 = cppVar_18830;
	}
	cppVar_18796 = cppVar_18813;
	}
	cppVar_18779 = cppVar_18796;
	}
	cppVar_18762 = cppVar_18779;
	}
	cppVar_18745 = cppVar_18762;
	}
	cppVar_18728 = cppVar_18745;
	}
	cppVar_18711 = cppVar_18728;
	}
	cppVar_18694 = cppVar_18711;
	}
	cppVar_18677 = cppVar_18694;
	}
	cppVar_18660 = cppVar_18677;
	}
	cppVar_18643 = cppVar_18660;
	}
	cppVar_18626 = cppVar_18643;
	}
	cppVar_18609 = cppVar_18626;
	}
	cppVar_18592 = cppVar_18609;
	}
	cppVar_18575 = cppVar_18592;
	}
	cppVar_18558 = cppVar_18575;
	}
	cppVar_18541 = cppVar_18558;
	}
	cppVar_18524 = cppVar_18541;
	}
	cppVar_18507 = cppVar_18524;
	}
	cppVar_18474 = cppVar_18507;
	}
	cppVar_18865 = cppVar_18473 & cppVar_18474;
	cppVar_18868 = PC + 1;
	cppVar_18868 = (cppVar_18868 & cppMask_un_16_);
	cppVar_18869 = ROM.rd(cppVar_18868);
	cppVar_18870 = (cppVar_18869 >> 7) & cppMask_un_1_;
	cppVar_18872 = (cppVar_18870 == 1);
	if (cppVar_18872) {
	cppVar_18873 = PC + 1;
	cppVar_18873 = (cppVar_18873 & cppMask_un_16_);
	cppVar_18874 = ROM.rd(cppVar_18873);
	cppVar_18875 = (cppVar_18874 >> 3) & cppMask_un_5_;
	cppVar_18877 = (cppVar_18875 << 3) | 0;
	cppVar_18877 = (cppVar_18877 & cppMask_un_8_);
	cppVar_18867 = cppVar_18877;
	} else {
	cppVar_18878 = PC + 1;
	cppVar_18878 = (cppVar_18878 & cppMask_un_16_);
	cppVar_18879 = ROM.rd(cppVar_18878);
	cppVar_18880 = (cppVar_18879 >> 3) & cppMask_un_5_;
	cppVar_18881 = (cppVar_18880 & cppMask_un_5_);
	cppVar_18883 = cppVar_18881 + 32;
	cppVar_18883 = (cppVar_18883 & cppMask_un_8_);
	cppVar_18867 = cppVar_18883;
	}
	cppVar_18884 = (cppVar_18867 >> 7) & cppMask_un_1_;
	cppVar_18886 = (cppVar_18884 == 0);
	if (cppVar_18886) {
	cppVar_18888 = PC + 1;
	cppVar_18888 = (cppVar_18888 & cppMask_un_16_);
	cppVar_18889 = ROM.rd(cppVar_18888);
	cppVar_18890 = (cppVar_18889 >> 7) & cppMask_un_1_;
	cppVar_18891 = (cppVar_18890 == 1);
	if (cppVar_18891) {
	cppVar_18892 = PC + 1;
	cppVar_18892 = (cppVar_18892 & cppMask_un_16_);
	cppVar_18893 = ROM.rd(cppVar_18892);
	cppVar_18894 = (cppVar_18893 >> 3) & cppMask_un_5_;
	cppVar_18895 = (cppVar_18894 << 3) | 0;
	cppVar_18895 = (cppVar_18895 & cppMask_un_8_);
	cppVar_18887 = cppVar_18895;
	} else {
	cppVar_18896 = PC + 1;
	cppVar_18896 = (cppVar_18896 & cppMask_un_16_);
	cppVar_18897 = ROM.rd(cppVar_18896);
	cppVar_18898 = (cppVar_18897 >> 3) & cppMask_un_5_;
	cppVar_18899 = (cppVar_18898 & cppMask_un_5_);
	cppVar_18900 = cppVar_18899 + 32;
	cppVar_18900 = (cppVar_18900 & cppMask_un_8_);
	cppVar_18887 = cppVar_18900;
	}
	cppVar_18901 = IRAM.rd(cppVar_18887);
	cppVar_18866 = cppVar_18901;
	} else {
	cppVar_18904 = PC + 1;
	cppVar_18904 = (cppVar_18904 & cppMask_un_16_);
	cppVar_18905 = ROM.rd(cppVar_18904);
	cppVar_18906 = (cppVar_18905 >> 7) & cppMask_un_1_;
	cppVar_18907 = (cppVar_18906 == 1);
	if (cppVar_18907) {
	cppVar_18908 = PC + 1;
	cppVar_18908 = (cppVar_18908 & cppMask_un_16_);
	cppVar_18909 = ROM.rd(cppVar_18908);
	cppVar_18910 = (cppVar_18909 >> 3) & cppMask_un_5_;
	cppVar_18911 = (cppVar_18910 << 3) | 0;
	cppVar_18911 = (cppVar_18911 & cppMask_un_8_);
	cppVar_18903 = cppVar_18911;
	} else {
	cppVar_18912 = PC + 1;
	cppVar_18912 = (cppVar_18912 & cppMask_un_16_);
	cppVar_18913 = ROM.rd(cppVar_18912);
	cppVar_18914 = (cppVar_18913 >> 3) & cppMask_un_5_;
	cppVar_18915 = (cppVar_18914 & cppMask_un_5_);
	cppVar_18916 = cppVar_18915 + 32;
	cppVar_18916 = (cppVar_18916 & cppMask_un_8_);
	cppVar_18903 = cppVar_18916;
	}
	cppVar_18918 = (cppVar_18903 == 128);
	if (cppVar_18918) {
	cppVar_18902 = P0;
	} else {
	cppVar_18921 = PC + 1;
	cppVar_18921 = (cppVar_18921 & cppMask_un_16_);
	cppVar_18922 = ROM.rd(cppVar_18921);
	cppVar_18923 = (cppVar_18922 >> 7) & cppMask_un_1_;
	cppVar_18924 = (cppVar_18923 == 1);
	if (cppVar_18924) {
	cppVar_18925 = PC + 1;
	cppVar_18925 = (cppVar_18925 & cppMask_un_16_);
	cppVar_18926 = ROM.rd(cppVar_18925);
	cppVar_18927 = (cppVar_18926 >> 3) & cppMask_un_5_;
	cppVar_18928 = (cppVar_18927 << 3) | 0;
	cppVar_18928 = (cppVar_18928 & cppMask_un_8_);
	cppVar_18920 = cppVar_18928;
	} else {
	cppVar_18929 = PC + 1;
	cppVar_18929 = (cppVar_18929 & cppMask_un_16_);
	cppVar_18930 = ROM.rd(cppVar_18929);
	cppVar_18931 = (cppVar_18930 >> 3) & cppMask_un_5_;
	cppVar_18932 = (cppVar_18931 & cppMask_un_5_);
	cppVar_18933 = cppVar_18932 + 32;
	cppVar_18933 = (cppVar_18933 & cppMask_un_8_);
	cppVar_18920 = cppVar_18933;
	}
	cppVar_18935 = (cppVar_18920 == 129);
	if (cppVar_18935) {
	cppVar_18919 = SP;
	} else {
	cppVar_18938 = PC + 1;
	cppVar_18938 = (cppVar_18938 & cppMask_un_16_);
	cppVar_18939 = ROM.rd(cppVar_18938);
	cppVar_18940 = (cppVar_18939 >> 7) & cppMask_un_1_;
	cppVar_18941 = (cppVar_18940 == 1);
	if (cppVar_18941) {
	cppVar_18942 = PC + 1;
	cppVar_18942 = (cppVar_18942 & cppMask_un_16_);
	cppVar_18943 = ROM.rd(cppVar_18942);
	cppVar_18944 = (cppVar_18943 >> 3) & cppMask_un_5_;
	cppVar_18945 = (cppVar_18944 << 3) | 0;
	cppVar_18945 = (cppVar_18945 & cppMask_un_8_);
	cppVar_18937 = cppVar_18945;
	} else {
	cppVar_18946 = PC + 1;
	cppVar_18946 = (cppVar_18946 & cppMask_un_16_);
	cppVar_18947 = ROM.rd(cppVar_18946);
	cppVar_18948 = (cppVar_18947 >> 3) & cppMask_un_5_;
	cppVar_18949 = (cppVar_18948 & cppMask_un_5_);
	cppVar_18950 = cppVar_18949 + 32;
	cppVar_18950 = (cppVar_18950 & cppMask_un_8_);
	cppVar_18937 = cppVar_18950;
	}
	cppVar_18952 = (cppVar_18937 == 130);
	if (cppVar_18952) {
	cppVar_18936 = DPL;
	} else {
	cppVar_18955 = PC + 1;
	cppVar_18955 = (cppVar_18955 & cppMask_un_16_);
	cppVar_18956 = ROM.rd(cppVar_18955);
	cppVar_18957 = (cppVar_18956 >> 7) & cppMask_un_1_;
	cppVar_18958 = (cppVar_18957 == 1);
	if (cppVar_18958) {
	cppVar_18959 = PC + 1;
	cppVar_18959 = (cppVar_18959 & cppMask_un_16_);
	cppVar_18960 = ROM.rd(cppVar_18959);
	cppVar_18961 = (cppVar_18960 >> 3) & cppMask_un_5_;
	cppVar_18962 = (cppVar_18961 << 3) | 0;
	cppVar_18962 = (cppVar_18962 & cppMask_un_8_);
	cppVar_18954 = cppVar_18962;
	} else {
	cppVar_18963 = PC + 1;
	cppVar_18963 = (cppVar_18963 & cppMask_un_16_);
	cppVar_18964 = ROM.rd(cppVar_18963);
	cppVar_18965 = (cppVar_18964 >> 3) & cppMask_un_5_;
	cppVar_18966 = (cppVar_18965 & cppMask_un_5_);
	cppVar_18967 = cppVar_18966 + 32;
	cppVar_18967 = (cppVar_18967 & cppMask_un_8_);
	cppVar_18954 = cppVar_18967;
	}
	cppVar_18969 = (cppVar_18954 == 131);
	if (cppVar_18969) {
	cppVar_18953 = DPH;
	} else {
	cppVar_18972 = PC + 1;
	cppVar_18972 = (cppVar_18972 & cppMask_un_16_);
	cppVar_18973 = ROM.rd(cppVar_18972);
	cppVar_18974 = (cppVar_18973 >> 7) & cppMask_un_1_;
	cppVar_18975 = (cppVar_18974 == 1);
	if (cppVar_18975) {
	cppVar_18976 = PC + 1;
	cppVar_18976 = (cppVar_18976 & cppMask_un_16_);
	cppVar_18977 = ROM.rd(cppVar_18976);
	cppVar_18978 = (cppVar_18977 >> 3) & cppMask_un_5_;
	cppVar_18979 = (cppVar_18978 << 3) | 0;
	cppVar_18979 = (cppVar_18979 & cppMask_un_8_);
	cppVar_18971 = cppVar_18979;
	} else {
	cppVar_18980 = PC + 1;
	cppVar_18980 = (cppVar_18980 & cppMask_un_16_);
	cppVar_18981 = ROM.rd(cppVar_18980);
	cppVar_18982 = (cppVar_18981 >> 3) & cppMask_un_5_;
	cppVar_18983 = (cppVar_18982 & cppMask_un_5_);
	cppVar_18984 = cppVar_18983 + 32;
	cppVar_18984 = (cppVar_18984 & cppMask_un_8_);
	cppVar_18971 = cppVar_18984;
	}
	cppVar_18986 = (cppVar_18971 == 135);
	if (cppVar_18986) {
	cppVar_18970 = PCON;
	} else {
	cppVar_18989 = PC + 1;
	cppVar_18989 = (cppVar_18989 & cppMask_un_16_);
	cppVar_18990 = ROM.rd(cppVar_18989);
	cppVar_18991 = (cppVar_18990 >> 7) & cppMask_un_1_;
	cppVar_18992 = (cppVar_18991 == 1);
	if (cppVar_18992) {
	cppVar_18993 = PC + 1;
	cppVar_18993 = (cppVar_18993 & cppMask_un_16_);
	cppVar_18994 = ROM.rd(cppVar_18993);
	cppVar_18995 = (cppVar_18994 >> 3) & cppMask_un_5_;
	cppVar_18996 = (cppVar_18995 << 3) | 0;
	cppVar_18996 = (cppVar_18996 & cppMask_un_8_);
	cppVar_18988 = cppVar_18996;
	} else {
	cppVar_18997 = PC + 1;
	cppVar_18997 = (cppVar_18997 & cppMask_un_16_);
	cppVar_18998 = ROM.rd(cppVar_18997);
	cppVar_18999 = (cppVar_18998 >> 3) & cppMask_un_5_;
	cppVar_19000 = (cppVar_18999 & cppMask_un_5_);
	cppVar_19001 = cppVar_19000 + 32;
	cppVar_19001 = (cppVar_19001 & cppMask_un_8_);
	cppVar_18988 = cppVar_19001;
	}
	cppVar_19003 = (cppVar_18988 == 136);
	if (cppVar_19003) {
	cppVar_18987 = TCON;
	} else {
	cppVar_19006 = PC + 1;
	cppVar_19006 = (cppVar_19006 & cppMask_un_16_);
	cppVar_19007 = ROM.rd(cppVar_19006);
	cppVar_19008 = (cppVar_19007 >> 7) & cppMask_un_1_;
	cppVar_19009 = (cppVar_19008 == 1);
	if (cppVar_19009) {
	cppVar_19010 = PC + 1;
	cppVar_19010 = (cppVar_19010 & cppMask_un_16_);
	cppVar_19011 = ROM.rd(cppVar_19010);
	cppVar_19012 = (cppVar_19011 >> 3) & cppMask_un_5_;
	cppVar_19013 = (cppVar_19012 << 3) | 0;
	cppVar_19013 = (cppVar_19013 & cppMask_un_8_);
	cppVar_19005 = cppVar_19013;
	} else {
	cppVar_19014 = PC + 1;
	cppVar_19014 = (cppVar_19014 & cppMask_un_16_);
	cppVar_19015 = ROM.rd(cppVar_19014);
	cppVar_19016 = (cppVar_19015 >> 3) & cppMask_un_5_;
	cppVar_19017 = (cppVar_19016 & cppMask_un_5_);
	cppVar_19018 = cppVar_19017 + 32;
	cppVar_19018 = (cppVar_19018 & cppMask_un_8_);
	cppVar_19005 = cppVar_19018;
	}
	cppVar_19020 = (cppVar_19005 == 137);
	if (cppVar_19020) {
	cppVar_19004 = TMOD;
	} else {
	cppVar_19023 = PC + 1;
	cppVar_19023 = (cppVar_19023 & cppMask_un_16_);
	cppVar_19024 = ROM.rd(cppVar_19023);
	cppVar_19025 = (cppVar_19024 >> 7) & cppMask_un_1_;
	cppVar_19026 = (cppVar_19025 == 1);
	if (cppVar_19026) {
	cppVar_19027 = PC + 1;
	cppVar_19027 = (cppVar_19027 & cppMask_un_16_);
	cppVar_19028 = ROM.rd(cppVar_19027);
	cppVar_19029 = (cppVar_19028 >> 3) & cppMask_un_5_;
	cppVar_19030 = (cppVar_19029 << 3) | 0;
	cppVar_19030 = (cppVar_19030 & cppMask_un_8_);
	cppVar_19022 = cppVar_19030;
	} else {
	cppVar_19031 = PC + 1;
	cppVar_19031 = (cppVar_19031 & cppMask_un_16_);
	cppVar_19032 = ROM.rd(cppVar_19031);
	cppVar_19033 = (cppVar_19032 >> 3) & cppMask_un_5_;
	cppVar_19034 = (cppVar_19033 & cppMask_un_5_);
	cppVar_19035 = cppVar_19034 + 32;
	cppVar_19035 = (cppVar_19035 & cppMask_un_8_);
	cppVar_19022 = cppVar_19035;
	}
	cppVar_19037 = (cppVar_19022 == 138);
	if (cppVar_19037) {
	cppVar_19021 = TL0;
	} else {
	cppVar_19040 = PC + 1;
	cppVar_19040 = (cppVar_19040 & cppMask_un_16_);
	cppVar_19041 = ROM.rd(cppVar_19040);
	cppVar_19042 = (cppVar_19041 >> 7) & cppMask_un_1_;
	cppVar_19043 = (cppVar_19042 == 1);
	if (cppVar_19043) {
	cppVar_19044 = PC + 1;
	cppVar_19044 = (cppVar_19044 & cppMask_un_16_);
	cppVar_19045 = ROM.rd(cppVar_19044);
	cppVar_19046 = (cppVar_19045 >> 3) & cppMask_un_5_;
	cppVar_19047 = (cppVar_19046 << 3) | 0;
	cppVar_19047 = (cppVar_19047 & cppMask_un_8_);
	cppVar_19039 = cppVar_19047;
	} else {
	cppVar_19048 = PC + 1;
	cppVar_19048 = (cppVar_19048 & cppMask_un_16_);
	cppVar_19049 = ROM.rd(cppVar_19048);
	cppVar_19050 = (cppVar_19049 >> 3) & cppMask_un_5_;
	cppVar_19051 = (cppVar_19050 & cppMask_un_5_);
	cppVar_19052 = cppVar_19051 + 32;
	cppVar_19052 = (cppVar_19052 & cppMask_un_8_);
	cppVar_19039 = cppVar_19052;
	}
	cppVar_19054 = (cppVar_19039 == 140);
	if (cppVar_19054) {
	cppVar_19038 = TH0;
	} else {
	cppVar_19057 = PC + 1;
	cppVar_19057 = (cppVar_19057 & cppMask_un_16_);
	cppVar_19058 = ROM.rd(cppVar_19057);
	cppVar_19059 = (cppVar_19058 >> 7) & cppMask_un_1_;
	cppVar_19060 = (cppVar_19059 == 1);
	if (cppVar_19060) {
	cppVar_19061 = PC + 1;
	cppVar_19061 = (cppVar_19061 & cppMask_un_16_);
	cppVar_19062 = ROM.rd(cppVar_19061);
	cppVar_19063 = (cppVar_19062 >> 3) & cppMask_un_5_;
	cppVar_19064 = (cppVar_19063 << 3) | 0;
	cppVar_19064 = (cppVar_19064 & cppMask_un_8_);
	cppVar_19056 = cppVar_19064;
	} else {
	cppVar_19065 = PC + 1;
	cppVar_19065 = (cppVar_19065 & cppMask_un_16_);
	cppVar_19066 = ROM.rd(cppVar_19065);
	cppVar_19067 = (cppVar_19066 >> 3) & cppMask_un_5_;
	cppVar_19068 = (cppVar_19067 & cppMask_un_5_);
	cppVar_19069 = cppVar_19068 + 32;
	cppVar_19069 = (cppVar_19069 & cppMask_un_8_);
	cppVar_19056 = cppVar_19069;
	}
	cppVar_19071 = (cppVar_19056 == 139);
	if (cppVar_19071) {
	cppVar_19055 = TL1;
	} else {
	cppVar_19074 = PC + 1;
	cppVar_19074 = (cppVar_19074 & cppMask_un_16_);
	cppVar_19075 = ROM.rd(cppVar_19074);
	cppVar_19076 = (cppVar_19075 >> 7) & cppMask_un_1_;
	cppVar_19077 = (cppVar_19076 == 1);
	if (cppVar_19077) {
	cppVar_19078 = PC + 1;
	cppVar_19078 = (cppVar_19078 & cppMask_un_16_);
	cppVar_19079 = ROM.rd(cppVar_19078);
	cppVar_19080 = (cppVar_19079 >> 3) & cppMask_un_5_;
	cppVar_19081 = (cppVar_19080 << 3) | 0;
	cppVar_19081 = (cppVar_19081 & cppMask_un_8_);
	cppVar_19073 = cppVar_19081;
	} else {
	cppVar_19082 = PC + 1;
	cppVar_19082 = (cppVar_19082 & cppMask_un_16_);
	cppVar_19083 = ROM.rd(cppVar_19082);
	cppVar_19084 = (cppVar_19083 >> 3) & cppMask_un_5_;
	cppVar_19085 = (cppVar_19084 & cppMask_un_5_);
	cppVar_19086 = cppVar_19085 + 32;
	cppVar_19086 = (cppVar_19086 & cppMask_un_8_);
	cppVar_19073 = cppVar_19086;
	}
	cppVar_19088 = (cppVar_19073 == 141);
	if (cppVar_19088) {
	cppVar_19072 = TH1;
	} else {
	cppVar_19091 = PC + 1;
	cppVar_19091 = (cppVar_19091 & cppMask_un_16_);
	cppVar_19092 = ROM.rd(cppVar_19091);
	cppVar_19093 = (cppVar_19092 >> 7) & cppMask_un_1_;
	cppVar_19094 = (cppVar_19093 == 1);
	if (cppVar_19094) {
	cppVar_19095 = PC + 1;
	cppVar_19095 = (cppVar_19095 & cppMask_un_16_);
	cppVar_19096 = ROM.rd(cppVar_19095);
	cppVar_19097 = (cppVar_19096 >> 3) & cppMask_un_5_;
	cppVar_19098 = (cppVar_19097 << 3) | 0;
	cppVar_19098 = (cppVar_19098 & cppMask_un_8_);
	cppVar_19090 = cppVar_19098;
	} else {
	cppVar_19099 = PC + 1;
	cppVar_19099 = (cppVar_19099 & cppMask_un_16_);
	cppVar_19100 = ROM.rd(cppVar_19099);
	cppVar_19101 = (cppVar_19100 >> 3) & cppMask_un_5_;
	cppVar_19102 = (cppVar_19101 & cppMask_un_5_);
	cppVar_19103 = cppVar_19102 + 32;
	cppVar_19103 = (cppVar_19103 & cppMask_un_8_);
	cppVar_19090 = cppVar_19103;
	}
	cppVar_19105 = (cppVar_19090 == 144);
	if (cppVar_19105) {
	cppVar_19089 = P1;
	} else {
	cppVar_19108 = PC + 1;
	cppVar_19108 = (cppVar_19108 & cppMask_un_16_);
	cppVar_19109 = ROM.rd(cppVar_19108);
	cppVar_19110 = (cppVar_19109 >> 7) & cppMask_un_1_;
	cppVar_19111 = (cppVar_19110 == 1);
	if (cppVar_19111) {
	cppVar_19112 = PC + 1;
	cppVar_19112 = (cppVar_19112 & cppMask_un_16_);
	cppVar_19113 = ROM.rd(cppVar_19112);
	cppVar_19114 = (cppVar_19113 >> 3) & cppMask_un_5_;
	cppVar_19115 = (cppVar_19114 << 3) | 0;
	cppVar_19115 = (cppVar_19115 & cppMask_un_8_);
	cppVar_19107 = cppVar_19115;
	} else {
	cppVar_19116 = PC + 1;
	cppVar_19116 = (cppVar_19116 & cppMask_un_16_);
	cppVar_19117 = ROM.rd(cppVar_19116);
	cppVar_19118 = (cppVar_19117 >> 3) & cppMask_un_5_;
	cppVar_19119 = (cppVar_19118 & cppMask_un_5_);
	cppVar_19120 = cppVar_19119 + 32;
	cppVar_19120 = (cppVar_19120 & cppMask_un_8_);
	cppVar_19107 = cppVar_19120;
	}
	cppVar_19122 = (cppVar_19107 == 152);
	if (cppVar_19122) {
	cppVar_19106 = SCON;
	} else {
	cppVar_19125 = PC + 1;
	cppVar_19125 = (cppVar_19125 & cppMask_un_16_);
	cppVar_19126 = ROM.rd(cppVar_19125);
	cppVar_19127 = (cppVar_19126 >> 7) & cppMask_un_1_;
	cppVar_19128 = (cppVar_19127 == 1);
	if (cppVar_19128) {
	cppVar_19129 = PC + 1;
	cppVar_19129 = (cppVar_19129 & cppMask_un_16_);
	cppVar_19130 = ROM.rd(cppVar_19129);
	cppVar_19131 = (cppVar_19130 >> 3) & cppMask_un_5_;
	cppVar_19132 = (cppVar_19131 << 3) | 0;
	cppVar_19132 = (cppVar_19132 & cppMask_un_8_);
	cppVar_19124 = cppVar_19132;
	} else {
	cppVar_19133 = PC + 1;
	cppVar_19133 = (cppVar_19133 & cppMask_un_16_);
	cppVar_19134 = ROM.rd(cppVar_19133);
	cppVar_19135 = (cppVar_19134 >> 3) & cppMask_un_5_;
	cppVar_19136 = (cppVar_19135 & cppMask_un_5_);
	cppVar_19137 = cppVar_19136 + 32;
	cppVar_19137 = (cppVar_19137 & cppMask_un_8_);
	cppVar_19124 = cppVar_19137;
	}
	cppVar_19139 = (cppVar_19124 == 153);
	if (cppVar_19139) {
	cppVar_19123 = SBUF;
	} else {
	cppVar_19142 = PC + 1;
	cppVar_19142 = (cppVar_19142 & cppMask_un_16_);
	cppVar_19143 = ROM.rd(cppVar_19142);
	cppVar_19144 = (cppVar_19143 >> 7) & cppMask_un_1_;
	cppVar_19145 = (cppVar_19144 == 1);
	if (cppVar_19145) {
	cppVar_19146 = PC + 1;
	cppVar_19146 = (cppVar_19146 & cppMask_un_16_);
	cppVar_19147 = ROM.rd(cppVar_19146);
	cppVar_19148 = (cppVar_19147 >> 3) & cppMask_un_5_;
	cppVar_19149 = (cppVar_19148 << 3) | 0;
	cppVar_19149 = (cppVar_19149 & cppMask_un_8_);
	cppVar_19141 = cppVar_19149;
	} else {
	cppVar_19150 = PC + 1;
	cppVar_19150 = (cppVar_19150 & cppMask_un_16_);
	cppVar_19151 = ROM.rd(cppVar_19150);
	cppVar_19152 = (cppVar_19151 >> 3) & cppMask_un_5_;
	cppVar_19153 = (cppVar_19152 & cppMask_un_5_);
	cppVar_19154 = cppVar_19153 + 32;
	cppVar_19154 = (cppVar_19154 & cppMask_un_8_);
	cppVar_19141 = cppVar_19154;
	}
	cppVar_19156 = (cppVar_19141 == 160);
	if (cppVar_19156) {
	cppVar_19140 = P2;
	} else {
	cppVar_19159 = PC + 1;
	cppVar_19159 = (cppVar_19159 & cppMask_un_16_);
	cppVar_19160 = ROM.rd(cppVar_19159);
	cppVar_19161 = (cppVar_19160 >> 7) & cppMask_un_1_;
	cppVar_19162 = (cppVar_19161 == 1);
	if (cppVar_19162) {
	cppVar_19163 = PC + 1;
	cppVar_19163 = (cppVar_19163 & cppMask_un_16_);
	cppVar_19164 = ROM.rd(cppVar_19163);
	cppVar_19165 = (cppVar_19164 >> 3) & cppMask_un_5_;
	cppVar_19166 = (cppVar_19165 << 3) | 0;
	cppVar_19166 = (cppVar_19166 & cppMask_un_8_);
	cppVar_19158 = cppVar_19166;
	} else {
	cppVar_19167 = PC + 1;
	cppVar_19167 = (cppVar_19167 & cppMask_un_16_);
	cppVar_19168 = ROM.rd(cppVar_19167);
	cppVar_19169 = (cppVar_19168 >> 3) & cppMask_un_5_;
	cppVar_19170 = (cppVar_19169 & cppMask_un_5_);
	cppVar_19171 = cppVar_19170 + 32;
	cppVar_19171 = (cppVar_19171 & cppMask_un_8_);
	cppVar_19158 = cppVar_19171;
	}
	cppVar_19173 = (cppVar_19158 == 168);
	if (cppVar_19173) {
	cppVar_19157 = IE;
	} else {
	cppVar_19176 = PC + 1;
	cppVar_19176 = (cppVar_19176 & cppMask_un_16_);
	cppVar_19177 = ROM.rd(cppVar_19176);
	cppVar_19178 = (cppVar_19177 >> 7) & cppMask_un_1_;
	cppVar_19179 = (cppVar_19178 == 1);
	if (cppVar_19179) {
	cppVar_19180 = PC + 1;
	cppVar_19180 = (cppVar_19180 & cppMask_un_16_);
	cppVar_19181 = ROM.rd(cppVar_19180);
	cppVar_19182 = (cppVar_19181 >> 3) & cppMask_un_5_;
	cppVar_19183 = (cppVar_19182 << 3) | 0;
	cppVar_19183 = (cppVar_19183 & cppMask_un_8_);
	cppVar_19175 = cppVar_19183;
	} else {
	cppVar_19184 = PC + 1;
	cppVar_19184 = (cppVar_19184 & cppMask_un_16_);
	cppVar_19185 = ROM.rd(cppVar_19184);
	cppVar_19186 = (cppVar_19185 >> 3) & cppMask_un_5_;
	cppVar_19187 = (cppVar_19186 & cppMask_un_5_);
	cppVar_19188 = cppVar_19187 + 32;
	cppVar_19188 = (cppVar_19188 & cppMask_un_8_);
	cppVar_19175 = cppVar_19188;
	}
	cppVar_19190 = (cppVar_19175 == 176);
	if (cppVar_19190) {
	cppVar_19174 = P3;
	} else {
	cppVar_19193 = PC + 1;
	cppVar_19193 = (cppVar_19193 & cppMask_un_16_);
	cppVar_19194 = ROM.rd(cppVar_19193);
	cppVar_19195 = (cppVar_19194 >> 7) & cppMask_un_1_;
	cppVar_19196 = (cppVar_19195 == 1);
	if (cppVar_19196) {
	cppVar_19197 = PC + 1;
	cppVar_19197 = (cppVar_19197 & cppMask_un_16_);
	cppVar_19198 = ROM.rd(cppVar_19197);
	cppVar_19199 = (cppVar_19198 >> 3) & cppMask_un_5_;
	cppVar_19200 = (cppVar_19199 << 3) | 0;
	cppVar_19200 = (cppVar_19200 & cppMask_un_8_);
	cppVar_19192 = cppVar_19200;
	} else {
	cppVar_19201 = PC + 1;
	cppVar_19201 = (cppVar_19201 & cppMask_un_16_);
	cppVar_19202 = ROM.rd(cppVar_19201);
	cppVar_19203 = (cppVar_19202 >> 3) & cppMask_un_5_;
	cppVar_19204 = (cppVar_19203 & cppMask_un_5_);
	cppVar_19205 = cppVar_19204 + 32;
	cppVar_19205 = (cppVar_19205 & cppMask_un_8_);
	cppVar_19192 = cppVar_19205;
	}
	cppVar_19207 = (cppVar_19192 == 184);
	if (cppVar_19207) {
	cppVar_19191 = IP;
	} else {
	cppVar_19210 = PC + 1;
	cppVar_19210 = (cppVar_19210 & cppMask_un_16_);
	cppVar_19211 = ROM.rd(cppVar_19210);
	cppVar_19212 = (cppVar_19211 >> 7) & cppMask_un_1_;
	cppVar_19213 = (cppVar_19212 == 1);
	if (cppVar_19213) {
	cppVar_19214 = PC + 1;
	cppVar_19214 = (cppVar_19214 & cppMask_un_16_);
	cppVar_19215 = ROM.rd(cppVar_19214);
	cppVar_19216 = (cppVar_19215 >> 3) & cppMask_un_5_;
	cppVar_19217 = (cppVar_19216 << 3) | 0;
	cppVar_19217 = (cppVar_19217 & cppMask_un_8_);
	cppVar_19209 = cppVar_19217;
	} else {
	cppVar_19218 = PC + 1;
	cppVar_19218 = (cppVar_19218 & cppMask_un_16_);
	cppVar_19219 = ROM.rd(cppVar_19218);
	cppVar_19220 = (cppVar_19219 >> 3) & cppMask_un_5_;
	cppVar_19221 = (cppVar_19220 & cppMask_un_5_);
	cppVar_19222 = cppVar_19221 + 32;
	cppVar_19222 = (cppVar_19222 & cppMask_un_8_);
	cppVar_19209 = cppVar_19222;
	}
	cppVar_19224 = (cppVar_19209 == 208);
	if (cppVar_19224) {
	cppVar_19208 = PSW;
	} else {
	cppVar_19227 = PC + 1;
	cppVar_19227 = (cppVar_19227 & cppMask_un_16_);
	cppVar_19228 = ROM.rd(cppVar_19227);
	cppVar_19229 = (cppVar_19228 >> 7) & cppMask_un_1_;
	cppVar_19230 = (cppVar_19229 == 1);
	if (cppVar_19230) {
	cppVar_19231 = PC + 1;
	cppVar_19231 = (cppVar_19231 & cppMask_un_16_);
	cppVar_19232 = ROM.rd(cppVar_19231);
	cppVar_19233 = (cppVar_19232 >> 3) & cppMask_un_5_;
	cppVar_19234 = (cppVar_19233 << 3) | 0;
	cppVar_19234 = (cppVar_19234 & cppMask_un_8_);
	cppVar_19226 = cppVar_19234;
	} else {
	cppVar_19235 = PC + 1;
	cppVar_19235 = (cppVar_19235 & cppMask_un_16_);
	cppVar_19236 = ROM.rd(cppVar_19235);
	cppVar_19237 = (cppVar_19236 >> 3) & cppMask_un_5_;
	cppVar_19238 = (cppVar_19237 & cppMask_un_5_);
	cppVar_19239 = cppVar_19238 + 32;
	cppVar_19239 = (cppVar_19239 & cppMask_un_8_);
	cppVar_19226 = cppVar_19239;
	}
	cppVar_19241 = (cppVar_19226 == 224);
	if (cppVar_19241) {
	cppVar_19225 = ACC;
	} else {
	cppVar_19244 = PC + 1;
	cppVar_19244 = (cppVar_19244 & cppMask_un_16_);
	cppVar_19245 = ROM.rd(cppVar_19244);
	cppVar_19246 = (cppVar_19245 >> 7) & cppMask_un_1_;
	cppVar_19247 = (cppVar_19246 == 1);
	if (cppVar_19247) {
	cppVar_19248 = PC + 1;
	cppVar_19248 = (cppVar_19248 & cppMask_un_16_);
	cppVar_19249 = ROM.rd(cppVar_19248);
	cppVar_19250 = (cppVar_19249 >> 3) & cppMask_un_5_;
	cppVar_19251 = (cppVar_19250 << 3) | 0;
	cppVar_19251 = (cppVar_19251 & cppMask_un_8_);
	cppVar_19243 = cppVar_19251;
	} else {
	cppVar_19252 = PC + 1;
	cppVar_19252 = (cppVar_19252 & cppMask_un_16_);
	cppVar_19253 = ROM.rd(cppVar_19252);
	cppVar_19254 = (cppVar_19253 >> 3) & cppMask_un_5_;
	cppVar_19255 = (cppVar_19254 & cppMask_un_5_);
	cppVar_19256 = cppVar_19255 + 32;
	cppVar_19256 = (cppVar_19256 & cppMask_un_8_);
	cppVar_19243 = cppVar_19256;
	}
	cppVar_19258 = (cppVar_19243 == 240);
	if (cppVar_19258) {
	cppVar_19242 = B;
	} else {
	cppVar_19242 = 0;
	}
	cppVar_19225 = cppVar_19242;
	}
	cppVar_19208 = cppVar_19225;
	}
	cppVar_19191 = cppVar_19208;
	}
	cppVar_19174 = cppVar_19191;
	}
	cppVar_19157 = cppVar_19174;
	}
	cppVar_19140 = cppVar_19157;
	}
	cppVar_19123 = cppVar_19140;
	}
	cppVar_19106 = cppVar_19123;
	}
	cppVar_19089 = cppVar_19106;
	}
	cppVar_19072 = cppVar_19089;
	}
	cppVar_19055 = cppVar_19072;
	}
	cppVar_19038 = cppVar_19055;
	}
	cppVar_19021 = cppVar_19038;
	}
	cppVar_19004 = cppVar_19021;
	}
	cppVar_18987 = cppVar_19004;
	}
	cppVar_18970 = cppVar_18987;
	}
	cppVar_18953 = cppVar_18970;
	}
	cppVar_18936 = cppVar_18953;
	}
	cppVar_18919 = cppVar_18936;
	}
	cppVar_18902 = cppVar_18919;
	}
	cppVar_18866 = cppVar_18902;
	}
	cppVar_19260 = PC + 1;
	cppVar_19260 = (cppVar_19260 & cppMask_un_16_);
	cppVar_19261 = ROM.rd(cppVar_19260);
	cppVar_19262 = (cppVar_19261 >> 0) & cppMask_un_3_;
	cppVar_19263 = (cppVar_18866 >> static_cast<unsigned>(cppVar_19262)) & 0x1;
	cppVar_19264 = ~cppVar_19263;
	cppVar_19265 = (cppVar_19264 & cppMask_un_1_);
	cppVar_19266 = PC + 1;
	cppVar_19266 = (cppVar_19266 & cppMask_un_16_);
	cppVar_19267 = ROM.rd(cppVar_19266);
	cppVar_19268 = (cppVar_19267 >> 0) & cppMask_un_3_;
	cppVar_19269 = (cppVar_19268 & cppMask_un_3_);
	cppVar_19270 = cppVar_19265 << static_cast<unsigned>(cppVar_19269);
	cppVar_19270 = (cppVar_19270 & cppMask_un_8_);
	cppVar_19271 = cppVar_18865 | cppVar_19270;
	cppVar_18446 = cppVar_19271;
	} else {
	cppVar_18446 = IP;
	}
	cppVar_18442 = cppVar_18446;
	} else {
	cppVar_19273 = ROM.rd(PC);
	cppVar_19275 = (cppVar_19273 == 146);
	if (cppVar_19275) {
	cppVar_19279 = PC + 1;
	cppVar_19279 = (cppVar_19279 & cppMask_un_16_);
	cppVar_19280 = ROM.rd(cppVar_19279);
	cppVar_19281 = (cppVar_19280 >> 7) & cppMask_un_1_;
	cppVar_19283 = (cppVar_19281 == 1);
	if (cppVar_19283) {
	cppVar_19284 = PC + 1;
	cppVar_19284 = (cppVar_19284 & cppMask_un_16_);
	cppVar_19285 = ROM.rd(cppVar_19284);
	cppVar_19286 = (cppVar_19285 >> 3) & cppMask_un_5_;
	cppVar_19288 = (cppVar_19286 << 3) | 0;
	cppVar_19288 = (cppVar_19288 & cppMask_un_8_);
	cppVar_19277 = cppVar_19288;
	} else {
	cppVar_19289 = PC + 1;
	cppVar_19289 = (cppVar_19289 & cppMask_un_16_);
	cppVar_19290 = ROM.rd(cppVar_19289);
	cppVar_19291 = (cppVar_19290 >> 3) & cppMask_un_5_;
	cppVar_19292 = (cppVar_19291 & cppMask_un_5_);
	cppVar_19294 = cppVar_19292 + 32;
	cppVar_19294 = (cppVar_19294 & cppMask_un_8_);
	cppVar_19277 = cppVar_19294;
	}
	cppVar_19296 = (cppVar_19277 == 184);
	if (cppVar_19296) {
	cppVar_19298 = PC + 1;
	cppVar_19298 = (cppVar_19298 & cppMask_un_16_);
	cppVar_19299 = ROM.rd(cppVar_19298);
	cppVar_19300 = (cppVar_19299 >> 0) & cppMask_un_3_;
	cppVar_19301 = (cppVar_19300 & cppMask_un_3_);
	cppVar_19302 = 1 << static_cast<unsigned>(cppVar_19301);
	cppVar_19302 = (cppVar_19302 & cppMask_un_8_);
	cppVar_19303 = ~cppVar_19302;
	cppVar_19306 = PC + 1;
	cppVar_19306 = (cppVar_19306 & cppMask_un_16_);
	cppVar_19307 = ROM.rd(cppVar_19306);
	cppVar_19308 = (cppVar_19307 >> 7) & cppMask_un_1_;
	cppVar_19309 = (cppVar_19308 == 1);
	if (cppVar_19309) {
	cppVar_19310 = PC + 1;
	cppVar_19310 = (cppVar_19310 & cppMask_un_16_);
	cppVar_19311 = ROM.rd(cppVar_19310);
	cppVar_19312 = (cppVar_19311 >> 3) & cppMask_un_5_;
	cppVar_19313 = (cppVar_19312 << 3) | 0;
	cppVar_19313 = (cppVar_19313 & cppMask_un_8_);
	cppVar_19305 = cppVar_19313;
	} else {
	cppVar_19314 = PC + 1;
	cppVar_19314 = (cppVar_19314 & cppMask_un_16_);
	cppVar_19315 = ROM.rd(cppVar_19314);
	cppVar_19316 = (cppVar_19315 >> 3) & cppMask_un_5_;
	cppVar_19317 = (cppVar_19316 & cppMask_un_5_);
	cppVar_19318 = cppVar_19317 + 32;
	cppVar_19318 = (cppVar_19318 & cppMask_un_8_);
	cppVar_19305 = cppVar_19318;
	}
	cppVar_19319 = (cppVar_19305 >> 7) & cppMask_un_1_;
	cppVar_19321 = (cppVar_19319 == 0);
	if (cppVar_19321) {
	cppVar_19323 = PC + 1;
	cppVar_19323 = (cppVar_19323 & cppMask_un_16_);
	cppVar_19324 = ROM.rd(cppVar_19323);
	cppVar_19325 = (cppVar_19324 >> 7) & cppMask_un_1_;
	cppVar_19326 = (cppVar_19325 == 1);
	if (cppVar_19326) {
	cppVar_19327 = PC + 1;
	cppVar_19327 = (cppVar_19327 & cppMask_un_16_);
	cppVar_19328 = ROM.rd(cppVar_19327);
	cppVar_19329 = (cppVar_19328 >> 3) & cppMask_un_5_;
	cppVar_19330 = (cppVar_19329 << 3) | 0;
	cppVar_19330 = (cppVar_19330 & cppMask_un_8_);
	cppVar_19322 = cppVar_19330;
	} else {
	cppVar_19331 = PC + 1;
	cppVar_19331 = (cppVar_19331 & cppMask_un_16_);
	cppVar_19332 = ROM.rd(cppVar_19331);
	cppVar_19333 = (cppVar_19332 >> 3) & cppMask_un_5_;
	cppVar_19334 = (cppVar_19333 & cppMask_un_5_);
	cppVar_19335 = cppVar_19334 + 32;
	cppVar_19335 = (cppVar_19335 & cppMask_un_8_);
	cppVar_19322 = cppVar_19335;
	}
	cppVar_19336 = IRAM.rd(cppVar_19322);
	cppVar_19304 = cppVar_19336;
	} else {
	cppVar_19339 = PC + 1;
	cppVar_19339 = (cppVar_19339 & cppMask_un_16_);
	cppVar_19340 = ROM.rd(cppVar_19339);
	cppVar_19341 = (cppVar_19340 >> 7) & cppMask_un_1_;
	cppVar_19342 = (cppVar_19341 == 1);
	if (cppVar_19342) {
	cppVar_19343 = PC + 1;
	cppVar_19343 = (cppVar_19343 & cppMask_un_16_);
	cppVar_19344 = ROM.rd(cppVar_19343);
	cppVar_19345 = (cppVar_19344 >> 3) & cppMask_un_5_;
	cppVar_19346 = (cppVar_19345 << 3) | 0;
	cppVar_19346 = (cppVar_19346 & cppMask_un_8_);
	cppVar_19338 = cppVar_19346;
	} else {
	cppVar_19347 = PC + 1;
	cppVar_19347 = (cppVar_19347 & cppMask_un_16_);
	cppVar_19348 = ROM.rd(cppVar_19347);
	cppVar_19349 = (cppVar_19348 >> 3) & cppMask_un_5_;
	cppVar_19350 = (cppVar_19349 & cppMask_un_5_);
	cppVar_19351 = cppVar_19350 + 32;
	cppVar_19351 = (cppVar_19351 & cppMask_un_8_);
	cppVar_19338 = cppVar_19351;
	}
	cppVar_19353 = (cppVar_19338 == 128);
	if (cppVar_19353) {
	cppVar_19337 = P0;
	} else {
	cppVar_19356 = PC + 1;
	cppVar_19356 = (cppVar_19356 & cppMask_un_16_);
	cppVar_19357 = ROM.rd(cppVar_19356);
	cppVar_19358 = (cppVar_19357 >> 7) & cppMask_un_1_;
	cppVar_19359 = (cppVar_19358 == 1);
	if (cppVar_19359) {
	cppVar_19360 = PC + 1;
	cppVar_19360 = (cppVar_19360 & cppMask_un_16_);
	cppVar_19361 = ROM.rd(cppVar_19360);
	cppVar_19362 = (cppVar_19361 >> 3) & cppMask_un_5_;
	cppVar_19363 = (cppVar_19362 << 3) | 0;
	cppVar_19363 = (cppVar_19363 & cppMask_un_8_);
	cppVar_19355 = cppVar_19363;
	} else {
	cppVar_19364 = PC + 1;
	cppVar_19364 = (cppVar_19364 & cppMask_un_16_);
	cppVar_19365 = ROM.rd(cppVar_19364);
	cppVar_19366 = (cppVar_19365 >> 3) & cppMask_un_5_;
	cppVar_19367 = (cppVar_19366 & cppMask_un_5_);
	cppVar_19368 = cppVar_19367 + 32;
	cppVar_19368 = (cppVar_19368 & cppMask_un_8_);
	cppVar_19355 = cppVar_19368;
	}
	cppVar_19370 = (cppVar_19355 == 129);
	if (cppVar_19370) {
	cppVar_19354 = SP;
	} else {
	cppVar_19373 = PC + 1;
	cppVar_19373 = (cppVar_19373 & cppMask_un_16_);
	cppVar_19374 = ROM.rd(cppVar_19373);
	cppVar_19375 = (cppVar_19374 >> 7) & cppMask_un_1_;
	cppVar_19376 = (cppVar_19375 == 1);
	if (cppVar_19376) {
	cppVar_19377 = PC + 1;
	cppVar_19377 = (cppVar_19377 & cppMask_un_16_);
	cppVar_19378 = ROM.rd(cppVar_19377);
	cppVar_19379 = (cppVar_19378 >> 3) & cppMask_un_5_;
	cppVar_19380 = (cppVar_19379 << 3) | 0;
	cppVar_19380 = (cppVar_19380 & cppMask_un_8_);
	cppVar_19372 = cppVar_19380;
	} else {
	cppVar_19381 = PC + 1;
	cppVar_19381 = (cppVar_19381 & cppMask_un_16_);
	cppVar_19382 = ROM.rd(cppVar_19381);
	cppVar_19383 = (cppVar_19382 >> 3) & cppMask_un_5_;
	cppVar_19384 = (cppVar_19383 & cppMask_un_5_);
	cppVar_19385 = cppVar_19384 + 32;
	cppVar_19385 = (cppVar_19385 & cppMask_un_8_);
	cppVar_19372 = cppVar_19385;
	}
	cppVar_19387 = (cppVar_19372 == 130);
	if (cppVar_19387) {
	cppVar_19371 = DPL;
	} else {
	cppVar_19390 = PC + 1;
	cppVar_19390 = (cppVar_19390 & cppMask_un_16_);
	cppVar_19391 = ROM.rd(cppVar_19390);
	cppVar_19392 = (cppVar_19391 >> 7) & cppMask_un_1_;
	cppVar_19393 = (cppVar_19392 == 1);
	if (cppVar_19393) {
	cppVar_19394 = PC + 1;
	cppVar_19394 = (cppVar_19394 & cppMask_un_16_);
	cppVar_19395 = ROM.rd(cppVar_19394);
	cppVar_19396 = (cppVar_19395 >> 3) & cppMask_un_5_;
	cppVar_19397 = (cppVar_19396 << 3) | 0;
	cppVar_19397 = (cppVar_19397 & cppMask_un_8_);
	cppVar_19389 = cppVar_19397;
	} else {
	cppVar_19398 = PC + 1;
	cppVar_19398 = (cppVar_19398 & cppMask_un_16_);
	cppVar_19399 = ROM.rd(cppVar_19398);
	cppVar_19400 = (cppVar_19399 >> 3) & cppMask_un_5_;
	cppVar_19401 = (cppVar_19400 & cppMask_un_5_);
	cppVar_19402 = cppVar_19401 + 32;
	cppVar_19402 = (cppVar_19402 & cppMask_un_8_);
	cppVar_19389 = cppVar_19402;
	}
	cppVar_19404 = (cppVar_19389 == 131);
	if (cppVar_19404) {
	cppVar_19388 = DPH;
	} else {
	cppVar_19407 = PC + 1;
	cppVar_19407 = (cppVar_19407 & cppMask_un_16_);
	cppVar_19408 = ROM.rd(cppVar_19407);
	cppVar_19409 = (cppVar_19408 >> 7) & cppMask_un_1_;
	cppVar_19410 = (cppVar_19409 == 1);
	if (cppVar_19410) {
	cppVar_19411 = PC + 1;
	cppVar_19411 = (cppVar_19411 & cppMask_un_16_);
	cppVar_19412 = ROM.rd(cppVar_19411);
	cppVar_19413 = (cppVar_19412 >> 3) & cppMask_un_5_;
	cppVar_19414 = (cppVar_19413 << 3) | 0;
	cppVar_19414 = (cppVar_19414 & cppMask_un_8_);
	cppVar_19406 = cppVar_19414;
	} else {
	cppVar_19415 = PC + 1;
	cppVar_19415 = (cppVar_19415 & cppMask_un_16_);
	cppVar_19416 = ROM.rd(cppVar_19415);
	cppVar_19417 = (cppVar_19416 >> 3) & cppMask_un_5_;
	cppVar_19418 = (cppVar_19417 & cppMask_un_5_);
	cppVar_19419 = cppVar_19418 + 32;
	cppVar_19419 = (cppVar_19419 & cppMask_un_8_);
	cppVar_19406 = cppVar_19419;
	}
	cppVar_19421 = (cppVar_19406 == 135);
	if (cppVar_19421) {
	cppVar_19405 = PCON;
	} else {
	cppVar_19424 = PC + 1;
	cppVar_19424 = (cppVar_19424 & cppMask_un_16_);
	cppVar_19425 = ROM.rd(cppVar_19424);
	cppVar_19426 = (cppVar_19425 >> 7) & cppMask_un_1_;
	cppVar_19427 = (cppVar_19426 == 1);
	if (cppVar_19427) {
	cppVar_19428 = PC + 1;
	cppVar_19428 = (cppVar_19428 & cppMask_un_16_);
	cppVar_19429 = ROM.rd(cppVar_19428);
	cppVar_19430 = (cppVar_19429 >> 3) & cppMask_un_5_;
	cppVar_19431 = (cppVar_19430 << 3) | 0;
	cppVar_19431 = (cppVar_19431 & cppMask_un_8_);
	cppVar_19423 = cppVar_19431;
	} else {
	cppVar_19432 = PC + 1;
	cppVar_19432 = (cppVar_19432 & cppMask_un_16_);
	cppVar_19433 = ROM.rd(cppVar_19432);
	cppVar_19434 = (cppVar_19433 >> 3) & cppMask_un_5_;
	cppVar_19435 = (cppVar_19434 & cppMask_un_5_);
	cppVar_19436 = cppVar_19435 + 32;
	cppVar_19436 = (cppVar_19436 & cppMask_un_8_);
	cppVar_19423 = cppVar_19436;
	}
	cppVar_19438 = (cppVar_19423 == 136);
	if (cppVar_19438) {
	cppVar_19422 = TCON;
	} else {
	cppVar_19441 = PC + 1;
	cppVar_19441 = (cppVar_19441 & cppMask_un_16_);
	cppVar_19442 = ROM.rd(cppVar_19441);
	cppVar_19443 = (cppVar_19442 >> 7) & cppMask_un_1_;
	cppVar_19444 = (cppVar_19443 == 1);
	if (cppVar_19444) {
	cppVar_19445 = PC + 1;
	cppVar_19445 = (cppVar_19445 & cppMask_un_16_);
	cppVar_19446 = ROM.rd(cppVar_19445);
	cppVar_19447 = (cppVar_19446 >> 3) & cppMask_un_5_;
	cppVar_19448 = (cppVar_19447 << 3) | 0;
	cppVar_19448 = (cppVar_19448 & cppMask_un_8_);
	cppVar_19440 = cppVar_19448;
	} else {
	cppVar_19449 = PC + 1;
	cppVar_19449 = (cppVar_19449 & cppMask_un_16_);
	cppVar_19450 = ROM.rd(cppVar_19449);
	cppVar_19451 = (cppVar_19450 >> 3) & cppMask_un_5_;
	cppVar_19452 = (cppVar_19451 & cppMask_un_5_);
	cppVar_19453 = cppVar_19452 + 32;
	cppVar_19453 = (cppVar_19453 & cppMask_un_8_);
	cppVar_19440 = cppVar_19453;
	}
	cppVar_19455 = (cppVar_19440 == 137);
	if (cppVar_19455) {
	cppVar_19439 = TMOD;
	} else {
	cppVar_19458 = PC + 1;
	cppVar_19458 = (cppVar_19458 & cppMask_un_16_);
	cppVar_19459 = ROM.rd(cppVar_19458);
	cppVar_19460 = (cppVar_19459 >> 7) & cppMask_un_1_;
	cppVar_19461 = (cppVar_19460 == 1);
	if (cppVar_19461) {
	cppVar_19462 = PC + 1;
	cppVar_19462 = (cppVar_19462 & cppMask_un_16_);
	cppVar_19463 = ROM.rd(cppVar_19462);
	cppVar_19464 = (cppVar_19463 >> 3) & cppMask_un_5_;
	cppVar_19465 = (cppVar_19464 << 3) | 0;
	cppVar_19465 = (cppVar_19465 & cppMask_un_8_);
	cppVar_19457 = cppVar_19465;
	} else {
	cppVar_19466 = PC + 1;
	cppVar_19466 = (cppVar_19466 & cppMask_un_16_);
	cppVar_19467 = ROM.rd(cppVar_19466);
	cppVar_19468 = (cppVar_19467 >> 3) & cppMask_un_5_;
	cppVar_19469 = (cppVar_19468 & cppMask_un_5_);
	cppVar_19470 = cppVar_19469 + 32;
	cppVar_19470 = (cppVar_19470 & cppMask_un_8_);
	cppVar_19457 = cppVar_19470;
	}
	cppVar_19472 = (cppVar_19457 == 138);
	if (cppVar_19472) {
	cppVar_19456 = TL0;
	} else {
	cppVar_19475 = PC + 1;
	cppVar_19475 = (cppVar_19475 & cppMask_un_16_);
	cppVar_19476 = ROM.rd(cppVar_19475);
	cppVar_19477 = (cppVar_19476 >> 7) & cppMask_un_1_;
	cppVar_19478 = (cppVar_19477 == 1);
	if (cppVar_19478) {
	cppVar_19479 = PC + 1;
	cppVar_19479 = (cppVar_19479 & cppMask_un_16_);
	cppVar_19480 = ROM.rd(cppVar_19479);
	cppVar_19481 = (cppVar_19480 >> 3) & cppMask_un_5_;
	cppVar_19482 = (cppVar_19481 << 3) | 0;
	cppVar_19482 = (cppVar_19482 & cppMask_un_8_);
	cppVar_19474 = cppVar_19482;
	} else {
	cppVar_19483 = PC + 1;
	cppVar_19483 = (cppVar_19483 & cppMask_un_16_);
	cppVar_19484 = ROM.rd(cppVar_19483);
	cppVar_19485 = (cppVar_19484 >> 3) & cppMask_un_5_;
	cppVar_19486 = (cppVar_19485 & cppMask_un_5_);
	cppVar_19487 = cppVar_19486 + 32;
	cppVar_19487 = (cppVar_19487 & cppMask_un_8_);
	cppVar_19474 = cppVar_19487;
	}
	cppVar_19489 = (cppVar_19474 == 140);
	if (cppVar_19489) {
	cppVar_19473 = TH0;
	} else {
	cppVar_19492 = PC + 1;
	cppVar_19492 = (cppVar_19492 & cppMask_un_16_);
	cppVar_19493 = ROM.rd(cppVar_19492);
	cppVar_19494 = (cppVar_19493 >> 7) & cppMask_un_1_;
	cppVar_19495 = (cppVar_19494 == 1);
	if (cppVar_19495) {
	cppVar_19496 = PC + 1;
	cppVar_19496 = (cppVar_19496 & cppMask_un_16_);
	cppVar_19497 = ROM.rd(cppVar_19496);
	cppVar_19498 = (cppVar_19497 >> 3) & cppMask_un_5_;
	cppVar_19499 = (cppVar_19498 << 3) | 0;
	cppVar_19499 = (cppVar_19499 & cppMask_un_8_);
	cppVar_19491 = cppVar_19499;
	} else {
	cppVar_19500 = PC + 1;
	cppVar_19500 = (cppVar_19500 & cppMask_un_16_);
	cppVar_19501 = ROM.rd(cppVar_19500);
	cppVar_19502 = (cppVar_19501 >> 3) & cppMask_un_5_;
	cppVar_19503 = (cppVar_19502 & cppMask_un_5_);
	cppVar_19504 = cppVar_19503 + 32;
	cppVar_19504 = (cppVar_19504 & cppMask_un_8_);
	cppVar_19491 = cppVar_19504;
	}
	cppVar_19506 = (cppVar_19491 == 139);
	if (cppVar_19506) {
	cppVar_19490 = TL1;
	} else {
	cppVar_19509 = PC + 1;
	cppVar_19509 = (cppVar_19509 & cppMask_un_16_);
	cppVar_19510 = ROM.rd(cppVar_19509);
	cppVar_19511 = (cppVar_19510 >> 7) & cppMask_un_1_;
	cppVar_19512 = (cppVar_19511 == 1);
	if (cppVar_19512) {
	cppVar_19513 = PC + 1;
	cppVar_19513 = (cppVar_19513 & cppMask_un_16_);
	cppVar_19514 = ROM.rd(cppVar_19513);
	cppVar_19515 = (cppVar_19514 >> 3) & cppMask_un_5_;
	cppVar_19516 = (cppVar_19515 << 3) | 0;
	cppVar_19516 = (cppVar_19516 & cppMask_un_8_);
	cppVar_19508 = cppVar_19516;
	} else {
	cppVar_19517 = PC + 1;
	cppVar_19517 = (cppVar_19517 & cppMask_un_16_);
	cppVar_19518 = ROM.rd(cppVar_19517);
	cppVar_19519 = (cppVar_19518 >> 3) & cppMask_un_5_;
	cppVar_19520 = (cppVar_19519 & cppMask_un_5_);
	cppVar_19521 = cppVar_19520 + 32;
	cppVar_19521 = (cppVar_19521 & cppMask_un_8_);
	cppVar_19508 = cppVar_19521;
	}
	cppVar_19523 = (cppVar_19508 == 141);
	if (cppVar_19523) {
	cppVar_19507 = TH1;
	} else {
	cppVar_19526 = PC + 1;
	cppVar_19526 = (cppVar_19526 & cppMask_un_16_);
	cppVar_19527 = ROM.rd(cppVar_19526);
	cppVar_19528 = (cppVar_19527 >> 7) & cppMask_un_1_;
	cppVar_19529 = (cppVar_19528 == 1);
	if (cppVar_19529) {
	cppVar_19530 = PC + 1;
	cppVar_19530 = (cppVar_19530 & cppMask_un_16_);
	cppVar_19531 = ROM.rd(cppVar_19530);
	cppVar_19532 = (cppVar_19531 >> 3) & cppMask_un_5_;
	cppVar_19533 = (cppVar_19532 << 3) | 0;
	cppVar_19533 = (cppVar_19533 & cppMask_un_8_);
	cppVar_19525 = cppVar_19533;
	} else {
	cppVar_19534 = PC + 1;
	cppVar_19534 = (cppVar_19534 & cppMask_un_16_);
	cppVar_19535 = ROM.rd(cppVar_19534);
	cppVar_19536 = (cppVar_19535 >> 3) & cppMask_un_5_;
	cppVar_19537 = (cppVar_19536 & cppMask_un_5_);
	cppVar_19538 = cppVar_19537 + 32;
	cppVar_19538 = (cppVar_19538 & cppMask_un_8_);
	cppVar_19525 = cppVar_19538;
	}
	cppVar_19540 = (cppVar_19525 == 144);
	if (cppVar_19540) {
	cppVar_19524 = P1;
	} else {
	cppVar_19543 = PC + 1;
	cppVar_19543 = (cppVar_19543 & cppMask_un_16_);
	cppVar_19544 = ROM.rd(cppVar_19543);
	cppVar_19545 = (cppVar_19544 >> 7) & cppMask_un_1_;
	cppVar_19546 = (cppVar_19545 == 1);
	if (cppVar_19546) {
	cppVar_19547 = PC + 1;
	cppVar_19547 = (cppVar_19547 & cppMask_un_16_);
	cppVar_19548 = ROM.rd(cppVar_19547);
	cppVar_19549 = (cppVar_19548 >> 3) & cppMask_un_5_;
	cppVar_19550 = (cppVar_19549 << 3) | 0;
	cppVar_19550 = (cppVar_19550 & cppMask_un_8_);
	cppVar_19542 = cppVar_19550;
	} else {
	cppVar_19551 = PC + 1;
	cppVar_19551 = (cppVar_19551 & cppMask_un_16_);
	cppVar_19552 = ROM.rd(cppVar_19551);
	cppVar_19553 = (cppVar_19552 >> 3) & cppMask_un_5_;
	cppVar_19554 = (cppVar_19553 & cppMask_un_5_);
	cppVar_19555 = cppVar_19554 + 32;
	cppVar_19555 = (cppVar_19555 & cppMask_un_8_);
	cppVar_19542 = cppVar_19555;
	}
	cppVar_19557 = (cppVar_19542 == 152);
	if (cppVar_19557) {
	cppVar_19541 = SCON;
	} else {
	cppVar_19560 = PC + 1;
	cppVar_19560 = (cppVar_19560 & cppMask_un_16_);
	cppVar_19561 = ROM.rd(cppVar_19560);
	cppVar_19562 = (cppVar_19561 >> 7) & cppMask_un_1_;
	cppVar_19563 = (cppVar_19562 == 1);
	if (cppVar_19563) {
	cppVar_19564 = PC + 1;
	cppVar_19564 = (cppVar_19564 & cppMask_un_16_);
	cppVar_19565 = ROM.rd(cppVar_19564);
	cppVar_19566 = (cppVar_19565 >> 3) & cppMask_un_5_;
	cppVar_19567 = (cppVar_19566 << 3) | 0;
	cppVar_19567 = (cppVar_19567 & cppMask_un_8_);
	cppVar_19559 = cppVar_19567;
	} else {
	cppVar_19568 = PC + 1;
	cppVar_19568 = (cppVar_19568 & cppMask_un_16_);
	cppVar_19569 = ROM.rd(cppVar_19568);
	cppVar_19570 = (cppVar_19569 >> 3) & cppMask_un_5_;
	cppVar_19571 = (cppVar_19570 & cppMask_un_5_);
	cppVar_19572 = cppVar_19571 + 32;
	cppVar_19572 = (cppVar_19572 & cppMask_un_8_);
	cppVar_19559 = cppVar_19572;
	}
	cppVar_19574 = (cppVar_19559 == 153);
	if (cppVar_19574) {
	cppVar_19558 = SBUF;
	} else {
	cppVar_19577 = PC + 1;
	cppVar_19577 = (cppVar_19577 & cppMask_un_16_);
	cppVar_19578 = ROM.rd(cppVar_19577);
	cppVar_19579 = (cppVar_19578 >> 7) & cppMask_un_1_;
	cppVar_19580 = (cppVar_19579 == 1);
	if (cppVar_19580) {
	cppVar_19581 = PC + 1;
	cppVar_19581 = (cppVar_19581 & cppMask_un_16_);
	cppVar_19582 = ROM.rd(cppVar_19581);
	cppVar_19583 = (cppVar_19582 >> 3) & cppMask_un_5_;
	cppVar_19584 = (cppVar_19583 << 3) | 0;
	cppVar_19584 = (cppVar_19584 & cppMask_un_8_);
	cppVar_19576 = cppVar_19584;
	} else {
	cppVar_19585 = PC + 1;
	cppVar_19585 = (cppVar_19585 & cppMask_un_16_);
	cppVar_19586 = ROM.rd(cppVar_19585);
	cppVar_19587 = (cppVar_19586 >> 3) & cppMask_un_5_;
	cppVar_19588 = (cppVar_19587 & cppMask_un_5_);
	cppVar_19589 = cppVar_19588 + 32;
	cppVar_19589 = (cppVar_19589 & cppMask_un_8_);
	cppVar_19576 = cppVar_19589;
	}
	cppVar_19591 = (cppVar_19576 == 160);
	if (cppVar_19591) {
	cppVar_19575 = P2;
	} else {
	cppVar_19594 = PC + 1;
	cppVar_19594 = (cppVar_19594 & cppMask_un_16_);
	cppVar_19595 = ROM.rd(cppVar_19594);
	cppVar_19596 = (cppVar_19595 >> 7) & cppMask_un_1_;
	cppVar_19597 = (cppVar_19596 == 1);
	if (cppVar_19597) {
	cppVar_19598 = PC + 1;
	cppVar_19598 = (cppVar_19598 & cppMask_un_16_);
	cppVar_19599 = ROM.rd(cppVar_19598);
	cppVar_19600 = (cppVar_19599 >> 3) & cppMask_un_5_;
	cppVar_19601 = (cppVar_19600 << 3) | 0;
	cppVar_19601 = (cppVar_19601 & cppMask_un_8_);
	cppVar_19593 = cppVar_19601;
	} else {
	cppVar_19602 = PC + 1;
	cppVar_19602 = (cppVar_19602 & cppMask_un_16_);
	cppVar_19603 = ROM.rd(cppVar_19602);
	cppVar_19604 = (cppVar_19603 >> 3) & cppMask_un_5_;
	cppVar_19605 = (cppVar_19604 & cppMask_un_5_);
	cppVar_19606 = cppVar_19605 + 32;
	cppVar_19606 = (cppVar_19606 & cppMask_un_8_);
	cppVar_19593 = cppVar_19606;
	}
	cppVar_19608 = (cppVar_19593 == 168);
	if (cppVar_19608) {
	cppVar_19592 = IE;
	} else {
	cppVar_19611 = PC + 1;
	cppVar_19611 = (cppVar_19611 & cppMask_un_16_);
	cppVar_19612 = ROM.rd(cppVar_19611);
	cppVar_19613 = (cppVar_19612 >> 7) & cppMask_un_1_;
	cppVar_19614 = (cppVar_19613 == 1);
	if (cppVar_19614) {
	cppVar_19615 = PC + 1;
	cppVar_19615 = (cppVar_19615 & cppMask_un_16_);
	cppVar_19616 = ROM.rd(cppVar_19615);
	cppVar_19617 = (cppVar_19616 >> 3) & cppMask_un_5_;
	cppVar_19618 = (cppVar_19617 << 3) | 0;
	cppVar_19618 = (cppVar_19618 & cppMask_un_8_);
	cppVar_19610 = cppVar_19618;
	} else {
	cppVar_19619 = PC + 1;
	cppVar_19619 = (cppVar_19619 & cppMask_un_16_);
	cppVar_19620 = ROM.rd(cppVar_19619);
	cppVar_19621 = (cppVar_19620 >> 3) & cppMask_un_5_;
	cppVar_19622 = (cppVar_19621 & cppMask_un_5_);
	cppVar_19623 = cppVar_19622 + 32;
	cppVar_19623 = (cppVar_19623 & cppMask_un_8_);
	cppVar_19610 = cppVar_19623;
	}
	cppVar_19625 = (cppVar_19610 == 176);
	if (cppVar_19625) {
	cppVar_19609 = P3;
	} else {
	cppVar_19628 = PC + 1;
	cppVar_19628 = (cppVar_19628 & cppMask_un_16_);
	cppVar_19629 = ROM.rd(cppVar_19628);
	cppVar_19630 = (cppVar_19629 >> 7) & cppMask_un_1_;
	cppVar_19631 = (cppVar_19630 == 1);
	if (cppVar_19631) {
	cppVar_19632 = PC + 1;
	cppVar_19632 = (cppVar_19632 & cppMask_un_16_);
	cppVar_19633 = ROM.rd(cppVar_19632);
	cppVar_19634 = (cppVar_19633 >> 3) & cppMask_un_5_;
	cppVar_19635 = (cppVar_19634 << 3) | 0;
	cppVar_19635 = (cppVar_19635 & cppMask_un_8_);
	cppVar_19627 = cppVar_19635;
	} else {
	cppVar_19636 = PC + 1;
	cppVar_19636 = (cppVar_19636 & cppMask_un_16_);
	cppVar_19637 = ROM.rd(cppVar_19636);
	cppVar_19638 = (cppVar_19637 >> 3) & cppMask_un_5_;
	cppVar_19639 = (cppVar_19638 & cppMask_un_5_);
	cppVar_19640 = cppVar_19639 + 32;
	cppVar_19640 = (cppVar_19640 & cppMask_un_8_);
	cppVar_19627 = cppVar_19640;
	}
	cppVar_19642 = (cppVar_19627 == 184);
	if (cppVar_19642) {
	cppVar_19626 = IP;
	} else {
	cppVar_19645 = PC + 1;
	cppVar_19645 = (cppVar_19645 & cppMask_un_16_);
	cppVar_19646 = ROM.rd(cppVar_19645);
	cppVar_19647 = (cppVar_19646 >> 7) & cppMask_un_1_;
	cppVar_19648 = (cppVar_19647 == 1);
	if (cppVar_19648) {
	cppVar_19649 = PC + 1;
	cppVar_19649 = (cppVar_19649 & cppMask_un_16_);
	cppVar_19650 = ROM.rd(cppVar_19649);
	cppVar_19651 = (cppVar_19650 >> 3) & cppMask_un_5_;
	cppVar_19652 = (cppVar_19651 << 3) | 0;
	cppVar_19652 = (cppVar_19652 & cppMask_un_8_);
	cppVar_19644 = cppVar_19652;
	} else {
	cppVar_19653 = PC + 1;
	cppVar_19653 = (cppVar_19653 & cppMask_un_16_);
	cppVar_19654 = ROM.rd(cppVar_19653);
	cppVar_19655 = (cppVar_19654 >> 3) & cppMask_un_5_;
	cppVar_19656 = (cppVar_19655 & cppMask_un_5_);
	cppVar_19657 = cppVar_19656 + 32;
	cppVar_19657 = (cppVar_19657 & cppMask_un_8_);
	cppVar_19644 = cppVar_19657;
	}
	cppVar_19659 = (cppVar_19644 == 208);
	if (cppVar_19659) {
	cppVar_19643 = PSW;
	} else {
	cppVar_19662 = PC + 1;
	cppVar_19662 = (cppVar_19662 & cppMask_un_16_);
	cppVar_19663 = ROM.rd(cppVar_19662);
	cppVar_19664 = (cppVar_19663 >> 7) & cppMask_un_1_;
	cppVar_19665 = (cppVar_19664 == 1);
	if (cppVar_19665) {
	cppVar_19666 = PC + 1;
	cppVar_19666 = (cppVar_19666 & cppMask_un_16_);
	cppVar_19667 = ROM.rd(cppVar_19666);
	cppVar_19668 = (cppVar_19667 >> 3) & cppMask_un_5_;
	cppVar_19669 = (cppVar_19668 << 3) | 0;
	cppVar_19669 = (cppVar_19669 & cppMask_un_8_);
	cppVar_19661 = cppVar_19669;
	} else {
	cppVar_19670 = PC + 1;
	cppVar_19670 = (cppVar_19670 & cppMask_un_16_);
	cppVar_19671 = ROM.rd(cppVar_19670);
	cppVar_19672 = (cppVar_19671 >> 3) & cppMask_un_5_;
	cppVar_19673 = (cppVar_19672 & cppMask_un_5_);
	cppVar_19674 = cppVar_19673 + 32;
	cppVar_19674 = (cppVar_19674 & cppMask_un_8_);
	cppVar_19661 = cppVar_19674;
	}
	cppVar_19676 = (cppVar_19661 == 224);
	if (cppVar_19676) {
	cppVar_19660 = ACC;
	} else {
	cppVar_19679 = PC + 1;
	cppVar_19679 = (cppVar_19679 & cppMask_un_16_);
	cppVar_19680 = ROM.rd(cppVar_19679);
	cppVar_19681 = (cppVar_19680 >> 7) & cppMask_un_1_;
	cppVar_19682 = (cppVar_19681 == 1);
	if (cppVar_19682) {
	cppVar_19683 = PC + 1;
	cppVar_19683 = (cppVar_19683 & cppMask_un_16_);
	cppVar_19684 = ROM.rd(cppVar_19683);
	cppVar_19685 = (cppVar_19684 >> 3) & cppMask_un_5_;
	cppVar_19686 = (cppVar_19685 << 3) | 0;
	cppVar_19686 = (cppVar_19686 & cppMask_un_8_);
	cppVar_19678 = cppVar_19686;
	} else {
	cppVar_19687 = PC + 1;
	cppVar_19687 = (cppVar_19687 & cppMask_un_16_);
	cppVar_19688 = ROM.rd(cppVar_19687);
	cppVar_19689 = (cppVar_19688 >> 3) & cppMask_un_5_;
	cppVar_19690 = (cppVar_19689 & cppMask_un_5_);
	cppVar_19691 = cppVar_19690 + 32;
	cppVar_19691 = (cppVar_19691 & cppMask_un_8_);
	cppVar_19678 = cppVar_19691;
	}
	cppVar_19693 = (cppVar_19678 == 240);
	if (cppVar_19693) {
	cppVar_19677 = B;
	} else {
	cppVar_19677 = 0;
	}
	cppVar_19660 = cppVar_19677;
	}
	cppVar_19643 = cppVar_19660;
	}
	cppVar_19626 = cppVar_19643;
	}
	cppVar_19609 = cppVar_19626;
	}
	cppVar_19592 = cppVar_19609;
	}
	cppVar_19575 = cppVar_19592;
	}
	cppVar_19558 = cppVar_19575;
	}
	cppVar_19541 = cppVar_19558;
	}
	cppVar_19524 = cppVar_19541;
	}
	cppVar_19507 = cppVar_19524;
	}
	cppVar_19490 = cppVar_19507;
	}
	cppVar_19473 = cppVar_19490;
	}
	cppVar_19456 = cppVar_19473;
	}
	cppVar_19439 = cppVar_19456;
	}
	cppVar_19422 = cppVar_19439;
	}
	cppVar_19405 = cppVar_19422;
	}
	cppVar_19388 = cppVar_19405;
	}
	cppVar_19371 = cppVar_19388;
	}
	cppVar_19354 = cppVar_19371;
	}
	cppVar_19337 = cppVar_19354;
	}
	cppVar_19304 = cppVar_19337;
	}
	cppVar_19695 = cppVar_19303 & cppVar_19304;
	cppVar_19696 = (PSW >> 7) & cppMask_un_1_;
	cppVar_19697 = (cppVar_19696 & cppMask_un_1_);
	cppVar_19698 = PC + 1;
	cppVar_19698 = (cppVar_19698 & cppMask_un_16_);
	cppVar_19699 = ROM.rd(cppVar_19698);
	cppVar_19700 = (cppVar_19699 >> 0) & cppMask_un_3_;
	cppVar_19701 = (cppVar_19700 & cppMask_un_3_);
	cppVar_19702 = cppVar_19697 << static_cast<unsigned>(cppVar_19701);
	cppVar_19702 = (cppVar_19702 & cppMask_un_8_);
	cppVar_19703 = cppVar_19695 | cppVar_19702;
	cppVar_19276 = cppVar_19703;
	} else {
	cppVar_19276 = IP;
	}
	cppVar_19272 = cppVar_19276;
	} else {
	cppVar_19705 = ROM.rd(PC);
	cppVar_19707 = (cppVar_19705 == 143);
	if (cppVar_19707) {
	cppVar_19710 = PC + 1;
	cppVar_19710 = (cppVar_19710 & cppMask_un_16_);
	cppVar_19711 = ROM.rd(cppVar_19710);
	cppVar_19713 = (cppVar_19711 == 184);
	if (cppVar_19713) {
	cppVar_19716 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19718 = (cppVar_19716 << 3) | 7;
	cppVar_19718 = (cppVar_19718 & cppMask_un_5_);
	cppVar_19719 = (0 << 5) | cppVar_19718;
	cppVar_19719 = (cppVar_19719 & cppMask_un_8_);
	cppVar_19720 = (cppVar_19719 >> 7) & cppMask_un_1_;
	cppVar_19722 = (cppVar_19720 == 0);
	if (cppVar_19722) {
	cppVar_19723 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19724 = (cppVar_19723 << 3) | 7;
	cppVar_19724 = (cppVar_19724 & cppMask_un_5_);
	cppVar_19725 = (0 << 5) | cppVar_19724;
	cppVar_19725 = (cppVar_19725 & cppMask_un_8_);
	cppVar_19726 = IRAM.rd(cppVar_19725);
	cppVar_19714 = cppVar_19726;
	} else {
	cppVar_19728 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19729 = (cppVar_19728 << 3) | 7;
	cppVar_19729 = (cppVar_19729 & cppMask_un_5_);
	cppVar_19730 = (0 << 5) | cppVar_19729;
	cppVar_19730 = (cppVar_19730 & cppMask_un_8_);
	cppVar_19732 = (cppVar_19730 == 128);
	if (cppVar_19732) {
	cppVar_19727 = P0;
	} else {
	cppVar_19734 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19735 = (cppVar_19734 << 3) | 7;
	cppVar_19735 = (cppVar_19735 & cppMask_un_5_);
	cppVar_19736 = (0 << 5) | cppVar_19735;
	cppVar_19736 = (cppVar_19736 & cppMask_un_8_);
	cppVar_19738 = (cppVar_19736 == 129);
	if (cppVar_19738) {
	cppVar_19733 = SP;
	} else {
	cppVar_19740 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19741 = (cppVar_19740 << 3) | 7;
	cppVar_19741 = (cppVar_19741 & cppMask_un_5_);
	cppVar_19742 = (0 << 5) | cppVar_19741;
	cppVar_19742 = (cppVar_19742 & cppMask_un_8_);
	cppVar_19744 = (cppVar_19742 == 130);
	if (cppVar_19744) {
	cppVar_19739 = DPL;
	} else {
	cppVar_19746 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19747 = (cppVar_19746 << 3) | 7;
	cppVar_19747 = (cppVar_19747 & cppMask_un_5_);
	cppVar_19748 = (0 << 5) | cppVar_19747;
	cppVar_19748 = (cppVar_19748 & cppMask_un_8_);
	cppVar_19750 = (cppVar_19748 == 131);
	if (cppVar_19750) {
	cppVar_19745 = DPH;
	} else {
	cppVar_19752 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19753 = (cppVar_19752 << 3) | 7;
	cppVar_19753 = (cppVar_19753 & cppMask_un_5_);
	cppVar_19754 = (0 << 5) | cppVar_19753;
	cppVar_19754 = (cppVar_19754 & cppMask_un_8_);
	cppVar_19756 = (cppVar_19754 == 135);
	if (cppVar_19756) {
	cppVar_19751 = PCON;
	} else {
	cppVar_19758 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19759 = (cppVar_19758 << 3) | 7;
	cppVar_19759 = (cppVar_19759 & cppMask_un_5_);
	cppVar_19760 = (0 << 5) | cppVar_19759;
	cppVar_19760 = (cppVar_19760 & cppMask_un_8_);
	cppVar_19762 = (cppVar_19760 == 136);
	if (cppVar_19762) {
	cppVar_19757 = TCON;
	} else {
	cppVar_19764 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19765 = (cppVar_19764 << 3) | 7;
	cppVar_19765 = (cppVar_19765 & cppMask_un_5_);
	cppVar_19766 = (0 << 5) | cppVar_19765;
	cppVar_19766 = (cppVar_19766 & cppMask_un_8_);
	cppVar_19768 = (cppVar_19766 == 137);
	if (cppVar_19768) {
	cppVar_19763 = TMOD;
	} else {
	cppVar_19770 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19771 = (cppVar_19770 << 3) | 7;
	cppVar_19771 = (cppVar_19771 & cppMask_un_5_);
	cppVar_19772 = (0 << 5) | cppVar_19771;
	cppVar_19772 = (cppVar_19772 & cppMask_un_8_);
	cppVar_19774 = (cppVar_19772 == 138);
	if (cppVar_19774) {
	cppVar_19769 = TL0;
	} else {
	cppVar_19776 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19777 = (cppVar_19776 << 3) | 7;
	cppVar_19777 = (cppVar_19777 & cppMask_un_5_);
	cppVar_19778 = (0 << 5) | cppVar_19777;
	cppVar_19778 = (cppVar_19778 & cppMask_un_8_);
	cppVar_19780 = (cppVar_19778 == 140);
	if (cppVar_19780) {
	cppVar_19775 = TH0;
	} else {
	cppVar_19782 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19783 = (cppVar_19782 << 3) | 7;
	cppVar_19783 = (cppVar_19783 & cppMask_un_5_);
	cppVar_19784 = (0 << 5) | cppVar_19783;
	cppVar_19784 = (cppVar_19784 & cppMask_un_8_);
	cppVar_19786 = (cppVar_19784 == 139);
	if (cppVar_19786) {
	cppVar_19781 = TL1;
	} else {
	cppVar_19788 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19789 = (cppVar_19788 << 3) | 7;
	cppVar_19789 = (cppVar_19789 & cppMask_un_5_);
	cppVar_19790 = (0 << 5) | cppVar_19789;
	cppVar_19790 = (cppVar_19790 & cppMask_un_8_);
	cppVar_19792 = (cppVar_19790 == 141);
	if (cppVar_19792) {
	cppVar_19787 = TH1;
	} else {
	cppVar_19794 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19795 = (cppVar_19794 << 3) | 7;
	cppVar_19795 = (cppVar_19795 & cppMask_un_5_);
	cppVar_19796 = (0 << 5) | cppVar_19795;
	cppVar_19796 = (cppVar_19796 & cppMask_un_8_);
	cppVar_19798 = (cppVar_19796 == 144);
	if (cppVar_19798) {
	cppVar_19793 = P1;
	} else {
	cppVar_19800 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19801 = (cppVar_19800 << 3) | 7;
	cppVar_19801 = (cppVar_19801 & cppMask_un_5_);
	cppVar_19802 = (0 << 5) | cppVar_19801;
	cppVar_19802 = (cppVar_19802 & cppMask_un_8_);
	cppVar_19804 = (cppVar_19802 == 152);
	if (cppVar_19804) {
	cppVar_19799 = SCON;
	} else {
	cppVar_19806 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19807 = (cppVar_19806 << 3) | 7;
	cppVar_19807 = (cppVar_19807 & cppMask_un_5_);
	cppVar_19808 = (0 << 5) | cppVar_19807;
	cppVar_19808 = (cppVar_19808 & cppMask_un_8_);
	cppVar_19810 = (cppVar_19808 == 153);
	if (cppVar_19810) {
	cppVar_19805 = SBUF;
	} else {
	cppVar_19812 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19813 = (cppVar_19812 << 3) | 7;
	cppVar_19813 = (cppVar_19813 & cppMask_un_5_);
	cppVar_19814 = (0 << 5) | cppVar_19813;
	cppVar_19814 = (cppVar_19814 & cppMask_un_8_);
	cppVar_19816 = (cppVar_19814 == 160);
	if (cppVar_19816) {
	cppVar_19811 = P2;
	} else {
	cppVar_19818 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19819 = (cppVar_19818 << 3) | 7;
	cppVar_19819 = (cppVar_19819 & cppMask_un_5_);
	cppVar_19820 = (0 << 5) | cppVar_19819;
	cppVar_19820 = (cppVar_19820 & cppMask_un_8_);
	cppVar_19822 = (cppVar_19820 == 168);
	if (cppVar_19822) {
	cppVar_19817 = IE;
	} else {
	cppVar_19824 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19825 = (cppVar_19824 << 3) | 7;
	cppVar_19825 = (cppVar_19825 & cppMask_un_5_);
	cppVar_19826 = (0 << 5) | cppVar_19825;
	cppVar_19826 = (cppVar_19826 & cppMask_un_8_);
	cppVar_19828 = (cppVar_19826 == 176);
	if (cppVar_19828) {
	cppVar_19823 = P3;
	} else {
	cppVar_19830 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19831 = (cppVar_19830 << 3) | 7;
	cppVar_19831 = (cppVar_19831 & cppMask_un_5_);
	cppVar_19832 = (0 << 5) | cppVar_19831;
	cppVar_19832 = (cppVar_19832 & cppMask_un_8_);
	cppVar_19834 = (cppVar_19832 == 184);
	if (cppVar_19834) {
	cppVar_19829 = IP;
	} else {
	cppVar_19836 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19837 = (cppVar_19836 << 3) | 7;
	cppVar_19837 = (cppVar_19837 & cppMask_un_5_);
	cppVar_19838 = (0 << 5) | cppVar_19837;
	cppVar_19838 = (cppVar_19838 & cppMask_un_8_);
	cppVar_19840 = (cppVar_19838 == 208);
	if (cppVar_19840) {
	cppVar_19835 = PSW;
	} else {
	cppVar_19842 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19843 = (cppVar_19842 << 3) | 7;
	cppVar_19843 = (cppVar_19843 & cppMask_un_5_);
	cppVar_19844 = (0 << 5) | cppVar_19843;
	cppVar_19844 = (cppVar_19844 & cppMask_un_8_);
	cppVar_19846 = (cppVar_19844 == 224);
	if (cppVar_19846) {
	cppVar_19841 = ACC;
	} else {
	cppVar_19848 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19849 = (cppVar_19848 << 3) | 7;
	cppVar_19849 = (cppVar_19849 & cppMask_un_5_);
	cppVar_19850 = (0 << 5) | cppVar_19849;
	cppVar_19850 = (cppVar_19850 & cppMask_un_8_);
	cppVar_19852 = (cppVar_19850 == 240);
	if (cppVar_19852) {
	cppVar_19847 = B;
	} else {
	cppVar_19847 = 0;
	}
	cppVar_19841 = cppVar_19847;
	}
	cppVar_19835 = cppVar_19841;
	}
	cppVar_19829 = cppVar_19835;
	}
	cppVar_19823 = cppVar_19829;
	}
	cppVar_19817 = cppVar_19823;
	}
	cppVar_19811 = cppVar_19817;
	}
	cppVar_19805 = cppVar_19811;
	}
	cppVar_19799 = cppVar_19805;
	}
	cppVar_19793 = cppVar_19799;
	}
	cppVar_19787 = cppVar_19793;
	}
	cppVar_19781 = cppVar_19787;
	}
	cppVar_19775 = cppVar_19781;
	}
	cppVar_19769 = cppVar_19775;
	}
	cppVar_19763 = cppVar_19769;
	}
	cppVar_19757 = cppVar_19763;
	}
	cppVar_19751 = cppVar_19757;
	}
	cppVar_19745 = cppVar_19751;
	}
	cppVar_19739 = cppVar_19745;
	}
	cppVar_19733 = cppVar_19739;
	}
	cppVar_19727 = cppVar_19733;
	}
	cppVar_19714 = cppVar_19727;
	}
	cppVar_19708 = cppVar_19714;
	} else {
	cppVar_19708 = IP;
	}
	cppVar_19704 = cppVar_19708;
	} else {
	cppVar_19855 = ROM.rd(PC);
	cppVar_19857 = (cppVar_19855 == 142);
	if (cppVar_19857) {
	cppVar_19860 = PC + 1;
	cppVar_19860 = (cppVar_19860 & cppMask_un_16_);
	cppVar_19861 = ROM.rd(cppVar_19860);
	cppVar_19863 = (cppVar_19861 == 184);
	if (cppVar_19863) {
	cppVar_19866 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19868 = (cppVar_19866 << 3) | 6;
	cppVar_19868 = (cppVar_19868 & cppMask_un_5_);
	cppVar_19869 = (0 << 5) | cppVar_19868;
	cppVar_19869 = (cppVar_19869 & cppMask_un_8_);
	cppVar_19870 = (cppVar_19869 >> 7) & cppMask_un_1_;
	cppVar_19872 = (cppVar_19870 == 0);
	if (cppVar_19872) {
	cppVar_19873 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19874 = (cppVar_19873 << 3) | 6;
	cppVar_19874 = (cppVar_19874 & cppMask_un_5_);
	cppVar_19875 = (0 << 5) | cppVar_19874;
	cppVar_19875 = (cppVar_19875 & cppMask_un_8_);
	cppVar_19876 = IRAM.rd(cppVar_19875);
	cppVar_19864 = cppVar_19876;
	} else {
	cppVar_19878 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19879 = (cppVar_19878 << 3) | 6;
	cppVar_19879 = (cppVar_19879 & cppMask_un_5_);
	cppVar_19880 = (0 << 5) | cppVar_19879;
	cppVar_19880 = (cppVar_19880 & cppMask_un_8_);
	cppVar_19882 = (cppVar_19880 == 128);
	if (cppVar_19882) {
	cppVar_19877 = P0;
	} else {
	cppVar_19884 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19885 = (cppVar_19884 << 3) | 6;
	cppVar_19885 = (cppVar_19885 & cppMask_un_5_);
	cppVar_19886 = (0 << 5) | cppVar_19885;
	cppVar_19886 = (cppVar_19886 & cppMask_un_8_);
	cppVar_19888 = (cppVar_19886 == 129);
	if (cppVar_19888) {
	cppVar_19883 = SP;
	} else {
	cppVar_19890 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19891 = (cppVar_19890 << 3) | 6;
	cppVar_19891 = (cppVar_19891 & cppMask_un_5_);
	cppVar_19892 = (0 << 5) | cppVar_19891;
	cppVar_19892 = (cppVar_19892 & cppMask_un_8_);
	cppVar_19894 = (cppVar_19892 == 130);
	if (cppVar_19894) {
	cppVar_19889 = DPL;
	} else {
	cppVar_19896 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19897 = (cppVar_19896 << 3) | 6;
	cppVar_19897 = (cppVar_19897 & cppMask_un_5_);
	cppVar_19898 = (0 << 5) | cppVar_19897;
	cppVar_19898 = (cppVar_19898 & cppMask_un_8_);
	cppVar_19900 = (cppVar_19898 == 131);
	if (cppVar_19900) {
	cppVar_19895 = DPH;
	} else {
	cppVar_19902 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19903 = (cppVar_19902 << 3) | 6;
	cppVar_19903 = (cppVar_19903 & cppMask_un_5_);
	cppVar_19904 = (0 << 5) | cppVar_19903;
	cppVar_19904 = (cppVar_19904 & cppMask_un_8_);
	cppVar_19906 = (cppVar_19904 == 135);
	if (cppVar_19906) {
	cppVar_19901 = PCON;
	} else {
	cppVar_19908 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19909 = (cppVar_19908 << 3) | 6;
	cppVar_19909 = (cppVar_19909 & cppMask_un_5_);
	cppVar_19910 = (0 << 5) | cppVar_19909;
	cppVar_19910 = (cppVar_19910 & cppMask_un_8_);
	cppVar_19912 = (cppVar_19910 == 136);
	if (cppVar_19912) {
	cppVar_19907 = TCON;
	} else {
	cppVar_19914 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19915 = (cppVar_19914 << 3) | 6;
	cppVar_19915 = (cppVar_19915 & cppMask_un_5_);
	cppVar_19916 = (0 << 5) | cppVar_19915;
	cppVar_19916 = (cppVar_19916 & cppMask_un_8_);
	cppVar_19918 = (cppVar_19916 == 137);
	if (cppVar_19918) {
	cppVar_19913 = TMOD;
	} else {
	cppVar_19920 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19921 = (cppVar_19920 << 3) | 6;
	cppVar_19921 = (cppVar_19921 & cppMask_un_5_);
	cppVar_19922 = (0 << 5) | cppVar_19921;
	cppVar_19922 = (cppVar_19922 & cppMask_un_8_);
	cppVar_19924 = (cppVar_19922 == 138);
	if (cppVar_19924) {
	cppVar_19919 = TL0;
	} else {
	cppVar_19926 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19927 = (cppVar_19926 << 3) | 6;
	cppVar_19927 = (cppVar_19927 & cppMask_un_5_);
	cppVar_19928 = (0 << 5) | cppVar_19927;
	cppVar_19928 = (cppVar_19928 & cppMask_un_8_);
	cppVar_19930 = (cppVar_19928 == 140);
	if (cppVar_19930) {
	cppVar_19925 = TH0;
	} else {
	cppVar_19932 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19933 = (cppVar_19932 << 3) | 6;
	cppVar_19933 = (cppVar_19933 & cppMask_un_5_);
	cppVar_19934 = (0 << 5) | cppVar_19933;
	cppVar_19934 = (cppVar_19934 & cppMask_un_8_);
	cppVar_19936 = (cppVar_19934 == 139);
	if (cppVar_19936) {
	cppVar_19931 = TL1;
	} else {
	cppVar_19938 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19939 = (cppVar_19938 << 3) | 6;
	cppVar_19939 = (cppVar_19939 & cppMask_un_5_);
	cppVar_19940 = (0 << 5) | cppVar_19939;
	cppVar_19940 = (cppVar_19940 & cppMask_un_8_);
	cppVar_19942 = (cppVar_19940 == 141);
	if (cppVar_19942) {
	cppVar_19937 = TH1;
	} else {
	cppVar_19944 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19945 = (cppVar_19944 << 3) | 6;
	cppVar_19945 = (cppVar_19945 & cppMask_un_5_);
	cppVar_19946 = (0 << 5) | cppVar_19945;
	cppVar_19946 = (cppVar_19946 & cppMask_un_8_);
	cppVar_19948 = (cppVar_19946 == 144);
	if (cppVar_19948) {
	cppVar_19943 = P1;
	} else {
	cppVar_19950 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19951 = (cppVar_19950 << 3) | 6;
	cppVar_19951 = (cppVar_19951 & cppMask_un_5_);
	cppVar_19952 = (0 << 5) | cppVar_19951;
	cppVar_19952 = (cppVar_19952 & cppMask_un_8_);
	cppVar_19954 = (cppVar_19952 == 152);
	if (cppVar_19954) {
	cppVar_19949 = SCON;
	} else {
	cppVar_19956 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19957 = (cppVar_19956 << 3) | 6;
	cppVar_19957 = (cppVar_19957 & cppMask_un_5_);
	cppVar_19958 = (0 << 5) | cppVar_19957;
	cppVar_19958 = (cppVar_19958 & cppMask_un_8_);
	cppVar_19960 = (cppVar_19958 == 153);
	if (cppVar_19960) {
	cppVar_19955 = SBUF;
	} else {
	cppVar_19962 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19963 = (cppVar_19962 << 3) | 6;
	cppVar_19963 = (cppVar_19963 & cppMask_un_5_);
	cppVar_19964 = (0 << 5) | cppVar_19963;
	cppVar_19964 = (cppVar_19964 & cppMask_un_8_);
	cppVar_19966 = (cppVar_19964 == 160);
	if (cppVar_19966) {
	cppVar_19961 = P2;
	} else {
	cppVar_19968 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19969 = (cppVar_19968 << 3) | 6;
	cppVar_19969 = (cppVar_19969 & cppMask_un_5_);
	cppVar_19970 = (0 << 5) | cppVar_19969;
	cppVar_19970 = (cppVar_19970 & cppMask_un_8_);
	cppVar_19972 = (cppVar_19970 == 168);
	if (cppVar_19972) {
	cppVar_19967 = IE;
	} else {
	cppVar_19974 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19975 = (cppVar_19974 << 3) | 6;
	cppVar_19975 = (cppVar_19975 & cppMask_un_5_);
	cppVar_19976 = (0 << 5) | cppVar_19975;
	cppVar_19976 = (cppVar_19976 & cppMask_un_8_);
	cppVar_19978 = (cppVar_19976 == 176);
	if (cppVar_19978) {
	cppVar_19973 = P3;
	} else {
	cppVar_19980 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19981 = (cppVar_19980 << 3) | 6;
	cppVar_19981 = (cppVar_19981 & cppMask_un_5_);
	cppVar_19982 = (0 << 5) | cppVar_19981;
	cppVar_19982 = (cppVar_19982 & cppMask_un_8_);
	cppVar_19984 = (cppVar_19982 == 184);
	if (cppVar_19984) {
	cppVar_19979 = IP;
	} else {
	cppVar_19986 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19987 = (cppVar_19986 << 3) | 6;
	cppVar_19987 = (cppVar_19987 & cppMask_un_5_);
	cppVar_19988 = (0 << 5) | cppVar_19987;
	cppVar_19988 = (cppVar_19988 & cppMask_un_8_);
	cppVar_19990 = (cppVar_19988 == 208);
	if (cppVar_19990) {
	cppVar_19985 = PSW;
	} else {
	cppVar_19992 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19993 = (cppVar_19992 << 3) | 6;
	cppVar_19993 = (cppVar_19993 & cppMask_un_5_);
	cppVar_19994 = (0 << 5) | cppVar_19993;
	cppVar_19994 = (cppVar_19994 & cppMask_un_8_);
	cppVar_19996 = (cppVar_19994 == 224);
	if (cppVar_19996) {
	cppVar_19991 = ACC;
	} else {
	cppVar_19998 = (PSW >> 3) & cppMask_un_2_;
	cppVar_19999 = (cppVar_19998 << 3) | 6;
	cppVar_19999 = (cppVar_19999 & cppMask_un_5_);
	cppVar_20000 = (0 << 5) | cppVar_19999;
	cppVar_20000 = (cppVar_20000 & cppMask_un_8_);
	cppVar_20002 = (cppVar_20000 == 240);
	if (cppVar_20002) {
	cppVar_19997 = B;
	} else {
	cppVar_19997 = 0;
	}
	cppVar_19991 = cppVar_19997;
	}
	cppVar_19985 = cppVar_19991;
	}
	cppVar_19979 = cppVar_19985;
	}
	cppVar_19973 = cppVar_19979;
	}
	cppVar_19967 = cppVar_19973;
	}
	cppVar_19961 = cppVar_19967;
	}
	cppVar_19955 = cppVar_19961;
	}
	cppVar_19949 = cppVar_19955;
	}
	cppVar_19943 = cppVar_19949;
	}
	cppVar_19937 = cppVar_19943;
	}
	cppVar_19931 = cppVar_19937;
	}
	cppVar_19925 = cppVar_19931;
	}
	cppVar_19919 = cppVar_19925;
	}
	cppVar_19913 = cppVar_19919;
	}
	cppVar_19907 = cppVar_19913;
	}
	cppVar_19901 = cppVar_19907;
	}
	cppVar_19895 = cppVar_19901;
	}
	cppVar_19889 = cppVar_19895;
	}
	cppVar_19883 = cppVar_19889;
	}
	cppVar_19877 = cppVar_19883;
	}
	cppVar_19864 = cppVar_19877;
	}
	cppVar_19858 = cppVar_19864;
	} else {
	cppVar_19858 = IP;
	}
	cppVar_19854 = cppVar_19858;
	} else {
	cppVar_20005 = ROM.rd(PC);
	cppVar_20007 = (cppVar_20005 == 141);
	if (cppVar_20007) {
	cppVar_20010 = PC + 1;
	cppVar_20010 = (cppVar_20010 & cppMask_un_16_);
	cppVar_20011 = ROM.rd(cppVar_20010);
	cppVar_20013 = (cppVar_20011 == 184);
	if (cppVar_20013) {
	cppVar_20016 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20018 = (cppVar_20016 << 3) | 5;
	cppVar_20018 = (cppVar_20018 & cppMask_un_5_);
	cppVar_20019 = (0 << 5) | cppVar_20018;
	cppVar_20019 = (cppVar_20019 & cppMask_un_8_);
	cppVar_20020 = (cppVar_20019 >> 7) & cppMask_un_1_;
	cppVar_20022 = (cppVar_20020 == 0);
	if (cppVar_20022) {
	cppVar_20023 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20024 = (cppVar_20023 << 3) | 5;
	cppVar_20024 = (cppVar_20024 & cppMask_un_5_);
	cppVar_20025 = (0 << 5) | cppVar_20024;
	cppVar_20025 = (cppVar_20025 & cppMask_un_8_);
	cppVar_20026 = IRAM.rd(cppVar_20025);
	cppVar_20014 = cppVar_20026;
	} else {
	cppVar_20028 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20029 = (cppVar_20028 << 3) | 5;
	cppVar_20029 = (cppVar_20029 & cppMask_un_5_);
	cppVar_20030 = (0 << 5) | cppVar_20029;
	cppVar_20030 = (cppVar_20030 & cppMask_un_8_);
	cppVar_20032 = (cppVar_20030 == 128);
	if (cppVar_20032) {
	cppVar_20027 = P0;
	} else {
	cppVar_20034 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20035 = (cppVar_20034 << 3) | 5;
	cppVar_20035 = (cppVar_20035 & cppMask_un_5_);
	cppVar_20036 = (0 << 5) | cppVar_20035;
	cppVar_20036 = (cppVar_20036 & cppMask_un_8_);
	cppVar_20038 = (cppVar_20036 == 129);
	if (cppVar_20038) {
	cppVar_20033 = SP;
	} else {
	cppVar_20040 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20041 = (cppVar_20040 << 3) | 5;
	cppVar_20041 = (cppVar_20041 & cppMask_un_5_);
	cppVar_20042 = (0 << 5) | cppVar_20041;
	cppVar_20042 = (cppVar_20042 & cppMask_un_8_);
	cppVar_20044 = (cppVar_20042 == 130);
	if (cppVar_20044) {
	cppVar_20039 = DPL;
	} else {
	cppVar_20046 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20047 = (cppVar_20046 << 3) | 5;
	cppVar_20047 = (cppVar_20047 & cppMask_un_5_);
	cppVar_20048 = (0 << 5) | cppVar_20047;
	cppVar_20048 = (cppVar_20048 & cppMask_un_8_);
	cppVar_20050 = (cppVar_20048 == 131);
	if (cppVar_20050) {
	cppVar_20045 = DPH;
	} else {
	cppVar_20052 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20053 = (cppVar_20052 << 3) | 5;
	cppVar_20053 = (cppVar_20053 & cppMask_un_5_);
	cppVar_20054 = (0 << 5) | cppVar_20053;
	cppVar_20054 = (cppVar_20054 & cppMask_un_8_);
	cppVar_20056 = (cppVar_20054 == 135);
	if (cppVar_20056) {
	cppVar_20051 = PCON;
	} else {
	cppVar_20058 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20059 = (cppVar_20058 << 3) | 5;
	cppVar_20059 = (cppVar_20059 & cppMask_un_5_);
	cppVar_20060 = (0 << 5) | cppVar_20059;
	cppVar_20060 = (cppVar_20060 & cppMask_un_8_);
	cppVar_20062 = (cppVar_20060 == 136);
	if (cppVar_20062) {
	cppVar_20057 = TCON;
	} else {
	cppVar_20064 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20065 = (cppVar_20064 << 3) | 5;
	cppVar_20065 = (cppVar_20065 & cppMask_un_5_);
	cppVar_20066 = (0 << 5) | cppVar_20065;
	cppVar_20066 = (cppVar_20066 & cppMask_un_8_);
	cppVar_20068 = (cppVar_20066 == 137);
	if (cppVar_20068) {
	cppVar_20063 = TMOD;
	} else {
	cppVar_20070 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20071 = (cppVar_20070 << 3) | 5;
	cppVar_20071 = (cppVar_20071 & cppMask_un_5_);
	cppVar_20072 = (0 << 5) | cppVar_20071;
	cppVar_20072 = (cppVar_20072 & cppMask_un_8_);
	cppVar_20074 = (cppVar_20072 == 138);
	if (cppVar_20074) {
	cppVar_20069 = TL0;
	} else {
	cppVar_20076 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20077 = (cppVar_20076 << 3) | 5;
	cppVar_20077 = (cppVar_20077 & cppMask_un_5_);
	cppVar_20078 = (0 << 5) | cppVar_20077;
	cppVar_20078 = (cppVar_20078 & cppMask_un_8_);
	cppVar_20080 = (cppVar_20078 == 140);
	if (cppVar_20080) {
	cppVar_20075 = TH0;
	} else {
	cppVar_20082 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20083 = (cppVar_20082 << 3) | 5;
	cppVar_20083 = (cppVar_20083 & cppMask_un_5_);
	cppVar_20084 = (0 << 5) | cppVar_20083;
	cppVar_20084 = (cppVar_20084 & cppMask_un_8_);
	cppVar_20086 = (cppVar_20084 == 139);
	if (cppVar_20086) {
	cppVar_20081 = TL1;
	} else {
	cppVar_20088 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20089 = (cppVar_20088 << 3) | 5;
	cppVar_20089 = (cppVar_20089 & cppMask_un_5_);
	cppVar_20090 = (0 << 5) | cppVar_20089;
	cppVar_20090 = (cppVar_20090 & cppMask_un_8_);
	cppVar_20092 = (cppVar_20090 == 141);
	if (cppVar_20092) {
	cppVar_20087 = TH1;
	} else {
	cppVar_20094 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20095 = (cppVar_20094 << 3) | 5;
	cppVar_20095 = (cppVar_20095 & cppMask_un_5_);
	cppVar_20096 = (0 << 5) | cppVar_20095;
	cppVar_20096 = (cppVar_20096 & cppMask_un_8_);
	cppVar_20098 = (cppVar_20096 == 144);
	if (cppVar_20098) {
	cppVar_20093 = P1;
	} else {
	cppVar_20100 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20101 = (cppVar_20100 << 3) | 5;
	cppVar_20101 = (cppVar_20101 & cppMask_un_5_);
	cppVar_20102 = (0 << 5) | cppVar_20101;
	cppVar_20102 = (cppVar_20102 & cppMask_un_8_);
	cppVar_20104 = (cppVar_20102 == 152);
	if (cppVar_20104) {
	cppVar_20099 = SCON;
	} else {
	cppVar_20106 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20107 = (cppVar_20106 << 3) | 5;
	cppVar_20107 = (cppVar_20107 & cppMask_un_5_);
	cppVar_20108 = (0 << 5) | cppVar_20107;
	cppVar_20108 = (cppVar_20108 & cppMask_un_8_);
	cppVar_20110 = (cppVar_20108 == 153);
	if (cppVar_20110) {
	cppVar_20105 = SBUF;
	} else {
	cppVar_20112 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20113 = (cppVar_20112 << 3) | 5;
	cppVar_20113 = (cppVar_20113 & cppMask_un_5_);
	cppVar_20114 = (0 << 5) | cppVar_20113;
	cppVar_20114 = (cppVar_20114 & cppMask_un_8_);
	cppVar_20116 = (cppVar_20114 == 160);
	if (cppVar_20116) {
	cppVar_20111 = P2;
	} else {
	cppVar_20118 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20119 = (cppVar_20118 << 3) | 5;
	cppVar_20119 = (cppVar_20119 & cppMask_un_5_);
	cppVar_20120 = (0 << 5) | cppVar_20119;
	cppVar_20120 = (cppVar_20120 & cppMask_un_8_);
	cppVar_20122 = (cppVar_20120 == 168);
	if (cppVar_20122) {
	cppVar_20117 = IE;
	} else {
	cppVar_20124 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20125 = (cppVar_20124 << 3) | 5;
	cppVar_20125 = (cppVar_20125 & cppMask_un_5_);
	cppVar_20126 = (0 << 5) | cppVar_20125;
	cppVar_20126 = (cppVar_20126 & cppMask_un_8_);
	cppVar_20128 = (cppVar_20126 == 176);
	if (cppVar_20128) {
	cppVar_20123 = P3;
	} else {
	cppVar_20130 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20131 = (cppVar_20130 << 3) | 5;
	cppVar_20131 = (cppVar_20131 & cppMask_un_5_);
	cppVar_20132 = (0 << 5) | cppVar_20131;
	cppVar_20132 = (cppVar_20132 & cppMask_un_8_);
	cppVar_20134 = (cppVar_20132 == 184);
	if (cppVar_20134) {
	cppVar_20129 = IP;
	} else {
	cppVar_20136 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20137 = (cppVar_20136 << 3) | 5;
	cppVar_20137 = (cppVar_20137 & cppMask_un_5_);
	cppVar_20138 = (0 << 5) | cppVar_20137;
	cppVar_20138 = (cppVar_20138 & cppMask_un_8_);
	cppVar_20140 = (cppVar_20138 == 208);
	if (cppVar_20140) {
	cppVar_20135 = PSW;
	} else {
	cppVar_20142 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20143 = (cppVar_20142 << 3) | 5;
	cppVar_20143 = (cppVar_20143 & cppMask_un_5_);
	cppVar_20144 = (0 << 5) | cppVar_20143;
	cppVar_20144 = (cppVar_20144 & cppMask_un_8_);
	cppVar_20146 = (cppVar_20144 == 224);
	if (cppVar_20146) {
	cppVar_20141 = ACC;
	} else {
	cppVar_20148 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20149 = (cppVar_20148 << 3) | 5;
	cppVar_20149 = (cppVar_20149 & cppMask_un_5_);
	cppVar_20150 = (0 << 5) | cppVar_20149;
	cppVar_20150 = (cppVar_20150 & cppMask_un_8_);
	cppVar_20152 = (cppVar_20150 == 240);
	if (cppVar_20152) {
	cppVar_20147 = B;
	} else {
	cppVar_20147 = 0;
	}
	cppVar_20141 = cppVar_20147;
	}
	cppVar_20135 = cppVar_20141;
	}
	cppVar_20129 = cppVar_20135;
	}
	cppVar_20123 = cppVar_20129;
	}
	cppVar_20117 = cppVar_20123;
	}
	cppVar_20111 = cppVar_20117;
	}
	cppVar_20105 = cppVar_20111;
	}
	cppVar_20099 = cppVar_20105;
	}
	cppVar_20093 = cppVar_20099;
	}
	cppVar_20087 = cppVar_20093;
	}
	cppVar_20081 = cppVar_20087;
	}
	cppVar_20075 = cppVar_20081;
	}
	cppVar_20069 = cppVar_20075;
	}
	cppVar_20063 = cppVar_20069;
	}
	cppVar_20057 = cppVar_20063;
	}
	cppVar_20051 = cppVar_20057;
	}
	cppVar_20045 = cppVar_20051;
	}
	cppVar_20039 = cppVar_20045;
	}
	cppVar_20033 = cppVar_20039;
	}
	cppVar_20027 = cppVar_20033;
	}
	cppVar_20014 = cppVar_20027;
	}
	cppVar_20008 = cppVar_20014;
	} else {
	cppVar_20008 = IP;
	}
	cppVar_20004 = cppVar_20008;
	} else {
	cppVar_20155 = ROM.rd(PC);
	cppVar_20157 = (cppVar_20155 == 140);
	if (cppVar_20157) {
	cppVar_20160 = PC + 1;
	cppVar_20160 = (cppVar_20160 & cppMask_un_16_);
	cppVar_20161 = ROM.rd(cppVar_20160);
	cppVar_20163 = (cppVar_20161 == 184);
	if (cppVar_20163) {
	cppVar_20166 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20168 = (cppVar_20166 << 3) | 4;
	cppVar_20168 = (cppVar_20168 & cppMask_un_5_);
	cppVar_20169 = (0 << 5) | cppVar_20168;
	cppVar_20169 = (cppVar_20169 & cppMask_un_8_);
	cppVar_20170 = (cppVar_20169 >> 7) & cppMask_un_1_;
	cppVar_20172 = (cppVar_20170 == 0);
	if (cppVar_20172) {
	cppVar_20173 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20174 = (cppVar_20173 << 3) | 4;
	cppVar_20174 = (cppVar_20174 & cppMask_un_5_);
	cppVar_20175 = (0 << 5) | cppVar_20174;
	cppVar_20175 = (cppVar_20175 & cppMask_un_8_);
	cppVar_20176 = IRAM.rd(cppVar_20175);
	cppVar_20164 = cppVar_20176;
	} else {
	cppVar_20178 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20179 = (cppVar_20178 << 3) | 4;
	cppVar_20179 = (cppVar_20179 & cppMask_un_5_);
	cppVar_20180 = (0 << 5) | cppVar_20179;
	cppVar_20180 = (cppVar_20180 & cppMask_un_8_);
	cppVar_20182 = (cppVar_20180 == 128);
	if (cppVar_20182) {
	cppVar_20177 = P0;
	} else {
	cppVar_20184 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20185 = (cppVar_20184 << 3) | 4;
	cppVar_20185 = (cppVar_20185 & cppMask_un_5_);
	cppVar_20186 = (0 << 5) | cppVar_20185;
	cppVar_20186 = (cppVar_20186 & cppMask_un_8_);
	cppVar_20188 = (cppVar_20186 == 129);
	if (cppVar_20188) {
	cppVar_20183 = SP;
	} else {
	cppVar_20190 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20191 = (cppVar_20190 << 3) | 4;
	cppVar_20191 = (cppVar_20191 & cppMask_un_5_);
	cppVar_20192 = (0 << 5) | cppVar_20191;
	cppVar_20192 = (cppVar_20192 & cppMask_un_8_);
	cppVar_20194 = (cppVar_20192 == 130);
	if (cppVar_20194) {
	cppVar_20189 = DPL;
	} else {
	cppVar_20196 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20197 = (cppVar_20196 << 3) | 4;
	cppVar_20197 = (cppVar_20197 & cppMask_un_5_);
	cppVar_20198 = (0 << 5) | cppVar_20197;
	cppVar_20198 = (cppVar_20198 & cppMask_un_8_);
	cppVar_20200 = (cppVar_20198 == 131);
	if (cppVar_20200) {
	cppVar_20195 = DPH;
	} else {
	cppVar_20202 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20203 = (cppVar_20202 << 3) | 4;
	cppVar_20203 = (cppVar_20203 & cppMask_un_5_);
	cppVar_20204 = (0 << 5) | cppVar_20203;
	cppVar_20204 = (cppVar_20204 & cppMask_un_8_);
	cppVar_20206 = (cppVar_20204 == 135);
	if (cppVar_20206) {
	cppVar_20201 = PCON;
	} else {
	cppVar_20208 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20209 = (cppVar_20208 << 3) | 4;
	cppVar_20209 = (cppVar_20209 & cppMask_un_5_);
	cppVar_20210 = (0 << 5) | cppVar_20209;
	cppVar_20210 = (cppVar_20210 & cppMask_un_8_);
	cppVar_20212 = (cppVar_20210 == 136);
	if (cppVar_20212) {
	cppVar_20207 = TCON;
	} else {
	cppVar_20214 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20215 = (cppVar_20214 << 3) | 4;
	cppVar_20215 = (cppVar_20215 & cppMask_un_5_);
	cppVar_20216 = (0 << 5) | cppVar_20215;
	cppVar_20216 = (cppVar_20216 & cppMask_un_8_);
	cppVar_20218 = (cppVar_20216 == 137);
	if (cppVar_20218) {
	cppVar_20213 = TMOD;
	} else {
	cppVar_20220 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20221 = (cppVar_20220 << 3) | 4;
	cppVar_20221 = (cppVar_20221 & cppMask_un_5_);
	cppVar_20222 = (0 << 5) | cppVar_20221;
	cppVar_20222 = (cppVar_20222 & cppMask_un_8_);
	cppVar_20224 = (cppVar_20222 == 138);
	if (cppVar_20224) {
	cppVar_20219 = TL0;
	} else {
	cppVar_20226 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20227 = (cppVar_20226 << 3) | 4;
	cppVar_20227 = (cppVar_20227 & cppMask_un_5_);
	cppVar_20228 = (0 << 5) | cppVar_20227;
	cppVar_20228 = (cppVar_20228 & cppMask_un_8_);
	cppVar_20230 = (cppVar_20228 == 140);
	if (cppVar_20230) {
	cppVar_20225 = TH0;
	} else {
	cppVar_20232 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20233 = (cppVar_20232 << 3) | 4;
	cppVar_20233 = (cppVar_20233 & cppMask_un_5_);
	cppVar_20234 = (0 << 5) | cppVar_20233;
	cppVar_20234 = (cppVar_20234 & cppMask_un_8_);
	cppVar_20236 = (cppVar_20234 == 139);
	if (cppVar_20236) {
	cppVar_20231 = TL1;
	} else {
	cppVar_20238 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20239 = (cppVar_20238 << 3) | 4;
	cppVar_20239 = (cppVar_20239 & cppMask_un_5_);
	cppVar_20240 = (0 << 5) | cppVar_20239;
	cppVar_20240 = (cppVar_20240 & cppMask_un_8_);
	cppVar_20242 = (cppVar_20240 == 141);
	if (cppVar_20242) {
	cppVar_20237 = TH1;
	} else {
	cppVar_20244 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20245 = (cppVar_20244 << 3) | 4;
	cppVar_20245 = (cppVar_20245 & cppMask_un_5_);
	cppVar_20246 = (0 << 5) | cppVar_20245;
	cppVar_20246 = (cppVar_20246 & cppMask_un_8_);
	cppVar_20248 = (cppVar_20246 == 144);
	if (cppVar_20248) {
	cppVar_20243 = P1;
	} else {
	cppVar_20250 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20251 = (cppVar_20250 << 3) | 4;
	cppVar_20251 = (cppVar_20251 & cppMask_un_5_);
	cppVar_20252 = (0 << 5) | cppVar_20251;
	cppVar_20252 = (cppVar_20252 & cppMask_un_8_);
	cppVar_20254 = (cppVar_20252 == 152);
	if (cppVar_20254) {
	cppVar_20249 = SCON;
	} else {
	cppVar_20256 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20257 = (cppVar_20256 << 3) | 4;
	cppVar_20257 = (cppVar_20257 & cppMask_un_5_);
	cppVar_20258 = (0 << 5) | cppVar_20257;
	cppVar_20258 = (cppVar_20258 & cppMask_un_8_);
	cppVar_20260 = (cppVar_20258 == 153);
	if (cppVar_20260) {
	cppVar_20255 = SBUF;
	} else {
	cppVar_20262 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20263 = (cppVar_20262 << 3) | 4;
	cppVar_20263 = (cppVar_20263 & cppMask_un_5_);
	cppVar_20264 = (0 << 5) | cppVar_20263;
	cppVar_20264 = (cppVar_20264 & cppMask_un_8_);
	cppVar_20266 = (cppVar_20264 == 160);
	if (cppVar_20266) {
	cppVar_20261 = P2;
	} else {
	cppVar_20268 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20269 = (cppVar_20268 << 3) | 4;
	cppVar_20269 = (cppVar_20269 & cppMask_un_5_);
	cppVar_20270 = (0 << 5) | cppVar_20269;
	cppVar_20270 = (cppVar_20270 & cppMask_un_8_);
	cppVar_20272 = (cppVar_20270 == 168);
	if (cppVar_20272) {
	cppVar_20267 = IE;
	} else {
	cppVar_20274 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20275 = (cppVar_20274 << 3) | 4;
	cppVar_20275 = (cppVar_20275 & cppMask_un_5_);
	cppVar_20276 = (0 << 5) | cppVar_20275;
	cppVar_20276 = (cppVar_20276 & cppMask_un_8_);
	cppVar_20278 = (cppVar_20276 == 176);
	if (cppVar_20278) {
	cppVar_20273 = P3;
	} else {
	cppVar_20280 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20281 = (cppVar_20280 << 3) | 4;
	cppVar_20281 = (cppVar_20281 & cppMask_un_5_);
	cppVar_20282 = (0 << 5) | cppVar_20281;
	cppVar_20282 = (cppVar_20282 & cppMask_un_8_);
	cppVar_20284 = (cppVar_20282 == 184);
	if (cppVar_20284) {
	cppVar_20279 = IP;
	} else {
	cppVar_20286 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20287 = (cppVar_20286 << 3) | 4;
	cppVar_20287 = (cppVar_20287 & cppMask_un_5_);
	cppVar_20288 = (0 << 5) | cppVar_20287;
	cppVar_20288 = (cppVar_20288 & cppMask_un_8_);
	cppVar_20290 = (cppVar_20288 == 208);
	if (cppVar_20290) {
	cppVar_20285 = PSW;
	} else {
	cppVar_20292 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20293 = (cppVar_20292 << 3) | 4;
	cppVar_20293 = (cppVar_20293 & cppMask_un_5_);
	cppVar_20294 = (0 << 5) | cppVar_20293;
	cppVar_20294 = (cppVar_20294 & cppMask_un_8_);
	cppVar_20296 = (cppVar_20294 == 224);
	if (cppVar_20296) {
	cppVar_20291 = ACC;
	} else {
	cppVar_20298 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20299 = (cppVar_20298 << 3) | 4;
	cppVar_20299 = (cppVar_20299 & cppMask_un_5_);
	cppVar_20300 = (0 << 5) | cppVar_20299;
	cppVar_20300 = (cppVar_20300 & cppMask_un_8_);
	cppVar_20302 = (cppVar_20300 == 240);
	if (cppVar_20302) {
	cppVar_20297 = B;
	} else {
	cppVar_20297 = 0;
	}
	cppVar_20291 = cppVar_20297;
	}
	cppVar_20285 = cppVar_20291;
	}
	cppVar_20279 = cppVar_20285;
	}
	cppVar_20273 = cppVar_20279;
	}
	cppVar_20267 = cppVar_20273;
	}
	cppVar_20261 = cppVar_20267;
	}
	cppVar_20255 = cppVar_20261;
	}
	cppVar_20249 = cppVar_20255;
	}
	cppVar_20243 = cppVar_20249;
	}
	cppVar_20237 = cppVar_20243;
	}
	cppVar_20231 = cppVar_20237;
	}
	cppVar_20225 = cppVar_20231;
	}
	cppVar_20219 = cppVar_20225;
	}
	cppVar_20213 = cppVar_20219;
	}
	cppVar_20207 = cppVar_20213;
	}
	cppVar_20201 = cppVar_20207;
	}
	cppVar_20195 = cppVar_20201;
	}
	cppVar_20189 = cppVar_20195;
	}
	cppVar_20183 = cppVar_20189;
	}
	cppVar_20177 = cppVar_20183;
	}
	cppVar_20164 = cppVar_20177;
	}
	cppVar_20158 = cppVar_20164;
	} else {
	cppVar_20158 = IP;
	}
	cppVar_20154 = cppVar_20158;
	} else {
	cppVar_20305 = ROM.rd(PC);
	cppVar_20307 = (cppVar_20305 == 139);
	if (cppVar_20307) {
	cppVar_20310 = PC + 1;
	cppVar_20310 = (cppVar_20310 & cppMask_un_16_);
	cppVar_20311 = ROM.rd(cppVar_20310);
	cppVar_20313 = (cppVar_20311 == 184);
	if (cppVar_20313) {
	cppVar_20316 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20318 = (cppVar_20316 << 3) | 3;
	cppVar_20318 = (cppVar_20318 & cppMask_un_5_);
	cppVar_20319 = (0 << 5) | cppVar_20318;
	cppVar_20319 = (cppVar_20319 & cppMask_un_8_);
	cppVar_20320 = (cppVar_20319 >> 7) & cppMask_un_1_;
	cppVar_20322 = (cppVar_20320 == 0);
	if (cppVar_20322) {
	cppVar_20323 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20324 = (cppVar_20323 << 3) | 3;
	cppVar_20324 = (cppVar_20324 & cppMask_un_5_);
	cppVar_20325 = (0 << 5) | cppVar_20324;
	cppVar_20325 = (cppVar_20325 & cppMask_un_8_);
	cppVar_20326 = IRAM.rd(cppVar_20325);
	cppVar_20314 = cppVar_20326;
	} else {
	cppVar_20328 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20329 = (cppVar_20328 << 3) | 3;
	cppVar_20329 = (cppVar_20329 & cppMask_un_5_);
	cppVar_20330 = (0 << 5) | cppVar_20329;
	cppVar_20330 = (cppVar_20330 & cppMask_un_8_);
	cppVar_20332 = (cppVar_20330 == 128);
	if (cppVar_20332) {
	cppVar_20327 = P0;
	} else {
	cppVar_20334 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20335 = (cppVar_20334 << 3) | 3;
	cppVar_20335 = (cppVar_20335 & cppMask_un_5_);
	cppVar_20336 = (0 << 5) | cppVar_20335;
	cppVar_20336 = (cppVar_20336 & cppMask_un_8_);
	cppVar_20338 = (cppVar_20336 == 129);
	if (cppVar_20338) {
	cppVar_20333 = SP;
	} else {
	cppVar_20340 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20341 = (cppVar_20340 << 3) | 3;
	cppVar_20341 = (cppVar_20341 & cppMask_un_5_);
	cppVar_20342 = (0 << 5) | cppVar_20341;
	cppVar_20342 = (cppVar_20342 & cppMask_un_8_);
	cppVar_20344 = (cppVar_20342 == 130);
	if (cppVar_20344) {
	cppVar_20339 = DPL;
	} else {
	cppVar_20346 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20347 = (cppVar_20346 << 3) | 3;
	cppVar_20347 = (cppVar_20347 & cppMask_un_5_);
	cppVar_20348 = (0 << 5) | cppVar_20347;
	cppVar_20348 = (cppVar_20348 & cppMask_un_8_);
	cppVar_20350 = (cppVar_20348 == 131);
	if (cppVar_20350) {
	cppVar_20345 = DPH;
	} else {
	cppVar_20352 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20353 = (cppVar_20352 << 3) | 3;
	cppVar_20353 = (cppVar_20353 & cppMask_un_5_);
	cppVar_20354 = (0 << 5) | cppVar_20353;
	cppVar_20354 = (cppVar_20354 & cppMask_un_8_);
	cppVar_20356 = (cppVar_20354 == 135);
	if (cppVar_20356) {
	cppVar_20351 = PCON;
	} else {
	cppVar_20358 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20359 = (cppVar_20358 << 3) | 3;
	cppVar_20359 = (cppVar_20359 & cppMask_un_5_);
	cppVar_20360 = (0 << 5) | cppVar_20359;
	cppVar_20360 = (cppVar_20360 & cppMask_un_8_);
	cppVar_20362 = (cppVar_20360 == 136);
	if (cppVar_20362) {
	cppVar_20357 = TCON;
	} else {
	cppVar_20364 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20365 = (cppVar_20364 << 3) | 3;
	cppVar_20365 = (cppVar_20365 & cppMask_un_5_);
	cppVar_20366 = (0 << 5) | cppVar_20365;
	cppVar_20366 = (cppVar_20366 & cppMask_un_8_);
	cppVar_20368 = (cppVar_20366 == 137);
	if (cppVar_20368) {
	cppVar_20363 = TMOD;
	} else {
	cppVar_20370 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20371 = (cppVar_20370 << 3) | 3;
	cppVar_20371 = (cppVar_20371 & cppMask_un_5_);
	cppVar_20372 = (0 << 5) | cppVar_20371;
	cppVar_20372 = (cppVar_20372 & cppMask_un_8_);
	cppVar_20374 = (cppVar_20372 == 138);
	if (cppVar_20374) {
	cppVar_20369 = TL0;
	} else {
	cppVar_20376 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20377 = (cppVar_20376 << 3) | 3;
	cppVar_20377 = (cppVar_20377 & cppMask_un_5_);
	cppVar_20378 = (0 << 5) | cppVar_20377;
	cppVar_20378 = (cppVar_20378 & cppMask_un_8_);
	cppVar_20380 = (cppVar_20378 == 140);
	if (cppVar_20380) {
	cppVar_20375 = TH0;
	} else {
	cppVar_20382 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20383 = (cppVar_20382 << 3) | 3;
	cppVar_20383 = (cppVar_20383 & cppMask_un_5_);
	cppVar_20384 = (0 << 5) | cppVar_20383;
	cppVar_20384 = (cppVar_20384 & cppMask_un_8_);
	cppVar_20386 = (cppVar_20384 == 139);
	if (cppVar_20386) {
	cppVar_20381 = TL1;
	} else {
	cppVar_20388 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20389 = (cppVar_20388 << 3) | 3;
	cppVar_20389 = (cppVar_20389 & cppMask_un_5_);
	cppVar_20390 = (0 << 5) | cppVar_20389;
	cppVar_20390 = (cppVar_20390 & cppMask_un_8_);
	cppVar_20392 = (cppVar_20390 == 141);
	if (cppVar_20392) {
	cppVar_20387 = TH1;
	} else {
	cppVar_20394 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20395 = (cppVar_20394 << 3) | 3;
	cppVar_20395 = (cppVar_20395 & cppMask_un_5_);
	cppVar_20396 = (0 << 5) | cppVar_20395;
	cppVar_20396 = (cppVar_20396 & cppMask_un_8_);
	cppVar_20398 = (cppVar_20396 == 144);
	if (cppVar_20398) {
	cppVar_20393 = P1;
	} else {
	cppVar_20400 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20401 = (cppVar_20400 << 3) | 3;
	cppVar_20401 = (cppVar_20401 & cppMask_un_5_);
	cppVar_20402 = (0 << 5) | cppVar_20401;
	cppVar_20402 = (cppVar_20402 & cppMask_un_8_);
	cppVar_20404 = (cppVar_20402 == 152);
	if (cppVar_20404) {
	cppVar_20399 = SCON;
	} else {
	cppVar_20406 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20407 = (cppVar_20406 << 3) | 3;
	cppVar_20407 = (cppVar_20407 & cppMask_un_5_);
	cppVar_20408 = (0 << 5) | cppVar_20407;
	cppVar_20408 = (cppVar_20408 & cppMask_un_8_);
	cppVar_20410 = (cppVar_20408 == 153);
	if (cppVar_20410) {
	cppVar_20405 = SBUF;
	} else {
	cppVar_20412 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20413 = (cppVar_20412 << 3) | 3;
	cppVar_20413 = (cppVar_20413 & cppMask_un_5_);
	cppVar_20414 = (0 << 5) | cppVar_20413;
	cppVar_20414 = (cppVar_20414 & cppMask_un_8_);
	cppVar_20416 = (cppVar_20414 == 160);
	if (cppVar_20416) {
	cppVar_20411 = P2;
	} else {
	cppVar_20418 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20419 = (cppVar_20418 << 3) | 3;
	cppVar_20419 = (cppVar_20419 & cppMask_un_5_);
	cppVar_20420 = (0 << 5) | cppVar_20419;
	cppVar_20420 = (cppVar_20420 & cppMask_un_8_);
	cppVar_20422 = (cppVar_20420 == 168);
	if (cppVar_20422) {
	cppVar_20417 = IE;
	} else {
	cppVar_20424 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20425 = (cppVar_20424 << 3) | 3;
	cppVar_20425 = (cppVar_20425 & cppMask_un_5_);
	cppVar_20426 = (0 << 5) | cppVar_20425;
	cppVar_20426 = (cppVar_20426 & cppMask_un_8_);
	cppVar_20428 = (cppVar_20426 == 176);
	if (cppVar_20428) {
	cppVar_20423 = P3;
	} else {
	cppVar_20430 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20431 = (cppVar_20430 << 3) | 3;
	cppVar_20431 = (cppVar_20431 & cppMask_un_5_);
	cppVar_20432 = (0 << 5) | cppVar_20431;
	cppVar_20432 = (cppVar_20432 & cppMask_un_8_);
	cppVar_20434 = (cppVar_20432 == 184);
	if (cppVar_20434) {
	cppVar_20429 = IP;
	} else {
	cppVar_20436 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20437 = (cppVar_20436 << 3) | 3;
	cppVar_20437 = (cppVar_20437 & cppMask_un_5_);
	cppVar_20438 = (0 << 5) | cppVar_20437;
	cppVar_20438 = (cppVar_20438 & cppMask_un_8_);
	cppVar_20440 = (cppVar_20438 == 208);
	if (cppVar_20440) {
	cppVar_20435 = PSW;
	} else {
	cppVar_20442 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20443 = (cppVar_20442 << 3) | 3;
	cppVar_20443 = (cppVar_20443 & cppMask_un_5_);
	cppVar_20444 = (0 << 5) | cppVar_20443;
	cppVar_20444 = (cppVar_20444 & cppMask_un_8_);
	cppVar_20446 = (cppVar_20444 == 224);
	if (cppVar_20446) {
	cppVar_20441 = ACC;
	} else {
	cppVar_20448 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20449 = (cppVar_20448 << 3) | 3;
	cppVar_20449 = (cppVar_20449 & cppMask_un_5_);
	cppVar_20450 = (0 << 5) | cppVar_20449;
	cppVar_20450 = (cppVar_20450 & cppMask_un_8_);
	cppVar_20452 = (cppVar_20450 == 240);
	if (cppVar_20452) {
	cppVar_20447 = B;
	} else {
	cppVar_20447 = 0;
	}
	cppVar_20441 = cppVar_20447;
	}
	cppVar_20435 = cppVar_20441;
	}
	cppVar_20429 = cppVar_20435;
	}
	cppVar_20423 = cppVar_20429;
	}
	cppVar_20417 = cppVar_20423;
	}
	cppVar_20411 = cppVar_20417;
	}
	cppVar_20405 = cppVar_20411;
	}
	cppVar_20399 = cppVar_20405;
	}
	cppVar_20393 = cppVar_20399;
	}
	cppVar_20387 = cppVar_20393;
	}
	cppVar_20381 = cppVar_20387;
	}
	cppVar_20375 = cppVar_20381;
	}
	cppVar_20369 = cppVar_20375;
	}
	cppVar_20363 = cppVar_20369;
	}
	cppVar_20357 = cppVar_20363;
	}
	cppVar_20351 = cppVar_20357;
	}
	cppVar_20345 = cppVar_20351;
	}
	cppVar_20339 = cppVar_20345;
	}
	cppVar_20333 = cppVar_20339;
	}
	cppVar_20327 = cppVar_20333;
	}
	cppVar_20314 = cppVar_20327;
	}
	cppVar_20308 = cppVar_20314;
	} else {
	cppVar_20308 = IP;
	}
	cppVar_20304 = cppVar_20308;
	} else {
	cppVar_20455 = ROM.rd(PC);
	cppVar_20457 = (cppVar_20455 == 138);
	if (cppVar_20457) {
	cppVar_20460 = PC + 1;
	cppVar_20460 = (cppVar_20460 & cppMask_un_16_);
	cppVar_20461 = ROM.rd(cppVar_20460);
	cppVar_20463 = (cppVar_20461 == 184);
	if (cppVar_20463) {
	cppVar_20466 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20468 = (cppVar_20466 << 3) | 2;
	cppVar_20468 = (cppVar_20468 & cppMask_un_5_);
	cppVar_20469 = (0 << 5) | cppVar_20468;
	cppVar_20469 = (cppVar_20469 & cppMask_un_8_);
	cppVar_20470 = (cppVar_20469 >> 7) & cppMask_un_1_;
	cppVar_20472 = (cppVar_20470 == 0);
	if (cppVar_20472) {
	cppVar_20473 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20474 = (cppVar_20473 << 3) | 2;
	cppVar_20474 = (cppVar_20474 & cppMask_un_5_);
	cppVar_20475 = (0 << 5) | cppVar_20474;
	cppVar_20475 = (cppVar_20475 & cppMask_un_8_);
	cppVar_20476 = IRAM.rd(cppVar_20475);
	cppVar_20464 = cppVar_20476;
	} else {
	cppVar_20478 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20479 = (cppVar_20478 << 3) | 2;
	cppVar_20479 = (cppVar_20479 & cppMask_un_5_);
	cppVar_20480 = (0 << 5) | cppVar_20479;
	cppVar_20480 = (cppVar_20480 & cppMask_un_8_);
	cppVar_20482 = (cppVar_20480 == 128);
	if (cppVar_20482) {
	cppVar_20477 = P0;
	} else {
	cppVar_20484 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20485 = (cppVar_20484 << 3) | 2;
	cppVar_20485 = (cppVar_20485 & cppMask_un_5_);
	cppVar_20486 = (0 << 5) | cppVar_20485;
	cppVar_20486 = (cppVar_20486 & cppMask_un_8_);
	cppVar_20488 = (cppVar_20486 == 129);
	if (cppVar_20488) {
	cppVar_20483 = SP;
	} else {
	cppVar_20490 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20491 = (cppVar_20490 << 3) | 2;
	cppVar_20491 = (cppVar_20491 & cppMask_un_5_);
	cppVar_20492 = (0 << 5) | cppVar_20491;
	cppVar_20492 = (cppVar_20492 & cppMask_un_8_);
	cppVar_20494 = (cppVar_20492 == 130);
	if (cppVar_20494) {
	cppVar_20489 = DPL;
	} else {
	cppVar_20496 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20497 = (cppVar_20496 << 3) | 2;
	cppVar_20497 = (cppVar_20497 & cppMask_un_5_);
	cppVar_20498 = (0 << 5) | cppVar_20497;
	cppVar_20498 = (cppVar_20498 & cppMask_un_8_);
	cppVar_20500 = (cppVar_20498 == 131);
	if (cppVar_20500) {
	cppVar_20495 = DPH;
	} else {
	cppVar_20502 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20503 = (cppVar_20502 << 3) | 2;
	cppVar_20503 = (cppVar_20503 & cppMask_un_5_);
	cppVar_20504 = (0 << 5) | cppVar_20503;
	cppVar_20504 = (cppVar_20504 & cppMask_un_8_);
	cppVar_20506 = (cppVar_20504 == 135);
	if (cppVar_20506) {
	cppVar_20501 = PCON;
	} else {
	cppVar_20508 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20509 = (cppVar_20508 << 3) | 2;
	cppVar_20509 = (cppVar_20509 & cppMask_un_5_);
	cppVar_20510 = (0 << 5) | cppVar_20509;
	cppVar_20510 = (cppVar_20510 & cppMask_un_8_);
	cppVar_20512 = (cppVar_20510 == 136);
	if (cppVar_20512) {
	cppVar_20507 = TCON;
	} else {
	cppVar_20514 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20515 = (cppVar_20514 << 3) | 2;
	cppVar_20515 = (cppVar_20515 & cppMask_un_5_);
	cppVar_20516 = (0 << 5) | cppVar_20515;
	cppVar_20516 = (cppVar_20516 & cppMask_un_8_);
	cppVar_20518 = (cppVar_20516 == 137);
	if (cppVar_20518) {
	cppVar_20513 = TMOD;
	} else {
	cppVar_20520 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20521 = (cppVar_20520 << 3) | 2;
	cppVar_20521 = (cppVar_20521 & cppMask_un_5_);
	cppVar_20522 = (0 << 5) | cppVar_20521;
	cppVar_20522 = (cppVar_20522 & cppMask_un_8_);
	cppVar_20524 = (cppVar_20522 == 138);
	if (cppVar_20524) {
	cppVar_20519 = TL0;
	} else {
	cppVar_20526 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20527 = (cppVar_20526 << 3) | 2;
	cppVar_20527 = (cppVar_20527 & cppMask_un_5_);
	cppVar_20528 = (0 << 5) | cppVar_20527;
	cppVar_20528 = (cppVar_20528 & cppMask_un_8_);
	cppVar_20530 = (cppVar_20528 == 140);
	if (cppVar_20530) {
	cppVar_20525 = TH0;
	} else {
	cppVar_20532 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20533 = (cppVar_20532 << 3) | 2;
	cppVar_20533 = (cppVar_20533 & cppMask_un_5_);
	cppVar_20534 = (0 << 5) | cppVar_20533;
	cppVar_20534 = (cppVar_20534 & cppMask_un_8_);
	cppVar_20536 = (cppVar_20534 == 139);
	if (cppVar_20536) {
	cppVar_20531 = TL1;
	} else {
	cppVar_20538 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20539 = (cppVar_20538 << 3) | 2;
	cppVar_20539 = (cppVar_20539 & cppMask_un_5_);
	cppVar_20540 = (0 << 5) | cppVar_20539;
	cppVar_20540 = (cppVar_20540 & cppMask_un_8_);
	cppVar_20542 = (cppVar_20540 == 141);
	if (cppVar_20542) {
	cppVar_20537 = TH1;
	} else {
	cppVar_20544 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20545 = (cppVar_20544 << 3) | 2;
	cppVar_20545 = (cppVar_20545 & cppMask_un_5_);
	cppVar_20546 = (0 << 5) | cppVar_20545;
	cppVar_20546 = (cppVar_20546 & cppMask_un_8_);
	cppVar_20548 = (cppVar_20546 == 144);
	if (cppVar_20548) {
	cppVar_20543 = P1;
	} else {
	cppVar_20550 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20551 = (cppVar_20550 << 3) | 2;
	cppVar_20551 = (cppVar_20551 & cppMask_un_5_);
	cppVar_20552 = (0 << 5) | cppVar_20551;
	cppVar_20552 = (cppVar_20552 & cppMask_un_8_);
	cppVar_20554 = (cppVar_20552 == 152);
	if (cppVar_20554) {
	cppVar_20549 = SCON;
	} else {
	cppVar_20556 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20557 = (cppVar_20556 << 3) | 2;
	cppVar_20557 = (cppVar_20557 & cppMask_un_5_);
	cppVar_20558 = (0 << 5) | cppVar_20557;
	cppVar_20558 = (cppVar_20558 & cppMask_un_8_);
	cppVar_20560 = (cppVar_20558 == 153);
	if (cppVar_20560) {
	cppVar_20555 = SBUF;
	} else {
	cppVar_20562 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20563 = (cppVar_20562 << 3) | 2;
	cppVar_20563 = (cppVar_20563 & cppMask_un_5_);
	cppVar_20564 = (0 << 5) | cppVar_20563;
	cppVar_20564 = (cppVar_20564 & cppMask_un_8_);
	cppVar_20566 = (cppVar_20564 == 160);
	if (cppVar_20566) {
	cppVar_20561 = P2;
	} else {
	cppVar_20568 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20569 = (cppVar_20568 << 3) | 2;
	cppVar_20569 = (cppVar_20569 & cppMask_un_5_);
	cppVar_20570 = (0 << 5) | cppVar_20569;
	cppVar_20570 = (cppVar_20570 & cppMask_un_8_);
	cppVar_20572 = (cppVar_20570 == 168);
	if (cppVar_20572) {
	cppVar_20567 = IE;
	} else {
	cppVar_20574 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20575 = (cppVar_20574 << 3) | 2;
	cppVar_20575 = (cppVar_20575 & cppMask_un_5_);
	cppVar_20576 = (0 << 5) | cppVar_20575;
	cppVar_20576 = (cppVar_20576 & cppMask_un_8_);
	cppVar_20578 = (cppVar_20576 == 176);
	if (cppVar_20578) {
	cppVar_20573 = P3;
	} else {
	cppVar_20580 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20581 = (cppVar_20580 << 3) | 2;
	cppVar_20581 = (cppVar_20581 & cppMask_un_5_);
	cppVar_20582 = (0 << 5) | cppVar_20581;
	cppVar_20582 = (cppVar_20582 & cppMask_un_8_);
	cppVar_20584 = (cppVar_20582 == 184);
	if (cppVar_20584) {
	cppVar_20579 = IP;
	} else {
	cppVar_20586 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20587 = (cppVar_20586 << 3) | 2;
	cppVar_20587 = (cppVar_20587 & cppMask_un_5_);
	cppVar_20588 = (0 << 5) | cppVar_20587;
	cppVar_20588 = (cppVar_20588 & cppMask_un_8_);
	cppVar_20590 = (cppVar_20588 == 208);
	if (cppVar_20590) {
	cppVar_20585 = PSW;
	} else {
	cppVar_20592 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20593 = (cppVar_20592 << 3) | 2;
	cppVar_20593 = (cppVar_20593 & cppMask_un_5_);
	cppVar_20594 = (0 << 5) | cppVar_20593;
	cppVar_20594 = (cppVar_20594 & cppMask_un_8_);
	cppVar_20596 = (cppVar_20594 == 224);
	if (cppVar_20596) {
	cppVar_20591 = ACC;
	} else {
	cppVar_20598 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20599 = (cppVar_20598 << 3) | 2;
	cppVar_20599 = (cppVar_20599 & cppMask_un_5_);
	cppVar_20600 = (0 << 5) | cppVar_20599;
	cppVar_20600 = (cppVar_20600 & cppMask_un_8_);
	cppVar_20602 = (cppVar_20600 == 240);
	if (cppVar_20602) {
	cppVar_20597 = B;
	} else {
	cppVar_20597 = 0;
	}
	cppVar_20591 = cppVar_20597;
	}
	cppVar_20585 = cppVar_20591;
	}
	cppVar_20579 = cppVar_20585;
	}
	cppVar_20573 = cppVar_20579;
	}
	cppVar_20567 = cppVar_20573;
	}
	cppVar_20561 = cppVar_20567;
	}
	cppVar_20555 = cppVar_20561;
	}
	cppVar_20549 = cppVar_20555;
	}
	cppVar_20543 = cppVar_20549;
	}
	cppVar_20537 = cppVar_20543;
	}
	cppVar_20531 = cppVar_20537;
	}
	cppVar_20525 = cppVar_20531;
	}
	cppVar_20519 = cppVar_20525;
	}
	cppVar_20513 = cppVar_20519;
	}
	cppVar_20507 = cppVar_20513;
	}
	cppVar_20501 = cppVar_20507;
	}
	cppVar_20495 = cppVar_20501;
	}
	cppVar_20489 = cppVar_20495;
	}
	cppVar_20483 = cppVar_20489;
	}
	cppVar_20477 = cppVar_20483;
	}
	cppVar_20464 = cppVar_20477;
	}
	cppVar_20458 = cppVar_20464;
	} else {
	cppVar_20458 = IP;
	}
	cppVar_20454 = cppVar_20458;
	} else {
	cppVar_20605 = ROM.rd(PC);
	cppVar_20607 = (cppVar_20605 == 137);
	if (cppVar_20607) {
	cppVar_20610 = PC + 1;
	cppVar_20610 = (cppVar_20610 & cppMask_un_16_);
	cppVar_20611 = ROM.rd(cppVar_20610);
	cppVar_20613 = (cppVar_20611 == 184);
	if (cppVar_20613) {
	cppVar_20616 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20618 = (cppVar_20616 << 3) | 1;
	cppVar_20618 = (cppVar_20618 & cppMask_un_5_);
	cppVar_20619 = (0 << 5) | cppVar_20618;
	cppVar_20619 = (cppVar_20619 & cppMask_un_8_);
	cppVar_20620 = (cppVar_20619 >> 7) & cppMask_un_1_;
	cppVar_20622 = (cppVar_20620 == 0);
	if (cppVar_20622) {
	cppVar_20623 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20624 = (cppVar_20623 << 3) | 1;
	cppVar_20624 = (cppVar_20624 & cppMask_un_5_);
	cppVar_20625 = (0 << 5) | cppVar_20624;
	cppVar_20625 = (cppVar_20625 & cppMask_un_8_);
	cppVar_20626 = IRAM.rd(cppVar_20625);
	cppVar_20614 = cppVar_20626;
	} else {
	cppVar_20628 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20629 = (cppVar_20628 << 3) | 1;
	cppVar_20629 = (cppVar_20629 & cppMask_un_5_);
	cppVar_20630 = (0 << 5) | cppVar_20629;
	cppVar_20630 = (cppVar_20630 & cppMask_un_8_);
	cppVar_20632 = (cppVar_20630 == 128);
	if (cppVar_20632) {
	cppVar_20627 = P0;
	} else {
	cppVar_20634 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20635 = (cppVar_20634 << 3) | 1;
	cppVar_20635 = (cppVar_20635 & cppMask_un_5_);
	cppVar_20636 = (0 << 5) | cppVar_20635;
	cppVar_20636 = (cppVar_20636 & cppMask_un_8_);
	cppVar_20638 = (cppVar_20636 == 129);
	if (cppVar_20638) {
	cppVar_20633 = SP;
	} else {
	cppVar_20640 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20641 = (cppVar_20640 << 3) | 1;
	cppVar_20641 = (cppVar_20641 & cppMask_un_5_);
	cppVar_20642 = (0 << 5) | cppVar_20641;
	cppVar_20642 = (cppVar_20642 & cppMask_un_8_);
	cppVar_20644 = (cppVar_20642 == 130);
	if (cppVar_20644) {
	cppVar_20639 = DPL;
	} else {
	cppVar_20646 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20647 = (cppVar_20646 << 3) | 1;
	cppVar_20647 = (cppVar_20647 & cppMask_un_5_);
	cppVar_20648 = (0 << 5) | cppVar_20647;
	cppVar_20648 = (cppVar_20648 & cppMask_un_8_);
	cppVar_20650 = (cppVar_20648 == 131);
	if (cppVar_20650) {
	cppVar_20645 = DPH;
	} else {
	cppVar_20652 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20653 = (cppVar_20652 << 3) | 1;
	cppVar_20653 = (cppVar_20653 & cppMask_un_5_);
	cppVar_20654 = (0 << 5) | cppVar_20653;
	cppVar_20654 = (cppVar_20654 & cppMask_un_8_);
	cppVar_20656 = (cppVar_20654 == 135);
	if (cppVar_20656) {
	cppVar_20651 = PCON;
	} else {
	cppVar_20658 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20659 = (cppVar_20658 << 3) | 1;
	cppVar_20659 = (cppVar_20659 & cppMask_un_5_);
	cppVar_20660 = (0 << 5) | cppVar_20659;
	cppVar_20660 = (cppVar_20660 & cppMask_un_8_);
	cppVar_20662 = (cppVar_20660 == 136);
	if (cppVar_20662) {
	cppVar_20657 = TCON;
	} else {
	cppVar_20664 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20665 = (cppVar_20664 << 3) | 1;
	cppVar_20665 = (cppVar_20665 & cppMask_un_5_);
	cppVar_20666 = (0 << 5) | cppVar_20665;
	cppVar_20666 = (cppVar_20666 & cppMask_un_8_);
	cppVar_20668 = (cppVar_20666 == 137);
	if (cppVar_20668) {
	cppVar_20663 = TMOD;
	} else {
	cppVar_20670 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20671 = (cppVar_20670 << 3) | 1;
	cppVar_20671 = (cppVar_20671 & cppMask_un_5_);
	cppVar_20672 = (0 << 5) | cppVar_20671;
	cppVar_20672 = (cppVar_20672 & cppMask_un_8_);
	cppVar_20674 = (cppVar_20672 == 138);
	if (cppVar_20674) {
	cppVar_20669 = TL0;
	} else {
	cppVar_20676 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20677 = (cppVar_20676 << 3) | 1;
	cppVar_20677 = (cppVar_20677 & cppMask_un_5_);
	cppVar_20678 = (0 << 5) | cppVar_20677;
	cppVar_20678 = (cppVar_20678 & cppMask_un_8_);
	cppVar_20680 = (cppVar_20678 == 140);
	if (cppVar_20680) {
	cppVar_20675 = TH0;
	} else {
	cppVar_20682 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20683 = (cppVar_20682 << 3) | 1;
	cppVar_20683 = (cppVar_20683 & cppMask_un_5_);
	cppVar_20684 = (0 << 5) | cppVar_20683;
	cppVar_20684 = (cppVar_20684 & cppMask_un_8_);
	cppVar_20686 = (cppVar_20684 == 139);
	if (cppVar_20686) {
	cppVar_20681 = TL1;
	} else {
	cppVar_20688 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20689 = (cppVar_20688 << 3) | 1;
	cppVar_20689 = (cppVar_20689 & cppMask_un_5_);
	cppVar_20690 = (0 << 5) | cppVar_20689;
	cppVar_20690 = (cppVar_20690 & cppMask_un_8_);
	cppVar_20692 = (cppVar_20690 == 141);
	if (cppVar_20692) {
	cppVar_20687 = TH1;
	} else {
	cppVar_20694 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20695 = (cppVar_20694 << 3) | 1;
	cppVar_20695 = (cppVar_20695 & cppMask_un_5_);
	cppVar_20696 = (0 << 5) | cppVar_20695;
	cppVar_20696 = (cppVar_20696 & cppMask_un_8_);
	cppVar_20698 = (cppVar_20696 == 144);
	if (cppVar_20698) {
	cppVar_20693 = P1;
	} else {
	cppVar_20700 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20701 = (cppVar_20700 << 3) | 1;
	cppVar_20701 = (cppVar_20701 & cppMask_un_5_);
	cppVar_20702 = (0 << 5) | cppVar_20701;
	cppVar_20702 = (cppVar_20702 & cppMask_un_8_);
	cppVar_20704 = (cppVar_20702 == 152);
	if (cppVar_20704) {
	cppVar_20699 = SCON;
	} else {
	cppVar_20706 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20707 = (cppVar_20706 << 3) | 1;
	cppVar_20707 = (cppVar_20707 & cppMask_un_5_);
	cppVar_20708 = (0 << 5) | cppVar_20707;
	cppVar_20708 = (cppVar_20708 & cppMask_un_8_);
	cppVar_20710 = (cppVar_20708 == 153);
	if (cppVar_20710) {
	cppVar_20705 = SBUF;
	} else {
	cppVar_20712 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20713 = (cppVar_20712 << 3) | 1;
	cppVar_20713 = (cppVar_20713 & cppMask_un_5_);
	cppVar_20714 = (0 << 5) | cppVar_20713;
	cppVar_20714 = (cppVar_20714 & cppMask_un_8_);
	cppVar_20716 = (cppVar_20714 == 160);
	if (cppVar_20716) {
	cppVar_20711 = P2;
	} else {
	cppVar_20718 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20719 = (cppVar_20718 << 3) | 1;
	cppVar_20719 = (cppVar_20719 & cppMask_un_5_);
	cppVar_20720 = (0 << 5) | cppVar_20719;
	cppVar_20720 = (cppVar_20720 & cppMask_un_8_);
	cppVar_20722 = (cppVar_20720 == 168);
	if (cppVar_20722) {
	cppVar_20717 = IE;
	} else {
	cppVar_20724 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20725 = (cppVar_20724 << 3) | 1;
	cppVar_20725 = (cppVar_20725 & cppMask_un_5_);
	cppVar_20726 = (0 << 5) | cppVar_20725;
	cppVar_20726 = (cppVar_20726 & cppMask_un_8_);
	cppVar_20728 = (cppVar_20726 == 176);
	if (cppVar_20728) {
	cppVar_20723 = P3;
	} else {
	cppVar_20730 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20731 = (cppVar_20730 << 3) | 1;
	cppVar_20731 = (cppVar_20731 & cppMask_un_5_);
	cppVar_20732 = (0 << 5) | cppVar_20731;
	cppVar_20732 = (cppVar_20732 & cppMask_un_8_);
	cppVar_20734 = (cppVar_20732 == 184);
	if (cppVar_20734) {
	cppVar_20729 = IP;
	} else {
	cppVar_20736 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20737 = (cppVar_20736 << 3) | 1;
	cppVar_20737 = (cppVar_20737 & cppMask_un_5_);
	cppVar_20738 = (0 << 5) | cppVar_20737;
	cppVar_20738 = (cppVar_20738 & cppMask_un_8_);
	cppVar_20740 = (cppVar_20738 == 208);
	if (cppVar_20740) {
	cppVar_20735 = PSW;
	} else {
	cppVar_20742 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20743 = (cppVar_20742 << 3) | 1;
	cppVar_20743 = (cppVar_20743 & cppMask_un_5_);
	cppVar_20744 = (0 << 5) | cppVar_20743;
	cppVar_20744 = (cppVar_20744 & cppMask_un_8_);
	cppVar_20746 = (cppVar_20744 == 224);
	if (cppVar_20746) {
	cppVar_20741 = ACC;
	} else {
	cppVar_20748 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20749 = (cppVar_20748 << 3) | 1;
	cppVar_20749 = (cppVar_20749 & cppMask_un_5_);
	cppVar_20750 = (0 << 5) | cppVar_20749;
	cppVar_20750 = (cppVar_20750 & cppMask_un_8_);
	cppVar_20752 = (cppVar_20750 == 240);
	if (cppVar_20752) {
	cppVar_20747 = B;
	} else {
	cppVar_20747 = 0;
	}
	cppVar_20741 = cppVar_20747;
	}
	cppVar_20735 = cppVar_20741;
	}
	cppVar_20729 = cppVar_20735;
	}
	cppVar_20723 = cppVar_20729;
	}
	cppVar_20717 = cppVar_20723;
	}
	cppVar_20711 = cppVar_20717;
	}
	cppVar_20705 = cppVar_20711;
	}
	cppVar_20699 = cppVar_20705;
	}
	cppVar_20693 = cppVar_20699;
	}
	cppVar_20687 = cppVar_20693;
	}
	cppVar_20681 = cppVar_20687;
	}
	cppVar_20675 = cppVar_20681;
	}
	cppVar_20669 = cppVar_20675;
	}
	cppVar_20663 = cppVar_20669;
	}
	cppVar_20657 = cppVar_20663;
	}
	cppVar_20651 = cppVar_20657;
	}
	cppVar_20645 = cppVar_20651;
	}
	cppVar_20639 = cppVar_20645;
	}
	cppVar_20633 = cppVar_20639;
	}
	cppVar_20627 = cppVar_20633;
	}
	cppVar_20614 = cppVar_20627;
	}
	cppVar_20608 = cppVar_20614;
	} else {
	cppVar_20608 = IP;
	}
	cppVar_20604 = cppVar_20608;
	} else {
	cppVar_20755 = ROM.rd(PC);
	cppVar_20757 = (cppVar_20755 == 136);
	if (cppVar_20757) {
	cppVar_20760 = PC + 1;
	cppVar_20760 = (cppVar_20760 & cppMask_un_16_);
	cppVar_20761 = ROM.rd(cppVar_20760);
	cppVar_20763 = (cppVar_20761 == 184);
	if (cppVar_20763) {
	cppVar_20766 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20768 = (cppVar_20766 << 3) | 0;
	cppVar_20768 = (cppVar_20768 & cppMask_un_5_);
	cppVar_20769 = (0 << 5) | cppVar_20768;
	cppVar_20769 = (cppVar_20769 & cppMask_un_8_);
	cppVar_20770 = (cppVar_20769 >> 7) & cppMask_un_1_;
	cppVar_20772 = (cppVar_20770 == 0);
	if (cppVar_20772) {
	cppVar_20773 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20774 = (cppVar_20773 << 3) | 0;
	cppVar_20774 = (cppVar_20774 & cppMask_un_5_);
	cppVar_20775 = (0 << 5) | cppVar_20774;
	cppVar_20775 = (cppVar_20775 & cppMask_un_8_);
	cppVar_20776 = IRAM.rd(cppVar_20775);
	cppVar_20764 = cppVar_20776;
	} else {
	cppVar_20778 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20779 = (cppVar_20778 << 3) | 0;
	cppVar_20779 = (cppVar_20779 & cppMask_un_5_);
	cppVar_20780 = (0 << 5) | cppVar_20779;
	cppVar_20780 = (cppVar_20780 & cppMask_un_8_);
	cppVar_20782 = (cppVar_20780 == 128);
	if (cppVar_20782) {
	cppVar_20777 = P0;
	} else {
	cppVar_20784 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20785 = (cppVar_20784 << 3) | 0;
	cppVar_20785 = (cppVar_20785 & cppMask_un_5_);
	cppVar_20786 = (0 << 5) | cppVar_20785;
	cppVar_20786 = (cppVar_20786 & cppMask_un_8_);
	cppVar_20788 = (cppVar_20786 == 129);
	if (cppVar_20788) {
	cppVar_20783 = SP;
	} else {
	cppVar_20790 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20791 = (cppVar_20790 << 3) | 0;
	cppVar_20791 = (cppVar_20791 & cppMask_un_5_);
	cppVar_20792 = (0 << 5) | cppVar_20791;
	cppVar_20792 = (cppVar_20792 & cppMask_un_8_);
	cppVar_20794 = (cppVar_20792 == 130);
	if (cppVar_20794) {
	cppVar_20789 = DPL;
	} else {
	cppVar_20796 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20797 = (cppVar_20796 << 3) | 0;
	cppVar_20797 = (cppVar_20797 & cppMask_un_5_);
	cppVar_20798 = (0 << 5) | cppVar_20797;
	cppVar_20798 = (cppVar_20798 & cppMask_un_8_);
	cppVar_20800 = (cppVar_20798 == 131);
	if (cppVar_20800) {
	cppVar_20795 = DPH;
	} else {
	cppVar_20802 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20803 = (cppVar_20802 << 3) | 0;
	cppVar_20803 = (cppVar_20803 & cppMask_un_5_);
	cppVar_20804 = (0 << 5) | cppVar_20803;
	cppVar_20804 = (cppVar_20804 & cppMask_un_8_);
	cppVar_20806 = (cppVar_20804 == 135);
	if (cppVar_20806) {
	cppVar_20801 = PCON;
	} else {
	cppVar_20808 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20809 = (cppVar_20808 << 3) | 0;
	cppVar_20809 = (cppVar_20809 & cppMask_un_5_);
	cppVar_20810 = (0 << 5) | cppVar_20809;
	cppVar_20810 = (cppVar_20810 & cppMask_un_8_);
	cppVar_20812 = (cppVar_20810 == 136);
	if (cppVar_20812) {
	cppVar_20807 = TCON;
	} else {
	cppVar_20814 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20815 = (cppVar_20814 << 3) | 0;
	cppVar_20815 = (cppVar_20815 & cppMask_un_5_);
	cppVar_20816 = (0 << 5) | cppVar_20815;
	cppVar_20816 = (cppVar_20816 & cppMask_un_8_);
	cppVar_20818 = (cppVar_20816 == 137);
	if (cppVar_20818) {
	cppVar_20813 = TMOD;
	} else {
	cppVar_20820 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20821 = (cppVar_20820 << 3) | 0;
	cppVar_20821 = (cppVar_20821 & cppMask_un_5_);
	cppVar_20822 = (0 << 5) | cppVar_20821;
	cppVar_20822 = (cppVar_20822 & cppMask_un_8_);
	cppVar_20824 = (cppVar_20822 == 138);
	if (cppVar_20824) {
	cppVar_20819 = TL0;
	} else {
	cppVar_20826 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20827 = (cppVar_20826 << 3) | 0;
	cppVar_20827 = (cppVar_20827 & cppMask_un_5_);
	cppVar_20828 = (0 << 5) | cppVar_20827;
	cppVar_20828 = (cppVar_20828 & cppMask_un_8_);
	cppVar_20830 = (cppVar_20828 == 140);
	if (cppVar_20830) {
	cppVar_20825 = TH0;
	} else {
	cppVar_20832 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20833 = (cppVar_20832 << 3) | 0;
	cppVar_20833 = (cppVar_20833 & cppMask_un_5_);
	cppVar_20834 = (0 << 5) | cppVar_20833;
	cppVar_20834 = (cppVar_20834 & cppMask_un_8_);
	cppVar_20836 = (cppVar_20834 == 139);
	if (cppVar_20836) {
	cppVar_20831 = TL1;
	} else {
	cppVar_20838 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20839 = (cppVar_20838 << 3) | 0;
	cppVar_20839 = (cppVar_20839 & cppMask_un_5_);
	cppVar_20840 = (0 << 5) | cppVar_20839;
	cppVar_20840 = (cppVar_20840 & cppMask_un_8_);
	cppVar_20842 = (cppVar_20840 == 141);
	if (cppVar_20842) {
	cppVar_20837 = TH1;
	} else {
	cppVar_20844 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20845 = (cppVar_20844 << 3) | 0;
	cppVar_20845 = (cppVar_20845 & cppMask_un_5_);
	cppVar_20846 = (0 << 5) | cppVar_20845;
	cppVar_20846 = (cppVar_20846 & cppMask_un_8_);
	cppVar_20848 = (cppVar_20846 == 144);
	if (cppVar_20848) {
	cppVar_20843 = P1;
	} else {
	cppVar_20850 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20851 = (cppVar_20850 << 3) | 0;
	cppVar_20851 = (cppVar_20851 & cppMask_un_5_);
	cppVar_20852 = (0 << 5) | cppVar_20851;
	cppVar_20852 = (cppVar_20852 & cppMask_un_8_);
	cppVar_20854 = (cppVar_20852 == 152);
	if (cppVar_20854) {
	cppVar_20849 = SCON;
	} else {
	cppVar_20856 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20857 = (cppVar_20856 << 3) | 0;
	cppVar_20857 = (cppVar_20857 & cppMask_un_5_);
	cppVar_20858 = (0 << 5) | cppVar_20857;
	cppVar_20858 = (cppVar_20858 & cppMask_un_8_);
	cppVar_20860 = (cppVar_20858 == 153);
	if (cppVar_20860) {
	cppVar_20855 = SBUF;
	} else {
	cppVar_20862 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20863 = (cppVar_20862 << 3) | 0;
	cppVar_20863 = (cppVar_20863 & cppMask_un_5_);
	cppVar_20864 = (0 << 5) | cppVar_20863;
	cppVar_20864 = (cppVar_20864 & cppMask_un_8_);
	cppVar_20866 = (cppVar_20864 == 160);
	if (cppVar_20866) {
	cppVar_20861 = P2;
	} else {
	cppVar_20868 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20869 = (cppVar_20868 << 3) | 0;
	cppVar_20869 = (cppVar_20869 & cppMask_un_5_);
	cppVar_20870 = (0 << 5) | cppVar_20869;
	cppVar_20870 = (cppVar_20870 & cppMask_un_8_);
	cppVar_20872 = (cppVar_20870 == 168);
	if (cppVar_20872) {
	cppVar_20867 = IE;
	} else {
	cppVar_20874 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20875 = (cppVar_20874 << 3) | 0;
	cppVar_20875 = (cppVar_20875 & cppMask_un_5_);
	cppVar_20876 = (0 << 5) | cppVar_20875;
	cppVar_20876 = (cppVar_20876 & cppMask_un_8_);
	cppVar_20878 = (cppVar_20876 == 176);
	if (cppVar_20878) {
	cppVar_20873 = P3;
	} else {
	cppVar_20880 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20881 = (cppVar_20880 << 3) | 0;
	cppVar_20881 = (cppVar_20881 & cppMask_un_5_);
	cppVar_20882 = (0 << 5) | cppVar_20881;
	cppVar_20882 = (cppVar_20882 & cppMask_un_8_);
	cppVar_20884 = (cppVar_20882 == 184);
	if (cppVar_20884) {
	cppVar_20879 = IP;
	} else {
	cppVar_20886 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20887 = (cppVar_20886 << 3) | 0;
	cppVar_20887 = (cppVar_20887 & cppMask_un_5_);
	cppVar_20888 = (0 << 5) | cppVar_20887;
	cppVar_20888 = (cppVar_20888 & cppMask_un_8_);
	cppVar_20890 = (cppVar_20888 == 208);
	if (cppVar_20890) {
	cppVar_20885 = PSW;
	} else {
	cppVar_20892 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20893 = (cppVar_20892 << 3) | 0;
	cppVar_20893 = (cppVar_20893 & cppMask_un_5_);
	cppVar_20894 = (0 << 5) | cppVar_20893;
	cppVar_20894 = (cppVar_20894 & cppMask_un_8_);
	cppVar_20896 = (cppVar_20894 == 224);
	if (cppVar_20896) {
	cppVar_20891 = ACC;
	} else {
	cppVar_20898 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20899 = (cppVar_20898 << 3) | 0;
	cppVar_20899 = (cppVar_20899 & cppMask_un_5_);
	cppVar_20900 = (0 << 5) | cppVar_20899;
	cppVar_20900 = (cppVar_20900 & cppMask_un_8_);
	cppVar_20902 = (cppVar_20900 == 240);
	if (cppVar_20902) {
	cppVar_20897 = B;
	} else {
	cppVar_20897 = 0;
	}
	cppVar_20891 = cppVar_20897;
	}
	cppVar_20885 = cppVar_20891;
	}
	cppVar_20879 = cppVar_20885;
	}
	cppVar_20873 = cppVar_20879;
	}
	cppVar_20867 = cppVar_20873;
	}
	cppVar_20861 = cppVar_20867;
	}
	cppVar_20855 = cppVar_20861;
	}
	cppVar_20849 = cppVar_20855;
	}
	cppVar_20843 = cppVar_20849;
	}
	cppVar_20837 = cppVar_20843;
	}
	cppVar_20831 = cppVar_20837;
	}
	cppVar_20825 = cppVar_20831;
	}
	cppVar_20819 = cppVar_20825;
	}
	cppVar_20813 = cppVar_20819;
	}
	cppVar_20807 = cppVar_20813;
	}
	cppVar_20801 = cppVar_20807;
	}
	cppVar_20795 = cppVar_20801;
	}
	cppVar_20789 = cppVar_20795;
	}
	cppVar_20783 = cppVar_20789;
	}
	cppVar_20777 = cppVar_20783;
	}
	cppVar_20764 = cppVar_20777;
	}
	cppVar_20758 = cppVar_20764;
	} else {
	cppVar_20758 = IP;
	}
	cppVar_20754 = cppVar_20758;
	} else {
	cppVar_20905 = ROM.rd(PC);
	cppVar_20907 = (cppVar_20905 == 135);
	if (cppVar_20907) {
	cppVar_20910 = PC + 1;
	cppVar_20910 = (cppVar_20910 & cppMask_un_16_);
	cppVar_20911 = ROM.rd(cppVar_20910);
	cppVar_20913 = (cppVar_20911 == 184);
	if (cppVar_20913) {
	cppVar_20915 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20917 = (cppVar_20915 << 3) | 1;
	cppVar_20917 = (cppVar_20917 & cppMask_un_5_);
	cppVar_20918 = (0 << 5) | cppVar_20917;
	cppVar_20918 = (cppVar_20918 & cppMask_un_8_);
	cppVar_20919 = IRAM.rd(cppVar_20918);
	cppVar_20920 = IRAM.rd(cppVar_20919);
	cppVar_20908 = cppVar_20920;
	} else {
	cppVar_20908 = IP;
	}
	cppVar_20904 = cppVar_20908;
	} else {
	cppVar_20922 = ROM.rd(PC);
	cppVar_20924 = (cppVar_20922 == 134);
	if (cppVar_20924) {
	cppVar_20927 = PC + 1;
	cppVar_20927 = (cppVar_20927 & cppMask_un_16_);
	cppVar_20928 = ROM.rd(cppVar_20927);
	cppVar_20930 = (cppVar_20928 == 184);
	if (cppVar_20930) {
	cppVar_20932 = (PSW >> 3) & cppMask_un_2_;
	cppVar_20934 = (cppVar_20932 << 3) | 0;
	cppVar_20934 = (cppVar_20934 & cppMask_un_5_);
	cppVar_20935 = (0 << 5) | cppVar_20934;
	cppVar_20935 = (cppVar_20935 & cppMask_un_8_);
	cppVar_20936 = IRAM.rd(cppVar_20935);
	cppVar_20937 = IRAM.rd(cppVar_20936);
	cppVar_20925 = cppVar_20937;
	} else {
	cppVar_20925 = IP;
	}
	cppVar_20921 = cppVar_20925;
	} else {
	cppVar_20939 = ROM.rd(PC);
	cppVar_20941 = (cppVar_20939 == 133);
	if (cppVar_20941) {
	cppVar_20944 = PC + 2;
	cppVar_20944 = (cppVar_20944 & cppMask_un_16_);
	cppVar_20945 = ROM.rd(cppVar_20944);
	cppVar_20947 = (cppVar_20945 == 184);
	if (cppVar_20947) {
	cppVar_20950 = PC + 1;
	cppVar_20950 = (cppVar_20950 & cppMask_un_16_);
	cppVar_20951 = ROM.rd(cppVar_20950);
	cppVar_20952 = (cppVar_20951 >> 7) & cppMask_un_1_;
	cppVar_20954 = (cppVar_20952 == 0);
	if (cppVar_20954) {
	cppVar_20955 = PC + 1;
	cppVar_20955 = (cppVar_20955 & cppMask_un_16_);
	cppVar_20956 = ROM.rd(cppVar_20955);
	cppVar_20957 = IRAM.rd(cppVar_20956);
	cppVar_20948 = cppVar_20957;
	} else {
	cppVar_20959 = PC + 1;
	cppVar_20959 = (cppVar_20959 & cppMask_un_16_);
	cppVar_20960 = ROM.rd(cppVar_20959);
	cppVar_20962 = (cppVar_20960 == 128);
	if (cppVar_20962) {
	cppVar_20958 = P0;
	} else {
	cppVar_20964 = PC + 1;
	cppVar_20964 = (cppVar_20964 & cppMask_un_16_);
	cppVar_20965 = ROM.rd(cppVar_20964);
	cppVar_20967 = (cppVar_20965 == 129);
	if (cppVar_20967) {
	cppVar_20963 = SP;
	} else {
	cppVar_20969 = PC + 1;
	cppVar_20969 = (cppVar_20969 & cppMask_un_16_);
	cppVar_20970 = ROM.rd(cppVar_20969);
	cppVar_20972 = (cppVar_20970 == 130);
	if (cppVar_20972) {
	cppVar_20968 = DPL;
	} else {
	cppVar_20974 = PC + 1;
	cppVar_20974 = (cppVar_20974 & cppMask_un_16_);
	cppVar_20975 = ROM.rd(cppVar_20974);
	cppVar_20977 = (cppVar_20975 == 131);
	if (cppVar_20977) {
	cppVar_20973 = DPH;
	} else {
	cppVar_20979 = PC + 1;
	cppVar_20979 = (cppVar_20979 & cppMask_un_16_);
	cppVar_20980 = ROM.rd(cppVar_20979);
	cppVar_20982 = (cppVar_20980 == 135);
	if (cppVar_20982) {
	cppVar_20978 = PCON;
	} else {
	cppVar_20984 = PC + 1;
	cppVar_20984 = (cppVar_20984 & cppMask_un_16_);
	cppVar_20985 = ROM.rd(cppVar_20984);
	cppVar_20987 = (cppVar_20985 == 136);
	if (cppVar_20987) {
	cppVar_20983 = TCON;
	} else {
	cppVar_20989 = PC + 1;
	cppVar_20989 = (cppVar_20989 & cppMask_un_16_);
	cppVar_20990 = ROM.rd(cppVar_20989);
	cppVar_20992 = (cppVar_20990 == 137);
	if (cppVar_20992) {
	cppVar_20988 = TMOD;
	} else {
	cppVar_20994 = PC + 1;
	cppVar_20994 = (cppVar_20994 & cppMask_un_16_);
	cppVar_20995 = ROM.rd(cppVar_20994);
	cppVar_20997 = (cppVar_20995 == 138);
	if (cppVar_20997) {
	cppVar_20993 = TL0;
	} else {
	cppVar_20999 = PC + 1;
	cppVar_20999 = (cppVar_20999 & cppMask_un_16_);
	cppVar_21000 = ROM.rd(cppVar_20999);
	cppVar_21002 = (cppVar_21000 == 140);
	if (cppVar_21002) {
	cppVar_20998 = TH0;
	} else {
	cppVar_21004 = PC + 1;
	cppVar_21004 = (cppVar_21004 & cppMask_un_16_);
	cppVar_21005 = ROM.rd(cppVar_21004);
	cppVar_21007 = (cppVar_21005 == 139);
	if (cppVar_21007) {
	cppVar_21003 = TL1;
	} else {
	cppVar_21009 = PC + 1;
	cppVar_21009 = (cppVar_21009 & cppMask_un_16_);
	cppVar_21010 = ROM.rd(cppVar_21009);
	cppVar_21012 = (cppVar_21010 == 141);
	if (cppVar_21012) {
	cppVar_21008 = TH1;
	} else {
	cppVar_21014 = PC + 1;
	cppVar_21014 = (cppVar_21014 & cppMask_un_16_);
	cppVar_21015 = ROM.rd(cppVar_21014);
	cppVar_21017 = (cppVar_21015 == 144);
	if (cppVar_21017) {
	cppVar_21013 = P1;
	} else {
	cppVar_21019 = PC + 1;
	cppVar_21019 = (cppVar_21019 & cppMask_un_16_);
	cppVar_21020 = ROM.rd(cppVar_21019);
	cppVar_21022 = (cppVar_21020 == 152);
	if (cppVar_21022) {
	cppVar_21018 = SCON;
	} else {
	cppVar_21024 = PC + 1;
	cppVar_21024 = (cppVar_21024 & cppMask_un_16_);
	cppVar_21025 = ROM.rd(cppVar_21024);
	cppVar_21027 = (cppVar_21025 == 153);
	if (cppVar_21027) {
	cppVar_21023 = SBUF;
	} else {
	cppVar_21029 = PC + 1;
	cppVar_21029 = (cppVar_21029 & cppMask_un_16_);
	cppVar_21030 = ROM.rd(cppVar_21029);
	cppVar_21032 = (cppVar_21030 == 160);
	if (cppVar_21032) {
	cppVar_21028 = P2;
	} else {
	cppVar_21034 = PC + 1;
	cppVar_21034 = (cppVar_21034 & cppMask_un_16_);
	cppVar_21035 = ROM.rd(cppVar_21034);
	cppVar_21037 = (cppVar_21035 == 168);
	if (cppVar_21037) {
	cppVar_21033 = IE;
	} else {
	cppVar_21039 = PC + 1;
	cppVar_21039 = (cppVar_21039 & cppMask_un_16_);
	cppVar_21040 = ROM.rd(cppVar_21039);
	cppVar_21042 = (cppVar_21040 == 176);
	if (cppVar_21042) {
	cppVar_21038 = P3;
	} else {
	cppVar_21044 = PC + 1;
	cppVar_21044 = (cppVar_21044 & cppMask_un_16_);
	cppVar_21045 = ROM.rd(cppVar_21044);
	cppVar_21047 = (cppVar_21045 == 184);
	if (cppVar_21047) {
	cppVar_21043 = IP;
	} else {
	cppVar_21049 = PC + 1;
	cppVar_21049 = (cppVar_21049 & cppMask_un_16_);
	cppVar_21050 = ROM.rd(cppVar_21049);
	cppVar_21052 = (cppVar_21050 == 208);
	if (cppVar_21052) {
	cppVar_21048 = PSW;
	} else {
	cppVar_21054 = PC + 1;
	cppVar_21054 = (cppVar_21054 & cppMask_un_16_);
	cppVar_21055 = ROM.rd(cppVar_21054);
	cppVar_21057 = (cppVar_21055 == 224);
	if (cppVar_21057) {
	cppVar_21053 = ACC;
	} else {
	cppVar_21059 = PC + 1;
	cppVar_21059 = (cppVar_21059 & cppMask_un_16_);
	cppVar_21060 = ROM.rd(cppVar_21059);
	cppVar_21062 = (cppVar_21060 == 240);
	if (cppVar_21062) {
	cppVar_21058 = B;
	} else {
	cppVar_21058 = 0;
	}
	cppVar_21053 = cppVar_21058;
	}
	cppVar_21048 = cppVar_21053;
	}
	cppVar_21043 = cppVar_21048;
	}
	cppVar_21038 = cppVar_21043;
	}
	cppVar_21033 = cppVar_21038;
	}
	cppVar_21028 = cppVar_21033;
	}
	cppVar_21023 = cppVar_21028;
	}
	cppVar_21018 = cppVar_21023;
	}
	cppVar_21013 = cppVar_21018;
	}
	cppVar_21008 = cppVar_21013;
	}
	cppVar_21003 = cppVar_21008;
	}
	cppVar_20998 = cppVar_21003;
	}
	cppVar_20993 = cppVar_20998;
	}
	cppVar_20988 = cppVar_20993;
	}
	cppVar_20983 = cppVar_20988;
	}
	cppVar_20978 = cppVar_20983;
	}
	cppVar_20973 = cppVar_20978;
	}
	cppVar_20968 = cppVar_20973;
	}
	cppVar_20963 = cppVar_20968;
	}
	cppVar_20958 = cppVar_20963;
	}
	cppVar_20948 = cppVar_20958;
	}
	cppVar_20942 = cppVar_20948;
	} else {
	cppVar_20942 = IP;
	}
	cppVar_20938 = cppVar_20942;
	} else {
	cppVar_21065 = ROM.rd(PC);
	cppVar_21067 = (cppVar_21065 == 117);
	if (cppVar_21067) {
	cppVar_21070 = PC + 1;
	cppVar_21070 = (cppVar_21070 & cppMask_un_16_);
	cppVar_21071 = ROM.rd(cppVar_21070);
	cppVar_21073 = (cppVar_21071 == 184);
	if (cppVar_21073) {
	cppVar_21075 = PC + 2;
	cppVar_21075 = (cppVar_21075 & cppMask_un_16_);
	cppVar_21076 = ROM.rd(cppVar_21075);
	cppVar_21068 = cppVar_21076;
	} else {
	cppVar_21068 = IP;
	}
	cppVar_21064 = cppVar_21068;
	} else {
	cppVar_21078 = ROM.rd(PC);
	cppVar_21080 = (cppVar_21078 == 99);
	if (cppVar_21080) {
	cppVar_21083 = PC + 1;
	cppVar_21083 = (cppVar_21083 & cppMask_un_16_);
	cppVar_21084 = ROM.rd(cppVar_21083);
	cppVar_21086 = (cppVar_21084 == 184);
	if (cppVar_21086) {
	cppVar_21088 = PC + 1;
	cppVar_21088 = (cppVar_21088 & cppMask_un_16_);
	cppVar_21089 = ROM.rd(cppVar_21088);
	cppVar_21090 = (cppVar_21089 >> 7) & cppMask_un_1_;
	cppVar_21092 = (cppVar_21090 == 0);
	if (cppVar_21092) {
	cppVar_21093 = PC + 1;
	cppVar_21093 = (cppVar_21093 & cppMask_un_16_);
	cppVar_21094 = ROM.rd(cppVar_21093);
	cppVar_21095 = IRAM.rd(cppVar_21094);
	cppVar_21087 = cppVar_21095;
	} else {
	cppVar_21097 = PC + 1;
	cppVar_21097 = (cppVar_21097 & cppMask_un_16_);
	cppVar_21098 = ROM.rd(cppVar_21097);
	cppVar_21100 = (cppVar_21098 == 128);
	if (cppVar_21100) {
	cppVar_21096 = P0;
	} else {
	cppVar_21102 = PC + 1;
	cppVar_21102 = (cppVar_21102 & cppMask_un_16_);
	cppVar_21103 = ROM.rd(cppVar_21102);
	cppVar_21105 = (cppVar_21103 == 129);
	if (cppVar_21105) {
	cppVar_21101 = SP;
	} else {
	cppVar_21107 = PC + 1;
	cppVar_21107 = (cppVar_21107 & cppMask_un_16_);
	cppVar_21108 = ROM.rd(cppVar_21107);
	cppVar_21110 = (cppVar_21108 == 130);
	if (cppVar_21110) {
	cppVar_21106 = DPL;
	} else {
	cppVar_21112 = PC + 1;
	cppVar_21112 = (cppVar_21112 & cppMask_un_16_);
	cppVar_21113 = ROM.rd(cppVar_21112);
	cppVar_21115 = (cppVar_21113 == 131);
	if (cppVar_21115) {
	cppVar_21111 = DPH;
	} else {
	cppVar_21117 = PC + 1;
	cppVar_21117 = (cppVar_21117 & cppMask_un_16_);
	cppVar_21118 = ROM.rd(cppVar_21117);
	cppVar_21120 = (cppVar_21118 == 135);
	if (cppVar_21120) {
	cppVar_21116 = PCON;
	} else {
	cppVar_21122 = PC + 1;
	cppVar_21122 = (cppVar_21122 & cppMask_un_16_);
	cppVar_21123 = ROM.rd(cppVar_21122);
	cppVar_21125 = (cppVar_21123 == 136);
	if (cppVar_21125) {
	cppVar_21121 = TCON;
	} else {
	cppVar_21127 = PC + 1;
	cppVar_21127 = (cppVar_21127 & cppMask_un_16_);
	cppVar_21128 = ROM.rd(cppVar_21127);
	cppVar_21130 = (cppVar_21128 == 137);
	if (cppVar_21130) {
	cppVar_21126 = TMOD;
	} else {
	cppVar_21132 = PC + 1;
	cppVar_21132 = (cppVar_21132 & cppMask_un_16_);
	cppVar_21133 = ROM.rd(cppVar_21132);
	cppVar_21135 = (cppVar_21133 == 138);
	if (cppVar_21135) {
	cppVar_21131 = TL0;
	} else {
	cppVar_21137 = PC + 1;
	cppVar_21137 = (cppVar_21137 & cppMask_un_16_);
	cppVar_21138 = ROM.rd(cppVar_21137);
	cppVar_21140 = (cppVar_21138 == 140);
	if (cppVar_21140) {
	cppVar_21136 = TH0;
	} else {
	cppVar_21142 = PC + 1;
	cppVar_21142 = (cppVar_21142 & cppMask_un_16_);
	cppVar_21143 = ROM.rd(cppVar_21142);
	cppVar_21145 = (cppVar_21143 == 139);
	if (cppVar_21145) {
	cppVar_21141 = TL1;
	} else {
	cppVar_21147 = PC + 1;
	cppVar_21147 = (cppVar_21147 & cppMask_un_16_);
	cppVar_21148 = ROM.rd(cppVar_21147);
	cppVar_21150 = (cppVar_21148 == 141);
	if (cppVar_21150) {
	cppVar_21146 = TH1;
	} else {
	cppVar_21152 = PC + 1;
	cppVar_21152 = (cppVar_21152 & cppMask_un_16_);
	cppVar_21153 = ROM.rd(cppVar_21152);
	cppVar_21155 = (cppVar_21153 == 144);
	if (cppVar_21155) {
	cppVar_21151 = P1;
	} else {
	cppVar_21157 = PC + 1;
	cppVar_21157 = (cppVar_21157 & cppMask_un_16_);
	cppVar_21158 = ROM.rd(cppVar_21157);
	cppVar_21160 = (cppVar_21158 == 152);
	if (cppVar_21160) {
	cppVar_21156 = SCON;
	} else {
	cppVar_21162 = PC + 1;
	cppVar_21162 = (cppVar_21162 & cppMask_un_16_);
	cppVar_21163 = ROM.rd(cppVar_21162);
	cppVar_21165 = (cppVar_21163 == 153);
	if (cppVar_21165) {
	cppVar_21161 = SBUF;
	} else {
	cppVar_21167 = PC + 1;
	cppVar_21167 = (cppVar_21167 & cppMask_un_16_);
	cppVar_21168 = ROM.rd(cppVar_21167);
	cppVar_21170 = (cppVar_21168 == 160);
	if (cppVar_21170) {
	cppVar_21166 = P2;
	} else {
	cppVar_21172 = PC + 1;
	cppVar_21172 = (cppVar_21172 & cppMask_un_16_);
	cppVar_21173 = ROM.rd(cppVar_21172);
	cppVar_21175 = (cppVar_21173 == 168);
	if (cppVar_21175) {
	cppVar_21171 = IE;
	} else {
	cppVar_21177 = PC + 1;
	cppVar_21177 = (cppVar_21177 & cppMask_un_16_);
	cppVar_21178 = ROM.rd(cppVar_21177);
	cppVar_21180 = (cppVar_21178 == 176);
	if (cppVar_21180) {
	cppVar_21176 = P3;
	} else {
	cppVar_21182 = PC + 1;
	cppVar_21182 = (cppVar_21182 & cppMask_un_16_);
	cppVar_21183 = ROM.rd(cppVar_21182);
	cppVar_21185 = (cppVar_21183 == 184);
	if (cppVar_21185) {
	cppVar_21181 = IP;
	} else {
	cppVar_21187 = PC + 1;
	cppVar_21187 = (cppVar_21187 & cppMask_un_16_);
	cppVar_21188 = ROM.rd(cppVar_21187);
	cppVar_21190 = (cppVar_21188 == 208);
	if (cppVar_21190) {
	cppVar_21186 = PSW;
	} else {
	cppVar_21192 = PC + 1;
	cppVar_21192 = (cppVar_21192 & cppMask_un_16_);
	cppVar_21193 = ROM.rd(cppVar_21192);
	cppVar_21195 = (cppVar_21193 == 224);
	if (cppVar_21195) {
	cppVar_21191 = ACC;
	} else {
	cppVar_21197 = PC + 1;
	cppVar_21197 = (cppVar_21197 & cppMask_un_16_);
	cppVar_21198 = ROM.rd(cppVar_21197);
	cppVar_21200 = (cppVar_21198 == 240);
	if (cppVar_21200) {
	cppVar_21196 = B;
	} else {
	cppVar_21196 = 0;
	}
	cppVar_21191 = cppVar_21196;
	}
	cppVar_21186 = cppVar_21191;
	}
	cppVar_21181 = cppVar_21186;
	}
	cppVar_21176 = cppVar_21181;
	}
	cppVar_21171 = cppVar_21176;
	}
	cppVar_21166 = cppVar_21171;
	}
	cppVar_21161 = cppVar_21166;
	}
	cppVar_21156 = cppVar_21161;
	}
	cppVar_21151 = cppVar_21156;
	}
	cppVar_21146 = cppVar_21151;
	}
	cppVar_21141 = cppVar_21146;
	}
	cppVar_21136 = cppVar_21141;
	}
	cppVar_21131 = cppVar_21136;
	}
	cppVar_21126 = cppVar_21131;
	}
	cppVar_21121 = cppVar_21126;
	}
	cppVar_21116 = cppVar_21121;
	}
	cppVar_21111 = cppVar_21116;
	}
	cppVar_21106 = cppVar_21111;
	}
	cppVar_21101 = cppVar_21106;
	}
	cppVar_21096 = cppVar_21101;
	}
	cppVar_21087 = cppVar_21096;
	}
	cppVar_21203 = PC + 2;
	cppVar_21203 = (cppVar_21203 & cppMask_un_16_);
	cppVar_21204 = ROM.rd(cppVar_21203);
	cppVar_21205 = cppVar_21087 ^ cppVar_21204;
	cppVar_21081 = cppVar_21205;
	} else {
	cppVar_21081 = IP;
	}
	cppVar_21077 = cppVar_21081;
	} else {
	cppVar_21207 = ROM.rd(PC);
	cppVar_21209 = (cppVar_21207 == 98);
	if (cppVar_21209) {
	cppVar_21212 = PC + 1;
	cppVar_21212 = (cppVar_21212 & cppMask_un_16_);
	cppVar_21213 = ROM.rd(cppVar_21212);
	cppVar_21215 = (cppVar_21213 == 184);
	if (cppVar_21215) {
	cppVar_21217 = PC + 1;
	cppVar_21217 = (cppVar_21217 & cppMask_un_16_);
	cppVar_21218 = ROM.rd(cppVar_21217);
	cppVar_21219 = (cppVar_21218 >> 7) & cppMask_un_1_;
	cppVar_21221 = (cppVar_21219 == 0);
	if (cppVar_21221) {
	cppVar_21222 = PC + 1;
	cppVar_21222 = (cppVar_21222 & cppMask_un_16_);
	cppVar_21223 = ROM.rd(cppVar_21222);
	cppVar_21224 = IRAM.rd(cppVar_21223);
	cppVar_21216 = cppVar_21224;
	} else {
	cppVar_21226 = PC + 1;
	cppVar_21226 = (cppVar_21226 & cppMask_un_16_);
	cppVar_21227 = ROM.rd(cppVar_21226);
	cppVar_21229 = (cppVar_21227 == 128);
	if (cppVar_21229) {
	cppVar_21225 = P0;
	} else {
	cppVar_21231 = PC + 1;
	cppVar_21231 = (cppVar_21231 & cppMask_un_16_);
	cppVar_21232 = ROM.rd(cppVar_21231);
	cppVar_21234 = (cppVar_21232 == 129);
	if (cppVar_21234) {
	cppVar_21230 = SP;
	} else {
	cppVar_21236 = PC + 1;
	cppVar_21236 = (cppVar_21236 & cppMask_un_16_);
	cppVar_21237 = ROM.rd(cppVar_21236);
	cppVar_21239 = (cppVar_21237 == 130);
	if (cppVar_21239) {
	cppVar_21235 = DPL;
	} else {
	cppVar_21241 = PC + 1;
	cppVar_21241 = (cppVar_21241 & cppMask_un_16_);
	cppVar_21242 = ROM.rd(cppVar_21241);
	cppVar_21244 = (cppVar_21242 == 131);
	if (cppVar_21244) {
	cppVar_21240 = DPH;
	} else {
	cppVar_21246 = PC + 1;
	cppVar_21246 = (cppVar_21246 & cppMask_un_16_);
	cppVar_21247 = ROM.rd(cppVar_21246);
	cppVar_21249 = (cppVar_21247 == 135);
	if (cppVar_21249) {
	cppVar_21245 = PCON;
	} else {
	cppVar_21251 = PC + 1;
	cppVar_21251 = (cppVar_21251 & cppMask_un_16_);
	cppVar_21252 = ROM.rd(cppVar_21251);
	cppVar_21254 = (cppVar_21252 == 136);
	if (cppVar_21254) {
	cppVar_21250 = TCON;
	} else {
	cppVar_21256 = PC + 1;
	cppVar_21256 = (cppVar_21256 & cppMask_un_16_);
	cppVar_21257 = ROM.rd(cppVar_21256);
	cppVar_21259 = (cppVar_21257 == 137);
	if (cppVar_21259) {
	cppVar_21255 = TMOD;
	} else {
	cppVar_21261 = PC + 1;
	cppVar_21261 = (cppVar_21261 & cppMask_un_16_);
	cppVar_21262 = ROM.rd(cppVar_21261);
	cppVar_21264 = (cppVar_21262 == 138);
	if (cppVar_21264) {
	cppVar_21260 = TL0;
	} else {
	cppVar_21266 = PC + 1;
	cppVar_21266 = (cppVar_21266 & cppMask_un_16_);
	cppVar_21267 = ROM.rd(cppVar_21266);
	cppVar_21269 = (cppVar_21267 == 140);
	if (cppVar_21269) {
	cppVar_21265 = TH0;
	} else {
	cppVar_21271 = PC + 1;
	cppVar_21271 = (cppVar_21271 & cppMask_un_16_);
	cppVar_21272 = ROM.rd(cppVar_21271);
	cppVar_21274 = (cppVar_21272 == 139);
	if (cppVar_21274) {
	cppVar_21270 = TL1;
	} else {
	cppVar_21276 = PC + 1;
	cppVar_21276 = (cppVar_21276 & cppMask_un_16_);
	cppVar_21277 = ROM.rd(cppVar_21276);
	cppVar_21279 = (cppVar_21277 == 141);
	if (cppVar_21279) {
	cppVar_21275 = TH1;
	} else {
	cppVar_21281 = PC + 1;
	cppVar_21281 = (cppVar_21281 & cppMask_un_16_);
	cppVar_21282 = ROM.rd(cppVar_21281);
	cppVar_21284 = (cppVar_21282 == 144);
	if (cppVar_21284) {
	cppVar_21280 = P1;
	} else {
	cppVar_21286 = PC + 1;
	cppVar_21286 = (cppVar_21286 & cppMask_un_16_);
	cppVar_21287 = ROM.rd(cppVar_21286);
	cppVar_21289 = (cppVar_21287 == 152);
	if (cppVar_21289) {
	cppVar_21285 = SCON;
	} else {
	cppVar_21291 = PC + 1;
	cppVar_21291 = (cppVar_21291 & cppMask_un_16_);
	cppVar_21292 = ROM.rd(cppVar_21291);
	cppVar_21294 = (cppVar_21292 == 153);
	if (cppVar_21294) {
	cppVar_21290 = SBUF;
	} else {
	cppVar_21296 = PC + 1;
	cppVar_21296 = (cppVar_21296 & cppMask_un_16_);
	cppVar_21297 = ROM.rd(cppVar_21296);
	cppVar_21299 = (cppVar_21297 == 160);
	if (cppVar_21299) {
	cppVar_21295 = P2;
	} else {
	cppVar_21301 = PC + 1;
	cppVar_21301 = (cppVar_21301 & cppMask_un_16_);
	cppVar_21302 = ROM.rd(cppVar_21301);
	cppVar_21304 = (cppVar_21302 == 168);
	if (cppVar_21304) {
	cppVar_21300 = IE;
	} else {
	cppVar_21306 = PC + 1;
	cppVar_21306 = (cppVar_21306 & cppMask_un_16_);
	cppVar_21307 = ROM.rd(cppVar_21306);
	cppVar_21309 = (cppVar_21307 == 176);
	if (cppVar_21309) {
	cppVar_21305 = P3;
	} else {
	cppVar_21311 = PC + 1;
	cppVar_21311 = (cppVar_21311 & cppMask_un_16_);
	cppVar_21312 = ROM.rd(cppVar_21311);
	cppVar_21314 = (cppVar_21312 == 184);
	if (cppVar_21314) {
	cppVar_21310 = IP;
	} else {
	cppVar_21316 = PC + 1;
	cppVar_21316 = (cppVar_21316 & cppMask_un_16_);
	cppVar_21317 = ROM.rd(cppVar_21316);
	cppVar_21319 = (cppVar_21317 == 208);
	if (cppVar_21319) {
	cppVar_21315 = PSW;
	} else {
	cppVar_21321 = PC + 1;
	cppVar_21321 = (cppVar_21321 & cppMask_un_16_);
	cppVar_21322 = ROM.rd(cppVar_21321);
	cppVar_21324 = (cppVar_21322 == 224);
	if (cppVar_21324) {
	cppVar_21320 = ACC;
	} else {
	cppVar_21326 = PC + 1;
	cppVar_21326 = (cppVar_21326 & cppMask_un_16_);
	cppVar_21327 = ROM.rd(cppVar_21326);
	cppVar_21329 = (cppVar_21327 == 240);
	if (cppVar_21329) {
	cppVar_21325 = B;
	} else {
	cppVar_21325 = 0;
	}
	cppVar_21320 = cppVar_21325;
	}
	cppVar_21315 = cppVar_21320;
	}
	cppVar_21310 = cppVar_21315;
	}
	cppVar_21305 = cppVar_21310;
	}
	cppVar_21300 = cppVar_21305;
	}
	cppVar_21295 = cppVar_21300;
	}
	cppVar_21290 = cppVar_21295;
	}
	cppVar_21285 = cppVar_21290;
	}
	cppVar_21280 = cppVar_21285;
	}
	cppVar_21275 = cppVar_21280;
	}
	cppVar_21270 = cppVar_21275;
	}
	cppVar_21265 = cppVar_21270;
	}
	cppVar_21260 = cppVar_21265;
	}
	cppVar_21255 = cppVar_21260;
	}
	cppVar_21250 = cppVar_21255;
	}
	cppVar_21245 = cppVar_21250;
	}
	cppVar_21240 = cppVar_21245;
	}
	cppVar_21235 = cppVar_21240;
	}
	cppVar_21230 = cppVar_21235;
	}
	cppVar_21225 = cppVar_21230;
	}
	cppVar_21216 = cppVar_21225;
	}
	cppVar_21331 = cppVar_21216 ^ ACC;
	cppVar_21210 = cppVar_21331;
	} else {
	cppVar_21210 = IP;
	}
	cppVar_21206 = cppVar_21210;
	} else {
	cppVar_21333 = ROM.rd(PC);
	cppVar_21335 = (cppVar_21333 == 83);
	if (cppVar_21335) {
	cppVar_21338 = PC + 1;
	cppVar_21338 = (cppVar_21338 & cppMask_un_16_);
	cppVar_21339 = ROM.rd(cppVar_21338);
	cppVar_21341 = (cppVar_21339 == 184);
	if (cppVar_21341) {
	cppVar_21343 = PC + 1;
	cppVar_21343 = (cppVar_21343 & cppMask_un_16_);
	cppVar_21344 = ROM.rd(cppVar_21343);
	cppVar_21345 = (cppVar_21344 >> 7) & cppMask_un_1_;
	cppVar_21347 = (cppVar_21345 == 0);
	if (cppVar_21347) {
	cppVar_21348 = PC + 1;
	cppVar_21348 = (cppVar_21348 & cppMask_un_16_);
	cppVar_21349 = ROM.rd(cppVar_21348);
	cppVar_21350 = IRAM.rd(cppVar_21349);
	cppVar_21342 = cppVar_21350;
	} else {
	cppVar_21352 = PC + 1;
	cppVar_21352 = (cppVar_21352 & cppMask_un_16_);
	cppVar_21353 = ROM.rd(cppVar_21352);
	cppVar_21355 = (cppVar_21353 == 128);
	if (cppVar_21355) {
	cppVar_21351 = P0;
	} else {
	cppVar_21357 = PC + 1;
	cppVar_21357 = (cppVar_21357 & cppMask_un_16_);
	cppVar_21358 = ROM.rd(cppVar_21357);
	cppVar_21360 = (cppVar_21358 == 129);
	if (cppVar_21360) {
	cppVar_21356 = SP;
	} else {
	cppVar_21362 = PC + 1;
	cppVar_21362 = (cppVar_21362 & cppMask_un_16_);
	cppVar_21363 = ROM.rd(cppVar_21362);
	cppVar_21365 = (cppVar_21363 == 130);
	if (cppVar_21365) {
	cppVar_21361 = DPL;
	} else {
	cppVar_21367 = PC + 1;
	cppVar_21367 = (cppVar_21367 & cppMask_un_16_);
	cppVar_21368 = ROM.rd(cppVar_21367);
	cppVar_21370 = (cppVar_21368 == 131);
	if (cppVar_21370) {
	cppVar_21366 = DPH;
	} else {
	cppVar_21372 = PC + 1;
	cppVar_21372 = (cppVar_21372 & cppMask_un_16_);
	cppVar_21373 = ROM.rd(cppVar_21372);
	cppVar_21375 = (cppVar_21373 == 135);
	if (cppVar_21375) {
	cppVar_21371 = PCON;
	} else {
	cppVar_21377 = PC + 1;
	cppVar_21377 = (cppVar_21377 & cppMask_un_16_);
	cppVar_21378 = ROM.rd(cppVar_21377);
	cppVar_21380 = (cppVar_21378 == 136);
	if (cppVar_21380) {
	cppVar_21376 = TCON;
	} else {
	cppVar_21382 = PC + 1;
	cppVar_21382 = (cppVar_21382 & cppMask_un_16_);
	cppVar_21383 = ROM.rd(cppVar_21382);
	cppVar_21385 = (cppVar_21383 == 137);
	if (cppVar_21385) {
	cppVar_21381 = TMOD;
	} else {
	cppVar_21387 = PC + 1;
	cppVar_21387 = (cppVar_21387 & cppMask_un_16_);
	cppVar_21388 = ROM.rd(cppVar_21387);
	cppVar_21390 = (cppVar_21388 == 138);
	if (cppVar_21390) {
	cppVar_21386 = TL0;
	} else {
	cppVar_21392 = PC + 1;
	cppVar_21392 = (cppVar_21392 & cppMask_un_16_);
	cppVar_21393 = ROM.rd(cppVar_21392);
	cppVar_21395 = (cppVar_21393 == 140);
	if (cppVar_21395) {
	cppVar_21391 = TH0;
	} else {
	cppVar_21397 = PC + 1;
	cppVar_21397 = (cppVar_21397 & cppMask_un_16_);
	cppVar_21398 = ROM.rd(cppVar_21397);
	cppVar_21400 = (cppVar_21398 == 139);
	if (cppVar_21400) {
	cppVar_21396 = TL1;
	} else {
	cppVar_21402 = PC + 1;
	cppVar_21402 = (cppVar_21402 & cppMask_un_16_);
	cppVar_21403 = ROM.rd(cppVar_21402);
	cppVar_21405 = (cppVar_21403 == 141);
	if (cppVar_21405) {
	cppVar_21401 = TH1;
	} else {
	cppVar_21407 = PC + 1;
	cppVar_21407 = (cppVar_21407 & cppMask_un_16_);
	cppVar_21408 = ROM.rd(cppVar_21407);
	cppVar_21410 = (cppVar_21408 == 144);
	if (cppVar_21410) {
	cppVar_21406 = P1;
	} else {
	cppVar_21412 = PC + 1;
	cppVar_21412 = (cppVar_21412 & cppMask_un_16_);
	cppVar_21413 = ROM.rd(cppVar_21412);
	cppVar_21415 = (cppVar_21413 == 152);
	if (cppVar_21415) {
	cppVar_21411 = SCON;
	} else {
	cppVar_21417 = PC + 1;
	cppVar_21417 = (cppVar_21417 & cppMask_un_16_);
	cppVar_21418 = ROM.rd(cppVar_21417);
	cppVar_21420 = (cppVar_21418 == 153);
	if (cppVar_21420) {
	cppVar_21416 = SBUF;
	} else {
	cppVar_21422 = PC + 1;
	cppVar_21422 = (cppVar_21422 & cppMask_un_16_);
	cppVar_21423 = ROM.rd(cppVar_21422);
	cppVar_21425 = (cppVar_21423 == 160);
	if (cppVar_21425) {
	cppVar_21421 = P2;
	} else {
	cppVar_21427 = PC + 1;
	cppVar_21427 = (cppVar_21427 & cppMask_un_16_);
	cppVar_21428 = ROM.rd(cppVar_21427);
	cppVar_21430 = (cppVar_21428 == 168);
	if (cppVar_21430) {
	cppVar_21426 = IE;
	} else {
	cppVar_21432 = PC + 1;
	cppVar_21432 = (cppVar_21432 & cppMask_un_16_);
	cppVar_21433 = ROM.rd(cppVar_21432);
	cppVar_21435 = (cppVar_21433 == 176);
	if (cppVar_21435) {
	cppVar_21431 = P3;
	} else {
	cppVar_21437 = PC + 1;
	cppVar_21437 = (cppVar_21437 & cppMask_un_16_);
	cppVar_21438 = ROM.rd(cppVar_21437);
	cppVar_21440 = (cppVar_21438 == 184);
	if (cppVar_21440) {
	cppVar_21436 = IP;
	} else {
	cppVar_21442 = PC + 1;
	cppVar_21442 = (cppVar_21442 & cppMask_un_16_);
	cppVar_21443 = ROM.rd(cppVar_21442);
	cppVar_21445 = (cppVar_21443 == 208);
	if (cppVar_21445) {
	cppVar_21441 = PSW;
	} else {
	cppVar_21447 = PC + 1;
	cppVar_21447 = (cppVar_21447 & cppMask_un_16_);
	cppVar_21448 = ROM.rd(cppVar_21447);
	cppVar_21450 = (cppVar_21448 == 224);
	if (cppVar_21450) {
	cppVar_21446 = ACC;
	} else {
	cppVar_21452 = PC + 1;
	cppVar_21452 = (cppVar_21452 & cppMask_un_16_);
	cppVar_21453 = ROM.rd(cppVar_21452);
	cppVar_21455 = (cppVar_21453 == 240);
	if (cppVar_21455) {
	cppVar_21451 = B;
	} else {
	cppVar_21451 = 0;
	}
	cppVar_21446 = cppVar_21451;
	}
	cppVar_21441 = cppVar_21446;
	}
	cppVar_21436 = cppVar_21441;
	}
	cppVar_21431 = cppVar_21436;
	}
	cppVar_21426 = cppVar_21431;
	}
	cppVar_21421 = cppVar_21426;
	}
	cppVar_21416 = cppVar_21421;
	}
	cppVar_21411 = cppVar_21416;
	}
	cppVar_21406 = cppVar_21411;
	}
	cppVar_21401 = cppVar_21406;
	}
	cppVar_21396 = cppVar_21401;
	}
	cppVar_21391 = cppVar_21396;
	}
	cppVar_21386 = cppVar_21391;
	}
	cppVar_21381 = cppVar_21386;
	}
	cppVar_21376 = cppVar_21381;
	}
	cppVar_21371 = cppVar_21376;
	}
	cppVar_21366 = cppVar_21371;
	}
	cppVar_21361 = cppVar_21366;
	}
	cppVar_21356 = cppVar_21361;
	}
	cppVar_21351 = cppVar_21356;
	}
	cppVar_21342 = cppVar_21351;
	}
	cppVar_21458 = PC + 2;
	cppVar_21458 = (cppVar_21458 & cppMask_un_16_);
	cppVar_21459 = ROM.rd(cppVar_21458);
	cppVar_21460 = cppVar_21342 & cppVar_21459;
	cppVar_21336 = cppVar_21460;
	} else {
	cppVar_21336 = IP;
	}
	cppVar_21332 = cppVar_21336;
	} else {
	cppVar_21462 = ROM.rd(PC);
	cppVar_21464 = (cppVar_21462 == 82);
	if (cppVar_21464) {
	cppVar_21467 = PC + 1;
	cppVar_21467 = (cppVar_21467 & cppMask_un_16_);
	cppVar_21468 = ROM.rd(cppVar_21467);
	cppVar_21470 = (cppVar_21468 == 184);
	if (cppVar_21470) {
	cppVar_21472 = PC + 1;
	cppVar_21472 = (cppVar_21472 & cppMask_un_16_);
	cppVar_21473 = ROM.rd(cppVar_21472);
	cppVar_21474 = (cppVar_21473 >> 7) & cppMask_un_1_;
	cppVar_21476 = (cppVar_21474 == 0);
	if (cppVar_21476) {
	cppVar_21477 = PC + 1;
	cppVar_21477 = (cppVar_21477 & cppMask_un_16_);
	cppVar_21478 = ROM.rd(cppVar_21477);
	cppVar_21479 = IRAM.rd(cppVar_21478);
	cppVar_21471 = cppVar_21479;
	} else {
	cppVar_21481 = PC + 1;
	cppVar_21481 = (cppVar_21481 & cppMask_un_16_);
	cppVar_21482 = ROM.rd(cppVar_21481);
	cppVar_21484 = (cppVar_21482 == 128);
	if (cppVar_21484) {
	cppVar_21480 = P0;
	} else {
	cppVar_21486 = PC + 1;
	cppVar_21486 = (cppVar_21486 & cppMask_un_16_);
	cppVar_21487 = ROM.rd(cppVar_21486);
	cppVar_21489 = (cppVar_21487 == 129);
	if (cppVar_21489) {
	cppVar_21485 = SP;
	} else {
	cppVar_21491 = PC + 1;
	cppVar_21491 = (cppVar_21491 & cppMask_un_16_);
	cppVar_21492 = ROM.rd(cppVar_21491);
	cppVar_21494 = (cppVar_21492 == 130);
	if (cppVar_21494) {
	cppVar_21490 = DPL;
	} else {
	cppVar_21496 = PC + 1;
	cppVar_21496 = (cppVar_21496 & cppMask_un_16_);
	cppVar_21497 = ROM.rd(cppVar_21496);
	cppVar_21499 = (cppVar_21497 == 131);
	if (cppVar_21499) {
	cppVar_21495 = DPH;
	} else {
	cppVar_21501 = PC + 1;
	cppVar_21501 = (cppVar_21501 & cppMask_un_16_);
	cppVar_21502 = ROM.rd(cppVar_21501);
	cppVar_21504 = (cppVar_21502 == 135);
	if (cppVar_21504) {
	cppVar_21500 = PCON;
	} else {
	cppVar_21506 = PC + 1;
	cppVar_21506 = (cppVar_21506 & cppMask_un_16_);
	cppVar_21507 = ROM.rd(cppVar_21506);
	cppVar_21509 = (cppVar_21507 == 136);
	if (cppVar_21509) {
	cppVar_21505 = TCON;
	} else {
	cppVar_21511 = PC + 1;
	cppVar_21511 = (cppVar_21511 & cppMask_un_16_);
	cppVar_21512 = ROM.rd(cppVar_21511);
	cppVar_21514 = (cppVar_21512 == 137);
	if (cppVar_21514) {
	cppVar_21510 = TMOD;
	} else {
	cppVar_21516 = PC + 1;
	cppVar_21516 = (cppVar_21516 & cppMask_un_16_);
	cppVar_21517 = ROM.rd(cppVar_21516);
	cppVar_21519 = (cppVar_21517 == 138);
	if (cppVar_21519) {
	cppVar_21515 = TL0;
	} else {
	cppVar_21521 = PC + 1;
	cppVar_21521 = (cppVar_21521 & cppMask_un_16_);
	cppVar_21522 = ROM.rd(cppVar_21521);
	cppVar_21524 = (cppVar_21522 == 140);
	if (cppVar_21524) {
	cppVar_21520 = TH0;
	} else {
	cppVar_21526 = PC + 1;
	cppVar_21526 = (cppVar_21526 & cppMask_un_16_);
	cppVar_21527 = ROM.rd(cppVar_21526);
	cppVar_21529 = (cppVar_21527 == 139);
	if (cppVar_21529) {
	cppVar_21525 = TL1;
	} else {
	cppVar_21531 = PC + 1;
	cppVar_21531 = (cppVar_21531 & cppMask_un_16_);
	cppVar_21532 = ROM.rd(cppVar_21531);
	cppVar_21534 = (cppVar_21532 == 141);
	if (cppVar_21534) {
	cppVar_21530 = TH1;
	} else {
	cppVar_21536 = PC + 1;
	cppVar_21536 = (cppVar_21536 & cppMask_un_16_);
	cppVar_21537 = ROM.rd(cppVar_21536);
	cppVar_21539 = (cppVar_21537 == 144);
	if (cppVar_21539) {
	cppVar_21535 = P1;
	} else {
	cppVar_21541 = PC + 1;
	cppVar_21541 = (cppVar_21541 & cppMask_un_16_);
	cppVar_21542 = ROM.rd(cppVar_21541);
	cppVar_21544 = (cppVar_21542 == 152);
	if (cppVar_21544) {
	cppVar_21540 = SCON;
	} else {
	cppVar_21546 = PC + 1;
	cppVar_21546 = (cppVar_21546 & cppMask_un_16_);
	cppVar_21547 = ROM.rd(cppVar_21546);
	cppVar_21549 = (cppVar_21547 == 153);
	if (cppVar_21549) {
	cppVar_21545 = SBUF;
	} else {
	cppVar_21551 = PC + 1;
	cppVar_21551 = (cppVar_21551 & cppMask_un_16_);
	cppVar_21552 = ROM.rd(cppVar_21551);
	cppVar_21554 = (cppVar_21552 == 160);
	if (cppVar_21554) {
	cppVar_21550 = P2;
	} else {
	cppVar_21556 = PC + 1;
	cppVar_21556 = (cppVar_21556 & cppMask_un_16_);
	cppVar_21557 = ROM.rd(cppVar_21556);
	cppVar_21559 = (cppVar_21557 == 168);
	if (cppVar_21559) {
	cppVar_21555 = IE;
	} else {
	cppVar_21561 = PC + 1;
	cppVar_21561 = (cppVar_21561 & cppMask_un_16_);
	cppVar_21562 = ROM.rd(cppVar_21561);
	cppVar_21564 = (cppVar_21562 == 176);
	if (cppVar_21564) {
	cppVar_21560 = P3;
	} else {
	cppVar_21566 = PC + 1;
	cppVar_21566 = (cppVar_21566 & cppMask_un_16_);
	cppVar_21567 = ROM.rd(cppVar_21566);
	cppVar_21569 = (cppVar_21567 == 184);
	if (cppVar_21569) {
	cppVar_21565 = IP;
	} else {
	cppVar_21571 = PC + 1;
	cppVar_21571 = (cppVar_21571 & cppMask_un_16_);
	cppVar_21572 = ROM.rd(cppVar_21571);
	cppVar_21574 = (cppVar_21572 == 208);
	if (cppVar_21574) {
	cppVar_21570 = PSW;
	} else {
	cppVar_21576 = PC + 1;
	cppVar_21576 = (cppVar_21576 & cppMask_un_16_);
	cppVar_21577 = ROM.rd(cppVar_21576);
	cppVar_21579 = (cppVar_21577 == 224);
	if (cppVar_21579) {
	cppVar_21575 = ACC;
	} else {
	cppVar_21581 = PC + 1;
	cppVar_21581 = (cppVar_21581 & cppMask_un_16_);
	cppVar_21582 = ROM.rd(cppVar_21581);
	cppVar_21584 = (cppVar_21582 == 240);
	if (cppVar_21584) {
	cppVar_21580 = B;
	} else {
	cppVar_21580 = 0;
	}
	cppVar_21575 = cppVar_21580;
	}
	cppVar_21570 = cppVar_21575;
	}
	cppVar_21565 = cppVar_21570;
	}
	cppVar_21560 = cppVar_21565;
	}
	cppVar_21555 = cppVar_21560;
	}
	cppVar_21550 = cppVar_21555;
	}
	cppVar_21545 = cppVar_21550;
	}
	cppVar_21540 = cppVar_21545;
	}
	cppVar_21535 = cppVar_21540;
	}
	cppVar_21530 = cppVar_21535;
	}
	cppVar_21525 = cppVar_21530;
	}
	cppVar_21520 = cppVar_21525;
	}
	cppVar_21515 = cppVar_21520;
	}
	cppVar_21510 = cppVar_21515;
	}
	cppVar_21505 = cppVar_21510;
	}
	cppVar_21500 = cppVar_21505;
	}
	cppVar_21495 = cppVar_21500;
	}
	cppVar_21490 = cppVar_21495;
	}
	cppVar_21485 = cppVar_21490;
	}
	cppVar_21480 = cppVar_21485;
	}
	cppVar_21471 = cppVar_21480;
	}
	cppVar_21586 = cppVar_21471 & ACC;
	cppVar_21465 = cppVar_21586;
	} else {
	cppVar_21465 = IP;
	}
	cppVar_21461 = cppVar_21465;
	} else {
	cppVar_21588 = ROM.rd(PC);
	cppVar_21590 = (cppVar_21588 == 67);
	if (cppVar_21590) {
	cppVar_21593 = PC + 1;
	cppVar_21593 = (cppVar_21593 & cppMask_un_16_);
	cppVar_21594 = ROM.rd(cppVar_21593);
	cppVar_21596 = (cppVar_21594 == 184);
	if (cppVar_21596) {
	cppVar_21598 = PC + 1;
	cppVar_21598 = (cppVar_21598 & cppMask_un_16_);
	cppVar_21599 = ROM.rd(cppVar_21598);
	cppVar_21600 = (cppVar_21599 >> 7) & cppMask_un_1_;
	cppVar_21602 = (cppVar_21600 == 0);
	if (cppVar_21602) {
	cppVar_21603 = PC + 1;
	cppVar_21603 = (cppVar_21603 & cppMask_un_16_);
	cppVar_21604 = ROM.rd(cppVar_21603);
	cppVar_21605 = IRAM.rd(cppVar_21604);
	cppVar_21597 = cppVar_21605;
	} else {
	cppVar_21607 = PC + 1;
	cppVar_21607 = (cppVar_21607 & cppMask_un_16_);
	cppVar_21608 = ROM.rd(cppVar_21607);
	cppVar_21610 = (cppVar_21608 == 128);
	if (cppVar_21610) {
	cppVar_21606 = P0;
	} else {
	cppVar_21612 = PC + 1;
	cppVar_21612 = (cppVar_21612 & cppMask_un_16_);
	cppVar_21613 = ROM.rd(cppVar_21612);
	cppVar_21615 = (cppVar_21613 == 129);
	if (cppVar_21615) {
	cppVar_21611 = SP;
	} else {
	cppVar_21617 = PC + 1;
	cppVar_21617 = (cppVar_21617 & cppMask_un_16_);
	cppVar_21618 = ROM.rd(cppVar_21617);
	cppVar_21620 = (cppVar_21618 == 130);
	if (cppVar_21620) {
	cppVar_21616 = DPL;
	} else {
	cppVar_21622 = PC + 1;
	cppVar_21622 = (cppVar_21622 & cppMask_un_16_);
	cppVar_21623 = ROM.rd(cppVar_21622);
	cppVar_21625 = (cppVar_21623 == 131);
	if (cppVar_21625) {
	cppVar_21621 = DPH;
	} else {
	cppVar_21627 = PC + 1;
	cppVar_21627 = (cppVar_21627 & cppMask_un_16_);
	cppVar_21628 = ROM.rd(cppVar_21627);
	cppVar_21630 = (cppVar_21628 == 135);
	if (cppVar_21630) {
	cppVar_21626 = PCON;
	} else {
	cppVar_21632 = PC + 1;
	cppVar_21632 = (cppVar_21632 & cppMask_un_16_);
	cppVar_21633 = ROM.rd(cppVar_21632);
	cppVar_21635 = (cppVar_21633 == 136);
	if (cppVar_21635) {
	cppVar_21631 = TCON;
	} else {
	cppVar_21637 = PC + 1;
	cppVar_21637 = (cppVar_21637 & cppMask_un_16_);
	cppVar_21638 = ROM.rd(cppVar_21637);
	cppVar_21640 = (cppVar_21638 == 137);
	if (cppVar_21640) {
	cppVar_21636 = TMOD;
	} else {
	cppVar_21642 = PC + 1;
	cppVar_21642 = (cppVar_21642 & cppMask_un_16_);
	cppVar_21643 = ROM.rd(cppVar_21642);
	cppVar_21645 = (cppVar_21643 == 138);
	if (cppVar_21645) {
	cppVar_21641 = TL0;
	} else {
	cppVar_21647 = PC + 1;
	cppVar_21647 = (cppVar_21647 & cppMask_un_16_);
	cppVar_21648 = ROM.rd(cppVar_21647);
	cppVar_21650 = (cppVar_21648 == 140);
	if (cppVar_21650) {
	cppVar_21646 = TH0;
	} else {
	cppVar_21652 = PC + 1;
	cppVar_21652 = (cppVar_21652 & cppMask_un_16_);
	cppVar_21653 = ROM.rd(cppVar_21652);
	cppVar_21655 = (cppVar_21653 == 139);
	if (cppVar_21655) {
	cppVar_21651 = TL1;
	} else {
	cppVar_21657 = PC + 1;
	cppVar_21657 = (cppVar_21657 & cppMask_un_16_);
	cppVar_21658 = ROM.rd(cppVar_21657);
	cppVar_21660 = (cppVar_21658 == 141);
	if (cppVar_21660) {
	cppVar_21656 = TH1;
	} else {
	cppVar_21662 = PC + 1;
	cppVar_21662 = (cppVar_21662 & cppMask_un_16_);
	cppVar_21663 = ROM.rd(cppVar_21662);
	cppVar_21665 = (cppVar_21663 == 144);
	if (cppVar_21665) {
	cppVar_21661 = P1;
	} else {
	cppVar_21667 = PC + 1;
	cppVar_21667 = (cppVar_21667 & cppMask_un_16_);
	cppVar_21668 = ROM.rd(cppVar_21667);
	cppVar_21670 = (cppVar_21668 == 152);
	if (cppVar_21670) {
	cppVar_21666 = SCON;
	} else {
	cppVar_21672 = PC + 1;
	cppVar_21672 = (cppVar_21672 & cppMask_un_16_);
	cppVar_21673 = ROM.rd(cppVar_21672);
	cppVar_21675 = (cppVar_21673 == 153);
	if (cppVar_21675) {
	cppVar_21671 = SBUF;
	} else {
	cppVar_21677 = PC + 1;
	cppVar_21677 = (cppVar_21677 & cppMask_un_16_);
	cppVar_21678 = ROM.rd(cppVar_21677);
	cppVar_21680 = (cppVar_21678 == 160);
	if (cppVar_21680) {
	cppVar_21676 = P2;
	} else {
	cppVar_21682 = PC + 1;
	cppVar_21682 = (cppVar_21682 & cppMask_un_16_);
	cppVar_21683 = ROM.rd(cppVar_21682);
	cppVar_21685 = (cppVar_21683 == 168);
	if (cppVar_21685) {
	cppVar_21681 = IE;
	} else {
	cppVar_21687 = PC + 1;
	cppVar_21687 = (cppVar_21687 & cppMask_un_16_);
	cppVar_21688 = ROM.rd(cppVar_21687);
	cppVar_21690 = (cppVar_21688 == 176);
	if (cppVar_21690) {
	cppVar_21686 = P3;
	} else {
	cppVar_21692 = PC + 1;
	cppVar_21692 = (cppVar_21692 & cppMask_un_16_);
	cppVar_21693 = ROM.rd(cppVar_21692);
	cppVar_21695 = (cppVar_21693 == 184);
	if (cppVar_21695) {
	cppVar_21691 = IP;
	} else {
	cppVar_21697 = PC + 1;
	cppVar_21697 = (cppVar_21697 & cppMask_un_16_);
	cppVar_21698 = ROM.rd(cppVar_21697);
	cppVar_21700 = (cppVar_21698 == 208);
	if (cppVar_21700) {
	cppVar_21696 = PSW;
	} else {
	cppVar_21702 = PC + 1;
	cppVar_21702 = (cppVar_21702 & cppMask_un_16_);
	cppVar_21703 = ROM.rd(cppVar_21702);
	cppVar_21705 = (cppVar_21703 == 224);
	if (cppVar_21705) {
	cppVar_21701 = ACC;
	} else {
	cppVar_21707 = PC + 1;
	cppVar_21707 = (cppVar_21707 & cppMask_un_16_);
	cppVar_21708 = ROM.rd(cppVar_21707);
	cppVar_21710 = (cppVar_21708 == 240);
	if (cppVar_21710) {
	cppVar_21706 = B;
	} else {
	cppVar_21706 = 0;
	}
	cppVar_21701 = cppVar_21706;
	}
	cppVar_21696 = cppVar_21701;
	}
	cppVar_21691 = cppVar_21696;
	}
	cppVar_21686 = cppVar_21691;
	}
	cppVar_21681 = cppVar_21686;
	}
	cppVar_21676 = cppVar_21681;
	}
	cppVar_21671 = cppVar_21676;
	}
	cppVar_21666 = cppVar_21671;
	}
	cppVar_21661 = cppVar_21666;
	}
	cppVar_21656 = cppVar_21661;
	}
	cppVar_21651 = cppVar_21656;
	}
	cppVar_21646 = cppVar_21651;
	}
	cppVar_21641 = cppVar_21646;
	}
	cppVar_21636 = cppVar_21641;
	}
	cppVar_21631 = cppVar_21636;
	}
	cppVar_21626 = cppVar_21631;
	}
	cppVar_21621 = cppVar_21626;
	}
	cppVar_21616 = cppVar_21621;
	}
	cppVar_21611 = cppVar_21616;
	}
	cppVar_21606 = cppVar_21611;
	}
	cppVar_21597 = cppVar_21606;
	}
	cppVar_21713 = PC + 2;
	cppVar_21713 = (cppVar_21713 & cppMask_un_16_);
	cppVar_21714 = ROM.rd(cppVar_21713);
	cppVar_21715 = cppVar_21597 | cppVar_21714;
	cppVar_21591 = cppVar_21715;
	} else {
	cppVar_21591 = IP;
	}
	cppVar_21587 = cppVar_21591;
	} else {
	cppVar_21717 = ROM.rd(PC);
	cppVar_21719 = (cppVar_21717 == 66);
	if (cppVar_21719) {
	cppVar_21722 = PC + 1;
	cppVar_21722 = (cppVar_21722 & cppMask_un_16_);
	cppVar_21723 = ROM.rd(cppVar_21722);
	cppVar_21725 = (cppVar_21723 == 184);
	if (cppVar_21725) {
	cppVar_21727 = PC + 1;
	cppVar_21727 = (cppVar_21727 & cppMask_un_16_);
	cppVar_21728 = ROM.rd(cppVar_21727);
	cppVar_21729 = (cppVar_21728 >> 7) & cppMask_un_1_;
	cppVar_21731 = (cppVar_21729 == 0);
	if (cppVar_21731) {
	cppVar_21732 = PC + 1;
	cppVar_21732 = (cppVar_21732 & cppMask_un_16_);
	cppVar_21733 = ROM.rd(cppVar_21732);
	cppVar_21734 = IRAM.rd(cppVar_21733);
	cppVar_21726 = cppVar_21734;
	} else {
	cppVar_21736 = PC + 1;
	cppVar_21736 = (cppVar_21736 & cppMask_un_16_);
	cppVar_21737 = ROM.rd(cppVar_21736);
	cppVar_21739 = (cppVar_21737 == 128);
	if (cppVar_21739) {
	cppVar_21735 = P0;
	} else {
	cppVar_21741 = PC + 1;
	cppVar_21741 = (cppVar_21741 & cppMask_un_16_);
	cppVar_21742 = ROM.rd(cppVar_21741);
	cppVar_21744 = (cppVar_21742 == 129);
	if (cppVar_21744) {
	cppVar_21740 = SP;
	} else {
	cppVar_21746 = PC + 1;
	cppVar_21746 = (cppVar_21746 & cppMask_un_16_);
	cppVar_21747 = ROM.rd(cppVar_21746);
	cppVar_21749 = (cppVar_21747 == 130);
	if (cppVar_21749) {
	cppVar_21745 = DPL;
	} else {
	cppVar_21751 = PC + 1;
	cppVar_21751 = (cppVar_21751 & cppMask_un_16_);
	cppVar_21752 = ROM.rd(cppVar_21751);
	cppVar_21754 = (cppVar_21752 == 131);
	if (cppVar_21754) {
	cppVar_21750 = DPH;
	} else {
	cppVar_21756 = PC + 1;
	cppVar_21756 = (cppVar_21756 & cppMask_un_16_);
	cppVar_21757 = ROM.rd(cppVar_21756);
	cppVar_21759 = (cppVar_21757 == 135);
	if (cppVar_21759) {
	cppVar_21755 = PCON;
	} else {
	cppVar_21761 = PC + 1;
	cppVar_21761 = (cppVar_21761 & cppMask_un_16_);
	cppVar_21762 = ROM.rd(cppVar_21761);
	cppVar_21764 = (cppVar_21762 == 136);
	if (cppVar_21764) {
	cppVar_21760 = TCON;
	} else {
	cppVar_21766 = PC + 1;
	cppVar_21766 = (cppVar_21766 & cppMask_un_16_);
	cppVar_21767 = ROM.rd(cppVar_21766);
	cppVar_21769 = (cppVar_21767 == 137);
	if (cppVar_21769) {
	cppVar_21765 = TMOD;
	} else {
	cppVar_21771 = PC + 1;
	cppVar_21771 = (cppVar_21771 & cppMask_un_16_);
	cppVar_21772 = ROM.rd(cppVar_21771);
	cppVar_21774 = (cppVar_21772 == 138);
	if (cppVar_21774) {
	cppVar_21770 = TL0;
	} else {
	cppVar_21776 = PC + 1;
	cppVar_21776 = (cppVar_21776 & cppMask_un_16_);
	cppVar_21777 = ROM.rd(cppVar_21776);
	cppVar_21779 = (cppVar_21777 == 140);
	if (cppVar_21779) {
	cppVar_21775 = TH0;
	} else {
	cppVar_21781 = PC + 1;
	cppVar_21781 = (cppVar_21781 & cppMask_un_16_);
	cppVar_21782 = ROM.rd(cppVar_21781);
	cppVar_21784 = (cppVar_21782 == 139);
	if (cppVar_21784) {
	cppVar_21780 = TL1;
	} else {
	cppVar_21786 = PC + 1;
	cppVar_21786 = (cppVar_21786 & cppMask_un_16_);
	cppVar_21787 = ROM.rd(cppVar_21786);
	cppVar_21789 = (cppVar_21787 == 141);
	if (cppVar_21789) {
	cppVar_21785 = TH1;
	} else {
	cppVar_21791 = PC + 1;
	cppVar_21791 = (cppVar_21791 & cppMask_un_16_);
	cppVar_21792 = ROM.rd(cppVar_21791);
	cppVar_21794 = (cppVar_21792 == 144);
	if (cppVar_21794) {
	cppVar_21790 = P1;
	} else {
	cppVar_21796 = PC + 1;
	cppVar_21796 = (cppVar_21796 & cppMask_un_16_);
	cppVar_21797 = ROM.rd(cppVar_21796);
	cppVar_21799 = (cppVar_21797 == 152);
	if (cppVar_21799) {
	cppVar_21795 = SCON;
	} else {
	cppVar_21801 = PC + 1;
	cppVar_21801 = (cppVar_21801 & cppMask_un_16_);
	cppVar_21802 = ROM.rd(cppVar_21801);
	cppVar_21804 = (cppVar_21802 == 153);
	if (cppVar_21804) {
	cppVar_21800 = SBUF;
	} else {
	cppVar_21806 = PC + 1;
	cppVar_21806 = (cppVar_21806 & cppMask_un_16_);
	cppVar_21807 = ROM.rd(cppVar_21806);
	cppVar_21809 = (cppVar_21807 == 160);
	if (cppVar_21809) {
	cppVar_21805 = P2;
	} else {
	cppVar_21811 = PC + 1;
	cppVar_21811 = (cppVar_21811 & cppMask_un_16_);
	cppVar_21812 = ROM.rd(cppVar_21811);
	cppVar_21814 = (cppVar_21812 == 168);
	if (cppVar_21814) {
	cppVar_21810 = IE;
	} else {
	cppVar_21816 = PC + 1;
	cppVar_21816 = (cppVar_21816 & cppMask_un_16_);
	cppVar_21817 = ROM.rd(cppVar_21816);
	cppVar_21819 = (cppVar_21817 == 176);
	if (cppVar_21819) {
	cppVar_21815 = P3;
	} else {
	cppVar_21821 = PC + 1;
	cppVar_21821 = (cppVar_21821 & cppMask_un_16_);
	cppVar_21822 = ROM.rd(cppVar_21821);
	cppVar_21824 = (cppVar_21822 == 184);
	if (cppVar_21824) {
	cppVar_21820 = IP;
	} else {
	cppVar_21826 = PC + 1;
	cppVar_21826 = (cppVar_21826 & cppMask_un_16_);
	cppVar_21827 = ROM.rd(cppVar_21826);
	cppVar_21829 = (cppVar_21827 == 208);
	if (cppVar_21829) {
	cppVar_21825 = PSW;
	} else {
	cppVar_21831 = PC + 1;
	cppVar_21831 = (cppVar_21831 & cppMask_un_16_);
	cppVar_21832 = ROM.rd(cppVar_21831);
	cppVar_21834 = (cppVar_21832 == 224);
	if (cppVar_21834) {
	cppVar_21830 = ACC;
	} else {
	cppVar_21836 = PC + 1;
	cppVar_21836 = (cppVar_21836 & cppMask_un_16_);
	cppVar_21837 = ROM.rd(cppVar_21836);
	cppVar_21839 = (cppVar_21837 == 240);
	if (cppVar_21839) {
	cppVar_21835 = B;
	} else {
	cppVar_21835 = 0;
	}
	cppVar_21830 = cppVar_21835;
	}
	cppVar_21825 = cppVar_21830;
	}
	cppVar_21820 = cppVar_21825;
	}
	cppVar_21815 = cppVar_21820;
	}
	cppVar_21810 = cppVar_21815;
	}
	cppVar_21805 = cppVar_21810;
	}
	cppVar_21800 = cppVar_21805;
	}
	cppVar_21795 = cppVar_21800;
	}
	cppVar_21790 = cppVar_21795;
	}
	cppVar_21785 = cppVar_21790;
	}
	cppVar_21780 = cppVar_21785;
	}
	cppVar_21775 = cppVar_21780;
	}
	cppVar_21770 = cppVar_21775;
	}
	cppVar_21765 = cppVar_21770;
	}
	cppVar_21760 = cppVar_21765;
	}
	cppVar_21755 = cppVar_21760;
	}
	cppVar_21750 = cppVar_21755;
	}
	cppVar_21745 = cppVar_21750;
	}
	cppVar_21740 = cppVar_21745;
	}
	cppVar_21735 = cppVar_21740;
	}
	cppVar_21726 = cppVar_21735;
	}
	cppVar_21841 = cppVar_21726 | ACC;
	cppVar_21720 = cppVar_21841;
	} else {
	cppVar_21720 = IP;
	}
	cppVar_21716 = cppVar_21720;
	} else {
	cppVar_21843 = ROM.rd(PC);
	cppVar_21845 = (cppVar_21843 == 213);
	cppVar_21846 = ROM.rd(PC);
	cppVar_21848 = (cppVar_21846 == 21);
	cppVar_21849 = cppVar_21845 || cppVar_21848;
	if (cppVar_21849) {
	cppVar_21852 = PC + 1;
	cppVar_21852 = (cppVar_21852 & cppMask_un_16_);
	cppVar_21853 = ROM.rd(cppVar_21852);
	cppVar_21855 = (cppVar_21853 == 184);
	if (cppVar_21855) {
	cppVar_21857 = PC + 1;
	cppVar_21857 = (cppVar_21857 & cppMask_un_16_);
	cppVar_21858 = ROM.rd(cppVar_21857);
	cppVar_21859 = (cppVar_21858 >> 7) & cppMask_un_1_;
	cppVar_21861 = (cppVar_21859 == 0);
	if (cppVar_21861) {
	cppVar_21862 = PC + 1;
	cppVar_21862 = (cppVar_21862 & cppMask_un_16_);
	cppVar_21863 = ROM.rd(cppVar_21862);
	cppVar_21864 = IRAM.rd(cppVar_21863);
	cppVar_21856 = cppVar_21864;
	} else {
	cppVar_21866 = PC + 1;
	cppVar_21866 = (cppVar_21866 & cppMask_un_16_);
	cppVar_21867 = ROM.rd(cppVar_21866);
	cppVar_21869 = (cppVar_21867 == 128);
	if (cppVar_21869) {
	cppVar_21865 = P0;
	} else {
	cppVar_21871 = PC + 1;
	cppVar_21871 = (cppVar_21871 & cppMask_un_16_);
	cppVar_21872 = ROM.rd(cppVar_21871);
	cppVar_21874 = (cppVar_21872 == 129);
	if (cppVar_21874) {
	cppVar_21870 = SP;
	} else {
	cppVar_21876 = PC + 1;
	cppVar_21876 = (cppVar_21876 & cppMask_un_16_);
	cppVar_21877 = ROM.rd(cppVar_21876);
	cppVar_21879 = (cppVar_21877 == 130);
	if (cppVar_21879) {
	cppVar_21875 = DPL;
	} else {
	cppVar_21881 = PC + 1;
	cppVar_21881 = (cppVar_21881 & cppMask_un_16_);
	cppVar_21882 = ROM.rd(cppVar_21881);
	cppVar_21884 = (cppVar_21882 == 131);
	if (cppVar_21884) {
	cppVar_21880 = DPH;
	} else {
	cppVar_21886 = PC + 1;
	cppVar_21886 = (cppVar_21886 & cppMask_un_16_);
	cppVar_21887 = ROM.rd(cppVar_21886);
	cppVar_21889 = (cppVar_21887 == 135);
	if (cppVar_21889) {
	cppVar_21885 = PCON;
	} else {
	cppVar_21891 = PC + 1;
	cppVar_21891 = (cppVar_21891 & cppMask_un_16_);
	cppVar_21892 = ROM.rd(cppVar_21891);
	cppVar_21894 = (cppVar_21892 == 136);
	if (cppVar_21894) {
	cppVar_21890 = TCON;
	} else {
	cppVar_21896 = PC + 1;
	cppVar_21896 = (cppVar_21896 & cppMask_un_16_);
	cppVar_21897 = ROM.rd(cppVar_21896);
	cppVar_21899 = (cppVar_21897 == 137);
	if (cppVar_21899) {
	cppVar_21895 = TMOD;
	} else {
	cppVar_21901 = PC + 1;
	cppVar_21901 = (cppVar_21901 & cppMask_un_16_);
	cppVar_21902 = ROM.rd(cppVar_21901);
	cppVar_21904 = (cppVar_21902 == 138);
	if (cppVar_21904) {
	cppVar_21900 = TL0;
	} else {
	cppVar_21906 = PC + 1;
	cppVar_21906 = (cppVar_21906 & cppMask_un_16_);
	cppVar_21907 = ROM.rd(cppVar_21906);
	cppVar_21909 = (cppVar_21907 == 140);
	if (cppVar_21909) {
	cppVar_21905 = TH0;
	} else {
	cppVar_21911 = PC + 1;
	cppVar_21911 = (cppVar_21911 & cppMask_un_16_);
	cppVar_21912 = ROM.rd(cppVar_21911);
	cppVar_21914 = (cppVar_21912 == 139);
	if (cppVar_21914) {
	cppVar_21910 = TL1;
	} else {
	cppVar_21916 = PC + 1;
	cppVar_21916 = (cppVar_21916 & cppMask_un_16_);
	cppVar_21917 = ROM.rd(cppVar_21916);
	cppVar_21919 = (cppVar_21917 == 141);
	if (cppVar_21919) {
	cppVar_21915 = TH1;
	} else {
	cppVar_21921 = PC + 1;
	cppVar_21921 = (cppVar_21921 & cppMask_un_16_);
	cppVar_21922 = ROM.rd(cppVar_21921);
	cppVar_21924 = (cppVar_21922 == 144);
	if (cppVar_21924) {
	cppVar_21920 = P1;
	} else {
	cppVar_21926 = PC + 1;
	cppVar_21926 = (cppVar_21926 & cppMask_un_16_);
	cppVar_21927 = ROM.rd(cppVar_21926);
	cppVar_21929 = (cppVar_21927 == 152);
	if (cppVar_21929) {
	cppVar_21925 = SCON;
	} else {
	cppVar_21931 = PC + 1;
	cppVar_21931 = (cppVar_21931 & cppMask_un_16_);
	cppVar_21932 = ROM.rd(cppVar_21931);
	cppVar_21934 = (cppVar_21932 == 153);
	if (cppVar_21934) {
	cppVar_21930 = SBUF;
	} else {
	cppVar_21936 = PC + 1;
	cppVar_21936 = (cppVar_21936 & cppMask_un_16_);
	cppVar_21937 = ROM.rd(cppVar_21936);
	cppVar_21939 = (cppVar_21937 == 160);
	if (cppVar_21939) {
	cppVar_21935 = P2;
	} else {
	cppVar_21941 = PC + 1;
	cppVar_21941 = (cppVar_21941 & cppMask_un_16_);
	cppVar_21942 = ROM.rd(cppVar_21941);
	cppVar_21944 = (cppVar_21942 == 168);
	if (cppVar_21944) {
	cppVar_21940 = IE;
	} else {
	cppVar_21946 = PC + 1;
	cppVar_21946 = (cppVar_21946 & cppMask_un_16_);
	cppVar_21947 = ROM.rd(cppVar_21946);
	cppVar_21949 = (cppVar_21947 == 176);
	if (cppVar_21949) {
	cppVar_21945 = P3;
	} else {
	cppVar_21951 = PC + 1;
	cppVar_21951 = (cppVar_21951 & cppMask_un_16_);
	cppVar_21952 = ROM.rd(cppVar_21951);
	cppVar_21954 = (cppVar_21952 == 184);
	if (cppVar_21954) {
	cppVar_21950 = IP;
	} else {
	cppVar_21956 = PC + 1;
	cppVar_21956 = (cppVar_21956 & cppMask_un_16_);
	cppVar_21957 = ROM.rd(cppVar_21956);
	cppVar_21959 = (cppVar_21957 == 208);
	if (cppVar_21959) {
	cppVar_21955 = PSW;
	} else {
	cppVar_21961 = PC + 1;
	cppVar_21961 = (cppVar_21961 & cppMask_un_16_);
	cppVar_21962 = ROM.rd(cppVar_21961);
	cppVar_21964 = (cppVar_21962 == 224);
	if (cppVar_21964) {
	cppVar_21960 = ACC;
	} else {
	cppVar_21966 = PC + 1;
	cppVar_21966 = (cppVar_21966 & cppMask_un_16_);
	cppVar_21967 = ROM.rd(cppVar_21966);
	cppVar_21969 = (cppVar_21967 == 240);
	if (cppVar_21969) {
	cppVar_21965 = B;
	} else {
	cppVar_21965 = 0;
	}
	cppVar_21960 = cppVar_21965;
	}
	cppVar_21955 = cppVar_21960;
	}
	cppVar_21950 = cppVar_21955;
	}
	cppVar_21945 = cppVar_21950;
	}
	cppVar_21940 = cppVar_21945;
	}
	cppVar_21935 = cppVar_21940;
	}
	cppVar_21930 = cppVar_21935;
	}
	cppVar_21925 = cppVar_21930;
	}
	cppVar_21920 = cppVar_21925;
	}
	cppVar_21915 = cppVar_21920;
	}
	cppVar_21910 = cppVar_21915;
	}
	cppVar_21905 = cppVar_21910;
	}
	cppVar_21900 = cppVar_21905;
	}
	cppVar_21895 = cppVar_21900;
	}
	cppVar_21890 = cppVar_21895;
	}
	cppVar_21885 = cppVar_21890;
	}
	cppVar_21880 = cppVar_21885;
	}
	cppVar_21875 = cppVar_21880;
	}
	cppVar_21870 = cppVar_21875;
	}
	cppVar_21865 = cppVar_21870;
	}
	cppVar_21856 = cppVar_21865;
	}
	cppVar_21972 = cppVar_21856 - 1;
	cppVar_21972 = (cppVar_21972 & cppMask_un_8_);
	cppVar_21850 = cppVar_21972;
	} else {
	cppVar_21850 = IP;
	}
	cppVar_21842 = cppVar_21850;
	} else {
	cppVar_21974 = ROM.rd(PC);
	cppVar_21976 = (cppVar_21974 == 194);
	cppVar_21977 = ROM.rd(PC);
	cppVar_21979 = (cppVar_21977 == 16);
	cppVar_21980 = cppVar_21976 || cppVar_21979;
	if (cppVar_21980) {
	cppVar_21984 = PC + 1;
	cppVar_21984 = (cppVar_21984 & cppMask_un_16_);
	cppVar_21985 = ROM.rd(cppVar_21984);
	cppVar_21986 = (cppVar_21985 >> 7) & cppMask_un_1_;
	cppVar_21988 = (cppVar_21986 == 1);
	if (cppVar_21988) {
	cppVar_21989 = PC + 1;
	cppVar_21989 = (cppVar_21989 & cppMask_un_16_);
	cppVar_21990 = ROM.rd(cppVar_21989);
	cppVar_21991 = (cppVar_21990 >> 3) & cppMask_un_5_;
	cppVar_21993 = (cppVar_21991 << 3) | 0;
	cppVar_21993 = (cppVar_21993 & cppMask_un_8_);
	cppVar_21982 = cppVar_21993;
	} else {
	cppVar_21994 = PC + 1;
	cppVar_21994 = (cppVar_21994 & cppMask_un_16_);
	cppVar_21995 = ROM.rd(cppVar_21994);
	cppVar_21996 = (cppVar_21995 >> 3) & cppMask_un_5_;
	cppVar_21997 = (cppVar_21996 & cppMask_un_5_);
	cppVar_21999 = cppVar_21997 + 32;
	cppVar_21999 = (cppVar_21999 & cppMask_un_8_);
	cppVar_21982 = cppVar_21999;
	}
	cppVar_22001 = (cppVar_21982 == 184);
	if (cppVar_22001) {
	cppVar_22003 = PC + 1;
	cppVar_22003 = (cppVar_22003 & cppMask_un_16_);
	cppVar_22004 = ROM.rd(cppVar_22003);
	cppVar_22005 = (cppVar_22004 >> 0) & cppMask_un_3_;
	cppVar_22006 = (cppVar_22005 & cppMask_un_3_);
	cppVar_22007 = 1 << static_cast<unsigned>(cppVar_22006);
	cppVar_22007 = (cppVar_22007 & cppMask_un_8_);
	cppVar_22008 = ~cppVar_22007;
	cppVar_22011 = PC + 1;
	cppVar_22011 = (cppVar_22011 & cppMask_un_16_);
	cppVar_22012 = ROM.rd(cppVar_22011);
	cppVar_22013 = (cppVar_22012 >> 7) & cppMask_un_1_;
	cppVar_22014 = (cppVar_22013 == 1);
	if (cppVar_22014) {
	cppVar_22015 = PC + 1;
	cppVar_22015 = (cppVar_22015 & cppMask_un_16_);
	cppVar_22016 = ROM.rd(cppVar_22015);
	cppVar_22017 = (cppVar_22016 >> 3) & cppMask_un_5_;
	cppVar_22018 = (cppVar_22017 << 3) | 0;
	cppVar_22018 = (cppVar_22018 & cppMask_un_8_);
	cppVar_22010 = cppVar_22018;
	} else {
	cppVar_22019 = PC + 1;
	cppVar_22019 = (cppVar_22019 & cppMask_un_16_);
	cppVar_22020 = ROM.rd(cppVar_22019);
	cppVar_22021 = (cppVar_22020 >> 3) & cppMask_un_5_;
	cppVar_22022 = (cppVar_22021 & cppMask_un_5_);
	cppVar_22023 = cppVar_22022 + 32;
	cppVar_22023 = (cppVar_22023 & cppMask_un_8_);
	cppVar_22010 = cppVar_22023;
	}
	cppVar_22024 = (cppVar_22010 >> 7) & cppMask_un_1_;
	cppVar_22026 = (cppVar_22024 == 0);
	if (cppVar_22026) {
	cppVar_22028 = PC + 1;
	cppVar_22028 = (cppVar_22028 & cppMask_un_16_);
	cppVar_22029 = ROM.rd(cppVar_22028);
	cppVar_22030 = (cppVar_22029 >> 7) & cppMask_un_1_;
	cppVar_22031 = (cppVar_22030 == 1);
	if (cppVar_22031) {
	cppVar_22032 = PC + 1;
	cppVar_22032 = (cppVar_22032 & cppMask_un_16_);
	cppVar_22033 = ROM.rd(cppVar_22032);
	cppVar_22034 = (cppVar_22033 >> 3) & cppMask_un_5_;
	cppVar_22035 = (cppVar_22034 << 3) | 0;
	cppVar_22035 = (cppVar_22035 & cppMask_un_8_);
	cppVar_22027 = cppVar_22035;
	} else {
	cppVar_22036 = PC + 1;
	cppVar_22036 = (cppVar_22036 & cppMask_un_16_);
	cppVar_22037 = ROM.rd(cppVar_22036);
	cppVar_22038 = (cppVar_22037 >> 3) & cppMask_un_5_;
	cppVar_22039 = (cppVar_22038 & cppMask_un_5_);
	cppVar_22040 = cppVar_22039 + 32;
	cppVar_22040 = (cppVar_22040 & cppMask_un_8_);
	cppVar_22027 = cppVar_22040;
	}
	cppVar_22041 = IRAM.rd(cppVar_22027);
	cppVar_22009 = cppVar_22041;
	} else {
	cppVar_22044 = PC + 1;
	cppVar_22044 = (cppVar_22044 & cppMask_un_16_);
	cppVar_22045 = ROM.rd(cppVar_22044);
	cppVar_22046 = (cppVar_22045 >> 7) & cppMask_un_1_;
	cppVar_22047 = (cppVar_22046 == 1);
	if (cppVar_22047) {
	cppVar_22048 = PC + 1;
	cppVar_22048 = (cppVar_22048 & cppMask_un_16_);
	cppVar_22049 = ROM.rd(cppVar_22048);
	cppVar_22050 = (cppVar_22049 >> 3) & cppMask_un_5_;
	cppVar_22051 = (cppVar_22050 << 3) | 0;
	cppVar_22051 = (cppVar_22051 & cppMask_un_8_);
	cppVar_22043 = cppVar_22051;
	} else {
	cppVar_22052 = PC + 1;
	cppVar_22052 = (cppVar_22052 & cppMask_un_16_);
	cppVar_22053 = ROM.rd(cppVar_22052);
	cppVar_22054 = (cppVar_22053 >> 3) & cppMask_un_5_;
	cppVar_22055 = (cppVar_22054 & cppMask_un_5_);
	cppVar_22056 = cppVar_22055 + 32;
	cppVar_22056 = (cppVar_22056 & cppMask_un_8_);
	cppVar_22043 = cppVar_22056;
	}
	cppVar_22058 = (cppVar_22043 == 128);
	if (cppVar_22058) {
	cppVar_22042 = P0;
	} else {
	cppVar_22061 = PC + 1;
	cppVar_22061 = (cppVar_22061 & cppMask_un_16_);
	cppVar_22062 = ROM.rd(cppVar_22061);
	cppVar_22063 = (cppVar_22062 >> 7) & cppMask_un_1_;
	cppVar_22064 = (cppVar_22063 == 1);
	if (cppVar_22064) {
	cppVar_22065 = PC + 1;
	cppVar_22065 = (cppVar_22065 & cppMask_un_16_);
	cppVar_22066 = ROM.rd(cppVar_22065);
	cppVar_22067 = (cppVar_22066 >> 3) & cppMask_un_5_;
	cppVar_22068 = (cppVar_22067 << 3) | 0;
	cppVar_22068 = (cppVar_22068 & cppMask_un_8_);
	cppVar_22060 = cppVar_22068;
	} else {
	cppVar_22069 = PC + 1;
	cppVar_22069 = (cppVar_22069 & cppMask_un_16_);
	cppVar_22070 = ROM.rd(cppVar_22069);
	cppVar_22071 = (cppVar_22070 >> 3) & cppMask_un_5_;
	cppVar_22072 = (cppVar_22071 & cppMask_un_5_);
	cppVar_22073 = cppVar_22072 + 32;
	cppVar_22073 = (cppVar_22073 & cppMask_un_8_);
	cppVar_22060 = cppVar_22073;
	}
	cppVar_22075 = (cppVar_22060 == 129);
	if (cppVar_22075) {
	cppVar_22059 = SP;
	} else {
	cppVar_22078 = PC + 1;
	cppVar_22078 = (cppVar_22078 & cppMask_un_16_);
	cppVar_22079 = ROM.rd(cppVar_22078);
	cppVar_22080 = (cppVar_22079 >> 7) & cppMask_un_1_;
	cppVar_22081 = (cppVar_22080 == 1);
	if (cppVar_22081) {
	cppVar_22082 = PC + 1;
	cppVar_22082 = (cppVar_22082 & cppMask_un_16_);
	cppVar_22083 = ROM.rd(cppVar_22082);
	cppVar_22084 = (cppVar_22083 >> 3) & cppMask_un_5_;
	cppVar_22085 = (cppVar_22084 << 3) | 0;
	cppVar_22085 = (cppVar_22085 & cppMask_un_8_);
	cppVar_22077 = cppVar_22085;
	} else {
	cppVar_22086 = PC + 1;
	cppVar_22086 = (cppVar_22086 & cppMask_un_16_);
	cppVar_22087 = ROM.rd(cppVar_22086);
	cppVar_22088 = (cppVar_22087 >> 3) & cppMask_un_5_;
	cppVar_22089 = (cppVar_22088 & cppMask_un_5_);
	cppVar_22090 = cppVar_22089 + 32;
	cppVar_22090 = (cppVar_22090 & cppMask_un_8_);
	cppVar_22077 = cppVar_22090;
	}
	cppVar_22092 = (cppVar_22077 == 130);
	if (cppVar_22092) {
	cppVar_22076 = DPL;
	} else {
	cppVar_22095 = PC + 1;
	cppVar_22095 = (cppVar_22095 & cppMask_un_16_);
	cppVar_22096 = ROM.rd(cppVar_22095);
	cppVar_22097 = (cppVar_22096 >> 7) & cppMask_un_1_;
	cppVar_22098 = (cppVar_22097 == 1);
	if (cppVar_22098) {
	cppVar_22099 = PC + 1;
	cppVar_22099 = (cppVar_22099 & cppMask_un_16_);
	cppVar_22100 = ROM.rd(cppVar_22099);
	cppVar_22101 = (cppVar_22100 >> 3) & cppMask_un_5_;
	cppVar_22102 = (cppVar_22101 << 3) | 0;
	cppVar_22102 = (cppVar_22102 & cppMask_un_8_);
	cppVar_22094 = cppVar_22102;
	} else {
	cppVar_22103 = PC + 1;
	cppVar_22103 = (cppVar_22103 & cppMask_un_16_);
	cppVar_22104 = ROM.rd(cppVar_22103);
	cppVar_22105 = (cppVar_22104 >> 3) & cppMask_un_5_;
	cppVar_22106 = (cppVar_22105 & cppMask_un_5_);
	cppVar_22107 = cppVar_22106 + 32;
	cppVar_22107 = (cppVar_22107 & cppMask_un_8_);
	cppVar_22094 = cppVar_22107;
	}
	cppVar_22109 = (cppVar_22094 == 131);
	if (cppVar_22109) {
	cppVar_22093 = DPH;
	} else {
	cppVar_22112 = PC + 1;
	cppVar_22112 = (cppVar_22112 & cppMask_un_16_);
	cppVar_22113 = ROM.rd(cppVar_22112);
	cppVar_22114 = (cppVar_22113 >> 7) & cppMask_un_1_;
	cppVar_22115 = (cppVar_22114 == 1);
	if (cppVar_22115) {
	cppVar_22116 = PC + 1;
	cppVar_22116 = (cppVar_22116 & cppMask_un_16_);
	cppVar_22117 = ROM.rd(cppVar_22116);
	cppVar_22118 = (cppVar_22117 >> 3) & cppMask_un_5_;
	cppVar_22119 = (cppVar_22118 << 3) | 0;
	cppVar_22119 = (cppVar_22119 & cppMask_un_8_);
	cppVar_22111 = cppVar_22119;
	} else {
	cppVar_22120 = PC + 1;
	cppVar_22120 = (cppVar_22120 & cppMask_un_16_);
	cppVar_22121 = ROM.rd(cppVar_22120);
	cppVar_22122 = (cppVar_22121 >> 3) & cppMask_un_5_;
	cppVar_22123 = (cppVar_22122 & cppMask_un_5_);
	cppVar_22124 = cppVar_22123 + 32;
	cppVar_22124 = (cppVar_22124 & cppMask_un_8_);
	cppVar_22111 = cppVar_22124;
	}
	cppVar_22126 = (cppVar_22111 == 135);
	if (cppVar_22126) {
	cppVar_22110 = PCON;
	} else {
	cppVar_22129 = PC + 1;
	cppVar_22129 = (cppVar_22129 & cppMask_un_16_);
	cppVar_22130 = ROM.rd(cppVar_22129);
	cppVar_22131 = (cppVar_22130 >> 7) & cppMask_un_1_;
	cppVar_22132 = (cppVar_22131 == 1);
	if (cppVar_22132) {
	cppVar_22133 = PC + 1;
	cppVar_22133 = (cppVar_22133 & cppMask_un_16_);
	cppVar_22134 = ROM.rd(cppVar_22133);
	cppVar_22135 = (cppVar_22134 >> 3) & cppMask_un_5_;
	cppVar_22136 = (cppVar_22135 << 3) | 0;
	cppVar_22136 = (cppVar_22136 & cppMask_un_8_);
	cppVar_22128 = cppVar_22136;
	} else {
	cppVar_22137 = PC + 1;
	cppVar_22137 = (cppVar_22137 & cppMask_un_16_);
	cppVar_22138 = ROM.rd(cppVar_22137);
	cppVar_22139 = (cppVar_22138 >> 3) & cppMask_un_5_;
	cppVar_22140 = (cppVar_22139 & cppMask_un_5_);
	cppVar_22141 = cppVar_22140 + 32;
	cppVar_22141 = (cppVar_22141 & cppMask_un_8_);
	cppVar_22128 = cppVar_22141;
	}
	cppVar_22143 = (cppVar_22128 == 136);
	if (cppVar_22143) {
	cppVar_22127 = TCON;
	} else {
	cppVar_22146 = PC + 1;
	cppVar_22146 = (cppVar_22146 & cppMask_un_16_);
	cppVar_22147 = ROM.rd(cppVar_22146);
	cppVar_22148 = (cppVar_22147 >> 7) & cppMask_un_1_;
	cppVar_22149 = (cppVar_22148 == 1);
	if (cppVar_22149) {
	cppVar_22150 = PC + 1;
	cppVar_22150 = (cppVar_22150 & cppMask_un_16_);
	cppVar_22151 = ROM.rd(cppVar_22150);
	cppVar_22152 = (cppVar_22151 >> 3) & cppMask_un_5_;
	cppVar_22153 = (cppVar_22152 << 3) | 0;
	cppVar_22153 = (cppVar_22153 & cppMask_un_8_);
	cppVar_22145 = cppVar_22153;
	} else {
	cppVar_22154 = PC + 1;
	cppVar_22154 = (cppVar_22154 & cppMask_un_16_);
	cppVar_22155 = ROM.rd(cppVar_22154);
	cppVar_22156 = (cppVar_22155 >> 3) & cppMask_un_5_;
	cppVar_22157 = (cppVar_22156 & cppMask_un_5_);
	cppVar_22158 = cppVar_22157 + 32;
	cppVar_22158 = (cppVar_22158 & cppMask_un_8_);
	cppVar_22145 = cppVar_22158;
	}
	cppVar_22160 = (cppVar_22145 == 137);
	if (cppVar_22160) {
	cppVar_22144 = TMOD;
	} else {
	cppVar_22163 = PC + 1;
	cppVar_22163 = (cppVar_22163 & cppMask_un_16_);
	cppVar_22164 = ROM.rd(cppVar_22163);
	cppVar_22165 = (cppVar_22164 >> 7) & cppMask_un_1_;
	cppVar_22166 = (cppVar_22165 == 1);
	if (cppVar_22166) {
	cppVar_22167 = PC + 1;
	cppVar_22167 = (cppVar_22167 & cppMask_un_16_);
	cppVar_22168 = ROM.rd(cppVar_22167);
	cppVar_22169 = (cppVar_22168 >> 3) & cppMask_un_5_;
	cppVar_22170 = (cppVar_22169 << 3) | 0;
	cppVar_22170 = (cppVar_22170 & cppMask_un_8_);
	cppVar_22162 = cppVar_22170;
	} else {
	cppVar_22171 = PC + 1;
	cppVar_22171 = (cppVar_22171 & cppMask_un_16_);
	cppVar_22172 = ROM.rd(cppVar_22171);
	cppVar_22173 = (cppVar_22172 >> 3) & cppMask_un_5_;
	cppVar_22174 = (cppVar_22173 & cppMask_un_5_);
	cppVar_22175 = cppVar_22174 + 32;
	cppVar_22175 = (cppVar_22175 & cppMask_un_8_);
	cppVar_22162 = cppVar_22175;
	}
	cppVar_22177 = (cppVar_22162 == 138);
	if (cppVar_22177) {
	cppVar_22161 = TL0;
	} else {
	cppVar_22180 = PC + 1;
	cppVar_22180 = (cppVar_22180 & cppMask_un_16_);
	cppVar_22181 = ROM.rd(cppVar_22180);
	cppVar_22182 = (cppVar_22181 >> 7) & cppMask_un_1_;
	cppVar_22183 = (cppVar_22182 == 1);
	if (cppVar_22183) {
	cppVar_22184 = PC + 1;
	cppVar_22184 = (cppVar_22184 & cppMask_un_16_);
	cppVar_22185 = ROM.rd(cppVar_22184);
	cppVar_22186 = (cppVar_22185 >> 3) & cppMask_un_5_;
	cppVar_22187 = (cppVar_22186 << 3) | 0;
	cppVar_22187 = (cppVar_22187 & cppMask_un_8_);
	cppVar_22179 = cppVar_22187;
	} else {
	cppVar_22188 = PC + 1;
	cppVar_22188 = (cppVar_22188 & cppMask_un_16_);
	cppVar_22189 = ROM.rd(cppVar_22188);
	cppVar_22190 = (cppVar_22189 >> 3) & cppMask_un_5_;
	cppVar_22191 = (cppVar_22190 & cppMask_un_5_);
	cppVar_22192 = cppVar_22191 + 32;
	cppVar_22192 = (cppVar_22192 & cppMask_un_8_);
	cppVar_22179 = cppVar_22192;
	}
	cppVar_22194 = (cppVar_22179 == 140);
	if (cppVar_22194) {
	cppVar_22178 = TH0;
	} else {
	cppVar_22197 = PC + 1;
	cppVar_22197 = (cppVar_22197 & cppMask_un_16_);
	cppVar_22198 = ROM.rd(cppVar_22197);
	cppVar_22199 = (cppVar_22198 >> 7) & cppMask_un_1_;
	cppVar_22200 = (cppVar_22199 == 1);
	if (cppVar_22200) {
	cppVar_22201 = PC + 1;
	cppVar_22201 = (cppVar_22201 & cppMask_un_16_);
	cppVar_22202 = ROM.rd(cppVar_22201);
	cppVar_22203 = (cppVar_22202 >> 3) & cppMask_un_5_;
	cppVar_22204 = (cppVar_22203 << 3) | 0;
	cppVar_22204 = (cppVar_22204 & cppMask_un_8_);
	cppVar_22196 = cppVar_22204;
	} else {
	cppVar_22205 = PC + 1;
	cppVar_22205 = (cppVar_22205 & cppMask_un_16_);
	cppVar_22206 = ROM.rd(cppVar_22205);
	cppVar_22207 = (cppVar_22206 >> 3) & cppMask_un_5_;
	cppVar_22208 = (cppVar_22207 & cppMask_un_5_);
	cppVar_22209 = cppVar_22208 + 32;
	cppVar_22209 = (cppVar_22209 & cppMask_un_8_);
	cppVar_22196 = cppVar_22209;
	}
	cppVar_22211 = (cppVar_22196 == 139);
	if (cppVar_22211) {
	cppVar_22195 = TL1;
	} else {
	cppVar_22214 = PC + 1;
	cppVar_22214 = (cppVar_22214 & cppMask_un_16_);
	cppVar_22215 = ROM.rd(cppVar_22214);
	cppVar_22216 = (cppVar_22215 >> 7) & cppMask_un_1_;
	cppVar_22217 = (cppVar_22216 == 1);
	if (cppVar_22217) {
	cppVar_22218 = PC + 1;
	cppVar_22218 = (cppVar_22218 & cppMask_un_16_);
	cppVar_22219 = ROM.rd(cppVar_22218);
	cppVar_22220 = (cppVar_22219 >> 3) & cppMask_un_5_;
	cppVar_22221 = (cppVar_22220 << 3) | 0;
	cppVar_22221 = (cppVar_22221 & cppMask_un_8_);
	cppVar_22213 = cppVar_22221;
	} else {
	cppVar_22222 = PC + 1;
	cppVar_22222 = (cppVar_22222 & cppMask_un_16_);
	cppVar_22223 = ROM.rd(cppVar_22222);
	cppVar_22224 = (cppVar_22223 >> 3) & cppMask_un_5_;
	cppVar_22225 = (cppVar_22224 & cppMask_un_5_);
	cppVar_22226 = cppVar_22225 + 32;
	cppVar_22226 = (cppVar_22226 & cppMask_un_8_);
	cppVar_22213 = cppVar_22226;
	}
	cppVar_22228 = (cppVar_22213 == 141);
	if (cppVar_22228) {
	cppVar_22212 = TH1;
	} else {
	cppVar_22231 = PC + 1;
	cppVar_22231 = (cppVar_22231 & cppMask_un_16_);
	cppVar_22232 = ROM.rd(cppVar_22231);
	cppVar_22233 = (cppVar_22232 >> 7) & cppMask_un_1_;
	cppVar_22234 = (cppVar_22233 == 1);
	if (cppVar_22234) {
	cppVar_22235 = PC + 1;
	cppVar_22235 = (cppVar_22235 & cppMask_un_16_);
	cppVar_22236 = ROM.rd(cppVar_22235);
	cppVar_22237 = (cppVar_22236 >> 3) & cppMask_un_5_;
	cppVar_22238 = (cppVar_22237 << 3) | 0;
	cppVar_22238 = (cppVar_22238 & cppMask_un_8_);
	cppVar_22230 = cppVar_22238;
	} else {
	cppVar_22239 = PC + 1;
	cppVar_22239 = (cppVar_22239 & cppMask_un_16_);
	cppVar_22240 = ROM.rd(cppVar_22239);
	cppVar_22241 = (cppVar_22240 >> 3) & cppMask_un_5_;
	cppVar_22242 = (cppVar_22241 & cppMask_un_5_);
	cppVar_22243 = cppVar_22242 + 32;
	cppVar_22243 = (cppVar_22243 & cppMask_un_8_);
	cppVar_22230 = cppVar_22243;
	}
	cppVar_22245 = (cppVar_22230 == 144);
	if (cppVar_22245) {
	cppVar_22229 = P1;
	} else {
	cppVar_22248 = PC + 1;
	cppVar_22248 = (cppVar_22248 & cppMask_un_16_);
	cppVar_22249 = ROM.rd(cppVar_22248);
	cppVar_22250 = (cppVar_22249 >> 7) & cppMask_un_1_;
	cppVar_22251 = (cppVar_22250 == 1);
	if (cppVar_22251) {
	cppVar_22252 = PC + 1;
	cppVar_22252 = (cppVar_22252 & cppMask_un_16_);
	cppVar_22253 = ROM.rd(cppVar_22252);
	cppVar_22254 = (cppVar_22253 >> 3) & cppMask_un_5_;
	cppVar_22255 = (cppVar_22254 << 3) | 0;
	cppVar_22255 = (cppVar_22255 & cppMask_un_8_);
	cppVar_22247 = cppVar_22255;
	} else {
	cppVar_22256 = PC + 1;
	cppVar_22256 = (cppVar_22256 & cppMask_un_16_);
	cppVar_22257 = ROM.rd(cppVar_22256);
	cppVar_22258 = (cppVar_22257 >> 3) & cppMask_un_5_;
	cppVar_22259 = (cppVar_22258 & cppMask_un_5_);
	cppVar_22260 = cppVar_22259 + 32;
	cppVar_22260 = (cppVar_22260 & cppMask_un_8_);
	cppVar_22247 = cppVar_22260;
	}
	cppVar_22262 = (cppVar_22247 == 152);
	if (cppVar_22262) {
	cppVar_22246 = SCON;
	} else {
	cppVar_22265 = PC + 1;
	cppVar_22265 = (cppVar_22265 & cppMask_un_16_);
	cppVar_22266 = ROM.rd(cppVar_22265);
	cppVar_22267 = (cppVar_22266 >> 7) & cppMask_un_1_;
	cppVar_22268 = (cppVar_22267 == 1);
	if (cppVar_22268) {
	cppVar_22269 = PC + 1;
	cppVar_22269 = (cppVar_22269 & cppMask_un_16_);
	cppVar_22270 = ROM.rd(cppVar_22269);
	cppVar_22271 = (cppVar_22270 >> 3) & cppMask_un_5_;
	cppVar_22272 = (cppVar_22271 << 3) | 0;
	cppVar_22272 = (cppVar_22272 & cppMask_un_8_);
	cppVar_22264 = cppVar_22272;
	} else {
	cppVar_22273 = PC + 1;
	cppVar_22273 = (cppVar_22273 & cppMask_un_16_);
	cppVar_22274 = ROM.rd(cppVar_22273);
	cppVar_22275 = (cppVar_22274 >> 3) & cppMask_un_5_;
	cppVar_22276 = (cppVar_22275 & cppMask_un_5_);
	cppVar_22277 = cppVar_22276 + 32;
	cppVar_22277 = (cppVar_22277 & cppMask_un_8_);
	cppVar_22264 = cppVar_22277;
	}
	cppVar_22279 = (cppVar_22264 == 153);
	if (cppVar_22279) {
	cppVar_22263 = SBUF;
	} else {
	cppVar_22282 = PC + 1;
	cppVar_22282 = (cppVar_22282 & cppMask_un_16_);
	cppVar_22283 = ROM.rd(cppVar_22282);
	cppVar_22284 = (cppVar_22283 >> 7) & cppMask_un_1_;
	cppVar_22285 = (cppVar_22284 == 1);
	if (cppVar_22285) {
	cppVar_22286 = PC + 1;
	cppVar_22286 = (cppVar_22286 & cppMask_un_16_);
	cppVar_22287 = ROM.rd(cppVar_22286);
	cppVar_22288 = (cppVar_22287 >> 3) & cppMask_un_5_;
	cppVar_22289 = (cppVar_22288 << 3) | 0;
	cppVar_22289 = (cppVar_22289 & cppMask_un_8_);
	cppVar_22281 = cppVar_22289;
	} else {
	cppVar_22290 = PC + 1;
	cppVar_22290 = (cppVar_22290 & cppMask_un_16_);
	cppVar_22291 = ROM.rd(cppVar_22290);
	cppVar_22292 = (cppVar_22291 >> 3) & cppMask_un_5_;
	cppVar_22293 = (cppVar_22292 & cppMask_un_5_);
	cppVar_22294 = cppVar_22293 + 32;
	cppVar_22294 = (cppVar_22294 & cppMask_un_8_);
	cppVar_22281 = cppVar_22294;
	}
	cppVar_22296 = (cppVar_22281 == 160);
	if (cppVar_22296) {
	cppVar_22280 = P2;
	} else {
	cppVar_22299 = PC + 1;
	cppVar_22299 = (cppVar_22299 & cppMask_un_16_);
	cppVar_22300 = ROM.rd(cppVar_22299);
	cppVar_22301 = (cppVar_22300 >> 7) & cppMask_un_1_;
	cppVar_22302 = (cppVar_22301 == 1);
	if (cppVar_22302) {
	cppVar_22303 = PC + 1;
	cppVar_22303 = (cppVar_22303 & cppMask_un_16_);
	cppVar_22304 = ROM.rd(cppVar_22303);
	cppVar_22305 = (cppVar_22304 >> 3) & cppMask_un_5_;
	cppVar_22306 = (cppVar_22305 << 3) | 0;
	cppVar_22306 = (cppVar_22306 & cppMask_un_8_);
	cppVar_22298 = cppVar_22306;
	} else {
	cppVar_22307 = PC + 1;
	cppVar_22307 = (cppVar_22307 & cppMask_un_16_);
	cppVar_22308 = ROM.rd(cppVar_22307);
	cppVar_22309 = (cppVar_22308 >> 3) & cppMask_un_5_;
	cppVar_22310 = (cppVar_22309 & cppMask_un_5_);
	cppVar_22311 = cppVar_22310 + 32;
	cppVar_22311 = (cppVar_22311 & cppMask_un_8_);
	cppVar_22298 = cppVar_22311;
	}
	cppVar_22313 = (cppVar_22298 == 168);
	if (cppVar_22313) {
	cppVar_22297 = IE;
	} else {
	cppVar_22316 = PC + 1;
	cppVar_22316 = (cppVar_22316 & cppMask_un_16_);
	cppVar_22317 = ROM.rd(cppVar_22316);
	cppVar_22318 = (cppVar_22317 >> 7) & cppMask_un_1_;
	cppVar_22319 = (cppVar_22318 == 1);
	if (cppVar_22319) {
	cppVar_22320 = PC + 1;
	cppVar_22320 = (cppVar_22320 & cppMask_un_16_);
	cppVar_22321 = ROM.rd(cppVar_22320);
	cppVar_22322 = (cppVar_22321 >> 3) & cppMask_un_5_;
	cppVar_22323 = (cppVar_22322 << 3) | 0;
	cppVar_22323 = (cppVar_22323 & cppMask_un_8_);
	cppVar_22315 = cppVar_22323;
	} else {
	cppVar_22324 = PC + 1;
	cppVar_22324 = (cppVar_22324 & cppMask_un_16_);
	cppVar_22325 = ROM.rd(cppVar_22324);
	cppVar_22326 = (cppVar_22325 >> 3) & cppMask_un_5_;
	cppVar_22327 = (cppVar_22326 & cppMask_un_5_);
	cppVar_22328 = cppVar_22327 + 32;
	cppVar_22328 = (cppVar_22328 & cppMask_un_8_);
	cppVar_22315 = cppVar_22328;
	}
	cppVar_22330 = (cppVar_22315 == 176);
	if (cppVar_22330) {
	cppVar_22314 = P3;
	} else {
	cppVar_22333 = PC + 1;
	cppVar_22333 = (cppVar_22333 & cppMask_un_16_);
	cppVar_22334 = ROM.rd(cppVar_22333);
	cppVar_22335 = (cppVar_22334 >> 7) & cppMask_un_1_;
	cppVar_22336 = (cppVar_22335 == 1);
	if (cppVar_22336) {
	cppVar_22337 = PC + 1;
	cppVar_22337 = (cppVar_22337 & cppMask_un_16_);
	cppVar_22338 = ROM.rd(cppVar_22337);
	cppVar_22339 = (cppVar_22338 >> 3) & cppMask_un_5_;
	cppVar_22340 = (cppVar_22339 << 3) | 0;
	cppVar_22340 = (cppVar_22340 & cppMask_un_8_);
	cppVar_22332 = cppVar_22340;
	} else {
	cppVar_22341 = PC + 1;
	cppVar_22341 = (cppVar_22341 & cppMask_un_16_);
	cppVar_22342 = ROM.rd(cppVar_22341);
	cppVar_22343 = (cppVar_22342 >> 3) & cppMask_un_5_;
	cppVar_22344 = (cppVar_22343 & cppMask_un_5_);
	cppVar_22345 = cppVar_22344 + 32;
	cppVar_22345 = (cppVar_22345 & cppMask_un_8_);
	cppVar_22332 = cppVar_22345;
	}
	cppVar_22347 = (cppVar_22332 == 184);
	if (cppVar_22347) {
	cppVar_22331 = IP;
	} else {
	cppVar_22350 = PC + 1;
	cppVar_22350 = (cppVar_22350 & cppMask_un_16_);
	cppVar_22351 = ROM.rd(cppVar_22350);
	cppVar_22352 = (cppVar_22351 >> 7) & cppMask_un_1_;
	cppVar_22353 = (cppVar_22352 == 1);
	if (cppVar_22353) {
	cppVar_22354 = PC + 1;
	cppVar_22354 = (cppVar_22354 & cppMask_un_16_);
	cppVar_22355 = ROM.rd(cppVar_22354);
	cppVar_22356 = (cppVar_22355 >> 3) & cppMask_un_5_;
	cppVar_22357 = (cppVar_22356 << 3) | 0;
	cppVar_22357 = (cppVar_22357 & cppMask_un_8_);
	cppVar_22349 = cppVar_22357;
	} else {
	cppVar_22358 = PC + 1;
	cppVar_22358 = (cppVar_22358 & cppMask_un_16_);
	cppVar_22359 = ROM.rd(cppVar_22358);
	cppVar_22360 = (cppVar_22359 >> 3) & cppMask_un_5_;
	cppVar_22361 = (cppVar_22360 & cppMask_un_5_);
	cppVar_22362 = cppVar_22361 + 32;
	cppVar_22362 = (cppVar_22362 & cppMask_un_8_);
	cppVar_22349 = cppVar_22362;
	}
	cppVar_22364 = (cppVar_22349 == 208);
	if (cppVar_22364) {
	cppVar_22348 = PSW;
	} else {
	cppVar_22367 = PC + 1;
	cppVar_22367 = (cppVar_22367 & cppMask_un_16_);
	cppVar_22368 = ROM.rd(cppVar_22367);
	cppVar_22369 = (cppVar_22368 >> 7) & cppMask_un_1_;
	cppVar_22370 = (cppVar_22369 == 1);
	if (cppVar_22370) {
	cppVar_22371 = PC + 1;
	cppVar_22371 = (cppVar_22371 & cppMask_un_16_);
	cppVar_22372 = ROM.rd(cppVar_22371);
	cppVar_22373 = (cppVar_22372 >> 3) & cppMask_un_5_;
	cppVar_22374 = (cppVar_22373 << 3) | 0;
	cppVar_22374 = (cppVar_22374 & cppMask_un_8_);
	cppVar_22366 = cppVar_22374;
	} else {
	cppVar_22375 = PC + 1;
	cppVar_22375 = (cppVar_22375 & cppMask_un_16_);
	cppVar_22376 = ROM.rd(cppVar_22375);
	cppVar_22377 = (cppVar_22376 >> 3) & cppMask_un_5_;
	cppVar_22378 = (cppVar_22377 & cppMask_un_5_);
	cppVar_22379 = cppVar_22378 + 32;
	cppVar_22379 = (cppVar_22379 & cppMask_un_8_);
	cppVar_22366 = cppVar_22379;
	}
	cppVar_22381 = (cppVar_22366 == 224);
	if (cppVar_22381) {
	cppVar_22365 = ACC;
	} else {
	cppVar_22384 = PC + 1;
	cppVar_22384 = (cppVar_22384 & cppMask_un_16_);
	cppVar_22385 = ROM.rd(cppVar_22384);
	cppVar_22386 = (cppVar_22385 >> 7) & cppMask_un_1_;
	cppVar_22387 = (cppVar_22386 == 1);
	if (cppVar_22387) {
	cppVar_22388 = PC + 1;
	cppVar_22388 = (cppVar_22388 & cppMask_un_16_);
	cppVar_22389 = ROM.rd(cppVar_22388);
	cppVar_22390 = (cppVar_22389 >> 3) & cppMask_un_5_;
	cppVar_22391 = (cppVar_22390 << 3) | 0;
	cppVar_22391 = (cppVar_22391 & cppMask_un_8_);
	cppVar_22383 = cppVar_22391;
	} else {
	cppVar_22392 = PC + 1;
	cppVar_22392 = (cppVar_22392 & cppMask_un_16_);
	cppVar_22393 = ROM.rd(cppVar_22392);
	cppVar_22394 = (cppVar_22393 >> 3) & cppMask_un_5_;
	cppVar_22395 = (cppVar_22394 & cppMask_un_5_);
	cppVar_22396 = cppVar_22395 + 32;
	cppVar_22396 = (cppVar_22396 & cppMask_un_8_);
	cppVar_22383 = cppVar_22396;
	}
	cppVar_22398 = (cppVar_22383 == 240);
	if (cppVar_22398) {
	cppVar_22382 = B;
	} else {
	cppVar_22382 = 0;
	}
	cppVar_22365 = cppVar_22382;
	}
	cppVar_22348 = cppVar_22365;
	}
	cppVar_22331 = cppVar_22348;
	}
	cppVar_22314 = cppVar_22331;
	}
	cppVar_22297 = cppVar_22314;
	}
	cppVar_22280 = cppVar_22297;
	}
	cppVar_22263 = cppVar_22280;
	}
	cppVar_22246 = cppVar_22263;
	}
	cppVar_22229 = cppVar_22246;
	}
	cppVar_22212 = cppVar_22229;
	}
	cppVar_22195 = cppVar_22212;
	}
	cppVar_22178 = cppVar_22195;
	}
	cppVar_22161 = cppVar_22178;
	}
	cppVar_22144 = cppVar_22161;
	}
	cppVar_22127 = cppVar_22144;
	}
	cppVar_22110 = cppVar_22127;
	}
	cppVar_22093 = cppVar_22110;
	}
	cppVar_22076 = cppVar_22093;
	}
	cppVar_22059 = cppVar_22076;
	}
	cppVar_22042 = cppVar_22059;
	}
	cppVar_22009 = cppVar_22042;
	}
	cppVar_22400 = cppVar_22008 & cppVar_22009;
	cppVar_22402 = 0;
	cppVar_22403 = PC + 1;
	cppVar_22403 = (cppVar_22403 & cppMask_un_16_);
	cppVar_22404 = ROM.rd(cppVar_22403);
	cppVar_22405 = (cppVar_22404 >> 0) & cppMask_un_3_;
	cppVar_22406 = (cppVar_22405 & cppMask_un_3_);
	cppVar_22407 = cppVar_22402 << static_cast<unsigned>(cppVar_22406);
	cppVar_22407 = (cppVar_22407 & cppMask_un_8_);
	cppVar_22408 = cppVar_22400 | cppVar_22407;
	cppVar_21981 = cppVar_22408;
	} else {
	cppVar_21981 = IP;
	}
	cppVar_21973 = cppVar_21981;
	} else {
	cppVar_22410 = ROM.rd(PC);
	cppVar_22412 = (cppVar_22410 == 5);
	if (cppVar_22412) {
	cppVar_22415 = PC + 1;
	cppVar_22415 = (cppVar_22415 & cppMask_un_16_);
	cppVar_22416 = ROM.rd(cppVar_22415);
	cppVar_22418 = (cppVar_22416 == 184);
	if (cppVar_22418) {
	cppVar_22420 = PC + 1;
	cppVar_22420 = (cppVar_22420 & cppMask_un_16_);
	cppVar_22421 = ROM.rd(cppVar_22420);
	cppVar_22422 = (cppVar_22421 >> 7) & cppMask_un_1_;
	cppVar_22424 = (cppVar_22422 == 0);
	if (cppVar_22424) {
	cppVar_22425 = PC + 1;
	cppVar_22425 = (cppVar_22425 & cppMask_un_16_);
	cppVar_22426 = ROM.rd(cppVar_22425);
	cppVar_22427 = IRAM.rd(cppVar_22426);
	cppVar_22419 = cppVar_22427;
	} else {
	cppVar_22429 = PC + 1;
	cppVar_22429 = (cppVar_22429 & cppMask_un_16_);
	cppVar_22430 = ROM.rd(cppVar_22429);
	cppVar_22432 = (cppVar_22430 == 128);
	if (cppVar_22432) {
	cppVar_22428 = P0;
	} else {
	cppVar_22434 = PC + 1;
	cppVar_22434 = (cppVar_22434 & cppMask_un_16_);
	cppVar_22435 = ROM.rd(cppVar_22434);
	cppVar_22437 = (cppVar_22435 == 129);
	if (cppVar_22437) {
	cppVar_22433 = SP;
	} else {
	cppVar_22439 = PC + 1;
	cppVar_22439 = (cppVar_22439 & cppMask_un_16_);
	cppVar_22440 = ROM.rd(cppVar_22439);
	cppVar_22442 = (cppVar_22440 == 130);
	if (cppVar_22442) {
	cppVar_22438 = DPL;
	} else {
	cppVar_22444 = PC + 1;
	cppVar_22444 = (cppVar_22444 & cppMask_un_16_);
	cppVar_22445 = ROM.rd(cppVar_22444);
	cppVar_22447 = (cppVar_22445 == 131);
	if (cppVar_22447) {
	cppVar_22443 = DPH;
	} else {
	cppVar_22449 = PC + 1;
	cppVar_22449 = (cppVar_22449 & cppMask_un_16_);
	cppVar_22450 = ROM.rd(cppVar_22449);
	cppVar_22452 = (cppVar_22450 == 135);
	if (cppVar_22452) {
	cppVar_22448 = PCON;
	} else {
	cppVar_22454 = PC + 1;
	cppVar_22454 = (cppVar_22454 & cppMask_un_16_);
	cppVar_22455 = ROM.rd(cppVar_22454);
	cppVar_22457 = (cppVar_22455 == 136);
	if (cppVar_22457) {
	cppVar_22453 = TCON;
	} else {
	cppVar_22459 = PC + 1;
	cppVar_22459 = (cppVar_22459 & cppMask_un_16_);
	cppVar_22460 = ROM.rd(cppVar_22459);
	cppVar_22462 = (cppVar_22460 == 137);
	if (cppVar_22462) {
	cppVar_22458 = TMOD;
	} else {
	cppVar_22464 = PC + 1;
	cppVar_22464 = (cppVar_22464 & cppMask_un_16_);
	cppVar_22465 = ROM.rd(cppVar_22464);
	cppVar_22467 = (cppVar_22465 == 138);
	if (cppVar_22467) {
	cppVar_22463 = TL0;
	} else {
	cppVar_22469 = PC + 1;
	cppVar_22469 = (cppVar_22469 & cppMask_un_16_);
	cppVar_22470 = ROM.rd(cppVar_22469);
	cppVar_22472 = (cppVar_22470 == 140);
	if (cppVar_22472) {
	cppVar_22468 = TH0;
	} else {
	cppVar_22474 = PC + 1;
	cppVar_22474 = (cppVar_22474 & cppMask_un_16_);
	cppVar_22475 = ROM.rd(cppVar_22474);
	cppVar_22477 = (cppVar_22475 == 139);
	if (cppVar_22477) {
	cppVar_22473 = TL1;
	} else {
	cppVar_22479 = PC + 1;
	cppVar_22479 = (cppVar_22479 & cppMask_un_16_);
	cppVar_22480 = ROM.rd(cppVar_22479);
	cppVar_22482 = (cppVar_22480 == 141);
	if (cppVar_22482) {
	cppVar_22478 = TH1;
	} else {
	cppVar_22484 = PC + 1;
	cppVar_22484 = (cppVar_22484 & cppMask_un_16_);
	cppVar_22485 = ROM.rd(cppVar_22484);
	cppVar_22487 = (cppVar_22485 == 144);
	if (cppVar_22487) {
	cppVar_22483 = P1;
	} else {
	cppVar_22489 = PC + 1;
	cppVar_22489 = (cppVar_22489 & cppMask_un_16_);
	cppVar_22490 = ROM.rd(cppVar_22489);
	cppVar_22492 = (cppVar_22490 == 152);
	if (cppVar_22492) {
	cppVar_22488 = SCON;
	} else {
	cppVar_22494 = PC + 1;
	cppVar_22494 = (cppVar_22494 & cppMask_un_16_);
	cppVar_22495 = ROM.rd(cppVar_22494);
	cppVar_22497 = (cppVar_22495 == 153);
	if (cppVar_22497) {
	cppVar_22493 = SBUF;
	} else {
	cppVar_22499 = PC + 1;
	cppVar_22499 = (cppVar_22499 & cppMask_un_16_);
	cppVar_22500 = ROM.rd(cppVar_22499);
	cppVar_22502 = (cppVar_22500 == 160);
	if (cppVar_22502) {
	cppVar_22498 = P2;
	} else {
	cppVar_22504 = PC + 1;
	cppVar_22504 = (cppVar_22504 & cppMask_un_16_);
	cppVar_22505 = ROM.rd(cppVar_22504);
	cppVar_22507 = (cppVar_22505 == 168);
	if (cppVar_22507) {
	cppVar_22503 = IE;
	} else {
	cppVar_22509 = PC + 1;
	cppVar_22509 = (cppVar_22509 & cppMask_un_16_);
	cppVar_22510 = ROM.rd(cppVar_22509);
	cppVar_22512 = (cppVar_22510 == 176);
	if (cppVar_22512) {
	cppVar_22508 = P3;
	} else {
	cppVar_22514 = PC + 1;
	cppVar_22514 = (cppVar_22514 & cppMask_un_16_);
	cppVar_22515 = ROM.rd(cppVar_22514);
	cppVar_22517 = (cppVar_22515 == 184);
	if (cppVar_22517) {
	cppVar_22513 = IP;
	} else {
	cppVar_22519 = PC + 1;
	cppVar_22519 = (cppVar_22519 & cppMask_un_16_);
	cppVar_22520 = ROM.rd(cppVar_22519);
	cppVar_22522 = (cppVar_22520 == 208);
	if (cppVar_22522) {
	cppVar_22518 = PSW;
	} else {
	cppVar_22524 = PC + 1;
	cppVar_22524 = (cppVar_22524 & cppMask_un_16_);
	cppVar_22525 = ROM.rd(cppVar_22524);
	cppVar_22527 = (cppVar_22525 == 224);
	if (cppVar_22527) {
	cppVar_22523 = ACC;
	} else {
	cppVar_22529 = PC + 1;
	cppVar_22529 = (cppVar_22529 & cppMask_un_16_);
	cppVar_22530 = ROM.rd(cppVar_22529);
	cppVar_22532 = (cppVar_22530 == 240);
	if (cppVar_22532) {
	cppVar_22528 = B;
	} else {
	cppVar_22528 = 0;
	}
	cppVar_22523 = cppVar_22528;
	}
	cppVar_22518 = cppVar_22523;
	}
	cppVar_22513 = cppVar_22518;
	}
	cppVar_22508 = cppVar_22513;
	}
	cppVar_22503 = cppVar_22508;
	}
	cppVar_22498 = cppVar_22503;
	}
	cppVar_22493 = cppVar_22498;
	}
	cppVar_22488 = cppVar_22493;
	}
	cppVar_22483 = cppVar_22488;
	}
	cppVar_22478 = cppVar_22483;
	}
	cppVar_22473 = cppVar_22478;
	}
	cppVar_22468 = cppVar_22473;
	}
	cppVar_22463 = cppVar_22468;
	}
	cppVar_22458 = cppVar_22463;
	}
	cppVar_22453 = cppVar_22458;
	}
	cppVar_22448 = cppVar_22453;
	}
	cppVar_22443 = cppVar_22448;
	}
	cppVar_22438 = cppVar_22443;
	}
	cppVar_22433 = cppVar_22438;
	}
	cppVar_22428 = cppVar_22433;
	}
	cppVar_22419 = cppVar_22428;
	}
	cppVar_22535 = cppVar_22419 + 1;
	cppVar_22535 = (cppVar_22535 & cppMask_un_8_);
	cppVar_22413 = cppVar_22535;
	} else {
	cppVar_22413 = IP;
	}
	cppVar_22409 = cppVar_22413;
	} else {
	cppVar_22409 = IP;
	}
	cppVar_21973 = cppVar_22409;
	}
	cppVar_21842 = cppVar_21973;
	}
	cppVar_21716 = cppVar_21842;
	}
	cppVar_21587 = cppVar_21716;
	}
	cppVar_21461 = cppVar_21587;
	}
	cppVar_21332 = cppVar_21461;
	}
	cppVar_21206 = cppVar_21332;
	}
	cppVar_21077 = cppVar_21206;
	}
	cppVar_21064 = cppVar_21077;
	}
	cppVar_20938 = cppVar_21064;
	}
	cppVar_20921 = cppVar_20938;
	}
	cppVar_20904 = cppVar_20921;
	}
	cppVar_20754 = cppVar_20904;
	}
	cppVar_20604 = cppVar_20754;
	}
	cppVar_20454 = cppVar_20604;
	}
	cppVar_20304 = cppVar_20454;
	}
	cppVar_20154 = cppVar_20304;
	}
	cppVar_20004 = cppVar_20154;
	}
	cppVar_19854 = cppVar_20004;
	}
	cppVar_19704 = cppVar_19854;
	}
	cppVar_19272 = cppVar_19704;
	}
	cppVar_18442 = cppVar_19272;
	}
	cppVar_18428 = cppVar_18442;
	}
	cppVar_18417 = cppVar_18428;
	}
	cppVar_17985 = cppVar_18417;
	}
	return cppVar_17985;
}
