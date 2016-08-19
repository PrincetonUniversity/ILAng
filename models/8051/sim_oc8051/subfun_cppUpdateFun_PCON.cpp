#include "common.hpp"
#include "model_oc8051_class.hpp"

BIT_VEC model_oc8051::cppUpdateFun_PCON()
{
	BIT_VEC cppVar_44274;
	BIT_VEC cppVar_44275;
	bool cppVar_44276;
	BIT_VEC cppVar_44278;
	BIT_VEC cppVar_44279;
	BIT_VEC cppVar_44280;
	BIT_VEC cppVar_44281;
	bool cppVar_44282;
	BIT_VEC cppVar_44283;
	BIT_VEC cppVar_44277;
	BIT_VEC cppVar_44285;
	BIT_VEC cppVar_44286;
	bool cppVar_44287;
	BIT_VEC cppVar_44288;
	BIT_VEC cppVar_44289;
	bool cppVar_44290;
	bool cppVar_44291;
	BIT_VEC cppVar_44293;
	BIT_VEC cppVar_44294;
	BIT_VEC cppVar_44295;
	BIT_VEC cppVar_44296;
	bool cppVar_44297;
	BIT_VEC cppVar_44292;
	BIT_VEC cppVar_44299;
	BIT_VEC cppVar_44300;
	bool cppVar_44301;
	BIT_VEC cppVar_44303;
	BIT_VEC cppVar_44304;
	BIT_VEC cppVar_44305;
	BIT_VEC cppVar_44306;
	bool cppVar_44307;
	BIT_VEC cppVar_44309;
	BIT_VEC cppVar_44310;
	BIT_VEC cppVar_44311;
	BIT_VEC cppVar_44312;
	BIT_VEC cppVar_44313;
	BIT_VEC cppVar_44314;
	BIT_VEC cppVar_44315;
	bool cppVar_44316;
	BIT_VEC cppVar_44317;
	BIT_VEC cppVar_44318;
	BIT_VEC cppVar_44319;
	BIT_VEC cppVar_44320;
	BIT_VEC cppVar_44322;
	BIT_VEC cppVar_44323;
	BIT_VEC cppVar_44324;
	BIT_VEC cppVar_44325;
	bool cppVar_44326;
	BIT_VEC cppVar_44328;
	BIT_VEC cppVar_44329;
	BIT_VEC cppVar_44330;
	BIT_VEC cppVar_44331;
	bool cppVar_44332;
	BIT_VEC cppVar_44334;
	BIT_VEC cppVar_44335;
	BIT_VEC cppVar_44336;
	BIT_VEC cppVar_44337;
	bool cppVar_44338;
	BIT_VEC cppVar_44340;
	BIT_VEC cppVar_44341;
	BIT_VEC cppVar_44342;
	BIT_VEC cppVar_44343;
	bool cppVar_44344;
	BIT_VEC cppVar_44346;
	BIT_VEC cppVar_44347;
	BIT_VEC cppVar_44348;
	BIT_VEC cppVar_44349;
	bool cppVar_44350;
	BIT_VEC cppVar_44352;
	BIT_VEC cppVar_44353;
	BIT_VEC cppVar_44354;
	BIT_VEC cppVar_44355;
	bool cppVar_44356;
	BIT_VEC cppVar_44358;
	BIT_VEC cppVar_44359;
	BIT_VEC cppVar_44360;
	BIT_VEC cppVar_44361;
	bool cppVar_44362;
	BIT_VEC cppVar_44364;
	BIT_VEC cppVar_44365;
	BIT_VEC cppVar_44366;
	BIT_VEC cppVar_44367;
	bool cppVar_44368;
	BIT_VEC cppVar_44370;
	BIT_VEC cppVar_44371;
	BIT_VEC cppVar_44372;
	BIT_VEC cppVar_44373;
	bool cppVar_44374;
	BIT_VEC cppVar_44376;
	BIT_VEC cppVar_44377;
	BIT_VEC cppVar_44378;
	BIT_VEC cppVar_44379;
	bool cppVar_44380;
	BIT_VEC cppVar_44382;
	BIT_VEC cppVar_44383;
	BIT_VEC cppVar_44384;
	BIT_VEC cppVar_44385;
	bool cppVar_44386;
	BIT_VEC cppVar_44388;
	BIT_VEC cppVar_44389;
	BIT_VEC cppVar_44390;
	BIT_VEC cppVar_44391;
	bool cppVar_44392;
	BIT_VEC cppVar_44394;
	BIT_VEC cppVar_44395;
	BIT_VEC cppVar_44396;
	BIT_VEC cppVar_44397;
	bool cppVar_44398;
	BIT_VEC cppVar_44400;
	BIT_VEC cppVar_44401;
	BIT_VEC cppVar_44402;
	BIT_VEC cppVar_44403;
	bool cppVar_44404;
	BIT_VEC cppVar_44406;
	BIT_VEC cppVar_44407;
	BIT_VEC cppVar_44408;
	BIT_VEC cppVar_44409;
	bool cppVar_44410;
	BIT_VEC cppVar_44412;
	BIT_VEC cppVar_44413;
	BIT_VEC cppVar_44414;
	BIT_VEC cppVar_44415;
	bool cppVar_44416;
	BIT_VEC cppVar_44418;
	BIT_VEC cppVar_44419;
	BIT_VEC cppVar_44420;
	BIT_VEC cppVar_44421;
	bool cppVar_44422;
	BIT_VEC cppVar_44424;
	BIT_VEC cppVar_44425;
	BIT_VEC cppVar_44426;
	BIT_VEC cppVar_44427;
	bool cppVar_44428;
	BIT_VEC cppVar_44430;
	BIT_VEC cppVar_44431;
	BIT_VEC cppVar_44432;
	BIT_VEC cppVar_44433;
	bool cppVar_44434;
	BIT_VEC cppVar_44436;
	BIT_VEC cppVar_44437;
	BIT_VEC cppVar_44438;
	BIT_VEC cppVar_44439;
	bool cppVar_44440;
	BIT_VEC cppVar_44442;
	BIT_VEC cppVar_44443;
	BIT_VEC cppVar_44444;
	BIT_VEC cppVar_44445;
	bool cppVar_44446;
	BIT_VEC cppVar_44447;
	BIT_VEC cppVar_44441;
	BIT_VEC cppVar_44435;
	BIT_VEC cppVar_44429;
	BIT_VEC cppVar_44423;
	BIT_VEC cppVar_44417;
	BIT_VEC cppVar_44411;
	BIT_VEC cppVar_44405;
	BIT_VEC cppVar_44399;
	BIT_VEC cppVar_44393;
	BIT_VEC cppVar_44387;
	BIT_VEC cppVar_44381;
	BIT_VEC cppVar_44375;
	BIT_VEC cppVar_44369;
	BIT_VEC cppVar_44363;
	BIT_VEC cppVar_44357;
	BIT_VEC cppVar_44351;
	BIT_VEC cppVar_44345;
	BIT_VEC cppVar_44339;
	BIT_VEC cppVar_44333;
	BIT_VEC cppVar_44327;
	BIT_VEC cppVar_44321;
	BIT_VEC cppVar_44308;
	BIT_VEC cppVar_44302;
	BIT_VEC cppVar_44449;
	BIT_VEC cppVar_44450;
	bool cppVar_44451;
	BIT_VEC cppVar_44453;
	BIT_VEC cppVar_44454;
	BIT_VEC cppVar_44455;
	BIT_VEC cppVar_44456;
	bool cppVar_44457;
	BIT_VEC cppVar_44459;
	BIT_VEC cppVar_44460;
	BIT_VEC cppVar_44461;
	BIT_VEC cppVar_44462;
	BIT_VEC cppVar_44463;
	BIT_VEC cppVar_44464;
	BIT_VEC cppVar_44465;
	bool cppVar_44466;
	BIT_VEC cppVar_44467;
	BIT_VEC cppVar_44468;
	BIT_VEC cppVar_44469;
	BIT_VEC cppVar_44470;
	BIT_VEC cppVar_44472;
	BIT_VEC cppVar_44473;
	BIT_VEC cppVar_44474;
	BIT_VEC cppVar_44475;
	bool cppVar_44476;
	BIT_VEC cppVar_44478;
	BIT_VEC cppVar_44479;
	BIT_VEC cppVar_44480;
	BIT_VEC cppVar_44481;
	bool cppVar_44482;
	BIT_VEC cppVar_44484;
	BIT_VEC cppVar_44485;
	BIT_VEC cppVar_44486;
	BIT_VEC cppVar_44487;
	bool cppVar_44488;
	BIT_VEC cppVar_44490;
	BIT_VEC cppVar_44491;
	BIT_VEC cppVar_44492;
	BIT_VEC cppVar_44493;
	bool cppVar_44494;
	BIT_VEC cppVar_44496;
	BIT_VEC cppVar_44497;
	BIT_VEC cppVar_44498;
	BIT_VEC cppVar_44499;
	bool cppVar_44500;
	BIT_VEC cppVar_44502;
	BIT_VEC cppVar_44503;
	BIT_VEC cppVar_44504;
	BIT_VEC cppVar_44505;
	bool cppVar_44506;
	BIT_VEC cppVar_44508;
	BIT_VEC cppVar_44509;
	BIT_VEC cppVar_44510;
	BIT_VEC cppVar_44511;
	bool cppVar_44512;
	BIT_VEC cppVar_44514;
	BIT_VEC cppVar_44515;
	BIT_VEC cppVar_44516;
	BIT_VEC cppVar_44517;
	bool cppVar_44518;
	BIT_VEC cppVar_44520;
	BIT_VEC cppVar_44521;
	BIT_VEC cppVar_44522;
	BIT_VEC cppVar_44523;
	bool cppVar_44524;
	BIT_VEC cppVar_44526;
	BIT_VEC cppVar_44527;
	BIT_VEC cppVar_44528;
	BIT_VEC cppVar_44529;
	bool cppVar_44530;
	BIT_VEC cppVar_44532;
	BIT_VEC cppVar_44533;
	BIT_VEC cppVar_44534;
	BIT_VEC cppVar_44535;
	bool cppVar_44536;
	BIT_VEC cppVar_44538;
	BIT_VEC cppVar_44539;
	BIT_VEC cppVar_44540;
	BIT_VEC cppVar_44541;
	bool cppVar_44542;
	BIT_VEC cppVar_44544;
	BIT_VEC cppVar_44545;
	BIT_VEC cppVar_44546;
	BIT_VEC cppVar_44547;
	bool cppVar_44548;
	BIT_VEC cppVar_44550;
	BIT_VEC cppVar_44551;
	BIT_VEC cppVar_44552;
	BIT_VEC cppVar_44553;
	bool cppVar_44554;
	BIT_VEC cppVar_44556;
	BIT_VEC cppVar_44557;
	BIT_VEC cppVar_44558;
	BIT_VEC cppVar_44559;
	bool cppVar_44560;
	BIT_VEC cppVar_44562;
	BIT_VEC cppVar_44563;
	BIT_VEC cppVar_44564;
	BIT_VEC cppVar_44565;
	bool cppVar_44566;
	BIT_VEC cppVar_44568;
	BIT_VEC cppVar_44569;
	BIT_VEC cppVar_44570;
	BIT_VEC cppVar_44571;
	bool cppVar_44572;
	BIT_VEC cppVar_44574;
	BIT_VEC cppVar_44575;
	BIT_VEC cppVar_44576;
	BIT_VEC cppVar_44577;
	bool cppVar_44578;
	BIT_VEC cppVar_44580;
	BIT_VEC cppVar_44581;
	BIT_VEC cppVar_44582;
	BIT_VEC cppVar_44583;
	bool cppVar_44584;
	BIT_VEC cppVar_44586;
	BIT_VEC cppVar_44587;
	BIT_VEC cppVar_44588;
	BIT_VEC cppVar_44589;
	bool cppVar_44590;
	BIT_VEC cppVar_44592;
	BIT_VEC cppVar_44593;
	BIT_VEC cppVar_44594;
	BIT_VEC cppVar_44595;
	bool cppVar_44596;
	BIT_VEC cppVar_44597;
	BIT_VEC cppVar_44591;
	BIT_VEC cppVar_44585;
	BIT_VEC cppVar_44579;
	BIT_VEC cppVar_44573;
	BIT_VEC cppVar_44567;
	BIT_VEC cppVar_44561;
	BIT_VEC cppVar_44555;
	BIT_VEC cppVar_44549;
	BIT_VEC cppVar_44543;
	BIT_VEC cppVar_44537;
	BIT_VEC cppVar_44531;
	BIT_VEC cppVar_44525;
	BIT_VEC cppVar_44519;
	BIT_VEC cppVar_44513;
	BIT_VEC cppVar_44507;
	BIT_VEC cppVar_44501;
	BIT_VEC cppVar_44495;
	BIT_VEC cppVar_44489;
	BIT_VEC cppVar_44483;
	BIT_VEC cppVar_44477;
	BIT_VEC cppVar_44471;
	BIT_VEC cppVar_44458;
	BIT_VEC cppVar_44452;
	BIT_VEC cppVar_44599;
	BIT_VEC cppVar_44600;
	bool cppVar_44601;
	BIT_VEC cppVar_44603;
	BIT_VEC cppVar_44604;
	BIT_VEC cppVar_44605;
	BIT_VEC cppVar_44606;
	bool cppVar_44607;
	BIT_VEC cppVar_44609;
	BIT_VEC cppVar_44610;
	BIT_VEC cppVar_44611;
	BIT_VEC cppVar_44612;
	BIT_VEC cppVar_44613;
	BIT_VEC cppVar_44614;
	BIT_VEC cppVar_44615;
	bool cppVar_44616;
	BIT_VEC cppVar_44617;
	BIT_VEC cppVar_44618;
	BIT_VEC cppVar_44619;
	BIT_VEC cppVar_44620;
	BIT_VEC cppVar_44622;
	BIT_VEC cppVar_44623;
	BIT_VEC cppVar_44624;
	BIT_VEC cppVar_44625;
	bool cppVar_44626;
	BIT_VEC cppVar_44628;
	BIT_VEC cppVar_44629;
	BIT_VEC cppVar_44630;
	BIT_VEC cppVar_44631;
	bool cppVar_44632;
	BIT_VEC cppVar_44634;
	BIT_VEC cppVar_44635;
	BIT_VEC cppVar_44636;
	BIT_VEC cppVar_44637;
	bool cppVar_44638;
	BIT_VEC cppVar_44640;
	BIT_VEC cppVar_44641;
	BIT_VEC cppVar_44642;
	BIT_VEC cppVar_44643;
	bool cppVar_44644;
	BIT_VEC cppVar_44646;
	BIT_VEC cppVar_44647;
	BIT_VEC cppVar_44648;
	BIT_VEC cppVar_44649;
	bool cppVar_44650;
	BIT_VEC cppVar_44652;
	BIT_VEC cppVar_44653;
	BIT_VEC cppVar_44654;
	BIT_VEC cppVar_44655;
	bool cppVar_44656;
	BIT_VEC cppVar_44658;
	BIT_VEC cppVar_44659;
	BIT_VEC cppVar_44660;
	BIT_VEC cppVar_44661;
	bool cppVar_44662;
	BIT_VEC cppVar_44664;
	BIT_VEC cppVar_44665;
	BIT_VEC cppVar_44666;
	BIT_VEC cppVar_44667;
	bool cppVar_44668;
	BIT_VEC cppVar_44670;
	BIT_VEC cppVar_44671;
	BIT_VEC cppVar_44672;
	BIT_VEC cppVar_44673;
	bool cppVar_44674;
	BIT_VEC cppVar_44676;
	BIT_VEC cppVar_44677;
	BIT_VEC cppVar_44678;
	BIT_VEC cppVar_44679;
	bool cppVar_44680;
	BIT_VEC cppVar_44682;
	BIT_VEC cppVar_44683;
	BIT_VEC cppVar_44684;
	BIT_VEC cppVar_44685;
	bool cppVar_44686;
	BIT_VEC cppVar_44688;
	BIT_VEC cppVar_44689;
	BIT_VEC cppVar_44690;
	BIT_VEC cppVar_44691;
	bool cppVar_44692;
	BIT_VEC cppVar_44694;
	BIT_VEC cppVar_44695;
	BIT_VEC cppVar_44696;
	BIT_VEC cppVar_44697;
	bool cppVar_44698;
	BIT_VEC cppVar_44700;
	BIT_VEC cppVar_44701;
	BIT_VEC cppVar_44702;
	BIT_VEC cppVar_44703;
	bool cppVar_44704;
	BIT_VEC cppVar_44706;
	BIT_VEC cppVar_44707;
	BIT_VEC cppVar_44708;
	BIT_VEC cppVar_44709;
	bool cppVar_44710;
	BIT_VEC cppVar_44712;
	BIT_VEC cppVar_44713;
	BIT_VEC cppVar_44714;
	BIT_VEC cppVar_44715;
	bool cppVar_44716;
	BIT_VEC cppVar_44718;
	BIT_VEC cppVar_44719;
	BIT_VEC cppVar_44720;
	BIT_VEC cppVar_44721;
	bool cppVar_44722;
	BIT_VEC cppVar_44724;
	BIT_VEC cppVar_44725;
	BIT_VEC cppVar_44726;
	BIT_VEC cppVar_44727;
	bool cppVar_44728;
	BIT_VEC cppVar_44730;
	BIT_VEC cppVar_44731;
	BIT_VEC cppVar_44732;
	BIT_VEC cppVar_44733;
	bool cppVar_44734;
	BIT_VEC cppVar_44736;
	BIT_VEC cppVar_44737;
	BIT_VEC cppVar_44738;
	BIT_VEC cppVar_44739;
	bool cppVar_44740;
	BIT_VEC cppVar_44742;
	BIT_VEC cppVar_44743;
	BIT_VEC cppVar_44744;
	BIT_VEC cppVar_44745;
	bool cppVar_44746;
	BIT_VEC cppVar_44747;
	BIT_VEC cppVar_44741;
	BIT_VEC cppVar_44735;
	BIT_VEC cppVar_44729;
	BIT_VEC cppVar_44723;
	BIT_VEC cppVar_44717;
	BIT_VEC cppVar_44711;
	BIT_VEC cppVar_44705;
	BIT_VEC cppVar_44699;
	BIT_VEC cppVar_44693;
	BIT_VEC cppVar_44687;
	BIT_VEC cppVar_44681;
	BIT_VEC cppVar_44675;
	BIT_VEC cppVar_44669;
	BIT_VEC cppVar_44663;
	BIT_VEC cppVar_44657;
	BIT_VEC cppVar_44651;
	BIT_VEC cppVar_44645;
	BIT_VEC cppVar_44639;
	BIT_VEC cppVar_44633;
	BIT_VEC cppVar_44627;
	BIT_VEC cppVar_44621;
	BIT_VEC cppVar_44608;
	BIT_VEC cppVar_44602;
	BIT_VEC cppVar_44749;
	BIT_VEC cppVar_44750;
	bool cppVar_44751;
	BIT_VEC cppVar_44753;
	BIT_VEC cppVar_44754;
	BIT_VEC cppVar_44755;
	BIT_VEC cppVar_44756;
	bool cppVar_44757;
	BIT_VEC cppVar_44759;
	BIT_VEC cppVar_44760;
	BIT_VEC cppVar_44761;
	BIT_VEC cppVar_44762;
	BIT_VEC cppVar_44763;
	BIT_VEC cppVar_44764;
	BIT_VEC cppVar_44765;
	bool cppVar_44766;
	BIT_VEC cppVar_44767;
	BIT_VEC cppVar_44768;
	BIT_VEC cppVar_44769;
	BIT_VEC cppVar_44770;
	BIT_VEC cppVar_44772;
	BIT_VEC cppVar_44773;
	BIT_VEC cppVar_44774;
	BIT_VEC cppVar_44775;
	bool cppVar_44776;
	BIT_VEC cppVar_44778;
	BIT_VEC cppVar_44779;
	BIT_VEC cppVar_44780;
	BIT_VEC cppVar_44781;
	bool cppVar_44782;
	BIT_VEC cppVar_44784;
	BIT_VEC cppVar_44785;
	BIT_VEC cppVar_44786;
	BIT_VEC cppVar_44787;
	bool cppVar_44788;
	BIT_VEC cppVar_44790;
	BIT_VEC cppVar_44791;
	BIT_VEC cppVar_44792;
	BIT_VEC cppVar_44793;
	bool cppVar_44794;
	BIT_VEC cppVar_44796;
	BIT_VEC cppVar_44797;
	BIT_VEC cppVar_44798;
	BIT_VEC cppVar_44799;
	bool cppVar_44800;
	BIT_VEC cppVar_44802;
	BIT_VEC cppVar_44803;
	BIT_VEC cppVar_44804;
	BIT_VEC cppVar_44805;
	bool cppVar_44806;
	BIT_VEC cppVar_44808;
	BIT_VEC cppVar_44809;
	BIT_VEC cppVar_44810;
	BIT_VEC cppVar_44811;
	bool cppVar_44812;
	BIT_VEC cppVar_44814;
	BIT_VEC cppVar_44815;
	BIT_VEC cppVar_44816;
	BIT_VEC cppVar_44817;
	bool cppVar_44818;
	BIT_VEC cppVar_44820;
	BIT_VEC cppVar_44821;
	BIT_VEC cppVar_44822;
	BIT_VEC cppVar_44823;
	bool cppVar_44824;
	BIT_VEC cppVar_44826;
	BIT_VEC cppVar_44827;
	BIT_VEC cppVar_44828;
	BIT_VEC cppVar_44829;
	bool cppVar_44830;
	BIT_VEC cppVar_44832;
	BIT_VEC cppVar_44833;
	BIT_VEC cppVar_44834;
	BIT_VEC cppVar_44835;
	bool cppVar_44836;
	BIT_VEC cppVar_44838;
	BIT_VEC cppVar_44839;
	BIT_VEC cppVar_44840;
	BIT_VEC cppVar_44841;
	bool cppVar_44842;
	BIT_VEC cppVar_44844;
	BIT_VEC cppVar_44845;
	BIT_VEC cppVar_44846;
	BIT_VEC cppVar_44847;
	bool cppVar_44848;
	BIT_VEC cppVar_44850;
	BIT_VEC cppVar_44851;
	BIT_VEC cppVar_44852;
	BIT_VEC cppVar_44853;
	bool cppVar_44854;
	BIT_VEC cppVar_44856;
	BIT_VEC cppVar_44857;
	BIT_VEC cppVar_44858;
	BIT_VEC cppVar_44859;
	bool cppVar_44860;
	BIT_VEC cppVar_44862;
	BIT_VEC cppVar_44863;
	BIT_VEC cppVar_44864;
	BIT_VEC cppVar_44865;
	bool cppVar_44866;
	BIT_VEC cppVar_44868;
	BIT_VEC cppVar_44869;
	BIT_VEC cppVar_44870;
	BIT_VEC cppVar_44871;
	bool cppVar_44872;
	BIT_VEC cppVar_44874;
	BIT_VEC cppVar_44875;
	BIT_VEC cppVar_44876;
	BIT_VEC cppVar_44877;
	bool cppVar_44878;
	BIT_VEC cppVar_44880;
	BIT_VEC cppVar_44881;
	BIT_VEC cppVar_44882;
	BIT_VEC cppVar_44883;
	bool cppVar_44884;
	BIT_VEC cppVar_44886;
	BIT_VEC cppVar_44887;
	BIT_VEC cppVar_44888;
	BIT_VEC cppVar_44889;
	bool cppVar_44890;
	BIT_VEC cppVar_44892;
	BIT_VEC cppVar_44893;
	BIT_VEC cppVar_44894;
	BIT_VEC cppVar_44895;
	bool cppVar_44896;
	BIT_VEC cppVar_44897;
	BIT_VEC cppVar_44891;
	BIT_VEC cppVar_44885;
	BIT_VEC cppVar_44879;
	BIT_VEC cppVar_44873;
	BIT_VEC cppVar_44867;
	BIT_VEC cppVar_44861;
	BIT_VEC cppVar_44855;
	BIT_VEC cppVar_44849;
	BIT_VEC cppVar_44843;
	BIT_VEC cppVar_44837;
	BIT_VEC cppVar_44831;
	BIT_VEC cppVar_44825;
	BIT_VEC cppVar_44819;
	BIT_VEC cppVar_44813;
	BIT_VEC cppVar_44807;
	BIT_VEC cppVar_44801;
	BIT_VEC cppVar_44795;
	BIT_VEC cppVar_44789;
	BIT_VEC cppVar_44783;
	BIT_VEC cppVar_44777;
	BIT_VEC cppVar_44771;
	BIT_VEC cppVar_44758;
	BIT_VEC cppVar_44752;
	BIT_VEC cppVar_44899;
	BIT_VEC cppVar_44900;
	bool cppVar_44901;
	BIT_VEC cppVar_44903;
	BIT_VEC cppVar_44904;
	BIT_VEC cppVar_44905;
	BIT_VEC cppVar_44906;
	bool cppVar_44907;
	BIT_VEC cppVar_44909;
	BIT_VEC cppVar_44910;
	BIT_VEC cppVar_44911;
	BIT_VEC cppVar_44912;
	BIT_VEC cppVar_44913;
	BIT_VEC cppVar_44914;
	BIT_VEC cppVar_44915;
	bool cppVar_44916;
	BIT_VEC cppVar_44917;
	BIT_VEC cppVar_44918;
	BIT_VEC cppVar_44919;
	BIT_VEC cppVar_44920;
	BIT_VEC cppVar_44922;
	BIT_VEC cppVar_44923;
	BIT_VEC cppVar_44924;
	BIT_VEC cppVar_44925;
	bool cppVar_44926;
	BIT_VEC cppVar_44928;
	BIT_VEC cppVar_44929;
	BIT_VEC cppVar_44930;
	BIT_VEC cppVar_44931;
	bool cppVar_44932;
	BIT_VEC cppVar_44934;
	BIT_VEC cppVar_44935;
	BIT_VEC cppVar_44936;
	BIT_VEC cppVar_44937;
	bool cppVar_44938;
	BIT_VEC cppVar_44940;
	BIT_VEC cppVar_44941;
	BIT_VEC cppVar_44942;
	BIT_VEC cppVar_44943;
	bool cppVar_44944;
	BIT_VEC cppVar_44946;
	BIT_VEC cppVar_44947;
	BIT_VEC cppVar_44948;
	BIT_VEC cppVar_44949;
	bool cppVar_44950;
	BIT_VEC cppVar_44952;
	BIT_VEC cppVar_44953;
	BIT_VEC cppVar_44954;
	BIT_VEC cppVar_44955;
	bool cppVar_44956;
	BIT_VEC cppVar_44958;
	BIT_VEC cppVar_44959;
	BIT_VEC cppVar_44960;
	BIT_VEC cppVar_44961;
	bool cppVar_44962;
	BIT_VEC cppVar_44964;
	BIT_VEC cppVar_44965;
	BIT_VEC cppVar_44966;
	BIT_VEC cppVar_44967;
	bool cppVar_44968;
	BIT_VEC cppVar_44970;
	BIT_VEC cppVar_44971;
	BIT_VEC cppVar_44972;
	BIT_VEC cppVar_44973;
	bool cppVar_44974;
	BIT_VEC cppVar_44976;
	BIT_VEC cppVar_44977;
	BIT_VEC cppVar_44978;
	BIT_VEC cppVar_44979;
	bool cppVar_44980;
	BIT_VEC cppVar_44982;
	BIT_VEC cppVar_44983;
	BIT_VEC cppVar_44984;
	BIT_VEC cppVar_44985;
	bool cppVar_44986;
	BIT_VEC cppVar_44988;
	BIT_VEC cppVar_44989;
	BIT_VEC cppVar_44990;
	BIT_VEC cppVar_44991;
	bool cppVar_44992;
	BIT_VEC cppVar_44994;
	BIT_VEC cppVar_44995;
	BIT_VEC cppVar_44996;
	BIT_VEC cppVar_44997;
	bool cppVar_44998;
	BIT_VEC cppVar_45000;
	BIT_VEC cppVar_45001;
	BIT_VEC cppVar_45002;
	BIT_VEC cppVar_45003;
	bool cppVar_45004;
	BIT_VEC cppVar_45006;
	BIT_VEC cppVar_45007;
	BIT_VEC cppVar_45008;
	BIT_VEC cppVar_45009;
	bool cppVar_45010;
	BIT_VEC cppVar_45012;
	BIT_VEC cppVar_45013;
	BIT_VEC cppVar_45014;
	BIT_VEC cppVar_45015;
	bool cppVar_45016;
	BIT_VEC cppVar_45018;
	BIT_VEC cppVar_45019;
	BIT_VEC cppVar_45020;
	BIT_VEC cppVar_45021;
	bool cppVar_45022;
	BIT_VEC cppVar_45024;
	BIT_VEC cppVar_45025;
	BIT_VEC cppVar_45026;
	BIT_VEC cppVar_45027;
	bool cppVar_45028;
	BIT_VEC cppVar_45030;
	BIT_VEC cppVar_45031;
	BIT_VEC cppVar_45032;
	BIT_VEC cppVar_45033;
	bool cppVar_45034;
	BIT_VEC cppVar_45036;
	BIT_VEC cppVar_45037;
	BIT_VEC cppVar_45038;
	BIT_VEC cppVar_45039;
	bool cppVar_45040;
	BIT_VEC cppVar_45042;
	BIT_VEC cppVar_45043;
	BIT_VEC cppVar_45044;
	BIT_VEC cppVar_45045;
	bool cppVar_45046;
	BIT_VEC cppVar_45047;
	BIT_VEC cppVar_45041;
	BIT_VEC cppVar_45035;
	BIT_VEC cppVar_45029;
	BIT_VEC cppVar_45023;
	BIT_VEC cppVar_45017;
	BIT_VEC cppVar_45011;
	BIT_VEC cppVar_45005;
	BIT_VEC cppVar_44999;
	BIT_VEC cppVar_44993;
	BIT_VEC cppVar_44987;
	BIT_VEC cppVar_44981;
	BIT_VEC cppVar_44975;
	BIT_VEC cppVar_44969;
	BIT_VEC cppVar_44963;
	BIT_VEC cppVar_44957;
	BIT_VEC cppVar_44951;
	BIT_VEC cppVar_44945;
	BIT_VEC cppVar_44939;
	BIT_VEC cppVar_44933;
	BIT_VEC cppVar_44927;
	BIT_VEC cppVar_44921;
	BIT_VEC cppVar_44908;
	BIT_VEC cppVar_44902;
	BIT_VEC cppVar_45049;
	BIT_VEC cppVar_45050;
	bool cppVar_45051;
	BIT_VEC cppVar_45053;
	BIT_VEC cppVar_45054;
	BIT_VEC cppVar_45055;
	BIT_VEC cppVar_45056;
	bool cppVar_45057;
	BIT_VEC cppVar_45059;
	BIT_VEC cppVar_45060;
	BIT_VEC cppVar_45061;
	BIT_VEC cppVar_45062;
	BIT_VEC cppVar_45063;
	BIT_VEC cppVar_45064;
	BIT_VEC cppVar_45065;
	bool cppVar_45066;
	BIT_VEC cppVar_45067;
	BIT_VEC cppVar_45068;
	BIT_VEC cppVar_45069;
	BIT_VEC cppVar_45070;
	BIT_VEC cppVar_45072;
	BIT_VEC cppVar_45073;
	BIT_VEC cppVar_45074;
	BIT_VEC cppVar_45075;
	bool cppVar_45076;
	BIT_VEC cppVar_45078;
	BIT_VEC cppVar_45079;
	BIT_VEC cppVar_45080;
	BIT_VEC cppVar_45081;
	bool cppVar_45082;
	BIT_VEC cppVar_45084;
	BIT_VEC cppVar_45085;
	BIT_VEC cppVar_45086;
	BIT_VEC cppVar_45087;
	bool cppVar_45088;
	BIT_VEC cppVar_45090;
	BIT_VEC cppVar_45091;
	BIT_VEC cppVar_45092;
	BIT_VEC cppVar_45093;
	bool cppVar_45094;
	BIT_VEC cppVar_45096;
	BIT_VEC cppVar_45097;
	BIT_VEC cppVar_45098;
	BIT_VEC cppVar_45099;
	bool cppVar_45100;
	BIT_VEC cppVar_45102;
	BIT_VEC cppVar_45103;
	BIT_VEC cppVar_45104;
	BIT_VEC cppVar_45105;
	bool cppVar_45106;
	BIT_VEC cppVar_45108;
	BIT_VEC cppVar_45109;
	BIT_VEC cppVar_45110;
	BIT_VEC cppVar_45111;
	bool cppVar_45112;
	BIT_VEC cppVar_45114;
	BIT_VEC cppVar_45115;
	BIT_VEC cppVar_45116;
	BIT_VEC cppVar_45117;
	bool cppVar_45118;
	BIT_VEC cppVar_45120;
	BIT_VEC cppVar_45121;
	BIT_VEC cppVar_45122;
	BIT_VEC cppVar_45123;
	bool cppVar_45124;
	BIT_VEC cppVar_45126;
	BIT_VEC cppVar_45127;
	BIT_VEC cppVar_45128;
	BIT_VEC cppVar_45129;
	bool cppVar_45130;
	BIT_VEC cppVar_45132;
	BIT_VEC cppVar_45133;
	BIT_VEC cppVar_45134;
	BIT_VEC cppVar_45135;
	bool cppVar_45136;
	BIT_VEC cppVar_45138;
	BIT_VEC cppVar_45139;
	BIT_VEC cppVar_45140;
	BIT_VEC cppVar_45141;
	bool cppVar_45142;
	BIT_VEC cppVar_45144;
	BIT_VEC cppVar_45145;
	BIT_VEC cppVar_45146;
	BIT_VEC cppVar_45147;
	bool cppVar_45148;
	BIT_VEC cppVar_45150;
	BIT_VEC cppVar_45151;
	BIT_VEC cppVar_45152;
	BIT_VEC cppVar_45153;
	bool cppVar_45154;
	BIT_VEC cppVar_45156;
	BIT_VEC cppVar_45157;
	BIT_VEC cppVar_45158;
	BIT_VEC cppVar_45159;
	bool cppVar_45160;
	BIT_VEC cppVar_45162;
	BIT_VEC cppVar_45163;
	BIT_VEC cppVar_45164;
	BIT_VEC cppVar_45165;
	bool cppVar_45166;
	BIT_VEC cppVar_45168;
	BIT_VEC cppVar_45169;
	BIT_VEC cppVar_45170;
	BIT_VEC cppVar_45171;
	bool cppVar_45172;
	BIT_VEC cppVar_45174;
	BIT_VEC cppVar_45175;
	BIT_VEC cppVar_45176;
	BIT_VEC cppVar_45177;
	bool cppVar_45178;
	BIT_VEC cppVar_45180;
	BIT_VEC cppVar_45181;
	BIT_VEC cppVar_45182;
	BIT_VEC cppVar_45183;
	bool cppVar_45184;
	BIT_VEC cppVar_45186;
	BIT_VEC cppVar_45187;
	BIT_VEC cppVar_45188;
	BIT_VEC cppVar_45189;
	bool cppVar_45190;
	BIT_VEC cppVar_45192;
	BIT_VEC cppVar_45193;
	BIT_VEC cppVar_45194;
	BIT_VEC cppVar_45195;
	bool cppVar_45196;
	BIT_VEC cppVar_45197;
	BIT_VEC cppVar_45191;
	BIT_VEC cppVar_45185;
	BIT_VEC cppVar_45179;
	BIT_VEC cppVar_45173;
	BIT_VEC cppVar_45167;
	BIT_VEC cppVar_45161;
	BIT_VEC cppVar_45155;
	BIT_VEC cppVar_45149;
	BIT_VEC cppVar_45143;
	BIT_VEC cppVar_45137;
	BIT_VEC cppVar_45131;
	BIT_VEC cppVar_45125;
	BIT_VEC cppVar_45119;
	BIT_VEC cppVar_45113;
	BIT_VEC cppVar_45107;
	BIT_VEC cppVar_45101;
	BIT_VEC cppVar_45095;
	BIT_VEC cppVar_45089;
	BIT_VEC cppVar_45083;
	BIT_VEC cppVar_45077;
	BIT_VEC cppVar_45071;
	BIT_VEC cppVar_45058;
	BIT_VEC cppVar_45052;
	BIT_VEC cppVar_45199;
	BIT_VEC cppVar_45200;
	bool cppVar_45201;
	BIT_VEC cppVar_45203;
	BIT_VEC cppVar_45204;
	BIT_VEC cppVar_45205;
	BIT_VEC cppVar_45206;
	bool cppVar_45207;
	BIT_VEC cppVar_45209;
	BIT_VEC cppVar_45210;
	BIT_VEC cppVar_45211;
	BIT_VEC cppVar_45212;
	BIT_VEC cppVar_45213;
	BIT_VEC cppVar_45214;
	BIT_VEC cppVar_45215;
	bool cppVar_45216;
	BIT_VEC cppVar_45217;
	BIT_VEC cppVar_45218;
	BIT_VEC cppVar_45219;
	BIT_VEC cppVar_45220;
	BIT_VEC cppVar_45222;
	BIT_VEC cppVar_45223;
	BIT_VEC cppVar_45224;
	BIT_VEC cppVar_45225;
	bool cppVar_45226;
	BIT_VEC cppVar_45228;
	BIT_VEC cppVar_45229;
	BIT_VEC cppVar_45230;
	BIT_VEC cppVar_45231;
	bool cppVar_45232;
	BIT_VEC cppVar_45234;
	BIT_VEC cppVar_45235;
	BIT_VEC cppVar_45236;
	BIT_VEC cppVar_45237;
	bool cppVar_45238;
	BIT_VEC cppVar_45240;
	BIT_VEC cppVar_45241;
	BIT_VEC cppVar_45242;
	BIT_VEC cppVar_45243;
	bool cppVar_45244;
	BIT_VEC cppVar_45246;
	BIT_VEC cppVar_45247;
	BIT_VEC cppVar_45248;
	BIT_VEC cppVar_45249;
	bool cppVar_45250;
	BIT_VEC cppVar_45252;
	BIT_VEC cppVar_45253;
	BIT_VEC cppVar_45254;
	BIT_VEC cppVar_45255;
	bool cppVar_45256;
	BIT_VEC cppVar_45258;
	BIT_VEC cppVar_45259;
	BIT_VEC cppVar_45260;
	BIT_VEC cppVar_45261;
	bool cppVar_45262;
	BIT_VEC cppVar_45264;
	BIT_VEC cppVar_45265;
	BIT_VEC cppVar_45266;
	BIT_VEC cppVar_45267;
	bool cppVar_45268;
	BIT_VEC cppVar_45270;
	BIT_VEC cppVar_45271;
	BIT_VEC cppVar_45272;
	BIT_VEC cppVar_45273;
	bool cppVar_45274;
	BIT_VEC cppVar_45276;
	BIT_VEC cppVar_45277;
	BIT_VEC cppVar_45278;
	BIT_VEC cppVar_45279;
	bool cppVar_45280;
	BIT_VEC cppVar_45282;
	BIT_VEC cppVar_45283;
	BIT_VEC cppVar_45284;
	BIT_VEC cppVar_45285;
	bool cppVar_45286;
	BIT_VEC cppVar_45288;
	BIT_VEC cppVar_45289;
	BIT_VEC cppVar_45290;
	BIT_VEC cppVar_45291;
	bool cppVar_45292;
	BIT_VEC cppVar_45294;
	BIT_VEC cppVar_45295;
	BIT_VEC cppVar_45296;
	BIT_VEC cppVar_45297;
	bool cppVar_45298;
	BIT_VEC cppVar_45300;
	BIT_VEC cppVar_45301;
	BIT_VEC cppVar_45302;
	BIT_VEC cppVar_45303;
	bool cppVar_45304;
	BIT_VEC cppVar_45306;
	BIT_VEC cppVar_45307;
	BIT_VEC cppVar_45308;
	BIT_VEC cppVar_45309;
	bool cppVar_45310;
	BIT_VEC cppVar_45312;
	BIT_VEC cppVar_45313;
	BIT_VEC cppVar_45314;
	BIT_VEC cppVar_45315;
	bool cppVar_45316;
	BIT_VEC cppVar_45318;
	BIT_VEC cppVar_45319;
	BIT_VEC cppVar_45320;
	BIT_VEC cppVar_45321;
	bool cppVar_45322;
	BIT_VEC cppVar_45324;
	BIT_VEC cppVar_45325;
	BIT_VEC cppVar_45326;
	BIT_VEC cppVar_45327;
	bool cppVar_45328;
	BIT_VEC cppVar_45330;
	BIT_VEC cppVar_45331;
	BIT_VEC cppVar_45332;
	BIT_VEC cppVar_45333;
	bool cppVar_45334;
	BIT_VEC cppVar_45336;
	BIT_VEC cppVar_45337;
	BIT_VEC cppVar_45338;
	BIT_VEC cppVar_45339;
	bool cppVar_45340;
	BIT_VEC cppVar_45342;
	BIT_VEC cppVar_45343;
	BIT_VEC cppVar_45344;
	BIT_VEC cppVar_45345;
	bool cppVar_45346;
	BIT_VEC cppVar_45347;
	BIT_VEC cppVar_45341;
	BIT_VEC cppVar_45335;
	BIT_VEC cppVar_45329;
	BIT_VEC cppVar_45323;
	BIT_VEC cppVar_45317;
	BIT_VEC cppVar_45311;
	BIT_VEC cppVar_45305;
	BIT_VEC cppVar_45299;
	BIT_VEC cppVar_45293;
	BIT_VEC cppVar_45287;
	BIT_VEC cppVar_45281;
	BIT_VEC cppVar_45275;
	BIT_VEC cppVar_45269;
	BIT_VEC cppVar_45263;
	BIT_VEC cppVar_45257;
	BIT_VEC cppVar_45251;
	BIT_VEC cppVar_45245;
	BIT_VEC cppVar_45239;
	BIT_VEC cppVar_45233;
	BIT_VEC cppVar_45227;
	BIT_VEC cppVar_45221;
	BIT_VEC cppVar_45208;
	BIT_VEC cppVar_45202;
	BIT_VEC cppVar_45349;
	BIT_VEC cppVar_45350;
	bool cppVar_45351;
	BIT_VEC cppVar_45353;
	BIT_VEC cppVar_45354;
	BIT_VEC cppVar_45355;
	BIT_VEC cppVar_45356;
	bool cppVar_45357;
	BIT_VEC cppVar_45359;
	BIT_VEC cppVar_45360;
	BIT_VEC cppVar_45361;
	BIT_VEC cppVar_45362;
	BIT_VEC cppVar_45363;
	BIT_VEC cppVar_45364;
	BIT_VEC cppVar_45365;
	bool cppVar_45366;
	BIT_VEC cppVar_45367;
	BIT_VEC cppVar_45368;
	BIT_VEC cppVar_45369;
	BIT_VEC cppVar_45370;
	BIT_VEC cppVar_45372;
	BIT_VEC cppVar_45373;
	BIT_VEC cppVar_45374;
	BIT_VEC cppVar_45375;
	bool cppVar_45376;
	BIT_VEC cppVar_45378;
	BIT_VEC cppVar_45379;
	BIT_VEC cppVar_45380;
	BIT_VEC cppVar_45381;
	bool cppVar_45382;
	BIT_VEC cppVar_45384;
	BIT_VEC cppVar_45385;
	BIT_VEC cppVar_45386;
	BIT_VEC cppVar_45387;
	bool cppVar_45388;
	BIT_VEC cppVar_45390;
	BIT_VEC cppVar_45391;
	BIT_VEC cppVar_45392;
	BIT_VEC cppVar_45393;
	bool cppVar_45394;
	BIT_VEC cppVar_45396;
	BIT_VEC cppVar_45397;
	BIT_VEC cppVar_45398;
	BIT_VEC cppVar_45399;
	bool cppVar_45400;
	BIT_VEC cppVar_45402;
	BIT_VEC cppVar_45403;
	BIT_VEC cppVar_45404;
	BIT_VEC cppVar_45405;
	bool cppVar_45406;
	BIT_VEC cppVar_45408;
	BIT_VEC cppVar_45409;
	BIT_VEC cppVar_45410;
	BIT_VEC cppVar_45411;
	bool cppVar_45412;
	BIT_VEC cppVar_45414;
	BIT_VEC cppVar_45415;
	BIT_VEC cppVar_45416;
	BIT_VEC cppVar_45417;
	bool cppVar_45418;
	BIT_VEC cppVar_45420;
	BIT_VEC cppVar_45421;
	BIT_VEC cppVar_45422;
	BIT_VEC cppVar_45423;
	bool cppVar_45424;
	BIT_VEC cppVar_45426;
	BIT_VEC cppVar_45427;
	BIT_VEC cppVar_45428;
	BIT_VEC cppVar_45429;
	bool cppVar_45430;
	BIT_VEC cppVar_45432;
	BIT_VEC cppVar_45433;
	BIT_VEC cppVar_45434;
	BIT_VEC cppVar_45435;
	bool cppVar_45436;
	BIT_VEC cppVar_45438;
	BIT_VEC cppVar_45439;
	BIT_VEC cppVar_45440;
	BIT_VEC cppVar_45441;
	bool cppVar_45442;
	BIT_VEC cppVar_45444;
	BIT_VEC cppVar_45445;
	BIT_VEC cppVar_45446;
	BIT_VEC cppVar_45447;
	bool cppVar_45448;
	BIT_VEC cppVar_45450;
	BIT_VEC cppVar_45451;
	BIT_VEC cppVar_45452;
	BIT_VEC cppVar_45453;
	bool cppVar_45454;
	BIT_VEC cppVar_45456;
	BIT_VEC cppVar_45457;
	BIT_VEC cppVar_45458;
	BIT_VEC cppVar_45459;
	bool cppVar_45460;
	BIT_VEC cppVar_45462;
	BIT_VEC cppVar_45463;
	BIT_VEC cppVar_45464;
	BIT_VEC cppVar_45465;
	bool cppVar_45466;
	BIT_VEC cppVar_45468;
	BIT_VEC cppVar_45469;
	BIT_VEC cppVar_45470;
	BIT_VEC cppVar_45471;
	bool cppVar_45472;
	BIT_VEC cppVar_45474;
	BIT_VEC cppVar_45475;
	BIT_VEC cppVar_45476;
	BIT_VEC cppVar_45477;
	bool cppVar_45478;
	BIT_VEC cppVar_45480;
	BIT_VEC cppVar_45481;
	BIT_VEC cppVar_45482;
	BIT_VEC cppVar_45483;
	bool cppVar_45484;
	BIT_VEC cppVar_45486;
	BIT_VEC cppVar_45487;
	BIT_VEC cppVar_45488;
	BIT_VEC cppVar_45489;
	bool cppVar_45490;
	BIT_VEC cppVar_45492;
	BIT_VEC cppVar_45493;
	BIT_VEC cppVar_45494;
	BIT_VEC cppVar_45495;
	bool cppVar_45496;
	BIT_VEC cppVar_45497;
	BIT_VEC cppVar_45491;
	BIT_VEC cppVar_45485;
	BIT_VEC cppVar_45479;
	BIT_VEC cppVar_45473;
	BIT_VEC cppVar_45467;
	BIT_VEC cppVar_45461;
	BIT_VEC cppVar_45455;
	BIT_VEC cppVar_45449;
	BIT_VEC cppVar_45443;
	BIT_VEC cppVar_45437;
	BIT_VEC cppVar_45431;
	BIT_VEC cppVar_45425;
	BIT_VEC cppVar_45419;
	BIT_VEC cppVar_45413;
	BIT_VEC cppVar_45407;
	BIT_VEC cppVar_45401;
	BIT_VEC cppVar_45395;
	BIT_VEC cppVar_45389;
	BIT_VEC cppVar_45383;
	BIT_VEC cppVar_45377;
	BIT_VEC cppVar_45371;
	BIT_VEC cppVar_45358;
	BIT_VEC cppVar_45352;
	BIT_VEC cppVar_45499;
	BIT_VEC cppVar_45500;
	bool cppVar_45501;
	BIT_VEC cppVar_45503;
	BIT_VEC cppVar_45504;
	BIT_VEC cppVar_45505;
	BIT_VEC cppVar_45506;
	bool cppVar_45507;
	BIT_VEC cppVar_45508;
	BIT_VEC cppVar_45509;
	BIT_VEC cppVar_45510;
	BIT_VEC cppVar_45511;
	BIT_VEC cppVar_45512;
	BIT_VEC cppVar_45513;
	BIT_VEC cppVar_45514;
	BIT_VEC cppVar_45502;
	BIT_VEC cppVar_45516;
	BIT_VEC cppVar_45517;
	bool cppVar_45518;
	BIT_VEC cppVar_45520;
	BIT_VEC cppVar_45521;
	BIT_VEC cppVar_45522;
	BIT_VEC cppVar_45523;
	bool cppVar_45524;
	BIT_VEC cppVar_45525;
	BIT_VEC cppVar_45526;
	BIT_VEC cppVar_45527;
	BIT_VEC cppVar_45528;
	BIT_VEC cppVar_45529;
	BIT_VEC cppVar_45530;
	BIT_VEC cppVar_45531;
	BIT_VEC cppVar_45519;
	BIT_VEC cppVar_45533;
	BIT_VEC cppVar_45534;
	bool cppVar_45535;
	BIT_VEC cppVar_45537;
	BIT_VEC cppVar_45538;
	BIT_VEC cppVar_45539;
	BIT_VEC cppVar_45540;
	bool cppVar_45541;
	BIT_VEC cppVar_45543;
	BIT_VEC cppVar_45544;
	BIT_VEC cppVar_45545;
	BIT_VEC cppVar_45546;
	BIT_VEC cppVar_45547;
	bool cppVar_45548;
	BIT_VEC cppVar_45549;
	BIT_VEC cppVar_45550;
	BIT_VEC cppVar_45551;
	BIT_VEC cppVar_45553;
	BIT_VEC cppVar_45554;
	BIT_VEC cppVar_45555;
	bool cppVar_45556;
	BIT_VEC cppVar_45558;
	BIT_VEC cppVar_45559;
	BIT_VEC cppVar_45560;
	bool cppVar_45561;
	BIT_VEC cppVar_45563;
	BIT_VEC cppVar_45564;
	BIT_VEC cppVar_45565;
	bool cppVar_45566;
	BIT_VEC cppVar_45568;
	BIT_VEC cppVar_45569;
	BIT_VEC cppVar_45570;
	bool cppVar_45571;
	BIT_VEC cppVar_45573;
	BIT_VEC cppVar_45574;
	BIT_VEC cppVar_45575;
	bool cppVar_45576;
	BIT_VEC cppVar_45578;
	BIT_VEC cppVar_45579;
	BIT_VEC cppVar_45580;
	bool cppVar_45581;
	BIT_VEC cppVar_45583;
	BIT_VEC cppVar_45584;
	BIT_VEC cppVar_45585;
	bool cppVar_45586;
	BIT_VEC cppVar_45588;
	BIT_VEC cppVar_45589;
	BIT_VEC cppVar_45590;
	bool cppVar_45591;
	BIT_VEC cppVar_45593;
	BIT_VEC cppVar_45594;
	BIT_VEC cppVar_45595;
	bool cppVar_45596;
	BIT_VEC cppVar_45598;
	BIT_VEC cppVar_45599;
	BIT_VEC cppVar_45600;
	bool cppVar_45601;
	BIT_VEC cppVar_45603;
	BIT_VEC cppVar_45604;
	BIT_VEC cppVar_45605;
	bool cppVar_45606;
	BIT_VEC cppVar_45608;
	BIT_VEC cppVar_45609;
	BIT_VEC cppVar_45610;
	bool cppVar_45611;
	BIT_VEC cppVar_45613;
	BIT_VEC cppVar_45614;
	BIT_VEC cppVar_45615;
	bool cppVar_45616;
	BIT_VEC cppVar_45618;
	BIT_VEC cppVar_45619;
	BIT_VEC cppVar_45620;
	bool cppVar_45621;
	BIT_VEC cppVar_45623;
	BIT_VEC cppVar_45624;
	BIT_VEC cppVar_45625;
	bool cppVar_45626;
	BIT_VEC cppVar_45628;
	BIT_VEC cppVar_45629;
	BIT_VEC cppVar_45630;
	bool cppVar_45631;
	BIT_VEC cppVar_45633;
	BIT_VEC cppVar_45634;
	BIT_VEC cppVar_45635;
	bool cppVar_45636;
	BIT_VEC cppVar_45638;
	BIT_VEC cppVar_45639;
	BIT_VEC cppVar_45640;
	bool cppVar_45641;
	BIT_VEC cppVar_45643;
	BIT_VEC cppVar_45644;
	BIT_VEC cppVar_45645;
	bool cppVar_45646;
	BIT_VEC cppVar_45648;
	BIT_VEC cppVar_45649;
	BIT_VEC cppVar_45650;
	bool cppVar_45651;
	BIT_VEC cppVar_45653;
	BIT_VEC cppVar_45654;
	BIT_VEC cppVar_45655;
	bool cppVar_45656;
	BIT_VEC cppVar_45657;
	BIT_VEC cppVar_45652;
	BIT_VEC cppVar_45647;
	BIT_VEC cppVar_45642;
	BIT_VEC cppVar_45637;
	BIT_VEC cppVar_45632;
	BIT_VEC cppVar_45627;
	BIT_VEC cppVar_45622;
	BIT_VEC cppVar_45617;
	BIT_VEC cppVar_45612;
	BIT_VEC cppVar_45607;
	BIT_VEC cppVar_45602;
	BIT_VEC cppVar_45597;
	BIT_VEC cppVar_45592;
	BIT_VEC cppVar_45587;
	BIT_VEC cppVar_45582;
	BIT_VEC cppVar_45577;
	BIT_VEC cppVar_45572;
	BIT_VEC cppVar_45567;
	BIT_VEC cppVar_45562;
	BIT_VEC cppVar_45557;
	BIT_VEC cppVar_45552;
	BIT_VEC cppVar_45542;
	BIT_VEC cppVar_45536;
	BIT_VEC cppVar_45659;
	BIT_VEC cppVar_45660;
	bool cppVar_45661;
	BIT_VEC cppVar_45663;
	BIT_VEC cppVar_45664;
	BIT_VEC cppVar_45665;
	BIT_VEC cppVar_45666;
	bool cppVar_45667;
	BIT_VEC cppVar_45668;
	BIT_VEC cppVar_45669;
	BIT_VEC cppVar_45670;
	BIT_VEC cppVar_45662;
	BIT_VEC cppVar_45672;
	BIT_VEC cppVar_45673;
	bool cppVar_45674;
	BIT_VEC cppVar_45676;
	BIT_VEC cppVar_45677;
	BIT_VEC cppVar_45678;
	BIT_VEC cppVar_45679;
	bool cppVar_45680;
	BIT_VEC cppVar_45682;
	BIT_VEC cppVar_45683;
	BIT_VEC cppVar_45684;
	BIT_VEC cppVar_45685;
	bool cppVar_45686;
	BIT_VEC cppVar_45687;
	BIT_VEC cppVar_45688;
	BIT_VEC cppVar_45689;
	BIT_VEC cppVar_45691;
	BIT_VEC cppVar_45692;
	BIT_VEC cppVar_45693;
	bool cppVar_45694;
	BIT_VEC cppVar_45696;
	BIT_VEC cppVar_45697;
	BIT_VEC cppVar_45698;
	bool cppVar_45699;
	BIT_VEC cppVar_45701;
	BIT_VEC cppVar_45702;
	BIT_VEC cppVar_45703;
	bool cppVar_45704;
	BIT_VEC cppVar_45706;
	BIT_VEC cppVar_45707;
	BIT_VEC cppVar_45708;
	bool cppVar_45709;
	BIT_VEC cppVar_45711;
	BIT_VEC cppVar_45712;
	BIT_VEC cppVar_45713;
	bool cppVar_45714;
	BIT_VEC cppVar_45716;
	BIT_VEC cppVar_45717;
	BIT_VEC cppVar_45718;
	bool cppVar_45719;
	BIT_VEC cppVar_45721;
	BIT_VEC cppVar_45722;
	BIT_VEC cppVar_45723;
	bool cppVar_45724;
	BIT_VEC cppVar_45726;
	BIT_VEC cppVar_45727;
	BIT_VEC cppVar_45728;
	bool cppVar_45729;
	BIT_VEC cppVar_45731;
	BIT_VEC cppVar_45732;
	BIT_VEC cppVar_45733;
	bool cppVar_45734;
	BIT_VEC cppVar_45736;
	BIT_VEC cppVar_45737;
	BIT_VEC cppVar_45738;
	bool cppVar_45739;
	BIT_VEC cppVar_45741;
	BIT_VEC cppVar_45742;
	BIT_VEC cppVar_45743;
	bool cppVar_45744;
	BIT_VEC cppVar_45746;
	BIT_VEC cppVar_45747;
	BIT_VEC cppVar_45748;
	bool cppVar_45749;
	BIT_VEC cppVar_45751;
	BIT_VEC cppVar_45752;
	BIT_VEC cppVar_45753;
	bool cppVar_45754;
	BIT_VEC cppVar_45756;
	BIT_VEC cppVar_45757;
	BIT_VEC cppVar_45758;
	bool cppVar_45759;
	BIT_VEC cppVar_45761;
	BIT_VEC cppVar_45762;
	BIT_VEC cppVar_45763;
	bool cppVar_45764;
	BIT_VEC cppVar_45766;
	BIT_VEC cppVar_45767;
	BIT_VEC cppVar_45768;
	bool cppVar_45769;
	BIT_VEC cppVar_45771;
	BIT_VEC cppVar_45772;
	BIT_VEC cppVar_45773;
	bool cppVar_45774;
	BIT_VEC cppVar_45776;
	BIT_VEC cppVar_45777;
	BIT_VEC cppVar_45778;
	bool cppVar_45779;
	BIT_VEC cppVar_45781;
	BIT_VEC cppVar_45782;
	BIT_VEC cppVar_45783;
	bool cppVar_45784;
	BIT_VEC cppVar_45786;
	BIT_VEC cppVar_45787;
	BIT_VEC cppVar_45788;
	bool cppVar_45789;
	BIT_VEC cppVar_45791;
	BIT_VEC cppVar_45792;
	BIT_VEC cppVar_45793;
	bool cppVar_45794;
	BIT_VEC cppVar_45795;
	BIT_VEC cppVar_45790;
	BIT_VEC cppVar_45785;
	BIT_VEC cppVar_45780;
	BIT_VEC cppVar_45775;
	BIT_VEC cppVar_45770;
	BIT_VEC cppVar_45765;
	BIT_VEC cppVar_45760;
	BIT_VEC cppVar_45755;
	BIT_VEC cppVar_45750;
	BIT_VEC cppVar_45745;
	BIT_VEC cppVar_45740;
	BIT_VEC cppVar_45735;
	BIT_VEC cppVar_45730;
	BIT_VEC cppVar_45725;
	BIT_VEC cppVar_45720;
	BIT_VEC cppVar_45715;
	BIT_VEC cppVar_45710;
	BIT_VEC cppVar_45705;
	BIT_VEC cppVar_45700;
	BIT_VEC cppVar_45695;
	BIT_VEC cppVar_45690;
	BIT_VEC cppVar_45681;
	BIT_VEC cppVar_45796;
	BIT_VEC cppVar_45797;
	BIT_VEC cppVar_45798;
	BIT_VEC cppVar_45799;
	BIT_VEC cppVar_45675;
	BIT_VEC cppVar_45801;
	BIT_VEC cppVar_45802;
	bool cppVar_45803;
	BIT_VEC cppVar_45805;
	BIT_VEC cppVar_45806;
	BIT_VEC cppVar_45807;
	BIT_VEC cppVar_45808;
	bool cppVar_45809;
	BIT_VEC cppVar_45811;
	BIT_VEC cppVar_45812;
	BIT_VEC cppVar_45813;
	BIT_VEC cppVar_45814;
	bool cppVar_45815;
	BIT_VEC cppVar_45816;
	BIT_VEC cppVar_45817;
	BIT_VEC cppVar_45818;
	BIT_VEC cppVar_45820;
	BIT_VEC cppVar_45821;
	BIT_VEC cppVar_45822;
	bool cppVar_45823;
	BIT_VEC cppVar_45825;
	BIT_VEC cppVar_45826;
	BIT_VEC cppVar_45827;
	bool cppVar_45828;
	BIT_VEC cppVar_45830;
	BIT_VEC cppVar_45831;
	BIT_VEC cppVar_45832;
	bool cppVar_45833;
	BIT_VEC cppVar_45835;
	BIT_VEC cppVar_45836;
	BIT_VEC cppVar_45837;
	bool cppVar_45838;
	BIT_VEC cppVar_45840;
	BIT_VEC cppVar_45841;
	BIT_VEC cppVar_45842;
	bool cppVar_45843;
	BIT_VEC cppVar_45845;
	BIT_VEC cppVar_45846;
	BIT_VEC cppVar_45847;
	bool cppVar_45848;
	BIT_VEC cppVar_45850;
	BIT_VEC cppVar_45851;
	BIT_VEC cppVar_45852;
	bool cppVar_45853;
	BIT_VEC cppVar_45855;
	BIT_VEC cppVar_45856;
	BIT_VEC cppVar_45857;
	bool cppVar_45858;
	BIT_VEC cppVar_45860;
	BIT_VEC cppVar_45861;
	BIT_VEC cppVar_45862;
	bool cppVar_45863;
	BIT_VEC cppVar_45865;
	BIT_VEC cppVar_45866;
	BIT_VEC cppVar_45867;
	bool cppVar_45868;
	BIT_VEC cppVar_45870;
	BIT_VEC cppVar_45871;
	BIT_VEC cppVar_45872;
	bool cppVar_45873;
	BIT_VEC cppVar_45875;
	BIT_VEC cppVar_45876;
	BIT_VEC cppVar_45877;
	bool cppVar_45878;
	BIT_VEC cppVar_45880;
	BIT_VEC cppVar_45881;
	BIT_VEC cppVar_45882;
	bool cppVar_45883;
	BIT_VEC cppVar_45885;
	BIT_VEC cppVar_45886;
	BIT_VEC cppVar_45887;
	bool cppVar_45888;
	BIT_VEC cppVar_45890;
	BIT_VEC cppVar_45891;
	BIT_VEC cppVar_45892;
	bool cppVar_45893;
	BIT_VEC cppVar_45895;
	BIT_VEC cppVar_45896;
	BIT_VEC cppVar_45897;
	bool cppVar_45898;
	BIT_VEC cppVar_45900;
	BIT_VEC cppVar_45901;
	BIT_VEC cppVar_45902;
	bool cppVar_45903;
	BIT_VEC cppVar_45905;
	BIT_VEC cppVar_45906;
	BIT_VEC cppVar_45907;
	bool cppVar_45908;
	BIT_VEC cppVar_45910;
	BIT_VEC cppVar_45911;
	BIT_VEC cppVar_45912;
	bool cppVar_45913;
	BIT_VEC cppVar_45915;
	BIT_VEC cppVar_45916;
	BIT_VEC cppVar_45917;
	bool cppVar_45918;
	BIT_VEC cppVar_45920;
	BIT_VEC cppVar_45921;
	BIT_VEC cppVar_45922;
	bool cppVar_45923;
	BIT_VEC cppVar_45924;
	BIT_VEC cppVar_45919;
	BIT_VEC cppVar_45914;
	BIT_VEC cppVar_45909;
	BIT_VEC cppVar_45904;
	BIT_VEC cppVar_45899;
	BIT_VEC cppVar_45894;
	BIT_VEC cppVar_45889;
	BIT_VEC cppVar_45884;
	BIT_VEC cppVar_45879;
	BIT_VEC cppVar_45874;
	BIT_VEC cppVar_45869;
	BIT_VEC cppVar_45864;
	BIT_VEC cppVar_45859;
	BIT_VEC cppVar_45854;
	BIT_VEC cppVar_45849;
	BIT_VEC cppVar_45844;
	BIT_VEC cppVar_45839;
	BIT_VEC cppVar_45834;
	BIT_VEC cppVar_45829;
	BIT_VEC cppVar_45824;
	BIT_VEC cppVar_45819;
	BIT_VEC cppVar_45810;
	BIT_VEC cppVar_45925;
	BIT_VEC cppVar_45804;
	BIT_VEC cppVar_45927;
	BIT_VEC cppVar_45928;
	bool cppVar_45929;
	BIT_VEC cppVar_45931;
	BIT_VEC cppVar_45932;
	BIT_VEC cppVar_45933;
	BIT_VEC cppVar_45934;
	bool cppVar_45935;
	BIT_VEC cppVar_45937;
	BIT_VEC cppVar_45938;
	BIT_VEC cppVar_45939;
	BIT_VEC cppVar_45940;
	bool cppVar_45941;
	BIT_VEC cppVar_45942;
	BIT_VEC cppVar_45943;
	BIT_VEC cppVar_45944;
	BIT_VEC cppVar_45946;
	BIT_VEC cppVar_45947;
	BIT_VEC cppVar_45948;
	bool cppVar_45949;
	BIT_VEC cppVar_45951;
	BIT_VEC cppVar_45952;
	BIT_VEC cppVar_45953;
	bool cppVar_45954;
	BIT_VEC cppVar_45956;
	BIT_VEC cppVar_45957;
	BIT_VEC cppVar_45958;
	bool cppVar_45959;
	BIT_VEC cppVar_45961;
	BIT_VEC cppVar_45962;
	BIT_VEC cppVar_45963;
	bool cppVar_45964;
	BIT_VEC cppVar_45966;
	BIT_VEC cppVar_45967;
	BIT_VEC cppVar_45968;
	bool cppVar_45969;
	BIT_VEC cppVar_45971;
	BIT_VEC cppVar_45972;
	BIT_VEC cppVar_45973;
	bool cppVar_45974;
	BIT_VEC cppVar_45976;
	BIT_VEC cppVar_45977;
	BIT_VEC cppVar_45978;
	bool cppVar_45979;
	BIT_VEC cppVar_45981;
	BIT_VEC cppVar_45982;
	BIT_VEC cppVar_45983;
	bool cppVar_45984;
	BIT_VEC cppVar_45986;
	BIT_VEC cppVar_45987;
	BIT_VEC cppVar_45988;
	bool cppVar_45989;
	BIT_VEC cppVar_45991;
	BIT_VEC cppVar_45992;
	BIT_VEC cppVar_45993;
	bool cppVar_45994;
	BIT_VEC cppVar_45996;
	BIT_VEC cppVar_45997;
	BIT_VEC cppVar_45998;
	bool cppVar_45999;
	BIT_VEC cppVar_46001;
	BIT_VEC cppVar_46002;
	BIT_VEC cppVar_46003;
	bool cppVar_46004;
	BIT_VEC cppVar_46006;
	BIT_VEC cppVar_46007;
	BIT_VEC cppVar_46008;
	bool cppVar_46009;
	BIT_VEC cppVar_46011;
	BIT_VEC cppVar_46012;
	BIT_VEC cppVar_46013;
	bool cppVar_46014;
	BIT_VEC cppVar_46016;
	BIT_VEC cppVar_46017;
	BIT_VEC cppVar_46018;
	bool cppVar_46019;
	BIT_VEC cppVar_46021;
	BIT_VEC cppVar_46022;
	BIT_VEC cppVar_46023;
	bool cppVar_46024;
	BIT_VEC cppVar_46026;
	BIT_VEC cppVar_46027;
	BIT_VEC cppVar_46028;
	bool cppVar_46029;
	BIT_VEC cppVar_46031;
	BIT_VEC cppVar_46032;
	BIT_VEC cppVar_46033;
	bool cppVar_46034;
	BIT_VEC cppVar_46036;
	BIT_VEC cppVar_46037;
	BIT_VEC cppVar_46038;
	bool cppVar_46039;
	BIT_VEC cppVar_46041;
	BIT_VEC cppVar_46042;
	BIT_VEC cppVar_46043;
	bool cppVar_46044;
	BIT_VEC cppVar_46046;
	BIT_VEC cppVar_46047;
	BIT_VEC cppVar_46048;
	bool cppVar_46049;
	BIT_VEC cppVar_46050;
	BIT_VEC cppVar_46045;
	BIT_VEC cppVar_46040;
	BIT_VEC cppVar_46035;
	BIT_VEC cppVar_46030;
	BIT_VEC cppVar_46025;
	BIT_VEC cppVar_46020;
	BIT_VEC cppVar_46015;
	BIT_VEC cppVar_46010;
	BIT_VEC cppVar_46005;
	BIT_VEC cppVar_46000;
	BIT_VEC cppVar_45995;
	BIT_VEC cppVar_45990;
	BIT_VEC cppVar_45985;
	BIT_VEC cppVar_45980;
	BIT_VEC cppVar_45975;
	BIT_VEC cppVar_45970;
	BIT_VEC cppVar_45965;
	BIT_VEC cppVar_45960;
	BIT_VEC cppVar_45955;
	BIT_VEC cppVar_45950;
	BIT_VEC cppVar_45945;
	BIT_VEC cppVar_45936;
	BIT_VEC cppVar_46051;
	BIT_VEC cppVar_46052;
	BIT_VEC cppVar_46053;
	BIT_VEC cppVar_46054;
	BIT_VEC cppVar_45930;
	BIT_VEC cppVar_46056;
	BIT_VEC cppVar_46057;
	bool cppVar_46058;
	BIT_VEC cppVar_46060;
	BIT_VEC cppVar_46061;
	BIT_VEC cppVar_46062;
	BIT_VEC cppVar_46063;
	bool cppVar_46064;
	BIT_VEC cppVar_46066;
	BIT_VEC cppVar_46067;
	BIT_VEC cppVar_46068;
	BIT_VEC cppVar_46069;
	bool cppVar_46070;
	BIT_VEC cppVar_46071;
	BIT_VEC cppVar_46072;
	BIT_VEC cppVar_46073;
	BIT_VEC cppVar_46075;
	BIT_VEC cppVar_46076;
	BIT_VEC cppVar_46077;
	bool cppVar_46078;
	BIT_VEC cppVar_46080;
	BIT_VEC cppVar_46081;
	BIT_VEC cppVar_46082;
	bool cppVar_46083;
	BIT_VEC cppVar_46085;
	BIT_VEC cppVar_46086;
	BIT_VEC cppVar_46087;
	bool cppVar_46088;
	BIT_VEC cppVar_46090;
	BIT_VEC cppVar_46091;
	BIT_VEC cppVar_46092;
	bool cppVar_46093;
	BIT_VEC cppVar_46095;
	BIT_VEC cppVar_46096;
	BIT_VEC cppVar_46097;
	bool cppVar_46098;
	BIT_VEC cppVar_46100;
	BIT_VEC cppVar_46101;
	BIT_VEC cppVar_46102;
	bool cppVar_46103;
	BIT_VEC cppVar_46105;
	BIT_VEC cppVar_46106;
	BIT_VEC cppVar_46107;
	bool cppVar_46108;
	BIT_VEC cppVar_46110;
	BIT_VEC cppVar_46111;
	BIT_VEC cppVar_46112;
	bool cppVar_46113;
	BIT_VEC cppVar_46115;
	BIT_VEC cppVar_46116;
	BIT_VEC cppVar_46117;
	bool cppVar_46118;
	BIT_VEC cppVar_46120;
	BIT_VEC cppVar_46121;
	BIT_VEC cppVar_46122;
	bool cppVar_46123;
	BIT_VEC cppVar_46125;
	BIT_VEC cppVar_46126;
	BIT_VEC cppVar_46127;
	bool cppVar_46128;
	BIT_VEC cppVar_46130;
	BIT_VEC cppVar_46131;
	BIT_VEC cppVar_46132;
	bool cppVar_46133;
	BIT_VEC cppVar_46135;
	BIT_VEC cppVar_46136;
	BIT_VEC cppVar_46137;
	bool cppVar_46138;
	BIT_VEC cppVar_46140;
	BIT_VEC cppVar_46141;
	BIT_VEC cppVar_46142;
	bool cppVar_46143;
	BIT_VEC cppVar_46145;
	BIT_VEC cppVar_46146;
	BIT_VEC cppVar_46147;
	bool cppVar_46148;
	BIT_VEC cppVar_46150;
	BIT_VEC cppVar_46151;
	BIT_VEC cppVar_46152;
	bool cppVar_46153;
	BIT_VEC cppVar_46155;
	BIT_VEC cppVar_46156;
	BIT_VEC cppVar_46157;
	bool cppVar_46158;
	BIT_VEC cppVar_46160;
	BIT_VEC cppVar_46161;
	BIT_VEC cppVar_46162;
	bool cppVar_46163;
	BIT_VEC cppVar_46165;
	BIT_VEC cppVar_46166;
	BIT_VEC cppVar_46167;
	bool cppVar_46168;
	BIT_VEC cppVar_46170;
	BIT_VEC cppVar_46171;
	BIT_VEC cppVar_46172;
	bool cppVar_46173;
	BIT_VEC cppVar_46175;
	BIT_VEC cppVar_46176;
	BIT_VEC cppVar_46177;
	bool cppVar_46178;
	BIT_VEC cppVar_46179;
	BIT_VEC cppVar_46174;
	BIT_VEC cppVar_46169;
	BIT_VEC cppVar_46164;
	BIT_VEC cppVar_46159;
	BIT_VEC cppVar_46154;
	BIT_VEC cppVar_46149;
	BIT_VEC cppVar_46144;
	BIT_VEC cppVar_46139;
	BIT_VEC cppVar_46134;
	BIT_VEC cppVar_46129;
	BIT_VEC cppVar_46124;
	BIT_VEC cppVar_46119;
	BIT_VEC cppVar_46114;
	BIT_VEC cppVar_46109;
	BIT_VEC cppVar_46104;
	BIT_VEC cppVar_46099;
	BIT_VEC cppVar_46094;
	BIT_VEC cppVar_46089;
	BIT_VEC cppVar_46084;
	BIT_VEC cppVar_46079;
	BIT_VEC cppVar_46074;
	BIT_VEC cppVar_46065;
	BIT_VEC cppVar_46180;
	BIT_VEC cppVar_46059;
	BIT_VEC cppVar_46182;
	BIT_VEC cppVar_46183;
	bool cppVar_46184;
	BIT_VEC cppVar_46186;
	BIT_VEC cppVar_46187;
	BIT_VEC cppVar_46188;
	BIT_VEC cppVar_46189;
	bool cppVar_46190;
	BIT_VEC cppVar_46192;
	BIT_VEC cppVar_46193;
	BIT_VEC cppVar_46194;
	BIT_VEC cppVar_46195;
	bool cppVar_46196;
	BIT_VEC cppVar_46197;
	BIT_VEC cppVar_46198;
	BIT_VEC cppVar_46199;
	BIT_VEC cppVar_46201;
	BIT_VEC cppVar_46202;
	BIT_VEC cppVar_46203;
	bool cppVar_46204;
	BIT_VEC cppVar_46206;
	BIT_VEC cppVar_46207;
	BIT_VEC cppVar_46208;
	bool cppVar_46209;
	BIT_VEC cppVar_46211;
	BIT_VEC cppVar_46212;
	BIT_VEC cppVar_46213;
	bool cppVar_46214;
	BIT_VEC cppVar_46216;
	BIT_VEC cppVar_46217;
	BIT_VEC cppVar_46218;
	bool cppVar_46219;
	BIT_VEC cppVar_46221;
	BIT_VEC cppVar_46222;
	BIT_VEC cppVar_46223;
	bool cppVar_46224;
	BIT_VEC cppVar_46226;
	BIT_VEC cppVar_46227;
	BIT_VEC cppVar_46228;
	bool cppVar_46229;
	BIT_VEC cppVar_46231;
	BIT_VEC cppVar_46232;
	BIT_VEC cppVar_46233;
	bool cppVar_46234;
	BIT_VEC cppVar_46236;
	BIT_VEC cppVar_46237;
	BIT_VEC cppVar_46238;
	bool cppVar_46239;
	BIT_VEC cppVar_46241;
	BIT_VEC cppVar_46242;
	BIT_VEC cppVar_46243;
	bool cppVar_46244;
	BIT_VEC cppVar_46246;
	BIT_VEC cppVar_46247;
	BIT_VEC cppVar_46248;
	bool cppVar_46249;
	BIT_VEC cppVar_46251;
	BIT_VEC cppVar_46252;
	BIT_VEC cppVar_46253;
	bool cppVar_46254;
	BIT_VEC cppVar_46256;
	BIT_VEC cppVar_46257;
	BIT_VEC cppVar_46258;
	bool cppVar_46259;
	BIT_VEC cppVar_46261;
	BIT_VEC cppVar_46262;
	BIT_VEC cppVar_46263;
	bool cppVar_46264;
	BIT_VEC cppVar_46266;
	BIT_VEC cppVar_46267;
	BIT_VEC cppVar_46268;
	bool cppVar_46269;
	BIT_VEC cppVar_46271;
	BIT_VEC cppVar_46272;
	BIT_VEC cppVar_46273;
	bool cppVar_46274;
	BIT_VEC cppVar_46276;
	BIT_VEC cppVar_46277;
	BIT_VEC cppVar_46278;
	bool cppVar_46279;
	BIT_VEC cppVar_46281;
	BIT_VEC cppVar_46282;
	BIT_VEC cppVar_46283;
	bool cppVar_46284;
	BIT_VEC cppVar_46286;
	BIT_VEC cppVar_46287;
	BIT_VEC cppVar_46288;
	bool cppVar_46289;
	BIT_VEC cppVar_46291;
	BIT_VEC cppVar_46292;
	BIT_VEC cppVar_46293;
	bool cppVar_46294;
	BIT_VEC cppVar_46296;
	BIT_VEC cppVar_46297;
	BIT_VEC cppVar_46298;
	bool cppVar_46299;
	BIT_VEC cppVar_46301;
	BIT_VEC cppVar_46302;
	BIT_VEC cppVar_46303;
	bool cppVar_46304;
	BIT_VEC cppVar_46305;
	BIT_VEC cppVar_46300;
	BIT_VEC cppVar_46295;
	BIT_VEC cppVar_46290;
	BIT_VEC cppVar_46285;
	BIT_VEC cppVar_46280;
	BIT_VEC cppVar_46275;
	BIT_VEC cppVar_46270;
	BIT_VEC cppVar_46265;
	BIT_VEC cppVar_46260;
	BIT_VEC cppVar_46255;
	BIT_VEC cppVar_46250;
	BIT_VEC cppVar_46245;
	BIT_VEC cppVar_46240;
	BIT_VEC cppVar_46235;
	BIT_VEC cppVar_46230;
	BIT_VEC cppVar_46225;
	BIT_VEC cppVar_46220;
	BIT_VEC cppVar_46215;
	BIT_VEC cppVar_46210;
	BIT_VEC cppVar_46205;
	BIT_VEC cppVar_46200;
	BIT_VEC cppVar_46191;
	BIT_VEC cppVar_46306;
	BIT_VEC cppVar_46307;
	BIT_VEC cppVar_46308;
	BIT_VEC cppVar_46309;
	BIT_VEC cppVar_46185;
	BIT_VEC cppVar_46311;
	BIT_VEC cppVar_46312;
	bool cppVar_46313;
	BIT_VEC cppVar_46315;
	BIT_VEC cppVar_46316;
	BIT_VEC cppVar_46317;
	BIT_VEC cppVar_46318;
	bool cppVar_46319;
	BIT_VEC cppVar_46321;
	BIT_VEC cppVar_46322;
	BIT_VEC cppVar_46323;
	BIT_VEC cppVar_46324;
	bool cppVar_46325;
	BIT_VEC cppVar_46326;
	BIT_VEC cppVar_46327;
	BIT_VEC cppVar_46328;
	BIT_VEC cppVar_46330;
	BIT_VEC cppVar_46331;
	BIT_VEC cppVar_46332;
	bool cppVar_46333;
	BIT_VEC cppVar_46335;
	BIT_VEC cppVar_46336;
	BIT_VEC cppVar_46337;
	bool cppVar_46338;
	BIT_VEC cppVar_46340;
	BIT_VEC cppVar_46341;
	BIT_VEC cppVar_46342;
	bool cppVar_46343;
	BIT_VEC cppVar_46345;
	BIT_VEC cppVar_46346;
	BIT_VEC cppVar_46347;
	bool cppVar_46348;
	BIT_VEC cppVar_46350;
	BIT_VEC cppVar_46351;
	BIT_VEC cppVar_46352;
	bool cppVar_46353;
	BIT_VEC cppVar_46355;
	BIT_VEC cppVar_46356;
	BIT_VEC cppVar_46357;
	bool cppVar_46358;
	BIT_VEC cppVar_46360;
	BIT_VEC cppVar_46361;
	BIT_VEC cppVar_46362;
	bool cppVar_46363;
	BIT_VEC cppVar_46365;
	BIT_VEC cppVar_46366;
	BIT_VEC cppVar_46367;
	bool cppVar_46368;
	BIT_VEC cppVar_46370;
	BIT_VEC cppVar_46371;
	BIT_VEC cppVar_46372;
	bool cppVar_46373;
	BIT_VEC cppVar_46375;
	BIT_VEC cppVar_46376;
	BIT_VEC cppVar_46377;
	bool cppVar_46378;
	BIT_VEC cppVar_46380;
	BIT_VEC cppVar_46381;
	BIT_VEC cppVar_46382;
	bool cppVar_46383;
	BIT_VEC cppVar_46385;
	BIT_VEC cppVar_46386;
	BIT_VEC cppVar_46387;
	bool cppVar_46388;
	BIT_VEC cppVar_46390;
	BIT_VEC cppVar_46391;
	BIT_VEC cppVar_46392;
	bool cppVar_46393;
	BIT_VEC cppVar_46395;
	BIT_VEC cppVar_46396;
	BIT_VEC cppVar_46397;
	bool cppVar_46398;
	BIT_VEC cppVar_46400;
	BIT_VEC cppVar_46401;
	BIT_VEC cppVar_46402;
	bool cppVar_46403;
	BIT_VEC cppVar_46405;
	BIT_VEC cppVar_46406;
	BIT_VEC cppVar_46407;
	bool cppVar_46408;
	BIT_VEC cppVar_46410;
	BIT_VEC cppVar_46411;
	BIT_VEC cppVar_46412;
	bool cppVar_46413;
	BIT_VEC cppVar_46415;
	BIT_VEC cppVar_46416;
	BIT_VEC cppVar_46417;
	bool cppVar_46418;
	BIT_VEC cppVar_46420;
	BIT_VEC cppVar_46421;
	BIT_VEC cppVar_46422;
	bool cppVar_46423;
	BIT_VEC cppVar_46425;
	BIT_VEC cppVar_46426;
	BIT_VEC cppVar_46427;
	bool cppVar_46428;
	BIT_VEC cppVar_46430;
	BIT_VEC cppVar_46431;
	BIT_VEC cppVar_46432;
	bool cppVar_46433;
	BIT_VEC cppVar_46434;
	BIT_VEC cppVar_46429;
	BIT_VEC cppVar_46424;
	BIT_VEC cppVar_46419;
	BIT_VEC cppVar_46414;
	BIT_VEC cppVar_46409;
	BIT_VEC cppVar_46404;
	BIT_VEC cppVar_46399;
	BIT_VEC cppVar_46394;
	BIT_VEC cppVar_46389;
	BIT_VEC cppVar_46384;
	BIT_VEC cppVar_46379;
	BIT_VEC cppVar_46374;
	BIT_VEC cppVar_46369;
	BIT_VEC cppVar_46364;
	BIT_VEC cppVar_46359;
	BIT_VEC cppVar_46354;
	BIT_VEC cppVar_46349;
	BIT_VEC cppVar_46344;
	BIT_VEC cppVar_46339;
	BIT_VEC cppVar_46334;
	BIT_VEC cppVar_46329;
	BIT_VEC cppVar_46320;
	BIT_VEC cppVar_46435;
	BIT_VEC cppVar_46314;
	BIT_VEC cppVar_46437;
	BIT_VEC cppVar_46438;
	bool cppVar_46439;
	BIT_VEC cppVar_46440;
	BIT_VEC cppVar_46441;
	bool cppVar_46442;
	bool cppVar_46443;
	BIT_VEC cppVar_46445;
	BIT_VEC cppVar_46446;
	BIT_VEC cppVar_46447;
	BIT_VEC cppVar_46448;
	bool cppVar_46449;
	BIT_VEC cppVar_46451;
	BIT_VEC cppVar_46452;
	BIT_VEC cppVar_46453;
	BIT_VEC cppVar_46454;
	bool cppVar_46455;
	BIT_VEC cppVar_46456;
	BIT_VEC cppVar_46457;
	BIT_VEC cppVar_46458;
	BIT_VEC cppVar_46460;
	BIT_VEC cppVar_46461;
	BIT_VEC cppVar_46462;
	bool cppVar_46463;
	BIT_VEC cppVar_46465;
	BIT_VEC cppVar_46466;
	BIT_VEC cppVar_46467;
	bool cppVar_46468;
	BIT_VEC cppVar_46470;
	BIT_VEC cppVar_46471;
	BIT_VEC cppVar_46472;
	bool cppVar_46473;
	BIT_VEC cppVar_46475;
	BIT_VEC cppVar_46476;
	BIT_VEC cppVar_46477;
	bool cppVar_46478;
	BIT_VEC cppVar_46480;
	BIT_VEC cppVar_46481;
	BIT_VEC cppVar_46482;
	bool cppVar_46483;
	BIT_VEC cppVar_46485;
	BIT_VEC cppVar_46486;
	BIT_VEC cppVar_46487;
	bool cppVar_46488;
	BIT_VEC cppVar_46490;
	BIT_VEC cppVar_46491;
	BIT_VEC cppVar_46492;
	bool cppVar_46493;
	BIT_VEC cppVar_46495;
	BIT_VEC cppVar_46496;
	BIT_VEC cppVar_46497;
	bool cppVar_46498;
	BIT_VEC cppVar_46500;
	BIT_VEC cppVar_46501;
	BIT_VEC cppVar_46502;
	bool cppVar_46503;
	BIT_VEC cppVar_46505;
	BIT_VEC cppVar_46506;
	BIT_VEC cppVar_46507;
	bool cppVar_46508;
	BIT_VEC cppVar_46510;
	BIT_VEC cppVar_46511;
	BIT_VEC cppVar_46512;
	bool cppVar_46513;
	BIT_VEC cppVar_46515;
	BIT_VEC cppVar_46516;
	BIT_VEC cppVar_46517;
	bool cppVar_46518;
	BIT_VEC cppVar_46520;
	BIT_VEC cppVar_46521;
	BIT_VEC cppVar_46522;
	bool cppVar_46523;
	BIT_VEC cppVar_46525;
	BIT_VEC cppVar_46526;
	BIT_VEC cppVar_46527;
	bool cppVar_46528;
	BIT_VEC cppVar_46530;
	BIT_VEC cppVar_46531;
	BIT_VEC cppVar_46532;
	bool cppVar_46533;
	BIT_VEC cppVar_46535;
	BIT_VEC cppVar_46536;
	BIT_VEC cppVar_46537;
	bool cppVar_46538;
	BIT_VEC cppVar_46540;
	BIT_VEC cppVar_46541;
	BIT_VEC cppVar_46542;
	bool cppVar_46543;
	BIT_VEC cppVar_46545;
	BIT_VEC cppVar_46546;
	BIT_VEC cppVar_46547;
	bool cppVar_46548;
	BIT_VEC cppVar_46550;
	BIT_VEC cppVar_46551;
	BIT_VEC cppVar_46552;
	bool cppVar_46553;
	BIT_VEC cppVar_46555;
	BIT_VEC cppVar_46556;
	BIT_VEC cppVar_46557;
	bool cppVar_46558;
	BIT_VEC cppVar_46560;
	BIT_VEC cppVar_46561;
	BIT_VEC cppVar_46562;
	bool cppVar_46563;
	BIT_VEC cppVar_46564;
	BIT_VEC cppVar_46559;
	BIT_VEC cppVar_46554;
	BIT_VEC cppVar_46549;
	BIT_VEC cppVar_46544;
	BIT_VEC cppVar_46539;
	BIT_VEC cppVar_46534;
	BIT_VEC cppVar_46529;
	BIT_VEC cppVar_46524;
	BIT_VEC cppVar_46519;
	BIT_VEC cppVar_46514;
	BIT_VEC cppVar_46509;
	BIT_VEC cppVar_46504;
	BIT_VEC cppVar_46499;
	BIT_VEC cppVar_46494;
	BIT_VEC cppVar_46489;
	BIT_VEC cppVar_46484;
	BIT_VEC cppVar_46479;
	BIT_VEC cppVar_46474;
	BIT_VEC cppVar_46469;
	BIT_VEC cppVar_46464;
	BIT_VEC cppVar_46459;
	BIT_VEC cppVar_46450;
	BIT_VEC cppVar_46565;
	BIT_VEC cppVar_46566;
	BIT_VEC cppVar_46444;
	BIT_VEC cppVar_46568;
	BIT_VEC cppVar_46569;
	bool cppVar_46570;
	BIT_VEC cppVar_46572;
	BIT_VEC cppVar_46573;
	BIT_VEC cppVar_46574;
	BIT_VEC cppVar_46575;
	bool cppVar_46576;
	BIT_VEC cppVar_46578;
	BIT_VEC cppVar_46579;
	BIT_VEC cppVar_46580;
	BIT_VEC cppVar_46581;
	bool cppVar_46582;
	BIT_VEC cppVar_46583;
	BIT_VEC cppVar_46584;
	BIT_VEC cppVar_46585;
	BIT_VEC cppVar_46587;
	BIT_VEC cppVar_46588;
	BIT_VEC cppVar_46589;
	bool cppVar_46590;
	BIT_VEC cppVar_46592;
	BIT_VEC cppVar_46593;
	BIT_VEC cppVar_46594;
	bool cppVar_46595;
	BIT_VEC cppVar_46597;
	BIT_VEC cppVar_46598;
	BIT_VEC cppVar_46599;
	bool cppVar_46600;
	BIT_VEC cppVar_46602;
	BIT_VEC cppVar_46603;
	BIT_VEC cppVar_46604;
	bool cppVar_46605;
	BIT_VEC cppVar_46607;
	BIT_VEC cppVar_46608;
	BIT_VEC cppVar_46609;
	bool cppVar_46610;
	BIT_VEC cppVar_46612;
	BIT_VEC cppVar_46613;
	BIT_VEC cppVar_46614;
	bool cppVar_46615;
	BIT_VEC cppVar_46617;
	BIT_VEC cppVar_46618;
	BIT_VEC cppVar_46619;
	bool cppVar_46620;
	BIT_VEC cppVar_46622;
	BIT_VEC cppVar_46623;
	BIT_VEC cppVar_46624;
	bool cppVar_46625;
	BIT_VEC cppVar_46627;
	BIT_VEC cppVar_46628;
	BIT_VEC cppVar_46629;
	bool cppVar_46630;
	BIT_VEC cppVar_46632;
	BIT_VEC cppVar_46633;
	BIT_VEC cppVar_46634;
	bool cppVar_46635;
	BIT_VEC cppVar_46637;
	BIT_VEC cppVar_46638;
	BIT_VEC cppVar_46639;
	bool cppVar_46640;
	BIT_VEC cppVar_46642;
	BIT_VEC cppVar_46643;
	BIT_VEC cppVar_46644;
	bool cppVar_46645;
	BIT_VEC cppVar_46647;
	BIT_VEC cppVar_46648;
	BIT_VEC cppVar_46649;
	bool cppVar_46650;
	BIT_VEC cppVar_46652;
	BIT_VEC cppVar_46653;
	BIT_VEC cppVar_46654;
	bool cppVar_46655;
	BIT_VEC cppVar_46657;
	BIT_VEC cppVar_46658;
	BIT_VEC cppVar_46659;
	bool cppVar_46660;
	BIT_VEC cppVar_46662;
	BIT_VEC cppVar_46663;
	BIT_VEC cppVar_46664;
	bool cppVar_46665;
	BIT_VEC cppVar_46667;
	BIT_VEC cppVar_46668;
	BIT_VEC cppVar_46669;
	bool cppVar_46670;
	BIT_VEC cppVar_46672;
	BIT_VEC cppVar_46673;
	BIT_VEC cppVar_46674;
	bool cppVar_46675;
	BIT_VEC cppVar_46677;
	BIT_VEC cppVar_46678;
	BIT_VEC cppVar_46679;
	bool cppVar_46680;
	BIT_VEC cppVar_46682;
	BIT_VEC cppVar_46683;
	BIT_VEC cppVar_46684;
	bool cppVar_46685;
	BIT_VEC cppVar_46687;
	BIT_VEC cppVar_46688;
	BIT_VEC cppVar_46689;
	bool cppVar_46690;
	BIT_VEC cppVar_46691;
	BIT_VEC cppVar_46686;
	BIT_VEC cppVar_46681;
	BIT_VEC cppVar_46676;
	BIT_VEC cppVar_46671;
	BIT_VEC cppVar_46666;
	BIT_VEC cppVar_46661;
	BIT_VEC cppVar_46656;
	BIT_VEC cppVar_46651;
	BIT_VEC cppVar_46646;
	BIT_VEC cppVar_46641;
	BIT_VEC cppVar_46636;
	BIT_VEC cppVar_46631;
	BIT_VEC cppVar_46626;
	BIT_VEC cppVar_46621;
	BIT_VEC cppVar_46616;
	BIT_VEC cppVar_46611;
	BIT_VEC cppVar_46606;
	BIT_VEC cppVar_46601;
	BIT_VEC cppVar_46596;
	BIT_VEC cppVar_46591;
	BIT_VEC cppVar_46586;
	BIT_VEC cppVar_46577;
	BIT_VEC cppVar_46692;
	BIT_VEC cppVar_46693;
	BIT_VEC cppVar_46571;
	BIT_VEC cppVar_46567;
	BIT_VEC cppVar_46436;
	BIT_VEC cppVar_46310;
	BIT_VEC cppVar_46181;
	BIT_VEC cppVar_46055;
	BIT_VEC cppVar_45926;
	BIT_VEC cppVar_45800;
	BIT_VEC cppVar_45671;
	BIT_VEC cppVar_45658;
	BIT_VEC cppVar_45532;
	BIT_VEC cppVar_45515;
	BIT_VEC cppVar_45498;
	BIT_VEC cppVar_45348;
	BIT_VEC cppVar_45198;
	BIT_VEC cppVar_45048;
	BIT_VEC cppVar_44898;
	BIT_VEC cppVar_44748;
	BIT_VEC cppVar_44598;
	BIT_VEC cppVar_44448;
	BIT_VEC cppVar_44298;
	BIT_VEC cppVar_44284;
	BIT_VEC cppVar_44273;
	cppVar_44274 = ROM.rd(PC);
	cppVar_44276 = (cppVar_44274 == 208);
	if (cppVar_44276) {
	cppVar_44279 = PC + 1;
	cppVar_44279 = (cppVar_44279 & cppMask_un_16_);
	cppVar_44280 = ROM.rd(cppVar_44279);
	cppVar_44282 = (cppVar_44280 == 135);
	if (cppVar_44282) {
	cppVar_44283 = IRAM.rd(SP);
	cppVar_44277 = cppVar_44283;
	} else {
	cppVar_44277 = PCON;
	}
	cppVar_44273 = cppVar_44277;
	} else {
	cppVar_44285 = ROM.rd(PC);
	cppVar_44287 = (cppVar_44285 == 245);
	cppVar_44288 = ROM.rd(PC);
	cppVar_44290 = (cppVar_44288 == 197);
	cppVar_44291 = cppVar_44287 || cppVar_44290;
	if (cppVar_44291) {
	cppVar_44294 = PC + 1;
	cppVar_44294 = (cppVar_44294 & cppMask_un_16_);
	cppVar_44295 = ROM.rd(cppVar_44294);
	cppVar_44297 = (cppVar_44295 == 135);
	if (cppVar_44297) {
	cppVar_44292 = ACC;
	} else {
	cppVar_44292 = PCON;
	}
	cppVar_44284 = cppVar_44292;
	} else {
	cppVar_44299 = ROM.rd(PC);
	cppVar_44301 = (cppVar_44299 == 143);
	if (cppVar_44301) {
	cppVar_44304 = PC + 1;
	cppVar_44304 = (cppVar_44304 & cppMask_un_16_);
	cppVar_44305 = ROM.rd(cppVar_44304);
	cppVar_44307 = (cppVar_44305 == 135);
	if (cppVar_44307) {
	cppVar_44310 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44312 = (cppVar_44310 << 3) | 7;
	cppVar_44312 = (cppVar_44312 & cppMask_un_5_);
	cppVar_44313 = (0 << 5) | cppVar_44312;
	cppVar_44313 = (cppVar_44313 & cppMask_un_8_);
	cppVar_44314 = (cppVar_44313 >> 7) & cppMask_un_1_;
	cppVar_44316 = (cppVar_44314 == 0);
	if (cppVar_44316) {
	cppVar_44317 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44318 = (cppVar_44317 << 3) | 7;
	cppVar_44318 = (cppVar_44318 & cppMask_un_5_);
	cppVar_44319 = (0 << 5) | cppVar_44318;
	cppVar_44319 = (cppVar_44319 & cppMask_un_8_);
	cppVar_44320 = IRAM.rd(cppVar_44319);
	cppVar_44308 = cppVar_44320;
	} else {
	cppVar_44322 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44323 = (cppVar_44322 << 3) | 7;
	cppVar_44323 = (cppVar_44323 & cppMask_un_5_);
	cppVar_44324 = (0 << 5) | cppVar_44323;
	cppVar_44324 = (cppVar_44324 & cppMask_un_8_);
	cppVar_44326 = (cppVar_44324 == 128);
	if (cppVar_44326) {
	cppVar_44321 = P0;
	} else {
	cppVar_44328 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44329 = (cppVar_44328 << 3) | 7;
	cppVar_44329 = (cppVar_44329 & cppMask_un_5_);
	cppVar_44330 = (0 << 5) | cppVar_44329;
	cppVar_44330 = (cppVar_44330 & cppMask_un_8_);
	cppVar_44332 = (cppVar_44330 == 129);
	if (cppVar_44332) {
	cppVar_44327 = SP;
	} else {
	cppVar_44334 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44335 = (cppVar_44334 << 3) | 7;
	cppVar_44335 = (cppVar_44335 & cppMask_un_5_);
	cppVar_44336 = (0 << 5) | cppVar_44335;
	cppVar_44336 = (cppVar_44336 & cppMask_un_8_);
	cppVar_44338 = (cppVar_44336 == 130);
	if (cppVar_44338) {
	cppVar_44333 = DPL;
	} else {
	cppVar_44340 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44341 = (cppVar_44340 << 3) | 7;
	cppVar_44341 = (cppVar_44341 & cppMask_un_5_);
	cppVar_44342 = (0 << 5) | cppVar_44341;
	cppVar_44342 = (cppVar_44342 & cppMask_un_8_);
	cppVar_44344 = (cppVar_44342 == 131);
	if (cppVar_44344) {
	cppVar_44339 = DPH;
	} else {
	cppVar_44346 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44347 = (cppVar_44346 << 3) | 7;
	cppVar_44347 = (cppVar_44347 & cppMask_un_5_);
	cppVar_44348 = (0 << 5) | cppVar_44347;
	cppVar_44348 = (cppVar_44348 & cppMask_un_8_);
	cppVar_44350 = (cppVar_44348 == 135);
	if (cppVar_44350) {
	cppVar_44345 = PCON;
	} else {
	cppVar_44352 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44353 = (cppVar_44352 << 3) | 7;
	cppVar_44353 = (cppVar_44353 & cppMask_un_5_);
	cppVar_44354 = (0 << 5) | cppVar_44353;
	cppVar_44354 = (cppVar_44354 & cppMask_un_8_);
	cppVar_44356 = (cppVar_44354 == 136);
	if (cppVar_44356) {
	cppVar_44351 = TCON;
	} else {
	cppVar_44358 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44359 = (cppVar_44358 << 3) | 7;
	cppVar_44359 = (cppVar_44359 & cppMask_un_5_);
	cppVar_44360 = (0 << 5) | cppVar_44359;
	cppVar_44360 = (cppVar_44360 & cppMask_un_8_);
	cppVar_44362 = (cppVar_44360 == 137);
	if (cppVar_44362) {
	cppVar_44357 = TMOD;
	} else {
	cppVar_44364 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44365 = (cppVar_44364 << 3) | 7;
	cppVar_44365 = (cppVar_44365 & cppMask_un_5_);
	cppVar_44366 = (0 << 5) | cppVar_44365;
	cppVar_44366 = (cppVar_44366 & cppMask_un_8_);
	cppVar_44368 = (cppVar_44366 == 138);
	if (cppVar_44368) {
	cppVar_44363 = TL0;
	} else {
	cppVar_44370 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44371 = (cppVar_44370 << 3) | 7;
	cppVar_44371 = (cppVar_44371 & cppMask_un_5_);
	cppVar_44372 = (0 << 5) | cppVar_44371;
	cppVar_44372 = (cppVar_44372 & cppMask_un_8_);
	cppVar_44374 = (cppVar_44372 == 140);
	if (cppVar_44374) {
	cppVar_44369 = TH0;
	} else {
	cppVar_44376 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44377 = (cppVar_44376 << 3) | 7;
	cppVar_44377 = (cppVar_44377 & cppMask_un_5_);
	cppVar_44378 = (0 << 5) | cppVar_44377;
	cppVar_44378 = (cppVar_44378 & cppMask_un_8_);
	cppVar_44380 = (cppVar_44378 == 139);
	if (cppVar_44380) {
	cppVar_44375 = TL1;
	} else {
	cppVar_44382 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44383 = (cppVar_44382 << 3) | 7;
	cppVar_44383 = (cppVar_44383 & cppMask_un_5_);
	cppVar_44384 = (0 << 5) | cppVar_44383;
	cppVar_44384 = (cppVar_44384 & cppMask_un_8_);
	cppVar_44386 = (cppVar_44384 == 141);
	if (cppVar_44386) {
	cppVar_44381 = TH1;
	} else {
	cppVar_44388 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44389 = (cppVar_44388 << 3) | 7;
	cppVar_44389 = (cppVar_44389 & cppMask_un_5_);
	cppVar_44390 = (0 << 5) | cppVar_44389;
	cppVar_44390 = (cppVar_44390 & cppMask_un_8_);
	cppVar_44392 = (cppVar_44390 == 144);
	if (cppVar_44392) {
	cppVar_44387 = P1;
	} else {
	cppVar_44394 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44395 = (cppVar_44394 << 3) | 7;
	cppVar_44395 = (cppVar_44395 & cppMask_un_5_);
	cppVar_44396 = (0 << 5) | cppVar_44395;
	cppVar_44396 = (cppVar_44396 & cppMask_un_8_);
	cppVar_44398 = (cppVar_44396 == 152);
	if (cppVar_44398) {
	cppVar_44393 = SCON;
	} else {
	cppVar_44400 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44401 = (cppVar_44400 << 3) | 7;
	cppVar_44401 = (cppVar_44401 & cppMask_un_5_);
	cppVar_44402 = (0 << 5) | cppVar_44401;
	cppVar_44402 = (cppVar_44402 & cppMask_un_8_);
	cppVar_44404 = (cppVar_44402 == 153);
	if (cppVar_44404) {
	cppVar_44399 = SBUF;
	} else {
	cppVar_44406 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44407 = (cppVar_44406 << 3) | 7;
	cppVar_44407 = (cppVar_44407 & cppMask_un_5_);
	cppVar_44408 = (0 << 5) | cppVar_44407;
	cppVar_44408 = (cppVar_44408 & cppMask_un_8_);
	cppVar_44410 = (cppVar_44408 == 160);
	if (cppVar_44410) {
	cppVar_44405 = P2;
	} else {
	cppVar_44412 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44413 = (cppVar_44412 << 3) | 7;
	cppVar_44413 = (cppVar_44413 & cppMask_un_5_);
	cppVar_44414 = (0 << 5) | cppVar_44413;
	cppVar_44414 = (cppVar_44414 & cppMask_un_8_);
	cppVar_44416 = (cppVar_44414 == 168);
	if (cppVar_44416) {
	cppVar_44411 = IE;
	} else {
	cppVar_44418 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44419 = (cppVar_44418 << 3) | 7;
	cppVar_44419 = (cppVar_44419 & cppMask_un_5_);
	cppVar_44420 = (0 << 5) | cppVar_44419;
	cppVar_44420 = (cppVar_44420 & cppMask_un_8_);
	cppVar_44422 = (cppVar_44420 == 176);
	if (cppVar_44422) {
	cppVar_44417 = P3;
	} else {
	cppVar_44424 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44425 = (cppVar_44424 << 3) | 7;
	cppVar_44425 = (cppVar_44425 & cppMask_un_5_);
	cppVar_44426 = (0 << 5) | cppVar_44425;
	cppVar_44426 = (cppVar_44426 & cppMask_un_8_);
	cppVar_44428 = (cppVar_44426 == 184);
	if (cppVar_44428) {
	cppVar_44423 = IP;
	} else {
	cppVar_44430 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44431 = (cppVar_44430 << 3) | 7;
	cppVar_44431 = (cppVar_44431 & cppMask_un_5_);
	cppVar_44432 = (0 << 5) | cppVar_44431;
	cppVar_44432 = (cppVar_44432 & cppMask_un_8_);
	cppVar_44434 = (cppVar_44432 == 208);
	if (cppVar_44434) {
	cppVar_44429 = PSW;
	} else {
	cppVar_44436 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44437 = (cppVar_44436 << 3) | 7;
	cppVar_44437 = (cppVar_44437 & cppMask_un_5_);
	cppVar_44438 = (0 << 5) | cppVar_44437;
	cppVar_44438 = (cppVar_44438 & cppMask_un_8_);
	cppVar_44440 = (cppVar_44438 == 224);
	if (cppVar_44440) {
	cppVar_44435 = ACC;
	} else {
	cppVar_44442 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44443 = (cppVar_44442 << 3) | 7;
	cppVar_44443 = (cppVar_44443 & cppMask_un_5_);
	cppVar_44444 = (0 << 5) | cppVar_44443;
	cppVar_44444 = (cppVar_44444 & cppMask_un_8_);
	cppVar_44446 = (cppVar_44444 == 240);
	if (cppVar_44446) {
	cppVar_44441 = B;
	} else {
	cppVar_44441 = 0;
	}
	cppVar_44435 = cppVar_44441;
	}
	cppVar_44429 = cppVar_44435;
	}
	cppVar_44423 = cppVar_44429;
	}
	cppVar_44417 = cppVar_44423;
	}
	cppVar_44411 = cppVar_44417;
	}
	cppVar_44405 = cppVar_44411;
	}
	cppVar_44399 = cppVar_44405;
	}
	cppVar_44393 = cppVar_44399;
	}
	cppVar_44387 = cppVar_44393;
	}
	cppVar_44381 = cppVar_44387;
	}
	cppVar_44375 = cppVar_44381;
	}
	cppVar_44369 = cppVar_44375;
	}
	cppVar_44363 = cppVar_44369;
	}
	cppVar_44357 = cppVar_44363;
	}
	cppVar_44351 = cppVar_44357;
	}
	cppVar_44345 = cppVar_44351;
	}
	cppVar_44339 = cppVar_44345;
	}
	cppVar_44333 = cppVar_44339;
	}
	cppVar_44327 = cppVar_44333;
	}
	cppVar_44321 = cppVar_44327;
	}
	cppVar_44308 = cppVar_44321;
	}
	cppVar_44302 = cppVar_44308;
	} else {
	cppVar_44302 = PCON;
	}
	cppVar_44298 = cppVar_44302;
	} else {
	cppVar_44449 = ROM.rd(PC);
	cppVar_44451 = (cppVar_44449 == 142);
	if (cppVar_44451) {
	cppVar_44454 = PC + 1;
	cppVar_44454 = (cppVar_44454 & cppMask_un_16_);
	cppVar_44455 = ROM.rd(cppVar_44454);
	cppVar_44457 = (cppVar_44455 == 135);
	if (cppVar_44457) {
	cppVar_44460 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44462 = (cppVar_44460 << 3) | 6;
	cppVar_44462 = (cppVar_44462 & cppMask_un_5_);
	cppVar_44463 = (0 << 5) | cppVar_44462;
	cppVar_44463 = (cppVar_44463 & cppMask_un_8_);
	cppVar_44464 = (cppVar_44463 >> 7) & cppMask_un_1_;
	cppVar_44466 = (cppVar_44464 == 0);
	if (cppVar_44466) {
	cppVar_44467 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44468 = (cppVar_44467 << 3) | 6;
	cppVar_44468 = (cppVar_44468 & cppMask_un_5_);
	cppVar_44469 = (0 << 5) | cppVar_44468;
	cppVar_44469 = (cppVar_44469 & cppMask_un_8_);
	cppVar_44470 = IRAM.rd(cppVar_44469);
	cppVar_44458 = cppVar_44470;
	} else {
	cppVar_44472 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44473 = (cppVar_44472 << 3) | 6;
	cppVar_44473 = (cppVar_44473 & cppMask_un_5_);
	cppVar_44474 = (0 << 5) | cppVar_44473;
	cppVar_44474 = (cppVar_44474 & cppMask_un_8_);
	cppVar_44476 = (cppVar_44474 == 128);
	if (cppVar_44476) {
	cppVar_44471 = P0;
	} else {
	cppVar_44478 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44479 = (cppVar_44478 << 3) | 6;
	cppVar_44479 = (cppVar_44479 & cppMask_un_5_);
	cppVar_44480 = (0 << 5) | cppVar_44479;
	cppVar_44480 = (cppVar_44480 & cppMask_un_8_);
	cppVar_44482 = (cppVar_44480 == 129);
	if (cppVar_44482) {
	cppVar_44477 = SP;
	} else {
	cppVar_44484 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44485 = (cppVar_44484 << 3) | 6;
	cppVar_44485 = (cppVar_44485 & cppMask_un_5_);
	cppVar_44486 = (0 << 5) | cppVar_44485;
	cppVar_44486 = (cppVar_44486 & cppMask_un_8_);
	cppVar_44488 = (cppVar_44486 == 130);
	if (cppVar_44488) {
	cppVar_44483 = DPL;
	} else {
	cppVar_44490 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44491 = (cppVar_44490 << 3) | 6;
	cppVar_44491 = (cppVar_44491 & cppMask_un_5_);
	cppVar_44492 = (0 << 5) | cppVar_44491;
	cppVar_44492 = (cppVar_44492 & cppMask_un_8_);
	cppVar_44494 = (cppVar_44492 == 131);
	if (cppVar_44494) {
	cppVar_44489 = DPH;
	} else {
	cppVar_44496 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44497 = (cppVar_44496 << 3) | 6;
	cppVar_44497 = (cppVar_44497 & cppMask_un_5_);
	cppVar_44498 = (0 << 5) | cppVar_44497;
	cppVar_44498 = (cppVar_44498 & cppMask_un_8_);
	cppVar_44500 = (cppVar_44498 == 135);
	if (cppVar_44500) {
	cppVar_44495 = PCON;
	} else {
	cppVar_44502 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44503 = (cppVar_44502 << 3) | 6;
	cppVar_44503 = (cppVar_44503 & cppMask_un_5_);
	cppVar_44504 = (0 << 5) | cppVar_44503;
	cppVar_44504 = (cppVar_44504 & cppMask_un_8_);
	cppVar_44506 = (cppVar_44504 == 136);
	if (cppVar_44506) {
	cppVar_44501 = TCON;
	} else {
	cppVar_44508 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44509 = (cppVar_44508 << 3) | 6;
	cppVar_44509 = (cppVar_44509 & cppMask_un_5_);
	cppVar_44510 = (0 << 5) | cppVar_44509;
	cppVar_44510 = (cppVar_44510 & cppMask_un_8_);
	cppVar_44512 = (cppVar_44510 == 137);
	if (cppVar_44512) {
	cppVar_44507 = TMOD;
	} else {
	cppVar_44514 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44515 = (cppVar_44514 << 3) | 6;
	cppVar_44515 = (cppVar_44515 & cppMask_un_5_);
	cppVar_44516 = (0 << 5) | cppVar_44515;
	cppVar_44516 = (cppVar_44516 & cppMask_un_8_);
	cppVar_44518 = (cppVar_44516 == 138);
	if (cppVar_44518) {
	cppVar_44513 = TL0;
	} else {
	cppVar_44520 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44521 = (cppVar_44520 << 3) | 6;
	cppVar_44521 = (cppVar_44521 & cppMask_un_5_);
	cppVar_44522 = (0 << 5) | cppVar_44521;
	cppVar_44522 = (cppVar_44522 & cppMask_un_8_);
	cppVar_44524 = (cppVar_44522 == 140);
	if (cppVar_44524) {
	cppVar_44519 = TH0;
	} else {
	cppVar_44526 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44527 = (cppVar_44526 << 3) | 6;
	cppVar_44527 = (cppVar_44527 & cppMask_un_5_);
	cppVar_44528 = (0 << 5) | cppVar_44527;
	cppVar_44528 = (cppVar_44528 & cppMask_un_8_);
	cppVar_44530 = (cppVar_44528 == 139);
	if (cppVar_44530) {
	cppVar_44525 = TL1;
	} else {
	cppVar_44532 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44533 = (cppVar_44532 << 3) | 6;
	cppVar_44533 = (cppVar_44533 & cppMask_un_5_);
	cppVar_44534 = (0 << 5) | cppVar_44533;
	cppVar_44534 = (cppVar_44534 & cppMask_un_8_);
	cppVar_44536 = (cppVar_44534 == 141);
	if (cppVar_44536) {
	cppVar_44531 = TH1;
	} else {
	cppVar_44538 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44539 = (cppVar_44538 << 3) | 6;
	cppVar_44539 = (cppVar_44539 & cppMask_un_5_);
	cppVar_44540 = (0 << 5) | cppVar_44539;
	cppVar_44540 = (cppVar_44540 & cppMask_un_8_);
	cppVar_44542 = (cppVar_44540 == 144);
	if (cppVar_44542) {
	cppVar_44537 = P1;
	} else {
	cppVar_44544 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44545 = (cppVar_44544 << 3) | 6;
	cppVar_44545 = (cppVar_44545 & cppMask_un_5_);
	cppVar_44546 = (0 << 5) | cppVar_44545;
	cppVar_44546 = (cppVar_44546 & cppMask_un_8_);
	cppVar_44548 = (cppVar_44546 == 152);
	if (cppVar_44548) {
	cppVar_44543 = SCON;
	} else {
	cppVar_44550 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44551 = (cppVar_44550 << 3) | 6;
	cppVar_44551 = (cppVar_44551 & cppMask_un_5_);
	cppVar_44552 = (0 << 5) | cppVar_44551;
	cppVar_44552 = (cppVar_44552 & cppMask_un_8_);
	cppVar_44554 = (cppVar_44552 == 153);
	if (cppVar_44554) {
	cppVar_44549 = SBUF;
	} else {
	cppVar_44556 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44557 = (cppVar_44556 << 3) | 6;
	cppVar_44557 = (cppVar_44557 & cppMask_un_5_);
	cppVar_44558 = (0 << 5) | cppVar_44557;
	cppVar_44558 = (cppVar_44558 & cppMask_un_8_);
	cppVar_44560 = (cppVar_44558 == 160);
	if (cppVar_44560) {
	cppVar_44555 = P2;
	} else {
	cppVar_44562 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44563 = (cppVar_44562 << 3) | 6;
	cppVar_44563 = (cppVar_44563 & cppMask_un_5_);
	cppVar_44564 = (0 << 5) | cppVar_44563;
	cppVar_44564 = (cppVar_44564 & cppMask_un_8_);
	cppVar_44566 = (cppVar_44564 == 168);
	if (cppVar_44566) {
	cppVar_44561 = IE;
	} else {
	cppVar_44568 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44569 = (cppVar_44568 << 3) | 6;
	cppVar_44569 = (cppVar_44569 & cppMask_un_5_);
	cppVar_44570 = (0 << 5) | cppVar_44569;
	cppVar_44570 = (cppVar_44570 & cppMask_un_8_);
	cppVar_44572 = (cppVar_44570 == 176);
	if (cppVar_44572) {
	cppVar_44567 = P3;
	} else {
	cppVar_44574 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44575 = (cppVar_44574 << 3) | 6;
	cppVar_44575 = (cppVar_44575 & cppMask_un_5_);
	cppVar_44576 = (0 << 5) | cppVar_44575;
	cppVar_44576 = (cppVar_44576 & cppMask_un_8_);
	cppVar_44578 = (cppVar_44576 == 184);
	if (cppVar_44578) {
	cppVar_44573 = IP;
	} else {
	cppVar_44580 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44581 = (cppVar_44580 << 3) | 6;
	cppVar_44581 = (cppVar_44581 & cppMask_un_5_);
	cppVar_44582 = (0 << 5) | cppVar_44581;
	cppVar_44582 = (cppVar_44582 & cppMask_un_8_);
	cppVar_44584 = (cppVar_44582 == 208);
	if (cppVar_44584) {
	cppVar_44579 = PSW;
	} else {
	cppVar_44586 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44587 = (cppVar_44586 << 3) | 6;
	cppVar_44587 = (cppVar_44587 & cppMask_un_5_);
	cppVar_44588 = (0 << 5) | cppVar_44587;
	cppVar_44588 = (cppVar_44588 & cppMask_un_8_);
	cppVar_44590 = (cppVar_44588 == 224);
	if (cppVar_44590) {
	cppVar_44585 = ACC;
	} else {
	cppVar_44592 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44593 = (cppVar_44592 << 3) | 6;
	cppVar_44593 = (cppVar_44593 & cppMask_un_5_);
	cppVar_44594 = (0 << 5) | cppVar_44593;
	cppVar_44594 = (cppVar_44594 & cppMask_un_8_);
	cppVar_44596 = (cppVar_44594 == 240);
	if (cppVar_44596) {
	cppVar_44591 = B;
	} else {
	cppVar_44591 = 0;
	}
	cppVar_44585 = cppVar_44591;
	}
	cppVar_44579 = cppVar_44585;
	}
	cppVar_44573 = cppVar_44579;
	}
	cppVar_44567 = cppVar_44573;
	}
	cppVar_44561 = cppVar_44567;
	}
	cppVar_44555 = cppVar_44561;
	}
	cppVar_44549 = cppVar_44555;
	}
	cppVar_44543 = cppVar_44549;
	}
	cppVar_44537 = cppVar_44543;
	}
	cppVar_44531 = cppVar_44537;
	}
	cppVar_44525 = cppVar_44531;
	}
	cppVar_44519 = cppVar_44525;
	}
	cppVar_44513 = cppVar_44519;
	}
	cppVar_44507 = cppVar_44513;
	}
	cppVar_44501 = cppVar_44507;
	}
	cppVar_44495 = cppVar_44501;
	}
	cppVar_44489 = cppVar_44495;
	}
	cppVar_44483 = cppVar_44489;
	}
	cppVar_44477 = cppVar_44483;
	}
	cppVar_44471 = cppVar_44477;
	}
	cppVar_44458 = cppVar_44471;
	}
	cppVar_44452 = cppVar_44458;
	} else {
	cppVar_44452 = PCON;
	}
	cppVar_44448 = cppVar_44452;
	} else {
	cppVar_44599 = ROM.rd(PC);
	cppVar_44601 = (cppVar_44599 == 141);
	if (cppVar_44601) {
	cppVar_44604 = PC + 1;
	cppVar_44604 = (cppVar_44604 & cppMask_un_16_);
	cppVar_44605 = ROM.rd(cppVar_44604);
	cppVar_44607 = (cppVar_44605 == 135);
	if (cppVar_44607) {
	cppVar_44610 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44612 = (cppVar_44610 << 3) | 5;
	cppVar_44612 = (cppVar_44612 & cppMask_un_5_);
	cppVar_44613 = (0 << 5) | cppVar_44612;
	cppVar_44613 = (cppVar_44613 & cppMask_un_8_);
	cppVar_44614 = (cppVar_44613 >> 7) & cppMask_un_1_;
	cppVar_44616 = (cppVar_44614 == 0);
	if (cppVar_44616) {
	cppVar_44617 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44618 = (cppVar_44617 << 3) | 5;
	cppVar_44618 = (cppVar_44618 & cppMask_un_5_);
	cppVar_44619 = (0 << 5) | cppVar_44618;
	cppVar_44619 = (cppVar_44619 & cppMask_un_8_);
	cppVar_44620 = IRAM.rd(cppVar_44619);
	cppVar_44608 = cppVar_44620;
	} else {
	cppVar_44622 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44623 = (cppVar_44622 << 3) | 5;
	cppVar_44623 = (cppVar_44623 & cppMask_un_5_);
	cppVar_44624 = (0 << 5) | cppVar_44623;
	cppVar_44624 = (cppVar_44624 & cppMask_un_8_);
	cppVar_44626 = (cppVar_44624 == 128);
	if (cppVar_44626) {
	cppVar_44621 = P0;
	} else {
	cppVar_44628 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44629 = (cppVar_44628 << 3) | 5;
	cppVar_44629 = (cppVar_44629 & cppMask_un_5_);
	cppVar_44630 = (0 << 5) | cppVar_44629;
	cppVar_44630 = (cppVar_44630 & cppMask_un_8_);
	cppVar_44632 = (cppVar_44630 == 129);
	if (cppVar_44632) {
	cppVar_44627 = SP;
	} else {
	cppVar_44634 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44635 = (cppVar_44634 << 3) | 5;
	cppVar_44635 = (cppVar_44635 & cppMask_un_5_);
	cppVar_44636 = (0 << 5) | cppVar_44635;
	cppVar_44636 = (cppVar_44636 & cppMask_un_8_);
	cppVar_44638 = (cppVar_44636 == 130);
	if (cppVar_44638) {
	cppVar_44633 = DPL;
	} else {
	cppVar_44640 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44641 = (cppVar_44640 << 3) | 5;
	cppVar_44641 = (cppVar_44641 & cppMask_un_5_);
	cppVar_44642 = (0 << 5) | cppVar_44641;
	cppVar_44642 = (cppVar_44642 & cppMask_un_8_);
	cppVar_44644 = (cppVar_44642 == 131);
	if (cppVar_44644) {
	cppVar_44639 = DPH;
	} else {
	cppVar_44646 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44647 = (cppVar_44646 << 3) | 5;
	cppVar_44647 = (cppVar_44647 & cppMask_un_5_);
	cppVar_44648 = (0 << 5) | cppVar_44647;
	cppVar_44648 = (cppVar_44648 & cppMask_un_8_);
	cppVar_44650 = (cppVar_44648 == 135);
	if (cppVar_44650) {
	cppVar_44645 = PCON;
	} else {
	cppVar_44652 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44653 = (cppVar_44652 << 3) | 5;
	cppVar_44653 = (cppVar_44653 & cppMask_un_5_);
	cppVar_44654 = (0 << 5) | cppVar_44653;
	cppVar_44654 = (cppVar_44654 & cppMask_un_8_);
	cppVar_44656 = (cppVar_44654 == 136);
	if (cppVar_44656) {
	cppVar_44651 = TCON;
	} else {
	cppVar_44658 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44659 = (cppVar_44658 << 3) | 5;
	cppVar_44659 = (cppVar_44659 & cppMask_un_5_);
	cppVar_44660 = (0 << 5) | cppVar_44659;
	cppVar_44660 = (cppVar_44660 & cppMask_un_8_);
	cppVar_44662 = (cppVar_44660 == 137);
	if (cppVar_44662) {
	cppVar_44657 = TMOD;
	} else {
	cppVar_44664 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44665 = (cppVar_44664 << 3) | 5;
	cppVar_44665 = (cppVar_44665 & cppMask_un_5_);
	cppVar_44666 = (0 << 5) | cppVar_44665;
	cppVar_44666 = (cppVar_44666 & cppMask_un_8_);
	cppVar_44668 = (cppVar_44666 == 138);
	if (cppVar_44668) {
	cppVar_44663 = TL0;
	} else {
	cppVar_44670 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44671 = (cppVar_44670 << 3) | 5;
	cppVar_44671 = (cppVar_44671 & cppMask_un_5_);
	cppVar_44672 = (0 << 5) | cppVar_44671;
	cppVar_44672 = (cppVar_44672 & cppMask_un_8_);
	cppVar_44674 = (cppVar_44672 == 140);
	if (cppVar_44674) {
	cppVar_44669 = TH0;
	} else {
	cppVar_44676 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44677 = (cppVar_44676 << 3) | 5;
	cppVar_44677 = (cppVar_44677 & cppMask_un_5_);
	cppVar_44678 = (0 << 5) | cppVar_44677;
	cppVar_44678 = (cppVar_44678 & cppMask_un_8_);
	cppVar_44680 = (cppVar_44678 == 139);
	if (cppVar_44680) {
	cppVar_44675 = TL1;
	} else {
	cppVar_44682 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44683 = (cppVar_44682 << 3) | 5;
	cppVar_44683 = (cppVar_44683 & cppMask_un_5_);
	cppVar_44684 = (0 << 5) | cppVar_44683;
	cppVar_44684 = (cppVar_44684 & cppMask_un_8_);
	cppVar_44686 = (cppVar_44684 == 141);
	if (cppVar_44686) {
	cppVar_44681 = TH1;
	} else {
	cppVar_44688 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44689 = (cppVar_44688 << 3) | 5;
	cppVar_44689 = (cppVar_44689 & cppMask_un_5_);
	cppVar_44690 = (0 << 5) | cppVar_44689;
	cppVar_44690 = (cppVar_44690 & cppMask_un_8_);
	cppVar_44692 = (cppVar_44690 == 144);
	if (cppVar_44692) {
	cppVar_44687 = P1;
	} else {
	cppVar_44694 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44695 = (cppVar_44694 << 3) | 5;
	cppVar_44695 = (cppVar_44695 & cppMask_un_5_);
	cppVar_44696 = (0 << 5) | cppVar_44695;
	cppVar_44696 = (cppVar_44696 & cppMask_un_8_);
	cppVar_44698 = (cppVar_44696 == 152);
	if (cppVar_44698) {
	cppVar_44693 = SCON;
	} else {
	cppVar_44700 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44701 = (cppVar_44700 << 3) | 5;
	cppVar_44701 = (cppVar_44701 & cppMask_un_5_);
	cppVar_44702 = (0 << 5) | cppVar_44701;
	cppVar_44702 = (cppVar_44702 & cppMask_un_8_);
	cppVar_44704 = (cppVar_44702 == 153);
	if (cppVar_44704) {
	cppVar_44699 = SBUF;
	} else {
	cppVar_44706 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44707 = (cppVar_44706 << 3) | 5;
	cppVar_44707 = (cppVar_44707 & cppMask_un_5_);
	cppVar_44708 = (0 << 5) | cppVar_44707;
	cppVar_44708 = (cppVar_44708 & cppMask_un_8_);
	cppVar_44710 = (cppVar_44708 == 160);
	if (cppVar_44710) {
	cppVar_44705 = P2;
	} else {
	cppVar_44712 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44713 = (cppVar_44712 << 3) | 5;
	cppVar_44713 = (cppVar_44713 & cppMask_un_5_);
	cppVar_44714 = (0 << 5) | cppVar_44713;
	cppVar_44714 = (cppVar_44714 & cppMask_un_8_);
	cppVar_44716 = (cppVar_44714 == 168);
	if (cppVar_44716) {
	cppVar_44711 = IE;
	} else {
	cppVar_44718 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44719 = (cppVar_44718 << 3) | 5;
	cppVar_44719 = (cppVar_44719 & cppMask_un_5_);
	cppVar_44720 = (0 << 5) | cppVar_44719;
	cppVar_44720 = (cppVar_44720 & cppMask_un_8_);
	cppVar_44722 = (cppVar_44720 == 176);
	if (cppVar_44722) {
	cppVar_44717 = P3;
	} else {
	cppVar_44724 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44725 = (cppVar_44724 << 3) | 5;
	cppVar_44725 = (cppVar_44725 & cppMask_un_5_);
	cppVar_44726 = (0 << 5) | cppVar_44725;
	cppVar_44726 = (cppVar_44726 & cppMask_un_8_);
	cppVar_44728 = (cppVar_44726 == 184);
	if (cppVar_44728) {
	cppVar_44723 = IP;
	} else {
	cppVar_44730 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44731 = (cppVar_44730 << 3) | 5;
	cppVar_44731 = (cppVar_44731 & cppMask_un_5_);
	cppVar_44732 = (0 << 5) | cppVar_44731;
	cppVar_44732 = (cppVar_44732 & cppMask_un_8_);
	cppVar_44734 = (cppVar_44732 == 208);
	if (cppVar_44734) {
	cppVar_44729 = PSW;
	} else {
	cppVar_44736 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44737 = (cppVar_44736 << 3) | 5;
	cppVar_44737 = (cppVar_44737 & cppMask_un_5_);
	cppVar_44738 = (0 << 5) | cppVar_44737;
	cppVar_44738 = (cppVar_44738 & cppMask_un_8_);
	cppVar_44740 = (cppVar_44738 == 224);
	if (cppVar_44740) {
	cppVar_44735 = ACC;
	} else {
	cppVar_44742 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44743 = (cppVar_44742 << 3) | 5;
	cppVar_44743 = (cppVar_44743 & cppMask_un_5_);
	cppVar_44744 = (0 << 5) | cppVar_44743;
	cppVar_44744 = (cppVar_44744 & cppMask_un_8_);
	cppVar_44746 = (cppVar_44744 == 240);
	if (cppVar_44746) {
	cppVar_44741 = B;
	} else {
	cppVar_44741 = 0;
	}
	cppVar_44735 = cppVar_44741;
	}
	cppVar_44729 = cppVar_44735;
	}
	cppVar_44723 = cppVar_44729;
	}
	cppVar_44717 = cppVar_44723;
	}
	cppVar_44711 = cppVar_44717;
	}
	cppVar_44705 = cppVar_44711;
	}
	cppVar_44699 = cppVar_44705;
	}
	cppVar_44693 = cppVar_44699;
	}
	cppVar_44687 = cppVar_44693;
	}
	cppVar_44681 = cppVar_44687;
	}
	cppVar_44675 = cppVar_44681;
	}
	cppVar_44669 = cppVar_44675;
	}
	cppVar_44663 = cppVar_44669;
	}
	cppVar_44657 = cppVar_44663;
	}
	cppVar_44651 = cppVar_44657;
	}
	cppVar_44645 = cppVar_44651;
	}
	cppVar_44639 = cppVar_44645;
	}
	cppVar_44633 = cppVar_44639;
	}
	cppVar_44627 = cppVar_44633;
	}
	cppVar_44621 = cppVar_44627;
	}
	cppVar_44608 = cppVar_44621;
	}
	cppVar_44602 = cppVar_44608;
	} else {
	cppVar_44602 = PCON;
	}
	cppVar_44598 = cppVar_44602;
	} else {
	cppVar_44749 = ROM.rd(PC);
	cppVar_44751 = (cppVar_44749 == 140);
	if (cppVar_44751) {
	cppVar_44754 = PC + 1;
	cppVar_44754 = (cppVar_44754 & cppMask_un_16_);
	cppVar_44755 = ROM.rd(cppVar_44754);
	cppVar_44757 = (cppVar_44755 == 135);
	if (cppVar_44757) {
	cppVar_44760 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44762 = (cppVar_44760 << 3) | 4;
	cppVar_44762 = (cppVar_44762 & cppMask_un_5_);
	cppVar_44763 = (0 << 5) | cppVar_44762;
	cppVar_44763 = (cppVar_44763 & cppMask_un_8_);
	cppVar_44764 = (cppVar_44763 >> 7) & cppMask_un_1_;
	cppVar_44766 = (cppVar_44764 == 0);
	if (cppVar_44766) {
	cppVar_44767 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44768 = (cppVar_44767 << 3) | 4;
	cppVar_44768 = (cppVar_44768 & cppMask_un_5_);
	cppVar_44769 = (0 << 5) | cppVar_44768;
	cppVar_44769 = (cppVar_44769 & cppMask_un_8_);
	cppVar_44770 = IRAM.rd(cppVar_44769);
	cppVar_44758 = cppVar_44770;
	} else {
	cppVar_44772 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44773 = (cppVar_44772 << 3) | 4;
	cppVar_44773 = (cppVar_44773 & cppMask_un_5_);
	cppVar_44774 = (0 << 5) | cppVar_44773;
	cppVar_44774 = (cppVar_44774 & cppMask_un_8_);
	cppVar_44776 = (cppVar_44774 == 128);
	if (cppVar_44776) {
	cppVar_44771 = P0;
	} else {
	cppVar_44778 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44779 = (cppVar_44778 << 3) | 4;
	cppVar_44779 = (cppVar_44779 & cppMask_un_5_);
	cppVar_44780 = (0 << 5) | cppVar_44779;
	cppVar_44780 = (cppVar_44780 & cppMask_un_8_);
	cppVar_44782 = (cppVar_44780 == 129);
	if (cppVar_44782) {
	cppVar_44777 = SP;
	} else {
	cppVar_44784 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44785 = (cppVar_44784 << 3) | 4;
	cppVar_44785 = (cppVar_44785 & cppMask_un_5_);
	cppVar_44786 = (0 << 5) | cppVar_44785;
	cppVar_44786 = (cppVar_44786 & cppMask_un_8_);
	cppVar_44788 = (cppVar_44786 == 130);
	if (cppVar_44788) {
	cppVar_44783 = DPL;
	} else {
	cppVar_44790 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44791 = (cppVar_44790 << 3) | 4;
	cppVar_44791 = (cppVar_44791 & cppMask_un_5_);
	cppVar_44792 = (0 << 5) | cppVar_44791;
	cppVar_44792 = (cppVar_44792 & cppMask_un_8_);
	cppVar_44794 = (cppVar_44792 == 131);
	if (cppVar_44794) {
	cppVar_44789 = DPH;
	} else {
	cppVar_44796 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44797 = (cppVar_44796 << 3) | 4;
	cppVar_44797 = (cppVar_44797 & cppMask_un_5_);
	cppVar_44798 = (0 << 5) | cppVar_44797;
	cppVar_44798 = (cppVar_44798 & cppMask_un_8_);
	cppVar_44800 = (cppVar_44798 == 135);
	if (cppVar_44800) {
	cppVar_44795 = PCON;
	} else {
	cppVar_44802 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44803 = (cppVar_44802 << 3) | 4;
	cppVar_44803 = (cppVar_44803 & cppMask_un_5_);
	cppVar_44804 = (0 << 5) | cppVar_44803;
	cppVar_44804 = (cppVar_44804 & cppMask_un_8_);
	cppVar_44806 = (cppVar_44804 == 136);
	if (cppVar_44806) {
	cppVar_44801 = TCON;
	} else {
	cppVar_44808 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44809 = (cppVar_44808 << 3) | 4;
	cppVar_44809 = (cppVar_44809 & cppMask_un_5_);
	cppVar_44810 = (0 << 5) | cppVar_44809;
	cppVar_44810 = (cppVar_44810 & cppMask_un_8_);
	cppVar_44812 = (cppVar_44810 == 137);
	if (cppVar_44812) {
	cppVar_44807 = TMOD;
	} else {
	cppVar_44814 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44815 = (cppVar_44814 << 3) | 4;
	cppVar_44815 = (cppVar_44815 & cppMask_un_5_);
	cppVar_44816 = (0 << 5) | cppVar_44815;
	cppVar_44816 = (cppVar_44816 & cppMask_un_8_);
	cppVar_44818 = (cppVar_44816 == 138);
	if (cppVar_44818) {
	cppVar_44813 = TL0;
	} else {
	cppVar_44820 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44821 = (cppVar_44820 << 3) | 4;
	cppVar_44821 = (cppVar_44821 & cppMask_un_5_);
	cppVar_44822 = (0 << 5) | cppVar_44821;
	cppVar_44822 = (cppVar_44822 & cppMask_un_8_);
	cppVar_44824 = (cppVar_44822 == 140);
	if (cppVar_44824) {
	cppVar_44819 = TH0;
	} else {
	cppVar_44826 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44827 = (cppVar_44826 << 3) | 4;
	cppVar_44827 = (cppVar_44827 & cppMask_un_5_);
	cppVar_44828 = (0 << 5) | cppVar_44827;
	cppVar_44828 = (cppVar_44828 & cppMask_un_8_);
	cppVar_44830 = (cppVar_44828 == 139);
	if (cppVar_44830) {
	cppVar_44825 = TL1;
	} else {
	cppVar_44832 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44833 = (cppVar_44832 << 3) | 4;
	cppVar_44833 = (cppVar_44833 & cppMask_un_5_);
	cppVar_44834 = (0 << 5) | cppVar_44833;
	cppVar_44834 = (cppVar_44834 & cppMask_un_8_);
	cppVar_44836 = (cppVar_44834 == 141);
	if (cppVar_44836) {
	cppVar_44831 = TH1;
	} else {
	cppVar_44838 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44839 = (cppVar_44838 << 3) | 4;
	cppVar_44839 = (cppVar_44839 & cppMask_un_5_);
	cppVar_44840 = (0 << 5) | cppVar_44839;
	cppVar_44840 = (cppVar_44840 & cppMask_un_8_);
	cppVar_44842 = (cppVar_44840 == 144);
	if (cppVar_44842) {
	cppVar_44837 = P1;
	} else {
	cppVar_44844 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44845 = (cppVar_44844 << 3) | 4;
	cppVar_44845 = (cppVar_44845 & cppMask_un_5_);
	cppVar_44846 = (0 << 5) | cppVar_44845;
	cppVar_44846 = (cppVar_44846 & cppMask_un_8_);
	cppVar_44848 = (cppVar_44846 == 152);
	if (cppVar_44848) {
	cppVar_44843 = SCON;
	} else {
	cppVar_44850 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44851 = (cppVar_44850 << 3) | 4;
	cppVar_44851 = (cppVar_44851 & cppMask_un_5_);
	cppVar_44852 = (0 << 5) | cppVar_44851;
	cppVar_44852 = (cppVar_44852 & cppMask_un_8_);
	cppVar_44854 = (cppVar_44852 == 153);
	if (cppVar_44854) {
	cppVar_44849 = SBUF;
	} else {
	cppVar_44856 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44857 = (cppVar_44856 << 3) | 4;
	cppVar_44857 = (cppVar_44857 & cppMask_un_5_);
	cppVar_44858 = (0 << 5) | cppVar_44857;
	cppVar_44858 = (cppVar_44858 & cppMask_un_8_);
	cppVar_44860 = (cppVar_44858 == 160);
	if (cppVar_44860) {
	cppVar_44855 = P2;
	} else {
	cppVar_44862 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44863 = (cppVar_44862 << 3) | 4;
	cppVar_44863 = (cppVar_44863 & cppMask_un_5_);
	cppVar_44864 = (0 << 5) | cppVar_44863;
	cppVar_44864 = (cppVar_44864 & cppMask_un_8_);
	cppVar_44866 = (cppVar_44864 == 168);
	if (cppVar_44866) {
	cppVar_44861 = IE;
	} else {
	cppVar_44868 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44869 = (cppVar_44868 << 3) | 4;
	cppVar_44869 = (cppVar_44869 & cppMask_un_5_);
	cppVar_44870 = (0 << 5) | cppVar_44869;
	cppVar_44870 = (cppVar_44870 & cppMask_un_8_);
	cppVar_44872 = (cppVar_44870 == 176);
	if (cppVar_44872) {
	cppVar_44867 = P3;
	} else {
	cppVar_44874 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44875 = (cppVar_44874 << 3) | 4;
	cppVar_44875 = (cppVar_44875 & cppMask_un_5_);
	cppVar_44876 = (0 << 5) | cppVar_44875;
	cppVar_44876 = (cppVar_44876 & cppMask_un_8_);
	cppVar_44878 = (cppVar_44876 == 184);
	if (cppVar_44878) {
	cppVar_44873 = IP;
	} else {
	cppVar_44880 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44881 = (cppVar_44880 << 3) | 4;
	cppVar_44881 = (cppVar_44881 & cppMask_un_5_);
	cppVar_44882 = (0 << 5) | cppVar_44881;
	cppVar_44882 = (cppVar_44882 & cppMask_un_8_);
	cppVar_44884 = (cppVar_44882 == 208);
	if (cppVar_44884) {
	cppVar_44879 = PSW;
	} else {
	cppVar_44886 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44887 = (cppVar_44886 << 3) | 4;
	cppVar_44887 = (cppVar_44887 & cppMask_un_5_);
	cppVar_44888 = (0 << 5) | cppVar_44887;
	cppVar_44888 = (cppVar_44888 & cppMask_un_8_);
	cppVar_44890 = (cppVar_44888 == 224);
	if (cppVar_44890) {
	cppVar_44885 = ACC;
	} else {
	cppVar_44892 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44893 = (cppVar_44892 << 3) | 4;
	cppVar_44893 = (cppVar_44893 & cppMask_un_5_);
	cppVar_44894 = (0 << 5) | cppVar_44893;
	cppVar_44894 = (cppVar_44894 & cppMask_un_8_);
	cppVar_44896 = (cppVar_44894 == 240);
	if (cppVar_44896) {
	cppVar_44891 = B;
	} else {
	cppVar_44891 = 0;
	}
	cppVar_44885 = cppVar_44891;
	}
	cppVar_44879 = cppVar_44885;
	}
	cppVar_44873 = cppVar_44879;
	}
	cppVar_44867 = cppVar_44873;
	}
	cppVar_44861 = cppVar_44867;
	}
	cppVar_44855 = cppVar_44861;
	}
	cppVar_44849 = cppVar_44855;
	}
	cppVar_44843 = cppVar_44849;
	}
	cppVar_44837 = cppVar_44843;
	}
	cppVar_44831 = cppVar_44837;
	}
	cppVar_44825 = cppVar_44831;
	}
	cppVar_44819 = cppVar_44825;
	}
	cppVar_44813 = cppVar_44819;
	}
	cppVar_44807 = cppVar_44813;
	}
	cppVar_44801 = cppVar_44807;
	}
	cppVar_44795 = cppVar_44801;
	}
	cppVar_44789 = cppVar_44795;
	}
	cppVar_44783 = cppVar_44789;
	}
	cppVar_44777 = cppVar_44783;
	}
	cppVar_44771 = cppVar_44777;
	}
	cppVar_44758 = cppVar_44771;
	}
	cppVar_44752 = cppVar_44758;
	} else {
	cppVar_44752 = PCON;
	}
	cppVar_44748 = cppVar_44752;
	} else {
	cppVar_44899 = ROM.rd(PC);
	cppVar_44901 = (cppVar_44899 == 139);
	if (cppVar_44901) {
	cppVar_44904 = PC + 1;
	cppVar_44904 = (cppVar_44904 & cppMask_un_16_);
	cppVar_44905 = ROM.rd(cppVar_44904);
	cppVar_44907 = (cppVar_44905 == 135);
	if (cppVar_44907) {
	cppVar_44910 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44912 = (cppVar_44910 << 3) | 3;
	cppVar_44912 = (cppVar_44912 & cppMask_un_5_);
	cppVar_44913 = (0 << 5) | cppVar_44912;
	cppVar_44913 = (cppVar_44913 & cppMask_un_8_);
	cppVar_44914 = (cppVar_44913 >> 7) & cppMask_un_1_;
	cppVar_44916 = (cppVar_44914 == 0);
	if (cppVar_44916) {
	cppVar_44917 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44918 = (cppVar_44917 << 3) | 3;
	cppVar_44918 = (cppVar_44918 & cppMask_un_5_);
	cppVar_44919 = (0 << 5) | cppVar_44918;
	cppVar_44919 = (cppVar_44919 & cppMask_un_8_);
	cppVar_44920 = IRAM.rd(cppVar_44919);
	cppVar_44908 = cppVar_44920;
	} else {
	cppVar_44922 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44923 = (cppVar_44922 << 3) | 3;
	cppVar_44923 = (cppVar_44923 & cppMask_un_5_);
	cppVar_44924 = (0 << 5) | cppVar_44923;
	cppVar_44924 = (cppVar_44924 & cppMask_un_8_);
	cppVar_44926 = (cppVar_44924 == 128);
	if (cppVar_44926) {
	cppVar_44921 = P0;
	} else {
	cppVar_44928 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44929 = (cppVar_44928 << 3) | 3;
	cppVar_44929 = (cppVar_44929 & cppMask_un_5_);
	cppVar_44930 = (0 << 5) | cppVar_44929;
	cppVar_44930 = (cppVar_44930 & cppMask_un_8_);
	cppVar_44932 = (cppVar_44930 == 129);
	if (cppVar_44932) {
	cppVar_44927 = SP;
	} else {
	cppVar_44934 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44935 = (cppVar_44934 << 3) | 3;
	cppVar_44935 = (cppVar_44935 & cppMask_un_5_);
	cppVar_44936 = (0 << 5) | cppVar_44935;
	cppVar_44936 = (cppVar_44936 & cppMask_un_8_);
	cppVar_44938 = (cppVar_44936 == 130);
	if (cppVar_44938) {
	cppVar_44933 = DPL;
	} else {
	cppVar_44940 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44941 = (cppVar_44940 << 3) | 3;
	cppVar_44941 = (cppVar_44941 & cppMask_un_5_);
	cppVar_44942 = (0 << 5) | cppVar_44941;
	cppVar_44942 = (cppVar_44942 & cppMask_un_8_);
	cppVar_44944 = (cppVar_44942 == 131);
	if (cppVar_44944) {
	cppVar_44939 = DPH;
	} else {
	cppVar_44946 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44947 = (cppVar_44946 << 3) | 3;
	cppVar_44947 = (cppVar_44947 & cppMask_un_5_);
	cppVar_44948 = (0 << 5) | cppVar_44947;
	cppVar_44948 = (cppVar_44948 & cppMask_un_8_);
	cppVar_44950 = (cppVar_44948 == 135);
	if (cppVar_44950) {
	cppVar_44945 = PCON;
	} else {
	cppVar_44952 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44953 = (cppVar_44952 << 3) | 3;
	cppVar_44953 = (cppVar_44953 & cppMask_un_5_);
	cppVar_44954 = (0 << 5) | cppVar_44953;
	cppVar_44954 = (cppVar_44954 & cppMask_un_8_);
	cppVar_44956 = (cppVar_44954 == 136);
	if (cppVar_44956) {
	cppVar_44951 = TCON;
	} else {
	cppVar_44958 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44959 = (cppVar_44958 << 3) | 3;
	cppVar_44959 = (cppVar_44959 & cppMask_un_5_);
	cppVar_44960 = (0 << 5) | cppVar_44959;
	cppVar_44960 = (cppVar_44960 & cppMask_un_8_);
	cppVar_44962 = (cppVar_44960 == 137);
	if (cppVar_44962) {
	cppVar_44957 = TMOD;
	} else {
	cppVar_44964 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44965 = (cppVar_44964 << 3) | 3;
	cppVar_44965 = (cppVar_44965 & cppMask_un_5_);
	cppVar_44966 = (0 << 5) | cppVar_44965;
	cppVar_44966 = (cppVar_44966 & cppMask_un_8_);
	cppVar_44968 = (cppVar_44966 == 138);
	if (cppVar_44968) {
	cppVar_44963 = TL0;
	} else {
	cppVar_44970 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44971 = (cppVar_44970 << 3) | 3;
	cppVar_44971 = (cppVar_44971 & cppMask_un_5_);
	cppVar_44972 = (0 << 5) | cppVar_44971;
	cppVar_44972 = (cppVar_44972 & cppMask_un_8_);
	cppVar_44974 = (cppVar_44972 == 140);
	if (cppVar_44974) {
	cppVar_44969 = TH0;
	} else {
	cppVar_44976 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44977 = (cppVar_44976 << 3) | 3;
	cppVar_44977 = (cppVar_44977 & cppMask_un_5_);
	cppVar_44978 = (0 << 5) | cppVar_44977;
	cppVar_44978 = (cppVar_44978 & cppMask_un_8_);
	cppVar_44980 = (cppVar_44978 == 139);
	if (cppVar_44980) {
	cppVar_44975 = TL1;
	} else {
	cppVar_44982 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44983 = (cppVar_44982 << 3) | 3;
	cppVar_44983 = (cppVar_44983 & cppMask_un_5_);
	cppVar_44984 = (0 << 5) | cppVar_44983;
	cppVar_44984 = (cppVar_44984 & cppMask_un_8_);
	cppVar_44986 = (cppVar_44984 == 141);
	if (cppVar_44986) {
	cppVar_44981 = TH1;
	} else {
	cppVar_44988 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44989 = (cppVar_44988 << 3) | 3;
	cppVar_44989 = (cppVar_44989 & cppMask_un_5_);
	cppVar_44990 = (0 << 5) | cppVar_44989;
	cppVar_44990 = (cppVar_44990 & cppMask_un_8_);
	cppVar_44992 = (cppVar_44990 == 144);
	if (cppVar_44992) {
	cppVar_44987 = P1;
	} else {
	cppVar_44994 = (PSW >> 3) & cppMask_un_2_;
	cppVar_44995 = (cppVar_44994 << 3) | 3;
	cppVar_44995 = (cppVar_44995 & cppMask_un_5_);
	cppVar_44996 = (0 << 5) | cppVar_44995;
	cppVar_44996 = (cppVar_44996 & cppMask_un_8_);
	cppVar_44998 = (cppVar_44996 == 152);
	if (cppVar_44998) {
	cppVar_44993 = SCON;
	} else {
	cppVar_45000 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45001 = (cppVar_45000 << 3) | 3;
	cppVar_45001 = (cppVar_45001 & cppMask_un_5_);
	cppVar_45002 = (0 << 5) | cppVar_45001;
	cppVar_45002 = (cppVar_45002 & cppMask_un_8_);
	cppVar_45004 = (cppVar_45002 == 153);
	if (cppVar_45004) {
	cppVar_44999 = SBUF;
	} else {
	cppVar_45006 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45007 = (cppVar_45006 << 3) | 3;
	cppVar_45007 = (cppVar_45007 & cppMask_un_5_);
	cppVar_45008 = (0 << 5) | cppVar_45007;
	cppVar_45008 = (cppVar_45008 & cppMask_un_8_);
	cppVar_45010 = (cppVar_45008 == 160);
	if (cppVar_45010) {
	cppVar_45005 = P2;
	} else {
	cppVar_45012 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45013 = (cppVar_45012 << 3) | 3;
	cppVar_45013 = (cppVar_45013 & cppMask_un_5_);
	cppVar_45014 = (0 << 5) | cppVar_45013;
	cppVar_45014 = (cppVar_45014 & cppMask_un_8_);
	cppVar_45016 = (cppVar_45014 == 168);
	if (cppVar_45016) {
	cppVar_45011 = IE;
	} else {
	cppVar_45018 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45019 = (cppVar_45018 << 3) | 3;
	cppVar_45019 = (cppVar_45019 & cppMask_un_5_);
	cppVar_45020 = (0 << 5) | cppVar_45019;
	cppVar_45020 = (cppVar_45020 & cppMask_un_8_);
	cppVar_45022 = (cppVar_45020 == 176);
	if (cppVar_45022) {
	cppVar_45017 = P3;
	} else {
	cppVar_45024 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45025 = (cppVar_45024 << 3) | 3;
	cppVar_45025 = (cppVar_45025 & cppMask_un_5_);
	cppVar_45026 = (0 << 5) | cppVar_45025;
	cppVar_45026 = (cppVar_45026 & cppMask_un_8_);
	cppVar_45028 = (cppVar_45026 == 184);
	if (cppVar_45028) {
	cppVar_45023 = IP;
	} else {
	cppVar_45030 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45031 = (cppVar_45030 << 3) | 3;
	cppVar_45031 = (cppVar_45031 & cppMask_un_5_);
	cppVar_45032 = (0 << 5) | cppVar_45031;
	cppVar_45032 = (cppVar_45032 & cppMask_un_8_);
	cppVar_45034 = (cppVar_45032 == 208);
	if (cppVar_45034) {
	cppVar_45029 = PSW;
	} else {
	cppVar_45036 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45037 = (cppVar_45036 << 3) | 3;
	cppVar_45037 = (cppVar_45037 & cppMask_un_5_);
	cppVar_45038 = (0 << 5) | cppVar_45037;
	cppVar_45038 = (cppVar_45038 & cppMask_un_8_);
	cppVar_45040 = (cppVar_45038 == 224);
	if (cppVar_45040) {
	cppVar_45035 = ACC;
	} else {
	cppVar_45042 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45043 = (cppVar_45042 << 3) | 3;
	cppVar_45043 = (cppVar_45043 & cppMask_un_5_);
	cppVar_45044 = (0 << 5) | cppVar_45043;
	cppVar_45044 = (cppVar_45044 & cppMask_un_8_);
	cppVar_45046 = (cppVar_45044 == 240);
	if (cppVar_45046) {
	cppVar_45041 = B;
	} else {
	cppVar_45041 = 0;
	}
	cppVar_45035 = cppVar_45041;
	}
	cppVar_45029 = cppVar_45035;
	}
	cppVar_45023 = cppVar_45029;
	}
	cppVar_45017 = cppVar_45023;
	}
	cppVar_45011 = cppVar_45017;
	}
	cppVar_45005 = cppVar_45011;
	}
	cppVar_44999 = cppVar_45005;
	}
	cppVar_44993 = cppVar_44999;
	}
	cppVar_44987 = cppVar_44993;
	}
	cppVar_44981 = cppVar_44987;
	}
	cppVar_44975 = cppVar_44981;
	}
	cppVar_44969 = cppVar_44975;
	}
	cppVar_44963 = cppVar_44969;
	}
	cppVar_44957 = cppVar_44963;
	}
	cppVar_44951 = cppVar_44957;
	}
	cppVar_44945 = cppVar_44951;
	}
	cppVar_44939 = cppVar_44945;
	}
	cppVar_44933 = cppVar_44939;
	}
	cppVar_44927 = cppVar_44933;
	}
	cppVar_44921 = cppVar_44927;
	}
	cppVar_44908 = cppVar_44921;
	}
	cppVar_44902 = cppVar_44908;
	} else {
	cppVar_44902 = PCON;
	}
	cppVar_44898 = cppVar_44902;
	} else {
	cppVar_45049 = ROM.rd(PC);
	cppVar_45051 = (cppVar_45049 == 138);
	if (cppVar_45051) {
	cppVar_45054 = PC + 1;
	cppVar_45054 = (cppVar_45054 & cppMask_un_16_);
	cppVar_45055 = ROM.rd(cppVar_45054);
	cppVar_45057 = (cppVar_45055 == 135);
	if (cppVar_45057) {
	cppVar_45060 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45062 = (cppVar_45060 << 3) | 2;
	cppVar_45062 = (cppVar_45062 & cppMask_un_5_);
	cppVar_45063 = (0 << 5) | cppVar_45062;
	cppVar_45063 = (cppVar_45063 & cppMask_un_8_);
	cppVar_45064 = (cppVar_45063 >> 7) & cppMask_un_1_;
	cppVar_45066 = (cppVar_45064 == 0);
	if (cppVar_45066) {
	cppVar_45067 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45068 = (cppVar_45067 << 3) | 2;
	cppVar_45068 = (cppVar_45068 & cppMask_un_5_);
	cppVar_45069 = (0 << 5) | cppVar_45068;
	cppVar_45069 = (cppVar_45069 & cppMask_un_8_);
	cppVar_45070 = IRAM.rd(cppVar_45069);
	cppVar_45058 = cppVar_45070;
	} else {
	cppVar_45072 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45073 = (cppVar_45072 << 3) | 2;
	cppVar_45073 = (cppVar_45073 & cppMask_un_5_);
	cppVar_45074 = (0 << 5) | cppVar_45073;
	cppVar_45074 = (cppVar_45074 & cppMask_un_8_);
	cppVar_45076 = (cppVar_45074 == 128);
	if (cppVar_45076) {
	cppVar_45071 = P0;
	} else {
	cppVar_45078 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45079 = (cppVar_45078 << 3) | 2;
	cppVar_45079 = (cppVar_45079 & cppMask_un_5_);
	cppVar_45080 = (0 << 5) | cppVar_45079;
	cppVar_45080 = (cppVar_45080 & cppMask_un_8_);
	cppVar_45082 = (cppVar_45080 == 129);
	if (cppVar_45082) {
	cppVar_45077 = SP;
	} else {
	cppVar_45084 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45085 = (cppVar_45084 << 3) | 2;
	cppVar_45085 = (cppVar_45085 & cppMask_un_5_);
	cppVar_45086 = (0 << 5) | cppVar_45085;
	cppVar_45086 = (cppVar_45086 & cppMask_un_8_);
	cppVar_45088 = (cppVar_45086 == 130);
	if (cppVar_45088) {
	cppVar_45083 = DPL;
	} else {
	cppVar_45090 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45091 = (cppVar_45090 << 3) | 2;
	cppVar_45091 = (cppVar_45091 & cppMask_un_5_);
	cppVar_45092 = (0 << 5) | cppVar_45091;
	cppVar_45092 = (cppVar_45092 & cppMask_un_8_);
	cppVar_45094 = (cppVar_45092 == 131);
	if (cppVar_45094) {
	cppVar_45089 = DPH;
	} else {
	cppVar_45096 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45097 = (cppVar_45096 << 3) | 2;
	cppVar_45097 = (cppVar_45097 & cppMask_un_5_);
	cppVar_45098 = (0 << 5) | cppVar_45097;
	cppVar_45098 = (cppVar_45098 & cppMask_un_8_);
	cppVar_45100 = (cppVar_45098 == 135);
	if (cppVar_45100) {
	cppVar_45095 = PCON;
	} else {
	cppVar_45102 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45103 = (cppVar_45102 << 3) | 2;
	cppVar_45103 = (cppVar_45103 & cppMask_un_5_);
	cppVar_45104 = (0 << 5) | cppVar_45103;
	cppVar_45104 = (cppVar_45104 & cppMask_un_8_);
	cppVar_45106 = (cppVar_45104 == 136);
	if (cppVar_45106) {
	cppVar_45101 = TCON;
	} else {
	cppVar_45108 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45109 = (cppVar_45108 << 3) | 2;
	cppVar_45109 = (cppVar_45109 & cppMask_un_5_);
	cppVar_45110 = (0 << 5) | cppVar_45109;
	cppVar_45110 = (cppVar_45110 & cppMask_un_8_);
	cppVar_45112 = (cppVar_45110 == 137);
	if (cppVar_45112) {
	cppVar_45107 = TMOD;
	} else {
	cppVar_45114 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45115 = (cppVar_45114 << 3) | 2;
	cppVar_45115 = (cppVar_45115 & cppMask_un_5_);
	cppVar_45116 = (0 << 5) | cppVar_45115;
	cppVar_45116 = (cppVar_45116 & cppMask_un_8_);
	cppVar_45118 = (cppVar_45116 == 138);
	if (cppVar_45118) {
	cppVar_45113 = TL0;
	} else {
	cppVar_45120 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45121 = (cppVar_45120 << 3) | 2;
	cppVar_45121 = (cppVar_45121 & cppMask_un_5_);
	cppVar_45122 = (0 << 5) | cppVar_45121;
	cppVar_45122 = (cppVar_45122 & cppMask_un_8_);
	cppVar_45124 = (cppVar_45122 == 140);
	if (cppVar_45124) {
	cppVar_45119 = TH0;
	} else {
	cppVar_45126 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45127 = (cppVar_45126 << 3) | 2;
	cppVar_45127 = (cppVar_45127 & cppMask_un_5_);
	cppVar_45128 = (0 << 5) | cppVar_45127;
	cppVar_45128 = (cppVar_45128 & cppMask_un_8_);
	cppVar_45130 = (cppVar_45128 == 139);
	if (cppVar_45130) {
	cppVar_45125 = TL1;
	} else {
	cppVar_45132 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45133 = (cppVar_45132 << 3) | 2;
	cppVar_45133 = (cppVar_45133 & cppMask_un_5_);
	cppVar_45134 = (0 << 5) | cppVar_45133;
	cppVar_45134 = (cppVar_45134 & cppMask_un_8_);
	cppVar_45136 = (cppVar_45134 == 141);
	if (cppVar_45136) {
	cppVar_45131 = TH1;
	} else {
	cppVar_45138 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45139 = (cppVar_45138 << 3) | 2;
	cppVar_45139 = (cppVar_45139 & cppMask_un_5_);
	cppVar_45140 = (0 << 5) | cppVar_45139;
	cppVar_45140 = (cppVar_45140 & cppMask_un_8_);
	cppVar_45142 = (cppVar_45140 == 144);
	if (cppVar_45142) {
	cppVar_45137 = P1;
	} else {
	cppVar_45144 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45145 = (cppVar_45144 << 3) | 2;
	cppVar_45145 = (cppVar_45145 & cppMask_un_5_);
	cppVar_45146 = (0 << 5) | cppVar_45145;
	cppVar_45146 = (cppVar_45146 & cppMask_un_8_);
	cppVar_45148 = (cppVar_45146 == 152);
	if (cppVar_45148) {
	cppVar_45143 = SCON;
	} else {
	cppVar_45150 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45151 = (cppVar_45150 << 3) | 2;
	cppVar_45151 = (cppVar_45151 & cppMask_un_5_);
	cppVar_45152 = (0 << 5) | cppVar_45151;
	cppVar_45152 = (cppVar_45152 & cppMask_un_8_);
	cppVar_45154 = (cppVar_45152 == 153);
	if (cppVar_45154) {
	cppVar_45149 = SBUF;
	} else {
	cppVar_45156 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45157 = (cppVar_45156 << 3) | 2;
	cppVar_45157 = (cppVar_45157 & cppMask_un_5_);
	cppVar_45158 = (0 << 5) | cppVar_45157;
	cppVar_45158 = (cppVar_45158 & cppMask_un_8_);
	cppVar_45160 = (cppVar_45158 == 160);
	if (cppVar_45160) {
	cppVar_45155 = P2;
	} else {
	cppVar_45162 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45163 = (cppVar_45162 << 3) | 2;
	cppVar_45163 = (cppVar_45163 & cppMask_un_5_);
	cppVar_45164 = (0 << 5) | cppVar_45163;
	cppVar_45164 = (cppVar_45164 & cppMask_un_8_);
	cppVar_45166 = (cppVar_45164 == 168);
	if (cppVar_45166) {
	cppVar_45161 = IE;
	} else {
	cppVar_45168 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45169 = (cppVar_45168 << 3) | 2;
	cppVar_45169 = (cppVar_45169 & cppMask_un_5_);
	cppVar_45170 = (0 << 5) | cppVar_45169;
	cppVar_45170 = (cppVar_45170 & cppMask_un_8_);
	cppVar_45172 = (cppVar_45170 == 176);
	if (cppVar_45172) {
	cppVar_45167 = P3;
	} else {
	cppVar_45174 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45175 = (cppVar_45174 << 3) | 2;
	cppVar_45175 = (cppVar_45175 & cppMask_un_5_);
	cppVar_45176 = (0 << 5) | cppVar_45175;
	cppVar_45176 = (cppVar_45176 & cppMask_un_8_);
	cppVar_45178 = (cppVar_45176 == 184);
	if (cppVar_45178) {
	cppVar_45173 = IP;
	} else {
	cppVar_45180 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45181 = (cppVar_45180 << 3) | 2;
	cppVar_45181 = (cppVar_45181 & cppMask_un_5_);
	cppVar_45182 = (0 << 5) | cppVar_45181;
	cppVar_45182 = (cppVar_45182 & cppMask_un_8_);
	cppVar_45184 = (cppVar_45182 == 208);
	if (cppVar_45184) {
	cppVar_45179 = PSW;
	} else {
	cppVar_45186 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45187 = (cppVar_45186 << 3) | 2;
	cppVar_45187 = (cppVar_45187 & cppMask_un_5_);
	cppVar_45188 = (0 << 5) | cppVar_45187;
	cppVar_45188 = (cppVar_45188 & cppMask_un_8_);
	cppVar_45190 = (cppVar_45188 == 224);
	if (cppVar_45190) {
	cppVar_45185 = ACC;
	} else {
	cppVar_45192 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45193 = (cppVar_45192 << 3) | 2;
	cppVar_45193 = (cppVar_45193 & cppMask_un_5_);
	cppVar_45194 = (0 << 5) | cppVar_45193;
	cppVar_45194 = (cppVar_45194 & cppMask_un_8_);
	cppVar_45196 = (cppVar_45194 == 240);
	if (cppVar_45196) {
	cppVar_45191 = B;
	} else {
	cppVar_45191 = 0;
	}
	cppVar_45185 = cppVar_45191;
	}
	cppVar_45179 = cppVar_45185;
	}
	cppVar_45173 = cppVar_45179;
	}
	cppVar_45167 = cppVar_45173;
	}
	cppVar_45161 = cppVar_45167;
	}
	cppVar_45155 = cppVar_45161;
	}
	cppVar_45149 = cppVar_45155;
	}
	cppVar_45143 = cppVar_45149;
	}
	cppVar_45137 = cppVar_45143;
	}
	cppVar_45131 = cppVar_45137;
	}
	cppVar_45125 = cppVar_45131;
	}
	cppVar_45119 = cppVar_45125;
	}
	cppVar_45113 = cppVar_45119;
	}
	cppVar_45107 = cppVar_45113;
	}
	cppVar_45101 = cppVar_45107;
	}
	cppVar_45095 = cppVar_45101;
	}
	cppVar_45089 = cppVar_45095;
	}
	cppVar_45083 = cppVar_45089;
	}
	cppVar_45077 = cppVar_45083;
	}
	cppVar_45071 = cppVar_45077;
	}
	cppVar_45058 = cppVar_45071;
	}
	cppVar_45052 = cppVar_45058;
	} else {
	cppVar_45052 = PCON;
	}
	cppVar_45048 = cppVar_45052;
	} else {
	cppVar_45199 = ROM.rd(PC);
	cppVar_45201 = (cppVar_45199 == 137);
	if (cppVar_45201) {
	cppVar_45204 = PC + 1;
	cppVar_45204 = (cppVar_45204 & cppMask_un_16_);
	cppVar_45205 = ROM.rd(cppVar_45204);
	cppVar_45207 = (cppVar_45205 == 135);
	if (cppVar_45207) {
	cppVar_45210 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45212 = (cppVar_45210 << 3) | 1;
	cppVar_45212 = (cppVar_45212 & cppMask_un_5_);
	cppVar_45213 = (0 << 5) | cppVar_45212;
	cppVar_45213 = (cppVar_45213 & cppMask_un_8_);
	cppVar_45214 = (cppVar_45213 >> 7) & cppMask_un_1_;
	cppVar_45216 = (cppVar_45214 == 0);
	if (cppVar_45216) {
	cppVar_45217 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45218 = (cppVar_45217 << 3) | 1;
	cppVar_45218 = (cppVar_45218 & cppMask_un_5_);
	cppVar_45219 = (0 << 5) | cppVar_45218;
	cppVar_45219 = (cppVar_45219 & cppMask_un_8_);
	cppVar_45220 = IRAM.rd(cppVar_45219);
	cppVar_45208 = cppVar_45220;
	} else {
	cppVar_45222 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45223 = (cppVar_45222 << 3) | 1;
	cppVar_45223 = (cppVar_45223 & cppMask_un_5_);
	cppVar_45224 = (0 << 5) | cppVar_45223;
	cppVar_45224 = (cppVar_45224 & cppMask_un_8_);
	cppVar_45226 = (cppVar_45224 == 128);
	if (cppVar_45226) {
	cppVar_45221 = P0;
	} else {
	cppVar_45228 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45229 = (cppVar_45228 << 3) | 1;
	cppVar_45229 = (cppVar_45229 & cppMask_un_5_);
	cppVar_45230 = (0 << 5) | cppVar_45229;
	cppVar_45230 = (cppVar_45230 & cppMask_un_8_);
	cppVar_45232 = (cppVar_45230 == 129);
	if (cppVar_45232) {
	cppVar_45227 = SP;
	} else {
	cppVar_45234 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45235 = (cppVar_45234 << 3) | 1;
	cppVar_45235 = (cppVar_45235 & cppMask_un_5_);
	cppVar_45236 = (0 << 5) | cppVar_45235;
	cppVar_45236 = (cppVar_45236 & cppMask_un_8_);
	cppVar_45238 = (cppVar_45236 == 130);
	if (cppVar_45238) {
	cppVar_45233 = DPL;
	} else {
	cppVar_45240 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45241 = (cppVar_45240 << 3) | 1;
	cppVar_45241 = (cppVar_45241 & cppMask_un_5_);
	cppVar_45242 = (0 << 5) | cppVar_45241;
	cppVar_45242 = (cppVar_45242 & cppMask_un_8_);
	cppVar_45244 = (cppVar_45242 == 131);
	if (cppVar_45244) {
	cppVar_45239 = DPH;
	} else {
	cppVar_45246 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45247 = (cppVar_45246 << 3) | 1;
	cppVar_45247 = (cppVar_45247 & cppMask_un_5_);
	cppVar_45248 = (0 << 5) | cppVar_45247;
	cppVar_45248 = (cppVar_45248 & cppMask_un_8_);
	cppVar_45250 = (cppVar_45248 == 135);
	if (cppVar_45250) {
	cppVar_45245 = PCON;
	} else {
	cppVar_45252 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45253 = (cppVar_45252 << 3) | 1;
	cppVar_45253 = (cppVar_45253 & cppMask_un_5_);
	cppVar_45254 = (0 << 5) | cppVar_45253;
	cppVar_45254 = (cppVar_45254 & cppMask_un_8_);
	cppVar_45256 = (cppVar_45254 == 136);
	if (cppVar_45256) {
	cppVar_45251 = TCON;
	} else {
	cppVar_45258 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45259 = (cppVar_45258 << 3) | 1;
	cppVar_45259 = (cppVar_45259 & cppMask_un_5_);
	cppVar_45260 = (0 << 5) | cppVar_45259;
	cppVar_45260 = (cppVar_45260 & cppMask_un_8_);
	cppVar_45262 = (cppVar_45260 == 137);
	if (cppVar_45262) {
	cppVar_45257 = TMOD;
	} else {
	cppVar_45264 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45265 = (cppVar_45264 << 3) | 1;
	cppVar_45265 = (cppVar_45265 & cppMask_un_5_);
	cppVar_45266 = (0 << 5) | cppVar_45265;
	cppVar_45266 = (cppVar_45266 & cppMask_un_8_);
	cppVar_45268 = (cppVar_45266 == 138);
	if (cppVar_45268) {
	cppVar_45263 = TL0;
	} else {
	cppVar_45270 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45271 = (cppVar_45270 << 3) | 1;
	cppVar_45271 = (cppVar_45271 & cppMask_un_5_);
	cppVar_45272 = (0 << 5) | cppVar_45271;
	cppVar_45272 = (cppVar_45272 & cppMask_un_8_);
	cppVar_45274 = (cppVar_45272 == 140);
	if (cppVar_45274) {
	cppVar_45269 = TH0;
	} else {
	cppVar_45276 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45277 = (cppVar_45276 << 3) | 1;
	cppVar_45277 = (cppVar_45277 & cppMask_un_5_);
	cppVar_45278 = (0 << 5) | cppVar_45277;
	cppVar_45278 = (cppVar_45278 & cppMask_un_8_);
	cppVar_45280 = (cppVar_45278 == 139);
	if (cppVar_45280) {
	cppVar_45275 = TL1;
	} else {
	cppVar_45282 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45283 = (cppVar_45282 << 3) | 1;
	cppVar_45283 = (cppVar_45283 & cppMask_un_5_);
	cppVar_45284 = (0 << 5) | cppVar_45283;
	cppVar_45284 = (cppVar_45284 & cppMask_un_8_);
	cppVar_45286 = (cppVar_45284 == 141);
	if (cppVar_45286) {
	cppVar_45281 = TH1;
	} else {
	cppVar_45288 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45289 = (cppVar_45288 << 3) | 1;
	cppVar_45289 = (cppVar_45289 & cppMask_un_5_);
	cppVar_45290 = (0 << 5) | cppVar_45289;
	cppVar_45290 = (cppVar_45290 & cppMask_un_8_);
	cppVar_45292 = (cppVar_45290 == 144);
	if (cppVar_45292) {
	cppVar_45287 = P1;
	} else {
	cppVar_45294 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45295 = (cppVar_45294 << 3) | 1;
	cppVar_45295 = (cppVar_45295 & cppMask_un_5_);
	cppVar_45296 = (0 << 5) | cppVar_45295;
	cppVar_45296 = (cppVar_45296 & cppMask_un_8_);
	cppVar_45298 = (cppVar_45296 == 152);
	if (cppVar_45298) {
	cppVar_45293 = SCON;
	} else {
	cppVar_45300 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45301 = (cppVar_45300 << 3) | 1;
	cppVar_45301 = (cppVar_45301 & cppMask_un_5_);
	cppVar_45302 = (0 << 5) | cppVar_45301;
	cppVar_45302 = (cppVar_45302 & cppMask_un_8_);
	cppVar_45304 = (cppVar_45302 == 153);
	if (cppVar_45304) {
	cppVar_45299 = SBUF;
	} else {
	cppVar_45306 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45307 = (cppVar_45306 << 3) | 1;
	cppVar_45307 = (cppVar_45307 & cppMask_un_5_);
	cppVar_45308 = (0 << 5) | cppVar_45307;
	cppVar_45308 = (cppVar_45308 & cppMask_un_8_);
	cppVar_45310 = (cppVar_45308 == 160);
	if (cppVar_45310) {
	cppVar_45305 = P2;
	} else {
	cppVar_45312 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45313 = (cppVar_45312 << 3) | 1;
	cppVar_45313 = (cppVar_45313 & cppMask_un_5_);
	cppVar_45314 = (0 << 5) | cppVar_45313;
	cppVar_45314 = (cppVar_45314 & cppMask_un_8_);
	cppVar_45316 = (cppVar_45314 == 168);
	if (cppVar_45316) {
	cppVar_45311 = IE;
	} else {
	cppVar_45318 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45319 = (cppVar_45318 << 3) | 1;
	cppVar_45319 = (cppVar_45319 & cppMask_un_5_);
	cppVar_45320 = (0 << 5) | cppVar_45319;
	cppVar_45320 = (cppVar_45320 & cppMask_un_8_);
	cppVar_45322 = (cppVar_45320 == 176);
	if (cppVar_45322) {
	cppVar_45317 = P3;
	} else {
	cppVar_45324 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45325 = (cppVar_45324 << 3) | 1;
	cppVar_45325 = (cppVar_45325 & cppMask_un_5_);
	cppVar_45326 = (0 << 5) | cppVar_45325;
	cppVar_45326 = (cppVar_45326 & cppMask_un_8_);
	cppVar_45328 = (cppVar_45326 == 184);
	if (cppVar_45328) {
	cppVar_45323 = IP;
	} else {
	cppVar_45330 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45331 = (cppVar_45330 << 3) | 1;
	cppVar_45331 = (cppVar_45331 & cppMask_un_5_);
	cppVar_45332 = (0 << 5) | cppVar_45331;
	cppVar_45332 = (cppVar_45332 & cppMask_un_8_);
	cppVar_45334 = (cppVar_45332 == 208);
	if (cppVar_45334) {
	cppVar_45329 = PSW;
	} else {
	cppVar_45336 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45337 = (cppVar_45336 << 3) | 1;
	cppVar_45337 = (cppVar_45337 & cppMask_un_5_);
	cppVar_45338 = (0 << 5) | cppVar_45337;
	cppVar_45338 = (cppVar_45338 & cppMask_un_8_);
	cppVar_45340 = (cppVar_45338 == 224);
	if (cppVar_45340) {
	cppVar_45335 = ACC;
	} else {
	cppVar_45342 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45343 = (cppVar_45342 << 3) | 1;
	cppVar_45343 = (cppVar_45343 & cppMask_un_5_);
	cppVar_45344 = (0 << 5) | cppVar_45343;
	cppVar_45344 = (cppVar_45344 & cppMask_un_8_);
	cppVar_45346 = (cppVar_45344 == 240);
	if (cppVar_45346) {
	cppVar_45341 = B;
	} else {
	cppVar_45341 = 0;
	}
	cppVar_45335 = cppVar_45341;
	}
	cppVar_45329 = cppVar_45335;
	}
	cppVar_45323 = cppVar_45329;
	}
	cppVar_45317 = cppVar_45323;
	}
	cppVar_45311 = cppVar_45317;
	}
	cppVar_45305 = cppVar_45311;
	}
	cppVar_45299 = cppVar_45305;
	}
	cppVar_45293 = cppVar_45299;
	}
	cppVar_45287 = cppVar_45293;
	}
	cppVar_45281 = cppVar_45287;
	}
	cppVar_45275 = cppVar_45281;
	}
	cppVar_45269 = cppVar_45275;
	}
	cppVar_45263 = cppVar_45269;
	}
	cppVar_45257 = cppVar_45263;
	}
	cppVar_45251 = cppVar_45257;
	}
	cppVar_45245 = cppVar_45251;
	}
	cppVar_45239 = cppVar_45245;
	}
	cppVar_45233 = cppVar_45239;
	}
	cppVar_45227 = cppVar_45233;
	}
	cppVar_45221 = cppVar_45227;
	}
	cppVar_45208 = cppVar_45221;
	}
	cppVar_45202 = cppVar_45208;
	} else {
	cppVar_45202 = PCON;
	}
	cppVar_45198 = cppVar_45202;
	} else {
	cppVar_45349 = ROM.rd(PC);
	cppVar_45351 = (cppVar_45349 == 136);
	if (cppVar_45351) {
	cppVar_45354 = PC + 1;
	cppVar_45354 = (cppVar_45354 & cppMask_un_16_);
	cppVar_45355 = ROM.rd(cppVar_45354);
	cppVar_45357 = (cppVar_45355 == 135);
	if (cppVar_45357) {
	cppVar_45360 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45362 = (cppVar_45360 << 3) | 0;
	cppVar_45362 = (cppVar_45362 & cppMask_un_5_);
	cppVar_45363 = (0 << 5) | cppVar_45362;
	cppVar_45363 = (cppVar_45363 & cppMask_un_8_);
	cppVar_45364 = (cppVar_45363 >> 7) & cppMask_un_1_;
	cppVar_45366 = (cppVar_45364 == 0);
	if (cppVar_45366) {
	cppVar_45367 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45368 = (cppVar_45367 << 3) | 0;
	cppVar_45368 = (cppVar_45368 & cppMask_un_5_);
	cppVar_45369 = (0 << 5) | cppVar_45368;
	cppVar_45369 = (cppVar_45369 & cppMask_un_8_);
	cppVar_45370 = IRAM.rd(cppVar_45369);
	cppVar_45358 = cppVar_45370;
	} else {
	cppVar_45372 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45373 = (cppVar_45372 << 3) | 0;
	cppVar_45373 = (cppVar_45373 & cppMask_un_5_);
	cppVar_45374 = (0 << 5) | cppVar_45373;
	cppVar_45374 = (cppVar_45374 & cppMask_un_8_);
	cppVar_45376 = (cppVar_45374 == 128);
	if (cppVar_45376) {
	cppVar_45371 = P0;
	} else {
	cppVar_45378 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45379 = (cppVar_45378 << 3) | 0;
	cppVar_45379 = (cppVar_45379 & cppMask_un_5_);
	cppVar_45380 = (0 << 5) | cppVar_45379;
	cppVar_45380 = (cppVar_45380 & cppMask_un_8_);
	cppVar_45382 = (cppVar_45380 == 129);
	if (cppVar_45382) {
	cppVar_45377 = SP;
	} else {
	cppVar_45384 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45385 = (cppVar_45384 << 3) | 0;
	cppVar_45385 = (cppVar_45385 & cppMask_un_5_);
	cppVar_45386 = (0 << 5) | cppVar_45385;
	cppVar_45386 = (cppVar_45386 & cppMask_un_8_);
	cppVar_45388 = (cppVar_45386 == 130);
	if (cppVar_45388) {
	cppVar_45383 = DPL;
	} else {
	cppVar_45390 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45391 = (cppVar_45390 << 3) | 0;
	cppVar_45391 = (cppVar_45391 & cppMask_un_5_);
	cppVar_45392 = (0 << 5) | cppVar_45391;
	cppVar_45392 = (cppVar_45392 & cppMask_un_8_);
	cppVar_45394 = (cppVar_45392 == 131);
	if (cppVar_45394) {
	cppVar_45389 = DPH;
	} else {
	cppVar_45396 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45397 = (cppVar_45396 << 3) | 0;
	cppVar_45397 = (cppVar_45397 & cppMask_un_5_);
	cppVar_45398 = (0 << 5) | cppVar_45397;
	cppVar_45398 = (cppVar_45398 & cppMask_un_8_);
	cppVar_45400 = (cppVar_45398 == 135);
	if (cppVar_45400) {
	cppVar_45395 = PCON;
	} else {
	cppVar_45402 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45403 = (cppVar_45402 << 3) | 0;
	cppVar_45403 = (cppVar_45403 & cppMask_un_5_);
	cppVar_45404 = (0 << 5) | cppVar_45403;
	cppVar_45404 = (cppVar_45404 & cppMask_un_8_);
	cppVar_45406 = (cppVar_45404 == 136);
	if (cppVar_45406) {
	cppVar_45401 = TCON;
	} else {
	cppVar_45408 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45409 = (cppVar_45408 << 3) | 0;
	cppVar_45409 = (cppVar_45409 & cppMask_un_5_);
	cppVar_45410 = (0 << 5) | cppVar_45409;
	cppVar_45410 = (cppVar_45410 & cppMask_un_8_);
	cppVar_45412 = (cppVar_45410 == 137);
	if (cppVar_45412) {
	cppVar_45407 = TMOD;
	} else {
	cppVar_45414 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45415 = (cppVar_45414 << 3) | 0;
	cppVar_45415 = (cppVar_45415 & cppMask_un_5_);
	cppVar_45416 = (0 << 5) | cppVar_45415;
	cppVar_45416 = (cppVar_45416 & cppMask_un_8_);
	cppVar_45418 = (cppVar_45416 == 138);
	if (cppVar_45418) {
	cppVar_45413 = TL0;
	} else {
	cppVar_45420 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45421 = (cppVar_45420 << 3) | 0;
	cppVar_45421 = (cppVar_45421 & cppMask_un_5_);
	cppVar_45422 = (0 << 5) | cppVar_45421;
	cppVar_45422 = (cppVar_45422 & cppMask_un_8_);
	cppVar_45424 = (cppVar_45422 == 140);
	if (cppVar_45424) {
	cppVar_45419 = TH0;
	} else {
	cppVar_45426 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45427 = (cppVar_45426 << 3) | 0;
	cppVar_45427 = (cppVar_45427 & cppMask_un_5_);
	cppVar_45428 = (0 << 5) | cppVar_45427;
	cppVar_45428 = (cppVar_45428 & cppMask_un_8_);
	cppVar_45430 = (cppVar_45428 == 139);
	if (cppVar_45430) {
	cppVar_45425 = TL1;
	} else {
	cppVar_45432 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45433 = (cppVar_45432 << 3) | 0;
	cppVar_45433 = (cppVar_45433 & cppMask_un_5_);
	cppVar_45434 = (0 << 5) | cppVar_45433;
	cppVar_45434 = (cppVar_45434 & cppMask_un_8_);
	cppVar_45436 = (cppVar_45434 == 141);
	if (cppVar_45436) {
	cppVar_45431 = TH1;
	} else {
	cppVar_45438 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45439 = (cppVar_45438 << 3) | 0;
	cppVar_45439 = (cppVar_45439 & cppMask_un_5_);
	cppVar_45440 = (0 << 5) | cppVar_45439;
	cppVar_45440 = (cppVar_45440 & cppMask_un_8_);
	cppVar_45442 = (cppVar_45440 == 144);
	if (cppVar_45442) {
	cppVar_45437 = P1;
	} else {
	cppVar_45444 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45445 = (cppVar_45444 << 3) | 0;
	cppVar_45445 = (cppVar_45445 & cppMask_un_5_);
	cppVar_45446 = (0 << 5) | cppVar_45445;
	cppVar_45446 = (cppVar_45446 & cppMask_un_8_);
	cppVar_45448 = (cppVar_45446 == 152);
	if (cppVar_45448) {
	cppVar_45443 = SCON;
	} else {
	cppVar_45450 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45451 = (cppVar_45450 << 3) | 0;
	cppVar_45451 = (cppVar_45451 & cppMask_un_5_);
	cppVar_45452 = (0 << 5) | cppVar_45451;
	cppVar_45452 = (cppVar_45452 & cppMask_un_8_);
	cppVar_45454 = (cppVar_45452 == 153);
	if (cppVar_45454) {
	cppVar_45449 = SBUF;
	} else {
	cppVar_45456 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45457 = (cppVar_45456 << 3) | 0;
	cppVar_45457 = (cppVar_45457 & cppMask_un_5_);
	cppVar_45458 = (0 << 5) | cppVar_45457;
	cppVar_45458 = (cppVar_45458 & cppMask_un_8_);
	cppVar_45460 = (cppVar_45458 == 160);
	if (cppVar_45460) {
	cppVar_45455 = P2;
	} else {
	cppVar_45462 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45463 = (cppVar_45462 << 3) | 0;
	cppVar_45463 = (cppVar_45463 & cppMask_un_5_);
	cppVar_45464 = (0 << 5) | cppVar_45463;
	cppVar_45464 = (cppVar_45464 & cppMask_un_8_);
	cppVar_45466 = (cppVar_45464 == 168);
	if (cppVar_45466) {
	cppVar_45461 = IE;
	} else {
	cppVar_45468 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45469 = (cppVar_45468 << 3) | 0;
	cppVar_45469 = (cppVar_45469 & cppMask_un_5_);
	cppVar_45470 = (0 << 5) | cppVar_45469;
	cppVar_45470 = (cppVar_45470 & cppMask_un_8_);
	cppVar_45472 = (cppVar_45470 == 176);
	if (cppVar_45472) {
	cppVar_45467 = P3;
	} else {
	cppVar_45474 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45475 = (cppVar_45474 << 3) | 0;
	cppVar_45475 = (cppVar_45475 & cppMask_un_5_);
	cppVar_45476 = (0 << 5) | cppVar_45475;
	cppVar_45476 = (cppVar_45476 & cppMask_un_8_);
	cppVar_45478 = (cppVar_45476 == 184);
	if (cppVar_45478) {
	cppVar_45473 = IP;
	} else {
	cppVar_45480 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45481 = (cppVar_45480 << 3) | 0;
	cppVar_45481 = (cppVar_45481 & cppMask_un_5_);
	cppVar_45482 = (0 << 5) | cppVar_45481;
	cppVar_45482 = (cppVar_45482 & cppMask_un_8_);
	cppVar_45484 = (cppVar_45482 == 208);
	if (cppVar_45484) {
	cppVar_45479 = PSW;
	} else {
	cppVar_45486 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45487 = (cppVar_45486 << 3) | 0;
	cppVar_45487 = (cppVar_45487 & cppMask_un_5_);
	cppVar_45488 = (0 << 5) | cppVar_45487;
	cppVar_45488 = (cppVar_45488 & cppMask_un_8_);
	cppVar_45490 = (cppVar_45488 == 224);
	if (cppVar_45490) {
	cppVar_45485 = ACC;
	} else {
	cppVar_45492 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45493 = (cppVar_45492 << 3) | 0;
	cppVar_45493 = (cppVar_45493 & cppMask_un_5_);
	cppVar_45494 = (0 << 5) | cppVar_45493;
	cppVar_45494 = (cppVar_45494 & cppMask_un_8_);
	cppVar_45496 = (cppVar_45494 == 240);
	if (cppVar_45496) {
	cppVar_45491 = B;
	} else {
	cppVar_45491 = 0;
	}
	cppVar_45485 = cppVar_45491;
	}
	cppVar_45479 = cppVar_45485;
	}
	cppVar_45473 = cppVar_45479;
	}
	cppVar_45467 = cppVar_45473;
	}
	cppVar_45461 = cppVar_45467;
	}
	cppVar_45455 = cppVar_45461;
	}
	cppVar_45449 = cppVar_45455;
	}
	cppVar_45443 = cppVar_45449;
	}
	cppVar_45437 = cppVar_45443;
	}
	cppVar_45431 = cppVar_45437;
	}
	cppVar_45425 = cppVar_45431;
	}
	cppVar_45419 = cppVar_45425;
	}
	cppVar_45413 = cppVar_45419;
	}
	cppVar_45407 = cppVar_45413;
	}
	cppVar_45401 = cppVar_45407;
	}
	cppVar_45395 = cppVar_45401;
	}
	cppVar_45389 = cppVar_45395;
	}
	cppVar_45383 = cppVar_45389;
	}
	cppVar_45377 = cppVar_45383;
	}
	cppVar_45371 = cppVar_45377;
	}
	cppVar_45358 = cppVar_45371;
	}
	cppVar_45352 = cppVar_45358;
	} else {
	cppVar_45352 = PCON;
	}
	cppVar_45348 = cppVar_45352;
	} else {
	cppVar_45499 = ROM.rd(PC);
	cppVar_45501 = (cppVar_45499 == 135);
	if (cppVar_45501) {
	cppVar_45504 = PC + 1;
	cppVar_45504 = (cppVar_45504 & cppMask_un_16_);
	cppVar_45505 = ROM.rd(cppVar_45504);
	cppVar_45507 = (cppVar_45505 == 135);
	if (cppVar_45507) {
	cppVar_45509 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45511 = (cppVar_45509 << 3) | 1;
	cppVar_45511 = (cppVar_45511 & cppMask_un_5_);
	cppVar_45512 = (0 << 5) | cppVar_45511;
	cppVar_45512 = (cppVar_45512 & cppMask_un_8_);
	cppVar_45513 = IRAM.rd(cppVar_45512);
	cppVar_45514 = IRAM.rd(cppVar_45513);
	cppVar_45502 = cppVar_45514;
	} else {
	cppVar_45502 = PCON;
	}
	cppVar_45498 = cppVar_45502;
	} else {
	cppVar_45516 = ROM.rd(PC);
	cppVar_45518 = (cppVar_45516 == 134);
	if (cppVar_45518) {
	cppVar_45521 = PC + 1;
	cppVar_45521 = (cppVar_45521 & cppMask_un_16_);
	cppVar_45522 = ROM.rd(cppVar_45521);
	cppVar_45524 = (cppVar_45522 == 135);
	if (cppVar_45524) {
	cppVar_45526 = (PSW >> 3) & cppMask_un_2_;
	cppVar_45528 = (cppVar_45526 << 3) | 0;
	cppVar_45528 = (cppVar_45528 & cppMask_un_5_);
	cppVar_45529 = (0 << 5) | cppVar_45528;
	cppVar_45529 = (cppVar_45529 & cppMask_un_8_);
	cppVar_45530 = IRAM.rd(cppVar_45529);
	cppVar_45531 = IRAM.rd(cppVar_45530);
	cppVar_45519 = cppVar_45531;
	} else {
	cppVar_45519 = PCON;
	}
	cppVar_45515 = cppVar_45519;
	} else {
	cppVar_45533 = ROM.rd(PC);
	cppVar_45535 = (cppVar_45533 == 133);
	if (cppVar_45535) {
	cppVar_45538 = PC + 2;
	cppVar_45538 = (cppVar_45538 & cppMask_un_16_);
	cppVar_45539 = ROM.rd(cppVar_45538);
	cppVar_45541 = (cppVar_45539 == 135);
	if (cppVar_45541) {
	cppVar_45544 = PC + 1;
	cppVar_45544 = (cppVar_45544 & cppMask_un_16_);
	cppVar_45545 = ROM.rd(cppVar_45544);
	cppVar_45546 = (cppVar_45545 >> 7) & cppMask_un_1_;
	cppVar_45548 = (cppVar_45546 == 0);
	if (cppVar_45548) {
	cppVar_45549 = PC + 1;
	cppVar_45549 = (cppVar_45549 & cppMask_un_16_);
	cppVar_45550 = ROM.rd(cppVar_45549);
	cppVar_45551 = IRAM.rd(cppVar_45550);
	cppVar_45542 = cppVar_45551;
	} else {
	cppVar_45553 = PC + 1;
	cppVar_45553 = (cppVar_45553 & cppMask_un_16_);
	cppVar_45554 = ROM.rd(cppVar_45553);
	cppVar_45556 = (cppVar_45554 == 128);
	if (cppVar_45556) {
	cppVar_45552 = P0;
	} else {
	cppVar_45558 = PC + 1;
	cppVar_45558 = (cppVar_45558 & cppMask_un_16_);
	cppVar_45559 = ROM.rd(cppVar_45558);
	cppVar_45561 = (cppVar_45559 == 129);
	if (cppVar_45561) {
	cppVar_45557 = SP;
	} else {
	cppVar_45563 = PC + 1;
	cppVar_45563 = (cppVar_45563 & cppMask_un_16_);
	cppVar_45564 = ROM.rd(cppVar_45563);
	cppVar_45566 = (cppVar_45564 == 130);
	if (cppVar_45566) {
	cppVar_45562 = DPL;
	} else {
	cppVar_45568 = PC + 1;
	cppVar_45568 = (cppVar_45568 & cppMask_un_16_);
	cppVar_45569 = ROM.rd(cppVar_45568);
	cppVar_45571 = (cppVar_45569 == 131);
	if (cppVar_45571) {
	cppVar_45567 = DPH;
	} else {
	cppVar_45573 = PC + 1;
	cppVar_45573 = (cppVar_45573 & cppMask_un_16_);
	cppVar_45574 = ROM.rd(cppVar_45573);
	cppVar_45576 = (cppVar_45574 == 135);
	if (cppVar_45576) {
	cppVar_45572 = PCON;
	} else {
	cppVar_45578 = PC + 1;
	cppVar_45578 = (cppVar_45578 & cppMask_un_16_);
	cppVar_45579 = ROM.rd(cppVar_45578);
	cppVar_45581 = (cppVar_45579 == 136);
	if (cppVar_45581) {
	cppVar_45577 = TCON;
	} else {
	cppVar_45583 = PC + 1;
	cppVar_45583 = (cppVar_45583 & cppMask_un_16_);
	cppVar_45584 = ROM.rd(cppVar_45583);
	cppVar_45586 = (cppVar_45584 == 137);
	if (cppVar_45586) {
	cppVar_45582 = TMOD;
	} else {
	cppVar_45588 = PC + 1;
	cppVar_45588 = (cppVar_45588 & cppMask_un_16_);
	cppVar_45589 = ROM.rd(cppVar_45588);
	cppVar_45591 = (cppVar_45589 == 138);
	if (cppVar_45591) {
	cppVar_45587 = TL0;
	} else {
	cppVar_45593 = PC + 1;
	cppVar_45593 = (cppVar_45593 & cppMask_un_16_);
	cppVar_45594 = ROM.rd(cppVar_45593);
	cppVar_45596 = (cppVar_45594 == 140);
	if (cppVar_45596) {
	cppVar_45592 = TH0;
	} else {
	cppVar_45598 = PC + 1;
	cppVar_45598 = (cppVar_45598 & cppMask_un_16_);
	cppVar_45599 = ROM.rd(cppVar_45598);
	cppVar_45601 = (cppVar_45599 == 139);
	if (cppVar_45601) {
	cppVar_45597 = TL1;
	} else {
	cppVar_45603 = PC + 1;
	cppVar_45603 = (cppVar_45603 & cppMask_un_16_);
	cppVar_45604 = ROM.rd(cppVar_45603);
	cppVar_45606 = (cppVar_45604 == 141);
	if (cppVar_45606) {
	cppVar_45602 = TH1;
	} else {
	cppVar_45608 = PC + 1;
	cppVar_45608 = (cppVar_45608 & cppMask_un_16_);
	cppVar_45609 = ROM.rd(cppVar_45608);
	cppVar_45611 = (cppVar_45609 == 144);
	if (cppVar_45611) {
	cppVar_45607 = P1;
	} else {
	cppVar_45613 = PC + 1;
	cppVar_45613 = (cppVar_45613 & cppMask_un_16_);
	cppVar_45614 = ROM.rd(cppVar_45613);
	cppVar_45616 = (cppVar_45614 == 152);
	if (cppVar_45616) {
	cppVar_45612 = SCON;
	} else {
	cppVar_45618 = PC + 1;
	cppVar_45618 = (cppVar_45618 & cppMask_un_16_);
	cppVar_45619 = ROM.rd(cppVar_45618);
	cppVar_45621 = (cppVar_45619 == 153);
	if (cppVar_45621) {
	cppVar_45617 = SBUF;
	} else {
	cppVar_45623 = PC + 1;
	cppVar_45623 = (cppVar_45623 & cppMask_un_16_);
	cppVar_45624 = ROM.rd(cppVar_45623);
	cppVar_45626 = (cppVar_45624 == 160);
	if (cppVar_45626) {
	cppVar_45622 = P2;
	} else {
	cppVar_45628 = PC + 1;
	cppVar_45628 = (cppVar_45628 & cppMask_un_16_);
	cppVar_45629 = ROM.rd(cppVar_45628);
	cppVar_45631 = (cppVar_45629 == 168);
	if (cppVar_45631) {
	cppVar_45627 = IE;
	} else {
	cppVar_45633 = PC + 1;
	cppVar_45633 = (cppVar_45633 & cppMask_un_16_);
	cppVar_45634 = ROM.rd(cppVar_45633);
	cppVar_45636 = (cppVar_45634 == 176);
	if (cppVar_45636) {
	cppVar_45632 = P3;
	} else {
	cppVar_45638 = PC + 1;
	cppVar_45638 = (cppVar_45638 & cppMask_un_16_);
	cppVar_45639 = ROM.rd(cppVar_45638);
	cppVar_45641 = (cppVar_45639 == 184);
	if (cppVar_45641) {
	cppVar_45637 = IP;
	} else {
	cppVar_45643 = PC + 1;
	cppVar_45643 = (cppVar_45643 & cppMask_un_16_);
	cppVar_45644 = ROM.rd(cppVar_45643);
	cppVar_45646 = (cppVar_45644 == 208);
	if (cppVar_45646) {
	cppVar_45642 = PSW;
	} else {
	cppVar_45648 = PC + 1;
	cppVar_45648 = (cppVar_45648 & cppMask_un_16_);
	cppVar_45649 = ROM.rd(cppVar_45648);
	cppVar_45651 = (cppVar_45649 == 224);
	if (cppVar_45651) {
	cppVar_45647 = ACC;
	} else {
	cppVar_45653 = PC + 1;
	cppVar_45653 = (cppVar_45653 & cppMask_un_16_);
	cppVar_45654 = ROM.rd(cppVar_45653);
	cppVar_45656 = (cppVar_45654 == 240);
	if (cppVar_45656) {
	cppVar_45652 = B;
	} else {
	cppVar_45652 = 0;
	}
	cppVar_45647 = cppVar_45652;
	}
	cppVar_45642 = cppVar_45647;
	}
	cppVar_45637 = cppVar_45642;
	}
	cppVar_45632 = cppVar_45637;
	}
	cppVar_45627 = cppVar_45632;
	}
	cppVar_45622 = cppVar_45627;
	}
	cppVar_45617 = cppVar_45622;
	}
	cppVar_45612 = cppVar_45617;
	}
	cppVar_45607 = cppVar_45612;
	}
	cppVar_45602 = cppVar_45607;
	}
	cppVar_45597 = cppVar_45602;
	}
	cppVar_45592 = cppVar_45597;
	}
	cppVar_45587 = cppVar_45592;
	}
	cppVar_45582 = cppVar_45587;
	}
	cppVar_45577 = cppVar_45582;
	}
	cppVar_45572 = cppVar_45577;
	}
	cppVar_45567 = cppVar_45572;
	}
	cppVar_45562 = cppVar_45567;
	}
	cppVar_45557 = cppVar_45562;
	}
	cppVar_45552 = cppVar_45557;
	}
	cppVar_45542 = cppVar_45552;
	}
	cppVar_45536 = cppVar_45542;
	} else {
	cppVar_45536 = PCON;
	}
	cppVar_45532 = cppVar_45536;
	} else {
	cppVar_45659 = ROM.rd(PC);
	cppVar_45661 = (cppVar_45659 == 117);
	if (cppVar_45661) {
	cppVar_45664 = PC + 1;
	cppVar_45664 = (cppVar_45664 & cppMask_un_16_);
	cppVar_45665 = ROM.rd(cppVar_45664);
	cppVar_45667 = (cppVar_45665 == 135);
	if (cppVar_45667) {
	cppVar_45669 = PC + 2;
	cppVar_45669 = (cppVar_45669 & cppMask_un_16_);
	cppVar_45670 = ROM.rd(cppVar_45669);
	cppVar_45662 = cppVar_45670;
	} else {
	cppVar_45662 = PCON;
	}
	cppVar_45658 = cppVar_45662;
	} else {
	cppVar_45672 = ROM.rd(PC);
	cppVar_45674 = (cppVar_45672 == 99);
	if (cppVar_45674) {
	cppVar_45677 = PC + 1;
	cppVar_45677 = (cppVar_45677 & cppMask_un_16_);
	cppVar_45678 = ROM.rd(cppVar_45677);
	cppVar_45680 = (cppVar_45678 == 135);
	if (cppVar_45680) {
	cppVar_45682 = PC + 1;
	cppVar_45682 = (cppVar_45682 & cppMask_un_16_);
	cppVar_45683 = ROM.rd(cppVar_45682);
	cppVar_45684 = (cppVar_45683 >> 7) & cppMask_un_1_;
	cppVar_45686 = (cppVar_45684 == 0);
	if (cppVar_45686) {
	cppVar_45687 = PC + 1;
	cppVar_45687 = (cppVar_45687 & cppMask_un_16_);
	cppVar_45688 = ROM.rd(cppVar_45687);
	cppVar_45689 = IRAM.rd(cppVar_45688);
	cppVar_45681 = cppVar_45689;
	} else {
	cppVar_45691 = PC + 1;
	cppVar_45691 = (cppVar_45691 & cppMask_un_16_);
	cppVar_45692 = ROM.rd(cppVar_45691);
	cppVar_45694 = (cppVar_45692 == 128);
	if (cppVar_45694) {
	cppVar_45690 = P0;
	} else {
	cppVar_45696 = PC + 1;
	cppVar_45696 = (cppVar_45696 & cppMask_un_16_);
	cppVar_45697 = ROM.rd(cppVar_45696);
	cppVar_45699 = (cppVar_45697 == 129);
	if (cppVar_45699) {
	cppVar_45695 = SP;
	} else {
	cppVar_45701 = PC + 1;
	cppVar_45701 = (cppVar_45701 & cppMask_un_16_);
	cppVar_45702 = ROM.rd(cppVar_45701);
	cppVar_45704 = (cppVar_45702 == 130);
	if (cppVar_45704) {
	cppVar_45700 = DPL;
	} else {
	cppVar_45706 = PC + 1;
	cppVar_45706 = (cppVar_45706 & cppMask_un_16_);
	cppVar_45707 = ROM.rd(cppVar_45706);
	cppVar_45709 = (cppVar_45707 == 131);
	if (cppVar_45709) {
	cppVar_45705 = DPH;
	} else {
	cppVar_45711 = PC + 1;
	cppVar_45711 = (cppVar_45711 & cppMask_un_16_);
	cppVar_45712 = ROM.rd(cppVar_45711);
	cppVar_45714 = (cppVar_45712 == 135);
	if (cppVar_45714) {
	cppVar_45710 = PCON;
	} else {
	cppVar_45716 = PC + 1;
	cppVar_45716 = (cppVar_45716 & cppMask_un_16_);
	cppVar_45717 = ROM.rd(cppVar_45716);
	cppVar_45719 = (cppVar_45717 == 136);
	if (cppVar_45719) {
	cppVar_45715 = TCON;
	} else {
	cppVar_45721 = PC + 1;
	cppVar_45721 = (cppVar_45721 & cppMask_un_16_);
	cppVar_45722 = ROM.rd(cppVar_45721);
	cppVar_45724 = (cppVar_45722 == 137);
	if (cppVar_45724) {
	cppVar_45720 = TMOD;
	} else {
	cppVar_45726 = PC + 1;
	cppVar_45726 = (cppVar_45726 & cppMask_un_16_);
	cppVar_45727 = ROM.rd(cppVar_45726);
	cppVar_45729 = (cppVar_45727 == 138);
	if (cppVar_45729) {
	cppVar_45725 = TL0;
	} else {
	cppVar_45731 = PC + 1;
	cppVar_45731 = (cppVar_45731 & cppMask_un_16_);
	cppVar_45732 = ROM.rd(cppVar_45731);
	cppVar_45734 = (cppVar_45732 == 140);
	if (cppVar_45734) {
	cppVar_45730 = TH0;
	} else {
	cppVar_45736 = PC + 1;
	cppVar_45736 = (cppVar_45736 & cppMask_un_16_);
	cppVar_45737 = ROM.rd(cppVar_45736);
	cppVar_45739 = (cppVar_45737 == 139);
	if (cppVar_45739) {
	cppVar_45735 = TL1;
	} else {
	cppVar_45741 = PC + 1;
	cppVar_45741 = (cppVar_45741 & cppMask_un_16_);
	cppVar_45742 = ROM.rd(cppVar_45741);
	cppVar_45744 = (cppVar_45742 == 141);
	if (cppVar_45744) {
	cppVar_45740 = TH1;
	} else {
	cppVar_45746 = PC + 1;
	cppVar_45746 = (cppVar_45746 & cppMask_un_16_);
	cppVar_45747 = ROM.rd(cppVar_45746);
	cppVar_45749 = (cppVar_45747 == 144);
	if (cppVar_45749) {
	cppVar_45745 = P1;
	} else {
	cppVar_45751 = PC + 1;
	cppVar_45751 = (cppVar_45751 & cppMask_un_16_);
	cppVar_45752 = ROM.rd(cppVar_45751);
	cppVar_45754 = (cppVar_45752 == 152);
	if (cppVar_45754) {
	cppVar_45750 = SCON;
	} else {
	cppVar_45756 = PC + 1;
	cppVar_45756 = (cppVar_45756 & cppMask_un_16_);
	cppVar_45757 = ROM.rd(cppVar_45756);
	cppVar_45759 = (cppVar_45757 == 153);
	if (cppVar_45759) {
	cppVar_45755 = SBUF;
	} else {
	cppVar_45761 = PC + 1;
	cppVar_45761 = (cppVar_45761 & cppMask_un_16_);
	cppVar_45762 = ROM.rd(cppVar_45761);
	cppVar_45764 = (cppVar_45762 == 160);
	if (cppVar_45764) {
	cppVar_45760 = P2;
	} else {
	cppVar_45766 = PC + 1;
	cppVar_45766 = (cppVar_45766 & cppMask_un_16_);
	cppVar_45767 = ROM.rd(cppVar_45766);
	cppVar_45769 = (cppVar_45767 == 168);
	if (cppVar_45769) {
	cppVar_45765 = IE;
	} else {
	cppVar_45771 = PC + 1;
	cppVar_45771 = (cppVar_45771 & cppMask_un_16_);
	cppVar_45772 = ROM.rd(cppVar_45771);
	cppVar_45774 = (cppVar_45772 == 176);
	if (cppVar_45774) {
	cppVar_45770 = P3;
	} else {
	cppVar_45776 = PC + 1;
	cppVar_45776 = (cppVar_45776 & cppMask_un_16_);
	cppVar_45777 = ROM.rd(cppVar_45776);
	cppVar_45779 = (cppVar_45777 == 184);
	if (cppVar_45779) {
	cppVar_45775 = IP;
	} else {
	cppVar_45781 = PC + 1;
	cppVar_45781 = (cppVar_45781 & cppMask_un_16_);
	cppVar_45782 = ROM.rd(cppVar_45781);
	cppVar_45784 = (cppVar_45782 == 208);
	if (cppVar_45784) {
	cppVar_45780 = PSW;
	} else {
	cppVar_45786 = PC + 1;
	cppVar_45786 = (cppVar_45786 & cppMask_un_16_);
	cppVar_45787 = ROM.rd(cppVar_45786);
	cppVar_45789 = (cppVar_45787 == 224);
	if (cppVar_45789) {
	cppVar_45785 = ACC;
	} else {
	cppVar_45791 = PC + 1;
	cppVar_45791 = (cppVar_45791 & cppMask_un_16_);
	cppVar_45792 = ROM.rd(cppVar_45791);
	cppVar_45794 = (cppVar_45792 == 240);
	if (cppVar_45794) {
	cppVar_45790 = B;
	} else {
	cppVar_45790 = 0;
	}
	cppVar_45785 = cppVar_45790;
	}
	cppVar_45780 = cppVar_45785;
	}
	cppVar_45775 = cppVar_45780;
	}
	cppVar_45770 = cppVar_45775;
	}
	cppVar_45765 = cppVar_45770;
	}
	cppVar_45760 = cppVar_45765;
	}
	cppVar_45755 = cppVar_45760;
	}
	cppVar_45750 = cppVar_45755;
	}
	cppVar_45745 = cppVar_45750;
	}
	cppVar_45740 = cppVar_45745;
	}
	cppVar_45735 = cppVar_45740;
	}
	cppVar_45730 = cppVar_45735;
	}
	cppVar_45725 = cppVar_45730;
	}
	cppVar_45720 = cppVar_45725;
	}
	cppVar_45715 = cppVar_45720;
	}
	cppVar_45710 = cppVar_45715;
	}
	cppVar_45705 = cppVar_45710;
	}
	cppVar_45700 = cppVar_45705;
	}
	cppVar_45695 = cppVar_45700;
	}
	cppVar_45690 = cppVar_45695;
	}
	cppVar_45681 = cppVar_45690;
	}
	cppVar_45797 = PC + 2;
	cppVar_45797 = (cppVar_45797 & cppMask_un_16_);
	cppVar_45798 = ROM.rd(cppVar_45797);
	cppVar_45799 = cppVar_45681 ^ cppVar_45798;
	cppVar_45675 = cppVar_45799;
	} else {
	cppVar_45675 = PCON;
	}
	cppVar_45671 = cppVar_45675;
	} else {
	cppVar_45801 = ROM.rd(PC);
	cppVar_45803 = (cppVar_45801 == 98);
	if (cppVar_45803) {
	cppVar_45806 = PC + 1;
	cppVar_45806 = (cppVar_45806 & cppMask_un_16_);
	cppVar_45807 = ROM.rd(cppVar_45806);
	cppVar_45809 = (cppVar_45807 == 135);
	if (cppVar_45809) {
	cppVar_45811 = PC + 1;
	cppVar_45811 = (cppVar_45811 & cppMask_un_16_);
	cppVar_45812 = ROM.rd(cppVar_45811);
	cppVar_45813 = (cppVar_45812 >> 7) & cppMask_un_1_;
	cppVar_45815 = (cppVar_45813 == 0);
	if (cppVar_45815) {
	cppVar_45816 = PC + 1;
	cppVar_45816 = (cppVar_45816 & cppMask_un_16_);
	cppVar_45817 = ROM.rd(cppVar_45816);
	cppVar_45818 = IRAM.rd(cppVar_45817);
	cppVar_45810 = cppVar_45818;
	} else {
	cppVar_45820 = PC + 1;
	cppVar_45820 = (cppVar_45820 & cppMask_un_16_);
	cppVar_45821 = ROM.rd(cppVar_45820);
	cppVar_45823 = (cppVar_45821 == 128);
	if (cppVar_45823) {
	cppVar_45819 = P0;
	} else {
	cppVar_45825 = PC + 1;
	cppVar_45825 = (cppVar_45825 & cppMask_un_16_);
	cppVar_45826 = ROM.rd(cppVar_45825);
	cppVar_45828 = (cppVar_45826 == 129);
	if (cppVar_45828) {
	cppVar_45824 = SP;
	} else {
	cppVar_45830 = PC + 1;
	cppVar_45830 = (cppVar_45830 & cppMask_un_16_);
	cppVar_45831 = ROM.rd(cppVar_45830);
	cppVar_45833 = (cppVar_45831 == 130);
	if (cppVar_45833) {
	cppVar_45829 = DPL;
	} else {
	cppVar_45835 = PC + 1;
	cppVar_45835 = (cppVar_45835 & cppMask_un_16_);
	cppVar_45836 = ROM.rd(cppVar_45835);
	cppVar_45838 = (cppVar_45836 == 131);
	if (cppVar_45838) {
	cppVar_45834 = DPH;
	} else {
	cppVar_45840 = PC + 1;
	cppVar_45840 = (cppVar_45840 & cppMask_un_16_);
	cppVar_45841 = ROM.rd(cppVar_45840);
	cppVar_45843 = (cppVar_45841 == 135);
	if (cppVar_45843) {
	cppVar_45839 = PCON;
	} else {
	cppVar_45845 = PC + 1;
	cppVar_45845 = (cppVar_45845 & cppMask_un_16_);
	cppVar_45846 = ROM.rd(cppVar_45845);
	cppVar_45848 = (cppVar_45846 == 136);
	if (cppVar_45848) {
	cppVar_45844 = TCON;
	} else {
	cppVar_45850 = PC + 1;
	cppVar_45850 = (cppVar_45850 & cppMask_un_16_);
	cppVar_45851 = ROM.rd(cppVar_45850);
	cppVar_45853 = (cppVar_45851 == 137);
	if (cppVar_45853) {
	cppVar_45849 = TMOD;
	} else {
	cppVar_45855 = PC + 1;
	cppVar_45855 = (cppVar_45855 & cppMask_un_16_);
	cppVar_45856 = ROM.rd(cppVar_45855);
	cppVar_45858 = (cppVar_45856 == 138);
	if (cppVar_45858) {
	cppVar_45854 = TL0;
	} else {
	cppVar_45860 = PC + 1;
	cppVar_45860 = (cppVar_45860 & cppMask_un_16_);
	cppVar_45861 = ROM.rd(cppVar_45860);
	cppVar_45863 = (cppVar_45861 == 140);
	if (cppVar_45863) {
	cppVar_45859 = TH0;
	} else {
	cppVar_45865 = PC + 1;
	cppVar_45865 = (cppVar_45865 & cppMask_un_16_);
	cppVar_45866 = ROM.rd(cppVar_45865);
	cppVar_45868 = (cppVar_45866 == 139);
	if (cppVar_45868) {
	cppVar_45864 = TL1;
	} else {
	cppVar_45870 = PC + 1;
	cppVar_45870 = (cppVar_45870 & cppMask_un_16_);
	cppVar_45871 = ROM.rd(cppVar_45870);
	cppVar_45873 = (cppVar_45871 == 141);
	if (cppVar_45873) {
	cppVar_45869 = TH1;
	} else {
	cppVar_45875 = PC + 1;
	cppVar_45875 = (cppVar_45875 & cppMask_un_16_);
	cppVar_45876 = ROM.rd(cppVar_45875);
	cppVar_45878 = (cppVar_45876 == 144);
	if (cppVar_45878) {
	cppVar_45874 = P1;
	} else {
	cppVar_45880 = PC + 1;
	cppVar_45880 = (cppVar_45880 & cppMask_un_16_);
	cppVar_45881 = ROM.rd(cppVar_45880);
	cppVar_45883 = (cppVar_45881 == 152);
	if (cppVar_45883) {
	cppVar_45879 = SCON;
	} else {
	cppVar_45885 = PC + 1;
	cppVar_45885 = (cppVar_45885 & cppMask_un_16_);
	cppVar_45886 = ROM.rd(cppVar_45885);
	cppVar_45888 = (cppVar_45886 == 153);
	if (cppVar_45888) {
	cppVar_45884 = SBUF;
	} else {
	cppVar_45890 = PC + 1;
	cppVar_45890 = (cppVar_45890 & cppMask_un_16_);
	cppVar_45891 = ROM.rd(cppVar_45890);
	cppVar_45893 = (cppVar_45891 == 160);
	if (cppVar_45893) {
	cppVar_45889 = P2;
	} else {
	cppVar_45895 = PC + 1;
	cppVar_45895 = (cppVar_45895 & cppMask_un_16_);
	cppVar_45896 = ROM.rd(cppVar_45895);
	cppVar_45898 = (cppVar_45896 == 168);
	if (cppVar_45898) {
	cppVar_45894 = IE;
	} else {
	cppVar_45900 = PC + 1;
	cppVar_45900 = (cppVar_45900 & cppMask_un_16_);
	cppVar_45901 = ROM.rd(cppVar_45900);
	cppVar_45903 = (cppVar_45901 == 176);
	if (cppVar_45903) {
	cppVar_45899 = P3;
	} else {
	cppVar_45905 = PC + 1;
	cppVar_45905 = (cppVar_45905 & cppMask_un_16_);
	cppVar_45906 = ROM.rd(cppVar_45905);
	cppVar_45908 = (cppVar_45906 == 184);
	if (cppVar_45908) {
	cppVar_45904 = IP;
	} else {
	cppVar_45910 = PC + 1;
	cppVar_45910 = (cppVar_45910 & cppMask_un_16_);
	cppVar_45911 = ROM.rd(cppVar_45910);
	cppVar_45913 = (cppVar_45911 == 208);
	if (cppVar_45913) {
	cppVar_45909 = PSW;
	} else {
	cppVar_45915 = PC + 1;
	cppVar_45915 = (cppVar_45915 & cppMask_un_16_);
	cppVar_45916 = ROM.rd(cppVar_45915);
	cppVar_45918 = (cppVar_45916 == 224);
	if (cppVar_45918) {
	cppVar_45914 = ACC;
	} else {
	cppVar_45920 = PC + 1;
	cppVar_45920 = (cppVar_45920 & cppMask_un_16_);
	cppVar_45921 = ROM.rd(cppVar_45920);
	cppVar_45923 = (cppVar_45921 == 240);
	if (cppVar_45923) {
	cppVar_45919 = B;
	} else {
	cppVar_45919 = 0;
	}
	cppVar_45914 = cppVar_45919;
	}
	cppVar_45909 = cppVar_45914;
	}
	cppVar_45904 = cppVar_45909;
	}
	cppVar_45899 = cppVar_45904;
	}
	cppVar_45894 = cppVar_45899;
	}
	cppVar_45889 = cppVar_45894;
	}
	cppVar_45884 = cppVar_45889;
	}
	cppVar_45879 = cppVar_45884;
	}
	cppVar_45874 = cppVar_45879;
	}
	cppVar_45869 = cppVar_45874;
	}
	cppVar_45864 = cppVar_45869;
	}
	cppVar_45859 = cppVar_45864;
	}
	cppVar_45854 = cppVar_45859;
	}
	cppVar_45849 = cppVar_45854;
	}
	cppVar_45844 = cppVar_45849;
	}
	cppVar_45839 = cppVar_45844;
	}
	cppVar_45834 = cppVar_45839;
	}
	cppVar_45829 = cppVar_45834;
	}
	cppVar_45824 = cppVar_45829;
	}
	cppVar_45819 = cppVar_45824;
	}
	cppVar_45810 = cppVar_45819;
	}
	cppVar_45925 = cppVar_45810 ^ ACC;
	cppVar_45804 = cppVar_45925;
	} else {
	cppVar_45804 = PCON;
	}
	cppVar_45800 = cppVar_45804;
	} else {
	cppVar_45927 = ROM.rd(PC);
	cppVar_45929 = (cppVar_45927 == 83);
	if (cppVar_45929) {
	cppVar_45932 = PC + 1;
	cppVar_45932 = (cppVar_45932 & cppMask_un_16_);
	cppVar_45933 = ROM.rd(cppVar_45932);
	cppVar_45935 = (cppVar_45933 == 135);
	if (cppVar_45935) {
	cppVar_45937 = PC + 1;
	cppVar_45937 = (cppVar_45937 & cppMask_un_16_);
	cppVar_45938 = ROM.rd(cppVar_45937);
	cppVar_45939 = (cppVar_45938 >> 7) & cppMask_un_1_;
	cppVar_45941 = (cppVar_45939 == 0);
	if (cppVar_45941) {
	cppVar_45942 = PC + 1;
	cppVar_45942 = (cppVar_45942 & cppMask_un_16_);
	cppVar_45943 = ROM.rd(cppVar_45942);
	cppVar_45944 = IRAM.rd(cppVar_45943);
	cppVar_45936 = cppVar_45944;
	} else {
	cppVar_45946 = PC + 1;
	cppVar_45946 = (cppVar_45946 & cppMask_un_16_);
	cppVar_45947 = ROM.rd(cppVar_45946);
	cppVar_45949 = (cppVar_45947 == 128);
	if (cppVar_45949) {
	cppVar_45945 = P0;
	} else {
	cppVar_45951 = PC + 1;
	cppVar_45951 = (cppVar_45951 & cppMask_un_16_);
	cppVar_45952 = ROM.rd(cppVar_45951);
	cppVar_45954 = (cppVar_45952 == 129);
	if (cppVar_45954) {
	cppVar_45950 = SP;
	} else {
	cppVar_45956 = PC + 1;
	cppVar_45956 = (cppVar_45956 & cppMask_un_16_);
	cppVar_45957 = ROM.rd(cppVar_45956);
	cppVar_45959 = (cppVar_45957 == 130);
	if (cppVar_45959) {
	cppVar_45955 = DPL;
	} else {
	cppVar_45961 = PC + 1;
	cppVar_45961 = (cppVar_45961 & cppMask_un_16_);
	cppVar_45962 = ROM.rd(cppVar_45961);
	cppVar_45964 = (cppVar_45962 == 131);
	if (cppVar_45964) {
	cppVar_45960 = DPH;
	} else {
	cppVar_45966 = PC + 1;
	cppVar_45966 = (cppVar_45966 & cppMask_un_16_);
	cppVar_45967 = ROM.rd(cppVar_45966);
	cppVar_45969 = (cppVar_45967 == 135);
	if (cppVar_45969) {
	cppVar_45965 = PCON;
	} else {
	cppVar_45971 = PC + 1;
	cppVar_45971 = (cppVar_45971 & cppMask_un_16_);
	cppVar_45972 = ROM.rd(cppVar_45971);
	cppVar_45974 = (cppVar_45972 == 136);
	if (cppVar_45974) {
	cppVar_45970 = TCON;
	} else {
	cppVar_45976 = PC + 1;
	cppVar_45976 = (cppVar_45976 & cppMask_un_16_);
	cppVar_45977 = ROM.rd(cppVar_45976);
	cppVar_45979 = (cppVar_45977 == 137);
	if (cppVar_45979) {
	cppVar_45975 = TMOD;
	} else {
	cppVar_45981 = PC + 1;
	cppVar_45981 = (cppVar_45981 & cppMask_un_16_);
	cppVar_45982 = ROM.rd(cppVar_45981);
	cppVar_45984 = (cppVar_45982 == 138);
	if (cppVar_45984) {
	cppVar_45980 = TL0;
	} else {
	cppVar_45986 = PC + 1;
	cppVar_45986 = (cppVar_45986 & cppMask_un_16_);
	cppVar_45987 = ROM.rd(cppVar_45986);
	cppVar_45989 = (cppVar_45987 == 140);
	if (cppVar_45989) {
	cppVar_45985 = TH0;
	} else {
	cppVar_45991 = PC + 1;
	cppVar_45991 = (cppVar_45991 & cppMask_un_16_);
	cppVar_45992 = ROM.rd(cppVar_45991);
	cppVar_45994 = (cppVar_45992 == 139);
	if (cppVar_45994) {
	cppVar_45990 = TL1;
	} else {
	cppVar_45996 = PC + 1;
	cppVar_45996 = (cppVar_45996 & cppMask_un_16_);
	cppVar_45997 = ROM.rd(cppVar_45996);
	cppVar_45999 = (cppVar_45997 == 141);
	if (cppVar_45999) {
	cppVar_45995 = TH1;
	} else {
	cppVar_46001 = PC + 1;
	cppVar_46001 = (cppVar_46001 & cppMask_un_16_);
	cppVar_46002 = ROM.rd(cppVar_46001);
	cppVar_46004 = (cppVar_46002 == 144);
	if (cppVar_46004) {
	cppVar_46000 = P1;
	} else {
	cppVar_46006 = PC + 1;
	cppVar_46006 = (cppVar_46006 & cppMask_un_16_);
	cppVar_46007 = ROM.rd(cppVar_46006);
	cppVar_46009 = (cppVar_46007 == 152);
	if (cppVar_46009) {
	cppVar_46005 = SCON;
	} else {
	cppVar_46011 = PC + 1;
	cppVar_46011 = (cppVar_46011 & cppMask_un_16_);
	cppVar_46012 = ROM.rd(cppVar_46011);
	cppVar_46014 = (cppVar_46012 == 153);
	if (cppVar_46014) {
	cppVar_46010 = SBUF;
	} else {
	cppVar_46016 = PC + 1;
	cppVar_46016 = (cppVar_46016 & cppMask_un_16_);
	cppVar_46017 = ROM.rd(cppVar_46016);
	cppVar_46019 = (cppVar_46017 == 160);
	if (cppVar_46019) {
	cppVar_46015 = P2;
	} else {
	cppVar_46021 = PC + 1;
	cppVar_46021 = (cppVar_46021 & cppMask_un_16_);
	cppVar_46022 = ROM.rd(cppVar_46021);
	cppVar_46024 = (cppVar_46022 == 168);
	if (cppVar_46024) {
	cppVar_46020 = IE;
	} else {
	cppVar_46026 = PC + 1;
	cppVar_46026 = (cppVar_46026 & cppMask_un_16_);
	cppVar_46027 = ROM.rd(cppVar_46026);
	cppVar_46029 = (cppVar_46027 == 176);
	if (cppVar_46029) {
	cppVar_46025 = P3;
	} else {
	cppVar_46031 = PC + 1;
	cppVar_46031 = (cppVar_46031 & cppMask_un_16_);
	cppVar_46032 = ROM.rd(cppVar_46031);
	cppVar_46034 = (cppVar_46032 == 184);
	if (cppVar_46034) {
	cppVar_46030 = IP;
	} else {
	cppVar_46036 = PC + 1;
	cppVar_46036 = (cppVar_46036 & cppMask_un_16_);
	cppVar_46037 = ROM.rd(cppVar_46036);
	cppVar_46039 = (cppVar_46037 == 208);
	if (cppVar_46039) {
	cppVar_46035 = PSW;
	} else {
	cppVar_46041 = PC + 1;
	cppVar_46041 = (cppVar_46041 & cppMask_un_16_);
	cppVar_46042 = ROM.rd(cppVar_46041);
	cppVar_46044 = (cppVar_46042 == 224);
	if (cppVar_46044) {
	cppVar_46040 = ACC;
	} else {
	cppVar_46046 = PC + 1;
	cppVar_46046 = (cppVar_46046 & cppMask_un_16_);
	cppVar_46047 = ROM.rd(cppVar_46046);
	cppVar_46049 = (cppVar_46047 == 240);
	if (cppVar_46049) {
	cppVar_46045 = B;
	} else {
	cppVar_46045 = 0;
	}
	cppVar_46040 = cppVar_46045;
	}
	cppVar_46035 = cppVar_46040;
	}
	cppVar_46030 = cppVar_46035;
	}
	cppVar_46025 = cppVar_46030;
	}
	cppVar_46020 = cppVar_46025;
	}
	cppVar_46015 = cppVar_46020;
	}
	cppVar_46010 = cppVar_46015;
	}
	cppVar_46005 = cppVar_46010;
	}
	cppVar_46000 = cppVar_46005;
	}
	cppVar_45995 = cppVar_46000;
	}
	cppVar_45990 = cppVar_45995;
	}
	cppVar_45985 = cppVar_45990;
	}
	cppVar_45980 = cppVar_45985;
	}
	cppVar_45975 = cppVar_45980;
	}
	cppVar_45970 = cppVar_45975;
	}
	cppVar_45965 = cppVar_45970;
	}
	cppVar_45960 = cppVar_45965;
	}
	cppVar_45955 = cppVar_45960;
	}
	cppVar_45950 = cppVar_45955;
	}
	cppVar_45945 = cppVar_45950;
	}
	cppVar_45936 = cppVar_45945;
	}
	cppVar_46052 = PC + 2;
	cppVar_46052 = (cppVar_46052 & cppMask_un_16_);
	cppVar_46053 = ROM.rd(cppVar_46052);
	cppVar_46054 = cppVar_45936 & cppVar_46053;
	cppVar_45930 = cppVar_46054;
	} else {
	cppVar_45930 = PCON;
	}
	cppVar_45926 = cppVar_45930;
	} else {
	cppVar_46056 = ROM.rd(PC);
	cppVar_46058 = (cppVar_46056 == 82);
	if (cppVar_46058) {
	cppVar_46061 = PC + 1;
	cppVar_46061 = (cppVar_46061 & cppMask_un_16_);
	cppVar_46062 = ROM.rd(cppVar_46061);
	cppVar_46064 = (cppVar_46062 == 135);
	if (cppVar_46064) {
	cppVar_46066 = PC + 1;
	cppVar_46066 = (cppVar_46066 & cppMask_un_16_);
	cppVar_46067 = ROM.rd(cppVar_46066);
	cppVar_46068 = (cppVar_46067 >> 7) & cppMask_un_1_;
	cppVar_46070 = (cppVar_46068 == 0);
	if (cppVar_46070) {
	cppVar_46071 = PC + 1;
	cppVar_46071 = (cppVar_46071 & cppMask_un_16_);
	cppVar_46072 = ROM.rd(cppVar_46071);
	cppVar_46073 = IRAM.rd(cppVar_46072);
	cppVar_46065 = cppVar_46073;
	} else {
	cppVar_46075 = PC + 1;
	cppVar_46075 = (cppVar_46075 & cppMask_un_16_);
	cppVar_46076 = ROM.rd(cppVar_46075);
	cppVar_46078 = (cppVar_46076 == 128);
	if (cppVar_46078) {
	cppVar_46074 = P0;
	} else {
	cppVar_46080 = PC + 1;
	cppVar_46080 = (cppVar_46080 & cppMask_un_16_);
	cppVar_46081 = ROM.rd(cppVar_46080);
	cppVar_46083 = (cppVar_46081 == 129);
	if (cppVar_46083) {
	cppVar_46079 = SP;
	} else {
	cppVar_46085 = PC + 1;
	cppVar_46085 = (cppVar_46085 & cppMask_un_16_);
	cppVar_46086 = ROM.rd(cppVar_46085);
	cppVar_46088 = (cppVar_46086 == 130);
	if (cppVar_46088) {
	cppVar_46084 = DPL;
	} else {
	cppVar_46090 = PC + 1;
	cppVar_46090 = (cppVar_46090 & cppMask_un_16_);
	cppVar_46091 = ROM.rd(cppVar_46090);
	cppVar_46093 = (cppVar_46091 == 131);
	if (cppVar_46093) {
	cppVar_46089 = DPH;
	} else {
	cppVar_46095 = PC + 1;
	cppVar_46095 = (cppVar_46095 & cppMask_un_16_);
	cppVar_46096 = ROM.rd(cppVar_46095);
	cppVar_46098 = (cppVar_46096 == 135);
	if (cppVar_46098) {
	cppVar_46094 = PCON;
	} else {
	cppVar_46100 = PC + 1;
	cppVar_46100 = (cppVar_46100 & cppMask_un_16_);
	cppVar_46101 = ROM.rd(cppVar_46100);
	cppVar_46103 = (cppVar_46101 == 136);
	if (cppVar_46103) {
	cppVar_46099 = TCON;
	} else {
	cppVar_46105 = PC + 1;
	cppVar_46105 = (cppVar_46105 & cppMask_un_16_);
	cppVar_46106 = ROM.rd(cppVar_46105);
	cppVar_46108 = (cppVar_46106 == 137);
	if (cppVar_46108) {
	cppVar_46104 = TMOD;
	} else {
	cppVar_46110 = PC + 1;
	cppVar_46110 = (cppVar_46110 & cppMask_un_16_);
	cppVar_46111 = ROM.rd(cppVar_46110);
	cppVar_46113 = (cppVar_46111 == 138);
	if (cppVar_46113) {
	cppVar_46109 = TL0;
	} else {
	cppVar_46115 = PC + 1;
	cppVar_46115 = (cppVar_46115 & cppMask_un_16_);
	cppVar_46116 = ROM.rd(cppVar_46115);
	cppVar_46118 = (cppVar_46116 == 140);
	if (cppVar_46118) {
	cppVar_46114 = TH0;
	} else {
	cppVar_46120 = PC + 1;
	cppVar_46120 = (cppVar_46120 & cppMask_un_16_);
	cppVar_46121 = ROM.rd(cppVar_46120);
	cppVar_46123 = (cppVar_46121 == 139);
	if (cppVar_46123) {
	cppVar_46119 = TL1;
	} else {
	cppVar_46125 = PC + 1;
	cppVar_46125 = (cppVar_46125 & cppMask_un_16_);
	cppVar_46126 = ROM.rd(cppVar_46125);
	cppVar_46128 = (cppVar_46126 == 141);
	if (cppVar_46128) {
	cppVar_46124 = TH1;
	} else {
	cppVar_46130 = PC + 1;
	cppVar_46130 = (cppVar_46130 & cppMask_un_16_);
	cppVar_46131 = ROM.rd(cppVar_46130);
	cppVar_46133 = (cppVar_46131 == 144);
	if (cppVar_46133) {
	cppVar_46129 = P1;
	} else {
	cppVar_46135 = PC + 1;
	cppVar_46135 = (cppVar_46135 & cppMask_un_16_);
	cppVar_46136 = ROM.rd(cppVar_46135);
	cppVar_46138 = (cppVar_46136 == 152);
	if (cppVar_46138) {
	cppVar_46134 = SCON;
	} else {
	cppVar_46140 = PC + 1;
	cppVar_46140 = (cppVar_46140 & cppMask_un_16_);
	cppVar_46141 = ROM.rd(cppVar_46140);
	cppVar_46143 = (cppVar_46141 == 153);
	if (cppVar_46143) {
	cppVar_46139 = SBUF;
	} else {
	cppVar_46145 = PC + 1;
	cppVar_46145 = (cppVar_46145 & cppMask_un_16_);
	cppVar_46146 = ROM.rd(cppVar_46145);
	cppVar_46148 = (cppVar_46146 == 160);
	if (cppVar_46148) {
	cppVar_46144 = P2;
	} else {
	cppVar_46150 = PC + 1;
	cppVar_46150 = (cppVar_46150 & cppMask_un_16_);
	cppVar_46151 = ROM.rd(cppVar_46150);
	cppVar_46153 = (cppVar_46151 == 168);
	if (cppVar_46153) {
	cppVar_46149 = IE;
	} else {
	cppVar_46155 = PC + 1;
	cppVar_46155 = (cppVar_46155 & cppMask_un_16_);
	cppVar_46156 = ROM.rd(cppVar_46155);
	cppVar_46158 = (cppVar_46156 == 176);
	if (cppVar_46158) {
	cppVar_46154 = P3;
	} else {
	cppVar_46160 = PC + 1;
	cppVar_46160 = (cppVar_46160 & cppMask_un_16_);
	cppVar_46161 = ROM.rd(cppVar_46160);
	cppVar_46163 = (cppVar_46161 == 184);
	if (cppVar_46163) {
	cppVar_46159 = IP;
	} else {
	cppVar_46165 = PC + 1;
	cppVar_46165 = (cppVar_46165 & cppMask_un_16_);
	cppVar_46166 = ROM.rd(cppVar_46165);
	cppVar_46168 = (cppVar_46166 == 208);
	if (cppVar_46168) {
	cppVar_46164 = PSW;
	} else {
	cppVar_46170 = PC + 1;
	cppVar_46170 = (cppVar_46170 & cppMask_un_16_);
	cppVar_46171 = ROM.rd(cppVar_46170);
	cppVar_46173 = (cppVar_46171 == 224);
	if (cppVar_46173) {
	cppVar_46169 = ACC;
	} else {
	cppVar_46175 = PC + 1;
	cppVar_46175 = (cppVar_46175 & cppMask_un_16_);
	cppVar_46176 = ROM.rd(cppVar_46175);
	cppVar_46178 = (cppVar_46176 == 240);
	if (cppVar_46178) {
	cppVar_46174 = B;
	} else {
	cppVar_46174 = 0;
	}
	cppVar_46169 = cppVar_46174;
	}
	cppVar_46164 = cppVar_46169;
	}
	cppVar_46159 = cppVar_46164;
	}
	cppVar_46154 = cppVar_46159;
	}
	cppVar_46149 = cppVar_46154;
	}
	cppVar_46144 = cppVar_46149;
	}
	cppVar_46139 = cppVar_46144;
	}
	cppVar_46134 = cppVar_46139;
	}
	cppVar_46129 = cppVar_46134;
	}
	cppVar_46124 = cppVar_46129;
	}
	cppVar_46119 = cppVar_46124;
	}
	cppVar_46114 = cppVar_46119;
	}
	cppVar_46109 = cppVar_46114;
	}
	cppVar_46104 = cppVar_46109;
	}
	cppVar_46099 = cppVar_46104;
	}
	cppVar_46094 = cppVar_46099;
	}
	cppVar_46089 = cppVar_46094;
	}
	cppVar_46084 = cppVar_46089;
	}
	cppVar_46079 = cppVar_46084;
	}
	cppVar_46074 = cppVar_46079;
	}
	cppVar_46065 = cppVar_46074;
	}
	cppVar_46180 = cppVar_46065 & ACC;
	cppVar_46059 = cppVar_46180;
	} else {
	cppVar_46059 = PCON;
	}
	cppVar_46055 = cppVar_46059;
	} else {
	cppVar_46182 = ROM.rd(PC);
	cppVar_46184 = (cppVar_46182 == 67);
	if (cppVar_46184) {
	cppVar_46187 = PC + 1;
	cppVar_46187 = (cppVar_46187 & cppMask_un_16_);
	cppVar_46188 = ROM.rd(cppVar_46187);
	cppVar_46190 = (cppVar_46188 == 135);
	if (cppVar_46190) {
	cppVar_46192 = PC + 1;
	cppVar_46192 = (cppVar_46192 & cppMask_un_16_);
	cppVar_46193 = ROM.rd(cppVar_46192);
	cppVar_46194 = (cppVar_46193 >> 7) & cppMask_un_1_;
	cppVar_46196 = (cppVar_46194 == 0);
	if (cppVar_46196) {
	cppVar_46197 = PC + 1;
	cppVar_46197 = (cppVar_46197 & cppMask_un_16_);
	cppVar_46198 = ROM.rd(cppVar_46197);
	cppVar_46199 = IRAM.rd(cppVar_46198);
	cppVar_46191 = cppVar_46199;
	} else {
	cppVar_46201 = PC + 1;
	cppVar_46201 = (cppVar_46201 & cppMask_un_16_);
	cppVar_46202 = ROM.rd(cppVar_46201);
	cppVar_46204 = (cppVar_46202 == 128);
	if (cppVar_46204) {
	cppVar_46200 = P0;
	} else {
	cppVar_46206 = PC + 1;
	cppVar_46206 = (cppVar_46206 & cppMask_un_16_);
	cppVar_46207 = ROM.rd(cppVar_46206);
	cppVar_46209 = (cppVar_46207 == 129);
	if (cppVar_46209) {
	cppVar_46205 = SP;
	} else {
	cppVar_46211 = PC + 1;
	cppVar_46211 = (cppVar_46211 & cppMask_un_16_);
	cppVar_46212 = ROM.rd(cppVar_46211);
	cppVar_46214 = (cppVar_46212 == 130);
	if (cppVar_46214) {
	cppVar_46210 = DPL;
	} else {
	cppVar_46216 = PC + 1;
	cppVar_46216 = (cppVar_46216 & cppMask_un_16_);
	cppVar_46217 = ROM.rd(cppVar_46216);
	cppVar_46219 = (cppVar_46217 == 131);
	if (cppVar_46219) {
	cppVar_46215 = DPH;
	} else {
	cppVar_46221 = PC + 1;
	cppVar_46221 = (cppVar_46221 & cppMask_un_16_);
	cppVar_46222 = ROM.rd(cppVar_46221);
	cppVar_46224 = (cppVar_46222 == 135);
	if (cppVar_46224) {
	cppVar_46220 = PCON;
	} else {
	cppVar_46226 = PC + 1;
	cppVar_46226 = (cppVar_46226 & cppMask_un_16_);
	cppVar_46227 = ROM.rd(cppVar_46226);
	cppVar_46229 = (cppVar_46227 == 136);
	if (cppVar_46229) {
	cppVar_46225 = TCON;
	} else {
	cppVar_46231 = PC + 1;
	cppVar_46231 = (cppVar_46231 & cppMask_un_16_);
	cppVar_46232 = ROM.rd(cppVar_46231);
	cppVar_46234 = (cppVar_46232 == 137);
	if (cppVar_46234) {
	cppVar_46230 = TMOD;
	} else {
	cppVar_46236 = PC + 1;
	cppVar_46236 = (cppVar_46236 & cppMask_un_16_);
	cppVar_46237 = ROM.rd(cppVar_46236);
	cppVar_46239 = (cppVar_46237 == 138);
	if (cppVar_46239) {
	cppVar_46235 = TL0;
	} else {
	cppVar_46241 = PC + 1;
	cppVar_46241 = (cppVar_46241 & cppMask_un_16_);
	cppVar_46242 = ROM.rd(cppVar_46241);
	cppVar_46244 = (cppVar_46242 == 140);
	if (cppVar_46244) {
	cppVar_46240 = TH0;
	} else {
	cppVar_46246 = PC + 1;
	cppVar_46246 = (cppVar_46246 & cppMask_un_16_);
	cppVar_46247 = ROM.rd(cppVar_46246);
	cppVar_46249 = (cppVar_46247 == 139);
	if (cppVar_46249) {
	cppVar_46245 = TL1;
	} else {
	cppVar_46251 = PC + 1;
	cppVar_46251 = (cppVar_46251 & cppMask_un_16_);
	cppVar_46252 = ROM.rd(cppVar_46251);
	cppVar_46254 = (cppVar_46252 == 141);
	if (cppVar_46254) {
	cppVar_46250 = TH1;
	} else {
	cppVar_46256 = PC + 1;
	cppVar_46256 = (cppVar_46256 & cppMask_un_16_);
	cppVar_46257 = ROM.rd(cppVar_46256);
	cppVar_46259 = (cppVar_46257 == 144);
	if (cppVar_46259) {
	cppVar_46255 = P1;
	} else {
	cppVar_46261 = PC + 1;
	cppVar_46261 = (cppVar_46261 & cppMask_un_16_);
	cppVar_46262 = ROM.rd(cppVar_46261);
	cppVar_46264 = (cppVar_46262 == 152);
	if (cppVar_46264) {
	cppVar_46260 = SCON;
	} else {
	cppVar_46266 = PC + 1;
	cppVar_46266 = (cppVar_46266 & cppMask_un_16_);
	cppVar_46267 = ROM.rd(cppVar_46266);
	cppVar_46269 = (cppVar_46267 == 153);
	if (cppVar_46269) {
	cppVar_46265 = SBUF;
	} else {
	cppVar_46271 = PC + 1;
	cppVar_46271 = (cppVar_46271 & cppMask_un_16_);
	cppVar_46272 = ROM.rd(cppVar_46271);
	cppVar_46274 = (cppVar_46272 == 160);
	if (cppVar_46274) {
	cppVar_46270 = P2;
	} else {
	cppVar_46276 = PC + 1;
	cppVar_46276 = (cppVar_46276 & cppMask_un_16_);
	cppVar_46277 = ROM.rd(cppVar_46276);
	cppVar_46279 = (cppVar_46277 == 168);
	if (cppVar_46279) {
	cppVar_46275 = IE;
	} else {
	cppVar_46281 = PC + 1;
	cppVar_46281 = (cppVar_46281 & cppMask_un_16_);
	cppVar_46282 = ROM.rd(cppVar_46281);
	cppVar_46284 = (cppVar_46282 == 176);
	if (cppVar_46284) {
	cppVar_46280 = P3;
	} else {
	cppVar_46286 = PC + 1;
	cppVar_46286 = (cppVar_46286 & cppMask_un_16_);
	cppVar_46287 = ROM.rd(cppVar_46286);
	cppVar_46289 = (cppVar_46287 == 184);
	if (cppVar_46289) {
	cppVar_46285 = IP;
	} else {
	cppVar_46291 = PC + 1;
	cppVar_46291 = (cppVar_46291 & cppMask_un_16_);
	cppVar_46292 = ROM.rd(cppVar_46291);
	cppVar_46294 = (cppVar_46292 == 208);
	if (cppVar_46294) {
	cppVar_46290 = PSW;
	} else {
	cppVar_46296 = PC + 1;
	cppVar_46296 = (cppVar_46296 & cppMask_un_16_);
	cppVar_46297 = ROM.rd(cppVar_46296);
	cppVar_46299 = (cppVar_46297 == 224);
	if (cppVar_46299) {
	cppVar_46295 = ACC;
	} else {
	cppVar_46301 = PC + 1;
	cppVar_46301 = (cppVar_46301 & cppMask_un_16_);
	cppVar_46302 = ROM.rd(cppVar_46301);
	cppVar_46304 = (cppVar_46302 == 240);
	if (cppVar_46304) {
	cppVar_46300 = B;
	} else {
	cppVar_46300 = 0;
	}
	cppVar_46295 = cppVar_46300;
	}
	cppVar_46290 = cppVar_46295;
	}
	cppVar_46285 = cppVar_46290;
	}
	cppVar_46280 = cppVar_46285;
	}
	cppVar_46275 = cppVar_46280;
	}
	cppVar_46270 = cppVar_46275;
	}
	cppVar_46265 = cppVar_46270;
	}
	cppVar_46260 = cppVar_46265;
	}
	cppVar_46255 = cppVar_46260;
	}
	cppVar_46250 = cppVar_46255;
	}
	cppVar_46245 = cppVar_46250;
	}
	cppVar_46240 = cppVar_46245;
	}
	cppVar_46235 = cppVar_46240;
	}
	cppVar_46230 = cppVar_46235;
	}
	cppVar_46225 = cppVar_46230;
	}
	cppVar_46220 = cppVar_46225;
	}
	cppVar_46215 = cppVar_46220;
	}
	cppVar_46210 = cppVar_46215;
	}
	cppVar_46205 = cppVar_46210;
	}
	cppVar_46200 = cppVar_46205;
	}
	cppVar_46191 = cppVar_46200;
	}
	cppVar_46307 = PC + 2;
	cppVar_46307 = (cppVar_46307 & cppMask_un_16_);
	cppVar_46308 = ROM.rd(cppVar_46307);
	cppVar_46309 = cppVar_46191 | cppVar_46308;
	cppVar_46185 = cppVar_46309;
	} else {
	cppVar_46185 = PCON;
	}
	cppVar_46181 = cppVar_46185;
	} else {
	cppVar_46311 = ROM.rd(PC);
	cppVar_46313 = (cppVar_46311 == 66);
	if (cppVar_46313) {
	cppVar_46316 = PC + 1;
	cppVar_46316 = (cppVar_46316 & cppMask_un_16_);
	cppVar_46317 = ROM.rd(cppVar_46316);
	cppVar_46319 = (cppVar_46317 == 135);
	if (cppVar_46319) {
	cppVar_46321 = PC + 1;
	cppVar_46321 = (cppVar_46321 & cppMask_un_16_);
	cppVar_46322 = ROM.rd(cppVar_46321);
	cppVar_46323 = (cppVar_46322 >> 7) & cppMask_un_1_;
	cppVar_46325 = (cppVar_46323 == 0);
	if (cppVar_46325) {
	cppVar_46326 = PC + 1;
	cppVar_46326 = (cppVar_46326 & cppMask_un_16_);
	cppVar_46327 = ROM.rd(cppVar_46326);
	cppVar_46328 = IRAM.rd(cppVar_46327);
	cppVar_46320 = cppVar_46328;
	} else {
	cppVar_46330 = PC + 1;
	cppVar_46330 = (cppVar_46330 & cppMask_un_16_);
	cppVar_46331 = ROM.rd(cppVar_46330);
	cppVar_46333 = (cppVar_46331 == 128);
	if (cppVar_46333) {
	cppVar_46329 = P0;
	} else {
	cppVar_46335 = PC + 1;
	cppVar_46335 = (cppVar_46335 & cppMask_un_16_);
	cppVar_46336 = ROM.rd(cppVar_46335);
	cppVar_46338 = (cppVar_46336 == 129);
	if (cppVar_46338) {
	cppVar_46334 = SP;
	} else {
	cppVar_46340 = PC + 1;
	cppVar_46340 = (cppVar_46340 & cppMask_un_16_);
	cppVar_46341 = ROM.rd(cppVar_46340);
	cppVar_46343 = (cppVar_46341 == 130);
	if (cppVar_46343) {
	cppVar_46339 = DPL;
	} else {
	cppVar_46345 = PC + 1;
	cppVar_46345 = (cppVar_46345 & cppMask_un_16_);
	cppVar_46346 = ROM.rd(cppVar_46345);
	cppVar_46348 = (cppVar_46346 == 131);
	if (cppVar_46348) {
	cppVar_46344 = DPH;
	} else {
	cppVar_46350 = PC + 1;
	cppVar_46350 = (cppVar_46350 & cppMask_un_16_);
	cppVar_46351 = ROM.rd(cppVar_46350);
	cppVar_46353 = (cppVar_46351 == 135);
	if (cppVar_46353) {
	cppVar_46349 = PCON;
	} else {
	cppVar_46355 = PC + 1;
	cppVar_46355 = (cppVar_46355 & cppMask_un_16_);
	cppVar_46356 = ROM.rd(cppVar_46355);
	cppVar_46358 = (cppVar_46356 == 136);
	if (cppVar_46358) {
	cppVar_46354 = TCON;
	} else {
	cppVar_46360 = PC + 1;
	cppVar_46360 = (cppVar_46360 & cppMask_un_16_);
	cppVar_46361 = ROM.rd(cppVar_46360);
	cppVar_46363 = (cppVar_46361 == 137);
	if (cppVar_46363) {
	cppVar_46359 = TMOD;
	} else {
	cppVar_46365 = PC + 1;
	cppVar_46365 = (cppVar_46365 & cppMask_un_16_);
	cppVar_46366 = ROM.rd(cppVar_46365);
	cppVar_46368 = (cppVar_46366 == 138);
	if (cppVar_46368) {
	cppVar_46364 = TL0;
	} else {
	cppVar_46370 = PC + 1;
	cppVar_46370 = (cppVar_46370 & cppMask_un_16_);
	cppVar_46371 = ROM.rd(cppVar_46370);
	cppVar_46373 = (cppVar_46371 == 140);
	if (cppVar_46373) {
	cppVar_46369 = TH0;
	} else {
	cppVar_46375 = PC + 1;
	cppVar_46375 = (cppVar_46375 & cppMask_un_16_);
	cppVar_46376 = ROM.rd(cppVar_46375);
	cppVar_46378 = (cppVar_46376 == 139);
	if (cppVar_46378) {
	cppVar_46374 = TL1;
	} else {
	cppVar_46380 = PC + 1;
	cppVar_46380 = (cppVar_46380 & cppMask_un_16_);
	cppVar_46381 = ROM.rd(cppVar_46380);
	cppVar_46383 = (cppVar_46381 == 141);
	if (cppVar_46383) {
	cppVar_46379 = TH1;
	} else {
	cppVar_46385 = PC + 1;
	cppVar_46385 = (cppVar_46385 & cppMask_un_16_);
	cppVar_46386 = ROM.rd(cppVar_46385);
	cppVar_46388 = (cppVar_46386 == 144);
	if (cppVar_46388) {
	cppVar_46384 = P1;
	} else {
	cppVar_46390 = PC + 1;
	cppVar_46390 = (cppVar_46390 & cppMask_un_16_);
	cppVar_46391 = ROM.rd(cppVar_46390);
	cppVar_46393 = (cppVar_46391 == 152);
	if (cppVar_46393) {
	cppVar_46389 = SCON;
	} else {
	cppVar_46395 = PC + 1;
	cppVar_46395 = (cppVar_46395 & cppMask_un_16_);
	cppVar_46396 = ROM.rd(cppVar_46395);
	cppVar_46398 = (cppVar_46396 == 153);
	if (cppVar_46398) {
	cppVar_46394 = SBUF;
	} else {
	cppVar_46400 = PC + 1;
	cppVar_46400 = (cppVar_46400 & cppMask_un_16_);
	cppVar_46401 = ROM.rd(cppVar_46400);
	cppVar_46403 = (cppVar_46401 == 160);
	if (cppVar_46403) {
	cppVar_46399 = P2;
	} else {
	cppVar_46405 = PC + 1;
	cppVar_46405 = (cppVar_46405 & cppMask_un_16_);
	cppVar_46406 = ROM.rd(cppVar_46405);
	cppVar_46408 = (cppVar_46406 == 168);
	if (cppVar_46408) {
	cppVar_46404 = IE;
	} else {
	cppVar_46410 = PC + 1;
	cppVar_46410 = (cppVar_46410 & cppMask_un_16_);
	cppVar_46411 = ROM.rd(cppVar_46410);
	cppVar_46413 = (cppVar_46411 == 176);
	if (cppVar_46413) {
	cppVar_46409 = P3;
	} else {
	cppVar_46415 = PC + 1;
	cppVar_46415 = (cppVar_46415 & cppMask_un_16_);
	cppVar_46416 = ROM.rd(cppVar_46415);
	cppVar_46418 = (cppVar_46416 == 184);
	if (cppVar_46418) {
	cppVar_46414 = IP;
	} else {
	cppVar_46420 = PC + 1;
	cppVar_46420 = (cppVar_46420 & cppMask_un_16_);
	cppVar_46421 = ROM.rd(cppVar_46420);
	cppVar_46423 = (cppVar_46421 == 208);
	if (cppVar_46423) {
	cppVar_46419 = PSW;
	} else {
	cppVar_46425 = PC + 1;
	cppVar_46425 = (cppVar_46425 & cppMask_un_16_);
	cppVar_46426 = ROM.rd(cppVar_46425);
	cppVar_46428 = (cppVar_46426 == 224);
	if (cppVar_46428) {
	cppVar_46424 = ACC;
	} else {
	cppVar_46430 = PC + 1;
	cppVar_46430 = (cppVar_46430 & cppMask_un_16_);
	cppVar_46431 = ROM.rd(cppVar_46430);
	cppVar_46433 = (cppVar_46431 == 240);
	if (cppVar_46433) {
	cppVar_46429 = B;
	} else {
	cppVar_46429 = 0;
	}
	cppVar_46424 = cppVar_46429;
	}
	cppVar_46419 = cppVar_46424;
	}
	cppVar_46414 = cppVar_46419;
	}
	cppVar_46409 = cppVar_46414;
	}
	cppVar_46404 = cppVar_46409;
	}
	cppVar_46399 = cppVar_46404;
	}
	cppVar_46394 = cppVar_46399;
	}
	cppVar_46389 = cppVar_46394;
	}
	cppVar_46384 = cppVar_46389;
	}
	cppVar_46379 = cppVar_46384;
	}
	cppVar_46374 = cppVar_46379;
	}
	cppVar_46369 = cppVar_46374;
	}
	cppVar_46364 = cppVar_46369;
	}
	cppVar_46359 = cppVar_46364;
	}
	cppVar_46354 = cppVar_46359;
	}
	cppVar_46349 = cppVar_46354;
	}
	cppVar_46344 = cppVar_46349;
	}
	cppVar_46339 = cppVar_46344;
	}
	cppVar_46334 = cppVar_46339;
	}
	cppVar_46329 = cppVar_46334;
	}
	cppVar_46320 = cppVar_46329;
	}
	cppVar_46435 = cppVar_46320 | ACC;
	cppVar_46314 = cppVar_46435;
	} else {
	cppVar_46314 = PCON;
	}
	cppVar_46310 = cppVar_46314;
	} else {
	cppVar_46437 = ROM.rd(PC);
	cppVar_46439 = (cppVar_46437 == 213);
	cppVar_46440 = ROM.rd(PC);
	cppVar_46442 = (cppVar_46440 == 21);
	cppVar_46443 = cppVar_46439 || cppVar_46442;
	if (cppVar_46443) {
	cppVar_46446 = PC + 1;
	cppVar_46446 = (cppVar_46446 & cppMask_un_16_);
	cppVar_46447 = ROM.rd(cppVar_46446);
	cppVar_46449 = (cppVar_46447 == 135);
	if (cppVar_46449) {
	cppVar_46451 = PC + 1;
	cppVar_46451 = (cppVar_46451 & cppMask_un_16_);
	cppVar_46452 = ROM.rd(cppVar_46451);
	cppVar_46453 = (cppVar_46452 >> 7) & cppMask_un_1_;
	cppVar_46455 = (cppVar_46453 == 0);
	if (cppVar_46455) {
	cppVar_46456 = PC + 1;
	cppVar_46456 = (cppVar_46456 & cppMask_un_16_);
	cppVar_46457 = ROM.rd(cppVar_46456);
	cppVar_46458 = IRAM.rd(cppVar_46457);
	cppVar_46450 = cppVar_46458;
	} else {
	cppVar_46460 = PC + 1;
	cppVar_46460 = (cppVar_46460 & cppMask_un_16_);
	cppVar_46461 = ROM.rd(cppVar_46460);
	cppVar_46463 = (cppVar_46461 == 128);
	if (cppVar_46463) {
	cppVar_46459 = P0;
	} else {
	cppVar_46465 = PC + 1;
	cppVar_46465 = (cppVar_46465 & cppMask_un_16_);
	cppVar_46466 = ROM.rd(cppVar_46465);
	cppVar_46468 = (cppVar_46466 == 129);
	if (cppVar_46468) {
	cppVar_46464 = SP;
	} else {
	cppVar_46470 = PC + 1;
	cppVar_46470 = (cppVar_46470 & cppMask_un_16_);
	cppVar_46471 = ROM.rd(cppVar_46470);
	cppVar_46473 = (cppVar_46471 == 130);
	if (cppVar_46473) {
	cppVar_46469 = DPL;
	} else {
	cppVar_46475 = PC + 1;
	cppVar_46475 = (cppVar_46475 & cppMask_un_16_);
	cppVar_46476 = ROM.rd(cppVar_46475);
	cppVar_46478 = (cppVar_46476 == 131);
	if (cppVar_46478) {
	cppVar_46474 = DPH;
	} else {
	cppVar_46480 = PC + 1;
	cppVar_46480 = (cppVar_46480 & cppMask_un_16_);
	cppVar_46481 = ROM.rd(cppVar_46480);
	cppVar_46483 = (cppVar_46481 == 135);
	if (cppVar_46483) {
	cppVar_46479 = PCON;
	} else {
	cppVar_46485 = PC + 1;
	cppVar_46485 = (cppVar_46485 & cppMask_un_16_);
	cppVar_46486 = ROM.rd(cppVar_46485);
	cppVar_46488 = (cppVar_46486 == 136);
	if (cppVar_46488) {
	cppVar_46484 = TCON;
	} else {
	cppVar_46490 = PC + 1;
	cppVar_46490 = (cppVar_46490 & cppMask_un_16_);
	cppVar_46491 = ROM.rd(cppVar_46490);
	cppVar_46493 = (cppVar_46491 == 137);
	if (cppVar_46493) {
	cppVar_46489 = TMOD;
	} else {
	cppVar_46495 = PC + 1;
	cppVar_46495 = (cppVar_46495 & cppMask_un_16_);
	cppVar_46496 = ROM.rd(cppVar_46495);
	cppVar_46498 = (cppVar_46496 == 138);
	if (cppVar_46498) {
	cppVar_46494 = TL0;
	} else {
	cppVar_46500 = PC + 1;
	cppVar_46500 = (cppVar_46500 & cppMask_un_16_);
	cppVar_46501 = ROM.rd(cppVar_46500);
	cppVar_46503 = (cppVar_46501 == 140);
	if (cppVar_46503) {
	cppVar_46499 = TH0;
	} else {
	cppVar_46505 = PC + 1;
	cppVar_46505 = (cppVar_46505 & cppMask_un_16_);
	cppVar_46506 = ROM.rd(cppVar_46505);
	cppVar_46508 = (cppVar_46506 == 139);
	if (cppVar_46508) {
	cppVar_46504 = TL1;
	} else {
	cppVar_46510 = PC + 1;
	cppVar_46510 = (cppVar_46510 & cppMask_un_16_);
	cppVar_46511 = ROM.rd(cppVar_46510);
	cppVar_46513 = (cppVar_46511 == 141);
	if (cppVar_46513) {
	cppVar_46509 = TH1;
	} else {
	cppVar_46515 = PC + 1;
	cppVar_46515 = (cppVar_46515 & cppMask_un_16_);
	cppVar_46516 = ROM.rd(cppVar_46515);
	cppVar_46518 = (cppVar_46516 == 144);
	if (cppVar_46518) {
	cppVar_46514 = P1;
	} else {
	cppVar_46520 = PC + 1;
	cppVar_46520 = (cppVar_46520 & cppMask_un_16_);
	cppVar_46521 = ROM.rd(cppVar_46520);
	cppVar_46523 = (cppVar_46521 == 152);
	if (cppVar_46523) {
	cppVar_46519 = SCON;
	} else {
	cppVar_46525 = PC + 1;
	cppVar_46525 = (cppVar_46525 & cppMask_un_16_);
	cppVar_46526 = ROM.rd(cppVar_46525);
	cppVar_46528 = (cppVar_46526 == 153);
	if (cppVar_46528) {
	cppVar_46524 = SBUF;
	} else {
	cppVar_46530 = PC + 1;
	cppVar_46530 = (cppVar_46530 & cppMask_un_16_);
	cppVar_46531 = ROM.rd(cppVar_46530);
	cppVar_46533 = (cppVar_46531 == 160);
	if (cppVar_46533) {
	cppVar_46529 = P2;
	} else {
	cppVar_46535 = PC + 1;
	cppVar_46535 = (cppVar_46535 & cppMask_un_16_);
	cppVar_46536 = ROM.rd(cppVar_46535);
	cppVar_46538 = (cppVar_46536 == 168);
	if (cppVar_46538) {
	cppVar_46534 = IE;
	} else {
	cppVar_46540 = PC + 1;
	cppVar_46540 = (cppVar_46540 & cppMask_un_16_);
	cppVar_46541 = ROM.rd(cppVar_46540);
	cppVar_46543 = (cppVar_46541 == 176);
	if (cppVar_46543) {
	cppVar_46539 = P3;
	} else {
	cppVar_46545 = PC + 1;
	cppVar_46545 = (cppVar_46545 & cppMask_un_16_);
	cppVar_46546 = ROM.rd(cppVar_46545);
	cppVar_46548 = (cppVar_46546 == 184);
	if (cppVar_46548) {
	cppVar_46544 = IP;
	} else {
	cppVar_46550 = PC + 1;
	cppVar_46550 = (cppVar_46550 & cppMask_un_16_);
	cppVar_46551 = ROM.rd(cppVar_46550);
	cppVar_46553 = (cppVar_46551 == 208);
	if (cppVar_46553) {
	cppVar_46549 = PSW;
	} else {
	cppVar_46555 = PC + 1;
	cppVar_46555 = (cppVar_46555 & cppMask_un_16_);
	cppVar_46556 = ROM.rd(cppVar_46555);
	cppVar_46558 = (cppVar_46556 == 224);
	if (cppVar_46558) {
	cppVar_46554 = ACC;
	} else {
	cppVar_46560 = PC + 1;
	cppVar_46560 = (cppVar_46560 & cppMask_un_16_);
	cppVar_46561 = ROM.rd(cppVar_46560);
	cppVar_46563 = (cppVar_46561 == 240);
	if (cppVar_46563) {
	cppVar_46559 = B;
	} else {
	cppVar_46559 = 0;
	}
	cppVar_46554 = cppVar_46559;
	}
	cppVar_46549 = cppVar_46554;
	}
	cppVar_46544 = cppVar_46549;
	}
	cppVar_46539 = cppVar_46544;
	}
	cppVar_46534 = cppVar_46539;
	}
	cppVar_46529 = cppVar_46534;
	}
	cppVar_46524 = cppVar_46529;
	}
	cppVar_46519 = cppVar_46524;
	}
	cppVar_46514 = cppVar_46519;
	}
	cppVar_46509 = cppVar_46514;
	}
	cppVar_46504 = cppVar_46509;
	}
	cppVar_46499 = cppVar_46504;
	}
	cppVar_46494 = cppVar_46499;
	}
	cppVar_46489 = cppVar_46494;
	}
	cppVar_46484 = cppVar_46489;
	}
	cppVar_46479 = cppVar_46484;
	}
	cppVar_46474 = cppVar_46479;
	}
	cppVar_46469 = cppVar_46474;
	}
	cppVar_46464 = cppVar_46469;
	}
	cppVar_46459 = cppVar_46464;
	}
	cppVar_46450 = cppVar_46459;
	}
	cppVar_46566 = cppVar_46450 - 1;
	cppVar_46566 = (cppVar_46566 & cppMask_un_8_);
	cppVar_46444 = cppVar_46566;
	} else {
	cppVar_46444 = PCON;
	}
	cppVar_46436 = cppVar_46444;
	} else {
	cppVar_46568 = ROM.rd(PC);
	cppVar_46570 = (cppVar_46568 == 5);
	if (cppVar_46570) {
	cppVar_46573 = PC + 1;
	cppVar_46573 = (cppVar_46573 & cppMask_un_16_);
	cppVar_46574 = ROM.rd(cppVar_46573);
	cppVar_46576 = (cppVar_46574 == 135);
	if (cppVar_46576) {
	cppVar_46578 = PC + 1;
	cppVar_46578 = (cppVar_46578 & cppMask_un_16_);
	cppVar_46579 = ROM.rd(cppVar_46578);
	cppVar_46580 = (cppVar_46579 >> 7) & cppMask_un_1_;
	cppVar_46582 = (cppVar_46580 == 0);
	if (cppVar_46582) {
	cppVar_46583 = PC + 1;
	cppVar_46583 = (cppVar_46583 & cppMask_un_16_);
	cppVar_46584 = ROM.rd(cppVar_46583);
	cppVar_46585 = IRAM.rd(cppVar_46584);
	cppVar_46577 = cppVar_46585;
	} else {
	cppVar_46587 = PC + 1;
	cppVar_46587 = (cppVar_46587 & cppMask_un_16_);
	cppVar_46588 = ROM.rd(cppVar_46587);
	cppVar_46590 = (cppVar_46588 == 128);
	if (cppVar_46590) {
	cppVar_46586 = P0;
	} else {
	cppVar_46592 = PC + 1;
	cppVar_46592 = (cppVar_46592 & cppMask_un_16_);
	cppVar_46593 = ROM.rd(cppVar_46592);
	cppVar_46595 = (cppVar_46593 == 129);
	if (cppVar_46595) {
	cppVar_46591 = SP;
	} else {
	cppVar_46597 = PC + 1;
	cppVar_46597 = (cppVar_46597 & cppMask_un_16_);
	cppVar_46598 = ROM.rd(cppVar_46597);
	cppVar_46600 = (cppVar_46598 == 130);
	if (cppVar_46600) {
	cppVar_46596 = DPL;
	} else {
	cppVar_46602 = PC + 1;
	cppVar_46602 = (cppVar_46602 & cppMask_un_16_);
	cppVar_46603 = ROM.rd(cppVar_46602);
	cppVar_46605 = (cppVar_46603 == 131);
	if (cppVar_46605) {
	cppVar_46601 = DPH;
	} else {
	cppVar_46607 = PC + 1;
	cppVar_46607 = (cppVar_46607 & cppMask_un_16_);
	cppVar_46608 = ROM.rd(cppVar_46607);
	cppVar_46610 = (cppVar_46608 == 135);
	if (cppVar_46610) {
	cppVar_46606 = PCON;
	} else {
	cppVar_46612 = PC + 1;
	cppVar_46612 = (cppVar_46612 & cppMask_un_16_);
	cppVar_46613 = ROM.rd(cppVar_46612);
	cppVar_46615 = (cppVar_46613 == 136);
	if (cppVar_46615) {
	cppVar_46611 = TCON;
	} else {
	cppVar_46617 = PC + 1;
	cppVar_46617 = (cppVar_46617 & cppMask_un_16_);
	cppVar_46618 = ROM.rd(cppVar_46617);
	cppVar_46620 = (cppVar_46618 == 137);
	if (cppVar_46620) {
	cppVar_46616 = TMOD;
	} else {
	cppVar_46622 = PC + 1;
	cppVar_46622 = (cppVar_46622 & cppMask_un_16_);
	cppVar_46623 = ROM.rd(cppVar_46622);
	cppVar_46625 = (cppVar_46623 == 138);
	if (cppVar_46625) {
	cppVar_46621 = TL0;
	} else {
	cppVar_46627 = PC + 1;
	cppVar_46627 = (cppVar_46627 & cppMask_un_16_);
	cppVar_46628 = ROM.rd(cppVar_46627);
	cppVar_46630 = (cppVar_46628 == 140);
	if (cppVar_46630) {
	cppVar_46626 = TH0;
	} else {
	cppVar_46632 = PC + 1;
	cppVar_46632 = (cppVar_46632 & cppMask_un_16_);
	cppVar_46633 = ROM.rd(cppVar_46632);
	cppVar_46635 = (cppVar_46633 == 139);
	if (cppVar_46635) {
	cppVar_46631 = TL1;
	} else {
	cppVar_46637 = PC + 1;
	cppVar_46637 = (cppVar_46637 & cppMask_un_16_);
	cppVar_46638 = ROM.rd(cppVar_46637);
	cppVar_46640 = (cppVar_46638 == 141);
	if (cppVar_46640) {
	cppVar_46636 = TH1;
	} else {
	cppVar_46642 = PC + 1;
	cppVar_46642 = (cppVar_46642 & cppMask_un_16_);
	cppVar_46643 = ROM.rd(cppVar_46642);
	cppVar_46645 = (cppVar_46643 == 144);
	if (cppVar_46645) {
	cppVar_46641 = P1;
	} else {
	cppVar_46647 = PC + 1;
	cppVar_46647 = (cppVar_46647 & cppMask_un_16_);
	cppVar_46648 = ROM.rd(cppVar_46647);
	cppVar_46650 = (cppVar_46648 == 152);
	if (cppVar_46650) {
	cppVar_46646 = SCON;
	} else {
	cppVar_46652 = PC + 1;
	cppVar_46652 = (cppVar_46652 & cppMask_un_16_);
	cppVar_46653 = ROM.rd(cppVar_46652);
	cppVar_46655 = (cppVar_46653 == 153);
	if (cppVar_46655) {
	cppVar_46651 = SBUF;
	} else {
	cppVar_46657 = PC + 1;
	cppVar_46657 = (cppVar_46657 & cppMask_un_16_);
	cppVar_46658 = ROM.rd(cppVar_46657);
	cppVar_46660 = (cppVar_46658 == 160);
	if (cppVar_46660) {
	cppVar_46656 = P2;
	} else {
	cppVar_46662 = PC + 1;
	cppVar_46662 = (cppVar_46662 & cppMask_un_16_);
	cppVar_46663 = ROM.rd(cppVar_46662);
	cppVar_46665 = (cppVar_46663 == 168);
	if (cppVar_46665) {
	cppVar_46661 = IE;
	} else {
	cppVar_46667 = PC + 1;
	cppVar_46667 = (cppVar_46667 & cppMask_un_16_);
	cppVar_46668 = ROM.rd(cppVar_46667);
	cppVar_46670 = (cppVar_46668 == 176);
	if (cppVar_46670) {
	cppVar_46666 = P3;
	} else {
	cppVar_46672 = PC + 1;
	cppVar_46672 = (cppVar_46672 & cppMask_un_16_);
	cppVar_46673 = ROM.rd(cppVar_46672);
	cppVar_46675 = (cppVar_46673 == 184);
	if (cppVar_46675) {
	cppVar_46671 = IP;
	} else {
	cppVar_46677 = PC + 1;
	cppVar_46677 = (cppVar_46677 & cppMask_un_16_);
	cppVar_46678 = ROM.rd(cppVar_46677);
	cppVar_46680 = (cppVar_46678 == 208);
	if (cppVar_46680) {
	cppVar_46676 = PSW;
	} else {
	cppVar_46682 = PC + 1;
	cppVar_46682 = (cppVar_46682 & cppMask_un_16_);
	cppVar_46683 = ROM.rd(cppVar_46682);
	cppVar_46685 = (cppVar_46683 == 224);
	if (cppVar_46685) {
	cppVar_46681 = ACC;
	} else {
	cppVar_46687 = PC + 1;
	cppVar_46687 = (cppVar_46687 & cppMask_un_16_);
	cppVar_46688 = ROM.rd(cppVar_46687);
	cppVar_46690 = (cppVar_46688 == 240);
	if (cppVar_46690) {
	cppVar_46686 = B;
	} else {
	cppVar_46686 = 0;
	}
	cppVar_46681 = cppVar_46686;
	}
	cppVar_46676 = cppVar_46681;
	}
	cppVar_46671 = cppVar_46676;
	}
	cppVar_46666 = cppVar_46671;
	}
	cppVar_46661 = cppVar_46666;
	}
	cppVar_46656 = cppVar_46661;
	}
	cppVar_46651 = cppVar_46656;
	}
	cppVar_46646 = cppVar_46651;
	}
	cppVar_46641 = cppVar_46646;
	}
	cppVar_46636 = cppVar_46641;
	}
	cppVar_46631 = cppVar_46636;
	}
	cppVar_46626 = cppVar_46631;
	}
	cppVar_46621 = cppVar_46626;
	}
	cppVar_46616 = cppVar_46621;
	}
	cppVar_46611 = cppVar_46616;
	}
	cppVar_46606 = cppVar_46611;
	}
	cppVar_46601 = cppVar_46606;
	}
	cppVar_46596 = cppVar_46601;
	}
	cppVar_46591 = cppVar_46596;
	}
	cppVar_46586 = cppVar_46591;
	}
	cppVar_46577 = cppVar_46586;
	}
	cppVar_46693 = cppVar_46577 + 1;
	cppVar_46693 = (cppVar_46693 & cppMask_un_8_);
	cppVar_46571 = cppVar_46693;
	} else {
	cppVar_46571 = PCON;
	}
	cppVar_46567 = cppVar_46571;
	} else {
	cppVar_46567 = PCON;
	}
	cppVar_46436 = cppVar_46567;
	}
	cppVar_46310 = cppVar_46436;
	}
	cppVar_46181 = cppVar_46310;
	}
	cppVar_46055 = cppVar_46181;
	}
	cppVar_45926 = cppVar_46055;
	}
	cppVar_45800 = cppVar_45926;
	}
	cppVar_45671 = cppVar_45800;
	}
	cppVar_45658 = cppVar_45671;
	}
	cppVar_45532 = cppVar_45658;
	}
	cppVar_45515 = cppVar_45532;
	}
	cppVar_45498 = cppVar_45515;
	}
	cppVar_45348 = cppVar_45498;
	}
	cppVar_45198 = cppVar_45348;
	}
	cppVar_45048 = cppVar_45198;
	}
	cppVar_44898 = cppVar_45048;
	}
	cppVar_44748 = cppVar_44898;
	}
	cppVar_44598 = cppVar_44748;
	}
	cppVar_44448 = cppVar_44598;
	}
	cppVar_44298 = cppVar_44448;
	}
	cppVar_44284 = cppVar_44298;
	}
	cppVar_44273 = cppVar_44284;
	}
	return cppVar_44273;
}
