#include "common.hpp"
#include "model_oc8051_class.hpp"

BIT_VEC model_oc8051::cppUpdateFun_SCON()
{
	BIT_VEC cppVar_59532;
	BIT_VEC cppVar_59533;
	bool cppVar_59534;
	BIT_VEC cppVar_59537;
	BIT_VEC cppVar_59538;
	BIT_VEC cppVar_59539;
	BIT_VEC cppVar_59540;
	BIT_VEC cppVar_59541;
	bool cppVar_59542;
	BIT_VEC cppVar_59543;
	BIT_VEC cppVar_59544;
	BIT_VEC cppVar_59545;
	BIT_VEC cppVar_59546;
	BIT_VEC cppVar_59547;
	BIT_VEC cppVar_59548;
	BIT_VEC cppVar_59549;
	BIT_VEC cppVar_59550;
	BIT_VEC cppVar_59551;
	BIT_VEC cppVar_59552;
	BIT_VEC cppVar_59553;
	BIT_VEC cppVar_59536;
	BIT_VEC cppVar_59554;
	bool cppVar_59555;
	BIT_VEC cppVar_59556;
	BIT_VEC cppVar_59557;
	BIT_VEC cppVar_59558;
	BIT_VEC cppVar_59559;
	BIT_VEC cppVar_59560;
	BIT_VEC cppVar_59561;
	BIT_VEC cppVar_59562;
	BIT_VEC cppVar_59565;
	BIT_VEC cppVar_59566;
	BIT_VEC cppVar_59567;
	bool cppVar_59568;
	BIT_VEC cppVar_59569;
	BIT_VEC cppVar_59570;
	BIT_VEC cppVar_59571;
	BIT_VEC cppVar_59572;
	BIT_VEC cppVar_59573;
	BIT_VEC cppVar_59574;
	BIT_VEC cppVar_59575;
	BIT_VEC cppVar_59576;
	BIT_VEC cppVar_59577;
	BIT_VEC cppVar_59564;
	BIT_VEC cppVar_59578;
	BIT_VEC cppVar_59579;
	bool cppVar_59580;
	BIT_VEC cppVar_59582;
	BIT_VEC cppVar_59583;
	BIT_VEC cppVar_59584;
	bool cppVar_59585;
	BIT_VEC cppVar_59586;
	BIT_VEC cppVar_59587;
	BIT_VEC cppVar_59588;
	BIT_VEC cppVar_59589;
	BIT_VEC cppVar_59590;
	BIT_VEC cppVar_59591;
	BIT_VEC cppVar_59592;
	BIT_VEC cppVar_59593;
	BIT_VEC cppVar_59594;
	BIT_VEC cppVar_59581;
	BIT_VEC cppVar_59595;
	BIT_VEC cppVar_59598;
	BIT_VEC cppVar_59599;
	BIT_VEC cppVar_59600;
	bool cppVar_59601;
	BIT_VEC cppVar_59602;
	BIT_VEC cppVar_59603;
	BIT_VEC cppVar_59604;
	BIT_VEC cppVar_59605;
	BIT_VEC cppVar_59606;
	BIT_VEC cppVar_59607;
	BIT_VEC cppVar_59608;
	BIT_VEC cppVar_59609;
	BIT_VEC cppVar_59610;
	BIT_VEC cppVar_59597;
	BIT_VEC cppVar_59611;
	bool cppVar_59612;
	BIT_VEC cppVar_59615;
	BIT_VEC cppVar_59616;
	BIT_VEC cppVar_59617;
	bool cppVar_59618;
	BIT_VEC cppVar_59619;
	BIT_VEC cppVar_59620;
	BIT_VEC cppVar_59621;
	BIT_VEC cppVar_59622;
	BIT_VEC cppVar_59623;
	BIT_VEC cppVar_59624;
	BIT_VEC cppVar_59625;
	BIT_VEC cppVar_59626;
	BIT_VEC cppVar_59627;
	BIT_VEC cppVar_59614;
	BIT_VEC cppVar_59628;
	bool cppVar_59629;
	BIT_VEC cppVar_59632;
	BIT_VEC cppVar_59633;
	BIT_VEC cppVar_59634;
	bool cppVar_59635;
	BIT_VEC cppVar_59636;
	BIT_VEC cppVar_59637;
	BIT_VEC cppVar_59638;
	BIT_VEC cppVar_59639;
	BIT_VEC cppVar_59640;
	BIT_VEC cppVar_59641;
	BIT_VEC cppVar_59642;
	BIT_VEC cppVar_59643;
	BIT_VEC cppVar_59644;
	BIT_VEC cppVar_59631;
	BIT_VEC cppVar_59645;
	bool cppVar_59646;
	BIT_VEC cppVar_59649;
	BIT_VEC cppVar_59650;
	BIT_VEC cppVar_59651;
	bool cppVar_59652;
	BIT_VEC cppVar_59653;
	BIT_VEC cppVar_59654;
	BIT_VEC cppVar_59655;
	BIT_VEC cppVar_59656;
	BIT_VEC cppVar_59657;
	BIT_VEC cppVar_59658;
	BIT_VEC cppVar_59659;
	BIT_VEC cppVar_59660;
	BIT_VEC cppVar_59661;
	BIT_VEC cppVar_59648;
	BIT_VEC cppVar_59662;
	bool cppVar_59663;
	BIT_VEC cppVar_59666;
	BIT_VEC cppVar_59667;
	BIT_VEC cppVar_59668;
	bool cppVar_59669;
	BIT_VEC cppVar_59670;
	BIT_VEC cppVar_59671;
	BIT_VEC cppVar_59672;
	BIT_VEC cppVar_59673;
	BIT_VEC cppVar_59674;
	BIT_VEC cppVar_59675;
	BIT_VEC cppVar_59676;
	BIT_VEC cppVar_59677;
	BIT_VEC cppVar_59678;
	BIT_VEC cppVar_59665;
	BIT_VEC cppVar_59679;
	bool cppVar_59680;
	BIT_VEC cppVar_59683;
	BIT_VEC cppVar_59684;
	BIT_VEC cppVar_59685;
	bool cppVar_59686;
	BIT_VEC cppVar_59687;
	BIT_VEC cppVar_59688;
	BIT_VEC cppVar_59689;
	BIT_VEC cppVar_59690;
	BIT_VEC cppVar_59691;
	BIT_VEC cppVar_59692;
	BIT_VEC cppVar_59693;
	BIT_VEC cppVar_59694;
	BIT_VEC cppVar_59695;
	BIT_VEC cppVar_59682;
	BIT_VEC cppVar_59696;
	bool cppVar_59697;
	BIT_VEC cppVar_59700;
	BIT_VEC cppVar_59701;
	BIT_VEC cppVar_59702;
	bool cppVar_59703;
	BIT_VEC cppVar_59704;
	BIT_VEC cppVar_59705;
	BIT_VEC cppVar_59706;
	BIT_VEC cppVar_59707;
	BIT_VEC cppVar_59708;
	BIT_VEC cppVar_59709;
	BIT_VEC cppVar_59710;
	BIT_VEC cppVar_59711;
	BIT_VEC cppVar_59712;
	BIT_VEC cppVar_59699;
	BIT_VEC cppVar_59713;
	bool cppVar_59714;
	BIT_VEC cppVar_59717;
	BIT_VEC cppVar_59718;
	BIT_VEC cppVar_59719;
	bool cppVar_59720;
	BIT_VEC cppVar_59721;
	BIT_VEC cppVar_59722;
	BIT_VEC cppVar_59723;
	BIT_VEC cppVar_59724;
	BIT_VEC cppVar_59725;
	BIT_VEC cppVar_59726;
	BIT_VEC cppVar_59727;
	BIT_VEC cppVar_59728;
	BIT_VEC cppVar_59729;
	BIT_VEC cppVar_59716;
	BIT_VEC cppVar_59730;
	bool cppVar_59731;
	BIT_VEC cppVar_59734;
	BIT_VEC cppVar_59735;
	BIT_VEC cppVar_59736;
	bool cppVar_59737;
	BIT_VEC cppVar_59738;
	BIT_VEC cppVar_59739;
	BIT_VEC cppVar_59740;
	BIT_VEC cppVar_59741;
	BIT_VEC cppVar_59742;
	BIT_VEC cppVar_59743;
	BIT_VEC cppVar_59744;
	BIT_VEC cppVar_59745;
	BIT_VEC cppVar_59746;
	BIT_VEC cppVar_59733;
	BIT_VEC cppVar_59747;
	bool cppVar_59748;
	BIT_VEC cppVar_59751;
	BIT_VEC cppVar_59752;
	BIT_VEC cppVar_59753;
	bool cppVar_59754;
	BIT_VEC cppVar_59755;
	BIT_VEC cppVar_59756;
	BIT_VEC cppVar_59757;
	BIT_VEC cppVar_59758;
	BIT_VEC cppVar_59759;
	BIT_VEC cppVar_59760;
	BIT_VEC cppVar_59761;
	BIT_VEC cppVar_59762;
	BIT_VEC cppVar_59763;
	BIT_VEC cppVar_59750;
	BIT_VEC cppVar_59764;
	bool cppVar_59765;
	BIT_VEC cppVar_59768;
	BIT_VEC cppVar_59769;
	BIT_VEC cppVar_59770;
	bool cppVar_59771;
	BIT_VEC cppVar_59772;
	BIT_VEC cppVar_59773;
	BIT_VEC cppVar_59774;
	BIT_VEC cppVar_59775;
	BIT_VEC cppVar_59776;
	BIT_VEC cppVar_59777;
	BIT_VEC cppVar_59778;
	BIT_VEC cppVar_59779;
	BIT_VEC cppVar_59780;
	BIT_VEC cppVar_59767;
	BIT_VEC cppVar_59781;
	bool cppVar_59782;
	BIT_VEC cppVar_59785;
	BIT_VEC cppVar_59786;
	BIT_VEC cppVar_59787;
	bool cppVar_59788;
	BIT_VEC cppVar_59789;
	BIT_VEC cppVar_59790;
	BIT_VEC cppVar_59791;
	BIT_VEC cppVar_59792;
	BIT_VEC cppVar_59793;
	BIT_VEC cppVar_59794;
	BIT_VEC cppVar_59795;
	BIT_VEC cppVar_59796;
	BIT_VEC cppVar_59797;
	BIT_VEC cppVar_59784;
	BIT_VEC cppVar_59798;
	bool cppVar_59799;
	BIT_VEC cppVar_59802;
	BIT_VEC cppVar_59803;
	BIT_VEC cppVar_59804;
	bool cppVar_59805;
	BIT_VEC cppVar_59806;
	BIT_VEC cppVar_59807;
	BIT_VEC cppVar_59808;
	BIT_VEC cppVar_59809;
	BIT_VEC cppVar_59810;
	BIT_VEC cppVar_59811;
	BIT_VEC cppVar_59812;
	BIT_VEC cppVar_59813;
	BIT_VEC cppVar_59814;
	BIT_VEC cppVar_59801;
	BIT_VEC cppVar_59815;
	bool cppVar_59816;
	BIT_VEC cppVar_59819;
	BIT_VEC cppVar_59820;
	BIT_VEC cppVar_59821;
	bool cppVar_59822;
	BIT_VEC cppVar_59823;
	BIT_VEC cppVar_59824;
	BIT_VEC cppVar_59825;
	BIT_VEC cppVar_59826;
	BIT_VEC cppVar_59827;
	BIT_VEC cppVar_59828;
	BIT_VEC cppVar_59829;
	BIT_VEC cppVar_59830;
	BIT_VEC cppVar_59831;
	BIT_VEC cppVar_59818;
	BIT_VEC cppVar_59832;
	bool cppVar_59833;
	BIT_VEC cppVar_59836;
	BIT_VEC cppVar_59837;
	BIT_VEC cppVar_59838;
	bool cppVar_59839;
	BIT_VEC cppVar_59840;
	BIT_VEC cppVar_59841;
	BIT_VEC cppVar_59842;
	BIT_VEC cppVar_59843;
	BIT_VEC cppVar_59844;
	BIT_VEC cppVar_59845;
	BIT_VEC cppVar_59846;
	BIT_VEC cppVar_59847;
	BIT_VEC cppVar_59848;
	BIT_VEC cppVar_59835;
	BIT_VEC cppVar_59849;
	bool cppVar_59850;
	BIT_VEC cppVar_59853;
	BIT_VEC cppVar_59854;
	BIT_VEC cppVar_59855;
	bool cppVar_59856;
	BIT_VEC cppVar_59857;
	BIT_VEC cppVar_59858;
	BIT_VEC cppVar_59859;
	BIT_VEC cppVar_59860;
	BIT_VEC cppVar_59861;
	BIT_VEC cppVar_59862;
	BIT_VEC cppVar_59863;
	BIT_VEC cppVar_59864;
	BIT_VEC cppVar_59865;
	BIT_VEC cppVar_59852;
	BIT_VEC cppVar_59866;
	bool cppVar_59867;
	BIT_VEC cppVar_59870;
	BIT_VEC cppVar_59871;
	BIT_VEC cppVar_59872;
	bool cppVar_59873;
	BIT_VEC cppVar_59874;
	BIT_VEC cppVar_59875;
	BIT_VEC cppVar_59876;
	BIT_VEC cppVar_59877;
	BIT_VEC cppVar_59878;
	BIT_VEC cppVar_59879;
	BIT_VEC cppVar_59880;
	BIT_VEC cppVar_59881;
	BIT_VEC cppVar_59882;
	BIT_VEC cppVar_59869;
	BIT_VEC cppVar_59883;
	bool cppVar_59884;
	BIT_VEC cppVar_59887;
	BIT_VEC cppVar_59888;
	BIT_VEC cppVar_59889;
	bool cppVar_59890;
	BIT_VEC cppVar_59891;
	BIT_VEC cppVar_59892;
	BIT_VEC cppVar_59893;
	BIT_VEC cppVar_59894;
	BIT_VEC cppVar_59895;
	BIT_VEC cppVar_59896;
	BIT_VEC cppVar_59897;
	BIT_VEC cppVar_59898;
	BIT_VEC cppVar_59899;
	BIT_VEC cppVar_59886;
	BIT_VEC cppVar_59900;
	bool cppVar_59901;
	BIT_VEC cppVar_59904;
	BIT_VEC cppVar_59905;
	BIT_VEC cppVar_59906;
	bool cppVar_59907;
	BIT_VEC cppVar_59908;
	BIT_VEC cppVar_59909;
	BIT_VEC cppVar_59910;
	BIT_VEC cppVar_59911;
	BIT_VEC cppVar_59912;
	BIT_VEC cppVar_59913;
	BIT_VEC cppVar_59914;
	BIT_VEC cppVar_59915;
	BIT_VEC cppVar_59916;
	BIT_VEC cppVar_59903;
	BIT_VEC cppVar_59917;
	bool cppVar_59918;
	BIT_VEC cppVar_59921;
	BIT_VEC cppVar_59922;
	BIT_VEC cppVar_59923;
	bool cppVar_59924;
	BIT_VEC cppVar_59925;
	BIT_VEC cppVar_59926;
	BIT_VEC cppVar_59927;
	BIT_VEC cppVar_59928;
	BIT_VEC cppVar_59929;
	BIT_VEC cppVar_59930;
	BIT_VEC cppVar_59931;
	BIT_VEC cppVar_59932;
	BIT_VEC cppVar_59933;
	BIT_VEC cppVar_59920;
	BIT_VEC cppVar_59934;
	bool cppVar_59935;
	BIT_VEC cppVar_59938;
	BIT_VEC cppVar_59939;
	BIT_VEC cppVar_59940;
	bool cppVar_59941;
	BIT_VEC cppVar_59942;
	BIT_VEC cppVar_59943;
	BIT_VEC cppVar_59944;
	BIT_VEC cppVar_59945;
	BIT_VEC cppVar_59946;
	BIT_VEC cppVar_59947;
	BIT_VEC cppVar_59948;
	BIT_VEC cppVar_59949;
	BIT_VEC cppVar_59950;
	BIT_VEC cppVar_59937;
	BIT_VEC cppVar_59951;
	bool cppVar_59952;
	BIT_VEC cppVar_59953;
	BIT_VEC cppVar_59936;
	BIT_VEC cppVar_59919;
	BIT_VEC cppVar_59902;
	BIT_VEC cppVar_59885;
	BIT_VEC cppVar_59868;
	BIT_VEC cppVar_59851;
	BIT_VEC cppVar_59834;
	BIT_VEC cppVar_59817;
	BIT_VEC cppVar_59800;
	BIT_VEC cppVar_59783;
	BIT_VEC cppVar_59766;
	BIT_VEC cppVar_59749;
	BIT_VEC cppVar_59732;
	BIT_VEC cppVar_59715;
	BIT_VEC cppVar_59698;
	BIT_VEC cppVar_59681;
	BIT_VEC cppVar_59664;
	BIT_VEC cppVar_59647;
	BIT_VEC cppVar_59630;
	BIT_VEC cppVar_59613;
	BIT_VEC cppVar_59596;
	BIT_VEC cppVar_59563;
	BIT_VEC cppVar_59954;
	BIT_VEC cppVar_59955;
	BIT_VEC cppVar_59956;
	BIT_VEC cppVar_59957;
	BIT_VEC cppVar_59958;
	BIT_VEC cppVar_59959;
	BIT_VEC cppVar_59960;
	BIT_VEC cppVar_59961;
	BIT_VEC cppVar_59962;
	BIT_VEC cppVar_59535;
	BIT_VEC cppVar_59964;
	BIT_VEC cppVar_59965;
	bool cppVar_59966;
	BIT_VEC cppVar_59968;
	BIT_VEC cppVar_59969;
	BIT_VEC cppVar_59970;
	BIT_VEC cppVar_59971;
	bool cppVar_59972;
	BIT_VEC cppVar_59973;
	BIT_VEC cppVar_59967;
	BIT_VEC cppVar_59975;
	BIT_VEC cppVar_59976;
	bool cppVar_59977;
	BIT_VEC cppVar_59978;
	BIT_VEC cppVar_59979;
	bool cppVar_59980;
	bool cppVar_59981;
	BIT_VEC cppVar_59983;
	BIT_VEC cppVar_59984;
	BIT_VEC cppVar_59985;
	BIT_VEC cppVar_59986;
	bool cppVar_59987;
	BIT_VEC cppVar_59982;
	BIT_VEC cppVar_59989;
	BIT_VEC cppVar_59990;
	bool cppVar_59991;
	BIT_VEC cppVar_59994;
	BIT_VEC cppVar_59995;
	BIT_VEC cppVar_59996;
	BIT_VEC cppVar_59997;
	BIT_VEC cppVar_59998;
	bool cppVar_59999;
	BIT_VEC cppVar_60000;
	BIT_VEC cppVar_60001;
	BIT_VEC cppVar_60002;
	BIT_VEC cppVar_60003;
	BIT_VEC cppVar_60004;
	BIT_VEC cppVar_60005;
	BIT_VEC cppVar_60006;
	BIT_VEC cppVar_60007;
	BIT_VEC cppVar_60008;
	BIT_VEC cppVar_60009;
	BIT_VEC cppVar_60010;
	BIT_VEC cppVar_59993;
	BIT_VEC cppVar_60011;
	bool cppVar_60012;
	BIT_VEC cppVar_60013;
	BIT_VEC cppVar_60014;
	BIT_VEC cppVar_60015;
	BIT_VEC cppVar_60016;
	BIT_VEC cppVar_60017;
	BIT_VEC cppVar_60018;
	BIT_VEC cppVar_60019;
	BIT_VEC cppVar_60022;
	BIT_VEC cppVar_60023;
	BIT_VEC cppVar_60024;
	bool cppVar_60025;
	BIT_VEC cppVar_60026;
	BIT_VEC cppVar_60027;
	BIT_VEC cppVar_60028;
	BIT_VEC cppVar_60029;
	BIT_VEC cppVar_60030;
	BIT_VEC cppVar_60031;
	BIT_VEC cppVar_60032;
	BIT_VEC cppVar_60033;
	BIT_VEC cppVar_60034;
	BIT_VEC cppVar_60021;
	BIT_VEC cppVar_60035;
	BIT_VEC cppVar_60036;
	bool cppVar_60037;
	BIT_VEC cppVar_60039;
	BIT_VEC cppVar_60040;
	BIT_VEC cppVar_60041;
	bool cppVar_60042;
	BIT_VEC cppVar_60043;
	BIT_VEC cppVar_60044;
	BIT_VEC cppVar_60045;
	BIT_VEC cppVar_60046;
	BIT_VEC cppVar_60047;
	BIT_VEC cppVar_60048;
	BIT_VEC cppVar_60049;
	BIT_VEC cppVar_60050;
	BIT_VEC cppVar_60051;
	BIT_VEC cppVar_60038;
	BIT_VEC cppVar_60052;
	BIT_VEC cppVar_60055;
	BIT_VEC cppVar_60056;
	BIT_VEC cppVar_60057;
	bool cppVar_60058;
	BIT_VEC cppVar_60059;
	BIT_VEC cppVar_60060;
	BIT_VEC cppVar_60061;
	BIT_VEC cppVar_60062;
	BIT_VEC cppVar_60063;
	BIT_VEC cppVar_60064;
	BIT_VEC cppVar_60065;
	BIT_VEC cppVar_60066;
	BIT_VEC cppVar_60067;
	BIT_VEC cppVar_60054;
	BIT_VEC cppVar_60068;
	bool cppVar_60069;
	BIT_VEC cppVar_60072;
	BIT_VEC cppVar_60073;
	BIT_VEC cppVar_60074;
	bool cppVar_60075;
	BIT_VEC cppVar_60076;
	BIT_VEC cppVar_60077;
	BIT_VEC cppVar_60078;
	BIT_VEC cppVar_60079;
	BIT_VEC cppVar_60080;
	BIT_VEC cppVar_60081;
	BIT_VEC cppVar_60082;
	BIT_VEC cppVar_60083;
	BIT_VEC cppVar_60084;
	BIT_VEC cppVar_60071;
	BIT_VEC cppVar_60085;
	bool cppVar_60086;
	BIT_VEC cppVar_60089;
	BIT_VEC cppVar_60090;
	BIT_VEC cppVar_60091;
	bool cppVar_60092;
	BIT_VEC cppVar_60093;
	BIT_VEC cppVar_60094;
	BIT_VEC cppVar_60095;
	BIT_VEC cppVar_60096;
	BIT_VEC cppVar_60097;
	BIT_VEC cppVar_60098;
	BIT_VEC cppVar_60099;
	BIT_VEC cppVar_60100;
	BIT_VEC cppVar_60101;
	BIT_VEC cppVar_60088;
	BIT_VEC cppVar_60102;
	bool cppVar_60103;
	BIT_VEC cppVar_60106;
	BIT_VEC cppVar_60107;
	BIT_VEC cppVar_60108;
	bool cppVar_60109;
	BIT_VEC cppVar_60110;
	BIT_VEC cppVar_60111;
	BIT_VEC cppVar_60112;
	BIT_VEC cppVar_60113;
	BIT_VEC cppVar_60114;
	BIT_VEC cppVar_60115;
	BIT_VEC cppVar_60116;
	BIT_VEC cppVar_60117;
	BIT_VEC cppVar_60118;
	BIT_VEC cppVar_60105;
	BIT_VEC cppVar_60119;
	bool cppVar_60120;
	BIT_VEC cppVar_60123;
	BIT_VEC cppVar_60124;
	BIT_VEC cppVar_60125;
	bool cppVar_60126;
	BIT_VEC cppVar_60127;
	BIT_VEC cppVar_60128;
	BIT_VEC cppVar_60129;
	BIT_VEC cppVar_60130;
	BIT_VEC cppVar_60131;
	BIT_VEC cppVar_60132;
	BIT_VEC cppVar_60133;
	BIT_VEC cppVar_60134;
	BIT_VEC cppVar_60135;
	BIT_VEC cppVar_60122;
	BIT_VEC cppVar_60136;
	bool cppVar_60137;
	BIT_VEC cppVar_60140;
	BIT_VEC cppVar_60141;
	BIT_VEC cppVar_60142;
	bool cppVar_60143;
	BIT_VEC cppVar_60144;
	BIT_VEC cppVar_60145;
	BIT_VEC cppVar_60146;
	BIT_VEC cppVar_60147;
	BIT_VEC cppVar_60148;
	BIT_VEC cppVar_60149;
	BIT_VEC cppVar_60150;
	BIT_VEC cppVar_60151;
	BIT_VEC cppVar_60152;
	BIT_VEC cppVar_60139;
	BIT_VEC cppVar_60153;
	bool cppVar_60154;
	BIT_VEC cppVar_60157;
	BIT_VEC cppVar_60158;
	BIT_VEC cppVar_60159;
	bool cppVar_60160;
	BIT_VEC cppVar_60161;
	BIT_VEC cppVar_60162;
	BIT_VEC cppVar_60163;
	BIT_VEC cppVar_60164;
	BIT_VEC cppVar_60165;
	BIT_VEC cppVar_60166;
	BIT_VEC cppVar_60167;
	BIT_VEC cppVar_60168;
	BIT_VEC cppVar_60169;
	BIT_VEC cppVar_60156;
	BIT_VEC cppVar_60170;
	bool cppVar_60171;
	BIT_VEC cppVar_60174;
	BIT_VEC cppVar_60175;
	BIT_VEC cppVar_60176;
	bool cppVar_60177;
	BIT_VEC cppVar_60178;
	BIT_VEC cppVar_60179;
	BIT_VEC cppVar_60180;
	BIT_VEC cppVar_60181;
	BIT_VEC cppVar_60182;
	BIT_VEC cppVar_60183;
	BIT_VEC cppVar_60184;
	BIT_VEC cppVar_60185;
	BIT_VEC cppVar_60186;
	BIT_VEC cppVar_60173;
	BIT_VEC cppVar_60187;
	bool cppVar_60188;
	BIT_VEC cppVar_60191;
	BIT_VEC cppVar_60192;
	BIT_VEC cppVar_60193;
	bool cppVar_60194;
	BIT_VEC cppVar_60195;
	BIT_VEC cppVar_60196;
	BIT_VEC cppVar_60197;
	BIT_VEC cppVar_60198;
	BIT_VEC cppVar_60199;
	BIT_VEC cppVar_60200;
	BIT_VEC cppVar_60201;
	BIT_VEC cppVar_60202;
	BIT_VEC cppVar_60203;
	BIT_VEC cppVar_60190;
	BIT_VEC cppVar_60204;
	bool cppVar_60205;
	BIT_VEC cppVar_60208;
	BIT_VEC cppVar_60209;
	BIT_VEC cppVar_60210;
	bool cppVar_60211;
	BIT_VEC cppVar_60212;
	BIT_VEC cppVar_60213;
	BIT_VEC cppVar_60214;
	BIT_VEC cppVar_60215;
	BIT_VEC cppVar_60216;
	BIT_VEC cppVar_60217;
	BIT_VEC cppVar_60218;
	BIT_VEC cppVar_60219;
	BIT_VEC cppVar_60220;
	BIT_VEC cppVar_60207;
	BIT_VEC cppVar_60221;
	bool cppVar_60222;
	BIT_VEC cppVar_60225;
	BIT_VEC cppVar_60226;
	BIT_VEC cppVar_60227;
	bool cppVar_60228;
	BIT_VEC cppVar_60229;
	BIT_VEC cppVar_60230;
	BIT_VEC cppVar_60231;
	BIT_VEC cppVar_60232;
	BIT_VEC cppVar_60233;
	BIT_VEC cppVar_60234;
	BIT_VEC cppVar_60235;
	BIT_VEC cppVar_60236;
	BIT_VEC cppVar_60237;
	BIT_VEC cppVar_60224;
	BIT_VEC cppVar_60238;
	bool cppVar_60239;
	BIT_VEC cppVar_60242;
	BIT_VEC cppVar_60243;
	BIT_VEC cppVar_60244;
	bool cppVar_60245;
	BIT_VEC cppVar_60246;
	BIT_VEC cppVar_60247;
	BIT_VEC cppVar_60248;
	BIT_VEC cppVar_60249;
	BIT_VEC cppVar_60250;
	BIT_VEC cppVar_60251;
	BIT_VEC cppVar_60252;
	BIT_VEC cppVar_60253;
	BIT_VEC cppVar_60254;
	BIT_VEC cppVar_60241;
	BIT_VEC cppVar_60255;
	bool cppVar_60256;
	BIT_VEC cppVar_60259;
	BIT_VEC cppVar_60260;
	BIT_VEC cppVar_60261;
	bool cppVar_60262;
	BIT_VEC cppVar_60263;
	BIT_VEC cppVar_60264;
	BIT_VEC cppVar_60265;
	BIT_VEC cppVar_60266;
	BIT_VEC cppVar_60267;
	BIT_VEC cppVar_60268;
	BIT_VEC cppVar_60269;
	BIT_VEC cppVar_60270;
	BIT_VEC cppVar_60271;
	BIT_VEC cppVar_60258;
	BIT_VEC cppVar_60272;
	bool cppVar_60273;
	BIT_VEC cppVar_60276;
	BIT_VEC cppVar_60277;
	BIT_VEC cppVar_60278;
	bool cppVar_60279;
	BIT_VEC cppVar_60280;
	BIT_VEC cppVar_60281;
	BIT_VEC cppVar_60282;
	BIT_VEC cppVar_60283;
	BIT_VEC cppVar_60284;
	BIT_VEC cppVar_60285;
	BIT_VEC cppVar_60286;
	BIT_VEC cppVar_60287;
	BIT_VEC cppVar_60288;
	BIT_VEC cppVar_60275;
	BIT_VEC cppVar_60289;
	bool cppVar_60290;
	BIT_VEC cppVar_60293;
	BIT_VEC cppVar_60294;
	BIT_VEC cppVar_60295;
	bool cppVar_60296;
	BIT_VEC cppVar_60297;
	BIT_VEC cppVar_60298;
	BIT_VEC cppVar_60299;
	BIT_VEC cppVar_60300;
	BIT_VEC cppVar_60301;
	BIT_VEC cppVar_60302;
	BIT_VEC cppVar_60303;
	BIT_VEC cppVar_60304;
	BIT_VEC cppVar_60305;
	BIT_VEC cppVar_60292;
	BIT_VEC cppVar_60306;
	bool cppVar_60307;
	BIT_VEC cppVar_60310;
	BIT_VEC cppVar_60311;
	BIT_VEC cppVar_60312;
	bool cppVar_60313;
	BIT_VEC cppVar_60314;
	BIT_VEC cppVar_60315;
	BIT_VEC cppVar_60316;
	BIT_VEC cppVar_60317;
	BIT_VEC cppVar_60318;
	BIT_VEC cppVar_60319;
	BIT_VEC cppVar_60320;
	BIT_VEC cppVar_60321;
	BIT_VEC cppVar_60322;
	BIT_VEC cppVar_60309;
	BIT_VEC cppVar_60323;
	bool cppVar_60324;
	BIT_VEC cppVar_60327;
	BIT_VEC cppVar_60328;
	BIT_VEC cppVar_60329;
	bool cppVar_60330;
	BIT_VEC cppVar_60331;
	BIT_VEC cppVar_60332;
	BIT_VEC cppVar_60333;
	BIT_VEC cppVar_60334;
	BIT_VEC cppVar_60335;
	BIT_VEC cppVar_60336;
	BIT_VEC cppVar_60337;
	BIT_VEC cppVar_60338;
	BIT_VEC cppVar_60339;
	BIT_VEC cppVar_60326;
	BIT_VEC cppVar_60340;
	bool cppVar_60341;
	BIT_VEC cppVar_60344;
	BIT_VEC cppVar_60345;
	BIT_VEC cppVar_60346;
	bool cppVar_60347;
	BIT_VEC cppVar_60348;
	BIT_VEC cppVar_60349;
	BIT_VEC cppVar_60350;
	BIT_VEC cppVar_60351;
	BIT_VEC cppVar_60352;
	BIT_VEC cppVar_60353;
	BIT_VEC cppVar_60354;
	BIT_VEC cppVar_60355;
	BIT_VEC cppVar_60356;
	BIT_VEC cppVar_60343;
	BIT_VEC cppVar_60357;
	bool cppVar_60358;
	BIT_VEC cppVar_60361;
	BIT_VEC cppVar_60362;
	BIT_VEC cppVar_60363;
	bool cppVar_60364;
	BIT_VEC cppVar_60365;
	BIT_VEC cppVar_60366;
	BIT_VEC cppVar_60367;
	BIT_VEC cppVar_60368;
	BIT_VEC cppVar_60369;
	BIT_VEC cppVar_60370;
	BIT_VEC cppVar_60371;
	BIT_VEC cppVar_60372;
	BIT_VEC cppVar_60373;
	BIT_VEC cppVar_60360;
	BIT_VEC cppVar_60374;
	bool cppVar_60375;
	BIT_VEC cppVar_60378;
	BIT_VEC cppVar_60379;
	BIT_VEC cppVar_60380;
	bool cppVar_60381;
	BIT_VEC cppVar_60382;
	BIT_VEC cppVar_60383;
	BIT_VEC cppVar_60384;
	BIT_VEC cppVar_60385;
	BIT_VEC cppVar_60386;
	BIT_VEC cppVar_60387;
	BIT_VEC cppVar_60388;
	BIT_VEC cppVar_60389;
	BIT_VEC cppVar_60390;
	BIT_VEC cppVar_60377;
	BIT_VEC cppVar_60391;
	bool cppVar_60392;
	BIT_VEC cppVar_60395;
	BIT_VEC cppVar_60396;
	BIT_VEC cppVar_60397;
	bool cppVar_60398;
	BIT_VEC cppVar_60399;
	BIT_VEC cppVar_60400;
	BIT_VEC cppVar_60401;
	BIT_VEC cppVar_60402;
	BIT_VEC cppVar_60403;
	BIT_VEC cppVar_60404;
	BIT_VEC cppVar_60405;
	BIT_VEC cppVar_60406;
	BIT_VEC cppVar_60407;
	BIT_VEC cppVar_60394;
	BIT_VEC cppVar_60408;
	bool cppVar_60409;
	BIT_VEC cppVar_60410;
	BIT_VEC cppVar_60393;
	BIT_VEC cppVar_60376;
	BIT_VEC cppVar_60359;
	BIT_VEC cppVar_60342;
	BIT_VEC cppVar_60325;
	BIT_VEC cppVar_60308;
	BIT_VEC cppVar_60291;
	BIT_VEC cppVar_60274;
	BIT_VEC cppVar_60257;
	BIT_VEC cppVar_60240;
	BIT_VEC cppVar_60223;
	BIT_VEC cppVar_60206;
	BIT_VEC cppVar_60189;
	BIT_VEC cppVar_60172;
	BIT_VEC cppVar_60155;
	BIT_VEC cppVar_60138;
	BIT_VEC cppVar_60121;
	BIT_VEC cppVar_60104;
	BIT_VEC cppVar_60087;
	BIT_VEC cppVar_60070;
	BIT_VEC cppVar_60053;
	BIT_VEC cppVar_60020;
	BIT_VEC cppVar_60411;
	BIT_VEC cppVar_60414;
	BIT_VEC cppVar_60415;
	BIT_VEC cppVar_60416;
	BIT_VEC cppVar_60417;
	bool cppVar_60418;
	BIT_VEC cppVar_60419;
	BIT_VEC cppVar_60420;
	BIT_VEC cppVar_60421;
	BIT_VEC cppVar_60422;
	BIT_VEC cppVar_60423;
	BIT_VEC cppVar_60424;
	BIT_VEC cppVar_60425;
	BIT_VEC cppVar_60426;
	BIT_VEC cppVar_60427;
	BIT_VEC cppVar_60428;
	BIT_VEC cppVar_60429;
	BIT_VEC cppVar_60413;
	BIT_VEC cppVar_60430;
	BIT_VEC cppVar_60431;
	bool cppVar_60432;
	BIT_VEC cppVar_60434;
	BIT_VEC cppVar_60435;
	BIT_VEC cppVar_60436;
	bool cppVar_60437;
	BIT_VEC cppVar_60438;
	BIT_VEC cppVar_60439;
	BIT_VEC cppVar_60440;
	BIT_VEC cppVar_60441;
	BIT_VEC cppVar_60442;
	BIT_VEC cppVar_60443;
	BIT_VEC cppVar_60444;
	BIT_VEC cppVar_60445;
	BIT_VEC cppVar_60446;
	BIT_VEC cppVar_60433;
	BIT_VEC cppVar_60447;
	BIT_VEC cppVar_60450;
	BIT_VEC cppVar_60451;
	BIT_VEC cppVar_60452;
	bool cppVar_60453;
	BIT_VEC cppVar_60454;
	BIT_VEC cppVar_60455;
	BIT_VEC cppVar_60456;
	BIT_VEC cppVar_60457;
	BIT_VEC cppVar_60458;
	BIT_VEC cppVar_60459;
	BIT_VEC cppVar_60460;
	BIT_VEC cppVar_60461;
	BIT_VEC cppVar_60462;
	BIT_VEC cppVar_60449;
	BIT_VEC cppVar_60463;
	bool cppVar_60464;
	BIT_VEC cppVar_60467;
	BIT_VEC cppVar_60468;
	BIT_VEC cppVar_60469;
	bool cppVar_60470;
	BIT_VEC cppVar_60471;
	BIT_VEC cppVar_60472;
	BIT_VEC cppVar_60473;
	BIT_VEC cppVar_60474;
	BIT_VEC cppVar_60475;
	BIT_VEC cppVar_60476;
	BIT_VEC cppVar_60477;
	BIT_VEC cppVar_60478;
	BIT_VEC cppVar_60479;
	BIT_VEC cppVar_60466;
	BIT_VEC cppVar_60480;
	bool cppVar_60481;
	BIT_VEC cppVar_60484;
	BIT_VEC cppVar_60485;
	BIT_VEC cppVar_60486;
	bool cppVar_60487;
	BIT_VEC cppVar_60488;
	BIT_VEC cppVar_60489;
	BIT_VEC cppVar_60490;
	BIT_VEC cppVar_60491;
	BIT_VEC cppVar_60492;
	BIT_VEC cppVar_60493;
	BIT_VEC cppVar_60494;
	BIT_VEC cppVar_60495;
	BIT_VEC cppVar_60496;
	BIT_VEC cppVar_60483;
	BIT_VEC cppVar_60497;
	bool cppVar_60498;
	BIT_VEC cppVar_60501;
	BIT_VEC cppVar_60502;
	BIT_VEC cppVar_60503;
	bool cppVar_60504;
	BIT_VEC cppVar_60505;
	BIT_VEC cppVar_60506;
	BIT_VEC cppVar_60507;
	BIT_VEC cppVar_60508;
	BIT_VEC cppVar_60509;
	BIT_VEC cppVar_60510;
	BIT_VEC cppVar_60511;
	BIT_VEC cppVar_60512;
	BIT_VEC cppVar_60513;
	BIT_VEC cppVar_60500;
	BIT_VEC cppVar_60514;
	bool cppVar_60515;
	BIT_VEC cppVar_60518;
	BIT_VEC cppVar_60519;
	BIT_VEC cppVar_60520;
	bool cppVar_60521;
	BIT_VEC cppVar_60522;
	BIT_VEC cppVar_60523;
	BIT_VEC cppVar_60524;
	BIT_VEC cppVar_60525;
	BIT_VEC cppVar_60526;
	BIT_VEC cppVar_60527;
	BIT_VEC cppVar_60528;
	BIT_VEC cppVar_60529;
	BIT_VEC cppVar_60530;
	BIT_VEC cppVar_60517;
	BIT_VEC cppVar_60531;
	bool cppVar_60532;
	BIT_VEC cppVar_60535;
	BIT_VEC cppVar_60536;
	BIT_VEC cppVar_60537;
	bool cppVar_60538;
	BIT_VEC cppVar_60539;
	BIT_VEC cppVar_60540;
	BIT_VEC cppVar_60541;
	BIT_VEC cppVar_60542;
	BIT_VEC cppVar_60543;
	BIT_VEC cppVar_60544;
	BIT_VEC cppVar_60545;
	BIT_VEC cppVar_60546;
	BIT_VEC cppVar_60547;
	BIT_VEC cppVar_60534;
	BIT_VEC cppVar_60548;
	bool cppVar_60549;
	BIT_VEC cppVar_60552;
	BIT_VEC cppVar_60553;
	BIT_VEC cppVar_60554;
	bool cppVar_60555;
	BIT_VEC cppVar_60556;
	BIT_VEC cppVar_60557;
	BIT_VEC cppVar_60558;
	BIT_VEC cppVar_60559;
	BIT_VEC cppVar_60560;
	BIT_VEC cppVar_60561;
	BIT_VEC cppVar_60562;
	BIT_VEC cppVar_60563;
	BIT_VEC cppVar_60564;
	BIT_VEC cppVar_60551;
	BIT_VEC cppVar_60565;
	bool cppVar_60566;
	BIT_VEC cppVar_60569;
	BIT_VEC cppVar_60570;
	BIT_VEC cppVar_60571;
	bool cppVar_60572;
	BIT_VEC cppVar_60573;
	BIT_VEC cppVar_60574;
	BIT_VEC cppVar_60575;
	BIT_VEC cppVar_60576;
	BIT_VEC cppVar_60577;
	BIT_VEC cppVar_60578;
	BIT_VEC cppVar_60579;
	BIT_VEC cppVar_60580;
	BIT_VEC cppVar_60581;
	BIT_VEC cppVar_60568;
	BIT_VEC cppVar_60582;
	bool cppVar_60583;
	BIT_VEC cppVar_60586;
	BIT_VEC cppVar_60587;
	BIT_VEC cppVar_60588;
	bool cppVar_60589;
	BIT_VEC cppVar_60590;
	BIT_VEC cppVar_60591;
	BIT_VEC cppVar_60592;
	BIT_VEC cppVar_60593;
	BIT_VEC cppVar_60594;
	BIT_VEC cppVar_60595;
	BIT_VEC cppVar_60596;
	BIT_VEC cppVar_60597;
	BIT_VEC cppVar_60598;
	BIT_VEC cppVar_60585;
	BIT_VEC cppVar_60599;
	bool cppVar_60600;
	BIT_VEC cppVar_60603;
	BIT_VEC cppVar_60604;
	BIT_VEC cppVar_60605;
	bool cppVar_60606;
	BIT_VEC cppVar_60607;
	BIT_VEC cppVar_60608;
	BIT_VEC cppVar_60609;
	BIT_VEC cppVar_60610;
	BIT_VEC cppVar_60611;
	BIT_VEC cppVar_60612;
	BIT_VEC cppVar_60613;
	BIT_VEC cppVar_60614;
	BIT_VEC cppVar_60615;
	BIT_VEC cppVar_60602;
	BIT_VEC cppVar_60616;
	bool cppVar_60617;
	BIT_VEC cppVar_60620;
	BIT_VEC cppVar_60621;
	BIT_VEC cppVar_60622;
	bool cppVar_60623;
	BIT_VEC cppVar_60624;
	BIT_VEC cppVar_60625;
	BIT_VEC cppVar_60626;
	BIT_VEC cppVar_60627;
	BIT_VEC cppVar_60628;
	BIT_VEC cppVar_60629;
	BIT_VEC cppVar_60630;
	BIT_VEC cppVar_60631;
	BIT_VEC cppVar_60632;
	BIT_VEC cppVar_60619;
	BIT_VEC cppVar_60633;
	bool cppVar_60634;
	BIT_VEC cppVar_60637;
	BIT_VEC cppVar_60638;
	BIT_VEC cppVar_60639;
	bool cppVar_60640;
	BIT_VEC cppVar_60641;
	BIT_VEC cppVar_60642;
	BIT_VEC cppVar_60643;
	BIT_VEC cppVar_60644;
	BIT_VEC cppVar_60645;
	BIT_VEC cppVar_60646;
	BIT_VEC cppVar_60647;
	BIT_VEC cppVar_60648;
	BIT_VEC cppVar_60649;
	BIT_VEC cppVar_60636;
	BIT_VEC cppVar_60650;
	bool cppVar_60651;
	BIT_VEC cppVar_60654;
	BIT_VEC cppVar_60655;
	BIT_VEC cppVar_60656;
	bool cppVar_60657;
	BIT_VEC cppVar_60658;
	BIT_VEC cppVar_60659;
	BIT_VEC cppVar_60660;
	BIT_VEC cppVar_60661;
	BIT_VEC cppVar_60662;
	BIT_VEC cppVar_60663;
	BIT_VEC cppVar_60664;
	BIT_VEC cppVar_60665;
	BIT_VEC cppVar_60666;
	BIT_VEC cppVar_60653;
	BIT_VEC cppVar_60667;
	bool cppVar_60668;
	BIT_VEC cppVar_60671;
	BIT_VEC cppVar_60672;
	BIT_VEC cppVar_60673;
	bool cppVar_60674;
	BIT_VEC cppVar_60675;
	BIT_VEC cppVar_60676;
	BIT_VEC cppVar_60677;
	BIT_VEC cppVar_60678;
	BIT_VEC cppVar_60679;
	BIT_VEC cppVar_60680;
	BIT_VEC cppVar_60681;
	BIT_VEC cppVar_60682;
	BIT_VEC cppVar_60683;
	BIT_VEC cppVar_60670;
	BIT_VEC cppVar_60684;
	bool cppVar_60685;
	BIT_VEC cppVar_60688;
	BIT_VEC cppVar_60689;
	BIT_VEC cppVar_60690;
	bool cppVar_60691;
	BIT_VEC cppVar_60692;
	BIT_VEC cppVar_60693;
	BIT_VEC cppVar_60694;
	BIT_VEC cppVar_60695;
	BIT_VEC cppVar_60696;
	BIT_VEC cppVar_60697;
	BIT_VEC cppVar_60698;
	BIT_VEC cppVar_60699;
	BIT_VEC cppVar_60700;
	BIT_VEC cppVar_60687;
	BIT_VEC cppVar_60701;
	bool cppVar_60702;
	BIT_VEC cppVar_60705;
	BIT_VEC cppVar_60706;
	BIT_VEC cppVar_60707;
	bool cppVar_60708;
	BIT_VEC cppVar_60709;
	BIT_VEC cppVar_60710;
	BIT_VEC cppVar_60711;
	BIT_VEC cppVar_60712;
	BIT_VEC cppVar_60713;
	BIT_VEC cppVar_60714;
	BIT_VEC cppVar_60715;
	BIT_VEC cppVar_60716;
	BIT_VEC cppVar_60717;
	BIT_VEC cppVar_60704;
	BIT_VEC cppVar_60718;
	bool cppVar_60719;
	BIT_VEC cppVar_60722;
	BIT_VEC cppVar_60723;
	BIT_VEC cppVar_60724;
	bool cppVar_60725;
	BIT_VEC cppVar_60726;
	BIT_VEC cppVar_60727;
	BIT_VEC cppVar_60728;
	BIT_VEC cppVar_60729;
	BIT_VEC cppVar_60730;
	BIT_VEC cppVar_60731;
	BIT_VEC cppVar_60732;
	BIT_VEC cppVar_60733;
	BIT_VEC cppVar_60734;
	BIT_VEC cppVar_60721;
	BIT_VEC cppVar_60735;
	bool cppVar_60736;
	BIT_VEC cppVar_60739;
	BIT_VEC cppVar_60740;
	BIT_VEC cppVar_60741;
	bool cppVar_60742;
	BIT_VEC cppVar_60743;
	BIT_VEC cppVar_60744;
	BIT_VEC cppVar_60745;
	BIT_VEC cppVar_60746;
	BIT_VEC cppVar_60747;
	BIT_VEC cppVar_60748;
	BIT_VEC cppVar_60749;
	BIT_VEC cppVar_60750;
	BIT_VEC cppVar_60751;
	BIT_VEC cppVar_60738;
	BIT_VEC cppVar_60752;
	bool cppVar_60753;
	BIT_VEC cppVar_60756;
	BIT_VEC cppVar_60757;
	BIT_VEC cppVar_60758;
	bool cppVar_60759;
	BIT_VEC cppVar_60760;
	BIT_VEC cppVar_60761;
	BIT_VEC cppVar_60762;
	BIT_VEC cppVar_60763;
	BIT_VEC cppVar_60764;
	BIT_VEC cppVar_60765;
	BIT_VEC cppVar_60766;
	BIT_VEC cppVar_60767;
	BIT_VEC cppVar_60768;
	BIT_VEC cppVar_60755;
	BIT_VEC cppVar_60769;
	bool cppVar_60770;
	BIT_VEC cppVar_60773;
	BIT_VEC cppVar_60774;
	BIT_VEC cppVar_60775;
	bool cppVar_60776;
	BIT_VEC cppVar_60777;
	BIT_VEC cppVar_60778;
	BIT_VEC cppVar_60779;
	BIT_VEC cppVar_60780;
	BIT_VEC cppVar_60781;
	BIT_VEC cppVar_60782;
	BIT_VEC cppVar_60783;
	BIT_VEC cppVar_60784;
	BIT_VEC cppVar_60785;
	BIT_VEC cppVar_60772;
	BIT_VEC cppVar_60786;
	bool cppVar_60787;
	BIT_VEC cppVar_60790;
	BIT_VEC cppVar_60791;
	BIT_VEC cppVar_60792;
	bool cppVar_60793;
	BIT_VEC cppVar_60794;
	BIT_VEC cppVar_60795;
	BIT_VEC cppVar_60796;
	BIT_VEC cppVar_60797;
	BIT_VEC cppVar_60798;
	BIT_VEC cppVar_60799;
	BIT_VEC cppVar_60800;
	BIT_VEC cppVar_60801;
	BIT_VEC cppVar_60802;
	BIT_VEC cppVar_60789;
	BIT_VEC cppVar_60803;
	bool cppVar_60804;
	BIT_VEC cppVar_60805;
	BIT_VEC cppVar_60788;
	BIT_VEC cppVar_60771;
	BIT_VEC cppVar_60754;
	BIT_VEC cppVar_60737;
	BIT_VEC cppVar_60720;
	BIT_VEC cppVar_60703;
	BIT_VEC cppVar_60686;
	BIT_VEC cppVar_60669;
	BIT_VEC cppVar_60652;
	BIT_VEC cppVar_60635;
	BIT_VEC cppVar_60618;
	BIT_VEC cppVar_60601;
	BIT_VEC cppVar_60584;
	BIT_VEC cppVar_60567;
	BIT_VEC cppVar_60550;
	BIT_VEC cppVar_60533;
	BIT_VEC cppVar_60516;
	BIT_VEC cppVar_60499;
	BIT_VEC cppVar_60482;
	BIT_VEC cppVar_60465;
	BIT_VEC cppVar_60448;
	BIT_VEC cppVar_60412;
	BIT_VEC cppVar_60806;
	BIT_VEC cppVar_60807;
	BIT_VEC cppVar_60808;
	BIT_VEC cppVar_60809;
	BIT_VEC cppVar_60810;
	BIT_VEC cppVar_60811;
	BIT_VEC cppVar_60812;
	BIT_VEC cppVar_60813;
	BIT_VEC cppVar_60814;
	BIT_VEC cppVar_60815;
	BIT_VEC cppVar_60816;
	BIT_VEC cppVar_60817;
	BIT_VEC cppVar_59992;
	BIT_VEC cppVar_60819;
	BIT_VEC cppVar_60820;
	bool cppVar_60821;
	BIT_VEC cppVar_60824;
	BIT_VEC cppVar_60825;
	BIT_VEC cppVar_60826;
	BIT_VEC cppVar_60827;
	BIT_VEC cppVar_60828;
	bool cppVar_60829;
	BIT_VEC cppVar_60830;
	BIT_VEC cppVar_60831;
	BIT_VEC cppVar_60832;
	BIT_VEC cppVar_60833;
	BIT_VEC cppVar_60834;
	BIT_VEC cppVar_60835;
	BIT_VEC cppVar_60836;
	BIT_VEC cppVar_60837;
	BIT_VEC cppVar_60838;
	BIT_VEC cppVar_60839;
	BIT_VEC cppVar_60840;
	BIT_VEC cppVar_60823;
	BIT_VEC cppVar_60841;
	bool cppVar_60842;
	BIT_VEC cppVar_60843;
	BIT_VEC cppVar_60844;
	BIT_VEC cppVar_60845;
	BIT_VEC cppVar_60846;
	BIT_VEC cppVar_60847;
	BIT_VEC cppVar_60848;
	BIT_VEC cppVar_60849;
	BIT_VEC cppVar_60852;
	BIT_VEC cppVar_60853;
	BIT_VEC cppVar_60854;
	bool cppVar_60855;
	BIT_VEC cppVar_60856;
	BIT_VEC cppVar_60857;
	BIT_VEC cppVar_60858;
	BIT_VEC cppVar_60859;
	BIT_VEC cppVar_60860;
	BIT_VEC cppVar_60861;
	BIT_VEC cppVar_60862;
	BIT_VEC cppVar_60863;
	BIT_VEC cppVar_60864;
	BIT_VEC cppVar_60851;
	BIT_VEC cppVar_60865;
	BIT_VEC cppVar_60866;
	bool cppVar_60867;
	BIT_VEC cppVar_60869;
	BIT_VEC cppVar_60870;
	BIT_VEC cppVar_60871;
	bool cppVar_60872;
	BIT_VEC cppVar_60873;
	BIT_VEC cppVar_60874;
	BIT_VEC cppVar_60875;
	BIT_VEC cppVar_60876;
	BIT_VEC cppVar_60877;
	BIT_VEC cppVar_60878;
	BIT_VEC cppVar_60879;
	BIT_VEC cppVar_60880;
	BIT_VEC cppVar_60881;
	BIT_VEC cppVar_60868;
	BIT_VEC cppVar_60882;
	BIT_VEC cppVar_60885;
	BIT_VEC cppVar_60886;
	BIT_VEC cppVar_60887;
	bool cppVar_60888;
	BIT_VEC cppVar_60889;
	BIT_VEC cppVar_60890;
	BIT_VEC cppVar_60891;
	BIT_VEC cppVar_60892;
	BIT_VEC cppVar_60893;
	BIT_VEC cppVar_60894;
	BIT_VEC cppVar_60895;
	BIT_VEC cppVar_60896;
	BIT_VEC cppVar_60897;
	BIT_VEC cppVar_60884;
	BIT_VEC cppVar_60898;
	bool cppVar_60899;
	BIT_VEC cppVar_60902;
	BIT_VEC cppVar_60903;
	BIT_VEC cppVar_60904;
	bool cppVar_60905;
	BIT_VEC cppVar_60906;
	BIT_VEC cppVar_60907;
	BIT_VEC cppVar_60908;
	BIT_VEC cppVar_60909;
	BIT_VEC cppVar_60910;
	BIT_VEC cppVar_60911;
	BIT_VEC cppVar_60912;
	BIT_VEC cppVar_60913;
	BIT_VEC cppVar_60914;
	BIT_VEC cppVar_60901;
	BIT_VEC cppVar_60915;
	bool cppVar_60916;
	BIT_VEC cppVar_60919;
	BIT_VEC cppVar_60920;
	BIT_VEC cppVar_60921;
	bool cppVar_60922;
	BIT_VEC cppVar_60923;
	BIT_VEC cppVar_60924;
	BIT_VEC cppVar_60925;
	BIT_VEC cppVar_60926;
	BIT_VEC cppVar_60927;
	BIT_VEC cppVar_60928;
	BIT_VEC cppVar_60929;
	BIT_VEC cppVar_60930;
	BIT_VEC cppVar_60931;
	BIT_VEC cppVar_60918;
	BIT_VEC cppVar_60932;
	bool cppVar_60933;
	BIT_VEC cppVar_60936;
	BIT_VEC cppVar_60937;
	BIT_VEC cppVar_60938;
	bool cppVar_60939;
	BIT_VEC cppVar_60940;
	BIT_VEC cppVar_60941;
	BIT_VEC cppVar_60942;
	BIT_VEC cppVar_60943;
	BIT_VEC cppVar_60944;
	BIT_VEC cppVar_60945;
	BIT_VEC cppVar_60946;
	BIT_VEC cppVar_60947;
	BIT_VEC cppVar_60948;
	BIT_VEC cppVar_60935;
	BIT_VEC cppVar_60949;
	bool cppVar_60950;
	BIT_VEC cppVar_60953;
	BIT_VEC cppVar_60954;
	BIT_VEC cppVar_60955;
	bool cppVar_60956;
	BIT_VEC cppVar_60957;
	BIT_VEC cppVar_60958;
	BIT_VEC cppVar_60959;
	BIT_VEC cppVar_60960;
	BIT_VEC cppVar_60961;
	BIT_VEC cppVar_60962;
	BIT_VEC cppVar_60963;
	BIT_VEC cppVar_60964;
	BIT_VEC cppVar_60965;
	BIT_VEC cppVar_60952;
	BIT_VEC cppVar_60966;
	bool cppVar_60967;
	BIT_VEC cppVar_60970;
	BIT_VEC cppVar_60971;
	BIT_VEC cppVar_60972;
	bool cppVar_60973;
	BIT_VEC cppVar_60974;
	BIT_VEC cppVar_60975;
	BIT_VEC cppVar_60976;
	BIT_VEC cppVar_60977;
	BIT_VEC cppVar_60978;
	BIT_VEC cppVar_60979;
	BIT_VEC cppVar_60980;
	BIT_VEC cppVar_60981;
	BIT_VEC cppVar_60982;
	BIT_VEC cppVar_60969;
	BIT_VEC cppVar_60983;
	bool cppVar_60984;
	BIT_VEC cppVar_60987;
	BIT_VEC cppVar_60988;
	BIT_VEC cppVar_60989;
	bool cppVar_60990;
	BIT_VEC cppVar_60991;
	BIT_VEC cppVar_60992;
	BIT_VEC cppVar_60993;
	BIT_VEC cppVar_60994;
	BIT_VEC cppVar_60995;
	BIT_VEC cppVar_60996;
	BIT_VEC cppVar_60997;
	BIT_VEC cppVar_60998;
	BIT_VEC cppVar_60999;
	BIT_VEC cppVar_60986;
	BIT_VEC cppVar_61000;
	bool cppVar_61001;
	BIT_VEC cppVar_61004;
	BIT_VEC cppVar_61005;
	BIT_VEC cppVar_61006;
	bool cppVar_61007;
	BIT_VEC cppVar_61008;
	BIT_VEC cppVar_61009;
	BIT_VEC cppVar_61010;
	BIT_VEC cppVar_61011;
	BIT_VEC cppVar_61012;
	BIT_VEC cppVar_61013;
	BIT_VEC cppVar_61014;
	BIT_VEC cppVar_61015;
	BIT_VEC cppVar_61016;
	BIT_VEC cppVar_61003;
	BIT_VEC cppVar_61017;
	bool cppVar_61018;
	BIT_VEC cppVar_61021;
	BIT_VEC cppVar_61022;
	BIT_VEC cppVar_61023;
	bool cppVar_61024;
	BIT_VEC cppVar_61025;
	BIT_VEC cppVar_61026;
	BIT_VEC cppVar_61027;
	BIT_VEC cppVar_61028;
	BIT_VEC cppVar_61029;
	BIT_VEC cppVar_61030;
	BIT_VEC cppVar_61031;
	BIT_VEC cppVar_61032;
	BIT_VEC cppVar_61033;
	BIT_VEC cppVar_61020;
	BIT_VEC cppVar_61034;
	bool cppVar_61035;
	BIT_VEC cppVar_61038;
	BIT_VEC cppVar_61039;
	BIT_VEC cppVar_61040;
	bool cppVar_61041;
	BIT_VEC cppVar_61042;
	BIT_VEC cppVar_61043;
	BIT_VEC cppVar_61044;
	BIT_VEC cppVar_61045;
	BIT_VEC cppVar_61046;
	BIT_VEC cppVar_61047;
	BIT_VEC cppVar_61048;
	BIT_VEC cppVar_61049;
	BIT_VEC cppVar_61050;
	BIT_VEC cppVar_61037;
	BIT_VEC cppVar_61051;
	bool cppVar_61052;
	BIT_VEC cppVar_61055;
	BIT_VEC cppVar_61056;
	BIT_VEC cppVar_61057;
	bool cppVar_61058;
	BIT_VEC cppVar_61059;
	BIT_VEC cppVar_61060;
	BIT_VEC cppVar_61061;
	BIT_VEC cppVar_61062;
	BIT_VEC cppVar_61063;
	BIT_VEC cppVar_61064;
	BIT_VEC cppVar_61065;
	BIT_VEC cppVar_61066;
	BIT_VEC cppVar_61067;
	BIT_VEC cppVar_61054;
	BIT_VEC cppVar_61068;
	bool cppVar_61069;
	BIT_VEC cppVar_61072;
	BIT_VEC cppVar_61073;
	BIT_VEC cppVar_61074;
	bool cppVar_61075;
	BIT_VEC cppVar_61076;
	BIT_VEC cppVar_61077;
	BIT_VEC cppVar_61078;
	BIT_VEC cppVar_61079;
	BIT_VEC cppVar_61080;
	BIT_VEC cppVar_61081;
	BIT_VEC cppVar_61082;
	BIT_VEC cppVar_61083;
	BIT_VEC cppVar_61084;
	BIT_VEC cppVar_61071;
	BIT_VEC cppVar_61085;
	bool cppVar_61086;
	BIT_VEC cppVar_61089;
	BIT_VEC cppVar_61090;
	BIT_VEC cppVar_61091;
	bool cppVar_61092;
	BIT_VEC cppVar_61093;
	BIT_VEC cppVar_61094;
	BIT_VEC cppVar_61095;
	BIT_VEC cppVar_61096;
	BIT_VEC cppVar_61097;
	BIT_VEC cppVar_61098;
	BIT_VEC cppVar_61099;
	BIT_VEC cppVar_61100;
	BIT_VEC cppVar_61101;
	BIT_VEC cppVar_61088;
	BIT_VEC cppVar_61102;
	bool cppVar_61103;
	BIT_VEC cppVar_61106;
	BIT_VEC cppVar_61107;
	BIT_VEC cppVar_61108;
	bool cppVar_61109;
	BIT_VEC cppVar_61110;
	BIT_VEC cppVar_61111;
	BIT_VEC cppVar_61112;
	BIT_VEC cppVar_61113;
	BIT_VEC cppVar_61114;
	BIT_VEC cppVar_61115;
	BIT_VEC cppVar_61116;
	BIT_VEC cppVar_61117;
	BIT_VEC cppVar_61118;
	BIT_VEC cppVar_61105;
	BIT_VEC cppVar_61119;
	bool cppVar_61120;
	BIT_VEC cppVar_61123;
	BIT_VEC cppVar_61124;
	BIT_VEC cppVar_61125;
	bool cppVar_61126;
	BIT_VEC cppVar_61127;
	BIT_VEC cppVar_61128;
	BIT_VEC cppVar_61129;
	BIT_VEC cppVar_61130;
	BIT_VEC cppVar_61131;
	BIT_VEC cppVar_61132;
	BIT_VEC cppVar_61133;
	BIT_VEC cppVar_61134;
	BIT_VEC cppVar_61135;
	BIT_VEC cppVar_61122;
	BIT_VEC cppVar_61136;
	bool cppVar_61137;
	BIT_VEC cppVar_61140;
	BIT_VEC cppVar_61141;
	BIT_VEC cppVar_61142;
	bool cppVar_61143;
	BIT_VEC cppVar_61144;
	BIT_VEC cppVar_61145;
	BIT_VEC cppVar_61146;
	BIT_VEC cppVar_61147;
	BIT_VEC cppVar_61148;
	BIT_VEC cppVar_61149;
	BIT_VEC cppVar_61150;
	BIT_VEC cppVar_61151;
	BIT_VEC cppVar_61152;
	BIT_VEC cppVar_61139;
	BIT_VEC cppVar_61153;
	bool cppVar_61154;
	BIT_VEC cppVar_61157;
	BIT_VEC cppVar_61158;
	BIT_VEC cppVar_61159;
	bool cppVar_61160;
	BIT_VEC cppVar_61161;
	BIT_VEC cppVar_61162;
	BIT_VEC cppVar_61163;
	BIT_VEC cppVar_61164;
	BIT_VEC cppVar_61165;
	BIT_VEC cppVar_61166;
	BIT_VEC cppVar_61167;
	BIT_VEC cppVar_61168;
	BIT_VEC cppVar_61169;
	BIT_VEC cppVar_61156;
	BIT_VEC cppVar_61170;
	bool cppVar_61171;
	BIT_VEC cppVar_61174;
	BIT_VEC cppVar_61175;
	BIT_VEC cppVar_61176;
	bool cppVar_61177;
	BIT_VEC cppVar_61178;
	BIT_VEC cppVar_61179;
	BIT_VEC cppVar_61180;
	BIT_VEC cppVar_61181;
	BIT_VEC cppVar_61182;
	BIT_VEC cppVar_61183;
	BIT_VEC cppVar_61184;
	BIT_VEC cppVar_61185;
	BIT_VEC cppVar_61186;
	BIT_VEC cppVar_61173;
	BIT_VEC cppVar_61187;
	bool cppVar_61188;
	BIT_VEC cppVar_61191;
	BIT_VEC cppVar_61192;
	BIT_VEC cppVar_61193;
	bool cppVar_61194;
	BIT_VEC cppVar_61195;
	BIT_VEC cppVar_61196;
	BIT_VEC cppVar_61197;
	BIT_VEC cppVar_61198;
	BIT_VEC cppVar_61199;
	BIT_VEC cppVar_61200;
	BIT_VEC cppVar_61201;
	BIT_VEC cppVar_61202;
	BIT_VEC cppVar_61203;
	BIT_VEC cppVar_61190;
	BIT_VEC cppVar_61204;
	bool cppVar_61205;
	BIT_VEC cppVar_61208;
	BIT_VEC cppVar_61209;
	BIT_VEC cppVar_61210;
	bool cppVar_61211;
	BIT_VEC cppVar_61212;
	BIT_VEC cppVar_61213;
	BIT_VEC cppVar_61214;
	BIT_VEC cppVar_61215;
	BIT_VEC cppVar_61216;
	BIT_VEC cppVar_61217;
	BIT_VEC cppVar_61218;
	BIT_VEC cppVar_61219;
	BIT_VEC cppVar_61220;
	BIT_VEC cppVar_61207;
	BIT_VEC cppVar_61221;
	bool cppVar_61222;
	BIT_VEC cppVar_61225;
	BIT_VEC cppVar_61226;
	BIT_VEC cppVar_61227;
	bool cppVar_61228;
	BIT_VEC cppVar_61229;
	BIT_VEC cppVar_61230;
	BIT_VEC cppVar_61231;
	BIT_VEC cppVar_61232;
	BIT_VEC cppVar_61233;
	BIT_VEC cppVar_61234;
	BIT_VEC cppVar_61235;
	BIT_VEC cppVar_61236;
	BIT_VEC cppVar_61237;
	BIT_VEC cppVar_61224;
	BIT_VEC cppVar_61238;
	bool cppVar_61239;
	BIT_VEC cppVar_61240;
	BIT_VEC cppVar_61223;
	BIT_VEC cppVar_61206;
	BIT_VEC cppVar_61189;
	BIT_VEC cppVar_61172;
	BIT_VEC cppVar_61155;
	BIT_VEC cppVar_61138;
	BIT_VEC cppVar_61121;
	BIT_VEC cppVar_61104;
	BIT_VEC cppVar_61087;
	BIT_VEC cppVar_61070;
	BIT_VEC cppVar_61053;
	BIT_VEC cppVar_61036;
	BIT_VEC cppVar_61019;
	BIT_VEC cppVar_61002;
	BIT_VEC cppVar_60985;
	BIT_VEC cppVar_60968;
	BIT_VEC cppVar_60951;
	BIT_VEC cppVar_60934;
	BIT_VEC cppVar_60917;
	BIT_VEC cppVar_60900;
	BIT_VEC cppVar_60883;
	BIT_VEC cppVar_60850;
	BIT_VEC cppVar_61241;
	BIT_VEC cppVar_61242;
	BIT_VEC cppVar_61243;
	BIT_VEC cppVar_61244;
	BIT_VEC cppVar_61245;
	BIT_VEC cppVar_61246;
	BIT_VEC cppVar_61247;
	BIT_VEC cppVar_61248;
	BIT_VEC cppVar_61249;
	BIT_VEC cppVar_60822;
	BIT_VEC cppVar_61251;
	BIT_VEC cppVar_61252;
	bool cppVar_61253;
	BIT_VEC cppVar_61255;
	BIT_VEC cppVar_61256;
	BIT_VEC cppVar_61257;
	BIT_VEC cppVar_61258;
	bool cppVar_61259;
	BIT_VEC cppVar_61261;
	BIT_VEC cppVar_61262;
	BIT_VEC cppVar_61263;
	BIT_VEC cppVar_61264;
	BIT_VEC cppVar_61265;
	BIT_VEC cppVar_61266;
	BIT_VEC cppVar_61267;
	bool cppVar_61268;
	BIT_VEC cppVar_61269;
	BIT_VEC cppVar_61270;
	BIT_VEC cppVar_61271;
	BIT_VEC cppVar_61272;
	BIT_VEC cppVar_61274;
	BIT_VEC cppVar_61275;
	BIT_VEC cppVar_61276;
	BIT_VEC cppVar_61277;
	bool cppVar_61278;
	BIT_VEC cppVar_61280;
	BIT_VEC cppVar_61281;
	BIT_VEC cppVar_61282;
	BIT_VEC cppVar_61283;
	bool cppVar_61284;
	BIT_VEC cppVar_61286;
	BIT_VEC cppVar_61287;
	BIT_VEC cppVar_61288;
	BIT_VEC cppVar_61289;
	bool cppVar_61290;
	BIT_VEC cppVar_61292;
	BIT_VEC cppVar_61293;
	BIT_VEC cppVar_61294;
	BIT_VEC cppVar_61295;
	bool cppVar_61296;
	BIT_VEC cppVar_61298;
	BIT_VEC cppVar_61299;
	BIT_VEC cppVar_61300;
	BIT_VEC cppVar_61301;
	bool cppVar_61302;
	BIT_VEC cppVar_61304;
	BIT_VEC cppVar_61305;
	BIT_VEC cppVar_61306;
	BIT_VEC cppVar_61307;
	bool cppVar_61308;
	BIT_VEC cppVar_61310;
	BIT_VEC cppVar_61311;
	BIT_VEC cppVar_61312;
	BIT_VEC cppVar_61313;
	bool cppVar_61314;
	BIT_VEC cppVar_61316;
	BIT_VEC cppVar_61317;
	BIT_VEC cppVar_61318;
	BIT_VEC cppVar_61319;
	bool cppVar_61320;
	BIT_VEC cppVar_61322;
	BIT_VEC cppVar_61323;
	BIT_VEC cppVar_61324;
	BIT_VEC cppVar_61325;
	bool cppVar_61326;
	BIT_VEC cppVar_61328;
	BIT_VEC cppVar_61329;
	BIT_VEC cppVar_61330;
	BIT_VEC cppVar_61331;
	bool cppVar_61332;
	BIT_VEC cppVar_61334;
	BIT_VEC cppVar_61335;
	BIT_VEC cppVar_61336;
	BIT_VEC cppVar_61337;
	bool cppVar_61338;
	BIT_VEC cppVar_61340;
	BIT_VEC cppVar_61341;
	BIT_VEC cppVar_61342;
	BIT_VEC cppVar_61343;
	bool cppVar_61344;
	BIT_VEC cppVar_61346;
	BIT_VEC cppVar_61347;
	BIT_VEC cppVar_61348;
	BIT_VEC cppVar_61349;
	bool cppVar_61350;
	BIT_VEC cppVar_61352;
	BIT_VEC cppVar_61353;
	BIT_VEC cppVar_61354;
	BIT_VEC cppVar_61355;
	bool cppVar_61356;
	BIT_VEC cppVar_61358;
	BIT_VEC cppVar_61359;
	BIT_VEC cppVar_61360;
	BIT_VEC cppVar_61361;
	bool cppVar_61362;
	BIT_VEC cppVar_61364;
	BIT_VEC cppVar_61365;
	BIT_VEC cppVar_61366;
	BIT_VEC cppVar_61367;
	bool cppVar_61368;
	BIT_VEC cppVar_61370;
	BIT_VEC cppVar_61371;
	BIT_VEC cppVar_61372;
	BIT_VEC cppVar_61373;
	bool cppVar_61374;
	BIT_VEC cppVar_61376;
	BIT_VEC cppVar_61377;
	BIT_VEC cppVar_61378;
	BIT_VEC cppVar_61379;
	bool cppVar_61380;
	BIT_VEC cppVar_61382;
	BIT_VEC cppVar_61383;
	BIT_VEC cppVar_61384;
	BIT_VEC cppVar_61385;
	bool cppVar_61386;
	BIT_VEC cppVar_61388;
	BIT_VEC cppVar_61389;
	BIT_VEC cppVar_61390;
	BIT_VEC cppVar_61391;
	bool cppVar_61392;
	BIT_VEC cppVar_61394;
	BIT_VEC cppVar_61395;
	BIT_VEC cppVar_61396;
	BIT_VEC cppVar_61397;
	bool cppVar_61398;
	BIT_VEC cppVar_61399;
	BIT_VEC cppVar_61393;
	BIT_VEC cppVar_61387;
	BIT_VEC cppVar_61381;
	BIT_VEC cppVar_61375;
	BIT_VEC cppVar_61369;
	BIT_VEC cppVar_61363;
	BIT_VEC cppVar_61357;
	BIT_VEC cppVar_61351;
	BIT_VEC cppVar_61345;
	BIT_VEC cppVar_61339;
	BIT_VEC cppVar_61333;
	BIT_VEC cppVar_61327;
	BIT_VEC cppVar_61321;
	BIT_VEC cppVar_61315;
	BIT_VEC cppVar_61309;
	BIT_VEC cppVar_61303;
	BIT_VEC cppVar_61297;
	BIT_VEC cppVar_61291;
	BIT_VEC cppVar_61285;
	BIT_VEC cppVar_61279;
	BIT_VEC cppVar_61273;
	BIT_VEC cppVar_61260;
	BIT_VEC cppVar_61254;
	BIT_VEC cppVar_61401;
	BIT_VEC cppVar_61402;
	bool cppVar_61403;
	BIT_VEC cppVar_61405;
	BIT_VEC cppVar_61406;
	BIT_VEC cppVar_61407;
	BIT_VEC cppVar_61408;
	bool cppVar_61409;
	BIT_VEC cppVar_61411;
	BIT_VEC cppVar_61412;
	BIT_VEC cppVar_61413;
	BIT_VEC cppVar_61414;
	BIT_VEC cppVar_61415;
	BIT_VEC cppVar_61416;
	BIT_VEC cppVar_61417;
	bool cppVar_61418;
	BIT_VEC cppVar_61419;
	BIT_VEC cppVar_61420;
	BIT_VEC cppVar_61421;
	BIT_VEC cppVar_61422;
	BIT_VEC cppVar_61424;
	BIT_VEC cppVar_61425;
	BIT_VEC cppVar_61426;
	BIT_VEC cppVar_61427;
	bool cppVar_61428;
	BIT_VEC cppVar_61430;
	BIT_VEC cppVar_61431;
	BIT_VEC cppVar_61432;
	BIT_VEC cppVar_61433;
	bool cppVar_61434;
	BIT_VEC cppVar_61436;
	BIT_VEC cppVar_61437;
	BIT_VEC cppVar_61438;
	BIT_VEC cppVar_61439;
	bool cppVar_61440;
	BIT_VEC cppVar_61442;
	BIT_VEC cppVar_61443;
	BIT_VEC cppVar_61444;
	BIT_VEC cppVar_61445;
	bool cppVar_61446;
	BIT_VEC cppVar_61448;
	BIT_VEC cppVar_61449;
	BIT_VEC cppVar_61450;
	BIT_VEC cppVar_61451;
	bool cppVar_61452;
	BIT_VEC cppVar_61454;
	BIT_VEC cppVar_61455;
	BIT_VEC cppVar_61456;
	BIT_VEC cppVar_61457;
	bool cppVar_61458;
	BIT_VEC cppVar_61460;
	BIT_VEC cppVar_61461;
	BIT_VEC cppVar_61462;
	BIT_VEC cppVar_61463;
	bool cppVar_61464;
	BIT_VEC cppVar_61466;
	BIT_VEC cppVar_61467;
	BIT_VEC cppVar_61468;
	BIT_VEC cppVar_61469;
	bool cppVar_61470;
	BIT_VEC cppVar_61472;
	BIT_VEC cppVar_61473;
	BIT_VEC cppVar_61474;
	BIT_VEC cppVar_61475;
	bool cppVar_61476;
	BIT_VEC cppVar_61478;
	BIT_VEC cppVar_61479;
	BIT_VEC cppVar_61480;
	BIT_VEC cppVar_61481;
	bool cppVar_61482;
	BIT_VEC cppVar_61484;
	BIT_VEC cppVar_61485;
	BIT_VEC cppVar_61486;
	BIT_VEC cppVar_61487;
	bool cppVar_61488;
	BIT_VEC cppVar_61490;
	BIT_VEC cppVar_61491;
	BIT_VEC cppVar_61492;
	BIT_VEC cppVar_61493;
	bool cppVar_61494;
	BIT_VEC cppVar_61496;
	BIT_VEC cppVar_61497;
	BIT_VEC cppVar_61498;
	BIT_VEC cppVar_61499;
	bool cppVar_61500;
	BIT_VEC cppVar_61502;
	BIT_VEC cppVar_61503;
	BIT_VEC cppVar_61504;
	BIT_VEC cppVar_61505;
	bool cppVar_61506;
	BIT_VEC cppVar_61508;
	BIT_VEC cppVar_61509;
	BIT_VEC cppVar_61510;
	BIT_VEC cppVar_61511;
	bool cppVar_61512;
	BIT_VEC cppVar_61514;
	BIT_VEC cppVar_61515;
	BIT_VEC cppVar_61516;
	BIT_VEC cppVar_61517;
	bool cppVar_61518;
	BIT_VEC cppVar_61520;
	BIT_VEC cppVar_61521;
	BIT_VEC cppVar_61522;
	BIT_VEC cppVar_61523;
	bool cppVar_61524;
	BIT_VEC cppVar_61526;
	BIT_VEC cppVar_61527;
	BIT_VEC cppVar_61528;
	BIT_VEC cppVar_61529;
	bool cppVar_61530;
	BIT_VEC cppVar_61532;
	BIT_VEC cppVar_61533;
	BIT_VEC cppVar_61534;
	BIT_VEC cppVar_61535;
	bool cppVar_61536;
	BIT_VEC cppVar_61538;
	BIT_VEC cppVar_61539;
	BIT_VEC cppVar_61540;
	BIT_VEC cppVar_61541;
	bool cppVar_61542;
	BIT_VEC cppVar_61544;
	BIT_VEC cppVar_61545;
	BIT_VEC cppVar_61546;
	BIT_VEC cppVar_61547;
	bool cppVar_61548;
	BIT_VEC cppVar_61549;
	BIT_VEC cppVar_61543;
	BIT_VEC cppVar_61537;
	BIT_VEC cppVar_61531;
	BIT_VEC cppVar_61525;
	BIT_VEC cppVar_61519;
	BIT_VEC cppVar_61513;
	BIT_VEC cppVar_61507;
	BIT_VEC cppVar_61501;
	BIT_VEC cppVar_61495;
	BIT_VEC cppVar_61489;
	BIT_VEC cppVar_61483;
	BIT_VEC cppVar_61477;
	BIT_VEC cppVar_61471;
	BIT_VEC cppVar_61465;
	BIT_VEC cppVar_61459;
	BIT_VEC cppVar_61453;
	BIT_VEC cppVar_61447;
	BIT_VEC cppVar_61441;
	BIT_VEC cppVar_61435;
	BIT_VEC cppVar_61429;
	BIT_VEC cppVar_61423;
	BIT_VEC cppVar_61410;
	BIT_VEC cppVar_61404;
	BIT_VEC cppVar_61551;
	BIT_VEC cppVar_61552;
	bool cppVar_61553;
	BIT_VEC cppVar_61555;
	BIT_VEC cppVar_61556;
	BIT_VEC cppVar_61557;
	BIT_VEC cppVar_61558;
	bool cppVar_61559;
	BIT_VEC cppVar_61561;
	BIT_VEC cppVar_61562;
	BIT_VEC cppVar_61563;
	BIT_VEC cppVar_61564;
	BIT_VEC cppVar_61565;
	BIT_VEC cppVar_61566;
	BIT_VEC cppVar_61567;
	bool cppVar_61568;
	BIT_VEC cppVar_61569;
	BIT_VEC cppVar_61570;
	BIT_VEC cppVar_61571;
	BIT_VEC cppVar_61572;
	BIT_VEC cppVar_61574;
	BIT_VEC cppVar_61575;
	BIT_VEC cppVar_61576;
	BIT_VEC cppVar_61577;
	bool cppVar_61578;
	BIT_VEC cppVar_61580;
	BIT_VEC cppVar_61581;
	BIT_VEC cppVar_61582;
	BIT_VEC cppVar_61583;
	bool cppVar_61584;
	BIT_VEC cppVar_61586;
	BIT_VEC cppVar_61587;
	BIT_VEC cppVar_61588;
	BIT_VEC cppVar_61589;
	bool cppVar_61590;
	BIT_VEC cppVar_61592;
	BIT_VEC cppVar_61593;
	BIT_VEC cppVar_61594;
	BIT_VEC cppVar_61595;
	bool cppVar_61596;
	BIT_VEC cppVar_61598;
	BIT_VEC cppVar_61599;
	BIT_VEC cppVar_61600;
	BIT_VEC cppVar_61601;
	bool cppVar_61602;
	BIT_VEC cppVar_61604;
	BIT_VEC cppVar_61605;
	BIT_VEC cppVar_61606;
	BIT_VEC cppVar_61607;
	bool cppVar_61608;
	BIT_VEC cppVar_61610;
	BIT_VEC cppVar_61611;
	BIT_VEC cppVar_61612;
	BIT_VEC cppVar_61613;
	bool cppVar_61614;
	BIT_VEC cppVar_61616;
	BIT_VEC cppVar_61617;
	BIT_VEC cppVar_61618;
	BIT_VEC cppVar_61619;
	bool cppVar_61620;
	BIT_VEC cppVar_61622;
	BIT_VEC cppVar_61623;
	BIT_VEC cppVar_61624;
	BIT_VEC cppVar_61625;
	bool cppVar_61626;
	BIT_VEC cppVar_61628;
	BIT_VEC cppVar_61629;
	BIT_VEC cppVar_61630;
	BIT_VEC cppVar_61631;
	bool cppVar_61632;
	BIT_VEC cppVar_61634;
	BIT_VEC cppVar_61635;
	BIT_VEC cppVar_61636;
	BIT_VEC cppVar_61637;
	bool cppVar_61638;
	BIT_VEC cppVar_61640;
	BIT_VEC cppVar_61641;
	BIT_VEC cppVar_61642;
	BIT_VEC cppVar_61643;
	bool cppVar_61644;
	BIT_VEC cppVar_61646;
	BIT_VEC cppVar_61647;
	BIT_VEC cppVar_61648;
	BIT_VEC cppVar_61649;
	bool cppVar_61650;
	BIT_VEC cppVar_61652;
	BIT_VEC cppVar_61653;
	BIT_VEC cppVar_61654;
	BIT_VEC cppVar_61655;
	bool cppVar_61656;
	BIT_VEC cppVar_61658;
	BIT_VEC cppVar_61659;
	BIT_VEC cppVar_61660;
	BIT_VEC cppVar_61661;
	bool cppVar_61662;
	BIT_VEC cppVar_61664;
	BIT_VEC cppVar_61665;
	BIT_VEC cppVar_61666;
	BIT_VEC cppVar_61667;
	bool cppVar_61668;
	BIT_VEC cppVar_61670;
	BIT_VEC cppVar_61671;
	BIT_VEC cppVar_61672;
	BIT_VEC cppVar_61673;
	bool cppVar_61674;
	BIT_VEC cppVar_61676;
	BIT_VEC cppVar_61677;
	BIT_VEC cppVar_61678;
	BIT_VEC cppVar_61679;
	bool cppVar_61680;
	BIT_VEC cppVar_61682;
	BIT_VEC cppVar_61683;
	BIT_VEC cppVar_61684;
	BIT_VEC cppVar_61685;
	bool cppVar_61686;
	BIT_VEC cppVar_61688;
	BIT_VEC cppVar_61689;
	BIT_VEC cppVar_61690;
	BIT_VEC cppVar_61691;
	bool cppVar_61692;
	BIT_VEC cppVar_61694;
	BIT_VEC cppVar_61695;
	BIT_VEC cppVar_61696;
	BIT_VEC cppVar_61697;
	bool cppVar_61698;
	BIT_VEC cppVar_61699;
	BIT_VEC cppVar_61693;
	BIT_VEC cppVar_61687;
	BIT_VEC cppVar_61681;
	BIT_VEC cppVar_61675;
	BIT_VEC cppVar_61669;
	BIT_VEC cppVar_61663;
	BIT_VEC cppVar_61657;
	BIT_VEC cppVar_61651;
	BIT_VEC cppVar_61645;
	BIT_VEC cppVar_61639;
	BIT_VEC cppVar_61633;
	BIT_VEC cppVar_61627;
	BIT_VEC cppVar_61621;
	BIT_VEC cppVar_61615;
	BIT_VEC cppVar_61609;
	BIT_VEC cppVar_61603;
	BIT_VEC cppVar_61597;
	BIT_VEC cppVar_61591;
	BIT_VEC cppVar_61585;
	BIT_VEC cppVar_61579;
	BIT_VEC cppVar_61573;
	BIT_VEC cppVar_61560;
	BIT_VEC cppVar_61554;
	BIT_VEC cppVar_61701;
	BIT_VEC cppVar_61702;
	bool cppVar_61703;
	BIT_VEC cppVar_61705;
	BIT_VEC cppVar_61706;
	BIT_VEC cppVar_61707;
	BIT_VEC cppVar_61708;
	bool cppVar_61709;
	BIT_VEC cppVar_61711;
	BIT_VEC cppVar_61712;
	BIT_VEC cppVar_61713;
	BIT_VEC cppVar_61714;
	BIT_VEC cppVar_61715;
	BIT_VEC cppVar_61716;
	BIT_VEC cppVar_61717;
	bool cppVar_61718;
	BIT_VEC cppVar_61719;
	BIT_VEC cppVar_61720;
	BIT_VEC cppVar_61721;
	BIT_VEC cppVar_61722;
	BIT_VEC cppVar_61724;
	BIT_VEC cppVar_61725;
	BIT_VEC cppVar_61726;
	BIT_VEC cppVar_61727;
	bool cppVar_61728;
	BIT_VEC cppVar_61730;
	BIT_VEC cppVar_61731;
	BIT_VEC cppVar_61732;
	BIT_VEC cppVar_61733;
	bool cppVar_61734;
	BIT_VEC cppVar_61736;
	BIT_VEC cppVar_61737;
	BIT_VEC cppVar_61738;
	BIT_VEC cppVar_61739;
	bool cppVar_61740;
	BIT_VEC cppVar_61742;
	BIT_VEC cppVar_61743;
	BIT_VEC cppVar_61744;
	BIT_VEC cppVar_61745;
	bool cppVar_61746;
	BIT_VEC cppVar_61748;
	BIT_VEC cppVar_61749;
	BIT_VEC cppVar_61750;
	BIT_VEC cppVar_61751;
	bool cppVar_61752;
	BIT_VEC cppVar_61754;
	BIT_VEC cppVar_61755;
	BIT_VEC cppVar_61756;
	BIT_VEC cppVar_61757;
	bool cppVar_61758;
	BIT_VEC cppVar_61760;
	BIT_VEC cppVar_61761;
	BIT_VEC cppVar_61762;
	BIT_VEC cppVar_61763;
	bool cppVar_61764;
	BIT_VEC cppVar_61766;
	BIT_VEC cppVar_61767;
	BIT_VEC cppVar_61768;
	BIT_VEC cppVar_61769;
	bool cppVar_61770;
	BIT_VEC cppVar_61772;
	BIT_VEC cppVar_61773;
	BIT_VEC cppVar_61774;
	BIT_VEC cppVar_61775;
	bool cppVar_61776;
	BIT_VEC cppVar_61778;
	BIT_VEC cppVar_61779;
	BIT_VEC cppVar_61780;
	BIT_VEC cppVar_61781;
	bool cppVar_61782;
	BIT_VEC cppVar_61784;
	BIT_VEC cppVar_61785;
	BIT_VEC cppVar_61786;
	BIT_VEC cppVar_61787;
	bool cppVar_61788;
	BIT_VEC cppVar_61790;
	BIT_VEC cppVar_61791;
	BIT_VEC cppVar_61792;
	BIT_VEC cppVar_61793;
	bool cppVar_61794;
	BIT_VEC cppVar_61796;
	BIT_VEC cppVar_61797;
	BIT_VEC cppVar_61798;
	BIT_VEC cppVar_61799;
	bool cppVar_61800;
	BIT_VEC cppVar_61802;
	BIT_VEC cppVar_61803;
	BIT_VEC cppVar_61804;
	BIT_VEC cppVar_61805;
	bool cppVar_61806;
	BIT_VEC cppVar_61808;
	BIT_VEC cppVar_61809;
	BIT_VEC cppVar_61810;
	BIT_VEC cppVar_61811;
	bool cppVar_61812;
	BIT_VEC cppVar_61814;
	BIT_VEC cppVar_61815;
	BIT_VEC cppVar_61816;
	BIT_VEC cppVar_61817;
	bool cppVar_61818;
	BIT_VEC cppVar_61820;
	BIT_VEC cppVar_61821;
	BIT_VEC cppVar_61822;
	BIT_VEC cppVar_61823;
	bool cppVar_61824;
	BIT_VEC cppVar_61826;
	BIT_VEC cppVar_61827;
	BIT_VEC cppVar_61828;
	BIT_VEC cppVar_61829;
	bool cppVar_61830;
	BIT_VEC cppVar_61832;
	BIT_VEC cppVar_61833;
	BIT_VEC cppVar_61834;
	BIT_VEC cppVar_61835;
	bool cppVar_61836;
	BIT_VEC cppVar_61838;
	BIT_VEC cppVar_61839;
	BIT_VEC cppVar_61840;
	BIT_VEC cppVar_61841;
	bool cppVar_61842;
	BIT_VEC cppVar_61844;
	BIT_VEC cppVar_61845;
	BIT_VEC cppVar_61846;
	BIT_VEC cppVar_61847;
	bool cppVar_61848;
	BIT_VEC cppVar_61849;
	BIT_VEC cppVar_61843;
	BIT_VEC cppVar_61837;
	BIT_VEC cppVar_61831;
	BIT_VEC cppVar_61825;
	BIT_VEC cppVar_61819;
	BIT_VEC cppVar_61813;
	BIT_VEC cppVar_61807;
	BIT_VEC cppVar_61801;
	BIT_VEC cppVar_61795;
	BIT_VEC cppVar_61789;
	BIT_VEC cppVar_61783;
	BIT_VEC cppVar_61777;
	BIT_VEC cppVar_61771;
	BIT_VEC cppVar_61765;
	BIT_VEC cppVar_61759;
	BIT_VEC cppVar_61753;
	BIT_VEC cppVar_61747;
	BIT_VEC cppVar_61741;
	BIT_VEC cppVar_61735;
	BIT_VEC cppVar_61729;
	BIT_VEC cppVar_61723;
	BIT_VEC cppVar_61710;
	BIT_VEC cppVar_61704;
	BIT_VEC cppVar_61851;
	BIT_VEC cppVar_61852;
	bool cppVar_61853;
	BIT_VEC cppVar_61855;
	BIT_VEC cppVar_61856;
	BIT_VEC cppVar_61857;
	BIT_VEC cppVar_61858;
	bool cppVar_61859;
	BIT_VEC cppVar_61861;
	BIT_VEC cppVar_61862;
	BIT_VEC cppVar_61863;
	BIT_VEC cppVar_61864;
	BIT_VEC cppVar_61865;
	BIT_VEC cppVar_61866;
	BIT_VEC cppVar_61867;
	bool cppVar_61868;
	BIT_VEC cppVar_61869;
	BIT_VEC cppVar_61870;
	BIT_VEC cppVar_61871;
	BIT_VEC cppVar_61872;
	BIT_VEC cppVar_61874;
	BIT_VEC cppVar_61875;
	BIT_VEC cppVar_61876;
	BIT_VEC cppVar_61877;
	bool cppVar_61878;
	BIT_VEC cppVar_61880;
	BIT_VEC cppVar_61881;
	BIT_VEC cppVar_61882;
	BIT_VEC cppVar_61883;
	bool cppVar_61884;
	BIT_VEC cppVar_61886;
	BIT_VEC cppVar_61887;
	BIT_VEC cppVar_61888;
	BIT_VEC cppVar_61889;
	bool cppVar_61890;
	BIT_VEC cppVar_61892;
	BIT_VEC cppVar_61893;
	BIT_VEC cppVar_61894;
	BIT_VEC cppVar_61895;
	bool cppVar_61896;
	BIT_VEC cppVar_61898;
	BIT_VEC cppVar_61899;
	BIT_VEC cppVar_61900;
	BIT_VEC cppVar_61901;
	bool cppVar_61902;
	BIT_VEC cppVar_61904;
	BIT_VEC cppVar_61905;
	BIT_VEC cppVar_61906;
	BIT_VEC cppVar_61907;
	bool cppVar_61908;
	BIT_VEC cppVar_61910;
	BIT_VEC cppVar_61911;
	BIT_VEC cppVar_61912;
	BIT_VEC cppVar_61913;
	bool cppVar_61914;
	BIT_VEC cppVar_61916;
	BIT_VEC cppVar_61917;
	BIT_VEC cppVar_61918;
	BIT_VEC cppVar_61919;
	bool cppVar_61920;
	BIT_VEC cppVar_61922;
	BIT_VEC cppVar_61923;
	BIT_VEC cppVar_61924;
	BIT_VEC cppVar_61925;
	bool cppVar_61926;
	BIT_VEC cppVar_61928;
	BIT_VEC cppVar_61929;
	BIT_VEC cppVar_61930;
	BIT_VEC cppVar_61931;
	bool cppVar_61932;
	BIT_VEC cppVar_61934;
	BIT_VEC cppVar_61935;
	BIT_VEC cppVar_61936;
	BIT_VEC cppVar_61937;
	bool cppVar_61938;
	BIT_VEC cppVar_61940;
	BIT_VEC cppVar_61941;
	BIT_VEC cppVar_61942;
	BIT_VEC cppVar_61943;
	bool cppVar_61944;
	BIT_VEC cppVar_61946;
	BIT_VEC cppVar_61947;
	BIT_VEC cppVar_61948;
	BIT_VEC cppVar_61949;
	bool cppVar_61950;
	BIT_VEC cppVar_61952;
	BIT_VEC cppVar_61953;
	BIT_VEC cppVar_61954;
	BIT_VEC cppVar_61955;
	bool cppVar_61956;
	BIT_VEC cppVar_61958;
	BIT_VEC cppVar_61959;
	BIT_VEC cppVar_61960;
	BIT_VEC cppVar_61961;
	bool cppVar_61962;
	BIT_VEC cppVar_61964;
	BIT_VEC cppVar_61965;
	BIT_VEC cppVar_61966;
	BIT_VEC cppVar_61967;
	bool cppVar_61968;
	BIT_VEC cppVar_61970;
	BIT_VEC cppVar_61971;
	BIT_VEC cppVar_61972;
	BIT_VEC cppVar_61973;
	bool cppVar_61974;
	BIT_VEC cppVar_61976;
	BIT_VEC cppVar_61977;
	BIT_VEC cppVar_61978;
	BIT_VEC cppVar_61979;
	bool cppVar_61980;
	BIT_VEC cppVar_61982;
	BIT_VEC cppVar_61983;
	BIT_VEC cppVar_61984;
	BIT_VEC cppVar_61985;
	bool cppVar_61986;
	BIT_VEC cppVar_61988;
	BIT_VEC cppVar_61989;
	BIT_VEC cppVar_61990;
	BIT_VEC cppVar_61991;
	bool cppVar_61992;
	BIT_VEC cppVar_61994;
	BIT_VEC cppVar_61995;
	BIT_VEC cppVar_61996;
	BIT_VEC cppVar_61997;
	bool cppVar_61998;
	BIT_VEC cppVar_61999;
	BIT_VEC cppVar_61993;
	BIT_VEC cppVar_61987;
	BIT_VEC cppVar_61981;
	BIT_VEC cppVar_61975;
	BIT_VEC cppVar_61969;
	BIT_VEC cppVar_61963;
	BIT_VEC cppVar_61957;
	BIT_VEC cppVar_61951;
	BIT_VEC cppVar_61945;
	BIT_VEC cppVar_61939;
	BIT_VEC cppVar_61933;
	BIT_VEC cppVar_61927;
	BIT_VEC cppVar_61921;
	BIT_VEC cppVar_61915;
	BIT_VEC cppVar_61909;
	BIT_VEC cppVar_61903;
	BIT_VEC cppVar_61897;
	BIT_VEC cppVar_61891;
	BIT_VEC cppVar_61885;
	BIT_VEC cppVar_61879;
	BIT_VEC cppVar_61873;
	BIT_VEC cppVar_61860;
	BIT_VEC cppVar_61854;
	BIT_VEC cppVar_62001;
	BIT_VEC cppVar_62002;
	bool cppVar_62003;
	BIT_VEC cppVar_62005;
	BIT_VEC cppVar_62006;
	BIT_VEC cppVar_62007;
	BIT_VEC cppVar_62008;
	bool cppVar_62009;
	BIT_VEC cppVar_62011;
	BIT_VEC cppVar_62012;
	BIT_VEC cppVar_62013;
	BIT_VEC cppVar_62014;
	BIT_VEC cppVar_62015;
	BIT_VEC cppVar_62016;
	BIT_VEC cppVar_62017;
	bool cppVar_62018;
	BIT_VEC cppVar_62019;
	BIT_VEC cppVar_62020;
	BIT_VEC cppVar_62021;
	BIT_VEC cppVar_62022;
	BIT_VEC cppVar_62024;
	BIT_VEC cppVar_62025;
	BIT_VEC cppVar_62026;
	BIT_VEC cppVar_62027;
	bool cppVar_62028;
	BIT_VEC cppVar_62030;
	BIT_VEC cppVar_62031;
	BIT_VEC cppVar_62032;
	BIT_VEC cppVar_62033;
	bool cppVar_62034;
	BIT_VEC cppVar_62036;
	BIT_VEC cppVar_62037;
	BIT_VEC cppVar_62038;
	BIT_VEC cppVar_62039;
	bool cppVar_62040;
	BIT_VEC cppVar_62042;
	BIT_VEC cppVar_62043;
	BIT_VEC cppVar_62044;
	BIT_VEC cppVar_62045;
	bool cppVar_62046;
	BIT_VEC cppVar_62048;
	BIT_VEC cppVar_62049;
	BIT_VEC cppVar_62050;
	BIT_VEC cppVar_62051;
	bool cppVar_62052;
	BIT_VEC cppVar_62054;
	BIT_VEC cppVar_62055;
	BIT_VEC cppVar_62056;
	BIT_VEC cppVar_62057;
	bool cppVar_62058;
	BIT_VEC cppVar_62060;
	BIT_VEC cppVar_62061;
	BIT_VEC cppVar_62062;
	BIT_VEC cppVar_62063;
	bool cppVar_62064;
	BIT_VEC cppVar_62066;
	BIT_VEC cppVar_62067;
	BIT_VEC cppVar_62068;
	BIT_VEC cppVar_62069;
	bool cppVar_62070;
	BIT_VEC cppVar_62072;
	BIT_VEC cppVar_62073;
	BIT_VEC cppVar_62074;
	BIT_VEC cppVar_62075;
	bool cppVar_62076;
	BIT_VEC cppVar_62078;
	BIT_VEC cppVar_62079;
	BIT_VEC cppVar_62080;
	BIT_VEC cppVar_62081;
	bool cppVar_62082;
	BIT_VEC cppVar_62084;
	BIT_VEC cppVar_62085;
	BIT_VEC cppVar_62086;
	BIT_VEC cppVar_62087;
	bool cppVar_62088;
	BIT_VEC cppVar_62090;
	BIT_VEC cppVar_62091;
	BIT_VEC cppVar_62092;
	BIT_VEC cppVar_62093;
	bool cppVar_62094;
	BIT_VEC cppVar_62096;
	BIT_VEC cppVar_62097;
	BIT_VEC cppVar_62098;
	BIT_VEC cppVar_62099;
	bool cppVar_62100;
	BIT_VEC cppVar_62102;
	BIT_VEC cppVar_62103;
	BIT_VEC cppVar_62104;
	BIT_VEC cppVar_62105;
	bool cppVar_62106;
	BIT_VEC cppVar_62108;
	BIT_VEC cppVar_62109;
	BIT_VEC cppVar_62110;
	BIT_VEC cppVar_62111;
	bool cppVar_62112;
	BIT_VEC cppVar_62114;
	BIT_VEC cppVar_62115;
	BIT_VEC cppVar_62116;
	BIT_VEC cppVar_62117;
	bool cppVar_62118;
	BIT_VEC cppVar_62120;
	BIT_VEC cppVar_62121;
	BIT_VEC cppVar_62122;
	BIT_VEC cppVar_62123;
	bool cppVar_62124;
	BIT_VEC cppVar_62126;
	BIT_VEC cppVar_62127;
	BIT_VEC cppVar_62128;
	BIT_VEC cppVar_62129;
	bool cppVar_62130;
	BIT_VEC cppVar_62132;
	BIT_VEC cppVar_62133;
	BIT_VEC cppVar_62134;
	BIT_VEC cppVar_62135;
	bool cppVar_62136;
	BIT_VEC cppVar_62138;
	BIT_VEC cppVar_62139;
	BIT_VEC cppVar_62140;
	BIT_VEC cppVar_62141;
	bool cppVar_62142;
	BIT_VEC cppVar_62144;
	BIT_VEC cppVar_62145;
	BIT_VEC cppVar_62146;
	BIT_VEC cppVar_62147;
	bool cppVar_62148;
	BIT_VEC cppVar_62149;
	BIT_VEC cppVar_62143;
	BIT_VEC cppVar_62137;
	BIT_VEC cppVar_62131;
	BIT_VEC cppVar_62125;
	BIT_VEC cppVar_62119;
	BIT_VEC cppVar_62113;
	BIT_VEC cppVar_62107;
	BIT_VEC cppVar_62101;
	BIT_VEC cppVar_62095;
	BIT_VEC cppVar_62089;
	BIT_VEC cppVar_62083;
	BIT_VEC cppVar_62077;
	BIT_VEC cppVar_62071;
	BIT_VEC cppVar_62065;
	BIT_VEC cppVar_62059;
	BIT_VEC cppVar_62053;
	BIT_VEC cppVar_62047;
	BIT_VEC cppVar_62041;
	BIT_VEC cppVar_62035;
	BIT_VEC cppVar_62029;
	BIT_VEC cppVar_62023;
	BIT_VEC cppVar_62010;
	BIT_VEC cppVar_62004;
	BIT_VEC cppVar_62151;
	BIT_VEC cppVar_62152;
	bool cppVar_62153;
	BIT_VEC cppVar_62155;
	BIT_VEC cppVar_62156;
	BIT_VEC cppVar_62157;
	BIT_VEC cppVar_62158;
	bool cppVar_62159;
	BIT_VEC cppVar_62161;
	BIT_VEC cppVar_62162;
	BIT_VEC cppVar_62163;
	BIT_VEC cppVar_62164;
	BIT_VEC cppVar_62165;
	BIT_VEC cppVar_62166;
	BIT_VEC cppVar_62167;
	bool cppVar_62168;
	BIT_VEC cppVar_62169;
	BIT_VEC cppVar_62170;
	BIT_VEC cppVar_62171;
	BIT_VEC cppVar_62172;
	BIT_VEC cppVar_62174;
	BIT_VEC cppVar_62175;
	BIT_VEC cppVar_62176;
	BIT_VEC cppVar_62177;
	bool cppVar_62178;
	BIT_VEC cppVar_62180;
	BIT_VEC cppVar_62181;
	BIT_VEC cppVar_62182;
	BIT_VEC cppVar_62183;
	bool cppVar_62184;
	BIT_VEC cppVar_62186;
	BIT_VEC cppVar_62187;
	BIT_VEC cppVar_62188;
	BIT_VEC cppVar_62189;
	bool cppVar_62190;
	BIT_VEC cppVar_62192;
	BIT_VEC cppVar_62193;
	BIT_VEC cppVar_62194;
	BIT_VEC cppVar_62195;
	bool cppVar_62196;
	BIT_VEC cppVar_62198;
	BIT_VEC cppVar_62199;
	BIT_VEC cppVar_62200;
	BIT_VEC cppVar_62201;
	bool cppVar_62202;
	BIT_VEC cppVar_62204;
	BIT_VEC cppVar_62205;
	BIT_VEC cppVar_62206;
	BIT_VEC cppVar_62207;
	bool cppVar_62208;
	BIT_VEC cppVar_62210;
	BIT_VEC cppVar_62211;
	BIT_VEC cppVar_62212;
	BIT_VEC cppVar_62213;
	bool cppVar_62214;
	BIT_VEC cppVar_62216;
	BIT_VEC cppVar_62217;
	BIT_VEC cppVar_62218;
	BIT_VEC cppVar_62219;
	bool cppVar_62220;
	BIT_VEC cppVar_62222;
	BIT_VEC cppVar_62223;
	BIT_VEC cppVar_62224;
	BIT_VEC cppVar_62225;
	bool cppVar_62226;
	BIT_VEC cppVar_62228;
	BIT_VEC cppVar_62229;
	BIT_VEC cppVar_62230;
	BIT_VEC cppVar_62231;
	bool cppVar_62232;
	BIT_VEC cppVar_62234;
	BIT_VEC cppVar_62235;
	BIT_VEC cppVar_62236;
	BIT_VEC cppVar_62237;
	bool cppVar_62238;
	BIT_VEC cppVar_62240;
	BIT_VEC cppVar_62241;
	BIT_VEC cppVar_62242;
	BIT_VEC cppVar_62243;
	bool cppVar_62244;
	BIT_VEC cppVar_62246;
	BIT_VEC cppVar_62247;
	BIT_VEC cppVar_62248;
	BIT_VEC cppVar_62249;
	bool cppVar_62250;
	BIT_VEC cppVar_62252;
	BIT_VEC cppVar_62253;
	BIT_VEC cppVar_62254;
	BIT_VEC cppVar_62255;
	bool cppVar_62256;
	BIT_VEC cppVar_62258;
	BIT_VEC cppVar_62259;
	BIT_VEC cppVar_62260;
	BIT_VEC cppVar_62261;
	bool cppVar_62262;
	BIT_VEC cppVar_62264;
	BIT_VEC cppVar_62265;
	BIT_VEC cppVar_62266;
	BIT_VEC cppVar_62267;
	bool cppVar_62268;
	BIT_VEC cppVar_62270;
	BIT_VEC cppVar_62271;
	BIT_VEC cppVar_62272;
	BIT_VEC cppVar_62273;
	bool cppVar_62274;
	BIT_VEC cppVar_62276;
	BIT_VEC cppVar_62277;
	BIT_VEC cppVar_62278;
	BIT_VEC cppVar_62279;
	bool cppVar_62280;
	BIT_VEC cppVar_62282;
	BIT_VEC cppVar_62283;
	BIT_VEC cppVar_62284;
	BIT_VEC cppVar_62285;
	bool cppVar_62286;
	BIT_VEC cppVar_62288;
	BIT_VEC cppVar_62289;
	BIT_VEC cppVar_62290;
	BIT_VEC cppVar_62291;
	bool cppVar_62292;
	BIT_VEC cppVar_62294;
	BIT_VEC cppVar_62295;
	BIT_VEC cppVar_62296;
	BIT_VEC cppVar_62297;
	bool cppVar_62298;
	BIT_VEC cppVar_62299;
	BIT_VEC cppVar_62293;
	BIT_VEC cppVar_62287;
	BIT_VEC cppVar_62281;
	BIT_VEC cppVar_62275;
	BIT_VEC cppVar_62269;
	BIT_VEC cppVar_62263;
	BIT_VEC cppVar_62257;
	BIT_VEC cppVar_62251;
	BIT_VEC cppVar_62245;
	BIT_VEC cppVar_62239;
	BIT_VEC cppVar_62233;
	BIT_VEC cppVar_62227;
	BIT_VEC cppVar_62221;
	BIT_VEC cppVar_62215;
	BIT_VEC cppVar_62209;
	BIT_VEC cppVar_62203;
	BIT_VEC cppVar_62197;
	BIT_VEC cppVar_62191;
	BIT_VEC cppVar_62185;
	BIT_VEC cppVar_62179;
	BIT_VEC cppVar_62173;
	BIT_VEC cppVar_62160;
	BIT_VEC cppVar_62154;
	BIT_VEC cppVar_62301;
	BIT_VEC cppVar_62302;
	bool cppVar_62303;
	BIT_VEC cppVar_62305;
	BIT_VEC cppVar_62306;
	BIT_VEC cppVar_62307;
	BIT_VEC cppVar_62308;
	bool cppVar_62309;
	BIT_VEC cppVar_62311;
	BIT_VEC cppVar_62312;
	BIT_VEC cppVar_62313;
	BIT_VEC cppVar_62314;
	BIT_VEC cppVar_62315;
	BIT_VEC cppVar_62316;
	BIT_VEC cppVar_62317;
	bool cppVar_62318;
	BIT_VEC cppVar_62319;
	BIT_VEC cppVar_62320;
	BIT_VEC cppVar_62321;
	BIT_VEC cppVar_62322;
	BIT_VEC cppVar_62324;
	BIT_VEC cppVar_62325;
	BIT_VEC cppVar_62326;
	BIT_VEC cppVar_62327;
	bool cppVar_62328;
	BIT_VEC cppVar_62330;
	BIT_VEC cppVar_62331;
	BIT_VEC cppVar_62332;
	BIT_VEC cppVar_62333;
	bool cppVar_62334;
	BIT_VEC cppVar_62336;
	BIT_VEC cppVar_62337;
	BIT_VEC cppVar_62338;
	BIT_VEC cppVar_62339;
	bool cppVar_62340;
	BIT_VEC cppVar_62342;
	BIT_VEC cppVar_62343;
	BIT_VEC cppVar_62344;
	BIT_VEC cppVar_62345;
	bool cppVar_62346;
	BIT_VEC cppVar_62348;
	BIT_VEC cppVar_62349;
	BIT_VEC cppVar_62350;
	BIT_VEC cppVar_62351;
	bool cppVar_62352;
	BIT_VEC cppVar_62354;
	BIT_VEC cppVar_62355;
	BIT_VEC cppVar_62356;
	BIT_VEC cppVar_62357;
	bool cppVar_62358;
	BIT_VEC cppVar_62360;
	BIT_VEC cppVar_62361;
	BIT_VEC cppVar_62362;
	BIT_VEC cppVar_62363;
	bool cppVar_62364;
	BIT_VEC cppVar_62366;
	BIT_VEC cppVar_62367;
	BIT_VEC cppVar_62368;
	BIT_VEC cppVar_62369;
	bool cppVar_62370;
	BIT_VEC cppVar_62372;
	BIT_VEC cppVar_62373;
	BIT_VEC cppVar_62374;
	BIT_VEC cppVar_62375;
	bool cppVar_62376;
	BIT_VEC cppVar_62378;
	BIT_VEC cppVar_62379;
	BIT_VEC cppVar_62380;
	BIT_VEC cppVar_62381;
	bool cppVar_62382;
	BIT_VEC cppVar_62384;
	BIT_VEC cppVar_62385;
	BIT_VEC cppVar_62386;
	BIT_VEC cppVar_62387;
	bool cppVar_62388;
	BIT_VEC cppVar_62390;
	BIT_VEC cppVar_62391;
	BIT_VEC cppVar_62392;
	BIT_VEC cppVar_62393;
	bool cppVar_62394;
	BIT_VEC cppVar_62396;
	BIT_VEC cppVar_62397;
	BIT_VEC cppVar_62398;
	BIT_VEC cppVar_62399;
	bool cppVar_62400;
	BIT_VEC cppVar_62402;
	BIT_VEC cppVar_62403;
	BIT_VEC cppVar_62404;
	BIT_VEC cppVar_62405;
	bool cppVar_62406;
	BIT_VEC cppVar_62408;
	BIT_VEC cppVar_62409;
	BIT_VEC cppVar_62410;
	BIT_VEC cppVar_62411;
	bool cppVar_62412;
	BIT_VEC cppVar_62414;
	BIT_VEC cppVar_62415;
	BIT_VEC cppVar_62416;
	BIT_VEC cppVar_62417;
	bool cppVar_62418;
	BIT_VEC cppVar_62420;
	BIT_VEC cppVar_62421;
	BIT_VEC cppVar_62422;
	BIT_VEC cppVar_62423;
	bool cppVar_62424;
	BIT_VEC cppVar_62426;
	BIT_VEC cppVar_62427;
	BIT_VEC cppVar_62428;
	BIT_VEC cppVar_62429;
	bool cppVar_62430;
	BIT_VEC cppVar_62432;
	BIT_VEC cppVar_62433;
	BIT_VEC cppVar_62434;
	BIT_VEC cppVar_62435;
	bool cppVar_62436;
	BIT_VEC cppVar_62438;
	BIT_VEC cppVar_62439;
	BIT_VEC cppVar_62440;
	BIT_VEC cppVar_62441;
	bool cppVar_62442;
	BIT_VEC cppVar_62444;
	BIT_VEC cppVar_62445;
	BIT_VEC cppVar_62446;
	BIT_VEC cppVar_62447;
	bool cppVar_62448;
	BIT_VEC cppVar_62449;
	BIT_VEC cppVar_62443;
	BIT_VEC cppVar_62437;
	BIT_VEC cppVar_62431;
	BIT_VEC cppVar_62425;
	BIT_VEC cppVar_62419;
	BIT_VEC cppVar_62413;
	BIT_VEC cppVar_62407;
	BIT_VEC cppVar_62401;
	BIT_VEC cppVar_62395;
	BIT_VEC cppVar_62389;
	BIT_VEC cppVar_62383;
	BIT_VEC cppVar_62377;
	BIT_VEC cppVar_62371;
	BIT_VEC cppVar_62365;
	BIT_VEC cppVar_62359;
	BIT_VEC cppVar_62353;
	BIT_VEC cppVar_62347;
	BIT_VEC cppVar_62341;
	BIT_VEC cppVar_62335;
	BIT_VEC cppVar_62329;
	BIT_VEC cppVar_62323;
	BIT_VEC cppVar_62310;
	BIT_VEC cppVar_62304;
	BIT_VEC cppVar_62451;
	BIT_VEC cppVar_62452;
	bool cppVar_62453;
	BIT_VEC cppVar_62455;
	BIT_VEC cppVar_62456;
	BIT_VEC cppVar_62457;
	BIT_VEC cppVar_62458;
	bool cppVar_62459;
	BIT_VEC cppVar_62460;
	BIT_VEC cppVar_62461;
	BIT_VEC cppVar_62462;
	BIT_VEC cppVar_62463;
	BIT_VEC cppVar_62464;
	BIT_VEC cppVar_62465;
	BIT_VEC cppVar_62466;
	BIT_VEC cppVar_62454;
	BIT_VEC cppVar_62468;
	BIT_VEC cppVar_62469;
	bool cppVar_62470;
	BIT_VEC cppVar_62472;
	BIT_VEC cppVar_62473;
	BIT_VEC cppVar_62474;
	BIT_VEC cppVar_62475;
	bool cppVar_62476;
	BIT_VEC cppVar_62477;
	BIT_VEC cppVar_62478;
	BIT_VEC cppVar_62479;
	BIT_VEC cppVar_62480;
	BIT_VEC cppVar_62481;
	BIT_VEC cppVar_62482;
	BIT_VEC cppVar_62483;
	BIT_VEC cppVar_62471;
	BIT_VEC cppVar_62485;
	BIT_VEC cppVar_62486;
	bool cppVar_62487;
	BIT_VEC cppVar_62489;
	BIT_VEC cppVar_62490;
	BIT_VEC cppVar_62491;
	BIT_VEC cppVar_62492;
	bool cppVar_62493;
	BIT_VEC cppVar_62495;
	BIT_VEC cppVar_62496;
	BIT_VEC cppVar_62497;
	BIT_VEC cppVar_62498;
	BIT_VEC cppVar_62499;
	bool cppVar_62500;
	BIT_VEC cppVar_62501;
	BIT_VEC cppVar_62502;
	BIT_VEC cppVar_62503;
	BIT_VEC cppVar_62505;
	BIT_VEC cppVar_62506;
	BIT_VEC cppVar_62507;
	bool cppVar_62508;
	BIT_VEC cppVar_62510;
	BIT_VEC cppVar_62511;
	BIT_VEC cppVar_62512;
	bool cppVar_62513;
	BIT_VEC cppVar_62515;
	BIT_VEC cppVar_62516;
	BIT_VEC cppVar_62517;
	bool cppVar_62518;
	BIT_VEC cppVar_62520;
	BIT_VEC cppVar_62521;
	BIT_VEC cppVar_62522;
	bool cppVar_62523;
	BIT_VEC cppVar_62525;
	BIT_VEC cppVar_62526;
	BIT_VEC cppVar_62527;
	bool cppVar_62528;
	BIT_VEC cppVar_62530;
	BIT_VEC cppVar_62531;
	BIT_VEC cppVar_62532;
	bool cppVar_62533;
	BIT_VEC cppVar_62535;
	BIT_VEC cppVar_62536;
	BIT_VEC cppVar_62537;
	bool cppVar_62538;
	BIT_VEC cppVar_62540;
	BIT_VEC cppVar_62541;
	BIT_VEC cppVar_62542;
	bool cppVar_62543;
	BIT_VEC cppVar_62545;
	BIT_VEC cppVar_62546;
	BIT_VEC cppVar_62547;
	bool cppVar_62548;
	BIT_VEC cppVar_62550;
	BIT_VEC cppVar_62551;
	BIT_VEC cppVar_62552;
	bool cppVar_62553;
	BIT_VEC cppVar_62555;
	BIT_VEC cppVar_62556;
	BIT_VEC cppVar_62557;
	bool cppVar_62558;
	BIT_VEC cppVar_62560;
	BIT_VEC cppVar_62561;
	BIT_VEC cppVar_62562;
	bool cppVar_62563;
	BIT_VEC cppVar_62565;
	BIT_VEC cppVar_62566;
	BIT_VEC cppVar_62567;
	bool cppVar_62568;
	BIT_VEC cppVar_62570;
	BIT_VEC cppVar_62571;
	BIT_VEC cppVar_62572;
	bool cppVar_62573;
	BIT_VEC cppVar_62575;
	BIT_VEC cppVar_62576;
	BIT_VEC cppVar_62577;
	bool cppVar_62578;
	BIT_VEC cppVar_62580;
	BIT_VEC cppVar_62581;
	BIT_VEC cppVar_62582;
	bool cppVar_62583;
	BIT_VEC cppVar_62585;
	BIT_VEC cppVar_62586;
	BIT_VEC cppVar_62587;
	bool cppVar_62588;
	BIT_VEC cppVar_62590;
	BIT_VEC cppVar_62591;
	BIT_VEC cppVar_62592;
	bool cppVar_62593;
	BIT_VEC cppVar_62595;
	BIT_VEC cppVar_62596;
	BIT_VEC cppVar_62597;
	bool cppVar_62598;
	BIT_VEC cppVar_62600;
	BIT_VEC cppVar_62601;
	BIT_VEC cppVar_62602;
	bool cppVar_62603;
	BIT_VEC cppVar_62605;
	BIT_VEC cppVar_62606;
	BIT_VEC cppVar_62607;
	bool cppVar_62608;
	BIT_VEC cppVar_62609;
	BIT_VEC cppVar_62604;
	BIT_VEC cppVar_62599;
	BIT_VEC cppVar_62594;
	BIT_VEC cppVar_62589;
	BIT_VEC cppVar_62584;
	BIT_VEC cppVar_62579;
	BIT_VEC cppVar_62574;
	BIT_VEC cppVar_62569;
	BIT_VEC cppVar_62564;
	BIT_VEC cppVar_62559;
	BIT_VEC cppVar_62554;
	BIT_VEC cppVar_62549;
	BIT_VEC cppVar_62544;
	BIT_VEC cppVar_62539;
	BIT_VEC cppVar_62534;
	BIT_VEC cppVar_62529;
	BIT_VEC cppVar_62524;
	BIT_VEC cppVar_62519;
	BIT_VEC cppVar_62514;
	BIT_VEC cppVar_62509;
	BIT_VEC cppVar_62504;
	BIT_VEC cppVar_62494;
	BIT_VEC cppVar_62488;
	BIT_VEC cppVar_62611;
	BIT_VEC cppVar_62612;
	bool cppVar_62613;
	BIT_VEC cppVar_62615;
	BIT_VEC cppVar_62616;
	BIT_VEC cppVar_62617;
	BIT_VEC cppVar_62618;
	bool cppVar_62619;
	BIT_VEC cppVar_62620;
	BIT_VEC cppVar_62621;
	BIT_VEC cppVar_62622;
	BIT_VEC cppVar_62614;
	BIT_VEC cppVar_62624;
	BIT_VEC cppVar_62625;
	bool cppVar_62626;
	BIT_VEC cppVar_62628;
	BIT_VEC cppVar_62629;
	BIT_VEC cppVar_62630;
	BIT_VEC cppVar_62631;
	bool cppVar_62632;
	BIT_VEC cppVar_62634;
	BIT_VEC cppVar_62635;
	BIT_VEC cppVar_62636;
	BIT_VEC cppVar_62637;
	bool cppVar_62638;
	BIT_VEC cppVar_62639;
	BIT_VEC cppVar_62640;
	BIT_VEC cppVar_62641;
	BIT_VEC cppVar_62643;
	BIT_VEC cppVar_62644;
	BIT_VEC cppVar_62645;
	bool cppVar_62646;
	BIT_VEC cppVar_62648;
	BIT_VEC cppVar_62649;
	BIT_VEC cppVar_62650;
	bool cppVar_62651;
	BIT_VEC cppVar_62653;
	BIT_VEC cppVar_62654;
	BIT_VEC cppVar_62655;
	bool cppVar_62656;
	BIT_VEC cppVar_62658;
	BIT_VEC cppVar_62659;
	BIT_VEC cppVar_62660;
	bool cppVar_62661;
	BIT_VEC cppVar_62663;
	BIT_VEC cppVar_62664;
	BIT_VEC cppVar_62665;
	bool cppVar_62666;
	BIT_VEC cppVar_62668;
	BIT_VEC cppVar_62669;
	BIT_VEC cppVar_62670;
	bool cppVar_62671;
	BIT_VEC cppVar_62673;
	BIT_VEC cppVar_62674;
	BIT_VEC cppVar_62675;
	bool cppVar_62676;
	BIT_VEC cppVar_62678;
	BIT_VEC cppVar_62679;
	BIT_VEC cppVar_62680;
	bool cppVar_62681;
	BIT_VEC cppVar_62683;
	BIT_VEC cppVar_62684;
	BIT_VEC cppVar_62685;
	bool cppVar_62686;
	BIT_VEC cppVar_62688;
	BIT_VEC cppVar_62689;
	BIT_VEC cppVar_62690;
	bool cppVar_62691;
	BIT_VEC cppVar_62693;
	BIT_VEC cppVar_62694;
	BIT_VEC cppVar_62695;
	bool cppVar_62696;
	BIT_VEC cppVar_62698;
	BIT_VEC cppVar_62699;
	BIT_VEC cppVar_62700;
	bool cppVar_62701;
	BIT_VEC cppVar_62703;
	BIT_VEC cppVar_62704;
	BIT_VEC cppVar_62705;
	bool cppVar_62706;
	BIT_VEC cppVar_62708;
	BIT_VEC cppVar_62709;
	BIT_VEC cppVar_62710;
	bool cppVar_62711;
	BIT_VEC cppVar_62713;
	BIT_VEC cppVar_62714;
	BIT_VEC cppVar_62715;
	bool cppVar_62716;
	BIT_VEC cppVar_62718;
	BIT_VEC cppVar_62719;
	BIT_VEC cppVar_62720;
	bool cppVar_62721;
	BIT_VEC cppVar_62723;
	BIT_VEC cppVar_62724;
	BIT_VEC cppVar_62725;
	bool cppVar_62726;
	BIT_VEC cppVar_62728;
	BIT_VEC cppVar_62729;
	BIT_VEC cppVar_62730;
	bool cppVar_62731;
	BIT_VEC cppVar_62733;
	BIT_VEC cppVar_62734;
	BIT_VEC cppVar_62735;
	bool cppVar_62736;
	BIT_VEC cppVar_62738;
	BIT_VEC cppVar_62739;
	BIT_VEC cppVar_62740;
	bool cppVar_62741;
	BIT_VEC cppVar_62743;
	BIT_VEC cppVar_62744;
	BIT_VEC cppVar_62745;
	bool cppVar_62746;
	BIT_VEC cppVar_62747;
	BIT_VEC cppVar_62742;
	BIT_VEC cppVar_62737;
	BIT_VEC cppVar_62732;
	BIT_VEC cppVar_62727;
	BIT_VEC cppVar_62722;
	BIT_VEC cppVar_62717;
	BIT_VEC cppVar_62712;
	BIT_VEC cppVar_62707;
	BIT_VEC cppVar_62702;
	BIT_VEC cppVar_62697;
	BIT_VEC cppVar_62692;
	BIT_VEC cppVar_62687;
	BIT_VEC cppVar_62682;
	BIT_VEC cppVar_62677;
	BIT_VEC cppVar_62672;
	BIT_VEC cppVar_62667;
	BIT_VEC cppVar_62662;
	BIT_VEC cppVar_62657;
	BIT_VEC cppVar_62652;
	BIT_VEC cppVar_62647;
	BIT_VEC cppVar_62642;
	BIT_VEC cppVar_62633;
	BIT_VEC cppVar_62748;
	BIT_VEC cppVar_62749;
	BIT_VEC cppVar_62750;
	BIT_VEC cppVar_62751;
	BIT_VEC cppVar_62627;
	BIT_VEC cppVar_62753;
	BIT_VEC cppVar_62754;
	bool cppVar_62755;
	BIT_VEC cppVar_62757;
	BIT_VEC cppVar_62758;
	BIT_VEC cppVar_62759;
	BIT_VEC cppVar_62760;
	bool cppVar_62761;
	BIT_VEC cppVar_62763;
	BIT_VEC cppVar_62764;
	BIT_VEC cppVar_62765;
	BIT_VEC cppVar_62766;
	bool cppVar_62767;
	BIT_VEC cppVar_62768;
	BIT_VEC cppVar_62769;
	BIT_VEC cppVar_62770;
	BIT_VEC cppVar_62772;
	BIT_VEC cppVar_62773;
	BIT_VEC cppVar_62774;
	bool cppVar_62775;
	BIT_VEC cppVar_62777;
	BIT_VEC cppVar_62778;
	BIT_VEC cppVar_62779;
	bool cppVar_62780;
	BIT_VEC cppVar_62782;
	BIT_VEC cppVar_62783;
	BIT_VEC cppVar_62784;
	bool cppVar_62785;
	BIT_VEC cppVar_62787;
	BIT_VEC cppVar_62788;
	BIT_VEC cppVar_62789;
	bool cppVar_62790;
	BIT_VEC cppVar_62792;
	BIT_VEC cppVar_62793;
	BIT_VEC cppVar_62794;
	bool cppVar_62795;
	BIT_VEC cppVar_62797;
	BIT_VEC cppVar_62798;
	BIT_VEC cppVar_62799;
	bool cppVar_62800;
	BIT_VEC cppVar_62802;
	BIT_VEC cppVar_62803;
	BIT_VEC cppVar_62804;
	bool cppVar_62805;
	BIT_VEC cppVar_62807;
	BIT_VEC cppVar_62808;
	BIT_VEC cppVar_62809;
	bool cppVar_62810;
	BIT_VEC cppVar_62812;
	BIT_VEC cppVar_62813;
	BIT_VEC cppVar_62814;
	bool cppVar_62815;
	BIT_VEC cppVar_62817;
	BIT_VEC cppVar_62818;
	BIT_VEC cppVar_62819;
	bool cppVar_62820;
	BIT_VEC cppVar_62822;
	BIT_VEC cppVar_62823;
	BIT_VEC cppVar_62824;
	bool cppVar_62825;
	BIT_VEC cppVar_62827;
	BIT_VEC cppVar_62828;
	BIT_VEC cppVar_62829;
	bool cppVar_62830;
	BIT_VEC cppVar_62832;
	BIT_VEC cppVar_62833;
	BIT_VEC cppVar_62834;
	bool cppVar_62835;
	BIT_VEC cppVar_62837;
	BIT_VEC cppVar_62838;
	BIT_VEC cppVar_62839;
	bool cppVar_62840;
	BIT_VEC cppVar_62842;
	BIT_VEC cppVar_62843;
	BIT_VEC cppVar_62844;
	bool cppVar_62845;
	BIT_VEC cppVar_62847;
	BIT_VEC cppVar_62848;
	BIT_VEC cppVar_62849;
	bool cppVar_62850;
	BIT_VEC cppVar_62852;
	BIT_VEC cppVar_62853;
	BIT_VEC cppVar_62854;
	bool cppVar_62855;
	BIT_VEC cppVar_62857;
	BIT_VEC cppVar_62858;
	BIT_VEC cppVar_62859;
	bool cppVar_62860;
	BIT_VEC cppVar_62862;
	BIT_VEC cppVar_62863;
	BIT_VEC cppVar_62864;
	bool cppVar_62865;
	BIT_VEC cppVar_62867;
	BIT_VEC cppVar_62868;
	BIT_VEC cppVar_62869;
	bool cppVar_62870;
	BIT_VEC cppVar_62872;
	BIT_VEC cppVar_62873;
	BIT_VEC cppVar_62874;
	bool cppVar_62875;
	BIT_VEC cppVar_62876;
	BIT_VEC cppVar_62871;
	BIT_VEC cppVar_62866;
	BIT_VEC cppVar_62861;
	BIT_VEC cppVar_62856;
	BIT_VEC cppVar_62851;
	BIT_VEC cppVar_62846;
	BIT_VEC cppVar_62841;
	BIT_VEC cppVar_62836;
	BIT_VEC cppVar_62831;
	BIT_VEC cppVar_62826;
	BIT_VEC cppVar_62821;
	BIT_VEC cppVar_62816;
	BIT_VEC cppVar_62811;
	BIT_VEC cppVar_62806;
	BIT_VEC cppVar_62801;
	BIT_VEC cppVar_62796;
	BIT_VEC cppVar_62791;
	BIT_VEC cppVar_62786;
	BIT_VEC cppVar_62781;
	BIT_VEC cppVar_62776;
	BIT_VEC cppVar_62771;
	BIT_VEC cppVar_62762;
	BIT_VEC cppVar_62877;
	BIT_VEC cppVar_62756;
	BIT_VEC cppVar_62879;
	BIT_VEC cppVar_62880;
	bool cppVar_62881;
	BIT_VEC cppVar_62883;
	BIT_VEC cppVar_62884;
	BIT_VEC cppVar_62885;
	BIT_VEC cppVar_62886;
	bool cppVar_62887;
	BIT_VEC cppVar_62889;
	BIT_VEC cppVar_62890;
	BIT_VEC cppVar_62891;
	BIT_VEC cppVar_62892;
	bool cppVar_62893;
	BIT_VEC cppVar_62894;
	BIT_VEC cppVar_62895;
	BIT_VEC cppVar_62896;
	BIT_VEC cppVar_62898;
	BIT_VEC cppVar_62899;
	BIT_VEC cppVar_62900;
	bool cppVar_62901;
	BIT_VEC cppVar_62903;
	BIT_VEC cppVar_62904;
	BIT_VEC cppVar_62905;
	bool cppVar_62906;
	BIT_VEC cppVar_62908;
	BIT_VEC cppVar_62909;
	BIT_VEC cppVar_62910;
	bool cppVar_62911;
	BIT_VEC cppVar_62913;
	BIT_VEC cppVar_62914;
	BIT_VEC cppVar_62915;
	bool cppVar_62916;
	BIT_VEC cppVar_62918;
	BIT_VEC cppVar_62919;
	BIT_VEC cppVar_62920;
	bool cppVar_62921;
	BIT_VEC cppVar_62923;
	BIT_VEC cppVar_62924;
	BIT_VEC cppVar_62925;
	bool cppVar_62926;
	BIT_VEC cppVar_62928;
	BIT_VEC cppVar_62929;
	BIT_VEC cppVar_62930;
	bool cppVar_62931;
	BIT_VEC cppVar_62933;
	BIT_VEC cppVar_62934;
	BIT_VEC cppVar_62935;
	bool cppVar_62936;
	BIT_VEC cppVar_62938;
	BIT_VEC cppVar_62939;
	BIT_VEC cppVar_62940;
	bool cppVar_62941;
	BIT_VEC cppVar_62943;
	BIT_VEC cppVar_62944;
	BIT_VEC cppVar_62945;
	bool cppVar_62946;
	BIT_VEC cppVar_62948;
	BIT_VEC cppVar_62949;
	BIT_VEC cppVar_62950;
	bool cppVar_62951;
	BIT_VEC cppVar_62953;
	BIT_VEC cppVar_62954;
	BIT_VEC cppVar_62955;
	bool cppVar_62956;
	BIT_VEC cppVar_62958;
	BIT_VEC cppVar_62959;
	BIT_VEC cppVar_62960;
	bool cppVar_62961;
	BIT_VEC cppVar_62963;
	BIT_VEC cppVar_62964;
	BIT_VEC cppVar_62965;
	bool cppVar_62966;
	BIT_VEC cppVar_62968;
	BIT_VEC cppVar_62969;
	BIT_VEC cppVar_62970;
	bool cppVar_62971;
	BIT_VEC cppVar_62973;
	BIT_VEC cppVar_62974;
	BIT_VEC cppVar_62975;
	bool cppVar_62976;
	BIT_VEC cppVar_62978;
	BIT_VEC cppVar_62979;
	BIT_VEC cppVar_62980;
	bool cppVar_62981;
	BIT_VEC cppVar_62983;
	BIT_VEC cppVar_62984;
	BIT_VEC cppVar_62985;
	bool cppVar_62986;
	BIT_VEC cppVar_62988;
	BIT_VEC cppVar_62989;
	BIT_VEC cppVar_62990;
	bool cppVar_62991;
	BIT_VEC cppVar_62993;
	BIT_VEC cppVar_62994;
	BIT_VEC cppVar_62995;
	bool cppVar_62996;
	BIT_VEC cppVar_62998;
	BIT_VEC cppVar_62999;
	BIT_VEC cppVar_63000;
	bool cppVar_63001;
	BIT_VEC cppVar_63002;
	BIT_VEC cppVar_62997;
	BIT_VEC cppVar_62992;
	BIT_VEC cppVar_62987;
	BIT_VEC cppVar_62982;
	BIT_VEC cppVar_62977;
	BIT_VEC cppVar_62972;
	BIT_VEC cppVar_62967;
	BIT_VEC cppVar_62962;
	BIT_VEC cppVar_62957;
	BIT_VEC cppVar_62952;
	BIT_VEC cppVar_62947;
	BIT_VEC cppVar_62942;
	BIT_VEC cppVar_62937;
	BIT_VEC cppVar_62932;
	BIT_VEC cppVar_62927;
	BIT_VEC cppVar_62922;
	BIT_VEC cppVar_62917;
	BIT_VEC cppVar_62912;
	BIT_VEC cppVar_62907;
	BIT_VEC cppVar_62902;
	BIT_VEC cppVar_62897;
	BIT_VEC cppVar_62888;
	BIT_VEC cppVar_63003;
	BIT_VEC cppVar_63004;
	BIT_VEC cppVar_63005;
	BIT_VEC cppVar_63006;
	BIT_VEC cppVar_62882;
	BIT_VEC cppVar_63008;
	BIT_VEC cppVar_63009;
	bool cppVar_63010;
	BIT_VEC cppVar_63012;
	BIT_VEC cppVar_63013;
	BIT_VEC cppVar_63014;
	BIT_VEC cppVar_63015;
	bool cppVar_63016;
	BIT_VEC cppVar_63018;
	BIT_VEC cppVar_63019;
	BIT_VEC cppVar_63020;
	BIT_VEC cppVar_63021;
	bool cppVar_63022;
	BIT_VEC cppVar_63023;
	BIT_VEC cppVar_63024;
	BIT_VEC cppVar_63025;
	BIT_VEC cppVar_63027;
	BIT_VEC cppVar_63028;
	BIT_VEC cppVar_63029;
	bool cppVar_63030;
	BIT_VEC cppVar_63032;
	BIT_VEC cppVar_63033;
	BIT_VEC cppVar_63034;
	bool cppVar_63035;
	BIT_VEC cppVar_63037;
	BIT_VEC cppVar_63038;
	BIT_VEC cppVar_63039;
	bool cppVar_63040;
	BIT_VEC cppVar_63042;
	BIT_VEC cppVar_63043;
	BIT_VEC cppVar_63044;
	bool cppVar_63045;
	BIT_VEC cppVar_63047;
	BIT_VEC cppVar_63048;
	BIT_VEC cppVar_63049;
	bool cppVar_63050;
	BIT_VEC cppVar_63052;
	BIT_VEC cppVar_63053;
	BIT_VEC cppVar_63054;
	bool cppVar_63055;
	BIT_VEC cppVar_63057;
	BIT_VEC cppVar_63058;
	BIT_VEC cppVar_63059;
	bool cppVar_63060;
	BIT_VEC cppVar_63062;
	BIT_VEC cppVar_63063;
	BIT_VEC cppVar_63064;
	bool cppVar_63065;
	BIT_VEC cppVar_63067;
	BIT_VEC cppVar_63068;
	BIT_VEC cppVar_63069;
	bool cppVar_63070;
	BIT_VEC cppVar_63072;
	BIT_VEC cppVar_63073;
	BIT_VEC cppVar_63074;
	bool cppVar_63075;
	BIT_VEC cppVar_63077;
	BIT_VEC cppVar_63078;
	BIT_VEC cppVar_63079;
	bool cppVar_63080;
	BIT_VEC cppVar_63082;
	BIT_VEC cppVar_63083;
	BIT_VEC cppVar_63084;
	bool cppVar_63085;
	BIT_VEC cppVar_63087;
	BIT_VEC cppVar_63088;
	BIT_VEC cppVar_63089;
	bool cppVar_63090;
	BIT_VEC cppVar_63092;
	BIT_VEC cppVar_63093;
	BIT_VEC cppVar_63094;
	bool cppVar_63095;
	BIT_VEC cppVar_63097;
	BIT_VEC cppVar_63098;
	BIT_VEC cppVar_63099;
	bool cppVar_63100;
	BIT_VEC cppVar_63102;
	BIT_VEC cppVar_63103;
	BIT_VEC cppVar_63104;
	bool cppVar_63105;
	BIT_VEC cppVar_63107;
	BIT_VEC cppVar_63108;
	BIT_VEC cppVar_63109;
	bool cppVar_63110;
	BIT_VEC cppVar_63112;
	BIT_VEC cppVar_63113;
	BIT_VEC cppVar_63114;
	bool cppVar_63115;
	BIT_VEC cppVar_63117;
	BIT_VEC cppVar_63118;
	BIT_VEC cppVar_63119;
	bool cppVar_63120;
	BIT_VEC cppVar_63122;
	BIT_VEC cppVar_63123;
	BIT_VEC cppVar_63124;
	bool cppVar_63125;
	BIT_VEC cppVar_63127;
	BIT_VEC cppVar_63128;
	BIT_VEC cppVar_63129;
	bool cppVar_63130;
	BIT_VEC cppVar_63131;
	BIT_VEC cppVar_63126;
	BIT_VEC cppVar_63121;
	BIT_VEC cppVar_63116;
	BIT_VEC cppVar_63111;
	BIT_VEC cppVar_63106;
	BIT_VEC cppVar_63101;
	BIT_VEC cppVar_63096;
	BIT_VEC cppVar_63091;
	BIT_VEC cppVar_63086;
	BIT_VEC cppVar_63081;
	BIT_VEC cppVar_63076;
	BIT_VEC cppVar_63071;
	BIT_VEC cppVar_63066;
	BIT_VEC cppVar_63061;
	BIT_VEC cppVar_63056;
	BIT_VEC cppVar_63051;
	BIT_VEC cppVar_63046;
	BIT_VEC cppVar_63041;
	BIT_VEC cppVar_63036;
	BIT_VEC cppVar_63031;
	BIT_VEC cppVar_63026;
	BIT_VEC cppVar_63017;
	BIT_VEC cppVar_63132;
	BIT_VEC cppVar_63011;
	BIT_VEC cppVar_63134;
	BIT_VEC cppVar_63135;
	bool cppVar_63136;
	BIT_VEC cppVar_63138;
	BIT_VEC cppVar_63139;
	BIT_VEC cppVar_63140;
	BIT_VEC cppVar_63141;
	bool cppVar_63142;
	BIT_VEC cppVar_63144;
	BIT_VEC cppVar_63145;
	BIT_VEC cppVar_63146;
	BIT_VEC cppVar_63147;
	bool cppVar_63148;
	BIT_VEC cppVar_63149;
	BIT_VEC cppVar_63150;
	BIT_VEC cppVar_63151;
	BIT_VEC cppVar_63153;
	BIT_VEC cppVar_63154;
	BIT_VEC cppVar_63155;
	bool cppVar_63156;
	BIT_VEC cppVar_63158;
	BIT_VEC cppVar_63159;
	BIT_VEC cppVar_63160;
	bool cppVar_63161;
	BIT_VEC cppVar_63163;
	BIT_VEC cppVar_63164;
	BIT_VEC cppVar_63165;
	bool cppVar_63166;
	BIT_VEC cppVar_63168;
	BIT_VEC cppVar_63169;
	BIT_VEC cppVar_63170;
	bool cppVar_63171;
	BIT_VEC cppVar_63173;
	BIT_VEC cppVar_63174;
	BIT_VEC cppVar_63175;
	bool cppVar_63176;
	BIT_VEC cppVar_63178;
	BIT_VEC cppVar_63179;
	BIT_VEC cppVar_63180;
	bool cppVar_63181;
	BIT_VEC cppVar_63183;
	BIT_VEC cppVar_63184;
	BIT_VEC cppVar_63185;
	bool cppVar_63186;
	BIT_VEC cppVar_63188;
	BIT_VEC cppVar_63189;
	BIT_VEC cppVar_63190;
	bool cppVar_63191;
	BIT_VEC cppVar_63193;
	BIT_VEC cppVar_63194;
	BIT_VEC cppVar_63195;
	bool cppVar_63196;
	BIT_VEC cppVar_63198;
	BIT_VEC cppVar_63199;
	BIT_VEC cppVar_63200;
	bool cppVar_63201;
	BIT_VEC cppVar_63203;
	BIT_VEC cppVar_63204;
	BIT_VEC cppVar_63205;
	bool cppVar_63206;
	BIT_VEC cppVar_63208;
	BIT_VEC cppVar_63209;
	BIT_VEC cppVar_63210;
	bool cppVar_63211;
	BIT_VEC cppVar_63213;
	BIT_VEC cppVar_63214;
	BIT_VEC cppVar_63215;
	bool cppVar_63216;
	BIT_VEC cppVar_63218;
	BIT_VEC cppVar_63219;
	BIT_VEC cppVar_63220;
	bool cppVar_63221;
	BIT_VEC cppVar_63223;
	BIT_VEC cppVar_63224;
	BIT_VEC cppVar_63225;
	bool cppVar_63226;
	BIT_VEC cppVar_63228;
	BIT_VEC cppVar_63229;
	BIT_VEC cppVar_63230;
	bool cppVar_63231;
	BIT_VEC cppVar_63233;
	BIT_VEC cppVar_63234;
	BIT_VEC cppVar_63235;
	bool cppVar_63236;
	BIT_VEC cppVar_63238;
	BIT_VEC cppVar_63239;
	BIT_VEC cppVar_63240;
	bool cppVar_63241;
	BIT_VEC cppVar_63243;
	BIT_VEC cppVar_63244;
	BIT_VEC cppVar_63245;
	bool cppVar_63246;
	BIT_VEC cppVar_63248;
	BIT_VEC cppVar_63249;
	BIT_VEC cppVar_63250;
	bool cppVar_63251;
	BIT_VEC cppVar_63253;
	BIT_VEC cppVar_63254;
	BIT_VEC cppVar_63255;
	bool cppVar_63256;
	BIT_VEC cppVar_63257;
	BIT_VEC cppVar_63252;
	BIT_VEC cppVar_63247;
	BIT_VEC cppVar_63242;
	BIT_VEC cppVar_63237;
	BIT_VEC cppVar_63232;
	BIT_VEC cppVar_63227;
	BIT_VEC cppVar_63222;
	BIT_VEC cppVar_63217;
	BIT_VEC cppVar_63212;
	BIT_VEC cppVar_63207;
	BIT_VEC cppVar_63202;
	BIT_VEC cppVar_63197;
	BIT_VEC cppVar_63192;
	BIT_VEC cppVar_63187;
	BIT_VEC cppVar_63182;
	BIT_VEC cppVar_63177;
	BIT_VEC cppVar_63172;
	BIT_VEC cppVar_63167;
	BIT_VEC cppVar_63162;
	BIT_VEC cppVar_63157;
	BIT_VEC cppVar_63152;
	BIT_VEC cppVar_63143;
	BIT_VEC cppVar_63258;
	BIT_VEC cppVar_63259;
	BIT_VEC cppVar_63260;
	BIT_VEC cppVar_63261;
	BIT_VEC cppVar_63137;
	BIT_VEC cppVar_63263;
	BIT_VEC cppVar_63264;
	bool cppVar_63265;
	BIT_VEC cppVar_63267;
	BIT_VEC cppVar_63268;
	BIT_VEC cppVar_63269;
	BIT_VEC cppVar_63270;
	bool cppVar_63271;
	BIT_VEC cppVar_63273;
	BIT_VEC cppVar_63274;
	BIT_VEC cppVar_63275;
	BIT_VEC cppVar_63276;
	bool cppVar_63277;
	BIT_VEC cppVar_63278;
	BIT_VEC cppVar_63279;
	BIT_VEC cppVar_63280;
	BIT_VEC cppVar_63282;
	BIT_VEC cppVar_63283;
	BIT_VEC cppVar_63284;
	bool cppVar_63285;
	BIT_VEC cppVar_63287;
	BIT_VEC cppVar_63288;
	BIT_VEC cppVar_63289;
	bool cppVar_63290;
	BIT_VEC cppVar_63292;
	BIT_VEC cppVar_63293;
	BIT_VEC cppVar_63294;
	bool cppVar_63295;
	BIT_VEC cppVar_63297;
	BIT_VEC cppVar_63298;
	BIT_VEC cppVar_63299;
	bool cppVar_63300;
	BIT_VEC cppVar_63302;
	BIT_VEC cppVar_63303;
	BIT_VEC cppVar_63304;
	bool cppVar_63305;
	BIT_VEC cppVar_63307;
	BIT_VEC cppVar_63308;
	BIT_VEC cppVar_63309;
	bool cppVar_63310;
	BIT_VEC cppVar_63312;
	BIT_VEC cppVar_63313;
	BIT_VEC cppVar_63314;
	bool cppVar_63315;
	BIT_VEC cppVar_63317;
	BIT_VEC cppVar_63318;
	BIT_VEC cppVar_63319;
	bool cppVar_63320;
	BIT_VEC cppVar_63322;
	BIT_VEC cppVar_63323;
	BIT_VEC cppVar_63324;
	bool cppVar_63325;
	BIT_VEC cppVar_63327;
	BIT_VEC cppVar_63328;
	BIT_VEC cppVar_63329;
	bool cppVar_63330;
	BIT_VEC cppVar_63332;
	BIT_VEC cppVar_63333;
	BIT_VEC cppVar_63334;
	bool cppVar_63335;
	BIT_VEC cppVar_63337;
	BIT_VEC cppVar_63338;
	BIT_VEC cppVar_63339;
	bool cppVar_63340;
	BIT_VEC cppVar_63342;
	BIT_VEC cppVar_63343;
	BIT_VEC cppVar_63344;
	bool cppVar_63345;
	BIT_VEC cppVar_63347;
	BIT_VEC cppVar_63348;
	BIT_VEC cppVar_63349;
	bool cppVar_63350;
	BIT_VEC cppVar_63352;
	BIT_VEC cppVar_63353;
	BIT_VEC cppVar_63354;
	bool cppVar_63355;
	BIT_VEC cppVar_63357;
	BIT_VEC cppVar_63358;
	BIT_VEC cppVar_63359;
	bool cppVar_63360;
	BIT_VEC cppVar_63362;
	BIT_VEC cppVar_63363;
	BIT_VEC cppVar_63364;
	bool cppVar_63365;
	BIT_VEC cppVar_63367;
	BIT_VEC cppVar_63368;
	BIT_VEC cppVar_63369;
	bool cppVar_63370;
	BIT_VEC cppVar_63372;
	BIT_VEC cppVar_63373;
	BIT_VEC cppVar_63374;
	bool cppVar_63375;
	BIT_VEC cppVar_63377;
	BIT_VEC cppVar_63378;
	BIT_VEC cppVar_63379;
	bool cppVar_63380;
	BIT_VEC cppVar_63382;
	BIT_VEC cppVar_63383;
	BIT_VEC cppVar_63384;
	bool cppVar_63385;
	BIT_VEC cppVar_63386;
	BIT_VEC cppVar_63381;
	BIT_VEC cppVar_63376;
	BIT_VEC cppVar_63371;
	BIT_VEC cppVar_63366;
	BIT_VEC cppVar_63361;
	BIT_VEC cppVar_63356;
	BIT_VEC cppVar_63351;
	BIT_VEC cppVar_63346;
	BIT_VEC cppVar_63341;
	BIT_VEC cppVar_63336;
	BIT_VEC cppVar_63331;
	BIT_VEC cppVar_63326;
	BIT_VEC cppVar_63321;
	BIT_VEC cppVar_63316;
	BIT_VEC cppVar_63311;
	BIT_VEC cppVar_63306;
	BIT_VEC cppVar_63301;
	BIT_VEC cppVar_63296;
	BIT_VEC cppVar_63291;
	BIT_VEC cppVar_63286;
	BIT_VEC cppVar_63281;
	BIT_VEC cppVar_63272;
	BIT_VEC cppVar_63387;
	BIT_VEC cppVar_63266;
	BIT_VEC cppVar_63389;
	BIT_VEC cppVar_63390;
	bool cppVar_63391;
	BIT_VEC cppVar_63392;
	BIT_VEC cppVar_63393;
	bool cppVar_63394;
	bool cppVar_63395;
	BIT_VEC cppVar_63397;
	BIT_VEC cppVar_63398;
	BIT_VEC cppVar_63399;
	BIT_VEC cppVar_63400;
	bool cppVar_63401;
	BIT_VEC cppVar_63403;
	BIT_VEC cppVar_63404;
	BIT_VEC cppVar_63405;
	BIT_VEC cppVar_63406;
	bool cppVar_63407;
	BIT_VEC cppVar_63408;
	BIT_VEC cppVar_63409;
	BIT_VEC cppVar_63410;
	BIT_VEC cppVar_63412;
	BIT_VEC cppVar_63413;
	BIT_VEC cppVar_63414;
	bool cppVar_63415;
	BIT_VEC cppVar_63417;
	BIT_VEC cppVar_63418;
	BIT_VEC cppVar_63419;
	bool cppVar_63420;
	BIT_VEC cppVar_63422;
	BIT_VEC cppVar_63423;
	BIT_VEC cppVar_63424;
	bool cppVar_63425;
	BIT_VEC cppVar_63427;
	BIT_VEC cppVar_63428;
	BIT_VEC cppVar_63429;
	bool cppVar_63430;
	BIT_VEC cppVar_63432;
	BIT_VEC cppVar_63433;
	BIT_VEC cppVar_63434;
	bool cppVar_63435;
	BIT_VEC cppVar_63437;
	BIT_VEC cppVar_63438;
	BIT_VEC cppVar_63439;
	bool cppVar_63440;
	BIT_VEC cppVar_63442;
	BIT_VEC cppVar_63443;
	BIT_VEC cppVar_63444;
	bool cppVar_63445;
	BIT_VEC cppVar_63447;
	BIT_VEC cppVar_63448;
	BIT_VEC cppVar_63449;
	bool cppVar_63450;
	BIT_VEC cppVar_63452;
	BIT_VEC cppVar_63453;
	BIT_VEC cppVar_63454;
	bool cppVar_63455;
	BIT_VEC cppVar_63457;
	BIT_VEC cppVar_63458;
	BIT_VEC cppVar_63459;
	bool cppVar_63460;
	BIT_VEC cppVar_63462;
	BIT_VEC cppVar_63463;
	BIT_VEC cppVar_63464;
	bool cppVar_63465;
	BIT_VEC cppVar_63467;
	BIT_VEC cppVar_63468;
	BIT_VEC cppVar_63469;
	bool cppVar_63470;
	BIT_VEC cppVar_63472;
	BIT_VEC cppVar_63473;
	BIT_VEC cppVar_63474;
	bool cppVar_63475;
	BIT_VEC cppVar_63477;
	BIT_VEC cppVar_63478;
	BIT_VEC cppVar_63479;
	bool cppVar_63480;
	BIT_VEC cppVar_63482;
	BIT_VEC cppVar_63483;
	BIT_VEC cppVar_63484;
	bool cppVar_63485;
	BIT_VEC cppVar_63487;
	BIT_VEC cppVar_63488;
	BIT_VEC cppVar_63489;
	bool cppVar_63490;
	BIT_VEC cppVar_63492;
	BIT_VEC cppVar_63493;
	BIT_VEC cppVar_63494;
	bool cppVar_63495;
	BIT_VEC cppVar_63497;
	BIT_VEC cppVar_63498;
	BIT_VEC cppVar_63499;
	bool cppVar_63500;
	BIT_VEC cppVar_63502;
	BIT_VEC cppVar_63503;
	BIT_VEC cppVar_63504;
	bool cppVar_63505;
	BIT_VEC cppVar_63507;
	BIT_VEC cppVar_63508;
	BIT_VEC cppVar_63509;
	bool cppVar_63510;
	BIT_VEC cppVar_63512;
	BIT_VEC cppVar_63513;
	BIT_VEC cppVar_63514;
	bool cppVar_63515;
	BIT_VEC cppVar_63516;
	BIT_VEC cppVar_63511;
	BIT_VEC cppVar_63506;
	BIT_VEC cppVar_63501;
	BIT_VEC cppVar_63496;
	BIT_VEC cppVar_63491;
	BIT_VEC cppVar_63486;
	BIT_VEC cppVar_63481;
	BIT_VEC cppVar_63476;
	BIT_VEC cppVar_63471;
	BIT_VEC cppVar_63466;
	BIT_VEC cppVar_63461;
	BIT_VEC cppVar_63456;
	BIT_VEC cppVar_63451;
	BIT_VEC cppVar_63446;
	BIT_VEC cppVar_63441;
	BIT_VEC cppVar_63436;
	BIT_VEC cppVar_63431;
	BIT_VEC cppVar_63426;
	BIT_VEC cppVar_63421;
	BIT_VEC cppVar_63416;
	BIT_VEC cppVar_63411;
	BIT_VEC cppVar_63402;
	BIT_VEC cppVar_63517;
	BIT_VEC cppVar_63518;
	BIT_VEC cppVar_63396;
	BIT_VEC cppVar_63520;
	BIT_VEC cppVar_63521;
	bool cppVar_63522;
	BIT_VEC cppVar_63523;
	BIT_VEC cppVar_63524;
	bool cppVar_63525;
	bool cppVar_63526;
	BIT_VEC cppVar_63529;
	BIT_VEC cppVar_63530;
	BIT_VEC cppVar_63531;
	BIT_VEC cppVar_63532;
	BIT_VEC cppVar_63533;
	bool cppVar_63534;
	BIT_VEC cppVar_63535;
	BIT_VEC cppVar_63536;
	BIT_VEC cppVar_63537;
	BIT_VEC cppVar_63538;
	BIT_VEC cppVar_63539;
	BIT_VEC cppVar_63540;
	BIT_VEC cppVar_63541;
	BIT_VEC cppVar_63542;
	BIT_VEC cppVar_63543;
	BIT_VEC cppVar_63544;
	BIT_VEC cppVar_63545;
	BIT_VEC cppVar_63528;
	BIT_VEC cppVar_63546;
	bool cppVar_63547;
	BIT_VEC cppVar_63548;
	BIT_VEC cppVar_63549;
	BIT_VEC cppVar_63550;
	BIT_VEC cppVar_63551;
	BIT_VEC cppVar_63552;
	BIT_VEC cppVar_63553;
	BIT_VEC cppVar_63554;
	BIT_VEC cppVar_63557;
	BIT_VEC cppVar_63558;
	BIT_VEC cppVar_63559;
	bool cppVar_63560;
	BIT_VEC cppVar_63561;
	BIT_VEC cppVar_63562;
	BIT_VEC cppVar_63563;
	BIT_VEC cppVar_63564;
	BIT_VEC cppVar_63565;
	BIT_VEC cppVar_63566;
	BIT_VEC cppVar_63567;
	BIT_VEC cppVar_63568;
	BIT_VEC cppVar_63569;
	BIT_VEC cppVar_63556;
	BIT_VEC cppVar_63570;
	BIT_VEC cppVar_63571;
	bool cppVar_63572;
	BIT_VEC cppVar_63574;
	BIT_VEC cppVar_63575;
	BIT_VEC cppVar_63576;
	bool cppVar_63577;
	BIT_VEC cppVar_63578;
	BIT_VEC cppVar_63579;
	BIT_VEC cppVar_63580;
	BIT_VEC cppVar_63581;
	BIT_VEC cppVar_63582;
	BIT_VEC cppVar_63583;
	BIT_VEC cppVar_63584;
	BIT_VEC cppVar_63585;
	BIT_VEC cppVar_63586;
	BIT_VEC cppVar_63573;
	BIT_VEC cppVar_63587;
	BIT_VEC cppVar_63590;
	BIT_VEC cppVar_63591;
	BIT_VEC cppVar_63592;
	bool cppVar_63593;
	BIT_VEC cppVar_63594;
	BIT_VEC cppVar_63595;
	BIT_VEC cppVar_63596;
	BIT_VEC cppVar_63597;
	BIT_VEC cppVar_63598;
	BIT_VEC cppVar_63599;
	BIT_VEC cppVar_63600;
	BIT_VEC cppVar_63601;
	BIT_VEC cppVar_63602;
	BIT_VEC cppVar_63589;
	BIT_VEC cppVar_63603;
	bool cppVar_63604;
	BIT_VEC cppVar_63607;
	BIT_VEC cppVar_63608;
	BIT_VEC cppVar_63609;
	bool cppVar_63610;
	BIT_VEC cppVar_63611;
	BIT_VEC cppVar_63612;
	BIT_VEC cppVar_63613;
	BIT_VEC cppVar_63614;
	BIT_VEC cppVar_63615;
	BIT_VEC cppVar_63616;
	BIT_VEC cppVar_63617;
	BIT_VEC cppVar_63618;
	BIT_VEC cppVar_63619;
	BIT_VEC cppVar_63606;
	BIT_VEC cppVar_63620;
	bool cppVar_63621;
	BIT_VEC cppVar_63624;
	BIT_VEC cppVar_63625;
	BIT_VEC cppVar_63626;
	bool cppVar_63627;
	BIT_VEC cppVar_63628;
	BIT_VEC cppVar_63629;
	BIT_VEC cppVar_63630;
	BIT_VEC cppVar_63631;
	BIT_VEC cppVar_63632;
	BIT_VEC cppVar_63633;
	BIT_VEC cppVar_63634;
	BIT_VEC cppVar_63635;
	BIT_VEC cppVar_63636;
	BIT_VEC cppVar_63623;
	BIT_VEC cppVar_63637;
	bool cppVar_63638;
	BIT_VEC cppVar_63641;
	BIT_VEC cppVar_63642;
	BIT_VEC cppVar_63643;
	bool cppVar_63644;
	BIT_VEC cppVar_63645;
	BIT_VEC cppVar_63646;
	BIT_VEC cppVar_63647;
	BIT_VEC cppVar_63648;
	BIT_VEC cppVar_63649;
	BIT_VEC cppVar_63650;
	BIT_VEC cppVar_63651;
	BIT_VEC cppVar_63652;
	BIT_VEC cppVar_63653;
	BIT_VEC cppVar_63640;
	BIT_VEC cppVar_63654;
	bool cppVar_63655;
	BIT_VEC cppVar_63658;
	BIT_VEC cppVar_63659;
	BIT_VEC cppVar_63660;
	bool cppVar_63661;
	BIT_VEC cppVar_63662;
	BIT_VEC cppVar_63663;
	BIT_VEC cppVar_63664;
	BIT_VEC cppVar_63665;
	BIT_VEC cppVar_63666;
	BIT_VEC cppVar_63667;
	BIT_VEC cppVar_63668;
	BIT_VEC cppVar_63669;
	BIT_VEC cppVar_63670;
	BIT_VEC cppVar_63657;
	BIT_VEC cppVar_63671;
	bool cppVar_63672;
	BIT_VEC cppVar_63675;
	BIT_VEC cppVar_63676;
	BIT_VEC cppVar_63677;
	bool cppVar_63678;
	BIT_VEC cppVar_63679;
	BIT_VEC cppVar_63680;
	BIT_VEC cppVar_63681;
	BIT_VEC cppVar_63682;
	BIT_VEC cppVar_63683;
	BIT_VEC cppVar_63684;
	BIT_VEC cppVar_63685;
	BIT_VEC cppVar_63686;
	BIT_VEC cppVar_63687;
	BIT_VEC cppVar_63674;
	BIT_VEC cppVar_63688;
	bool cppVar_63689;
	BIT_VEC cppVar_63692;
	BIT_VEC cppVar_63693;
	BIT_VEC cppVar_63694;
	bool cppVar_63695;
	BIT_VEC cppVar_63696;
	BIT_VEC cppVar_63697;
	BIT_VEC cppVar_63698;
	BIT_VEC cppVar_63699;
	BIT_VEC cppVar_63700;
	BIT_VEC cppVar_63701;
	BIT_VEC cppVar_63702;
	BIT_VEC cppVar_63703;
	BIT_VEC cppVar_63704;
	BIT_VEC cppVar_63691;
	BIT_VEC cppVar_63705;
	bool cppVar_63706;
	BIT_VEC cppVar_63709;
	BIT_VEC cppVar_63710;
	BIT_VEC cppVar_63711;
	bool cppVar_63712;
	BIT_VEC cppVar_63713;
	BIT_VEC cppVar_63714;
	BIT_VEC cppVar_63715;
	BIT_VEC cppVar_63716;
	BIT_VEC cppVar_63717;
	BIT_VEC cppVar_63718;
	BIT_VEC cppVar_63719;
	BIT_VEC cppVar_63720;
	BIT_VEC cppVar_63721;
	BIT_VEC cppVar_63708;
	BIT_VEC cppVar_63722;
	bool cppVar_63723;
	BIT_VEC cppVar_63726;
	BIT_VEC cppVar_63727;
	BIT_VEC cppVar_63728;
	bool cppVar_63729;
	BIT_VEC cppVar_63730;
	BIT_VEC cppVar_63731;
	BIT_VEC cppVar_63732;
	BIT_VEC cppVar_63733;
	BIT_VEC cppVar_63734;
	BIT_VEC cppVar_63735;
	BIT_VEC cppVar_63736;
	BIT_VEC cppVar_63737;
	BIT_VEC cppVar_63738;
	BIT_VEC cppVar_63725;
	BIT_VEC cppVar_63739;
	bool cppVar_63740;
	BIT_VEC cppVar_63743;
	BIT_VEC cppVar_63744;
	BIT_VEC cppVar_63745;
	bool cppVar_63746;
	BIT_VEC cppVar_63747;
	BIT_VEC cppVar_63748;
	BIT_VEC cppVar_63749;
	BIT_VEC cppVar_63750;
	BIT_VEC cppVar_63751;
	BIT_VEC cppVar_63752;
	BIT_VEC cppVar_63753;
	BIT_VEC cppVar_63754;
	BIT_VEC cppVar_63755;
	BIT_VEC cppVar_63742;
	BIT_VEC cppVar_63756;
	bool cppVar_63757;
	BIT_VEC cppVar_63760;
	BIT_VEC cppVar_63761;
	BIT_VEC cppVar_63762;
	bool cppVar_63763;
	BIT_VEC cppVar_63764;
	BIT_VEC cppVar_63765;
	BIT_VEC cppVar_63766;
	BIT_VEC cppVar_63767;
	BIT_VEC cppVar_63768;
	BIT_VEC cppVar_63769;
	BIT_VEC cppVar_63770;
	BIT_VEC cppVar_63771;
	BIT_VEC cppVar_63772;
	BIT_VEC cppVar_63759;
	BIT_VEC cppVar_63773;
	bool cppVar_63774;
	BIT_VEC cppVar_63777;
	BIT_VEC cppVar_63778;
	BIT_VEC cppVar_63779;
	bool cppVar_63780;
	BIT_VEC cppVar_63781;
	BIT_VEC cppVar_63782;
	BIT_VEC cppVar_63783;
	BIT_VEC cppVar_63784;
	BIT_VEC cppVar_63785;
	BIT_VEC cppVar_63786;
	BIT_VEC cppVar_63787;
	BIT_VEC cppVar_63788;
	BIT_VEC cppVar_63789;
	BIT_VEC cppVar_63776;
	BIT_VEC cppVar_63790;
	bool cppVar_63791;
	BIT_VEC cppVar_63794;
	BIT_VEC cppVar_63795;
	BIT_VEC cppVar_63796;
	bool cppVar_63797;
	BIT_VEC cppVar_63798;
	BIT_VEC cppVar_63799;
	BIT_VEC cppVar_63800;
	BIT_VEC cppVar_63801;
	BIT_VEC cppVar_63802;
	BIT_VEC cppVar_63803;
	BIT_VEC cppVar_63804;
	BIT_VEC cppVar_63805;
	BIT_VEC cppVar_63806;
	BIT_VEC cppVar_63793;
	BIT_VEC cppVar_63807;
	bool cppVar_63808;
	BIT_VEC cppVar_63811;
	BIT_VEC cppVar_63812;
	BIT_VEC cppVar_63813;
	bool cppVar_63814;
	BIT_VEC cppVar_63815;
	BIT_VEC cppVar_63816;
	BIT_VEC cppVar_63817;
	BIT_VEC cppVar_63818;
	BIT_VEC cppVar_63819;
	BIT_VEC cppVar_63820;
	BIT_VEC cppVar_63821;
	BIT_VEC cppVar_63822;
	BIT_VEC cppVar_63823;
	BIT_VEC cppVar_63810;
	BIT_VEC cppVar_63824;
	bool cppVar_63825;
	BIT_VEC cppVar_63828;
	BIT_VEC cppVar_63829;
	BIT_VEC cppVar_63830;
	bool cppVar_63831;
	BIT_VEC cppVar_63832;
	BIT_VEC cppVar_63833;
	BIT_VEC cppVar_63834;
	BIT_VEC cppVar_63835;
	BIT_VEC cppVar_63836;
	BIT_VEC cppVar_63837;
	BIT_VEC cppVar_63838;
	BIT_VEC cppVar_63839;
	BIT_VEC cppVar_63840;
	BIT_VEC cppVar_63827;
	BIT_VEC cppVar_63841;
	bool cppVar_63842;
	BIT_VEC cppVar_63845;
	BIT_VEC cppVar_63846;
	BIT_VEC cppVar_63847;
	bool cppVar_63848;
	BIT_VEC cppVar_63849;
	BIT_VEC cppVar_63850;
	BIT_VEC cppVar_63851;
	BIT_VEC cppVar_63852;
	BIT_VEC cppVar_63853;
	BIT_VEC cppVar_63854;
	BIT_VEC cppVar_63855;
	BIT_VEC cppVar_63856;
	BIT_VEC cppVar_63857;
	BIT_VEC cppVar_63844;
	BIT_VEC cppVar_63858;
	bool cppVar_63859;
	BIT_VEC cppVar_63862;
	BIT_VEC cppVar_63863;
	BIT_VEC cppVar_63864;
	bool cppVar_63865;
	BIT_VEC cppVar_63866;
	BIT_VEC cppVar_63867;
	BIT_VEC cppVar_63868;
	BIT_VEC cppVar_63869;
	BIT_VEC cppVar_63870;
	BIT_VEC cppVar_63871;
	BIT_VEC cppVar_63872;
	BIT_VEC cppVar_63873;
	BIT_VEC cppVar_63874;
	BIT_VEC cppVar_63861;
	BIT_VEC cppVar_63875;
	bool cppVar_63876;
	BIT_VEC cppVar_63879;
	BIT_VEC cppVar_63880;
	BIT_VEC cppVar_63881;
	bool cppVar_63882;
	BIT_VEC cppVar_63883;
	BIT_VEC cppVar_63884;
	BIT_VEC cppVar_63885;
	BIT_VEC cppVar_63886;
	BIT_VEC cppVar_63887;
	BIT_VEC cppVar_63888;
	BIT_VEC cppVar_63889;
	BIT_VEC cppVar_63890;
	BIT_VEC cppVar_63891;
	BIT_VEC cppVar_63878;
	BIT_VEC cppVar_63892;
	bool cppVar_63893;
	BIT_VEC cppVar_63896;
	BIT_VEC cppVar_63897;
	BIT_VEC cppVar_63898;
	bool cppVar_63899;
	BIT_VEC cppVar_63900;
	BIT_VEC cppVar_63901;
	BIT_VEC cppVar_63902;
	BIT_VEC cppVar_63903;
	BIT_VEC cppVar_63904;
	BIT_VEC cppVar_63905;
	BIT_VEC cppVar_63906;
	BIT_VEC cppVar_63907;
	BIT_VEC cppVar_63908;
	BIT_VEC cppVar_63895;
	BIT_VEC cppVar_63909;
	bool cppVar_63910;
	BIT_VEC cppVar_63913;
	BIT_VEC cppVar_63914;
	BIT_VEC cppVar_63915;
	bool cppVar_63916;
	BIT_VEC cppVar_63917;
	BIT_VEC cppVar_63918;
	BIT_VEC cppVar_63919;
	BIT_VEC cppVar_63920;
	BIT_VEC cppVar_63921;
	BIT_VEC cppVar_63922;
	BIT_VEC cppVar_63923;
	BIT_VEC cppVar_63924;
	BIT_VEC cppVar_63925;
	BIT_VEC cppVar_63912;
	BIT_VEC cppVar_63926;
	bool cppVar_63927;
	BIT_VEC cppVar_63930;
	BIT_VEC cppVar_63931;
	BIT_VEC cppVar_63932;
	bool cppVar_63933;
	BIT_VEC cppVar_63934;
	BIT_VEC cppVar_63935;
	BIT_VEC cppVar_63936;
	BIT_VEC cppVar_63937;
	BIT_VEC cppVar_63938;
	BIT_VEC cppVar_63939;
	BIT_VEC cppVar_63940;
	BIT_VEC cppVar_63941;
	BIT_VEC cppVar_63942;
	BIT_VEC cppVar_63929;
	BIT_VEC cppVar_63943;
	bool cppVar_63944;
	BIT_VEC cppVar_63945;
	BIT_VEC cppVar_63928;
	BIT_VEC cppVar_63911;
	BIT_VEC cppVar_63894;
	BIT_VEC cppVar_63877;
	BIT_VEC cppVar_63860;
	BIT_VEC cppVar_63843;
	BIT_VEC cppVar_63826;
	BIT_VEC cppVar_63809;
	BIT_VEC cppVar_63792;
	BIT_VEC cppVar_63775;
	BIT_VEC cppVar_63758;
	BIT_VEC cppVar_63741;
	BIT_VEC cppVar_63724;
	BIT_VEC cppVar_63707;
	BIT_VEC cppVar_63690;
	BIT_VEC cppVar_63673;
	BIT_VEC cppVar_63656;
	BIT_VEC cppVar_63639;
	BIT_VEC cppVar_63622;
	BIT_VEC cppVar_63605;
	BIT_VEC cppVar_63588;
	BIT_VEC cppVar_63555;
	BIT_VEC cppVar_63946;
	BIT_VEC cppVar_63947;
	BIT_VEC cppVar_63948;
	BIT_VEC cppVar_63949;
	BIT_VEC cppVar_63950;
	BIT_VEC cppVar_63951;
	BIT_VEC cppVar_63952;
	BIT_VEC cppVar_63953;
	BIT_VEC cppVar_63954;
	BIT_VEC cppVar_63527;
	BIT_VEC cppVar_63956;
	BIT_VEC cppVar_63957;
	bool cppVar_63958;
	BIT_VEC cppVar_63960;
	BIT_VEC cppVar_63961;
	BIT_VEC cppVar_63962;
	BIT_VEC cppVar_63963;
	bool cppVar_63964;
	BIT_VEC cppVar_63966;
	BIT_VEC cppVar_63967;
	BIT_VEC cppVar_63968;
	BIT_VEC cppVar_63969;
	bool cppVar_63970;
	BIT_VEC cppVar_63971;
	BIT_VEC cppVar_63972;
	BIT_VEC cppVar_63973;
	BIT_VEC cppVar_63975;
	BIT_VEC cppVar_63976;
	BIT_VEC cppVar_63977;
	bool cppVar_63978;
	BIT_VEC cppVar_63980;
	BIT_VEC cppVar_63981;
	BIT_VEC cppVar_63982;
	bool cppVar_63983;
	BIT_VEC cppVar_63985;
	BIT_VEC cppVar_63986;
	BIT_VEC cppVar_63987;
	bool cppVar_63988;
	BIT_VEC cppVar_63990;
	BIT_VEC cppVar_63991;
	BIT_VEC cppVar_63992;
	bool cppVar_63993;
	BIT_VEC cppVar_63995;
	BIT_VEC cppVar_63996;
	BIT_VEC cppVar_63997;
	bool cppVar_63998;
	BIT_VEC cppVar_64000;
	BIT_VEC cppVar_64001;
	BIT_VEC cppVar_64002;
	bool cppVar_64003;
	BIT_VEC cppVar_64005;
	BIT_VEC cppVar_64006;
	BIT_VEC cppVar_64007;
	bool cppVar_64008;
	BIT_VEC cppVar_64010;
	BIT_VEC cppVar_64011;
	BIT_VEC cppVar_64012;
	bool cppVar_64013;
	BIT_VEC cppVar_64015;
	BIT_VEC cppVar_64016;
	BIT_VEC cppVar_64017;
	bool cppVar_64018;
	BIT_VEC cppVar_64020;
	BIT_VEC cppVar_64021;
	BIT_VEC cppVar_64022;
	bool cppVar_64023;
	BIT_VEC cppVar_64025;
	BIT_VEC cppVar_64026;
	BIT_VEC cppVar_64027;
	bool cppVar_64028;
	BIT_VEC cppVar_64030;
	BIT_VEC cppVar_64031;
	BIT_VEC cppVar_64032;
	bool cppVar_64033;
	BIT_VEC cppVar_64035;
	BIT_VEC cppVar_64036;
	BIT_VEC cppVar_64037;
	bool cppVar_64038;
	BIT_VEC cppVar_64040;
	BIT_VEC cppVar_64041;
	BIT_VEC cppVar_64042;
	bool cppVar_64043;
	BIT_VEC cppVar_64045;
	BIT_VEC cppVar_64046;
	BIT_VEC cppVar_64047;
	bool cppVar_64048;
	BIT_VEC cppVar_64050;
	BIT_VEC cppVar_64051;
	BIT_VEC cppVar_64052;
	bool cppVar_64053;
	BIT_VEC cppVar_64055;
	BIT_VEC cppVar_64056;
	BIT_VEC cppVar_64057;
	bool cppVar_64058;
	BIT_VEC cppVar_64060;
	BIT_VEC cppVar_64061;
	BIT_VEC cppVar_64062;
	bool cppVar_64063;
	BIT_VEC cppVar_64065;
	BIT_VEC cppVar_64066;
	BIT_VEC cppVar_64067;
	bool cppVar_64068;
	BIT_VEC cppVar_64070;
	BIT_VEC cppVar_64071;
	BIT_VEC cppVar_64072;
	bool cppVar_64073;
	BIT_VEC cppVar_64075;
	BIT_VEC cppVar_64076;
	BIT_VEC cppVar_64077;
	bool cppVar_64078;
	BIT_VEC cppVar_64079;
	BIT_VEC cppVar_64074;
	BIT_VEC cppVar_64069;
	BIT_VEC cppVar_64064;
	BIT_VEC cppVar_64059;
	BIT_VEC cppVar_64054;
	BIT_VEC cppVar_64049;
	BIT_VEC cppVar_64044;
	BIT_VEC cppVar_64039;
	BIT_VEC cppVar_64034;
	BIT_VEC cppVar_64029;
	BIT_VEC cppVar_64024;
	BIT_VEC cppVar_64019;
	BIT_VEC cppVar_64014;
	BIT_VEC cppVar_64009;
	BIT_VEC cppVar_64004;
	BIT_VEC cppVar_63999;
	BIT_VEC cppVar_63994;
	BIT_VEC cppVar_63989;
	BIT_VEC cppVar_63984;
	BIT_VEC cppVar_63979;
	BIT_VEC cppVar_63974;
	BIT_VEC cppVar_63965;
	BIT_VEC cppVar_64080;
	BIT_VEC cppVar_64081;
	BIT_VEC cppVar_63959;
	BIT_VEC cppVar_63955;
	BIT_VEC cppVar_63519;
	BIT_VEC cppVar_63388;
	BIT_VEC cppVar_63262;
	BIT_VEC cppVar_63133;
	BIT_VEC cppVar_63007;
	BIT_VEC cppVar_62878;
	BIT_VEC cppVar_62752;
	BIT_VEC cppVar_62623;
	BIT_VEC cppVar_62610;
	BIT_VEC cppVar_62484;
	BIT_VEC cppVar_62467;
	BIT_VEC cppVar_62450;
	BIT_VEC cppVar_62300;
	BIT_VEC cppVar_62150;
	BIT_VEC cppVar_62000;
	BIT_VEC cppVar_61850;
	BIT_VEC cppVar_61700;
	BIT_VEC cppVar_61550;
	BIT_VEC cppVar_61400;
	BIT_VEC cppVar_61250;
	BIT_VEC cppVar_60818;
	BIT_VEC cppVar_59988;
	BIT_VEC cppVar_59974;
	BIT_VEC cppVar_59963;
	BIT_VEC cppVar_59531;
	cppVar_59532 = ROM.rd(PC);
	cppVar_59534 = (cppVar_59532 == 210);
	if (cppVar_59534) {
	cppVar_59538 = PC + 1;
	cppVar_59538 = (cppVar_59538 & cppMask_un_16_);
	cppVar_59539 = ROM.rd(cppVar_59538);
	cppVar_59540 = (cppVar_59539 >> 7) & cppMask_un_1_;
	cppVar_59542 = (cppVar_59540 == 1);
	if (cppVar_59542) {
	cppVar_59543 = PC + 1;
	cppVar_59543 = (cppVar_59543 & cppMask_un_16_);
	cppVar_59544 = ROM.rd(cppVar_59543);
	cppVar_59545 = (cppVar_59544 >> 3) & cppMask_un_5_;
	cppVar_59547 = (cppVar_59545 << 3) | 0;
	cppVar_59547 = (cppVar_59547 & cppMask_un_8_);
	cppVar_59536 = cppVar_59547;
	} else {
	cppVar_59548 = PC + 1;
	cppVar_59548 = (cppVar_59548 & cppMask_un_16_);
	cppVar_59549 = ROM.rd(cppVar_59548);
	cppVar_59550 = (cppVar_59549 >> 3) & cppMask_un_5_;
	cppVar_59551 = (cppVar_59550 & cppMask_un_5_);
	cppVar_59553 = cppVar_59551 + 32;
	cppVar_59553 = (cppVar_59553 & cppMask_un_8_);
	cppVar_59536 = cppVar_59553;
	}
	cppVar_59555 = (cppVar_59536 == 152);
	if (cppVar_59555) {
	cppVar_59557 = PC + 1;
	cppVar_59557 = (cppVar_59557 & cppMask_un_16_);
	cppVar_59558 = ROM.rd(cppVar_59557);
	cppVar_59559 = (cppVar_59558 >> 0) & cppMask_un_3_;
	cppVar_59560 = (cppVar_59559 & cppMask_un_3_);
	cppVar_59561 = 1 << static_cast<unsigned>(cppVar_59560);
	cppVar_59561 = (cppVar_59561 & cppMask_un_8_);
	cppVar_59562 = ~cppVar_59561;
	cppVar_59565 = PC + 1;
	cppVar_59565 = (cppVar_59565 & cppMask_un_16_);
	cppVar_59566 = ROM.rd(cppVar_59565);
	cppVar_59567 = (cppVar_59566 >> 7) & cppMask_un_1_;
	cppVar_59568 = (cppVar_59567 == 1);
	if (cppVar_59568) {
	cppVar_59569 = PC + 1;
	cppVar_59569 = (cppVar_59569 & cppMask_un_16_);
	cppVar_59570 = ROM.rd(cppVar_59569);
	cppVar_59571 = (cppVar_59570 >> 3) & cppMask_un_5_;
	cppVar_59572 = (cppVar_59571 << 3) | 0;
	cppVar_59572 = (cppVar_59572 & cppMask_un_8_);
	cppVar_59564 = cppVar_59572;
	} else {
	cppVar_59573 = PC + 1;
	cppVar_59573 = (cppVar_59573 & cppMask_un_16_);
	cppVar_59574 = ROM.rd(cppVar_59573);
	cppVar_59575 = (cppVar_59574 >> 3) & cppMask_un_5_;
	cppVar_59576 = (cppVar_59575 & cppMask_un_5_);
	cppVar_59577 = cppVar_59576 + 32;
	cppVar_59577 = (cppVar_59577 & cppMask_un_8_);
	cppVar_59564 = cppVar_59577;
	}
	cppVar_59578 = (cppVar_59564 >> 7) & cppMask_un_1_;
	cppVar_59580 = (cppVar_59578 == 0);
	if (cppVar_59580) {
	cppVar_59582 = PC + 1;
	cppVar_59582 = (cppVar_59582 & cppMask_un_16_);
	cppVar_59583 = ROM.rd(cppVar_59582);
	cppVar_59584 = (cppVar_59583 >> 7) & cppMask_un_1_;
	cppVar_59585 = (cppVar_59584 == 1);
	if (cppVar_59585) {
	cppVar_59586 = PC + 1;
	cppVar_59586 = (cppVar_59586 & cppMask_un_16_);
	cppVar_59587 = ROM.rd(cppVar_59586);
	cppVar_59588 = (cppVar_59587 >> 3) & cppMask_un_5_;
	cppVar_59589 = (cppVar_59588 << 3) | 0;
	cppVar_59589 = (cppVar_59589 & cppMask_un_8_);
	cppVar_59581 = cppVar_59589;
	} else {
	cppVar_59590 = PC + 1;
	cppVar_59590 = (cppVar_59590 & cppMask_un_16_);
	cppVar_59591 = ROM.rd(cppVar_59590);
	cppVar_59592 = (cppVar_59591 >> 3) & cppMask_un_5_;
	cppVar_59593 = (cppVar_59592 & cppMask_un_5_);
	cppVar_59594 = cppVar_59593 + 32;
	cppVar_59594 = (cppVar_59594 & cppMask_un_8_);
	cppVar_59581 = cppVar_59594;
	}
	cppVar_59595 = IRAM.rd(cppVar_59581);
	cppVar_59563 = cppVar_59595;
	} else {
	cppVar_59598 = PC + 1;
	cppVar_59598 = (cppVar_59598 & cppMask_un_16_);
	cppVar_59599 = ROM.rd(cppVar_59598);
	cppVar_59600 = (cppVar_59599 >> 7) & cppMask_un_1_;
	cppVar_59601 = (cppVar_59600 == 1);
	if (cppVar_59601) {
	cppVar_59602 = PC + 1;
	cppVar_59602 = (cppVar_59602 & cppMask_un_16_);
	cppVar_59603 = ROM.rd(cppVar_59602);
	cppVar_59604 = (cppVar_59603 >> 3) & cppMask_un_5_;
	cppVar_59605 = (cppVar_59604 << 3) | 0;
	cppVar_59605 = (cppVar_59605 & cppMask_un_8_);
	cppVar_59597 = cppVar_59605;
	} else {
	cppVar_59606 = PC + 1;
	cppVar_59606 = (cppVar_59606 & cppMask_un_16_);
	cppVar_59607 = ROM.rd(cppVar_59606);
	cppVar_59608 = (cppVar_59607 >> 3) & cppMask_un_5_;
	cppVar_59609 = (cppVar_59608 & cppMask_un_5_);
	cppVar_59610 = cppVar_59609 + 32;
	cppVar_59610 = (cppVar_59610 & cppMask_un_8_);
	cppVar_59597 = cppVar_59610;
	}
	cppVar_59612 = (cppVar_59597 == 128);
	if (cppVar_59612) {
	cppVar_59596 = P0;
	} else {
	cppVar_59615 = PC + 1;
	cppVar_59615 = (cppVar_59615 & cppMask_un_16_);
	cppVar_59616 = ROM.rd(cppVar_59615);
	cppVar_59617 = (cppVar_59616 >> 7) & cppMask_un_1_;
	cppVar_59618 = (cppVar_59617 == 1);
	if (cppVar_59618) {
	cppVar_59619 = PC + 1;
	cppVar_59619 = (cppVar_59619 & cppMask_un_16_);
	cppVar_59620 = ROM.rd(cppVar_59619);
	cppVar_59621 = (cppVar_59620 >> 3) & cppMask_un_5_;
	cppVar_59622 = (cppVar_59621 << 3) | 0;
	cppVar_59622 = (cppVar_59622 & cppMask_un_8_);
	cppVar_59614 = cppVar_59622;
	} else {
	cppVar_59623 = PC + 1;
	cppVar_59623 = (cppVar_59623 & cppMask_un_16_);
	cppVar_59624 = ROM.rd(cppVar_59623);
	cppVar_59625 = (cppVar_59624 >> 3) & cppMask_un_5_;
	cppVar_59626 = (cppVar_59625 & cppMask_un_5_);
	cppVar_59627 = cppVar_59626 + 32;
	cppVar_59627 = (cppVar_59627 & cppMask_un_8_);
	cppVar_59614 = cppVar_59627;
	}
	cppVar_59629 = (cppVar_59614 == 129);
	if (cppVar_59629) {
	cppVar_59613 = SP;
	} else {
	cppVar_59632 = PC + 1;
	cppVar_59632 = (cppVar_59632 & cppMask_un_16_);
	cppVar_59633 = ROM.rd(cppVar_59632);
	cppVar_59634 = (cppVar_59633 >> 7) & cppMask_un_1_;
	cppVar_59635 = (cppVar_59634 == 1);
	if (cppVar_59635) {
	cppVar_59636 = PC + 1;
	cppVar_59636 = (cppVar_59636 & cppMask_un_16_);
	cppVar_59637 = ROM.rd(cppVar_59636);
	cppVar_59638 = (cppVar_59637 >> 3) & cppMask_un_5_;
	cppVar_59639 = (cppVar_59638 << 3) | 0;
	cppVar_59639 = (cppVar_59639 & cppMask_un_8_);
	cppVar_59631 = cppVar_59639;
	} else {
	cppVar_59640 = PC + 1;
	cppVar_59640 = (cppVar_59640 & cppMask_un_16_);
	cppVar_59641 = ROM.rd(cppVar_59640);
	cppVar_59642 = (cppVar_59641 >> 3) & cppMask_un_5_;
	cppVar_59643 = (cppVar_59642 & cppMask_un_5_);
	cppVar_59644 = cppVar_59643 + 32;
	cppVar_59644 = (cppVar_59644 & cppMask_un_8_);
	cppVar_59631 = cppVar_59644;
	}
	cppVar_59646 = (cppVar_59631 == 130);
	if (cppVar_59646) {
	cppVar_59630 = DPL;
	} else {
	cppVar_59649 = PC + 1;
	cppVar_59649 = (cppVar_59649 & cppMask_un_16_);
	cppVar_59650 = ROM.rd(cppVar_59649);
	cppVar_59651 = (cppVar_59650 >> 7) & cppMask_un_1_;
	cppVar_59652 = (cppVar_59651 == 1);
	if (cppVar_59652) {
	cppVar_59653 = PC + 1;
	cppVar_59653 = (cppVar_59653 & cppMask_un_16_);
	cppVar_59654 = ROM.rd(cppVar_59653);
	cppVar_59655 = (cppVar_59654 >> 3) & cppMask_un_5_;
	cppVar_59656 = (cppVar_59655 << 3) | 0;
	cppVar_59656 = (cppVar_59656 & cppMask_un_8_);
	cppVar_59648 = cppVar_59656;
	} else {
	cppVar_59657 = PC + 1;
	cppVar_59657 = (cppVar_59657 & cppMask_un_16_);
	cppVar_59658 = ROM.rd(cppVar_59657);
	cppVar_59659 = (cppVar_59658 >> 3) & cppMask_un_5_;
	cppVar_59660 = (cppVar_59659 & cppMask_un_5_);
	cppVar_59661 = cppVar_59660 + 32;
	cppVar_59661 = (cppVar_59661 & cppMask_un_8_);
	cppVar_59648 = cppVar_59661;
	}
	cppVar_59663 = (cppVar_59648 == 131);
	if (cppVar_59663) {
	cppVar_59647 = DPH;
	} else {
	cppVar_59666 = PC + 1;
	cppVar_59666 = (cppVar_59666 & cppMask_un_16_);
	cppVar_59667 = ROM.rd(cppVar_59666);
	cppVar_59668 = (cppVar_59667 >> 7) & cppMask_un_1_;
	cppVar_59669 = (cppVar_59668 == 1);
	if (cppVar_59669) {
	cppVar_59670 = PC + 1;
	cppVar_59670 = (cppVar_59670 & cppMask_un_16_);
	cppVar_59671 = ROM.rd(cppVar_59670);
	cppVar_59672 = (cppVar_59671 >> 3) & cppMask_un_5_;
	cppVar_59673 = (cppVar_59672 << 3) | 0;
	cppVar_59673 = (cppVar_59673 & cppMask_un_8_);
	cppVar_59665 = cppVar_59673;
	} else {
	cppVar_59674 = PC + 1;
	cppVar_59674 = (cppVar_59674 & cppMask_un_16_);
	cppVar_59675 = ROM.rd(cppVar_59674);
	cppVar_59676 = (cppVar_59675 >> 3) & cppMask_un_5_;
	cppVar_59677 = (cppVar_59676 & cppMask_un_5_);
	cppVar_59678 = cppVar_59677 + 32;
	cppVar_59678 = (cppVar_59678 & cppMask_un_8_);
	cppVar_59665 = cppVar_59678;
	}
	cppVar_59680 = (cppVar_59665 == 135);
	if (cppVar_59680) {
	cppVar_59664 = PCON;
	} else {
	cppVar_59683 = PC + 1;
	cppVar_59683 = (cppVar_59683 & cppMask_un_16_);
	cppVar_59684 = ROM.rd(cppVar_59683);
	cppVar_59685 = (cppVar_59684 >> 7) & cppMask_un_1_;
	cppVar_59686 = (cppVar_59685 == 1);
	if (cppVar_59686) {
	cppVar_59687 = PC + 1;
	cppVar_59687 = (cppVar_59687 & cppMask_un_16_);
	cppVar_59688 = ROM.rd(cppVar_59687);
	cppVar_59689 = (cppVar_59688 >> 3) & cppMask_un_5_;
	cppVar_59690 = (cppVar_59689 << 3) | 0;
	cppVar_59690 = (cppVar_59690 & cppMask_un_8_);
	cppVar_59682 = cppVar_59690;
	} else {
	cppVar_59691 = PC + 1;
	cppVar_59691 = (cppVar_59691 & cppMask_un_16_);
	cppVar_59692 = ROM.rd(cppVar_59691);
	cppVar_59693 = (cppVar_59692 >> 3) & cppMask_un_5_;
	cppVar_59694 = (cppVar_59693 & cppMask_un_5_);
	cppVar_59695 = cppVar_59694 + 32;
	cppVar_59695 = (cppVar_59695 & cppMask_un_8_);
	cppVar_59682 = cppVar_59695;
	}
	cppVar_59697 = (cppVar_59682 == 136);
	if (cppVar_59697) {
	cppVar_59681 = TCON;
	} else {
	cppVar_59700 = PC + 1;
	cppVar_59700 = (cppVar_59700 & cppMask_un_16_);
	cppVar_59701 = ROM.rd(cppVar_59700);
	cppVar_59702 = (cppVar_59701 >> 7) & cppMask_un_1_;
	cppVar_59703 = (cppVar_59702 == 1);
	if (cppVar_59703) {
	cppVar_59704 = PC + 1;
	cppVar_59704 = (cppVar_59704 & cppMask_un_16_);
	cppVar_59705 = ROM.rd(cppVar_59704);
	cppVar_59706 = (cppVar_59705 >> 3) & cppMask_un_5_;
	cppVar_59707 = (cppVar_59706 << 3) | 0;
	cppVar_59707 = (cppVar_59707 & cppMask_un_8_);
	cppVar_59699 = cppVar_59707;
	} else {
	cppVar_59708 = PC + 1;
	cppVar_59708 = (cppVar_59708 & cppMask_un_16_);
	cppVar_59709 = ROM.rd(cppVar_59708);
	cppVar_59710 = (cppVar_59709 >> 3) & cppMask_un_5_;
	cppVar_59711 = (cppVar_59710 & cppMask_un_5_);
	cppVar_59712 = cppVar_59711 + 32;
	cppVar_59712 = (cppVar_59712 & cppMask_un_8_);
	cppVar_59699 = cppVar_59712;
	}
	cppVar_59714 = (cppVar_59699 == 137);
	if (cppVar_59714) {
	cppVar_59698 = TMOD;
	} else {
	cppVar_59717 = PC + 1;
	cppVar_59717 = (cppVar_59717 & cppMask_un_16_);
	cppVar_59718 = ROM.rd(cppVar_59717);
	cppVar_59719 = (cppVar_59718 >> 7) & cppMask_un_1_;
	cppVar_59720 = (cppVar_59719 == 1);
	if (cppVar_59720) {
	cppVar_59721 = PC + 1;
	cppVar_59721 = (cppVar_59721 & cppMask_un_16_);
	cppVar_59722 = ROM.rd(cppVar_59721);
	cppVar_59723 = (cppVar_59722 >> 3) & cppMask_un_5_;
	cppVar_59724 = (cppVar_59723 << 3) | 0;
	cppVar_59724 = (cppVar_59724 & cppMask_un_8_);
	cppVar_59716 = cppVar_59724;
	} else {
	cppVar_59725 = PC + 1;
	cppVar_59725 = (cppVar_59725 & cppMask_un_16_);
	cppVar_59726 = ROM.rd(cppVar_59725);
	cppVar_59727 = (cppVar_59726 >> 3) & cppMask_un_5_;
	cppVar_59728 = (cppVar_59727 & cppMask_un_5_);
	cppVar_59729 = cppVar_59728 + 32;
	cppVar_59729 = (cppVar_59729 & cppMask_un_8_);
	cppVar_59716 = cppVar_59729;
	}
	cppVar_59731 = (cppVar_59716 == 138);
	if (cppVar_59731) {
	cppVar_59715 = TL0;
	} else {
	cppVar_59734 = PC + 1;
	cppVar_59734 = (cppVar_59734 & cppMask_un_16_);
	cppVar_59735 = ROM.rd(cppVar_59734);
	cppVar_59736 = (cppVar_59735 >> 7) & cppMask_un_1_;
	cppVar_59737 = (cppVar_59736 == 1);
	if (cppVar_59737) {
	cppVar_59738 = PC + 1;
	cppVar_59738 = (cppVar_59738 & cppMask_un_16_);
	cppVar_59739 = ROM.rd(cppVar_59738);
	cppVar_59740 = (cppVar_59739 >> 3) & cppMask_un_5_;
	cppVar_59741 = (cppVar_59740 << 3) | 0;
	cppVar_59741 = (cppVar_59741 & cppMask_un_8_);
	cppVar_59733 = cppVar_59741;
	} else {
	cppVar_59742 = PC + 1;
	cppVar_59742 = (cppVar_59742 & cppMask_un_16_);
	cppVar_59743 = ROM.rd(cppVar_59742);
	cppVar_59744 = (cppVar_59743 >> 3) & cppMask_un_5_;
	cppVar_59745 = (cppVar_59744 & cppMask_un_5_);
	cppVar_59746 = cppVar_59745 + 32;
	cppVar_59746 = (cppVar_59746 & cppMask_un_8_);
	cppVar_59733 = cppVar_59746;
	}
	cppVar_59748 = (cppVar_59733 == 140);
	if (cppVar_59748) {
	cppVar_59732 = TH0;
	} else {
	cppVar_59751 = PC + 1;
	cppVar_59751 = (cppVar_59751 & cppMask_un_16_);
	cppVar_59752 = ROM.rd(cppVar_59751);
	cppVar_59753 = (cppVar_59752 >> 7) & cppMask_un_1_;
	cppVar_59754 = (cppVar_59753 == 1);
	if (cppVar_59754) {
	cppVar_59755 = PC + 1;
	cppVar_59755 = (cppVar_59755 & cppMask_un_16_);
	cppVar_59756 = ROM.rd(cppVar_59755);
	cppVar_59757 = (cppVar_59756 >> 3) & cppMask_un_5_;
	cppVar_59758 = (cppVar_59757 << 3) | 0;
	cppVar_59758 = (cppVar_59758 & cppMask_un_8_);
	cppVar_59750 = cppVar_59758;
	} else {
	cppVar_59759 = PC + 1;
	cppVar_59759 = (cppVar_59759 & cppMask_un_16_);
	cppVar_59760 = ROM.rd(cppVar_59759);
	cppVar_59761 = (cppVar_59760 >> 3) & cppMask_un_5_;
	cppVar_59762 = (cppVar_59761 & cppMask_un_5_);
	cppVar_59763 = cppVar_59762 + 32;
	cppVar_59763 = (cppVar_59763 & cppMask_un_8_);
	cppVar_59750 = cppVar_59763;
	}
	cppVar_59765 = (cppVar_59750 == 139);
	if (cppVar_59765) {
	cppVar_59749 = TL1;
	} else {
	cppVar_59768 = PC + 1;
	cppVar_59768 = (cppVar_59768 & cppMask_un_16_);
	cppVar_59769 = ROM.rd(cppVar_59768);
	cppVar_59770 = (cppVar_59769 >> 7) & cppMask_un_1_;
	cppVar_59771 = (cppVar_59770 == 1);
	if (cppVar_59771) {
	cppVar_59772 = PC + 1;
	cppVar_59772 = (cppVar_59772 & cppMask_un_16_);
	cppVar_59773 = ROM.rd(cppVar_59772);
	cppVar_59774 = (cppVar_59773 >> 3) & cppMask_un_5_;
	cppVar_59775 = (cppVar_59774 << 3) | 0;
	cppVar_59775 = (cppVar_59775 & cppMask_un_8_);
	cppVar_59767 = cppVar_59775;
	} else {
	cppVar_59776 = PC + 1;
	cppVar_59776 = (cppVar_59776 & cppMask_un_16_);
	cppVar_59777 = ROM.rd(cppVar_59776);
	cppVar_59778 = (cppVar_59777 >> 3) & cppMask_un_5_;
	cppVar_59779 = (cppVar_59778 & cppMask_un_5_);
	cppVar_59780 = cppVar_59779 + 32;
	cppVar_59780 = (cppVar_59780 & cppMask_un_8_);
	cppVar_59767 = cppVar_59780;
	}
	cppVar_59782 = (cppVar_59767 == 141);
	if (cppVar_59782) {
	cppVar_59766 = TH1;
	} else {
	cppVar_59785 = PC + 1;
	cppVar_59785 = (cppVar_59785 & cppMask_un_16_);
	cppVar_59786 = ROM.rd(cppVar_59785);
	cppVar_59787 = (cppVar_59786 >> 7) & cppMask_un_1_;
	cppVar_59788 = (cppVar_59787 == 1);
	if (cppVar_59788) {
	cppVar_59789 = PC + 1;
	cppVar_59789 = (cppVar_59789 & cppMask_un_16_);
	cppVar_59790 = ROM.rd(cppVar_59789);
	cppVar_59791 = (cppVar_59790 >> 3) & cppMask_un_5_;
	cppVar_59792 = (cppVar_59791 << 3) | 0;
	cppVar_59792 = (cppVar_59792 & cppMask_un_8_);
	cppVar_59784 = cppVar_59792;
	} else {
	cppVar_59793 = PC + 1;
	cppVar_59793 = (cppVar_59793 & cppMask_un_16_);
	cppVar_59794 = ROM.rd(cppVar_59793);
	cppVar_59795 = (cppVar_59794 >> 3) & cppMask_un_5_;
	cppVar_59796 = (cppVar_59795 & cppMask_un_5_);
	cppVar_59797 = cppVar_59796 + 32;
	cppVar_59797 = (cppVar_59797 & cppMask_un_8_);
	cppVar_59784 = cppVar_59797;
	}
	cppVar_59799 = (cppVar_59784 == 144);
	if (cppVar_59799) {
	cppVar_59783 = P1;
	} else {
	cppVar_59802 = PC + 1;
	cppVar_59802 = (cppVar_59802 & cppMask_un_16_);
	cppVar_59803 = ROM.rd(cppVar_59802);
	cppVar_59804 = (cppVar_59803 >> 7) & cppMask_un_1_;
	cppVar_59805 = (cppVar_59804 == 1);
	if (cppVar_59805) {
	cppVar_59806 = PC + 1;
	cppVar_59806 = (cppVar_59806 & cppMask_un_16_);
	cppVar_59807 = ROM.rd(cppVar_59806);
	cppVar_59808 = (cppVar_59807 >> 3) & cppMask_un_5_;
	cppVar_59809 = (cppVar_59808 << 3) | 0;
	cppVar_59809 = (cppVar_59809 & cppMask_un_8_);
	cppVar_59801 = cppVar_59809;
	} else {
	cppVar_59810 = PC + 1;
	cppVar_59810 = (cppVar_59810 & cppMask_un_16_);
	cppVar_59811 = ROM.rd(cppVar_59810);
	cppVar_59812 = (cppVar_59811 >> 3) & cppMask_un_5_;
	cppVar_59813 = (cppVar_59812 & cppMask_un_5_);
	cppVar_59814 = cppVar_59813 + 32;
	cppVar_59814 = (cppVar_59814 & cppMask_un_8_);
	cppVar_59801 = cppVar_59814;
	}
	cppVar_59816 = (cppVar_59801 == 152);
	if (cppVar_59816) {
	cppVar_59800 = SCON;
	} else {
	cppVar_59819 = PC + 1;
	cppVar_59819 = (cppVar_59819 & cppMask_un_16_);
	cppVar_59820 = ROM.rd(cppVar_59819);
	cppVar_59821 = (cppVar_59820 >> 7) & cppMask_un_1_;
	cppVar_59822 = (cppVar_59821 == 1);
	if (cppVar_59822) {
	cppVar_59823 = PC + 1;
	cppVar_59823 = (cppVar_59823 & cppMask_un_16_);
	cppVar_59824 = ROM.rd(cppVar_59823);
	cppVar_59825 = (cppVar_59824 >> 3) & cppMask_un_5_;
	cppVar_59826 = (cppVar_59825 << 3) | 0;
	cppVar_59826 = (cppVar_59826 & cppMask_un_8_);
	cppVar_59818 = cppVar_59826;
	} else {
	cppVar_59827 = PC + 1;
	cppVar_59827 = (cppVar_59827 & cppMask_un_16_);
	cppVar_59828 = ROM.rd(cppVar_59827);
	cppVar_59829 = (cppVar_59828 >> 3) & cppMask_un_5_;
	cppVar_59830 = (cppVar_59829 & cppMask_un_5_);
	cppVar_59831 = cppVar_59830 + 32;
	cppVar_59831 = (cppVar_59831 & cppMask_un_8_);
	cppVar_59818 = cppVar_59831;
	}
	cppVar_59833 = (cppVar_59818 == 153);
	if (cppVar_59833) {
	cppVar_59817 = SBUF;
	} else {
	cppVar_59836 = PC + 1;
	cppVar_59836 = (cppVar_59836 & cppMask_un_16_);
	cppVar_59837 = ROM.rd(cppVar_59836);
	cppVar_59838 = (cppVar_59837 >> 7) & cppMask_un_1_;
	cppVar_59839 = (cppVar_59838 == 1);
	if (cppVar_59839) {
	cppVar_59840 = PC + 1;
	cppVar_59840 = (cppVar_59840 & cppMask_un_16_);
	cppVar_59841 = ROM.rd(cppVar_59840);
	cppVar_59842 = (cppVar_59841 >> 3) & cppMask_un_5_;
	cppVar_59843 = (cppVar_59842 << 3) | 0;
	cppVar_59843 = (cppVar_59843 & cppMask_un_8_);
	cppVar_59835 = cppVar_59843;
	} else {
	cppVar_59844 = PC + 1;
	cppVar_59844 = (cppVar_59844 & cppMask_un_16_);
	cppVar_59845 = ROM.rd(cppVar_59844);
	cppVar_59846 = (cppVar_59845 >> 3) & cppMask_un_5_;
	cppVar_59847 = (cppVar_59846 & cppMask_un_5_);
	cppVar_59848 = cppVar_59847 + 32;
	cppVar_59848 = (cppVar_59848 & cppMask_un_8_);
	cppVar_59835 = cppVar_59848;
	}
	cppVar_59850 = (cppVar_59835 == 160);
	if (cppVar_59850) {
	cppVar_59834 = P2;
	} else {
	cppVar_59853 = PC + 1;
	cppVar_59853 = (cppVar_59853 & cppMask_un_16_);
	cppVar_59854 = ROM.rd(cppVar_59853);
	cppVar_59855 = (cppVar_59854 >> 7) & cppMask_un_1_;
	cppVar_59856 = (cppVar_59855 == 1);
	if (cppVar_59856) {
	cppVar_59857 = PC + 1;
	cppVar_59857 = (cppVar_59857 & cppMask_un_16_);
	cppVar_59858 = ROM.rd(cppVar_59857);
	cppVar_59859 = (cppVar_59858 >> 3) & cppMask_un_5_;
	cppVar_59860 = (cppVar_59859 << 3) | 0;
	cppVar_59860 = (cppVar_59860 & cppMask_un_8_);
	cppVar_59852 = cppVar_59860;
	} else {
	cppVar_59861 = PC + 1;
	cppVar_59861 = (cppVar_59861 & cppMask_un_16_);
	cppVar_59862 = ROM.rd(cppVar_59861);
	cppVar_59863 = (cppVar_59862 >> 3) & cppMask_un_5_;
	cppVar_59864 = (cppVar_59863 & cppMask_un_5_);
	cppVar_59865 = cppVar_59864 + 32;
	cppVar_59865 = (cppVar_59865 & cppMask_un_8_);
	cppVar_59852 = cppVar_59865;
	}
	cppVar_59867 = (cppVar_59852 == 168);
	if (cppVar_59867) {
	cppVar_59851 = IE;
	} else {
	cppVar_59870 = PC + 1;
	cppVar_59870 = (cppVar_59870 & cppMask_un_16_);
	cppVar_59871 = ROM.rd(cppVar_59870);
	cppVar_59872 = (cppVar_59871 >> 7) & cppMask_un_1_;
	cppVar_59873 = (cppVar_59872 == 1);
	if (cppVar_59873) {
	cppVar_59874 = PC + 1;
	cppVar_59874 = (cppVar_59874 & cppMask_un_16_);
	cppVar_59875 = ROM.rd(cppVar_59874);
	cppVar_59876 = (cppVar_59875 >> 3) & cppMask_un_5_;
	cppVar_59877 = (cppVar_59876 << 3) | 0;
	cppVar_59877 = (cppVar_59877 & cppMask_un_8_);
	cppVar_59869 = cppVar_59877;
	} else {
	cppVar_59878 = PC + 1;
	cppVar_59878 = (cppVar_59878 & cppMask_un_16_);
	cppVar_59879 = ROM.rd(cppVar_59878);
	cppVar_59880 = (cppVar_59879 >> 3) & cppMask_un_5_;
	cppVar_59881 = (cppVar_59880 & cppMask_un_5_);
	cppVar_59882 = cppVar_59881 + 32;
	cppVar_59882 = (cppVar_59882 & cppMask_un_8_);
	cppVar_59869 = cppVar_59882;
	}
	cppVar_59884 = (cppVar_59869 == 176);
	if (cppVar_59884) {
	cppVar_59868 = P3;
	} else {
	cppVar_59887 = PC + 1;
	cppVar_59887 = (cppVar_59887 & cppMask_un_16_);
	cppVar_59888 = ROM.rd(cppVar_59887);
	cppVar_59889 = (cppVar_59888 >> 7) & cppMask_un_1_;
	cppVar_59890 = (cppVar_59889 == 1);
	if (cppVar_59890) {
	cppVar_59891 = PC + 1;
	cppVar_59891 = (cppVar_59891 & cppMask_un_16_);
	cppVar_59892 = ROM.rd(cppVar_59891);
	cppVar_59893 = (cppVar_59892 >> 3) & cppMask_un_5_;
	cppVar_59894 = (cppVar_59893 << 3) | 0;
	cppVar_59894 = (cppVar_59894 & cppMask_un_8_);
	cppVar_59886 = cppVar_59894;
	} else {
	cppVar_59895 = PC + 1;
	cppVar_59895 = (cppVar_59895 & cppMask_un_16_);
	cppVar_59896 = ROM.rd(cppVar_59895);
	cppVar_59897 = (cppVar_59896 >> 3) & cppMask_un_5_;
	cppVar_59898 = (cppVar_59897 & cppMask_un_5_);
	cppVar_59899 = cppVar_59898 + 32;
	cppVar_59899 = (cppVar_59899 & cppMask_un_8_);
	cppVar_59886 = cppVar_59899;
	}
	cppVar_59901 = (cppVar_59886 == 184);
	if (cppVar_59901) {
	cppVar_59885 = IP;
	} else {
	cppVar_59904 = PC + 1;
	cppVar_59904 = (cppVar_59904 & cppMask_un_16_);
	cppVar_59905 = ROM.rd(cppVar_59904);
	cppVar_59906 = (cppVar_59905 >> 7) & cppMask_un_1_;
	cppVar_59907 = (cppVar_59906 == 1);
	if (cppVar_59907) {
	cppVar_59908 = PC + 1;
	cppVar_59908 = (cppVar_59908 & cppMask_un_16_);
	cppVar_59909 = ROM.rd(cppVar_59908);
	cppVar_59910 = (cppVar_59909 >> 3) & cppMask_un_5_;
	cppVar_59911 = (cppVar_59910 << 3) | 0;
	cppVar_59911 = (cppVar_59911 & cppMask_un_8_);
	cppVar_59903 = cppVar_59911;
	} else {
	cppVar_59912 = PC + 1;
	cppVar_59912 = (cppVar_59912 & cppMask_un_16_);
	cppVar_59913 = ROM.rd(cppVar_59912);
	cppVar_59914 = (cppVar_59913 >> 3) & cppMask_un_5_;
	cppVar_59915 = (cppVar_59914 & cppMask_un_5_);
	cppVar_59916 = cppVar_59915 + 32;
	cppVar_59916 = (cppVar_59916 & cppMask_un_8_);
	cppVar_59903 = cppVar_59916;
	}
	cppVar_59918 = (cppVar_59903 == 208);
	if (cppVar_59918) {
	cppVar_59902 = PSW;
	} else {
	cppVar_59921 = PC + 1;
	cppVar_59921 = (cppVar_59921 & cppMask_un_16_);
	cppVar_59922 = ROM.rd(cppVar_59921);
	cppVar_59923 = (cppVar_59922 >> 7) & cppMask_un_1_;
	cppVar_59924 = (cppVar_59923 == 1);
	if (cppVar_59924) {
	cppVar_59925 = PC + 1;
	cppVar_59925 = (cppVar_59925 & cppMask_un_16_);
	cppVar_59926 = ROM.rd(cppVar_59925);
	cppVar_59927 = (cppVar_59926 >> 3) & cppMask_un_5_;
	cppVar_59928 = (cppVar_59927 << 3) | 0;
	cppVar_59928 = (cppVar_59928 & cppMask_un_8_);
	cppVar_59920 = cppVar_59928;
	} else {
	cppVar_59929 = PC + 1;
	cppVar_59929 = (cppVar_59929 & cppMask_un_16_);
	cppVar_59930 = ROM.rd(cppVar_59929);
	cppVar_59931 = (cppVar_59930 >> 3) & cppMask_un_5_;
	cppVar_59932 = (cppVar_59931 & cppMask_un_5_);
	cppVar_59933 = cppVar_59932 + 32;
	cppVar_59933 = (cppVar_59933 & cppMask_un_8_);
	cppVar_59920 = cppVar_59933;
	}
	cppVar_59935 = (cppVar_59920 == 224);
	if (cppVar_59935) {
	cppVar_59919 = ACC;
	} else {
	cppVar_59938 = PC + 1;
	cppVar_59938 = (cppVar_59938 & cppMask_un_16_);
	cppVar_59939 = ROM.rd(cppVar_59938);
	cppVar_59940 = (cppVar_59939 >> 7) & cppMask_un_1_;
	cppVar_59941 = (cppVar_59940 == 1);
	if (cppVar_59941) {
	cppVar_59942 = PC + 1;
	cppVar_59942 = (cppVar_59942 & cppMask_un_16_);
	cppVar_59943 = ROM.rd(cppVar_59942);
	cppVar_59944 = (cppVar_59943 >> 3) & cppMask_un_5_;
	cppVar_59945 = (cppVar_59944 << 3) | 0;
	cppVar_59945 = (cppVar_59945 & cppMask_un_8_);
	cppVar_59937 = cppVar_59945;
	} else {
	cppVar_59946 = PC + 1;
	cppVar_59946 = (cppVar_59946 & cppMask_un_16_);
	cppVar_59947 = ROM.rd(cppVar_59946);
	cppVar_59948 = (cppVar_59947 >> 3) & cppMask_un_5_;
	cppVar_59949 = (cppVar_59948 & cppMask_un_5_);
	cppVar_59950 = cppVar_59949 + 32;
	cppVar_59950 = (cppVar_59950 & cppMask_un_8_);
	cppVar_59937 = cppVar_59950;
	}
	cppVar_59952 = (cppVar_59937 == 240);
	if (cppVar_59952) {
	cppVar_59936 = B;
	} else {
	cppVar_59936 = 0;
	}
	cppVar_59919 = cppVar_59936;
	}
	cppVar_59902 = cppVar_59919;
	}
	cppVar_59885 = cppVar_59902;
	}
	cppVar_59868 = cppVar_59885;
	}
	cppVar_59851 = cppVar_59868;
	}
	cppVar_59834 = cppVar_59851;
	}
	cppVar_59817 = cppVar_59834;
	}
	cppVar_59800 = cppVar_59817;
	}
	cppVar_59783 = cppVar_59800;
	}
	cppVar_59766 = cppVar_59783;
	}
	cppVar_59749 = cppVar_59766;
	}
	cppVar_59732 = cppVar_59749;
	}
	cppVar_59715 = cppVar_59732;
	}
	cppVar_59698 = cppVar_59715;
	}
	cppVar_59681 = cppVar_59698;
	}
	cppVar_59664 = cppVar_59681;
	}
	cppVar_59647 = cppVar_59664;
	}
	cppVar_59630 = cppVar_59647;
	}
	cppVar_59613 = cppVar_59630;
	}
	cppVar_59596 = cppVar_59613;
	}
	cppVar_59563 = cppVar_59596;
	}
	cppVar_59954 = cppVar_59562 & cppVar_59563;
	cppVar_59956 = 1;
	cppVar_59957 = PC + 1;
	cppVar_59957 = (cppVar_59957 & cppMask_un_16_);
	cppVar_59958 = ROM.rd(cppVar_59957);
	cppVar_59959 = (cppVar_59958 >> 0) & cppMask_un_3_;
	cppVar_59960 = (cppVar_59959 & cppMask_un_3_);
	cppVar_59961 = cppVar_59956 << static_cast<unsigned>(cppVar_59960);
	cppVar_59961 = (cppVar_59961 & cppMask_un_8_);
	cppVar_59962 = cppVar_59954 | cppVar_59961;
	cppVar_59535 = cppVar_59962;
	} else {
	cppVar_59535 = SCON;
	}
	cppVar_59531 = cppVar_59535;
	} else {
	cppVar_59964 = ROM.rd(PC);
	cppVar_59966 = (cppVar_59964 == 208);
	if (cppVar_59966) {
	cppVar_59969 = PC + 1;
	cppVar_59969 = (cppVar_59969 & cppMask_un_16_);
	cppVar_59970 = ROM.rd(cppVar_59969);
	cppVar_59972 = (cppVar_59970 == 152);
	if (cppVar_59972) {
	cppVar_59973 = IRAM.rd(SP);
	cppVar_59967 = cppVar_59973;
	} else {
	cppVar_59967 = SCON;
	}
	cppVar_59963 = cppVar_59967;
	} else {
	cppVar_59975 = ROM.rd(PC);
	cppVar_59977 = (cppVar_59975 == 245);
	cppVar_59978 = ROM.rd(PC);
	cppVar_59980 = (cppVar_59978 == 197);
	cppVar_59981 = cppVar_59977 || cppVar_59980;
	if (cppVar_59981) {
	cppVar_59984 = PC + 1;
	cppVar_59984 = (cppVar_59984 & cppMask_un_16_);
	cppVar_59985 = ROM.rd(cppVar_59984);
	cppVar_59987 = (cppVar_59985 == 152);
	if (cppVar_59987) {
	cppVar_59982 = ACC;
	} else {
	cppVar_59982 = SCON;
	}
	cppVar_59974 = cppVar_59982;
	} else {
	cppVar_59989 = ROM.rd(PC);
	cppVar_59991 = (cppVar_59989 == 178);
	if (cppVar_59991) {
	cppVar_59995 = PC + 1;
	cppVar_59995 = (cppVar_59995 & cppMask_un_16_);
	cppVar_59996 = ROM.rd(cppVar_59995);
	cppVar_59997 = (cppVar_59996 >> 7) & cppMask_un_1_;
	cppVar_59999 = (cppVar_59997 == 1);
	if (cppVar_59999) {
	cppVar_60000 = PC + 1;
	cppVar_60000 = (cppVar_60000 & cppMask_un_16_);
	cppVar_60001 = ROM.rd(cppVar_60000);
	cppVar_60002 = (cppVar_60001 >> 3) & cppMask_un_5_;
	cppVar_60004 = (cppVar_60002 << 3) | 0;
	cppVar_60004 = (cppVar_60004 & cppMask_un_8_);
	cppVar_59993 = cppVar_60004;
	} else {
	cppVar_60005 = PC + 1;
	cppVar_60005 = (cppVar_60005 & cppMask_un_16_);
	cppVar_60006 = ROM.rd(cppVar_60005);
	cppVar_60007 = (cppVar_60006 >> 3) & cppMask_un_5_;
	cppVar_60008 = (cppVar_60007 & cppMask_un_5_);
	cppVar_60010 = cppVar_60008 + 32;
	cppVar_60010 = (cppVar_60010 & cppMask_un_8_);
	cppVar_59993 = cppVar_60010;
	}
	cppVar_60012 = (cppVar_59993 == 152);
	if (cppVar_60012) {
	cppVar_60014 = PC + 1;
	cppVar_60014 = (cppVar_60014 & cppMask_un_16_);
	cppVar_60015 = ROM.rd(cppVar_60014);
	cppVar_60016 = (cppVar_60015 >> 0) & cppMask_un_3_;
	cppVar_60017 = (cppVar_60016 & cppMask_un_3_);
	cppVar_60018 = 1 << static_cast<unsigned>(cppVar_60017);
	cppVar_60018 = (cppVar_60018 & cppMask_un_8_);
	cppVar_60019 = ~cppVar_60018;
	cppVar_60022 = PC + 1;
	cppVar_60022 = (cppVar_60022 & cppMask_un_16_);
	cppVar_60023 = ROM.rd(cppVar_60022);
	cppVar_60024 = (cppVar_60023 >> 7) & cppMask_un_1_;
	cppVar_60025 = (cppVar_60024 == 1);
	if (cppVar_60025) {
	cppVar_60026 = PC + 1;
	cppVar_60026 = (cppVar_60026 & cppMask_un_16_);
	cppVar_60027 = ROM.rd(cppVar_60026);
	cppVar_60028 = (cppVar_60027 >> 3) & cppMask_un_5_;
	cppVar_60029 = (cppVar_60028 << 3) | 0;
	cppVar_60029 = (cppVar_60029 & cppMask_un_8_);
	cppVar_60021 = cppVar_60029;
	} else {
	cppVar_60030 = PC + 1;
	cppVar_60030 = (cppVar_60030 & cppMask_un_16_);
	cppVar_60031 = ROM.rd(cppVar_60030);
	cppVar_60032 = (cppVar_60031 >> 3) & cppMask_un_5_;
	cppVar_60033 = (cppVar_60032 & cppMask_un_5_);
	cppVar_60034 = cppVar_60033 + 32;
	cppVar_60034 = (cppVar_60034 & cppMask_un_8_);
	cppVar_60021 = cppVar_60034;
	}
	cppVar_60035 = (cppVar_60021 >> 7) & cppMask_un_1_;
	cppVar_60037 = (cppVar_60035 == 0);
	if (cppVar_60037) {
	cppVar_60039 = PC + 1;
	cppVar_60039 = (cppVar_60039 & cppMask_un_16_);
	cppVar_60040 = ROM.rd(cppVar_60039);
	cppVar_60041 = (cppVar_60040 >> 7) & cppMask_un_1_;
	cppVar_60042 = (cppVar_60041 == 1);
	if (cppVar_60042) {
	cppVar_60043 = PC + 1;
	cppVar_60043 = (cppVar_60043 & cppMask_un_16_);
	cppVar_60044 = ROM.rd(cppVar_60043);
	cppVar_60045 = (cppVar_60044 >> 3) & cppMask_un_5_;
	cppVar_60046 = (cppVar_60045 << 3) | 0;
	cppVar_60046 = (cppVar_60046 & cppMask_un_8_);
	cppVar_60038 = cppVar_60046;
	} else {
	cppVar_60047 = PC + 1;
	cppVar_60047 = (cppVar_60047 & cppMask_un_16_);
	cppVar_60048 = ROM.rd(cppVar_60047);
	cppVar_60049 = (cppVar_60048 >> 3) & cppMask_un_5_;
	cppVar_60050 = (cppVar_60049 & cppMask_un_5_);
	cppVar_60051 = cppVar_60050 + 32;
	cppVar_60051 = (cppVar_60051 & cppMask_un_8_);
	cppVar_60038 = cppVar_60051;
	}
	cppVar_60052 = IRAM.rd(cppVar_60038);
	cppVar_60020 = cppVar_60052;
	} else {
	cppVar_60055 = PC + 1;
	cppVar_60055 = (cppVar_60055 & cppMask_un_16_);
	cppVar_60056 = ROM.rd(cppVar_60055);
	cppVar_60057 = (cppVar_60056 >> 7) & cppMask_un_1_;
	cppVar_60058 = (cppVar_60057 == 1);
	if (cppVar_60058) {
	cppVar_60059 = PC + 1;
	cppVar_60059 = (cppVar_60059 & cppMask_un_16_);
	cppVar_60060 = ROM.rd(cppVar_60059);
	cppVar_60061 = (cppVar_60060 >> 3) & cppMask_un_5_;
	cppVar_60062 = (cppVar_60061 << 3) | 0;
	cppVar_60062 = (cppVar_60062 & cppMask_un_8_);
	cppVar_60054 = cppVar_60062;
	} else {
	cppVar_60063 = PC + 1;
	cppVar_60063 = (cppVar_60063 & cppMask_un_16_);
	cppVar_60064 = ROM.rd(cppVar_60063);
	cppVar_60065 = (cppVar_60064 >> 3) & cppMask_un_5_;
	cppVar_60066 = (cppVar_60065 & cppMask_un_5_);
	cppVar_60067 = cppVar_60066 + 32;
	cppVar_60067 = (cppVar_60067 & cppMask_un_8_);
	cppVar_60054 = cppVar_60067;
	}
	cppVar_60069 = (cppVar_60054 == 128);
	if (cppVar_60069) {
	cppVar_60053 = P0;
	} else {
	cppVar_60072 = PC + 1;
	cppVar_60072 = (cppVar_60072 & cppMask_un_16_);
	cppVar_60073 = ROM.rd(cppVar_60072);
	cppVar_60074 = (cppVar_60073 >> 7) & cppMask_un_1_;
	cppVar_60075 = (cppVar_60074 == 1);
	if (cppVar_60075) {
	cppVar_60076 = PC + 1;
	cppVar_60076 = (cppVar_60076 & cppMask_un_16_);
	cppVar_60077 = ROM.rd(cppVar_60076);
	cppVar_60078 = (cppVar_60077 >> 3) & cppMask_un_5_;
	cppVar_60079 = (cppVar_60078 << 3) | 0;
	cppVar_60079 = (cppVar_60079 & cppMask_un_8_);
	cppVar_60071 = cppVar_60079;
	} else {
	cppVar_60080 = PC + 1;
	cppVar_60080 = (cppVar_60080 & cppMask_un_16_);
	cppVar_60081 = ROM.rd(cppVar_60080);
	cppVar_60082 = (cppVar_60081 >> 3) & cppMask_un_5_;
	cppVar_60083 = (cppVar_60082 & cppMask_un_5_);
	cppVar_60084 = cppVar_60083 + 32;
	cppVar_60084 = (cppVar_60084 & cppMask_un_8_);
	cppVar_60071 = cppVar_60084;
	}
	cppVar_60086 = (cppVar_60071 == 129);
	if (cppVar_60086) {
	cppVar_60070 = SP;
	} else {
	cppVar_60089 = PC + 1;
	cppVar_60089 = (cppVar_60089 & cppMask_un_16_);
	cppVar_60090 = ROM.rd(cppVar_60089);
	cppVar_60091 = (cppVar_60090 >> 7) & cppMask_un_1_;
	cppVar_60092 = (cppVar_60091 == 1);
	if (cppVar_60092) {
	cppVar_60093 = PC + 1;
	cppVar_60093 = (cppVar_60093 & cppMask_un_16_);
	cppVar_60094 = ROM.rd(cppVar_60093);
	cppVar_60095 = (cppVar_60094 >> 3) & cppMask_un_5_;
	cppVar_60096 = (cppVar_60095 << 3) | 0;
	cppVar_60096 = (cppVar_60096 & cppMask_un_8_);
	cppVar_60088 = cppVar_60096;
	} else {
	cppVar_60097 = PC + 1;
	cppVar_60097 = (cppVar_60097 & cppMask_un_16_);
	cppVar_60098 = ROM.rd(cppVar_60097);
	cppVar_60099 = (cppVar_60098 >> 3) & cppMask_un_5_;
	cppVar_60100 = (cppVar_60099 & cppMask_un_5_);
	cppVar_60101 = cppVar_60100 + 32;
	cppVar_60101 = (cppVar_60101 & cppMask_un_8_);
	cppVar_60088 = cppVar_60101;
	}
	cppVar_60103 = (cppVar_60088 == 130);
	if (cppVar_60103) {
	cppVar_60087 = DPL;
	} else {
	cppVar_60106 = PC + 1;
	cppVar_60106 = (cppVar_60106 & cppMask_un_16_);
	cppVar_60107 = ROM.rd(cppVar_60106);
	cppVar_60108 = (cppVar_60107 >> 7) & cppMask_un_1_;
	cppVar_60109 = (cppVar_60108 == 1);
	if (cppVar_60109) {
	cppVar_60110 = PC + 1;
	cppVar_60110 = (cppVar_60110 & cppMask_un_16_);
	cppVar_60111 = ROM.rd(cppVar_60110);
	cppVar_60112 = (cppVar_60111 >> 3) & cppMask_un_5_;
	cppVar_60113 = (cppVar_60112 << 3) | 0;
	cppVar_60113 = (cppVar_60113 & cppMask_un_8_);
	cppVar_60105 = cppVar_60113;
	} else {
	cppVar_60114 = PC + 1;
	cppVar_60114 = (cppVar_60114 & cppMask_un_16_);
	cppVar_60115 = ROM.rd(cppVar_60114);
	cppVar_60116 = (cppVar_60115 >> 3) & cppMask_un_5_;
	cppVar_60117 = (cppVar_60116 & cppMask_un_5_);
	cppVar_60118 = cppVar_60117 + 32;
	cppVar_60118 = (cppVar_60118 & cppMask_un_8_);
	cppVar_60105 = cppVar_60118;
	}
	cppVar_60120 = (cppVar_60105 == 131);
	if (cppVar_60120) {
	cppVar_60104 = DPH;
	} else {
	cppVar_60123 = PC + 1;
	cppVar_60123 = (cppVar_60123 & cppMask_un_16_);
	cppVar_60124 = ROM.rd(cppVar_60123);
	cppVar_60125 = (cppVar_60124 >> 7) & cppMask_un_1_;
	cppVar_60126 = (cppVar_60125 == 1);
	if (cppVar_60126) {
	cppVar_60127 = PC + 1;
	cppVar_60127 = (cppVar_60127 & cppMask_un_16_);
	cppVar_60128 = ROM.rd(cppVar_60127);
	cppVar_60129 = (cppVar_60128 >> 3) & cppMask_un_5_;
	cppVar_60130 = (cppVar_60129 << 3) | 0;
	cppVar_60130 = (cppVar_60130 & cppMask_un_8_);
	cppVar_60122 = cppVar_60130;
	} else {
	cppVar_60131 = PC + 1;
	cppVar_60131 = (cppVar_60131 & cppMask_un_16_);
	cppVar_60132 = ROM.rd(cppVar_60131);
	cppVar_60133 = (cppVar_60132 >> 3) & cppMask_un_5_;
	cppVar_60134 = (cppVar_60133 & cppMask_un_5_);
	cppVar_60135 = cppVar_60134 + 32;
	cppVar_60135 = (cppVar_60135 & cppMask_un_8_);
	cppVar_60122 = cppVar_60135;
	}
	cppVar_60137 = (cppVar_60122 == 135);
	if (cppVar_60137) {
	cppVar_60121 = PCON;
	} else {
	cppVar_60140 = PC + 1;
	cppVar_60140 = (cppVar_60140 & cppMask_un_16_);
	cppVar_60141 = ROM.rd(cppVar_60140);
	cppVar_60142 = (cppVar_60141 >> 7) & cppMask_un_1_;
	cppVar_60143 = (cppVar_60142 == 1);
	if (cppVar_60143) {
	cppVar_60144 = PC + 1;
	cppVar_60144 = (cppVar_60144 & cppMask_un_16_);
	cppVar_60145 = ROM.rd(cppVar_60144);
	cppVar_60146 = (cppVar_60145 >> 3) & cppMask_un_5_;
	cppVar_60147 = (cppVar_60146 << 3) | 0;
	cppVar_60147 = (cppVar_60147 & cppMask_un_8_);
	cppVar_60139 = cppVar_60147;
	} else {
	cppVar_60148 = PC + 1;
	cppVar_60148 = (cppVar_60148 & cppMask_un_16_);
	cppVar_60149 = ROM.rd(cppVar_60148);
	cppVar_60150 = (cppVar_60149 >> 3) & cppMask_un_5_;
	cppVar_60151 = (cppVar_60150 & cppMask_un_5_);
	cppVar_60152 = cppVar_60151 + 32;
	cppVar_60152 = (cppVar_60152 & cppMask_un_8_);
	cppVar_60139 = cppVar_60152;
	}
	cppVar_60154 = (cppVar_60139 == 136);
	if (cppVar_60154) {
	cppVar_60138 = TCON;
	} else {
	cppVar_60157 = PC + 1;
	cppVar_60157 = (cppVar_60157 & cppMask_un_16_);
	cppVar_60158 = ROM.rd(cppVar_60157);
	cppVar_60159 = (cppVar_60158 >> 7) & cppMask_un_1_;
	cppVar_60160 = (cppVar_60159 == 1);
	if (cppVar_60160) {
	cppVar_60161 = PC + 1;
	cppVar_60161 = (cppVar_60161 & cppMask_un_16_);
	cppVar_60162 = ROM.rd(cppVar_60161);
	cppVar_60163 = (cppVar_60162 >> 3) & cppMask_un_5_;
	cppVar_60164 = (cppVar_60163 << 3) | 0;
	cppVar_60164 = (cppVar_60164 & cppMask_un_8_);
	cppVar_60156 = cppVar_60164;
	} else {
	cppVar_60165 = PC + 1;
	cppVar_60165 = (cppVar_60165 & cppMask_un_16_);
	cppVar_60166 = ROM.rd(cppVar_60165);
	cppVar_60167 = (cppVar_60166 >> 3) & cppMask_un_5_;
	cppVar_60168 = (cppVar_60167 & cppMask_un_5_);
	cppVar_60169 = cppVar_60168 + 32;
	cppVar_60169 = (cppVar_60169 & cppMask_un_8_);
	cppVar_60156 = cppVar_60169;
	}
	cppVar_60171 = (cppVar_60156 == 137);
	if (cppVar_60171) {
	cppVar_60155 = TMOD;
	} else {
	cppVar_60174 = PC + 1;
	cppVar_60174 = (cppVar_60174 & cppMask_un_16_);
	cppVar_60175 = ROM.rd(cppVar_60174);
	cppVar_60176 = (cppVar_60175 >> 7) & cppMask_un_1_;
	cppVar_60177 = (cppVar_60176 == 1);
	if (cppVar_60177) {
	cppVar_60178 = PC + 1;
	cppVar_60178 = (cppVar_60178 & cppMask_un_16_);
	cppVar_60179 = ROM.rd(cppVar_60178);
	cppVar_60180 = (cppVar_60179 >> 3) & cppMask_un_5_;
	cppVar_60181 = (cppVar_60180 << 3) | 0;
	cppVar_60181 = (cppVar_60181 & cppMask_un_8_);
	cppVar_60173 = cppVar_60181;
	} else {
	cppVar_60182 = PC + 1;
	cppVar_60182 = (cppVar_60182 & cppMask_un_16_);
	cppVar_60183 = ROM.rd(cppVar_60182);
	cppVar_60184 = (cppVar_60183 >> 3) & cppMask_un_5_;
	cppVar_60185 = (cppVar_60184 & cppMask_un_5_);
	cppVar_60186 = cppVar_60185 + 32;
	cppVar_60186 = (cppVar_60186 & cppMask_un_8_);
	cppVar_60173 = cppVar_60186;
	}
	cppVar_60188 = (cppVar_60173 == 138);
	if (cppVar_60188) {
	cppVar_60172 = TL0;
	} else {
	cppVar_60191 = PC + 1;
	cppVar_60191 = (cppVar_60191 & cppMask_un_16_);
	cppVar_60192 = ROM.rd(cppVar_60191);
	cppVar_60193 = (cppVar_60192 >> 7) & cppMask_un_1_;
	cppVar_60194 = (cppVar_60193 == 1);
	if (cppVar_60194) {
	cppVar_60195 = PC + 1;
	cppVar_60195 = (cppVar_60195 & cppMask_un_16_);
	cppVar_60196 = ROM.rd(cppVar_60195);
	cppVar_60197 = (cppVar_60196 >> 3) & cppMask_un_5_;
	cppVar_60198 = (cppVar_60197 << 3) | 0;
	cppVar_60198 = (cppVar_60198 & cppMask_un_8_);
	cppVar_60190 = cppVar_60198;
	} else {
	cppVar_60199 = PC + 1;
	cppVar_60199 = (cppVar_60199 & cppMask_un_16_);
	cppVar_60200 = ROM.rd(cppVar_60199);
	cppVar_60201 = (cppVar_60200 >> 3) & cppMask_un_5_;
	cppVar_60202 = (cppVar_60201 & cppMask_un_5_);
	cppVar_60203 = cppVar_60202 + 32;
	cppVar_60203 = (cppVar_60203 & cppMask_un_8_);
	cppVar_60190 = cppVar_60203;
	}
	cppVar_60205 = (cppVar_60190 == 140);
	if (cppVar_60205) {
	cppVar_60189 = TH0;
	} else {
	cppVar_60208 = PC + 1;
	cppVar_60208 = (cppVar_60208 & cppMask_un_16_);
	cppVar_60209 = ROM.rd(cppVar_60208);
	cppVar_60210 = (cppVar_60209 >> 7) & cppMask_un_1_;
	cppVar_60211 = (cppVar_60210 == 1);
	if (cppVar_60211) {
	cppVar_60212 = PC + 1;
	cppVar_60212 = (cppVar_60212 & cppMask_un_16_);
	cppVar_60213 = ROM.rd(cppVar_60212);
	cppVar_60214 = (cppVar_60213 >> 3) & cppMask_un_5_;
	cppVar_60215 = (cppVar_60214 << 3) | 0;
	cppVar_60215 = (cppVar_60215 & cppMask_un_8_);
	cppVar_60207 = cppVar_60215;
	} else {
	cppVar_60216 = PC + 1;
	cppVar_60216 = (cppVar_60216 & cppMask_un_16_);
	cppVar_60217 = ROM.rd(cppVar_60216);
	cppVar_60218 = (cppVar_60217 >> 3) & cppMask_un_5_;
	cppVar_60219 = (cppVar_60218 & cppMask_un_5_);
	cppVar_60220 = cppVar_60219 + 32;
	cppVar_60220 = (cppVar_60220 & cppMask_un_8_);
	cppVar_60207 = cppVar_60220;
	}
	cppVar_60222 = (cppVar_60207 == 139);
	if (cppVar_60222) {
	cppVar_60206 = TL1;
	} else {
	cppVar_60225 = PC + 1;
	cppVar_60225 = (cppVar_60225 & cppMask_un_16_);
	cppVar_60226 = ROM.rd(cppVar_60225);
	cppVar_60227 = (cppVar_60226 >> 7) & cppMask_un_1_;
	cppVar_60228 = (cppVar_60227 == 1);
	if (cppVar_60228) {
	cppVar_60229 = PC + 1;
	cppVar_60229 = (cppVar_60229 & cppMask_un_16_);
	cppVar_60230 = ROM.rd(cppVar_60229);
	cppVar_60231 = (cppVar_60230 >> 3) & cppMask_un_5_;
	cppVar_60232 = (cppVar_60231 << 3) | 0;
	cppVar_60232 = (cppVar_60232 & cppMask_un_8_);
	cppVar_60224 = cppVar_60232;
	} else {
	cppVar_60233 = PC + 1;
	cppVar_60233 = (cppVar_60233 & cppMask_un_16_);
	cppVar_60234 = ROM.rd(cppVar_60233);
	cppVar_60235 = (cppVar_60234 >> 3) & cppMask_un_5_;
	cppVar_60236 = (cppVar_60235 & cppMask_un_5_);
	cppVar_60237 = cppVar_60236 + 32;
	cppVar_60237 = (cppVar_60237 & cppMask_un_8_);
	cppVar_60224 = cppVar_60237;
	}
	cppVar_60239 = (cppVar_60224 == 141);
	if (cppVar_60239) {
	cppVar_60223 = TH1;
	} else {
	cppVar_60242 = PC + 1;
	cppVar_60242 = (cppVar_60242 & cppMask_un_16_);
	cppVar_60243 = ROM.rd(cppVar_60242);
	cppVar_60244 = (cppVar_60243 >> 7) & cppMask_un_1_;
	cppVar_60245 = (cppVar_60244 == 1);
	if (cppVar_60245) {
	cppVar_60246 = PC + 1;
	cppVar_60246 = (cppVar_60246 & cppMask_un_16_);
	cppVar_60247 = ROM.rd(cppVar_60246);
	cppVar_60248 = (cppVar_60247 >> 3) & cppMask_un_5_;
	cppVar_60249 = (cppVar_60248 << 3) | 0;
	cppVar_60249 = (cppVar_60249 & cppMask_un_8_);
	cppVar_60241 = cppVar_60249;
	} else {
	cppVar_60250 = PC + 1;
	cppVar_60250 = (cppVar_60250 & cppMask_un_16_);
	cppVar_60251 = ROM.rd(cppVar_60250);
	cppVar_60252 = (cppVar_60251 >> 3) & cppMask_un_5_;
	cppVar_60253 = (cppVar_60252 & cppMask_un_5_);
	cppVar_60254 = cppVar_60253 + 32;
	cppVar_60254 = (cppVar_60254 & cppMask_un_8_);
	cppVar_60241 = cppVar_60254;
	}
	cppVar_60256 = (cppVar_60241 == 144);
	if (cppVar_60256) {
	cppVar_60240 = P1;
	} else {
	cppVar_60259 = PC + 1;
	cppVar_60259 = (cppVar_60259 & cppMask_un_16_);
	cppVar_60260 = ROM.rd(cppVar_60259);
	cppVar_60261 = (cppVar_60260 >> 7) & cppMask_un_1_;
	cppVar_60262 = (cppVar_60261 == 1);
	if (cppVar_60262) {
	cppVar_60263 = PC + 1;
	cppVar_60263 = (cppVar_60263 & cppMask_un_16_);
	cppVar_60264 = ROM.rd(cppVar_60263);
	cppVar_60265 = (cppVar_60264 >> 3) & cppMask_un_5_;
	cppVar_60266 = (cppVar_60265 << 3) | 0;
	cppVar_60266 = (cppVar_60266 & cppMask_un_8_);
	cppVar_60258 = cppVar_60266;
	} else {
	cppVar_60267 = PC + 1;
	cppVar_60267 = (cppVar_60267 & cppMask_un_16_);
	cppVar_60268 = ROM.rd(cppVar_60267);
	cppVar_60269 = (cppVar_60268 >> 3) & cppMask_un_5_;
	cppVar_60270 = (cppVar_60269 & cppMask_un_5_);
	cppVar_60271 = cppVar_60270 + 32;
	cppVar_60271 = (cppVar_60271 & cppMask_un_8_);
	cppVar_60258 = cppVar_60271;
	}
	cppVar_60273 = (cppVar_60258 == 152);
	if (cppVar_60273) {
	cppVar_60257 = SCON;
	} else {
	cppVar_60276 = PC + 1;
	cppVar_60276 = (cppVar_60276 & cppMask_un_16_);
	cppVar_60277 = ROM.rd(cppVar_60276);
	cppVar_60278 = (cppVar_60277 >> 7) & cppMask_un_1_;
	cppVar_60279 = (cppVar_60278 == 1);
	if (cppVar_60279) {
	cppVar_60280 = PC + 1;
	cppVar_60280 = (cppVar_60280 & cppMask_un_16_);
	cppVar_60281 = ROM.rd(cppVar_60280);
	cppVar_60282 = (cppVar_60281 >> 3) & cppMask_un_5_;
	cppVar_60283 = (cppVar_60282 << 3) | 0;
	cppVar_60283 = (cppVar_60283 & cppMask_un_8_);
	cppVar_60275 = cppVar_60283;
	} else {
	cppVar_60284 = PC + 1;
	cppVar_60284 = (cppVar_60284 & cppMask_un_16_);
	cppVar_60285 = ROM.rd(cppVar_60284);
	cppVar_60286 = (cppVar_60285 >> 3) & cppMask_un_5_;
	cppVar_60287 = (cppVar_60286 & cppMask_un_5_);
	cppVar_60288 = cppVar_60287 + 32;
	cppVar_60288 = (cppVar_60288 & cppMask_un_8_);
	cppVar_60275 = cppVar_60288;
	}
	cppVar_60290 = (cppVar_60275 == 153);
	if (cppVar_60290) {
	cppVar_60274 = SBUF;
	} else {
	cppVar_60293 = PC + 1;
	cppVar_60293 = (cppVar_60293 & cppMask_un_16_);
	cppVar_60294 = ROM.rd(cppVar_60293);
	cppVar_60295 = (cppVar_60294 >> 7) & cppMask_un_1_;
	cppVar_60296 = (cppVar_60295 == 1);
	if (cppVar_60296) {
	cppVar_60297 = PC + 1;
	cppVar_60297 = (cppVar_60297 & cppMask_un_16_);
	cppVar_60298 = ROM.rd(cppVar_60297);
	cppVar_60299 = (cppVar_60298 >> 3) & cppMask_un_5_;
	cppVar_60300 = (cppVar_60299 << 3) | 0;
	cppVar_60300 = (cppVar_60300 & cppMask_un_8_);
	cppVar_60292 = cppVar_60300;
	} else {
	cppVar_60301 = PC + 1;
	cppVar_60301 = (cppVar_60301 & cppMask_un_16_);
	cppVar_60302 = ROM.rd(cppVar_60301);
	cppVar_60303 = (cppVar_60302 >> 3) & cppMask_un_5_;
	cppVar_60304 = (cppVar_60303 & cppMask_un_5_);
	cppVar_60305 = cppVar_60304 + 32;
	cppVar_60305 = (cppVar_60305 & cppMask_un_8_);
	cppVar_60292 = cppVar_60305;
	}
	cppVar_60307 = (cppVar_60292 == 160);
	if (cppVar_60307) {
	cppVar_60291 = P2;
	} else {
	cppVar_60310 = PC + 1;
	cppVar_60310 = (cppVar_60310 & cppMask_un_16_);
	cppVar_60311 = ROM.rd(cppVar_60310);
	cppVar_60312 = (cppVar_60311 >> 7) & cppMask_un_1_;
	cppVar_60313 = (cppVar_60312 == 1);
	if (cppVar_60313) {
	cppVar_60314 = PC + 1;
	cppVar_60314 = (cppVar_60314 & cppMask_un_16_);
	cppVar_60315 = ROM.rd(cppVar_60314);
	cppVar_60316 = (cppVar_60315 >> 3) & cppMask_un_5_;
	cppVar_60317 = (cppVar_60316 << 3) | 0;
	cppVar_60317 = (cppVar_60317 & cppMask_un_8_);
	cppVar_60309 = cppVar_60317;
	} else {
	cppVar_60318 = PC + 1;
	cppVar_60318 = (cppVar_60318 & cppMask_un_16_);
	cppVar_60319 = ROM.rd(cppVar_60318);
	cppVar_60320 = (cppVar_60319 >> 3) & cppMask_un_5_;
	cppVar_60321 = (cppVar_60320 & cppMask_un_5_);
	cppVar_60322 = cppVar_60321 + 32;
	cppVar_60322 = (cppVar_60322 & cppMask_un_8_);
	cppVar_60309 = cppVar_60322;
	}
	cppVar_60324 = (cppVar_60309 == 168);
	if (cppVar_60324) {
	cppVar_60308 = IE;
	} else {
	cppVar_60327 = PC + 1;
	cppVar_60327 = (cppVar_60327 & cppMask_un_16_);
	cppVar_60328 = ROM.rd(cppVar_60327);
	cppVar_60329 = (cppVar_60328 >> 7) & cppMask_un_1_;
	cppVar_60330 = (cppVar_60329 == 1);
	if (cppVar_60330) {
	cppVar_60331 = PC + 1;
	cppVar_60331 = (cppVar_60331 & cppMask_un_16_);
	cppVar_60332 = ROM.rd(cppVar_60331);
	cppVar_60333 = (cppVar_60332 >> 3) & cppMask_un_5_;
	cppVar_60334 = (cppVar_60333 << 3) | 0;
	cppVar_60334 = (cppVar_60334 & cppMask_un_8_);
	cppVar_60326 = cppVar_60334;
	} else {
	cppVar_60335 = PC + 1;
	cppVar_60335 = (cppVar_60335 & cppMask_un_16_);
	cppVar_60336 = ROM.rd(cppVar_60335);
	cppVar_60337 = (cppVar_60336 >> 3) & cppMask_un_5_;
	cppVar_60338 = (cppVar_60337 & cppMask_un_5_);
	cppVar_60339 = cppVar_60338 + 32;
	cppVar_60339 = (cppVar_60339 & cppMask_un_8_);
	cppVar_60326 = cppVar_60339;
	}
	cppVar_60341 = (cppVar_60326 == 176);
	if (cppVar_60341) {
	cppVar_60325 = P3;
	} else {
	cppVar_60344 = PC + 1;
	cppVar_60344 = (cppVar_60344 & cppMask_un_16_);
	cppVar_60345 = ROM.rd(cppVar_60344);
	cppVar_60346 = (cppVar_60345 >> 7) & cppMask_un_1_;
	cppVar_60347 = (cppVar_60346 == 1);
	if (cppVar_60347) {
	cppVar_60348 = PC + 1;
	cppVar_60348 = (cppVar_60348 & cppMask_un_16_);
	cppVar_60349 = ROM.rd(cppVar_60348);
	cppVar_60350 = (cppVar_60349 >> 3) & cppMask_un_5_;
	cppVar_60351 = (cppVar_60350 << 3) | 0;
	cppVar_60351 = (cppVar_60351 & cppMask_un_8_);
	cppVar_60343 = cppVar_60351;
	} else {
	cppVar_60352 = PC + 1;
	cppVar_60352 = (cppVar_60352 & cppMask_un_16_);
	cppVar_60353 = ROM.rd(cppVar_60352);
	cppVar_60354 = (cppVar_60353 >> 3) & cppMask_un_5_;
	cppVar_60355 = (cppVar_60354 & cppMask_un_5_);
	cppVar_60356 = cppVar_60355 + 32;
	cppVar_60356 = (cppVar_60356 & cppMask_un_8_);
	cppVar_60343 = cppVar_60356;
	}
	cppVar_60358 = (cppVar_60343 == 184);
	if (cppVar_60358) {
	cppVar_60342 = IP;
	} else {
	cppVar_60361 = PC + 1;
	cppVar_60361 = (cppVar_60361 & cppMask_un_16_);
	cppVar_60362 = ROM.rd(cppVar_60361);
	cppVar_60363 = (cppVar_60362 >> 7) & cppMask_un_1_;
	cppVar_60364 = (cppVar_60363 == 1);
	if (cppVar_60364) {
	cppVar_60365 = PC + 1;
	cppVar_60365 = (cppVar_60365 & cppMask_un_16_);
	cppVar_60366 = ROM.rd(cppVar_60365);
	cppVar_60367 = (cppVar_60366 >> 3) & cppMask_un_5_;
	cppVar_60368 = (cppVar_60367 << 3) | 0;
	cppVar_60368 = (cppVar_60368 & cppMask_un_8_);
	cppVar_60360 = cppVar_60368;
	} else {
	cppVar_60369 = PC + 1;
	cppVar_60369 = (cppVar_60369 & cppMask_un_16_);
	cppVar_60370 = ROM.rd(cppVar_60369);
	cppVar_60371 = (cppVar_60370 >> 3) & cppMask_un_5_;
	cppVar_60372 = (cppVar_60371 & cppMask_un_5_);
	cppVar_60373 = cppVar_60372 + 32;
	cppVar_60373 = (cppVar_60373 & cppMask_un_8_);
	cppVar_60360 = cppVar_60373;
	}
	cppVar_60375 = (cppVar_60360 == 208);
	if (cppVar_60375) {
	cppVar_60359 = PSW;
	} else {
	cppVar_60378 = PC + 1;
	cppVar_60378 = (cppVar_60378 & cppMask_un_16_);
	cppVar_60379 = ROM.rd(cppVar_60378);
	cppVar_60380 = (cppVar_60379 >> 7) & cppMask_un_1_;
	cppVar_60381 = (cppVar_60380 == 1);
	if (cppVar_60381) {
	cppVar_60382 = PC + 1;
	cppVar_60382 = (cppVar_60382 & cppMask_un_16_);
	cppVar_60383 = ROM.rd(cppVar_60382);
	cppVar_60384 = (cppVar_60383 >> 3) & cppMask_un_5_;
	cppVar_60385 = (cppVar_60384 << 3) | 0;
	cppVar_60385 = (cppVar_60385 & cppMask_un_8_);
	cppVar_60377 = cppVar_60385;
	} else {
	cppVar_60386 = PC + 1;
	cppVar_60386 = (cppVar_60386 & cppMask_un_16_);
	cppVar_60387 = ROM.rd(cppVar_60386);
	cppVar_60388 = (cppVar_60387 >> 3) & cppMask_un_5_;
	cppVar_60389 = (cppVar_60388 & cppMask_un_5_);
	cppVar_60390 = cppVar_60389 + 32;
	cppVar_60390 = (cppVar_60390 & cppMask_un_8_);
	cppVar_60377 = cppVar_60390;
	}
	cppVar_60392 = (cppVar_60377 == 224);
	if (cppVar_60392) {
	cppVar_60376 = ACC;
	} else {
	cppVar_60395 = PC + 1;
	cppVar_60395 = (cppVar_60395 & cppMask_un_16_);
	cppVar_60396 = ROM.rd(cppVar_60395);
	cppVar_60397 = (cppVar_60396 >> 7) & cppMask_un_1_;
	cppVar_60398 = (cppVar_60397 == 1);
	if (cppVar_60398) {
	cppVar_60399 = PC + 1;
	cppVar_60399 = (cppVar_60399 & cppMask_un_16_);
	cppVar_60400 = ROM.rd(cppVar_60399);
	cppVar_60401 = (cppVar_60400 >> 3) & cppMask_un_5_;
	cppVar_60402 = (cppVar_60401 << 3) | 0;
	cppVar_60402 = (cppVar_60402 & cppMask_un_8_);
	cppVar_60394 = cppVar_60402;
	} else {
	cppVar_60403 = PC + 1;
	cppVar_60403 = (cppVar_60403 & cppMask_un_16_);
	cppVar_60404 = ROM.rd(cppVar_60403);
	cppVar_60405 = (cppVar_60404 >> 3) & cppMask_un_5_;
	cppVar_60406 = (cppVar_60405 & cppMask_un_5_);
	cppVar_60407 = cppVar_60406 + 32;
	cppVar_60407 = (cppVar_60407 & cppMask_un_8_);
	cppVar_60394 = cppVar_60407;
	}
	cppVar_60409 = (cppVar_60394 == 240);
	if (cppVar_60409) {
	cppVar_60393 = B;
	} else {
	cppVar_60393 = 0;
	}
	cppVar_60376 = cppVar_60393;
	}
	cppVar_60359 = cppVar_60376;
	}
	cppVar_60342 = cppVar_60359;
	}
	cppVar_60325 = cppVar_60342;
	}
	cppVar_60308 = cppVar_60325;
	}
	cppVar_60291 = cppVar_60308;
	}
	cppVar_60274 = cppVar_60291;
	}
	cppVar_60257 = cppVar_60274;
	}
	cppVar_60240 = cppVar_60257;
	}
	cppVar_60223 = cppVar_60240;
	}
	cppVar_60206 = cppVar_60223;
	}
	cppVar_60189 = cppVar_60206;
	}
	cppVar_60172 = cppVar_60189;
	}
	cppVar_60155 = cppVar_60172;
	}
	cppVar_60138 = cppVar_60155;
	}
	cppVar_60121 = cppVar_60138;
	}
	cppVar_60104 = cppVar_60121;
	}
	cppVar_60087 = cppVar_60104;
	}
	cppVar_60070 = cppVar_60087;
	}
	cppVar_60053 = cppVar_60070;
	}
	cppVar_60020 = cppVar_60053;
	}
	cppVar_60411 = cppVar_60019 & cppVar_60020;
	cppVar_60414 = PC + 1;
	cppVar_60414 = (cppVar_60414 & cppMask_un_16_);
	cppVar_60415 = ROM.rd(cppVar_60414);
	cppVar_60416 = (cppVar_60415 >> 7) & cppMask_un_1_;
	cppVar_60418 = (cppVar_60416 == 1);
	if (cppVar_60418) {
	cppVar_60419 = PC + 1;
	cppVar_60419 = (cppVar_60419 & cppMask_un_16_);
	cppVar_60420 = ROM.rd(cppVar_60419);
	cppVar_60421 = (cppVar_60420 >> 3) & cppMask_un_5_;
	cppVar_60423 = (cppVar_60421 << 3) | 0;
	cppVar_60423 = (cppVar_60423 & cppMask_un_8_);
	cppVar_60413 = cppVar_60423;
	} else {
	cppVar_60424 = PC + 1;
	cppVar_60424 = (cppVar_60424 & cppMask_un_16_);
	cppVar_60425 = ROM.rd(cppVar_60424);
	cppVar_60426 = (cppVar_60425 >> 3) & cppMask_un_5_;
	cppVar_60427 = (cppVar_60426 & cppMask_un_5_);
	cppVar_60429 = cppVar_60427 + 32;
	cppVar_60429 = (cppVar_60429 & cppMask_un_8_);
	cppVar_60413 = cppVar_60429;
	}
	cppVar_60430 = (cppVar_60413 >> 7) & cppMask_un_1_;
	cppVar_60432 = (cppVar_60430 == 0);
	if (cppVar_60432) {
	cppVar_60434 = PC + 1;
	cppVar_60434 = (cppVar_60434 & cppMask_un_16_);
	cppVar_60435 = ROM.rd(cppVar_60434);
	cppVar_60436 = (cppVar_60435 >> 7) & cppMask_un_1_;
	cppVar_60437 = (cppVar_60436 == 1);
	if (cppVar_60437) {
	cppVar_60438 = PC + 1;
	cppVar_60438 = (cppVar_60438 & cppMask_un_16_);
	cppVar_60439 = ROM.rd(cppVar_60438);
	cppVar_60440 = (cppVar_60439 >> 3) & cppMask_un_5_;
	cppVar_60441 = (cppVar_60440 << 3) | 0;
	cppVar_60441 = (cppVar_60441 & cppMask_un_8_);
	cppVar_60433 = cppVar_60441;
	} else {
	cppVar_60442 = PC + 1;
	cppVar_60442 = (cppVar_60442 & cppMask_un_16_);
	cppVar_60443 = ROM.rd(cppVar_60442);
	cppVar_60444 = (cppVar_60443 >> 3) & cppMask_un_5_;
	cppVar_60445 = (cppVar_60444 & cppMask_un_5_);
	cppVar_60446 = cppVar_60445 + 32;
	cppVar_60446 = (cppVar_60446 & cppMask_un_8_);
	cppVar_60433 = cppVar_60446;
	}
	cppVar_60447 = IRAM.rd(cppVar_60433);
	cppVar_60412 = cppVar_60447;
	} else {
	cppVar_60450 = PC + 1;
	cppVar_60450 = (cppVar_60450 & cppMask_un_16_);
	cppVar_60451 = ROM.rd(cppVar_60450);
	cppVar_60452 = (cppVar_60451 >> 7) & cppMask_un_1_;
	cppVar_60453 = (cppVar_60452 == 1);
	if (cppVar_60453) {
	cppVar_60454 = PC + 1;
	cppVar_60454 = (cppVar_60454 & cppMask_un_16_);
	cppVar_60455 = ROM.rd(cppVar_60454);
	cppVar_60456 = (cppVar_60455 >> 3) & cppMask_un_5_;
	cppVar_60457 = (cppVar_60456 << 3) | 0;
	cppVar_60457 = (cppVar_60457 & cppMask_un_8_);
	cppVar_60449 = cppVar_60457;
	} else {
	cppVar_60458 = PC + 1;
	cppVar_60458 = (cppVar_60458 & cppMask_un_16_);
	cppVar_60459 = ROM.rd(cppVar_60458);
	cppVar_60460 = (cppVar_60459 >> 3) & cppMask_un_5_;
	cppVar_60461 = (cppVar_60460 & cppMask_un_5_);
	cppVar_60462 = cppVar_60461 + 32;
	cppVar_60462 = (cppVar_60462 & cppMask_un_8_);
	cppVar_60449 = cppVar_60462;
	}
	cppVar_60464 = (cppVar_60449 == 128);
	if (cppVar_60464) {
	cppVar_60448 = P0;
	} else {
	cppVar_60467 = PC + 1;
	cppVar_60467 = (cppVar_60467 & cppMask_un_16_);
	cppVar_60468 = ROM.rd(cppVar_60467);
	cppVar_60469 = (cppVar_60468 >> 7) & cppMask_un_1_;
	cppVar_60470 = (cppVar_60469 == 1);
	if (cppVar_60470) {
	cppVar_60471 = PC + 1;
	cppVar_60471 = (cppVar_60471 & cppMask_un_16_);
	cppVar_60472 = ROM.rd(cppVar_60471);
	cppVar_60473 = (cppVar_60472 >> 3) & cppMask_un_5_;
	cppVar_60474 = (cppVar_60473 << 3) | 0;
	cppVar_60474 = (cppVar_60474 & cppMask_un_8_);
	cppVar_60466 = cppVar_60474;
	} else {
	cppVar_60475 = PC + 1;
	cppVar_60475 = (cppVar_60475 & cppMask_un_16_);
	cppVar_60476 = ROM.rd(cppVar_60475);
	cppVar_60477 = (cppVar_60476 >> 3) & cppMask_un_5_;
	cppVar_60478 = (cppVar_60477 & cppMask_un_5_);
	cppVar_60479 = cppVar_60478 + 32;
	cppVar_60479 = (cppVar_60479 & cppMask_un_8_);
	cppVar_60466 = cppVar_60479;
	}
	cppVar_60481 = (cppVar_60466 == 129);
	if (cppVar_60481) {
	cppVar_60465 = SP;
	} else {
	cppVar_60484 = PC + 1;
	cppVar_60484 = (cppVar_60484 & cppMask_un_16_);
	cppVar_60485 = ROM.rd(cppVar_60484);
	cppVar_60486 = (cppVar_60485 >> 7) & cppMask_un_1_;
	cppVar_60487 = (cppVar_60486 == 1);
	if (cppVar_60487) {
	cppVar_60488 = PC + 1;
	cppVar_60488 = (cppVar_60488 & cppMask_un_16_);
	cppVar_60489 = ROM.rd(cppVar_60488);
	cppVar_60490 = (cppVar_60489 >> 3) & cppMask_un_5_;
	cppVar_60491 = (cppVar_60490 << 3) | 0;
	cppVar_60491 = (cppVar_60491 & cppMask_un_8_);
	cppVar_60483 = cppVar_60491;
	} else {
	cppVar_60492 = PC + 1;
	cppVar_60492 = (cppVar_60492 & cppMask_un_16_);
	cppVar_60493 = ROM.rd(cppVar_60492);
	cppVar_60494 = (cppVar_60493 >> 3) & cppMask_un_5_;
	cppVar_60495 = (cppVar_60494 & cppMask_un_5_);
	cppVar_60496 = cppVar_60495 + 32;
	cppVar_60496 = (cppVar_60496 & cppMask_un_8_);
	cppVar_60483 = cppVar_60496;
	}
	cppVar_60498 = (cppVar_60483 == 130);
	if (cppVar_60498) {
	cppVar_60482 = DPL;
	} else {
	cppVar_60501 = PC + 1;
	cppVar_60501 = (cppVar_60501 & cppMask_un_16_);
	cppVar_60502 = ROM.rd(cppVar_60501);
	cppVar_60503 = (cppVar_60502 >> 7) & cppMask_un_1_;
	cppVar_60504 = (cppVar_60503 == 1);
	if (cppVar_60504) {
	cppVar_60505 = PC + 1;
	cppVar_60505 = (cppVar_60505 & cppMask_un_16_);
	cppVar_60506 = ROM.rd(cppVar_60505);
	cppVar_60507 = (cppVar_60506 >> 3) & cppMask_un_5_;
	cppVar_60508 = (cppVar_60507 << 3) | 0;
	cppVar_60508 = (cppVar_60508 & cppMask_un_8_);
	cppVar_60500 = cppVar_60508;
	} else {
	cppVar_60509 = PC + 1;
	cppVar_60509 = (cppVar_60509 & cppMask_un_16_);
	cppVar_60510 = ROM.rd(cppVar_60509);
	cppVar_60511 = (cppVar_60510 >> 3) & cppMask_un_5_;
	cppVar_60512 = (cppVar_60511 & cppMask_un_5_);
	cppVar_60513 = cppVar_60512 + 32;
	cppVar_60513 = (cppVar_60513 & cppMask_un_8_);
	cppVar_60500 = cppVar_60513;
	}
	cppVar_60515 = (cppVar_60500 == 131);
	if (cppVar_60515) {
	cppVar_60499 = DPH;
	} else {
	cppVar_60518 = PC + 1;
	cppVar_60518 = (cppVar_60518 & cppMask_un_16_);
	cppVar_60519 = ROM.rd(cppVar_60518);
	cppVar_60520 = (cppVar_60519 >> 7) & cppMask_un_1_;
	cppVar_60521 = (cppVar_60520 == 1);
	if (cppVar_60521) {
	cppVar_60522 = PC + 1;
	cppVar_60522 = (cppVar_60522 & cppMask_un_16_);
	cppVar_60523 = ROM.rd(cppVar_60522);
	cppVar_60524 = (cppVar_60523 >> 3) & cppMask_un_5_;
	cppVar_60525 = (cppVar_60524 << 3) | 0;
	cppVar_60525 = (cppVar_60525 & cppMask_un_8_);
	cppVar_60517 = cppVar_60525;
	} else {
	cppVar_60526 = PC + 1;
	cppVar_60526 = (cppVar_60526 & cppMask_un_16_);
	cppVar_60527 = ROM.rd(cppVar_60526);
	cppVar_60528 = (cppVar_60527 >> 3) & cppMask_un_5_;
	cppVar_60529 = (cppVar_60528 & cppMask_un_5_);
	cppVar_60530 = cppVar_60529 + 32;
	cppVar_60530 = (cppVar_60530 & cppMask_un_8_);
	cppVar_60517 = cppVar_60530;
	}
	cppVar_60532 = (cppVar_60517 == 135);
	if (cppVar_60532) {
	cppVar_60516 = PCON;
	} else {
	cppVar_60535 = PC + 1;
	cppVar_60535 = (cppVar_60535 & cppMask_un_16_);
	cppVar_60536 = ROM.rd(cppVar_60535);
	cppVar_60537 = (cppVar_60536 >> 7) & cppMask_un_1_;
	cppVar_60538 = (cppVar_60537 == 1);
	if (cppVar_60538) {
	cppVar_60539 = PC + 1;
	cppVar_60539 = (cppVar_60539 & cppMask_un_16_);
	cppVar_60540 = ROM.rd(cppVar_60539);
	cppVar_60541 = (cppVar_60540 >> 3) & cppMask_un_5_;
	cppVar_60542 = (cppVar_60541 << 3) | 0;
	cppVar_60542 = (cppVar_60542 & cppMask_un_8_);
	cppVar_60534 = cppVar_60542;
	} else {
	cppVar_60543 = PC + 1;
	cppVar_60543 = (cppVar_60543 & cppMask_un_16_);
	cppVar_60544 = ROM.rd(cppVar_60543);
	cppVar_60545 = (cppVar_60544 >> 3) & cppMask_un_5_;
	cppVar_60546 = (cppVar_60545 & cppMask_un_5_);
	cppVar_60547 = cppVar_60546 + 32;
	cppVar_60547 = (cppVar_60547 & cppMask_un_8_);
	cppVar_60534 = cppVar_60547;
	}
	cppVar_60549 = (cppVar_60534 == 136);
	if (cppVar_60549) {
	cppVar_60533 = TCON;
	} else {
	cppVar_60552 = PC + 1;
	cppVar_60552 = (cppVar_60552 & cppMask_un_16_);
	cppVar_60553 = ROM.rd(cppVar_60552);
	cppVar_60554 = (cppVar_60553 >> 7) & cppMask_un_1_;
	cppVar_60555 = (cppVar_60554 == 1);
	if (cppVar_60555) {
	cppVar_60556 = PC + 1;
	cppVar_60556 = (cppVar_60556 & cppMask_un_16_);
	cppVar_60557 = ROM.rd(cppVar_60556);
	cppVar_60558 = (cppVar_60557 >> 3) & cppMask_un_5_;
	cppVar_60559 = (cppVar_60558 << 3) | 0;
	cppVar_60559 = (cppVar_60559 & cppMask_un_8_);
	cppVar_60551 = cppVar_60559;
	} else {
	cppVar_60560 = PC + 1;
	cppVar_60560 = (cppVar_60560 & cppMask_un_16_);
	cppVar_60561 = ROM.rd(cppVar_60560);
	cppVar_60562 = (cppVar_60561 >> 3) & cppMask_un_5_;
	cppVar_60563 = (cppVar_60562 & cppMask_un_5_);
	cppVar_60564 = cppVar_60563 + 32;
	cppVar_60564 = (cppVar_60564 & cppMask_un_8_);
	cppVar_60551 = cppVar_60564;
	}
	cppVar_60566 = (cppVar_60551 == 137);
	if (cppVar_60566) {
	cppVar_60550 = TMOD;
	} else {
	cppVar_60569 = PC + 1;
	cppVar_60569 = (cppVar_60569 & cppMask_un_16_);
	cppVar_60570 = ROM.rd(cppVar_60569);
	cppVar_60571 = (cppVar_60570 >> 7) & cppMask_un_1_;
	cppVar_60572 = (cppVar_60571 == 1);
	if (cppVar_60572) {
	cppVar_60573 = PC + 1;
	cppVar_60573 = (cppVar_60573 & cppMask_un_16_);
	cppVar_60574 = ROM.rd(cppVar_60573);
	cppVar_60575 = (cppVar_60574 >> 3) & cppMask_un_5_;
	cppVar_60576 = (cppVar_60575 << 3) | 0;
	cppVar_60576 = (cppVar_60576 & cppMask_un_8_);
	cppVar_60568 = cppVar_60576;
	} else {
	cppVar_60577 = PC + 1;
	cppVar_60577 = (cppVar_60577 & cppMask_un_16_);
	cppVar_60578 = ROM.rd(cppVar_60577);
	cppVar_60579 = (cppVar_60578 >> 3) & cppMask_un_5_;
	cppVar_60580 = (cppVar_60579 & cppMask_un_5_);
	cppVar_60581 = cppVar_60580 + 32;
	cppVar_60581 = (cppVar_60581 & cppMask_un_8_);
	cppVar_60568 = cppVar_60581;
	}
	cppVar_60583 = (cppVar_60568 == 138);
	if (cppVar_60583) {
	cppVar_60567 = TL0;
	} else {
	cppVar_60586 = PC + 1;
	cppVar_60586 = (cppVar_60586 & cppMask_un_16_);
	cppVar_60587 = ROM.rd(cppVar_60586);
	cppVar_60588 = (cppVar_60587 >> 7) & cppMask_un_1_;
	cppVar_60589 = (cppVar_60588 == 1);
	if (cppVar_60589) {
	cppVar_60590 = PC + 1;
	cppVar_60590 = (cppVar_60590 & cppMask_un_16_);
	cppVar_60591 = ROM.rd(cppVar_60590);
	cppVar_60592 = (cppVar_60591 >> 3) & cppMask_un_5_;
	cppVar_60593 = (cppVar_60592 << 3) | 0;
	cppVar_60593 = (cppVar_60593 & cppMask_un_8_);
	cppVar_60585 = cppVar_60593;
	} else {
	cppVar_60594 = PC + 1;
	cppVar_60594 = (cppVar_60594 & cppMask_un_16_);
	cppVar_60595 = ROM.rd(cppVar_60594);
	cppVar_60596 = (cppVar_60595 >> 3) & cppMask_un_5_;
	cppVar_60597 = (cppVar_60596 & cppMask_un_5_);
	cppVar_60598 = cppVar_60597 + 32;
	cppVar_60598 = (cppVar_60598 & cppMask_un_8_);
	cppVar_60585 = cppVar_60598;
	}
	cppVar_60600 = (cppVar_60585 == 140);
	if (cppVar_60600) {
	cppVar_60584 = TH0;
	} else {
	cppVar_60603 = PC + 1;
	cppVar_60603 = (cppVar_60603 & cppMask_un_16_);
	cppVar_60604 = ROM.rd(cppVar_60603);
	cppVar_60605 = (cppVar_60604 >> 7) & cppMask_un_1_;
	cppVar_60606 = (cppVar_60605 == 1);
	if (cppVar_60606) {
	cppVar_60607 = PC + 1;
	cppVar_60607 = (cppVar_60607 & cppMask_un_16_);
	cppVar_60608 = ROM.rd(cppVar_60607);
	cppVar_60609 = (cppVar_60608 >> 3) & cppMask_un_5_;
	cppVar_60610 = (cppVar_60609 << 3) | 0;
	cppVar_60610 = (cppVar_60610 & cppMask_un_8_);
	cppVar_60602 = cppVar_60610;
	} else {
	cppVar_60611 = PC + 1;
	cppVar_60611 = (cppVar_60611 & cppMask_un_16_);
	cppVar_60612 = ROM.rd(cppVar_60611);
	cppVar_60613 = (cppVar_60612 >> 3) & cppMask_un_5_;
	cppVar_60614 = (cppVar_60613 & cppMask_un_5_);
	cppVar_60615 = cppVar_60614 + 32;
	cppVar_60615 = (cppVar_60615 & cppMask_un_8_);
	cppVar_60602 = cppVar_60615;
	}
	cppVar_60617 = (cppVar_60602 == 139);
	if (cppVar_60617) {
	cppVar_60601 = TL1;
	} else {
	cppVar_60620 = PC + 1;
	cppVar_60620 = (cppVar_60620 & cppMask_un_16_);
	cppVar_60621 = ROM.rd(cppVar_60620);
	cppVar_60622 = (cppVar_60621 >> 7) & cppMask_un_1_;
	cppVar_60623 = (cppVar_60622 == 1);
	if (cppVar_60623) {
	cppVar_60624 = PC + 1;
	cppVar_60624 = (cppVar_60624 & cppMask_un_16_);
	cppVar_60625 = ROM.rd(cppVar_60624);
	cppVar_60626 = (cppVar_60625 >> 3) & cppMask_un_5_;
	cppVar_60627 = (cppVar_60626 << 3) | 0;
	cppVar_60627 = (cppVar_60627 & cppMask_un_8_);
	cppVar_60619 = cppVar_60627;
	} else {
	cppVar_60628 = PC + 1;
	cppVar_60628 = (cppVar_60628 & cppMask_un_16_);
	cppVar_60629 = ROM.rd(cppVar_60628);
	cppVar_60630 = (cppVar_60629 >> 3) & cppMask_un_5_;
	cppVar_60631 = (cppVar_60630 & cppMask_un_5_);
	cppVar_60632 = cppVar_60631 + 32;
	cppVar_60632 = (cppVar_60632 & cppMask_un_8_);
	cppVar_60619 = cppVar_60632;
	}
	cppVar_60634 = (cppVar_60619 == 141);
	if (cppVar_60634) {
	cppVar_60618 = TH1;
	} else {
	cppVar_60637 = PC + 1;
	cppVar_60637 = (cppVar_60637 & cppMask_un_16_);
	cppVar_60638 = ROM.rd(cppVar_60637);
	cppVar_60639 = (cppVar_60638 >> 7) & cppMask_un_1_;
	cppVar_60640 = (cppVar_60639 == 1);
	if (cppVar_60640) {
	cppVar_60641 = PC + 1;
	cppVar_60641 = (cppVar_60641 & cppMask_un_16_);
	cppVar_60642 = ROM.rd(cppVar_60641);
	cppVar_60643 = (cppVar_60642 >> 3) & cppMask_un_5_;
	cppVar_60644 = (cppVar_60643 << 3) | 0;
	cppVar_60644 = (cppVar_60644 & cppMask_un_8_);
	cppVar_60636 = cppVar_60644;
	} else {
	cppVar_60645 = PC + 1;
	cppVar_60645 = (cppVar_60645 & cppMask_un_16_);
	cppVar_60646 = ROM.rd(cppVar_60645);
	cppVar_60647 = (cppVar_60646 >> 3) & cppMask_un_5_;
	cppVar_60648 = (cppVar_60647 & cppMask_un_5_);
	cppVar_60649 = cppVar_60648 + 32;
	cppVar_60649 = (cppVar_60649 & cppMask_un_8_);
	cppVar_60636 = cppVar_60649;
	}
	cppVar_60651 = (cppVar_60636 == 144);
	if (cppVar_60651) {
	cppVar_60635 = P1;
	} else {
	cppVar_60654 = PC + 1;
	cppVar_60654 = (cppVar_60654 & cppMask_un_16_);
	cppVar_60655 = ROM.rd(cppVar_60654);
	cppVar_60656 = (cppVar_60655 >> 7) & cppMask_un_1_;
	cppVar_60657 = (cppVar_60656 == 1);
	if (cppVar_60657) {
	cppVar_60658 = PC + 1;
	cppVar_60658 = (cppVar_60658 & cppMask_un_16_);
	cppVar_60659 = ROM.rd(cppVar_60658);
	cppVar_60660 = (cppVar_60659 >> 3) & cppMask_un_5_;
	cppVar_60661 = (cppVar_60660 << 3) | 0;
	cppVar_60661 = (cppVar_60661 & cppMask_un_8_);
	cppVar_60653 = cppVar_60661;
	} else {
	cppVar_60662 = PC + 1;
	cppVar_60662 = (cppVar_60662 & cppMask_un_16_);
	cppVar_60663 = ROM.rd(cppVar_60662);
	cppVar_60664 = (cppVar_60663 >> 3) & cppMask_un_5_;
	cppVar_60665 = (cppVar_60664 & cppMask_un_5_);
	cppVar_60666 = cppVar_60665 + 32;
	cppVar_60666 = (cppVar_60666 & cppMask_un_8_);
	cppVar_60653 = cppVar_60666;
	}
	cppVar_60668 = (cppVar_60653 == 152);
	if (cppVar_60668) {
	cppVar_60652 = SCON;
	} else {
	cppVar_60671 = PC + 1;
	cppVar_60671 = (cppVar_60671 & cppMask_un_16_);
	cppVar_60672 = ROM.rd(cppVar_60671);
	cppVar_60673 = (cppVar_60672 >> 7) & cppMask_un_1_;
	cppVar_60674 = (cppVar_60673 == 1);
	if (cppVar_60674) {
	cppVar_60675 = PC + 1;
	cppVar_60675 = (cppVar_60675 & cppMask_un_16_);
	cppVar_60676 = ROM.rd(cppVar_60675);
	cppVar_60677 = (cppVar_60676 >> 3) & cppMask_un_5_;
	cppVar_60678 = (cppVar_60677 << 3) | 0;
	cppVar_60678 = (cppVar_60678 & cppMask_un_8_);
	cppVar_60670 = cppVar_60678;
	} else {
	cppVar_60679 = PC + 1;
	cppVar_60679 = (cppVar_60679 & cppMask_un_16_);
	cppVar_60680 = ROM.rd(cppVar_60679);
	cppVar_60681 = (cppVar_60680 >> 3) & cppMask_un_5_;
	cppVar_60682 = (cppVar_60681 & cppMask_un_5_);
	cppVar_60683 = cppVar_60682 + 32;
	cppVar_60683 = (cppVar_60683 & cppMask_un_8_);
	cppVar_60670 = cppVar_60683;
	}
	cppVar_60685 = (cppVar_60670 == 153);
	if (cppVar_60685) {
	cppVar_60669 = SBUF;
	} else {
	cppVar_60688 = PC + 1;
	cppVar_60688 = (cppVar_60688 & cppMask_un_16_);
	cppVar_60689 = ROM.rd(cppVar_60688);
	cppVar_60690 = (cppVar_60689 >> 7) & cppMask_un_1_;
	cppVar_60691 = (cppVar_60690 == 1);
	if (cppVar_60691) {
	cppVar_60692 = PC + 1;
	cppVar_60692 = (cppVar_60692 & cppMask_un_16_);
	cppVar_60693 = ROM.rd(cppVar_60692);
	cppVar_60694 = (cppVar_60693 >> 3) & cppMask_un_5_;
	cppVar_60695 = (cppVar_60694 << 3) | 0;
	cppVar_60695 = (cppVar_60695 & cppMask_un_8_);
	cppVar_60687 = cppVar_60695;
	} else {
	cppVar_60696 = PC + 1;
	cppVar_60696 = (cppVar_60696 & cppMask_un_16_);
	cppVar_60697 = ROM.rd(cppVar_60696);
	cppVar_60698 = (cppVar_60697 >> 3) & cppMask_un_5_;
	cppVar_60699 = (cppVar_60698 & cppMask_un_5_);
	cppVar_60700 = cppVar_60699 + 32;
	cppVar_60700 = (cppVar_60700 & cppMask_un_8_);
	cppVar_60687 = cppVar_60700;
	}
	cppVar_60702 = (cppVar_60687 == 160);
	if (cppVar_60702) {
	cppVar_60686 = P2;
	} else {
	cppVar_60705 = PC + 1;
	cppVar_60705 = (cppVar_60705 & cppMask_un_16_);
	cppVar_60706 = ROM.rd(cppVar_60705);
	cppVar_60707 = (cppVar_60706 >> 7) & cppMask_un_1_;
	cppVar_60708 = (cppVar_60707 == 1);
	if (cppVar_60708) {
	cppVar_60709 = PC + 1;
	cppVar_60709 = (cppVar_60709 & cppMask_un_16_);
	cppVar_60710 = ROM.rd(cppVar_60709);
	cppVar_60711 = (cppVar_60710 >> 3) & cppMask_un_5_;
	cppVar_60712 = (cppVar_60711 << 3) | 0;
	cppVar_60712 = (cppVar_60712 & cppMask_un_8_);
	cppVar_60704 = cppVar_60712;
	} else {
	cppVar_60713 = PC + 1;
	cppVar_60713 = (cppVar_60713 & cppMask_un_16_);
	cppVar_60714 = ROM.rd(cppVar_60713);
	cppVar_60715 = (cppVar_60714 >> 3) & cppMask_un_5_;
	cppVar_60716 = (cppVar_60715 & cppMask_un_5_);
	cppVar_60717 = cppVar_60716 + 32;
	cppVar_60717 = (cppVar_60717 & cppMask_un_8_);
	cppVar_60704 = cppVar_60717;
	}
	cppVar_60719 = (cppVar_60704 == 168);
	if (cppVar_60719) {
	cppVar_60703 = IE;
	} else {
	cppVar_60722 = PC + 1;
	cppVar_60722 = (cppVar_60722 & cppMask_un_16_);
	cppVar_60723 = ROM.rd(cppVar_60722);
	cppVar_60724 = (cppVar_60723 >> 7) & cppMask_un_1_;
	cppVar_60725 = (cppVar_60724 == 1);
	if (cppVar_60725) {
	cppVar_60726 = PC + 1;
	cppVar_60726 = (cppVar_60726 & cppMask_un_16_);
	cppVar_60727 = ROM.rd(cppVar_60726);
	cppVar_60728 = (cppVar_60727 >> 3) & cppMask_un_5_;
	cppVar_60729 = (cppVar_60728 << 3) | 0;
	cppVar_60729 = (cppVar_60729 & cppMask_un_8_);
	cppVar_60721 = cppVar_60729;
	} else {
	cppVar_60730 = PC + 1;
	cppVar_60730 = (cppVar_60730 & cppMask_un_16_);
	cppVar_60731 = ROM.rd(cppVar_60730);
	cppVar_60732 = (cppVar_60731 >> 3) & cppMask_un_5_;
	cppVar_60733 = (cppVar_60732 & cppMask_un_5_);
	cppVar_60734 = cppVar_60733 + 32;
	cppVar_60734 = (cppVar_60734 & cppMask_un_8_);
	cppVar_60721 = cppVar_60734;
	}
	cppVar_60736 = (cppVar_60721 == 176);
	if (cppVar_60736) {
	cppVar_60720 = P3;
	} else {
	cppVar_60739 = PC + 1;
	cppVar_60739 = (cppVar_60739 & cppMask_un_16_);
	cppVar_60740 = ROM.rd(cppVar_60739);
	cppVar_60741 = (cppVar_60740 >> 7) & cppMask_un_1_;
	cppVar_60742 = (cppVar_60741 == 1);
	if (cppVar_60742) {
	cppVar_60743 = PC + 1;
	cppVar_60743 = (cppVar_60743 & cppMask_un_16_);
	cppVar_60744 = ROM.rd(cppVar_60743);
	cppVar_60745 = (cppVar_60744 >> 3) & cppMask_un_5_;
	cppVar_60746 = (cppVar_60745 << 3) | 0;
	cppVar_60746 = (cppVar_60746 & cppMask_un_8_);
	cppVar_60738 = cppVar_60746;
	} else {
	cppVar_60747 = PC + 1;
	cppVar_60747 = (cppVar_60747 & cppMask_un_16_);
	cppVar_60748 = ROM.rd(cppVar_60747);
	cppVar_60749 = (cppVar_60748 >> 3) & cppMask_un_5_;
	cppVar_60750 = (cppVar_60749 & cppMask_un_5_);
	cppVar_60751 = cppVar_60750 + 32;
	cppVar_60751 = (cppVar_60751 & cppMask_un_8_);
	cppVar_60738 = cppVar_60751;
	}
	cppVar_60753 = (cppVar_60738 == 184);
	if (cppVar_60753) {
	cppVar_60737 = IP;
	} else {
	cppVar_60756 = PC + 1;
	cppVar_60756 = (cppVar_60756 & cppMask_un_16_);
	cppVar_60757 = ROM.rd(cppVar_60756);
	cppVar_60758 = (cppVar_60757 >> 7) & cppMask_un_1_;
	cppVar_60759 = (cppVar_60758 == 1);
	if (cppVar_60759) {
	cppVar_60760 = PC + 1;
	cppVar_60760 = (cppVar_60760 & cppMask_un_16_);
	cppVar_60761 = ROM.rd(cppVar_60760);
	cppVar_60762 = (cppVar_60761 >> 3) & cppMask_un_5_;
	cppVar_60763 = (cppVar_60762 << 3) | 0;
	cppVar_60763 = (cppVar_60763 & cppMask_un_8_);
	cppVar_60755 = cppVar_60763;
	} else {
	cppVar_60764 = PC + 1;
	cppVar_60764 = (cppVar_60764 & cppMask_un_16_);
	cppVar_60765 = ROM.rd(cppVar_60764);
	cppVar_60766 = (cppVar_60765 >> 3) & cppMask_un_5_;
	cppVar_60767 = (cppVar_60766 & cppMask_un_5_);
	cppVar_60768 = cppVar_60767 + 32;
	cppVar_60768 = (cppVar_60768 & cppMask_un_8_);
	cppVar_60755 = cppVar_60768;
	}
	cppVar_60770 = (cppVar_60755 == 208);
	if (cppVar_60770) {
	cppVar_60754 = PSW;
	} else {
	cppVar_60773 = PC + 1;
	cppVar_60773 = (cppVar_60773 & cppMask_un_16_);
	cppVar_60774 = ROM.rd(cppVar_60773);
	cppVar_60775 = (cppVar_60774 >> 7) & cppMask_un_1_;
	cppVar_60776 = (cppVar_60775 == 1);
	if (cppVar_60776) {
	cppVar_60777 = PC + 1;
	cppVar_60777 = (cppVar_60777 & cppMask_un_16_);
	cppVar_60778 = ROM.rd(cppVar_60777);
	cppVar_60779 = (cppVar_60778 >> 3) & cppMask_un_5_;
	cppVar_60780 = (cppVar_60779 << 3) | 0;
	cppVar_60780 = (cppVar_60780 & cppMask_un_8_);
	cppVar_60772 = cppVar_60780;
	} else {
	cppVar_60781 = PC + 1;
	cppVar_60781 = (cppVar_60781 & cppMask_un_16_);
	cppVar_60782 = ROM.rd(cppVar_60781);
	cppVar_60783 = (cppVar_60782 >> 3) & cppMask_un_5_;
	cppVar_60784 = (cppVar_60783 & cppMask_un_5_);
	cppVar_60785 = cppVar_60784 + 32;
	cppVar_60785 = (cppVar_60785 & cppMask_un_8_);
	cppVar_60772 = cppVar_60785;
	}
	cppVar_60787 = (cppVar_60772 == 224);
	if (cppVar_60787) {
	cppVar_60771 = ACC;
	} else {
	cppVar_60790 = PC + 1;
	cppVar_60790 = (cppVar_60790 & cppMask_un_16_);
	cppVar_60791 = ROM.rd(cppVar_60790);
	cppVar_60792 = (cppVar_60791 >> 7) & cppMask_un_1_;
	cppVar_60793 = (cppVar_60792 == 1);
	if (cppVar_60793) {
	cppVar_60794 = PC + 1;
	cppVar_60794 = (cppVar_60794 & cppMask_un_16_);
	cppVar_60795 = ROM.rd(cppVar_60794);
	cppVar_60796 = (cppVar_60795 >> 3) & cppMask_un_5_;
	cppVar_60797 = (cppVar_60796 << 3) | 0;
	cppVar_60797 = (cppVar_60797 & cppMask_un_8_);
	cppVar_60789 = cppVar_60797;
	} else {
	cppVar_60798 = PC + 1;
	cppVar_60798 = (cppVar_60798 & cppMask_un_16_);
	cppVar_60799 = ROM.rd(cppVar_60798);
	cppVar_60800 = (cppVar_60799 >> 3) & cppMask_un_5_;
	cppVar_60801 = (cppVar_60800 & cppMask_un_5_);
	cppVar_60802 = cppVar_60801 + 32;
	cppVar_60802 = (cppVar_60802 & cppMask_un_8_);
	cppVar_60789 = cppVar_60802;
	}
	cppVar_60804 = (cppVar_60789 == 240);
	if (cppVar_60804) {
	cppVar_60788 = B;
	} else {
	cppVar_60788 = 0;
	}
	cppVar_60771 = cppVar_60788;
	}
	cppVar_60754 = cppVar_60771;
	}
	cppVar_60737 = cppVar_60754;
	}
	cppVar_60720 = cppVar_60737;
	}
	cppVar_60703 = cppVar_60720;
	}
	cppVar_60686 = cppVar_60703;
	}
	cppVar_60669 = cppVar_60686;
	}
	cppVar_60652 = cppVar_60669;
	}
	cppVar_60635 = cppVar_60652;
	}
	cppVar_60618 = cppVar_60635;
	}
	cppVar_60601 = cppVar_60618;
	}
	cppVar_60584 = cppVar_60601;
	}
	cppVar_60567 = cppVar_60584;
	}
	cppVar_60550 = cppVar_60567;
	}
	cppVar_60533 = cppVar_60550;
	}
	cppVar_60516 = cppVar_60533;
	}
	cppVar_60499 = cppVar_60516;
	}
	cppVar_60482 = cppVar_60499;
	}
	cppVar_60465 = cppVar_60482;
	}
	cppVar_60448 = cppVar_60465;
	}
	cppVar_60412 = cppVar_60448;
	}
	cppVar_60806 = PC + 1;
	cppVar_60806 = (cppVar_60806 & cppMask_un_16_);
	cppVar_60807 = ROM.rd(cppVar_60806);
	cppVar_60808 = (cppVar_60807 >> 0) & cppMask_un_3_;
	cppVar_60809 = (cppVar_60412 >> static_cast<unsigned>(cppVar_60808)) & 0x1;
	cppVar_60810 = ~cppVar_60809;
	cppVar_60811 = (cppVar_60810 & cppMask_un_1_);
	cppVar_60812 = PC + 1;
	cppVar_60812 = (cppVar_60812 & cppMask_un_16_);
	cppVar_60813 = ROM.rd(cppVar_60812);
	cppVar_60814 = (cppVar_60813 >> 0) & cppMask_un_3_;
	cppVar_60815 = (cppVar_60814 & cppMask_un_3_);
	cppVar_60816 = cppVar_60811 << static_cast<unsigned>(cppVar_60815);
	cppVar_60816 = (cppVar_60816 & cppMask_un_8_);
	cppVar_60817 = cppVar_60411 | cppVar_60816;
	cppVar_59992 = cppVar_60817;
	} else {
	cppVar_59992 = SCON;
	}
	cppVar_59988 = cppVar_59992;
	} else {
	cppVar_60819 = ROM.rd(PC);
	cppVar_60821 = (cppVar_60819 == 146);
	if (cppVar_60821) {
	cppVar_60825 = PC + 1;
	cppVar_60825 = (cppVar_60825 & cppMask_un_16_);
	cppVar_60826 = ROM.rd(cppVar_60825);
	cppVar_60827 = (cppVar_60826 >> 7) & cppMask_un_1_;
	cppVar_60829 = (cppVar_60827 == 1);
	if (cppVar_60829) {
	cppVar_60830 = PC + 1;
	cppVar_60830 = (cppVar_60830 & cppMask_un_16_);
	cppVar_60831 = ROM.rd(cppVar_60830);
	cppVar_60832 = (cppVar_60831 >> 3) & cppMask_un_5_;
	cppVar_60834 = (cppVar_60832 << 3) | 0;
	cppVar_60834 = (cppVar_60834 & cppMask_un_8_);
	cppVar_60823 = cppVar_60834;
	} else {
	cppVar_60835 = PC + 1;
	cppVar_60835 = (cppVar_60835 & cppMask_un_16_);
	cppVar_60836 = ROM.rd(cppVar_60835);
	cppVar_60837 = (cppVar_60836 >> 3) & cppMask_un_5_;
	cppVar_60838 = (cppVar_60837 & cppMask_un_5_);
	cppVar_60840 = cppVar_60838 + 32;
	cppVar_60840 = (cppVar_60840 & cppMask_un_8_);
	cppVar_60823 = cppVar_60840;
	}
	cppVar_60842 = (cppVar_60823 == 152);
	if (cppVar_60842) {
	cppVar_60844 = PC + 1;
	cppVar_60844 = (cppVar_60844 & cppMask_un_16_);
	cppVar_60845 = ROM.rd(cppVar_60844);
	cppVar_60846 = (cppVar_60845 >> 0) & cppMask_un_3_;
	cppVar_60847 = (cppVar_60846 & cppMask_un_3_);
	cppVar_60848 = 1 << static_cast<unsigned>(cppVar_60847);
	cppVar_60848 = (cppVar_60848 & cppMask_un_8_);
	cppVar_60849 = ~cppVar_60848;
	cppVar_60852 = PC + 1;
	cppVar_60852 = (cppVar_60852 & cppMask_un_16_);
	cppVar_60853 = ROM.rd(cppVar_60852);
	cppVar_60854 = (cppVar_60853 >> 7) & cppMask_un_1_;
	cppVar_60855 = (cppVar_60854 == 1);
	if (cppVar_60855) {
	cppVar_60856 = PC + 1;
	cppVar_60856 = (cppVar_60856 & cppMask_un_16_);
	cppVar_60857 = ROM.rd(cppVar_60856);
	cppVar_60858 = (cppVar_60857 >> 3) & cppMask_un_5_;
	cppVar_60859 = (cppVar_60858 << 3) | 0;
	cppVar_60859 = (cppVar_60859 & cppMask_un_8_);
	cppVar_60851 = cppVar_60859;
	} else {
	cppVar_60860 = PC + 1;
	cppVar_60860 = (cppVar_60860 & cppMask_un_16_);
	cppVar_60861 = ROM.rd(cppVar_60860);
	cppVar_60862 = (cppVar_60861 >> 3) & cppMask_un_5_;
	cppVar_60863 = (cppVar_60862 & cppMask_un_5_);
	cppVar_60864 = cppVar_60863 + 32;
	cppVar_60864 = (cppVar_60864 & cppMask_un_8_);
	cppVar_60851 = cppVar_60864;
	}
	cppVar_60865 = (cppVar_60851 >> 7) & cppMask_un_1_;
	cppVar_60867 = (cppVar_60865 == 0);
	if (cppVar_60867) {
	cppVar_60869 = PC + 1;
	cppVar_60869 = (cppVar_60869 & cppMask_un_16_);
	cppVar_60870 = ROM.rd(cppVar_60869);
	cppVar_60871 = (cppVar_60870 >> 7) & cppMask_un_1_;
	cppVar_60872 = (cppVar_60871 == 1);
	if (cppVar_60872) {
	cppVar_60873 = PC + 1;
	cppVar_60873 = (cppVar_60873 & cppMask_un_16_);
	cppVar_60874 = ROM.rd(cppVar_60873);
	cppVar_60875 = (cppVar_60874 >> 3) & cppMask_un_5_;
	cppVar_60876 = (cppVar_60875 << 3) | 0;
	cppVar_60876 = (cppVar_60876 & cppMask_un_8_);
	cppVar_60868 = cppVar_60876;
	} else {
	cppVar_60877 = PC + 1;
	cppVar_60877 = (cppVar_60877 & cppMask_un_16_);
	cppVar_60878 = ROM.rd(cppVar_60877);
	cppVar_60879 = (cppVar_60878 >> 3) & cppMask_un_5_;
	cppVar_60880 = (cppVar_60879 & cppMask_un_5_);
	cppVar_60881 = cppVar_60880 + 32;
	cppVar_60881 = (cppVar_60881 & cppMask_un_8_);
	cppVar_60868 = cppVar_60881;
	}
	cppVar_60882 = IRAM.rd(cppVar_60868);
	cppVar_60850 = cppVar_60882;
	} else {
	cppVar_60885 = PC + 1;
	cppVar_60885 = (cppVar_60885 & cppMask_un_16_);
	cppVar_60886 = ROM.rd(cppVar_60885);
	cppVar_60887 = (cppVar_60886 >> 7) & cppMask_un_1_;
	cppVar_60888 = (cppVar_60887 == 1);
	if (cppVar_60888) {
	cppVar_60889 = PC + 1;
	cppVar_60889 = (cppVar_60889 & cppMask_un_16_);
	cppVar_60890 = ROM.rd(cppVar_60889);
	cppVar_60891 = (cppVar_60890 >> 3) & cppMask_un_5_;
	cppVar_60892 = (cppVar_60891 << 3) | 0;
	cppVar_60892 = (cppVar_60892 & cppMask_un_8_);
	cppVar_60884 = cppVar_60892;
	} else {
	cppVar_60893 = PC + 1;
	cppVar_60893 = (cppVar_60893 & cppMask_un_16_);
	cppVar_60894 = ROM.rd(cppVar_60893);
	cppVar_60895 = (cppVar_60894 >> 3) & cppMask_un_5_;
	cppVar_60896 = (cppVar_60895 & cppMask_un_5_);
	cppVar_60897 = cppVar_60896 + 32;
	cppVar_60897 = (cppVar_60897 & cppMask_un_8_);
	cppVar_60884 = cppVar_60897;
	}
	cppVar_60899 = (cppVar_60884 == 128);
	if (cppVar_60899) {
	cppVar_60883 = P0;
	} else {
	cppVar_60902 = PC + 1;
	cppVar_60902 = (cppVar_60902 & cppMask_un_16_);
	cppVar_60903 = ROM.rd(cppVar_60902);
	cppVar_60904 = (cppVar_60903 >> 7) & cppMask_un_1_;
	cppVar_60905 = (cppVar_60904 == 1);
	if (cppVar_60905) {
	cppVar_60906 = PC + 1;
	cppVar_60906 = (cppVar_60906 & cppMask_un_16_);
	cppVar_60907 = ROM.rd(cppVar_60906);
	cppVar_60908 = (cppVar_60907 >> 3) & cppMask_un_5_;
	cppVar_60909 = (cppVar_60908 << 3) | 0;
	cppVar_60909 = (cppVar_60909 & cppMask_un_8_);
	cppVar_60901 = cppVar_60909;
	} else {
	cppVar_60910 = PC + 1;
	cppVar_60910 = (cppVar_60910 & cppMask_un_16_);
	cppVar_60911 = ROM.rd(cppVar_60910);
	cppVar_60912 = (cppVar_60911 >> 3) & cppMask_un_5_;
	cppVar_60913 = (cppVar_60912 & cppMask_un_5_);
	cppVar_60914 = cppVar_60913 + 32;
	cppVar_60914 = (cppVar_60914 & cppMask_un_8_);
	cppVar_60901 = cppVar_60914;
	}
	cppVar_60916 = (cppVar_60901 == 129);
	if (cppVar_60916) {
	cppVar_60900 = SP;
	} else {
	cppVar_60919 = PC + 1;
	cppVar_60919 = (cppVar_60919 & cppMask_un_16_);
	cppVar_60920 = ROM.rd(cppVar_60919);
	cppVar_60921 = (cppVar_60920 >> 7) & cppMask_un_1_;
	cppVar_60922 = (cppVar_60921 == 1);
	if (cppVar_60922) {
	cppVar_60923 = PC + 1;
	cppVar_60923 = (cppVar_60923 & cppMask_un_16_);
	cppVar_60924 = ROM.rd(cppVar_60923);
	cppVar_60925 = (cppVar_60924 >> 3) & cppMask_un_5_;
	cppVar_60926 = (cppVar_60925 << 3) | 0;
	cppVar_60926 = (cppVar_60926 & cppMask_un_8_);
	cppVar_60918 = cppVar_60926;
	} else {
	cppVar_60927 = PC + 1;
	cppVar_60927 = (cppVar_60927 & cppMask_un_16_);
	cppVar_60928 = ROM.rd(cppVar_60927);
	cppVar_60929 = (cppVar_60928 >> 3) & cppMask_un_5_;
	cppVar_60930 = (cppVar_60929 & cppMask_un_5_);
	cppVar_60931 = cppVar_60930 + 32;
	cppVar_60931 = (cppVar_60931 & cppMask_un_8_);
	cppVar_60918 = cppVar_60931;
	}
	cppVar_60933 = (cppVar_60918 == 130);
	if (cppVar_60933) {
	cppVar_60917 = DPL;
	} else {
	cppVar_60936 = PC + 1;
	cppVar_60936 = (cppVar_60936 & cppMask_un_16_);
	cppVar_60937 = ROM.rd(cppVar_60936);
	cppVar_60938 = (cppVar_60937 >> 7) & cppMask_un_1_;
	cppVar_60939 = (cppVar_60938 == 1);
	if (cppVar_60939) {
	cppVar_60940 = PC + 1;
	cppVar_60940 = (cppVar_60940 & cppMask_un_16_);
	cppVar_60941 = ROM.rd(cppVar_60940);
	cppVar_60942 = (cppVar_60941 >> 3) & cppMask_un_5_;
	cppVar_60943 = (cppVar_60942 << 3) | 0;
	cppVar_60943 = (cppVar_60943 & cppMask_un_8_);
	cppVar_60935 = cppVar_60943;
	} else {
	cppVar_60944 = PC + 1;
	cppVar_60944 = (cppVar_60944 & cppMask_un_16_);
	cppVar_60945 = ROM.rd(cppVar_60944);
	cppVar_60946 = (cppVar_60945 >> 3) & cppMask_un_5_;
	cppVar_60947 = (cppVar_60946 & cppMask_un_5_);
	cppVar_60948 = cppVar_60947 + 32;
	cppVar_60948 = (cppVar_60948 & cppMask_un_8_);
	cppVar_60935 = cppVar_60948;
	}
	cppVar_60950 = (cppVar_60935 == 131);
	if (cppVar_60950) {
	cppVar_60934 = DPH;
	} else {
	cppVar_60953 = PC + 1;
	cppVar_60953 = (cppVar_60953 & cppMask_un_16_);
	cppVar_60954 = ROM.rd(cppVar_60953);
	cppVar_60955 = (cppVar_60954 >> 7) & cppMask_un_1_;
	cppVar_60956 = (cppVar_60955 == 1);
	if (cppVar_60956) {
	cppVar_60957 = PC + 1;
	cppVar_60957 = (cppVar_60957 & cppMask_un_16_);
	cppVar_60958 = ROM.rd(cppVar_60957);
	cppVar_60959 = (cppVar_60958 >> 3) & cppMask_un_5_;
	cppVar_60960 = (cppVar_60959 << 3) | 0;
	cppVar_60960 = (cppVar_60960 & cppMask_un_8_);
	cppVar_60952 = cppVar_60960;
	} else {
	cppVar_60961 = PC + 1;
	cppVar_60961 = (cppVar_60961 & cppMask_un_16_);
	cppVar_60962 = ROM.rd(cppVar_60961);
	cppVar_60963 = (cppVar_60962 >> 3) & cppMask_un_5_;
	cppVar_60964 = (cppVar_60963 & cppMask_un_5_);
	cppVar_60965 = cppVar_60964 + 32;
	cppVar_60965 = (cppVar_60965 & cppMask_un_8_);
	cppVar_60952 = cppVar_60965;
	}
	cppVar_60967 = (cppVar_60952 == 135);
	if (cppVar_60967) {
	cppVar_60951 = PCON;
	} else {
	cppVar_60970 = PC + 1;
	cppVar_60970 = (cppVar_60970 & cppMask_un_16_);
	cppVar_60971 = ROM.rd(cppVar_60970);
	cppVar_60972 = (cppVar_60971 >> 7) & cppMask_un_1_;
	cppVar_60973 = (cppVar_60972 == 1);
	if (cppVar_60973) {
	cppVar_60974 = PC + 1;
	cppVar_60974 = (cppVar_60974 & cppMask_un_16_);
	cppVar_60975 = ROM.rd(cppVar_60974);
	cppVar_60976 = (cppVar_60975 >> 3) & cppMask_un_5_;
	cppVar_60977 = (cppVar_60976 << 3) | 0;
	cppVar_60977 = (cppVar_60977 & cppMask_un_8_);
	cppVar_60969 = cppVar_60977;
	} else {
	cppVar_60978 = PC + 1;
	cppVar_60978 = (cppVar_60978 & cppMask_un_16_);
	cppVar_60979 = ROM.rd(cppVar_60978);
	cppVar_60980 = (cppVar_60979 >> 3) & cppMask_un_5_;
	cppVar_60981 = (cppVar_60980 & cppMask_un_5_);
	cppVar_60982 = cppVar_60981 + 32;
	cppVar_60982 = (cppVar_60982 & cppMask_un_8_);
	cppVar_60969 = cppVar_60982;
	}
	cppVar_60984 = (cppVar_60969 == 136);
	if (cppVar_60984) {
	cppVar_60968 = TCON;
	} else {
	cppVar_60987 = PC + 1;
	cppVar_60987 = (cppVar_60987 & cppMask_un_16_);
	cppVar_60988 = ROM.rd(cppVar_60987);
	cppVar_60989 = (cppVar_60988 >> 7) & cppMask_un_1_;
	cppVar_60990 = (cppVar_60989 == 1);
	if (cppVar_60990) {
	cppVar_60991 = PC + 1;
	cppVar_60991 = (cppVar_60991 & cppMask_un_16_);
	cppVar_60992 = ROM.rd(cppVar_60991);
	cppVar_60993 = (cppVar_60992 >> 3) & cppMask_un_5_;
	cppVar_60994 = (cppVar_60993 << 3) | 0;
	cppVar_60994 = (cppVar_60994 & cppMask_un_8_);
	cppVar_60986 = cppVar_60994;
	} else {
	cppVar_60995 = PC + 1;
	cppVar_60995 = (cppVar_60995 & cppMask_un_16_);
	cppVar_60996 = ROM.rd(cppVar_60995);
	cppVar_60997 = (cppVar_60996 >> 3) & cppMask_un_5_;
	cppVar_60998 = (cppVar_60997 & cppMask_un_5_);
	cppVar_60999 = cppVar_60998 + 32;
	cppVar_60999 = (cppVar_60999 & cppMask_un_8_);
	cppVar_60986 = cppVar_60999;
	}
	cppVar_61001 = (cppVar_60986 == 137);
	if (cppVar_61001) {
	cppVar_60985 = TMOD;
	} else {
	cppVar_61004 = PC + 1;
	cppVar_61004 = (cppVar_61004 & cppMask_un_16_);
	cppVar_61005 = ROM.rd(cppVar_61004);
	cppVar_61006 = (cppVar_61005 >> 7) & cppMask_un_1_;
	cppVar_61007 = (cppVar_61006 == 1);
	if (cppVar_61007) {
	cppVar_61008 = PC + 1;
	cppVar_61008 = (cppVar_61008 & cppMask_un_16_);
	cppVar_61009 = ROM.rd(cppVar_61008);
	cppVar_61010 = (cppVar_61009 >> 3) & cppMask_un_5_;
	cppVar_61011 = (cppVar_61010 << 3) | 0;
	cppVar_61011 = (cppVar_61011 & cppMask_un_8_);
	cppVar_61003 = cppVar_61011;
	} else {
	cppVar_61012 = PC + 1;
	cppVar_61012 = (cppVar_61012 & cppMask_un_16_);
	cppVar_61013 = ROM.rd(cppVar_61012);
	cppVar_61014 = (cppVar_61013 >> 3) & cppMask_un_5_;
	cppVar_61015 = (cppVar_61014 & cppMask_un_5_);
	cppVar_61016 = cppVar_61015 + 32;
	cppVar_61016 = (cppVar_61016 & cppMask_un_8_);
	cppVar_61003 = cppVar_61016;
	}
	cppVar_61018 = (cppVar_61003 == 138);
	if (cppVar_61018) {
	cppVar_61002 = TL0;
	} else {
	cppVar_61021 = PC + 1;
	cppVar_61021 = (cppVar_61021 & cppMask_un_16_);
	cppVar_61022 = ROM.rd(cppVar_61021);
	cppVar_61023 = (cppVar_61022 >> 7) & cppMask_un_1_;
	cppVar_61024 = (cppVar_61023 == 1);
	if (cppVar_61024) {
	cppVar_61025 = PC + 1;
	cppVar_61025 = (cppVar_61025 & cppMask_un_16_);
	cppVar_61026 = ROM.rd(cppVar_61025);
	cppVar_61027 = (cppVar_61026 >> 3) & cppMask_un_5_;
	cppVar_61028 = (cppVar_61027 << 3) | 0;
	cppVar_61028 = (cppVar_61028 & cppMask_un_8_);
	cppVar_61020 = cppVar_61028;
	} else {
	cppVar_61029 = PC + 1;
	cppVar_61029 = (cppVar_61029 & cppMask_un_16_);
	cppVar_61030 = ROM.rd(cppVar_61029);
	cppVar_61031 = (cppVar_61030 >> 3) & cppMask_un_5_;
	cppVar_61032 = (cppVar_61031 & cppMask_un_5_);
	cppVar_61033 = cppVar_61032 + 32;
	cppVar_61033 = (cppVar_61033 & cppMask_un_8_);
	cppVar_61020 = cppVar_61033;
	}
	cppVar_61035 = (cppVar_61020 == 140);
	if (cppVar_61035) {
	cppVar_61019 = TH0;
	} else {
	cppVar_61038 = PC + 1;
	cppVar_61038 = (cppVar_61038 & cppMask_un_16_);
	cppVar_61039 = ROM.rd(cppVar_61038);
	cppVar_61040 = (cppVar_61039 >> 7) & cppMask_un_1_;
	cppVar_61041 = (cppVar_61040 == 1);
	if (cppVar_61041) {
	cppVar_61042 = PC + 1;
	cppVar_61042 = (cppVar_61042 & cppMask_un_16_);
	cppVar_61043 = ROM.rd(cppVar_61042);
	cppVar_61044 = (cppVar_61043 >> 3) & cppMask_un_5_;
	cppVar_61045 = (cppVar_61044 << 3) | 0;
	cppVar_61045 = (cppVar_61045 & cppMask_un_8_);
	cppVar_61037 = cppVar_61045;
	} else {
	cppVar_61046 = PC + 1;
	cppVar_61046 = (cppVar_61046 & cppMask_un_16_);
	cppVar_61047 = ROM.rd(cppVar_61046);
	cppVar_61048 = (cppVar_61047 >> 3) & cppMask_un_5_;
	cppVar_61049 = (cppVar_61048 & cppMask_un_5_);
	cppVar_61050 = cppVar_61049 + 32;
	cppVar_61050 = (cppVar_61050 & cppMask_un_8_);
	cppVar_61037 = cppVar_61050;
	}
	cppVar_61052 = (cppVar_61037 == 139);
	if (cppVar_61052) {
	cppVar_61036 = TL1;
	} else {
	cppVar_61055 = PC + 1;
	cppVar_61055 = (cppVar_61055 & cppMask_un_16_);
	cppVar_61056 = ROM.rd(cppVar_61055);
	cppVar_61057 = (cppVar_61056 >> 7) & cppMask_un_1_;
	cppVar_61058 = (cppVar_61057 == 1);
	if (cppVar_61058) {
	cppVar_61059 = PC + 1;
	cppVar_61059 = (cppVar_61059 & cppMask_un_16_);
	cppVar_61060 = ROM.rd(cppVar_61059);
	cppVar_61061 = (cppVar_61060 >> 3) & cppMask_un_5_;
	cppVar_61062 = (cppVar_61061 << 3) | 0;
	cppVar_61062 = (cppVar_61062 & cppMask_un_8_);
	cppVar_61054 = cppVar_61062;
	} else {
	cppVar_61063 = PC + 1;
	cppVar_61063 = (cppVar_61063 & cppMask_un_16_);
	cppVar_61064 = ROM.rd(cppVar_61063);
	cppVar_61065 = (cppVar_61064 >> 3) & cppMask_un_5_;
	cppVar_61066 = (cppVar_61065 & cppMask_un_5_);
	cppVar_61067 = cppVar_61066 + 32;
	cppVar_61067 = (cppVar_61067 & cppMask_un_8_);
	cppVar_61054 = cppVar_61067;
	}
	cppVar_61069 = (cppVar_61054 == 141);
	if (cppVar_61069) {
	cppVar_61053 = TH1;
	} else {
	cppVar_61072 = PC + 1;
	cppVar_61072 = (cppVar_61072 & cppMask_un_16_);
	cppVar_61073 = ROM.rd(cppVar_61072);
	cppVar_61074 = (cppVar_61073 >> 7) & cppMask_un_1_;
	cppVar_61075 = (cppVar_61074 == 1);
	if (cppVar_61075) {
	cppVar_61076 = PC + 1;
	cppVar_61076 = (cppVar_61076 & cppMask_un_16_);
	cppVar_61077 = ROM.rd(cppVar_61076);
	cppVar_61078 = (cppVar_61077 >> 3) & cppMask_un_5_;
	cppVar_61079 = (cppVar_61078 << 3) | 0;
	cppVar_61079 = (cppVar_61079 & cppMask_un_8_);
	cppVar_61071 = cppVar_61079;
	} else {
	cppVar_61080 = PC + 1;
	cppVar_61080 = (cppVar_61080 & cppMask_un_16_);
	cppVar_61081 = ROM.rd(cppVar_61080);
	cppVar_61082 = (cppVar_61081 >> 3) & cppMask_un_5_;
	cppVar_61083 = (cppVar_61082 & cppMask_un_5_);
	cppVar_61084 = cppVar_61083 + 32;
	cppVar_61084 = (cppVar_61084 & cppMask_un_8_);
	cppVar_61071 = cppVar_61084;
	}
	cppVar_61086 = (cppVar_61071 == 144);
	if (cppVar_61086) {
	cppVar_61070 = P1;
	} else {
	cppVar_61089 = PC + 1;
	cppVar_61089 = (cppVar_61089 & cppMask_un_16_);
	cppVar_61090 = ROM.rd(cppVar_61089);
	cppVar_61091 = (cppVar_61090 >> 7) & cppMask_un_1_;
	cppVar_61092 = (cppVar_61091 == 1);
	if (cppVar_61092) {
	cppVar_61093 = PC + 1;
	cppVar_61093 = (cppVar_61093 & cppMask_un_16_);
	cppVar_61094 = ROM.rd(cppVar_61093);
	cppVar_61095 = (cppVar_61094 >> 3) & cppMask_un_5_;
	cppVar_61096 = (cppVar_61095 << 3) | 0;
	cppVar_61096 = (cppVar_61096 & cppMask_un_8_);
	cppVar_61088 = cppVar_61096;
	} else {
	cppVar_61097 = PC + 1;
	cppVar_61097 = (cppVar_61097 & cppMask_un_16_);
	cppVar_61098 = ROM.rd(cppVar_61097);
	cppVar_61099 = (cppVar_61098 >> 3) & cppMask_un_5_;
	cppVar_61100 = (cppVar_61099 & cppMask_un_5_);
	cppVar_61101 = cppVar_61100 + 32;
	cppVar_61101 = (cppVar_61101 & cppMask_un_8_);
	cppVar_61088 = cppVar_61101;
	}
	cppVar_61103 = (cppVar_61088 == 152);
	if (cppVar_61103) {
	cppVar_61087 = SCON;
	} else {
	cppVar_61106 = PC + 1;
	cppVar_61106 = (cppVar_61106 & cppMask_un_16_);
	cppVar_61107 = ROM.rd(cppVar_61106);
	cppVar_61108 = (cppVar_61107 >> 7) & cppMask_un_1_;
	cppVar_61109 = (cppVar_61108 == 1);
	if (cppVar_61109) {
	cppVar_61110 = PC + 1;
	cppVar_61110 = (cppVar_61110 & cppMask_un_16_);
	cppVar_61111 = ROM.rd(cppVar_61110);
	cppVar_61112 = (cppVar_61111 >> 3) & cppMask_un_5_;
	cppVar_61113 = (cppVar_61112 << 3) | 0;
	cppVar_61113 = (cppVar_61113 & cppMask_un_8_);
	cppVar_61105 = cppVar_61113;
	} else {
	cppVar_61114 = PC + 1;
	cppVar_61114 = (cppVar_61114 & cppMask_un_16_);
	cppVar_61115 = ROM.rd(cppVar_61114);
	cppVar_61116 = (cppVar_61115 >> 3) & cppMask_un_5_;
	cppVar_61117 = (cppVar_61116 & cppMask_un_5_);
	cppVar_61118 = cppVar_61117 + 32;
	cppVar_61118 = (cppVar_61118 & cppMask_un_8_);
	cppVar_61105 = cppVar_61118;
	}
	cppVar_61120 = (cppVar_61105 == 153);
	if (cppVar_61120) {
	cppVar_61104 = SBUF;
	} else {
	cppVar_61123 = PC + 1;
	cppVar_61123 = (cppVar_61123 & cppMask_un_16_);
	cppVar_61124 = ROM.rd(cppVar_61123);
	cppVar_61125 = (cppVar_61124 >> 7) & cppMask_un_1_;
	cppVar_61126 = (cppVar_61125 == 1);
	if (cppVar_61126) {
	cppVar_61127 = PC + 1;
	cppVar_61127 = (cppVar_61127 & cppMask_un_16_);
	cppVar_61128 = ROM.rd(cppVar_61127);
	cppVar_61129 = (cppVar_61128 >> 3) & cppMask_un_5_;
	cppVar_61130 = (cppVar_61129 << 3) | 0;
	cppVar_61130 = (cppVar_61130 & cppMask_un_8_);
	cppVar_61122 = cppVar_61130;
	} else {
	cppVar_61131 = PC + 1;
	cppVar_61131 = (cppVar_61131 & cppMask_un_16_);
	cppVar_61132 = ROM.rd(cppVar_61131);
	cppVar_61133 = (cppVar_61132 >> 3) & cppMask_un_5_;
	cppVar_61134 = (cppVar_61133 & cppMask_un_5_);
	cppVar_61135 = cppVar_61134 + 32;
	cppVar_61135 = (cppVar_61135 & cppMask_un_8_);
	cppVar_61122 = cppVar_61135;
	}
	cppVar_61137 = (cppVar_61122 == 160);
	if (cppVar_61137) {
	cppVar_61121 = P2;
	} else {
	cppVar_61140 = PC + 1;
	cppVar_61140 = (cppVar_61140 & cppMask_un_16_);
	cppVar_61141 = ROM.rd(cppVar_61140);
	cppVar_61142 = (cppVar_61141 >> 7) & cppMask_un_1_;
	cppVar_61143 = (cppVar_61142 == 1);
	if (cppVar_61143) {
	cppVar_61144 = PC + 1;
	cppVar_61144 = (cppVar_61144 & cppMask_un_16_);
	cppVar_61145 = ROM.rd(cppVar_61144);
	cppVar_61146 = (cppVar_61145 >> 3) & cppMask_un_5_;
	cppVar_61147 = (cppVar_61146 << 3) | 0;
	cppVar_61147 = (cppVar_61147 & cppMask_un_8_);
	cppVar_61139 = cppVar_61147;
	} else {
	cppVar_61148 = PC + 1;
	cppVar_61148 = (cppVar_61148 & cppMask_un_16_);
	cppVar_61149 = ROM.rd(cppVar_61148);
	cppVar_61150 = (cppVar_61149 >> 3) & cppMask_un_5_;
	cppVar_61151 = (cppVar_61150 & cppMask_un_5_);
	cppVar_61152 = cppVar_61151 + 32;
	cppVar_61152 = (cppVar_61152 & cppMask_un_8_);
	cppVar_61139 = cppVar_61152;
	}
	cppVar_61154 = (cppVar_61139 == 168);
	if (cppVar_61154) {
	cppVar_61138 = IE;
	} else {
	cppVar_61157 = PC + 1;
	cppVar_61157 = (cppVar_61157 & cppMask_un_16_);
	cppVar_61158 = ROM.rd(cppVar_61157);
	cppVar_61159 = (cppVar_61158 >> 7) & cppMask_un_1_;
	cppVar_61160 = (cppVar_61159 == 1);
	if (cppVar_61160) {
	cppVar_61161 = PC + 1;
	cppVar_61161 = (cppVar_61161 & cppMask_un_16_);
	cppVar_61162 = ROM.rd(cppVar_61161);
	cppVar_61163 = (cppVar_61162 >> 3) & cppMask_un_5_;
	cppVar_61164 = (cppVar_61163 << 3) | 0;
	cppVar_61164 = (cppVar_61164 & cppMask_un_8_);
	cppVar_61156 = cppVar_61164;
	} else {
	cppVar_61165 = PC + 1;
	cppVar_61165 = (cppVar_61165 & cppMask_un_16_);
	cppVar_61166 = ROM.rd(cppVar_61165);
	cppVar_61167 = (cppVar_61166 >> 3) & cppMask_un_5_;
	cppVar_61168 = (cppVar_61167 & cppMask_un_5_);
	cppVar_61169 = cppVar_61168 + 32;
	cppVar_61169 = (cppVar_61169 & cppMask_un_8_);
	cppVar_61156 = cppVar_61169;
	}
	cppVar_61171 = (cppVar_61156 == 176);
	if (cppVar_61171) {
	cppVar_61155 = P3;
	} else {
	cppVar_61174 = PC + 1;
	cppVar_61174 = (cppVar_61174 & cppMask_un_16_);
	cppVar_61175 = ROM.rd(cppVar_61174);
	cppVar_61176 = (cppVar_61175 >> 7) & cppMask_un_1_;
	cppVar_61177 = (cppVar_61176 == 1);
	if (cppVar_61177) {
	cppVar_61178 = PC + 1;
	cppVar_61178 = (cppVar_61178 & cppMask_un_16_);
	cppVar_61179 = ROM.rd(cppVar_61178);
	cppVar_61180 = (cppVar_61179 >> 3) & cppMask_un_5_;
	cppVar_61181 = (cppVar_61180 << 3) | 0;
	cppVar_61181 = (cppVar_61181 & cppMask_un_8_);
	cppVar_61173 = cppVar_61181;
	} else {
	cppVar_61182 = PC + 1;
	cppVar_61182 = (cppVar_61182 & cppMask_un_16_);
	cppVar_61183 = ROM.rd(cppVar_61182);
	cppVar_61184 = (cppVar_61183 >> 3) & cppMask_un_5_;
	cppVar_61185 = (cppVar_61184 & cppMask_un_5_);
	cppVar_61186 = cppVar_61185 + 32;
	cppVar_61186 = (cppVar_61186 & cppMask_un_8_);
	cppVar_61173 = cppVar_61186;
	}
	cppVar_61188 = (cppVar_61173 == 184);
	if (cppVar_61188) {
	cppVar_61172 = IP;
	} else {
	cppVar_61191 = PC + 1;
	cppVar_61191 = (cppVar_61191 & cppMask_un_16_);
	cppVar_61192 = ROM.rd(cppVar_61191);
	cppVar_61193 = (cppVar_61192 >> 7) & cppMask_un_1_;
	cppVar_61194 = (cppVar_61193 == 1);
	if (cppVar_61194) {
	cppVar_61195 = PC + 1;
	cppVar_61195 = (cppVar_61195 & cppMask_un_16_);
	cppVar_61196 = ROM.rd(cppVar_61195);
	cppVar_61197 = (cppVar_61196 >> 3) & cppMask_un_5_;
	cppVar_61198 = (cppVar_61197 << 3) | 0;
	cppVar_61198 = (cppVar_61198 & cppMask_un_8_);
	cppVar_61190 = cppVar_61198;
	} else {
	cppVar_61199 = PC + 1;
	cppVar_61199 = (cppVar_61199 & cppMask_un_16_);
	cppVar_61200 = ROM.rd(cppVar_61199);
	cppVar_61201 = (cppVar_61200 >> 3) & cppMask_un_5_;
	cppVar_61202 = (cppVar_61201 & cppMask_un_5_);
	cppVar_61203 = cppVar_61202 + 32;
	cppVar_61203 = (cppVar_61203 & cppMask_un_8_);
	cppVar_61190 = cppVar_61203;
	}
	cppVar_61205 = (cppVar_61190 == 208);
	if (cppVar_61205) {
	cppVar_61189 = PSW;
	} else {
	cppVar_61208 = PC + 1;
	cppVar_61208 = (cppVar_61208 & cppMask_un_16_);
	cppVar_61209 = ROM.rd(cppVar_61208);
	cppVar_61210 = (cppVar_61209 >> 7) & cppMask_un_1_;
	cppVar_61211 = (cppVar_61210 == 1);
	if (cppVar_61211) {
	cppVar_61212 = PC + 1;
	cppVar_61212 = (cppVar_61212 & cppMask_un_16_);
	cppVar_61213 = ROM.rd(cppVar_61212);
	cppVar_61214 = (cppVar_61213 >> 3) & cppMask_un_5_;
	cppVar_61215 = (cppVar_61214 << 3) | 0;
	cppVar_61215 = (cppVar_61215 & cppMask_un_8_);
	cppVar_61207 = cppVar_61215;
	} else {
	cppVar_61216 = PC + 1;
	cppVar_61216 = (cppVar_61216 & cppMask_un_16_);
	cppVar_61217 = ROM.rd(cppVar_61216);
	cppVar_61218 = (cppVar_61217 >> 3) & cppMask_un_5_;
	cppVar_61219 = (cppVar_61218 & cppMask_un_5_);
	cppVar_61220 = cppVar_61219 + 32;
	cppVar_61220 = (cppVar_61220 & cppMask_un_8_);
	cppVar_61207 = cppVar_61220;
	}
	cppVar_61222 = (cppVar_61207 == 224);
	if (cppVar_61222) {
	cppVar_61206 = ACC;
	} else {
	cppVar_61225 = PC + 1;
	cppVar_61225 = (cppVar_61225 & cppMask_un_16_);
	cppVar_61226 = ROM.rd(cppVar_61225);
	cppVar_61227 = (cppVar_61226 >> 7) & cppMask_un_1_;
	cppVar_61228 = (cppVar_61227 == 1);
	if (cppVar_61228) {
	cppVar_61229 = PC + 1;
	cppVar_61229 = (cppVar_61229 & cppMask_un_16_);
	cppVar_61230 = ROM.rd(cppVar_61229);
	cppVar_61231 = (cppVar_61230 >> 3) & cppMask_un_5_;
	cppVar_61232 = (cppVar_61231 << 3) | 0;
	cppVar_61232 = (cppVar_61232 & cppMask_un_8_);
	cppVar_61224 = cppVar_61232;
	} else {
	cppVar_61233 = PC + 1;
	cppVar_61233 = (cppVar_61233 & cppMask_un_16_);
	cppVar_61234 = ROM.rd(cppVar_61233);
	cppVar_61235 = (cppVar_61234 >> 3) & cppMask_un_5_;
	cppVar_61236 = (cppVar_61235 & cppMask_un_5_);
	cppVar_61237 = cppVar_61236 + 32;
	cppVar_61237 = (cppVar_61237 & cppMask_un_8_);
	cppVar_61224 = cppVar_61237;
	}
	cppVar_61239 = (cppVar_61224 == 240);
	if (cppVar_61239) {
	cppVar_61223 = B;
	} else {
	cppVar_61223 = 0;
	}
	cppVar_61206 = cppVar_61223;
	}
	cppVar_61189 = cppVar_61206;
	}
	cppVar_61172 = cppVar_61189;
	}
	cppVar_61155 = cppVar_61172;
	}
	cppVar_61138 = cppVar_61155;
	}
	cppVar_61121 = cppVar_61138;
	}
	cppVar_61104 = cppVar_61121;
	}
	cppVar_61087 = cppVar_61104;
	}
	cppVar_61070 = cppVar_61087;
	}
	cppVar_61053 = cppVar_61070;
	}
	cppVar_61036 = cppVar_61053;
	}
	cppVar_61019 = cppVar_61036;
	}
	cppVar_61002 = cppVar_61019;
	}
	cppVar_60985 = cppVar_61002;
	}
	cppVar_60968 = cppVar_60985;
	}
	cppVar_60951 = cppVar_60968;
	}
	cppVar_60934 = cppVar_60951;
	}
	cppVar_60917 = cppVar_60934;
	}
	cppVar_60900 = cppVar_60917;
	}
	cppVar_60883 = cppVar_60900;
	}
	cppVar_60850 = cppVar_60883;
	}
	cppVar_61241 = cppVar_60849 & cppVar_60850;
	cppVar_61242 = (PSW >> 7) & cppMask_un_1_;
	cppVar_61243 = (cppVar_61242 & cppMask_un_1_);
	cppVar_61244 = PC + 1;
	cppVar_61244 = (cppVar_61244 & cppMask_un_16_);
	cppVar_61245 = ROM.rd(cppVar_61244);
	cppVar_61246 = (cppVar_61245 >> 0) & cppMask_un_3_;
	cppVar_61247 = (cppVar_61246 & cppMask_un_3_);
	cppVar_61248 = cppVar_61243 << static_cast<unsigned>(cppVar_61247);
	cppVar_61248 = (cppVar_61248 & cppMask_un_8_);
	cppVar_61249 = cppVar_61241 | cppVar_61248;
	cppVar_60822 = cppVar_61249;
	} else {
	cppVar_60822 = SCON;
	}
	cppVar_60818 = cppVar_60822;
	} else {
	cppVar_61251 = ROM.rd(PC);
	cppVar_61253 = (cppVar_61251 == 143);
	if (cppVar_61253) {
	cppVar_61256 = PC + 1;
	cppVar_61256 = (cppVar_61256 & cppMask_un_16_);
	cppVar_61257 = ROM.rd(cppVar_61256);
	cppVar_61259 = (cppVar_61257 == 152);
	if (cppVar_61259) {
	cppVar_61262 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61264 = (cppVar_61262 << 3) | 7;
	cppVar_61264 = (cppVar_61264 & cppMask_un_5_);
	cppVar_61265 = (0 << 5) | cppVar_61264;
	cppVar_61265 = (cppVar_61265 & cppMask_un_8_);
	cppVar_61266 = (cppVar_61265 >> 7) & cppMask_un_1_;
	cppVar_61268 = (cppVar_61266 == 0);
	if (cppVar_61268) {
	cppVar_61269 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61270 = (cppVar_61269 << 3) | 7;
	cppVar_61270 = (cppVar_61270 & cppMask_un_5_);
	cppVar_61271 = (0 << 5) | cppVar_61270;
	cppVar_61271 = (cppVar_61271 & cppMask_un_8_);
	cppVar_61272 = IRAM.rd(cppVar_61271);
	cppVar_61260 = cppVar_61272;
	} else {
	cppVar_61274 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61275 = (cppVar_61274 << 3) | 7;
	cppVar_61275 = (cppVar_61275 & cppMask_un_5_);
	cppVar_61276 = (0 << 5) | cppVar_61275;
	cppVar_61276 = (cppVar_61276 & cppMask_un_8_);
	cppVar_61278 = (cppVar_61276 == 128);
	if (cppVar_61278) {
	cppVar_61273 = P0;
	} else {
	cppVar_61280 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61281 = (cppVar_61280 << 3) | 7;
	cppVar_61281 = (cppVar_61281 & cppMask_un_5_);
	cppVar_61282 = (0 << 5) | cppVar_61281;
	cppVar_61282 = (cppVar_61282 & cppMask_un_8_);
	cppVar_61284 = (cppVar_61282 == 129);
	if (cppVar_61284) {
	cppVar_61279 = SP;
	} else {
	cppVar_61286 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61287 = (cppVar_61286 << 3) | 7;
	cppVar_61287 = (cppVar_61287 & cppMask_un_5_);
	cppVar_61288 = (0 << 5) | cppVar_61287;
	cppVar_61288 = (cppVar_61288 & cppMask_un_8_);
	cppVar_61290 = (cppVar_61288 == 130);
	if (cppVar_61290) {
	cppVar_61285 = DPL;
	} else {
	cppVar_61292 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61293 = (cppVar_61292 << 3) | 7;
	cppVar_61293 = (cppVar_61293 & cppMask_un_5_);
	cppVar_61294 = (0 << 5) | cppVar_61293;
	cppVar_61294 = (cppVar_61294 & cppMask_un_8_);
	cppVar_61296 = (cppVar_61294 == 131);
	if (cppVar_61296) {
	cppVar_61291 = DPH;
	} else {
	cppVar_61298 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61299 = (cppVar_61298 << 3) | 7;
	cppVar_61299 = (cppVar_61299 & cppMask_un_5_);
	cppVar_61300 = (0 << 5) | cppVar_61299;
	cppVar_61300 = (cppVar_61300 & cppMask_un_8_);
	cppVar_61302 = (cppVar_61300 == 135);
	if (cppVar_61302) {
	cppVar_61297 = PCON;
	} else {
	cppVar_61304 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61305 = (cppVar_61304 << 3) | 7;
	cppVar_61305 = (cppVar_61305 & cppMask_un_5_);
	cppVar_61306 = (0 << 5) | cppVar_61305;
	cppVar_61306 = (cppVar_61306 & cppMask_un_8_);
	cppVar_61308 = (cppVar_61306 == 136);
	if (cppVar_61308) {
	cppVar_61303 = TCON;
	} else {
	cppVar_61310 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61311 = (cppVar_61310 << 3) | 7;
	cppVar_61311 = (cppVar_61311 & cppMask_un_5_);
	cppVar_61312 = (0 << 5) | cppVar_61311;
	cppVar_61312 = (cppVar_61312 & cppMask_un_8_);
	cppVar_61314 = (cppVar_61312 == 137);
	if (cppVar_61314) {
	cppVar_61309 = TMOD;
	} else {
	cppVar_61316 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61317 = (cppVar_61316 << 3) | 7;
	cppVar_61317 = (cppVar_61317 & cppMask_un_5_);
	cppVar_61318 = (0 << 5) | cppVar_61317;
	cppVar_61318 = (cppVar_61318 & cppMask_un_8_);
	cppVar_61320 = (cppVar_61318 == 138);
	if (cppVar_61320) {
	cppVar_61315 = TL0;
	} else {
	cppVar_61322 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61323 = (cppVar_61322 << 3) | 7;
	cppVar_61323 = (cppVar_61323 & cppMask_un_5_);
	cppVar_61324 = (0 << 5) | cppVar_61323;
	cppVar_61324 = (cppVar_61324 & cppMask_un_8_);
	cppVar_61326 = (cppVar_61324 == 140);
	if (cppVar_61326) {
	cppVar_61321 = TH0;
	} else {
	cppVar_61328 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61329 = (cppVar_61328 << 3) | 7;
	cppVar_61329 = (cppVar_61329 & cppMask_un_5_);
	cppVar_61330 = (0 << 5) | cppVar_61329;
	cppVar_61330 = (cppVar_61330 & cppMask_un_8_);
	cppVar_61332 = (cppVar_61330 == 139);
	if (cppVar_61332) {
	cppVar_61327 = TL1;
	} else {
	cppVar_61334 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61335 = (cppVar_61334 << 3) | 7;
	cppVar_61335 = (cppVar_61335 & cppMask_un_5_);
	cppVar_61336 = (0 << 5) | cppVar_61335;
	cppVar_61336 = (cppVar_61336 & cppMask_un_8_);
	cppVar_61338 = (cppVar_61336 == 141);
	if (cppVar_61338) {
	cppVar_61333 = TH1;
	} else {
	cppVar_61340 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61341 = (cppVar_61340 << 3) | 7;
	cppVar_61341 = (cppVar_61341 & cppMask_un_5_);
	cppVar_61342 = (0 << 5) | cppVar_61341;
	cppVar_61342 = (cppVar_61342 & cppMask_un_8_);
	cppVar_61344 = (cppVar_61342 == 144);
	if (cppVar_61344) {
	cppVar_61339 = P1;
	} else {
	cppVar_61346 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61347 = (cppVar_61346 << 3) | 7;
	cppVar_61347 = (cppVar_61347 & cppMask_un_5_);
	cppVar_61348 = (0 << 5) | cppVar_61347;
	cppVar_61348 = (cppVar_61348 & cppMask_un_8_);
	cppVar_61350 = (cppVar_61348 == 152);
	if (cppVar_61350) {
	cppVar_61345 = SCON;
	} else {
	cppVar_61352 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61353 = (cppVar_61352 << 3) | 7;
	cppVar_61353 = (cppVar_61353 & cppMask_un_5_);
	cppVar_61354 = (0 << 5) | cppVar_61353;
	cppVar_61354 = (cppVar_61354 & cppMask_un_8_);
	cppVar_61356 = (cppVar_61354 == 153);
	if (cppVar_61356) {
	cppVar_61351 = SBUF;
	} else {
	cppVar_61358 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61359 = (cppVar_61358 << 3) | 7;
	cppVar_61359 = (cppVar_61359 & cppMask_un_5_);
	cppVar_61360 = (0 << 5) | cppVar_61359;
	cppVar_61360 = (cppVar_61360 & cppMask_un_8_);
	cppVar_61362 = (cppVar_61360 == 160);
	if (cppVar_61362) {
	cppVar_61357 = P2;
	} else {
	cppVar_61364 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61365 = (cppVar_61364 << 3) | 7;
	cppVar_61365 = (cppVar_61365 & cppMask_un_5_);
	cppVar_61366 = (0 << 5) | cppVar_61365;
	cppVar_61366 = (cppVar_61366 & cppMask_un_8_);
	cppVar_61368 = (cppVar_61366 == 168);
	if (cppVar_61368) {
	cppVar_61363 = IE;
	} else {
	cppVar_61370 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61371 = (cppVar_61370 << 3) | 7;
	cppVar_61371 = (cppVar_61371 & cppMask_un_5_);
	cppVar_61372 = (0 << 5) | cppVar_61371;
	cppVar_61372 = (cppVar_61372 & cppMask_un_8_);
	cppVar_61374 = (cppVar_61372 == 176);
	if (cppVar_61374) {
	cppVar_61369 = P3;
	} else {
	cppVar_61376 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61377 = (cppVar_61376 << 3) | 7;
	cppVar_61377 = (cppVar_61377 & cppMask_un_5_);
	cppVar_61378 = (0 << 5) | cppVar_61377;
	cppVar_61378 = (cppVar_61378 & cppMask_un_8_);
	cppVar_61380 = (cppVar_61378 == 184);
	if (cppVar_61380) {
	cppVar_61375 = IP;
	} else {
	cppVar_61382 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61383 = (cppVar_61382 << 3) | 7;
	cppVar_61383 = (cppVar_61383 & cppMask_un_5_);
	cppVar_61384 = (0 << 5) | cppVar_61383;
	cppVar_61384 = (cppVar_61384 & cppMask_un_8_);
	cppVar_61386 = (cppVar_61384 == 208);
	if (cppVar_61386) {
	cppVar_61381 = PSW;
	} else {
	cppVar_61388 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61389 = (cppVar_61388 << 3) | 7;
	cppVar_61389 = (cppVar_61389 & cppMask_un_5_);
	cppVar_61390 = (0 << 5) | cppVar_61389;
	cppVar_61390 = (cppVar_61390 & cppMask_un_8_);
	cppVar_61392 = (cppVar_61390 == 224);
	if (cppVar_61392) {
	cppVar_61387 = ACC;
	} else {
	cppVar_61394 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61395 = (cppVar_61394 << 3) | 7;
	cppVar_61395 = (cppVar_61395 & cppMask_un_5_);
	cppVar_61396 = (0 << 5) | cppVar_61395;
	cppVar_61396 = (cppVar_61396 & cppMask_un_8_);
	cppVar_61398 = (cppVar_61396 == 240);
	if (cppVar_61398) {
	cppVar_61393 = B;
	} else {
	cppVar_61393 = 0;
	}
	cppVar_61387 = cppVar_61393;
	}
	cppVar_61381 = cppVar_61387;
	}
	cppVar_61375 = cppVar_61381;
	}
	cppVar_61369 = cppVar_61375;
	}
	cppVar_61363 = cppVar_61369;
	}
	cppVar_61357 = cppVar_61363;
	}
	cppVar_61351 = cppVar_61357;
	}
	cppVar_61345 = cppVar_61351;
	}
	cppVar_61339 = cppVar_61345;
	}
	cppVar_61333 = cppVar_61339;
	}
	cppVar_61327 = cppVar_61333;
	}
	cppVar_61321 = cppVar_61327;
	}
	cppVar_61315 = cppVar_61321;
	}
	cppVar_61309 = cppVar_61315;
	}
	cppVar_61303 = cppVar_61309;
	}
	cppVar_61297 = cppVar_61303;
	}
	cppVar_61291 = cppVar_61297;
	}
	cppVar_61285 = cppVar_61291;
	}
	cppVar_61279 = cppVar_61285;
	}
	cppVar_61273 = cppVar_61279;
	}
	cppVar_61260 = cppVar_61273;
	}
	cppVar_61254 = cppVar_61260;
	} else {
	cppVar_61254 = SCON;
	}
	cppVar_61250 = cppVar_61254;
	} else {
	cppVar_61401 = ROM.rd(PC);
	cppVar_61403 = (cppVar_61401 == 142);
	if (cppVar_61403) {
	cppVar_61406 = PC + 1;
	cppVar_61406 = (cppVar_61406 & cppMask_un_16_);
	cppVar_61407 = ROM.rd(cppVar_61406);
	cppVar_61409 = (cppVar_61407 == 152);
	if (cppVar_61409) {
	cppVar_61412 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61414 = (cppVar_61412 << 3) | 6;
	cppVar_61414 = (cppVar_61414 & cppMask_un_5_);
	cppVar_61415 = (0 << 5) | cppVar_61414;
	cppVar_61415 = (cppVar_61415 & cppMask_un_8_);
	cppVar_61416 = (cppVar_61415 >> 7) & cppMask_un_1_;
	cppVar_61418 = (cppVar_61416 == 0);
	if (cppVar_61418) {
	cppVar_61419 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61420 = (cppVar_61419 << 3) | 6;
	cppVar_61420 = (cppVar_61420 & cppMask_un_5_);
	cppVar_61421 = (0 << 5) | cppVar_61420;
	cppVar_61421 = (cppVar_61421 & cppMask_un_8_);
	cppVar_61422 = IRAM.rd(cppVar_61421);
	cppVar_61410 = cppVar_61422;
	} else {
	cppVar_61424 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61425 = (cppVar_61424 << 3) | 6;
	cppVar_61425 = (cppVar_61425 & cppMask_un_5_);
	cppVar_61426 = (0 << 5) | cppVar_61425;
	cppVar_61426 = (cppVar_61426 & cppMask_un_8_);
	cppVar_61428 = (cppVar_61426 == 128);
	if (cppVar_61428) {
	cppVar_61423 = P0;
	} else {
	cppVar_61430 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61431 = (cppVar_61430 << 3) | 6;
	cppVar_61431 = (cppVar_61431 & cppMask_un_5_);
	cppVar_61432 = (0 << 5) | cppVar_61431;
	cppVar_61432 = (cppVar_61432 & cppMask_un_8_);
	cppVar_61434 = (cppVar_61432 == 129);
	if (cppVar_61434) {
	cppVar_61429 = SP;
	} else {
	cppVar_61436 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61437 = (cppVar_61436 << 3) | 6;
	cppVar_61437 = (cppVar_61437 & cppMask_un_5_);
	cppVar_61438 = (0 << 5) | cppVar_61437;
	cppVar_61438 = (cppVar_61438 & cppMask_un_8_);
	cppVar_61440 = (cppVar_61438 == 130);
	if (cppVar_61440) {
	cppVar_61435 = DPL;
	} else {
	cppVar_61442 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61443 = (cppVar_61442 << 3) | 6;
	cppVar_61443 = (cppVar_61443 & cppMask_un_5_);
	cppVar_61444 = (0 << 5) | cppVar_61443;
	cppVar_61444 = (cppVar_61444 & cppMask_un_8_);
	cppVar_61446 = (cppVar_61444 == 131);
	if (cppVar_61446) {
	cppVar_61441 = DPH;
	} else {
	cppVar_61448 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61449 = (cppVar_61448 << 3) | 6;
	cppVar_61449 = (cppVar_61449 & cppMask_un_5_);
	cppVar_61450 = (0 << 5) | cppVar_61449;
	cppVar_61450 = (cppVar_61450 & cppMask_un_8_);
	cppVar_61452 = (cppVar_61450 == 135);
	if (cppVar_61452) {
	cppVar_61447 = PCON;
	} else {
	cppVar_61454 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61455 = (cppVar_61454 << 3) | 6;
	cppVar_61455 = (cppVar_61455 & cppMask_un_5_);
	cppVar_61456 = (0 << 5) | cppVar_61455;
	cppVar_61456 = (cppVar_61456 & cppMask_un_8_);
	cppVar_61458 = (cppVar_61456 == 136);
	if (cppVar_61458) {
	cppVar_61453 = TCON;
	} else {
	cppVar_61460 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61461 = (cppVar_61460 << 3) | 6;
	cppVar_61461 = (cppVar_61461 & cppMask_un_5_);
	cppVar_61462 = (0 << 5) | cppVar_61461;
	cppVar_61462 = (cppVar_61462 & cppMask_un_8_);
	cppVar_61464 = (cppVar_61462 == 137);
	if (cppVar_61464) {
	cppVar_61459 = TMOD;
	} else {
	cppVar_61466 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61467 = (cppVar_61466 << 3) | 6;
	cppVar_61467 = (cppVar_61467 & cppMask_un_5_);
	cppVar_61468 = (0 << 5) | cppVar_61467;
	cppVar_61468 = (cppVar_61468 & cppMask_un_8_);
	cppVar_61470 = (cppVar_61468 == 138);
	if (cppVar_61470) {
	cppVar_61465 = TL0;
	} else {
	cppVar_61472 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61473 = (cppVar_61472 << 3) | 6;
	cppVar_61473 = (cppVar_61473 & cppMask_un_5_);
	cppVar_61474 = (0 << 5) | cppVar_61473;
	cppVar_61474 = (cppVar_61474 & cppMask_un_8_);
	cppVar_61476 = (cppVar_61474 == 140);
	if (cppVar_61476) {
	cppVar_61471 = TH0;
	} else {
	cppVar_61478 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61479 = (cppVar_61478 << 3) | 6;
	cppVar_61479 = (cppVar_61479 & cppMask_un_5_);
	cppVar_61480 = (0 << 5) | cppVar_61479;
	cppVar_61480 = (cppVar_61480 & cppMask_un_8_);
	cppVar_61482 = (cppVar_61480 == 139);
	if (cppVar_61482) {
	cppVar_61477 = TL1;
	} else {
	cppVar_61484 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61485 = (cppVar_61484 << 3) | 6;
	cppVar_61485 = (cppVar_61485 & cppMask_un_5_);
	cppVar_61486 = (0 << 5) | cppVar_61485;
	cppVar_61486 = (cppVar_61486 & cppMask_un_8_);
	cppVar_61488 = (cppVar_61486 == 141);
	if (cppVar_61488) {
	cppVar_61483 = TH1;
	} else {
	cppVar_61490 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61491 = (cppVar_61490 << 3) | 6;
	cppVar_61491 = (cppVar_61491 & cppMask_un_5_);
	cppVar_61492 = (0 << 5) | cppVar_61491;
	cppVar_61492 = (cppVar_61492 & cppMask_un_8_);
	cppVar_61494 = (cppVar_61492 == 144);
	if (cppVar_61494) {
	cppVar_61489 = P1;
	} else {
	cppVar_61496 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61497 = (cppVar_61496 << 3) | 6;
	cppVar_61497 = (cppVar_61497 & cppMask_un_5_);
	cppVar_61498 = (0 << 5) | cppVar_61497;
	cppVar_61498 = (cppVar_61498 & cppMask_un_8_);
	cppVar_61500 = (cppVar_61498 == 152);
	if (cppVar_61500) {
	cppVar_61495 = SCON;
	} else {
	cppVar_61502 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61503 = (cppVar_61502 << 3) | 6;
	cppVar_61503 = (cppVar_61503 & cppMask_un_5_);
	cppVar_61504 = (0 << 5) | cppVar_61503;
	cppVar_61504 = (cppVar_61504 & cppMask_un_8_);
	cppVar_61506 = (cppVar_61504 == 153);
	if (cppVar_61506) {
	cppVar_61501 = SBUF;
	} else {
	cppVar_61508 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61509 = (cppVar_61508 << 3) | 6;
	cppVar_61509 = (cppVar_61509 & cppMask_un_5_);
	cppVar_61510 = (0 << 5) | cppVar_61509;
	cppVar_61510 = (cppVar_61510 & cppMask_un_8_);
	cppVar_61512 = (cppVar_61510 == 160);
	if (cppVar_61512) {
	cppVar_61507 = P2;
	} else {
	cppVar_61514 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61515 = (cppVar_61514 << 3) | 6;
	cppVar_61515 = (cppVar_61515 & cppMask_un_5_);
	cppVar_61516 = (0 << 5) | cppVar_61515;
	cppVar_61516 = (cppVar_61516 & cppMask_un_8_);
	cppVar_61518 = (cppVar_61516 == 168);
	if (cppVar_61518) {
	cppVar_61513 = IE;
	} else {
	cppVar_61520 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61521 = (cppVar_61520 << 3) | 6;
	cppVar_61521 = (cppVar_61521 & cppMask_un_5_);
	cppVar_61522 = (0 << 5) | cppVar_61521;
	cppVar_61522 = (cppVar_61522 & cppMask_un_8_);
	cppVar_61524 = (cppVar_61522 == 176);
	if (cppVar_61524) {
	cppVar_61519 = P3;
	} else {
	cppVar_61526 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61527 = (cppVar_61526 << 3) | 6;
	cppVar_61527 = (cppVar_61527 & cppMask_un_5_);
	cppVar_61528 = (0 << 5) | cppVar_61527;
	cppVar_61528 = (cppVar_61528 & cppMask_un_8_);
	cppVar_61530 = (cppVar_61528 == 184);
	if (cppVar_61530) {
	cppVar_61525 = IP;
	} else {
	cppVar_61532 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61533 = (cppVar_61532 << 3) | 6;
	cppVar_61533 = (cppVar_61533 & cppMask_un_5_);
	cppVar_61534 = (0 << 5) | cppVar_61533;
	cppVar_61534 = (cppVar_61534 & cppMask_un_8_);
	cppVar_61536 = (cppVar_61534 == 208);
	if (cppVar_61536) {
	cppVar_61531 = PSW;
	} else {
	cppVar_61538 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61539 = (cppVar_61538 << 3) | 6;
	cppVar_61539 = (cppVar_61539 & cppMask_un_5_);
	cppVar_61540 = (0 << 5) | cppVar_61539;
	cppVar_61540 = (cppVar_61540 & cppMask_un_8_);
	cppVar_61542 = (cppVar_61540 == 224);
	if (cppVar_61542) {
	cppVar_61537 = ACC;
	} else {
	cppVar_61544 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61545 = (cppVar_61544 << 3) | 6;
	cppVar_61545 = (cppVar_61545 & cppMask_un_5_);
	cppVar_61546 = (0 << 5) | cppVar_61545;
	cppVar_61546 = (cppVar_61546 & cppMask_un_8_);
	cppVar_61548 = (cppVar_61546 == 240);
	if (cppVar_61548) {
	cppVar_61543 = B;
	} else {
	cppVar_61543 = 0;
	}
	cppVar_61537 = cppVar_61543;
	}
	cppVar_61531 = cppVar_61537;
	}
	cppVar_61525 = cppVar_61531;
	}
	cppVar_61519 = cppVar_61525;
	}
	cppVar_61513 = cppVar_61519;
	}
	cppVar_61507 = cppVar_61513;
	}
	cppVar_61501 = cppVar_61507;
	}
	cppVar_61495 = cppVar_61501;
	}
	cppVar_61489 = cppVar_61495;
	}
	cppVar_61483 = cppVar_61489;
	}
	cppVar_61477 = cppVar_61483;
	}
	cppVar_61471 = cppVar_61477;
	}
	cppVar_61465 = cppVar_61471;
	}
	cppVar_61459 = cppVar_61465;
	}
	cppVar_61453 = cppVar_61459;
	}
	cppVar_61447 = cppVar_61453;
	}
	cppVar_61441 = cppVar_61447;
	}
	cppVar_61435 = cppVar_61441;
	}
	cppVar_61429 = cppVar_61435;
	}
	cppVar_61423 = cppVar_61429;
	}
	cppVar_61410 = cppVar_61423;
	}
	cppVar_61404 = cppVar_61410;
	} else {
	cppVar_61404 = SCON;
	}
	cppVar_61400 = cppVar_61404;
	} else {
	cppVar_61551 = ROM.rd(PC);
	cppVar_61553 = (cppVar_61551 == 141);
	if (cppVar_61553) {
	cppVar_61556 = PC + 1;
	cppVar_61556 = (cppVar_61556 & cppMask_un_16_);
	cppVar_61557 = ROM.rd(cppVar_61556);
	cppVar_61559 = (cppVar_61557 == 152);
	if (cppVar_61559) {
	cppVar_61562 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61564 = (cppVar_61562 << 3) | 5;
	cppVar_61564 = (cppVar_61564 & cppMask_un_5_);
	cppVar_61565 = (0 << 5) | cppVar_61564;
	cppVar_61565 = (cppVar_61565 & cppMask_un_8_);
	cppVar_61566 = (cppVar_61565 >> 7) & cppMask_un_1_;
	cppVar_61568 = (cppVar_61566 == 0);
	if (cppVar_61568) {
	cppVar_61569 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61570 = (cppVar_61569 << 3) | 5;
	cppVar_61570 = (cppVar_61570 & cppMask_un_5_);
	cppVar_61571 = (0 << 5) | cppVar_61570;
	cppVar_61571 = (cppVar_61571 & cppMask_un_8_);
	cppVar_61572 = IRAM.rd(cppVar_61571);
	cppVar_61560 = cppVar_61572;
	} else {
	cppVar_61574 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61575 = (cppVar_61574 << 3) | 5;
	cppVar_61575 = (cppVar_61575 & cppMask_un_5_);
	cppVar_61576 = (0 << 5) | cppVar_61575;
	cppVar_61576 = (cppVar_61576 & cppMask_un_8_);
	cppVar_61578 = (cppVar_61576 == 128);
	if (cppVar_61578) {
	cppVar_61573 = P0;
	} else {
	cppVar_61580 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61581 = (cppVar_61580 << 3) | 5;
	cppVar_61581 = (cppVar_61581 & cppMask_un_5_);
	cppVar_61582 = (0 << 5) | cppVar_61581;
	cppVar_61582 = (cppVar_61582 & cppMask_un_8_);
	cppVar_61584 = (cppVar_61582 == 129);
	if (cppVar_61584) {
	cppVar_61579 = SP;
	} else {
	cppVar_61586 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61587 = (cppVar_61586 << 3) | 5;
	cppVar_61587 = (cppVar_61587 & cppMask_un_5_);
	cppVar_61588 = (0 << 5) | cppVar_61587;
	cppVar_61588 = (cppVar_61588 & cppMask_un_8_);
	cppVar_61590 = (cppVar_61588 == 130);
	if (cppVar_61590) {
	cppVar_61585 = DPL;
	} else {
	cppVar_61592 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61593 = (cppVar_61592 << 3) | 5;
	cppVar_61593 = (cppVar_61593 & cppMask_un_5_);
	cppVar_61594 = (0 << 5) | cppVar_61593;
	cppVar_61594 = (cppVar_61594 & cppMask_un_8_);
	cppVar_61596 = (cppVar_61594 == 131);
	if (cppVar_61596) {
	cppVar_61591 = DPH;
	} else {
	cppVar_61598 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61599 = (cppVar_61598 << 3) | 5;
	cppVar_61599 = (cppVar_61599 & cppMask_un_5_);
	cppVar_61600 = (0 << 5) | cppVar_61599;
	cppVar_61600 = (cppVar_61600 & cppMask_un_8_);
	cppVar_61602 = (cppVar_61600 == 135);
	if (cppVar_61602) {
	cppVar_61597 = PCON;
	} else {
	cppVar_61604 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61605 = (cppVar_61604 << 3) | 5;
	cppVar_61605 = (cppVar_61605 & cppMask_un_5_);
	cppVar_61606 = (0 << 5) | cppVar_61605;
	cppVar_61606 = (cppVar_61606 & cppMask_un_8_);
	cppVar_61608 = (cppVar_61606 == 136);
	if (cppVar_61608) {
	cppVar_61603 = TCON;
	} else {
	cppVar_61610 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61611 = (cppVar_61610 << 3) | 5;
	cppVar_61611 = (cppVar_61611 & cppMask_un_5_);
	cppVar_61612 = (0 << 5) | cppVar_61611;
	cppVar_61612 = (cppVar_61612 & cppMask_un_8_);
	cppVar_61614 = (cppVar_61612 == 137);
	if (cppVar_61614) {
	cppVar_61609 = TMOD;
	} else {
	cppVar_61616 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61617 = (cppVar_61616 << 3) | 5;
	cppVar_61617 = (cppVar_61617 & cppMask_un_5_);
	cppVar_61618 = (0 << 5) | cppVar_61617;
	cppVar_61618 = (cppVar_61618 & cppMask_un_8_);
	cppVar_61620 = (cppVar_61618 == 138);
	if (cppVar_61620) {
	cppVar_61615 = TL0;
	} else {
	cppVar_61622 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61623 = (cppVar_61622 << 3) | 5;
	cppVar_61623 = (cppVar_61623 & cppMask_un_5_);
	cppVar_61624 = (0 << 5) | cppVar_61623;
	cppVar_61624 = (cppVar_61624 & cppMask_un_8_);
	cppVar_61626 = (cppVar_61624 == 140);
	if (cppVar_61626) {
	cppVar_61621 = TH0;
	} else {
	cppVar_61628 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61629 = (cppVar_61628 << 3) | 5;
	cppVar_61629 = (cppVar_61629 & cppMask_un_5_);
	cppVar_61630 = (0 << 5) | cppVar_61629;
	cppVar_61630 = (cppVar_61630 & cppMask_un_8_);
	cppVar_61632 = (cppVar_61630 == 139);
	if (cppVar_61632) {
	cppVar_61627 = TL1;
	} else {
	cppVar_61634 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61635 = (cppVar_61634 << 3) | 5;
	cppVar_61635 = (cppVar_61635 & cppMask_un_5_);
	cppVar_61636 = (0 << 5) | cppVar_61635;
	cppVar_61636 = (cppVar_61636 & cppMask_un_8_);
	cppVar_61638 = (cppVar_61636 == 141);
	if (cppVar_61638) {
	cppVar_61633 = TH1;
	} else {
	cppVar_61640 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61641 = (cppVar_61640 << 3) | 5;
	cppVar_61641 = (cppVar_61641 & cppMask_un_5_);
	cppVar_61642 = (0 << 5) | cppVar_61641;
	cppVar_61642 = (cppVar_61642 & cppMask_un_8_);
	cppVar_61644 = (cppVar_61642 == 144);
	if (cppVar_61644) {
	cppVar_61639 = P1;
	} else {
	cppVar_61646 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61647 = (cppVar_61646 << 3) | 5;
	cppVar_61647 = (cppVar_61647 & cppMask_un_5_);
	cppVar_61648 = (0 << 5) | cppVar_61647;
	cppVar_61648 = (cppVar_61648 & cppMask_un_8_);
	cppVar_61650 = (cppVar_61648 == 152);
	if (cppVar_61650) {
	cppVar_61645 = SCON;
	} else {
	cppVar_61652 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61653 = (cppVar_61652 << 3) | 5;
	cppVar_61653 = (cppVar_61653 & cppMask_un_5_);
	cppVar_61654 = (0 << 5) | cppVar_61653;
	cppVar_61654 = (cppVar_61654 & cppMask_un_8_);
	cppVar_61656 = (cppVar_61654 == 153);
	if (cppVar_61656) {
	cppVar_61651 = SBUF;
	} else {
	cppVar_61658 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61659 = (cppVar_61658 << 3) | 5;
	cppVar_61659 = (cppVar_61659 & cppMask_un_5_);
	cppVar_61660 = (0 << 5) | cppVar_61659;
	cppVar_61660 = (cppVar_61660 & cppMask_un_8_);
	cppVar_61662 = (cppVar_61660 == 160);
	if (cppVar_61662) {
	cppVar_61657 = P2;
	} else {
	cppVar_61664 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61665 = (cppVar_61664 << 3) | 5;
	cppVar_61665 = (cppVar_61665 & cppMask_un_5_);
	cppVar_61666 = (0 << 5) | cppVar_61665;
	cppVar_61666 = (cppVar_61666 & cppMask_un_8_);
	cppVar_61668 = (cppVar_61666 == 168);
	if (cppVar_61668) {
	cppVar_61663 = IE;
	} else {
	cppVar_61670 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61671 = (cppVar_61670 << 3) | 5;
	cppVar_61671 = (cppVar_61671 & cppMask_un_5_);
	cppVar_61672 = (0 << 5) | cppVar_61671;
	cppVar_61672 = (cppVar_61672 & cppMask_un_8_);
	cppVar_61674 = (cppVar_61672 == 176);
	if (cppVar_61674) {
	cppVar_61669 = P3;
	} else {
	cppVar_61676 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61677 = (cppVar_61676 << 3) | 5;
	cppVar_61677 = (cppVar_61677 & cppMask_un_5_);
	cppVar_61678 = (0 << 5) | cppVar_61677;
	cppVar_61678 = (cppVar_61678 & cppMask_un_8_);
	cppVar_61680 = (cppVar_61678 == 184);
	if (cppVar_61680) {
	cppVar_61675 = IP;
	} else {
	cppVar_61682 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61683 = (cppVar_61682 << 3) | 5;
	cppVar_61683 = (cppVar_61683 & cppMask_un_5_);
	cppVar_61684 = (0 << 5) | cppVar_61683;
	cppVar_61684 = (cppVar_61684 & cppMask_un_8_);
	cppVar_61686 = (cppVar_61684 == 208);
	if (cppVar_61686) {
	cppVar_61681 = PSW;
	} else {
	cppVar_61688 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61689 = (cppVar_61688 << 3) | 5;
	cppVar_61689 = (cppVar_61689 & cppMask_un_5_);
	cppVar_61690 = (0 << 5) | cppVar_61689;
	cppVar_61690 = (cppVar_61690 & cppMask_un_8_);
	cppVar_61692 = (cppVar_61690 == 224);
	if (cppVar_61692) {
	cppVar_61687 = ACC;
	} else {
	cppVar_61694 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61695 = (cppVar_61694 << 3) | 5;
	cppVar_61695 = (cppVar_61695 & cppMask_un_5_);
	cppVar_61696 = (0 << 5) | cppVar_61695;
	cppVar_61696 = (cppVar_61696 & cppMask_un_8_);
	cppVar_61698 = (cppVar_61696 == 240);
	if (cppVar_61698) {
	cppVar_61693 = B;
	} else {
	cppVar_61693 = 0;
	}
	cppVar_61687 = cppVar_61693;
	}
	cppVar_61681 = cppVar_61687;
	}
	cppVar_61675 = cppVar_61681;
	}
	cppVar_61669 = cppVar_61675;
	}
	cppVar_61663 = cppVar_61669;
	}
	cppVar_61657 = cppVar_61663;
	}
	cppVar_61651 = cppVar_61657;
	}
	cppVar_61645 = cppVar_61651;
	}
	cppVar_61639 = cppVar_61645;
	}
	cppVar_61633 = cppVar_61639;
	}
	cppVar_61627 = cppVar_61633;
	}
	cppVar_61621 = cppVar_61627;
	}
	cppVar_61615 = cppVar_61621;
	}
	cppVar_61609 = cppVar_61615;
	}
	cppVar_61603 = cppVar_61609;
	}
	cppVar_61597 = cppVar_61603;
	}
	cppVar_61591 = cppVar_61597;
	}
	cppVar_61585 = cppVar_61591;
	}
	cppVar_61579 = cppVar_61585;
	}
	cppVar_61573 = cppVar_61579;
	}
	cppVar_61560 = cppVar_61573;
	}
	cppVar_61554 = cppVar_61560;
	} else {
	cppVar_61554 = SCON;
	}
	cppVar_61550 = cppVar_61554;
	} else {
	cppVar_61701 = ROM.rd(PC);
	cppVar_61703 = (cppVar_61701 == 140);
	if (cppVar_61703) {
	cppVar_61706 = PC + 1;
	cppVar_61706 = (cppVar_61706 & cppMask_un_16_);
	cppVar_61707 = ROM.rd(cppVar_61706);
	cppVar_61709 = (cppVar_61707 == 152);
	if (cppVar_61709) {
	cppVar_61712 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61714 = (cppVar_61712 << 3) | 4;
	cppVar_61714 = (cppVar_61714 & cppMask_un_5_);
	cppVar_61715 = (0 << 5) | cppVar_61714;
	cppVar_61715 = (cppVar_61715 & cppMask_un_8_);
	cppVar_61716 = (cppVar_61715 >> 7) & cppMask_un_1_;
	cppVar_61718 = (cppVar_61716 == 0);
	if (cppVar_61718) {
	cppVar_61719 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61720 = (cppVar_61719 << 3) | 4;
	cppVar_61720 = (cppVar_61720 & cppMask_un_5_);
	cppVar_61721 = (0 << 5) | cppVar_61720;
	cppVar_61721 = (cppVar_61721 & cppMask_un_8_);
	cppVar_61722 = IRAM.rd(cppVar_61721);
	cppVar_61710 = cppVar_61722;
	} else {
	cppVar_61724 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61725 = (cppVar_61724 << 3) | 4;
	cppVar_61725 = (cppVar_61725 & cppMask_un_5_);
	cppVar_61726 = (0 << 5) | cppVar_61725;
	cppVar_61726 = (cppVar_61726 & cppMask_un_8_);
	cppVar_61728 = (cppVar_61726 == 128);
	if (cppVar_61728) {
	cppVar_61723 = P0;
	} else {
	cppVar_61730 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61731 = (cppVar_61730 << 3) | 4;
	cppVar_61731 = (cppVar_61731 & cppMask_un_5_);
	cppVar_61732 = (0 << 5) | cppVar_61731;
	cppVar_61732 = (cppVar_61732 & cppMask_un_8_);
	cppVar_61734 = (cppVar_61732 == 129);
	if (cppVar_61734) {
	cppVar_61729 = SP;
	} else {
	cppVar_61736 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61737 = (cppVar_61736 << 3) | 4;
	cppVar_61737 = (cppVar_61737 & cppMask_un_5_);
	cppVar_61738 = (0 << 5) | cppVar_61737;
	cppVar_61738 = (cppVar_61738 & cppMask_un_8_);
	cppVar_61740 = (cppVar_61738 == 130);
	if (cppVar_61740) {
	cppVar_61735 = DPL;
	} else {
	cppVar_61742 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61743 = (cppVar_61742 << 3) | 4;
	cppVar_61743 = (cppVar_61743 & cppMask_un_5_);
	cppVar_61744 = (0 << 5) | cppVar_61743;
	cppVar_61744 = (cppVar_61744 & cppMask_un_8_);
	cppVar_61746 = (cppVar_61744 == 131);
	if (cppVar_61746) {
	cppVar_61741 = DPH;
	} else {
	cppVar_61748 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61749 = (cppVar_61748 << 3) | 4;
	cppVar_61749 = (cppVar_61749 & cppMask_un_5_);
	cppVar_61750 = (0 << 5) | cppVar_61749;
	cppVar_61750 = (cppVar_61750 & cppMask_un_8_);
	cppVar_61752 = (cppVar_61750 == 135);
	if (cppVar_61752) {
	cppVar_61747 = PCON;
	} else {
	cppVar_61754 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61755 = (cppVar_61754 << 3) | 4;
	cppVar_61755 = (cppVar_61755 & cppMask_un_5_);
	cppVar_61756 = (0 << 5) | cppVar_61755;
	cppVar_61756 = (cppVar_61756 & cppMask_un_8_);
	cppVar_61758 = (cppVar_61756 == 136);
	if (cppVar_61758) {
	cppVar_61753 = TCON;
	} else {
	cppVar_61760 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61761 = (cppVar_61760 << 3) | 4;
	cppVar_61761 = (cppVar_61761 & cppMask_un_5_);
	cppVar_61762 = (0 << 5) | cppVar_61761;
	cppVar_61762 = (cppVar_61762 & cppMask_un_8_);
	cppVar_61764 = (cppVar_61762 == 137);
	if (cppVar_61764) {
	cppVar_61759 = TMOD;
	} else {
	cppVar_61766 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61767 = (cppVar_61766 << 3) | 4;
	cppVar_61767 = (cppVar_61767 & cppMask_un_5_);
	cppVar_61768 = (0 << 5) | cppVar_61767;
	cppVar_61768 = (cppVar_61768 & cppMask_un_8_);
	cppVar_61770 = (cppVar_61768 == 138);
	if (cppVar_61770) {
	cppVar_61765 = TL0;
	} else {
	cppVar_61772 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61773 = (cppVar_61772 << 3) | 4;
	cppVar_61773 = (cppVar_61773 & cppMask_un_5_);
	cppVar_61774 = (0 << 5) | cppVar_61773;
	cppVar_61774 = (cppVar_61774 & cppMask_un_8_);
	cppVar_61776 = (cppVar_61774 == 140);
	if (cppVar_61776) {
	cppVar_61771 = TH0;
	} else {
	cppVar_61778 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61779 = (cppVar_61778 << 3) | 4;
	cppVar_61779 = (cppVar_61779 & cppMask_un_5_);
	cppVar_61780 = (0 << 5) | cppVar_61779;
	cppVar_61780 = (cppVar_61780 & cppMask_un_8_);
	cppVar_61782 = (cppVar_61780 == 139);
	if (cppVar_61782) {
	cppVar_61777 = TL1;
	} else {
	cppVar_61784 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61785 = (cppVar_61784 << 3) | 4;
	cppVar_61785 = (cppVar_61785 & cppMask_un_5_);
	cppVar_61786 = (0 << 5) | cppVar_61785;
	cppVar_61786 = (cppVar_61786 & cppMask_un_8_);
	cppVar_61788 = (cppVar_61786 == 141);
	if (cppVar_61788) {
	cppVar_61783 = TH1;
	} else {
	cppVar_61790 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61791 = (cppVar_61790 << 3) | 4;
	cppVar_61791 = (cppVar_61791 & cppMask_un_5_);
	cppVar_61792 = (0 << 5) | cppVar_61791;
	cppVar_61792 = (cppVar_61792 & cppMask_un_8_);
	cppVar_61794 = (cppVar_61792 == 144);
	if (cppVar_61794) {
	cppVar_61789 = P1;
	} else {
	cppVar_61796 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61797 = (cppVar_61796 << 3) | 4;
	cppVar_61797 = (cppVar_61797 & cppMask_un_5_);
	cppVar_61798 = (0 << 5) | cppVar_61797;
	cppVar_61798 = (cppVar_61798 & cppMask_un_8_);
	cppVar_61800 = (cppVar_61798 == 152);
	if (cppVar_61800) {
	cppVar_61795 = SCON;
	} else {
	cppVar_61802 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61803 = (cppVar_61802 << 3) | 4;
	cppVar_61803 = (cppVar_61803 & cppMask_un_5_);
	cppVar_61804 = (0 << 5) | cppVar_61803;
	cppVar_61804 = (cppVar_61804 & cppMask_un_8_);
	cppVar_61806 = (cppVar_61804 == 153);
	if (cppVar_61806) {
	cppVar_61801 = SBUF;
	} else {
	cppVar_61808 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61809 = (cppVar_61808 << 3) | 4;
	cppVar_61809 = (cppVar_61809 & cppMask_un_5_);
	cppVar_61810 = (0 << 5) | cppVar_61809;
	cppVar_61810 = (cppVar_61810 & cppMask_un_8_);
	cppVar_61812 = (cppVar_61810 == 160);
	if (cppVar_61812) {
	cppVar_61807 = P2;
	} else {
	cppVar_61814 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61815 = (cppVar_61814 << 3) | 4;
	cppVar_61815 = (cppVar_61815 & cppMask_un_5_);
	cppVar_61816 = (0 << 5) | cppVar_61815;
	cppVar_61816 = (cppVar_61816 & cppMask_un_8_);
	cppVar_61818 = (cppVar_61816 == 168);
	if (cppVar_61818) {
	cppVar_61813 = IE;
	} else {
	cppVar_61820 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61821 = (cppVar_61820 << 3) | 4;
	cppVar_61821 = (cppVar_61821 & cppMask_un_5_);
	cppVar_61822 = (0 << 5) | cppVar_61821;
	cppVar_61822 = (cppVar_61822 & cppMask_un_8_);
	cppVar_61824 = (cppVar_61822 == 176);
	if (cppVar_61824) {
	cppVar_61819 = P3;
	} else {
	cppVar_61826 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61827 = (cppVar_61826 << 3) | 4;
	cppVar_61827 = (cppVar_61827 & cppMask_un_5_);
	cppVar_61828 = (0 << 5) | cppVar_61827;
	cppVar_61828 = (cppVar_61828 & cppMask_un_8_);
	cppVar_61830 = (cppVar_61828 == 184);
	if (cppVar_61830) {
	cppVar_61825 = IP;
	} else {
	cppVar_61832 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61833 = (cppVar_61832 << 3) | 4;
	cppVar_61833 = (cppVar_61833 & cppMask_un_5_);
	cppVar_61834 = (0 << 5) | cppVar_61833;
	cppVar_61834 = (cppVar_61834 & cppMask_un_8_);
	cppVar_61836 = (cppVar_61834 == 208);
	if (cppVar_61836) {
	cppVar_61831 = PSW;
	} else {
	cppVar_61838 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61839 = (cppVar_61838 << 3) | 4;
	cppVar_61839 = (cppVar_61839 & cppMask_un_5_);
	cppVar_61840 = (0 << 5) | cppVar_61839;
	cppVar_61840 = (cppVar_61840 & cppMask_un_8_);
	cppVar_61842 = (cppVar_61840 == 224);
	if (cppVar_61842) {
	cppVar_61837 = ACC;
	} else {
	cppVar_61844 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61845 = (cppVar_61844 << 3) | 4;
	cppVar_61845 = (cppVar_61845 & cppMask_un_5_);
	cppVar_61846 = (0 << 5) | cppVar_61845;
	cppVar_61846 = (cppVar_61846 & cppMask_un_8_);
	cppVar_61848 = (cppVar_61846 == 240);
	if (cppVar_61848) {
	cppVar_61843 = B;
	} else {
	cppVar_61843 = 0;
	}
	cppVar_61837 = cppVar_61843;
	}
	cppVar_61831 = cppVar_61837;
	}
	cppVar_61825 = cppVar_61831;
	}
	cppVar_61819 = cppVar_61825;
	}
	cppVar_61813 = cppVar_61819;
	}
	cppVar_61807 = cppVar_61813;
	}
	cppVar_61801 = cppVar_61807;
	}
	cppVar_61795 = cppVar_61801;
	}
	cppVar_61789 = cppVar_61795;
	}
	cppVar_61783 = cppVar_61789;
	}
	cppVar_61777 = cppVar_61783;
	}
	cppVar_61771 = cppVar_61777;
	}
	cppVar_61765 = cppVar_61771;
	}
	cppVar_61759 = cppVar_61765;
	}
	cppVar_61753 = cppVar_61759;
	}
	cppVar_61747 = cppVar_61753;
	}
	cppVar_61741 = cppVar_61747;
	}
	cppVar_61735 = cppVar_61741;
	}
	cppVar_61729 = cppVar_61735;
	}
	cppVar_61723 = cppVar_61729;
	}
	cppVar_61710 = cppVar_61723;
	}
	cppVar_61704 = cppVar_61710;
	} else {
	cppVar_61704 = SCON;
	}
	cppVar_61700 = cppVar_61704;
	} else {
	cppVar_61851 = ROM.rd(PC);
	cppVar_61853 = (cppVar_61851 == 139);
	if (cppVar_61853) {
	cppVar_61856 = PC + 1;
	cppVar_61856 = (cppVar_61856 & cppMask_un_16_);
	cppVar_61857 = ROM.rd(cppVar_61856);
	cppVar_61859 = (cppVar_61857 == 152);
	if (cppVar_61859) {
	cppVar_61862 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61864 = (cppVar_61862 << 3) | 3;
	cppVar_61864 = (cppVar_61864 & cppMask_un_5_);
	cppVar_61865 = (0 << 5) | cppVar_61864;
	cppVar_61865 = (cppVar_61865 & cppMask_un_8_);
	cppVar_61866 = (cppVar_61865 >> 7) & cppMask_un_1_;
	cppVar_61868 = (cppVar_61866 == 0);
	if (cppVar_61868) {
	cppVar_61869 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61870 = (cppVar_61869 << 3) | 3;
	cppVar_61870 = (cppVar_61870 & cppMask_un_5_);
	cppVar_61871 = (0 << 5) | cppVar_61870;
	cppVar_61871 = (cppVar_61871 & cppMask_un_8_);
	cppVar_61872 = IRAM.rd(cppVar_61871);
	cppVar_61860 = cppVar_61872;
	} else {
	cppVar_61874 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61875 = (cppVar_61874 << 3) | 3;
	cppVar_61875 = (cppVar_61875 & cppMask_un_5_);
	cppVar_61876 = (0 << 5) | cppVar_61875;
	cppVar_61876 = (cppVar_61876 & cppMask_un_8_);
	cppVar_61878 = (cppVar_61876 == 128);
	if (cppVar_61878) {
	cppVar_61873 = P0;
	} else {
	cppVar_61880 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61881 = (cppVar_61880 << 3) | 3;
	cppVar_61881 = (cppVar_61881 & cppMask_un_5_);
	cppVar_61882 = (0 << 5) | cppVar_61881;
	cppVar_61882 = (cppVar_61882 & cppMask_un_8_);
	cppVar_61884 = (cppVar_61882 == 129);
	if (cppVar_61884) {
	cppVar_61879 = SP;
	} else {
	cppVar_61886 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61887 = (cppVar_61886 << 3) | 3;
	cppVar_61887 = (cppVar_61887 & cppMask_un_5_);
	cppVar_61888 = (0 << 5) | cppVar_61887;
	cppVar_61888 = (cppVar_61888 & cppMask_un_8_);
	cppVar_61890 = (cppVar_61888 == 130);
	if (cppVar_61890) {
	cppVar_61885 = DPL;
	} else {
	cppVar_61892 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61893 = (cppVar_61892 << 3) | 3;
	cppVar_61893 = (cppVar_61893 & cppMask_un_5_);
	cppVar_61894 = (0 << 5) | cppVar_61893;
	cppVar_61894 = (cppVar_61894 & cppMask_un_8_);
	cppVar_61896 = (cppVar_61894 == 131);
	if (cppVar_61896) {
	cppVar_61891 = DPH;
	} else {
	cppVar_61898 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61899 = (cppVar_61898 << 3) | 3;
	cppVar_61899 = (cppVar_61899 & cppMask_un_5_);
	cppVar_61900 = (0 << 5) | cppVar_61899;
	cppVar_61900 = (cppVar_61900 & cppMask_un_8_);
	cppVar_61902 = (cppVar_61900 == 135);
	if (cppVar_61902) {
	cppVar_61897 = PCON;
	} else {
	cppVar_61904 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61905 = (cppVar_61904 << 3) | 3;
	cppVar_61905 = (cppVar_61905 & cppMask_un_5_);
	cppVar_61906 = (0 << 5) | cppVar_61905;
	cppVar_61906 = (cppVar_61906 & cppMask_un_8_);
	cppVar_61908 = (cppVar_61906 == 136);
	if (cppVar_61908) {
	cppVar_61903 = TCON;
	} else {
	cppVar_61910 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61911 = (cppVar_61910 << 3) | 3;
	cppVar_61911 = (cppVar_61911 & cppMask_un_5_);
	cppVar_61912 = (0 << 5) | cppVar_61911;
	cppVar_61912 = (cppVar_61912 & cppMask_un_8_);
	cppVar_61914 = (cppVar_61912 == 137);
	if (cppVar_61914) {
	cppVar_61909 = TMOD;
	} else {
	cppVar_61916 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61917 = (cppVar_61916 << 3) | 3;
	cppVar_61917 = (cppVar_61917 & cppMask_un_5_);
	cppVar_61918 = (0 << 5) | cppVar_61917;
	cppVar_61918 = (cppVar_61918 & cppMask_un_8_);
	cppVar_61920 = (cppVar_61918 == 138);
	if (cppVar_61920) {
	cppVar_61915 = TL0;
	} else {
	cppVar_61922 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61923 = (cppVar_61922 << 3) | 3;
	cppVar_61923 = (cppVar_61923 & cppMask_un_5_);
	cppVar_61924 = (0 << 5) | cppVar_61923;
	cppVar_61924 = (cppVar_61924 & cppMask_un_8_);
	cppVar_61926 = (cppVar_61924 == 140);
	if (cppVar_61926) {
	cppVar_61921 = TH0;
	} else {
	cppVar_61928 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61929 = (cppVar_61928 << 3) | 3;
	cppVar_61929 = (cppVar_61929 & cppMask_un_5_);
	cppVar_61930 = (0 << 5) | cppVar_61929;
	cppVar_61930 = (cppVar_61930 & cppMask_un_8_);
	cppVar_61932 = (cppVar_61930 == 139);
	if (cppVar_61932) {
	cppVar_61927 = TL1;
	} else {
	cppVar_61934 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61935 = (cppVar_61934 << 3) | 3;
	cppVar_61935 = (cppVar_61935 & cppMask_un_5_);
	cppVar_61936 = (0 << 5) | cppVar_61935;
	cppVar_61936 = (cppVar_61936 & cppMask_un_8_);
	cppVar_61938 = (cppVar_61936 == 141);
	if (cppVar_61938) {
	cppVar_61933 = TH1;
	} else {
	cppVar_61940 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61941 = (cppVar_61940 << 3) | 3;
	cppVar_61941 = (cppVar_61941 & cppMask_un_5_);
	cppVar_61942 = (0 << 5) | cppVar_61941;
	cppVar_61942 = (cppVar_61942 & cppMask_un_8_);
	cppVar_61944 = (cppVar_61942 == 144);
	if (cppVar_61944) {
	cppVar_61939 = P1;
	} else {
	cppVar_61946 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61947 = (cppVar_61946 << 3) | 3;
	cppVar_61947 = (cppVar_61947 & cppMask_un_5_);
	cppVar_61948 = (0 << 5) | cppVar_61947;
	cppVar_61948 = (cppVar_61948 & cppMask_un_8_);
	cppVar_61950 = (cppVar_61948 == 152);
	if (cppVar_61950) {
	cppVar_61945 = SCON;
	} else {
	cppVar_61952 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61953 = (cppVar_61952 << 3) | 3;
	cppVar_61953 = (cppVar_61953 & cppMask_un_5_);
	cppVar_61954 = (0 << 5) | cppVar_61953;
	cppVar_61954 = (cppVar_61954 & cppMask_un_8_);
	cppVar_61956 = (cppVar_61954 == 153);
	if (cppVar_61956) {
	cppVar_61951 = SBUF;
	} else {
	cppVar_61958 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61959 = (cppVar_61958 << 3) | 3;
	cppVar_61959 = (cppVar_61959 & cppMask_un_5_);
	cppVar_61960 = (0 << 5) | cppVar_61959;
	cppVar_61960 = (cppVar_61960 & cppMask_un_8_);
	cppVar_61962 = (cppVar_61960 == 160);
	if (cppVar_61962) {
	cppVar_61957 = P2;
	} else {
	cppVar_61964 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61965 = (cppVar_61964 << 3) | 3;
	cppVar_61965 = (cppVar_61965 & cppMask_un_5_);
	cppVar_61966 = (0 << 5) | cppVar_61965;
	cppVar_61966 = (cppVar_61966 & cppMask_un_8_);
	cppVar_61968 = (cppVar_61966 == 168);
	if (cppVar_61968) {
	cppVar_61963 = IE;
	} else {
	cppVar_61970 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61971 = (cppVar_61970 << 3) | 3;
	cppVar_61971 = (cppVar_61971 & cppMask_un_5_);
	cppVar_61972 = (0 << 5) | cppVar_61971;
	cppVar_61972 = (cppVar_61972 & cppMask_un_8_);
	cppVar_61974 = (cppVar_61972 == 176);
	if (cppVar_61974) {
	cppVar_61969 = P3;
	} else {
	cppVar_61976 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61977 = (cppVar_61976 << 3) | 3;
	cppVar_61977 = (cppVar_61977 & cppMask_un_5_);
	cppVar_61978 = (0 << 5) | cppVar_61977;
	cppVar_61978 = (cppVar_61978 & cppMask_un_8_);
	cppVar_61980 = (cppVar_61978 == 184);
	if (cppVar_61980) {
	cppVar_61975 = IP;
	} else {
	cppVar_61982 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61983 = (cppVar_61982 << 3) | 3;
	cppVar_61983 = (cppVar_61983 & cppMask_un_5_);
	cppVar_61984 = (0 << 5) | cppVar_61983;
	cppVar_61984 = (cppVar_61984 & cppMask_un_8_);
	cppVar_61986 = (cppVar_61984 == 208);
	if (cppVar_61986) {
	cppVar_61981 = PSW;
	} else {
	cppVar_61988 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61989 = (cppVar_61988 << 3) | 3;
	cppVar_61989 = (cppVar_61989 & cppMask_un_5_);
	cppVar_61990 = (0 << 5) | cppVar_61989;
	cppVar_61990 = (cppVar_61990 & cppMask_un_8_);
	cppVar_61992 = (cppVar_61990 == 224);
	if (cppVar_61992) {
	cppVar_61987 = ACC;
	} else {
	cppVar_61994 = (PSW >> 3) & cppMask_un_2_;
	cppVar_61995 = (cppVar_61994 << 3) | 3;
	cppVar_61995 = (cppVar_61995 & cppMask_un_5_);
	cppVar_61996 = (0 << 5) | cppVar_61995;
	cppVar_61996 = (cppVar_61996 & cppMask_un_8_);
	cppVar_61998 = (cppVar_61996 == 240);
	if (cppVar_61998) {
	cppVar_61993 = B;
	} else {
	cppVar_61993 = 0;
	}
	cppVar_61987 = cppVar_61993;
	}
	cppVar_61981 = cppVar_61987;
	}
	cppVar_61975 = cppVar_61981;
	}
	cppVar_61969 = cppVar_61975;
	}
	cppVar_61963 = cppVar_61969;
	}
	cppVar_61957 = cppVar_61963;
	}
	cppVar_61951 = cppVar_61957;
	}
	cppVar_61945 = cppVar_61951;
	}
	cppVar_61939 = cppVar_61945;
	}
	cppVar_61933 = cppVar_61939;
	}
	cppVar_61927 = cppVar_61933;
	}
	cppVar_61921 = cppVar_61927;
	}
	cppVar_61915 = cppVar_61921;
	}
	cppVar_61909 = cppVar_61915;
	}
	cppVar_61903 = cppVar_61909;
	}
	cppVar_61897 = cppVar_61903;
	}
	cppVar_61891 = cppVar_61897;
	}
	cppVar_61885 = cppVar_61891;
	}
	cppVar_61879 = cppVar_61885;
	}
	cppVar_61873 = cppVar_61879;
	}
	cppVar_61860 = cppVar_61873;
	}
	cppVar_61854 = cppVar_61860;
	} else {
	cppVar_61854 = SCON;
	}
	cppVar_61850 = cppVar_61854;
	} else {
	cppVar_62001 = ROM.rd(PC);
	cppVar_62003 = (cppVar_62001 == 138);
	if (cppVar_62003) {
	cppVar_62006 = PC + 1;
	cppVar_62006 = (cppVar_62006 & cppMask_un_16_);
	cppVar_62007 = ROM.rd(cppVar_62006);
	cppVar_62009 = (cppVar_62007 == 152);
	if (cppVar_62009) {
	cppVar_62012 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62014 = (cppVar_62012 << 3) | 2;
	cppVar_62014 = (cppVar_62014 & cppMask_un_5_);
	cppVar_62015 = (0 << 5) | cppVar_62014;
	cppVar_62015 = (cppVar_62015 & cppMask_un_8_);
	cppVar_62016 = (cppVar_62015 >> 7) & cppMask_un_1_;
	cppVar_62018 = (cppVar_62016 == 0);
	if (cppVar_62018) {
	cppVar_62019 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62020 = (cppVar_62019 << 3) | 2;
	cppVar_62020 = (cppVar_62020 & cppMask_un_5_);
	cppVar_62021 = (0 << 5) | cppVar_62020;
	cppVar_62021 = (cppVar_62021 & cppMask_un_8_);
	cppVar_62022 = IRAM.rd(cppVar_62021);
	cppVar_62010 = cppVar_62022;
	} else {
	cppVar_62024 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62025 = (cppVar_62024 << 3) | 2;
	cppVar_62025 = (cppVar_62025 & cppMask_un_5_);
	cppVar_62026 = (0 << 5) | cppVar_62025;
	cppVar_62026 = (cppVar_62026 & cppMask_un_8_);
	cppVar_62028 = (cppVar_62026 == 128);
	if (cppVar_62028) {
	cppVar_62023 = P0;
	} else {
	cppVar_62030 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62031 = (cppVar_62030 << 3) | 2;
	cppVar_62031 = (cppVar_62031 & cppMask_un_5_);
	cppVar_62032 = (0 << 5) | cppVar_62031;
	cppVar_62032 = (cppVar_62032 & cppMask_un_8_);
	cppVar_62034 = (cppVar_62032 == 129);
	if (cppVar_62034) {
	cppVar_62029 = SP;
	} else {
	cppVar_62036 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62037 = (cppVar_62036 << 3) | 2;
	cppVar_62037 = (cppVar_62037 & cppMask_un_5_);
	cppVar_62038 = (0 << 5) | cppVar_62037;
	cppVar_62038 = (cppVar_62038 & cppMask_un_8_);
	cppVar_62040 = (cppVar_62038 == 130);
	if (cppVar_62040) {
	cppVar_62035 = DPL;
	} else {
	cppVar_62042 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62043 = (cppVar_62042 << 3) | 2;
	cppVar_62043 = (cppVar_62043 & cppMask_un_5_);
	cppVar_62044 = (0 << 5) | cppVar_62043;
	cppVar_62044 = (cppVar_62044 & cppMask_un_8_);
	cppVar_62046 = (cppVar_62044 == 131);
	if (cppVar_62046) {
	cppVar_62041 = DPH;
	} else {
	cppVar_62048 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62049 = (cppVar_62048 << 3) | 2;
	cppVar_62049 = (cppVar_62049 & cppMask_un_5_);
	cppVar_62050 = (0 << 5) | cppVar_62049;
	cppVar_62050 = (cppVar_62050 & cppMask_un_8_);
	cppVar_62052 = (cppVar_62050 == 135);
	if (cppVar_62052) {
	cppVar_62047 = PCON;
	} else {
	cppVar_62054 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62055 = (cppVar_62054 << 3) | 2;
	cppVar_62055 = (cppVar_62055 & cppMask_un_5_);
	cppVar_62056 = (0 << 5) | cppVar_62055;
	cppVar_62056 = (cppVar_62056 & cppMask_un_8_);
	cppVar_62058 = (cppVar_62056 == 136);
	if (cppVar_62058) {
	cppVar_62053 = TCON;
	} else {
	cppVar_62060 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62061 = (cppVar_62060 << 3) | 2;
	cppVar_62061 = (cppVar_62061 & cppMask_un_5_);
	cppVar_62062 = (0 << 5) | cppVar_62061;
	cppVar_62062 = (cppVar_62062 & cppMask_un_8_);
	cppVar_62064 = (cppVar_62062 == 137);
	if (cppVar_62064) {
	cppVar_62059 = TMOD;
	} else {
	cppVar_62066 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62067 = (cppVar_62066 << 3) | 2;
	cppVar_62067 = (cppVar_62067 & cppMask_un_5_);
	cppVar_62068 = (0 << 5) | cppVar_62067;
	cppVar_62068 = (cppVar_62068 & cppMask_un_8_);
	cppVar_62070 = (cppVar_62068 == 138);
	if (cppVar_62070) {
	cppVar_62065 = TL0;
	} else {
	cppVar_62072 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62073 = (cppVar_62072 << 3) | 2;
	cppVar_62073 = (cppVar_62073 & cppMask_un_5_);
	cppVar_62074 = (0 << 5) | cppVar_62073;
	cppVar_62074 = (cppVar_62074 & cppMask_un_8_);
	cppVar_62076 = (cppVar_62074 == 140);
	if (cppVar_62076) {
	cppVar_62071 = TH0;
	} else {
	cppVar_62078 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62079 = (cppVar_62078 << 3) | 2;
	cppVar_62079 = (cppVar_62079 & cppMask_un_5_);
	cppVar_62080 = (0 << 5) | cppVar_62079;
	cppVar_62080 = (cppVar_62080 & cppMask_un_8_);
	cppVar_62082 = (cppVar_62080 == 139);
	if (cppVar_62082) {
	cppVar_62077 = TL1;
	} else {
	cppVar_62084 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62085 = (cppVar_62084 << 3) | 2;
	cppVar_62085 = (cppVar_62085 & cppMask_un_5_);
	cppVar_62086 = (0 << 5) | cppVar_62085;
	cppVar_62086 = (cppVar_62086 & cppMask_un_8_);
	cppVar_62088 = (cppVar_62086 == 141);
	if (cppVar_62088) {
	cppVar_62083 = TH1;
	} else {
	cppVar_62090 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62091 = (cppVar_62090 << 3) | 2;
	cppVar_62091 = (cppVar_62091 & cppMask_un_5_);
	cppVar_62092 = (0 << 5) | cppVar_62091;
	cppVar_62092 = (cppVar_62092 & cppMask_un_8_);
	cppVar_62094 = (cppVar_62092 == 144);
	if (cppVar_62094) {
	cppVar_62089 = P1;
	} else {
	cppVar_62096 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62097 = (cppVar_62096 << 3) | 2;
	cppVar_62097 = (cppVar_62097 & cppMask_un_5_);
	cppVar_62098 = (0 << 5) | cppVar_62097;
	cppVar_62098 = (cppVar_62098 & cppMask_un_8_);
	cppVar_62100 = (cppVar_62098 == 152);
	if (cppVar_62100) {
	cppVar_62095 = SCON;
	} else {
	cppVar_62102 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62103 = (cppVar_62102 << 3) | 2;
	cppVar_62103 = (cppVar_62103 & cppMask_un_5_);
	cppVar_62104 = (0 << 5) | cppVar_62103;
	cppVar_62104 = (cppVar_62104 & cppMask_un_8_);
	cppVar_62106 = (cppVar_62104 == 153);
	if (cppVar_62106) {
	cppVar_62101 = SBUF;
	} else {
	cppVar_62108 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62109 = (cppVar_62108 << 3) | 2;
	cppVar_62109 = (cppVar_62109 & cppMask_un_5_);
	cppVar_62110 = (0 << 5) | cppVar_62109;
	cppVar_62110 = (cppVar_62110 & cppMask_un_8_);
	cppVar_62112 = (cppVar_62110 == 160);
	if (cppVar_62112) {
	cppVar_62107 = P2;
	} else {
	cppVar_62114 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62115 = (cppVar_62114 << 3) | 2;
	cppVar_62115 = (cppVar_62115 & cppMask_un_5_);
	cppVar_62116 = (0 << 5) | cppVar_62115;
	cppVar_62116 = (cppVar_62116 & cppMask_un_8_);
	cppVar_62118 = (cppVar_62116 == 168);
	if (cppVar_62118) {
	cppVar_62113 = IE;
	} else {
	cppVar_62120 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62121 = (cppVar_62120 << 3) | 2;
	cppVar_62121 = (cppVar_62121 & cppMask_un_5_);
	cppVar_62122 = (0 << 5) | cppVar_62121;
	cppVar_62122 = (cppVar_62122 & cppMask_un_8_);
	cppVar_62124 = (cppVar_62122 == 176);
	if (cppVar_62124) {
	cppVar_62119 = P3;
	} else {
	cppVar_62126 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62127 = (cppVar_62126 << 3) | 2;
	cppVar_62127 = (cppVar_62127 & cppMask_un_5_);
	cppVar_62128 = (0 << 5) | cppVar_62127;
	cppVar_62128 = (cppVar_62128 & cppMask_un_8_);
	cppVar_62130 = (cppVar_62128 == 184);
	if (cppVar_62130) {
	cppVar_62125 = IP;
	} else {
	cppVar_62132 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62133 = (cppVar_62132 << 3) | 2;
	cppVar_62133 = (cppVar_62133 & cppMask_un_5_);
	cppVar_62134 = (0 << 5) | cppVar_62133;
	cppVar_62134 = (cppVar_62134 & cppMask_un_8_);
	cppVar_62136 = (cppVar_62134 == 208);
	if (cppVar_62136) {
	cppVar_62131 = PSW;
	} else {
	cppVar_62138 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62139 = (cppVar_62138 << 3) | 2;
	cppVar_62139 = (cppVar_62139 & cppMask_un_5_);
	cppVar_62140 = (0 << 5) | cppVar_62139;
	cppVar_62140 = (cppVar_62140 & cppMask_un_8_);
	cppVar_62142 = (cppVar_62140 == 224);
	if (cppVar_62142) {
	cppVar_62137 = ACC;
	} else {
	cppVar_62144 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62145 = (cppVar_62144 << 3) | 2;
	cppVar_62145 = (cppVar_62145 & cppMask_un_5_);
	cppVar_62146 = (0 << 5) | cppVar_62145;
	cppVar_62146 = (cppVar_62146 & cppMask_un_8_);
	cppVar_62148 = (cppVar_62146 == 240);
	if (cppVar_62148) {
	cppVar_62143 = B;
	} else {
	cppVar_62143 = 0;
	}
	cppVar_62137 = cppVar_62143;
	}
	cppVar_62131 = cppVar_62137;
	}
	cppVar_62125 = cppVar_62131;
	}
	cppVar_62119 = cppVar_62125;
	}
	cppVar_62113 = cppVar_62119;
	}
	cppVar_62107 = cppVar_62113;
	}
	cppVar_62101 = cppVar_62107;
	}
	cppVar_62095 = cppVar_62101;
	}
	cppVar_62089 = cppVar_62095;
	}
	cppVar_62083 = cppVar_62089;
	}
	cppVar_62077 = cppVar_62083;
	}
	cppVar_62071 = cppVar_62077;
	}
	cppVar_62065 = cppVar_62071;
	}
	cppVar_62059 = cppVar_62065;
	}
	cppVar_62053 = cppVar_62059;
	}
	cppVar_62047 = cppVar_62053;
	}
	cppVar_62041 = cppVar_62047;
	}
	cppVar_62035 = cppVar_62041;
	}
	cppVar_62029 = cppVar_62035;
	}
	cppVar_62023 = cppVar_62029;
	}
	cppVar_62010 = cppVar_62023;
	}
	cppVar_62004 = cppVar_62010;
	} else {
	cppVar_62004 = SCON;
	}
	cppVar_62000 = cppVar_62004;
	} else {
	cppVar_62151 = ROM.rd(PC);
	cppVar_62153 = (cppVar_62151 == 137);
	if (cppVar_62153) {
	cppVar_62156 = PC + 1;
	cppVar_62156 = (cppVar_62156 & cppMask_un_16_);
	cppVar_62157 = ROM.rd(cppVar_62156);
	cppVar_62159 = (cppVar_62157 == 152);
	if (cppVar_62159) {
	cppVar_62162 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62164 = (cppVar_62162 << 3) | 1;
	cppVar_62164 = (cppVar_62164 & cppMask_un_5_);
	cppVar_62165 = (0 << 5) | cppVar_62164;
	cppVar_62165 = (cppVar_62165 & cppMask_un_8_);
	cppVar_62166 = (cppVar_62165 >> 7) & cppMask_un_1_;
	cppVar_62168 = (cppVar_62166 == 0);
	if (cppVar_62168) {
	cppVar_62169 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62170 = (cppVar_62169 << 3) | 1;
	cppVar_62170 = (cppVar_62170 & cppMask_un_5_);
	cppVar_62171 = (0 << 5) | cppVar_62170;
	cppVar_62171 = (cppVar_62171 & cppMask_un_8_);
	cppVar_62172 = IRAM.rd(cppVar_62171);
	cppVar_62160 = cppVar_62172;
	} else {
	cppVar_62174 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62175 = (cppVar_62174 << 3) | 1;
	cppVar_62175 = (cppVar_62175 & cppMask_un_5_);
	cppVar_62176 = (0 << 5) | cppVar_62175;
	cppVar_62176 = (cppVar_62176 & cppMask_un_8_);
	cppVar_62178 = (cppVar_62176 == 128);
	if (cppVar_62178) {
	cppVar_62173 = P0;
	} else {
	cppVar_62180 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62181 = (cppVar_62180 << 3) | 1;
	cppVar_62181 = (cppVar_62181 & cppMask_un_5_);
	cppVar_62182 = (0 << 5) | cppVar_62181;
	cppVar_62182 = (cppVar_62182 & cppMask_un_8_);
	cppVar_62184 = (cppVar_62182 == 129);
	if (cppVar_62184) {
	cppVar_62179 = SP;
	} else {
	cppVar_62186 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62187 = (cppVar_62186 << 3) | 1;
	cppVar_62187 = (cppVar_62187 & cppMask_un_5_);
	cppVar_62188 = (0 << 5) | cppVar_62187;
	cppVar_62188 = (cppVar_62188 & cppMask_un_8_);
	cppVar_62190 = (cppVar_62188 == 130);
	if (cppVar_62190) {
	cppVar_62185 = DPL;
	} else {
	cppVar_62192 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62193 = (cppVar_62192 << 3) | 1;
	cppVar_62193 = (cppVar_62193 & cppMask_un_5_);
	cppVar_62194 = (0 << 5) | cppVar_62193;
	cppVar_62194 = (cppVar_62194 & cppMask_un_8_);
	cppVar_62196 = (cppVar_62194 == 131);
	if (cppVar_62196) {
	cppVar_62191 = DPH;
	} else {
	cppVar_62198 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62199 = (cppVar_62198 << 3) | 1;
	cppVar_62199 = (cppVar_62199 & cppMask_un_5_);
	cppVar_62200 = (0 << 5) | cppVar_62199;
	cppVar_62200 = (cppVar_62200 & cppMask_un_8_);
	cppVar_62202 = (cppVar_62200 == 135);
	if (cppVar_62202) {
	cppVar_62197 = PCON;
	} else {
	cppVar_62204 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62205 = (cppVar_62204 << 3) | 1;
	cppVar_62205 = (cppVar_62205 & cppMask_un_5_);
	cppVar_62206 = (0 << 5) | cppVar_62205;
	cppVar_62206 = (cppVar_62206 & cppMask_un_8_);
	cppVar_62208 = (cppVar_62206 == 136);
	if (cppVar_62208) {
	cppVar_62203 = TCON;
	} else {
	cppVar_62210 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62211 = (cppVar_62210 << 3) | 1;
	cppVar_62211 = (cppVar_62211 & cppMask_un_5_);
	cppVar_62212 = (0 << 5) | cppVar_62211;
	cppVar_62212 = (cppVar_62212 & cppMask_un_8_);
	cppVar_62214 = (cppVar_62212 == 137);
	if (cppVar_62214) {
	cppVar_62209 = TMOD;
	} else {
	cppVar_62216 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62217 = (cppVar_62216 << 3) | 1;
	cppVar_62217 = (cppVar_62217 & cppMask_un_5_);
	cppVar_62218 = (0 << 5) | cppVar_62217;
	cppVar_62218 = (cppVar_62218 & cppMask_un_8_);
	cppVar_62220 = (cppVar_62218 == 138);
	if (cppVar_62220) {
	cppVar_62215 = TL0;
	} else {
	cppVar_62222 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62223 = (cppVar_62222 << 3) | 1;
	cppVar_62223 = (cppVar_62223 & cppMask_un_5_);
	cppVar_62224 = (0 << 5) | cppVar_62223;
	cppVar_62224 = (cppVar_62224 & cppMask_un_8_);
	cppVar_62226 = (cppVar_62224 == 140);
	if (cppVar_62226) {
	cppVar_62221 = TH0;
	} else {
	cppVar_62228 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62229 = (cppVar_62228 << 3) | 1;
	cppVar_62229 = (cppVar_62229 & cppMask_un_5_);
	cppVar_62230 = (0 << 5) | cppVar_62229;
	cppVar_62230 = (cppVar_62230 & cppMask_un_8_);
	cppVar_62232 = (cppVar_62230 == 139);
	if (cppVar_62232) {
	cppVar_62227 = TL1;
	} else {
	cppVar_62234 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62235 = (cppVar_62234 << 3) | 1;
	cppVar_62235 = (cppVar_62235 & cppMask_un_5_);
	cppVar_62236 = (0 << 5) | cppVar_62235;
	cppVar_62236 = (cppVar_62236 & cppMask_un_8_);
	cppVar_62238 = (cppVar_62236 == 141);
	if (cppVar_62238) {
	cppVar_62233 = TH1;
	} else {
	cppVar_62240 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62241 = (cppVar_62240 << 3) | 1;
	cppVar_62241 = (cppVar_62241 & cppMask_un_5_);
	cppVar_62242 = (0 << 5) | cppVar_62241;
	cppVar_62242 = (cppVar_62242 & cppMask_un_8_);
	cppVar_62244 = (cppVar_62242 == 144);
	if (cppVar_62244) {
	cppVar_62239 = P1;
	} else {
	cppVar_62246 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62247 = (cppVar_62246 << 3) | 1;
	cppVar_62247 = (cppVar_62247 & cppMask_un_5_);
	cppVar_62248 = (0 << 5) | cppVar_62247;
	cppVar_62248 = (cppVar_62248 & cppMask_un_8_);
	cppVar_62250 = (cppVar_62248 == 152);
	if (cppVar_62250) {
	cppVar_62245 = SCON;
	} else {
	cppVar_62252 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62253 = (cppVar_62252 << 3) | 1;
	cppVar_62253 = (cppVar_62253 & cppMask_un_5_);
	cppVar_62254 = (0 << 5) | cppVar_62253;
	cppVar_62254 = (cppVar_62254 & cppMask_un_8_);
	cppVar_62256 = (cppVar_62254 == 153);
	if (cppVar_62256) {
	cppVar_62251 = SBUF;
	} else {
	cppVar_62258 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62259 = (cppVar_62258 << 3) | 1;
	cppVar_62259 = (cppVar_62259 & cppMask_un_5_);
	cppVar_62260 = (0 << 5) | cppVar_62259;
	cppVar_62260 = (cppVar_62260 & cppMask_un_8_);
	cppVar_62262 = (cppVar_62260 == 160);
	if (cppVar_62262) {
	cppVar_62257 = P2;
	} else {
	cppVar_62264 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62265 = (cppVar_62264 << 3) | 1;
	cppVar_62265 = (cppVar_62265 & cppMask_un_5_);
	cppVar_62266 = (0 << 5) | cppVar_62265;
	cppVar_62266 = (cppVar_62266 & cppMask_un_8_);
	cppVar_62268 = (cppVar_62266 == 168);
	if (cppVar_62268) {
	cppVar_62263 = IE;
	} else {
	cppVar_62270 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62271 = (cppVar_62270 << 3) | 1;
	cppVar_62271 = (cppVar_62271 & cppMask_un_5_);
	cppVar_62272 = (0 << 5) | cppVar_62271;
	cppVar_62272 = (cppVar_62272 & cppMask_un_8_);
	cppVar_62274 = (cppVar_62272 == 176);
	if (cppVar_62274) {
	cppVar_62269 = P3;
	} else {
	cppVar_62276 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62277 = (cppVar_62276 << 3) | 1;
	cppVar_62277 = (cppVar_62277 & cppMask_un_5_);
	cppVar_62278 = (0 << 5) | cppVar_62277;
	cppVar_62278 = (cppVar_62278 & cppMask_un_8_);
	cppVar_62280 = (cppVar_62278 == 184);
	if (cppVar_62280) {
	cppVar_62275 = IP;
	} else {
	cppVar_62282 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62283 = (cppVar_62282 << 3) | 1;
	cppVar_62283 = (cppVar_62283 & cppMask_un_5_);
	cppVar_62284 = (0 << 5) | cppVar_62283;
	cppVar_62284 = (cppVar_62284 & cppMask_un_8_);
	cppVar_62286 = (cppVar_62284 == 208);
	if (cppVar_62286) {
	cppVar_62281 = PSW;
	} else {
	cppVar_62288 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62289 = (cppVar_62288 << 3) | 1;
	cppVar_62289 = (cppVar_62289 & cppMask_un_5_);
	cppVar_62290 = (0 << 5) | cppVar_62289;
	cppVar_62290 = (cppVar_62290 & cppMask_un_8_);
	cppVar_62292 = (cppVar_62290 == 224);
	if (cppVar_62292) {
	cppVar_62287 = ACC;
	} else {
	cppVar_62294 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62295 = (cppVar_62294 << 3) | 1;
	cppVar_62295 = (cppVar_62295 & cppMask_un_5_);
	cppVar_62296 = (0 << 5) | cppVar_62295;
	cppVar_62296 = (cppVar_62296 & cppMask_un_8_);
	cppVar_62298 = (cppVar_62296 == 240);
	if (cppVar_62298) {
	cppVar_62293 = B;
	} else {
	cppVar_62293 = 0;
	}
	cppVar_62287 = cppVar_62293;
	}
	cppVar_62281 = cppVar_62287;
	}
	cppVar_62275 = cppVar_62281;
	}
	cppVar_62269 = cppVar_62275;
	}
	cppVar_62263 = cppVar_62269;
	}
	cppVar_62257 = cppVar_62263;
	}
	cppVar_62251 = cppVar_62257;
	}
	cppVar_62245 = cppVar_62251;
	}
	cppVar_62239 = cppVar_62245;
	}
	cppVar_62233 = cppVar_62239;
	}
	cppVar_62227 = cppVar_62233;
	}
	cppVar_62221 = cppVar_62227;
	}
	cppVar_62215 = cppVar_62221;
	}
	cppVar_62209 = cppVar_62215;
	}
	cppVar_62203 = cppVar_62209;
	}
	cppVar_62197 = cppVar_62203;
	}
	cppVar_62191 = cppVar_62197;
	}
	cppVar_62185 = cppVar_62191;
	}
	cppVar_62179 = cppVar_62185;
	}
	cppVar_62173 = cppVar_62179;
	}
	cppVar_62160 = cppVar_62173;
	}
	cppVar_62154 = cppVar_62160;
	} else {
	cppVar_62154 = SCON;
	}
	cppVar_62150 = cppVar_62154;
	} else {
	cppVar_62301 = ROM.rd(PC);
	cppVar_62303 = (cppVar_62301 == 136);
	if (cppVar_62303) {
	cppVar_62306 = PC + 1;
	cppVar_62306 = (cppVar_62306 & cppMask_un_16_);
	cppVar_62307 = ROM.rd(cppVar_62306);
	cppVar_62309 = (cppVar_62307 == 152);
	if (cppVar_62309) {
	cppVar_62312 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62314 = (cppVar_62312 << 3) | 0;
	cppVar_62314 = (cppVar_62314 & cppMask_un_5_);
	cppVar_62315 = (0 << 5) | cppVar_62314;
	cppVar_62315 = (cppVar_62315 & cppMask_un_8_);
	cppVar_62316 = (cppVar_62315 >> 7) & cppMask_un_1_;
	cppVar_62318 = (cppVar_62316 == 0);
	if (cppVar_62318) {
	cppVar_62319 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62320 = (cppVar_62319 << 3) | 0;
	cppVar_62320 = (cppVar_62320 & cppMask_un_5_);
	cppVar_62321 = (0 << 5) | cppVar_62320;
	cppVar_62321 = (cppVar_62321 & cppMask_un_8_);
	cppVar_62322 = IRAM.rd(cppVar_62321);
	cppVar_62310 = cppVar_62322;
	} else {
	cppVar_62324 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62325 = (cppVar_62324 << 3) | 0;
	cppVar_62325 = (cppVar_62325 & cppMask_un_5_);
	cppVar_62326 = (0 << 5) | cppVar_62325;
	cppVar_62326 = (cppVar_62326 & cppMask_un_8_);
	cppVar_62328 = (cppVar_62326 == 128);
	if (cppVar_62328) {
	cppVar_62323 = P0;
	} else {
	cppVar_62330 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62331 = (cppVar_62330 << 3) | 0;
	cppVar_62331 = (cppVar_62331 & cppMask_un_5_);
	cppVar_62332 = (0 << 5) | cppVar_62331;
	cppVar_62332 = (cppVar_62332 & cppMask_un_8_);
	cppVar_62334 = (cppVar_62332 == 129);
	if (cppVar_62334) {
	cppVar_62329 = SP;
	} else {
	cppVar_62336 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62337 = (cppVar_62336 << 3) | 0;
	cppVar_62337 = (cppVar_62337 & cppMask_un_5_);
	cppVar_62338 = (0 << 5) | cppVar_62337;
	cppVar_62338 = (cppVar_62338 & cppMask_un_8_);
	cppVar_62340 = (cppVar_62338 == 130);
	if (cppVar_62340) {
	cppVar_62335 = DPL;
	} else {
	cppVar_62342 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62343 = (cppVar_62342 << 3) | 0;
	cppVar_62343 = (cppVar_62343 & cppMask_un_5_);
	cppVar_62344 = (0 << 5) | cppVar_62343;
	cppVar_62344 = (cppVar_62344 & cppMask_un_8_);
	cppVar_62346 = (cppVar_62344 == 131);
	if (cppVar_62346) {
	cppVar_62341 = DPH;
	} else {
	cppVar_62348 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62349 = (cppVar_62348 << 3) | 0;
	cppVar_62349 = (cppVar_62349 & cppMask_un_5_);
	cppVar_62350 = (0 << 5) | cppVar_62349;
	cppVar_62350 = (cppVar_62350 & cppMask_un_8_);
	cppVar_62352 = (cppVar_62350 == 135);
	if (cppVar_62352) {
	cppVar_62347 = PCON;
	} else {
	cppVar_62354 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62355 = (cppVar_62354 << 3) | 0;
	cppVar_62355 = (cppVar_62355 & cppMask_un_5_);
	cppVar_62356 = (0 << 5) | cppVar_62355;
	cppVar_62356 = (cppVar_62356 & cppMask_un_8_);
	cppVar_62358 = (cppVar_62356 == 136);
	if (cppVar_62358) {
	cppVar_62353 = TCON;
	} else {
	cppVar_62360 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62361 = (cppVar_62360 << 3) | 0;
	cppVar_62361 = (cppVar_62361 & cppMask_un_5_);
	cppVar_62362 = (0 << 5) | cppVar_62361;
	cppVar_62362 = (cppVar_62362 & cppMask_un_8_);
	cppVar_62364 = (cppVar_62362 == 137);
	if (cppVar_62364) {
	cppVar_62359 = TMOD;
	} else {
	cppVar_62366 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62367 = (cppVar_62366 << 3) | 0;
	cppVar_62367 = (cppVar_62367 & cppMask_un_5_);
	cppVar_62368 = (0 << 5) | cppVar_62367;
	cppVar_62368 = (cppVar_62368 & cppMask_un_8_);
	cppVar_62370 = (cppVar_62368 == 138);
	if (cppVar_62370) {
	cppVar_62365 = TL0;
	} else {
	cppVar_62372 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62373 = (cppVar_62372 << 3) | 0;
	cppVar_62373 = (cppVar_62373 & cppMask_un_5_);
	cppVar_62374 = (0 << 5) | cppVar_62373;
	cppVar_62374 = (cppVar_62374 & cppMask_un_8_);
	cppVar_62376 = (cppVar_62374 == 140);
	if (cppVar_62376) {
	cppVar_62371 = TH0;
	} else {
	cppVar_62378 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62379 = (cppVar_62378 << 3) | 0;
	cppVar_62379 = (cppVar_62379 & cppMask_un_5_);
	cppVar_62380 = (0 << 5) | cppVar_62379;
	cppVar_62380 = (cppVar_62380 & cppMask_un_8_);
	cppVar_62382 = (cppVar_62380 == 139);
	if (cppVar_62382) {
	cppVar_62377 = TL1;
	} else {
	cppVar_62384 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62385 = (cppVar_62384 << 3) | 0;
	cppVar_62385 = (cppVar_62385 & cppMask_un_5_);
	cppVar_62386 = (0 << 5) | cppVar_62385;
	cppVar_62386 = (cppVar_62386 & cppMask_un_8_);
	cppVar_62388 = (cppVar_62386 == 141);
	if (cppVar_62388) {
	cppVar_62383 = TH1;
	} else {
	cppVar_62390 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62391 = (cppVar_62390 << 3) | 0;
	cppVar_62391 = (cppVar_62391 & cppMask_un_5_);
	cppVar_62392 = (0 << 5) | cppVar_62391;
	cppVar_62392 = (cppVar_62392 & cppMask_un_8_);
	cppVar_62394 = (cppVar_62392 == 144);
	if (cppVar_62394) {
	cppVar_62389 = P1;
	} else {
	cppVar_62396 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62397 = (cppVar_62396 << 3) | 0;
	cppVar_62397 = (cppVar_62397 & cppMask_un_5_);
	cppVar_62398 = (0 << 5) | cppVar_62397;
	cppVar_62398 = (cppVar_62398 & cppMask_un_8_);
	cppVar_62400 = (cppVar_62398 == 152);
	if (cppVar_62400) {
	cppVar_62395 = SCON;
	} else {
	cppVar_62402 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62403 = (cppVar_62402 << 3) | 0;
	cppVar_62403 = (cppVar_62403 & cppMask_un_5_);
	cppVar_62404 = (0 << 5) | cppVar_62403;
	cppVar_62404 = (cppVar_62404 & cppMask_un_8_);
	cppVar_62406 = (cppVar_62404 == 153);
	if (cppVar_62406) {
	cppVar_62401 = SBUF;
	} else {
	cppVar_62408 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62409 = (cppVar_62408 << 3) | 0;
	cppVar_62409 = (cppVar_62409 & cppMask_un_5_);
	cppVar_62410 = (0 << 5) | cppVar_62409;
	cppVar_62410 = (cppVar_62410 & cppMask_un_8_);
	cppVar_62412 = (cppVar_62410 == 160);
	if (cppVar_62412) {
	cppVar_62407 = P2;
	} else {
	cppVar_62414 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62415 = (cppVar_62414 << 3) | 0;
	cppVar_62415 = (cppVar_62415 & cppMask_un_5_);
	cppVar_62416 = (0 << 5) | cppVar_62415;
	cppVar_62416 = (cppVar_62416 & cppMask_un_8_);
	cppVar_62418 = (cppVar_62416 == 168);
	if (cppVar_62418) {
	cppVar_62413 = IE;
	} else {
	cppVar_62420 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62421 = (cppVar_62420 << 3) | 0;
	cppVar_62421 = (cppVar_62421 & cppMask_un_5_);
	cppVar_62422 = (0 << 5) | cppVar_62421;
	cppVar_62422 = (cppVar_62422 & cppMask_un_8_);
	cppVar_62424 = (cppVar_62422 == 176);
	if (cppVar_62424) {
	cppVar_62419 = P3;
	} else {
	cppVar_62426 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62427 = (cppVar_62426 << 3) | 0;
	cppVar_62427 = (cppVar_62427 & cppMask_un_5_);
	cppVar_62428 = (0 << 5) | cppVar_62427;
	cppVar_62428 = (cppVar_62428 & cppMask_un_8_);
	cppVar_62430 = (cppVar_62428 == 184);
	if (cppVar_62430) {
	cppVar_62425 = IP;
	} else {
	cppVar_62432 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62433 = (cppVar_62432 << 3) | 0;
	cppVar_62433 = (cppVar_62433 & cppMask_un_5_);
	cppVar_62434 = (0 << 5) | cppVar_62433;
	cppVar_62434 = (cppVar_62434 & cppMask_un_8_);
	cppVar_62436 = (cppVar_62434 == 208);
	if (cppVar_62436) {
	cppVar_62431 = PSW;
	} else {
	cppVar_62438 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62439 = (cppVar_62438 << 3) | 0;
	cppVar_62439 = (cppVar_62439 & cppMask_un_5_);
	cppVar_62440 = (0 << 5) | cppVar_62439;
	cppVar_62440 = (cppVar_62440 & cppMask_un_8_);
	cppVar_62442 = (cppVar_62440 == 224);
	if (cppVar_62442) {
	cppVar_62437 = ACC;
	} else {
	cppVar_62444 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62445 = (cppVar_62444 << 3) | 0;
	cppVar_62445 = (cppVar_62445 & cppMask_un_5_);
	cppVar_62446 = (0 << 5) | cppVar_62445;
	cppVar_62446 = (cppVar_62446 & cppMask_un_8_);
	cppVar_62448 = (cppVar_62446 == 240);
	if (cppVar_62448) {
	cppVar_62443 = B;
	} else {
	cppVar_62443 = 0;
	}
	cppVar_62437 = cppVar_62443;
	}
	cppVar_62431 = cppVar_62437;
	}
	cppVar_62425 = cppVar_62431;
	}
	cppVar_62419 = cppVar_62425;
	}
	cppVar_62413 = cppVar_62419;
	}
	cppVar_62407 = cppVar_62413;
	}
	cppVar_62401 = cppVar_62407;
	}
	cppVar_62395 = cppVar_62401;
	}
	cppVar_62389 = cppVar_62395;
	}
	cppVar_62383 = cppVar_62389;
	}
	cppVar_62377 = cppVar_62383;
	}
	cppVar_62371 = cppVar_62377;
	}
	cppVar_62365 = cppVar_62371;
	}
	cppVar_62359 = cppVar_62365;
	}
	cppVar_62353 = cppVar_62359;
	}
	cppVar_62347 = cppVar_62353;
	}
	cppVar_62341 = cppVar_62347;
	}
	cppVar_62335 = cppVar_62341;
	}
	cppVar_62329 = cppVar_62335;
	}
	cppVar_62323 = cppVar_62329;
	}
	cppVar_62310 = cppVar_62323;
	}
	cppVar_62304 = cppVar_62310;
	} else {
	cppVar_62304 = SCON;
	}
	cppVar_62300 = cppVar_62304;
	} else {
	cppVar_62451 = ROM.rd(PC);
	cppVar_62453 = (cppVar_62451 == 135);
	if (cppVar_62453) {
	cppVar_62456 = PC + 1;
	cppVar_62456 = (cppVar_62456 & cppMask_un_16_);
	cppVar_62457 = ROM.rd(cppVar_62456);
	cppVar_62459 = (cppVar_62457 == 152);
	if (cppVar_62459) {
	cppVar_62461 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62463 = (cppVar_62461 << 3) | 1;
	cppVar_62463 = (cppVar_62463 & cppMask_un_5_);
	cppVar_62464 = (0 << 5) | cppVar_62463;
	cppVar_62464 = (cppVar_62464 & cppMask_un_8_);
	cppVar_62465 = IRAM.rd(cppVar_62464);
	cppVar_62466 = IRAM.rd(cppVar_62465);
	cppVar_62454 = cppVar_62466;
	} else {
	cppVar_62454 = SCON;
	}
	cppVar_62450 = cppVar_62454;
	} else {
	cppVar_62468 = ROM.rd(PC);
	cppVar_62470 = (cppVar_62468 == 134);
	if (cppVar_62470) {
	cppVar_62473 = PC + 1;
	cppVar_62473 = (cppVar_62473 & cppMask_un_16_);
	cppVar_62474 = ROM.rd(cppVar_62473);
	cppVar_62476 = (cppVar_62474 == 152);
	if (cppVar_62476) {
	cppVar_62478 = (PSW >> 3) & cppMask_un_2_;
	cppVar_62480 = (cppVar_62478 << 3) | 0;
	cppVar_62480 = (cppVar_62480 & cppMask_un_5_);
	cppVar_62481 = (0 << 5) | cppVar_62480;
	cppVar_62481 = (cppVar_62481 & cppMask_un_8_);
	cppVar_62482 = IRAM.rd(cppVar_62481);
	cppVar_62483 = IRAM.rd(cppVar_62482);
	cppVar_62471 = cppVar_62483;
	} else {
	cppVar_62471 = SCON;
	}
	cppVar_62467 = cppVar_62471;
	} else {
	cppVar_62485 = ROM.rd(PC);
	cppVar_62487 = (cppVar_62485 == 133);
	if (cppVar_62487) {
	cppVar_62490 = PC + 2;
	cppVar_62490 = (cppVar_62490 & cppMask_un_16_);
	cppVar_62491 = ROM.rd(cppVar_62490);
	cppVar_62493 = (cppVar_62491 == 152);
	if (cppVar_62493) {
	cppVar_62496 = PC + 1;
	cppVar_62496 = (cppVar_62496 & cppMask_un_16_);
	cppVar_62497 = ROM.rd(cppVar_62496);
	cppVar_62498 = (cppVar_62497 >> 7) & cppMask_un_1_;
	cppVar_62500 = (cppVar_62498 == 0);
	if (cppVar_62500) {
	cppVar_62501 = PC + 1;
	cppVar_62501 = (cppVar_62501 & cppMask_un_16_);
	cppVar_62502 = ROM.rd(cppVar_62501);
	cppVar_62503 = IRAM.rd(cppVar_62502);
	cppVar_62494 = cppVar_62503;
	} else {
	cppVar_62505 = PC + 1;
	cppVar_62505 = (cppVar_62505 & cppMask_un_16_);
	cppVar_62506 = ROM.rd(cppVar_62505);
	cppVar_62508 = (cppVar_62506 == 128);
	if (cppVar_62508) {
	cppVar_62504 = P0;
	} else {
	cppVar_62510 = PC + 1;
	cppVar_62510 = (cppVar_62510 & cppMask_un_16_);
	cppVar_62511 = ROM.rd(cppVar_62510);
	cppVar_62513 = (cppVar_62511 == 129);
	if (cppVar_62513) {
	cppVar_62509 = SP;
	} else {
	cppVar_62515 = PC + 1;
	cppVar_62515 = (cppVar_62515 & cppMask_un_16_);
	cppVar_62516 = ROM.rd(cppVar_62515);
	cppVar_62518 = (cppVar_62516 == 130);
	if (cppVar_62518) {
	cppVar_62514 = DPL;
	} else {
	cppVar_62520 = PC + 1;
	cppVar_62520 = (cppVar_62520 & cppMask_un_16_);
	cppVar_62521 = ROM.rd(cppVar_62520);
	cppVar_62523 = (cppVar_62521 == 131);
	if (cppVar_62523) {
	cppVar_62519 = DPH;
	} else {
	cppVar_62525 = PC + 1;
	cppVar_62525 = (cppVar_62525 & cppMask_un_16_);
	cppVar_62526 = ROM.rd(cppVar_62525);
	cppVar_62528 = (cppVar_62526 == 135);
	if (cppVar_62528) {
	cppVar_62524 = PCON;
	} else {
	cppVar_62530 = PC + 1;
	cppVar_62530 = (cppVar_62530 & cppMask_un_16_);
	cppVar_62531 = ROM.rd(cppVar_62530);
	cppVar_62533 = (cppVar_62531 == 136);
	if (cppVar_62533) {
	cppVar_62529 = TCON;
	} else {
	cppVar_62535 = PC + 1;
	cppVar_62535 = (cppVar_62535 & cppMask_un_16_);
	cppVar_62536 = ROM.rd(cppVar_62535);
	cppVar_62538 = (cppVar_62536 == 137);
	if (cppVar_62538) {
	cppVar_62534 = TMOD;
	} else {
	cppVar_62540 = PC + 1;
	cppVar_62540 = (cppVar_62540 & cppMask_un_16_);
	cppVar_62541 = ROM.rd(cppVar_62540);
	cppVar_62543 = (cppVar_62541 == 138);
	if (cppVar_62543) {
	cppVar_62539 = TL0;
	} else {
	cppVar_62545 = PC + 1;
	cppVar_62545 = (cppVar_62545 & cppMask_un_16_);
	cppVar_62546 = ROM.rd(cppVar_62545);
	cppVar_62548 = (cppVar_62546 == 140);
	if (cppVar_62548) {
	cppVar_62544 = TH0;
	} else {
	cppVar_62550 = PC + 1;
	cppVar_62550 = (cppVar_62550 & cppMask_un_16_);
	cppVar_62551 = ROM.rd(cppVar_62550);
	cppVar_62553 = (cppVar_62551 == 139);
	if (cppVar_62553) {
	cppVar_62549 = TL1;
	} else {
	cppVar_62555 = PC + 1;
	cppVar_62555 = (cppVar_62555 & cppMask_un_16_);
	cppVar_62556 = ROM.rd(cppVar_62555);
	cppVar_62558 = (cppVar_62556 == 141);
	if (cppVar_62558) {
	cppVar_62554 = TH1;
	} else {
	cppVar_62560 = PC + 1;
	cppVar_62560 = (cppVar_62560 & cppMask_un_16_);
	cppVar_62561 = ROM.rd(cppVar_62560);
	cppVar_62563 = (cppVar_62561 == 144);
	if (cppVar_62563) {
	cppVar_62559 = P1;
	} else {
	cppVar_62565 = PC + 1;
	cppVar_62565 = (cppVar_62565 & cppMask_un_16_);
	cppVar_62566 = ROM.rd(cppVar_62565);
	cppVar_62568 = (cppVar_62566 == 152);
	if (cppVar_62568) {
	cppVar_62564 = SCON;
	} else {
	cppVar_62570 = PC + 1;
	cppVar_62570 = (cppVar_62570 & cppMask_un_16_);
	cppVar_62571 = ROM.rd(cppVar_62570);
	cppVar_62573 = (cppVar_62571 == 153);
	if (cppVar_62573) {
	cppVar_62569 = SBUF;
	} else {
	cppVar_62575 = PC + 1;
	cppVar_62575 = (cppVar_62575 & cppMask_un_16_);
	cppVar_62576 = ROM.rd(cppVar_62575);
	cppVar_62578 = (cppVar_62576 == 160);
	if (cppVar_62578) {
	cppVar_62574 = P2;
	} else {
	cppVar_62580 = PC + 1;
	cppVar_62580 = (cppVar_62580 & cppMask_un_16_);
	cppVar_62581 = ROM.rd(cppVar_62580);
	cppVar_62583 = (cppVar_62581 == 168);
	if (cppVar_62583) {
	cppVar_62579 = IE;
	} else {
	cppVar_62585 = PC + 1;
	cppVar_62585 = (cppVar_62585 & cppMask_un_16_);
	cppVar_62586 = ROM.rd(cppVar_62585);
	cppVar_62588 = (cppVar_62586 == 176);
	if (cppVar_62588) {
	cppVar_62584 = P3;
	} else {
	cppVar_62590 = PC + 1;
	cppVar_62590 = (cppVar_62590 & cppMask_un_16_);
	cppVar_62591 = ROM.rd(cppVar_62590);
	cppVar_62593 = (cppVar_62591 == 184);
	if (cppVar_62593) {
	cppVar_62589 = IP;
	} else {
	cppVar_62595 = PC + 1;
	cppVar_62595 = (cppVar_62595 & cppMask_un_16_);
	cppVar_62596 = ROM.rd(cppVar_62595);
	cppVar_62598 = (cppVar_62596 == 208);
	if (cppVar_62598) {
	cppVar_62594 = PSW;
	} else {
	cppVar_62600 = PC + 1;
	cppVar_62600 = (cppVar_62600 & cppMask_un_16_);
	cppVar_62601 = ROM.rd(cppVar_62600);
	cppVar_62603 = (cppVar_62601 == 224);
	if (cppVar_62603) {
	cppVar_62599 = ACC;
	} else {
	cppVar_62605 = PC + 1;
	cppVar_62605 = (cppVar_62605 & cppMask_un_16_);
	cppVar_62606 = ROM.rd(cppVar_62605);
	cppVar_62608 = (cppVar_62606 == 240);
	if (cppVar_62608) {
	cppVar_62604 = B;
	} else {
	cppVar_62604 = 0;
	}
	cppVar_62599 = cppVar_62604;
	}
	cppVar_62594 = cppVar_62599;
	}
	cppVar_62589 = cppVar_62594;
	}
	cppVar_62584 = cppVar_62589;
	}
	cppVar_62579 = cppVar_62584;
	}
	cppVar_62574 = cppVar_62579;
	}
	cppVar_62569 = cppVar_62574;
	}
	cppVar_62564 = cppVar_62569;
	}
	cppVar_62559 = cppVar_62564;
	}
	cppVar_62554 = cppVar_62559;
	}
	cppVar_62549 = cppVar_62554;
	}
	cppVar_62544 = cppVar_62549;
	}
	cppVar_62539 = cppVar_62544;
	}
	cppVar_62534 = cppVar_62539;
	}
	cppVar_62529 = cppVar_62534;
	}
	cppVar_62524 = cppVar_62529;
	}
	cppVar_62519 = cppVar_62524;
	}
	cppVar_62514 = cppVar_62519;
	}
	cppVar_62509 = cppVar_62514;
	}
	cppVar_62504 = cppVar_62509;
	}
	cppVar_62494 = cppVar_62504;
	}
	cppVar_62488 = cppVar_62494;
	} else {
	cppVar_62488 = SCON;
	}
	cppVar_62484 = cppVar_62488;
	} else {
	cppVar_62611 = ROM.rd(PC);
	cppVar_62613 = (cppVar_62611 == 117);
	if (cppVar_62613) {
	cppVar_62616 = PC + 1;
	cppVar_62616 = (cppVar_62616 & cppMask_un_16_);
	cppVar_62617 = ROM.rd(cppVar_62616);
	cppVar_62619 = (cppVar_62617 == 152);
	if (cppVar_62619) {
	cppVar_62621 = PC + 2;
	cppVar_62621 = (cppVar_62621 & cppMask_un_16_);
	cppVar_62622 = ROM.rd(cppVar_62621);
	cppVar_62614 = cppVar_62622;
	} else {
	cppVar_62614 = SCON;
	}
	cppVar_62610 = cppVar_62614;
	} else {
	cppVar_62624 = ROM.rd(PC);
	cppVar_62626 = (cppVar_62624 == 99);
	if (cppVar_62626) {
	cppVar_62629 = PC + 1;
	cppVar_62629 = (cppVar_62629 & cppMask_un_16_);
	cppVar_62630 = ROM.rd(cppVar_62629);
	cppVar_62632 = (cppVar_62630 == 152);
	if (cppVar_62632) {
	cppVar_62634 = PC + 1;
	cppVar_62634 = (cppVar_62634 & cppMask_un_16_);
	cppVar_62635 = ROM.rd(cppVar_62634);
	cppVar_62636 = (cppVar_62635 >> 7) & cppMask_un_1_;
	cppVar_62638 = (cppVar_62636 == 0);
	if (cppVar_62638) {
	cppVar_62639 = PC + 1;
	cppVar_62639 = (cppVar_62639 & cppMask_un_16_);
	cppVar_62640 = ROM.rd(cppVar_62639);
	cppVar_62641 = IRAM.rd(cppVar_62640);
	cppVar_62633 = cppVar_62641;
	} else {
	cppVar_62643 = PC + 1;
	cppVar_62643 = (cppVar_62643 & cppMask_un_16_);
	cppVar_62644 = ROM.rd(cppVar_62643);
	cppVar_62646 = (cppVar_62644 == 128);
	if (cppVar_62646) {
	cppVar_62642 = P0;
	} else {
	cppVar_62648 = PC + 1;
	cppVar_62648 = (cppVar_62648 & cppMask_un_16_);
	cppVar_62649 = ROM.rd(cppVar_62648);
	cppVar_62651 = (cppVar_62649 == 129);
	if (cppVar_62651) {
	cppVar_62647 = SP;
	} else {
	cppVar_62653 = PC + 1;
	cppVar_62653 = (cppVar_62653 & cppMask_un_16_);
	cppVar_62654 = ROM.rd(cppVar_62653);
	cppVar_62656 = (cppVar_62654 == 130);
	if (cppVar_62656) {
	cppVar_62652 = DPL;
	} else {
	cppVar_62658 = PC + 1;
	cppVar_62658 = (cppVar_62658 & cppMask_un_16_);
	cppVar_62659 = ROM.rd(cppVar_62658);
	cppVar_62661 = (cppVar_62659 == 131);
	if (cppVar_62661) {
	cppVar_62657 = DPH;
	} else {
	cppVar_62663 = PC + 1;
	cppVar_62663 = (cppVar_62663 & cppMask_un_16_);
	cppVar_62664 = ROM.rd(cppVar_62663);
	cppVar_62666 = (cppVar_62664 == 135);
	if (cppVar_62666) {
	cppVar_62662 = PCON;
	} else {
	cppVar_62668 = PC + 1;
	cppVar_62668 = (cppVar_62668 & cppMask_un_16_);
	cppVar_62669 = ROM.rd(cppVar_62668);
	cppVar_62671 = (cppVar_62669 == 136);
	if (cppVar_62671) {
	cppVar_62667 = TCON;
	} else {
	cppVar_62673 = PC + 1;
	cppVar_62673 = (cppVar_62673 & cppMask_un_16_);
	cppVar_62674 = ROM.rd(cppVar_62673);
	cppVar_62676 = (cppVar_62674 == 137);
	if (cppVar_62676) {
	cppVar_62672 = TMOD;
	} else {
	cppVar_62678 = PC + 1;
	cppVar_62678 = (cppVar_62678 & cppMask_un_16_);
	cppVar_62679 = ROM.rd(cppVar_62678);
	cppVar_62681 = (cppVar_62679 == 138);
	if (cppVar_62681) {
	cppVar_62677 = TL0;
	} else {
	cppVar_62683 = PC + 1;
	cppVar_62683 = (cppVar_62683 & cppMask_un_16_);
	cppVar_62684 = ROM.rd(cppVar_62683);
	cppVar_62686 = (cppVar_62684 == 140);
	if (cppVar_62686) {
	cppVar_62682 = TH0;
	} else {
	cppVar_62688 = PC + 1;
	cppVar_62688 = (cppVar_62688 & cppMask_un_16_);
	cppVar_62689 = ROM.rd(cppVar_62688);
	cppVar_62691 = (cppVar_62689 == 139);
	if (cppVar_62691) {
	cppVar_62687 = TL1;
	} else {
	cppVar_62693 = PC + 1;
	cppVar_62693 = (cppVar_62693 & cppMask_un_16_);
	cppVar_62694 = ROM.rd(cppVar_62693);
	cppVar_62696 = (cppVar_62694 == 141);
	if (cppVar_62696) {
	cppVar_62692 = TH1;
	} else {
	cppVar_62698 = PC + 1;
	cppVar_62698 = (cppVar_62698 & cppMask_un_16_);
	cppVar_62699 = ROM.rd(cppVar_62698);
	cppVar_62701 = (cppVar_62699 == 144);
	if (cppVar_62701) {
	cppVar_62697 = P1;
	} else {
	cppVar_62703 = PC + 1;
	cppVar_62703 = (cppVar_62703 & cppMask_un_16_);
	cppVar_62704 = ROM.rd(cppVar_62703);
	cppVar_62706 = (cppVar_62704 == 152);
	if (cppVar_62706) {
	cppVar_62702 = SCON;
	} else {
	cppVar_62708 = PC + 1;
	cppVar_62708 = (cppVar_62708 & cppMask_un_16_);
	cppVar_62709 = ROM.rd(cppVar_62708);
	cppVar_62711 = (cppVar_62709 == 153);
	if (cppVar_62711) {
	cppVar_62707 = SBUF;
	} else {
	cppVar_62713 = PC + 1;
	cppVar_62713 = (cppVar_62713 & cppMask_un_16_);
	cppVar_62714 = ROM.rd(cppVar_62713);
	cppVar_62716 = (cppVar_62714 == 160);
	if (cppVar_62716) {
	cppVar_62712 = P2;
	} else {
	cppVar_62718 = PC + 1;
	cppVar_62718 = (cppVar_62718 & cppMask_un_16_);
	cppVar_62719 = ROM.rd(cppVar_62718);
	cppVar_62721 = (cppVar_62719 == 168);
	if (cppVar_62721) {
	cppVar_62717 = IE;
	} else {
	cppVar_62723 = PC + 1;
	cppVar_62723 = (cppVar_62723 & cppMask_un_16_);
	cppVar_62724 = ROM.rd(cppVar_62723);
	cppVar_62726 = (cppVar_62724 == 176);
	if (cppVar_62726) {
	cppVar_62722 = P3;
	} else {
	cppVar_62728 = PC + 1;
	cppVar_62728 = (cppVar_62728 & cppMask_un_16_);
	cppVar_62729 = ROM.rd(cppVar_62728);
	cppVar_62731 = (cppVar_62729 == 184);
	if (cppVar_62731) {
	cppVar_62727 = IP;
	} else {
	cppVar_62733 = PC + 1;
	cppVar_62733 = (cppVar_62733 & cppMask_un_16_);
	cppVar_62734 = ROM.rd(cppVar_62733);
	cppVar_62736 = (cppVar_62734 == 208);
	if (cppVar_62736) {
	cppVar_62732 = PSW;
	} else {
	cppVar_62738 = PC + 1;
	cppVar_62738 = (cppVar_62738 & cppMask_un_16_);
	cppVar_62739 = ROM.rd(cppVar_62738);
	cppVar_62741 = (cppVar_62739 == 224);
	if (cppVar_62741) {
	cppVar_62737 = ACC;
	} else {
	cppVar_62743 = PC + 1;
	cppVar_62743 = (cppVar_62743 & cppMask_un_16_);
	cppVar_62744 = ROM.rd(cppVar_62743);
	cppVar_62746 = (cppVar_62744 == 240);
	if (cppVar_62746) {
	cppVar_62742 = B;
	} else {
	cppVar_62742 = 0;
	}
	cppVar_62737 = cppVar_62742;
	}
	cppVar_62732 = cppVar_62737;
	}
	cppVar_62727 = cppVar_62732;
	}
	cppVar_62722 = cppVar_62727;
	}
	cppVar_62717 = cppVar_62722;
	}
	cppVar_62712 = cppVar_62717;
	}
	cppVar_62707 = cppVar_62712;
	}
	cppVar_62702 = cppVar_62707;
	}
	cppVar_62697 = cppVar_62702;
	}
	cppVar_62692 = cppVar_62697;
	}
	cppVar_62687 = cppVar_62692;
	}
	cppVar_62682 = cppVar_62687;
	}
	cppVar_62677 = cppVar_62682;
	}
	cppVar_62672 = cppVar_62677;
	}
	cppVar_62667 = cppVar_62672;
	}
	cppVar_62662 = cppVar_62667;
	}
	cppVar_62657 = cppVar_62662;
	}
	cppVar_62652 = cppVar_62657;
	}
	cppVar_62647 = cppVar_62652;
	}
	cppVar_62642 = cppVar_62647;
	}
	cppVar_62633 = cppVar_62642;
	}
	cppVar_62749 = PC + 2;
	cppVar_62749 = (cppVar_62749 & cppMask_un_16_);
	cppVar_62750 = ROM.rd(cppVar_62749);
	cppVar_62751 = cppVar_62633 ^ cppVar_62750;
	cppVar_62627 = cppVar_62751;
	} else {
	cppVar_62627 = SCON;
	}
	cppVar_62623 = cppVar_62627;
	} else {
	cppVar_62753 = ROM.rd(PC);
	cppVar_62755 = (cppVar_62753 == 98);
	if (cppVar_62755) {
	cppVar_62758 = PC + 1;
	cppVar_62758 = (cppVar_62758 & cppMask_un_16_);
	cppVar_62759 = ROM.rd(cppVar_62758);
	cppVar_62761 = (cppVar_62759 == 152);
	if (cppVar_62761) {
	cppVar_62763 = PC + 1;
	cppVar_62763 = (cppVar_62763 & cppMask_un_16_);
	cppVar_62764 = ROM.rd(cppVar_62763);
	cppVar_62765 = (cppVar_62764 >> 7) & cppMask_un_1_;
	cppVar_62767 = (cppVar_62765 == 0);
	if (cppVar_62767) {
	cppVar_62768 = PC + 1;
	cppVar_62768 = (cppVar_62768 & cppMask_un_16_);
	cppVar_62769 = ROM.rd(cppVar_62768);
	cppVar_62770 = IRAM.rd(cppVar_62769);
	cppVar_62762 = cppVar_62770;
	} else {
	cppVar_62772 = PC + 1;
	cppVar_62772 = (cppVar_62772 & cppMask_un_16_);
	cppVar_62773 = ROM.rd(cppVar_62772);
	cppVar_62775 = (cppVar_62773 == 128);
	if (cppVar_62775) {
	cppVar_62771 = P0;
	} else {
	cppVar_62777 = PC + 1;
	cppVar_62777 = (cppVar_62777 & cppMask_un_16_);
	cppVar_62778 = ROM.rd(cppVar_62777);
	cppVar_62780 = (cppVar_62778 == 129);
	if (cppVar_62780) {
	cppVar_62776 = SP;
	} else {
	cppVar_62782 = PC + 1;
	cppVar_62782 = (cppVar_62782 & cppMask_un_16_);
	cppVar_62783 = ROM.rd(cppVar_62782);
	cppVar_62785 = (cppVar_62783 == 130);
	if (cppVar_62785) {
	cppVar_62781 = DPL;
	} else {
	cppVar_62787 = PC + 1;
	cppVar_62787 = (cppVar_62787 & cppMask_un_16_);
	cppVar_62788 = ROM.rd(cppVar_62787);
	cppVar_62790 = (cppVar_62788 == 131);
	if (cppVar_62790) {
	cppVar_62786 = DPH;
	} else {
	cppVar_62792 = PC + 1;
	cppVar_62792 = (cppVar_62792 & cppMask_un_16_);
	cppVar_62793 = ROM.rd(cppVar_62792);
	cppVar_62795 = (cppVar_62793 == 135);
	if (cppVar_62795) {
	cppVar_62791 = PCON;
	} else {
	cppVar_62797 = PC + 1;
	cppVar_62797 = (cppVar_62797 & cppMask_un_16_);
	cppVar_62798 = ROM.rd(cppVar_62797);
	cppVar_62800 = (cppVar_62798 == 136);
	if (cppVar_62800) {
	cppVar_62796 = TCON;
	} else {
	cppVar_62802 = PC + 1;
	cppVar_62802 = (cppVar_62802 & cppMask_un_16_);
	cppVar_62803 = ROM.rd(cppVar_62802);
	cppVar_62805 = (cppVar_62803 == 137);
	if (cppVar_62805) {
	cppVar_62801 = TMOD;
	} else {
	cppVar_62807 = PC + 1;
	cppVar_62807 = (cppVar_62807 & cppMask_un_16_);
	cppVar_62808 = ROM.rd(cppVar_62807);
	cppVar_62810 = (cppVar_62808 == 138);
	if (cppVar_62810) {
	cppVar_62806 = TL0;
	} else {
	cppVar_62812 = PC + 1;
	cppVar_62812 = (cppVar_62812 & cppMask_un_16_);
	cppVar_62813 = ROM.rd(cppVar_62812);
	cppVar_62815 = (cppVar_62813 == 140);
	if (cppVar_62815) {
	cppVar_62811 = TH0;
	} else {
	cppVar_62817 = PC + 1;
	cppVar_62817 = (cppVar_62817 & cppMask_un_16_);
	cppVar_62818 = ROM.rd(cppVar_62817);
	cppVar_62820 = (cppVar_62818 == 139);
	if (cppVar_62820) {
	cppVar_62816 = TL1;
	} else {
	cppVar_62822 = PC + 1;
	cppVar_62822 = (cppVar_62822 & cppMask_un_16_);
	cppVar_62823 = ROM.rd(cppVar_62822);
	cppVar_62825 = (cppVar_62823 == 141);
	if (cppVar_62825) {
	cppVar_62821 = TH1;
	} else {
	cppVar_62827 = PC + 1;
	cppVar_62827 = (cppVar_62827 & cppMask_un_16_);
	cppVar_62828 = ROM.rd(cppVar_62827);
	cppVar_62830 = (cppVar_62828 == 144);
	if (cppVar_62830) {
	cppVar_62826 = P1;
	} else {
	cppVar_62832 = PC + 1;
	cppVar_62832 = (cppVar_62832 & cppMask_un_16_);
	cppVar_62833 = ROM.rd(cppVar_62832);
	cppVar_62835 = (cppVar_62833 == 152);
	if (cppVar_62835) {
	cppVar_62831 = SCON;
	} else {
	cppVar_62837 = PC + 1;
	cppVar_62837 = (cppVar_62837 & cppMask_un_16_);
	cppVar_62838 = ROM.rd(cppVar_62837);
	cppVar_62840 = (cppVar_62838 == 153);
	if (cppVar_62840) {
	cppVar_62836 = SBUF;
	} else {
	cppVar_62842 = PC + 1;
	cppVar_62842 = (cppVar_62842 & cppMask_un_16_);
	cppVar_62843 = ROM.rd(cppVar_62842);
	cppVar_62845 = (cppVar_62843 == 160);
	if (cppVar_62845) {
	cppVar_62841 = P2;
	} else {
	cppVar_62847 = PC + 1;
	cppVar_62847 = (cppVar_62847 & cppMask_un_16_);
	cppVar_62848 = ROM.rd(cppVar_62847);
	cppVar_62850 = (cppVar_62848 == 168);
	if (cppVar_62850) {
	cppVar_62846 = IE;
	} else {
	cppVar_62852 = PC + 1;
	cppVar_62852 = (cppVar_62852 & cppMask_un_16_);
	cppVar_62853 = ROM.rd(cppVar_62852);
	cppVar_62855 = (cppVar_62853 == 176);
	if (cppVar_62855) {
	cppVar_62851 = P3;
	} else {
	cppVar_62857 = PC + 1;
	cppVar_62857 = (cppVar_62857 & cppMask_un_16_);
	cppVar_62858 = ROM.rd(cppVar_62857);
	cppVar_62860 = (cppVar_62858 == 184);
	if (cppVar_62860) {
	cppVar_62856 = IP;
	} else {
	cppVar_62862 = PC + 1;
	cppVar_62862 = (cppVar_62862 & cppMask_un_16_);
	cppVar_62863 = ROM.rd(cppVar_62862);
	cppVar_62865 = (cppVar_62863 == 208);
	if (cppVar_62865) {
	cppVar_62861 = PSW;
	} else {
	cppVar_62867 = PC + 1;
	cppVar_62867 = (cppVar_62867 & cppMask_un_16_);
	cppVar_62868 = ROM.rd(cppVar_62867);
	cppVar_62870 = (cppVar_62868 == 224);
	if (cppVar_62870) {
	cppVar_62866 = ACC;
	} else {
	cppVar_62872 = PC + 1;
	cppVar_62872 = (cppVar_62872 & cppMask_un_16_);
	cppVar_62873 = ROM.rd(cppVar_62872);
	cppVar_62875 = (cppVar_62873 == 240);
	if (cppVar_62875) {
	cppVar_62871 = B;
	} else {
	cppVar_62871 = 0;
	}
	cppVar_62866 = cppVar_62871;
	}
	cppVar_62861 = cppVar_62866;
	}
	cppVar_62856 = cppVar_62861;
	}
	cppVar_62851 = cppVar_62856;
	}
	cppVar_62846 = cppVar_62851;
	}
	cppVar_62841 = cppVar_62846;
	}
	cppVar_62836 = cppVar_62841;
	}
	cppVar_62831 = cppVar_62836;
	}
	cppVar_62826 = cppVar_62831;
	}
	cppVar_62821 = cppVar_62826;
	}
	cppVar_62816 = cppVar_62821;
	}
	cppVar_62811 = cppVar_62816;
	}
	cppVar_62806 = cppVar_62811;
	}
	cppVar_62801 = cppVar_62806;
	}
	cppVar_62796 = cppVar_62801;
	}
	cppVar_62791 = cppVar_62796;
	}
	cppVar_62786 = cppVar_62791;
	}
	cppVar_62781 = cppVar_62786;
	}
	cppVar_62776 = cppVar_62781;
	}
	cppVar_62771 = cppVar_62776;
	}
	cppVar_62762 = cppVar_62771;
	}
	cppVar_62877 = cppVar_62762 ^ ACC;
	cppVar_62756 = cppVar_62877;
	} else {
	cppVar_62756 = SCON;
	}
	cppVar_62752 = cppVar_62756;
	} else {
	cppVar_62879 = ROM.rd(PC);
	cppVar_62881 = (cppVar_62879 == 83);
	if (cppVar_62881) {
	cppVar_62884 = PC + 1;
	cppVar_62884 = (cppVar_62884 & cppMask_un_16_);
	cppVar_62885 = ROM.rd(cppVar_62884);
	cppVar_62887 = (cppVar_62885 == 152);
	if (cppVar_62887) {
	cppVar_62889 = PC + 1;
	cppVar_62889 = (cppVar_62889 & cppMask_un_16_);
	cppVar_62890 = ROM.rd(cppVar_62889);
	cppVar_62891 = (cppVar_62890 >> 7) & cppMask_un_1_;
	cppVar_62893 = (cppVar_62891 == 0);
	if (cppVar_62893) {
	cppVar_62894 = PC + 1;
	cppVar_62894 = (cppVar_62894 & cppMask_un_16_);
	cppVar_62895 = ROM.rd(cppVar_62894);
	cppVar_62896 = IRAM.rd(cppVar_62895);
	cppVar_62888 = cppVar_62896;
	} else {
	cppVar_62898 = PC + 1;
	cppVar_62898 = (cppVar_62898 & cppMask_un_16_);
	cppVar_62899 = ROM.rd(cppVar_62898);
	cppVar_62901 = (cppVar_62899 == 128);
	if (cppVar_62901) {
	cppVar_62897 = P0;
	} else {
	cppVar_62903 = PC + 1;
	cppVar_62903 = (cppVar_62903 & cppMask_un_16_);
	cppVar_62904 = ROM.rd(cppVar_62903);
	cppVar_62906 = (cppVar_62904 == 129);
	if (cppVar_62906) {
	cppVar_62902 = SP;
	} else {
	cppVar_62908 = PC + 1;
	cppVar_62908 = (cppVar_62908 & cppMask_un_16_);
	cppVar_62909 = ROM.rd(cppVar_62908);
	cppVar_62911 = (cppVar_62909 == 130);
	if (cppVar_62911) {
	cppVar_62907 = DPL;
	} else {
	cppVar_62913 = PC + 1;
	cppVar_62913 = (cppVar_62913 & cppMask_un_16_);
	cppVar_62914 = ROM.rd(cppVar_62913);
	cppVar_62916 = (cppVar_62914 == 131);
	if (cppVar_62916) {
	cppVar_62912 = DPH;
	} else {
	cppVar_62918 = PC + 1;
	cppVar_62918 = (cppVar_62918 & cppMask_un_16_);
	cppVar_62919 = ROM.rd(cppVar_62918);
	cppVar_62921 = (cppVar_62919 == 135);
	if (cppVar_62921) {
	cppVar_62917 = PCON;
	} else {
	cppVar_62923 = PC + 1;
	cppVar_62923 = (cppVar_62923 & cppMask_un_16_);
	cppVar_62924 = ROM.rd(cppVar_62923);
	cppVar_62926 = (cppVar_62924 == 136);
	if (cppVar_62926) {
	cppVar_62922 = TCON;
	} else {
	cppVar_62928 = PC + 1;
	cppVar_62928 = (cppVar_62928 & cppMask_un_16_);
	cppVar_62929 = ROM.rd(cppVar_62928);
	cppVar_62931 = (cppVar_62929 == 137);
	if (cppVar_62931) {
	cppVar_62927 = TMOD;
	} else {
	cppVar_62933 = PC + 1;
	cppVar_62933 = (cppVar_62933 & cppMask_un_16_);
	cppVar_62934 = ROM.rd(cppVar_62933);
	cppVar_62936 = (cppVar_62934 == 138);
	if (cppVar_62936) {
	cppVar_62932 = TL0;
	} else {
	cppVar_62938 = PC + 1;
	cppVar_62938 = (cppVar_62938 & cppMask_un_16_);
	cppVar_62939 = ROM.rd(cppVar_62938);
	cppVar_62941 = (cppVar_62939 == 140);
	if (cppVar_62941) {
	cppVar_62937 = TH0;
	} else {
	cppVar_62943 = PC + 1;
	cppVar_62943 = (cppVar_62943 & cppMask_un_16_);
	cppVar_62944 = ROM.rd(cppVar_62943);
	cppVar_62946 = (cppVar_62944 == 139);
	if (cppVar_62946) {
	cppVar_62942 = TL1;
	} else {
	cppVar_62948 = PC + 1;
	cppVar_62948 = (cppVar_62948 & cppMask_un_16_);
	cppVar_62949 = ROM.rd(cppVar_62948);
	cppVar_62951 = (cppVar_62949 == 141);
	if (cppVar_62951) {
	cppVar_62947 = TH1;
	} else {
	cppVar_62953 = PC + 1;
	cppVar_62953 = (cppVar_62953 & cppMask_un_16_);
	cppVar_62954 = ROM.rd(cppVar_62953);
	cppVar_62956 = (cppVar_62954 == 144);
	if (cppVar_62956) {
	cppVar_62952 = P1;
	} else {
	cppVar_62958 = PC + 1;
	cppVar_62958 = (cppVar_62958 & cppMask_un_16_);
	cppVar_62959 = ROM.rd(cppVar_62958);
	cppVar_62961 = (cppVar_62959 == 152);
	if (cppVar_62961) {
	cppVar_62957 = SCON;
	} else {
	cppVar_62963 = PC + 1;
	cppVar_62963 = (cppVar_62963 & cppMask_un_16_);
	cppVar_62964 = ROM.rd(cppVar_62963);
	cppVar_62966 = (cppVar_62964 == 153);
	if (cppVar_62966) {
	cppVar_62962 = SBUF;
	} else {
	cppVar_62968 = PC + 1;
	cppVar_62968 = (cppVar_62968 & cppMask_un_16_);
	cppVar_62969 = ROM.rd(cppVar_62968);
	cppVar_62971 = (cppVar_62969 == 160);
	if (cppVar_62971) {
	cppVar_62967 = P2;
	} else {
	cppVar_62973 = PC + 1;
	cppVar_62973 = (cppVar_62973 & cppMask_un_16_);
	cppVar_62974 = ROM.rd(cppVar_62973);
	cppVar_62976 = (cppVar_62974 == 168);
	if (cppVar_62976) {
	cppVar_62972 = IE;
	} else {
	cppVar_62978 = PC + 1;
	cppVar_62978 = (cppVar_62978 & cppMask_un_16_);
	cppVar_62979 = ROM.rd(cppVar_62978);
	cppVar_62981 = (cppVar_62979 == 176);
	if (cppVar_62981) {
	cppVar_62977 = P3;
	} else {
	cppVar_62983 = PC + 1;
	cppVar_62983 = (cppVar_62983 & cppMask_un_16_);
	cppVar_62984 = ROM.rd(cppVar_62983);
	cppVar_62986 = (cppVar_62984 == 184);
	if (cppVar_62986) {
	cppVar_62982 = IP;
	} else {
	cppVar_62988 = PC + 1;
	cppVar_62988 = (cppVar_62988 & cppMask_un_16_);
	cppVar_62989 = ROM.rd(cppVar_62988);
	cppVar_62991 = (cppVar_62989 == 208);
	if (cppVar_62991) {
	cppVar_62987 = PSW;
	} else {
	cppVar_62993 = PC + 1;
	cppVar_62993 = (cppVar_62993 & cppMask_un_16_);
	cppVar_62994 = ROM.rd(cppVar_62993);
	cppVar_62996 = (cppVar_62994 == 224);
	if (cppVar_62996) {
	cppVar_62992 = ACC;
	} else {
	cppVar_62998 = PC + 1;
	cppVar_62998 = (cppVar_62998 & cppMask_un_16_);
	cppVar_62999 = ROM.rd(cppVar_62998);
	cppVar_63001 = (cppVar_62999 == 240);
	if (cppVar_63001) {
	cppVar_62997 = B;
	} else {
	cppVar_62997 = 0;
	}
	cppVar_62992 = cppVar_62997;
	}
	cppVar_62987 = cppVar_62992;
	}
	cppVar_62982 = cppVar_62987;
	}
	cppVar_62977 = cppVar_62982;
	}
	cppVar_62972 = cppVar_62977;
	}
	cppVar_62967 = cppVar_62972;
	}
	cppVar_62962 = cppVar_62967;
	}
	cppVar_62957 = cppVar_62962;
	}
	cppVar_62952 = cppVar_62957;
	}
	cppVar_62947 = cppVar_62952;
	}
	cppVar_62942 = cppVar_62947;
	}
	cppVar_62937 = cppVar_62942;
	}
	cppVar_62932 = cppVar_62937;
	}
	cppVar_62927 = cppVar_62932;
	}
	cppVar_62922 = cppVar_62927;
	}
	cppVar_62917 = cppVar_62922;
	}
	cppVar_62912 = cppVar_62917;
	}
	cppVar_62907 = cppVar_62912;
	}
	cppVar_62902 = cppVar_62907;
	}
	cppVar_62897 = cppVar_62902;
	}
	cppVar_62888 = cppVar_62897;
	}
	cppVar_63004 = PC + 2;
	cppVar_63004 = (cppVar_63004 & cppMask_un_16_);
	cppVar_63005 = ROM.rd(cppVar_63004);
	cppVar_63006 = cppVar_62888 & cppVar_63005;
	cppVar_62882 = cppVar_63006;
	} else {
	cppVar_62882 = SCON;
	}
	cppVar_62878 = cppVar_62882;
	} else {
	cppVar_63008 = ROM.rd(PC);
	cppVar_63010 = (cppVar_63008 == 82);
	if (cppVar_63010) {
	cppVar_63013 = PC + 1;
	cppVar_63013 = (cppVar_63013 & cppMask_un_16_);
	cppVar_63014 = ROM.rd(cppVar_63013);
	cppVar_63016 = (cppVar_63014 == 152);
	if (cppVar_63016) {
	cppVar_63018 = PC + 1;
	cppVar_63018 = (cppVar_63018 & cppMask_un_16_);
	cppVar_63019 = ROM.rd(cppVar_63018);
	cppVar_63020 = (cppVar_63019 >> 7) & cppMask_un_1_;
	cppVar_63022 = (cppVar_63020 == 0);
	if (cppVar_63022) {
	cppVar_63023 = PC + 1;
	cppVar_63023 = (cppVar_63023 & cppMask_un_16_);
	cppVar_63024 = ROM.rd(cppVar_63023);
	cppVar_63025 = IRAM.rd(cppVar_63024);
	cppVar_63017 = cppVar_63025;
	} else {
	cppVar_63027 = PC + 1;
	cppVar_63027 = (cppVar_63027 & cppMask_un_16_);
	cppVar_63028 = ROM.rd(cppVar_63027);
	cppVar_63030 = (cppVar_63028 == 128);
	if (cppVar_63030) {
	cppVar_63026 = P0;
	} else {
	cppVar_63032 = PC + 1;
	cppVar_63032 = (cppVar_63032 & cppMask_un_16_);
	cppVar_63033 = ROM.rd(cppVar_63032);
	cppVar_63035 = (cppVar_63033 == 129);
	if (cppVar_63035) {
	cppVar_63031 = SP;
	} else {
	cppVar_63037 = PC + 1;
	cppVar_63037 = (cppVar_63037 & cppMask_un_16_);
	cppVar_63038 = ROM.rd(cppVar_63037);
	cppVar_63040 = (cppVar_63038 == 130);
	if (cppVar_63040) {
	cppVar_63036 = DPL;
	} else {
	cppVar_63042 = PC + 1;
	cppVar_63042 = (cppVar_63042 & cppMask_un_16_);
	cppVar_63043 = ROM.rd(cppVar_63042);
	cppVar_63045 = (cppVar_63043 == 131);
	if (cppVar_63045) {
	cppVar_63041 = DPH;
	} else {
	cppVar_63047 = PC + 1;
	cppVar_63047 = (cppVar_63047 & cppMask_un_16_);
	cppVar_63048 = ROM.rd(cppVar_63047);
	cppVar_63050 = (cppVar_63048 == 135);
	if (cppVar_63050) {
	cppVar_63046 = PCON;
	} else {
	cppVar_63052 = PC + 1;
	cppVar_63052 = (cppVar_63052 & cppMask_un_16_);
	cppVar_63053 = ROM.rd(cppVar_63052);
	cppVar_63055 = (cppVar_63053 == 136);
	if (cppVar_63055) {
	cppVar_63051 = TCON;
	} else {
	cppVar_63057 = PC + 1;
	cppVar_63057 = (cppVar_63057 & cppMask_un_16_);
	cppVar_63058 = ROM.rd(cppVar_63057);
	cppVar_63060 = (cppVar_63058 == 137);
	if (cppVar_63060) {
	cppVar_63056 = TMOD;
	} else {
	cppVar_63062 = PC + 1;
	cppVar_63062 = (cppVar_63062 & cppMask_un_16_);
	cppVar_63063 = ROM.rd(cppVar_63062);
	cppVar_63065 = (cppVar_63063 == 138);
	if (cppVar_63065) {
	cppVar_63061 = TL0;
	} else {
	cppVar_63067 = PC + 1;
	cppVar_63067 = (cppVar_63067 & cppMask_un_16_);
	cppVar_63068 = ROM.rd(cppVar_63067);
	cppVar_63070 = (cppVar_63068 == 140);
	if (cppVar_63070) {
	cppVar_63066 = TH0;
	} else {
	cppVar_63072 = PC + 1;
	cppVar_63072 = (cppVar_63072 & cppMask_un_16_);
	cppVar_63073 = ROM.rd(cppVar_63072);
	cppVar_63075 = (cppVar_63073 == 139);
	if (cppVar_63075) {
	cppVar_63071 = TL1;
	} else {
	cppVar_63077 = PC + 1;
	cppVar_63077 = (cppVar_63077 & cppMask_un_16_);
	cppVar_63078 = ROM.rd(cppVar_63077);
	cppVar_63080 = (cppVar_63078 == 141);
	if (cppVar_63080) {
	cppVar_63076 = TH1;
	} else {
	cppVar_63082 = PC + 1;
	cppVar_63082 = (cppVar_63082 & cppMask_un_16_);
	cppVar_63083 = ROM.rd(cppVar_63082);
	cppVar_63085 = (cppVar_63083 == 144);
	if (cppVar_63085) {
	cppVar_63081 = P1;
	} else {
	cppVar_63087 = PC + 1;
	cppVar_63087 = (cppVar_63087 & cppMask_un_16_);
	cppVar_63088 = ROM.rd(cppVar_63087);
	cppVar_63090 = (cppVar_63088 == 152);
	if (cppVar_63090) {
	cppVar_63086 = SCON;
	} else {
	cppVar_63092 = PC + 1;
	cppVar_63092 = (cppVar_63092 & cppMask_un_16_);
	cppVar_63093 = ROM.rd(cppVar_63092);
	cppVar_63095 = (cppVar_63093 == 153);
	if (cppVar_63095) {
	cppVar_63091 = SBUF;
	} else {
	cppVar_63097 = PC + 1;
	cppVar_63097 = (cppVar_63097 & cppMask_un_16_);
	cppVar_63098 = ROM.rd(cppVar_63097);
	cppVar_63100 = (cppVar_63098 == 160);
	if (cppVar_63100) {
	cppVar_63096 = P2;
	} else {
	cppVar_63102 = PC + 1;
	cppVar_63102 = (cppVar_63102 & cppMask_un_16_);
	cppVar_63103 = ROM.rd(cppVar_63102);
	cppVar_63105 = (cppVar_63103 == 168);
	if (cppVar_63105) {
	cppVar_63101 = IE;
	} else {
	cppVar_63107 = PC + 1;
	cppVar_63107 = (cppVar_63107 & cppMask_un_16_);
	cppVar_63108 = ROM.rd(cppVar_63107);
	cppVar_63110 = (cppVar_63108 == 176);
	if (cppVar_63110) {
	cppVar_63106 = P3;
	} else {
	cppVar_63112 = PC + 1;
	cppVar_63112 = (cppVar_63112 & cppMask_un_16_);
	cppVar_63113 = ROM.rd(cppVar_63112);
	cppVar_63115 = (cppVar_63113 == 184);
	if (cppVar_63115) {
	cppVar_63111 = IP;
	} else {
	cppVar_63117 = PC + 1;
	cppVar_63117 = (cppVar_63117 & cppMask_un_16_);
	cppVar_63118 = ROM.rd(cppVar_63117);
	cppVar_63120 = (cppVar_63118 == 208);
	if (cppVar_63120) {
	cppVar_63116 = PSW;
	} else {
	cppVar_63122 = PC + 1;
	cppVar_63122 = (cppVar_63122 & cppMask_un_16_);
	cppVar_63123 = ROM.rd(cppVar_63122);
	cppVar_63125 = (cppVar_63123 == 224);
	if (cppVar_63125) {
	cppVar_63121 = ACC;
	} else {
	cppVar_63127 = PC + 1;
	cppVar_63127 = (cppVar_63127 & cppMask_un_16_);
	cppVar_63128 = ROM.rd(cppVar_63127);
	cppVar_63130 = (cppVar_63128 == 240);
	if (cppVar_63130) {
	cppVar_63126 = B;
	} else {
	cppVar_63126 = 0;
	}
	cppVar_63121 = cppVar_63126;
	}
	cppVar_63116 = cppVar_63121;
	}
	cppVar_63111 = cppVar_63116;
	}
	cppVar_63106 = cppVar_63111;
	}
	cppVar_63101 = cppVar_63106;
	}
	cppVar_63096 = cppVar_63101;
	}
	cppVar_63091 = cppVar_63096;
	}
	cppVar_63086 = cppVar_63091;
	}
	cppVar_63081 = cppVar_63086;
	}
	cppVar_63076 = cppVar_63081;
	}
	cppVar_63071 = cppVar_63076;
	}
	cppVar_63066 = cppVar_63071;
	}
	cppVar_63061 = cppVar_63066;
	}
	cppVar_63056 = cppVar_63061;
	}
	cppVar_63051 = cppVar_63056;
	}
	cppVar_63046 = cppVar_63051;
	}
	cppVar_63041 = cppVar_63046;
	}
	cppVar_63036 = cppVar_63041;
	}
	cppVar_63031 = cppVar_63036;
	}
	cppVar_63026 = cppVar_63031;
	}
	cppVar_63017 = cppVar_63026;
	}
	cppVar_63132 = cppVar_63017 & ACC;
	cppVar_63011 = cppVar_63132;
	} else {
	cppVar_63011 = SCON;
	}
	cppVar_63007 = cppVar_63011;
	} else {
	cppVar_63134 = ROM.rd(PC);
	cppVar_63136 = (cppVar_63134 == 67);
	if (cppVar_63136) {
	cppVar_63139 = PC + 1;
	cppVar_63139 = (cppVar_63139 & cppMask_un_16_);
	cppVar_63140 = ROM.rd(cppVar_63139);
	cppVar_63142 = (cppVar_63140 == 152);
	if (cppVar_63142) {
	cppVar_63144 = PC + 1;
	cppVar_63144 = (cppVar_63144 & cppMask_un_16_);
	cppVar_63145 = ROM.rd(cppVar_63144);
	cppVar_63146 = (cppVar_63145 >> 7) & cppMask_un_1_;
	cppVar_63148 = (cppVar_63146 == 0);
	if (cppVar_63148) {
	cppVar_63149 = PC + 1;
	cppVar_63149 = (cppVar_63149 & cppMask_un_16_);
	cppVar_63150 = ROM.rd(cppVar_63149);
	cppVar_63151 = IRAM.rd(cppVar_63150);
	cppVar_63143 = cppVar_63151;
	} else {
	cppVar_63153 = PC + 1;
	cppVar_63153 = (cppVar_63153 & cppMask_un_16_);
	cppVar_63154 = ROM.rd(cppVar_63153);
	cppVar_63156 = (cppVar_63154 == 128);
	if (cppVar_63156) {
	cppVar_63152 = P0;
	} else {
	cppVar_63158 = PC + 1;
	cppVar_63158 = (cppVar_63158 & cppMask_un_16_);
	cppVar_63159 = ROM.rd(cppVar_63158);
	cppVar_63161 = (cppVar_63159 == 129);
	if (cppVar_63161) {
	cppVar_63157 = SP;
	} else {
	cppVar_63163 = PC + 1;
	cppVar_63163 = (cppVar_63163 & cppMask_un_16_);
	cppVar_63164 = ROM.rd(cppVar_63163);
	cppVar_63166 = (cppVar_63164 == 130);
	if (cppVar_63166) {
	cppVar_63162 = DPL;
	} else {
	cppVar_63168 = PC + 1;
	cppVar_63168 = (cppVar_63168 & cppMask_un_16_);
	cppVar_63169 = ROM.rd(cppVar_63168);
	cppVar_63171 = (cppVar_63169 == 131);
	if (cppVar_63171) {
	cppVar_63167 = DPH;
	} else {
	cppVar_63173 = PC + 1;
	cppVar_63173 = (cppVar_63173 & cppMask_un_16_);
	cppVar_63174 = ROM.rd(cppVar_63173);
	cppVar_63176 = (cppVar_63174 == 135);
	if (cppVar_63176) {
	cppVar_63172 = PCON;
	} else {
	cppVar_63178 = PC + 1;
	cppVar_63178 = (cppVar_63178 & cppMask_un_16_);
	cppVar_63179 = ROM.rd(cppVar_63178);
	cppVar_63181 = (cppVar_63179 == 136);
	if (cppVar_63181) {
	cppVar_63177 = TCON;
	} else {
	cppVar_63183 = PC + 1;
	cppVar_63183 = (cppVar_63183 & cppMask_un_16_);
	cppVar_63184 = ROM.rd(cppVar_63183);
	cppVar_63186 = (cppVar_63184 == 137);
	if (cppVar_63186) {
	cppVar_63182 = TMOD;
	} else {
	cppVar_63188 = PC + 1;
	cppVar_63188 = (cppVar_63188 & cppMask_un_16_);
	cppVar_63189 = ROM.rd(cppVar_63188);
	cppVar_63191 = (cppVar_63189 == 138);
	if (cppVar_63191) {
	cppVar_63187 = TL0;
	} else {
	cppVar_63193 = PC + 1;
	cppVar_63193 = (cppVar_63193 & cppMask_un_16_);
	cppVar_63194 = ROM.rd(cppVar_63193);
	cppVar_63196 = (cppVar_63194 == 140);
	if (cppVar_63196) {
	cppVar_63192 = TH0;
	} else {
	cppVar_63198 = PC + 1;
	cppVar_63198 = (cppVar_63198 & cppMask_un_16_);
	cppVar_63199 = ROM.rd(cppVar_63198);
	cppVar_63201 = (cppVar_63199 == 139);
	if (cppVar_63201) {
	cppVar_63197 = TL1;
	} else {
	cppVar_63203 = PC + 1;
	cppVar_63203 = (cppVar_63203 & cppMask_un_16_);
	cppVar_63204 = ROM.rd(cppVar_63203);
	cppVar_63206 = (cppVar_63204 == 141);
	if (cppVar_63206) {
	cppVar_63202 = TH1;
	} else {
	cppVar_63208 = PC + 1;
	cppVar_63208 = (cppVar_63208 & cppMask_un_16_);
	cppVar_63209 = ROM.rd(cppVar_63208);
	cppVar_63211 = (cppVar_63209 == 144);
	if (cppVar_63211) {
	cppVar_63207 = P1;
	} else {
	cppVar_63213 = PC + 1;
	cppVar_63213 = (cppVar_63213 & cppMask_un_16_);
	cppVar_63214 = ROM.rd(cppVar_63213);
	cppVar_63216 = (cppVar_63214 == 152);
	if (cppVar_63216) {
	cppVar_63212 = SCON;
	} else {
	cppVar_63218 = PC + 1;
	cppVar_63218 = (cppVar_63218 & cppMask_un_16_);
	cppVar_63219 = ROM.rd(cppVar_63218);
	cppVar_63221 = (cppVar_63219 == 153);
	if (cppVar_63221) {
	cppVar_63217 = SBUF;
	} else {
	cppVar_63223 = PC + 1;
	cppVar_63223 = (cppVar_63223 & cppMask_un_16_);
	cppVar_63224 = ROM.rd(cppVar_63223);
	cppVar_63226 = (cppVar_63224 == 160);
	if (cppVar_63226) {
	cppVar_63222 = P2;
	} else {
	cppVar_63228 = PC + 1;
	cppVar_63228 = (cppVar_63228 & cppMask_un_16_);
	cppVar_63229 = ROM.rd(cppVar_63228);
	cppVar_63231 = (cppVar_63229 == 168);
	if (cppVar_63231) {
	cppVar_63227 = IE;
	} else {
	cppVar_63233 = PC + 1;
	cppVar_63233 = (cppVar_63233 & cppMask_un_16_);
	cppVar_63234 = ROM.rd(cppVar_63233);
	cppVar_63236 = (cppVar_63234 == 176);
	if (cppVar_63236) {
	cppVar_63232 = P3;
	} else {
	cppVar_63238 = PC + 1;
	cppVar_63238 = (cppVar_63238 & cppMask_un_16_);
	cppVar_63239 = ROM.rd(cppVar_63238);
	cppVar_63241 = (cppVar_63239 == 184);
	if (cppVar_63241) {
	cppVar_63237 = IP;
	} else {
	cppVar_63243 = PC + 1;
	cppVar_63243 = (cppVar_63243 & cppMask_un_16_);
	cppVar_63244 = ROM.rd(cppVar_63243);
	cppVar_63246 = (cppVar_63244 == 208);
	if (cppVar_63246) {
	cppVar_63242 = PSW;
	} else {
	cppVar_63248 = PC + 1;
	cppVar_63248 = (cppVar_63248 & cppMask_un_16_);
	cppVar_63249 = ROM.rd(cppVar_63248);
	cppVar_63251 = (cppVar_63249 == 224);
	if (cppVar_63251) {
	cppVar_63247 = ACC;
	} else {
	cppVar_63253 = PC + 1;
	cppVar_63253 = (cppVar_63253 & cppMask_un_16_);
	cppVar_63254 = ROM.rd(cppVar_63253);
	cppVar_63256 = (cppVar_63254 == 240);
	if (cppVar_63256) {
	cppVar_63252 = B;
	} else {
	cppVar_63252 = 0;
	}
	cppVar_63247 = cppVar_63252;
	}
	cppVar_63242 = cppVar_63247;
	}
	cppVar_63237 = cppVar_63242;
	}
	cppVar_63232 = cppVar_63237;
	}
	cppVar_63227 = cppVar_63232;
	}
	cppVar_63222 = cppVar_63227;
	}
	cppVar_63217 = cppVar_63222;
	}
	cppVar_63212 = cppVar_63217;
	}
	cppVar_63207 = cppVar_63212;
	}
	cppVar_63202 = cppVar_63207;
	}
	cppVar_63197 = cppVar_63202;
	}
	cppVar_63192 = cppVar_63197;
	}
	cppVar_63187 = cppVar_63192;
	}
	cppVar_63182 = cppVar_63187;
	}
	cppVar_63177 = cppVar_63182;
	}
	cppVar_63172 = cppVar_63177;
	}
	cppVar_63167 = cppVar_63172;
	}
	cppVar_63162 = cppVar_63167;
	}
	cppVar_63157 = cppVar_63162;
	}
	cppVar_63152 = cppVar_63157;
	}
	cppVar_63143 = cppVar_63152;
	}
	cppVar_63259 = PC + 2;
	cppVar_63259 = (cppVar_63259 & cppMask_un_16_);
	cppVar_63260 = ROM.rd(cppVar_63259);
	cppVar_63261 = cppVar_63143 | cppVar_63260;
	cppVar_63137 = cppVar_63261;
	} else {
	cppVar_63137 = SCON;
	}
	cppVar_63133 = cppVar_63137;
	} else {
	cppVar_63263 = ROM.rd(PC);
	cppVar_63265 = (cppVar_63263 == 66);
	if (cppVar_63265) {
	cppVar_63268 = PC + 1;
	cppVar_63268 = (cppVar_63268 & cppMask_un_16_);
	cppVar_63269 = ROM.rd(cppVar_63268);
	cppVar_63271 = (cppVar_63269 == 152);
	if (cppVar_63271) {
	cppVar_63273 = PC + 1;
	cppVar_63273 = (cppVar_63273 & cppMask_un_16_);
	cppVar_63274 = ROM.rd(cppVar_63273);
	cppVar_63275 = (cppVar_63274 >> 7) & cppMask_un_1_;
	cppVar_63277 = (cppVar_63275 == 0);
	if (cppVar_63277) {
	cppVar_63278 = PC + 1;
	cppVar_63278 = (cppVar_63278 & cppMask_un_16_);
	cppVar_63279 = ROM.rd(cppVar_63278);
	cppVar_63280 = IRAM.rd(cppVar_63279);
	cppVar_63272 = cppVar_63280;
	} else {
	cppVar_63282 = PC + 1;
	cppVar_63282 = (cppVar_63282 & cppMask_un_16_);
	cppVar_63283 = ROM.rd(cppVar_63282);
	cppVar_63285 = (cppVar_63283 == 128);
	if (cppVar_63285) {
	cppVar_63281 = P0;
	} else {
	cppVar_63287 = PC + 1;
	cppVar_63287 = (cppVar_63287 & cppMask_un_16_);
	cppVar_63288 = ROM.rd(cppVar_63287);
	cppVar_63290 = (cppVar_63288 == 129);
	if (cppVar_63290) {
	cppVar_63286 = SP;
	} else {
	cppVar_63292 = PC + 1;
	cppVar_63292 = (cppVar_63292 & cppMask_un_16_);
	cppVar_63293 = ROM.rd(cppVar_63292);
	cppVar_63295 = (cppVar_63293 == 130);
	if (cppVar_63295) {
	cppVar_63291 = DPL;
	} else {
	cppVar_63297 = PC + 1;
	cppVar_63297 = (cppVar_63297 & cppMask_un_16_);
	cppVar_63298 = ROM.rd(cppVar_63297);
	cppVar_63300 = (cppVar_63298 == 131);
	if (cppVar_63300) {
	cppVar_63296 = DPH;
	} else {
	cppVar_63302 = PC + 1;
	cppVar_63302 = (cppVar_63302 & cppMask_un_16_);
	cppVar_63303 = ROM.rd(cppVar_63302);
	cppVar_63305 = (cppVar_63303 == 135);
	if (cppVar_63305) {
	cppVar_63301 = PCON;
	} else {
	cppVar_63307 = PC + 1;
	cppVar_63307 = (cppVar_63307 & cppMask_un_16_);
	cppVar_63308 = ROM.rd(cppVar_63307);
	cppVar_63310 = (cppVar_63308 == 136);
	if (cppVar_63310) {
	cppVar_63306 = TCON;
	} else {
	cppVar_63312 = PC + 1;
	cppVar_63312 = (cppVar_63312 & cppMask_un_16_);
	cppVar_63313 = ROM.rd(cppVar_63312);
	cppVar_63315 = (cppVar_63313 == 137);
	if (cppVar_63315) {
	cppVar_63311 = TMOD;
	} else {
	cppVar_63317 = PC + 1;
	cppVar_63317 = (cppVar_63317 & cppMask_un_16_);
	cppVar_63318 = ROM.rd(cppVar_63317);
	cppVar_63320 = (cppVar_63318 == 138);
	if (cppVar_63320) {
	cppVar_63316 = TL0;
	} else {
	cppVar_63322 = PC + 1;
	cppVar_63322 = (cppVar_63322 & cppMask_un_16_);
	cppVar_63323 = ROM.rd(cppVar_63322);
	cppVar_63325 = (cppVar_63323 == 140);
	if (cppVar_63325) {
	cppVar_63321 = TH0;
	} else {
	cppVar_63327 = PC + 1;
	cppVar_63327 = (cppVar_63327 & cppMask_un_16_);
	cppVar_63328 = ROM.rd(cppVar_63327);
	cppVar_63330 = (cppVar_63328 == 139);
	if (cppVar_63330) {
	cppVar_63326 = TL1;
	} else {
	cppVar_63332 = PC + 1;
	cppVar_63332 = (cppVar_63332 & cppMask_un_16_);
	cppVar_63333 = ROM.rd(cppVar_63332);
	cppVar_63335 = (cppVar_63333 == 141);
	if (cppVar_63335) {
	cppVar_63331 = TH1;
	} else {
	cppVar_63337 = PC + 1;
	cppVar_63337 = (cppVar_63337 & cppMask_un_16_);
	cppVar_63338 = ROM.rd(cppVar_63337);
	cppVar_63340 = (cppVar_63338 == 144);
	if (cppVar_63340) {
	cppVar_63336 = P1;
	} else {
	cppVar_63342 = PC + 1;
	cppVar_63342 = (cppVar_63342 & cppMask_un_16_);
	cppVar_63343 = ROM.rd(cppVar_63342);
	cppVar_63345 = (cppVar_63343 == 152);
	if (cppVar_63345) {
	cppVar_63341 = SCON;
	} else {
	cppVar_63347 = PC + 1;
	cppVar_63347 = (cppVar_63347 & cppMask_un_16_);
	cppVar_63348 = ROM.rd(cppVar_63347);
	cppVar_63350 = (cppVar_63348 == 153);
	if (cppVar_63350) {
	cppVar_63346 = SBUF;
	} else {
	cppVar_63352 = PC + 1;
	cppVar_63352 = (cppVar_63352 & cppMask_un_16_);
	cppVar_63353 = ROM.rd(cppVar_63352);
	cppVar_63355 = (cppVar_63353 == 160);
	if (cppVar_63355) {
	cppVar_63351 = P2;
	} else {
	cppVar_63357 = PC + 1;
	cppVar_63357 = (cppVar_63357 & cppMask_un_16_);
	cppVar_63358 = ROM.rd(cppVar_63357);
	cppVar_63360 = (cppVar_63358 == 168);
	if (cppVar_63360) {
	cppVar_63356 = IE;
	} else {
	cppVar_63362 = PC + 1;
	cppVar_63362 = (cppVar_63362 & cppMask_un_16_);
	cppVar_63363 = ROM.rd(cppVar_63362);
	cppVar_63365 = (cppVar_63363 == 176);
	if (cppVar_63365) {
	cppVar_63361 = P3;
	} else {
	cppVar_63367 = PC + 1;
	cppVar_63367 = (cppVar_63367 & cppMask_un_16_);
	cppVar_63368 = ROM.rd(cppVar_63367);
	cppVar_63370 = (cppVar_63368 == 184);
	if (cppVar_63370) {
	cppVar_63366 = IP;
	} else {
	cppVar_63372 = PC + 1;
	cppVar_63372 = (cppVar_63372 & cppMask_un_16_);
	cppVar_63373 = ROM.rd(cppVar_63372);
	cppVar_63375 = (cppVar_63373 == 208);
	if (cppVar_63375) {
	cppVar_63371 = PSW;
	} else {
	cppVar_63377 = PC + 1;
	cppVar_63377 = (cppVar_63377 & cppMask_un_16_);
	cppVar_63378 = ROM.rd(cppVar_63377);
	cppVar_63380 = (cppVar_63378 == 224);
	if (cppVar_63380) {
	cppVar_63376 = ACC;
	} else {
	cppVar_63382 = PC + 1;
	cppVar_63382 = (cppVar_63382 & cppMask_un_16_);
	cppVar_63383 = ROM.rd(cppVar_63382);
	cppVar_63385 = (cppVar_63383 == 240);
	if (cppVar_63385) {
	cppVar_63381 = B;
	} else {
	cppVar_63381 = 0;
	}
	cppVar_63376 = cppVar_63381;
	}
	cppVar_63371 = cppVar_63376;
	}
	cppVar_63366 = cppVar_63371;
	}
	cppVar_63361 = cppVar_63366;
	}
	cppVar_63356 = cppVar_63361;
	}
	cppVar_63351 = cppVar_63356;
	}
	cppVar_63346 = cppVar_63351;
	}
	cppVar_63341 = cppVar_63346;
	}
	cppVar_63336 = cppVar_63341;
	}
	cppVar_63331 = cppVar_63336;
	}
	cppVar_63326 = cppVar_63331;
	}
	cppVar_63321 = cppVar_63326;
	}
	cppVar_63316 = cppVar_63321;
	}
	cppVar_63311 = cppVar_63316;
	}
	cppVar_63306 = cppVar_63311;
	}
	cppVar_63301 = cppVar_63306;
	}
	cppVar_63296 = cppVar_63301;
	}
	cppVar_63291 = cppVar_63296;
	}
	cppVar_63286 = cppVar_63291;
	}
	cppVar_63281 = cppVar_63286;
	}
	cppVar_63272 = cppVar_63281;
	}
	cppVar_63387 = cppVar_63272 | ACC;
	cppVar_63266 = cppVar_63387;
	} else {
	cppVar_63266 = SCON;
	}
	cppVar_63262 = cppVar_63266;
	} else {
	cppVar_63389 = ROM.rd(PC);
	cppVar_63391 = (cppVar_63389 == 213);
	cppVar_63392 = ROM.rd(PC);
	cppVar_63394 = (cppVar_63392 == 21);
	cppVar_63395 = cppVar_63391 || cppVar_63394;
	if (cppVar_63395) {
	cppVar_63398 = PC + 1;
	cppVar_63398 = (cppVar_63398 & cppMask_un_16_);
	cppVar_63399 = ROM.rd(cppVar_63398);
	cppVar_63401 = (cppVar_63399 == 152);
	if (cppVar_63401) {
	cppVar_63403 = PC + 1;
	cppVar_63403 = (cppVar_63403 & cppMask_un_16_);
	cppVar_63404 = ROM.rd(cppVar_63403);
	cppVar_63405 = (cppVar_63404 >> 7) & cppMask_un_1_;
	cppVar_63407 = (cppVar_63405 == 0);
	if (cppVar_63407) {
	cppVar_63408 = PC + 1;
	cppVar_63408 = (cppVar_63408 & cppMask_un_16_);
	cppVar_63409 = ROM.rd(cppVar_63408);
	cppVar_63410 = IRAM.rd(cppVar_63409);
	cppVar_63402 = cppVar_63410;
	} else {
	cppVar_63412 = PC + 1;
	cppVar_63412 = (cppVar_63412 & cppMask_un_16_);
	cppVar_63413 = ROM.rd(cppVar_63412);
	cppVar_63415 = (cppVar_63413 == 128);
	if (cppVar_63415) {
	cppVar_63411 = P0;
	} else {
	cppVar_63417 = PC + 1;
	cppVar_63417 = (cppVar_63417 & cppMask_un_16_);
	cppVar_63418 = ROM.rd(cppVar_63417);
	cppVar_63420 = (cppVar_63418 == 129);
	if (cppVar_63420) {
	cppVar_63416 = SP;
	} else {
	cppVar_63422 = PC + 1;
	cppVar_63422 = (cppVar_63422 & cppMask_un_16_);
	cppVar_63423 = ROM.rd(cppVar_63422);
	cppVar_63425 = (cppVar_63423 == 130);
	if (cppVar_63425) {
	cppVar_63421 = DPL;
	} else {
	cppVar_63427 = PC + 1;
	cppVar_63427 = (cppVar_63427 & cppMask_un_16_);
	cppVar_63428 = ROM.rd(cppVar_63427);
	cppVar_63430 = (cppVar_63428 == 131);
	if (cppVar_63430) {
	cppVar_63426 = DPH;
	} else {
	cppVar_63432 = PC + 1;
	cppVar_63432 = (cppVar_63432 & cppMask_un_16_);
	cppVar_63433 = ROM.rd(cppVar_63432);
	cppVar_63435 = (cppVar_63433 == 135);
	if (cppVar_63435) {
	cppVar_63431 = PCON;
	} else {
	cppVar_63437 = PC + 1;
	cppVar_63437 = (cppVar_63437 & cppMask_un_16_);
	cppVar_63438 = ROM.rd(cppVar_63437);
	cppVar_63440 = (cppVar_63438 == 136);
	if (cppVar_63440) {
	cppVar_63436 = TCON;
	} else {
	cppVar_63442 = PC + 1;
	cppVar_63442 = (cppVar_63442 & cppMask_un_16_);
	cppVar_63443 = ROM.rd(cppVar_63442);
	cppVar_63445 = (cppVar_63443 == 137);
	if (cppVar_63445) {
	cppVar_63441 = TMOD;
	} else {
	cppVar_63447 = PC + 1;
	cppVar_63447 = (cppVar_63447 & cppMask_un_16_);
	cppVar_63448 = ROM.rd(cppVar_63447);
	cppVar_63450 = (cppVar_63448 == 138);
	if (cppVar_63450) {
	cppVar_63446 = TL0;
	} else {
	cppVar_63452 = PC + 1;
	cppVar_63452 = (cppVar_63452 & cppMask_un_16_);
	cppVar_63453 = ROM.rd(cppVar_63452);
	cppVar_63455 = (cppVar_63453 == 140);
	if (cppVar_63455) {
	cppVar_63451 = TH0;
	} else {
	cppVar_63457 = PC + 1;
	cppVar_63457 = (cppVar_63457 & cppMask_un_16_);
	cppVar_63458 = ROM.rd(cppVar_63457);
	cppVar_63460 = (cppVar_63458 == 139);
	if (cppVar_63460) {
	cppVar_63456 = TL1;
	} else {
	cppVar_63462 = PC + 1;
	cppVar_63462 = (cppVar_63462 & cppMask_un_16_);
	cppVar_63463 = ROM.rd(cppVar_63462);
	cppVar_63465 = (cppVar_63463 == 141);
	if (cppVar_63465) {
	cppVar_63461 = TH1;
	} else {
	cppVar_63467 = PC + 1;
	cppVar_63467 = (cppVar_63467 & cppMask_un_16_);
	cppVar_63468 = ROM.rd(cppVar_63467);
	cppVar_63470 = (cppVar_63468 == 144);
	if (cppVar_63470) {
	cppVar_63466 = P1;
	} else {
	cppVar_63472 = PC + 1;
	cppVar_63472 = (cppVar_63472 & cppMask_un_16_);
	cppVar_63473 = ROM.rd(cppVar_63472);
	cppVar_63475 = (cppVar_63473 == 152);
	if (cppVar_63475) {
	cppVar_63471 = SCON;
	} else {
	cppVar_63477 = PC + 1;
	cppVar_63477 = (cppVar_63477 & cppMask_un_16_);
	cppVar_63478 = ROM.rd(cppVar_63477);
	cppVar_63480 = (cppVar_63478 == 153);
	if (cppVar_63480) {
	cppVar_63476 = SBUF;
	} else {
	cppVar_63482 = PC + 1;
	cppVar_63482 = (cppVar_63482 & cppMask_un_16_);
	cppVar_63483 = ROM.rd(cppVar_63482);
	cppVar_63485 = (cppVar_63483 == 160);
	if (cppVar_63485) {
	cppVar_63481 = P2;
	} else {
	cppVar_63487 = PC + 1;
	cppVar_63487 = (cppVar_63487 & cppMask_un_16_);
	cppVar_63488 = ROM.rd(cppVar_63487);
	cppVar_63490 = (cppVar_63488 == 168);
	if (cppVar_63490) {
	cppVar_63486 = IE;
	} else {
	cppVar_63492 = PC + 1;
	cppVar_63492 = (cppVar_63492 & cppMask_un_16_);
	cppVar_63493 = ROM.rd(cppVar_63492);
	cppVar_63495 = (cppVar_63493 == 176);
	if (cppVar_63495) {
	cppVar_63491 = P3;
	} else {
	cppVar_63497 = PC + 1;
	cppVar_63497 = (cppVar_63497 & cppMask_un_16_);
	cppVar_63498 = ROM.rd(cppVar_63497);
	cppVar_63500 = (cppVar_63498 == 184);
	if (cppVar_63500) {
	cppVar_63496 = IP;
	} else {
	cppVar_63502 = PC + 1;
	cppVar_63502 = (cppVar_63502 & cppMask_un_16_);
	cppVar_63503 = ROM.rd(cppVar_63502);
	cppVar_63505 = (cppVar_63503 == 208);
	if (cppVar_63505) {
	cppVar_63501 = PSW;
	} else {
	cppVar_63507 = PC + 1;
	cppVar_63507 = (cppVar_63507 & cppMask_un_16_);
	cppVar_63508 = ROM.rd(cppVar_63507);
	cppVar_63510 = (cppVar_63508 == 224);
	if (cppVar_63510) {
	cppVar_63506 = ACC;
	} else {
	cppVar_63512 = PC + 1;
	cppVar_63512 = (cppVar_63512 & cppMask_un_16_);
	cppVar_63513 = ROM.rd(cppVar_63512);
	cppVar_63515 = (cppVar_63513 == 240);
	if (cppVar_63515) {
	cppVar_63511 = B;
	} else {
	cppVar_63511 = 0;
	}
	cppVar_63506 = cppVar_63511;
	}
	cppVar_63501 = cppVar_63506;
	}
	cppVar_63496 = cppVar_63501;
	}
	cppVar_63491 = cppVar_63496;
	}
	cppVar_63486 = cppVar_63491;
	}
	cppVar_63481 = cppVar_63486;
	}
	cppVar_63476 = cppVar_63481;
	}
	cppVar_63471 = cppVar_63476;
	}
	cppVar_63466 = cppVar_63471;
	}
	cppVar_63461 = cppVar_63466;
	}
	cppVar_63456 = cppVar_63461;
	}
	cppVar_63451 = cppVar_63456;
	}
	cppVar_63446 = cppVar_63451;
	}
	cppVar_63441 = cppVar_63446;
	}
	cppVar_63436 = cppVar_63441;
	}
	cppVar_63431 = cppVar_63436;
	}
	cppVar_63426 = cppVar_63431;
	}
	cppVar_63421 = cppVar_63426;
	}
	cppVar_63416 = cppVar_63421;
	}
	cppVar_63411 = cppVar_63416;
	}
	cppVar_63402 = cppVar_63411;
	}
	cppVar_63518 = cppVar_63402 - 1;
	cppVar_63518 = (cppVar_63518 & cppMask_un_8_);
	cppVar_63396 = cppVar_63518;
	} else {
	cppVar_63396 = SCON;
	}
	cppVar_63388 = cppVar_63396;
	} else {
	cppVar_63520 = ROM.rd(PC);
	cppVar_63522 = (cppVar_63520 == 194);
	cppVar_63523 = ROM.rd(PC);
	cppVar_63525 = (cppVar_63523 == 16);
	cppVar_63526 = cppVar_63522 || cppVar_63525;
	if (cppVar_63526) {
	cppVar_63530 = PC + 1;
	cppVar_63530 = (cppVar_63530 & cppMask_un_16_);
	cppVar_63531 = ROM.rd(cppVar_63530);
	cppVar_63532 = (cppVar_63531 >> 7) & cppMask_un_1_;
	cppVar_63534 = (cppVar_63532 == 1);
	if (cppVar_63534) {
	cppVar_63535 = PC + 1;
	cppVar_63535 = (cppVar_63535 & cppMask_un_16_);
	cppVar_63536 = ROM.rd(cppVar_63535);
	cppVar_63537 = (cppVar_63536 >> 3) & cppMask_un_5_;
	cppVar_63539 = (cppVar_63537 << 3) | 0;
	cppVar_63539 = (cppVar_63539 & cppMask_un_8_);
	cppVar_63528 = cppVar_63539;
	} else {
	cppVar_63540 = PC + 1;
	cppVar_63540 = (cppVar_63540 & cppMask_un_16_);
	cppVar_63541 = ROM.rd(cppVar_63540);
	cppVar_63542 = (cppVar_63541 >> 3) & cppMask_un_5_;
	cppVar_63543 = (cppVar_63542 & cppMask_un_5_);
	cppVar_63545 = cppVar_63543 + 32;
	cppVar_63545 = (cppVar_63545 & cppMask_un_8_);
	cppVar_63528 = cppVar_63545;
	}
	cppVar_63547 = (cppVar_63528 == 152);
	if (cppVar_63547) {
	cppVar_63549 = PC + 1;
	cppVar_63549 = (cppVar_63549 & cppMask_un_16_);
	cppVar_63550 = ROM.rd(cppVar_63549);
	cppVar_63551 = (cppVar_63550 >> 0) & cppMask_un_3_;
	cppVar_63552 = (cppVar_63551 & cppMask_un_3_);
	cppVar_63553 = 1 << static_cast<unsigned>(cppVar_63552);
	cppVar_63553 = (cppVar_63553 & cppMask_un_8_);
	cppVar_63554 = ~cppVar_63553;
	cppVar_63557 = PC + 1;
	cppVar_63557 = (cppVar_63557 & cppMask_un_16_);
	cppVar_63558 = ROM.rd(cppVar_63557);
	cppVar_63559 = (cppVar_63558 >> 7) & cppMask_un_1_;
	cppVar_63560 = (cppVar_63559 == 1);
	if (cppVar_63560) {
	cppVar_63561 = PC + 1;
	cppVar_63561 = (cppVar_63561 & cppMask_un_16_);
	cppVar_63562 = ROM.rd(cppVar_63561);
	cppVar_63563 = (cppVar_63562 >> 3) & cppMask_un_5_;
	cppVar_63564 = (cppVar_63563 << 3) | 0;
	cppVar_63564 = (cppVar_63564 & cppMask_un_8_);
	cppVar_63556 = cppVar_63564;
	} else {
	cppVar_63565 = PC + 1;
	cppVar_63565 = (cppVar_63565 & cppMask_un_16_);
	cppVar_63566 = ROM.rd(cppVar_63565);
	cppVar_63567 = (cppVar_63566 >> 3) & cppMask_un_5_;
	cppVar_63568 = (cppVar_63567 & cppMask_un_5_);
	cppVar_63569 = cppVar_63568 + 32;
	cppVar_63569 = (cppVar_63569 & cppMask_un_8_);
	cppVar_63556 = cppVar_63569;
	}
	cppVar_63570 = (cppVar_63556 >> 7) & cppMask_un_1_;
	cppVar_63572 = (cppVar_63570 == 0);
	if (cppVar_63572) {
	cppVar_63574 = PC + 1;
	cppVar_63574 = (cppVar_63574 & cppMask_un_16_);
	cppVar_63575 = ROM.rd(cppVar_63574);
	cppVar_63576 = (cppVar_63575 >> 7) & cppMask_un_1_;
	cppVar_63577 = (cppVar_63576 == 1);
	if (cppVar_63577) {
	cppVar_63578 = PC + 1;
	cppVar_63578 = (cppVar_63578 & cppMask_un_16_);
	cppVar_63579 = ROM.rd(cppVar_63578);
	cppVar_63580 = (cppVar_63579 >> 3) & cppMask_un_5_;
	cppVar_63581 = (cppVar_63580 << 3) | 0;
	cppVar_63581 = (cppVar_63581 & cppMask_un_8_);
	cppVar_63573 = cppVar_63581;
	} else {
	cppVar_63582 = PC + 1;
	cppVar_63582 = (cppVar_63582 & cppMask_un_16_);
	cppVar_63583 = ROM.rd(cppVar_63582);
	cppVar_63584 = (cppVar_63583 >> 3) & cppMask_un_5_;
	cppVar_63585 = (cppVar_63584 & cppMask_un_5_);
	cppVar_63586 = cppVar_63585 + 32;
	cppVar_63586 = (cppVar_63586 & cppMask_un_8_);
	cppVar_63573 = cppVar_63586;
	}
	cppVar_63587 = IRAM.rd(cppVar_63573);
	cppVar_63555 = cppVar_63587;
	} else {
	cppVar_63590 = PC + 1;
	cppVar_63590 = (cppVar_63590 & cppMask_un_16_);
	cppVar_63591 = ROM.rd(cppVar_63590);
	cppVar_63592 = (cppVar_63591 >> 7) & cppMask_un_1_;
	cppVar_63593 = (cppVar_63592 == 1);
	if (cppVar_63593) {
	cppVar_63594 = PC + 1;
	cppVar_63594 = (cppVar_63594 & cppMask_un_16_);
	cppVar_63595 = ROM.rd(cppVar_63594);
	cppVar_63596 = (cppVar_63595 >> 3) & cppMask_un_5_;
	cppVar_63597 = (cppVar_63596 << 3) | 0;
	cppVar_63597 = (cppVar_63597 & cppMask_un_8_);
	cppVar_63589 = cppVar_63597;
	} else {
	cppVar_63598 = PC + 1;
	cppVar_63598 = (cppVar_63598 & cppMask_un_16_);
	cppVar_63599 = ROM.rd(cppVar_63598);
	cppVar_63600 = (cppVar_63599 >> 3) & cppMask_un_5_;
	cppVar_63601 = (cppVar_63600 & cppMask_un_5_);
	cppVar_63602 = cppVar_63601 + 32;
	cppVar_63602 = (cppVar_63602 & cppMask_un_8_);
	cppVar_63589 = cppVar_63602;
	}
	cppVar_63604 = (cppVar_63589 == 128);
	if (cppVar_63604) {
	cppVar_63588 = P0;
	} else {
	cppVar_63607 = PC + 1;
	cppVar_63607 = (cppVar_63607 & cppMask_un_16_);
	cppVar_63608 = ROM.rd(cppVar_63607);
	cppVar_63609 = (cppVar_63608 >> 7) & cppMask_un_1_;
	cppVar_63610 = (cppVar_63609 == 1);
	if (cppVar_63610) {
	cppVar_63611 = PC + 1;
	cppVar_63611 = (cppVar_63611 & cppMask_un_16_);
	cppVar_63612 = ROM.rd(cppVar_63611);
	cppVar_63613 = (cppVar_63612 >> 3) & cppMask_un_5_;
	cppVar_63614 = (cppVar_63613 << 3) | 0;
	cppVar_63614 = (cppVar_63614 & cppMask_un_8_);
	cppVar_63606 = cppVar_63614;
	} else {
	cppVar_63615 = PC + 1;
	cppVar_63615 = (cppVar_63615 & cppMask_un_16_);
	cppVar_63616 = ROM.rd(cppVar_63615);
	cppVar_63617 = (cppVar_63616 >> 3) & cppMask_un_5_;
	cppVar_63618 = (cppVar_63617 & cppMask_un_5_);
	cppVar_63619 = cppVar_63618 + 32;
	cppVar_63619 = (cppVar_63619 & cppMask_un_8_);
	cppVar_63606 = cppVar_63619;
	}
	cppVar_63621 = (cppVar_63606 == 129);
	if (cppVar_63621) {
	cppVar_63605 = SP;
	} else {
	cppVar_63624 = PC + 1;
	cppVar_63624 = (cppVar_63624 & cppMask_un_16_);
	cppVar_63625 = ROM.rd(cppVar_63624);
	cppVar_63626 = (cppVar_63625 >> 7) & cppMask_un_1_;
	cppVar_63627 = (cppVar_63626 == 1);
	if (cppVar_63627) {
	cppVar_63628 = PC + 1;
	cppVar_63628 = (cppVar_63628 & cppMask_un_16_);
	cppVar_63629 = ROM.rd(cppVar_63628);
	cppVar_63630 = (cppVar_63629 >> 3) & cppMask_un_5_;
	cppVar_63631 = (cppVar_63630 << 3) | 0;
	cppVar_63631 = (cppVar_63631 & cppMask_un_8_);
	cppVar_63623 = cppVar_63631;
	} else {
	cppVar_63632 = PC + 1;
	cppVar_63632 = (cppVar_63632 & cppMask_un_16_);
	cppVar_63633 = ROM.rd(cppVar_63632);
	cppVar_63634 = (cppVar_63633 >> 3) & cppMask_un_5_;
	cppVar_63635 = (cppVar_63634 & cppMask_un_5_);
	cppVar_63636 = cppVar_63635 + 32;
	cppVar_63636 = (cppVar_63636 & cppMask_un_8_);
	cppVar_63623 = cppVar_63636;
	}
	cppVar_63638 = (cppVar_63623 == 130);
	if (cppVar_63638) {
	cppVar_63622 = DPL;
	} else {
	cppVar_63641 = PC + 1;
	cppVar_63641 = (cppVar_63641 & cppMask_un_16_);
	cppVar_63642 = ROM.rd(cppVar_63641);
	cppVar_63643 = (cppVar_63642 >> 7) & cppMask_un_1_;
	cppVar_63644 = (cppVar_63643 == 1);
	if (cppVar_63644) {
	cppVar_63645 = PC + 1;
	cppVar_63645 = (cppVar_63645 & cppMask_un_16_);
	cppVar_63646 = ROM.rd(cppVar_63645);
	cppVar_63647 = (cppVar_63646 >> 3) & cppMask_un_5_;
	cppVar_63648 = (cppVar_63647 << 3) | 0;
	cppVar_63648 = (cppVar_63648 & cppMask_un_8_);
	cppVar_63640 = cppVar_63648;
	} else {
	cppVar_63649 = PC + 1;
	cppVar_63649 = (cppVar_63649 & cppMask_un_16_);
	cppVar_63650 = ROM.rd(cppVar_63649);
	cppVar_63651 = (cppVar_63650 >> 3) & cppMask_un_5_;
	cppVar_63652 = (cppVar_63651 & cppMask_un_5_);
	cppVar_63653 = cppVar_63652 + 32;
	cppVar_63653 = (cppVar_63653 & cppMask_un_8_);
	cppVar_63640 = cppVar_63653;
	}
	cppVar_63655 = (cppVar_63640 == 131);
	if (cppVar_63655) {
	cppVar_63639 = DPH;
	} else {
	cppVar_63658 = PC + 1;
	cppVar_63658 = (cppVar_63658 & cppMask_un_16_);
	cppVar_63659 = ROM.rd(cppVar_63658);
	cppVar_63660 = (cppVar_63659 >> 7) & cppMask_un_1_;
	cppVar_63661 = (cppVar_63660 == 1);
	if (cppVar_63661) {
	cppVar_63662 = PC + 1;
	cppVar_63662 = (cppVar_63662 & cppMask_un_16_);
	cppVar_63663 = ROM.rd(cppVar_63662);
	cppVar_63664 = (cppVar_63663 >> 3) & cppMask_un_5_;
	cppVar_63665 = (cppVar_63664 << 3) | 0;
	cppVar_63665 = (cppVar_63665 & cppMask_un_8_);
	cppVar_63657 = cppVar_63665;
	} else {
	cppVar_63666 = PC + 1;
	cppVar_63666 = (cppVar_63666 & cppMask_un_16_);
	cppVar_63667 = ROM.rd(cppVar_63666);
	cppVar_63668 = (cppVar_63667 >> 3) & cppMask_un_5_;
	cppVar_63669 = (cppVar_63668 & cppMask_un_5_);
	cppVar_63670 = cppVar_63669 + 32;
	cppVar_63670 = (cppVar_63670 & cppMask_un_8_);
	cppVar_63657 = cppVar_63670;
	}
	cppVar_63672 = (cppVar_63657 == 135);
	if (cppVar_63672) {
	cppVar_63656 = PCON;
	} else {
	cppVar_63675 = PC + 1;
	cppVar_63675 = (cppVar_63675 & cppMask_un_16_);
	cppVar_63676 = ROM.rd(cppVar_63675);
	cppVar_63677 = (cppVar_63676 >> 7) & cppMask_un_1_;
	cppVar_63678 = (cppVar_63677 == 1);
	if (cppVar_63678) {
	cppVar_63679 = PC + 1;
	cppVar_63679 = (cppVar_63679 & cppMask_un_16_);
	cppVar_63680 = ROM.rd(cppVar_63679);
	cppVar_63681 = (cppVar_63680 >> 3) & cppMask_un_5_;
	cppVar_63682 = (cppVar_63681 << 3) | 0;
	cppVar_63682 = (cppVar_63682 & cppMask_un_8_);
	cppVar_63674 = cppVar_63682;
	} else {
	cppVar_63683 = PC + 1;
	cppVar_63683 = (cppVar_63683 & cppMask_un_16_);
	cppVar_63684 = ROM.rd(cppVar_63683);
	cppVar_63685 = (cppVar_63684 >> 3) & cppMask_un_5_;
	cppVar_63686 = (cppVar_63685 & cppMask_un_5_);
	cppVar_63687 = cppVar_63686 + 32;
	cppVar_63687 = (cppVar_63687 & cppMask_un_8_);
	cppVar_63674 = cppVar_63687;
	}
	cppVar_63689 = (cppVar_63674 == 136);
	if (cppVar_63689) {
	cppVar_63673 = TCON;
	} else {
	cppVar_63692 = PC + 1;
	cppVar_63692 = (cppVar_63692 & cppMask_un_16_);
	cppVar_63693 = ROM.rd(cppVar_63692);
	cppVar_63694 = (cppVar_63693 >> 7) & cppMask_un_1_;
	cppVar_63695 = (cppVar_63694 == 1);
	if (cppVar_63695) {
	cppVar_63696 = PC + 1;
	cppVar_63696 = (cppVar_63696 & cppMask_un_16_);
	cppVar_63697 = ROM.rd(cppVar_63696);
	cppVar_63698 = (cppVar_63697 >> 3) & cppMask_un_5_;
	cppVar_63699 = (cppVar_63698 << 3) | 0;
	cppVar_63699 = (cppVar_63699 & cppMask_un_8_);
	cppVar_63691 = cppVar_63699;
	} else {
	cppVar_63700 = PC + 1;
	cppVar_63700 = (cppVar_63700 & cppMask_un_16_);
	cppVar_63701 = ROM.rd(cppVar_63700);
	cppVar_63702 = (cppVar_63701 >> 3) & cppMask_un_5_;
	cppVar_63703 = (cppVar_63702 & cppMask_un_5_);
	cppVar_63704 = cppVar_63703 + 32;
	cppVar_63704 = (cppVar_63704 & cppMask_un_8_);
	cppVar_63691 = cppVar_63704;
	}
	cppVar_63706 = (cppVar_63691 == 137);
	if (cppVar_63706) {
	cppVar_63690 = TMOD;
	} else {
	cppVar_63709 = PC + 1;
	cppVar_63709 = (cppVar_63709 & cppMask_un_16_);
	cppVar_63710 = ROM.rd(cppVar_63709);
	cppVar_63711 = (cppVar_63710 >> 7) & cppMask_un_1_;
	cppVar_63712 = (cppVar_63711 == 1);
	if (cppVar_63712) {
	cppVar_63713 = PC + 1;
	cppVar_63713 = (cppVar_63713 & cppMask_un_16_);
	cppVar_63714 = ROM.rd(cppVar_63713);
	cppVar_63715 = (cppVar_63714 >> 3) & cppMask_un_5_;
	cppVar_63716 = (cppVar_63715 << 3) | 0;
	cppVar_63716 = (cppVar_63716 & cppMask_un_8_);
	cppVar_63708 = cppVar_63716;
	} else {
	cppVar_63717 = PC + 1;
	cppVar_63717 = (cppVar_63717 & cppMask_un_16_);
	cppVar_63718 = ROM.rd(cppVar_63717);
	cppVar_63719 = (cppVar_63718 >> 3) & cppMask_un_5_;
	cppVar_63720 = (cppVar_63719 & cppMask_un_5_);
	cppVar_63721 = cppVar_63720 + 32;
	cppVar_63721 = (cppVar_63721 & cppMask_un_8_);
	cppVar_63708 = cppVar_63721;
	}
	cppVar_63723 = (cppVar_63708 == 138);
	if (cppVar_63723) {
	cppVar_63707 = TL0;
	} else {
	cppVar_63726 = PC + 1;
	cppVar_63726 = (cppVar_63726 & cppMask_un_16_);
	cppVar_63727 = ROM.rd(cppVar_63726);
	cppVar_63728 = (cppVar_63727 >> 7) & cppMask_un_1_;
	cppVar_63729 = (cppVar_63728 == 1);
	if (cppVar_63729) {
	cppVar_63730 = PC + 1;
	cppVar_63730 = (cppVar_63730 & cppMask_un_16_);
	cppVar_63731 = ROM.rd(cppVar_63730);
	cppVar_63732 = (cppVar_63731 >> 3) & cppMask_un_5_;
	cppVar_63733 = (cppVar_63732 << 3) | 0;
	cppVar_63733 = (cppVar_63733 & cppMask_un_8_);
	cppVar_63725 = cppVar_63733;
	} else {
	cppVar_63734 = PC + 1;
	cppVar_63734 = (cppVar_63734 & cppMask_un_16_);
	cppVar_63735 = ROM.rd(cppVar_63734);
	cppVar_63736 = (cppVar_63735 >> 3) & cppMask_un_5_;
	cppVar_63737 = (cppVar_63736 & cppMask_un_5_);
	cppVar_63738 = cppVar_63737 + 32;
	cppVar_63738 = (cppVar_63738 & cppMask_un_8_);
	cppVar_63725 = cppVar_63738;
	}
	cppVar_63740 = (cppVar_63725 == 140);
	if (cppVar_63740) {
	cppVar_63724 = TH0;
	} else {
	cppVar_63743 = PC + 1;
	cppVar_63743 = (cppVar_63743 & cppMask_un_16_);
	cppVar_63744 = ROM.rd(cppVar_63743);
	cppVar_63745 = (cppVar_63744 >> 7) & cppMask_un_1_;
	cppVar_63746 = (cppVar_63745 == 1);
	if (cppVar_63746) {
	cppVar_63747 = PC + 1;
	cppVar_63747 = (cppVar_63747 & cppMask_un_16_);
	cppVar_63748 = ROM.rd(cppVar_63747);
	cppVar_63749 = (cppVar_63748 >> 3) & cppMask_un_5_;
	cppVar_63750 = (cppVar_63749 << 3) | 0;
	cppVar_63750 = (cppVar_63750 & cppMask_un_8_);
	cppVar_63742 = cppVar_63750;
	} else {
	cppVar_63751 = PC + 1;
	cppVar_63751 = (cppVar_63751 & cppMask_un_16_);
	cppVar_63752 = ROM.rd(cppVar_63751);
	cppVar_63753 = (cppVar_63752 >> 3) & cppMask_un_5_;
	cppVar_63754 = (cppVar_63753 & cppMask_un_5_);
	cppVar_63755 = cppVar_63754 + 32;
	cppVar_63755 = (cppVar_63755 & cppMask_un_8_);
	cppVar_63742 = cppVar_63755;
	}
	cppVar_63757 = (cppVar_63742 == 139);
	if (cppVar_63757) {
	cppVar_63741 = TL1;
	} else {
	cppVar_63760 = PC + 1;
	cppVar_63760 = (cppVar_63760 & cppMask_un_16_);
	cppVar_63761 = ROM.rd(cppVar_63760);
	cppVar_63762 = (cppVar_63761 >> 7) & cppMask_un_1_;
	cppVar_63763 = (cppVar_63762 == 1);
	if (cppVar_63763) {
	cppVar_63764 = PC + 1;
	cppVar_63764 = (cppVar_63764 & cppMask_un_16_);
	cppVar_63765 = ROM.rd(cppVar_63764);
	cppVar_63766 = (cppVar_63765 >> 3) & cppMask_un_5_;
	cppVar_63767 = (cppVar_63766 << 3) | 0;
	cppVar_63767 = (cppVar_63767 & cppMask_un_8_);
	cppVar_63759 = cppVar_63767;
	} else {
	cppVar_63768 = PC + 1;
	cppVar_63768 = (cppVar_63768 & cppMask_un_16_);
	cppVar_63769 = ROM.rd(cppVar_63768);
	cppVar_63770 = (cppVar_63769 >> 3) & cppMask_un_5_;
	cppVar_63771 = (cppVar_63770 & cppMask_un_5_);
	cppVar_63772 = cppVar_63771 + 32;
	cppVar_63772 = (cppVar_63772 & cppMask_un_8_);
	cppVar_63759 = cppVar_63772;
	}
	cppVar_63774 = (cppVar_63759 == 141);
	if (cppVar_63774) {
	cppVar_63758 = TH1;
	} else {
	cppVar_63777 = PC + 1;
	cppVar_63777 = (cppVar_63777 & cppMask_un_16_);
	cppVar_63778 = ROM.rd(cppVar_63777);
	cppVar_63779 = (cppVar_63778 >> 7) & cppMask_un_1_;
	cppVar_63780 = (cppVar_63779 == 1);
	if (cppVar_63780) {
	cppVar_63781 = PC + 1;
	cppVar_63781 = (cppVar_63781 & cppMask_un_16_);
	cppVar_63782 = ROM.rd(cppVar_63781);
	cppVar_63783 = (cppVar_63782 >> 3) & cppMask_un_5_;
	cppVar_63784 = (cppVar_63783 << 3) | 0;
	cppVar_63784 = (cppVar_63784 & cppMask_un_8_);
	cppVar_63776 = cppVar_63784;
	} else {
	cppVar_63785 = PC + 1;
	cppVar_63785 = (cppVar_63785 & cppMask_un_16_);
	cppVar_63786 = ROM.rd(cppVar_63785);
	cppVar_63787 = (cppVar_63786 >> 3) & cppMask_un_5_;
	cppVar_63788 = (cppVar_63787 & cppMask_un_5_);
	cppVar_63789 = cppVar_63788 + 32;
	cppVar_63789 = (cppVar_63789 & cppMask_un_8_);
	cppVar_63776 = cppVar_63789;
	}
	cppVar_63791 = (cppVar_63776 == 144);
	if (cppVar_63791) {
	cppVar_63775 = P1;
	} else {
	cppVar_63794 = PC + 1;
	cppVar_63794 = (cppVar_63794 & cppMask_un_16_);
	cppVar_63795 = ROM.rd(cppVar_63794);
	cppVar_63796 = (cppVar_63795 >> 7) & cppMask_un_1_;
	cppVar_63797 = (cppVar_63796 == 1);
	if (cppVar_63797) {
	cppVar_63798 = PC + 1;
	cppVar_63798 = (cppVar_63798 & cppMask_un_16_);
	cppVar_63799 = ROM.rd(cppVar_63798);
	cppVar_63800 = (cppVar_63799 >> 3) & cppMask_un_5_;
	cppVar_63801 = (cppVar_63800 << 3) | 0;
	cppVar_63801 = (cppVar_63801 & cppMask_un_8_);
	cppVar_63793 = cppVar_63801;
	} else {
	cppVar_63802 = PC + 1;
	cppVar_63802 = (cppVar_63802 & cppMask_un_16_);
	cppVar_63803 = ROM.rd(cppVar_63802);
	cppVar_63804 = (cppVar_63803 >> 3) & cppMask_un_5_;
	cppVar_63805 = (cppVar_63804 & cppMask_un_5_);
	cppVar_63806 = cppVar_63805 + 32;
	cppVar_63806 = (cppVar_63806 & cppMask_un_8_);
	cppVar_63793 = cppVar_63806;
	}
	cppVar_63808 = (cppVar_63793 == 152);
	if (cppVar_63808) {
	cppVar_63792 = SCON;
	} else {
	cppVar_63811 = PC + 1;
	cppVar_63811 = (cppVar_63811 & cppMask_un_16_);
	cppVar_63812 = ROM.rd(cppVar_63811);
	cppVar_63813 = (cppVar_63812 >> 7) & cppMask_un_1_;
	cppVar_63814 = (cppVar_63813 == 1);
	if (cppVar_63814) {
	cppVar_63815 = PC + 1;
	cppVar_63815 = (cppVar_63815 & cppMask_un_16_);
	cppVar_63816 = ROM.rd(cppVar_63815);
	cppVar_63817 = (cppVar_63816 >> 3) & cppMask_un_5_;
	cppVar_63818 = (cppVar_63817 << 3) | 0;
	cppVar_63818 = (cppVar_63818 & cppMask_un_8_);
	cppVar_63810 = cppVar_63818;
	} else {
	cppVar_63819 = PC + 1;
	cppVar_63819 = (cppVar_63819 & cppMask_un_16_);
	cppVar_63820 = ROM.rd(cppVar_63819);
	cppVar_63821 = (cppVar_63820 >> 3) & cppMask_un_5_;
	cppVar_63822 = (cppVar_63821 & cppMask_un_5_);
	cppVar_63823 = cppVar_63822 + 32;
	cppVar_63823 = (cppVar_63823 & cppMask_un_8_);
	cppVar_63810 = cppVar_63823;
	}
	cppVar_63825 = (cppVar_63810 == 153);
	if (cppVar_63825) {
	cppVar_63809 = SBUF;
	} else {
	cppVar_63828 = PC + 1;
	cppVar_63828 = (cppVar_63828 & cppMask_un_16_);
	cppVar_63829 = ROM.rd(cppVar_63828);
	cppVar_63830 = (cppVar_63829 >> 7) & cppMask_un_1_;
	cppVar_63831 = (cppVar_63830 == 1);
	if (cppVar_63831) {
	cppVar_63832 = PC + 1;
	cppVar_63832 = (cppVar_63832 & cppMask_un_16_);
	cppVar_63833 = ROM.rd(cppVar_63832);
	cppVar_63834 = (cppVar_63833 >> 3) & cppMask_un_5_;
	cppVar_63835 = (cppVar_63834 << 3) | 0;
	cppVar_63835 = (cppVar_63835 & cppMask_un_8_);
	cppVar_63827 = cppVar_63835;
	} else {
	cppVar_63836 = PC + 1;
	cppVar_63836 = (cppVar_63836 & cppMask_un_16_);
	cppVar_63837 = ROM.rd(cppVar_63836);
	cppVar_63838 = (cppVar_63837 >> 3) & cppMask_un_5_;
	cppVar_63839 = (cppVar_63838 & cppMask_un_5_);
	cppVar_63840 = cppVar_63839 + 32;
	cppVar_63840 = (cppVar_63840 & cppMask_un_8_);
	cppVar_63827 = cppVar_63840;
	}
	cppVar_63842 = (cppVar_63827 == 160);
	if (cppVar_63842) {
	cppVar_63826 = P2;
	} else {
	cppVar_63845 = PC + 1;
	cppVar_63845 = (cppVar_63845 & cppMask_un_16_);
	cppVar_63846 = ROM.rd(cppVar_63845);
	cppVar_63847 = (cppVar_63846 >> 7) & cppMask_un_1_;
	cppVar_63848 = (cppVar_63847 == 1);
	if (cppVar_63848) {
	cppVar_63849 = PC + 1;
	cppVar_63849 = (cppVar_63849 & cppMask_un_16_);
	cppVar_63850 = ROM.rd(cppVar_63849);
	cppVar_63851 = (cppVar_63850 >> 3) & cppMask_un_5_;
	cppVar_63852 = (cppVar_63851 << 3) | 0;
	cppVar_63852 = (cppVar_63852 & cppMask_un_8_);
	cppVar_63844 = cppVar_63852;
	} else {
	cppVar_63853 = PC + 1;
	cppVar_63853 = (cppVar_63853 & cppMask_un_16_);
	cppVar_63854 = ROM.rd(cppVar_63853);
	cppVar_63855 = (cppVar_63854 >> 3) & cppMask_un_5_;
	cppVar_63856 = (cppVar_63855 & cppMask_un_5_);
	cppVar_63857 = cppVar_63856 + 32;
	cppVar_63857 = (cppVar_63857 & cppMask_un_8_);
	cppVar_63844 = cppVar_63857;
	}
	cppVar_63859 = (cppVar_63844 == 168);
	if (cppVar_63859) {
	cppVar_63843 = IE;
	} else {
	cppVar_63862 = PC + 1;
	cppVar_63862 = (cppVar_63862 & cppMask_un_16_);
	cppVar_63863 = ROM.rd(cppVar_63862);
	cppVar_63864 = (cppVar_63863 >> 7) & cppMask_un_1_;
	cppVar_63865 = (cppVar_63864 == 1);
	if (cppVar_63865) {
	cppVar_63866 = PC + 1;
	cppVar_63866 = (cppVar_63866 & cppMask_un_16_);
	cppVar_63867 = ROM.rd(cppVar_63866);
	cppVar_63868 = (cppVar_63867 >> 3) & cppMask_un_5_;
	cppVar_63869 = (cppVar_63868 << 3) | 0;
	cppVar_63869 = (cppVar_63869 & cppMask_un_8_);
	cppVar_63861 = cppVar_63869;
	} else {
	cppVar_63870 = PC + 1;
	cppVar_63870 = (cppVar_63870 & cppMask_un_16_);
	cppVar_63871 = ROM.rd(cppVar_63870);
	cppVar_63872 = (cppVar_63871 >> 3) & cppMask_un_5_;
	cppVar_63873 = (cppVar_63872 & cppMask_un_5_);
	cppVar_63874 = cppVar_63873 + 32;
	cppVar_63874 = (cppVar_63874 & cppMask_un_8_);
	cppVar_63861 = cppVar_63874;
	}
	cppVar_63876 = (cppVar_63861 == 176);
	if (cppVar_63876) {
	cppVar_63860 = P3;
	} else {
	cppVar_63879 = PC + 1;
	cppVar_63879 = (cppVar_63879 & cppMask_un_16_);
	cppVar_63880 = ROM.rd(cppVar_63879);
	cppVar_63881 = (cppVar_63880 >> 7) & cppMask_un_1_;
	cppVar_63882 = (cppVar_63881 == 1);
	if (cppVar_63882) {
	cppVar_63883 = PC + 1;
	cppVar_63883 = (cppVar_63883 & cppMask_un_16_);
	cppVar_63884 = ROM.rd(cppVar_63883);
	cppVar_63885 = (cppVar_63884 >> 3) & cppMask_un_5_;
	cppVar_63886 = (cppVar_63885 << 3) | 0;
	cppVar_63886 = (cppVar_63886 & cppMask_un_8_);
	cppVar_63878 = cppVar_63886;
	} else {
	cppVar_63887 = PC + 1;
	cppVar_63887 = (cppVar_63887 & cppMask_un_16_);
	cppVar_63888 = ROM.rd(cppVar_63887);
	cppVar_63889 = (cppVar_63888 >> 3) & cppMask_un_5_;
	cppVar_63890 = (cppVar_63889 & cppMask_un_5_);
	cppVar_63891 = cppVar_63890 + 32;
	cppVar_63891 = (cppVar_63891 & cppMask_un_8_);
	cppVar_63878 = cppVar_63891;
	}
	cppVar_63893 = (cppVar_63878 == 184);
	if (cppVar_63893) {
	cppVar_63877 = IP;
	} else {
	cppVar_63896 = PC + 1;
	cppVar_63896 = (cppVar_63896 & cppMask_un_16_);
	cppVar_63897 = ROM.rd(cppVar_63896);
	cppVar_63898 = (cppVar_63897 >> 7) & cppMask_un_1_;
	cppVar_63899 = (cppVar_63898 == 1);
	if (cppVar_63899) {
	cppVar_63900 = PC + 1;
	cppVar_63900 = (cppVar_63900 & cppMask_un_16_);
	cppVar_63901 = ROM.rd(cppVar_63900);
	cppVar_63902 = (cppVar_63901 >> 3) & cppMask_un_5_;
	cppVar_63903 = (cppVar_63902 << 3) | 0;
	cppVar_63903 = (cppVar_63903 & cppMask_un_8_);
	cppVar_63895 = cppVar_63903;
	} else {
	cppVar_63904 = PC + 1;
	cppVar_63904 = (cppVar_63904 & cppMask_un_16_);
	cppVar_63905 = ROM.rd(cppVar_63904);
	cppVar_63906 = (cppVar_63905 >> 3) & cppMask_un_5_;
	cppVar_63907 = (cppVar_63906 & cppMask_un_5_);
	cppVar_63908 = cppVar_63907 + 32;
	cppVar_63908 = (cppVar_63908 & cppMask_un_8_);
	cppVar_63895 = cppVar_63908;
	}
	cppVar_63910 = (cppVar_63895 == 208);
	if (cppVar_63910) {
	cppVar_63894 = PSW;
	} else {
	cppVar_63913 = PC + 1;
	cppVar_63913 = (cppVar_63913 & cppMask_un_16_);
	cppVar_63914 = ROM.rd(cppVar_63913);
	cppVar_63915 = (cppVar_63914 >> 7) & cppMask_un_1_;
	cppVar_63916 = (cppVar_63915 == 1);
	if (cppVar_63916) {
	cppVar_63917 = PC + 1;
	cppVar_63917 = (cppVar_63917 & cppMask_un_16_);
	cppVar_63918 = ROM.rd(cppVar_63917);
	cppVar_63919 = (cppVar_63918 >> 3) & cppMask_un_5_;
	cppVar_63920 = (cppVar_63919 << 3) | 0;
	cppVar_63920 = (cppVar_63920 & cppMask_un_8_);
	cppVar_63912 = cppVar_63920;
	} else {
	cppVar_63921 = PC + 1;
	cppVar_63921 = (cppVar_63921 & cppMask_un_16_);
	cppVar_63922 = ROM.rd(cppVar_63921);
	cppVar_63923 = (cppVar_63922 >> 3) & cppMask_un_5_;
	cppVar_63924 = (cppVar_63923 & cppMask_un_5_);
	cppVar_63925 = cppVar_63924 + 32;
	cppVar_63925 = (cppVar_63925 & cppMask_un_8_);
	cppVar_63912 = cppVar_63925;
	}
	cppVar_63927 = (cppVar_63912 == 224);
	if (cppVar_63927) {
	cppVar_63911 = ACC;
	} else {
	cppVar_63930 = PC + 1;
	cppVar_63930 = (cppVar_63930 & cppMask_un_16_);
	cppVar_63931 = ROM.rd(cppVar_63930);
	cppVar_63932 = (cppVar_63931 >> 7) & cppMask_un_1_;
	cppVar_63933 = (cppVar_63932 == 1);
	if (cppVar_63933) {
	cppVar_63934 = PC + 1;
	cppVar_63934 = (cppVar_63934 & cppMask_un_16_);
	cppVar_63935 = ROM.rd(cppVar_63934);
	cppVar_63936 = (cppVar_63935 >> 3) & cppMask_un_5_;
	cppVar_63937 = (cppVar_63936 << 3) | 0;
	cppVar_63937 = (cppVar_63937 & cppMask_un_8_);
	cppVar_63929 = cppVar_63937;
	} else {
	cppVar_63938 = PC + 1;
	cppVar_63938 = (cppVar_63938 & cppMask_un_16_);
	cppVar_63939 = ROM.rd(cppVar_63938);
	cppVar_63940 = (cppVar_63939 >> 3) & cppMask_un_5_;
	cppVar_63941 = (cppVar_63940 & cppMask_un_5_);
	cppVar_63942 = cppVar_63941 + 32;
	cppVar_63942 = (cppVar_63942 & cppMask_un_8_);
	cppVar_63929 = cppVar_63942;
	}
	cppVar_63944 = (cppVar_63929 == 240);
	if (cppVar_63944) {
	cppVar_63928 = B;
	} else {
	cppVar_63928 = 0;
	}
	cppVar_63911 = cppVar_63928;
	}
	cppVar_63894 = cppVar_63911;
	}
	cppVar_63877 = cppVar_63894;
	}
	cppVar_63860 = cppVar_63877;
	}
	cppVar_63843 = cppVar_63860;
	}
	cppVar_63826 = cppVar_63843;
	}
	cppVar_63809 = cppVar_63826;
	}
	cppVar_63792 = cppVar_63809;
	}
	cppVar_63775 = cppVar_63792;
	}
	cppVar_63758 = cppVar_63775;
	}
	cppVar_63741 = cppVar_63758;
	}
	cppVar_63724 = cppVar_63741;
	}
	cppVar_63707 = cppVar_63724;
	}
	cppVar_63690 = cppVar_63707;
	}
	cppVar_63673 = cppVar_63690;
	}
	cppVar_63656 = cppVar_63673;
	}
	cppVar_63639 = cppVar_63656;
	}
	cppVar_63622 = cppVar_63639;
	}
	cppVar_63605 = cppVar_63622;
	}
	cppVar_63588 = cppVar_63605;
	}
	cppVar_63555 = cppVar_63588;
	}
	cppVar_63946 = cppVar_63554 & cppVar_63555;
	cppVar_63948 = 0;
	cppVar_63949 = PC + 1;
	cppVar_63949 = (cppVar_63949 & cppMask_un_16_);
	cppVar_63950 = ROM.rd(cppVar_63949);
	cppVar_63951 = (cppVar_63950 >> 0) & cppMask_un_3_;
	cppVar_63952 = (cppVar_63951 & cppMask_un_3_);
	cppVar_63953 = cppVar_63948 << static_cast<unsigned>(cppVar_63952);
	cppVar_63953 = (cppVar_63953 & cppMask_un_8_);
	cppVar_63954 = cppVar_63946 | cppVar_63953;
	cppVar_63527 = cppVar_63954;
	} else {
	cppVar_63527 = SCON;
	}
	cppVar_63519 = cppVar_63527;
	} else {
	cppVar_63956 = ROM.rd(PC);
	cppVar_63958 = (cppVar_63956 == 5);
	if (cppVar_63958) {
	cppVar_63961 = PC + 1;
	cppVar_63961 = (cppVar_63961 & cppMask_un_16_);
	cppVar_63962 = ROM.rd(cppVar_63961);
	cppVar_63964 = (cppVar_63962 == 152);
	if (cppVar_63964) {
	cppVar_63966 = PC + 1;
	cppVar_63966 = (cppVar_63966 & cppMask_un_16_);
	cppVar_63967 = ROM.rd(cppVar_63966);
	cppVar_63968 = (cppVar_63967 >> 7) & cppMask_un_1_;
	cppVar_63970 = (cppVar_63968 == 0);
	if (cppVar_63970) {
	cppVar_63971 = PC + 1;
	cppVar_63971 = (cppVar_63971 & cppMask_un_16_);
	cppVar_63972 = ROM.rd(cppVar_63971);
	cppVar_63973 = IRAM.rd(cppVar_63972);
	cppVar_63965 = cppVar_63973;
	} else {
	cppVar_63975 = PC + 1;
	cppVar_63975 = (cppVar_63975 & cppMask_un_16_);
	cppVar_63976 = ROM.rd(cppVar_63975);
	cppVar_63978 = (cppVar_63976 == 128);
	if (cppVar_63978) {
	cppVar_63974 = P0;
	} else {
	cppVar_63980 = PC + 1;
	cppVar_63980 = (cppVar_63980 & cppMask_un_16_);
	cppVar_63981 = ROM.rd(cppVar_63980);
	cppVar_63983 = (cppVar_63981 == 129);
	if (cppVar_63983) {
	cppVar_63979 = SP;
	} else {
	cppVar_63985 = PC + 1;
	cppVar_63985 = (cppVar_63985 & cppMask_un_16_);
	cppVar_63986 = ROM.rd(cppVar_63985);
	cppVar_63988 = (cppVar_63986 == 130);
	if (cppVar_63988) {
	cppVar_63984 = DPL;
	} else {
	cppVar_63990 = PC + 1;
	cppVar_63990 = (cppVar_63990 & cppMask_un_16_);
	cppVar_63991 = ROM.rd(cppVar_63990);
	cppVar_63993 = (cppVar_63991 == 131);
	if (cppVar_63993) {
	cppVar_63989 = DPH;
	} else {
	cppVar_63995 = PC + 1;
	cppVar_63995 = (cppVar_63995 & cppMask_un_16_);
	cppVar_63996 = ROM.rd(cppVar_63995);
	cppVar_63998 = (cppVar_63996 == 135);
	if (cppVar_63998) {
	cppVar_63994 = PCON;
	} else {
	cppVar_64000 = PC + 1;
	cppVar_64000 = (cppVar_64000 & cppMask_un_16_);
	cppVar_64001 = ROM.rd(cppVar_64000);
	cppVar_64003 = (cppVar_64001 == 136);
	if (cppVar_64003) {
	cppVar_63999 = TCON;
	} else {
	cppVar_64005 = PC + 1;
	cppVar_64005 = (cppVar_64005 & cppMask_un_16_);
	cppVar_64006 = ROM.rd(cppVar_64005);
	cppVar_64008 = (cppVar_64006 == 137);
	if (cppVar_64008) {
	cppVar_64004 = TMOD;
	} else {
	cppVar_64010 = PC + 1;
	cppVar_64010 = (cppVar_64010 & cppMask_un_16_);
	cppVar_64011 = ROM.rd(cppVar_64010);
	cppVar_64013 = (cppVar_64011 == 138);
	if (cppVar_64013) {
	cppVar_64009 = TL0;
	} else {
	cppVar_64015 = PC + 1;
	cppVar_64015 = (cppVar_64015 & cppMask_un_16_);
	cppVar_64016 = ROM.rd(cppVar_64015);
	cppVar_64018 = (cppVar_64016 == 140);
	if (cppVar_64018) {
	cppVar_64014 = TH0;
	} else {
	cppVar_64020 = PC + 1;
	cppVar_64020 = (cppVar_64020 & cppMask_un_16_);
	cppVar_64021 = ROM.rd(cppVar_64020);
	cppVar_64023 = (cppVar_64021 == 139);
	if (cppVar_64023) {
	cppVar_64019 = TL1;
	} else {
	cppVar_64025 = PC + 1;
	cppVar_64025 = (cppVar_64025 & cppMask_un_16_);
	cppVar_64026 = ROM.rd(cppVar_64025);
	cppVar_64028 = (cppVar_64026 == 141);
	if (cppVar_64028) {
	cppVar_64024 = TH1;
	} else {
	cppVar_64030 = PC + 1;
	cppVar_64030 = (cppVar_64030 & cppMask_un_16_);
	cppVar_64031 = ROM.rd(cppVar_64030);
	cppVar_64033 = (cppVar_64031 == 144);
	if (cppVar_64033) {
	cppVar_64029 = P1;
	} else {
	cppVar_64035 = PC + 1;
	cppVar_64035 = (cppVar_64035 & cppMask_un_16_);
	cppVar_64036 = ROM.rd(cppVar_64035);
	cppVar_64038 = (cppVar_64036 == 152);
	if (cppVar_64038) {
	cppVar_64034 = SCON;
	} else {
	cppVar_64040 = PC + 1;
	cppVar_64040 = (cppVar_64040 & cppMask_un_16_);
	cppVar_64041 = ROM.rd(cppVar_64040);
	cppVar_64043 = (cppVar_64041 == 153);
	if (cppVar_64043) {
	cppVar_64039 = SBUF;
	} else {
	cppVar_64045 = PC + 1;
	cppVar_64045 = (cppVar_64045 & cppMask_un_16_);
	cppVar_64046 = ROM.rd(cppVar_64045);
	cppVar_64048 = (cppVar_64046 == 160);
	if (cppVar_64048) {
	cppVar_64044 = P2;
	} else {
	cppVar_64050 = PC + 1;
	cppVar_64050 = (cppVar_64050 & cppMask_un_16_);
	cppVar_64051 = ROM.rd(cppVar_64050);
	cppVar_64053 = (cppVar_64051 == 168);
	if (cppVar_64053) {
	cppVar_64049 = IE;
	} else {
	cppVar_64055 = PC + 1;
	cppVar_64055 = (cppVar_64055 & cppMask_un_16_);
	cppVar_64056 = ROM.rd(cppVar_64055);
	cppVar_64058 = (cppVar_64056 == 176);
	if (cppVar_64058) {
	cppVar_64054 = P3;
	} else {
	cppVar_64060 = PC + 1;
	cppVar_64060 = (cppVar_64060 & cppMask_un_16_);
	cppVar_64061 = ROM.rd(cppVar_64060);
	cppVar_64063 = (cppVar_64061 == 184);
	if (cppVar_64063) {
	cppVar_64059 = IP;
	} else {
	cppVar_64065 = PC + 1;
	cppVar_64065 = (cppVar_64065 & cppMask_un_16_);
	cppVar_64066 = ROM.rd(cppVar_64065);
	cppVar_64068 = (cppVar_64066 == 208);
	if (cppVar_64068) {
	cppVar_64064 = PSW;
	} else {
	cppVar_64070 = PC + 1;
	cppVar_64070 = (cppVar_64070 & cppMask_un_16_);
	cppVar_64071 = ROM.rd(cppVar_64070);
	cppVar_64073 = (cppVar_64071 == 224);
	if (cppVar_64073) {
	cppVar_64069 = ACC;
	} else {
	cppVar_64075 = PC + 1;
	cppVar_64075 = (cppVar_64075 & cppMask_un_16_);
	cppVar_64076 = ROM.rd(cppVar_64075);
	cppVar_64078 = (cppVar_64076 == 240);
	if (cppVar_64078) {
	cppVar_64074 = B;
	} else {
	cppVar_64074 = 0;
	}
	cppVar_64069 = cppVar_64074;
	}
	cppVar_64064 = cppVar_64069;
	}
	cppVar_64059 = cppVar_64064;
	}
	cppVar_64054 = cppVar_64059;
	}
	cppVar_64049 = cppVar_64054;
	}
	cppVar_64044 = cppVar_64049;
	}
	cppVar_64039 = cppVar_64044;
	}
	cppVar_64034 = cppVar_64039;
	}
	cppVar_64029 = cppVar_64034;
	}
	cppVar_64024 = cppVar_64029;
	}
	cppVar_64019 = cppVar_64024;
	}
	cppVar_64014 = cppVar_64019;
	}
	cppVar_64009 = cppVar_64014;
	}
	cppVar_64004 = cppVar_64009;
	}
	cppVar_63999 = cppVar_64004;
	}
	cppVar_63994 = cppVar_63999;
	}
	cppVar_63989 = cppVar_63994;
	}
	cppVar_63984 = cppVar_63989;
	}
	cppVar_63979 = cppVar_63984;
	}
	cppVar_63974 = cppVar_63979;
	}
	cppVar_63965 = cppVar_63974;
	}
	cppVar_64081 = cppVar_63965 + 1;
	cppVar_64081 = (cppVar_64081 & cppMask_un_8_);
	cppVar_63959 = cppVar_64081;
	} else {
	cppVar_63959 = SCON;
	}
	cppVar_63955 = cppVar_63959;
	} else {
	cppVar_63955 = SCON;
	}
	cppVar_63519 = cppVar_63955;
	}
	cppVar_63388 = cppVar_63519;
	}
	cppVar_63262 = cppVar_63388;
	}
	cppVar_63133 = cppVar_63262;
	}
	cppVar_63007 = cppVar_63133;
	}
	cppVar_62878 = cppVar_63007;
	}
	cppVar_62752 = cppVar_62878;
	}
	cppVar_62623 = cppVar_62752;
	}
	cppVar_62610 = cppVar_62623;
	}
	cppVar_62484 = cppVar_62610;
	}
	cppVar_62467 = cppVar_62484;
	}
	cppVar_62450 = cppVar_62467;
	}
	cppVar_62300 = cppVar_62450;
	}
	cppVar_62150 = cppVar_62300;
	}
	cppVar_62000 = cppVar_62150;
	}
	cppVar_61850 = cppVar_62000;
	}
	cppVar_61700 = cppVar_61850;
	}
	cppVar_61550 = cppVar_61700;
	}
	cppVar_61400 = cppVar_61550;
	}
	cppVar_61250 = cppVar_61400;
	}
	cppVar_60818 = cppVar_61250;
	}
	cppVar_59988 = cppVar_60818;
	}
	cppVar_59974 = cppVar_59988;
	}
	cppVar_59963 = cppVar_59974;
	}
	cppVar_59531 = cppVar_59963;
	}
	return cppVar_59531;
}
