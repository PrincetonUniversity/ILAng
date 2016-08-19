#include "common.hpp"
#include "model_oc8051_class.hpp"

BIT_VEC model_oc8051::cppUpdateFun_SP()
{
	BIT_VEC cppVar_64084;
	BIT_VEC cppVar_64085;
	bool cppVar_64086;
	BIT_VEC cppVar_64088;
	BIT_VEC cppVar_64089;
	BIT_VEC cppVar_64090;
	BIT_VEC cppVar_64091;
	bool cppVar_64092;
	BIT_VEC cppVar_64094;
	BIT_VEC cppVar_64095;
	BIT_VEC cppVar_64096;
	bool cppVar_64097;
	BIT_VEC cppVar_64098;
	BIT_VEC cppVar_64093;
	BIT_VEC cppVar_64099;
	BIT_VEC cppVar_64100;
	BIT_VEC cppVar_64087;
	BIT_VEC cppVar_64102;
	BIT_VEC cppVar_64103;
	bool cppVar_64104;
	BIT_VEC cppVar_64105;
	BIT_VEC cppVar_64106;
	bool cppVar_64107;
	bool cppVar_64108;
	BIT_VEC cppVar_64110;
	BIT_VEC cppVar_64111;
	BIT_VEC cppVar_64112;
	BIT_VEC cppVar_64113;
	bool cppVar_64114;
	BIT_VEC cppVar_64109;
	BIT_VEC cppVar_64116;
	BIT_VEC cppVar_64117;
	bool cppVar_64118;
	BIT_VEC cppVar_64119;
	BIT_VEC cppVar_64120;
	BIT_VEC cppVar_64122;
	BIT_VEC cppVar_64123;
	bool cppVar_64124;
	BIT_VEC cppVar_64126;
	BIT_VEC cppVar_64127;
	BIT_VEC cppVar_64128;
	BIT_VEC cppVar_64129;
	bool cppVar_64130;
	BIT_VEC cppVar_64132;
	BIT_VEC cppVar_64133;
	BIT_VEC cppVar_64134;
	BIT_VEC cppVar_64135;
	BIT_VEC cppVar_64136;
	BIT_VEC cppVar_64137;
	BIT_VEC cppVar_64138;
	bool cppVar_64139;
	BIT_VEC cppVar_64140;
	BIT_VEC cppVar_64141;
	BIT_VEC cppVar_64142;
	BIT_VEC cppVar_64143;
	BIT_VEC cppVar_64145;
	BIT_VEC cppVar_64146;
	BIT_VEC cppVar_64147;
	BIT_VEC cppVar_64148;
	bool cppVar_64149;
	BIT_VEC cppVar_64151;
	BIT_VEC cppVar_64152;
	BIT_VEC cppVar_64153;
	BIT_VEC cppVar_64154;
	bool cppVar_64155;
	BIT_VEC cppVar_64157;
	BIT_VEC cppVar_64158;
	BIT_VEC cppVar_64159;
	BIT_VEC cppVar_64160;
	bool cppVar_64161;
	BIT_VEC cppVar_64163;
	BIT_VEC cppVar_64164;
	BIT_VEC cppVar_64165;
	BIT_VEC cppVar_64166;
	bool cppVar_64167;
	BIT_VEC cppVar_64169;
	BIT_VEC cppVar_64170;
	BIT_VEC cppVar_64171;
	BIT_VEC cppVar_64172;
	bool cppVar_64173;
	BIT_VEC cppVar_64175;
	BIT_VEC cppVar_64176;
	BIT_VEC cppVar_64177;
	BIT_VEC cppVar_64178;
	bool cppVar_64179;
	BIT_VEC cppVar_64181;
	BIT_VEC cppVar_64182;
	BIT_VEC cppVar_64183;
	BIT_VEC cppVar_64184;
	bool cppVar_64185;
	BIT_VEC cppVar_64187;
	BIT_VEC cppVar_64188;
	BIT_VEC cppVar_64189;
	BIT_VEC cppVar_64190;
	bool cppVar_64191;
	BIT_VEC cppVar_64193;
	BIT_VEC cppVar_64194;
	BIT_VEC cppVar_64195;
	BIT_VEC cppVar_64196;
	bool cppVar_64197;
	BIT_VEC cppVar_64199;
	BIT_VEC cppVar_64200;
	BIT_VEC cppVar_64201;
	BIT_VEC cppVar_64202;
	bool cppVar_64203;
	BIT_VEC cppVar_64205;
	BIT_VEC cppVar_64206;
	BIT_VEC cppVar_64207;
	BIT_VEC cppVar_64208;
	bool cppVar_64209;
	BIT_VEC cppVar_64211;
	BIT_VEC cppVar_64212;
	BIT_VEC cppVar_64213;
	BIT_VEC cppVar_64214;
	bool cppVar_64215;
	BIT_VEC cppVar_64217;
	BIT_VEC cppVar_64218;
	BIT_VEC cppVar_64219;
	BIT_VEC cppVar_64220;
	bool cppVar_64221;
	BIT_VEC cppVar_64223;
	BIT_VEC cppVar_64224;
	BIT_VEC cppVar_64225;
	BIT_VEC cppVar_64226;
	bool cppVar_64227;
	BIT_VEC cppVar_64229;
	BIT_VEC cppVar_64230;
	BIT_VEC cppVar_64231;
	BIT_VEC cppVar_64232;
	bool cppVar_64233;
	BIT_VEC cppVar_64235;
	BIT_VEC cppVar_64236;
	BIT_VEC cppVar_64237;
	BIT_VEC cppVar_64238;
	bool cppVar_64239;
	BIT_VEC cppVar_64241;
	BIT_VEC cppVar_64242;
	BIT_VEC cppVar_64243;
	BIT_VEC cppVar_64244;
	bool cppVar_64245;
	BIT_VEC cppVar_64247;
	BIT_VEC cppVar_64248;
	BIT_VEC cppVar_64249;
	BIT_VEC cppVar_64250;
	bool cppVar_64251;
	BIT_VEC cppVar_64253;
	BIT_VEC cppVar_64254;
	BIT_VEC cppVar_64255;
	BIT_VEC cppVar_64256;
	bool cppVar_64257;
	BIT_VEC cppVar_64259;
	BIT_VEC cppVar_64260;
	BIT_VEC cppVar_64261;
	BIT_VEC cppVar_64262;
	bool cppVar_64263;
	BIT_VEC cppVar_64265;
	BIT_VEC cppVar_64266;
	BIT_VEC cppVar_64267;
	BIT_VEC cppVar_64268;
	bool cppVar_64269;
	BIT_VEC cppVar_64270;
	BIT_VEC cppVar_64264;
	BIT_VEC cppVar_64258;
	BIT_VEC cppVar_64252;
	BIT_VEC cppVar_64246;
	BIT_VEC cppVar_64240;
	BIT_VEC cppVar_64234;
	BIT_VEC cppVar_64228;
	BIT_VEC cppVar_64222;
	BIT_VEC cppVar_64216;
	BIT_VEC cppVar_64210;
	BIT_VEC cppVar_64204;
	BIT_VEC cppVar_64198;
	BIT_VEC cppVar_64192;
	BIT_VEC cppVar_64186;
	BIT_VEC cppVar_64180;
	BIT_VEC cppVar_64174;
	BIT_VEC cppVar_64168;
	BIT_VEC cppVar_64162;
	BIT_VEC cppVar_64156;
	BIT_VEC cppVar_64150;
	BIT_VEC cppVar_64144;
	BIT_VEC cppVar_64131;
	BIT_VEC cppVar_64125;
	BIT_VEC cppVar_64272;
	BIT_VEC cppVar_64273;
	bool cppVar_64274;
	BIT_VEC cppVar_64276;
	BIT_VEC cppVar_64277;
	BIT_VEC cppVar_64278;
	BIT_VEC cppVar_64279;
	bool cppVar_64280;
	BIT_VEC cppVar_64282;
	BIT_VEC cppVar_64283;
	BIT_VEC cppVar_64284;
	BIT_VEC cppVar_64285;
	BIT_VEC cppVar_64286;
	BIT_VEC cppVar_64287;
	BIT_VEC cppVar_64288;
	bool cppVar_64289;
	BIT_VEC cppVar_64290;
	BIT_VEC cppVar_64291;
	BIT_VEC cppVar_64292;
	BIT_VEC cppVar_64293;
	BIT_VEC cppVar_64295;
	BIT_VEC cppVar_64296;
	BIT_VEC cppVar_64297;
	BIT_VEC cppVar_64298;
	bool cppVar_64299;
	BIT_VEC cppVar_64301;
	BIT_VEC cppVar_64302;
	BIT_VEC cppVar_64303;
	BIT_VEC cppVar_64304;
	bool cppVar_64305;
	BIT_VEC cppVar_64307;
	BIT_VEC cppVar_64308;
	BIT_VEC cppVar_64309;
	BIT_VEC cppVar_64310;
	bool cppVar_64311;
	BIT_VEC cppVar_64313;
	BIT_VEC cppVar_64314;
	BIT_VEC cppVar_64315;
	BIT_VEC cppVar_64316;
	bool cppVar_64317;
	BIT_VEC cppVar_64319;
	BIT_VEC cppVar_64320;
	BIT_VEC cppVar_64321;
	BIT_VEC cppVar_64322;
	bool cppVar_64323;
	BIT_VEC cppVar_64325;
	BIT_VEC cppVar_64326;
	BIT_VEC cppVar_64327;
	BIT_VEC cppVar_64328;
	bool cppVar_64329;
	BIT_VEC cppVar_64331;
	BIT_VEC cppVar_64332;
	BIT_VEC cppVar_64333;
	BIT_VEC cppVar_64334;
	bool cppVar_64335;
	BIT_VEC cppVar_64337;
	BIT_VEC cppVar_64338;
	BIT_VEC cppVar_64339;
	BIT_VEC cppVar_64340;
	bool cppVar_64341;
	BIT_VEC cppVar_64343;
	BIT_VEC cppVar_64344;
	BIT_VEC cppVar_64345;
	BIT_VEC cppVar_64346;
	bool cppVar_64347;
	BIT_VEC cppVar_64349;
	BIT_VEC cppVar_64350;
	BIT_VEC cppVar_64351;
	BIT_VEC cppVar_64352;
	bool cppVar_64353;
	BIT_VEC cppVar_64355;
	BIT_VEC cppVar_64356;
	BIT_VEC cppVar_64357;
	BIT_VEC cppVar_64358;
	bool cppVar_64359;
	BIT_VEC cppVar_64361;
	BIT_VEC cppVar_64362;
	BIT_VEC cppVar_64363;
	BIT_VEC cppVar_64364;
	bool cppVar_64365;
	BIT_VEC cppVar_64367;
	BIT_VEC cppVar_64368;
	BIT_VEC cppVar_64369;
	BIT_VEC cppVar_64370;
	bool cppVar_64371;
	BIT_VEC cppVar_64373;
	BIT_VEC cppVar_64374;
	BIT_VEC cppVar_64375;
	BIT_VEC cppVar_64376;
	bool cppVar_64377;
	BIT_VEC cppVar_64379;
	BIT_VEC cppVar_64380;
	BIT_VEC cppVar_64381;
	BIT_VEC cppVar_64382;
	bool cppVar_64383;
	BIT_VEC cppVar_64385;
	BIT_VEC cppVar_64386;
	BIT_VEC cppVar_64387;
	BIT_VEC cppVar_64388;
	bool cppVar_64389;
	BIT_VEC cppVar_64391;
	BIT_VEC cppVar_64392;
	BIT_VEC cppVar_64393;
	BIT_VEC cppVar_64394;
	bool cppVar_64395;
	BIT_VEC cppVar_64397;
	BIT_VEC cppVar_64398;
	BIT_VEC cppVar_64399;
	BIT_VEC cppVar_64400;
	bool cppVar_64401;
	BIT_VEC cppVar_64403;
	BIT_VEC cppVar_64404;
	BIT_VEC cppVar_64405;
	BIT_VEC cppVar_64406;
	bool cppVar_64407;
	BIT_VEC cppVar_64409;
	BIT_VEC cppVar_64410;
	BIT_VEC cppVar_64411;
	BIT_VEC cppVar_64412;
	bool cppVar_64413;
	BIT_VEC cppVar_64415;
	BIT_VEC cppVar_64416;
	BIT_VEC cppVar_64417;
	BIT_VEC cppVar_64418;
	bool cppVar_64419;
	BIT_VEC cppVar_64420;
	BIT_VEC cppVar_64414;
	BIT_VEC cppVar_64408;
	BIT_VEC cppVar_64402;
	BIT_VEC cppVar_64396;
	BIT_VEC cppVar_64390;
	BIT_VEC cppVar_64384;
	BIT_VEC cppVar_64378;
	BIT_VEC cppVar_64372;
	BIT_VEC cppVar_64366;
	BIT_VEC cppVar_64360;
	BIT_VEC cppVar_64354;
	BIT_VEC cppVar_64348;
	BIT_VEC cppVar_64342;
	BIT_VEC cppVar_64336;
	BIT_VEC cppVar_64330;
	BIT_VEC cppVar_64324;
	BIT_VEC cppVar_64318;
	BIT_VEC cppVar_64312;
	BIT_VEC cppVar_64306;
	BIT_VEC cppVar_64300;
	BIT_VEC cppVar_64294;
	BIT_VEC cppVar_64281;
	BIT_VEC cppVar_64275;
	BIT_VEC cppVar_64422;
	BIT_VEC cppVar_64423;
	bool cppVar_64424;
	BIT_VEC cppVar_64426;
	BIT_VEC cppVar_64427;
	BIT_VEC cppVar_64428;
	BIT_VEC cppVar_64429;
	bool cppVar_64430;
	BIT_VEC cppVar_64432;
	BIT_VEC cppVar_64433;
	BIT_VEC cppVar_64434;
	BIT_VEC cppVar_64435;
	BIT_VEC cppVar_64436;
	BIT_VEC cppVar_64437;
	BIT_VEC cppVar_64438;
	bool cppVar_64439;
	BIT_VEC cppVar_64440;
	BIT_VEC cppVar_64441;
	BIT_VEC cppVar_64442;
	BIT_VEC cppVar_64443;
	BIT_VEC cppVar_64445;
	BIT_VEC cppVar_64446;
	BIT_VEC cppVar_64447;
	BIT_VEC cppVar_64448;
	bool cppVar_64449;
	BIT_VEC cppVar_64451;
	BIT_VEC cppVar_64452;
	BIT_VEC cppVar_64453;
	BIT_VEC cppVar_64454;
	bool cppVar_64455;
	BIT_VEC cppVar_64457;
	BIT_VEC cppVar_64458;
	BIT_VEC cppVar_64459;
	BIT_VEC cppVar_64460;
	bool cppVar_64461;
	BIT_VEC cppVar_64463;
	BIT_VEC cppVar_64464;
	BIT_VEC cppVar_64465;
	BIT_VEC cppVar_64466;
	bool cppVar_64467;
	BIT_VEC cppVar_64469;
	BIT_VEC cppVar_64470;
	BIT_VEC cppVar_64471;
	BIT_VEC cppVar_64472;
	bool cppVar_64473;
	BIT_VEC cppVar_64475;
	BIT_VEC cppVar_64476;
	BIT_VEC cppVar_64477;
	BIT_VEC cppVar_64478;
	bool cppVar_64479;
	BIT_VEC cppVar_64481;
	BIT_VEC cppVar_64482;
	BIT_VEC cppVar_64483;
	BIT_VEC cppVar_64484;
	bool cppVar_64485;
	BIT_VEC cppVar_64487;
	BIT_VEC cppVar_64488;
	BIT_VEC cppVar_64489;
	BIT_VEC cppVar_64490;
	bool cppVar_64491;
	BIT_VEC cppVar_64493;
	BIT_VEC cppVar_64494;
	BIT_VEC cppVar_64495;
	BIT_VEC cppVar_64496;
	bool cppVar_64497;
	BIT_VEC cppVar_64499;
	BIT_VEC cppVar_64500;
	BIT_VEC cppVar_64501;
	BIT_VEC cppVar_64502;
	bool cppVar_64503;
	BIT_VEC cppVar_64505;
	BIT_VEC cppVar_64506;
	BIT_VEC cppVar_64507;
	BIT_VEC cppVar_64508;
	bool cppVar_64509;
	BIT_VEC cppVar_64511;
	BIT_VEC cppVar_64512;
	BIT_VEC cppVar_64513;
	BIT_VEC cppVar_64514;
	bool cppVar_64515;
	BIT_VEC cppVar_64517;
	BIT_VEC cppVar_64518;
	BIT_VEC cppVar_64519;
	BIT_VEC cppVar_64520;
	bool cppVar_64521;
	BIT_VEC cppVar_64523;
	BIT_VEC cppVar_64524;
	BIT_VEC cppVar_64525;
	BIT_VEC cppVar_64526;
	bool cppVar_64527;
	BIT_VEC cppVar_64529;
	BIT_VEC cppVar_64530;
	BIT_VEC cppVar_64531;
	BIT_VEC cppVar_64532;
	bool cppVar_64533;
	BIT_VEC cppVar_64535;
	BIT_VEC cppVar_64536;
	BIT_VEC cppVar_64537;
	BIT_VEC cppVar_64538;
	bool cppVar_64539;
	BIT_VEC cppVar_64541;
	BIT_VEC cppVar_64542;
	BIT_VEC cppVar_64543;
	BIT_VEC cppVar_64544;
	bool cppVar_64545;
	BIT_VEC cppVar_64547;
	BIT_VEC cppVar_64548;
	BIT_VEC cppVar_64549;
	BIT_VEC cppVar_64550;
	bool cppVar_64551;
	BIT_VEC cppVar_64553;
	BIT_VEC cppVar_64554;
	BIT_VEC cppVar_64555;
	BIT_VEC cppVar_64556;
	bool cppVar_64557;
	BIT_VEC cppVar_64559;
	BIT_VEC cppVar_64560;
	BIT_VEC cppVar_64561;
	BIT_VEC cppVar_64562;
	bool cppVar_64563;
	BIT_VEC cppVar_64565;
	BIT_VEC cppVar_64566;
	BIT_VEC cppVar_64567;
	BIT_VEC cppVar_64568;
	bool cppVar_64569;
	BIT_VEC cppVar_64570;
	BIT_VEC cppVar_64564;
	BIT_VEC cppVar_64558;
	BIT_VEC cppVar_64552;
	BIT_VEC cppVar_64546;
	BIT_VEC cppVar_64540;
	BIT_VEC cppVar_64534;
	BIT_VEC cppVar_64528;
	BIT_VEC cppVar_64522;
	BIT_VEC cppVar_64516;
	BIT_VEC cppVar_64510;
	BIT_VEC cppVar_64504;
	BIT_VEC cppVar_64498;
	BIT_VEC cppVar_64492;
	BIT_VEC cppVar_64486;
	BIT_VEC cppVar_64480;
	BIT_VEC cppVar_64474;
	BIT_VEC cppVar_64468;
	BIT_VEC cppVar_64462;
	BIT_VEC cppVar_64456;
	BIT_VEC cppVar_64450;
	BIT_VEC cppVar_64444;
	BIT_VEC cppVar_64431;
	BIT_VEC cppVar_64425;
	BIT_VEC cppVar_64572;
	BIT_VEC cppVar_64573;
	bool cppVar_64574;
	BIT_VEC cppVar_64576;
	BIT_VEC cppVar_64577;
	BIT_VEC cppVar_64578;
	BIT_VEC cppVar_64579;
	bool cppVar_64580;
	BIT_VEC cppVar_64582;
	BIT_VEC cppVar_64583;
	BIT_VEC cppVar_64584;
	BIT_VEC cppVar_64585;
	BIT_VEC cppVar_64586;
	BIT_VEC cppVar_64587;
	BIT_VEC cppVar_64588;
	bool cppVar_64589;
	BIT_VEC cppVar_64590;
	BIT_VEC cppVar_64591;
	BIT_VEC cppVar_64592;
	BIT_VEC cppVar_64593;
	BIT_VEC cppVar_64595;
	BIT_VEC cppVar_64596;
	BIT_VEC cppVar_64597;
	BIT_VEC cppVar_64598;
	bool cppVar_64599;
	BIT_VEC cppVar_64601;
	BIT_VEC cppVar_64602;
	BIT_VEC cppVar_64603;
	BIT_VEC cppVar_64604;
	bool cppVar_64605;
	BIT_VEC cppVar_64607;
	BIT_VEC cppVar_64608;
	BIT_VEC cppVar_64609;
	BIT_VEC cppVar_64610;
	bool cppVar_64611;
	BIT_VEC cppVar_64613;
	BIT_VEC cppVar_64614;
	BIT_VEC cppVar_64615;
	BIT_VEC cppVar_64616;
	bool cppVar_64617;
	BIT_VEC cppVar_64619;
	BIT_VEC cppVar_64620;
	BIT_VEC cppVar_64621;
	BIT_VEC cppVar_64622;
	bool cppVar_64623;
	BIT_VEC cppVar_64625;
	BIT_VEC cppVar_64626;
	BIT_VEC cppVar_64627;
	BIT_VEC cppVar_64628;
	bool cppVar_64629;
	BIT_VEC cppVar_64631;
	BIT_VEC cppVar_64632;
	BIT_VEC cppVar_64633;
	BIT_VEC cppVar_64634;
	bool cppVar_64635;
	BIT_VEC cppVar_64637;
	BIT_VEC cppVar_64638;
	BIT_VEC cppVar_64639;
	BIT_VEC cppVar_64640;
	bool cppVar_64641;
	BIT_VEC cppVar_64643;
	BIT_VEC cppVar_64644;
	BIT_VEC cppVar_64645;
	BIT_VEC cppVar_64646;
	bool cppVar_64647;
	BIT_VEC cppVar_64649;
	BIT_VEC cppVar_64650;
	BIT_VEC cppVar_64651;
	BIT_VEC cppVar_64652;
	bool cppVar_64653;
	BIT_VEC cppVar_64655;
	BIT_VEC cppVar_64656;
	BIT_VEC cppVar_64657;
	BIT_VEC cppVar_64658;
	bool cppVar_64659;
	BIT_VEC cppVar_64661;
	BIT_VEC cppVar_64662;
	BIT_VEC cppVar_64663;
	BIT_VEC cppVar_64664;
	bool cppVar_64665;
	BIT_VEC cppVar_64667;
	BIT_VEC cppVar_64668;
	BIT_VEC cppVar_64669;
	BIT_VEC cppVar_64670;
	bool cppVar_64671;
	BIT_VEC cppVar_64673;
	BIT_VEC cppVar_64674;
	BIT_VEC cppVar_64675;
	BIT_VEC cppVar_64676;
	bool cppVar_64677;
	BIT_VEC cppVar_64679;
	BIT_VEC cppVar_64680;
	BIT_VEC cppVar_64681;
	BIT_VEC cppVar_64682;
	bool cppVar_64683;
	BIT_VEC cppVar_64685;
	BIT_VEC cppVar_64686;
	BIT_VEC cppVar_64687;
	BIT_VEC cppVar_64688;
	bool cppVar_64689;
	BIT_VEC cppVar_64691;
	BIT_VEC cppVar_64692;
	BIT_VEC cppVar_64693;
	BIT_VEC cppVar_64694;
	bool cppVar_64695;
	BIT_VEC cppVar_64697;
	BIT_VEC cppVar_64698;
	BIT_VEC cppVar_64699;
	BIT_VEC cppVar_64700;
	bool cppVar_64701;
	BIT_VEC cppVar_64703;
	BIT_VEC cppVar_64704;
	BIT_VEC cppVar_64705;
	BIT_VEC cppVar_64706;
	bool cppVar_64707;
	BIT_VEC cppVar_64709;
	BIT_VEC cppVar_64710;
	BIT_VEC cppVar_64711;
	BIT_VEC cppVar_64712;
	bool cppVar_64713;
	BIT_VEC cppVar_64715;
	BIT_VEC cppVar_64716;
	BIT_VEC cppVar_64717;
	BIT_VEC cppVar_64718;
	bool cppVar_64719;
	BIT_VEC cppVar_64720;
	BIT_VEC cppVar_64714;
	BIT_VEC cppVar_64708;
	BIT_VEC cppVar_64702;
	BIT_VEC cppVar_64696;
	BIT_VEC cppVar_64690;
	BIT_VEC cppVar_64684;
	BIT_VEC cppVar_64678;
	BIT_VEC cppVar_64672;
	BIT_VEC cppVar_64666;
	BIT_VEC cppVar_64660;
	BIT_VEC cppVar_64654;
	BIT_VEC cppVar_64648;
	BIT_VEC cppVar_64642;
	BIT_VEC cppVar_64636;
	BIT_VEC cppVar_64630;
	BIT_VEC cppVar_64624;
	BIT_VEC cppVar_64618;
	BIT_VEC cppVar_64612;
	BIT_VEC cppVar_64606;
	BIT_VEC cppVar_64600;
	BIT_VEC cppVar_64594;
	BIT_VEC cppVar_64581;
	BIT_VEC cppVar_64575;
	BIT_VEC cppVar_64722;
	BIT_VEC cppVar_64723;
	bool cppVar_64724;
	BIT_VEC cppVar_64726;
	BIT_VEC cppVar_64727;
	BIT_VEC cppVar_64728;
	BIT_VEC cppVar_64729;
	bool cppVar_64730;
	BIT_VEC cppVar_64732;
	BIT_VEC cppVar_64733;
	BIT_VEC cppVar_64734;
	BIT_VEC cppVar_64735;
	BIT_VEC cppVar_64736;
	BIT_VEC cppVar_64737;
	BIT_VEC cppVar_64738;
	bool cppVar_64739;
	BIT_VEC cppVar_64740;
	BIT_VEC cppVar_64741;
	BIT_VEC cppVar_64742;
	BIT_VEC cppVar_64743;
	BIT_VEC cppVar_64745;
	BIT_VEC cppVar_64746;
	BIT_VEC cppVar_64747;
	BIT_VEC cppVar_64748;
	bool cppVar_64749;
	BIT_VEC cppVar_64751;
	BIT_VEC cppVar_64752;
	BIT_VEC cppVar_64753;
	BIT_VEC cppVar_64754;
	bool cppVar_64755;
	BIT_VEC cppVar_64757;
	BIT_VEC cppVar_64758;
	BIT_VEC cppVar_64759;
	BIT_VEC cppVar_64760;
	bool cppVar_64761;
	BIT_VEC cppVar_64763;
	BIT_VEC cppVar_64764;
	BIT_VEC cppVar_64765;
	BIT_VEC cppVar_64766;
	bool cppVar_64767;
	BIT_VEC cppVar_64769;
	BIT_VEC cppVar_64770;
	BIT_VEC cppVar_64771;
	BIT_VEC cppVar_64772;
	bool cppVar_64773;
	BIT_VEC cppVar_64775;
	BIT_VEC cppVar_64776;
	BIT_VEC cppVar_64777;
	BIT_VEC cppVar_64778;
	bool cppVar_64779;
	BIT_VEC cppVar_64781;
	BIT_VEC cppVar_64782;
	BIT_VEC cppVar_64783;
	BIT_VEC cppVar_64784;
	bool cppVar_64785;
	BIT_VEC cppVar_64787;
	BIT_VEC cppVar_64788;
	BIT_VEC cppVar_64789;
	BIT_VEC cppVar_64790;
	bool cppVar_64791;
	BIT_VEC cppVar_64793;
	BIT_VEC cppVar_64794;
	BIT_VEC cppVar_64795;
	BIT_VEC cppVar_64796;
	bool cppVar_64797;
	BIT_VEC cppVar_64799;
	BIT_VEC cppVar_64800;
	BIT_VEC cppVar_64801;
	BIT_VEC cppVar_64802;
	bool cppVar_64803;
	BIT_VEC cppVar_64805;
	BIT_VEC cppVar_64806;
	BIT_VEC cppVar_64807;
	BIT_VEC cppVar_64808;
	bool cppVar_64809;
	BIT_VEC cppVar_64811;
	BIT_VEC cppVar_64812;
	BIT_VEC cppVar_64813;
	BIT_VEC cppVar_64814;
	bool cppVar_64815;
	BIT_VEC cppVar_64817;
	BIT_VEC cppVar_64818;
	BIT_VEC cppVar_64819;
	BIT_VEC cppVar_64820;
	bool cppVar_64821;
	BIT_VEC cppVar_64823;
	BIT_VEC cppVar_64824;
	BIT_VEC cppVar_64825;
	BIT_VEC cppVar_64826;
	bool cppVar_64827;
	BIT_VEC cppVar_64829;
	BIT_VEC cppVar_64830;
	BIT_VEC cppVar_64831;
	BIT_VEC cppVar_64832;
	bool cppVar_64833;
	BIT_VEC cppVar_64835;
	BIT_VEC cppVar_64836;
	BIT_VEC cppVar_64837;
	BIT_VEC cppVar_64838;
	bool cppVar_64839;
	BIT_VEC cppVar_64841;
	BIT_VEC cppVar_64842;
	BIT_VEC cppVar_64843;
	BIT_VEC cppVar_64844;
	bool cppVar_64845;
	BIT_VEC cppVar_64847;
	BIT_VEC cppVar_64848;
	BIT_VEC cppVar_64849;
	BIT_VEC cppVar_64850;
	bool cppVar_64851;
	BIT_VEC cppVar_64853;
	BIT_VEC cppVar_64854;
	BIT_VEC cppVar_64855;
	BIT_VEC cppVar_64856;
	bool cppVar_64857;
	BIT_VEC cppVar_64859;
	BIT_VEC cppVar_64860;
	BIT_VEC cppVar_64861;
	BIT_VEC cppVar_64862;
	bool cppVar_64863;
	BIT_VEC cppVar_64865;
	BIT_VEC cppVar_64866;
	BIT_VEC cppVar_64867;
	BIT_VEC cppVar_64868;
	bool cppVar_64869;
	BIT_VEC cppVar_64870;
	BIT_VEC cppVar_64864;
	BIT_VEC cppVar_64858;
	BIT_VEC cppVar_64852;
	BIT_VEC cppVar_64846;
	BIT_VEC cppVar_64840;
	BIT_VEC cppVar_64834;
	BIT_VEC cppVar_64828;
	BIT_VEC cppVar_64822;
	BIT_VEC cppVar_64816;
	BIT_VEC cppVar_64810;
	BIT_VEC cppVar_64804;
	BIT_VEC cppVar_64798;
	BIT_VEC cppVar_64792;
	BIT_VEC cppVar_64786;
	BIT_VEC cppVar_64780;
	BIT_VEC cppVar_64774;
	BIT_VEC cppVar_64768;
	BIT_VEC cppVar_64762;
	BIT_VEC cppVar_64756;
	BIT_VEC cppVar_64750;
	BIT_VEC cppVar_64744;
	BIT_VEC cppVar_64731;
	BIT_VEC cppVar_64725;
	BIT_VEC cppVar_64872;
	BIT_VEC cppVar_64873;
	bool cppVar_64874;
	BIT_VEC cppVar_64876;
	BIT_VEC cppVar_64877;
	BIT_VEC cppVar_64878;
	BIT_VEC cppVar_64879;
	bool cppVar_64880;
	BIT_VEC cppVar_64882;
	BIT_VEC cppVar_64883;
	BIT_VEC cppVar_64884;
	BIT_VEC cppVar_64885;
	BIT_VEC cppVar_64886;
	BIT_VEC cppVar_64887;
	BIT_VEC cppVar_64888;
	bool cppVar_64889;
	BIT_VEC cppVar_64890;
	BIT_VEC cppVar_64891;
	BIT_VEC cppVar_64892;
	BIT_VEC cppVar_64893;
	BIT_VEC cppVar_64895;
	BIT_VEC cppVar_64896;
	BIT_VEC cppVar_64897;
	BIT_VEC cppVar_64898;
	bool cppVar_64899;
	BIT_VEC cppVar_64901;
	BIT_VEC cppVar_64902;
	BIT_VEC cppVar_64903;
	BIT_VEC cppVar_64904;
	bool cppVar_64905;
	BIT_VEC cppVar_64907;
	BIT_VEC cppVar_64908;
	BIT_VEC cppVar_64909;
	BIT_VEC cppVar_64910;
	bool cppVar_64911;
	BIT_VEC cppVar_64913;
	BIT_VEC cppVar_64914;
	BIT_VEC cppVar_64915;
	BIT_VEC cppVar_64916;
	bool cppVar_64917;
	BIT_VEC cppVar_64919;
	BIT_VEC cppVar_64920;
	BIT_VEC cppVar_64921;
	BIT_VEC cppVar_64922;
	bool cppVar_64923;
	BIT_VEC cppVar_64925;
	BIT_VEC cppVar_64926;
	BIT_VEC cppVar_64927;
	BIT_VEC cppVar_64928;
	bool cppVar_64929;
	BIT_VEC cppVar_64931;
	BIT_VEC cppVar_64932;
	BIT_VEC cppVar_64933;
	BIT_VEC cppVar_64934;
	bool cppVar_64935;
	BIT_VEC cppVar_64937;
	BIT_VEC cppVar_64938;
	BIT_VEC cppVar_64939;
	BIT_VEC cppVar_64940;
	bool cppVar_64941;
	BIT_VEC cppVar_64943;
	BIT_VEC cppVar_64944;
	BIT_VEC cppVar_64945;
	BIT_VEC cppVar_64946;
	bool cppVar_64947;
	BIT_VEC cppVar_64949;
	BIT_VEC cppVar_64950;
	BIT_VEC cppVar_64951;
	BIT_VEC cppVar_64952;
	bool cppVar_64953;
	BIT_VEC cppVar_64955;
	BIT_VEC cppVar_64956;
	BIT_VEC cppVar_64957;
	BIT_VEC cppVar_64958;
	bool cppVar_64959;
	BIT_VEC cppVar_64961;
	BIT_VEC cppVar_64962;
	BIT_VEC cppVar_64963;
	BIT_VEC cppVar_64964;
	bool cppVar_64965;
	BIT_VEC cppVar_64967;
	BIT_VEC cppVar_64968;
	BIT_VEC cppVar_64969;
	BIT_VEC cppVar_64970;
	bool cppVar_64971;
	BIT_VEC cppVar_64973;
	BIT_VEC cppVar_64974;
	BIT_VEC cppVar_64975;
	BIT_VEC cppVar_64976;
	bool cppVar_64977;
	BIT_VEC cppVar_64979;
	BIT_VEC cppVar_64980;
	BIT_VEC cppVar_64981;
	BIT_VEC cppVar_64982;
	bool cppVar_64983;
	BIT_VEC cppVar_64985;
	BIT_VEC cppVar_64986;
	BIT_VEC cppVar_64987;
	BIT_VEC cppVar_64988;
	bool cppVar_64989;
	BIT_VEC cppVar_64991;
	BIT_VEC cppVar_64992;
	BIT_VEC cppVar_64993;
	BIT_VEC cppVar_64994;
	bool cppVar_64995;
	BIT_VEC cppVar_64997;
	BIT_VEC cppVar_64998;
	BIT_VEC cppVar_64999;
	BIT_VEC cppVar_65000;
	bool cppVar_65001;
	BIT_VEC cppVar_65003;
	BIT_VEC cppVar_65004;
	BIT_VEC cppVar_65005;
	BIT_VEC cppVar_65006;
	bool cppVar_65007;
	BIT_VEC cppVar_65009;
	BIT_VEC cppVar_65010;
	BIT_VEC cppVar_65011;
	BIT_VEC cppVar_65012;
	bool cppVar_65013;
	BIT_VEC cppVar_65015;
	BIT_VEC cppVar_65016;
	BIT_VEC cppVar_65017;
	BIT_VEC cppVar_65018;
	bool cppVar_65019;
	BIT_VEC cppVar_65020;
	BIT_VEC cppVar_65014;
	BIT_VEC cppVar_65008;
	BIT_VEC cppVar_65002;
	BIT_VEC cppVar_64996;
	BIT_VEC cppVar_64990;
	BIT_VEC cppVar_64984;
	BIT_VEC cppVar_64978;
	BIT_VEC cppVar_64972;
	BIT_VEC cppVar_64966;
	BIT_VEC cppVar_64960;
	BIT_VEC cppVar_64954;
	BIT_VEC cppVar_64948;
	BIT_VEC cppVar_64942;
	BIT_VEC cppVar_64936;
	BIT_VEC cppVar_64930;
	BIT_VEC cppVar_64924;
	BIT_VEC cppVar_64918;
	BIT_VEC cppVar_64912;
	BIT_VEC cppVar_64906;
	BIT_VEC cppVar_64900;
	BIT_VEC cppVar_64894;
	BIT_VEC cppVar_64881;
	BIT_VEC cppVar_64875;
	BIT_VEC cppVar_65022;
	BIT_VEC cppVar_65023;
	bool cppVar_65024;
	BIT_VEC cppVar_65026;
	BIT_VEC cppVar_65027;
	BIT_VEC cppVar_65028;
	BIT_VEC cppVar_65029;
	bool cppVar_65030;
	BIT_VEC cppVar_65032;
	BIT_VEC cppVar_65033;
	BIT_VEC cppVar_65034;
	BIT_VEC cppVar_65035;
	BIT_VEC cppVar_65036;
	BIT_VEC cppVar_65037;
	BIT_VEC cppVar_65038;
	bool cppVar_65039;
	BIT_VEC cppVar_65040;
	BIT_VEC cppVar_65041;
	BIT_VEC cppVar_65042;
	BIT_VEC cppVar_65043;
	BIT_VEC cppVar_65045;
	BIT_VEC cppVar_65046;
	BIT_VEC cppVar_65047;
	BIT_VEC cppVar_65048;
	bool cppVar_65049;
	BIT_VEC cppVar_65051;
	BIT_VEC cppVar_65052;
	BIT_VEC cppVar_65053;
	BIT_VEC cppVar_65054;
	bool cppVar_65055;
	BIT_VEC cppVar_65057;
	BIT_VEC cppVar_65058;
	BIT_VEC cppVar_65059;
	BIT_VEC cppVar_65060;
	bool cppVar_65061;
	BIT_VEC cppVar_65063;
	BIT_VEC cppVar_65064;
	BIT_VEC cppVar_65065;
	BIT_VEC cppVar_65066;
	bool cppVar_65067;
	BIT_VEC cppVar_65069;
	BIT_VEC cppVar_65070;
	BIT_VEC cppVar_65071;
	BIT_VEC cppVar_65072;
	bool cppVar_65073;
	BIT_VEC cppVar_65075;
	BIT_VEC cppVar_65076;
	BIT_VEC cppVar_65077;
	BIT_VEC cppVar_65078;
	bool cppVar_65079;
	BIT_VEC cppVar_65081;
	BIT_VEC cppVar_65082;
	BIT_VEC cppVar_65083;
	BIT_VEC cppVar_65084;
	bool cppVar_65085;
	BIT_VEC cppVar_65087;
	BIT_VEC cppVar_65088;
	BIT_VEC cppVar_65089;
	BIT_VEC cppVar_65090;
	bool cppVar_65091;
	BIT_VEC cppVar_65093;
	BIT_VEC cppVar_65094;
	BIT_VEC cppVar_65095;
	BIT_VEC cppVar_65096;
	bool cppVar_65097;
	BIT_VEC cppVar_65099;
	BIT_VEC cppVar_65100;
	BIT_VEC cppVar_65101;
	BIT_VEC cppVar_65102;
	bool cppVar_65103;
	BIT_VEC cppVar_65105;
	BIT_VEC cppVar_65106;
	BIT_VEC cppVar_65107;
	BIT_VEC cppVar_65108;
	bool cppVar_65109;
	BIT_VEC cppVar_65111;
	BIT_VEC cppVar_65112;
	BIT_VEC cppVar_65113;
	BIT_VEC cppVar_65114;
	bool cppVar_65115;
	BIT_VEC cppVar_65117;
	BIT_VEC cppVar_65118;
	BIT_VEC cppVar_65119;
	BIT_VEC cppVar_65120;
	bool cppVar_65121;
	BIT_VEC cppVar_65123;
	BIT_VEC cppVar_65124;
	BIT_VEC cppVar_65125;
	BIT_VEC cppVar_65126;
	bool cppVar_65127;
	BIT_VEC cppVar_65129;
	BIT_VEC cppVar_65130;
	BIT_VEC cppVar_65131;
	BIT_VEC cppVar_65132;
	bool cppVar_65133;
	BIT_VEC cppVar_65135;
	BIT_VEC cppVar_65136;
	BIT_VEC cppVar_65137;
	BIT_VEC cppVar_65138;
	bool cppVar_65139;
	BIT_VEC cppVar_65141;
	BIT_VEC cppVar_65142;
	BIT_VEC cppVar_65143;
	BIT_VEC cppVar_65144;
	bool cppVar_65145;
	BIT_VEC cppVar_65147;
	BIT_VEC cppVar_65148;
	BIT_VEC cppVar_65149;
	BIT_VEC cppVar_65150;
	bool cppVar_65151;
	BIT_VEC cppVar_65153;
	BIT_VEC cppVar_65154;
	BIT_VEC cppVar_65155;
	BIT_VEC cppVar_65156;
	bool cppVar_65157;
	BIT_VEC cppVar_65159;
	BIT_VEC cppVar_65160;
	BIT_VEC cppVar_65161;
	BIT_VEC cppVar_65162;
	bool cppVar_65163;
	BIT_VEC cppVar_65165;
	BIT_VEC cppVar_65166;
	BIT_VEC cppVar_65167;
	BIT_VEC cppVar_65168;
	bool cppVar_65169;
	BIT_VEC cppVar_65170;
	BIT_VEC cppVar_65164;
	BIT_VEC cppVar_65158;
	BIT_VEC cppVar_65152;
	BIT_VEC cppVar_65146;
	BIT_VEC cppVar_65140;
	BIT_VEC cppVar_65134;
	BIT_VEC cppVar_65128;
	BIT_VEC cppVar_65122;
	BIT_VEC cppVar_65116;
	BIT_VEC cppVar_65110;
	BIT_VEC cppVar_65104;
	BIT_VEC cppVar_65098;
	BIT_VEC cppVar_65092;
	BIT_VEC cppVar_65086;
	BIT_VEC cppVar_65080;
	BIT_VEC cppVar_65074;
	BIT_VEC cppVar_65068;
	BIT_VEC cppVar_65062;
	BIT_VEC cppVar_65056;
	BIT_VEC cppVar_65050;
	BIT_VEC cppVar_65044;
	BIT_VEC cppVar_65031;
	BIT_VEC cppVar_65025;
	BIT_VEC cppVar_65172;
	BIT_VEC cppVar_65173;
	bool cppVar_65174;
	BIT_VEC cppVar_65176;
	BIT_VEC cppVar_65177;
	BIT_VEC cppVar_65178;
	BIT_VEC cppVar_65179;
	bool cppVar_65180;
	BIT_VEC cppVar_65182;
	BIT_VEC cppVar_65183;
	BIT_VEC cppVar_65184;
	BIT_VEC cppVar_65185;
	BIT_VEC cppVar_65186;
	BIT_VEC cppVar_65187;
	BIT_VEC cppVar_65188;
	bool cppVar_65189;
	BIT_VEC cppVar_65190;
	BIT_VEC cppVar_65191;
	BIT_VEC cppVar_65192;
	BIT_VEC cppVar_65193;
	BIT_VEC cppVar_65195;
	BIT_VEC cppVar_65196;
	BIT_VEC cppVar_65197;
	BIT_VEC cppVar_65198;
	bool cppVar_65199;
	BIT_VEC cppVar_65201;
	BIT_VEC cppVar_65202;
	BIT_VEC cppVar_65203;
	BIT_VEC cppVar_65204;
	bool cppVar_65205;
	BIT_VEC cppVar_65207;
	BIT_VEC cppVar_65208;
	BIT_VEC cppVar_65209;
	BIT_VEC cppVar_65210;
	bool cppVar_65211;
	BIT_VEC cppVar_65213;
	BIT_VEC cppVar_65214;
	BIT_VEC cppVar_65215;
	BIT_VEC cppVar_65216;
	bool cppVar_65217;
	BIT_VEC cppVar_65219;
	BIT_VEC cppVar_65220;
	BIT_VEC cppVar_65221;
	BIT_VEC cppVar_65222;
	bool cppVar_65223;
	BIT_VEC cppVar_65225;
	BIT_VEC cppVar_65226;
	BIT_VEC cppVar_65227;
	BIT_VEC cppVar_65228;
	bool cppVar_65229;
	BIT_VEC cppVar_65231;
	BIT_VEC cppVar_65232;
	BIT_VEC cppVar_65233;
	BIT_VEC cppVar_65234;
	bool cppVar_65235;
	BIT_VEC cppVar_65237;
	BIT_VEC cppVar_65238;
	BIT_VEC cppVar_65239;
	BIT_VEC cppVar_65240;
	bool cppVar_65241;
	BIT_VEC cppVar_65243;
	BIT_VEC cppVar_65244;
	BIT_VEC cppVar_65245;
	BIT_VEC cppVar_65246;
	bool cppVar_65247;
	BIT_VEC cppVar_65249;
	BIT_VEC cppVar_65250;
	BIT_VEC cppVar_65251;
	BIT_VEC cppVar_65252;
	bool cppVar_65253;
	BIT_VEC cppVar_65255;
	BIT_VEC cppVar_65256;
	BIT_VEC cppVar_65257;
	BIT_VEC cppVar_65258;
	bool cppVar_65259;
	BIT_VEC cppVar_65261;
	BIT_VEC cppVar_65262;
	BIT_VEC cppVar_65263;
	BIT_VEC cppVar_65264;
	bool cppVar_65265;
	BIT_VEC cppVar_65267;
	BIT_VEC cppVar_65268;
	BIT_VEC cppVar_65269;
	BIT_VEC cppVar_65270;
	bool cppVar_65271;
	BIT_VEC cppVar_65273;
	BIT_VEC cppVar_65274;
	BIT_VEC cppVar_65275;
	BIT_VEC cppVar_65276;
	bool cppVar_65277;
	BIT_VEC cppVar_65279;
	BIT_VEC cppVar_65280;
	BIT_VEC cppVar_65281;
	BIT_VEC cppVar_65282;
	bool cppVar_65283;
	BIT_VEC cppVar_65285;
	BIT_VEC cppVar_65286;
	BIT_VEC cppVar_65287;
	BIT_VEC cppVar_65288;
	bool cppVar_65289;
	BIT_VEC cppVar_65291;
	BIT_VEC cppVar_65292;
	BIT_VEC cppVar_65293;
	BIT_VEC cppVar_65294;
	bool cppVar_65295;
	BIT_VEC cppVar_65297;
	BIT_VEC cppVar_65298;
	BIT_VEC cppVar_65299;
	BIT_VEC cppVar_65300;
	bool cppVar_65301;
	BIT_VEC cppVar_65303;
	BIT_VEC cppVar_65304;
	BIT_VEC cppVar_65305;
	BIT_VEC cppVar_65306;
	bool cppVar_65307;
	BIT_VEC cppVar_65309;
	BIT_VEC cppVar_65310;
	BIT_VEC cppVar_65311;
	BIT_VEC cppVar_65312;
	bool cppVar_65313;
	BIT_VEC cppVar_65315;
	BIT_VEC cppVar_65316;
	BIT_VEC cppVar_65317;
	BIT_VEC cppVar_65318;
	bool cppVar_65319;
	BIT_VEC cppVar_65320;
	BIT_VEC cppVar_65314;
	BIT_VEC cppVar_65308;
	BIT_VEC cppVar_65302;
	BIT_VEC cppVar_65296;
	BIT_VEC cppVar_65290;
	BIT_VEC cppVar_65284;
	BIT_VEC cppVar_65278;
	BIT_VEC cppVar_65272;
	BIT_VEC cppVar_65266;
	BIT_VEC cppVar_65260;
	BIT_VEC cppVar_65254;
	BIT_VEC cppVar_65248;
	BIT_VEC cppVar_65242;
	BIT_VEC cppVar_65236;
	BIT_VEC cppVar_65230;
	BIT_VEC cppVar_65224;
	BIT_VEC cppVar_65218;
	BIT_VEC cppVar_65212;
	BIT_VEC cppVar_65206;
	BIT_VEC cppVar_65200;
	BIT_VEC cppVar_65194;
	BIT_VEC cppVar_65181;
	BIT_VEC cppVar_65175;
	BIT_VEC cppVar_65322;
	BIT_VEC cppVar_65323;
	bool cppVar_65324;
	BIT_VEC cppVar_65326;
	BIT_VEC cppVar_65327;
	BIT_VEC cppVar_65328;
	BIT_VEC cppVar_65329;
	bool cppVar_65330;
	BIT_VEC cppVar_65331;
	BIT_VEC cppVar_65332;
	BIT_VEC cppVar_65333;
	BIT_VEC cppVar_65334;
	BIT_VEC cppVar_65335;
	BIT_VEC cppVar_65336;
	BIT_VEC cppVar_65337;
	BIT_VEC cppVar_65325;
	BIT_VEC cppVar_65339;
	BIT_VEC cppVar_65340;
	bool cppVar_65341;
	BIT_VEC cppVar_65343;
	BIT_VEC cppVar_65344;
	BIT_VEC cppVar_65345;
	BIT_VEC cppVar_65346;
	bool cppVar_65347;
	BIT_VEC cppVar_65348;
	BIT_VEC cppVar_65349;
	BIT_VEC cppVar_65350;
	BIT_VEC cppVar_65351;
	BIT_VEC cppVar_65352;
	BIT_VEC cppVar_65353;
	BIT_VEC cppVar_65354;
	BIT_VEC cppVar_65342;
	BIT_VEC cppVar_65356;
	BIT_VEC cppVar_65357;
	bool cppVar_65358;
	BIT_VEC cppVar_65360;
	BIT_VEC cppVar_65361;
	BIT_VEC cppVar_65362;
	BIT_VEC cppVar_65363;
	bool cppVar_65364;
	BIT_VEC cppVar_65366;
	BIT_VEC cppVar_65367;
	BIT_VEC cppVar_65368;
	BIT_VEC cppVar_65369;
	BIT_VEC cppVar_65370;
	bool cppVar_65371;
	BIT_VEC cppVar_65372;
	BIT_VEC cppVar_65373;
	BIT_VEC cppVar_65374;
	BIT_VEC cppVar_65376;
	BIT_VEC cppVar_65377;
	BIT_VEC cppVar_65378;
	bool cppVar_65379;
	BIT_VEC cppVar_65381;
	BIT_VEC cppVar_65382;
	BIT_VEC cppVar_65383;
	bool cppVar_65384;
	BIT_VEC cppVar_65386;
	BIT_VEC cppVar_65387;
	BIT_VEC cppVar_65388;
	bool cppVar_65389;
	BIT_VEC cppVar_65391;
	BIT_VEC cppVar_65392;
	BIT_VEC cppVar_65393;
	bool cppVar_65394;
	BIT_VEC cppVar_65396;
	BIT_VEC cppVar_65397;
	BIT_VEC cppVar_65398;
	bool cppVar_65399;
	BIT_VEC cppVar_65401;
	BIT_VEC cppVar_65402;
	BIT_VEC cppVar_65403;
	bool cppVar_65404;
	BIT_VEC cppVar_65406;
	BIT_VEC cppVar_65407;
	BIT_VEC cppVar_65408;
	bool cppVar_65409;
	BIT_VEC cppVar_65411;
	BIT_VEC cppVar_65412;
	BIT_VEC cppVar_65413;
	bool cppVar_65414;
	BIT_VEC cppVar_65416;
	BIT_VEC cppVar_65417;
	BIT_VEC cppVar_65418;
	bool cppVar_65419;
	BIT_VEC cppVar_65421;
	BIT_VEC cppVar_65422;
	BIT_VEC cppVar_65423;
	bool cppVar_65424;
	BIT_VEC cppVar_65426;
	BIT_VEC cppVar_65427;
	BIT_VEC cppVar_65428;
	bool cppVar_65429;
	BIT_VEC cppVar_65431;
	BIT_VEC cppVar_65432;
	BIT_VEC cppVar_65433;
	bool cppVar_65434;
	BIT_VEC cppVar_65436;
	BIT_VEC cppVar_65437;
	BIT_VEC cppVar_65438;
	bool cppVar_65439;
	BIT_VEC cppVar_65441;
	BIT_VEC cppVar_65442;
	BIT_VEC cppVar_65443;
	bool cppVar_65444;
	BIT_VEC cppVar_65446;
	BIT_VEC cppVar_65447;
	BIT_VEC cppVar_65448;
	bool cppVar_65449;
	BIT_VEC cppVar_65451;
	BIT_VEC cppVar_65452;
	BIT_VEC cppVar_65453;
	bool cppVar_65454;
	BIT_VEC cppVar_65456;
	BIT_VEC cppVar_65457;
	BIT_VEC cppVar_65458;
	bool cppVar_65459;
	BIT_VEC cppVar_65461;
	BIT_VEC cppVar_65462;
	BIT_VEC cppVar_65463;
	bool cppVar_65464;
	BIT_VEC cppVar_65466;
	BIT_VEC cppVar_65467;
	BIT_VEC cppVar_65468;
	bool cppVar_65469;
	BIT_VEC cppVar_65471;
	BIT_VEC cppVar_65472;
	BIT_VEC cppVar_65473;
	bool cppVar_65474;
	BIT_VEC cppVar_65476;
	BIT_VEC cppVar_65477;
	BIT_VEC cppVar_65478;
	bool cppVar_65479;
	BIT_VEC cppVar_65480;
	BIT_VEC cppVar_65475;
	BIT_VEC cppVar_65470;
	BIT_VEC cppVar_65465;
	BIT_VEC cppVar_65460;
	BIT_VEC cppVar_65455;
	BIT_VEC cppVar_65450;
	BIT_VEC cppVar_65445;
	BIT_VEC cppVar_65440;
	BIT_VEC cppVar_65435;
	BIT_VEC cppVar_65430;
	BIT_VEC cppVar_65425;
	BIT_VEC cppVar_65420;
	BIT_VEC cppVar_65415;
	BIT_VEC cppVar_65410;
	BIT_VEC cppVar_65405;
	BIT_VEC cppVar_65400;
	BIT_VEC cppVar_65395;
	BIT_VEC cppVar_65390;
	BIT_VEC cppVar_65385;
	BIT_VEC cppVar_65380;
	BIT_VEC cppVar_65375;
	BIT_VEC cppVar_65365;
	BIT_VEC cppVar_65359;
	BIT_VEC cppVar_65482;
	BIT_VEC cppVar_65483;
	bool cppVar_65484;
	BIT_VEC cppVar_65486;
	BIT_VEC cppVar_65487;
	BIT_VEC cppVar_65488;
	BIT_VEC cppVar_65489;
	bool cppVar_65490;
	BIT_VEC cppVar_65491;
	BIT_VEC cppVar_65492;
	BIT_VEC cppVar_65493;
	BIT_VEC cppVar_65485;
	BIT_VEC cppVar_65495;
	BIT_VEC cppVar_65496;
	bool cppVar_65497;
	BIT_VEC cppVar_65499;
	BIT_VEC cppVar_65500;
	BIT_VEC cppVar_65501;
	BIT_VEC cppVar_65502;
	bool cppVar_65503;
	BIT_VEC cppVar_65505;
	BIT_VEC cppVar_65506;
	BIT_VEC cppVar_65507;
	BIT_VEC cppVar_65508;
	bool cppVar_65509;
	BIT_VEC cppVar_65510;
	BIT_VEC cppVar_65511;
	BIT_VEC cppVar_65512;
	BIT_VEC cppVar_65514;
	BIT_VEC cppVar_65515;
	BIT_VEC cppVar_65516;
	bool cppVar_65517;
	BIT_VEC cppVar_65519;
	BIT_VEC cppVar_65520;
	BIT_VEC cppVar_65521;
	bool cppVar_65522;
	BIT_VEC cppVar_65524;
	BIT_VEC cppVar_65525;
	BIT_VEC cppVar_65526;
	bool cppVar_65527;
	BIT_VEC cppVar_65529;
	BIT_VEC cppVar_65530;
	BIT_VEC cppVar_65531;
	bool cppVar_65532;
	BIT_VEC cppVar_65534;
	BIT_VEC cppVar_65535;
	BIT_VEC cppVar_65536;
	bool cppVar_65537;
	BIT_VEC cppVar_65539;
	BIT_VEC cppVar_65540;
	BIT_VEC cppVar_65541;
	bool cppVar_65542;
	BIT_VEC cppVar_65544;
	BIT_VEC cppVar_65545;
	BIT_VEC cppVar_65546;
	bool cppVar_65547;
	BIT_VEC cppVar_65549;
	BIT_VEC cppVar_65550;
	BIT_VEC cppVar_65551;
	bool cppVar_65552;
	BIT_VEC cppVar_65554;
	BIT_VEC cppVar_65555;
	BIT_VEC cppVar_65556;
	bool cppVar_65557;
	BIT_VEC cppVar_65559;
	BIT_VEC cppVar_65560;
	BIT_VEC cppVar_65561;
	bool cppVar_65562;
	BIT_VEC cppVar_65564;
	BIT_VEC cppVar_65565;
	BIT_VEC cppVar_65566;
	bool cppVar_65567;
	BIT_VEC cppVar_65569;
	BIT_VEC cppVar_65570;
	BIT_VEC cppVar_65571;
	bool cppVar_65572;
	BIT_VEC cppVar_65574;
	BIT_VEC cppVar_65575;
	BIT_VEC cppVar_65576;
	bool cppVar_65577;
	BIT_VEC cppVar_65579;
	BIT_VEC cppVar_65580;
	BIT_VEC cppVar_65581;
	bool cppVar_65582;
	BIT_VEC cppVar_65584;
	BIT_VEC cppVar_65585;
	BIT_VEC cppVar_65586;
	bool cppVar_65587;
	BIT_VEC cppVar_65589;
	BIT_VEC cppVar_65590;
	BIT_VEC cppVar_65591;
	bool cppVar_65592;
	BIT_VEC cppVar_65594;
	BIT_VEC cppVar_65595;
	BIT_VEC cppVar_65596;
	bool cppVar_65597;
	BIT_VEC cppVar_65599;
	BIT_VEC cppVar_65600;
	BIT_VEC cppVar_65601;
	bool cppVar_65602;
	BIT_VEC cppVar_65604;
	BIT_VEC cppVar_65605;
	BIT_VEC cppVar_65606;
	bool cppVar_65607;
	BIT_VEC cppVar_65609;
	BIT_VEC cppVar_65610;
	BIT_VEC cppVar_65611;
	bool cppVar_65612;
	BIT_VEC cppVar_65614;
	BIT_VEC cppVar_65615;
	BIT_VEC cppVar_65616;
	bool cppVar_65617;
	BIT_VEC cppVar_65618;
	BIT_VEC cppVar_65613;
	BIT_VEC cppVar_65608;
	BIT_VEC cppVar_65603;
	BIT_VEC cppVar_65598;
	BIT_VEC cppVar_65593;
	BIT_VEC cppVar_65588;
	BIT_VEC cppVar_65583;
	BIT_VEC cppVar_65578;
	BIT_VEC cppVar_65573;
	BIT_VEC cppVar_65568;
	BIT_VEC cppVar_65563;
	BIT_VEC cppVar_65558;
	BIT_VEC cppVar_65553;
	BIT_VEC cppVar_65548;
	BIT_VEC cppVar_65543;
	BIT_VEC cppVar_65538;
	BIT_VEC cppVar_65533;
	BIT_VEC cppVar_65528;
	BIT_VEC cppVar_65523;
	BIT_VEC cppVar_65518;
	BIT_VEC cppVar_65513;
	BIT_VEC cppVar_65504;
	BIT_VEC cppVar_65619;
	BIT_VEC cppVar_65620;
	BIT_VEC cppVar_65621;
	BIT_VEC cppVar_65622;
	BIT_VEC cppVar_65498;
	BIT_VEC cppVar_65624;
	BIT_VEC cppVar_65625;
	bool cppVar_65626;
	BIT_VEC cppVar_65628;
	BIT_VEC cppVar_65629;
	BIT_VEC cppVar_65630;
	BIT_VEC cppVar_65631;
	bool cppVar_65632;
	BIT_VEC cppVar_65634;
	BIT_VEC cppVar_65635;
	BIT_VEC cppVar_65636;
	BIT_VEC cppVar_65637;
	bool cppVar_65638;
	BIT_VEC cppVar_65639;
	BIT_VEC cppVar_65640;
	BIT_VEC cppVar_65641;
	BIT_VEC cppVar_65643;
	BIT_VEC cppVar_65644;
	BIT_VEC cppVar_65645;
	bool cppVar_65646;
	BIT_VEC cppVar_65648;
	BIT_VEC cppVar_65649;
	BIT_VEC cppVar_65650;
	bool cppVar_65651;
	BIT_VEC cppVar_65653;
	BIT_VEC cppVar_65654;
	BIT_VEC cppVar_65655;
	bool cppVar_65656;
	BIT_VEC cppVar_65658;
	BIT_VEC cppVar_65659;
	BIT_VEC cppVar_65660;
	bool cppVar_65661;
	BIT_VEC cppVar_65663;
	BIT_VEC cppVar_65664;
	BIT_VEC cppVar_65665;
	bool cppVar_65666;
	BIT_VEC cppVar_65668;
	BIT_VEC cppVar_65669;
	BIT_VEC cppVar_65670;
	bool cppVar_65671;
	BIT_VEC cppVar_65673;
	BIT_VEC cppVar_65674;
	BIT_VEC cppVar_65675;
	bool cppVar_65676;
	BIT_VEC cppVar_65678;
	BIT_VEC cppVar_65679;
	BIT_VEC cppVar_65680;
	bool cppVar_65681;
	BIT_VEC cppVar_65683;
	BIT_VEC cppVar_65684;
	BIT_VEC cppVar_65685;
	bool cppVar_65686;
	BIT_VEC cppVar_65688;
	BIT_VEC cppVar_65689;
	BIT_VEC cppVar_65690;
	bool cppVar_65691;
	BIT_VEC cppVar_65693;
	BIT_VEC cppVar_65694;
	BIT_VEC cppVar_65695;
	bool cppVar_65696;
	BIT_VEC cppVar_65698;
	BIT_VEC cppVar_65699;
	BIT_VEC cppVar_65700;
	bool cppVar_65701;
	BIT_VEC cppVar_65703;
	BIT_VEC cppVar_65704;
	BIT_VEC cppVar_65705;
	bool cppVar_65706;
	BIT_VEC cppVar_65708;
	BIT_VEC cppVar_65709;
	BIT_VEC cppVar_65710;
	bool cppVar_65711;
	BIT_VEC cppVar_65713;
	BIT_VEC cppVar_65714;
	BIT_VEC cppVar_65715;
	bool cppVar_65716;
	BIT_VEC cppVar_65718;
	BIT_VEC cppVar_65719;
	BIT_VEC cppVar_65720;
	bool cppVar_65721;
	BIT_VEC cppVar_65723;
	BIT_VEC cppVar_65724;
	BIT_VEC cppVar_65725;
	bool cppVar_65726;
	BIT_VEC cppVar_65728;
	BIT_VEC cppVar_65729;
	BIT_VEC cppVar_65730;
	bool cppVar_65731;
	BIT_VEC cppVar_65733;
	BIT_VEC cppVar_65734;
	BIT_VEC cppVar_65735;
	bool cppVar_65736;
	BIT_VEC cppVar_65738;
	BIT_VEC cppVar_65739;
	BIT_VEC cppVar_65740;
	bool cppVar_65741;
	BIT_VEC cppVar_65743;
	BIT_VEC cppVar_65744;
	BIT_VEC cppVar_65745;
	bool cppVar_65746;
	BIT_VEC cppVar_65747;
	BIT_VEC cppVar_65742;
	BIT_VEC cppVar_65737;
	BIT_VEC cppVar_65732;
	BIT_VEC cppVar_65727;
	BIT_VEC cppVar_65722;
	BIT_VEC cppVar_65717;
	BIT_VEC cppVar_65712;
	BIT_VEC cppVar_65707;
	BIT_VEC cppVar_65702;
	BIT_VEC cppVar_65697;
	BIT_VEC cppVar_65692;
	BIT_VEC cppVar_65687;
	BIT_VEC cppVar_65682;
	BIT_VEC cppVar_65677;
	BIT_VEC cppVar_65672;
	BIT_VEC cppVar_65667;
	BIT_VEC cppVar_65662;
	BIT_VEC cppVar_65657;
	BIT_VEC cppVar_65652;
	BIT_VEC cppVar_65647;
	BIT_VEC cppVar_65642;
	BIT_VEC cppVar_65633;
	BIT_VEC cppVar_65748;
	BIT_VEC cppVar_65627;
	BIT_VEC cppVar_65750;
	BIT_VEC cppVar_65751;
	bool cppVar_65752;
	BIT_VEC cppVar_65754;
	BIT_VEC cppVar_65755;
	BIT_VEC cppVar_65756;
	BIT_VEC cppVar_65757;
	bool cppVar_65758;
	BIT_VEC cppVar_65760;
	BIT_VEC cppVar_65761;
	BIT_VEC cppVar_65762;
	BIT_VEC cppVar_65763;
	bool cppVar_65764;
	BIT_VEC cppVar_65765;
	BIT_VEC cppVar_65766;
	BIT_VEC cppVar_65767;
	BIT_VEC cppVar_65769;
	BIT_VEC cppVar_65770;
	BIT_VEC cppVar_65771;
	bool cppVar_65772;
	BIT_VEC cppVar_65774;
	BIT_VEC cppVar_65775;
	BIT_VEC cppVar_65776;
	bool cppVar_65777;
	BIT_VEC cppVar_65779;
	BIT_VEC cppVar_65780;
	BIT_VEC cppVar_65781;
	bool cppVar_65782;
	BIT_VEC cppVar_65784;
	BIT_VEC cppVar_65785;
	BIT_VEC cppVar_65786;
	bool cppVar_65787;
	BIT_VEC cppVar_65789;
	BIT_VEC cppVar_65790;
	BIT_VEC cppVar_65791;
	bool cppVar_65792;
	BIT_VEC cppVar_65794;
	BIT_VEC cppVar_65795;
	BIT_VEC cppVar_65796;
	bool cppVar_65797;
	BIT_VEC cppVar_65799;
	BIT_VEC cppVar_65800;
	BIT_VEC cppVar_65801;
	bool cppVar_65802;
	BIT_VEC cppVar_65804;
	BIT_VEC cppVar_65805;
	BIT_VEC cppVar_65806;
	bool cppVar_65807;
	BIT_VEC cppVar_65809;
	BIT_VEC cppVar_65810;
	BIT_VEC cppVar_65811;
	bool cppVar_65812;
	BIT_VEC cppVar_65814;
	BIT_VEC cppVar_65815;
	BIT_VEC cppVar_65816;
	bool cppVar_65817;
	BIT_VEC cppVar_65819;
	BIT_VEC cppVar_65820;
	BIT_VEC cppVar_65821;
	bool cppVar_65822;
	BIT_VEC cppVar_65824;
	BIT_VEC cppVar_65825;
	BIT_VEC cppVar_65826;
	bool cppVar_65827;
	BIT_VEC cppVar_65829;
	BIT_VEC cppVar_65830;
	BIT_VEC cppVar_65831;
	bool cppVar_65832;
	BIT_VEC cppVar_65834;
	BIT_VEC cppVar_65835;
	BIT_VEC cppVar_65836;
	bool cppVar_65837;
	BIT_VEC cppVar_65839;
	BIT_VEC cppVar_65840;
	BIT_VEC cppVar_65841;
	bool cppVar_65842;
	BIT_VEC cppVar_65844;
	BIT_VEC cppVar_65845;
	BIT_VEC cppVar_65846;
	bool cppVar_65847;
	BIT_VEC cppVar_65849;
	BIT_VEC cppVar_65850;
	BIT_VEC cppVar_65851;
	bool cppVar_65852;
	BIT_VEC cppVar_65854;
	BIT_VEC cppVar_65855;
	BIT_VEC cppVar_65856;
	bool cppVar_65857;
	BIT_VEC cppVar_65859;
	BIT_VEC cppVar_65860;
	BIT_VEC cppVar_65861;
	bool cppVar_65862;
	BIT_VEC cppVar_65864;
	BIT_VEC cppVar_65865;
	BIT_VEC cppVar_65866;
	bool cppVar_65867;
	BIT_VEC cppVar_65869;
	BIT_VEC cppVar_65870;
	BIT_VEC cppVar_65871;
	bool cppVar_65872;
	BIT_VEC cppVar_65873;
	BIT_VEC cppVar_65868;
	BIT_VEC cppVar_65863;
	BIT_VEC cppVar_65858;
	BIT_VEC cppVar_65853;
	BIT_VEC cppVar_65848;
	BIT_VEC cppVar_65843;
	BIT_VEC cppVar_65838;
	BIT_VEC cppVar_65833;
	BIT_VEC cppVar_65828;
	BIT_VEC cppVar_65823;
	BIT_VEC cppVar_65818;
	BIT_VEC cppVar_65813;
	BIT_VEC cppVar_65808;
	BIT_VEC cppVar_65803;
	BIT_VEC cppVar_65798;
	BIT_VEC cppVar_65793;
	BIT_VEC cppVar_65788;
	BIT_VEC cppVar_65783;
	BIT_VEC cppVar_65778;
	BIT_VEC cppVar_65773;
	BIT_VEC cppVar_65768;
	BIT_VEC cppVar_65759;
	BIT_VEC cppVar_65874;
	BIT_VEC cppVar_65875;
	BIT_VEC cppVar_65876;
	BIT_VEC cppVar_65877;
	BIT_VEC cppVar_65753;
	BIT_VEC cppVar_65879;
	BIT_VEC cppVar_65880;
	bool cppVar_65881;
	BIT_VEC cppVar_65883;
	BIT_VEC cppVar_65884;
	BIT_VEC cppVar_65885;
	BIT_VEC cppVar_65886;
	bool cppVar_65887;
	BIT_VEC cppVar_65889;
	BIT_VEC cppVar_65890;
	BIT_VEC cppVar_65891;
	BIT_VEC cppVar_65892;
	bool cppVar_65893;
	BIT_VEC cppVar_65894;
	BIT_VEC cppVar_65895;
	BIT_VEC cppVar_65896;
	BIT_VEC cppVar_65898;
	BIT_VEC cppVar_65899;
	BIT_VEC cppVar_65900;
	bool cppVar_65901;
	BIT_VEC cppVar_65903;
	BIT_VEC cppVar_65904;
	BIT_VEC cppVar_65905;
	bool cppVar_65906;
	BIT_VEC cppVar_65908;
	BIT_VEC cppVar_65909;
	BIT_VEC cppVar_65910;
	bool cppVar_65911;
	BIT_VEC cppVar_65913;
	BIT_VEC cppVar_65914;
	BIT_VEC cppVar_65915;
	bool cppVar_65916;
	BIT_VEC cppVar_65918;
	BIT_VEC cppVar_65919;
	BIT_VEC cppVar_65920;
	bool cppVar_65921;
	BIT_VEC cppVar_65923;
	BIT_VEC cppVar_65924;
	BIT_VEC cppVar_65925;
	bool cppVar_65926;
	BIT_VEC cppVar_65928;
	BIT_VEC cppVar_65929;
	BIT_VEC cppVar_65930;
	bool cppVar_65931;
	BIT_VEC cppVar_65933;
	BIT_VEC cppVar_65934;
	BIT_VEC cppVar_65935;
	bool cppVar_65936;
	BIT_VEC cppVar_65938;
	BIT_VEC cppVar_65939;
	BIT_VEC cppVar_65940;
	bool cppVar_65941;
	BIT_VEC cppVar_65943;
	BIT_VEC cppVar_65944;
	BIT_VEC cppVar_65945;
	bool cppVar_65946;
	BIT_VEC cppVar_65948;
	BIT_VEC cppVar_65949;
	BIT_VEC cppVar_65950;
	bool cppVar_65951;
	BIT_VEC cppVar_65953;
	BIT_VEC cppVar_65954;
	BIT_VEC cppVar_65955;
	bool cppVar_65956;
	BIT_VEC cppVar_65958;
	BIT_VEC cppVar_65959;
	BIT_VEC cppVar_65960;
	bool cppVar_65961;
	BIT_VEC cppVar_65963;
	BIT_VEC cppVar_65964;
	BIT_VEC cppVar_65965;
	bool cppVar_65966;
	BIT_VEC cppVar_65968;
	BIT_VEC cppVar_65969;
	BIT_VEC cppVar_65970;
	bool cppVar_65971;
	BIT_VEC cppVar_65973;
	BIT_VEC cppVar_65974;
	BIT_VEC cppVar_65975;
	bool cppVar_65976;
	BIT_VEC cppVar_65978;
	BIT_VEC cppVar_65979;
	BIT_VEC cppVar_65980;
	bool cppVar_65981;
	BIT_VEC cppVar_65983;
	BIT_VEC cppVar_65984;
	BIT_VEC cppVar_65985;
	bool cppVar_65986;
	BIT_VEC cppVar_65988;
	BIT_VEC cppVar_65989;
	BIT_VEC cppVar_65990;
	bool cppVar_65991;
	BIT_VEC cppVar_65993;
	BIT_VEC cppVar_65994;
	BIT_VEC cppVar_65995;
	bool cppVar_65996;
	BIT_VEC cppVar_65998;
	BIT_VEC cppVar_65999;
	BIT_VEC cppVar_66000;
	bool cppVar_66001;
	BIT_VEC cppVar_66002;
	BIT_VEC cppVar_65997;
	BIT_VEC cppVar_65992;
	BIT_VEC cppVar_65987;
	BIT_VEC cppVar_65982;
	BIT_VEC cppVar_65977;
	BIT_VEC cppVar_65972;
	BIT_VEC cppVar_65967;
	BIT_VEC cppVar_65962;
	BIT_VEC cppVar_65957;
	BIT_VEC cppVar_65952;
	BIT_VEC cppVar_65947;
	BIT_VEC cppVar_65942;
	BIT_VEC cppVar_65937;
	BIT_VEC cppVar_65932;
	BIT_VEC cppVar_65927;
	BIT_VEC cppVar_65922;
	BIT_VEC cppVar_65917;
	BIT_VEC cppVar_65912;
	BIT_VEC cppVar_65907;
	BIT_VEC cppVar_65902;
	BIT_VEC cppVar_65897;
	BIT_VEC cppVar_65888;
	BIT_VEC cppVar_66003;
	BIT_VEC cppVar_65882;
	BIT_VEC cppVar_66005;
	BIT_VEC cppVar_66006;
	bool cppVar_66007;
	BIT_VEC cppVar_66009;
	BIT_VEC cppVar_66010;
	BIT_VEC cppVar_66011;
	BIT_VEC cppVar_66012;
	bool cppVar_66013;
	BIT_VEC cppVar_66015;
	BIT_VEC cppVar_66016;
	BIT_VEC cppVar_66017;
	BIT_VEC cppVar_66018;
	bool cppVar_66019;
	BIT_VEC cppVar_66020;
	BIT_VEC cppVar_66021;
	BIT_VEC cppVar_66022;
	BIT_VEC cppVar_66024;
	BIT_VEC cppVar_66025;
	BIT_VEC cppVar_66026;
	bool cppVar_66027;
	BIT_VEC cppVar_66029;
	BIT_VEC cppVar_66030;
	BIT_VEC cppVar_66031;
	bool cppVar_66032;
	BIT_VEC cppVar_66034;
	BIT_VEC cppVar_66035;
	BIT_VEC cppVar_66036;
	bool cppVar_66037;
	BIT_VEC cppVar_66039;
	BIT_VEC cppVar_66040;
	BIT_VEC cppVar_66041;
	bool cppVar_66042;
	BIT_VEC cppVar_66044;
	BIT_VEC cppVar_66045;
	BIT_VEC cppVar_66046;
	bool cppVar_66047;
	BIT_VEC cppVar_66049;
	BIT_VEC cppVar_66050;
	BIT_VEC cppVar_66051;
	bool cppVar_66052;
	BIT_VEC cppVar_66054;
	BIT_VEC cppVar_66055;
	BIT_VEC cppVar_66056;
	bool cppVar_66057;
	BIT_VEC cppVar_66059;
	BIT_VEC cppVar_66060;
	BIT_VEC cppVar_66061;
	bool cppVar_66062;
	BIT_VEC cppVar_66064;
	BIT_VEC cppVar_66065;
	BIT_VEC cppVar_66066;
	bool cppVar_66067;
	BIT_VEC cppVar_66069;
	BIT_VEC cppVar_66070;
	BIT_VEC cppVar_66071;
	bool cppVar_66072;
	BIT_VEC cppVar_66074;
	BIT_VEC cppVar_66075;
	BIT_VEC cppVar_66076;
	bool cppVar_66077;
	BIT_VEC cppVar_66079;
	BIT_VEC cppVar_66080;
	BIT_VEC cppVar_66081;
	bool cppVar_66082;
	BIT_VEC cppVar_66084;
	BIT_VEC cppVar_66085;
	BIT_VEC cppVar_66086;
	bool cppVar_66087;
	BIT_VEC cppVar_66089;
	BIT_VEC cppVar_66090;
	BIT_VEC cppVar_66091;
	bool cppVar_66092;
	BIT_VEC cppVar_66094;
	BIT_VEC cppVar_66095;
	BIT_VEC cppVar_66096;
	bool cppVar_66097;
	BIT_VEC cppVar_66099;
	BIT_VEC cppVar_66100;
	BIT_VEC cppVar_66101;
	bool cppVar_66102;
	BIT_VEC cppVar_66104;
	BIT_VEC cppVar_66105;
	BIT_VEC cppVar_66106;
	bool cppVar_66107;
	BIT_VEC cppVar_66109;
	BIT_VEC cppVar_66110;
	BIT_VEC cppVar_66111;
	bool cppVar_66112;
	BIT_VEC cppVar_66114;
	BIT_VEC cppVar_66115;
	BIT_VEC cppVar_66116;
	bool cppVar_66117;
	BIT_VEC cppVar_66119;
	BIT_VEC cppVar_66120;
	BIT_VEC cppVar_66121;
	bool cppVar_66122;
	BIT_VEC cppVar_66124;
	BIT_VEC cppVar_66125;
	BIT_VEC cppVar_66126;
	bool cppVar_66127;
	BIT_VEC cppVar_66128;
	BIT_VEC cppVar_66123;
	BIT_VEC cppVar_66118;
	BIT_VEC cppVar_66113;
	BIT_VEC cppVar_66108;
	BIT_VEC cppVar_66103;
	BIT_VEC cppVar_66098;
	BIT_VEC cppVar_66093;
	BIT_VEC cppVar_66088;
	BIT_VEC cppVar_66083;
	BIT_VEC cppVar_66078;
	BIT_VEC cppVar_66073;
	BIT_VEC cppVar_66068;
	BIT_VEC cppVar_66063;
	BIT_VEC cppVar_66058;
	BIT_VEC cppVar_66053;
	BIT_VEC cppVar_66048;
	BIT_VEC cppVar_66043;
	BIT_VEC cppVar_66038;
	BIT_VEC cppVar_66033;
	BIT_VEC cppVar_66028;
	BIT_VEC cppVar_66023;
	BIT_VEC cppVar_66014;
	BIT_VEC cppVar_66129;
	BIT_VEC cppVar_66130;
	BIT_VEC cppVar_66131;
	BIT_VEC cppVar_66132;
	BIT_VEC cppVar_66008;
	BIT_VEC cppVar_66134;
	BIT_VEC cppVar_66135;
	bool cppVar_66136;
	BIT_VEC cppVar_66138;
	BIT_VEC cppVar_66139;
	BIT_VEC cppVar_66140;
	BIT_VEC cppVar_66141;
	bool cppVar_66142;
	BIT_VEC cppVar_66144;
	BIT_VEC cppVar_66145;
	BIT_VEC cppVar_66146;
	BIT_VEC cppVar_66147;
	bool cppVar_66148;
	BIT_VEC cppVar_66149;
	BIT_VEC cppVar_66150;
	BIT_VEC cppVar_66151;
	BIT_VEC cppVar_66153;
	BIT_VEC cppVar_66154;
	BIT_VEC cppVar_66155;
	bool cppVar_66156;
	BIT_VEC cppVar_66158;
	BIT_VEC cppVar_66159;
	BIT_VEC cppVar_66160;
	bool cppVar_66161;
	BIT_VEC cppVar_66163;
	BIT_VEC cppVar_66164;
	BIT_VEC cppVar_66165;
	bool cppVar_66166;
	BIT_VEC cppVar_66168;
	BIT_VEC cppVar_66169;
	BIT_VEC cppVar_66170;
	bool cppVar_66171;
	BIT_VEC cppVar_66173;
	BIT_VEC cppVar_66174;
	BIT_VEC cppVar_66175;
	bool cppVar_66176;
	BIT_VEC cppVar_66178;
	BIT_VEC cppVar_66179;
	BIT_VEC cppVar_66180;
	bool cppVar_66181;
	BIT_VEC cppVar_66183;
	BIT_VEC cppVar_66184;
	BIT_VEC cppVar_66185;
	bool cppVar_66186;
	BIT_VEC cppVar_66188;
	BIT_VEC cppVar_66189;
	BIT_VEC cppVar_66190;
	bool cppVar_66191;
	BIT_VEC cppVar_66193;
	BIT_VEC cppVar_66194;
	BIT_VEC cppVar_66195;
	bool cppVar_66196;
	BIT_VEC cppVar_66198;
	BIT_VEC cppVar_66199;
	BIT_VEC cppVar_66200;
	bool cppVar_66201;
	BIT_VEC cppVar_66203;
	BIT_VEC cppVar_66204;
	BIT_VEC cppVar_66205;
	bool cppVar_66206;
	BIT_VEC cppVar_66208;
	BIT_VEC cppVar_66209;
	BIT_VEC cppVar_66210;
	bool cppVar_66211;
	BIT_VEC cppVar_66213;
	BIT_VEC cppVar_66214;
	BIT_VEC cppVar_66215;
	bool cppVar_66216;
	BIT_VEC cppVar_66218;
	BIT_VEC cppVar_66219;
	BIT_VEC cppVar_66220;
	bool cppVar_66221;
	BIT_VEC cppVar_66223;
	BIT_VEC cppVar_66224;
	BIT_VEC cppVar_66225;
	bool cppVar_66226;
	BIT_VEC cppVar_66228;
	BIT_VEC cppVar_66229;
	BIT_VEC cppVar_66230;
	bool cppVar_66231;
	BIT_VEC cppVar_66233;
	BIT_VEC cppVar_66234;
	BIT_VEC cppVar_66235;
	bool cppVar_66236;
	BIT_VEC cppVar_66238;
	BIT_VEC cppVar_66239;
	BIT_VEC cppVar_66240;
	bool cppVar_66241;
	BIT_VEC cppVar_66243;
	BIT_VEC cppVar_66244;
	BIT_VEC cppVar_66245;
	bool cppVar_66246;
	BIT_VEC cppVar_66248;
	BIT_VEC cppVar_66249;
	BIT_VEC cppVar_66250;
	bool cppVar_66251;
	BIT_VEC cppVar_66253;
	BIT_VEC cppVar_66254;
	BIT_VEC cppVar_66255;
	bool cppVar_66256;
	BIT_VEC cppVar_66257;
	BIT_VEC cppVar_66252;
	BIT_VEC cppVar_66247;
	BIT_VEC cppVar_66242;
	BIT_VEC cppVar_66237;
	BIT_VEC cppVar_66232;
	BIT_VEC cppVar_66227;
	BIT_VEC cppVar_66222;
	BIT_VEC cppVar_66217;
	BIT_VEC cppVar_66212;
	BIT_VEC cppVar_66207;
	BIT_VEC cppVar_66202;
	BIT_VEC cppVar_66197;
	BIT_VEC cppVar_66192;
	BIT_VEC cppVar_66187;
	BIT_VEC cppVar_66182;
	BIT_VEC cppVar_66177;
	BIT_VEC cppVar_66172;
	BIT_VEC cppVar_66167;
	BIT_VEC cppVar_66162;
	BIT_VEC cppVar_66157;
	BIT_VEC cppVar_66152;
	BIT_VEC cppVar_66143;
	BIT_VEC cppVar_66258;
	BIT_VEC cppVar_66137;
	BIT_VEC cppVar_66260;
	BIT_VEC cppVar_66261;
	bool cppVar_66262;
	BIT_VEC cppVar_66263;
	BIT_VEC cppVar_66264;
	bool cppVar_66265;
	bool cppVar_66266;
	BIT_VEC cppVar_66267;
	BIT_VEC cppVar_66268;
	BIT_VEC cppVar_66270;
	BIT_VEC cppVar_66271;
	bool cppVar_66272;
	BIT_VEC cppVar_66273;
	BIT_VEC cppVar_66274;
	bool cppVar_66275;
	bool cppVar_66276;
	BIT_VEC cppVar_66278;
	BIT_VEC cppVar_66279;
	BIT_VEC cppVar_66280;
	BIT_VEC cppVar_66281;
	bool cppVar_66282;
	BIT_VEC cppVar_66284;
	BIT_VEC cppVar_66285;
	BIT_VEC cppVar_66286;
	BIT_VEC cppVar_66287;
	bool cppVar_66288;
	BIT_VEC cppVar_66289;
	BIT_VEC cppVar_66290;
	BIT_VEC cppVar_66291;
	BIT_VEC cppVar_66293;
	BIT_VEC cppVar_66294;
	BIT_VEC cppVar_66295;
	bool cppVar_66296;
	BIT_VEC cppVar_66298;
	BIT_VEC cppVar_66299;
	BIT_VEC cppVar_66300;
	bool cppVar_66301;
	BIT_VEC cppVar_66303;
	BIT_VEC cppVar_66304;
	BIT_VEC cppVar_66305;
	bool cppVar_66306;
	BIT_VEC cppVar_66308;
	BIT_VEC cppVar_66309;
	BIT_VEC cppVar_66310;
	bool cppVar_66311;
	BIT_VEC cppVar_66313;
	BIT_VEC cppVar_66314;
	BIT_VEC cppVar_66315;
	bool cppVar_66316;
	BIT_VEC cppVar_66318;
	BIT_VEC cppVar_66319;
	BIT_VEC cppVar_66320;
	bool cppVar_66321;
	BIT_VEC cppVar_66323;
	BIT_VEC cppVar_66324;
	BIT_VEC cppVar_66325;
	bool cppVar_66326;
	BIT_VEC cppVar_66328;
	BIT_VEC cppVar_66329;
	BIT_VEC cppVar_66330;
	bool cppVar_66331;
	BIT_VEC cppVar_66333;
	BIT_VEC cppVar_66334;
	BIT_VEC cppVar_66335;
	bool cppVar_66336;
	BIT_VEC cppVar_66338;
	BIT_VEC cppVar_66339;
	BIT_VEC cppVar_66340;
	bool cppVar_66341;
	BIT_VEC cppVar_66343;
	BIT_VEC cppVar_66344;
	BIT_VEC cppVar_66345;
	bool cppVar_66346;
	BIT_VEC cppVar_66348;
	BIT_VEC cppVar_66349;
	BIT_VEC cppVar_66350;
	bool cppVar_66351;
	BIT_VEC cppVar_66353;
	BIT_VEC cppVar_66354;
	BIT_VEC cppVar_66355;
	bool cppVar_66356;
	BIT_VEC cppVar_66358;
	BIT_VEC cppVar_66359;
	BIT_VEC cppVar_66360;
	bool cppVar_66361;
	BIT_VEC cppVar_66363;
	BIT_VEC cppVar_66364;
	BIT_VEC cppVar_66365;
	bool cppVar_66366;
	BIT_VEC cppVar_66368;
	BIT_VEC cppVar_66369;
	BIT_VEC cppVar_66370;
	bool cppVar_66371;
	BIT_VEC cppVar_66373;
	BIT_VEC cppVar_66374;
	BIT_VEC cppVar_66375;
	bool cppVar_66376;
	BIT_VEC cppVar_66378;
	BIT_VEC cppVar_66379;
	BIT_VEC cppVar_66380;
	bool cppVar_66381;
	BIT_VEC cppVar_66383;
	BIT_VEC cppVar_66384;
	BIT_VEC cppVar_66385;
	bool cppVar_66386;
	BIT_VEC cppVar_66388;
	BIT_VEC cppVar_66389;
	BIT_VEC cppVar_66390;
	bool cppVar_66391;
	BIT_VEC cppVar_66393;
	BIT_VEC cppVar_66394;
	BIT_VEC cppVar_66395;
	bool cppVar_66396;
	BIT_VEC cppVar_66397;
	BIT_VEC cppVar_66392;
	BIT_VEC cppVar_66387;
	BIT_VEC cppVar_66382;
	BIT_VEC cppVar_66377;
	BIT_VEC cppVar_66372;
	BIT_VEC cppVar_66367;
	BIT_VEC cppVar_66362;
	BIT_VEC cppVar_66357;
	BIT_VEC cppVar_66352;
	BIT_VEC cppVar_66347;
	BIT_VEC cppVar_66342;
	BIT_VEC cppVar_66337;
	BIT_VEC cppVar_66332;
	BIT_VEC cppVar_66327;
	BIT_VEC cppVar_66322;
	BIT_VEC cppVar_66317;
	BIT_VEC cppVar_66312;
	BIT_VEC cppVar_66307;
	BIT_VEC cppVar_66302;
	BIT_VEC cppVar_66297;
	BIT_VEC cppVar_66292;
	BIT_VEC cppVar_66283;
	BIT_VEC cppVar_66398;
	BIT_VEC cppVar_66399;
	BIT_VEC cppVar_66277;
	BIT_VEC cppVar_66401;
	BIT_VEC cppVar_66402;
	bool cppVar_66403;
	BIT_VEC cppVar_66404;
	BIT_VEC cppVar_66405;
	bool cppVar_66406;
	BIT_VEC cppVar_66407;
	BIT_VEC cppVar_66408;
	bool cppVar_66409;
	BIT_VEC cppVar_66410;
	BIT_VEC cppVar_66411;
	bool cppVar_66412;
	BIT_VEC cppVar_66413;
	BIT_VEC cppVar_66414;
	bool cppVar_66415;
	BIT_VEC cppVar_66416;
	BIT_VEC cppVar_66417;
	bool cppVar_66418;
	BIT_VEC cppVar_66419;
	BIT_VEC cppVar_66420;
	bool cppVar_66421;
	BIT_VEC cppVar_66422;
	BIT_VEC cppVar_66423;
	bool cppVar_66424;
	BIT_VEC cppVar_66425;
	BIT_VEC cppVar_66426;
	bool cppVar_66427;
	bool cppVar_66428;
	bool cppVar_66429;
	bool cppVar_66430;
	bool cppVar_66431;
	bool cppVar_66432;
	bool cppVar_66433;
	bool cppVar_66434;
	bool cppVar_66435;
	BIT_VEC cppVar_66436;
	BIT_VEC cppVar_66437;
	BIT_VEC cppVar_66439;
	BIT_VEC cppVar_66440;
	bool cppVar_66441;
	BIT_VEC cppVar_66443;
	BIT_VEC cppVar_66444;
	BIT_VEC cppVar_66445;
	BIT_VEC cppVar_66446;
	bool cppVar_66447;
	BIT_VEC cppVar_66449;
	BIT_VEC cppVar_66450;
	BIT_VEC cppVar_66451;
	BIT_VEC cppVar_66452;
	bool cppVar_66453;
	BIT_VEC cppVar_66454;
	BIT_VEC cppVar_66455;
	BIT_VEC cppVar_66456;
	BIT_VEC cppVar_66458;
	BIT_VEC cppVar_66459;
	BIT_VEC cppVar_66460;
	bool cppVar_66461;
	BIT_VEC cppVar_66463;
	BIT_VEC cppVar_66464;
	BIT_VEC cppVar_66465;
	bool cppVar_66466;
	BIT_VEC cppVar_66468;
	BIT_VEC cppVar_66469;
	BIT_VEC cppVar_66470;
	bool cppVar_66471;
	BIT_VEC cppVar_66473;
	BIT_VEC cppVar_66474;
	BIT_VEC cppVar_66475;
	bool cppVar_66476;
	BIT_VEC cppVar_66478;
	BIT_VEC cppVar_66479;
	BIT_VEC cppVar_66480;
	bool cppVar_66481;
	BIT_VEC cppVar_66483;
	BIT_VEC cppVar_66484;
	BIT_VEC cppVar_66485;
	bool cppVar_66486;
	BIT_VEC cppVar_66488;
	BIT_VEC cppVar_66489;
	BIT_VEC cppVar_66490;
	bool cppVar_66491;
	BIT_VEC cppVar_66493;
	BIT_VEC cppVar_66494;
	BIT_VEC cppVar_66495;
	bool cppVar_66496;
	BIT_VEC cppVar_66498;
	BIT_VEC cppVar_66499;
	BIT_VEC cppVar_66500;
	bool cppVar_66501;
	BIT_VEC cppVar_66503;
	BIT_VEC cppVar_66504;
	BIT_VEC cppVar_66505;
	bool cppVar_66506;
	BIT_VEC cppVar_66508;
	BIT_VEC cppVar_66509;
	BIT_VEC cppVar_66510;
	bool cppVar_66511;
	BIT_VEC cppVar_66513;
	BIT_VEC cppVar_66514;
	BIT_VEC cppVar_66515;
	bool cppVar_66516;
	BIT_VEC cppVar_66518;
	BIT_VEC cppVar_66519;
	BIT_VEC cppVar_66520;
	bool cppVar_66521;
	BIT_VEC cppVar_66523;
	BIT_VEC cppVar_66524;
	BIT_VEC cppVar_66525;
	bool cppVar_66526;
	BIT_VEC cppVar_66528;
	BIT_VEC cppVar_66529;
	BIT_VEC cppVar_66530;
	bool cppVar_66531;
	BIT_VEC cppVar_66533;
	BIT_VEC cppVar_66534;
	BIT_VEC cppVar_66535;
	bool cppVar_66536;
	BIT_VEC cppVar_66538;
	BIT_VEC cppVar_66539;
	BIT_VEC cppVar_66540;
	bool cppVar_66541;
	BIT_VEC cppVar_66543;
	BIT_VEC cppVar_66544;
	BIT_VEC cppVar_66545;
	bool cppVar_66546;
	BIT_VEC cppVar_66548;
	BIT_VEC cppVar_66549;
	BIT_VEC cppVar_66550;
	bool cppVar_66551;
	BIT_VEC cppVar_66553;
	BIT_VEC cppVar_66554;
	BIT_VEC cppVar_66555;
	bool cppVar_66556;
	BIT_VEC cppVar_66558;
	BIT_VEC cppVar_66559;
	BIT_VEC cppVar_66560;
	bool cppVar_66561;
	BIT_VEC cppVar_66562;
	BIT_VEC cppVar_66557;
	BIT_VEC cppVar_66552;
	BIT_VEC cppVar_66547;
	BIT_VEC cppVar_66542;
	BIT_VEC cppVar_66537;
	BIT_VEC cppVar_66532;
	BIT_VEC cppVar_66527;
	BIT_VEC cppVar_66522;
	BIT_VEC cppVar_66517;
	BIT_VEC cppVar_66512;
	BIT_VEC cppVar_66507;
	BIT_VEC cppVar_66502;
	BIT_VEC cppVar_66497;
	BIT_VEC cppVar_66492;
	BIT_VEC cppVar_66487;
	BIT_VEC cppVar_66482;
	BIT_VEC cppVar_66477;
	BIT_VEC cppVar_66472;
	BIT_VEC cppVar_66467;
	BIT_VEC cppVar_66462;
	BIT_VEC cppVar_66457;
	BIT_VEC cppVar_66448;
	BIT_VEC cppVar_66563;
	BIT_VEC cppVar_66564;
	BIT_VEC cppVar_66442;
	BIT_VEC cppVar_66566;
	BIT_VEC cppVar_66567;
	bool cppVar_66568;
	BIT_VEC cppVar_66569;
	BIT_VEC cppVar_66570;
	bool cppVar_66571;
	BIT_VEC cppVar_66572;
	BIT_VEC cppVar_66573;
	bool cppVar_66574;
	BIT_VEC cppVar_66575;
	BIT_VEC cppVar_66576;
	bool cppVar_66577;
	BIT_VEC cppVar_66578;
	BIT_VEC cppVar_66579;
	bool cppVar_66580;
	BIT_VEC cppVar_66581;
	BIT_VEC cppVar_66582;
	bool cppVar_66583;
	BIT_VEC cppVar_66584;
	BIT_VEC cppVar_66585;
	bool cppVar_66586;
	BIT_VEC cppVar_66587;
	BIT_VEC cppVar_66588;
	bool cppVar_66589;
	BIT_VEC cppVar_66590;
	BIT_VEC cppVar_66591;
	bool cppVar_66592;
	BIT_VEC cppVar_66593;
	BIT_VEC cppVar_66594;
	bool cppVar_66595;
	BIT_VEC cppVar_66596;
	BIT_VEC cppVar_66597;
	bool cppVar_66598;
	BIT_VEC cppVar_66599;
	BIT_VEC cppVar_66600;
	bool cppVar_66601;
	BIT_VEC cppVar_66602;
	BIT_VEC cppVar_66603;
	bool cppVar_66604;
	BIT_VEC cppVar_66605;
	BIT_VEC cppVar_66606;
	bool cppVar_66607;
	BIT_VEC cppVar_66608;
	BIT_VEC cppVar_66609;
	bool cppVar_66610;
	BIT_VEC cppVar_66611;
	BIT_VEC cppVar_66612;
	bool cppVar_66613;
	BIT_VEC cppVar_66614;
	BIT_VEC cppVar_66615;
	bool cppVar_66616;
	BIT_VEC cppVar_66617;
	BIT_VEC cppVar_66618;
	bool cppVar_66619;
	BIT_VEC cppVar_66620;
	BIT_VEC cppVar_66621;
	bool cppVar_66622;
	BIT_VEC cppVar_66623;
	BIT_VEC cppVar_66624;
	bool cppVar_66625;
	BIT_VEC cppVar_66626;
	BIT_VEC cppVar_66627;
	bool cppVar_66628;
	BIT_VEC cppVar_66629;
	BIT_VEC cppVar_66630;
	bool cppVar_66631;
	BIT_VEC cppVar_66632;
	BIT_VEC cppVar_66633;
	bool cppVar_66634;
	BIT_VEC cppVar_66635;
	BIT_VEC cppVar_66636;
	bool cppVar_66637;
	BIT_VEC cppVar_66638;
	BIT_VEC cppVar_66639;
	bool cppVar_66640;
	BIT_VEC cppVar_66641;
	BIT_VEC cppVar_66642;
	bool cppVar_66643;
	BIT_VEC cppVar_66644;
	BIT_VEC cppVar_66645;
	bool cppVar_66646;
	BIT_VEC cppVar_66647;
	BIT_VEC cppVar_66648;
	bool cppVar_66649;
	BIT_VEC cppVar_66650;
	BIT_VEC cppVar_66651;
	bool cppVar_66652;
	BIT_VEC cppVar_66653;
	BIT_VEC cppVar_66654;
	bool cppVar_66655;
	BIT_VEC cppVar_66656;
	BIT_VEC cppVar_66657;
	bool cppVar_66658;
	BIT_VEC cppVar_66659;
	BIT_VEC cppVar_66660;
	bool cppVar_66661;
	BIT_VEC cppVar_66662;
	BIT_VEC cppVar_66663;
	bool cppVar_66664;
	BIT_VEC cppVar_66665;
	BIT_VEC cppVar_66666;
	bool cppVar_66667;
	BIT_VEC cppVar_66668;
	BIT_VEC cppVar_66669;
	bool cppVar_66670;
	BIT_VEC cppVar_66671;
	BIT_VEC cppVar_66672;
	bool cppVar_66673;
	BIT_VEC cppVar_66674;
	BIT_VEC cppVar_66675;
	bool cppVar_66676;
	BIT_VEC cppVar_66677;
	BIT_VEC cppVar_66678;
	bool cppVar_66679;
	BIT_VEC cppVar_66680;
	BIT_VEC cppVar_66681;
	bool cppVar_66682;
	BIT_VEC cppVar_66683;
	BIT_VEC cppVar_66684;
	bool cppVar_66685;
	BIT_VEC cppVar_66686;
	BIT_VEC cppVar_66687;
	bool cppVar_66688;
	BIT_VEC cppVar_66689;
	BIT_VEC cppVar_66690;
	bool cppVar_66691;
	BIT_VEC cppVar_66692;
	BIT_VEC cppVar_66693;
	bool cppVar_66694;
	BIT_VEC cppVar_66695;
	BIT_VEC cppVar_66696;
	bool cppVar_66697;
	BIT_VEC cppVar_66698;
	BIT_VEC cppVar_66699;
	bool cppVar_66700;
	BIT_VEC cppVar_66701;
	BIT_VEC cppVar_66702;
	bool cppVar_66703;
	BIT_VEC cppVar_66704;
	BIT_VEC cppVar_66705;
	bool cppVar_66706;
	BIT_VEC cppVar_66707;
	BIT_VEC cppVar_66708;
	bool cppVar_66709;
	BIT_VEC cppVar_66710;
	BIT_VEC cppVar_66711;
	bool cppVar_66712;
	BIT_VEC cppVar_66713;
	BIT_VEC cppVar_66714;
	bool cppVar_66715;
	BIT_VEC cppVar_66716;
	BIT_VEC cppVar_66717;
	bool cppVar_66718;
	BIT_VEC cppVar_66719;
	BIT_VEC cppVar_66720;
	bool cppVar_66721;
	BIT_VEC cppVar_66722;
	BIT_VEC cppVar_66723;
	bool cppVar_66724;
	BIT_VEC cppVar_66725;
	BIT_VEC cppVar_66726;
	bool cppVar_66727;
	BIT_VEC cppVar_66728;
	BIT_VEC cppVar_66729;
	bool cppVar_66730;
	BIT_VEC cppVar_66731;
	BIT_VEC cppVar_66732;
	bool cppVar_66733;
	BIT_VEC cppVar_66734;
	BIT_VEC cppVar_66735;
	bool cppVar_66736;
	BIT_VEC cppVar_66737;
	BIT_VEC cppVar_66738;
	bool cppVar_66739;
	BIT_VEC cppVar_66740;
	BIT_VEC cppVar_66741;
	bool cppVar_66742;
	BIT_VEC cppVar_66743;
	BIT_VEC cppVar_66744;
	bool cppVar_66745;
	BIT_VEC cppVar_66746;
	BIT_VEC cppVar_66747;
	bool cppVar_66748;
	BIT_VEC cppVar_66749;
	BIT_VEC cppVar_66750;
	bool cppVar_66751;
	BIT_VEC cppVar_66752;
	BIT_VEC cppVar_66753;
	bool cppVar_66754;
	BIT_VEC cppVar_66755;
	BIT_VEC cppVar_66756;
	bool cppVar_66757;
	BIT_VEC cppVar_66758;
	BIT_VEC cppVar_66759;
	bool cppVar_66760;
	BIT_VEC cppVar_66761;
	BIT_VEC cppVar_66762;
	bool cppVar_66763;
	BIT_VEC cppVar_66764;
	BIT_VEC cppVar_66765;
	bool cppVar_66766;
	BIT_VEC cppVar_66767;
	BIT_VEC cppVar_66768;
	bool cppVar_66769;
	BIT_VEC cppVar_66770;
	BIT_VEC cppVar_66771;
	bool cppVar_66772;
	BIT_VEC cppVar_66773;
	BIT_VEC cppVar_66774;
	bool cppVar_66775;
	BIT_VEC cppVar_66776;
	BIT_VEC cppVar_66777;
	bool cppVar_66778;
	BIT_VEC cppVar_66779;
	BIT_VEC cppVar_66780;
	bool cppVar_66781;
	BIT_VEC cppVar_66782;
	BIT_VEC cppVar_66783;
	bool cppVar_66784;
	BIT_VEC cppVar_66785;
	BIT_VEC cppVar_66786;
	bool cppVar_66787;
	BIT_VEC cppVar_66788;
	BIT_VEC cppVar_66789;
	bool cppVar_66790;
	BIT_VEC cppVar_66791;
	BIT_VEC cppVar_66792;
	bool cppVar_66793;
	BIT_VEC cppVar_66794;
	BIT_VEC cppVar_66795;
	bool cppVar_66796;
	BIT_VEC cppVar_66797;
	BIT_VEC cppVar_66798;
	bool cppVar_66799;
	BIT_VEC cppVar_66800;
	BIT_VEC cppVar_66801;
	bool cppVar_66802;
	BIT_VEC cppVar_66803;
	BIT_VEC cppVar_66804;
	bool cppVar_66805;
	BIT_VEC cppVar_66806;
	BIT_VEC cppVar_66807;
	bool cppVar_66808;
	BIT_VEC cppVar_66809;
	BIT_VEC cppVar_66810;
	bool cppVar_66811;
	BIT_VEC cppVar_66812;
	BIT_VEC cppVar_66813;
	bool cppVar_66814;
	BIT_VEC cppVar_66815;
	BIT_VEC cppVar_66816;
	bool cppVar_66817;
	BIT_VEC cppVar_66818;
	BIT_VEC cppVar_66819;
	bool cppVar_66820;
	BIT_VEC cppVar_66821;
	BIT_VEC cppVar_66822;
	bool cppVar_66823;
	BIT_VEC cppVar_66824;
	BIT_VEC cppVar_66825;
	bool cppVar_66826;
	BIT_VEC cppVar_66827;
	BIT_VEC cppVar_66828;
	bool cppVar_66829;
	BIT_VEC cppVar_66830;
	BIT_VEC cppVar_66831;
	bool cppVar_66832;
	BIT_VEC cppVar_66833;
	BIT_VEC cppVar_66834;
	bool cppVar_66835;
	BIT_VEC cppVar_66836;
	BIT_VEC cppVar_66837;
	bool cppVar_66838;
	BIT_VEC cppVar_66839;
	BIT_VEC cppVar_66840;
	bool cppVar_66841;
	BIT_VEC cppVar_66842;
	BIT_VEC cppVar_66843;
	bool cppVar_66844;
	BIT_VEC cppVar_66845;
	BIT_VEC cppVar_66846;
	bool cppVar_66847;
	BIT_VEC cppVar_66848;
	BIT_VEC cppVar_66849;
	bool cppVar_66850;
	BIT_VEC cppVar_66851;
	BIT_VEC cppVar_66852;
	bool cppVar_66853;
	BIT_VEC cppVar_66854;
	BIT_VEC cppVar_66855;
	bool cppVar_66856;
	BIT_VEC cppVar_66857;
	BIT_VEC cppVar_66858;
	bool cppVar_66859;
	BIT_VEC cppVar_66860;
	BIT_VEC cppVar_66861;
	bool cppVar_66862;
	BIT_VEC cppVar_66863;
	BIT_VEC cppVar_66864;
	bool cppVar_66865;
	BIT_VEC cppVar_66866;
	BIT_VEC cppVar_66867;
	bool cppVar_66868;
	BIT_VEC cppVar_66869;
	BIT_VEC cppVar_66870;
	bool cppVar_66871;
	BIT_VEC cppVar_66872;
	BIT_VEC cppVar_66873;
	bool cppVar_66874;
	BIT_VEC cppVar_66875;
	BIT_VEC cppVar_66876;
	bool cppVar_66877;
	BIT_VEC cppVar_66878;
	BIT_VEC cppVar_66879;
	bool cppVar_66880;
	BIT_VEC cppVar_66881;
	BIT_VEC cppVar_66882;
	bool cppVar_66883;
	BIT_VEC cppVar_66884;
	BIT_VEC cppVar_66885;
	bool cppVar_66886;
	BIT_VEC cppVar_66887;
	BIT_VEC cppVar_66888;
	bool cppVar_66889;
	BIT_VEC cppVar_66890;
	BIT_VEC cppVar_66891;
	bool cppVar_66892;
	BIT_VEC cppVar_66893;
	BIT_VEC cppVar_66894;
	bool cppVar_66895;
	BIT_VEC cppVar_66896;
	BIT_VEC cppVar_66897;
	bool cppVar_66898;
	BIT_VEC cppVar_66899;
	BIT_VEC cppVar_66900;
	bool cppVar_66901;
	BIT_VEC cppVar_66902;
	BIT_VEC cppVar_66903;
	bool cppVar_66904;
	BIT_VEC cppVar_66905;
	BIT_VEC cppVar_66906;
	bool cppVar_66907;
	BIT_VEC cppVar_66908;
	BIT_VEC cppVar_66909;
	bool cppVar_66910;
	BIT_VEC cppVar_66911;
	BIT_VEC cppVar_66912;
	bool cppVar_66913;
	BIT_VEC cppVar_66914;
	BIT_VEC cppVar_66915;
	bool cppVar_66916;
	BIT_VEC cppVar_66917;
	BIT_VEC cppVar_66918;
	bool cppVar_66919;
	BIT_VEC cppVar_66920;
	BIT_VEC cppVar_66921;
	bool cppVar_66922;
	BIT_VEC cppVar_66923;
	BIT_VEC cppVar_66924;
	bool cppVar_66925;
	BIT_VEC cppVar_66926;
	BIT_VEC cppVar_66927;
	bool cppVar_66928;
	BIT_VEC cppVar_66929;
	BIT_VEC cppVar_66930;
	bool cppVar_66931;
	BIT_VEC cppVar_66932;
	BIT_VEC cppVar_66933;
	bool cppVar_66934;
	BIT_VEC cppVar_66935;
	BIT_VEC cppVar_66936;
	bool cppVar_66937;
	BIT_VEC cppVar_66938;
	BIT_VEC cppVar_66939;
	bool cppVar_66940;
	BIT_VEC cppVar_66941;
	BIT_VEC cppVar_66942;
	bool cppVar_66943;
	BIT_VEC cppVar_66944;
	BIT_VEC cppVar_66945;
	bool cppVar_66946;
	BIT_VEC cppVar_66947;
	BIT_VEC cppVar_66948;
	bool cppVar_66949;
	BIT_VEC cppVar_66950;
	BIT_VEC cppVar_66951;
	bool cppVar_66952;
	BIT_VEC cppVar_66953;
	BIT_VEC cppVar_66954;
	bool cppVar_66955;
	BIT_VEC cppVar_66956;
	BIT_VEC cppVar_66957;
	bool cppVar_66958;
	BIT_VEC cppVar_66959;
	BIT_VEC cppVar_66960;
	bool cppVar_66961;
	BIT_VEC cppVar_66962;
	BIT_VEC cppVar_66963;
	bool cppVar_66964;
	BIT_VEC cppVar_66965;
	BIT_VEC cppVar_66966;
	bool cppVar_66967;
	BIT_VEC cppVar_66968;
	BIT_VEC cppVar_66969;
	bool cppVar_66970;
	BIT_VEC cppVar_66971;
	BIT_VEC cppVar_66972;
	bool cppVar_66973;
	BIT_VEC cppVar_66974;
	BIT_VEC cppVar_66975;
	bool cppVar_66976;
	BIT_VEC cppVar_66977;
	BIT_VEC cppVar_66978;
	bool cppVar_66979;
	BIT_VEC cppVar_66980;
	BIT_VEC cppVar_66981;
	bool cppVar_66982;
	BIT_VEC cppVar_66983;
	BIT_VEC cppVar_66984;
	bool cppVar_66985;
	BIT_VEC cppVar_66986;
	BIT_VEC cppVar_66987;
	bool cppVar_66988;
	BIT_VEC cppVar_66989;
	BIT_VEC cppVar_66990;
	bool cppVar_66991;
	BIT_VEC cppVar_66992;
	BIT_VEC cppVar_66993;
	bool cppVar_66994;
	BIT_VEC cppVar_66995;
	BIT_VEC cppVar_66996;
	bool cppVar_66997;
	BIT_VEC cppVar_66998;
	BIT_VEC cppVar_66999;
	bool cppVar_67000;
	BIT_VEC cppVar_67001;
	BIT_VEC cppVar_67002;
	bool cppVar_67003;
	BIT_VEC cppVar_67004;
	BIT_VEC cppVar_67005;
	bool cppVar_67006;
	BIT_VEC cppVar_67007;
	BIT_VEC cppVar_67008;
	bool cppVar_67009;
	BIT_VEC cppVar_67010;
	BIT_VEC cppVar_67011;
	bool cppVar_67012;
	BIT_VEC cppVar_67013;
	BIT_VEC cppVar_67014;
	bool cppVar_67015;
	BIT_VEC cppVar_67016;
	BIT_VEC cppVar_67017;
	bool cppVar_67018;
	BIT_VEC cppVar_67019;
	BIT_VEC cppVar_67020;
	bool cppVar_67021;
	BIT_VEC cppVar_67022;
	BIT_VEC cppVar_67023;
	bool cppVar_67024;
	BIT_VEC cppVar_67025;
	BIT_VEC cppVar_67026;
	bool cppVar_67027;
	BIT_VEC cppVar_67028;
	BIT_VEC cppVar_67029;
	bool cppVar_67030;
	BIT_VEC cppVar_67031;
	BIT_VEC cppVar_67032;
	bool cppVar_67033;
	BIT_VEC cppVar_67034;
	BIT_VEC cppVar_67035;
	bool cppVar_67036;
	BIT_VEC cppVar_67037;
	BIT_VEC cppVar_67038;
	bool cppVar_67039;
	BIT_VEC cppVar_67040;
	BIT_VEC cppVar_67041;
	bool cppVar_67042;
	BIT_VEC cppVar_67043;
	BIT_VEC cppVar_67044;
	bool cppVar_67045;
	BIT_VEC cppVar_67046;
	BIT_VEC cppVar_67047;
	bool cppVar_67048;
	BIT_VEC cppVar_67049;
	BIT_VEC cppVar_67050;
	bool cppVar_67051;
	BIT_VEC cppVar_67052;
	BIT_VEC cppVar_67053;
	bool cppVar_67054;
	BIT_VEC cppVar_67055;
	BIT_VEC cppVar_67056;
	bool cppVar_67057;
	BIT_VEC cppVar_67058;
	BIT_VEC cppVar_67059;
	bool cppVar_67060;
	BIT_VEC cppVar_67061;
	BIT_VEC cppVar_67062;
	bool cppVar_67063;
	BIT_VEC cppVar_67064;
	BIT_VEC cppVar_67065;
	bool cppVar_67066;
	BIT_VEC cppVar_67067;
	BIT_VEC cppVar_67068;
	bool cppVar_67069;
	BIT_VEC cppVar_67070;
	BIT_VEC cppVar_67071;
	bool cppVar_67072;
	BIT_VEC cppVar_67073;
	BIT_VEC cppVar_67074;
	bool cppVar_67075;
	BIT_VEC cppVar_67076;
	BIT_VEC cppVar_67077;
	bool cppVar_67078;
	BIT_VEC cppVar_67079;
	BIT_VEC cppVar_67080;
	bool cppVar_67081;
	BIT_VEC cppVar_67082;
	BIT_VEC cppVar_67083;
	bool cppVar_67084;
	BIT_VEC cppVar_67085;
	BIT_VEC cppVar_67086;
	bool cppVar_67087;
	BIT_VEC cppVar_67088;
	BIT_VEC cppVar_67089;
	bool cppVar_67090;
	BIT_VEC cppVar_67091;
	BIT_VEC cppVar_67092;
	bool cppVar_67093;
	BIT_VEC cppVar_67094;
	BIT_VEC cppVar_67095;
	bool cppVar_67096;
	BIT_VEC cppVar_67097;
	BIT_VEC cppVar_67098;
	bool cppVar_67099;
	BIT_VEC cppVar_67100;
	BIT_VEC cppVar_67101;
	bool cppVar_67102;
	BIT_VEC cppVar_67103;
	BIT_VEC cppVar_67104;
	bool cppVar_67105;
	BIT_VEC cppVar_67106;
	BIT_VEC cppVar_67107;
	bool cppVar_67108;
	BIT_VEC cppVar_67109;
	BIT_VEC cppVar_67110;
	bool cppVar_67111;
	BIT_VEC cppVar_67112;
	BIT_VEC cppVar_67113;
	bool cppVar_67114;
	BIT_VEC cppVar_67115;
	BIT_VEC cppVar_67116;
	bool cppVar_67117;
	BIT_VEC cppVar_67118;
	BIT_VEC cppVar_67119;
	bool cppVar_67120;
	BIT_VEC cppVar_67121;
	BIT_VEC cppVar_67122;
	bool cppVar_67123;
	BIT_VEC cppVar_67124;
	BIT_VEC cppVar_67125;
	bool cppVar_67126;
	BIT_VEC cppVar_67127;
	BIT_VEC cppVar_67128;
	bool cppVar_67129;
	BIT_VEC cppVar_67130;
	BIT_VEC cppVar_67131;
	bool cppVar_67132;
	BIT_VEC cppVar_67133;
	BIT_VEC cppVar_67134;
	bool cppVar_67135;
	BIT_VEC cppVar_67136;
	BIT_VEC cppVar_67137;
	bool cppVar_67138;
	BIT_VEC cppVar_67139;
	BIT_VEC cppVar_67140;
	bool cppVar_67141;
	BIT_VEC cppVar_67142;
	BIT_VEC cppVar_67143;
	bool cppVar_67144;
	BIT_VEC cppVar_67145;
	BIT_VEC cppVar_67146;
	bool cppVar_67147;
	BIT_VEC cppVar_67148;
	BIT_VEC cppVar_67149;
	bool cppVar_67150;
	BIT_VEC cppVar_67151;
	BIT_VEC cppVar_67152;
	bool cppVar_67153;
	BIT_VEC cppVar_67154;
	BIT_VEC cppVar_67155;
	bool cppVar_67156;
	BIT_VEC cppVar_67157;
	BIT_VEC cppVar_67158;
	bool cppVar_67159;
	BIT_VEC cppVar_67160;
	BIT_VEC cppVar_67161;
	bool cppVar_67162;
	BIT_VEC cppVar_67163;
	BIT_VEC cppVar_67164;
	bool cppVar_67165;
	BIT_VEC cppVar_67166;
	BIT_VEC cppVar_67167;
	bool cppVar_67168;
	BIT_VEC cppVar_67169;
	BIT_VEC cppVar_67170;
	bool cppVar_67171;
	BIT_VEC cppVar_67172;
	BIT_VEC cppVar_67173;
	bool cppVar_67174;
	BIT_VEC cppVar_67175;
	BIT_VEC cppVar_67176;
	bool cppVar_67177;
	BIT_VEC cppVar_67178;
	BIT_VEC cppVar_67179;
	bool cppVar_67180;
	BIT_VEC cppVar_67181;
	BIT_VEC cppVar_67182;
	bool cppVar_67183;
	BIT_VEC cppVar_67184;
	BIT_VEC cppVar_67185;
	bool cppVar_67186;
	BIT_VEC cppVar_67187;
	BIT_VEC cppVar_67188;
	bool cppVar_67189;
	BIT_VEC cppVar_67190;
	BIT_VEC cppVar_67191;
	bool cppVar_67192;
	BIT_VEC cppVar_67193;
	BIT_VEC cppVar_67194;
	bool cppVar_67195;
	BIT_VEC cppVar_67196;
	BIT_VEC cppVar_67197;
	bool cppVar_67198;
	BIT_VEC cppVar_67199;
	BIT_VEC cppVar_67200;
	bool cppVar_67201;
	BIT_VEC cppVar_67202;
	BIT_VEC cppVar_67203;
	bool cppVar_67204;
	BIT_VEC cppVar_67205;
	BIT_VEC cppVar_67206;
	bool cppVar_67207;
	BIT_VEC cppVar_67208;
	BIT_VEC cppVar_67209;
	bool cppVar_67210;
	BIT_VEC cppVar_67211;
	BIT_VEC cppVar_67212;
	bool cppVar_67213;
	BIT_VEC cppVar_67214;
	BIT_VEC cppVar_67215;
	bool cppVar_67216;
	BIT_VEC cppVar_67217;
	BIT_VEC cppVar_67218;
	bool cppVar_67219;
	BIT_VEC cppVar_67220;
	BIT_VEC cppVar_67221;
	bool cppVar_67222;
	BIT_VEC cppVar_67223;
	BIT_VEC cppVar_67224;
	bool cppVar_67225;
	bool cppVar_67226;
	bool cppVar_67227;
	bool cppVar_67228;
	bool cppVar_67229;
	bool cppVar_67230;
	bool cppVar_67231;
	bool cppVar_67232;
	bool cppVar_67233;
	bool cppVar_67234;
	bool cppVar_67235;
	bool cppVar_67236;
	bool cppVar_67237;
	bool cppVar_67238;
	bool cppVar_67239;
	bool cppVar_67240;
	bool cppVar_67241;
	bool cppVar_67242;
	bool cppVar_67243;
	bool cppVar_67244;
	bool cppVar_67245;
	bool cppVar_67246;
	bool cppVar_67247;
	bool cppVar_67248;
	bool cppVar_67249;
	bool cppVar_67250;
	bool cppVar_67251;
	bool cppVar_67252;
	bool cppVar_67253;
	bool cppVar_67254;
	bool cppVar_67255;
	bool cppVar_67256;
	bool cppVar_67257;
	bool cppVar_67258;
	bool cppVar_67259;
	bool cppVar_67260;
	bool cppVar_67261;
	bool cppVar_67262;
	bool cppVar_67263;
	bool cppVar_67264;
	bool cppVar_67265;
	bool cppVar_67266;
	bool cppVar_67267;
	bool cppVar_67268;
	bool cppVar_67269;
	bool cppVar_67270;
	bool cppVar_67271;
	bool cppVar_67272;
	bool cppVar_67273;
	bool cppVar_67274;
	bool cppVar_67275;
	bool cppVar_67276;
	bool cppVar_67277;
	bool cppVar_67278;
	bool cppVar_67279;
	bool cppVar_67280;
	bool cppVar_67281;
	bool cppVar_67282;
	bool cppVar_67283;
	bool cppVar_67284;
	bool cppVar_67285;
	bool cppVar_67286;
	bool cppVar_67287;
	bool cppVar_67288;
	bool cppVar_67289;
	bool cppVar_67290;
	bool cppVar_67291;
	bool cppVar_67292;
	bool cppVar_67293;
	bool cppVar_67294;
	bool cppVar_67295;
	bool cppVar_67296;
	bool cppVar_67297;
	bool cppVar_67298;
	bool cppVar_67299;
	bool cppVar_67300;
	bool cppVar_67301;
	bool cppVar_67302;
	bool cppVar_67303;
	bool cppVar_67304;
	bool cppVar_67305;
	bool cppVar_67306;
	bool cppVar_67307;
	bool cppVar_67308;
	bool cppVar_67309;
	bool cppVar_67310;
	bool cppVar_67311;
	bool cppVar_67312;
	bool cppVar_67313;
	bool cppVar_67314;
	bool cppVar_67315;
	bool cppVar_67316;
	bool cppVar_67317;
	bool cppVar_67318;
	bool cppVar_67319;
	bool cppVar_67320;
	bool cppVar_67321;
	bool cppVar_67322;
	bool cppVar_67323;
	bool cppVar_67324;
	bool cppVar_67325;
	bool cppVar_67326;
	bool cppVar_67327;
	bool cppVar_67328;
	bool cppVar_67329;
	bool cppVar_67330;
	bool cppVar_67331;
	bool cppVar_67332;
	bool cppVar_67333;
	bool cppVar_67334;
	bool cppVar_67335;
	bool cppVar_67336;
	bool cppVar_67337;
	bool cppVar_67338;
	bool cppVar_67339;
	bool cppVar_67340;
	bool cppVar_67341;
	bool cppVar_67342;
	bool cppVar_67343;
	bool cppVar_67344;
	bool cppVar_67345;
	bool cppVar_67346;
	bool cppVar_67347;
	bool cppVar_67348;
	bool cppVar_67349;
	bool cppVar_67350;
	bool cppVar_67351;
	bool cppVar_67352;
	bool cppVar_67353;
	bool cppVar_67354;
	bool cppVar_67355;
	bool cppVar_67356;
	bool cppVar_67357;
	bool cppVar_67358;
	bool cppVar_67359;
	bool cppVar_67360;
	bool cppVar_67361;
	bool cppVar_67362;
	bool cppVar_67363;
	bool cppVar_67364;
	bool cppVar_67365;
	bool cppVar_67366;
	bool cppVar_67367;
	bool cppVar_67368;
	bool cppVar_67369;
	bool cppVar_67370;
	bool cppVar_67371;
	bool cppVar_67372;
	bool cppVar_67373;
	bool cppVar_67374;
	bool cppVar_67375;
	bool cppVar_67376;
	bool cppVar_67377;
	bool cppVar_67378;
	bool cppVar_67379;
	bool cppVar_67380;
	bool cppVar_67381;
	bool cppVar_67382;
	bool cppVar_67383;
	bool cppVar_67384;
	bool cppVar_67385;
	bool cppVar_67386;
	bool cppVar_67387;
	bool cppVar_67388;
	bool cppVar_67389;
	bool cppVar_67390;
	bool cppVar_67391;
	bool cppVar_67392;
	bool cppVar_67393;
	bool cppVar_67394;
	bool cppVar_67395;
	bool cppVar_67396;
	bool cppVar_67397;
	bool cppVar_67398;
	bool cppVar_67399;
	bool cppVar_67400;
	bool cppVar_67401;
	bool cppVar_67402;
	bool cppVar_67403;
	bool cppVar_67404;
	bool cppVar_67405;
	bool cppVar_67406;
	bool cppVar_67407;
	bool cppVar_67408;
	bool cppVar_67409;
	bool cppVar_67410;
	bool cppVar_67411;
	bool cppVar_67412;
	bool cppVar_67413;
	bool cppVar_67414;
	bool cppVar_67415;
	bool cppVar_67416;
	bool cppVar_67417;
	bool cppVar_67418;
	bool cppVar_67419;
	bool cppVar_67420;
	bool cppVar_67421;
	bool cppVar_67422;
	bool cppVar_67423;
	bool cppVar_67424;
	bool cppVar_67425;
	bool cppVar_67426;
	bool cppVar_67427;
	bool cppVar_67428;
	bool cppVar_67429;
	bool cppVar_67430;
	bool cppVar_67431;
	bool cppVar_67432;
	bool cppVar_67433;
	bool cppVar_67434;
	bool cppVar_67435;
	bool cppVar_67436;
	bool cppVar_67437;
	bool cppVar_67438;
	bool cppVar_67439;
	bool cppVar_67440;
	bool cppVar_67441;
	bool cppVar_67442;
	bool cppVar_67443;
	bool cppVar_67444;
	BIT_VEC cppVar_67447;
	BIT_VEC cppVar_67448;
	BIT_VEC cppVar_67449;
	BIT_VEC cppVar_67450;
	BIT_VEC cppVar_67451;
	bool cppVar_67452;
	BIT_VEC cppVar_67453;
	BIT_VEC cppVar_67454;
	BIT_VEC cppVar_67455;
	BIT_VEC cppVar_67456;
	BIT_VEC cppVar_67457;
	BIT_VEC cppVar_67458;
	BIT_VEC cppVar_67459;
	BIT_VEC cppVar_67460;
	BIT_VEC cppVar_67461;
	BIT_VEC cppVar_67462;
	BIT_VEC cppVar_67463;
	BIT_VEC cppVar_67446;
	BIT_VEC cppVar_67464;
	bool cppVar_67465;
	BIT_VEC cppVar_67466;
	BIT_VEC cppVar_67467;
	BIT_VEC cppVar_67468;
	BIT_VEC cppVar_67469;
	BIT_VEC cppVar_67470;
	BIT_VEC cppVar_67471;
	BIT_VEC cppVar_67472;
	BIT_VEC cppVar_67475;
	BIT_VEC cppVar_67476;
	BIT_VEC cppVar_67477;
	bool cppVar_67478;
	BIT_VEC cppVar_67479;
	BIT_VEC cppVar_67480;
	BIT_VEC cppVar_67481;
	BIT_VEC cppVar_67482;
	BIT_VEC cppVar_67483;
	BIT_VEC cppVar_67484;
	BIT_VEC cppVar_67485;
	BIT_VEC cppVar_67486;
	BIT_VEC cppVar_67487;
	BIT_VEC cppVar_67474;
	BIT_VEC cppVar_67488;
	BIT_VEC cppVar_67489;
	bool cppVar_67490;
	BIT_VEC cppVar_67492;
	BIT_VEC cppVar_67493;
	BIT_VEC cppVar_67494;
	bool cppVar_67495;
	BIT_VEC cppVar_67496;
	BIT_VEC cppVar_67497;
	BIT_VEC cppVar_67498;
	BIT_VEC cppVar_67499;
	BIT_VEC cppVar_67500;
	BIT_VEC cppVar_67501;
	BIT_VEC cppVar_67502;
	BIT_VEC cppVar_67503;
	BIT_VEC cppVar_67504;
	BIT_VEC cppVar_67491;
	BIT_VEC cppVar_67505;
	BIT_VEC cppVar_67508;
	BIT_VEC cppVar_67509;
	BIT_VEC cppVar_67510;
	bool cppVar_67511;
	BIT_VEC cppVar_67512;
	BIT_VEC cppVar_67513;
	BIT_VEC cppVar_67514;
	BIT_VEC cppVar_67515;
	BIT_VEC cppVar_67516;
	BIT_VEC cppVar_67517;
	BIT_VEC cppVar_67518;
	BIT_VEC cppVar_67519;
	BIT_VEC cppVar_67520;
	BIT_VEC cppVar_67507;
	BIT_VEC cppVar_67521;
	bool cppVar_67522;
	BIT_VEC cppVar_67525;
	BIT_VEC cppVar_67526;
	BIT_VEC cppVar_67527;
	bool cppVar_67528;
	BIT_VEC cppVar_67529;
	BIT_VEC cppVar_67530;
	BIT_VEC cppVar_67531;
	BIT_VEC cppVar_67532;
	BIT_VEC cppVar_67533;
	BIT_VEC cppVar_67534;
	BIT_VEC cppVar_67535;
	BIT_VEC cppVar_67536;
	BIT_VEC cppVar_67537;
	BIT_VEC cppVar_67524;
	BIT_VEC cppVar_67538;
	bool cppVar_67539;
	BIT_VEC cppVar_67542;
	BIT_VEC cppVar_67543;
	BIT_VEC cppVar_67544;
	bool cppVar_67545;
	BIT_VEC cppVar_67546;
	BIT_VEC cppVar_67547;
	BIT_VEC cppVar_67548;
	BIT_VEC cppVar_67549;
	BIT_VEC cppVar_67550;
	BIT_VEC cppVar_67551;
	BIT_VEC cppVar_67552;
	BIT_VEC cppVar_67553;
	BIT_VEC cppVar_67554;
	BIT_VEC cppVar_67541;
	BIT_VEC cppVar_67555;
	bool cppVar_67556;
	BIT_VEC cppVar_67559;
	BIT_VEC cppVar_67560;
	BIT_VEC cppVar_67561;
	bool cppVar_67562;
	BIT_VEC cppVar_67563;
	BIT_VEC cppVar_67564;
	BIT_VEC cppVar_67565;
	BIT_VEC cppVar_67566;
	BIT_VEC cppVar_67567;
	BIT_VEC cppVar_67568;
	BIT_VEC cppVar_67569;
	BIT_VEC cppVar_67570;
	BIT_VEC cppVar_67571;
	BIT_VEC cppVar_67558;
	BIT_VEC cppVar_67572;
	bool cppVar_67573;
	BIT_VEC cppVar_67576;
	BIT_VEC cppVar_67577;
	BIT_VEC cppVar_67578;
	bool cppVar_67579;
	BIT_VEC cppVar_67580;
	BIT_VEC cppVar_67581;
	BIT_VEC cppVar_67582;
	BIT_VEC cppVar_67583;
	BIT_VEC cppVar_67584;
	BIT_VEC cppVar_67585;
	BIT_VEC cppVar_67586;
	BIT_VEC cppVar_67587;
	BIT_VEC cppVar_67588;
	BIT_VEC cppVar_67575;
	BIT_VEC cppVar_67589;
	bool cppVar_67590;
	BIT_VEC cppVar_67593;
	BIT_VEC cppVar_67594;
	BIT_VEC cppVar_67595;
	bool cppVar_67596;
	BIT_VEC cppVar_67597;
	BIT_VEC cppVar_67598;
	BIT_VEC cppVar_67599;
	BIT_VEC cppVar_67600;
	BIT_VEC cppVar_67601;
	BIT_VEC cppVar_67602;
	BIT_VEC cppVar_67603;
	BIT_VEC cppVar_67604;
	BIT_VEC cppVar_67605;
	BIT_VEC cppVar_67592;
	BIT_VEC cppVar_67606;
	bool cppVar_67607;
	BIT_VEC cppVar_67610;
	BIT_VEC cppVar_67611;
	BIT_VEC cppVar_67612;
	bool cppVar_67613;
	BIT_VEC cppVar_67614;
	BIT_VEC cppVar_67615;
	BIT_VEC cppVar_67616;
	BIT_VEC cppVar_67617;
	BIT_VEC cppVar_67618;
	BIT_VEC cppVar_67619;
	BIT_VEC cppVar_67620;
	BIT_VEC cppVar_67621;
	BIT_VEC cppVar_67622;
	BIT_VEC cppVar_67609;
	BIT_VEC cppVar_67623;
	bool cppVar_67624;
	BIT_VEC cppVar_67627;
	BIT_VEC cppVar_67628;
	BIT_VEC cppVar_67629;
	bool cppVar_67630;
	BIT_VEC cppVar_67631;
	BIT_VEC cppVar_67632;
	BIT_VEC cppVar_67633;
	BIT_VEC cppVar_67634;
	BIT_VEC cppVar_67635;
	BIT_VEC cppVar_67636;
	BIT_VEC cppVar_67637;
	BIT_VEC cppVar_67638;
	BIT_VEC cppVar_67639;
	BIT_VEC cppVar_67626;
	BIT_VEC cppVar_67640;
	bool cppVar_67641;
	BIT_VEC cppVar_67644;
	BIT_VEC cppVar_67645;
	BIT_VEC cppVar_67646;
	bool cppVar_67647;
	BIT_VEC cppVar_67648;
	BIT_VEC cppVar_67649;
	BIT_VEC cppVar_67650;
	BIT_VEC cppVar_67651;
	BIT_VEC cppVar_67652;
	BIT_VEC cppVar_67653;
	BIT_VEC cppVar_67654;
	BIT_VEC cppVar_67655;
	BIT_VEC cppVar_67656;
	BIT_VEC cppVar_67643;
	BIT_VEC cppVar_67657;
	bool cppVar_67658;
	BIT_VEC cppVar_67661;
	BIT_VEC cppVar_67662;
	BIT_VEC cppVar_67663;
	bool cppVar_67664;
	BIT_VEC cppVar_67665;
	BIT_VEC cppVar_67666;
	BIT_VEC cppVar_67667;
	BIT_VEC cppVar_67668;
	BIT_VEC cppVar_67669;
	BIT_VEC cppVar_67670;
	BIT_VEC cppVar_67671;
	BIT_VEC cppVar_67672;
	BIT_VEC cppVar_67673;
	BIT_VEC cppVar_67660;
	BIT_VEC cppVar_67674;
	bool cppVar_67675;
	BIT_VEC cppVar_67678;
	BIT_VEC cppVar_67679;
	BIT_VEC cppVar_67680;
	bool cppVar_67681;
	BIT_VEC cppVar_67682;
	BIT_VEC cppVar_67683;
	BIT_VEC cppVar_67684;
	BIT_VEC cppVar_67685;
	BIT_VEC cppVar_67686;
	BIT_VEC cppVar_67687;
	BIT_VEC cppVar_67688;
	BIT_VEC cppVar_67689;
	BIT_VEC cppVar_67690;
	BIT_VEC cppVar_67677;
	BIT_VEC cppVar_67691;
	bool cppVar_67692;
	BIT_VEC cppVar_67695;
	BIT_VEC cppVar_67696;
	BIT_VEC cppVar_67697;
	bool cppVar_67698;
	BIT_VEC cppVar_67699;
	BIT_VEC cppVar_67700;
	BIT_VEC cppVar_67701;
	BIT_VEC cppVar_67702;
	BIT_VEC cppVar_67703;
	BIT_VEC cppVar_67704;
	BIT_VEC cppVar_67705;
	BIT_VEC cppVar_67706;
	BIT_VEC cppVar_67707;
	BIT_VEC cppVar_67694;
	BIT_VEC cppVar_67708;
	bool cppVar_67709;
	BIT_VEC cppVar_67712;
	BIT_VEC cppVar_67713;
	BIT_VEC cppVar_67714;
	bool cppVar_67715;
	BIT_VEC cppVar_67716;
	BIT_VEC cppVar_67717;
	BIT_VEC cppVar_67718;
	BIT_VEC cppVar_67719;
	BIT_VEC cppVar_67720;
	BIT_VEC cppVar_67721;
	BIT_VEC cppVar_67722;
	BIT_VEC cppVar_67723;
	BIT_VEC cppVar_67724;
	BIT_VEC cppVar_67711;
	BIT_VEC cppVar_67725;
	bool cppVar_67726;
	BIT_VEC cppVar_67729;
	BIT_VEC cppVar_67730;
	BIT_VEC cppVar_67731;
	bool cppVar_67732;
	BIT_VEC cppVar_67733;
	BIT_VEC cppVar_67734;
	BIT_VEC cppVar_67735;
	BIT_VEC cppVar_67736;
	BIT_VEC cppVar_67737;
	BIT_VEC cppVar_67738;
	BIT_VEC cppVar_67739;
	BIT_VEC cppVar_67740;
	BIT_VEC cppVar_67741;
	BIT_VEC cppVar_67728;
	BIT_VEC cppVar_67742;
	bool cppVar_67743;
	BIT_VEC cppVar_67746;
	BIT_VEC cppVar_67747;
	BIT_VEC cppVar_67748;
	bool cppVar_67749;
	BIT_VEC cppVar_67750;
	BIT_VEC cppVar_67751;
	BIT_VEC cppVar_67752;
	BIT_VEC cppVar_67753;
	BIT_VEC cppVar_67754;
	BIT_VEC cppVar_67755;
	BIT_VEC cppVar_67756;
	BIT_VEC cppVar_67757;
	BIT_VEC cppVar_67758;
	BIT_VEC cppVar_67745;
	BIT_VEC cppVar_67759;
	bool cppVar_67760;
	BIT_VEC cppVar_67763;
	BIT_VEC cppVar_67764;
	BIT_VEC cppVar_67765;
	bool cppVar_67766;
	BIT_VEC cppVar_67767;
	BIT_VEC cppVar_67768;
	BIT_VEC cppVar_67769;
	BIT_VEC cppVar_67770;
	BIT_VEC cppVar_67771;
	BIT_VEC cppVar_67772;
	BIT_VEC cppVar_67773;
	BIT_VEC cppVar_67774;
	BIT_VEC cppVar_67775;
	BIT_VEC cppVar_67762;
	BIT_VEC cppVar_67776;
	bool cppVar_67777;
	BIT_VEC cppVar_67780;
	BIT_VEC cppVar_67781;
	BIT_VEC cppVar_67782;
	bool cppVar_67783;
	BIT_VEC cppVar_67784;
	BIT_VEC cppVar_67785;
	BIT_VEC cppVar_67786;
	BIT_VEC cppVar_67787;
	BIT_VEC cppVar_67788;
	BIT_VEC cppVar_67789;
	BIT_VEC cppVar_67790;
	BIT_VEC cppVar_67791;
	BIT_VEC cppVar_67792;
	BIT_VEC cppVar_67779;
	BIT_VEC cppVar_67793;
	bool cppVar_67794;
	BIT_VEC cppVar_67797;
	BIT_VEC cppVar_67798;
	BIT_VEC cppVar_67799;
	bool cppVar_67800;
	BIT_VEC cppVar_67801;
	BIT_VEC cppVar_67802;
	BIT_VEC cppVar_67803;
	BIT_VEC cppVar_67804;
	BIT_VEC cppVar_67805;
	BIT_VEC cppVar_67806;
	BIT_VEC cppVar_67807;
	BIT_VEC cppVar_67808;
	BIT_VEC cppVar_67809;
	BIT_VEC cppVar_67796;
	BIT_VEC cppVar_67810;
	bool cppVar_67811;
	BIT_VEC cppVar_67814;
	BIT_VEC cppVar_67815;
	BIT_VEC cppVar_67816;
	bool cppVar_67817;
	BIT_VEC cppVar_67818;
	BIT_VEC cppVar_67819;
	BIT_VEC cppVar_67820;
	BIT_VEC cppVar_67821;
	BIT_VEC cppVar_67822;
	BIT_VEC cppVar_67823;
	BIT_VEC cppVar_67824;
	BIT_VEC cppVar_67825;
	BIT_VEC cppVar_67826;
	BIT_VEC cppVar_67813;
	BIT_VEC cppVar_67827;
	bool cppVar_67828;
	BIT_VEC cppVar_67831;
	BIT_VEC cppVar_67832;
	BIT_VEC cppVar_67833;
	bool cppVar_67834;
	BIT_VEC cppVar_67835;
	BIT_VEC cppVar_67836;
	BIT_VEC cppVar_67837;
	BIT_VEC cppVar_67838;
	BIT_VEC cppVar_67839;
	BIT_VEC cppVar_67840;
	BIT_VEC cppVar_67841;
	BIT_VEC cppVar_67842;
	BIT_VEC cppVar_67843;
	BIT_VEC cppVar_67830;
	BIT_VEC cppVar_67844;
	bool cppVar_67845;
	BIT_VEC cppVar_67848;
	BIT_VEC cppVar_67849;
	BIT_VEC cppVar_67850;
	bool cppVar_67851;
	BIT_VEC cppVar_67852;
	BIT_VEC cppVar_67853;
	BIT_VEC cppVar_67854;
	BIT_VEC cppVar_67855;
	BIT_VEC cppVar_67856;
	BIT_VEC cppVar_67857;
	BIT_VEC cppVar_67858;
	BIT_VEC cppVar_67859;
	BIT_VEC cppVar_67860;
	BIT_VEC cppVar_67847;
	BIT_VEC cppVar_67861;
	bool cppVar_67862;
	BIT_VEC cppVar_67863;
	BIT_VEC cppVar_67846;
	BIT_VEC cppVar_67829;
	BIT_VEC cppVar_67812;
	BIT_VEC cppVar_67795;
	BIT_VEC cppVar_67778;
	BIT_VEC cppVar_67761;
	BIT_VEC cppVar_67744;
	BIT_VEC cppVar_67727;
	BIT_VEC cppVar_67710;
	BIT_VEC cppVar_67693;
	BIT_VEC cppVar_67676;
	BIT_VEC cppVar_67659;
	BIT_VEC cppVar_67642;
	BIT_VEC cppVar_67625;
	BIT_VEC cppVar_67608;
	BIT_VEC cppVar_67591;
	BIT_VEC cppVar_67574;
	BIT_VEC cppVar_67557;
	BIT_VEC cppVar_67540;
	BIT_VEC cppVar_67523;
	BIT_VEC cppVar_67506;
	BIT_VEC cppVar_67473;
	BIT_VEC cppVar_67864;
	BIT_VEC cppVar_67865;
	BIT_VEC cppVar_67866;
	BIT_VEC cppVar_67867;
	BIT_VEC cppVar_67868;
	BIT_VEC cppVar_67869;
	BIT_VEC cppVar_67870;
	BIT_VEC cppVar_67871;
	BIT_VEC cppVar_67872;
	BIT_VEC cppVar_67445;
	BIT_VEC cppVar_66565;
	BIT_VEC cppVar_66438;
	BIT_VEC cppVar_66400;
	BIT_VEC cppVar_66269;
	BIT_VEC cppVar_66259;
	BIT_VEC cppVar_66133;
	BIT_VEC cppVar_66004;
	BIT_VEC cppVar_65878;
	BIT_VEC cppVar_65749;
	BIT_VEC cppVar_65623;
	BIT_VEC cppVar_65494;
	BIT_VEC cppVar_65481;
	BIT_VEC cppVar_65355;
	BIT_VEC cppVar_65338;
	BIT_VEC cppVar_65321;
	BIT_VEC cppVar_65171;
	BIT_VEC cppVar_65021;
	BIT_VEC cppVar_64871;
	BIT_VEC cppVar_64721;
	BIT_VEC cppVar_64571;
	BIT_VEC cppVar_64421;
	BIT_VEC cppVar_64271;
	BIT_VEC cppVar_64121;
	BIT_VEC cppVar_64115;
	BIT_VEC cppVar_64101;
	BIT_VEC cppVar_64083;
	cppVar_64084 = ROM.rd(PC);
	cppVar_64086 = (cppVar_64084 == 208);
	if (cppVar_64086) {
	cppVar_64089 = PC + 1;
	cppVar_64089 = (cppVar_64089 & cppMask_un_16_);
	cppVar_64090 = ROM.rd(cppVar_64089);
	cppVar_64092 = (cppVar_64090 == 129);
	if (cppVar_64092) {
	cppVar_64094 = PC + 1;
	cppVar_64094 = (cppVar_64094 & cppMask_un_16_);
	cppVar_64095 = ROM.rd(cppVar_64094);
	cppVar_64097 = (cppVar_64095 == 129);
	if (cppVar_64097) {
	cppVar_64098 = IRAM.rd(SP);
	cppVar_64093 = cppVar_64098;
	} else {
	cppVar_64093 = SP;
	}
	cppVar_64087 = cppVar_64093;
	} else {
	cppVar_64100 = SP - 1;
	cppVar_64100 = (cppVar_64100 & cppMask_un_8_);
	cppVar_64087 = cppVar_64100;
	}
	cppVar_64083 = cppVar_64087;
	} else {
	cppVar_64102 = ROM.rd(PC);
	cppVar_64104 = (cppVar_64102 == 245);
	cppVar_64105 = ROM.rd(PC);
	cppVar_64107 = (cppVar_64105 == 197);
	cppVar_64108 = cppVar_64104 || cppVar_64107;
	if (cppVar_64108) {
	cppVar_64111 = PC + 1;
	cppVar_64111 = (cppVar_64111 & cppMask_un_16_);
	cppVar_64112 = ROM.rd(cppVar_64111);
	cppVar_64114 = (cppVar_64112 == 129);
	if (cppVar_64114) {
	cppVar_64109 = ACC;
	} else {
	cppVar_64109 = SP;
	}
	cppVar_64101 = cppVar_64109;
	} else {
	cppVar_64116 = ROM.rd(PC);
	cppVar_64118 = (cppVar_64116 == 192);
	if (cppVar_64118) {
	cppVar_64120 = SP + 1;
	cppVar_64120 = (cppVar_64120 & cppMask_un_8_);
	cppVar_64115 = cppVar_64120;
	} else {
	cppVar_64122 = ROM.rd(PC);
	cppVar_64124 = (cppVar_64122 == 143);
	if (cppVar_64124) {
	cppVar_64127 = PC + 1;
	cppVar_64127 = (cppVar_64127 & cppMask_un_16_);
	cppVar_64128 = ROM.rd(cppVar_64127);
	cppVar_64130 = (cppVar_64128 == 129);
	if (cppVar_64130) {
	cppVar_64133 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64135 = (cppVar_64133 << 3) | 7;
	cppVar_64135 = (cppVar_64135 & cppMask_un_5_);
	cppVar_64136 = (0 << 5) | cppVar_64135;
	cppVar_64136 = (cppVar_64136 & cppMask_un_8_);
	cppVar_64137 = (cppVar_64136 >> 7) & cppMask_un_1_;
	cppVar_64139 = (cppVar_64137 == 0);
	if (cppVar_64139) {
	cppVar_64140 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64141 = (cppVar_64140 << 3) | 7;
	cppVar_64141 = (cppVar_64141 & cppMask_un_5_);
	cppVar_64142 = (0 << 5) | cppVar_64141;
	cppVar_64142 = (cppVar_64142 & cppMask_un_8_);
	cppVar_64143 = IRAM.rd(cppVar_64142);
	cppVar_64131 = cppVar_64143;
	} else {
	cppVar_64145 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64146 = (cppVar_64145 << 3) | 7;
	cppVar_64146 = (cppVar_64146 & cppMask_un_5_);
	cppVar_64147 = (0 << 5) | cppVar_64146;
	cppVar_64147 = (cppVar_64147 & cppMask_un_8_);
	cppVar_64149 = (cppVar_64147 == 128);
	if (cppVar_64149) {
	cppVar_64144 = P0;
	} else {
	cppVar_64151 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64152 = (cppVar_64151 << 3) | 7;
	cppVar_64152 = (cppVar_64152 & cppMask_un_5_);
	cppVar_64153 = (0 << 5) | cppVar_64152;
	cppVar_64153 = (cppVar_64153 & cppMask_un_8_);
	cppVar_64155 = (cppVar_64153 == 129);
	if (cppVar_64155) {
	cppVar_64150 = SP;
	} else {
	cppVar_64157 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64158 = (cppVar_64157 << 3) | 7;
	cppVar_64158 = (cppVar_64158 & cppMask_un_5_);
	cppVar_64159 = (0 << 5) | cppVar_64158;
	cppVar_64159 = (cppVar_64159 & cppMask_un_8_);
	cppVar_64161 = (cppVar_64159 == 130);
	if (cppVar_64161) {
	cppVar_64156 = DPL;
	} else {
	cppVar_64163 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64164 = (cppVar_64163 << 3) | 7;
	cppVar_64164 = (cppVar_64164 & cppMask_un_5_);
	cppVar_64165 = (0 << 5) | cppVar_64164;
	cppVar_64165 = (cppVar_64165 & cppMask_un_8_);
	cppVar_64167 = (cppVar_64165 == 131);
	if (cppVar_64167) {
	cppVar_64162 = DPH;
	} else {
	cppVar_64169 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64170 = (cppVar_64169 << 3) | 7;
	cppVar_64170 = (cppVar_64170 & cppMask_un_5_);
	cppVar_64171 = (0 << 5) | cppVar_64170;
	cppVar_64171 = (cppVar_64171 & cppMask_un_8_);
	cppVar_64173 = (cppVar_64171 == 135);
	if (cppVar_64173) {
	cppVar_64168 = PCON;
	} else {
	cppVar_64175 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64176 = (cppVar_64175 << 3) | 7;
	cppVar_64176 = (cppVar_64176 & cppMask_un_5_);
	cppVar_64177 = (0 << 5) | cppVar_64176;
	cppVar_64177 = (cppVar_64177 & cppMask_un_8_);
	cppVar_64179 = (cppVar_64177 == 136);
	if (cppVar_64179) {
	cppVar_64174 = TCON;
	} else {
	cppVar_64181 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64182 = (cppVar_64181 << 3) | 7;
	cppVar_64182 = (cppVar_64182 & cppMask_un_5_);
	cppVar_64183 = (0 << 5) | cppVar_64182;
	cppVar_64183 = (cppVar_64183 & cppMask_un_8_);
	cppVar_64185 = (cppVar_64183 == 137);
	if (cppVar_64185) {
	cppVar_64180 = TMOD;
	} else {
	cppVar_64187 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64188 = (cppVar_64187 << 3) | 7;
	cppVar_64188 = (cppVar_64188 & cppMask_un_5_);
	cppVar_64189 = (0 << 5) | cppVar_64188;
	cppVar_64189 = (cppVar_64189 & cppMask_un_8_);
	cppVar_64191 = (cppVar_64189 == 138);
	if (cppVar_64191) {
	cppVar_64186 = TL0;
	} else {
	cppVar_64193 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64194 = (cppVar_64193 << 3) | 7;
	cppVar_64194 = (cppVar_64194 & cppMask_un_5_);
	cppVar_64195 = (0 << 5) | cppVar_64194;
	cppVar_64195 = (cppVar_64195 & cppMask_un_8_);
	cppVar_64197 = (cppVar_64195 == 140);
	if (cppVar_64197) {
	cppVar_64192 = TH0;
	} else {
	cppVar_64199 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64200 = (cppVar_64199 << 3) | 7;
	cppVar_64200 = (cppVar_64200 & cppMask_un_5_);
	cppVar_64201 = (0 << 5) | cppVar_64200;
	cppVar_64201 = (cppVar_64201 & cppMask_un_8_);
	cppVar_64203 = (cppVar_64201 == 139);
	if (cppVar_64203) {
	cppVar_64198 = TL1;
	} else {
	cppVar_64205 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64206 = (cppVar_64205 << 3) | 7;
	cppVar_64206 = (cppVar_64206 & cppMask_un_5_);
	cppVar_64207 = (0 << 5) | cppVar_64206;
	cppVar_64207 = (cppVar_64207 & cppMask_un_8_);
	cppVar_64209 = (cppVar_64207 == 141);
	if (cppVar_64209) {
	cppVar_64204 = TH1;
	} else {
	cppVar_64211 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64212 = (cppVar_64211 << 3) | 7;
	cppVar_64212 = (cppVar_64212 & cppMask_un_5_);
	cppVar_64213 = (0 << 5) | cppVar_64212;
	cppVar_64213 = (cppVar_64213 & cppMask_un_8_);
	cppVar_64215 = (cppVar_64213 == 144);
	if (cppVar_64215) {
	cppVar_64210 = P1;
	} else {
	cppVar_64217 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64218 = (cppVar_64217 << 3) | 7;
	cppVar_64218 = (cppVar_64218 & cppMask_un_5_);
	cppVar_64219 = (0 << 5) | cppVar_64218;
	cppVar_64219 = (cppVar_64219 & cppMask_un_8_);
	cppVar_64221 = (cppVar_64219 == 152);
	if (cppVar_64221) {
	cppVar_64216 = SCON;
	} else {
	cppVar_64223 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64224 = (cppVar_64223 << 3) | 7;
	cppVar_64224 = (cppVar_64224 & cppMask_un_5_);
	cppVar_64225 = (0 << 5) | cppVar_64224;
	cppVar_64225 = (cppVar_64225 & cppMask_un_8_);
	cppVar_64227 = (cppVar_64225 == 153);
	if (cppVar_64227) {
	cppVar_64222 = SBUF;
	} else {
	cppVar_64229 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64230 = (cppVar_64229 << 3) | 7;
	cppVar_64230 = (cppVar_64230 & cppMask_un_5_);
	cppVar_64231 = (0 << 5) | cppVar_64230;
	cppVar_64231 = (cppVar_64231 & cppMask_un_8_);
	cppVar_64233 = (cppVar_64231 == 160);
	if (cppVar_64233) {
	cppVar_64228 = P2;
	} else {
	cppVar_64235 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64236 = (cppVar_64235 << 3) | 7;
	cppVar_64236 = (cppVar_64236 & cppMask_un_5_);
	cppVar_64237 = (0 << 5) | cppVar_64236;
	cppVar_64237 = (cppVar_64237 & cppMask_un_8_);
	cppVar_64239 = (cppVar_64237 == 168);
	if (cppVar_64239) {
	cppVar_64234 = IE;
	} else {
	cppVar_64241 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64242 = (cppVar_64241 << 3) | 7;
	cppVar_64242 = (cppVar_64242 & cppMask_un_5_);
	cppVar_64243 = (0 << 5) | cppVar_64242;
	cppVar_64243 = (cppVar_64243 & cppMask_un_8_);
	cppVar_64245 = (cppVar_64243 == 176);
	if (cppVar_64245) {
	cppVar_64240 = P3;
	} else {
	cppVar_64247 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64248 = (cppVar_64247 << 3) | 7;
	cppVar_64248 = (cppVar_64248 & cppMask_un_5_);
	cppVar_64249 = (0 << 5) | cppVar_64248;
	cppVar_64249 = (cppVar_64249 & cppMask_un_8_);
	cppVar_64251 = (cppVar_64249 == 184);
	if (cppVar_64251) {
	cppVar_64246 = IP;
	} else {
	cppVar_64253 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64254 = (cppVar_64253 << 3) | 7;
	cppVar_64254 = (cppVar_64254 & cppMask_un_5_);
	cppVar_64255 = (0 << 5) | cppVar_64254;
	cppVar_64255 = (cppVar_64255 & cppMask_un_8_);
	cppVar_64257 = (cppVar_64255 == 208);
	if (cppVar_64257) {
	cppVar_64252 = PSW;
	} else {
	cppVar_64259 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64260 = (cppVar_64259 << 3) | 7;
	cppVar_64260 = (cppVar_64260 & cppMask_un_5_);
	cppVar_64261 = (0 << 5) | cppVar_64260;
	cppVar_64261 = (cppVar_64261 & cppMask_un_8_);
	cppVar_64263 = (cppVar_64261 == 224);
	if (cppVar_64263) {
	cppVar_64258 = ACC;
	} else {
	cppVar_64265 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64266 = (cppVar_64265 << 3) | 7;
	cppVar_64266 = (cppVar_64266 & cppMask_un_5_);
	cppVar_64267 = (0 << 5) | cppVar_64266;
	cppVar_64267 = (cppVar_64267 & cppMask_un_8_);
	cppVar_64269 = (cppVar_64267 == 240);
	if (cppVar_64269) {
	cppVar_64264 = B;
	} else {
	cppVar_64264 = 0;
	}
	cppVar_64258 = cppVar_64264;
	}
	cppVar_64252 = cppVar_64258;
	}
	cppVar_64246 = cppVar_64252;
	}
	cppVar_64240 = cppVar_64246;
	}
	cppVar_64234 = cppVar_64240;
	}
	cppVar_64228 = cppVar_64234;
	}
	cppVar_64222 = cppVar_64228;
	}
	cppVar_64216 = cppVar_64222;
	}
	cppVar_64210 = cppVar_64216;
	}
	cppVar_64204 = cppVar_64210;
	}
	cppVar_64198 = cppVar_64204;
	}
	cppVar_64192 = cppVar_64198;
	}
	cppVar_64186 = cppVar_64192;
	}
	cppVar_64180 = cppVar_64186;
	}
	cppVar_64174 = cppVar_64180;
	}
	cppVar_64168 = cppVar_64174;
	}
	cppVar_64162 = cppVar_64168;
	}
	cppVar_64156 = cppVar_64162;
	}
	cppVar_64150 = cppVar_64156;
	}
	cppVar_64144 = cppVar_64150;
	}
	cppVar_64131 = cppVar_64144;
	}
	cppVar_64125 = cppVar_64131;
	} else {
	cppVar_64125 = SP;
	}
	cppVar_64121 = cppVar_64125;
	} else {
	cppVar_64272 = ROM.rd(PC);
	cppVar_64274 = (cppVar_64272 == 142);
	if (cppVar_64274) {
	cppVar_64277 = PC + 1;
	cppVar_64277 = (cppVar_64277 & cppMask_un_16_);
	cppVar_64278 = ROM.rd(cppVar_64277);
	cppVar_64280 = (cppVar_64278 == 129);
	if (cppVar_64280) {
	cppVar_64283 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64285 = (cppVar_64283 << 3) | 6;
	cppVar_64285 = (cppVar_64285 & cppMask_un_5_);
	cppVar_64286 = (0 << 5) | cppVar_64285;
	cppVar_64286 = (cppVar_64286 & cppMask_un_8_);
	cppVar_64287 = (cppVar_64286 >> 7) & cppMask_un_1_;
	cppVar_64289 = (cppVar_64287 == 0);
	if (cppVar_64289) {
	cppVar_64290 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64291 = (cppVar_64290 << 3) | 6;
	cppVar_64291 = (cppVar_64291 & cppMask_un_5_);
	cppVar_64292 = (0 << 5) | cppVar_64291;
	cppVar_64292 = (cppVar_64292 & cppMask_un_8_);
	cppVar_64293 = IRAM.rd(cppVar_64292);
	cppVar_64281 = cppVar_64293;
	} else {
	cppVar_64295 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64296 = (cppVar_64295 << 3) | 6;
	cppVar_64296 = (cppVar_64296 & cppMask_un_5_);
	cppVar_64297 = (0 << 5) | cppVar_64296;
	cppVar_64297 = (cppVar_64297 & cppMask_un_8_);
	cppVar_64299 = (cppVar_64297 == 128);
	if (cppVar_64299) {
	cppVar_64294 = P0;
	} else {
	cppVar_64301 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64302 = (cppVar_64301 << 3) | 6;
	cppVar_64302 = (cppVar_64302 & cppMask_un_5_);
	cppVar_64303 = (0 << 5) | cppVar_64302;
	cppVar_64303 = (cppVar_64303 & cppMask_un_8_);
	cppVar_64305 = (cppVar_64303 == 129);
	if (cppVar_64305) {
	cppVar_64300 = SP;
	} else {
	cppVar_64307 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64308 = (cppVar_64307 << 3) | 6;
	cppVar_64308 = (cppVar_64308 & cppMask_un_5_);
	cppVar_64309 = (0 << 5) | cppVar_64308;
	cppVar_64309 = (cppVar_64309 & cppMask_un_8_);
	cppVar_64311 = (cppVar_64309 == 130);
	if (cppVar_64311) {
	cppVar_64306 = DPL;
	} else {
	cppVar_64313 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64314 = (cppVar_64313 << 3) | 6;
	cppVar_64314 = (cppVar_64314 & cppMask_un_5_);
	cppVar_64315 = (0 << 5) | cppVar_64314;
	cppVar_64315 = (cppVar_64315 & cppMask_un_8_);
	cppVar_64317 = (cppVar_64315 == 131);
	if (cppVar_64317) {
	cppVar_64312 = DPH;
	} else {
	cppVar_64319 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64320 = (cppVar_64319 << 3) | 6;
	cppVar_64320 = (cppVar_64320 & cppMask_un_5_);
	cppVar_64321 = (0 << 5) | cppVar_64320;
	cppVar_64321 = (cppVar_64321 & cppMask_un_8_);
	cppVar_64323 = (cppVar_64321 == 135);
	if (cppVar_64323) {
	cppVar_64318 = PCON;
	} else {
	cppVar_64325 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64326 = (cppVar_64325 << 3) | 6;
	cppVar_64326 = (cppVar_64326 & cppMask_un_5_);
	cppVar_64327 = (0 << 5) | cppVar_64326;
	cppVar_64327 = (cppVar_64327 & cppMask_un_8_);
	cppVar_64329 = (cppVar_64327 == 136);
	if (cppVar_64329) {
	cppVar_64324 = TCON;
	} else {
	cppVar_64331 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64332 = (cppVar_64331 << 3) | 6;
	cppVar_64332 = (cppVar_64332 & cppMask_un_5_);
	cppVar_64333 = (0 << 5) | cppVar_64332;
	cppVar_64333 = (cppVar_64333 & cppMask_un_8_);
	cppVar_64335 = (cppVar_64333 == 137);
	if (cppVar_64335) {
	cppVar_64330 = TMOD;
	} else {
	cppVar_64337 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64338 = (cppVar_64337 << 3) | 6;
	cppVar_64338 = (cppVar_64338 & cppMask_un_5_);
	cppVar_64339 = (0 << 5) | cppVar_64338;
	cppVar_64339 = (cppVar_64339 & cppMask_un_8_);
	cppVar_64341 = (cppVar_64339 == 138);
	if (cppVar_64341) {
	cppVar_64336 = TL0;
	} else {
	cppVar_64343 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64344 = (cppVar_64343 << 3) | 6;
	cppVar_64344 = (cppVar_64344 & cppMask_un_5_);
	cppVar_64345 = (0 << 5) | cppVar_64344;
	cppVar_64345 = (cppVar_64345 & cppMask_un_8_);
	cppVar_64347 = (cppVar_64345 == 140);
	if (cppVar_64347) {
	cppVar_64342 = TH0;
	} else {
	cppVar_64349 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64350 = (cppVar_64349 << 3) | 6;
	cppVar_64350 = (cppVar_64350 & cppMask_un_5_);
	cppVar_64351 = (0 << 5) | cppVar_64350;
	cppVar_64351 = (cppVar_64351 & cppMask_un_8_);
	cppVar_64353 = (cppVar_64351 == 139);
	if (cppVar_64353) {
	cppVar_64348 = TL1;
	} else {
	cppVar_64355 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64356 = (cppVar_64355 << 3) | 6;
	cppVar_64356 = (cppVar_64356 & cppMask_un_5_);
	cppVar_64357 = (0 << 5) | cppVar_64356;
	cppVar_64357 = (cppVar_64357 & cppMask_un_8_);
	cppVar_64359 = (cppVar_64357 == 141);
	if (cppVar_64359) {
	cppVar_64354 = TH1;
	} else {
	cppVar_64361 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64362 = (cppVar_64361 << 3) | 6;
	cppVar_64362 = (cppVar_64362 & cppMask_un_5_);
	cppVar_64363 = (0 << 5) | cppVar_64362;
	cppVar_64363 = (cppVar_64363 & cppMask_un_8_);
	cppVar_64365 = (cppVar_64363 == 144);
	if (cppVar_64365) {
	cppVar_64360 = P1;
	} else {
	cppVar_64367 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64368 = (cppVar_64367 << 3) | 6;
	cppVar_64368 = (cppVar_64368 & cppMask_un_5_);
	cppVar_64369 = (0 << 5) | cppVar_64368;
	cppVar_64369 = (cppVar_64369 & cppMask_un_8_);
	cppVar_64371 = (cppVar_64369 == 152);
	if (cppVar_64371) {
	cppVar_64366 = SCON;
	} else {
	cppVar_64373 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64374 = (cppVar_64373 << 3) | 6;
	cppVar_64374 = (cppVar_64374 & cppMask_un_5_);
	cppVar_64375 = (0 << 5) | cppVar_64374;
	cppVar_64375 = (cppVar_64375 & cppMask_un_8_);
	cppVar_64377 = (cppVar_64375 == 153);
	if (cppVar_64377) {
	cppVar_64372 = SBUF;
	} else {
	cppVar_64379 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64380 = (cppVar_64379 << 3) | 6;
	cppVar_64380 = (cppVar_64380 & cppMask_un_5_);
	cppVar_64381 = (0 << 5) | cppVar_64380;
	cppVar_64381 = (cppVar_64381 & cppMask_un_8_);
	cppVar_64383 = (cppVar_64381 == 160);
	if (cppVar_64383) {
	cppVar_64378 = P2;
	} else {
	cppVar_64385 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64386 = (cppVar_64385 << 3) | 6;
	cppVar_64386 = (cppVar_64386 & cppMask_un_5_);
	cppVar_64387 = (0 << 5) | cppVar_64386;
	cppVar_64387 = (cppVar_64387 & cppMask_un_8_);
	cppVar_64389 = (cppVar_64387 == 168);
	if (cppVar_64389) {
	cppVar_64384 = IE;
	} else {
	cppVar_64391 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64392 = (cppVar_64391 << 3) | 6;
	cppVar_64392 = (cppVar_64392 & cppMask_un_5_);
	cppVar_64393 = (0 << 5) | cppVar_64392;
	cppVar_64393 = (cppVar_64393 & cppMask_un_8_);
	cppVar_64395 = (cppVar_64393 == 176);
	if (cppVar_64395) {
	cppVar_64390 = P3;
	} else {
	cppVar_64397 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64398 = (cppVar_64397 << 3) | 6;
	cppVar_64398 = (cppVar_64398 & cppMask_un_5_);
	cppVar_64399 = (0 << 5) | cppVar_64398;
	cppVar_64399 = (cppVar_64399 & cppMask_un_8_);
	cppVar_64401 = (cppVar_64399 == 184);
	if (cppVar_64401) {
	cppVar_64396 = IP;
	} else {
	cppVar_64403 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64404 = (cppVar_64403 << 3) | 6;
	cppVar_64404 = (cppVar_64404 & cppMask_un_5_);
	cppVar_64405 = (0 << 5) | cppVar_64404;
	cppVar_64405 = (cppVar_64405 & cppMask_un_8_);
	cppVar_64407 = (cppVar_64405 == 208);
	if (cppVar_64407) {
	cppVar_64402 = PSW;
	} else {
	cppVar_64409 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64410 = (cppVar_64409 << 3) | 6;
	cppVar_64410 = (cppVar_64410 & cppMask_un_5_);
	cppVar_64411 = (0 << 5) | cppVar_64410;
	cppVar_64411 = (cppVar_64411 & cppMask_un_8_);
	cppVar_64413 = (cppVar_64411 == 224);
	if (cppVar_64413) {
	cppVar_64408 = ACC;
	} else {
	cppVar_64415 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64416 = (cppVar_64415 << 3) | 6;
	cppVar_64416 = (cppVar_64416 & cppMask_un_5_);
	cppVar_64417 = (0 << 5) | cppVar_64416;
	cppVar_64417 = (cppVar_64417 & cppMask_un_8_);
	cppVar_64419 = (cppVar_64417 == 240);
	if (cppVar_64419) {
	cppVar_64414 = B;
	} else {
	cppVar_64414 = 0;
	}
	cppVar_64408 = cppVar_64414;
	}
	cppVar_64402 = cppVar_64408;
	}
	cppVar_64396 = cppVar_64402;
	}
	cppVar_64390 = cppVar_64396;
	}
	cppVar_64384 = cppVar_64390;
	}
	cppVar_64378 = cppVar_64384;
	}
	cppVar_64372 = cppVar_64378;
	}
	cppVar_64366 = cppVar_64372;
	}
	cppVar_64360 = cppVar_64366;
	}
	cppVar_64354 = cppVar_64360;
	}
	cppVar_64348 = cppVar_64354;
	}
	cppVar_64342 = cppVar_64348;
	}
	cppVar_64336 = cppVar_64342;
	}
	cppVar_64330 = cppVar_64336;
	}
	cppVar_64324 = cppVar_64330;
	}
	cppVar_64318 = cppVar_64324;
	}
	cppVar_64312 = cppVar_64318;
	}
	cppVar_64306 = cppVar_64312;
	}
	cppVar_64300 = cppVar_64306;
	}
	cppVar_64294 = cppVar_64300;
	}
	cppVar_64281 = cppVar_64294;
	}
	cppVar_64275 = cppVar_64281;
	} else {
	cppVar_64275 = SP;
	}
	cppVar_64271 = cppVar_64275;
	} else {
	cppVar_64422 = ROM.rd(PC);
	cppVar_64424 = (cppVar_64422 == 141);
	if (cppVar_64424) {
	cppVar_64427 = PC + 1;
	cppVar_64427 = (cppVar_64427 & cppMask_un_16_);
	cppVar_64428 = ROM.rd(cppVar_64427);
	cppVar_64430 = (cppVar_64428 == 129);
	if (cppVar_64430) {
	cppVar_64433 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64435 = (cppVar_64433 << 3) | 5;
	cppVar_64435 = (cppVar_64435 & cppMask_un_5_);
	cppVar_64436 = (0 << 5) | cppVar_64435;
	cppVar_64436 = (cppVar_64436 & cppMask_un_8_);
	cppVar_64437 = (cppVar_64436 >> 7) & cppMask_un_1_;
	cppVar_64439 = (cppVar_64437 == 0);
	if (cppVar_64439) {
	cppVar_64440 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64441 = (cppVar_64440 << 3) | 5;
	cppVar_64441 = (cppVar_64441 & cppMask_un_5_);
	cppVar_64442 = (0 << 5) | cppVar_64441;
	cppVar_64442 = (cppVar_64442 & cppMask_un_8_);
	cppVar_64443 = IRAM.rd(cppVar_64442);
	cppVar_64431 = cppVar_64443;
	} else {
	cppVar_64445 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64446 = (cppVar_64445 << 3) | 5;
	cppVar_64446 = (cppVar_64446 & cppMask_un_5_);
	cppVar_64447 = (0 << 5) | cppVar_64446;
	cppVar_64447 = (cppVar_64447 & cppMask_un_8_);
	cppVar_64449 = (cppVar_64447 == 128);
	if (cppVar_64449) {
	cppVar_64444 = P0;
	} else {
	cppVar_64451 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64452 = (cppVar_64451 << 3) | 5;
	cppVar_64452 = (cppVar_64452 & cppMask_un_5_);
	cppVar_64453 = (0 << 5) | cppVar_64452;
	cppVar_64453 = (cppVar_64453 & cppMask_un_8_);
	cppVar_64455 = (cppVar_64453 == 129);
	if (cppVar_64455) {
	cppVar_64450 = SP;
	} else {
	cppVar_64457 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64458 = (cppVar_64457 << 3) | 5;
	cppVar_64458 = (cppVar_64458 & cppMask_un_5_);
	cppVar_64459 = (0 << 5) | cppVar_64458;
	cppVar_64459 = (cppVar_64459 & cppMask_un_8_);
	cppVar_64461 = (cppVar_64459 == 130);
	if (cppVar_64461) {
	cppVar_64456 = DPL;
	} else {
	cppVar_64463 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64464 = (cppVar_64463 << 3) | 5;
	cppVar_64464 = (cppVar_64464 & cppMask_un_5_);
	cppVar_64465 = (0 << 5) | cppVar_64464;
	cppVar_64465 = (cppVar_64465 & cppMask_un_8_);
	cppVar_64467 = (cppVar_64465 == 131);
	if (cppVar_64467) {
	cppVar_64462 = DPH;
	} else {
	cppVar_64469 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64470 = (cppVar_64469 << 3) | 5;
	cppVar_64470 = (cppVar_64470 & cppMask_un_5_);
	cppVar_64471 = (0 << 5) | cppVar_64470;
	cppVar_64471 = (cppVar_64471 & cppMask_un_8_);
	cppVar_64473 = (cppVar_64471 == 135);
	if (cppVar_64473) {
	cppVar_64468 = PCON;
	} else {
	cppVar_64475 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64476 = (cppVar_64475 << 3) | 5;
	cppVar_64476 = (cppVar_64476 & cppMask_un_5_);
	cppVar_64477 = (0 << 5) | cppVar_64476;
	cppVar_64477 = (cppVar_64477 & cppMask_un_8_);
	cppVar_64479 = (cppVar_64477 == 136);
	if (cppVar_64479) {
	cppVar_64474 = TCON;
	} else {
	cppVar_64481 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64482 = (cppVar_64481 << 3) | 5;
	cppVar_64482 = (cppVar_64482 & cppMask_un_5_);
	cppVar_64483 = (0 << 5) | cppVar_64482;
	cppVar_64483 = (cppVar_64483 & cppMask_un_8_);
	cppVar_64485 = (cppVar_64483 == 137);
	if (cppVar_64485) {
	cppVar_64480 = TMOD;
	} else {
	cppVar_64487 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64488 = (cppVar_64487 << 3) | 5;
	cppVar_64488 = (cppVar_64488 & cppMask_un_5_);
	cppVar_64489 = (0 << 5) | cppVar_64488;
	cppVar_64489 = (cppVar_64489 & cppMask_un_8_);
	cppVar_64491 = (cppVar_64489 == 138);
	if (cppVar_64491) {
	cppVar_64486 = TL0;
	} else {
	cppVar_64493 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64494 = (cppVar_64493 << 3) | 5;
	cppVar_64494 = (cppVar_64494 & cppMask_un_5_);
	cppVar_64495 = (0 << 5) | cppVar_64494;
	cppVar_64495 = (cppVar_64495 & cppMask_un_8_);
	cppVar_64497 = (cppVar_64495 == 140);
	if (cppVar_64497) {
	cppVar_64492 = TH0;
	} else {
	cppVar_64499 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64500 = (cppVar_64499 << 3) | 5;
	cppVar_64500 = (cppVar_64500 & cppMask_un_5_);
	cppVar_64501 = (0 << 5) | cppVar_64500;
	cppVar_64501 = (cppVar_64501 & cppMask_un_8_);
	cppVar_64503 = (cppVar_64501 == 139);
	if (cppVar_64503) {
	cppVar_64498 = TL1;
	} else {
	cppVar_64505 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64506 = (cppVar_64505 << 3) | 5;
	cppVar_64506 = (cppVar_64506 & cppMask_un_5_);
	cppVar_64507 = (0 << 5) | cppVar_64506;
	cppVar_64507 = (cppVar_64507 & cppMask_un_8_);
	cppVar_64509 = (cppVar_64507 == 141);
	if (cppVar_64509) {
	cppVar_64504 = TH1;
	} else {
	cppVar_64511 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64512 = (cppVar_64511 << 3) | 5;
	cppVar_64512 = (cppVar_64512 & cppMask_un_5_);
	cppVar_64513 = (0 << 5) | cppVar_64512;
	cppVar_64513 = (cppVar_64513 & cppMask_un_8_);
	cppVar_64515 = (cppVar_64513 == 144);
	if (cppVar_64515) {
	cppVar_64510 = P1;
	} else {
	cppVar_64517 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64518 = (cppVar_64517 << 3) | 5;
	cppVar_64518 = (cppVar_64518 & cppMask_un_5_);
	cppVar_64519 = (0 << 5) | cppVar_64518;
	cppVar_64519 = (cppVar_64519 & cppMask_un_8_);
	cppVar_64521 = (cppVar_64519 == 152);
	if (cppVar_64521) {
	cppVar_64516 = SCON;
	} else {
	cppVar_64523 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64524 = (cppVar_64523 << 3) | 5;
	cppVar_64524 = (cppVar_64524 & cppMask_un_5_);
	cppVar_64525 = (0 << 5) | cppVar_64524;
	cppVar_64525 = (cppVar_64525 & cppMask_un_8_);
	cppVar_64527 = (cppVar_64525 == 153);
	if (cppVar_64527) {
	cppVar_64522 = SBUF;
	} else {
	cppVar_64529 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64530 = (cppVar_64529 << 3) | 5;
	cppVar_64530 = (cppVar_64530 & cppMask_un_5_);
	cppVar_64531 = (0 << 5) | cppVar_64530;
	cppVar_64531 = (cppVar_64531 & cppMask_un_8_);
	cppVar_64533 = (cppVar_64531 == 160);
	if (cppVar_64533) {
	cppVar_64528 = P2;
	} else {
	cppVar_64535 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64536 = (cppVar_64535 << 3) | 5;
	cppVar_64536 = (cppVar_64536 & cppMask_un_5_);
	cppVar_64537 = (0 << 5) | cppVar_64536;
	cppVar_64537 = (cppVar_64537 & cppMask_un_8_);
	cppVar_64539 = (cppVar_64537 == 168);
	if (cppVar_64539) {
	cppVar_64534 = IE;
	} else {
	cppVar_64541 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64542 = (cppVar_64541 << 3) | 5;
	cppVar_64542 = (cppVar_64542 & cppMask_un_5_);
	cppVar_64543 = (0 << 5) | cppVar_64542;
	cppVar_64543 = (cppVar_64543 & cppMask_un_8_);
	cppVar_64545 = (cppVar_64543 == 176);
	if (cppVar_64545) {
	cppVar_64540 = P3;
	} else {
	cppVar_64547 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64548 = (cppVar_64547 << 3) | 5;
	cppVar_64548 = (cppVar_64548 & cppMask_un_5_);
	cppVar_64549 = (0 << 5) | cppVar_64548;
	cppVar_64549 = (cppVar_64549 & cppMask_un_8_);
	cppVar_64551 = (cppVar_64549 == 184);
	if (cppVar_64551) {
	cppVar_64546 = IP;
	} else {
	cppVar_64553 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64554 = (cppVar_64553 << 3) | 5;
	cppVar_64554 = (cppVar_64554 & cppMask_un_5_);
	cppVar_64555 = (0 << 5) | cppVar_64554;
	cppVar_64555 = (cppVar_64555 & cppMask_un_8_);
	cppVar_64557 = (cppVar_64555 == 208);
	if (cppVar_64557) {
	cppVar_64552 = PSW;
	} else {
	cppVar_64559 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64560 = (cppVar_64559 << 3) | 5;
	cppVar_64560 = (cppVar_64560 & cppMask_un_5_);
	cppVar_64561 = (0 << 5) | cppVar_64560;
	cppVar_64561 = (cppVar_64561 & cppMask_un_8_);
	cppVar_64563 = (cppVar_64561 == 224);
	if (cppVar_64563) {
	cppVar_64558 = ACC;
	} else {
	cppVar_64565 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64566 = (cppVar_64565 << 3) | 5;
	cppVar_64566 = (cppVar_64566 & cppMask_un_5_);
	cppVar_64567 = (0 << 5) | cppVar_64566;
	cppVar_64567 = (cppVar_64567 & cppMask_un_8_);
	cppVar_64569 = (cppVar_64567 == 240);
	if (cppVar_64569) {
	cppVar_64564 = B;
	} else {
	cppVar_64564 = 0;
	}
	cppVar_64558 = cppVar_64564;
	}
	cppVar_64552 = cppVar_64558;
	}
	cppVar_64546 = cppVar_64552;
	}
	cppVar_64540 = cppVar_64546;
	}
	cppVar_64534 = cppVar_64540;
	}
	cppVar_64528 = cppVar_64534;
	}
	cppVar_64522 = cppVar_64528;
	}
	cppVar_64516 = cppVar_64522;
	}
	cppVar_64510 = cppVar_64516;
	}
	cppVar_64504 = cppVar_64510;
	}
	cppVar_64498 = cppVar_64504;
	}
	cppVar_64492 = cppVar_64498;
	}
	cppVar_64486 = cppVar_64492;
	}
	cppVar_64480 = cppVar_64486;
	}
	cppVar_64474 = cppVar_64480;
	}
	cppVar_64468 = cppVar_64474;
	}
	cppVar_64462 = cppVar_64468;
	}
	cppVar_64456 = cppVar_64462;
	}
	cppVar_64450 = cppVar_64456;
	}
	cppVar_64444 = cppVar_64450;
	}
	cppVar_64431 = cppVar_64444;
	}
	cppVar_64425 = cppVar_64431;
	} else {
	cppVar_64425 = SP;
	}
	cppVar_64421 = cppVar_64425;
	} else {
	cppVar_64572 = ROM.rd(PC);
	cppVar_64574 = (cppVar_64572 == 140);
	if (cppVar_64574) {
	cppVar_64577 = PC + 1;
	cppVar_64577 = (cppVar_64577 & cppMask_un_16_);
	cppVar_64578 = ROM.rd(cppVar_64577);
	cppVar_64580 = (cppVar_64578 == 129);
	if (cppVar_64580) {
	cppVar_64583 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64585 = (cppVar_64583 << 3) | 4;
	cppVar_64585 = (cppVar_64585 & cppMask_un_5_);
	cppVar_64586 = (0 << 5) | cppVar_64585;
	cppVar_64586 = (cppVar_64586 & cppMask_un_8_);
	cppVar_64587 = (cppVar_64586 >> 7) & cppMask_un_1_;
	cppVar_64589 = (cppVar_64587 == 0);
	if (cppVar_64589) {
	cppVar_64590 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64591 = (cppVar_64590 << 3) | 4;
	cppVar_64591 = (cppVar_64591 & cppMask_un_5_);
	cppVar_64592 = (0 << 5) | cppVar_64591;
	cppVar_64592 = (cppVar_64592 & cppMask_un_8_);
	cppVar_64593 = IRAM.rd(cppVar_64592);
	cppVar_64581 = cppVar_64593;
	} else {
	cppVar_64595 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64596 = (cppVar_64595 << 3) | 4;
	cppVar_64596 = (cppVar_64596 & cppMask_un_5_);
	cppVar_64597 = (0 << 5) | cppVar_64596;
	cppVar_64597 = (cppVar_64597 & cppMask_un_8_);
	cppVar_64599 = (cppVar_64597 == 128);
	if (cppVar_64599) {
	cppVar_64594 = P0;
	} else {
	cppVar_64601 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64602 = (cppVar_64601 << 3) | 4;
	cppVar_64602 = (cppVar_64602 & cppMask_un_5_);
	cppVar_64603 = (0 << 5) | cppVar_64602;
	cppVar_64603 = (cppVar_64603 & cppMask_un_8_);
	cppVar_64605 = (cppVar_64603 == 129);
	if (cppVar_64605) {
	cppVar_64600 = SP;
	} else {
	cppVar_64607 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64608 = (cppVar_64607 << 3) | 4;
	cppVar_64608 = (cppVar_64608 & cppMask_un_5_);
	cppVar_64609 = (0 << 5) | cppVar_64608;
	cppVar_64609 = (cppVar_64609 & cppMask_un_8_);
	cppVar_64611 = (cppVar_64609 == 130);
	if (cppVar_64611) {
	cppVar_64606 = DPL;
	} else {
	cppVar_64613 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64614 = (cppVar_64613 << 3) | 4;
	cppVar_64614 = (cppVar_64614 & cppMask_un_5_);
	cppVar_64615 = (0 << 5) | cppVar_64614;
	cppVar_64615 = (cppVar_64615 & cppMask_un_8_);
	cppVar_64617 = (cppVar_64615 == 131);
	if (cppVar_64617) {
	cppVar_64612 = DPH;
	} else {
	cppVar_64619 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64620 = (cppVar_64619 << 3) | 4;
	cppVar_64620 = (cppVar_64620 & cppMask_un_5_);
	cppVar_64621 = (0 << 5) | cppVar_64620;
	cppVar_64621 = (cppVar_64621 & cppMask_un_8_);
	cppVar_64623 = (cppVar_64621 == 135);
	if (cppVar_64623) {
	cppVar_64618 = PCON;
	} else {
	cppVar_64625 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64626 = (cppVar_64625 << 3) | 4;
	cppVar_64626 = (cppVar_64626 & cppMask_un_5_);
	cppVar_64627 = (0 << 5) | cppVar_64626;
	cppVar_64627 = (cppVar_64627 & cppMask_un_8_);
	cppVar_64629 = (cppVar_64627 == 136);
	if (cppVar_64629) {
	cppVar_64624 = TCON;
	} else {
	cppVar_64631 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64632 = (cppVar_64631 << 3) | 4;
	cppVar_64632 = (cppVar_64632 & cppMask_un_5_);
	cppVar_64633 = (0 << 5) | cppVar_64632;
	cppVar_64633 = (cppVar_64633 & cppMask_un_8_);
	cppVar_64635 = (cppVar_64633 == 137);
	if (cppVar_64635) {
	cppVar_64630 = TMOD;
	} else {
	cppVar_64637 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64638 = (cppVar_64637 << 3) | 4;
	cppVar_64638 = (cppVar_64638 & cppMask_un_5_);
	cppVar_64639 = (0 << 5) | cppVar_64638;
	cppVar_64639 = (cppVar_64639 & cppMask_un_8_);
	cppVar_64641 = (cppVar_64639 == 138);
	if (cppVar_64641) {
	cppVar_64636 = TL0;
	} else {
	cppVar_64643 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64644 = (cppVar_64643 << 3) | 4;
	cppVar_64644 = (cppVar_64644 & cppMask_un_5_);
	cppVar_64645 = (0 << 5) | cppVar_64644;
	cppVar_64645 = (cppVar_64645 & cppMask_un_8_);
	cppVar_64647 = (cppVar_64645 == 140);
	if (cppVar_64647) {
	cppVar_64642 = TH0;
	} else {
	cppVar_64649 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64650 = (cppVar_64649 << 3) | 4;
	cppVar_64650 = (cppVar_64650 & cppMask_un_5_);
	cppVar_64651 = (0 << 5) | cppVar_64650;
	cppVar_64651 = (cppVar_64651 & cppMask_un_8_);
	cppVar_64653 = (cppVar_64651 == 139);
	if (cppVar_64653) {
	cppVar_64648 = TL1;
	} else {
	cppVar_64655 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64656 = (cppVar_64655 << 3) | 4;
	cppVar_64656 = (cppVar_64656 & cppMask_un_5_);
	cppVar_64657 = (0 << 5) | cppVar_64656;
	cppVar_64657 = (cppVar_64657 & cppMask_un_8_);
	cppVar_64659 = (cppVar_64657 == 141);
	if (cppVar_64659) {
	cppVar_64654 = TH1;
	} else {
	cppVar_64661 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64662 = (cppVar_64661 << 3) | 4;
	cppVar_64662 = (cppVar_64662 & cppMask_un_5_);
	cppVar_64663 = (0 << 5) | cppVar_64662;
	cppVar_64663 = (cppVar_64663 & cppMask_un_8_);
	cppVar_64665 = (cppVar_64663 == 144);
	if (cppVar_64665) {
	cppVar_64660 = P1;
	} else {
	cppVar_64667 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64668 = (cppVar_64667 << 3) | 4;
	cppVar_64668 = (cppVar_64668 & cppMask_un_5_);
	cppVar_64669 = (0 << 5) | cppVar_64668;
	cppVar_64669 = (cppVar_64669 & cppMask_un_8_);
	cppVar_64671 = (cppVar_64669 == 152);
	if (cppVar_64671) {
	cppVar_64666 = SCON;
	} else {
	cppVar_64673 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64674 = (cppVar_64673 << 3) | 4;
	cppVar_64674 = (cppVar_64674 & cppMask_un_5_);
	cppVar_64675 = (0 << 5) | cppVar_64674;
	cppVar_64675 = (cppVar_64675 & cppMask_un_8_);
	cppVar_64677 = (cppVar_64675 == 153);
	if (cppVar_64677) {
	cppVar_64672 = SBUF;
	} else {
	cppVar_64679 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64680 = (cppVar_64679 << 3) | 4;
	cppVar_64680 = (cppVar_64680 & cppMask_un_5_);
	cppVar_64681 = (0 << 5) | cppVar_64680;
	cppVar_64681 = (cppVar_64681 & cppMask_un_8_);
	cppVar_64683 = (cppVar_64681 == 160);
	if (cppVar_64683) {
	cppVar_64678 = P2;
	} else {
	cppVar_64685 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64686 = (cppVar_64685 << 3) | 4;
	cppVar_64686 = (cppVar_64686 & cppMask_un_5_);
	cppVar_64687 = (0 << 5) | cppVar_64686;
	cppVar_64687 = (cppVar_64687 & cppMask_un_8_);
	cppVar_64689 = (cppVar_64687 == 168);
	if (cppVar_64689) {
	cppVar_64684 = IE;
	} else {
	cppVar_64691 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64692 = (cppVar_64691 << 3) | 4;
	cppVar_64692 = (cppVar_64692 & cppMask_un_5_);
	cppVar_64693 = (0 << 5) | cppVar_64692;
	cppVar_64693 = (cppVar_64693 & cppMask_un_8_);
	cppVar_64695 = (cppVar_64693 == 176);
	if (cppVar_64695) {
	cppVar_64690 = P3;
	} else {
	cppVar_64697 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64698 = (cppVar_64697 << 3) | 4;
	cppVar_64698 = (cppVar_64698 & cppMask_un_5_);
	cppVar_64699 = (0 << 5) | cppVar_64698;
	cppVar_64699 = (cppVar_64699 & cppMask_un_8_);
	cppVar_64701 = (cppVar_64699 == 184);
	if (cppVar_64701) {
	cppVar_64696 = IP;
	} else {
	cppVar_64703 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64704 = (cppVar_64703 << 3) | 4;
	cppVar_64704 = (cppVar_64704 & cppMask_un_5_);
	cppVar_64705 = (0 << 5) | cppVar_64704;
	cppVar_64705 = (cppVar_64705 & cppMask_un_8_);
	cppVar_64707 = (cppVar_64705 == 208);
	if (cppVar_64707) {
	cppVar_64702 = PSW;
	} else {
	cppVar_64709 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64710 = (cppVar_64709 << 3) | 4;
	cppVar_64710 = (cppVar_64710 & cppMask_un_5_);
	cppVar_64711 = (0 << 5) | cppVar_64710;
	cppVar_64711 = (cppVar_64711 & cppMask_un_8_);
	cppVar_64713 = (cppVar_64711 == 224);
	if (cppVar_64713) {
	cppVar_64708 = ACC;
	} else {
	cppVar_64715 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64716 = (cppVar_64715 << 3) | 4;
	cppVar_64716 = (cppVar_64716 & cppMask_un_5_);
	cppVar_64717 = (0 << 5) | cppVar_64716;
	cppVar_64717 = (cppVar_64717 & cppMask_un_8_);
	cppVar_64719 = (cppVar_64717 == 240);
	if (cppVar_64719) {
	cppVar_64714 = B;
	} else {
	cppVar_64714 = 0;
	}
	cppVar_64708 = cppVar_64714;
	}
	cppVar_64702 = cppVar_64708;
	}
	cppVar_64696 = cppVar_64702;
	}
	cppVar_64690 = cppVar_64696;
	}
	cppVar_64684 = cppVar_64690;
	}
	cppVar_64678 = cppVar_64684;
	}
	cppVar_64672 = cppVar_64678;
	}
	cppVar_64666 = cppVar_64672;
	}
	cppVar_64660 = cppVar_64666;
	}
	cppVar_64654 = cppVar_64660;
	}
	cppVar_64648 = cppVar_64654;
	}
	cppVar_64642 = cppVar_64648;
	}
	cppVar_64636 = cppVar_64642;
	}
	cppVar_64630 = cppVar_64636;
	}
	cppVar_64624 = cppVar_64630;
	}
	cppVar_64618 = cppVar_64624;
	}
	cppVar_64612 = cppVar_64618;
	}
	cppVar_64606 = cppVar_64612;
	}
	cppVar_64600 = cppVar_64606;
	}
	cppVar_64594 = cppVar_64600;
	}
	cppVar_64581 = cppVar_64594;
	}
	cppVar_64575 = cppVar_64581;
	} else {
	cppVar_64575 = SP;
	}
	cppVar_64571 = cppVar_64575;
	} else {
	cppVar_64722 = ROM.rd(PC);
	cppVar_64724 = (cppVar_64722 == 139);
	if (cppVar_64724) {
	cppVar_64727 = PC + 1;
	cppVar_64727 = (cppVar_64727 & cppMask_un_16_);
	cppVar_64728 = ROM.rd(cppVar_64727);
	cppVar_64730 = (cppVar_64728 == 129);
	if (cppVar_64730) {
	cppVar_64733 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64735 = (cppVar_64733 << 3) | 3;
	cppVar_64735 = (cppVar_64735 & cppMask_un_5_);
	cppVar_64736 = (0 << 5) | cppVar_64735;
	cppVar_64736 = (cppVar_64736 & cppMask_un_8_);
	cppVar_64737 = (cppVar_64736 >> 7) & cppMask_un_1_;
	cppVar_64739 = (cppVar_64737 == 0);
	if (cppVar_64739) {
	cppVar_64740 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64741 = (cppVar_64740 << 3) | 3;
	cppVar_64741 = (cppVar_64741 & cppMask_un_5_);
	cppVar_64742 = (0 << 5) | cppVar_64741;
	cppVar_64742 = (cppVar_64742 & cppMask_un_8_);
	cppVar_64743 = IRAM.rd(cppVar_64742);
	cppVar_64731 = cppVar_64743;
	} else {
	cppVar_64745 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64746 = (cppVar_64745 << 3) | 3;
	cppVar_64746 = (cppVar_64746 & cppMask_un_5_);
	cppVar_64747 = (0 << 5) | cppVar_64746;
	cppVar_64747 = (cppVar_64747 & cppMask_un_8_);
	cppVar_64749 = (cppVar_64747 == 128);
	if (cppVar_64749) {
	cppVar_64744 = P0;
	} else {
	cppVar_64751 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64752 = (cppVar_64751 << 3) | 3;
	cppVar_64752 = (cppVar_64752 & cppMask_un_5_);
	cppVar_64753 = (0 << 5) | cppVar_64752;
	cppVar_64753 = (cppVar_64753 & cppMask_un_8_);
	cppVar_64755 = (cppVar_64753 == 129);
	if (cppVar_64755) {
	cppVar_64750 = SP;
	} else {
	cppVar_64757 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64758 = (cppVar_64757 << 3) | 3;
	cppVar_64758 = (cppVar_64758 & cppMask_un_5_);
	cppVar_64759 = (0 << 5) | cppVar_64758;
	cppVar_64759 = (cppVar_64759 & cppMask_un_8_);
	cppVar_64761 = (cppVar_64759 == 130);
	if (cppVar_64761) {
	cppVar_64756 = DPL;
	} else {
	cppVar_64763 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64764 = (cppVar_64763 << 3) | 3;
	cppVar_64764 = (cppVar_64764 & cppMask_un_5_);
	cppVar_64765 = (0 << 5) | cppVar_64764;
	cppVar_64765 = (cppVar_64765 & cppMask_un_8_);
	cppVar_64767 = (cppVar_64765 == 131);
	if (cppVar_64767) {
	cppVar_64762 = DPH;
	} else {
	cppVar_64769 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64770 = (cppVar_64769 << 3) | 3;
	cppVar_64770 = (cppVar_64770 & cppMask_un_5_);
	cppVar_64771 = (0 << 5) | cppVar_64770;
	cppVar_64771 = (cppVar_64771 & cppMask_un_8_);
	cppVar_64773 = (cppVar_64771 == 135);
	if (cppVar_64773) {
	cppVar_64768 = PCON;
	} else {
	cppVar_64775 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64776 = (cppVar_64775 << 3) | 3;
	cppVar_64776 = (cppVar_64776 & cppMask_un_5_);
	cppVar_64777 = (0 << 5) | cppVar_64776;
	cppVar_64777 = (cppVar_64777 & cppMask_un_8_);
	cppVar_64779 = (cppVar_64777 == 136);
	if (cppVar_64779) {
	cppVar_64774 = TCON;
	} else {
	cppVar_64781 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64782 = (cppVar_64781 << 3) | 3;
	cppVar_64782 = (cppVar_64782 & cppMask_un_5_);
	cppVar_64783 = (0 << 5) | cppVar_64782;
	cppVar_64783 = (cppVar_64783 & cppMask_un_8_);
	cppVar_64785 = (cppVar_64783 == 137);
	if (cppVar_64785) {
	cppVar_64780 = TMOD;
	} else {
	cppVar_64787 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64788 = (cppVar_64787 << 3) | 3;
	cppVar_64788 = (cppVar_64788 & cppMask_un_5_);
	cppVar_64789 = (0 << 5) | cppVar_64788;
	cppVar_64789 = (cppVar_64789 & cppMask_un_8_);
	cppVar_64791 = (cppVar_64789 == 138);
	if (cppVar_64791) {
	cppVar_64786 = TL0;
	} else {
	cppVar_64793 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64794 = (cppVar_64793 << 3) | 3;
	cppVar_64794 = (cppVar_64794 & cppMask_un_5_);
	cppVar_64795 = (0 << 5) | cppVar_64794;
	cppVar_64795 = (cppVar_64795 & cppMask_un_8_);
	cppVar_64797 = (cppVar_64795 == 140);
	if (cppVar_64797) {
	cppVar_64792 = TH0;
	} else {
	cppVar_64799 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64800 = (cppVar_64799 << 3) | 3;
	cppVar_64800 = (cppVar_64800 & cppMask_un_5_);
	cppVar_64801 = (0 << 5) | cppVar_64800;
	cppVar_64801 = (cppVar_64801 & cppMask_un_8_);
	cppVar_64803 = (cppVar_64801 == 139);
	if (cppVar_64803) {
	cppVar_64798 = TL1;
	} else {
	cppVar_64805 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64806 = (cppVar_64805 << 3) | 3;
	cppVar_64806 = (cppVar_64806 & cppMask_un_5_);
	cppVar_64807 = (0 << 5) | cppVar_64806;
	cppVar_64807 = (cppVar_64807 & cppMask_un_8_);
	cppVar_64809 = (cppVar_64807 == 141);
	if (cppVar_64809) {
	cppVar_64804 = TH1;
	} else {
	cppVar_64811 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64812 = (cppVar_64811 << 3) | 3;
	cppVar_64812 = (cppVar_64812 & cppMask_un_5_);
	cppVar_64813 = (0 << 5) | cppVar_64812;
	cppVar_64813 = (cppVar_64813 & cppMask_un_8_);
	cppVar_64815 = (cppVar_64813 == 144);
	if (cppVar_64815) {
	cppVar_64810 = P1;
	} else {
	cppVar_64817 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64818 = (cppVar_64817 << 3) | 3;
	cppVar_64818 = (cppVar_64818 & cppMask_un_5_);
	cppVar_64819 = (0 << 5) | cppVar_64818;
	cppVar_64819 = (cppVar_64819 & cppMask_un_8_);
	cppVar_64821 = (cppVar_64819 == 152);
	if (cppVar_64821) {
	cppVar_64816 = SCON;
	} else {
	cppVar_64823 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64824 = (cppVar_64823 << 3) | 3;
	cppVar_64824 = (cppVar_64824 & cppMask_un_5_);
	cppVar_64825 = (0 << 5) | cppVar_64824;
	cppVar_64825 = (cppVar_64825 & cppMask_un_8_);
	cppVar_64827 = (cppVar_64825 == 153);
	if (cppVar_64827) {
	cppVar_64822 = SBUF;
	} else {
	cppVar_64829 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64830 = (cppVar_64829 << 3) | 3;
	cppVar_64830 = (cppVar_64830 & cppMask_un_5_);
	cppVar_64831 = (0 << 5) | cppVar_64830;
	cppVar_64831 = (cppVar_64831 & cppMask_un_8_);
	cppVar_64833 = (cppVar_64831 == 160);
	if (cppVar_64833) {
	cppVar_64828 = P2;
	} else {
	cppVar_64835 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64836 = (cppVar_64835 << 3) | 3;
	cppVar_64836 = (cppVar_64836 & cppMask_un_5_);
	cppVar_64837 = (0 << 5) | cppVar_64836;
	cppVar_64837 = (cppVar_64837 & cppMask_un_8_);
	cppVar_64839 = (cppVar_64837 == 168);
	if (cppVar_64839) {
	cppVar_64834 = IE;
	} else {
	cppVar_64841 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64842 = (cppVar_64841 << 3) | 3;
	cppVar_64842 = (cppVar_64842 & cppMask_un_5_);
	cppVar_64843 = (0 << 5) | cppVar_64842;
	cppVar_64843 = (cppVar_64843 & cppMask_un_8_);
	cppVar_64845 = (cppVar_64843 == 176);
	if (cppVar_64845) {
	cppVar_64840 = P3;
	} else {
	cppVar_64847 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64848 = (cppVar_64847 << 3) | 3;
	cppVar_64848 = (cppVar_64848 & cppMask_un_5_);
	cppVar_64849 = (0 << 5) | cppVar_64848;
	cppVar_64849 = (cppVar_64849 & cppMask_un_8_);
	cppVar_64851 = (cppVar_64849 == 184);
	if (cppVar_64851) {
	cppVar_64846 = IP;
	} else {
	cppVar_64853 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64854 = (cppVar_64853 << 3) | 3;
	cppVar_64854 = (cppVar_64854 & cppMask_un_5_);
	cppVar_64855 = (0 << 5) | cppVar_64854;
	cppVar_64855 = (cppVar_64855 & cppMask_un_8_);
	cppVar_64857 = (cppVar_64855 == 208);
	if (cppVar_64857) {
	cppVar_64852 = PSW;
	} else {
	cppVar_64859 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64860 = (cppVar_64859 << 3) | 3;
	cppVar_64860 = (cppVar_64860 & cppMask_un_5_);
	cppVar_64861 = (0 << 5) | cppVar_64860;
	cppVar_64861 = (cppVar_64861 & cppMask_un_8_);
	cppVar_64863 = (cppVar_64861 == 224);
	if (cppVar_64863) {
	cppVar_64858 = ACC;
	} else {
	cppVar_64865 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64866 = (cppVar_64865 << 3) | 3;
	cppVar_64866 = (cppVar_64866 & cppMask_un_5_);
	cppVar_64867 = (0 << 5) | cppVar_64866;
	cppVar_64867 = (cppVar_64867 & cppMask_un_8_);
	cppVar_64869 = (cppVar_64867 == 240);
	if (cppVar_64869) {
	cppVar_64864 = B;
	} else {
	cppVar_64864 = 0;
	}
	cppVar_64858 = cppVar_64864;
	}
	cppVar_64852 = cppVar_64858;
	}
	cppVar_64846 = cppVar_64852;
	}
	cppVar_64840 = cppVar_64846;
	}
	cppVar_64834 = cppVar_64840;
	}
	cppVar_64828 = cppVar_64834;
	}
	cppVar_64822 = cppVar_64828;
	}
	cppVar_64816 = cppVar_64822;
	}
	cppVar_64810 = cppVar_64816;
	}
	cppVar_64804 = cppVar_64810;
	}
	cppVar_64798 = cppVar_64804;
	}
	cppVar_64792 = cppVar_64798;
	}
	cppVar_64786 = cppVar_64792;
	}
	cppVar_64780 = cppVar_64786;
	}
	cppVar_64774 = cppVar_64780;
	}
	cppVar_64768 = cppVar_64774;
	}
	cppVar_64762 = cppVar_64768;
	}
	cppVar_64756 = cppVar_64762;
	}
	cppVar_64750 = cppVar_64756;
	}
	cppVar_64744 = cppVar_64750;
	}
	cppVar_64731 = cppVar_64744;
	}
	cppVar_64725 = cppVar_64731;
	} else {
	cppVar_64725 = SP;
	}
	cppVar_64721 = cppVar_64725;
	} else {
	cppVar_64872 = ROM.rd(PC);
	cppVar_64874 = (cppVar_64872 == 138);
	if (cppVar_64874) {
	cppVar_64877 = PC + 1;
	cppVar_64877 = (cppVar_64877 & cppMask_un_16_);
	cppVar_64878 = ROM.rd(cppVar_64877);
	cppVar_64880 = (cppVar_64878 == 129);
	if (cppVar_64880) {
	cppVar_64883 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64885 = (cppVar_64883 << 3) | 2;
	cppVar_64885 = (cppVar_64885 & cppMask_un_5_);
	cppVar_64886 = (0 << 5) | cppVar_64885;
	cppVar_64886 = (cppVar_64886 & cppMask_un_8_);
	cppVar_64887 = (cppVar_64886 >> 7) & cppMask_un_1_;
	cppVar_64889 = (cppVar_64887 == 0);
	if (cppVar_64889) {
	cppVar_64890 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64891 = (cppVar_64890 << 3) | 2;
	cppVar_64891 = (cppVar_64891 & cppMask_un_5_);
	cppVar_64892 = (0 << 5) | cppVar_64891;
	cppVar_64892 = (cppVar_64892 & cppMask_un_8_);
	cppVar_64893 = IRAM.rd(cppVar_64892);
	cppVar_64881 = cppVar_64893;
	} else {
	cppVar_64895 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64896 = (cppVar_64895 << 3) | 2;
	cppVar_64896 = (cppVar_64896 & cppMask_un_5_);
	cppVar_64897 = (0 << 5) | cppVar_64896;
	cppVar_64897 = (cppVar_64897 & cppMask_un_8_);
	cppVar_64899 = (cppVar_64897 == 128);
	if (cppVar_64899) {
	cppVar_64894 = P0;
	} else {
	cppVar_64901 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64902 = (cppVar_64901 << 3) | 2;
	cppVar_64902 = (cppVar_64902 & cppMask_un_5_);
	cppVar_64903 = (0 << 5) | cppVar_64902;
	cppVar_64903 = (cppVar_64903 & cppMask_un_8_);
	cppVar_64905 = (cppVar_64903 == 129);
	if (cppVar_64905) {
	cppVar_64900 = SP;
	} else {
	cppVar_64907 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64908 = (cppVar_64907 << 3) | 2;
	cppVar_64908 = (cppVar_64908 & cppMask_un_5_);
	cppVar_64909 = (0 << 5) | cppVar_64908;
	cppVar_64909 = (cppVar_64909 & cppMask_un_8_);
	cppVar_64911 = (cppVar_64909 == 130);
	if (cppVar_64911) {
	cppVar_64906 = DPL;
	} else {
	cppVar_64913 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64914 = (cppVar_64913 << 3) | 2;
	cppVar_64914 = (cppVar_64914 & cppMask_un_5_);
	cppVar_64915 = (0 << 5) | cppVar_64914;
	cppVar_64915 = (cppVar_64915 & cppMask_un_8_);
	cppVar_64917 = (cppVar_64915 == 131);
	if (cppVar_64917) {
	cppVar_64912 = DPH;
	} else {
	cppVar_64919 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64920 = (cppVar_64919 << 3) | 2;
	cppVar_64920 = (cppVar_64920 & cppMask_un_5_);
	cppVar_64921 = (0 << 5) | cppVar_64920;
	cppVar_64921 = (cppVar_64921 & cppMask_un_8_);
	cppVar_64923 = (cppVar_64921 == 135);
	if (cppVar_64923) {
	cppVar_64918 = PCON;
	} else {
	cppVar_64925 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64926 = (cppVar_64925 << 3) | 2;
	cppVar_64926 = (cppVar_64926 & cppMask_un_5_);
	cppVar_64927 = (0 << 5) | cppVar_64926;
	cppVar_64927 = (cppVar_64927 & cppMask_un_8_);
	cppVar_64929 = (cppVar_64927 == 136);
	if (cppVar_64929) {
	cppVar_64924 = TCON;
	} else {
	cppVar_64931 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64932 = (cppVar_64931 << 3) | 2;
	cppVar_64932 = (cppVar_64932 & cppMask_un_5_);
	cppVar_64933 = (0 << 5) | cppVar_64932;
	cppVar_64933 = (cppVar_64933 & cppMask_un_8_);
	cppVar_64935 = (cppVar_64933 == 137);
	if (cppVar_64935) {
	cppVar_64930 = TMOD;
	} else {
	cppVar_64937 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64938 = (cppVar_64937 << 3) | 2;
	cppVar_64938 = (cppVar_64938 & cppMask_un_5_);
	cppVar_64939 = (0 << 5) | cppVar_64938;
	cppVar_64939 = (cppVar_64939 & cppMask_un_8_);
	cppVar_64941 = (cppVar_64939 == 138);
	if (cppVar_64941) {
	cppVar_64936 = TL0;
	} else {
	cppVar_64943 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64944 = (cppVar_64943 << 3) | 2;
	cppVar_64944 = (cppVar_64944 & cppMask_un_5_);
	cppVar_64945 = (0 << 5) | cppVar_64944;
	cppVar_64945 = (cppVar_64945 & cppMask_un_8_);
	cppVar_64947 = (cppVar_64945 == 140);
	if (cppVar_64947) {
	cppVar_64942 = TH0;
	} else {
	cppVar_64949 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64950 = (cppVar_64949 << 3) | 2;
	cppVar_64950 = (cppVar_64950 & cppMask_un_5_);
	cppVar_64951 = (0 << 5) | cppVar_64950;
	cppVar_64951 = (cppVar_64951 & cppMask_un_8_);
	cppVar_64953 = (cppVar_64951 == 139);
	if (cppVar_64953) {
	cppVar_64948 = TL1;
	} else {
	cppVar_64955 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64956 = (cppVar_64955 << 3) | 2;
	cppVar_64956 = (cppVar_64956 & cppMask_un_5_);
	cppVar_64957 = (0 << 5) | cppVar_64956;
	cppVar_64957 = (cppVar_64957 & cppMask_un_8_);
	cppVar_64959 = (cppVar_64957 == 141);
	if (cppVar_64959) {
	cppVar_64954 = TH1;
	} else {
	cppVar_64961 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64962 = (cppVar_64961 << 3) | 2;
	cppVar_64962 = (cppVar_64962 & cppMask_un_5_);
	cppVar_64963 = (0 << 5) | cppVar_64962;
	cppVar_64963 = (cppVar_64963 & cppMask_un_8_);
	cppVar_64965 = (cppVar_64963 == 144);
	if (cppVar_64965) {
	cppVar_64960 = P1;
	} else {
	cppVar_64967 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64968 = (cppVar_64967 << 3) | 2;
	cppVar_64968 = (cppVar_64968 & cppMask_un_5_);
	cppVar_64969 = (0 << 5) | cppVar_64968;
	cppVar_64969 = (cppVar_64969 & cppMask_un_8_);
	cppVar_64971 = (cppVar_64969 == 152);
	if (cppVar_64971) {
	cppVar_64966 = SCON;
	} else {
	cppVar_64973 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64974 = (cppVar_64973 << 3) | 2;
	cppVar_64974 = (cppVar_64974 & cppMask_un_5_);
	cppVar_64975 = (0 << 5) | cppVar_64974;
	cppVar_64975 = (cppVar_64975 & cppMask_un_8_);
	cppVar_64977 = (cppVar_64975 == 153);
	if (cppVar_64977) {
	cppVar_64972 = SBUF;
	} else {
	cppVar_64979 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64980 = (cppVar_64979 << 3) | 2;
	cppVar_64980 = (cppVar_64980 & cppMask_un_5_);
	cppVar_64981 = (0 << 5) | cppVar_64980;
	cppVar_64981 = (cppVar_64981 & cppMask_un_8_);
	cppVar_64983 = (cppVar_64981 == 160);
	if (cppVar_64983) {
	cppVar_64978 = P2;
	} else {
	cppVar_64985 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64986 = (cppVar_64985 << 3) | 2;
	cppVar_64986 = (cppVar_64986 & cppMask_un_5_);
	cppVar_64987 = (0 << 5) | cppVar_64986;
	cppVar_64987 = (cppVar_64987 & cppMask_un_8_);
	cppVar_64989 = (cppVar_64987 == 168);
	if (cppVar_64989) {
	cppVar_64984 = IE;
	} else {
	cppVar_64991 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64992 = (cppVar_64991 << 3) | 2;
	cppVar_64992 = (cppVar_64992 & cppMask_un_5_);
	cppVar_64993 = (0 << 5) | cppVar_64992;
	cppVar_64993 = (cppVar_64993 & cppMask_un_8_);
	cppVar_64995 = (cppVar_64993 == 176);
	if (cppVar_64995) {
	cppVar_64990 = P3;
	} else {
	cppVar_64997 = (PSW >> 3) & cppMask_un_2_;
	cppVar_64998 = (cppVar_64997 << 3) | 2;
	cppVar_64998 = (cppVar_64998 & cppMask_un_5_);
	cppVar_64999 = (0 << 5) | cppVar_64998;
	cppVar_64999 = (cppVar_64999 & cppMask_un_8_);
	cppVar_65001 = (cppVar_64999 == 184);
	if (cppVar_65001) {
	cppVar_64996 = IP;
	} else {
	cppVar_65003 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65004 = (cppVar_65003 << 3) | 2;
	cppVar_65004 = (cppVar_65004 & cppMask_un_5_);
	cppVar_65005 = (0 << 5) | cppVar_65004;
	cppVar_65005 = (cppVar_65005 & cppMask_un_8_);
	cppVar_65007 = (cppVar_65005 == 208);
	if (cppVar_65007) {
	cppVar_65002 = PSW;
	} else {
	cppVar_65009 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65010 = (cppVar_65009 << 3) | 2;
	cppVar_65010 = (cppVar_65010 & cppMask_un_5_);
	cppVar_65011 = (0 << 5) | cppVar_65010;
	cppVar_65011 = (cppVar_65011 & cppMask_un_8_);
	cppVar_65013 = (cppVar_65011 == 224);
	if (cppVar_65013) {
	cppVar_65008 = ACC;
	} else {
	cppVar_65015 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65016 = (cppVar_65015 << 3) | 2;
	cppVar_65016 = (cppVar_65016 & cppMask_un_5_);
	cppVar_65017 = (0 << 5) | cppVar_65016;
	cppVar_65017 = (cppVar_65017 & cppMask_un_8_);
	cppVar_65019 = (cppVar_65017 == 240);
	if (cppVar_65019) {
	cppVar_65014 = B;
	} else {
	cppVar_65014 = 0;
	}
	cppVar_65008 = cppVar_65014;
	}
	cppVar_65002 = cppVar_65008;
	}
	cppVar_64996 = cppVar_65002;
	}
	cppVar_64990 = cppVar_64996;
	}
	cppVar_64984 = cppVar_64990;
	}
	cppVar_64978 = cppVar_64984;
	}
	cppVar_64972 = cppVar_64978;
	}
	cppVar_64966 = cppVar_64972;
	}
	cppVar_64960 = cppVar_64966;
	}
	cppVar_64954 = cppVar_64960;
	}
	cppVar_64948 = cppVar_64954;
	}
	cppVar_64942 = cppVar_64948;
	}
	cppVar_64936 = cppVar_64942;
	}
	cppVar_64930 = cppVar_64936;
	}
	cppVar_64924 = cppVar_64930;
	}
	cppVar_64918 = cppVar_64924;
	}
	cppVar_64912 = cppVar_64918;
	}
	cppVar_64906 = cppVar_64912;
	}
	cppVar_64900 = cppVar_64906;
	}
	cppVar_64894 = cppVar_64900;
	}
	cppVar_64881 = cppVar_64894;
	}
	cppVar_64875 = cppVar_64881;
	} else {
	cppVar_64875 = SP;
	}
	cppVar_64871 = cppVar_64875;
	} else {
	cppVar_65022 = ROM.rd(PC);
	cppVar_65024 = (cppVar_65022 == 137);
	if (cppVar_65024) {
	cppVar_65027 = PC + 1;
	cppVar_65027 = (cppVar_65027 & cppMask_un_16_);
	cppVar_65028 = ROM.rd(cppVar_65027);
	cppVar_65030 = (cppVar_65028 == 129);
	if (cppVar_65030) {
	cppVar_65033 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65035 = (cppVar_65033 << 3) | 1;
	cppVar_65035 = (cppVar_65035 & cppMask_un_5_);
	cppVar_65036 = (0 << 5) | cppVar_65035;
	cppVar_65036 = (cppVar_65036 & cppMask_un_8_);
	cppVar_65037 = (cppVar_65036 >> 7) & cppMask_un_1_;
	cppVar_65039 = (cppVar_65037 == 0);
	if (cppVar_65039) {
	cppVar_65040 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65041 = (cppVar_65040 << 3) | 1;
	cppVar_65041 = (cppVar_65041 & cppMask_un_5_);
	cppVar_65042 = (0 << 5) | cppVar_65041;
	cppVar_65042 = (cppVar_65042 & cppMask_un_8_);
	cppVar_65043 = IRAM.rd(cppVar_65042);
	cppVar_65031 = cppVar_65043;
	} else {
	cppVar_65045 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65046 = (cppVar_65045 << 3) | 1;
	cppVar_65046 = (cppVar_65046 & cppMask_un_5_);
	cppVar_65047 = (0 << 5) | cppVar_65046;
	cppVar_65047 = (cppVar_65047 & cppMask_un_8_);
	cppVar_65049 = (cppVar_65047 == 128);
	if (cppVar_65049) {
	cppVar_65044 = P0;
	} else {
	cppVar_65051 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65052 = (cppVar_65051 << 3) | 1;
	cppVar_65052 = (cppVar_65052 & cppMask_un_5_);
	cppVar_65053 = (0 << 5) | cppVar_65052;
	cppVar_65053 = (cppVar_65053 & cppMask_un_8_);
	cppVar_65055 = (cppVar_65053 == 129);
	if (cppVar_65055) {
	cppVar_65050 = SP;
	} else {
	cppVar_65057 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65058 = (cppVar_65057 << 3) | 1;
	cppVar_65058 = (cppVar_65058 & cppMask_un_5_);
	cppVar_65059 = (0 << 5) | cppVar_65058;
	cppVar_65059 = (cppVar_65059 & cppMask_un_8_);
	cppVar_65061 = (cppVar_65059 == 130);
	if (cppVar_65061) {
	cppVar_65056 = DPL;
	} else {
	cppVar_65063 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65064 = (cppVar_65063 << 3) | 1;
	cppVar_65064 = (cppVar_65064 & cppMask_un_5_);
	cppVar_65065 = (0 << 5) | cppVar_65064;
	cppVar_65065 = (cppVar_65065 & cppMask_un_8_);
	cppVar_65067 = (cppVar_65065 == 131);
	if (cppVar_65067) {
	cppVar_65062 = DPH;
	} else {
	cppVar_65069 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65070 = (cppVar_65069 << 3) | 1;
	cppVar_65070 = (cppVar_65070 & cppMask_un_5_);
	cppVar_65071 = (0 << 5) | cppVar_65070;
	cppVar_65071 = (cppVar_65071 & cppMask_un_8_);
	cppVar_65073 = (cppVar_65071 == 135);
	if (cppVar_65073) {
	cppVar_65068 = PCON;
	} else {
	cppVar_65075 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65076 = (cppVar_65075 << 3) | 1;
	cppVar_65076 = (cppVar_65076 & cppMask_un_5_);
	cppVar_65077 = (0 << 5) | cppVar_65076;
	cppVar_65077 = (cppVar_65077 & cppMask_un_8_);
	cppVar_65079 = (cppVar_65077 == 136);
	if (cppVar_65079) {
	cppVar_65074 = TCON;
	} else {
	cppVar_65081 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65082 = (cppVar_65081 << 3) | 1;
	cppVar_65082 = (cppVar_65082 & cppMask_un_5_);
	cppVar_65083 = (0 << 5) | cppVar_65082;
	cppVar_65083 = (cppVar_65083 & cppMask_un_8_);
	cppVar_65085 = (cppVar_65083 == 137);
	if (cppVar_65085) {
	cppVar_65080 = TMOD;
	} else {
	cppVar_65087 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65088 = (cppVar_65087 << 3) | 1;
	cppVar_65088 = (cppVar_65088 & cppMask_un_5_);
	cppVar_65089 = (0 << 5) | cppVar_65088;
	cppVar_65089 = (cppVar_65089 & cppMask_un_8_);
	cppVar_65091 = (cppVar_65089 == 138);
	if (cppVar_65091) {
	cppVar_65086 = TL0;
	} else {
	cppVar_65093 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65094 = (cppVar_65093 << 3) | 1;
	cppVar_65094 = (cppVar_65094 & cppMask_un_5_);
	cppVar_65095 = (0 << 5) | cppVar_65094;
	cppVar_65095 = (cppVar_65095 & cppMask_un_8_);
	cppVar_65097 = (cppVar_65095 == 140);
	if (cppVar_65097) {
	cppVar_65092 = TH0;
	} else {
	cppVar_65099 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65100 = (cppVar_65099 << 3) | 1;
	cppVar_65100 = (cppVar_65100 & cppMask_un_5_);
	cppVar_65101 = (0 << 5) | cppVar_65100;
	cppVar_65101 = (cppVar_65101 & cppMask_un_8_);
	cppVar_65103 = (cppVar_65101 == 139);
	if (cppVar_65103) {
	cppVar_65098 = TL1;
	} else {
	cppVar_65105 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65106 = (cppVar_65105 << 3) | 1;
	cppVar_65106 = (cppVar_65106 & cppMask_un_5_);
	cppVar_65107 = (0 << 5) | cppVar_65106;
	cppVar_65107 = (cppVar_65107 & cppMask_un_8_);
	cppVar_65109 = (cppVar_65107 == 141);
	if (cppVar_65109) {
	cppVar_65104 = TH1;
	} else {
	cppVar_65111 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65112 = (cppVar_65111 << 3) | 1;
	cppVar_65112 = (cppVar_65112 & cppMask_un_5_);
	cppVar_65113 = (0 << 5) | cppVar_65112;
	cppVar_65113 = (cppVar_65113 & cppMask_un_8_);
	cppVar_65115 = (cppVar_65113 == 144);
	if (cppVar_65115) {
	cppVar_65110 = P1;
	} else {
	cppVar_65117 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65118 = (cppVar_65117 << 3) | 1;
	cppVar_65118 = (cppVar_65118 & cppMask_un_5_);
	cppVar_65119 = (0 << 5) | cppVar_65118;
	cppVar_65119 = (cppVar_65119 & cppMask_un_8_);
	cppVar_65121 = (cppVar_65119 == 152);
	if (cppVar_65121) {
	cppVar_65116 = SCON;
	} else {
	cppVar_65123 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65124 = (cppVar_65123 << 3) | 1;
	cppVar_65124 = (cppVar_65124 & cppMask_un_5_);
	cppVar_65125 = (0 << 5) | cppVar_65124;
	cppVar_65125 = (cppVar_65125 & cppMask_un_8_);
	cppVar_65127 = (cppVar_65125 == 153);
	if (cppVar_65127) {
	cppVar_65122 = SBUF;
	} else {
	cppVar_65129 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65130 = (cppVar_65129 << 3) | 1;
	cppVar_65130 = (cppVar_65130 & cppMask_un_5_);
	cppVar_65131 = (0 << 5) | cppVar_65130;
	cppVar_65131 = (cppVar_65131 & cppMask_un_8_);
	cppVar_65133 = (cppVar_65131 == 160);
	if (cppVar_65133) {
	cppVar_65128 = P2;
	} else {
	cppVar_65135 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65136 = (cppVar_65135 << 3) | 1;
	cppVar_65136 = (cppVar_65136 & cppMask_un_5_);
	cppVar_65137 = (0 << 5) | cppVar_65136;
	cppVar_65137 = (cppVar_65137 & cppMask_un_8_);
	cppVar_65139 = (cppVar_65137 == 168);
	if (cppVar_65139) {
	cppVar_65134 = IE;
	} else {
	cppVar_65141 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65142 = (cppVar_65141 << 3) | 1;
	cppVar_65142 = (cppVar_65142 & cppMask_un_5_);
	cppVar_65143 = (0 << 5) | cppVar_65142;
	cppVar_65143 = (cppVar_65143 & cppMask_un_8_);
	cppVar_65145 = (cppVar_65143 == 176);
	if (cppVar_65145) {
	cppVar_65140 = P3;
	} else {
	cppVar_65147 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65148 = (cppVar_65147 << 3) | 1;
	cppVar_65148 = (cppVar_65148 & cppMask_un_5_);
	cppVar_65149 = (0 << 5) | cppVar_65148;
	cppVar_65149 = (cppVar_65149 & cppMask_un_8_);
	cppVar_65151 = (cppVar_65149 == 184);
	if (cppVar_65151) {
	cppVar_65146 = IP;
	} else {
	cppVar_65153 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65154 = (cppVar_65153 << 3) | 1;
	cppVar_65154 = (cppVar_65154 & cppMask_un_5_);
	cppVar_65155 = (0 << 5) | cppVar_65154;
	cppVar_65155 = (cppVar_65155 & cppMask_un_8_);
	cppVar_65157 = (cppVar_65155 == 208);
	if (cppVar_65157) {
	cppVar_65152 = PSW;
	} else {
	cppVar_65159 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65160 = (cppVar_65159 << 3) | 1;
	cppVar_65160 = (cppVar_65160 & cppMask_un_5_);
	cppVar_65161 = (0 << 5) | cppVar_65160;
	cppVar_65161 = (cppVar_65161 & cppMask_un_8_);
	cppVar_65163 = (cppVar_65161 == 224);
	if (cppVar_65163) {
	cppVar_65158 = ACC;
	} else {
	cppVar_65165 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65166 = (cppVar_65165 << 3) | 1;
	cppVar_65166 = (cppVar_65166 & cppMask_un_5_);
	cppVar_65167 = (0 << 5) | cppVar_65166;
	cppVar_65167 = (cppVar_65167 & cppMask_un_8_);
	cppVar_65169 = (cppVar_65167 == 240);
	if (cppVar_65169) {
	cppVar_65164 = B;
	} else {
	cppVar_65164 = 0;
	}
	cppVar_65158 = cppVar_65164;
	}
	cppVar_65152 = cppVar_65158;
	}
	cppVar_65146 = cppVar_65152;
	}
	cppVar_65140 = cppVar_65146;
	}
	cppVar_65134 = cppVar_65140;
	}
	cppVar_65128 = cppVar_65134;
	}
	cppVar_65122 = cppVar_65128;
	}
	cppVar_65116 = cppVar_65122;
	}
	cppVar_65110 = cppVar_65116;
	}
	cppVar_65104 = cppVar_65110;
	}
	cppVar_65098 = cppVar_65104;
	}
	cppVar_65092 = cppVar_65098;
	}
	cppVar_65086 = cppVar_65092;
	}
	cppVar_65080 = cppVar_65086;
	}
	cppVar_65074 = cppVar_65080;
	}
	cppVar_65068 = cppVar_65074;
	}
	cppVar_65062 = cppVar_65068;
	}
	cppVar_65056 = cppVar_65062;
	}
	cppVar_65050 = cppVar_65056;
	}
	cppVar_65044 = cppVar_65050;
	}
	cppVar_65031 = cppVar_65044;
	}
	cppVar_65025 = cppVar_65031;
	} else {
	cppVar_65025 = SP;
	}
	cppVar_65021 = cppVar_65025;
	} else {
	cppVar_65172 = ROM.rd(PC);
	cppVar_65174 = (cppVar_65172 == 136);
	if (cppVar_65174) {
	cppVar_65177 = PC + 1;
	cppVar_65177 = (cppVar_65177 & cppMask_un_16_);
	cppVar_65178 = ROM.rd(cppVar_65177);
	cppVar_65180 = (cppVar_65178 == 129);
	if (cppVar_65180) {
	cppVar_65183 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65185 = (cppVar_65183 << 3) | 0;
	cppVar_65185 = (cppVar_65185 & cppMask_un_5_);
	cppVar_65186 = (0 << 5) | cppVar_65185;
	cppVar_65186 = (cppVar_65186 & cppMask_un_8_);
	cppVar_65187 = (cppVar_65186 >> 7) & cppMask_un_1_;
	cppVar_65189 = (cppVar_65187 == 0);
	if (cppVar_65189) {
	cppVar_65190 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65191 = (cppVar_65190 << 3) | 0;
	cppVar_65191 = (cppVar_65191 & cppMask_un_5_);
	cppVar_65192 = (0 << 5) | cppVar_65191;
	cppVar_65192 = (cppVar_65192 & cppMask_un_8_);
	cppVar_65193 = IRAM.rd(cppVar_65192);
	cppVar_65181 = cppVar_65193;
	} else {
	cppVar_65195 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65196 = (cppVar_65195 << 3) | 0;
	cppVar_65196 = (cppVar_65196 & cppMask_un_5_);
	cppVar_65197 = (0 << 5) | cppVar_65196;
	cppVar_65197 = (cppVar_65197 & cppMask_un_8_);
	cppVar_65199 = (cppVar_65197 == 128);
	if (cppVar_65199) {
	cppVar_65194 = P0;
	} else {
	cppVar_65201 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65202 = (cppVar_65201 << 3) | 0;
	cppVar_65202 = (cppVar_65202 & cppMask_un_5_);
	cppVar_65203 = (0 << 5) | cppVar_65202;
	cppVar_65203 = (cppVar_65203 & cppMask_un_8_);
	cppVar_65205 = (cppVar_65203 == 129);
	if (cppVar_65205) {
	cppVar_65200 = SP;
	} else {
	cppVar_65207 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65208 = (cppVar_65207 << 3) | 0;
	cppVar_65208 = (cppVar_65208 & cppMask_un_5_);
	cppVar_65209 = (0 << 5) | cppVar_65208;
	cppVar_65209 = (cppVar_65209 & cppMask_un_8_);
	cppVar_65211 = (cppVar_65209 == 130);
	if (cppVar_65211) {
	cppVar_65206 = DPL;
	} else {
	cppVar_65213 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65214 = (cppVar_65213 << 3) | 0;
	cppVar_65214 = (cppVar_65214 & cppMask_un_5_);
	cppVar_65215 = (0 << 5) | cppVar_65214;
	cppVar_65215 = (cppVar_65215 & cppMask_un_8_);
	cppVar_65217 = (cppVar_65215 == 131);
	if (cppVar_65217) {
	cppVar_65212 = DPH;
	} else {
	cppVar_65219 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65220 = (cppVar_65219 << 3) | 0;
	cppVar_65220 = (cppVar_65220 & cppMask_un_5_);
	cppVar_65221 = (0 << 5) | cppVar_65220;
	cppVar_65221 = (cppVar_65221 & cppMask_un_8_);
	cppVar_65223 = (cppVar_65221 == 135);
	if (cppVar_65223) {
	cppVar_65218 = PCON;
	} else {
	cppVar_65225 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65226 = (cppVar_65225 << 3) | 0;
	cppVar_65226 = (cppVar_65226 & cppMask_un_5_);
	cppVar_65227 = (0 << 5) | cppVar_65226;
	cppVar_65227 = (cppVar_65227 & cppMask_un_8_);
	cppVar_65229 = (cppVar_65227 == 136);
	if (cppVar_65229) {
	cppVar_65224 = TCON;
	} else {
	cppVar_65231 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65232 = (cppVar_65231 << 3) | 0;
	cppVar_65232 = (cppVar_65232 & cppMask_un_5_);
	cppVar_65233 = (0 << 5) | cppVar_65232;
	cppVar_65233 = (cppVar_65233 & cppMask_un_8_);
	cppVar_65235 = (cppVar_65233 == 137);
	if (cppVar_65235) {
	cppVar_65230 = TMOD;
	} else {
	cppVar_65237 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65238 = (cppVar_65237 << 3) | 0;
	cppVar_65238 = (cppVar_65238 & cppMask_un_5_);
	cppVar_65239 = (0 << 5) | cppVar_65238;
	cppVar_65239 = (cppVar_65239 & cppMask_un_8_);
	cppVar_65241 = (cppVar_65239 == 138);
	if (cppVar_65241) {
	cppVar_65236 = TL0;
	} else {
	cppVar_65243 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65244 = (cppVar_65243 << 3) | 0;
	cppVar_65244 = (cppVar_65244 & cppMask_un_5_);
	cppVar_65245 = (0 << 5) | cppVar_65244;
	cppVar_65245 = (cppVar_65245 & cppMask_un_8_);
	cppVar_65247 = (cppVar_65245 == 140);
	if (cppVar_65247) {
	cppVar_65242 = TH0;
	} else {
	cppVar_65249 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65250 = (cppVar_65249 << 3) | 0;
	cppVar_65250 = (cppVar_65250 & cppMask_un_5_);
	cppVar_65251 = (0 << 5) | cppVar_65250;
	cppVar_65251 = (cppVar_65251 & cppMask_un_8_);
	cppVar_65253 = (cppVar_65251 == 139);
	if (cppVar_65253) {
	cppVar_65248 = TL1;
	} else {
	cppVar_65255 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65256 = (cppVar_65255 << 3) | 0;
	cppVar_65256 = (cppVar_65256 & cppMask_un_5_);
	cppVar_65257 = (0 << 5) | cppVar_65256;
	cppVar_65257 = (cppVar_65257 & cppMask_un_8_);
	cppVar_65259 = (cppVar_65257 == 141);
	if (cppVar_65259) {
	cppVar_65254 = TH1;
	} else {
	cppVar_65261 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65262 = (cppVar_65261 << 3) | 0;
	cppVar_65262 = (cppVar_65262 & cppMask_un_5_);
	cppVar_65263 = (0 << 5) | cppVar_65262;
	cppVar_65263 = (cppVar_65263 & cppMask_un_8_);
	cppVar_65265 = (cppVar_65263 == 144);
	if (cppVar_65265) {
	cppVar_65260 = P1;
	} else {
	cppVar_65267 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65268 = (cppVar_65267 << 3) | 0;
	cppVar_65268 = (cppVar_65268 & cppMask_un_5_);
	cppVar_65269 = (0 << 5) | cppVar_65268;
	cppVar_65269 = (cppVar_65269 & cppMask_un_8_);
	cppVar_65271 = (cppVar_65269 == 152);
	if (cppVar_65271) {
	cppVar_65266 = SCON;
	} else {
	cppVar_65273 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65274 = (cppVar_65273 << 3) | 0;
	cppVar_65274 = (cppVar_65274 & cppMask_un_5_);
	cppVar_65275 = (0 << 5) | cppVar_65274;
	cppVar_65275 = (cppVar_65275 & cppMask_un_8_);
	cppVar_65277 = (cppVar_65275 == 153);
	if (cppVar_65277) {
	cppVar_65272 = SBUF;
	} else {
	cppVar_65279 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65280 = (cppVar_65279 << 3) | 0;
	cppVar_65280 = (cppVar_65280 & cppMask_un_5_);
	cppVar_65281 = (0 << 5) | cppVar_65280;
	cppVar_65281 = (cppVar_65281 & cppMask_un_8_);
	cppVar_65283 = (cppVar_65281 == 160);
	if (cppVar_65283) {
	cppVar_65278 = P2;
	} else {
	cppVar_65285 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65286 = (cppVar_65285 << 3) | 0;
	cppVar_65286 = (cppVar_65286 & cppMask_un_5_);
	cppVar_65287 = (0 << 5) | cppVar_65286;
	cppVar_65287 = (cppVar_65287 & cppMask_un_8_);
	cppVar_65289 = (cppVar_65287 == 168);
	if (cppVar_65289) {
	cppVar_65284 = IE;
	} else {
	cppVar_65291 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65292 = (cppVar_65291 << 3) | 0;
	cppVar_65292 = (cppVar_65292 & cppMask_un_5_);
	cppVar_65293 = (0 << 5) | cppVar_65292;
	cppVar_65293 = (cppVar_65293 & cppMask_un_8_);
	cppVar_65295 = (cppVar_65293 == 176);
	if (cppVar_65295) {
	cppVar_65290 = P3;
	} else {
	cppVar_65297 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65298 = (cppVar_65297 << 3) | 0;
	cppVar_65298 = (cppVar_65298 & cppMask_un_5_);
	cppVar_65299 = (0 << 5) | cppVar_65298;
	cppVar_65299 = (cppVar_65299 & cppMask_un_8_);
	cppVar_65301 = (cppVar_65299 == 184);
	if (cppVar_65301) {
	cppVar_65296 = IP;
	} else {
	cppVar_65303 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65304 = (cppVar_65303 << 3) | 0;
	cppVar_65304 = (cppVar_65304 & cppMask_un_5_);
	cppVar_65305 = (0 << 5) | cppVar_65304;
	cppVar_65305 = (cppVar_65305 & cppMask_un_8_);
	cppVar_65307 = (cppVar_65305 == 208);
	if (cppVar_65307) {
	cppVar_65302 = PSW;
	} else {
	cppVar_65309 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65310 = (cppVar_65309 << 3) | 0;
	cppVar_65310 = (cppVar_65310 & cppMask_un_5_);
	cppVar_65311 = (0 << 5) | cppVar_65310;
	cppVar_65311 = (cppVar_65311 & cppMask_un_8_);
	cppVar_65313 = (cppVar_65311 == 224);
	if (cppVar_65313) {
	cppVar_65308 = ACC;
	} else {
	cppVar_65315 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65316 = (cppVar_65315 << 3) | 0;
	cppVar_65316 = (cppVar_65316 & cppMask_un_5_);
	cppVar_65317 = (0 << 5) | cppVar_65316;
	cppVar_65317 = (cppVar_65317 & cppMask_un_8_);
	cppVar_65319 = (cppVar_65317 == 240);
	if (cppVar_65319) {
	cppVar_65314 = B;
	} else {
	cppVar_65314 = 0;
	}
	cppVar_65308 = cppVar_65314;
	}
	cppVar_65302 = cppVar_65308;
	}
	cppVar_65296 = cppVar_65302;
	}
	cppVar_65290 = cppVar_65296;
	}
	cppVar_65284 = cppVar_65290;
	}
	cppVar_65278 = cppVar_65284;
	}
	cppVar_65272 = cppVar_65278;
	}
	cppVar_65266 = cppVar_65272;
	}
	cppVar_65260 = cppVar_65266;
	}
	cppVar_65254 = cppVar_65260;
	}
	cppVar_65248 = cppVar_65254;
	}
	cppVar_65242 = cppVar_65248;
	}
	cppVar_65236 = cppVar_65242;
	}
	cppVar_65230 = cppVar_65236;
	}
	cppVar_65224 = cppVar_65230;
	}
	cppVar_65218 = cppVar_65224;
	}
	cppVar_65212 = cppVar_65218;
	}
	cppVar_65206 = cppVar_65212;
	}
	cppVar_65200 = cppVar_65206;
	}
	cppVar_65194 = cppVar_65200;
	}
	cppVar_65181 = cppVar_65194;
	}
	cppVar_65175 = cppVar_65181;
	} else {
	cppVar_65175 = SP;
	}
	cppVar_65171 = cppVar_65175;
	} else {
	cppVar_65322 = ROM.rd(PC);
	cppVar_65324 = (cppVar_65322 == 135);
	if (cppVar_65324) {
	cppVar_65327 = PC + 1;
	cppVar_65327 = (cppVar_65327 & cppMask_un_16_);
	cppVar_65328 = ROM.rd(cppVar_65327);
	cppVar_65330 = (cppVar_65328 == 129);
	if (cppVar_65330) {
	cppVar_65332 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65334 = (cppVar_65332 << 3) | 1;
	cppVar_65334 = (cppVar_65334 & cppMask_un_5_);
	cppVar_65335 = (0 << 5) | cppVar_65334;
	cppVar_65335 = (cppVar_65335 & cppMask_un_8_);
	cppVar_65336 = IRAM.rd(cppVar_65335);
	cppVar_65337 = IRAM.rd(cppVar_65336);
	cppVar_65325 = cppVar_65337;
	} else {
	cppVar_65325 = SP;
	}
	cppVar_65321 = cppVar_65325;
	} else {
	cppVar_65339 = ROM.rd(PC);
	cppVar_65341 = (cppVar_65339 == 134);
	if (cppVar_65341) {
	cppVar_65344 = PC + 1;
	cppVar_65344 = (cppVar_65344 & cppMask_un_16_);
	cppVar_65345 = ROM.rd(cppVar_65344);
	cppVar_65347 = (cppVar_65345 == 129);
	if (cppVar_65347) {
	cppVar_65349 = (PSW >> 3) & cppMask_un_2_;
	cppVar_65351 = (cppVar_65349 << 3) | 0;
	cppVar_65351 = (cppVar_65351 & cppMask_un_5_);
	cppVar_65352 = (0 << 5) | cppVar_65351;
	cppVar_65352 = (cppVar_65352 & cppMask_un_8_);
	cppVar_65353 = IRAM.rd(cppVar_65352);
	cppVar_65354 = IRAM.rd(cppVar_65353);
	cppVar_65342 = cppVar_65354;
	} else {
	cppVar_65342 = SP;
	}
	cppVar_65338 = cppVar_65342;
	} else {
	cppVar_65356 = ROM.rd(PC);
	cppVar_65358 = (cppVar_65356 == 133);
	if (cppVar_65358) {
	cppVar_65361 = PC + 2;
	cppVar_65361 = (cppVar_65361 & cppMask_un_16_);
	cppVar_65362 = ROM.rd(cppVar_65361);
	cppVar_65364 = (cppVar_65362 == 129);
	if (cppVar_65364) {
	cppVar_65367 = PC + 1;
	cppVar_65367 = (cppVar_65367 & cppMask_un_16_);
	cppVar_65368 = ROM.rd(cppVar_65367);
	cppVar_65369 = (cppVar_65368 >> 7) & cppMask_un_1_;
	cppVar_65371 = (cppVar_65369 == 0);
	if (cppVar_65371) {
	cppVar_65372 = PC + 1;
	cppVar_65372 = (cppVar_65372 & cppMask_un_16_);
	cppVar_65373 = ROM.rd(cppVar_65372);
	cppVar_65374 = IRAM.rd(cppVar_65373);
	cppVar_65365 = cppVar_65374;
	} else {
	cppVar_65376 = PC + 1;
	cppVar_65376 = (cppVar_65376 & cppMask_un_16_);
	cppVar_65377 = ROM.rd(cppVar_65376);
	cppVar_65379 = (cppVar_65377 == 128);
	if (cppVar_65379) {
	cppVar_65375 = P0;
	} else {
	cppVar_65381 = PC + 1;
	cppVar_65381 = (cppVar_65381 & cppMask_un_16_);
	cppVar_65382 = ROM.rd(cppVar_65381);
	cppVar_65384 = (cppVar_65382 == 129);
	if (cppVar_65384) {
	cppVar_65380 = SP;
	} else {
	cppVar_65386 = PC + 1;
	cppVar_65386 = (cppVar_65386 & cppMask_un_16_);
	cppVar_65387 = ROM.rd(cppVar_65386);
	cppVar_65389 = (cppVar_65387 == 130);
	if (cppVar_65389) {
	cppVar_65385 = DPL;
	} else {
	cppVar_65391 = PC + 1;
	cppVar_65391 = (cppVar_65391 & cppMask_un_16_);
	cppVar_65392 = ROM.rd(cppVar_65391);
	cppVar_65394 = (cppVar_65392 == 131);
	if (cppVar_65394) {
	cppVar_65390 = DPH;
	} else {
	cppVar_65396 = PC + 1;
	cppVar_65396 = (cppVar_65396 & cppMask_un_16_);
	cppVar_65397 = ROM.rd(cppVar_65396);
	cppVar_65399 = (cppVar_65397 == 135);
	if (cppVar_65399) {
	cppVar_65395 = PCON;
	} else {
	cppVar_65401 = PC + 1;
	cppVar_65401 = (cppVar_65401 & cppMask_un_16_);
	cppVar_65402 = ROM.rd(cppVar_65401);
	cppVar_65404 = (cppVar_65402 == 136);
	if (cppVar_65404) {
	cppVar_65400 = TCON;
	} else {
	cppVar_65406 = PC + 1;
	cppVar_65406 = (cppVar_65406 & cppMask_un_16_);
	cppVar_65407 = ROM.rd(cppVar_65406);
	cppVar_65409 = (cppVar_65407 == 137);
	if (cppVar_65409) {
	cppVar_65405 = TMOD;
	} else {
	cppVar_65411 = PC + 1;
	cppVar_65411 = (cppVar_65411 & cppMask_un_16_);
	cppVar_65412 = ROM.rd(cppVar_65411);
	cppVar_65414 = (cppVar_65412 == 138);
	if (cppVar_65414) {
	cppVar_65410 = TL0;
	} else {
	cppVar_65416 = PC + 1;
	cppVar_65416 = (cppVar_65416 & cppMask_un_16_);
	cppVar_65417 = ROM.rd(cppVar_65416);
	cppVar_65419 = (cppVar_65417 == 140);
	if (cppVar_65419) {
	cppVar_65415 = TH0;
	} else {
	cppVar_65421 = PC + 1;
	cppVar_65421 = (cppVar_65421 & cppMask_un_16_);
	cppVar_65422 = ROM.rd(cppVar_65421);
	cppVar_65424 = (cppVar_65422 == 139);
	if (cppVar_65424) {
	cppVar_65420 = TL1;
	} else {
	cppVar_65426 = PC + 1;
	cppVar_65426 = (cppVar_65426 & cppMask_un_16_);
	cppVar_65427 = ROM.rd(cppVar_65426);
	cppVar_65429 = (cppVar_65427 == 141);
	if (cppVar_65429) {
	cppVar_65425 = TH1;
	} else {
	cppVar_65431 = PC + 1;
	cppVar_65431 = (cppVar_65431 & cppMask_un_16_);
	cppVar_65432 = ROM.rd(cppVar_65431);
	cppVar_65434 = (cppVar_65432 == 144);
	if (cppVar_65434) {
	cppVar_65430 = P1;
	} else {
	cppVar_65436 = PC + 1;
	cppVar_65436 = (cppVar_65436 & cppMask_un_16_);
	cppVar_65437 = ROM.rd(cppVar_65436);
	cppVar_65439 = (cppVar_65437 == 152);
	if (cppVar_65439) {
	cppVar_65435 = SCON;
	} else {
	cppVar_65441 = PC + 1;
	cppVar_65441 = (cppVar_65441 & cppMask_un_16_);
	cppVar_65442 = ROM.rd(cppVar_65441);
	cppVar_65444 = (cppVar_65442 == 153);
	if (cppVar_65444) {
	cppVar_65440 = SBUF;
	} else {
	cppVar_65446 = PC + 1;
	cppVar_65446 = (cppVar_65446 & cppMask_un_16_);
	cppVar_65447 = ROM.rd(cppVar_65446);
	cppVar_65449 = (cppVar_65447 == 160);
	if (cppVar_65449) {
	cppVar_65445 = P2;
	} else {
	cppVar_65451 = PC + 1;
	cppVar_65451 = (cppVar_65451 & cppMask_un_16_);
	cppVar_65452 = ROM.rd(cppVar_65451);
	cppVar_65454 = (cppVar_65452 == 168);
	if (cppVar_65454) {
	cppVar_65450 = IE;
	} else {
	cppVar_65456 = PC + 1;
	cppVar_65456 = (cppVar_65456 & cppMask_un_16_);
	cppVar_65457 = ROM.rd(cppVar_65456);
	cppVar_65459 = (cppVar_65457 == 176);
	if (cppVar_65459) {
	cppVar_65455 = P3;
	} else {
	cppVar_65461 = PC + 1;
	cppVar_65461 = (cppVar_65461 & cppMask_un_16_);
	cppVar_65462 = ROM.rd(cppVar_65461);
	cppVar_65464 = (cppVar_65462 == 184);
	if (cppVar_65464) {
	cppVar_65460 = IP;
	} else {
	cppVar_65466 = PC + 1;
	cppVar_65466 = (cppVar_65466 & cppMask_un_16_);
	cppVar_65467 = ROM.rd(cppVar_65466);
	cppVar_65469 = (cppVar_65467 == 208);
	if (cppVar_65469) {
	cppVar_65465 = PSW;
	} else {
	cppVar_65471 = PC + 1;
	cppVar_65471 = (cppVar_65471 & cppMask_un_16_);
	cppVar_65472 = ROM.rd(cppVar_65471);
	cppVar_65474 = (cppVar_65472 == 224);
	if (cppVar_65474) {
	cppVar_65470 = ACC;
	} else {
	cppVar_65476 = PC + 1;
	cppVar_65476 = (cppVar_65476 & cppMask_un_16_);
	cppVar_65477 = ROM.rd(cppVar_65476);
	cppVar_65479 = (cppVar_65477 == 240);
	if (cppVar_65479) {
	cppVar_65475 = B;
	} else {
	cppVar_65475 = 0;
	}
	cppVar_65470 = cppVar_65475;
	}
	cppVar_65465 = cppVar_65470;
	}
	cppVar_65460 = cppVar_65465;
	}
	cppVar_65455 = cppVar_65460;
	}
	cppVar_65450 = cppVar_65455;
	}
	cppVar_65445 = cppVar_65450;
	}
	cppVar_65440 = cppVar_65445;
	}
	cppVar_65435 = cppVar_65440;
	}
	cppVar_65430 = cppVar_65435;
	}
	cppVar_65425 = cppVar_65430;
	}
	cppVar_65420 = cppVar_65425;
	}
	cppVar_65415 = cppVar_65420;
	}
	cppVar_65410 = cppVar_65415;
	}
	cppVar_65405 = cppVar_65410;
	}
	cppVar_65400 = cppVar_65405;
	}
	cppVar_65395 = cppVar_65400;
	}
	cppVar_65390 = cppVar_65395;
	}
	cppVar_65385 = cppVar_65390;
	}
	cppVar_65380 = cppVar_65385;
	}
	cppVar_65375 = cppVar_65380;
	}
	cppVar_65365 = cppVar_65375;
	}
	cppVar_65359 = cppVar_65365;
	} else {
	cppVar_65359 = SP;
	}
	cppVar_65355 = cppVar_65359;
	} else {
	cppVar_65482 = ROM.rd(PC);
	cppVar_65484 = (cppVar_65482 == 117);
	if (cppVar_65484) {
	cppVar_65487 = PC + 1;
	cppVar_65487 = (cppVar_65487 & cppMask_un_16_);
	cppVar_65488 = ROM.rd(cppVar_65487);
	cppVar_65490 = (cppVar_65488 == 129);
	if (cppVar_65490) {
	cppVar_65492 = PC + 2;
	cppVar_65492 = (cppVar_65492 & cppMask_un_16_);
	cppVar_65493 = ROM.rd(cppVar_65492);
	cppVar_65485 = cppVar_65493;
	} else {
	cppVar_65485 = SP;
	}
	cppVar_65481 = cppVar_65485;
	} else {
	cppVar_65495 = ROM.rd(PC);
	cppVar_65497 = (cppVar_65495 == 99);
	if (cppVar_65497) {
	cppVar_65500 = PC + 1;
	cppVar_65500 = (cppVar_65500 & cppMask_un_16_);
	cppVar_65501 = ROM.rd(cppVar_65500);
	cppVar_65503 = (cppVar_65501 == 129);
	if (cppVar_65503) {
	cppVar_65505 = PC + 1;
	cppVar_65505 = (cppVar_65505 & cppMask_un_16_);
	cppVar_65506 = ROM.rd(cppVar_65505);
	cppVar_65507 = (cppVar_65506 >> 7) & cppMask_un_1_;
	cppVar_65509 = (cppVar_65507 == 0);
	if (cppVar_65509) {
	cppVar_65510 = PC + 1;
	cppVar_65510 = (cppVar_65510 & cppMask_un_16_);
	cppVar_65511 = ROM.rd(cppVar_65510);
	cppVar_65512 = IRAM.rd(cppVar_65511);
	cppVar_65504 = cppVar_65512;
	} else {
	cppVar_65514 = PC + 1;
	cppVar_65514 = (cppVar_65514 & cppMask_un_16_);
	cppVar_65515 = ROM.rd(cppVar_65514);
	cppVar_65517 = (cppVar_65515 == 128);
	if (cppVar_65517) {
	cppVar_65513 = P0;
	} else {
	cppVar_65519 = PC + 1;
	cppVar_65519 = (cppVar_65519 & cppMask_un_16_);
	cppVar_65520 = ROM.rd(cppVar_65519);
	cppVar_65522 = (cppVar_65520 == 129);
	if (cppVar_65522) {
	cppVar_65518 = SP;
	} else {
	cppVar_65524 = PC + 1;
	cppVar_65524 = (cppVar_65524 & cppMask_un_16_);
	cppVar_65525 = ROM.rd(cppVar_65524);
	cppVar_65527 = (cppVar_65525 == 130);
	if (cppVar_65527) {
	cppVar_65523 = DPL;
	} else {
	cppVar_65529 = PC + 1;
	cppVar_65529 = (cppVar_65529 & cppMask_un_16_);
	cppVar_65530 = ROM.rd(cppVar_65529);
	cppVar_65532 = (cppVar_65530 == 131);
	if (cppVar_65532) {
	cppVar_65528 = DPH;
	} else {
	cppVar_65534 = PC + 1;
	cppVar_65534 = (cppVar_65534 & cppMask_un_16_);
	cppVar_65535 = ROM.rd(cppVar_65534);
	cppVar_65537 = (cppVar_65535 == 135);
	if (cppVar_65537) {
	cppVar_65533 = PCON;
	} else {
	cppVar_65539 = PC + 1;
	cppVar_65539 = (cppVar_65539 & cppMask_un_16_);
	cppVar_65540 = ROM.rd(cppVar_65539);
	cppVar_65542 = (cppVar_65540 == 136);
	if (cppVar_65542) {
	cppVar_65538 = TCON;
	} else {
	cppVar_65544 = PC + 1;
	cppVar_65544 = (cppVar_65544 & cppMask_un_16_);
	cppVar_65545 = ROM.rd(cppVar_65544);
	cppVar_65547 = (cppVar_65545 == 137);
	if (cppVar_65547) {
	cppVar_65543 = TMOD;
	} else {
	cppVar_65549 = PC + 1;
	cppVar_65549 = (cppVar_65549 & cppMask_un_16_);
	cppVar_65550 = ROM.rd(cppVar_65549);
	cppVar_65552 = (cppVar_65550 == 138);
	if (cppVar_65552) {
	cppVar_65548 = TL0;
	} else {
	cppVar_65554 = PC + 1;
	cppVar_65554 = (cppVar_65554 & cppMask_un_16_);
	cppVar_65555 = ROM.rd(cppVar_65554);
	cppVar_65557 = (cppVar_65555 == 140);
	if (cppVar_65557) {
	cppVar_65553 = TH0;
	} else {
	cppVar_65559 = PC + 1;
	cppVar_65559 = (cppVar_65559 & cppMask_un_16_);
	cppVar_65560 = ROM.rd(cppVar_65559);
	cppVar_65562 = (cppVar_65560 == 139);
	if (cppVar_65562) {
	cppVar_65558 = TL1;
	} else {
	cppVar_65564 = PC + 1;
	cppVar_65564 = (cppVar_65564 & cppMask_un_16_);
	cppVar_65565 = ROM.rd(cppVar_65564);
	cppVar_65567 = (cppVar_65565 == 141);
	if (cppVar_65567) {
	cppVar_65563 = TH1;
	} else {
	cppVar_65569 = PC + 1;
	cppVar_65569 = (cppVar_65569 & cppMask_un_16_);
	cppVar_65570 = ROM.rd(cppVar_65569);
	cppVar_65572 = (cppVar_65570 == 144);
	if (cppVar_65572) {
	cppVar_65568 = P1;
	} else {
	cppVar_65574 = PC + 1;
	cppVar_65574 = (cppVar_65574 & cppMask_un_16_);
	cppVar_65575 = ROM.rd(cppVar_65574);
	cppVar_65577 = (cppVar_65575 == 152);
	if (cppVar_65577) {
	cppVar_65573 = SCON;
	} else {
	cppVar_65579 = PC + 1;
	cppVar_65579 = (cppVar_65579 & cppMask_un_16_);
	cppVar_65580 = ROM.rd(cppVar_65579);
	cppVar_65582 = (cppVar_65580 == 153);
	if (cppVar_65582) {
	cppVar_65578 = SBUF;
	} else {
	cppVar_65584 = PC + 1;
	cppVar_65584 = (cppVar_65584 & cppMask_un_16_);
	cppVar_65585 = ROM.rd(cppVar_65584);
	cppVar_65587 = (cppVar_65585 == 160);
	if (cppVar_65587) {
	cppVar_65583 = P2;
	} else {
	cppVar_65589 = PC + 1;
	cppVar_65589 = (cppVar_65589 & cppMask_un_16_);
	cppVar_65590 = ROM.rd(cppVar_65589);
	cppVar_65592 = (cppVar_65590 == 168);
	if (cppVar_65592) {
	cppVar_65588 = IE;
	} else {
	cppVar_65594 = PC + 1;
	cppVar_65594 = (cppVar_65594 & cppMask_un_16_);
	cppVar_65595 = ROM.rd(cppVar_65594);
	cppVar_65597 = (cppVar_65595 == 176);
	if (cppVar_65597) {
	cppVar_65593 = P3;
	} else {
	cppVar_65599 = PC + 1;
	cppVar_65599 = (cppVar_65599 & cppMask_un_16_);
	cppVar_65600 = ROM.rd(cppVar_65599);
	cppVar_65602 = (cppVar_65600 == 184);
	if (cppVar_65602) {
	cppVar_65598 = IP;
	} else {
	cppVar_65604 = PC + 1;
	cppVar_65604 = (cppVar_65604 & cppMask_un_16_);
	cppVar_65605 = ROM.rd(cppVar_65604);
	cppVar_65607 = (cppVar_65605 == 208);
	if (cppVar_65607) {
	cppVar_65603 = PSW;
	} else {
	cppVar_65609 = PC + 1;
	cppVar_65609 = (cppVar_65609 & cppMask_un_16_);
	cppVar_65610 = ROM.rd(cppVar_65609);
	cppVar_65612 = (cppVar_65610 == 224);
	if (cppVar_65612) {
	cppVar_65608 = ACC;
	} else {
	cppVar_65614 = PC + 1;
	cppVar_65614 = (cppVar_65614 & cppMask_un_16_);
	cppVar_65615 = ROM.rd(cppVar_65614);
	cppVar_65617 = (cppVar_65615 == 240);
	if (cppVar_65617) {
	cppVar_65613 = B;
	} else {
	cppVar_65613 = 0;
	}
	cppVar_65608 = cppVar_65613;
	}
	cppVar_65603 = cppVar_65608;
	}
	cppVar_65598 = cppVar_65603;
	}
	cppVar_65593 = cppVar_65598;
	}
	cppVar_65588 = cppVar_65593;
	}
	cppVar_65583 = cppVar_65588;
	}
	cppVar_65578 = cppVar_65583;
	}
	cppVar_65573 = cppVar_65578;
	}
	cppVar_65568 = cppVar_65573;
	}
	cppVar_65563 = cppVar_65568;
	}
	cppVar_65558 = cppVar_65563;
	}
	cppVar_65553 = cppVar_65558;
	}
	cppVar_65548 = cppVar_65553;
	}
	cppVar_65543 = cppVar_65548;
	}
	cppVar_65538 = cppVar_65543;
	}
	cppVar_65533 = cppVar_65538;
	}
	cppVar_65528 = cppVar_65533;
	}
	cppVar_65523 = cppVar_65528;
	}
	cppVar_65518 = cppVar_65523;
	}
	cppVar_65513 = cppVar_65518;
	}
	cppVar_65504 = cppVar_65513;
	}
	cppVar_65620 = PC + 2;
	cppVar_65620 = (cppVar_65620 & cppMask_un_16_);
	cppVar_65621 = ROM.rd(cppVar_65620);
	cppVar_65622 = cppVar_65504 ^ cppVar_65621;
	cppVar_65498 = cppVar_65622;
	} else {
	cppVar_65498 = SP;
	}
	cppVar_65494 = cppVar_65498;
	} else {
	cppVar_65624 = ROM.rd(PC);
	cppVar_65626 = (cppVar_65624 == 98);
	if (cppVar_65626) {
	cppVar_65629 = PC + 1;
	cppVar_65629 = (cppVar_65629 & cppMask_un_16_);
	cppVar_65630 = ROM.rd(cppVar_65629);
	cppVar_65632 = (cppVar_65630 == 129);
	if (cppVar_65632) {
	cppVar_65634 = PC + 1;
	cppVar_65634 = (cppVar_65634 & cppMask_un_16_);
	cppVar_65635 = ROM.rd(cppVar_65634);
	cppVar_65636 = (cppVar_65635 >> 7) & cppMask_un_1_;
	cppVar_65638 = (cppVar_65636 == 0);
	if (cppVar_65638) {
	cppVar_65639 = PC + 1;
	cppVar_65639 = (cppVar_65639 & cppMask_un_16_);
	cppVar_65640 = ROM.rd(cppVar_65639);
	cppVar_65641 = IRAM.rd(cppVar_65640);
	cppVar_65633 = cppVar_65641;
	} else {
	cppVar_65643 = PC + 1;
	cppVar_65643 = (cppVar_65643 & cppMask_un_16_);
	cppVar_65644 = ROM.rd(cppVar_65643);
	cppVar_65646 = (cppVar_65644 == 128);
	if (cppVar_65646) {
	cppVar_65642 = P0;
	} else {
	cppVar_65648 = PC + 1;
	cppVar_65648 = (cppVar_65648 & cppMask_un_16_);
	cppVar_65649 = ROM.rd(cppVar_65648);
	cppVar_65651 = (cppVar_65649 == 129);
	if (cppVar_65651) {
	cppVar_65647 = SP;
	} else {
	cppVar_65653 = PC + 1;
	cppVar_65653 = (cppVar_65653 & cppMask_un_16_);
	cppVar_65654 = ROM.rd(cppVar_65653);
	cppVar_65656 = (cppVar_65654 == 130);
	if (cppVar_65656) {
	cppVar_65652 = DPL;
	} else {
	cppVar_65658 = PC + 1;
	cppVar_65658 = (cppVar_65658 & cppMask_un_16_);
	cppVar_65659 = ROM.rd(cppVar_65658);
	cppVar_65661 = (cppVar_65659 == 131);
	if (cppVar_65661) {
	cppVar_65657 = DPH;
	} else {
	cppVar_65663 = PC + 1;
	cppVar_65663 = (cppVar_65663 & cppMask_un_16_);
	cppVar_65664 = ROM.rd(cppVar_65663);
	cppVar_65666 = (cppVar_65664 == 135);
	if (cppVar_65666) {
	cppVar_65662 = PCON;
	} else {
	cppVar_65668 = PC + 1;
	cppVar_65668 = (cppVar_65668 & cppMask_un_16_);
	cppVar_65669 = ROM.rd(cppVar_65668);
	cppVar_65671 = (cppVar_65669 == 136);
	if (cppVar_65671) {
	cppVar_65667 = TCON;
	} else {
	cppVar_65673 = PC + 1;
	cppVar_65673 = (cppVar_65673 & cppMask_un_16_);
	cppVar_65674 = ROM.rd(cppVar_65673);
	cppVar_65676 = (cppVar_65674 == 137);
	if (cppVar_65676) {
	cppVar_65672 = TMOD;
	} else {
	cppVar_65678 = PC + 1;
	cppVar_65678 = (cppVar_65678 & cppMask_un_16_);
	cppVar_65679 = ROM.rd(cppVar_65678);
	cppVar_65681 = (cppVar_65679 == 138);
	if (cppVar_65681) {
	cppVar_65677 = TL0;
	} else {
	cppVar_65683 = PC + 1;
	cppVar_65683 = (cppVar_65683 & cppMask_un_16_);
	cppVar_65684 = ROM.rd(cppVar_65683);
	cppVar_65686 = (cppVar_65684 == 140);
	if (cppVar_65686) {
	cppVar_65682 = TH0;
	} else {
	cppVar_65688 = PC + 1;
	cppVar_65688 = (cppVar_65688 & cppMask_un_16_);
	cppVar_65689 = ROM.rd(cppVar_65688);
	cppVar_65691 = (cppVar_65689 == 139);
	if (cppVar_65691) {
	cppVar_65687 = TL1;
	} else {
	cppVar_65693 = PC + 1;
	cppVar_65693 = (cppVar_65693 & cppMask_un_16_);
	cppVar_65694 = ROM.rd(cppVar_65693);
	cppVar_65696 = (cppVar_65694 == 141);
	if (cppVar_65696) {
	cppVar_65692 = TH1;
	} else {
	cppVar_65698 = PC + 1;
	cppVar_65698 = (cppVar_65698 & cppMask_un_16_);
	cppVar_65699 = ROM.rd(cppVar_65698);
	cppVar_65701 = (cppVar_65699 == 144);
	if (cppVar_65701) {
	cppVar_65697 = P1;
	} else {
	cppVar_65703 = PC + 1;
	cppVar_65703 = (cppVar_65703 & cppMask_un_16_);
	cppVar_65704 = ROM.rd(cppVar_65703);
	cppVar_65706 = (cppVar_65704 == 152);
	if (cppVar_65706) {
	cppVar_65702 = SCON;
	} else {
	cppVar_65708 = PC + 1;
	cppVar_65708 = (cppVar_65708 & cppMask_un_16_);
	cppVar_65709 = ROM.rd(cppVar_65708);
	cppVar_65711 = (cppVar_65709 == 153);
	if (cppVar_65711) {
	cppVar_65707 = SBUF;
	} else {
	cppVar_65713 = PC + 1;
	cppVar_65713 = (cppVar_65713 & cppMask_un_16_);
	cppVar_65714 = ROM.rd(cppVar_65713);
	cppVar_65716 = (cppVar_65714 == 160);
	if (cppVar_65716) {
	cppVar_65712 = P2;
	} else {
	cppVar_65718 = PC + 1;
	cppVar_65718 = (cppVar_65718 & cppMask_un_16_);
	cppVar_65719 = ROM.rd(cppVar_65718);
	cppVar_65721 = (cppVar_65719 == 168);
	if (cppVar_65721) {
	cppVar_65717 = IE;
	} else {
	cppVar_65723 = PC + 1;
	cppVar_65723 = (cppVar_65723 & cppMask_un_16_);
	cppVar_65724 = ROM.rd(cppVar_65723);
	cppVar_65726 = (cppVar_65724 == 176);
	if (cppVar_65726) {
	cppVar_65722 = P3;
	} else {
	cppVar_65728 = PC + 1;
	cppVar_65728 = (cppVar_65728 & cppMask_un_16_);
	cppVar_65729 = ROM.rd(cppVar_65728);
	cppVar_65731 = (cppVar_65729 == 184);
	if (cppVar_65731) {
	cppVar_65727 = IP;
	} else {
	cppVar_65733 = PC + 1;
	cppVar_65733 = (cppVar_65733 & cppMask_un_16_);
	cppVar_65734 = ROM.rd(cppVar_65733);
	cppVar_65736 = (cppVar_65734 == 208);
	if (cppVar_65736) {
	cppVar_65732 = PSW;
	} else {
	cppVar_65738 = PC + 1;
	cppVar_65738 = (cppVar_65738 & cppMask_un_16_);
	cppVar_65739 = ROM.rd(cppVar_65738);
	cppVar_65741 = (cppVar_65739 == 224);
	if (cppVar_65741) {
	cppVar_65737 = ACC;
	} else {
	cppVar_65743 = PC + 1;
	cppVar_65743 = (cppVar_65743 & cppMask_un_16_);
	cppVar_65744 = ROM.rd(cppVar_65743);
	cppVar_65746 = (cppVar_65744 == 240);
	if (cppVar_65746) {
	cppVar_65742 = B;
	} else {
	cppVar_65742 = 0;
	}
	cppVar_65737 = cppVar_65742;
	}
	cppVar_65732 = cppVar_65737;
	}
	cppVar_65727 = cppVar_65732;
	}
	cppVar_65722 = cppVar_65727;
	}
	cppVar_65717 = cppVar_65722;
	}
	cppVar_65712 = cppVar_65717;
	}
	cppVar_65707 = cppVar_65712;
	}
	cppVar_65702 = cppVar_65707;
	}
	cppVar_65697 = cppVar_65702;
	}
	cppVar_65692 = cppVar_65697;
	}
	cppVar_65687 = cppVar_65692;
	}
	cppVar_65682 = cppVar_65687;
	}
	cppVar_65677 = cppVar_65682;
	}
	cppVar_65672 = cppVar_65677;
	}
	cppVar_65667 = cppVar_65672;
	}
	cppVar_65662 = cppVar_65667;
	}
	cppVar_65657 = cppVar_65662;
	}
	cppVar_65652 = cppVar_65657;
	}
	cppVar_65647 = cppVar_65652;
	}
	cppVar_65642 = cppVar_65647;
	}
	cppVar_65633 = cppVar_65642;
	}
	cppVar_65748 = cppVar_65633 ^ ACC;
	cppVar_65627 = cppVar_65748;
	} else {
	cppVar_65627 = SP;
	}
	cppVar_65623 = cppVar_65627;
	} else {
	cppVar_65750 = ROM.rd(PC);
	cppVar_65752 = (cppVar_65750 == 83);
	if (cppVar_65752) {
	cppVar_65755 = PC + 1;
	cppVar_65755 = (cppVar_65755 & cppMask_un_16_);
	cppVar_65756 = ROM.rd(cppVar_65755);
	cppVar_65758 = (cppVar_65756 == 129);
	if (cppVar_65758) {
	cppVar_65760 = PC + 1;
	cppVar_65760 = (cppVar_65760 & cppMask_un_16_);
	cppVar_65761 = ROM.rd(cppVar_65760);
	cppVar_65762 = (cppVar_65761 >> 7) & cppMask_un_1_;
	cppVar_65764 = (cppVar_65762 == 0);
	if (cppVar_65764) {
	cppVar_65765 = PC + 1;
	cppVar_65765 = (cppVar_65765 & cppMask_un_16_);
	cppVar_65766 = ROM.rd(cppVar_65765);
	cppVar_65767 = IRAM.rd(cppVar_65766);
	cppVar_65759 = cppVar_65767;
	} else {
	cppVar_65769 = PC + 1;
	cppVar_65769 = (cppVar_65769 & cppMask_un_16_);
	cppVar_65770 = ROM.rd(cppVar_65769);
	cppVar_65772 = (cppVar_65770 == 128);
	if (cppVar_65772) {
	cppVar_65768 = P0;
	} else {
	cppVar_65774 = PC + 1;
	cppVar_65774 = (cppVar_65774 & cppMask_un_16_);
	cppVar_65775 = ROM.rd(cppVar_65774);
	cppVar_65777 = (cppVar_65775 == 129);
	if (cppVar_65777) {
	cppVar_65773 = SP;
	} else {
	cppVar_65779 = PC + 1;
	cppVar_65779 = (cppVar_65779 & cppMask_un_16_);
	cppVar_65780 = ROM.rd(cppVar_65779);
	cppVar_65782 = (cppVar_65780 == 130);
	if (cppVar_65782) {
	cppVar_65778 = DPL;
	} else {
	cppVar_65784 = PC + 1;
	cppVar_65784 = (cppVar_65784 & cppMask_un_16_);
	cppVar_65785 = ROM.rd(cppVar_65784);
	cppVar_65787 = (cppVar_65785 == 131);
	if (cppVar_65787) {
	cppVar_65783 = DPH;
	} else {
	cppVar_65789 = PC + 1;
	cppVar_65789 = (cppVar_65789 & cppMask_un_16_);
	cppVar_65790 = ROM.rd(cppVar_65789);
	cppVar_65792 = (cppVar_65790 == 135);
	if (cppVar_65792) {
	cppVar_65788 = PCON;
	} else {
	cppVar_65794 = PC + 1;
	cppVar_65794 = (cppVar_65794 & cppMask_un_16_);
	cppVar_65795 = ROM.rd(cppVar_65794);
	cppVar_65797 = (cppVar_65795 == 136);
	if (cppVar_65797) {
	cppVar_65793 = TCON;
	} else {
	cppVar_65799 = PC + 1;
	cppVar_65799 = (cppVar_65799 & cppMask_un_16_);
	cppVar_65800 = ROM.rd(cppVar_65799);
	cppVar_65802 = (cppVar_65800 == 137);
	if (cppVar_65802) {
	cppVar_65798 = TMOD;
	} else {
	cppVar_65804 = PC + 1;
	cppVar_65804 = (cppVar_65804 & cppMask_un_16_);
	cppVar_65805 = ROM.rd(cppVar_65804);
	cppVar_65807 = (cppVar_65805 == 138);
	if (cppVar_65807) {
	cppVar_65803 = TL0;
	} else {
	cppVar_65809 = PC + 1;
	cppVar_65809 = (cppVar_65809 & cppMask_un_16_);
	cppVar_65810 = ROM.rd(cppVar_65809);
	cppVar_65812 = (cppVar_65810 == 140);
	if (cppVar_65812) {
	cppVar_65808 = TH0;
	} else {
	cppVar_65814 = PC + 1;
	cppVar_65814 = (cppVar_65814 & cppMask_un_16_);
	cppVar_65815 = ROM.rd(cppVar_65814);
	cppVar_65817 = (cppVar_65815 == 139);
	if (cppVar_65817) {
	cppVar_65813 = TL1;
	} else {
	cppVar_65819 = PC + 1;
	cppVar_65819 = (cppVar_65819 & cppMask_un_16_);
	cppVar_65820 = ROM.rd(cppVar_65819);
	cppVar_65822 = (cppVar_65820 == 141);
	if (cppVar_65822) {
	cppVar_65818 = TH1;
	} else {
	cppVar_65824 = PC + 1;
	cppVar_65824 = (cppVar_65824 & cppMask_un_16_);
	cppVar_65825 = ROM.rd(cppVar_65824);
	cppVar_65827 = (cppVar_65825 == 144);
	if (cppVar_65827) {
	cppVar_65823 = P1;
	} else {
	cppVar_65829 = PC + 1;
	cppVar_65829 = (cppVar_65829 & cppMask_un_16_);
	cppVar_65830 = ROM.rd(cppVar_65829);
	cppVar_65832 = (cppVar_65830 == 152);
	if (cppVar_65832) {
	cppVar_65828 = SCON;
	} else {
	cppVar_65834 = PC + 1;
	cppVar_65834 = (cppVar_65834 & cppMask_un_16_);
	cppVar_65835 = ROM.rd(cppVar_65834);
	cppVar_65837 = (cppVar_65835 == 153);
	if (cppVar_65837) {
	cppVar_65833 = SBUF;
	} else {
	cppVar_65839 = PC + 1;
	cppVar_65839 = (cppVar_65839 & cppMask_un_16_);
	cppVar_65840 = ROM.rd(cppVar_65839);
	cppVar_65842 = (cppVar_65840 == 160);
	if (cppVar_65842) {
	cppVar_65838 = P2;
	} else {
	cppVar_65844 = PC + 1;
	cppVar_65844 = (cppVar_65844 & cppMask_un_16_);
	cppVar_65845 = ROM.rd(cppVar_65844);
	cppVar_65847 = (cppVar_65845 == 168);
	if (cppVar_65847) {
	cppVar_65843 = IE;
	} else {
	cppVar_65849 = PC + 1;
	cppVar_65849 = (cppVar_65849 & cppMask_un_16_);
	cppVar_65850 = ROM.rd(cppVar_65849);
	cppVar_65852 = (cppVar_65850 == 176);
	if (cppVar_65852) {
	cppVar_65848 = P3;
	} else {
	cppVar_65854 = PC + 1;
	cppVar_65854 = (cppVar_65854 & cppMask_un_16_);
	cppVar_65855 = ROM.rd(cppVar_65854);
	cppVar_65857 = (cppVar_65855 == 184);
	if (cppVar_65857) {
	cppVar_65853 = IP;
	} else {
	cppVar_65859 = PC + 1;
	cppVar_65859 = (cppVar_65859 & cppMask_un_16_);
	cppVar_65860 = ROM.rd(cppVar_65859);
	cppVar_65862 = (cppVar_65860 == 208);
	if (cppVar_65862) {
	cppVar_65858 = PSW;
	} else {
	cppVar_65864 = PC + 1;
	cppVar_65864 = (cppVar_65864 & cppMask_un_16_);
	cppVar_65865 = ROM.rd(cppVar_65864);
	cppVar_65867 = (cppVar_65865 == 224);
	if (cppVar_65867) {
	cppVar_65863 = ACC;
	} else {
	cppVar_65869 = PC + 1;
	cppVar_65869 = (cppVar_65869 & cppMask_un_16_);
	cppVar_65870 = ROM.rd(cppVar_65869);
	cppVar_65872 = (cppVar_65870 == 240);
	if (cppVar_65872) {
	cppVar_65868 = B;
	} else {
	cppVar_65868 = 0;
	}
	cppVar_65863 = cppVar_65868;
	}
	cppVar_65858 = cppVar_65863;
	}
	cppVar_65853 = cppVar_65858;
	}
	cppVar_65848 = cppVar_65853;
	}
	cppVar_65843 = cppVar_65848;
	}
	cppVar_65838 = cppVar_65843;
	}
	cppVar_65833 = cppVar_65838;
	}
	cppVar_65828 = cppVar_65833;
	}
	cppVar_65823 = cppVar_65828;
	}
	cppVar_65818 = cppVar_65823;
	}
	cppVar_65813 = cppVar_65818;
	}
	cppVar_65808 = cppVar_65813;
	}
	cppVar_65803 = cppVar_65808;
	}
	cppVar_65798 = cppVar_65803;
	}
	cppVar_65793 = cppVar_65798;
	}
	cppVar_65788 = cppVar_65793;
	}
	cppVar_65783 = cppVar_65788;
	}
	cppVar_65778 = cppVar_65783;
	}
	cppVar_65773 = cppVar_65778;
	}
	cppVar_65768 = cppVar_65773;
	}
	cppVar_65759 = cppVar_65768;
	}
	cppVar_65875 = PC + 2;
	cppVar_65875 = (cppVar_65875 & cppMask_un_16_);
	cppVar_65876 = ROM.rd(cppVar_65875);
	cppVar_65877 = cppVar_65759 & cppVar_65876;
	cppVar_65753 = cppVar_65877;
	} else {
	cppVar_65753 = SP;
	}
	cppVar_65749 = cppVar_65753;
	} else {
	cppVar_65879 = ROM.rd(PC);
	cppVar_65881 = (cppVar_65879 == 82);
	if (cppVar_65881) {
	cppVar_65884 = PC + 1;
	cppVar_65884 = (cppVar_65884 & cppMask_un_16_);
	cppVar_65885 = ROM.rd(cppVar_65884);
	cppVar_65887 = (cppVar_65885 == 129);
	if (cppVar_65887) {
	cppVar_65889 = PC + 1;
	cppVar_65889 = (cppVar_65889 & cppMask_un_16_);
	cppVar_65890 = ROM.rd(cppVar_65889);
	cppVar_65891 = (cppVar_65890 >> 7) & cppMask_un_1_;
	cppVar_65893 = (cppVar_65891 == 0);
	if (cppVar_65893) {
	cppVar_65894 = PC + 1;
	cppVar_65894 = (cppVar_65894 & cppMask_un_16_);
	cppVar_65895 = ROM.rd(cppVar_65894);
	cppVar_65896 = IRAM.rd(cppVar_65895);
	cppVar_65888 = cppVar_65896;
	} else {
	cppVar_65898 = PC + 1;
	cppVar_65898 = (cppVar_65898 & cppMask_un_16_);
	cppVar_65899 = ROM.rd(cppVar_65898);
	cppVar_65901 = (cppVar_65899 == 128);
	if (cppVar_65901) {
	cppVar_65897 = P0;
	} else {
	cppVar_65903 = PC + 1;
	cppVar_65903 = (cppVar_65903 & cppMask_un_16_);
	cppVar_65904 = ROM.rd(cppVar_65903);
	cppVar_65906 = (cppVar_65904 == 129);
	if (cppVar_65906) {
	cppVar_65902 = SP;
	} else {
	cppVar_65908 = PC + 1;
	cppVar_65908 = (cppVar_65908 & cppMask_un_16_);
	cppVar_65909 = ROM.rd(cppVar_65908);
	cppVar_65911 = (cppVar_65909 == 130);
	if (cppVar_65911) {
	cppVar_65907 = DPL;
	} else {
	cppVar_65913 = PC + 1;
	cppVar_65913 = (cppVar_65913 & cppMask_un_16_);
	cppVar_65914 = ROM.rd(cppVar_65913);
	cppVar_65916 = (cppVar_65914 == 131);
	if (cppVar_65916) {
	cppVar_65912 = DPH;
	} else {
	cppVar_65918 = PC + 1;
	cppVar_65918 = (cppVar_65918 & cppMask_un_16_);
	cppVar_65919 = ROM.rd(cppVar_65918);
	cppVar_65921 = (cppVar_65919 == 135);
	if (cppVar_65921) {
	cppVar_65917 = PCON;
	} else {
	cppVar_65923 = PC + 1;
	cppVar_65923 = (cppVar_65923 & cppMask_un_16_);
	cppVar_65924 = ROM.rd(cppVar_65923);
	cppVar_65926 = (cppVar_65924 == 136);
	if (cppVar_65926) {
	cppVar_65922 = TCON;
	} else {
	cppVar_65928 = PC + 1;
	cppVar_65928 = (cppVar_65928 & cppMask_un_16_);
	cppVar_65929 = ROM.rd(cppVar_65928);
	cppVar_65931 = (cppVar_65929 == 137);
	if (cppVar_65931) {
	cppVar_65927 = TMOD;
	} else {
	cppVar_65933 = PC + 1;
	cppVar_65933 = (cppVar_65933 & cppMask_un_16_);
	cppVar_65934 = ROM.rd(cppVar_65933);
	cppVar_65936 = (cppVar_65934 == 138);
	if (cppVar_65936) {
	cppVar_65932 = TL0;
	} else {
	cppVar_65938 = PC + 1;
	cppVar_65938 = (cppVar_65938 & cppMask_un_16_);
	cppVar_65939 = ROM.rd(cppVar_65938);
	cppVar_65941 = (cppVar_65939 == 140);
	if (cppVar_65941) {
	cppVar_65937 = TH0;
	} else {
	cppVar_65943 = PC + 1;
	cppVar_65943 = (cppVar_65943 & cppMask_un_16_);
	cppVar_65944 = ROM.rd(cppVar_65943);
	cppVar_65946 = (cppVar_65944 == 139);
	if (cppVar_65946) {
	cppVar_65942 = TL1;
	} else {
	cppVar_65948 = PC + 1;
	cppVar_65948 = (cppVar_65948 & cppMask_un_16_);
	cppVar_65949 = ROM.rd(cppVar_65948);
	cppVar_65951 = (cppVar_65949 == 141);
	if (cppVar_65951) {
	cppVar_65947 = TH1;
	} else {
	cppVar_65953 = PC + 1;
	cppVar_65953 = (cppVar_65953 & cppMask_un_16_);
	cppVar_65954 = ROM.rd(cppVar_65953);
	cppVar_65956 = (cppVar_65954 == 144);
	if (cppVar_65956) {
	cppVar_65952 = P1;
	} else {
	cppVar_65958 = PC + 1;
	cppVar_65958 = (cppVar_65958 & cppMask_un_16_);
	cppVar_65959 = ROM.rd(cppVar_65958);
	cppVar_65961 = (cppVar_65959 == 152);
	if (cppVar_65961) {
	cppVar_65957 = SCON;
	} else {
	cppVar_65963 = PC + 1;
	cppVar_65963 = (cppVar_65963 & cppMask_un_16_);
	cppVar_65964 = ROM.rd(cppVar_65963);
	cppVar_65966 = (cppVar_65964 == 153);
	if (cppVar_65966) {
	cppVar_65962 = SBUF;
	} else {
	cppVar_65968 = PC + 1;
	cppVar_65968 = (cppVar_65968 & cppMask_un_16_);
	cppVar_65969 = ROM.rd(cppVar_65968);
	cppVar_65971 = (cppVar_65969 == 160);
	if (cppVar_65971) {
	cppVar_65967 = P2;
	} else {
	cppVar_65973 = PC + 1;
	cppVar_65973 = (cppVar_65973 & cppMask_un_16_);
	cppVar_65974 = ROM.rd(cppVar_65973);
	cppVar_65976 = (cppVar_65974 == 168);
	if (cppVar_65976) {
	cppVar_65972 = IE;
	} else {
	cppVar_65978 = PC + 1;
	cppVar_65978 = (cppVar_65978 & cppMask_un_16_);
	cppVar_65979 = ROM.rd(cppVar_65978);
	cppVar_65981 = (cppVar_65979 == 176);
	if (cppVar_65981) {
	cppVar_65977 = P3;
	} else {
	cppVar_65983 = PC + 1;
	cppVar_65983 = (cppVar_65983 & cppMask_un_16_);
	cppVar_65984 = ROM.rd(cppVar_65983);
	cppVar_65986 = (cppVar_65984 == 184);
	if (cppVar_65986) {
	cppVar_65982 = IP;
	} else {
	cppVar_65988 = PC + 1;
	cppVar_65988 = (cppVar_65988 & cppMask_un_16_);
	cppVar_65989 = ROM.rd(cppVar_65988);
	cppVar_65991 = (cppVar_65989 == 208);
	if (cppVar_65991) {
	cppVar_65987 = PSW;
	} else {
	cppVar_65993 = PC + 1;
	cppVar_65993 = (cppVar_65993 & cppMask_un_16_);
	cppVar_65994 = ROM.rd(cppVar_65993);
	cppVar_65996 = (cppVar_65994 == 224);
	if (cppVar_65996) {
	cppVar_65992 = ACC;
	} else {
	cppVar_65998 = PC + 1;
	cppVar_65998 = (cppVar_65998 & cppMask_un_16_);
	cppVar_65999 = ROM.rd(cppVar_65998);
	cppVar_66001 = (cppVar_65999 == 240);
	if (cppVar_66001) {
	cppVar_65997 = B;
	} else {
	cppVar_65997 = 0;
	}
	cppVar_65992 = cppVar_65997;
	}
	cppVar_65987 = cppVar_65992;
	}
	cppVar_65982 = cppVar_65987;
	}
	cppVar_65977 = cppVar_65982;
	}
	cppVar_65972 = cppVar_65977;
	}
	cppVar_65967 = cppVar_65972;
	}
	cppVar_65962 = cppVar_65967;
	}
	cppVar_65957 = cppVar_65962;
	}
	cppVar_65952 = cppVar_65957;
	}
	cppVar_65947 = cppVar_65952;
	}
	cppVar_65942 = cppVar_65947;
	}
	cppVar_65937 = cppVar_65942;
	}
	cppVar_65932 = cppVar_65937;
	}
	cppVar_65927 = cppVar_65932;
	}
	cppVar_65922 = cppVar_65927;
	}
	cppVar_65917 = cppVar_65922;
	}
	cppVar_65912 = cppVar_65917;
	}
	cppVar_65907 = cppVar_65912;
	}
	cppVar_65902 = cppVar_65907;
	}
	cppVar_65897 = cppVar_65902;
	}
	cppVar_65888 = cppVar_65897;
	}
	cppVar_66003 = cppVar_65888 & ACC;
	cppVar_65882 = cppVar_66003;
	} else {
	cppVar_65882 = SP;
	}
	cppVar_65878 = cppVar_65882;
	} else {
	cppVar_66005 = ROM.rd(PC);
	cppVar_66007 = (cppVar_66005 == 67);
	if (cppVar_66007) {
	cppVar_66010 = PC + 1;
	cppVar_66010 = (cppVar_66010 & cppMask_un_16_);
	cppVar_66011 = ROM.rd(cppVar_66010);
	cppVar_66013 = (cppVar_66011 == 129);
	if (cppVar_66013) {
	cppVar_66015 = PC + 1;
	cppVar_66015 = (cppVar_66015 & cppMask_un_16_);
	cppVar_66016 = ROM.rd(cppVar_66015);
	cppVar_66017 = (cppVar_66016 >> 7) & cppMask_un_1_;
	cppVar_66019 = (cppVar_66017 == 0);
	if (cppVar_66019) {
	cppVar_66020 = PC + 1;
	cppVar_66020 = (cppVar_66020 & cppMask_un_16_);
	cppVar_66021 = ROM.rd(cppVar_66020);
	cppVar_66022 = IRAM.rd(cppVar_66021);
	cppVar_66014 = cppVar_66022;
	} else {
	cppVar_66024 = PC + 1;
	cppVar_66024 = (cppVar_66024 & cppMask_un_16_);
	cppVar_66025 = ROM.rd(cppVar_66024);
	cppVar_66027 = (cppVar_66025 == 128);
	if (cppVar_66027) {
	cppVar_66023 = P0;
	} else {
	cppVar_66029 = PC + 1;
	cppVar_66029 = (cppVar_66029 & cppMask_un_16_);
	cppVar_66030 = ROM.rd(cppVar_66029);
	cppVar_66032 = (cppVar_66030 == 129);
	if (cppVar_66032) {
	cppVar_66028 = SP;
	} else {
	cppVar_66034 = PC + 1;
	cppVar_66034 = (cppVar_66034 & cppMask_un_16_);
	cppVar_66035 = ROM.rd(cppVar_66034);
	cppVar_66037 = (cppVar_66035 == 130);
	if (cppVar_66037) {
	cppVar_66033 = DPL;
	} else {
	cppVar_66039 = PC + 1;
	cppVar_66039 = (cppVar_66039 & cppMask_un_16_);
	cppVar_66040 = ROM.rd(cppVar_66039);
	cppVar_66042 = (cppVar_66040 == 131);
	if (cppVar_66042) {
	cppVar_66038 = DPH;
	} else {
	cppVar_66044 = PC + 1;
	cppVar_66044 = (cppVar_66044 & cppMask_un_16_);
	cppVar_66045 = ROM.rd(cppVar_66044);
	cppVar_66047 = (cppVar_66045 == 135);
	if (cppVar_66047) {
	cppVar_66043 = PCON;
	} else {
	cppVar_66049 = PC + 1;
	cppVar_66049 = (cppVar_66049 & cppMask_un_16_);
	cppVar_66050 = ROM.rd(cppVar_66049);
	cppVar_66052 = (cppVar_66050 == 136);
	if (cppVar_66052) {
	cppVar_66048 = TCON;
	} else {
	cppVar_66054 = PC + 1;
	cppVar_66054 = (cppVar_66054 & cppMask_un_16_);
	cppVar_66055 = ROM.rd(cppVar_66054);
	cppVar_66057 = (cppVar_66055 == 137);
	if (cppVar_66057) {
	cppVar_66053 = TMOD;
	} else {
	cppVar_66059 = PC + 1;
	cppVar_66059 = (cppVar_66059 & cppMask_un_16_);
	cppVar_66060 = ROM.rd(cppVar_66059);
	cppVar_66062 = (cppVar_66060 == 138);
	if (cppVar_66062) {
	cppVar_66058 = TL0;
	} else {
	cppVar_66064 = PC + 1;
	cppVar_66064 = (cppVar_66064 & cppMask_un_16_);
	cppVar_66065 = ROM.rd(cppVar_66064);
	cppVar_66067 = (cppVar_66065 == 140);
	if (cppVar_66067) {
	cppVar_66063 = TH0;
	} else {
	cppVar_66069 = PC + 1;
	cppVar_66069 = (cppVar_66069 & cppMask_un_16_);
	cppVar_66070 = ROM.rd(cppVar_66069);
	cppVar_66072 = (cppVar_66070 == 139);
	if (cppVar_66072) {
	cppVar_66068 = TL1;
	} else {
	cppVar_66074 = PC + 1;
	cppVar_66074 = (cppVar_66074 & cppMask_un_16_);
	cppVar_66075 = ROM.rd(cppVar_66074);
	cppVar_66077 = (cppVar_66075 == 141);
	if (cppVar_66077) {
	cppVar_66073 = TH1;
	} else {
	cppVar_66079 = PC + 1;
	cppVar_66079 = (cppVar_66079 & cppMask_un_16_);
	cppVar_66080 = ROM.rd(cppVar_66079);
	cppVar_66082 = (cppVar_66080 == 144);
	if (cppVar_66082) {
	cppVar_66078 = P1;
	} else {
	cppVar_66084 = PC + 1;
	cppVar_66084 = (cppVar_66084 & cppMask_un_16_);
	cppVar_66085 = ROM.rd(cppVar_66084);
	cppVar_66087 = (cppVar_66085 == 152);
	if (cppVar_66087) {
	cppVar_66083 = SCON;
	} else {
	cppVar_66089 = PC + 1;
	cppVar_66089 = (cppVar_66089 & cppMask_un_16_);
	cppVar_66090 = ROM.rd(cppVar_66089);
	cppVar_66092 = (cppVar_66090 == 153);
	if (cppVar_66092) {
	cppVar_66088 = SBUF;
	} else {
	cppVar_66094 = PC + 1;
	cppVar_66094 = (cppVar_66094 & cppMask_un_16_);
	cppVar_66095 = ROM.rd(cppVar_66094);
	cppVar_66097 = (cppVar_66095 == 160);
	if (cppVar_66097) {
	cppVar_66093 = P2;
	} else {
	cppVar_66099 = PC + 1;
	cppVar_66099 = (cppVar_66099 & cppMask_un_16_);
	cppVar_66100 = ROM.rd(cppVar_66099);
	cppVar_66102 = (cppVar_66100 == 168);
	if (cppVar_66102) {
	cppVar_66098 = IE;
	} else {
	cppVar_66104 = PC + 1;
	cppVar_66104 = (cppVar_66104 & cppMask_un_16_);
	cppVar_66105 = ROM.rd(cppVar_66104);
	cppVar_66107 = (cppVar_66105 == 176);
	if (cppVar_66107) {
	cppVar_66103 = P3;
	} else {
	cppVar_66109 = PC + 1;
	cppVar_66109 = (cppVar_66109 & cppMask_un_16_);
	cppVar_66110 = ROM.rd(cppVar_66109);
	cppVar_66112 = (cppVar_66110 == 184);
	if (cppVar_66112) {
	cppVar_66108 = IP;
	} else {
	cppVar_66114 = PC + 1;
	cppVar_66114 = (cppVar_66114 & cppMask_un_16_);
	cppVar_66115 = ROM.rd(cppVar_66114);
	cppVar_66117 = (cppVar_66115 == 208);
	if (cppVar_66117) {
	cppVar_66113 = PSW;
	} else {
	cppVar_66119 = PC + 1;
	cppVar_66119 = (cppVar_66119 & cppMask_un_16_);
	cppVar_66120 = ROM.rd(cppVar_66119);
	cppVar_66122 = (cppVar_66120 == 224);
	if (cppVar_66122) {
	cppVar_66118 = ACC;
	} else {
	cppVar_66124 = PC + 1;
	cppVar_66124 = (cppVar_66124 & cppMask_un_16_);
	cppVar_66125 = ROM.rd(cppVar_66124);
	cppVar_66127 = (cppVar_66125 == 240);
	if (cppVar_66127) {
	cppVar_66123 = B;
	} else {
	cppVar_66123 = 0;
	}
	cppVar_66118 = cppVar_66123;
	}
	cppVar_66113 = cppVar_66118;
	}
	cppVar_66108 = cppVar_66113;
	}
	cppVar_66103 = cppVar_66108;
	}
	cppVar_66098 = cppVar_66103;
	}
	cppVar_66093 = cppVar_66098;
	}
	cppVar_66088 = cppVar_66093;
	}
	cppVar_66083 = cppVar_66088;
	}
	cppVar_66078 = cppVar_66083;
	}
	cppVar_66073 = cppVar_66078;
	}
	cppVar_66068 = cppVar_66073;
	}
	cppVar_66063 = cppVar_66068;
	}
	cppVar_66058 = cppVar_66063;
	}
	cppVar_66053 = cppVar_66058;
	}
	cppVar_66048 = cppVar_66053;
	}
	cppVar_66043 = cppVar_66048;
	}
	cppVar_66038 = cppVar_66043;
	}
	cppVar_66033 = cppVar_66038;
	}
	cppVar_66028 = cppVar_66033;
	}
	cppVar_66023 = cppVar_66028;
	}
	cppVar_66014 = cppVar_66023;
	}
	cppVar_66130 = PC + 2;
	cppVar_66130 = (cppVar_66130 & cppMask_un_16_);
	cppVar_66131 = ROM.rd(cppVar_66130);
	cppVar_66132 = cppVar_66014 | cppVar_66131;
	cppVar_66008 = cppVar_66132;
	} else {
	cppVar_66008 = SP;
	}
	cppVar_66004 = cppVar_66008;
	} else {
	cppVar_66134 = ROM.rd(PC);
	cppVar_66136 = (cppVar_66134 == 66);
	if (cppVar_66136) {
	cppVar_66139 = PC + 1;
	cppVar_66139 = (cppVar_66139 & cppMask_un_16_);
	cppVar_66140 = ROM.rd(cppVar_66139);
	cppVar_66142 = (cppVar_66140 == 129);
	if (cppVar_66142) {
	cppVar_66144 = PC + 1;
	cppVar_66144 = (cppVar_66144 & cppMask_un_16_);
	cppVar_66145 = ROM.rd(cppVar_66144);
	cppVar_66146 = (cppVar_66145 >> 7) & cppMask_un_1_;
	cppVar_66148 = (cppVar_66146 == 0);
	if (cppVar_66148) {
	cppVar_66149 = PC + 1;
	cppVar_66149 = (cppVar_66149 & cppMask_un_16_);
	cppVar_66150 = ROM.rd(cppVar_66149);
	cppVar_66151 = IRAM.rd(cppVar_66150);
	cppVar_66143 = cppVar_66151;
	} else {
	cppVar_66153 = PC + 1;
	cppVar_66153 = (cppVar_66153 & cppMask_un_16_);
	cppVar_66154 = ROM.rd(cppVar_66153);
	cppVar_66156 = (cppVar_66154 == 128);
	if (cppVar_66156) {
	cppVar_66152 = P0;
	} else {
	cppVar_66158 = PC + 1;
	cppVar_66158 = (cppVar_66158 & cppMask_un_16_);
	cppVar_66159 = ROM.rd(cppVar_66158);
	cppVar_66161 = (cppVar_66159 == 129);
	if (cppVar_66161) {
	cppVar_66157 = SP;
	} else {
	cppVar_66163 = PC + 1;
	cppVar_66163 = (cppVar_66163 & cppMask_un_16_);
	cppVar_66164 = ROM.rd(cppVar_66163);
	cppVar_66166 = (cppVar_66164 == 130);
	if (cppVar_66166) {
	cppVar_66162 = DPL;
	} else {
	cppVar_66168 = PC + 1;
	cppVar_66168 = (cppVar_66168 & cppMask_un_16_);
	cppVar_66169 = ROM.rd(cppVar_66168);
	cppVar_66171 = (cppVar_66169 == 131);
	if (cppVar_66171) {
	cppVar_66167 = DPH;
	} else {
	cppVar_66173 = PC + 1;
	cppVar_66173 = (cppVar_66173 & cppMask_un_16_);
	cppVar_66174 = ROM.rd(cppVar_66173);
	cppVar_66176 = (cppVar_66174 == 135);
	if (cppVar_66176) {
	cppVar_66172 = PCON;
	} else {
	cppVar_66178 = PC + 1;
	cppVar_66178 = (cppVar_66178 & cppMask_un_16_);
	cppVar_66179 = ROM.rd(cppVar_66178);
	cppVar_66181 = (cppVar_66179 == 136);
	if (cppVar_66181) {
	cppVar_66177 = TCON;
	} else {
	cppVar_66183 = PC + 1;
	cppVar_66183 = (cppVar_66183 & cppMask_un_16_);
	cppVar_66184 = ROM.rd(cppVar_66183);
	cppVar_66186 = (cppVar_66184 == 137);
	if (cppVar_66186) {
	cppVar_66182 = TMOD;
	} else {
	cppVar_66188 = PC + 1;
	cppVar_66188 = (cppVar_66188 & cppMask_un_16_);
	cppVar_66189 = ROM.rd(cppVar_66188);
	cppVar_66191 = (cppVar_66189 == 138);
	if (cppVar_66191) {
	cppVar_66187 = TL0;
	} else {
	cppVar_66193 = PC + 1;
	cppVar_66193 = (cppVar_66193 & cppMask_un_16_);
	cppVar_66194 = ROM.rd(cppVar_66193);
	cppVar_66196 = (cppVar_66194 == 140);
	if (cppVar_66196) {
	cppVar_66192 = TH0;
	} else {
	cppVar_66198 = PC + 1;
	cppVar_66198 = (cppVar_66198 & cppMask_un_16_);
	cppVar_66199 = ROM.rd(cppVar_66198);
	cppVar_66201 = (cppVar_66199 == 139);
	if (cppVar_66201) {
	cppVar_66197 = TL1;
	} else {
	cppVar_66203 = PC + 1;
	cppVar_66203 = (cppVar_66203 & cppMask_un_16_);
	cppVar_66204 = ROM.rd(cppVar_66203);
	cppVar_66206 = (cppVar_66204 == 141);
	if (cppVar_66206) {
	cppVar_66202 = TH1;
	} else {
	cppVar_66208 = PC + 1;
	cppVar_66208 = (cppVar_66208 & cppMask_un_16_);
	cppVar_66209 = ROM.rd(cppVar_66208);
	cppVar_66211 = (cppVar_66209 == 144);
	if (cppVar_66211) {
	cppVar_66207 = P1;
	} else {
	cppVar_66213 = PC + 1;
	cppVar_66213 = (cppVar_66213 & cppMask_un_16_);
	cppVar_66214 = ROM.rd(cppVar_66213);
	cppVar_66216 = (cppVar_66214 == 152);
	if (cppVar_66216) {
	cppVar_66212 = SCON;
	} else {
	cppVar_66218 = PC + 1;
	cppVar_66218 = (cppVar_66218 & cppMask_un_16_);
	cppVar_66219 = ROM.rd(cppVar_66218);
	cppVar_66221 = (cppVar_66219 == 153);
	if (cppVar_66221) {
	cppVar_66217 = SBUF;
	} else {
	cppVar_66223 = PC + 1;
	cppVar_66223 = (cppVar_66223 & cppMask_un_16_);
	cppVar_66224 = ROM.rd(cppVar_66223);
	cppVar_66226 = (cppVar_66224 == 160);
	if (cppVar_66226) {
	cppVar_66222 = P2;
	} else {
	cppVar_66228 = PC + 1;
	cppVar_66228 = (cppVar_66228 & cppMask_un_16_);
	cppVar_66229 = ROM.rd(cppVar_66228);
	cppVar_66231 = (cppVar_66229 == 168);
	if (cppVar_66231) {
	cppVar_66227 = IE;
	} else {
	cppVar_66233 = PC + 1;
	cppVar_66233 = (cppVar_66233 & cppMask_un_16_);
	cppVar_66234 = ROM.rd(cppVar_66233);
	cppVar_66236 = (cppVar_66234 == 176);
	if (cppVar_66236) {
	cppVar_66232 = P3;
	} else {
	cppVar_66238 = PC + 1;
	cppVar_66238 = (cppVar_66238 & cppMask_un_16_);
	cppVar_66239 = ROM.rd(cppVar_66238);
	cppVar_66241 = (cppVar_66239 == 184);
	if (cppVar_66241) {
	cppVar_66237 = IP;
	} else {
	cppVar_66243 = PC + 1;
	cppVar_66243 = (cppVar_66243 & cppMask_un_16_);
	cppVar_66244 = ROM.rd(cppVar_66243);
	cppVar_66246 = (cppVar_66244 == 208);
	if (cppVar_66246) {
	cppVar_66242 = PSW;
	} else {
	cppVar_66248 = PC + 1;
	cppVar_66248 = (cppVar_66248 & cppMask_un_16_);
	cppVar_66249 = ROM.rd(cppVar_66248);
	cppVar_66251 = (cppVar_66249 == 224);
	if (cppVar_66251) {
	cppVar_66247 = ACC;
	} else {
	cppVar_66253 = PC + 1;
	cppVar_66253 = (cppVar_66253 & cppMask_un_16_);
	cppVar_66254 = ROM.rd(cppVar_66253);
	cppVar_66256 = (cppVar_66254 == 240);
	if (cppVar_66256) {
	cppVar_66252 = B;
	} else {
	cppVar_66252 = 0;
	}
	cppVar_66247 = cppVar_66252;
	}
	cppVar_66242 = cppVar_66247;
	}
	cppVar_66237 = cppVar_66242;
	}
	cppVar_66232 = cppVar_66237;
	}
	cppVar_66227 = cppVar_66232;
	}
	cppVar_66222 = cppVar_66227;
	}
	cppVar_66217 = cppVar_66222;
	}
	cppVar_66212 = cppVar_66217;
	}
	cppVar_66207 = cppVar_66212;
	}
	cppVar_66202 = cppVar_66207;
	}
	cppVar_66197 = cppVar_66202;
	}
	cppVar_66192 = cppVar_66197;
	}
	cppVar_66187 = cppVar_66192;
	}
	cppVar_66182 = cppVar_66187;
	}
	cppVar_66177 = cppVar_66182;
	}
	cppVar_66172 = cppVar_66177;
	}
	cppVar_66167 = cppVar_66172;
	}
	cppVar_66162 = cppVar_66167;
	}
	cppVar_66157 = cppVar_66162;
	}
	cppVar_66152 = cppVar_66157;
	}
	cppVar_66143 = cppVar_66152;
	}
	cppVar_66258 = cppVar_66143 | ACC;
	cppVar_66137 = cppVar_66258;
	} else {
	cppVar_66137 = SP;
	}
	cppVar_66133 = cppVar_66137;
	} else {
	cppVar_66260 = ROM.rd(PC);
	cppVar_66262 = (cppVar_66260 == 50);
	cppVar_66263 = ROM.rd(PC);
	cppVar_66265 = (cppVar_66263 == 34);
	cppVar_66266 = cppVar_66262 || cppVar_66265;
	if (cppVar_66266) {
	cppVar_66268 = SP - 2;
	cppVar_66268 = (cppVar_66268 & cppMask_un_8_);
	cppVar_66259 = cppVar_66268;
	} else {
	cppVar_66270 = ROM.rd(PC);
	cppVar_66272 = (cppVar_66270 == 213);
	cppVar_66273 = ROM.rd(PC);
	cppVar_66275 = (cppVar_66273 == 21);
	cppVar_66276 = cppVar_66272 || cppVar_66275;
	if (cppVar_66276) {
	cppVar_66279 = PC + 1;
	cppVar_66279 = (cppVar_66279 & cppMask_un_16_);
	cppVar_66280 = ROM.rd(cppVar_66279);
	cppVar_66282 = (cppVar_66280 == 129);
	if (cppVar_66282) {
	cppVar_66284 = PC + 1;
	cppVar_66284 = (cppVar_66284 & cppMask_un_16_);
	cppVar_66285 = ROM.rd(cppVar_66284);
	cppVar_66286 = (cppVar_66285 >> 7) & cppMask_un_1_;
	cppVar_66288 = (cppVar_66286 == 0);
	if (cppVar_66288) {
	cppVar_66289 = PC + 1;
	cppVar_66289 = (cppVar_66289 & cppMask_un_16_);
	cppVar_66290 = ROM.rd(cppVar_66289);
	cppVar_66291 = IRAM.rd(cppVar_66290);
	cppVar_66283 = cppVar_66291;
	} else {
	cppVar_66293 = PC + 1;
	cppVar_66293 = (cppVar_66293 & cppMask_un_16_);
	cppVar_66294 = ROM.rd(cppVar_66293);
	cppVar_66296 = (cppVar_66294 == 128);
	if (cppVar_66296) {
	cppVar_66292 = P0;
	} else {
	cppVar_66298 = PC + 1;
	cppVar_66298 = (cppVar_66298 & cppMask_un_16_);
	cppVar_66299 = ROM.rd(cppVar_66298);
	cppVar_66301 = (cppVar_66299 == 129);
	if (cppVar_66301) {
	cppVar_66297 = SP;
	} else {
	cppVar_66303 = PC + 1;
	cppVar_66303 = (cppVar_66303 & cppMask_un_16_);
	cppVar_66304 = ROM.rd(cppVar_66303);
	cppVar_66306 = (cppVar_66304 == 130);
	if (cppVar_66306) {
	cppVar_66302 = DPL;
	} else {
	cppVar_66308 = PC + 1;
	cppVar_66308 = (cppVar_66308 & cppMask_un_16_);
	cppVar_66309 = ROM.rd(cppVar_66308);
	cppVar_66311 = (cppVar_66309 == 131);
	if (cppVar_66311) {
	cppVar_66307 = DPH;
	} else {
	cppVar_66313 = PC + 1;
	cppVar_66313 = (cppVar_66313 & cppMask_un_16_);
	cppVar_66314 = ROM.rd(cppVar_66313);
	cppVar_66316 = (cppVar_66314 == 135);
	if (cppVar_66316) {
	cppVar_66312 = PCON;
	} else {
	cppVar_66318 = PC + 1;
	cppVar_66318 = (cppVar_66318 & cppMask_un_16_);
	cppVar_66319 = ROM.rd(cppVar_66318);
	cppVar_66321 = (cppVar_66319 == 136);
	if (cppVar_66321) {
	cppVar_66317 = TCON;
	} else {
	cppVar_66323 = PC + 1;
	cppVar_66323 = (cppVar_66323 & cppMask_un_16_);
	cppVar_66324 = ROM.rd(cppVar_66323);
	cppVar_66326 = (cppVar_66324 == 137);
	if (cppVar_66326) {
	cppVar_66322 = TMOD;
	} else {
	cppVar_66328 = PC + 1;
	cppVar_66328 = (cppVar_66328 & cppMask_un_16_);
	cppVar_66329 = ROM.rd(cppVar_66328);
	cppVar_66331 = (cppVar_66329 == 138);
	if (cppVar_66331) {
	cppVar_66327 = TL0;
	} else {
	cppVar_66333 = PC + 1;
	cppVar_66333 = (cppVar_66333 & cppMask_un_16_);
	cppVar_66334 = ROM.rd(cppVar_66333);
	cppVar_66336 = (cppVar_66334 == 140);
	if (cppVar_66336) {
	cppVar_66332 = TH0;
	} else {
	cppVar_66338 = PC + 1;
	cppVar_66338 = (cppVar_66338 & cppMask_un_16_);
	cppVar_66339 = ROM.rd(cppVar_66338);
	cppVar_66341 = (cppVar_66339 == 139);
	if (cppVar_66341) {
	cppVar_66337 = TL1;
	} else {
	cppVar_66343 = PC + 1;
	cppVar_66343 = (cppVar_66343 & cppMask_un_16_);
	cppVar_66344 = ROM.rd(cppVar_66343);
	cppVar_66346 = (cppVar_66344 == 141);
	if (cppVar_66346) {
	cppVar_66342 = TH1;
	} else {
	cppVar_66348 = PC + 1;
	cppVar_66348 = (cppVar_66348 & cppMask_un_16_);
	cppVar_66349 = ROM.rd(cppVar_66348);
	cppVar_66351 = (cppVar_66349 == 144);
	if (cppVar_66351) {
	cppVar_66347 = P1;
	} else {
	cppVar_66353 = PC + 1;
	cppVar_66353 = (cppVar_66353 & cppMask_un_16_);
	cppVar_66354 = ROM.rd(cppVar_66353);
	cppVar_66356 = (cppVar_66354 == 152);
	if (cppVar_66356) {
	cppVar_66352 = SCON;
	} else {
	cppVar_66358 = PC + 1;
	cppVar_66358 = (cppVar_66358 & cppMask_un_16_);
	cppVar_66359 = ROM.rd(cppVar_66358);
	cppVar_66361 = (cppVar_66359 == 153);
	if (cppVar_66361) {
	cppVar_66357 = SBUF;
	} else {
	cppVar_66363 = PC + 1;
	cppVar_66363 = (cppVar_66363 & cppMask_un_16_);
	cppVar_66364 = ROM.rd(cppVar_66363);
	cppVar_66366 = (cppVar_66364 == 160);
	if (cppVar_66366) {
	cppVar_66362 = P2;
	} else {
	cppVar_66368 = PC + 1;
	cppVar_66368 = (cppVar_66368 & cppMask_un_16_);
	cppVar_66369 = ROM.rd(cppVar_66368);
	cppVar_66371 = (cppVar_66369 == 168);
	if (cppVar_66371) {
	cppVar_66367 = IE;
	} else {
	cppVar_66373 = PC + 1;
	cppVar_66373 = (cppVar_66373 & cppMask_un_16_);
	cppVar_66374 = ROM.rd(cppVar_66373);
	cppVar_66376 = (cppVar_66374 == 176);
	if (cppVar_66376) {
	cppVar_66372 = P3;
	} else {
	cppVar_66378 = PC + 1;
	cppVar_66378 = (cppVar_66378 & cppMask_un_16_);
	cppVar_66379 = ROM.rd(cppVar_66378);
	cppVar_66381 = (cppVar_66379 == 184);
	if (cppVar_66381) {
	cppVar_66377 = IP;
	} else {
	cppVar_66383 = PC + 1;
	cppVar_66383 = (cppVar_66383 & cppMask_un_16_);
	cppVar_66384 = ROM.rd(cppVar_66383);
	cppVar_66386 = (cppVar_66384 == 208);
	if (cppVar_66386) {
	cppVar_66382 = PSW;
	} else {
	cppVar_66388 = PC + 1;
	cppVar_66388 = (cppVar_66388 & cppMask_un_16_);
	cppVar_66389 = ROM.rd(cppVar_66388);
	cppVar_66391 = (cppVar_66389 == 224);
	if (cppVar_66391) {
	cppVar_66387 = ACC;
	} else {
	cppVar_66393 = PC + 1;
	cppVar_66393 = (cppVar_66393 & cppMask_un_16_);
	cppVar_66394 = ROM.rd(cppVar_66393);
	cppVar_66396 = (cppVar_66394 == 240);
	if (cppVar_66396) {
	cppVar_66392 = B;
	} else {
	cppVar_66392 = 0;
	}
	cppVar_66387 = cppVar_66392;
	}
	cppVar_66382 = cppVar_66387;
	}
	cppVar_66377 = cppVar_66382;
	}
	cppVar_66372 = cppVar_66377;
	}
	cppVar_66367 = cppVar_66372;
	}
	cppVar_66362 = cppVar_66367;
	}
	cppVar_66357 = cppVar_66362;
	}
	cppVar_66352 = cppVar_66357;
	}
	cppVar_66347 = cppVar_66352;
	}
	cppVar_66342 = cppVar_66347;
	}
	cppVar_66337 = cppVar_66342;
	}
	cppVar_66332 = cppVar_66337;
	}
	cppVar_66327 = cppVar_66332;
	}
	cppVar_66322 = cppVar_66327;
	}
	cppVar_66317 = cppVar_66322;
	}
	cppVar_66312 = cppVar_66317;
	}
	cppVar_66307 = cppVar_66312;
	}
	cppVar_66302 = cppVar_66307;
	}
	cppVar_66297 = cppVar_66302;
	}
	cppVar_66292 = cppVar_66297;
	}
	cppVar_66283 = cppVar_66292;
	}
	cppVar_66399 = cppVar_66283 - 1;
	cppVar_66399 = (cppVar_66399 & cppMask_un_8_);
	cppVar_66277 = cppVar_66399;
	} else {
	cppVar_66277 = SP;
	}
	cppVar_66269 = cppVar_66277;
	} else {
	cppVar_66401 = ROM.rd(PC);
	cppVar_66403 = (cppVar_66401 == 241);
	cppVar_66404 = ROM.rd(PC);
	cppVar_66406 = (cppVar_66404 == 209);
	cppVar_66407 = ROM.rd(PC);
	cppVar_66409 = (cppVar_66407 == 177);
	cppVar_66410 = ROM.rd(PC);
	cppVar_66412 = (cppVar_66410 == 145);
	cppVar_66413 = ROM.rd(PC);
	cppVar_66415 = (cppVar_66413 == 113);
	cppVar_66416 = ROM.rd(PC);
	cppVar_66418 = (cppVar_66416 == 81);
	cppVar_66419 = ROM.rd(PC);
	cppVar_66421 = (cppVar_66419 == 49);
	cppVar_66422 = ROM.rd(PC);
	cppVar_66424 = (cppVar_66422 == 18);
	cppVar_66425 = ROM.rd(PC);
	cppVar_66427 = (cppVar_66425 == 17);
	cppVar_66428 = cppVar_66424 || cppVar_66427;
	cppVar_66429 = cppVar_66421 || cppVar_66428;
	cppVar_66430 = cppVar_66418 || cppVar_66429;
	cppVar_66431 = cppVar_66415 || cppVar_66430;
	cppVar_66432 = cppVar_66412 || cppVar_66431;
	cppVar_66433 = cppVar_66409 || cppVar_66432;
	cppVar_66434 = cppVar_66406 || cppVar_66433;
	cppVar_66435 = cppVar_66403 || cppVar_66434;
	if (cppVar_66435) {
	cppVar_66437 = SP + 2;
	cppVar_66437 = (cppVar_66437 & cppMask_un_8_);
	cppVar_66400 = cppVar_66437;
	} else {
	cppVar_66439 = ROM.rd(PC);
	cppVar_66441 = (cppVar_66439 == 5);
	if (cppVar_66441) {
	cppVar_66444 = PC + 1;
	cppVar_66444 = (cppVar_66444 & cppMask_un_16_);
	cppVar_66445 = ROM.rd(cppVar_66444);
	cppVar_66447 = (cppVar_66445 == 129);
	if (cppVar_66447) {
	cppVar_66449 = PC + 1;
	cppVar_66449 = (cppVar_66449 & cppMask_un_16_);
	cppVar_66450 = ROM.rd(cppVar_66449);
	cppVar_66451 = (cppVar_66450 >> 7) & cppMask_un_1_;
	cppVar_66453 = (cppVar_66451 == 0);
	if (cppVar_66453) {
	cppVar_66454 = PC + 1;
	cppVar_66454 = (cppVar_66454 & cppMask_un_16_);
	cppVar_66455 = ROM.rd(cppVar_66454);
	cppVar_66456 = IRAM.rd(cppVar_66455);
	cppVar_66448 = cppVar_66456;
	} else {
	cppVar_66458 = PC + 1;
	cppVar_66458 = (cppVar_66458 & cppMask_un_16_);
	cppVar_66459 = ROM.rd(cppVar_66458);
	cppVar_66461 = (cppVar_66459 == 128);
	if (cppVar_66461) {
	cppVar_66457 = P0;
	} else {
	cppVar_66463 = PC + 1;
	cppVar_66463 = (cppVar_66463 & cppMask_un_16_);
	cppVar_66464 = ROM.rd(cppVar_66463);
	cppVar_66466 = (cppVar_66464 == 129);
	if (cppVar_66466) {
	cppVar_66462 = SP;
	} else {
	cppVar_66468 = PC + 1;
	cppVar_66468 = (cppVar_66468 & cppMask_un_16_);
	cppVar_66469 = ROM.rd(cppVar_66468);
	cppVar_66471 = (cppVar_66469 == 130);
	if (cppVar_66471) {
	cppVar_66467 = DPL;
	} else {
	cppVar_66473 = PC + 1;
	cppVar_66473 = (cppVar_66473 & cppMask_un_16_);
	cppVar_66474 = ROM.rd(cppVar_66473);
	cppVar_66476 = (cppVar_66474 == 131);
	if (cppVar_66476) {
	cppVar_66472 = DPH;
	} else {
	cppVar_66478 = PC + 1;
	cppVar_66478 = (cppVar_66478 & cppMask_un_16_);
	cppVar_66479 = ROM.rd(cppVar_66478);
	cppVar_66481 = (cppVar_66479 == 135);
	if (cppVar_66481) {
	cppVar_66477 = PCON;
	} else {
	cppVar_66483 = PC + 1;
	cppVar_66483 = (cppVar_66483 & cppMask_un_16_);
	cppVar_66484 = ROM.rd(cppVar_66483);
	cppVar_66486 = (cppVar_66484 == 136);
	if (cppVar_66486) {
	cppVar_66482 = TCON;
	} else {
	cppVar_66488 = PC + 1;
	cppVar_66488 = (cppVar_66488 & cppMask_un_16_);
	cppVar_66489 = ROM.rd(cppVar_66488);
	cppVar_66491 = (cppVar_66489 == 137);
	if (cppVar_66491) {
	cppVar_66487 = TMOD;
	} else {
	cppVar_66493 = PC + 1;
	cppVar_66493 = (cppVar_66493 & cppMask_un_16_);
	cppVar_66494 = ROM.rd(cppVar_66493);
	cppVar_66496 = (cppVar_66494 == 138);
	if (cppVar_66496) {
	cppVar_66492 = TL0;
	} else {
	cppVar_66498 = PC + 1;
	cppVar_66498 = (cppVar_66498 & cppMask_un_16_);
	cppVar_66499 = ROM.rd(cppVar_66498);
	cppVar_66501 = (cppVar_66499 == 140);
	if (cppVar_66501) {
	cppVar_66497 = TH0;
	} else {
	cppVar_66503 = PC + 1;
	cppVar_66503 = (cppVar_66503 & cppMask_un_16_);
	cppVar_66504 = ROM.rd(cppVar_66503);
	cppVar_66506 = (cppVar_66504 == 139);
	if (cppVar_66506) {
	cppVar_66502 = TL1;
	} else {
	cppVar_66508 = PC + 1;
	cppVar_66508 = (cppVar_66508 & cppMask_un_16_);
	cppVar_66509 = ROM.rd(cppVar_66508);
	cppVar_66511 = (cppVar_66509 == 141);
	if (cppVar_66511) {
	cppVar_66507 = TH1;
	} else {
	cppVar_66513 = PC + 1;
	cppVar_66513 = (cppVar_66513 & cppMask_un_16_);
	cppVar_66514 = ROM.rd(cppVar_66513);
	cppVar_66516 = (cppVar_66514 == 144);
	if (cppVar_66516) {
	cppVar_66512 = P1;
	} else {
	cppVar_66518 = PC + 1;
	cppVar_66518 = (cppVar_66518 & cppMask_un_16_);
	cppVar_66519 = ROM.rd(cppVar_66518);
	cppVar_66521 = (cppVar_66519 == 152);
	if (cppVar_66521) {
	cppVar_66517 = SCON;
	} else {
	cppVar_66523 = PC + 1;
	cppVar_66523 = (cppVar_66523 & cppMask_un_16_);
	cppVar_66524 = ROM.rd(cppVar_66523);
	cppVar_66526 = (cppVar_66524 == 153);
	if (cppVar_66526) {
	cppVar_66522 = SBUF;
	} else {
	cppVar_66528 = PC + 1;
	cppVar_66528 = (cppVar_66528 & cppMask_un_16_);
	cppVar_66529 = ROM.rd(cppVar_66528);
	cppVar_66531 = (cppVar_66529 == 160);
	if (cppVar_66531) {
	cppVar_66527 = P2;
	} else {
	cppVar_66533 = PC + 1;
	cppVar_66533 = (cppVar_66533 & cppMask_un_16_);
	cppVar_66534 = ROM.rd(cppVar_66533);
	cppVar_66536 = (cppVar_66534 == 168);
	if (cppVar_66536) {
	cppVar_66532 = IE;
	} else {
	cppVar_66538 = PC + 1;
	cppVar_66538 = (cppVar_66538 & cppMask_un_16_);
	cppVar_66539 = ROM.rd(cppVar_66538);
	cppVar_66541 = (cppVar_66539 == 176);
	if (cppVar_66541) {
	cppVar_66537 = P3;
	} else {
	cppVar_66543 = PC + 1;
	cppVar_66543 = (cppVar_66543 & cppMask_un_16_);
	cppVar_66544 = ROM.rd(cppVar_66543);
	cppVar_66546 = (cppVar_66544 == 184);
	if (cppVar_66546) {
	cppVar_66542 = IP;
	} else {
	cppVar_66548 = PC + 1;
	cppVar_66548 = (cppVar_66548 & cppMask_un_16_);
	cppVar_66549 = ROM.rd(cppVar_66548);
	cppVar_66551 = (cppVar_66549 == 208);
	if (cppVar_66551) {
	cppVar_66547 = PSW;
	} else {
	cppVar_66553 = PC + 1;
	cppVar_66553 = (cppVar_66553 & cppMask_un_16_);
	cppVar_66554 = ROM.rd(cppVar_66553);
	cppVar_66556 = (cppVar_66554 == 224);
	if (cppVar_66556) {
	cppVar_66552 = ACC;
	} else {
	cppVar_66558 = PC + 1;
	cppVar_66558 = (cppVar_66558 & cppMask_un_16_);
	cppVar_66559 = ROM.rd(cppVar_66558);
	cppVar_66561 = (cppVar_66559 == 240);
	if (cppVar_66561) {
	cppVar_66557 = B;
	} else {
	cppVar_66557 = 0;
	}
	cppVar_66552 = cppVar_66557;
	}
	cppVar_66547 = cppVar_66552;
	}
	cppVar_66542 = cppVar_66547;
	}
	cppVar_66537 = cppVar_66542;
	}
	cppVar_66532 = cppVar_66537;
	}
	cppVar_66527 = cppVar_66532;
	}
	cppVar_66522 = cppVar_66527;
	}
	cppVar_66517 = cppVar_66522;
	}
	cppVar_66512 = cppVar_66517;
	}
	cppVar_66507 = cppVar_66512;
	}
	cppVar_66502 = cppVar_66507;
	}
	cppVar_66497 = cppVar_66502;
	}
	cppVar_66492 = cppVar_66497;
	}
	cppVar_66487 = cppVar_66492;
	}
	cppVar_66482 = cppVar_66487;
	}
	cppVar_66477 = cppVar_66482;
	}
	cppVar_66472 = cppVar_66477;
	}
	cppVar_66467 = cppVar_66472;
	}
	cppVar_66462 = cppVar_66467;
	}
	cppVar_66457 = cppVar_66462;
	}
	cppVar_66448 = cppVar_66457;
	}
	cppVar_66564 = cppVar_66448 + 1;
	cppVar_66564 = (cppVar_66564 & cppMask_un_8_);
	cppVar_66442 = cppVar_66564;
	} else {
	cppVar_66442 = SP;
	}
	cppVar_66438 = cppVar_66442;
	} else {
	cppVar_66566 = ROM.rd(PC);
	cppVar_66568 = (cppVar_66566 == 255);
	cppVar_66569 = ROM.rd(PC);
	cppVar_66571 = (cppVar_66569 == 254);
	cppVar_66572 = ROM.rd(PC);
	cppVar_66574 = (cppVar_66572 == 253);
	cppVar_66575 = ROM.rd(PC);
	cppVar_66577 = (cppVar_66575 == 252);
	cppVar_66578 = ROM.rd(PC);
	cppVar_66580 = (cppVar_66578 == 251);
	cppVar_66581 = ROM.rd(PC);
	cppVar_66583 = (cppVar_66581 == 250);
	cppVar_66584 = ROM.rd(PC);
	cppVar_66586 = (cppVar_66584 == 249);
	cppVar_66587 = ROM.rd(PC);
	cppVar_66589 = (cppVar_66587 == 248);
	cppVar_66590 = ROM.rd(PC);
	cppVar_66592 = (cppVar_66590 == 247);
	cppVar_66593 = ROM.rd(PC);
	cppVar_66595 = (cppVar_66593 == 246);
	cppVar_66596 = ROM.rd(PC);
	cppVar_66598 = (cppVar_66596 == 244);
	cppVar_66599 = ROM.rd(PC);
	cppVar_66601 = (cppVar_66599 == 243);
	cppVar_66602 = ROM.rd(PC);
	cppVar_66604 = (cppVar_66602 == 242);
	cppVar_66605 = ROM.rd(PC);
	cppVar_66607 = (cppVar_66605 == 240);
	cppVar_66608 = ROM.rd(PC);
	cppVar_66610 = (cppVar_66608 == 239);
	cppVar_66611 = ROM.rd(PC);
	cppVar_66613 = (cppVar_66611 == 238);
	cppVar_66614 = ROM.rd(PC);
	cppVar_66616 = (cppVar_66614 == 237);
	cppVar_66617 = ROM.rd(PC);
	cppVar_66619 = (cppVar_66617 == 236);
	cppVar_66620 = ROM.rd(PC);
	cppVar_66622 = (cppVar_66620 == 235);
	cppVar_66623 = ROM.rd(PC);
	cppVar_66625 = (cppVar_66623 == 234);
	cppVar_66626 = ROM.rd(PC);
	cppVar_66628 = (cppVar_66626 == 233);
	cppVar_66629 = ROM.rd(PC);
	cppVar_66631 = (cppVar_66629 == 232);
	cppVar_66632 = ROM.rd(PC);
	cppVar_66634 = (cppVar_66632 == 231);
	cppVar_66635 = ROM.rd(PC);
	cppVar_66637 = (cppVar_66635 == 230);
	cppVar_66638 = ROM.rd(PC);
	cppVar_66640 = (cppVar_66638 == 229);
	cppVar_66641 = ROM.rd(PC);
	cppVar_66643 = (cppVar_66641 == 228);
	cppVar_66644 = ROM.rd(PC);
	cppVar_66646 = (cppVar_66644 == 227);
	cppVar_66647 = ROM.rd(PC);
	cppVar_66649 = (cppVar_66647 == 226);
	cppVar_66650 = ROM.rd(PC);
	cppVar_66652 = (cppVar_66650 == 225);
	cppVar_66653 = ROM.rd(PC);
	cppVar_66655 = (cppVar_66653 == 224);
	cppVar_66656 = ROM.rd(PC);
	cppVar_66658 = (cppVar_66656 == 223);
	cppVar_66659 = ROM.rd(PC);
	cppVar_66661 = (cppVar_66659 == 222);
	cppVar_66662 = ROM.rd(PC);
	cppVar_66664 = (cppVar_66662 == 221);
	cppVar_66665 = ROM.rd(PC);
	cppVar_66667 = (cppVar_66665 == 220);
	cppVar_66668 = ROM.rd(PC);
	cppVar_66670 = (cppVar_66668 == 219);
	cppVar_66671 = ROM.rd(PC);
	cppVar_66673 = (cppVar_66671 == 218);
	cppVar_66674 = ROM.rd(PC);
	cppVar_66676 = (cppVar_66674 == 217);
	cppVar_66677 = ROM.rd(PC);
	cppVar_66679 = (cppVar_66677 == 216);
	cppVar_66680 = ROM.rd(PC);
	cppVar_66682 = (cppVar_66680 == 215);
	cppVar_66683 = ROM.rd(PC);
	cppVar_66685 = (cppVar_66683 == 214);
	cppVar_66686 = ROM.rd(PC);
	cppVar_66688 = (cppVar_66686 == 212);
	cppVar_66689 = ROM.rd(PC);
	cppVar_66691 = (cppVar_66689 == 211);
	cppVar_66692 = ROM.rd(PC);
	cppVar_66694 = (cppVar_66692 == 210);
	cppVar_66695 = ROM.rd(PC);
	cppVar_66697 = (cppVar_66695 == 207);
	cppVar_66698 = ROM.rd(PC);
	cppVar_66700 = (cppVar_66698 == 206);
	cppVar_66701 = ROM.rd(PC);
	cppVar_66703 = (cppVar_66701 == 205);
	cppVar_66704 = ROM.rd(PC);
	cppVar_66706 = (cppVar_66704 == 204);
	cppVar_66707 = ROM.rd(PC);
	cppVar_66709 = (cppVar_66707 == 203);
	cppVar_66710 = ROM.rd(PC);
	cppVar_66712 = (cppVar_66710 == 202);
	cppVar_66713 = ROM.rd(PC);
	cppVar_66715 = (cppVar_66713 == 201);
	cppVar_66716 = ROM.rd(PC);
	cppVar_66718 = (cppVar_66716 == 200);
	cppVar_66719 = ROM.rd(PC);
	cppVar_66721 = (cppVar_66719 == 199);
	cppVar_66722 = ROM.rd(PC);
	cppVar_66724 = (cppVar_66722 == 198);
	cppVar_66725 = ROM.rd(PC);
	cppVar_66727 = (cppVar_66725 == 196);
	cppVar_66728 = ROM.rd(PC);
	cppVar_66730 = (cppVar_66728 == 195);
	cppVar_66731 = ROM.rd(PC);
	cppVar_66733 = (cppVar_66731 == 194);
	cppVar_66734 = ROM.rd(PC);
	cppVar_66736 = (cppVar_66734 == 193);
	cppVar_66737 = ROM.rd(PC);
	cppVar_66739 = (cppVar_66737 == 191);
	cppVar_66740 = ROM.rd(PC);
	cppVar_66742 = (cppVar_66740 == 190);
	cppVar_66743 = ROM.rd(PC);
	cppVar_66745 = (cppVar_66743 == 189);
	cppVar_66746 = ROM.rd(PC);
	cppVar_66748 = (cppVar_66746 == 188);
	cppVar_66749 = ROM.rd(PC);
	cppVar_66751 = (cppVar_66749 == 187);
	cppVar_66752 = ROM.rd(PC);
	cppVar_66754 = (cppVar_66752 == 186);
	cppVar_66755 = ROM.rd(PC);
	cppVar_66757 = (cppVar_66755 == 185);
	cppVar_66758 = ROM.rd(PC);
	cppVar_66760 = (cppVar_66758 == 184);
	cppVar_66761 = ROM.rd(PC);
	cppVar_66763 = (cppVar_66761 == 183);
	cppVar_66764 = ROM.rd(PC);
	cppVar_66766 = (cppVar_66764 == 182);
	cppVar_66767 = ROM.rd(PC);
	cppVar_66769 = (cppVar_66767 == 181);
	cppVar_66770 = ROM.rd(PC);
	cppVar_66772 = (cppVar_66770 == 180);
	cppVar_66773 = ROM.rd(PC);
	cppVar_66775 = (cppVar_66773 == 179);
	cppVar_66776 = ROM.rd(PC);
	cppVar_66778 = (cppVar_66776 == 178);
	cppVar_66779 = ROM.rd(PC);
	cppVar_66781 = (cppVar_66779 == 176);
	cppVar_66782 = ROM.rd(PC);
	cppVar_66784 = (cppVar_66782 == 175);
	cppVar_66785 = ROM.rd(PC);
	cppVar_66787 = (cppVar_66785 == 174);
	cppVar_66788 = ROM.rd(PC);
	cppVar_66790 = (cppVar_66788 == 173);
	cppVar_66791 = ROM.rd(PC);
	cppVar_66793 = (cppVar_66791 == 172);
	cppVar_66794 = ROM.rd(PC);
	cppVar_66796 = (cppVar_66794 == 171);
	cppVar_66797 = ROM.rd(PC);
	cppVar_66799 = (cppVar_66797 == 170);
	cppVar_66800 = ROM.rd(PC);
	cppVar_66802 = (cppVar_66800 == 169);
	cppVar_66803 = ROM.rd(PC);
	cppVar_66805 = (cppVar_66803 == 168);
	cppVar_66806 = ROM.rd(PC);
	cppVar_66808 = (cppVar_66806 == 167);
	cppVar_66809 = ROM.rd(PC);
	cppVar_66811 = (cppVar_66809 == 166);
	cppVar_66812 = ROM.rd(PC);
	cppVar_66814 = (cppVar_66812 == 165);
	cppVar_66815 = ROM.rd(PC);
	cppVar_66817 = (cppVar_66815 == 164);
	cppVar_66818 = ROM.rd(PC);
	cppVar_66820 = (cppVar_66818 == 163);
	cppVar_66821 = ROM.rd(PC);
	cppVar_66823 = (cppVar_66821 == 162);
	cppVar_66824 = ROM.rd(PC);
	cppVar_66826 = (cppVar_66824 == 161);
	cppVar_66827 = ROM.rd(PC);
	cppVar_66829 = (cppVar_66827 == 160);
	cppVar_66830 = ROM.rd(PC);
	cppVar_66832 = (cppVar_66830 == 159);
	cppVar_66833 = ROM.rd(PC);
	cppVar_66835 = (cppVar_66833 == 158);
	cppVar_66836 = ROM.rd(PC);
	cppVar_66838 = (cppVar_66836 == 157);
	cppVar_66839 = ROM.rd(PC);
	cppVar_66841 = (cppVar_66839 == 156);
	cppVar_66842 = ROM.rd(PC);
	cppVar_66844 = (cppVar_66842 == 155);
	cppVar_66845 = ROM.rd(PC);
	cppVar_66847 = (cppVar_66845 == 154);
	cppVar_66848 = ROM.rd(PC);
	cppVar_66850 = (cppVar_66848 == 153);
	cppVar_66851 = ROM.rd(PC);
	cppVar_66853 = (cppVar_66851 == 152);
	cppVar_66854 = ROM.rd(PC);
	cppVar_66856 = (cppVar_66854 == 151);
	cppVar_66857 = ROM.rd(PC);
	cppVar_66859 = (cppVar_66857 == 150);
	cppVar_66860 = ROM.rd(PC);
	cppVar_66862 = (cppVar_66860 == 149);
	cppVar_66863 = ROM.rd(PC);
	cppVar_66865 = (cppVar_66863 == 148);
	cppVar_66866 = ROM.rd(PC);
	cppVar_66868 = (cppVar_66866 == 147);
	cppVar_66869 = ROM.rd(PC);
	cppVar_66871 = (cppVar_66869 == 146);
	cppVar_66872 = ROM.rd(PC);
	cppVar_66874 = (cppVar_66872 == 144);
	cppVar_66875 = ROM.rd(PC);
	cppVar_66877 = (cppVar_66875 == 132);
	cppVar_66878 = ROM.rd(PC);
	cppVar_66880 = (cppVar_66878 == 131);
	cppVar_66881 = ROM.rd(PC);
	cppVar_66883 = (cppVar_66881 == 130);
	cppVar_66884 = ROM.rd(PC);
	cppVar_66886 = (cppVar_66884 == 129);
	cppVar_66887 = ROM.rd(PC);
	cppVar_66889 = (cppVar_66887 == 128);
	cppVar_66890 = ROM.rd(PC);
	cppVar_66892 = (cppVar_66890 == 127);
	cppVar_66893 = ROM.rd(PC);
	cppVar_66895 = (cppVar_66893 == 126);
	cppVar_66896 = ROM.rd(PC);
	cppVar_66898 = (cppVar_66896 == 125);
	cppVar_66899 = ROM.rd(PC);
	cppVar_66901 = (cppVar_66899 == 124);
	cppVar_66902 = ROM.rd(PC);
	cppVar_66904 = (cppVar_66902 == 123);
	cppVar_66905 = ROM.rd(PC);
	cppVar_66907 = (cppVar_66905 == 122);
	cppVar_66908 = ROM.rd(PC);
	cppVar_66910 = (cppVar_66908 == 121);
	cppVar_66911 = ROM.rd(PC);
	cppVar_66913 = (cppVar_66911 == 120);
	cppVar_66914 = ROM.rd(PC);
	cppVar_66916 = (cppVar_66914 == 119);
	cppVar_66917 = ROM.rd(PC);
	cppVar_66919 = (cppVar_66917 == 118);
	cppVar_66920 = ROM.rd(PC);
	cppVar_66922 = (cppVar_66920 == 116);
	cppVar_66923 = ROM.rd(PC);
	cppVar_66925 = (cppVar_66923 == 115);
	cppVar_66926 = ROM.rd(PC);
	cppVar_66928 = (cppVar_66926 == 114);
	cppVar_66929 = ROM.rd(PC);
	cppVar_66931 = (cppVar_66929 == 112);
	cppVar_66932 = ROM.rd(PC);
	cppVar_66934 = (cppVar_66932 == 111);
	cppVar_66935 = ROM.rd(PC);
	cppVar_66937 = (cppVar_66935 == 110);
	cppVar_66938 = ROM.rd(PC);
	cppVar_66940 = (cppVar_66938 == 109);
	cppVar_66941 = ROM.rd(PC);
	cppVar_66943 = (cppVar_66941 == 108);
	cppVar_66944 = ROM.rd(PC);
	cppVar_66946 = (cppVar_66944 == 107);
	cppVar_66947 = ROM.rd(PC);
	cppVar_66949 = (cppVar_66947 == 106);
	cppVar_66950 = ROM.rd(PC);
	cppVar_66952 = (cppVar_66950 == 105);
	cppVar_66953 = ROM.rd(PC);
	cppVar_66955 = (cppVar_66953 == 104);
	cppVar_66956 = ROM.rd(PC);
	cppVar_66958 = (cppVar_66956 == 103);
	cppVar_66959 = ROM.rd(PC);
	cppVar_66961 = (cppVar_66959 == 102);
	cppVar_66962 = ROM.rd(PC);
	cppVar_66964 = (cppVar_66962 == 101);
	cppVar_66965 = ROM.rd(PC);
	cppVar_66967 = (cppVar_66965 == 100);
	cppVar_66968 = ROM.rd(PC);
	cppVar_66970 = (cppVar_66968 == 97);
	cppVar_66971 = ROM.rd(PC);
	cppVar_66973 = (cppVar_66971 == 96);
	cppVar_66974 = ROM.rd(PC);
	cppVar_66976 = (cppVar_66974 == 95);
	cppVar_66977 = ROM.rd(PC);
	cppVar_66979 = (cppVar_66977 == 94);
	cppVar_66980 = ROM.rd(PC);
	cppVar_66982 = (cppVar_66980 == 93);
	cppVar_66983 = ROM.rd(PC);
	cppVar_66985 = (cppVar_66983 == 92);
	cppVar_66986 = ROM.rd(PC);
	cppVar_66988 = (cppVar_66986 == 91);
	cppVar_66989 = ROM.rd(PC);
	cppVar_66991 = (cppVar_66989 == 90);
	cppVar_66992 = ROM.rd(PC);
	cppVar_66994 = (cppVar_66992 == 89);
	cppVar_66995 = ROM.rd(PC);
	cppVar_66997 = (cppVar_66995 == 88);
	cppVar_66998 = ROM.rd(PC);
	cppVar_67000 = (cppVar_66998 == 87);
	cppVar_67001 = ROM.rd(PC);
	cppVar_67003 = (cppVar_67001 == 86);
	cppVar_67004 = ROM.rd(PC);
	cppVar_67006 = (cppVar_67004 == 85);
	cppVar_67007 = ROM.rd(PC);
	cppVar_67009 = (cppVar_67007 == 84);
	cppVar_67010 = ROM.rd(PC);
	cppVar_67012 = (cppVar_67010 == 80);
	cppVar_67013 = ROM.rd(PC);
	cppVar_67015 = (cppVar_67013 == 79);
	cppVar_67016 = ROM.rd(PC);
	cppVar_67018 = (cppVar_67016 == 78);
	cppVar_67019 = ROM.rd(PC);
	cppVar_67021 = (cppVar_67019 == 77);
	cppVar_67022 = ROM.rd(PC);
	cppVar_67024 = (cppVar_67022 == 76);
	cppVar_67025 = ROM.rd(PC);
	cppVar_67027 = (cppVar_67025 == 75);
	cppVar_67028 = ROM.rd(PC);
	cppVar_67030 = (cppVar_67028 == 74);
	cppVar_67031 = ROM.rd(PC);
	cppVar_67033 = (cppVar_67031 == 73);
	cppVar_67034 = ROM.rd(PC);
	cppVar_67036 = (cppVar_67034 == 72);
	cppVar_67037 = ROM.rd(PC);
	cppVar_67039 = (cppVar_67037 == 71);
	cppVar_67040 = ROM.rd(PC);
	cppVar_67042 = (cppVar_67040 == 70);
	cppVar_67043 = ROM.rd(PC);
	cppVar_67045 = (cppVar_67043 == 69);
	cppVar_67046 = ROM.rd(PC);
	cppVar_67048 = (cppVar_67046 == 68);
	cppVar_67049 = ROM.rd(PC);
	cppVar_67051 = (cppVar_67049 == 65);
	cppVar_67052 = ROM.rd(PC);
	cppVar_67054 = (cppVar_67052 == 64);
	cppVar_67055 = ROM.rd(PC);
	cppVar_67057 = (cppVar_67055 == 63);
	cppVar_67058 = ROM.rd(PC);
	cppVar_67060 = (cppVar_67058 == 62);
	cppVar_67061 = ROM.rd(PC);
	cppVar_67063 = (cppVar_67061 == 61);
	cppVar_67064 = ROM.rd(PC);
	cppVar_67066 = (cppVar_67064 == 60);
	cppVar_67067 = ROM.rd(PC);
	cppVar_67069 = (cppVar_67067 == 59);
	cppVar_67070 = ROM.rd(PC);
	cppVar_67072 = (cppVar_67070 == 58);
	cppVar_67073 = ROM.rd(PC);
	cppVar_67075 = (cppVar_67073 == 57);
	cppVar_67076 = ROM.rd(PC);
	cppVar_67078 = (cppVar_67076 == 56);
	cppVar_67079 = ROM.rd(PC);
	cppVar_67081 = (cppVar_67079 == 55);
	cppVar_67082 = ROM.rd(PC);
	cppVar_67084 = (cppVar_67082 == 54);
	cppVar_67085 = ROM.rd(PC);
	cppVar_67087 = (cppVar_67085 == 53);
	cppVar_67088 = ROM.rd(PC);
	cppVar_67090 = (cppVar_67088 == 52);
	cppVar_67091 = ROM.rd(PC);
	cppVar_67093 = (cppVar_67091 == 51);
	cppVar_67094 = ROM.rd(PC);
	cppVar_67096 = (cppVar_67094 == 48);
	cppVar_67097 = ROM.rd(PC);
	cppVar_67099 = (cppVar_67097 == 47);
	cppVar_67100 = ROM.rd(PC);
	cppVar_67102 = (cppVar_67100 == 46);
	cppVar_67103 = ROM.rd(PC);
	cppVar_67105 = (cppVar_67103 == 45);
	cppVar_67106 = ROM.rd(PC);
	cppVar_67108 = (cppVar_67106 == 44);
	cppVar_67109 = ROM.rd(PC);
	cppVar_67111 = (cppVar_67109 == 43);
	cppVar_67112 = ROM.rd(PC);
	cppVar_67114 = (cppVar_67112 == 42);
	cppVar_67115 = ROM.rd(PC);
	cppVar_67117 = (cppVar_67115 == 41);
	cppVar_67118 = ROM.rd(PC);
	cppVar_67120 = (cppVar_67118 == 40);
	cppVar_67121 = ROM.rd(PC);
	cppVar_67123 = (cppVar_67121 == 39);
	cppVar_67124 = ROM.rd(PC);
	cppVar_67126 = (cppVar_67124 == 38);
	cppVar_67127 = ROM.rd(PC);
	cppVar_67129 = (cppVar_67127 == 37);
	cppVar_67130 = ROM.rd(PC);
	cppVar_67132 = (cppVar_67130 == 36);
	cppVar_67133 = ROM.rd(PC);
	cppVar_67135 = (cppVar_67133 == 35);
	cppVar_67136 = ROM.rd(PC);
	cppVar_67138 = (cppVar_67136 == 33);
	cppVar_67139 = ROM.rd(PC);
	cppVar_67141 = (cppVar_67139 == 32);
	cppVar_67142 = ROM.rd(PC);
	cppVar_67144 = (cppVar_67142 == 31);
	cppVar_67145 = ROM.rd(PC);
	cppVar_67147 = (cppVar_67145 == 30);
	cppVar_67148 = ROM.rd(PC);
	cppVar_67150 = (cppVar_67148 == 29);
	cppVar_67151 = ROM.rd(PC);
	cppVar_67153 = (cppVar_67151 == 28);
	cppVar_67154 = ROM.rd(PC);
	cppVar_67156 = (cppVar_67154 == 27);
	cppVar_67157 = ROM.rd(PC);
	cppVar_67159 = (cppVar_67157 == 26);
	cppVar_67160 = ROM.rd(PC);
	cppVar_67162 = (cppVar_67160 == 25);
	cppVar_67163 = ROM.rd(PC);
	cppVar_67165 = (cppVar_67163 == 24);
	cppVar_67166 = ROM.rd(PC);
	cppVar_67168 = (cppVar_67166 == 23);
	cppVar_67169 = ROM.rd(PC);
	cppVar_67171 = (cppVar_67169 == 22);
	cppVar_67172 = ROM.rd(PC);
	cppVar_67174 = (cppVar_67172 == 20);
	cppVar_67175 = ROM.rd(PC);
	cppVar_67177 = (cppVar_67175 == 19);
	cppVar_67178 = ROM.rd(PC);
	cppVar_67180 = (cppVar_67178 == 16);
	cppVar_67181 = ROM.rd(PC);
	cppVar_67183 = (cppVar_67181 == 15);
	cppVar_67184 = ROM.rd(PC);
	cppVar_67186 = (cppVar_67184 == 14);
	cppVar_67187 = ROM.rd(PC);
	cppVar_67189 = (cppVar_67187 == 13);
	cppVar_67190 = ROM.rd(PC);
	cppVar_67192 = (cppVar_67190 == 12);
	cppVar_67193 = ROM.rd(PC);
	cppVar_67195 = (cppVar_67193 == 11);
	cppVar_67196 = ROM.rd(PC);
	cppVar_67198 = (cppVar_67196 == 10);
	cppVar_67199 = ROM.rd(PC);
	cppVar_67201 = (cppVar_67199 == 9);
	cppVar_67202 = ROM.rd(PC);
	cppVar_67204 = (cppVar_67202 == 8);
	cppVar_67205 = ROM.rd(PC);
	cppVar_67207 = (cppVar_67205 == 7);
	cppVar_67208 = ROM.rd(PC);
	cppVar_67210 = (cppVar_67208 == 6);
	cppVar_67211 = ROM.rd(PC);
	cppVar_67213 = (cppVar_67211 == 4);
	cppVar_67214 = ROM.rd(PC);
	cppVar_67216 = (cppVar_67214 == 3);
	cppVar_67217 = ROM.rd(PC);
	cppVar_67219 = (cppVar_67217 == 2);
	cppVar_67220 = ROM.rd(PC);
	cppVar_67222 = (cppVar_67220 == 1);
	cppVar_67223 = ROM.rd(PC);
	cppVar_67225 = (cppVar_67223 == 0);
	cppVar_67226 = cppVar_67222 || cppVar_67225;
	cppVar_67227 = cppVar_67219 || cppVar_67226;
	cppVar_67228 = cppVar_67216 || cppVar_67227;
	cppVar_67229 = cppVar_67213 || cppVar_67228;
	cppVar_67230 = cppVar_67210 || cppVar_67229;
	cppVar_67231 = cppVar_67207 || cppVar_67230;
	cppVar_67232 = cppVar_67204 || cppVar_67231;
	cppVar_67233 = cppVar_67201 || cppVar_67232;
	cppVar_67234 = cppVar_67198 || cppVar_67233;
	cppVar_67235 = cppVar_67195 || cppVar_67234;
	cppVar_67236 = cppVar_67192 || cppVar_67235;
	cppVar_67237 = cppVar_67189 || cppVar_67236;
	cppVar_67238 = cppVar_67186 || cppVar_67237;
	cppVar_67239 = cppVar_67183 || cppVar_67238;
	cppVar_67240 = cppVar_67180 || cppVar_67239;
	cppVar_67241 = cppVar_67177 || cppVar_67240;
	cppVar_67242 = cppVar_67174 || cppVar_67241;
	cppVar_67243 = cppVar_67171 || cppVar_67242;
	cppVar_67244 = cppVar_67168 || cppVar_67243;
	cppVar_67245 = cppVar_67165 || cppVar_67244;
	cppVar_67246 = cppVar_67162 || cppVar_67245;
	cppVar_67247 = cppVar_67159 || cppVar_67246;
	cppVar_67248 = cppVar_67156 || cppVar_67247;
	cppVar_67249 = cppVar_67153 || cppVar_67248;
	cppVar_67250 = cppVar_67150 || cppVar_67249;
	cppVar_67251 = cppVar_67147 || cppVar_67250;
	cppVar_67252 = cppVar_67144 || cppVar_67251;
	cppVar_67253 = cppVar_67141 || cppVar_67252;
	cppVar_67254 = cppVar_67138 || cppVar_67253;
	cppVar_67255 = cppVar_67135 || cppVar_67254;
	cppVar_67256 = cppVar_67132 || cppVar_67255;
	cppVar_67257 = cppVar_67129 || cppVar_67256;
	cppVar_67258 = cppVar_67126 || cppVar_67257;
	cppVar_67259 = cppVar_67123 || cppVar_67258;
	cppVar_67260 = cppVar_67120 || cppVar_67259;
	cppVar_67261 = cppVar_67117 || cppVar_67260;
	cppVar_67262 = cppVar_67114 || cppVar_67261;
	cppVar_67263 = cppVar_67111 || cppVar_67262;
	cppVar_67264 = cppVar_67108 || cppVar_67263;
	cppVar_67265 = cppVar_67105 || cppVar_67264;
	cppVar_67266 = cppVar_67102 || cppVar_67265;
	cppVar_67267 = cppVar_67099 || cppVar_67266;
	cppVar_67268 = cppVar_67096 || cppVar_67267;
	cppVar_67269 = cppVar_67093 || cppVar_67268;
	cppVar_67270 = cppVar_67090 || cppVar_67269;
	cppVar_67271 = cppVar_67087 || cppVar_67270;
	cppVar_67272 = cppVar_67084 || cppVar_67271;
	cppVar_67273 = cppVar_67081 || cppVar_67272;
	cppVar_67274 = cppVar_67078 || cppVar_67273;
	cppVar_67275 = cppVar_67075 || cppVar_67274;
	cppVar_67276 = cppVar_67072 || cppVar_67275;
	cppVar_67277 = cppVar_67069 || cppVar_67276;
	cppVar_67278 = cppVar_67066 || cppVar_67277;
	cppVar_67279 = cppVar_67063 || cppVar_67278;
	cppVar_67280 = cppVar_67060 || cppVar_67279;
	cppVar_67281 = cppVar_67057 || cppVar_67280;
	cppVar_67282 = cppVar_67054 || cppVar_67281;
	cppVar_67283 = cppVar_67051 || cppVar_67282;
	cppVar_67284 = cppVar_67048 || cppVar_67283;
	cppVar_67285 = cppVar_67045 || cppVar_67284;
	cppVar_67286 = cppVar_67042 || cppVar_67285;
	cppVar_67287 = cppVar_67039 || cppVar_67286;
	cppVar_67288 = cppVar_67036 || cppVar_67287;
	cppVar_67289 = cppVar_67033 || cppVar_67288;
	cppVar_67290 = cppVar_67030 || cppVar_67289;
	cppVar_67291 = cppVar_67027 || cppVar_67290;
	cppVar_67292 = cppVar_67024 || cppVar_67291;
	cppVar_67293 = cppVar_67021 || cppVar_67292;
	cppVar_67294 = cppVar_67018 || cppVar_67293;
	cppVar_67295 = cppVar_67015 || cppVar_67294;
	cppVar_67296 = cppVar_67012 || cppVar_67295;
	cppVar_67297 = cppVar_67009 || cppVar_67296;
	cppVar_67298 = cppVar_67006 || cppVar_67297;
	cppVar_67299 = cppVar_67003 || cppVar_67298;
	cppVar_67300 = cppVar_67000 || cppVar_67299;
	cppVar_67301 = cppVar_66997 || cppVar_67300;
	cppVar_67302 = cppVar_66994 || cppVar_67301;
	cppVar_67303 = cppVar_66991 || cppVar_67302;
	cppVar_67304 = cppVar_66988 || cppVar_67303;
	cppVar_67305 = cppVar_66985 || cppVar_67304;
	cppVar_67306 = cppVar_66982 || cppVar_67305;
	cppVar_67307 = cppVar_66979 || cppVar_67306;
	cppVar_67308 = cppVar_66976 || cppVar_67307;
	cppVar_67309 = cppVar_66973 || cppVar_67308;
	cppVar_67310 = cppVar_66970 || cppVar_67309;
	cppVar_67311 = cppVar_66967 || cppVar_67310;
	cppVar_67312 = cppVar_66964 || cppVar_67311;
	cppVar_67313 = cppVar_66961 || cppVar_67312;
	cppVar_67314 = cppVar_66958 || cppVar_67313;
	cppVar_67315 = cppVar_66955 || cppVar_67314;
	cppVar_67316 = cppVar_66952 || cppVar_67315;
	cppVar_67317 = cppVar_66949 || cppVar_67316;
	cppVar_67318 = cppVar_66946 || cppVar_67317;
	cppVar_67319 = cppVar_66943 || cppVar_67318;
	cppVar_67320 = cppVar_66940 || cppVar_67319;
	cppVar_67321 = cppVar_66937 || cppVar_67320;
	cppVar_67322 = cppVar_66934 || cppVar_67321;
	cppVar_67323 = cppVar_66931 || cppVar_67322;
	cppVar_67324 = cppVar_66928 || cppVar_67323;
	cppVar_67325 = cppVar_66925 || cppVar_67324;
	cppVar_67326 = cppVar_66922 || cppVar_67325;
	cppVar_67327 = cppVar_66919 || cppVar_67326;
	cppVar_67328 = cppVar_66916 || cppVar_67327;
	cppVar_67329 = cppVar_66913 || cppVar_67328;
	cppVar_67330 = cppVar_66910 || cppVar_67329;
	cppVar_67331 = cppVar_66907 || cppVar_67330;
	cppVar_67332 = cppVar_66904 || cppVar_67331;
	cppVar_67333 = cppVar_66901 || cppVar_67332;
	cppVar_67334 = cppVar_66898 || cppVar_67333;
	cppVar_67335 = cppVar_66895 || cppVar_67334;
	cppVar_67336 = cppVar_66892 || cppVar_67335;
	cppVar_67337 = cppVar_66889 || cppVar_67336;
	cppVar_67338 = cppVar_66886 || cppVar_67337;
	cppVar_67339 = cppVar_66883 || cppVar_67338;
	cppVar_67340 = cppVar_66880 || cppVar_67339;
	cppVar_67341 = cppVar_66877 || cppVar_67340;
	cppVar_67342 = cppVar_66874 || cppVar_67341;
	cppVar_67343 = cppVar_66871 || cppVar_67342;
	cppVar_67344 = cppVar_66868 || cppVar_67343;
	cppVar_67345 = cppVar_66865 || cppVar_67344;
	cppVar_67346 = cppVar_66862 || cppVar_67345;
	cppVar_67347 = cppVar_66859 || cppVar_67346;
	cppVar_67348 = cppVar_66856 || cppVar_67347;
	cppVar_67349 = cppVar_66853 || cppVar_67348;
	cppVar_67350 = cppVar_66850 || cppVar_67349;
	cppVar_67351 = cppVar_66847 || cppVar_67350;
	cppVar_67352 = cppVar_66844 || cppVar_67351;
	cppVar_67353 = cppVar_66841 || cppVar_67352;
	cppVar_67354 = cppVar_66838 || cppVar_67353;
	cppVar_67355 = cppVar_66835 || cppVar_67354;
	cppVar_67356 = cppVar_66832 || cppVar_67355;
	cppVar_67357 = cppVar_66829 || cppVar_67356;
	cppVar_67358 = cppVar_66826 || cppVar_67357;
	cppVar_67359 = cppVar_66823 || cppVar_67358;
	cppVar_67360 = cppVar_66820 || cppVar_67359;
	cppVar_67361 = cppVar_66817 || cppVar_67360;
	cppVar_67362 = cppVar_66814 || cppVar_67361;
	cppVar_67363 = cppVar_66811 || cppVar_67362;
	cppVar_67364 = cppVar_66808 || cppVar_67363;
	cppVar_67365 = cppVar_66805 || cppVar_67364;
	cppVar_67366 = cppVar_66802 || cppVar_67365;
	cppVar_67367 = cppVar_66799 || cppVar_67366;
	cppVar_67368 = cppVar_66796 || cppVar_67367;
	cppVar_67369 = cppVar_66793 || cppVar_67368;
	cppVar_67370 = cppVar_66790 || cppVar_67369;
	cppVar_67371 = cppVar_66787 || cppVar_67370;
	cppVar_67372 = cppVar_66784 || cppVar_67371;
	cppVar_67373 = cppVar_66781 || cppVar_67372;
	cppVar_67374 = cppVar_66778 || cppVar_67373;
	cppVar_67375 = cppVar_66775 || cppVar_67374;
	cppVar_67376 = cppVar_66772 || cppVar_67375;
	cppVar_67377 = cppVar_66769 || cppVar_67376;
	cppVar_67378 = cppVar_66766 || cppVar_67377;
	cppVar_67379 = cppVar_66763 || cppVar_67378;
	cppVar_67380 = cppVar_66760 || cppVar_67379;
	cppVar_67381 = cppVar_66757 || cppVar_67380;
	cppVar_67382 = cppVar_66754 || cppVar_67381;
	cppVar_67383 = cppVar_66751 || cppVar_67382;
	cppVar_67384 = cppVar_66748 || cppVar_67383;
	cppVar_67385 = cppVar_66745 || cppVar_67384;
	cppVar_67386 = cppVar_66742 || cppVar_67385;
	cppVar_67387 = cppVar_66739 || cppVar_67386;
	cppVar_67388 = cppVar_66736 || cppVar_67387;
	cppVar_67389 = cppVar_66733 || cppVar_67388;
	cppVar_67390 = cppVar_66730 || cppVar_67389;
	cppVar_67391 = cppVar_66727 || cppVar_67390;
	cppVar_67392 = cppVar_66724 || cppVar_67391;
	cppVar_67393 = cppVar_66721 || cppVar_67392;
	cppVar_67394 = cppVar_66718 || cppVar_67393;
	cppVar_67395 = cppVar_66715 || cppVar_67394;
	cppVar_67396 = cppVar_66712 || cppVar_67395;
	cppVar_67397 = cppVar_66709 || cppVar_67396;
	cppVar_67398 = cppVar_66706 || cppVar_67397;
	cppVar_67399 = cppVar_66703 || cppVar_67398;
	cppVar_67400 = cppVar_66700 || cppVar_67399;
	cppVar_67401 = cppVar_66697 || cppVar_67400;
	cppVar_67402 = cppVar_66694 || cppVar_67401;
	cppVar_67403 = cppVar_66691 || cppVar_67402;
	cppVar_67404 = cppVar_66688 || cppVar_67403;
	cppVar_67405 = cppVar_66685 || cppVar_67404;
	cppVar_67406 = cppVar_66682 || cppVar_67405;
	cppVar_67407 = cppVar_66679 || cppVar_67406;
	cppVar_67408 = cppVar_66676 || cppVar_67407;
	cppVar_67409 = cppVar_66673 || cppVar_67408;
	cppVar_67410 = cppVar_66670 || cppVar_67409;
	cppVar_67411 = cppVar_66667 || cppVar_67410;
	cppVar_67412 = cppVar_66664 || cppVar_67411;
	cppVar_67413 = cppVar_66661 || cppVar_67412;
	cppVar_67414 = cppVar_66658 || cppVar_67413;
	cppVar_67415 = cppVar_66655 || cppVar_67414;
	cppVar_67416 = cppVar_66652 || cppVar_67415;
	cppVar_67417 = cppVar_66649 || cppVar_67416;
	cppVar_67418 = cppVar_66646 || cppVar_67417;
	cppVar_67419 = cppVar_66643 || cppVar_67418;
	cppVar_67420 = cppVar_66640 || cppVar_67419;
	cppVar_67421 = cppVar_66637 || cppVar_67420;
	cppVar_67422 = cppVar_66634 || cppVar_67421;
	cppVar_67423 = cppVar_66631 || cppVar_67422;
	cppVar_67424 = cppVar_66628 || cppVar_67423;
	cppVar_67425 = cppVar_66625 || cppVar_67424;
	cppVar_67426 = cppVar_66622 || cppVar_67425;
	cppVar_67427 = cppVar_66619 || cppVar_67426;
	cppVar_67428 = cppVar_66616 || cppVar_67427;
	cppVar_67429 = cppVar_66613 || cppVar_67428;
	cppVar_67430 = cppVar_66610 || cppVar_67429;
	cppVar_67431 = cppVar_66607 || cppVar_67430;
	cppVar_67432 = cppVar_66604 || cppVar_67431;
	cppVar_67433 = cppVar_66601 || cppVar_67432;
	cppVar_67434 = cppVar_66598 || cppVar_67433;
	cppVar_67435 = cppVar_66595 || cppVar_67434;
	cppVar_67436 = cppVar_66592 || cppVar_67435;
	cppVar_67437 = cppVar_66589 || cppVar_67436;
	cppVar_67438 = cppVar_66586 || cppVar_67437;
	cppVar_67439 = cppVar_66583 || cppVar_67438;
	cppVar_67440 = cppVar_66580 || cppVar_67439;
	cppVar_67441 = cppVar_66577 || cppVar_67440;
	cppVar_67442 = cppVar_66574 || cppVar_67441;
	cppVar_67443 = cppVar_66571 || cppVar_67442;
	cppVar_67444 = cppVar_66568 || cppVar_67443;
	if (cppVar_67444) {
	cppVar_67448 = PC + 1;
	cppVar_67448 = (cppVar_67448 & cppMask_un_16_);
	cppVar_67449 = ROM.rd(cppVar_67448);
	cppVar_67450 = (cppVar_67449 >> 7) & cppMask_un_1_;
	cppVar_67452 = (cppVar_67450 == 1);
	if (cppVar_67452) {
	cppVar_67453 = PC + 1;
	cppVar_67453 = (cppVar_67453 & cppMask_un_16_);
	cppVar_67454 = ROM.rd(cppVar_67453);
	cppVar_67455 = (cppVar_67454 >> 3) & cppMask_un_5_;
	cppVar_67457 = (cppVar_67455 << 3) | 0;
	cppVar_67457 = (cppVar_67457 & cppMask_un_8_);
	cppVar_67446 = cppVar_67457;
	} else {
	cppVar_67458 = PC + 1;
	cppVar_67458 = (cppVar_67458 & cppMask_un_16_);
	cppVar_67459 = ROM.rd(cppVar_67458);
	cppVar_67460 = (cppVar_67459 >> 3) & cppMask_un_5_;
	cppVar_67461 = (cppVar_67460 & cppMask_un_5_);
	cppVar_67463 = cppVar_67461 + 32;
	cppVar_67463 = (cppVar_67463 & cppMask_un_8_);
	cppVar_67446 = cppVar_67463;
	}
	cppVar_67465 = (cppVar_67446 == 129);
	if (cppVar_67465) {
	cppVar_67467 = PC + 1;
	cppVar_67467 = (cppVar_67467 & cppMask_un_16_);
	cppVar_67468 = ROM.rd(cppVar_67467);
	cppVar_67469 = (cppVar_67468 >> 0) & cppMask_un_3_;
	cppVar_67470 = (cppVar_67469 & cppMask_un_3_);
	cppVar_67471 = 1 << static_cast<unsigned>(cppVar_67470);
	cppVar_67471 = (cppVar_67471 & cppMask_un_8_);
	cppVar_67472 = ~cppVar_67471;
	cppVar_67475 = PC + 1;
	cppVar_67475 = (cppVar_67475 & cppMask_un_16_);
	cppVar_67476 = ROM.rd(cppVar_67475);
	cppVar_67477 = (cppVar_67476 >> 7) & cppMask_un_1_;
	cppVar_67478 = (cppVar_67477 == 1);
	if (cppVar_67478) {
	cppVar_67479 = PC + 1;
	cppVar_67479 = (cppVar_67479 & cppMask_un_16_);
	cppVar_67480 = ROM.rd(cppVar_67479);
	cppVar_67481 = (cppVar_67480 >> 3) & cppMask_un_5_;
	cppVar_67482 = (cppVar_67481 << 3) | 0;
	cppVar_67482 = (cppVar_67482 & cppMask_un_8_);
	cppVar_67474 = cppVar_67482;
	} else {
	cppVar_67483 = PC + 1;
	cppVar_67483 = (cppVar_67483 & cppMask_un_16_);
	cppVar_67484 = ROM.rd(cppVar_67483);
	cppVar_67485 = (cppVar_67484 >> 3) & cppMask_un_5_;
	cppVar_67486 = (cppVar_67485 & cppMask_un_5_);
	cppVar_67487 = cppVar_67486 + 32;
	cppVar_67487 = (cppVar_67487 & cppMask_un_8_);
	cppVar_67474 = cppVar_67487;
	}
	cppVar_67488 = (cppVar_67474 >> 7) & cppMask_un_1_;
	cppVar_67490 = (cppVar_67488 == 0);
	if (cppVar_67490) {
	cppVar_67492 = PC + 1;
	cppVar_67492 = (cppVar_67492 & cppMask_un_16_);
	cppVar_67493 = ROM.rd(cppVar_67492);
	cppVar_67494 = (cppVar_67493 >> 7) & cppMask_un_1_;
	cppVar_67495 = (cppVar_67494 == 1);
	if (cppVar_67495) {
	cppVar_67496 = PC + 1;
	cppVar_67496 = (cppVar_67496 & cppMask_un_16_);
	cppVar_67497 = ROM.rd(cppVar_67496);
	cppVar_67498 = (cppVar_67497 >> 3) & cppMask_un_5_;
	cppVar_67499 = (cppVar_67498 << 3) | 0;
	cppVar_67499 = (cppVar_67499 & cppMask_un_8_);
	cppVar_67491 = cppVar_67499;
	} else {
	cppVar_67500 = PC + 1;
	cppVar_67500 = (cppVar_67500 & cppMask_un_16_);
	cppVar_67501 = ROM.rd(cppVar_67500);
	cppVar_67502 = (cppVar_67501 >> 3) & cppMask_un_5_;
	cppVar_67503 = (cppVar_67502 & cppMask_un_5_);
	cppVar_67504 = cppVar_67503 + 32;
	cppVar_67504 = (cppVar_67504 & cppMask_un_8_);
	cppVar_67491 = cppVar_67504;
	}
	cppVar_67505 = IRAM.rd(cppVar_67491);
	cppVar_67473 = cppVar_67505;
	} else {
	cppVar_67508 = PC + 1;
	cppVar_67508 = (cppVar_67508 & cppMask_un_16_);
	cppVar_67509 = ROM.rd(cppVar_67508);
	cppVar_67510 = (cppVar_67509 >> 7) & cppMask_un_1_;
	cppVar_67511 = (cppVar_67510 == 1);
	if (cppVar_67511) {
	cppVar_67512 = PC + 1;
	cppVar_67512 = (cppVar_67512 & cppMask_un_16_);
	cppVar_67513 = ROM.rd(cppVar_67512);
	cppVar_67514 = (cppVar_67513 >> 3) & cppMask_un_5_;
	cppVar_67515 = (cppVar_67514 << 3) | 0;
	cppVar_67515 = (cppVar_67515 & cppMask_un_8_);
	cppVar_67507 = cppVar_67515;
	} else {
	cppVar_67516 = PC + 1;
	cppVar_67516 = (cppVar_67516 & cppMask_un_16_);
	cppVar_67517 = ROM.rd(cppVar_67516);
	cppVar_67518 = (cppVar_67517 >> 3) & cppMask_un_5_;
	cppVar_67519 = (cppVar_67518 & cppMask_un_5_);
	cppVar_67520 = cppVar_67519 + 32;
	cppVar_67520 = (cppVar_67520 & cppMask_un_8_);
	cppVar_67507 = cppVar_67520;
	}
	cppVar_67522 = (cppVar_67507 == 128);
	if (cppVar_67522) {
	cppVar_67506 = P0;
	} else {
	cppVar_67525 = PC + 1;
	cppVar_67525 = (cppVar_67525 & cppMask_un_16_);
	cppVar_67526 = ROM.rd(cppVar_67525);
	cppVar_67527 = (cppVar_67526 >> 7) & cppMask_un_1_;
	cppVar_67528 = (cppVar_67527 == 1);
	if (cppVar_67528) {
	cppVar_67529 = PC + 1;
	cppVar_67529 = (cppVar_67529 & cppMask_un_16_);
	cppVar_67530 = ROM.rd(cppVar_67529);
	cppVar_67531 = (cppVar_67530 >> 3) & cppMask_un_5_;
	cppVar_67532 = (cppVar_67531 << 3) | 0;
	cppVar_67532 = (cppVar_67532 & cppMask_un_8_);
	cppVar_67524 = cppVar_67532;
	} else {
	cppVar_67533 = PC + 1;
	cppVar_67533 = (cppVar_67533 & cppMask_un_16_);
	cppVar_67534 = ROM.rd(cppVar_67533);
	cppVar_67535 = (cppVar_67534 >> 3) & cppMask_un_5_;
	cppVar_67536 = (cppVar_67535 & cppMask_un_5_);
	cppVar_67537 = cppVar_67536 + 32;
	cppVar_67537 = (cppVar_67537 & cppMask_un_8_);
	cppVar_67524 = cppVar_67537;
	}
	cppVar_67539 = (cppVar_67524 == 129);
	if (cppVar_67539) {
	cppVar_67523 = SP;
	} else {
	cppVar_67542 = PC + 1;
	cppVar_67542 = (cppVar_67542 & cppMask_un_16_);
	cppVar_67543 = ROM.rd(cppVar_67542);
	cppVar_67544 = (cppVar_67543 >> 7) & cppMask_un_1_;
	cppVar_67545 = (cppVar_67544 == 1);
	if (cppVar_67545) {
	cppVar_67546 = PC + 1;
	cppVar_67546 = (cppVar_67546 & cppMask_un_16_);
	cppVar_67547 = ROM.rd(cppVar_67546);
	cppVar_67548 = (cppVar_67547 >> 3) & cppMask_un_5_;
	cppVar_67549 = (cppVar_67548 << 3) | 0;
	cppVar_67549 = (cppVar_67549 & cppMask_un_8_);
	cppVar_67541 = cppVar_67549;
	} else {
	cppVar_67550 = PC + 1;
	cppVar_67550 = (cppVar_67550 & cppMask_un_16_);
	cppVar_67551 = ROM.rd(cppVar_67550);
	cppVar_67552 = (cppVar_67551 >> 3) & cppMask_un_5_;
	cppVar_67553 = (cppVar_67552 & cppMask_un_5_);
	cppVar_67554 = cppVar_67553 + 32;
	cppVar_67554 = (cppVar_67554 & cppMask_un_8_);
	cppVar_67541 = cppVar_67554;
	}
	cppVar_67556 = (cppVar_67541 == 130);
	if (cppVar_67556) {
	cppVar_67540 = DPL;
	} else {
	cppVar_67559 = PC + 1;
	cppVar_67559 = (cppVar_67559 & cppMask_un_16_);
	cppVar_67560 = ROM.rd(cppVar_67559);
	cppVar_67561 = (cppVar_67560 >> 7) & cppMask_un_1_;
	cppVar_67562 = (cppVar_67561 == 1);
	if (cppVar_67562) {
	cppVar_67563 = PC + 1;
	cppVar_67563 = (cppVar_67563 & cppMask_un_16_);
	cppVar_67564 = ROM.rd(cppVar_67563);
	cppVar_67565 = (cppVar_67564 >> 3) & cppMask_un_5_;
	cppVar_67566 = (cppVar_67565 << 3) | 0;
	cppVar_67566 = (cppVar_67566 & cppMask_un_8_);
	cppVar_67558 = cppVar_67566;
	} else {
	cppVar_67567 = PC + 1;
	cppVar_67567 = (cppVar_67567 & cppMask_un_16_);
	cppVar_67568 = ROM.rd(cppVar_67567);
	cppVar_67569 = (cppVar_67568 >> 3) & cppMask_un_5_;
	cppVar_67570 = (cppVar_67569 & cppMask_un_5_);
	cppVar_67571 = cppVar_67570 + 32;
	cppVar_67571 = (cppVar_67571 & cppMask_un_8_);
	cppVar_67558 = cppVar_67571;
	}
	cppVar_67573 = (cppVar_67558 == 131);
	if (cppVar_67573) {
	cppVar_67557 = DPH;
	} else {
	cppVar_67576 = PC + 1;
	cppVar_67576 = (cppVar_67576 & cppMask_un_16_);
	cppVar_67577 = ROM.rd(cppVar_67576);
	cppVar_67578 = (cppVar_67577 >> 7) & cppMask_un_1_;
	cppVar_67579 = (cppVar_67578 == 1);
	if (cppVar_67579) {
	cppVar_67580 = PC + 1;
	cppVar_67580 = (cppVar_67580 & cppMask_un_16_);
	cppVar_67581 = ROM.rd(cppVar_67580);
	cppVar_67582 = (cppVar_67581 >> 3) & cppMask_un_5_;
	cppVar_67583 = (cppVar_67582 << 3) | 0;
	cppVar_67583 = (cppVar_67583 & cppMask_un_8_);
	cppVar_67575 = cppVar_67583;
	} else {
	cppVar_67584 = PC + 1;
	cppVar_67584 = (cppVar_67584 & cppMask_un_16_);
	cppVar_67585 = ROM.rd(cppVar_67584);
	cppVar_67586 = (cppVar_67585 >> 3) & cppMask_un_5_;
	cppVar_67587 = (cppVar_67586 & cppMask_un_5_);
	cppVar_67588 = cppVar_67587 + 32;
	cppVar_67588 = (cppVar_67588 & cppMask_un_8_);
	cppVar_67575 = cppVar_67588;
	}
	cppVar_67590 = (cppVar_67575 == 135);
	if (cppVar_67590) {
	cppVar_67574 = PCON;
	} else {
	cppVar_67593 = PC + 1;
	cppVar_67593 = (cppVar_67593 & cppMask_un_16_);
	cppVar_67594 = ROM.rd(cppVar_67593);
	cppVar_67595 = (cppVar_67594 >> 7) & cppMask_un_1_;
	cppVar_67596 = (cppVar_67595 == 1);
	if (cppVar_67596) {
	cppVar_67597 = PC + 1;
	cppVar_67597 = (cppVar_67597 & cppMask_un_16_);
	cppVar_67598 = ROM.rd(cppVar_67597);
	cppVar_67599 = (cppVar_67598 >> 3) & cppMask_un_5_;
	cppVar_67600 = (cppVar_67599 << 3) | 0;
	cppVar_67600 = (cppVar_67600 & cppMask_un_8_);
	cppVar_67592 = cppVar_67600;
	} else {
	cppVar_67601 = PC + 1;
	cppVar_67601 = (cppVar_67601 & cppMask_un_16_);
	cppVar_67602 = ROM.rd(cppVar_67601);
	cppVar_67603 = (cppVar_67602 >> 3) & cppMask_un_5_;
	cppVar_67604 = (cppVar_67603 & cppMask_un_5_);
	cppVar_67605 = cppVar_67604 + 32;
	cppVar_67605 = (cppVar_67605 & cppMask_un_8_);
	cppVar_67592 = cppVar_67605;
	}
	cppVar_67607 = (cppVar_67592 == 136);
	if (cppVar_67607) {
	cppVar_67591 = TCON;
	} else {
	cppVar_67610 = PC + 1;
	cppVar_67610 = (cppVar_67610 & cppMask_un_16_);
	cppVar_67611 = ROM.rd(cppVar_67610);
	cppVar_67612 = (cppVar_67611 >> 7) & cppMask_un_1_;
	cppVar_67613 = (cppVar_67612 == 1);
	if (cppVar_67613) {
	cppVar_67614 = PC + 1;
	cppVar_67614 = (cppVar_67614 & cppMask_un_16_);
	cppVar_67615 = ROM.rd(cppVar_67614);
	cppVar_67616 = (cppVar_67615 >> 3) & cppMask_un_5_;
	cppVar_67617 = (cppVar_67616 << 3) | 0;
	cppVar_67617 = (cppVar_67617 & cppMask_un_8_);
	cppVar_67609 = cppVar_67617;
	} else {
	cppVar_67618 = PC + 1;
	cppVar_67618 = (cppVar_67618 & cppMask_un_16_);
	cppVar_67619 = ROM.rd(cppVar_67618);
	cppVar_67620 = (cppVar_67619 >> 3) & cppMask_un_5_;
	cppVar_67621 = (cppVar_67620 & cppMask_un_5_);
	cppVar_67622 = cppVar_67621 + 32;
	cppVar_67622 = (cppVar_67622 & cppMask_un_8_);
	cppVar_67609 = cppVar_67622;
	}
	cppVar_67624 = (cppVar_67609 == 137);
	if (cppVar_67624) {
	cppVar_67608 = TMOD;
	} else {
	cppVar_67627 = PC + 1;
	cppVar_67627 = (cppVar_67627 & cppMask_un_16_);
	cppVar_67628 = ROM.rd(cppVar_67627);
	cppVar_67629 = (cppVar_67628 >> 7) & cppMask_un_1_;
	cppVar_67630 = (cppVar_67629 == 1);
	if (cppVar_67630) {
	cppVar_67631 = PC + 1;
	cppVar_67631 = (cppVar_67631 & cppMask_un_16_);
	cppVar_67632 = ROM.rd(cppVar_67631);
	cppVar_67633 = (cppVar_67632 >> 3) & cppMask_un_5_;
	cppVar_67634 = (cppVar_67633 << 3) | 0;
	cppVar_67634 = (cppVar_67634 & cppMask_un_8_);
	cppVar_67626 = cppVar_67634;
	} else {
	cppVar_67635 = PC + 1;
	cppVar_67635 = (cppVar_67635 & cppMask_un_16_);
	cppVar_67636 = ROM.rd(cppVar_67635);
	cppVar_67637 = (cppVar_67636 >> 3) & cppMask_un_5_;
	cppVar_67638 = (cppVar_67637 & cppMask_un_5_);
	cppVar_67639 = cppVar_67638 + 32;
	cppVar_67639 = (cppVar_67639 & cppMask_un_8_);
	cppVar_67626 = cppVar_67639;
	}
	cppVar_67641 = (cppVar_67626 == 138);
	if (cppVar_67641) {
	cppVar_67625 = TL0;
	} else {
	cppVar_67644 = PC + 1;
	cppVar_67644 = (cppVar_67644 & cppMask_un_16_);
	cppVar_67645 = ROM.rd(cppVar_67644);
	cppVar_67646 = (cppVar_67645 >> 7) & cppMask_un_1_;
	cppVar_67647 = (cppVar_67646 == 1);
	if (cppVar_67647) {
	cppVar_67648 = PC + 1;
	cppVar_67648 = (cppVar_67648 & cppMask_un_16_);
	cppVar_67649 = ROM.rd(cppVar_67648);
	cppVar_67650 = (cppVar_67649 >> 3) & cppMask_un_5_;
	cppVar_67651 = (cppVar_67650 << 3) | 0;
	cppVar_67651 = (cppVar_67651 & cppMask_un_8_);
	cppVar_67643 = cppVar_67651;
	} else {
	cppVar_67652 = PC + 1;
	cppVar_67652 = (cppVar_67652 & cppMask_un_16_);
	cppVar_67653 = ROM.rd(cppVar_67652);
	cppVar_67654 = (cppVar_67653 >> 3) & cppMask_un_5_;
	cppVar_67655 = (cppVar_67654 & cppMask_un_5_);
	cppVar_67656 = cppVar_67655 + 32;
	cppVar_67656 = (cppVar_67656 & cppMask_un_8_);
	cppVar_67643 = cppVar_67656;
	}
	cppVar_67658 = (cppVar_67643 == 140);
	if (cppVar_67658) {
	cppVar_67642 = TH0;
	} else {
	cppVar_67661 = PC + 1;
	cppVar_67661 = (cppVar_67661 & cppMask_un_16_);
	cppVar_67662 = ROM.rd(cppVar_67661);
	cppVar_67663 = (cppVar_67662 >> 7) & cppMask_un_1_;
	cppVar_67664 = (cppVar_67663 == 1);
	if (cppVar_67664) {
	cppVar_67665 = PC + 1;
	cppVar_67665 = (cppVar_67665 & cppMask_un_16_);
	cppVar_67666 = ROM.rd(cppVar_67665);
	cppVar_67667 = (cppVar_67666 >> 3) & cppMask_un_5_;
	cppVar_67668 = (cppVar_67667 << 3) | 0;
	cppVar_67668 = (cppVar_67668 & cppMask_un_8_);
	cppVar_67660 = cppVar_67668;
	} else {
	cppVar_67669 = PC + 1;
	cppVar_67669 = (cppVar_67669 & cppMask_un_16_);
	cppVar_67670 = ROM.rd(cppVar_67669);
	cppVar_67671 = (cppVar_67670 >> 3) & cppMask_un_5_;
	cppVar_67672 = (cppVar_67671 & cppMask_un_5_);
	cppVar_67673 = cppVar_67672 + 32;
	cppVar_67673 = (cppVar_67673 & cppMask_un_8_);
	cppVar_67660 = cppVar_67673;
	}
	cppVar_67675 = (cppVar_67660 == 139);
	if (cppVar_67675) {
	cppVar_67659 = TL1;
	} else {
	cppVar_67678 = PC + 1;
	cppVar_67678 = (cppVar_67678 & cppMask_un_16_);
	cppVar_67679 = ROM.rd(cppVar_67678);
	cppVar_67680 = (cppVar_67679 >> 7) & cppMask_un_1_;
	cppVar_67681 = (cppVar_67680 == 1);
	if (cppVar_67681) {
	cppVar_67682 = PC + 1;
	cppVar_67682 = (cppVar_67682 & cppMask_un_16_);
	cppVar_67683 = ROM.rd(cppVar_67682);
	cppVar_67684 = (cppVar_67683 >> 3) & cppMask_un_5_;
	cppVar_67685 = (cppVar_67684 << 3) | 0;
	cppVar_67685 = (cppVar_67685 & cppMask_un_8_);
	cppVar_67677 = cppVar_67685;
	} else {
	cppVar_67686 = PC + 1;
	cppVar_67686 = (cppVar_67686 & cppMask_un_16_);
	cppVar_67687 = ROM.rd(cppVar_67686);
	cppVar_67688 = (cppVar_67687 >> 3) & cppMask_un_5_;
	cppVar_67689 = (cppVar_67688 & cppMask_un_5_);
	cppVar_67690 = cppVar_67689 + 32;
	cppVar_67690 = (cppVar_67690 & cppMask_un_8_);
	cppVar_67677 = cppVar_67690;
	}
	cppVar_67692 = (cppVar_67677 == 141);
	if (cppVar_67692) {
	cppVar_67676 = TH1;
	} else {
	cppVar_67695 = PC + 1;
	cppVar_67695 = (cppVar_67695 & cppMask_un_16_);
	cppVar_67696 = ROM.rd(cppVar_67695);
	cppVar_67697 = (cppVar_67696 >> 7) & cppMask_un_1_;
	cppVar_67698 = (cppVar_67697 == 1);
	if (cppVar_67698) {
	cppVar_67699 = PC + 1;
	cppVar_67699 = (cppVar_67699 & cppMask_un_16_);
	cppVar_67700 = ROM.rd(cppVar_67699);
	cppVar_67701 = (cppVar_67700 >> 3) & cppMask_un_5_;
	cppVar_67702 = (cppVar_67701 << 3) | 0;
	cppVar_67702 = (cppVar_67702 & cppMask_un_8_);
	cppVar_67694 = cppVar_67702;
	} else {
	cppVar_67703 = PC + 1;
	cppVar_67703 = (cppVar_67703 & cppMask_un_16_);
	cppVar_67704 = ROM.rd(cppVar_67703);
	cppVar_67705 = (cppVar_67704 >> 3) & cppMask_un_5_;
	cppVar_67706 = (cppVar_67705 & cppMask_un_5_);
	cppVar_67707 = cppVar_67706 + 32;
	cppVar_67707 = (cppVar_67707 & cppMask_un_8_);
	cppVar_67694 = cppVar_67707;
	}
	cppVar_67709 = (cppVar_67694 == 144);
	if (cppVar_67709) {
	cppVar_67693 = P1;
	} else {
	cppVar_67712 = PC + 1;
	cppVar_67712 = (cppVar_67712 & cppMask_un_16_);
	cppVar_67713 = ROM.rd(cppVar_67712);
	cppVar_67714 = (cppVar_67713 >> 7) & cppMask_un_1_;
	cppVar_67715 = (cppVar_67714 == 1);
	if (cppVar_67715) {
	cppVar_67716 = PC + 1;
	cppVar_67716 = (cppVar_67716 & cppMask_un_16_);
	cppVar_67717 = ROM.rd(cppVar_67716);
	cppVar_67718 = (cppVar_67717 >> 3) & cppMask_un_5_;
	cppVar_67719 = (cppVar_67718 << 3) | 0;
	cppVar_67719 = (cppVar_67719 & cppMask_un_8_);
	cppVar_67711 = cppVar_67719;
	} else {
	cppVar_67720 = PC + 1;
	cppVar_67720 = (cppVar_67720 & cppMask_un_16_);
	cppVar_67721 = ROM.rd(cppVar_67720);
	cppVar_67722 = (cppVar_67721 >> 3) & cppMask_un_5_;
	cppVar_67723 = (cppVar_67722 & cppMask_un_5_);
	cppVar_67724 = cppVar_67723 + 32;
	cppVar_67724 = (cppVar_67724 & cppMask_un_8_);
	cppVar_67711 = cppVar_67724;
	}
	cppVar_67726 = (cppVar_67711 == 152);
	if (cppVar_67726) {
	cppVar_67710 = SCON;
	} else {
	cppVar_67729 = PC + 1;
	cppVar_67729 = (cppVar_67729 & cppMask_un_16_);
	cppVar_67730 = ROM.rd(cppVar_67729);
	cppVar_67731 = (cppVar_67730 >> 7) & cppMask_un_1_;
	cppVar_67732 = (cppVar_67731 == 1);
	if (cppVar_67732) {
	cppVar_67733 = PC + 1;
	cppVar_67733 = (cppVar_67733 & cppMask_un_16_);
	cppVar_67734 = ROM.rd(cppVar_67733);
	cppVar_67735 = (cppVar_67734 >> 3) & cppMask_un_5_;
	cppVar_67736 = (cppVar_67735 << 3) | 0;
	cppVar_67736 = (cppVar_67736 & cppMask_un_8_);
	cppVar_67728 = cppVar_67736;
	} else {
	cppVar_67737 = PC + 1;
	cppVar_67737 = (cppVar_67737 & cppMask_un_16_);
	cppVar_67738 = ROM.rd(cppVar_67737);
	cppVar_67739 = (cppVar_67738 >> 3) & cppMask_un_5_;
	cppVar_67740 = (cppVar_67739 & cppMask_un_5_);
	cppVar_67741 = cppVar_67740 + 32;
	cppVar_67741 = (cppVar_67741 & cppMask_un_8_);
	cppVar_67728 = cppVar_67741;
	}
	cppVar_67743 = (cppVar_67728 == 153);
	if (cppVar_67743) {
	cppVar_67727 = SBUF;
	} else {
	cppVar_67746 = PC + 1;
	cppVar_67746 = (cppVar_67746 & cppMask_un_16_);
	cppVar_67747 = ROM.rd(cppVar_67746);
	cppVar_67748 = (cppVar_67747 >> 7) & cppMask_un_1_;
	cppVar_67749 = (cppVar_67748 == 1);
	if (cppVar_67749) {
	cppVar_67750 = PC + 1;
	cppVar_67750 = (cppVar_67750 & cppMask_un_16_);
	cppVar_67751 = ROM.rd(cppVar_67750);
	cppVar_67752 = (cppVar_67751 >> 3) & cppMask_un_5_;
	cppVar_67753 = (cppVar_67752 << 3) | 0;
	cppVar_67753 = (cppVar_67753 & cppMask_un_8_);
	cppVar_67745 = cppVar_67753;
	} else {
	cppVar_67754 = PC + 1;
	cppVar_67754 = (cppVar_67754 & cppMask_un_16_);
	cppVar_67755 = ROM.rd(cppVar_67754);
	cppVar_67756 = (cppVar_67755 >> 3) & cppMask_un_5_;
	cppVar_67757 = (cppVar_67756 & cppMask_un_5_);
	cppVar_67758 = cppVar_67757 + 32;
	cppVar_67758 = (cppVar_67758 & cppMask_un_8_);
	cppVar_67745 = cppVar_67758;
	}
	cppVar_67760 = (cppVar_67745 == 160);
	if (cppVar_67760) {
	cppVar_67744 = P2;
	} else {
	cppVar_67763 = PC + 1;
	cppVar_67763 = (cppVar_67763 & cppMask_un_16_);
	cppVar_67764 = ROM.rd(cppVar_67763);
	cppVar_67765 = (cppVar_67764 >> 7) & cppMask_un_1_;
	cppVar_67766 = (cppVar_67765 == 1);
	if (cppVar_67766) {
	cppVar_67767 = PC + 1;
	cppVar_67767 = (cppVar_67767 & cppMask_un_16_);
	cppVar_67768 = ROM.rd(cppVar_67767);
	cppVar_67769 = (cppVar_67768 >> 3) & cppMask_un_5_;
	cppVar_67770 = (cppVar_67769 << 3) | 0;
	cppVar_67770 = (cppVar_67770 & cppMask_un_8_);
	cppVar_67762 = cppVar_67770;
	} else {
	cppVar_67771 = PC + 1;
	cppVar_67771 = (cppVar_67771 & cppMask_un_16_);
	cppVar_67772 = ROM.rd(cppVar_67771);
	cppVar_67773 = (cppVar_67772 >> 3) & cppMask_un_5_;
	cppVar_67774 = (cppVar_67773 & cppMask_un_5_);
	cppVar_67775 = cppVar_67774 + 32;
	cppVar_67775 = (cppVar_67775 & cppMask_un_8_);
	cppVar_67762 = cppVar_67775;
	}
	cppVar_67777 = (cppVar_67762 == 168);
	if (cppVar_67777) {
	cppVar_67761 = IE;
	} else {
	cppVar_67780 = PC + 1;
	cppVar_67780 = (cppVar_67780 & cppMask_un_16_);
	cppVar_67781 = ROM.rd(cppVar_67780);
	cppVar_67782 = (cppVar_67781 >> 7) & cppMask_un_1_;
	cppVar_67783 = (cppVar_67782 == 1);
	if (cppVar_67783) {
	cppVar_67784 = PC + 1;
	cppVar_67784 = (cppVar_67784 & cppMask_un_16_);
	cppVar_67785 = ROM.rd(cppVar_67784);
	cppVar_67786 = (cppVar_67785 >> 3) & cppMask_un_5_;
	cppVar_67787 = (cppVar_67786 << 3) | 0;
	cppVar_67787 = (cppVar_67787 & cppMask_un_8_);
	cppVar_67779 = cppVar_67787;
	} else {
	cppVar_67788 = PC + 1;
	cppVar_67788 = (cppVar_67788 & cppMask_un_16_);
	cppVar_67789 = ROM.rd(cppVar_67788);
	cppVar_67790 = (cppVar_67789 >> 3) & cppMask_un_5_;
	cppVar_67791 = (cppVar_67790 & cppMask_un_5_);
	cppVar_67792 = cppVar_67791 + 32;
	cppVar_67792 = (cppVar_67792 & cppMask_un_8_);
	cppVar_67779 = cppVar_67792;
	}
	cppVar_67794 = (cppVar_67779 == 176);
	if (cppVar_67794) {
	cppVar_67778 = P3;
	} else {
	cppVar_67797 = PC + 1;
	cppVar_67797 = (cppVar_67797 & cppMask_un_16_);
	cppVar_67798 = ROM.rd(cppVar_67797);
	cppVar_67799 = (cppVar_67798 >> 7) & cppMask_un_1_;
	cppVar_67800 = (cppVar_67799 == 1);
	if (cppVar_67800) {
	cppVar_67801 = PC + 1;
	cppVar_67801 = (cppVar_67801 & cppMask_un_16_);
	cppVar_67802 = ROM.rd(cppVar_67801);
	cppVar_67803 = (cppVar_67802 >> 3) & cppMask_un_5_;
	cppVar_67804 = (cppVar_67803 << 3) | 0;
	cppVar_67804 = (cppVar_67804 & cppMask_un_8_);
	cppVar_67796 = cppVar_67804;
	} else {
	cppVar_67805 = PC + 1;
	cppVar_67805 = (cppVar_67805 & cppMask_un_16_);
	cppVar_67806 = ROM.rd(cppVar_67805);
	cppVar_67807 = (cppVar_67806 >> 3) & cppMask_un_5_;
	cppVar_67808 = (cppVar_67807 & cppMask_un_5_);
	cppVar_67809 = cppVar_67808 + 32;
	cppVar_67809 = (cppVar_67809 & cppMask_un_8_);
	cppVar_67796 = cppVar_67809;
	}
	cppVar_67811 = (cppVar_67796 == 184);
	if (cppVar_67811) {
	cppVar_67795 = IP;
	} else {
	cppVar_67814 = PC + 1;
	cppVar_67814 = (cppVar_67814 & cppMask_un_16_);
	cppVar_67815 = ROM.rd(cppVar_67814);
	cppVar_67816 = (cppVar_67815 >> 7) & cppMask_un_1_;
	cppVar_67817 = (cppVar_67816 == 1);
	if (cppVar_67817) {
	cppVar_67818 = PC + 1;
	cppVar_67818 = (cppVar_67818 & cppMask_un_16_);
	cppVar_67819 = ROM.rd(cppVar_67818);
	cppVar_67820 = (cppVar_67819 >> 3) & cppMask_un_5_;
	cppVar_67821 = (cppVar_67820 << 3) | 0;
	cppVar_67821 = (cppVar_67821 & cppMask_un_8_);
	cppVar_67813 = cppVar_67821;
	} else {
	cppVar_67822 = PC + 1;
	cppVar_67822 = (cppVar_67822 & cppMask_un_16_);
	cppVar_67823 = ROM.rd(cppVar_67822);
	cppVar_67824 = (cppVar_67823 >> 3) & cppMask_un_5_;
	cppVar_67825 = (cppVar_67824 & cppMask_un_5_);
	cppVar_67826 = cppVar_67825 + 32;
	cppVar_67826 = (cppVar_67826 & cppMask_un_8_);
	cppVar_67813 = cppVar_67826;
	}
	cppVar_67828 = (cppVar_67813 == 208);
	if (cppVar_67828) {
	cppVar_67812 = PSW;
	} else {
	cppVar_67831 = PC + 1;
	cppVar_67831 = (cppVar_67831 & cppMask_un_16_);
	cppVar_67832 = ROM.rd(cppVar_67831);
	cppVar_67833 = (cppVar_67832 >> 7) & cppMask_un_1_;
	cppVar_67834 = (cppVar_67833 == 1);
	if (cppVar_67834) {
	cppVar_67835 = PC + 1;
	cppVar_67835 = (cppVar_67835 & cppMask_un_16_);
	cppVar_67836 = ROM.rd(cppVar_67835);
	cppVar_67837 = (cppVar_67836 >> 3) & cppMask_un_5_;
	cppVar_67838 = (cppVar_67837 << 3) | 0;
	cppVar_67838 = (cppVar_67838 & cppMask_un_8_);
	cppVar_67830 = cppVar_67838;
	} else {
	cppVar_67839 = PC + 1;
	cppVar_67839 = (cppVar_67839 & cppMask_un_16_);
	cppVar_67840 = ROM.rd(cppVar_67839);
	cppVar_67841 = (cppVar_67840 >> 3) & cppMask_un_5_;
	cppVar_67842 = (cppVar_67841 & cppMask_un_5_);
	cppVar_67843 = cppVar_67842 + 32;
	cppVar_67843 = (cppVar_67843 & cppMask_un_8_);
	cppVar_67830 = cppVar_67843;
	}
	cppVar_67845 = (cppVar_67830 == 224);
	if (cppVar_67845) {
	cppVar_67829 = ACC;
	} else {
	cppVar_67848 = PC + 1;
	cppVar_67848 = (cppVar_67848 & cppMask_un_16_);
	cppVar_67849 = ROM.rd(cppVar_67848);
	cppVar_67850 = (cppVar_67849 >> 7) & cppMask_un_1_;
	cppVar_67851 = (cppVar_67850 == 1);
	if (cppVar_67851) {
	cppVar_67852 = PC + 1;
	cppVar_67852 = (cppVar_67852 & cppMask_un_16_);
	cppVar_67853 = ROM.rd(cppVar_67852);
	cppVar_67854 = (cppVar_67853 >> 3) & cppMask_un_5_;
	cppVar_67855 = (cppVar_67854 << 3) | 0;
	cppVar_67855 = (cppVar_67855 & cppMask_un_8_);
	cppVar_67847 = cppVar_67855;
	} else {
	cppVar_67856 = PC + 1;
	cppVar_67856 = (cppVar_67856 & cppMask_un_16_);
	cppVar_67857 = ROM.rd(cppVar_67856);
	cppVar_67858 = (cppVar_67857 >> 3) & cppMask_un_5_;
	cppVar_67859 = (cppVar_67858 & cppMask_un_5_);
	cppVar_67860 = cppVar_67859 + 32;
	cppVar_67860 = (cppVar_67860 & cppMask_un_8_);
	cppVar_67847 = cppVar_67860;
	}
	cppVar_67862 = (cppVar_67847 == 240);
	if (cppVar_67862) {
	cppVar_67846 = B;
	} else {
	cppVar_67846 = 0;
	}
	cppVar_67829 = cppVar_67846;
	}
	cppVar_67812 = cppVar_67829;
	}
	cppVar_67795 = cppVar_67812;
	}
	cppVar_67778 = cppVar_67795;
	}
	cppVar_67761 = cppVar_67778;
	}
	cppVar_67744 = cppVar_67761;
	}
	cppVar_67727 = cppVar_67744;
	}
	cppVar_67710 = cppVar_67727;
	}
	cppVar_67693 = cppVar_67710;
	}
	cppVar_67676 = cppVar_67693;
	}
	cppVar_67659 = cppVar_67676;
	}
	cppVar_67642 = cppVar_67659;
	}
	cppVar_67625 = cppVar_67642;
	}
	cppVar_67608 = cppVar_67625;
	}
	cppVar_67591 = cppVar_67608;
	}
	cppVar_67574 = cppVar_67591;
	}
	cppVar_67557 = cppVar_67574;
	}
	cppVar_67540 = cppVar_67557;
	}
	cppVar_67523 = cppVar_67540;
	}
	cppVar_67506 = cppVar_67523;
	}
	cppVar_67473 = cppVar_67506;
	}
	cppVar_67864 = cppVar_67472 & cppVar_67473;
	cppVar_67865 = (PSW >> 7) & cppMask_un_1_;
	cppVar_67866 = (cppVar_67865 & cppMask_un_1_);
	cppVar_67867 = PC + 1;
	cppVar_67867 = (cppVar_67867 & cppMask_un_16_);
	cppVar_67868 = ROM.rd(cppVar_67867);
	cppVar_67869 = (cppVar_67868 >> 0) & cppMask_un_3_;
	cppVar_67870 = (cppVar_67869 & cppMask_un_3_);
	cppVar_67871 = cppVar_67866 << static_cast<unsigned>(cppVar_67870);
	cppVar_67871 = (cppVar_67871 & cppMask_un_8_);
	cppVar_67872 = cppVar_67864 | cppVar_67871;
	cppVar_67445 = cppVar_67872;
	} else {
	cppVar_67445 = SP;
	}
	cppVar_66565 = cppVar_67445;
	} else {
	cppVar_66565 = SP;
	}
	cppVar_66438 = cppVar_66565;
	}
	cppVar_66400 = cppVar_66438;
	}
	cppVar_66269 = cppVar_66400;
	}
	cppVar_66259 = cppVar_66269;
	}
	cppVar_66133 = cppVar_66259;
	}
	cppVar_66004 = cppVar_66133;
	}
	cppVar_65878 = cppVar_66004;
	}
	cppVar_65749 = cppVar_65878;
	}
	cppVar_65623 = cppVar_65749;
	}
	cppVar_65494 = cppVar_65623;
	}
	cppVar_65481 = cppVar_65494;
	}
	cppVar_65355 = cppVar_65481;
	}
	cppVar_65338 = cppVar_65355;
	}
	cppVar_65321 = cppVar_65338;
	}
	cppVar_65171 = cppVar_65321;
	}
	cppVar_65021 = cppVar_65171;
	}
	cppVar_64871 = cppVar_65021;
	}
	cppVar_64721 = cppVar_64871;
	}
	cppVar_64571 = cppVar_64721;
	}
	cppVar_64421 = cppVar_64571;
	}
	cppVar_64271 = cppVar_64421;
	}
	cppVar_64121 = cppVar_64271;
	}
	cppVar_64115 = cppVar_64121;
	}
	cppVar_64101 = cppVar_64115;
	}
	cppVar_64083 = cppVar_64101;
	}
	return cppVar_64083;
}
