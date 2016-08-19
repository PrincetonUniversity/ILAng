#include "common.hpp"
#include "model_oc8051_class.hpp"

BIT_VEC model_oc8051::cppUpdateFun_P0()
{
	BIT_VEC cppVar_22538;
	BIT_VEC cppVar_22539;
	bool cppVar_22540;
	BIT_VEC cppVar_22543;
	BIT_VEC cppVar_22544;
	BIT_VEC cppVar_22545;
	BIT_VEC cppVar_22546;
	BIT_VEC cppVar_22547;
	bool cppVar_22548;
	BIT_VEC cppVar_22549;
	BIT_VEC cppVar_22550;
	BIT_VEC cppVar_22551;
	BIT_VEC cppVar_22552;
	BIT_VEC cppVar_22553;
	BIT_VEC cppVar_22554;
	BIT_VEC cppVar_22555;
	BIT_VEC cppVar_22556;
	BIT_VEC cppVar_22557;
	BIT_VEC cppVar_22558;
	BIT_VEC cppVar_22559;
	BIT_VEC cppVar_22542;
	BIT_VEC cppVar_22560;
	bool cppVar_22561;
	BIT_VEC cppVar_22562;
	BIT_VEC cppVar_22563;
	BIT_VEC cppVar_22564;
	BIT_VEC cppVar_22565;
	BIT_VEC cppVar_22566;
	BIT_VEC cppVar_22567;
	BIT_VEC cppVar_22568;
	BIT_VEC cppVar_22571;
	BIT_VEC cppVar_22572;
	BIT_VEC cppVar_22573;
	bool cppVar_22574;
	BIT_VEC cppVar_22575;
	BIT_VEC cppVar_22576;
	BIT_VEC cppVar_22577;
	BIT_VEC cppVar_22578;
	BIT_VEC cppVar_22579;
	BIT_VEC cppVar_22580;
	BIT_VEC cppVar_22581;
	BIT_VEC cppVar_22582;
	BIT_VEC cppVar_22583;
	BIT_VEC cppVar_22570;
	BIT_VEC cppVar_22584;
	BIT_VEC cppVar_22585;
	bool cppVar_22586;
	BIT_VEC cppVar_22588;
	BIT_VEC cppVar_22589;
	BIT_VEC cppVar_22590;
	bool cppVar_22591;
	BIT_VEC cppVar_22592;
	BIT_VEC cppVar_22593;
	BIT_VEC cppVar_22594;
	BIT_VEC cppVar_22595;
	BIT_VEC cppVar_22596;
	BIT_VEC cppVar_22597;
	BIT_VEC cppVar_22598;
	BIT_VEC cppVar_22599;
	BIT_VEC cppVar_22600;
	BIT_VEC cppVar_22587;
	BIT_VEC cppVar_22601;
	BIT_VEC cppVar_22604;
	BIT_VEC cppVar_22605;
	BIT_VEC cppVar_22606;
	bool cppVar_22607;
	BIT_VEC cppVar_22608;
	BIT_VEC cppVar_22609;
	BIT_VEC cppVar_22610;
	BIT_VEC cppVar_22611;
	BIT_VEC cppVar_22612;
	BIT_VEC cppVar_22613;
	BIT_VEC cppVar_22614;
	BIT_VEC cppVar_22615;
	BIT_VEC cppVar_22616;
	BIT_VEC cppVar_22603;
	BIT_VEC cppVar_22617;
	bool cppVar_22618;
	BIT_VEC cppVar_22621;
	BIT_VEC cppVar_22622;
	BIT_VEC cppVar_22623;
	bool cppVar_22624;
	BIT_VEC cppVar_22625;
	BIT_VEC cppVar_22626;
	BIT_VEC cppVar_22627;
	BIT_VEC cppVar_22628;
	BIT_VEC cppVar_22629;
	BIT_VEC cppVar_22630;
	BIT_VEC cppVar_22631;
	BIT_VEC cppVar_22632;
	BIT_VEC cppVar_22633;
	BIT_VEC cppVar_22620;
	BIT_VEC cppVar_22634;
	bool cppVar_22635;
	BIT_VEC cppVar_22638;
	BIT_VEC cppVar_22639;
	BIT_VEC cppVar_22640;
	bool cppVar_22641;
	BIT_VEC cppVar_22642;
	BIT_VEC cppVar_22643;
	BIT_VEC cppVar_22644;
	BIT_VEC cppVar_22645;
	BIT_VEC cppVar_22646;
	BIT_VEC cppVar_22647;
	BIT_VEC cppVar_22648;
	BIT_VEC cppVar_22649;
	BIT_VEC cppVar_22650;
	BIT_VEC cppVar_22637;
	BIT_VEC cppVar_22651;
	bool cppVar_22652;
	BIT_VEC cppVar_22655;
	BIT_VEC cppVar_22656;
	BIT_VEC cppVar_22657;
	bool cppVar_22658;
	BIT_VEC cppVar_22659;
	BIT_VEC cppVar_22660;
	BIT_VEC cppVar_22661;
	BIT_VEC cppVar_22662;
	BIT_VEC cppVar_22663;
	BIT_VEC cppVar_22664;
	BIT_VEC cppVar_22665;
	BIT_VEC cppVar_22666;
	BIT_VEC cppVar_22667;
	BIT_VEC cppVar_22654;
	BIT_VEC cppVar_22668;
	bool cppVar_22669;
	BIT_VEC cppVar_22672;
	BIT_VEC cppVar_22673;
	BIT_VEC cppVar_22674;
	bool cppVar_22675;
	BIT_VEC cppVar_22676;
	BIT_VEC cppVar_22677;
	BIT_VEC cppVar_22678;
	BIT_VEC cppVar_22679;
	BIT_VEC cppVar_22680;
	BIT_VEC cppVar_22681;
	BIT_VEC cppVar_22682;
	BIT_VEC cppVar_22683;
	BIT_VEC cppVar_22684;
	BIT_VEC cppVar_22671;
	BIT_VEC cppVar_22685;
	bool cppVar_22686;
	BIT_VEC cppVar_22689;
	BIT_VEC cppVar_22690;
	BIT_VEC cppVar_22691;
	bool cppVar_22692;
	BIT_VEC cppVar_22693;
	BIT_VEC cppVar_22694;
	BIT_VEC cppVar_22695;
	BIT_VEC cppVar_22696;
	BIT_VEC cppVar_22697;
	BIT_VEC cppVar_22698;
	BIT_VEC cppVar_22699;
	BIT_VEC cppVar_22700;
	BIT_VEC cppVar_22701;
	BIT_VEC cppVar_22688;
	BIT_VEC cppVar_22702;
	bool cppVar_22703;
	BIT_VEC cppVar_22706;
	BIT_VEC cppVar_22707;
	BIT_VEC cppVar_22708;
	bool cppVar_22709;
	BIT_VEC cppVar_22710;
	BIT_VEC cppVar_22711;
	BIT_VEC cppVar_22712;
	BIT_VEC cppVar_22713;
	BIT_VEC cppVar_22714;
	BIT_VEC cppVar_22715;
	BIT_VEC cppVar_22716;
	BIT_VEC cppVar_22717;
	BIT_VEC cppVar_22718;
	BIT_VEC cppVar_22705;
	BIT_VEC cppVar_22719;
	bool cppVar_22720;
	BIT_VEC cppVar_22723;
	BIT_VEC cppVar_22724;
	BIT_VEC cppVar_22725;
	bool cppVar_22726;
	BIT_VEC cppVar_22727;
	BIT_VEC cppVar_22728;
	BIT_VEC cppVar_22729;
	BIT_VEC cppVar_22730;
	BIT_VEC cppVar_22731;
	BIT_VEC cppVar_22732;
	BIT_VEC cppVar_22733;
	BIT_VEC cppVar_22734;
	BIT_VEC cppVar_22735;
	BIT_VEC cppVar_22722;
	BIT_VEC cppVar_22736;
	bool cppVar_22737;
	BIT_VEC cppVar_22740;
	BIT_VEC cppVar_22741;
	BIT_VEC cppVar_22742;
	bool cppVar_22743;
	BIT_VEC cppVar_22744;
	BIT_VEC cppVar_22745;
	BIT_VEC cppVar_22746;
	BIT_VEC cppVar_22747;
	BIT_VEC cppVar_22748;
	BIT_VEC cppVar_22749;
	BIT_VEC cppVar_22750;
	BIT_VEC cppVar_22751;
	BIT_VEC cppVar_22752;
	BIT_VEC cppVar_22739;
	BIT_VEC cppVar_22753;
	bool cppVar_22754;
	BIT_VEC cppVar_22757;
	BIT_VEC cppVar_22758;
	BIT_VEC cppVar_22759;
	bool cppVar_22760;
	BIT_VEC cppVar_22761;
	BIT_VEC cppVar_22762;
	BIT_VEC cppVar_22763;
	BIT_VEC cppVar_22764;
	BIT_VEC cppVar_22765;
	BIT_VEC cppVar_22766;
	BIT_VEC cppVar_22767;
	BIT_VEC cppVar_22768;
	BIT_VEC cppVar_22769;
	BIT_VEC cppVar_22756;
	BIT_VEC cppVar_22770;
	bool cppVar_22771;
	BIT_VEC cppVar_22774;
	BIT_VEC cppVar_22775;
	BIT_VEC cppVar_22776;
	bool cppVar_22777;
	BIT_VEC cppVar_22778;
	BIT_VEC cppVar_22779;
	BIT_VEC cppVar_22780;
	BIT_VEC cppVar_22781;
	BIT_VEC cppVar_22782;
	BIT_VEC cppVar_22783;
	BIT_VEC cppVar_22784;
	BIT_VEC cppVar_22785;
	BIT_VEC cppVar_22786;
	BIT_VEC cppVar_22773;
	BIT_VEC cppVar_22787;
	bool cppVar_22788;
	BIT_VEC cppVar_22791;
	BIT_VEC cppVar_22792;
	BIT_VEC cppVar_22793;
	bool cppVar_22794;
	BIT_VEC cppVar_22795;
	BIT_VEC cppVar_22796;
	BIT_VEC cppVar_22797;
	BIT_VEC cppVar_22798;
	BIT_VEC cppVar_22799;
	BIT_VEC cppVar_22800;
	BIT_VEC cppVar_22801;
	BIT_VEC cppVar_22802;
	BIT_VEC cppVar_22803;
	BIT_VEC cppVar_22790;
	BIT_VEC cppVar_22804;
	bool cppVar_22805;
	BIT_VEC cppVar_22808;
	BIT_VEC cppVar_22809;
	BIT_VEC cppVar_22810;
	bool cppVar_22811;
	BIT_VEC cppVar_22812;
	BIT_VEC cppVar_22813;
	BIT_VEC cppVar_22814;
	BIT_VEC cppVar_22815;
	BIT_VEC cppVar_22816;
	BIT_VEC cppVar_22817;
	BIT_VEC cppVar_22818;
	BIT_VEC cppVar_22819;
	BIT_VEC cppVar_22820;
	BIT_VEC cppVar_22807;
	BIT_VEC cppVar_22821;
	bool cppVar_22822;
	BIT_VEC cppVar_22825;
	BIT_VEC cppVar_22826;
	BIT_VEC cppVar_22827;
	bool cppVar_22828;
	BIT_VEC cppVar_22829;
	BIT_VEC cppVar_22830;
	BIT_VEC cppVar_22831;
	BIT_VEC cppVar_22832;
	BIT_VEC cppVar_22833;
	BIT_VEC cppVar_22834;
	BIT_VEC cppVar_22835;
	BIT_VEC cppVar_22836;
	BIT_VEC cppVar_22837;
	BIT_VEC cppVar_22824;
	BIT_VEC cppVar_22838;
	bool cppVar_22839;
	BIT_VEC cppVar_22842;
	BIT_VEC cppVar_22843;
	BIT_VEC cppVar_22844;
	bool cppVar_22845;
	BIT_VEC cppVar_22846;
	BIT_VEC cppVar_22847;
	BIT_VEC cppVar_22848;
	BIT_VEC cppVar_22849;
	BIT_VEC cppVar_22850;
	BIT_VEC cppVar_22851;
	BIT_VEC cppVar_22852;
	BIT_VEC cppVar_22853;
	BIT_VEC cppVar_22854;
	BIT_VEC cppVar_22841;
	BIT_VEC cppVar_22855;
	bool cppVar_22856;
	BIT_VEC cppVar_22859;
	BIT_VEC cppVar_22860;
	BIT_VEC cppVar_22861;
	bool cppVar_22862;
	BIT_VEC cppVar_22863;
	BIT_VEC cppVar_22864;
	BIT_VEC cppVar_22865;
	BIT_VEC cppVar_22866;
	BIT_VEC cppVar_22867;
	BIT_VEC cppVar_22868;
	BIT_VEC cppVar_22869;
	BIT_VEC cppVar_22870;
	BIT_VEC cppVar_22871;
	BIT_VEC cppVar_22858;
	BIT_VEC cppVar_22872;
	bool cppVar_22873;
	BIT_VEC cppVar_22876;
	BIT_VEC cppVar_22877;
	BIT_VEC cppVar_22878;
	bool cppVar_22879;
	BIT_VEC cppVar_22880;
	BIT_VEC cppVar_22881;
	BIT_VEC cppVar_22882;
	BIT_VEC cppVar_22883;
	BIT_VEC cppVar_22884;
	BIT_VEC cppVar_22885;
	BIT_VEC cppVar_22886;
	BIT_VEC cppVar_22887;
	BIT_VEC cppVar_22888;
	BIT_VEC cppVar_22875;
	BIT_VEC cppVar_22889;
	bool cppVar_22890;
	BIT_VEC cppVar_22893;
	BIT_VEC cppVar_22894;
	BIT_VEC cppVar_22895;
	bool cppVar_22896;
	BIT_VEC cppVar_22897;
	BIT_VEC cppVar_22898;
	BIT_VEC cppVar_22899;
	BIT_VEC cppVar_22900;
	BIT_VEC cppVar_22901;
	BIT_VEC cppVar_22902;
	BIT_VEC cppVar_22903;
	BIT_VEC cppVar_22904;
	BIT_VEC cppVar_22905;
	BIT_VEC cppVar_22892;
	BIT_VEC cppVar_22906;
	bool cppVar_22907;
	BIT_VEC cppVar_22910;
	BIT_VEC cppVar_22911;
	BIT_VEC cppVar_22912;
	bool cppVar_22913;
	BIT_VEC cppVar_22914;
	BIT_VEC cppVar_22915;
	BIT_VEC cppVar_22916;
	BIT_VEC cppVar_22917;
	BIT_VEC cppVar_22918;
	BIT_VEC cppVar_22919;
	BIT_VEC cppVar_22920;
	BIT_VEC cppVar_22921;
	BIT_VEC cppVar_22922;
	BIT_VEC cppVar_22909;
	BIT_VEC cppVar_22923;
	bool cppVar_22924;
	BIT_VEC cppVar_22927;
	BIT_VEC cppVar_22928;
	BIT_VEC cppVar_22929;
	bool cppVar_22930;
	BIT_VEC cppVar_22931;
	BIT_VEC cppVar_22932;
	BIT_VEC cppVar_22933;
	BIT_VEC cppVar_22934;
	BIT_VEC cppVar_22935;
	BIT_VEC cppVar_22936;
	BIT_VEC cppVar_22937;
	BIT_VEC cppVar_22938;
	BIT_VEC cppVar_22939;
	BIT_VEC cppVar_22926;
	BIT_VEC cppVar_22940;
	bool cppVar_22941;
	BIT_VEC cppVar_22944;
	BIT_VEC cppVar_22945;
	BIT_VEC cppVar_22946;
	bool cppVar_22947;
	BIT_VEC cppVar_22948;
	BIT_VEC cppVar_22949;
	BIT_VEC cppVar_22950;
	BIT_VEC cppVar_22951;
	BIT_VEC cppVar_22952;
	BIT_VEC cppVar_22953;
	BIT_VEC cppVar_22954;
	BIT_VEC cppVar_22955;
	BIT_VEC cppVar_22956;
	BIT_VEC cppVar_22943;
	BIT_VEC cppVar_22957;
	bool cppVar_22958;
	BIT_VEC cppVar_22959;
	BIT_VEC cppVar_22942;
	BIT_VEC cppVar_22925;
	BIT_VEC cppVar_22908;
	BIT_VEC cppVar_22891;
	BIT_VEC cppVar_22874;
	BIT_VEC cppVar_22857;
	BIT_VEC cppVar_22840;
	BIT_VEC cppVar_22823;
	BIT_VEC cppVar_22806;
	BIT_VEC cppVar_22789;
	BIT_VEC cppVar_22772;
	BIT_VEC cppVar_22755;
	BIT_VEC cppVar_22738;
	BIT_VEC cppVar_22721;
	BIT_VEC cppVar_22704;
	BIT_VEC cppVar_22687;
	BIT_VEC cppVar_22670;
	BIT_VEC cppVar_22653;
	BIT_VEC cppVar_22636;
	BIT_VEC cppVar_22619;
	BIT_VEC cppVar_22602;
	BIT_VEC cppVar_22569;
	BIT_VEC cppVar_22960;
	BIT_VEC cppVar_22961;
	BIT_VEC cppVar_22962;
	BIT_VEC cppVar_22963;
	BIT_VEC cppVar_22964;
	BIT_VEC cppVar_22965;
	BIT_VEC cppVar_22966;
	BIT_VEC cppVar_22967;
	BIT_VEC cppVar_22968;
	BIT_VEC cppVar_22541;
	BIT_VEC cppVar_22970;
	BIT_VEC cppVar_22971;
	bool cppVar_22972;
	BIT_VEC cppVar_22974;
	BIT_VEC cppVar_22975;
	BIT_VEC cppVar_22976;
	BIT_VEC cppVar_22977;
	bool cppVar_22978;
	BIT_VEC cppVar_22979;
	BIT_VEC cppVar_22973;
	BIT_VEC cppVar_22981;
	BIT_VEC cppVar_22982;
	bool cppVar_22983;
	BIT_VEC cppVar_22984;
	BIT_VEC cppVar_22985;
	bool cppVar_22986;
	bool cppVar_22987;
	BIT_VEC cppVar_22989;
	BIT_VEC cppVar_22990;
	BIT_VEC cppVar_22991;
	BIT_VEC cppVar_22992;
	bool cppVar_22993;
	BIT_VEC cppVar_22988;
	BIT_VEC cppVar_22995;
	BIT_VEC cppVar_22996;
	bool cppVar_22997;
	BIT_VEC cppVar_23000;
	BIT_VEC cppVar_23001;
	BIT_VEC cppVar_23002;
	BIT_VEC cppVar_23003;
	BIT_VEC cppVar_23004;
	bool cppVar_23005;
	BIT_VEC cppVar_23006;
	BIT_VEC cppVar_23007;
	BIT_VEC cppVar_23008;
	BIT_VEC cppVar_23009;
	BIT_VEC cppVar_23010;
	BIT_VEC cppVar_23011;
	BIT_VEC cppVar_23012;
	BIT_VEC cppVar_23013;
	BIT_VEC cppVar_23014;
	BIT_VEC cppVar_23015;
	BIT_VEC cppVar_23016;
	BIT_VEC cppVar_22999;
	BIT_VEC cppVar_23017;
	bool cppVar_23018;
	BIT_VEC cppVar_23019;
	BIT_VEC cppVar_23020;
	BIT_VEC cppVar_23021;
	BIT_VEC cppVar_23022;
	BIT_VEC cppVar_23023;
	BIT_VEC cppVar_23024;
	BIT_VEC cppVar_23025;
	BIT_VEC cppVar_23028;
	BIT_VEC cppVar_23029;
	BIT_VEC cppVar_23030;
	bool cppVar_23031;
	BIT_VEC cppVar_23032;
	BIT_VEC cppVar_23033;
	BIT_VEC cppVar_23034;
	BIT_VEC cppVar_23035;
	BIT_VEC cppVar_23036;
	BIT_VEC cppVar_23037;
	BIT_VEC cppVar_23038;
	BIT_VEC cppVar_23039;
	BIT_VEC cppVar_23040;
	BIT_VEC cppVar_23027;
	BIT_VEC cppVar_23041;
	BIT_VEC cppVar_23042;
	bool cppVar_23043;
	BIT_VEC cppVar_23045;
	BIT_VEC cppVar_23046;
	BIT_VEC cppVar_23047;
	bool cppVar_23048;
	BIT_VEC cppVar_23049;
	BIT_VEC cppVar_23050;
	BIT_VEC cppVar_23051;
	BIT_VEC cppVar_23052;
	BIT_VEC cppVar_23053;
	BIT_VEC cppVar_23054;
	BIT_VEC cppVar_23055;
	BIT_VEC cppVar_23056;
	BIT_VEC cppVar_23057;
	BIT_VEC cppVar_23044;
	BIT_VEC cppVar_23058;
	BIT_VEC cppVar_23061;
	BIT_VEC cppVar_23062;
	BIT_VEC cppVar_23063;
	bool cppVar_23064;
	BIT_VEC cppVar_23065;
	BIT_VEC cppVar_23066;
	BIT_VEC cppVar_23067;
	BIT_VEC cppVar_23068;
	BIT_VEC cppVar_23069;
	BIT_VEC cppVar_23070;
	BIT_VEC cppVar_23071;
	BIT_VEC cppVar_23072;
	BIT_VEC cppVar_23073;
	BIT_VEC cppVar_23060;
	BIT_VEC cppVar_23074;
	bool cppVar_23075;
	BIT_VEC cppVar_23078;
	BIT_VEC cppVar_23079;
	BIT_VEC cppVar_23080;
	bool cppVar_23081;
	BIT_VEC cppVar_23082;
	BIT_VEC cppVar_23083;
	BIT_VEC cppVar_23084;
	BIT_VEC cppVar_23085;
	BIT_VEC cppVar_23086;
	BIT_VEC cppVar_23087;
	BIT_VEC cppVar_23088;
	BIT_VEC cppVar_23089;
	BIT_VEC cppVar_23090;
	BIT_VEC cppVar_23077;
	BIT_VEC cppVar_23091;
	bool cppVar_23092;
	BIT_VEC cppVar_23095;
	BIT_VEC cppVar_23096;
	BIT_VEC cppVar_23097;
	bool cppVar_23098;
	BIT_VEC cppVar_23099;
	BIT_VEC cppVar_23100;
	BIT_VEC cppVar_23101;
	BIT_VEC cppVar_23102;
	BIT_VEC cppVar_23103;
	BIT_VEC cppVar_23104;
	BIT_VEC cppVar_23105;
	BIT_VEC cppVar_23106;
	BIT_VEC cppVar_23107;
	BIT_VEC cppVar_23094;
	BIT_VEC cppVar_23108;
	bool cppVar_23109;
	BIT_VEC cppVar_23112;
	BIT_VEC cppVar_23113;
	BIT_VEC cppVar_23114;
	bool cppVar_23115;
	BIT_VEC cppVar_23116;
	BIT_VEC cppVar_23117;
	BIT_VEC cppVar_23118;
	BIT_VEC cppVar_23119;
	BIT_VEC cppVar_23120;
	BIT_VEC cppVar_23121;
	BIT_VEC cppVar_23122;
	BIT_VEC cppVar_23123;
	BIT_VEC cppVar_23124;
	BIT_VEC cppVar_23111;
	BIT_VEC cppVar_23125;
	bool cppVar_23126;
	BIT_VEC cppVar_23129;
	BIT_VEC cppVar_23130;
	BIT_VEC cppVar_23131;
	bool cppVar_23132;
	BIT_VEC cppVar_23133;
	BIT_VEC cppVar_23134;
	BIT_VEC cppVar_23135;
	BIT_VEC cppVar_23136;
	BIT_VEC cppVar_23137;
	BIT_VEC cppVar_23138;
	BIT_VEC cppVar_23139;
	BIT_VEC cppVar_23140;
	BIT_VEC cppVar_23141;
	BIT_VEC cppVar_23128;
	BIT_VEC cppVar_23142;
	bool cppVar_23143;
	BIT_VEC cppVar_23146;
	BIT_VEC cppVar_23147;
	BIT_VEC cppVar_23148;
	bool cppVar_23149;
	BIT_VEC cppVar_23150;
	BIT_VEC cppVar_23151;
	BIT_VEC cppVar_23152;
	BIT_VEC cppVar_23153;
	BIT_VEC cppVar_23154;
	BIT_VEC cppVar_23155;
	BIT_VEC cppVar_23156;
	BIT_VEC cppVar_23157;
	BIT_VEC cppVar_23158;
	BIT_VEC cppVar_23145;
	BIT_VEC cppVar_23159;
	bool cppVar_23160;
	BIT_VEC cppVar_23163;
	BIT_VEC cppVar_23164;
	BIT_VEC cppVar_23165;
	bool cppVar_23166;
	BIT_VEC cppVar_23167;
	BIT_VEC cppVar_23168;
	BIT_VEC cppVar_23169;
	BIT_VEC cppVar_23170;
	BIT_VEC cppVar_23171;
	BIT_VEC cppVar_23172;
	BIT_VEC cppVar_23173;
	BIT_VEC cppVar_23174;
	BIT_VEC cppVar_23175;
	BIT_VEC cppVar_23162;
	BIT_VEC cppVar_23176;
	bool cppVar_23177;
	BIT_VEC cppVar_23180;
	BIT_VEC cppVar_23181;
	BIT_VEC cppVar_23182;
	bool cppVar_23183;
	BIT_VEC cppVar_23184;
	BIT_VEC cppVar_23185;
	BIT_VEC cppVar_23186;
	BIT_VEC cppVar_23187;
	BIT_VEC cppVar_23188;
	BIT_VEC cppVar_23189;
	BIT_VEC cppVar_23190;
	BIT_VEC cppVar_23191;
	BIT_VEC cppVar_23192;
	BIT_VEC cppVar_23179;
	BIT_VEC cppVar_23193;
	bool cppVar_23194;
	BIT_VEC cppVar_23197;
	BIT_VEC cppVar_23198;
	BIT_VEC cppVar_23199;
	bool cppVar_23200;
	BIT_VEC cppVar_23201;
	BIT_VEC cppVar_23202;
	BIT_VEC cppVar_23203;
	BIT_VEC cppVar_23204;
	BIT_VEC cppVar_23205;
	BIT_VEC cppVar_23206;
	BIT_VEC cppVar_23207;
	BIT_VEC cppVar_23208;
	BIT_VEC cppVar_23209;
	BIT_VEC cppVar_23196;
	BIT_VEC cppVar_23210;
	bool cppVar_23211;
	BIT_VEC cppVar_23214;
	BIT_VEC cppVar_23215;
	BIT_VEC cppVar_23216;
	bool cppVar_23217;
	BIT_VEC cppVar_23218;
	BIT_VEC cppVar_23219;
	BIT_VEC cppVar_23220;
	BIT_VEC cppVar_23221;
	BIT_VEC cppVar_23222;
	BIT_VEC cppVar_23223;
	BIT_VEC cppVar_23224;
	BIT_VEC cppVar_23225;
	BIT_VEC cppVar_23226;
	BIT_VEC cppVar_23213;
	BIT_VEC cppVar_23227;
	bool cppVar_23228;
	BIT_VEC cppVar_23231;
	BIT_VEC cppVar_23232;
	BIT_VEC cppVar_23233;
	bool cppVar_23234;
	BIT_VEC cppVar_23235;
	BIT_VEC cppVar_23236;
	BIT_VEC cppVar_23237;
	BIT_VEC cppVar_23238;
	BIT_VEC cppVar_23239;
	BIT_VEC cppVar_23240;
	BIT_VEC cppVar_23241;
	BIT_VEC cppVar_23242;
	BIT_VEC cppVar_23243;
	BIT_VEC cppVar_23230;
	BIT_VEC cppVar_23244;
	bool cppVar_23245;
	BIT_VEC cppVar_23248;
	BIT_VEC cppVar_23249;
	BIT_VEC cppVar_23250;
	bool cppVar_23251;
	BIT_VEC cppVar_23252;
	BIT_VEC cppVar_23253;
	BIT_VEC cppVar_23254;
	BIT_VEC cppVar_23255;
	BIT_VEC cppVar_23256;
	BIT_VEC cppVar_23257;
	BIT_VEC cppVar_23258;
	BIT_VEC cppVar_23259;
	BIT_VEC cppVar_23260;
	BIT_VEC cppVar_23247;
	BIT_VEC cppVar_23261;
	bool cppVar_23262;
	BIT_VEC cppVar_23265;
	BIT_VEC cppVar_23266;
	BIT_VEC cppVar_23267;
	bool cppVar_23268;
	BIT_VEC cppVar_23269;
	BIT_VEC cppVar_23270;
	BIT_VEC cppVar_23271;
	BIT_VEC cppVar_23272;
	BIT_VEC cppVar_23273;
	BIT_VEC cppVar_23274;
	BIT_VEC cppVar_23275;
	BIT_VEC cppVar_23276;
	BIT_VEC cppVar_23277;
	BIT_VEC cppVar_23264;
	BIT_VEC cppVar_23278;
	bool cppVar_23279;
	BIT_VEC cppVar_23282;
	BIT_VEC cppVar_23283;
	BIT_VEC cppVar_23284;
	bool cppVar_23285;
	BIT_VEC cppVar_23286;
	BIT_VEC cppVar_23287;
	BIT_VEC cppVar_23288;
	BIT_VEC cppVar_23289;
	BIT_VEC cppVar_23290;
	BIT_VEC cppVar_23291;
	BIT_VEC cppVar_23292;
	BIT_VEC cppVar_23293;
	BIT_VEC cppVar_23294;
	BIT_VEC cppVar_23281;
	BIT_VEC cppVar_23295;
	bool cppVar_23296;
	BIT_VEC cppVar_23299;
	BIT_VEC cppVar_23300;
	BIT_VEC cppVar_23301;
	bool cppVar_23302;
	BIT_VEC cppVar_23303;
	BIT_VEC cppVar_23304;
	BIT_VEC cppVar_23305;
	BIT_VEC cppVar_23306;
	BIT_VEC cppVar_23307;
	BIT_VEC cppVar_23308;
	BIT_VEC cppVar_23309;
	BIT_VEC cppVar_23310;
	BIT_VEC cppVar_23311;
	BIT_VEC cppVar_23298;
	BIT_VEC cppVar_23312;
	bool cppVar_23313;
	BIT_VEC cppVar_23316;
	BIT_VEC cppVar_23317;
	BIT_VEC cppVar_23318;
	bool cppVar_23319;
	BIT_VEC cppVar_23320;
	BIT_VEC cppVar_23321;
	BIT_VEC cppVar_23322;
	BIT_VEC cppVar_23323;
	BIT_VEC cppVar_23324;
	BIT_VEC cppVar_23325;
	BIT_VEC cppVar_23326;
	BIT_VEC cppVar_23327;
	BIT_VEC cppVar_23328;
	BIT_VEC cppVar_23315;
	BIT_VEC cppVar_23329;
	bool cppVar_23330;
	BIT_VEC cppVar_23333;
	BIT_VEC cppVar_23334;
	BIT_VEC cppVar_23335;
	bool cppVar_23336;
	BIT_VEC cppVar_23337;
	BIT_VEC cppVar_23338;
	BIT_VEC cppVar_23339;
	BIT_VEC cppVar_23340;
	BIT_VEC cppVar_23341;
	BIT_VEC cppVar_23342;
	BIT_VEC cppVar_23343;
	BIT_VEC cppVar_23344;
	BIT_VEC cppVar_23345;
	BIT_VEC cppVar_23332;
	BIT_VEC cppVar_23346;
	bool cppVar_23347;
	BIT_VEC cppVar_23350;
	BIT_VEC cppVar_23351;
	BIT_VEC cppVar_23352;
	bool cppVar_23353;
	BIT_VEC cppVar_23354;
	BIT_VEC cppVar_23355;
	BIT_VEC cppVar_23356;
	BIT_VEC cppVar_23357;
	BIT_VEC cppVar_23358;
	BIT_VEC cppVar_23359;
	BIT_VEC cppVar_23360;
	BIT_VEC cppVar_23361;
	BIT_VEC cppVar_23362;
	BIT_VEC cppVar_23349;
	BIT_VEC cppVar_23363;
	bool cppVar_23364;
	BIT_VEC cppVar_23367;
	BIT_VEC cppVar_23368;
	BIT_VEC cppVar_23369;
	bool cppVar_23370;
	BIT_VEC cppVar_23371;
	BIT_VEC cppVar_23372;
	BIT_VEC cppVar_23373;
	BIT_VEC cppVar_23374;
	BIT_VEC cppVar_23375;
	BIT_VEC cppVar_23376;
	BIT_VEC cppVar_23377;
	BIT_VEC cppVar_23378;
	BIT_VEC cppVar_23379;
	BIT_VEC cppVar_23366;
	BIT_VEC cppVar_23380;
	bool cppVar_23381;
	BIT_VEC cppVar_23384;
	BIT_VEC cppVar_23385;
	BIT_VEC cppVar_23386;
	bool cppVar_23387;
	BIT_VEC cppVar_23388;
	BIT_VEC cppVar_23389;
	BIT_VEC cppVar_23390;
	BIT_VEC cppVar_23391;
	BIT_VEC cppVar_23392;
	BIT_VEC cppVar_23393;
	BIT_VEC cppVar_23394;
	BIT_VEC cppVar_23395;
	BIT_VEC cppVar_23396;
	BIT_VEC cppVar_23383;
	BIT_VEC cppVar_23397;
	bool cppVar_23398;
	BIT_VEC cppVar_23401;
	BIT_VEC cppVar_23402;
	BIT_VEC cppVar_23403;
	bool cppVar_23404;
	BIT_VEC cppVar_23405;
	BIT_VEC cppVar_23406;
	BIT_VEC cppVar_23407;
	BIT_VEC cppVar_23408;
	BIT_VEC cppVar_23409;
	BIT_VEC cppVar_23410;
	BIT_VEC cppVar_23411;
	BIT_VEC cppVar_23412;
	BIT_VEC cppVar_23413;
	BIT_VEC cppVar_23400;
	BIT_VEC cppVar_23414;
	bool cppVar_23415;
	BIT_VEC cppVar_23416;
	BIT_VEC cppVar_23399;
	BIT_VEC cppVar_23382;
	BIT_VEC cppVar_23365;
	BIT_VEC cppVar_23348;
	BIT_VEC cppVar_23331;
	BIT_VEC cppVar_23314;
	BIT_VEC cppVar_23297;
	BIT_VEC cppVar_23280;
	BIT_VEC cppVar_23263;
	BIT_VEC cppVar_23246;
	BIT_VEC cppVar_23229;
	BIT_VEC cppVar_23212;
	BIT_VEC cppVar_23195;
	BIT_VEC cppVar_23178;
	BIT_VEC cppVar_23161;
	BIT_VEC cppVar_23144;
	BIT_VEC cppVar_23127;
	BIT_VEC cppVar_23110;
	BIT_VEC cppVar_23093;
	BIT_VEC cppVar_23076;
	BIT_VEC cppVar_23059;
	BIT_VEC cppVar_23026;
	BIT_VEC cppVar_23417;
	BIT_VEC cppVar_23420;
	BIT_VEC cppVar_23421;
	BIT_VEC cppVar_23422;
	BIT_VEC cppVar_23423;
	bool cppVar_23424;
	BIT_VEC cppVar_23425;
	BIT_VEC cppVar_23426;
	BIT_VEC cppVar_23427;
	BIT_VEC cppVar_23428;
	BIT_VEC cppVar_23429;
	BIT_VEC cppVar_23430;
	BIT_VEC cppVar_23431;
	BIT_VEC cppVar_23432;
	BIT_VEC cppVar_23433;
	BIT_VEC cppVar_23434;
	BIT_VEC cppVar_23435;
	BIT_VEC cppVar_23419;
	BIT_VEC cppVar_23436;
	BIT_VEC cppVar_23437;
	bool cppVar_23438;
	BIT_VEC cppVar_23440;
	BIT_VEC cppVar_23441;
	BIT_VEC cppVar_23442;
	bool cppVar_23443;
	BIT_VEC cppVar_23444;
	BIT_VEC cppVar_23445;
	BIT_VEC cppVar_23446;
	BIT_VEC cppVar_23447;
	BIT_VEC cppVar_23448;
	BIT_VEC cppVar_23449;
	BIT_VEC cppVar_23450;
	BIT_VEC cppVar_23451;
	BIT_VEC cppVar_23452;
	BIT_VEC cppVar_23439;
	BIT_VEC cppVar_23453;
	BIT_VEC cppVar_23456;
	BIT_VEC cppVar_23457;
	BIT_VEC cppVar_23458;
	bool cppVar_23459;
	BIT_VEC cppVar_23460;
	BIT_VEC cppVar_23461;
	BIT_VEC cppVar_23462;
	BIT_VEC cppVar_23463;
	BIT_VEC cppVar_23464;
	BIT_VEC cppVar_23465;
	BIT_VEC cppVar_23466;
	BIT_VEC cppVar_23467;
	BIT_VEC cppVar_23468;
	BIT_VEC cppVar_23455;
	BIT_VEC cppVar_23469;
	bool cppVar_23470;
	BIT_VEC cppVar_23473;
	BIT_VEC cppVar_23474;
	BIT_VEC cppVar_23475;
	bool cppVar_23476;
	BIT_VEC cppVar_23477;
	BIT_VEC cppVar_23478;
	BIT_VEC cppVar_23479;
	BIT_VEC cppVar_23480;
	BIT_VEC cppVar_23481;
	BIT_VEC cppVar_23482;
	BIT_VEC cppVar_23483;
	BIT_VEC cppVar_23484;
	BIT_VEC cppVar_23485;
	BIT_VEC cppVar_23472;
	BIT_VEC cppVar_23486;
	bool cppVar_23487;
	BIT_VEC cppVar_23490;
	BIT_VEC cppVar_23491;
	BIT_VEC cppVar_23492;
	bool cppVar_23493;
	BIT_VEC cppVar_23494;
	BIT_VEC cppVar_23495;
	BIT_VEC cppVar_23496;
	BIT_VEC cppVar_23497;
	BIT_VEC cppVar_23498;
	BIT_VEC cppVar_23499;
	BIT_VEC cppVar_23500;
	BIT_VEC cppVar_23501;
	BIT_VEC cppVar_23502;
	BIT_VEC cppVar_23489;
	BIT_VEC cppVar_23503;
	bool cppVar_23504;
	BIT_VEC cppVar_23507;
	BIT_VEC cppVar_23508;
	BIT_VEC cppVar_23509;
	bool cppVar_23510;
	BIT_VEC cppVar_23511;
	BIT_VEC cppVar_23512;
	BIT_VEC cppVar_23513;
	BIT_VEC cppVar_23514;
	BIT_VEC cppVar_23515;
	BIT_VEC cppVar_23516;
	BIT_VEC cppVar_23517;
	BIT_VEC cppVar_23518;
	BIT_VEC cppVar_23519;
	BIT_VEC cppVar_23506;
	BIT_VEC cppVar_23520;
	bool cppVar_23521;
	BIT_VEC cppVar_23524;
	BIT_VEC cppVar_23525;
	BIT_VEC cppVar_23526;
	bool cppVar_23527;
	BIT_VEC cppVar_23528;
	BIT_VEC cppVar_23529;
	BIT_VEC cppVar_23530;
	BIT_VEC cppVar_23531;
	BIT_VEC cppVar_23532;
	BIT_VEC cppVar_23533;
	BIT_VEC cppVar_23534;
	BIT_VEC cppVar_23535;
	BIT_VEC cppVar_23536;
	BIT_VEC cppVar_23523;
	BIT_VEC cppVar_23537;
	bool cppVar_23538;
	BIT_VEC cppVar_23541;
	BIT_VEC cppVar_23542;
	BIT_VEC cppVar_23543;
	bool cppVar_23544;
	BIT_VEC cppVar_23545;
	BIT_VEC cppVar_23546;
	BIT_VEC cppVar_23547;
	BIT_VEC cppVar_23548;
	BIT_VEC cppVar_23549;
	BIT_VEC cppVar_23550;
	BIT_VEC cppVar_23551;
	BIT_VEC cppVar_23552;
	BIT_VEC cppVar_23553;
	BIT_VEC cppVar_23540;
	BIT_VEC cppVar_23554;
	bool cppVar_23555;
	BIT_VEC cppVar_23558;
	BIT_VEC cppVar_23559;
	BIT_VEC cppVar_23560;
	bool cppVar_23561;
	BIT_VEC cppVar_23562;
	BIT_VEC cppVar_23563;
	BIT_VEC cppVar_23564;
	BIT_VEC cppVar_23565;
	BIT_VEC cppVar_23566;
	BIT_VEC cppVar_23567;
	BIT_VEC cppVar_23568;
	BIT_VEC cppVar_23569;
	BIT_VEC cppVar_23570;
	BIT_VEC cppVar_23557;
	BIT_VEC cppVar_23571;
	bool cppVar_23572;
	BIT_VEC cppVar_23575;
	BIT_VEC cppVar_23576;
	BIT_VEC cppVar_23577;
	bool cppVar_23578;
	BIT_VEC cppVar_23579;
	BIT_VEC cppVar_23580;
	BIT_VEC cppVar_23581;
	BIT_VEC cppVar_23582;
	BIT_VEC cppVar_23583;
	BIT_VEC cppVar_23584;
	BIT_VEC cppVar_23585;
	BIT_VEC cppVar_23586;
	BIT_VEC cppVar_23587;
	BIT_VEC cppVar_23574;
	BIT_VEC cppVar_23588;
	bool cppVar_23589;
	BIT_VEC cppVar_23592;
	BIT_VEC cppVar_23593;
	BIT_VEC cppVar_23594;
	bool cppVar_23595;
	BIT_VEC cppVar_23596;
	BIT_VEC cppVar_23597;
	BIT_VEC cppVar_23598;
	BIT_VEC cppVar_23599;
	BIT_VEC cppVar_23600;
	BIT_VEC cppVar_23601;
	BIT_VEC cppVar_23602;
	BIT_VEC cppVar_23603;
	BIT_VEC cppVar_23604;
	BIT_VEC cppVar_23591;
	BIT_VEC cppVar_23605;
	bool cppVar_23606;
	BIT_VEC cppVar_23609;
	BIT_VEC cppVar_23610;
	BIT_VEC cppVar_23611;
	bool cppVar_23612;
	BIT_VEC cppVar_23613;
	BIT_VEC cppVar_23614;
	BIT_VEC cppVar_23615;
	BIT_VEC cppVar_23616;
	BIT_VEC cppVar_23617;
	BIT_VEC cppVar_23618;
	BIT_VEC cppVar_23619;
	BIT_VEC cppVar_23620;
	BIT_VEC cppVar_23621;
	BIT_VEC cppVar_23608;
	BIT_VEC cppVar_23622;
	bool cppVar_23623;
	BIT_VEC cppVar_23626;
	BIT_VEC cppVar_23627;
	BIT_VEC cppVar_23628;
	bool cppVar_23629;
	BIT_VEC cppVar_23630;
	BIT_VEC cppVar_23631;
	BIT_VEC cppVar_23632;
	BIT_VEC cppVar_23633;
	BIT_VEC cppVar_23634;
	BIT_VEC cppVar_23635;
	BIT_VEC cppVar_23636;
	BIT_VEC cppVar_23637;
	BIT_VEC cppVar_23638;
	BIT_VEC cppVar_23625;
	BIT_VEC cppVar_23639;
	bool cppVar_23640;
	BIT_VEC cppVar_23643;
	BIT_VEC cppVar_23644;
	BIT_VEC cppVar_23645;
	bool cppVar_23646;
	BIT_VEC cppVar_23647;
	BIT_VEC cppVar_23648;
	BIT_VEC cppVar_23649;
	BIT_VEC cppVar_23650;
	BIT_VEC cppVar_23651;
	BIT_VEC cppVar_23652;
	BIT_VEC cppVar_23653;
	BIT_VEC cppVar_23654;
	BIT_VEC cppVar_23655;
	BIT_VEC cppVar_23642;
	BIT_VEC cppVar_23656;
	bool cppVar_23657;
	BIT_VEC cppVar_23660;
	BIT_VEC cppVar_23661;
	BIT_VEC cppVar_23662;
	bool cppVar_23663;
	BIT_VEC cppVar_23664;
	BIT_VEC cppVar_23665;
	BIT_VEC cppVar_23666;
	BIT_VEC cppVar_23667;
	BIT_VEC cppVar_23668;
	BIT_VEC cppVar_23669;
	BIT_VEC cppVar_23670;
	BIT_VEC cppVar_23671;
	BIT_VEC cppVar_23672;
	BIT_VEC cppVar_23659;
	BIT_VEC cppVar_23673;
	bool cppVar_23674;
	BIT_VEC cppVar_23677;
	BIT_VEC cppVar_23678;
	BIT_VEC cppVar_23679;
	bool cppVar_23680;
	BIT_VEC cppVar_23681;
	BIT_VEC cppVar_23682;
	BIT_VEC cppVar_23683;
	BIT_VEC cppVar_23684;
	BIT_VEC cppVar_23685;
	BIT_VEC cppVar_23686;
	BIT_VEC cppVar_23687;
	BIT_VEC cppVar_23688;
	BIT_VEC cppVar_23689;
	BIT_VEC cppVar_23676;
	BIT_VEC cppVar_23690;
	bool cppVar_23691;
	BIT_VEC cppVar_23694;
	BIT_VEC cppVar_23695;
	BIT_VEC cppVar_23696;
	bool cppVar_23697;
	BIT_VEC cppVar_23698;
	BIT_VEC cppVar_23699;
	BIT_VEC cppVar_23700;
	BIT_VEC cppVar_23701;
	BIT_VEC cppVar_23702;
	BIT_VEC cppVar_23703;
	BIT_VEC cppVar_23704;
	BIT_VEC cppVar_23705;
	BIT_VEC cppVar_23706;
	BIT_VEC cppVar_23693;
	BIT_VEC cppVar_23707;
	bool cppVar_23708;
	BIT_VEC cppVar_23711;
	BIT_VEC cppVar_23712;
	BIT_VEC cppVar_23713;
	bool cppVar_23714;
	BIT_VEC cppVar_23715;
	BIT_VEC cppVar_23716;
	BIT_VEC cppVar_23717;
	BIT_VEC cppVar_23718;
	BIT_VEC cppVar_23719;
	BIT_VEC cppVar_23720;
	BIT_VEC cppVar_23721;
	BIT_VEC cppVar_23722;
	BIT_VEC cppVar_23723;
	BIT_VEC cppVar_23710;
	BIT_VEC cppVar_23724;
	bool cppVar_23725;
	BIT_VEC cppVar_23728;
	BIT_VEC cppVar_23729;
	BIT_VEC cppVar_23730;
	bool cppVar_23731;
	BIT_VEC cppVar_23732;
	BIT_VEC cppVar_23733;
	BIT_VEC cppVar_23734;
	BIT_VEC cppVar_23735;
	BIT_VEC cppVar_23736;
	BIT_VEC cppVar_23737;
	BIT_VEC cppVar_23738;
	BIT_VEC cppVar_23739;
	BIT_VEC cppVar_23740;
	BIT_VEC cppVar_23727;
	BIT_VEC cppVar_23741;
	bool cppVar_23742;
	BIT_VEC cppVar_23745;
	BIT_VEC cppVar_23746;
	BIT_VEC cppVar_23747;
	bool cppVar_23748;
	BIT_VEC cppVar_23749;
	BIT_VEC cppVar_23750;
	BIT_VEC cppVar_23751;
	BIT_VEC cppVar_23752;
	BIT_VEC cppVar_23753;
	BIT_VEC cppVar_23754;
	BIT_VEC cppVar_23755;
	BIT_VEC cppVar_23756;
	BIT_VEC cppVar_23757;
	BIT_VEC cppVar_23744;
	BIT_VEC cppVar_23758;
	bool cppVar_23759;
	BIT_VEC cppVar_23762;
	BIT_VEC cppVar_23763;
	BIT_VEC cppVar_23764;
	bool cppVar_23765;
	BIT_VEC cppVar_23766;
	BIT_VEC cppVar_23767;
	BIT_VEC cppVar_23768;
	BIT_VEC cppVar_23769;
	BIT_VEC cppVar_23770;
	BIT_VEC cppVar_23771;
	BIT_VEC cppVar_23772;
	BIT_VEC cppVar_23773;
	BIT_VEC cppVar_23774;
	BIT_VEC cppVar_23761;
	BIT_VEC cppVar_23775;
	bool cppVar_23776;
	BIT_VEC cppVar_23779;
	BIT_VEC cppVar_23780;
	BIT_VEC cppVar_23781;
	bool cppVar_23782;
	BIT_VEC cppVar_23783;
	BIT_VEC cppVar_23784;
	BIT_VEC cppVar_23785;
	BIT_VEC cppVar_23786;
	BIT_VEC cppVar_23787;
	BIT_VEC cppVar_23788;
	BIT_VEC cppVar_23789;
	BIT_VEC cppVar_23790;
	BIT_VEC cppVar_23791;
	BIT_VEC cppVar_23778;
	BIT_VEC cppVar_23792;
	bool cppVar_23793;
	BIT_VEC cppVar_23796;
	BIT_VEC cppVar_23797;
	BIT_VEC cppVar_23798;
	bool cppVar_23799;
	BIT_VEC cppVar_23800;
	BIT_VEC cppVar_23801;
	BIT_VEC cppVar_23802;
	BIT_VEC cppVar_23803;
	BIT_VEC cppVar_23804;
	BIT_VEC cppVar_23805;
	BIT_VEC cppVar_23806;
	BIT_VEC cppVar_23807;
	BIT_VEC cppVar_23808;
	BIT_VEC cppVar_23795;
	BIT_VEC cppVar_23809;
	bool cppVar_23810;
	BIT_VEC cppVar_23811;
	BIT_VEC cppVar_23794;
	BIT_VEC cppVar_23777;
	BIT_VEC cppVar_23760;
	BIT_VEC cppVar_23743;
	BIT_VEC cppVar_23726;
	BIT_VEC cppVar_23709;
	BIT_VEC cppVar_23692;
	BIT_VEC cppVar_23675;
	BIT_VEC cppVar_23658;
	BIT_VEC cppVar_23641;
	BIT_VEC cppVar_23624;
	BIT_VEC cppVar_23607;
	BIT_VEC cppVar_23590;
	BIT_VEC cppVar_23573;
	BIT_VEC cppVar_23556;
	BIT_VEC cppVar_23539;
	BIT_VEC cppVar_23522;
	BIT_VEC cppVar_23505;
	BIT_VEC cppVar_23488;
	BIT_VEC cppVar_23471;
	BIT_VEC cppVar_23454;
	BIT_VEC cppVar_23418;
	BIT_VEC cppVar_23812;
	BIT_VEC cppVar_23813;
	BIT_VEC cppVar_23814;
	BIT_VEC cppVar_23815;
	BIT_VEC cppVar_23816;
	BIT_VEC cppVar_23817;
	BIT_VEC cppVar_23818;
	BIT_VEC cppVar_23819;
	BIT_VEC cppVar_23820;
	BIT_VEC cppVar_23821;
	BIT_VEC cppVar_23822;
	BIT_VEC cppVar_23823;
	BIT_VEC cppVar_22998;
	BIT_VEC cppVar_23825;
	BIT_VEC cppVar_23826;
	bool cppVar_23827;
	BIT_VEC cppVar_23830;
	BIT_VEC cppVar_23831;
	BIT_VEC cppVar_23832;
	BIT_VEC cppVar_23833;
	BIT_VEC cppVar_23834;
	bool cppVar_23835;
	BIT_VEC cppVar_23836;
	BIT_VEC cppVar_23837;
	BIT_VEC cppVar_23838;
	BIT_VEC cppVar_23839;
	BIT_VEC cppVar_23840;
	BIT_VEC cppVar_23841;
	BIT_VEC cppVar_23842;
	BIT_VEC cppVar_23843;
	BIT_VEC cppVar_23844;
	BIT_VEC cppVar_23845;
	BIT_VEC cppVar_23846;
	BIT_VEC cppVar_23829;
	BIT_VEC cppVar_23847;
	bool cppVar_23848;
	BIT_VEC cppVar_23849;
	BIT_VEC cppVar_23850;
	BIT_VEC cppVar_23851;
	BIT_VEC cppVar_23852;
	BIT_VEC cppVar_23853;
	BIT_VEC cppVar_23854;
	BIT_VEC cppVar_23855;
	BIT_VEC cppVar_23858;
	BIT_VEC cppVar_23859;
	BIT_VEC cppVar_23860;
	bool cppVar_23861;
	BIT_VEC cppVar_23862;
	BIT_VEC cppVar_23863;
	BIT_VEC cppVar_23864;
	BIT_VEC cppVar_23865;
	BIT_VEC cppVar_23866;
	BIT_VEC cppVar_23867;
	BIT_VEC cppVar_23868;
	BIT_VEC cppVar_23869;
	BIT_VEC cppVar_23870;
	BIT_VEC cppVar_23857;
	BIT_VEC cppVar_23871;
	BIT_VEC cppVar_23872;
	bool cppVar_23873;
	BIT_VEC cppVar_23875;
	BIT_VEC cppVar_23876;
	BIT_VEC cppVar_23877;
	bool cppVar_23878;
	BIT_VEC cppVar_23879;
	BIT_VEC cppVar_23880;
	BIT_VEC cppVar_23881;
	BIT_VEC cppVar_23882;
	BIT_VEC cppVar_23883;
	BIT_VEC cppVar_23884;
	BIT_VEC cppVar_23885;
	BIT_VEC cppVar_23886;
	BIT_VEC cppVar_23887;
	BIT_VEC cppVar_23874;
	BIT_VEC cppVar_23888;
	BIT_VEC cppVar_23891;
	BIT_VEC cppVar_23892;
	BIT_VEC cppVar_23893;
	bool cppVar_23894;
	BIT_VEC cppVar_23895;
	BIT_VEC cppVar_23896;
	BIT_VEC cppVar_23897;
	BIT_VEC cppVar_23898;
	BIT_VEC cppVar_23899;
	BIT_VEC cppVar_23900;
	BIT_VEC cppVar_23901;
	BIT_VEC cppVar_23902;
	BIT_VEC cppVar_23903;
	BIT_VEC cppVar_23890;
	BIT_VEC cppVar_23904;
	bool cppVar_23905;
	BIT_VEC cppVar_23908;
	BIT_VEC cppVar_23909;
	BIT_VEC cppVar_23910;
	bool cppVar_23911;
	BIT_VEC cppVar_23912;
	BIT_VEC cppVar_23913;
	BIT_VEC cppVar_23914;
	BIT_VEC cppVar_23915;
	BIT_VEC cppVar_23916;
	BIT_VEC cppVar_23917;
	BIT_VEC cppVar_23918;
	BIT_VEC cppVar_23919;
	BIT_VEC cppVar_23920;
	BIT_VEC cppVar_23907;
	BIT_VEC cppVar_23921;
	bool cppVar_23922;
	BIT_VEC cppVar_23925;
	BIT_VEC cppVar_23926;
	BIT_VEC cppVar_23927;
	bool cppVar_23928;
	BIT_VEC cppVar_23929;
	BIT_VEC cppVar_23930;
	BIT_VEC cppVar_23931;
	BIT_VEC cppVar_23932;
	BIT_VEC cppVar_23933;
	BIT_VEC cppVar_23934;
	BIT_VEC cppVar_23935;
	BIT_VEC cppVar_23936;
	BIT_VEC cppVar_23937;
	BIT_VEC cppVar_23924;
	BIT_VEC cppVar_23938;
	bool cppVar_23939;
	BIT_VEC cppVar_23942;
	BIT_VEC cppVar_23943;
	BIT_VEC cppVar_23944;
	bool cppVar_23945;
	BIT_VEC cppVar_23946;
	BIT_VEC cppVar_23947;
	BIT_VEC cppVar_23948;
	BIT_VEC cppVar_23949;
	BIT_VEC cppVar_23950;
	BIT_VEC cppVar_23951;
	BIT_VEC cppVar_23952;
	BIT_VEC cppVar_23953;
	BIT_VEC cppVar_23954;
	BIT_VEC cppVar_23941;
	BIT_VEC cppVar_23955;
	bool cppVar_23956;
	BIT_VEC cppVar_23959;
	BIT_VEC cppVar_23960;
	BIT_VEC cppVar_23961;
	bool cppVar_23962;
	BIT_VEC cppVar_23963;
	BIT_VEC cppVar_23964;
	BIT_VEC cppVar_23965;
	BIT_VEC cppVar_23966;
	BIT_VEC cppVar_23967;
	BIT_VEC cppVar_23968;
	BIT_VEC cppVar_23969;
	BIT_VEC cppVar_23970;
	BIT_VEC cppVar_23971;
	BIT_VEC cppVar_23958;
	BIT_VEC cppVar_23972;
	bool cppVar_23973;
	BIT_VEC cppVar_23976;
	BIT_VEC cppVar_23977;
	BIT_VEC cppVar_23978;
	bool cppVar_23979;
	BIT_VEC cppVar_23980;
	BIT_VEC cppVar_23981;
	BIT_VEC cppVar_23982;
	BIT_VEC cppVar_23983;
	BIT_VEC cppVar_23984;
	BIT_VEC cppVar_23985;
	BIT_VEC cppVar_23986;
	BIT_VEC cppVar_23987;
	BIT_VEC cppVar_23988;
	BIT_VEC cppVar_23975;
	BIT_VEC cppVar_23989;
	bool cppVar_23990;
	BIT_VEC cppVar_23993;
	BIT_VEC cppVar_23994;
	BIT_VEC cppVar_23995;
	bool cppVar_23996;
	BIT_VEC cppVar_23997;
	BIT_VEC cppVar_23998;
	BIT_VEC cppVar_23999;
	BIT_VEC cppVar_24000;
	BIT_VEC cppVar_24001;
	BIT_VEC cppVar_24002;
	BIT_VEC cppVar_24003;
	BIT_VEC cppVar_24004;
	BIT_VEC cppVar_24005;
	BIT_VEC cppVar_23992;
	BIT_VEC cppVar_24006;
	bool cppVar_24007;
	BIT_VEC cppVar_24010;
	BIT_VEC cppVar_24011;
	BIT_VEC cppVar_24012;
	bool cppVar_24013;
	BIT_VEC cppVar_24014;
	BIT_VEC cppVar_24015;
	BIT_VEC cppVar_24016;
	BIT_VEC cppVar_24017;
	BIT_VEC cppVar_24018;
	BIT_VEC cppVar_24019;
	BIT_VEC cppVar_24020;
	BIT_VEC cppVar_24021;
	BIT_VEC cppVar_24022;
	BIT_VEC cppVar_24009;
	BIT_VEC cppVar_24023;
	bool cppVar_24024;
	BIT_VEC cppVar_24027;
	BIT_VEC cppVar_24028;
	BIT_VEC cppVar_24029;
	bool cppVar_24030;
	BIT_VEC cppVar_24031;
	BIT_VEC cppVar_24032;
	BIT_VEC cppVar_24033;
	BIT_VEC cppVar_24034;
	BIT_VEC cppVar_24035;
	BIT_VEC cppVar_24036;
	BIT_VEC cppVar_24037;
	BIT_VEC cppVar_24038;
	BIT_VEC cppVar_24039;
	BIT_VEC cppVar_24026;
	BIT_VEC cppVar_24040;
	bool cppVar_24041;
	BIT_VEC cppVar_24044;
	BIT_VEC cppVar_24045;
	BIT_VEC cppVar_24046;
	bool cppVar_24047;
	BIT_VEC cppVar_24048;
	BIT_VEC cppVar_24049;
	BIT_VEC cppVar_24050;
	BIT_VEC cppVar_24051;
	BIT_VEC cppVar_24052;
	BIT_VEC cppVar_24053;
	BIT_VEC cppVar_24054;
	BIT_VEC cppVar_24055;
	BIT_VEC cppVar_24056;
	BIT_VEC cppVar_24043;
	BIT_VEC cppVar_24057;
	bool cppVar_24058;
	BIT_VEC cppVar_24061;
	BIT_VEC cppVar_24062;
	BIT_VEC cppVar_24063;
	bool cppVar_24064;
	BIT_VEC cppVar_24065;
	BIT_VEC cppVar_24066;
	BIT_VEC cppVar_24067;
	BIT_VEC cppVar_24068;
	BIT_VEC cppVar_24069;
	BIT_VEC cppVar_24070;
	BIT_VEC cppVar_24071;
	BIT_VEC cppVar_24072;
	BIT_VEC cppVar_24073;
	BIT_VEC cppVar_24060;
	BIT_VEC cppVar_24074;
	bool cppVar_24075;
	BIT_VEC cppVar_24078;
	BIT_VEC cppVar_24079;
	BIT_VEC cppVar_24080;
	bool cppVar_24081;
	BIT_VEC cppVar_24082;
	BIT_VEC cppVar_24083;
	BIT_VEC cppVar_24084;
	BIT_VEC cppVar_24085;
	BIT_VEC cppVar_24086;
	BIT_VEC cppVar_24087;
	BIT_VEC cppVar_24088;
	BIT_VEC cppVar_24089;
	BIT_VEC cppVar_24090;
	BIT_VEC cppVar_24077;
	BIT_VEC cppVar_24091;
	bool cppVar_24092;
	BIT_VEC cppVar_24095;
	BIT_VEC cppVar_24096;
	BIT_VEC cppVar_24097;
	bool cppVar_24098;
	BIT_VEC cppVar_24099;
	BIT_VEC cppVar_24100;
	BIT_VEC cppVar_24101;
	BIT_VEC cppVar_24102;
	BIT_VEC cppVar_24103;
	BIT_VEC cppVar_24104;
	BIT_VEC cppVar_24105;
	BIT_VEC cppVar_24106;
	BIT_VEC cppVar_24107;
	BIT_VEC cppVar_24094;
	BIT_VEC cppVar_24108;
	bool cppVar_24109;
	BIT_VEC cppVar_24112;
	BIT_VEC cppVar_24113;
	BIT_VEC cppVar_24114;
	bool cppVar_24115;
	BIT_VEC cppVar_24116;
	BIT_VEC cppVar_24117;
	BIT_VEC cppVar_24118;
	BIT_VEC cppVar_24119;
	BIT_VEC cppVar_24120;
	BIT_VEC cppVar_24121;
	BIT_VEC cppVar_24122;
	BIT_VEC cppVar_24123;
	BIT_VEC cppVar_24124;
	BIT_VEC cppVar_24111;
	BIT_VEC cppVar_24125;
	bool cppVar_24126;
	BIT_VEC cppVar_24129;
	BIT_VEC cppVar_24130;
	BIT_VEC cppVar_24131;
	bool cppVar_24132;
	BIT_VEC cppVar_24133;
	BIT_VEC cppVar_24134;
	BIT_VEC cppVar_24135;
	BIT_VEC cppVar_24136;
	BIT_VEC cppVar_24137;
	BIT_VEC cppVar_24138;
	BIT_VEC cppVar_24139;
	BIT_VEC cppVar_24140;
	BIT_VEC cppVar_24141;
	BIT_VEC cppVar_24128;
	BIT_VEC cppVar_24142;
	bool cppVar_24143;
	BIT_VEC cppVar_24146;
	BIT_VEC cppVar_24147;
	BIT_VEC cppVar_24148;
	bool cppVar_24149;
	BIT_VEC cppVar_24150;
	BIT_VEC cppVar_24151;
	BIT_VEC cppVar_24152;
	BIT_VEC cppVar_24153;
	BIT_VEC cppVar_24154;
	BIT_VEC cppVar_24155;
	BIT_VEC cppVar_24156;
	BIT_VEC cppVar_24157;
	BIT_VEC cppVar_24158;
	BIT_VEC cppVar_24145;
	BIT_VEC cppVar_24159;
	bool cppVar_24160;
	BIT_VEC cppVar_24163;
	BIT_VEC cppVar_24164;
	BIT_VEC cppVar_24165;
	bool cppVar_24166;
	BIT_VEC cppVar_24167;
	BIT_VEC cppVar_24168;
	BIT_VEC cppVar_24169;
	BIT_VEC cppVar_24170;
	BIT_VEC cppVar_24171;
	BIT_VEC cppVar_24172;
	BIT_VEC cppVar_24173;
	BIT_VEC cppVar_24174;
	BIT_VEC cppVar_24175;
	BIT_VEC cppVar_24162;
	BIT_VEC cppVar_24176;
	bool cppVar_24177;
	BIT_VEC cppVar_24180;
	BIT_VEC cppVar_24181;
	BIT_VEC cppVar_24182;
	bool cppVar_24183;
	BIT_VEC cppVar_24184;
	BIT_VEC cppVar_24185;
	BIT_VEC cppVar_24186;
	BIT_VEC cppVar_24187;
	BIT_VEC cppVar_24188;
	BIT_VEC cppVar_24189;
	BIT_VEC cppVar_24190;
	BIT_VEC cppVar_24191;
	BIT_VEC cppVar_24192;
	BIT_VEC cppVar_24179;
	BIT_VEC cppVar_24193;
	bool cppVar_24194;
	BIT_VEC cppVar_24197;
	BIT_VEC cppVar_24198;
	BIT_VEC cppVar_24199;
	bool cppVar_24200;
	BIT_VEC cppVar_24201;
	BIT_VEC cppVar_24202;
	BIT_VEC cppVar_24203;
	BIT_VEC cppVar_24204;
	BIT_VEC cppVar_24205;
	BIT_VEC cppVar_24206;
	BIT_VEC cppVar_24207;
	BIT_VEC cppVar_24208;
	BIT_VEC cppVar_24209;
	BIT_VEC cppVar_24196;
	BIT_VEC cppVar_24210;
	bool cppVar_24211;
	BIT_VEC cppVar_24214;
	BIT_VEC cppVar_24215;
	BIT_VEC cppVar_24216;
	bool cppVar_24217;
	BIT_VEC cppVar_24218;
	BIT_VEC cppVar_24219;
	BIT_VEC cppVar_24220;
	BIT_VEC cppVar_24221;
	BIT_VEC cppVar_24222;
	BIT_VEC cppVar_24223;
	BIT_VEC cppVar_24224;
	BIT_VEC cppVar_24225;
	BIT_VEC cppVar_24226;
	BIT_VEC cppVar_24213;
	BIT_VEC cppVar_24227;
	bool cppVar_24228;
	BIT_VEC cppVar_24231;
	BIT_VEC cppVar_24232;
	BIT_VEC cppVar_24233;
	bool cppVar_24234;
	BIT_VEC cppVar_24235;
	BIT_VEC cppVar_24236;
	BIT_VEC cppVar_24237;
	BIT_VEC cppVar_24238;
	BIT_VEC cppVar_24239;
	BIT_VEC cppVar_24240;
	BIT_VEC cppVar_24241;
	BIT_VEC cppVar_24242;
	BIT_VEC cppVar_24243;
	BIT_VEC cppVar_24230;
	BIT_VEC cppVar_24244;
	bool cppVar_24245;
	BIT_VEC cppVar_24246;
	BIT_VEC cppVar_24229;
	BIT_VEC cppVar_24212;
	BIT_VEC cppVar_24195;
	BIT_VEC cppVar_24178;
	BIT_VEC cppVar_24161;
	BIT_VEC cppVar_24144;
	BIT_VEC cppVar_24127;
	BIT_VEC cppVar_24110;
	BIT_VEC cppVar_24093;
	BIT_VEC cppVar_24076;
	BIT_VEC cppVar_24059;
	BIT_VEC cppVar_24042;
	BIT_VEC cppVar_24025;
	BIT_VEC cppVar_24008;
	BIT_VEC cppVar_23991;
	BIT_VEC cppVar_23974;
	BIT_VEC cppVar_23957;
	BIT_VEC cppVar_23940;
	BIT_VEC cppVar_23923;
	BIT_VEC cppVar_23906;
	BIT_VEC cppVar_23889;
	BIT_VEC cppVar_23856;
	BIT_VEC cppVar_24247;
	BIT_VEC cppVar_24248;
	BIT_VEC cppVar_24249;
	BIT_VEC cppVar_24250;
	BIT_VEC cppVar_24251;
	BIT_VEC cppVar_24252;
	BIT_VEC cppVar_24253;
	BIT_VEC cppVar_24254;
	BIT_VEC cppVar_24255;
	BIT_VEC cppVar_23828;
	BIT_VEC cppVar_24257;
	BIT_VEC cppVar_24258;
	bool cppVar_24259;
	BIT_VEC cppVar_24261;
	BIT_VEC cppVar_24262;
	BIT_VEC cppVar_24263;
	BIT_VEC cppVar_24264;
	bool cppVar_24265;
	BIT_VEC cppVar_24267;
	BIT_VEC cppVar_24268;
	BIT_VEC cppVar_24269;
	BIT_VEC cppVar_24270;
	BIT_VEC cppVar_24271;
	BIT_VEC cppVar_24272;
	BIT_VEC cppVar_24273;
	bool cppVar_24274;
	BIT_VEC cppVar_24275;
	BIT_VEC cppVar_24276;
	BIT_VEC cppVar_24277;
	BIT_VEC cppVar_24278;
	BIT_VEC cppVar_24280;
	BIT_VEC cppVar_24281;
	BIT_VEC cppVar_24282;
	BIT_VEC cppVar_24283;
	bool cppVar_24284;
	BIT_VEC cppVar_24286;
	BIT_VEC cppVar_24287;
	BIT_VEC cppVar_24288;
	BIT_VEC cppVar_24289;
	bool cppVar_24290;
	BIT_VEC cppVar_24292;
	BIT_VEC cppVar_24293;
	BIT_VEC cppVar_24294;
	BIT_VEC cppVar_24295;
	bool cppVar_24296;
	BIT_VEC cppVar_24298;
	BIT_VEC cppVar_24299;
	BIT_VEC cppVar_24300;
	BIT_VEC cppVar_24301;
	bool cppVar_24302;
	BIT_VEC cppVar_24304;
	BIT_VEC cppVar_24305;
	BIT_VEC cppVar_24306;
	BIT_VEC cppVar_24307;
	bool cppVar_24308;
	BIT_VEC cppVar_24310;
	BIT_VEC cppVar_24311;
	BIT_VEC cppVar_24312;
	BIT_VEC cppVar_24313;
	bool cppVar_24314;
	BIT_VEC cppVar_24316;
	BIT_VEC cppVar_24317;
	BIT_VEC cppVar_24318;
	BIT_VEC cppVar_24319;
	bool cppVar_24320;
	BIT_VEC cppVar_24322;
	BIT_VEC cppVar_24323;
	BIT_VEC cppVar_24324;
	BIT_VEC cppVar_24325;
	bool cppVar_24326;
	BIT_VEC cppVar_24328;
	BIT_VEC cppVar_24329;
	BIT_VEC cppVar_24330;
	BIT_VEC cppVar_24331;
	bool cppVar_24332;
	BIT_VEC cppVar_24334;
	BIT_VEC cppVar_24335;
	BIT_VEC cppVar_24336;
	BIT_VEC cppVar_24337;
	bool cppVar_24338;
	BIT_VEC cppVar_24340;
	BIT_VEC cppVar_24341;
	BIT_VEC cppVar_24342;
	BIT_VEC cppVar_24343;
	bool cppVar_24344;
	BIT_VEC cppVar_24346;
	BIT_VEC cppVar_24347;
	BIT_VEC cppVar_24348;
	BIT_VEC cppVar_24349;
	bool cppVar_24350;
	BIT_VEC cppVar_24352;
	BIT_VEC cppVar_24353;
	BIT_VEC cppVar_24354;
	BIT_VEC cppVar_24355;
	bool cppVar_24356;
	BIT_VEC cppVar_24358;
	BIT_VEC cppVar_24359;
	BIT_VEC cppVar_24360;
	BIT_VEC cppVar_24361;
	bool cppVar_24362;
	BIT_VEC cppVar_24364;
	BIT_VEC cppVar_24365;
	BIT_VEC cppVar_24366;
	BIT_VEC cppVar_24367;
	bool cppVar_24368;
	BIT_VEC cppVar_24370;
	BIT_VEC cppVar_24371;
	BIT_VEC cppVar_24372;
	BIT_VEC cppVar_24373;
	bool cppVar_24374;
	BIT_VEC cppVar_24376;
	BIT_VEC cppVar_24377;
	BIT_VEC cppVar_24378;
	BIT_VEC cppVar_24379;
	bool cppVar_24380;
	BIT_VEC cppVar_24382;
	BIT_VEC cppVar_24383;
	BIT_VEC cppVar_24384;
	BIT_VEC cppVar_24385;
	bool cppVar_24386;
	BIT_VEC cppVar_24388;
	BIT_VEC cppVar_24389;
	BIT_VEC cppVar_24390;
	BIT_VEC cppVar_24391;
	bool cppVar_24392;
	BIT_VEC cppVar_24394;
	BIT_VEC cppVar_24395;
	BIT_VEC cppVar_24396;
	BIT_VEC cppVar_24397;
	bool cppVar_24398;
	BIT_VEC cppVar_24400;
	BIT_VEC cppVar_24401;
	BIT_VEC cppVar_24402;
	BIT_VEC cppVar_24403;
	bool cppVar_24404;
	BIT_VEC cppVar_24405;
	BIT_VEC cppVar_24399;
	BIT_VEC cppVar_24393;
	BIT_VEC cppVar_24387;
	BIT_VEC cppVar_24381;
	BIT_VEC cppVar_24375;
	BIT_VEC cppVar_24369;
	BIT_VEC cppVar_24363;
	BIT_VEC cppVar_24357;
	BIT_VEC cppVar_24351;
	BIT_VEC cppVar_24345;
	BIT_VEC cppVar_24339;
	BIT_VEC cppVar_24333;
	BIT_VEC cppVar_24327;
	BIT_VEC cppVar_24321;
	BIT_VEC cppVar_24315;
	BIT_VEC cppVar_24309;
	BIT_VEC cppVar_24303;
	BIT_VEC cppVar_24297;
	BIT_VEC cppVar_24291;
	BIT_VEC cppVar_24285;
	BIT_VEC cppVar_24279;
	BIT_VEC cppVar_24266;
	BIT_VEC cppVar_24260;
	BIT_VEC cppVar_24407;
	BIT_VEC cppVar_24408;
	bool cppVar_24409;
	BIT_VEC cppVar_24411;
	BIT_VEC cppVar_24412;
	BIT_VEC cppVar_24413;
	BIT_VEC cppVar_24414;
	bool cppVar_24415;
	BIT_VEC cppVar_24417;
	BIT_VEC cppVar_24418;
	BIT_VEC cppVar_24419;
	BIT_VEC cppVar_24420;
	BIT_VEC cppVar_24421;
	BIT_VEC cppVar_24422;
	BIT_VEC cppVar_24423;
	bool cppVar_24424;
	BIT_VEC cppVar_24425;
	BIT_VEC cppVar_24426;
	BIT_VEC cppVar_24427;
	BIT_VEC cppVar_24428;
	BIT_VEC cppVar_24430;
	BIT_VEC cppVar_24431;
	BIT_VEC cppVar_24432;
	BIT_VEC cppVar_24433;
	bool cppVar_24434;
	BIT_VEC cppVar_24436;
	BIT_VEC cppVar_24437;
	BIT_VEC cppVar_24438;
	BIT_VEC cppVar_24439;
	bool cppVar_24440;
	BIT_VEC cppVar_24442;
	BIT_VEC cppVar_24443;
	BIT_VEC cppVar_24444;
	BIT_VEC cppVar_24445;
	bool cppVar_24446;
	BIT_VEC cppVar_24448;
	BIT_VEC cppVar_24449;
	BIT_VEC cppVar_24450;
	BIT_VEC cppVar_24451;
	bool cppVar_24452;
	BIT_VEC cppVar_24454;
	BIT_VEC cppVar_24455;
	BIT_VEC cppVar_24456;
	BIT_VEC cppVar_24457;
	bool cppVar_24458;
	BIT_VEC cppVar_24460;
	BIT_VEC cppVar_24461;
	BIT_VEC cppVar_24462;
	BIT_VEC cppVar_24463;
	bool cppVar_24464;
	BIT_VEC cppVar_24466;
	BIT_VEC cppVar_24467;
	BIT_VEC cppVar_24468;
	BIT_VEC cppVar_24469;
	bool cppVar_24470;
	BIT_VEC cppVar_24472;
	BIT_VEC cppVar_24473;
	BIT_VEC cppVar_24474;
	BIT_VEC cppVar_24475;
	bool cppVar_24476;
	BIT_VEC cppVar_24478;
	BIT_VEC cppVar_24479;
	BIT_VEC cppVar_24480;
	BIT_VEC cppVar_24481;
	bool cppVar_24482;
	BIT_VEC cppVar_24484;
	BIT_VEC cppVar_24485;
	BIT_VEC cppVar_24486;
	BIT_VEC cppVar_24487;
	bool cppVar_24488;
	BIT_VEC cppVar_24490;
	BIT_VEC cppVar_24491;
	BIT_VEC cppVar_24492;
	BIT_VEC cppVar_24493;
	bool cppVar_24494;
	BIT_VEC cppVar_24496;
	BIT_VEC cppVar_24497;
	BIT_VEC cppVar_24498;
	BIT_VEC cppVar_24499;
	bool cppVar_24500;
	BIT_VEC cppVar_24502;
	BIT_VEC cppVar_24503;
	BIT_VEC cppVar_24504;
	BIT_VEC cppVar_24505;
	bool cppVar_24506;
	BIT_VEC cppVar_24508;
	BIT_VEC cppVar_24509;
	BIT_VEC cppVar_24510;
	BIT_VEC cppVar_24511;
	bool cppVar_24512;
	BIT_VEC cppVar_24514;
	BIT_VEC cppVar_24515;
	BIT_VEC cppVar_24516;
	BIT_VEC cppVar_24517;
	bool cppVar_24518;
	BIT_VEC cppVar_24520;
	BIT_VEC cppVar_24521;
	BIT_VEC cppVar_24522;
	BIT_VEC cppVar_24523;
	bool cppVar_24524;
	BIT_VEC cppVar_24526;
	BIT_VEC cppVar_24527;
	BIT_VEC cppVar_24528;
	BIT_VEC cppVar_24529;
	bool cppVar_24530;
	BIT_VEC cppVar_24532;
	BIT_VEC cppVar_24533;
	BIT_VEC cppVar_24534;
	BIT_VEC cppVar_24535;
	bool cppVar_24536;
	BIT_VEC cppVar_24538;
	BIT_VEC cppVar_24539;
	BIT_VEC cppVar_24540;
	BIT_VEC cppVar_24541;
	bool cppVar_24542;
	BIT_VEC cppVar_24544;
	BIT_VEC cppVar_24545;
	BIT_VEC cppVar_24546;
	BIT_VEC cppVar_24547;
	bool cppVar_24548;
	BIT_VEC cppVar_24550;
	BIT_VEC cppVar_24551;
	BIT_VEC cppVar_24552;
	BIT_VEC cppVar_24553;
	bool cppVar_24554;
	BIT_VEC cppVar_24555;
	BIT_VEC cppVar_24549;
	BIT_VEC cppVar_24543;
	BIT_VEC cppVar_24537;
	BIT_VEC cppVar_24531;
	BIT_VEC cppVar_24525;
	BIT_VEC cppVar_24519;
	BIT_VEC cppVar_24513;
	BIT_VEC cppVar_24507;
	BIT_VEC cppVar_24501;
	BIT_VEC cppVar_24495;
	BIT_VEC cppVar_24489;
	BIT_VEC cppVar_24483;
	BIT_VEC cppVar_24477;
	BIT_VEC cppVar_24471;
	BIT_VEC cppVar_24465;
	BIT_VEC cppVar_24459;
	BIT_VEC cppVar_24453;
	BIT_VEC cppVar_24447;
	BIT_VEC cppVar_24441;
	BIT_VEC cppVar_24435;
	BIT_VEC cppVar_24429;
	BIT_VEC cppVar_24416;
	BIT_VEC cppVar_24410;
	BIT_VEC cppVar_24557;
	BIT_VEC cppVar_24558;
	bool cppVar_24559;
	BIT_VEC cppVar_24561;
	BIT_VEC cppVar_24562;
	BIT_VEC cppVar_24563;
	BIT_VEC cppVar_24564;
	bool cppVar_24565;
	BIT_VEC cppVar_24567;
	BIT_VEC cppVar_24568;
	BIT_VEC cppVar_24569;
	BIT_VEC cppVar_24570;
	BIT_VEC cppVar_24571;
	BIT_VEC cppVar_24572;
	BIT_VEC cppVar_24573;
	bool cppVar_24574;
	BIT_VEC cppVar_24575;
	BIT_VEC cppVar_24576;
	BIT_VEC cppVar_24577;
	BIT_VEC cppVar_24578;
	BIT_VEC cppVar_24580;
	BIT_VEC cppVar_24581;
	BIT_VEC cppVar_24582;
	BIT_VEC cppVar_24583;
	bool cppVar_24584;
	BIT_VEC cppVar_24586;
	BIT_VEC cppVar_24587;
	BIT_VEC cppVar_24588;
	BIT_VEC cppVar_24589;
	bool cppVar_24590;
	BIT_VEC cppVar_24592;
	BIT_VEC cppVar_24593;
	BIT_VEC cppVar_24594;
	BIT_VEC cppVar_24595;
	bool cppVar_24596;
	BIT_VEC cppVar_24598;
	BIT_VEC cppVar_24599;
	BIT_VEC cppVar_24600;
	BIT_VEC cppVar_24601;
	bool cppVar_24602;
	BIT_VEC cppVar_24604;
	BIT_VEC cppVar_24605;
	BIT_VEC cppVar_24606;
	BIT_VEC cppVar_24607;
	bool cppVar_24608;
	BIT_VEC cppVar_24610;
	BIT_VEC cppVar_24611;
	BIT_VEC cppVar_24612;
	BIT_VEC cppVar_24613;
	bool cppVar_24614;
	BIT_VEC cppVar_24616;
	BIT_VEC cppVar_24617;
	BIT_VEC cppVar_24618;
	BIT_VEC cppVar_24619;
	bool cppVar_24620;
	BIT_VEC cppVar_24622;
	BIT_VEC cppVar_24623;
	BIT_VEC cppVar_24624;
	BIT_VEC cppVar_24625;
	bool cppVar_24626;
	BIT_VEC cppVar_24628;
	BIT_VEC cppVar_24629;
	BIT_VEC cppVar_24630;
	BIT_VEC cppVar_24631;
	bool cppVar_24632;
	BIT_VEC cppVar_24634;
	BIT_VEC cppVar_24635;
	BIT_VEC cppVar_24636;
	BIT_VEC cppVar_24637;
	bool cppVar_24638;
	BIT_VEC cppVar_24640;
	BIT_VEC cppVar_24641;
	BIT_VEC cppVar_24642;
	BIT_VEC cppVar_24643;
	bool cppVar_24644;
	BIT_VEC cppVar_24646;
	BIT_VEC cppVar_24647;
	BIT_VEC cppVar_24648;
	BIT_VEC cppVar_24649;
	bool cppVar_24650;
	BIT_VEC cppVar_24652;
	BIT_VEC cppVar_24653;
	BIT_VEC cppVar_24654;
	BIT_VEC cppVar_24655;
	bool cppVar_24656;
	BIT_VEC cppVar_24658;
	BIT_VEC cppVar_24659;
	BIT_VEC cppVar_24660;
	BIT_VEC cppVar_24661;
	bool cppVar_24662;
	BIT_VEC cppVar_24664;
	BIT_VEC cppVar_24665;
	BIT_VEC cppVar_24666;
	BIT_VEC cppVar_24667;
	bool cppVar_24668;
	BIT_VEC cppVar_24670;
	BIT_VEC cppVar_24671;
	BIT_VEC cppVar_24672;
	BIT_VEC cppVar_24673;
	bool cppVar_24674;
	BIT_VEC cppVar_24676;
	BIT_VEC cppVar_24677;
	BIT_VEC cppVar_24678;
	BIT_VEC cppVar_24679;
	bool cppVar_24680;
	BIT_VEC cppVar_24682;
	BIT_VEC cppVar_24683;
	BIT_VEC cppVar_24684;
	BIT_VEC cppVar_24685;
	bool cppVar_24686;
	BIT_VEC cppVar_24688;
	BIT_VEC cppVar_24689;
	BIT_VEC cppVar_24690;
	BIT_VEC cppVar_24691;
	bool cppVar_24692;
	BIT_VEC cppVar_24694;
	BIT_VEC cppVar_24695;
	BIT_VEC cppVar_24696;
	BIT_VEC cppVar_24697;
	bool cppVar_24698;
	BIT_VEC cppVar_24700;
	BIT_VEC cppVar_24701;
	BIT_VEC cppVar_24702;
	BIT_VEC cppVar_24703;
	bool cppVar_24704;
	BIT_VEC cppVar_24705;
	BIT_VEC cppVar_24699;
	BIT_VEC cppVar_24693;
	BIT_VEC cppVar_24687;
	BIT_VEC cppVar_24681;
	BIT_VEC cppVar_24675;
	BIT_VEC cppVar_24669;
	BIT_VEC cppVar_24663;
	BIT_VEC cppVar_24657;
	BIT_VEC cppVar_24651;
	BIT_VEC cppVar_24645;
	BIT_VEC cppVar_24639;
	BIT_VEC cppVar_24633;
	BIT_VEC cppVar_24627;
	BIT_VEC cppVar_24621;
	BIT_VEC cppVar_24615;
	BIT_VEC cppVar_24609;
	BIT_VEC cppVar_24603;
	BIT_VEC cppVar_24597;
	BIT_VEC cppVar_24591;
	BIT_VEC cppVar_24585;
	BIT_VEC cppVar_24579;
	BIT_VEC cppVar_24566;
	BIT_VEC cppVar_24560;
	BIT_VEC cppVar_24707;
	BIT_VEC cppVar_24708;
	bool cppVar_24709;
	BIT_VEC cppVar_24711;
	BIT_VEC cppVar_24712;
	BIT_VEC cppVar_24713;
	BIT_VEC cppVar_24714;
	bool cppVar_24715;
	BIT_VEC cppVar_24717;
	BIT_VEC cppVar_24718;
	BIT_VEC cppVar_24719;
	BIT_VEC cppVar_24720;
	BIT_VEC cppVar_24721;
	BIT_VEC cppVar_24722;
	BIT_VEC cppVar_24723;
	bool cppVar_24724;
	BIT_VEC cppVar_24725;
	BIT_VEC cppVar_24726;
	BIT_VEC cppVar_24727;
	BIT_VEC cppVar_24728;
	BIT_VEC cppVar_24730;
	BIT_VEC cppVar_24731;
	BIT_VEC cppVar_24732;
	BIT_VEC cppVar_24733;
	bool cppVar_24734;
	BIT_VEC cppVar_24736;
	BIT_VEC cppVar_24737;
	BIT_VEC cppVar_24738;
	BIT_VEC cppVar_24739;
	bool cppVar_24740;
	BIT_VEC cppVar_24742;
	BIT_VEC cppVar_24743;
	BIT_VEC cppVar_24744;
	BIT_VEC cppVar_24745;
	bool cppVar_24746;
	BIT_VEC cppVar_24748;
	BIT_VEC cppVar_24749;
	BIT_VEC cppVar_24750;
	BIT_VEC cppVar_24751;
	bool cppVar_24752;
	BIT_VEC cppVar_24754;
	BIT_VEC cppVar_24755;
	BIT_VEC cppVar_24756;
	BIT_VEC cppVar_24757;
	bool cppVar_24758;
	BIT_VEC cppVar_24760;
	BIT_VEC cppVar_24761;
	BIT_VEC cppVar_24762;
	BIT_VEC cppVar_24763;
	bool cppVar_24764;
	BIT_VEC cppVar_24766;
	BIT_VEC cppVar_24767;
	BIT_VEC cppVar_24768;
	BIT_VEC cppVar_24769;
	bool cppVar_24770;
	BIT_VEC cppVar_24772;
	BIT_VEC cppVar_24773;
	BIT_VEC cppVar_24774;
	BIT_VEC cppVar_24775;
	bool cppVar_24776;
	BIT_VEC cppVar_24778;
	BIT_VEC cppVar_24779;
	BIT_VEC cppVar_24780;
	BIT_VEC cppVar_24781;
	bool cppVar_24782;
	BIT_VEC cppVar_24784;
	BIT_VEC cppVar_24785;
	BIT_VEC cppVar_24786;
	BIT_VEC cppVar_24787;
	bool cppVar_24788;
	BIT_VEC cppVar_24790;
	BIT_VEC cppVar_24791;
	BIT_VEC cppVar_24792;
	BIT_VEC cppVar_24793;
	bool cppVar_24794;
	BIT_VEC cppVar_24796;
	BIT_VEC cppVar_24797;
	BIT_VEC cppVar_24798;
	BIT_VEC cppVar_24799;
	bool cppVar_24800;
	BIT_VEC cppVar_24802;
	BIT_VEC cppVar_24803;
	BIT_VEC cppVar_24804;
	BIT_VEC cppVar_24805;
	bool cppVar_24806;
	BIT_VEC cppVar_24808;
	BIT_VEC cppVar_24809;
	BIT_VEC cppVar_24810;
	BIT_VEC cppVar_24811;
	bool cppVar_24812;
	BIT_VEC cppVar_24814;
	BIT_VEC cppVar_24815;
	BIT_VEC cppVar_24816;
	BIT_VEC cppVar_24817;
	bool cppVar_24818;
	BIT_VEC cppVar_24820;
	BIT_VEC cppVar_24821;
	BIT_VEC cppVar_24822;
	BIT_VEC cppVar_24823;
	bool cppVar_24824;
	BIT_VEC cppVar_24826;
	BIT_VEC cppVar_24827;
	BIT_VEC cppVar_24828;
	BIT_VEC cppVar_24829;
	bool cppVar_24830;
	BIT_VEC cppVar_24832;
	BIT_VEC cppVar_24833;
	BIT_VEC cppVar_24834;
	BIT_VEC cppVar_24835;
	bool cppVar_24836;
	BIT_VEC cppVar_24838;
	BIT_VEC cppVar_24839;
	BIT_VEC cppVar_24840;
	BIT_VEC cppVar_24841;
	bool cppVar_24842;
	BIT_VEC cppVar_24844;
	BIT_VEC cppVar_24845;
	BIT_VEC cppVar_24846;
	BIT_VEC cppVar_24847;
	bool cppVar_24848;
	BIT_VEC cppVar_24850;
	BIT_VEC cppVar_24851;
	BIT_VEC cppVar_24852;
	BIT_VEC cppVar_24853;
	bool cppVar_24854;
	BIT_VEC cppVar_24855;
	BIT_VEC cppVar_24849;
	BIT_VEC cppVar_24843;
	BIT_VEC cppVar_24837;
	BIT_VEC cppVar_24831;
	BIT_VEC cppVar_24825;
	BIT_VEC cppVar_24819;
	BIT_VEC cppVar_24813;
	BIT_VEC cppVar_24807;
	BIT_VEC cppVar_24801;
	BIT_VEC cppVar_24795;
	BIT_VEC cppVar_24789;
	BIT_VEC cppVar_24783;
	BIT_VEC cppVar_24777;
	BIT_VEC cppVar_24771;
	BIT_VEC cppVar_24765;
	BIT_VEC cppVar_24759;
	BIT_VEC cppVar_24753;
	BIT_VEC cppVar_24747;
	BIT_VEC cppVar_24741;
	BIT_VEC cppVar_24735;
	BIT_VEC cppVar_24729;
	BIT_VEC cppVar_24716;
	BIT_VEC cppVar_24710;
	BIT_VEC cppVar_24857;
	BIT_VEC cppVar_24858;
	bool cppVar_24859;
	BIT_VEC cppVar_24861;
	BIT_VEC cppVar_24862;
	BIT_VEC cppVar_24863;
	BIT_VEC cppVar_24864;
	bool cppVar_24865;
	BIT_VEC cppVar_24867;
	BIT_VEC cppVar_24868;
	BIT_VEC cppVar_24869;
	BIT_VEC cppVar_24870;
	BIT_VEC cppVar_24871;
	BIT_VEC cppVar_24872;
	BIT_VEC cppVar_24873;
	bool cppVar_24874;
	BIT_VEC cppVar_24875;
	BIT_VEC cppVar_24876;
	BIT_VEC cppVar_24877;
	BIT_VEC cppVar_24878;
	BIT_VEC cppVar_24880;
	BIT_VEC cppVar_24881;
	BIT_VEC cppVar_24882;
	BIT_VEC cppVar_24883;
	bool cppVar_24884;
	BIT_VEC cppVar_24886;
	BIT_VEC cppVar_24887;
	BIT_VEC cppVar_24888;
	BIT_VEC cppVar_24889;
	bool cppVar_24890;
	BIT_VEC cppVar_24892;
	BIT_VEC cppVar_24893;
	BIT_VEC cppVar_24894;
	BIT_VEC cppVar_24895;
	bool cppVar_24896;
	BIT_VEC cppVar_24898;
	BIT_VEC cppVar_24899;
	BIT_VEC cppVar_24900;
	BIT_VEC cppVar_24901;
	bool cppVar_24902;
	BIT_VEC cppVar_24904;
	BIT_VEC cppVar_24905;
	BIT_VEC cppVar_24906;
	BIT_VEC cppVar_24907;
	bool cppVar_24908;
	BIT_VEC cppVar_24910;
	BIT_VEC cppVar_24911;
	BIT_VEC cppVar_24912;
	BIT_VEC cppVar_24913;
	bool cppVar_24914;
	BIT_VEC cppVar_24916;
	BIT_VEC cppVar_24917;
	BIT_VEC cppVar_24918;
	BIT_VEC cppVar_24919;
	bool cppVar_24920;
	BIT_VEC cppVar_24922;
	BIT_VEC cppVar_24923;
	BIT_VEC cppVar_24924;
	BIT_VEC cppVar_24925;
	bool cppVar_24926;
	BIT_VEC cppVar_24928;
	BIT_VEC cppVar_24929;
	BIT_VEC cppVar_24930;
	BIT_VEC cppVar_24931;
	bool cppVar_24932;
	BIT_VEC cppVar_24934;
	BIT_VEC cppVar_24935;
	BIT_VEC cppVar_24936;
	BIT_VEC cppVar_24937;
	bool cppVar_24938;
	BIT_VEC cppVar_24940;
	BIT_VEC cppVar_24941;
	BIT_VEC cppVar_24942;
	BIT_VEC cppVar_24943;
	bool cppVar_24944;
	BIT_VEC cppVar_24946;
	BIT_VEC cppVar_24947;
	BIT_VEC cppVar_24948;
	BIT_VEC cppVar_24949;
	bool cppVar_24950;
	BIT_VEC cppVar_24952;
	BIT_VEC cppVar_24953;
	BIT_VEC cppVar_24954;
	BIT_VEC cppVar_24955;
	bool cppVar_24956;
	BIT_VEC cppVar_24958;
	BIT_VEC cppVar_24959;
	BIT_VEC cppVar_24960;
	BIT_VEC cppVar_24961;
	bool cppVar_24962;
	BIT_VEC cppVar_24964;
	BIT_VEC cppVar_24965;
	BIT_VEC cppVar_24966;
	BIT_VEC cppVar_24967;
	bool cppVar_24968;
	BIT_VEC cppVar_24970;
	BIT_VEC cppVar_24971;
	BIT_VEC cppVar_24972;
	BIT_VEC cppVar_24973;
	bool cppVar_24974;
	BIT_VEC cppVar_24976;
	BIT_VEC cppVar_24977;
	BIT_VEC cppVar_24978;
	BIT_VEC cppVar_24979;
	bool cppVar_24980;
	BIT_VEC cppVar_24982;
	BIT_VEC cppVar_24983;
	BIT_VEC cppVar_24984;
	BIT_VEC cppVar_24985;
	bool cppVar_24986;
	BIT_VEC cppVar_24988;
	BIT_VEC cppVar_24989;
	BIT_VEC cppVar_24990;
	BIT_VEC cppVar_24991;
	bool cppVar_24992;
	BIT_VEC cppVar_24994;
	BIT_VEC cppVar_24995;
	BIT_VEC cppVar_24996;
	BIT_VEC cppVar_24997;
	bool cppVar_24998;
	BIT_VEC cppVar_25000;
	BIT_VEC cppVar_25001;
	BIT_VEC cppVar_25002;
	BIT_VEC cppVar_25003;
	bool cppVar_25004;
	BIT_VEC cppVar_25005;
	BIT_VEC cppVar_24999;
	BIT_VEC cppVar_24993;
	BIT_VEC cppVar_24987;
	BIT_VEC cppVar_24981;
	BIT_VEC cppVar_24975;
	BIT_VEC cppVar_24969;
	BIT_VEC cppVar_24963;
	BIT_VEC cppVar_24957;
	BIT_VEC cppVar_24951;
	BIT_VEC cppVar_24945;
	BIT_VEC cppVar_24939;
	BIT_VEC cppVar_24933;
	BIT_VEC cppVar_24927;
	BIT_VEC cppVar_24921;
	BIT_VEC cppVar_24915;
	BIT_VEC cppVar_24909;
	BIT_VEC cppVar_24903;
	BIT_VEC cppVar_24897;
	BIT_VEC cppVar_24891;
	BIT_VEC cppVar_24885;
	BIT_VEC cppVar_24879;
	BIT_VEC cppVar_24866;
	BIT_VEC cppVar_24860;
	BIT_VEC cppVar_25007;
	BIT_VEC cppVar_25008;
	bool cppVar_25009;
	BIT_VEC cppVar_25011;
	BIT_VEC cppVar_25012;
	BIT_VEC cppVar_25013;
	BIT_VEC cppVar_25014;
	bool cppVar_25015;
	BIT_VEC cppVar_25017;
	BIT_VEC cppVar_25018;
	BIT_VEC cppVar_25019;
	BIT_VEC cppVar_25020;
	BIT_VEC cppVar_25021;
	BIT_VEC cppVar_25022;
	BIT_VEC cppVar_25023;
	bool cppVar_25024;
	BIT_VEC cppVar_25025;
	BIT_VEC cppVar_25026;
	BIT_VEC cppVar_25027;
	BIT_VEC cppVar_25028;
	BIT_VEC cppVar_25030;
	BIT_VEC cppVar_25031;
	BIT_VEC cppVar_25032;
	BIT_VEC cppVar_25033;
	bool cppVar_25034;
	BIT_VEC cppVar_25036;
	BIT_VEC cppVar_25037;
	BIT_VEC cppVar_25038;
	BIT_VEC cppVar_25039;
	bool cppVar_25040;
	BIT_VEC cppVar_25042;
	BIT_VEC cppVar_25043;
	BIT_VEC cppVar_25044;
	BIT_VEC cppVar_25045;
	bool cppVar_25046;
	BIT_VEC cppVar_25048;
	BIT_VEC cppVar_25049;
	BIT_VEC cppVar_25050;
	BIT_VEC cppVar_25051;
	bool cppVar_25052;
	BIT_VEC cppVar_25054;
	BIT_VEC cppVar_25055;
	BIT_VEC cppVar_25056;
	BIT_VEC cppVar_25057;
	bool cppVar_25058;
	BIT_VEC cppVar_25060;
	BIT_VEC cppVar_25061;
	BIT_VEC cppVar_25062;
	BIT_VEC cppVar_25063;
	bool cppVar_25064;
	BIT_VEC cppVar_25066;
	BIT_VEC cppVar_25067;
	BIT_VEC cppVar_25068;
	BIT_VEC cppVar_25069;
	bool cppVar_25070;
	BIT_VEC cppVar_25072;
	BIT_VEC cppVar_25073;
	BIT_VEC cppVar_25074;
	BIT_VEC cppVar_25075;
	bool cppVar_25076;
	BIT_VEC cppVar_25078;
	BIT_VEC cppVar_25079;
	BIT_VEC cppVar_25080;
	BIT_VEC cppVar_25081;
	bool cppVar_25082;
	BIT_VEC cppVar_25084;
	BIT_VEC cppVar_25085;
	BIT_VEC cppVar_25086;
	BIT_VEC cppVar_25087;
	bool cppVar_25088;
	BIT_VEC cppVar_25090;
	BIT_VEC cppVar_25091;
	BIT_VEC cppVar_25092;
	BIT_VEC cppVar_25093;
	bool cppVar_25094;
	BIT_VEC cppVar_25096;
	BIT_VEC cppVar_25097;
	BIT_VEC cppVar_25098;
	BIT_VEC cppVar_25099;
	bool cppVar_25100;
	BIT_VEC cppVar_25102;
	BIT_VEC cppVar_25103;
	BIT_VEC cppVar_25104;
	BIT_VEC cppVar_25105;
	bool cppVar_25106;
	BIT_VEC cppVar_25108;
	BIT_VEC cppVar_25109;
	BIT_VEC cppVar_25110;
	BIT_VEC cppVar_25111;
	bool cppVar_25112;
	BIT_VEC cppVar_25114;
	BIT_VEC cppVar_25115;
	BIT_VEC cppVar_25116;
	BIT_VEC cppVar_25117;
	bool cppVar_25118;
	BIT_VEC cppVar_25120;
	BIT_VEC cppVar_25121;
	BIT_VEC cppVar_25122;
	BIT_VEC cppVar_25123;
	bool cppVar_25124;
	BIT_VEC cppVar_25126;
	BIT_VEC cppVar_25127;
	BIT_VEC cppVar_25128;
	BIT_VEC cppVar_25129;
	bool cppVar_25130;
	BIT_VEC cppVar_25132;
	BIT_VEC cppVar_25133;
	BIT_VEC cppVar_25134;
	BIT_VEC cppVar_25135;
	bool cppVar_25136;
	BIT_VEC cppVar_25138;
	BIT_VEC cppVar_25139;
	BIT_VEC cppVar_25140;
	BIT_VEC cppVar_25141;
	bool cppVar_25142;
	BIT_VEC cppVar_25144;
	BIT_VEC cppVar_25145;
	BIT_VEC cppVar_25146;
	BIT_VEC cppVar_25147;
	bool cppVar_25148;
	BIT_VEC cppVar_25150;
	BIT_VEC cppVar_25151;
	BIT_VEC cppVar_25152;
	BIT_VEC cppVar_25153;
	bool cppVar_25154;
	BIT_VEC cppVar_25155;
	BIT_VEC cppVar_25149;
	BIT_VEC cppVar_25143;
	BIT_VEC cppVar_25137;
	BIT_VEC cppVar_25131;
	BIT_VEC cppVar_25125;
	BIT_VEC cppVar_25119;
	BIT_VEC cppVar_25113;
	BIT_VEC cppVar_25107;
	BIT_VEC cppVar_25101;
	BIT_VEC cppVar_25095;
	BIT_VEC cppVar_25089;
	BIT_VEC cppVar_25083;
	BIT_VEC cppVar_25077;
	BIT_VEC cppVar_25071;
	BIT_VEC cppVar_25065;
	BIT_VEC cppVar_25059;
	BIT_VEC cppVar_25053;
	BIT_VEC cppVar_25047;
	BIT_VEC cppVar_25041;
	BIT_VEC cppVar_25035;
	BIT_VEC cppVar_25029;
	BIT_VEC cppVar_25016;
	BIT_VEC cppVar_25010;
	BIT_VEC cppVar_25157;
	BIT_VEC cppVar_25158;
	bool cppVar_25159;
	BIT_VEC cppVar_25161;
	BIT_VEC cppVar_25162;
	BIT_VEC cppVar_25163;
	BIT_VEC cppVar_25164;
	bool cppVar_25165;
	BIT_VEC cppVar_25167;
	BIT_VEC cppVar_25168;
	BIT_VEC cppVar_25169;
	BIT_VEC cppVar_25170;
	BIT_VEC cppVar_25171;
	BIT_VEC cppVar_25172;
	BIT_VEC cppVar_25173;
	bool cppVar_25174;
	BIT_VEC cppVar_25175;
	BIT_VEC cppVar_25176;
	BIT_VEC cppVar_25177;
	BIT_VEC cppVar_25178;
	BIT_VEC cppVar_25180;
	BIT_VEC cppVar_25181;
	BIT_VEC cppVar_25182;
	BIT_VEC cppVar_25183;
	bool cppVar_25184;
	BIT_VEC cppVar_25186;
	BIT_VEC cppVar_25187;
	BIT_VEC cppVar_25188;
	BIT_VEC cppVar_25189;
	bool cppVar_25190;
	BIT_VEC cppVar_25192;
	BIT_VEC cppVar_25193;
	BIT_VEC cppVar_25194;
	BIT_VEC cppVar_25195;
	bool cppVar_25196;
	BIT_VEC cppVar_25198;
	BIT_VEC cppVar_25199;
	BIT_VEC cppVar_25200;
	BIT_VEC cppVar_25201;
	bool cppVar_25202;
	BIT_VEC cppVar_25204;
	BIT_VEC cppVar_25205;
	BIT_VEC cppVar_25206;
	BIT_VEC cppVar_25207;
	bool cppVar_25208;
	BIT_VEC cppVar_25210;
	BIT_VEC cppVar_25211;
	BIT_VEC cppVar_25212;
	BIT_VEC cppVar_25213;
	bool cppVar_25214;
	BIT_VEC cppVar_25216;
	BIT_VEC cppVar_25217;
	BIT_VEC cppVar_25218;
	BIT_VEC cppVar_25219;
	bool cppVar_25220;
	BIT_VEC cppVar_25222;
	BIT_VEC cppVar_25223;
	BIT_VEC cppVar_25224;
	BIT_VEC cppVar_25225;
	bool cppVar_25226;
	BIT_VEC cppVar_25228;
	BIT_VEC cppVar_25229;
	BIT_VEC cppVar_25230;
	BIT_VEC cppVar_25231;
	bool cppVar_25232;
	BIT_VEC cppVar_25234;
	BIT_VEC cppVar_25235;
	BIT_VEC cppVar_25236;
	BIT_VEC cppVar_25237;
	bool cppVar_25238;
	BIT_VEC cppVar_25240;
	BIT_VEC cppVar_25241;
	BIT_VEC cppVar_25242;
	BIT_VEC cppVar_25243;
	bool cppVar_25244;
	BIT_VEC cppVar_25246;
	BIT_VEC cppVar_25247;
	BIT_VEC cppVar_25248;
	BIT_VEC cppVar_25249;
	bool cppVar_25250;
	BIT_VEC cppVar_25252;
	BIT_VEC cppVar_25253;
	BIT_VEC cppVar_25254;
	BIT_VEC cppVar_25255;
	bool cppVar_25256;
	BIT_VEC cppVar_25258;
	BIT_VEC cppVar_25259;
	BIT_VEC cppVar_25260;
	BIT_VEC cppVar_25261;
	bool cppVar_25262;
	BIT_VEC cppVar_25264;
	BIT_VEC cppVar_25265;
	BIT_VEC cppVar_25266;
	BIT_VEC cppVar_25267;
	bool cppVar_25268;
	BIT_VEC cppVar_25270;
	BIT_VEC cppVar_25271;
	BIT_VEC cppVar_25272;
	BIT_VEC cppVar_25273;
	bool cppVar_25274;
	BIT_VEC cppVar_25276;
	BIT_VEC cppVar_25277;
	BIT_VEC cppVar_25278;
	BIT_VEC cppVar_25279;
	bool cppVar_25280;
	BIT_VEC cppVar_25282;
	BIT_VEC cppVar_25283;
	BIT_VEC cppVar_25284;
	BIT_VEC cppVar_25285;
	bool cppVar_25286;
	BIT_VEC cppVar_25288;
	BIT_VEC cppVar_25289;
	BIT_VEC cppVar_25290;
	BIT_VEC cppVar_25291;
	bool cppVar_25292;
	BIT_VEC cppVar_25294;
	BIT_VEC cppVar_25295;
	BIT_VEC cppVar_25296;
	BIT_VEC cppVar_25297;
	bool cppVar_25298;
	BIT_VEC cppVar_25300;
	BIT_VEC cppVar_25301;
	BIT_VEC cppVar_25302;
	BIT_VEC cppVar_25303;
	bool cppVar_25304;
	BIT_VEC cppVar_25305;
	BIT_VEC cppVar_25299;
	BIT_VEC cppVar_25293;
	BIT_VEC cppVar_25287;
	BIT_VEC cppVar_25281;
	BIT_VEC cppVar_25275;
	BIT_VEC cppVar_25269;
	BIT_VEC cppVar_25263;
	BIT_VEC cppVar_25257;
	BIT_VEC cppVar_25251;
	BIT_VEC cppVar_25245;
	BIT_VEC cppVar_25239;
	BIT_VEC cppVar_25233;
	BIT_VEC cppVar_25227;
	BIT_VEC cppVar_25221;
	BIT_VEC cppVar_25215;
	BIT_VEC cppVar_25209;
	BIT_VEC cppVar_25203;
	BIT_VEC cppVar_25197;
	BIT_VEC cppVar_25191;
	BIT_VEC cppVar_25185;
	BIT_VEC cppVar_25179;
	BIT_VEC cppVar_25166;
	BIT_VEC cppVar_25160;
	BIT_VEC cppVar_25307;
	BIT_VEC cppVar_25308;
	bool cppVar_25309;
	BIT_VEC cppVar_25311;
	BIT_VEC cppVar_25312;
	BIT_VEC cppVar_25313;
	BIT_VEC cppVar_25314;
	bool cppVar_25315;
	BIT_VEC cppVar_25317;
	BIT_VEC cppVar_25318;
	BIT_VEC cppVar_25319;
	BIT_VEC cppVar_25320;
	BIT_VEC cppVar_25321;
	BIT_VEC cppVar_25322;
	BIT_VEC cppVar_25323;
	bool cppVar_25324;
	BIT_VEC cppVar_25325;
	BIT_VEC cppVar_25326;
	BIT_VEC cppVar_25327;
	BIT_VEC cppVar_25328;
	BIT_VEC cppVar_25330;
	BIT_VEC cppVar_25331;
	BIT_VEC cppVar_25332;
	BIT_VEC cppVar_25333;
	bool cppVar_25334;
	BIT_VEC cppVar_25336;
	BIT_VEC cppVar_25337;
	BIT_VEC cppVar_25338;
	BIT_VEC cppVar_25339;
	bool cppVar_25340;
	BIT_VEC cppVar_25342;
	BIT_VEC cppVar_25343;
	BIT_VEC cppVar_25344;
	BIT_VEC cppVar_25345;
	bool cppVar_25346;
	BIT_VEC cppVar_25348;
	BIT_VEC cppVar_25349;
	BIT_VEC cppVar_25350;
	BIT_VEC cppVar_25351;
	bool cppVar_25352;
	BIT_VEC cppVar_25354;
	BIT_VEC cppVar_25355;
	BIT_VEC cppVar_25356;
	BIT_VEC cppVar_25357;
	bool cppVar_25358;
	BIT_VEC cppVar_25360;
	BIT_VEC cppVar_25361;
	BIT_VEC cppVar_25362;
	BIT_VEC cppVar_25363;
	bool cppVar_25364;
	BIT_VEC cppVar_25366;
	BIT_VEC cppVar_25367;
	BIT_VEC cppVar_25368;
	BIT_VEC cppVar_25369;
	bool cppVar_25370;
	BIT_VEC cppVar_25372;
	BIT_VEC cppVar_25373;
	BIT_VEC cppVar_25374;
	BIT_VEC cppVar_25375;
	bool cppVar_25376;
	BIT_VEC cppVar_25378;
	BIT_VEC cppVar_25379;
	BIT_VEC cppVar_25380;
	BIT_VEC cppVar_25381;
	bool cppVar_25382;
	BIT_VEC cppVar_25384;
	BIT_VEC cppVar_25385;
	BIT_VEC cppVar_25386;
	BIT_VEC cppVar_25387;
	bool cppVar_25388;
	BIT_VEC cppVar_25390;
	BIT_VEC cppVar_25391;
	BIT_VEC cppVar_25392;
	BIT_VEC cppVar_25393;
	bool cppVar_25394;
	BIT_VEC cppVar_25396;
	BIT_VEC cppVar_25397;
	BIT_VEC cppVar_25398;
	BIT_VEC cppVar_25399;
	bool cppVar_25400;
	BIT_VEC cppVar_25402;
	BIT_VEC cppVar_25403;
	BIT_VEC cppVar_25404;
	BIT_VEC cppVar_25405;
	bool cppVar_25406;
	BIT_VEC cppVar_25408;
	BIT_VEC cppVar_25409;
	BIT_VEC cppVar_25410;
	BIT_VEC cppVar_25411;
	bool cppVar_25412;
	BIT_VEC cppVar_25414;
	BIT_VEC cppVar_25415;
	BIT_VEC cppVar_25416;
	BIT_VEC cppVar_25417;
	bool cppVar_25418;
	BIT_VEC cppVar_25420;
	BIT_VEC cppVar_25421;
	BIT_VEC cppVar_25422;
	BIT_VEC cppVar_25423;
	bool cppVar_25424;
	BIT_VEC cppVar_25426;
	BIT_VEC cppVar_25427;
	BIT_VEC cppVar_25428;
	BIT_VEC cppVar_25429;
	bool cppVar_25430;
	BIT_VEC cppVar_25432;
	BIT_VEC cppVar_25433;
	BIT_VEC cppVar_25434;
	BIT_VEC cppVar_25435;
	bool cppVar_25436;
	BIT_VEC cppVar_25438;
	BIT_VEC cppVar_25439;
	BIT_VEC cppVar_25440;
	BIT_VEC cppVar_25441;
	bool cppVar_25442;
	BIT_VEC cppVar_25444;
	BIT_VEC cppVar_25445;
	BIT_VEC cppVar_25446;
	BIT_VEC cppVar_25447;
	bool cppVar_25448;
	BIT_VEC cppVar_25450;
	BIT_VEC cppVar_25451;
	BIT_VEC cppVar_25452;
	BIT_VEC cppVar_25453;
	bool cppVar_25454;
	BIT_VEC cppVar_25455;
	BIT_VEC cppVar_25449;
	BIT_VEC cppVar_25443;
	BIT_VEC cppVar_25437;
	BIT_VEC cppVar_25431;
	BIT_VEC cppVar_25425;
	BIT_VEC cppVar_25419;
	BIT_VEC cppVar_25413;
	BIT_VEC cppVar_25407;
	BIT_VEC cppVar_25401;
	BIT_VEC cppVar_25395;
	BIT_VEC cppVar_25389;
	BIT_VEC cppVar_25383;
	BIT_VEC cppVar_25377;
	BIT_VEC cppVar_25371;
	BIT_VEC cppVar_25365;
	BIT_VEC cppVar_25359;
	BIT_VEC cppVar_25353;
	BIT_VEC cppVar_25347;
	BIT_VEC cppVar_25341;
	BIT_VEC cppVar_25335;
	BIT_VEC cppVar_25329;
	BIT_VEC cppVar_25316;
	BIT_VEC cppVar_25310;
	BIT_VEC cppVar_25457;
	BIT_VEC cppVar_25458;
	bool cppVar_25459;
	BIT_VEC cppVar_25461;
	BIT_VEC cppVar_25462;
	BIT_VEC cppVar_25463;
	BIT_VEC cppVar_25464;
	bool cppVar_25465;
	BIT_VEC cppVar_25466;
	BIT_VEC cppVar_25467;
	BIT_VEC cppVar_25468;
	BIT_VEC cppVar_25469;
	BIT_VEC cppVar_25470;
	BIT_VEC cppVar_25471;
	BIT_VEC cppVar_25472;
	BIT_VEC cppVar_25460;
	BIT_VEC cppVar_25474;
	BIT_VEC cppVar_25475;
	bool cppVar_25476;
	BIT_VEC cppVar_25478;
	BIT_VEC cppVar_25479;
	BIT_VEC cppVar_25480;
	BIT_VEC cppVar_25481;
	bool cppVar_25482;
	BIT_VEC cppVar_25483;
	BIT_VEC cppVar_25484;
	BIT_VEC cppVar_25485;
	BIT_VEC cppVar_25486;
	BIT_VEC cppVar_25487;
	BIT_VEC cppVar_25488;
	BIT_VEC cppVar_25489;
	BIT_VEC cppVar_25477;
	BIT_VEC cppVar_25491;
	BIT_VEC cppVar_25492;
	bool cppVar_25493;
	BIT_VEC cppVar_25495;
	BIT_VEC cppVar_25496;
	BIT_VEC cppVar_25497;
	BIT_VEC cppVar_25498;
	bool cppVar_25499;
	BIT_VEC cppVar_25501;
	BIT_VEC cppVar_25502;
	BIT_VEC cppVar_25503;
	BIT_VEC cppVar_25504;
	BIT_VEC cppVar_25505;
	bool cppVar_25506;
	BIT_VEC cppVar_25507;
	BIT_VEC cppVar_25508;
	BIT_VEC cppVar_25509;
	BIT_VEC cppVar_25511;
	BIT_VEC cppVar_25512;
	BIT_VEC cppVar_25513;
	bool cppVar_25514;
	BIT_VEC cppVar_25516;
	BIT_VEC cppVar_25517;
	BIT_VEC cppVar_25518;
	bool cppVar_25519;
	BIT_VEC cppVar_25521;
	BIT_VEC cppVar_25522;
	BIT_VEC cppVar_25523;
	bool cppVar_25524;
	BIT_VEC cppVar_25526;
	BIT_VEC cppVar_25527;
	BIT_VEC cppVar_25528;
	bool cppVar_25529;
	BIT_VEC cppVar_25531;
	BIT_VEC cppVar_25532;
	BIT_VEC cppVar_25533;
	bool cppVar_25534;
	BIT_VEC cppVar_25536;
	BIT_VEC cppVar_25537;
	BIT_VEC cppVar_25538;
	bool cppVar_25539;
	BIT_VEC cppVar_25541;
	BIT_VEC cppVar_25542;
	BIT_VEC cppVar_25543;
	bool cppVar_25544;
	BIT_VEC cppVar_25546;
	BIT_VEC cppVar_25547;
	BIT_VEC cppVar_25548;
	bool cppVar_25549;
	BIT_VEC cppVar_25551;
	BIT_VEC cppVar_25552;
	BIT_VEC cppVar_25553;
	bool cppVar_25554;
	BIT_VEC cppVar_25556;
	BIT_VEC cppVar_25557;
	BIT_VEC cppVar_25558;
	bool cppVar_25559;
	BIT_VEC cppVar_25561;
	BIT_VEC cppVar_25562;
	BIT_VEC cppVar_25563;
	bool cppVar_25564;
	BIT_VEC cppVar_25566;
	BIT_VEC cppVar_25567;
	BIT_VEC cppVar_25568;
	bool cppVar_25569;
	BIT_VEC cppVar_25571;
	BIT_VEC cppVar_25572;
	BIT_VEC cppVar_25573;
	bool cppVar_25574;
	BIT_VEC cppVar_25576;
	BIT_VEC cppVar_25577;
	BIT_VEC cppVar_25578;
	bool cppVar_25579;
	BIT_VEC cppVar_25581;
	BIT_VEC cppVar_25582;
	BIT_VEC cppVar_25583;
	bool cppVar_25584;
	BIT_VEC cppVar_25586;
	BIT_VEC cppVar_25587;
	BIT_VEC cppVar_25588;
	bool cppVar_25589;
	BIT_VEC cppVar_25591;
	BIT_VEC cppVar_25592;
	BIT_VEC cppVar_25593;
	bool cppVar_25594;
	BIT_VEC cppVar_25596;
	BIT_VEC cppVar_25597;
	BIT_VEC cppVar_25598;
	bool cppVar_25599;
	BIT_VEC cppVar_25601;
	BIT_VEC cppVar_25602;
	BIT_VEC cppVar_25603;
	bool cppVar_25604;
	BIT_VEC cppVar_25606;
	BIT_VEC cppVar_25607;
	BIT_VEC cppVar_25608;
	bool cppVar_25609;
	BIT_VEC cppVar_25611;
	BIT_VEC cppVar_25612;
	BIT_VEC cppVar_25613;
	bool cppVar_25614;
	BIT_VEC cppVar_25615;
	BIT_VEC cppVar_25610;
	BIT_VEC cppVar_25605;
	BIT_VEC cppVar_25600;
	BIT_VEC cppVar_25595;
	BIT_VEC cppVar_25590;
	BIT_VEC cppVar_25585;
	BIT_VEC cppVar_25580;
	BIT_VEC cppVar_25575;
	BIT_VEC cppVar_25570;
	BIT_VEC cppVar_25565;
	BIT_VEC cppVar_25560;
	BIT_VEC cppVar_25555;
	BIT_VEC cppVar_25550;
	BIT_VEC cppVar_25545;
	BIT_VEC cppVar_25540;
	BIT_VEC cppVar_25535;
	BIT_VEC cppVar_25530;
	BIT_VEC cppVar_25525;
	BIT_VEC cppVar_25520;
	BIT_VEC cppVar_25515;
	BIT_VEC cppVar_25510;
	BIT_VEC cppVar_25500;
	BIT_VEC cppVar_25494;
	BIT_VEC cppVar_25617;
	BIT_VEC cppVar_25618;
	bool cppVar_25619;
	BIT_VEC cppVar_25621;
	BIT_VEC cppVar_25622;
	BIT_VEC cppVar_25623;
	BIT_VEC cppVar_25624;
	bool cppVar_25625;
	BIT_VEC cppVar_25626;
	BIT_VEC cppVar_25627;
	BIT_VEC cppVar_25628;
	BIT_VEC cppVar_25620;
	BIT_VEC cppVar_25630;
	BIT_VEC cppVar_25631;
	bool cppVar_25632;
	BIT_VEC cppVar_25634;
	BIT_VEC cppVar_25635;
	BIT_VEC cppVar_25636;
	BIT_VEC cppVar_25637;
	bool cppVar_25638;
	BIT_VEC cppVar_25640;
	BIT_VEC cppVar_25641;
	BIT_VEC cppVar_25642;
	BIT_VEC cppVar_25643;
	bool cppVar_25644;
	BIT_VEC cppVar_25645;
	BIT_VEC cppVar_25646;
	BIT_VEC cppVar_25647;
	BIT_VEC cppVar_25649;
	BIT_VEC cppVar_25650;
	BIT_VEC cppVar_25651;
	bool cppVar_25652;
	BIT_VEC cppVar_25654;
	BIT_VEC cppVar_25655;
	BIT_VEC cppVar_25656;
	bool cppVar_25657;
	BIT_VEC cppVar_25659;
	BIT_VEC cppVar_25660;
	BIT_VEC cppVar_25661;
	bool cppVar_25662;
	BIT_VEC cppVar_25664;
	BIT_VEC cppVar_25665;
	BIT_VEC cppVar_25666;
	bool cppVar_25667;
	BIT_VEC cppVar_25669;
	BIT_VEC cppVar_25670;
	BIT_VEC cppVar_25671;
	bool cppVar_25672;
	BIT_VEC cppVar_25674;
	BIT_VEC cppVar_25675;
	BIT_VEC cppVar_25676;
	bool cppVar_25677;
	BIT_VEC cppVar_25679;
	BIT_VEC cppVar_25680;
	BIT_VEC cppVar_25681;
	bool cppVar_25682;
	BIT_VEC cppVar_25684;
	BIT_VEC cppVar_25685;
	BIT_VEC cppVar_25686;
	bool cppVar_25687;
	BIT_VEC cppVar_25689;
	BIT_VEC cppVar_25690;
	BIT_VEC cppVar_25691;
	bool cppVar_25692;
	BIT_VEC cppVar_25694;
	BIT_VEC cppVar_25695;
	BIT_VEC cppVar_25696;
	bool cppVar_25697;
	BIT_VEC cppVar_25699;
	BIT_VEC cppVar_25700;
	BIT_VEC cppVar_25701;
	bool cppVar_25702;
	BIT_VEC cppVar_25704;
	BIT_VEC cppVar_25705;
	BIT_VEC cppVar_25706;
	bool cppVar_25707;
	BIT_VEC cppVar_25709;
	BIT_VEC cppVar_25710;
	BIT_VEC cppVar_25711;
	bool cppVar_25712;
	BIT_VEC cppVar_25714;
	BIT_VEC cppVar_25715;
	BIT_VEC cppVar_25716;
	bool cppVar_25717;
	BIT_VEC cppVar_25719;
	BIT_VEC cppVar_25720;
	BIT_VEC cppVar_25721;
	bool cppVar_25722;
	BIT_VEC cppVar_25724;
	BIT_VEC cppVar_25725;
	BIT_VEC cppVar_25726;
	bool cppVar_25727;
	BIT_VEC cppVar_25729;
	BIT_VEC cppVar_25730;
	BIT_VEC cppVar_25731;
	bool cppVar_25732;
	BIT_VEC cppVar_25734;
	BIT_VEC cppVar_25735;
	BIT_VEC cppVar_25736;
	bool cppVar_25737;
	BIT_VEC cppVar_25739;
	BIT_VEC cppVar_25740;
	BIT_VEC cppVar_25741;
	bool cppVar_25742;
	BIT_VEC cppVar_25744;
	BIT_VEC cppVar_25745;
	BIT_VEC cppVar_25746;
	bool cppVar_25747;
	BIT_VEC cppVar_25749;
	BIT_VEC cppVar_25750;
	BIT_VEC cppVar_25751;
	bool cppVar_25752;
	BIT_VEC cppVar_25753;
	BIT_VEC cppVar_25748;
	BIT_VEC cppVar_25743;
	BIT_VEC cppVar_25738;
	BIT_VEC cppVar_25733;
	BIT_VEC cppVar_25728;
	BIT_VEC cppVar_25723;
	BIT_VEC cppVar_25718;
	BIT_VEC cppVar_25713;
	BIT_VEC cppVar_25708;
	BIT_VEC cppVar_25703;
	BIT_VEC cppVar_25698;
	BIT_VEC cppVar_25693;
	BIT_VEC cppVar_25688;
	BIT_VEC cppVar_25683;
	BIT_VEC cppVar_25678;
	BIT_VEC cppVar_25673;
	BIT_VEC cppVar_25668;
	BIT_VEC cppVar_25663;
	BIT_VEC cppVar_25658;
	BIT_VEC cppVar_25653;
	BIT_VEC cppVar_25648;
	BIT_VEC cppVar_25639;
	BIT_VEC cppVar_25754;
	BIT_VEC cppVar_25755;
	BIT_VEC cppVar_25756;
	BIT_VEC cppVar_25757;
	BIT_VEC cppVar_25633;
	BIT_VEC cppVar_25759;
	BIT_VEC cppVar_25760;
	bool cppVar_25761;
	BIT_VEC cppVar_25763;
	BIT_VEC cppVar_25764;
	BIT_VEC cppVar_25765;
	BIT_VEC cppVar_25766;
	bool cppVar_25767;
	BIT_VEC cppVar_25769;
	BIT_VEC cppVar_25770;
	BIT_VEC cppVar_25771;
	BIT_VEC cppVar_25772;
	bool cppVar_25773;
	BIT_VEC cppVar_25774;
	BIT_VEC cppVar_25775;
	BIT_VEC cppVar_25776;
	BIT_VEC cppVar_25778;
	BIT_VEC cppVar_25779;
	BIT_VEC cppVar_25780;
	bool cppVar_25781;
	BIT_VEC cppVar_25783;
	BIT_VEC cppVar_25784;
	BIT_VEC cppVar_25785;
	bool cppVar_25786;
	BIT_VEC cppVar_25788;
	BIT_VEC cppVar_25789;
	BIT_VEC cppVar_25790;
	bool cppVar_25791;
	BIT_VEC cppVar_25793;
	BIT_VEC cppVar_25794;
	BIT_VEC cppVar_25795;
	bool cppVar_25796;
	BIT_VEC cppVar_25798;
	BIT_VEC cppVar_25799;
	BIT_VEC cppVar_25800;
	bool cppVar_25801;
	BIT_VEC cppVar_25803;
	BIT_VEC cppVar_25804;
	BIT_VEC cppVar_25805;
	bool cppVar_25806;
	BIT_VEC cppVar_25808;
	BIT_VEC cppVar_25809;
	BIT_VEC cppVar_25810;
	bool cppVar_25811;
	BIT_VEC cppVar_25813;
	BIT_VEC cppVar_25814;
	BIT_VEC cppVar_25815;
	bool cppVar_25816;
	BIT_VEC cppVar_25818;
	BIT_VEC cppVar_25819;
	BIT_VEC cppVar_25820;
	bool cppVar_25821;
	BIT_VEC cppVar_25823;
	BIT_VEC cppVar_25824;
	BIT_VEC cppVar_25825;
	bool cppVar_25826;
	BIT_VEC cppVar_25828;
	BIT_VEC cppVar_25829;
	BIT_VEC cppVar_25830;
	bool cppVar_25831;
	BIT_VEC cppVar_25833;
	BIT_VEC cppVar_25834;
	BIT_VEC cppVar_25835;
	bool cppVar_25836;
	BIT_VEC cppVar_25838;
	BIT_VEC cppVar_25839;
	BIT_VEC cppVar_25840;
	bool cppVar_25841;
	BIT_VEC cppVar_25843;
	BIT_VEC cppVar_25844;
	BIT_VEC cppVar_25845;
	bool cppVar_25846;
	BIT_VEC cppVar_25848;
	BIT_VEC cppVar_25849;
	BIT_VEC cppVar_25850;
	bool cppVar_25851;
	BIT_VEC cppVar_25853;
	BIT_VEC cppVar_25854;
	BIT_VEC cppVar_25855;
	bool cppVar_25856;
	BIT_VEC cppVar_25858;
	BIT_VEC cppVar_25859;
	BIT_VEC cppVar_25860;
	bool cppVar_25861;
	BIT_VEC cppVar_25863;
	BIT_VEC cppVar_25864;
	BIT_VEC cppVar_25865;
	bool cppVar_25866;
	BIT_VEC cppVar_25868;
	BIT_VEC cppVar_25869;
	BIT_VEC cppVar_25870;
	bool cppVar_25871;
	BIT_VEC cppVar_25873;
	BIT_VEC cppVar_25874;
	BIT_VEC cppVar_25875;
	bool cppVar_25876;
	BIT_VEC cppVar_25878;
	BIT_VEC cppVar_25879;
	BIT_VEC cppVar_25880;
	bool cppVar_25881;
	BIT_VEC cppVar_25882;
	BIT_VEC cppVar_25877;
	BIT_VEC cppVar_25872;
	BIT_VEC cppVar_25867;
	BIT_VEC cppVar_25862;
	BIT_VEC cppVar_25857;
	BIT_VEC cppVar_25852;
	BIT_VEC cppVar_25847;
	BIT_VEC cppVar_25842;
	BIT_VEC cppVar_25837;
	BIT_VEC cppVar_25832;
	BIT_VEC cppVar_25827;
	BIT_VEC cppVar_25822;
	BIT_VEC cppVar_25817;
	BIT_VEC cppVar_25812;
	BIT_VEC cppVar_25807;
	BIT_VEC cppVar_25802;
	BIT_VEC cppVar_25797;
	BIT_VEC cppVar_25792;
	BIT_VEC cppVar_25787;
	BIT_VEC cppVar_25782;
	BIT_VEC cppVar_25777;
	BIT_VEC cppVar_25768;
	BIT_VEC cppVar_25883;
	BIT_VEC cppVar_25762;
	BIT_VEC cppVar_25885;
	BIT_VEC cppVar_25886;
	bool cppVar_25887;
	BIT_VEC cppVar_25889;
	BIT_VEC cppVar_25890;
	BIT_VEC cppVar_25891;
	BIT_VEC cppVar_25892;
	bool cppVar_25893;
	BIT_VEC cppVar_25895;
	BIT_VEC cppVar_25896;
	BIT_VEC cppVar_25897;
	BIT_VEC cppVar_25898;
	bool cppVar_25899;
	BIT_VEC cppVar_25900;
	BIT_VEC cppVar_25901;
	BIT_VEC cppVar_25902;
	BIT_VEC cppVar_25904;
	BIT_VEC cppVar_25905;
	BIT_VEC cppVar_25906;
	bool cppVar_25907;
	BIT_VEC cppVar_25909;
	BIT_VEC cppVar_25910;
	BIT_VEC cppVar_25911;
	bool cppVar_25912;
	BIT_VEC cppVar_25914;
	BIT_VEC cppVar_25915;
	BIT_VEC cppVar_25916;
	bool cppVar_25917;
	BIT_VEC cppVar_25919;
	BIT_VEC cppVar_25920;
	BIT_VEC cppVar_25921;
	bool cppVar_25922;
	BIT_VEC cppVar_25924;
	BIT_VEC cppVar_25925;
	BIT_VEC cppVar_25926;
	bool cppVar_25927;
	BIT_VEC cppVar_25929;
	BIT_VEC cppVar_25930;
	BIT_VEC cppVar_25931;
	bool cppVar_25932;
	BIT_VEC cppVar_25934;
	BIT_VEC cppVar_25935;
	BIT_VEC cppVar_25936;
	bool cppVar_25937;
	BIT_VEC cppVar_25939;
	BIT_VEC cppVar_25940;
	BIT_VEC cppVar_25941;
	bool cppVar_25942;
	BIT_VEC cppVar_25944;
	BIT_VEC cppVar_25945;
	BIT_VEC cppVar_25946;
	bool cppVar_25947;
	BIT_VEC cppVar_25949;
	BIT_VEC cppVar_25950;
	BIT_VEC cppVar_25951;
	bool cppVar_25952;
	BIT_VEC cppVar_25954;
	BIT_VEC cppVar_25955;
	BIT_VEC cppVar_25956;
	bool cppVar_25957;
	BIT_VEC cppVar_25959;
	BIT_VEC cppVar_25960;
	BIT_VEC cppVar_25961;
	bool cppVar_25962;
	BIT_VEC cppVar_25964;
	BIT_VEC cppVar_25965;
	BIT_VEC cppVar_25966;
	bool cppVar_25967;
	BIT_VEC cppVar_25969;
	BIT_VEC cppVar_25970;
	BIT_VEC cppVar_25971;
	bool cppVar_25972;
	BIT_VEC cppVar_25974;
	BIT_VEC cppVar_25975;
	BIT_VEC cppVar_25976;
	bool cppVar_25977;
	BIT_VEC cppVar_25979;
	BIT_VEC cppVar_25980;
	BIT_VEC cppVar_25981;
	bool cppVar_25982;
	BIT_VEC cppVar_25984;
	BIT_VEC cppVar_25985;
	BIT_VEC cppVar_25986;
	bool cppVar_25987;
	BIT_VEC cppVar_25989;
	BIT_VEC cppVar_25990;
	BIT_VEC cppVar_25991;
	bool cppVar_25992;
	BIT_VEC cppVar_25994;
	BIT_VEC cppVar_25995;
	BIT_VEC cppVar_25996;
	bool cppVar_25997;
	BIT_VEC cppVar_25999;
	BIT_VEC cppVar_26000;
	BIT_VEC cppVar_26001;
	bool cppVar_26002;
	BIT_VEC cppVar_26004;
	BIT_VEC cppVar_26005;
	BIT_VEC cppVar_26006;
	bool cppVar_26007;
	BIT_VEC cppVar_26008;
	BIT_VEC cppVar_26003;
	BIT_VEC cppVar_25998;
	BIT_VEC cppVar_25993;
	BIT_VEC cppVar_25988;
	BIT_VEC cppVar_25983;
	BIT_VEC cppVar_25978;
	BIT_VEC cppVar_25973;
	BIT_VEC cppVar_25968;
	BIT_VEC cppVar_25963;
	BIT_VEC cppVar_25958;
	BIT_VEC cppVar_25953;
	BIT_VEC cppVar_25948;
	BIT_VEC cppVar_25943;
	BIT_VEC cppVar_25938;
	BIT_VEC cppVar_25933;
	BIT_VEC cppVar_25928;
	BIT_VEC cppVar_25923;
	BIT_VEC cppVar_25918;
	BIT_VEC cppVar_25913;
	BIT_VEC cppVar_25908;
	BIT_VEC cppVar_25903;
	BIT_VEC cppVar_25894;
	BIT_VEC cppVar_26009;
	BIT_VEC cppVar_26010;
	BIT_VEC cppVar_26011;
	BIT_VEC cppVar_26012;
	BIT_VEC cppVar_25888;
	BIT_VEC cppVar_26014;
	BIT_VEC cppVar_26015;
	bool cppVar_26016;
	BIT_VEC cppVar_26018;
	BIT_VEC cppVar_26019;
	BIT_VEC cppVar_26020;
	BIT_VEC cppVar_26021;
	bool cppVar_26022;
	BIT_VEC cppVar_26024;
	BIT_VEC cppVar_26025;
	BIT_VEC cppVar_26026;
	BIT_VEC cppVar_26027;
	bool cppVar_26028;
	BIT_VEC cppVar_26029;
	BIT_VEC cppVar_26030;
	BIT_VEC cppVar_26031;
	BIT_VEC cppVar_26033;
	BIT_VEC cppVar_26034;
	BIT_VEC cppVar_26035;
	bool cppVar_26036;
	BIT_VEC cppVar_26038;
	BIT_VEC cppVar_26039;
	BIT_VEC cppVar_26040;
	bool cppVar_26041;
	BIT_VEC cppVar_26043;
	BIT_VEC cppVar_26044;
	BIT_VEC cppVar_26045;
	bool cppVar_26046;
	BIT_VEC cppVar_26048;
	BIT_VEC cppVar_26049;
	BIT_VEC cppVar_26050;
	bool cppVar_26051;
	BIT_VEC cppVar_26053;
	BIT_VEC cppVar_26054;
	BIT_VEC cppVar_26055;
	bool cppVar_26056;
	BIT_VEC cppVar_26058;
	BIT_VEC cppVar_26059;
	BIT_VEC cppVar_26060;
	bool cppVar_26061;
	BIT_VEC cppVar_26063;
	BIT_VEC cppVar_26064;
	BIT_VEC cppVar_26065;
	bool cppVar_26066;
	BIT_VEC cppVar_26068;
	BIT_VEC cppVar_26069;
	BIT_VEC cppVar_26070;
	bool cppVar_26071;
	BIT_VEC cppVar_26073;
	BIT_VEC cppVar_26074;
	BIT_VEC cppVar_26075;
	bool cppVar_26076;
	BIT_VEC cppVar_26078;
	BIT_VEC cppVar_26079;
	BIT_VEC cppVar_26080;
	bool cppVar_26081;
	BIT_VEC cppVar_26083;
	BIT_VEC cppVar_26084;
	BIT_VEC cppVar_26085;
	bool cppVar_26086;
	BIT_VEC cppVar_26088;
	BIT_VEC cppVar_26089;
	BIT_VEC cppVar_26090;
	bool cppVar_26091;
	BIT_VEC cppVar_26093;
	BIT_VEC cppVar_26094;
	BIT_VEC cppVar_26095;
	bool cppVar_26096;
	BIT_VEC cppVar_26098;
	BIT_VEC cppVar_26099;
	BIT_VEC cppVar_26100;
	bool cppVar_26101;
	BIT_VEC cppVar_26103;
	BIT_VEC cppVar_26104;
	BIT_VEC cppVar_26105;
	bool cppVar_26106;
	BIT_VEC cppVar_26108;
	BIT_VEC cppVar_26109;
	BIT_VEC cppVar_26110;
	bool cppVar_26111;
	BIT_VEC cppVar_26113;
	BIT_VEC cppVar_26114;
	BIT_VEC cppVar_26115;
	bool cppVar_26116;
	BIT_VEC cppVar_26118;
	BIT_VEC cppVar_26119;
	BIT_VEC cppVar_26120;
	bool cppVar_26121;
	BIT_VEC cppVar_26123;
	BIT_VEC cppVar_26124;
	BIT_VEC cppVar_26125;
	bool cppVar_26126;
	BIT_VEC cppVar_26128;
	BIT_VEC cppVar_26129;
	BIT_VEC cppVar_26130;
	bool cppVar_26131;
	BIT_VEC cppVar_26133;
	BIT_VEC cppVar_26134;
	BIT_VEC cppVar_26135;
	bool cppVar_26136;
	BIT_VEC cppVar_26137;
	BIT_VEC cppVar_26132;
	BIT_VEC cppVar_26127;
	BIT_VEC cppVar_26122;
	BIT_VEC cppVar_26117;
	BIT_VEC cppVar_26112;
	BIT_VEC cppVar_26107;
	BIT_VEC cppVar_26102;
	BIT_VEC cppVar_26097;
	BIT_VEC cppVar_26092;
	BIT_VEC cppVar_26087;
	BIT_VEC cppVar_26082;
	BIT_VEC cppVar_26077;
	BIT_VEC cppVar_26072;
	BIT_VEC cppVar_26067;
	BIT_VEC cppVar_26062;
	BIT_VEC cppVar_26057;
	BIT_VEC cppVar_26052;
	BIT_VEC cppVar_26047;
	BIT_VEC cppVar_26042;
	BIT_VEC cppVar_26037;
	BIT_VEC cppVar_26032;
	BIT_VEC cppVar_26023;
	BIT_VEC cppVar_26138;
	BIT_VEC cppVar_26017;
	BIT_VEC cppVar_26140;
	BIT_VEC cppVar_26141;
	bool cppVar_26142;
	BIT_VEC cppVar_26144;
	BIT_VEC cppVar_26145;
	BIT_VEC cppVar_26146;
	BIT_VEC cppVar_26147;
	bool cppVar_26148;
	BIT_VEC cppVar_26150;
	BIT_VEC cppVar_26151;
	BIT_VEC cppVar_26152;
	BIT_VEC cppVar_26153;
	bool cppVar_26154;
	BIT_VEC cppVar_26155;
	BIT_VEC cppVar_26156;
	BIT_VEC cppVar_26157;
	BIT_VEC cppVar_26159;
	BIT_VEC cppVar_26160;
	BIT_VEC cppVar_26161;
	bool cppVar_26162;
	BIT_VEC cppVar_26164;
	BIT_VEC cppVar_26165;
	BIT_VEC cppVar_26166;
	bool cppVar_26167;
	BIT_VEC cppVar_26169;
	BIT_VEC cppVar_26170;
	BIT_VEC cppVar_26171;
	bool cppVar_26172;
	BIT_VEC cppVar_26174;
	BIT_VEC cppVar_26175;
	BIT_VEC cppVar_26176;
	bool cppVar_26177;
	BIT_VEC cppVar_26179;
	BIT_VEC cppVar_26180;
	BIT_VEC cppVar_26181;
	bool cppVar_26182;
	BIT_VEC cppVar_26184;
	BIT_VEC cppVar_26185;
	BIT_VEC cppVar_26186;
	bool cppVar_26187;
	BIT_VEC cppVar_26189;
	BIT_VEC cppVar_26190;
	BIT_VEC cppVar_26191;
	bool cppVar_26192;
	BIT_VEC cppVar_26194;
	BIT_VEC cppVar_26195;
	BIT_VEC cppVar_26196;
	bool cppVar_26197;
	BIT_VEC cppVar_26199;
	BIT_VEC cppVar_26200;
	BIT_VEC cppVar_26201;
	bool cppVar_26202;
	BIT_VEC cppVar_26204;
	BIT_VEC cppVar_26205;
	BIT_VEC cppVar_26206;
	bool cppVar_26207;
	BIT_VEC cppVar_26209;
	BIT_VEC cppVar_26210;
	BIT_VEC cppVar_26211;
	bool cppVar_26212;
	BIT_VEC cppVar_26214;
	BIT_VEC cppVar_26215;
	BIT_VEC cppVar_26216;
	bool cppVar_26217;
	BIT_VEC cppVar_26219;
	BIT_VEC cppVar_26220;
	BIT_VEC cppVar_26221;
	bool cppVar_26222;
	BIT_VEC cppVar_26224;
	BIT_VEC cppVar_26225;
	BIT_VEC cppVar_26226;
	bool cppVar_26227;
	BIT_VEC cppVar_26229;
	BIT_VEC cppVar_26230;
	BIT_VEC cppVar_26231;
	bool cppVar_26232;
	BIT_VEC cppVar_26234;
	BIT_VEC cppVar_26235;
	BIT_VEC cppVar_26236;
	bool cppVar_26237;
	BIT_VEC cppVar_26239;
	BIT_VEC cppVar_26240;
	BIT_VEC cppVar_26241;
	bool cppVar_26242;
	BIT_VEC cppVar_26244;
	BIT_VEC cppVar_26245;
	BIT_VEC cppVar_26246;
	bool cppVar_26247;
	BIT_VEC cppVar_26249;
	BIT_VEC cppVar_26250;
	BIT_VEC cppVar_26251;
	bool cppVar_26252;
	BIT_VEC cppVar_26254;
	BIT_VEC cppVar_26255;
	BIT_VEC cppVar_26256;
	bool cppVar_26257;
	BIT_VEC cppVar_26259;
	BIT_VEC cppVar_26260;
	BIT_VEC cppVar_26261;
	bool cppVar_26262;
	BIT_VEC cppVar_26263;
	BIT_VEC cppVar_26258;
	BIT_VEC cppVar_26253;
	BIT_VEC cppVar_26248;
	BIT_VEC cppVar_26243;
	BIT_VEC cppVar_26238;
	BIT_VEC cppVar_26233;
	BIT_VEC cppVar_26228;
	BIT_VEC cppVar_26223;
	BIT_VEC cppVar_26218;
	BIT_VEC cppVar_26213;
	BIT_VEC cppVar_26208;
	BIT_VEC cppVar_26203;
	BIT_VEC cppVar_26198;
	BIT_VEC cppVar_26193;
	BIT_VEC cppVar_26188;
	BIT_VEC cppVar_26183;
	BIT_VEC cppVar_26178;
	BIT_VEC cppVar_26173;
	BIT_VEC cppVar_26168;
	BIT_VEC cppVar_26163;
	BIT_VEC cppVar_26158;
	BIT_VEC cppVar_26149;
	BIT_VEC cppVar_26264;
	BIT_VEC cppVar_26265;
	BIT_VEC cppVar_26266;
	BIT_VEC cppVar_26267;
	BIT_VEC cppVar_26143;
	BIT_VEC cppVar_26269;
	BIT_VEC cppVar_26270;
	bool cppVar_26271;
	BIT_VEC cppVar_26273;
	BIT_VEC cppVar_26274;
	BIT_VEC cppVar_26275;
	BIT_VEC cppVar_26276;
	bool cppVar_26277;
	BIT_VEC cppVar_26279;
	BIT_VEC cppVar_26280;
	BIT_VEC cppVar_26281;
	BIT_VEC cppVar_26282;
	bool cppVar_26283;
	BIT_VEC cppVar_26284;
	BIT_VEC cppVar_26285;
	BIT_VEC cppVar_26286;
	BIT_VEC cppVar_26288;
	BIT_VEC cppVar_26289;
	BIT_VEC cppVar_26290;
	bool cppVar_26291;
	BIT_VEC cppVar_26293;
	BIT_VEC cppVar_26294;
	BIT_VEC cppVar_26295;
	bool cppVar_26296;
	BIT_VEC cppVar_26298;
	BIT_VEC cppVar_26299;
	BIT_VEC cppVar_26300;
	bool cppVar_26301;
	BIT_VEC cppVar_26303;
	BIT_VEC cppVar_26304;
	BIT_VEC cppVar_26305;
	bool cppVar_26306;
	BIT_VEC cppVar_26308;
	BIT_VEC cppVar_26309;
	BIT_VEC cppVar_26310;
	bool cppVar_26311;
	BIT_VEC cppVar_26313;
	BIT_VEC cppVar_26314;
	BIT_VEC cppVar_26315;
	bool cppVar_26316;
	BIT_VEC cppVar_26318;
	BIT_VEC cppVar_26319;
	BIT_VEC cppVar_26320;
	bool cppVar_26321;
	BIT_VEC cppVar_26323;
	BIT_VEC cppVar_26324;
	BIT_VEC cppVar_26325;
	bool cppVar_26326;
	BIT_VEC cppVar_26328;
	BIT_VEC cppVar_26329;
	BIT_VEC cppVar_26330;
	bool cppVar_26331;
	BIT_VEC cppVar_26333;
	BIT_VEC cppVar_26334;
	BIT_VEC cppVar_26335;
	bool cppVar_26336;
	BIT_VEC cppVar_26338;
	BIT_VEC cppVar_26339;
	BIT_VEC cppVar_26340;
	bool cppVar_26341;
	BIT_VEC cppVar_26343;
	BIT_VEC cppVar_26344;
	BIT_VEC cppVar_26345;
	bool cppVar_26346;
	BIT_VEC cppVar_26348;
	BIT_VEC cppVar_26349;
	BIT_VEC cppVar_26350;
	bool cppVar_26351;
	BIT_VEC cppVar_26353;
	BIT_VEC cppVar_26354;
	BIT_VEC cppVar_26355;
	bool cppVar_26356;
	BIT_VEC cppVar_26358;
	BIT_VEC cppVar_26359;
	BIT_VEC cppVar_26360;
	bool cppVar_26361;
	BIT_VEC cppVar_26363;
	BIT_VEC cppVar_26364;
	BIT_VEC cppVar_26365;
	bool cppVar_26366;
	BIT_VEC cppVar_26368;
	BIT_VEC cppVar_26369;
	BIT_VEC cppVar_26370;
	bool cppVar_26371;
	BIT_VEC cppVar_26373;
	BIT_VEC cppVar_26374;
	BIT_VEC cppVar_26375;
	bool cppVar_26376;
	BIT_VEC cppVar_26378;
	BIT_VEC cppVar_26379;
	BIT_VEC cppVar_26380;
	bool cppVar_26381;
	BIT_VEC cppVar_26383;
	BIT_VEC cppVar_26384;
	BIT_VEC cppVar_26385;
	bool cppVar_26386;
	BIT_VEC cppVar_26388;
	BIT_VEC cppVar_26389;
	BIT_VEC cppVar_26390;
	bool cppVar_26391;
	BIT_VEC cppVar_26392;
	BIT_VEC cppVar_26387;
	BIT_VEC cppVar_26382;
	BIT_VEC cppVar_26377;
	BIT_VEC cppVar_26372;
	BIT_VEC cppVar_26367;
	BIT_VEC cppVar_26362;
	BIT_VEC cppVar_26357;
	BIT_VEC cppVar_26352;
	BIT_VEC cppVar_26347;
	BIT_VEC cppVar_26342;
	BIT_VEC cppVar_26337;
	BIT_VEC cppVar_26332;
	BIT_VEC cppVar_26327;
	BIT_VEC cppVar_26322;
	BIT_VEC cppVar_26317;
	BIT_VEC cppVar_26312;
	BIT_VEC cppVar_26307;
	BIT_VEC cppVar_26302;
	BIT_VEC cppVar_26297;
	BIT_VEC cppVar_26292;
	BIT_VEC cppVar_26287;
	BIT_VEC cppVar_26278;
	BIT_VEC cppVar_26393;
	BIT_VEC cppVar_26272;
	BIT_VEC cppVar_26395;
	BIT_VEC cppVar_26396;
	bool cppVar_26397;
	BIT_VEC cppVar_26398;
	BIT_VEC cppVar_26399;
	bool cppVar_26400;
	bool cppVar_26401;
	BIT_VEC cppVar_26403;
	BIT_VEC cppVar_26404;
	BIT_VEC cppVar_26405;
	BIT_VEC cppVar_26406;
	bool cppVar_26407;
	BIT_VEC cppVar_26409;
	BIT_VEC cppVar_26410;
	BIT_VEC cppVar_26411;
	BIT_VEC cppVar_26412;
	bool cppVar_26413;
	BIT_VEC cppVar_26414;
	BIT_VEC cppVar_26415;
	BIT_VEC cppVar_26416;
	BIT_VEC cppVar_26418;
	BIT_VEC cppVar_26419;
	BIT_VEC cppVar_26420;
	bool cppVar_26421;
	BIT_VEC cppVar_26423;
	BIT_VEC cppVar_26424;
	BIT_VEC cppVar_26425;
	bool cppVar_26426;
	BIT_VEC cppVar_26428;
	BIT_VEC cppVar_26429;
	BIT_VEC cppVar_26430;
	bool cppVar_26431;
	BIT_VEC cppVar_26433;
	BIT_VEC cppVar_26434;
	BIT_VEC cppVar_26435;
	bool cppVar_26436;
	BIT_VEC cppVar_26438;
	BIT_VEC cppVar_26439;
	BIT_VEC cppVar_26440;
	bool cppVar_26441;
	BIT_VEC cppVar_26443;
	BIT_VEC cppVar_26444;
	BIT_VEC cppVar_26445;
	bool cppVar_26446;
	BIT_VEC cppVar_26448;
	BIT_VEC cppVar_26449;
	BIT_VEC cppVar_26450;
	bool cppVar_26451;
	BIT_VEC cppVar_26453;
	BIT_VEC cppVar_26454;
	BIT_VEC cppVar_26455;
	bool cppVar_26456;
	BIT_VEC cppVar_26458;
	BIT_VEC cppVar_26459;
	BIT_VEC cppVar_26460;
	bool cppVar_26461;
	BIT_VEC cppVar_26463;
	BIT_VEC cppVar_26464;
	BIT_VEC cppVar_26465;
	bool cppVar_26466;
	BIT_VEC cppVar_26468;
	BIT_VEC cppVar_26469;
	BIT_VEC cppVar_26470;
	bool cppVar_26471;
	BIT_VEC cppVar_26473;
	BIT_VEC cppVar_26474;
	BIT_VEC cppVar_26475;
	bool cppVar_26476;
	BIT_VEC cppVar_26478;
	BIT_VEC cppVar_26479;
	BIT_VEC cppVar_26480;
	bool cppVar_26481;
	BIT_VEC cppVar_26483;
	BIT_VEC cppVar_26484;
	BIT_VEC cppVar_26485;
	bool cppVar_26486;
	BIT_VEC cppVar_26488;
	BIT_VEC cppVar_26489;
	BIT_VEC cppVar_26490;
	bool cppVar_26491;
	BIT_VEC cppVar_26493;
	BIT_VEC cppVar_26494;
	BIT_VEC cppVar_26495;
	bool cppVar_26496;
	BIT_VEC cppVar_26498;
	BIT_VEC cppVar_26499;
	BIT_VEC cppVar_26500;
	bool cppVar_26501;
	BIT_VEC cppVar_26503;
	BIT_VEC cppVar_26504;
	BIT_VEC cppVar_26505;
	bool cppVar_26506;
	BIT_VEC cppVar_26508;
	BIT_VEC cppVar_26509;
	BIT_VEC cppVar_26510;
	bool cppVar_26511;
	BIT_VEC cppVar_26513;
	BIT_VEC cppVar_26514;
	BIT_VEC cppVar_26515;
	bool cppVar_26516;
	BIT_VEC cppVar_26518;
	BIT_VEC cppVar_26519;
	BIT_VEC cppVar_26520;
	bool cppVar_26521;
	BIT_VEC cppVar_26522;
	BIT_VEC cppVar_26517;
	BIT_VEC cppVar_26512;
	BIT_VEC cppVar_26507;
	BIT_VEC cppVar_26502;
	BIT_VEC cppVar_26497;
	BIT_VEC cppVar_26492;
	BIT_VEC cppVar_26487;
	BIT_VEC cppVar_26482;
	BIT_VEC cppVar_26477;
	BIT_VEC cppVar_26472;
	BIT_VEC cppVar_26467;
	BIT_VEC cppVar_26462;
	BIT_VEC cppVar_26457;
	BIT_VEC cppVar_26452;
	BIT_VEC cppVar_26447;
	BIT_VEC cppVar_26442;
	BIT_VEC cppVar_26437;
	BIT_VEC cppVar_26432;
	BIT_VEC cppVar_26427;
	BIT_VEC cppVar_26422;
	BIT_VEC cppVar_26417;
	BIT_VEC cppVar_26408;
	BIT_VEC cppVar_26523;
	BIT_VEC cppVar_26524;
	BIT_VEC cppVar_26402;
	BIT_VEC cppVar_26526;
	BIT_VEC cppVar_26527;
	bool cppVar_26528;
	BIT_VEC cppVar_26529;
	BIT_VEC cppVar_26530;
	bool cppVar_26531;
	bool cppVar_26532;
	BIT_VEC cppVar_26535;
	BIT_VEC cppVar_26536;
	BIT_VEC cppVar_26537;
	BIT_VEC cppVar_26538;
	BIT_VEC cppVar_26539;
	bool cppVar_26540;
	BIT_VEC cppVar_26541;
	BIT_VEC cppVar_26542;
	BIT_VEC cppVar_26543;
	BIT_VEC cppVar_26544;
	BIT_VEC cppVar_26545;
	BIT_VEC cppVar_26546;
	BIT_VEC cppVar_26547;
	BIT_VEC cppVar_26548;
	BIT_VEC cppVar_26549;
	BIT_VEC cppVar_26550;
	BIT_VEC cppVar_26551;
	BIT_VEC cppVar_26534;
	BIT_VEC cppVar_26552;
	bool cppVar_26553;
	BIT_VEC cppVar_26554;
	BIT_VEC cppVar_26555;
	BIT_VEC cppVar_26556;
	BIT_VEC cppVar_26557;
	BIT_VEC cppVar_26558;
	BIT_VEC cppVar_26559;
	BIT_VEC cppVar_26560;
	BIT_VEC cppVar_26563;
	BIT_VEC cppVar_26564;
	BIT_VEC cppVar_26565;
	bool cppVar_26566;
	BIT_VEC cppVar_26567;
	BIT_VEC cppVar_26568;
	BIT_VEC cppVar_26569;
	BIT_VEC cppVar_26570;
	BIT_VEC cppVar_26571;
	BIT_VEC cppVar_26572;
	BIT_VEC cppVar_26573;
	BIT_VEC cppVar_26574;
	BIT_VEC cppVar_26575;
	BIT_VEC cppVar_26562;
	BIT_VEC cppVar_26576;
	BIT_VEC cppVar_26577;
	bool cppVar_26578;
	BIT_VEC cppVar_26580;
	BIT_VEC cppVar_26581;
	BIT_VEC cppVar_26582;
	bool cppVar_26583;
	BIT_VEC cppVar_26584;
	BIT_VEC cppVar_26585;
	BIT_VEC cppVar_26586;
	BIT_VEC cppVar_26587;
	BIT_VEC cppVar_26588;
	BIT_VEC cppVar_26589;
	BIT_VEC cppVar_26590;
	BIT_VEC cppVar_26591;
	BIT_VEC cppVar_26592;
	BIT_VEC cppVar_26579;
	BIT_VEC cppVar_26593;
	BIT_VEC cppVar_26596;
	BIT_VEC cppVar_26597;
	BIT_VEC cppVar_26598;
	bool cppVar_26599;
	BIT_VEC cppVar_26600;
	BIT_VEC cppVar_26601;
	BIT_VEC cppVar_26602;
	BIT_VEC cppVar_26603;
	BIT_VEC cppVar_26604;
	BIT_VEC cppVar_26605;
	BIT_VEC cppVar_26606;
	BIT_VEC cppVar_26607;
	BIT_VEC cppVar_26608;
	BIT_VEC cppVar_26595;
	BIT_VEC cppVar_26609;
	bool cppVar_26610;
	BIT_VEC cppVar_26613;
	BIT_VEC cppVar_26614;
	BIT_VEC cppVar_26615;
	bool cppVar_26616;
	BIT_VEC cppVar_26617;
	BIT_VEC cppVar_26618;
	BIT_VEC cppVar_26619;
	BIT_VEC cppVar_26620;
	BIT_VEC cppVar_26621;
	BIT_VEC cppVar_26622;
	BIT_VEC cppVar_26623;
	BIT_VEC cppVar_26624;
	BIT_VEC cppVar_26625;
	BIT_VEC cppVar_26612;
	BIT_VEC cppVar_26626;
	bool cppVar_26627;
	BIT_VEC cppVar_26630;
	BIT_VEC cppVar_26631;
	BIT_VEC cppVar_26632;
	bool cppVar_26633;
	BIT_VEC cppVar_26634;
	BIT_VEC cppVar_26635;
	BIT_VEC cppVar_26636;
	BIT_VEC cppVar_26637;
	BIT_VEC cppVar_26638;
	BIT_VEC cppVar_26639;
	BIT_VEC cppVar_26640;
	BIT_VEC cppVar_26641;
	BIT_VEC cppVar_26642;
	BIT_VEC cppVar_26629;
	BIT_VEC cppVar_26643;
	bool cppVar_26644;
	BIT_VEC cppVar_26647;
	BIT_VEC cppVar_26648;
	BIT_VEC cppVar_26649;
	bool cppVar_26650;
	BIT_VEC cppVar_26651;
	BIT_VEC cppVar_26652;
	BIT_VEC cppVar_26653;
	BIT_VEC cppVar_26654;
	BIT_VEC cppVar_26655;
	BIT_VEC cppVar_26656;
	BIT_VEC cppVar_26657;
	BIT_VEC cppVar_26658;
	BIT_VEC cppVar_26659;
	BIT_VEC cppVar_26646;
	BIT_VEC cppVar_26660;
	bool cppVar_26661;
	BIT_VEC cppVar_26664;
	BIT_VEC cppVar_26665;
	BIT_VEC cppVar_26666;
	bool cppVar_26667;
	BIT_VEC cppVar_26668;
	BIT_VEC cppVar_26669;
	BIT_VEC cppVar_26670;
	BIT_VEC cppVar_26671;
	BIT_VEC cppVar_26672;
	BIT_VEC cppVar_26673;
	BIT_VEC cppVar_26674;
	BIT_VEC cppVar_26675;
	BIT_VEC cppVar_26676;
	BIT_VEC cppVar_26663;
	BIT_VEC cppVar_26677;
	bool cppVar_26678;
	BIT_VEC cppVar_26681;
	BIT_VEC cppVar_26682;
	BIT_VEC cppVar_26683;
	bool cppVar_26684;
	BIT_VEC cppVar_26685;
	BIT_VEC cppVar_26686;
	BIT_VEC cppVar_26687;
	BIT_VEC cppVar_26688;
	BIT_VEC cppVar_26689;
	BIT_VEC cppVar_26690;
	BIT_VEC cppVar_26691;
	BIT_VEC cppVar_26692;
	BIT_VEC cppVar_26693;
	BIT_VEC cppVar_26680;
	BIT_VEC cppVar_26694;
	bool cppVar_26695;
	BIT_VEC cppVar_26698;
	BIT_VEC cppVar_26699;
	BIT_VEC cppVar_26700;
	bool cppVar_26701;
	BIT_VEC cppVar_26702;
	BIT_VEC cppVar_26703;
	BIT_VEC cppVar_26704;
	BIT_VEC cppVar_26705;
	BIT_VEC cppVar_26706;
	BIT_VEC cppVar_26707;
	BIT_VEC cppVar_26708;
	BIT_VEC cppVar_26709;
	BIT_VEC cppVar_26710;
	BIT_VEC cppVar_26697;
	BIT_VEC cppVar_26711;
	bool cppVar_26712;
	BIT_VEC cppVar_26715;
	BIT_VEC cppVar_26716;
	BIT_VEC cppVar_26717;
	bool cppVar_26718;
	BIT_VEC cppVar_26719;
	BIT_VEC cppVar_26720;
	BIT_VEC cppVar_26721;
	BIT_VEC cppVar_26722;
	BIT_VEC cppVar_26723;
	BIT_VEC cppVar_26724;
	BIT_VEC cppVar_26725;
	BIT_VEC cppVar_26726;
	BIT_VEC cppVar_26727;
	BIT_VEC cppVar_26714;
	BIT_VEC cppVar_26728;
	bool cppVar_26729;
	BIT_VEC cppVar_26732;
	BIT_VEC cppVar_26733;
	BIT_VEC cppVar_26734;
	bool cppVar_26735;
	BIT_VEC cppVar_26736;
	BIT_VEC cppVar_26737;
	BIT_VEC cppVar_26738;
	BIT_VEC cppVar_26739;
	BIT_VEC cppVar_26740;
	BIT_VEC cppVar_26741;
	BIT_VEC cppVar_26742;
	BIT_VEC cppVar_26743;
	BIT_VEC cppVar_26744;
	BIT_VEC cppVar_26731;
	BIT_VEC cppVar_26745;
	bool cppVar_26746;
	BIT_VEC cppVar_26749;
	BIT_VEC cppVar_26750;
	BIT_VEC cppVar_26751;
	bool cppVar_26752;
	BIT_VEC cppVar_26753;
	BIT_VEC cppVar_26754;
	BIT_VEC cppVar_26755;
	BIT_VEC cppVar_26756;
	BIT_VEC cppVar_26757;
	BIT_VEC cppVar_26758;
	BIT_VEC cppVar_26759;
	BIT_VEC cppVar_26760;
	BIT_VEC cppVar_26761;
	BIT_VEC cppVar_26748;
	BIT_VEC cppVar_26762;
	bool cppVar_26763;
	BIT_VEC cppVar_26766;
	BIT_VEC cppVar_26767;
	BIT_VEC cppVar_26768;
	bool cppVar_26769;
	BIT_VEC cppVar_26770;
	BIT_VEC cppVar_26771;
	BIT_VEC cppVar_26772;
	BIT_VEC cppVar_26773;
	BIT_VEC cppVar_26774;
	BIT_VEC cppVar_26775;
	BIT_VEC cppVar_26776;
	BIT_VEC cppVar_26777;
	BIT_VEC cppVar_26778;
	BIT_VEC cppVar_26765;
	BIT_VEC cppVar_26779;
	bool cppVar_26780;
	BIT_VEC cppVar_26783;
	BIT_VEC cppVar_26784;
	BIT_VEC cppVar_26785;
	bool cppVar_26786;
	BIT_VEC cppVar_26787;
	BIT_VEC cppVar_26788;
	BIT_VEC cppVar_26789;
	BIT_VEC cppVar_26790;
	BIT_VEC cppVar_26791;
	BIT_VEC cppVar_26792;
	BIT_VEC cppVar_26793;
	BIT_VEC cppVar_26794;
	BIT_VEC cppVar_26795;
	BIT_VEC cppVar_26782;
	BIT_VEC cppVar_26796;
	bool cppVar_26797;
	BIT_VEC cppVar_26800;
	BIT_VEC cppVar_26801;
	BIT_VEC cppVar_26802;
	bool cppVar_26803;
	BIT_VEC cppVar_26804;
	BIT_VEC cppVar_26805;
	BIT_VEC cppVar_26806;
	BIT_VEC cppVar_26807;
	BIT_VEC cppVar_26808;
	BIT_VEC cppVar_26809;
	BIT_VEC cppVar_26810;
	BIT_VEC cppVar_26811;
	BIT_VEC cppVar_26812;
	BIT_VEC cppVar_26799;
	BIT_VEC cppVar_26813;
	bool cppVar_26814;
	BIT_VEC cppVar_26817;
	BIT_VEC cppVar_26818;
	BIT_VEC cppVar_26819;
	bool cppVar_26820;
	BIT_VEC cppVar_26821;
	BIT_VEC cppVar_26822;
	BIT_VEC cppVar_26823;
	BIT_VEC cppVar_26824;
	BIT_VEC cppVar_26825;
	BIT_VEC cppVar_26826;
	BIT_VEC cppVar_26827;
	BIT_VEC cppVar_26828;
	BIT_VEC cppVar_26829;
	BIT_VEC cppVar_26816;
	BIT_VEC cppVar_26830;
	bool cppVar_26831;
	BIT_VEC cppVar_26834;
	BIT_VEC cppVar_26835;
	BIT_VEC cppVar_26836;
	bool cppVar_26837;
	BIT_VEC cppVar_26838;
	BIT_VEC cppVar_26839;
	BIT_VEC cppVar_26840;
	BIT_VEC cppVar_26841;
	BIT_VEC cppVar_26842;
	BIT_VEC cppVar_26843;
	BIT_VEC cppVar_26844;
	BIT_VEC cppVar_26845;
	BIT_VEC cppVar_26846;
	BIT_VEC cppVar_26833;
	BIT_VEC cppVar_26847;
	bool cppVar_26848;
	BIT_VEC cppVar_26851;
	BIT_VEC cppVar_26852;
	BIT_VEC cppVar_26853;
	bool cppVar_26854;
	BIT_VEC cppVar_26855;
	BIT_VEC cppVar_26856;
	BIT_VEC cppVar_26857;
	BIT_VEC cppVar_26858;
	BIT_VEC cppVar_26859;
	BIT_VEC cppVar_26860;
	BIT_VEC cppVar_26861;
	BIT_VEC cppVar_26862;
	BIT_VEC cppVar_26863;
	BIT_VEC cppVar_26850;
	BIT_VEC cppVar_26864;
	bool cppVar_26865;
	BIT_VEC cppVar_26868;
	BIT_VEC cppVar_26869;
	BIT_VEC cppVar_26870;
	bool cppVar_26871;
	BIT_VEC cppVar_26872;
	BIT_VEC cppVar_26873;
	BIT_VEC cppVar_26874;
	BIT_VEC cppVar_26875;
	BIT_VEC cppVar_26876;
	BIT_VEC cppVar_26877;
	BIT_VEC cppVar_26878;
	BIT_VEC cppVar_26879;
	BIT_VEC cppVar_26880;
	BIT_VEC cppVar_26867;
	BIT_VEC cppVar_26881;
	bool cppVar_26882;
	BIT_VEC cppVar_26885;
	BIT_VEC cppVar_26886;
	BIT_VEC cppVar_26887;
	bool cppVar_26888;
	BIT_VEC cppVar_26889;
	BIT_VEC cppVar_26890;
	BIT_VEC cppVar_26891;
	BIT_VEC cppVar_26892;
	BIT_VEC cppVar_26893;
	BIT_VEC cppVar_26894;
	BIT_VEC cppVar_26895;
	BIT_VEC cppVar_26896;
	BIT_VEC cppVar_26897;
	BIT_VEC cppVar_26884;
	BIT_VEC cppVar_26898;
	bool cppVar_26899;
	BIT_VEC cppVar_26902;
	BIT_VEC cppVar_26903;
	BIT_VEC cppVar_26904;
	bool cppVar_26905;
	BIT_VEC cppVar_26906;
	BIT_VEC cppVar_26907;
	BIT_VEC cppVar_26908;
	BIT_VEC cppVar_26909;
	BIT_VEC cppVar_26910;
	BIT_VEC cppVar_26911;
	BIT_VEC cppVar_26912;
	BIT_VEC cppVar_26913;
	BIT_VEC cppVar_26914;
	BIT_VEC cppVar_26901;
	BIT_VEC cppVar_26915;
	bool cppVar_26916;
	BIT_VEC cppVar_26919;
	BIT_VEC cppVar_26920;
	BIT_VEC cppVar_26921;
	bool cppVar_26922;
	BIT_VEC cppVar_26923;
	BIT_VEC cppVar_26924;
	BIT_VEC cppVar_26925;
	BIT_VEC cppVar_26926;
	BIT_VEC cppVar_26927;
	BIT_VEC cppVar_26928;
	BIT_VEC cppVar_26929;
	BIT_VEC cppVar_26930;
	BIT_VEC cppVar_26931;
	BIT_VEC cppVar_26918;
	BIT_VEC cppVar_26932;
	bool cppVar_26933;
	BIT_VEC cppVar_26936;
	BIT_VEC cppVar_26937;
	BIT_VEC cppVar_26938;
	bool cppVar_26939;
	BIT_VEC cppVar_26940;
	BIT_VEC cppVar_26941;
	BIT_VEC cppVar_26942;
	BIT_VEC cppVar_26943;
	BIT_VEC cppVar_26944;
	BIT_VEC cppVar_26945;
	BIT_VEC cppVar_26946;
	BIT_VEC cppVar_26947;
	BIT_VEC cppVar_26948;
	BIT_VEC cppVar_26935;
	BIT_VEC cppVar_26949;
	bool cppVar_26950;
	BIT_VEC cppVar_26951;
	BIT_VEC cppVar_26934;
	BIT_VEC cppVar_26917;
	BIT_VEC cppVar_26900;
	BIT_VEC cppVar_26883;
	BIT_VEC cppVar_26866;
	BIT_VEC cppVar_26849;
	BIT_VEC cppVar_26832;
	BIT_VEC cppVar_26815;
	BIT_VEC cppVar_26798;
	BIT_VEC cppVar_26781;
	BIT_VEC cppVar_26764;
	BIT_VEC cppVar_26747;
	BIT_VEC cppVar_26730;
	BIT_VEC cppVar_26713;
	BIT_VEC cppVar_26696;
	BIT_VEC cppVar_26679;
	BIT_VEC cppVar_26662;
	BIT_VEC cppVar_26645;
	BIT_VEC cppVar_26628;
	BIT_VEC cppVar_26611;
	BIT_VEC cppVar_26594;
	BIT_VEC cppVar_26561;
	BIT_VEC cppVar_26952;
	BIT_VEC cppVar_26953;
	BIT_VEC cppVar_26954;
	BIT_VEC cppVar_26955;
	BIT_VEC cppVar_26956;
	BIT_VEC cppVar_26957;
	BIT_VEC cppVar_26958;
	BIT_VEC cppVar_26959;
	BIT_VEC cppVar_26960;
	BIT_VEC cppVar_26533;
	BIT_VEC cppVar_26962;
	BIT_VEC cppVar_26963;
	bool cppVar_26964;
	BIT_VEC cppVar_26966;
	BIT_VEC cppVar_26967;
	BIT_VEC cppVar_26968;
	BIT_VEC cppVar_26969;
	bool cppVar_26970;
	BIT_VEC cppVar_26972;
	BIT_VEC cppVar_26973;
	BIT_VEC cppVar_26974;
	BIT_VEC cppVar_26975;
	bool cppVar_26976;
	BIT_VEC cppVar_26977;
	BIT_VEC cppVar_26978;
	BIT_VEC cppVar_26979;
	BIT_VEC cppVar_26981;
	BIT_VEC cppVar_26982;
	BIT_VEC cppVar_26983;
	bool cppVar_26984;
	BIT_VEC cppVar_26986;
	BIT_VEC cppVar_26987;
	BIT_VEC cppVar_26988;
	bool cppVar_26989;
	BIT_VEC cppVar_26991;
	BIT_VEC cppVar_26992;
	BIT_VEC cppVar_26993;
	bool cppVar_26994;
	BIT_VEC cppVar_26996;
	BIT_VEC cppVar_26997;
	BIT_VEC cppVar_26998;
	bool cppVar_26999;
	BIT_VEC cppVar_27001;
	BIT_VEC cppVar_27002;
	BIT_VEC cppVar_27003;
	bool cppVar_27004;
	BIT_VEC cppVar_27006;
	BIT_VEC cppVar_27007;
	BIT_VEC cppVar_27008;
	bool cppVar_27009;
	BIT_VEC cppVar_27011;
	BIT_VEC cppVar_27012;
	BIT_VEC cppVar_27013;
	bool cppVar_27014;
	BIT_VEC cppVar_27016;
	BIT_VEC cppVar_27017;
	BIT_VEC cppVar_27018;
	bool cppVar_27019;
	BIT_VEC cppVar_27021;
	BIT_VEC cppVar_27022;
	BIT_VEC cppVar_27023;
	bool cppVar_27024;
	BIT_VEC cppVar_27026;
	BIT_VEC cppVar_27027;
	BIT_VEC cppVar_27028;
	bool cppVar_27029;
	BIT_VEC cppVar_27031;
	BIT_VEC cppVar_27032;
	BIT_VEC cppVar_27033;
	bool cppVar_27034;
	BIT_VEC cppVar_27036;
	BIT_VEC cppVar_27037;
	BIT_VEC cppVar_27038;
	bool cppVar_27039;
	BIT_VEC cppVar_27041;
	BIT_VEC cppVar_27042;
	BIT_VEC cppVar_27043;
	bool cppVar_27044;
	BIT_VEC cppVar_27046;
	BIT_VEC cppVar_27047;
	BIT_VEC cppVar_27048;
	bool cppVar_27049;
	BIT_VEC cppVar_27051;
	BIT_VEC cppVar_27052;
	BIT_VEC cppVar_27053;
	bool cppVar_27054;
	BIT_VEC cppVar_27056;
	BIT_VEC cppVar_27057;
	BIT_VEC cppVar_27058;
	bool cppVar_27059;
	BIT_VEC cppVar_27061;
	BIT_VEC cppVar_27062;
	BIT_VEC cppVar_27063;
	bool cppVar_27064;
	BIT_VEC cppVar_27066;
	BIT_VEC cppVar_27067;
	BIT_VEC cppVar_27068;
	bool cppVar_27069;
	BIT_VEC cppVar_27071;
	BIT_VEC cppVar_27072;
	BIT_VEC cppVar_27073;
	bool cppVar_27074;
	BIT_VEC cppVar_27076;
	BIT_VEC cppVar_27077;
	BIT_VEC cppVar_27078;
	bool cppVar_27079;
	BIT_VEC cppVar_27081;
	BIT_VEC cppVar_27082;
	BIT_VEC cppVar_27083;
	bool cppVar_27084;
	BIT_VEC cppVar_27085;
	BIT_VEC cppVar_27080;
	BIT_VEC cppVar_27075;
	BIT_VEC cppVar_27070;
	BIT_VEC cppVar_27065;
	BIT_VEC cppVar_27060;
	BIT_VEC cppVar_27055;
	BIT_VEC cppVar_27050;
	BIT_VEC cppVar_27045;
	BIT_VEC cppVar_27040;
	BIT_VEC cppVar_27035;
	BIT_VEC cppVar_27030;
	BIT_VEC cppVar_27025;
	BIT_VEC cppVar_27020;
	BIT_VEC cppVar_27015;
	BIT_VEC cppVar_27010;
	BIT_VEC cppVar_27005;
	BIT_VEC cppVar_27000;
	BIT_VEC cppVar_26995;
	BIT_VEC cppVar_26990;
	BIT_VEC cppVar_26985;
	BIT_VEC cppVar_26980;
	BIT_VEC cppVar_26971;
	BIT_VEC cppVar_27086;
	BIT_VEC cppVar_27087;
	BIT_VEC cppVar_26965;
	BIT_VEC cppVar_26961;
	BIT_VEC cppVar_26525;
	BIT_VEC cppVar_26394;
	BIT_VEC cppVar_26268;
	BIT_VEC cppVar_26139;
	BIT_VEC cppVar_26013;
	BIT_VEC cppVar_25884;
	BIT_VEC cppVar_25758;
	BIT_VEC cppVar_25629;
	BIT_VEC cppVar_25616;
	BIT_VEC cppVar_25490;
	BIT_VEC cppVar_25473;
	BIT_VEC cppVar_25456;
	BIT_VEC cppVar_25306;
	BIT_VEC cppVar_25156;
	BIT_VEC cppVar_25006;
	BIT_VEC cppVar_24856;
	BIT_VEC cppVar_24706;
	BIT_VEC cppVar_24556;
	BIT_VEC cppVar_24406;
	BIT_VEC cppVar_24256;
	BIT_VEC cppVar_23824;
	BIT_VEC cppVar_22994;
	BIT_VEC cppVar_22980;
	BIT_VEC cppVar_22969;
	BIT_VEC cppVar_22537;
	cppVar_22538 = ROM.rd(PC);
	cppVar_22540 = (cppVar_22538 == 210);
	if (cppVar_22540) {
	cppVar_22544 = PC + 1;
	cppVar_22544 = (cppVar_22544 & cppMask_un_16_);
	cppVar_22545 = ROM.rd(cppVar_22544);
	cppVar_22546 = (cppVar_22545 >> 7) & cppMask_un_1_;
	cppVar_22548 = (cppVar_22546 == 1);
	if (cppVar_22548) {
	cppVar_22549 = PC + 1;
	cppVar_22549 = (cppVar_22549 & cppMask_un_16_);
	cppVar_22550 = ROM.rd(cppVar_22549);
	cppVar_22551 = (cppVar_22550 >> 3) & cppMask_un_5_;
	cppVar_22553 = (cppVar_22551 << 3) | 0;
	cppVar_22553 = (cppVar_22553 & cppMask_un_8_);
	cppVar_22542 = cppVar_22553;
	} else {
	cppVar_22554 = PC + 1;
	cppVar_22554 = (cppVar_22554 & cppMask_un_16_);
	cppVar_22555 = ROM.rd(cppVar_22554);
	cppVar_22556 = (cppVar_22555 >> 3) & cppMask_un_5_;
	cppVar_22557 = (cppVar_22556 & cppMask_un_5_);
	cppVar_22559 = cppVar_22557 + 32;
	cppVar_22559 = (cppVar_22559 & cppMask_un_8_);
	cppVar_22542 = cppVar_22559;
	}
	cppVar_22561 = (cppVar_22542 == 128);
	if (cppVar_22561) {
	cppVar_22563 = PC + 1;
	cppVar_22563 = (cppVar_22563 & cppMask_un_16_);
	cppVar_22564 = ROM.rd(cppVar_22563);
	cppVar_22565 = (cppVar_22564 >> 0) & cppMask_un_3_;
	cppVar_22566 = (cppVar_22565 & cppMask_un_3_);
	cppVar_22567 = 1 << static_cast<unsigned>(cppVar_22566);
	cppVar_22567 = (cppVar_22567 & cppMask_un_8_);
	cppVar_22568 = ~cppVar_22567;
	cppVar_22571 = PC + 1;
	cppVar_22571 = (cppVar_22571 & cppMask_un_16_);
	cppVar_22572 = ROM.rd(cppVar_22571);
	cppVar_22573 = (cppVar_22572 >> 7) & cppMask_un_1_;
	cppVar_22574 = (cppVar_22573 == 1);
	if (cppVar_22574) {
	cppVar_22575 = PC + 1;
	cppVar_22575 = (cppVar_22575 & cppMask_un_16_);
	cppVar_22576 = ROM.rd(cppVar_22575);
	cppVar_22577 = (cppVar_22576 >> 3) & cppMask_un_5_;
	cppVar_22578 = (cppVar_22577 << 3) | 0;
	cppVar_22578 = (cppVar_22578 & cppMask_un_8_);
	cppVar_22570 = cppVar_22578;
	} else {
	cppVar_22579 = PC + 1;
	cppVar_22579 = (cppVar_22579 & cppMask_un_16_);
	cppVar_22580 = ROM.rd(cppVar_22579);
	cppVar_22581 = (cppVar_22580 >> 3) & cppMask_un_5_;
	cppVar_22582 = (cppVar_22581 & cppMask_un_5_);
	cppVar_22583 = cppVar_22582 + 32;
	cppVar_22583 = (cppVar_22583 & cppMask_un_8_);
	cppVar_22570 = cppVar_22583;
	}
	cppVar_22584 = (cppVar_22570 >> 7) & cppMask_un_1_;
	cppVar_22586 = (cppVar_22584 == 0);
	if (cppVar_22586) {
	cppVar_22588 = PC + 1;
	cppVar_22588 = (cppVar_22588 & cppMask_un_16_);
	cppVar_22589 = ROM.rd(cppVar_22588);
	cppVar_22590 = (cppVar_22589 >> 7) & cppMask_un_1_;
	cppVar_22591 = (cppVar_22590 == 1);
	if (cppVar_22591) {
	cppVar_22592 = PC + 1;
	cppVar_22592 = (cppVar_22592 & cppMask_un_16_);
	cppVar_22593 = ROM.rd(cppVar_22592);
	cppVar_22594 = (cppVar_22593 >> 3) & cppMask_un_5_;
	cppVar_22595 = (cppVar_22594 << 3) | 0;
	cppVar_22595 = (cppVar_22595 & cppMask_un_8_);
	cppVar_22587 = cppVar_22595;
	} else {
	cppVar_22596 = PC + 1;
	cppVar_22596 = (cppVar_22596 & cppMask_un_16_);
	cppVar_22597 = ROM.rd(cppVar_22596);
	cppVar_22598 = (cppVar_22597 >> 3) & cppMask_un_5_;
	cppVar_22599 = (cppVar_22598 & cppMask_un_5_);
	cppVar_22600 = cppVar_22599 + 32;
	cppVar_22600 = (cppVar_22600 & cppMask_un_8_);
	cppVar_22587 = cppVar_22600;
	}
	cppVar_22601 = IRAM.rd(cppVar_22587);
	cppVar_22569 = cppVar_22601;
	} else {
	cppVar_22604 = PC + 1;
	cppVar_22604 = (cppVar_22604 & cppMask_un_16_);
	cppVar_22605 = ROM.rd(cppVar_22604);
	cppVar_22606 = (cppVar_22605 >> 7) & cppMask_un_1_;
	cppVar_22607 = (cppVar_22606 == 1);
	if (cppVar_22607) {
	cppVar_22608 = PC + 1;
	cppVar_22608 = (cppVar_22608 & cppMask_un_16_);
	cppVar_22609 = ROM.rd(cppVar_22608);
	cppVar_22610 = (cppVar_22609 >> 3) & cppMask_un_5_;
	cppVar_22611 = (cppVar_22610 << 3) | 0;
	cppVar_22611 = (cppVar_22611 & cppMask_un_8_);
	cppVar_22603 = cppVar_22611;
	} else {
	cppVar_22612 = PC + 1;
	cppVar_22612 = (cppVar_22612 & cppMask_un_16_);
	cppVar_22613 = ROM.rd(cppVar_22612);
	cppVar_22614 = (cppVar_22613 >> 3) & cppMask_un_5_;
	cppVar_22615 = (cppVar_22614 & cppMask_un_5_);
	cppVar_22616 = cppVar_22615 + 32;
	cppVar_22616 = (cppVar_22616 & cppMask_un_8_);
	cppVar_22603 = cppVar_22616;
	}
	cppVar_22618 = (cppVar_22603 == 128);
	if (cppVar_22618) {
	cppVar_22602 = P0;
	} else {
	cppVar_22621 = PC + 1;
	cppVar_22621 = (cppVar_22621 & cppMask_un_16_);
	cppVar_22622 = ROM.rd(cppVar_22621);
	cppVar_22623 = (cppVar_22622 >> 7) & cppMask_un_1_;
	cppVar_22624 = (cppVar_22623 == 1);
	if (cppVar_22624) {
	cppVar_22625 = PC + 1;
	cppVar_22625 = (cppVar_22625 & cppMask_un_16_);
	cppVar_22626 = ROM.rd(cppVar_22625);
	cppVar_22627 = (cppVar_22626 >> 3) & cppMask_un_5_;
	cppVar_22628 = (cppVar_22627 << 3) | 0;
	cppVar_22628 = (cppVar_22628 & cppMask_un_8_);
	cppVar_22620 = cppVar_22628;
	} else {
	cppVar_22629 = PC + 1;
	cppVar_22629 = (cppVar_22629 & cppMask_un_16_);
	cppVar_22630 = ROM.rd(cppVar_22629);
	cppVar_22631 = (cppVar_22630 >> 3) & cppMask_un_5_;
	cppVar_22632 = (cppVar_22631 & cppMask_un_5_);
	cppVar_22633 = cppVar_22632 + 32;
	cppVar_22633 = (cppVar_22633 & cppMask_un_8_);
	cppVar_22620 = cppVar_22633;
	}
	cppVar_22635 = (cppVar_22620 == 129);
	if (cppVar_22635) {
	cppVar_22619 = SP;
	} else {
	cppVar_22638 = PC + 1;
	cppVar_22638 = (cppVar_22638 & cppMask_un_16_);
	cppVar_22639 = ROM.rd(cppVar_22638);
	cppVar_22640 = (cppVar_22639 >> 7) & cppMask_un_1_;
	cppVar_22641 = (cppVar_22640 == 1);
	if (cppVar_22641) {
	cppVar_22642 = PC + 1;
	cppVar_22642 = (cppVar_22642 & cppMask_un_16_);
	cppVar_22643 = ROM.rd(cppVar_22642);
	cppVar_22644 = (cppVar_22643 >> 3) & cppMask_un_5_;
	cppVar_22645 = (cppVar_22644 << 3) | 0;
	cppVar_22645 = (cppVar_22645 & cppMask_un_8_);
	cppVar_22637 = cppVar_22645;
	} else {
	cppVar_22646 = PC + 1;
	cppVar_22646 = (cppVar_22646 & cppMask_un_16_);
	cppVar_22647 = ROM.rd(cppVar_22646);
	cppVar_22648 = (cppVar_22647 >> 3) & cppMask_un_5_;
	cppVar_22649 = (cppVar_22648 & cppMask_un_5_);
	cppVar_22650 = cppVar_22649 + 32;
	cppVar_22650 = (cppVar_22650 & cppMask_un_8_);
	cppVar_22637 = cppVar_22650;
	}
	cppVar_22652 = (cppVar_22637 == 130);
	if (cppVar_22652) {
	cppVar_22636 = DPL;
	} else {
	cppVar_22655 = PC + 1;
	cppVar_22655 = (cppVar_22655 & cppMask_un_16_);
	cppVar_22656 = ROM.rd(cppVar_22655);
	cppVar_22657 = (cppVar_22656 >> 7) & cppMask_un_1_;
	cppVar_22658 = (cppVar_22657 == 1);
	if (cppVar_22658) {
	cppVar_22659 = PC + 1;
	cppVar_22659 = (cppVar_22659 & cppMask_un_16_);
	cppVar_22660 = ROM.rd(cppVar_22659);
	cppVar_22661 = (cppVar_22660 >> 3) & cppMask_un_5_;
	cppVar_22662 = (cppVar_22661 << 3) | 0;
	cppVar_22662 = (cppVar_22662 & cppMask_un_8_);
	cppVar_22654 = cppVar_22662;
	} else {
	cppVar_22663 = PC + 1;
	cppVar_22663 = (cppVar_22663 & cppMask_un_16_);
	cppVar_22664 = ROM.rd(cppVar_22663);
	cppVar_22665 = (cppVar_22664 >> 3) & cppMask_un_5_;
	cppVar_22666 = (cppVar_22665 & cppMask_un_5_);
	cppVar_22667 = cppVar_22666 + 32;
	cppVar_22667 = (cppVar_22667 & cppMask_un_8_);
	cppVar_22654 = cppVar_22667;
	}
	cppVar_22669 = (cppVar_22654 == 131);
	if (cppVar_22669) {
	cppVar_22653 = DPH;
	} else {
	cppVar_22672 = PC + 1;
	cppVar_22672 = (cppVar_22672 & cppMask_un_16_);
	cppVar_22673 = ROM.rd(cppVar_22672);
	cppVar_22674 = (cppVar_22673 >> 7) & cppMask_un_1_;
	cppVar_22675 = (cppVar_22674 == 1);
	if (cppVar_22675) {
	cppVar_22676 = PC + 1;
	cppVar_22676 = (cppVar_22676 & cppMask_un_16_);
	cppVar_22677 = ROM.rd(cppVar_22676);
	cppVar_22678 = (cppVar_22677 >> 3) & cppMask_un_5_;
	cppVar_22679 = (cppVar_22678 << 3) | 0;
	cppVar_22679 = (cppVar_22679 & cppMask_un_8_);
	cppVar_22671 = cppVar_22679;
	} else {
	cppVar_22680 = PC + 1;
	cppVar_22680 = (cppVar_22680 & cppMask_un_16_);
	cppVar_22681 = ROM.rd(cppVar_22680);
	cppVar_22682 = (cppVar_22681 >> 3) & cppMask_un_5_;
	cppVar_22683 = (cppVar_22682 & cppMask_un_5_);
	cppVar_22684 = cppVar_22683 + 32;
	cppVar_22684 = (cppVar_22684 & cppMask_un_8_);
	cppVar_22671 = cppVar_22684;
	}
	cppVar_22686 = (cppVar_22671 == 135);
	if (cppVar_22686) {
	cppVar_22670 = PCON;
	} else {
	cppVar_22689 = PC + 1;
	cppVar_22689 = (cppVar_22689 & cppMask_un_16_);
	cppVar_22690 = ROM.rd(cppVar_22689);
	cppVar_22691 = (cppVar_22690 >> 7) & cppMask_un_1_;
	cppVar_22692 = (cppVar_22691 == 1);
	if (cppVar_22692) {
	cppVar_22693 = PC + 1;
	cppVar_22693 = (cppVar_22693 & cppMask_un_16_);
	cppVar_22694 = ROM.rd(cppVar_22693);
	cppVar_22695 = (cppVar_22694 >> 3) & cppMask_un_5_;
	cppVar_22696 = (cppVar_22695 << 3) | 0;
	cppVar_22696 = (cppVar_22696 & cppMask_un_8_);
	cppVar_22688 = cppVar_22696;
	} else {
	cppVar_22697 = PC + 1;
	cppVar_22697 = (cppVar_22697 & cppMask_un_16_);
	cppVar_22698 = ROM.rd(cppVar_22697);
	cppVar_22699 = (cppVar_22698 >> 3) & cppMask_un_5_;
	cppVar_22700 = (cppVar_22699 & cppMask_un_5_);
	cppVar_22701 = cppVar_22700 + 32;
	cppVar_22701 = (cppVar_22701 & cppMask_un_8_);
	cppVar_22688 = cppVar_22701;
	}
	cppVar_22703 = (cppVar_22688 == 136);
	if (cppVar_22703) {
	cppVar_22687 = TCON;
	} else {
	cppVar_22706 = PC + 1;
	cppVar_22706 = (cppVar_22706 & cppMask_un_16_);
	cppVar_22707 = ROM.rd(cppVar_22706);
	cppVar_22708 = (cppVar_22707 >> 7) & cppMask_un_1_;
	cppVar_22709 = (cppVar_22708 == 1);
	if (cppVar_22709) {
	cppVar_22710 = PC + 1;
	cppVar_22710 = (cppVar_22710 & cppMask_un_16_);
	cppVar_22711 = ROM.rd(cppVar_22710);
	cppVar_22712 = (cppVar_22711 >> 3) & cppMask_un_5_;
	cppVar_22713 = (cppVar_22712 << 3) | 0;
	cppVar_22713 = (cppVar_22713 & cppMask_un_8_);
	cppVar_22705 = cppVar_22713;
	} else {
	cppVar_22714 = PC + 1;
	cppVar_22714 = (cppVar_22714 & cppMask_un_16_);
	cppVar_22715 = ROM.rd(cppVar_22714);
	cppVar_22716 = (cppVar_22715 >> 3) & cppMask_un_5_;
	cppVar_22717 = (cppVar_22716 & cppMask_un_5_);
	cppVar_22718 = cppVar_22717 + 32;
	cppVar_22718 = (cppVar_22718 & cppMask_un_8_);
	cppVar_22705 = cppVar_22718;
	}
	cppVar_22720 = (cppVar_22705 == 137);
	if (cppVar_22720) {
	cppVar_22704 = TMOD;
	} else {
	cppVar_22723 = PC + 1;
	cppVar_22723 = (cppVar_22723 & cppMask_un_16_);
	cppVar_22724 = ROM.rd(cppVar_22723);
	cppVar_22725 = (cppVar_22724 >> 7) & cppMask_un_1_;
	cppVar_22726 = (cppVar_22725 == 1);
	if (cppVar_22726) {
	cppVar_22727 = PC + 1;
	cppVar_22727 = (cppVar_22727 & cppMask_un_16_);
	cppVar_22728 = ROM.rd(cppVar_22727);
	cppVar_22729 = (cppVar_22728 >> 3) & cppMask_un_5_;
	cppVar_22730 = (cppVar_22729 << 3) | 0;
	cppVar_22730 = (cppVar_22730 & cppMask_un_8_);
	cppVar_22722 = cppVar_22730;
	} else {
	cppVar_22731 = PC + 1;
	cppVar_22731 = (cppVar_22731 & cppMask_un_16_);
	cppVar_22732 = ROM.rd(cppVar_22731);
	cppVar_22733 = (cppVar_22732 >> 3) & cppMask_un_5_;
	cppVar_22734 = (cppVar_22733 & cppMask_un_5_);
	cppVar_22735 = cppVar_22734 + 32;
	cppVar_22735 = (cppVar_22735 & cppMask_un_8_);
	cppVar_22722 = cppVar_22735;
	}
	cppVar_22737 = (cppVar_22722 == 138);
	if (cppVar_22737) {
	cppVar_22721 = TL0;
	} else {
	cppVar_22740 = PC + 1;
	cppVar_22740 = (cppVar_22740 & cppMask_un_16_);
	cppVar_22741 = ROM.rd(cppVar_22740);
	cppVar_22742 = (cppVar_22741 >> 7) & cppMask_un_1_;
	cppVar_22743 = (cppVar_22742 == 1);
	if (cppVar_22743) {
	cppVar_22744 = PC + 1;
	cppVar_22744 = (cppVar_22744 & cppMask_un_16_);
	cppVar_22745 = ROM.rd(cppVar_22744);
	cppVar_22746 = (cppVar_22745 >> 3) & cppMask_un_5_;
	cppVar_22747 = (cppVar_22746 << 3) | 0;
	cppVar_22747 = (cppVar_22747 & cppMask_un_8_);
	cppVar_22739 = cppVar_22747;
	} else {
	cppVar_22748 = PC + 1;
	cppVar_22748 = (cppVar_22748 & cppMask_un_16_);
	cppVar_22749 = ROM.rd(cppVar_22748);
	cppVar_22750 = (cppVar_22749 >> 3) & cppMask_un_5_;
	cppVar_22751 = (cppVar_22750 & cppMask_un_5_);
	cppVar_22752 = cppVar_22751 + 32;
	cppVar_22752 = (cppVar_22752 & cppMask_un_8_);
	cppVar_22739 = cppVar_22752;
	}
	cppVar_22754 = (cppVar_22739 == 140);
	if (cppVar_22754) {
	cppVar_22738 = TH0;
	} else {
	cppVar_22757 = PC + 1;
	cppVar_22757 = (cppVar_22757 & cppMask_un_16_);
	cppVar_22758 = ROM.rd(cppVar_22757);
	cppVar_22759 = (cppVar_22758 >> 7) & cppMask_un_1_;
	cppVar_22760 = (cppVar_22759 == 1);
	if (cppVar_22760) {
	cppVar_22761 = PC + 1;
	cppVar_22761 = (cppVar_22761 & cppMask_un_16_);
	cppVar_22762 = ROM.rd(cppVar_22761);
	cppVar_22763 = (cppVar_22762 >> 3) & cppMask_un_5_;
	cppVar_22764 = (cppVar_22763 << 3) | 0;
	cppVar_22764 = (cppVar_22764 & cppMask_un_8_);
	cppVar_22756 = cppVar_22764;
	} else {
	cppVar_22765 = PC + 1;
	cppVar_22765 = (cppVar_22765 & cppMask_un_16_);
	cppVar_22766 = ROM.rd(cppVar_22765);
	cppVar_22767 = (cppVar_22766 >> 3) & cppMask_un_5_;
	cppVar_22768 = (cppVar_22767 & cppMask_un_5_);
	cppVar_22769 = cppVar_22768 + 32;
	cppVar_22769 = (cppVar_22769 & cppMask_un_8_);
	cppVar_22756 = cppVar_22769;
	}
	cppVar_22771 = (cppVar_22756 == 139);
	if (cppVar_22771) {
	cppVar_22755 = TL1;
	} else {
	cppVar_22774 = PC + 1;
	cppVar_22774 = (cppVar_22774 & cppMask_un_16_);
	cppVar_22775 = ROM.rd(cppVar_22774);
	cppVar_22776 = (cppVar_22775 >> 7) & cppMask_un_1_;
	cppVar_22777 = (cppVar_22776 == 1);
	if (cppVar_22777) {
	cppVar_22778 = PC + 1;
	cppVar_22778 = (cppVar_22778 & cppMask_un_16_);
	cppVar_22779 = ROM.rd(cppVar_22778);
	cppVar_22780 = (cppVar_22779 >> 3) & cppMask_un_5_;
	cppVar_22781 = (cppVar_22780 << 3) | 0;
	cppVar_22781 = (cppVar_22781 & cppMask_un_8_);
	cppVar_22773 = cppVar_22781;
	} else {
	cppVar_22782 = PC + 1;
	cppVar_22782 = (cppVar_22782 & cppMask_un_16_);
	cppVar_22783 = ROM.rd(cppVar_22782);
	cppVar_22784 = (cppVar_22783 >> 3) & cppMask_un_5_;
	cppVar_22785 = (cppVar_22784 & cppMask_un_5_);
	cppVar_22786 = cppVar_22785 + 32;
	cppVar_22786 = (cppVar_22786 & cppMask_un_8_);
	cppVar_22773 = cppVar_22786;
	}
	cppVar_22788 = (cppVar_22773 == 141);
	if (cppVar_22788) {
	cppVar_22772 = TH1;
	} else {
	cppVar_22791 = PC + 1;
	cppVar_22791 = (cppVar_22791 & cppMask_un_16_);
	cppVar_22792 = ROM.rd(cppVar_22791);
	cppVar_22793 = (cppVar_22792 >> 7) & cppMask_un_1_;
	cppVar_22794 = (cppVar_22793 == 1);
	if (cppVar_22794) {
	cppVar_22795 = PC + 1;
	cppVar_22795 = (cppVar_22795 & cppMask_un_16_);
	cppVar_22796 = ROM.rd(cppVar_22795);
	cppVar_22797 = (cppVar_22796 >> 3) & cppMask_un_5_;
	cppVar_22798 = (cppVar_22797 << 3) | 0;
	cppVar_22798 = (cppVar_22798 & cppMask_un_8_);
	cppVar_22790 = cppVar_22798;
	} else {
	cppVar_22799 = PC + 1;
	cppVar_22799 = (cppVar_22799 & cppMask_un_16_);
	cppVar_22800 = ROM.rd(cppVar_22799);
	cppVar_22801 = (cppVar_22800 >> 3) & cppMask_un_5_;
	cppVar_22802 = (cppVar_22801 & cppMask_un_5_);
	cppVar_22803 = cppVar_22802 + 32;
	cppVar_22803 = (cppVar_22803 & cppMask_un_8_);
	cppVar_22790 = cppVar_22803;
	}
	cppVar_22805 = (cppVar_22790 == 144);
	if (cppVar_22805) {
	cppVar_22789 = P1;
	} else {
	cppVar_22808 = PC + 1;
	cppVar_22808 = (cppVar_22808 & cppMask_un_16_);
	cppVar_22809 = ROM.rd(cppVar_22808);
	cppVar_22810 = (cppVar_22809 >> 7) & cppMask_un_1_;
	cppVar_22811 = (cppVar_22810 == 1);
	if (cppVar_22811) {
	cppVar_22812 = PC + 1;
	cppVar_22812 = (cppVar_22812 & cppMask_un_16_);
	cppVar_22813 = ROM.rd(cppVar_22812);
	cppVar_22814 = (cppVar_22813 >> 3) & cppMask_un_5_;
	cppVar_22815 = (cppVar_22814 << 3) | 0;
	cppVar_22815 = (cppVar_22815 & cppMask_un_8_);
	cppVar_22807 = cppVar_22815;
	} else {
	cppVar_22816 = PC + 1;
	cppVar_22816 = (cppVar_22816 & cppMask_un_16_);
	cppVar_22817 = ROM.rd(cppVar_22816);
	cppVar_22818 = (cppVar_22817 >> 3) & cppMask_un_5_;
	cppVar_22819 = (cppVar_22818 & cppMask_un_5_);
	cppVar_22820 = cppVar_22819 + 32;
	cppVar_22820 = (cppVar_22820 & cppMask_un_8_);
	cppVar_22807 = cppVar_22820;
	}
	cppVar_22822 = (cppVar_22807 == 152);
	if (cppVar_22822) {
	cppVar_22806 = SCON;
	} else {
	cppVar_22825 = PC + 1;
	cppVar_22825 = (cppVar_22825 & cppMask_un_16_);
	cppVar_22826 = ROM.rd(cppVar_22825);
	cppVar_22827 = (cppVar_22826 >> 7) & cppMask_un_1_;
	cppVar_22828 = (cppVar_22827 == 1);
	if (cppVar_22828) {
	cppVar_22829 = PC + 1;
	cppVar_22829 = (cppVar_22829 & cppMask_un_16_);
	cppVar_22830 = ROM.rd(cppVar_22829);
	cppVar_22831 = (cppVar_22830 >> 3) & cppMask_un_5_;
	cppVar_22832 = (cppVar_22831 << 3) | 0;
	cppVar_22832 = (cppVar_22832 & cppMask_un_8_);
	cppVar_22824 = cppVar_22832;
	} else {
	cppVar_22833 = PC + 1;
	cppVar_22833 = (cppVar_22833 & cppMask_un_16_);
	cppVar_22834 = ROM.rd(cppVar_22833);
	cppVar_22835 = (cppVar_22834 >> 3) & cppMask_un_5_;
	cppVar_22836 = (cppVar_22835 & cppMask_un_5_);
	cppVar_22837 = cppVar_22836 + 32;
	cppVar_22837 = (cppVar_22837 & cppMask_un_8_);
	cppVar_22824 = cppVar_22837;
	}
	cppVar_22839 = (cppVar_22824 == 153);
	if (cppVar_22839) {
	cppVar_22823 = SBUF;
	} else {
	cppVar_22842 = PC + 1;
	cppVar_22842 = (cppVar_22842 & cppMask_un_16_);
	cppVar_22843 = ROM.rd(cppVar_22842);
	cppVar_22844 = (cppVar_22843 >> 7) & cppMask_un_1_;
	cppVar_22845 = (cppVar_22844 == 1);
	if (cppVar_22845) {
	cppVar_22846 = PC + 1;
	cppVar_22846 = (cppVar_22846 & cppMask_un_16_);
	cppVar_22847 = ROM.rd(cppVar_22846);
	cppVar_22848 = (cppVar_22847 >> 3) & cppMask_un_5_;
	cppVar_22849 = (cppVar_22848 << 3) | 0;
	cppVar_22849 = (cppVar_22849 & cppMask_un_8_);
	cppVar_22841 = cppVar_22849;
	} else {
	cppVar_22850 = PC + 1;
	cppVar_22850 = (cppVar_22850 & cppMask_un_16_);
	cppVar_22851 = ROM.rd(cppVar_22850);
	cppVar_22852 = (cppVar_22851 >> 3) & cppMask_un_5_;
	cppVar_22853 = (cppVar_22852 & cppMask_un_5_);
	cppVar_22854 = cppVar_22853 + 32;
	cppVar_22854 = (cppVar_22854 & cppMask_un_8_);
	cppVar_22841 = cppVar_22854;
	}
	cppVar_22856 = (cppVar_22841 == 160);
	if (cppVar_22856) {
	cppVar_22840 = P2;
	} else {
	cppVar_22859 = PC + 1;
	cppVar_22859 = (cppVar_22859 & cppMask_un_16_);
	cppVar_22860 = ROM.rd(cppVar_22859);
	cppVar_22861 = (cppVar_22860 >> 7) & cppMask_un_1_;
	cppVar_22862 = (cppVar_22861 == 1);
	if (cppVar_22862) {
	cppVar_22863 = PC + 1;
	cppVar_22863 = (cppVar_22863 & cppMask_un_16_);
	cppVar_22864 = ROM.rd(cppVar_22863);
	cppVar_22865 = (cppVar_22864 >> 3) & cppMask_un_5_;
	cppVar_22866 = (cppVar_22865 << 3) | 0;
	cppVar_22866 = (cppVar_22866 & cppMask_un_8_);
	cppVar_22858 = cppVar_22866;
	} else {
	cppVar_22867 = PC + 1;
	cppVar_22867 = (cppVar_22867 & cppMask_un_16_);
	cppVar_22868 = ROM.rd(cppVar_22867);
	cppVar_22869 = (cppVar_22868 >> 3) & cppMask_un_5_;
	cppVar_22870 = (cppVar_22869 & cppMask_un_5_);
	cppVar_22871 = cppVar_22870 + 32;
	cppVar_22871 = (cppVar_22871 & cppMask_un_8_);
	cppVar_22858 = cppVar_22871;
	}
	cppVar_22873 = (cppVar_22858 == 168);
	if (cppVar_22873) {
	cppVar_22857 = IE;
	} else {
	cppVar_22876 = PC + 1;
	cppVar_22876 = (cppVar_22876 & cppMask_un_16_);
	cppVar_22877 = ROM.rd(cppVar_22876);
	cppVar_22878 = (cppVar_22877 >> 7) & cppMask_un_1_;
	cppVar_22879 = (cppVar_22878 == 1);
	if (cppVar_22879) {
	cppVar_22880 = PC + 1;
	cppVar_22880 = (cppVar_22880 & cppMask_un_16_);
	cppVar_22881 = ROM.rd(cppVar_22880);
	cppVar_22882 = (cppVar_22881 >> 3) & cppMask_un_5_;
	cppVar_22883 = (cppVar_22882 << 3) | 0;
	cppVar_22883 = (cppVar_22883 & cppMask_un_8_);
	cppVar_22875 = cppVar_22883;
	} else {
	cppVar_22884 = PC + 1;
	cppVar_22884 = (cppVar_22884 & cppMask_un_16_);
	cppVar_22885 = ROM.rd(cppVar_22884);
	cppVar_22886 = (cppVar_22885 >> 3) & cppMask_un_5_;
	cppVar_22887 = (cppVar_22886 & cppMask_un_5_);
	cppVar_22888 = cppVar_22887 + 32;
	cppVar_22888 = (cppVar_22888 & cppMask_un_8_);
	cppVar_22875 = cppVar_22888;
	}
	cppVar_22890 = (cppVar_22875 == 176);
	if (cppVar_22890) {
	cppVar_22874 = P3;
	} else {
	cppVar_22893 = PC + 1;
	cppVar_22893 = (cppVar_22893 & cppMask_un_16_);
	cppVar_22894 = ROM.rd(cppVar_22893);
	cppVar_22895 = (cppVar_22894 >> 7) & cppMask_un_1_;
	cppVar_22896 = (cppVar_22895 == 1);
	if (cppVar_22896) {
	cppVar_22897 = PC + 1;
	cppVar_22897 = (cppVar_22897 & cppMask_un_16_);
	cppVar_22898 = ROM.rd(cppVar_22897);
	cppVar_22899 = (cppVar_22898 >> 3) & cppMask_un_5_;
	cppVar_22900 = (cppVar_22899 << 3) | 0;
	cppVar_22900 = (cppVar_22900 & cppMask_un_8_);
	cppVar_22892 = cppVar_22900;
	} else {
	cppVar_22901 = PC + 1;
	cppVar_22901 = (cppVar_22901 & cppMask_un_16_);
	cppVar_22902 = ROM.rd(cppVar_22901);
	cppVar_22903 = (cppVar_22902 >> 3) & cppMask_un_5_;
	cppVar_22904 = (cppVar_22903 & cppMask_un_5_);
	cppVar_22905 = cppVar_22904 + 32;
	cppVar_22905 = (cppVar_22905 & cppMask_un_8_);
	cppVar_22892 = cppVar_22905;
	}
	cppVar_22907 = (cppVar_22892 == 184);
	if (cppVar_22907) {
	cppVar_22891 = IP;
	} else {
	cppVar_22910 = PC + 1;
	cppVar_22910 = (cppVar_22910 & cppMask_un_16_);
	cppVar_22911 = ROM.rd(cppVar_22910);
	cppVar_22912 = (cppVar_22911 >> 7) & cppMask_un_1_;
	cppVar_22913 = (cppVar_22912 == 1);
	if (cppVar_22913) {
	cppVar_22914 = PC + 1;
	cppVar_22914 = (cppVar_22914 & cppMask_un_16_);
	cppVar_22915 = ROM.rd(cppVar_22914);
	cppVar_22916 = (cppVar_22915 >> 3) & cppMask_un_5_;
	cppVar_22917 = (cppVar_22916 << 3) | 0;
	cppVar_22917 = (cppVar_22917 & cppMask_un_8_);
	cppVar_22909 = cppVar_22917;
	} else {
	cppVar_22918 = PC + 1;
	cppVar_22918 = (cppVar_22918 & cppMask_un_16_);
	cppVar_22919 = ROM.rd(cppVar_22918);
	cppVar_22920 = (cppVar_22919 >> 3) & cppMask_un_5_;
	cppVar_22921 = (cppVar_22920 & cppMask_un_5_);
	cppVar_22922 = cppVar_22921 + 32;
	cppVar_22922 = (cppVar_22922 & cppMask_un_8_);
	cppVar_22909 = cppVar_22922;
	}
	cppVar_22924 = (cppVar_22909 == 208);
	if (cppVar_22924) {
	cppVar_22908 = PSW;
	} else {
	cppVar_22927 = PC + 1;
	cppVar_22927 = (cppVar_22927 & cppMask_un_16_);
	cppVar_22928 = ROM.rd(cppVar_22927);
	cppVar_22929 = (cppVar_22928 >> 7) & cppMask_un_1_;
	cppVar_22930 = (cppVar_22929 == 1);
	if (cppVar_22930) {
	cppVar_22931 = PC + 1;
	cppVar_22931 = (cppVar_22931 & cppMask_un_16_);
	cppVar_22932 = ROM.rd(cppVar_22931);
	cppVar_22933 = (cppVar_22932 >> 3) & cppMask_un_5_;
	cppVar_22934 = (cppVar_22933 << 3) | 0;
	cppVar_22934 = (cppVar_22934 & cppMask_un_8_);
	cppVar_22926 = cppVar_22934;
	} else {
	cppVar_22935 = PC + 1;
	cppVar_22935 = (cppVar_22935 & cppMask_un_16_);
	cppVar_22936 = ROM.rd(cppVar_22935);
	cppVar_22937 = (cppVar_22936 >> 3) & cppMask_un_5_;
	cppVar_22938 = (cppVar_22937 & cppMask_un_5_);
	cppVar_22939 = cppVar_22938 + 32;
	cppVar_22939 = (cppVar_22939 & cppMask_un_8_);
	cppVar_22926 = cppVar_22939;
	}
	cppVar_22941 = (cppVar_22926 == 224);
	if (cppVar_22941) {
	cppVar_22925 = ACC;
	} else {
	cppVar_22944 = PC + 1;
	cppVar_22944 = (cppVar_22944 & cppMask_un_16_);
	cppVar_22945 = ROM.rd(cppVar_22944);
	cppVar_22946 = (cppVar_22945 >> 7) & cppMask_un_1_;
	cppVar_22947 = (cppVar_22946 == 1);
	if (cppVar_22947) {
	cppVar_22948 = PC + 1;
	cppVar_22948 = (cppVar_22948 & cppMask_un_16_);
	cppVar_22949 = ROM.rd(cppVar_22948);
	cppVar_22950 = (cppVar_22949 >> 3) & cppMask_un_5_;
	cppVar_22951 = (cppVar_22950 << 3) | 0;
	cppVar_22951 = (cppVar_22951 & cppMask_un_8_);
	cppVar_22943 = cppVar_22951;
	} else {
	cppVar_22952 = PC + 1;
	cppVar_22952 = (cppVar_22952 & cppMask_un_16_);
	cppVar_22953 = ROM.rd(cppVar_22952);
	cppVar_22954 = (cppVar_22953 >> 3) & cppMask_un_5_;
	cppVar_22955 = (cppVar_22954 & cppMask_un_5_);
	cppVar_22956 = cppVar_22955 + 32;
	cppVar_22956 = (cppVar_22956 & cppMask_un_8_);
	cppVar_22943 = cppVar_22956;
	}
	cppVar_22958 = (cppVar_22943 == 240);
	if (cppVar_22958) {
	cppVar_22942 = B;
	} else {
	cppVar_22942 = 0;
	}
	cppVar_22925 = cppVar_22942;
	}
	cppVar_22908 = cppVar_22925;
	}
	cppVar_22891 = cppVar_22908;
	}
	cppVar_22874 = cppVar_22891;
	}
	cppVar_22857 = cppVar_22874;
	}
	cppVar_22840 = cppVar_22857;
	}
	cppVar_22823 = cppVar_22840;
	}
	cppVar_22806 = cppVar_22823;
	}
	cppVar_22789 = cppVar_22806;
	}
	cppVar_22772 = cppVar_22789;
	}
	cppVar_22755 = cppVar_22772;
	}
	cppVar_22738 = cppVar_22755;
	}
	cppVar_22721 = cppVar_22738;
	}
	cppVar_22704 = cppVar_22721;
	}
	cppVar_22687 = cppVar_22704;
	}
	cppVar_22670 = cppVar_22687;
	}
	cppVar_22653 = cppVar_22670;
	}
	cppVar_22636 = cppVar_22653;
	}
	cppVar_22619 = cppVar_22636;
	}
	cppVar_22602 = cppVar_22619;
	}
	cppVar_22569 = cppVar_22602;
	}
	cppVar_22960 = cppVar_22568 & cppVar_22569;
	cppVar_22962 = 1;
	cppVar_22963 = PC + 1;
	cppVar_22963 = (cppVar_22963 & cppMask_un_16_);
	cppVar_22964 = ROM.rd(cppVar_22963);
	cppVar_22965 = (cppVar_22964 >> 0) & cppMask_un_3_;
	cppVar_22966 = (cppVar_22965 & cppMask_un_3_);
	cppVar_22967 = cppVar_22962 << static_cast<unsigned>(cppVar_22966);
	cppVar_22967 = (cppVar_22967 & cppMask_un_8_);
	cppVar_22968 = cppVar_22960 | cppVar_22967;
	cppVar_22541 = cppVar_22968;
	} else {
	cppVar_22541 = P0;
	}
	cppVar_22537 = cppVar_22541;
	} else {
	cppVar_22970 = ROM.rd(PC);
	cppVar_22972 = (cppVar_22970 == 208);
	if (cppVar_22972) {
	cppVar_22975 = PC + 1;
	cppVar_22975 = (cppVar_22975 & cppMask_un_16_);
	cppVar_22976 = ROM.rd(cppVar_22975);
	cppVar_22978 = (cppVar_22976 == 128);
	if (cppVar_22978) {
	cppVar_22979 = IRAM.rd(SP);
	cppVar_22973 = cppVar_22979;
	} else {
	cppVar_22973 = P0;
	}
	cppVar_22969 = cppVar_22973;
	} else {
	cppVar_22981 = ROM.rd(PC);
	cppVar_22983 = (cppVar_22981 == 245);
	cppVar_22984 = ROM.rd(PC);
	cppVar_22986 = (cppVar_22984 == 197);
	cppVar_22987 = cppVar_22983 || cppVar_22986;
	if (cppVar_22987) {
	cppVar_22990 = PC + 1;
	cppVar_22990 = (cppVar_22990 & cppMask_un_16_);
	cppVar_22991 = ROM.rd(cppVar_22990);
	cppVar_22993 = (cppVar_22991 == 128);
	if (cppVar_22993) {
	cppVar_22988 = ACC;
	} else {
	cppVar_22988 = P0;
	}
	cppVar_22980 = cppVar_22988;
	} else {
	cppVar_22995 = ROM.rd(PC);
	cppVar_22997 = (cppVar_22995 == 178);
	if (cppVar_22997) {
	cppVar_23001 = PC + 1;
	cppVar_23001 = (cppVar_23001 & cppMask_un_16_);
	cppVar_23002 = ROM.rd(cppVar_23001);
	cppVar_23003 = (cppVar_23002 >> 7) & cppMask_un_1_;
	cppVar_23005 = (cppVar_23003 == 1);
	if (cppVar_23005) {
	cppVar_23006 = PC + 1;
	cppVar_23006 = (cppVar_23006 & cppMask_un_16_);
	cppVar_23007 = ROM.rd(cppVar_23006);
	cppVar_23008 = (cppVar_23007 >> 3) & cppMask_un_5_;
	cppVar_23010 = (cppVar_23008 << 3) | 0;
	cppVar_23010 = (cppVar_23010 & cppMask_un_8_);
	cppVar_22999 = cppVar_23010;
	} else {
	cppVar_23011 = PC + 1;
	cppVar_23011 = (cppVar_23011 & cppMask_un_16_);
	cppVar_23012 = ROM.rd(cppVar_23011);
	cppVar_23013 = (cppVar_23012 >> 3) & cppMask_un_5_;
	cppVar_23014 = (cppVar_23013 & cppMask_un_5_);
	cppVar_23016 = cppVar_23014 + 32;
	cppVar_23016 = (cppVar_23016 & cppMask_un_8_);
	cppVar_22999 = cppVar_23016;
	}
	cppVar_23018 = (cppVar_22999 == 128);
	if (cppVar_23018) {
	cppVar_23020 = PC + 1;
	cppVar_23020 = (cppVar_23020 & cppMask_un_16_);
	cppVar_23021 = ROM.rd(cppVar_23020);
	cppVar_23022 = (cppVar_23021 >> 0) & cppMask_un_3_;
	cppVar_23023 = (cppVar_23022 & cppMask_un_3_);
	cppVar_23024 = 1 << static_cast<unsigned>(cppVar_23023);
	cppVar_23024 = (cppVar_23024 & cppMask_un_8_);
	cppVar_23025 = ~cppVar_23024;
	cppVar_23028 = PC + 1;
	cppVar_23028 = (cppVar_23028 & cppMask_un_16_);
	cppVar_23029 = ROM.rd(cppVar_23028);
	cppVar_23030 = (cppVar_23029 >> 7) & cppMask_un_1_;
	cppVar_23031 = (cppVar_23030 == 1);
	if (cppVar_23031) {
	cppVar_23032 = PC + 1;
	cppVar_23032 = (cppVar_23032 & cppMask_un_16_);
	cppVar_23033 = ROM.rd(cppVar_23032);
	cppVar_23034 = (cppVar_23033 >> 3) & cppMask_un_5_;
	cppVar_23035 = (cppVar_23034 << 3) | 0;
	cppVar_23035 = (cppVar_23035 & cppMask_un_8_);
	cppVar_23027 = cppVar_23035;
	} else {
	cppVar_23036 = PC + 1;
	cppVar_23036 = (cppVar_23036 & cppMask_un_16_);
	cppVar_23037 = ROM.rd(cppVar_23036);
	cppVar_23038 = (cppVar_23037 >> 3) & cppMask_un_5_;
	cppVar_23039 = (cppVar_23038 & cppMask_un_5_);
	cppVar_23040 = cppVar_23039 + 32;
	cppVar_23040 = (cppVar_23040 & cppMask_un_8_);
	cppVar_23027 = cppVar_23040;
	}
	cppVar_23041 = (cppVar_23027 >> 7) & cppMask_un_1_;
	cppVar_23043 = (cppVar_23041 == 0);
	if (cppVar_23043) {
	cppVar_23045 = PC + 1;
	cppVar_23045 = (cppVar_23045 & cppMask_un_16_);
	cppVar_23046 = ROM.rd(cppVar_23045);
	cppVar_23047 = (cppVar_23046 >> 7) & cppMask_un_1_;
	cppVar_23048 = (cppVar_23047 == 1);
	if (cppVar_23048) {
	cppVar_23049 = PC + 1;
	cppVar_23049 = (cppVar_23049 & cppMask_un_16_);
	cppVar_23050 = ROM.rd(cppVar_23049);
	cppVar_23051 = (cppVar_23050 >> 3) & cppMask_un_5_;
	cppVar_23052 = (cppVar_23051 << 3) | 0;
	cppVar_23052 = (cppVar_23052 & cppMask_un_8_);
	cppVar_23044 = cppVar_23052;
	} else {
	cppVar_23053 = PC + 1;
	cppVar_23053 = (cppVar_23053 & cppMask_un_16_);
	cppVar_23054 = ROM.rd(cppVar_23053);
	cppVar_23055 = (cppVar_23054 >> 3) & cppMask_un_5_;
	cppVar_23056 = (cppVar_23055 & cppMask_un_5_);
	cppVar_23057 = cppVar_23056 + 32;
	cppVar_23057 = (cppVar_23057 & cppMask_un_8_);
	cppVar_23044 = cppVar_23057;
	}
	cppVar_23058 = IRAM.rd(cppVar_23044);
	cppVar_23026 = cppVar_23058;
	} else {
	cppVar_23061 = PC + 1;
	cppVar_23061 = (cppVar_23061 & cppMask_un_16_);
	cppVar_23062 = ROM.rd(cppVar_23061);
	cppVar_23063 = (cppVar_23062 >> 7) & cppMask_un_1_;
	cppVar_23064 = (cppVar_23063 == 1);
	if (cppVar_23064) {
	cppVar_23065 = PC + 1;
	cppVar_23065 = (cppVar_23065 & cppMask_un_16_);
	cppVar_23066 = ROM.rd(cppVar_23065);
	cppVar_23067 = (cppVar_23066 >> 3) & cppMask_un_5_;
	cppVar_23068 = (cppVar_23067 << 3) | 0;
	cppVar_23068 = (cppVar_23068 & cppMask_un_8_);
	cppVar_23060 = cppVar_23068;
	} else {
	cppVar_23069 = PC + 1;
	cppVar_23069 = (cppVar_23069 & cppMask_un_16_);
	cppVar_23070 = ROM.rd(cppVar_23069);
	cppVar_23071 = (cppVar_23070 >> 3) & cppMask_un_5_;
	cppVar_23072 = (cppVar_23071 & cppMask_un_5_);
	cppVar_23073 = cppVar_23072 + 32;
	cppVar_23073 = (cppVar_23073 & cppMask_un_8_);
	cppVar_23060 = cppVar_23073;
	}
	cppVar_23075 = (cppVar_23060 == 128);
	if (cppVar_23075) {
	cppVar_23059 = P0;
	} else {
	cppVar_23078 = PC + 1;
	cppVar_23078 = (cppVar_23078 & cppMask_un_16_);
	cppVar_23079 = ROM.rd(cppVar_23078);
	cppVar_23080 = (cppVar_23079 >> 7) & cppMask_un_1_;
	cppVar_23081 = (cppVar_23080 == 1);
	if (cppVar_23081) {
	cppVar_23082 = PC + 1;
	cppVar_23082 = (cppVar_23082 & cppMask_un_16_);
	cppVar_23083 = ROM.rd(cppVar_23082);
	cppVar_23084 = (cppVar_23083 >> 3) & cppMask_un_5_;
	cppVar_23085 = (cppVar_23084 << 3) | 0;
	cppVar_23085 = (cppVar_23085 & cppMask_un_8_);
	cppVar_23077 = cppVar_23085;
	} else {
	cppVar_23086 = PC + 1;
	cppVar_23086 = (cppVar_23086 & cppMask_un_16_);
	cppVar_23087 = ROM.rd(cppVar_23086);
	cppVar_23088 = (cppVar_23087 >> 3) & cppMask_un_5_;
	cppVar_23089 = (cppVar_23088 & cppMask_un_5_);
	cppVar_23090 = cppVar_23089 + 32;
	cppVar_23090 = (cppVar_23090 & cppMask_un_8_);
	cppVar_23077 = cppVar_23090;
	}
	cppVar_23092 = (cppVar_23077 == 129);
	if (cppVar_23092) {
	cppVar_23076 = SP;
	} else {
	cppVar_23095 = PC + 1;
	cppVar_23095 = (cppVar_23095 & cppMask_un_16_);
	cppVar_23096 = ROM.rd(cppVar_23095);
	cppVar_23097 = (cppVar_23096 >> 7) & cppMask_un_1_;
	cppVar_23098 = (cppVar_23097 == 1);
	if (cppVar_23098) {
	cppVar_23099 = PC + 1;
	cppVar_23099 = (cppVar_23099 & cppMask_un_16_);
	cppVar_23100 = ROM.rd(cppVar_23099);
	cppVar_23101 = (cppVar_23100 >> 3) & cppMask_un_5_;
	cppVar_23102 = (cppVar_23101 << 3) | 0;
	cppVar_23102 = (cppVar_23102 & cppMask_un_8_);
	cppVar_23094 = cppVar_23102;
	} else {
	cppVar_23103 = PC + 1;
	cppVar_23103 = (cppVar_23103 & cppMask_un_16_);
	cppVar_23104 = ROM.rd(cppVar_23103);
	cppVar_23105 = (cppVar_23104 >> 3) & cppMask_un_5_;
	cppVar_23106 = (cppVar_23105 & cppMask_un_5_);
	cppVar_23107 = cppVar_23106 + 32;
	cppVar_23107 = (cppVar_23107 & cppMask_un_8_);
	cppVar_23094 = cppVar_23107;
	}
	cppVar_23109 = (cppVar_23094 == 130);
	if (cppVar_23109) {
	cppVar_23093 = DPL;
	} else {
	cppVar_23112 = PC + 1;
	cppVar_23112 = (cppVar_23112 & cppMask_un_16_);
	cppVar_23113 = ROM.rd(cppVar_23112);
	cppVar_23114 = (cppVar_23113 >> 7) & cppMask_un_1_;
	cppVar_23115 = (cppVar_23114 == 1);
	if (cppVar_23115) {
	cppVar_23116 = PC + 1;
	cppVar_23116 = (cppVar_23116 & cppMask_un_16_);
	cppVar_23117 = ROM.rd(cppVar_23116);
	cppVar_23118 = (cppVar_23117 >> 3) & cppMask_un_5_;
	cppVar_23119 = (cppVar_23118 << 3) | 0;
	cppVar_23119 = (cppVar_23119 & cppMask_un_8_);
	cppVar_23111 = cppVar_23119;
	} else {
	cppVar_23120 = PC + 1;
	cppVar_23120 = (cppVar_23120 & cppMask_un_16_);
	cppVar_23121 = ROM.rd(cppVar_23120);
	cppVar_23122 = (cppVar_23121 >> 3) & cppMask_un_5_;
	cppVar_23123 = (cppVar_23122 & cppMask_un_5_);
	cppVar_23124 = cppVar_23123 + 32;
	cppVar_23124 = (cppVar_23124 & cppMask_un_8_);
	cppVar_23111 = cppVar_23124;
	}
	cppVar_23126 = (cppVar_23111 == 131);
	if (cppVar_23126) {
	cppVar_23110 = DPH;
	} else {
	cppVar_23129 = PC + 1;
	cppVar_23129 = (cppVar_23129 & cppMask_un_16_);
	cppVar_23130 = ROM.rd(cppVar_23129);
	cppVar_23131 = (cppVar_23130 >> 7) & cppMask_un_1_;
	cppVar_23132 = (cppVar_23131 == 1);
	if (cppVar_23132) {
	cppVar_23133 = PC + 1;
	cppVar_23133 = (cppVar_23133 & cppMask_un_16_);
	cppVar_23134 = ROM.rd(cppVar_23133);
	cppVar_23135 = (cppVar_23134 >> 3) & cppMask_un_5_;
	cppVar_23136 = (cppVar_23135 << 3) | 0;
	cppVar_23136 = (cppVar_23136 & cppMask_un_8_);
	cppVar_23128 = cppVar_23136;
	} else {
	cppVar_23137 = PC + 1;
	cppVar_23137 = (cppVar_23137 & cppMask_un_16_);
	cppVar_23138 = ROM.rd(cppVar_23137);
	cppVar_23139 = (cppVar_23138 >> 3) & cppMask_un_5_;
	cppVar_23140 = (cppVar_23139 & cppMask_un_5_);
	cppVar_23141 = cppVar_23140 + 32;
	cppVar_23141 = (cppVar_23141 & cppMask_un_8_);
	cppVar_23128 = cppVar_23141;
	}
	cppVar_23143 = (cppVar_23128 == 135);
	if (cppVar_23143) {
	cppVar_23127 = PCON;
	} else {
	cppVar_23146 = PC + 1;
	cppVar_23146 = (cppVar_23146 & cppMask_un_16_);
	cppVar_23147 = ROM.rd(cppVar_23146);
	cppVar_23148 = (cppVar_23147 >> 7) & cppMask_un_1_;
	cppVar_23149 = (cppVar_23148 == 1);
	if (cppVar_23149) {
	cppVar_23150 = PC + 1;
	cppVar_23150 = (cppVar_23150 & cppMask_un_16_);
	cppVar_23151 = ROM.rd(cppVar_23150);
	cppVar_23152 = (cppVar_23151 >> 3) & cppMask_un_5_;
	cppVar_23153 = (cppVar_23152 << 3) | 0;
	cppVar_23153 = (cppVar_23153 & cppMask_un_8_);
	cppVar_23145 = cppVar_23153;
	} else {
	cppVar_23154 = PC + 1;
	cppVar_23154 = (cppVar_23154 & cppMask_un_16_);
	cppVar_23155 = ROM.rd(cppVar_23154);
	cppVar_23156 = (cppVar_23155 >> 3) & cppMask_un_5_;
	cppVar_23157 = (cppVar_23156 & cppMask_un_5_);
	cppVar_23158 = cppVar_23157 + 32;
	cppVar_23158 = (cppVar_23158 & cppMask_un_8_);
	cppVar_23145 = cppVar_23158;
	}
	cppVar_23160 = (cppVar_23145 == 136);
	if (cppVar_23160) {
	cppVar_23144 = TCON;
	} else {
	cppVar_23163 = PC + 1;
	cppVar_23163 = (cppVar_23163 & cppMask_un_16_);
	cppVar_23164 = ROM.rd(cppVar_23163);
	cppVar_23165 = (cppVar_23164 >> 7) & cppMask_un_1_;
	cppVar_23166 = (cppVar_23165 == 1);
	if (cppVar_23166) {
	cppVar_23167 = PC + 1;
	cppVar_23167 = (cppVar_23167 & cppMask_un_16_);
	cppVar_23168 = ROM.rd(cppVar_23167);
	cppVar_23169 = (cppVar_23168 >> 3) & cppMask_un_5_;
	cppVar_23170 = (cppVar_23169 << 3) | 0;
	cppVar_23170 = (cppVar_23170 & cppMask_un_8_);
	cppVar_23162 = cppVar_23170;
	} else {
	cppVar_23171 = PC + 1;
	cppVar_23171 = (cppVar_23171 & cppMask_un_16_);
	cppVar_23172 = ROM.rd(cppVar_23171);
	cppVar_23173 = (cppVar_23172 >> 3) & cppMask_un_5_;
	cppVar_23174 = (cppVar_23173 & cppMask_un_5_);
	cppVar_23175 = cppVar_23174 + 32;
	cppVar_23175 = (cppVar_23175 & cppMask_un_8_);
	cppVar_23162 = cppVar_23175;
	}
	cppVar_23177 = (cppVar_23162 == 137);
	if (cppVar_23177) {
	cppVar_23161 = TMOD;
	} else {
	cppVar_23180 = PC + 1;
	cppVar_23180 = (cppVar_23180 & cppMask_un_16_);
	cppVar_23181 = ROM.rd(cppVar_23180);
	cppVar_23182 = (cppVar_23181 >> 7) & cppMask_un_1_;
	cppVar_23183 = (cppVar_23182 == 1);
	if (cppVar_23183) {
	cppVar_23184 = PC + 1;
	cppVar_23184 = (cppVar_23184 & cppMask_un_16_);
	cppVar_23185 = ROM.rd(cppVar_23184);
	cppVar_23186 = (cppVar_23185 >> 3) & cppMask_un_5_;
	cppVar_23187 = (cppVar_23186 << 3) | 0;
	cppVar_23187 = (cppVar_23187 & cppMask_un_8_);
	cppVar_23179 = cppVar_23187;
	} else {
	cppVar_23188 = PC + 1;
	cppVar_23188 = (cppVar_23188 & cppMask_un_16_);
	cppVar_23189 = ROM.rd(cppVar_23188);
	cppVar_23190 = (cppVar_23189 >> 3) & cppMask_un_5_;
	cppVar_23191 = (cppVar_23190 & cppMask_un_5_);
	cppVar_23192 = cppVar_23191 + 32;
	cppVar_23192 = (cppVar_23192 & cppMask_un_8_);
	cppVar_23179 = cppVar_23192;
	}
	cppVar_23194 = (cppVar_23179 == 138);
	if (cppVar_23194) {
	cppVar_23178 = TL0;
	} else {
	cppVar_23197 = PC + 1;
	cppVar_23197 = (cppVar_23197 & cppMask_un_16_);
	cppVar_23198 = ROM.rd(cppVar_23197);
	cppVar_23199 = (cppVar_23198 >> 7) & cppMask_un_1_;
	cppVar_23200 = (cppVar_23199 == 1);
	if (cppVar_23200) {
	cppVar_23201 = PC + 1;
	cppVar_23201 = (cppVar_23201 & cppMask_un_16_);
	cppVar_23202 = ROM.rd(cppVar_23201);
	cppVar_23203 = (cppVar_23202 >> 3) & cppMask_un_5_;
	cppVar_23204 = (cppVar_23203 << 3) | 0;
	cppVar_23204 = (cppVar_23204 & cppMask_un_8_);
	cppVar_23196 = cppVar_23204;
	} else {
	cppVar_23205 = PC + 1;
	cppVar_23205 = (cppVar_23205 & cppMask_un_16_);
	cppVar_23206 = ROM.rd(cppVar_23205);
	cppVar_23207 = (cppVar_23206 >> 3) & cppMask_un_5_;
	cppVar_23208 = (cppVar_23207 & cppMask_un_5_);
	cppVar_23209 = cppVar_23208 + 32;
	cppVar_23209 = (cppVar_23209 & cppMask_un_8_);
	cppVar_23196 = cppVar_23209;
	}
	cppVar_23211 = (cppVar_23196 == 140);
	if (cppVar_23211) {
	cppVar_23195 = TH0;
	} else {
	cppVar_23214 = PC + 1;
	cppVar_23214 = (cppVar_23214 & cppMask_un_16_);
	cppVar_23215 = ROM.rd(cppVar_23214);
	cppVar_23216 = (cppVar_23215 >> 7) & cppMask_un_1_;
	cppVar_23217 = (cppVar_23216 == 1);
	if (cppVar_23217) {
	cppVar_23218 = PC + 1;
	cppVar_23218 = (cppVar_23218 & cppMask_un_16_);
	cppVar_23219 = ROM.rd(cppVar_23218);
	cppVar_23220 = (cppVar_23219 >> 3) & cppMask_un_5_;
	cppVar_23221 = (cppVar_23220 << 3) | 0;
	cppVar_23221 = (cppVar_23221 & cppMask_un_8_);
	cppVar_23213 = cppVar_23221;
	} else {
	cppVar_23222 = PC + 1;
	cppVar_23222 = (cppVar_23222 & cppMask_un_16_);
	cppVar_23223 = ROM.rd(cppVar_23222);
	cppVar_23224 = (cppVar_23223 >> 3) & cppMask_un_5_;
	cppVar_23225 = (cppVar_23224 & cppMask_un_5_);
	cppVar_23226 = cppVar_23225 + 32;
	cppVar_23226 = (cppVar_23226 & cppMask_un_8_);
	cppVar_23213 = cppVar_23226;
	}
	cppVar_23228 = (cppVar_23213 == 139);
	if (cppVar_23228) {
	cppVar_23212 = TL1;
	} else {
	cppVar_23231 = PC + 1;
	cppVar_23231 = (cppVar_23231 & cppMask_un_16_);
	cppVar_23232 = ROM.rd(cppVar_23231);
	cppVar_23233 = (cppVar_23232 >> 7) & cppMask_un_1_;
	cppVar_23234 = (cppVar_23233 == 1);
	if (cppVar_23234) {
	cppVar_23235 = PC + 1;
	cppVar_23235 = (cppVar_23235 & cppMask_un_16_);
	cppVar_23236 = ROM.rd(cppVar_23235);
	cppVar_23237 = (cppVar_23236 >> 3) & cppMask_un_5_;
	cppVar_23238 = (cppVar_23237 << 3) | 0;
	cppVar_23238 = (cppVar_23238 & cppMask_un_8_);
	cppVar_23230 = cppVar_23238;
	} else {
	cppVar_23239 = PC + 1;
	cppVar_23239 = (cppVar_23239 & cppMask_un_16_);
	cppVar_23240 = ROM.rd(cppVar_23239);
	cppVar_23241 = (cppVar_23240 >> 3) & cppMask_un_5_;
	cppVar_23242 = (cppVar_23241 & cppMask_un_5_);
	cppVar_23243 = cppVar_23242 + 32;
	cppVar_23243 = (cppVar_23243 & cppMask_un_8_);
	cppVar_23230 = cppVar_23243;
	}
	cppVar_23245 = (cppVar_23230 == 141);
	if (cppVar_23245) {
	cppVar_23229 = TH1;
	} else {
	cppVar_23248 = PC + 1;
	cppVar_23248 = (cppVar_23248 & cppMask_un_16_);
	cppVar_23249 = ROM.rd(cppVar_23248);
	cppVar_23250 = (cppVar_23249 >> 7) & cppMask_un_1_;
	cppVar_23251 = (cppVar_23250 == 1);
	if (cppVar_23251) {
	cppVar_23252 = PC + 1;
	cppVar_23252 = (cppVar_23252 & cppMask_un_16_);
	cppVar_23253 = ROM.rd(cppVar_23252);
	cppVar_23254 = (cppVar_23253 >> 3) & cppMask_un_5_;
	cppVar_23255 = (cppVar_23254 << 3) | 0;
	cppVar_23255 = (cppVar_23255 & cppMask_un_8_);
	cppVar_23247 = cppVar_23255;
	} else {
	cppVar_23256 = PC + 1;
	cppVar_23256 = (cppVar_23256 & cppMask_un_16_);
	cppVar_23257 = ROM.rd(cppVar_23256);
	cppVar_23258 = (cppVar_23257 >> 3) & cppMask_un_5_;
	cppVar_23259 = (cppVar_23258 & cppMask_un_5_);
	cppVar_23260 = cppVar_23259 + 32;
	cppVar_23260 = (cppVar_23260 & cppMask_un_8_);
	cppVar_23247 = cppVar_23260;
	}
	cppVar_23262 = (cppVar_23247 == 144);
	if (cppVar_23262) {
	cppVar_23246 = P1;
	} else {
	cppVar_23265 = PC + 1;
	cppVar_23265 = (cppVar_23265 & cppMask_un_16_);
	cppVar_23266 = ROM.rd(cppVar_23265);
	cppVar_23267 = (cppVar_23266 >> 7) & cppMask_un_1_;
	cppVar_23268 = (cppVar_23267 == 1);
	if (cppVar_23268) {
	cppVar_23269 = PC + 1;
	cppVar_23269 = (cppVar_23269 & cppMask_un_16_);
	cppVar_23270 = ROM.rd(cppVar_23269);
	cppVar_23271 = (cppVar_23270 >> 3) & cppMask_un_5_;
	cppVar_23272 = (cppVar_23271 << 3) | 0;
	cppVar_23272 = (cppVar_23272 & cppMask_un_8_);
	cppVar_23264 = cppVar_23272;
	} else {
	cppVar_23273 = PC + 1;
	cppVar_23273 = (cppVar_23273 & cppMask_un_16_);
	cppVar_23274 = ROM.rd(cppVar_23273);
	cppVar_23275 = (cppVar_23274 >> 3) & cppMask_un_5_;
	cppVar_23276 = (cppVar_23275 & cppMask_un_5_);
	cppVar_23277 = cppVar_23276 + 32;
	cppVar_23277 = (cppVar_23277 & cppMask_un_8_);
	cppVar_23264 = cppVar_23277;
	}
	cppVar_23279 = (cppVar_23264 == 152);
	if (cppVar_23279) {
	cppVar_23263 = SCON;
	} else {
	cppVar_23282 = PC + 1;
	cppVar_23282 = (cppVar_23282 & cppMask_un_16_);
	cppVar_23283 = ROM.rd(cppVar_23282);
	cppVar_23284 = (cppVar_23283 >> 7) & cppMask_un_1_;
	cppVar_23285 = (cppVar_23284 == 1);
	if (cppVar_23285) {
	cppVar_23286 = PC + 1;
	cppVar_23286 = (cppVar_23286 & cppMask_un_16_);
	cppVar_23287 = ROM.rd(cppVar_23286);
	cppVar_23288 = (cppVar_23287 >> 3) & cppMask_un_5_;
	cppVar_23289 = (cppVar_23288 << 3) | 0;
	cppVar_23289 = (cppVar_23289 & cppMask_un_8_);
	cppVar_23281 = cppVar_23289;
	} else {
	cppVar_23290 = PC + 1;
	cppVar_23290 = (cppVar_23290 & cppMask_un_16_);
	cppVar_23291 = ROM.rd(cppVar_23290);
	cppVar_23292 = (cppVar_23291 >> 3) & cppMask_un_5_;
	cppVar_23293 = (cppVar_23292 & cppMask_un_5_);
	cppVar_23294 = cppVar_23293 + 32;
	cppVar_23294 = (cppVar_23294 & cppMask_un_8_);
	cppVar_23281 = cppVar_23294;
	}
	cppVar_23296 = (cppVar_23281 == 153);
	if (cppVar_23296) {
	cppVar_23280 = SBUF;
	} else {
	cppVar_23299 = PC + 1;
	cppVar_23299 = (cppVar_23299 & cppMask_un_16_);
	cppVar_23300 = ROM.rd(cppVar_23299);
	cppVar_23301 = (cppVar_23300 >> 7) & cppMask_un_1_;
	cppVar_23302 = (cppVar_23301 == 1);
	if (cppVar_23302) {
	cppVar_23303 = PC + 1;
	cppVar_23303 = (cppVar_23303 & cppMask_un_16_);
	cppVar_23304 = ROM.rd(cppVar_23303);
	cppVar_23305 = (cppVar_23304 >> 3) & cppMask_un_5_;
	cppVar_23306 = (cppVar_23305 << 3) | 0;
	cppVar_23306 = (cppVar_23306 & cppMask_un_8_);
	cppVar_23298 = cppVar_23306;
	} else {
	cppVar_23307 = PC + 1;
	cppVar_23307 = (cppVar_23307 & cppMask_un_16_);
	cppVar_23308 = ROM.rd(cppVar_23307);
	cppVar_23309 = (cppVar_23308 >> 3) & cppMask_un_5_;
	cppVar_23310 = (cppVar_23309 & cppMask_un_5_);
	cppVar_23311 = cppVar_23310 + 32;
	cppVar_23311 = (cppVar_23311 & cppMask_un_8_);
	cppVar_23298 = cppVar_23311;
	}
	cppVar_23313 = (cppVar_23298 == 160);
	if (cppVar_23313) {
	cppVar_23297 = P2;
	} else {
	cppVar_23316 = PC + 1;
	cppVar_23316 = (cppVar_23316 & cppMask_un_16_);
	cppVar_23317 = ROM.rd(cppVar_23316);
	cppVar_23318 = (cppVar_23317 >> 7) & cppMask_un_1_;
	cppVar_23319 = (cppVar_23318 == 1);
	if (cppVar_23319) {
	cppVar_23320 = PC + 1;
	cppVar_23320 = (cppVar_23320 & cppMask_un_16_);
	cppVar_23321 = ROM.rd(cppVar_23320);
	cppVar_23322 = (cppVar_23321 >> 3) & cppMask_un_5_;
	cppVar_23323 = (cppVar_23322 << 3) | 0;
	cppVar_23323 = (cppVar_23323 & cppMask_un_8_);
	cppVar_23315 = cppVar_23323;
	} else {
	cppVar_23324 = PC + 1;
	cppVar_23324 = (cppVar_23324 & cppMask_un_16_);
	cppVar_23325 = ROM.rd(cppVar_23324);
	cppVar_23326 = (cppVar_23325 >> 3) & cppMask_un_5_;
	cppVar_23327 = (cppVar_23326 & cppMask_un_5_);
	cppVar_23328 = cppVar_23327 + 32;
	cppVar_23328 = (cppVar_23328 & cppMask_un_8_);
	cppVar_23315 = cppVar_23328;
	}
	cppVar_23330 = (cppVar_23315 == 168);
	if (cppVar_23330) {
	cppVar_23314 = IE;
	} else {
	cppVar_23333 = PC + 1;
	cppVar_23333 = (cppVar_23333 & cppMask_un_16_);
	cppVar_23334 = ROM.rd(cppVar_23333);
	cppVar_23335 = (cppVar_23334 >> 7) & cppMask_un_1_;
	cppVar_23336 = (cppVar_23335 == 1);
	if (cppVar_23336) {
	cppVar_23337 = PC + 1;
	cppVar_23337 = (cppVar_23337 & cppMask_un_16_);
	cppVar_23338 = ROM.rd(cppVar_23337);
	cppVar_23339 = (cppVar_23338 >> 3) & cppMask_un_5_;
	cppVar_23340 = (cppVar_23339 << 3) | 0;
	cppVar_23340 = (cppVar_23340 & cppMask_un_8_);
	cppVar_23332 = cppVar_23340;
	} else {
	cppVar_23341 = PC + 1;
	cppVar_23341 = (cppVar_23341 & cppMask_un_16_);
	cppVar_23342 = ROM.rd(cppVar_23341);
	cppVar_23343 = (cppVar_23342 >> 3) & cppMask_un_5_;
	cppVar_23344 = (cppVar_23343 & cppMask_un_5_);
	cppVar_23345 = cppVar_23344 + 32;
	cppVar_23345 = (cppVar_23345 & cppMask_un_8_);
	cppVar_23332 = cppVar_23345;
	}
	cppVar_23347 = (cppVar_23332 == 176);
	if (cppVar_23347) {
	cppVar_23331 = P3;
	} else {
	cppVar_23350 = PC + 1;
	cppVar_23350 = (cppVar_23350 & cppMask_un_16_);
	cppVar_23351 = ROM.rd(cppVar_23350);
	cppVar_23352 = (cppVar_23351 >> 7) & cppMask_un_1_;
	cppVar_23353 = (cppVar_23352 == 1);
	if (cppVar_23353) {
	cppVar_23354 = PC + 1;
	cppVar_23354 = (cppVar_23354 & cppMask_un_16_);
	cppVar_23355 = ROM.rd(cppVar_23354);
	cppVar_23356 = (cppVar_23355 >> 3) & cppMask_un_5_;
	cppVar_23357 = (cppVar_23356 << 3) | 0;
	cppVar_23357 = (cppVar_23357 & cppMask_un_8_);
	cppVar_23349 = cppVar_23357;
	} else {
	cppVar_23358 = PC + 1;
	cppVar_23358 = (cppVar_23358 & cppMask_un_16_);
	cppVar_23359 = ROM.rd(cppVar_23358);
	cppVar_23360 = (cppVar_23359 >> 3) & cppMask_un_5_;
	cppVar_23361 = (cppVar_23360 & cppMask_un_5_);
	cppVar_23362 = cppVar_23361 + 32;
	cppVar_23362 = (cppVar_23362 & cppMask_un_8_);
	cppVar_23349 = cppVar_23362;
	}
	cppVar_23364 = (cppVar_23349 == 184);
	if (cppVar_23364) {
	cppVar_23348 = IP;
	} else {
	cppVar_23367 = PC + 1;
	cppVar_23367 = (cppVar_23367 & cppMask_un_16_);
	cppVar_23368 = ROM.rd(cppVar_23367);
	cppVar_23369 = (cppVar_23368 >> 7) & cppMask_un_1_;
	cppVar_23370 = (cppVar_23369 == 1);
	if (cppVar_23370) {
	cppVar_23371 = PC + 1;
	cppVar_23371 = (cppVar_23371 & cppMask_un_16_);
	cppVar_23372 = ROM.rd(cppVar_23371);
	cppVar_23373 = (cppVar_23372 >> 3) & cppMask_un_5_;
	cppVar_23374 = (cppVar_23373 << 3) | 0;
	cppVar_23374 = (cppVar_23374 & cppMask_un_8_);
	cppVar_23366 = cppVar_23374;
	} else {
	cppVar_23375 = PC + 1;
	cppVar_23375 = (cppVar_23375 & cppMask_un_16_);
	cppVar_23376 = ROM.rd(cppVar_23375);
	cppVar_23377 = (cppVar_23376 >> 3) & cppMask_un_5_;
	cppVar_23378 = (cppVar_23377 & cppMask_un_5_);
	cppVar_23379 = cppVar_23378 + 32;
	cppVar_23379 = (cppVar_23379 & cppMask_un_8_);
	cppVar_23366 = cppVar_23379;
	}
	cppVar_23381 = (cppVar_23366 == 208);
	if (cppVar_23381) {
	cppVar_23365 = PSW;
	} else {
	cppVar_23384 = PC + 1;
	cppVar_23384 = (cppVar_23384 & cppMask_un_16_);
	cppVar_23385 = ROM.rd(cppVar_23384);
	cppVar_23386 = (cppVar_23385 >> 7) & cppMask_un_1_;
	cppVar_23387 = (cppVar_23386 == 1);
	if (cppVar_23387) {
	cppVar_23388 = PC + 1;
	cppVar_23388 = (cppVar_23388 & cppMask_un_16_);
	cppVar_23389 = ROM.rd(cppVar_23388);
	cppVar_23390 = (cppVar_23389 >> 3) & cppMask_un_5_;
	cppVar_23391 = (cppVar_23390 << 3) | 0;
	cppVar_23391 = (cppVar_23391 & cppMask_un_8_);
	cppVar_23383 = cppVar_23391;
	} else {
	cppVar_23392 = PC + 1;
	cppVar_23392 = (cppVar_23392 & cppMask_un_16_);
	cppVar_23393 = ROM.rd(cppVar_23392);
	cppVar_23394 = (cppVar_23393 >> 3) & cppMask_un_5_;
	cppVar_23395 = (cppVar_23394 & cppMask_un_5_);
	cppVar_23396 = cppVar_23395 + 32;
	cppVar_23396 = (cppVar_23396 & cppMask_un_8_);
	cppVar_23383 = cppVar_23396;
	}
	cppVar_23398 = (cppVar_23383 == 224);
	if (cppVar_23398) {
	cppVar_23382 = ACC;
	} else {
	cppVar_23401 = PC + 1;
	cppVar_23401 = (cppVar_23401 & cppMask_un_16_);
	cppVar_23402 = ROM.rd(cppVar_23401);
	cppVar_23403 = (cppVar_23402 >> 7) & cppMask_un_1_;
	cppVar_23404 = (cppVar_23403 == 1);
	if (cppVar_23404) {
	cppVar_23405 = PC + 1;
	cppVar_23405 = (cppVar_23405 & cppMask_un_16_);
	cppVar_23406 = ROM.rd(cppVar_23405);
	cppVar_23407 = (cppVar_23406 >> 3) & cppMask_un_5_;
	cppVar_23408 = (cppVar_23407 << 3) | 0;
	cppVar_23408 = (cppVar_23408 & cppMask_un_8_);
	cppVar_23400 = cppVar_23408;
	} else {
	cppVar_23409 = PC + 1;
	cppVar_23409 = (cppVar_23409 & cppMask_un_16_);
	cppVar_23410 = ROM.rd(cppVar_23409);
	cppVar_23411 = (cppVar_23410 >> 3) & cppMask_un_5_;
	cppVar_23412 = (cppVar_23411 & cppMask_un_5_);
	cppVar_23413 = cppVar_23412 + 32;
	cppVar_23413 = (cppVar_23413 & cppMask_un_8_);
	cppVar_23400 = cppVar_23413;
	}
	cppVar_23415 = (cppVar_23400 == 240);
	if (cppVar_23415) {
	cppVar_23399 = B;
	} else {
	cppVar_23399 = 0;
	}
	cppVar_23382 = cppVar_23399;
	}
	cppVar_23365 = cppVar_23382;
	}
	cppVar_23348 = cppVar_23365;
	}
	cppVar_23331 = cppVar_23348;
	}
	cppVar_23314 = cppVar_23331;
	}
	cppVar_23297 = cppVar_23314;
	}
	cppVar_23280 = cppVar_23297;
	}
	cppVar_23263 = cppVar_23280;
	}
	cppVar_23246 = cppVar_23263;
	}
	cppVar_23229 = cppVar_23246;
	}
	cppVar_23212 = cppVar_23229;
	}
	cppVar_23195 = cppVar_23212;
	}
	cppVar_23178 = cppVar_23195;
	}
	cppVar_23161 = cppVar_23178;
	}
	cppVar_23144 = cppVar_23161;
	}
	cppVar_23127 = cppVar_23144;
	}
	cppVar_23110 = cppVar_23127;
	}
	cppVar_23093 = cppVar_23110;
	}
	cppVar_23076 = cppVar_23093;
	}
	cppVar_23059 = cppVar_23076;
	}
	cppVar_23026 = cppVar_23059;
	}
	cppVar_23417 = cppVar_23025 & cppVar_23026;
	cppVar_23420 = PC + 1;
	cppVar_23420 = (cppVar_23420 & cppMask_un_16_);
	cppVar_23421 = ROM.rd(cppVar_23420);
	cppVar_23422 = (cppVar_23421 >> 7) & cppMask_un_1_;
	cppVar_23424 = (cppVar_23422 == 1);
	if (cppVar_23424) {
	cppVar_23425 = PC + 1;
	cppVar_23425 = (cppVar_23425 & cppMask_un_16_);
	cppVar_23426 = ROM.rd(cppVar_23425);
	cppVar_23427 = (cppVar_23426 >> 3) & cppMask_un_5_;
	cppVar_23429 = (cppVar_23427 << 3) | 0;
	cppVar_23429 = (cppVar_23429 & cppMask_un_8_);
	cppVar_23419 = cppVar_23429;
	} else {
	cppVar_23430 = PC + 1;
	cppVar_23430 = (cppVar_23430 & cppMask_un_16_);
	cppVar_23431 = ROM.rd(cppVar_23430);
	cppVar_23432 = (cppVar_23431 >> 3) & cppMask_un_5_;
	cppVar_23433 = (cppVar_23432 & cppMask_un_5_);
	cppVar_23435 = cppVar_23433 + 32;
	cppVar_23435 = (cppVar_23435 & cppMask_un_8_);
	cppVar_23419 = cppVar_23435;
	}
	cppVar_23436 = (cppVar_23419 >> 7) & cppMask_un_1_;
	cppVar_23438 = (cppVar_23436 == 0);
	if (cppVar_23438) {
	cppVar_23440 = PC + 1;
	cppVar_23440 = (cppVar_23440 & cppMask_un_16_);
	cppVar_23441 = ROM.rd(cppVar_23440);
	cppVar_23442 = (cppVar_23441 >> 7) & cppMask_un_1_;
	cppVar_23443 = (cppVar_23442 == 1);
	if (cppVar_23443) {
	cppVar_23444 = PC + 1;
	cppVar_23444 = (cppVar_23444 & cppMask_un_16_);
	cppVar_23445 = ROM.rd(cppVar_23444);
	cppVar_23446 = (cppVar_23445 >> 3) & cppMask_un_5_;
	cppVar_23447 = (cppVar_23446 << 3) | 0;
	cppVar_23447 = (cppVar_23447 & cppMask_un_8_);
	cppVar_23439 = cppVar_23447;
	} else {
	cppVar_23448 = PC + 1;
	cppVar_23448 = (cppVar_23448 & cppMask_un_16_);
	cppVar_23449 = ROM.rd(cppVar_23448);
	cppVar_23450 = (cppVar_23449 >> 3) & cppMask_un_5_;
	cppVar_23451 = (cppVar_23450 & cppMask_un_5_);
	cppVar_23452 = cppVar_23451 + 32;
	cppVar_23452 = (cppVar_23452 & cppMask_un_8_);
	cppVar_23439 = cppVar_23452;
	}
	cppVar_23453 = IRAM.rd(cppVar_23439);
	cppVar_23418 = cppVar_23453;
	} else {
	cppVar_23456 = PC + 1;
	cppVar_23456 = (cppVar_23456 & cppMask_un_16_);
	cppVar_23457 = ROM.rd(cppVar_23456);
	cppVar_23458 = (cppVar_23457 >> 7) & cppMask_un_1_;
	cppVar_23459 = (cppVar_23458 == 1);
	if (cppVar_23459) {
	cppVar_23460 = PC + 1;
	cppVar_23460 = (cppVar_23460 & cppMask_un_16_);
	cppVar_23461 = ROM.rd(cppVar_23460);
	cppVar_23462 = (cppVar_23461 >> 3) & cppMask_un_5_;
	cppVar_23463 = (cppVar_23462 << 3) | 0;
	cppVar_23463 = (cppVar_23463 & cppMask_un_8_);
	cppVar_23455 = cppVar_23463;
	} else {
	cppVar_23464 = PC + 1;
	cppVar_23464 = (cppVar_23464 & cppMask_un_16_);
	cppVar_23465 = ROM.rd(cppVar_23464);
	cppVar_23466 = (cppVar_23465 >> 3) & cppMask_un_5_;
	cppVar_23467 = (cppVar_23466 & cppMask_un_5_);
	cppVar_23468 = cppVar_23467 + 32;
	cppVar_23468 = (cppVar_23468 & cppMask_un_8_);
	cppVar_23455 = cppVar_23468;
	}
	cppVar_23470 = (cppVar_23455 == 128);
	if (cppVar_23470) {
	cppVar_23454 = P0;
	} else {
	cppVar_23473 = PC + 1;
	cppVar_23473 = (cppVar_23473 & cppMask_un_16_);
	cppVar_23474 = ROM.rd(cppVar_23473);
	cppVar_23475 = (cppVar_23474 >> 7) & cppMask_un_1_;
	cppVar_23476 = (cppVar_23475 == 1);
	if (cppVar_23476) {
	cppVar_23477 = PC + 1;
	cppVar_23477 = (cppVar_23477 & cppMask_un_16_);
	cppVar_23478 = ROM.rd(cppVar_23477);
	cppVar_23479 = (cppVar_23478 >> 3) & cppMask_un_5_;
	cppVar_23480 = (cppVar_23479 << 3) | 0;
	cppVar_23480 = (cppVar_23480 & cppMask_un_8_);
	cppVar_23472 = cppVar_23480;
	} else {
	cppVar_23481 = PC + 1;
	cppVar_23481 = (cppVar_23481 & cppMask_un_16_);
	cppVar_23482 = ROM.rd(cppVar_23481);
	cppVar_23483 = (cppVar_23482 >> 3) & cppMask_un_5_;
	cppVar_23484 = (cppVar_23483 & cppMask_un_5_);
	cppVar_23485 = cppVar_23484 + 32;
	cppVar_23485 = (cppVar_23485 & cppMask_un_8_);
	cppVar_23472 = cppVar_23485;
	}
	cppVar_23487 = (cppVar_23472 == 129);
	if (cppVar_23487) {
	cppVar_23471 = SP;
	} else {
	cppVar_23490 = PC + 1;
	cppVar_23490 = (cppVar_23490 & cppMask_un_16_);
	cppVar_23491 = ROM.rd(cppVar_23490);
	cppVar_23492 = (cppVar_23491 >> 7) & cppMask_un_1_;
	cppVar_23493 = (cppVar_23492 == 1);
	if (cppVar_23493) {
	cppVar_23494 = PC + 1;
	cppVar_23494 = (cppVar_23494 & cppMask_un_16_);
	cppVar_23495 = ROM.rd(cppVar_23494);
	cppVar_23496 = (cppVar_23495 >> 3) & cppMask_un_5_;
	cppVar_23497 = (cppVar_23496 << 3) | 0;
	cppVar_23497 = (cppVar_23497 & cppMask_un_8_);
	cppVar_23489 = cppVar_23497;
	} else {
	cppVar_23498 = PC + 1;
	cppVar_23498 = (cppVar_23498 & cppMask_un_16_);
	cppVar_23499 = ROM.rd(cppVar_23498);
	cppVar_23500 = (cppVar_23499 >> 3) & cppMask_un_5_;
	cppVar_23501 = (cppVar_23500 & cppMask_un_5_);
	cppVar_23502 = cppVar_23501 + 32;
	cppVar_23502 = (cppVar_23502 & cppMask_un_8_);
	cppVar_23489 = cppVar_23502;
	}
	cppVar_23504 = (cppVar_23489 == 130);
	if (cppVar_23504) {
	cppVar_23488 = DPL;
	} else {
	cppVar_23507 = PC + 1;
	cppVar_23507 = (cppVar_23507 & cppMask_un_16_);
	cppVar_23508 = ROM.rd(cppVar_23507);
	cppVar_23509 = (cppVar_23508 >> 7) & cppMask_un_1_;
	cppVar_23510 = (cppVar_23509 == 1);
	if (cppVar_23510) {
	cppVar_23511 = PC + 1;
	cppVar_23511 = (cppVar_23511 & cppMask_un_16_);
	cppVar_23512 = ROM.rd(cppVar_23511);
	cppVar_23513 = (cppVar_23512 >> 3) & cppMask_un_5_;
	cppVar_23514 = (cppVar_23513 << 3) | 0;
	cppVar_23514 = (cppVar_23514 & cppMask_un_8_);
	cppVar_23506 = cppVar_23514;
	} else {
	cppVar_23515 = PC + 1;
	cppVar_23515 = (cppVar_23515 & cppMask_un_16_);
	cppVar_23516 = ROM.rd(cppVar_23515);
	cppVar_23517 = (cppVar_23516 >> 3) & cppMask_un_5_;
	cppVar_23518 = (cppVar_23517 & cppMask_un_5_);
	cppVar_23519 = cppVar_23518 + 32;
	cppVar_23519 = (cppVar_23519 & cppMask_un_8_);
	cppVar_23506 = cppVar_23519;
	}
	cppVar_23521 = (cppVar_23506 == 131);
	if (cppVar_23521) {
	cppVar_23505 = DPH;
	} else {
	cppVar_23524 = PC + 1;
	cppVar_23524 = (cppVar_23524 & cppMask_un_16_);
	cppVar_23525 = ROM.rd(cppVar_23524);
	cppVar_23526 = (cppVar_23525 >> 7) & cppMask_un_1_;
	cppVar_23527 = (cppVar_23526 == 1);
	if (cppVar_23527) {
	cppVar_23528 = PC + 1;
	cppVar_23528 = (cppVar_23528 & cppMask_un_16_);
	cppVar_23529 = ROM.rd(cppVar_23528);
	cppVar_23530 = (cppVar_23529 >> 3) & cppMask_un_5_;
	cppVar_23531 = (cppVar_23530 << 3) | 0;
	cppVar_23531 = (cppVar_23531 & cppMask_un_8_);
	cppVar_23523 = cppVar_23531;
	} else {
	cppVar_23532 = PC + 1;
	cppVar_23532 = (cppVar_23532 & cppMask_un_16_);
	cppVar_23533 = ROM.rd(cppVar_23532);
	cppVar_23534 = (cppVar_23533 >> 3) & cppMask_un_5_;
	cppVar_23535 = (cppVar_23534 & cppMask_un_5_);
	cppVar_23536 = cppVar_23535 + 32;
	cppVar_23536 = (cppVar_23536 & cppMask_un_8_);
	cppVar_23523 = cppVar_23536;
	}
	cppVar_23538 = (cppVar_23523 == 135);
	if (cppVar_23538) {
	cppVar_23522 = PCON;
	} else {
	cppVar_23541 = PC + 1;
	cppVar_23541 = (cppVar_23541 & cppMask_un_16_);
	cppVar_23542 = ROM.rd(cppVar_23541);
	cppVar_23543 = (cppVar_23542 >> 7) & cppMask_un_1_;
	cppVar_23544 = (cppVar_23543 == 1);
	if (cppVar_23544) {
	cppVar_23545 = PC + 1;
	cppVar_23545 = (cppVar_23545 & cppMask_un_16_);
	cppVar_23546 = ROM.rd(cppVar_23545);
	cppVar_23547 = (cppVar_23546 >> 3) & cppMask_un_5_;
	cppVar_23548 = (cppVar_23547 << 3) | 0;
	cppVar_23548 = (cppVar_23548 & cppMask_un_8_);
	cppVar_23540 = cppVar_23548;
	} else {
	cppVar_23549 = PC + 1;
	cppVar_23549 = (cppVar_23549 & cppMask_un_16_);
	cppVar_23550 = ROM.rd(cppVar_23549);
	cppVar_23551 = (cppVar_23550 >> 3) & cppMask_un_5_;
	cppVar_23552 = (cppVar_23551 & cppMask_un_5_);
	cppVar_23553 = cppVar_23552 + 32;
	cppVar_23553 = (cppVar_23553 & cppMask_un_8_);
	cppVar_23540 = cppVar_23553;
	}
	cppVar_23555 = (cppVar_23540 == 136);
	if (cppVar_23555) {
	cppVar_23539 = TCON;
	} else {
	cppVar_23558 = PC + 1;
	cppVar_23558 = (cppVar_23558 & cppMask_un_16_);
	cppVar_23559 = ROM.rd(cppVar_23558);
	cppVar_23560 = (cppVar_23559 >> 7) & cppMask_un_1_;
	cppVar_23561 = (cppVar_23560 == 1);
	if (cppVar_23561) {
	cppVar_23562 = PC + 1;
	cppVar_23562 = (cppVar_23562 & cppMask_un_16_);
	cppVar_23563 = ROM.rd(cppVar_23562);
	cppVar_23564 = (cppVar_23563 >> 3) & cppMask_un_5_;
	cppVar_23565 = (cppVar_23564 << 3) | 0;
	cppVar_23565 = (cppVar_23565 & cppMask_un_8_);
	cppVar_23557 = cppVar_23565;
	} else {
	cppVar_23566 = PC + 1;
	cppVar_23566 = (cppVar_23566 & cppMask_un_16_);
	cppVar_23567 = ROM.rd(cppVar_23566);
	cppVar_23568 = (cppVar_23567 >> 3) & cppMask_un_5_;
	cppVar_23569 = (cppVar_23568 & cppMask_un_5_);
	cppVar_23570 = cppVar_23569 + 32;
	cppVar_23570 = (cppVar_23570 & cppMask_un_8_);
	cppVar_23557 = cppVar_23570;
	}
	cppVar_23572 = (cppVar_23557 == 137);
	if (cppVar_23572) {
	cppVar_23556 = TMOD;
	} else {
	cppVar_23575 = PC + 1;
	cppVar_23575 = (cppVar_23575 & cppMask_un_16_);
	cppVar_23576 = ROM.rd(cppVar_23575);
	cppVar_23577 = (cppVar_23576 >> 7) & cppMask_un_1_;
	cppVar_23578 = (cppVar_23577 == 1);
	if (cppVar_23578) {
	cppVar_23579 = PC + 1;
	cppVar_23579 = (cppVar_23579 & cppMask_un_16_);
	cppVar_23580 = ROM.rd(cppVar_23579);
	cppVar_23581 = (cppVar_23580 >> 3) & cppMask_un_5_;
	cppVar_23582 = (cppVar_23581 << 3) | 0;
	cppVar_23582 = (cppVar_23582 & cppMask_un_8_);
	cppVar_23574 = cppVar_23582;
	} else {
	cppVar_23583 = PC + 1;
	cppVar_23583 = (cppVar_23583 & cppMask_un_16_);
	cppVar_23584 = ROM.rd(cppVar_23583);
	cppVar_23585 = (cppVar_23584 >> 3) & cppMask_un_5_;
	cppVar_23586 = (cppVar_23585 & cppMask_un_5_);
	cppVar_23587 = cppVar_23586 + 32;
	cppVar_23587 = (cppVar_23587 & cppMask_un_8_);
	cppVar_23574 = cppVar_23587;
	}
	cppVar_23589 = (cppVar_23574 == 138);
	if (cppVar_23589) {
	cppVar_23573 = TL0;
	} else {
	cppVar_23592 = PC + 1;
	cppVar_23592 = (cppVar_23592 & cppMask_un_16_);
	cppVar_23593 = ROM.rd(cppVar_23592);
	cppVar_23594 = (cppVar_23593 >> 7) & cppMask_un_1_;
	cppVar_23595 = (cppVar_23594 == 1);
	if (cppVar_23595) {
	cppVar_23596 = PC + 1;
	cppVar_23596 = (cppVar_23596 & cppMask_un_16_);
	cppVar_23597 = ROM.rd(cppVar_23596);
	cppVar_23598 = (cppVar_23597 >> 3) & cppMask_un_5_;
	cppVar_23599 = (cppVar_23598 << 3) | 0;
	cppVar_23599 = (cppVar_23599 & cppMask_un_8_);
	cppVar_23591 = cppVar_23599;
	} else {
	cppVar_23600 = PC + 1;
	cppVar_23600 = (cppVar_23600 & cppMask_un_16_);
	cppVar_23601 = ROM.rd(cppVar_23600);
	cppVar_23602 = (cppVar_23601 >> 3) & cppMask_un_5_;
	cppVar_23603 = (cppVar_23602 & cppMask_un_5_);
	cppVar_23604 = cppVar_23603 + 32;
	cppVar_23604 = (cppVar_23604 & cppMask_un_8_);
	cppVar_23591 = cppVar_23604;
	}
	cppVar_23606 = (cppVar_23591 == 140);
	if (cppVar_23606) {
	cppVar_23590 = TH0;
	} else {
	cppVar_23609 = PC + 1;
	cppVar_23609 = (cppVar_23609 & cppMask_un_16_);
	cppVar_23610 = ROM.rd(cppVar_23609);
	cppVar_23611 = (cppVar_23610 >> 7) & cppMask_un_1_;
	cppVar_23612 = (cppVar_23611 == 1);
	if (cppVar_23612) {
	cppVar_23613 = PC + 1;
	cppVar_23613 = (cppVar_23613 & cppMask_un_16_);
	cppVar_23614 = ROM.rd(cppVar_23613);
	cppVar_23615 = (cppVar_23614 >> 3) & cppMask_un_5_;
	cppVar_23616 = (cppVar_23615 << 3) | 0;
	cppVar_23616 = (cppVar_23616 & cppMask_un_8_);
	cppVar_23608 = cppVar_23616;
	} else {
	cppVar_23617 = PC + 1;
	cppVar_23617 = (cppVar_23617 & cppMask_un_16_);
	cppVar_23618 = ROM.rd(cppVar_23617);
	cppVar_23619 = (cppVar_23618 >> 3) & cppMask_un_5_;
	cppVar_23620 = (cppVar_23619 & cppMask_un_5_);
	cppVar_23621 = cppVar_23620 + 32;
	cppVar_23621 = (cppVar_23621 & cppMask_un_8_);
	cppVar_23608 = cppVar_23621;
	}
	cppVar_23623 = (cppVar_23608 == 139);
	if (cppVar_23623) {
	cppVar_23607 = TL1;
	} else {
	cppVar_23626 = PC + 1;
	cppVar_23626 = (cppVar_23626 & cppMask_un_16_);
	cppVar_23627 = ROM.rd(cppVar_23626);
	cppVar_23628 = (cppVar_23627 >> 7) & cppMask_un_1_;
	cppVar_23629 = (cppVar_23628 == 1);
	if (cppVar_23629) {
	cppVar_23630 = PC + 1;
	cppVar_23630 = (cppVar_23630 & cppMask_un_16_);
	cppVar_23631 = ROM.rd(cppVar_23630);
	cppVar_23632 = (cppVar_23631 >> 3) & cppMask_un_5_;
	cppVar_23633 = (cppVar_23632 << 3) | 0;
	cppVar_23633 = (cppVar_23633 & cppMask_un_8_);
	cppVar_23625 = cppVar_23633;
	} else {
	cppVar_23634 = PC + 1;
	cppVar_23634 = (cppVar_23634 & cppMask_un_16_);
	cppVar_23635 = ROM.rd(cppVar_23634);
	cppVar_23636 = (cppVar_23635 >> 3) & cppMask_un_5_;
	cppVar_23637 = (cppVar_23636 & cppMask_un_5_);
	cppVar_23638 = cppVar_23637 + 32;
	cppVar_23638 = (cppVar_23638 & cppMask_un_8_);
	cppVar_23625 = cppVar_23638;
	}
	cppVar_23640 = (cppVar_23625 == 141);
	if (cppVar_23640) {
	cppVar_23624 = TH1;
	} else {
	cppVar_23643 = PC + 1;
	cppVar_23643 = (cppVar_23643 & cppMask_un_16_);
	cppVar_23644 = ROM.rd(cppVar_23643);
	cppVar_23645 = (cppVar_23644 >> 7) & cppMask_un_1_;
	cppVar_23646 = (cppVar_23645 == 1);
	if (cppVar_23646) {
	cppVar_23647 = PC + 1;
	cppVar_23647 = (cppVar_23647 & cppMask_un_16_);
	cppVar_23648 = ROM.rd(cppVar_23647);
	cppVar_23649 = (cppVar_23648 >> 3) & cppMask_un_5_;
	cppVar_23650 = (cppVar_23649 << 3) | 0;
	cppVar_23650 = (cppVar_23650 & cppMask_un_8_);
	cppVar_23642 = cppVar_23650;
	} else {
	cppVar_23651 = PC + 1;
	cppVar_23651 = (cppVar_23651 & cppMask_un_16_);
	cppVar_23652 = ROM.rd(cppVar_23651);
	cppVar_23653 = (cppVar_23652 >> 3) & cppMask_un_5_;
	cppVar_23654 = (cppVar_23653 & cppMask_un_5_);
	cppVar_23655 = cppVar_23654 + 32;
	cppVar_23655 = (cppVar_23655 & cppMask_un_8_);
	cppVar_23642 = cppVar_23655;
	}
	cppVar_23657 = (cppVar_23642 == 144);
	if (cppVar_23657) {
	cppVar_23641 = P1;
	} else {
	cppVar_23660 = PC + 1;
	cppVar_23660 = (cppVar_23660 & cppMask_un_16_);
	cppVar_23661 = ROM.rd(cppVar_23660);
	cppVar_23662 = (cppVar_23661 >> 7) & cppMask_un_1_;
	cppVar_23663 = (cppVar_23662 == 1);
	if (cppVar_23663) {
	cppVar_23664 = PC + 1;
	cppVar_23664 = (cppVar_23664 & cppMask_un_16_);
	cppVar_23665 = ROM.rd(cppVar_23664);
	cppVar_23666 = (cppVar_23665 >> 3) & cppMask_un_5_;
	cppVar_23667 = (cppVar_23666 << 3) | 0;
	cppVar_23667 = (cppVar_23667 & cppMask_un_8_);
	cppVar_23659 = cppVar_23667;
	} else {
	cppVar_23668 = PC + 1;
	cppVar_23668 = (cppVar_23668 & cppMask_un_16_);
	cppVar_23669 = ROM.rd(cppVar_23668);
	cppVar_23670 = (cppVar_23669 >> 3) & cppMask_un_5_;
	cppVar_23671 = (cppVar_23670 & cppMask_un_5_);
	cppVar_23672 = cppVar_23671 + 32;
	cppVar_23672 = (cppVar_23672 & cppMask_un_8_);
	cppVar_23659 = cppVar_23672;
	}
	cppVar_23674 = (cppVar_23659 == 152);
	if (cppVar_23674) {
	cppVar_23658 = SCON;
	} else {
	cppVar_23677 = PC + 1;
	cppVar_23677 = (cppVar_23677 & cppMask_un_16_);
	cppVar_23678 = ROM.rd(cppVar_23677);
	cppVar_23679 = (cppVar_23678 >> 7) & cppMask_un_1_;
	cppVar_23680 = (cppVar_23679 == 1);
	if (cppVar_23680) {
	cppVar_23681 = PC + 1;
	cppVar_23681 = (cppVar_23681 & cppMask_un_16_);
	cppVar_23682 = ROM.rd(cppVar_23681);
	cppVar_23683 = (cppVar_23682 >> 3) & cppMask_un_5_;
	cppVar_23684 = (cppVar_23683 << 3) | 0;
	cppVar_23684 = (cppVar_23684 & cppMask_un_8_);
	cppVar_23676 = cppVar_23684;
	} else {
	cppVar_23685 = PC + 1;
	cppVar_23685 = (cppVar_23685 & cppMask_un_16_);
	cppVar_23686 = ROM.rd(cppVar_23685);
	cppVar_23687 = (cppVar_23686 >> 3) & cppMask_un_5_;
	cppVar_23688 = (cppVar_23687 & cppMask_un_5_);
	cppVar_23689 = cppVar_23688 + 32;
	cppVar_23689 = (cppVar_23689 & cppMask_un_8_);
	cppVar_23676 = cppVar_23689;
	}
	cppVar_23691 = (cppVar_23676 == 153);
	if (cppVar_23691) {
	cppVar_23675 = SBUF;
	} else {
	cppVar_23694 = PC + 1;
	cppVar_23694 = (cppVar_23694 & cppMask_un_16_);
	cppVar_23695 = ROM.rd(cppVar_23694);
	cppVar_23696 = (cppVar_23695 >> 7) & cppMask_un_1_;
	cppVar_23697 = (cppVar_23696 == 1);
	if (cppVar_23697) {
	cppVar_23698 = PC + 1;
	cppVar_23698 = (cppVar_23698 & cppMask_un_16_);
	cppVar_23699 = ROM.rd(cppVar_23698);
	cppVar_23700 = (cppVar_23699 >> 3) & cppMask_un_5_;
	cppVar_23701 = (cppVar_23700 << 3) | 0;
	cppVar_23701 = (cppVar_23701 & cppMask_un_8_);
	cppVar_23693 = cppVar_23701;
	} else {
	cppVar_23702 = PC + 1;
	cppVar_23702 = (cppVar_23702 & cppMask_un_16_);
	cppVar_23703 = ROM.rd(cppVar_23702);
	cppVar_23704 = (cppVar_23703 >> 3) & cppMask_un_5_;
	cppVar_23705 = (cppVar_23704 & cppMask_un_5_);
	cppVar_23706 = cppVar_23705 + 32;
	cppVar_23706 = (cppVar_23706 & cppMask_un_8_);
	cppVar_23693 = cppVar_23706;
	}
	cppVar_23708 = (cppVar_23693 == 160);
	if (cppVar_23708) {
	cppVar_23692 = P2;
	} else {
	cppVar_23711 = PC + 1;
	cppVar_23711 = (cppVar_23711 & cppMask_un_16_);
	cppVar_23712 = ROM.rd(cppVar_23711);
	cppVar_23713 = (cppVar_23712 >> 7) & cppMask_un_1_;
	cppVar_23714 = (cppVar_23713 == 1);
	if (cppVar_23714) {
	cppVar_23715 = PC + 1;
	cppVar_23715 = (cppVar_23715 & cppMask_un_16_);
	cppVar_23716 = ROM.rd(cppVar_23715);
	cppVar_23717 = (cppVar_23716 >> 3) & cppMask_un_5_;
	cppVar_23718 = (cppVar_23717 << 3) | 0;
	cppVar_23718 = (cppVar_23718 & cppMask_un_8_);
	cppVar_23710 = cppVar_23718;
	} else {
	cppVar_23719 = PC + 1;
	cppVar_23719 = (cppVar_23719 & cppMask_un_16_);
	cppVar_23720 = ROM.rd(cppVar_23719);
	cppVar_23721 = (cppVar_23720 >> 3) & cppMask_un_5_;
	cppVar_23722 = (cppVar_23721 & cppMask_un_5_);
	cppVar_23723 = cppVar_23722 + 32;
	cppVar_23723 = (cppVar_23723 & cppMask_un_8_);
	cppVar_23710 = cppVar_23723;
	}
	cppVar_23725 = (cppVar_23710 == 168);
	if (cppVar_23725) {
	cppVar_23709 = IE;
	} else {
	cppVar_23728 = PC + 1;
	cppVar_23728 = (cppVar_23728 & cppMask_un_16_);
	cppVar_23729 = ROM.rd(cppVar_23728);
	cppVar_23730 = (cppVar_23729 >> 7) & cppMask_un_1_;
	cppVar_23731 = (cppVar_23730 == 1);
	if (cppVar_23731) {
	cppVar_23732 = PC + 1;
	cppVar_23732 = (cppVar_23732 & cppMask_un_16_);
	cppVar_23733 = ROM.rd(cppVar_23732);
	cppVar_23734 = (cppVar_23733 >> 3) & cppMask_un_5_;
	cppVar_23735 = (cppVar_23734 << 3) | 0;
	cppVar_23735 = (cppVar_23735 & cppMask_un_8_);
	cppVar_23727 = cppVar_23735;
	} else {
	cppVar_23736 = PC + 1;
	cppVar_23736 = (cppVar_23736 & cppMask_un_16_);
	cppVar_23737 = ROM.rd(cppVar_23736);
	cppVar_23738 = (cppVar_23737 >> 3) & cppMask_un_5_;
	cppVar_23739 = (cppVar_23738 & cppMask_un_5_);
	cppVar_23740 = cppVar_23739 + 32;
	cppVar_23740 = (cppVar_23740 & cppMask_un_8_);
	cppVar_23727 = cppVar_23740;
	}
	cppVar_23742 = (cppVar_23727 == 176);
	if (cppVar_23742) {
	cppVar_23726 = P3;
	} else {
	cppVar_23745 = PC + 1;
	cppVar_23745 = (cppVar_23745 & cppMask_un_16_);
	cppVar_23746 = ROM.rd(cppVar_23745);
	cppVar_23747 = (cppVar_23746 >> 7) & cppMask_un_1_;
	cppVar_23748 = (cppVar_23747 == 1);
	if (cppVar_23748) {
	cppVar_23749 = PC + 1;
	cppVar_23749 = (cppVar_23749 & cppMask_un_16_);
	cppVar_23750 = ROM.rd(cppVar_23749);
	cppVar_23751 = (cppVar_23750 >> 3) & cppMask_un_5_;
	cppVar_23752 = (cppVar_23751 << 3) | 0;
	cppVar_23752 = (cppVar_23752 & cppMask_un_8_);
	cppVar_23744 = cppVar_23752;
	} else {
	cppVar_23753 = PC + 1;
	cppVar_23753 = (cppVar_23753 & cppMask_un_16_);
	cppVar_23754 = ROM.rd(cppVar_23753);
	cppVar_23755 = (cppVar_23754 >> 3) & cppMask_un_5_;
	cppVar_23756 = (cppVar_23755 & cppMask_un_5_);
	cppVar_23757 = cppVar_23756 + 32;
	cppVar_23757 = (cppVar_23757 & cppMask_un_8_);
	cppVar_23744 = cppVar_23757;
	}
	cppVar_23759 = (cppVar_23744 == 184);
	if (cppVar_23759) {
	cppVar_23743 = IP;
	} else {
	cppVar_23762 = PC + 1;
	cppVar_23762 = (cppVar_23762 & cppMask_un_16_);
	cppVar_23763 = ROM.rd(cppVar_23762);
	cppVar_23764 = (cppVar_23763 >> 7) & cppMask_un_1_;
	cppVar_23765 = (cppVar_23764 == 1);
	if (cppVar_23765) {
	cppVar_23766 = PC + 1;
	cppVar_23766 = (cppVar_23766 & cppMask_un_16_);
	cppVar_23767 = ROM.rd(cppVar_23766);
	cppVar_23768 = (cppVar_23767 >> 3) & cppMask_un_5_;
	cppVar_23769 = (cppVar_23768 << 3) | 0;
	cppVar_23769 = (cppVar_23769 & cppMask_un_8_);
	cppVar_23761 = cppVar_23769;
	} else {
	cppVar_23770 = PC + 1;
	cppVar_23770 = (cppVar_23770 & cppMask_un_16_);
	cppVar_23771 = ROM.rd(cppVar_23770);
	cppVar_23772 = (cppVar_23771 >> 3) & cppMask_un_5_;
	cppVar_23773 = (cppVar_23772 & cppMask_un_5_);
	cppVar_23774 = cppVar_23773 + 32;
	cppVar_23774 = (cppVar_23774 & cppMask_un_8_);
	cppVar_23761 = cppVar_23774;
	}
	cppVar_23776 = (cppVar_23761 == 208);
	if (cppVar_23776) {
	cppVar_23760 = PSW;
	} else {
	cppVar_23779 = PC + 1;
	cppVar_23779 = (cppVar_23779 & cppMask_un_16_);
	cppVar_23780 = ROM.rd(cppVar_23779);
	cppVar_23781 = (cppVar_23780 >> 7) & cppMask_un_1_;
	cppVar_23782 = (cppVar_23781 == 1);
	if (cppVar_23782) {
	cppVar_23783 = PC + 1;
	cppVar_23783 = (cppVar_23783 & cppMask_un_16_);
	cppVar_23784 = ROM.rd(cppVar_23783);
	cppVar_23785 = (cppVar_23784 >> 3) & cppMask_un_5_;
	cppVar_23786 = (cppVar_23785 << 3) | 0;
	cppVar_23786 = (cppVar_23786 & cppMask_un_8_);
	cppVar_23778 = cppVar_23786;
	} else {
	cppVar_23787 = PC + 1;
	cppVar_23787 = (cppVar_23787 & cppMask_un_16_);
	cppVar_23788 = ROM.rd(cppVar_23787);
	cppVar_23789 = (cppVar_23788 >> 3) & cppMask_un_5_;
	cppVar_23790 = (cppVar_23789 & cppMask_un_5_);
	cppVar_23791 = cppVar_23790 + 32;
	cppVar_23791 = (cppVar_23791 & cppMask_un_8_);
	cppVar_23778 = cppVar_23791;
	}
	cppVar_23793 = (cppVar_23778 == 224);
	if (cppVar_23793) {
	cppVar_23777 = ACC;
	} else {
	cppVar_23796 = PC + 1;
	cppVar_23796 = (cppVar_23796 & cppMask_un_16_);
	cppVar_23797 = ROM.rd(cppVar_23796);
	cppVar_23798 = (cppVar_23797 >> 7) & cppMask_un_1_;
	cppVar_23799 = (cppVar_23798 == 1);
	if (cppVar_23799) {
	cppVar_23800 = PC + 1;
	cppVar_23800 = (cppVar_23800 & cppMask_un_16_);
	cppVar_23801 = ROM.rd(cppVar_23800);
	cppVar_23802 = (cppVar_23801 >> 3) & cppMask_un_5_;
	cppVar_23803 = (cppVar_23802 << 3) | 0;
	cppVar_23803 = (cppVar_23803 & cppMask_un_8_);
	cppVar_23795 = cppVar_23803;
	} else {
	cppVar_23804 = PC + 1;
	cppVar_23804 = (cppVar_23804 & cppMask_un_16_);
	cppVar_23805 = ROM.rd(cppVar_23804);
	cppVar_23806 = (cppVar_23805 >> 3) & cppMask_un_5_;
	cppVar_23807 = (cppVar_23806 & cppMask_un_5_);
	cppVar_23808 = cppVar_23807 + 32;
	cppVar_23808 = (cppVar_23808 & cppMask_un_8_);
	cppVar_23795 = cppVar_23808;
	}
	cppVar_23810 = (cppVar_23795 == 240);
	if (cppVar_23810) {
	cppVar_23794 = B;
	} else {
	cppVar_23794 = 0;
	}
	cppVar_23777 = cppVar_23794;
	}
	cppVar_23760 = cppVar_23777;
	}
	cppVar_23743 = cppVar_23760;
	}
	cppVar_23726 = cppVar_23743;
	}
	cppVar_23709 = cppVar_23726;
	}
	cppVar_23692 = cppVar_23709;
	}
	cppVar_23675 = cppVar_23692;
	}
	cppVar_23658 = cppVar_23675;
	}
	cppVar_23641 = cppVar_23658;
	}
	cppVar_23624 = cppVar_23641;
	}
	cppVar_23607 = cppVar_23624;
	}
	cppVar_23590 = cppVar_23607;
	}
	cppVar_23573 = cppVar_23590;
	}
	cppVar_23556 = cppVar_23573;
	}
	cppVar_23539 = cppVar_23556;
	}
	cppVar_23522 = cppVar_23539;
	}
	cppVar_23505 = cppVar_23522;
	}
	cppVar_23488 = cppVar_23505;
	}
	cppVar_23471 = cppVar_23488;
	}
	cppVar_23454 = cppVar_23471;
	}
	cppVar_23418 = cppVar_23454;
	}
	cppVar_23812 = PC + 1;
	cppVar_23812 = (cppVar_23812 & cppMask_un_16_);
	cppVar_23813 = ROM.rd(cppVar_23812);
	cppVar_23814 = (cppVar_23813 >> 0) & cppMask_un_3_;
	cppVar_23815 = (cppVar_23418 >> static_cast<unsigned>(cppVar_23814)) & 0x1;
	cppVar_23816 = ~cppVar_23815;
	cppVar_23817 = (cppVar_23816 & cppMask_un_1_);
	cppVar_23818 = PC + 1;
	cppVar_23818 = (cppVar_23818 & cppMask_un_16_);
	cppVar_23819 = ROM.rd(cppVar_23818);
	cppVar_23820 = (cppVar_23819 >> 0) & cppMask_un_3_;
	cppVar_23821 = (cppVar_23820 & cppMask_un_3_);
	cppVar_23822 = cppVar_23817 << static_cast<unsigned>(cppVar_23821);
	cppVar_23822 = (cppVar_23822 & cppMask_un_8_);
	cppVar_23823 = cppVar_23417 | cppVar_23822;
	cppVar_22998 = cppVar_23823;
	} else {
	cppVar_22998 = P0;
	}
	cppVar_22994 = cppVar_22998;
	} else {
	cppVar_23825 = ROM.rd(PC);
	cppVar_23827 = (cppVar_23825 == 146);
	if (cppVar_23827) {
	cppVar_23831 = PC + 1;
	cppVar_23831 = (cppVar_23831 & cppMask_un_16_);
	cppVar_23832 = ROM.rd(cppVar_23831);
	cppVar_23833 = (cppVar_23832 >> 7) & cppMask_un_1_;
	cppVar_23835 = (cppVar_23833 == 1);
	if (cppVar_23835) {
	cppVar_23836 = PC + 1;
	cppVar_23836 = (cppVar_23836 & cppMask_un_16_);
	cppVar_23837 = ROM.rd(cppVar_23836);
	cppVar_23838 = (cppVar_23837 >> 3) & cppMask_un_5_;
	cppVar_23840 = (cppVar_23838 << 3) | 0;
	cppVar_23840 = (cppVar_23840 & cppMask_un_8_);
	cppVar_23829 = cppVar_23840;
	} else {
	cppVar_23841 = PC + 1;
	cppVar_23841 = (cppVar_23841 & cppMask_un_16_);
	cppVar_23842 = ROM.rd(cppVar_23841);
	cppVar_23843 = (cppVar_23842 >> 3) & cppMask_un_5_;
	cppVar_23844 = (cppVar_23843 & cppMask_un_5_);
	cppVar_23846 = cppVar_23844 + 32;
	cppVar_23846 = (cppVar_23846 & cppMask_un_8_);
	cppVar_23829 = cppVar_23846;
	}
	cppVar_23848 = (cppVar_23829 == 128);
	if (cppVar_23848) {
	cppVar_23850 = PC + 1;
	cppVar_23850 = (cppVar_23850 & cppMask_un_16_);
	cppVar_23851 = ROM.rd(cppVar_23850);
	cppVar_23852 = (cppVar_23851 >> 0) & cppMask_un_3_;
	cppVar_23853 = (cppVar_23852 & cppMask_un_3_);
	cppVar_23854 = 1 << static_cast<unsigned>(cppVar_23853);
	cppVar_23854 = (cppVar_23854 & cppMask_un_8_);
	cppVar_23855 = ~cppVar_23854;
	cppVar_23858 = PC + 1;
	cppVar_23858 = (cppVar_23858 & cppMask_un_16_);
	cppVar_23859 = ROM.rd(cppVar_23858);
	cppVar_23860 = (cppVar_23859 >> 7) & cppMask_un_1_;
	cppVar_23861 = (cppVar_23860 == 1);
	if (cppVar_23861) {
	cppVar_23862 = PC + 1;
	cppVar_23862 = (cppVar_23862 & cppMask_un_16_);
	cppVar_23863 = ROM.rd(cppVar_23862);
	cppVar_23864 = (cppVar_23863 >> 3) & cppMask_un_5_;
	cppVar_23865 = (cppVar_23864 << 3) | 0;
	cppVar_23865 = (cppVar_23865 & cppMask_un_8_);
	cppVar_23857 = cppVar_23865;
	} else {
	cppVar_23866 = PC + 1;
	cppVar_23866 = (cppVar_23866 & cppMask_un_16_);
	cppVar_23867 = ROM.rd(cppVar_23866);
	cppVar_23868 = (cppVar_23867 >> 3) & cppMask_un_5_;
	cppVar_23869 = (cppVar_23868 & cppMask_un_5_);
	cppVar_23870 = cppVar_23869 + 32;
	cppVar_23870 = (cppVar_23870 & cppMask_un_8_);
	cppVar_23857 = cppVar_23870;
	}
	cppVar_23871 = (cppVar_23857 >> 7) & cppMask_un_1_;
	cppVar_23873 = (cppVar_23871 == 0);
	if (cppVar_23873) {
	cppVar_23875 = PC + 1;
	cppVar_23875 = (cppVar_23875 & cppMask_un_16_);
	cppVar_23876 = ROM.rd(cppVar_23875);
	cppVar_23877 = (cppVar_23876 >> 7) & cppMask_un_1_;
	cppVar_23878 = (cppVar_23877 == 1);
	if (cppVar_23878) {
	cppVar_23879 = PC + 1;
	cppVar_23879 = (cppVar_23879 & cppMask_un_16_);
	cppVar_23880 = ROM.rd(cppVar_23879);
	cppVar_23881 = (cppVar_23880 >> 3) & cppMask_un_5_;
	cppVar_23882 = (cppVar_23881 << 3) | 0;
	cppVar_23882 = (cppVar_23882 & cppMask_un_8_);
	cppVar_23874 = cppVar_23882;
	} else {
	cppVar_23883 = PC + 1;
	cppVar_23883 = (cppVar_23883 & cppMask_un_16_);
	cppVar_23884 = ROM.rd(cppVar_23883);
	cppVar_23885 = (cppVar_23884 >> 3) & cppMask_un_5_;
	cppVar_23886 = (cppVar_23885 & cppMask_un_5_);
	cppVar_23887 = cppVar_23886 + 32;
	cppVar_23887 = (cppVar_23887 & cppMask_un_8_);
	cppVar_23874 = cppVar_23887;
	}
	cppVar_23888 = IRAM.rd(cppVar_23874);
	cppVar_23856 = cppVar_23888;
	} else {
	cppVar_23891 = PC + 1;
	cppVar_23891 = (cppVar_23891 & cppMask_un_16_);
	cppVar_23892 = ROM.rd(cppVar_23891);
	cppVar_23893 = (cppVar_23892 >> 7) & cppMask_un_1_;
	cppVar_23894 = (cppVar_23893 == 1);
	if (cppVar_23894) {
	cppVar_23895 = PC + 1;
	cppVar_23895 = (cppVar_23895 & cppMask_un_16_);
	cppVar_23896 = ROM.rd(cppVar_23895);
	cppVar_23897 = (cppVar_23896 >> 3) & cppMask_un_5_;
	cppVar_23898 = (cppVar_23897 << 3) | 0;
	cppVar_23898 = (cppVar_23898 & cppMask_un_8_);
	cppVar_23890 = cppVar_23898;
	} else {
	cppVar_23899 = PC + 1;
	cppVar_23899 = (cppVar_23899 & cppMask_un_16_);
	cppVar_23900 = ROM.rd(cppVar_23899);
	cppVar_23901 = (cppVar_23900 >> 3) & cppMask_un_5_;
	cppVar_23902 = (cppVar_23901 & cppMask_un_5_);
	cppVar_23903 = cppVar_23902 + 32;
	cppVar_23903 = (cppVar_23903 & cppMask_un_8_);
	cppVar_23890 = cppVar_23903;
	}
	cppVar_23905 = (cppVar_23890 == 128);
	if (cppVar_23905) {
	cppVar_23889 = P0;
	} else {
	cppVar_23908 = PC + 1;
	cppVar_23908 = (cppVar_23908 & cppMask_un_16_);
	cppVar_23909 = ROM.rd(cppVar_23908);
	cppVar_23910 = (cppVar_23909 >> 7) & cppMask_un_1_;
	cppVar_23911 = (cppVar_23910 == 1);
	if (cppVar_23911) {
	cppVar_23912 = PC + 1;
	cppVar_23912 = (cppVar_23912 & cppMask_un_16_);
	cppVar_23913 = ROM.rd(cppVar_23912);
	cppVar_23914 = (cppVar_23913 >> 3) & cppMask_un_5_;
	cppVar_23915 = (cppVar_23914 << 3) | 0;
	cppVar_23915 = (cppVar_23915 & cppMask_un_8_);
	cppVar_23907 = cppVar_23915;
	} else {
	cppVar_23916 = PC + 1;
	cppVar_23916 = (cppVar_23916 & cppMask_un_16_);
	cppVar_23917 = ROM.rd(cppVar_23916);
	cppVar_23918 = (cppVar_23917 >> 3) & cppMask_un_5_;
	cppVar_23919 = (cppVar_23918 & cppMask_un_5_);
	cppVar_23920 = cppVar_23919 + 32;
	cppVar_23920 = (cppVar_23920 & cppMask_un_8_);
	cppVar_23907 = cppVar_23920;
	}
	cppVar_23922 = (cppVar_23907 == 129);
	if (cppVar_23922) {
	cppVar_23906 = SP;
	} else {
	cppVar_23925 = PC + 1;
	cppVar_23925 = (cppVar_23925 & cppMask_un_16_);
	cppVar_23926 = ROM.rd(cppVar_23925);
	cppVar_23927 = (cppVar_23926 >> 7) & cppMask_un_1_;
	cppVar_23928 = (cppVar_23927 == 1);
	if (cppVar_23928) {
	cppVar_23929 = PC + 1;
	cppVar_23929 = (cppVar_23929 & cppMask_un_16_);
	cppVar_23930 = ROM.rd(cppVar_23929);
	cppVar_23931 = (cppVar_23930 >> 3) & cppMask_un_5_;
	cppVar_23932 = (cppVar_23931 << 3) | 0;
	cppVar_23932 = (cppVar_23932 & cppMask_un_8_);
	cppVar_23924 = cppVar_23932;
	} else {
	cppVar_23933 = PC + 1;
	cppVar_23933 = (cppVar_23933 & cppMask_un_16_);
	cppVar_23934 = ROM.rd(cppVar_23933);
	cppVar_23935 = (cppVar_23934 >> 3) & cppMask_un_5_;
	cppVar_23936 = (cppVar_23935 & cppMask_un_5_);
	cppVar_23937 = cppVar_23936 + 32;
	cppVar_23937 = (cppVar_23937 & cppMask_un_8_);
	cppVar_23924 = cppVar_23937;
	}
	cppVar_23939 = (cppVar_23924 == 130);
	if (cppVar_23939) {
	cppVar_23923 = DPL;
	} else {
	cppVar_23942 = PC + 1;
	cppVar_23942 = (cppVar_23942 & cppMask_un_16_);
	cppVar_23943 = ROM.rd(cppVar_23942);
	cppVar_23944 = (cppVar_23943 >> 7) & cppMask_un_1_;
	cppVar_23945 = (cppVar_23944 == 1);
	if (cppVar_23945) {
	cppVar_23946 = PC + 1;
	cppVar_23946 = (cppVar_23946 & cppMask_un_16_);
	cppVar_23947 = ROM.rd(cppVar_23946);
	cppVar_23948 = (cppVar_23947 >> 3) & cppMask_un_5_;
	cppVar_23949 = (cppVar_23948 << 3) | 0;
	cppVar_23949 = (cppVar_23949 & cppMask_un_8_);
	cppVar_23941 = cppVar_23949;
	} else {
	cppVar_23950 = PC + 1;
	cppVar_23950 = (cppVar_23950 & cppMask_un_16_);
	cppVar_23951 = ROM.rd(cppVar_23950);
	cppVar_23952 = (cppVar_23951 >> 3) & cppMask_un_5_;
	cppVar_23953 = (cppVar_23952 & cppMask_un_5_);
	cppVar_23954 = cppVar_23953 + 32;
	cppVar_23954 = (cppVar_23954 & cppMask_un_8_);
	cppVar_23941 = cppVar_23954;
	}
	cppVar_23956 = (cppVar_23941 == 131);
	if (cppVar_23956) {
	cppVar_23940 = DPH;
	} else {
	cppVar_23959 = PC + 1;
	cppVar_23959 = (cppVar_23959 & cppMask_un_16_);
	cppVar_23960 = ROM.rd(cppVar_23959);
	cppVar_23961 = (cppVar_23960 >> 7) & cppMask_un_1_;
	cppVar_23962 = (cppVar_23961 == 1);
	if (cppVar_23962) {
	cppVar_23963 = PC + 1;
	cppVar_23963 = (cppVar_23963 & cppMask_un_16_);
	cppVar_23964 = ROM.rd(cppVar_23963);
	cppVar_23965 = (cppVar_23964 >> 3) & cppMask_un_5_;
	cppVar_23966 = (cppVar_23965 << 3) | 0;
	cppVar_23966 = (cppVar_23966 & cppMask_un_8_);
	cppVar_23958 = cppVar_23966;
	} else {
	cppVar_23967 = PC + 1;
	cppVar_23967 = (cppVar_23967 & cppMask_un_16_);
	cppVar_23968 = ROM.rd(cppVar_23967);
	cppVar_23969 = (cppVar_23968 >> 3) & cppMask_un_5_;
	cppVar_23970 = (cppVar_23969 & cppMask_un_5_);
	cppVar_23971 = cppVar_23970 + 32;
	cppVar_23971 = (cppVar_23971 & cppMask_un_8_);
	cppVar_23958 = cppVar_23971;
	}
	cppVar_23973 = (cppVar_23958 == 135);
	if (cppVar_23973) {
	cppVar_23957 = PCON;
	} else {
	cppVar_23976 = PC + 1;
	cppVar_23976 = (cppVar_23976 & cppMask_un_16_);
	cppVar_23977 = ROM.rd(cppVar_23976);
	cppVar_23978 = (cppVar_23977 >> 7) & cppMask_un_1_;
	cppVar_23979 = (cppVar_23978 == 1);
	if (cppVar_23979) {
	cppVar_23980 = PC + 1;
	cppVar_23980 = (cppVar_23980 & cppMask_un_16_);
	cppVar_23981 = ROM.rd(cppVar_23980);
	cppVar_23982 = (cppVar_23981 >> 3) & cppMask_un_5_;
	cppVar_23983 = (cppVar_23982 << 3) | 0;
	cppVar_23983 = (cppVar_23983 & cppMask_un_8_);
	cppVar_23975 = cppVar_23983;
	} else {
	cppVar_23984 = PC + 1;
	cppVar_23984 = (cppVar_23984 & cppMask_un_16_);
	cppVar_23985 = ROM.rd(cppVar_23984);
	cppVar_23986 = (cppVar_23985 >> 3) & cppMask_un_5_;
	cppVar_23987 = (cppVar_23986 & cppMask_un_5_);
	cppVar_23988 = cppVar_23987 + 32;
	cppVar_23988 = (cppVar_23988 & cppMask_un_8_);
	cppVar_23975 = cppVar_23988;
	}
	cppVar_23990 = (cppVar_23975 == 136);
	if (cppVar_23990) {
	cppVar_23974 = TCON;
	} else {
	cppVar_23993 = PC + 1;
	cppVar_23993 = (cppVar_23993 & cppMask_un_16_);
	cppVar_23994 = ROM.rd(cppVar_23993);
	cppVar_23995 = (cppVar_23994 >> 7) & cppMask_un_1_;
	cppVar_23996 = (cppVar_23995 == 1);
	if (cppVar_23996) {
	cppVar_23997 = PC + 1;
	cppVar_23997 = (cppVar_23997 & cppMask_un_16_);
	cppVar_23998 = ROM.rd(cppVar_23997);
	cppVar_23999 = (cppVar_23998 >> 3) & cppMask_un_5_;
	cppVar_24000 = (cppVar_23999 << 3) | 0;
	cppVar_24000 = (cppVar_24000 & cppMask_un_8_);
	cppVar_23992 = cppVar_24000;
	} else {
	cppVar_24001 = PC + 1;
	cppVar_24001 = (cppVar_24001 & cppMask_un_16_);
	cppVar_24002 = ROM.rd(cppVar_24001);
	cppVar_24003 = (cppVar_24002 >> 3) & cppMask_un_5_;
	cppVar_24004 = (cppVar_24003 & cppMask_un_5_);
	cppVar_24005 = cppVar_24004 + 32;
	cppVar_24005 = (cppVar_24005 & cppMask_un_8_);
	cppVar_23992 = cppVar_24005;
	}
	cppVar_24007 = (cppVar_23992 == 137);
	if (cppVar_24007) {
	cppVar_23991 = TMOD;
	} else {
	cppVar_24010 = PC + 1;
	cppVar_24010 = (cppVar_24010 & cppMask_un_16_);
	cppVar_24011 = ROM.rd(cppVar_24010);
	cppVar_24012 = (cppVar_24011 >> 7) & cppMask_un_1_;
	cppVar_24013 = (cppVar_24012 == 1);
	if (cppVar_24013) {
	cppVar_24014 = PC + 1;
	cppVar_24014 = (cppVar_24014 & cppMask_un_16_);
	cppVar_24015 = ROM.rd(cppVar_24014);
	cppVar_24016 = (cppVar_24015 >> 3) & cppMask_un_5_;
	cppVar_24017 = (cppVar_24016 << 3) | 0;
	cppVar_24017 = (cppVar_24017 & cppMask_un_8_);
	cppVar_24009 = cppVar_24017;
	} else {
	cppVar_24018 = PC + 1;
	cppVar_24018 = (cppVar_24018 & cppMask_un_16_);
	cppVar_24019 = ROM.rd(cppVar_24018);
	cppVar_24020 = (cppVar_24019 >> 3) & cppMask_un_5_;
	cppVar_24021 = (cppVar_24020 & cppMask_un_5_);
	cppVar_24022 = cppVar_24021 + 32;
	cppVar_24022 = (cppVar_24022 & cppMask_un_8_);
	cppVar_24009 = cppVar_24022;
	}
	cppVar_24024 = (cppVar_24009 == 138);
	if (cppVar_24024) {
	cppVar_24008 = TL0;
	} else {
	cppVar_24027 = PC + 1;
	cppVar_24027 = (cppVar_24027 & cppMask_un_16_);
	cppVar_24028 = ROM.rd(cppVar_24027);
	cppVar_24029 = (cppVar_24028 >> 7) & cppMask_un_1_;
	cppVar_24030 = (cppVar_24029 == 1);
	if (cppVar_24030) {
	cppVar_24031 = PC + 1;
	cppVar_24031 = (cppVar_24031 & cppMask_un_16_);
	cppVar_24032 = ROM.rd(cppVar_24031);
	cppVar_24033 = (cppVar_24032 >> 3) & cppMask_un_5_;
	cppVar_24034 = (cppVar_24033 << 3) | 0;
	cppVar_24034 = (cppVar_24034 & cppMask_un_8_);
	cppVar_24026 = cppVar_24034;
	} else {
	cppVar_24035 = PC + 1;
	cppVar_24035 = (cppVar_24035 & cppMask_un_16_);
	cppVar_24036 = ROM.rd(cppVar_24035);
	cppVar_24037 = (cppVar_24036 >> 3) & cppMask_un_5_;
	cppVar_24038 = (cppVar_24037 & cppMask_un_5_);
	cppVar_24039 = cppVar_24038 + 32;
	cppVar_24039 = (cppVar_24039 & cppMask_un_8_);
	cppVar_24026 = cppVar_24039;
	}
	cppVar_24041 = (cppVar_24026 == 140);
	if (cppVar_24041) {
	cppVar_24025 = TH0;
	} else {
	cppVar_24044 = PC + 1;
	cppVar_24044 = (cppVar_24044 & cppMask_un_16_);
	cppVar_24045 = ROM.rd(cppVar_24044);
	cppVar_24046 = (cppVar_24045 >> 7) & cppMask_un_1_;
	cppVar_24047 = (cppVar_24046 == 1);
	if (cppVar_24047) {
	cppVar_24048 = PC + 1;
	cppVar_24048 = (cppVar_24048 & cppMask_un_16_);
	cppVar_24049 = ROM.rd(cppVar_24048);
	cppVar_24050 = (cppVar_24049 >> 3) & cppMask_un_5_;
	cppVar_24051 = (cppVar_24050 << 3) | 0;
	cppVar_24051 = (cppVar_24051 & cppMask_un_8_);
	cppVar_24043 = cppVar_24051;
	} else {
	cppVar_24052 = PC + 1;
	cppVar_24052 = (cppVar_24052 & cppMask_un_16_);
	cppVar_24053 = ROM.rd(cppVar_24052);
	cppVar_24054 = (cppVar_24053 >> 3) & cppMask_un_5_;
	cppVar_24055 = (cppVar_24054 & cppMask_un_5_);
	cppVar_24056 = cppVar_24055 + 32;
	cppVar_24056 = (cppVar_24056 & cppMask_un_8_);
	cppVar_24043 = cppVar_24056;
	}
	cppVar_24058 = (cppVar_24043 == 139);
	if (cppVar_24058) {
	cppVar_24042 = TL1;
	} else {
	cppVar_24061 = PC + 1;
	cppVar_24061 = (cppVar_24061 & cppMask_un_16_);
	cppVar_24062 = ROM.rd(cppVar_24061);
	cppVar_24063 = (cppVar_24062 >> 7) & cppMask_un_1_;
	cppVar_24064 = (cppVar_24063 == 1);
	if (cppVar_24064) {
	cppVar_24065 = PC + 1;
	cppVar_24065 = (cppVar_24065 & cppMask_un_16_);
	cppVar_24066 = ROM.rd(cppVar_24065);
	cppVar_24067 = (cppVar_24066 >> 3) & cppMask_un_5_;
	cppVar_24068 = (cppVar_24067 << 3) | 0;
	cppVar_24068 = (cppVar_24068 & cppMask_un_8_);
	cppVar_24060 = cppVar_24068;
	} else {
	cppVar_24069 = PC + 1;
	cppVar_24069 = (cppVar_24069 & cppMask_un_16_);
	cppVar_24070 = ROM.rd(cppVar_24069);
	cppVar_24071 = (cppVar_24070 >> 3) & cppMask_un_5_;
	cppVar_24072 = (cppVar_24071 & cppMask_un_5_);
	cppVar_24073 = cppVar_24072 + 32;
	cppVar_24073 = (cppVar_24073 & cppMask_un_8_);
	cppVar_24060 = cppVar_24073;
	}
	cppVar_24075 = (cppVar_24060 == 141);
	if (cppVar_24075) {
	cppVar_24059 = TH1;
	} else {
	cppVar_24078 = PC + 1;
	cppVar_24078 = (cppVar_24078 & cppMask_un_16_);
	cppVar_24079 = ROM.rd(cppVar_24078);
	cppVar_24080 = (cppVar_24079 >> 7) & cppMask_un_1_;
	cppVar_24081 = (cppVar_24080 == 1);
	if (cppVar_24081) {
	cppVar_24082 = PC + 1;
	cppVar_24082 = (cppVar_24082 & cppMask_un_16_);
	cppVar_24083 = ROM.rd(cppVar_24082);
	cppVar_24084 = (cppVar_24083 >> 3) & cppMask_un_5_;
	cppVar_24085 = (cppVar_24084 << 3) | 0;
	cppVar_24085 = (cppVar_24085 & cppMask_un_8_);
	cppVar_24077 = cppVar_24085;
	} else {
	cppVar_24086 = PC + 1;
	cppVar_24086 = (cppVar_24086 & cppMask_un_16_);
	cppVar_24087 = ROM.rd(cppVar_24086);
	cppVar_24088 = (cppVar_24087 >> 3) & cppMask_un_5_;
	cppVar_24089 = (cppVar_24088 & cppMask_un_5_);
	cppVar_24090 = cppVar_24089 + 32;
	cppVar_24090 = (cppVar_24090 & cppMask_un_8_);
	cppVar_24077 = cppVar_24090;
	}
	cppVar_24092 = (cppVar_24077 == 144);
	if (cppVar_24092) {
	cppVar_24076 = P1;
	} else {
	cppVar_24095 = PC + 1;
	cppVar_24095 = (cppVar_24095 & cppMask_un_16_);
	cppVar_24096 = ROM.rd(cppVar_24095);
	cppVar_24097 = (cppVar_24096 >> 7) & cppMask_un_1_;
	cppVar_24098 = (cppVar_24097 == 1);
	if (cppVar_24098) {
	cppVar_24099 = PC + 1;
	cppVar_24099 = (cppVar_24099 & cppMask_un_16_);
	cppVar_24100 = ROM.rd(cppVar_24099);
	cppVar_24101 = (cppVar_24100 >> 3) & cppMask_un_5_;
	cppVar_24102 = (cppVar_24101 << 3) | 0;
	cppVar_24102 = (cppVar_24102 & cppMask_un_8_);
	cppVar_24094 = cppVar_24102;
	} else {
	cppVar_24103 = PC + 1;
	cppVar_24103 = (cppVar_24103 & cppMask_un_16_);
	cppVar_24104 = ROM.rd(cppVar_24103);
	cppVar_24105 = (cppVar_24104 >> 3) & cppMask_un_5_;
	cppVar_24106 = (cppVar_24105 & cppMask_un_5_);
	cppVar_24107 = cppVar_24106 + 32;
	cppVar_24107 = (cppVar_24107 & cppMask_un_8_);
	cppVar_24094 = cppVar_24107;
	}
	cppVar_24109 = (cppVar_24094 == 152);
	if (cppVar_24109) {
	cppVar_24093 = SCON;
	} else {
	cppVar_24112 = PC + 1;
	cppVar_24112 = (cppVar_24112 & cppMask_un_16_);
	cppVar_24113 = ROM.rd(cppVar_24112);
	cppVar_24114 = (cppVar_24113 >> 7) & cppMask_un_1_;
	cppVar_24115 = (cppVar_24114 == 1);
	if (cppVar_24115) {
	cppVar_24116 = PC + 1;
	cppVar_24116 = (cppVar_24116 & cppMask_un_16_);
	cppVar_24117 = ROM.rd(cppVar_24116);
	cppVar_24118 = (cppVar_24117 >> 3) & cppMask_un_5_;
	cppVar_24119 = (cppVar_24118 << 3) | 0;
	cppVar_24119 = (cppVar_24119 & cppMask_un_8_);
	cppVar_24111 = cppVar_24119;
	} else {
	cppVar_24120 = PC + 1;
	cppVar_24120 = (cppVar_24120 & cppMask_un_16_);
	cppVar_24121 = ROM.rd(cppVar_24120);
	cppVar_24122 = (cppVar_24121 >> 3) & cppMask_un_5_;
	cppVar_24123 = (cppVar_24122 & cppMask_un_5_);
	cppVar_24124 = cppVar_24123 + 32;
	cppVar_24124 = (cppVar_24124 & cppMask_un_8_);
	cppVar_24111 = cppVar_24124;
	}
	cppVar_24126 = (cppVar_24111 == 153);
	if (cppVar_24126) {
	cppVar_24110 = SBUF;
	} else {
	cppVar_24129 = PC + 1;
	cppVar_24129 = (cppVar_24129 & cppMask_un_16_);
	cppVar_24130 = ROM.rd(cppVar_24129);
	cppVar_24131 = (cppVar_24130 >> 7) & cppMask_un_1_;
	cppVar_24132 = (cppVar_24131 == 1);
	if (cppVar_24132) {
	cppVar_24133 = PC + 1;
	cppVar_24133 = (cppVar_24133 & cppMask_un_16_);
	cppVar_24134 = ROM.rd(cppVar_24133);
	cppVar_24135 = (cppVar_24134 >> 3) & cppMask_un_5_;
	cppVar_24136 = (cppVar_24135 << 3) | 0;
	cppVar_24136 = (cppVar_24136 & cppMask_un_8_);
	cppVar_24128 = cppVar_24136;
	} else {
	cppVar_24137 = PC + 1;
	cppVar_24137 = (cppVar_24137 & cppMask_un_16_);
	cppVar_24138 = ROM.rd(cppVar_24137);
	cppVar_24139 = (cppVar_24138 >> 3) & cppMask_un_5_;
	cppVar_24140 = (cppVar_24139 & cppMask_un_5_);
	cppVar_24141 = cppVar_24140 + 32;
	cppVar_24141 = (cppVar_24141 & cppMask_un_8_);
	cppVar_24128 = cppVar_24141;
	}
	cppVar_24143 = (cppVar_24128 == 160);
	if (cppVar_24143) {
	cppVar_24127 = P2;
	} else {
	cppVar_24146 = PC + 1;
	cppVar_24146 = (cppVar_24146 & cppMask_un_16_);
	cppVar_24147 = ROM.rd(cppVar_24146);
	cppVar_24148 = (cppVar_24147 >> 7) & cppMask_un_1_;
	cppVar_24149 = (cppVar_24148 == 1);
	if (cppVar_24149) {
	cppVar_24150 = PC + 1;
	cppVar_24150 = (cppVar_24150 & cppMask_un_16_);
	cppVar_24151 = ROM.rd(cppVar_24150);
	cppVar_24152 = (cppVar_24151 >> 3) & cppMask_un_5_;
	cppVar_24153 = (cppVar_24152 << 3) | 0;
	cppVar_24153 = (cppVar_24153 & cppMask_un_8_);
	cppVar_24145 = cppVar_24153;
	} else {
	cppVar_24154 = PC + 1;
	cppVar_24154 = (cppVar_24154 & cppMask_un_16_);
	cppVar_24155 = ROM.rd(cppVar_24154);
	cppVar_24156 = (cppVar_24155 >> 3) & cppMask_un_5_;
	cppVar_24157 = (cppVar_24156 & cppMask_un_5_);
	cppVar_24158 = cppVar_24157 + 32;
	cppVar_24158 = (cppVar_24158 & cppMask_un_8_);
	cppVar_24145 = cppVar_24158;
	}
	cppVar_24160 = (cppVar_24145 == 168);
	if (cppVar_24160) {
	cppVar_24144 = IE;
	} else {
	cppVar_24163 = PC + 1;
	cppVar_24163 = (cppVar_24163 & cppMask_un_16_);
	cppVar_24164 = ROM.rd(cppVar_24163);
	cppVar_24165 = (cppVar_24164 >> 7) & cppMask_un_1_;
	cppVar_24166 = (cppVar_24165 == 1);
	if (cppVar_24166) {
	cppVar_24167 = PC + 1;
	cppVar_24167 = (cppVar_24167 & cppMask_un_16_);
	cppVar_24168 = ROM.rd(cppVar_24167);
	cppVar_24169 = (cppVar_24168 >> 3) & cppMask_un_5_;
	cppVar_24170 = (cppVar_24169 << 3) | 0;
	cppVar_24170 = (cppVar_24170 & cppMask_un_8_);
	cppVar_24162 = cppVar_24170;
	} else {
	cppVar_24171 = PC + 1;
	cppVar_24171 = (cppVar_24171 & cppMask_un_16_);
	cppVar_24172 = ROM.rd(cppVar_24171);
	cppVar_24173 = (cppVar_24172 >> 3) & cppMask_un_5_;
	cppVar_24174 = (cppVar_24173 & cppMask_un_5_);
	cppVar_24175 = cppVar_24174 + 32;
	cppVar_24175 = (cppVar_24175 & cppMask_un_8_);
	cppVar_24162 = cppVar_24175;
	}
	cppVar_24177 = (cppVar_24162 == 176);
	if (cppVar_24177) {
	cppVar_24161 = P3;
	} else {
	cppVar_24180 = PC + 1;
	cppVar_24180 = (cppVar_24180 & cppMask_un_16_);
	cppVar_24181 = ROM.rd(cppVar_24180);
	cppVar_24182 = (cppVar_24181 >> 7) & cppMask_un_1_;
	cppVar_24183 = (cppVar_24182 == 1);
	if (cppVar_24183) {
	cppVar_24184 = PC + 1;
	cppVar_24184 = (cppVar_24184 & cppMask_un_16_);
	cppVar_24185 = ROM.rd(cppVar_24184);
	cppVar_24186 = (cppVar_24185 >> 3) & cppMask_un_5_;
	cppVar_24187 = (cppVar_24186 << 3) | 0;
	cppVar_24187 = (cppVar_24187 & cppMask_un_8_);
	cppVar_24179 = cppVar_24187;
	} else {
	cppVar_24188 = PC + 1;
	cppVar_24188 = (cppVar_24188 & cppMask_un_16_);
	cppVar_24189 = ROM.rd(cppVar_24188);
	cppVar_24190 = (cppVar_24189 >> 3) & cppMask_un_5_;
	cppVar_24191 = (cppVar_24190 & cppMask_un_5_);
	cppVar_24192 = cppVar_24191 + 32;
	cppVar_24192 = (cppVar_24192 & cppMask_un_8_);
	cppVar_24179 = cppVar_24192;
	}
	cppVar_24194 = (cppVar_24179 == 184);
	if (cppVar_24194) {
	cppVar_24178 = IP;
	} else {
	cppVar_24197 = PC + 1;
	cppVar_24197 = (cppVar_24197 & cppMask_un_16_);
	cppVar_24198 = ROM.rd(cppVar_24197);
	cppVar_24199 = (cppVar_24198 >> 7) & cppMask_un_1_;
	cppVar_24200 = (cppVar_24199 == 1);
	if (cppVar_24200) {
	cppVar_24201 = PC + 1;
	cppVar_24201 = (cppVar_24201 & cppMask_un_16_);
	cppVar_24202 = ROM.rd(cppVar_24201);
	cppVar_24203 = (cppVar_24202 >> 3) & cppMask_un_5_;
	cppVar_24204 = (cppVar_24203 << 3) | 0;
	cppVar_24204 = (cppVar_24204 & cppMask_un_8_);
	cppVar_24196 = cppVar_24204;
	} else {
	cppVar_24205 = PC + 1;
	cppVar_24205 = (cppVar_24205 & cppMask_un_16_);
	cppVar_24206 = ROM.rd(cppVar_24205);
	cppVar_24207 = (cppVar_24206 >> 3) & cppMask_un_5_;
	cppVar_24208 = (cppVar_24207 & cppMask_un_5_);
	cppVar_24209 = cppVar_24208 + 32;
	cppVar_24209 = (cppVar_24209 & cppMask_un_8_);
	cppVar_24196 = cppVar_24209;
	}
	cppVar_24211 = (cppVar_24196 == 208);
	if (cppVar_24211) {
	cppVar_24195 = PSW;
	} else {
	cppVar_24214 = PC + 1;
	cppVar_24214 = (cppVar_24214 & cppMask_un_16_);
	cppVar_24215 = ROM.rd(cppVar_24214);
	cppVar_24216 = (cppVar_24215 >> 7) & cppMask_un_1_;
	cppVar_24217 = (cppVar_24216 == 1);
	if (cppVar_24217) {
	cppVar_24218 = PC + 1;
	cppVar_24218 = (cppVar_24218 & cppMask_un_16_);
	cppVar_24219 = ROM.rd(cppVar_24218);
	cppVar_24220 = (cppVar_24219 >> 3) & cppMask_un_5_;
	cppVar_24221 = (cppVar_24220 << 3) | 0;
	cppVar_24221 = (cppVar_24221 & cppMask_un_8_);
	cppVar_24213 = cppVar_24221;
	} else {
	cppVar_24222 = PC + 1;
	cppVar_24222 = (cppVar_24222 & cppMask_un_16_);
	cppVar_24223 = ROM.rd(cppVar_24222);
	cppVar_24224 = (cppVar_24223 >> 3) & cppMask_un_5_;
	cppVar_24225 = (cppVar_24224 & cppMask_un_5_);
	cppVar_24226 = cppVar_24225 + 32;
	cppVar_24226 = (cppVar_24226 & cppMask_un_8_);
	cppVar_24213 = cppVar_24226;
	}
	cppVar_24228 = (cppVar_24213 == 224);
	if (cppVar_24228) {
	cppVar_24212 = ACC;
	} else {
	cppVar_24231 = PC + 1;
	cppVar_24231 = (cppVar_24231 & cppMask_un_16_);
	cppVar_24232 = ROM.rd(cppVar_24231);
	cppVar_24233 = (cppVar_24232 >> 7) & cppMask_un_1_;
	cppVar_24234 = (cppVar_24233 == 1);
	if (cppVar_24234) {
	cppVar_24235 = PC + 1;
	cppVar_24235 = (cppVar_24235 & cppMask_un_16_);
	cppVar_24236 = ROM.rd(cppVar_24235);
	cppVar_24237 = (cppVar_24236 >> 3) & cppMask_un_5_;
	cppVar_24238 = (cppVar_24237 << 3) | 0;
	cppVar_24238 = (cppVar_24238 & cppMask_un_8_);
	cppVar_24230 = cppVar_24238;
	} else {
	cppVar_24239 = PC + 1;
	cppVar_24239 = (cppVar_24239 & cppMask_un_16_);
	cppVar_24240 = ROM.rd(cppVar_24239);
	cppVar_24241 = (cppVar_24240 >> 3) & cppMask_un_5_;
	cppVar_24242 = (cppVar_24241 & cppMask_un_5_);
	cppVar_24243 = cppVar_24242 + 32;
	cppVar_24243 = (cppVar_24243 & cppMask_un_8_);
	cppVar_24230 = cppVar_24243;
	}
	cppVar_24245 = (cppVar_24230 == 240);
	if (cppVar_24245) {
	cppVar_24229 = B;
	} else {
	cppVar_24229 = 0;
	}
	cppVar_24212 = cppVar_24229;
	}
	cppVar_24195 = cppVar_24212;
	}
	cppVar_24178 = cppVar_24195;
	}
	cppVar_24161 = cppVar_24178;
	}
	cppVar_24144 = cppVar_24161;
	}
	cppVar_24127 = cppVar_24144;
	}
	cppVar_24110 = cppVar_24127;
	}
	cppVar_24093 = cppVar_24110;
	}
	cppVar_24076 = cppVar_24093;
	}
	cppVar_24059 = cppVar_24076;
	}
	cppVar_24042 = cppVar_24059;
	}
	cppVar_24025 = cppVar_24042;
	}
	cppVar_24008 = cppVar_24025;
	}
	cppVar_23991 = cppVar_24008;
	}
	cppVar_23974 = cppVar_23991;
	}
	cppVar_23957 = cppVar_23974;
	}
	cppVar_23940 = cppVar_23957;
	}
	cppVar_23923 = cppVar_23940;
	}
	cppVar_23906 = cppVar_23923;
	}
	cppVar_23889 = cppVar_23906;
	}
	cppVar_23856 = cppVar_23889;
	}
	cppVar_24247 = cppVar_23855 & cppVar_23856;
	cppVar_24248 = (PSW >> 7) & cppMask_un_1_;
	cppVar_24249 = (cppVar_24248 & cppMask_un_1_);
	cppVar_24250 = PC + 1;
	cppVar_24250 = (cppVar_24250 & cppMask_un_16_);
	cppVar_24251 = ROM.rd(cppVar_24250);
	cppVar_24252 = (cppVar_24251 >> 0) & cppMask_un_3_;
	cppVar_24253 = (cppVar_24252 & cppMask_un_3_);
	cppVar_24254 = cppVar_24249 << static_cast<unsigned>(cppVar_24253);
	cppVar_24254 = (cppVar_24254 & cppMask_un_8_);
	cppVar_24255 = cppVar_24247 | cppVar_24254;
	cppVar_23828 = cppVar_24255;
	} else {
	cppVar_23828 = P0;
	}
	cppVar_23824 = cppVar_23828;
	} else {
	cppVar_24257 = ROM.rd(PC);
	cppVar_24259 = (cppVar_24257 == 143);
	if (cppVar_24259) {
	cppVar_24262 = PC + 1;
	cppVar_24262 = (cppVar_24262 & cppMask_un_16_);
	cppVar_24263 = ROM.rd(cppVar_24262);
	cppVar_24265 = (cppVar_24263 == 128);
	if (cppVar_24265) {
	cppVar_24268 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24270 = (cppVar_24268 << 3) | 7;
	cppVar_24270 = (cppVar_24270 & cppMask_un_5_);
	cppVar_24271 = (0 << 5) | cppVar_24270;
	cppVar_24271 = (cppVar_24271 & cppMask_un_8_);
	cppVar_24272 = (cppVar_24271 >> 7) & cppMask_un_1_;
	cppVar_24274 = (cppVar_24272 == 0);
	if (cppVar_24274) {
	cppVar_24275 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24276 = (cppVar_24275 << 3) | 7;
	cppVar_24276 = (cppVar_24276 & cppMask_un_5_);
	cppVar_24277 = (0 << 5) | cppVar_24276;
	cppVar_24277 = (cppVar_24277 & cppMask_un_8_);
	cppVar_24278 = IRAM.rd(cppVar_24277);
	cppVar_24266 = cppVar_24278;
	} else {
	cppVar_24280 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24281 = (cppVar_24280 << 3) | 7;
	cppVar_24281 = (cppVar_24281 & cppMask_un_5_);
	cppVar_24282 = (0 << 5) | cppVar_24281;
	cppVar_24282 = (cppVar_24282 & cppMask_un_8_);
	cppVar_24284 = (cppVar_24282 == 128);
	if (cppVar_24284) {
	cppVar_24279 = P0;
	} else {
	cppVar_24286 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24287 = (cppVar_24286 << 3) | 7;
	cppVar_24287 = (cppVar_24287 & cppMask_un_5_);
	cppVar_24288 = (0 << 5) | cppVar_24287;
	cppVar_24288 = (cppVar_24288 & cppMask_un_8_);
	cppVar_24290 = (cppVar_24288 == 129);
	if (cppVar_24290) {
	cppVar_24285 = SP;
	} else {
	cppVar_24292 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24293 = (cppVar_24292 << 3) | 7;
	cppVar_24293 = (cppVar_24293 & cppMask_un_5_);
	cppVar_24294 = (0 << 5) | cppVar_24293;
	cppVar_24294 = (cppVar_24294 & cppMask_un_8_);
	cppVar_24296 = (cppVar_24294 == 130);
	if (cppVar_24296) {
	cppVar_24291 = DPL;
	} else {
	cppVar_24298 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24299 = (cppVar_24298 << 3) | 7;
	cppVar_24299 = (cppVar_24299 & cppMask_un_5_);
	cppVar_24300 = (0 << 5) | cppVar_24299;
	cppVar_24300 = (cppVar_24300 & cppMask_un_8_);
	cppVar_24302 = (cppVar_24300 == 131);
	if (cppVar_24302) {
	cppVar_24297 = DPH;
	} else {
	cppVar_24304 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24305 = (cppVar_24304 << 3) | 7;
	cppVar_24305 = (cppVar_24305 & cppMask_un_5_);
	cppVar_24306 = (0 << 5) | cppVar_24305;
	cppVar_24306 = (cppVar_24306 & cppMask_un_8_);
	cppVar_24308 = (cppVar_24306 == 135);
	if (cppVar_24308) {
	cppVar_24303 = PCON;
	} else {
	cppVar_24310 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24311 = (cppVar_24310 << 3) | 7;
	cppVar_24311 = (cppVar_24311 & cppMask_un_5_);
	cppVar_24312 = (0 << 5) | cppVar_24311;
	cppVar_24312 = (cppVar_24312 & cppMask_un_8_);
	cppVar_24314 = (cppVar_24312 == 136);
	if (cppVar_24314) {
	cppVar_24309 = TCON;
	} else {
	cppVar_24316 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24317 = (cppVar_24316 << 3) | 7;
	cppVar_24317 = (cppVar_24317 & cppMask_un_5_);
	cppVar_24318 = (0 << 5) | cppVar_24317;
	cppVar_24318 = (cppVar_24318 & cppMask_un_8_);
	cppVar_24320 = (cppVar_24318 == 137);
	if (cppVar_24320) {
	cppVar_24315 = TMOD;
	} else {
	cppVar_24322 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24323 = (cppVar_24322 << 3) | 7;
	cppVar_24323 = (cppVar_24323 & cppMask_un_5_);
	cppVar_24324 = (0 << 5) | cppVar_24323;
	cppVar_24324 = (cppVar_24324 & cppMask_un_8_);
	cppVar_24326 = (cppVar_24324 == 138);
	if (cppVar_24326) {
	cppVar_24321 = TL0;
	} else {
	cppVar_24328 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24329 = (cppVar_24328 << 3) | 7;
	cppVar_24329 = (cppVar_24329 & cppMask_un_5_);
	cppVar_24330 = (0 << 5) | cppVar_24329;
	cppVar_24330 = (cppVar_24330 & cppMask_un_8_);
	cppVar_24332 = (cppVar_24330 == 140);
	if (cppVar_24332) {
	cppVar_24327 = TH0;
	} else {
	cppVar_24334 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24335 = (cppVar_24334 << 3) | 7;
	cppVar_24335 = (cppVar_24335 & cppMask_un_5_);
	cppVar_24336 = (0 << 5) | cppVar_24335;
	cppVar_24336 = (cppVar_24336 & cppMask_un_8_);
	cppVar_24338 = (cppVar_24336 == 139);
	if (cppVar_24338) {
	cppVar_24333 = TL1;
	} else {
	cppVar_24340 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24341 = (cppVar_24340 << 3) | 7;
	cppVar_24341 = (cppVar_24341 & cppMask_un_5_);
	cppVar_24342 = (0 << 5) | cppVar_24341;
	cppVar_24342 = (cppVar_24342 & cppMask_un_8_);
	cppVar_24344 = (cppVar_24342 == 141);
	if (cppVar_24344) {
	cppVar_24339 = TH1;
	} else {
	cppVar_24346 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24347 = (cppVar_24346 << 3) | 7;
	cppVar_24347 = (cppVar_24347 & cppMask_un_5_);
	cppVar_24348 = (0 << 5) | cppVar_24347;
	cppVar_24348 = (cppVar_24348 & cppMask_un_8_);
	cppVar_24350 = (cppVar_24348 == 144);
	if (cppVar_24350) {
	cppVar_24345 = P1;
	} else {
	cppVar_24352 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24353 = (cppVar_24352 << 3) | 7;
	cppVar_24353 = (cppVar_24353 & cppMask_un_5_);
	cppVar_24354 = (0 << 5) | cppVar_24353;
	cppVar_24354 = (cppVar_24354 & cppMask_un_8_);
	cppVar_24356 = (cppVar_24354 == 152);
	if (cppVar_24356) {
	cppVar_24351 = SCON;
	} else {
	cppVar_24358 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24359 = (cppVar_24358 << 3) | 7;
	cppVar_24359 = (cppVar_24359 & cppMask_un_5_);
	cppVar_24360 = (0 << 5) | cppVar_24359;
	cppVar_24360 = (cppVar_24360 & cppMask_un_8_);
	cppVar_24362 = (cppVar_24360 == 153);
	if (cppVar_24362) {
	cppVar_24357 = SBUF;
	} else {
	cppVar_24364 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24365 = (cppVar_24364 << 3) | 7;
	cppVar_24365 = (cppVar_24365 & cppMask_un_5_);
	cppVar_24366 = (0 << 5) | cppVar_24365;
	cppVar_24366 = (cppVar_24366 & cppMask_un_8_);
	cppVar_24368 = (cppVar_24366 == 160);
	if (cppVar_24368) {
	cppVar_24363 = P2;
	} else {
	cppVar_24370 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24371 = (cppVar_24370 << 3) | 7;
	cppVar_24371 = (cppVar_24371 & cppMask_un_5_);
	cppVar_24372 = (0 << 5) | cppVar_24371;
	cppVar_24372 = (cppVar_24372 & cppMask_un_8_);
	cppVar_24374 = (cppVar_24372 == 168);
	if (cppVar_24374) {
	cppVar_24369 = IE;
	} else {
	cppVar_24376 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24377 = (cppVar_24376 << 3) | 7;
	cppVar_24377 = (cppVar_24377 & cppMask_un_5_);
	cppVar_24378 = (0 << 5) | cppVar_24377;
	cppVar_24378 = (cppVar_24378 & cppMask_un_8_);
	cppVar_24380 = (cppVar_24378 == 176);
	if (cppVar_24380) {
	cppVar_24375 = P3;
	} else {
	cppVar_24382 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24383 = (cppVar_24382 << 3) | 7;
	cppVar_24383 = (cppVar_24383 & cppMask_un_5_);
	cppVar_24384 = (0 << 5) | cppVar_24383;
	cppVar_24384 = (cppVar_24384 & cppMask_un_8_);
	cppVar_24386 = (cppVar_24384 == 184);
	if (cppVar_24386) {
	cppVar_24381 = IP;
	} else {
	cppVar_24388 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24389 = (cppVar_24388 << 3) | 7;
	cppVar_24389 = (cppVar_24389 & cppMask_un_5_);
	cppVar_24390 = (0 << 5) | cppVar_24389;
	cppVar_24390 = (cppVar_24390 & cppMask_un_8_);
	cppVar_24392 = (cppVar_24390 == 208);
	if (cppVar_24392) {
	cppVar_24387 = PSW;
	} else {
	cppVar_24394 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24395 = (cppVar_24394 << 3) | 7;
	cppVar_24395 = (cppVar_24395 & cppMask_un_5_);
	cppVar_24396 = (0 << 5) | cppVar_24395;
	cppVar_24396 = (cppVar_24396 & cppMask_un_8_);
	cppVar_24398 = (cppVar_24396 == 224);
	if (cppVar_24398) {
	cppVar_24393 = ACC;
	} else {
	cppVar_24400 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24401 = (cppVar_24400 << 3) | 7;
	cppVar_24401 = (cppVar_24401 & cppMask_un_5_);
	cppVar_24402 = (0 << 5) | cppVar_24401;
	cppVar_24402 = (cppVar_24402 & cppMask_un_8_);
	cppVar_24404 = (cppVar_24402 == 240);
	if (cppVar_24404) {
	cppVar_24399 = B;
	} else {
	cppVar_24399 = 0;
	}
	cppVar_24393 = cppVar_24399;
	}
	cppVar_24387 = cppVar_24393;
	}
	cppVar_24381 = cppVar_24387;
	}
	cppVar_24375 = cppVar_24381;
	}
	cppVar_24369 = cppVar_24375;
	}
	cppVar_24363 = cppVar_24369;
	}
	cppVar_24357 = cppVar_24363;
	}
	cppVar_24351 = cppVar_24357;
	}
	cppVar_24345 = cppVar_24351;
	}
	cppVar_24339 = cppVar_24345;
	}
	cppVar_24333 = cppVar_24339;
	}
	cppVar_24327 = cppVar_24333;
	}
	cppVar_24321 = cppVar_24327;
	}
	cppVar_24315 = cppVar_24321;
	}
	cppVar_24309 = cppVar_24315;
	}
	cppVar_24303 = cppVar_24309;
	}
	cppVar_24297 = cppVar_24303;
	}
	cppVar_24291 = cppVar_24297;
	}
	cppVar_24285 = cppVar_24291;
	}
	cppVar_24279 = cppVar_24285;
	}
	cppVar_24266 = cppVar_24279;
	}
	cppVar_24260 = cppVar_24266;
	} else {
	cppVar_24260 = P0;
	}
	cppVar_24256 = cppVar_24260;
	} else {
	cppVar_24407 = ROM.rd(PC);
	cppVar_24409 = (cppVar_24407 == 142);
	if (cppVar_24409) {
	cppVar_24412 = PC + 1;
	cppVar_24412 = (cppVar_24412 & cppMask_un_16_);
	cppVar_24413 = ROM.rd(cppVar_24412);
	cppVar_24415 = (cppVar_24413 == 128);
	if (cppVar_24415) {
	cppVar_24418 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24420 = (cppVar_24418 << 3) | 6;
	cppVar_24420 = (cppVar_24420 & cppMask_un_5_);
	cppVar_24421 = (0 << 5) | cppVar_24420;
	cppVar_24421 = (cppVar_24421 & cppMask_un_8_);
	cppVar_24422 = (cppVar_24421 >> 7) & cppMask_un_1_;
	cppVar_24424 = (cppVar_24422 == 0);
	if (cppVar_24424) {
	cppVar_24425 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24426 = (cppVar_24425 << 3) | 6;
	cppVar_24426 = (cppVar_24426 & cppMask_un_5_);
	cppVar_24427 = (0 << 5) | cppVar_24426;
	cppVar_24427 = (cppVar_24427 & cppMask_un_8_);
	cppVar_24428 = IRAM.rd(cppVar_24427);
	cppVar_24416 = cppVar_24428;
	} else {
	cppVar_24430 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24431 = (cppVar_24430 << 3) | 6;
	cppVar_24431 = (cppVar_24431 & cppMask_un_5_);
	cppVar_24432 = (0 << 5) | cppVar_24431;
	cppVar_24432 = (cppVar_24432 & cppMask_un_8_);
	cppVar_24434 = (cppVar_24432 == 128);
	if (cppVar_24434) {
	cppVar_24429 = P0;
	} else {
	cppVar_24436 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24437 = (cppVar_24436 << 3) | 6;
	cppVar_24437 = (cppVar_24437 & cppMask_un_5_);
	cppVar_24438 = (0 << 5) | cppVar_24437;
	cppVar_24438 = (cppVar_24438 & cppMask_un_8_);
	cppVar_24440 = (cppVar_24438 == 129);
	if (cppVar_24440) {
	cppVar_24435 = SP;
	} else {
	cppVar_24442 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24443 = (cppVar_24442 << 3) | 6;
	cppVar_24443 = (cppVar_24443 & cppMask_un_5_);
	cppVar_24444 = (0 << 5) | cppVar_24443;
	cppVar_24444 = (cppVar_24444 & cppMask_un_8_);
	cppVar_24446 = (cppVar_24444 == 130);
	if (cppVar_24446) {
	cppVar_24441 = DPL;
	} else {
	cppVar_24448 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24449 = (cppVar_24448 << 3) | 6;
	cppVar_24449 = (cppVar_24449 & cppMask_un_5_);
	cppVar_24450 = (0 << 5) | cppVar_24449;
	cppVar_24450 = (cppVar_24450 & cppMask_un_8_);
	cppVar_24452 = (cppVar_24450 == 131);
	if (cppVar_24452) {
	cppVar_24447 = DPH;
	} else {
	cppVar_24454 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24455 = (cppVar_24454 << 3) | 6;
	cppVar_24455 = (cppVar_24455 & cppMask_un_5_);
	cppVar_24456 = (0 << 5) | cppVar_24455;
	cppVar_24456 = (cppVar_24456 & cppMask_un_8_);
	cppVar_24458 = (cppVar_24456 == 135);
	if (cppVar_24458) {
	cppVar_24453 = PCON;
	} else {
	cppVar_24460 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24461 = (cppVar_24460 << 3) | 6;
	cppVar_24461 = (cppVar_24461 & cppMask_un_5_);
	cppVar_24462 = (0 << 5) | cppVar_24461;
	cppVar_24462 = (cppVar_24462 & cppMask_un_8_);
	cppVar_24464 = (cppVar_24462 == 136);
	if (cppVar_24464) {
	cppVar_24459 = TCON;
	} else {
	cppVar_24466 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24467 = (cppVar_24466 << 3) | 6;
	cppVar_24467 = (cppVar_24467 & cppMask_un_5_);
	cppVar_24468 = (0 << 5) | cppVar_24467;
	cppVar_24468 = (cppVar_24468 & cppMask_un_8_);
	cppVar_24470 = (cppVar_24468 == 137);
	if (cppVar_24470) {
	cppVar_24465 = TMOD;
	} else {
	cppVar_24472 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24473 = (cppVar_24472 << 3) | 6;
	cppVar_24473 = (cppVar_24473 & cppMask_un_5_);
	cppVar_24474 = (0 << 5) | cppVar_24473;
	cppVar_24474 = (cppVar_24474 & cppMask_un_8_);
	cppVar_24476 = (cppVar_24474 == 138);
	if (cppVar_24476) {
	cppVar_24471 = TL0;
	} else {
	cppVar_24478 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24479 = (cppVar_24478 << 3) | 6;
	cppVar_24479 = (cppVar_24479 & cppMask_un_5_);
	cppVar_24480 = (0 << 5) | cppVar_24479;
	cppVar_24480 = (cppVar_24480 & cppMask_un_8_);
	cppVar_24482 = (cppVar_24480 == 140);
	if (cppVar_24482) {
	cppVar_24477 = TH0;
	} else {
	cppVar_24484 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24485 = (cppVar_24484 << 3) | 6;
	cppVar_24485 = (cppVar_24485 & cppMask_un_5_);
	cppVar_24486 = (0 << 5) | cppVar_24485;
	cppVar_24486 = (cppVar_24486 & cppMask_un_8_);
	cppVar_24488 = (cppVar_24486 == 139);
	if (cppVar_24488) {
	cppVar_24483 = TL1;
	} else {
	cppVar_24490 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24491 = (cppVar_24490 << 3) | 6;
	cppVar_24491 = (cppVar_24491 & cppMask_un_5_);
	cppVar_24492 = (0 << 5) | cppVar_24491;
	cppVar_24492 = (cppVar_24492 & cppMask_un_8_);
	cppVar_24494 = (cppVar_24492 == 141);
	if (cppVar_24494) {
	cppVar_24489 = TH1;
	} else {
	cppVar_24496 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24497 = (cppVar_24496 << 3) | 6;
	cppVar_24497 = (cppVar_24497 & cppMask_un_5_);
	cppVar_24498 = (0 << 5) | cppVar_24497;
	cppVar_24498 = (cppVar_24498 & cppMask_un_8_);
	cppVar_24500 = (cppVar_24498 == 144);
	if (cppVar_24500) {
	cppVar_24495 = P1;
	} else {
	cppVar_24502 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24503 = (cppVar_24502 << 3) | 6;
	cppVar_24503 = (cppVar_24503 & cppMask_un_5_);
	cppVar_24504 = (0 << 5) | cppVar_24503;
	cppVar_24504 = (cppVar_24504 & cppMask_un_8_);
	cppVar_24506 = (cppVar_24504 == 152);
	if (cppVar_24506) {
	cppVar_24501 = SCON;
	} else {
	cppVar_24508 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24509 = (cppVar_24508 << 3) | 6;
	cppVar_24509 = (cppVar_24509 & cppMask_un_5_);
	cppVar_24510 = (0 << 5) | cppVar_24509;
	cppVar_24510 = (cppVar_24510 & cppMask_un_8_);
	cppVar_24512 = (cppVar_24510 == 153);
	if (cppVar_24512) {
	cppVar_24507 = SBUF;
	} else {
	cppVar_24514 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24515 = (cppVar_24514 << 3) | 6;
	cppVar_24515 = (cppVar_24515 & cppMask_un_5_);
	cppVar_24516 = (0 << 5) | cppVar_24515;
	cppVar_24516 = (cppVar_24516 & cppMask_un_8_);
	cppVar_24518 = (cppVar_24516 == 160);
	if (cppVar_24518) {
	cppVar_24513 = P2;
	} else {
	cppVar_24520 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24521 = (cppVar_24520 << 3) | 6;
	cppVar_24521 = (cppVar_24521 & cppMask_un_5_);
	cppVar_24522 = (0 << 5) | cppVar_24521;
	cppVar_24522 = (cppVar_24522 & cppMask_un_8_);
	cppVar_24524 = (cppVar_24522 == 168);
	if (cppVar_24524) {
	cppVar_24519 = IE;
	} else {
	cppVar_24526 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24527 = (cppVar_24526 << 3) | 6;
	cppVar_24527 = (cppVar_24527 & cppMask_un_5_);
	cppVar_24528 = (0 << 5) | cppVar_24527;
	cppVar_24528 = (cppVar_24528 & cppMask_un_8_);
	cppVar_24530 = (cppVar_24528 == 176);
	if (cppVar_24530) {
	cppVar_24525 = P3;
	} else {
	cppVar_24532 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24533 = (cppVar_24532 << 3) | 6;
	cppVar_24533 = (cppVar_24533 & cppMask_un_5_);
	cppVar_24534 = (0 << 5) | cppVar_24533;
	cppVar_24534 = (cppVar_24534 & cppMask_un_8_);
	cppVar_24536 = (cppVar_24534 == 184);
	if (cppVar_24536) {
	cppVar_24531 = IP;
	} else {
	cppVar_24538 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24539 = (cppVar_24538 << 3) | 6;
	cppVar_24539 = (cppVar_24539 & cppMask_un_5_);
	cppVar_24540 = (0 << 5) | cppVar_24539;
	cppVar_24540 = (cppVar_24540 & cppMask_un_8_);
	cppVar_24542 = (cppVar_24540 == 208);
	if (cppVar_24542) {
	cppVar_24537 = PSW;
	} else {
	cppVar_24544 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24545 = (cppVar_24544 << 3) | 6;
	cppVar_24545 = (cppVar_24545 & cppMask_un_5_);
	cppVar_24546 = (0 << 5) | cppVar_24545;
	cppVar_24546 = (cppVar_24546 & cppMask_un_8_);
	cppVar_24548 = (cppVar_24546 == 224);
	if (cppVar_24548) {
	cppVar_24543 = ACC;
	} else {
	cppVar_24550 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24551 = (cppVar_24550 << 3) | 6;
	cppVar_24551 = (cppVar_24551 & cppMask_un_5_);
	cppVar_24552 = (0 << 5) | cppVar_24551;
	cppVar_24552 = (cppVar_24552 & cppMask_un_8_);
	cppVar_24554 = (cppVar_24552 == 240);
	if (cppVar_24554) {
	cppVar_24549 = B;
	} else {
	cppVar_24549 = 0;
	}
	cppVar_24543 = cppVar_24549;
	}
	cppVar_24537 = cppVar_24543;
	}
	cppVar_24531 = cppVar_24537;
	}
	cppVar_24525 = cppVar_24531;
	}
	cppVar_24519 = cppVar_24525;
	}
	cppVar_24513 = cppVar_24519;
	}
	cppVar_24507 = cppVar_24513;
	}
	cppVar_24501 = cppVar_24507;
	}
	cppVar_24495 = cppVar_24501;
	}
	cppVar_24489 = cppVar_24495;
	}
	cppVar_24483 = cppVar_24489;
	}
	cppVar_24477 = cppVar_24483;
	}
	cppVar_24471 = cppVar_24477;
	}
	cppVar_24465 = cppVar_24471;
	}
	cppVar_24459 = cppVar_24465;
	}
	cppVar_24453 = cppVar_24459;
	}
	cppVar_24447 = cppVar_24453;
	}
	cppVar_24441 = cppVar_24447;
	}
	cppVar_24435 = cppVar_24441;
	}
	cppVar_24429 = cppVar_24435;
	}
	cppVar_24416 = cppVar_24429;
	}
	cppVar_24410 = cppVar_24416;
	} else {
	cppVar_24410 = P0;
	}
	cppVar_24406 = cppVar_24410;
	} else {
	cppVar_24557 = ROM.rd(PC);
	cppVar_24559 = (cppVar_24557 == 141);
	if (cppVar_24559) {
	cppVar_24562 = PC + 1;
	cppVar_24562 = (cppVar_24562 & cppMask_un_16_);
	cppVar_24563 = ROM.rd(cppVar_24562);
	cppVar_24565 = (cppVar_24563 == 128);
	if (cppVar_24565) {
	cppVar_24568 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24570 = (cppVar_24568 << 3) | 5;
	cppVar_24570 = (cppVar_24570 & cppMask_un_5_);
	cppVar_24571 = (0 << 5) | cppVar_24570;
	cppVar_24571 = (cppVar_24571 & cppMask_un_8_);
	cppVar_24572 = (cppVar_24571 >> 7) & cppMask_un_1_;
	cppVar_24574 = (cppVar_24572 == 0);
	if (cppVar_24574) {
	cppVar_24575 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24576 = (cppVar_24575 << 3) | 5;
	cppVar_24576 = (cppVar_24576 & cppMask_un_5_);
	cppVar_24577 = (0 << 5) | cppVar_24576;
	cppVar_24577 = (cppVar_24577 & cppMask_un_8_);
	cppVar_24578 = IRAM.rd(cppVar_24577);
	cppVar_24566 = cppVar_24578;
	} else {
	cppVar_24580 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24581 = (cppVar_24580 << 3) | 5;
	cppVar_24581 = (cppVar_24581 & cppMask_un_5_);
	cppVar_24582 = (0 << 5) | cppVar_24581;
	cppVar_24582 = (cppVar_24582 & cppMask_un_8_);
	cppVar_24584 = (cppVar_24582 == 128);
	if (cppVar_24584) {
	cppVar_24579 = P0;
	} else {
	cppVar_24586 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24587 = (cppVar_24586 << 3) | 5;
	cppVar_24587 = (cppVar_24587 & cppMask_un_5_);
	cppVar_24588 = (0 << 5) | cppVar_24587;
	cppVar_24588 = (cppVar_24588 & cppMask_un_8_);
	cppVar_24590 = (cppVar_24588 == 129);
	if (cppVar_24590) {
	cppVar_24585 = SP;
	} else {
	cppVar_24592 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24593 = (cppVar_24592 << 3) | 5;
	cppVar_24593 = (cppVar_24593 & cppMask_un_5_);
	cppVar_24594 = (0 << 5) | cppVar_24593;
	cppVar_24594 = (cppVar_24594 & cppMask_un_8_);
	cppVar_24596 = (cppVar_24594 == 130);
	if (cppVar_24596) {
	cppVar_24591 = DPL;
	} else {
	cppVar_24598 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24599 = (cppVar_24598 << 3) | 5;
	cppVar_24599 = (cppVar_24599 & cppMask_un_5_);
	cppVar_24600 = (0 << 5) | cppVar_24599;
	cppVar_24600 = (cppVar_24600 & cppMask_un_8_);
	cppVar_24602 = (cppVar_24600 == 131);
	if (cppVar_24602) {
	cppVar_24597 = DPH;
	} else {
	cppVar_24604 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24605 = (cppVar_24604 << 3) | 5;
	cppVar_24605 = (cppVar_24605 & cppMask_un_5_);
	cppVar_24606 = (0 << 5) | cppVar_24605;
	cppVar_24606 = (cppVar_24606 & cppMask_un_8_);
	cppVar_24608 = (cppVar_24606 == 135);
	if (cppVar_24608) {
	cppVar_24603 = PCON;
	} else {
	cppVar_24610 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24611 = (cppVar_24610 << 3) | 5;
	cppVar_24611 = (cppVar_24611 & cppMask_un_5_);
	cppVar_24612 = (0 << 5) | cppVar_24611;
	cppVar_24612 = (cppVar_24612 & cppMask_un_8_);
	cppVar_24614 = (cppVar_24612 == 136);
	if (cppVar_24614) {
	cppVar_24609 = TCON;
	} else {
	cppVar_24616 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24617 = (cppVar_24616 << 3) | 5;
	cppVar_24617 = (cppVar_24617 & cppMask_un_5_);
	cppVar_24618 = (0 << 5) | cppVar_24617;
	cppVar_24618 = (cppVar_24618 & cppMask_un_8_);
	cppVar_24620 = (cppVar_24618 == 137);
	if (cppVar_24620) {
	cppVar_24615 = TMOD;
	} else {
	cppVar_24622 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24623 = (cppVar_24622 << 3) | 5;
	cppVar_24623 = (cppVar_24623 & cppMask_un_5_);
	cppVar_24624 = (0 << 5) | cppVar_24623;
	cppVar_24624 = (cppVar_24624 & cppMask_un_8_);
	cppVar_24626 = (cppVar_24624 == 138);
	if (cppVar_24626) {
	cppVar_24621 = TL0;
	} else {
	cppVar_24628 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24629 = (cppVar_24628 << 3) | 5;
	cppVar_24629 = (cppVar_24629 & cppMask_un_5_);
	cppVar_24630 = (0 << 5) | cppVar_24629;
	cppVar_24630 = (cppVar_24630 & cppMask_un_8_);
	cppVar_24632 = (cppVar_24630 == 140);
	if (cppVar_24632) {
	cppVar_24627 = TH0;
	} else {
	cppVar_24634 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24635 = (cppVar_24634 << 3) | 5;
	cppVar_24635 = (cppVar_24635 & cppMask_un_5_);
	cppVar_24636 = (0 << 5) | cppVar_24635;
	cppVar_24636 = (cppVar_24636 & cppMask_un_8_);
	cppVar_24638 = (cppVar_24636 == 139);
	if (cppVar_24638) {
	cppVar_24633 = TL1;
	} else {
	cppVar_24640 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24641 = (cppVar_24640 << 3) | 5;
	cppVar_24641 = (cppVar_24641 & cppMask_un_5_);
	cppVar_24642 = (0 << 5) | cppVar_24641;
	cppVar_24642 = (cppVar_24642 & cppMask_un_8_);
	cppVar_24644 = (cppVar_24642 == 141);
	if (cppVar_24644) {
	cppVar_24639 = TH1;
	} else {
	cppVar_24646 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24647 = (cppVar_24646 << 3) | 5;
	cppVar_24647 = (cppVar_24647 & cppMask_un_5_);
	cppVar_24648 = (0 << 5) | cppVar_24647;
	cppVar_24648 = (cppVar_24648 & cppMask_un_8_);
	cppVar_24650 = (cppVar_24648 == 144);
	if (cppVar_24650) {
	cppVar_24645 = P1;
	} else {
	cppVar_24652 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24653 = (cppVar_24652 << 3) | 5;
	cppVar_24653 = (cppVar_24653 & cppMask_un_5_);
	cppVar_24654 = (0 << 5) | cppVar_24653;
	cppVar_24654 = (cppVar_24654 & cppMask_un_8_);
	cppVar_24656 = (cppVar_24654 == 152);
	if (cppVar_24656) {
	cppVar_24651 = SCON;
	} else {
	cppVar_24658 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24659 = (cppVar_24658 << 3) | 5;
	cppVar_24659 = (cppVar_24659 & cppMask_un_5_);
	cppVar_24660 = (0 << 5) | cppVar_24659;
	cppVar_24660 = (cppVar_24660 & cppMask_un_8_);
	cppVar_24662 = (cppVar_24660 == 153);
	if (cppVar_24662) {
	cppVar_24657 = SBUF;
	} else {
	cppVar_24664 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24665 = (cppVar_24664 << 3) | 5;
	cppVar_24665 = (cppVar_24665 & cppMask_un_5_);
	cppVar_24666 = (0 << 5) | cppVar_24665;
	cppVar_24666 = (cppVar_24666 & cppMask_un_8_);
	cppVar_24668 = (cppVar_24666 == 160);
	if (cppVar_24668) {
	cppVar_24663 = P2;
	} else {
	cppVar_24670 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24671 = (cppVar_24670 << 3) | 5;
	cppVar_24671 = (cppVar_24671 & cppMask_un_5_);
	cppVar_24672 = (0 << 5) | cppVar_24671;
	cppVar_24672 = (cppVar_24672 & cppMask_un_8_);
	cppVar_24674 = (cppVar_24672 == 168);
	if (cppVar_24674) {
	cppVar_24669 = IE;
	} else {
	cppVar_24676 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24677 = (cppVar_24676 << 3) | 5;
	cppVar_24677 = (cppVar_24677 & cppMask_un_5_);
	cppVar_24678 = (0 << 5) | cppVar_24677;
	cppVar_24678 = (cppVar_24678 & cppMask_un_8_);
	cppVar_24680 = (cppVar_24678 == 176);
	if (cppVar_24680) {
	cppVar_24675 = P3;
	} else {
	cppVar_24682 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24683 = (cppVar_24682 << 3) | 5;
	cppVar_24683 = (cppVar_24683 & cppMask_un_5_);
	cppVar_24684 = (0 << 5) | cppVar_24683;
	cppVar_24684 = (cppVar_24684 & cppMask_un_8_);
	cppVar_24686 = (cppVar_24684 == 184);
	if (cppVar_24686) {
	cppVar_24681 = IP;
	} else {
	cppVar_24688 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24689 = (cppVar_24688 << 3) | 5;
	cppVar_24689 = (cppVar_24689 & cppMask_un_5_);
	cppVar_24690 = (0 << 5) | cppVar_24689;
	cppVar_24690 = (cppVar_24690 & cppMask_un_8_);
	cppVar_24692 = (cppVar_24690 == 208);
	if (cppVar_24692) {
	cppVar_24687 = PSW;
	} else {
	cppVar_24694 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24695 = (cppVar_24694 << 3) | 5;
	cppVar_24695 = (cppVar_24695 & cppMask_un_5_);
	cppVar_24696 = (0 << 5) | cppVar_24695;
	cppVar_24696 = (cppVar_24696 & cppMask_un_8_);
	cppVar_24698 = (cppVar_24696 == 224);
	if (cppVar_24698) {
	cppVar_24693 = ACC;
	} else {
	cppVar_24700 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24701 = (cppVar_24700 << 3) | 5;
	cppVar_24701 = (cppVar_24701 & cppMask_un_5_);
	cppVar_24702 = (0 << 5) | cppVar_24701;
	cppVar_24702 = (cppVar_24702 & cppMask_un_8_);
	cppVar_24704 = (cppVar_24702 == 240);
	if (cppVar_24704) {
	cppVar_24699 = B;
	} else {
	cppVar_24699 = 0;
	}
	cppVar_24693 = cppVar_24699;
	}
	cppVar_24687 = cppVar_24693;
	}
	cppVar_24681 = cppVar_24687;
	}
	cppVar_24675 = cppVar_24681;
	}
	cppVar_24669 = cppVar_24675;
	}
	cppVar_24663 = cppVar_24669;
	}
	cppVar_24657 = cppVar_24663;
	}
	cppVar_24651 = cppVar_24657;
	}
	cppVar_24645 = cppVar_24651;
	}
	cppVar_24639 = cppVar_24645;
	}
	cppVar_24633 = cppVar_24639;
	}
	cppVar_24627 = cppVar_24633;
	}
	cppVar_24621 = cppVar_24627;
	}
	cppVar_24615 = cppVar_24621;
	}
	cppVar_24609 = cppVar_24615;
	}
	cppVar_24603 = cppVar_24609;
	}
	cppVar_24597 = cppVar_24603;
	}
	cppVar_24591 = cppVar_24597;
	}
	cppVar_24585 = cppVar_24591;
	}
	cppVar_24579 = cppVar_24585;
	}
	cppVar_24566 = cppVar_24579;
	}
	cppVar_24560 = cppVar_24566;
	} else {
	cppVar_24560 = P0;
	}
	cppVar_24556 = cppVar_24560;
	} else {
	cppVar_24707 = ROM.rd(PC);
	cppVar_24709 = (cppVar_24707 == 140);
	if (cppVar_24709) {
	cppVar_24712 = PC + 1;
	cppVar_24712 = (cppVar_24712 & cppMask_un_16_);
	cppVar_24713 = ROM.rd(cppVar_24712);
	cppVar_24715 = (cppVar_24713 == 128);
	if (cppVar_24715) {
	cppVar_24718 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24720 = (cppVar_24718 << 3) | 4;
	cppVar_24720 = (cppVar_24720 & cppMask_un_5_);
	cppVar_24721 = (0 << 5) | cppVar_24720;
	cppVar_24721 = (cppVar_24721 & cppMask_un_8_);
	cppVar_24722 = (cppVar_24721 >> 7) & cppMask_un_1_;
	cppVar_24724 = (cppVar_24722 == 0);
	if (cppVar_24724) {
	cppVar_24725 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24726 = (cppVar_24725 << 3) | 4;
	cppVar_24726 = (cppVar_24726 & cppMask_un_5_);
	cppVar_24727 = (0 << 5) | cppVar_24726;
	cppVar_24727 = (cppVar_24727 & cppMask_un_8_);
	cppVar_24728 = IRAM.rd(cppVar_24727);
	cppVar_24716 = cppVar_24728;
	} else {
	cppVar_24730 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24731 = (cppVar_24730 << 3) | 4;
	cppVar_24731 = (cppVar_24731 & cppMask_un_5_);
	cppVar_24732 = (0 << 5) | cppVar_24731;
	cppVar_24732 = (cppVar_24732 & cppMask_un_8_);
	cppVar_24734 = (cppVar_24732 == 128);
	if (cppVar_24734) {
	cppVar_24729 = P0;
	} else {
	cppVar_24736 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24737 = (cppVar_24736 << 3) | 4;
	cppVar_24737 = (cppVar_24737 & cppMask_un_5_);
	cppVar_24738 = (0 << 5) | cppVar_24737;
	cppVar_24738 = (cppVar_24738 & cppMask_un_8_);
	cppVar_24740 = (cppVar_24738 == 129);
	if (cppVar_24740) {
	cppVar_24735 = SP;
	} else {
	cppVar_24742 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24743 = (cppVar_24742 << 3) | 4;
	cppVar_24743 = (cppVar_24743 & cppMask_un_5_);
	cppVar_24744 = (0 << 5) | cppVar_24743;
	cppVar_24744 = (cppVar_24744 & cppMask_un_8_);
	cppVar_24746 = (cppVar_24744 == 130);
	if (cppVar_24746) {
	cppVar_24741 = DPL;
	} else {
	cppVar_24748 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24749 = (cppVar_24748 << 3) | 4;
	cppVar_24749 = (cppVar_24749 & cppMask_un_5_);
	cppVar_24750 = (0 << 5) | cppVar_24749;
	cppVar_24750 = (cppVar_24750 & cppMask_un_8_);
	cppVar_24752 = (cppVar_24750 == 131);
	if (cppVar_24752) {
	cppVar_24747 = DPH;
	} else {
	cppVar_24754 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24755 = (cppVar_24754 << 3) | 4;
	cppVar_24755 = (cppVar_24755 & cppMask_un_5_);
	cppVar_24756 = (0 << 5) | cppVar_24755;
	cppVar_24756 = (cppVar_24756 & cppMask_un_8_);
	cppVar_24758 = (cppVar_24756 == 135);
	if (cppVar_24758) {
	cppVar_24753 = PCON;
	} else {
	cppVar_24760 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24761 = (cppVar_24760 << 3) | 4;
	cppVar_24761 = (cppVar_24761 & cppMask_un_5_);
	cppVar_24762 = (0 << 5) | cppVar_24761;
	cppVar_24762 = (cppVar_24762 & cppMask_un_8_);
	cppVar_24764 = (cppVar_24762 == 136);
	if (cppVar_24764) {
	cppVar_24759 = TCON;
	} else {
	cppVar_24766 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24767 = (cppVar_24766 << 3) | 4;
	cppVar_24767 = (cppVar_24767 & cppMask_un_5_);
	cppVar_24768 = (0 << 5) | cppVar_24767;
	cppVar_24768 = (cppVar_24768 & cppMask_un_8_);
	cppVar_24770 = (cppVar_24768 == 137);
	if (cppVar_24770) {
	cppVar_24765 = TMOD;
	} else {
	cppVar_24772 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24773 = (cppVar_24772 << 3) | 4;
	cppVar_24773 = (cppVar_24773 & cppMask_un_5_);
	cppVar_24774 = (0 << 5) | cppVar_24773;
	cppVar_24774 = (cppVar_24774 & cppMask_un_8_);
	cppVar_24776 = (cppVar_24774 == 138);
	if (cppVar_24776) {
	cppVar_24771 = TL0;
	} else {
	cppVar_24778 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24779 = (cppVar_24778 << 3) | 4;
	cppVar_24779 = (cppVar_24779 & cppMask_un_5_);
	cppVar_24780 = (0 << 5) | cppVar_24779;
	cppVar_24780 = (cppVar_24780 & cppMask_un_8_);
	cppVar_24782 = (cppVar_24780 == 140);
	if (cppVar_24782) {
	cppVar_24777 = TH0;
	} else {
	cppVar_24784 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24785 = (cppVar_24784 << 3) | 4;
	cppVar_24785 = (cppVar_24785 & cppMask_un_5_);
	cppVar_24786 = (0 << 5) | cppVar_24785;
	cppVar_24786 = (cppVar_24786 & cppMask_un_8_);
	cppVar_24788 = (cppVar_24786 == 139);
	if (cppVar_24788) {
	cppVar_24783 = TL1;
	} else {
	cppVar_24790 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24791 = (cppVar_24790 << 3) | 4;
	cppVar_24791 = (cppVar_24791 & cppMask_un_5_);
	cppVar_24792 = (0 << 5) | cppVar_24791;
	cppVar_24792 = (cppVar_24792 & cppMask_un_8_);
	cppVar_24794 = (cppVar_24792 == 141);
	if (cppVar_24794) {
	cppVar_24789 = TH1;
	} else {
	cppVar_24796 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24797 = (cppVar_24796 << 3) | 4;
	cppVar_24797 = (cppVar_24797 & cppMask_un_5_);
	cppVar_24798 = (0 << 5) | cppVar_24797;
	cppVar_24798 = (cppVar_24798 & cppMask_un_8_);
	cppVar_24800 = (cppVar_24798 == 144);
	if (cppVar_24800) {
	cppVar_24795 = P1;
	} else {
	cppVar_24802 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24803 = (cppVar_24802 << 3) | 4;
	cppVar_24803 = (cppVar_24803 & cppMask_un_5_);
	cppVar_24804 = (0 << 5) | cppVar_24803;
	cppVar_24804 = (cppVar_24804 & cppMask_un_8_);
	cppVar_24806 = (cppVar_24804 == 152);
	if (cppVar_24806) {
	cppVar_24801 = SCON;
	} else {
	cppVar_24808 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24809 = (cppVar_24808 << 3) | 4;
	cppVar_24809 = (cppVar_24809 & cppMask_un_5_);
	cppVar_24810 = (0 << 5) | cppVar_24809;
	cppVar_24810 = (cppVar_24810 & cppMask_un_8_);
	cppVar_24812 = (cppVar_24810 == 153);
	if (cppVar_24812) {
	cppVar_24807 = SBUF;
	} else {
	cppVar_24814 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24815 = (cppVar_24814 << 3) | 4;
	cppVar_24815 = (cppVar_24815 & cppMask_un_5_);
	cppVar_24816 = (0 << 5) | cppVar_24815;
	cppVar_24816 = (cppVar_24816 & cppMask_un_8_);
	cppVar_24818 = (cppVar_24816 == 160);
	if (cppVar_24818) {
	cppVar_24813 = P2;
	} else {
	cppVar_24820 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24821 = (cppVar_24820 << 3) | 4;
	cppVar_24821 = (cppVar_24821 & cppMask_un_5_);
	cppVar_24822 = (0 << 5) | cppVar_24821;
	cppVar_24822 = (cppVar_24822 & cppMask_un_8_);
	cppVar_24824 = (cppVar_24822 == 168);
	if (cppVar_24824) {
	cppVar_24819 = IE;
	} else {
	cppVar_24826 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24827 = (cppVar_24826 << 3) | 4;
	cppVar_24827 = (cppVar_24827 & cppMask_un_5_);
	cppVar_24828 = (0 << 5) | cppVar_24827;
	cppVar_24828 = (cppVar_24828 & cppMask_un_8_);
	cppVar_24830 = (cppVar_24828 == 176);
	if (cppVar_24830) {
	cppVar_24825 = P3;
	} else {
	cppVar_24832 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24833 = (cppVar_24832 << 3) | 4;
	cppVar_24833 = (cppVar_24833 & cppMask_un_5_);
	cppVar_24834 = (0 << 5) | cppVar_24833;
	cppVar_24834 = (cppVar_24834 & cppMask_un_8_);
	cppVar_24836 = (cppVar_24834 == 184);
	if (cppVar_24836) {
	cppVar_24831 = IP;
	} else {
	cppVar_24838 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24839 = (cppVar_24838 << 3) | 4;
	cppVar_24839 = (cppVar_24839 & cppMask_un_5_);
	cppVar_24840 = (0 << 5) | cppVar_24839;
	cppVar_24840 = (cppVar_24840 & cppMask_un_8_);
	cppVar_24842 = (cppVar_24840 == 208);
	if (cppVar_24842) {
	cppVar_24837 = PSW;
	} else {
	cppVar_24844 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24845 = (cppVar_24844 << 3) | 4;
	cppVar_24845 = (cppVar_24845 & cppMask_un_5_);
	cppVar_24846 = (0 << 5) | cppVar_24845;
	cppVar_24846 = (cppVar_24846 & cppMask_un_8_);
	cppVar_24848 = (cppVar_24846 == 224);
	if (cppVar_24848) {
	cppVar_24843 = ACC;
	} else {
	cppVar_24850 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24851 = (cppVar_24850 << 3) | 4;
	cppVar_24851 = (cppVar_24851 & cppMask_un_5_);
	cppVar_24852 = (0 << 5) | cppVar_24851;
	cppVar_24852 = (cppVar_24852 & cppMask_un_8_);
	cppVar_24854 = (cppVar_24852 == 240);
	if (cppVar_24854) {
	cppVar_24849 = B;
	} else {
	cppVar_24849 = 0;
	}
	cppVar_24843 = cppVar_24849;
	}
	cppVar_24837 = cppVar_24843;
	}
	cppVar_24831 = cppVar_24837;
	}
	cppVar_24825 = cppVar_24831;
	}
	cppVar_24819 = cppVar_24825;
	}
	cppVar_24813 = cppVar_24819;
	}
	cppVar_24807 = cppVar_24813;
	}
	cppVar_24801 = cppVar_24807;
	}
	cppVar_24795 = cppVar_24801;
	}
	cppVar_24789 = cppVar_24795;
	}
	cppVar_24783 = cppVar_24789;
	}
	cppVar_24777 = cppVar_24783;
	}
	cppVar_24771 = cppVar_24777;
	}
	cppVar_24765 = cppVar_24771;
	}
	cppVar_24759 = cppVar_24765;
	}
	cppVar_24753 = cppVar_24759;
	}
	cppVar_24747 = cppVar_24753;
	}
	cppVar_24741 = cppVar_24747;
	}
	cppVar_24735 = cppVar_24741;
	}
	cppVar_24729 = cppVar_24735;
	}
	cppVar_24716 = cppVar_24729;
	}
	cppVar_24710 = cppVar_24716;
	} else {
	cppVar_24710 = P0;
	}
	cppVar_24706 = cppVar_24710;
	} else {
	cppVar_24857 = ROM.rd(PC);
	cppVar_24859 = (cppVar_24857 == 139);
	if (cppVar_24859) {
	cppVar_24862 = PC + 1;
	cppVar_24862 = (cppVar_24862 & cppMask_un_16_);
	cppVar_24863 = ROM.rd(cppVar_24862);
	cppVar_24865 = (cppVar_24863 == 128);
	if (cppVar_24865) {
	cppVar_24868 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24870 = (cppVar_24868 << 3) | 3;
	cppVar_24870 = (cppVar_24870 & cppMask_un_5_);
	cppVar_24871 = (0 << 5) | cppVar_24870;
	cppVar_24871 = (cppVar_24871 & cppMask_un_8_);
	cppVar_24872 = (cppVar_24871 >> 7) & cppMask_un_1_;
	cppVar_24874 = (cppVar_24872 == 0);
	if (cppVar_24874) {
	cppVar_24875 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24876 = (cppVar_24875 << 3) | 3;
	cppVar_24876 = (cppVar_24876 & cppMask_un_5_);
	cppVar_24877 = (0 << 5) | cppVar_24876;
	cppVar_24877 = (cppVar_24877 & cppMask_un_8_);
	cppVar_24878 = IRAM.rd(cppVar_24877);
	cppVar_24866 = cppVar_24878;
	} else {
	cppVar_24880 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24881 = (cppVar_24880 << 3) | 3;
	cppVar_24881 = (cppVar_24881 & cppMask_un_5_);
	cppVar_24882 = (0 << 5) | cppVar_24881;
	cppVar_24882 = (cppVar_24882 & cppMask_un_8_);
	cppVar_24884 = (cppVar_24882 == 128);
	if (cppVar_24884) {
	cppVar_24879 = P0;
	} else {
	cppVar_24886 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24887 = (cppVar_24886 << 3) | 3;
	cppVar_24887 = (cppVar_24887 & cppMask_un_5_);
	cppVar_24888 = (0 << 5) | cppVar_24887;
	cppVar_24888 = (cppVar_24888 & cppMask_un_8_);
	cppVar_24890 = (cppVar_24888 == 129);
	if (cppVar_24890) {
	cppVar_24885 = SP;
	} else {
	cppVar_24892 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24893 = (cppVar_24892 << 3) | 3;
	cppVar_24893 = (cppVar_24893 & cppMask_un_5_);
	cppVar_24894 = (0 << 5) | cppVar_24893;
	cppVar_24894 = (cppVar_24894 & cppMask_un_8_);
	cppVar_24896 = (cppVar_24894 == 130);
	if (cppVar_24896) {
	cppVar_24891 = DPL;
	} else {
	cppVar_24898 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24899 = (cppVar_24898 << 3) | 3;
	cppVar_24899 = (cppVar_24899 & cppMask_un_5_);
	cppVar_24900 = (0 << 5) | cppVar_24899;
	cppVar_24900 = (cppVar_24900 & cppMask_un_8_);
	cppVar_24902 = (cppVar_24900 == 131);
	if (cppVar_24902) {
	cppVar_24897 = DPH;
	} else {
	cppVar_24904 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24905 = (cppVar_24904 << 3) | 3;
	cppVar_24905 = (cppVar_24905 & cppMask_un_5_);
	cppVar_24906 = (0 << 5) | cppVar_24905;
	cppVar_24906 = (cppVar_24906 & cppMask_un_8_);
	cppVar_24908 = (cppVar_24906 == 135);
	if (cppVar_24908) {
	cppVar_24903 = PCON;
	} else {
	cppVar_24910 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24911 = (cppVar_24910 << 3) | 3;
	cppVar_24911 = (cppVar_24911 & cppMask_un_5_);
	cppVar_24912 = (0 << 5) | cppVar_24911;
	cppVar_24912 = (cppVar_24912 & cppMask_un_8_);
	cppVar_24914 = (cppVar_24912 == 136);
	if (cppVar_24914) {
	cppVar_24909 = TCON;
	} else {
	cppVar_24916 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24917 = (cppVar_24916 << 3) | 3;
	cppVar_24917 = (cppVar_24917 & cppMask_un_5_);
	cppVar_24918 = (0 << 5) | cppVar_24917;
	cppVar_24918 = (cppVar_24918 & cppMask_un_8_);
	cppVar_24920 = (cppVar_24918 == 137);
	if (cppVar_24920) {
	cppVar_24915 = TMOD;
	} else {
	cppVar_24922 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24923 = (cppVar_24922 << 3) | 3;
	cppVar_24923 = (cppVar_24923 & cppMask_un_5_);
	cppVar_24924 = (0 << 5) | cppVar_24923;
	cppVar_24924 = (cppVar_24924 & cppMask_un_8_);
	cppVar_24926 = (cppVar_24924 == 138);
	if (cppVar_24926) {
	cppVar_24921 = TL0;
	} else {
	cppVar_24928 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24929 = (cppVar_24928 << 3) | 3;
	cppVar_24929 = (cppVar_24929 & cppMask_un_5_);
	cppVar_24930 = (0 << 5) | cppVar_24929;
	cppVar_24930 = (cppVar_24930 & cppMask_un_8_);
	cppVar_24932 = (cppVar_24930 == 140);
	if (cppVar_24932) {
	cppVar_24927 = TH0;
	} else {
	cppVar_24934 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24935 = (cppVar_24934 << 3) | 3;
	cppVar_24935 = (cppVar_24935 & cppMask_un_5_);
	cppVar_24936 = (0 << 5) | cppVar_24935;
	cppVar_24936 = (cppVar_24936 & cppMask_un_8_);
	cppVar_24938 = (cppVar_24936 == 139);
	if (cppVar_24938) {
	cppVar_24933 = TL1;
	} else {
	cppVar_24940 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24941 = (cppVar_24940 << 3) | 3;
	cppVar_24941 = (cppVar_24941 & cppMask_un_5_);
	cppVar_24942 = (0 << 5) | cppVar_24941;
	cppVar_24942 = (cppVar_24942 & cppMask_un_8_);
	cppVar_24944 = (cppVar_24942 == 141);
	if (cppVar_24944) {
	cppVar_24939 = TH1;
	} else {
	cppVar_24946 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24947 = (cppVar_24946 << 3) | 3;
	cppVar_24947 = (cppVar_24947 & cppMask_un_5_);
	cppVar_24948 = (0 << 5) | cppVar_24947;
	cppVar_24948 = (cppVar_24948 & cppMask_un_8_);
	cppVar_24950 = (cppVar_24948 == 144);
	if (cppVar_24950) {
	cppVar_24945 = P1;
	} else {
	cppVar_24952 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24953 = (cppVar_24952 << 3) | 3;
	cppVar_24953 = (cppVar_24953 & cppMask_un_5_);
	cppVar_24954 = (0 << 5) | cppVar_24953;
	cppVar_24954 = (cppVar_24954 & cppMask_un_8_);
	cppVar_24956 = (cppVar_24954 == 152);
	if (cppVar_24956) {
	cppVar_24951 = SCON;
	} else {
	cppVar_24958 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24959 = (cppVar_24958 << 3) | 3;
	cppVar_24959 = (cppVar_24959 & cppMask_un_5_);
	cppVar_24960 = (0 << 5) | cppVar_24959;
	cppVar_24960 = (cppVar_24960 & cppMask_un_8_);
	cppVar_24962 = (cppVar_24960 == 153);
	if (cppVar_24962) {
	cppVar_24957 = SBUF;
	} else {
	cppVar_24964 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24965 = (cppVar_24964 << 3) | 3;
	cppVar_24965 = (cppVar_24965 & cppMask_un_5_);
	cppVar_24966 = (0 << 5) | cppVar_24965;
	cppVar_24966 = (cppVar_24966 & cppMask_un_8_);
	cppVar_24968 = (cppVar_24966 == 160);
	if (cppVar_24968) {
	cppVar_24963 = P2;
	} else {
	cppVar_24970 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24971 = (cppVar_24970 << 3) | 3;
	cppVar_24971 = (cppVar_24971 & cppMask_un_5_);
	cppVar_24972 = (0 << 5) | cppVar_24971;
	cppVar_24972 = (cppVar_24972 & cppMask_un_8_);
	cppVar_24974 = (cppVar_24972 == 168);
	if (cppVar_24974) {
	cppVar_24969 = IE;
	} else {
	cppVar_24976 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24977 = (cppVar_24976 << 3) | 3;
	cppVar_24977 = (cppVar_24977 & cppMask_un_5_);
	cppVar_24978 = (0 << 5) | cppVar_24977;
	cppVar_24978 = (cppVar_24978 & cppMask_un_8_);
	cppVar_24980 = (cppVar_24978 == 176);
	if (cppVar_24980) {
	cppVar_24975 = P3;
	} else {
	cppVar_24982 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24983 = (cppVar_24982 << 3) | 3;
	cppVar_24983 = (cppVar_24983 & cppMask_un_5_);
	cppVar_24984 = (0 << 5) | cppVar_24983;
	cppVar_24984 = (cppVar_24984 & cppMask_un_8_);
	cppVar_24986 = (cppVar_24984 == 184);
	if (cppVar_24986) {
	cppVar_24981 = IP;
	} else {
	cppVar_24988 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24989 = (cppVar_24988 << 3) | 3;
	cppVar_24989 = (cppVar_24989 & cppMask_un_5_);
	cppVar_24990 = (0 << 5) | cppVar_24989;
	cppVar_24990 = (cppVar_24990 & cppMask_un_8_);
	cppVar_24992 = (cppVar_24990 == 208);
	if (cppVar_24992) {
	cppVar_24987 = PSW;
	} else {
	cppVar_24994 = (PSW >> 3) & cppMask_un_2_;
	cppVar_24995 = (cppVar_24994 << 3) | 3;
	cppVar_24995 = (cppVar_24995 & cppMask_un_5_);
	cppVar_24996 = (0 << 5) | cppVar_24995;
	cppVar_24996 = (cppVar_24996 & cppMask_un_8_);
	cppVar_24998 = (cppVar_24996 == 224);
	if (cppVar_24998) {
	cppVar_24993 = ACC;
	} else {
	cppVar_25000 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25001 = (cppVar_25000 << 3) | 3;
	cppVar_25001 = (cppVar_25001 & cppMask_un_5_);
	cppVar_25002 = (0 << 5) | cppVar_25001;
	cppVar_25002 = (cppVar_25002 & cppMask_un_8_);
	cppVar_25004 = (cppVar_25002 == 240);
	if (cppVar_25004) {
	cppVar_24999 = B;
	} else {
	cppVar_24999 = 0;
	}
	cppVar_24993 = cppVar_24999;
	}
	cppVar_24987 = cppVar_24993;
	}
	cppVar_24981 = cppVar_24987;
	}
	cppVar_24975 = cppVar_24981;
	}
	cppVar_24969 = cppVar_24975;
	}
	cppVar_24963 = cppVar_24969;
	}
	cppVar_24957 = cppVar_24963;
	}
	cppVar_24951 = cppVar_24957;
	}
	cppVar_24945 = cppVar_24951;
	}
	cppVar_24939 = cppVar_24945;
	}
	cppVar_24933 = cppVar_24939;
	}
	cppVar_24927 = cppVar_24933;
	}
	cppVar_24921 = cppVar_24927;
	}
	cppVar_24915 = cppVar_24921;
	}
	cppVar_24909 = cppVar_24915;
	}
	cppVar_24903 = cppVar_24909;
	}
	cppVar_24897 = cppVar_24903;
	}
	cppVar_24891 = cppVar_24897;
	}
	cppVar_24885 = cppVar_24891;
	}
	cppVar_24879 = cppVar_24885;
	}
	cppVar_24866 = cppVar_24879;
	}
	cppVar_24860 = cppVar_24866;
	} else {
	cppVar_24860 = P0;
	}
	cppVar_24856 = cppVar_24860;
	} else {
	cppVar_25007 = ROM.rd(PC);
	cppVar_25009 = (cppVar_25007 == 138);
	if (cppVar_25009) {
	cppVar_25012 = PC + 1;
	cppVar_25012 = (cppVar_25012 & cppMask_un_16_);
	cppVar_25013 = ROM.rd(cppVar_25012);
	cppVar_25015 = (cppVar_25013 == 128);
	if (cppVar_25015) {
	cppVar_25018 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25020 = (cppVar_25018 << 3) | 2;
	cppVar_25020 = (cppVar_25020 & cppMask_un_5_);
	cppVar_25021 = (0 << 5) | cppVar_25020;
	cppVar_25021 = (cppVar_25021 & cppMask_un_8_);
	cppVar_25022 = (cppVar_25021 >> 7) & cppMask_un_1_;
	cppVar_25024 = (cppVar_25022 == 0);
	if (cppVar_25024) {
	cppVar_25025 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25026 = (cppVar_25025 << 3) | 2;
	cppVar_25026 = (cppVar_25026 & cppMask_un_5_);
	cppVar_25027 = (0 << 5) | cppVar_25026;
	cppVar_25027 = (cppVar_25027 & cppMask_un_8_);
	cppVar_25028 = IRAM.rd(cppVar_25027);
	cppVar_25016 = cppVar_25028;
	} else {
	cppVar_25030 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25031 = (cppVar_25030 << 3) | 2;
	cppVar_25031 = (cppVar_25031 & cppMask_un_5_);
	cppVar_25032 = (0 << 5) | cppVar_25031;
	cppVar_25032 = (cppVar_25032 & cppMask_un_8_);
	cppVar_25034 = (cppVar_25032 == 128);
	if (cppVar_25034) {
	cppVar_25029 = P0;
	} else {
	cppVar_25036 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25037 = (cppVar_25036 << 3) | 2;
	cppVar_25037 = (cppVar_25037 & cppMask_un_5_);
	cppVar_25038 = (0 << 5) | cppVar_25037;
	cppVar_25038 = (cppVar_25038 & cppMask_un_8_);
	cppVar_25040 = (cppVar_25038 == 129);
	if (cppVar_25040) {
	cppVar_25035 = SP;
	} else {
	cppVar_25042 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25043 = (cppVar_25042 << 3) | 2;
	cppVar_25043 = (cppVar_25043 & cppMask_un_5_);
	cppVar_25044 = (0 << 5) | cppVar_25043;
	cppVar_25044 = (cppVar_25044 & cppMask_un_8_);
	cppVar_25046 = (cppVar_25044 == 130);
	if (cppVar_25046) {
	cppVar_25041 = DPL;
	} else {
	cppVar_25048 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25049 = (cppVar_25048 << 3) | 2;
	cppVar_25049 = (cppVar_25049 & cppMask_un_5_);
	cppVar_25050 = (0 << 5) | cppVar_25049;
	cppVar_25050 = (cppVar_25050 & cppMask_un_8_);
	cppVar_25052 = (cppVar_25050 == 131);
	if (cppVar_25052) {
	cppVar_25047 = DPH;
	} else {
	cppVar_25054 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25055 = (cppVar_25054 << 3) | 2;
	cppVar_25055 = (cppVar_25055 & cppMask_un_5_);
	cppVar_25056 = (0 << 5) | cppVar_25055;
	cppVar_25056 = (cppVar_25056 & cppMask_un_8_);
	cppVar_25058 = (cppVar_25056 == 135);
	if (cppVar_25058) {
	cppVar_25053 = PCON;
	} else {
	cppVar_25060 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25061 = (cppVar_25060 << 3) | 2;
	cppVar_25061 = (cppVar_25061 & cppMask_un_5_);
	cppVar_25062 = (0 << 5) | cppVar_25061;
	cppVar_25062 = (cppVar_25062 & cppMask_un_8_);
	cppVar_25064 = (cppVar_25062 == 136);
	if (cppVar_25064) {
	cppVar_25059 = TCON;
	} else {
	cppVar_25066 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25067 = (cppVar_25066 << 3) | 2;
	cppVar_25067 = (cppVar_25067 & cppMask_un_5_);
	cppVar_25068 = (0 << 5) | cppVar_25067;
	cppVar_25068 = (cppVar_25068 & cppMask_un_8_);
	cppVar_25070 = (cppVar_25068 == 137);
	if (cppVar_25070) {
	cppVar_25065 = TMOD;
	} else {
	cppVar_25072 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25073 = (cppVar_25072 << 3) | 2;
	cppVar_25073 = (cppVar_25073 & cppMask_un_5_);
	cppVar_25074 = (0 << 5) | cppVar_25073;
	cppVar_25074 = (cppVar_25074 & cppMask_un_8_);
	cppVar_25076 = (cppVar_25074 == 138);
	if (cppVar_25076) {
	cppVar_25071 = TL0;
	} else {
	cppVar_25078 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25079 = (cppVar_25078 << 3) | 2;
	cppVar_25079 = (cppVar_25079 & cppMask_un_5_);
	cppVar_25080 = (0 << 5) | cppVar_25079;
	cppVar_25080 = (cppVar_25080 & cppMask_un_8_);
	cppVar_25082 = (cppVar_25080 == 140);
	if (cppVar_25082) {
	cppVar_25077 = TH0;
	} else {
	cppVar_25084 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25085 = (cppVar_25084 << 3) | 2;
	cppVar_25085 = (cppVar_25085 & cppMask_un_5_);
	cppVar_25086 = (0 << 5) | cppVar_25085;
	cppVar_25086 = (cppVar_25086 & cppMask_un_8_);
	cppVar_25088 = (cppVar_25086 == 139);
	if (cppVar_25088) {
	cppVar_25083 = TL1;
	} else {
	cppVar_25090 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25091 = (cppVar_25090 << 3) | 2;
	cppVar_25091 = (cppVar_25091 & cppMask_un_5_);
	cppVar_25092 = (0 << 5) | cppVar_25091;
	cppVar_25092 = (cppVar_25092 & cppMask_un_8_);
	cppVar_25094 = (cppVar_25092 == 141);
	if (cppVar_25094) {
	cppVar_25089 = TH1;
	} else {
	cppVar_25096 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25097 = (cppVar_25096 << 3) | 2;
	cppVar_25097 = (cppVar_25097 & cppMask_un_5_);
	cppVar_25098 = (0 << 5) | cppVar_25097;
	cppVar_25098 = (cppVar_25098 & cppMask_un_8_);
	cppVar_25100 = (cppVar_25098 == 144);
	if (cppVar_25100) {
	cppVar_25095 = P1;
	} else {
	cppVar_25102 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25103 = (cppVar_25102 << 3) | 2;
	cppVar_25103 = (cppVar_25103 & cppMask_un_5_);
	cppVar_25104 = (0 << 5) | cppVar_25103;
	cppVar_25104 = (cppVar_25104 & cppMask_un_8_);
	cppVar_25106 = (cppVar_25104 == 152);
	if (cppVar_25106) {
	cppVar_25101 = SCON;
	} else {
	cppVar_25108 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25109 = (cppVar_25108 << 3) | 2;
	cppVar_25109 = (cppVar_25109 & cppMask_un_5_);
	cppVar_25110 = (0 << 5) | cppVar_25109;
	cppVar_25110 = (cppVar_25110 & cppMask_un_8_);
	cppVar_25112 = (cppVar_25110 == 153);
	if (cppVar_25112) {
	cppVar_25107 = SBUF;
	} else {
	cppVar_25114 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25115 = (cppVar_25114 << 3) | 2;
	cppVar_25115 = (cppVar_25115 & cppMask_un_5_);
	cppVar_25116 = (0 << 5) | cppVar_25115;
	cppVar_25116 = (cppVar_25116 & cppMask_un_8_);
	cppVar_25118 = (cppVar_25116 == 160);
	if (cppVar_25118) {
	cppVar_25113 = P2;
	} else {
	cppVar_25120 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25121 = (cppVar_25120 << 3) | 2;
	cppVar_25121 = (cppVar_25121 & cppMask_un_5_);
	cppVar_25122 = (0 << 5) | cppVar_25121;
	cppVar_25122 = (cppVar_25122 & cppMask_un_8_);
	cppVar_25124 = (cppVar_25122 == 168);
	if (cppVar_25124) {
	cppVar_25119 = IE;
	} else {
	cppVar_25126 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25127 = (cppVar_25126 << 3) | 2;
	cppVar_25127 = (cppVar_25127 & cppMask_un_5_);
	cppVar_25128 = (0 << 5) | cppVar_25127;
	cppVar_25128 = (cppVar_25128 & cppMask_un_8_);
	cppVar_25130 = (cppVar_25128 == 176);
	if (cppVar_25130) {
	cppVar_25125 = P3;
	} else {
	cppVar_25132 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25133 = (cppVar_25132 << 3) | 2;
	cppVar_25133 = (cppVar_25133 & cppMask_un_5_);
	cppVar_25134 = (0 << 5) | cppVar_25133;
	cppVar_25134 = (cppVar_25134 & cppMask_un_8_);
	cppVar_25136 = (cppVar_25134 == 184);
	if (cppVar_25136) {
	cppVar_25131 = IP;
	} else {
	cppVar_25138 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25139 = (cppVar_25138 << 3) | 2;
	cppVar_25139 = (cppVar_25139 & cppMask_un_5_);
	cppVar_25140 = (0 << 5) | cppVar_25139;
	cppVar_25140 = (cppVar_25140 & cppMask_un_8_);
	cppVar_25142 = (cppVar_25140 == 208);
	if (cppVar_25142) {
	cppVar_25137 = PSW;
	} else {
	cppVar_25144 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25145 = (cppVar_25144 << 3) | 2;
	cppVar_25145 = (cppVar_25145 & cppMask_un_5_);
	cppVar_25146 = (0 << 5) | cppVar_25145;
	cppVar_25146 = (cppVar_25146 & cppMask_un_8_);
	cppVar_25148 = (cppVar_25146 == 224);
	if (cppVar_25148) {
	cppVar_25143 = ACC;
	} else {
	cppVar_25150 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25151 = (cppVar_25150 << 3) | 2;
	cppVar_25151 = (cppVar_25151 & cppMask_un_5_);
	cppVar_25152 = (0 << 5) | cppVar_25151;
	cppVar_25152 = (cppVar_25152 & cppMask_un_8_);
	cppVar_25154 = (cppVar_25152 == 240);
	if (cppVar_25154) {
	cppVar_25149 = B;
	} else {
	cppVar_25149 = 0;
	}
	cppVar_25143 = cppVar_25149;
	}
	cppVar_25137 = cppVar_25143;
	}
	cppVar_25131 = cppVar_25137;
	}
	cppVar_25125 = cppVar_25131;
	}
	cppVar_25119 = cppVar_25125;
	}
	cppVar_25113 = cppVar_25119;
	}
	cppVar_25107 = cppVar_25113;
	}
	cppVar_25101 = cppVar_25107;
	}
	cppVar_25095 = cppVar_25101;
	}
	cppVar_25089 = cppVar_25095;
	}
	cppVar_25083 = cppVar_25089;
	}
	cppVar_25077 = cppVar_25083;
	}
	cppVar_25071 = cppVar_25077;
	}
	cppVar_25065 = cppVar_25071;
	}
	cppVar_25059 = cppVar_25065;
	}
	cppVar_25053 = cppVar_25059;
	}
	cppVar_25047 = cppVar_25053;
	}
	cppVar_25041 = cppVar_25047;
	}
	cppVar_25035 = cppVar_25041;
	}
	cppVar_25029 = cppVar_25035;
	}
	cppVar_25016 = cppVar_25029;
	}
	cppVar_25010 = cppVar_25016;
	} else {
	cppVar_25010 = P0;
	}
	cppVar_25006 = cppVar_25010;
	} else {
	cppVar_25157 = ROM.rd(PC);
	cppVar_25159 = (cppVar_25157 == 137);
	if (cppVar_25159) {
	cppVar_25162 = PC + 1;
	cppVar_25162 = (cppVar_25162 & cppMask_un_16_);
	cppVar_25163 = ROM.rd(cppVar_25162);
	cppVar_25165 = (cppVar_25163 == 128);
	if (cppVar_25165) {
	cppVar_25168 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25170 = (cppVar_25168 << 3) | 1;
	cppVar_25170 = (cppVar_25170 & cppMask_un_5_);
	cppVar_25171 = (0 << 5) | cppVar_25170;
	cppVar_25171 = (cppVar_25171 & cppMask_un_8_);
	cppVar_25172 = (cppVar_25171 >> 7) & cppMask_un_1_;
	cppVar_25174 = (cppVar_25172 == 0);
	if (cppVar_25174) {
	cppVar_25175 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25176 = (cppVar_25175 << 3) | 1;
	cppVar_25176 = (cppVar_25176 & cppMask_un_5_);
	cppVar_25177 = (0 << 5) | cppVar_25176;
	cppVar_25177 = (cppVar_25177 & cppMask_un_8_);
	cppVar_25178 = IRAM.rd(cppVar_25177);
	cppVar_25166 = cppVar_25178;
	} else {
	cppVar_25180 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25181 = (cppVar_25180 << 3) | 1;
	cppVar_25181 = (cppVar_25181 & cppMask_un_5_);
	cppVar_25182 = (0 << 5) | cppVar_25181;
	cppVar_25182 = (cppVar_25182 & cppMask_un_8_);
	cppVar_25184 = (cppVar_25182 == 128);
	if (cppVar_25184) {
	cppVar_25179 = P0;
	} else {
	cppVar_25186 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25187 = (cppVar_25186 << 3) | 1;
	cppVar_25187 = (cppVar_25187 & cppMask_un_5_);
	cppVar_25188 = (0 << 5) | cppVar_25187;
	cppVar_25188 = (cppVar_25188 & cppMask_un_8_);
	cppVar_25190 = (cppVar_25188 == 129);
	if (cppVar_25190) {
	cppVar_25185 = SP;
	} else {
	cppVar_25192 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25193 = (cppVar_25192 << 3) | 1;
	cppVar_25193 = (cppVar_25193 & cppMask_un_5_);
	cppVar_25194 = (0 << 5) | cppVar_25193;
	cppVar_25194 = (cppVar_25194 & cppMask_un_8_);
	cppVar_25196 = (cppVar_25194 == 130);
	if (cppVar_25196) {
	cppVar_25191 = DPL;
	} else {
	cppVar_25198 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25199 = (cppVar_25198 << 3) | 1;
	cppVar_25199 = (cppVar_25199 & cppMask_un_5_);
	cppVar_25200 = (0 << 5) | cppVar_25199;
	cppVar_25200 = (cppVar_25200 & cppMask_un_8_);
	cppVar_25202 = (cppVar_25200 == 131);
	if (cppVar_25202) {
	cppVar_25197 = DPH;
	} else {
	cppVar_25204 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25205 = (cppVar_25204 << 3) | 1;
	cppVar_25205 = (cppVar_25205 & cppMask_un_5_);
	cppVar_25206 = (0 << 5) | cppVar_25205;
	cppVar_25206 = (cppVar_25206 & cppMask_un_8_);
	cppVar_25208 = (cppVar_25206 == 135);
	if (cppVar_25208) {
	cppVar_25203 = PCON;
	} else {
	cppVar_25210 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25211 = (cppVar_25210 << 3) | 1;
	cppVar_25211 = (cppVar_25211 & cppMask_un_5_);
	cppVar_25212 = (0 << 5) | cppVar_25211;
	cppVar_25212 = (cppVar_25212 & cppMask_un_8_);
	cppVar_25214 = (cppVar_25212 == 136);
	if (cppVar_25214) {
	cppVar_25209 = TCON;
	} else {
	cppVar_25216 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25217 = (cppVar_25216 << 3) | 1;
	cppVar_25217 = (cppVar_25217 & cppMask_un_5_);
	cppVar_25218 = (0 << 5) | cppVar_25217;
	cppVar_25218 = (cppVar_25218 & cppMask_un_8_);
	cppVar_25220 = (cppVar_25218 == 137);
	if (cppVar_25220) {
	cppVar_25215 = TMOD;
	} else {
	cppVar_25222 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25223 = (cppVar_25222 << 3) | 1;
	cppVar_25223 = (cppVar_25223 & cppMask_un_5_);
	cppVar_25224 = (0 << 5) | cppVar_25223;
	cppVar_25224 = (cppVar_25224 & cppMask_un_8_);
	cppVar_25226 = (cppVar_25224 == 138);
	if (cppVar_25226) {
	cppVar_25221 = TL0;
	} else {
	cppVar_25228 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25229 = (cppVar_25228 << 3) | 1;
	cppVar_25229 = (cppVar_25229 & cppMask_un_5_);
	cppVar_25230 = (0 << 5) | cppVar_25229;
	cppVar_25230 = (cppVar_25230 & cppMask_un_8_);
	cppVar_25232 = (cppVar_25230 == 140);
	if (cppVar_25232) {
	cppVar_25227 = TH0;
	} else {
	cppVar_25234 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25235 = (cppVar_25234 << 3) | 1;
	cppVar_25235 = (cppVar_25235 & cppMask_un_5_);
	cppVar_25236 = (0 << 5) | cppVar_25235;
	cppVar_25236 = (cppVar_25236 & cppMask_un_8_);
	cppVar_25238 = (cppVar_25236 == 139);
	if (cppVar_25238) {
	cppVar_25233 = TL1;
	} else {
	cppVar_25240 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25241 = (cppVar_25240 << 3) | 1;
	cppVar_25241 = (cppVar_25241 & cppMask_un_5_);
	cppVar_25242 = (0 << 5) | cppVar_25241;
	cppVar_25242 = (cppVar_25242 & cppMask_un_8_);
	cppVar_25244 = (cppVar_25242 == 141);
	if (cppVar_25244) {
	cppVar_25239 = TH1;
	} else {
	cppVar_25246 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25247 = (cppVar_25246 << 3) | 1;
	cppVar_25247 = (cppVar_25247 & cppMask_un_5_);
	cppVar_25248 = (0 << 5) | cppVar_25247;
	cppVar_25248 = (cppVar_25248 & cppMask_un_8_);
	cppVar_25250 = (cppVar_25248 == 144);
	if (cppVar_25250) {
	cppVar_25245 = P1;
	} else {
	cppVar_25252 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25253 = (cppVar_25252 << 3) | 1;
	cppVar_25253 = (cppVar_25253 & cppMask_un_5_);
	cppVar_25254 = (0 << 5) | cppVar_25253;
	cppVar_25254 = (cppVar_25254 & cppMask_un_8_);
	cppVar_25256 = (cppVar_25254 == 152);
	if (cppVar_25256) {
	cppVar_25251 = SCON;
	} else {
	cppVar_25258 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25259 = (cppVar_25258 << 3) | 1;
	cppVar_25259 = (cppVar_25259 & cppMask_un_5_);
	cppVar_25260 = (0 << 5) | cppVar_25259;
	cppVar_25260 = (cppVar_25260 & cppMask_un_8_);
	cppVar_25262 = (cppVar_25260 == 153);
	if (cppVar_25262) {
	cppVar_25257 = SBUF;
	} else {
	cppVar_25264 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25265 = (cppVar_25264 << 3) | 1;
	cppVar_25265 = (cppVar_25265 & cppMask_un_5_);
	cppVar_25266 = (0 << 5) | cppVar_25265;
	cppVar_25266 = (cppVar_25266 & cppMask_un_8_);
	cppVar_25268 = (cppVar_25266 == 160);
	if (cppVar_25268) {
	cppVar_25263 = P2;
	} else {
	cppVar_25270 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25271 = (cppVar_25270 << 3) | 1;
	cppVar_25271 = (cppVar_25271 & cppMask_un_5_);
	cppVar_25272 = (0 << 5) | cppVar_25271;
	cppVar_25272 = (cppVar_25272 & cppMask_un_8_);
	cppVar_25274 = (cppVar_25272 == 168);
	if (cppVar_25274) {
	cppVar_25269 = IE;
	} else {
	cppVar_25276 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25277 = (cppVar_25276 << 3) | 1;
	cppVar_25277 = (cppVar_25277 & cppMask_un_5_);
	cppVar_25278 = (0 << 5) | cppVar_25277;
	cppVar_25278 = (cppVar_25278 & cppMask_un_8_);
	cppVar_25280 = (cppVar_25278 == 176);
	if (cppVar_25280) {
	cppVar_25275 = P3;
	} else {
	cppVar_25282 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25283 = (cppVar_25282 << 3) | 1;
	cppVar_25283 = (cppVar_25283 & cppMask_un_5_);
	cppVar_25284 = (0 << 5) | cppVar_25283;
	cppVar_25284 = (cppVar_25284 & cppMask_un_8_);
	cppVar_25286 = (cppVar_25284 == 184);
	if (cppVar_25286) {
	cppVar_25281 = IP;
	} else {
	cppVar_25288 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25289 = (cppVar_25288 << 3) | 1;
	cppVar_25289 = (cppVar_25289 & cppMask_un_5_);
	cppVar_25290 = (0 << 5) | cppVar_25289;
	cppVar_25290 = (cppVar_25290 & cppMask_un_8_);
	cppVar_25292 = (cppVar_25290 == 208);
	if (cppVar_25292) {
	cppVar_25287 = PSW;
	} else {
	cppVar_25294 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25295 = (cppVar_25294 << 3) | 1;
	cppVar_25295 = (cppVar_25295 & cppMask_un_5_);
	cppVar_25296 = (0 << 5) | cppVar_25295;
	cppVar_25296 = (cppVar_25296 & cppMask_un_8_);
	cppVar_25298 = (cppVar_25296 == 224);
	if (cppVar_25298) {
	cppVar_25293 = ACC;
	} else {
	cppVar_25300 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25301 = (cppVar_25300 << 3) | 1;
	cppVar_25301 = (cppVar_25301 & cppMask_un_5_);
	cppVar_25302 = (0 << 5) | cppVar_25301;
	cppVar_25302 = (cppVar_25302 & cppMask_un_8_);
	cppVar_25304 = (cppVar_25302 == 240);
	if (cppVar_25304) {
	cppVar_25299 = B;
	} else {
	cppVar_25299 = 0;
	}
	cppVar_25293 = cppVar_25299;
	}
	cppVar_25287 = cppVar_25293;
	}
	cppVar_25281 = cppVar_25287;
	}
	cppVar_25275 = cppVar_25281;
	}
	cppVar_25269 = cppVar_25275;
	}
	cppVar_25263 = cppVar_25269;
	}
	cppVar_25257 = cppVar_25263;
	}
	cppVar_25251 = cppVar_25257;
	}
	cppVar_25245 = cppVar_25251;
	}
	cppVar_25239 = cppVar_25245;
	}
	cppVar_25233 = cppVar_25239;
	}
	cppVar_25227 = cppVar_25233;
	}
	cppVar_25221 = cppVar_25227;
	}
	cppVar_25215 = cppVar_25221;
	}
	cppVar_25209 = cppVar_25215;
	}
	cppVar_25203 = cppVar_25209;
	}
	cppVar_25197 = cppVar_25203;
	}
	cppVar_25191 = cppVar_25197;
	}
	cppVar_25185 = cppVar_25191;
	}
	cppVar_25179 = cppVar_25185;
	}
	cppVar_25166 = cppVar_25179;
	}
	cppVar_25160 = cppVar_25166;
	} else {
	cppVar_25160 = P0;
	}
	cppVar_25156 = cppVar_25160;
	} else {
	cppVar_25307 = ROM.rd(PC);
	cppVar_25309 = (cppVar_25307 == 136);
	if (cppVar_25309) {
	cppVar_25312 = PC + 1;
	cppVar_25312 = (cppVar_25312 & cppMask_un_16_);
	cppVar_25313 = ROM.rd(cppVar_25312);
	cppVar_25315 = (cppVar_25313 == 128);
	if (cppVar_25315) {
	cppVar_25318 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25320 = (cppVar_25318 << 3) | 0;
	cppVar_25320 = (cppVar_25320 & cppMask_un_5_);
	cppVar_25321 = (0 << 5) | cppVar_25320;
	cppVar_25321 = (cppVar_25321 & cppMask_un_8_);
	cppVar_25322 = (cppVar_25321 >> 7) & cppMask_un_1_;
	cppVar_25324 = (cppVar_25322 == 0);
	if (cppVar_25324) {
	cppVar_25325 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25326 = (cppVar_25325 << 3) | 0;
	cppVar_25326 = (cppVar_25326 & cppMask_un_5_);
	cppVar_25327 = (0 << 5) | cppVar_25326;
	cppVar_25327 = (cppVar_25327 & cppMask_un_8_);
	cppVar_25328 = IRAM.rd(cppVar_25327);
	cppVar_25316 = cppVar_25328;
	} else {
	cppVar_25330 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25331 = (cppVar_25330 << 3) | 0;
	cppVar_25331 = (cppVar_25331 & cppMask_un_5_);
	cppVar_25332 = (0 << 5) | cppVar_25331;
	cppVar_25332 = (cppVar_25332 & cppMask_un_8_);
	cppVar_25334 = (cppVar_25332 == 128);
	if (cppVar_25334) {
	cppVar_25329 = P0;
	} else {
	cppVar_25336 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25337 = (cppVar_25336 << 3) | 0;
	cppVar_25337 = (cppVar_25337 & cppMask_un_5_);
	cppVar_25338 = (0 << 5) | cppVar_25337;
	cppVar_25338 = (cppVar_25338 & cppMask_un_8_);
	cppVar_25340 = (cppVar_25338 == 129);
	if (cppVar_25340) {
	cppVar_25335 = SP;
	} else {
	cppVar_25342 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25343 = (cppVar_25342 << 3) | 0;
	cppVar_25343 = (cppVar_25343 & cppMask_un_5_);
	cppVar_25344 = (0 << 5) | cppVar_25343;
	cppVar_25344 = (cppVar_25344 & cppMask_un_8_);
	cppVar_25346 = (cppVar_25344 == 130);
	if (cppVar_25346) {
	cppVar_25341 = DPL;
	} else {
	cppVar_25348 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25349 = (cppVar_25348 << 3) | 0;
	cppVar_25349 = (cppVar_25349 & cppMask_un_5_);
	cppVar_25350 = (0 << 5) | cppVar_25349;
	cppVar_25350 = (cppVar_25350 & cppMask_un_8_);
	cppVar_25352 = (cppVar_25350 == 131);
	if (cppVar_25352) {
	cppVar_25347 = DPH;
	} else {
	cppVar_25354 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25355 = (cppVar_25354 << 3) | 0;
	cppVar_25355 = (cppVar_25355 & cppMask_un_5_);
	cppVar_25356 = (0 << 5) | cppVar_25355;
	cppVar_25356 = (cppVar_25356 & cppMask_un_8_);
	cppVar_25358 = (cppVar_25356 == 135);
	if (cppVar_25358) {
	cppVar_25353 = PCON;
	} else {
	cppVar_25360 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25361 = (cppVar_25360 << 3) | 0;
	cppVar_25361 = (cppVar_25361 & cppMask_un_5_);
	cppVar_25362 = (0 << 5) | cppVar_25361;
	cppVar_25362 = (cppVar_25362 & cppMask_un_8_);
	cppVar_25364 = (cppVar_25362 == 136);
	if (cppVar_25364) {
	cppVar_25359 = TCON;
	} else {
	cppVar_25366 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25367 = (cppVar_25366 << 3) | 0;
	cppVar_25367 = (cppVar_25367 & cppMask_un_5_);
	cppVar_25368 = (0 << 5) | cppVar_25367;
	cppVar_25368 = (cppVar_25368 & cppMask_un_8_);
	cppVar_25370 = (cppVar_25368 == 137);
	if (cppVar_25370) {
	cppVar_25365 = TMOD;
	} else {
	cppVar_25372 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25373 = (cppVar_25372 << 3) | 0;
	cppVar_25373 = (cppVar_25373 & cppMask_un_5_);
	cppVar_25374 = (0 << 5) | cppVar_25373;
	cppVar_25374 = (cppVar_25374 & cppMask_un_8_);
	cppVar_25376 = (cppVar_25374 == 138);
	if (cppVar_25376) {
	cppVar_25371 = TL0;
	} else {
	cppVar_25378 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25379 = (cppVar_25378 << 3) | 0;
	cppVar_25379 = (cppVar_25379 & cppMask_un_5_);
	cppVar_25380 = (0 << 5) | cppVar_25379;
	cppVar_25380 = (cppVar_25380 & cppMask_un_8_);
	cppVar_25382 = (cppVar_25380 == 140);
	if (cppVar_25382) {
	cppVar_25377 = TH0;
	} else {
	cppVar_25384 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25385 = (cppVar_25384 << 3) | 0;
	cppVar_25385 = (cppVar_25385 & cppMask_un_5_);
	cppVar_25386 = (0 << 5) | cppVar_25385;
	cppVar_25386 = (cppVar_25386 & cppMask_un_8_);
	cppVar_25388 = (cppVar_25386 == 139);
	if (cppVar_25388) {
	cppVar_25383 = TL1;
	} else {
	cppVar_25390 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25391 = (cppVar_25390 << 3) | 0;
	cppVar_25391 = (cppVar_25391 & cppMask_un_5_);
	cppVar_25392 = (0 << 5) | cppVar_25391;
	cppVar_25392 = (cppVar_25392 & cppMask_un_8_);
	cppVar_25394 = (cppVar_25392 == 141);
	if (cppVar_25394) {
	cppVar_25389 = TH1;
	} else {
	cppVar_25396 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25397 = (cppVar_25396 << 3) | 0;
	cppVar_25397 = (cppVar_25397 & cppMask_un_5_);
	cppVar_25398 = (0 << 5) | cppVar_25397;
	cppVar_25398 = (cppVar_25398 & cppMask_un_8_);
	cppVar_25400 = (cppVar_25398 == 144);
	if (cppVar_25400) {
	cppVar_25395 = P1;
	} else {
	cppVar_25402 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25403 = (cppVar_25402 << 3) | 0;
	cppVar_25403 = (cppVar_25403 & cppMask_un_5_);
	cppVar_25404 = (0 << 5) | cppVar_25403;
	cppVar_25404 = (cppVar_25404 & cppMask_un_8_);
	cppVar_25406 = (cppVar_25404 == 152);
	if (cppVar_25406) {
	cppVar_25401 = SCON;
	} else {
	cppVar_25408 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25409 = (cppVar_25408 << 3) | 0;
	cppVar_25409 = (cppVar_25409 & cppMask_un_5_);
	cppVar_25410 = (0 << 5) | cppVar_25409;
	cppVar_25410 = (cppVar_25410 & cppMask_un_8_);
	cppVar_25412 = (cppVar_25410 == 153);
	if (cppVar_25412) {
	cppVar_25407 = SBUF;
	} else {
	cppVar_25414 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25415 = (cppVar_25414 << 3) | 0;
	cppVar_25415 = (cppVar_25415 & cppMask_un_5_);
	cppVar_25416 = (0 << 5) | cppVar_25415;
	cppVar_25416 = (cppVar_25416 & cppMask_un_8_);
	cppVar_25418 = (cppVar_25416 == 160);
	if (cppVar_25418) {
	cppVar_25413 = P2;
	} else {
	cppVar_25420 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25421 = (cppVar_25420 << 3) | 0;
	cppVar_25421 = (cppVar_25421 & cppMask_un_5_);
	cppVar_25422 = (0 << 5) | cppVar_25421;
	cppVar_25422 = (cppVar_25422 & cppMask_un_8_);
	cppVar_25424 = (cppVar_25422 == 168);
	if (cppVar_25424) {
	cppVar_25419 = IE;
	} else {
	cppVar_25426 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25427 = (cppVar_25426 << 3) | 0;
	cppVar_25427 = (cppVar_25427 & cppMask_un_5_);
	cppVar_25428 = (0 << 5) | cppVar_25427;
	cppVar_25428 = (cppVar_25428 & cppMask_un_8_);
	cppVar_25430 = (cppVar_25428 == 176);
	if (cppVar_25430) {
	cppVar_25425 = P3;
	} else {
	cppVar_25432 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25433 = (cppVar_25432 << 3) | 0;
	cppVar_25433 = (cppVar_25433 & cppMask_un_5_);
	cppVar_25434 = (0 << 5) | cppVar_25433;
	cppVar_25434 = (cppVar_25434 & cppMask_un_8_);
	cppVar_25436 = (cppVar_25434 == 184);
	if (cppVar_25436) {
	cppVar_25431 = IP;
	} else {
	cppVar_25438 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25439 = (cppVar_25438 << 3) | 0;
	cppVar_25439 = (cppVar_25439 & cppMask_un_5_);
	cppVar_25440 = (0 << 5) | cppVar_25439;
	cppVar_25440 = (cppVar_25440 & cppMask_un_8_);
	cppVar_25442 = (cppVar_25440 == 208);
	if (cppVar_25442) {
	cppVar_25437 = PSW;
	} else {
	cppVar_25444 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25445 = (cppVar_25444 << 3) | 0;
	cppVar_25445 = (cppVar_25445 & cppMask_un_5_);
	cppVar_25446 = (0 << 5) | cppVar_25445;
	cppVar_25446 = (cppVar_25446 & cppMask_un_8_);
	cppVar_25448 = (cppVar_25446 == 224);
	if (cppVar_25448) {
	cppVar_25443 = ACC;
	} else {
	cppVar_25450 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25451 = (cppVar_25450 << 3) | 0;
	cppVar_25451 = (cppVar_25451 & cppMask_un_5_);
	cppVar_25452 = (0 << 5) | cppVar_25451;
	cppVar_25452 = (cppVar_25452 & cppMask_un_8_);
	cppVar_25454 = (cppVar_25452 == 240);
	if (cppVar_25454) {
	cppVar_25449 = B;
	} else {
	cppVar_25449 = 0;
	}
	cppVar_25443 = cppVar_25449;
	}
	cppVar_25437 = cppVar_25443;
	}
	cppVar_25431 = cppVar_25437;
	}
	cppVar_25425 = cppVar_25431;
	}
	cppVar_25419 = cppVar_25425;
	}
	cppVar_25413 = cppVar_25419;
	}
	cppVar_25407 = cppVar_25413;
	}
	cppVar_25401 = cppVar_25407;
	}
	cppVar_25395 = cppVar_25401;
	}
	cppVar_25389 = cppVar_25395;
	}
	cppVar_25383 = cppVar_25389;
	}
	cppVar_25377 = cppVar_25383;
	}
	cppVar_25371 = cppVar_25377;
	}
	cppVar_25365 = cppVar_25371;
	}
	cppVar_25359 = cppVar_25365;
	}
	cppVar_25353 = cppVar_25359;
	}
	cppVar_25347 = cppVar_25353;
	}
	cppVar_25341 = cppVar_25347;
	}
	cppVar_25335 = cppVar_25341;
	}
	cppVar_25329 = cppVar_25335;
	}
	cppVar_25316 = cppVar_25329;
	}
	cppVar_25310 = cppVar_25316;
	} else {
	cppVar_25310 = P0;
	}
	cppVar_25306 = cppVar_25310;
	} else {
	cppVar_25457 = ROM.rd(PC);
	cppVar_25459 = (cppVar_25457 == 135);
	if (cppVar_25459) {
	cppVar_25462 = PC + 1;
	cppVar_25462 = (cppVar_25462 & cppMask_un_16_);
	cppVar_25463 = ROM.rd(cppVar_25462);
	cppVar_25465 = (cppVar_25463 == 128);
	if (cppVar_25465) {
	cppVar_25467 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25469 = (cppVar_25467 << 3) | 1;
	cppVar_25469 = (cppVar_25469 & cppMask_un_5_);
	cppVar_25470 = (0 << 5) | cppVar_25469;
	cppVar_25470 = (cppVar_25470 & cppMask_un_8_);
	cppVar_25471 = IRAM.rd(cppVar_25470);
	cppVar_25472 = IRAM.rd(cppVar_25471);
	cppVar_25460 = cppVar_25472;
	} else {
	cppVar_25460 = P0;
	}
	cppVar_25456 = cppVar_25460;
	} else {
	cppVar_25474 = ROM.rd(PC);
	cppVar_25476 = (cppVar_25474 == 134);
	if (cppVar_25476) {
	cppVar_25479 = PC + 1;
	cppVar_25479 = (cppVar_25479 & cppMask_un_16_);
	cppVar_25480 = ROM.rd(cppVar_25479);
	cppVar_25482 = (cppVar_25480 == 128);
	if (cppVar_25482) {
	cppVar_25484 = (PSW >> 3) & cppMask_un_2_;
	cppVar_25486 = (cppVar_25484 << 3) | 0;
	cppVar_25486 = (cppVar_25486 & cppMask_un_5_);
	cppVar_25487 = (0 << 5) | cppVar_25486;
	cppVar_25487 = (cppVar_25487 & cppMask_un_8_);
	cppVar_25488 = IRAM.rd(cppVar_25487);
	cppVar_25489 = IRAM.rd(cppVar_25488);
	cppVar_25477 = cppVar_25489;
	} else {
	cppVar_25477 = P0;
	}
	cppVar_25473 = cppVar_25477;
	} else {
	cppVar_25491 = ROM.rd(PC);
	cppVar_25493 = (cppVar_25491 == 133);
	if (cppVar_25493) {
	cppVar_25496 = PC + 2;
	cppVar_25496 = (cppVar_25496 & cppMask_un_16_);
	cppVar_25497 = ROM.rd(cppVar_25496);
	cppVar_25499 = (cppVar_25497 == 128);
	if (cppVar_25499) {
	cppVar_25502 = PC + 1;
	cppVar_25502 = (cppVar_25502 & cppMask_un_16_);
	cppVar_25503 = ROM.rd(cppVar_25502);
	cppVar_25504 = (cppVar_25503 >> 7) & cppMask_un_1_;
	cppVar_25506 = (cppVar_25504 == 0);
	if (cppVar_25506) {
	cppVar_25507 = PC + 1;
	cppVar_25507 = (cppVar_25507 & cppMask_un_16_);
	cppVar_25508 = ROM.rd(cppVar_25507);
	cppVar_25509 = IRAM.rd(cppVar_25508);
	cppVar_25500 = cppVar_25509;
	} else {
	cppVar_25511 = PC + 1;
	cppVar_25511 = (cppVar_25511 & cppMask_un_16_);
	cppVar_25512 = ROM.rd(cppVar_25511);
	cppVar_25514 = (cppVar_25512 == 128);
	if (cppVar_25514) {
	cppVar_25510 = P0;
	} else {
	cppVar_25516 = PC + 1;
	cppVar_25516 = (cppVar_25516 & cppMask_un_16_);
	cppVar_25517 = ROM.rd(cppVar_25516);
	cppVar_25519 = (cppVar_25517 == 129);
	if (cppVar_25519) {
	cppVar_25515 = SP;
	} else {
	cppVar_25521 = PC + 1;
	cppVar_25521 = (cppVar_25521 & cppMask_un_16_);
	cppVar_25522 = ROM.rd(cppVar_25521);
	cppVar_25524 = (cppVar_25522 == 130);
	if (cppVar_25524) {
	cppVar_25520 = DPL;
	} else {
	cppVar_25526 = PC + 1;
	cppVar_25526 = (cppVar_25526 & cppMask_un_16_);
	cppVar_25527 = ROM.rd(cppVar_25526);
	cppVar_25529 = (cppVar_25527 == 131);
	if (cppVar_25529) {
	cppVar_25525 = DPH;
	} else {
	cppVar_25531 = PC + 1;
	cppVar_25531 = (cppVar_25531 & cppMask_un_16_);
	cppVar_25532 = ROM.rd(cppVar_25531);
	cppVar_25534 = (cppVar_25532 == 135);
	if (cppVar_25534) {
	cppVar_25530 = PCON;
	} else {
	cppVar_25536 = PC + 1;
	cppVar_25536 = (cppVar_25536 & cppMask_un_16_);
	cppVar_25537 = ROM.rd(cppVar_25536);
	cppVar_25539 = (cppVar_25537 == 136);
	if (cppVar_25539) {
	cppVar_25535 = TCON;
	} else {
	cppVar_25541 = PC + 1;
	cppVar_25541 = (cppVar_25541 & cppMask_un_16_);
	cppVar_25542 = ROM.rd(cppVar_25541);
	cppVar_25544 = (cppVar_25542 == 137);
	if (cppVar_25544) {
	cppVar_25540 = TMOD;
	} else {
	cppVar_25546 = PC + 1;
	cppVar_25546 = (cppVar_25546 & cppMask_un_16_);
	cppVar_25547 = ROM.rd(cppVar_25546);
	cppVar_25549 = (cppVar_25547 == 138);
	if (cppVar_25549) {
	cppVar_25545 = TL0;
	} else {
	cppVar_25551 = PC + 1;
	cppVar_25551 = (cppVar_25551 & cppMask_un_16_);
	cppVar_25552 = ROM.rd(cppVar_25551);
	cppVar_25554 = (cppVar_25552 == 140);
	if (cppVar_25554) {
	cppVar_25550 = TH0;
	} else {
	cppVar_25556 = PC + 1;
	cppVar_25556 = (cppVar_25556 & cppMask_un_16_);
	cppVar_25557 = ROM.rd(cppVar_25556);
	cppVar_25559 = (cppVar_25557 == 139);
	if (cppVar_25559) {
	cppVar_25555 = TL1;
	} else {
	cppVar_25561 = PC + 1;
	cppVar_25561 = (cppVar_25561 & cppMask_un_16_);
	cppVar_25562 = ROM.rd(cppVar_25561);
	cppVar_25564 = (cppVar_25562 == 141);
	if (cppVar_25564) {
	cppVar_25560 = TH1;
	} else {
	cppVar_25566 = PC + 1;
	cppVar_25566 = (cppVar_25566 & cppMask_un_16_);
	cppVar_25567 = ROM.rd(cppVar_25566);
	cppVar_25569 = (cppVar_25567 == 144);
	if (cppVar_25569) {
	cppVar_25565 = P1;
	} else {
	cppVar_25571 = PC + 1;
	cppVar_25571 = (cppVar_25571 & cppMask_un_16_);
	cppVar_25572 = ROM.rd(cppVar_25571);
	cppVar_25574 = (cppVar_25572 == 152);
	if (cppVar_25574) {
	cppVar_25570 = SCON;
	} else {
	cppVar_25576 = PC + 1;
	cppVar_25576 = (cppVar_25576 & cppMask_un_16_);
	cppVar_25577 = ROM.rd(cppVar_25576);
	cppVar_25579 = (cppVar_25577 == 153);
	if (cppVar_25579) {
	cppVar_25575 = SBUF;
	} else {
	cppVar_25581 = PC + 1;
	cppVar_25581 = (cppVar_25581 & cppMask_un_16_);
	cppVar_25582 = ROM.rd(cppVar_25581);
	cppVar_25584 = (cppVar_25582 == 160);
	if (cppVar_25584) {
	cppVar_25580 = P2;
	} else {
	cppVar_25586 = PC + 1;
	cppVar_25586 = (cppVar_25586 & cppMask_un_16_);
	cppVar_25587 = ROM.rd(cppVar_25586);
	cppVar_25589 = (cppVar_25587 == 168);
	if (cppVar_25589) {
	cppVar_25585 = IE;
	} else {
	cppVar_25591 = PC + 1;
	cppVar_25591 = (cppVar_25591 & cppMask_un_16_);
	cppVar_25592 = ROM.rd(cppVar_25591);
	cppVar_25594 = (cppVar_25592 == 176);
	if (cppVar_25594) {
	cppVar_25590 = P3;
	} else {
	cppVar_25596 = PC + 1;
	cppVar_25596 = (cppVar_25596 & cppMask_un_16_);
	cppVar_25597 = ROM.rd(cppVar_25596);
	cppVar_25599 = (cppVar_25597 == 184);
	if (cppVar_25599) {
	cppVar_25595 = IP;
	} else {
	cppVar_25601 = PC + 1;
	cppVar_25601 = (cppVar_25601 & cppMask_un_16_);
	cppVar_25602 = ROM.rd(cppVar_25601);
	cppVar_25604 = (cppVar_25602 == 208);
	if (cppVar_25604) {
	cppVar_25600 = PSW;
	} else {
	cppVar_25606 = PC + 1;
	cppVar_25606 = (cppVar_25606 & cppMask_un_16_);
	cppVar_25607 = ROM.rd(cppVar_25606);
	cppVar_25609 = (cppVar_25607 == 224);
	if (cppVar_25609) {
	cppVar_25605 = ACC;
	} else {
	cppVar_25611 = PC + 1;
	cppVar_25611 = (cppVar_25611 & cppMask_un_16_);
	cppVar_25612 = ROM.rd(cppVar_25611);
	cppVar_25614 = (cppVar_25612 == 240);
	if (cppVar_25614) {
	cppVar_25610 = B;
	} else {
	cppVar_25610 = 0;
	}
	cppVar_25605 = cppVar_25610;
	}
	cppVar_25600 = cppVar_25605;
	}
	cppVar_25595 = cppVar_25600;
	}
	cppVar_25590 = cppVar_25595;
	}
	cppVar_25585 = cppVar_25590;
	}
	cppVar_25580 = cppVar_25585;
	}
	cppVar_25575 = cppVar_25580;
	}
	cppVar_25570 = cppVar_25575;
	}
	cppVar_25565 = cppVar_25570;
	}
	cppVar_25560 = cppVar_25565;
	}
	cppVar_25555 = cppVar_25560;
	}
	cppVar_25550 = cppVar_25555;
	}
	cppVar_25545 = cppVar_25550;
	}
	cppVar_25540 = cppVar_25545;
	}
	cppVar_25535 = cppVar_25540;
	}
	cppVar_25530 = cppVar_25535;
	}
	cppVar_25525 = cppVar_25530;
	}
	cppVar_25520 = cppVar_25525;
	}
	cppVar_25515 = cppVar_25520;
	}
	cppVar_25510 = cppVar_25515;
	}
	cppVar_25500 = cppVar_25510;
	}
	cppVar_25494 = cppVar_25500;
	} else {
	cppVar_25494 = P0;
	}
	cppVar_25490 = cppVar_25494;
	} else {
	cppVar_25617 = ROM.rd(PC);
	cppVar_25619 = (cppVar_25617 == 117);
	if (cppVar_25619) {
	cppVar_25622 = PC + 1;
	cppVar_25622 = (cppVar_25622 & cppMask_un_16_);
	cppVar_25623 = ROM.rd(cppVar_25622);
	cppVar_25625 = (cppVar_25623 == 128);
	if (cppVar_25625) {
	cppVar_25627 = PC + 2;
	cppVar_25627 = (cppVar_25627 & cppMask_un_16_);
	cppVar_25628 = ROM.rd(cppVar_25627);
	cppVar_25620 = cppVar_25628;
	} else {
	cppVar_25620 = P0;
	}
	cppVar_25616 = cppVar_25620;
	} else {
	cppVar_25630 = ROM.rd(PC);
	cppVar_25632 = (cppVar_25630 == 99);
	if (cppVar_25632) {
	cppVar_25635 = PC + 1;
	cppVar_25635 = (cppVar_25635 & cppMask_un_16_);
	cppVar_25636 = ROM.rd(cppVar_25635);
	cppVar_25638 = (cppVar_25636 == 128);
	if (cppVar_25638) {
	cppVar_25640 = PC + 1;
	cppVar_25640 = (cppVar_25640 & cppMask_un_16_);
	cppVar_25641 = ROM.rd(cppVar_25640);
	cppVar_25642 = (cppVar_25641 >> 7) & cppMask_un_1_;
	cppVar_25644 = (cppVar_25642 == 0);
	if (cppVar_25644) {
	cppVar_25645 = PC + 1;
	cppVar_25645 = (cppVar_25645 & cppMask_un_16_);
	cppVar_25646 = ROM.rd(cppVar_25645);
	cppVar_25647 = IRAM.rd(cppVar_25646);
	cppVar_25639 = cppVar_25647;
	} else {
	cppVar_25649 = PC + 1;
	cppVar_25649 = (cppVar_25649 & cppMask_un_16_);
	cppVar_25650 = ROM.rd(cppVar_25649);
	cppVar_25652 = (cppVar_25650 == 128);
	if (cppVar_25652) {
	cppVar_25648 = P0;
	} else {
	cppVar_25654 = PC + 1;
	cppVar_25654 = (cppVar_25654 & cppMask_un_16_);
	cppVar_25655 = ROM.rd(cppVar_25654);
	cppVar_25657 = (cppVar_25655 == 129);
	if (cppVar_25657) {
	cppVar_25653 = SP;
	} else {
	cppVar_25659 = PC + 1;
	cppVar_25659 = (cppVar_25659 & cppMask_un_16_);
	cppVar_25660 = ROM.rd(cppVar_25659);
	cppVar_25662 = (cppVar_25660 == 130);
	if (cppVar_25662) {
	cppVar_25658 = DPL;
	} else {
	cppVar_25664 = PC + 1;
	cppVar_25664 = (cppVar_25664 & cppMask_un_16_);
	cppVar_25665 = ROM.rd(cppVar_25664);
	cppVar_25667 = (cppVar_25665 == 131);
	if (cppVar_25667) {
	cppVar_25663 = DPH;
	} else {
	cppVar_25669 = PC + 1;
	cppVar_25669 = (cppVar_25669 & cppMask_un_16_);
	cppVar_25670 = ROM.rd(cppVar_25669);
	cppVar_25672 = (cppVar_25670 == 135);
	if (cppVar_25672) {
	cppVar_25668 = PCON;
	} else {
	cppVar_25674 = PC + 1;
	cppVar_25674 = (cppVar_25674 & cppMask_un_16_);
	cppVar_25675 = ROM.rd(cppVar_25674);
	cppVar_25677 = (cppVar_25675 == 136);
	if (cppVar_25677) {
	cppVar_25673 = TCON;
	} else {
	cppVar_25679 = PC + 1;
	cppVar_25679 = (cppVar_25679 & cppMask_un_16_);
	cppVar_25680 = ROM.rd(cppVar_25679);
	cppVar_25682 = (cppVar_25680 == 137);
	if (cppVar_25682) {
	cppVar_25678 = TMOD;
	} else {
	cppVar_25684 = PC + 1;
	cppVar_25684 = (cppVar_25684 & cppMask_un_16_);
	cppVar_25685 = ROM.rd(cppVar_25684);
	cppVar_25687 = (cppVar_25685 == 138);
	if (cppVar_25687) {
	cppVar_25683 = TL0;
	} else {
	cppVar_25689 = PC + 1;
	cppVar_25689 = (cppVar_25689 & cppMask_un_16_);
	cppVar_25690 = ROM.rd(cppVar_25689);
	cppVar_25692 = (cppVar_25690 == 140);
	if (cppVar_25692) {
	cppVar_25688 = TH0;
	} else {
	cppVar_25694 = PC + 1;
	cppVar_25694 = (cppVar_25694 & cppMask_un_16_);
	cppVar_25695 = ROM.rd(cppVar_25694);
	cppVar_25697 = (cppVar_25695 == 139);
	if (cppVar_25697) {
	cppVar_25693 = TL1;
	} else {
	cppVar_25699 = PC + 1;
	cppVar_25699 = (cppVar_25699 & cppMask_un_16_);
	cppVar_25700 = ROM.rd(cppVar_25699);
	cppVar_25702 = (cppVar_25700 == 141);
	if (cppVar_25702) {
	cppVar_25698 = TH1;
	} else {
	cppVar_25704 = PC + 1;
	cppVar_25704 = (cppVar_25704 & cppMask_un_16_);
	cppVar_25705 = ROM.rd(cppVar_25704);
	cppVar_25707 = (cppVar_25705 == 144);
	if (cppVar_25707) {
	cppVar_25703 = P1;
	} else {
	cppVar_25709 = PC + 1;
	cppVar_25709 = (cppVar_25709 & cppMask_un_16_);
	cppVar_25710 = ROM.rd(cppVar_25709);
	cppVar_25712 = (cppVar_25710 == 152);
	if (cppVar_25712) {
	cppVar_25708 = SCON;
	} else {
	cppVar_25714 = PC + 1;
	cppVar_25714 = (cppVar_25714 & cppMask_un_16_);
	cppVar_25715 = ROM.rd(cppVar_25714);
	cppVar_25717 = (cppVar_25715 == 153);
	if (cppVar_25717) {
	cppVar_25713 = SBUF;
	} else {
	cppVar_25719 = PC + 1;
	cppVar_25719 = (cppVar_25719 & cppMask_un_16_);
	cppVar_25720 = ROM.rd(cppVar_25719);
	cppVar_25722 = (cppVar_25720 == 160);
	if (cppVar_25722) {
	cppVar_25718 = P2;
	} else {
	cppVar_25724 = PC + 1;
	cppVar_25724 = (cppVar_25724 & cppMask_un_16_);
	cppVar_25725 = ROM.rd(cppVar_25724);
	cppVar_25727 = (cppVar_25725 == 168);
	if (cppVar_25727) {
	cppVar_25723 = IE;
	} else {
	cppVar_25729 = PC + 1;
	cppVar_25729 = (cppVar_25729 & cppMask_un_16_);
	cppVar_25730 = ROM.rd(cppVar_25729);
	cppVar_25732 = (cppVar_25730 == 176);
	if (cppVar_25732) {
	cppVar_25728 = P3;
	} else {
	cppVar_25734 = PC + 1;
	cppVar_25734 = (cppVar_25734 & cppMask_un_16_);
	cppVar_25735 = ROM.rd(cppVar_25734);
	cppVar_25737 = (cppVar_25735 == 184);
	if (cppVar_25737) {
	cppVar_25733 = IP;
	} else {
	cppVar_25739 = PC + 1;
	cppVar_25739 = (cppVar_25739 & cppMask_un_16_);
	cppVar_25740 = ROM.rd(cppVar_25739);
	cppVar_25742 = (cppVar_25740 == 208);
	if (cppVar_25742) {
	cppVar_25738 = PSW;
	} else {
	cppVar_25744 = PC + 1;
	cppVar_25744 = (cppVar_25744 & cppMask_un_16_);
	cppVar_25745 = ROM.rd(cppVar_25744);
	cppVar_25747 = (cppVar_25745 == 224);
	if (cppVar_25747) {
	cppVar_25743 = ACC;
	} else {
	cppVar_25749 = PC + 1;
	cppVar_25749 = (cppVar_25749 & cppMask_un_16_);
	cppVar_25750 = ROM.rd(cppVar_25749);
	cppVar_25752 = (cppVar_25750 == 240);
	if (cppVar_25752) {
	cppVar_25748 = B;
	} else {
	cppVar_25748 = 0;
	}
	cppVar_25743 = cppVar_25748;
	}
	cppVar_25738 = cppVar_25743;
	}
	cppVar_25733 = cppVar_25738;
	}
	cppVar_25728 = cppVar_25733;
	}
	cppVar_25723 = cppVar_25728;
	}
	cppVar_25718 = cppVar_25723;
	}
	cppVar_25713 = cppVar_25718;
	}
	cppVar_25708 = cppVar_25713;
	}
	cppVar_25703 = cppVar_25708;
	}
	cppVar_25698 = cppVar_25703;
	}
	cppVar_25693 = cppVar_25698;
	}
	cppVar_25688 = cppVar_25693;
	}
	cppVar_25683 = cppVar_25688;
	}
	cppVar_25678 = cppVar_25683;
	}
	cppVar_25673 = cppVar_25678;
	}
	cppVar_25668 = cppVar_25673;
	}
	cppVar_25663 = cppVar_25668;
	}
	cppVar_25658 = cppVar_25663;
	}
	cppVar_25653 = cppVar_25658;
	}
	cppVar_25648 = cppVar_25653;
	}
	cppVar_25639 = cppVar_25648;
	}
	cppVar_25755 = PC + 2;
	cppVar_25755 = (cppVar_25755 & cppMask_un_16_);
	cppVar_25756 = ROM.rd(cppVar_25755);
	cppVar_25757 = cppVar_25639 ^ cppVar_25756;
	cppVar_25633 = cppVar_25757;
	} else {
	cppVar_25633 = P0;
	}
	cppVar_25629 = cppVar_25633;
	} else {
	cppVar_25759 = ROM.rd(PC);
	cppVar_25761 = (cppVar_25759 == 98);
	if (cppVar_25761) {
	cppVar_25764 = PC + 1;
	cppVar_25764 = (cppVar_25764 & cppMask_un_16_);
	cppVar_25765 = ROM.rd(cppVar_25764);
	cppVar_25767 = (cppVar_25765 == 128);
	if (cppVar_25767) {
	cppVar_25769 = PC + 1;
	cppVar_25769 = (cppVar_25769 & cppMask_un_16_);
	cppVar_25770 = ROM.rd(cppVar_25769);
	cppVar_25771 = (cppVar_25770 >> 7) & cppMask_un_1_;
	cppVar_25773 = (cppVar_25771 == 0);
	if (cppVar_25773) {
	cppVar_25774 = PC + 1;
	cppVar_25774 = (cppVar_25774 & cppMask_un_16_);
	cppVar_25775 = ROM.rd(cppVar_25774);
	cppVar_25776 = IRAM.rd(cppVar_25775);
	cppVar_25768 = cppVar_25776;
	} else {
	cppVar_25778 = PC + 1;
	cppVar_25778 = (cppVar_25778 & cppMask_un_16_);
	cppVar_25779 = ROM.rd(cppVar_25778);
	cppVar_25781 = (cppVar_25779 == 128);
	if (cppVar_25781) {
	cppVar_25777 = P0;
	} else {
	cppVar_25783 = PC + 1;
	cppVar_25783 = (cppVar_25783 & cppMask_un_16_);
	cppVar_25784 = ROM.rd(cppVar_25783);
	cppVar_25786 = (cppVar_25784 == 129);
	if (cppVar_25786) {
	cppVar_25782 = SP;
	} else {
	cppVar_25788 = PC + 1;
	cppVar_25788 = (cppVar_25788 & cppMask_un_16_);
	cppVar_25789 = ROM.rd(cppVar_25788);
	cppVar_25791 = (cppVar_25789 == 130);
	if (cppVar_25791) {
	cppVar_25787 = DPL;
	} else {
	cppVar_25793 = PC + 1;
	cppVar_25793 = (cppVar_25793 & cppMask_un_16_);
	cppVar_25794 = ROM.rd(cppVar_25793);
	cppVar_25796 = (cppVar_25794 == 131);
	if (cppVar_25796) {
	cppVar_25792 = DPH;
	} else {
	cppVar_25798 = PC + 1;
	cppVar_25798 = (cppVar_25798 & cppMask_un_16_);
	cppVar_25799 = ROM.rd(cppVar_25798);
	cppVar_25801 = (cppVar_25799 == 135);
	if (cppVar_25801) {
	cppVar_25797 = PCON;
	} else {
	cppVar_25803 = PC + 1;
	cppVar_25803 = (cppVar_25803 & cppMask_un_16_);
	cppVar_25804 = ROM.rd(cppVar_25803);
	cppVar_25806 = (cppVar_25804 == 136);
	if (cppVar_25806) {
	cppVar_25802 = TCON;
	} else {
	cppVar_25808 = PC + 1;
	cppVar_25808 = (cppVar_25808 & cppMask_un_16_);
	cppVar_25809 = ROM.rd(cppVar_25808);
	cppVar_25811 = (cppVar_25809 == 137);
	if (cppVar_25811) {
	cppVar_25807 = TMOD;
	} else {
	cppVar_25813 = PC + 1;
	cppVar_25813 = (cppVar_25813 & cppMask_un_16_);
	cppVar_25814 = ROM.rd(cppVar_25813);
	cppVar_25816 = (cppVar_25814 == 138);
	if (cppVar_25816) {
	cppVar_25812 = TL0;
	} else {
	cppVar_25818 = PC + 1;
	cppVar_25818 = (cppVar_25818 & cppMask_un_16_);
	cppVar_25819 = ROM.rd(cppVar_25818);
	cppVar_25821 = (cppVar_25819 == 140);
	if (cppVar_25821) {
	cppVar_25817 = TH0;
	} else {
	cppVar_25823 = PC + 1;
	cppVar_25823 = (cppVar_25823 & cppMask_un_16_);
	cppVar_25824 = ROM.rd(cppVar_25823);
	cppVar_25826 = (cppVar_25824 == 139);
	if (cppVar_25826) {
	cppVar_25822 = TL1;
	} else {
	cppVar_25828 = PC + 1;
	cppVar_25828 = (cppVar_25828 & cppMask_un_16_);
	cppVar_25829 = ROM.rd(cppVar_25828);
	cppVar_25831 = (cppVar_25829 == 141);
	if (cppVar_25831) {
	cppVar_25827 = TH1;
	} else {
	cppVar_25833 = PC + 1;
	cppVar_25833 = (cppVar_25833 & cppMask_un_16_);
	cppVar_25834 = ROM.rd(cppVar_25833);
	cppVar_25836 = (cppVar_25834 == 144);
	if (cppVar_25836) {
	cppVar_25832 = P1;
	} else {
	cppVar_25838 = PC + 1;
	cppVar_25838 = (cppVar_25838 & cppMask_un_16_);
	cppVar_25839 = ROM.rd(cppVar_25838);
	cppVar_25841 = (cppVar_25839 == 152);
	if (cppVar_25841) {
	cppVar_25837 = SCON;
	} else {
	cppVar_25843 = PC + 1;
	cppVar_25843 = (cppVar_25843 & cppMask_un_16_);
	cppVar_25844 = ROM.rd(cppVar_25843);
	cppVar_25846 = (cppVar_25844 == 153);
	if (cppVar_25846) {
	cppVar_25842 = SBUF;
	} else {
	cppVar_25848 = PC + 1;
	cppVar_25848 = (cppVar_25848 & cppMask_un_16_);
	cppVar_25849 = ROM.rd(cppVar_25848);
	cppVar_25851 = (cppVar_25849 == 160);
	if (cppVar_25851) {
	cppVar_25847 = P2;
	} else {
	cppVar_25853 = PC + 1;
	cppVar_25853 = (cppVar_25853 & cppMask_un_16_);
	cppVar_25854 = ROM.rd(cppVar_25853);
	cppVar_25856 = (cppVar_25854 == 168);
	if (cppVar_25856) {
	cppVar_25852 = IE;
	} else {
	cppVar_25858 = PC + 1;
	cppVar_25858 = (cppVar_25858 & cppMask_un_16_);
	cppVar_25859 = ROM.rd(cppVar_25858);
	cppVar_25861 = (cppVar_25859 == 176);
	if (cppVar_25861) {
	cppVar_25857 = P3;
	} else {
	cppVar_25863 = PC + 1;
	cppVar_25863 = (cppVar_25863 & cppMask_un_16_);
	cppVar_25864 = ROM.rd(cppVar_25863);
	cppVar_25866 = (cppVar_25864 == 184);
	if (cppVar_25866) {
	cppVar_25862 = IP;
	} else {
	cppVar_25868 = PC + 1;
	cppVar_25868 = (cppVar_25868 & cppMask_un_16_);
	cppVar_25869 = ROM.rd(cppVar_25868);
	cppVar_25871 = (cppVar_25869 == 208);
	if (cppVar_25871) {
	cppVar_25867 = PSW;
	} else {
	cppVar_25873 = PC + 1;
	cppVar_25873 = (cppVar_25873 & cppMask_un_16_);
	cppVar_25874 = ROM.rd(cppVar_25873);
	cppVar_25876 = (cppVar_25874 == 224);
	if (cppVar_25876) {
	cppVar_25872 = ACC;
	} else {
	cppVar_25878 = PC + 1;
	cppVar_25878 = (cppVar_25878 & cppMask_un_16_);
	cppVar_25879 = ROM.rd(cppVar_25878);
	cppVar_25881 = (cppVar_25879 == 240);
	if (cppVar_25881) {
	cppVar_25877 = B;
	} else {
	cppVar_25877 = 0;
	}
	cppVar_25872 = cppVar_25877;
	}
	cppVar_25867 = cppVar_25872;
	}
	cppVar_25862 = cppVar_25867;
	}
	cppVar_25857 = cppVar_25862;
	}
	cppVar_25852 = cppVar_25857;
	}
	cppVar_25847 = cppVar_25852;
	}
	cppVar_25842 = cppVar_25847;
	}
	cppVar_25837 = cppVar_25842;
	}
	cppVar_25832 = cppVar_25837;
	}
	cppVar_25827 = cppVar_25832;
	}
	cppVar_25822 = cppVar_25827;
	}
	cppVar_25817 = cppVar_25822;
	}
	cppVar_25812 = cppVar_25817;
	}
	cppVar_25807 = cppVar_25812;
	}
	cppVar_25802 = cppVar_25807;
	}
	cppVar_25797 = cppVar_25802;
	}
	cppVar_25792 = cppVar_25797;
	}
	cppVar_25787 = cppVar_25792;
	}
	cppVar_25782 = cppVar_25787;
	}
	cppVar_25777 = cppVar_25782;
	}
	cppVar_25768 = cppVar_25777;
	}
	cppVar_25883 = cppVar_25768 ^ ACC;
	cppVar_25762 = cppVar_25883;
	} else {
	cppVar_25762 = P0;
	}
	cppVar_25758 = cppVar_25762;
	} else {
	cppVar_25885 = ROM.rd(PC);
	cppVar_25887 = (cppVar_25885 == 83);
	if (cppVar_25887) {
	cppVar_25890 = PC + 1;
	cppVar_25890 = (cppVar_25890 & cppMask_un_16_);
	cppVar_25891 = ROM.rd(cppVar_25890);
	cppVar_25893 = (cppVar_25891 == 128);
	if (cppVar_25893) {
	cppVar_25895 = PC + 1;
	cppVar_25895 = (cppVar_25895 & cppMask_un_16_);
	cppVar_25896 = ROM.rd(cppVar_25895);
	cppVar_25897 = (cppVar_25896 >> 7) & cppMask_un_1_;
	cppVar_25899 = (cppVar_25897 == 0);
	if (cppVar_25899) {
	cppVar_25900 = PC + 1;
	cppVar_25900 = (cppVar_25900 & cppMask_un_16_);
	cppVar_25901 = ROM.rd(cppVar_25900);
	cppVar_25902 = IRAM.rd(cppVar_25901);
	cppVar_25894 = cppVar_25902;
	} else {
	cppVar_25904 = PC + 1;
	cppVar_25904 = (cppVar_25904 & cppMask_un_16_);
	cppVar_25905 = ROM.rd(cppVar_25904);
	cppVar_25907 = (cppVar_25905 == 128);
	if (cppVar_25907) {
	cppVar_25903 = P0;
	} else {
	cppVar_25909 = PC + 1;
	cppVar_25909 = (cppVar_25909 & cppMask_un_16_);
	cppVar_25910 = ROM.rd(cppVar_25909);
	cppVar_25912 = (cppVar_25910 == 129);
	if (cppVar_25912) {
	cppVar_25908 = SP;
	} else {
	cppVar_25914 = PC + 1;
	cppVar_25914 = (cppVar_25914 & cppMask_un_16_);
	cppVar_25915 = ROM.rd(cppVar_25914);
	cppVar_25917 = (cppVar_25915 == 130);
	if (cppVar_25917) {
	cppVar_25913 = DPL;
	} else {
	cppVar_25919 = PC + 1;
	cppVar_25919 = (cppVar_25919 & cppMask_un_16_);
	cppVar_25920 = ROM.rd(cppVar_25919);
	cppVar_25922 = (cppVar_25920 == 131);
	if (cppVar_25922) {
	cppVar_25918 = DPH;
	} else {
	cppVar_25924 = PC + 1;
	cppVar_25924 = (cppVar_25924 & cppMask_un_16_);
	cppVar_25925 = ROM.rd(cppVar_25924);
	cppVar_25927 = (cppVar_25925 == 135);
	if (cppVar_25927) {
	cppVar_25923 = PCON;
	} else {
	cppVar_25929 = PC + 1;
	cppVar_25929 = (cppVar_25929 & cppMask_un_16_);
	cppVar_25930 = ROM.rd(cppVar_25929);
	cppVar_25932 = (cppVar_25930 == 136);
	if (cppVar_25932) {
	cppVar_25928 = TCON;
	} else {
	cppVar_25934 = PC + 1;
	cppVar_25934 = (cppVar_25934 & cppMask_un_16_);
	cppVar_25935 = ROM.rd(cppVar_25934);
	cppVar_25937 = (cppVar_25935 == 137);
	if (cppVar_25937) {
	cppVar_25933 = TMOD;
	} else {
	cppVar_25939 = PC + 1;
	cppVar_25939 = (cppVar_25939 & cppMask_un_16_);
	cppVar_25940 = ROM.rd(cppVar_25939);
	cppVar_25942 = (cppVar_25940 == 138);
	if (cppVar_25942) {
	cppVar_25938 = TL0;
	} else {
	cppVar_25944 = PC + 1;
	cppVar_25944 = (cppVar_25944 & cppMask_un_16_);
	cppVar_25945 = ROM.rd(cppVar_25944);
	cppVar_25947 = (cppVar_25945 == 140);
	if (cppVar_25947) {
	cppVar_25943 = TH0;
	} else {
	cppVar_25949 = PC + 1;
	cppVar_25949 = (cppVar_25949 & cppMask_un_16_);
	cppVar_25950 = ROM.rd(cppVar_25949);
	cppVar_25952 = (cppVar_25950 == 139);
	if (cppVar_25952) {
	cppVar_25948 = TL1;
	} else {
	cppVar_25954 = PC + 1;
	cppVar_25954 = (cppVar_25954 & cppMask_un_16_);
	cppVar_25955 = ROM.rd(cppVar_25954);
	cppVar_25957 = (cppVar_25955 == 141);
	if (cppVar_25957) {
	cppVar_25953 = TH1;
	} else {
	cppVar_25959 = PC + 1;
	cppVar_25959 = (cppVar_25959 & cppMask_un_16_);
	cppVar_25960 = ROM.rd(cppVar_25959);
	cppVar_25962 = (cppVar_25960 == 144);
	if (cppVar_25962) {
	cppVar_25958 = P1;
	} else {
	cppVar_25964 = PC + 1;
	cppVar_25964 = (cppVar_25964 & cppMask_un_16_);
	cppVar_25965 = ROM.rd(cppVar_25964);
	cppVar_25967 = (cppVar_25965 == 152);
	if (cppVar_25967) {
	cppVar_25963 = SCON;
	} else {
	cppVar_25969 = PC + 1;
	cppVar_25969 = (cppVar_25969 & cppMask_un_16_);
	cppVar_25970 = ROM.rd(cppVar_25969);
	cppVar_25972 = (cppVar_25970 == 153);
	if (cppVar_25972) {
	cppVar_25968 = SBUF;
	} else {
	cppVar_25974 = PC + 1;
	cppVar_25974 = (cppVar_25974 & cppMask_un_16_);
	cppVar_25975 = ROM.rd(cppVar_25974);
	cppVar_25977 = (cppVar_25975 == 160);
	if (cppVar_25977) {
	cppVar_25973 = P2;
	} else {
	cppVar_25979 = PC + 1;
	cppVar_25979 = (cppVar_25979 & cppMask_un_16_);
	cppVar_25980 = ROM.rd(cppVar_25979);
	cppVar_25982 = (cppVar_25980 == 168);
	if (cppVar_25982) {
	cppVar_25978 = IE;
	} else {
	cppVar_25984 = PC + 1;
	cppVar_25984 = (cppVar_25984 & cppMask_un_16_);
	cppVar_25985 = ROM.rd(cppVar_25984);
	cppVar_25987 = (cppVar_25985 == 176);
	if (cppVar_25987) {
	cppVar_25983 = P3;
	} else {
	cppVar_25989 = PC + 1;
	cppVar_25989 = (cppVar_25989 & cppMask_un_16_);
	cppVar_25990 = ROM.rd(cppVar_25989);
	cppVar_25992 = (cppVar_25990 == 184);
	if (cppVar_25992) {
	cppVar_25988 = IP;
	} else {
	cppVar_25994 = PC + 1;
	cppVar_25994 = (cppVar_25994 & cppMask_un_16_);
	cppVar_25995 = ROM.rd(cppVar_25994);
	cppVar_25997 = (cppVar_25995 == 208);
	if (cppVar_25997) {
	cppVar_25993 = PSW;
	} else {
	cppVar_25999 = PC + 1;
	cppVar_25999 = (cppVar_25999 & cppMask_un_16_);
	cppVar_26000 = ROM.rd(cppVar_25999);
	cppVar_26002 = (cppVar_26000 == 224);
	if (cppVar_26002) {
	cppVar_25998 = ACC;
	} else {
	cppVar_26004 = PC + 1;
	cppVar_26004 = (cppVar_26004 & cppMask_un_16_);
	cppVar_26005 = ROM.rd(cppVar_26004);
	cppVar_26007 = (cppVar_26005 == 240);
	if (cppVar_26007) {
	cppVar_26003 = B;
	} else {
	cppVar_26003 = 0;
	}
	cppVar_25998 = cppVar_26003;
	}
	cppVar_25993 = cppVar_25998;
	}
	cppVar_25988 = cppVar_25993;
	}
	cppVar_25983 = cppVar_25988;
	}
	cppVar_25978 = cppVar_25983;
	}
	cppVar_25973 = cppVar_25978;
	}
	cppVar_25968 = cppVar_25973;
	}
	cppVar_25963 = cppVar_25968;
	}
	cppVar_25958 = cppVar_25963;
	}
	cppVar_25953 = cppVar_25958;
	}
	cppVar_25948 = cppVar_25953;
	}
	cppVar_25943 = cppVar_25948;
	}
	cppVar_25938 = cppVar_25943;
	}
	cppVar_25933 = cppVar_25938;
	}
	cppVar_25928 = cppVar_25933;
	}
	cppVar_25923 = cppVar_25928;
	}
	cppVar_25918 = cppVar_25923;
	}
	cppVar_25913 = cppVar_25918;
	}
	cppVar_25908 = cppVar_25913;
	}
	cppVar_25903 = cppVar_25908;
	}
	cppVar_25894 = cppVar_25903;
	}
	cppVar_26010 = PC + 2;
	cppVar_26010 = (cppVar_26010 & cppMask_un_16_);
	cppVar_26011 = ROM.rd(cppVar_26010);
	cppVar_26012 = cppVar_25894 & cppVar_26011;
	cppVar_25888 = cppVar_26012;
	} else {
	cppVar_25888 = P0;
	}
	cppVar_25884 = cppVar_25888;
	} else {
	cppVar_26014 = ROM.rd(PC);
	cppVar_26016 = (cppVar_26014 == 82);
	if (cppVar_26016) {
	cppVar_26019 = PC + 1;
	cppVar_26019 = (cppVar_26019 & cppMask_un_16_);
	cppVar_26020 = ROM.rd(cppVar_26019);
	cppVar_26022 = (cppVar_26020 == 128);
	if (cppVar_26022) {
	cppVar_26024 = PC + 1;
	cppVar_26024 = (cppVar_26024 & cppMask_un_16_);
	cppVar_26025 = ROM.rd(cppVar_26024);
	cppVar_26026 = (cppVar_26025 >> 7) & cppMask_un_1_;
	cppVar_26028 = (cppVar_26026 == 0);
	if (cppVar_26028) {
	cppVar_26029 = PC + 1;
	cppVar_26029 = (cppVar_26029 & cppMask_un_16_);
	cppVar_26030 = ROM.rd(cppVar_26029);
	cppVar_26031 = IRAM.rd(cppVar_26030);
	cppVar_26023 = cppVar_26031;
	} else {
	cppVar_26033 = PC + 1;
	cppVar_26033 = (cppVar_26033 & cppMask_un_16_);
	cppVar_26034 = ROM.rd(cppVar_26033);
	cppVar_26036 = (cppVar_26034 == 128);
	if (cppVar_26036) {
	cppVar_26032 = P0;
	} else {
	cppVar_26038 = PC + 1;
	cppVar_26038 = (cppVar_26038 & cppMask_un_16_);
	cppVar_26039 = ROM.rd(cppVar_26038);
	cppVar_26041 = (cppVar_26039 == 129);
	if (cppVar_26041) {
	cppVar_26037 = SP;
	} else {
	cppVar_26043 = PC + 1;
	cppVar_26043 = (cppVar_26043 & cppMask_un_16_);
	cppVar_26044 = ROM.rd(cppVar_26043);
	cppVar_26046 = (cppVar_26044 == 130);
	if (cppVar_26046) {
	cppVar_26042 = DPL;
	} else {
	cppVar_26048 = PC + 1;
	cppVar_26048 = (cppVar_26048 & cppMask_un_16_);
	cppVar_26049 = ROM.rd(cppVar_26048);
	cppVar_26051 = (cppVar_26049 == 131);
	if (cppVar_26051) {
	cppVar_26047 = DPH;
	} else {
	cppVar_26053 = PC + 1;
	cppVar_26053 = (cppVar_26053 & cppMask_un_16_);
	cppVar_26054 = ROM.rd(cppVar_26053);
	cppVar_26056 = (cppVar_26054 == 135);
	if (cppVar_26056) {
	cppVar_26052 = PCON;
	} else {
	cppVar_26058 = PC + 1;
	cppVar_26058 = (cppVar_26058 & cppMask_un_16_);
	cppVar_26059 = ROM.rd(cppVar_26058);
	cppVar_26061 = (cppVar_26059 == 136);
	if (cppVar_26061) {
	cppVar_26057 = TCON;
	} else {
	cppVar_26063 = PC + 1;
	cppVar_26063 = (cppVar_26063 & cppMask_un_16_);
	cppVar_26064 = ROM.rd(cppVar_26063);
	cppVar_26066 = (cppVar_26064 == 137);
	if (cppVar_26066) {
	cppVar_26062 = TMOD;
	} else {
	cppVar_26068 = PC + 1;
	cppVar_26068 = (cppVar_26068 & cppMask_un_16_);
	cppVar_26069 = ROM.rd(cppVar_26068);
	cppVar_26071 = (cppVar_26069 == 138);
	if (cppVar_26071) {
	cppVar_26067 = TL0;
	} else {
	cppVar_26073 = PC + 1;
	cppVar_26073 = (cppVar_26073 & cppMask_un_16_);
	cppVar_26074 = ROM.rd(cppVar_26073);
	cppVar_26076 = (cppVar_26074 == 140);
	if (cppVar_26076) {
	cppVar_26072 = TH0;
	} else {
	cppVar_26078 = PC + 1;
	cppVar_26078 = (cppVar_26078 & cppMask_un_16_);
	cppVar_26079 = ROM.rd(cppVar_26078);
	cppVar_26081 = (cppVar_26079 == 139);
	if (cppVar_26081) {
	cppVar_26077 = TL1;
	} else {
	cppVar_26083 = PC + 1;
	cppVar_26083 = (cppVar_26083 & cppMask_un_16_);
	cppVar_26084 = ROM.rd(cppVar_26083);
	cppVar_26086 = (cppVar_26084 == 141);
	if (cppVar_26086) {
	cppVar_26082 = TH1;
	} else {
	cppVar_26088 = PC + 1;
	cppVar_26088 = (cppVar_26088 & cppMask_un_16_);
	cppVar_26089 = ROM.rd(cppVar_26088);
	cppVar_26091 = (cppVar_26089 == 144);
	if (cppVar_26091) {
	cppVar_26087 = P1;
	} else {
	cppVar_26093 = PC + 1;
	cppVar_26093 = (cppVar_26093 & cppMask_un_16_);
	cppVar_26094 = ROM.rd(cppVar_26093);
	cppVar_26096 = (cppVar_26094 == 152);
	if (cppVar_26096) {
	cppVar_26092 = SCON;
	} else {
	cppVar_26098 = PC + 1;
	cppVar_26098 = (cppVar_26098 & cppMask_un_16_);
	cppVar_26099 = ROM.rd(cppVar_26098);
	cppVar_26101 = (cppVar_26099 == 153);
	if (cppVar_26101) {
	cppVar_26097 = SBUF;
	} else {
	cppVar_26103 = PC + 1;
	cppVar_26103 = (cppVar_26103 & cppMask_un_16_);
	cppVar_26104 = ROM.rd(cppVar_26103);
	cppVar_26106 = (cppVar_26104 == 160);
	if (cppVar_26106) {
	cppVar_26102 = P2;
	} else {
	cppVar_26108 = PC + 1;
	cppVar_26108 = (cppVar_26108 & cppMask_un_16_);
	cppVar_26109 = ROM.rd(cppVar_26108);
	cppVar_26111 = (cppVar_26109 == 168);
	if (cppVar_26111) {
	cppVar_26107 = IE;
	} else {
	cppVar_26113 = PC + 1;
	cppVar_26113 = (cppVar_26113 & cppMask_un_16_);
	cppVar_26114 = ROM.rd(cppVar_26113);
	cppVar_26116 = (cppVar_26114 == 176);
	if (cppVar_26116) {
	cppVar_26112 = P3;
	} else {
	cppVar_26118 = PC + 1;
	cppVar_26118 = (cppVar_26118 & cppMask_un_16_);
	cppVar_26119 = ROM.rd(cppVar_26118);
	cppVar_26121 = (cppVar_26119 == 184);
	if (cppVar_26121) {
	cppVar_26117 = IP;
	} else {
	cppVar_26123 = PC + 1;
	cppVar_26123 = (cppVar_26123 & cppMask_un_16_);
	cppVar_26124 = ROM.rd(cppVar_26123);
	cppVar_26126 = (cppVar_26124 == 208);
	if (cppVar_26126) {
	cppVar_26122 = PSW;
	} else {
	cppVar_26128 = PC + 1;
	cppVar_26128 = (cppVar_26128 & cppMask_un_16_);
	cppVar_26129 = ROM.rd(cppVar_26128);
	cppVar_26131 = (cppVar_26129 == 224);
	if (cppVar_26131) {
	cppVar_26127 = ACC;
	} else {
	cppVar_26133 = PC + 1;
	cppVar_26133 = (cppVar_26133 & cppMask_un_16_);
	cppVar_26134 = ROM.rd(cppVar_26133);
	cppVar_26136 = (cppVar_26134 == 240);
	if (cppVar_26136) {
	cppVar_26132 = B;
	} else {
	cppVar_26132 = 0;
	}
	cppVar_26127 = cppVar_26132;
	}
	cppVar_26122 = cppVar_26127;
	}
	cppVar_26117 = cppVar_26122;
	}
	cppVar_26112 = cppVar_26117;
	}
	cppVar_26107 = cppVar_26112;
	}
	cppVar_26102 = cppVar_26107;
	}
	cppVar_26097 = cppVar_26102;
	}
	cppVar_26092 = cppVar_26097;
	}
	cppVar_26087 = cppVar_26092;
	}
	cppVar_26082 = cppVar_26087;
	}
	cppVar_26077 = cppVar_26082;
	}
	cppVar_26072 = cppVar_26077;
	}
	cppVar_26067 = cppVar_26072;
	}
	cppVar_26062 = cppVar_26067;
	}
	cppVar_26057 = cppVar_26062;
	}
	cppVar_26052 = cppVar_26057;
	}
	cppVar_26047 = cppVar_26052;
	}
	cppVar_26042 = cppVar_26047;
	}
	cppVar_26037 = cppVar_26042;
	}
	cppVar_26032 = cppVar_26037;
	}
	cppVar_26023 = cppVar_26032;
	}
	cppVar_26138 = cppVar_26023 & ACC;
	cppVar_26017 = cppVar_26138;
	} else {
	cppVar_26017 = P0;
	}
	cppVar_26013 = cppVar_26017;
	} else {
	cppVar_26140 = ROM.rd(PC);
	cppVar_26142 = (cppVar_26140 == 67);
	if (cppVar_26142) {
	cppVar_26145 = PC + 1;
	cppVar_26145 = (cppVar_26145 & cppMask_un_16_);
	cppVar_26146 = ROM.rd(cppVar_26145);
	cppVar_26148 = (cppVar_26146 == 128);
	if (cppVar_26148) {
	cppVar_26150 = PC + 1;
	cppVar_26150 = (cppVar_26150 & cppMask_un_16_);
	cppVar_26151 = ROM.rd(cppVar_26150);
	cppVar_26152 = (cppVar_26151 >> 7) & cppMask_un_1_;
	cppVar_26154 = (cppVar_26152 == 0);
	if (cppVar_26154) {
	cppVar_26155 = PC + 1;
	cppVar_26155 = (cppVar_26155 & cppMask_un_16_);
	cppVar_26156 = ROM.rd(cppVar_26155);
	cppVar_26157 = IRAM.rd(cppVar_26156);
	cppVar_26149 = cppVar_26157;
	} else {
	cppVar_26159 = PC + 1;
	cppVar_26159 = (cppVar_26159 & cppMask_un_16_);
	cppVar_26160 = ROM.rd(cppVar_26159);
	cppVar_26162 = (cppVar_26160 == 128);
	if (cppVar_26162) {
	cppVar_26158 = P0;
	} else {
	cppVar_26164 = PC + 1;
	cppVar_26164 = (cppVar_26164 & cppMask_un_16_);
	cppVar_26165 = ROM.rd(cppVar_26164);
	cppVar_26167 = (cppVar_26165 == 129);
	if (cppVar_26167) {
	cppVar_26163 = SP;
	} else {
	cppVar_26169 = PC + 1;
	cppVar_26169 = (cppVar_26169 & cppMask_un_16_);
	cppVar_26170 = ROM.rd(cppVar_26169);
	cppVar_26172 = (cppVar_26170 == 130);
	if (cppVar_26172) {
	cppVar_26168 = DPL;
	} else {
	cppVar_26174 = PC + 1;
	cppVar_26174 = (cppVar_26174 & cppMask_un_16_);
	cppVar_26175 = ROM.rd(cppVar_26174);
	cppVar_26177 = (cppVar_26175 == 131);
	if (cppVar_26177) {
	cppVar_26173 = DPH;
	} else {
	cppVar_26179 = PC + 1;
	cppVar_26179 = (cppVar_26179 & cppMask_un_16_);
	cppVar_26180 = ROM.rd(cppVar_26179);
	cppVar_26182 = (cppVar_26180 == 135);
	if (cppVar_26182) {
	cppVar_26178 = PCON;
	} else {
	cppVar_26184 = PC + 1;
	cppVar_26184 = (cppVar_26184 & cppMask_un_16_);
	cppVar_26185 = ROM.rd(cppVar_26184);
	cppVar_26187 = (cppVar_26185 == 136);
	if (cppVar_26187) {
	cppVar_26183 = TCON;
	} else {
	cppVar_26189 = PC + 1;
	cppVar_26189 = (cppVar_26189 & cppMask_un_16_);
	cppVar_26190 = ROM.rd(cppVar_26189);
	cppVar_26192 = (cppVar_26190 == 137);
	if (cppVar_26192) {
	cppVar_26188 = TMOD;
	} else {
	cppVar_26194 = PC + 1;
	cppVar_26194 = (cppVar_26194 & cppMask_un_16_);
	cppVar_26195 = ROM.rd(cppVar_26194);
	cppVar_26197 = (cppVar_26195 == 138);
	if (cppVar_26197) {
	cppVar_26193 = TL0;
	} else {
	cppVar_26199 = PC + 1;
	cppVar_26199 = (cppVar_26199 & cppMask_un_16_);
	cppVar_26200 = ROM.rd(cppVar_26199);
	cppVar_26202 = (cppVar_26200 == 140);
	if (cppVar_26202) {
	cppVar_26198 = TH0;
	} else {
	cppVar_26204 = PC + 1;
	cppVar_26204 = (cppVar_26204 & cppMask_un_16_);
	cppVar_26205 = ROM.rd(cppVar_26204);
	cppVar_26207 = (cppVar_26205 == 139);
	if (cppVar_26207) {
	cppVar_26203 = TL1;
	} else {
	cppVar_26209 = PC + 1;
	cppVar_26209 = (cppVar_26209 & cppMask_un_16_);
	cppVar_26210 = ROM.rd(cppVar_26209);
	cppVar_26212 = (cppVar_26210 == 141);
	if (cppVar_26212) {
	cppVar_26208 = TH1;
	} else {
	cppVar_26214 = PC + 1;
	cppVar_26214 = (cppVar_26214 & cppMask_un_16_);
	cppVar_26215 = ROM.rd(cppVar_26214);
	cppVar_26217 = (cppVar_26215 == 144);
	if (cppVar_26217) {
	cppVar_26213 = P1;
	} else {
	cppVar_26219 = PC + 1;
	cppVar_26219 = (cppVar_26219 & cppMask_un_16_);
	cppVar_26220 = ROM.rd(cppVar_26219);
	cppVar_26222 = (cppVar_26220 == 152);
	if (cppVar_26222) {
	cppVar_26218 = SCON;
	} else {
	cppVar_26224 = PC + 1;
	cppVar_26224 = (cppVar_26224 & cppMask_un_16_);
	cppVar_26225 = ROM.rd(cppVar_26224);
	cppVar_26227 = (cppVar_26225 == 153);
	if (cppVar_26227) {
	cppVar_26223 = SBUF;
	} else {
	cppVar_26229 = PC + 1;
	cppVar_26229 = (cppVar_26229 & cppMask_un_16_);
	cppVar_26230 = ROM.rd(cppVar_26229);
	cppVar_26232 = (cppVar_26230 == 160);
	if (cppVar_26232) {
	cppVar_26228 = P2;
	} else {
	cppVar_26234 = PC + 1;
	cppVar_26234 = (cppVar_26234 & cppMask_un_16_);
	cppVar_26235 = ROM.rd(cppVar_26234);
	cppVar_26237 = (cppVar_26235 == 168);
	if (cppVar_26237) {
	cppVar_26233 = IE;
	} else {
	cppVar_26239 = PC + 1;
	cppVar_26239 = (cppVar_26239 & cppMask_un_16_);
	cppVar_26240 = ROM.rd(cppVar_26239);
	cppVar_26242 = (cppVar_26240 == 176);
	if (cppVar_26242) {
	cppVar_26238 = P3;
	} else {
	cppVar_26244 = PC + 1;
	cppVar_26244 = (cppVar_26244 & cppMask_un_16_);
	cppVar_26245 = ROM.rd(cppVar_26244);
	cppVar_26247 = (cppVar_26245 == 184);
	if (cppVar_26247) {
	cppVar_26243 = IP;
	} else {
	cppVar_26249 = PC + 1;
	cppVar_26249 = (cppVar_26249 & cppMask_un_16_);
	cppVar_26250 = ROM.rd(cppVar_26249);
	cppVar_26252 = (cppVar_26250 == 208);
	if (cppVar_26252) {
	cppVar_26248 = PSW;
	} else {
	cppVar_26254 = PC + 1;
	cppVar_26254 = (cppVar_26254 & cppMask_un_16_);
	cppVar_26255 = ROM.rd(cppVar_26254);
	cppVar_26257 = (cppVar_26255 == 224);
	if (cppVar_26257) {
	cppVar_26253 = ACC;
	} else {
	cppVar_26259 = PC + 1;
	cppVar_26259 = (cppVar_26259 & cppMask_un_16_);
	cppVar_26260 = ROM.rd(cppVar_26259);
	cppVar_26262 = (cppVar_26260 == 240);
	if (cppVar_26262) {
	cppVar_26258 = B;
	} else {
	cppVar_26258 = 0;
	}
	cppVar_26253 = cppVar_26258;
	}
	cppVar_26248 = cppVar_26253;
	}
	cppVar_26243 = cppVar_26248;
	}
	cppVar_26238 = cppVar_26243;
	}
	cppVar_26233 = cppVar_26238;
	}
	cppVar_26228 = cppVar_26233;
	}
	cppVar_26223 = cppVar_26228;
	}
	cppVar_26218 = cppVar_26223;
	}
	cppVar_26213 = cppVar_26218;
	}
	cppVar_26208 = cppVar_26213;
	}
	cppVar_26203 = cppVar_26208;
	}
	cppVar_26198 = cppVar_26203;
	}
	cppVar_26193 = cppVar_26198;
	}
	cppVar_26188 = cppVar_26193;
	}
	cppVar_26183 = cppVar_26188;
	}
	cppVar_26178 = cppVar_26183;
	}
	cppVar_26173 = cppVar_26178;
	}
	cppVar_26168 = cppVar_26173;
	}
	cppVar_26163 = cppVar_26168;
	}
	cppVar_26158 = cppVar_26163;
	}
	cppVar_26149 = cppVar_26158;
	}
	cppVar_26265 = PC + 2;
	cppVar_26265 = (cppVar_26265 & cppMask_un_16_);
	cppVar_26266 = ROM.rd(cppVar_26265);
	cppVar_26267 = cppVar_26149 | cppVar_26266;
	cppVar_26143 = cppVar_26267;
	} else {
	cppVar_26143 = P0;
	}
	cppVar_26139 = cppVar_26143;
	} else {
	cppVar_26269 = ROM.rd(PC);
	cppVar_26271 = (cppVar_26269 == 66);
	if (cppVar_26271) {
	cppVar_26274 = PC + 1;
	cppVar_26274 = (cppVar_26274 & cppMask_un_16_);
	cppVar_26275 = ROM.rd(cppVar_26274);
	cppVar_26277 = (cppVar_26275 == 128);
	if (cppVar_26277) {
	cppVar_26279 = PC + 1;
	cppVar_26279 = (cppVar_26279 & cppMask_un_16_);
	cppVar_26280 = ROM.rd(cppVar_26279);
	cppVar_26281 = (cppVar_26280 >> 7) & cppMask_un_1_;
	cppVar_26283 = (cppVar_26281 == 0);
	if (cppVar_26283) {
	cppVar_26284 = PC + 1;
	cppVar_26284 = (cppVar_26284 & cppMask_un_16_);
	cppVar_26285 = ROM.rd(cppVar_26284);
	cppVar_26286 = IRAM.rd(cppVar_26285);
	cppVar_26278 = cppVar_26286;
	} else {
	cppVar_26288 = PC + 1;
	cppVar_26288 = (cppVar_26288 & cppMask_un_16_);
	cppVar_26289 = ROM.rd(cppVar_26288);
	cppVar_26291 = (cppVar_26289 == 128);
	if (cppVar_26291) {
	cppVar_26287 = P0;
	} else {
	cppVar_26293 = PC + 1;
	cppVar_26293 = (cppVar_26293 & cppMask_un_16_);
	cppVar_26294 = ROM.rd(cppVar_26293);
	cppVar_26296 = (cppVar_26294 == 129);
	if (cppVar_26296) {
	cppVar_26292 = SP;
	} else {
	cppVar_26298 = PC + 1;
	cppVar_26298 = (cppVar_26298 & cppMask_un_16_);
	cppVar_26299 = ROM.rd(cppVar_26298);
	cppVar_26301 = (cppVar_26299 == 130);
	if (cppVar_26301) {
	cppVar_26297 = DPL;
	} else {
	cppVar_26303 = PC + 1;
	cppVar_26303 = (cppVar_26303 & cppMask_un_16_);
	cppVar_26304 = ROM.rd(cppVar_26303);
	cppVar_26306 = (cppVar_26304 == 131);
	if (cppVar_26306) {
	cppVar_26302 = DPH;
	} else {
	cppVar_26308 = PC + 1;
	cppVar_26308 = (cppVar_26308 & cppMask_un_16_);
	cppVar_26309 = ROM.rd(cppVar_26308);
	cppVar_26311 = (cppVar_26309 == 135);
	if (cppVar_26311) {
	cppVar_26307 = PCON;
	} else {
	cppVar_26313 = PC + 1;
	cppVar_26313 = (cppVar_26313 & cppMask_un_16_);
	cppVar_26314 = ROM.rd(cppVar_26313);
	cppVar_26316 = (cppVar_26314 == 136);
	if (cppVar_26316) {
	cppVar_26312 = TCON;
	} else {
	cppVar_26318 = PC + 1;
	cppVar_26318 = (cppVar_26318 & cppMask_un_16_);
	cppVar_26319 = ROM.rd(cppVar_26318);
	cppVar_26321 = (cppVar_26319 == 137);
	if (cppVar_26321) {
	cppVar_26317 = TMOD;
	} else {
	cppVar_26323 = PC + 1;
	cppVar_26323 = (cppVar_26323 & cppMask_un_16_);
	cppVar_26324 = ROM.rd(cppVar_26323);
	cppVar_26326 = (cppVar_26324 == 138);
	if (cppVar_26326) {
	cppVar_26322 = TL0;
	} else {
	cppVar_26328 = PC + 1;
	cppVar_26328 = (cppVar_26328 & cppMask_un_16_);
	cppVar_26329 = ROM.rd(cppVar_26328);
	cppVar_26331 = (cppVar_26329 == 140);
	if (cppVar_26331) {
	cppVar_26327 = TH0;
	} else {
	cppVar_26333 = PC + 1;
	cppVar_26333 = (cppVar_26333 & cppMask_un_16_);
	cppVar_26334 = ROM.rd(cppVar_26333);
	cppVar_26336 = (cppVar_26334 == 139);
	if (cppVar_26336) {
	cppVar_26332 = TL1;
	} else {
	cppVar_26338 = PC + 1;
	cppVar_26338 = (cppVar_26338 & cppMask_un_16_);
	cppVar_26339 = ROM.rd(cppVar_26338);
	cppVar_26341 = (cppVar_26339 == 141);
	if (cppVar_26341) {
	cppVar_26337 = TH1;
	} else {
	cppVar_26343 = PC + 1;
	cppVar_26343 = (cppVar_26343 & cppMask_un_16_);
	cppVar_26344 = ROM.rd(cppVar_26343);
	cppVar_26346 = (cppVar_26344 == 144);
	if (cppVar_26346) {
	cppVar_26342 = P1;
	} else {
	cppVar_26348 = PC + 1;
	cppVar_26348 = (cppVar_26348 & cppMask_un_16_);
	cppVar_26349 = ROM.rd(cppVar_26348);
	cppVar_26351 = (cppVar_26349 == 152);
	if (cppVar_26351) {
	cppVar_26347 = SCON;
	} else {
	cppVar_26353 = PC + 1;
	cppVar_26353 = (cppVar_26353 & cppMask_un_16_);
	cppVar_26354 = ROM.rd(cppVar_26353);
	cppVar_26356 = (cppVar_26354 == 153);
	if (cppVar_26356) {
	cppVar_26352 = SBUF;
	} else {
	cppVar_26358 = PC + 1;
	cppVar_26358 = (cppVar_26358 & cppMask_un_16_);
	cppVar_26359 = ROM.rd(cppVar_26358);
	cppVar_26361 = (cppVar_26359 == 160);
	if (cppVar_26361) {
	cppVar_26357 = P2;
	} else {
	cppVar_26363 = PC + 1;
	cppVar_26363 = (cppVar_26363 & cppMask_un_16_);
	cppVar_26364 = ROM.rd(cppVar_26363);
	cppVar_26366 = (cppVar_26364 == 168);
	if (cppVar_26366) {
	cppVar_26362 = IE;
	} else {
	cppVar_26368 = PC + 1;
	cppVar_26368 = (cppVar_26368 & cppMask_un_16_);
	cppVar_26369 = ROM.rd(cppVar_26368);
	cppVar_26371 = (cppVar_26369 == 176);
	if (cppVar_26371) {
	cppVar_26367 = P3;
	} else {
	cppVar_26373 = PC + 1;
	cppVar_26373 = (cppVar_26373 & cppMask_un_16_);
	cppVar_26374 = ROM.rd(cppVar_26373);
	cppVar_26376 = (cppVar_26374 == 184);
	if (cppVar_26376) {
	cppVar_26372 = IP;
	} else {
	cppVar_26378 = PC + 1;
	cppVar_26378 = (cppVar_26378 & cppMask_un_16_);
	cppVar_26379 = ROM.rd(cppVar_26378);
	cppVar_26381 = (cppVar_26379 == 208);
	if (cppVar_26381) {
	cppVar_26377 = PSW;
	} else {
	cppVar_26383 = PC + 1;
	cppVar_26383 = (cppVar_26383 & cppMask_un_16_);
	cppVar_26384 = ROM.rd(cppVar_26383);
	cppVar_26386 = (cppVar_26384 == 224);
	if (cppVar_26386) {
	cppVar_26382 = ACC;
	} else {
	cppVar_26388 = PC + 1;
	cppVar_26388 = (cppVar_26388 & cppMask_un_16_);
	cppVar_26389 = ROM.rd(cppVar_26388);
	cppVar_26391 = (cppVar_26389 == 240);
	if (cppVar_26391) {
	cppVar_26387 = B;
	} else {
	cppVar_26387 = 0;
	}
	cppVar_26382 = cppVar_26387;
	}
	cppVar_26377 = cppVar_26382;
	}
	cppVar_26372 = cppVar_26377;
	}
	cppVar_26367 = cppVar_26372;
	}
	cppVar_26362 = cppVar_26367;
	}
	cppVar_26357 = cppVar_26362;
	}
	cppVar_26352 = cppVar_26357;
	}
	cppVar_26347 = cppVar_26352;
	}
	cppVar_26342 = cppVar_26347;
	}
	cppVar_26337 = cppVar_26342;
	}
	cppVar_26332 = cppVar_26337;
	}
	cppVar_26327 = cppVar_26332;
	}
	cppVar_26322 = cppVar_26327;
	}
	cppVar_26317 = cppVar_26322;
	}
	cppVar_26312 = cppVar_26317;
	}
	cppVar_26307 = cppVar_26312;
	}
	cppVar_26302 = cppVar_26307;
	}
	cppVar_26297 = cppVar_26302;
	}
	cppVar_26292 = cppVar_26297;
	}
	cppVar_26287 = cppVar_26292;
	}
	cppVar_26278 = cppVar_26287;
	}
	cppVar_26393 = cppVar_26278 | ACC;
	cppVar_26272 = cppVar_26393;
	} else {
	cppVar_26272 = P0;
	}
	cppVar_26268 = cppVar_26272;
	} else {
	cppVar_26395 = ROM.rd(PC);
	cppVar_26397 = (cppVar_26395 == 213);
	cppVar_26398 = ROM.rd(PC);
	cppVar_26400 = (cppVar_26398 == 21);
	cppVar_26401 = cppVar_26397 || cppVar_26400;
	if (cppVar_26401) {
	cppVar_26404 = PC + 1;
	cppVar_26404 = (cppVar_26404 & cppMask_un_16_);
	cppVar_26405 = ROM.rd(cppVar_26404);
	cppVar_26407 = (cppVar_26405 == 128);
	if (cppVar_26407) {
	cppVar_26409 = PC + 1;
	cppVar_26409 = (cppVar_26409 & cppMask_un_16_);
	cppVar_26410 = ROM.rd(cppVar_26409);
	cppVar_26411 = (cppVar_26410 >> 7) & cppMask_un_1_;
	cppVar_26413 = (cppVar_26411 == 0);
	if (cppVar_26413) {
	cppVar_26414 = PC + 1;
	cppVar_26414 = (cppVar_26414 & cppMask_un_16_);
	cppVar_26415 = ROM.rd(cppVar_26414);
	cppVar_26416 = IRAM.rd(cppVar_26415);
	cppVar_26408 = cppVar_26416;
	} else {
	cppVar_26418 = PC + 1;
	cppVar_26418 = (cppVar_26418 & cppMask_un_16_);
	cppVar_26419 = ROM.rd(cppVar_26418);
	cppVar_26421 = (cppVar_26419 == 128);
	if (cppVar_26421) {
	cppVar_26417 = P0;
	} else {
	cppVar_26423 = PC + 1;
	cppVar_26423 = (cppVar_26423 & cppMask_un_16_);
	cppVar_26424 = ROM.rd(cppVar_26423);
	cppVar_26426 = (cppVar_26424 == 129);
	if (cppVar_26426) {
	cppVar_26422 = SP;
	} else {
	cppVar_26428 = PC + 1;
	cppVar_26428 = (cppVar_26428 & cppMask_un_16_);
	cppVar_26429 = ROM.rd(cppVar_26428);
	cppVar_26431 = (cppVar_26429 == 130);
	if (cppVar_26431) {
	cppVar_26427 = DPL;
	} else {
	cppVar_26433 = PC + 1;
	cppVar_26433 = (cppVar_26433 & cppMask_un_16_);
	cppVar_26434 = ROM.rd(cppVar_26433);
	cppVar_26436 = (cppVar_26434 == 131);
	if (cppVar_26436) {
	cppVar_26432 = DPH;
	} else {
	cppVar_26438 = PC + 1;
	cppVar_26438 = (cppVar_26438 & cppMask_un_16_);
	cppVar_26439 = ROM.rd(cppVar_26438);
	cppVar_26441 = (cppVar_26439 == 135);
	if (cppVar_26441) {
	cppVar_26437 = PCON;
	} else {
	cppVar_26443 = PC + 1;
	cppVar_26443 = (cppVar_26443 & cppMask_un_16_);
	cppVar_26444 = ROM.rd(cppVar_26443);
	cppVar_26446 = (cppVar_26444 == 136);
	if (cppVar_26446) {
	cppVar_26442 = TCON;
	} else {
	cppVar_26448 = PC + 1;
	cppVar_26448 = (cppVar_26448 & cppMask_un_16_);
	cppVar_26449 = ROM.rd(cppVar_26448);
	cppVar_26451 = (cppVar_26449 == 137);
	if (cppVar_26451) {
	cppVar_26447 = TMOD;
	} else {
	cppVar_26453 = PC + 1;
	cppVar_26453 = (cppVar_26453 & cppMask_un_16_);
	cppVar_26454 = ROM.rd(cppVar_26453);
	cppVar_26456 = (cppVar_26454 == 138);
	if (cppVar_26456) {
	cppVar_26452 = TL0;
	} else {
	cppVar_26458 = PC + 1;
	cppVar_26458 = (cppVar_26458 & cppMask_un_16_);
	cppVar_26459 = ROM.rd(cppVar_26458);
	cppVar_26461 = (cppVar_26459 == 140);
	if (cppVar_26461) {
	cppVar_26457 = TH0;
	} else {
	cppVar_26463 = PC + 1;
	cppVar_26463 = (cppVar_26463 & cppMask_un_16_);
	cppVar_26464 = ROM.rd(cppVar_26463);
	cppVar_26466 = (cppVar_26464 == 139);
	if (cppVar_26466) {
	cppVar_26462 = TL1;
	} else {
	cppVar_26468 = PC + 1;
	cppVar_26468 = (cppVar_26468 & cppMask_un_16_);
	cppVar_26469 = ROM.rd(cppVar_26468);
	cppVar_26471 = (cppVar_26469 == 141);
	if (cppVar_26471) {
	cppVar_26467 = TH1;
	} else {
	cppVar_26473 = PC + 1;
	cppVar_26473 = (cppVar_26473 & cppMask_un_16_);
	cppVar_26474 = ROM.rd(cppVar_26473);
	cppVar_26476 = (cppVar_26474 == 144);
	if (cppVar_26476) {
	cppVar_26472 = P1;
	} else {
	cppVar_26478 = PC + 1;
	cppVar_26478 = (cppVar_26478 & cppMask_un_16_);
	cppVar_26479 = ROM.rd(cppVar_26478);
	cppVar_26481 = (cppVar_26479 == 152);
	if (cppVar_26481) {
	cppVar_26477 = SCON;
	} else {
	cppVar_26483 = PC + 1;
	cppVar_26483 = (cppVar_26483 & cppMask_un_16_);
	cppVar_26484 = ROM.rd(cppVar_26483);
	cppVar_26486 = (cppVar_26484 == 153);
	if (cppVar_26486) {
	cppVar_26482 = SBUF;
	} else {
	cppVar_26488 = PC + 1;
	cppVar_26488 = (cppVar_26488 & cppMask_un_16_);
	cppVar_26489 = ROM.rd(cppVar_26488);
	cppVar_26491 = (cppVar_26489 == 160);
	if (cppVar_26491) {
	cppVar_26487 = P2;
	} else {
	cppVar_26493 = PC + 1;
	cppVar_26493 = (cppVar_26493 & cppMask_un_16_);
	cppVar_26494 = ROM.rd(cppVar_26493);
	cppVar_26496 = (cppVar_26494 == 168);
	if (cppVar_26496) {
	cppVar_26492 = IE;
	} else {
	cppVar_26498 = PC + 1;
	cppVar_26498 = (cppVar_26498 & cppMask_un_16_);
	cppVar_26499 = ROM.rd(cppVar_26498);
	cppVar_26501 = (cppVar_26499 == 176);
	if (cppVar_26501) {
	cppVar_26497 = P3;
	} else {
	cppVar_26503 = PC + 1;
	cppVar_26503 = (cppVar_26503 & cppMask_un_16_);
	cppVar_26504 = ROM.rd(cppVar_26503);
	cppVar_26506 = (cppVar_26504 == 184);
	if (cppVar_26506) {
	cppVar_26502 = IP;
	} else {
	cppVar_26508 = PC + 1;
	cppVar_26508 = (cppVar_26508 & cppMask_un_16_);
	cppVar_26509 = ROM.rd(cppVar_26508);
	cppVar_26511 = (cppVar_26509 == 208);
	if (cppVar_26511) {
	cppVar_26507 = PSW;
	} else {
	cppVar_26513 = PC + 1;
	cppVar_26513 = (cppVar_26513 & cppMask_un_16_);
	cppVar_26514 = ROM.rd(cppVar_26513);
	cppVar_26516 = (cppVar_26514 == 224);
	if (cppVar_26516) {
	cppVar_26512 = ACC;
	} else {
	cppVar_26518 = PC + 1;
	cppVar_26518 = (cppVar_26518 & cppMask_un_16_);
	cppVar_26519 = ROM.rd(cppVar_26518);
	cppVar_26521 = (cppVar_26519 == 240);
	if (cppVar_26521) {
	cppVar_26517 = B;
	} else {
	cppVar_26517 = 0;
	}
	cppVar_26512 = cppVar_26517;
	}
	cppVar_26507 = cppVar_26512;
	}
	cppVar_26502 = cppVar_26507;
	}
	cppVar_26497 = cppVar_26502;
	}
	cppVar_26492 = cppVar_26497;
	}
	cppVar_26487 = cppVar_26492;
	}
	cppVar_26482 = cppVar_26487;
	}
	cppVar_26477 = cppVar_26482;
	}
	cppVar_26472 = cppVar_26477;
	}
	cppVar_26467 = cppVar_26472;
	}
	cppVar_26462 = cppVar_26467;
	}
	cppVar_26457 = cppVar_26462;
	}
	cppVar_26452 = cppVar_26457;
	}
	cppVar_26447 = cppVar_26452;
	}
	cppVar_26442 = cppVar_26447;
	}
	cppVar_26437 = cppVar_26442;
	}
	cppVar_26432 = cppVar_26437;
	}
	cppVar_26427 = cppVar_26432;
	}
	cppVar_26422 = cppVar_26427;
	}
	cppVar_26417 = cppVar_26422;
	}
	cppVar_26408 = cppVar_26417;
	}
	cppVar_26524 = cppVar_26408 - 1;
	cppVar_26524 = (cppVar_26524 & cppMask_un_8_);
	cppVar_26402 = cppVar_26524;
	} else {
	cppVar_26402 = P0;
	}
	cppVar_26394 = cppVar_26402;
	} else {
	cppVar_26526 = ROM.rd(PC);
	cppVar_26528 = (cppVar_26526 == 194);
	cppVar_26529 = ROM.rd(PC);
	cppVar_26531 = (cppVar_26529 == 16);
	cppVar_26532 = cppVar_26528 || cppVar_26531;
	if (cppVar_26532) {
	cppVar_26536 = PC + 1;
	cppVar_26536 = (cppVar_26536 & cppMask_un_16_);
	cppVar_26537 = ROM.rd(cppVar_26536);
	cppVar_26538 = (cppVar_26537 >> 7) & cppMask_un_1_;
	cppVar_26540 = (cppVar_26538 == 1);
	if (cppVar_26540) {
	cppVar_26541 = PC + 1;
	cppVar_26541 = (cppVar_26541 & cppMask_un_16_);
	cppVar_26542 = ROM.rd(cppVar_26541);
	cppVar_26543 = (cppVar_26542 >> 3) & cppMask_un_5_;
	cppVar_26545 = (cppVar_26543 << 3) | 0;
	cppVar_26545 = (cppVar_26545 & cppMask_un_8_);
	cppVar_26534 = cppVar_26545;
	} else {
	cppVar_26546 = PC + 1;
	cppVar_26546 = (cppVar_26546 & cppMask_un_16_);
	cppVar_26547 = ROM.rd(cppVar_26546);
	cppVar_26548 = (cppVar_26547 >> 3) & cppMask_un_5_;
	cppVar_26549 = (cppVar_26548 & cppMask_un_5_);
	cppVar_26551 = cppVar_26549 + 32;
	cppVar_26551 = (cppVar_26551 & cppMask_un_8_);
	cppVar_26534 = cppVar_26551;
	}
	cppVar_26553 = (cppVar_26534 == 128);
	if (cppVar_26553) {
	cppVar_26555 = PC + 1;
	cppVar_26555 = (cppVar_26555 & cppMask_un_16_);
	cppVar_26556 = ROM.rd(cppVar_26555);
	cppVar_26557 = (cppVar_26556 >> 0) & cppMask_un_3_;
	cppVar_26558 = (cppVar_26557 & cppMask_un_3_);
	cppVar_26559 = 1 << static_cast<unsigned>(cppVar_26558);
	cppVar_26559 = (cppVar_26559 & cppMask_un_8_);
	cppVar_26560 = ~cppVar_26559;
	cppVar_26563 = PC + 1;
	cppVar_26563 = (cppVar_26563 & cppMask_un_16_);
	cppVar_26564 = ROM.rd(cppVar_26563);
	cppVar_26565 = (cppVar_26564 >> 7) & cppMask_un_1_;
	cppVar_26566 = (cppVar_26565 == 1);
	if (cppVar_26566) {
	cppVar_26567 = PC + 1;
	cppVar_26567 = (cppVar_26567 & cppMask_un_16_);
	cppVar_26568 = ROM.rd(cppVar_26567);
	cppVar_26569 = (cppVar_26568 >> 3) & cppMask_un_5_;
	cppVar_26570 = (cppVar_26569 << 3) | 0;
	cppVar_26570 = (cppVar_26570 & cppMask_un_8_);
	cppVar_26562 = cppVar_26570;
	} else {
	cppVar_26571 = PC + 1;
	cppVar_26571 = (cppVar_26571 & cppMask_un_16_);
	cppVar_26572 = ROM.rd(cppVar_26571);
	cppVar_26573 = (cppVar_26572 >> 3) & cppMask_un_5_;
	cppVar_26574 = (cppVar_26573 & cppMask_un_5_);
	cppVar_26575 = cppVar_26574 + 32;
	cppVar_26575 = (cppVar_26575 & cppMask_un_8_);
	cppVar_26562 = cppVar_26575;
	}
	cppVar_26576 = (cppVar_26562 >> 7) & cppMask_un_1_;
	cppVar_26578 = (cppVar_26576 == 0);
	if (cppVar_26578) {
	cppVar_26580 = PC + 1;
	cppVar_26580 = (cppVar_26580 & cppMask_un_16_);
	cppVar_26581 = ROM.rd(cppVar_26580);
	cppVar_26582 = (cppVar_26581 >> 7) & cppMask_un_1_;
	cppVar_26583 = (cppVar_26582 == 1);
	if (cppVar_26583) {
	cppVar_26584 = PC + 1;
	cppVar_26584 = (cppVar_26584 & cppMask_un_16_);
	cppVar_26585 = ROM.rd(cppVar_26584);
	cppVar_26586 = (cppVar_26585 >> 3) & cppMask_un_5_;
	cppVar_26587 = (cppVar_26586 << 3) | 0;
	cppVar_26587 = (cppVar_26587 & cppMask_un_8_);
	cppVar_26579 = cppVar_26587;
	} else {
	cppVar_26588 = PC + 1;
	cppVar_26588 = (cppVar_26588 & cppMask_un_16_);
	cppVar_26589 = ROM.rd(cppVar_26588);
	cppVar_26590 = (cppVar_26589 >> 3) & cppMask_un_5_;
	cppVar_26591 = (cppVar_26590 & cppMask_un_5_);
	cppVar_26592 = cppVar_26591 + 32;
	cppVar_26592 = (cppVar_26592 & cppMask_un_8_);
	cppVar_26579 = cppVar_26592;
	}
	cppVar_26593 = IRAM.rd(cppVar_26579);
	cppVar_26561 = cppVar_26593;
	} else {
	cppVar_26596 = PC + 1;
	cppVar_26596 = (cppVar_26596 & cppMask_un_16_);
	cppVar_26597 = ROM.rd(cppVar_26596);
	cppVar_26598 = (cppVar_26597 >> 7) & cppMask_un_1_;
	cppVar_26599 = (cppVar_26598 == 1);
	if (cppVar_26599) {
	cppVar_26600 = PC + 1;
	cppVar_26600 = (cppVar_26600 & cppMask_un_16_);
	cppVar_26601 = ROM.rd(cppVar_26600);
	cppVar_26602 = (cppVar_26601 >> 3) & cppMask_un_5_;
	cppVar_26603 = (cppVar_26602 << 3) | 0;
	cppVar_26603 = (cppVar_26603 & cppMask_un_8_);
	cppVar_26595 = cppVar_26603;
	} else {
	cppVar_26604 = PC + 1;
	cppVar_26604 = (cppVar_26604 & cppMask_un_16_);
	cppVar_26605 = ROM.rd(cppVar_26604);
	cppVar_26606 = (cppVar_26605 >> 3) & cppMask_un_5_;
	cppVar_26607 = (cppVar_26606 & cppMask_un_5_);
	cppVar_26608 = cppVar_26607 + 32;
	cppVar_26608 = (cppVar_26608 & cppMask_un_8_);
	cppVar_26595 = cppVar_26608;
	}
	cppVar_26610 = (cppVar_26595 == 128);
	if (cppVar_26610) {
	cppVar_26594 = P0;
	} else {
	cppVar_26613 = PC + 1;
	cppVar_26613 = (cppVar_26613 & cppMask_un_16_);
	cppVar_26614 = ROM.rd(cppVar_26613);
	cppVar_26615 = (cppVar_26614 >> 7) & cppMask_un_1_;
	cppVar_26616 = (cppVar_26615 == 1);
	if (cppVar_26616) {
	cppVar_26617 = PC + 1;
	cppVar_26617 = (cppVar_26617 & cppMask_un_16_);
	cppVar_26618 = ROM.rd(cppVar_26617);
	cppVar_26619 = (cppVar_26618 >> 3) & cppMask_un_5_;
	cppVar_26620 = (cppVar_26619 << 3) | 0;
	cppVar_26620 = (cppVar_26620 & cppMask_un_8_);
	cppVar_26612 = cppVar_26620;
	} else {
	cppVar_26621 = PC + 1;
	cppVar_26621 = (cppVar_26621 & cppMask_un_16_);
	cppVar_26622 = ROM.rd(cppVar_26621);
	cppVar_26623 = (cppVar_26622 >> 3) & cppMask_un_5_;
	cppVar_26624 = (cppVar_26623 & cppMask_un_5_);
	cppVar_26625 = cppVar_26624 + 32;
	cppVar_26625 = (cppVar_26625 & cppMask_un_8_);
	cppVar_26612 = cppVar_26625;
	}
	cppVar_26627 = (cppVar_26612 == 129);
	if (cppVar_26627) {
	cppVar_26611 = SP;
	} else {
	cppVar_26630 = PC + 1;
	cppVar_26630 = (cppVar_26630 & cppMask_un_16_);
	cppVar_26631 = ROM.rd(cppVar_26630);
	cppVar_26632 = (cppVar_26631 >> 7) & cppMask_un_1_;
	cppVar_26633 = (cppVar_26632 == 1);
	if (cppVar_26633) {
	cppVar_26634 = PC + 1;
	cppVar_26634 = (cppVar_26634 & cppMask_un_16_);
	cppVar_26635 = ROM.rd(cppVar_26634);
	cppVar_26636 = (cppVar_26635 >> 3) & cppMask_un_5_;
	cppVar_26637 = (cppVar_26636 << 3) | 0;
	cppVar_26637 = (cppVar_26637 & cppMask_un_8_);
	cppVar_26629 = cppVar_26637;
	} else {
	cppVar_26638 = PC + 1;
	cppVar_26638 = (cppVar_26638 & cppMask_un_16_);
	cppVar_26639 = ROM.rd(cppVar_26638);
	cppVar_26640 = (cppVar_26639 >> 3) & cppMask_un_5_;
	cppVar_26641 = (cppVar_26640 & cppMask_un_5_);
	cppVar_26642 = cppVar_26641 + 32;
	cppVar_26642 = (cppVar_26642 & cppMask_un_8_);
	cppVar_26629 = cppVar_26642;
	}
	cppVar_26644 = (cppVar_26629 == 130);
	if (cppVar_26644) {
	cppVar_26628 = DPL;
	} else {
	cppVar_26647 = PC + 1;
	cppVar_26647 = (cppVar_26647 & cppMask_un_16_);
	cppVar_26648 = ROM.rd(cppVar_26647);
	cppVar_26649 = (cppVar_26648 >> 7) & cppMask_un_1_;
	cppVar_26650 = (cppVar_26649 == 1);
	if (cppVar_26650) {
	cppVar_26651 = PC + 1;
	cppVar_26651 = (cppVar_26651 & cppMask_un_16_);
	cppVar_26652 = ROM.rd(cppVar_26651);
	cppVar_26653 = (cppVar_26652 >> 3) & cppMask_un_5_;
	cppVar_26654 = (cppVar_26653 << 3) | 0;
	cppVar_26654 = (cppVar_26654 & cppMask_un_8_);
	cppVar_26646 = cppVar_26654;
	} else {
	cppVar_26655 = PC + 1;
	cppVar_26655 = (cppVar_26655 & cppMask_un_16_);
	cppVar_26656 = ROM.rd(cppVar_26655);
	cppVar_26657 = (cppVar_26656 >> 3) & cppMask_un_5_;
	cppVar_26658 = (cppVar_26657 & cppMask_un_5_);
	cppVar_26659 = cppVar_26658 + 32;
	cppVar_26659 = (cppVar_26659 & cppMask_un_8_);
	cppVar_26646 = cppVar_26659;
	}
	cppVar_26661 = (cppVar_26646 == 131);
	if (cppVar_26661) {
	cppVar_26645 = DPH;
	} else {
	cppVar_26664 = PC + 1;
	cppVar_26664 = (cppVar_26664 & cppMask_un_16_);
	cppVar_26665 = ROM.rd(cppVar_26664);
	cppVar_26666 = (cppVar_26665 >> 7) & cppMask_un_1_;
	cppVar_26667 = (cppVar_26666 == 1);
	if (cppVar_26667) {
	cppVar_26668 = PC + 1;
	cppVar_26668 = (cppVar_26668 & cppMask_un_16_);
	cppVar_26669 = ROM.rd(cppVar_26668);
	cppVar_26670 = (cppVar_26669 >> 3) & cppMask_un_5_;
	cppVar_26671 = (cppVar_26670 << 3) | 0;
	cppVar_26671 = (cppVar_26671 & cppMask_un_8_);
	cppVar_26663 = cppVar_26671;
	} else {
	cppVar_26672 = PC + 1;
	cppVar_26672 = (cppVar_26672 & cppMask_un_16_);
	cppVar_26673 = ROM.rd(cppVar_26672);
	cppVar_26674 = (cppVar_26673 >> 3) & cppMask_un_5_;
	cppVar_26675 = (cppVar_26674 & cppMask_un_5_);
	cppVar_26676 = cppVar_26675 + 32;
	cppVar_26676 = (cppVar_26676 & cppMask_un_8_);
	cppVar_26663 = cppVar_26676;
	}
	cppVar_26678 = (cppVar_26663 == 135);
	if (cppVar_26678) {
	cppVar_26662 = PCON;
	} else {
	cppVar_26681 = PC + 1;
	cppVar_26681 = (cppVar_26681 & cppMask_un_16_);
	cppVar_26682 = ROM.rd(cppVar_26681);
	cppVar_26683 = (cppVar_26682 >> 7) & cppMask_un_1_;
	cppVar_26684 = (cppVar_26683 == 1);
	if (cppVar_26684) {
	cppVar_26685 = PC + 1;
	cppVar_26685 = (cppVar_26685 & cppMask_un_16_);
	cppVar_26686 = ROM.rd(cppVar_26685);
	cppVar_26687 = (cppVar_26686 >> 3) & cppMask_un_5_;
	cppVar_26688 = (cppVar_26687 << 3) | 0;
	cppVar_26688 = (cppVar_26688 & cppMask_un_8_);
	cppVar_26680 = cppVar_26688;
	} else {
	cppVar_26689 = PC + 1;
	cppVar_26689 = (cppVar_26689 & cppMask_un_16_);
	cppVar_26690 = ROM.rd(cppVar_26689);
	cppVar_26691 = (cppVar_26690 >> 3) & cppMask_un_5_;
	cppVar_26692 = (cppVar_26691 & cppMask_un_5_);
	cppVar_26693 = cppVar_26692 + 32;
	cppVar_26693 = (cppVar_26693 & cppMask_un_8_);
	cppVar_26680 = cppVar_26693;
	}
	cppVar_26695 = (cppVar_26680 == 136);
	if (cppVar_26695) {
	cppVar_26679 = TCON;
	} else {
	cppVar_26698 = PC + 1;
	cppVar_26698 = (cppVar_26698 & cppMask_un_16_);
	cppVar_26699 = ROM.rd(cppVar_26698);
	cppVar_26700 = (cppVar_26699 >> 7) & cppMask_un_1_;
	cppVar_26701 = (cppVar_26700 == 1);
	if (cppVar_26701) {
	cppVar_26702 = PC + 1;
	cppVar_26702 = (cppVar_26702 & cppMask_un_16_);
	cppVar_26703 = ROM.rd(cppVar_26702);
	cppVar_26704 = (cppVar_26703 >> 3) & cppMask_un_5_;
	cppVar_26705 = (cppVar_26704 << 3) | 0;
	cppVar_26705 = (cppVar_26705 & cppMask_un_8_);
	cppVar_26697 = cppVar_26705;
	} else {
	cppVar_26706 = PC + 1;
	cppVar_26706 = (cppVar_26706 & cppMask_un_16_);
	cppVar_26707 = ROM.rd(cppVar_26706);
	cppVar_26708 = (cppVar_26707 >> 3) & cppMask_un_5_;
	cppVar_26709 = (cppVar_26708 & cppMask_un_5_);
	cppVar_26710 = cppVar_26709 + 32;
	cppVar_26710 = (cppVar_26710 & cppMask_un_8_);
	cppVar_26697 = cppVar_26710;
	}
	cppVar_26712 = (cppVar_26697 == 137);
	if (cppVar_26712) {
	cppVar_26696 = TMOD;
	} else {
	cppVar_26715 = PC + 1;
	cppVar_26715 = (cppVar_26715 & cppMask_un_16_);
	cppVar_26716 = ROM.rd(cppVar_26715);
	cppVar_26717 = (cppVar_26716 >> 7) & cppMask_un_1_;
	cppVar_26718 = (cppVar_26717 == 1);
	if (cppVar_26718) {
	cppVar_26719 = PC + 1;
	cppVar_26719 = (cppVar_26719 & cppMask_un_16_);
	cppVar_26720 = ROM.rd(cppVar_26719);
	cppVar_26721 = (cppVar_26720 >> 3) & cppMask_un_5_;
	cppVar_26722 = (cppVar_26721 << 3) | 0;
	cppVar_26722 = (cppVar_26722 & cppMask_un_8_);
	cppVar_26714 = cppVar_26722;
	} else {
	cppVar_26723 = PC + 1;
	cppVar_26723 = (cppVar_26723 & cppMask_un_16_);
	cppVar_26724 = ROM.rd(cppVar_26723);
	cppVar_26725 = (cppVar_26724 >> 3) & cppMask_un_5_;
	cppVar_26726 = (cppVar_26725 & cppMask_un_5_);
	cppVar_26727 = cppVar_26726 + 32;
	cppVar_26727 = (cppVar_26727 & cppMask_un_8_);
	cppVar_26714 = cppVar_26727;
	}
	cppVar_26729 = (cppVar_26714 == 138);
	if (cppVar_26729) {
	cppVar_26713 = TL0;
	} else {
	cppVar_26732 = PC + 1;
	cppVar_26732 = (cppVar_26732 & cppMask_un_16_);
	cppVar_26733 = ROM.rd(cppVar_26732);
	cppVar_26734 = (cppVar_26733 >> 7) & cppMask_un_1_;
	cppVar_26735 = (cppVar_26734 == 1);
	if (cppVar_26735) {
	cppVar_26736 = PC + 1;
	cppVar_26736 = (cppVar_26736 & cppMask_un_16_);
	cppVar_26737 = ROM.rd(cppVar_26736);
	cppVar_26738 = (cppVar_26737 >> 3) & cppMask_un_5_;
	cppVar_26739 = (cppVar_26738 << 3) | 0;
	cppVar_26739 = (cppVar_26739 & cppMask_un_8_);
	cppVar_26731 = cppVar_26739;
	} else {
	cppVar_26740 = PC + 1;
	cppVar_26740 = (cppVar_26740 & cppMask_un_16_);
	cppVar_26741 = ROM.rd(cppVar_26740);
	cppVar_26742 = (cppVar_26741 >> 3) & cppMask_un_5_;
	cppVar_26743 = (cppVar_26742 & cppMask_un_5_);
	cppVar_26744 = cppVar_26743 + 32;
	cppVar_26744 = (cppVar_26744 & cppMask_un_8_);
	cppVar_26731 = cppVar_26744;
	}
	cppVar_26746 = (cppVar_26731 == 140);
	if (cppVar_26746) {
	cppVar_26730 = TH0;
	} else {
	cppVar_26749 = PC + 1;
	cppVar_26749 = (cppVar_26749 & cppMask_un_16_);
	cppVar_26750 = ROM.rd(cppVar_26749);
	cppVar_26751 = (cppVar_26750 >> 7) & cppMask_un_1_;
	cppVar_26752 = (cppVar_26751 == 1);
	if (cppVar_26752) {
	cppVar_26753 = PC + 1;
	cppVar_26753 = (cppVar_26753 & cppMask_un_16_);
	cppVar_26754 = ROM.rd(cppVar_26753);
	cppVar_26755 = (cppVar_26754 >> 3) & cppMask_un_5_;
	cppVar_26756 = (cppVar_26755 << 3) | 0;
	cppVar_26756 = (cppVar_26756 & cppMask_un_8_);
	cppVar_26748 = cppVar_26756;
	} else {
	cppVar_26757 = PC + 1;
	cppVar_26757 = (cppVar_26757 & cppMask_un_16_);
	cppVar_26758 = ROM.rd(cppVar_26757);
	cppVar_26759 = (cppVar_26758 >> 3) & cppMask_un_5_;
	cppVar_26760 = (cppVar_26759 & cppMask_un_5_);
	cppVar_26761 = cppVar_26760 + 32;
	cppVar_26761 = (cppVar_26761 & cppMask_un_8_);
	cppVar_26748 = cppVar_26761;
	}
	cppVar_26763 = (cppVar_26748 == 139);
	if (cppVar_26763) {
	cppVar_26747 = TL1;
	} else {
	cppVar_26766 = PC + 1;
	cppVar_26766 = (cppVar_26766 & cppMask_un_16_);
	cppVar_26767 = ROM.rd(cppVar_26766);
	cppVar_26768 = (cppVar_26767 >> 7) & cppMask_un_1_;
	cppVar_26769 = (cppVar_26768 == 1);
	if (cppVar_26769) {
	cppVar_26770 = PC + 1;
	cppVar_26770 = (cppVar_26770 & cppMask_un_16_);
	cppVar_26771 = ROM.rd(cppVar_26770);
	cppVar_26772 = (cppVar_26771 >> 3) & cppMask_un_5_;
	cppVar_26773 = (cppVar_26772 << 3) | 0;
	cppVar_26773 = (cppVar_26773 & cppMask_un_8_);
	cppVar_26765 = cppVar_26773;
	} else {
	cppVar_26774 = PC + 1;
	cppVar_26774 = (cppVar_26774 & cppMask_un_16_);
	cppVar_26775 = ROM.rd(cppVar_26774);
	cppVar_26776 = (cppVar_26775 >> 3) & cppMask_un_5_;
	cppVar_26777 = (cppVar_26776 & cppMask_un_5_);
	cppVar_26778 = cppVar_26777 + 32;
	cppVar_26778 = (cppVar_26778 & cppMask_un_8_);
	cppVar_26765 = cppVar_26778;
	}
	cppVar_26780 = (cppVar_26765 == 141);
	if (cppVar_26780) {
	cppVar_26764 = TH1;
	} else {
	cppVar_26783 = PC + 1;
	cppVar_26783 = (cppVar_26783 & cppMask_un_16_);
	cppVar_26784 = ROM.rd(cppVar_26783);
	cppVar_26785 = (cppVar_26784 >> 7) & cppMask_un_1_;
	cppVar_26786 = (cppVar_26785 == 1);
	if (cppVar_26786) {
	cppVar_26787 = PC + 1;
	cppVar_26787 = (cppVar_26787 & cppMask_un_16_);
	cppVar_26788 = ROM.rd(cppVar_26787);
	cppVar_26789 = (cppVar_26788 >> 3) & cppMask_un_5_;
	cppVar_26790 = (cppVar_26789 << 3) | 0;
	cppVar_26790 = (cppVar_26790 & cppMask_un_8_);
	cppVar_26782 = cppVar_26790;
	} else {
	cppVar_26791 = PC + 1;
	cppVar_26791 = (cppVar_26791 & cppMask_un_16_);
	cppVar_26792 = ROM.rd(cppVar_26791);
	cppVar_26793 = (cppVar_26792 >> 3) & cppMask_un_5_;
	cppVar_26794 = (cppVar_26793 & cppMask_un_5_);
	cppVar_26795 = cppVar_26794 + 32;
	cppVar_26795 = (cppVar_26795 & cppMask_un_8_);
	cppVar_26782 = cppVar_26795;
	}
	cppVar_26797 = (cppVar_26782 == 144);
	if (cppVar_26797) {
	cppVar_26781 = P1;
	} else {
	cppVar_26800 = PC + 1;
	cppVar_26800 = (cppVar_26800 & cppMask_un_16_);
	cppVar_26801 = ROM.rd(cppVar_26800);
	cppVar_26802 = (cppVar_26801 >> 7) & cppMask_un_1_;
	cppVar_26803 = (cppVar_26802 == 1);
	if (cppVar_26803) {
	cppVar_26804 = PC + 1;
	cppVar_26804 = (cppVar_26804 & cppMask_un_16_);
	cppVar_26805 = ROM.rd(cppVar_26804);
	cppVar_26806 = (cppVar_26805 >> 3) & cppMask_un_5_;
	cppVar_26807 = (cppVar_26806 << 3) | 0;
	cppVar_26807 = (cppVar_26807 & cppMask_un_8_);
	cppVar_26799 = cppVar_26807;
	} else {
	cppVar_26808 = PC + 1;
	cppVar_26808 = (cppVar_26808 & cppMask_un_16_);
	cppVar_26809 = ROM.rd(cppVar_26808);
	cppVar_26810 = (cppVar_26809 >> 3) & cppMask_un_5_;
	cppVar_26811 = (cppVar_26810 & cppMask_un_5_);
	cppVar_26812 = cppVar_26811 + 32;
	cppVar_26812 = (cppVar_26812 & cppMask_un_8_);
	cppVar_26799 = cppVar_26812;
	}
	cppVar_26814 = (cppVar_26799 == 152);
	if (cppVar_26814) {
	cppVar_26798 = SCON;
	} else {
	cppVar_26817 = PC + 1;
	cppVar_26817 = (cppVar_26817 & cppMask_un_16_);
	cppVar_26818 = ROM.rd(cppVar_26817);
	cppVar_26819 = (cppVar_26818 >> 7) & cppMask_un_1_;
	cppVar_26820 = (cppVar_26819 == 1);
	if (cppVar_26820) {
	cppVar_26821 = PC + 1;
	cppVar_26821 = (cppVar_26821 & cppMask_un_16_);
	cppVar_26822 = ROM.rd(cppVar_26821);
	cppVar_26823 = (cppVar_26822 >> 3) & cppMask_un_5_;
	cppVar_26824 = (cppVar_26823 << 3) | 0;
	cppVar_26824 = (cppVar_26824 & cppMask_un_8_);
	cppVar_26816 = cppVar_26824;
	} else {
	cppVar_26825 = PC + 1;
	cppVar_26825 = (cppVar_26825 & cppMask_un_16_);
	cppVar_26826 = ROM.rd(cppVar_26825);
	cppVar_26827 = (cppVar_26826 >> 3) & cppMask_un_5_;
	cppVar_26828 = (cppVar_26827 & cppMask_un_5_);
	cppVar_26829 = cppVar_26828 + 32;
	cppVar_26829 = (cppVar_26829 & cppMask_un_8_);
	cppVar_26816 = cppVar_26829;
	}
	cppVar_26831 = (cppVar_26816 == 153);
	if (cppVar_26831) {
	cppVar_26815 = SBUF;
	} else {
	cppVar_26834 = PC + 1;
	cppVar_26834 = (cppVar_26834 & cppMask_un_16_);
	cppVar_26835 = ROM.rd(cppVar_26834);
	cppVar_26836 = (cppVar_26835 >> 7) & cppMask_un_1_;
	cppVar_26837 = (cppVar_26836 == 1);
	if (cppVar_26837) {
	cppVar_26838 = PC + 1;
	cppVar_26838 = (cppVar_26838 & cppMask_un_16_);
	cppVar_26839 = ROM.rd(cppVar_26838);
	cppVar_26840 = (cppVar_26839 >> 3) & cppMask_un_5_;
	cppVar_26841 = (cppVar_26840 << 3) | 0;
	cppVar_26841 = (cppVar_26841 & cppMask_un_8_);
	cppVar_26833 = cppVar_26841;
	} else {
	cppVar_26842 = PC + 1;
	cppVar_26842 = (cppVar_26842 & cppMask_un_16_);
	cppVar_26843 = ROM.rd(cppVar_26842);
	cppVar_26844 = (cppVar_26843 >> 3) & cppMask_un_5_;
	cppVar_26845 = (cppVar_26844 & cppMask_un_5_);
	cppVar_26846 = cppVar_26845 + 32;
	cppVar_26846 = (cppVar_26846 & cppMask_un_8_);
	cppVar_26833 = cppVar_26846;
	}
	cppVar_26848 = (cppVar_26833 == 160);
	if (cppVar_26848) {
	cppVar_26832 = P2;
	} else {
	cppVar_26851 = PC + 1;
	cppVar_26851 = (cppVar_26851 & cppMask_un_16_);
	cppVar_26852 = ROM.rd(cppVar_26851);
	cppVar_26853 = (cppVar_26852 >> 7) & cppMask_un_1_;
	cppVar_26854 = (cppVar_26853 == 1);
	if (cppVar_26854) {
	cppVar_26855 = PC + 1;
	cppVar_26855 = (cppVar_26855 & cppMask_un_16_);
	cppVar_26856 = ROM.rd(cppVar_26855);
	cppVar_26857 = (cppVar_26856 >> 3) & cppMask_un_5_;
	cppVar_26858 = (cppVar_26857 << 3) | 0;
	cppVar_26858 = (cppVar_26858 & cppMask_un_8_);
	cppVar_26850 = cppVar_26858;
	} else {
	cppVar_26859 = PC + 1;
	cppVar_26859 = (cppVar_26859 & cppMask_un_16_);
	cppVar_26860 = ROM.rd(cppVar_26859);
	cppVar_26861 = (cppVar_26860 >> 3) & cppMask_un_5_;
	cppVar_26862 = (cppVar_26861 & cppMask_un_5_);
	cppVar_26863 = cppVar_26862 + 32;
	cppVar_26863 = (cppVar_26863 & cppMask_un_8_);
	cppVar_26850 = cppVar_26863;
	}
	cppVar_26865 = (cppVar_26850 == 168);
	if (cppVar_26865) {
	cppVar_26849 = IE;
	} else {
	cppVar_26868 = PC + 1;
	cppVar_26868 = (cppVar_26868 & cppMask_un_16_);
	cppVar_26869 = ROM.rd(cppVar_26868);
	cppVar_26870 = (cppVar_26869 >> 7) & cppMask_un_1_;
	cppVar_26871 = (cppVar_26870 == 1);
	if (cppVar_26871) {
	cppVar_26872 = PC + 1;
	cppVar_26872 = (cppVar_26872 & cppMask_un_16_);
	cppVar_26873 = ROM.rd(cppVar_26872);
	cppVar_26874 = (cppVar_26873 >> 3) & cppMask_un_5_;
	cppVar_26875 = (cppVar_26874 << 3) | 0;
	cppVar_26875 = (cppVar_26875 & cppMask_un_8_);
	cppVar_26867 = cppVar_26875;
	} else {
	cppVar_26876 = PC + 1;
	cppVar_26876 = (cppVar_26876 & cppMask_un_16_);
	cppVar_26877 = ROM.rd(cppVar_26876);
	cppVar_26878 = (cppVar_26877 >> 3) & cppMask_un_5_;
	cppVar_26879 = (cppVar_26878 & cppMask_un_5_);
	cppVar_26880 = cppVar_26879 + 32;
	cppVar_26880 = (cppVar_26880 & cppMask_un_8_);
	cppVar_26867 = cppVar_26880;
	}
	cppVar_26882 = (cppVar_26867 == 176);
	if (cppVar_26882) {
	cppVar_26866 = P3;
	} else {
	cppVar_26885 = PC + 1;
	cppVar_26885 = (cppVar_26885 & cppMask_un_16_);
	cppVar_26886 = ROM.rd(cppVar_26885);
	cppVar_26887 = (cppVar_26886 >> 7) & cppMask_un_1_;
	cppVar_26888 = (cppVar_26887 == 1);
	if (cppVar_26888) {
	cppVar_26889 = PC + 1;
	cppVar_26889 = (cppVar_26889 & cppMask_un_16_);
	cppVar_26890 = ROM.rd(cppVar_26889);
	cppVar_26891 = (cppVar_26890 >> 3) & cppMask_un_5_;
	cppVar_26892 = (cppVar_26891 << 3) | 0;
	cppVar_26892 = (cppVar_26892 & cppMask_un_8_);
	cppVar_26884 = cppVar_26892;
	} else {
	cppVar_26893 = PC + 1;
	cppVar_26893 = (cppVar_26893 & cppMask_un_16_);
	cppVar_26894 = ROM.rd(cppVar_26893);
	cppVar_26895 = (cppVar_26894 >> 3) & cppMask_un_5_;
	cppVar_26896 = (cppVar_26895 & cppMask_un_5_);
	cppVar_26897 = cppVar_26896 + 32;
	cppVar_26897 = (cppVar_26897 & cppMask_un_8_);
	cppVar_26884 = cppVar_26897;
	}
	cppVar_26899 = (cppVar_26884 == 184);
	if (cppVar_26899) {
	cppVar_26883 = IP;
	} else {
	cppVar_26902 = PC + 1;
	cppVar_26902 = (cppVar_26902 & cppMask_un_16_);
	cppVar_26903 = ROM.rd(cppVar_26902);
	cppVar_26904 = (cppVar_26903 >> 7) & cppMask_un_1_;
	cppVar_26905 = (cppVar_26904 == 1);
	if (cppVar_26905) {
	cppVar_26906 = PC + 1;
	cppVar_26906 = (cppVar_26906 & cppMask_un_16_);
	cppVar_26907 = ROM.rd(cppVar_26906);
	cppVar_26908 = (cppVar_26907 >> 3) & cppMask_un_5_;
	cppVar_26909 = (cppVar_26908 << 3) | 0;
	cppVar_26909 = (cppVar_26909 & cppMask_un_8_);
	cppVar_26901 = cppVar_26909;
	} else {
	cppVar_26910 = PC + 1;
	cppVar_26910 = (cppVar_26910 & cppMask_un_16_);
	cppVar_26911 = ROM.rd(cppVar_26910);
	cppVar_26912 = (cppVar_26911 >> 3) & cppMask_un_5_;
	cppVar_26913 = (cppVar_26912 & cppMask_un_5_);
	cppVar_26914 = cppVar_26913 + 32;
	cppVar_26914 = (cppVar_26914 & cppMask_un_8_);
	cppVar_26901 = cppVar_26914;
	}
	cppVar_26916 = (cppVar_26901 == 208);
	if (cppVar_26916) {
	cppVar_26900 = PSW;
	} else {
	cppVar_26919 = PC + 1;
	cppVar_26919 = (cppVar_26919 & cppMask_un_16_);
	cppVar_26920 = ROM.rd(cppVar_26919);
	cppVar_26921 = (cppVar_26920 >> 7) & cppMask_un_1_;
	cppVar_26922 = (cppVar_26921 == 1);
	if (cppVar_26922) {
	cppVar_26923 = PC + 1;
	cppVar_26923 = (cppVar_26923 & cppMask_un_16_);
	cppVar_26924 = ROM.rd(cppVar_26923);
	cppVar_26925 = (cppVar_26924 >> 3) & cppMask_un_5_;
	cppVar_26926 = (cppVar_26925 << 3) | 0;
	cppVar_26926 = (cppVar_26926 & cppMask_un_8_);
	cppVar_26918 = cppVar_26926;
	} else {
	cppVar_26927 = PC + 1;
	cppVar_26927 = (cppVar_26927 & cppMask_un_16_);
	cppVar_26928 = ROM.rd(cppVar_26927);
	cppVar_26929 = (cppVar_26928 >> 3) & cppMask_un_5_;
	cppVar_26930 = (cppVar_26929 & cppMask_un_5_);
	cppVar_26931 = cppVar_26930 + 32;
	cppVar_26931 = (cppVar_26931 & cppMask_un_8_);
	cppVar_26918 = cppVar_26931;
	}
	cppVar_26933 = (cppVar_26918 == 224);
	if (cppVar_26933) {
	cppVar_26917 = ACC;
	} else {
	cppVar_26936 = PC + 1;
	cppVar_26936 = (cppVar_26936 & cppMask_un_16_);
	cppVar_26937 = ROM.rd(cppVar_26936);
	cppVar_26938 = (cppVar_26937 >> 7) & cppMask_un_1_;
	cppVar_26939 = (cppVar_26938 == 1);
	if (cppVar_26939) {
	cppVar_26940 = PC + 1;
	cppVar_26940 = (cppVar_26940 & cppMask_un_16_);
	cppVar_26941 = ROM.rd(cppVar_26940);
	cppVar_26942 = (cppVar_26941 >> 3) & cppMask_un_5_;
	cppVar_26943 = (cppVar_26942 << 3) | 0;
	cppVar_26943 = (cppVar_26943 & cppMask_un_8_);
	cppVar_26935 = cppVar_26943;
	} else {
	cppVar_26944 = PC + 1;
	cppVar_26944 = (cppVar_26944 & cppMask_un_16_);
	cppVar_26945 = ROM.rd(cppVar_26944);
	cppVar_26946 = (cppVar_26945 >> 3) & cppMask_un_5_;
	cppVar_26947 = (cppVar_26946 & cppMask_un_5_);
	cppVar_26948 = cppVar_26947 + 32;
	cppVar_26948 = (cppVar_26948 & cppMask_un_8_);
	cppVar_26935 = cppVar_26948;
	}
	cppVar_26950 = (cppVar_26935 == 240);
	if (cppVar_26950) {
	cppVar_26934 = B;
	} else {
	cppVar_26934 = 0;
	}
	cppVar_26917 = cppVar_26934;
	}
	cppVar_26900 = cppVar_26917;
	}
	cppVar_26883 = cppVar_26900;
	}
	cppVar_26866 = cppVar_26883;
	}
	cppVar_26849 = cppVar_26866;
	}
	cppVar_26832 = cppVar_26849;
	}
	cppVar_26815 = cppVar_26832;
	}
	cppVar_26798 = cppVar_26815;
	}
	cppVar_26781 = cppVar_26798;
	}
	cppVar_26764 = cppVar_26781;
	}
	cppVar_26747 = cppVar_26764;
	}
	cppVar_26730 = cppVar_26747;
	}
	cppVar_26713 = cppVar_26730;
	}
	cppVar_26696 = cppVar_26713;
	}
	cppVar_26679 = cppVar_26696;
	}
	cppVar_26662 = cppVar_26679;
	}
	cppVar_26645 = cppVar_26662;
	}
	cppVar_26628 = cppVar_26645;
	}
	cppVar_26611 = cppVar_26628;
	}
	cppVar_26594 = cppVar_26611;
	}
	cppVar_26561 = cppVar_26594;
	}
	cppVar_26952 = cppVar_26560 & cppVar_26561;
	cppVar_26954 = 0;
	cppVar_26955 = PC + 1;
	cppVar_26955 = (cppVar_26955 & cppMask_un_16_);
	cppVar_26956 = ROM.rd(cppVar_26955);
	cppVar_26957 = (cppVar_26956 >> 0) & cppMask_un_3_;
	cppVar_26958 = (cppVar_26957 & cppMask_un_3_);
	cppVar_26959 = cppVar_26954 << static_cast<unsigned>(cppVar_26958);
	cppVar_26959 = (cppVar_26959 & cppMask_un_8_);
	cppVar_26960 = cppVar_26952 | cppVar_26959;
	cppVar_26533 = cppVar_26960;
	} else {
	cppVar_26533 = P0;
	}
	cppVar_26525 = cppVar_26533;
	} else {
	cppVar_26962 = ROM.rd(PC);
	cppVar_26964 = (cppVar_26962 == 5);
	if (cppVar_26964) {
	cppVar_26967 = PC + 1;
	cppVar_26967 = (cppVar_26967 & cppMask_un_16_);
	cppVar_26968 = ROM.rd(cppVar_26967);
	cppVar_26970 = (cppVar_26968 == 128);
	if (cppVar_26970) {
	cppVar_26972 = PC + 1;
	cppVar_26972 = (cppVar_26972 & cppMask_un_16_);
	cppVar_26973 = ROM.rd(cppVar_26972);
	cppVar_26974 = (cppVar_26973 >> 7) & cppMask_un_1_;
	cppVar_26976 = (cppVar_26974 == 0);
	if (cppVar_26976) {
	cppVar_26977 = PC + 1;
	cppVar_26977 = (cppVar_26977 & cppMask_un_16_);
	cppVar_26978 = ROM.rd(cppVar_26977);
	cppVar_26979 = IRAM.rd(cppVar_26978);
	cppVar_26971 = cppVar_26979;
	} else {
	cppVar_26981 = PC + 1;
	cppVar_26981 = (cppVar_26981 & cppMask_un_16_);
	cppVar_26982 = ROM.rd(cppVar_26981);
	cppVar_26984 = (cppVar_26982 == 128);
	if (cppVar_26984) {
	cppVar_26980 = P0;
	} else {
	cppVar_26986 = PC + 1;
	cppVar_26986 = (cppVar_26986 & cppMask_un_16_);
	cppVar_26987 = ROM.rd(cppVar_26986);
	cppVar_26989 = (cppVar_26987 == 129);
	if (cppVar_26989) {
	cppVar_26985 = SP;
	} else {
	cppVar_26991 = PC + 1;
	cppVar_26991 = (cppVar_26991 & cppMask_un_16_);
	cppVar_26992 = ROM.rd(cppVar_26991);
	cppVar_26994 = (cppVar_26992 == 130);
	if (cppVar_26994) {
	cppVar_26990 = DPL;
	} else {
	cppVar_26996 = PC + 1;
	cppVar_26996 = (cppVar_26996 & cppMask_un_16_);
	cppVar_26997 = ROM.rd(cppVar_26996);
	cppVar_26999 = (cppVar_26997 == 131);
	if (cppVar_26999) {
	cppVar_26995 = DPH;
	} else {
	cppVar_27001 = PC + 1;
	cppVar_27001 = (cppVar_27001 & cppMask_un_16_);
	cppVar_27002 = ROM.rd(cppVar_27001);
	cppVar_27004 = (cppVar_27002 == 135);
	if (cppVar_27004) {
	cppVar_27000 = PCON;
	} else {
	cppVar_27006 = PC + 1;
	cppVar_27006 = (cppVar_27006 & cppMask_un_16_);
	cppVar_27007 = ROM.rd(cppVar_27006);
	cppVar_27009 = (cppVar_27007 == 136);
	if (cppVar_27009) {
	cppVar_27005 = TCON;
	} else {
	cppVar_27011 = PC + 1;
	cppVar_27011 = (cppVar_27011 & cppMask_un_16_);
	cppVar_27012 = ROM.rd(cppVar_27011);
	cppVar_27014 = (cppVar_27012 == 137);
	if (cppVar_27014) {
	cppVar_27010 = TMOD;
	} else {
	cppVar_27016 = PC + 1;
	cppVar_27016 = (cppVar_27016 & cppMask_un_16_);
	cppVar_27017 = ROM.rd(cppVar_27016);
	cppVar_27019 = (cppVar_27017 == 138);
	if (cppVar_27019) {
	cppVar_27015 = TL0;
	} else {
	cppVar_27021 = PC + 1;
	cppVar_27021 = (cppVar_27021 & cppMask_un_16_);
	cppVar_27022 = ROM.rd(cppVar_27021);
	cppVar_27024 = (cppVar_27022 == 140);
	if (cppVar_27024) {
	cppVar_27020 = TH0;
	} else {
	cppVar_27026 = PC + 1;
	cppVar_27026 = (cppVar_27026 & cppMask_un_16_);
	cppVar_27027 = ROM.rd(cppVar_27026);
	cppVar_27029 = (cppVar_27027 == 139);
	if (cppVar_27029) {
	cppVar_27025 = TL1;
	} else {
	cppVar_27031 = PC + 1;
	cppVar_27031 = (cppVar_27031 & cppMask_un_16_);
	cppVar_27032 = ROM.rd(cppVar_27031);
	cppVar_27034 = (cppVar_27032 == 141);
	if (cppVar_27034) {
	cppVar_27030 = TH1;
	} else {
	cppVar_27036 = PC + 1;
	cppVar_27036 = (cppVar_27036 & cppMask_un_16_);
	cppVar_27037 = ROM.rd(cppVar_27036);
	cppVar_27039 = (cppVar_27037 == 144);
	if (cppVar_27039) {
	cppVar_27035 = P1;
	} else {
	cppVar_27041 = PC + 1;
	cppVar_27041 = (cppVar_27041 & cppMask_un_16_);
	cppVar_27042 = ROM.rd(cppVar_27041);
	cppVar_27044 = (cppVar_27042 == 152);
	if (cppVar_27044) {
	cppVar_27040 = SCON;
	} else {
	cppVar_27046 = PC + 1;
	cppVar_27046 = (cppVar_27046 & cppMask_un_16_);
	cppVar_27047 = ROM.rd(cppVar_27046);
	cppVar_27049 = (cppVar_27047 == 153);
	if (cppVar_27049) {
	cppVar_27045 = SBUF;
	} else {
	cppVar_27051 = PC + 1;
	cppVar_27051 = (cppVar_27051 & cppMask_un_16_);
	cppVar_27052 = ROM.rd(cppVar_27051);
	cppVar_27054 = (cppVar_27052 == 160);
	if (cppVar_27054) {
	cppVar_27050 = P2;
	} else {
	cppVar_27056 = PC + 1;
	cppVar_27056 = (cppVar_27056 & cppMask_un_16_);
	cppVar_27057 = ROM.rd(cppVar_27056);
	cppVar_27059 = (cppVar_27057 == 168);
	if (cppVar_27059) {
	cppVar_27055 = IE;
	} else {
	cppVar_27061 = PC + 1;
	cppVar_27061 = (cppVar_27061 & cppMask_un_16_);
	cppVar_27062 = ROM.rd(cppVar_27061);
	cppVar_27064 = (cppVar_27062 == 176);
	if (cppVar_27064) {
	cppVar_27060 = P3;
	} else {
	cppVar_27066 = PC + 1;
	cppVar_27066 = (cppVar_27066 & cppMask_un_16_);
	cppVar_27067 = ROM.rd(cppVar_27066);
	cppVar_27069 = (cppVar_27067 == 184);
	if (cppVar_27069) {
	cppVar_27065 = IP;
	} else {
	cppVar_27071 = PC + 1;
	cppVar_27071 = (cppVar_27071 & cppMask_un_16_);
	cppVar_27072 = ROM.rd(cppVar_27071);
	cppVar_27074 = (cppVar_27072 == 208);
	if (cppVar_27074) {
	cppVar_27070 = PSW;
	} else {
	cppVar_27076 = PC + 1;
	cppVar_27076 = (cppVar_27076 & cppMask_un_16_);
	cppVar_27077 = ROM.rd(cppVar_27076);
	cppVar_27079 = (cppVar_27077 == 224);
	if (cppVar_27079) {
	cppVar_27075 = ACC;
	} else {
	cppVar_27081 = PC + 1;
	cppVar_27081 = (cppVar_27081 & cppMask_un_16_);
	cppVar_27082 = ROM.rd(cppVar_27081);
	cppVar_27084 = (cppVar_27082 == 240);
	if (cppVar_27084) {
	cppVar_27080 = B;
	} else {
	cppVar_27080 = 0;
	}
	cppVar_27075 = cppVar_27080;
	}
	cppVar_27070 = cppVar_27075;
	}
	cppVar_27065 = cppVar_27070;
	}
	cppVar_27060 = cppVar_27065;
	}
	cppVar_27055 = cppVar_27060;
	}
	cppVar_27050 = cppVar_27055;
	}
	cppVar_27045 = cppVar_27050;
	}
	cppVar_27040 = cppVar_27045;
	}
	cppVar_27035 = cppVar_27040;
	}
	cppVar_27030 = cppVar_27035;
	}
	cppVar_27025 = cppVar_27030;
	}
	cppVar_27020 = cppVar_27025;
	}
	cppVar_27015 = cppVar_27020;
	}
	cppVar_27010 = cppVar_27015;
	}
	cppVar_27005 = cppVar_27010;
	}
	cppVar_27000 = cppVar_27005;
	}
	cppVar_26995 = cppVar_27000;
	}
	cppVar_26990 = cppVar_26995;
	}
	cppVar_26985 = cppVar_26990;
	}
	cppVar_26980 = cppVar_26985;
	}
	cppVar_26971 = cppVar_26980;
	}
	cppVar_27087 = cppVar_26971 + 1;
	cppVar_27087 = (cppVar_27087 & cppMask_un_8_);
	cppVar_26965 = cppVar_27087;
	} else {
	cppVar_26965 = P0;
	}
	cppVar_26961 = cppVar_26965;
	} else {
	cppVar_26961 = P0;
	}
	cppVar_26525 = cppVar_26961;
	}
	cppVar_26394 = cppVar_26525;
	}
	cppVar_26268 = cppVar_26394;
	}
	cppVar_26139 = cppVar_26268;
	}
	cppVar_26013 = cppVar_26139;
	}
	cppVar_25884 = cppVar_26013;
	}
	cppVar_25758 = cppVar_25884;
	}
	cppVar_25629 = cppVar_25758;
	}
	cppVar_25616 = cppVar_25629;
	}
	cppVar_25490 = cppVar_25616;
	}
	cppVar_25473 = cppVar_25490;
	}
	cppVar_25456 = cppVar_25473;
	}
	cppVar_25306 = cppVar_25456;
	}
	cppVar_25156 = cppVar_25306;
	}
	cppVar_25006 = cppVar_25156;
	}
	cppVar_24856 = cppVar_25006;
	}
	cppVar_24706 = cppVar_24856;
	}
	cppVar_24556 = cppVar_24706;
	}
	cppVar_24406 = cppVar_24556;
	}
	cppVar_24256 = cppVar_24406;
	}
	cppVar_23824 = cppVar_24256;
	}
	cppVar_22994 = cppVar_23824;
	}
	cppVar_22980 = cppVar_22994;
	}
	cppVar_22969 = cppVar_22980;
	}
	cppVar_22537 = cppVar_22969;
	}
	return cppVar_22537;
}
