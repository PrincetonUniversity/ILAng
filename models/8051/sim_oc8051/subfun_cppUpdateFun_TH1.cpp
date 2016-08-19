#include "common.hpp"
#include "model_oc8051_class.hpp"

BIT_VEC model_oc8051::cppUpdateFun_TH1()
{
	BIT_VEC cppVar_74849;
	BIT_VEC cppVar_74850;
	bool cppVar_74851;
	BIT_VEC cppVar_74853;
	BIT_VEC cppVar_74854;
	BIT_VEC cppVar_74855;
	BIT_VEC cppVar_74856;
	bool cppVar_74857;
	BIT_VEC cppVar_74858;
	BIT_VEC cppVar_74852;
	BIT_VEC cppVar_74860;
	BIT_VEC cppVar_74861;
	bool cppVar_74862;
	BIT_VEC cppVar_74863;
	BIT_VEC cppVar_74864;
	bool cppVar_74865;
	bool cppVar_74866;
	BIT_VEC cppVar_74868;
	BIT_VEC cppVar_74869;
	BIT_VEC cppVar_74870;
	BIT_VEC cppVar_74871;
	bool cppVar_74872;
	BIT_VEC cppVar_74867;
	BIT_VEC cppVar_74874;
	BIT_VEC cppVar_74875;
	bool cppVar_74876;
	BIT_VEC cppVar_74878;
	BIT_VEC cppVar_74879;
	BIT_VEC cppVar_74880;
	BIT_VEC cppVar_74881;
	bool cppVar_74882;
	BIT_VEC cppVar_74884;
	BIT_VEC cppVar_74885;
	BIT_VEC cppVar_74886;
	BIT_VEC cppVar_74887;
	BIT_VEC cppVar_74888;
	BIT_VEC cppVar_74889;
	BIT_VEC cppVar_74890;
	bool cppVar_74891;
	BIT_VEC cppVar_74892;
	BIT_VEC cppVar_74893;
	BIT_VEC cppVar_74894;
	BIT_VEC cppVar_74895;
	BIT_VEC cppVar_74897;
	BIT_VEC cppVar_74898;
	BIT_VEC cppVar_74899;
	BIT_VEC cppVar_74900;
	bool cppVar_74901;
	BIT_VEC cppVar_74903;
	BIT_VEC cppVar_74904;
	BIT_VEC cppVar_74905;
	BIT_VEC cppVar_74906;
	bool cppVar_74907;
	BIT_VEC cppVar_74909;
	BIT_VEC cppVar_74910;
	BIT_VEC cppVar_74911;
	BIT_VEC cppVar_74912;
	bool cppVar_74913;
	BIT_VEC cppVar_74915;
	BIT_VEC cppVar_74916;
	BIT_VEC cppVar_74917;
	BIT_VEC cppVar_74918;
	bool cppVar_74919;
	BIT_VEC cppVar_74921;
	BIT_VEC cppVar_74922;
	BIT_VEC cppVar_74923;
	BIT_VEC cppVar_74924;
	bool cppVar_74925;
	BIT_VEC cppVar_74927;
	BIT_VEC cppVar_74928;
	BIT_VEC cppVar_74929;
	BIT_VEC cppVar_74930;
	bool cppVar_74931;
	BIT_VEC cppVar_74933;
	BIT_VEC cppVar_74934;
	BIT_VEC cppVar_74935;
	BIT_VEC cppVar_74936;
	bool cppVar_74937;
	BIT_VEC cppVar_74939;
	BIT_VEC cppVar_74940;
	BIT_VEC cppVar_74941;
	BIT_VEC cppVar_74942;
	bool cppVar_74943;
	BIT_VEC cppVar_74945;
	BIT_VEC cppVar_74946;
	BIT_VEC cppVar_74947;
	BIT_VEC cppVar_74948;
	bool cppVar_74949;
	BIT_VEC cppVar_74951;
	BIT_VEC cppVar_74952;
	BIT_VEC cppVar_74953;
	BIT_VEC cppVar_74954;
	bool cppVar_74955;
	BIT_VEC cppVar_74957;
	BIT_VEC cppVar_74958;
	BIT_VEC cppVar_74959;
	BIT_VEC cppVar_74960;
	bool cppVar_74961;
	BIT_VEC cppVar_74963;
	BIT_VEC cppVar_74964;
	BIT_VEC cppVar_74965;
	BIT_VEC cppVar_74966;
	bool cppVar_74967;
	BIT_VEC cppVar_74969;
	BIT_VEC cppVar_74970;
	BIT_VEC cppVar_74971;
	BIT_VEC cppVar_74972;
	bool cppVar_74973;
	BIT_VEC cppVar_74975;
	BIT_VEC cppVar_74976;
	BIT_VEC cppVar_74977;
	BIT_VEC cppVar_74978;
	bool cppVar_74979;
	BIT_VEC cppVar_74981;
	BIT_VEC cppVar_74982;
	BIT_VEC cppVar_74983;
	BIT_VEC cppVar_74984;
	bool cppVar_74985;
	BIT_VEC cppVar_74987;
	BIT_VEC cppVar_74988;
	BIT_VEC cppVar_74989;
	BIT_VEC cppVar_74990;
	bool cppVar_74991;
	BIT_VEC cppVar_74993;
	BIT_VEC cppVar_74994;
	BIT_VEC cppVar_74995;
	BIT_VEC cppVar_74996;
	bool cppVar_74997;
	BIT_VEC cppVar_74999;
	BIT_VEC cppVar_75000;
	BIT_VEC cppVar_75001;
	BIT_VEC cppVar_75002;
	bool cppVar_75003;
	BIT_VEC cppVar_75005;
	BIT_VEC cppVar_75006;
	BIT_VEC cppVar_75007;
	BIT_VEC cppVar_75008;
	bool cppVar_75009;
	BIT_VEC cppVar_75011;
	BIT_VEC cppVar_75012;
	BIT_VEC cppVar_75013;
	BIT_VEC cppVar_75014;
	bool cppVar_75015;
	BIT_VEC cppVar_75017;
	BIT_VEC cppVar_75018;
	BIT_VEC cppVar_75019;
	BIT_VEC cppVar_75020;
	bool cppVar_75021;
	BIT_VEC cppVar_75022;
	BIT_VEC cppVar_75016;
	BIT_VEC cppVar_75010;
	BIT_VEC cppVar_75004;
	BIT_VEC cppVar_74998;
	BIT_VEC cppVar_74992;
	BIT_VEC cppVar_74986;
	BIT_VEC cppVar_74980;
	BIT_VEC cppVar_74974;
	BIT_VEC cppVar_74968;
	BIT_VEC cppVar_74962;
	BIT_VEC cppVar_74956;
	BIT_VEC cppVar_74950;
	BIT_VEC cppVar_74944;
	BIT_VEC cppVar_74938;
	BIT_VEC cppVar_74932;
	BIT_VEC cppVar_74926;
	BIT_VEC cppVar_74920;
	BIT_VEC cppVar_74914;
	BIT_VEC cppVar_74908;
	BIT_VEC cppVar_74902;
	BIT_VEC cppVar_74896;
	BIT_VEC cppVar_74883;
	BIT_VEC cppVar_74877;
	BIT_VEC cppVar_75024;
	BIT_VEC cppVar_75025;
	bool cppVar_75026;
	BIT_VEC cppVar_75028;
	BIT_VEC cppVar_75029;
	BIT_VEC cppVar_75030;
	BIT_VEC cppVar_75031;
	bool cppVar_75032;
	BIT_VEC cppVar_75034;
	BIT_VEC cppVar_75035;
	BIT_VEC cppVar_75036;
	BIT_VEC cppVar_75037;
	BIT_VEC cppVar_75038;
	BIT_VEC cppVar_75039;
	BIT_VEC cppVar_75040;
	bool cppVar_75041;
	BIT_VEC cppVar_75042;
	BIT_VEC cppVar_75043;
	BIT_VEC cppVar_75044;
	BIT_VEC cppVar_75045;
	BIT_VEC cppVar_75047;
	BIT_VEC cppVar_75048;
	BIT_VEC cppVar_75049;
	BIT_VEC cppVar_75050;
	bool cppVar_75051;
	BIT_VEC cppVar_75053;
	BIT_VEC cppVar_75054;
	BIT_VEC cppVar_75055;
	BIT_VEC cppVar_75056;
	bool cppVar_75057;
	BIT_VEC cppVar_75059;
	BIT_VEC cppVar_75060;
	BIT_VEC cppVar_75061;
	BIT_VEC cppVar_75062;
	bool cppVar_75063;
	BIT_VEC cppVar_75065;
	BIT_VEC cppVar_75066;
	BIT_VEC cppVar_75067;
	BIT_VEC cppVar_75068;
	bool cppVar_75069;
	BIT_VEC cppVar_75071;
	BIT_VEC cppVar_75072;
	BIT_VEC cppVar_75073;
	BIT_VEC cppVar_75074;
	bool cppVar_75075;
	BIT_VEC cppVar_75077;
	BIT_VEC cppVar_75078;
	BIT_VEC cppVar_75079;
	BIT_VEC cppVar_75080;
	bool cppVar_75081;
	BIT_VEC cppVar_75083;
	BIT_VEC cppVar_75084;
	BIT_VEC cppVar_75085;
	BIT_VEC cppVar_75086;
	bool cppVar_75087;
	BIT_VEC cppVar_75089;
	BIT_VEC cppVar_75090;
	BIT_VEC cppVar_75091;
	BIT_VEC cppVar_75092;
	bool cppVar_75093;
	BIT_VEC cppVar_75095;
	BIT_VEC cppVar_75096;
	BIT_VEC cppVar_75097;
	BIT_VEC cppVar_75098;
	bool cppVar_75099;
	BIT_VEC cppVar_75101;
	BIT_VEC cppVar_75102;
	BIT_VEC cppVar_75103;
	BIT_VEC cppVar_75104;
	bool cppVar_75105;
	BIT_VEC cppVar_75107;
	BIT_VEC cppVar_75108;
	BIT_VEC cppVar_75109;
	BIT_VEC cppVar_75110;
	bool cppVar_75111;
	BIT_VEC cppVar_75113;
	BIT_VEC cppVar_75114;
	BIT_VEC cppVar_75115;
	BIT_VEC cppVar_75116;
	bool cppVar_75117;
	BIT_VEC cppVar_75119;
	BIT_VEC cppVar_75120;
	BIT_VEC cppVar_75121;
	BIT_VEC cppVar_75122;
	bool cppVar_75123;
	BIT_VEC cppVar_75125;
	BIT_VEC cppVar_75126;
	BIT_VEC cppVar_75127;
	BIT_VEC cppVar_75128;
	bool cppVar_75129;
	BIT_VEC cppVar_75131;
	BIT_VEC cppVar_75132;
	BIT_VEC cppVar_75133;
	BIT_VEC cppVar_75134;
	bool cppVar_75135;
	BIT_VEC cppVar_75137;
	BIT_VEC cppVar_75138;
	BIT_VEC cppVar_75139;
	BIT_VEC cppVar_75140;
	bool cppVar_75141;
	BIT_VEC cppVar_75143;
	BIT_VEC cppVar_75144;
	BIT_VEC cppVar_75145;
	BIT_VEC cppVar_75146;
	bool cppVar_75147;
	BIT_VEC cppVar_75149;
	BIT_VEC cppVar_75150;
	BIT_VEC cppVar_75151;
	BIT_VEC cppVar_75152;
	bool cppVar_75153;
	BIT_VEC cppVar_75155;
	BIT_VEC cppVar_75156;
	BIT_VEC cppVar_75157;
	BIT_VEC cppVar_75158;
	bool cppVar_75159;
	BIT_VEC cppVar_75161;
	BIT_VEC cppVar_75162;
	BIT_VEC cppVar_75163;
	BIT_VEC cppVar_75164;
	bool cppVar_75165;
	BIT_VEC cppVar_75167;
	BIT_VEC cppVar_75168;
	BIT_VEC cppVar_75169;
	BIT_VEC cppVar_75170;
	bool cppVar_75171;
	BIT_VEC cppVar_75172;
	BIT_VEC cppVar_75166;
	BIT_VEC cppVar_75160;
	BIT_VEC cppVar_75154;
	BIT_VEC cppVar_75148;
	BIT_VEC cppVar_75142;
	BIT_VEC cppVar_75136;
	BIT_VEC cppVar_75130;
	BIT_VEC cppVar_75124;
	BIT_VEC cppVar_75118;
	BIT_VEC cppVar_75112;
	BIT_VEC cppVar_75106;
	BIT_VEC cppVar_75100;
	BIT_VEC cppVar_75094;
	BIT_VEC cppVar_75088;
	BIT_VEC cppVar_75082;
	BIT_VEC cppVar_75076;
	BIT_VEC cppVar_75070;
	BIT_VEC cppVar_75064;
	BIT_VEC cppVar_75058;
	BIT_VEC cppVar_75052;
	BIT_VEC cppVar_75046;
	BIT_VEC cppVar_75033;
	BIT_VEC cppVar_75027;
	BIT_VEC cppVar_75174;
	BIT_VEC cppVar_75175;
	bool cppVar_75176;
	BIT_VEC cppVar_75178;
	BIT_VEC cppVar_75179;
	BIT_VEC cppVar_75180;
	BIT_VEC cppVar_75181;
	bool cppVar_75182;
	BIT_VEC cppVar_75184;
	BIT_VEC cppVar_75185;
	BIT_VEC cppVar_75186;
	BIT_VEC cppVar_75187;
	BIT_VEC cppVar_75188;
	BIT_VEC cppVar_75189;
	BIT_VEC cppVar_75190;
	bool cppVar_75191;
	BIT_VEC cppVar_75192;
	BIT_VEC cppVar_75193;
	BIT_VEC cppVar_75194;
	BIT_VEC cppVar_75195;
	BIT_VEC cppVar_75197;
	BIT_VEC cppVar_75198;
	BIT_VEC cppVar_75199;
	BIT_VEC cppVar_75200;
	bool cppVar_75201;
	BIT_VEC cppVar_75203;
	BIT_VEC cppVar_75204;
	BIT_VEC cppVar_75205;
	BIT_VEC cppVar_75206;
	bool cppVar_75207;
	BIT_VEC cppVar_75209;
	BIT_VEC cppVar_75210;
	BIT_VEC cppVar_75211;
	BIT_VEC cppVar_75212;
	bool cppVar_75213;
	BIT_VEC cppVar_75215;
	BIT_VEC cppVar_75216;
	BIT_VEC cppVar_75217;
	BIT_VEC cppVar_75218;
	bool cppVar_75219;
	BIT_VEC cppVar_75221;
	BIT_VEC cppVar_75222;
	BIT_VEC cppVar_75223;
	BIT_VEC cppVar_75224;
	bool cppVar_75225;
	BIT_VEC cppVar_75227;
	BIT_VEC cppVar_75228;
	BIT_VEC cppVar_75229;
	BIT_VEC cppVar_75230;
	bool cppVar_75231;
	BIT_VEC cppVar_75233;
	BIT_VEC cppVar_75234;
	BIT_VEC cppVar_75235;
	BIT_VEC cppVar_75236;
	bool cppVar_75237;
	BIT_VEC cppVar_75239;
	BIT_VEC cppVar_75240;
	BIT_VEC cppVar_75241;
	BIT_VEC cppVar_75242;
	bool cppVar_75243;
	BIT_VEC cppVar_75245;
	BIT_VEC cppVar_75246;
	BIT_VEC cppVar_75247;
	BIT_VEC cppVar_75248;
	bool cppVar_75249;
	BIT_VEC cppVar_75251;
	BIT_VEC cppVar_75252;
	BIT_VEC cppVar_75253;
	BIT_VEC cppVar_75254;
	bool cppVar_75255;
	BIT_VEC cppVar_75257;
	BIT_VEC cppVar_75258;
	BIT_VEC cppVar_75259;
	BIT_VEC cppVar_75260;
	bool cppVar_75261;
	BIT_VEC cppVar_75263;
	BIT_VEC cppVar_75264;
	BIT_VEC cppVar_75265;
	BIT_VEC cppVar_75266;
	bool cppVar_75267;
	BIT_VEC cppVar_75269;
	BIT_VEC cppVar_75270;
	BIT_VEC cppVar_75271;
	BIT_VEC cppVar_75272;
	bool cppVar_75273;
	BIT_VEC cppVar_75275;
	BIT_VEC cppVar_75276;
	BIT_VEC cppVar_75277;
	BIT_VEC cppVar_75278;
	bool cppVar_75279;
	BIT_VEC cppVar_75281;
	BIT_VEC cppVar_75282;
	BIT_VEC cppVar_75283;
	BIT_VEC cppVar_75284;
	bool cppVar_75285;
	BIT_VEC cppVar_75287;
	BIT_VEC cppVar_75288;
	BIT_VEC cppVar_75289;
	BIT_VEC cppVar_75290;
	bool cppVar_75291;
	BIT_VEC cppVar_75293;
	BIT_VEC cppVar_75294;
	BIT_VEC cppVar_75295;
	BIT_VEC cppVar_75296;
	bool cppVar_75297;
	BIT_VEC cppVar_75299;
	BIT_VEC cppVar_75300;
	BIT_VEC cppVar_75301;
	BIT_VEC cppVar_75302;
	bool cppVar_75303;
	BIT_VEC cppVar_75305;
	BIT_VEC cppVar_75306;
	BIT_VEC cppVar_75307;
	BIT_VEC cppVar_75308;
	bool cppVar_75309;
	BIT_VEC cppVar_75311;
	BIT_VEC cppVar_75312;
	BIT_VEC cppVar_75313;
	BIT_VEC cppVar_75314;
	bool cppVar_75315;
	BIT_VEC cppVar_75317;
	BIT_VEC cppVar_75318;
	BIT_VEC cppVar_75319;
	BIT_VEC cppVar_75320;
	bool cppVar_75321;
	BIT_VEC cppVar_75322;
	BIT_VEC cppVar_75316;
	BIT_VEC cppVar_75310;
	BIT_VEC cppVar_75304;
	BIT_VEC cppVar_75298;
	BIT_VEC cppVar_75292;
	BIT_VEC cppVar_75286;
	BIT_VEC cppVar_75280;
	BIT_VEC cppVar_75274;
	BIT_VEC cppVar_75268;
	BIT_VEC cppVar_75262;
	BIT_VEC cppVar_75256;
	BIT_VEC cppVar_75250;
	BIT_VEC cppVar_75244;
	BIT_VEC cppVar_75238;
	BIT_VEC cppVar_75232;
	BIT_VEC cppVar_75226;
	BIT_VEC cppVar_75220;
	BIT_VEC cppVar_75214;
	BIT_VEC cppVar_75208;
	BIT_VEC cppVar_75202;
	BIT_VEC cppVar_75196;
	BIT_VEC cppVar_75183;
	BIT_VEC cppVar_75177;
	BIT_VEC cppVar_75324;
	BIT_VEC cppVar_75325;
	bool cppVar_75326;
	BIT_VEC cppVar_75328;
	BIT_VEC cppVar_75329;
	BIT_VEC cppVar_75330;
	BIT_VEC cppVar_75331;
	bool cppVar_75332;
	BIT_VEC cppVar_75334;
	BIT_VEC cppVar_75335;
	BIT_VEC cppVar_75336;
	BIT_VEC cppVar_75337;
	BIT_VEC cppVar_75338;
	BIT_VEC cppVar_75339;
	BIT_VEC cppVar_75340;
	bool cppVar_75341;
	BIT_VEC cppVar_75342;
	BIT_VEC cppVar_75343;
	BIT_VEC cppVar_75344;
	BIT_VEC cppVar_75345;
	BIT_VEC cppVar_75347;
	BIT_VEC cppVar_75348;
	BIT_VEC cppVar_75349;
	BIT_VEC cppVar_75350;
	bool cppVar_75351;
	BIT_VEC cppVar_75353;
	BIT_VEC cppVar_75354;
	BIT_VEC cppVar_75355;
	BIT_VEC cppVar_75356;
	bool cppVar_75357;
	BIT_VEC cppVar_75359;
	BIT_VEC cppVar_75360;
	BIT_VEC cppVar_75361;
	BIT_VEC cppVar_75362;
	bool cppVar_75363;
	BIT_VEC cppVar_75365;
	BIT_VEC cppVar_75366;
	BIT_VEC cppVar_75367;
	BIT_VEC cppVar_75368;
	bool cppVar_75369;
	BIT_VEC cppVar_75371;
	BIT_VEC cppVar_75372;
	BIT_VEC cppVar_75373;
	BIT_VEC cppVar_75374;
	bool cppVar_75375;
	BIT_VEC cppVar_75377;
	BIT_VEC cppVar_75378;
	BIT_VEC cppVar_75379;
	BIT_VEC cppVar_75380;
	bool cppVar_75381;
	BIT_VEC cppVar_75383;
	BIT_VEC cppVar_75384;
	BIT_VEC cppVar_75385;
	BIT_VEC cppVar_75386;
	bool cppVar_75387;
	BIT_VEC cppVar_75389;
	BIT_VEC cppVar_75390;
	BIT_VEC cppVar_75391;
	BIT_VEC cppVar_75392;
	bool cppVar_75393;
	BIT_VEC cppVar_75395;
	BIT_VEC cppVar_75396;
	BIT_VEC cppVar_75397;
	BIT_VEC cppVar_75398;
	bool cppVar_75399;
	BIT_VEC cppVar_75401;
	BIT_VEC cppVar_75402;
	BIT_VEC cppVar_75403;
	BIT_VEC cppVar_75404;
	bool cppVar_75405;
	BIT_VEC cppVar_75407;
	BIT_VEC cppVar_75408;
	BIT_VEC cppVar_75409;
	BIT_VEC cppVar_75410;
	bool cppVar_75411;
	BIT_VEC cppVar_75413;
	BIT_VEC cppVar_75414;
	BIT_VEC cppVar_75415;
	BIT_VEC cppVar_75416;
	bool cppVar_75417;
	BIT_VEC cppVar_75419;
	BIT_VEC cppVar_75420;
	BIT_VEC cppVar_75421;
	BIT_VEC cppVar_75422;
	bool cppVar_75423;
	BIT_VEC cppVar_75425;
	BIT_VEC cppVar_75426;
	BIT_VEC cppVar_75427;
	BIT_VEC cppVar_75428;
	bool cppVar_75429;
	BIT_VEC cppVar_75431;
	BIT_VEC cppVar_75432;
	BIT_VEC cppVar_75433;
	BIT_VEC cppVar_75434;
	bool cppVar_75435;
	BIT_VEC cppVar_75437;
	BIT_VEC cppVar_75438;
	BIT_VEC cppVar_75439;
	BIT_VEC cppVar_75440;
	bool cppVar_75441;
	BIT_VEC cppVar_75443;
	BIT_VEC cppVar_75444;
	BIT_VEC cppVar_75445;
	BIT_VEC cppVar_75446;
	bool cppVar_75447;
	BIT_VEC cppVar_75449;
	BIT_VEC cppVar_75450;
	BIT_VEC cppVar_75451;
	BIT_VEC cppVar_75452;
	bool cppVar_75453;
	BIT_VEC cppVar_75455;
	BIT_VEC cppVar_75456;
	BIT_VEC cppVar_75457;
	BIT_VEC cppVar_75458;
	bool cppVar_75459;
	BIT_VEC cppVar_75461;
	BIT_VEC cppVar_75462;
	BIT_VEC cppVar_75463;
	BIT_VEC cppVar_75464;
	bool cppVar_75465;
	BIT_VEC cppVar_75467;
	BIT_VEC cppVar_75468;
	BIT_VEC cppVar_75469;
	BIT_VEC cppVar_75470;
	bool cppVar_75471;
	BIT_VEC cppVar_75472;
	BIT_VEC cppVar_75466;
	BIT_VEC cppVar_75460;
	BIT_VEC cppVar_75454;
	BIT_VEC cppVar_75448;
	BIT_VEC cppVar_75442;
	BIT_VEC cppVar_75436;
	BIT_VEC cppVar_75430;
	BIT_VEC cppVar_75424;
	BIT_VEC cppVar_75418;
	BIT_VEC cppVar_75412;
	BIT_VEC cppVar_75406;
	BIT_VEC cppVar_75400;
	BIT_VEC cppVar_75394;
	BIT_VEC cppVar_75388;
	BIT_VEC cppVar_75382;
	BIT_VEC cppVar_75376;
	BIT_VEC cppVar_75370;
	BIT_VEC cppVar_75364;
	BIT_VEC cppVar_75358;
	BIT_VEC cppVar_75352;
	BIT_VEC cppVar_75346;
	BIT_VEC cppVar_75333;
	BIT_VEC cppVar_75327;
	BIT_VEC cppVar_75474;
	BIT_VEC cppVar_75475;
	bool cppVar_75476;
	BIT_VEC cppVar_75478;
	BIT_VEC cppVar_75479;
	BIT_VEC cppVar_75480;
	BIT_VEC cppVar_75481;
	bool cppVar_75482;
	BIT_VEC cppVar_75484;
	BIT_VEC cppVar_75485;
	BIT_VEC cppVar_75486;
	BIT_VEC cppVar_75487;
	BIT_VEC cppVar_75488;
	BIT_VEC cppVar_75489;
	BIT_VEC cppVar_75490;
	bool cppVar_75491;
	BIT_VEC cppVar_75492;
	BIT_VEC cppVar_75493;
	BIT_VEC cppVar_75494;
	BIT_VEC cppVar_75495;
	BIT_VEC cppVar_75497;
	BIT_VEC cppVar_75498;
	BIT_VEC cppVar_75499;
	BIT_VEC cppVar_75500;
	bool cppVar_75501;
	BIT_VEC cppVar_75503;
	BIT_VEC cppVar_75504;
	BIT_VEC cppVar_75505;
	BIT_VEC cppVar_75506;
	bool cppVar_75507;
	BIT_VEC cppVar_75509;
	BIT_VEC cppVar_75510;
	BIT_VEC cppVar_75511;
	BIT_VEC cppVar_75512;
	bool cppVar_75513;
	BIT_VEC cppVar_75515;
	BIT_VEC cppVar_75516;
	BIT_VEC cppVar_75517;
	BIT_VEC cppVar_75518;
	bool cppVar_75519;
	BIT_VEC cppVar_75521;
	BIT_VEC cppVar_75522;
	BIT_VEC cppVar_75523;
	BIT_VEC cppVar_75524;
	bool cppVar_75525;
	BIT_VEC cppVar_75527;
	BIT_VEC cppVar_75528;
	BIT_VEC cppVar_75529;
	BIT_VEC cppVar_75530;
	bool cppVar_75531;
	BIT_VEC cppVar_75533;
	BIT_VEC cppVar_75534;
	BIT_VEC cppVar_75535;
	BIT_VEC cppVar_75536;
	bool cppVar_75537;
	BIT_VEC cppVar_75539;
	BIT_VEC cppVar_75540;
	BIT_VEC cppVar_75541;
	BIT_VEC cppVar_75542;
	bool cppVar_75543;
	BIT_VEC cppVar_75545;
	BIT_VEC cppVar_75546;
	BIT_VEC cppVar_75547;
	BIT_VEC cppVar_75548;
	bool cppVar_75549;
	BIT_VEC cppVar_75551;
	BIT_VEC cppVar_75552;
	BIT_VEC cppVar_75553;
	BIT_VEC cppVar_75554;
	bool cppVar_75555;
	BIT_VEC cppVar_75557;
	BIT_VEC cppVar_75558;
	BIT_VEC cppVar_75559;
	BIT_VEC cppVar_75560;
	bool cppVar_75561;
	BIT_VEC cppVar_75563;
	BIT_VEC cppVar_75564;
	BIT_VEC cppVar_75565;
	BIT_VEC cppVar_75566;
	bool cppVar_75567;
	BIT_VEC cppVar_75569;
	BIT_VEC cppVar_75570;
	BIT_VEC cppVar_75571;
	BIT_VEC cppVar_75572;
	bool cppVar_75573;
	BIT_VEC cppVar_75575;
	BIT_VEC cppVar_75576;
	BIT_VEC cppVar_75577;
	BIT_VEC cppVar_75578;
	bool cppVar_75579;
	BIT_VEC cppVar_75581;
	BIT_VEC cppVar_75582;
	BIT_VEC cppVar_75583;
	BIT_VEC cppVar_75584;
	bool cppVar_75585;
	BIT_VEC cppVar_75587;
	BIT_VEC cppVar_75588;
	BIT_VEC cppVar_75589;
	BIT_VEC cppVar_75590;
	bool cppVar_75591;
	BIT_VEC cppVar_75593;
	BIT_VEC cppVar_75594;
	BIT_VEC cppVar_75595;
	BIT_VEC cppVar_75596;
	bool cppVar_75597;
	BIT_VEC cppVar_75599;
	BIT_VEC cppVar_75600;
	BIT_VEC cppVar_75601;
	BIT_VEC cppVar_75602;
	bool cppVar_75603;
	BIT_VEC cppVar_75605;
	BIT_VEC cppVar_75606;
	BIT_VEC cppVar_75607;
	BIT_VEC cppVar_75608;
	bool cppVar_75609;
	BIT_VEC cppVar_75611;
	BIT_VEC cppVar_75612;
	BIT_VEC cppVar_75613;
	BIT_VEC cppVar_75614;
	bool cppVar_75615;
	BIT_VEC cppVar_75617;
	BIT_VEC cppVar_75618;
	BIT_VEC cppVar_75619;
	BIT_VEC cppVar_75620;
	bool cppVar_75621;
	BIT_VEC cppVar_75622;
	BIT_VEC cppVar_75616;
	BIT_VEC cppVar_75610;
	BIT_VEC cppVar_75604;
	BIT_VEC cppVar_75598;
	BIT_VEC cppVar_75592;
	BIT_VEC cppVar_75586;
	BIT_VEC cppVar_75580;
	BIT_VEC cppVar_75574;
	BIT_VEC cppVar_75568;
	BIT_VEC cppVar_75562;
	BIT_VEC cppVar_75556;
	BIT_VEC cppVar_75550;
	BIT_VEC cppVar_75544;
	BIT_VEC cppVar_75538;
	BIT_VEC cppVar_75532;
	BIT_VEC cppVar_75526;
	BIT_VEC cppVar_75520;
	BIT_VEC cppVar_75514;
	BIT_VEC cppVar_75508;
	BIT_VEC cppVar_75502;
	BIT_VEC cppVar_75496;
	BIT_VEC cppVar_75483;
	BIT_VEC cppVar_75477;
	BIT_VEC cppVar_75624;
	BIT_VEC cppVar_75625;
	bool cppVar_75626;
	BIT_VEC cppVar_75628;
	BIT_VEC cppVar_75629;
	BIT_VEC cppVar_75630;
	BIT_VEC cppVar_75631;
	bool cppVar_75632;
	BIT_VEC cppVar_75634;
	BIT_VEC cppVar_75635;
	BIT_VEC cppVar_75636;
	BIT_VEC cppVar_75637;
	BIT_VEC cppVar_75638;
	BIT_VEC cppVar_75639;
	BIT_VEC cppVar_75640;
	bool cppVar_75641;
	BIT_VEC cppVar_75642;
	BIT_VEC cppVar_75643;
	BIT_VEC cppVar_75644;
	BIT_VEC cppVar_75645;
	BIT_VEC cppVar_75647;
	BIT_VEC cppVar_75648;
	BIT_VEC cppVar_75649;
	BIT_VEC cppVar_75650;
	bool cppVar_75651;
	BIT_VEC cppVar_75653;
	BIT_VEC cppVar_75654;
	BIT_VEC cppVar_75655;
	BIT_VEC cppVar_75656;
	bool cppVar_75657;
	BIT_VEC cppVar_75659;
	BIT_VEC cppVar_75660;
	BIT_VEC cppVar_75661;
	BIT_VEC cppVar_75662;
	bool cppVar_75663;
	BIT_VEC cppVar_75665;
	BIT_VEC cppVar_75666;
	BIT_VEC cppVar_75667;
	BIT_VEC cppVar_75668;
	bool cppVar_75669;
	BIT_VEC cppVar_75671;
	BIT_VEC cppVar_75672;
	BIT_VEC cppVar_75673;
	BIT_VEC cppVar_75674;
	bool cppVar_75675;
	BIT_VEC cppVar_75677;
	BIT_VEC cppVar_75678;
	BIT_VEC cppVar_75679;
	BIT_VEC cppVar_75680;
	bool cppVar_75681;
	BIT_VEC cppVar_75683;
	BIT_VEC cppVar_75684;
	BIT_VEC cppVar_75685;
	BIT_VEC cppVar_75686;
	bool cppVar_75687;
	BIT_VEC cppVar_75689;
	BIT_VEC cppVar_75690;
	BIT_VEC cppVar_75691;
	BIT_VEC cppVar_75692;
	bool cppVar_75693;
	BIT_VEC cppVar_75695;
	BIT_VEC cppVar_75696;
	BIT_VEC cppVar_75697;
	BIT_VEC cppVar_75698;
	bool cppVar_75699;
	BIT_VEC cppVar_75701;
	BIT_VEC cppVar_75702;
	BIT_VEC cppVar_75703;
	BIT_VEC cppVar_75704;
	bool cppVar_75705;
	BIT_VEC cppVar_75707;
	BIT_VEC cppVar_75708;
	BIT_VEC cppVar_75709;
	BIT_VEC cppVar_75710;
	bool cppVar_75711;
	BIT_VEC cppVar_75713;
	BIT_VEC cppVar_75714;
	BIT_VEC cppVar_75715;
	BIT_VEC cppVar_75716;
	bool cppVar_75717;
	BIT_VEC cppVar_75719;
	BIT_VEC cppVar_75720;
	BIT_VEC cppVar_75721;
	BIT_VEC cppVar_75722;
	bool cppVar_75723;
	BIT_VEC cppVar_75725;
	BIT_VEC cppVar_75726;
	BIT_VEC cppVar_75727;
	BIT_VEC cppVar_75728;
	bool cppVar_75729;
	BIT_VEC cppVar_75731;
	BIT_VEC cppVar_75732;
	BIT_VEC cppVar_75733;
	BIT_VEC cppVar_75734;
	bool cppVar_75735;
	BIT_VEC cppVar_75737;
	BIT_VEC cppVar_75738;
	BIT_VEC cppVar_75739;
	BIT_VEC cppVar_75740;
	bool cppVar_75741;
	BIT_VEC cppVar_75743;
	BIT_VEC cppVar_75744;
	BIT_VEC cppVar_75745;
	BIT_VEC cppVar_75746;
	bool cppVar_75747;
	BIT_VEC cppVar_75749;
	BIT_VEC cppVar_75750;
	BIT_VEC cppVar_75751;
	BIT_VEC cppVar_75752;
	bool cppVar_75753;
	BIT_VEC cppVar_75755;
	BIT_VEC cppVar_75756;
	BIT_VEC cppVar_75757;
	BIT_VEC cppVar_75758;
	bool cppVar_75759;
	BIT_VEC cppVar_75761;
	BIT_VEC cppVar_75762;
	BIT_VEC cppVar_75763;
	BIT_VEC cppVar_75764;
	bool cppVar_75765;
	BIT_VEC cppVar_75767;
	BIT_VEC cppVar_75768;
	BIT_VEC cppVar_75769;
	BIT_VEC cppVar_75770;
	bool cppVar_75771;
	BIT_VEC cppVar_75772;
	BIT_VEC cppVar_75766;
	BIT_VEC cppVar_75760;
	BIT_VEC cppVar_75754;
	BIT_VEC cppVar_75748;
	BIT_VEC cppVar_75742;
	BIT_VEC cppVar_75736;
	BIT_VEC cppVar_75730;
	BIT_VEC cppVar_75724;
	BIT_VEC cppVar_75718;
	BIT_VEC cppVar_75712;
	BIT_VEC cppVar_75706;
	BIT_VEC cppVar_75700;
	BIT_VEC cppVar_75694;
	BIT_VEC cppVar_75688;
	BIT_VEC cppVar_75682;
	BIT_VEC cppVar_75676;
	BIT_VEC cppVar_75670;
	BIT_VEC cppVar_75664;
	BIT_VEC cppVar_75658;
	BIT_VEC cppVar_75652;
	BIT_VEC cppVar_75646;
	BIT_VEC cppVar_75633;
	BIT_VEC cppVar_75627;
	BIT_VEC cppVar_75774;
	BIT_VEC cppVar_75775;
	bool cppVar_75776;
	BIT_VEC cppVar_75778;
	BIT_VEC cppVar_75779;
	BIT_VEC cppVar_75780;
	BIT_VEC cppVar_75781;
	bool cppVar_75782;
	BIT_VEC cppVar_75784;
	BIT_VEC cppVar_75785;
	BIT_VEC cppVar_75786;
	BIT_VEC cppVar_75787;
	BIT_VEC cppVar_75788;
	BIT_VEC cppVar_75789;
	BIT_VEC cppVar_75790;
	bool cppVar_75791;
	BIT_VEC cppVar_75792;
	BIT_VEC cppVar_75793;
	BIT_VEC cppVar_75794;
	BIT_VEC cppVar_75795;
	BIT_VEC cppVar_75797;
	BIT_VEC cppVar_75798;
	BIT_VEC cppVar_75799;
	BIT_VEC cppVar_75800;
	bool cppVar_75801;
	BIT_VEC cppVar_75803;
	BIT_VEC cppVar_75804;
	BIT_VEC cppVar_75805;
	BIT_VEC cppVar_75806;
	bool cppVar_75807;
	BIT_VEC cppVar_75809;
	BIT_VEC cppVar_75810;
	BIT_VEC cppVar_75811;
	BIT_VEC cppVar_75812;
	bool cppVar_75813;
	BIT_VEC cppVar_75815;
	BIT_VEC cppVar_75816;
	BIT_VEC cppVar_75817;
	BIT_VEC cppVar_75818;
	bool cppVar_75819;
	BIT_VEC cppVar_75821;
	BIT_VEC cppVar_75822;
	BIT_VEC cppVar_75823;
	BIT_VEC cppVar_75824;
	bool cppVar_75825;
	BIT_VEC cppVar_75827;
	BIT_VEC cppVar_75828;
	BIT_VEC cppVar_75829;
	BIT_VEC cppVar_75830;
	bool cppVar_75831;
	BIT_VEC cppVar_75833;
	BIT_VEC cppVar_75834;
	BIT_VEC cppVar_75835;
	BIT_VEC cppVar_75836;
	bool cppVar_75837;
	BIT_VEC cppVar_75839;
	BIT_VEC cppVar_75840;
	BIT_VEC cppVar_75841;
	BIT_VEC cppVar_75842;
	bool cppVar_75843;
	BIT_VEC cppVar_75845;
	BIT_VEC cppVar_75846;
	BIT_VEC cppVar_75847;
	BIT_VEC cppVar_75848;
	bool cppVar_75849;
	BIT_VEC cppVar_75851;
	BIT_VEC cppVar_75852;
	BIT_VEC cppVar_75853;
	BIT_VEC cppVar_75854;
	bool cppVar_75855;
	BIT_VEC cppVar_75857;
	BIT_VEC cppVar_75858;
	BIT_VEC cppVar_75859;
	BIT_VEC cppVar_75860;
	bool cppVar_75861;
	BIT_VEC cppVar_75863;
	BIT_VEC cppVar_75864;
	BIT_VEC cppVar_75865;
	BIT_VEC cppVar_75866;
	bool cppVar_75867;
	BIT_VEC cppVar_75869;
	BIT_VEC cppVar_75870;
	BIT_VEC cppVar_75871;
	BIT_VEC cppVar_75872;
	bool cppVar_75873;
	BIT_VEC cppVar_75875;
	BIT_VEC cppVar_75876;
	BIT_VEC cppVar_75877;
	BIT_VEC cppVar_75878;
	bool cppVar_75879;
	BIT_VEC cppVar_75881;
	BIT_VEC cppVar_75882;
	BIT_VEC cppVar_75883;
	BIT_VEC cppVar_75884;
	bool cppVar_75885;
	BIT_VEC cppVar_75887;
	BIT_VEC cppVar_75888;
	BIT_VEC cppVar_75889;
	BIT_VEC cppVar_75890;
	bool cppVar_75891;
	BIT_VEC cppVar_75893;
	BIT_VEC cppVar_75894;
	BIT_VEC cppVar_75895;
	BIT_VEC cppVar_75896;
	bool cppVar_75897;
	BIT_VEC cppVar_75899;
	BIT_VEC cppVar_75900;
	BIT_VEC cppVar_75901;
	BIT_VEC cppVar_75902;
	bool cppVar_75903;
	BIT_VEC cppVar_75905;
	BIT_VEC cppVar_75906;
	BIT_VEC cppVar_75907;
	BIT_VEC cppVar_75908;
	bool cppVar_75909;
	BIT_VEC cppVar_75911;
	BIT_VEC cppVar_75912;
	BIT_VEC cppVar_75913;
	BIT_VEC cppVar_75914;
	bool cppVar_75915;
	BIT_VEC cppVar_75917;
	BIT_VEC cppVar_75918;
	BIT_VEC cppVar_75919;
	BIT_VEC cppVar_75920;
	bool cppVar_75921;
	BIT_VEC cppVar_75922;
	BIT_VEC cppVar_75916;
	BIT_VEC cppVar_75910;
	BIT_VEC cppVar_75904;
	BIT_VEC cppVar_75898;
	BIT_VEC cppVar_75892;
	BIT_VEC cppVar_75886;
	BIT_VEC cppVar_75880;
	BIT_VEC cppVar_75874;
	BIT_VEC cppVar_75868;
	BIT_VEC cppVar_75862;
	BIT_VEC cppVar_75856;
	BIT_VEC cppVar_75850;
	BIT_VEC cppVar_75844;
	BIT_VEC cppVar_75838;
	BIT_VEC cppVar_75832;
	BIT_VEC cppVar_75826;
	BIT_VEC cppVar_75820;
	BIT_VEC cppVar_75814;
	BIT_VEC cppVar_75808;
	BIT_VEC cppVar_75802;
	BIT_VEC cppVar_75796;
	BIT_VEC cppVar_75783;
	BIT_VEC cppVar_75777;
	BIT_VEC cppVar_75924;
	BIT_VEC cppVar_75925;
	bool cppVar_75926;
	BIT_VEC cppVar_75928;
	BIT_VEC cppVar_75929;
	BIT_VEC cppVar_75930;
	BIT_VEC cppVar_75931;
	bool cppVar_75932;
	BIT_VEC cppVar_75934;
	BIT_VEC cppVar_75935;
	BIT_VEC cppVar_75936;
	BIT_VEC cppVar_75937;
	BIT_VEC cppVar_75938;
	BIT_VEC cppVar_75939;
	BIT_VEC cppVar_75940;
	bool cppVar_75941;
	BIT_VEC cppVar_75942;
	BIT_VEC cppVar_75943;
	BIT_VEC cppVar_75944;
	BIT_VEC cppVar_75945;
	BIT_VEC cppVar_75947;
	BIT_VEC cppVar_75948;
	BIT_VEC cppVar_75949;
	BIT_VEC cppVar_75950;
	bool cppVar_75951;
	BIT_VEC cppVar_75953;
	BIT_VEC cppVar_75954;
	BIT_VEC cppVar_75955;
	BIT_VEC cppVar_75956;
	bool cppVar_75957;
	BIT_VEC cppVar_75959;
	BIT_VEC cppVar_75960;
	BIT_VEC cppVar_75961;
	BIT_VEC cppVar_75962;
	bool cppVar_75963;
	BIT_VEC cppVar_75965;
	BIT_VEC cppVar_75966;
	BIT_VEC cppVar_75967;
	BIT_VEC cppVar_75968;
	bool cppVar_75969;
	BIT_VEC cppVar_75971;
	BIT_VEC cppVar_75972;
	BIT_VEC cppVar_75973;
	BIT_VEC cppVar_75974;
	bool cppVar_75975;
	BIT_VEC cppVar_75977;
	BIT_VEC cppVar_75978;
	BIT_VEC cppVar_75979;
	BIT_VEC cppVar_75980;
	bool cppVar_75981;
	BIT_VEC cppVar_75983;
	BIT_VEC cppVar_75984;
	BIT_VEC cppVar_75985;
	BIT_VEC cppVar_75986;
	bool cppVar_75987;
	BIT_VEC cppVar_75989;
	BIT_VEC cppVar_75990;
	BIT_VEC cppVar_75991;
	BIT_VEC cppVar_75992;
	bool cppVar_75993;
	BIT_VEC cppVar_75995;
	BIT_VEC cppVar_75996;
	BIT_VEC cppVar_75997;
	BIT_VEC cppVar_75998;
	bool cppVar_75999;
	BIT_VEC cppVar_76001;
	BIT_VEC cppVar_76002;
	BIT_VEC cppVar_76003;
	BIT_VEC cppVar_76004;
	bool cppVar_76005;
	BIT_VEC cppVar_76007;
	BIT_VEC cppVar_76008;
	BIT_VEC cppVar_76009;
	BIT_VEC cppVar_76010;
	bool cppVar_76011;
	BIT_VEC cppVar_76013;
	BIT_VEC cppVar_76014;
	BIT_VEC cppVar_76015;
	BIT_VEC cppVar_76016;
	bool cppVar_76017;
	BIT_VEC cppVar_76019;
	BIT_VEC cppVar_76020;
	BIT_VEC cppVar_76021;
	BIT_VEC cppVar_76022;
	bool cppVar_76023;
	BIT_VEC cppVar_76025;
	BIT_VEC cppVar_76026;
	BIT_VEC cppVar_76027;
	BIT_VEC cppVar_76028;
	bool cppVar_76029;
	BIT_VEC cppVar_76031;
	BIT_VEC cppVar_76032;
	BIT_VEC cppVar_76033;
	BIT_VEC cppVar_76034;
	bool cppVar_76035;
	BIT_VEC cppVar_76037;
	BIT_VEC cppVar_76038;
	BIT_VEC cppVar_76039;
	BIT_VEC cppVar_76040;
	bool cppVar_76041;
	BIT_VEC cppVar_76043;
	BIT_VEC cppVar_76044;
	BIT_VEC cppVar_76045;
	BIT_VEC cppVar_76046;
	bool cppVar_76047;
	BIT_VEC cppVar_76049;
	BIT_VEC cppVar_76050;
	BIT_VEC cppVar_76051;
	BIT_VEC cppVar_76052;
	bool cppVar_76053;
	BIT_VEC cppVar_76055;
	BIT_VEC cppVar_76056;
	BIT_VEC cppVar_76057;
	BIT_VEC cppVar_76058;
	bool cppVar_76059;
	BIT_VEC cppVar_76061;
	BIT_VEC cppVar_76062;
	BIT_VEC cppVar_76063;
	BIT_VEC cppVar_76064;
	bool cppVar_76065;
	BIT_VEC cppVar_76067;
	BIT_VEC cppVar_76068;
	BIT_VEC cppVar_76069;
	BIT_VEC cppVar_76070;
	bool cppVar_76071;
	BIT_VEC cppVar_76072;
	BIT_VEC cppVar_76066;
	BIT_VEC cppVar_76060;
	BIT_VEC cppVar_76054;
	BIT_VEC cppVar_76048;
	BIT_VEC cppVar_76042;
	BIT_VEC cppVar_76036;
	BIT_VEC cppVar_76030;
	BIT_VEC cppVar_76024;
	BIT_VEC cppVar_76018;
	BIT_VEC cppVar_76012;
	BIT_VEC cppVar_76006;
	BIT_VEC cppVar_76000;
	BIT_VEC cppVar_75994;
	BIT_VEC cppVar_75988;
	BIT_VEC cppVar_75982;
	BIT_VEC cppVar_75976;
	BIT_VEC cppVar_75970;
	BIT_VEC cppVar_75964;
	BIT_VEC cppVar_75958;
	BIT_VEC cppVar_75952;
	BIT_VEC cppVar_75946;
	BIT_VEC cppVar_75933;
	BIT_VEC cppVar_75927;
	BIT_VEC cppVar_76074;
	BIT_VEC cppVar_76075;
	bool cppVar_76076;
	BIT_VEC cppVar_76078;
	BIT_VEC cppVar_76079;
	BIT_VEC cppVar_76080;
	BIT_VEC cppVar_76081;
	bool cppVar_76082;
	BIT_VEC cppVar_76083;
	BIT_VEC cppVar_76084;
	BIT_VEC cppVar_76085;
	BIT_VEC cppVar_76086;
	BIT_VEC cppVar_76087;
	BIT_VEC cppVar_76088;
	BIT_VEC cppVar_76089;
	BIT_VEC cppVar_76077;
	BIT_VEC cppVar_76091;
	BIT_VEC cppVar_76092;
	bool cppVar_76093;
	BIT_VEC cppVar_76095;
	BIT_VEC cppVar_76096;
	BIT_VEC cppVar_76097;
	BIT_VEC cppVar_76098;
	bool cppVar_76099;
	BIT_VEC cppVar_76100;
	BIT_VEC cppVar_76101;
	BIT_VEC cppVar_76102;
	BIT_VEC cppVar_76103;
	BIT_VEC cppVar_76104;
	BIT_VEC cppVar_76105;
	BIT_VEC cppVar_76106;
	BIT_VEC cppVar_76094;
	BIT_VEC cppVar_76108;
	BIT_VEC cppVar_76109;
	bool cppVar_76110;
	BIT_VEC cppVar_76112;
	BIT_VEC cppVar_76113;
	BIT_VEC cppVar_76114;
	BIT_VEC cppVar_76115;
	bool cppVar_76116;
	BIT_VEC cppVar_76118;
	BIT_VEC cppVar_76119;
	BIT_VEC cppVar_76120;
	BIT_VEC cppVar_76121;
	BIT_VEC cppVar_76122;
	bool cppVar_76123;
	BIT_VEC cppVar_76124;
	BIT_VEC cppVar_76125;
	BIT_VEC cppVar_76126;
	BIT_VEC cppVar_76128;
	BIT_VEC cppVar_76129;
	BIT_VEC cppVar_76130;
	bool cppVar_76131;
	BIT_VEC cppVar_76133;
	BIT_VEC cppVar_76134;
	BIT_VEC cppVar_76135;
	bool cppVar_76136;
	BIT_VEC cppVar_76138;
	BIT_VEC cppVar_76139;
	BIT_VEC cppVar_76140;
	bool cppVar_76141;
	BIT_VEC cppVar_76143;
	BIT_VEC cppVar_76144;
	BIT_VEC cppVar_76145;
	bool cppVar_76146;
	BIT_VEC cppVar_76148;
	BIT_VEC cppVar_76149;
	BIT_VEC cppVar_76150;
	bool cppVar_76151;
	BIT_VEC cppVar_76153;
	BIT_VEC cppVar_76154;
	BIT_VEC cppVar_76155;
	bool cppVar_76156;
	BIT_VEC cppVar_76158;
	BIT_VEC cppVar_76159;
	BIT_VEC cppVar_76160;
	bool cppVar_76161;
	BIT_VEC cppVar_76163;
	BIT_VEC cppVar_76164;
	BIT_VEC cppVar_76165;
	bool cppVar_76166;
	BIT_VEC cppVar_76168;
	BIT_VEC cppVar_76169;
	BIT_VEC cppVar_76170;
	bool cppVar_76171;
	BIT_VEC cppVar_76173;
	BIT_VEC cppVar_76174;
	BIT_VEC cppVar_76175;
	bool cppVar_76176;
	BIT_VEC cppVar_76178;
	BIT_VEC cppVar_76179;
	BIT_VEC cppVar_76180;
	bool cppVar_76181;
	BIT_VEC cppVar_76183;
	BIT_VEC cppVar_76184;
	BIT_VEC cppVar_76185;
	bool cppVar_76186;
	BIT_VEC cppVar_76188;
	BIT_VEC cppVar_76189;
	BIT_VEC cppVar_76190;
	bool cppVar_76191;
	BIT_VEC cppVar_76193;
	BIT_VEC cppVar_76194;
	BIT_VEC cppVar_76195;
	bool cppVar_76196;
	BIT_VEC cppVar_76198;
	BIT_VEC cppVar_76199;
	BIT_VEC cppVar_76200;
	bool cppVar_76201;
	BIT_VEC cppVar_76203;
	BIT_VEC cppVar_76204;
	BIT_VEC cppVar_76205;
	bool cppVar_76206;
	BIT_VEC cppVar_76208;
	BIT_VEC cppVar_76209;
	BIT_VEC cppVar_76210;
	bool cppVar_76211;
	BIT_VEC cppVar_76213;
	BIT_VEC cppVar_76214;
	BIT_VEC cppVar_76215;
	bool cppVar_76216;
	BIT_VEC cppVar_76218;
	BIT_VEC cppVar_76219;
	BIT_VEC cppVar_76220;
	bool cppVar_76221;
	BIT_VEC cppVar_76223;
	BIT_VEC cppVar_76224;
	BIT_VEC cppVar_76225;
	bool cppVar_76226;
	BIT_VEC cppVar_76228;
	BIT_VEC cppVar_76229;
	BIT_VEC cppVar_76230;
	bool cppVar_76231;
	BIT_VEC cppVar_76232;
	BIT_VEC cppVar_76227;
	BIT_VEC cppVar_76222;
	BIT_VEC cppVar_76217;
	BIT_VEC cppVar_76212;
	BIT_VEC cppVar_76207;
	BIT_VEC cppVar_76202;
	BIT_VEC cppVar_76197;
	BIT_VEC cppVar_76192;
	BIT_VEC cppVar_76187;
	BIT_VEC cppVar_76182;
	BIT_VEC cppVar_76177;
	BIT_VEC cppVar_76172;
	BIT_VEC cppVar_76167;
	BIT_VEC cppVar_76162;
	BIT_VEC cppVar_76157;
	BIT_VEC cppVar_76152;
	BIT_VEC cppVar_76147;
	BIT_VEC cppVar_76142;
	BIT_VEC cppVar_76137;
	BIT_VEC cppVar_76132;
	BIT_VEC cppVar_76127;
	BIT_VEC cppVar_76117;
	BIT_VEC cppVar_76111;
	BIT_VEC cppVar_76234;
	BIT_VEC cppVar_76235;
	bool cppVar_76236;
	BIT_VEC cppVar_76238;
	BIT_VEC cppVar_76239;
	BIT_VEC cppVar_76240;
	BIT_VEC cppVar_76241;
	bool cppVar_76242;
	BIT_VEC cppVar_76243;
	BIT_VEC cppVar_76244;
	BIT_VEC cppVar_76245;
	BIT_VEC cppVar_76237;
	BIT_VEC cppVar_76247;
	BIT_VEC cppVar_76248;
	bool cppVar_76249;
	BIT_VEC cppVar_76251;
	BIT_VEC cppVar_76252;
	BIT_VEC cppVar_76253;
	BIT_VEC cppVar_76254;
	bool cppVar_76255;
	BIT_VEC cppVar_76257;
	BIT_VEC cppVar_76258;
	BIT_VEC cppVar_76259;
	BIT_VEC cppVar_76260;
	bool cppVar_76261;
	BIT_VEC cppVar_76262;
	BIT_VEC cppVar_76263;
	BIT_VEC cppVar_76264;
	BIT_VEC cppVar_76266;
	BIT_VEC cppVar_76267;
	BIT_VEC cppVar_76268;
	bool cppVar_76269;
	BIT_VEC cppVar_76271;
	BIT_VEC cppVar_76272;
	BIT_VEC cppVar_76273;
	bool cppVar_76274;
	BIT_VEC cppVar_76276;
	BIT_VEC cppVar_76277;
	BIT_VEC cppVar_76278;
	bool cppVar_76279;
	BIT_VEC cppVar_76281;
	BIT_VEC cppVar_76282;
	BIT_VEC cppVar_76283;
	bool cppVar_76284;
	BIT_VEC cppVar_76286;
	BIT_VEC cppVar_76287;
	BIT_VEC cppVar_76288;
	bool cppVar_76289;
	BIT_VEC cppVar_76291;
	BIT_VEC cppVar_76292;
	BIT_VEC cppVar_76293;
	bool cppVar_76294;
	BIT_VEC cppVar_76296;
	BIT_VEC cppVar_76297;
	BIT_VEC cppVar_76298;
	bool cppVar_76299;
	BIT_VEC cppVar_76301;
	BIT_VEC cppVar_76302;
	BIT_VEC cppVar_76303;
	bool cppVar_76304;
	BIT_VEC cppVar_76306;
	BIT_VEC cppVar_76307;
	BIT_VEC cppVar_76308;
	bool cppVar_76309;
	BIT_VEC cppVar_76311;
	BIT_VEC cppVar_76312;
	BIT_VEC cppVar_76313;
	bool cppVar_76314;
	BIT_VEC cppVar_76316;
	BIT_VEC cppVar_76317;
	BIT_VEC cppVar_76318;
	bool cppVar_76319;
	BIT_VEC cppVar_76321;
	BIT_VEC cppVar_76322;
	BIT_VEC cppVar_76323;
	bool cppVar_76324;
	BIT_VEC cppVar_76326;
	BIT_VEC cppVar_76327;
	BIT_VEC cppVar_76328;
	bool cppVar_76329;
	BIT_VEC cppVar_76331;
	BIT_VEC cppVar_76332;
	BIT_VEC cppVar_76333;
	bool cppVar_76334;
	BIT_VEC cppVar_76336;
	BIT_VEC cppVar_76337;
	BIT_VEC cppVar_76338;
	bool cppVar_76339;
	BIT_VEC cppVar_76341;
	BIT_VEC cppVar_76342;
	BIT_VEC cppVar_76343;
	bool cppVar_76344;
	BIT_VEC cppVar_76346;
	BIT_VEC cppVar_76347;
	BIT_VEC cppVar_76348;
	bool cppVar_76349;
	BIT_VEC cppVar_76351;
	BIT_VEC cppVar_76352;
	BIT_VEC cppVar_76353;
	bool cppVar_76354;
	BIT_VEC cppVar_76356;
	BIT_VEC cppVar_76357;
	BIT_VEC cppVar_76358;
	bool cppVar_76359;
	BIT_VEC cppVar_76361;
	BIT_VEC cppVar_76362;
	BIT_VEC cppVar_76363;
	bool cppVar_76364;
	BIT_VEC cppVar_76366;
	BIT_VEC cppVar_76367;
	BIT_VEC cppVar_76368;
	bool cppVar_76369;
	BIT_VEC cppVar_76370;
	BIT_VEC cppVar_76365;
	BIT_VEC cppVar_76360;
	BIT_VEC cppVar_76355;
	BIT_VEC cppVar_76350;
	BIT_VEC cppVar_76345;
	BIT_VEC cppVar_76340;
	BIT_VEC cppVar_76335;
	BIT_VEC cppVar_76330;
	BIT_VEC cppVar_76325;
	BIT_VEC cppVar_76320;
	BIT_VEC cppVar_76315;
	BIT_VEC cppVar_76310;
	BIT_VEC cppVar_76305;
	BIT_VEC cppVar_76300;
	BIT_VEC cppVar_76295;
	BIT_VEC cppVar_76290;
	BIT_VEC cppVar_76285;
	BIT_VEC cppVar_76280;
	BIT_VEC cppVar_76275;
	BIT_VEC cppVar_76270;
	BIT_VEC cppVar_76265;
	BIT_VEC cppVar_76256;
	BIT_VEC cppVar_76371;
	BIT_VEC cppVar_76372;
	BIT_VEC cppVar_76373;
	BIT_VEC cppVar_76374;
	BIT_VEC cppVar_76250;
	BIT_VEC cppVar_76376;
	BIT_VEC cppVar_76377;
	bool cppVar_76378;
	BIT_VEC cppVar_76380;
	BIT_VEC cppVar_76381;
	BIT_VEC cppVar_76382;
	BIT_VEC cppVar_76383;
	bool cppVar_76384;
	BIT_VEC cppVar_76386;
	BIT_VEC cppVar_76387;
	BIT_VEC cppVar_76388;
	BIT_VEC cppVar_76389;
	bool cppVar_76390;
	BIT_VEC cppVar_76391;
	BIT_VEC cppVar_76392;
	BIT_VEC cppVar_76393;
	BIT_VEC cppVar_76395;
	BIT_VEC cppVar_76396;
	BIT_VEC cppVar_76397;
	bool cppVar_76398;
	BIT_VEC cppVar_76400;
	BIT_VEC cppVar_76401;
	BIT_VEC cppVar_76402;
	bool cppVar_76403;
	BIT_VEC cppVar_76405;
	BIT_VEC cppVar_76406;
	BIT_VEC cppVar_76407;
	bool cppVar_76408;
	BIT_VEC cppVar_76410;
	BIT_VEC cppVar_76411;
	BIT_VEC cppVar_76412;
	bool cppVar_76413;
	BIT_VEC cppVar_76415;
	BIT_VEC cppVar_76416;
	BIT_VEC cppVar_76417;
	bool cppVar_76418;
	BIT_VEC cppVar_76420;
	BIT_VEC cppVar_76421;
	BIT_VEC cppVar_76422;
	bool cppVar_76423;
	BIT_VEC cppVar_76425;
	BIT_VEC cppVar_76426;
	BIT_VEC cppVar_76427;
	bool cppVar_76428;
	BIT_VEC cppVar_76430;
	BIT_VEC cppVar_76431;
	BIT_VEC cppVar_76432;
	bool cppVar_76433;
	BIT_VEC cppVar_76435;
	BIT_VEC cppVar_76436;
	BIT_VEC cppVar_76437;
	bool cppVar_76438;
	BIT_VEC cppVar_76440;
	BIT_VEC cppVar_76441;
	BIT_VEC cppVar_76442;
	bool cppVar_76443;
	BIT_VEC cppVar_76445;
	BIT_VEC cppVar_76446;
	BIT_VEC cppVar_76447;
	bool cppVar_76448;
	BIT_VEC cppVar_76450;
	BIT_VEC cppVar_76451;
	BIT_VEC cppVar_76452;
	bool cppVar_76453;
	BIT_VEC cppVar_76455;
	BIT_VEC cppVar_76456;
	BIT_VEC cppVar_76457;
	bool cppVar_76458;
	BIT_VEC cppVar_76460;
	BIT_VEC cppVar_76461;
	BIT_VEC cppVar_76462;
	bool cppVar_76463;
	BIT_VEC cppVar_76465;
	BIT_VEC cppVar_76466;
	BIT_VEC cppVar_76467;
	bool cppVar_76468;
	BIT_VEC cppVar_76470;
	BIT_VEC cppVar_76471;
	BIT_VEC cppVar_76472;
	bool cppVar_76473;
	BIT_VEC cppVar_76475;
	BIT_VEC cppVar_76476;
	BIT_VEC cppVar_76477;
	bool cppVar_76478;
	BIT_VEC cppVar_76480;
	BIT_VEC cppVar_76481;
	BIT_VEC cppVar_76482;
	bool cppVar_76483;
	BIT_VEC cppVar_76485;
	BIT_VEC cppVar_76486;
	BIT_VEC cppVar_76487;
	bool cppVar_76488;
	BIT_VEC cppVar_76490;
	BIT_VEC cppVar_76491;
	BIT_VEC cppVar_76492;
	bool cppVar_76493;
	BIT_VEC cppVar_76495;
	BIT_VEC cppVar_76496;
	BIT_VEC cppVar_76497;
	bool cppVar_76498;
	BIT_VEC cppVar_76499;
	BIT_VEC cppVar_76494;
	BIT_VEC cppVar_76489;
	BIT_VEC cppVar_76484;
	BIT_VEC cppVar_76479;
	BIT_VEC cppVar_76474;
	BIT_VEC cppVar_76469;
	BIT_VEC cppVar_76464;
	BIT_VEC cppVar_76459;
	BIT_VEC cppVar_76454;
	BIT_VEC cppVar_76449;
	BIT_VEC cppVar_76444;
	BIT_VEC cppVar_76439;
	BIT_VEC cppVar_76434;
	BIT_VEC cppVar_76429;
	BIT_VEC cppVar_76424;
	BIT_VEC cppVar_76419;
	BIT_VEC cppVar_76414;
	BIT_VEC cppVar_76409;
	BIT_VEC cppVar_76404;
	BIT_VEC cppVar_76399;
	BIT_VEC cppVar_76394;
	BIT_VEC cppVar_76385;
	BIT_VEC cppVar_76500;
	BIT_VEC cppVar_76379;
	BIT_VEC cppVar_76502;
	BIT_VEC cppVar_76503;
	bool cppVar_76504;
	BIT_VEC cppVar_76506;
	BIT_VEC cppVar_76507;
	BIT_VEC cppVar_76508;
	BIT_VEC cppVar_76509;
	bool cppVar_76510;
	BIT_VEC cppVar_76512;
	BIT_VEC cppVar_76513;
	BIT_VEC cppVar_76514;
	BIT_VEC cppVar_76515;
	bool cppVar_76516;
	BIT_VEC cppVar_76517;
	BIT_VEC cppVar_76518;
	BIT_VEC cppVar_76519;
	BIT_VEC cppVar_76521;
	BIT_VEC cppVar_76522;
	BIT_VEC cppVar_76523;
	bool cppVar_76524;
	BIT_VEC cppVar_76526;
	BIT_VEC cppVar_76527;
	BIT_VEC cppVar_76528;
	bool cppVar_76529;
	BIT_VEC cppVar_76531;
	BIT_VEC cppVar_76532;
	BIT_VEC cppVar_76533;
	bool cppVar_76534;
	BIT_VEC cppVar_76536;
	BIT_VEC cppVar_76537;
	BIT_VEC cppVar_76538;
	bool cppVar_76539;
	BIT_VEC cppVar_76541;
	BIT_VEC cppVar_76542;
	BIT_VEC cppVar_76543;
	bool cppVar_76544;
	BIT_VEC cppVar_76546;
	BIT_VEC cppVar_76547;
	BIT_VEC cppVar_76548;
	bool cppVar_76549;
	BIT_VEC cppVar_76551;
	BIT_VEC cppVar_76552;
	BIT_VEC cppVar_76553;
	bool cppVar_76554;
	BIT_VEC cppVar_76556;
	BIT_VEC cppVar_76557;
	BIT_VEC cppVar_76558;
	bool cppVar_76559;
	BIT_VEC cppVar_76561;
	BIT_VEC cppVar_76562;
	BIT_VEC cppVar_76563;
	bool cppVar_76564;
	BIT_VEC cppVar_76566;
	BIT_VEC cppVar_76567;
	BIT_VEC cppVar_76568;
	bool cppVar_76569;
	BIT_VEC cppVar_76571;
	BIT_VEC cppVar_76572;
	BIT_VEC cppVar_76573;
	bool cppVar_76574;
	BIT_VEC cppVar_76576;
	BIT_VEC cppVar_76577;
	BIT_VEC cppVar_76578;
	bool cppVar_76579;
	BIT_VEC cppVar_76581;
	BIT_VEC cppVar_76582;
	BIT_VEC cppVar_76583;
	bool cppVar_76584;
	BIT_VEC cppVar_76586;
	BIT_VEC cppVar_76587;
	BIT_VEC cppVar_76588;
	bool cppVar_76589;
	BIT_VEC cppVar_76591;
	BIT_VEC cppVar_76592;
	BIT_VEC cppVar_76593;
	bool cppVar_76594;
	BIT_VEC cppVar_76596;
	BIT_VEC cppVar_76597;
	BIT_VEC cppVar_76598;
	bool cppVar_76599;
	BIT_VEC cppVar_76601;
	BIT_VEC cppVar_76602;
	BIT_VEC cppVar_76603;
	bool cppVar_76604;
	BIT_VEC cppVar_76606;
	BIT_VEC cppVar_76607;
	BIT_VEC cppVar_76608;
	bool cppVar_76609;
	BIT_VEC cppVar_76611;
	BIT_VEC cppVar_76612;
	BIT_VEC cppVar_76613;
	bool cppVar_76614;
	BIT_VEC cppVar_76616;
	BIT_VEC cppVar_76617;
	BIT_VEC cppVar_76618;
	bool cppVar_76619;
	BIT_VEC cppVar_76621;
	BIT_VEC cppVar_76622;
	BIT_VEC cppVar_76623;
	bool cppVar_76624;
	BIT_VEC cppVar_76625;
	BIT_VEC cppVar_76620;
	BIT_VEC cppVar_76615;
	BIT_VEC cppVar_76610;
	BIT_VEC cppVar_76605;
	BIT_VEC cppVar_76600;
	BIT_VEC cppVar_76595;
	BIT_VEC cppVar_76590;
	BIT_VEC cppVar_76585;
	BIT_VEC cppVar_76580;
	BIT_VEC cppVar_76575;
	BIT_VEC cppVar_76570;
	BIT_VEC cppVar_76565;
	BIT_VEC cppVar_76560;
	BIT_VEC cppVar_76555;
	BIT_VEC cppVar_76550;
	BIT_VEC cppVar_76545;
	BIT_VEC cppVar_76540;
	BIT_VEC cppVar_76535;
	BIT_VEC cppVar_76530;
	BIT_VEC cppVar_76525;
	BIT_VEC cppVar_76520;
	BIT_VEC cppVar_76511;
	BIT_VEC cppVar_76626;
	BIT_VEC cppVar_76627;
	BIT_VEC cppVar_76628;
	BIT_VEC cppVar_76629;
	BIT_VEC cppVar_76505;
	BIT_VEC cppVar_76631;
	BIT_VEC cppVar_76632;
	bool cppVar_76633;
	BIT_VEC cppVar_76635;
	BIT_VEC cppVar_76636;
	BIT_VEC cppVar_76637;
	BIT_VEC cppVar_76638;
	bool cppVar_76639;
	BIT_VEC cppVar_76641;
	BIT_VEC cppVar_76642;
	BIT_VEC cppVar_76643;
	BIT_VEC cppVar_76644;
	bool cppVar_76645;
	BIT_VEC cppVar_76646;
	BIT_VEC cppVar_76647;
	BIT_VEC cppVar_76648;
	BIT_VEC cppVar_76650;
	BIT_VEC cppVar_76651;
	BIT_VEC cppVar_76652;
	bool cppVar_76653;
	BIT_VEC cppVar_76655;
	BIT_VEC cppVar_76656;
	BIT_VEC cppVar_76657;
	bool cppVar_76658;
	BIT_VEC cppVar_76660;
	BIT_VEC cppVar_76661;
	BIT_VEC cppVar_76662;
	bool cppVar_76663;
	BIT_VEC cppVar_76665;
	BIT_VEC cppVar_76666;
	BIT_VEC cppVar_76667;
	bool cppVar_76668;
	BIT_VEC cppVar_76670;
	BIT_VEC cppVar_76671;
	BIT_VEC cppVar_76672;
	bool cppVar_76673;
	BIT_VEC cppVar_76675;
	BIT_VEC cppVar_76676;
	BIT_VEC cppVar_76677;
	bool cppVar_76678;
	BIT_VEC cppVar_76680;
	BIT_VEC cppVar_76681;
	BIT_VEC cppVar_76682;
	bool cppVar_76683;
	BIT_VEC cppVar_76685;
	BIT_VEC cppVar_76686;
	BIT_VEC cppVar_76687;
	bool cppVar_76688;
	BIT_VEC cppVar_76690;
	BIT_VEC cppVar_76691;
	BIT_VEC cppVar_76692;
	bool cppVar_76693;
	BIT_VEC cppVar_76695;
	BIT_VEC cppVar_76696;
	BIT_VEC cppVar_76697;
	bool cppVar_76698;
	BIT_VEC cppVar_76700;
	BIT_VEC cppVar_76701;
	BIT_VEC cppVar_76702;
	bool cppVar_76703;
	BIT_VEC cppVar_76705;
	BIT_VEC cppVar_76706;
	BIT_VEC cppVar_76707;
	bool cppVar_76708;
	BIT_VEC cppVar_76710;
	BIT_VEC cppVar_76711;
	BIT_VEC cppVar_76712;
	bool cppVar_76713;
	BIT_VEC cppVar_76715;
	BIT_VEC cppVar_76716;
	BIT_VEC cppVar_76717;
	bool cppVar_76718;
	BIT_VEC cppVar_76720;
	BIT_VEC cppVar_76721;
	BIT_VEC cppVar_76722;
	bool cppVar_76723;
	BIT_VEC cppVar_76725;
	BIT_VEC cppVar_76726;
	BIT_VEC cppVar_76727;
	bool cppVar_76728;
	BIT_VEC cppVar_76730;
	BIT_VEC cppVar_76731;
	BIT_VEC cppVar_76732;
	bool cppVar_76733;
	BIT_VEC cppVar_76735;
	BIT_VEC cppVar_76736;
	BIT_VEC cppVar_76737;
	bool cppVar_76738;
	BIT_VEC cppVar_76740;
	BIT_VEC cppVar_76741;
	BIT_VEC cppVar_76742;
	bool cppVar_76743;
	BIT_VEC cppVar_76745;
	BIT_VEC cppVar_76746;
	BIT_VEC cppVar_76747;
	bool cppVar_76748;
	BIT_VEC cppVar_76750;
	BIT_VEC cppVar_76751;
	BIT_VEC cppVar_76752;
	bool cppVar_76753;
	BIT_VEC cppVar_76754;
	BIT_VEC cppVar_76749;
	BIT_VEC cppVar_76744;
	BIT_VEC cppVar_76739;
	BIT_VEC cppVar_76734;
	BIT_VEC cppVar_76729;
	BIT_VEC cppVar_76724;
	BIT_VEC cppVar_76719;
	BIT_VEC cppVar_76714;
	BIT_VEC cppVar_76709;
	BIT_VEC cppVar_76704;
	BIT_VEC cppVar_76699;
	BIT_VEC cppVar_76694;
	BIT_VEC cppVar_76689;
	BIT_VEC cppVar_76684;
	BIT_VEC cppVar_76679;
	BIT_VEC cppVar_76674;
	BIT_VEC cppVar_76669;
	BIT_VEC cppVar_76664;
	BIT_VEC cppVar_76659;
	BIT_VEC cppVar_76654;
	BIT_VEC cppVar_76649;
	BIT_VEC cppVar_76640;
	BIT_VEC cppVar_76755;
	BIT_VEC cppVar_76634;
	BIT_VEC cppVar_76757;
	BIT_VEC cppVar_76758;
	bool cppVar_76759;
	BIT_VEC cppVar_76761;
	BIT_VEC cppVar_76762;
	BIT_VEC cppVar_76763;
	BIT_VEC cppVar_76764;
	bool cppVar_76765;
	BIT_VEC cppVar_76767;
	BIT_VEC cppVar_76768;
	BIT_VEC cppVar_76769;
	BIT_VEC cppVar_76770;
	bool cppVar_76771;
	BIT_VEC cppVar_76772;
	BIT_VEC cppVar_76773;
	BIT_VEC cppVar_76774;
	BIT_VEC cppVar_76776;
	BIT_VEC cppVar_76777;
	BIT_VEC cppVar_76778;
	bool cppVar_76779;
	BIT_VEC cppVar_76781;
	BIT_VEC cppVar_76782;
	BIT_VEC cppVar_76783;
	bool cppVar_76784;
	BIT_VEC cppVar_76786;
	BIT_VEC cppVar_76787;
	BIT_VEC cppVar_76788;
	bool cppVar_76789;
	BIT_VEC cppVar_76791;
	BIT_VEC cppVar_76792;
	BIT_VEC cppVar_76793;
	bool cppVar_76794;
	BIT_VEC cppVar_76796;
	BIT_VEC cppVar_76797;
	BIT_VEC cppVar_76798;
	bool cppVar_76799;
	BIT_VEC cppVar_76801;
	BIT_VEC cppVar_76802;
	BIT_VEC cppVar_76803;
	bool cppVar_76804;
	BIT_VEC cppVar_76806;
	BIT_VEC cppVar_76807;
	BIT_VEC cppVar_76808;
	bool cppVar_76809;
	BIT_VEC cppVar_76811;
	BIT_VEC cppVar_76812;
	BIT_VEC cppVar_76813;
	bool cppVar_76814;
	BIT_VEC cppVar_76816;
	BIT_VEC cppVar_76817;
	BIT_VEC cppVar_76818;
	bool cppVar_76819;
	BIT_VEC cppVar_76821;
	BIT_VEC cppVar_76822;
	BIT_VEC cppVar_76823;
	bool cppVar_76824;
	BIT_VEC cppVar_76826;
	BIT_VEC cppVar_76827;
	BIT_VEC cppVar_76828;
	bool cppVar_76829;
	BIT_VEC cppVar_76831;
	BIT_VEC cppVar_76832;
	BIT_VEC cppVar_76833;
	bool cppVar_76834;
	BIT_VEC cppVar_76836;
	BIT_VEC cppVar_76837;
	BIT_VEC cppVar_76838;
	bool cppVar_76839;
	BIT_VEC cppVar_76841;
	BIT_VEC cppVar_76842;
	BIT_VEC cppVar_76843;
	bool cppVar_76844;
	BIT_VEC cppVar_76846;
	BIT_VEC cppVar_76847;
	BIT_VEC cppVar_76848;
	bool cppVar_76849;
	BIT_VEC cppVar_76851;
	BIT_VEC cppVar_76852;
	BIT_VEC cppVar_76853;
	bool cppVar_76854;
	BIT_VEC cppVar_76856;
	BIT_VEC cppVar_76857;
	BIT_VEC cppVar_76858;
	bool cppVar_76859;
	BIT_VEC cppVar_76861;
	BIT_VEC cppVar_76862;
	BIT_VEC cppVar_76863;
	bool cppVar_76864;
	BIT_VEC cppVar_76866;
	BIT_VEC cppVar_76867;
	BIT_VEC cppVar_76868;
	bool cppVar_76869;
	BIT_VEC cppVar_76871;
	BIT_VEC cppVar_76872;
	BIT_VEC cppVar_76873;
	bool cppVar_76874;
	BIT_VEC cppVar_76876;
	BIT_VEC cppVar_76877;
	BIT_VEC cppVar_76878;
	bool cppVar_76879;
	BIT_VEC cppVar_76880;
	BIT_VEC cppVar_76875;
	BIT_VEC cppVar_76870;
	BIT_VEC cppVar_76865;
	BIT_VEC cppVar_76860;
	BIT_VEC cppVar_76855;
	BIT_VEC cppVar_76850;
	BIT_VEC cppVar_76845;
	BIT_VEC cppVar_76840;
	BIT_VEC cppVar_76835;
	BIT_VEC cppVar_76830;
	BIT_VEC cppVar_76825;
	BIT_VEC cppVar_76820;
	BIT_VEC cppVar_76815;
	BIT_VEC cppVar_76810;
	BIT_VEC cppVar_76805;
	BIT_VEC cppVar_76800;
	BIT_VEC cppVar_76795;
	BIT_VEC cppVar_76790;
	BIT_VEC cppVar_76785;
	BIT_VEC cppVar_76780;
	BIT_VEC cppVar_76775;
	BIT_VEC cppVar_76766;
	BIT_VEC cppVar_76881;
	BIT_VEC cppVar_76882;
	BIT_VEC cppVar_76883;
	BIT_VEC cppVar_76884;
	BIT_VEC cppVar_76760;
	BIT_VEC cppVar_76886;
	BIT_VEC cppVar_76887;
	bool cppVar_76888;
	BIT_VEC cppVar_76890;
	BIT_VEC cppVar_76891;
	BIT_VEC cppVar_76892;
	BIT_VEC cppVar_76893;
	bool cppVar_76894;
	BIT_VEC cppVar_76896;
	BIT_VEC cppVar_76897;
	BIT_VEC cppVar_76898;
	BIT_VEC cppVar_76899;
	bool cppVar_76900;
	BIT_VEC cppVar_76901;
	BIT_VEC cppVar_76902;
	BIT_VEC cppVar_76903;
	BIT_VEC cppVar_76905;
	BIT_VEC cppVar_76906;
	BIT_VEC cppVar_76907;
	bool cppVar_76908;
	BIT_VEC cppVar_76910;
	BIT_VEC cppVar_76911;
	BIT_VEC cppVar_76912;
	bool cppVar_76913;
	BIT_VEC cppVar_76915;
	BIT_VEC cppVar_76916;
	BIT_VEC cppVar_76917;
	bool cppVar_76918;
	BIT_VEC cppVar_76920;
	BIT_VEC cppVar_76921;
	BIT_VEC cppVar_76922;
	bool cppVar_76923;
	BIT_VEC cppVar_76925;
	BIT_VEC cppVar_76926;
	BIT_VEC cppVar_76927;
	bool cppVar_76928;
	BIT_VEC cppVar_76930;
	BIT_VEC cppVar_76931;
	BIT_VEC cppVar_76932;
	bool cppVar_76933;
	BIT_VEC cppVar_76935;
	BIT_VEC cppVar_76936;
	BIT_VEC cppVar_76937;
	bool cppVar_76938;
	BIT_VEC cppVar_76940;
	BIT_VEC cppVar_76941;
	BIT_VEC cppVar_76942;
	bool cppVar_76943;
	BIT_VEC cppVar_76945;
	BIT_VEC cppVar_76946;
	BIT_VEC cppVar_76947;
	bool cppVar_76948;
	BIT_VEC cppVar_76950;
	BIT_VEC cppVar_76951;
	BIT_VEC cppVar_76952;
	bool cppVar_76953;
	BIT_VEC cppVar_76955;
	BIT_VEC cppVar_76956;
	BIT_VEC cppVar_76957;
	bool cppVar_76958;
	BIT_VEC cppVar_76960;
	BIT_VEC cppVar_76961;
	BIT_VEC cppVar_76962;
	bool cppVar_76963;
	BIT_VEC cppVar_76965;
	BIT_VEC cppVar_76966;
	BIT_VEC cppVar_76967;
	bool cppVar_76968;
	BIT_VEC cppVar_76970;
	BIT_VEC cppVar_76971;
	BIT_VEC cppVar_76972;
	bool cppVar_76973;
	BIT_VEC cppVar_76975;
	BIT_VEC cppVar_76976;
	BIT_VEC cppVar_76977;
	bool cppVar_76978;
	BIT_VEC cppVar_76980;
	BIT_VEC cppVar_76981;
	BIT_VEC cppVar_76982;
	bool cppVar_76983;
	BIT_VEC cppVar_76985;
	BIT_VEC cppVar_76986;
	BIT_VEC cppVar_76987;
	bool cppVar_76988;
	BIT_VEC cppVar_76990;
	BIT_VEC cppVar_76991;
	BIT_VEC cppVar_76992;
	bool cppVar_76993;
	BIT_VEC cppVar_76995;
	BIT_VEC cppVar_76996;
	BIT_VEC cppVar_76997;
	bool cppVar_76998;
	BIT_VEC cppVar_77000;
	BIT_VEC cppVar_77001;
	BIT_VEC cppVar_77002;
	bool cppVar_77003;
	BIT_VEC cppVar_77005;
	BIT_VEC cppVar_77006;
	BIT_VEC cppVar_77007;
	bool cppVar_77008;
	BIT_VEC cppVar_77009;
	BIT_VEC cppVar_77004;
	BIT_VEC cppVar_76999;
	BIT_VEC cppVar_76994;
	BIT_VEC cppVar_76989;
	BIT_VEC cppVar_76984;
	BIT_VEC cppVar_76979;
	BIT_VEC cppVar_76974;
	BIT_VEC cppVar_76969;
	BIT_VEC cppVar_76964;
	BIT_VEC cppVar_76959;
	BIT_VEC cppVar_76954;
	BIT_VEC cppVar_76949;
	BIT_VEC cppVar_76944;
	BIT_VEC cppVar_76939;
	BIT_VEC cppVar_76934;
	BIT_VEC cppVar_76929;
	BIT_VEC cppVar_76924;
	BIT_VEC cppVar_76919;
	BIT_VEC cppVar_76914;
	BIT_VEC cppVar_76909;
	BIT_VEC cppVar_76904;
	BIT_VEC cppVar_76895;
	BIT_VEC cppVar_77010;
	BIT_VEC cppVar_76889;
	BIT_VEC cppVar_77012;
	BIT_VEC cppVar_77013;
	bool cppVar_77014;
	BIT_VEC cppVar_77015;
	BIT_VEC cppVar_77016;
	bool cppVar_77017;
	bool cppVar_77018;
	BIT_VEC cppVar_77020;
	BIT_VEC cppVar_77021;
	BIT_VEC cppVar_77022;
	BIT_VEC cppVar_77023;
	bool cppVar_77024;
	BIT_VEC cppVar_77026;
	BIT_VEC cppVar_77027;
	BIT_VEC cppVar_77028;
	BIT_VEC cppVar_77029;
	bool cppVar_77030;
	BIT_VEC cppVar_77031;
	BIT_VEC cppVar_77032;
	BIT_VEC cppVar_77033;
	BIT_VEC cppVar_77035;
	BIT_VEC cppVar_77036;
	BIT_VEC cppVar_77037;
	bool cppVar_77038;
	BIT_VEC cppVar_77040;
	BIT_VEC cppVar_77041;
	BIT_VEC cppVar_77042;
	bool cppVar_77043;
	BIT_VEC cppVar_77045;
	BIT_VEC cppVar_77046;
	BIT_VEC cppVar_77047;
	bool cppVar_77048;
	BIT_VEC cppVar_77050;
	BIT_VEC cppVar_77051;
	BIT_VEC cppVar_77052;
	bool cppVar_77053;
	BIT_VEC cppVar_77055;
	BIT_VEC cppVar_77056;
	BIT_VEC cppVar_77057;
	bool cppVar_77058;
	BIT_VEC cppVar_77060;
	BIT_VEC cppVar_77061;
	BIT_VEC cppVar_77062;
	bool cppVar_77063;
	BIT_VEC cppVar_77065;
	BIT_VEC cppVar_77066;
	BIT_VEC cppVar_77067;
	bool cppVar_77068;
	BIT_VEC cppVar_77070;
	BIT_VEC cppVar_77071;
	BIT_VEC cppVar_77072;
	bool cppVar_77073;
	BIT_VEC cppVar_77075;
	BIT_VEC cppVar_77076;
	BIT_VEC cppVar_77077;
	bool cppVar_77078;
	BIT_VEC cppVar_77080;
	BIT_VEC cppVar_77081;
	BIT_VEC cppVar_77082;
	bool cppVar_77083;
	BIT_VEC cppVar_77085;
	BIT_VEC cppVar_77086;
	BIT_VEC cppVar_77087;
	bool cppVar_77088;
	BIT_VEC cppVar_77090;
	BIT_VEC cppVar_77091;
	BIT_VEC cppVar_77092;
	bool cppVar_77093;
	BIT_VEC cppVar_77095;
	BIT_VEC cppVar_77096;
	BIT_VEC cppVar_77097;
	bool cppVar_77098;
	BIT_VEC cppVar_77100;
	BIT_VEC cppVar_77101;
	BIT_VEC cppVar_77102;
	bool cppVar_77103;
	BIT_VEC cppVar_77105;
	BIT_VEC cppVar_77106;
	BIT_VEC cppVar_77107;
	bool cppVar_77108;
	BIT_VEC cppVar_77110;
	BIT_VEC cppVar_77111;
	BIT_VEC cppVar_77112;
	bool cppVar_77113;
	BIT_VEC cppVar_77115;
	BIT_VEC cppVar_77116;
	BIT_VEC cppVar_77117;
	bool cppVar_77118;
	BIT_VEC cppVar_77120;
	BIT_VEC cppVar_77121;
	BIT_VEC cppVar_77122;
	bool cppVar_77123;
	BIT_VEC cppVar_77125;
	BIT_VEC cppVar_77126;
	BIT_VEC cppVar_77127;
	bool cppVar_77128;
	BIT_VEC cppVar_77130;
	BIT_VEC cppVar_77131;
	BIT_VEC cppVar_77132;
	bool cppVar_77133;
	BIT_VEC cppVar_77135;
	BIT_VEC cppVar_77136;
	BIT_VEC cppVar_77137;
	bool cppVar_77138;
	BIT_VEC cppVar_77139;
	BIT_VEC cppVar_77134;
	BIT_VEC cppVar_77129;
	BIT_VEC cppVar_77124;
	BIT_VEC cppVar_77119;
	BIT_VEC cppVar_77114;
	BIT_VEC cppVar_77109;
	BIT_VEC cppVar_77104;
	BIT_VEC cppVar_77099;
	BIT_VEC cppVar_77094;
	BIT_VEC cppVar_77089;
	BIT_VEC cppVar_77084;
	BIT_VEC cppVar_77079;
	BIT_VEC cppVar_77074;
	BIT_VEC cppVar_77069;
	BIT_VEC cppVar_77064;
	BIT_VEC cppVar_77059;
	BIT_VEC cppVar_77054;
	BIT_VEC cppVar_77049;
	BIT_VEC cppVar_77044;
	BIT_VEC cppVar_77039;
	BIT_VEC cppVar_77034;
	BIT_VEC cppVar_77025;
	BIT_VEC cppVar_77140;
	BIT_VEC cppVar_77141;
	BIT_VEC cppVar_77019;
	BIT_VEC cppVar_77143;
	BIT_VEC cppVar_77144;
	bool cppVar_77145;
	BIT_VEC cppVar_77147;
	BIT_VEC cppVar_77148;
	BIT_VEC cppVar_77149;
	BIT_VEC cppVar_77150;
	bool cppVar_77151;
	BIT_VEC cppVar_77153;
	BIT_VEC cppVar_77154;
	BIT_VEC cppVar_77155;
	BIT_VEC cppVar_77156;
	bool cppVar_77157;
	BIT_VEC cppVar_77158;
	BIT_VEC cppVar_77159;
	BIT_VEC cppVar_77160;
	BIT_VEC cppVar_77162;
	BIT_VEC cppVar_77163;
	BIT_VEC cppVar_77164;
	bool cppVar_77165;
	BIT_VEC cppVar_77167;
	BIT_VEC cppVar_77168;
	BIT_VEC cppVar_77169;
	bool cppVar_77170;
	BIT_VEC cppVar_77172;
	BIT_VEC cppVar_77173;
	BIT_VEC cppVar_77174;
	bool cppVar_77175;
	BIT_VEC cppVar_77177;
	BIT_VEC cppVar_77178;
	BIT_VEC cppVar_77179;
	bool cppVar_77180;
	BIT_VEC cppVar_77182;
	BIT_VEC cppVar_77183;
	BIT_VEC cppVar_77184;
	bool cppVar_77185;
	BIT_VEC cppVar_77187;
	BIT_VEC cppVar_77188;
	BIT_VEC cppVar_77189;
	bool cppVar_77190;
	BIT_VEC cppVar_77192;
	BIT_VEC cppVar_77193;
	BIT_VEC cppVar_77194;
	bool cppVar_77195;
	BIT_VEC cppVar_77197;
	BIT_VEC cppVar_77198;
	BIT_VEC cppVar_77199;
	bool cppVar_77200;
	BIT_VEC cppVar_77202;
	BIT_VEC cppVar_77203;
	BIT_VEC cppVar_77204;
	bool cppVar_77205;
	BIT_VEC cppVar_77207;
	BIT_VEC cppVar_77208;
	BIT_VEC cppVar_77209;
	bool cppVar_77210;
	BIT_VEC cppVar_77212;
	BIT_VEC cppVar_77213;
	BIT_VEC cppVar_77214;
	bool cppVar_77215;
	BIT_VEC cppVar_77217;
	BIT_VEC cppVar_77218;
	BIT_VEC cppVar_77219;
	bool cppVar_77220;
	BIT_VEC cppVar_77222;
	BIT_VEC cppVar_77223;
	BIT_VEC cppVar_77224;
	bool cppVar_77225;
	BIT_VEC cppVar_77227;
	BIT_VEC cppVar_77228;
	BIT_VEC cppVar_77229;
	bool cppVar_77230;
	BIT_VEC cppVar_77232;
	BIT_VEC cppVar_77233;
	BIT_VEC cppVar_77234;
	bool cppVar_77235;
	BIT_VEC cppVar_77237;
	BIT_VEC cppVar_77238;
	BIT_VEC cppVar_77239;
	bool cppVar_77240;
	BIT_VEC cppVar_77242;
	BIT_VEC cppVar_77243;
	BIT_VEC cppVar_77244;
	bool cppVar_77245;
	BIT_VEC cppVar_77247;
	BIT_VEC cppVar_77248;
	BIT_VEC cppVar_77249;
	bool cppVar_77250;
	BIT_VEC cppVar_77252;
	BIT_VEC cppVar_77253;
	BIT_VEC cppVar_77254;
	bool cppVar_77255;
	BIT_VEC cppVar_77257;
	BIT_VEC cppVar_77258;
	BIT_VEC cppVar_77259;
	bool cppVar_77260;
	BIT_VEC cppVar_77262;
	BIT_VEC cppVar_77263;
	BIT_VEC cppVar_77264;
	bool cppVar_77265;
	BIT_VEC cppVar_77266;
	BIT_VEC cppVar_77261;
	BIT_VEC cppVar_77256;
	BIT_VEC cppVar_77251;
	BIT_VEC cppVar_77246;
	BIT_VEC cppVar_77241;
	BIT_VEC cppVar_77236;
	BIT_VEC cppVar_77231;
	BIT_VEC cppVar_77226;
	BIT_VEC cppVar_77221;
	BIT_VEC cppVar_77216;
	BIT_VEC cppVar_77211;
	BIT_VEC cppVar_77206;
	BIT_VEC cppVar_77201;
	BIT_VEC cppVar_77196;
	BIT_VEC cppVar_77191;
	BIT_VEC cppVar_77186;
	BIT_VEC cppVar_77181;
	BIT_VEC cppVar_77176;
	BIT_VEC cppVar_77171;
	BIT_VEC cppVar_77166;
	BIT_VEC cppVar_77161;
	BIT_VEC cppVar_77152;
	BIT_VEC cppVar_77267;
	BIT_VEC cppVar_77268;
	BIT_VEC cppVar_77146;
	BIT_VEC cppVar_77142;
	BIT_VEC cppVar_77011;
	BIT_VEC cppVar_76885;
	BIT_VEC cppVar_76756;
	BIT_VEC cppVar_76630;
	BIT_VEC cppVar_76501;
	BIT_VEC cppVar_76375;
	BIT_VEC cppVar_76246;
	BIT_VEC cppVar_76233;
	BIT_VEC cppVar_76107;
	BIT_VEC cppVar_76090;
	BIT_VEC cppVar_76073;
	BIT_VEC cppVar_75923;
	BIT_VEC cppVar_75773;
	BIT_VEC cppVar_75623;
	BIT_VEC cppVar_75473;
	BIT_VEC cppVar_75323;
	BIT_VEC cppVar_75173;
	BIT_VEC cppVar_75023;
	BIT_VEC cppVar_74873;
	BIT_VEC cppVar_74859;
	BIT_VEC cppVar_74848;
	cppVar_74849 = ROM.rd(PC);
	cppVar_74851 = (cppVar_74849 == 208);
	if (cppVar_74851) {
	cppVar_74854 = PC + 1;
	cppVar_74854 = (cppVar_74854 & cppMask_un_16_);
	cppVar_74855 = ROM.rd(cppVar_74854);
	cppVar_74857 = (cppVar_74855 == 141);
	if (cppVar_74857) {
	cppVar_74858 = IRAM.rd(SP);
	cppVar_74852 = cppVar_74858;
	} else {
	cppVar_74852 = TH1;
	}
	cppVar_74848 = cppVar_74852;
	} else {
	cppVar_74860 = ROM.rd(PC);
	cppVar_74862 = (cppVar_74860 == 245);
	cppVar_74863 = ROM.rd(PC);
	cppVar_74865 = (cppVar_74863 == 197);
	cppVar_74866 = cppVar_74862 || cppVar_74865;
	if (cppVar_74866) {
	cppVar_74869 = PC + 1;
	cppVar_74869 = (cppVar_74869 & cppMask_un_16_);
	cppVar_74870 = ROM.rd(cppVar_74869);
	cppVar_74872 = (cppVar_74870 == 141);
	if (cppVar_74872) {
	cppVar_74867 = ACC;
	} else {
	cppVar_74867 = TH1;
	}
	cppVar_74859 = cppVar_74867;
	} else {
	cppVar_74874 = ROM.rd(PC);
	cppVar_74876 = (cppVar_74874 == 143);
	if (cppVar_74876) {
	cppVar_74879 = PC + 1;
	cppVar_74879 = (cppVar_74879 & cppMask_un_16_);
	cppVar_74880 = ROM.rd(cppVar_74879);
	cppVar_74882 = (cppVar_74880 == 141);
	if (cppVar_74882) {
	cppVar_74885 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74887 = (cppVar_74885 << 3) | 7;
	cppVar_74887 = (cppVar_74887 & cppMask_un_5_);
	cppVar_74888 = (0 << 5) | cppVar_74887;
	cppVar_74888 = (cppVar_74888 & cppMask_un_8_);
	cppVar_74889 = (cppVar_74888 >> 7) & cppMask_un_1_;
	cppVar_74891 = (cppVar_74889 == 0);
	if (cppVar_74891) {
	cppVar_74892 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74893 = (cppVar_74892 << 3) | 7;
	cppVar_74893 = (cppVar_74893 & cppMask_un_5_);
	cppVar_74894 = (0 << 5) | cppVar_74893;
	cppVar_74894 = (cppVar_74894 & cppMask_un_8_);
	cppVar_74895 = IRAM.rd(cppVar_74894);
	cppVar_74883 = cppVar_74895;
	} else {
	cppVar_74897 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74898 = (cppVar_74897 << 3) | 7;
	cppVar_74898 = (cppVar_74898 & cppMask_un_5_);
	cppVar_74899 = (0 << 5) | cppVar_74898;
	cppVar_74899 = (cppVar_74899 & cppMask_un_8_);
	cppVar_74901 = (cppVar_74899 == 128);
	if (cppVar_74901) {
	cppVar_74896 = P0;
	} else {
	cppVar_74903 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74904 = (cppVar_74903 << 3) | 7;
	cppVar_74904 = (cppVar_74904 & cppMask_un_5_);
	cppVar_74905 = (0 << 5) | cppVar_74904;
	cppVar_74905 = (cppVar_74905 & cppMask_un_8_);
	cppVar_74907 = (cppVar_74905 == 129);
	if (cppVar_74907) {
	cppVar_74902 = SP;
	} else {
	cppVar_74909 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74910 = (cppVar_74909 << 3) | 7;
	cppVar_74910 = (cppVar_74910 & cppMask_un_5_);
	cppVar_74911 = (0 << 5) | cppVar_74910;
	cppVar_74911 = (cppVar_74911 & cppMask_un_8_);
	cppVar_74913 = (cppVar_74911 == 130);
	if (cppVar_74913) {
	cppVar_74908 = DPL;
	} else {
	cppVar_74915 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74916 = (cppVar_74915 << 3) | 7;
	cppVar_74916 = (cppVar_74916 & cppMask_un_5_);
	cppVar_74917 = (0 << 5) | cppVar_74916;
	cppVar_74917 = (cppVar_74917 & cppMask_un_8_);
	cppVar_74919 = (cppVar_74917 == 131);
	if (cppVar_74919) {
	cppVar_74914 = DPH;
	} else {
	cppVar_74921 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74922 = (cppVar_74921 << 3) | 7;
	cppVar_74922 = (cppVar_74922 & cppMask_un_5_);
	cppVar_74923 = (0 << 5) | cppVar_74922;
	cppVar_74923 = (cppVar_74923 & cppMask_un_8_);
	cppVar_74925 = (cppVar_74923 == 135);
	if (cppVar_74925) {
	cppVar_74920 = PCON;
	} else {
	cppVar_74927 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74928 = (cppVar_74927 << 3) | 7;
	cppVar_74928 = (cppVar_74928 & cppMask_un_5_);
	cppVar_74929 = (0 << 5) | cppVar_74928;
	cppVar_74929 = (cppVar_74929 & cppMask_un_8_);
	cppVar_74931 = (cppVar_74929 == 136);
	if (cppVar_74931) {
	cppVar_74926 = TCON;
	} else {
	cppVar_74933 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74934 = (cppVar_74933 << 3) | 7;
	cppVar_74934 = (cppVar_74934 & cppMask_un_5_);
	cppVar_74935 = (0 << 5) | cppVar_74934;
	cppVar_74935 = (cppVar_74935 & cppMask_un_8_);
	cppVar_74937 = (cppVar_74935 == 137);
	if (cppVar_74937) {
	cppVar_74932 = TMOD;
	} else {
	cppVar_74939 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74940 = (cppVar_74939 << 3) | 7;
	cppVar_74940 = (cppVar_74940 & cppMask_un_5_);
	cppVar_74941 = (0 << 5) | cppVar_74940;
	cppVar_74941 = (cppVar_74941 & cppMask_un_8_);
	cppVar_74943 = (cppVar_74941 == 138);
	if (cppVar_74943) {
	cppVar_74938 = TL0;
	} else {
	cppVar_74945 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74946 = (cppVar_74945 << 3) | 7;
	cppVar_74946 = (cppVar_74946 & cppMask_un_5_);
	cppVar_74947 = (0 << 5) | cppVar_74946;
	cppVar_74947 = (cppVar_74947 & cppMask_un_8_);
	cppVar_74949 = (cppVar_74947 == 140);
	if (cppVar_74949) {
	cppVar_74944 = TH0;
	} else {
	cppVar_74951 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74952 = (cppVar_74951 << 3) | 7;
	cppVar_74952 = (cppVar_74952 & cppMask_un_5_);
	cppVar_74953 = (0 << 5) | cppVar_74952;
	cppVar_74953 = (cppVar_74953 & cppMask_un_8_);
	cppVar_74955 = (cppVar_74953 == 139);
	if (cppVar_74955) {
	cppVar_74950 = TL1;
	} else {
	cppVar_74957 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74958 = (cppVar_74957 << 3) | 7;
	cppVar_74958 = (cppVar_74958 & cppMask_un_5_);
	cppVar_74959 = (0 << 5) | cppVar_74958;
	cppVar_74959 = (cppVar_74959 & cppMask_un_8_);
	cppVar_74961 = (cppVar_74959 == 141);
	if (cppVar_74961) {
	cppVar_74956 = TH1;
	} else {
	cppVar_74963 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74964 = (cppVar_74963 << 3) | 7;
	cppVar_74964 = (cppVar_74964 & cppMask_un_5_);
	cppVar_74965 = (0 << 5) | cppVar_74964;
	cppVar_74965 = (cppVar_74965 & cppMask_un_8_);
	cppVar_74967 = (cppVar_74965 == 144);
	if (cppVar_74967) {
	cppVar_74962 = P1;
	} else {
	cppVar_74969 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74970 = (cppVar_74969 << 3) | 7;
	cppVar_74970 = (cppVar_74970 & cppMask_un_5_);
	cppVar_74971 = (0 << 5) | cppVar_74970;
	cppVar_74971 = (cppVar_74971 & cppMask_un_8_);
	cppVar_74973 = (cppVar_74971 == 152);
	if (cppVar_74973) {
	cppVar_74968 = SCON;
	} else {
	cppVar_74975 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74976 = (cppVar_74975 << 3) | 7;
	cppVar_74976 = (cppVar_74976 & cppMask_un_5_);
	cppVar_74977 = (0 << 5) | cppVar_74976;
	cppVar_74977 = (cppVar_74977 & cppMask_un_8_);
	cppVar_74979 = (cppVar_74977 == 153);
	if (cppVar_74979) {
	cppVar_74974 = SBUF;
	} else {
	cppVar_74981 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74982 = (cppVar_74981 << 3) | 7;
	cppVar_74982 = (cppVar_74982 & cppMask_un_5_);
	cppVar_74983 = (0 << 5) | cppVar_74982;
	cppVar_74983 = (cppVar_74983 & cppMask_un_8_);
	cppVar_74985 = (cppVar_74983 == 160);
	if (cppVar_74985) {
	cppVar_74980 = P2;
	} else {
	cppVar_74987 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74988 = (cppVar_74987 << 3) | 7;
	cppVar_74988 = (cppVar_74988 & cppMask_un_5_);
	cppVar_74989 = (0 << 5) | cppVar_74988;
	cppVar_74989 = (cppVar_74989 & cppMask_un_8_);
	cppVar_74991 = (cppVar_74989 == 168);
	if (cppVar_74991) {
	cppVar_74986 = IE;
	} else {
	cppVar_74993 = (PSW >> 3) & cppMask_un_2_;
	cppVar_74994 = (cppVar_74993 << 3) | 7;
	cppVar_74994 = (cppVar_74994 & cppMask_un_5_);
	cppVar_74995 = (0 << 5) | cppVar_74994;
	cppVar_74995 = (cppVar_74995 & cppMask_un_8_);
	cppVar_74997 = (cppVar_74995 == 176);
	if (cppVar_74997) {
	cppVar_74992 = P3;
	} else {
	cppVar_74999 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75000 = (cppVar_74999 << 3) | 7;
	cppVar_75000 = (cppVar_75000 & cppMask_un_5_);
	cppVar_75001 = (0 << 5) | cppVar_75000;
	cppVar_75001 = (cppVar_75001 & cppMask_un_8_);
	cppVar_75003 = (cppVar_75001 == 184);
	if (cppVar_75003) {
	cppVar_74998 = IP;
	} else {
	cppVar_75005 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75006 = (cppVar_75005 << 3) | 7;
	cppVar_75006 = (cppVar_75006 & cppMask_un_5_);
	cppVar_75007 = (0 << 5) | cppVar_75006;
	cppVar_75007 = (cppVar_75007 & cppMask_un_8_);
	cppVar_75009 = (cppVar_75007 == 208);
	if (cppVar_75009) {
	cppVar_75004 = PSW;
	} else {
	cppVar_75011 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75012 = (cppVar_75011 << 3) | 7;
	cppVar_75012 = (cppVar_75012 & cppMask_un_5_);
	cppVar_75013 = (0 << 5) | cppVar_75012;
	cppVar_75013 = (cppVar_75013 & cppMask_un_8_);
	cppVar_75015 = (cppVar_75013 == 224);
	if (cppVar_75015) {
	cppVar_75010 = ACC;
	} else {
	cppVar_75017 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75018 = (cppVar_75017 << 3) | 7;
	cppVar_75018 = (cppVar_75018 & cppMask_un_5_);
	cppVar_75019 = (0 << 5) | cppVar_75018;
	cppVar_75019 = (cppVar_75019 & cppMask_un_8_);
	cppVar_75021 = (cppVar_75019 == 240);
	if (cppVar_75021) {
	cppVar_75016 = B;
	} else {
	cppVar_75016 = 0;
	}
	cppVar_75010 = cppVar_75016;
	}
	cppVar_75004 = cppVar_75010;
	}
	cppVar_74998 = cppVar_75004;
	}
	cppVar_74992 = cppVar_74998;
	}
	cppVar_74986 = cppVar_74992;
	}
	cppVar_74980 = cppVar_74986;
	}
	cppVar_74974 = cppVar_74980;
	}
	cppVar_74968 = cppVar_74974;
	}
	cppVar_74962 = cppVar_74968;
	}
	cppVar_74956 = cppVar_74962;
	}
	cppVar_74950 = cppVar_74956;
	}
	cppVar_74944 = cppVar_74950;
	}
	cppVar_74938 = cppVar_74944;
	}
	cppVar_74932 = cppVar_74938;
	}
	cppVar_74926 = cppVar_74932;
	}
	cppVar_74920 = cppVar_74926;
	}
	cppVar_74914 = cppVar_74920;
	}
	cppVar_74908 = cppVar_74914;
	}
	cppVar_74902 = cppVar_74908;
	}
	cppVar_74896 = cppVar_74902;
	}
	cppVar_74883 = cppVar_74896;
	}
	cppVar_74877 = cppVar_74883;
	} else {
	cppVar_74877 = TH1;
	}
	cppVar_74873 = cppVar_74877;
	} else {
	cppVar_75024 = ROM.rd(PC);
	cppVar_75026 = (cppVar_75024 == 142);
	if (cppVar_75026) {
	cppVar_75029 = PC + 1;
	cppVar_75029 = (cppVar_75029 & cppMask_un_16_);
	cppVar_75030 = ROM.rd(cppVar_75029);
	cppVar_75032 = (cppVar_75030 == 141);
	if (cppVar_75032) {
	cppVar_75035 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75037 = (cppVar_75035 << 3) | 6;
	cppVar_75037 = (cppVar_75037 & cppMask_un_5_);
	cppVar_75038 = (0 << 5) | cppVar_75037;
	cppVar_75038 = (cppVar_75038 & cppMask_un_8_);
	cppVar_75039 = (cppVar_75038 >> 7) & cppMask_un_1_;
	cppVar_75041 = (cppVar_75039 == 0);
	if (cppVar_75041) {
	cppVar_75042 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75043 = (cppVar_75042 << 3) | 6;
	cppVar_75043 = (cppVar_75043 & cppMask_un_5_);
	cppVar_75044 = (0 << 5) | cppVar_75043;
	cppVar_75044 = (cppVar_75044 & cppMask_un_8_);
	cppVar_75045 = IRAM.rd(cppVar_75044);
	cppVar_75033 = cppVar_75045;
	} else {
	cppVar_75047 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75048 = (cppVar_75047 << 3) | 6;
	cppVar_75048 = (cppVar_75048 & cppMask_un_5_);
	cppVar_75049 = (0 << 5) | cppVar_75048;
	cppVar_75049 = (cppVar_75049 & cppMask_un_8_);
	cppVar_75051 = (cppVar_75049 == 128);
	if (cppVar_75051) {
	cppVar_75046 = P0;
	} else {
	cppVar_75053 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75054 = (cppVar_75053 << 3) | 6;
	cppVar_75054 = (cppVar_75054 & cppMask_un_5_);
	cppVar_75055 = (0 << 5) | cppVar_75054;
	cppVar_75055 = (cppVar_75055 & cppMask_un_8_);
	cppVar_75057 = (cppVar_75055 == 129);
	if (cppVar_75057) {
	cppVar_75052 = SP;
	} else {
	cppVar_75059 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75060 = (cppVar_75059 << 3) | 6;
	cppVar_75060 = (cppVar_75060 & cppMask_un_5_);
	cppVar_75061 = (0 << 5) | cppVar_75060;
	cppVar_75061 = (cppVar_75061 & cppMask_un_8_);
	cppVar_75063 = (cppVar_75061 == 130);
	if (cppVar_75063) {
	cppVar_75058 = DPL;
	} else {
	cppVar_75065 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75066 = (cppVar_75065 << 3) | 6;
	cppVar_75066 = (cppVar_75066 & cppMask_un_5_);
	cppVar_75067 = (0 << 5) | cppVar_75066;
	cppVar_75067 = (cppVar_75067 & cppMask_un_8_);
	cppVar_75069 = (cppVar_75067 == 131);
	if (cppVar_75069) {
	cppVar_75064 = DPH;
	} else {
	cppVar_75071 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75072 = (cppVar_75071 << 3) | 6;
	cppVar_75072 = (cppVar_75072 & cppMask_un_5_);
	cppVar_75073 = (0 << 5) | cppVar_75072;
	cppVar_75073 = (cppVar_75073 & cppMask_un_8_);
	cppVar_75075 = (cppVar_75073 == 135);
	if (cppVar_75075) {
	cppVar_75070 = PCON;
	} else {
	cppVar_75077 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75078 = (cppVar_75077 << 3) | 6;
	cppVar_75078 = (cppVar_75078 & cppMask_un_5_);
	cppVar_75079 = (0 << 5) | cppVar_75078;
	cppVar_75079 = (cppVar_75079 & cppMask_un_8_);
	cppVar_75081 = (cppVar_75079 == 136);
	if (cppVar_75081) {
	cppVar_75076 = TCON;
	} else {
	cppVar_75083 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75084 = (cppVar_75083 << 3) | 6;
	cppVar_75084 = (cppVar_75084 & cppMask_un_5_);
	cppVar_75085 = (0 << 5) | cppVar_75084;
	cppVar_75085 = (cppVar_75085 & cppMask_un_8_);
	cppVar_75087 = (cppVar_75085 == 137);
	if (cppVar_75087) {
	cppVar_75082 = TMOD;
	} else {
	cppVar_75089 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75090 = (cppVar_75089 << 3) | 6;
	cppVar_75090 = (cppVar_75090 & cppMask_un_5_);
	cppVar_75091 = (0 << 5) | cppVar_75090;
	cppVar_75091 = (cppVar_75091 & cppMask_un_8_);
	cppVar_75093 = (cppVar_75091 == 138);
	if (cppVar_75093) {
	cppVar_75088 = TL0;
	} else {
	cppVar_75095 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75096 = (cppVar_75095 << 3) | 6;
	cppVar_75096 = (cppVar_75096 & cppMask_un_5_);
	cppVar_75097 = (0 << 5) | cppVar_75096;
	cppVar_75097 = (cppVar_75097 & cppMask_un_8_);
	cppVar_75099 = (cppVar_75097 == 140);
	if (cppVar_75099) {
	cppVar_75094 = TH0;
	} else {
	cppVar_75101 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75102 = (cppVar_75101 << 3) | 6;
	cppVar_75102 = (cppVar_75102 & cppMask_un_5_);
	cppVar_75103 = (0 << 5) | cppVar_75102;
	cppVar_75103 = (cppVar_75103 & cppMask_un_8_);
	cppVar_75105 = (cppVar_75103 == 139);
	if (cppVar_75105) {
	cppVar_75100 = TL1;
	} else {
	cppVar_75107 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75108 = (cppVar_75107 << 3) | 6;
	cppVar_75108 = (cppVar_75108 & cppMask_un_5_);
	cppVar_75109 = (0 << 5) | cppVar_75108;
	cppVar_75109 = (cppVar_75109 & cppMask_un_8_);
	cppVar_75111 = (cppVar_75109 == 141);
	if (cppVar_75111) {
	cppVar_75106 = TH1;
	} else {
	cppVar_75113 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75114 = (cppVar_75113 << 3) | 6;
	cppVar_75114 = (cppVar_75114 & cppMask_un_5_);
	cppVar_75115 = (0 << 5) | cppVar_75114;
	cppVar_75115 = (cppVar_75115 & cppMask_un_8_);
	cppVar_75117 = (cppVar_75115 == 144);
	if (cppVar_75117) {
	cppVar_75112 = P1;
	} else {
	cppVar_75119 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75120 = (cppVar_75119 << 3) | 6;
	cppVar_75120 = (cppVar_75120 & cppMask_un_5_);
	cppVar_75121 = (0 << 5) | cppVar_75120;
	cppVar_75121 = (cppVar_75121 & cppMask_un_8_);
	cppVar_75123 = (cppVar_75121 == 152);
	if (cppVar_75123) {
	cppVar_75118 = SCON;
	} else {
	cppVar_75125 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75126 = (cppVar_75125 << 3) | 6;
	cppVar_75126 = (cppVar_75126 & cppMask_un_5_);
	cppVar_75127 = (0 << 5) | cppVar_75126;
	cppVar_75127 = (cppVar_75127 & cppMask_un_8_);
	cppVar_75129 = (cppVar_75127 == 153);
	if (cppVar_75129) {
	cppVar_75124 = SBUF;
	} else {
	cppVar_75131 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75132 = (cppVar_75131 << 3) | 6;
	cppVar_75132 = (cppVar_75132 & cppMask_un_5_);
	cppVar_75133 = (0 << 5) | cppVar_75132;
	cppVar_75133 = (cppVar_75133 & cppMask_un_8_);
	cppVar_75135 = (cppVar_75133 == 160);
	if (cppVar_75135) {
	cppVar_75130 = P2;
	} else {
	cppVar_75137 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75138 = (cppVar_75137 << 3) | 6;
	cppVar_75138 = (cppVar_75138 & cppMask_un_5_);
	cppVar_75139 = (0 << 5) | cppVar_75138;
	cppVar_75139 = (cppVar_75139 & cppMask_un_8_);
	cppVar_75141 = (cppVar_75139 == 168);
	if (cppVar_75141) {
	cppVar_75136 = IE;
	} else {
	cppVar_75143 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75144 = (cppVar_75143 << 3) | 6;
	cppVar_75144 = (cppVar_75144 & cppMask_un_5_);
	cppVar_75145 = (0 << 5) | cppVar_75144;
	cppVar_75145 = (cppVar_75145 & cppMask_un_8_);
	cppVar_75147 = (cppVar_75145 == 176);
	if (cppVar_75147) {
	cppVar_75142 = P3;
	} else {
	cppVar_75149 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75150 = (cppVar_75149 << 3) | 6;
	cppVar_75150 = (cppVar_75150 & cppMask_un_5_);
	cppVar_75151 = (0 << 5) | cppVar_75150;
	cppVar_75151 = (cppVar_75151 & cppMask_un_8_);
	cppVar_75153 = (cppVar_75151 == 184);
	if (cppVar_75153) {
	cppVar_75148 = IP;
	} else {
	cppVar_75155 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75156 = (cppVar_75155 << 3) | 6;
	cppVar_75156 = (cppVar_75156 & cppMask_un_5_);
	cppVar_75157 = (0 << 5) | cppVar_75156;
	cppVar_75157 = (cppVar_75157 & cppMask_un_8_);
	cppVar_75159 = (cppVar_75157 == 208);
	if (cppVar_75159) {
	cppVar_75154 = PSW;
	} else {
	cppVar_75161 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75162 = (cppVar_75161 << 3) | 6;
	cppVar_75162 = (cppVar_75162 & cppMask_un_5_);
	cppVar_75163 = (0 << 5) | cppVar_75162;
	cppVar_75163 = (cppVar_75163 & cppMask_un_8_);
	cppVar_75165 = (cppVar_75163 == 224);
	if (cppVar_75165) {
	cppVar_75160 = ACC;
	} else {
	cppVar_75167 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75168 = (cppVar_75167 << 3) | 6;
	cppVar_75168 = (cppVar_75168 & cppMask_un_5_);
	cppVar_75169 = (0 << 5) | cppVar_75168;
	cppVar_75169 = (cppVar_75169 & cppMask_un_8_);
	cppVar_75171 = (cppVar_75169 == 240);
	if (cppVar_75171) {
	cppVar_75166 = B;
	} else {
	cppVar_75166 = 0;
	}
	cppVar_75160 = cppVar_75166;
	}
	cppVar_75154 = cppVar_75160;
	}
	cppVar_75148 = cppVar_75154;
	}
	cppVar_75142 = cppVar_75148;
	}
	cppVar_75136 = cppVar_75142;
	}
	cppVar_75130 = cppVar_75136;
	}
	cppVar_75124 = cppVar_75130;
	}
	cppVar_75118 = cppVar_75124;
	}
	cppVar_75112 = cppVar_75118;
	}
	cppVar_75106 = cppVar_75112;
	}
	cppVar_75100 = cppVar_75106;
	}
	cppVar_75094 = cppVar_75100;
	}
	cppVar_75088 = cppVar_75094;
	}
	cppVar_75082 = cppVar_75088;
	}
	cppVar_75076 = cppVar_75082;
	}
	cppVar_75070 = cppVar_75076;
	}
	cppVar_75064 = cppVar_75070;
	}
	cppVar_75058 = cppVar_75064;
	}
	cppVar_75052 = cppVar_75058;
	}
	cppVar_75046 = cppVar_75052;
	}
	cppVar_75033 = cppVar_75046;
	}
	cppVar_75027 = cppVar_75033;
	} else {
	cppVar_75027 = TH1;
	}
	cppVar_75023 = cppVar_75027;
	} else {
	cppVar_75174 = ROM.rd(PC);
	cppVar_75176 = (cppVar_75174 == 141);
	if (cppVar_75176) {
	cppVar_75179 = PC + 1;
	cppVar_75179 = (cppVar_75179 & cppMask_un_16_);
	cppVar_75180 = ROM.rd(cppVar_75179);
	cppVar_75182 = (cppVar_75180 == 141);
	if (cppVar_75182) {
	cppVar_75185 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75187 = (cppVar_75185 << 3) | 5;
	cppVar_75187 = (cppVar_75187 & cppMask_un_5_);
	cppVar_75188 = (0 << 5) | cppVar_75187;
	cppVar_75188 = (cppVar_75188 & cppMask_un_8_);
	cppVar_75189 = (cppVar_75188 >> 7) & cppMask_un_1_;
	cppVar_75191 = (cppVar_75189 == 0);
	if (cppVar_75191) {
	cppVar_75192 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75193 = (cppVar_75192 << 3) | 5;
	cppVar_75193 = (cppVar_75193 & cppMask_un_5_);
	cppVar_75194 = (0 << 5) | cppVar_75193;
	cppVar_75194 = (cppVar_75194 & cppMask_un_8_);
	cppVar_75195 = IRAM.rd(cppVar_75194);
	cppVar_75183 = cppVar_75195;
	} else {
	cppVar_75197 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75198 = (cppVar_75197 << 3) | 5;
	cppVar_75198 = (cppVar_75198 & cppMask_un_5_);
	cppVar_75199 = (0 << 5) | cppVar_75198;
	cppVar_75199 = (cppVar_75199 & cppMask_un_8_);
	cppVar_75201 = (cppVar_75199 == 128);
	if (cppVar_75201) {
	cppVar_75196 = P0;
	} else {
	cppVar_75203 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75204 = (cppVar_75203 << 3) | 5;
	cppVar_75204 = (cppVar_75204 & cppMask_un_5_);
	cppVar_75205 = (0 << 5) | cppVar_75204;
	cppVar_75205 = (cppVar_75205 & cppMask_un_8_);
	cppVar_75207 = (cppVar_75205 == 129);
	if (cppVar_75207) {
	cppVar_75202 = SP;
	} else {
	cppVar_75209 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75210 = (cppVar_75209 << 3) | 5;
	cppVar_75210 = (cppVar_75210 & cppMask_un_5_);
	cppVar_75211 = (0 << 5) | cppVar_75210;
	cppVar_75211 = (cppVar_75211 & cppMask_un_8_);
	cppVar_75213 = (cppVar_75211 == 130);
	if (cppVar_75213) {
	cppVar_75208 = DPL;
	} else {
	cppVar_75215 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75216 = (cppVar_75215 << 3) | 5;
	cppVar_75216 = (cppVar_75216 & cppMask_un_5_);
	cppVar_75217 = (0 << 5) | cppVar_75216;
	cppVar_75217 = (cppVar_75217 & cppMask_un_8_);
	cppVar_75219 = (cppVar_75217 == 131);
	if (cppVar_75219) {
	cppVar_75214 = DPH;
	} else {
	cppVar_75221 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75222 = (cppVar_75221 << 3) | 5;
	cppVar_75222 = (cppVar_75222 & cppMask_un_5_);
	cppVar_75223 = (0 << 5) | cppVar_75222;
	cppVar_75223 = (cppVar_75223 & cppMask_un_8_);
	cppVar_75225 = (cppVar_75223 == 135);
	if (cppVar_75225) {
	cppVar_75220 = PCON;
	} else {
	cppVar_75227 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75228 = (cppVar_75227 << 3) | 5;
	cppVar_75228 = (cppVar_75228 & cppMask_un_5_);
	cppVar_75229 = (0 << 5) | cppVar_75228;
	cppVar_75229 = (cppVar_75229 & cppMask_un_8_);
	cppVar_75231 = (cppVar_75229 == 136);
	if (cppVar_75231) {
	cppVar_75226 = TCON;
	} else {
	cppVar_75233 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75234 = (cppVar_75233 << 3) | 5;
	cppVar_75234 = (cppVar_75234 & cppMask_un_5_);
	cppVar_75235 = (0 << 5) | cppVar_75234;
	cppVar_75235 = (cppVar_75235 & cppMask_un_8_);
	cppVar_75237 = (cppVar_75235 == 137);
	if (cppVar_75237) {
	cppVar_75232 = TMOD;
	} else {
	cppVar_75239 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75240 = (cppVar_75239 << 3) | 5;
	cppVar_75240 = (cppVar_75240 & cppMask_un_5_);
	cppVar_75241 = (0 << 5) | cppVar_75240;
	cppVar_75241 = (cppVar_75241 & cppMask_un_8_);
	cppVar_75243 = (cppVar_75241 == 138);
	if (cppVar_75243) {
	cppVar_75238 = TL0;
	} else {
	cppVar_75245 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75246 = (cppVar_75245 << 3) | 5;
	cppVar_75246 = (cppVar_75246 & cppMask_un_5_);
	cppVar_75247 = (0 << 5) | cppVar_75246;
	cppVar_75247 = (cppVar_75247 & cppMask_un_8_);
	cppVar_75249 = (cppVar_75247 == 140);
	if (cppVar_75249) {
	cppVar_75244 = TH0;
	} else {
	cppVar_75251 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75252 = (cppVar_75251 << 3) | 5;
	cppVar_75252 = (cppVar_75252 & cppMask_un_5_);
	cppVar_75253 = (0 << 5) | cppVar_75252;
	cppVar_75253 = (cppVar_75253 & cppMask_un_8_);
	cppVar_75255 = (cppVar_75253 == 139);
	if (cppVar_75255) {
	cppVar_75250 = TL1;
	} else {
	cppVar_75257 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75258 = (cppVar_75257 << 3) | 5;
	cppVar_75258 = (cppVar_75258 & cppMask_un_5_);
	cppVar_75259 = (0 << 5) | cppVar_75258;
	cppVar_75259 = (cppVar_75259 & cppMask_un_8_);
	cppVar_75261 = (cppVar_75259 == 141);
	if (cppVar_75261) {
	cppVar_75256 = TH1;
	} else {
	cppVar_75263 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75264 = (cppVar_75263 << 3) | 5;
	cppVar_75264 = (cppVar_75264 & cppMask_un_5_);
	cppVar_75265 = (0 << 5) | cppVar_75264;
	cppVar_75265 = (cppVar_75265 & cppMask_un_8_);
	cppVar_75267 = (cppVar_75265 == 144);
	if (cppVar_75267) {
	cppVar_75262 = P1;
	} else {
	cppVar_75269 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75270 = (cppVar_75269 << 3) | 5;
	cppVar_75270 = (cppVar_75270 & cppMask_un_5_);
	cppVar_75271 = (0 << 5) | cppVar_75270;
	cppVar_75271 = (cppVar_75271 & cppMask_un_8_);
	cppVar_75273 = (cppVar_75271 == 152);
	if (cppVar_75273) {
	cppVar_75268 = SCON;
	} else {
	cppVar_75275 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75276 = (cppVar_75275 << 3) | 5;
	cppVar_75276 = (cppVar_75276 & cppMask_un_5_);
	cppVar_75277 = (0 << 5) | cppVar_75276;
	cppVar_75277 = (cppVar_75277 & cppMask_un_8_);
	cppVar_75279 = (cppVar_75277 == 153);
	if (cppVar_75279) {
	cppVar_75274 = SBUF;
	} else {
	cppVar_75281 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75282 = (cppVar_75281 << 3) | 5;
	cppVar_75282 = (cppVar_75282 & cppMask_un_5_);
	cppVar_75283 = (0 << 5) | cppVar_75282;
	cppVar_75283 = (cppVar_75283 & cppMask_un_8_);
	cppVar_75285 = (cppVar_75283 == 160);
	if (cppVar_75285) {
	cppVar_75280 = P2;
	} else {
	cppVar_75287 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75288 = (cppVar_75287 << 3) | 5;
	cppVar_75288 = (cppVar_75288 & cppMask_un_5_);
	cppVar_75289 = (0 << 5) | cppVar_75288;
	cppVar_75289 = (cppVar_75289 & cppMask_un_8_);
	cppVar_75291 = (cppVar_75289 == 168);
	if (cppVar_75291) {
	cppVar_75286 = IE;
	} else {
	cppVar_75293 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75294 = (cppVar_75293 << 3) | 5;
	cppVar_75294 = (cppVar_75294 & cppMask_un_5_);
	cppVar_75295 = (0 << 5) | cppVar_75294;
	cppVar_75295 = (cppVar_75295 & cppMask_un_8_);
	cppVar_75297 = (cppVar_75295 == 176);
	if (cppVar_75297) {
	cppVar_75292 = P3;
	} else {
	cppVar_75299 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75300 = (cppVar_75299 << 3) | 5;
	cppVar_75300 = (cppVar_75300 & cppMask_un_5_);
	cppVar_75301 = (0 << 5) | cppVar_75300;
	cppVar_75301 = (cppVar_75301 & cppMask_un_8_);
	cppVar_75303 = (cppVar_75301 == 184);
	if (cppVar_75303) {
	cppVar_75298 = IP;
	} else {
	cppVar_75305 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75306 = (cppVar_75305 << 3) | 5;
	cppVar_75306 = (cppVar_75306 & cppMask_un_5_);
	cppVar_75307 = (0 << 5) | cppVar_75306;
	cppVar_75307 = (cppVar_75307 & cppMask_un_8_);
	cppVar_75309 = (cppVar_75307 == 208);
	if (cppVar_75309) {
	cppVar_75304 = PSW;
	} else {
	cppVar_75311 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75312 = (cppVar_75311 << 3) | 5;
	cppVar_75312 = (cppVar_75312 & cppMask_un_5_);
	cppVar_75313 = (0 << 5) | cppVar_75312;
	cppVar_75313 = (cppVar_75313 & cppMask_un_8_);
	cppVar_75315 = (cppVar_75313 == 224);
	if (cppVar_75315) {
	cppVar_75310 = ACC;
	} else {
	cppVar_75317 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75318 = (cppVar_75317 << 3) | 5;
	cppVar_75318 = (cppVar_75318 & cppMask_un_5_);
	cppVar_75319 = (0 << 5) | cppVar_75318;
	cppVar_75319 = (cppVar_75319 & cppMask_un_8_);
	cppVar_75321 = (cppVar_75319 == 240);
	if (cppVar_75321) {
	cppVar_75316 = B;
	} else {
	cppVar_75316 = 0;
	}
	cppVar_75310 = cppVar_75316;
	}
	cppVar_75304 = cppVar_75310;
	}
	cppVar_75298 = cppVar_75304;
	}
	cppVar_75292 = cppVar_75298;
	}
	cppVar_75286 = cppVar_75292;
	}
	cppVar_75280 = cppVar_75286;
	}
	cppVar_75274 = cppVar_75280;
	}
	cppVar_75268 = cppVar_75274;
	}
	cppVar_75262 = cppVar_75268;
	}
	cppVar_75256 = cppVar_75262;
	}
	cppVar_75250 = cppVar_75256;
	}
	cppVar_75244 = cppVar_75250;
	}
	cppVar_75238 = cppVar_75244;
	}
	cppVar_75232 = cppVar_75238;
	}
	cppVar_75226 = cppVar_75232;
	}
	cppVar_75220 = cppVar_75226;
	}
	cppVar_75214 = cppVar_75220;
	}
	cppVar_75208 = cppVar_75214;
	}
	cppVar_75202 = cppVar_75208;
	}
	cppVar_75196 = cppVar_75202;
	}
	cppVar_75183 = cppVar_75196;
	}
	cppVar_75177 = cppVar_75183;
	} else {
	cppVar_75177 = TH1;
	}
	cppVar_75173 = cppVar_75177;
	} else {
	cppVar_75324 = ROM.rd(PC);
	cppVar_75326 = (cppVar_75324 == 140);
	if (cppVar_75326) {
	cppVar_75329 = PC + 1;
	cppVar_75329 = (cppVar_75329 & cppMask_un_16_);
	cppVar_75330 = ROM.rd(cppVar_75329);
	cppVar_75332 = (cppVar_75330 == 141);
	if (cppVar_75332) {
	cppVar_75335 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75337 = (cppVar_75335 << 3) | 4;
	cppVar_75337 = (cppVar_75337 & cppMask_un_5_);
	cppVar_75338 = (0 << 5) | cppVar_75337;
	cppVar_75338 = (cppVar_75338 & cppMask_un_8_);
	cppVar_75339 = (cppVar_75338 >> 7) & cppMask_un_1_;
	cppVar_75341 = (cppVar_75339 == 0);
	if (cppVar_75341) {
	cppVar_75342 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75343 = (cppVar_75342 << 3) | 4;
	cppVar_75343 = (cppVar_75343 & cppMask_un_5_);
	cppVar_75344 = (0 << 5) | cppVar_75343;
	cppVar_75344 = (cppVar_75344 & cppMask_un_8_);
	cppVar_75345 = IRAM.rd(cppVar_75344);
	cppVar_75333 = cppVar_75345;
	} else {
	cppVar_75347 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75348 = (cppVar_75347 << 3) | 4;
	cppVar_75348 = (cppVar_75348 & cppMask_un_5_);
	cppVar_75349 = (0 << 5) | cppVar_75348;
	cppVar_75349 = (cppVar_75349 & cppMask_un_8_);
	cppVar_75351 = (cppVar_75349 == 128);
	if (cppVar_75351) {
	cppVar_75346 = P0;
	} else {
	cppVar_75353 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75354 = (cppVar_75353 << 3) | 4;
	cppVar_75354 = (cppVar_75354 & cppMask_un_5_);
	cppVar_75355 = (0 << 5) | cppVar_75354;
	cppVar_75355 = (cppVar_75355 & cppMask_un_8_);
	cppVar_75357 = (cppVar_75355 == 129);
	if (cppVar_75357) {
	cppVar_75352 = SP;
	} else {
	cppVar_75359 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75360 = (cppVar_75359 << 3) | 4;
	cppVar_75360 = (cppVar_75360 & cppMask_un_5_);
	cppVar_75361 = (0 << 5) | cppVar_75360;
	cppVar_75361 = (cppVar_75361 & cppMask_un_8_);
	cppVar_75363 = (cppVar_75361 == 130);
	if (cppVar_75363) {
	cppVar_75358 = DPL;
	} else {
	cppVar_75365 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75366 = (cppVar_75365 << 3) | 4;
	cppVar_75366 = (cppVar_75366 & cppMask_un_5_);
	cppVar_75367 = (0 << 5) | cppVar_75366;
	cppVar_75367 = (cppVar_75367 & cppMask_un_8_);
	cppVar_75369 = (cppVar_75367 == 131);
	if (cppVar_75369) {
	cppVar_75364 = DPH;
	} else {
	cppVar_75371 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75372 = (cppVar_75371 << 3) | 4;
	cppVar_75372 = (cppVar_75372 & cppMask_un_5_);
	cppVar_75373 = (0 << 5) | cppVar_75372;
	cppVar_75373 = (cppVar_75373 & cppMask_un_8_);
	cppVar_75375 = (cppVar_75373 == 135);
	if (cppVar_75375) {
	cppVar_75370 = PCON;
	} else {
	cppVar_75377 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75378 = (cppVar_75377 << 3) | 4;
	cppVar_75378 = (cppVar_75378 & cppMask_un_5_);
	cppVar_75379 = (0 << 5) | cppVar_75378;
	cppVar_75379 = (cppVar_75379 & cppMask_un_8_);
	cppVar_75381 = (cppVar_75379 == 136);
	if (cppVar_75381) {
	cppVar_75376 = TCON;
	} else {
	cppVar_75383 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75384 = (cppVar_75383 << 3) | 4;
	cppVar_75384 = (cppVar_75384 & cppMask_un_5_);
	cppVar_75385 = (0 << 5) | cppVar_75384;
	cppVar_75385 = (cppVar_75385 & cppMask_un_8_);
	cppVar_75387 = (cppVar_75385 == 137);
	if (cppVar_75387) {
	cppVar_75382 = TMOD;
	} else {
	cppVar_75389 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75390 = (cppVar_75389 << 3) | 4;
	cppVar_75390 = (cppVar_75390 & cppMask_un_5_);
	cppVar_75391 = (0 << 5) | cppVar_75390;
	cppVar_75391 = (cppVar_75391 & cppMask_un_8_);
	cppVar_75393 = (cppVar_75391 == 138);
	if (cppVar_75393) {
	cppVar_75388 = TL0;
	} else {
	cppVar_75395 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75396 = (cppVar_75395 << 3) | 4;
	cppVar_75396 = (cppVar_75396 & cppMask_un_5_);
	cppVar_75397 = (0 << 5) | cppVar_75396;
	cppVar_75397 = (cppVar_75397 & cppMask_un_8_);
	cppVar_75399 = (cppVar_75397 == 140);
	if (cppVar_75399) {
	cppVar_75394 = TH0;
	} else {
	cppVar_75401 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75402 = (cppVar_75401 << 3) | 4;
	cppVar_75402 = (cppVar_75402 & cppMask_un_5_);
	cppVar_75403 = (0 << 5) | cppVar_75402;
	cppVar_75403 = (cppVar_75403 & cppMask_un_8_);
	cppVar_75405 = (cppVar_75403 == 139);
	if (cppVar_75405) {
	cppVar_75400 = TL1;
	} else {
	cppVar_75407 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75408 = (cppVar_75407 << 3) | 4;
	cppVar_75408 = (cppVar_75408 & cppMask_un_5_);
	cppVar_75409 = (0 << 5) | cppVar_75408;
	cppVar_75409 = (cppVar_75409 & cppMask_un_8_);
	cppVar_75411 = (cppVar_75409 == 141);
	if (cppVar_75411) {
	cppVar_75406 = TH1;
	} else {
	cppVar_75413 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75414 = (cppVar_75413 << 3) | 4;
	cppVar_75414 = (cppVar_75414 & cppMask_un_5_);
	cppVar_75415 = (0 << 5) | cppVar_75414;
	cppVar_75415 = (cppVar_75415 & cppMask_un_8_);
	cppVar_75417 = (cppVar_75415 == 144);
	if (cppVar_75417) {
	cppVar_75412 = P1;
	} else {
	cppVar_75419 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75420 = (cppVar_75419 << 3) | 4;
	cppVar_75420 = (cppVar_75420 & cppMask_un_5_);
	cppVar_75421 = (0 << 5) | cppVar_75420;
	cppVar_75421 = (cppVar_75421 & cppMask_un_8_);
	cppVar_75423 = (cppVar_75421 == 152);
	if (cppVar_75423) {
	cppVar_75418 = SCON;
	} else {
	cppVar_75425 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75426 = (cppVar_75425 << 3) | 4;
	cppVar_75426 = (cppVar_75426 & cppMask_un_5_);
	cppVar_75427 = (0 << 5) | cppVar_75426;
	cppVar_75427 = (cppVar_75427 & cppMask_un_8_);
	cppVar_75429 = (cppVar_75427 == 153);
	if (cppVar_75429) {
	cppVar_75424 = SBUF;
	} else {
	cppVar_75431 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75432 = (cppVar_75431 << 3) | 4;
	cppVar_75432 = (cppVar_75432 & cppMask_un_5_);
	cppVar_75433 = (0 << 5) | cppVar_75432;
	cppVar_75433 = (cppVar_75433 & cppMask_un_8_);
	cppVar_75435 = (cppVar_75433 == 160);
	if (cppVar_75435) {
	cppVar_75430 = P2;
	} else {
	cppVar_75437 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75438 = (cppVar_75437 << 3) | 4;
	cppVar_75438 = (cppVar_75438 & cppMask_un_5_);
	cppVar_75439 = (0 << 5) | cppVar_75438;
	cppVar_75439 = (cppVar_75439 & cppMask_un_8_);
	cppVar_75441 = (cppVar_75439 == 168);
	if (cppVar_75441) {
	cppVar_75436 = IE;
	} else {
	cppVar_75443 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75444 = (cppVar_75443 << 3) | 4;
	cppVar_75444 = (cppVar_75444 & cppMask_un_5_);
	cppVar_75445 = (0 << 5) | cppVar_75444;
	cppVar_75445 = (cppVar_75445 & cppMask_un_8_);
	cppVar_75447 = (cppVar_75445 == 176);
	if (cppVar_75447) {
	cppVar_75442 = P3;
	} else {
	cppVar_75449 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75450 = (cppVar_75449 << 3) | 4;
	cppVar_75450 = (cppVar_75450 & cppMask_un_5_);
	cppVar_75451 = (0 << 5) | cppVar_75450;
	cppVar_75451 = (cppVar_75451 & cppMask_un_8_);
	cppVar_75453 = (cppVar_75451 == 184);
	if (cppVar_75453) {
	cppVar_75448 = IP;
	} else {
	cppVar_75455 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75456 = (cppVar_75455 << 3) | 4;
	cppVar_75456 = (cppVar_75456 & cppMask_un_5_);
	cppVar_75457 = (0 << 5) | cppVar_75456;
	cppVar_75457 = (cppVar_75457 & cppMask_un_8_);
	cppVar_75459 = (cppVar_75457 == 208);
	if (cppVar_75459) {
	cppVar_75454 = PSW;
	} else {
	cppVar_75461 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75462 = (cppVar_75461 << 3) | 4;
	cppVar_75462 = (cppVar_75462 & cppMask_un_5_);
	cppVar_75463 = (0 << 5) | cppVar_75462;
	cppVar_75463 = (cppVar_75463 & cppMask_un_8_);
	cppVar_75465 = (cppVar_75463 == 224);
	if (cppVar_75465) {
	cppVar_75460 = ACC;
	} else {
	cppVar_75467 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75468 = (cppVar_75467 << 3) | 4;
	cppVar_75468 = (cppVar_75468 & cppMask_un_5_);
	cppVar_75469 = (0 << 5) | cppVar_75468;
	cppVar_75469 = (cppVar_75469 & cppMask_un_8_);
	cppVar_75471 = (cppVar_75469 == 240);
	if (cppVar_75471) {
	cppVar_75466 = B;
	} else {
	cppVar_75466 = 0;
	}
	cppVar_75460 = cppVar_75466;
	}
	cppVar_75454 = cppVar_75460;
	}
	cppVar_75448 = cppVar_75454;
	}
	cppVar_75442 = cppVar_75448;
	}
	cppVar_75436 = cppVar_75442;
	}
	cppVar_75430 = cppVar_75436;
	}
	cppVar_75424 = cppVar_75430;
	}
	cppVar_75418 = cppVar_75424;
	}
	cppVar_75412 = cppVar_75418;
	}
	cppVar_75406 = cppVar_75412;
	}
	cppVar_75400 = cppVar_75406;
	}
	cppVar_75394 = cppVar_75400;
	}
	cppVar_75388 = cppVar_75394;
	}
	cppVar_75382 = cppVar_75388;
	}
	cppVar_75376 = cppVar_75382;
	}
	cppVar_75370 = cppVar_75376;
	}
	cppVar_75364 = cppVar_75370;
	}
	cppVar_75358 = cppVar_75364;
	}
	cppVar_75352 = cppVar_75358;
	}
	cppVar_75346 = cppVar_75352;
	}
	cppVar_75333 = cppVar_75346;
	}
	cppVar_75327 = cppVar_75333;
	} else {
	cppVar_75327 = TH1;
	}
	cppVar_75323 = cppVar_75327;
	} else {
	cppVar_75474 = ROM.rd(PC);
	cppVar_75476 = (cppVar_75474 == 139);
	if (cppVar_75476) {
	cppVar_75479 = PC + 1;
	cppVar_75479 = (cppVar_75479 & cppMask_un_16_);
	cppVar_75480 = ROM.rd(cppVar_75479);
	cppVar_75482 = (cppVar_75480 == 141);
	if (cppVar_75482) {
	cppVar_75485 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75487 = (cppVar_75485 << 3) | 3;
	cppVar_75487 = (cppVar_75487 & cppMask_un_5_);
	cppVar_75488 = (0 << 5) | cppVar_75487;
	cppVar_75488 = (cppVar_75488 & cppMask_un_8_);
	cppVar_75489 = (cppVar_75488 >> 7) & cppMask_un_1_;
	cppVar_75491 = (cppVar_75489 == 0);
	if (cppVar_75491) {
	cppVar_75492 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75493 = (cppVar_75492 << 3) | 3;
	cppVar_75493 = (cppVar_75493 & cppMask_un_5_);
	cppVar_75494 = (0 << 5) | cppVar_75493;
	cppVar_75494 = (cppVar_75494 & cppMask_un_8_);
	cppVar_75495 = IRAM.rd(cppVar_75494);
	cppVar_75483 = cppVar_75495;
	} else {
	cppVar_75497 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75498 = (cppVar_75497 << 3) | 3;
	cppVar_75498 = (cppVar_75498 & cppMask_un_5_);
	cppVar_75499 = (0 << 5) | cppVar_75498;
	cppVar_75499 = (cppVar_75499 & cppMask_un_8_);
	cppVar_75501 = (cppVar_75499 == 128);
	if (cppVar_75501) {
	cppVar_75496 = P0;
	} else {
	cppVar_75503 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75504 = (cppVar_75503 << 3) | 3;
	cppVar_75504 = (cppVar_75504 & cppMask_un_5_);
	cppVar_75505 = (0 << 5) | cppVar_75504;
	cppVar_75505 = (cppVar_75505 & cppMask_un_8_);
	cppVar_75507 = (cppVar_75505 == 129);
	if (cppVar_75507) {
	cppVar_75502 = SP;
	} else {
	cppVar_75509 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75510 = (cppVar_75509 << 3) | 3;
	cppVar_75510 = (cppVar_75510 & cppMask_un_5_);
	cppVar_75511 = (0 << 5) | cppVar_75510;
	cppVar_75511 = (cppVar_75511 & cppMask_un_8_);
	cppVar_75513 = (cppVar_75511 == 130);
	if (cppVar_75513) {
	cppVar_75508 = DPL;
	} else {
	cppVar_75515 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75516 = (cppVar_75515 << 3) | 3;
	cppVar_75516 = (cppVar_75516 & cppMask_un_5_);
	cppVar_75517 = (0 << 5) | cppVar_75516;
	cppVar_75517 = (cppVar_75517 & cppMask_un_8_);
	cppVar_75519 = (cppVar_75517 == 131);
	if (cppVar_75519) {
	cppVar_75514 = DPH;
	} else {
	cppVar_75521 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75522 = (cppVar_75521 << 3) | 3;
	cppVar_75522 = (cppVar_75522 & cppMask_un_5_);
	cppVar_75523 = (0 << 5) | cppVar_75522;
	cppVar_75523 = (cppVar_75523 & cppMask_un_8_);
	cppVar_75525 = (cppVar_75523 == 135);
	if (cppVar_75525) {
	cppVar_75520 = PCON;
	} else {
	cppVar_75527 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75528 = (cppVar_75527 << 3) | 3;
	cppVar_75528 = (cppVar_75528 & cppMask_un_5_);
	cppVar_75529 = (0 << 5) | cppVar_75528;
	cppVar_75529 = (cppVar_75529 & cppMask_un_8_);
	cppVar_75531 = (cppVar_75529 == 136);
	if (cppVar_75531) {
	cppVar_75526 = TCON;
	} else {
	cppVar_75533 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75534 = (cppVar_75533 << 3) | 3;
	cppVar_75534 = (cppVar_75534 & cppMask_un_5_);
	cppVar_75535 = (0 << 5) | cppVar_75534;
	cppVar_75535 = (cppVar_75535 & cppMask_un_8_);
	cppVar_75537 = (cppVar_75535 == 137);
	if (cppVar_75537) {
	cppVar_75532 = TMOD;
	} else {
	cppVar_75539 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75540 = (cppVar_75539 << 3) | 3;
	cppVar_75540 = (cppVar_75540 & cppMask_un_5_);
	cppVar_75541 = (0 << 5) | cppVar_75540;
	cppVar_75541 = (cppVar_75541 & cppMask_un_8_);
	cppVar_75543 = (cppVar_75541 == 138);
	if (cppVar_75543) {
	cppVar_75538 = TL0;
	} else {
	cppVar_75545 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75546 = (cppVar_75545 << 3) | 3;
	cppVar_75546 = (cppVar_75546 & cppMask_un_5_);
	cppVar_75547 = (0 << 5) | cppVar_75546;
	cppVar_75547 = (cppVar_75547 & cppMask_un_8_);
	cppVar_75549 = (cppVar_75547 == 140);
	if (cppVar_75549) {
	cppVar_75544 = TH0;
	} else {
	cppVar_75551 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75552 = (cppVar_75551 << 3) | 3;
	cppVar_75552 = (cppVar_75552 & cppMask_un_5_);
	cppVar_75553 = (0 << 5) | cppVar_75552;
	cppVar_75553 = (cppVar_75553 & cppMask_un_8_);
	cppVar_75555 = (cppVar_75553 == 139);
	if (cppVar_75555) {
	cppVar_75550 = TL1;
	} else {
	cppVar_75557 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75558 = (cppVar_75557 << 3) | 3;
	cppVar_75558 = (cppVar_75558 & cppMask_un_5_);
	cppVar_75559 = (0 << 5) | cppVar_75558;
	cppVar_75559 = (cppVar_75559 & cppMask_un_8_);
	cppVar_75561 = (cppVar_75559 == 141);
	if (cppVar_75561) {
	cppVar_75556 = TH1;
	} else {
	cppVar_75563 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75564 = (cppVar_75563 << 3) | 3;
	cppVar_75564 = (cppVar_75564 & cppMask_un_5_);
	cppVar_75565 = (0 << 5) | cppVar_75564;
	cppVar_75565 = (cppVar_75565 & cppMask_un_8_);
	cppVar_75567 = (cppVar_75565 == 144);
	if (cppVar_75567) {
	cppVar_75562 = P1;
	} else {
	cppVar_75569 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75570 = (cppVar_75569 << 3) | 3;
	cppVar_75570 = (cppVar_75570 & cppMask_un_5_);
	cppVar_75571 = (0 << 5) | cppVar_75570;
	cppVar_75571 = (cppVar_75571 & cppMask_un_8_);
	cppVar_75573 = (cppVar_75571 == 152);
	if (cppVar_75573) {
	cppVar_75568 = SCON;
	} else {
	cppVar_75575 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75576 = (cppVar_75575 << 3) | 3;
	cppVar_75576 = (cppVar_75576 & cppMask_un_5_);
	cppVar_75577 = (0 << 5) | cppVar_75576;
	cppVar_75577 = (cppVar_75577 & cppMask_un_8_);
	cppVar_75579 = (cppVar_75577 == 153);
	if (cppVar_75579) {
	cppVar_75574 = SBUF;
	} else {
	cppVar_75581 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75582 = (cppVar_75581 << 3) | 3;
	cppVar_75582 = (cppVar_75582 & cppMask_un_5_);
	cppVar_75583 = (0 << 5) | cppVar_75582;
	cppVar_75583 = (cppVar_75583 & cppMask_un_8_);
	cppVar_75585 = (cppVar_75583 == 160);
	if (cppVar_75585) {
	cppVar_75580 = P2;
	} else {
	cppVar_75587 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75588 = (cppVar_75587 << 3) | 3;
	cppVar_75588 = (cppVar_75588 & cppMask_un_5_);
	cppVar_75589 = (0 << 5) | cppVar_75588;
	cppVar_75589 = (cppVar_75589 & cppMask_un_8_);
	cppVar_75591 = (cppVar_75589 == 168);
	if (cppVar_75591) {
	cppVar_75586 = IE;
	} else {
	cppVar_75593 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75594 = (cppVar_75593 << 3) | 3;
	cppVar_75594 = (cppVar_75594 & cppMask_un_5_);
	cppVar_75595 = (0 << 5) | cppVar_75594;
	cppVar_75595 = (cppVar_75595 & cppMask_un_8_);
	cppVar_75597 = (cppVar_75595 == 176);
	if (cppVar_75597) {
	cppVar_75592 = P3;
	} else {
	cppVar_75599 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75600 = (cppVar_75599 << 3) | 3;
	cppVar_75600 = (cppVar_75600 & cppMask_un_5_);
	cppVar_75601 = (0 << 5) | cppVar_75600;
	cppVar_75601 = (cppVar_75601 & cppMask_un_8_);
	cppVar_75603 = (cppVar_75601 == 184);
	if (cppVar_75603) {
	cppVar_75598 = IP;
	} else {
	cppVar_75605 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75606 = (cppVar_75605 << 3) | 3;
	cppVar_75606 = (cppVar_75606 & cppMask_un_5_);
	cppVar_75607 = (0 << 5) | cppVar_75606;
	cppVar_75607 = (cppVar_75607 & cppMask_un_8_);
	cppVar_75609 = (cppVar_75607 == 208);
	if (cppVar_75609) {
	cppVar_75604 = PSW;
	} else {
	cppVar_75611 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75612 = (cppVar_75611 << 3) | 3;
	cppVar_75612 = (cppVar_75612 & cppMask_un_5_);
	cppVar_75613 = (0 << 5) | cppVar_75612;
	cppVar_75613 = (cppVar_75613 & cppMask_un_8_);
	cppVar_75615 = (cppVar_75613 == 224);
	if (cppVar_75615) {
	cppVar_75610 = ACC;
	} else {
	cppVar_75617 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75618 = (cppVar_75617 << 3) | 3;
	cppVar_75618 = (cppVar_75618 & cppMask_un_5_);
	cppVar_75619 = (0 << 5) | cppVar_75618;
	cppVar_75619 = (cppVar_75619 & cppMask_un_8_);
	cppVar_75621 = (cppVar_75619 == 240);
	if (cppVar_75621) {
	cppVar_75616 = B;
	} else {
	cppVar_75616 = 0;
	}
	cppVar_75610 = cppVar_75616;
	}
	cppVar_75604 = cppVar_75610;
	}
	cppVar_75598 = cppVar_75604;
	}
	cppVar_75592 = cppVar_75598;
	}
	cppVar_75586 = cppVar_75592;
	}
	cppVar_75580 = cppVar_75586;
	}
	cppVar_75574 = cppVar_75580;
	}
	cppVar_75568 = cppVar_75574;
	}
	cppVar_75562 = cppVar_75568;
	}
	cppVar_75556 = cppVar_75562;
	}
	cppVar_75550 = cppVar_75556;
	}
	cppVar_75544 = cppVar_75550;
	}
	cppVar_75538 = cppVar_75544;
	}
	cppVar_75532 = cppVar_75538;
	}
	cppVar_75526 = cppVar_75532;
	}
	cppVar_75520 = cppVar_75526;
	}
	cppVar_75514 = cppVar_75520;
	}
	cppVar_75508 = cppVar_75514;
	}
	cppVar_75502 = cppVar_75508;
	}
	cppVar_75496 = cppVar_75502;
	}
	cppVar_75483 = cppVar_75496;
	}
	cppVar_75477 = cppVar_75483;
	} else {
	cppVar_75477 = TH1;
	}
	cppVar_75473 = cppVar_75477;
	} else {
	cppVar_75624 = ROM.rd(PC);
	cppVar_75626 = (cppVar_75624 == 138);
	if (cppVar_75626) {
	cppVar_75629 = PC + 1;
	cppVar_75629 = (cppVar_75629 & cppMask_un_16_);
	cppVar_75630 = ROM.rd(cppVar_75629);
	cppVar_75632 = (cppVar_75630 == 141);
	if (cppVar_75632) {
	cppVar_75635 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75637 = (cppVar_75635 << 3) | 2;
	cppVar_75637 = (cppVar_75637 & cppMask_un_5_);
	cppVar_75638 = (0 << 5) | cppVar_75637;
	cppVar_75638 = (cppVar_75638 & cppMask_un_8_);
	cppVar_75639 = (cppVar_75638 >> 7) & cppMask_un_1_;
	cppVar_75641 = (cppVar_75639 == 0);
	if (cppVar_75641) {
	cppVar_75642 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75643 = (cppVar_75642 << 3) | 2;
	cppVar_75643 = (cppVar_75643 & cppMask_un_5_);
	cppVar_75644 = (0 << 5) | cppVar_75643;
	cppVar_75644 = (cppVar_75644 & cppMask_un_8_);
	cppVar_75645 = IRAM.rd(cppVar_75644);
	cppVar_75633 = cppVar_75645;
	} else {
	cppVar_75647 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75648 = (cppVar_75647 << 3) | 2;
	cppVar_75648 = (cppVar_75648 & cppMask_un_5_);
	cppVar_75649 = (0 << 5) | cppVar_75648;
	cppVar_75649 = (cppVar_75649 & cppMask_un_8_);
	cppVar_75651 = (cppVar_75649 == 128);
	if (cppVar_75651) {
	cppVar_75646 = P0;
	} else {
	cppVar_75653 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75654 = (cppVar_75653 << 3) | 2;
	cppVar_75654 = (cppVar_75654 & cppMask_un_5_);
	cppVar_75655 = (0 << 5) | cppVar_75654;
	cppVar_75655 = (cppVar_75655 & cppMask_un_8_);
	cppVar_75657 = (cppVar_75655 == 129);
	if (cppVar_75657) {
	cppVar_75652 = SP;
	} else {
	cppVar_75659 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75660 = (cppVar_75659 << 3) | 2;
	cppVar_75660 = (cppVar_75660 & cppMask_un_5_);
	cppVar_75661 = (0 << 5) | cppVar_75660;
	cppVar_75661 = (cppVar_75661 & cppMask_un_8_);
	cppVar_75663 = (cppVar_75661 == 130);
	if (cppVar_75663) {
	cppVar_75658 = DPL;
	} else {
	cppVar_75665 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75666 = (cppVar_75665 << 3) | 2;
	cppVar_75666 = (cppVar_75666 & cppMask_un_5_);
	cppVar_75667 = (0 << 5) | cppVar_75666;
	cppVar_75667 = (cppVar_75667 & cppMask_un_8_);
	cppVar_75669 = (cppVar_75667 == 131);
	if (cppVar_75669) {
	cppVar_75664 = DPH;
	} else {
	cppVar_75671 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75672 = (cppVar_75671 << 3) | 2;
	cppVar_75672 = (cppVar_75672 & cppMask_un_5_);
	cppVar_75673 = (0 << 5) | cppVar_75672;
	cppVar_75673 = (cppVar_75673 & cppMask_un_8_);
	cppVar_75675 = (cppVar_75673 == 135);
	if (cppVar_75675) {
	cppVar_75670 = PCON;
	} else {
	cppVar_75677 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75678 = (cppVar_75677 << 3) | 2;
	cppVar_75678 = (cppVar_75678 & cppMask_un_5_);
	cppVar_75679 = (0 << 5) | cppVar_75678;
	cppVar_75679 = (cppVar_75679 & cppMask_un_8_);
	cppVar_75681 = (cppVar_75679 == 136);
	if (cppVar_75681) {
	cppVar_75676 = TCON;
	} else {
	cppVar_75683 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75684 = (cppVar_75683 << 3) | 2;
	cppVar_75684 = (cppVar_75684 & cppMask_un_5_);
	cppVar_75685 = (0 << 5) | cppVar_75684;
	cppVar_75685 = (cppVar_75685 & cppMask_un_8_);
	cppVar_75687 = (cppVar_75685 == 137);
	if (cppVar_75687) {
	cppVar_75682 = TMOD;
	} else {
	cppVar_75689 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75690 = (cppVar_75689 << 3) | 2;
	cppVar_75690 = (cppVar_75690 & cppMask_un_5_);
	cppVar_75691 = (0 << 5) | cppVar_75690;
	cppVar_75691 = (cppVar_75691 & cppMask_un_8_);
	cppVar_75693 = (cppVar_75691 == 138);
	if (cppVar_75693) {
	cppVar_75688 = TL0;
	} else {
	cppVar_75695 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75696 = (cppVar_75695 << 3) | 2;
	cppVar_75696 = (cppVar_75696 & cppMask_un_5_);
	cppVar_75697 = (0 << 5) | cppVar_75696;
	cppVar_75697 = (cppVar_75697 & cppMask_un_8_);
	cppVar_75699 = (cppVar_75697 == 140);
	if (cppVar_75699) {
	cppVar_75694 = TH0;
	} else {
	cppVar_75701 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75702 = (cppVar_75701 << 3) | 2;
	cppVar_75702 = (cppVar_75702 & cppMask_un_5_);
	cppVar_75703 = (0 << 5) | cppVar_75702;
	cppVar_75703 = (cppVar_75703 & cppMask_un_8_);
	cppVar_75705 = (cppVar_75703 == 139);
	if (cppVar_75705) {
	cppVar_75700 = TL1;
	} else {
	cppVar_75707 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75708 = (cppVar_75707 << 3) | 2;
	cppVar_75708 = (cppVar_75708 & cppMask_un_5_);
	cppVar_75709 = (0 << 5) | cppVar_75708;
	cppVar_75709 = (cppVar_75709 & cppMask_un_8_);
	cppVar_75711 = (cppVar_75709 == 141);
	if (cppVar_75711) {
	cppVar_75706 = TH1;
	} else {
	cppVar_75713 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75714 = (cppVar_75713 << 3) | 2;
	cppVar_75714 = (cppVar_75714 & cppMask_un_5_);
	cppVar_75715 = (0 << 5) | cppVar_75714;
	cppVar_75715 = (cppVar_75715 & cppMask_un_8_);
	cppVar_75717 = (cppVar_75715 == 144);
	if (cppVar_75717) {
	cppVar_75712 = P1;
	} else {
	cppVar_75719 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75720 = (cppVar_75719 << 3) | 2;
	cppVar_75720 = (cppVar_75720 & cppMask_un_5_);
	cppVar_75721 = (0 << 5) | cppVar_75720;
	cppVar_75721 = (cppVar_75721 & cppMask_un_8_);
	cppVar_75723 = (cppVar_75721 == 152);
	if (cppVar_75723) {
	cppVar_75718 = SCON;
	} else {
	cppVar_75725 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75726 = (cppVar_75725 << 3) | 2;
	cppVar_75726 = (cppVar_75726 & cppMask_un_5_);
	cppVar_75727 = (0 << 5) | cppVar_75726;
	cppVar_75727 = (cppVar_75727 & cppMask_un_8_);
	cppVar_75729 = (cppVar_75727 == 153);
	if (cppVar_75729) {
	cppVar_75724 = SBUF;
	} else {
	cppVar_75731 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75732 = (cppVar_75731 << 3) | 2;
	cppVar_75732 = (cppVar_75732 & cppMask_un_5_);
	cppVar_75733 = (0 << 5) | cppVar_75732;
	cppVar_75733 = (cppVar_75733 & cppMask_un_8_);
	cppVar_75735 = (cppVar_75733 == 160);
	if (cppVar_75735) {
	cppVar_75730 = P2;
	} else {
	cppVar_75737 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75738 = (cppVar_75737 << 3) | 2;
	cppVar_75738 = (cppVar_75738 & cppMask_un_5_);
	cppVar_75739 = (0 << 5) | cppVar_75738;
	cppVar_75739 = (cppVar_75739 & cppMask_un_8_);
	cppVar_75741 = (cppVar_75739 == 168);
	if (cppVar_75741) {
	cppVar_75736 = IE;
	} else {
	cppVar_75743 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75744 = (cppVar_75743 << 3) | 2;
	cppVar_75744 = (cppVar_75744 & cppMask_un_5_);
	cppVar_75745 = (0 << 5) | cppVar_75744;
	cppVar_75745 = (cppVar_75745 & cppMask_un_8_);
	cppVar_75747 = (cppVar_75745 == 176);
	if (cppVar_75747) {
	cppVar_75742 = P3;
	} else {
	cppVar_75749 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75750 = (cppVar_75749 << 3) | 2;
	cppVar_75750 = (cppVar_75750 & cppMask_un_5_);
	cppVar_75751 = (0 << 5) | cppVar_75750;
	cppVar_75751 = (cppVar_75751 & cppMask_un_8_);
	cppVar_75753 = (cppVar_75751 == 184);
	if (cppVar_75753) {
	cppVar_75748 = IP;
	} else {
	cppVar_75755 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75756 = (cppVar_75755 << 3) | 2;
	cppVar_75756 = (cppVar_75756 & cppMask_un_5_);
	cppVar_75757 = (0 << 5) | cppVar_75756;
	cppVar_75757 = (cppVar_75757 & cppMask_un_8_);
	cppVar_75759 = (cppVar_75757 == 208);
	if (cppVar_75759) {
	cppVar_75754 = PSW;
	} else {
	cppVar_75761 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75762 = (cppVar_75761 << 3) | 2;
	cppVar_75762 = (cppVar_75762 & cppMask_un_5_);
	cppVar_75763 = (0 << 5) | cppVar_75762;
	cppVar_75763 = (cppVar_75763 & cppMask_un_8_);
	cppVar_75765 = (cppVar_75763 == 224);
	if (cppVar_75765) {
	cppVar_75760 = ACC;
	} else {
	cppVar_75767 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75768 = (cppVar_75767 << 3) | 2;
	cppVar_75768 = (cppVar_75768 & cppMask_un_5_);
	cppVar_75769 = (0 << 5) | cppVar_75768;
	cppVar_75769 = (cppVar_75769 & cppMask_un_8_);
	cppVar_75771 = (cppVar_75769 == 240);
	if (cppVar_75771) {
	cppVar_75766 = B;
	} else {
	cppVar_75766 = 0;
	}
	cppVar_75760 = cppVar_75766;
	}
	cppVar_75754 = cppVar_75760;
	}
	cppVar_75748 = cppVar_75754;
	}
	cppVar_75742 = cppVar_75748;
	}
	cppVar_75736 = cppVar_75742;
	}
	cppVar_75730 = cppVar_75736;
	}
	cppVar_75724 = cppVar_75730;
	}
	cppVar_75718 = cppVar_75724;
	}
	cppVar_75712 = cppVar_75718;
	}
	cppVar_75706 = cppVar_75712;
	}
	cppVar_75700 = cppVar_75706;
	}
	cppVar_75694 = cppVar_75700;
	}
	cppVar_75688 = cppVar_75694;
	}
	cppVar_75682 = cppVar_75688;
	}
	cppVar_75676 = cppVar_75682;
	}
	cppVar_75670 = cppVar_75676;
	}
	cppVar_75664 = cppVar_75670;
	}
	cppVar_75658 = cppVar_75664;
	}
	cppVar_75652 = cppVar_75658;
	}
	cppVar_75646 = cppVar_75652;
	}
	cppVar_75633 = cppVar_75646;
	}
	cppVar_75627 = cppVar_75633;
	} else {
	cppVar_75627 = TH1;
	}
	cppVar_75623 = cppVar_75627;
	} else {
	cppVar_75774 = ROM.rd(PC);
	cppVar_75776 = (cppVar_75774 == 137);
	if (cppVar_75776) {
	cppVar_75779 = PC + 1;
	cppVar_75779 = (cppVar_75779 & cppMask_un_16_);
	cppVar_75780 = ROM.rd(cppVar_75779);
	cppVar_75782 = (cppVar_75780 == 141);
	if (cppVar_75782) {
	cppVar_75785 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75787 = (cppVar_75785 << 3) | 1;
	cppVar_75787 = (cppVar_75787 & cppMask_un_5_);
	cppVar_75788 = (0 << 5) | cppVar_75787;
	cppVar_75788 = (cppVar_75788 & cppMask_un_8_);
	cppVar_75789 = (cppVar_75788 >> 7) & cppMask_un_1_;
	cppVar_75791 = (cppVar_75789 == 0);
	if (cppVar_75791) {
	cppVar_75792 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75793 = (cppVar_75792 << 3) | 1;
	cppVar_75793 = (cppVar_75793 & cppMask_un_5_);
	cppVar_75794 = (0 << 5) | cppVar_75793;
	cppVar_75794 = (cppVar_75794 & cppMask_un_8_);
	cppVar_75795 = IRAM.rd(cppVar_75794);
	cppVar_75783 = cppVar_75795;
	} else {
	cppVar_75797 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75798 = (cppVar_75797 << 3) | 1;
	cppVar_75798 = (cppVar_75798 & cppMask_un_5_);
	cppVar_75799 = (0 << 5) | cppVar_75798;
	cppVar_75799 = (cppVar_75799 & cppMask_un_8_);
	cppVar_75801 = (cppVar_75799 == 128);
	if (cppVar_75801) {
	cppVar_75796 = P0;
	} else {
	cppVar_75803 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75804 = (cppVar_75803 << 3) | 1;
	cppVar_75804 = (cppVar_75804 & cppMask_un_5_);
	cppVar_75805 = (0 << 5) | cppVar_75804;
	cppVar_75805 = (cppVar_75805 & cppMask_un_8_);
	cppVar_75807 = (cppVar_75805 == 129);
	if (cppVar_75807) {
	cppVar_75802 = SP;
	} else {
	cppVar_75809 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75810 = (cppVar_75809 << 3) | 1;
	cppVar_75810 = (cppVar_75810 & cppMask_un_5_);
	cppVar_75811 = (0 << 5) | cppVar_75810;
	cppVar_75811 = (cppVar_75811 & cppMask_un_8_);
	cppVar_75813 = (cppVar_75811 == 130);
	if (cppVar_75813) {
	cppVar_75808 = DPL;
	} else {
	cppVar_75815 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75816 = (cppVar_75815 << 3) | 1;
	cppVar_75816 = (cppVar_75816 & cppMask_un_5_);
	cppVar_75817 = (0 << 5) | cppVar_75816;
	cppVar_75817 = (cppVar_75817 & cppMask_un_8_);
	cppVar_75819 = (cppVar_75817 == 131);
	if (cppVar_75819) {
	cppVar_75814 = DPH;
	} else {
	cppVar_75821 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75822 = (cppVar_75821 << 3) | 1;
	cppVar_75822 = (cppVar_75822 & cppMask_un_5_);
	cppVar_75823 = (0 << 5) | cppVar_75822;
	cppVar_75823 = (cppVar_75823 & cppMask_un_8_);
	cppVar_75825 = (cppVar_75823 == 135);
	if (cppVar_75825) {
	cppVar_75820 = PCON;
	} else {
	cppVar_75827 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75828 = (cppVar_75827 << 3) | 1;
	cppVar_75828 = (cppVar_75828 & cppMask_un_5_);
	cppVar_75829 = (0 << 5) | cppVar_75828;
	cppVar_75829 = (cppVar_75829 & cppMask_un_8_);
	cppVar_75831 = (cppVar_75829 == 136);
	if (cppVar_75831) {
	cppVar_75826 = TCON;
	} else {
	cppVar_75833 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75834 = (cppVar_75833 << 3) | 1;
	cppVar_75834 = (cppVar_75834 & cppMask_un_5_);
	cppVar_75835 = (0 << 5) | cppVar_75834;
	cppVar_75835 = (cppVar_75835 & cppMask_un_8_);
	cppVar_75837 = (cppVar_75835 == 137);
	if (cppVar_75837) {
	cppVar_75832 = TMOD;
	} else {
	cppVar_75839 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75840 = (cppVar_75839 << 3) | 1;
	cppVar_75840 = (cppVar_75840 & cppMask_un_5_);
	cppVar_75841 = (0 << 5) | cppVar_75840;
	cppVar_75841 = (cppVar_75841 & cppMask_un_8_);
	cppVar_75843 = (cppVar_75841 == 138);
	if (cppVar_75843) {
	cppVar_75838 = TL0;
	} else {
	cppVar_75845 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75846 = (cppVar_75845 << 3) | 1;
	cppVar_75846 = (cppVar_75846 & cppMask_un_5_);
	cppVar_75847 = (0 << 5) | cppVar_75846;
	cppVar_75847 = (cppVar_75847 & cppMask_un_8_);
	cppVar_75849 = (cppVar_75847 == 140);
	if (cppVar_75849) {
	cppVar_75844 = TH0;
	} else {
	cppVar_75851 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75852 = (cppVar_75851 << 3) | 1;
	cppVar_75852 = (cppVar_75852 & cppMask_un_5_);
	cppVar_75853 = (0 << 5) | cppVar_75852;
	cppVar_75853 = (cppVar_75853 & cppMask_un_8_);
	cppVar_75855 = (cppVar_75853 == 139);
	if (cppVar_75855) {
	cppVar_75850 = TL1;
	} else {
	cppVar_75857 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75858 = (cppVar_75857 << 3) | 1;
	cppVar_75858 = (cppVar_75858 & cppMask_un_5_);
	cppVar_75859 = (0 << 5) | cppVar_75858;
	cppVar_75859 = (cppVar_75859 & cppMask_un_8_);
	cppVar_75861 = (cppVar_75859 == 141);
	if (cppVar_75861) {
	cppVar_75856 = TH1;
	} else {
	cppVar_75863 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75864 = (cppVar_75863 << 3) | 1;
	cppVar_75864 = (cppVar_75864 & cppMask_un_5_);
	cppVar_75865 = (0 << 5) | cppVar_75864;
	cppVar_75865 = (cppVar_75865 & cppMask_un_8_);
	cppVar_75867 = (cppVar_75865 == 144);
	if (cppVar_75867) {
	cppVar_75862 = P1;
	} else {
	cppVar_75869 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75870 = (cppVar_75869 << 3) | 1;
	cppVar_75870 = (cppVar_75870 & cppMask_un_5_);
	cppVar_75871 = (0 << 5) | cppVar_75870;
	cppVar_75871 = (cppVar_75871 & cppMask_un_8_);
	cppVar_75873 = (cppVar_75871 == 152);
	if (cppVar_75873) {
	cppVar_75868 = SCON;
	} else {
	cppVar_75875 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75876 = (cppVar_75875 << 3) | 1;
	cppVar_75876 = (cppVar_75876 & cppMask_un_5_);
	cppVar_75877 = (0 << 5) | cppVar_75876;
	cppVar_75877 = (cppVar_75877 & cppMask_un_8_);
	cppVar_75879 = (cppVar_75877 == 153);
	if (cppVar_75879) {
	cppVar_75874 = SBUF;
	} else {
	cppVar_75881 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75882 = (cppVar_75881 << 3) | 1;
	cppVar_75882 = (cppVar_75882 & cppMask_un_5_);
	cppVar_75883 = (0 << 5) | cppVar_75882;
	cppVar_75883 = (cppVar_75883 & cppMask_un_8_);
	cppVar_75885 = (cppVar_75883 == 160);
	if (cppVar_75885) {
	cppVar_75880 = P2;
	} else {
	cppVar_75887 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75888 = (cppVar_75887 << 3) | 1;
	cppVar_75888 = (cppVar_75888 & cppMask_un_5_);
	cppVar_75889 = (0 << 5) | cppVar_75888;
	cppVar_75889 = (cppVar_75889 & cppMask_un_8_);
	cppVar_75891 = (cppVar_75889 == 168);
	if (cppVar_75891) {
	cppVar_75886 = IE;
	} else {
	cppVar_75893 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75894 = (cppVar_75893 << 3) | 1;
	cppVar_75894 = (cppVar_75894 & cppMask_un_5_);
	cppVar_75895 = (0 << 5) | cppVar_75894;
	cppVar_75895 = (cppVar_75895 & cppMask_un_8_);
	cppVar_75897 = (cppVar_75895 == 176);
	if (cppVar_75897) {
	cppVar_75892 = P3;
	} else {
	cppVar_75899 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75900 = (cppVar_75899 << 3) | 1;
	cppVar_75900 = (cppVar_75900 & cppMask_un_5_);
	cppVar_75901 = (0 << 5) | cppVar_75900;
	cppVar_75901 = (cppVar_75901 & cppMask_un_8_);
	cppVar_75903 = (cppVar_75901 == 184);
	if (cppVar_75903) {
	cppVar_75898 = IP;
	} else {
	cppVar_75905 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75906 = (cppVar_75905 << 3) | 1;
	cppVar_75906 = (cppVar_75906 & cppMask_un_5_);
	cppVar_75907 = (0 << 5) | cppVar_75906;
	cppVar_75907 = (cppVar_75907 & cppMask_un_8_);
	cppVar_75909 = (cppVar_75907 == 208);
	if (cppVar_75909) {
	cppVar_75904 = PSW;
	} else {
	cppVar_75911 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75912 = (cppVar_75911 << 3) | 1;
	cppVar_75912 = (cppVar_75912 & cppMask_un_5_);
	cppVar_75913 = (0 << 5) | cppVar_75912;
	cppVar_75913 = (cppVar_75913 & cppMask_un_8_);
	cppVar_75915 = (cppVar_75913 == 224);
	if (cppVar_75915) {
	cppVar_75910 = ACC;
	} else {
	cppVar_75917 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75918 = (cppVar_75917 << 3) | 1;
	cppVar_75918 = (cppVar_75918 & cppMask_un_5_);
	cppVar_75919 = (0 << 5) | cppVar_75918;
	cppVar_75919 = (cppVar_75919 & cppMask_un_8_);
	cppVar_75921 = (cppVar_75919 == 240);
	if (cppVar_75921) {
	cppVar_75916 = B;
	} else {
	cppVar_75916 = 0;
	}
	cppVar_75910 = cppVar_75916;
	}
	cppVar_75904 = cppVar_75910;
	}
	cppVar_75898 = cppVar_75904;
	}
	cppVar_75892 = cppVar_75898;
	}
	cppVar_75886 = cppVar_75892;
	}
	cppVar_75880 = cppVar_75886;
	}
	cppVar_75874 = cppVar_75880;
	}
	cppVar_75868 = cppVar_75874;
	}
	cppVar_75862 = cppVar_75868;
	}
	cppVar_75856 = cppVar_75862;
	}
	cppVar_75850 = cppVar_75856;
	}
	cppVar_75844 = cppVar_75850;
	}
	cppVar_75838 = cppVar_75844;
	}
	cppVar_75832 = cppVar_75838;
	}
	cppVar_75826 = cppVar_75832;
	}
	cppVar_75820 = cppVar_75826;
	}
	cppVar_75814 = cppVar_75820;
	}
	cppVar_75808 = cppVar_75814;
	}
	cppVar_75802 = cppVar_75808;
	}
	cppVar_75796 = cppVar_75802;
	}
	cppVar_75783 = cppVar_75796;
	}
	cppVar_75777 = cppVar_75783;
	} else {
	cppVar_75777 = TH1;
	}
	cppVar_75773 = cppVar_75777;
	} else {
	cppVar_75924 = ROM.rd(PC);
	cppVar_75926 = (cppVar_75924 == 136);
	if (cppVar_75926) {
	cppVar_75929 = PC + 1;
	cppVar_75929 = (cppVar_75929 & cppMask_un_16_);
	cppVar_75930 = ROM.rd(cppVar_75929);
	cppVar_75932 = (cppVar_75930 == 141);
	if (cppVar_75932) {
	cppVar_75935 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75937 = (cppVar_75935 << 3) | 0;
	cppVar_75937 = (cppVar_75937 & cppMask_un_5_);
	cppVar_75938 = (0 << 5) | cppVar_75937;
	cppVar_75938 = (cppVar_75938 & cppMask_un_8_);
	cppVar_75939 = (cppVar_75938 >> 7) & cppMask_un_1_;
	cppVar_75941 = (cppVar_75939 == 0);
	if (cppVar_75941) {
	cppVar_75942 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75943 = (cppVar_75942 << 3) | 0;
	cppVar_75943 = (cppVar_75943 & cppMask_un_5_);
	cppVar_75944 = (0 << 5) | cppVar_75943;
	cppVar_75944 = (cppVar_75944 & cppMask_un_8_);
	cppVar_75945 = IRAM.rd(cppVar_75944);
	cppVar_75933 = cppVar_75945;
	} else {
	cppVar_75947 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75948 = (cppVar_75947 << 3) | 0;
	cppVar_75948 = (cppVar_75948 & cppMask_un_5_);
	cppVar_75949 = (0 << 5) | cppVar_75948;
	cppVar_75949 = (cppVar_75949 & cppMask_un_8_);
	cppVar_75951 = (cppVar_75949 == 128);
	if (cppVar_75951) {
	cppVar_75946 = P0;
	} else {
	cppVar_75953 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75954 = (cppVar_75953 << 3) | 0;
	cppVar_75954 = (cppVar_75954 & cppMask_un_5_);
	cppVar_75955 = (0 << 5) | cppVar_75954;
	cppVar_75955 = (cppVar_75955 & cppMask_un_8_);
	cppVar_75957 = (cppVar_75955 == 129);
	if (cppVar_75957) {
	cppVar_75952 = SP;
	} else {
	cppVar_75959 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75960 = (cppVar_75959 << 3) | 0;
	cppVar_75960 = (cppVar_75960 & cppMask_un_5_);
	cppVar_75961 = (0 << 5) | cppVar_75960;
	cppVar_75961 = (cppVar_75961 & cppMask_un_8_);
	cppVar_75963 = (cppVar_75961 == 130);
	if (cppVar_75963) {
	cppVar_75958 = DPL;
	} else {
	cppVar_75965 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75966 = (cppVar_75965 << 3) | 0;
	cppVar_75966 = (cppVar_75966 & cppMask_un_5_);
	cppVar_75967 = (0 << 5) | cppVar_75966;
	cppVar_75967 = (cppVar_75967 & cppMask_un_8_);
	cppVar_75969 = (cppVar_75967 == 131);
	if (cppVar_75969) {
	cppVar_75964 = DPH;
	} else {
	cppVar_75971 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75972 = (cppVar_75971 << 3) | 0;
	cppVar_75972 = (cppVar_75972 & cppMask_un_5_);
	cppVar_75973 = (0 << 5) | cppVar_75972;
	cppVar_75973 = (cppVar_75973 & cppMask_un_8_);
	cppVar_75975 = (cppVar_75973 == 135);
	if (cppVar_75975) {
	cppVar_75970 = PCON;
	} else {
	cppVar_75977 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75978 = (cppVar_75977 << 3) | 0;
	cppVar_75978 = (cppVar_75978 & cppMask_un_5_);
	cppVar_75979 = (0 << 5) | cppVar_75978;
	cppVar_75979 = (cppVar_75979 & cppMask_un_8_);
	cppVar_75981 = (cppVar_75979 == 136);
	if (cppVar_75981) {
	cppVar_75976 = TCON;
	} else {
	cppVar_75983 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75984 = (cppVar_75983 << 3) | 0;
	cppVar_75984 = (cppVar_75984 & cppMask_un_5_);
	cppVar_75985 = (0 << 5) | cppVar_75984;
	cppVar_75985 = (cppVar_75985 & cppMask_un_8_);
	cppVar_75987 = (cppVar_75985 == 137);
	if (cppVar_75987) {
	cppVar_75982 = TMOD;
	} else {
	cppVar_75989 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75990 = (cppVar_75989 << 3) | 0;
	cppVar_75990 = (cppVar_75990 & cppMask_un_5_);
	cppVar_75991 = (0 << 5) | cppVar_75990;
	cppVar_75991 = (cppVar_75991 & cppMask_un_8_);
	cppVar_75993 = (cppVar_75991 == 138);
	if (cppVar_75993) {
	cppVar_75988 = TL0;
	} else {
	cppVar_75995 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75996 = (cppVar_75995 << 3) | 0;
	cppVar_75996 = (cppVar_75996 & cppMask_un_5_);
	cppVar_75997 = (0 << 5) | cppVar_75996;
	cppVar_75997 = (cppVar_75997 & cppMask_un_8_);
	cppVar_75999 = (cppVar_75997 == 140);
	if (cppVar_75999) {
	cppVar_75994 = TH0;
	} else {
	cppVar_76001 = (PSW >> 3) & cppMask_un_2_;
	cppVar_76002 = (cppVar_76001 << 3) | 0;
	cppVar_76002 = (cppVar_76002 & cppMask_un_5_);
	cppVar_76003 = (0 << 5) | cppVar_76002;
	cppVar_76003 = (cppVar_76003 & cppMask_un_8_);
	cppVar_76005 = (cppVar_76003 == 139);
	if (cppVar_76005) {
	cppVar_76000 = TL1;
	} else {
	cppVar_76007 = (PSW >> 3) & cppMask_un_2_;
	cppVar_76008 = (cppVar_76007 << 3) | 0;
	cppVar_76008 = (cppVar_76008 & cppMask_un_5_);
	cppVar_76009 = (0 << 5) | cppVar_76008;
	cppVar_76009 = (cppVar_76009 & cppMask_un_8_);
	cppVar_76011 = (cppVar_76009 == 141);
	if (cppVar_76011) {
	cppVar_76006 = TH1;
	} else {
	cppVar_76013 = (PSW >> 3) & cppMask_un_2_;
	cppVar_76014 = (cppVar_76013 << 3) | 0;
	cppVar_76014 = (cppVar_76014 & cppMask_un_5_);
	cppVar_76015 = (0 << 5) | cppVar_76014;
	cppVar_76015 = (cppVar_76015 & cppMask_un_8_);
	cppVar_76017 = (cppVar_76015 == 144);
	if (cppVar_76017) {
	cppVar_76012 = P1;
	} else {
	cppVar_76019 = (PSW >> 3) & cppMask_un_2_;
	cppVar_76020 = (cppVar_76019 << 3) | 0;
	cppVar_76020 = (cppVar_76020 & cppMask_un_5_);
	cppVar_76021 = (0 << 5) | cppVar_76020;
	cppVar_76021 = (cppVar_76021 & cppMask_un_8_);
	cppVar_76023 = (cppVar_76021 == 152);
	if (cppVar_76023) {
	cppVar_76018 = SCON;
	} else {
	cppVar_76025 = (PSW >> 3) & cppMask_un_2_;
	cppVar_76026 = (cppVar_76025 << 3) | 0;
	cppVar_76026 = (cppVar_76026 & cppMask_un_5_);
	cppVar_76027 = (0 << 5) | cppVar_76026;
	cppVar_76027 = (cppVar_76027 & cppMask_un_8_);
	cppVar_76029 = (cppVar_76027 == 153);
	if (cppVar_76029) {
	cppVar_76024 = SBUF;
	} else {
	cppVar_76031 = (PSW >> 3) & cppMask_un_2_;
	cppVar_76032 = (cppVar_76031 << 3) | 0;
	cppVar_76032 = (cppVar_76032 & cppMask_un_5_);
	cppVar_76033 = (0 << 5) | cppVar_76032;
	cppVar_76033 = (cppVar_76033 & cppMask_un_8_);
	cppVar_76035 = (cppVar_76033 == 160);
	if (cppVar_76035) {
	cppVar_76030 = P2;
	} else {
	cppVar_76037 = (PSW >> 3) & cppMask_un_2_;
	cppVar_76038 = (cppVar_76037 << 3) | 0;
	cppVar_76038 = (cppVar_76038 & cppMask_un_5_);
	cppVar_76039 = (0 << 5) | cppVar_76038;
	cppVar_76039 = (cppVar_76039 & cppMask_un_8_);
	cppVar_76041 = (cppVar_76039 == 168);
	if (cppVar_76041) {
	cppVar_76036 = IE;
	} else {
	cppVar_76043 = (PSW >> 3) & cppMask_un_2_;
	cppVar_76044 = (cppVar_76043 << 3) | 0;
	cppVar_76044 = (cppVar_76044 & cppMask_un_5_);
	cppVar_76045 = (0 << 5) | cppVar_76044;
	cppVar_76045 = (cppVar_76045 & cppMask_un_8_);
	cppVar_76047 = (cppVar_76045 == 176);
	if (cppVar_76047) {
	cppVar_76042 = P3;
	} else {
	cppVar_76049 = (PSW >> 3) & cppMask_un_2_;
	cppVar_76050 = (cppVar_76049 << 3) | 0;
	cppVar_76050 = (cppVar_76050 & cppMask_un_5_);
	cppVar_76051 = (0 << 5) | cppVar_76050;
	cppVar_76051 = (cppVar_76051 & cppMask_un_8_);
	cppVar_76053 = (cppVar_76051 == 184);
	if (cppVar_76053) {
	cppVar_76048 = IP;
	} else {
	cppVar_76055 = (PSW >> 3) & cppMask_un_2_;
	cppVar_76056 = (cppVar_76055 << 3) | 0;
	cppVar_76056 = (cppVar_76056 & cppMask_un_5_);
	cppVar_76057 = (0 << 5) | cppVar_76056;
	cppVar_76057 = (cppVar_76057 & cppMask_un_8_);
	cppVar_76059 = (cppVar_76057 == 208);
	if (cppVar_76059) {
	cppVar_76054 = PSW;
	} else {
	cppVar_76061 = (PSW >> 3) & cppMask_un_2_;
	cppVar_76062 = (cppVar_76061 << 3) | 0;
	cppVar_76062 = (cppVar_76062 & cppMask_un_5_);
	cppVar_76063 = (0 << 5) | cppVar_76062;
	cppVar_76063 = (cppVar_76063 & cppMask_un_8_);
	cppVar_76065 = (cppVar_76063 == 224);
	if (cppVar_76065) {
	cppVar_76060 = ACC;
	} else {
	cppVar_76067 = (PSW >> 3) & cppMask_un_2_;
	cppVar_76068 = (cppVar_76067 << 3) | 0;
	cppVar_76068 = (cppVar_76068 & cppMask_un_5_);
	cppVar_76069 = (0 << 5) | cppVar_76068;
	cppVar_76069 = (cppVar_76069 & cppMask_un_8_);
	cppVar_76071 = (cppVar_76069 == 240);
	if (cppVar_76071) {
	cppVar_76066 = B;
	} else {
	cppVar_76066 = 0;
	}
	cppVar_76060 = cppVar_76066;
	}
	cppVar_76054 = cppVar_76060;
	}
	cppVar_76048 = cppVar_76054;
	}
	cppVar_76042 = cppVar_76048;
	}
	cppVar_76036 = cppVar_76042;
	}
	cppVar_76030 = cppVar_76036;
	}
	cppVar_76024 = cppVar_76030;
	}
	cppVar_76018 = cppVar_76024;
	}
	cppVar_76012 = cppVar_76018;
	}
	cppVar_76006 = cppVar_76012;
	}
	cppVar_76000 = cppVar_76006;
	}
	cppVar_75994 = cppVar_76000;
	}
	cppVar_75988 = cppVar_75994;
	}
	cppVar_75982 = cppVar_75988;
	}
	cppVar_75976 = cppVar_75982;
	}
	cppVar_75970 = cppVar_75976;
	}
	cppVar_75964 = cppVar_75970;
	}
	cppVar_75958 = cppVar_75964;
	}
	cppVar_75952 = cppVar_75958;
	}
	cppVar_75946 = cppVar_75952;
	}
	cppVar_75933 = cppVar_75946;
	}
	cppVar_75927 = cppVar_75933;
	} else {
	cppVar_75927 = TH1;
	}
	cppVar_75923 = cppVar_75927;
	} else {
	cppVar_76074 = ROM.rd(PC);
	cppVar_76076 = (cppVar_76074 == 135);
	if (cppVar_76076) {
	cppVar_76079 = PC + 1;
	cppVar_76079 = (cppVar_76079 & cppMask_un_16_);
	cppVar_76080 = ROM.rd(cppVar_76079);
	cppVar_76082 = (cppVar_76080 == 141);
	if (cppVar_76082) {
	cppVar_76084 = (PSW >> 3) & cppMask_un_2_;
	cppVar_76086 = (cppVar_76084 << 3) | 1;
	cppVar_76086 = (cppVar_76086 & cppMask_un_5_);
	cppVar_76087 = (0 << 5) | cppVar_76086;
	cppVar_76087 = (cppVar_76087 & cppMask_un_8_);
	cppVar_76088 = IRAM.rd(cppVar_76087);
	cppVar_76089 = IRAM.rd(cppVar_76088);
	cppVar_76077 = cppVar_76089;
	} else {
	cppVar_76077 = TH1;
	}
	cppVar_76073 = cppVar_76077;
	} else {
	cppVar_76091 = ROM.rd(PC);
	cppVar_76093 = (cppVar_76091 == 134);
	if (cppVar_76093) {
	cppVar_76096 = PC + 1;
	cppVar_76096 = (cppVar_76096 & cppMask_un_16_);
	cppVar_76097 = ROM.rd(cppVar_76096);
	cppVar_76099 = (cppVar_76097 == 141);
	if (cppVar_76099) {
	cppVar_76101 = (PSW >> 3) & cppMask_un_2_;
	cppVar_76103 = (cppVar_76101 << 3) | 0;
	cppVar_76103 = (cppVar_76103 & cppMask_un_5_);
	cppVar_76104 = (0 << 5) | cppVar_76103;
	cppVar_76104 = (cppVar_76104 & cppMask_un_8_);
	cppVar_76105 = IRAM.rd(cppVar_76104);
	cppVar_76106 = IRAM.rd(cppVar_76105);
	cppVar_76094 = cppVar_76106;
	} else {
	cppVar_76094 = TH1;
	}
	cppVar_76090 = cppVar_76094;
	} else {
	cppVar_76108 = ROM.rd(PC);
	cppVar_76110 = (cppVar_76108 == 133);
	if (cppVar_76110) {
	cppVar_76113 = PC + 2;
	cppVar_76113 = (cppVar_76113 & cppMask_un_16_);
	cppVar_76114 = ROM.rd(cppVar_76113);
	cppVar_76116 = (cppVar_76114 == 141);
	if (cppVar_76116) {
	cppVar_76119 = PC + 1;
	cppVar_76119 = (cppVar_76119 & cppMask_un_16_);
	cppVar_76120 = ROM.rd(cppVar_76119);
	cppVar_76121 = (cppVar_76120 >> 7) & cppMask_un_1_;
	cppVar_76123 = (cppVar_76121 == 0);
	if (cppVar_76123) {
	cppVar_76124 = PC + 1;
	cppVar_76124 = (cppVar_76124 & cppMask_un_16_);
	cppVar_76125 = ROM.rd(cppVar_76124);
	cppVar_76126 = IRAM.rd(cppVar_76125);
	cppVar_76117 = cppVar_76126;
	} else {
	cppVar_76128 = PC + 1;
	cppVar_76128 = (cppVar_76128 & cppMask_un_16_);
	cppVar_76129 = ROM.rd(cppVar_76128);
	cppVar_76131 = (cppVar_76129 == 128);
	if (cppVar_76131) {
	cppVar_76127 = P0;
	} else {
	cppVar_76133 = PC + 1;
	cppVar_76133 = (cppVar_76133 & cppMask_un_16_);
	cppVar_76134 = ROM.rd(cppVar_76133);
	cppVar_76136 = (cppVar_76134 == 129);
	if (cppVar_76136) {
	cppVar_76132 = SP;
	} else {
	cppVar_76138 = PC + 1;
	cppVar_76138 = (cppVar_76138 & cppMask_un_16_);
	cppVar_76139 = ROM.rd(cppVar_76138);
	cppVar_76141 = (cppVar_76139 == 130);
	if (cppVar_76141) {
	cppVar_76137 = DPL;
	} else {
	cppVar_76143 = PC + 1;
	cppVar_76143 = (cppVar_76143 & cppMask_un_16_);
	cppVar_76144 = ROM.rd(cppVar_76143);
	cppVar_76146 = (cppVar_76144 == 131);
	if (cppVar_76146) {
	cppVar_76142 = DPH;
	} else {
	cppVar_76148 = PC + 1;
	cppVar_76148 = (cppVar_76148 & cppMask_un_16_);
	cppVar_76149 = ROM.rd(cppVar_76148);
	cppVar_76151 = (cppVar_76149 == 135);
	if (cppVar_76151) {
	cppVar_76147 = PCON;
	} else {
	cppVar_76153 = PC + 1;
	cppVar_76153 = (cppVar_76153 & cppMask_un_16_);
	cppVar_76154 = ROM.rd(cppVar_76153);
	cppVar_76156 = (cppVar_76154 == 136);
	if (cppVar_76156) {
	cppVar_76152 = TCON;
	} else {
	cppVar_76158 = PC + 1;
	cppVar_76158 = (cppVar_76158 & cppMask_un_16_);
	cppVar_76159 = ROM.rd(cppVar_76158);
	cppVar_76161 = (cppVar_76159 == 137);
	if (cppVar_76161) {
	cppVar_76157 = TMOD;
	} else {
	cppVar_76163 = PC + 1;
	cppVar_76163 = (cppVar_76163 & cppMask_un_16_);
	cppVar_76164 = ROM.rd(cppVar_76163);
	cppVar_76166 = (cppVar_76164 == 138);
	if (cppVar_76166) {
	cppVar_76162 = TL0;
	} else {
	cppVar_76168 = PC + 1;
	cppVar_76168 = (cppVar_76168 & cppMask_un_16_);
	cppVar_76169 = ROM.rd(cppVar_76168);
	cppVar_76171 = (cppVar_76169 == 140);
	if (cppVar_76171) {
	cppVar_76167 = TH0;
	} else {
	cppVar_76173 = PC + 1;
	cppVar_76173 = (cppVar_76173 & cppMask_un_16_);
	cppVar_76174 = ROM.rd(cppVar_76173);
	cppVar_76176 = (cppVar_76174 == 139);
	if (cppVar_76176) {
	cppVar_76172 = TL1;
	} else {
	cppVar_76178 = PC + 1;
	cppVar_76178 = (cppVar_76178 & cppMask_un_16_);
	cppVar_76179 = ROM.rd(cppVar_76178);
	cppVar_76181 = (cppVar_76179 == 141);
	if (cppVar_76181) {
	cppVar_76177 = TH1;
	} else {
	cppVar_76183 = PC + 1;
	cppVar_76183 = (cppVar_76183 & cppMask_un_16_);
	cppVar_76184 = ROM.rd(cppVar_76183);
	cppVar_76186 = (cppVar_76184 == 144);
	if (cppVar_76186) {
	cppVar_76182 = P1;
	} else {
	cppVar_76188 = PC + 1;
	cppVar_76188 = (cppVar_76188 & cppMask_un_16_);
	cppVar_76189 = ROM.rd(cppVar_76188);
	cppVar_76191 = (cppVar_76189 == 152);
	if (cppVar_76191) {
	cppVar_76187 = SCON;
	} else {
	cppVar_76193 = PC + 1;
	cppVar_76193 = (cppVar_76193 & cppMask_un_16_);
	cppVar_76194 = ROM.rd(cppVar_76193);
	cppVar_76196 = (cppVar_76194 == 153);
	if (cppVar_76196) {
	cppVar_76192 = SBUF;
	} else {
	cppVar_76198 = PC + 1;
	cppVar_76198 = (cppVar_76198 & cppMask_un_16_);
	cppVar_76199 = ROM.rd(cppVar_76198);
	cppVar_76201 = (cppVar_76199 == 160);
	if (cppVar_76201) {
	cppVar_76197 = P2;
	} else {
	cppVar_76203 = PC + 1;
	cppVar_76203 = (cppVar_76203 & cppMask_un_16_);
	cppVar_76204 = ROM.rd(cppVar_76203);
	cppVar_76206 = (cppVar_76204 == 168);
	if (cppVar_76206) {
	cppVar_76202 = IE;
	} else {
	cppVar_76208 = PC + 1;
	cppVar_76208 = (cppVar_76208 & cppMask_un_16_);
	cppVar_76209 = ROM.rd(cppVar_76208);
	cppVar_76211 = (cppVar_76209 == 176);
	if (cppVar_76211) {
	cppVar_76207 = P3;
	} else {
	cppVar_76213 = PC + 1;
	cppVar_76213 = (cppVar_76213 & cppMask_un_16_);
	cppVar_76214 = ROM.rd(cppVar_76213);
	cppVar_76216 = (cppVar_76214 == 184);
	if (cppVar_76216) {
	cppVar_76212 = IP;
	} else {
	cppVar_76218 = PC + 1;
	cppVar_76218 = (cppVar_76218 & cppMask_un_16_);
	cppVar_76219 = ROM.rd(cppVar_76218);
	cppVar_76221 = (cppVar_76219 == 208);
	if (cppVar_76221) {
	cppVar_76217 = PSW;
	} else {
	cppVar_76223 = PC + 1;
	cppVar_76223 = (cppVar_76223 & cppMask_un_16_);
	cppVar_76224 = ROM.rd(cppVar_76223);
	cppVar_76226 = (cppVar_76224 == 224);
	if (cppVar_76226) {
	cppVar_76222 = ACC;
	} else {
	cppVar_76228 = PC + 1;
	cppVar_76228 = (cppVar_76228 & cppMask_un_16_);
	cppVar_76229 = ROM.rd(cppVar_76228);
	cppVar_76231 = (cppVar_76229 == 240);
	if (cppVar_76231) {
	cppVar_76227 = B;
	} else {
	cppVar_76227 = 0;
	}
	cppVar_76222 = cppVar_76227;
	}
	cppVar_76217 = cppVar_76222;
	}
	cppVar_76212 = cppVar_76217;
	}
	cppVar_76207 = cppVar_76212;
	}
	cppVar_76202 = cppVar_76207;
	}
	cppVar_76197 = cppVar_76202;
	}
	cppVar_76192 = cppVar_76197;
	}
	cppVar_76187 = cppVar_76192;
	}
	cppVar_76182 = cppVar_76187;
	}
	cppVar_76177 = cppVar_76182;
	}
	cppVar_76172 = cppVar_76177;
	}
	cppVar_76167 = cppVar_76172;
	}
	cppVar_76162 = cppVar_76167;
	}
	cppVar_76157 = cppVar_76162;
	}
	cppVar_76152 = cppVar_76157;
	}
	cppVar_76147 = cppVar_76152;
	}
	cppVar_76142 = cppVar_76147;
	}
	cppVar_76137 = cppVar_76142;
	}
	cppVar_76132 = cppVar_76137;
	}
	cppVar_76127 = cppVar_76132;
	}
	cppVar_76117 = cppVar_76127;
	}
	cppVar_76111 = cppVar_76117;
	} else {
	cppVar_76111 = TH1;
	}
	cppVar_76107 = cppVar_76111;
	} else {
	cppVar_76234 = ROM.rd(PC);
	cppVar_76236 = (cppVar_76234 == 117);
	if (cppVar_76236) {
	cppVar_76239 = PC + 1;
	cppVar_76239 = (cppVar_76239 & cppMask_un_16_);
	cppVar_76240 = ROM.rd(cppVar_76239);
	cppVar_76242 = (cppVar_76240 == 141);
	if (cppVar_76242) {
	cppVar_76244 = PC + 2;
	cppVar_76244 = (cppVar_76244 & cppMask_un_16_);
	cppVar_76245 = ROM.rd(cppVar_76244);
	cppVar_76237 = cppVar_76245;
	} else {
	cppVar_76237 = TH1;
	}
	cppVar_76233 = cppVar_76237;
	} else {
	cppVar_76247 = ROM.rd(PC);
	cppVar_76249 = (cppVar_76247 == 99);
	if (cppVar_76249) {
	cppVar_76252 = PC + 1;
	cppVar_76252 = (cppVar_76252 & cppMask_un_16_);
	cppVar_76253 = ROM.rd(cppVar_76252);
	cppVar_76255 = (cppVar_76253 == 141);
	if (cppVar_76255) {
	cppVar_76257 = PC + 1;
	cppVar_76257 = (cppVar_76257 & cppMask_un_16_);
	cppVar_76258 = ROM.rd(cppVar_76257);
	cppVar_76259 = (cppVar_76258 >> 7) & cppMask_un_1_;
	cppVar_76261 = (cppVar_76259 == 0);
	if (cppVar_76261) {
	cppVar_76262 = PC + 1;
	cppVar_76262 = (cppVar_76262 & cppMask_un_16_);
	cppVar_76263 = ROM.rd(cppVar_76262);
	cppVar_76264 = IRAM.rd(cppVar_76263);
	cppVar_76256 = cppVar_76264;
	} else {
	cppVar_76266 = PC + 1;
	cppVar_76266 = (cppVar_76266 & cppMask_un_16_);
	cppVar_76267 = ROM.rd(cppVar_76266);
	cppVar_76269 = (cppVar_76267 == 128);
	if (cppVar_76269) {
	cppVar_76265 = P0;
	} else {
	cppVar_76271 = PC + 1;
	cppVar_76271 = (cppVar_76271 & cppMask_un_16_);
	cppVar_76272 = ROM.rd(cppVar_76271);
	cppVar_76274 = (cppVar_76272 == 129);
	if (cppVar_76274) {
	cppVar_76270 = SP;
	} else {
	cppVar_76276 = PC + 1;
	cppVar_76276 = (cppVar_76276 & cppMask_un_16_);
	cppVar_76277 = ROM.rd(cppVar_76276);
	cppVar_76279 = (cppVar_76277 == 130);
	if (cppVar_76279) {
	cppVar_76275 = DPL;
	} else {
	cppVar_76281 = PC + 1;
	cppVar_76281 = (cppVar_76281 & cppMask_un_16_);
	cppVar_76282 = ROM.rd(cppVar_76281);
	cppVar_76284 = (cppVar_76282 == 131);
	if (cppVar_76284) {
	cppVar_76280 = DPH;
	} else {
	cppVar_76286 = PC + 1;
	cppVar_76286 = (cppVar_76286 & cppMask_un_16_);
	cppVar_76287 = ROM.rd(cppVar_76286);
	cppVar_76289 = (cppVar_76287 == 135);
	if (cppVar_76289) {
	cppVar_76285 = PCON;
	} else {
	cppVar_76291 = PC + 1;
	cppVar_76291 = (cppVar_76291 & cppMask_un_16_);
	cppVar_76292 = ROM.rd(cppVar_76291);
	cppVar_76294 = (cppVar_76292 == 136);
	if (cppVar_76294) {
	cppVar_76290 = TCON;
	} else {
	cppVar_76296 = PC + 1;
	cppVar_76296 = (cppVar_76296 & cppMask_un_16_);
	cppVar_76297 = ROM.rd(cppVar_76296);
	cppVar_76299 = (cppVar_76297 == 137);
	if (cppVar_76299) {
	cppVar_76295 = TMOD;
	} else {
	cppVar_76301 = PC + 1;
	cppVar_76301 = (cppVar_76301 & cppMask_un_16_);
	cppVar_76302 = ROM.rd(cppVar_76301);
	cppVar_76304 = (cppVar_76302 == 138);
	if (cppVar_76304) {
	cppVar_76300 = TL0;
	} else {
	cppVar_76306 = PC + 1;
	cppVar_76306 = (cppVar_76306 & cppMask_un_16_);
	cppVar_76307 = ROM.rd(cppVar_76306);
	cppVar_76309 = (cppVar_76307 == 140);
	if (cppVar_76309) {
	cppVar_76305 = TH0;
	} else {
	cppVar_76311 = PC + 1;
	cppVar_76311 = (cppVar_76311 & cppMask_un_16_);
	cppVar_76312 = ROM.rd(cppVar_76311);
	cppVar_76314 = (cppVar_76312 == 139);
	if (cppVar_76314) {
	cppVar_76310 = TL1;
	} else {
	cppVar_76316 = PC + 1;
	cppVar_76316 = (cppVar_76316 & cppMask_un_16_);
	cppVar_76317 = ROM.rd(cppVar_76316);
	cppVar_76319 = (cppVar_76317 == 141);
	if (cppVar_76319) {
	cppVar_76315 = TH1;
	} else {
	cppVar_76321 = PC + 1;
	cppVar_76321 = (cppVar_76321 & cppMask_un_16_);
	cppVar_76322 = ROM.rd(cppVar_76321);
	cppVar_76324 = (cppVar_76322 == 144);
	if (cppVar_76324) {
	cppVar_76320 = P1;
	} else {
	cppVar_76326 = PC + 1;
	cppVar_76326 = (cppVar_76326 & cppMask_un_16_);
	cppVar_76327 = ROM.rd(cppVar_76326);
	cppVar_76329 = (cppVar_76327 == 152);
	if (cppVar_76329) {
	cppVar_76325 = SCON;
	} else {
	cppVar_76331 = PC + 1;
	cppVar_76331 = (cppVar_76331 & cppMask_un_16_);
	cppVar_76332 = ROM.rd(cppVar_76331);
	cppVar_76334 = (cppVar_76332 == 153);
	if (cppVar_76334) {
	cppVar_76330 = SBUF;
	} else {
	cppVar_76336 = PC + 1;
	cppVar_76336 = (cppVar_76336 & cppMask_un_16_);
	cppVar_76337 = ROM.rd(cppVar_76336);
	cppVar_76339 = (cppVar_76337 == 160);
	if (cppVar_76339) {
	cppVar_76335 = P2;
	} else {
	cppVar_76341 = PC + 1;
	cppVar_76341 = (cppVar_76341 & cppMask_un_16_);
	cppVar_76342 = ROM.rd(cppVar_76341);
	cppVar_76344 = (cppVar_76342 == 168);
	if (cppVar_76344) {
	cppVar_76340 = IE;
	} else {
	cppVar_76346 = PC + 1;
	cppVar_76346 = (cppVar_76346 & cppMask_un_16_);
	cppVar_76347 = ROM.rd(cppVar_76346);
	cppVar_76349 = (cppVar_76347 == 176);
	if (cppVar_76349) {
	cppVar_76345 = P3;
	} else {
	cppVar_76351 = PC + 1;
	cppVar_76351 = (cppVar_76351 & cppMask_un_16_);
	cppVar_76352 = ROM.rd(cppVar_76351);
	cppVar_76354 = (cppVar_76352 == 184);
	if (cppVar_76354) {
	cppVar_76350 = IP;
	} else {
	cppVar_76356 = PC + 1;
	cppVar_76356 = (cppVar_76356 & cppMask_un_16_);
	cppVar_76357 = ROM.rd(cppVar_76356);
	cppVar_76359 = (cppVar_76357 == 208);
	if (cppVar_76359) {
	cppVar_76355 = PSW;
	} else {
	cppVar_76361 = PC + 1;
	cppVar_76361 = (cppVar_76361 & cppMask_un_16_);
	cppVar_76362 = ROM.rd(cppVar_76361);
	cppVar_76364 = (cppVar_76362 == 224);
	if (cppVar_76364) {
	cppVar_76360 = ACC;
	} else {
	cppVar_76366 = PC + 1;
	cppVar_76366 = (cppVar_76366 & cppMask_un_16_);
	cppVar_76367 = ROM.rd(cppVar_76366);
	cppVar_76369 = (cppVar_76367 == 240);
	if (cppVar_76369) {
	cppVar_76365 = B;
	} else {
	cppVar_76365 = 0;
	}
	cppVar_76360 = cppVar_76365;
	}
	cppVar_76355 = cppVar_76360;
	}
	cppVar_76350 = cppVar_76355;
	}
	cppVar_76345 = cppVar_76350;
	}
	cppVar_76340 = cppVar_76345;
	}
	cppVar_76335 = cppVar_76340;
	}
	cppVar_76330 = cppVar_76335;
	}
	cppVar_76325 = cppVar_76330;
	}
	cppVar_76320 = cppVar_76325;
	}
	cppVar_76315 = cppVar_76320;
	}
	cppVar_76310 = cppVar_76315;
	}
	cppVar_76305 = cppVar_76310;
	}
	cppVar_76300 = cppVar_76305;
	}
	cppVar_76295 = cppVar_76300;
	}
	cppVar_76290 = cppVar_76295;
	}
	cppVar_76285 = cppVar_76290;
	}
	cppVar_76280 = cppVar_76285;
	}
	cppVar_76275 = cppVar_76280;
	}
	cppVar_76270 = cppVar_76275;
	}
	cppVar_76265 = cppVar_76270;
	}
	cppVar_76256 = cppVar_76265;
	}
	cppVar_76372 = PC + 2;
	cppVar_76372 = (cppVar_76372 & cppMask_un_16_);
	cppVar_76373 = ROM.rd(cppVar_76372);
	cppVar_76374 = cppVar_76256 ^ cppVar_76373;
	cppVar_76250 = cppVar_76374;
	} else {
	cppVar_76250 = TH1;
	}
	cppVar_76246 = cppVar_76250;
	} else {
	cppVar_76376 = ROM.rd(PC);
	cppVar_76378 = (cppVar_76376 == 98);
	if (cppVar_76378) {
	cppVar_76381 = PC + 1;
	cppVar_76381 = (cppVar_76381 & cppMask_un_16_);
	cppVar_76382 = ROM.rd(cppVar_76381);
	cppVar_76384 = (cppVar_76382 == 141);
	if (cppVar_76384) {
	cppVar_76386 = PC + 1;
	cppVar_76386 = (cppVar_76386 & cppMask_un_16_);
	cppVar_76387 = ROM.rd(cppVar_76386);
	cppVar_76388 = (cppVar_76387 >> 7) & cppMask_un_1_;
	cppVar_76390 = (cppVar_76388 == 0);
	if (cppVar_76390) {
	cppVar_76391 = PC + 1;
	cppVar_76391 = (cppVar_76391 & cppMask_un_16_);
	cppVar_76392 = ROM.rd(cppVar_76391);
	cppVar_76393 = IRAM.rd(cppVar_76392);
	cppVar_76385 = cppVar_76393;
	} else {
	cppVar_76395 = PC + 1;
	cppVar_76395 = (cppVar_76395 & cppMask_un_16_);
	cppVar_76396 = ROM.rd(cppVar_76395);
	cppVar_76398 = (cppVar_76396 == 128);
	if (cppVar_76398) {
	cppVar_76394 = P0;
	} else {
	cppVar_76400 = PC + 1;
	cppVar_76400 = (cppVar_76400 & cppMask_un_16_);
	cppVar_76401 = ROM.rd(cppVar_76400);
	cppVar_76403 = (cppVar_76401 == 129);
	if (cppVar_76403) {
	cppVar_76399 = SP;
	} else {
	cppVar_76405 = PC + 1;
	cppVar_76405 = (cppVar_76405 & cppMask_un_16_);
	cppVar_76406 = ROM.rd(cppVar_76405);
	cppVar_76408 = (cppVar_76406 == 130);
	if (cppVar_76408) {
	cppVar_76404 = DPL;
	} else {
	cppVar_76410 = PC + 1;
	cppVar_76410 = (cppVar_76410 & cppMask_un_16_);
	cppVar_76411 = ROM.rd(cppVar_76410);
	cppVar_76413 = (cppVar_76411 == 131);
	if (cppVar_76413) {
	cppVar_76409 = DPH;
	} else {
	cppVar_76415 = PC + 1;
	cppVar_76415 = (cppVar_76415 & cppMask_un_16_);
	cppVar_76416 = ROM.rd(cppVar_76415);
	cppVar_76418 = (cppVar_76416 == 135);
	if (cppVar_76418) {
	cppVar_76414 = PCON;
	} else {
	cppVar_76420 = PC + 1;
	cppVar_76420 = (cppVar_76420 & cppMask_un_16_);
	cppVar_76421 = ROM.rd(cppVar_76420);
	cppVar_76423 = (cppVar_76421 == 136);
	if (cppVar_76423) {
	cppVar_76419 = TCON;
	} else {
	cppVar_76425 = PC + 1;
	cppVar_76425 = (cppVar_76425 & cppMask_un_16_);
	cppVar_76426 = ROM.rd(cppVar_76425);
	cppVar_76428 = (cppVar_76426 == 137);
	if (cppVar_76428) {
	cppVar_76424 = TMOD;
	} else {
	cppVar_76430 = PC + 1;
	cppVar_76430 = (cppVar_76430 & cppMask_un_16_);
	cppVar_76431 = ROM.rd(cppVar_76430);
	cppVar_76433 = (cppVar_76431 == 138);
	if (cppVar_76433) {
	cppVar_76429 = TL0;
	} else {
	cppVar_76435 = PC + 1;
	cppVar_76435 = (cppVar_76435 & cppMask_un_16_);
	cppVar_76436 = ROM.rd(cppVar_76435);
	cppVar_76438 = (cppVar_76436 == 140);
	if (cppVar_76438) {
	cppVar_76434 = TH0;
	} else {
	cppVar_76440 = PC + 1;
	cppVar_76440 = (cppVar_76440 & cppMask_un_16_);
	cppVar_76441 = ROM.rd(cppVar_76440);
	cppVar_76443 = (cppVar_76441 == 139);
	if (cppVar_76443) {
	cppVar_76439 = TL1;
	} else {
	cppVar_76445 = PC + 1;
	cppVar_76445 = (cppVar_76445 & cppMask_un_16_);
	cppVar_76446 = ROM.rd(cppVar_76445);
	cppVar_76448 = (cppVar_76446 == 141);
	if (cppVar_76448) {
	cppVar_76444 = TH1;
	} else {
	cppVar_76450 = PC + 1;
	cppVar_76450 = (cppVar_76450 & cppMask_un_16_);
	cppVar_76451 = ROM.rd(cppVar_76450);
	cppVar_76453 = (cppVar_76451 == 144);
	if (cppVar_76453) {
	cppVar_76449 = P1;
	} else {
	cppVar_76455 = PC + 1;
	cppVar_76455 = (cppVar_76455 & cppMask_un_16_);
	cppVar_76456 = ROM.rd(cppVar_76455);
	cppVar_76458 = (cppVar_76456 == 152);
	if (cppVar_76458) {
	cppVar_76454 = SCON;
	} else {
	cppVar_76460 = PC + 1;
	cppVar_76460 = (cppVar_76460 & cppMask_un_16_);
	cppVar_76461 = ROM.rd(cppVar_76460);
	cppVar_76463 = (cppVar_76461 == 153);
	if (cppVar_76463) {
	cppVar_76459 = SBUF;
	} else {
	cppVar_76465 = PC + 1;
	cppVar_76465 = (cppVar_76465 & cppMask_un_16_);
	cppVar_76466 = ROM.rd(cppVar_76465);
	cppVar_76468 = (cppVar_76466 == 160);
	if (cppVar_76468) {
	cppVar_76464 = P2;
	} else {
	cppVar_76470 = PC + 1;
	cppVar_76470 = (cppVar_76470 & cppMask_un_16_);
	cppVar_76471 = ROM.rd(cppVar_76470);
	cppVar_76473 = (cppVar_76471 == 168);
	if (cppVar_76473) {
	cppVar_76469 = IE;
	} else {
	cppVar_76475 = PC + 1;
	cppVar_76475 = (cppVar_76475 & cppMask_un_16_);
	cppVar_76476 = ROM.rd(cppVar_76475);
	cppVar_76478 = (cppVar_76476 == 176);
	if (cppVar_76478) {
	cppVar_76474 = P3;
	} else {
	cppVar_76480 = PC + 1;
	cppVar_76480 = (cppVar_76480 & cppMask_un_16_);
	cppVar_76481 = ROM.rd(cppVar_76480);
	cppVar_76483 = (cppVar_76481 == 184);
	if (cppVar_76483) {
	cppVar_76479 = IP;
	} else {
	cppVar_76485 = PC + 1;
	cppVar_76485 = (cppVar_76485 & cppMask_un_16_);
	cppVar_76486 = ROM.rd(cppVar_76485);
	cppVar_76488 = (cppVar_76486 == 208);
	if (cppVar_76488) {
	cppVar_76484 = PSW;
	} else {
	cppVar_76490 = PC + 1;
	cppVar_76490 = (cppVar_76490 & cppMask_un_16_);
	cppVar_76491 = ROM.rd(cppVar_76490);
	cppVar_76493 = (cppVar_76491 == 224);
	if (cppVar_76493) {
	cppVar_76489 = ACC;
	} else {
	cppVar_76495 = PC + 1;
	cppVar_76495 = (cppVar_76495 & cppMask_un_16_);
	cppVar_76496 = ROM.rd(cppVar_76495);
	cppVar_76498 = (cppVar_76496 == 240);
	if (cppVar_76498) {
	cppVar_76494 = B;
	} else {
	cppVar_76494 = 0;
	}
	cppVar_76489 = cppVar_76494;
	}
	cppVar_76484 = cppVar_76489;
	}
	cppVar_76479 = cppVar_76484;
	}
	cppVar_76474 = cppVar_76479;
	}
	cppVar_76469 = cppVar_76474;
	}
	cppVar_76464 = cppVar_76469;
	}
	cppVar_76459 = cppVar_76464;
	}
	cppVar_76454 = cppVar_76459;
	}
	cppVar_76449 = cppVar_76454;
	}
	cppVar_76444 = cppVar_76449;
	}
	cppVar_76439 = cppVar_76444;
	}
	cppVar_76434 = cppVar_76439;
	}
	cppVar_76429 = cppVar_76434;
	}
	cppVar_76424 = cppVar_76429;
	}
	cppVar_76419 = cppVar_76424;
	}
	cppVar_76414 = cppVar_76419;
	}
	cppVar_76409 = cppVar_76414;
	}
	cppVar_76404 = cppVar_76409;
	}
	cppVar_76399 = cppVar_76404;
	}
	cppVar_76394 = cppVar_76399;
	}
	cppVar_76385 = cppVar_76394;
	}
	cppVar_76500 = cppVar_76385 ^ ACC;
	cppVar_76379 = cppVar_76500;
	} else {
	cppVar_76379 = TH1;
	}
	cppVar_76375 = cppVar_76379;
	} else {
	cppVar_76502 = ROM.rd(PC);
	cppVar_76504 = (cppVar_76502 == 83);
	if (cppVar_76504) {
	cppVar_76507 = PC + 1;
	cppVar_76507 = (cppVar_76507 & cppMask_un_16_);
	cppVar_76508 = ROM.rd(cppVar_76507);
	cppVar_76510 = (cppVar_76508 == 141);
	if (cppVar_76510) {
	cppVar_76512 = PC + 1;
	cppVar_76512 = (cppVar_76512 & cppMask_un_16_);
	cppVar_76513 = ROM.rd(cppVar_76512);
	cppVar_76514 = (cppVar_76513 >> 7) & cppMask_un_1_;
	cppVar_76516 = (cppVar_76514 == 0);
	if (cppVar_76516) {
	cppVar_76517 = PC + 1;
	cppVar_76517 = (cppVar_76517 & cppMask_un_16_);
	cppVar_76518 = ROM.rd(cppVar_76517);
	cppVar_76519 = IRAM.rd(cppVar_76518);
	cppVar_76511 = cppVar_76519;
	} else {
	cppVar_76521 = PC + 1;
	cppVar_76521 = (cppVar_76521 & cppMask_un_16_);
	cppVar_76522 = ROM.rd(cppVar_76521);
	cppVar_76524 = (cppVar_76522 == 128);
	if (cppVar_76524) {
	cppVar_76520 = P0;
	} else {
	cppVar_76526 = PC + 1;
	cppVar_76526 = (cppVar_76526 & cppMask_un_16_);
	cppVar_76527 = ROM.rd(cppVar_76526);
	cppVar_76529 = (cppVar_76527 == 129);
	if (cppVar_76529) {
	cppVar_76525 = SP;
	} else {
	cppVar_76531 = PC + 1;
	cppVar_76531 = (cppVar_76531 & cppMask_un_16_);
	cppVar_76532 = ROM.rd(cppVar_76531);
	cppVar_76534 = (cppVar_76532 == 130);
	if (cppVar_76534) {
	cppVar_76530 = DPL;
	} else {
	cppVar_76536 = PC + 1;
	cppVar_76536 = (cppVar_76536 & cppMask_un_16_);
	cppVar_76537 = ROM.rd(cppVar_76536);
	cppVar_76539 = (cppVar_76537 == 131);
	if (cppVar_76539) {
	cppVar_76535 = DPH;
	} else {
	cppVar_76541 = PC + 1;
	cppVar_76541 = (cppVar_76541 & cppMask_un_16_);
	cppVar_76542 = ROM.rd(cppVar_76541);
	cppVar_76544 = (cppVar_76542 == 135);
	if (cppVar_76544) {
	cppVar_76540 = PCON;
	} else {
	cppVar_76546 = PC + 1;
	cppVar_76546 = (cppVar_76546 & cppMask_un_16_);
	cppVar_76547 = ROM.rd(cppVar_76546);
	cppVar_76549 = (cppVar_76547 == 136);
	if (cppVar_76549) {
	cppVar_76545 = TCON;
	} else {
	cppVar_76551 = PC + 1;
	cppVar_76551 = (cppVar_76551 & cppMask_un_16_);
	cppVar_76552 = ROM.rd(cppVar_76551);
	cppVar_76554 = (cppVar_76552 == 137);
	if (cppVar_76554) {
	cppVar_76550 = TMOD;
	} else {
	cppVar_76556 = PC + 1;
	cppVar_76556 = (cppVar_76556 & cppMask_un_16_);
	cppVar_76557 = ROM.rd(cppVar_76556);
	cppVar_76559 = (cppVar_76557 == 138);
	if (cppVar_76559) {
	cppVar_76555 = TL0;
	} else {
	cppVar_76561 = PC + 1;
	cppVar_76561 = (cppVar_76561 & cppMask_un_16_);
	cppVar_76562 = ROM.rd(cppVar_76561);
	cppVar_76564 = (cppVar_76562 == 140);
	if (cppVar_76564) {
	cppVar_76560 = TH0;
	} else {
	cppVar_76566 = PC + 1;
	cppVar_76566 = (cppVar_76566 & cppMask_un_16_);
	cppVar_76567 = ROM.rd(cppVar_76566);
	cppVar_76569 = (cppVar_76567 == 139);
	if (cppVar_76569) {
	cppVar_76565 = TL1;
	} else {
	cppVar_76571 = PC + 1;
	cppVar_76571 = (cppVar_76571 & cppMask_un_16_);
	cppVar_76572 = ROM.rd(cppVar_76571);
	cppVar_76574 = (cppVar_76572 == 141);
	if (cppVar_76574) {
	cppVar_76570 = TH1;
	} else {
	cppVar_76576 = PC + 1;
	cppVar_76576 = (cppVar_76576 & cppMask_un_16_);
	cppVar_76577 = ROM.rd(cppVar_76576);
	cppVar_76579 = (cppVar_76577 == 144);
	if (cppVar_76579) {
	cppVar_76575 = P1;
	} else {
	cppVar_76581 = PC + 1;
	cppVar_76581 = (cppVar_76581 & cppMask_un_16_);
	cppVar_76582 = ROM.rd(cppVar_76581);
	cppVar_76584 = (cppVar_76582 == 152);
	if (cppVar_76584) {
	cppVar_76580 = SCON;
	} else {
	cppVar_76586 = PC + 1;
	cppVar_76586 = (cppVar_76586 & cppMask_un_16_);
	cppVar_76587 = ROM.rd(cppVar_76586);
	cppVar_76589 = (cppVar_76587 == 153);
	if (cppVar_76589) {
	cppVar_76585 = SBUF;
	} else {
	cppVar_76591 = PC + 1;
	cppVar_76591 = (cppVar_76591 & cppMask_un_16_);
	cppVar_76592 = ROM.rd(cppVar_76591);
	cppVar_76594 = (cppVar_76592 == 160);
	if (cppVar_76594) {
	cppVar_76590 = P2;
	} else {
	cppVar_76596 = PC + 1;
	cppVar_76596 = (cppVar_76596 & cppMask_un_16_);
	cppVar_76597 = ROM.rd(cppVar_76596);
	cppVar_76599 = (cppVar_76597 == 168);
	if (cppVar_76599) {
	cppVar_76595 = IE;
	} else {
	cppVar_76601 = PC + 1;
	cppVar_76601 = (cppVar_76601 & cppMask_un_16_);
	cppVar_76602 = ROM.rd(cppVar_76601);
	cppVar_76604 = (cppVar_76602 == 176);
	if (cppVar_76604) {
	cppVar_76600 = P3;
	} else {
	cppVar_76606 = PC + 1;
	cppVar_76606 = (cppVar_76606 & cppMask_un_16_);
	cppVar_76607 = ROM.rd(cppVar_76606);
	cppVar_76609 = (cppVar_76607 == 184);
	if (cppVar_76609) {
	cppVar_76605 = IP;
	} else {
	cppVar_76611 = PC + 1;
	cppVar_76611 = (cppVar_76611 & cppMask_un_16_);
	cppVar_76612 = ROM.rd(cppVar_76611);
	cppVar_76614 = (cppVar_76612 == 208);
	if (cppVar_76614) {
	cppVar_76610 = PSW;
	} else {
	cppVar_76616 = PC + 1;
	cppVar_76616 = (cppVar_76616 & cppMask_un_16_);
	cppVar_76617 = ROM.rd(cppVar_76616);
	cppVar_76619 = (cppVar_76617 == 224);
	if (cppVar_76619) {
	cppVar_76615 = ACC;
	} else {
	cppVar_76621 = PC + 1;
	cppVar_76621 = (cppVar_76621 & cppMask_un_16_);
	cppVar_76622 = ROM.rd(cppVar_76621);
	cppVar_76624 = (cppVar_76622 == 240);
	if (cppVar_76624) {
	cppVar_76620 = B;
	} else {
	cppVar_76620 = 0;
	}
	cppVar_76615 = cppVar_76620;
	}
	cppVar_76610 = cppVar_76615;
	}
	cppVar_76605 = cppVar_76610;
	}
	cppVar_76600 = cppVar_76605;
	}
	cppVar_76595 = cppVar_76600;
	}
	cppVar_76590 = cppVar_76595;
	}
	cppVar_76585 = cppVar_76590;
	}
	cppVar_76580 = cppVar_76585;
	}
	cppVar_76575 = cppVar_76580;
	}
	cppVar_76570 = cppVar_76575;
	}
	cppVar_76565 = cppVar_76570;
	}
	cppVar_76560 = cppVar_76565;
	}
	cppVar_76555 = cppVar_76560;
	}
	cppVar_76550 = cppVar_76555;
	}
	cppVar_76545 = cppVar_76550;
	}
	cppVar_76540 = cppVar_76545;
	}
	cppVar_76535 = cppVar_76540;
	}
	cppVar_76530 = cppVar_76535;
	}
	cppVar_76525 = cppVar_76530;
	}
	cppVar_76520 = cppVar_76525;
	}
	cppVar_76511 = cppVar_76520;
	}
	cppVar_76627 = PC + 2;
	cppVar_76627 = (cppVar_76627 & cppMask_un_16_);
	cppVar_76628 = ROM.rd(cppVar_76627);
	cppVar_76629 = cppVar_76511 & cppVar_76628;
	cppVar_76505 = cppVar_76629;
	} else {
	cppVar_76505 = TH1;
	}
	cppVar_76501 = cppVar_76505;
	} else {
	cppVar_76631 = ROM.rd(PC);
	cppVar_76633 = (cppVar_76631 == 82);
	if (cppVar_76633) {
	cppVar_76636 = PC + 1;
	cppVar_76636 = (cppVar_76636 & cppMask_un_16_);
	cppVar_76637 = ROM.rd(cppVar_76636);
	cppVar_76639 = (cppVar_76637 == 141);
	if (cppVar_76639) {
	cppVar_76641 = PC + 1;
	cppVar_76641 = (cppVar_76641 & cppMask_un_16_);
	cppVar_76642 = ROM.rd(cppVar_76641);
	cppVar_76643 = (cppVar_76642 >> 7) & cppMask_un_1_;
	cppVar_76645 = (cppVar_76643 == 0);
	if (cppVar_76645) {
	cppVar_76646 = PC + 1;
	cppVar_76646 = (cppVar_76646 & cppMask_un_16_);
	cppVar_76647 = ROM.rd(cppVar_76646);
	cppVar_76648 = IRAM.rd(cppVar_76647);
	cppVar_76640 = cppVar_76648;
	} else {
	cppVar_76650 = PC + 1;
	cppVar_76650 = (cppVar_76650 & cppMask_un_16_);
	cppVar_76651 = ROM.rd(cppVar_76650);
	cppVar_76653 = (cppVar_76651 == 128);
	if (cppVar_76653) {
	cppVar_76649 = P0;
	} else {
	cppVar_76655 = PC + 1;
	cppVar_76655 = (cppVar_76655 & cppMask_un_16_);
	cppVar_76656 = ROM.rd(cppVar_76655);
	cppVar_76658 = (cppVar_76656 == 129);
	if (cppVar_76658) {
	cppVar_76654 = SP;
	} else {
	cppVar_76660 = PC + 1;
	cppVar_76660 = (cppVar_76660 & cppMask_un_16_);
	cppVar_76661 = ROM.rd(cppVar_76660);
	cppVar_76663 = (cppVar_76661 == 130);
	if (cppVar_76663) {
	cppVar_76659 = DPL;
	} else {
	cppVar_76665 = PC + 1;
	cppVar_76665 = (cppVar_76665 & cppMask_un_16_);
	cppVar_76666 = ROM.rd(cppVar_76665);
	cppVar_76668 = (cppVar_76666 == 131);
	if (cppVar_76668) {
	cppVar_76664 = DPH;
	} else {
	cppVar_76670 = PC + 1;
	cppVar_76670 = (cppVar_76670 & cppMask_un_16_);
	cppVar_76671 = ROM.rd(cppVar_76670);
	cppVar_76673 = (cppVar_76671 == 135);
	if (cppVar_76673) {
	cppVar_76669 = PCON;
	} else {
	cppVar_76675 = PC + 1;
	cppVar_76675 = (cppVar_76675 & cppMask_un_16_);
	cppVar_76676 = ROM.rd(cppVar_76675);
	cppVar_76678 = (cppVar_76676 == 136);
	if (cppVar_76678) {
	cppVar_76674 = TCON;
	} else {
	cppVar_76680 = PC + 1;
	cppVar_76680 = (cppVar_76680 & cppMask_un_16_);
	cppVar_76681 = ROM.rd(cppVar_76680);
	cppVar_76683 = (cppVar_76681 == 137);
	if (cppVar_76683) {
	cppVar_76679 = TMOD;
	} else {
	cppVar_76685 = PC + 1;
	cppVar_76685 = (cppVar_76685 & cppMask_un_16_);
	cppVar_76686 = ROM.rd(cppVar_76685);
	cppVar_76688 = (cppVar_76686 == 138);
	if (cppVar_76688) {
	cppVar_76684 = TL0;
	} else {
	cppVar_76690 = PC + 1;
	cppVar_76690 = (cppVar_76690 & cppMask_un_16_);
	cppVar_76691 = ROM.rd(cppVar_76690);
	cppVar_76693 = (cppVar_76691 == 140);
	if (cppVar_76693) {
	cppVar_76689 = TH0;
	} else {
	cppVar_76695 = PC + 1;
	cppVar_76695 = (cppVar_76695 & cppMask_un_16_);
	cppVar_76696 = ROM.rd(cppVar_76695);
	cppVar_76698 = (cppVar_76696 == 139);
	if (cppVar_76698) {
	cppVar_76694 = TL1;
	} else {
	cppVar_76700 = PC + 1;
	cppVar_76700 = (cppVar_76700 & cppMask_un_16_);
	cppVar_76701 = ROM.rd(cppVar_76700);
	cppVar_76703 = (cppVar_76701 == 141);
	if (cppVar_76703) {
	cppVar_76699 = TH1;
	} else {
	cppVar_76705 = PC + 1;
	cppVar_76705 = (cppVar_76705 & cppMask_un_16_);
	cppVar_76706 = ROM.rd(cppVar_76705);
	cppVar_76708 = (cppVar_76706 == 144);
	if (cppVar_76708) {
	cppVar_76704 = P1;
	} else {
	cppVar_76710 = PC + 1;
	cppVar_76710 = (cppVar_76710 & cppMask_un_16_);
	cppVar_76711 = ROM.rd(cppVar_76710);
	cppVar_76713 = (cppVar_76711 == 152);
	if (cppVar_76713) {
	cppVar_76709 = SCON;
	} else {
	cppVar_76715 = PC + 1;
	cppVar_76715 = (cppVar_76715 & cppMask_un_16_);
	cppVar_76716 = ROM.rd(cppVar_76715);
	cppVar_76718 = (cppVar_76716 == 153);
	if (cppVar_76718) {
	cppVar_76714 = SBUF;
	} else {
	cppVar_76720 = PC + 1;
	cppVar_76720 = (cppVar_76720 & cppMask_un_16_);
	cppVar_76721 = ROM.rd(cppVar_76720);
	cppVar_76723 = (cppVar_76721 == 160);
	if (cppVar_76723) {
	cppVar_76719 = P2;
	} else {
	cppVar_76725 = PC + 1;
	cppVar_76725 = (cppVar_76725 & cppMask_un_16_);
	cppVar_76726 = ROM.rd(cppVar_76725);
	cppVar_76728 = (cppVar_76726 == 168);
	if (cppVar_76728) {
	cppVar_76724 = IE;
	} else {
	cppVar_76730 = PC + 1;
	cppVar_76730 = (cppVar_76730 & cppMask_un_16_);
	cppVar_76731 = ROM.rd(cppVar_76730);
	cppVar_76733 = (cppVar_76731 == 176);
	if (cppVar_76733) {
	cppVar_76729 = P3;
	} else {
	cppVar_76735 = PC + 1;
	cppVar_76735 = (cppVar_76735 & cppMask_un_16_);
	cppVar_76736 = ROM.rd(cppVar_76735);
	cppVar_76738 = (cppVar_76736 == 184);
	if (cppVar_76738) {
	cppVar_76734 = IP;
	} else {
	cppVar_76740 = PC + 1;
	cppVar_76740 = (cppVar_76740 & cppMask_un_16_);
	cppVar_76741 = ROM.rd(cppVar_76740);
	cppVar_76743 = (cppVar_76741 == 208);
	if (cppVar_76743) {
	cppVar_76739 = PSW;
	} else {
	cppVar_76745 = PC + 1;
	cppVar_76745 = (cppVar_76745 & cppMask_un_16_);
	cppVar_76746 = ROM.rd(cppVar_76745);
	cppVar_76748 = (cppVar_76746 == 224);
	if (cppVar_76748) {
	cppVar_76744 = ACC;
	} else {
	cppVar_76750 = PC + 1;
	cppVar_76750 = (cppVar_76750 & cppMask_un_16_);
	cppVar_76751 = ROM.rd(cppVar_76750);
	cppVar_76753 = (cppVar_76751 == 240);
	if (cppVar_76753) {
	cppVar_76749 = B;
	} else {
	cppVar_76749 = 0;
	}
	cppVar_76744 = cppVar_76749;
	}
	cppVar_76739 = cppVar_76744;
	}
	cppVar_76734 = cppVar_76739;
	}
	cppVar_76729 = cppVar_76734;
	}
	cppVar_76724 = cppVar_76729;
	}
	cppVar_76719 = cppVar_76724;
	}
	cppVar_76714 = cppVar_76719;
	}
	cppVar_76709 = cppVar_76714;
	}
	cppVar_76704 = cppVar_76709;
	}
	cppVar_76699 = cppVar_76704;
	}
	cppVar_76694 = cppVar_76699;
	}
	cppVar_76689 = cppVar_76694;
	}
	cppVar_76684 = cppVar_76689;
	}
	cppVar_76679 = cppVar_76684;
	}
	cppVar_76674 = cppVar_76679;
	}
	cppVar_76669 = cppVar_76674;
	}
	cppVar_76664 = cppVar_76669;
	}
	cppVar_76659 = cppVar_76664;
	}
	cppVar_76654 = cppVar_76659;
	}
	cppVar_76649 = cppVar_76654;
	}
	cppVar_76640 = cppVar_76649;
	}
	cppVar_76755 = cppVar_76640 & ACC;
	cppVar_76634 = cppVar_76755;
	} else {
	cppVar_76634 = TH1;
	}
	cppVar_76630 = cppVar_76634;
	} else {
	cppVar_76757 = ROM.rd(PC);
	cppVar_76759 = (cppVar_76757 == 67);
	if (cppVar_76759) {
	cppVar_76762 = PC + 1;
	cppVar_76762 = (cppVar_76762 & cppMask_un_16_);
	cppVar_76763 = ROM.rd(cppVar_76762);
	cppVar_76765 = (cppVar_76763 == 141);
	if (cppVar_76765) {
	cppVar_76767 = PC + 1;
	cppVar_76767 = (cppVar_76767 & cppMask_un_16_);
	cppVar_76768 = ROM.rd(cppVar_76767);
	cppVar_76769 = (cppVar_76768 >> 7) & cppMask_un_1_;
	cppVar_76771 = (cppVar_76769 == 0);
	if (cppVar_76771) {
	cppVar_76772 = PC + 1;
	cppVar_76772 = (cppVar_76772 & cppMask_un_16_);
	cppVar_76773 = ROM.rd(cppVar_76772);
	cppVar_76774 = IRAM.rd(cppVar_76773);
	cppVar_76766 = cppVar_76774;
	} else {
	cppVar_76776 = PC + 1;
	cppVar_76776 = (cppVar_76776 & cppMask_un_16_);
	cppVar_76777 = ROM.rd(cppVar_76776);
	cppVar_76779 = (cppVar_76777 == 128);
	if (cppVar_76779) {
	cppVar_76775 = P0;
	} else {
	cppVar_76781 = PC + 1;
	cppVar_76781 = (cppVar_76781 & cppMask_un_16_);
	cppVar_76782 = ROM.rd(cppVar_76781);
	cppVar_76784 = (cppVar_76782 == 129);
	if (cppVar_76784) {
	cppVar_76780 = SP;
	} else {
	cppVar_76786 = PC + 1;
	cppVar_76786 = (cppVar_76786 & cppMask_un_16_);
	cppVar_76787 = ROM.rd(cppVar_76786);
	cppVar_76789 = (cppVar_76787 == 130);
	if (cppVar_76789) {
	cppVar_76785 = DPL;
	} else {
	cppVar_76791 = PC + 1;
	cppVar_76791 = (cppVar_76791 & cppMask_un_16_);
	cppVar_76792 = ROM.rd(cppVar_76791);
	cppVar_76794 = (cppVar_76792 == 131);
	if (cppVar_76794) {
	cppVar_76790 = DPH;
	} else {
	cppVar_76796 = PC + 1;
	cppVar_76796 = (cppVar_76796 & cppMask_un_16_);
	cppVar_76797 = ROM.rd(cppVar_76796);
	cppVar_76799 = (cppVar_76797 == 135);
	if (cppVar_76799) {
	cppVar_76795 = PCON;
	} else {
	cppVar_76801 = PC + 1;
	cppVar_76801 = (cppVar_76801 & cppMask_un_16_);
	cppVar_76802 = ROM.rd(cppVar_76801);
	cppVar_76804 = (cppVar_76802 == 136);
	if (cppVar_76804) {
	cppVar_76800 = TCON;
	} else {
	cppVar_76806 = PC + 1;
	cppVar_76806 = (cppVar_76806 & cppMask_un_16_);
	cppVar_76807 = ROM.rd(cppVar_76806);
	cppVar_76809 = (cppVar_76807 == 137);
	if (cppVar_76809) {
	cppVar_76805 = TMOD;
	} else {
	cppVar_76811 = PC + 1;
	cppVar_76811 = (cppVar_76811 & cppMask_un_16_);
	cppVar_76812 = ROM.rd(cppVar_76811);
	cppVar_76814 = (cppVar_76812 == 138);
	if (cppVar_76814) {
	cppVar_76810 = TL0;
	} else {
	cppVar_76816 = PC + 1;
	cppVar_76816 = (cppVar_76816 & cppMask_un_16_);
	cppVar_76817 = ROM.rd(cppVar_76816);
	cppVar_76819 = (cppVar_76817 == 140);
	if (cppVar_76819) {
	cppVar_76815 = TH0;
	} else {
	cppVar_76821 = PC + 1;
	cppVar_76821 = (cppVar_76821 & cppMask_un_16_);
	cppVar_76822 = ROM.rd(cppVar_76821);
	cppVar_76824 = (cppVar_76822 == 139);
	if (cppVar_76824) {
	cppVar_76820 = TL1;
	} else {
	cppVar_76826 = PC + 1;
	cppVar_76826 = (cppVar_76826 & cppMask_un_16_);
	cppVar_76827 = ROM.rd(cppVar_76826);
	cppVar_76829 = (cppVar_76827 == 141);
	if (cppVar_76829) {
	cppVar_76825 = TH1;
	} else {
	cppVar_76831 = PC + 1;
	cppVar_76831 = (cppVar_76831 & cppMask_un_16_);
	cppVar_76832 = ROM.rd(cppVar_76831);
	cppVar_76834 = (cppVar_76832 == 144);
	if (cppVar_76834) {
	cppVar_76830 = P1;
	} else {
	cppVar_76836 = PC + 1;
	cppVar_76836 = (cppVar_76836 & cppMask_un_16_);
	cppVar_76837 = ROM.rd(cppVar_76836);
	cppVar_76839 = (cppVar_76837 == 152);
	if (cppVar_76839) {
	cppVar_76835 = SCON;
	} else {
	cppVar_76841 = PC + 1;
	cppVar_76841 = (cppVar_76841 & cppMask_un_16_);
	cppVar_76842 = ROM.rd(cppVar_76841);
	cppVar_76844 = (cppVar_76842 == 153);
	if (cppVar_76844) {
	cppVar_76840 = SBUF;
	} else {
	cppVar_76846 = PC + 1;
	cppVar_76846 = (cppVar_76846 & cppMask_un_16_);
	cppVar_76847 = ROM.rd(cppVar_76846);
	cppVar_76849 = (cppVar_76847 == 160);
	if (cppVar_76849) {
	cppVar_76845 = P2;
	} else {
	cppVar_76851 = PC + 1;
	cppVar_76851 = (cppVar_76851 & cppMask_un_16_);
	cppVar_76852 = ROM.rd(cppVar_76851);
	cppVar_76854 = (cppVar_76852 == 168);
	if (cppVar_76854) {
	cppVar_76850 = IE;
	} else {
	cppVar_76856 = PC + 1;
	cppVar_76856 = (cppVar_76856 & cppMask_un_16_);
	cppVar_76857 = ROM.rd(cppVar_76856);
	cppVar_76859 = (cppVar_76857 == 176);
	if (cppVar_76859) {
	cppVar_76855 = P3;
	} else {
	cppVar_76861 = PC + 1;
	cppVar_76861 = (cppVar_76861 & cppMask_un_16_);
	cppVar_76862 = ROM.rd(cppVar_76861);
	cppVar_76864 = (cppVar_76862 == 184);
	if (cppVar_76864) {
	cppVar_76860 = IP;
	} else {
	cppVar_76866 = PC + 1;
	cppVar_76866 = (cppVar_76866 & cppMask_un_16_);
	cppVar_76867 = ROM.rd(cppVar_76866);
	cppVar_76869 = (cppVar_76867 == 208);
	if (cppVar_76869) {
	cppVar_76865 = PSW;
	} else {
	cppVar_76871 = PC + 1;
	cppVar_76871 = (cppVar_76871 & cppMask_un_16_);
	cppVar_76872 = ROM.rd(cppVar_76871);
	cppVar_76874 = (cppVar_76872 == 224);
	if (cppVar_76874) {
	cppVar_76870 = ACC;
	} else {
	cppVar_76876 = PC + 1;
	cppVar_76876 = (cppVar_76876 & cppMask_un_16_);
	cppVar_76877 = ROM.rd(cppVar_76876);
	cppVar_76879 = (cppVar_76877 == 240);
	if (cppVar_76879) {
	cppVar_76875 = B;
	} else {
	cppVar_76875 = 0;
	}
	cppVar_76870 = cppVar_76875;
	}
	cppVar_76865 = cppVar_76870;
	}
	cppVar_76860 = cppVar_76865;
	}
	cppVar_76855 = cppVar_76860;
	}
	cppVar_76850 = cppVar_76855;
	}
	cppVar_76845 = cppVar_76850;
	}
	cppVar_76840 = cppVar_76845;
	}
	cppVar_76835 = cppVar_76840;
	}
	cppVar_76830 = cppVar_76835;
	}
	cppVar_76825 = cppVar_76830;
	}
	cppVar_76820 = cppVar_76825;
	}
	cppVar_76815 = cppVar_76820;
	}
	cppVar_76810 = cppVar_76815;
	}
	cppVar_76805 = cppVar_76810;
	}
	cppVar_76800 = cppVar_76805;
	}
	cppVar_76795 = cppVar_76800;
	}
	cppVar_76790 = cppVar_76795;
	}
	cppVar_76785 = cppVar_76790;
	}
	cppVar_76780 = cppVar_76785;
	}
	cppVar_76775 = cppVar_76780;
	}
	cppVar_76766 = cppVar_76775;
	}
	cppVar_76882 = PC + 2;
	cppVar_76882 = (cppVar_76882 & cppMask_un_16_);
	cppVar_76883 = ROM.rd(cppVar_76882);
	cppVar_76884 = cppVar_76766 | cppVar_76883;
	cppVar_76760 = cppVar_76884;
	} else {
	cppVar_76760 = TH1;
	}
	cppVar_76756 = cppVar_76760;
	} else {
	cppVar_76886 = ROM.rd(PC);
	cppVar_76888 = (cppVar_76886 == 66);
	if (cppVar_76888) {
	cppVar_76891 = PC + 1;
	cppVar_76891 = (cppVar_76891 & cppMask_un_16_);
	cppVar_76892 = ROM.rd(cppVar_76891);
	cppVar_76894 = (cppVar_76892 == 141);
	if (cppVar_76894) {
	cppVar_76896 = PC + 1;
	cppVar_76896 = (cppVar_76896 & cppMask_un_16_);
	cppVar_76897 = ROM.rd(cppVar_76896);
	cppVar_76898 = (cppVar_76897 >> 7) & cppMask_un_1_;
	cppVar_76900 = (cppVar_76898 == 0);
	if (cppVar_76900) {
	cppVar_76901 = PC + 1;
	cppVar_76901 = (cppVar_76901 & cppMask_un_16_);
	cppVar_76902 = ROM.rd(cppVar_76901);
	cppVar_76903 = IRAM.rd(cppVar_76902);
	cppVar_76895 = cppVar_76903;
	} else {
	cppVar_76905 = PC + 1;
	cppVar_76905 = (cppVar_76905 & cppMask_un_16_);
	cppVar_76906 = ROM.rd(cppVar_76905);
	cppVar_76908 = (cppVar_76906 == 128);
	if (cppVar_76908) {
	cppVar_76904 = P0;
	} else {
	cppVar_76910 = PC + 1;
	cppVar_76910 = (cppVar_76910 & cppMask_un_16_);
	cppVar_76911 = ROM.rd(cppVar_76910);
	cppVar_76913 = (cppVar_76911 == 129);
	if (cppVar_76913) {
	cppVar_76909 = SP;
	} else {
	cppVar_76915 = PC + 1;
	cppVar_76915 = (cppVar_76915 & cppMask_un_16_);
	cppVar_76916 = ROM.rd(cppVar_76915);
	cppVar_76918 = (cppVar_76916 == 130);
	if (cppVar_76918) {
	cppVar_76914 = DPL;
	} else {
	cppVar_76920 = PC + 1;
	cppVar_76920 = (cppVar_76920 & cppMask_un_16_);
	cppVar_76921 = ROM.rd(cppVar_76920);
	cppVar_76923 = (cppVar_76921 == 131);
	if (cppVar_76923) {
	cppVar_76919 = DPH;
	} else {
	cppVar_76925 = PC + 1;
	cppVar_76925 = (cppVar_76925 & cppMask_un_16_);
	cppVar_76926 = ROM.rd(cppVar_76925);
	cppVar_76928 = (cppVar_76926 == 135);
	if (cppVar_76928) {
	cppVar_76924 = PCON;
	} else {
	cppVar_76930 = PC + 1;
	cppVar_76930 = (cppVar_76930 & cppMask_un_16_);
	cppVar_76931 = ROM.rd(cppVar_76930);
	cppVar_76933 = (cppVar_76931 == 136);
	if (cppVar_76933) {
	cppVar_76929 = TCON;
	} else {
	cppVar_76935 = PC + 1;
	cppVar_76935 = (cppVar_76935 & cppMask_un_16_);
	cppVar_76936 = ROM.rd(cppVar_76935);
	cppVar_76938 = (cppVar_76936 == 137);
	if (cppVar_76938) {
	cppVar_76934 = TMOD;
	} else {
	cppVar_76940 = PC + 1;
	cppVar_76940 = (cppVar_76940 & cppMask_un_16_);
	cppVar_76941 = ROM.rd(cppVar_76940);
	cppVar_76943 = (cppVar_76941 == 138);
	if (cppVar_76943) {
	cppVar_76939 = TL0;
	} else {
	cppVar_76945 = PC + 1;
	cppVar_76945 = (cppVar_76945 & cppMask_un_16_);
	cppVar_76946 = ROM.rd(cppVar_76945);
	cppVar_76948 = (cppVar_76946 == 140);
	if (cppVar_76948) {
	cppVar_76944 = TH0;
	} else {
	cppVar_76950 = PC + 1;
	cppVar_76950 = (cppVar_76950 & cppMask_un_16_);
	cppVar_76951 = ROM.rd(cppVar_76950);
	cppVar_76953 = (cppVar_76951 == 139);
	if (cppVar_76953) {
	cppVar_76949 = TL1;
	} else {
	cppVar_76955 = PC + 1;
	cppVar_76955 = (cppVar_76955 & cppMask_un_16_);
	cppVar_76956 = ROM.rd(cppVar_76955);
	cppVar_76958 = (cppVar_76956 == 141);
	if (cppVar_76958) {
	cppVar_76954 = TH1;
	} else {
	cppVar_76960 = PC + 1;
	cppVar_76960 = (cppVar_76960 & cppMask_un_16_);
	cppVar_76961 = ROM.rd(cppVar_76960);
	cppVar_76963 = (cppVar_76961 == 144);
	if (cppVar_76963) {
	cppVar_76959 = P1;
	} else {
	cppVar_76965 = PC + 1;
	cppVar_76965 = (cppVar_76965 & cppMask_un_16_);
	cppVar_76966 = ROM.rd(cppVar_76965);
	cppVar_76968 = (cppVar_76966 == 152);
	if (cppVar_76968) {
	cppVar_76964 = SCON;
	} else {
	cppVar_76970 = PC + 1;
	cppVar_76970 = (cppVar_76970 & cppMask_un_16_);
	cppVar_76971 = ROM.rd(cppVar_76970);
	cppVar_76973 = (cppVar_76971 == 153);
	if (cppVar_76973) {
	cppVar_76969 = SBUF;
	} else {
	cppVar_76975 = PC + 1;
	cppVar_76975 = (cppVar_76975 & cppMask_un_16_);
	cppVar_76976 = ROM.rd(cppVar_76975);
	cppVar_76978 = (cppVar_76976 == 160);
	if (cppVar_76978) {
	cppVar_76974 = P2;
	} else {
	cppVar_76980 = PC + 1;
	cppVar_76980 = (cppVar_76980 & cppMask_un_16_);
	cppVar_76981 = ROM.rd(cppVar_76980);
	cppVar_76983 = (cppVar_76981 == 168);
	if (cppVar_76983) {
	cppVar_76979 = IE;
	} else {
	cppVar_76985 = PC + 1;
	cppVar_76985 = (cppVar_76985 & cppMask_un_16_);
	cppVar_76986 = ROM.rd(cppVar_76985);
	cppVar_76988 = (cppVar_76986 == 176);
	if (cppVar_76988) {
	cppVar_76984 = P3;
	} else {
	cppVar_76990 = PC + 1;
	cppVar_76990 = (cppVar_76990 & cppMask_un_16_);
	cppVar_76991 = ROM.rd(cppVar_76990);
	cppVar_76993 = (cppVar_76991 == 184);
	if (cppVar_76993) {
	cppVar_76989 = IP;
	} else {
	cppVar_76995 = PC + 1;
	cppVar_76995 = (cppVar_76995 & cppMask_un_16_);
	cppVar_76996 = ROM.rd(cppVar_76995);
	cppVar_76998 = (cppVar_76996 == 208);
	if (cppVar_76998) {
	cppVar_76994 = PSW;
	} else {
	cppVar_77000 = PC + 1;
	cppVar_77000 = (cppVar_77000 & cppMask_un_16_);
	cppVar_77001 = ROM.rd(cppVar_77000);
	cppVar_77003 = (cppVar_77001 == 224);
	if (cppVar_77003) {
	cppVar_76999 = ACC;
	} else {
	cppVar_77005 = PC + 1;
	cppVar_77005 = (cppVar_77005 & cppMask_un_16_);
	cppVar_77006 = ROM.rd(cppVar_77005);
	cppVar_77008 = (cppVar_77006 == 240);
	if (cppVar_77008) {
	cppVar_77004 = B;
	} else {
	cppVar_77004 = 0;
	}
	cppVar_76999 = cppVar_77004;
	}
	cppVar_76994 = cppVar_76999;
	}
	cppVar_76989 = cppVar_76994;
	}
	cppVar_76984 = cppVar_76989;
	}
	cppVar_76979 = cppVar_76984;
	}
	cppVar_76974 = cppVar_76979;
	}
	cppVar_76969 = cppVar_76974;
	}
	cppVar_76964 = cppVar_76969;
	}
	cppVar_76959 = cppVar_76964;
	}
	cppVar_76954 = cppVar_76959;
	}
	cppVar_76949 = cppVar_76954;
	}
	cppVar_76944 = cppVar_76949;
	}
	cppVar_76939 = cppVar_76944;
	}
	cppVar_76934 = cppVar_76939;
	}
	cppVar_76929 = cppVar_76934;
	}
	cppVar_76924 = cppVar_76929;
	}
	cppVar_76919 = cppVar_76924;
	}
	cppVar_76914 = cppVar_76919;
	}
	cppVar_76909 = cppVar_76914;
	}
	cppVar_76904 = cppVar_76909;
	}
	cppVar_76895 = cppVar_76904;
	}
	cppVar_77010 = cppVar_76895 | ACC;
	cppVar_76889 = cppVar_77010;
	} else {
	cppVar_76889 = TH1;
	}
	cppVar_76885 = cppVar_76889;
	} else {
	cppVar_77012 = ROM.rd(PC);
	cppVar_77014 = (cppVar_77012 == 213);
	cppVar_77015 = ROM.rd(PC);
	cppVar_77017 = (cppVar_77015 == 21);
	cppVar_77018 = cppVar_77014 || cppVar_77017;
	if (cppVar_77018) {
	cppVar_77021 = PC + 1;
	cppVar_77021 = (cppVar_77021 & cppMask_un_16_);
	cppVar_77022 = ROM.rd(cppVar_77021);
	cppVar_77024 = (cppVar_77022 == 141);
	if (cppVar_77024) {
	cppVar_77026 = PC + 1;
	cppVar_77026 = (cppVar_77026 & cppMask_un_16_);
	cppVar_77027 = ROM.rd(cppVar_77026);
	cppVar_77028 = (cppVar_77027 >> 7) & cppMask_un_1_;
	cppVar_77030 = (cppVar_77028 == 0);
	if (cppVar_77030) {
	cppVar_77031 = PC + 1;
	cppVar_77031 = (cppVar_77031 & cppMask_un_16_);
	cppVar_77032 = ROM.rd(cppVar_77031);
	cppVar_77033 = IRAM.rd(cppVar_77032);
	cppVar_77025 = cppVar_77033;
	} else {
	cppVar_77035 = PC + 1;
	cppVar_77035 = (cppVar_77035 & cppMask_un_16_);
	cppVar_77036 = ROM.rd(cppVar_77035);
	cppVar_77038 = (cppVar_77036 == 128);
	if (cppVar_77038) {
	cppVar_77034 = P0;
	} else {
	cppVar_77040 = PC + 1;
	cppVar_77040 = (cppVar_77040 & cppMask_un_16_);
	cppVar_77041 = ROM.rd(cppVar_77040);
	cppVar_77043 = (cppVar_77041 == 129);
	if (cppVar_77043) {
	cppVar_77039 = SP;
	} else {
	cppVar_77045 = PC + 1;
	cppVar_77045 = (cppVar_77045 & cppMask_un_16_);
	cppVar_77046 = ROM.rd(cppVar_77045);
	cppVar_77048 = (cppVar_77046 == 130);
	if (cppVar_77048) {
	cppVar_77044 = DPL;
	} else {
	cppVar_77050 = PC + 1;
	cppVar_77050 = (cppVar_77050 & cppMask_un_16_);
	cppVar_77051 = ROM.rd(cppVar_77050);
	cppVar_77053 = (cppVar_77051 == 131);
	if (cppVar_77053) {
	cppVar_77049 = DPH;
	} else {
	cppVar_77055 = PC + 1;
	cppVar_77055 = (cppVar_77055 & cppMask_un_16_);
	cppVar_77056 = ROM.rd(cppVar_77055);
	cppVar_77058 = (cppVar_77056 == 135);
	if (cppVar_77058) {
	cppVar_77054 = PCON;
	} else {
	cppVar_77060 = PC + 1;
	cppVar_77060 = (cppVar_77060 & cppMask_un_16_);
	cppVar_77061 = ROM.rd(cppVar_77060);
	cppVar_77063 = (cppVar_77061 == 136);
	if (cppVar_77063) {
	cppVar_77059 = TCON;
	} else {
	cppVar_77065 = PC + 1;
	cppVar_77065 = (cppVar_77065 & cppMask_un_16_);
	cppVar_77066 = ROM.rd(cppVar_77065);
	cppVar_77068 = (cppVar_77066 == 137);
	if (cppVar_77068) {
	cppVar_77064 = TMOD;
	} else {
	cppVar_77070 = PC + 1;
	cppVar_77070 = (cppVar_77070 & cppMask_un_16_);
	cppVar_77071 = ROM.rd(cppVar_77070);
	cppVar_77073 = (cppVar_77071 == 138);
	if (cppVar_77073) {
	cppVar_77069 = TL0;
	} else {
	cppVar_77075 = PC + 1;
	cppVar_77075 = (cppVar_77075 & cppMask_un_16_);
	cppVar_77076 = ROM.rd(cppVar_77075);
	cppVar_77078 = (cppVar_77076 == 140);
	if (cppVar_77078) {
	cppVar_77074 = TH0;
	} else {
	cppVar_77080 = PC + 1;
	cppVar_77080 = (cppVar_77080 & cppMask_un_16_);
	cppVar_77081 = ROM.rd(cppVar_77080);
	cppVar_77083 = (cppVar_77081 == 139);
	if (cppVar_77083) {
	cppVar_77079 = TL1;
	} else {
	cppVar_77085 = PC + 1;
	cppVar_77085 = (cppVar_77085 & cppMask_un_16_);
	cppVar_77086 = ROM.rd(cppVar_77085);
	cppVar_77088 = (cppVar_77086 == 141);
	if (cppVar_77088) {
	cppVar_77084 = TH1;
	} else {
	cppVar_77090 = PC + 1;
	cppVar_77090 = (cppVar_77090 & cppMask_un_16_);
	cppVar_77091 = ROM.rd(cppVar_77090);
	cppVar_77093 = (cppVar_77091 == 144);
	if (cppVar_77093) {
	cppVar_77089 = P1;
	} else {
	cppVar_77095 = PC + 1;
	cppVar_77095 = (cppVar_77095 & cppMask_un_16_);
	cppVar_77096 = ROM.rd(cppVar_77095);
	cppVar_77098 = (cppVar_77096 == 152);
	if (cppVar_77098) {
	cppVar_77094 = SCON;
	} else {
	cppVar_77100 = PC + 1;
	cppVar_77100 = (cppVar_77100 & cppMask_un_16_);
	cppVar_77101 = ROM.rd(cppVar_77100);
	cppVar_77103 = (cppVar_77101 == 153);
	if (cppVar_77103) {
	cppVar_77099 = SBUF;
	} else {
	cppVar_77105 = PC + 1;
	cppVar_77105 = (cppVar_77105 & cppMask_un_16_);
	cppVar_77106 = ROM.rd(cppVar_77105);
	cppVar_77108 = (cppVar_77106 == 160);
	if (cppVar_77108) {
	cppVar_77104 = P2;
	} else {
	cppVar_77110 = PC + 1;
	cppVar_77110 = (cppVar_77110 & cppMask_un_16_);
	cppVar_77111 = ROM.rd(cppVar_77110);
	cppVar_77113 = (cppVar_77111 == 168);
	if (cppVar_77113) {
	cppVar_77109 = IE;
	} else {
	cppVar_77115 = PC + 1;
	cppVar_77115 = (cppVar_77115 & cppMask_un_16_);
	cppVar_77116 = ROM.rd(cppVar_77115);
	cppVar_77118 = (cppVar_77116 == 176);
	if (cppVar_77118) {
	cppVar_77114 = P3;
	} else {
	cppVar_77120 = PC + 1;
	cppVar_77120 = (cppVar_77120 & cppMask_un_16_);
	cppVar_77121 = ROM.rd(cppVar_77120);
	cppVar_77123 = (cppVar_77121 == 184);
	if (cppVar_77123) {
	cppVar_77119 = IP;
	} else {
	cppVar_77125 = PC + 1;
	cppVar_77125 = (cppVar_77125 & cppMask_un_16_);
	cppVar_77126 = ROM.rd(cppVar_77125);
	cppVar_77128 = (cppVar_77126 == 208);
	if (cppVar_77128) {
	cppVar_77124 = PSW;
	} else {
	cppVar_77130 = PC + 1;
	cppVar_77130 = (cppVar_77130 & cppMask_un_16_);
	cppVar_77131 = ROM.rd(cppVar_77130);
	cppVar_77133 = (cppVar_77131 == 224);
	if (cppVar_77133) {
	cppVar_77129 = ACC;
	} else {
	cppVar_77135 = PC + 1;
	cppVar_77135 = (cppVar_77135 & cppMask_un_16_);
	cppVar_77136 = ROM.rd(cppVar_77135);
	cppVar_77138 = (cppVar_77136 == 240);
	if (cppVar_77138) {
	cppVar_77134 = B;
	} else {
	cppVar_77134 = 0;
	}
	cppVar_77129 = cppVar_77134;
	}
	cppVar_77124 = cppVar_77129;
	}
	cppVar_77119 = cppVar_77124;
	}
	cppVar_77114 = cppVar_77119;
	}
	cppVar_77109 = cppVar_77114;
	}
	cppVar_77104 = cppVar_77109;
	}
	cppVar_77099 = cppVar_77104;
	}
	cppVar_77094 = cppVar_77099;
	}
	cppVar_77089 = cppVar_77094;
	}
	cppVar_77084 = cppVar_77089;
	}
	cppVar_77079 = cppVar_77084;
	}
	cppVar_77074 = cppVar_77079;
	}
	cppVar_77069 = cppVar_77074;
	}
	cppVar_77064 = cppVar_77069;
	}
	cppVar_77059 = cppVar_77064;
	}
	cppVar_77054 = cppVar_77059;
	}
	cppVar_77049 = cppVar_77054;
	}
	cppVar_77044 = cppVar_77049;
	}
	cppVar_77039 = cppVar_77044;
	}
	cppVar_77034 = cppVar_77039;
	}
	cppVar_77025 = cppVar_77034;
	}
	cppVar_77141 = cppVar_77025 - 1;
	cppVar_77141 = (cppVar_77141 & cppMask_un_8_);
	cppVar_77019 = cppVar_77141;
	} else {
	cppVar_77019 = TH1;
	}
	cppVar_77011 = cppVar_77019;
	} else {
	cppVar_77143 = ROM.rd(PC);
	cppVar_77145 = (cppVar_77143 == 5);
	if (cppVar_77145) {
	cppVar_77148 = PC + 1;
	cppVar_77148 = (cppVar_77148 & cppMask_un_16_);
	cppVar_77149 = ROM.rd(cppVar_77148);
	cppVar_77151 = (cppVar_77149 == 141);
	if (cppVar_77151) {
	cppVar_77153 = PC + 1;
	cppVar_77153 = (cppVar_77153 & cppMask_un_16_);
	cppVar_77154 = ROM.rd(cppVar_77153);
	cppVar_77155 = (cppVar_77154 >> 7) & cppMask_un_1_;
	cppVar_77157 = (cppVar_77155 == 0);
	if (cppVar_77157) {
	cppVar_77158 = PC + 1;
	cppVar_77158 = (cppVar_77158 & cppMask_un_16_);
	cppVar_77159 = ROM.rd(cppVar_77158);
	cppVar_77160 = IRAM.rd(cppVar_77159);
	cppVar_77152 = cppVar_77160;
	} else {
	cppVar_77162 = PC + 1;
	cppVar_77162 = (cppVar_77162 & cppMask_un_16_);
	cppVar_77163 = ROM.rd(cppVar_77162);
	cppVar_77165 = (cppVar_77163 == 128);
	if (cppVar_77165) {
	cppVar_77161 = P0;
	} else {
	cppVar_77167 = PC + 1;
	cppVar_77167 = (cppVar_77167 & cppMask_un_16_);
	cppVar_77168 = ROM.rd(cppVar_77167);
	cppVar_77170 = (cppVar_77168 == 129);
	if (cppVar_77170) {
	cppVar_77166 = SP;
	} else {
	cppVar_77172 = PC + 1;
	cppVar_77172 = (cppVar_77172 & cppMask_un_16_);
	cppVar_77173 = ROM.rd(cppVar_77172);
	cppVar_77175 = (cppVar_77173 == 130);
	if (cppVar_77175) {
	cppVar_77171 = DPL;
	} else {
	cppVar_77177 = PC + 1;
	cppVar_77177 = (cppVar_77177 & cppMask_un_16_);
	cppVar_77178 = ROM.rd(cppVar_77177);
	cppVar_77180 = (cppVar_77178 == 131);
	if (cppVar_77180) {
	cppVar_77176 = DPH;
	} else {
	cppVar_77182 = PC + 1;
	cppVar_77182 = (cppVar_77182 & cppMask_un_16_);
	cppVar_77183 = ROM.rd(cppVar_77182);
	cppVar_77185 = (cppVar_77183 == 135);
	if (cppVar_77185) {
	cppVar_77181 = PCON;
	} else {
	cppVar_77187 = PC + 1;
	cppVar_77187 = (cppVar_77187 & cppMask_un_16_);
	cppVar_77188 = ROM.rd(cppVar_77187);
	cppVar_77190 = (cppVar_77188 == 136);
	if (cppVar_77190) {
	cppVar_77186 = TCON;
	} else {
	cppVar_77192 = PC + 1;
	cppVar_77192 = (cppVar_77192 & cppMask_un_16_);
	cppVar_77193 = ROM.rd(cppVar_77192);
	cppVar_77195 = (cppVar_77193 == 137);
	if (cppVar_77195) {
	cppVar_77191 = TMOD;
	} else {
	cppVar_77197 = PC + 1;
	cppVar_77197 = (cppVar_77197 & cppMask_un_16_);
	cppVar_77198 = ROM.rd(cppVar_77197);
	cppVar_77200 = (cppVar_77198 == 138);
	if (cppVar_77200) {
	cppVar_77196 = TL0;
	} else {
	cppVar_77202 = PC + 1;
	cppVar_77202 = (cppVar_77202 & cppMask_un_16_);
	cppVar_77203 = ROM.rd(cppVar_77202);
	cppVar_77205 = (cppVar_77203 == 140);
	if (cppVar_77205) {
	cppVar_77201 = TH0;
	} else {
	cppVar_77207 = PC + 1;
	cppVar_77207 = (cppVar_77207 & cppMask_un_16_);
	cppVar_77208 = ROM.rd(cppVar_77207);
	cppVar_77210 = (cppVar_77208 == 139);
	if (cppVar_77210) {
	cppVar_77206 = TL1;
	} else {
	cppVar_77212 = PC + 1;
	cppVar_77212 = (cppVar_77212 & cppMask_un_16_);
	cppVar_77213 = ROM.rd(cppVar_77212);
	cppVar_77215 = (cppVar_77213 == 141);
	if (cppVar_77215) {
	cppVar_77211 = TH1;
	} else {
	cppVar_77217 = PC + 1;
	cppVar_77217 = (cppVar_77217 & cppMask_un_16_);
	cppVar_77218 = ROM.rd(cppVar_77217);
	cppVar_77220 = (cppVar_77218 == 144);
	if (cppVar_77220) {
	cppVar_77216 = P1;
	} else {
	cppVar_77222 = PC + 1;
	cppVar_77222 = (cppVar_77222 & cppMask_un_16_);
	cppVar_77223 = ROM.rd(cppVar_77222);
	cppVar_77225 = (cppVar_77223 == 152);
	if (cppVar_77225) {
	cppVar_77221 = SCON;
	} else {
	cppVar_77227 = PC + 1;
	cppVar_77227 = (cppVar_77227 & cppMask_un_16_);
	cppVar_77228 = ROM.rd(cppVar_77227);
	cppVar_77230 = (cppVar_77228 == 153);
	if (cppVar_77230) {
	cppVar_77226 = SBUF;
	} else {
	cppVar_77232 = PC + 1;
	cppVar_77232 = (cppVar_77232 & cppMask_un_16_);
	cppVar_77233 = ROM.rd(cppVar_77232);
	cppVar_77235 = (cppVar_77233 == 160);
	if (cppVar_77235) {
	cppVar_77231 = P2;
	} else {
	cppVar_77237 = PC + 1;
	cppVar_77237 = (cppVar_77237 & cppMask_un_16_);
	cppVar_77238 = ROM.rd(cppVar_77237);
	cppVar_77240 = (cppVar_77238 == 168);
	if (cppVar_77240) {
	cppVar_77236 = IE;
	} else {
	cppVar_77242 = PC + 1;
	cppVar_77242 = (cppVar_77242 & cppMask_un_16_);
	cppVar_77243 = ROM.rd(cppVar_77242);
	cppVar_77245 = (cppVar_77243 == 176);
	if (cppVar_77245) {
	cppVar_77241 = P3;
	} else {
	cppVar_77247 = PC + 1;
	cppVar_77247 = (cppVar_77247 & cppMask_un_16_);
	cppVar_77248 = ROM.rd(cppVar_77247);
	cppVar_77250 = (cppVar_77248 == 184);
	if (cppVar_77250) {
	cppVar_77246 = IP;
	} else {
	cppVar_77252 = PC + 1;
	cppVar_77252 = (cppVar_77252 & cppMask_un_16_);
	cppVar_77253 = ROM.rd(cppVar_77252);
	cppVar_77255 = (cppVar_77253 == 208);
	if (cppVar_77255) {
	cppVar_77251 = PSW;
	} else {
	cppVar_77257 = PC + 1;
	cppVar_77257 = (cppVar_77257 & cppMask_un_16_);
	cppVar_77258 = ROM.rd(cppVar_77257);
	cppVar_77260 = (cppVar_77258 == 224);
	if (cppVar_77260) {
	cppVar_77256 = ACC;
	} else {
	cppVar_77262 = PC + 1;
	cppVar_77262 = (cppVar_77262 & cppMask_un_16_);
	cppVar_77263 = ROM.rd(cppVar_77262);
	cppVar_77265 = (cppVar_77263 == 240);
	if (cppVar_77265) {
	cppVar_77261 = B;
	} else {
	cppVar_77261 = 0;
	}
	cppVar_77256 = cppVar_77261;
	}
	cppVar_77251 = cppVar_77256;
	}
	cppVar_77246 = cppVar_77251;
	}
	cppVar_77241 = cppVar_77246;
	}
	cppVar_77236 = cppVar_77241;
	}
	cppVar_77231 = cppVar_77236;
	}
	cppVar_77226 = cppVar_77231;
	}
	cppVar_77221 = cppVar_77226;
	}
	cppVar_77216 = cppVar_77221;
	}
	cppVar_77211 = cppVar_77216;
	}
	cppVar_77206 = cppVar_77211;
	}
	cppVar_77201 = cppVar_77206;
	}
	cppVar_77196 = cppVar_77201;
	}
	cppVar_77191 = cppVar_77196;
	}
	cppVar_77186 = cppVar_77191;
	}
	cppVar_77181 = cppVar_77186;
	}
	cppVar_77176 = cppVar_77181;
	}
	cppVar_77171 = cppVar_77176;
	}
	cppVar_77166 = cppVar_77171;
	}
	cppVar_77161 = cppVar_77166;
	}
	cppVar_77152 = cppVar_77161;
	}
	cppVar_77268 = cppVar_77152 + 1;
	cppVar_77268 = (cppVar_77268 & cppMask_un_8_);
	cppVar_77146 = cppVar_77268;
	} else {
	cppVar_77146 = TH1;
	}
	cppVar_77142 = cppVar_77146;
	} else {
	cppVar_77142 = TH1;
	}
	cppVar_77011 = cppVar_77142;
	}
	cppVar_76885 = cppVar_77011;
	}
	cppVar_76756 = cppVar_76885;
	}
	cppVar_76630 = cppVar_76756;
	}
	cppVar_76501 = cppVar_76630;
	}
	cppVar_76375 = cppVar_76501;
	}
	cppVar_76246 = cppVar_76375;
	}
	cppVar_76233 = cppVar_76246;
	}
	cppVar_76107 = cppVar_76233;
	}
	cppVar_76090 = cppVar_76107;
	}
	cppVar_76073 = cppVar_76090;
	}
	cppVar_75923 = cppVar_76073;
	}
	cppVar_75773 = cppVar_75923;
	}
	cppVar_75623 = cppVar_75773;
	}
	cppVar_75473 = cppVar_75623;
	}
	cppVar_75323 = cppVar_75473;
	}
	cppVar_75173 = cppVar_75323;
	}
	cppVar_75023 = cppVar_75173;
	}
	cppVar_74873 = cppVar_75023;
	}
	cppVar_74859 = cppVar_74873;
	}
	cppVar_74848 = cppVar_74859;
	}
	return cppVar_74848;
}
