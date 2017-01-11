#include "common.hpp"
#include "model_oc8051_class.hpp"

BIT_VEC model_oc8051::cppUpdateFun_PC()
{
	bool cppVar_42054;
	BIT_VEC cppVar_42056;
	BIT_VEC cppVar_42057;
	BIT_VEC cppVar_42058;
	BIT_VEC cppVar_42059;
	BIT_VEC cppVar_42060;
	BIT_VEC cppVar_42061;
	BIT_VEC cppVar_42062;
	BIT_VEC cppVar_42063;
	BIT_VEC cppVar_42064;
	bool cppVar_42065;
	BIT_VEC cppVar_42066;
	BIT_VEC cppVar_42067;
	BIT_VEC cppVar_42068;
	BIT_VEC cppVar_42069;
	BIT_VEC cppVar_42070;
	BIT_VEC cppVar_42071;
	BIT_VEC cppVar_42072;
	BIT_VEC cppVar_42073;
	BIT_VEC cppVar_42074;
	BIT_VEC cppVar_42055;
	BIT_VEC cppVar_42076;
	BIT_VEC cppVar_42077;
	bool cppVar_42078;
	BIT_VEC cppVar_42080;
	BIT_VEC cppVar_42081;
	BIT_VEC cppVar_42082;
	BIT_VEC cppVar_42083;
	BIT_VEC cppVar_42084;
	BIT_VEC cppVar_42085;
	BIT_VEC cppVar_42086;
	BIT_VEC cppVar_42087;
	BIT_VEC cppVar_42088;
	bool cppVar_42089;
	BIT_VEC cppVar_42090;
	BIT_VEC cppVar_42091;
	BIT_VEC cppVar_42092;
	BIT_VEC cppVar_42093;
	BIT_VEC cppVar_42094;
	BIT_VEC cppVar_42095;
	BIT_VEC cppVar_42096;
	BIT_VEC cppVar_42097;
	BIT_VEC cppVar_42098;
	BIT_VEC cppVar_42079;
	BIT_VEC cppVar_42100;
	BIT_VEC cppVar_42101;
	bool cppVar_42102;
	BIT_VEC cppVar_42104;
	BIT_VEC cppVar_42105;
	BIT_VEC cppVar_42106;
	BIT_VEC cppVar_42107;
	BIT_VEC cppVar_42108;
	BIT_VEC cppVar_42109;
	BIT_VEC cppVar_42110;
	BIT_VEC cppVar_42111;
	BIT_VEC cppVar_42112;
	bool cppVar_42113;
	BIT_VEC cppVar_42114;
	BIT_VEC cppVar_42115;
	BIT_VEC cppVar_42116;
	BIT_VEC cppVar_42117;
	BIT_VEC cppVar_42118;
	BIT_VEC cppVar_42119;
	BIT_VEC cppVar_42120;
	BIT_VEC cppVar_42121;
	BIT_VEC cppVar_42122;
	BIT_VEC cppVar_42103;
	BIT_VEC cppVar_42124;
	BIT_VEC cppVar_42125;
	bool cppVar_42126;
	BIT_VEC cppVar_42128;
	BIT_VEC cppVar_42129;
	BIT_VEC cppVar_42130;
	BIT_VEC cppVar_42131;
	BIT_VEC cppVar_42132;
	BIT_VEC cppVar_42133;
	BIT_VEC cppVar_42134;
	BIT_VEC cppVar_42135;
	BIT_VEC cppVar_42136;
	bool cppVar_42137;
	BIT_VEC cppVar_42138;
	BIT_VEC cppVar_42139;
	BIT_VEC cppVar_42140;
	BIT_VEC cppVar_42141;
	BIT_VEC cppVar_42142;
	BIT_VEC cppVar_42143;
	BIT_VEC cppVar_42144;
	BIT_VEC cppVar_42145;
	BIT_VEC cppVar_42146;
	BIT_VEC cppVar_42127;
	BIT_VEC cppVar_42148;
	BIT_VEC cppVar_42149;
	bool cppVar_42150;
	BIT_VEC cppVar_42152;
	BIT_VEC cppVar_42153;
	BIT_VEC cppVar_42154;
	BIT_VEC cppVar_42155;
	BIT_VEC cppVar_42156;
	BIT_VEC cppVar_42157;
	BIT_VEC cppVar_42158;
	BIT_VEC cppVar_42159;
	BIT_VEC cppVar_42160;
	bool cppVar_42161;
	BIT_VEC cppVar_42162;
	BIT_VEC cppVar_42163;
	BIT_VEC cppVar_42164;
	BIT_VEC cppVar_42165;
	BIT_VEC cppVar_42166;
	BIT_VEC cppVar_42167;
	BIT_VEC cppVar_42168;
	BIT_VEC cppVar_42169;
	BIT_VEC cppVar_42170;
	BIT_VEC cppVar_42151;
	BIT_VEC cppVar_42172;
	BIT_VEC cppVar_42173;
	bool cppVar_42174;
	BIT_VEC cppVar_42176;
	BIT_VEC cppVar_42177;
	BIT_VEC cppVar_42178;
	BIT_VEC cppVar_42179;
	BIT_VEC cppVar_42180;
	BIT_VEC cppVar_42181;
	BIT_VEC cppVar_42182;
	BIT_VEC cppVar_42183;
	BIT_VEC cppVar_42184;
	bool cppVar_42185;
	BIT_VEC cppVar_42186;
	BIT_VEC cppVar_42187;
	BIT_VEC cppVar_42188;
	BIT_VEC cppVar_42189;
	BIT_VEC cppVar_42190;
	BIT_VEC cppVar_42191;
	BIT_VEC cppVar_42192;
	BIT_VEC cppVar_42193;
	BIT_VEC cppVar_42194;
	BIT_VEC cppVar_42175;
	BIT_VEC cppVar_42196;
	BIT_VEC cppVar_42197;
	bool cppVar_42198;
	BIT_VEC cppVar_42200;
	BIT_VEC cppVar_42201;
	BIT_VEC cppVar_42202;
	BIT_VEC cppVar_42203;
	BIT_VEC cppVar_42204;
	BIT_VEC cppVar_42205;
	BIT_VEC cppVar_42206;
	BIT_VEC cppVar_42207;
	BIT_VEC cppVar_42208;
	BIT_VEC cppVar_42209;
	bool cppVar_42210;
	BIT_VEC cppVar_42211;
	BIT_VEC cppVar_42212;
	BIT_VEC cppVar_42213;
	BIT_VEC cppVar_42214;
	BIT_VEC cppVar_42215;
	BIT_VEC cppVar_42216;
	BIT_VEC cppVar_42217;
	BIT_VEC cppVar_42218;
	BIT_VEC cppVar_42219;
	BIT_VEC cppVar_42199;
	BIT_VEC cppVar_42221;
	BIT_VEC cppVar_42222;
	bool cppVar_42223;
	BIT_VEC cppVar_42225;
	BIT_VEC cppVar_42226;
	BIT_VEC cppVar_42227;
	BIT_VEC cppVar_42228;
	BIT_VEC cppVar_42229;
	BIT_VEC cppVar_42230;
	BIT_VEC cppVar_42231;
	BIT_VEC cppVar_42232;
	BIT_VEC cppVar_42233;
	BIT_VEC cppVar_42234;
	bool cppVar_42235;
	BIT_VEC cppVar_42236;
	BIT_VEC cppVar_42237;
	BIT_VEC cppVar_42238;
	BIT_VEC cppVar_42239;
	BIT_VEC cppVar_42240;
	BIT_VEC cppVar_42241;
	BIT_VEC cppVar_42242;
	BIT_VEC cppVar_42243;
	BIT_VEC cppVar_42244;
	BIT_VEC cppVar_42224;
	BIT_VEC cppVar_42246;
	BIT_VEC cppVar_42247;
	bool cppVar_42248;
	BIT_VEC cppVar_42251;
	BIT_VEC cppVar_42252;
	BIT_VEC cppVar_42253;
	BIT_VEC cppVar_42254;
	BIT_VEC cppVar_42255;
	bool cppVar_42256;
	BIT_VEC cppVar_42257;
	BIT_VEC cppVar_42258;
	BIT_VEC cppVar_42259;
	BIT_VEC cppVar_42261;
	BIT_VEC cppVar_42262;
	BIT_VEC cppVar_42263;
	bool cppVar_42264;
	BIT_VEC cppVar_42266;
	BIT_VEC cppVar_42267;
	BIT_VEC cppVar_42268;
	bool cppVar_42269;
	BIT_VEC cppVar_42271;
	BIT_VEC cppVar_42272;
	BIT_VEC cppVar_42273;
	bool cppVar_42274;
	BIT_VEC cppVar_42276;
	BIT_VEC cppVar_42277;
	BIT_VEC cppVar_42278;
	bool cppVar_42279;
	BIT_VEC cppVar_42281;
	BIT_VEC cppVar_42282;
	BIT_VEC cppVar_42283;
	bool cppVar_42284;
	BIT_VEC cppVar_42286;
	BIT_VEC cppVar_42287;
	BIT_VEC cppVar_42288;
	bool cppVar_42289;
	BIT_VEC cppVar_42291;
	BIT_VEC cppVar_42292;
	BIT_VEC cppVar_42293;
	bool cppVar_42294;
	BIT_VEC cppVar_42296;
	BIT_VEC cppVar_42297;
	BIT_VEC cppVar_42298;
	bool cppVar_42299;
	BIT_VEC cppVar_42301;
	BIT_VEC cppVar_42302;
	BIT_VEC cppVar_42303;
	bool cppVar_42304;
	BIT_VEC cppVar_42306;
	BIT_VEC cppVar_42307;
	BIT_VEC cppVar_42308;
	bool cppVar_42309;
	BIT_VEC cppVar_42311;
	BIT_VEC cppVar_42312;
	BIT_VEC cppVar_42313;
	bool cppVar_42314;
	BIT_VEC cppVar_42316;
	BIT_VEC cppVar_42317;
	BIT_VEC cppVar_42318;
	bool cppVar_42319;
	BIT_VEC cppVar_42321;
	BIT_VEC cppVar_42322;
	BIT_VEC cppVar_42323;
	bool cppVar_42324;
	BIT_VEC cppVar_42326;
	BIT_VEC cppVar_42327;
	BIT_VEC cppVar_42328;
	bool cppVar_42329;
	BIT_VEC cppVar_42331;
	BIT_VEC cppVar_42332;
	BIT_VEC cppVar_42333;
	bool cppVar_42334;
	BIT_VEC cppVar_42336;
	BIT_VEC cppVar_42337;
	BIT_VEC cppVar_42338;
	bool cppVar_42339;
	BIT_VEC cppVar_42341;
	BIT_VEC cppVar_42342;
	BIT_VEC cppVar_42343;
	bool cppVar_42344;
	BIT_VEC cppVar_42346;
	BIT_VEC cppVar_42347;
	BIT_VEC cppVar_42348;
	bool cppVar_42349;
	BIT_VEC cppVar_42351;
	BIT_VEC cppVar_42352;
	BIT_VEC cppVar_42353;
	bool cppVar_42354;
	BIT_VEC cppVar_42356;
	BIT_VEC cppVar_42357;
	BIT_VEC cppVar_42358;
	bool cppVar_42359;
	BIT_VEC cppVar_42361;
	BIT_VEC cppVar_42362;
	BIT_VEC cppVar_42363;
	bool cppVar_42364;
	BIT_VEC cppVar_42365;
	BIT_VEC cppVar_42360;
	BIT_VEC cppVar_42355;
	BIT_VEC cppVar_42350;
	BIT_VEC cppVar_42345;
	BIT_VEC cppVar_42340;
	BIT_VEC cppVar_42335;
	BIT_VEC cppVar_42330;
	BIT_VEC cppVar_42325;
	BIT_VEC cppVar_42320;
	BIT_VEC cppVar_42315;
	BIT_VEC cppVar_42310;
	BIT_VEC cppVar_42305;
	BIT_VEC cppVar_42300;
	BIT_VEC cppVar_42295;
	BIT_VEC cppVar_42290;
	BIT_VEC cppVar_42285;
	BIT_VEC cppVar_42280;
	BIT_VEC cppVar_42275;
	BIT_VEC cppVar_42270;
	BIT_VEC cppVar_42265;
	BIT_VEC cppVar_42260;
	BIT_VEC cppVar_42250;
	bool cppVar_42366;
	BIT_VEC cppVar_42367;
	BIT_VEC cppVar_42368;
	BIT_VEC cppVar_42369;
	BIT_VEC cppVar_42370;
	BIT_VEC cppVar_42371;
	BIT_VEC cppVar_42372;
	BIT_VEC cppVar_42373;
	BIT_VEC cppVar_42374;
	BIT_VEC cppVar_42375;
	BIT_VEC cppVar_42249;
	BIT_VEC cppVar_42377;
	BIT_VEC cppVar_42378;
	bool cppVar_42379;
	BIT_VEC cppVar_42381;
	BIT_VEC cppVar_42382;
	BIT_VEC cppVar_42383;
	bool cppVar_42384;
	BIT_VEC cppVar_42385;
	BIT_VEC cppVar_42386;
	BIT_VEC cppVar_42387;
	BIT_VEC cppVar_42388;
	BIT_VEC cppVar_42389;
	BIT_VEC cppVar_42390;
	BIT_VEC cppVar_42391;
	BIT_VEC cppVar_42392;
	BIT_VEC cppVar_42393;
	BIT_VEC cppVar_42380;
	BIT_VEC cppVar_42395;
	BIT_VEC cppVar_42396;
	bool cppVar_42397;
	BIT_VEC cppVar_42398;
	BIT_VEC cppVar_42399;
	bool cppVar_42400;
	bool cppVar_42401;
	BIT_VEC cppVar_42402;
	BIT_VEC cppVar_42403;
	BIT_VEC cppVar_42404;
	BIT_VEC cppVar_42405;
	BIT_VEC cppVar_42406;
	BIT_VEC cppVar_42407;
	BIT_VEC cppVar_42408;
	BIT_VEC cppVar_42409;
	BIT_VEC cppVar_42410;
	BIT_VEC cppVar_42412;
	BIT_VEC cppVar_42413;
	bool cppVar_42414;
	BIT_VEC cppVar_42415;
	BIT_VEC cppVar_42416;
	bool cppVar_42417;
	bool cppVar_42418;
	BIT_VEC cppVar_42419;
	BIT_VEC cppVar_42420;
	BIT_VEC cppVar_42421;
	BIT_VEC cppVar_42422;
	BIT_VEC cppVar_42423;
	BIT_VEC cppVar_42424;
	BIT_VEC cppVar_42425;
	BIT_VEC cppVar_42426;
	BIT_VEC cppVar_42427;
	BIT_VEC cppVar_42429;
	BIT_VEC cppVar_42430;
	bool cppVar_42431;
	BIT_VEC cppVar_42432;
	BIT_VEC cppVar_42433;
	BIT_VEC cppVar_42434;
	BIT_VEC cppVar_42435;
	BIT_VEC cppVar_42436;
	BIT_VEC cppVar_42437;
	BIT_VEC cppVar_42438;
	BIT_VEC cppVar_42440;
	BIT_VEC cppVar_42441;
	bool cppVar_42442;
	BIT_VEC cppVar_42443;
	BIT_VEC cppVar_42444;
	BIT_VEC cppVar_42445;
	BIT_VEC cppVar_42447;
	BIT_VEC cppVar_42448;
	bool cppVar_42449;
	BIT_VEC cppVar_42451;
	bool cppVar_42452;
	BIT_VEC cppVar_42453;
	BIT_VEC cppVar_42454;
	BIT_VEC cppVar_42455;
	BIT_VEC cppVar_42456;
	BIT_VEC cppVar_42457;
	BIT_VEC cppVar_42458;
	BIT_VEC cppVar_42459;
	BIT_VEC cppVar_42460;
	BIT_VEC cppVar_42461;
	BIT_VEC cppVar_42450;
	BIT_VEC cppVar_42463;
	BIT_VEC cppVar_42464;
	bool cppVar_42465;
	BIT_VEC cppVar_42466;
	BIT_VEC cppVar_42467;
	bool cppVar_42468;
	bool cppVar_42469;
	BIT_VEC cppVar_42470;
	BIT_VEC cppVar_42471;
	BIT_VEC cppVar_42472;
	BIT_VEC cppVar_42473;
	BIT_VEC cppVar_42474;
	BIT_VEC cppVar_42475;
	BIT_VEC cppVar_42476;
	BIT_VEC cppVar_42477;
	BIT_VEC cppVar_42478;
	BIT_VEC cppVar_42480;
	BIT_VEC cppVar_42481;
	bool cppVar_42482;
	BIT_VEC cppVar_42484;
	bool cppVar_42485;
	BIT_VEC cppVar_42486;
	BIT_VEC cppVar_42487;
	BIT_VEC cppVar_42488;
	BIT_VEC cppVar_42489;
	BIT_VEC cppVar_42490;
	BIT_VEC cppVar_42491;
	BIT_VEC cppVar_42492;
	BIT_VEC cppVar_42493;
	BIT_VEC cppVar_42494;
	BIT_VEC cppVar_42483;
	BIT_VEC cppVar_42496;
	BIT_VEC cppVar_42497;
	bool cppVar_42498;
	BIT_VEC cppVar_42500;
	BIT_VEC cppVar_42501;
	bool cppVar_42502;
	BIT_VEC cppVar_42503;
	BIT_VEC cppVar_42504;
	BIT_VEC cppVar_42505;
	BIT_VEC cppVar_42506;
	BIT_VEC cppVar_42507;
	BIT_VEC cppVar_42508;
	BIT_VEC cppVar_42509;
	BIT_VEC cppVar_42510;
	BIT_VEC cppVar_42511;
	BIT_VEC cppVar_42499;
	BIT_VEC cppVar_42513;
	BIT_VEC cppVar_42514;
	bool cppVar_42515;
	BIT_VEC cppVar_42516;
	BIT_VEC cppVar_42517;
	bool cppVar_42518;
	BIT_VEC cppVar_42519;
	BIT_VEC cppVar_42520;
	bool cppVar_42521;
	BIT_VEC cppVar_42522;
	BIT_VEC cppVar_42523;
	bool cppVar_42524;
	BIT_VEC cppVar_42525;
	BIT_VEC cppVar_42526;
	bool cppVar_42527;
	BIT_VEC cppVar_42528;
	BIT_VEC cppVar_42529;
	bool cppVar_42530;
	bool cppVar_42531;
	bool cppVar_42532;
	bool cppVar_42533;
	bool cppVar_42534;
	bool cppVar_42535;
	BIT_VEC cppVar_42536;
	BIT_VEC cppVar_42537;
	BIT_VEC cppVar_42539;
	BIT_VEC cppVar_42540;
	bool cppVar_42541;
	BIT_VEC cppVar_42542;
	BIT_VEC cppVar_42543;
	bool cppVar_42544;
	bool cppVar_42545;
	BIT_VEC cppVar_42546;
	BIT_VEC cppVar_42547;
	BIT_VEC cppVar_42548;
	BIT_VEC cppVar_42549;
	BIT_VEC cppVar_42550;
	BIT_VEC cppVar_42551;
	BIT_VEC cppVar_42552;
	BIT_VEC cppVar_42553;
	BIT_VEC cppVar_42554;
	BIT_VEC cppVar_42556;
	BIT_VEC cppVar_42557;
	bool cppVar_42558;
	BIT_VEC cppVar_42560;
	BIT_VEC cppVar_42561;
	bool cppVar_42562;
	BIT_VEC cppVar_42563;
	BIT_VEC cppVar_42564;
	BIT_VEC cppVar_42565;
	BIT_VEC cppVar_42566;
	BIT_VEC cppVar_42567;
	BIT_VEC cppVar_42568;
	BIT_VEC cppVar_42569;
	BIT_VEC cppVar_42570;
	BIT_VEC cppVar_42571;
	BIT_VEC cppVar_42559;
	BIT_VEC cppVar_42573;
	BIT_VEC cppVar_42574;
	bool cppVar_42575;
	BIT_VEC cppVar_42579;
	BIT_VEC cppVar_42580;
	BIT_VEC cppVar_42581;
	BIT_VEC cppVar_42582;
	BIT_VEC cppVar_42583;
	bool cppVar_42584;
	BIT_VEC cppVar_42585;
	BIT_VEC cppVar_42586;
	BIT_VEC cppVar_42587;
	BIT_VEC cppVar_42588;
	BIT_VEC cppVar_42589;
	BIT_VEC cppVar_42590;
	BIT_VEC cppVar_42591;
	BIT_VEC cppVar_42592;
	BIT_VEC cppVar_42593;
	BIT_VEC cppVar_42594;
	BIT_VEC cppVar_42595;
	BIT_VEC cppVar_42578;
	BIT_VEC cppVar_42596;
	BIT_VEC cppVar_42597;
	bool cppVar_42598;
	BIT_VEC cppVar_42600;
	BIT_VEC cppVar_42601;
	BIT_VEC cppVar_42602;
	bool cppVar_42603;
	BIT_VEC cppVar_42604;
	BIT_VEC cppVar_42605;
	BIT_VEC cppVar_42606;
	BIT_VEC cppVar_42607;
	BIT_VEC cppVar_42608;
	BIT_VEC cppVar_42609;
	BIT_VEC cppVar_42610;
	BIT_VEC cppVar_42611;
	BIT_VEC cppVar_42612;
	BIT_VEC cppVar_42599;
	BIT_VEC cppVar_42613;
	BIT_VEC cppVar_42616;
	BIT_VEC cppVar_42617;
	BIT_VEC cppVar_42618;
	bool cppVar_42619;
	BIT_VEC cppVar_42620;
	BIT_VEC cppVar_42621;
	BIT_VEC cppVar_42622;
	BIT_VEC cppVar_42623;
	BIT_VEC cppVar_42624;
	BIT_VEC cppVar_42625;
	BIT_VEC cppVar_42626;
	BIT_VEC cppVar_42627;
	BIT_VEC cppVar_42628;
	BIT_VEC cppVar_42615;
	BIT_VEC cppVar_42629;
	bool cppVar_42630;
	BIT_VEC cppVar_42633;
	BIT_VEC cppVar_42634;
	BIT_VEC cppVar_42635;
	bool cppVar_42636;
	BIT_VEC cppVar_42637;
	BIT_VEC cppVar_42638;
	BIT_VEC cppVar_42639;
	BIT_VEC cppVar_42640;
	BIT_VEC cppVar_42641;
	BIT_VEC cppVar_42642;
	BIT_VEC cppVar_42643;
	BIT_VEC cppVar_42644;
	BIT_VEC cppVar_42645;
	BIT_VEC cppVar_42632;
	BIT_VEC cppVar_42646;
	bool cppVar_42647;
	BIT_VEC cppVar_42650;
	BIT_VEC cppVar_42651;
	BIT_VEC cppVar_42652;
	bool cppVar_42653;
	BIT_VEC cppVar_42654;
	BIT_VEC cppVar_42655;
	BIT_VEC cppVar_42656;
	BIT_VEC cppVar_42657;
	BIT_VEC cppVar_42658;
	BIT_VEC cppVar_42659;
	BIT_VEC cppVar_42660;
	BIT_VEC cppVar_42661;
	BIT_VEC cppVar_42662;
	BIT_VEC cppVar_42649;
	BIT_VEC cppVar_42663;
	bool cppVar_42664;
	BIT_VEC cppVar_42667;
	BIT_VEC cppVar_42668;
	BIT_VEC cppVar_42669;
	bool cppVar_42670;
	BIT_VEC cppVar_42671;
	BIT_VEC cppVar_42672;
	BIT_VEC cppVar_42673;
	BIT_VEC cppVar_42674;
	BIT_VEC cppVar_42675;
	BIT_VEC cppVar_42676;
	BIT_VEC cppVar_42677;
	BIT_VEC cppVar_42678;
	BIT_VEC cppVar_42679;
	BIT_VEC cppVar_42666;
	BIT_VEC cppVar_42680;
	bool cppVar_42681;
	BIT_VEC cppVar_42684;
	BIT_VEC cppVar_42685;
	BIT_VEC cppVar_42686;
	bool cppVar_42687;
	BIT_VEC cppVar_42688;
	BIT_VEC cppVar_42689;
	BIT_VEC cppVar_42690;
	BIT_VEC cppVar_42691;
	BIT_VEC cppVar_42692;
	BIT_VEC cppVar_42693;
	BIT_VEC cppVar_42694;
	BIT_VEC cppVar_42695;
	BIT_VEC cppVar_42696;
	BIT_VEC cppVar_42683;
	BIT_VEC cppVar_42697;
	bool cppVar_42698;
	BIT_VEC cppVar_42701;
	BIT_VEC cppVar_42702;
	BIT_VEC cppVar_42703;
	bool cppVar_42704;
	BIT_VEC cppVar_42705;
	BIT_VEC cppVar_42706;
	BIT_VEC cppVar_42707;
	BIT_VEC cppVar_42708;
	BIT_VEC cppVar_42709;
	BIT_VEC cppVar_42710;
	BIT_VEC cppVar_42711;
	BIT_VEC cppVar_42712;
	BIT_VEC cppVar_42713;
	BIT_VEC cppVar_42700;
	BIT_VEC cppVar_42714;
	bool cppVar_42715;
	BIT_VEC cppVar_42718;
	BIT_VEC cppVar_42719;
	BIT_VEC cppVar_42720;
	bool cppVar_42721;
	BIT_VEC cppVar_42722;
	BIT_VEC cppVar_42723;
	BIT_VEC cppVar_42724;
	BIT_VEC cppVar_42725;
	BIT_VEC cppVar_42726;
	BIT_VEC cppVar_42727;
	BIT_VEC cppVar_42728;
	BIT_VEC cppVar_42729;
	BIT_VEC cppVar_42730;
	BIT_VEC cppVar_42717;
	BIT_VEC cppVar_42731;
	bool cppVar_42732;
	BIT_VEC cppVar_42735;
	BIT_VEC cppVar_42736;
	BIT_VEC cppVar_42737;
	bool cppVar_42738;
	BIT_VEC cppVar_42739;
	BIT_VEC cppVar_42740;
	BIT_VEC cppVar_42741;
	BIT_VEC cppVar_42742;
	BIT_VEC cppVar_42743;
	BIT_VEC cppVar_42744;
	BIT_VEC cppVar_42745;
	BIT_VEC cppVar_42746;
	BIT_VEC cppVar_42747;
	BIT_VEC cppVar_42734;
	BIT_VEC cppVar_42748;
	bool cppVar_42749;
	BIT_VEC cppVar_42752;
	BIT_VEC cppVar_42753;
	BIT_VEC cppVar_42754;
	bool cppVar_42755;
	BIT_VEC cppVar_42756;
	BIT_VEC cppVar_42757;
	BIT_VEC cppVar_42758;
	BIT_VEC cppVar_42759;
	BIT_VEC cppVar_42760;
	BIT_VEC cppVar_42761;
	BIT_VEC cppVar_42762;
	BIT_VEC cppVar_42763;
	BIT_VEC cppVar_42764;
	BIT_VEC cppVar_42751;
	BIT_VEC cppVar_42765;
	bool cppVar_42766;
	BIT_VEC cppVar_42769;
	BIT_VEC cppVar_42770;
	BIT_VEC cppVar_42771;
	bool cppVar_42772;
	BIT_VEC cppVar_42773;
	BIT_VEC cppVar_42774;
	BIT_VEC cppVar_42775;
	BIT_VEC cppVar_42776;
	BIT_VEC cppVar_42777;
	BIT_VEC cppVar_42778;
	BIT_VEC cppVar_42779;
	BIT_VEC cppVar_42780;
	BIT_VEC cppVar_42781;
	BIT_VEC cppVar_42768;
	BIT_VEC cppVar_42782;
	bool cppVar_42783;
	BIT_VEC cppVar_42786;
	BIT_VEC cppVar_42787;
	BIT_VEC cppVar_42788;
	bool cppVar_42789;
	BIT_VEC cppVar_42790;
	BIT_VEC cppVar_42791;
	BIT_VEC cppVar_42792;
	BIT_VEC cppVar_42793;
	BIT_VEC cppVar_42794;
	BIT_VEC cppVar_42795;
	BIT_VEC cppVar_42796;
	BIT_VEC cppVar_42797;
	BIT_VEC cppVar_42798;
	BIT_VEC cppVar_42785;
	BIT_VEC cppVar_42799;
	bool cppVar_42800;
	BIT_VEC cppVar_42803;
	BIT_VEC cppVar_42804;
	BIT_VEC cppVar_42805;
	bool cppVar_42806;
	BIT_VEC cppVar_42807;
	BIT_VEC cppVar_42808;
	BIT_VEC cppVar_42809;
	BIT_VEC cppVar_42810;
	BIT_VEC cppVar_42811;
	BIT_VEC cppVar_42812;
	BIT_VEC cppVar_42813;
	BIT_VEC cppVar_42814;
	BIT_VEC cppVar_42815;
	BIT_VEC cppVar_42802;
	BIT_VEC cppVar_42816;
	bool cppVar_42817;
	BIT_VEC cppVar_42820;
	BIT_VEC cppVar_42821;
	BIT_VEC cppVar_42822;
	bool cppVar_42823;
	BIT_VEC cppVar_42824;
	BIT_VEC cppVar_42825;
	BIT_VEC cppVar_42826;
	BIT_VEC cppVar_42827;
	BIT_VEC cppVar_42828;
	BIT_VEC cppVar_42829;
	BIT_VEC cppVar_42830;
	BIT_VEC cppVar_42831;
	BIT_VEC cppVar_42832;
	BIT_VEC cppVar_42819;
	BIT_VEC cppVar_42833;
	bool cppVar_42834;
	BIT_VEC cppVar_42837;
	BIT_VEC cppVar_42838;
	BIT_VEC cppVar_42839;
	bool cppVar_42840;
	BIT_VEC cppVar_42841;
	BIT_VEC cppVar_42842;
	BIT_VEC cppVar_42843;
	BIT_VEC cppVar_42844;
	BIT_VEC cppVar_42845;
	BIT_VEC cppVar_42846;
	BIT_VEC cppVar_42847;
	BIT_VEC cppVar_42848;
	BIT_VEC cppVar_42849;
	BIT_VEC cppVar_42836;
	BIT_VEC cppVar_42850;
	bool cppVar_42851;
	BIT_VEC cppVar_42854;
	BIT_VEC cppVar_42855;
	BIT_VEC cppVar_42856;
	bool cppVar_42857;
	BIT_VEC cppVar_42858;
	BIT_VEC cppVar_42859;
	BIT_VEC cppVar_42860;
	BIT_VEC cppVar_42861;
	BIT_VEC cppVar_42862;
	BIT_VEC cppVar_42863;
	BIT_VEC cppVar_42864;
	BIT_VEC cppVar_42865;
	BIT_VEC cppVar_42866;
	BIT_VEC cppVar_42853;
	BIT_VEC cppVar_42867;
	bool cppVar_42868;
	BIT_VEC cppVar_42871;
	BIT_VEC cppVar_42872;
	BIT_VEC cppVar_42873;
	bool cppVar_42874;
	BIT_VEC cppVar_42875;
	BIT_VEC cppVar_42876;
	BIT_VEC cppVar_42877;
	BIT_VEC cppVar_42878;
	BIT_VEC cppVar_42879;
	BIT_VEC cppVar_42880;
	BIT_VEC cppVar_42881;
	BIT_VEC cppVar_42882;
	BIT_VEC cppVar_42883;
	BIT_VEC cppVar_42870;
	BIT_VEC cppVar_42884;
	bool cppVar_42885;
	BIT_VEC cppVar_42888;
	BIT_VEC cppVar_42889;
	BIT_VEC cppVar_42890;
	bool cppVar_42891;
	BIT_VEC cppVar_42892;
	BIT_VEC cppVar_42893;
	BIT_VEC cppVar_42894;
	BIT_VEC cppVar_42895;
	BIT_VEC cppVar_42896;
	BIT_VEC cppVar_42897;
	BIT_VEC cppVar_42898;
	BIT_VEC cppVar_42899;
	BIT_VEC cppVar_42900;
	BIT_VEC cppVar_42887;
	BIT_VEC cppVar_42901;
	bool cppVar_42902;
	BIT_VEC cppVar_42905;
	BIT_VEC cppVar_42906;
	BIT_VEC cppVar_42907;
	bool cppVar_42908;
	BIT_VEC cppVar_42909;
	BIT_VEC cppVar_42910;
	BIT_VEC cppVar_42911;
	BIT_VEC cppVar_42912;
	BIT_VEC cppVar_42913;
	BIT_VEC cppVar_42914;
	BIT_VEC cppVar_42915;
	BIT_VEC cppVar_42916;
	BIT_VEC cppVar_42917;
	BIT_VEC cppVar_42904;
	BIT_VEC cppVar_42918;
	bool cppVar_42919;
	BIT_VEC cppVar_42922;
	BIT_VEC cppVar_42923;
	BIT_VEC cppVar_42924;
	bool cppVar_42925;
	BIT_VEC cppVar_42926;
	BIT_VEC cppVar_42927;
	BIT_VEC cppVar_42928;
	BIT_VEC cppVar_42929;
	BIT_VEC cppVar_42930;
	BIT_VEC cppVar_42931;
	BIT_VEC cppVar_42932;
	BIT_VEC cppVar_42933;
	BIT_VEC cppVar_42934;
	BIT_VEC cppVar_42921;
	BIT_VEC cppVar_42935;
	bool cppVar_42936;
	BIT_VEC cppVar_42939;
	BIT_VEC cppVar_42940;
	BIT_VEC cppVar_42941;
	bool cppVar_42942;
	BIT_VEC cppVar_42943;
	BIT_VEC cppVar_42944;
	BIT_VEC cppVar_42945;
	BIT_VEC cppVar_42946;
	BIT_VEC cppVar_42947;
	BIT_VEC cppVar_42948;
	BIT_VEC cppVar_42949;
	BIT_VEC cppVar_42950;
	BIT_VEC cppVar_42951;
	BIT_VEC cppVar_42938;
	BIT_VEC cppVar_42952;
	bool cppVar_42953;
	BIT_VEC cppVar_42956;
	BIT_VEC cppVar_42957;
	BIT_VEC cppVar_42958;
	bool cppVar_42959;
	BIT_VEC cppVar_42960;
	BIT_VEC cppVar_42961;
	BIT_VEC cppVar_42962;
	BIT_VEC cppVar_42963;
	BIT_VEC cppVar_42964;
	BIT_VEC cppVar_42965;
	BIT_VEC cppVar_42966;
	BIT_VEC cppVar_42967;
	BIT_VEC cppVar_42968;
	BIT_VEC cppVar_42955;
	BIT_VEC cppVar_42969;
	bool cppVar_42970;
	BIT_VEC cppVar_42971;
	BIT_VEC cppVar_42954;
	BIT_VEC cppVar_42937;
	BIT_VEC cppVar_42920;
	BIT_VEC cppVar_42903;
	BIT_VEC cppVar_42886;
	BIT_VEC cppVar_42869;
	BIT_VEC cppVar_42852;
	BIT_VEC cppVar_42835;
	BIT_VEC cppVar_42818;
	BIT_VEC cppVar_42801;
	BIT_VEC cppVar_42784;
	BIT_VEC cppVar_42767;
	BIT_VEC cppVar_42750;
	BIT_VEC cppVar_42733;
	BIT_VEC cppVar_42716;
	BIT_VEC cppVar_42699;
	BIT_VEC cppVar_42682;
	BIT_VEC cppVar_42665;
	BIT_VEC cppVar_42648;
	BIT_VEC cppVar_42631;
	BIT_VEC cppVar_42614;
	BIT_VEC cppVar_42577;
	BIT_VEC cppVar_42972;
	BIT_VEC cppVar_42973;
	BIT_VEC cppVar_42974;
	BIT_VEC cppVar_42975;
	BIT_VEC cppVar_42976;
	bool cppVar_42977;
	BIT_VEC cppVar_42978;
	BIT_VEC cppVar_42979;
	BIT_VEC cppVar_42980;
	BIT_VEC cppVar_42981;
	BIT_VEC cppVar_42982;
	BIT_VEC cppVar_42983;
	BIT_VEC cppVar_42984;
	BIT_VEC cppVar_42985;
	BIT_VEC cppVar_42986;
	BIT_VEC cppVar_42576;
	BIT_VEC cppVar_42988;
	BIT_VEC cppVar_42989;
	bool cppVar_42990;
	BIT_VEC cppVar_42991;
	BIT_VEC cppVar_42992;
	bool cppVar_42993;
	bool cppVar_42994;
	BIT_VEC cppVar_42995;
	BIT_VEC cppVar_42996;
	BIT_VEC cppVar_42997;
	BIT_VEC cppVar_42998;
	BIT_VEC cppVar_42999;
	BIT_VEC cppVar_43001;
	BIT_VEC cppVar_43002;
	bool cppVar_43003;
	BIT_VEC cppVar_43004;
	BIT_VEC cppVar_43005;
	bool cppVar_43006;
	bool cppVar_43007;
	BIT_VEC cppVar_43008;
	BIT_VEC cppVar_43009;
	BIT_VEC cppVar_43010;
	BIT_VEC cppVar_43011;
	BIT_VEC cppVar_43012;
	BIT_VEC cppVar_43013;
	BIT_VEC cppVar_43014;
	BIT_VEC cppVar_43015;
	BIT_VEC cppVar_43016;
	BIT_VEC cppVar_43018;
	BIT_VEC cppVar_43019;
	bool cppVar_43020;
	BIT_VEC cppVar_43021;
	BIT_VEC cppVar_43022;
	bool cppVar_43023;
	bool cppVar_43024;
	BIT_VEC cppVar_43028;
	BIT_VEC cppVar_43029;
	BIT_VEC cppVar_43030;
	BIT_VEC cppVar_43031;
	BIT_VEC cppVar_43032;
	bool cppVar_43033;
	BIT_VEC cppVar_43034;
	BIT_VEC cppVar_43035;
	BIT_VEC cppVar_43036;
	BIT_VEC cppVar_43037;
	BIT_VEC cppVar_43038;
	BIT_VEC cppVar_43039;
	BIT_VEC cppVar_43040;
	BIT_VEC cppVar_43041;
	BIT_VEC cppVar_43042;
	BIT_VEC cppVar_43043;
	BIT_VEC cppVar_43044;
	BIT_VEC cppVar_43027;
	BIT_VEC cppVar_43045;
	BIT_VEC cppVar_43046;
	bool cppVar_43047;
	BIT_VEC cppVar_43049;
	BIT_VEC cppVar_43050;
	BIT_VEC cppVar_43051;
	bool cppVar_43052;
	BIT_VEC cppVar_43053;
	BIT_VEC cppVar_43054;
	BIT_VEC cppVar_43055;
	BIT_VEC cppVar_43056;
	BIT_VEC cppVar_43057;
	BIT_VEC cppVar_43058;
	BIT_VEC cppVar_43059;
	BIT_VEC cppVar_43060;
	BIT_VEC cppVar_43061;
	BIT_VEC cppVar_43048;
	BIT_VEC cppVar_43062;
	BIT_VEC cppVar_43065;
	BIT_VEC cppVar_43066;
	BIT_VEC cppVar_43067;
	bool cppVar_43068;
	BIT_VEC cppVar_43069;
	BIT_VEC cppVar_43070;
	BIT_VEC cppVar_43071;
	BIT_VEC cppVar_43072;
	BIT_VEC cppVar_43073;
	BIT_VEC cppVar_43074;
	BIT_VEC cppVar_43075;
	BIT_VEC cppVar_43076;
	BIT_VEC cppVar_43077;
	BIT_VEC cppVar_43064;
	BIT_VEC cppVar_43078;
	bool cppVar_43079;
	BIT_VEC cppVar_43082;
	BIT_VEC cppVar_43083;
	BIT_VEC cppVar_43084;
	bool cppVar_43085;
	BIT_VEC cppVar_43086;
	BIT_VEC cppVar_43087;
	BIT_VEC cppVar_43088;
	BIT_VEC cppVar_43089;
	BIT_VEC cppVar_43090;
	BIT_VEC cppVar_43091;
	BIT_VEC cppVar_43092;
	BIT_VEC cppVar_43093;
	BIT_VEC cppVar_43094;
	BIT_VEC cppVar_43081;
	BIT_VEC cppVar_43095;
	bool cppVar_43096;
	BIT_VEC cppVar_43099;
	BIT_VEC cppVar_43100;
	BIT_VEC cppVar_43101;
	bool cppVar_43102;
	BIT_VEC cppVar_43103;
	BIT_VEC cppVar_43104;
	BIT_VEC cppVar_43105;
	BIT_VEC cppVar_43106;
	BIT_VEC cppVar_43107;
	BIT_VEC cppVar_43108;
	BIT_VEC cppVar_43109;
	BIT_VEC cppVar_43110;
	BIT_VEC cppVar_43111;
	BIT_VEC cppVar_43098;
	BIT_VEC cppVar_43112;
	bool cppVar_43113;
	BIT_VEC cppVar_43116;
	BIT_VEC cppVar_43117;
	BIT_VEC cppVar_43118;
	bool cppVar_43119;
	BIT_VEC cppVar_43120;
	BIT_VEC cppVar_43121;
	BIT_VEC cppVar_43122;
	BIT_VEC cppVar_43123;
	BIT_VEC cppVar_43124;
	BIT_VEC cppVar_43125;
	BIT_VEC cppVar_43126;
	BIT_VEC cppVar_43127;
	BIT_VEC cppVar_43128;
	BIT_VEC cppVar_43115;
	BIT_VEC cppVar_43129;
	bool cppVar_43130;
	BIT_VEC cppVar_43133;
	BIT_VEC cppVar_43134;
	BIT_VEC cppVar_43135;
	bool cppVar_43136;
	BIT_VEC cppVar_43137;
	BIT_VEC cppVar_43138;
	BIT_VEC cppVar_43139;
	BIT_VEC cppVar_43140;
	BIT_VEC cppVar_43141;
	BIT_VEC cppVar_43142;
	BIT_VEC cppVar_43143;
	BIT_VEC cppVar_43144;
	BIT_VEC cppVar_43145;
	BIT_VEC cppVar_43132;
	BIT_VEC cppVar_43146;
	bool cppVar_43147;
	BIT_VEC cppVar_43150;
	BIT_VEC cppVar_43151;
	BIT_VEC cppVar_43152;
	bool cppVar_43153;
	BIT_VEC cppVar_43154;
	BIT_VEC cppVar_43155;
	BIT_VEC cppVar_43156;
	BIT_VEC cppVar_43157;
	BIT_VEC cppVar_43158;
	BIT_VEC cppVar_43159;
	BIT_VEC cppVar_43160;
	BIT_VEC cppVar_43161;
	BIT_VEC cppVar_43162;
	BIT_VEC cppVar_43149;
	BIT_VEC cppVar_43163;
	bool cppVar_43164;
	BIT_VEC cppVar_43167;
	BIT_VEC cppVar_43168;
	BIT_VEC cppVar_43169;
	bool cppVar_43170;
	BIT_VEC cppVar_43171;
	BIT_VEC cppVar_43172;
	BIT_VEC cppVar_43173;
	BIT_VEC cppVar_43174;
	BIT_VEC cppVar_43175;
	BIT_VEC cppVar_43176;
	BIT_VEC cppVar_43177;
	BIT_VEC cppVar_43178;
	BIT_VEC cppVar_43179;
	BIT_VEC cppVar_43166;
	BIT_VEC cppVar_43180;
	bool cppVar_43181;
	BIT_VEC cppVar_43184;
	BIT_VEC cppVar_43185;
	BIT_VEC cppVar_43186;
	bool cppVar_43187;
	BIT_VEC cppVar_43188;
	BIT_VEC cppVar_43189;
	BIT_VEC cppVar_43190;
	BIT_VEC cppVar_43191;
	BIT_VEC cppVar_43192;
	BIT_VEC cppVar_43193;
	BIT_VEC cppVar_43194;
	BIT_VEC cppVar_43195;
	BIT_VEC cppVar_43196;
	BIT_VEC cppVar_43183;
	BIT_VEC cppVar_43197;
	bool cppVar_43198;
	BIT_VEC cppVar_43201;
	BIT_VEC cppVar_43202;
	BIT_VEC cppVar_43203;
	bool cppVar_43204;
	BIT_VEC cppVar_43205;
	BIT_VEC cppVar_43206;
	BIT_VEC cppVar_43207;
	BIT_VEC cppVar_43208;
	BIT_VEC cppVar_43209;
	BIT_VEC cppVar_43210;
	BIT_VEC cppVar_43211;
	BIT_VEC cppVar_43212;
	BIT_VEC cppVar_43213;
	BIT_VEC cppVar_43200;
	BIT_VEC cppVar_43214;
	bool cppVar_43215;
	BIT_VEC cppVar_43218;
	BIT_VEC cppVar_43219;
	BIT_VEC cppVar_43220;
	bool cppVar_43221;
	BIT_VEC cppVar_43222;
	BIT_VEC cppVar_43223;
	BIT_VEC cppVar_43224;
	BIT_VEC cppVar_43225;
	BIT_VEC cppVar_43226;
	BIT_VEC cppVar_43227;
	BIT_VEC cppVar_43228;
	BIT_VEC cppVar_43229;
	BIT_VEC cppVar_43230;
	BIT_VEC cppVar_43217;
	BIT_VEC cppVar_43231;
	bool cppVar_43232;
	BIT_VEC cppVar_43235;
	BIT_VEC cppVar_43236;
	BIT_VEC cppVar_43237;
	bool cppVar_43238;
	BIT_VEC cppVar_43239;
	BIT_VEC cppVar_43240;
	BIT_VEC cppVar_43241;
	BIT_VEC cppVar_43242;
	BIT_VEC cppVar_43243;
	BIT_VEC cppVar_43244;
	BIT_VEC cppVar_43245;
	BIT_VEC cppVar_43246;
	BIT_VEC cppVar_43247;
	BIT_VEC cppVar_43234;
	BIT_VEC cppVar_43248;
	bool cppVar_43249;
	BIT_VEC cppVar_43252;
	BIT_VEC cppVar_43253;
	BIT_VEC cppVar_43254;
	bool cppVar_43255;
	BIT_VEC cppVar_43256;
	BIT_VEC cppVar_43257;
	BIT_VEC cppVar_43258;
	BIT_VEC cppVar_43259;
	BIT_VEC cppVar_43260;
	BIT_VEC cppVar_43261;
	BIT_VEC cppVar_43262;
	BIT_VEC cppVar_43263;
	BIT_VEC cppVar_43264;
	BIT_VEC cppVar_43251;
	BIT_VEC cppVar_43265;
	bool cppVar_43266;
	BIT_VEC cppVar_43269;
	BIT_VEC cppVar_43270;
	BIT_VEC cppVar_43271;
	bool cppVar_43272;
	BIT_VEC cppVar_43273;
	BIT_VEC cppVar_43274;
	BIT_VEC cppVar_43275;
	BIT_VEC cppVar_43276;
	BIT_VEC cppVar_43277;
	BIT_VEC cppVar_43278;
	BIT_VEC cppVar_43279;
	BIT_VEC cppVar_43280;
	BIT_VEC cppVar_43281;
	BIT_VEC cppVar_43268;
	BIT_VEC cppVar_43282;
	bool cppVar_43283;
	BIT_VEC cppVar_43286;
	BIT_VEC cppVar_43287;
	BIT_VEC cppVar_43288;
	bool cppVar_43289;
	BIT_VEC cppVar_43290;
	BIT_VEC cppVar_43291;
	BIT_VEC cppVar_43292;
	BIT_VEC cppVar_43293;
	BIT_VEC cppVar_43294;
	BIT_VEC cppVar_43295;
	BIT_VEC cppVar_43296;
	BIT_VEC cppVar_43297;
	BIT_VEC cppVar_43298;
	BIT_VEC cppVar_43285;
	BIT_VEC cppVar_43299;
	bool cppVar_43300;
	BIT_VEC cppVar_43303;
	BIT_VEC cppVar_43304;
	BIT_VEC cppVar_43305;
	bool cppVar_43306;
	BIT_VEC cppVar_43307;
	BIT_VEC cppVar_43308;
	BIT_VEC cppVar_43309;
	BIT_VEC cppVar_43310;
	BIT_VEC cppVar_43311;
	BIT_VEC cppVar_43312;
	BIT_VEC cppVar_43313;
	BIT_VEC cppVar_43314;
	BIT_VEC cppVar_43315;
	BIT_VEC cppVar_43302;
	BIT_VEC cppVar_43316;
	bool cppVar_43317;
	BIT_VEC cppVar_43320;
	BIT_VEC cppVar_43321;
	BIT_VEC cppVar_43322;
	bool cppVar_43323;
	BIT_VEC cppVar_43324;
	BIT_VEC cppVar_43325;
	BIT_VEC cppVar_43326;
	BIT_VEC cppVar_43327;
	BIT_VEC cppVar_43328;
	BIT_VEC cppVar_43329;
	BIT_VEC cppVar_43330;
	BIT_VEC cppVar_43331;
	BIT_VEC cppVar_43332;
	BIT_VEC cppVar_43319;
	BIT_VEC cppVar_43333;
	bool cppVar_43334;
	BIT_VEC cppVar_43337;
	BIT_VEC cppVar_43338;
	BIT_VEC cppVar_43339;
	bool cppVar_43340;
	BIT_VEC cppVar_43341;
	BIT_VEC cppVar_43342;
	BIT_VEC cppVar_43343;
	BIT_VEC cppVar_43344;
	BIT_VEC cppVar_43345;
	BIT_VEC cppVar_43346;
	BIT_VEC cppVar_43347;
	BIT_VEC cppVar_43348;
	BIT_VEC cppVar_43349;
	BIT_VEC cppVar_43336;
	BIT_VEC cppVar_43350;
	bool cppVar_43351;
	BIT_VEC cppVar_43354;
	BIT_VEC cppVar_43355;
	BIT_VEC cppVar_43356;
	bool cppVar_43357;
	BIT_VEC cppVar_43358;
	BIT_VEC cppVar_43359;
	BIT_VEC cppVar_43360;
	BIT_VEC cppVar_43361;
	BIT_VEC cppVar_43362;
	BIT_VEC cppVar_43363;
	BIT_VEC cppVar_43364;
	BIT_VEC cppVar_43365;
	BIT_VEC cppVar_43366;
	BIT_VEC cppVar_43353;
	BIT_VEC cppVar_43367;
	bool cppVar_43368;
	BIT_VEC cppVar_43371;
	BIT_VEC cppVar_43372;
	BIT_VEC cppVar_43373;
	bool cppVar_43374;
	BIT_VEC cppVar_43375;
	BIT_VEC cppVar_43376;
	BIT_VEC cppVar_43377;
	BIT_VEC cppVar_43378;
	BIT_VEC cppVar_43379;
	BIT_VEC cppVar_43380;
	BIT_VEC cppVar_43381;
	BIT_VEC cppVar_43382;
	BIT_VEC cppVar_43383;
	BIT_VEC cppVar_43370;
	BIT_VEC cppVar_43384;
	bool cppVar_43385;
	BIT_VEC cppVar_43388;
	BIT_VEC cppVar_43389;
	BIT_VEC cppVar_43390;
	bool cppVar_43391;
	BIT_VEC cppVar_43392;
	BIT_VEC cppVar_43393;
	BIT_VEC cppVar_43394;
	BIT_VEC cppVar_43395;
	BIT_VEC cppVar_43396;
	BIT_VEC cppVar_43397;
	BIT_VEC cppVar_43398;
	BIT_VEC cppVar_43399;
	BIT_VEC cppVar_43400;
	BIT_VEC cppVar_43387;
	BIT_VEC cppVar_43401;
	bool cppVar_43402;
	BIT_VEC cppVar_43405;
	BIT_VEC cppVar_43406;
	BIT_VEC cppVar_43407;
	bool cppVar_43408;
	BIT_VEC cppVar_43409;
	BIT_VEC cppVar_43410;
	BIT_VEC cppVar_43411;
	BIT_VEC cppVar_43412;
	BIT_VEC cppVar_43413;
	BIT_VEC cppVar_43414;
	BIT_VEC cppVar_43415;
	BIT_VEC cppVar_43416;
	BIT_VEC cppVar_43417;
	BIT_VEC cppVar_43404;
	BIT_VEC cppVar_43418;
	bool cppVar_43419;
	BIT_VEC cppVar_43420;
	BIT_VEC cppVar_43403;
	BIT_VEC cppVar_43386;
	BIT_VEC cppVar_43369;
	BIT_VEC cppVar_43352;
	BIT_VEC cppVar_43335;
	BIT_VEC cppVar_43318;
	BIT_VEC cppVar_43301;
	BIT_VEC cppVar_43284;
	BIT_VEC cppVar_43267;
	BIT_VEC cppVar_43250;
	BIT_VEC cppVar_43233;
	BIT_VEC cppVar_43216;
	BIT_VEC cppVar_43199;
	BIT_VEC cppVar_43182;
	BIT_VEC cppVar_43165;
	BIT_VEC cppVar_43148;
	BIT_VEC cppVar_43131;
	BIT_VEC cppVar_43114;
	BIT_VEC cppVar_43097;
	BIT_VEC cppVar_43080;
	BIT_VEC cppVar_43063;
	BIT_VEC cppVar_43026;
	BIT_VEC cppVar_43421;
	BIT_VEC cppVar_43422;
	BIT_VEC cppVar_43423;
	BIT_VEC cppVar_43424;
	BIT_VEC cppVar_43425;
	bool cppVar_43426;
	BIT_VEC cppVar_43427;
	BIT_VEC cppVar_43428;
	BIT_VEC cppVar_43429;
	BIT_VEC cppVar_43430;
	BIT_VEC cppVar_43431;
	BIT_VEC cppVar_43432;
	BIT_VEC cppVar_43433;
	BIT_VEC cppVar_43434;
	BIT_VEC cppVar_43435;
	BIT_VEC cppVar_43025;
	BIT_VEC cppVar_43437;
	BIT_VEC cppVar_43438;
	bool cppVar_43439;
	BIT_VEC cppVar_43440;
	BIT_VEC cppVar_43441;
	bool cppVar_43442;
	BIT_VEC cppVar_43443;
	BIT_VEC cppVar_43444;
	bool cppVar_43445;
	BIT_VEC cppVar_43446;
	BIT_VEC cppVar_43447;
	bool cppVar_43448;
	BIT_VEC cppVar_43449;
	BIT_VEC cppVar_43450;
	bool cppVar_43451;
	BIT_VEC cppVar_43452;
	BIT_VEC cppVar_43453;
	bool cppVar_43454;
	BIT_VEC cppVar_43455;
	BIT_VEC cppVar_43456;
	bool cppVar_43457;
	BIT_VEC cppVar_43458;
	BIT_VEC cppVar_43459;
	bool cppVar_43460;
	BIT_VEC cppVar_43461;
	BIT_VEC cppVar_43462;
	bool cppVar_43463;
	BIT_VEC cppVar_43464;
	BIT_VEC cppVar_43465;
	bool cppVar_43466;
	BIT_VEC cppVar_43467;
	BIT_VEC cppVar_43468;
	bool cppVar_43469;
	BIT_VEC cppVar_43470;
	BIT_VEC cppVar_43471;
	bool cppVar_43472;
	BIT_VEC cppVar_43473;
	BIT_VEC cppVar_43474;
	bool cppVar_43475;
	BIT_VEC cppVar_43476;
	BIT_VEC cppVar_43477;
	bool cppVar_43478;
	BIT_VEC cppVar_43479;
	BIT_VEC cppVar_43480;
	bool cppVar_43481;
	BIT_VEC cppVar_43482;
	BIT_VEC cppVar_43483;
	bool cppVar_43484;
	BIT_VEC cppVar_43485;
	BIT_VEC cppVar_43486;
	bool cppVar_43487;
	BIT_VEC cppVar_43488;
	BIT_VEC cppVar_43489;
	bool cppVar_43490;
	BIT_VEC cppVar_43491;
	BIT_VEC cppVar_43492;
	bool cppVar_43493;
	BIT_VEC cppVar_43494;
	BIT_VEC cppVar_43495;
	bool cppVar_43496;
	BIT_VEC cppVar_43497;
	BIT_VEC cppVar_43498;
	bool cppVar_43499;
	BIT_VEC cppVar_43500;
	BIT_VEC cppVar_43501;
	bool cppVar_43502;
	BIT_VEC cppVar_43503;
	BIT_VEC cppVar_43504;
	bool cppVar_43505;
	BIT_VEC cppVar_43506;
	BIT_VEC cppVar_43507;
	bool cppVar_43508;
	BIT_VEC cppVar_43509;
	BIT_VEC cppVar_43510;
	bool cppVar_43511;
	BIT_VEC cppVar_43512;
	BIT_VEC cppVar_43513;
	bool cppVar_43514;
	BIT_VEC cppVar_43515;
	BIT_VEC cppVar_43516;
	bool cppVar_43517;
	BIT_VEC cppVar_43518;
	BIT_VEC cppVar_43519;
	bool cppVar_43520;
	BIT_VEC cppVar_43521;
	BIT_VEC cppVar_43522;
	bool cppVar_43523;
	BIT_VEC cppVar_43524;
	BIT_VEC cppVar_43525;
	bool cppVar_43526;
	BIT_VEC cppVar_43527;
	BIT_VEC cppVar_43528;
	bool cppVar_43529;
	BIT_VEC cppVar_43530;
	BIT_VEC cppVar_43531;
	bool cppVar_43532;
	BIT_VEC cppVar_43533;
	BIT_VEC cppVar_43534;
	bool cppVar_43535;
	BIT_VEC cppVar_43536;
	BIT_VEC cppVar_43537;
	bool cppVar_43538;
	BIT_VEC cppVar_43539;
	BIT_VEC cppVar_43540;
	bool cppVar_43541;
	BIT_VEC cppVar_43542;
	BIT_VEC cppVar_43543;
	bool cppVar_43544;
	BIT_VEC cppVar_43545;
	BIT_VEC cppVar_43546;
	bool cppVar_43547;
	BIT_VEC cppVar_43548;
	BIT_VEC cppVar_43549;
	bool cppVar_43550;
	BIT_VEC cppVar_43551;
	BIT_VEC cppVar_43552;
	bool cppVar_43553;
	BIT_VEC cppVar_43554;
	BIT_VEC cppVar_43555;
	bool cppVar_43556;
	BIT_VEC cppVar_43557;
	BIT_VEC cppVar_43558;
	bool cppVar_43559;
	BIT_VEC cppVar_43560;
	BIT_VEC cppVar_43561;
	bool cppVar_43562;
	BIT_VEC cppVar_43563;
	BIT_VEC cppVar_43564;
	bool cppVar_43565;
	BIT_VEC cppVar_43566;
	BIT_VEC cppVar_43567;
	bool cppVar_43568;
	BIT_VEC cppVar_43569;
	BIT_VEC cppVar_43570;
	bool cppVar_43571;
	BIT_VEC cppVar_43572;
	BIT_VEC cppVar_43573;
	bool cppVar_43574;
	BIT_VEC cppVar_43575;
	BIT_VEC cppVar_43576;
	bool cppVar_43577;
	BIT_VEC cppVar_43578;
	BIT_VEC cppVar_43579;
	bool cppVar_43580;
	BIT_VEC cppVar_43581;
	BIT_VEC cppVar_43582;
	bool cppVar_43583;
	BIT_VEC cppVar_43584;
	BIT_VEC cppVar_43585;
	bool cppVar_43586;
	BIT_VEC cppVar_43587;
	BIT_VEC cppVar_43588;
	bool cppVar_43589;
	BIT_VEC cppVar_43590;
	BIT_VEC cppVar_43591;
	bool cppVar_43592;
	BIT_VEC cppVar_43593;
	BIT_VEC cppVar_43594;
	bool cppVar_43595;
	BIT_VEC cppVar_43596;
	BIT_VEC cppVar_43597;
	bool cppVar_43598;
	BIT_VEC cppVar_43599;
	BIT_VEC cppVar_43600;
	bool cppVar_43601;
	BIT_VEC cppVar_43602;
	BIT_VEC cppVar_43603;
	bool cppVar_43604;
	BIT_VEC cppVar_43605;
	BIT_VEC cppVar_43606;
	bool cppVar_43607;
	BIT_VEC cppVar_43608;
	BIT_VEC cppVar_43609;
	bool cppVar_43610;
	BIT_VEC cppVar_43611;
	BIT_VEC cppVar_43612;
	bool cppVar_43613;
	BIT_VEC cppVar_43614;
	BIT_VEC cppVar_43615;
	bool cppVar_43616;
	BIT_VEC cppVar_43617;
	BIT_VEC cppVar_43618;
	bool cppVar_43619;
	BIT_VEC cppVar_43620;
	BIT_VEC cppVar_43621;
	bool cppVar_43622;
	bool cppVar_43623;
	bool cppVar_43624;
	bool cppVar_43625;
	bool cppVar_43626;
	bool cppVar_43627;
	bool cppVar_43628;
	bool cppVar_43629;
	bool cppVar_43630;
	bool cppVar_43631;
	bool cppVar_43632;
	bool cppVar_43633;
	bool cppVar_43634;
	bool cppVar_43635;
	bool cppVar_43636;
	bool cppVar_43637;
	bool cppVar_43638;
	bool cppVar_43639;
	bool cppVar_43640;
	bool cppVar_43641;
	bool cppVar_43642;
	bool cppVar_43643;
	bool cppVar_43644;
	bool cppVar_43645;
	bool cppVar_43646;
	bool cppVar_43647;
	bool cppVar_43648;
	bool cppVar_43649;
	bool cppVar_43650;
	bool cppVar_43651;
	bool cppVar_43652;
	bool cppVar_43653;
	bool cppVar_43654;
	bool cppVar_43655;
	bool cppVar_43656;
	bool cppVar_43657;
	bool cppVar_43658;
	bool cppVar_43659;
	bool cppVar_43660;
	bool cppVar_43661;
	bool cppVar_43662;
	bool cppVar_43663;
	bool cppVar_43664;
	bool cppVar_43665;
	bool cppVar_43666;
	bool cppVar_43667;
	bool cppVar_43668;
	bool cppVar_43669;
	bool cppVar_43670;
	bool cppVar_43671;
	bool cppVar_43672;
	bool cppVar_43673;
	bool cppVar_43674;
	bool cppVar_43675;
	bool cppVar_43676;
	bool cppVar_43677;
	bool cppVar_43678;
	bool cppVar_43679;
	bool cppVar_43680;
	bool cppVar_43681;
	bool cppVar_43682;
	bool cppVar_43683;
	BIT_VEC cppVar_43684;
	BIT_VEC cppVar_43685;
	BIT_VEC cppVar_43687;
	BIT_VEC cppVar_43688;
	bool cppVar_43689;
	BIT_VEC cppVar_43690;
	BIT_VEC cppVar_43691;
	bool cppVar_43692;
	bool cppVar_43693;
	BIT_VEC cppVar_43694;
	BIT_VEC cppVar_43695;
	BIT_VEC cppVar_43696;
	BIT_VEC cppVar_43697;
	BIT_VEC cppVar_43698;
	BIT_VEC cppVar_43699;
	BIT_VEC cppVar_43700;
	BIT_VEC cppVar_43702;
	BIT_VEC cppVar_43703;
	bool cppVar_43704;
	BIT_VEC cppVar_43705;
	BIT_VEC cppVar_43706;
	bool cppVar_43707;
	bool cppVar_43708;
	BIT_VEC cppVar_43709;
	BIT_VEC cppVar_43710;
	BIT_VEC cppVar_43711;
	BIT_VEC cppVar_43712;
	BIT_VEC cppVar_43713;
	BIT_VEC cppVar_43714;
	BIT_VEC cppVar_43715;
	BIT_VEC cppVar_43716;
	BIT_VEC cppVar_43717;
	BIT_VEC cppVar_43719;
	BIT_VEC cppVar_43720;
	bool cppVar_43721;
	BIT_VEC cppVar_43722;
	BIT_VEC cppVar_43723;
	bool cppVar_43724;
	BIT_VEC cppVar_43725;
	BIT_VEC cppVar_43726;
	bool cppVar_43727;
	BIT_VEC cppVar_43728;
	BIT_VEC cppVar_43729;
	bool cppVar_43730;
	BIT_VEC cppVar_43731;
	BIT_VEC cppVar_43732;
	bool cppVar_43733;
	BIT_VEC cppVar_43734;
	BIT_VEC cppVar_43735;
	bool cppVar_43736;
	BIT_VEC cppVar_43737;
	BIT_VEC cppVar_43738;
	bool cppVar_43739;
	BIT_VEC cppVar_43740;
	BIT_VEC cppVar_43741;
	bool cppVar_43742;
	BIT_VEC cppVar_43743;
	BIT_VEC cppVar_43744;
	bool cppVar_43745;
	BIT_VEC cppVar_43746;
	BIT_VEC cppVar_43747;
	bool cppVar_43748;
	BIT_VEC cppVar_43749;
	BIT_VEC cppVar_43750;
	bool cppVar_43751;
	BIT_VEC cppVar_43752;
	BIT_VEC cppVar_43753;
	bool cppVar_43754;
	BIT_VEC cppVar_43755;
	BIT_VEC cppVar_43756;
	bool cppVar_43757;
	BIT_VEC cppVar_43758;
	BIT_VEC cppVar_43759;
	bool cppVar_43760;
	BIT_VEC cppVar_43761;
	BIT_VEC cppVar_43762;
	bool cppVar_43763;
	BIT_VEC cppVar_43764;
	BIT_VEC cppVar_43765;
	bool cppVar_43766;
	BIT_VEC cppVar_43767;
	BIT_VEC cppVar_43768;
	bool cppVar_43769;
	BIT_VEC cppVar_43770;
	BIT_VEC cppVar_43771;
	bool cppVar_43772;
	BIT_VEC cppVar_43773;
	BIT_VEC cppVar_43774;
	bool cppVar_43775;
	BIT_VEC cppVar_43776;
	BIT_VEC cppVar_43777;
	bool cppVar_43778;
	BIT_VEC cppVar_43779;
	BIT_VEC cppVar_43780;
	bool cppVar_43781;
	BIT_VEC cppVar_43782;
	BIT_VEC cppVar_43783;
	bool cppVar_43784;
	BIT_VEC cppVar_43785;
	BIT_VEC cppVar_43786;
	bool cppVar_43787;
	BIT_VEC cppVar_43788;
	BIT_VEC cppVar_43789;
	bool cppVar_43790;
	BIT_VEC cppVar_43791;
	BIT_VEC cppVar_43792;
	bool cppVar_43793;
	BIT_VEC cppVar_43794;
	BIT_VEC cppVar_43795;
	bool cppVar_43796;
	BIT_VEC cppVar_43797;
	BIT_VEC cppVar_43798;
	bool cppVar_43799;
	BIT_VEC cppVar_43800;
	BIT_VEC cppVar_43801;
	bool cppVar_43802;
	BIT_VEC cppVar_43803;
	BIT_VEC cppVar_43804;
	bool cppVar_43805;
	BIT_VEC cppVar_43806;
	BIT_VEC cppVar_43807;
	bool cppVar_43808;
	BIT_VEC cppVar_43809;
	BIT_VEC cppVar_43810;
	bool cppVar_43811;
	BIT_VEC cppVar_43812;
	BIT_VEC cppVar_43813;
	bool cppVar_43814;
	BIT_VEC cppVar_43815;
	BIT_VEC cppVar_43816;
	bool cppVar_43817;
	BIT_VEC cppVar_43818;
	BIT_VEC cppVar_43819;
	bool cppVar_43820;
	BIT_VEC cppVar_43821;
	BIT_VEC cppVar_43822;
	bool cppVar_43823;
	BIT_VEC cppVar_43824;
	BIT_VEC cppVar_43825;
	bool cppVar_43826;
	BIT_VEC cppVar_43827;
	BIT_VEC cppVar_43828;
	bool cppVar_43829;
	BIT_VEC cppVar_43830;
	BIT_VEC cppVar_43831;
	bool cppVar_43832;
	BIT_VEC cppVar_43833;
	BIT_VEC cppVar_43834;
	bool cppVar_43835;
	BIT_VEC cppVar_43836;
	BIT_VEC cppVar_43837;
	bool cppVar_43838;
	BIT_VEC cppVar_43839;
	BIT_VEC cppVar_43840;
	bool cppVar_43841;
	BIT_VEC cppVar_43842;
	BIT_VEC cppVar_43843;
	bool cppVar_43844;
	BIT_VEC cppVar_43845;
	BIT_VEC cppVar_43846;
	bool cppVar_43847;
	BIT_VEC cppVar_43848;
	BIT_VEC cppVar_43849;
	bool cppVar_43850;
	BIT_VEC cppVar_43851;
	BIT_VEC cppVar_43852;
	bool cppVar_43853;
	BIT_VEC cppVar_43854;
	BIT_VEC cppVar_43855;
	bool cppVar_43856;
	BIT_VEC cppVar_43857;
	BIT_VEC cppVar_43858;
	bool cppVar_43859;
	BIT_VEC cppVar_43860;
	BIT_VEC cppVar_43861;
	bool cppVar_43862;
	BIT_VEC cppVar_43863;
	BIT_VEC cppVar_43864;
	bool cppVar_43865;
	BIT_VEC cppVar_43866;
	BIT_VEC cppVar_43867;
	bool cppVar_43868;
	BIT_VEC cppVar_43869;
	BIT_VEC cppVar_43870;
	bool cppVar_43871;
	BIT_VEC cppVar_43872;
	BIT_VEC cppVar_43873;
	bool cppVar_43874;
	BIT_VEC cppVar_43875;
	BIT_VEC cppVar_43876;
	bool cppVar_43877;
	BIT_VEC cppVar_43878;
	BIT_VEC cppVar_43879;
	bool cppVar_43880;
	BIT_VEC cppVar_43881;
	BIT_VEC cppVar_43882;
	bool cppVar_43883;
	BIT_VEC cppVar_43884;
	BIT_VEC cppVar_43885;
	bool cppVar_43886;
	BIT_VEC cppVar_43887;
	BIT_VEC cppVar_43888;
	bool cppVar_43889;
	BIT_VEC cppVar_43890;
	BIT_VEC cppVar_43891;
	bool cppVar_43892;
	BIT_VEC cppVar_43893;
	BIT_VEC cppVar_43894;
	bool cppVar_43895;
	BIT_VEC cppVar_43896;
	BIT_VEC cppVar_43897;
	bool cppVar_43898;
	BIT_VEC cppVar_43899;
	BIT_VEC cppVar_43900;
	bool cppVar_43901;
	BIT_VEC cppVar_43902;
	BIT_VEC cppVar_43903;
	bool cppVar_43904;
	BIT_VEC cppVar_43905;
	BIT_VEC cppVar_43906;
	bool cppVar_43907;
	BIT_VEC cppVar_43908;
	BIT_VEC cppVar_43909;
	bool cppVar_43910;
	BIT_VEC cppVar_43911;
	BIT_VEC cppVar_43912;
	bool cppVar_43913;
	BIT_VEC cppVar_43914;
	BIT_VEC cppVar_43915;
	bool cppVar_43916;
	BIT_VEC cppVar_43917;
	BIT_VEC cppVar_43918;
	bool cppVar_43919;
	BIT_VEC cppVar_43920;
	BIT_VEC cppVar_43921;
	bool cppVar_43922;
	BIT_VEC cppVar_43923;
	BIT_VEC cppVar_43924;
	bool cppVar_43925;
	BIT_VEC cppVar_43926;
	BIT_VEC cppVar_43927;
	bool cppVar_43928;
	BIT_VEC cppVar_43929;
	BIT_VEC cppVar_43930;
	bool cppVar_43931;
	BIT_VEC cppVar_43932;
	BIT_VEC cppVar_43933;
	bool cppVar_43934;
	BIT_VEC cppVar_43935;
	BIT_VEC cppVar_43936;
	bool cppVar_43937;
	BIT_VEC cppVar_43938;
	BIT_VEC cppVar_43939;
	bool cppVar_43940;
	BIT_VEC cppVar_43941;
	BIT_VEC cppVar_43942;
	bool cppVar_43943;
	BIT_VEC cppVar_43944;
	BIT_VEC cppVar_43945;
	bool cppVar_43946;
	BIT_VEC cppVar_43947;
	BIT_VEC cppVar_43948;
	bool cppVar_43949;
	BIT_VEC cppVar_43950;
	BIT_VEC cppVar_43951;
	bool cppVar_43952;
	BIT_VEC cppVar_43953;
	BIT_VEC cppVar_43954;
	bool cppVar_43955;
	BIT_VEC cppVar_43956;
	BIT_VEC cppVar_43957;
	bool cppVar_43958;
	BIT_VEC cppVar_43959;
	BIT_VEC cppVar_43960;
	bool cppVar_43961;
	BIT_VEC cppVar_43962;
	BIT_VEC cppVar_43963;
	bool cppVar_43964;
	BIT_VEC cppVar_43965;
	BIT_VEC cppVar_43966;
	bool cppVar_43967;
	BIT_VEC cppVar_43968;
	BIT_VEC cppVar_43969;
	bool cppVar_43970;
	BIT_VEC cppVar_43971;
	BIT_VEC cppVar_43972;
	bool cppVar_43973;
	BIT_VEC cppVar_43974;
	BIT_VEC cppVar_43975;
	bool cppVar_43976;
	BIT_VEC cppVar_43977;
	BIT_VEC cppVar_43978;
	bool cppVar_43979;
	BIT_VEC cppVar_43980;
	BIT_VEC cppVar_43981;
	bool cppVar_43982;
	BIT_VEC cppVar_43983;
	BIT_VEC cppVar_43984;
	bool cppVar_43985;
	BIT_VEC cppVar_43986;
	BIT_VEC cppVar_43987;
	bool cppVar_43988;
	BIT_VEC cppVar_43989;
	BIT_VEC cppVar_43990;
	bool cppVar_43991;
	BIT_VEC cppVar_43992;
	BIT_VEC cppVar_43993;
	bool cppVar_43994;
	BIT_VEC cppVar_43995;
	BIT_VEC cppVar_43996;
	bool cppVar_43997;
	BIT_VEC cppVar_43998;
	BIT_VEC cppVar_43999;
	bool cppVar_44000;
	BIT_VEC cppVar_44001;
	BIT_VEC cppVar_44002;
	bool cppVar_44003;
	BIT_VEC cppVar_44004;
	BIT_VEC cppVar_44005;
	bool cppVar_44006;
	BIT_VEC cppVar_44007;
	BIT_VEC cppVar_44008;
	bool cppVar_44009;
	BIT_VEC cppVar_44010;
	BIT_VEC cppVar_44011;
	bool cppVar_44012;
	BIT_VEC cppVar_44013;
	BIT_VEC cppVar_44014;
	bool cppVar_44015;
	BIT_VEC cppVar_44016;
	BIT_VEC cppVar_44017;
	bool cppVar_44018;
	BIT_VEC cppVar_44019;
	BIT_VEC cppVar_44020;
	bool cppVar_44021;
	BIT_VEC cppVar_44022;
	BIT_VEC cppVar_44023;
	bool cppVar_44024;
	BIT_VEC cppVar_44025;
	BIT_VEC cppVar_44026;
	bool cppVar_44027;
	BIT_VEC cppVar_44028;
	BIT_VEC cppVar_44029;
	bool cppVar_44030;
	BIT_VEC cppVar_44031;
	BIT_VEC cppVar_44032;
	bool cppVar_44033;
	BIT_VEC cppVar_44034;
	BIT_VEC cppVar_44035;
	bool cppVar_44036;
	BIT_VEC cppVar_44037;
	BIT_VEC cppVar_44038;
	bool cppVar_44039;
	BIT_VEC cppVar_44040;
	BIT_VEC cppVar_44041;
	bool cppVar_44042;
	BIT_VEC cppVar_44043;
	BIT_VEC cppVar_44044;
	bool cppVar_44045;
	BIT_VEC cppVar_44046;
	BIT_VEC cppVar_44047;
	bool cppVar_44048;
	BIT_VEC cppVar_44049;
	BIT_VEC cppVar_44050;
	bool cppVar_44051;
	BIT_VEC cppVar_44052;
	BIT_VEC cppVar_44053;
	bool cppVar_44054;
	BIT_VEC cppVar_44055;
	BIT_VEC cppVar_44056;
	bool cppVar_44057;
	BIT_VEC cppVar_44058;
	BIT_VEC cppVar_44059;
	bool cppVar_44060;
	BIT_VEC cppVar_44061;
	BIT_VEC cppVar_44062;
	bool cppVar_44063;
	BIT_VEC cppVar_44064;
	BIT_VEC cppVar_44065;
	bool cppVar_44066;
	BIT_VEC cppVar_44067;
	BIT_VEC cppVar_44068;
	bool cppVar_44069;
	BIT_VEC cppVar_44070;
	BIT_VEC cppVar_44071;
	bool cppVar_44072;
	BIT_VEC cppVar_44073;
	BIT_VEC cppVar_44074;
	bool cppVar_44075;
	BIT_VEC cppVar_44076;
	BIT_VEC cppVar_44077;
	bool cppVar_44078;
	BIT_VEC cppVar_44079;
	BIT_VEC cppVar_44080;
	bool cppVar_44081;
	BIT_VEC cppVar_44082;
	BIT_VEC cppVar_44083;
	bool cppVar_44084;
	BIT_VEC cppVar_44085;
	BIT_VEC cppVar_44086;
	bool cppVar_44087;
	BIT_VEC cppVar_44088;
	BIT_VEC cppVar_44089;
	bool cppVar_44090;
	BIT_VEC cppVar_44091;
	BIT_VEC cppVar_44092;
	bool cppVar_44093;
	BIT_VEC cppVar_44094;
	BIT_VEC cppVar_44095;
	bool cppVar_44096;
	BIT_VEC cppVar_44097;
	BIT_VEC cppVar_44098;
	bool cppVar_44099;
	BIT_VEC cppVar_44100;
	BIT_VEC cppVar_44101;
	bool cppVar_44102;
	BIT_VEC cppVar_44103;
	BIT_VEC cppVar_44104;
	bool cppVar_44105;
	BIT_VEC cppVar_44106;
	BIT_VEC cppVar_44107;
	bool cppVar_44108;
	BIT_VEC cppVar_44109;
	BIT_VEC cppVar_44110;
	bool cppVar_44111;
	BIT_VEC cppVar_44112;
	BIT_VEC cppVar_44113;
	bool cppVar_44114;
	BIT_VEC cppVar_44115;
	BIT_VEC cppVar_44116;
	bool cppVar_44117;
	BIT_VEC cppVar_44118;
	BIT_VEC cppVar_44119;
	bool cppVar_44120;
	BIT_VEC cppVar_44121;
	BIT_VEC cppVar_44122;
	bool cppVar_44123;
	BIT_VEC cppVar_44124;
	BIT_VEC cppVar_44125;
	bool cppVar_44126;
	BIT_VEC cppVar_44127;
	BIT_VEC cppVar_44128;
	bool cppVar_44129;
	BIT_VEC cppVar_44130;
	BIT_VEC cppVar_44131;
	bool cppVar_44132;
	bool cppVar_44133;
	bool cppVar_44134;
	bool cppVar_44135;
	bool cppVar_44136;
	bool cppVar_44137;
	bool cppVar_44138;
	bool cppVar_44139;
	bool cppVar_44140;
	bool cppVar_44141;
	bool cppVar_44142;
	bool cppVar_44143;
	bool cppVar_44144;
	bool cppVar_44145;
	bool cppVar_44146;
	bool cppVar_44147;
	bool cppVar_44148;
	bool cppVar_44149;
	bool cppVar_44150;
	bool cppVar_44151;
	bool cppVar_44152;
	bool cppVar_44153;
	bool cppVar_44154;
	bool cppVar_44155;
	bool cppVar_44156;
	bool cppVar_44157;
	bool cppVar_44158;
	bool cppVar_44159;
	bool cppVar_44160;
	bool cppVar_44161;
	bool cppVar_44162;
	bool cppVar_44163;
	bool cppVar_44164;
	bool cppVar_44165;
	bool cppVar_44166;
	bool cppVar_44167;
	bool cppVar_44168;
	bool cppVar_44169;
	bool cppVar_44170;
	bool cppVar_44171;
	bool cppVar_44172;
	bool cppVar_44173;
	bool cppVar_44174;
	bool cppVar_44175;
	bool cppVar_44176;
	bool cppVar_44177;
	bool cppVar_44178;
	bool cppVar_44179;
	bool cppVar_44180;
	bool cppVar_44181;
	bool cppVar_44182;
	bool cppVar_44183;
	bool cppVar_44184;
	bool cppVar_44185;
	bool cppVar_44186;
	bool cppVar_44187;
	bool cppVar_44188;
	bool cppVar_44189;
	bool cppVar_44190;
	bool cppVar_44191;
	bool cppVar_44192;
	bool cppVar_44193;
	bool cppVar_44194;
	bool cppVar_44195;
	bool cppVar_44196;
	bool cppVar_44197;
	bool cppVar_44198;
	bool cppVar_44199;
	bool cppVar_44200;
	bool cppVar_44201;
	bool cppVar_44202;
	bool cppVar_44203;
	bool cppVar_44204;
	bool cppVar_44205;
	bool cppVar_44206;
	bool cppVar_44207;
	bool cppVar_44208;
	bool cppVar_44209;
	bool cppVar_44210;
	bool cppVar_44211;
	bool cppVar_44212;
	bool cppVar_44213;
	bool cppVar_44214;
	bool cppVar_44215;
	bool cppVar_44216;
	bool cppVar_44217;
	bool cppVar_44218;
	bool cppVar_44219;
	bool cppVar_44220;
	bool cppVar_44221;
	bool cppVar_44222;
	bool cppVar_44223;
	bool cppVar_44224;
	bool cppVar_44225;
	bool cppVar_44226;
	bool cppVar_44227;
	bool cppVar_44228;
	bool cppVar_44229;
	bool cppVar_44230;
	bool cppVar_44231;
	bool cppVar_44232;
	bool cppVar_44233;
	bool cppVar_44234;
	bool cppVar_44235;
	bool cppVar_44236;
	bool cppVar_44237;
	bool cppVar_44238;
	bool cppVar_44239;
	bool cppVar_44240;
	bool cppVar_44241;
	bool cppVar_44242;
	bool cppVar_44243;
	bool cppVar_44244;
	bool cppVar_44245;
	bool cppVar_44246;
	bool cppVar_44247;
	bool cppVar_44248;
	bool cppVar_44249;
	bool cppVar_44250;
	bool cppVar_44251;
	bool cppVar_44252;
	bool cppVar_44253;
	bool cppVar_44254;
	bool cppVar_44255;
	bool cppVar_44256;
	bool cppVar_44257;
	bool cppVar_44258;
	bool cppVar_44259;
	bool cppVar_44260;
	bool cppVar_44261;
	bool cppVar_44262;
	bool cppVar_44263;
	bool cppVar_44264;
	bool cppVar_44265;
	bool cppVar_44266;
	bool cppVar_44267;
	bool cppVar_44268;
	bool cppVar_44269;
	BIT_VEC cppVar_44270;
	BIT_VEC cppVar_44271;
	BIT_VEC cppVar_43718;
	BIT_VEC cppVar_43701;
	BIT_VEC cppVar_43686;
	BIT_VEC cppVar_43436;
	BIT_VEC cppVar_43017;
	BIT_VEC cppVar_43000;
	BIT_VEC cppVar_42987;
	BIT_VEC cppVar_42572;
	BIT_VEC cppVar_42555;
	BIT_VEC cppVar_42538;
	BIT_VEC cppVar_42512;
	BIT_VEC cppVar_42495;
	BIT_VEC cppVar_42479;
	BIT_VEC cppVar_42462;
	BIT_VEC cppVar_42446;
	BIT_VEC cppVar_42439;
	BIT_VEC cppVar_42428;
	BIT_VEC cppVar_42411;
	BIT_VEC cppVar_42394;
	BIT_VEC cppVar_42376;
	BIT_VEC cppVar_42245;
	BIT_VEC cppVar_42220;
	BIT_VEC cppVar_42195;
	BIT_VEC cppVar_42171;
	BIT_VEC cppVar_42147;
	BIT_VEC cppVar_42123;
	BIT_VEC cppVar_42099;
	BIT_VEC cppVar_42075;
	BIT_VEC cppVar_42051;
	BIT_VEC cppVar_42027;
	BIT_VEC cppVar_42003;
	BIT_VEC cppVar_41986;
	BIT_VEC cppVar_41854;
	BIT_VEC cppVar_41832;
	BIT_VEC cppVar_41810;
	BIT_VEC cppVar_41788;
	BIT_VEC cppVar_41766;
	BIT_VEC cppVar_41744;
	BIT_VEC cppVar_41722;
	BIT_VEC cppVar_41700;
	BIT_VEC cppVar_41678;
	BIT_VEC cppVar_41661;
	BIT_VEC cppVar_41662;
	BIT_VEC cppVar_41663;
	bool cppVar_41664;
	BIT_VEC cppVar_41665;
	BIT_VEC cppVar_41666;
	bool cppVar_41667;
	bool cppVar_41668;
	BIT_VEC cppVar_41669;
	BIT_VEC cppVar_41670;
	BIT_VEC cppVar_41671;
	BIT_VEC cppVar_41672;
	BIT_VEC cppVar_41673;
	BIT_VEC cppVar_41674;
	BIT_VEC cppVar_41675;
	BIT_VEC cppVar_41676;
	BIT_VEC cppVar_41677;
	BIT_VEC cppVar_41679;
	BIT_VEC cppVar_41680;
	bool cppVar_41681;
	BIT_VEC cppVar_41683;
	BIT_VEC cppVar_41684;
	BIT_VEC cppVar_41685;
	BIT_VEC cppVar_41686;
	BIT_VEC cppVar_41687;
	BIT_VEC cppVar_41688;
	BIT_VEC cppVar_41689;
	bool cppVar_41690;
	BIT_VEC cppVar_41691;
	BIT_VEC cppVar_41692;
	BIT_VEC cppVar_41693;
	BIT_VEC cppVar_41694;
	BIT_VEC cppVar_41695;
	BIT_VEC cppVar_41696;
	BIT_VEC cppVar_41697;
	BIT_VEC cppVar_41698;
	BIT_VEC cppVar_41699;
	BIT_VEC cppVar_41682;
	BIT_VEC cppVar_41701;
	BIT_VEC cppVar_41702;
	bool cppVar_41703;
	BIT_VEC cppVar_41705;
	BIT_VEC cppVar_41706;
	BIT_VEC cppVar_41707;
	BIT_VEC cppVar_41708;
	BIT_VEC cppVar_41709;
	BIT_VEC cppVar_41710;
	BIT_VEC cppVar_41711;
	bool cppVar_41712;
	BIT_VEC cppVar_41713;
	BIT_VEC cppVar_41714;
	BIT_VEC cppVar_41715;
	BIT_VEC cppVar_41716;
	BIT_VEC cppVar_41717;
	BIT_VEC cppVar_41718;
	BIT_VEC cppVar_41719;
	BIT_VEC cppVar_41720;
	BIT_VEC cppVar_41721;
	BIT_VEC cppVar_41704;
	BIT_VEC cppVar_41723;
	BIT_VEC cppVar_41724;
	bool cppVar_41725;
	BIT_VEC cppVar_41727;
	BIT_VEC cppVar_41728;
	BIT_VEC cppVar_41729;
	BIT_VEC cppVar_41730;
	BIT_VEC cppVar_41731;
	BIT_VEC cppVar_41732;
	BIT_VEC cppVar_41733;
	bool cppVar_41734;
	BIT_VEC cppVar_41735;
	BIT_VEC cppVar_41736;
	BIT_VEC cppVar_41737;
	BIT_VEC cppVar_41738;
	BIT_VEC cppVar_41739;
	BIT_VEC cppVar_41740;
	BIT_VEC cppVar_41741;
	BIT_VEC cppVar_41742;
	BIT_VEC cppVar_41743;
	BIT_VEC cppVar_41726;
	BIT_VEC cppVar_41745;
	BIT_VEC cppVar_41746;
	bool cppVar_41747;
	BIT_VEC cppVar_41749;
	BIT_VEC cppVar_41750;
	BIT_VEC cppVar_41751;
	BIT_VEC cppVar_41752;
	BIT_VEC cppVar_41753;
	BIT_VEC cppVar_41754;
	BIT_VEC cppVar_41755;
	bool cppVar_41756;
	BIT_VEC cppVar_41757;
	BIT_VEC cppVar_41758;
	BIT_VEC cppVar_41759;
	BIT_VEC cppVar_41760;
	BIT_VEC cppVar_41761;
	BIT_VEC cppVar_41762;
	BIT_VEC cppVar_41763;
	BIT_VEC cppVar_41764;
	BIT_VEC cppVar_41765;
	BIT_VEC cppVar_41748;
	BIT_VEC cppVar_41767;
	BIT_VEC cppVar_41768;
	bool cppVar_41769;
	BIT_VEC cppVar_41771;
	BIT_VEC cppVar_41772;
	BIT_VEC cppVar_41773;
	BIT_VEC cppVar_41774;
	BIT_VEC cppVar_41775;
	BIT_VEC cppVar_41776;
	BIT_VEC cppVar_41777;
	bool cppVar_41778;
	BIT_VEC cppVar_41779;
	BIT_VEC cppVar_41780;
	BIT_VEC cppVar_41781;
	BIT_VEC cppVar_41782;
	BIT_VEC cppVar_41783;
	BIT_VEC cppVar_41784;
	BIT_VEC cppVar_41785;
	BIT_VEC cppVar_41786;
	BIT_VEC cppVar_41787;
	BIT_VEC cppVar_41770;
	BIT_VEC cppVar_41789;
	BIT_VEC cppVar_41790;
	bool cppVar_41791;
	BIT_VEC cppVar_41793;
	BIT_VEC cppVar_41794;
	BIT_VEC cppVar_41795;
	BIT_VEC cppVar_41796;
	BIT_VEC cppVar_41797;
	BIT_VEC cppVar_41798;
	BIT_VEC cppVar_41799;
	bool cppVar_41800;
	BIT_VEC cppVar_41801;
	BIT_VEC cppVar_41802;
	BIT_VEC cppVar_41803;
	BIT_VEC cppVar_41804;
	BIT_VEC cppVar_41805;
	BIT_VEC cppVar_41806;
	BIT_VEC cppVar_41807;
	BIT_VEC cppVar_41808;
	BIT_VEC cppVar_41809;
	BIT_VEC cppVar_41792;
	BIT_VEC cppVar_41811;
	BIT_VEC cppVar_41812;
	bool cppVar_41813;
	BIT_VEC cppVar_41815;
	BIT_VEC cppVar_41816;
	BIT_VEC cppVar_41817;
	BIT_VEC cppVar_41818;
	BIT_VEC cppVar_41819;
	BIT_VEC cppVar_41820;
	BIT_VEC cppVar_41821;
	bool cppVar_41822;
	BIT_VEC cppVar_41823;
	BIT_VEC cppVar_41824;
	BIT_VEC cppVar_41825;
	BIT_VEC cppVar_41826;
	BIT_VEC cppVar_41827;
	BIT_VEC cppVar_41828;
	BIT_VEC cppVar_41829;
	BIT_VEC cppVar_41830;
	BIT_VEC cppVar_41831;
	BIT_VEC cppVar_41814;
	BIT_VEC cppVar_41833;
	BIT_VEC cppVar_41834;
	bool cppVar_41835;
	BIT_VEC cppVar_41837;
	BIT_VEC cppVar_41838;
	BIT_VEC cppVar_41839;
	BIT_VEC cppVar_41840;
	BIT_VEC cppVar_41841;
	BIT_VEC cppVar_41842;
	BIT_VEC cppVar_41843;
	bool cppVar_41844;
	BIT_VEC cppVar_41845;
	BIT_VEC cppVar_41846;
	BIT_VEC cppVar_41847;
	BIT_VEC cppVar_41848;
	BIT_VEC cppVar_41849;
	BIT_VEC cppVar_41850;
	BIT_VEC cppVar_41851;
	BIT_VEC cppVar_41852;
	BIT_VEC cppVar_41853;
	BIT_VEC cppVar_41836;
	BIT_VEC cppVar_41855;
	BIT_VEC cppVar_41856;
	bool cppVar_41857;
	BIT_VEC cppVar_41860;
	BIT_VEC cppVar_41861;
	BIT_VEC cppVar_41862;
	BIT_VEC cppVar_41863;
	BIT_VEC cppVar_41864;
	bool cppVar_41865;
	BIT_VEC cppVar_41866;
	BIT_VEC cppVar_41867;
	BIT_VEC cppVar_41868;
	BIT_VEC cppVar_41870;
	BIT_VEC cppVar_41871;
	BIT_VEC cppVar_41872;
	bool cppVar_41873;
	BIT_VEC cppVar_41875;
	BIT_VEC cppVar_41876;
	BIT_VEC cppVar_41877;
	bool cppVar_41878;
	BIT_VEC cppVar_41880;
	BIT_VEC cppVar_41881;
	BIT_VEC cppVar_41882;
	bool cppVar_41883;
	BIT_VEC cppVar_41885;
	BIT_VEC cppVar_41886;
	BIT_VEC cppVar_41887;
	bool cppVar_41888;
	BIT_VEC cppVar_41890;
	BIT_VEC cppVar_41891;
	BIT_VEC cppVar_41892;
	bool cppVar_41893;
	BIT_VEC cppVar_41895;
	BIT_VEC cppVar_41896;
	BIT_VEC cppVar_41897;
	bool cppVar_41898;
	BIT_VEC cppVar_41900;
	BIT_VEC cppVar_41901;
	BIT_VEC cppVar_41902;
	bool cppVar_41903;
	BIT_VEC cppVar_41905;
	BIT_VEC cppVar_41906;
	BIT_VEC cppVar_41907;
	bool cppVar_41908;
	BIT_VEC cppVar_41910;
	BIT_VEC cppVar_41911;
	BIT_VEC cppVar_41912;
	bool cppVar_41913;
	BIT_VEC cppVar_41915;
	BIT_VEC cppVar_41916;
	BIT_VEC cppVar_41917;
	bool cppVar_41918;
	BIT_VEC cppVar_41920;
	BIT_VEC cppVar_41921;
	BIT_VEC cppVar_41922;
	bool cppVar_41923;
	BIT_VEC cppVar_41925;
	BIT_VEC cppVar_41926;
	BIT_VEC cppVar_41927;
	bool cppVar_41928;
	BIT_VEC cppVar_41930;
	BIT_VEC cppVar_41931;
	BIT_VEC cppVar_41932;
	bool cppVar_41933;
	BIT_VEC cppVar_41935;
	BIT_VEC cppVar_41936;
	BIT_VEC cppVar_41937;
	bool cppVar_41938;
	BIT_VEC cppVar_41940;
	BIT_VEC cppVar_41941;
	BIT_VEC cppVar_41942;
	bool cppVar_41943;
	BIT_VEC cppVar_41945;
	BIT_VEC cppVar_41946;
	BIT_VEC cppVar_41947;
	bool cppVar_41948;
	BIT_VEC cppVar_41950;
	BIT_VEC cppVar_41951;
	BIT_VEC cppVar_41952;
	bool cppVar_41953;
	BIT_VEC cppVar_41955;
	BIT_VEC cppVar_41956;
	BIT_VEC cppVar_41957;
	bool cppVar_41958;
	BIT_VEC cppVar_41960;
	BIT_VEC cppVar_41961;
	BIT_VEC cppVar_41962;
	bool cppVar_41963;
	BIT_VEC cppVar_41965;
	BIT_VEC cppVar_41966;
	BIT_VEC cppVar_41967;
	bool cppVar_41968;
	BIT_VEC cppVar_41970;
	BIT_VEC cppVar_41971;
	BIT_VEC cppVar_41972;
	bool cppVar_41973;
	BIT_VEC cppVar_41974;
	BIT_VEC cppVar_41969;
	BIT_VEC cppVar_41964;
	BIT_VEC cppVar_41959;
	BIT_VEC cppVar_41954;
	BIT_VEC cppVar_41949;
	BIT_VEC cppVar_41944;
	BIT_VEC cppVar_41939;
	BIT_VEC cppVar_41934;
	BIT_VEC cppVar_41929;
	BIT_VEC cppVar_41924;
	BIT_VEC cppVar_41919;
	BIT_VEC cppVar_41914;
	BIT_VEC cppVar_41909;
	BIT_VEC cppVar_41904;
	BIT_VEC cppVar_41899;
	BIT_VEC cppVar_41894;
	BIT_VEC cppVar_41889;
	BIT_VEC cppVar_41884;
	BIT_VEC cppVar_41879;
	BIT_VEC cppVar_41874;
	BIT_VEC cppVar_41869;
	BIT_VEC cppVar_41859;
	BIT_VEC cppVar_41975;
	bool cppVar_41976;
	BIT_VEC cppVar_41977;
	BIT_VEC cppVar_41978;
	BIT_VEC cppVar_41979;
	BIT_VEC cppVar_41980;
	BIT_VEC cppVar_41981;
	BIT_VEC cppVar_41982;
	BIT_VEC cppVar_41983;
	BIT_VEC cppVar_41984;
	BIT_VEC cppVar_41985;
	BIT_VEC cppVar_41858;
	BIT_VEC cppVar_41987;
	BIT_VEC cppVar_41988;
	bool cppVar_41989;
	BIT_VEC cppVar_41990;
	BIT_VEC cppVar_41991;
	bool cppVar_41992;
	bool cppVar_41993;
	BIT_VEC cppVar_41994;
	BIT_VEC cppVar_41995;
	BIT_VEC cppVar_41996;
	BIT_VEC cppVar_41997;
	BIT_VEC cppVar_41998;
	BIT_VEC cppVar_41999;
	BIT_VEC cppVar_42000;
	BIT_VEC cppVar_42001;
	BIT_VEC cppVar_42002;
	BIT_VEC cppVar_42004;
	BIT_VEC cppVar_42005;
	bool cppVar_42006;
	BIT_VEC cppVar_42008;
	BIT_VEC cppVar_42009;
	BIT_VEC cppVar_42010;
	BIT_VEC cppVar_42011;
	BIT_VEC cppVar_42012;
	BIT_VEC cppVar_42013;
	BIT_VEC cppVar_42014;
	BIT_VEC cppVar_42015;
	BIT_VEC cppVar_42016;
	bool cppVar_42017;
	BIT_VEC cppVar_42018;
	BIT_VEC cppVar_42019;
	BIT_VEC cppVar_42020;
	BIT_VEC cppVar_42021;
	BIT_VEC cppVar_42022;
	BIT_VEC cppVar_42023;
	BIT_VEC cppVar_42024;
	BIT_VEC cppVar_42025;
	BIT_VEC cppVar_42026;
	BIT_VEC cppVar_42007;
	BIT_VEC cppVar_42028;
	BIT_VEC cppVar_42029;
	bool cppVar_42030;
	BIT_VEC cppVar_42032;
	BIT_VEC cppVar_42033;
	BIT_VEC cppVar_42034;
	BIT_VEC cppVar_42035;
	BIT_VEC cppVar_42036;
	BIT_VEC cppVar_42037;
	BIT_VEC cppVar_42038;
	BIT_VEC cppVar_42039;
	BIT_VEC cppVar_42040;
	bool cppVar_42041;
	BIT_VEC cppVar_42042;
	BIT_VEC cppVar_42043;
	BIT_VEC cppVar_42044;
	BIT_VEC cppVar_42045;
	BIT_VEC cppVar_42046;
	BIT_VEC cppVar_42047;
	BIT_VEC cppVar_42048;
	BIT_VEC cppVar_42049;
	BIT_VEC cppVar_42050;
	BIT_VEC cppVar_42031;
	BIT_VEC cppVar_42052;
	BIT_VEC cppVar_42053;
	cppVar_41662 = ROM.rd(PC);
	cppVar_41664 = (cppVar_41662 == 241);
	cppVar_41665 = ROM.rd(PC);
	cppVar_41667 = (cppVar_41665 == 225);
	cppVar_41668 = cppVar_41664 || cppVar_41667;
	if (cppVar_41668) {
	cppVar_41670 = PC + 2;
	cppVar_41670 = (cppVar_41670 & cppMask_un_16_);
	cppVar_41671 = (cppVar_41670 >> 11) & cppMask_un_5_;
	cppVar_41673 = (cppVar_41671 << 3) | 7;
	cppVar_41673 = (cppVar_41673 & cppMask_un_8_);
	cppVar_41675 = PC + 1;
	cppVar_41675 = (cppVar_41675 & cppMask_un_16_);
	cppVar_41676 = ROM.rd(cppVar_41675);
	cppVar_41677 = (cppVar_41673 << 8) | cppVar_41676;
	cppVar_41677 = (cppVar_41677 & cppMask_un_16_);
	cppVar_41661 = cppVar_41677;
	} else {
	cppVar_41679 = ROM.rd(PC);
	cppVar_41681 = (cppVar_41679 == 223);
	if (cppVar_41681) {
	cppVar_41684 = (PSW >> 3) & cppMask_un_2_;
	cppVar_41686 = (cppVar_41684 << 3) | 7;
	cppVar_41686 = (cppVar_41686 & cppMask_un_5_);
	cppVar_41687 = (0 << 5) | cppVar_41686;
	cppVar_41687 = (cppVar_41687 & cppMask_un_8_);
	cppVar_41688 = IRAM.rd(cppVar_41687);
	cppVar_41690 = (cppVar_41688 != 1);
	if (cppVar_41690) {
	cppVar_41692 = PC + 2;
	cppVar_41692 = (cppVar_41692 & cppMask_un_16_);
	cppVar_41694 = PC + 1;
	cppVar_41694 = (cppVar_41694 & cppMask_un_16_);
	cppVar_41695 = ROM.rd(cppVar_41694);
	cppVar_41696 = ((cppVar_41695 & cppMask_bit_8_) ? (cppVar_41695 | cppMask_sign_8_) : cppVar_41695);
	cppVar_41697 = cppVar_41692 + cppVar_41696;
	cppVar_41697 = (cppVar_41697 & cppMask_un_16_);
	cppVar_41682 = cppVar_41697;
	} else {
	cppVar_41699 = PC + 2;
	cppVar_41699 = (cppVar_41699 & cppMask_un_16_);
	cppVar_41682 = cppVar_41699;
	}
	cppVar_41678 = cppVar_41682;
	} else {
	cppVar_41701 = ROM.rd(PC);
	cppVar_41703 = (cppVar_41701 == 222);
	if (cppVar_41703) {
	cppVar_41706 = (PSW >> 3) & cppMask_un_2_;
	cppVar_41708 = (cppVar_41706 << 3) | 6;
	cppVar_41708 = (cppVar_41708 & cppMask_un_5_);
	cppVar_41709 = (0 << 5) | cppVar_41708;
	cppVar_41709 = (cppVar_41709 & cppMask_un_8_);
	cppVar_41710 = IRAM.rd(cppVar_41709);
	cppVar_41712 = (cppVar_41710 != 1);
	if (cppVar_41712) {
	cppVar_41714 = PC + 2;
	cppVar_41714 = (cppVar_41714 & cppMask_un_16_);
	cppVar_41716 = PC + 1;
	cppVar_41716 = (cppVar_41716 & cppMask_un_16_);
	cppVar_41717 = ROM.rd(cppVar_41716);
	cppVar_41718 = ((cppVar_41717 & cppMask_bit_8_) ? (cppVar_41717 | cppMask_sign_8_) : cppVar_41717);
	cppVar_41719 = cppVar_41714 + cppVar_41718;
	cppVar_41719 = (cppVar_41719 & cppMask_un_16_);
	cppVar_41704 = cppVar_41719;
	} else {
	cppVar_41721 = PC + 2;
	cppVar_41721 = (cppVar_41721 & cppMask_un_16_);
	cppVar_41704 = cppVar_41721;
	}
	cppVar_41700 = cppVar_41704;
	} else {
	cppVar_41723 = ROM.rd(PC);
	cppVar_41725 = (cppVar_41723 == 221);
	if (cppVar_41725) {
	cppVar_41728 = (PSW >> 3) & cppMask_un_2_;
	cppVar_41730 = (cppVar_41728 << 3) | 5;
	cppVar_41730 = (cppVar_41730 & cppMask_un_5_);
	cppVar_41731 = (0 << 5) | cppVar_41730;
	cppVar_41731 = (cppVar_41731 & cppMask_un_8_);
	cppVar_41732 = IRAM.rd(cppVar_41731);
	cppVar_41734 = (cppVar_41732 != 1);
	if (cppVar_41734) {
	cppVar_41736 = PC + 2;
	cppVar_41736 = (cppVar_41736 & cppMask_un_16_);
	cppVar_41738 = PC + 1;
	cppVar_41738 = (cppVar_41738 & cppMask_un_16_);
	cppVar_41739 = ROM.rd(cppVar_41738);
	cppVar_41740 = ((cppVar_41739 & cppMask_bit_8_) ? (cppVar_41739 | cppMask_sign_8_) : cppVar_41739);
	cppVar_41741 = cppVar_41736 + cppVar_41740;
	cppVar_41741 = (cppVar_41741 & cppMask_un_16_);
	cppVar_41726 = cppVar_41741;
	} else {
	cppVar_41743 = PC + 2;
	cppVar_41743 = (cppVar_41743 & cppMask_un_16_);
	cppVar_41726 = cppVar_41743;
	}
	cppVar_41722 = cppVar_41726;
	} else {
	cppVar_41745 = ROM.rd(PC);
	cppVar_41747 = (cppVar_41745 == 220);
	if (cppVar_41747) {
	cppVar_41750 = (PSW >> 3) & cppMask_un_2_;
	cppVar_41752 = (cppVar_41750 << 3) | 4;
	cppVar_41752 = (cppVar_41752 & cppMask_un_5_);
	cppVar_41753 = (0 << 5) | cppVar_41752;
	cppVar_41753 = (cppVar_41753 & cppMask_un_8_);
	cppVar_41754 = IRAM.rd(cppVar_41753);
	cppVar_41756 = (cppVar_41754 != 1);
	if (cppVar_41756) {
	cppVar_41758 = PC + 2;
	cppVar_41758 = (cppVar_41758 & cppMask_un_16_);
	cppVar_41760 = PC + 1;
	cppVar_41760 = (cppVar_41760 & cppMask_un_16_);
	cppVar_41761 = ROM.rd(cppVar_41760);
	cppVar_41762 = ((cppVar_41761 & cppMask_bit_8_) ? (cppVar_41761 | cppMask_sign_8_) : cppVar_41761);
	cppVar_41763 = cppVar_41758 + cppVar_41762;
	cppVar_41763 = (cppVar_41763 & cppMask_un_16_);
	cppVar_41748 = cppVar_41763;
	} else {
	cppVar_41765 = PC + 2;
	cppVar_41765 = (cppVar_41765 & cppMask_un_16_);
	cppVar_41748 = cppVar_41765;
	}
	cppVar_41744 = cppVar_41748;
	} else {
	cppVar_41767 = ROM.rd(PC);
	cppVar_41769 = (cppVar_41767 == 219);
	if (cppVar_41769) {
	cppVar_41772 = (PSW >> 3) & cppMask_un_2_;
	cppVar_41774 = (cppVar_41772 << 3) | 3;
	cppVar_41774 = (cppVar_41774 & cppMask_un_5_);
	cppVar_41775 = (0 << 5) | cppVar_41774;
	cppVar_41775 = (cppVar_41775 & cppMask_un_8_);
	cppVar_41776 = IRAM.rd(cppVar_41775);
	cppVar_41778 = (cppVar_41776 != 1);
	if (cppVar_41778) {
	cppVar_41780 = PC + 2;
	cppVar_41780 = (cppVar_41780 & cppMask_un_16_);
	cppVar_41782 = PC + 1;
	cppVar_41782 = (cppVar_41782 & cppMask_un_16_);
	cppVar_41783 = ROM.rd(cppVar_41782);
	cppVar_41784 = ((cppVar_41783 & cppMask_bit_8_) ? (cppVar_41783 | cppMask_sign_8_) : cppVar_41783);
	cppVar_41785 = cppVar_41780 + cppVar_41784;
	cppVar_41785 = (cppVar_41785 & cppMask_un_16_);
	cppVar_41770 = cppVar_41785;
	} else {
	cppVar_41787 = PC + 2;
	cppVar_41787 = (cppVar_41787 & cppMask_un_16_);
	cppVar_41770 = cppVar_41787;
	}
	cppVar_41766 = cppVar_41770;
	} else {
	cppVar_41789 = ROM.rd(PC);
	cppVar_41791 = (cppVar_41789 == 218);
	if (cppVar_41791) {
	cppVar_41794 = (PSW >> 3) & cppMask_un_2_;
	cppVar_41796 = (cppVar_41794 << 3) | 2;
	cppVar_41796 = (cppVar_41796 & cppMask_un_5_);
	cppVar_41797 = (0 << 5) | cppVar_41796;
	cppVar_41797 = (cppVar_41797 & cppMask_un_8_);
	cppVar_41798 = IRAM.rd(cppVar_41797);
	cppVar_41800 = (cppVar_41798 != 1);
	if (cppVar_41800) {
	cppVar_41802 = PC + 2;
	cppVar_41802 = (cppVar_41802 & cppMask_un_16_);
	cppVar_41804 = PC + 1;
	cppVar_41804 = (cppVar_41804 & cppMask_un_16_);
	cppVar_41805 = ROM.rd(cppVar_41804);
	cppVar_41806 = ((cppVar_41805 & cppMask_bit_8_) ? (cppVar_41805 | cppMask_sign_8_) : cppVar_41805);
	cppVar_41807 = cppVar_41802 + cppVar_41806;
	cppVar_41807 = (cppVar_41807 & cppMask_un_16_);
	cppVar_41792 = cppVar_41807;
	} else {
	cppVar_41809 = PC + 2;
	cppVar_41809 = (cppVar_41809 & cppMask_un_16_);
	cppVar_41792 = cppVar_41809;
	}
	cppVar_41788 = cppVar_41792;
	} else {
	cppVar_41811 = ROM.rd(PC);
	cppVar_41813 = (cppVar_41811 == 217);
	if (cppVar_41813) {
	cppVar_41816 = (PSW >> 3) & cppMask_un_2_;
	cppVar_41818 = (cppVar_41816 << 3) | 1;
	cppVar_41818 = (cppVar_41818 & cppMask_un_5_);
	cppVar_41819 = (0 << 5) | cppVar_41818;
	cppVar_41819 = (cppVar_41819 & cppMask_un_8_);
	cppVar_41820 = IRAM.rd(cppVar_41819);
	cppVar_41822 = (cppVar_41820 != 1);
	if (cppVar_41822) {
	cppVar_41824 = PC + 2;
	cppVar_41824 = (cppVar_41824 & cppMask_un_16_);
	cppVar_41826 = PC + 1;
	cppVar_41826 = (cppVar_41826 & cppMask_un_16_);
	cppVar_41827 = ROM.rd(cppVar_41826);
	cppVar_41828 = ((cppVar_41827 & cppMask_bit_8_) ? (cppVar_41827 | cppMask_sign_8_) : cppVar_41827);
	cppVar_41829 = cppVar_41824 + cppVar_41828;
	cppVar_41829 = (cppVar_41829 & cppMask_un_16_);
	cppVar_41814 = cppVar_41829;
	} else {
	cppVar_41831 = PC + 2;
	cppVar_41831 = (cppVar_41831 & cppMask_un_16_);
	cppVar_41814 = cppVar_41831;
	}
	cppVar_41810 = cppVar_41814;
	} else {
	cppVar_41833 = ROM.rd(PC);
	cppVar_41835 = (cppVar_41833 == 216);
	if (cppVar_41835) {
	cppVar_41838 = (PSW >> 3) & cppMask_un_2_;
	cppVar_41840 = (cppVar_41838 << 3) | 0;
	cppVar_41840 = (cppVar_41840 & cppMask_un_5_);
	cppVar_41841 = (0 << 5) | cppVar_41840;
	cppVar_41841 = (cppVar_41841 & cppMask_un_8_);
	cppVar_41842 = IRAM.rd(cppVar_41841);
	cppVar_41844 = (cppVar_41842 != 1);
	if (cppVar_41844) {
	cppVar_41846 = PC + 2;
	cppVar_41846 = (cppVar_41846 & cppMask_un_16_);
	cppVar_41848 = PC + 1;
	cppVar_41848 = (cppVar_41848 & cppMask_un_16_);
	cppVar_41849 = ROM.rd(cppVar_41848);
	cppVar_41850 = ((cppVar_41849 & cppMask_bit_8_) ? (cppVar_41849 | cppMask_sign_8_) : cppVar_41849);
	cppVar_41851 = cppVar_41846 + cppVar_41850;
	cppVar_41851 = (cppVar_41851 & cppMask_un_16_);
	cppVar_41836 = cppVar_41851;
	} else {
	cppVar_41853 = PC + 2;
	cppVar_41853 = (cppVar_41853 & cppMask_un_16_);
	cppVar_41836 = cppVar_41853;
	}
	cppVar_41832 = cppVar_41836;
	} else {
	cppVar_41855 = ROM.rd(PC);
	cppVar_41857 = (cppVar_41855 == 213);
	if (cppVar_41857) {
	cppVar_41861 = PC + 1;
	cppVar_41861 = (cppVar_41861 & cppMask_un_16_);
	cppVar_41862 = ROM.rd(cppVar_41861);
	cppVar_41863 = (cppVar_41862 >> 7) & cppMask_un_1_;
	cppVar_41865 = (cppVar_41863 == 0);
	if (cppVar_41865) {
	cppVar_41866 = PC + 1;
	cppVar_41866 = (cppVar_41866 & cppMask_un_16_);
	cppVar_41867 = ROM.rd(cppVar_41866);
	cppVar_41868 = IRAM.rd(cppVar_41867);
	cppVar_41859 = cppVar_41868;
	} else {
	cppVar_41870 = PC + 1;
	cppVar_41870 = (cppVar_41870 & cppMask_un_16_);
	cppVar_41871 = ROM.rd(cppVar_41870);
	cppVar_41873 = (cppVar_41871 == 128);
	if (cppVar_41873) {
	cppVar_41869 = P0;
	} else {
	cppVar_41875 = PC + 1;
	cppVar_41875 = (cppVar_41875 & cppMask_un_16_);
	cppVar_41876 = ROM.rd(cppVar_41875);
	cppVar_41878 = (cppVar_41876 == 129);
	if (cppVar_41878) {
	cppVar_41874 = SP;
	} else {
	cppVar_41880 = PC + 1;
	cppVar_41880 = (cppVar_41880 & cppMask_un_16_);
	cppVar_41881 = ROM.rd(cppVar_41880);
	cppVar_41883 = (cppVar_41881 == 130);
	if (cppVar_41883) {
	cppVar_41879 = DPL;
	} else {
	cppVar_41885 = PC + 1;
	cppVar_41885 = (cppVar_41885 & cppMask_un_16_);
	cppVar_41886 = ROM.rd(cppVar_41885);
	cppVar_41888 = (cppVar_41886 == 131);
	if (cppVar_41888) {
	cppVar_41884 = DPH;
	} else {
	cppVar_41890 = PC + 1;
	cppVar_41890 = (cppVar_41890 & cppMask_un_16_);
	cppVar_41891 = ROM.rd(cppVar_41890);
	cppVar_41893 = (cppVar_41891 == 135);
	if (cppVar_41893) {
	cppVar_41889 = PCON;
	} else {
	cppVar_41895 = PC + 1;
	cppVar_41895 = (cppVar_41895 & cppMask_un_16_);
	cppVar_41896 = ROM.rd(cppVar_41895);
	cppVar_41898 = (cppVar_41896 == 136);
	if (cppVar_41898) {
	cppVar_41894 = TCON;
	} else {
	cppVar_41900 = PC + 1;
	cppVar_41900 = (cppVar_41900 & cppMask_un_16_);
	cppVar_41901 = ROM.rd(cppVar_41900);
	cppVar_41903 = (cppVar_41901 == 137);
	if (cppVar_41903) {
	cppVar_41899 = TMOD;
	} else {
	cppVar_41905 = PC + 1;
	cppVar_41905 = (cppVar_41905 & cppMask_un_16_);
	cppVar_41906 = ROM.rd(cppVar_41905);
	cppVar_41908 = (cppVar_41906 == 138);
	if (cppVar_41908) {
	cppVar_41904 = TL0;
	} else {
	cppVar_41910 = PC + 1;
	cppVar_41910 = (cppVar_41910 & cppMask_un_16_);
	cppVar_41911 = ROM.rd(cppVar_41910);
	cppVar_41913 = (cppVar_41911 == 140);
	if (cppVar_41913) {
	cppVar_41909 = TH0;
	} else {
	cppVar_41915 = PC + 1;
	cppVar_41915 = (cppVar_41915 & cppMask_un_16_);
	cppVar_41916 = ROM.rd(cppVar_41915);
	cppVar_41918 = (cppVar_41916 == 139);
	if (cppVar_41918) {
	cppVar_41914 = TL1;
	} else {
	cppVar_41920 = PC + 1;
	cppVar_41920 = (cppVar_41920 & cppMask_un_16_);
	cppVar_41921 = ROM.rd(cppVar_41920);
	cppVar_41923 = (cppVar_41921 == 141);
	if (cppVar_41923) {
	cppVar_41919 = TH1;
	} else {
	cppVar_41925 = PC + 1;
	cppVar_41925 = (cppVar_41925 & cppMask_un_16_);
	cppVar_41926 = ROM.rd(cppVar_41925);
	cppVar_41928 = (cppVar_41926 == 144);
	if (cppVar_41928) {
	cppVar_41924 = P1;
	} else {
	cppVar_41930 = PC + 1;
	cppVar_41930 = (cppVar_41930 & cppMask_un_16_);
	cppVar_41931 = ROM.rd(cppVar_41930);
	cppVar_41933 = (cppVar_41931 == 152);
	if (cppVar_41933) {
	cppVar_41929 = SCON;
	} else {
	cppVar_41935 = PC + 1;
	cppVar_41935 = (cppVar_41935 & cppMask_un_16_);
	cppVar_41936 = ROM.rd(cppVar_41935);
	cppVar_41938 = (cppVar_41936 == 153);
	if (cppVar_41938) {
	cppVar_41934 = SBUF;
	} else {
	cppVar_41940 = PC + 1;
	cppVar_41940 = (cppVar_41940 & cppMask_un_16_);
	cppVar_41941 = ROM.rd(cppVar_41940);
	cppVar_41943 = (cppVar_41941 == 160);
	if (cppVar_41943) {
	cppVar_41939 = P2;
	} else {
	cppVar_41945 = PC + 1;
	cppVar_41945 = (cppVar_41945 & cppMask_un_16_);
	cppVar_41946 = ROM.rd(cppVar_41945);
	cppVar_41948 = (cppVar_41946 == 168);
	if (cppVar_41948) {
	cppVar_41944 = IE;
	} else {
	cppVar_41950 = PC + 1;
	cppVar_41950 = (cppVar_41950 & cppMask_un_16_);
	cppVar_41951 = ROM.rd(cppVar_41950);
	cppVar_41953 = (cppVar_41951 == 176);
	if (cppVar_41953) {
	cppVar_41949 = P3;
	} else {
	cppVar_41955 = PC + 1;
	cppVar_41955 = (cppVar_41955 & cppMask_un_16_);
	cppVar_41956 = ROM.rd(cppVar_41955);
	cppVar_41958 = (cppVar_41956 == 184);
	if (cppVar_41958) {
	cppVar_41954 = IP;
	} else {
	cppVar_41960 = PC + 1;
	cppVar_41960 = (cppVar_41960 & cppMask_un_16_);
	cppVar_41961 = ROM.rd(cppVar_41960);
	cppVar_41963 = (cppVar_41961 == 208);
	if (cppVar_41963) {
	cppVar_41959 = PSW;
	} else {
	cppVar_41965 = PC + 1;
	cppVar_41965 = (cppVar_41965 & cppMask_un_16_);
	cppVar_41966 = ROM.rd(cppVar_41965);
	cppVar_41968 = (cppVar_41966 == 224);
	if (cppVar_41968) {
	cppVar_41964 = ACC;
	} else {
	cppVar_41970 = PC + 1;
	cppVar_41970 = (cppVar_41970 & cppMask_un_16_);
	cppVar_41971 = ROM.rd(cppVar_41970);
	cppVar_41973 = (cppVar_41971 == 240);
	if (cppVar_41973) {
	cppVar_41969 = B;
	} else {
	cppVar_41969 = 0;
	}
	cppVar_41964 = cppVar_41969;
	}
	cppVar_41959 = cppVar_41964;
	}
	cppVar_41954 = cppVar_41959;
	}
	cppVar_41949 = cppVar_41954;
	}
	cppVar_41944 = cppVar_41949;
	}
	cppVar_41939 = cppVar_41944;
	}
	cppVar_41934 = cppVar_41939;
	}
	cppVar_41929 = cppVar_41934;
	}
	cppVar_41924 = cppVar_41929;
	}
	cppVar_41919 = cppVar_41924;
	}
	cppVar_41914 = cppVar_41919;
	}
	cppVar_41909 = cppVar_41914;
	}
	cppVar_41904 = cppVar_41909;
	}
	cppVar_41899 = cppVar_41904;
	}
	cppVar_41894 = cppVar_41899;
	}
	cppVar_41889 = cppVar_41894;
	}
	cppVar_41884 = cppVar_41889;
	}
	cppVar_41879 = cppVar_41884;
	}
	cppVar_41874 = cppVar_41879;
	}
	cppVar_41869 = cppVar_41874;
	}
	cppVar_41859 = cppVar_41869;
	}
	cppVar_41976 = (cppVar_41859 != 1);
	if (cppVar_41976) {
	cppVar_41978 = PC + 3;
	cppVar_41978 = (cppVar_41978 & cppMask_un_16_);
	cppVar_41980 = PC + 2;
	cppVar_41980 = (cppVar_41980 & cppMask_un_16_);
	cppVar_41981 = ROM.rd(cppVar_41980);
	cppVar_41982 = ((cppVar_41981 & cppMask_bit_8_) ? (cppVar_41981 | cppMask_sign_8_) : cppVar_41981);
	cppVar_41983 = cppVar_41978 + cppVar_41982;
	cppVar_41983 = (cppVar_41983 & cppMask_un_16_);
	cppVar_41858 = cppVar_41983;
	} else {
	cppVar_41985 = PC + 3;
	cppVar_41985 = (cppVar_41985 & cppMask_un_16_);
	cppVar_41858 = cppVar_41985;
	}
	cppVar_41854 = cppVar_41858;
	} else {
	cppVar_41987 = ROM.rd(PC);
	cppVar_41989 = (cppVar_41987 == 209);
	cppVar_41990 = ROM.rd(PC);
	cppVar_41992 = (cppVar_41990 == 193);
	cppVar_41993 = cppVar_41989 || cppVar_41992;
	if (cppVar_41993) {
	cppVar_41995 = PC + 2;
	cppVar_41995 = (cppVar_41995 & cppMask_un_16_);
	cppVar_41996 = (cppVar_41995 >> 11) & cppMask_un_5_;
	cppVar_41998 = (cppVar_41996 << 3) | 6;
	cppVar_41998 = (cppVar_41998 & cppMask_un_8_);
	cppVar_42000 = PC + 1;
	cppVar_42000 = (cppVar_42000 & cppMask_un_16_);
	cppVar_42001 = ROM.rd(cppVar_42000);
	cppVar_42002 = (cppVar_41998 << 8) | cppVar_42001;
	cppVar_42002 = (cppVar_42002 & cppMask_un_16_);
	cppVar_41986 = cppVar_42002;
	} else {
	cppVar_42004 = ROM.rd(PC);
	cppVar_42006 = (cppVar_42004 == 191);
	if (cppVar_42006) {
	cppVar_42009 = (PSW >> 3) & cppMask_un_2_;
	cppVar_42011 = (cppVar_42009 << 3) | 7;
	cppVar_42011 = (cppVar_42011 & cppMask_un_5_);
	cppVar_42012 = (0 << 5) | cppVar_42011;
	cppVar_42012 = (cppVar_42012 & cppMask_un_8_);
	cppVar_42013 = IRAM.rd(cppVar_42012);
	cppVar_42015 = PC + 1;
	cppVar_42015 = (cppVar_42015 & cppMask_un_16_);
	cppVar_42016 = ROM.rd(cppVar_42015);
	cppVar_42017 = (cppVar_42013 != cppVar_42016);
	if (cppVar_42017) {
	cppVar_42019 = PC + 3;
	cppVar_42019 = (cppVar_42019 & cppMask_un_16_);
	cppVar_42021 = PC + 2;
	cppVar_42021 = (cppVar_42021 & cppMask_un_16_);
	cppVar_42022 = ROM.rd(cppVar_42021);
	cppVar_42023 = ((cppVar_42022 & cppMask_bit_8_) ? (cppVar_42022 | cppMask_sign_8_) : cppVar_42022);
	cppVar_42024 = cppVar_42019 + cppVar_42023;
	cppVar_42024 = (cppVar_42024 & cppMask_un_16_);
	cppVar_42007 = cppVar_42024;
	} else {
	cppVar_42026 = PC + 3;
	cppVar_42026 = (cppVar_42026 & cppMask_un_16_);
	cppVar_42007 = cppVar_42026;
	}
	cppVar_42003 = cppVar_42007;
	} else {
	cppVar_42028 = ROM.rd(PC);
	cppVar_42030 = (cppVar_42028 == 190);
	if (cppVar_42030) {
	cppVar_42033 = (PSW >> 3) & cppMask_un_2_;
	cppVar_42035 = (cppVar_42033 << 3) | 6;
	cppVar_42035 = (cppVar_42035 & cppMask_un_5_);
	cppVar_42036 = (0 << 5) | cppVar_42035;
	cppVar_42036 = (cppVar_42036 & cppMask_un_8_);
	cppVar_42037 = IRAM.rd(cppVar_42036);
	cppVar_42039 = PC + 1;
	cppVar_42039 = (cppVar_42039 & cppMask_un_16_);
	cppVar_42040 = ROM.rd(cppVar_42039);
	cppVar_42041 = (cppVar_42037 != cppVar_42040);
	if (cppVar_42041) {
	cppVar_42043 = PC + 3;
	cppVar_42043 = (cppVar_42043 & cppMask_un_16_);
	cppVar_42045 = PC + 2;
	cppVar_42045 = (cppVar_42045 & cppMask_un_16_);
	cppVar_42046 = ROM.rd(cppVar_42045);
	cppVar_42047 = ((cppVar_42046 & cppMask_bit_8_) ? (cppVar_42046 | cppMask_sign_8_) : cppVar_42046);
	cppVar_42048 = cppVar_42043 + cppVar_42047;
	cppVar_42048 = (cppVar_42048 & cppMask_un_16_);
	cppVar_42031 = cppVar_42048;
	} else {
	cppVar_42050 = PC + 3;
	cppVar_42050 = (cppVar_42050 & cppMask_un_16_);
	cppVar_42031 = cppVar_42050;
	}
	cppVar_42027 = cppVar_42031;
	} else {
	cppVar_42052 = ROM.rd(PC);
	cppVar_42054 = (cppVar_42052 == 189);
	if (cppVar_42054) {
	cppVar_42057 = (PSW >> 3) & cppMask_un_2_;
	cppVar_42059 = (cppVar_42057 << 3) | 5;
	cppVar_42059 = (cppVar_42059 & cppMask_un_5_);
	cppVar_42060 = (0 << 5) | cppVar_42059;
	cppVar_42060 = (cppVar_42060 & cppMask_un_8_);
	cppVar_42061 = IRAM.rd(cppVar_42060);
	cppVar_42063 = PC + 1;
	cppVar_42063 = (cppVar_42063 & cppMask_un_16_);
	cppVar_42064 = ROM.rd(cppVar_42063);
	cppVar_42065 = (cppVar_42061 != cppVar_42064);
	if (cppVar_42065) {
	cppVar_42067 = PC + 3;
	cppVar_42067 = (cppVar_42067 & cppMask_un_16_);
	cppVar_42069 = PC + 2;
	cppVar_42069 = (cppVar_42069 & cppMask_un_16_);
	cppVar_42070 = ROM.rd(cppVar_42069);
	cppVar_42071 = ((cppVar_42070 & cppMask_bit_8_) ? (cppVar_42070 | cppMask_sign_8_) : cppVar_42070);
	cppVar_42072 = cppVar_42067 + cppVar_42071;
	cppVar_42072 = (cppVar_42072 & cppMask_un_16_);
	cppVar_42055 = cppVar_42072;
	} else {
	cppVar_42074 = PC + 3;
	cppVar_42074 = (cppVar_42074 & cppMask_un_16_);
	cppVar_42055 = cppVar_42074;
	}
	cppVar_42051 = cppVar_42055;
	} else {
	cppVar_42076 = ROM.rd(PC);
	cppVar_42078 = (cppVar_42076 == 188);
	if (cppVar_42078) {
	cppVar_42081 = (PSW >> 3) & cppMask_un_2_;
	cppVar_42083 = (cppVar_42081 << 3) | 4;
	cppVar_42083 = (cppVar_42083 & cppMask_un_5_);
	cppVar_42084 = (0 << 5) | cppVar_42083;
	cppVar_42084 = (cppVar_42084 & cppMask_un_8_);
	cppVar_42085 = IRAM.rd(cppVar_42084);
	cppVar_42087 = PC + 1;
	cppVar_42087 = (cppVar_42087 & cppMask_un_16_);
	cppVar_42088 = ROM.rd(cppVar_42087);
	cppVar_42089 = (cppVar_42085 != cppVar_42088);
	if (cppVar_42089) {
	cppVar_42091 = PC + 3;
	cppVar_42091 = (cppVar_42091 & cppMask_un_16_);
	cppVar_42093 = PC + 2;
	cppVar_42093 = (cppVar_42093 & cppMask_un_16_);
	cppVar_42094 = ROM.rd(cppVar_42093);
	cppVar_42095 = ((cppVar_42094 & cppMask_bit_8_) ? (cppVar_42094 | cppMask_sign_8_) : cppVar_42094);
	cppVar_42096 = cppVar_42091 + cppVar_42095;
	cppVar_42096 = (cppVar_42096 & cppMask_un_16_);
	cppVar_42079 = cppVar_42096;
	} else {
	cppVar_42098 = PC + 3;
	cppVar_42098 = (cppVar_42098 & cppMask_un_16_);
	cppVar_42079 = cppVar_42098;
	}
	cppVar_42075 = cppVar_42079;
	} else {
	cppVar_42100 = ROM.rd(PC);
	cppVar_42102 = (cppVar_42100 == 187);
	if (cppVar_42102) {
	cppVar_42105 = (PSW >> 3) & cppMask_un_2_;
	cppVar_42107 = (cppVar_42105 << 3) | 3;
	cppVar_42107 = (cppVar_42107 & cppMask_un_5_);
	cppVar_42108 = (0 << 5) | cppVar_42107;
	cppVar_42108 = (cppVar_42108 & cppMask_un_8_);
	cppVar_42109 = IRAM.rd(cppVar_42108);
	cppVar_42111 = PC + 1;
	cppVar_42111 = (cppVar_42111 & cppMask_un_16_);
	cppVar_42112 = ROM.rd(cppVar_42111);
	cppVar_42113 = (cppVar_42109 != cppVar_42112);
	if (cppVar_42113) {
	cppVar_42115 = PC + 3;
	cppVar_42115 = (cppVar_42115 & cppMask_un_16_);
	cppVar_42117 = PC + 2;
	cppVar_42117 = (cppVar_42117 & cppMask_un_16_);
	cppVar_42118 = ROM.rd(cppVar_42117);
	cppVar_42119 = ((cppVar_42118 & cppMask_bit_8_) ? (cppVar_42118 | cppMask_sign_8_) : cppVar_42118);
	cppVar_42120 = cppVar_42115 + cppVar_42119;
	cppVar_42120 = (cppVar_42120 & cppMask_un_16_);
	cppVar_42103 = cppVar_42120;
	} else {
	cppVar_42122 = PC + 3;
	cppVar_42122 = (cppVar_42122 & cppMask_un_16_);
	cppVar_42103 = cppVar_42122;
	}
	cppVar_42099 = cppVar_42103;
	} else {
	cppVar_42124 = ROM.rd(PC);
	cppVar_42126 = (cppVar_42124 == 186);
	if (cppVar_42126) {
	cppVar_42129 = (PSW >> 3) & cppMask_un_2_;
	cppVar_42131 = (cppVar_42129 << 3) | 2;
	cppVar_42131 = (cppVar_42131 & cppMask_un_5_);
	cppVar_42132 = (0 << 5) | cppVar_42131;
	cppVar_42132 = (cppVar_42132 & cppMask_un_8_);
	cppVar_42133 = IRAM.rd(cppVar_42132);
	cppVar_42135 = PC + 1;
	cppVar_42135 = (cppVar_42135 & cppMask_un_16_);
	cppVar_42136 = ROM.rd(cppVar_42135);
	cppVar_42137 = (cppVar_42133 != cppVar_42136);
	if (cppVar_42137) {
	cppVar_42139 = PC + 3;
	cppVar_42139 = (cppVar_42139 & cppMask_un_16_);
	cppVar_42141 = PC + 2;
	cppVar_42141 = (cppVar_42141 & cppMask_un_16_);
	cppVar_42142 = ROM.rd(cppVar_42141);
	cppVar_42143 = ((cppVar_42142 & cppMask_bit_8_) ? (cppVar_42142 | cppMask_sign_8_) : cppVar_42142);
	cppVar_42144 = cppVar_42139 + cppVar_42143;
	cppVar_42144 = (cppVar_42144 & cppMask_un_16_);
	cppVar_42127 = cppVar_42144;
	} else {
	cppVar_42146 = PC + 3;
	cppVar_42146 = (cppVar_42146 & cppMask_un_16_);
	cppVar_42127 = cppVar_42146;
	}
	cppVar_42123 = cppVar_42127;
	} else {
	cppVar_42148 = ROM.rd(PC);
	cppVar_42150 = (cppVar_42148 == 185);
	if (cppVar_42150) {
	cppVar_42153 = (PSW >> 3) & cppMask_un_2_;
	cppVar_42155 = (cppVar_42153 << 3) | 1;
	cppVar_42155 = (cppVar_42155 & cppMask_un_5_);
	cppVar_42156 = (0 << 5) | cppVar_42155;
	cppVar_42156 = (cppVar_42156 & cppMask_un_8_);
	cppVar_42157 = IRAM.rd(cppVar_42156);
	cppVar_42159 = PC + 1;
	cppVar_42159 = (cppVar_42159 & cppMask_un_16_);
	cppVar_42160 = ROM.rd(cppVar_42159);
	cppVar_42161 = (cppVar_42157 != cppVar_42160);
	if (cppVar_42161) {
	cppVar_42163 = PC + 3;
	cppVar_42163 = (cppVar_42163 & cppMask_un_16_);
	cppVar_42165 = PC + 2;
	cppVar_42165 = (cppVar_42165 & cppMask_un_16_);
	cppVar_42166 = ROM.rd(cppVar_42165);
	cppVar_42167 = ((cppVar_42166 & cppMask_bit_8_) ? (cppVar_42166 | cppMask_sign_8_) : cppVar_42166);
	cppVar_42168 = cppVar_42163 + cppVar_42167;
	cppVar_42168 = (cppVar_42168 & cppMask_un_16_);
	cppVar_42151 = cppVar_42168;
	} else {
	cppVar_42170 = PC + 3;
	cppVar_42170 = (cppVar_42170 & cppMask_un_16_);
	cppVar_42151 = cppVar_42170;
	}
	cppVar_42147 = cppVar_42151;
	} else {
	cppVar_42172 = ROM.rd(PC);
	cppVar_42174 = (cppVar_42172 == 184);
	if (cppVar_42174) {
	cppVar_42177 = (PSW >> 3) & cppMask_un_2_;
	cppVar_42179 = (cppVar_42177 << 3) | 0;
	cppVar_42179 = (cppVar_42179 & cppMask_un_5_);
	cppVar_42180 = (0 << 5) | cppVar_42179;
	cppVar_42180 = (cppVar_42180 & cppMask_un_8_);
	cppVar_42181 = IRAM.rd(cppVar_42180);
	cppVar_42183 = PC + 1;
	cppVar_42183 = (cppVar_42183 & cppMask_un_16_);
	cppVar_42184 = ROM.rd(cppVar_42183);
	cppVar_42185 = (cppVar_42181 != cppVar_42184);
	if (cppVar_42185) {
	cppVar_42187 = PC + 3;
	cppVar_42187 = (cppVar_42187 & cppMask_un_16_);
	cppVar_42189 = PC + 2;
	cppVar_42189 = (cppVar_42189 & cppMask_un_16_);
	cppVar_42190 = ROM.rd(cppVar_42189);
	cppVar_42191 = ((cppVar_42190 & cppMask_bit_8_) ? (cppVar_42190 | cppMask_sign_8_) : cppVar_42190);
	cppVar_42192 = cppVar_42187 + cppVar_42191;
	cppVar_42192 = (cppVar_42192 & cppMask_un_16_);
	cppVar_42175 = cppVar_42192;
	} else {
	cppVar_42194 = PC + 3;
	cppVar_42194 = (cppVar_42194 & cppMask_un_16_);
	cppVar_42175 = cppVar_42194;
	}
	cppVar_42171 = cppVar_42175;
	} else {
	cppVar_42196 = ROM.rd(PC);
	cppVar_42198 = (cppVar_42196 == 183);
	if (cppVar_42198) {
	cppVar_42201 = (PSW >> 3) & cppMask_un_2_;
	cppVar_42203 = (cppVar_42201 << 3) | 1;
	cppVar_42203 = (cppVar_42203 & cppMask_un_5_);
	cppVar_42204 = (0 << 5) | cppVar_42203;
	cppVar_42204 = (cppVar_42204 & cppMask_un_8_);
	cppVar_42205 = IRAM.rd(cppVar_42204);
	cppVar_42206 = IRAM.rd(cppVar_42205);
	cppVar_42208 = PC + 1;
	cppVar_42208 = (cppVar_42208 & cppMask_un_16_);
	cppVar_42209 = ROM.rd(cppVar_42208);
	cppVar_42210 = (cppVar_42206 != cppVar_42209);
	if (cppVar_42210) {
	cppVar_42212 = PC + 3;
	cppVar_42212 = (cppVar_42212 & cppMask_un_16_);
	cppVar_42214 = PC + 2;
	cppVar_42214 = (cppVar_42214 & cppMask_un_16_);
	cppVar_42215 = ROM.rd(cppVar_42214);
	cppVar_42216 = ((cppVar_42215 & cppMask_bit_8_) ? (cppVar_42215 | cppMask_sign_8_) : cppVar_42215);
	cppVar_42217 = cppVar_42212 + cppVar_42216;
	cppVar_42217 = (cppVar_42217 & cppMask_un_16_);
	cppVar_42199 = cppVar_42217;
	} else {
	cppVar_42219 = PC + 3;
	cppVar_42219 = (cppVar_42219 & cppMask_un_16_);
	cppVar_42199 = cppVar_42219;
	}
	cppVar_42195 = cppVar_42199;
	} else {
	cppVar_42221 = ROM.rd(PC);
	cppVar_42223 = (cppVar_42221 == 182);
	if (cppVar_42223) {
	cppVar_42226 = (PSW >> 3) & cppMask_un_2_;
	cppVar_42228 = (cppVar_42226 << 3) | 0;
	cppVar_42228 = (cppVar_42228 & cppMask_un_5_);
	cppVar_42229 = (0 << 5) | cppVar_42228;
	cppVar_42229 = (cppVar_42229 & cppMask_un_8_);
	cppVar_42230 = IRAM.rd(cppVar_42229);
	cppVar_42231 = IRAM.rd(cppVar_42230);
	cppVar_42233 = PC + 1;
	cppVar_42233 = (cppVar_42233 & cppMask_un_16_);
	cppVar_42234 = ROM.rd(cppVar_42233);
	cppVar_42235 = (cppVar_42231 != cppVar_42234);
	if (cppVar_42235) {
	cppVar_42237 = PC + 3;
	cppVar_42237 = (cppVar_42237 & cppMask_un_16_);
	cppVar_42239 = PC + 2;
	cppVar_42239 = (cppVar_42239 & cppMask_un_16_);
	cppVar_42240 = ROM.rd(cppVar_42239);
	cppVar_42241 = ((cppVar_42240 & cppMask_bit_8_) ? (cppVar_42240 | cppMask_sign_8_) : cppVar_42240);
	cppVar_42242 = cppVar_42237 + cppVar_42241;
	cppVar_42242 = (cppVar_42242 & cppMask_un_16_);
	cppVar_42224 = cppVar_42242;
	} else {
	cppVar_42244 = PC + 3;
	cppVar_42244 = (cppVar_42244 & cppMask_un_16_);
	cppVar_42224 = cppVar_42244;
	}
	cppVar_42220 = cppVar_42224;
	} else {
	cppVar_42246 = ROM.rd(PC);
	cppVar_42248 = (cppVar_42246 == 181);
	if (cppVar_42248) {
	cppVar_42252 = PC + 1;
	cppVar_42252 = (cppVar_42252 & cppMask_un_16_);
	cppVar_42253 = ROM.rd(cppVar_42252);
	cppVar_42254 = (cppVar_42253 >> 7) & cppMask_un_1_;
	cppVar_42256 = (cppVar_42254 == 0);
	if (cppVar_42256) {
	cppVar_42257 = PC + 1;
	cppVar_42257 = (cppVar_42257 & cppMask_un_16_);
	cppVar_42258 = ROM.rd(cppVar_42257);
	cppVar_42259 = IRAM.rd(cppVar_42258);
	cppVar_42250 = cppVar_42259;
	} else {
	cppVar_42261 = PC + 1;
	cppVar_42261 = (cppVar_42261 & cppMask_un_16_);
	cppVar_42262 = ROM.rd(cppVar_42261);
	cppVar_42264 = (cppVar_42262 == 128);
	if (cppVar_42264) {
	cppVar_42260 = P0;
	} else {
	cppVar_42266 = PC + 1;
	cppVar_42266 = (cppVar_42266 & cppMask_un_16_);
	cppVar_42267 = ROM.rd(cppVar_42266);
	cppVar_42269 = (cppVar_42267 == 129);
	if (cppVar_42269) {
	cppVar_42265 = SP;
	} else {
	cppVar_42271 = PC + 1;
	cppVar_42271 = (cppVar_42271 & cppMask_un_16_);
	cppVar_42272 = ROM.rd(cppVar_42271);
	cppVar_42274 = (cppVar_42272 == 130);
	if (cppVar_42274) {
	cppVar_42270 = DPL;
	} else {
	cppVar_42276 = PC + 1;
	cppVar_42276 = (cppVar_42276 & cppMask_un_16_);
	cppVar_42277 = ROM.rd(cppVar_42276);
	cppVar_42279 = (cppVar_42277 == 131);
	if (cppVar_42279) {
	cppVar_42275 = DPH;
	} else {
	cppVar_42281 = PC + 1;
	cppVar_42281 = (cppVar_42281 & cppMask_un_16_);
	cppVar_42282 = ROM.rd(cppVar_42281);
	cppVar_42284 = (cppVar_42282 == 135);
	if (cppVar_42284) {
	cppVar_42280 = PCON;
	} else {
	cppVar_42286 = PC + 1;
	cppVar_42286 = (cppVar_42286 & cppMask_un_16_);
	cppVar_42287 = ROM.rd(cppVar_42286);
	cppVar_42289 = (cppVar_42287 == 136);
	if (cppVar_42289) {
	cppVar_42285 = TCON;
	} else {
	cppVar_42291 = PC + 1;
	cppVar_42291 = (cppVar_42291 & cppMask_un_16_);
	cppVar_42292 = ROM.rd(cppVar_42291);
	cppVar_42294 = (cppVar_42292 == 137);
	if (cppVar_42294) {
	cppVar_42290 = TMOD;
	} else {
	cppVar_42296 = PC + 1;
	cppVar_42296 = (cppVar_42296 & cppMask_un_16_);
	cppVar_42297 = ROM.rd(cppVar_42296);
	cppVar_42299 = (cppVar_42297 == 138);
	if (cppVar_42299) {
	cppVar_42295 = TL0;
	} else {
	cppVar_42301 = PC + 1;
	cppVar_42301 = (cppVar_42301 & cppMask_un_16_);
	cppVar_42302 = ROM.rd(cppVar_42301);
	cppVar_42304 = (cppVar_42302 == 140);
	if (cppVar_42304) {
	cppVar_42300 = TH0;
	} else {
	cppVar_42306 = PC + 1;
	cppVar_42306 = (cppVar_42306 & cppMask_un_16_);
	cppVar_42307 = ROM.rd(cppVar_42306);
	cppVar_42309 = (cppVar_42307 == 139);
	if (cppVar_42309) {
	cppVar_42305 = TL1;
	} else {
	cppVar_42311 = PC + 1;
	cppVar_42311 = (cppVar_42311 & cppMask_un_16_);
	cppVar_42312 = ROM.rd(cppVar_42311);
	cppVar_42314 = (cppVar_42312 == 141);
	if (cppVar_42314) {
	cppVar_42310 = TH1;
	} else {
	cppVar_42316 = PC + 1;
	cppVar_42316 = (cppVar_42316 & cppMask_un_16_);
	cppVar_42317 = ROM.rd(cppVar_42316);
	cppVar_42319 = (cppVar_42317 == 144);
	if (cppVar_42319) {
	cppVar_42315 = P1;
	} else {
	cppVar_42321 = PC + 1;
	cppVar_42321 = (cppVar_42321 & cppMask_un_16_);
	cppVar_42322 = ROM.rd(cppVar_42321);
	cppVar_42324 = (cppVar_42322 == 152);
	if (cppVar_42324) {
	cppVar_42320 = SCON;
	} else {
	cppVar_42326 = PC + 1;
	cppVar_42326 = (cppVar_42326 & cppMask_un_16_);
	cppVar_42327 = ROM.rd(cppVar_42326);
	cppVar_42329 = (cppVar_42327 == 153);
	if (cppVar_42329) {
	cppVar_42325 = SBUF;
	} else {
	cppVar_42331 = PC + 1;
	cppVar_42331 = (cppVar_42331 & cppMask_un_16_);
	cppVar_42332 = ROM.rd(cppVar_42331);
	cppVar_42334 = (cppVar_42332 == 160);
	if (cppVar_42334) {
	cppVar_42330 = P2;
	} else {
	cppVar_42336 = PC + 1;
	cppVar_42336 = (cppVar_42336 & cppMask_un_16_);
	cppVar_42337 = ROM.rd(cppVar_42336);
	cppVar_42339 = (cppVar_42337 == 168);
	if (cppVar_42339) {
	cppVar_42335 = IE;
	} else {
	cppVar_42341 = PC + 1;
	cppVar_42341 = (cppVar_42341 & cppMask_un_16_);
	cppVar_42342 = ROM.rd(cppVar_42341);
	cppVar_42344 = (cppVar_42342 == 176);
	if (cppVar_42344) {
	cppVar_42340 = P3;
	} else {
	cppVar_42346 = PC + 1;
	cppVar_42346 = (cppVar_42346 & cppMask_un_16_);
	cppVar_42347 = ROM.rd(cppVar_42346);
	cppVar_42349 = (cppVar_42347 == 184);
	if (cppVar_42349) {
	cppVar_42345 = IP;
	} else {
	cppVar_42351 = PC + 1;
	cppVar_42351 = (cppVar_42351 & cppMask_un_16_);
	cppVar_42352 = ROM.rd(cppVar_42351);
	cppVar_42354 = (cppVar_42352 == 208);
	if (cppVar_42354) {
	cppVar_42350 = PSW;
	} else {
	cppVar_42356 = PC + 1;
	cppVar_42356 = (cppVar_42356 & cppMask_un_16_);
	cppVar_42357 = ROM.rd(cppVar_42356);
	cppVar_42359 = (cppVar_42357 == 224);
	if (cppVar_42359) {
	cppVar_42355 = ACC;
	} else {
	cppVar_42361 = PC + 1;
	cppVar_42361 = (cppVar_42361 & cppMask_un_16_);
	cppVar_42362 = ROM.rd(cppVar_42361);
	cppVar_42364 = (cppVar_42362 == 240);
	if (cppVar_42364) {
	cppVar_42360 = B;
	} else {
	cppVar_42360 = 0;
	}
	cppVar_42355 = cppVar_42360;
	}
	cppVar_42350 = cppVar_42355;
	}
	cppVar_42345 = cppVar_42350;
	}
	cppVar_42340 = cppVar_42345;
	}
	cppVar_42335 = cppVar_42340;
	}
	cppVar_42330 = cppVar_42335;
	}
	cppVar_42325 = cppVar_42330;
	}
	cppVar_42320 = cppVar_42325;
	}
	cppVar_42315 = cppVar_42320;
	}
	cppVar_42310 = cppVar_42315;
	}
	cppVar_42305 = cppVar_42310;
	}
	cppVar_42300 = cppVar_42305;
	}
	cppVar_42295 = cppVar_42300;
	}
	cppVar_42290 = cppVar_42295;
	}
	cppVar_42285 = cppVar_42290;
	}
	cppVar_42280 = cppVar_42285;
	}
	cppVar_42275 = cppVar_42280;
	}
	cppVar_42270 = cppVar_42275;
	}
	cppVar_42265 = cppVar_42270;
	}
	cppVar_42260 = cppVar_42265;
	}
	cppVar_42250 = cppVar_42260;
	}
	cppVar_42366 = (ACC != cppVar_42250);
	if (cppVar_42366) {
	cppVar_42368 = PC + 3;
	cppVar_42368 = (cppVar_42368 & cppMask_un_16_);
	cppVar_42370 = PC + 2;
	cppVar_42370 = (cppVar_42370 & cppMask_un_16_);
	cppVar_42371 = ROM.rd(cppVar_42370);
	cppVar_42372 = ((cppVar_42371 & cppMask_bit_8_) ? (cppVar_42371 | cppMask_sign_8_) : cppVar_42371);
	cppVar_42373 = cppVar_42368 + cppVar_42372;
	cppVar_42373 = (cppVar_42373 & cppMask_un_16_);
	cppVar_42249 = cppVar_42373;
	} else {
	cppVar_42375 = PC + 3;
	cppVar_42375 = (cppVar_42375 & cppMask_un_16_);
	cppVar_42249 = cppVar_42375;
	}
	cppVar_42245 = cppVar_42249;
	} else {
	cppVar_42377 = ROM.rd(PC);
	cppVar_42379 = (cppVar_42377 == 180);
	if (cppVar_42379) {
	cppVar_42382 = PC + 1;
	cppVar_42382 = (cppVar_42382 & cppMask_un_16_);
	cppVar_42383 = ROM.rd(cppVar_42382);
	cppVar_42384 = (ACC != cppVar_42383);
	if (cppVar_42384) {
	cppVar_42386 = PC + 3;
	cppVar_42386 = (cppVar_42386 & cppMask_un_16_);
	cppVar_42388 = PC + 2;
	cppVar_42388 = (cppVar_42388 & cppMask_un_16_);
	cppVar_42389 = ROM.rd(cppVar_42388);
	cppVar_42390 = ((cppVar_42389 & cppMask_bit_8_) ? (cppVar_42389 | cppMask_sign_8_) : cppVar_42389);
	cppVar_42391 = cppVar_42386 + cppVar_42390;
	cppVar_42391 = (cppVar_42391 & cppMask_un_16_);
	cppVar_42380 = cppVar_42391;
	} else {
	cppVar_42393 = PC + 3;
	cppVar_42393 = (cppVar_42393 & cppMask_un_16_);
	cppVar_42380 = cppVar_42393;
	}
	cppVar_42376 = cppVar_42380;
	} else {
	cppVar_42395 = ROM.rd(PC);
	cppVar_42397 = (cppVar_42395 == 177);
	cppVar_42398 = ROM.rd(PC);
	cppVar_42400 = (cppVar_42398 == 161);
	cppVar_42401 = cppVar_42397 || cppVar_42400;
	if (cppVar_42401) {
	cppVar_42403 = PC + 2;
	cppVar_42403 = (cppVar_42403 & cppMask_un_16_);
	cppVar_42404 = (cppVar_42403 >> 11) & cppMask_un_5_;
	cppVar_42406 = (cppVar_42404 << 3) | 5;
	cppVar_42406 = (cppVar_42406 & cppMask_un_8_);
	cppVar_42408 = PC + 1;
	cppVar_42408 = (cppVar_42408 & cppMask_un_16_);
	cppVar_42409 = ROM.rd(cppVar_42408);
	cppVar_42410 = (cppVar_42406 << 8) | cppVar_42409;
	cppVar_42410 = (cppVar_42410 & cppMask_un_16_);
	cppVar_42394 = cppVar_42410;
	} else {
	cppVar_42412 = ROM.rd(PC);
	cppVar_42414 = (cppVar_42412 == 145);
	cppVar_42415 = ROM.rd(PC);
	cppVar_42417 = (cppVar_42415 == 129);
	cppVar_42418 = cppVar_42414 || cppVar_42417;
	if (cppVar_42418) {
	cppVar_42420 = PC + 2;
	cppVar_42420 = (cppVar_42420 & cppMask_un_16_);
	cppVar_42421 = (cppVar_42420 >> 11) & cppMask_un_5_;
	cppVar_42423 = (cppVar_42421 << 3) | 4;
	cppVar_42423 = (cppVar_42423 & cppMask_un_8_);
	cppVar_42425 = PC + 1;
	cppVar_42425 = (cppVar_42425 & cppMask_un_16_);
	cppVar_42426 = ROM.rd(cppVar_42425);
	cppVar_42427 = (cppVar_42423 << 8) | cppVar_42426;
	cppVar_42427 = (cppVar_42427 & cppMask_un_16_);
	cppVar_42411 = cppVar_42427;
	} else {
	cppVar_42429 = ROM.rd(PC);
	cppVar_42431 = (cppVar_42429 == 128);
	if (cppVar_42431) {
	cppVar_42433 = PC + 2;
	cppVar_42433 = (cppVar_42433 & cppMask_un_16_);
	cppVar_42435 = PC + 1;
	cppVar_42435 = (cppVar_42435 & cppMask_un_16_);
	cppVar_42436 = ROM.rd(cppVar_42435);
	cppVar_42437 = ((cppVar_42436 & cppMask_bit_8_) ? (cppVar_42436 | cppMask_sign_8_) : cppVar_42436);
	cppVar_42438 = cppVar_42433 + cppVar_42437;
	cppVar_42438 = (cppVar_42438 & cppMask_un_16_);
	cppVar_42428 = cppVar_42438;
	} else {
	cppVar_42440 = ROM.rd(PC);
	cppVar_42442 = (cppVar_42440 == 115);
	if (cppVar_42442) {
	cppVar_42443 = (DPH << 8) | DPL;
	cppVar_42443 = (cppVar_42443 & cppMask_un_16_);
	cppVar_42444 = (ACC & cppMask_un_8_);
	cppVar_42445 = cppVar_42443 + cppVar_42444;
	cppVar_42445 = (cppVar_42445 & cppMask_un_16_);
	cppVar_42439 = cppVar_42445;
	} else {
	cppVar_42447 = ROM.rd(PC);
	cppVar_42449 = (cppVar_42447 == 112);
	if (cppVar_42449) {
	cppVar_42452 = (ACC != 0);
	if (cppVar_42452) {
	cppVar_42454 = PC + 2;
	cppVar_42454 = (cppVar_42454 & cppMask_un_16_);
	cppVar_42456 = PC + 1;
	cppVar_42456 = (cppVar_42456 & cppMask_un_16_);
	cppVar_42457 = ROM.rd(cppVar_42456);
	cppVar_42458 = ((cppVar_42457 & cppMask_bit_8_) ? (cppVar_42457 | cppMask_sign_8_) : cppVar_42457);
	cppVar_42459 = cppVar_42454 + cppVar_42458;
	cppVar_42459 = (cppVar_42459 & cppMask_un_16_);
	cppVar_42450 = cppVar_42459;
	} else {
	cppVar_42461 = PC + 2;
	cppVar_42461 = (cppVar_42461 & cppMask_un_16_);
	cppVar_42450 = cppVar_42461;
	}
	cppVar_42446 = cppVar_42450;
	} else {
	cppVar_42463 = ROM.rd(PC);
	cppVar_42465 = (cppVar_42463 == 113);
	cppVar_42466 = ROM.rd(PC);
	cppVar_42468 = (cppVar_42466 == 97);
	cppVar_42469 = cppVar_42465 || cppVar_42468;
	if (cppVar_42469) {
	cppVar_42471 = PC + 2;
	cppVar_42471 = (cppVar_42471 & cppMask_un_16_);
	cppVar_42472 = (cppVar_42471 >> 11) & cppMask_un_5_;
	cppVar_42474 = (cppVar_42472 << 3) | 3;
	cppVar_42474 = (cppVar_42474 & cppMask_un_8_);
	cppVar_42476 = PC + 1;
	cppVar_42476 = (cppVar_42476 & cppMask_un_16_);
	cppVar_42477 = ROM.rd(cppVar_42476);
	cppVar_42478 = (cppVar_42474 << 8) | cppVar_42477;
	cppVar_42478 = (cppVar_42478 & cppMask_un_16_);
	cppVar_42462 = cppVar_42478;
	} else {
	cppVar_42480 = ROM.rd(PC);
	cppVar_42482 = (cppVar_42480 == 96);
	if (cppVar_42482) {
	cppVar_42485 = (ACC == 0);
	if (cppVar_42485) {
	cppVar_42487 = PC + 2;
	cppVar_42487 = (cppVar_42487 & cppMask_un_16_);
	cppVar_42489 = PC + 1;
	cppVar_42489 = (cppVar_42489 & cppMask_un_16_);
	cppVar_42490 = ROM.rd(cppVar_42489);
	cppVar_42491 = ((cppVar_42490 & cppMask_bit_8_) ? (cppVar_42490 | cppMask_sign_8_) : cppVar_42490);
	cppVar_42492 = cppVar_42487 + cppVar_42491;
	cppVar_42492 = (cppVar_42492 & cppMask_un_16_);
	cppVar_42483 = cppVar_42492;
	} else {
	cppVar_42494 = PC + 2;
	cppVar_42494 = (cppVar_42494 & cppMask_un_16_);
	cppVar_42483 = cppVar_42494;
	}
	cppVar_42479 = cppVar_42483;
	} else {
	cppVar_42496 = ROM.rd(PC);
	cppVar_42498 = (cppVar_42496 == 80);
	if (cppVar_42498) {
	cppVar_42500 = (PSW >> 7) & cppMask_un_1_;
	cppVar_42502 = (cppVar_42500 == 0);
	if (cppVar_42502) {
	cppVar_42504 = PC + 2;
	cppVar_42504 = (cppVar_42504 & cppMask_un_16_);
	cppVar_42506 = PC + 1;
	cppVar_42506 = (cppVar_42506 & cppMask_un_16_);
	cppVar_42507 = ROM.rd(cppVar_42506);
	cppVar_42508 = ((cppVar_42507 & cppMask_bit_8_) ? (cppVar_42507 | cppMask_sign_8_) : cppVar_42507);
	cppVar_42509 = cppVar_42504 + cppVar_42508;
	cppVar_42509 = (cppVar_42509 & cppMask_un_16_);
	cppVar_42499 = cppVar_42509;
	} else {
	cppVar_42511 = PC + 2;
	cppVar_42511 = (cppVar_42511 & cppMask_un_16_);
	cppVar_42499 = cppVar_42511;
	}
	cppVar_42495 = cppVar_42499;
	} else {
	cppVar_42513 = ROM.rd(PC);
	cppVar_42515 = (cppVar_42513 == 144);
	cppVar_42516 = ROM.rd(PC);
	cppVar_42518 = (cppVar_42516 == 133);
	cppVar_42519 = ROM.rd(PC);
	cppVar_42521 = (cppVar_42519 == 117);
	cppVar_42522 = ROM.rd(PC);
	cppVar_42524 = (cppVar_42522 == 99);
	cppVar_42525 = ROM.rd(PC);
	cppVar_42527 = (cppVar_42525 == 83);
	cppVar_42528 = ROM.rd(PC);
	cppVar_42530 = (cppVar_42528 == 67);
	cppVar_42531 = cppVar_42527 || cppVar_42530;
	cppVar_42532 = cppVar_42524 || cppVar_42531;
	cppVar_42533 = cppVar_42521 || cppVar_42532;
	cppVar_42534 = cppVar_42518 || cppVar_42533;
	cppVar_42535 = cppVar_42515 || cppVar_42534;
	if (cppVar_42535) {
	cppVar_42537 = PC + 3;
	cppVar_42537 = (cppVar_42537 & cppMask_un_16_);
	cppVar_42512 = cppVar_42537;
	} else {
	cppVar_42539 = ROM.rd(PC);
	cppVar_42541 = (cppVar_42539 == 81);
	cppVar_42542 = ROM.rd(PC);
	cppVar_42544 = (cppVar_42542 == 65);
	cppVar_42545 = cppVar_42541 || cppVar_42544;
	if (cppVar_42545) {
	cppVar_42547 = PC + 2;
	cppVar_42547 = (cppVar_42547 & cppMask_un_16_);
	cppVar_42548 = (cppVar_42547 >> 11) & cppMask_un_5_;
	cppVar_42550 = (cppVar_42548 << 3) | 2;
	cppVar_42550 = (cppVar_42550 & cppMask_un_8_);
	cppVar_42552 = PC + 1;
	cppVar_42552 = (cppVar_42552 & cppMask_un_16_);
	cppVar_42553 = ROM.rd(cppVar_42552);
	cppVar_42554 = (cppVar_42550 << 8) | cppVar_42553;
	cppVar_42554 = (cppVar_42554 & cppMask_un_16_);
	cppVar_42538 = cppVar_42554;
	} else {
	cppVar_42556 = ROM.rd(PC);
	cppVar_42558 = (cppVar_42556 == 64);
	if (cppVar_42558) {
	cppVar_42560 = (PSW >> 7) & cppMask_un_1_;
	cppVar_42562 = (cppVar_42560 == 1);
	if (cppVar_42562) {
	cppVar_42564 = PC + 2;
	cppVar_42564 = (cppVar_42564 & cppMask_un_16_);
	cppVar_42566 = PC + 1;
	cppVar_42566 = (cppVar_42566 & cppMask_un_16_);
	cppVar_42567 = ROM.rd(cppVar_42566);
	cppVar_42568 = ((cppVar_42567 & cppMask_bit_8_) ? (cppVar_42567 | cppMask_sign_8_) : cppVar_42567);
	cppVar_42569 = cppVar_42564 + cppVar_42568;
	cppVar_42569 = (cppVar_42569 & cppMask_un_16_);
	cppVar_42559 = cppVar_42569;
	} else {
	cppVar_42571 = PC + 2;
	cppVar_42571 = (cppVar_42571 & cppMask_un_16_);
	cppVar_42559 = cppVar_42571;
	}
	cppVar_42555 = cppVar_42559;
	} else {
	cppVar_42573 = ROM.rd(PC);
	cppVar_42575 = (cppVar_42573 == 48);
	if (cppVar_42575) {
	cppVar_42580 = PC + 1;
	cppVar_42580 = (cppVar_42580 & cppMask_un_16_);
	cppVar_42581 = ROM.rd(cppVar_42580);
	cppVar_42582 = (cppVar_42581 >> 7) & cppMask_un_1_;
	cppVar_42584 = (cppVar_42582 == 1);
	if (cppVar_42584) {
	cppVar_42585 = PC + 1;
	cppVar_42585 = (cppVar_42585 & cppMask_un_16_);
	cppVar_42586 = ROM.rd(cppVar_42585);
	cppVar_42587 = (cppVar_42586 >> 3) & cppMask_un_5_;
	cppVar_42589 = (cppVar_42587 << 3) | 0;
	cppVar_42589 = (cppVar_42589 & cppMask_un_8_);
	cppVar_42578 = cppVar_42589;
	} else {
	cppVar_42590 = PC + 1;
	cppVar_42590 = (cppVar_42590 & cppMask_un_16_);
	cppVar_42591 = ROM.rd(cppVar_42590);
	cppVar_42592 = (cppVar_42591 >> 3) & cppMask_un_5_;
	cppVar_42593 = (cppVar_42592 & cppMask_un_5_);
	cppVar_42595 = cppVar_42593 + 32;
	cppVar_42595 = (cppVar_42595 & cppMask_un_8_);
	cppVar_42578 = cppVar_42595;
	}
	cppVar_42596 = (cppVar_42578 >> 7) & cppMask_un_1_;
	cppVar_42598 = (cppVar_42596 == 0);
	if (cppVar_42598) {
	cppVar_42600 = PC + 1;
	cppVar_42600 = (cppVar_42600 & cppMask_un_16_);
	cppVar_42601 = ROM.rd(cppVar_42600);
	cppVar_42602 = (cppVar_42601 >> 7) & cppMask_un_1_;
	cppVar_42603 = (cppVar_42602 == 1);
	if (cppVar_42603) {
	cppVar_42604 = PC + 1;
	cppVar_42604 = (cppVar_42604 & cppMask_un_16_);
	cppVar_42605 = ROM.rd(cppVar_42604);
	cppVar_42606 = (cppVar_42605 >> 3) & cppMask_un_5_;
	cppVar_42607 = (cppVar_42606 << 3) | 0;
	cppVar_42607 = (cppVar_42607 & cppMask_un_8_);
	cppVar_42599 = cppVar_42607;
	} else {
	cppVar_42608 = PC + 1;
	cppVar_42608 = (cppVar_42608 & cppMask_un_16_);
	cppVar_42609 = ROM.rd(cppVar_42608);
	cppVar_42610 = (cppVar_42609 >> 3) & cppMask_un_5_;
	cppVar_42611 = (cppVar_42610 & cppMask_un_5_);
	cppVar_42612 = cppVar_42611 + 32;
	cppVar_42612 = (cppVar_42612 & cppMask_un_8_);
	cppVar_42599 = cppVar_42612;
	}
	cppVar_42613 = IRAM.rd(cppVar_42599);
	cppVar_42577 = cppVar_42613;
	} else {
	cppVar_42616 = PC + 1;
	cppVar_42616 = (cppVar_42616 & cppMask_un_16_);
	cppVar_42617 = ROM.rd(cppVar_42616);
	cppVar_42618 = (cppVar_42617 >> 7) & cppMask_un_1_;
	cppVar_42619 = (cppVar_42618 == 1);
	if (cppVar_42619) {
	cppVar_42620 = PC + 1;
	cppVar_42620 = (cppVar_42620 & cppMask_un_16_);
	cppVar_42621 = ROM.rd(cppVar_42620);
	cppVar_42622 = (cppVar_42621 >> 3) & cppMask_un_5_;
	cppVar_42623 = (cppVar_42622 << 3) | 0;
	cppVar_42623 = (cppVar_42623 & cppMask_un_8_);
	cppVar_42615 = cppVar_42623;
	} else {
	cppVar_42624 = PC + 1;
	cppVar_42624 = (cppVar_42624 & cppMask_un_16_);
	cppVar_42625 = ROM.rd(cppVar_42624);
	cppVar_42626 = (cppVar_42625 >> 3) & cppMask_un_5_;
	cppVar_42627 = (cppVar_42626 & cppMask_un_5_);
	cppVar_42628 = cppVar_42627 + 32;
	cppVar_42628 = (cppVar_42628 & cppMask_un_8_);
	cppVar_42615 = cppVar_42628;
	}
	cppVar_42630 = (cppVar_42615 == 128);
	if (cppVar_42630) {
	cppVar_42614 = P0;
	} else {
	cppVar_42633 = PC + 1;
	cppVar_42633 = (cppVar_42633 & cppMask_un_16_);
	cppVar_42634 = ROM.rd(cppVar_42633);
	cppVar_42635 = (cppVar_42634 >> 7) & cppMask_un_1_;
	cppVar_42636 = (cppVar_42635 == 1);
	if (cppVar_42636) {
	cppVar_42637 = PC + 1;
	cppVar_42637 = (cppVar_42637 & cppMask_un_16_);
	cppVar_42638 = ROM.rd(cppVar_42637);
	cppVar_42639 = (cppVar_42638 >> 3) & cppMask_un_5_;
	cppVar_42640 = (cppVar_42639 << 3) | 0;
	cppVar_42640 = (cppVar_42640 & cppMask_un_8_);
	cppVar_42632 = cppVar_42640;
	} else {
	cppVar_42641 = PC + 1;
	cppVar_42641 = (cppVar_42641 & cppMask_un_16_);
	cppVar_42642 = ROM.rd(cppVar_42641);
	cppVar_42643 = (cppVar_42642 >> 3) & cppMask_un_5_;
	cppVar_42644 = (cppVar_42643 & cppMask_un_5_);
	cppVar_42645 = cppVar_42644 + 32;
	cppVar_42645 = (cppVar_42645 & cppMask_un_8_);
	cppVar_42632 = cppVar_42645;
	}
	cppVar_42647 = (cppVar_42632 == 129);
	if (cppVar_42647) {
	cppVar_42631 = SP;
	} else {
	cppVar_42650 = PC + 1;
	cppVar_42650 = (cppVar_42650 & cppMask_un_16_);
	cppVar_42651 = ROM.rd(cppVar_42650);
	cppVar_42652 = (cppVar_42651 >> 7) & cppMask_un_1_;
	cppVar_42653 = (cppVar_42652 == 1);
	if (cppVar_42653) {
	cppVar_42654 = PC + 1;
	cppVar_42654 = (cppVar_42654 & cppMask_un_16_);
	cppVar_42655 = ROM.rd(cppVar_42654);
	cppVar_42656 = (cppVar_42655 >> 3) & cppMask_un_5_;
	cppVar_42657 = (cppVar_42656 << 3) | 0;
	cppVar_42657 = (cppVar_42657 & cppMask_un_8_);
	cppVar_42649 = cppVar_42657;
	} else {
	cppVar_42658 = PC + 1;
	cppVar_42658 = (cppVar_42658 & cppMask_un_16_);
	cppVar_42659 = ROM.rd(cppVar_42658);
	cppVar_42660 = (cppVar_42659 >> 3) & cppMask_un_5_;
	cppVar_42661 = (cppVar_42660 & cppMask_un_5_);
	cppVar_42662 = cppVar_42661 + 32;
	cppVar_42662 = (cppVar_42662 & cppMask_un_8_);
	cppVar_42649 = cppVar_42662;
	}
	cppVar_42664 = (cppVar_42649 == 130);
	if (cppVar_42664) {
	cppVar_42648 = DPL;
	} else {
	cppVar_42667 = PC + 1;
	cppVar_42667 = (cppVar_42667 & cppMask_un_16_);
	cppVar_42668 = ROM.rd(cppVar_42667);
	cppVar_42669 = (cppVar_42668 >> 7) & cppMask_un_1_;
	cppVar_42670 = (cppVar_42669 == 1);
	if (cppVar_42670) {
	cppVar_42671 = PC + 1;
	cppVar_42671 = (cppVar_42671 & cppMask_un_16_);
	cppVar_42672 = ROM.rd(cppVar_42671);
	cppVar_42673 = (cppVar_42672 >> 3) & cppMask_un_5_;
	cppVar_42674 = (cppVar_42673 << 3) | 0;
	cppVar_42674 = (cppVar_42674 & cppMask_un_8_);
	cppVar_42666 = cppVar_42674;
	} else {
	cppVar_42675 = PC + 1;
	cppVar_42675 = (cppVar_42675 & cppMask_un_16_);
	cppVar_42676 = ROM.rd(cppVar_42675);
	cppVar_42677 = (cppVar_42676 >> 3) & cppMask_un_5_;
	cppVar_42678 = (cppVar_42677 & cppMask_un_5_);
	cppVar_42679 = cppVar_42678 + 32;
	cppVar_42679 = (cppVar_42679 & cppMask_un_8_);
	cppVar_42666 = cppVar_42679;
	}
	cppVar_42681 = (cppVar_42666 == 131);
	if (cppVar_42681) {
	cppVar_42665 = DPH;
	} else {
	cppVar_42684 = PC + 1;
	cppVar_42684 = (cppVar_42684 & cppMask_un_16_);
	cppVar_42685 = ROM.rd(cppVar_42684);
	cppVar_42686 = (cppVar_42685 >> 7) & cppMask_un_1_;
	cppVar_42687 = (cppVar_42686 == 1);
	if (cppVar_42687) {
	cppVar_42688 = PC + 1;
	cppVar_42688 = (cppVar_42688 & cppMask_un_16_);
	cppVar_42689 = ROM.rd(cppVar_42688);
	cppVar_42690 = (cppVar_42689 >> 3) & cppMask_un_5_;
	cppVar_42691 = (cppVar_42690 << 3) | 0;
	cppVar_42691 = (cppVar_42691 & cppMask_un_8_);
	cppVar_42683 = cppVar_42691;
	} else {
	cppVar_42692 = PC + 1;
	cppVar_42692 = (cppVar_42692 & cppMask_un_16_);
	cppVar_42693 = ROM.rd(cppVar_42692);
	cppVar_42694 = (cppVar_42693 >> 3) & cppMask_un_5_;
	cppVar_42695 = (cppVar_42694 & cppMask_un_5_);
	cppVar_42696 = cppVar_42695 + 32;
	cppVar_42696 = (cppVar_42696 & cppMask_un_8_);
	cppVar_42683 = cppVar_42696;
	}
	cppVar_42698 = (cppVar_42683 == 135);
	if (cppVar_42698) {
	cppVar_42682 = PCON;
	} else {
	cppVar_42701 = PC + 1;
	cppVar_42701 = (cppVar_42701 & cppMask_un_16_);
	cppVar_42702 = ROM.rd(cppVar_42701);
	cppVar_42703 = (cppVar_42702 >> 7) & cppMask_un_1_;
	cppVar_42704 = (cppVar_42703 == 1);
	if (cppVar_42704) {
	cppVar_42705 = PC + 1;
	cppVar_42705 = (cppVar_42705 & cppMask_un_16_);
	cppVar_42706 = ROM.rd(cppVar_42705);
	cppVar_42707 = (cppVar_42706 >> 3) & cppMask_un_5_;
	cppVar_42708 = (cppVar_42707 << 3) | 0;
	cppVar_42708 = (cppVar_42708 & cppMask_un_8_);
	cppVar_42700 = cppVar_42708;
	} else {
	cppVar_42709 = PC + 1;
	cppVar_42709 = (cppVar_42709 & cppMask_un_16_);
	cppVar_42710 = ROM.rd(cppVar_42709);
	cppVar_42711 = (cppVar_42710 >> 3) & cppMask_un_5_;
	cppVar_42712 = (cppVar_42711 & cppMask_un_5_);
	cppVar_42713 = cppVar_42712 + 32;
	cppVar_42713 = (cppVar_42713 & cppMask_un_8_);
	cppVar_42700 = cppVar_42713;
	}
	cppVar_42715 = (cppVar_42700 == 136);
	if (cppVar_42715) {
	cppVar_42699 = TCON;
	} else {
	cppVar_42718 = PC + 1;
	cppVar_42718 = (cppVar_42718 & cppMask_un_16_);
	cppVar_42719 = ROM.rd(cppVar_42718);
	cppVar_42720 = (cppVar_42719 >> 7) & cppMask_un_1_;
	cppVar_42721 = (cppVar_42720 == 1);
	if (cppVar_42721) {
	cppVar_42722 = PC + 1;
	cppVar_42722 = (cppVar_42722 & cppMask_un_16_);
	cppVar_42723 = ROM.rd(cppVar_42722);
	cppVar_42724 = (cppVar_42723 >> 3) & cppMask_un_5_;
	cppVar_42725 = (cppVar_42724 << 3) | 0;
	cppVar_42725 = (cppVar_42725 & cppMask_un_8_);
	cppVar_42717 = cppVar_42725;
	} else {
	cppVar_42726 = PC + 1;
	cppVar_42726 = (cppVar_42726 & cppMask_un_16_);
	cppVar_42727 = ROM.rd(cppVar_42726);
	cppVar_42728 = (cppVar_42727 >> 3) & cppMask_un_5_;
	cppVar_42729 = (cppVar_42728 & cppMask_un_5_);
	cppVar_42730 = cppVar_42729 + 32;
	cppVar_42730 = (cppVar_42730 & cppMask_un_8_);
	cppVar_42717 = cppVar_42730;
	}
	cppVar_42732 = (cppVar_42717 == 137);
	if (cppVar_42732) {
	cppVar_42716 = TMOD;
	} else {
	cppVar_42735 = PC + 1;
	cppVar_42735 = (cppVar_42735 & cppMask_un_16_);
	cppVar_42736 = ROM.rd(cppVar_42735);
	cppVar_42737 = (cppVar_42736 >> 7) & cppMask_un_1_;
	cppVar_42738 = (cppVar_42737 == 1);
	if (cppVar_42738) {
	cppVar_42739 = PC + 1;
	cppVar_42739 = (cppVar_42739 & cppMask_un_16_);
	cppVar_42740 = ROM.rd(cppVar_42739);
	cppVar_42741 = (cppVar_42740 >> 3) & cppMask_un_5_;
	cppVar_42742 = (cppVar_42741 << 3) | 0;
	cppVar_42742 = (cppVar_42742 & cppMask_un_8_);
	cppVar_42734 = cppVar_42742;
	} else {
	cppVar_42743 = PC + 1;
	cppVar_42743 = (cppVar_42743 & cppMask_un_16_);
	cppVar_42744 = ROM.rd(cppVar_42743);
	cppVar_42745 = (cppVar_42744 >> 3) & cppMask_un_5_;
	cppVar_42746 = (cppVar_42745 & cppMask_un_5_);
	cppVar_42747 = cppVar_42746 + 32;
	cppVar_42747 = (cppVar_42747 & cppMask_un_8_);
	cppVar_42734 = cppVar_42747;
	}
	cppVar_42749 = (cppVar_42734 == 138);
	if (cppVar_42749) {
	cppVar_42733 = TL0;
	} else {
	cppVar_42752 = PC + 1;
	cppVar_42752 = (cppVar_42752 & cppMask_un_16_);
	cppVar_42753 = ROM.rd(cppVar_42752);
	cppVar_42754 = (cppVar_42753 >> 7) & cppMask_un_1_;
	cppVar_42755 = (cppVar_42754 == 1);
	if (cppVar_42755) {
	cppVar_42756 = PC + 1;
	cppVar_42756 = (cppVar_42756 & cppMask_un_16_);
	cppVar_42757 = ROM.rd(cppVar_42756);
	cppVar_42758 = (cppVar_42757 >> 3) & cppMask_un_5_;
	cppVar_42759 = (cppVar_42758 << 3) | 0;
	cppVar_42759 = (cppVar_42759 & cppMask_un_8_);
	cppVar_42751 = cppVar_42759;
	} else {
	cppVar_42760 = PC + 1;
	cppVar_42760 = (cppVar_42760 & cppMask_un_16_);
	cppVar_42761 = ROM.rd(cppVar_42760);
	cppVar_42762 = (cppVar_42761 >> 3) & cppMask_un_5_;
	cppVar_42763 = (cppVar_42762 & cppMask_un_5_);
	cppVar_42764 = cppVar_42763 + 32;
	cppVar_42764 = (cppVar_42764 & cppMask_un_8_);
	cppVar_42751 = cppVar_42764;
	}
	cppVar_42766 = (cppVar_42751 == 140);
	if (cppVar_42766) {
	cppVar_42750 = TH0;
	} else {
	cppVar_42769 = PC + 1;
	cppVar_42769 = (cppVar_42769 & cppMask_un_16_);
	cppVar_42770 = ROM.rd(cppVar_42769);
	cppVar_42771 = (cppVar_42770 >> 7) & cppMask_un_1_;
	cppVar_42772 = (cppVar_42771 == 1);
	if (cppVar_42772) {
	cppVar_42773 = PC + 1;
	cppVar_42773 = (cppVar_42773 & cppMask_un_16_);
	cppVar_42774 = ROM.rd(cppVar_42773);
	cppVar_42775 = (cppVar_42774 >> 3) & cppMask_un_5_;
	cppVar_42776 = (cppVar_42775 << 3) | 0;
	cppVar_42776 = (cppVar_42776 & cppMask_un_8_);
	cppVar_42768 = cppVar_42776;
	} else {
	cppVar_42777 = PC + 1;
	cppVar_42777 = (cppVar_42777 & cppMask_un_16_);
	cppVar_42778 = ROM.rd(cppVar_42777);
	cppVar_42779 = (cppVar_42778 >> 3) & cppMask_un_5_;
	cppVar_42780 = (cppVar_42779 & cppMask_un_5_);
	cppVar_42781 = cppVar_42780 + 32;
	cppVar_42781 = (cppVar_42781 & cppMask_un_8_);
	cppVar_42768 = cppVar_42781;
	}
	cppVar_42783 = (cppVar_42768 == 139);
	if (cppVar_42783) {
	cppVar_42767 = TL1;
	} else {
	cppVar_42786 = PC + 1;
	cppVar_42786 = (cppVar_42786 & cppMask_un_16_);
	cppVar_42787 = ROM.rd(cppVar_42786);
	cppVar_42788 = (cppVar_42787 >> 7) & cppMask_un_1_;
	cppVar_42789 = (cppVar_42788 == 1);
	if (cppVar_42789) {
	cppVar_42790 = PC + 1;
	cppVar_42790 = (cppVar_42790 & cppMask_un_16_);
	cppVar_42791 = ROM.rd(cppVar_42790);
	cppVar_42792 = (cppVar_42791 >> 3) & cppMask_un_5_;
	cppVar_42793 = (cppVar_42792 << 3) | 0;
	cppVar_42793 = (cppVar_42793 & cppMask_un_8_);
	cppVar_42785 = cppVar_42793;
	} else {
	cppVar_42794 = PC + 1;
	cppVar_42794 = (cppVar_42794 & cppMask_un_16_);
	cppVar_42795 = ROM.rd(cppVar_42794);
	cppVar_42796 = (cppVar_42795 >> 3) & cppMask_un_5_;
	cppVar_42797 = (cppVar_42796 & cppMask_un_5_);
	cppVar_42798 = cppVar_42797 + 32;
	cppVar_42798 = (cppVar_42798 & cppMask_un_8_);
	cppVar_42785 = cppVar_42798;
	}
	cppVar_42800 = (cppVar_42785 == 141);
	if (cppVar_42800) {
	cppVar_42784 = TH1;
	} else {
	cppVar_42803 = PC + 1;
	cppVar_42803 = (cppVar_42803 & cppMask_un_16_);
	cppVar_42804 = ROM.rd(cppVar_42803);
	cppVar_42805 = (cppVar_42804 >> 7) & cppMask_un_1_;
	cppVar_42806 = (cppVar_42805 == 1);
	if (cppVar_42806) {
	cppVar_42807 = PC + 1;
	cppVar_42807 = (cppVar_42807 & cppMask_un_16_);
	cppVar_42808 = ROM.rd(cppVar_42807);
	cppVar_42809 = (cppVar_42808 >> 3) & cppMask_un_5_;
	cppVar_42810 = (cppVar_42809 << 3) | 0;
	cppVar_42810 = (cppVar_42810 & cppMask_un_8_);
	cppVar_42802 = cppVar_42810;
	} else {
	cppVar_42811 = PC + 1;
	cppVar_42811 = (cppVar_42811 & cppMask_un_16_);
	cppVar_42812 = ROM.rd(cppVar_42811);
	cppVar_42813 = (cppVar_42812 >> 3) & cppMask_un_5_;
	cppVar_42814 = (cppVar_42813 & cppMask_un_5_);
	cppVar_42815 = cppVar_42814 + 32;
	cppVar_42815 = (cppVar_42815 & cppMask_un_8_);
	cppVar_42802 = cppVar_42815;
	}
	cppVar_42817 = (cppVar_42802 == 144);
	if (cppVar_42817) {
	cppVar_42801 = P1;
	} else {
	cppVar_42820 = PC + 1;
	cppVar_42820 = (cppVar_42820 & cppMask_un_16_);
	cppVar_42821 = ROM.rd(cppVar_42820);
	cppVar_42822 = (cppVar_42821 >> 7) & cppMask_un_1_;
	cppVar_42823 = (cppVar_42822 == 1);
	if (cppVar_42823) {
	cppVar_42824 = PC + 1;
	cppVar_42824 = (cppVar_42824 & cppMask_un_16_);
	cppVar_42825 = ROM.rd(cppVar_42824);
	cppVar_42826 = (cppVar_42825 >> 3) & cppMask_un_5_;
	cppVar_42827 = (cppVar_42826 << 3) | 0;
	cppVar_42827 = (cppVar_42827 & cppMask_un_8_);
	cppVar_42819 = cppVar_42827;
	} else {
	cppVar_42828 = PC + 1;
	cppVar_42828 = (cppVar_42828 & cppMask_un_16_);
	cppVar_42829 = ROM.rd(cppVar_42828);
	cppVar_42830 = (cppVar_42829 >> 3) & cppMask_un_5_;
	cppVar_42831 = (cppVar_42830 & cppMask_un_5_);
	cppVar_42832 = cppVar_42831 + 32;
	cppVar_42832 = (cppVar_42832 & cppMask_un_8_);
	cppVar_42819 = cppVar_42832;
	}
	cppVar_42834 = (cppVar_42819 == 152);
	if (cppVar_42834) {
	cppVar_42818 = SCON;
	} else {
	cppVar_42837 = PC + 1;
	cppVar_42837 = (cppVar_42837 & cppMask_un_16_);
	cppVar_42838 = ROM.rd(cppVar_42837);
	cppVar_42839 = (cppVar_42838 >> 7) & cppMask_un_1_;
	cppVar_42840 = (cppVar_42839 == 1);
	if (cppVar_42840) {
	cppVar_42841 = PC + 1;
	cppVar_42841 = (cppVar_42841 & cppMask_un_16_);
	cppVar_42842 = ROM.rd(cppVar_42841);
	cppVar_42843 = (cppVar_42842 >> 3) & cppMask_un_5_;
	cppVar_42844 = (cppVar_42843 << 3) | 0;
	cppVar_42844 = (cppVar_42844 & cppMask_un_8_);
	cppVar_42836 = cppVar_42844;
	} else {
	cppVar_42845 = PC + 1;
	cppVar_42845 = (cppVar_42845 & cppMask_un_16_);
	cppVar_42846 = ROM.rd(cppVar_42845);
	cppVar_42847 = (cppVar_42846 >> 3) & cppMask_un_5_;
	cppVar_42848 = (cppVar_42847 & cppMask_un_5_);
	cppVar_42849 = cppVar_42848 + 32;
	cppVar_42849 = (cppVar_42849 & cppMask_un_8_);
	cppVar_42836 = cppVar_42849;
	}
	cppVar_42851 = (cppVar_42836 == 153);
	if (cppVar_42851) {
	cppVar_42835 = SBUF;
	} else {
	cppVar_42854 = PC + 1;
	cppVar_42854 = (cppVar_42854 & cppMask_un_16_);
	cppVar_42855 = ROM.rd(cppVar_42854);
	cppVar_42856 = (cppVar_42855 >> 7) & cppMask_un_1_;
	cppVar_42857 = (cppVar_42856 == 1);
	if (cppVar_42857) {
	cppVar_42858 = PC + 1;
	cppVar_42858 = (cppVar_42858 & cppMask_un_16_);
	cppVar_42859 = ROM.rd(cppVar_42858);
	cppVar_42860 = (cppVar_42859 >> 3) & cppMask_un_5_;
	cppVar_42861 = (cppVar_42860 << 3) | 0;
	cppVar_42861 = (cppVar_42861 & cppMask_un_8_);
	cppVar_42853 = cppVar_42861;
	} else {
	cppVar_42862 = PC + 1;
	cppVar_42862 = (cppVar_42862 & cppMask_un_16_);
	cppVar_42863 = ROM.rd(cppVar_42862);
	cppVar_42864 = (cppVar_42863 >> 3) & cppMask_un_5_;
	cppVar_42865 = (cppVar_42864 & cppMask_un_5_);
	cppVar_42866 = cppVar_42865 + 32;
	cppVar_42866 = (cppVar_42866 & cppMask_un_8_);
	cppVar_42853 = cppVar_42866;
	}
	cppVar_42868 = (cppVar_42853 == 160);
	if (cppVar_42868) {
	cppVar_42852 = P2;
	} else {
	cppVar_42871 = PC + 1;
	cppVar_42871 = (cppVar_42871 & cppMask_un_16_);
	cppVar_42872 = ROM.rd(cppVar_42871);
	cppVar_42873 = (cppVar_42872 >> 7) & cppMask_un_1_;
	cppVar_42874 = (cppVar_42873 == 1);
	if (cppVar_42874) {
	cppVar_42875 = PC + 1;
	cppVar_42875 = (cppVar_42875 & cppMask_un_16_);
	cppVar_42876 = ROM.rd(cppVar_42875);
	cppVar_42877 = (cppVar_42876 >> 3) & cppMask_un_5_;
	cppVar_42878 = (cppVar_42877 << 3) | 0;
	cppVar_42878 = (cppVar_42878 & cppMask_un_8_);
	cppVar_42870 = cppVar_42878;
	} else {
	cppVar_42879 = PC + 1;
	cppVar_42879 = (cppVar_42879 & cppMask_un_16_);
	cppVar_42880 = ROM.rd(cppVar_42879);
	cppVar_42881 = (cppVar_42880 >> 3) & cppMask_un_5_;
	cppVar_42882 = (cppVar_42881 & cppMask_un_5_);
	cppVar_42883 = cppVar_42882 + 32;
	cppVar_42883 = (cppVar_42883 & cppMask_un_8_);
	cppVar_42870 = cppVar_42883;
	}
	cppVar_42885 = (cppVar_42870 == 168);
	if (cppVar_42885) {
	cppVar_42869 = IE;
	} else {
	cppVar_42888 = PC + 1;
	cppVar_42888 = (cppVar_42888 & cppMask_un_16_);
	cppVar_42889 = ROM.rd(cppVar_42888);
	cppVar_42890 = (cppVar_42889 >> 7) & cppMask_un_1_;
	cppVar_42891 = (cppVar_42890 == 1);
	if (cppVar_42891) {
	cppVar_42892 = PC + 1;
	cppVar_42892 = (cppVar_42892 & cppMask_un_16_);
	cppVar_42893 = ROM.rd(cppVar_42892);
	cppVar_42894 = (cppVar_42893 >> 3) & cppMask_un_5_;
	cppVar_42895 = (cppVar_42894 << 3) | 0;
	cppVar_42895 = (cppVar_42895 & cppMask_un_8_);
	cppVar_42887 = cppVar_42895;
	} else {
	cppVar_42896 = PC + 1;
	cppVar_42896 = (cppVar_42896 & cppMask_un_16_);
	cppVar_42897 = ROM.rd(cppVar_42896);
	cppVar_42898 = (cppVar_42897 >> 3) & cppMask_un_5_;
	cppVar_42899 = (cppVar_42898 & cppMask_un_5_);
	cppVar_42900 = cppVar_42899 + 32;
	cppVar_42900 = (cppVar_42900 & cppMask_un_8_);
	cppVar_42887 = cppVar_42900;
	}
	cppVar_42902 = (cppVar_42887 == 176);
	if (cppVar_42902) {
	cppVar_42886 = P3;
	} else {
	cppVar_42905 = PC + 1;
	cppVar_42905 = (cppVar_42905 & cppMask_un_16_);
	cppVar_42906 = ROM.rd(cppVar_42905);
	cppVar_42907 = (cppVar_42906 >> 7) & cppMask_un_1_;
	cppVar_42908 = (cppVar_42907 == 1);
	if (cppVar_42908) {
	cppVar_42909 = PC + 1;
	cppVar_42909 = (cppVar_42909 & cppMask_un_16_);
	cppVar_42910 = ROM.rd(cppVar_42909);
	cppVar_42911 = (cppVar_42910 >> 3) & cppMask_un_5_;
	cppVar_42912 = (cppVar_42911 << 3) | 0;
	cppVar_42912 = (cppVar_42912 & cppMask_un_8_);
	cppVar_42904 = cppVar_42912;
	} else {
	cppVar_42913 = PC + 1;
	cppVar_42913 = (cppVar_42913 & cppMask_un_16_);
	cppVar_42914 = ROM.rd(cppVar_42913);
	cppVar_42915 = (cppVar_42914 >> 3) & cppMask_un_5_;
	cppVar_42916 = (cppVar_42915 & cppMask_un_5_);
	cppVar_42917 = cppVar_42916 + 32;
	cppVar_42917 = (cppVar_42917 & cppMask_un_8_);
	cppVar_42904 = cppVar_42917;
	}
	cppVar_42919 = (cppVar_42904 == 184);
	if (cppVar_42919) {
	cppVar_42903 = IP;
	} else {
	cppVar_42922 = PC + 1;
	cppVar_42922 = (cppVar_42922 & cppMask_un_16_);
	cppVar_42923 = ROM.rd(cppVar_42922);
	cppVar_42924 = (cppVar_42923 >> 7) & cppMask_un_1_;
	cppVar_42925 = (cppVar_42924 == 1);
	if (cppVar_42925) {
	cppVar_42926 = PC + 1;
	cppVar_42926 = (cppVar_42926 & cppMask_un_16_);
	cppVar_42927 = ROM.rd(cppVar_42926);
	cppVar_42928 = (cppVar_42927 >> 3) & cppMask_un_5_;
	cppVar_42929 = (cppVar_42928 << 3) | 0;
	cppVar_42929 = (cppVar_42929 & cppMask_un_8_);
	cppVar_42921 = cppVar_42929;
	} else {
	cppVar_42930 = PC + 1;
	cppVar_42930 = (cppVar_42930 & cppMask_un_16_);
	cppVar_42931 = ROM.rd(cppVar_42930);
	cppVar_42932 = (cppVar_42931 >> 3) & cppMask_un_5_;
	cppVar_42933 = (cppVar_42932 & cppMask_un_5_);
	cppVar_42934 = cppVar_42933 + 32;
	cppVar_42934 = (cppVar_42934 & cppMask_un_8_);
	cppVar_42921 = cppVar_42934;
	}
	cppVar_42936 = (cppVar_42921 == 208);
	if (cppVar_42936) {
	cppVar_42920 = PSW;
	} else {
	cppVar_42939 = PC + 1;
	cppVar_42939 = (cppVar_42939 & cppMask_un_16_);
	cppVar_42940 = ROM.rd(cppVar_42939);
	cppVar_42941 = (cppVar_42940 >> 7) & cppMask_un_1_;
	cppVar_42942 = (cppVar_42941 == 1);
	if (cppVar_42942) {
	cppVar_42943 = PC + 1;
	cppVar_42943 = (cppVar_42943 & cppMask_un_16_);
	cppVar_42944 = ROM.rd(cppVar_42943);
	cppVar_42945 = (cppVar_42944 >> 3) & cppMask_un_5_;
	cppVar_42946 = (cppVar_42945 << 3) | 0;
	cppVar_42946 = (cppVar_42946 & cppMask_un_8_);
	cppVar_42938 = cppVar_42946;
	} else {
	cppVar_42947 = PC + 1;
	cppVar_42947 = (cppVar_42947 & cppMask_un_16_);
	cppVar_42948 = ROM.rd(cppVar_42947);
	cppVar_42949 = (cppVar_42948 >> 3) & cppMask_un_5_;
	cppVar_42950 = (cppVar_42949 & cppMask_un_5_);
	cppVar_42951 = cppVar_42950 + 32;
	cppVar_42951 = (cppVar_42951 & cppMask_un_8_);
	cppVar_42938 = cppVar_42951;
	}
	cppVar_42953 = (cppVar_42938 == 224);
	if (cppVar_42953) {
	cppVar_42937 = ACC;
	} else {
	cppVar_42956 = PC + 1;
	cppVar_42956 = (cppVar_42956 & cppMask_un_16_);
	cppVar_42957 = ROM.rd(cppVar_42956);
	cppVar_42958 = (cppVar_42957 >> 7) & cppMask_un_1_;
	cppVar_42959 = (cppVar_42958 == 1);
	if (cppVar_42959) {
	cppVar_42960 = PC + 1;
	cppVar_42960 = (cppVar_42960 & cppMask_un_16_);
	cppVar_42961 = ROM.rd(cppVar_42960);
	cppVar_42962 = (cppVar_42961 >> 3) & cppMask_un_5_;
	cppVar_42963 = (cppVar_42962 << 3) | 0;
	cppVar_42963 = (cppVar_42963 & cppMask_un_8_);
	cppVar_42955 = cppVar_42963;
	} else {
	cppVar_42964 = PC + 1;
	cppVar_42964 = (cppVar_42964 & cppMask_un_16_);
	cppVar_42965 = ROM.rd(cppVar_42964);
	cppVar_42966 = (cppVar_42965 >> 3) & cppMask_un_5_;
	cppVar_42967 = (cppVar_42966 & cppMask_un_5_);
	cppVar_42968 = cppVar_42967 + 32;
	cppVar_42968 = (cppVar_42968 & cppMask_un_8_);
	cppVar_42955 = cppVar_42968;
	}
	cppVar_42970 = (cppVar_42955 == 240);
	if (cppVar_42970) {
	cppVar_42954 = B;
	} else {
	cppVar_42954 = 0;
	}
	cppVar_42937 = cppVar_42954;
	}
	cppVar_42920 = cppVar_42937;
	}
	cppVar_42903 = cppVar_42920;
	}
	cppVar_42886 = cppVar_42903;
	}
	cppVar_42869 = cppVar_42886;
	}
	cppVar_42852 = cppVar_42869;
	}
	cppVar_42835 = cppVar_42852;
	}
	cppVar_42818 = cppVar_42835;
	}
	cppVar_42801 = cppVar_42818;
	}
	cppVar_42784 = cppVar_42801;
	}
	cppVar_42767 = cppVar_42784;
	}
	cppVar_42750 = cppVar_42767;
	}
	cppVar_42733 = cppVar_42750;
	}
	cppVar_42716 = cppVar_42733;
	}
	cppVar_42699 = cppVar_42716;
	}
	cppVar_42682 = cppVar_42699;
	}
	cppVar_42665 = cppVar_42682;
	}
	cppVar_42648 = cppVar_42665;
	}
	cppVar_42631 = cppVar_42648;
	}
	cppVar_42614 = cppVar_42631;
	}
	cppVar_42577 = cppVar_42614;
	}
	cppVar_42972 = PC + 1;
	cppVar_42972 = (cppVar_42972 & cppMask_un_16_);
	cppVar_42973 = ROM.rd(cppVar_42972);
	cppVar_42974 = (cppVar_42973 >> 0) & cppMask_un_3_;
	cppVar_42975 = (cppVar_42577 >> static_cast<unsigned>(cppVar_42974)) & 0x1;
	cppVar_42977 = (cppVar_42975 == 0);
	if (cppVar_42977) {
	cppVar_42979 = PC + 3;
	cppVar_42979 = (cppVar_42979 & cppMask_un_16_);
	cppVar_42981 = PC + 2;
	cppVar_42981 = (cppVar_42981 & cppMask_un_16_);
	cppVar_42982 = ROM.rd(cppVar_42981);
	cppVar_42983 = ((cppVar_42982 & cppMask_bit_8_) ? (cppVar_42982 | cppMask_sign_8_) : cppVar_42982);
	cppVar_42984 = cppVar_42979 + cppVar_42983;
	cppVar_42984 = (cppVar_42984 & cppMask_un_16_);
	cppVar_42576 = cppVar_42984;
	} else {
	cppVar_42986 = PC + 3;
	cppVar_42986 = (cppVar_42986 & cppMask_un_16_);
	cppVar_42576 = cppVar_42986;
	}
	cppVar_42572 = cppVar_42576;
	} else {
	cppVar_42988 = ROM.rd(PC);
	cppVar_42990 = (cppVar_42988 == 50);
	cppVar_42991 = ROM.rd(PC);
	cppVar_42993 = (cppVar_42991 == 34);
	cppVar_42994 = cppVar_42990 || cppVar_42993;
	if (cppVar_42994) {
	cppVar_42995 = IRAM.rd(SP);
	cppVar_42997 = SP - 1;
	cppVar_42997 = (cppVar_42997 & cppMask_un_8_);
	cppVar_42998 = IRAM.rd(cppVar_42997);
	cppVar_42999 = (cppVar_42995 << 8) | cppVar_42998;
	cppVar_42999 = (cppVar_42999 & cppMask_un_16_);
	cppVar_42987 = cppVar_42999;
	} else {
	cppVar_43001 = ROM.rd(PC);
	cppVar_43003 = (cppVar_43001 == 49);
	cppVar_43004 = ROM.rd(PC);
	cppVar_43006 = (cppVar_43004 == 33);
	cppVar_43007 = cppVar_43003 || cppVar_43006;
	if (cppVar_43007) {
	cppVar_43009 = PC + 2;
	cppVar_43009 = (cppVar_43009 & cppMask_un_16_);
	cppVar_43010 = (cppVar_43009 >> 11) & cppMask_un_5_;
	cppVar_43012 = (cppVar_43010 << 3) | 1;
	cppVar_43012 = (cppVar_43012 & cppMask_un_8_);
	cppVar_43014 = PC + 1;
	cppVar_43014 = (cppVar_43014 & cppMask_un_16_);
	cppVar_43015 = ROM.rd(cppVar_43014);
	cppVar_43016 = (cppVar_43012 << 8) | cppVar_43015;
	cppVar_43016 = (cppVar_43016 & cppMask_un_16_);
	cppVar_43000 = cppVar_43016;
	} else {
	cppVar_43018 = ROM.rd(PC);
	cppVar_43020 = (cppVar_43018 == 32);
	cppVar_43021 = ROM.rd(PC);
	cppVar_43023 = (cppVar_43021 == 16);
	cppVar_43024 = cppVar_43020 || cppVar_43023;
	if (cppVar_43024) {
	cppVar_43029 = PC + 1;
	cppVar_43029 = (cppVar_43029 & cppMask_un_16_);
	cppVar_43030 = ROM.rd(cppVar_43029);
	cppVar_43031 = (cppVar_43030 >> 7) & cppMask_un_1_;
	cppVar_43033 = (cppVar_43031 == 1);
	if (cppVar_43033) {
	cppVar_43034 = PC + 1;
	cppVar_43034 = (cppVar_43034 & cppMask_un_16_);
	cppVar_43035 = ROM.rd(cppVar_43034);
	cppVar_43036 = (cppVar_43035 >> 3) & cppMask_un_5_;
	cppVar_43038 = (cppVar_43036 << 3) | 0;
	cppVar_43038 = (cppVar_43038 & cppMask_un_8_);
	cppVar_43027 = cppVar_43038;
	} else {
	cppVar_43039 = PC + 1;
	cppVar_43039 = (cppVar_43039 & cppMask_un_16_);
	cppVar_43040 = ROM.rd(cppVar_43039);
	cppVar_43041 = (cppVar_43040 >> 3) & cppMask_un_5_;
	cppVar_43042 = (cppVar_43041 & cppMask_un_5_);
	cppVar_43044 = cppVar_43042 + 32;
	cppVar_43044 = (cppVar_43044 & cppMask_un_8_);
	cppVar_43027 = cppVar_43044;
	}
	cppVar_43045 = (cppVar_43027 >> 7) & cppMask_un_1_;
	cppVar_43047 = (cppVar_43045 == 0);
	if (cppVar_43047) {
	cppVar_43049 = PC + 1;
	cppVar_43049 = (cppVar_43049 & cppMask_un_16_);
	cppVar_43050 = ROM.rd(cppVar_43049);
	cppVar_43051 = (cppVar_43050 >> 7) & cppMask_un_1_;
	cppVar_43052 = (cppVar_43051 == 1);
	if (cppVar_43052) {
	cppVar_43053 = PC + 1;
	cppVar_43053 = (cppVar_43053 & cppMask_un_16_);
	cppVar_43054 = ROM.rd(cppVar_43053);
	cppVar_43055 = (cppVar_43054 >> 3) & cppMask_un_5_;
	cppVar_43056 = (cppVar_43055 << 3) | 0;
	cppVar_43056 = (cppVar_43056 & cppMask_un_8_);
	cppVar_43048 = cppVar_43056;
	} else {
	cppVar_43057 = PC + 1;
	cppVar_43057 = (cppVar_43057 & cppMask_un_16_);
	cppVar_43058 = ROM.rd(cppVar_43057);
	cppVar_43059 = (cppVar_43058 >> 3) & cppMask_un_5_;
	cppVar_43060 = (cppVar_43059 & cppMask_un_5_);
	cppVar_43061 = cppVar_43060 + 32;
	cppVar_43061 = (cppVar_43061 & cppMask_un_8_);
	cppVar_43048 = cppVar_43061;
	}
	cppVar_43062 = IRAM.rd(cppVar_43048);
	cppVar_43026 = cppVar_43062;
	} else {
	cppVar_43065 = PC + 1;
	cppVar_43065 = (cppVar_43065 & cppMask_un_16_);
	cppVar_43066 = ROM.rd(cppVar_43065);
	cppVar_43067 = (cppVar_43066 >> 7) & cppMask_un_1_;
	cppVar_43068 = (cppVar_43067 == 1);
	if (cppVar_43068) {
	cppVar_43069 = PC + 1;
	cppVar_43069 = (cppVar_43069 & cppMask_un_16_);
	cppVar_43070 = ROM.rd(cppVar_43069);
	cppVar_43071 = (cppVar_43070 >> 3) & cppMask_un_5_;
	cppVar_43072 = (cppVar_43071 << 3) | 0;
	cppVar_43072 = (cppVar_43072 & cppMask_un_8_);
	cppVar_43064 = cppVar_43072;
	} else {
	cppVar_43073 = PC + 1;
	cppVar_43073 = (cppVar_43073 & cppMask_un_16_);
	cppVar_43074 = ROM.rd(cppVar_43073);
	cppVar_43075 = (cppVar_43074 >> 3) & cppMask_un_5_;
	cppVar_43076 = (cppVar_43075 & cppMask_un_5_);
	cppVar_43077 = cppVar_43076 + 32;
	cppVar_43077 = (cppVar_43077 & cppMask_un_8_);
	cppVar_43064 = cppVar_43077;
	}
	cppVar_43079 = (cppVar_43064 == 128);
	if (cppVar_43079) {
	cppVar_43063 = P0;
	} else {
	cppVar_43082 = PC + 1;
	cppVar_43082 = (cppVar_43082 & cppMask_un_16_);
	cppVar_43083 = ROM.rd(cppVar_43082);
	cppVar_43084 = (cppVar_43083 >> 7) & cppMask_un_1_;
	cppVar_43085 = (cppVar_43084 == 1);
	if (cppVar_43085) {
	cppVar_43086 = PC + 1;
	cppVar_43086 = (cppVar_43086 & cppMask_un_16_);
	cppVar_43087 = ROM.rd(cppVar_43086);
	cppVar_43088 = (cppVar_43087 >> 3) & cppMask_un_5_;
	cppVar_43089 = (cppVar_43088 << 3) | 0;
	cppVar_43089 = (cppVar_43089 & cppMask_un_8_);
	cppVar_43081 = cppVar_43089;
	} else {
	cppVar_43090 = PC + 1;
	cppVar_43090 = (cppVar_43090 & cppMask_un_16_);
	cppVar_43091 = ROM.rd(cppVar_43090);
	cppVar_43092 = (cppVar_43091 >> 3) & cppMask_un_5_;
	cppVar_43093 = (cppVar_43092 & cppMask_un_5_);
	cppVar_43094 = cppVar_43093 + 32;
	cppVar_43094 = (cppVar_43094 & cppMask_un_8_);
	cppVar_43081 = cppVar_43094;
	}
	cppVar_43096 = (cppVar_43081 == 129);
	if (cppVar_43096) {
	cppVar_43080 = SP;
	} else {
	cppVar_43099 = PC + 1;
	cppVar_43099 = (cppVar_43099 & cppMask_un_16_);
	cppVar_43100 = ROM.rd(cppVar_43099);
	cppVar_43101 = (cppVar_43100 >> 7) & cppMask_un_1_;
	cppVar_43102 = (cppVar_43101 == 1);
	if (cppVar_43102) {
	cppVar_43103 = PC + 1;
	cppVar_43103 = (cppVar_43103 & cppMask_un_16_);
	cppVar_43104 = ROM.rd(cppVar_43103);
	cppVar_43105 = (cppVar_43104 >> 3) & cppMask_un_5_;
	cppVar_43106 = (cppVar_43105 << 3) | 0;
	cppVar_43106 = (cppVar_43106 & cppMask_un_8_);
	cppVar_43098 = cppVar_43106;
	} else {
	cppVar_43107 = PC + 1;
	cppVar_43107 = (cppVar_43107 & cppMask_un_16_);
	cppVar_43108 = ROM.rd(cppVar_43107);
	cppVar_43109 = (cppVar_43108 >> 3) & cppMask_un_5_;
	cppVar_43110 = (cppVar_43109 & cppMask_un_5_);
	cppVar_43111 = cppVar_43110 + 32;
	cppVar_43111 = (cppVar_43111 & cppMask_un_8_);
	cppVar_43098 = cppVar_43111;
	}
	cppVar_43113 = (cppVar_43098 == 130);
	if (cppVar_43113) {
	cppVar_43097 = DPL;
	} else {
	cppVar_43116 = PC + 1;
	cppVar_43116 = (cppVar_43116 & cppMask_un_16_);
	cppVar_43117 = ROM.rd(cppVar_43116);
	cppVar_43118 = (cppVar_43117 >> 7) & cppMask_un_1_;
	cppVar_43119 = (cppVar_43118 == 1);
	if (cppVar_43119) {
	cppVar_43120 = PC + 1;
	cppVar_43120 = (cppVar_43120 & cppMask_un_16_);
	cppVar_43121 = ROM.rd(cppVar_43120);
	cppVar_43122 = (cppVar_43121 >> 3) & cppMask_un_5_;
	cppVar_43123 = (cppVar_43122 << 3) | 0;
	cppVar_43123 = (cppVar_43123 & cppMask_un_8_);
	cppVar_43115 = cppVar_43123;
	} else {
	cppVar_43124 = PC + 1;
	cppVar_43124 = (cppVar_43124 & cppMask_un_16_);
	cppVar_43125 = ROM.rd(cppVar_43124);
	cppVar_43126 = (cppVar_43125 >> 3) & cppMask_un_5_;
	cppVar_43127 = (cppVar_43126 & cppMask_un_5_);
	cppVar_43128 = cppVar_43127 + 32;
	cppVar_43128 = (cppVar_43128 & cppMask_un_8_);
	cppVar_43115 = cppVar_43128;
	}
	cppVar_43130 = (cppVar_43115 == 131);
	if (cppVar_43130) {
	cppVar_43114 = DPH;
	} else {
	cppVar_43133 = PC + 1;
	cppVar_43133 = (cppVar_43133 & cppMask_un_16_);
	cppVar_43134 = ROM.rd(cppVar_43133);
	cppVar_43135 = (cppVar_43134 >> 7) & cppMask_un_1_;
	cppVar_43136 = (cppVar_43135 == 1);
	if (cppVar_43136) {
	cppVar_43137 = PC + 1;
	cppVar_43137 = (cppVar_43137 & cppMask_un_16_);
	cppVar_43138 = ROM.rd(cppVar_43137);
	cppVar_43139 = (cppVar_43138 >> 3) & cppMask_un_5_;
	cppVar_43140 = (cppVar_43139 << 3) | 0;
	cppVar_43140 = (cppVar_43140 & cppMask_un_8_);
	cppVar_43132 = cppVar_43140;
	} else {
	cppVar_43141 = PC + 1;
	cppVar_43141 = (cppVar_43141 & cppMask_un_16_);
	cppVar_43142 = ROM.rd(cppVar_43141);
	cppVar_43143 = (cppVar_43142 >> 3) & cppMask_un_5_;
	cppVar_43144 = (cppVar_43143 & cppMask_un_5_);
	cppVar_43145 = cppVar_43144 + 32;
	cppVar_43145 = (cppVar_43145 & cppMask_un_8_);
	cppVar_43132 = cppVar_43145;
	}
	cppVar_43147 = (cppVar_43132 == 135);
	if (cppVar_43147) {
	cppVar_43131 = PCON;
	} else {
	cppVar_43150 = PC + 1;
	cppVar_43150 = (cppVar_43150 & cppMask_un_16_);
	cppVar_43151 = ROM.rd(cppVar_43150);
	cppVar_43152 = (cppVar_43151 >> 7) & cppMask_un_1_;
	cppVar_43153 = (cppVar_43152 == 1);
	if (cppVar_43153) {
	cppVar_43154 = PC + 1;
	cppVar_43154 = (cppVar_43154 & cppMask_un_16_);
	cppVar_43155 = ROM.rd(cppVar_43154);
	cppVar_43156 = (cppVar_43155 >> 3) & cppMask_un_5_;
	cppVar_43157 = (cppVar_43156 << 3) | 0;
	cppVar_43157 = (cppVar_43157 & cppMask_un_8_);
	cppVar_43149 = cppVar_43157;
	} else {
	cppVar_43158 = PC + 1;
	cppVar_43158 = (cppVar_43158 & cppMask_un_16_);
	cppVar_43159 = ROM.rd(cppVar_43158);
	cppVar_43160 = (cppVar_43159 >> 3) & cppMask_un_5_;
	cppVar_43161 = (cppVar_43160 & cppMask_un_5_);
	cppVar_43162 = cppVar_43161 + 32;
	cppVar_43162 = (cppVar_43162 & cppMask_un_8_);
	cppVar_43149 = cppVar_43162;
	}
	cppVar_43164 = (cppVar_43149 == 136);
	if (cppVar_43164) {
	cppVar_43148 = TCON;
	} else {
	cppVar_43167 = PC + 1;
	cppVar_43167 = (cppVar_43167 & cppMask_un_16_);
	cppVar_43168 = ROM.rd(cppVar_43167);
	cppVar_43169 = (cppVar_43168 >> 7) & cppMask_un_1_;
	cppVar_43170 = (cppVar_43169 == 1);
	if (cppVar_43170) {
	cppVar_43171 = PC + 1;
	cppVar_43171 = (cppVar_43171 & cppMask_un_16_);
	cppVar_43172 = ROM.rd(cppVar_43171);
	cppVar_43173 = (cppVar_43172 >> 3) & cppMask_un_5_;
	cppVar_43174 = (cppVar_43173 << 3) | 0;
	cppVar_43174 = (cppVar_43174 & cppMask_un_8_);
	cppVar_43166 = cppVar_43174;
	} else {
	cppVar_43175 = PC + 1;
	cppVar_43175 = (cppVar_43175 & cppMask_un_16_);
	cppVar_43176 = ROM.rd(cppVar_43175);
	cppVar_43177 = (cppVar_43176 >> 3) & cppMask_un_5_;
	cppVar_43178 = (cppVar_43177 & cppMask_un_5_);
	cppVar_43179 = cppVar_43178 + 32;
	cppVar_43179 = (cppVar_43179 & cppMask_un_8_);
	cppVar_43166 = cppVar_43179;
	}
	cppVar_43181 = (cppVar_43166 == 137);
	if (cppVar_43181) {
	cppVar_43165 = TMOD;
	} else {
	cppVar_43184 = PC + 1;
	cppVar_43184 = (cppVar_43184 & cppMask_un_16_);
	cppVar_43185 = ROM.rd(cppVar_43184);
	cppVar_43186 = (cppVar_43185 >> 7) & cppMask_un_1_;
	cppVar_43187 = (cppVar_43186 == 1);
	if (cppVar_43187) {
	cppVar_43188 = PC + 1;
	cppVar_43188 = (cppVar_43188 & cppMask_un_16_);
	cppVar_43189 = ROM.rd(cppVar_43188);
	cppVar_43190 = (cppVar_43189 >> 3) & cppMask_un_5_;
	cppVar_43191 = (cppVar_43190 << 3) | 0;
	cppVar_43191 = (cppVar_43191 & cppMask_un_8_);
	cppVar_43183 = cppVar_43191;
	} else {
	cppVar_43192 = PC + 1;
	cppVar_43192 = (cppVar_43192 & cppMask_un_16_);
	cppVar_43193 = ROM.rd(cppVar_43192);
	cppVar_43194 = (cppVar_43193 >> 3) & cppMask_un_5_;
	cppVar_43195 = (cppVar_43194 & cppMask_un_5_);
	cppVar_43196 = cppVar_43195 + 32;
	cppVar_43196 = (cppVar_43196 & cppMask_un_8_);
	cppVar_43183 = cppVar_43196;
	}
	cppVar_43198 = (cppVar_43183 == 138);
	if (cppVar_43198) {
	cppVar_43182 = TL0;
	} else {
	cppVar_43201 = PC + 1;
	cppVar_43201 = (cppVar_43201 & cppMask_un_16_);
	cppVar_43202 = ROM.rd(cppVar_43201);
	cppVar_43203 = (cppVar_43202 >> 7) & cppMask_un_1_;
	cppVar_43204 = (cppVar_43203 == 1);
	if (cppVar_43204) {
	cppVar_43205 = PC + 1;
	cppVar_43205 = (cppVar_43205 & cppMask_un_16_);
	cppVar_43206 = ROM.rd(cppVar_43205);
	cppVar_43207 = (cppVar_43206 >> 3) & cppMask_un_5_;
	cppVar_43208 = (cppVar_43207 << 3) | 0;
	cppVar_43208 = (cppVar_43208 & cppMask_un_8_);
	cppVar_43200 = cppVar_43208;
	} else {
	cppVar_43209 = PC + 1;
	cppVar_43209 = (cppVar_43209 & cppMask_un_16_);
	cppVar_43210 = ROM.rd(cppVar_43209);
	cppVar_43211 = (cppVar_43210 >> 3) & cppMask_un_5_;
	cppVar_43212 = (cppVar_43211 & cppMask_un_5_);
	cppVar_43213 = cppVar_43212 + 32;
	cppVar_43213 = (cppVar_43213 & cppMask_un_8_);
	cppVar_43200 = cppVar_43213;
	}
	cppVar_43215 = (cppVar_43200 == 140);
	if (cppVar_43215) {
	cppVar_43199 = TH0;
	} else {
	cppVar_43218 = PC + 1;
	cppVar_43218 = (cppVar_43218 & cppMask_un_16_);
	cppVar_43219 = ROM.rd(cppVar_43218);
	cppVar_43220 = (cppVar_43219 >> 7) & cppMask_un_1_;
	cppVar_43221 = (cppVar_43220 == 1);
	if (cppVar_43221) {
	cppVar_43222 = PC + 1;
	cppVar_43222 = (cppVar_43222 & cppMask_un_16_);
	cppVar_43223 = ROM.rd(cppVar_43222);
	cppVar_43224 = (cppVar_43223 >> 3) & cppMask_un_5_;
	cppVar_43225 = (cppVar_43224 << 3) | 0;
	cppVar_43225 = (cppVar_43225 & cppMask_un_8_);
	cppVar_43217 = cppVar_43225;
	} else {
	cppVar_43226 = PC + 1;
	cppVar_43226 = (cppVar_43226 & cppMask_un_16_);
	cppVar_43227 = ROM.rd(cppVar_43226);
	cppVar_43228 = (cppVar_43227 >> 3) & cppMask_un_5_;
	cppVar_43229 = (cppVar_43228 & cppMask_un_5_);
	cppVar_43230 = cppVar_43229 + 32;
	cppVar_43230 = (cppVar_43230 & cppMask_un_8_);
	cppVar_43217 = cppVar_43230;
	}
	cppVar_43232 = (cppVar_43217 == 139);
	if (cppVar_43232) {
	cppVar_43216 = TL1;
	} else {
	cppVar_43235 = PC + 1;
	cppVar_43235 = (cppVar_43235 & cppMask_un_16_);
	cppVar_43236 = ROM.rd(cppVar_43235);
	cppVar_43237 = (cppVar_43236 >> 7) & cppMask_un_1_;
	cppVar_43238 = (cppVar_43237 == 1);
	if (cppVar_43238) {
	cppVar_43239 = PC + 1;
	cppVar_43239 = (cppVar_43239 & cppMask_un_16_);
	cppVar_43240 = ROM.rd(cppVar_43239);
	cppVar_43241 = (cppVar_43240 >> 3) & cppMask_un_5_;
	cppVar_43242 = (cppVar_43241 << 3) | 0;
	cppVar_43242 = (cppVar_43242 & cppMask_un_8_);
	cppVar_43234 = cppVar_43242;
	} else {
	cppVar_43243 = PC + 1;
	cppVar_43243 = (cppVar_43243 & cppMask_un_16_);
	cppVar_43244 = ROM.rd(cppVar_43243);
	cppVar_43245 = (cppVar_43244 >> 3) & cppMask_un_5_;
	cppVar_43246 = (cppVar_43245 & cppMask_un_5_);
	cppVar_43247 = cppVar_43246 + 32;
	cppVar_43247 = (cppVar_43247 & cppMask_un_8_);
	cppVar_43234 = cppVar_43247;
	}
	cppVar_43249 = (cppVar_43234 == 141);
	if (cppVar_43249) {
	cppVar_43233 = TH1;
	} else {
	cppVar_43252 = PC + 1;
	cppVar_43252 = (cppVar_43252 & cppMask_un_16_);
	cppVar_43253 = ROM.rd(cppVar_43252);
	cppVar_43254 = (cppVar_43253 >> 7) & cppMask_un_1_;
	cppVar_43255 = (cppVar_43254 == 1);
	if (cppVar_43255) {
	cppVar_43256 = PC + 1;
	cppVar_43256 = (cppVar_43256 & cppMask_un_16_);
	cppVar_43257 = ROM.rd(cppVar_43256);
	cppVar_43258 = (cppVar_43257 >> 3) & cppMask_un_5_;
	cppVar_43259 = (cppVar_43258 << 3) | 0;
	cppVar_43259 = (cppVar_43259 & cppMask_un_8_);
	cppVar_43251 = cppVar_43259;
	} else {
	cppVar_43260 = PC + 1;
	cppVar_43260 = (cppVar_43260 & cppMask_un_16_);
	cppVar_43261 = ROM.rd(cppVar_43260);
	cppVar_43262 = (cppVar_43261 >> 3) & cppMask_un_5_;
	cppVar_43263 = (cppVar_43262 & cppMask_un_5_);
	cppVar_43264 = cppVar_43263 + 32;
	cppVar_43264 = (cppVar_43264 & cppMask_un_8_);
	cppVar_43251 = cppVar_43264;
	}
	cppVar_43266 = (cppVar_43251 == 144);
	if (cppVar_43266) {
	cppVar_43250 = P1;
	} else {
	cppVar_43269 = PC + 1;
	cppVar_43269 = (cppVar_43269 & cppMask_un_16_);
	cppVar_43270 = ROM.rd(cppVar_43269);
	cppVar_43271 = (cppVar_43270 >> 7) & cppMask_un_1_;
	cppVar_43272 = (cppVar_43271 == 1);
	if (cppVar_43272) {
	cppVar_43273 = PC + 1;
	cppVar_43273 = (cppVar_43273 & cppMask_un_16_);
	cppVar_43274 = ROM.rd(cppVar_43273);
	cppVar_43275 = (cppVar_43274 >> 3) & cppMask_un_5_;
	cppVar_43276 = (cppVar_43275 << 3) | 0;
	cppVar_43276 = (cppVar_43276 & cppMask_un_8_);
	cppVar_43268 = cppVar_43276;
	} else {
	cppVar_43277 = PC + 1;
	cppVar_43277 = (cppVar_43277 & cppMask_un_16_);
	cppVar_43278 = ROM.rd(cppVar_43277);
	cppVar_43279 = (cppVar_43278 >> 3) & cppMask_un_5_;
	cppVar_43280 = (cppVar_43279 & cppMask_un_5_);
	cppVar_43281 = cppVar_43280 + 32;
	cppVar_43281 = (cppVar_43281 & cppMask_un_8_);
	cppVar_43268 = cppVar_43281;
	}
	cppVar_43283 = (cppVar_43268 == 152);
	if (cppVar_43283) {
	cppVar_43267 = SCON;
	} else {
	cppVar_43286 = PC + 1;
	cppVar_43286 = (cppVar_43286 & cppMask_un_16_);
	cppVar_43287 = ROM.rd(cppVar_43286);
	cppVar_43288 = (cppVar_43287 >> 7) & cppMask_un_1_;
	cppVar_43289 = (cppVar_43288 == 1);
	if (cppVar_43289) {
	cppVar_43290 = PC + 1;
	cppVar_43290 = (cppVar_43290 & cppMask_un_16_);
	cppVar_43291 = ROM.rd(cppVar_43290);
	cppVar_43292 = (cppVar_43291 >> 3) & cppMask_un_5_;
	cppVar_43293 = (cppVar_43292 << 3) | 0;
	cppVar_43293 = (cppVar_43293 & cppMask_un_8_);
	cppVar_43285 = cppVar_43293;
	} else {
	cppVar_43294 = PC + 1;
	cppVar_43294 = (cppVar_43294 & cppMask_un_16_);
	cppVar_43295 = ROM.rd(cppVar_43294);
	cppVar_43296 = (cppVar_43295 >> 3) & cppMask_un_5_;
	cppVar_43297 = (cppVar_43296 & cppMask_un_5_);
	cppVar_43298 = cppVar_43297 + 32;
	cppVar_43298 = (cppVar_43298 & cppMask_un_8_);
	cppVar_43285 = cppVar_43298;
	}
	cppVar_43300 = (cppVar_43285 == 153);
	if (cppVar_43300) {
	cppVar_43284 = SBUF;
	} else {
	cppVar_43303 = PC + 1;
	cppVar_43303 = (cppVar_43303 & cppMask_un_16_);
	cppVar_43304 = ROM.rd(cppVar_43303);
	cppVar_43305 = (cppVar_43304 >> 7) & cppMask_un_1_;
	cppVar_43306 = (cppVar_43305 == 1);
	if (cppVar_43306) {
	cppVar_43307 = PC + 1;
	cppVar_43307 = (cppVar_43307 & cppMask_un_16_);
	cppVar_43308 = ROM.rd(cppVar_43307);
	cppVar_43309 = (cppVar_43308 >> 3) & cppMask_un_5_;
	cppVar_43310 = (cppVar_43309 << 3) | 0;
	cppVar_43310 = (cppVar_43310 & cppMask_un_8_);
	cppVar_43302 = cppVar_43310;
	} else {
	cppVar_43311 = PC + 1;
	cppVar_43311 = (cppVar_43311 & cppMask_un_16_);
	cppVar_43312 = ROM.rd(cppVar_43311);
	cppVar_43313 = (cppVar_43312 >> 3) & cppMask_un_5_;
	cppVar_43314 = (cppVar_43313 & cppMask_un_5_);
	cppVar_43315 = cppVar_43314 + 32;
	cppVar_43315 = (cppVar_43315 & cppMask_un_8_);
	cppVar_43302 = cppVar_43315;
	}
	cppVar_43317 = (cppVar_43302 == 160);
	if (cppVar_43317) {
	cppVar_43301 = P2;
	} else {
	cppVar_43320 = PC + 1;
	cppVar_43320 = (cppVar_43320 & cppMask_un_16_);
	cppVar_43321 = ROM.rd(cppVar_43320);
	cppVar_43322 = (cppVar_43321 >> 7) & cppMask_un_1_;
	cppVar_43323 = (cppVar_43322 == 1);
	if (cppVar_43323) {
	cppVar_43324 = PC + 1;
	cppVar_43324 = (cppVar_43324 & cppMask_un_16_);
	cppVar_43325 = ROM.rd(cppVar_43324);
	cppVar_43326 = (cppVar_43325 >> 3) & cppMask_un_5_;
	cppVar_43327 = (cppVar_43326 << 3) | 0;
	cppVar_43327 = (cppVar_43327 & cppMask_un_8_);
	cppVar_43319 = cppVar_43327;
	} else {
	cppVar_43328 = PC + 1;
	cppVar_43328 = (cppVar_43328 & cppMask_un_16_);
	cppVar_43329 = ROM.rd(cppVar_43328);
	cppVar_43330 = (cppVar_43329 >> 3) & cppMask_un_5_;
	cppVar_43331 = (cppVar_43330 & cppMask_un_5_);
	cppVar_43332 = cppVar_43331 + 32;
	cppVar_43332 = (cppVar_43332 & cppMask_un_8_);
	cppVar_43319 = cppVar_43332;
	}
	cppVar_43334 = (cppVar_43319 == 168);
	if (cppVar_43334) {
	cppVar_43318 = IE;
	} else {
	cppVar_43337 = PC + 1;
	cppVar_43337 = (cppVar_43337 & cppMask_un_16_);
	cppVar_43338 = ROM.rd(cppVar_43337);
	cppVar_43339 = (cppVar_43338 >> 7) & cppMask_un_1_;
	cppVar_43340 = (cppVar_43339 == 1);
	if (cppVar_43340) {
	cppVar_43341 = PC + 1;
	cppVar_43341 = (cppVar_43341 & cppMask_un_16_);
	cppVar_43342 = ROM.rd(cppVar_43341);
	cppVar_43343 = (cppVar_43342 >> 3) & cppMask_un_5_;
	cppVar_43344 = (cppVar_43343 << 3) | 0;
	cppVar_43344 = (cppVar_43344 & cppMask_un_8_);
	cppVar_43336 = cppVar_43344;
	} else {
	cppVar_43345 = PC + 1;
	cppVar_43345 = (cppVar_43345 & cppMask_un_16_);
	cppVar_43346 = ROM.rd(cppVar_43345);
	cppVar_43347 = (cppVar_43346 >> 3) & cppMask_un_5_;
	cppVar_43348 = (cppVar_43347 & cppMask_un_5_);
	cppVar_43349 = cppVar_43348 + 32;
	cppVar_43349 = (cppVar_43349 & cppMask_un_8_);
	cppVar_43336 = cppVar_43349;
	}
	cppVar_43351 = (cppVar_43336 == 176);
	if (cppVar_43351) {
	cppVar_43335 = P3;
	} else {
	cppVar_43354 = PC + 1;
	cppVar_43354 = (cppVar_43354 & cppMask_un_16_);
	cppVar_43355 = ROM.rd(cppVar_43354);
	cppVar_43356 = (cppVar_43355 >> 7) & cppMask_un_1_;
	cppVar_43357 = (cppVar_43356 == 1);
	if (cppVar_43357) {
	cppVar_43358 = PC + 1;
	cppVar_43358 = (cppVar_43358 & cppMask_un_16_);
	cppVar_43359 = ROM.rd(cppVar_43358);
	cppVar_43360 = (cppVar_43359 >> 3) & cppMask_un_5_;
	cppVar_43361 = (cppVar_43360 << 3) | 0;
	cppVar_43361 = (cppVar_43361 & cppMask_un_8_);
	cppVar_43353 = cppVar_43361;
	} else {
	cppVar_43362 = PC + 1;
	cppVar_43362 = (cppVar_43362 & cppMask_un_16_);
	cppVar_43363 = ROM.rd(cppVar_43362);
	cppVar_43364 = (cppVar_43363 >> 3) & cppMask_un_5_;
	cppVar_43365 = (cppVar_43364 & cppMask_un_5_);
	cppVar_43366 = cppVar_43365 + 32;
	cppVar_43366 = (cppVar_43366 & cppMask_un_8_);
	cppVar_43353 = cppVar_43366;
	}
	cppVar_43368 = (cppVar_43353 == 184);
	if (cppVar_43368) {
	cppVar_43352 = IP;
	} else {
	cppVar_43371 = PC + 1;
	cppVar_43371 = (cppVar_43371 & cppMask_un_16_);
	cppVar_43372 = ROM.rd(cppVar_43371);
	cppVar_43373 = (cppVar_43372 >> 7) & cppMask_un_1_;
	cppVar_43374 = (cppVar_43373 == 1);
	if (cppVar_43374) {
	cppVar_43375 = PC + 1;
	cppVar_43375 = (cppVar_43375 & cppMask_un_16_);
	cppVar_43376 = ROM.rd(cppVar_43375);
	cppVar_43377 = (cppVar_43376 >> 3) & cppMask_un_5_;
	cppVar_43378 = (cppVar_43377 << 3) | 0;
	cppVar_43378 = (cppVar_43378 & cppMask_un_8_);
	cppVar_43370 = cppVar_43378;
	} else {
	cppVar_43379 = PC + 1;
	cppVar_43379 = (cppVar_43379 & cppMask_un_16_);
	cppVar_43380 = ROM.rd(cppVar_43379);
	cppVar_43381 = (cppVar_43380 >> 3) & cppMask_un_5_;
	cppVar_43382 = (cppVar_43381 & cppMask_un_5_);
	cppVar_43383 = cppVar_43382 + 32;
	cppVar_43383 = (cppVar_43383 & cppMask_un_8_);
	cppVar_43370 = cppVar_43383;
	}
	cppVar_43385 = (cppVar_43370 == 208);
	if (cppVar_43385) {
	cppVar_43369 = PSW;
	} else {
	cppVar_43388 = PC + 1;
	cppVar_43388 = (cppVar_43388 & cppMask_un_16_);
	cppVar_43389 = ROM.rd(cppVar_43388);
	cppVar_43390 = (cppVar_43389 >> 7) & cppMask_un_1_;
	cppVar_43391 = (cppVar_43390 == 1);
	if (cppVar_43391) {
	cppVar_43392 = PC + 1;
	cppVar_43392 = (cppVar_43392 & cppMask_un_16_);
	cppVar_43393 = ROM.rd(cppVar_43392);
	cppVar_43394 = (cppVar_43393 >> 3) & cppMask_un_5_;
	cppVar_43395 = (cppVar_43394 << 3) | 0;
	cppVar_43395 = (cppVar_43395 & cppMask_un_8_);
	cppVar_43387 = cppVar_43395;
	} else {
	cppVar_43396 = PC + 1;
	cppVar_43396 = (cppVar_43396 & cppMask_un_16_);
	cppVar_43397 = ROM.rd(cppVar_43396);
	cppVar_43398 = (cppVar_43397 >> 3) & cppMask_un_5_;
	cppVar_43399 = (cppVar_43398 & cppMask_un_5_);
	cppVar_43400 = cppVar_43399 + 32;
	cppVar_43400 = (cppVar_43400 & cppMask_un_8_);
	cppVar_43387 = cppVar_43400;
	}
	cppVar_43402 = (cppVar_43387 == 224);
	if (cppVar_43402) {
	cppVar_43386 = ACC;
	} else {
	cppVar_43405 = PC + 1;
	cppVar_43405 = (cppVar_43405 & cppMask_un_16_);
	cppVar_43406 = ROM.rd(cppVar_43405);
	cppVar_43407 = (cppVar_43406 >> 7) & cppMask_un_1_;
	cppVar_43408 = (cppVar_43407 == 1);
	if (cppVar_43408) {
	cppVar_43409 = PC + 1;
	cppVar_43409 = (cppVar_43409 & cppMask_un_16_);
	cppVar_43410 = ROM.rd(cppVar_43409);
	cppVar_43411 = (cppVar_43410 >> 3) & cppMask_un_5_;
	cppVar_43412 = (cppVar_43411 << 3) | 0;
	cppVar_43412 = (cppVar_43412 & cppMask_un_8_);
	cppVar_43404 = cppVar_43412;
	} else {
	cppVar_43413 = PC + 1;
	cppVar_43413 = (cppVar_43413 & cppMask_un_16_);
	cppVar_43414 = ROM.rd(cppVar_43413);
	cppVar_43415 = (cppVar_43414 >> 3) & cppMask_un_5_;
	cppVar_43416 = (cppVar_43415 & cppMask_un_5_);
	cppVar_43417 = cppVar_43416 + 32;
	cppVar_43417 = (cppVar_43417 & cppMask_un_8_);
	cppVar_43404 = cppVar_43417;
	}
	cppVar_43419 = (cppVar_43404 == 240);
	if (cppVar_43419) {
	cppVar_43403 = B;
	} else {
	cppVar_43403 = 0;
	}
	cppVar_43386 = cppVar_43403;
	}
	cppVar_43369 = cppVar_43386;
	}
	cppVar_43352 = cppVar_43369;
	}
	cppVar_43335 = cppVar_43352;
	}
	cppVar_43318 = cppVar_43335;
	}
	cppVar_43301 = cppVar_43318;
	}
	cppVar_43284 = cppVar_43301;
	}
	cppVar_43267 = cppVar_43284;
	}
	cppVar_43250 = cppVar_43267;
	}
	cppVar_43233 = cppVar_43250;
	}
	cppVar_43216 = cppVar_43233;
	}
	cppVar_43199 = cppVar_43216;
	}
	cppVar_43182 = cppVar_43199;
	}
	cppVar_43165 = cppVar_43182;
	}
	cppVar_43148 = cppVar_43165;
	}
	cppVar_43131 = cppVar_43148;
	}
	cppVar_43114 = cppVar_43131;
	}
	cppVar_43097 = cppVar_43114;
	}
	cppVar_43080 = cppVar_43097;
	}
	cppVar_43063 = cppVar_43080;
	}
	cppVar_43026 = cppVar_43063;
	}
	cppVar_43421 = PC + 1;
	cppVar_43421 = (cppVar_43421 & cppMask_un_16_);
	cppVar_43422 = ROM.rd(cppVar_43421);
	cppVar_43423 = (cppVar_43422 >> 0) & cppMask_un_3_;
	cppVar_43424 = (cppVar_43026 >> static_cast<unsigned>(cppVar_43423)) & 0x1;
	cppVar_43426 = (cppVar_43424 == 1);
	if (cppVar_43426) {
	cppVar_43428 = PC + 3;
	cppVar_43428 = (cppVar_43428 & cppMask_un_16_);
	cppVar_43430 = PC + 2;
	cppVar_43430 = (cppVar_43430 & cppMask_un_16_);
	cppVar_43431 = ROM.rd(cppVar_43430);
	cppVar_43432 = ((cppVar_43431 & cppMask_bit_8_) ? (cppVar_43431 | cppMask_sign_8_) : cppVar_43431);
	cppVar_43433 = cppVar_43428 + cppVar_43432;
	cppVar_43433 = (cppVar_43433 & cppMask_un_16_);
	cppVar_43025 = cppVar_43433;
	} else {
	cppVar_43435 = PC + 3;
	cppVar_43435 = (cppVar_43435 & cppMask_un_16_);
	cppVar_43025 = cppVar_43435;
	}
	cppVar_43017 = cppVar_43025;
	} else {
	cppVar_43437 = ROM.rd(PC);
	cppVar_43439 = (cppVar_43437 == 245);
	cppVar_43440 = ROM.rd(PC);
	cppVar_43442 = (cppVar_43440 == 229);
	cppVar_43443 = ROM.rd(PC);
	cppVar_43445 = (cppVar_43443 == 210);
	cppVar_43446 = ROM.rd(PC);
	cppVar_43448 = (cppVar_43446 == 208);
	cppVar_43449 = ROM.rd(PC);
	cppVar_43451 = (cppVar_43449 == 197);
	cppVar_43452 = ROM.rd(PC);
	cppVar_43454 = (cppVar_43452 == 194);
	cppVar_43455 = ROM.rd(PC);
	cppVar_43457 = (cppVar_43455 == 192);
	cppVar_43458 = ROM.rd(PC);
	cppVar_43460 = (cppVar_43458 == 178);
	cppVar_43461 = ROM.rd(PC);
	cppVar_43463 = (cppVar_43461 == 176);
	cppVar_43464 = ROM.rd(PC);
	cppVar_43466 = (cppVar_43464 == 175);
	cppVar_43467 = ROM.rd(PC);
	cppVar_43469 = (cppVar_43467 == 174);
	cppVar_43470 = ROM.rd(PC);
	cppVar_43472 = (cppVar_43470 == 173);
	cppVar_43473 = ROM.rd(PC);
	cppVar_43475 = (cppVar_43473 == 172);
	cppVar_43476 = ROM.rd(PC);
	cppVar_43478 = (cppVar_43476 == 171);
	cppVar_43479 = ROM.rd(PC);
	cppVar_43481 = (cppVar_43479 == 170);
	cppVar_43482 = ROM.rd(PC);
	cppVar_43484 = (cppVar_43482 == 169);
	cppVar_43485 = ROM.rd(PC);
	cppVar_43487 = (cppVar_43485 == 168);
	cppVar_43488 = ROM.rd(PC);
	cppVar_43490 = (cppVar_43488 == 167);
	cppVar_43491 = ROM.rd(PC);
	cppVar_43493 = (cppVar_43491 == 166);
	cppVar_43494 = ROM.rd(PC);
	cppVar_43496 = (cppVar_43494 == 162);
	cppVar_43497 = ROM.rd(PC);
	cppVar_43499 = (cppVar_43497 == 160);
	cppVar_43500 = ROM.rd(PC);
	cppVar_43502 = (cppVar_43500 == 149);
	cppVar_43503 = ROM.rd(PC);
	cppVar_43505 = (cppVar_43503 == 148);
	cppVar_43506 = ROM.rd(PC);
	cppVar_43508 = (cppVar_43506 == 146);
	cppVar_43509 = ROM.rd(PC);
	cppVar_43511 = (cppVar_43509 == 143);
	cppVar_43512 = ROM.rd(PC);
	cppVar_43514 = (cppVar_43512 == 142);
	cppVar_43515 = ROM.rd(PC);
	cppVar_43517 = (cppVar_43515 == 141);
	cppVar_43518 = ROM.rd(PC);
	cppVar_43520 = (cppVar_43518 == 140);
	cppVar_43521 = ROM.rd(PC);
	cppVar_43523 = (cppVar_43521 == 139);
	cppVar_43524 = ROM.rd(PC);
	cppVar_43526 = (cppVar_43524 == 138);
	cppVar_43527 = ROM.rd(PC);
	cppVar_43529 = (cppVar_43527 == 137);
	cppVar_43530 = ROM.rd(PC);
	cppVar_43532 = (cppVar_43530 == 136);
	cppVar_43533 = ROM.rd(PC);
	cppVar_43535 = (cppVar_43533 == 135);
	cppVar_43536 = ROM.rd(PC);
	cppVar_43538 = (cppVar_43536 == 134);
	cppVar_43539 = ROM.rd(PC);
	cppVar_43541 = (cppVar_43539 == 130);
	cppVar_43542 = ROM.rd(PC);
	cppVar_43544 = (cppVar_43542 == 127);
	cppVar_43545 = ROM.rd(PC);
	cppVar_43547 = (cppVar_43545 == 126);
	cppVar_43548 = ROM.rd(PC);
	cppVar_43550 = (cppVar_43548 == 125);
	cppVar_43551 = ROM.rd(PC);
	cppVar_43553 = (cppVar_43551 == 124);
	cppVar_43554 = ROM.rd(PC);
	cppVar_43556 = (cppVar_43554 == 123);
	cppVar_43557 = ROM.rd(PC);
	cppVar_43559 = (cppVar_43557 == 122);
	cppVar_43560 = ROM.rd(PC);
	cppVar_43562 = (cppVar_43560 == 121);
	cppVar_43563 = ROM.rd(PC);
	cppVar_43565 = (cppVar_43563 == 120);
	cppVar_43566 = ROM.rd(PC);
	cppVar_43568 = (cppVar_43566 == 119);
	cppVar_43569 = ROM.rd(PC);
	cppVar_43571 = (cppVar_43569 == 118);
	cppVar_43572 = ROM.rd(PC);
	cppVar_43574 = (cppVar_43572 == 116);
	cppVar_43575 = ROM.rd(PC);
	cppVar_43577 = (cppVar_43575 == 114);
	cppVar_43578 = ROM.rd(PC);
	cppVar_43580 = (cppVar_43578 == 101);
	cppVar_43581 = ROM.rd(PC);
	cppVar_43583 = (cppVar_43581 == 100);
	cppVar_43584 = ROM.rd(PC);
	cppVar_43586 = (cppVar_43584 == 98);
	cppVar_43587 = ROM.rd(PC);
	cppVar_43589 = (cppVar_43587 == 85);
	cppVar_43590 = ROM.rd(PC);
	cppVar_43592 = (cppVar_43590 == 84);
	cppVar_43593 = ROM.rd(PC);
	cppVar_43595 = (cppVar_43593 == 82);
	cppVar_43596 = ROM.rd(PC);
	cppVar_43598 = (cppVar_43596 == 69);
	cppVar_43599 = ROM.rd(PC);
	cppVar_43601 = (cppVar_43599 == 68);
	cppVar_43602 = ROM.rd(PC);
	cppVar_43604 = (cppVar_43602 == 66);
	cppVar_43605 = ROM.rd(PC);
	cppVar_43607 = (cppVar_43605 == 53);
	cppVar_43608 = ROM.rd(PC);
	cppVar_43610 = (cppVar_43608 == 52);
	cppVar_43611 = ROM.rd(PC);
	cppVar_43613 = (cppVar_43611 == 37);
	cppVar_43614 = ROM.rd(PC);
	cppVar_43616 = (cppVar_43614 == 36);
	cppVar_43617 = ROM.rd(PC);
	cppVar_43619 = (cppVar_43617 == 21);
	cppVar_43620 = ROM.rd(PC);
	cppVar_43622 = (cppVar_43620 == 5);
	cppVar_43623 = cppVar_43619 || cppVar_43622;
	cppVar_43624 = cppVar_43616 || cppVar_43623;
	cppVar_43625 = cppVar_43613 || cppVar_43624;
	cppVar_43626 = cppVar_43610 || cppVar_43625;
	cppVar_43627 = cppVar_43607 || cppVar_43626;
	cppVar_43628 = cppVar_43604 || cppVar_43627;
	cppVar_43629 = cppVar_43601 || cppVar_43628;
	cppVar_43630 = cppVar_43598 || cppVar_43629;
	cppVar_43631 = cppVar_43595 || cppVar_43630;
	cppVar_43632 = cppVar_43592 || cppVar_43631;
	cppVar_43633 = cppVar_43589 || cppVar_43632;
	cppVar_43634 = cppVar_43586 || cppVar_43633;
	cppVar_43635 = cppVar_43583 || cppVar_43634;
	cppVar_43636 = cppVar_43580 || cppVar_43635;
	cppVar_43637 = cppVar_43577 || cppVar_43636;
	cppVar_43638 = cppVar_43574 || cppVar_43637;
	cppVar_43639 = cppVar_43571 || cppVar_43638;
	cppVar_43640 = cppVar_43568 || cppVar_43639;
	cppVar_43641 = cppVar_43565 || cppVar_43640;
	cppVar_43642 = cppVar_43562 || cppVar_43641;
	cppVar_43643 = cppVar_43559 || cppVar_43642;
	cppVar_43644 = cppVar_43556 || cppVar_43643;
	cppVar_43645 = cppVar_43553 || cppVar_43644;
	cppVar_43646 = cppVar_43550 || cppVar_43645;
	cppVar_43647 = cppVar_43547 || cppVar_43646;
	cppVar_43648 = cppVar_43544 || cppVar_43647;
	cppVar_43649 = cppVar_43541 || cppVar_43648;
	cppVar_43650 = cppVar_43538 || cppVar_43649;
	cppVar_43651 = cppVar_43535 || cppVar_43650;
	cppVar_43652 = cppVar_43532 || cppVar_43651;
	cppVar_43653 = cppVar_43529 || cppVar_43652;
	cppVar_43654 = cppVar_43526 || cppVar_43653;
	cppVar_43655 = cppVar_43523 || cppVar_43654;
	cppVar_43656 = cppVar_43520 || cppVar_43655;
	cppVar_43657 = cppVar_43517 || cppVar_43656;
	cppVar_43658 = cppVar_43514 || cppVar_43657;
	cppVar_43659 = cppVar_43511 || cppVar_43658;
	cppVar_43660 = cppVar_43508 || cppVar_43659;
	cppVar_43661 = cppVar_43505 || cppVar_43660;
	cppVar_43662 = cppVar_43502 || cppVar_43661;
	cppVar_43663 = cppVar_43499 || cppVar_43662;
	cppVar_43664 = cppVar_43496 || cppVar_43663;
	cppVar_43665 = cppVar_43493 || cppVar_43664;
	cppVar_43666 = cppVar_43490 || cppVar_43665;
	cppVar_43667 = cppVar_43487 || cppVar_43666;
	cppVar_43668 = cppVar_43484 || cppVar_43667;
	cppVar_43669 = cppVar_43481 || cppVar_43668;
	cppVar_43670 = cppVar_43478 || cppVar_43669;
	cppVar_43671 = cppVar_43475 || cppVar_43670;
	cppVar_43672 = cppVar_43472 || cppVar_43671;
	cppVar_43673 = cppVar_43469 || cppVar_43672;
	cppVar_43674 = cppVar_43466 || cppVar_43673;
	cppVar_43675 = cppVar_43463 || cppVar_43674;
	cppVar_43676 = cppVar_43460 || cppVar_43675;
	cppVar_43677 = cppVar_43457 || cppVar_43676;
	cppVar_43678 = cppVar_43454 || cppVar_43677;
	cppVar_43679 = cppVar_43451 || cppVar_43678;
	cppVar_43680 = cppVar_43448 || cppVar_43679;
	cppVar_43681 = cppVar_43445 || cppVar_43680;
	cppVar_43682 = cppVar_43442 || cppVar_43681;
	cppVar_43683 = cppVar_43439 || cppVar_43682;
	if (cppVar_43683) {
	cppVar_43685 = PC + 2;
	cppVar_43685 = (cppVar_43685 & cppMask_un_16_);
	cppVar_43436 = cppVar_43685;
	} else {
	cppVar_43687 = ROM.rd(PC);
	cppVar_43689 = (cppVar_43687 == 18);
	cppVar_43690 = ROM.rd(PC);
	cppVar_43692 = (cppVar_43690 == 2);
	cppVar_43693 = cppVar_43689 || cppVar_43692;
	if (cppVar_43693) {
	cppVar_43695 = PC + 1;
	cppVar_43695 = (cppVar_43695 & cppMask_un_16_);
	cppVar_43696 = ROM.rd(cppVar_43695);
	cppVar_43698 = PC + 2;
	cppVar_43698 = (cppVar_43698 & cppMask_un_16_);
	cppVar_43699 = ROM.rd(cppVar_43698);
	cppVar_43700 = (cppVar_43696 << 8) | cppVar_43699;
	cppVar_43700 = (cppVar_43700 & cppMask_un_16_);
	cppVar_43686 = cppVar_43700;
	} else {
	cppVar_43702 = ROM.rd(PC);
	cppVar_43704 = (cppVar_43702 == 17);
	cppVar_43705 = ROM.rd(PC);
	cppVar_43707 = (cppVar_43705 == 1);
	cppVar_43708 = cppVar_43704 || cppVar_43707;
	if (cppVar_43708) {
	cppVar_43710 = PC + 2;
	cppVar_43710 = (cppVar_43710 & cppMask_un_16_);
	cppVar_43711 = (cppVar_43710 >> 11) & cppMask_un_5_;
	cppVar_43713 = (cppVar_43711 << 3) | 0;
	cppVar_43713 = (cppVar_43713 & cppMask_un_8_);
	cppVar_43715 = PC + 1;
	cppVar_43715 = (cppVar_43715 & cppMask_un_16_);
	cppVar_43716 = ROM.rd(cppVar_43715);
	cppVar_43717 = (cppVar_43713 << 8) | cppVar_43716;
	cppVar_43717 = (cppVar_43717 & cppMask_un_16_);
	cppVar_43701 = cppVar_43717;
	} else {
	cppVar_43719 = ROM.rd(PC);
	cppVar_43721 = (cppVar_43719 == 255);
	cppVar_43722 = ROM.rd(PC);
	cppVar_43724 = (cppVar_43722 == 254);
	cppVar_43725 = ROM.rd(PC);
	cppVar_43727 = (cppVar_43725 == 253);
	cppVar_43728 = ROM.rd(PC);
	cppVar_43730 = (cppVar_43728 == 252);
	cppVar_43731 = ROM.rd(PC);
	cppVar_43733 = (cppVar_43731 == 251);
	cppVar_43734 = ROM.rd(PC);
	cppVar_43736 = (cppVar_43734 == 250);
	cppVar_43737 = ROM.rd(PC);
	cppVar_43739 = (cppVar_43737 == 249);
	cppVar_43740 = ROM.rd(PC);
	cppVar_43742 = (cppVar_43740 == 248);
	cppVar_43743 = ROM.rd(PC);
	cppVar_43745 = (cppVar_43743 == 247);
	cppVar_43746 = ROM.rd(PC);
	cppVar_43748 = (cppVar_43746 == 246);
	cppVar_43749 = ROM.rd(PC);
	cppVar_43751 = (cppVar_43749 == 244);
	cppVar_43752 = ROM.rd(PC);
	cppVar_43754 = (cppVar_43752 == 243);
	cppVar_43755 = ROM.rd(PC);
	cppVar_43757 = (cppVar_43755 == 242);
	cppVar_43758 = ROM.rd(PC);
	cppVar_43760 = (cppVar_43758 == 240);
	cppVar_43761 = ROM.rd(PC);
	cppVar_43763 = (cppVar_43761 == 239);
	cppVar_43764 = ROM.rd(PC);
	cppVar_43766 = (cppVar_43764 == 238);
	cppVar_43767 = ROM.rd(PC);
	cppVar_43769 = (cppVar_43767 == 237);
	cppVar_43770 = ROM.rd(PC);
	cppVar_43772 = (cppVar_43770 == 236);
	cppVar_43773 = ROM.rd(PC);
	cppVar_43775 = (cppVar_43773 == 235);
	cppVar_43776 = ROM.rd(PC);
	cppVar_43778 = (cppVar_43776 == 234);
	cppVar_43779 = ROM.rd(PC);
	cppVar_43781 = (cppVar_43779 == 233);
	cppVar_43782 = ROM.rd(PC);
	cppVar_43784 = (cppVar_43782 == 232);
	cppVar_43785 = ROM.rd(PC);
	cppVar_43787 = (cppVar_43785 == 231);
	cppVar_43788 = ROM.rd(PC);
	cppVar_43790 = (cppVar_43788 == 230);
	cppVar_43791 = ROM.rd(PC);
	cppVar_43793 = (cppVar_43791 == 228);
	cppVar_43794 = ROM.rd(PC);
	cppVar_43796 = (cppVar_43794 == 227);
	cppVar_43797 = ROM.rd(PC);
	cppVar_43799 = (cppVar_43797 == 226);
	cppVar_43800 = ROM.rd(PC);
	cppVar_43802 = (cppVar_43800 == 224);
	cppVar_43803 = ROM.rd(PC);
	cppVar_43805 = (cppVar_43803 == 215);
	cppVar_43806 = ROM.rd(PC);
	cppVar_43808 = (cppVar_43806 == 214);
	cppVar_43809 = ROM.rd(PC);
	cppVar_43811 = (cppVar_43809 == 212);
	cppVar_43812 = ROM.rd(PC);
	cppVar_43814 = (cppVar_43812 == 211);
	cppVar_43815 = ROM.rd(PC);
	cppVar_43817 = (cppVar_43815 == 207);
	cppVar_43818 = ROM.rd(PC);
	cppVar_43820 = (cppVar_43818 == 206);
	cppVar_43821 = ROM.rd(PC);
	cppVar_43823 = (cppVar_43821 == 205);
	cppVar_43824 = ROM.rd(PC);
	cppVar_43826 = (cppVar_43824 == 204);
	cppVar_43827 = ROM.rd(PC);
	cppVar_43829 = (cppVar_43827 == 203);
	cppVar_43830 = ROM.rd(PC);
	cppVar_43832 = (cppVar_43830 == 202);
	cppVar_43833 = ROM.rd(PC);
	cppVar_43835 = (cppVar_43833 == 201);
	cppVar_43836 = ROM.rd(PC);
	cppVar_43838 = (cppVar_43836 == 200);
	cppVar_43839 = ROM.rd(PC);
	cppVar_43841 = (cppVar_43839 == 199);
	cppVar_43842 = ROM.rd(PC);
	cppVar_43844 = (cppVar_43842 == 198);
	cppVar_43845 = ROM.rd(PC);
	cppVar_43847 = (cppVar_43845 == 196);
	cppVar_43848 = ROM.rd(PC);
	cppVar_43850 = (cppVar_43848 == 195);
	cppVar_43851 = ROM.rd(PC);
	cppVar_43853 = (cppVar_43851 == 179);
	cppVar_43854 = ROM.rd(PC);
	cppVar_43856 = (cppVar_43854 == 165);
	cppVar_43857 = ROM.rd(PC);
	cppVar_43859 = (cppVar_43857 == 164);
	cppVar_43860 = ROM.rd(PC);
	cppVar_43862 = (cppVar_43860 == 163);
	cppVar_43863 = ROM.rd(PC);
	cppVar_43865 = (cppVar_43863 == 159);
	cppVar_43866 = ROM.rd(PC);
	cppVar_43868 = (cppVar_43866 == 158);
	cppVar_43869 = ROM.rd(PC);
	cppVar_43871 = (cppVar_43869 == 157);
	cppVar_43872 = ROM.rd(PC);
	cppVar_43874 = (cppVar_43872 == 156);
	cppVar_43875 = ROM.rd(PC);
	cppVar_43877 = (cppVar_43875 == 155);
	cppVar_43878 = ROM.rd(PC);
	cppVar_43880 = (cppVar_43878 == 154);
	cppVar_43881 = ROM.rd(PC);
	cppVar_43883 = (cppVar_43881 == 153);
	cppVar_43884 = ROM.rd(PC);
	cppVar_43886 = (cppVar_43884 == 152);
	cppVar_43887 = ROM.rd(PC);
	cppVar_43889 = (cppVar_43887 == 151);
	cppVar_43890 = ROM.rd(PC);
	cppVar_43892 = (cppVar_43890 == 150);
	cppVar_43893 = ROM.rd(PC);
	cppVar_43895 = (cppVar_43893 == 147);
	cppVar_43896 = ROM.rd(PC);
	cppVar_43898 = (cppVar_43896 == 132);
	cppVar_43899 = ROM.rd(PC);
	cppVar_43901 = (cppVar_43899 == 131);
	cppVar_43902 = ROM.rd(PC);
	cppVar_43904 = (cppVar_43902 == 111);
	cppVar_43905 = ROM.rd(PC);
	cppVar_43907 = (cppVar_43905 == 110);
	cppVar_43908 = ROM.rd(PC);
	cppVar_43910 = (cppVar_43908 == 109);
	cppVar_43911 = ROM.rd(PC);
	cppVar_43913 = (cppVar_43911 == 108);
	cppVar_43914 = ROM.rd(PC);
	cppVar_43916 = (cppVar_43914 == 107);
	cppVar_43917 = ROM.rd(PC);
	cppVar_43919 = (cppVar_43917 == 106);
	cppVar_43920 = ROM.rd(PC);
	cppVar_43922 = (cppVar_43920 == 105);
	cppVar_43923 = ROM.rd(PC);
	cppVar_43925 = (cppVar_43923 == 104);
	cppVar_43926 = ROM.rd(PC);
	cppVar_43928 = (cppVar_43926 == 103);
	cppVar_43929 = ROM.rd(PC);
	cppVar_43931 = (cppVar_43929 == 102);
	cppVar_43932 = ROM.rd(PC);
	cppVar_43934 = (cppVar_43932 == 95);
	cppVar_43935 = ROM.rd(PC);
	cppVar_43937 = (cppVar_43935 == 94);
	cppVar_43938 = ROM.rd(PC);
	cppVar_43940 = (cppVar_43938 == 93);
	cppVar_43941 = ROM.rd(PC);
	cppVar_43943 = (cppVar_43941 == 92);
	cppVar_43944 = ROM.rd(PC);
	cppVar_43946 = (cppVar_43944 == 91);
	cppVar_43947 = ROM.rd(PC);
	cppVar_43949 = (cppVar_43947 == 90);
	cppVar_43950 = ROM.rd(PC);
	cppVar_43952 = (cppVar_43950 == 89);
	cppVar_43953 = ROM.rd(PC);
	cppVar_43955 = (cppVar_43953 == 88);
	cppVar_43956 = ROM.rd(PC);
	cppVar_43958 = (cppVar_43956 == 87);
	cppVar_43959 = ROM.rd(PC);
	cppVar_43961 = (cppVar_43959 == 86);
	cppVar_43962 = ROM.rd(PC);
	cppVar_43964 = (cppVar_43962 == 79);
	cppVar_43965 = ROM.rd(PC);
	cppVar_43967 = (cppVar_43965 == 78);
	cppVar_43968 = ROM.rd(PC);
	cppVar_43970 = (cppVar_43968 == 77);
	cppVar_43971 = ROM.rd(PC);
	cppVar_43973 = (cppVar_43971 == 76);
	cppVar_43974 = ROM.rd(PC);
	cppVar_43976 = (cppVar_43974 == 75);
	cppVar_43977 = ROM.rd(PC);
	cppVar_43979 = (cppVar_43977 == 74);
	cppVar_43980 = ROM.rd(PC);
	cppVar_43982 = (cppVar_43980 == 73);
	cppVar_43983 = ROM.rd(PC);
	cppVar_43985 = (cppVar_43983 == 72);
	cppVar_43986 = ROM.rd(PC);
	cppVar_43988 = (cppVar_43986 == 71);
	cppVar_43989 = ROM.rd(PC);
	cppVar_43991 = (cppVar_43989 == 70);
	cppVar_43992 = ROM.rd(PC);
	cppVar_43994 = (cppVar_43992 == 63);
	cppVar_43995 = ROM.rd(PC);
	cppVar_43997 = (cppVar_43995 == 62);
	cppVar_43998 = ROM.rd(PC);
	cppVar_44000 = (cppVar_43998 == 61);
	cppVar_44001 = ROM.rd(PC);
	cppVar_44003 = (cppVar_44001 == 60);
	cppVar_44004 = ROM.rd(PC);
	cppVar_44006 = (cppVar_44004 == 59);
	cppVar_44007 = ROM.rd(PC);
	cppVar_44009 = (cppVar_44007 == 58);
	cppVar_44010 = ROM.rd(PC);
	cppVar_44012 = (cppVar_44010 == 57);
	cppVar_44013 = ROM.rd(PC);
	cppVar_44015 = (cppVar_44013 == 56);
	cppVar_44016 = ROM.rd(PC);
	cppVar_44018 = (cppVar_44016 == 55);
	cppVar_44019 = ROM.rd(PC);
	cppVar_44021 = (cppVar_44019 == 54);
	cppVar_44022 = ROM.rd(PC);
	cppVar_44024 = (cppVar_44022 == 51);
	cppVar_44025 = ROM.rd(PC);
	cppVar_44027 = (cppVar_44025 == 47);
	cppVar_44028 = ROM.rd(PC);
	cppVar_44030 = (cppVar_44028 == 46);
	cppVar_44031 = ROM.rd(PC);
	cppVar_44033 = (cppVar_44031 == 45);
	cppVar_44034 = ROM.rd(PC);
	cppVar_44036 = (cppVar_44034 == 44);
	cppVar_44037 = ROM.rd(PC);
	cppVar_44039 = (cppVar_44037 == 43);
	cppVar_44040 = ROM.rd(PC);
	cppVar_44042 = (cppVar_44040 == 42);
	cppVar_44043 = ROM.rd(PC);
	cppVar_44045 = (cppVar_44043 == 41);
	cppVar_44046 = ROM.rd(PC);
	cppVar_44048 = (cppVar_44046 == 40);
	cppVar_44049 = ROM.rd(PC);
	cppVar_44051 = (cppVar_44049 == 39);
	cppVar_44052 = ROM.rd(PC);
	cppVar_44054 = (cppVar_44052 == 38);
	cppVar_44055 = ROM.rd(PC);
	cppVar_44057 = (cppVar_44055 == 35);
	cppVar_44058 = ROM.rd(PC);
	cppVar_44060 = (cppVar_44058 == 31);
	cppVar_44061 = ROM.rd(PC);
	cppVar_44063 = (cppVar_44061 == 30);
	cppVar_44064 = ROM.rd(PC);
	cppVar_44066 = (cppVar_44064 == 29);
	cppVar_44067 = ROM.rd(PC);
	cppVar_44069 = (cppVar_44067 == 28);
	cppVar_44070 = ROM.rd(PC);
	cppVar_44072 = (cppVar_44070 == 27);
	cppVar_44073 = ROM.rd(PC);
	cppVar_44075 = (cppVar_44073 == 26);
	cppVar_44076 = ROM.rd(PC);
	cppVar_44078 = (cppVar_44076 == 25);
	cppVar_44079 = ROM.rd(PC);
	cppVar_44081 = (cppVar_44079 == 24);
	cppVar_44082 = ROM.rd(PC);
	cppVar_44084 = (cppVar_44082 == 23);
	cppVar_44085 = ROM.rd(PC);
	cppVar_44087 = (cppVar_44085 == 22);
	cppVar_44088 = ROM.rd(PC);
	cppVar_44090 = (cppVar_44088 == 20);
	cppVar_44091 = ROM.rd(PC);
	cppVar_44093 = (cppVar_44091 == 19);
	cppVar_44094 = ROM.rd(PC);
	cppVar_44096 = (cppVar_44094 == 15);
	cppVar_44097 = ROM.rd(PC);
	cppVar_44099 = (cppVar_44097 == 14);
	cppVar_44100 = ROM.rd(PC);
	cppVar_44102 = (cppVar_44100 == 13);
	cppVar_44103 = ROM.rd(PC);
	cppVar_44105 = (cppVar_44103 == 12);
	cppVar_44106 = ROM.rd(PC);
	cppVar_44108 = (cppVar_44106 == 11);
	cppVar_44109 = ROM.rd(PC);
	cppVar_44111 = (cppVar_44109 == 10);
	cppVar_44112 = ROM.rd(PC);
	cppVar_44114 = (cppVar_44112 == 9);
	cppVar_44115 = ROM.rd(PC);
	cppVar_44117 = (cppVar_44115 == 8);
	cppVar_44118 = ROM.rd(PC);
	cppVar_44120 = (cppVar_44118 == 7);
	cppVar_44121 = ROM.rd(PC);
	cppVar_44123 = (cppVar_44121 == 6);
	cppVar_44124 = ROM.rd(PC);
	cppVar_44126 = (cppVar_44124 == 4);
	cppVar_44127 = ROM.rd(PC);
	cppVar_44129 = (cppVar_44127 == 3);
	cppVar_44130 = ROM.rd(PC);
	cppVar_44132 = (cppVar_44130 == 0);
	cppVar_44133 = cppVar_44129 || cppVar_44132;
	cppVar_44134 = cppVar_44126 || cppVar_44133;
	cppVar_44135 = cppVar_44123 || cppVar_44134;
	cppVar_44136 = cppVar_44120 || cppVar_44135;
	cppVar_44137 = cppVar_44117 || cppVar_44136;
	cppVar_44138 = cppVar_44114 || cppVar_44137;
	cppVar_44139 = cppVar_44111 || cppVar_44138;
	cppVar_44140 = cppVar_44108 || cppVar_44139;
	cppVar_44141 = cppVar_44105 || cppVar_44140;
	cppVar_44142 = cppVar_44102 || cppVar_44141;
	cppVar_44143 = cppVar_44099 || cppVar_44142;
	cppVar_44144 = cppVar_44096 || cppVar_44143;
	cppVar_44145 = cppVar_44093 || cppVar_44144;
	cppVar_44146 = cppVar_44090 || cppVar_44145;
	cppVar_44147 = cppVar_44087 || cppVar_44146;
	cppVar_44148 = cppVar_44084 || cppVar_44147;
	cppVar_44149 = cppVar_44081 || cppVar_44148;
	cppVar_44150 = cppVar_44078 || cppVar_44149;
	cppVar_44151 = cppVar_44075 || cppVar_44150;
	cppVar_44152 = cppVar_44072 || cppVar_44151;
	cppVar_44153 = cppVar_44069 || cppVar_44152;
	cppVar_44154 = cppVar_44066 || cppVar_44153;
	cppVar_44155 = cppVar_44063 || cppVar_44154;
	cppVar_44156 = cppVar_44060 || cppVar_44155;
	cppVar_44157 = cppVar_44057 || cppVar_44156;
	cppVar_44158 = cppVar_44054 || cppVar_44157;
	cppVar_44159 = cppVar_44051 || cppVar_44158;
	cppVar_44160 = cppVar_44048 || cppVar_44159;
	cppVar_44161 = cppVar_44045 || cppVar_44160;
	cppVar_44162 = cppVar_44042 || cppVar_44161;
	cppVar_44163 = cppVar_44039 || cppVar_44162;
	cppVar_44164 = cppVar_44036 || cppVar_44163;
	cppVar_44165 = cppVar_44033 || cppVar_44164;
	cppVar_44166 = cppVar_44030 || cppVar_44165;
	cppVar_44167 = cppVar_44027 || cppVar_44166;
	cppVar_44168 = cppVar_44024 || cppVar_44167;
	cppVar_44169 = cppVar_44021 || cppVar_44168;
	cppVar_44170 = cppVar_44018 || cppVar_44169;
	cppVar_44171 = cppVar_44015 || cppVar_44170;
	cppVar_44172 = cppVar_44012 || cppVar_44171;
	cppVar_44173 = cppVar_44009 || cppVar_44172;
	cppVar_44174 = cppVar_44006 || cppVar_44173;
	cppVar_44175 = cppVar_44003 || cppVar_44174;
	cppVar_44176 = cppVar_44000 || cppVar_44175;
	cppVar_44177 = cppVar_43997 || cppVar_44176;
	cppVar_44178 = cppVar_43994 || cppVar_44177;
	cppVar_44179 = cppVar_43991 || cppVar_44178;
	cppVar_44180 = cppVar_43988 || cppVar_44179;
	cppVar_44181 = cppVar_43985 || cppVar_44180;
	cppVar_44182 = cppVar_43982 || cppVar_44181;
	cppVar_44183 = cppVar_43979 || cppVar_44182;
	cppVar_44184 = cppVar_43976 || cppVar_44183;
	cppVar_44185 = cppVar_43973 || cppVar_44184;
	cppVar_44186 = cppVar_43970 || cppVar_44185;
	cppVar_44187 = cppVar_43967 || cppVar_44186;
	cppVar_44188 = cppVar_43964 || cppVar_44187;
	cppVar_44189 = cppVar_43961 || cppVar_44188;
	cppVar_44190 = cppVar_43958 || cppVar_44189;
	cppVar_44191 = cppVar_43955 || cppVar_44190;
	cppVar_44192 = cppVar_43952 || cppVar_44191;
	cppVar_44193 = cppVar_43949 || cppVar_44192;
	cppVar_44194 = cppVar_43946 || cppVar_44193;
	cppVar_44195 = cppVar_43943 || cppVar_44194;
	cppVar_44196 = cppVar_43940 || cppVar_44195;
	cppVar_44197 = cppVar_43937 || cppVar_44196;
	cppVar_44198 = cppVar_43934 || cppVar_44197;
	cppVar_44199 = cppVar_43931 || cppVar_44198;
	cppVar_44200 = cppVar_43928 || cppVar_44199;
	cppVar_44201 = cppVar_43925 || cppVar_44200;
	cppVar_44202 = cppVar_43922 || cppVar_44201;
	cppVar_44203 = cppVar_43919 || cppVar_44202;
	cppVar_44204 = cppVar_43916 || cppVar_44203;
	cppVar_44205 = cppVar_43913 || cppVar_44204;
	cppVar_44206 = cppVar_43910 || cppVar_44205;
	cppVar_44207 = cppVar_43907 || cppVar_44206;
	cppVar_44208 = cppVar_43904 || cppVar_44207;
	cppVar_44209 = cppVar_43901 || cppVar_44208;
	cppVar_44210 = cppVar_43898 || cppVar_44209;
	cppVar_44211 = cppVar_43895 || cppVar_44210;
	cppVar_44212 = cppVar_43892 || cppVar_44211;
	cppVar_44213 = cppVar_43889 || cppVar_44212;
	cppVar_44214 = cppVar_43886 || cppVar_44213;
	cppVar_44215 = cppVar_43883 || cppVar_44214;
	cppVar_44216 = cppVar_43880 || cppVar_44215;
	cppVar_44217 = cppVar_43877 || cppVar_44216;
	cppVar_44218 = cppVar_43874 || cppVar_44217;
	cppVar_44219 = cppVar_43871 || cppVar_44218;
	cppVar_44220 = cppVar_43868 || cppVar_44219;
	cppVar_44221 = cppVar_43865 || cppVar_44220;
	cppVar_44222 = cppVar_43862 || cppVar_44221;
	cppVar_44223 = cppVar_43859 || cppVar_44222;
	cppVar_44224 = cppVar_43856 || cppVar_44223;
	cppVar_44225 = cppVar_43853 || cppVar_44224;
	cppVar_44226 = cppVar_43850 || cppVar_44225;
	cppVar_44227 = cppVar_43847 || cppVar_44226;
	cppVar_44228 = cppVar_43844 || cppVar_44227;
	cppVar_44229 = cppVar_43841 || cppVar_44228;
	cppVar_44230 = cppVar_43838 || cppVar_44229;
	cppVar_44231 = cppVar_43835 || cppVar_44230;
	cppVar_44232 = cppVar_43832 || cppVar_44231;
	cppVar_44233 = cppVar_43829 || cppVar_44232;
	cppVar_44234 = cppVar_43826 || cppVar_44233;
	cppVar_44235 = cppVar_43823 || cppVar_44234;
	cppVar_44236 = cppVar_43820 || cppVar_44235;
	cppVar_44237 = cppVar_43817 || cppVar_44236;
	cppVar_44238 = cppVar_43814 || cppVar_44237;
	cppVar_44239 = cppVar_43811 || cppVar_44238;
	cppVar_44240 = cppVar_43808 || cppVar_44239;
	cppVar_44241 = cppVar_43805 || cppVar_44240;
	cppVar_44242 = cppVar_43802 || cppVar_44241;
	cppVar_44243 = cppVar_43799 || cppVar_44242;
	cppVar_44244 = cppVar_43796 || cppVar_44243;
	cppVar_44245 = cppVar_43793 || cppVar_44244;
	cppVar_44246 = cppVar_43790 || cppVar_44245;
	cppVar_44247 = cppVar_43787 || cppVar_44246;
	cppVar_44248 = cppVar_43784 || cppVar_44247;
	cppVar_44249 = cppVar_43781 || cppVar_44248;
	cppVar_44250 = cppVar_43778 || cppVar_44249;
	cppVar_44251 = cppVar_43775 || cppVar_44250;
	cppVar_44252 = cppVar_43772 || cppVar_44251;
	cppVar_44253 = cppVar_43769 || cppVar_44252;
	cppVar_44254 = cppVar_43766 || cppVar_44253;
	cppVar_44255 = cppVar_43763 || cppVar_44254;
	cppVar_44256 = cppVar_43760 || cppVar_44255;
	cppVar_44257 = cppVar_43757 || cppVar_44256;
	cppVar_44258 = cppVar_43754 || cppVar_44257;
	cppVar_44259 = cppVar_43751 || cppVar_44258;
	cppVar_44260 = cppVar_43748 || cppVar_44259;
	cppVar_44261 = cppVar_43745 || cppVar_44260;
	cppVar_44262 = cppVar_43742 || cppVar_44261;
	cppVar_44263 = cppVar_43739 || cppVar_44262;
	cppVar_44264 = cppVar_43736 || cppVar_44263;
	cppVar_44265 = cppVar_43733 || cppVar_44264;
	cppVar_44266 = cppVar_43730 || cppVar_44265;
	cppVar_44267 = cppVar_43727 || cppVar_44266;
	cppVar_44268 = cppVar_43724 || cppVar_44267;
	cppVar_44269 = cppVar_43721 || cppVar_44268;
	if (cppVar_44269) {
	cppVar_44271 = PC + 1;
	cppVar_44271 = (cppVar_44271 & cppMask_un_16_);
	cppVar_43718 = cppVar_44271;
	} else {
	cppVar_43718 = PC;
	}
	cppVar_43701 = cppVar_43718;
	}
	cppVar_43686 = cppVar_43701;
	}
	cppVar_43436 = cppVar_43686;
	}
	cppVar_43017 = cppVar_43436;
	}
	cppVar_43000 = cppVar_43017;
	}
	cppVar_42987 = cppVar_43000;
	}
	cppVar_42572 = cppVar_42987;
	}
	cppVar_42555 = cppVar_42572;
	}
	cppVar_42538 = cppVar_42555;
	}
	cppVar_42512 = cppVar_42538;
	}
	cppVar_42495 = cppVar_42512;
	}
	cppVar_42479 = cppVar_42495;
	}
	cppVar_42462 = cppVar_42479;
	}
	cppVar_42446 = cppVar_42462;
	}
	cppVar_42439 = cppVar_42446;
	}
	cppVar_42428 = cppVar_42439;
	}
	cppVar_42411 = cppVar_42428;
	}
	cppVar_42394 = cppVar_42411;
	}
	cppVar_42376 = cppVar_42394;
	}
	cppVar_42245 = cppVar_42376;
	}
	cppVar_42220 = cppVar_42245;
	}
	cppVar_42195 = cppVar_42220;
	}
	cppVar_42171 = cppVar_42195;
	}
	cppVar_42147 = cppVar_42171;
	}
	cppVar_42123 = cppVar_42147;
	}
	cppVar_42099 = cppVar_42123;
	}
	cppVar_42075 = cppVar_42099;
	}
	cppVar_42051 = cppVar_42075;
	}
	cppVar_42027 = cppVar_42051;
	}
	cppVar_42003 = cppVar_42027;
	}
	cppVar_41986 = cppVar_42003;
	}
	cppVar_41854 = cppVar_41986;
	}
	cppVar_41832 = cppVar_41854;
	}
	cppVar_41810 = cppVar_41832;
	}
	cppVar_41788 = cppVar_41810;
	}
	cppVar_41766 = cppVar_41788;
	}
	cppVar_41744 = cppVar_41766;
	}
	cppVar_41722 = cppVar_41744;
	}
	cppVar_41700 = cppVar_41722;
	}
	cppVar_41678 = cppVar_41700;
	}
	cppVar_41661 = cppVar_41678;
	}
	return cppVar_41661;
}
