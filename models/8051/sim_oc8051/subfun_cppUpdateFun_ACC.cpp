#include "common.hpp"
#include "model_oc8051_class.hpp"

BIT_VEC model_oc8051::cppUpdateFun_ACC()
{
	BIT_VEC cppVar_28;
	BIT_VEC cppVar_29;
	bool cppVar_30;
	BIT_VEC cppVar_31;
	BIT_VEC cppVar_33;
	BIT_VEC cppVar_34;
	bool cppVar_35;
	BIT_VEC cppVar_37;
	BIT_VEC cppVar_38;
	BIT_VEC cppVar_39;
	BIT_VEC cppVar_40;
	BIT_VEC cppVar_41;
	BIT_VEC cppVar_42;
	BIT_VEC cppVar_43;
	bool cppVar_44;
	BIT_VEC cppVar_45;
	BIT_VEC cppVar_46;
	BIT_VEC cppVar_47;
	BIT_VEC cppVar_48;
	BIT_VEC cppVar_50;
	BIT_VEC cppVar_51;
	BIT_VEC cppVar_52;
	BIT_VEC cppVar_53;
	bool cppVar_54;
	BIT_VEC cppVar_56;
	BIT_VEC cppVar_57;
	BIT_VEC cppVar_58;
	BIT_VEC cppVar_59;
	bool cppVar_60;
	BIT_VEC cppVar_62;
	BIT_VEC cppVar_63;
	BIT_VEC cppVar_64;
	BIT_VEC cppVar_65;
	bool cppVar_66;
	BIT_VEC cppVar_68;
	BIT_VEC cppVar_69;
	BIT_VEC cppVar_70;
	BIT_VEC cppVar_71;
	bool cppVar_72;
	BIT_VEC cppVar_74;
	BIT_VEC cppVar_75;
	BIT_VEC cppVar_76;
	BIT_VEC cppVar_77;
	bool cppVar_78;
	BIT_VEC cppVar_80;
	BIT_VEC cppVar_81;
	BIT_VEC cppVar_82;
	BIT_VEC cppVar_83;
	bool cppVar_84;
	BIT_VEC cppVar_86;
	BIT_VEC cppVar_87;
	BIT_VEC cppVar_88;
	BIT_VEC cppVar_89;
	bool cppVar_90;
	BIT_VEC cppVar_92;
	BIT_VEC cppVar_93;
	BIT_VEC cppVar_94;
	BIT_VEC cppVar_95;
	bool cppVar_96;
	BIT_VEC cppVar_98;
	BIT_VEC cppVar_99;
	BIT_VEC cppVar_100;
	BIT_VEC cppVar_101;
	bool cppVar_102;
	BIT_VEC cppVar_104;
	BIT_VEC cppVar_105;
	BIT_VEC cppVar_106;
	BIT_VEC cppVar_107;
	bool cppVar_108;
	BIT_VEC cppVar_110;
	BIT_VEC cppVar_111;
	BIT_VEC cppVar_112;
	BIT_VEC cppVar_113;
	bool cppVar_114;
	BIT_VEC cppVar_116;
	BIT_VEC cppVar_117;
	BIT_VEC cppVar_118;
	BIT_VEC cppVar_119;
	bool cppVar_120;
	BIT_VEC cppVar_122;
	BIT_VEC cppVar_123;
	BIT_VEC cppVar_124;
	BIT_VEC cppVar_125;
	bool cppVar_126;
	BIT_VEC cppVar_128;
	BIT_VEC cppVar_129;
	BIT_VEC cppVar_130;
	BIT_VEC cppVar_131;
	bool cppVar_132;
	BIT_VEC cppVar_134;
	BIT_VEC cppVar_135;
	BIT_VEC cppVar_136;
	BIT_VEC cppVar_137;
	bool cppVar_138;
	BIT_VEC cppVar_140;
	BIT_VEC cppVar_141;
	BIT_VEC cppVar_142;
	BIT_VEC cppVar_143;
	bool cppVar_144;
	BIT_VEC cppVar_146;
	BIT_VEC cppVar_147;
	BIT_VEC cppVar_148;
	BIT_VEC cppVar_149;
	bool cppVar_150;
	BIT_VEC cppVar_152;
	BIT_VEC cppVar_153;
	BIT_VEC cppVar_154;
	BIT_VEC cppVar_155;
	bool cppVar_156;
	BIT_VEC cppVar_158;
	BIT_VEC cppVar_159;
	BIT_VEC cppVar_160;
	BIT_VEC cppVar_161;
	bool cppVar_162;
	BIT_VEC cppVar_164;
	BIT_VEC cppVar_165;
	BIT_VEC cppVar_166;
	BIT_VEC cppVar_167;
	bool cppVar_168;
	BIT_VEC cppVar_170;
	BIT_VEC cppVar_171;
	BIT_VEC cppVar_172;
	BIT_VEC cppVar_173;
	bool cppVar_174;
	BIT_VEC cppVar_175;
	BIT_VEC cppVar_169;
	BIT_VEC cppVar_163;
	BIT_VEC cppVar_157;
	BIT_VEC cppVar_151;
	BIT_VEC cppVar_145;
	BIT_VEC cppVar_139;
	BIT_VEC cppVar_133;
	BIT_VEC cppVar_127;
	BIT_VEC cppVar_121;
	BIT_VEC cppVar_115;
	BIT_VEC cppVar_109;
	BIT_VEC cppVar_103;
	BIT_VEC cppVar_97;
	BIT_VEC cppVar_91;
	BIT_VEC cppVar_85;
	BIT_VEC cppVar_79;
	BIT_VEC cppVar_73;
	BIT_VEC cppVar_67;
	BIT_VEC cppVar_61;
	BIT_VEC cppVar_55;
	BIT_VEC cppVar_49;
	BIT_VEC cppVar_36;
	BIT_VEC cppVar_177;
	BIT_VEC cppVar_178;
	bool cppVar_179;
	BIT_VEC cppVar_180;
	BIT_VEC cppVar_182;
	BIT_VEC cppVar_183;
	bool cppVar_184;
	BIT_VEC cppVar_185;
	BIT_VEC cppVar_186;
	bool cppVar_187;
	BIT_VEC cppVar_188;
	BIT_VEC cppVar_189;
	bool cppVar_190;
	bool cppVar_191;
	bool cppVar_192;
	BIT_VEC cppVar_194;
	BIT_VEC cppVar_195;
	bool cppVar_196;
	BIT_VEC cppVar_197;
	BIT_VEC cppVar_198;
	BIT_VEC cppVar_199;
	BIT_VEC cppVar_200;
	BIT_VEC cppVar_201;
	BIT_VEC cppVar_202;
	BIT_VEC cppVar_203;
	BIT_VEC cppVar_204;
	BIT_VEC cppVar_205;
	BIT_VEC cppVar_206;
	BIT_VEC cppVar_208;
	BIT_VEC cppVar_209;
	bool cppVar_210;
	BIT_VEC cppVar_211;
	BIT_VEC cppVar_212;
	BIT_VEC cppVar_213;
	BIT_VEC cppVar_214;
	BIT_VEC cppVar_215;
	BIT_VEC cppVar_216;
	BIT_VEC cppVar_217;
	BIT_VEC cppVar_218;
	BIT_VEC cppVar_219;
	BIT_VEC cppVar_220;
	BIT_VEC cppVar_222;
	BIT_VEC cppVar_223;
	bool cppVar_224;
	BIT_VEC cppVar_227;
	BIT_VEC cppVar_228;
	bool cppVar_229;
	BIT_VEC cppVar_230;
	BIT_VEC cppVar_231;
	bool cppVar_232;
	bool cppVar_233;
	BIT_VEC cppVar_234;
	BIT_VEC cppVar_235;
	BIT_VEC cppVar_236;
	BIT_VEC cppVar_237;
	BIT_VEC cppVar_226;
	BIT_VEC cppVar_238;
	BIT_VEC cppVar_239;
	BIT_VEC cppVar_240;
	BIT_VEC cppVar_241;
	bool cppVar_242;
	BIT_VEC cppVar_244;
	bool cppVar_245;
	BIT_VEC cppVar_246;
	bool cppVar_247;
	bool cppVar_248;
	BIT_VEC cppVar_249;
	BIT_VEC cppVar_250;
	BIT_VEC cppVar_251;
	BIT_VEC cppVar_243;
	BIT_VEC cppVar_252;
	BIT_VEC cppVar_253;
	bool cppVar_254;
	bool cppVar_255;
	BIT_VEC cppVar_257;
	bool cppVar_258;
	BIT_VEC cppVar_259;
	bool cppVar_260;
	bool cppVar_261;
	BIT_VEC cppVar_262;
	BIT_VEC cppVar_263;
	BIT_VEC cppVar_264;
	BIT_VEC cppVar_256;
	BIT_VEC cppVar_265;
	BIT_VEC cppVar_266;
	BIT_VEC cppVar_268;
	bool cppVar_269;
	BIT_VEC cppVar_270;
	bool cppVar_271;
	bool cppVar_272;
	BIT_VEC cppVar_273;
	BIT_VEC cppVar_274;
	BIT_VEC cppVar_275;
	BIT_VEC cppVar_267;
	BIT_VEC cppVar_225;
	BIT_VEC cppVar_276;
	BIT_VEC cppVar_278;
	BIT_VEC cppVar_279;
	bool cppVar_280;
	BIT_VEC cppVar_281;
	BIT_VEC cppVar_282;
	bool cppVar_283;
	bool cppVar_284;
	BIT_VEC cppVar_286;
	BIT_VEC cppVar_287;
	BIT_VEC cppVar_288;
	BIT_VEC cppVar_289;
	BIT_VEC cppVar_290;
	BIT_VEC cppVar_291;
	BIT_VEC cppVar_292;
	bool cppVar_293;
	BIT_VEC cppVar_294;
	BIT_VEC cppVar_295;
	BIT_VEC cppVar_296;
	BIT_VEC cppVar_297;
	BIT_VEC cppVar_299;
	BIT_VEC cppVar_300;
	BIT_VEC cppVar_301;
	BIT_VEC cppVar_302;
	bool cppVar_303;
	BIT_VEC cppVar_305;
	BIT_VEC cppVar_306;
	BIT_VEC cppVar_307;
	BIT_VEC cppVar_308;
	bool cppVar_309;
	BIT_VEC cppVar_311;
	BIT_VEC cppVar_312;
	BIT_VEC cppVar_313;
	BIT_VEC cppVar_314;
	bool cppVar_315;
	BIT_VEC cppVar_317;
	BIT_VEC cppVar_318;
	BIT_VEC cppVar_319;
	BIT_VEC cppVar_320;
	bool cppVar_321;
	BIT_VEC cppVar_323;
	BIT_VEC cppVar_324;
	BIT_VEC cppVar_325;
	BIT_VEC cppVar_326;
	bool cppVar_327;
	BIT_VEC cppVar_329;
	BIT_VEC cppVar_330;
	BIT_VEC cppVar_331;
	BIT_VEC cppVar_332;
	bool cppVar_333;
	BIT_VEC cppVar_335;
	BIT_VEC cppVar_336;
	BIT_VEC cppVar_337;
	BIT_VEC cppVar_338;
	bool cppVar_339;
	BIT_VEC cppVar_341;
	BIT_VEC cppVar_342;
	BIT_VEC cppVar_343;
	BIT_VEC cppVar_344;
	bool cppVar_345;
	BIT_VEC cppVar_347;
	BIT_VEC cppVar_348;
	BIT_VEC cppVar_349;
	BIT_VEC cppVar_350;
	bool cppVar_351;
	BIT_VEC cppVar_353;
	BIT_VEC cppVar_354;
	BIT_VEC cppVar_355;
	BIT_VEC cppVar_356;
	bool cppVar_357;
	BIT_VEC cppVar_359;
	BIT_VEC cppVar_360;
	BIT_VEC cppVar_361;
	BIT_VEC cppVar_362;
	bool cppVar_363;
	BIT_VEC cppVar_365;
	BIT_VEC cppVar_366;
	BIT_VEC cppVar_367;
	BIT_VEC cppVar_368;
	bool cppVar_369;
	BIT_VEC cppVar_371;
	BIT_VEC cppVar_372;
	BIT_VEC cppVar_373;
	BIT_VEC cppVar_374;
	bool cppVar_375;
	BIT_VEC cppVar_377;
	BIT_VEC cppVar_378;
	BIT_VEC cppVar_379;
	BIT_VEC cppVar_380;
	bool cppVar_381;
	BIT_VEC cppVar_383;
	BIT_VEC cppVar_384;
	BIT_VEC cppVar_385;
	BIT_VEC cppVar_386;
	bool cppVar_387;
	BIT_VEC cppVar_389;
	BIT_VEC cppVar_390;
	BIT_VEC cppVar_391;
	BIT_VEC cppVar_392;
	bool cppVar_393;
	BIT_VEC cppVar_395;
	BIT_VEC cppVar_396;
	BIT_VEC cppVar_397;
	BIT_VEC cppVar_398;
	bool cppVar_399;
	BIT_VEC cppVar_401;
	BIT_VEC cppVar_402;
	BIT_VEC cppVar_403;
	BIT_VEC cppVar_404;
	bool cppVar_405;
	BIT_VEC cppVar_407;
	BIT_VEC cppVar_408;
	BIT_VEC cppVar_409;
	BIT_VEC cppVar_410;
	bool cppVar_411;
	BIT_VEC cppVar_413;
	BIT_VEC cppVar_414;
	BIT_VEC cppVar_415;
	BIT_VEC cppVar_416;
	bool cppVar_417;
	BIT_VEC cppVar_419;
	BIT_VEC cppVar_420;
	BIT_VEC cppVar_421;
	BIT_VEC cppVar_422;
	bool cppVar_423;
	BIT_VEC cppVar_424;
	BIT_VEC cppVar_418;
	BIT_VEC cppVar_412;
	BIT_VEC cppVar_406;
	BIT_VEC cppVar_400;
	BIT_VEC cppVar_394;
	BIT_VEC cppVar_388;
	BIT_VEC cppVar_382;
	BIT_VEC cppVar_376;
	BIT_VEC cppVar_370;
	BIT_VEC cppVar_364;
	BIT_VEC cppVar_358;
	BIT_VEC cppVar_352;
	BIT_VEC cppVar_346;
	BIT_VEC cppVar_340;
	BIT_VEC cppVar_334;
	BIT_VEC cppVar_328;
	BIT_VEC cppVar_322;
	BIT_VEC cppVar_316;
	BIT_VEC cppVar_310;
	BIT_VEC cppVar_304;
	BIT_VEC cppVar_298;
	BIT_VEC cppVar_285;
	BIT_VEC cppVar_426;
	BIT_VEC cppVar_427;
	bool cppVar_428;
	BIT_VEC cppVar_429;
	BIT_VEC cppVar_430;
	BIT_VEC cppVar_431;
	BIT_VEC cppVar_432;
	BIT_VEC cppVar_433;
	BIT_VEC cppVar_434;
	BIT_VEC cppVar_436;
	BIT_VEC cppVar_437;
	bool cppVar_438;
	BIT_VEC cppVar_439;
	BIT_VEC cppVar_440;
	bool cppVar_441;
	bool cppVar_442;
	BIT_VEC cppVar_443;
	BIT_VEC cppVar_444;
	BIT_VEC cppVar_445;
	BIT_VEC cppVar_446;
	BIT_VEC cppVar_447;
	BIT_VEC cppVar_448;
	BIT_VEC cppVar_450;
	BIT_VEC cppVar_451;
	bool cppVar_452;
	BIT_VEC cppVar_453;
	BIT_VEC cppVar_454;
	bool cppVar_455;
	bool cppVar_456;
	BIT_VEC cppVar_458;
	BIT_VEC cppVar_459;
	BIT_VEC cppVar_460;
	BIT_VEC cppVar_461;
	BIT_VEC cppVar_462;
	BIT_VEC cppVar_463;
	BIT_VEC cppVar_464;
	bool cppVar_465;
	BIT_VEC cppVar_466;
	BIT_VEC cppVar_467;
	BIT_VEC cppVar_468;
	BIT_VEC cppVar_469;
	BIT_VEC cppVar_471;
	BIT_VEC cppVar_472;
	BIT_VEC cppVar_473;
	BIT_VEC cppVar_474;
	bool cppVar_475;
	BIT_VEC cppVar_477;
	BIT_VEC cppVar_478;
	BIT_VEC cppVar_479;
	BIT_VEC cppVar_480;
	bool cppVar_481;
	BIT_VEC cppVar_483;
	BIT_VEC cppVar_484;
	BIT_VEC cppVar_485;
	BIT_VEC cppVar_486;
	bool cppVar_487;
	BIT_VEC cppVar_489;
	BIT_VEC cppVar_490;
	BIT_VEC cppVar_491;
	BIT_VEC cppVar_492;
	bool cppVar_493;
	BIT_VEC cppVar_495;
	BIT_VEC cppVar_496;
	BIT_VEC cppVar_497;
	BIT_VEC cppVar_498;
	bool cppVar_499;
	BIT_VEC cppVar_501;
	BIT_VEC cppVar_502;
	BIT_VEC cppVar_503;
	BIT_VEC cppVar_504;
	bool cppVar_505;
	BIT_VEC cppVar_507;
	BIT_VEC cppVar_508;
	BIT_VEC cppVar_509;
	BIT_VEC cppVar_510;
	bool cppVar_511;
	BIT_VEC cppVar_513;
	BIT_VEC cppVar_514;
	BIT_VEC cppVar_515;
	BIT_VEC cppVar_516;
	bool cppVar_517;
	BIT_VEC cppVar_519;
	BIT_VEC cppVar_520;
	BIT_VEC cppVar_521;
	BIT_VEC cppVar_522;
	bool cppVar_523;
	BIT_VEC cppVar_525;
	BIT_VEC cppVar_526;
	BIT_VEC cppVar_527;
	BIT_VEC cppVar_528;
	bool cppVar_529;
	BIT_VEC cppVar_531;
	BIT_VEC cppVar_532;
	BIT_VEC cppVar_533;
	BIT_VEC cppVar_534;
	bool cppVar_535;
	BIT_VEC cppVar_537;
	BIT_VEC cppVar_538;
	BIT_VEC cppVar_539;
	BIT_VEC cppVar_540;
	bool cppVar_541;
	BIT_VEC cppVar_543;
	BIT_VEC cppVar_544;
	BIT_VEC cppVar_545;
	BIT_VEC cppVar_546;
	bool cppVar_547;
	BIT_VEC cppVar_549;
	BIT_VEC cppVar_550;
	BIT_VEC cppVar_551;
	BIT_VEC cppVar_552;
	bool cppVar_553;
	BIT_VEC cppVar_555;
	BIT_VEC cppVar_556;
	BIT_VEC cppVar_557;
	BIT_VEC cppVar_558;
	bool cppVar_559;
	BIT_VEC cppVar_561;
	BIT_VEC cppVar_562;
	BIT_VEC cppVar_563;
	BIT_VEC cppVar_564;
	bool cppVar_565;
	BIT_VEC cppVar_567;
	BIT_VEC cppVar_568;
	BIT_VEC cppVar_569;
	BIT_VEC cppVar_570;
	bool cppVar_571;
	BIT_VEC cppVar_573;
	BIT_VEC cppVar_574;
	BIT_VEC cppVar_575;
	BIT_VEC cppVar_576;
	bool cppVar_577;
	BIT_VEC cppVar_579;
	BIT_VEC cppVar_580;
	BIT_VEC cppVar_581;
	BIT_VEC cppVar_582;
	bool cppVar_583;
	BIT_VEC cppVar_585;
	BIT_VEC cppVar_586;
	BIT_VEC cppVar_587;
	BIT_VEC cppVar_588;
	bool cppVar_589;
	BIT_VEC cppVar_591;
	BIT_VEC cppVar_592;
	BIT_VEC cppVar_593;
	BIT_VEC cppVar_594;
	bool cppVar_595;
	BIT_VEC cppVar_596;
	BIT_VEC cppVar_590;
	BIT_VEC cppVar_584;
	BIT_VEC cppVar_578;
	BIT_VEC cppVar_572;
	BIT_VEC cppVar_566;
	BIT_VEC cppVar_560;
	BIT_VEC cppVar_554;
	BIT_VEC cppVar_548;
	BIT_VEC cppVar_542;
	BIT_VEC cppVar_536;
	BIT_VEC cppVar_530;
	BIT_VEC cppVar_524;
	BIT_VEC cppVar_518;
	BIT_VEC cppVar_512;
	BIT_VEC cppVar_506;
	BIT_VEC cppVar_500;
	BIT_VEC cppVar_494;
	BIT_VEC cppVar_488;
	BIT_VEC cppVar_482;
	BIT_VEC cppVar_476;
	BIT_VEC cppVar_470;
	BIT_VEC cppVar_457;
	BIT_VEC cppVar_598;
	BIT_VEC cppVar_599;
	bool cppVar_600;
	BIT_VEC cppVar_601;
	BIT_VEC cppVar_602;
	bool cppVar_603;
	bool cppVar_604;
	BIT_VEC cppVar_606;
	BIT_VEC cppVar_607;
	BIT_VEC cppVar_608;
	BIT_VEC cppVar_609;
	BIT_VEC cppVar_610;
	BIT_VEC cppVar_611;
	BIT_VEC cppVar_612;
	bool cppVar_613;
	BIT_VEC cppVar_614;
	BIT_VEC cppVar_615;
	BIT_VEC cppVar_616;
	BIT_VEC cppVar_617;
	BIT_VEC cppVar_619;
	BIT_VEC cppVar_620;
	BIT_VEC cppVar_621;
	BIT_VEC cppVar_622;
	bool cppVar_623;
	BIT_VEC cppVar_625;
	BIT_VEC cppVar_626;
	BIT_VEC cppVar_627;
	BIT_VEC cppVar_628;
	bool cppVar_629;
	BIT_VEC cppVar_631;
	BIT_VEC cppVar_632;
	BIT_VEC cppVar_633;
	BIT_VEC cppVar_634;
	bool cppVar_635;
	BIT_VEC cppVar_637;
	BIT_VEC cppVar_638;
	BIT_VEC cppVar_639;
	BIT_VEC cppVar_640;
	bool cppVar_641;
	BIT_VEC cppVar_643;
	BIT_VEC cppVar_644;
	BIT_VEC cppVar_645;
	BIT_VEC cppVar_646;
	bool cppVar_647;
	BIT_VEC cppVar_649;
	BIT_VEC cppVar_650;
	BIT_VEC cppVar_651;
	BIT_VEC cppVar_652;
	bool cppVar_653;
	BIT_VEC cppVar_655;
	BIT_VEC cppVar_656;
	BIT_VEC cppVar_657;
	BIT_VEC cppVar_658;
	bool cppVar_659;
	BIT_VEC cppVar_661;
	BIT_VEC cppVar_662;
	BIT_VEC cppVar_663;
	BIT_VEC cppVar_664;
	bool cppVar_665;
	BIT_VEC cppVar_667;
	BIT_VEC cppVar_668;
	BIT_VEC cppVar_669;
	BIT_VEC cppVar_670;
	bool cppVar_671;
	BIT_VEC cppVar_673;
	BIT_VEC cppVar_674;
	BIT_VEC cppVar_675;
	BIT_VEC cppVar_676;
	bool cppVar_677;
	BIT_VEC cppVar_679;
	BIT_VEC cppVar_680;
	BIT_VEC cppVar_681;
	BIT_VEC cppVar_682;
	bool cppVar_683;
	BIT_VEC cppVar_685;
	BIT_VEC cppVar_686;
	BIT_VEC cppVar_687;
	BIT_VEC cppVar_688;
	bool cppVar_689;
	BIT_VEC cppVar_691;
	BIT_VEC cppVar_692;
	BIT_VEC cppVar_693;
	BIT_VEC cppVar_694;
	bool cppVar_695;
	BIT_VEC cppVar_697;
	BIT_VEC cppVar_698;
	BIT_VEC cppVar_699;
	BIT_VEC cppVar_700;
	bool cppVar_701;
	BIT_VEC cppVar_703;
	BIT_VEC cppVar_704;
	BIT_VEC cppVar_705;
	BIT_VEC cppVar_706;
	bool cppVar_707;
	BIT_VEC cppVar_709;
	BIT_VEC cppVar_710;
	BIT_VEC cppVar_711;
	BIT_VEC cppVar_712;
	bool cppVar_713;
	BIT_VEC cppVar_715;
	BIT_VEC cppVar_716;
	BIT_VEC cppVar_717;
	BIT_VEC cppVar_718;
	bool cppVar_719;
	BIT_VEC cppVar_721;
	BIT_VEC cppVar_722;
	BIT_VEC cppVar_723;
	BIT_VEC cppVar_724;
	bool cppVar_725;
	BIT_VEC cppVar_727;
	BIT_VEC cppVar_728;
	BIT_VEC cppVar_729;
	BIT_VEC cppVar_730;
	bool cppVar_731;
	BIT_VEC cppVar_733;
	BIT_VEC cppVar_734;
	BIT_VEC cppVar_735;
	BIT_VEC cppVar_736;
	bool cppVar_737;
	BIT_VEC cppVar_739;
	BIT_VEC cppVar_740;
	BIT_VEC cppVar_741;
	BIT_VEC cppVar_742;
	bool cppVar_743;
	BIT_VEC cppVar_744;
	BIT_VEC cppVar_738;
	BIT_VEC cppVar_732;
	BIT_VEC cppVar_726;
	BIT_VEC cppVar_720;
	BIT_VEC cppVar_714;
	BIT_VEC cppVar_708;
	BIT_VEC cppVar_702;
	BIT_VEC cppVar_696;
	BIT_VEC cppVar_690;
	BIT_VEC cppVar_684;
	BIT_VEC cppVar_678;
	BIT_VEC cppVar_672;
	BIT_VEC cppVar_666;
	BIT_VEC cppVar_660;
	BIT_VEC cppVar_654;
	BIT_VEC cppVar_648;
	BIT_VEC cppVar_642;
	BIT_VEC cppVar_636;
	BIT_VEC cppVar_630;
	BIT_VEC cppVar_624;
	BIT_VEC cppVar_618;
	BIT_VEC cppVar_605;
	BIT_VEC cppVar_746;
	BIT_VEC cppVar_747;
	bool cppVar_748;
	BIT_VEC cppVar_749;
	BIT_VEC cppVar_750;
	bool cppVar_751;
	bool cppVar_752;
	BIT_VEC cppVar_754;
	BIT_VEC cppVar_755;
	BIT_VEC cppVar_756;
	BIT_VEC cppVar_757;
	BIT_VEC cppVar_758;
	BIT_VEC cppVar_759;
	BIT_VEC cppVar_760;
	bool cppVar_761;
	BIT_VEC cppVar_762;
	BIT_VEC cppVar_763;
	BIT_VEC cppVar_764;
	BIT_VEC cppVar_765;
	BIT_VEC cppVar_767;
	BIT_VEC cppVar_768;
	BIT_VEC cppVar_769;
	BIT_VEC cppVar_770;
	bool cppVar_771;
	BIT_VEC cppVar_773;
	BIT_VEC cppVar_774;
	BIT_VEC cppVar_775;
	BIT_VEC cppVar_776;
	bool cppVar_777;
	BIT_VEC cppVar_779;
	BIT_VEC cppVar_780;
	BIT_VEC cppVar_781;
	BIT_VEC cppVar_782;
	bool cppVar_783;
	BIT_VEC cppVar_785;
	BIT_VEC cppVar_786;
	BIT_VEC cppVar_787;
	BIT_VEC cppVar_788;
	bool cppVar_789;
	BIT_VEC cppVar_791;
	BIT_VEC cppVar_792;
	BIT_VEC cppVar_793;
	BIT_VEC cppVar_794;
	bool cppVar_795;
	BIT_VEC cppVar_797;
	BIT_VEC cppVar_798;
	BIT_VEC cppVar_799;
	BIT_VEC cppVar_800;
	bool cppVar_801;
	BIT_VEC cppVar_803;
	BIT_VEC cppVar_804;
	BIT_VEC cppVar_805;
	BIT_VEC cppVar_806;
	bool cppVar_807;
	BIT_VEC cppVar_809;
	BIT_VEC cppVar_810;
	BIT_VEC cppVar_811;
	BIT_VEC cppVar_812;
	bool cppVar_813;
	BIT_VEC cppVar_815;
	BIT_VEC cppVar_816;
	BIT_VEC cppVar_817;
	BIT_VEC cppVar_818;
	bool cppVar_819;
	BIT_VEC cppVar_821;
	BIT_VEC cppVar_822;
	BIT_VEC cppVar_823;
	BIT_VEC cppVar_824;
	bool cppVar_825;
	BIT_VEC cppVar_827;
	BIT_VEC cppVar_828;
	BIT_VEC cppVar_829;
	BIT_VEC cppVar_830;
	bool cppVar_831;
	BIT_VEC cppVar_833;
	BIT_VEC cppVar_834;
	BIT_VEC cppVar_835;
	BIT_VEC cppVar_836;
	bool cppVar_837;
	BIT_VEC cppVar_839;
	BIT_VEC cppVar_840;
	BIT_VEC cppVar_841;
	BIT_VEC cppVar_842;
	bool cppVar_843;
	BIT_VEC cppVar_845;
	BIT_VEC cppVar_846;
	BIT_VEC cppVar_847;
	BIT_VEC cppVar_848;
	bool cppVar_849;
	BIT_VEC cppVar_851;
	BIT_VEC cppVar_852;
	BIT_VEC cppVar_853;
	BIT_VEC cppVar_854;
	bool cppVar_855;
	BIT_VEC cppVar_857;
	BIT_VEC cppVar_858;
	BIT_VEC cppVar_859;
	BIT_VEC cppVar_860;
	bool cppVar_861;
	BIT_VEC cppVar_863;
	BIT_VEC cppVar_864;
	BIT_VEC cppVar_865;
	BIT_VEC cppVar_866;
	bool cppVar_867;
	BIT_VEC cppVar_869;
	BIT_VEC cppVar_870;
	BIT_VEC cppVar_871;
	BIT_VEC cppVar_872;
	bool cppVar_873;
	BIT_VEC cppVar_875;
	BIT_VEC cppVar_876;
	BIT_VEC cppVar_877;
	BIT_VEC cppVar_878;
	bool cppVar_879;
	BIT_VEC cppVar_881;
	BIT_VEC cppVar_882;
	BIT_VEC cppVar_883;
	BIT_VEC cppVar_884;
	bool cppVar_885;
	BIT_VEC cppVar_887;
	BIT_VEC cppVar_888;
	BIT_VEC cppVar_889;
	BIT_VEC cppVar_890;
	bool cppVar_891;
	BIT_VEC cppVar_892;
	BIT_VEC cppVar_886;
	BIT_VEC cppVar_880;
	BIT_VEC cppVar_874;
	BIT_VEC cppVar_868;
	BIT_VEC cppVar_862;
	BIT_VEC cppVar_856;
	BIT_VEC cppVar_850;
	BIT_VEC cppVar_844;
	BIT_VEC cppVar_838;
	BIT_VEC cppVar_832;
	BIT_VEC cppVar_826;
	BIT_VEC cppVar_820;
	BIT_VEC cppVar_814;
	BIT_VEC cppVar_808;
	BIT_VEC cppVar_802;
	BIT_VEC cppVar_796;
	BIT_VEC cppVar_790;
	BIT_VEC cppVar_784;
	BIT_VEC cppVar_778;
	BIT_VEC cppVar_772;
	BIT_VEC cppVar_766;
	BIT_VEC cppVar_753;
	BIT_VEC cppVar_894;
	BIT_VEC cppVar_895;
	bool cppVar_896;
	BIT_VEC cppVar_897;
	BIT_VEC cppVar_898;
	bool cppVar_899;
	bool cppVar_900;
	BIT_VEC cppVar_902;
	BIT_VEC cppVar_903;
	BIT_VEC cppVar_904;
	BIT_VEC cppVar_905;
	BIT_VEC cppVar_906;
	BIT_VEC cppVar_907;
	BIT_VEC cppVar_908;
	bool cppVar_909;
	BIT_VEC cppVar_910;
	BIT_VEC cppVar_911;
	BIT_VEC cppVar_912;
	BIT_VEC cppVar_913;
	BIT_VEC cppVar_915;
	BIT_VEC cppVar_916;
	BIT_VEC cppVar_917;
	BIT_VEC cppVar_918;
	bool cppVar_919;
	BIT_VEC cppVar_921;
	BIT_VEC cppVar_922;
	BIT_VEC cppVar_923;
	BIT_VEC cppVar_924;
	bool cppVar_925;
	BIT_VEC cppVar_927;
	BIT_VEC cppVar_928;
	BIT_VEC cppVar_929;
	BIT_VEC cppVar_930;
	bool cppVar_931;
	BIT_VEC cppVar_933;
	BIT_VEC cppVar_934;
	BIT_VEC cppVar_935;
	BIT_VEC cppVar_936;
	bool cppVar_937;
	BIT_VEC cppVar_939;
	BIT_VEC cppVar_940;
	BIT_VEC cppVar_941;
	BIT_VEC cppVar_942;
	bool cppVar_943;
	BIT_VEC cppVar_945;
	BIT_VEC cppVar_946;
	BIT_VEC cppVar_947;
	BIT_VEC cppVar_948;
	bool cppVar_949;
	BIT_VEC cppVar_951;
	BIT_VEC cppVar_952;
	BIT_VEC cppVar_953;
	BIT_VEC cppVar_954;
	bool cppVar_955;
	BIT_VEC cppVar_957;
	BIT_VEC cppVar_958;
	BIT_VEC cppVar_959;
	BIT_VEC cppVar_960;
	bool cppVar_961;
	BIT_VEC cppVar_963;
	BIT_VEC cppVar_964;
	BIT_VEC cppVar_965;
	BIT_VEC cppVar_966;
	bool cppVar_967;
	BIT_VEC cppVar_969;
	BIT_VEC cppVar_970;
	BIT_VEC cppVar_971;
	BIT_VEC cppVar_972;
	bool cppVar_973;
	BIT_VEC cppVar_975;
	BIT_VEC cppVar_976;
	BIT_VEC cppVar_977;
	BIT_VEC cppVar_978;
	bool cppVar_979;
	BIT_VEC cppVar_981;
	BIT_VEC cppVar_982;
	BIT_VEC cppVar_983;
	BIT_VEC cppVar_984;
	bool cppVar_985;
	BIT_VEC cppVar_987;
	BIT_VEC cppVar_988;
	BIT_VEC cppVar_989;
	BIT_VEC cppVar_990;
	bool cppVar_991;
	BIT_VEC cppVar_993;
	BIT_VEC cppVar_994;
	BIT_VEC cppVar_995;
	BIT_VEC cppVar_996;
	bool cppVar_997;
	BIT_VEC cppVar_999;
	BIT_VEC cppVar_1000;
	BIT_VEC cppVar_1001;
	BIT_VEC cppVar_1002;
	bool cppVar_1003;
	BIT_VEC cppVar_1005;
	BIT_VEC cppVar_1006;
	BIT_VEC cppVar_1007;
	BIT_VEC cppVar_1008;
	bool cppVar_1009;
	BIT_VEC cppVar_1011;
	BIT_VEC cppVar_1012;
	BIT_VEC cppVar_1013;
	BIT_VEC cppVar_1014;
	bool cppVar_1015;
	BIT_VEC cppVar_1017;
	BIT_VEC cppVar_1018;
	BIT_VEC cppVar_1019;
	BIT_VEC cppVar_1020;
	bool cppVar_1021;
	BIT_VEC cppVar_1023;
	BIT_VEC cppVar_1024;
	BIT_VEC cppVar_1025;
	BIT_VEC cppVar_1026;
	bool cppVar_1027;
	BIT_VEC cppVar_1029;
	BIT_VEC cppVar_1030;
	BIT_VEC cppVar_1031;
	BIT_VEC cppVar_1032;
	bool cppVar_1033;
	BIT_VEC cppVar_1035;
	BIT_VEC cppVar_1036;
	BIT_VEC cppVar_1037;
	BIT_VEC cppVar_1038;
	bool cppVar_1039;
	BIT_VEC cppVar_1040;
	BIT_VEC cppVar_1034;
	BIT_VEC cppVar_1028;
	BIT_VEC cppVar_1022;
	BIT_VEC cppVar_1016;
	BIT_VEC cppVar_1010;
	BIT_VEC cppVar_1004;
	BIT_VEC cppVar_998;
	BIT_VEC cppVar_992;
	BIT_VEC cppVar_986;
	BIT_VEC cppVar_980;
	BIT_VEC cppVar_974;
	BIT_VEC cppVar_968;
	BIT_VEC cppVar_962;
	BIT_VEC cppVar_956;
	BIT_VEC cppVar_950;
	BIT_VEC cppVar_944;
	BIT_VEC cppVar_938;
	BIT_VEC cppVar_932;
	BIT_VEC cppVar_926;
	BIT_VEC cppVar_920;
	BIT_VEC cppVar_914;
	BIT_VEC cppVar_901;
	BIT_VEC cppVar_1042;
	BIT_VEC cppVar_1043;
	bool cppVar_1044;
	BIT_VEC cppVar_1045;
	BIT_VEC cppVar_1046;
	bool cppVar_1047;
	bool cppVar_1048;
	BIT_VEC cppVar_1050;
	BIT_VEC cppVar_1051;
	BIT_VEC cppVar_1052;
	BIT_VEC cppVar_1053;
	BIT_VEC cppVar_1054;
	BIT_VEC cppVar_1055;
	BIT_VEC cppVar_1056;
	bool cppVar_1057;
	BIT_VEC cppVar_1058;
	BIT_VEC cppVar_1059;
	BIT_VEC cppVar_1060;
	BIT_VEC cppVar_1061;
	BIT_VEC cppVar_1063;
	BIT_VEC cppVar_1064;
	BIT_VEC cppVar_1065;
	BIT_VEC cppVar_1066;
	bool cppVar_1067;
	BIT_VEC cppVar_1069;
	BIT_VEC cppVar_1070;
	BIT_VEC cppVar_1071;
	BIT_VEC cppVar_1072;
	bool cppVar_1073;
	BIT_VEC cppVar_1075;
	BIT_VEC cppVar_1076;
	BIT_VEC cppVar_1077;
	BIT_VEC cppVar_1078;
	bool cppVar_1079;
	BIT_VEC cppVar_1081;
	BIT_VEC cppVar_1082;
	BIT_VEC cppVar_1083;
	BIT_VEC cppVar_1084;
	bool cppVar_1085;
	BIT_VEC cppVar_1087;
	BIT_VEC cppVar_1088;
	BIT_VEC cppVar_1089;
	BIT_VEC cppVar_1090;
	bool cppVar_1091;
	BIT_VEC cppVar_1093;
	BIT_VEC cppVar_1094;
	BIT_VEC cppVar_1095;
	BIT_VEC cppVar_1096;
	bool cppVar_1097;
	BIT_VEC cppVar_1099;
	BIT_VEC cppVar_1100;
	BIT_VEC cppVar_1101;
	BIT_VEC cppVar_1102;
	bool cppVar_1103;
	BIT_VEC cppVar_1105;
	BIT_VEC cppVar_1106;
	BIT_VEC cppVar_1107;
	BIT_VEC cppVar_1108;
	bool cppVar_1109;
	BIT_VEC cppVar_1111;
	BIT_VEC cppVar_1112;
	BIT_VEC cppVar_1113;
	BIT_VEC cppVar_1114;
	bool cppVar_1115;
	BIT_VEC cppVar_1117;
	BIT_VEC cppVar_1118;
	BIT_VEC cppVar_1119;
	BIT_VEC cppVar_1120;
	bool cppVar_1121;
	BIT_VEC cppVar_1123;
	BIT_VEC cppVar_1124;
	BIT_VEC cppVar_1125;
	BIT_VEC cppVar_1126;
	bool cppVar_1127;
	BIT_VEC cppVar_1129;
	BIT_VEC cppVar_1130;
	BIT_VEC cppVar_1131;
	BIT_VEC cppVar_1132;
	bool cppVar_1133;
	BIT_VEC cppVar_1135;
	BIT_VEC cppVar_1136;
	BIT_VEC cppVar_1137;
	BIT_VEC cppVar_1138;
	bool cppVar_1139;
	BIT_VEC cppVar_1141;
	BIT_VEC cppVar_1142;
	BIT_VEC cppVar_1143;
	BIT_VEC cppVar_1144;
	bool cppVar_1145;
	BIT_VEC cppVar_1147;
	BIT_VEC cppVar_1148;
	BIT_VEC cppVar_1149;
	BIT_VEC cppVar_1150;
	bool cppVar_1151;
	BIT_VEC cppVar_1153;
	BIT_VEC cppVar_1154;
	BIT_VEC cppVar_1155;
	BIT_VEC cppVar_1156;
	bool cppVar_1157;
	BIT_VEC cppVar_1159;
	BIT_VEC cppVar_1160;
	BIT_VEC cppVar_1161;
	BIT_VEC cppVar_1162;
	bool cppVar_1163;
	BIT_VEC cppVar_1165;
	BIT_VEC cppVar_1166;
	BIT_VEC cppVar_1167;
	BIT_VEC cppVar_1168;
	bool cppVar_1169;
	BIT_VEC cppVar_1171;
	BIT_VEC cppVar_1172;
	BIT_VEC cppVar_1173;
	BIT_VEC cppVar_1174;
	bool cppVar_1175;
	BIT_VEC cppVar_1177;
	BIT_VEC cppVar_1178;
	BIT_VEC cppVar_1179;
	BIT_VEC cppVar_1180;
	bool cppVar_1181;
	BIT_VEC cppVar_1183;
	BIT_VEC cppVar_1184;
	BIT_VEC cppVar_1185;
	BIT_VEC cppVar_1186;
	bool cppVar_1187;
	BIT_VEC cppVar_1188;
	BIT_VEC cppVar_1182;
	BIT_VEC cppVar_1176;
	BIT_VEC cppVar_1170;
	BIT_VEC cppVar_1164;
	BIT_VEC cppVar_1158;
	BIT_VEC cppVar_1152;
	BIT_VEC cppVar_1146;
	BIT_VEC cppVar_1140;
	BIT_VEC cppVar_1134;
	BIT_VEC cppVar_1128;
	BIT_VEC cppVar_1122;
	BIT_VEC cppVar_1116;
	BIT_VEC cppVar_1110;
	BIT_VEC cppVar_1104;
	BIT_VEC cppVar_1098;
	BIT_VEC cppVar_1092;
	BIT_VEC cppVar_1086;
	BIT_VEC cppVar_1080;
	BIT_VEC cppVar_1074;
	BIT_VEC cppVar_1068;
	BIT_VEC cppVar_1062;
	BIT_VEC cppVar_1049;
	BIT_VEC cppVar_1190;
	BIT_VEC cppVar_1191;
	bool cppVar_1192;
	BIT_VEC cppVar_1193;
	BIT_VEC cppVar_1194;
	bool cppVar_1195;
	bool cppVar_1196;
	BIT_VEC cppVar_1197;
	BIT_VEC cppVar_1198;
	BIT_VEC cppVar_1199;
	BIT_VEC cppVar_1200;
	BIT_VEC cppVar_1201;
	BIT_VEC cppVar_1202;
	BIT_VEC cppVar_1203;
	BIT_VEC cppVar_1205;
	BIT_VEC cppVar_1206;
	bool cppVar_1207;
	BIT_VEC cppVar_1208;
	BIT_VEC cppVar_1209;
	bool cppVar_1210;
	bool cppVar_1211;
	BIT_VEC cppVar_1212;
	BIT_VEC cppVar_1213;
	BIT_VEC cppVar_1214;
	BIT_VEC cppVar_1215;
	BIT_VEC cppVar_1216;
	BIT_VEC cppVar_1217;
	BIT_VEC cppVar_1218;
	BIT_VEC cppVar_1220;
	BIT_VEC cppVar_1221;
	bool cppVar_1222;
	BIT_VEC cppVar_1223;
	BIT_VEC cppVar_1224;
	bool cppVar_1225;
	bool cppVar_1226;
	BIT_VEC cppVar_1228;
	BIT_VEC cppVar_1229;
	BIT_VEC cppVar_1230;
	BIT_VEC cppVar_1231;
	BIT_VEC cppVar_1232;
	bool cppVar_1233;
	BIT_VEC cppVar_1234;
	BIT_VEC cppVar_1235;
	BIT_VEC cppVar_1236;
	BIT_VEC cppVar_1238;
	BIT_VEC cppVar_1239;
	BIT_VEC cppVar_1240;
	bool cppVar_1241;
	BIT_VEC cppVar_1243;
	BIT_VEC cppVar_1244;
	BIT_VEC cppVar_1245;
	bool cppVar_1246;
	BIT_VEC cppVar_1248;
	BIT_VEC cppVar_1249;
	BIT_VEC cppVar_1250;
	bool cppVar_1251;
	BIT_VEC cppVar_1253;
	BIT_VEC cppVar_1254;
	BIT_VEC cppVar_1255;
	bool cppVar_1256;
	BIT_VEC cppVar_1258;
	BIT_VEC cppVar_1259;
	BIT_VEC cppVar_1260;
	bool cppVar_1261;
	BIT_VEC cppVar_1263;
	BIT_VEC cppVar_1264;
	BIT_VEC cppVar_1265;
	bool cppVar_1266;
	BIT_VEC cppVar_1268;
	BIT_VEC cppVar_1269;
	BIT_VEC cppVar_1270;
	bool cppVar_1271;
	BIT_VEC cppVar_1273;
	BIT_VEC cppVar_1274;
	BIT_VEC cppVar_1275;
	bool cppVar_1276;
	BIT_VEC cppVar_1278;
	BIT_VEC cppVar_1279;
	BIT_VEC cppVar_1280;
	bool cppVar_1281;
	BIT_VEC cppVar_1283;
	BIT_VEC cppVar_1284;
	BIT_VEC cppVar_1285;
	bool cppVar_1286;
	BIT_VEC cppVar_1288;
	BIT_VEC cppVar_1289;
	BIT_VEC cppVar_1290;
	bool cppVar_1291;
	BIT_VEC cppVar_1293;
	BIT_VEC cppVar_1294;
	BIT_VEC cppVar_1295;
	bool cppVar_1296;
	BIT_VEC cppVar_1298;
	BIT_VEC cppVar_1299;
	BIT_VEC cppVar_1300;
	bool cppVar_1301;
	BIT_VEC cppVar_1303;
	BIT_VEC cppVar_1304;
	BIT_VEC cppVar_1305;
	bool cppVar_1306;
	BIT_VEC cppVar_1308;
	BIT_VEC cppVar_1309;
	BIT_VEC cppVar_1310;
	bool cppVar_1311;
	BIT_VEC cppVar_1313;
	BIT_VEC cppVar_1314;
	BIT_VEC cppVar_1315;
	bool cppVar_1316;
	BIT_VEC cppVar_1318;
	BIT_VEC cppVar_1319;
	BIT_VEC cppVar_1320;
	bool cppVar_1321;
	BIT_VEC cppVar_1323;
	BIT_VEC cppVar_1324;
	BIT_VEC cppVar_1325;
	bool cppVar_1326;
	BIT_VEC cppVar_1328;
	BIT_VEC cppVar_1329;
	BIT_VEC cppVar_1330;
	bool cppVar_1331;
	BIT_VEC cppVar_1333;
	BIT_VEC cppVar_1334;
	BIT_VEC cppVar_1335;
	bool cppVar_1336;
	BIT_VEC cppVar_1338;
	BIT_VEC cppVar_1339;
	BIT_VEC cppVar_1340;
	bool cppVar_1341;
	BIT_VEC cppVar_1342;
	BIT_VEC cppVar_1337;
	BIT_VEC cppVar_1332;
	BIT_VEC cppVar_1327;
	BIT_VEC cppVar_1322;
	BIT_VEC cppVar_1317;
	BIT_VEC cppVar_1312;
	BIT_VEC cppVar_1307;
	BIT_VEC cppVar_1302;
	BIT_VEC cppVar_1297;
	BIT_VEC cppVar_1292;
	BIT_VEC cppVar_1287;
	BIT_VEC cppVar_1282;
	BIT_VEC cppVar_1277;
	BIT_VEC cppVar_1272;
	BIT_VEC cppVar_1267;
	BIT_VEC cppVar_1262;
	BIT_VEC cppVar_1257;
	BIT_VEC cppVar_1252;
	BIT_VEC cppVar_1247;
	BIT_VEC cppVar_1242;
	BIT_VEC cppVar_1237;
	BIT_VEC cppVar_1227;
	BIT_VEC cppVar_1344;
	BIT_VEC cppVar_1345;
	bool cppVar_1346;
	BIT_VEC cppVar_1347;
	BIT_VEC cppVar_1348;
	BIT_VEC cppVar_1349;
	BIT_VEC cppVar_1351;
	BIT_VEC cppVar_1352;
	bool cppVar_1353;
	BIT_VEC cppVar_1354;
	BIT_VEC cppVar_1355;
	BIT_VEC cppVar_1356;
	BIT_VEC cppVar_1357;
	BIT_VEC cppVar_1359;
	BIT_VEC cppVar_1360;
	bool cppVar_1361;
	BIT_VEC cppVar_1362;
	BIT_VEC cppVar_1363;
	BIT_VEC cppVar_1364;
	BIT_VEC cppVar_1365;
	BIT_VEC cppVar_1366;
	BIT_VEC cppVar_1367;
	BIT_VEC cppVar_1368;
	BIT_VEC cppVar_1369;
	BIT_VEC cppVar_1370;
	BIT_VEC cppVar_1371;
	BIT_VEC cppVar_1373;
	BIT_VEC cppVar_1374;
	bool cppVar_1375;
	BIT_VEC cppVar_1376;
	BIT_VEC cppVar_1377;
	BIT_VEC cppVar_1378;
	BIT_VEC cppVar_1379;
	BIT_VEC cppVar_1380;
	BIT_VEC cppVar_1381;
	BIT_VEC cppVar_1382;
	BIT_VEC cppVar_1383;
	BIT_VEC cppVar_1384;
	BIT_VEC cppVar_1385;
	BIT_VEC cppVar_1387;
	BIT_VEC cppVar_1388;
	bool cppVar_1389;
	BIT_VEC cppVar_1390;
	BIT_VEC cppVar_1391;
	BIT_VEC cppVar_1392;
	BIT_VEC cppVar_1393;
	BIT_VEC cppVar_1394;
	BIT_VEC cppVar_1395;
	BIT_VEC cppVar_1396;
	BIT_VEC cppVar_1397;
	BIT_VEC cppVar_1398;
	BIT_VEC cppVar_1399;
	BIT_VEC cppVar_1401;
	BIT_VEC cppVar_1402;
	bool cppVar_1403;
	BIT_VEC cppVar_1404;
	BIT_VEC cppVar_1405;
	BIT_VEC cppVar_1406;
	BIT_VEC cppVar_1407;
	BIT_VEC cppVar_1408;
	BIT_VEC cppVar_1409;
	BIT_VEC cppVar_1410;
	BIT_VEC cppVar_1411;
	BIT_VEC cppVar_1412;
	BIT_VEC cppVar_1413;
	BIT_VEC cppVar_1415;
	BIT_VEC cppVar_1416;
	bool cppVar_1417;
	BIT_VEC cppVar_1418;
	BIT_VEC cppVar_1419;
	BIT_VEC cppVar_1420;
	BIT_VEC cppVar_1421;
	BIT_VEC cppVar_1422;
	BIT_VEC cppVar_1423;
	BIT_VEC cppVar_1424;
	BIT_VEC cppVar_1425;
	BIT_VEC cppVar_1426;
	BIT_VEC cppVar_1427;
	BIT_VEC cppVar_1429;
	BIT_VEC cppVar_1430;
	bool cppVar_1431;
	BIT_VEC cppVar_1432;
	BIT_VEC cppVar_1433;
	BIT_VEC cppVar_1434;
	BIT_VEC cppVar_1435;
	BIT_VEC cppVar_1436;
	BIT_VEC cppVar_1437;
	BIT_VEC cppVar_1438;
	BIT_VEC cppVar_1439;
	BIT_VEC cppVar_1440;
	BIT_VEC cppVar_1441;
	BIT_VEC cppVar_1443;
	BIT_VEC cppVar_1444;
	bool cppVar_1445;
	BIT_VEC cppVar_1446;
	BIT_VEC cppVar_1447;
	BIT_VEC cppVar_1448;
	BIT_VEC cppVar_1449;
	BIT_VEC cppVar_1450;
	BIT_VEC cppVar_1451;
	BIT_VEC cppVar_1452;
	BIT_VEC cppVar_1453;
	BIT_VEC cppVar_1454;
	BIT_VEC cppVar_1455;
	BIT_VEC cppVar_1457;
	BIT_VEC cppVar_1458;
	bool cppVar_1459;
	BIT_VEC cppVar_1460;
	BIT_VEC cppVar_1461;
	BIT_VEC cppVar_1462;
	BIT_VEC cppVar_1463;
	BIT_VEC cppVar_1464;
	BIT_VEC cppVar_1465;
	BIT_VEC cppVar_1466;
	BIT_VEC cppVar_1467;
	BIT_VEC cppVar_1468;
	BIT_VEC cppVar_1469;
	BIT_VEC cppVar_1471;
	BIT_VEC cppVar_1472;
	bool cppVar_1473;
	BIT_VEC cppVar_1474;
	BIT_VEC cppVar_1475;
	BIT_VEC cppVar_1476;
	BIT_VEC cppVar_1477;
	BIT_VEC cppVar_1478;
	BIT_VEC cppVar_1479;
	BIT_VEC cppVar_1480;
	BIT_VEC cppVar_1481;
	BIT_VEC cppVar_1482;
	BIT_VEC cppVar_1483;
	BIT_VEC cppVar_1484;
	BIT_VEC cppVar_1486;
	BIT_VEC cppVar_1487;
	bool cppVar_1488;
	BIT_VEC cppVar_1489;
	BIT_VEC cppVar_1490;
	BIT_VEC cppVar_1491;
	BIT_VEC cppVar_1492;
	BIT_VEC cppVar_1493;
	BIT_VEC cppVar_1494;
	BIT_VEC cppVar_1495;
	BIT_VEC cppVar_1496;
	BIT_VEC cppVar_1497;
	BIT_VEC cppVar_1498;
	BIT_VEC cppVar_1499;
	BIT_VEC cppVar_1501;
	BIT_VEC cppVar_1502;
	bool cppVar_1503;
	BIT_VEC cppVar_1505;
	BIT_VEC cppVar_1506;
	BIT_VEC cppVar_1507;
	BIT_VEC cppVar_1508;
	BIT_VEC cppVar_1509;
	bool cppVar_1510;
	BIT_VEC cppVar_1511;
	BIT_VEC cppVar_1512;
	BIT_VEC cppVar_1513;
	BIT_VEC cppVar_1515;
	BIT_VEC cppVar_1516;
	BIT_VEC cppVar_1517;
	bool cppVar_1518;
	BIT_VEC cppVar_1520;
	BIT_VEC cppVar_1521;
	BIT_VEC cppVar_1522;
	bool cppVar_1523;
	BIT_VEC cppVar_1525;
	BIT_VEC cppVar_1526;
	BIT_VEC cppVar_1527;
	bool cppVar_1528;
	BIT_VEC cppVar_1530;
	BIT_VEC cppVar_1531;
	BIT_VEC cppVar_1532;
	bool cppVar_1533;
	BIT_VEC cppVar_1535;
	BIT_VEC cppVar_1536;
	BIT_VEC cppVar_1537;
	bool cppVar_1538;
	BIT_VEC cppVar_1540;
	BIT_VEC cppVar_1541;
	BIT_VEC cppVar_1542;
	bool cppVar_1543;
	BIT_VEC cppVar_1545;
	BIT_VEC cppVar_1546;
	BIT_VEC cppVar_1547;
	bool cppVar_1548;
	BIT_VEC cppVar_1550;
	BIT_VEC cppVar_1551;
	BIT_VEC cppVar_1552;
	bool cppVar_1553;
	BIT_VEC cppVar_1555;
	BIT_VEC cppVar_1556;
	BIT_VEC cppVar_1557;
	bool cppVar_1558;
	BIT_VEC cppVar_1560;
	BIT_VEC cppVar_1561;
	BIT_VEC cppVar_1562;
	bool cppVar_1563;
	BIT_VEC cppVar_1565;
	BIT_VEC cppVar_1566;
	BIT_VEC cppVar_1567;
	bool cppVar_1568;
	BIT_VEC cppVar_1570;
	BIT_VEC cppVar_1571;
	BIT_VEC cppVar_1572;
	bool cppVar_1573;
	BIT_VEC cppVar_1575;
	BIT_VEC cppVar_1576;
	BIT_VEC cppVar_1577;
	bool cppVar_1578;
	BIT_VEC cppVar_1580;
	BIT_VEC cppVar_1581;
	BIT_VEC cppVar_1582;
	bool cppVar_1583;
	BIT_VEC cppVar_1585;
	BIT_VEC cppVar_1586;
	BIT_VEC cppVar_1587;
	bool cppVar_1588;
	BIT_VEC cppVar_1590;
	BIT_VEC cppVar_1591;
	BIT_VEC cppVar_1592;
	bool cppVar_1593;
	BIT_VEC cppVar_1595;
	BIT_VEC cppVar_1596;
	BIT_VEC cppVar_1597;
	bool cppVar_1598;
	BIT_VEC cppVar_1600;
	BIT_VEC cppVar_1601;
	BIT_VEC cppVar_1602;
	bool cppVar_1603;
	BIT_VEC cppVar_1605;
	BIT_VEC cppVar_1606;
	BIT_VEC cppVar_1607;
	bool cppVar_1608;
	BIT_VEC cppVar_1610;
	BIT_VEC cppVar_1611;
	BIT_VEC cppVar_1612;
	bool cppVar_1613;
	BIT_VEC cppVar_1615;
	BIT_VEC cppVar_1616;
	BIT_VEC cppVar_1617;
	bool cppVar_1618;
	BIT_VEC cppVar_1619;
	BIT_VEC cppVar_1614;
	BIT_VEC cppVar_1609;
	BIT_VEC cppVar_1604;
	BIT_VEC cppVar_1599;
	BIT_VEC cppVar_1594;
	BIT_VEC cppVar_1589;
	BIT_VEC cppVar_1584;
	BIT_VEC cppVar_1579;
	BIT_VEC cppVar_1574;
	BIT_VEC cppVar_1569;
	BIT_VEC cppVar_1564;
	BIT_VEC cppVar_1559;
	BIT_VEC cppVar_1554;
	BIT_VEC cppVar_1549;
	BIT_VEC cppVar_1544;
	BIT_VEC cppVar_1539;
	BIT_VEC cppVar_1534;
	BIT_VEC cppVar_1529;
	BIT_VEC cppVar_1524;
	BIT_VEC cppVar_1519;
	BIT_VEC cppVar_1514;
	BIT_VEC cppVar_1504;
	BIT_VEC cppVar_1620;
	BIT_VEC cppVar_1621;
	BIT_VEC cppVar_1622;
	BIT_VEC cppVar_1623;
	BIT_VEC cppVar_1625;
	BIT_VEC cppVar_1626;
	bool cppVar_1627;
	BIT_VEC cppVar_1628;
	BIT_VEC cppVar_1629;
	BIT_VEC cppVar_1630;
	BIT_VEC cppVar_1631;
	BIT_VEC cppVar_1632;
	BIT_VEC cppVar_1633;
	BIT_VEC cppVar_1634;
	BIT_VEC cppVar_1636;
	BIT_VEC cppVar_1637;
	bool cppVar_1638;
	BIT_VEC cppVar_1639;
	BIT_VEC cppVar_1640;
	BIT_VEC cppVar_1641;
	BIT_VEC cppVar_1642;
	BIT_VEC cppVar_1644;
	BIT_VEC cppVar_1645;
	bool cppVar_1646;
	BIT_VEC cppVar_1648;
	bool cppVar_1649;
	BIT_VEC cppVar_1650;
	BIT_VEC cppVar_1651;
	BIT_VEC cppVar_1647;
	BIT_VEC cppVar_1653;
	BIT_VEC cppVar_1654;
	bool cppVar_1655;
	BIT_VEC cppVar_1656;
	BIT_VEC cppVar_1657;
	BIT_VEC cppVar_1658;
	BIT_VEC cppVar_1659;
	BIT_VEC cppVar_1660;
	BIT_VEC cppVar_1662;
	BIT_VEC cppVar_1663;
	bool cppVar_1664;
	BIT_VEC cppVar_1665;
	BIT_VEC cppVar_1666;
	BIT_VEC cppVar_1667;
	BIT_VEC cppVar_1669;
	BIT_VEC cppVar_1670;
	bool cppVar_1671;
	BIT_VEC cppVar_1672;
	BIT_VEC cppVar_1673;
	BIT_VEC cppVar_1674;
	BIT_VEC cppVar_1675;
	BIT_VEC cppVar_1676;
	BIT_VEC cppVar_1677;
	BIT_VEC cppVar_1678;
	BIT_VEC cppVar_1680;
	BIT_VEC cppVar_1681;
	bool cppVar_1682;
	BIT_VEC cppVar_1683;
	BIT_VEC cppVar_1684;
	BIT_VEC cppVar_1685;
	BIT_VEC cppVar_1686;
	BIT_VEC cppVar_1687;
	BIT_VEC cppVar_1688;
	BIT_VEC cppVar_1689;
	BIT_VEC cppVar_1691;
	BIT_VEC cppVar_1692;
	bool cppVar_1693;
	BIT_VEC cppVar_1694;
	BIT_VEC cppVar_1695;
	BIT_VEC cppVar_1696;
	BIT_VEC cppVar_1697;
	BIT_VEC cppVar_1698;
	BIT_VEC cppVar_1699;
	BIT_VEC cppVar_1700;
	BIT_VEC cppVar_1702;
	BIT_VEC cppVar_1703;
	bool cppVar_1704;
	BIT_VEC cppVar_1705;
	BIT_VEC cppVar_1706;
	BIT_VEC cppVar_1707;
	BIT_VEC cppVar_1708;
	BIT_VEC cppVar_1709;
	BIT_VEC cppVar_1710;
	BIT_VEC cppVar_1711;
	BIT_VEC cppVar_1713;
	BIT_VEC cppVar_1714;
	bool cppVar_1715;
	BIT_VEC cppVar_1716;
	BIT_VEC cppVar_1717;
	BIT_VEC cppVar_1718;
	BIT_VEC cppVar_1719;
	BIT_VEC cppVar_1720;
	BIT_VEC cppVar_1721;
	BIT_VEC cppVar_1722;
	BIT_VEC cppVar_1724;
	BIT_VEC cppVar_1725;
	bool cppVar_1726;
	BIT_VEC cppVar_1727;
	BIT_VEC cppVar_1728;
	BIT_VEC cppVar_1729;
	BIT_VEC cppVar_1730;
	BIT_VEC cppVar_1731;
	BIT_VEC cppVar_1732;
	BIT_VEC cppVar_1733;
	BIT_VEC cppVar_1735;
	BIT_VEC cppVar_1736;
	bool cppVar_1737;
	BIT_VEC cppVar_1738;
	BIT_VEC cppVar_1739;
	BIT_VEC cppVar_1740;
	BIT_VEC cppVar_1741;
	BIT_VEC cppVar_1742;
	BIT_VEC cppVar_1743;
	BIT_VEC cppVar_1744;
	BIT_VEC cppVar_1746;
	BIT_VEC cppVar_1747;
	bool cppVar_1748;
	BIT_VEC cppVar_1749;
	BIT_VEC cppVar_1750;
	BIT_VEC cppVar_1751;
	BIT_VEC cppVar_1752;
	BIT_VEC cppVar_1753;
	BIT_VEC cppVar_1754;
	BIT_VEC cppVar_1755;
	BIT_VEC cppVar_1757;
	BIT_VEC cppVar_1758;
	bool cppVar_1759;
	BIT_VEC cppVar_1760;
	BIT_VEC cppVar_1761;
	BIT_VEC cppVar_1762;
	BIT_VEC cppVar_1763;
	BIT_VEC cppVar_1764;
	BIT_VEC cppVar_1765;
	BIT_VEC cppVar_1766;
	BIT_VEC cppVar_1767;
	BIT_VEC cppVar_1769;
	BIT_VEC cppVar_1770;
	bool cppVar_1771;
	BIT_VEC cppVar_1772;
	BIT_VEC cppVar_1773;
	BIT_VEC cppVar_1774;
	BIT_VEC cppVar_1775;
	BIT_VEC cppVar_1776;
	BIT_VEC cppVar_1777;
	BIT_VEC cppVar_1778;
	BIT_VEC cppVar_1779;
	BIT_VEC cppVar_1781;
	BIT_VEC cppVar_1782;
	bool cppVar_1783;
	BIT_VEC cppVar_1785;
	BIT_VEC cppVar_1786;
	BIT_VEC cppVar_1787;
	BIT_VEC cppVar_1788;
	BIT_VEC cppVar_1789;
	bool cppVar_1790;
	BIT_VEC cppVar_1791;
	BIT_VEC cppVar_1792;
	BIT_VEC cppVar_1793;
	BIT_VEC cppVar_1795;
	BIT_VEC cppVar_1796;
	BIT_VEC cppVar_1797;
	bool cppVar_1798;
	BIT_VEC cppVar_1800;
	BIT_VEC cppVar_1801;
	BIT_VEC cppVar_1802;
	bool cppVar_1803;
	BIT_VEC cppVar_1805;
	BIT_VEC cppVar_1806;
	BIT_VEC cppVar_1807;
	bool cppVar_1808;
	BIT_VEC cppVar_1810;
	BIT_VEC cppVar_1811;
	BIT_VEC cppVar_1812;
	bool cppVar_1813;
	BIT_VEC cppVar_1815;
	BIT_VEC cppVar_1816;
	BIT_VEC cppVar_1817;
	bool cppVar_1818;
	BIT_VEC cppVar_1820;
	BIT_VEC cppVar_1821;
	BIT_VEC cppVar_1822;
	bool cppVar_1823;
	BIT_VEC cppVar_1825;
	BIT_VEC cppVar_1826;
	BIT_VEC cppVar_1827;
	bool cppVar_1828;
	BIT_VEC cppVar_1830;
	BIT_VEC cppVar_1831;
	BIT_VEC cppVar_1832;
	bool cppVar_1833;
	BIT_VEC cppVar_1835;
	BIT_VEC cppVar_1836;
	BIT_VEC cppVar_1837;
	bool cppVar_1838;
	BIT_VEC cppVar_1840;
	BIT_VEC cppVar_1841;
	BIT_VEC cppVar_1842;
	bool cppVar_1843;
	BIT_VEC cppVar_1845;
	BIT_VEC cppVar_1846;
	BIT_VEC cppVar_1847;
	bool cppVar_1848;
	BIT_VEC cppVar_1850;
	BIT_VEC cppVar_1851;
	BIT_VEC cppVar_1852;
	bool cppVar_1853;
	BIT_VEC cppVar_1855;
	BIT_VEC cppVar_1856;
	BIT_VEC cppVar_1857;
	bool cppVar_1858;
	BIT_VEC cppVar_1860;
	BIT_VEC cppVar_1861;
	BIT_VEC cppVar_1862;
	bool cppVar_1863;
	BIT_VEC cppVar_1865;
	BIT_VEC cppVar_1866;
	BIT_VEC cppVar_1867;
	bool cppVar_1868;
	BIT_VEC cppVar_1870;
	BIT_VEC cppVar_1871;
	BIT_VEC cppVar_1872;
	bool cppVar_1873;
	BIT_VEC cppVar_1875;
	BIT_VEC cppVar_1876;
	BIT_VEC cppVar_1877;
	bool cppVar_1878;
	BIT_VEC cppVar_1880;
	BIT_VEC cppVar_1881;
	BIT_VEC cppVar_1882;
	bool cppVar_1883;
	BIT_VEC cppVar_1885;
	BIT_VEC cppVar_1886;
	BIT_VEC cppVar_1887;
	bool cppVar_1888;
	BIT_VEC cppVar_1890;
	BIT_VEC cppVar_1891;
	BIT_VEC cppVar_1892;
	bool cppVar_1893;
	BIT_VEC cppVar_1895;
	BIT_VEC cppVar_1896;
	BIT_VEC cppVar_1897;
	bool cppVar_1898;
	BIT_VEC cppVar_1899;
	BIT_VEC cppVar_1894;
	BIT_VEC cppVar_1889;
	BIT_VEC cppVar_1884;
	BIT_VEC cppVar_1879;
	BIT_VEC cppVar_1874;
	BIT_VEC cppVar_1869;
	BIT_VEC cppVar_1864;
	BIT_VEC cppVar_1859;
	BIT_VEC cppVar_1854;
	BIT_VEC cppVar_1849;
	BIT_VEC cppVar_1844;
	BIT_VEC cppVar_1839;
	BIT_VEC cppVar_1834;
	BIT_VEC cppVar_1829;
	BIT_VEC cppVar_1824;
	BIT_VEC cppVar_1819;
	BIT_VEC cppVar_1814;
	BIT_VEC cppVar_1809;
	BIT_VEC cppVar_1804;
	BIT_VEC cppVar_1799;
	BIT_VEC cppVar_1794;
	BIT_VEC cppVar_1784;
	BIT_VEC cppVar_1900;
	BIT_VEC cppVar_1902;
	BIT_VEC cppVar_1903;
	bool cppVar_1904;
	BIT_VEC cppVar_1905;
	BIT_VEC cppVar_1906;
	BIT_VEC cppVar_1907;
	BIT_VEC cppVar_1908;
	BIT_VEC cppVar_1910;
	BIT_VEC cppVar_1911;
	bool cppVar_1912;
	BIT_VEC cppVar_1913;
	BIT_VEC cppVar_1914;
	BIT_VEC cppVar_1915;
	BIT_VEC cppVar_1916;
	BIT_VEC cppVar_1917;
	BIT_VEC cppVar_1918;
	BIT_VEC cppVar_1919;
	BIT_VEC cppVar_1921;
	BIT_VEC cppVar_1922;
	bool cppVar_1923;
	BIT_VEC cppVar_1924;
	BIT_VEC cppVar_1925;
	BIT_VEC cppVar_1926;
	BIT_VEC cppVar_1927;
	BIT_VEC cppVar_1928;
	BIT_VEC cppVar_1929;
	BIT_VEC cppVar_1930;
	BIT_VEC cppVar_1932;
	BIT_VEC cppVar_1933;
	bool cppVar_1934;
	BIT_VEC cppVar_1935;
	BIT_VEC cppVar_1936;
	BIT_VEC cppVar_1937;
	BIT_VEC cppVar_1938;
	BIT_VEC cppVar_1939;
	BIT_VEC cppVar_1940;
	BIT_VEC cppVar_1941;
	BIT_VEC cppVar_1943;
	BIT_VEC cppVar_1944;
	bool cppVar_1945;
	BIT_VEC cppVar_1946;
	BIT_VEC cppVar_1947;
	BIT_VEC cppVar_1948;
	BIT_VEC cppVar_1949;
	BIT_VEC cppVar_1950;
	BIT_VEC cppVar_1951;
	BIT_VEC cppVar_1952;
	BIT_VEC cppVar_1954;
	BIT_VEC cppVar_1955;
	bool cppVar_1956;
	BIT_VEC cppVar_1957;
	BIT_VEC cppVar_1958;
	BIT_VEC cppVar_1959;
	BIT_VEC cppVar_1960;
	BIT_VEC cppVar_1961;
	BIT_VEC cppVar_1962;
	BIT_VEC cppVar_1963;
	BIT_VEC cppVar_1965;
	BIT_VEC cppVar_1966;
	bool cppVar_1967;
	BIT_VEC cppVar_1968;
	BIT_VEC cppVar_1969;
	BIT_VEC cppVar_1970;
	BIT_VEC cppVar_1971;
	BIT_VEC cppVar_1972;
	BIT_VEC cppVar_1973;
	BIT_VEC cppVar_1974;
	BIT_VEC cppVar_1976;
	BIT_VEC cppVar_1977;
	bool cppVar_1978;
	BIT_VEC cppVar_1979;
	BIT_VEC cppVar_1980;
	BIT_VEC cppVar_1981;
	BIT_VEC cppVar_1982;
	BIT_VEC cppVar_1983;
	BIT_VEC cppVar_1984;
	BIT_VEC cppVar_1985;
	BIT_VEC cppVar_1987;
	BIT_VEC cppVar_1988;
	bool cppVar_1989;
	BIT_VEC cppVar_1990;
	BIT_VEC cppVar_1991;
	BIT_VEC cppVar_1992;
	BIT_VEC cppVar_1993;
	BIT_VEC cppVar_1994;
	BIT_VEC cppVar_1995;
	BIT_VEC cppVar_1996;
	BIT_VEC cppVar_1998;
	BIT_VEC cppVar_1999;
	bool cppVar_2000;
	BIT_VEC cppVar_2001;
	BIT_VEC cppVar_2002;
	BIT_VEC cppVar_2003;
	BIT_VEC cppVar_2004;
	BIT_VEC cppVar_2005;
	BIT_VEC cppVar_2006;
	BIT_VEC cppVar_2007;
	BIT_VEC cppVar_2008;
	BIT_VEC cppVar_2010;
	BIT_VEC cppVar_2011;
	bool cppVar_2012;
	BIT_VEC cppVar_2013;
	BIT_VEC cppVar_2014;
	BIT_VEC cppVar_2015;
	BIT_VEC cppVar_2016;
	BIT_VEC cppVar_2017;
	BIT_VEC cppVar_2018;
	BIT_VEC cppVar_2019;
	BIT_VEC cppVar_2020;
	BIT_VEC cppVar_2022;
	BIT_VEC cppVar_2023;
	bool cppVar_2024;
	BIT_VEC cppVar_2026;
	BIT_VEC cppVar_2027;
	BIT_VEC cppVar_2028;
	BIT_VEC cppVar_2029;
	BIT_VEC cppVar_2030;
	bool cppVar_2031;
	BIT_VEC cppVar_2032;
	BIT_VEC cppVar_2033;
	BIT_VEC cppVar_2034;
	BIT_VEC cppVar_2036;
	BIT_VEC cppVar_2037;
	BIT_VEC cppVar_2038;
	bool cppVar_2039;
	BIT_VEC cppVar_2041;
	BIT_VEC cppVar_2042;
	BIT_VEC cppVar_2043;
	bool cppVar_2044;
	BIT_VEC cppVar_2046;
	BIT_VEC cppVar_2047;
	BIT_VEC cppVar_2048;
	bool cppVar_2049;
	BIT_VEC cppVar_2051;
	BIT_VEC cppVar_2052;
	BIT_VEC cppVar_2053;
	bool cppVar_2054;
	BIT_VEC cppVar_2056;
	BIT_VEC cppVar_2057;
	BIT_VEC cppVar_2058;
	bool cppVar_2059;
	BIT_VEC cppVar_2061;
	BIT_VEC cppVar_2062;
	BIT_VEC cppVar_2063;
	bool cppVar_2064;
	BIT_VEC cppVar_2066;
	BIT_VEC cppVar_2067;
	BIT_VEC cppVar_2068;
	bool cppVar_2069;
	BIT_VEC cppVar_2071;
	BIT_VEC cppVar_2072;
	BIT_VEC cppVar_2073;
	bool cppVar_2074;
	BIT_VEC cppVar_2076;
	BIT_VEC cppVar_2077;
	BIT_VEC cppVar_2078;
	bool cppVar_2079;
	BIT_VEC cppVar_2081;
	BIT_VEC cppVar_2082;
	BIT_VEC cppVar_2083;
	bool cppVar_2084;
	BIT_VEC cppVar_2086;
	BIT_VEC cppVar_2087;
	BIT_VEC cppVar_2088;
	bool cppVar_2089;
	BIT_VEC cppVar_2091;
	BIT_VEC cppVar_2092;
	BIT_VEC cppVar_2093;
	bool cppVar_2094;
	BIT_VEC cppVar_2096;
	BIT_VEC cppVar_2097;
	BIT_VEC cppVar_2098;
	bool cppVar_2099;
	BIT_VEC cppVar_2101;
	BIT_VEC cppVar_2102;
	BIT_VEC cppVar_2103;
	bool cppVar_2104;
	BIT_VEC cppVar_2106;
	BIT_VEC cppVar_2107;
	BIT_VEC cppVar_2108;
	bool cppVar_2109;
	BIT_VEC cppVar_2111;
	BIT_VEC cppVar_2112;
	BIT_VEC cppVar_2113;
	bool cppVar_2114;
	BIT_VEC cppVar_2116;
	BIT_VEC cppVar_2117;
	BIT_VEC cppVar_2118;
	bool cppVar_2119;
	BIT_VEC cppVar_2121;
	BIT_VEC cppVar_2122;
	BIT_VEC cppVar_2123;
	bool cppVar_2124;
	BIT_VEC cppVar_2126;
	BIT_VEC cppVar_2127;
	BIT_VEC cppVar_2128;
	bool cppVar_2129;
	BIT_VEC cppVar_2131;
	BIT_VEC cppVar_2132;
	BIT_VEC cppVar_2133;
	bool cppVar_2134;
	BIT_VEC cppVar_2136;
	BIT_VEC cppVar_2137;
	BIT_VEC cppVar_2138;
	bool cppVar_2139;
	BIT_VEC cppVar_2140;
	BIT_VEC cppVar_2135;
	BIT_VEC cppVar_2130;
	BIT_VEC cppVar_2125;
	BIT_VEC cppVar_2120;
	BIT_VEC cppVar_2115;
	BIT_VEC cppVar_2110;
	BIT_VEC cppVar_2105;
	BIT_VEC cppVar_2100;
	BIT_VEC cppVar_2095;
	BIT_VEC cppVar_2090;
	BIT_VEC cppVar_2085;
	BIT_VEC cppVar_2080;
	BIT_VEC cppVar_2075;
	BIT_VEC cppVar_2070;
	BIT_VEC cppVar_2065;
	BIT_VEC cppVar_2060;
	BIT_VEC cppVar_2055;
	BIT_VEC cppVar_2050;
	BIT_VEC cppVar_2045;
	BIT_VEC cppVar_2040;
	BIT_VEC cppVar_2035;
	BIT_VEC cppVar_2025;
	BIT_VEC cppVar_2141;
	BIT_VEC cppVar_2143;
	BIT_VEC cppVar_2144;
	bool cppVar_2145;
	BIT_VEC cppVar_2146;
	BIT_VEC cppVar_2147;
	BIT_VEC cppVar_2148;
	BIT_VEC cppVar_2149;
	BIT_VEC cppVar_2151;
	BIT_VEC cppVar_2152;
	bool cppVar_2153;
	BIT_VEC cppVar_2154;
	BIT_VEC cppVar_2155;
	BIT_VEC cppVar_2156;
	BIT_VEC cppVar_2157;
	BIT_VEC cppVar_2158;
	BIT_VEC cppVar_2159;
	BIT_VEC cppVar_2160;
	BIT_VEC cppVar_2162;
	BIT_VEC cppVar_2163;
	bool cppVar_2164;
	BIT_VEC cppVar_2165;
	BIT_VEC cppVar_2166;
	BIT_VEC cppVar_2167;
	BIT_VEC cppVar_2168;
	BIT_VEC cppVar_2169;
	BIT_VEC cppVar_2170;
	BIT_VEC cppVar_2171;
	BIT_VEC cppVar_2173;
	BIT_VEC cppVar_2174;
	bool cppVar_2175;
	BIT_VEC cppVar_2176;
	BIT_VEC cppVar_2177;
	BIT_VEC cppVar_2178;
	BIT_VEC cppVar_2179;
	BIT_VEC cppVar_2180;
	BIT_VEC cppVar_2181;
	BIT_VEC cppVar_2182;
	BIT_VEC cppVar_2184;
	BIT_VEC cppVar_2185;
	bool cppVar_2186;
	BIT_VEC cppVar_2187;
	BIT_VEC cppVar_2188;
	BIT_VEC cppVar_2189;
	BIT_VEC cppVar_2190;
	BIT_VEC cppVar_2191;
	BIT_VEC cppVar_2192;
	BIT_VEC cppVar_2193;
	BIT_VEC cppVar_2195;
	BIT_VEC cppVar_2196;
	bool cppVar_2197;
	BIT_VEC cppVar_2198;
	BIT_VEC cppVar_2199;
	BIT_VEC cppVar_2200;
	BIT_VEC cppVar_2201;
	BIT_VEC cppVar_2202;
	BIT_VEC cppVar_2203;
	BIT_VEC cppVar_2204;
	BIT_VEC cppVar_2206;
	BIT_VEC cppVar_2207;
	bool cppVar_2208;
	BIT_VEC cppVar_2209;
	BIT_VEC cppVar_2210;
	BIT_VEC cppVar_2211;
	BIT_VEC cppVar_2212;
	BIT_VEC cppVar_2213;
	BIT_VEC cppVar_2214;
	BIT_VEC cppVar_2215;
	BIT_VEC cppVar_2217;
	BIT_VEC cppVar_2218;
	bool cppVar_2219;
	BIT_VEC cppVar_2220;
	BIT_VEC cppVar_2221;
	BIT_VEC cppVar_2222;
	BIT_VEC cppVar_2223;
	BIT_VEC cppVar_2224;
	BIT_VEC cppVar_2225;
	BIT_VEC cppVar_2226;
	BIT_VEC cppVar_2228;
	BIT_VEC cppVar_2229;
	bool cppVar_2230;
	BIT_VEC cppVar_2231;
	BIT_VEC cppVar_2232;
	BIT_VEC cppVar_2233;
	BIT_VEC cppVar_2234;
	BIT_VEC cppVar_2235;
	BIT_VEC cppVar_2236;
	BIT_VEC cppVar_2237;
	BIT_VEC cppVar_2239;
	BIT_VEC cppVar_2240;
	bool cppVar_2241;
	BIT_VEC cppVar_2242;
	BIT_VEC cppVar_2243;
	BIT_VEC cppVar_2244;
	BIT_VEC cppVar_2245;
	BIT_VEC cppVar_2246;
	BIT_VEC cppVar_2247;
	BIT_VEC cppVar_2248;
	BIT_VEC cppVar_2249;
	BIT_VEC cppVar_2251;
	BIT_VEC cppVar_2252;
	bool cppVar_2253;
	BIT_VEC cppVar_2254;
	BIT_VEC cppVar_2255;
	BIT_VEC cppVar_2256;
	BIT_VEC cppVar_2257;
	BIT_VEC cppVar_2258;
	BIT_VEC cppVar_2259;
	BIT_VEC cppVar_2260;
	BIT_VEC cppVar_2261;
	BIT_VEC cppVar_2263;
	BIT_VEC cppVar_2264;
	bool cppVar_2265;
	BIT_VEC cppVar_2267;
	BIT_VEC cppVar_2268;
	BIT_VEC cppVar_2269;
	BIT_VEC cppVar_2270;
	BIT_VEC cppVar_2271;
	bool cppVar_2272;
	BIT_VEC cppVar_2273;
	BIT_VEC cppVar_2274;
	BIT_VEC cppVar_2275;
	BIT_VEC cppVar_2277;
	BIT_VEC cppVar_2278;
	BIT_VEC cppVar_2279;
	bool cppVar_2280;
	BIT_VEC cppVar_2282;
	BIT_VEC cppVar_2283;
	BIT_VEC cppVar_2284;
	bool cppVar_2285;
	BIT_VEC cppVar_2287;
	BIT_VEC cppVar_2288;
	BIT_VEC cppVar_2289;
	bool cppVar_2290;
	BIT_VEC cppVar_2292;
	BIT_VEC cppVar_2293;
	BIT_VEC cppVar_2294;
	bool cppVar_2295;
	BIT_VEC cppVar_2297;
	BIT_VEC cppVar_2298;
	BIT_VEC cppVar_2299;
	bool cppVar_2300;
	BIT_VEC cppVar_2302;
	BIT_VEC cppVar_2303;
	BIT_VEC cppVar_2304;
	bool cppVar_2305;
	BIT_VEC cppVar_2307;
	BIT_VEC cppVar_2308;
	BIT_VEC cppVar_2309;
	bool cppVar_2310;
	BIT_VEC cppVar_2312;
	BIT_VEC cppVar_2313;
	BIT_VEC cppVar_2314;
	bool cppVar_2315;
	BIT_VEC cppVar_2317;
	BIT_VEC cppVar_2318;
	BIT_VEC cppVar_2319;
	bool cppVar_2320;
	BIT_VEC cppVar_2322;
	BIT_VEC cppVar_2323;
	BIT_VEC cppVar_2324;
	bool cppVar_2325;
	BIT_VEC cppVar_2327;
	BIT_VEC cppVar_2328;
	BIT_VEC cppVar_2329;
	bool cppVar_2330;
	BIT_VEC cppVar_2332;
	BIT_VEC cppVar_2333;
	BIT_VEC cppVar_2334;
	bool cppVar_2335;
	BIT_VEC cppVar_2337;
	BIT_VEC cppVar_2338;
	BIT_VEC cppVar_2339;
	bool cppVar_2340;
	BIT_VEC cppVar_2342;
	BIT_VEC cppVar_2343;
	BIT_VEC cppVar_2344;
	bool cppVar_2345;
	BIT_VEC cppVar_2347;
	BIT_VEC cppVar_2348;
	BIT_VEC cppVar_2349;
	bool cppVar_2350;
	BIT_VEC cppVar_2352;
	BIT_VEC cppVar_2353;
	BIT_VEC cppVar_2354;
	bool cppVar_2355;
	BIT_VEC cppVar_2357;
	BIT_VEC cppVar_2358;
	BIT_VEC cppVar_2359;
	bool cppVar_2360;
	BIT_VEC cppVar_2362;
	BIT_VEC cppVar_2363;
	BIT_VEC cppVar_2364;
	bool cppVar_2365;
	BIT_VEC cppVar_2367;
	BIT_VEC cppVar_2368;
	BIT_VEC cppVar_2369;
	bool cppVar_2370;
	BIT_VEC cppVar_2372;
	BIT_VEC cppVar_2373;
	BIT_VEC cppVar_2374;
	bool cppVar_2375;
	BIT_VEC cppVar_2377;
	BIT_VEC cppVar_2378;
	BIT_VEC cppVar_2379;
	bool cppVar_2380;
	BIT_VEC cppVar_2381;
	BIT_VEC cppVar_2376;
	BIT_VEC cppVar_2371;
	BIT_VEC cppVar_2366;
	BIT_VEC cppVar_2361;
	BIT_VEC cppVar_2356;
	BIT_VEC cppVar_2351;
	BIT_VEC cppVar_2346;
	BIT_VEC cppVar_2341;
	BIT_VEC cppVar_2336;
	BIT_VEC cppVar_2331;
	BIT_VEC cppVar_2326;
	BIT_VEC cppVar_2321;
	BIT_VEC cppVar_2316;
	BIT_VEC cppVar_2311;
	BIT_VEC cppVar_2306;
	BIT_VEC cppVar_2301;
	BIT_VEC cppVar_2296;
	BIT_VEC cppVar_2291;
	BIT_VEC cppVar_2286;
	BIT_VEC cppVar_2281;
	BIT_VEC cppVar_2276;
	BIT_VEC cppVar_2266;
	BIT_VEC cppVar_2382;
	BIT_VEC cppVar_2384;
	BIT_VEC cppVar_2385;
	bool cppVar_2386;
	BIT_VEC cppVar_2387;
	BIT_VEC cppVar_2388;
	BIT_VEC cppVar_2389;
	BIT_VEC cppVar_2390;
	BIT_VEC cppVar_2392;
	BIT_VEC cppVar_2393;
	bool cppVar_2394;
	BIT_VEC cppVar_2395;
	BIT_VEC cppVar_2396;
	BIT_VEC cppVar_2397;
	BIT_VEC cppVar_2398;
	BIT_VEC cppVar_2399;
	BIT_VEC cppVar_2400;
	BIT_VEC cppVar_2401;
	BIT_VEC cppVar_2402;
	BIT_VEC cppVar_2403;
	BIT_VEC cppVar_2404;
	BIT_VEC cppVar_2406;
	BIT_VEC cppVar_2407;
	bool cppVar_2408;
	BIT_VEC cppVar_2409;
	BIT_VEC cppVar_2410;
	BIT_VEC cppVar_2411;
	BIT_VEC cppVar_2412;
	BIT_VEC cppVar_2413;
	BIT_VEC cppVar_2414;
	BIT_VEC cppVar_2415;
	BIT_VEC cppVar_2416;
	BIT_VEC cppVar_2417;
	BIT_VEC cppVar_2418;
	BIT_VEC cppVar_2420;
	BIT_VEC cppVar_2421;
	bool cppVar_2422;
	BIT_VEC cppVar_2423;
	BIT_VEC cppVar_2424;
	BIT_VEC cppVar_2425;
	BIT_VEC cppVar_2426;
	BIT_VEC cppVar_2427;
	BIT_VEC cppVar_2428;
	BIT_VEC cppVar_2429;
	BIT_VEC cppVar_2430;
	BIT_VEC cppVar_2431;
	BIT_VEC cppVar_2432;
	BIT_VEC cppVar_2434;
	BIT_VEC cppVar_2435;
	bool cppVar_2436;
	BIT_VEC cppVar_2437;
	BIT_VEC cppVar_2438;
	BIT_VEC cppVar_2439;
	BIT_VEC cppVar_2440;
	BIT_VEC cppVar_2441;
	BIT_VEC cppVar_2442;
	BIT_VEC cppVar_2443;
	BIT_VEC cppVar_2444;
	BIT_VEC cppVar_2445;
	BIT_VEC cppVar_2446;
	BIT_VEC cppVar_2448;
	BIT_VEC cppVar_2449;
	bool cppVar_2450;
	BIT_VEC cppVar_2451;
	BIT_VEC cppVar_2452;
	BIT_VEC cppVar_2453;
	BIT_VEC cppVar_2454;
	BIT_VEC cppVar_2455;
	BIT_VEC cppVar_2456;
	BIT_VEC cppVar_2457;
	BIT_VEC cppVar_2458;
	BIT_VEC cppVar_2459;
	BIT_VEC cppVar_2460;
	BIT_VEC cppVar_2462;
	BIT_VEC cppVar_2463;
	bool cppVar_2464;
	BIT_VEC cppVar_2465;
	BIT_VEC cppVar_2466;
	BIT_VEC cppVar_2467;
	BIT_VEC cppVar_2468;
	BIT_VEC cppVar_2469;
	BIT_VEC cppVar_2470;
	BIT_VEC cppVar_2471;
	BIT_VEC cppVar_2472;
	BIT_VEC cppVar_2473;
	BIT_VEC cppVar_2474;
	BIT_VEC cppVar_2476;
	BIT_VEC cppVar_2477;
	bool cppVar_2478;
	BIT_VEC cppVar_2479;
	BIT_VEC cppVar_2480;
	BIT_VEC cppVar_2481;
	BIT_VEC cppVar_2482;
	BIT_VEC cppVar_2483;
	BIT_VEC cppVar_2484;
	BIT_VEC cppVar_2485;
	BIT_VEC cppVar_2486;
	BIT_VEC cppVar_2487;
	BIT_VEC cppVar_2488;
	BIT_VEC cppVar_2490;
	BIT_VEC cppVar_2491;
	bool cppVar_2492;
	BIT_VEC cppVar_2493;
	BIT_VEC cppVar_2494;
	BIT_VEC cppVar_2495;
	BIT_VEC cppVar_2496;
	BIT_VEC cppVar_2497;
	BIT_VEC cppVar_2498;
	BIT_VEC cppVar_2499;
	BIT_VEC cppVar_2500;
	BIT_VEC cppVar_2501;
	BIT_VEC cppVar_2502;
	BIT_VEC cppVar_2504;
	BIT_VEC cppVar_2505;
	bool cppVar_2506;
	BIT_VEC cppVar_2507;
	BIT_VEC cppVar_2508;
	BIT_VEC cppVar_2509;
	BIT_VEC cppVar_2510;
	BIT_VEC cppVar_2511;
	BIT_VEC cppVar_2512;
	BIT_VEC cppVar_2513;
	BIT_VEC cppVar_2514;
	BIT_VEC cppVar_2515;
	BIT_VEC cppVar_2516;
	BIT_VEC cppVar_2517;
	BIT_VEC cppVar_2519;
	BIT_VEC cppVar_2520;
	bool cppVar_2521;
	BIT_VEC cppVar_2522;
	BIT_VEC cppVar_2523;
	BIT_VEC cppVar_2524;
	BIT_VEC cppVar_2525;
	BIT_VEC cppVar_2526;
	BIT_VEC cppVar_2527;
	BIT_VEC cppVar_2528;
	BIT_VEC cppVar_2529;
	BIT_VEC cppVar_2530;
	BIT_VEC cppVar_2531;
	BIT_VEC cppVar_2532;
	BIT_VEC cppVar_2534;
	BIT_VEC cppVar_2535;
	bool cppVar_2536;
	BIT_VEC cppVar_2538;
	BIT_VEC cppVar_2539;
	BIT_VEC cppVar_2540;
	BIT_VEC cppVar_2541;
	BIT_VEC cppVar_2542;
	bool cppVar_2543;
	BIT_VEC cppVar_2544;
	BIT_VEC cppVar_2545;
	BIT_VEC cppVar_2546;
	BIT_VEC cppVar_2548;
	BIT_VEC cppVar_2549;
	BIT_VEC cppVar_2550;
	bool cppVar_2551;
	BIT_VEC cppVar_2553;
	BIT_VEC cppVar_2554;
	BIT_VEC cppVar_2555;
	bool cppVar_2556;
	BIT_VEC cppVar_2558;
	BIT_VEC cppVar_2559;
	BIT_VEC cppVar_2560;
	bool cppVar_2561;
	BIT_VEC cppVar_2563;
	BIT_VEC cppVar_2564;
	BIT_VEC cppVar_2565;
	bool cppVar_2566;
	BIT_VEC cppVar_2568;
	BIT_VEC cppVar_2569;
	BIT_VEC cppVar_2570;
	bool cppVar_2571;
	BIT_VEC cppVar_2573;
	BIT_VEC cppVar_2574;
	BIT_VEC cppVar_2575;
	bool cppVar_2576;
	BIT_VEC cppVar_2578;
	BIT_VEC cppVar_2579;
	BIT_VEC cppVar_2580;
	bool cppVar_2581;
	BIT_VEC cppVar_2583;
	BIT_VEC cppVar_2584;
	BIT_VEC cppVar_2585;
	bool cppVar_2586;
	BIT_VEC cppVar_2588;
	BIT_VEC cppVar_2589;
	BIT_VEC cppVar_2590;
	bool cppVar_2591;
	BIT_VEC cppVar_2593;
	BIT_VEC cppVar_2594;
	BIT_VEC cppVar_2595;
	bool cppVar_2596;
	BIT_VEC cppVar_2598;
	BIT_VEC cppVar_2599;
	BIT_VEC cppVar_2600;
	bool cppVar_2601;
	BIT_VEC cppVar_2603;
	BIT_VEC cppVar_2604;
	BIT_VEC cppVar_2605;
	bool cppVar_2606;
	BIT_VEC cppVar_2608;
	BIT_VEC cppVar_2609;
	BIT_VEC cppVar_2610;
	bool cppVar_2611;
	BIT_VEC cppVar_2613;
	BIT_VEC cppVar_2614;
	BIT_VEC cppVar_2615;
	bool cppVar_2616;
	BIT_VEC cppVar_2618;
	BIT_VEC cppVar_2619;
	BIT_VEC cppVar_2620;
	bool cppVar_2621;
	BIT_VEC cppVar_2623;
	BIT_VEC cppVar_2624;
	BIT_VEC cppVar_2625;
	bool cppVar_2626;
	BIT_VEC cppVar_2628;
	BIT_VEC cppVar_2629;
	BIT_VEC cppVar_2630;
	bool cppVar_2631;
	BIT_VEC cppVar_2633;
	BIT_VEC cppVar_2634;
	BIT_VEC cppVar_2635;
	bool cppVar_2636;
	BIT_VEC cppVar_2638;
	BIT_VEC cppVar_2639;
	BIT_VEC cppVar_2640;
	bool cppVar_2641;
	BIT_VEC cppVar_2643;
	BIT_VEC cppVar_2644;
	BIT_VEC cppVar_2645;
	bool cppVar_2646;
	BIT_VEC cppVar_2648;
	BIT_VEC cppVar_2649;
	BIT_VEC cppVar_2650;
	bool cppVar_2651;
	BIT_VEC cppVar_2652;
	BIT_VEC cppVar_2647;
	BIT_VEC cppVar_2642;
	BIT_VEC cppVar_2637;
	BIT_VEC cppVar_2632;
	BIT_VEC cppVar_2627;
	BIT_VEC cppVar_2622;
	BIT_VEC cppVar_2617;
	BIT_VEC cppVar_2612;
	BIT_VEC cppVar_2607;
	BIT_VEC cppVar_2602;
	BIT_VEC cppVar_2597;
	BIT_VEC cppVar_2592;
	BIT_VEC cppVar_2587;
	BIT_VEC cppVar_2582;
	BIT_VEC cppVar_2577;
	BIT_VEC cppVar_2572;
	BIT_VEC cppVar_2567;
	BIT_VEC cppVar_2562;
	BIT_VEC cppVar_2557;
	BIT_VEC cppVar_2552;
	BIT_VEC cppVar_2547;
	BIT_VEC cppVar_2537;
	BIT_VEC cppVar_2653;
	BIT_VEC cppVar_2654;
	BIT_VEC cppVar_2655;
	BIT_VEC cppVar_2656;
	BIT_VEC cppVar_2658;
	BIT_VEC cppVar_2659;
	bool cppVar_2660;
	BIT_VEC cppVar_2661;
	BIT_VEC cppVar_2662;
	BIT_VEC cppVar_2663;
	BIT_VEC cppVar_2664;
	BIT_VEC cppVar_2665;
	BIT_VEC cppVar_2666;
	BIT_VEC cppVar_2667;
	BIT_VEC cppVar_2669;
	BIT_VEC cppVar_2670;
	bool cppVar_2671;
	BIT_VEC cppVar_2672;
	BIT_VEC cppVar_2673;
	BIT_VEC cppVar_2674;
	BIT_VEC cppVar_2675;
	BIT_VEC cppVar_2677;
	BIT_VEC cppVar_2678;
	bool cppVar_2679;
	BIT_VEC cppVar_2680;
	BIT_VEC cppVar_2681;
	BIT_VEC cppVar_2682;
	BIT_VEC cppVar_2683;
	BIT_VEC cppVar_2684;
	BIT_VEC cppVar_2685;
	BIT_VEC cppVar_2686;
	BIT_VEC cppVar_2688;
	BIT_VEC cppVar_2689;
	bool cppVar_2690;
	BIT_VEC cppVar_2691;
	BIT_VEC cppVar_2692;
	BIT_VEC cppVar_2693;
	BIT_VEC cppVar_2694;
	BIT_VEC cppVar_2695;
	BIT_VEC cppVar_2696;
	BIT_VEC cppVar_2697;
	BIT_VEC cppVar_2699;
	BIT_VEC cppVar_2700;
	bool cppVar_2701;
	BIT_VEC cppVar_2702;
	BIT_VEC cppVar_2703;
	BIT_VEC cppVar_2704;
	BIT_VEC cppVar_2705;
	BIT_VEC cppVar_2706;
	BIT_VEC cppVar_2707;
	BIT_VEC cppVar_2708;
	BIT_VEC cppVar_2710;
	BIT_VEC cppVar_2711;
	bool cppVar_2712;
	BIT_VEC cppVar_2713;
	BIT_VEC cppVar_2714;
	BIT_VEC cppVar_2715;
	BIT_VEC cppVar_2716;
	BIT_VEC cppVar_2717;
	BIT_VEC cppVar_2718;
	BIT_VEC cppVar_2719;
	BIT_VEC cppVar_2721;
	BIT_VEC cppVar_2722;
	bool cppVar_2723;
	BIT_VEC cppVar_2724;
	BIT_VEC cppVar_2725;
	BIT_VEC cppVar_2726;
	BIT_VEC cppVar_2727;
	BIT_VEC cppVar_2728;
	BIT_VEC cppVar_2729;
	BIT_VEC cppVar_2730;
	BIT_VEC cppVar_2732;
	BIT_VEC cppVar_2733;
	bool cppVar_2734;
	BIT_VEC cppVar_2735;
	BIT_VEC cppVar_2736;
	BIT_VEC cppVar_2737;
	BIT_VEC cppVar_2738;
	BIT_VEC cppVar_2739;
	BIT_VEC cppVar_2740;
	BIT_VEC cppVar_2741;
	BIT_VEC cppVar_2743;
	BIT_VEC cppVar_2744;
	bool cppVar_2745;
	BIT_VEC cppVar_2746;
	BIT_VEC cppVar_2747;
	BIT_VEC cppVar_2748;
	BIT_VEC cppVar_2749;
	BIT_VEC cppVar_2750;
	BIT_VEC cppVar_2751;
	BIT_VEC cppVar_2752;
	BIT_VEC cppVar_2754;
	BIT_VEC cppVar_2755;
	bool cppVar_2756;
	BIT_VEC cppVar_2757;
	BIT_VEC cppVar_2758;
	BIT_VEC cppVar_2759;
	BIT_VEC cppVar_2760;
	BIT_VEC cppVar_2761;
	BIT_VEC cppVar_2762;
	BIT_VEC cppVar_2763;
	BIT_VEC cppVar_2765;
	BIT_VEC cppVar_2766;
	bool cppVar_2767;
	BIT_VEC cppVar_2768;
	BIT_VEC cppVar_2769;
	BIT_VEC cppVar_2770;
	BIT_VEC cppVar_2771;
	BIT_VEC cppVar_2772;
	BIT_VEC cppVar_2773;
	BIT_VEC cppVar_2774;
	BIT_VEC cppVar_2775;
	BIT_VEC cppVar_2777;
	BIT_VEC cppVar_2778;
	bool cppVar_2779;
	BIT_VEC cppVar_2780;
	BIT_VEC cppVar_2781;
	BIT_VEC cppVar_2782;
	BIT_VEC cppVar_2783;
	BIT_VEC cppVar_2784;
	BIT_VEC cppVar_2785;
	BIT_VEC cppVar_2786;
	BIT_VEC cppVar_2787;
	BIT_VEC cppVar_2789;
	BIT_VEC cppVar_2790;
	bool cppVar_2791;
	BIT_VEC cppVar_2793;
	BIT_VEC cppVar_2794;
	BIT_VEC cppVar_2795;
	BIT_VEC cppVar_2796;
	BIT_VEC cppVar_2797;
	bool cppVar_2798;
	BIT_VEC cppVar_2799;
	BIT_VEC cppVar_2800;
	BIT_VEC cppVar_2801;
	BIT_VEC cppVar_2803;
	BIT_VEC cppVar_2804;
	BIT_VEC cppVar_2805;
	bool cppVar_2806;
	BIT_VEC cppVar_2808;
	BIT_VEC cppVar_2809;
	BIT_VEC cppVar_2810;
	bool cppVar_2811;
	BIT_VEC cppVar_2813;
	BIT_VEC cppVar_2814;
	BIT_VEC cppVar_2815;
	bool cppVar_2816;
	BIT_VEC cppVar_2818;
	BIT_VEC cppVar_2819;
	BIT_VEC cppVar_2820;
	bool cppVar_2821;
	BIT_VEC cppVar_2823;
	BIT_VEC cppVar_2824;
	BIT_VEC cppVar_2825;
	bool cppVar_2826;
	BIT_VEC cppVar_2828;
	BIT_VEC cppVar_2829;
	BIT_VEC cppVar_2830;
	bool cppVar_2831;
	BIT_VEC cppVar_2833;
	BIT_VEC cppVar_2834;
	BIT_VEC cppVar_2835;
	bool cppVar_2836;
	BIT_VEC cppVar_2838;
	BIT_VEC cppVar_2839;
	BIT_VEC cppVar_2840;
	bool cppVar_2841;
	BIT_VEC cppVar_2843;
	BIT_VEC cppVar_2844;
	BIT_VEC cppVar_2845;
	bool cppVar_2846;
	BIT_VEC cppVar_2848;
	BIT_VEC cppVar_2849;
	BIT_VEC cppVar_2850;
	bool cppVar_2851;
	BIT_VEC cppVar_2853;
	BIT_VEC cppVar_2854;
	BIT_VEC cppVar_2855;
	bool cppVar_2856;
	BIT_VEC cppVar_2858;
	BIT_VEC cppVar_2859;
	BIT_VEC cppVar_2860;
	bool cppVar_2861;
	BIT_VEC cppVar_2863;
	BIT_VEC cppVar_2864;
	BIT_VEC cppVar_2865;
	bool cppVar_2866;
	BIT_VEC cppVar_2868;
	BIT_VEC cppVar_2869;
	BIT_VEC cppVar_2870;
	bool cppVar_2871;
	BIT_VEC cppVar_2873;
	BIT_VEC cppVar_2874;
	BIT_VEC cppVar_2875;
	bool cppVar_2876;
	BIT_VEC cppVar_2878;
	BIT_VEC cppVar_2879;
	BIT_VEC cppVar_2880;
	bool cppVar_2881;
	BIT_VEC cppVar_2883;
	BIT_VEC cppVar_2884;
	BIT_VEC cppVar_2885;
	bool cppVar_2886;
	BIT_VEC cppVar_2888;
	BIT_VEC cppVar_2889;
	BIT_VEC cppVar_2890;
	bool cppVar_2891;
	BIT_VEC cppVar_2893;
	BIT_VEC cppVar_2894;
	BIT_VEC cppVar_2895;
	bool cppVar_2896;
	BIT_VEC cppVar_2898;
	BIT_VEC cppVar_2899;
	BIT_VEC cppVar_2900;
	bool cppVar_2901;
	BIT_VEC cppVar_2903;
	BIT_VEC cppVar_2904;
	BIT_VEC cppVar_2905;
	bool cppVar_2906;
	BIT_VEC cppVar_2907;
	BIT_VEC cppVar_2902;
	BIT_VEC cppVar_2897;
	BIT_VEC cppVar_2892;
	BIT_VEC cppVar_2887;
	BIT_VEC cppVar_2882;
	BIT_VEC cppVar_2877;
	BIT_VEC cppVar_2872;
	BIT_VEC cppVar_2867;
	BIT_VEC cppVar_2862;
	BIT_VEC cppVar_2857;
	BIT_VEC cppVar_2852;
	BIT_VEC cppVar_2847;
	BIT_VEC cppVar_2842;
	BIT_VEC cppVar_2837;
	BIT_VEC cppVar_2832;
	BIT_VEC cppVar_2827;
	BIT_VEC cppVar_2822;
	BIT_VEC cppVar_2817;
	BIT_VEC cppVar_2812;
	BIT_VEC cppVar_2807;
	BIT_VEC cppVar_2802;
	BIT_VEC cppVar_2792;
	BIT_VEC cppVar_2908;
	BIT_VEC cppVar_2910;
	BIT_VEC cppVar_2911;
	bool cppVar_2912;
	BIT_VEC cppVar_2913;
	BIT_VEC cppVar_2914;
	BIT_VEC cppVar_2915;
	BIT_VEC cppVar_2916;
	BIT_VEC cppVar_2918;
	BIT_VEC cppVar_2919;
	bool cppVar_2920;
	BIT_VEC cppVar_2921;
	BIT_VEC cppVar_2923;
	BIT_VEC cppVar_2924;
	bool cppVar_2925;
	BIT_VEC cppVar_2926;
	BIT_VEC cppVar_2927;
	BIT_VEC cppVar_2929;
	BIT_VEC cppVar_2930;
	bool cppVar_2931;
	BIT_VEC cppVar_2932;
	BIT_VEC cppVar_2933;
	BIT_VEC cppVar_2934;
	BIT_VEC cppVar_2935;
	BIT_VEC cppVar_2937;
	BIT_VEC cppVar_2938;
	bool cppVar_2939;
	BIT_VEC cppVar_2940;
	BIT_VEC cppVar_2941;
	BIT_VEC cppVar_2943;
	BIT_VEC cppVar_2944;
	bool cppVar_2945;
	BIT_VEC cppVar_2946;
	BIT_VEC cppVar_2942;
	BIT_VEC cppVar_2936;
	BIT_VEC cppVar_2928;
	BIT_VEC cppVar_2922;
	BIT_VEC cppVar_2917;
	BIT_VEC cppVar_2909;
	BIT_VEC cppVar_2788;
	BIT_VEC cppVar_2776;
	BIT_VEC cppVar_2764;
	BIT_VEC cppVar_2753;
	BIT_VEC cppVar_2742;
	BIT_VEC cppVar_2731;
	BIT_VEC cppVar_2720;
	BIT_VEC cppVar_2709;
	BIT_VEC cppVar_2698;
	BIT_VEC cppVar_2687;
	BIT_VEC cppVar_2676;
	BIT_VEC cppVar_2668;
	BIT_VEC cppVar_2657;
	BIT_VEC cppVar_2533;
	BIT_VEC cppVar_2518;
	BIT_VEC cppVar_2503;
	BIT_VEC cppVar_2489;
	BIT_VEC cppVar_2475;
	BIT_VEC cppVar_2461;
	BIT_VEC cppVar_2447;
	BIT_VEC cppVar_2433;
	BIT_VEC cppVar_2419;
	BIT_VEC cppVar_2405;
	BIT_VEC cppVar_2391;
	BIT_VEC cppVar_2383;
	BIT_VEC cppVar_2262;
	BIT_VEC cppVar_2250;
	BIT_VEC cppVar_2238;
	BIT_VEC cppVar_2227;
	BIT_VEC cppVar_2216;
	BIT_VEC cppVar_2205;
	BIT_VEC cppVar_2194;
	BIT_VEC cppVar_2183;
	BIT_VEC cppVar_2172;
	BIT_VEC cppVar_2161;
	BIT_VEC cppVar_2150;
	BIT_VEC cppVar_2142;
	BIT_VEC cppVar_2021;
	BIT_VEC cppVar_2009;
	BIT_VEC cppVar_1997;
	BIT_VEC cppVar_1986;
	BIT_VEC cppVar_1975;
	BIT_VEC cppVar_1964;
	BIT_VEC cppVar_1953;
	BIT_VEC cppVar_1942;
	BIT_VEC cppVar_1931;
	BIT_VEC cppVar_1920;
	BIT_VEC cppVar_1909;
	BIT_VEC cppVar_1901;
	BIT_VEC cppVar_1780;
	BIT_VEC cppVar_1768;
	BIT_VEC cppVar_1756;
	BIT_VEC cppVar_1745;
	BIT_VEC cppVar_1734;
	BIT_VEC cppVar_1723;
	BIT_VEC cppVar_1712;
	BIT_VEC cppVar_1701;
	BIT_VEC cppVar_1690;
	BIT_VEC cppVar_1679;
	BIT_VEC cppVar_1668;
	BIT_VEC cppVar_1661;
	BIT_VEC cppVar_1652;
	BIT_VEC cppVar_1643;
	BIT_VEC cppVar_1635;
	BIT_VEC cppVar_1624;
	BIT_VEC cppVar_1500;
	BIT_VEC cppVar_1485;
	BIT_VEC cppVar_1470;
	BIT_VEC cppVar_1456;
	BIT_VEC cppVar_1442;
	BIT_VEC cppVar_1428;
	BIT_VEC cppVar_1414;
	BIT_VEC cppVar_1400;
	BIT_VEC cppVar_1386;
	BIT_VEC cppVar_1372;
	BIT_VEC cppVar_1358;
	BIT_VEC cppVar_1350;
	BIT_VEC cppVar_1343;
	BIT_VEC cppVar_1219;
	BIT_VEC cppVar_1204;
	BIT_VEC cppVar_1189;
	BIT_VEC cppVar_1041;
	BIT_VEC cppVar_893;
	BIT_VEC cppVar_745;
	BIT_VEC cppVar_597;
	BIT_VEC cppVar_449;
	BIT_VEC cppVar_435;
	BIT_VEC cppVar_425;
	BIT_VEC cppVar_277;
	BIT_VEC cppVar_221;
	BIT_VEC cppVar_207;
	BIT_VEC cppVar_193;
	BIT_VEC cppVar_181;
	BIT_VEC cppVar_176;
	BIT_VEC cppVar_32;
	BIT_VEC cppVar_27;
	cppVar_28 = ROM.rd(PC);
	cppVar_30 = (cppVar_28 == 244);
	if (cppVar_30) {
	cppVar_31 = ~ACC;
	cppVar_27 = cppVar_31;
	} else {
	cppVar_33 = ROM.rd(PC);
	cppVar_35 = (cppVar_33 == 238);
	if (cppVar_35) {
	cppVar_38 = (PSW >> 3) & cppMask_un_2_;
	cppVar_40 = (cppVar_38 << 3) | 6;
	cppVar_40 = (cppVar_40 & cppMask_un_5_);
	cppVar_41 = (0 << 5) | cppVar_40;
	cppVar_41 = (cppVar_41 & cppMask_un_8_);
	cppVar_42 = (cppVar_41 >> 7) & cppMask_un_1_;
	cppVar_44 = (cppVar_42 == 0);
	if (cppVar_44) {
	cppVar_45 = (PSW >> 3) & cppMask_un_2_;
	cppVar_46 = (cppVar_45 << 3) | 6;
	cppVar_46 = (cppVar_46 & cppMask_un_5_);
	cppVar_47 = (0 << 5) | cppVar_46;
	cppVar_47 = (cppVar_47 & cppMask_un_8_);
	cppVar_48 = IRAM.rd(cppVar_47);
	cppVar_36 = cppVar_48;
	} else {
	cppVar_50 = (PSW >> 3) & cppMask_un_2_;
	cppVar_51 = (cppVar_50 << 3) | 6;
	cppVar_51 = (cppVar_51 & cppMask_un_5_);
	cppVar_52 = (0 << 5) | cppVar_51;
	cppVar_52 = (cppVar_52 & cppMask_un_8_);
	cppVar_54 = (cppVar_52 == 128);
	if (cppVar_54) {
	cppVar_49 = P0;
	} else {
	cppVar_56 = (PSW >> 3) & cppMask_un_2_;
	cppVar_57 = (cppVar_56 << 3) | 6;
	cppVar_57 = (cppVar_57 & cppMask_un_5_);
	cppVar_58 = (0 << 5) | cppVar_57;
	cppVar_58 = (cppVar_58 & cppMask_un_8_);
	cppVar_60 = (cppVar_58 == 129);
	if (cppVar_60) {
	cppVar_55 = SP;
	} else {
	cppVar_62 = (PSW >> 3) & cppMask_un_2_;
	cppVar_63 = (cppVar_62 << 3) | 6;
	cppVar_63 = (cppVar_63 & cppMask_un_5_);
	cppVar_64 = (0 << 5) | cppVar_63;
	cppVar_64 = (cppVar_64 & cppMask_un_8_);
	cppVar_66 = (cppVar_64 == 130);
	if (cppVar_66) {
	cppVar_61 = DPL;
	} else {
	cppVar_68 = (PSW >> 3) & cppMask_un_2_;
	cppVar_69 = (cppVar_68 << 3) | 6;
	cppVar_69 = (cppVar_69 & cppMask_un_5_);
	cppVar_70 = (0 << 5) | cppVar_69;
	cppVar_70 = (cppVar_70 & cppMask_un_8_);
	cppVar_72 = (cppVar_70 == 131);
	if (cppVar_72) {
	cppVar_67 = DPH;
	} else {
	cppVar_74 = (PSW >> 3) & cppMask_un_2_;
	cppVar_75 = (cppVar_74 << 3) | 6;
	cppVar_75 = (cppVar_75 & cppMask_un_5_);
	cppVar_76 = (0 << 5) | cppVar_75;
	cppVar_76 = (cppVar_76 & cppMask_un_8_);
	cppVar_78 = (cppVar_76 == 135);
	if (cppVar_78) {
	cppVar_73 = PCON;
	} else {
	cppVar_80 = (PSW >> 3) & cppMask_un_2_;
	cppVar_81 = (cppVar_80 << 3) | 6;
	cppVar_81 = (cppVar_81 & cppMask_un_5_);
	cppVar_82 = (0 << 5) | cppVar_81;
	cppVar_82 = (cppVar_82 & cppMask_un_8_);
	cppVar_84 = (cppVar_82 == 136);
	if (cppVar_84) {
	cppVar_79 = TCON;
	} else {
	cppVar_86 = (PSW >> 3) & cppMask_un_2_;
	cppVar_87 = (cppVar_86 << 3) | 6;
	cppVar_87 = (cppVar_87 & cppMask_un_5_);
	cppVar_88 = (0 << 5) | cppVar_87;
	cppVar_88 = (cppVar_88 & cppMask_un_8_);
	cppVar_90 = (cppVar_88 == 137);
	if (cppVar_90) {
	cppVar_85 = TMOD;
	} else {
	cppVar_92 = (PSW >> 3) & cppMask_un_2_;
	cppVar_93 = (cppVar_92 << 3) | 6;
	cppVar_93 = (cppVar_93 & cppMask_un_5_);
	cppVar_94 = (0 << 5) | cppVar_93;
	cppVar_94 = (cppVar_94 & cppMask_un_8_);
	cppVar_96 = (cppVar_94 == 138);
	if (cppVar_96) {
	cppVar_91 = TL0;
	} else {
	cppVar_98 = (PSW >> 3) & cppMask_un_2_;
	cppVar_99 = (cppVar_98 << 3) | 6;
	cppVar_99 = (cppVar_99 & cppMask_un_5_);
	cppVar_100 = (0 << 5) | cppVar_99;
	cppVar_100 = (cppVar_100 & cppMask_un_8_);
	cppVar_102 = (cppVar_100 == 140);
	if (cppVar_102) {
	cppVar_97 = TH0;
	} else {
	cppVar_104 = (PSW >> 3) & cppMask_un_2_;
	cppVar_105 = (cppVar_104 << 3) | 6;
	cppVar_105 = (cppVar_105 & cppMask_un_5_);
	cppVar_106 = (0 << 5) | cppVar_105;
	cppVar_106 = (cppVar_106 & cppMask_un_8_);
	cppVar_108 = (cppVar_106 == 139);
	if (cppVar_108) {
	cppVar_103 = TL1;
	} else {
	cppVar_110 = (PSW >> 3) & cppMask_un_2_;
	cppVar_111 = (cppVar_110 << 3) | 6;
	cppVar_111 = (cppVar_111 & cppMask_un_5_);
	cppVar_112 = (0 << 5) | cppVar_111;
	cppVar_112 = (cppVar_112 & cppMask_un_8_);
	cppVar_114 = (cppVar_112 == 141);
	if (cppVar_114) {
	cppVar_109 = TH1;
	} else {
	cppVar_116 = (PSW >> 3) & cppMask_un_2_;
	cppVar_117 = (cppVar_116 << 3) | 6;
	cppVar_117 = (cppVar_117 & cppMask_un_5_);
	cppVar_118 = (0 << 5) | cppVar_117;
	cppVar_118 = (cppVar_118 & cppMask_un_8_);
	cppVar_120 = (cppVar_118 == 144);
	if (cppVar_120) {
	cppVar_115 = P1;
	} else {
	cppVar_122 = (PSW >> 3) & cppMask_un_2_;
	cppVar_123 = (cppVar_122 << 3) | 6;
	cppVar_123 = (cppVar_123 & cppMask_un_5_);
	cppVar_124 = (0 << 5) | cppVar_123;
	cppVar_124 = (cppVar_124 & cppMask_un_8_);
	cppVar_126 = (cppVar_124 == 152);
	if (cppVar_126) {
	cppVar_121 = SCON;
	} else {
	cppVar_128 = (PSW >> 3) & cppMask_un_2_;
	cppVar_129 = (cppVar_128 << 3) | 6;
	cppVar_129 = (cppVar_129 & cppMask_un_5_);
	cppVar_130 = (0 << 5) | cppVar_129;
	cppVar_130 = (cppVar_130 & cppMask_un_8_);
	cppVar_132 = (cppVar_130 == 153);
	if (cppVar_132) {
	cppVar_127 = SBUF;
	} else {
	cppVar_134 = (PSW >> 3) & cppMask_un_2_;
	cppVar_135 = (cppVar_134 << 3) | 6;
	cppVar_135 = (cppVar_135 & cppMask_un_5_);
	cppVar_136 = (0 << 5) | cppVar_135;
	cppVar_136 = (cppVar_136 & cppMask_un_8_);
	cppVar_138 = (cppVar_136 == 160);
	if (cppVar_138) {
	cppVar_133 = P2;
	} else {
	cppVar_140 = (PSW >> 3) & cppMask_un_2_;
	cppVar_141 = (cppVar_140 << 3) | 6;
	cppVar_141 = (cppVar_141 & cppMask_un_5_);
	cppVar_142 = (0 << 5) | cppVar_141;
	cppVar_142 = (cppVar_142 & cppMask_un_8_);
	cppVar_144 = (cppVar_142 == 168);
	if (cppVar_144) {
	cppVar_139 = IE;
	} else {
	cppVar_146 = (PSW >> 3) & cppMask_un_2_;
	cppVar_147 = (cppVar_146 << 3) | 6;
	cppVar_147 = (cppVar_147 & cppMask_un_5_);
	cppVar_148 = (0 << 5) | cppVar_147;
	cppVar_148 = (cppVar_148 & cppMask_un_8_);
	cppVar_150 = (cppVar_148 == 176);
	if (cppVar_150) {
	cppVar_145 = P3;
	} else {
	cppVar_152 = (PSW >> 3) & cppMask_un_2_;
	cppVar_153 = (cppVar_152 << 3) | 6;
	cppVar_153 = (cppVar_153 & cppMask_un_5_);
	cppVar_154 = (0 << 5) | cppVar_153;
	cppVar_154 = (cppVar_154 & cppMask_un_8_);
	cppVar_156 = (cppVar_154 == 184);
	if (cppVar_156) {
	cppVar_151 = IP;
	} else {
	cppVar_158 = (PSW >> 3) & cppMask_un_2_;
	cppVar_159 = (cppVar_158 << 3) | 6;
	cppVar_159 = (cppVar_159 & cppMask_un_5_);
	cppVar_160 = (0 << 5) | cppVar_159;
	cppVar_160 = (cppVar_160 & cppMask_un_8_);
	cppVar_162 = (cppVar_160 == 208);
	if (cppVar_162) {
	cppVar_157 = PSW;
	} else {
	cppVar_164 = (PSW >> 3) & cppMask_un_2_;
	cppVar_165 = (cppVar_164 << 3) | 6;
	cppVar_165 = (cppVar_165 & cppMask_un_5_);
	cppVar_166 = (0 << 5) | cppVar_165;
	cppVar_166 = (cppVar_166 & cppMask_un_8_);
	cppVar_168 = (cppVar_166 == 224);
	if (cppVar_168) {
	cppVar_163 = ACC;
	} else {
	cppVar_170 = (PSW >> 3) & cppMask_un_2_;
	cppVar_171 = (cppVar_170 << 3) | 6;
	cppVar_171 = (cppVar_171 & cppMask_un_5_);
	cppVar_172 = (0 << 5) | cppVar_171;
	cppVar_172 = (cppVar_172 & cppMask_un_8_);
	cppVar_174 = (cppVar_172 == 240);
	if (cppVar_174) {
	cppVar_169 = B;
	} else {
	cppVar_169 = 0;
	}
	cppVar_163 = cppVar_169;
	}
	cppVar_157 = cppVar_163;
	}
	cppVar_151 = cppVar_157;
	}
	cppVar_145 = cppVar_151;
	}
	cppVar_139 = cppVar_145;
	}
	cppVar_133 = cppVar_139;
	}
	cppVar_127 = cppVar_133;
	}
	cppVar_121 = cppVar_127;
	}
	cppVar_115 = cppVar_121;
	}
	cppVar_109 = cppVar_115;
	}
	cppVar_103 = cppVar_109;
	}
	cppVar_97 = cppVar_103;
	}
	cppVar_91 = cppVar_97;
	}
	cppVar_85 = cppVar_91;
	}
	cppVar_79 = cppVar_85;
	}
	cppVar_73 = cppVar_79;
	}
	cppVar_67 = cppVar_73;
	}
	cppVar_61 = cppVar_67;
	}
	cppVar_55 = cppVar_61;
	}
	cppVar_49 = cppVar_55;
	}
	cppVar_36 = cppVar_49;
	}
	cppVar_32 = cppVar_36;
	} else {
	cppVar_177 = ROM.rd(PC);
	cppVar_179 = (cppVar_177 == 228);
	if (cppVar_179) {
	cppVar_176 = 0;
	} else {
	cppVar_182 = ROM.rd(PC);
	cppVar_184 = (cppVar_182 == 227);
	cppVar_185 = ROM.rd(PC);
	cppVar_187 = (cppVar_185 == 226);
	cppVar_188 = ROM.rd(PC);
	cppVar_190 = (cppVar_188 == 224);
	cppVar_191 = cppVar_187 || cppVar_190;
	cppVar_192 = cppVar_184 || cppVar_191;
	if (cppVar_192) {
	cppVar_181 = XRAM_DATA_IN;
	} else {
	cppVar_194 = ROM.rd(PC);
	cppVar_196 = (cppVar_194 == 215);
	if (cppVar_196) {
	cppVar_197 = (ACC >> 4) & cppMask_un_4_;
	cppVar_199 = (PSW >> 3) & cppMask_un_2_;
	cppVar_201 = (cppVar_199 << 3) | 1;
	cppVar_201 = (cppVar_201 & cppMask_un_5_);
	cppVar_202 = (0 << 5) | cppVar_201;
	cppVar_202 = (cppVar_202 & cppMask_un_8_);
	cppVar_203 = IRAM.rd(cppVar_202);
	cppVar_204 = IRAM.rd(cppVar_203);
	cppVar_205 = (cppVar_204 >> 0) & cppMask_un_4_;
	cppVar_206 = (cppVar_197 << 4) | cppVar_205;
	cppVar_206 = (cppVar_206 & cppMask_un_8_);
	cppVar_193 = cppVar_206;
	} else {
	cppVar_208 = ROM.rd(PC);
	cppVar_210 = (cppVar_208 == 214);
	if (cppVar_210) {
	cppVar_211 = (ACC >> 4) & cppMask_un_4_;
	cppVar_213 = (PSW >> 3) & cppMask_un_2_;
	cppVar_215 = (cppVar_213 << 3) | 0;
	cppVar_215 = (cppVar_215 & cppMask_un_5_);
	cppVar_216 = (0 << 5) | cppVar_215;
	cppVar_216 = (cppVar_216 & cppMask_un_8_);
	cppVar_217 = IRAM.rd(cppVar_216);
	cppVar_218 = IRAM.rd(cppVar_217);
	cppVar_219 = (cppVar_218 >> 0) & cppMask_un_4_;
	cppVar_220 = (cppVar_211 << 4) | cppVar_219;
	cppVar_220 = (cppVar_220 & cppMask_un_8_);
	cppVar_207 = cppVar_220;
	} else {
	cppVar_222 = ROM.rd(PC);
	cppVar_224 = (cppVar_222 == 212);
	if (cppVar_224) {
	cppVar_227 = (PSW >> 6) & cppMask_un_1_;
	cppVar_229 = (cppVar_227 == 1);
	cppVar_230 = (ACC >> 0) & cppMask_un_4_;
	cppVar_232 = cppVar_230 > 9;
	cppVar_233 = cppVar_229 || cppVar_232;
	if (cppVar_233) {
	cppVar_234 = (ACC & cppMask_un_8_);
	cppVar_236 = cppVar_234 + 6;
	cppVar_236 = (cppVar_236 & cppMask_un_9_);
	cppVar_226 = cppVar_236;
	} else {
	cppVar_237 = (ACC & cppMask_un_8_);
	cppVar_226 = cppVar_237;
	}
	cppVar_238 = (cppVar_226 >> 8) & cppMask_un_1_;
	cppVar_239 = (PSW >> 7) & cppMask_un_1_;
	cppVar_240 = cppVar_238 | cppVar_239;
	cppVar_242 = (cppVar_240 == 1);
	cppVar_244 = (PSW >> 6) & cppMask_un_1_;
	cppVar_245 = (cppVar_244 == 1);
	cppVar_246 = (ACC >> 0) & cppMask_un_4_;
	cppVar_247 = cppVar_246 > 9;
	cppVar_248 = cppVar_245 || cppVar_247;
	if (cppVar_248) {
	cppVar_249 = (ACC & cppMask_un_8_);
	cppVar_250 = cppVar_249 + 6;
	cppVar_250 = (cppVar_250 & cppMask_un_9_);
	cppVar_243 = cppVar_250;
	} else {
	cppVar_251 = (ACC & cppMask_un_8_);
	cppVar_243 = cppVar_251;
	}
	cppVar_252 = (cppVar_243 >> 4) & cppMask_un_4_;
	cppVar_254 = cppVar_252 > 9;
	cppVar_255 = cppVar_242 || cppVar_254;
	if (cppVar_255) {
	cppVar_257 = (PSW >> 6) & cppMask_un_1_;
	cppVar_258 = (cppVar_257 == 1);
	cppVar_259 = (ACC >> 0) & cppMask_un_4_;
	cppVar_260 = cppVar_259 > 9;
	cppVar_261 = cppVar_258 || cppVar_260;
	if (cppVar_261) {
	cppVar_262 = (ACC & cppMask_un_8_);
	cppVar_263 = cppVar_262 + 6;
	cppVar_263 = (cppVar_263 & cppMask_un_9_);
	cppVar_256 = cppVar_263;
	} else {
	cppVar_264 = (ACC & cppMask_un_8_);
	cppVar_256 = cppVar_264;
	}
	cppVar_266 = cppVar_256 + 96;
	cppVar_266 = (cppVar_266 & cppMask_un_9_);
	cppVar_225 = cppVar_266;
	} else {
	cppVar_268 = (PSW >> 6) & cppMask_un_1_;
	cppVar_269 = (cppVar_268 == 1);
	cppVar_270 = (ACC >> 0) & cppMask_un_4_;
	cppVar_271 = cppVar_270 > 9;
	cppVar_272 = cppVar_269 || cppVar_271;
	if (cppVar_272) {
	cppVar_273 = (ACC & cppMask_un_8_);
	cppVar_274 = cppVar_273 + 6;
	cppVar_274 = (cppVar_274 & cppMask_un_9_);
	cppVar_267 = cppVar_274;
	} else {
	cppVar_275 = (ACC & cppMask_un_8_);
	cppVar_267 = cppVar_275;
	}
	cppVar_225 = cppVar_267;
	}
	cppVar_276 = (cppVar_225 >> 0) & cppMask_un_8_;
	cppVar_221 = cppVar_276;
	} else {
	cppVar_278 = ROM.rd(PC);
	cppVar_280 = (cppVar_278 == 239);
	cppVar_281 = ROM.rd(PC);
	cppVar_283 = (cppVar_281 == 207);
	cppVar_284 = cppVar_280 || cppVar_283;
	if (cppVar_284) {
	cppVar_287 = (PSW >> 3) & cppMask_un_2_;
	cppVar_289 = (cppVar_287 << 3) | 7;
	cppVar_289 = (cppVar_289 & cppMask_un_5_);
	cppVar_290 = (0 << 5) | cppVar_289;
	cppVar_290 = (cppVar_290 & cppMask_un_8_);
	cppVar_291 = (cppVar_290 >> 7) & cppMask_un_1_;
	cppVar_293 = (cppVar_291 == 0);
	if (cppVar_293) {
	cppVar_294 = (PSW >> 3) & cppMask_un_2_;
	cppVar_295 = (cppVar_294 << 3) | 7;
	cppVar_295 = (cppVar_295 & cppMask_un_5_);
	cppVar_296 = (0 << 5) | cppVar_295;
	cppVar_296 = (cppVar_296 & cppMask_un_8_);
	cppVar_297 = IRAM.rd(cppVar_296);
	cppVar_285 = cppVar_297;
	} else {
	cppVar_299 = (PSW >> 3) & cppMask_un_2_;
	cppVar_300 = (cppVar_299 << 3) | 7;
	cppVar_300 = (cppVar_300 & cppMask_un_5_);
	cppVar_301 = (0 << 5) | cppVar_300;
	cppVar_301 = (cppVar_301 & cppMask_un_8_);
	cppVar_303 = (cppVar_301 == 128);
	if (cppVar_303) {
	cppVar_298 = P0;
	} else {
	cppVar_305 = (PSW >> 3) & cppMask_un_2_;
	cppVar_306 = (cppVar_305 << 3) | 7;
	cppVar_306 = (cppVar_306 & cppMask_un_5_);
	cppVar_307 = (0 << 5) | cppVar_306;
	cppVar_307 = (cppVar_307 & cppMask_un_8_);
	cppVar_309 = (cppVar_307 == 129);
	if (cppVar_309) {
	cppVar_304 = SP;
	} else {
	cppVar_311 = (PSW >> 3) & cppMask_un_2_;
	cppVar_312 = (cppVar_311 << 3) | 7;
	cppVar_312 = (cppVar_312 & cppMask_un_5_);
	cppVar_313 = (0 << 5) | cppVar_312;
	cppVar_313 = (cppVar_313 & cppMask_un_8_);
	cppVar_315 = (cppVar_313 == 130);
	if (cppVar_315) {
	cppVar_310 = DPL;
	} else {
	cppVar_317 = (PSW >> 3) & cppMask_un_2_;
	cppVar_318 = (cppVar_317 << 3) | 7;
	cppVar_318 = (cppVar_318 & cppMask_un_5_);
	cppVar_319 = (0 << 5) | cppVar_318;
	cppVar_319 = (cppVar_319 & cppMask_un_8_);
	cppVar_321 = (cppVar_319 == 131);
	if (cppVar_321) {
	cppVar_316 = DPH;
	} else {
	cppVar_323 = (PSW >> 3) & cppMask_un_2_;
	cppVar_324 = (cppVar_323 << 3) | 7;
	cppVar_324 = (cppVar_324 & cppMask_un_5_);
	cppVar_325 = (0 << 5) | cppVar_324;
	cppVar_325 = (cppVar_325 & cppMask_un_8_);
	cppVar_327 = (cppVar_325 == 135);
	if (cppVar_327) {
	cppVar_322 = PCON;
	} else {
	cppVar_329 = (PSW >> 3) & cppMask_un_2_;
	cppVar_330 = (cppVar_329 << 3) | 7;
	cppVar_330 = (cppVar_330 & cppMask_un_5_);
	cppVar_331 = (0 << 5) | cppVar_330;
	cppVar_331 = (cppVar_331 & cppMask_un_8_);
	cppVar_333 = (cppVar_331 == 136);
	if (cppVar_333) {
	cppVar_328 = TCON;
	} else {
	cppVar_335 = (PSW >> 3) & cppMask_un_2_;
	cppVar_336 = (cppVar_335 << 3) | 7;
	cppVar_336 = (cppVar_336 & cppMask_un_5_);
	cppVar_337 = (0 << 5) | cppVar_336;
	cppVar_337 = (cppVar_337 & cppMask_un_8_);
	cppVar_339 = (cppVar_337 == 137);
	if (cppVar_339) {
	cppVar_334 = TMOD;
	} else {
	cppVar_341 = (PSW >> 3) & cppMask_un_2_;
	cppVar_342 = (cppVar_341 << 3) | 7;
	cppVar_342 = (cppVar_342 & cppMask_un_5_);
	cppVar_343 = (0 << 5) | cppVar_342;
	cppVar_343 = (cppVar_343 & cppMask_un_8_);
	cppVar_345 = (cppVar_343 == 138);
	if (cppVar_345) {
	cppVar_340 = TL0;
	} else {
	cppVar_347 = (PSW >> 3) & cppMask_un_2_;
	cppVar_348 = (cppVar_347 << 3) | 7;
	cppVar_348 = (cppVar_348 & cppMask_un_5_);
	cppVar_349 = (0 << 5) | cppVar_348;
	cppVar_349 = (cppVar_349 & cppMask_un_8_);
	cppVar_351 = (cppVar_349 == 140);
	if (cppVar_351) {
	cppVar_346 = TH0;
	} else {
	cppVar_353 = (PSW >> 3) & cppMask_un_2_;
	cppVar_354 = (cppVar_353 << 3) | 7;
	cppVar_354 = (cppVar_354 & cppMask_un_5_);
	cppVar_355 = (0 << 5) | cppVar_354;
	cppVar_355 = (cppVar_355 & cppMask_un_8_);
	cppVar_357 = (cppVar_355 == 139);
	if (cppVar_357) {
	cppVar_352 = TL1;
	} else {
	cppVar_359 = (PSW >> 3) & cppMask_un_2_;
	cppVar_360 = (cppVar_359 << 3) | 7;
	cppVar_360 = (cppVar_360 & cppMask_un_5_);
	cppVar_361 = (0 << 5) | cppVar_360;
	cppVar_361 = (cppVar_361 & cppMask_un_8_);
	cppVar_363 = (cppVar_361 == 141);
	if (cppVar_363) {
	cppVar_358 = TH1;
	} else {
	cppVar_365 = (PSW >> 3) & cppMask_un_2_;
	cppVar_366 = (cppVar_365 << 3) | 7;
	cppVar_366 = (cppVar_366 & cppMask_un_5_);
	cppVar_367 = (0 << 5) | cppVar_366;
	cppVar_367 = (cppVar_367 & cppMask_un_8_);
	cppVar_369 = (cppVar_367 == 144);
	if (cppVar_369) {
	cppVar_364 = P1;
	} else {
	cppVar_371 = (PSW >> 3) & cppMask_un_2_;
	cppVar_372 = (cppVar_371 << 3) | 7;
	cppVar_372 = (cppVar_372 & cppMask_un_5_);
	cppVar_373 = (0 << 5) | cppVar_372;
	cppVar_373 = (cppVar_373 & cppMask_un_8_);
	cppVar_375 = (cppVar_373 == 152);
	if (cppVar_375) {
	cppVar_370 = SCON;
	} else {
	cppVar_377 = (PSW >> 3) & cppMask_un_2_;
	cppVar_378 = (cppVar_377 << 3) | 7;
	cppVar_378 = (cppVar_378 & cppMask_un_5_);
	cppVar_379 = (0 << 5) | cppVar_378;
	cppVar_379 = (cppVar_379 & cppMask_un_8_);
	cppVar_381 = (cppVar_379 == 153);
	if (cppVar_381) {
	cppVar_376 = SBUF;
	} else {
	cppVar_383 = (PSW >> 3) & cppMask_un_2_;
	cppVar_384 = (cppVar_383 << 3) | 7;
	cppVar_384 = (cppVar_384 & cppMask_un_5_);
	cppVar_385 = (0 << 5) | cppVar_384;
	cppVar_385 = (cppVar_385 & cppMask_un_8_);
	cppVar_387 = (cppVar_385 == 160);
	if (cppVar_387) {
	cppVar_382 = P2;
	} else {
	cppVar_389 = (PSW >> 3) & cppMask_un_2_;
	cppVar_390 = (cppVar_389 << 3) | 7;
	cppVar_390 = (cppVar_390 & cppMask_un_5_);
	cppVar_391 = (0 << 5) | cppVar_390;
	cppVar_391 = (cppVar_391 & cppMask_un_8_);
	cppVar_393 = (cppVar_391 == 168);
	if (cppVar_393) {
	cppVar_388 = IE;
	} else {
	cppVar_395 = (PSW >> 3) & cppMask_un_2_;
	cppVar_396 = (cppVar_395 << 3) | 7;
	cppVar_396 = (cppVar_396 & cppMask_un_5_);
	cppVar_397 = (0 << 5) | cppVar_396;
	cppVar_397 = (cppVar_397 & cppMask_un_8_);
	cppVar_399 = (cppVar_397 == 176);
	if (cppVar_399) {
	cppVar_394 = P3;
	} else {
	cppVar_401 = (PSW >> 3) & cppMask_un_2_;
	cppVar_402 = (cppVar_401 << 3) | 7;
	cppVar_402 = (cppVar_402 & cppMask_un_5_);
	cppVar_403 = (0 << 5) | cppVar_402;
	cppVar_403 = (cppVar_403 & cppMask_un_8_);
	cppVar_405 = (cppVar_403 == 184);
	if (cppVar_405) {
	cppVar_400 = IP;
	} else {
	cppVar_407 = (PSW >> 3) & cppMask_un_2_;
	cppVar_408 = (cppVar_407 << 3) | 7;
	cppVar_408 = (cppVar_408 & cppMask_un_5_);
	cppVar_409 = (0 << 5) | cppVar_408;
	cppVar_409 = (cppVar_409 & cppMask_un_8_);
	cppVar_411 = (cppVar_409 == 208);
	if (cppVar_411) {
	cppVar_406 = PSW;
	} else {
	cppVar_413 = (PSW >> 3) & cppMask_un_2_;
	cppVar_414 = (cppVar_413 << 3) | 7;
	cppVar_414 = (cppVar_414 & cppMask_un_5_);
	cppVar_415 = (0 << 5) | cppVar_414;
	cppVar_415 = (cppVar_415 & cppMask_un_8_);
	cppVar_417 = (cppVar_415 == 224);
	if (cppVar_417) {
	cppVar_412 = ACC;
	} else {
	cppVar_419 = (PSW >> 3) & cppMask_un_2_;
	cppVar_420 = (cppVar_419 << 3) | 7;
	cppVar_420 = (cppVar_420 & cppMask_un_5_);
	cppVar_421 = (0 << 5) | cppVar_420;
	cppVar_421 = (cppVar_421 & cppMask_un_8_);
	cppVar_423 = (cppVar_421 == 240);
	if (cppVar_423) {
	cppVar_418 = B;
	} else {
	cppVar_418 = 0;
	}
	cppVar_412 = cppVar_418;
	}
	cppVar_406 = cppVar_412;
	}
	cppVar_400 = cppVar_406;
	}
	cppVar_394 = cppVar_400;
	}
	cppVar_388 = cppVar_394;
	}
	cppVar_382 = cppVar_388;
	}
	cppVar_376 = cppVar_382;
	}
	cppVar_370 = cppVar_376;
	}
	cppVar_364 = cppVar_370;
	}
	cppVar_358 = cppVar_364;
	}
	cppVar_352 = cppVar_358;
	}
	cppVar_346 = cppVar_352;
	}
	cppVar_340 = cppVar_346;
	}
	cppVar_334 = cppVar_340;
	}
	cppVar_328 = cppVar_334;
	}
	cppVar_322 = cppVar_328;
	}
	cppVar_316 = cppVar_322;
	}
	cppVar_310 = cppVar_316;
	}
	cppVar_304 = cppVar_310;
	}
	cppVar_298 = cppVar_304;
	}
	cppVar_285 = cppVar_298;
	}
	cppVar_277 = cppVar_285;
	} else {
	cppVar_426 = ROM.rd(PC);
	cppVar_428 = (cppVar_426 == 206);
	if (cppVar_428) {
	cppVar_430 = (PSW >> 3) & cppMask_un_2_;
	cppVar_432 = (cppVar_430 << 3) | 6;
	cppVar_432 = (cppVar_432 & cppMask_un_5_);
	cppVar_433 = (0 << 5) | cppVar_432;
	cppVar_433 = (cppVar_433 & cppMask_un_8_);
	cppVar_434 = IRAM.rd(cppVar_433);
	cppVar_425 = cppVar_434;
	} else {
	cppVar_436 = ROM.rd(PC);
	cppVar_438 = (cppVar_436 == 237);
	cppVar_439 = ROM.rd(PC);
	cppVar_441 = (cppVar_439 == 205);
	cppVar_442 = cppVar_438 || cppVar_441;
	if (cppVar_442) {
	cppVar_444 = (PSW >> 3) & cppMask_un_2_;
	cppVar_446 = (cppVar_444 << 3) | 5;
	cppVar_446 = (cppVar_446 & cppMask_un_5_);
	cppVar_447 = (0 << 5) | cppVar_446;
	cppVar_447 = (cppVar_447 & cppMask_un_8_);
	cppVar_448 = IRAM.rd(cppVar_447);
	cppVar_435 = cppVar_448;
	} else {
	cppVar_450 = ROM.rd(PC);
	cppVar_452 = (cppVar_450 == 236);
	cppVar_453 = ROM.rd(PC);
	cppVar_455 = (cppVar_453 == 204);
	cppVar_456 = cppVar_452 || cppVar_455;
	if (cppVar_456) {
	cppVar_459 = (PSW >> 3) & cppMask_un_2_;
	cppVar_461 = (cppVar_459 << 3) | 4;
	cppVar_461 = (cppVar_461 & cppMask_un_5_);
	cppVar_462 = (0 << 5) | cppVar_461;
	cppVar_462 = (cppVar_462 & cppMask_un_8_);
	cppVar_463 = (cppVar_462 >> 7) & cppMask_un_1_;
	cppVar_465 = (cppVar_463 == 0);
	if (cppVar_465) {
	cppVar_466 = (PSW >> 3) & cppMask_un_2_;
	cppVar_467 = (cppVar_466 << 3) | 4;
	cppVar_467 = (cppVar_467 & cppMask_un_5_);
	cppVar_468 = (0 << 5) | cppVar_467;
	cppVar_468 = (cppVar_468 & cppMask_un_8_);
	cppVar_469 = IRAM.rd(cppVar_468);
	cppVar_457 = cppVar_469;
	} else {
	cppVar_471 = (PSW >> 3) & cppMask_un_2_;
	cppVar_472 = (cppVar_471 << 3) | 4;
	cppVar_472 = (cppVar_472 & cppMask_un_5_);
	cppVar_473 = (0 << 5) | cppVar_472;
	cppVar_473 = (cppVar_473 & cppMask_un_8_);
	cppVar_475 = (cppVar_473 == 128);
	if (cppVar_475) {
	cppVar_470 = P0;
	} else {
	cppVar_477 = (PSW >> 3) & cppMask_un_2_;
	cppVar_478 = (cppVar_477 << 3) | 4;
	cppVar_478 = (cppVar_478 & cppMask_un_5_);
	cppVar_479 = (0 << 5) | cppVar_478;
	cppVar_479 = (cppVar_479 & cppMask_un_8_);
	cppVar_481 = (cppVar_479 == 129);
	if (cppVar_481) {
	cppVar_476 = SP;
	} else {
	cppVar_483 = (PSW >> 3) & cppMask_un_2_;
	cppVar_484 = (cppVar_483 << 3) | 4;
	cppVar_484 = (cppVar_484 & cppMask_un_5_);
	cppVar_485 = (0 << 5) | cppVar_484;
	cppVar_485 = (cppVar_485 & cppMask_un_8_);
	cppVar_487 = (cppVar_485 == 130);
	if (cppVar_487) {
	cppVar_482 = DPL;
	} else {
	cppVar_489 = (PSW >> 3) & cppMask_un_2_;
	cppVar_490 = (cppVar_489 << 3) | 4;
	cppVar_490 = (cppVar_490 & cppMask_un_5_);
	cppVar_491 = (0 << 5) | cppVar_490;
	cppVar_491 = (cppVar_491 & cppMask_un_8_);
	cppVar_493 = (cppVar_491 == 131);
	if (cppVar_493) {
	cppVar_488 = DPH;
	} else {
	cppVar_495 = (PSW >> 3) & cppMask_un_2_;
	cppVar_496 = (cppVar_495 << 3) | 4;
	cppVar_496 = (cppVar_496 & cppMask_un_5_);
	cppVar_497 = (0 << 5) | cppVar_496;
	cppVar_497 = (cppVar_497 & cppMask_un_8_);
	cppVar_499 = (cppVar_497 == 135);
	if (cppVar_499) {
	cppVar_494 = PCON;
	} else {
	cppVar_501 = (PSW >> 3) & cppMask_un_2_;
	cppVar_502 = (cppVar_501 << 3) | 4;
	cppVar_502 = (cppVar_502 & cppMask_un_5_);
	cppVar_503 = (0 << 5) | cppVar_502;
	cppVar_503 = (cppVar_503 & cppMask_un_8_);
	cppVar_505 = (cppVar_503 == 136);
	if (cppVar_505) {
	cppVar_500 = TCON;
	} else {
	cppVar_507 = (PSW >> 3) & cppMask_un_2_;
	cppVar_508 = (cppVar_507 << 3) | 4;
	cppVar_508 = (cppVar_508 & cppMask_un_5_);
	cppVar_509 = (0 << 5) | cppVar_508;
	cppVar_509 = (cppVar_509 & cppMask_un_8_);
	cppVar_511 = (cppVar_509 == 137);
	if (cppVar_511) {
	cppVar_506 = TMOD;
	} else {
	cppVar_513 = (PSW >> 3) & cppMask_un_2_;
	cppVar_514 = (cppVar_513 << 3) | 4;
	cppVar_514 = (cppVar_514 & cppMask_un_5_);
	cppVar_515 = (0 << 5) | cppVar_514;
	cppVar_515 = (cppVar_515 & cppMask_un_8_);
	cppVar_517 = (cppVar_515 == 138);
	if (cppVar_517) {
	cppVar_512 = TL0;
	} else {
	cppVar_519 = (PSW >> 3) & cppMask_un_2_;
	cppVar_520 = (cppVar_519 << 3) | 4;
	cppVar_520 = (cppVar_520 & cppMask_un_5_);
	cppVar_521 = (0 << 5) | cppVar_520;
	cppVar_521 = (cppVar_521 & cppMask_un_8_);
	cppVar_523 = (cppVar_521 == 140);
	if (cppVar_523) {
	cppVar_518 = TH0;
	} else {
	cppVar_525 = (PSW >> 3) & cppMask_un_2_;
	cppVar_526 = (cppVar_525 << 3) | 4;
	cppVar_526 = (cppVar_526 & cppMask_un_5_);
	cppVar_527 = (0 << 5) | cppVar_526;
	cppVar_527 = (cppVar_527 & cppMask_un_8_);
	cppVar_529 = (cppVar_527 == 139);
	if (cppVar_529) {
	cppVar_524 = TL1;
	} else {
	cppVar_531 = (PSW >> 3) & cppMask_un_2_;
	cppVar_532 = (cppVar_531 << 3) | 4;
	cppVar_532 = (cppVar_532 & cppMask_un_5_);
	cppVar_533 = (0 << 5) | cppVar_532;
	cppVar_533 = (cppVar_533 & cppMask_un_8_);
	cppVar_535 = (cppVar_533 == 141);
	if (cppVar_535) {
	cppVar_530 = TH1;
	} else {
	cppVar_537 = (PSW >> 3) & cppMask_un_2_;
	cppVar_538 = (cppVar_537 << 3) | 4;
	cppVar_538 = (cppVar_538 & cppMask_un_5_);
	cppVar_539 = (0 << 5) | cppVar_538;
	cppVar_539 = (cppVar_539 & cppMask_un_8_);
	cppVar_541 = (cppVar_539 == 144);
	if (cppVar_541) {
	cppVar_536 = P1;
	} else {
	cppVar_543 = (PSW >> 3) & cppMask_un_2_;
	cppVar_544 = (cppVar_543 << 3) | 4;
	cppVar_544 = (cppVar_544 & cppMask_un_5_);
	cppVar_545 = (0 << 5) | cppVar_544;
	cppVar_545 = (cppVar_545 & cppMask_un_8_);
	cppVar_547 = (cppVar_545 == 152);
	if (cppVar_547) {
	cppVar_542 = SCON;
	} else {
	cppVar_549 = (PSW >> 3) & cppMask_un_2_;
	cppVar_550 = (cppVar_549 << 3) | 4;
	cppVar_550 = (cppVar_550 & cppMask_un_5_);
	cppVar_551 = (0 << 5) | cppVar_550;
	cppVar_551 = (cppVar_551 & cppMask_un_8_);
	cppVar_553 = (cppVar_551 == 153);
	if (cppVar_553) {
	cppVar_548 = SBUF;
	} else {
	cppVar_555 = (PSW >> 3) & cppMask_un_2_;
	cppVar_556 = (cppVar_555 << 3) | 4;
	cppVar_556 = (cppVar_556 & cppMask_un_5_);
	cppVar_557 = (0 << 5) | cppVar_556;
	cppVar_557 = (cppVar_557 & cppMask_un_8_);
	cppVar_559 = (cppVar_557 == 160);
	if (cppVar_559) {
	cppVar_554 = P2;
	} else {
	cppVar_561 = (PSW >> 3) & cppMask_un_2_;
	cppVar_562 = (cppVar_561 << 3) | 4;
	cppVar_562 = (cppVar_562 & cppMask_un_5_);
	cppVar_563 = (0 << 5) | cppVar_562;
	cppVar_563 = (cppVar_563 & cppMask_un_8_);
	cppVar_565 = (cppVar_563 == 168);
	if (cppVar_565) {
	cppVar_560 = IE;
	} else {
	cppVar_567 = (PSW >> 3) & cppMask_un_2_;
	cppVar_568 = (cppVar_567 << 3) | 4;
	cppVar_568 = (cppVar_568 & cppMask_un_5_);
	cppVar_569 = (0 << 5) | cppVar_568;
	cppVar_569 = (cppVar_569 & cppMask_un_8_);
	cppVar_571 = (cppVar_569 == 176);
	if (cppVar_571) {
	cppVar_566 = P3;
	} else {
	cppVar_573 = (PSW >> 3) & cppMask_un_2_;
	cppVar_574 = (cppVar_573 << 3) | 4;
	cppVar_574 = (cppVar_574 & cppMask_un_5_);
	cppVar_575 = (0 << 5) | cppVar_574;
	cppVar_575 = (cppVar_575 & cppMask_un_8_);
	cppVar_577 = (cppVar_575 == 184);
	if (cppVar_577) {
	cppVar_572 = IP;
	} else {
	cppVar_579 = (PSW >> 3) & cppMask_un_2_;
	cppVar_580 = (cppVar_579 << 3) | 4;
	cppVar_580 = (cppVar_580 & cppMask_un_5_);
	cppVar_581 = (0 << 5) | cppVar_580;
	cppVar_581 = (cppVar_581 & cppMask_un_8_);
	cppVar_583 = (cppVar_581 == 208);
	if (cppVar_583) {
	cppVar_578 = PSW;
	} else {
	cppVar_585 = (PSW >> 3) & cppMask_un_2_;
	cppVar_586 = (cppVar_585 << 3) | 4;
	cppVar_586 = (cppVar_586 & cppMask_un_5_);
	cppVar_587 = (0 << 5) | cppVar_586;
	cppVar_587 = (cppVar_587 & cppMask_un_8_);
	cppVar_589 = (cppVar_587 == 224);
	if (cppVar_589) {
	cppVar_584 = ACC;
	} else {
	cppVar_591 = (PSW >> 3) & cppMask_un_2_;
	cppVar_592 = (cppVar_591 << 3) | 4;
	cppVar_592 = (cppVar_592 & cppMask_un_5_);
	cppVar_593 = (0 << 5) | cppVar_592;
	cppVar_593 = (cppVar_593 & cppMask_un_8_);
	cppVar_595 = (cppVar_593 == 240);
	if (cppVar_595) {
	cppVar_590 = B;
	} else {
	cppVar_590 = 0;
	}
	cppVar_584 = cppVar_590;
	}
	cppVar_578 = cppVar_584;
	}
	cppVar_572 = cppVar_578;
	}
	cppVar_566 = cppVar_572;
	}
	cppVar_560 = cppVar_566;
	}
	cppVar_554 = cppVar_560;
	}
	cppVar_548 = cppVar_554;
	}
	cppVar_542 = cppVar_548;
	}
	cppVar_536 = cppVar_542;
	}
	cppVar_530 = cppVar_536;
	}
	cppVar_524 = cppVar_530;
	}
	cppVar_518 = cppVar_524;
	}
	cppVar_512 = cppVar_518;
	}
	cppVar_506 = cppVar_512;
	}
	cppVar_500 = cppVar_506;
	}
	cppVar_494 = cppVar_500;
	}
	cppVar_488 = cppVar_494;
	}
	cppVar_482 = cppVar_488;
	}
	cppVar_476 = cppVar_482;
	}
	cppVar_470 = cppVar_476;
	}
	cppVar_457 = cppVar_470;
	}
	cppVar_449 = cppVar_457;
	} else {
	cppVar_598 = ROM.rd(PC);
	cppVar_600 = (cppVar_598 == 235);
	cppVar_601 = ROM.rd(PC);
	cppVar_603 = (cppVar_601 == 203);
	cppVar_604 = cppVar_600 || cppVar_603;
	if (cppVar_604) {
	cppVar_607 = (PSW >> 3) & cppMask_un_2_;
	cppVar_609 = (cppVar_607 << 3) | 3;
	cppVar_609 = (cppVar_609 & cppMask_un_5_);
	cppVar_610 = (0 << 5) | cppVar_609;
	cppVar_610 = (cppVar_610 & cppMask_un_8_);
	cppVar_611 = (cppVar_610 >> 7) & cppMask_un_1_;
	cppVar_613 = (cppVar_611 == 0);
	if (cppVar_613) {
	cppVar_614 = (PSW >> 3) & cppMask_un_2_;
	cppVar_615 = (cppVar_614 << 3) | 3;
	cppVar_615 = (cppVar_615 & cppMask_un_5_);
	cppVar_616 = (0 << 5) | cppVar_615;
	cppVar_616 = (cppVar_616 & cppMask_un_8_);
	cppVar_617 = IRAM.rd(cppVar_616);
	cppVar_605 = cppVar_617;
	} else {
	cppVar_619 = (PSW >> 3) & cppMask_un_2_;
	cppVar_620 = (cppVar_619 << 3) | 3;
	cppVar_620 = (cppVar_620 & cppMask_un_5_);
	cppVar_621 = (0 << 5) | cppVar_620;
	cppVar_621 = (cppVar_621 & cppMask_un_8_);
	cppVar_623 = (cppVar_621 == 128);
	if (cppVar_623) {
	cppVar_618 = P0;
	} else {
	cppVar_625 = (PSW >> 3) & cppMask_un_2_;
	cppVar_626 = (cppVar_625 << 3) | 3;
	cppVar_626 = (cppVar_626 & cppMask_un_5_);
	cppVar_627 = (0 << 5) | cppVar_626;
	cppVar_627 = (cppVar_627 & cppMask_un_8_);
	cppVar_629 = (cppVar_627 == 129);
	if (cppVar_629) {
	cppVar_624 = SP;
	} else {
	cppVar_631 = (PSW >> 3) & cppMask_un_2_;
	cppVar_632 = (cppVar_631 << 3) | 3;
	cppVar_632 = (cppVar_632 & cppMask_un_5_);
	cppVar_633 = (0 << 5) | cppVar_632;
	cppVar_633 = (cppVar_633 & cppMask_un_8_);
	cppVar_635 = (cppVar_633 == 130);
	if (cppVar_635) {
	cppVar_630 = DPL;
	} else {
	cppVar_637 = (PSW >> 3) & cppMask_un_2_;
	cppVar_638 = (cppVar_637 << 3) | 3;
	cppVar_638 = (cppVar_638 & cppMask_un_5_);
	cppVar_639 = (0 << 5) | cppVar_638;
	cppVar_639 = (cppVar_639 & cppMask_un_8_);
	cppVar_641 = (cppVar_639 == 131);
	if (cppVar_641) {
	cppVar_636 = DPH;
	} else {
	cppVar_643 = (PSW >> 3) & cppMask_un_2_;
	cppVar_644 = (cppVar_643 << 3) | 3;
	cppVar_644 = (cppVar_644 & cppMask_un_5_);
	cppVar_645 = (0 << 5) | cppVar_644;
	cppVar_645 = (cppVar_645 & cppMask_un_8_);
	cppVar_647 = (cppVar_645 == 135);
	if (cppVar_647) {
	cppVar_642 = PCON;
	} else {
	cppVar_649 = (PSW >> 3) & cppMask_un_2_;
	cppVar_650 = (cppVar_649 << 3) | 3;
	cppVar_650 = (cppVar_650 & cppMask_un_5_);
	cppVar_651 = (0 << 5) | cppVar_650;
	cppVar_651 = (cppVar_651 & cppMask_un_8_);
	cppVar_653 = (cppVar_651 == 136);
	if (cppVar_653) {
	cppVar_648 = TCON;
	} else {
	cppVar_655 = (PSW >> 3) & cppMask_un_2_;
	cppVar_656 = (cppVar_655 << 3) | 3;
	cppVar_656 = (cppVar_656 & cppMask_un_5_);
	cppVar_657 = (0 << 5) | cppVar_656;
	cppVar_657 = (cppVar_657 & cppMask_un_8_);
	cppVar_659 = (cppVar_657 == 137);
	if (cppVar_659) {
	cppVar_654 = TMOD;
	} else {
	cppVar_661 = (PSW >> 3) & cppMask_un_2_;
	cppVar_662 = (cppVar_661 << 3) | 3;
	cppVar_662 = (cppVar_662 & cppMask_un_5_);
	cppVar_663 = (0 << 5) | cppVar_662;
	cppVar_663 = (cppVar_663 & cppMask_un_8_);
	cppVar_665 = (cppVar_663 == 138);
	if (cppVar_665) {
	cppVar_660 = TL0;
	} else {
	cppVar_667 = (PSW >> 3) & cppMask_un_2_;
	cppVar_668 = (cppVar_667 << 3) | 3;
	cppVar_668 = (cppVar_668 & cppMask_un_5_);
	cppVar_669 = (0 << 5) | cppVar_668;
	cppVar_669 = (cppVar_669 & cppMask_un_8_);
	cppVar_671 = (cppVar_669 == 140);
	if (cppVar_671) {
	cppVar_666 = TH0;
	} else {
	cppVar_673 = (PSW >> 3) & cppMask_un_2_;
	cppVar_674 = (cppVar_673 << 3) | 3;
	cppVar_674 = (cppVar_674 & cppMask_un_5_);
	cppVar_675 = (0 << 5) | cppVar_674;
	cppVar_675 = (cppVar_675 & cppMask_un_8_);
	cppVar_677 = (cppVar_675 == 139);
	if (cppVar_677) {
	cppVar_672 = TL1;
	} else {
	cppVar_679 = (PSW >> 3) & cppMask_un_2_;
	cppVar_680 = (cppVar_679 << 3) | 3;
	cppVar_680 = (cppVar_680 & cppMask_un_5_);
	cppVar_681 = (0 << 5) | cppVar_680;
	cppVar_681 = (cppVar_681 & cppMask_un_8_);
	cppVar_683 = (cppVar_681 == 141);
	if (cppVar_683) {
	cppVar_678 = TH1;
	} else {
	cppVar_685 = (PSW >> 3) & cppMask_un_2_;
	cppVar_686 = (cppVar_685 << 3) | 3;
	cppVar_686 = (cppVar_686 & cppMask_un_5_);
	cppVar_687 = (0 << 5) | cppVar_686;
	cppVar_687 = (cppVar_687 & cppMask_un_8_);
	cppVar_689 = (cppVar_687 == 144);
	if (cppVar_689) {
	cppVar_684 = P1;
	} else {
	cppVar_691 = (PSW >> 3) & cppMask_un_2_;
	cppVar_692 = (cppVar_691 << 3) | 3;
	cppVar_692 = (cppVar_692 & cppMask_un_5_);
	cppVar_693 = (0 << 5) | cppVar_692;
	cppVar_693 = (cppVar_693 & cppMask_un_8_);
	cppVar_695 = (cppVar_693 == 152);
	if (cppVar_695) {
	cppVar_690 = SCON;
	} else {
	cppVar_697 = (PSW >> 3) & cppMask_un_2_;
	cppVar_698 = (cppVar_697 << 3) | 3;
	cppVar_698 = (cppVar_698 & cppMask_un_5_);
	cppVar_699 = (0 << 5) | cppVar_698;
	cppVar_699 = (cppVar_699 & cppMask_un_8_);
	cppVar_701 = (cppVar_699 == 153);
	if (cppVar_701) {
	cppVar_696 = SBUF;
	} else {
	cppVar_703 = (PSW >> 3) & cppMask_un_2_;
	cppVar_704 = (cppVar_703 << 3) | 3;
	cppVar_704 = (cppVar_704 & cppMask_un_5_);
	cppVar_705 = (0 << 5) | cppVar_704;
	cppVar_705 = (cppVar_705 & cppMask_un_8_);
	cppVar_707 = (cppVar_705 == 160);
	if (cppVar_707) {
	cppVar_702 = P2;
	} else {
	cppVar_709 = (PSW >> 3) & cppMask_un_2_;
	cppVar_710 = (cppVar_709 << 3) | 3;
	cppVar_710 = (cppVar_710 & cppMask_un_5_);
	cppVar_711 = (0 << 5) | cppVar_710;
	cppVar_711 = (cppVar_711 & cppMask_un_8_);
	cppVar_713 = (cppVar_711 == 168);
	if (cppVar_713) {
	cppVar_708 = IE;
	} else {
	cppVar_715 = (PSW >> 3) & cppMask_un_2_;
	cppVar_716 = (cppVar_715 << 3) | 3;
	cppVar_716 = (cppVar_716 & cppMask_un_5_);
	cppVar_717 = (0 << 5) | cppVar_716;
	cppVar_717 = (cppVar_717 & cppMask_un_8_);
	cppVar_719 = (cppVar_717 == 176);
	if (cppVar_719) {
	cppVar_714 = P3;
	} else {
	cppVar_721 = (PSW >> 3) & cppMask_un_2_;
	cppVar_722 = (cppVar_721 << 3) | 3;
	cppVar_722 = (cppVar_722 & cppMask_un_5_);
	cppVar_723 = (0 << 5) | cppVar_722;
	cppVar_723 = (cppVar_723 & cppMask_un_8_);
	cppVar_725 = (cppVar_723 == 184);
	if (cppVar_725) {
	cppVar_720 = IP;
	} else {
	cppVar_727 = (PSW >> 3) & cppMask_un_2_;
	cppVar_728 = (cppVar_727 << 3) | 3;
	cppVar_728 = (cppVar_728 & cppMask_un_5_);
	cppVar_729 = (0 << 5) | cppVar_728;
	cppVar_729 = (cppVar_729 & cppMask_un_8_);
	cppVar_731 = (cppVar_729 == 208);
	if (cppVar_731) {
	cppVar_726 = PSW;
	} else {
	cppVar_733 = (PSW >> 3) & cppMask_un_2_;
	cppVar_734 = (cppVar_733 << 3) | 3;
	cppVar_734 = (cppVar_734 & cppMask_un_5_);
	cppVar_735 = (0 << 5) | cppVar_734;
	cppVar_735 = (cppVar_735 & cppMask_un_8_);
	cppVar_737 = (cppVar_735 == 224);
	if (cppVar_737) {
	cppVar_732 = ACC;
	} else {
	cppVar_739 = (PSW >> 3) & cppMask_un_2_;
	cppVar_740 = (cppVar_739 << 3) | 3;
	cppVar_740 = (cppVar_740 & cppMask_un_5_);
	cppVar_741 = (0 << 5) | cppVar_740;
	cppVar_741 = (cppVar_741 & cppMask_un_8_);
	cppVar_743 = (cppVar_741 == 240);
	if (cppVar_743) {
	cppVar_738 = B;
	} else {
	cppVar_738 = 0;
	}
	cppVar_732 = cppVar_738;
	}
	cppVar_726 = cppVar_732;
	}
	cppVar_720 = cppVar_726;
	}
	cppVar_714 = cppVar_720;
	}
	cppVar_708 = cppVar_714;
	}
	cppVar_702 = cppVar_708;
	}
	cppVar_696 = cppVar_702;
	}
	cppVar_690 = cppVar_696;
	}
	cppVar_684 = cppVar_690;
	}
	cppVar_678 = cppVar_684;
	}
	cppVar_672 = cppVar_678;
	}
	cppVar_666 = cppVar_672;
	}
	cppVar_660 = cppVar_666;
	}
	cppVar_654 = cppVar_660;
	}
	cppVar_648 = cppVar_654;
	}
	cppVar_642 = cppVar_648;
	}
	cppVar_636 = cppVar_642;
	}
	cppVar_630 = cppVar_636;
	}
	cppVar_624 = cppVar_630;
	}
	cppVar_618 = cppVar_624;
	}
	cppVar_605 = cppVar_618;
	}
	cppVar_597 = cppVar_605;
	} else {
	cppVar_746 = ROM.rd(PC);
	cppVar_748 = (cppVar_746 == 234);
	cppVar_749 = ROM.rd(PC);
	cppVar_751 = (cppVar_749 == 202);
	cppVar_752 = cppVar_748 || cppVar_751;
	if (cppVar_752) {
	cppVar_755 = (PSW >> 3) & cppMask_un_2_;
	cppVar_757 = (cppVar_755 << 3) | 2;
	cppVar_757 = (cppVar_757 & cppMask_un_5_);
	cppVar_758 = (0 << 5) | cppVar_757;
	cppVar_758 = (cppVar_758 & cppMask_un_8_);
	cppVar_759 = (cppVar_758 >> 7) & cppMask_un_1_;
	cppVar_761 = (cppVar_759 == 0);
	if (cppVar_761) {
	cppVar_762 = (PSW >> 3) & cppMask_un_2_;
	cppVar_763 = (cppVar_762 << 3) | 2;
	cppVar_763 = (cppVar_763 & cppMask_un_5_);
	cppVar_764 = (0 << 5) | cppVar_763;
	cppVar_764 = (cppVar_764 & cppMask_un_8_);
	cppVar_765 = IRAM.rd(cppVar_764);
	cppVar_753 = cppVar_765;
	} else {
	cppVar_767 = (PSW >> 3) & cppMask_un_2_;
	cppVar_768 = (cppVar_767 << 3) | 2;
	cppVar_768 = (cppVar_768 & cppMask_un_5_);
	cppVar_769 = (0 << 5) | cppVar_768;
	cppVar_769 = (cppVar_769 & cppMask_un_8_);
	cppVar_771 = (cppVar_769 == 128);
	if (cppVar_771) {
	cppVar_766 = P0;
	} else {
	cppVar_773 = (PSW >> 3) & cppMask_un_2_;
	cppVar_774 = (cppVar_773 << 3) | 2;
	cppVar_774 = (cppVar_774 & cppMask_un_5_);
	cppVar_775 = (0 << 5) | cppVar_774;
	cppVar_775 = (cppVar_775 & cppMask_un_8_);
	cppVar_777 = (cppVar_775 == 129);
	if (cppVar_777) {
	cppVar_772 = SP;
	} else {
	cppVar_779 = (PSW >> 3) & cppMask_un_2_;
	cppVar_780 = (cppVar_779 << 3) | 2;
	cppVar_780 = (cppVar_780 & cppMask_un_5_);
	cppVar_781 = (0 << 5) | cppVar_780;
	cppVar_781 = (cppVar_781 & cppMask_un_8_);
	cppVar_783 = (cppVar_781 == 130);
	if (cppVar_783) {
	cppVar_778 = DPL;
	} else {
	cppVar_785 = (PSW >> 3) & cppMask_un_2_;
	cppVar_786 = (cppVar_785 << 3) | 2;
	cppVar_786 = (cppVar_786 & cppMask_un_5_);
	cppVar_787 = (0 << 5) | cppVar_786;
	cppVar_787 = (cppVar_787 & cppMask_un_8_);
	cppVar_789 = (cppVar_787 == 131);
	if (cppVar_789) {
	cppVar_784 = DPH;
	} else {
	cppVar_791 = (PSW >> 3) & cppMask_un_2_;
	cppVar_792 = (cppVar_791 << 3) | 2;
	cppVar_792 = (cppVar_792 & cppMask_un_5_);
	cppVar_793 = (0 << 5) | cppVar_792;
	cppVar_793 = (cppVar_793 & cppMask_un_8_);
	cppVar_795 = (cppVar_793 == 135);
	if (cppVar_795) {
	cppVar_790 = PCON;
	} else {
	cppVar_797 = (PSW >> 3) & cppMask_un_2_;
	cppVar_798 = (cppVar_797 << 3) | 2;
	cppVar_798 = (cppVar_798 & cppMask_un_5_);
	cppVar_799 = (0 << 5) | cppVar_798;
	cppVar_799 = (cppVar_799 & cppMask_un_8_);
	cppVar_801 = (cppVar_799 == 136);
	if (cppVar_801) {
	cppVar_796 = TCON;
	} else {
	cppVar_803 = (PSW >> 3) & cppMask_un_2_;
	cppVar_804 = (cppVar_803 << 3) | 2;
	cppVar_804 = (cppVar_804 & cppMask_un_5_);
	cppVar_805 = (0 << 5) | cppVar_804;
	cppVar_805 = (cppVar_805 & cppMask_un_8_);
	cppVar_807 = (cppVar_805 == 137);
	if (cppVar_807) {
	cppVar_802 = TMOD;
	} else {
	cppVar_809 = (PSW >> 3) & cppMask_un_2_;
	cppVar_810 = (cppVar_809 << 3) | 2;
	cppVar_810 = (cppVar_810 & cppMask_un_5_);
	cppVar_811 = (0 << 5) | cppVar_810;
	cppVar_811 = (cppVar_811 & cppMask_un_8_);
	cppVar_813 = (cppVar_811 == 138);
	if (cppVar_813) {
	cppVar_808 = TL0;
	} else {
	cppVar_815 = (PSW >> 3) & cppMask_un_2_;
	cppVar_816 = (cppVar_815 << 3) | 2;
	cppVar_816 = (cppVar_816 & cppMask_un_5_);
	cppVar_817 = (0 << 5) | cppVar_816;
	cppVar_817 = (cppVar_817 & cppMask_un_8_);
	cppVar_819 = (cppVar_817 == 140);
	if (cppVar_819) {
	cppVar_814 = TH0;
	} else {
	cppVar_821 = (PSW >> 3) & cppMask_un_2_;
	cppVar_822 = (cppVar_821 << 3) | 2;
	cppVar_822 = (cppVar_822 & cppMask_un_5_);
	cppVar_823 = (0 << 5) | cppVar_822;
	cppVar_823 = (cppVar_823 & cppMask_un_8_);
	cppVar_825 = (cppVar_823 == 139);
	if (cppVar_825) {
	cppVar_820 = TL1;
	} else {
	cppVar_827 = (PSW >> 3) & cppMask_un_2_;
	cppVar_828 = (cppVar_827 << 3) | 2;
	cppVar_828 = (cppVar_828 & cppMask_un_5_);
	cppVar_829 = (0 << 5) | cppVar_828;
	cppVar_829 = (cppVar_829 & cppMask_un_8_);
	cppVar_831 = (cppVar_829 == 141);
	if (cppVar_831) {
	cppVar_826 = TH1;
	} else {
	cppVar_833 = (PSW >> 3) & cppMask_un_2_;
	cppVar_834 = (cppVar_833 << 3) | 2;
	cppVar_834 = (cppVar_834 & cppMask_un_5_);
	cppVar_835 = (0 << 5) | cppVar_834;
	cppVar_835 = (cppVar_835 & cppMask_un_8_);
	cppVar_837 = (cppVar_835 == 144);
	if (cppVar_837) {
	cppVar_832 = P1;
	} else {
	cppVar_839 = (PSW >> 3) & cppMask_un_2_;
	cppVar_840 = (cppVar_839 << 3) | 2;
	cppVar_840 = (cppVar_840 & cppMask_un_5_);
	cppVar_841 = (0 << 5) | cppVar_840;
	cppVar_841 = (cppVar_841 & cppMask_un_8_);
	cppVar_843 = (cppVar_841 == 152);
	if (cppVar_843) {
	cppVar_838 = SCON;
	} else {
	cppVar_845 = (PSW >> 3) & cppMask_un_2_;
	cppVar_846 = (cppVar_845 << 3) | 2;
	cppVar_846 = (cppVar_846 & cppMask_un_5_);
	cppVar_847 = (0 << 5) | cppVar_846;
	cppVar_847 = (cppVar_847 & cppMask_un_8_);
	cppVar_849 = (cppVar_847 == 153);
	if (cppVar_849) {
	cppVar_844 = SBUF;
	} else {
	cppVar_851 = (PSW >> 3) & cppMask_un_2_;
	cppVar_852 = (cppVar_851 << 3) | 2;
	cppVar_852 = (cppVar_852 & cppMask_un_5_);
	cppVar_853 = (0 << 5) | cppVar_852;
	cppVar_853 = (cppVar_853 & cppMask_un_8_);
	cppVar_855 = (cppVar_853 == 160);
	if (cppVar_855) {
	cppVar_850 = P2;
	} else {
	cppVar_857 = (PSW >> 3) & cppMask_un_2_;
	cppVar_858 = (cppVar_857 << 3) | 2;
	cppVar_858 = (cppVar_858 & cppMask_un_5_);
	cppVar_859 = (0 << 5) | cppVar_858;
	cppVar_859 = (cppVar_859 & cppMask_un_8_);
	cppVar_861 = (cppVar_859 == 168);
	if (cppVar_861) {
	cppVar_856 = IE;
	} else {
	cppVar_863 = (PSW >> 3) & cppMask_un_2_;
	cppVar_864 = (cppVar_863 << 3) | 2;
	cppVar_864 = (cppVar_864 & cppMask_un_5_);
	cppVar_865 = (0 << 5) | cppVar_864;
	cppVar_865 = (cppVar_865 & cppMask_un_8_);
	cppVar_867 = (cppVar_865 == 176);
	if (cppVar_867) {
	cppVar_862 = P3;
	} else {
	cppVar_869 = (PSW >> 3) & cppMask_un_2_;
	cppVar_870 = (cppVar_869 << 3) | 2;
	cppVar_870 = (cppVar_870 & cppMask_un_5_);
	cppVar_871 = (0 << 5) | cppVar_870;
	cppVar_871 = (cppVar_871 & cppMask_un_8_);
	cppVar_873 = (cppVar_871 == 184);
	if (cppVar_873) {
	cppVar_868 = IP;
	} else {
	cppVar_875 = (PSW >> 3) & cppMask_un_2_;
	cppVar_876 = (cppVar_875 << 3) | 2;
	cppVar_876 = (cppVar_876 & cppMask_un_5_);
	cppVar_877 = (0 << 5) | cppVar_876;
	cppVar_877 = (cppVar_877 & cppMask_un_8_);
	cppVar_879 = (cppVar_877 == 208);
	if (cppVar_879) {
	cppVar_874 = PSW;
	} else {
	cppVar_881 = (PSW >> 3) & cppMask_un_2_;
	cppVar_882 = (cppVar_881 << 3) | 2;
	cppVar_882 = (cppVar_882 & cppMask_un_5_);
	cppVar_883 = (0 << 5) | cppVar_882;
	cppVar_883 = (cppVar_883 & cppMask_un_8_);
	cppVar_885 = (cppVar_883 == 224);
	if (cppVar_885) {
	cppVar_880 = ACC;
	} else {
	cppVar_887 = (PSW >> 3) & cppMask_un_2_;
	cppVar_888 = (cppVar_887 << 3) | 2;
	cppVar_888 = (cppVar_888 & cppMask_un_5_);
	cppVar_889 = (0 << 5) | cppVar_888;
	cppVar_889 = (cppVar_889 & cppMask_un_8_);
	cppVar_891 = (cppVar_889 == 240);
	if (cppVar_891) {
	cppVar_886 = B;
	} else {
	cppVar_886 = 0;
	}
	cppVar_880 = cppVar_886;
	}
	cppVar_874 = cppVar_880;
	}
	cppVar_868 = cppVar_874;
	}
	cppVar_862 = cppVar_868;
	}
	cppVar_856 = cppVar_862;
	}
	cppVar_850 = cppVar_856;
	}
	cppVar_844 = cppVar_850;
	}
	cppVar_838 = cppVar_844;
	}
	cppVar_832 = cppVar_838;
	}
	cppVar_826 = cppVar_832;
	}
	cppVar_820 = cppVar_826;
	}
	cppVar_814 = cppVar_820;
	}
	cppVar_808 = cppVar_814;
	}
	cppVar_802 = cppVar_808;
	}
	cppVar_796 = cppVar_802;
	}
	cppVar_790 = cppVar_796;
	}
	cppVar_784 = cppVar_790;
	}
	cppVar_778 = cppVar_784;
	}
	cppVar_772 = cppVar_778;
	}
	cppVar_766 = cppVar_772;
	}
	cppVar_753 = cppVar_766;
	}
	cppVar_745 = cppVar_753;
	} else {
	cppVar_894 = ROM.rd(PC);
	cppVar_896 = (cppVar_894 == 233);
	cppVar_897 = ROM.rd(PC);
	cppVar_899 = (cppVar_897 == 201);
	cppVar_900 = cppVar_896 || cppVar_899;
	if (cppVar_900) {
	cppVar_903 = (PSW >> 3) & cppMask_un_2_;
	cppVar_905 = (cppVar_903 << 3) | 1;
	cppVar_905 = (cppVar_905 & cppMask_un_5_);
	cppVar_906 = (0 << 5) | cppVar_905;
	cppVar_906 = (cppVar_906 & cppMask_un_8_);
	cppVar_907 = (cppVar_906 >> 7) & cppMask_un_1_;
	cppVar_909 = (cppVar_907 == 0);
	if (cppVar_909) {
	cppVar_910 = (PSW >> 3) & cppMask_un_2_;
	cppVar_911 = (cppVar_910 << 3) | 1;
	cppVar_911 = (cppVar_911 & cppMask_un_5_);
	cppVar_912 = (0 << 5) | cppVar_911;
	cppVar_912 = (cppVar_912 & cppMask_un_8_);
	cppVar_913 = IRAM.rd(cppVar_912);
	cppVar_901 = cppVar_913;
	} else {
	cppVar_915 = (PSW >> 3) & cppMask_un_2_;
	cppVar_916 = (cppVar_915 << 3) | 1;
	cppVar_916 = (cppVar_916 & cppMask_un_5_);
	cppVar_917 = (0 << 5) | cppVar_916;
	cppVar_917 = (cppVar_917 & cppMask_un_8_);
	cppVar_919 = (cppVar_917 == 128);
	if (cppVar_919) {
	cppVar_914 = P0;
	} else {
	cppVar_921 = (PSW >> 3) & cppMask_un_2_;
	cppVar_922 = (cppVar_921 << 3) | 1;
	cppVar_922 = (cppVar_922 & cppMask_un_5_);
	cppVar_923 = (0 << 5) | cppVar_922;
	cppVar_923 = (cppVar_923 & cppMask_un_8_);
	cppVar_925 = (cppVar_923 == 129);
	if (cppVar_925) {
	cppVar_920 = SP;
	} else {
	cppVar_927 = (PSW >> 3) & cppMask_un_2_;
	cppVar_928 = (cppVar_927 << 3) | 1;
	cppVar_928 = (cppVar_928 & cppMask_un_5_);
	cppVar_929 = (0 << 5) | cppVar_928;
	cppVar_929 = (cppVar_929 & cppMask_un_8_);
	cppVar_931 = (cppVar_929 == 130);
	if (cppVar_931) {
	cppVar_926 = DPL;
	} else {
	cppVar_933 = (PSW >> 3) & cppMask_un_2_;
	cppVar_934 = (cppVar_933 << 3) | 1;
	cppVar_934 = (cppVar_934 & cppMask_un_5_);
	cppVar_935 = (0 << 5) | cppVar_934;
	cppVar_935 = (cppVar_935 & cppMask_un_8_);
	cppVar_937 = (cppVar_935 == 131);
	if (cppVar_937) {
	cppVar_932 = DPH;
	} else {
	cppVar_939 = (PSW >> 3) & cppMask_un_2_;
	cppVar_940 = (cppVar_939 << 3) | 1;
	cppVar_940 = (cppVar_940 & cppMask_un_5_);
	cppVar_941 = (0 << 5) | cppVar_940;
	cppVar_941 = (cppVar_941 & cppMask_un_8_);
	cppVar_943 = (cppVar_941 == 135);
	if (cppVar_943) {
	cppVar_938 = PCON;
	} else {
	cppVar_945 = (PSW >> 3) & cppMask_un_2_;
	cppVar_946 = (cppVar_945 << 3) | 1;
	cppVar_946 = (cppVar_946 & cppMask_un_5_);
	cppVar_947 = (0 << 5) | cppVar_946;
	cppVar_947 = (cppVar_947 & cppMask_un_8_);
	cppVar_949 = (cppVar_947 == 136);
	if (cppVar_949) {
	cppVar_944 = TCON;
	} else {
	cppVar_951 = (PSW >> 3) & cppMask_un_2_;
	cppVar_952 = (cppVar_951 << 3) | 1;
	cppVar_952 = (cppVar_952 & cppMask_un_5_);
	cppVar_953 = (0 << 5) | cppVar_952;
	cppVar_953 = (cppVar_953 & cppMask_un_8_);
	cppVar_955 = (cppVar_953 == 137);
	if (cppVar_955) {
	cppVar_950 = TMOD;
	} else {
	cppVar_957 = (PSW >> 3) & cppMask_un_2_;
	cppVar_958 = (cppVar_957 << 3) | 1;
	cppVar_958 = (cppVar_958 & cppMask_un_5_);
	cppVar_959 = (0 << 5) | cppVar_958;
	cppVar_959 = (cppVar_959 & cppMask_un_8_);
	cppVar_961 = (cppVar_959 == 138);
	if (cppVar_961) {
	cppVar_956 = TL0;
	} else {
	cppVar_963 = (PSW >> 3) & cppMask_un_2_;
	cppVar_964 = (cppVar_963 << 3) | 1;
	cppVar_964 = (cppVar_964 & cppMask_un_5_);
	cppVar_965 = (0 << 5) | cppVar_964;
	cppVar_965 = (cppVar_965 & cppMask_un_8_);
	cppVar_967 = (cppVar_965 == 140);
	if (cppVar_967) {
	cppVar_962 = TH0;
	} else {
	cppVar_969 = (PSW >> 3) & cppMask_un_2_;
	cppVar_970 = (cppVar_969 << 3) | 1;
	cppVar_970 = (cppVar_970 & cppMask_un_5_);
	cppVar_971 = (0 << 5) | cppVar_970;
	cppVar_971 = (cppVar_971 & cppMask_un_8_);
	cppVar_973 = (cppVar_971 == 139);
	if (cppVar_973) {
	cppVar_968 = TL1;
	} else {
	cppVar_975 = (PSW >> 3) & cppMask_un_2_;
	cppVar_976 = (cppVar_975 << 3) | 1;
	cppVar_976 = (cppVar_976 & cppMask_un_5_);
	cppVar_977 = (0 << 5) | cppVar_976;
	cppVar_977 = (cppVar_977 & cppMask_un_8_);
	cppVar_979 = (cppVar_977 == 141);
	if (cppVar_979) {
	cppVar_974 = TH1;
	} else {
	cppVar_981 = (PSW >> 3) & cppMask_un_2_;
	cppVar_982 = (cppVar_981 << 3) | 1;
	cppVar_982 = (cppVar_982 & cppMask_un_5_);
	cppVar_983 = (0 << 5) | cppVar_982;
	cppVar_983 = (cppVar_983 & cppMask_un_8_);
	cppVar_985 = (cppVar_983 == 144);
	if (cppVar_985) {
	cppVar_980 = P1;
	} else {
	cppVar_987 = (PSW >> 3) & cppMask_un_2_;
	cppVar_988 = (cppVar_987 << 3) | 1;
	cppVar_988 = (cppVar_988 & cppMask_un_5_);
	cppVar_989 = (0 << 5) | cppVar_988;
	cppVar_989 = (cppVar_989 & cppMask_un_8_);
	cppVar_991 = (cppVar_989 == 152);
	if (cppVar_991) {
	cppVar_986 = SCON;
	} else {
	cppVar_993 = (PSW >> 3) & cppMask_un_2_;
	cppVar_994 = (cppVar_993 << 3) | 1;
	cppVar_994 = (cppVar_994 & cppMask_un_5_);
	cppVar_995 = (0 << 5) | cppVar_994;
	cppVar_995 = (cppVar_995 & cppMask_un_8_);
	cppVar_997 = (cppVar_995 == 153);
	if (cppVar_997) {
	cppVar_992 = SBUF;
	} else {
	cppVar_999 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1000 = (cppVar_999 << 3) | 1;
	cppVar_1000 = (cppVar_1000 & cppMask_un_5_);
	cppVar_1001 = (0 << 5) | cppVar_1000;
	cppVar_1001 = (cppVar_1001 & cppMask_un_8_);
	cppVar_1003 = (cppVar_1001 == 160);
	if (cppVar_1003) {
	cppVar_998 = P2;
	} else {
	cppVar_1005 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1006 = (cppVar_1005 << 3) | 1;
	cppVar_1006 = (cppVar_1006 & cppMask_un_5_);
	cppVar_1007 = (0 << 5) | cppVar_1006;
	cppVar_1007 = (cppVar_1007 & cppMask_un_8_);
	cppVar_1009 = (cppVar_1007 == 168);
	if (cppVar_1009) {
	cppVar_1004 = IE;
	} else {
	cppVar_1011 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1012 = (cppVar_1011 << 3) | 1;
	cppVar_1012 = (cppVar_1012 & cppMask_un_5_);
	cppVar_1013 = (0 << 5) | cppVar_1012;
	cppVar_1013 = (cppVar_1013 & cppMask_un_8_);
	cppVar_1015 = (cppVar_1013 == 176);
	if (cppVar_1015) {
	cppVar_1010 = P3;
	} else {
	cppVar_1017 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1018 = (cppVar_1017 << 3) | 1;
	cppVar_1018 = (cppVar_1018 & cppMask_un_5_);
	cppVar_1019 = (0 << 5) | cppVar_1018;
	cppVar_1019 = (cppVar_1019 & cppMask_un_8_);
	cppVar_1021 = (cppVar_1019 == 184);
	if (cppVar_1021) {
	cppVar_1016 = IP;
	} else {
	cppVar_1023 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1024 = (cppVar_1023 << 3) | 1;
	cppVar_1024 = (cppVar_1024 & cppMask_un_5_);
	cppVar_1025 = (0 << 5) | cppVar_1024;
	cppVar_1025 = (cppVar_1025 & cppMask_un_8_);
	cppVar_1027 = (cppVar_1025 == 208);
	if (cppVar_1027) {
	cppVar_1022 = PSW;
	} else {
	cppVar_1029 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1030 = (cppVar_1029 << 3) | 1;
	cppVar_1030 = (cppVar_1030 & cppMask_un_5_);
	cppVar_1031 = (0 << 5) | cppVar_1030;
	cppVar_1031 = (cppVar_1031 & cppMask_un_8_);
	cppVar_1033 = (cppVar_1031 == 224);
	if (cppVar_1033) {
	cppVar_1028 = ACC;
	} else {
	cppVar_1035 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1036 = (cppVar_1035 << 3) | 1;
	cppVar_1036 = (cppVar_1036 & cppMask_un_5_);
	cppVar_1037 = (0 << 5) | cppVar_1036;
	cppVar_1037 = (cppVar_1037 & cppMask_un_8_);
	cppVar_1039 = (cppVar_1037 == 240);
	if (cppVar_1039) {
	cppVar_1034 = B;
	} else {
	cppVar_1034 = 0;
	}
	cppVar_1028 = cppVar_1034;
	}
	cppVar_1022 = cppVar_1028;
	}
	cppVar_1016 = cppVar_1022;
	}
	cppVar_1010 = cppVar_1016;
	}
	cppVar_1004 = cppVar_1010;
	}
	cppVar_998 = cppVar_1004;
	}
	cppVar_992 = cppVar_998;
	}
	cppVar_986 = cppVar_992;
	}
	cppVar_980 = cppVar_986;
	}
	cppVar_974 = cppVar_980;
	}
	cppVar_968 = cppVar_974;
	}
	cppVar_962 = cppVar_968;
	}
	cppVar_956 = cppVar_962;
	}
	cppVar_950 = cppVar_956;
	}
	cppVar_944 = cppVar_950;
	}
	cppVar_938 = cppVar_944;
	}
	cppVar_932 = cppVar_938;
	}
	cppVar_926 = cppVar_932;
	}
	cppVar_920 = cppVar_926;
	}
	cppVar_914 = cppVar_920;
	}
	cppVar_901 = cppVar_914;
	}
	cppVar_893 = cppVar_901;
	} else {
	cppVar_1042 = ROM.rd(PC);
	cppVar_1044 = (cppVar_1042 == 232);
	cppVar_1045 = ROM.rd(PC);
	cppVar_1047 = (cppVar_1045 == 200);
	cppVar_1048 = cppVar_1044 || cppVar_1047;
	if (cppVar_1048) {
	cppVar_1051 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1053 = (cppVar_1051 << 3) | 0;
	cppVar_1053 = (cppVar_1053 & cppMask_un_5_);
	cppVar_1054 = (0 << 5) | cppVar_1053;
	cppVar_1054 = (cppVar_1054 & cppMask_un_8_);
	cppVar_1055 = (cppVar_1054 >> 7) & cppMask_un_1_;
	cppVar_1057 = (cppVar_1055 == 0);
	if (cppVar_1057) {
	cppVar_1058 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1059 = (cppVar_1058 << 3) | 0;
	cppVar_1059 = (cppVar_1059 & cppMask_un_5_);
	cppVar_1060 = (0 << 5) | cppVar_1059;
	cppVar_1060 = (cppVar_1060 & cppMask_un_8_);
	cppVar_1061 = IRAM.rd(cppVar_1060);
	cppVar_1049 = cppVar_1061;
	} else {
	cppVar_1063 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1064 = (cppVar_1063 << 3) | 0;
	cppVar_1064 = (cppVar_1064 & cppMask_un_5_);
	cppVar_1065 = (0 << 5) | cppVar_1064;
	cppVar_1065 = (cppVar_1065 & cppMask_un_8_);
	cppVar_1067 = (cppVar_1065 == 128);
	if (cppVar_1067) {
	cppVar_1062 = P0;
	} else {
	cppVar_1069 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1070 = (cppVar_1069 << 3) | 0;
	cppVar_1070 = (cppVar_1070 & cppMask_un_5_);
	cppVar_1071 = (0 << 5) | cppVar_1070;
	cppVar_1071 = (cppVar_1071 & cppMask_un_8_);
	cppVar_1073 = (cppVar_1071 == 129);
	if (cppVar_1073) {
	cppVar_1068 = SP;
	} else {
	cppVar_1075 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1076 = (cppVar_1075 << 3) | 0;
	cppVar_1076 = (cppVar_1076 & cppMask_un_5_);
	cppVar_1077 = (0 << 5) | cppVar_1076;
	cppVar_1077 = (cppVar_1077 & cppMask_un_8_);
	cppVar_1079 = (cppVar_1077 == 130);
	if (cppVar_1079) {
	cppVar_1074 = DPL;
	} else {
	cppVar_1081 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1082 = (cppVar_1081 << 3) | 0;
	cppVar_1082 = (cppVar_1082 & cppMask_un_5_);
	cppVar_1083 = (0 << 5) | cppVar_1082;
	cppVar_1083 = (cppVar_1083 & cppMask_un_8_);
	cppVar_1085 = (cppVar_1083 == 131);
	if (cppVar_1085) {
	cppVar_1080 = DPH;
	} else {
	cppVar_1087 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1088 = (cppVar_1087 << 3) | 0;
	cppVar_1088 = (cppVar_1088 & cppMask_un_5_);
	cppVar_1089 = (0 << 5) | cppVar_1088;
	cppVar_1089 = (cppVar_1089 & cppMask_un_8_);
	cppVar_1091 = (cppVar_1089 == 135);
	if (cppVar_1091) {
	cppVar_1086 = PCON;
	} else {
	cppVar_1093 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1094 = (cppVar_1093 << 3) | 0;
	cppVar_1094 = (cppVar_1094 & cppMask_un_5_);
	cppVar_1095 = (0 << 5) | cppVar_1094;
	cppVar_1095 = (cppVar_1095 & cppMask_un_8_);
	cppVar_1097 = (cppVar_1095 == 136);
	if (cppVar_1097) {
	cppVar_1092 = TCON;
	} else {
	cppVar_1099 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1100 = (cppVar_1099 << 3) | 0;
	cppVar_1100 = (cppVar_1100 & cppMask_un_5_);
	cppVar_1101 = (0 << 5) | cppVar_1100;
	cppVar_1101 = (cppVar_1101 & cppMask_un_8_);
	cppVar_1103 = (cppVar_1101 == 137);
	if (cppVar_1103) {
	cppVar_1098 = TMOD;
	} else {
	cppVar_1105 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1106 = (cppVar_1105 << 3) | 0;
	cppVar_1106 = (cppVar_1106 & cppMask_un_5_);
	cppVar_1107 = (0 << 5) | cppVar_1106;
	cppVar_1107 = (cppVar_1107 & cppMask_un_8_);
	cppVar_1109 = (cppVar_1107 == 138);
	if (cppVar_1109) {
	cppVar_1104 = TL0;
	} else {
	cppVar_1111 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1112 = (cppVar_1111 << 3) | 0;
	cppVar_1112 = (cppVar_1112 & cppMask_un_5_);
	cppVar_1113 = (0 << 5) | cppVar_1112;
	cppVar_1113 = (cppVar_1113 & cppMask_un_8_);
	cppVar_1115 = (cppVar_1113 == 140);
	if (cppVar_1115) {
	cppVar_1110 = TH0;
	} else {
	cppVar_1117 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1118 = (cppVar_1117 << 3) | 0;
	cppVar_1118 = (cppVar_1118 & cppMask_un_5_);
	cppVar_1119 = (0 << 5) | cppVar_1118;
	cppVar_1119 = (cppVar_1119 & cppMask_un_8_);
	cppVar_1121 = (cppVar_1119 == 139);
	if (cppVar_1121) {
	cppVar_1116 = TL1;
	} else {
	cppVar_1123 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1124 = (cppVar_1123 << 3) | 0;
	cppVar_1124 = (cppVar_1124 & cppMask_un_5_);
	cppVar_1125 = (0 << 5) | cppVar_1124;
	cppVar_1125 = (cppVar_1125 & cppMask_un_8_);
	cppVar_1127 = (cppVar_1125 == 141);
	if (cppVar_1127) {
	cppVar_1122 = TH1;
	} else {
	cppVar_1129 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1130 = (cppVar_1129 << 3) | 0;
	cppVar_1130 = (cppVar_1130 & cppMask_un_5_);
	cppVar_1131 = (0 << 5) | cppVar_1130;
	cppVar_1131 = (cppVar_1131 & cppMask_un_8_);
	cppVar_1133 = (cppVar_1131 == 144);
	if (cppVar_1133) {
	cppVar_1128 = P1;
	} else {
	cppVar_1135 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1136 = (cppVar_1135 << 3) | 0;
	cppVar_1136 = (cppVar_1136 & cppMask_un_5_);
	cppVar_1137 = (0 << 5) | cppVar_1136;
	cppVar_1137 = (cppVar_1137 & cppMask_un_8_);
	cppVar_1139 = (cppVar_1137 == 152);
	if (cppVar_1139) {
	cppVar_1134 = SCON;
	} else {
	cppVar_1141 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1142 = (cppVar_1141 << 3) | 0;
	cppVar_1142 = (cppVar_1142 & cppMask_un_5_);
	cppVar_1143 = (0 << 5) | cppVar_1142;
	cppVar_1143 = (cppVar_1143 & cppMask_un_8_);
	cppVar_1145 = (cppVar_1143 == 153);
	if (cppVar_1145) {
	cppVar_1140 = SBUF;
	} else {
	cppVar_1147 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1148 = (cppVar_1147 << 3) | 0;
	cppVar_1148 = (cppVar_1148 & cppMask_un_5_);
	cppVar_1149 = (0 << 5) | cppVar_1148;
	cppVar_1149 = (cppVar_1149 & cppMask_un_8_);
	cppVar_1151 = (cppVar_1149 == 160);
	if (cppVar_1151) {
	cppVar_1146 = P2;
	} else {
	cppVar_1153 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1154 = (cppVar_1153 << 3) | 0;
	cppVar_1154 = (cppVar_1154 & cppMask_un_5_);
	cppVar_1155 = (0 << 5) | cppVar_1154;
	cppVar_1155 = (cppVar_1155 & cppMask_un_8_);
	cppVar_1157 = (cppVar_1155 == 168);
	if (cppVar_1157) {
	cppVar_1152 = IE;
	} else {
	cppVar_1159 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1160 = (cppVar_1159 << 3) | 0;
	cppVar_1160 = (cppVar_1160 & cppMask_un_5_);
	cppVar_1161 = (0 << 5) | cppVar_1160;
	cppVar_1161 = (cppVar_1161 & cppMask_un_8_);
	cppVar_1163 = (cppVar_1161 == 176);
	if (cppVar_1163) {
	cppVar_1158 = P3;
	} else {
	cppVar_1165 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1166 = (cppVar_1165 << 3) | 0;
	cppVar_1166 = (cppVar_1166 & cppMask_un_5_);
	cppVar_1167 = (0 << 5) | cppVar_1166;
	cppVar_1167 = (cppVar_1167 & cppMask_un_8_);
	cppVar_1169 = (cppVar_1167 == 184);
	if (cppVar_1169) {
	cppVar_1164 = IP;
	} else {
	cppVar_1171 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1172 = (cppVar_1171 << 3) | 0;
	cppVar_1172 = (cppVar_1172 & cppMask_un_5_);
	cppVar_1173 = (0 << 5) | cppVar_1172;
	cppVar_1173 = (cppVar_1173 & cppMask_un_8_);
	cppVar_1175 = (cppVar_1173 == 208);
	if (cppVar_1175) {
	cppVar_1170 = PSW;
	} else {
	cppVar_1177 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1178 = (cppVar_1177 << 3) | 0;
	cppVar_1178 = (cppVar_1178 & cppMask_un_5_);
	cppVar_1179 = (0 << 5) | cppVar_1178;
	cppVar_1179 = (cppVar_1179 & cppMask_un_8_);
	cppVar_1181 = (cppVar_1179 == 224);
	if (cppVar_1181) {
	cppVar_1176 = ACC;
	} else {
	cppVar_1183 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1184 = (cppVar_1183 << 3) | 0;
	cppVar_1184 = (cppVar_1184 & cppMask_un_5_);
	cppVar_1185 = (0 << 5) | cppVar_1184;
	cppVar_1185 = (cppVar_1185 & cppMask_un_8_);
	cppVar_1187 = (cppVar_1185 == 240);
	if (cppVar_1187) {
	cppVar_1182 = B;
	} else {
	cppVar_1182 = 0;
	}
	cppVar_1176 = cppVar_1182;
	}
	cppVar_1170 = cppVar_1176;
	}
	cppVar_1164 = cppVar_1170;
	}
	cppVar_1158 = cppVar_1164;
	}
	cppVar_1152 = cppVar_1158;
	}
	cppVar_1146 = cppVar_1152;
	}
	cppVar_1140 = cppVar_1146;
	}
	cppVar_1134 = cppVar_1140;
	}
	cppVar_1128 = cppVar_1134;
	}
	cppVar_1122 = cppVar_1128;
	}
	cppVar_1116 = cppVar_1122;
	}
	cppVar_1110 = cppVar_1116;
	}
	cppVar_1104 = cppVar_1110;
	}
	cppVar_1098 = cppVar_1104;
	}
	cppVar_1092 = cppVar_1098;
	}
	cppVar_1086 = cppVar_1092;
	}
	cppVar_1080 = cppVar_1086;
	}
	cppVar_1074 = cppVar_1080;
	}
	cppVar_1068 = cppVar_1074;
	}
	cppVar_1062 = cppVar_1068;
	}
	cppVar_1049 = cppVar_1062;
	}
	cppVar_1041 = cppVar_1049;
	} else {
	cppVar_1190 = ROM.rd(PC);
	cppVar_1192 = (cppVar_1190 == 231);
	cppVar_1193 = ROM.rd(PC);
	cppVar_1195 = (cppVar_1193 == 199);
	cppVar_1196 = cppVar_1192 || cppVar_1195;
	if (cppVar_1196) {
	cppVar_1198 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1200 = (cppVar_1198 << 3) | 1;
	cppVar_1200 = (cppVar_1200 & cppMask_un_5_);
	cppVar_1201 = (0 << 5) | cppVar_1200;
	cppVar_1201 = (cppVar_1201 & cppMask_un_8_);
	cppVar_1202 = IRAM.rd(cppVar_1201);
	cppVar_1203 = IRAM.rd(cppVar_1202);
	cppVar_1189 = cppVar_1203;
	} else {
	cppVar_1205 = ROM.rd(PC);
	cppVar_1207 = (cppVar_1205 == 230);
	cppVar_1208 = ROM.rd(PC);
	cppVar_1210 = (cppVar_1208 == 198);
	cppVar_1211 = cppVar_1207 || cppVar_1210;
	if (cppVar_1211) {
	cppVar_1213 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1215 = (cppVar_1213 << 3) | 0;
	cppVar_1215 = (cppVar_1215 & cppMask_un_5_);
	cppVar_1216 = (0 << 5) | cppVar_1215;
	cppVar_1216 = (cppVar_1216 & cppMask_un_8_);
	cppVar_1217 = IRAM.rd(cppVar_1216);
	cppVar_1218 = IRAM.rd(cppVar_1217);
	cppVar_1204 = cppVar_1218;
	} else {
	cppVar_1220 = ROM.rd(PC);
	cppVar_1222 = (cppVar_1220 == 229);
	cppVar_1223 = ROM.rd(PC);
	cppVar_1225 = (cppVar_1223 == 197);
	cppVar_1226 = cppVar_1222 || cppVar_1225;
	if (cppVar_1226) {
	cppVar_1229 = PC + 1;
	cppVar_1229 = (cppVar_1229 & cppMask_un_16_);
	cppVar_1230 = ROM.rd(cppVar_1229);
	cppVar_1231 = (cppVar_1230 >> 7) & cppMask_un_1_;
	cppVar_1233 = (cppVar_1231 == 0);
	if (cppVar_1233) {
	cppVar_1234 = PC + 1;
	cppVar_1234 = (cppVar_1234 & cppMask_un_16_);
	cppVar_1235 = ROM.rd(cppVar_1234);
	cppVar_1236 = IRAM.rd(cppVar_1235);
	cppVar_1227 = cppVar_1236;
	} else {
	cppVar_1238 = PC + 1;
	cppVar_1238 = (cppVar_1238 & cppMask_un_16_);
	cppVar_1239 = ROM.rd(cppVar_1238);
	cppVar_1241 = (cppVar_1239 == 128);
	if (cppVar_1241) {
	cppVar_1237 = P0;
	} else {
	cppVar_1243 = PC + 1;
	cppVar_1243 = (cppVar_1243 & cppMask_un_16_);
	cppVar_1244 = ROM.rd(cppVar_1243);
	cppVar_1246 = (cppVar_1244 == 129);
	if (cppVar_1246) {
	cppVar_1242 = SP;
	} else {
	cppVar_1248 = PC + 1;
	cppVar_1248 = (cppVar_1248 & cppMask_un_16_);
	cppVar_1249 = ROM.rd(cppVar_1248);
	cppVar_1251 = (cppVar_1249 == 130);
	if (cppVar_1251) {
	cppVar_1247 = DPL;
	} else {
	cppVar_1253 = PC + 1;
	cppVar_1253 = (cppVar_1253 & cppMask_un_16_);
	cppVar_1254 = ROM.rd(cppVar_1253);
	cppVar_1256 = (cppVar_1254 == 131);
	if (cppVar_1256) {
	cppVar_1252 = DPH;
	} else {
	cppVar_1258 = PC + 1;
	cppVar_1258 = (cppVar_1258 & cppMask_un_16_);
	cppVar_1259 = ROM.rd(cppVar_1258);
	cppVar_1261 = (cppVar_1259 == 135);
	if (cppVar_1261) {
	cppVar_1257 = PCON;
	} else {
	cppVar_1263 = PC + 1;
	cppVar_1263 = (cppVar_1263 & cppMask_un_16_);
	cppVar_1264 = ROM.rd(cppVar_1263);
	cppVar_1266 = (cppVar_1264 == 136);
	if (cppVar_1266) {
	cppVar_1262 = TCON;
	} else {
	cppVar_1268 = PC + 1;
	cppVar_1268 = (cppVar_1268 & cppMask_un_16_);
	cppVar_1269 = ROM.rd(cppVar_1268);
	cppVar_1271 = (cppVar_1269 == 137);
	if (cppVar_1271) {
	cppVar_1267 = TMOD;
	} else {
	cppVar_1273 = PC + 1;
	cppVar_1273 = (cppVar_1273 & cppMask_un_16_);
	cppVar_1274 = ROM.rd(cppVar_1273);
	cppVar_1276 = (cppVar_1274 == 138);
	if (cppVar_1276) {
	cppVar_1272 = TL0;
	} else {
	cppVar_1278 = PC + 1;
	cppVar_1278 = (cppVar_1278 & cppMask_un_16_);
	cppVar_1279 = ROM.rd(cppVar_1278);
	cppVar_1281 = (cppVar_1279 == 140);
	if (cppVar_1281) {
	cppVar_1277 = TH0;
	} else {
	cppVar_1283 = PC + 1;
	cppVar_1283 = (cppVar_1283 & cppMask_un_16_);
	cppVar_1284 = ROM.rd(cppVar_1283);
	cppVar_1286 = (cppVar_1284 == 139);
	if (cppVar_1286) {
	cppVar_1282 = TL1;
	} else {
	cppVar_1288 = PC + 1;
	cppVar_1288 = (cppVar_1288 & cppMask_un_16_);
	cppVar_1289 = ROM.rd(cppVar_1288);
	cppVar_1291 = (cppVar_1289 == 141);
	if (cppVar_1291) {
	cppVar_1287 = TH1;
	} else {
	cppVar_1293 = PC + 1;
	cppVar_1293 = (cppVar_1293 & cppMask_un_16_);
	cppVar_1294 = ROM.rd(cppVar_1293);
	cppVar_1296 = (cppVar_1294 == 144);
	if (cppVar_1296) {
	cppVar_1292 = P1;
	} else {
	cppVar_1298 = PC + 1;
	cppVar_1298 = (cppVar_1298 & cppMask_un_16_);
	cppVar_1299 = ROM.rd(cppVar_1298);
	cppVar_1301 = (cppVar_1299 == 152);
	if (cppVar_1301) {
	cppVar_1297 = SCON;
	} else {
	cppVar_1303 = PC + 1;
	cppVar_1303 = (cppVar_1303 & cppMask_un_16_);
	cppVar_1304 = ROM.rd(cppVar_1303);
	cppVar_1306 = (cppVar_1304 == 153);
	if (cppVar_1306) {
	cppVar_1302 = SBUF;
	} else {
	cppVar_1308 = PC + 1;
	cppVar_1308 = (cppVar_1308 & cppMask_un_16_);
	cppVar_1309 = ROM.rd(cppVar_1308);
	cppVar_1311 = (cppVar_1309 == 160);
	if (cppVar_1311) {
	cppVar_1307 = P2;
	} else {
	cppVar_1313 = PC + 1;
	cppVar_1313 = (cppVar_1313 & cppMask_un_16_);
	cppVar_1314 = ROM.rd(cppVar_1313);
	cppVar_1316 = (cppVar_1314 == 168);
	if (cppVar_1316) {
	cppVar_1312 = IE;
	} else {
	cppVar_1318 = PC + 1;
	cppVar_1318 = (cppVar_1318 & cppMask_un_16_);
	cppVar_1319 = ROM.rd(cppVar_1318);
	cppVar_1321 = (cppVar_1319 == 176);
	if (cppVar_1321) {
	cppVar_1317 = P3;
	} else {
	cppVar_1323 = PC + 1;
	cppVar_1323 = (cppVar_1323 & cppMask_un_16_);
	cppVar_1324 = ROM.rd(cppVar_1323);
	cppVar_1326 = (cppVar_1324 == 184);
	if (cppVar_1326) {
	cppVar_1322 = IP;
	} else {
	cppVar_1328 = PC + 1;
	cppVar_1328 = (cppVar_1328 & cppMask_un_16_);
	cppVar_1329 = ROM.rd(cppVar_1328);
	cppVar_1331 = (cppVar_1329 == 208);
	if (cppVar_1331) {
	cppVar_1327 = PSW;
	} else {
	cppVar_1333 = PC + 1;
	cppVar_1333 = (cppVar_1333 & cppMask_un_16_);
	cppVar_1334 = ROM.rd(cppVar_1333);
	cppVar_1336 = (cppVar_1334 == 224);
	if (cppVar_1336) {
	cppVar_1332 = ACC;
	} else {
	cppVar_1338 = PC + 1;
	cppVar_1338 = (cppVar_1338 & cppMask_un_16_);
	cppVar_1339 = ROM.rd(cppVar_1338);
	cppVar_1341 = (cppVar_1339 == 240);
	if (cppVar_1341) {
	cppVar_1337 = B;
	} else {
	cppVar_1337 = 0;
	}
	cppVar_1332 = cppVar_1337;
	}
	cppVar_1327 = cppVar_1332;
	}
	cppVar_1322 = cppVar_1327;
	}
	cppVar_1317 = cppVar_1322;
	}
	cppVar_1312 = cppVar_1317;
	}
	cppVar_1307 = cppVar_1312;
	}
	cppVar_1302 = cppVar_1307;
	}
	cppVar_1297 = cppVar_1302;
	}
	cppVar_1292 = cppVar_1297;
	}
	cppVar_1287 = cppVar_1292;
	}
	cppVar_1282 = cppVar_1287;
	}
	cppVar_1277 = cppVar_1282;
	}
	cppVar_1272 = cppVar_1277;
	}
	cppVar_1267 = cppVar_1272;
	}
	cppVar_1262 = cppVar_1267;
	}
	cppVar_1257 = cppVar_1262;
	}
	cppVar_1252 = cppVar_1257;
	}
	cppVar_1247 = cppVar_1252;
	}
	cppVar_1242 = cppVar_1247;
	}
	cppVar_1237 = cppVar_1242;
	}
	cppVar_1227 = cppVar_1237;
	}
	cppVar_1219 = cppVar_1227;
	} else {
	cppVar_1344 = ROM.rd(PC);
	cppVar_1346 = (cppVar_1344 == 196);
	if (cppVar_1346) {
	cppVar_1347 = (ACC >> 0) & cppMask_un_4_;
	cppVar_1348 = (ACC >> 4) & cppMask_un_4_;
	cppVar_1349 = (cppVar_1347 << 4) | cppVar_1348;
	cppVar_1349 = (cppVar_1349 & cppMask_un_8_);
	cppVar_1343 = cppVar_1349;
	} else {
	cppVar_1351 = ROM.rd(PC);
	cppVar_1353 = (cppVar_1351 == 164);
	if (cppVar_1353) {
	cppVar_1354 = (ACC & cppMask_un_8_);
	cppVar_1355 = (B & cppMask_un_8_);
	cppVar_1356 = cppVar_1354 * cppVar_1355;
	cppVar_1356 = (cppVar_1356 & cppMask_un_16_);
	cppVar_1357 = (cppVar_1356 >> 0) & cppMask_un_8_;
	cppVar_1350 = cppVar_1357;
	} else {
	cppVar_1359 = ROM.rd(PC);
	cppVar_1361 = (cppVar_1359 == 159);
	if (cppVar_1361) {
	cppVar_1363 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1365 = (cppVar_1363 << 3) | 7;
	cppVar_1365 = (cppVar_1365 & cppMask_un_5_);
	cppVar_1366 = (0 << 5) | cppVar_1365;
	cppVar_1366 = (cppVar_1366 & cppMask_un_8_);
	cppVar_1367 = IRAM.rd(cppVar_1366);
	cppVar_1368 = ACC - cppVar_1367;
	cppVar_1368 = (cppVar_1368 & cppMask_un_8_);
	cppVar_1369 = (PSW >> 7) & cppMask_un_1_;
	cppVar_1370 = ((cppVar_1369 & cppMask_bit_1_) ? (cppVar_1369 | cppMask_sign_1_) : cppVar_1369);
	cppVar_1371 = cppVar_1368 + cppVar_1370;
	cppVar_1371 = (cppVar_1371 & cppMask_un_8_);
	cppVar_1358 = cppVar_1371;
	} else {
	cppVar_1373 = ROM.rd(PC);
	cppVar_1375 = (cppVar_1373 == 158);
	if (cppVar_1375) {
	cppVar_1377 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1379 = (cppVar_1377 << 3) | 6;
	cppVar_1379 = (cppVar_1379 & cppMask_un_5_);
	cppVar_1380 = (0 << 5) | cppVar_1379;
	cppVar_1380 = (cppVar_1380 & cppMask_un_8_);
	cppVar_1381 = IRAM.rd(cppVar_1380);
	cppVar_1382 = ACC - cppVar_1381;
	cppVar_1382 = (cppVar_1382 & cppMask_un_8_);
	cppVar_1383 = (PSW >> 7) & cppMask_un_1_;
	cppVar_1384 = ((cppVar_1383 & cppMask_bit_1_) ? (cppVar_1383 | cppMask_sign_1_) : cppVar_1383);
	cppVar_1385 = cppVar_1382 + cppVar_1384;
	cppVar_1385 = (cppVar_1385 & cppMask_un_8_);
	cppVar_1372 = cppVar_1385;
	} else {
	cppVar_1387 = ROM.rd(PC);
	cppVar_1389 = (cppVar_1387 == 157);
	if (cppVar_1389) {
	cppVar_1391 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1393 = (cppVar_1391 << 3) | 5;
	cppVar_1393 = (cppVar_1393 & cppMask_un_5_);
	cppVar_1394 = (0 << 5) | cppVar_1393;
	cppVar_1394 = (cppVar_1394 & cppMask_un_8_);
	cppVar_1395 = IRAM.rd(cppVar_1394);
	cppVar_1396 = ACC - cppVar_1395;
	cppVar_1396 = (cppVar_1396 & cppMask_un_8_);
	cppVar_1397 = (PSW >> 7) & cppMask_un_1_;
	cppVar_1398 = ((cppVar_1397 & cppMask_bit_1_) ? (cppVar_1397 | cppMask_sign_1_) : cppVar_1397);
	cppVar_1399 = cppVar_1396 + cppVar_1398;
	cppVar_1399 = (cppVar_1399 & cppMask_un_8_);
	cppVar_1386 = cppVar_1399;
	} else {
	cppVar_1401 = ROM.rd(PC);
	cppVar_1403 = (cppVar_1401 == 156);
	if (cppVar_1403) {
	cppVar_1405 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1407 = (cppVar_1405 << 3) | 4;
	cppVar_1407 = (cppVar_1407 & cppMask_un_5_);
	cppVar_1408 = (0 << 5) | cppVar_1407;
	cppVar_1408 = (cppVar_1408 & cppMask_un_8_);
	cppVar_1409 = IRAM.rd(cppVar_1408);
	cppVar_1410 = ACC - cppVar_1409;
	cppVar_1410 = (cppVar_1410 & cppMask_un_8_);
	cppVar_1411 = (PSW >> 7) & cppMask_un_1_;
	cppVar_1412 = ((cppVar_1411 & cppMask_bit_1_) ? (cppVar_1411 | cppMask_sign_1_) : cppVar_1411);
	cppVar_1413 = cppVar_1410 + cppVar_1412;
	cppVar_1413 = (cppVar_1413 & cppMask_un_8_);
	cppVar_1400 = cppVar_1413;
	} else {
	cppVar_1415 = ROM.rd(PC);
	cppVar_1417 = (cppVar_1415 == 155);
	if (cppVar_1417) {
	cppVar_1419 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1421 = (cppVar_1419 << 3) | 3;
	cppVar_1421 = (cppVar_1421 & cppMask_un_5_);
	cppVar_1422 = (0 << 5) | cppVar_1421;
	cppVar_1422 = (cppVar_1422 & cppMask_un_8_);
	cppVar_1423 = IRAM.rd(cppVar_1422);
	cppVar_1424 = ACC - cppVar_1423;
	cppVar_1424 = (cppVar_1424 & cppMask_un_8_);
	cppVar_1425 = (PSW >> 7) & cppMask_un_1_;
	cppVar_1426 = ((cppVar_1425 & cppMask_bit_1_) ? (cppVar_1425 | cppMask_sign_1_) : cppVar_1425);
	cppVar_1427 = cppVar_1424 + cppVar_1426;
	cppVar_1427 = (cppVar_1427 & cppMask_un_8_);
	cppVar_1414 = cppVar_1427;
	} else {
	cppVar_1429 = ROM.rd(PC);
	cppVar_1431 = (cppVar_1429 == 154);
	if (cppVar_1431) {
	cppVar_1433 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1435 = (cppVar_1433 << 3) | 2;
	cppVar_1435 = (cppVar_1435 & cppMask_un_5_);
	cppVar_1436 = (0 << 5) | cppVar_1435;
	cppVar_1436 = (cppVar_1436 & cppMask_un_8_);
	cppVar_1437 = IRAM.rd(cppVar_1436);
	cppVar_1438 = ACC - cppVar_1437;
	cppVar_1438 = (cppVar_1438 & cppMask_un_8_);
	cppVar_1439 = (PSW >> 7) & cppMask_un_1_;
	cppVar_1440 = ((cppVar_1439 & cppMask_bit_1_) ? (cppVar_1439 | cppMask_sign_1_) : cppVar_1439);
	cppVar_1441 = cppVar_1438 + cppVar_1440;
	cppVar_1441 = (cppVar_1441 & cppMask_un_8_);
	cppVar_1428 = cppVar_1441;
	} else {
	cppVar_1443 = ROM.rd(PC);
	cppVar_1445 = (cppVar_1443 == 153);
	if (cppVar_1445) {
	cppVar_1447 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1449 = (cppVar_1447 << 3) | 1;
	cppVar_1449 = (cppVar_1449 & cppMask_un_5_);
	cppVar_1450 = (0 << 5) | cppVar_1449;
	cppVar_1450 = (cppVar_1450 & cppMask_un_8_);
	cppVar_1451 = IRAM.rd(cppVar_1450);
	cppVar_1452 = ACC - cppVar_1451;
	cppVar_1452 = (cppVar_1452 & cppMask_un_8_);
	cppVar_1453 = (PSW >> 7) & cppMask_un_1_;
	cppVar_1454 = ((cppVar_1453 & cppMask_bit_1_) ? (cppVar_1453 | cppMask_sign_1_) : cppVar_1453);
	cppVar_1455 = cppVar_1452 + cppVar_1454;
	cppVar_1455 = (cppVar_1455 & cppMask_un_8_);
	cppVar_1442 = cppVar_1455;
	} else {
	cppVar_1457 = ROM.rd(PC);
	cppVar_1459 = (cppVar_1457 == 152);
	if (cppVar_1459) {
	cppVar_1461 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1463 = (cppVar_1461 << 3) | 0;
	cppVar_1463 = (cppVar_1463 & cppMask_un_5_);
	cppVar_1464 = (0 << 5) | cppVar_1463;
	cppVar_1464 = (cppVar_1464 & cppMask_un_8_);
	cppVar_1465 = IRAM.rd(cppVar_1464);
	cppVar_1466 = ACC - cppVar_1465;
	cppVar_1466 = (cppVar_1466 & cppMask_un_8_);
	cppVar_1467 = (PSW >> 7) & cppMask_un_1_;
	cppVar_1468 = ((cppVar_1467 & cppMask_bit_1_) ? (cppVar_1467 | cppMask_sign_1_) : cppVar_1467);
	cppVar_1469 = cppVar_1466 + cppVar_1468;
	cppVar_1469 = (cppVar_1469 & cppMask_un_8_);
	cppVar_1456 = cppVar_1469;
	} else {
	cppVar_1471 = ROM.rd(PC);
	cppVar_1473 = (cppVar_1471 == 151);
	if (cppVar_1473) {
	cppVar_1475 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1477 = (cppVar_1475 << 3) | 1;
	cppVar_1477 = (cppVar_1477 & cppMask_un_5_);
	cppVar_1478 = (0 << 5) | cppVar_1477;
	cppVar_1478 = (cppVar_1478 & cppMask_un_8_);
	cppVar_1479 = IRAM.rd(cppVar_1478);
	cppVar_1480 = IRAM.rd(cppVar_1479);
	cppVar_1481 = ACC - cppVar_1480;
	cppVar_1481 = (cppVar_1481 & cppMask_un_8_);
	cppVar_1482 = (PSW >> 7) & cppMask_un_1_;
	cppVar_1483 = ((cppVar_1482 & cppMask_bit_1_) ? (cppVar_1482 | cppMask_sign_1_) : cppVar_1482);
	cppVar_1484 = cppVar_1481 + cppVar_1483;
	cppVar_1484 = (cppVar_1484 & cppMask_un_8_);
	cppVar_1470 = cppVar_1484;
	} else {
	cppVar_1486 = ROM.rd(PC);
	cppVar_1488 = (cppVar_1486 == 150);
	if (cppVar_1488) {
	cppVar_1490 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1492 = (cppVar_1490 << 3) | 0;
	cppVar_1492 = (cppVar_1492 & cppMask_un_5_);
	cppVar_1493 = (0 << 5) | cppVar_1492;
	cppVar_1493 = (cppVar_1493 & cppMask_un_8_);
	cppVar_1494 = IRAM.rd(cppVar_1493);
	cppVar_1495 = IRAM.rd(cppVar_1494);
	cppVar_1496 = ACC - cppVar_1495;
	cppVar_1496 = (cppVar_1496 & cppMask_un_8_);
	cppVar_1497 = (PSW >> 7) & cppMask_un_1_;
	cppVar_1498 = ((cppVar_1497 & cppMask_bit_1_) ? (cppVar_1497 | cppMask_sign_1_) : cppVar_1497);
	cppVar_1499 = cppVar_1496 + cppVar_1498;
	cppVar_1499 = (cppVar_1499 & cppMask_un_8_);
	cppVar_1485 = cppVar_1499;
	} else {
	cppVar_1501 = ROM.rd(PC);
	cppVar_1503 = (cppVar_1501 == 149);
	if (cppVar_1503) {
	cppVar_1506 = PC + 1;
	cppVar_1506 = (cppVar_1506 & cppMask_un_16_);
	cppVar_1507 = ROM.rd(cppVar_1506);
	cppVar_1508 = (cppVar_1507 >> 7) & cppMask_un_1_;
	cppVar_1510 = (cppVar_1508 == 0);
	if (cppVar_1510) {
	cppVar_1511 = PC + 1;
	cppVar_1511 = (cppVar_1511 & cppMask_un_16_);
	cppVar_1512 = ROM.rd(cppVar_1511);
	cppVar_1513 = IRAM.rd(cppVar_1512);
	cppVar_1504 = cppVar_1513;
	} else {
	cppVar_1515 = PC + 1;
	cppVar_1515 = (cppVar_1515 & cppMask_un_16_);
	cppVar_1516 = ROM.rd(cppVar_1515);
	cppVar_1518 = (cppVar_1516 == 128);
	if (cppVar_1518) {
	cppVar_1514 = P0;
	} else {
	cppVar_1520 = PC + 1;
	cppVar_1520 = (cppVar_1520 & cppMask_un_16_);
	cppVar_1521 = ROM.rd(cppVar_1520);
	cppVar_1523 = (cppVar_1521 == 129);
	if (cppVar_1523) {
	cppVar_1519 = SP;
	} else {
	cppVar_1525 = PC + 1;
	cppVar_1525 = (cppVar_1525 & cppMask_un_16_);
	cppVar_1526 = ROM.rd(cppVar_1525);
	cppVar_1528 = (cppVar_1526 == 130);
	if (cppVar_1528) {
	cppVar_1524 = DPL;
	} else {
	cppVar_1530 = PC + 1;
	cppVar_1530 = (cppVar_1530 & cppMask_un_16_);
	cppVar_1531 = ROM.rd(cppVar_1530);
	cppVar_1533 = (cppVar_1531 == 131);
	if (cppVar_1533) {
	cppVar_1529 = DPH;
	} else {
	cppVar_1535 = PC + 1;
	cppVar_1535 = (cppVar_1535 & cppMask_un_16_);
	cppVar_1536 = ROM.rd(cppVar_1535);
	cppVar_1538 = (cppVar_1536 == 135);
	if (cppVar_1538) {
	cppVar_1534 = PCON;
	} else {
	cppVar_1540 = PC + 1;
	cppVar_1540 = (cppVar_1540 & cppMask_un_16_);
	cppVar_1541 = ROM.rd(cppVar_1540);
	cppVar_1543 = (cppVar_1541 == 136);
	if (cppVar_1543) {
	cppVar_1539 = TCON;
	} else {
	cppVar_1545 = PC + 1;
	cppVar_1545 = (cppVar_1545 & cppMask_un_16_);
	cppVar_1546 = ROM.rd(cppVar_1545);
	cppVar_1548 = (cppVar_1546 == 137);
	if (cppVar_1548) {
	cppVar_1544 = TMOD;
	} else {
	cppVar_1550 = PC + 1;
	cppVar_1550 = (cppVar_1550 & cppMask_un_16_);
	cppVar_1551 = ROM.rd(cppVar_1550);
	cppVar_1553 = (cppVar_1551 == 138);
	if (cppVar_1553) {
	cppVar_1549 = TL0;
	} else {
	cppVar_1555 = PC + 1;
	cppVar_1555 = (cppVar_1555 & cppMask_un_16_);
	cppVar_1556 = ROM.rd(cppVar_1555);
	cppVar_1558 = (cppVar_1556 == 140);
	if (cppVar_1558) {
	cppVar_1554 = TH0;
	} else {
	cppVar_1560 = PC + 1;
	cppVar_1560 = (cppVar_1560 & cppMask_un_16_);
	cppVar_1561 = ROM.rd(cppVar_1560);
	cppVar_1563 = (cppVar_1561 == 139);
	if (cppVar_1563) {
	cppVar_1559 = TL1;
	} else {
	cppVar_1565 = PC + 1;
	cppVar_1565 = (cppVar_1565 & cppMask_un_16_);
	cppVar_1566 = ROM.rd(cppVar_1565);
	cppVar_1568 = (cppVar_1566 == 141);
	if (cppVar_1568) {
	cppVar_1564 = TH1;
	} else {
	cppVar_1570 = PC + 1;
	cppVar_1570 = (cppVar_1570 & cppMask_un_16_);
	cppVar_1571 = ROM.rd(cppVar_1570);
	cppVar_1573 = (cppVar_1571 == 144);
	if (cppVar_1573) {
	cppVar_1569 = P1;
	} else {
	cppVar_1575 = PC + 1;
	cppVar_1575 = (cppVar_1575 & cppMask_un_16_);
	cppVar_1576 = ROM.rd(cppVar_1575);
	cppVar_1578 = (cppVar_1576 == 152);
	if (cppVar_1578) {
	cppVar_1574 = SCON;
	} else {
	cppVar_1580 = PC + 1;
	cppVar_1580 = (cppVar_1580 & cppMask_un_16_);
	cppVar_1581 = ROM.rd(cppVar_1580);
	cppVar_1583 = (cppVar_1581 == 153);
	if (cppVar_1583) {
	cppVar_1579 = SBUF;
	} else {
	cppVar_1585 = PC + 1;
	cppVar_1585 = (cppVar_1585 & cppMask_un_16_);
	cppVar_1586 = ROM.rd(cppVar_1585);
	cppVar_1588 = (cppVar_1586 == 160);
	if (cppVar_1588) {
	cppVar_1584 = P2;
	} else {
	cppVar_1590 = PC + 1;
	cppVar_1590 = (cppVar_1590 & cppMask_un_16_);
	cppVar_1591 = ROM.rd(cppVar_1590);
	cppVar_1593 = (cppVar_1591 == 168);
	if (cppVar_1593) {
	cppVar_1589 = IE;
	} else {
	cppVar_1595 = PC + 1;
	cppVar_1595 = (cppVar_1595 & cppMask_un_16_);
	cppVar_1596 = ROM.rd(cppVar_1595);
	cppVar_1598 = (cppVar_1596 == 176);
	if (cppVar_1598) {
	cppVar_1594 = P3;
	} else {
	cppVar_1600 = PC + 1;
	cppVar_1600 = (cppVar_1600 & cppMask_un_16_);
	cppVar_1601 = ROM.rd(cppVar_1600);
	cppVar_1603 = (cppVar_1601 == 184);
	if (cppVar_1603) {
	cppVar_1599 = IP;
	} else {
	cppVar_1605 = PC + 1;
	cppVar_1605 = (cppVar_1605 & cppMask_un_16_);
	cppVar_1606 = ROM.rd(cppVar_1605);
	cppVar_1608 = (cppVar_1606 == 208);
	if (cppVar_1608) {
	cppVar_1604 = PSW;
	} else {
	cppVar_1610 = PC + 1;
	cppVar_1610 = (cppVar_1610 & cppMask_un_16_);
	cppVar_1611 = ROM.rd(cppVar_1610);
	cppVar_1613 = (cppVar_1611 == 224);
	if (cppVar_1613) {
	cppVar_1609 = ACC;
	} else {
	cppVar_1615 = PC + 1;
	cppVar_1615 = (cppVar_1615 & cppMask_un_16_);
	cppVar_1616 = ROM.rd(cppVar_1615);
	cppVar_1618 = (cppVar_1616 == 240);
	if (cppVar_1618) {
	cppVar_1614 = B;
	} else {
	cppVar_1614 = 0;
	}
	cppVar_1609 = cppVar_1614;
	}
	cppVar_1604 = cppVar_1609;
	}
	cppVar_1599 = cppVar_1604;
	}
	cppVar_1594 = cppVar_1599;
	}
	cppVar_1589 = cppVar_1594;
	}
	cppVar_1584 = cppVar_1589;
	}
	cppVar_1579 = cppVar_1584;
	}
	cppVar_1574 = cppVar_1579;
	}
	cppVar_1569 = cppVar_1574;
	}
	cppVar_1564 = cppVar_1569;
	}
	cppVar_1559 = cppVar_1564;
	}
	cppVar_1554 = cppVar_1559;
	}
	cppVar_1549 = cppVar_1554;
	}
	cppVar_1544 = cppVar_1549;
	}
	cppVar_1539 = cppVar_1544;
	}
	cppVar_1534 = cppVar_1539;
	}
	cppVar_1529 = cppVar_1534;
	}
	cppVar_1524 = cppVar_1529;
	}
	cppVar_1519 = cppVar_1524;
	}
	cppVar_1514 = cppVar_1519;
	}
	cppVar_1504 = cppVar_1514;
	}
	cppVar_1620 = ACC - cppVar_1504;
	cppVar_1620 = (cppVar_1620 & cppMask_un_8_);
	cppVar_1621 = (PSW >> 7) & cppMask_un_1_;
	cppVar_1622 = ((cppVar_1621 & cppMask_bit_1_) ? (cppVar_1621 | cppMask_sign_1_) : cppVar_1621);
	cppVar_1623 = cppVar_1620 + cppVar_1622;
	cppVar_1623 = (cppVar_1623 & cppMask_un_8_);
	cppVar_1500 = cppVar_1623;
	} else {
	cppVar_1625 = ROM.rd(PC);
	cppVar_1627 = (cppVar_1625 == 148);
	if (cppVar_1627) {
	cppVar_1629 = PC + 1;
	cppVar_1629 = (cppVar_1629 & cppMask_un_16_);
	cppVar_1630 = ROM.rd(cppVar_1629);
	cppVar_1631 = ACC - cppVar_1630;
	cppVar_1631 = (cppVar_1631 & cppMask_un_8_);
	cppVar_1632 = (PSW >> 7) & cppMask_un_1_;
	cppVar_1633 = ((cppVar_1632 & cppMask_bit_1_) ? (cppVar_1632 | cppMask_sign_1_) : cppVar_1632);
	cppVar_1634 = cppVar_1631 + cppVar_1633;
	cppVar_1634 = (cppVar_1634 & cppMask_un_8_);
	cppVar_1624 = cppVar_1634;
	} else {
	cppVar_1636 = ROM.rd(PC);
	cppVar_1638 = (cppVar_1636 == 147);
	if (cppVar_1638) {
	cppVar_1639 = (ACC & cppMask_un_8_);
	cppVar_1640 = (DPH << 8) | DPL;
	cppVar_1640 = (cppVar_1640 & cppMask_un_16_);
	cppVar_1641 = cppVar_1639 + cppVar_1640;
	cppVar_1641 = (cppVar_1641 & cppMask_un_16_);
	cppVar_1642 = ROM.rd(cppVar_1641);
	cppVar_1635 = cppVar_1642;
	} else {
	cppVar_1644 = ROM.rd(PC);
	cppVar_1646 = (cppVar_1644 == 132);
	if (cppVar_1646) {
	cppVar_1649 = (B == 0);
	if (cppVar_1649) {
	cppVar_1647 = 255;
	} else {
	cppVar_1651 = ACC / B;
	cppVar_1651 = (cppVar_1651 & cppMask_un_8_);
	cppVar_1647 = cppVar_1651;
	}
	cppVar_1643 = cppVar_1647;
	} else {
	cppVar_1653 = ROM.rd(PC);
	cppVar_1655 = (cppVar_1653 == 131);
	if (cppVar_1655) {
	cppVar_1656 = (ACC & cppMask_un_8_);
	cppVar_1658 = PC + 1;
	cppVar_1658 = (cppVar_1658 & cppMask_un_16_);
	cppVar_1659 = cppVar_1656 + cppVar_1658;
	cppVar_1659 = (cppVar_1659 & cppMask_un_16_);
	cppVar_1660 = ROM.rd(cppVar_1659);
	cppVar_1652 = cppVar_1660;
	} else {
	cppVar_1662 = ROM.rd(PC);
	cppVar_1664 = (cppVar_1662 == 116);
	if (cppVar_1664) {
	cppVar_1666 = PC + 1;
	cppVar_1666 = (cppVar_1666 & cppMask_un_16_);
	cppVar_1667 = ROM.rd(cppVar_1666);
	cppVar_1661 = cppVar_1667;
	} else {
	cppVar_1669 = ROM.rd(PC);
	cppVar_1671 = (cppVar_1669 == 111);
	if (cppVar_1671) {
	cppVar_1673 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1675 = (cppVar_1673 << 3) | 7;
	cppVar_1675 = (cppVar_1675 & cppMask_un_5_);
	cppVar_1676 = (0 << 5) | cppVar_1675;
	cppVar_1676 = (cppVar_1676 & cppMask_un_8_);
	cppVar_1677 = IRAM.rd(cppVar_1676);
	cppVar_1678 = ACC ^ cppVar_1677;
	cppVar_1668 = cppVar_1678;
	} else {
	cppVar_1680 = ROM.rd(PC);
	cppVar_1682 = (cppVar_1680 == 110);
	if (cppVar_1682) {
	cppVar_1684 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1686 = (cppVar_1684 << 3) | 6;
	cppVar_1686 = (cppVar_1686 & cppMask_un_5_);
	cppVar_1687 = (0 << 5) | cppVar_1686;
	cppVar_1687 = (cppVar_1687 & cppMask_un_8_);
	cppVar_1688 = IRAM.rd(cppVar_1687);
	cppVar_1689 = ACC ^ cppVar_1688;
	cppVar_1679 = cppVar_1689;
	} else {
	cppVar_1691 = ROM.rd(PC);
	cppVar_1693 = (cppVar_1691 == 109);
	if (cppVar_1693) {
	cppVar_1695 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1697 = (cppVar_1695 << 3) | 5;
	cppVar_1697 = (cppVar_1697 & cppMask_un_5_);
	cppVar_1698 = (0 << 5) | cppVar_1697;
	cppVar_1698 = (cppVar_1698 & cppMask_un_8_);
	cppVar_1699 = IRAM.rd(cppVar_1698);
	cppVar_1700 = ACC ^ cppVar_1699;
	cppVar_1690 = cppVar_1700;
	} else {
	cppVar_1702 = ROM.rd(PC);
	cppVar_1704 = (cppVar_1702 == 108);
	if (cppVar_1704) {
	cppVar_1706 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1708 = (cppVar_1706 << 3) | 4;
	cppVar_1708 = (cppVar_1708 & cppMask_un_5_);
	cppVar_1709 = (0 << 5) | cppVar_1708;
	cppVar_1709 = (cppVar_1709 & cppMask_un_8_);
	cppVar_1710 = IRAM.rd(cppVar_1709);
	cppVar_1711 = ACC ^ cppVar_1710;
	cppVar_1701 = cppVar_1711;
	} else {
	cppVar_1713 = ROM.rd(PC);
	cppVar_1715 = (cppVar_1713 == 107);
	if (cppVar_1715) {
	cppVar_1717 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1719 = (cppVar_1717 << 3) | 3;
	cppVar_1719 = (cppVar_1719 & cppMask_un_5_);
	cppVar_1720 = (0 << 5) | cppVar_1719;
	cppVar_1720 = (cppVar_1720 & cppMask_un_8_);
	cppVar_1721 = IRAM.rd(cppVar_1720);
	cppVar_1722 = ACC ^ cppVar_1721;
	cppVar_1712 = cppVar_1722;
	} else {
	cppVar_1724 = ROM.rd(PC);
	cppVar_1726 = (cppVar_1724 == 106);
	if (cppVar_1726) {
	cppVar_1728 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1730 = (cppVar_1728 << 3) | 2;
	cppVar_1730 = (cppVar_1730 & cppMask_un_5_);
	cppVar_1731 = (0 << 5) | cppVar_1730;
	cppVar_1731 = (cppVar_1731 & cppMask_un_8_);
	cppVar_1732 = IRAM.rd(cppVar_1731);
	cppVar_1733 = ACC ^ cppVar_1732;
	cppVar_1723 = cppVar_1733;
	} else {
	cppVar_1735 = ROM.rd(PC);
	cppVar_1737 = (cppVar_1735 == 105);
	if (cppVar_1737) {
	cppVar_1739 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1741 = (cppVar_1739 << 3) | 1;
	cppVar_1741 = (cppVar_1741 & cppMask_un_5_);
	cppVar_1742 = (0 << 5) | cppVar_1741;
	cppVar_1742 = (cppVar_1742 & cppMask_un_8_);
	cppVar_1743 = IRAM.rd(cppVar_1742);
	cppVar_1744 = ACC ^ cppVar_1743;
	cppVar_1734 = cppVar_1744;
	} else {
	cppVar_1746 = ROM.rd(PC);
	cppVar_1748 = (cppVar_1746 == 104);
	if (cppVar_1748) {
	cppVar_1750 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1752 = (cppVar_1750 << 3) | 0;
	cppVar_1752 = (cppVar_1752 & cppMask_un_5_);
	cppVar_1753 = (0 << 5) | cppVar_1752;
	cppVar_1753 = (cppVar_1753 & cppMask_un_8_);
	cppVar_1754 = IRAM.rd(cppVar_1753);
	cppVar_1755 = ACC ^ cppVar_1754;
	cppVar_1745 = cppVar_1755;
	} else {
	cppVar_1757 = ROM.rd(PC);
	cppVar_1759 = (cppVar_1757 == 103);
	if (cppVar_1759) {
	cppVar_1761 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1763 = (cppVar_1761 << 3) | 1;
	cppVar_1763 = (cppVar_1763 & cppMask_un_5_);
	cppVar_1764 = (0 << 5) | cppVar_1763;
	cppVar_1764 = (cppVar_1764 & cppMask_un_8_);
	cppVar_1765 = IRAM.rd(cppVar_1764);
	cppVar_1766 = IRAM.rd(cppVar_1765);
	cppVar_1767 = ACC ^ cppVar_1766;
	cppVar_1756 = cppVar_1767;
	} else {
	cppVar_1769 = ROM.rd(PC);
	cppVar_1771 = (cppVar_1769 == 102);
	if (cppVar_1771) {
	cppVar_1773 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1775 = (cppVar_1773 << 3) | 0;
	cppVar_1775 = (cppVar_1775 & cppMask_un_5_);
	cppVar_1776 = (0 << 5) | cppVar_1775;
	cppVar_1776 = (cppVar_1776 & cppMask_un_8_);
	cppVar_1777 = IRAM.rd(cppVar_1776);
	cppVar_1778 = IRAM.rd(cppVar_1777);
	cppVar_1779 = ACC ^ cppVar_1778;
	cppVar_1768 = cppVar_1779;
	} else {
	cppVar_1781 = ROM.rd(PC);
	cppVar_1783 = (cppVar_1781 == 101);
	if (cppVar_1783) {
	cppVar_1786 = PC + 1;
	cppVar_1786 = (cppVar_1786 & cppMask_un_16_);
	cppVar_1787 = ROM.rd(cppVar_1786);
	cppVar_1788 = (cppVar_1787 >> 7) & cppMask_un_1_;
	cppVar_1790 = (cppVar_1788 == 0);
	if (cppVar_1790) {
	cppVar_1791 = PC + 1;
	cppVar_1791 = (cppVar_1791 & cppMask_un_16_);
	cppVar_1792 = ROM.rd(cppVar_1791);
	cppVar_1793 = IRAM.rd(cppVar_1792);
	cppVar_1784 = cppVar_1793;
	} else {
	cppVar_1795 = PC + 1;
	cppVar_1795 = (cppVar_1795 & cppMask_un_16_);
	cppVar_1796 = ROM.rd(cppVar_1795);
	cppVar_1798 = (cppVar_1796 == 128);
	if (cppVar_1798) {
	cppVar_1794 = P0;
	} else {
	cppVar_1800 = PC + 1;
	cppVar_1800 = (cppVar_1800 & cppMask_un_16_);
	cppVar_1801 = ROM.rd(cppVar_1800);
	cppVar_1803 = (cppVar_1801 == 129);
	if (cppVar_1803) {
	cppVar_1799 = SP;
	} else {
	cppVar_1805 = PC + 1;
	cppVar_1805 = (cppVar_1805 & cppMask_un_16_);
	cppVar_1806 = ROM.rd(cppVar_1805);
	cppVar_1808 = (cppVar_1806 == 130);
	if (cppVar_1808) {
	cppVar_1804 = DPL;
	} else {
	cppVar_1810 = PC + 1;
	cppVar_1810 = (cppVar_1810 & cppMask_un_16_);
	cppVar_1811 = ROM.rd(cppVar_1810);
	cppVar_1813 = (cppVar_1811 == 131);
	if (cppVar_1813) {
	cppVar_1809 = DPH;
	} else {
	cppVar_1815 = PC + 1;
	cppVar_1815 = (cppVar_1815 & cppMask_un_16_);
	cppVar_1816 = ROM.rd(cppVar_1815);
	cppVar_1818 = (cppVar_1816 == 135);
	if (cppVar_1818) {
	cppVar_1814 = PCON;
	} else {
	cppVar_1820 = PC + 1;
	cppVar_1820 = (cppVar_1820 & cppMask_un_16_);
	cppVar_1821 = ROM.rd(cppVar_1820);
	cppVar_1823 = (cppVar_1821 == 136);
	if (cppVar_1823) {
	cppVar_1819 = TCON;
	} else {
	cppVar_1825 = PC + 1;
	cppVar_1825 = (cppVar_1825 & cppMask_un_16_);
	cppVar_1826 = ROM.rd(cppVar_1825);
	cppVar_1828 = (cppVar_1826 == 137);
	if (cppVar_1828) {
	cppVar_1824 = TMOD;
	} else {
	cppVar_1830 = PC + 1;
	cppVar_1830 = (cppVar_1830 & cppMask_un_16_);
	cppVar_1831 = ROM.rd(cppVar_1830);
	cppVar_1833 = (cppVar_1831 == 138);
	if (cppVar_1833) {
	cppVar_1829 = TL0;
	} else {
	cppVar_1835 = PC + 1;
	cppVar_1835 = (cppVar_1835 & cppMask_un_16_);
	cppVar_1836 = ROM.rd(cppVar_1835);
	cppVar_1838 = (cppVar_1836 == 140);
	if (cppVar_1838) {
	cppVar_1834 = TH0;
	} else {
	cppVar_1840 = PC + 1;
	cppVar_1840 = (cppVar_1840 & cppMask_un_16_);
	cppVar_1841 = ROM.rd(cppVar_1840);
	cppVar_1843 = (cppVar_1841 == 139);
	if (cppVar_1843) {
	cppVar_1839 = TL1;
	} else {
	cppVar_1845 = PC + 1;
	cppVar_1845 = (cppVar_1845 & cppMask_un_16_);
	cppVar_1846 = ROM.rd(cppVar_1845);
	cppVar_1848 = (cppVar_1846 == 141);
	if (cppVar_1848) {
	cppVar_1844 = TH1;
	} else {
	cppVar_1850 = PC + 1;
	cppVar_1850 = (cppVar_1850 & cppMask_un_16_);
	cppVar_1851 = ROM.rd(cppVar_1850);
	cppVar_1853 = (cppVar_1851 == 144);
	if (cppVar_1853) {
	cppVar_1849 = P1;
	} else {
	cppVar_1855 = PC + 1;
	cppVar_1855 = (cppVar_1855 & cppMask_un_16_);
	cppVar_1856 = ROM.rd(cppVar_1855);
	cppVar_1858 = (cppVar_1856 == 152);
	if (cppVar_1858) {
	cppVar_1854 = SCON;
	} else {
	cppVar_1860 = PC + 1;
	cppVar_1860 = (cppVar_1860 & cppMask_un_16_);
	cppVar_1861 = ROM.rd(cppVar_1860);
	cppVar_1863 = (cppVar_1861 == 153);
	if (cppVar_1863) {
	cppVar_1859 = SBUF;
	} else {
	cppVar_1865 = PC + 1;
	cppVar_1865 = (cppVar_1865 & cppMask_un_16_);
	cppVar_1866 = ROM.rd(cppVar_1865);
	cppVar_1868 = (cppVar_1866 == 160);
	if (cppVar_1868) {
	cppVar_1864 = P2;
	} else {
	cppVar_1870 = PC + 1;
	cppVar_1870 = (cppVar_1870 & cppMask_un_16_);
	cppVar_1871 = ROM.rd(cppVar_1870);
	cppVar_1873 = (cppVar_1871 == 168);
	if (cppVar_1873) {
	cppVar_1869 = IE;
	} else {
	cppVar_1875 = PC + 1;
	cppVar_1875 = (cppVar_1875 & cppMask_un_16_);
	cppVar_1876 = ROM.rd(cppVar_1875);
	cppVar_1878 = (cppVar_1876 == 176);
	if (cppVar_1878) {
	cppVar_1874 = P3;
	} else {
	cppVar_1880 = PC + 1;
	cppVar_1880 = (cppVar_1880 & cppMask_un_16_);
	cppVar_1881 = ROM.rd(cppVar_1880);
	cppVar_1883 = (cppVar_1881 == 184);
	if (cppVar_1883) {
	cppVar_1879 = IP;
	} else {
	cppVar_1885 = PC + 1;
	cppVar_1885 = (cppVar_1885 & cppMask_un_16_);
	cppVar_1886 = ROM.rd(cppVar_1885);
	cppVar_1888 = (cppVar_1886 == 208);
	if (cppVar_1888) {
	cppVar_1884 = PSW;
	} else {
	cppVar_1890 = PC + 1;
	cppVar_1890 = (cppVar_1890 & cppMask_un_16_);
	cppVar_1891 = ROM.rd(cppVar_1890);
	cppVar_1893 = (cppVar_1891 == 224);
	if (cppVar_1893) {
	cppVar_1889 = ACC;
	} else {
	cppVar_1895 = PC + 1;
	cppVar_1895 = (cppVar_1895 & cppMask_un_16_);
	cppVar_1896 = ROM.rd(cppVar_1895);
	cppVar_1898 = (cppVar_1896 == 240);
	if (cppVar_1898) {
	cppVar_1894 = B;
	} else {
	cppVar_1894 = 0;
	}
	cppVar_1889 = cppVar_1894;
	}
	cppVar_1884 = cppVar_1889;
	}
	cppVar_1879 = cppVar_1884;
	}
	cppVar_1874 = cppVar_1879;
	}
	cppVar_1869 = cppVar_1874;
	}
	cppVar_1864 = cppVar_1869;
	}
	cppVar_1859 = cppVar_1864;
	}
	cppVar_1854 = cppVar_1859;
	}
	cppVar_1849 = cppVar_1854;
	}
	cppVar_1844 = cppVar_1849;
	}
	cppVar_1839 = cppVar_1844;
	}
	cppVar_1834 = cppVar_1839;
	}
	cppVar_1829 = cppVar_1834;
	}
	cppVar_1824 = cppVar_1829;
	}
	cppVar_1819 = cppVar_1824;
	}
	cppVar_1814 = cppVar_1819;
	}
	cppVar_1809 = cppVar_1814;
	}
	cppVar_1804 = cppVar_1809;
	}
	cppVar_1799 = cppVar_1804;
	}
	cppVar_1794 = cppVar_1799;
	}
	cppVar_1784 = cppVar_1794;
	}
	cppVar_1900 = ACC ^ cppVar_1784;
	cppVar_1780 = cppVar_1900;
	} else {
	cppVar_1902 = ROM.rd(PC);
	cppVar_1904 = (cppVar_1902 == 100);
	if (cppVar_1904) {
	cppVar_1906 = PC + 1;
	cppVar_1906 = (cppVar_1906 & cppMask_un_16_);
	cppVar_1907 = ROM.rd(cppVar_1906);
	cppVar_1908 = ACC ^ cppVar_1907;
	cppVar_1901 = cppVar_1908;
	} else {
	cppVar_1910 = ROM.rd(PC);
	cppVar_1912 = (cppVar_1910 == 95);
	if (cppVar_1912) {
	cppVar_1914 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1916 = (cppVar_1914 << 3) | 7;
	cppVar_1916 = (cppVar_1916 & cppMask_un_5_);
	cppVar_1917 = (0 << 5) | cppVar_1916;
	cppVar_1917 = (cppVar_1917 & cppMask_un_8_);
	cppVar_1918 = IRAM.rd(cppVar_1917);
	cppVar_1919 = ACC & cppVar_1918;
	cppVar_1909 = cppVar_1919;
	} else {
	cppVar_1921 = ROM.rd(PC);
	cppVar_1923 = (cppVar_1921 == 94);
	if (cppVar_1923) {
	cppVar_1925 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1927 = (cppVar_1925 << 3) | 6;
	cppVar_1927 = (cppVar_1927 & cppMask_un_5_);
	cppVar_1928 = (0 << 5) | cppVar_1927;
	cppVar_1928 = (cppVar_1928 & cppMask_un_8_);
	cppVar_1929 = IRAM.rd(cppVar_1928);
	cppVar_1930 = ACC & cppVar_1929;
	cppVar_1920 = cppVar_1930;
	} else {
	cppVar_1932 = ROM.rd(PC);
	cppVar_1934 = (cppVar_1932 == 93);
	if (cppVar_1934) {
	cppVar_1936 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1938 = (cppVar_1936 << 3) | 5;
	cppVar_1938 = (cppVar_1938 & cppMask_un_5_);
	cppVar_1939 = (0 << 5) | cppVar_1938;
	cppVar_1939 = (cppVar_1939 & cppMask_un_8_);
	cppVar_1940 = IRAM.rd(cppVar_1939);
	cppVar_1941 = ACC & cppVar_1940;
	cppVar_1931 = cppVar_1941;
	} else {
	cppVar_1943 = ROM.rd(PC);
	cppVar_1945 = (cppVar_1943 == 92);
	if (cppVar_1945) {
	cppVar_1947 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1949 = (cppVar_1947 << 3) | 4;
	cppVar_1949 = (cppVar_1949 & cppMask_un_5_);
	cppVar_1950 = (0 << 5) | cppVar_1949;
	cppVar_1950 = (cppVar_1950 & cppMask_un_8_);
	cppVar_1951 = IRAM.rd(cppVar_1950);
	cppVar_1952 = ACC & cppVar_1951;
	cppVar_1942 = cppVar_1952;
	} else {
	cppVar_1954 = ROM.rd(PC);
	cppVar_1956 = (cppVar_1954 == 91);
	if (cppVar_1956) {
	cppVar_1958 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1960 = (cppVar_1958 << 3) | 3;
	cppVar_1960 = (cppVar_1960 & cppMask_un_5_);
	cppVar_1961 = (0 << 5) | cppVar_1960;
	cppVar_1961 = (cppVar_1961 & cppMask_un_8_);
	cppVar_1962 = IRAM.rd(cppVar_1961);
	cppVar_1963 = ACC & cppVar_1962;
	cppVar_1953 = cppVar_1963;
	} else {
	cppVar_1965 = ROM.rd(PC);
	cppVar_1967 = (cppVar_1965 == 90);
	if (cppVar_1967) {
	cppVar_1969 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1971 = (cppVar_1969 << 3) | 2;
	cppVar_1971 = (cppVar_1971 & cppMask_un_5_);
	cppVar_1972 = (0 << 5) | cppVar_1971;
	cppVar_1972 = (cppVar_1972 & cppMask_un_8_);
	cppVar_1973 = IRAM.rd(cppVar_1972);
	cppVar_1974 = ACC & cppVar_1973;
	cppVar_1964 = cppVar_1974;
	} else {
	cppVar_1976 = ROM.rd(PC);
	cppVar_1978 = (cppVar_1976 == 89);
	if (cppVar_1978) {
	cppVar_1980 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1982 = (cppVar_1980 << 3) | 1;
	cppVar_1982 = (cppVar_1982 & cppMask_un_5_);
	cppVar_1983 = (0 << 5) | cppVar_1982;
	cppVar_1983 = (cppVar_1983 & cppMask_un_8_);
	cppVar_1984 = IRAM.rd(cppVar_1983);
	cppVar_1985 = ACC & cppVar_1984;
	cppVar_1975 = cppVar_1985;
	} else {
	cppVar_1987 = ROM.rd(PC);
	cppVar_1989 = (cppVar_1987 == 88);
	if (cppVar_1989) {
	cppVar_1991 = (PSW >> 3) & cppMask_un_2_;
	cppVar_1993 = (cppVar_1991 << 3) | 0;
	cppVar_1993 = (cppVar_1993 & cppMask_un_5_);
	cppVar_1994 = (0 << 5) | cppVar_1993;
	cppVar_1994 = (cppVar_1994 & cppMask_un_8_);
	cppVar_1995 = IRAM.rd(cppVar_1994);
	cppVar_1996 = ACC & cppVar_1995;
	cppVar_1986 = cppVar_1996;
	} else {
	cppVar_1998 = ROM.rd(PC);
	cppVar_2000 = (cppVar_1998 == 87);
	if (cppVar_2000) {
	cppVar_2002 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2004 = (cppVar_2002 << 3) | 1;
	cppVar_2004 = (cppVar_2004 & cppMask_un_5_);
	cppVar_2005 = (0 << 5) | cppVar_2004;
	cppVar_2005 = (cppVar_2005 & cppMask_un_8_);
	cppVar_2006 = IRAM.rd(cppVar_2005);
	cppVar_2007 = IRAM.rd(cppVar_2006);
	cppVar_2008 = ACC & cppVar_2007;
	cppVar_1997 = cppVar_2008;
	} else {
	cppVar_2010 = ROM.rd(PC);
	cppVar_2012 = (cppVar_2010 == 86);
	if (cppVar_2012) {
	cppVar_2014 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2016 = (cppVar_2014 << 3) | 0;
	cppVar_2016 = (cppVar_2016 & cppMask_un_5_);
	cppVar_2017 = (0 << 5) | cppVar_2016;
	cppVar_2017 = (cppVar_2017 & cppMask_un_8_);
	cppVar_2018 = IRAM.rd(cppVar_2017);
	cppVar_2019 = IRAM.rd(cppVar_2018);
	cppVar_2020 = ACC & cppVar_2019;
	cppVar_2009 = cppVar_2020;
	} else {
	cppVar_2022 = ROM.rd(PC);
	cppVar_2024 = (cppVar_2022 == 85);
	if (cppVar_2024) {
	cppVar_2027 = PC + 1;
	cppVar_2027 = (cppVar_2027 & cppMask_un_16_);
	cppVar_2028 = ROM.rd(cppVar_2027);
	cppVar_2029 = (cppVar_2028 >> 7) & cppMask_un_1_;
	cppVar_2031 = (cppVar_2029 == 0);
	if (cppVar_2031) {
	cppVar_2032 = PC + 1;
	cppVar_2032 = (cppVar_2032 & cppMask_un_16_);
	cppVar_2033 = ROM.rd(cppVar_2032);
	cppVar_2034 = IRAM.rd(cppVar_2033);
	cppVar_2025 = cppVar_2034;
	} else {
	cppVar_2036 = PC + 1;
	cppVar_2036 = (cppVar_2036 & cppMask_un_16_);
	cppVar_2037 = ROM.rd(cppVar_2036);
	cppVar_2039 = (cppVar_2037 == 128);
	if (cppVar_2039) {
	cppVar_2035 = P0;
	} else {
	cppVar_2041 = PC + 1;
	cppVar_2041 = (cppVar_2041 & cppMask_un_16_);
	cppVar_2042 = ROM.rd(cppVar_2041);
	cppVar_2044 = (cppVar_2042 == 129);
	if (cppVar_2044) {
	cppVar_2040 = SP;
	} else {
	cppVar_2046 = PC + 1;
	cppVar_2046 = (cppVar_2046 & cppMask_un_16_);
	cppVar_2047 = ROM.rd(cppVar_2046);
	cppVar_2049 = (cppVar_2047 == 130);
	if (cppVar_2049) {
	cppVar_2045 = DPL;
	} else {
	cppVar_2051 = PC + 1;
	cppVar_2051 = (cppVar_2051 & cppMask_un_16_);
	cppVar_2052 = ROM.rd(cppVar_2051);
	cppVar_2054 = (cppVar_2052 == 131);
	if (cppVar_2054) {
	cppVar_2050 = DPH;
	} else {
	cppVar_2056 = PC + 1;
	cppVar_2056 = (cppVar_2056 & cppMask_un_16_);
	cppVar_2057 = ROM.rd(cppVar_2056);
	cppVar_2059 = (cppVar_2057 == 135);
	if (cppVar_2059) {
	cppVar_2055 = PCON;
	} else {
	cppVar_2061 = PC + 1;
	cppVar_2061 = (cppVar_2061 & cppMask_un_16_);
	cppVar_2062 = ROM.rd(cppVar_2061);
	cppVar_2064 = (cppVar_2062 == 136);
	if (cppVar_2064) {
	cppVar_2060 = TCON;
	} else {
	cppVar_2066 = PC + 1;
	cppVar_2066 = (cppVar_2066 & cppMask_un_16_);
	cppVar_2067 = ROM.rd(cppVar_2066);
	cppVar_2069 = (cppVar_2067 == 137);
	if (cppVar_2069) {
	cppVar_2065 = TMOD;
	} else {
	cppVar_2071 = PC + 1;
	cppVar_2071 = (cppVar_2071 & cppMask_un_16_);
	cppVar_2072 = ROM.rd(cppVar_2071);
	cppVar_2074 = (cppVar_2072 == 138);
	if (cppVar_2074) {
	cppVar_2070 = TL0;
	} else {
	cppVar_2076 = PC + 1;
	cppVar_2076 = (cppVar_2076 & cppMask_un_16_);
	cppVar_2077 = ROM.rd(cppVar_2076);
	cppVar_2079 = (cppVar_2077 == 140);
	if (cppVar_2079) {
	cppVar_2075 = TH0;
	} else {
	cppVar_2081 = PC + 1;
	cppVar_2081 = (cppVar_2081 & cppMask_un_16_);
	cppVar_2082 = ROM.rd(cppVar_2081);
	cppVar_2084 = (cppVar_2082 == 139);
	if (cppVar_2084) {
	cppVar_2080 = TL1;
	} else {
	cppVar_2086 = PC + 1;
	cppVar_2086 = (cppVar_2086 & cppMask_un_16_);
	cppVar_2087 = ROM.rd(cppVar_2086);
	cppVar_2089 = (cppVar_2087 == 141);
	if (cppVar_2089) {
	cppVar_2085 = TH1;
	} else {
	cppVar_2091 = PC + 1;
	cppVar_2091 = (cppVar_2091 & cppMask_un_16_);
	cppVar_2092 = ROM.rd(cppVar_2091);
	cppVar_2094 = (cppVar_2092 == 144);
	if (cppVar_2094) {
	cppVar_2090 = P1;
	} else {
	cppVar_2096 = PC + 1;
	cppVar_2096 = (cppVar_2096 & cppMask_un_16_);
	cppVar_2097 = ROM.rd(cppVar_2096);
	cppVar_2099 = (cppVar_2097 == 152);
	if (cppVar_2099) {
	cppVar_2095 = SCON;
	} else {
	cppVar_2101 = PC + 1;
	cppVar_2101 = (cppVar_2101 & cppMask_un_16_);
	cppVar_2102 = ROM.rd(cppVar_2101);
	cppVar_2104 = (cppVar_2102 == 153);
	if (cppVar_2104) {
	cppVar_2100 = SBUF;
	} else {
	cppVar_2106 = PC + 1;
	cppVar_2106 = (cppVar_2106 & cppMask_un_16_);
	cppVar_2107 = ROM.rd(cppVar_2106);
	cppVar_2109 = (cppVar_2107 == 160);
	if (cppVar_2109) {
	cppVar_2105 = P2;
	} else {
	cppVar_2111 = PC + 1;
	cppVar_2111 = (cppVar_2111 & cppMask_un_16_);
	cppVar_2112 = ROM.rd(cppVar_2111);
	cppVar_2114 = (cppVar_2112 == 168);
	if (cppVar_2114) {
	cppVar_2110 = IE;
	} else {
	cppVar_2116 = PC + 1;
	cppVar_2116 = (cppVar_2116 & cppMask_un_16_);
	cppVar_2117 = ROM.rd(cppVar_2116);
	cppVar_2119 = (cppVar_2117 == 176);
	if (cppVar_2119) {
	cppVar_2115 = P3;
	} else {
	cppVar_2121 = PC + 1;
	cppVar_2121 = (cppVar_2121 & cppMask_un_16_);
	cppVar_2122 = ROM.rd(cppVar_2121);
	cppVar_2124 = (cppVar_2122 == 184);
	if (cppVar_2124) {
	cppVar_2120 = IP;
	} else {
	cppVar_2126 = PC + 1;
	cppVar_2126 = (cppVar_2126 & cppMask_un_16_);
	cppVar_2127 = ROM.rd(cppVar_2126);
	cppVar_2129 = (cppVar_2127 == 208);
	if (cppVar_2129) {
	cppVar_2125 = PSW;
	} else {
	cppVar_2131 = PC + 1;
	cppVar_2131 = (cppVar_2131 & cppMask_un_16_);
	cppVar_2132 = ROM.rd(cppVar_2131);
	cppVar_2134 = (cppVar_2132 == 224);
	if (cppVar_2134) {
	cppVar_2130 = ACC;
	} else {
	cppVar_2136 = PC + 1;
	cppVar_2136 = (cppVar_2136 & cppMask_un_16_);
	cppVar_2137 = ROM.rd(cppVar_2136);
	cppVar_2139 = (cppVar_2137 == 240);
	if (cppVar_2139) {
	cppVar_2135 = B;
	} else {
	cppVar_2135 = 0;
	}
	cppVar_2130 = cppVar_2135;
	}
	cppVar_2125 = cppVar_2130;
	}
	cppVar_2120 = cppVar_2125;
	}
	cppVar_2115 = cppVar_2120;
	}
	cppVar_2110 = cppVar_2115;
	}
	cppVar_2105 = cppVar_2110;
	}
	cppVar_2100 = cppVar_2105;
	}
	cppVar_2095 = cppVar_2100;
	}
	cppVar_2090 = cppVar_2095;
	}
	cppVar_2085 = cppVar_2090;
	}
	cppVar_2080 = cppVar_2085;
	}
	cppVar_2075 = cppVar_2080;
	}
	cppVar_2070 = cppVar_2075;
	}
	cppVar_2065 = cppVar_2070;
	}
	cppVar_2060 = cppVar_2065;
	}
	cppVar_2055 = cppVar_2060;
	}
	cppVar_2050 = cppVar_2055;
	}
	cppVar_2045 = cppVar_2050;
	}
	cppVar_2040 = cppVar_2045;
	}
	cppVar_2035 = cppVar_2040;
	}
	cppVar_2025 = cppVar_2035;
	}
	cppVar_2141 = ACC & cppVar_2025;
	cppVar_2021 = cppVar_2141;
	} else {
	cppVar_2143 = ROM.rd(PC);
	cppVar_2145 = (cppVar_2143 == 84);
	if (cppVar_2145) {
	cppVar_2147 = PC + 1;
	cppVar_2147 = (cppVar_2147 & cppMask_un_16_);
	cppVar_2148 = ROM.rd(cppVar_2147);
	cppVar_2149 = ACC & cppVar_2148;
	cppVar_2142 = cppVar_2149;
	} else {
	cppVar_2151 = ROM.rd(PC);
	cppVar_2153 = (cppVar_2151 == 79);
	if (cppVar_2153) {
	cppVar_2155 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2157 = (cppVar_2155 << 3) | 7;
	cppVar_2157 = (cppVar_2157 & cppMask_un_5_);
	cppVar_2158 = (0 << 5) | cppVar_2157;
	cppVar_2158 = (cppVar_2158 & cppMask_un_8_);
	cppVar_2159 = IRAM.rd(cppVar_2158);
	cppVar_2160 = ACC | cppVar_2159;
	cppVar_2150 = cppVar_2160;
	} else {
	cppVar_2162 = ROM.rd(PC);
	cppVar_2164 = (cppVar_2162 == 78);
	if (cppVar_2164) {
	cppVar_2166 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2168 = (cppVar_2166 << 3) | 6;
	cppVar_2168 = (cppVar_2168 & cppMask_un_5_);
	cppVar_2169 = (0 << 5) | cppVar_2168;
	cppVar_2169 = (cppVar_2169 & cppMask_un_8_);
	cppVar_2170 = IRAM.rd(cppVar_2169);
	cppVar_2171 = ACC | cppVar_2170;
	cppVar_2161 = cppVar_2171;
	} else {
	cppVar_2173 = ROM.rd(PC);
	cppVar_2175 = (cppVar_2173 == 77);
	if (cppVar_2175) {
	cppVar_2177 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2179 = (cppVar_2177 << 3) | 5;
	cppVar_2179 = (cppVar_2179 & cppMask_un_5_);
	cppVar_2180 = (0 << 5) | cppVar_2179;
	cppVar_2180 = (cppVar_2180 & cppMask_un_8_);
	cppVar_2181 = IRAM.rd(cppVar_2180);
	cppVar_2182 = ACC | cppVar_2181;
	cppVar_2172 = cppVar_2182;
	} else {
	cppVar_2184 = ROM.rd(PC);
	cppVar_2186 = (cppVar_2184 == 76);
	if (cppVar_2186) {
	cppVar_2188 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2190 = (cppVar_2188 << 3) | 4;
	cppVar_2190 = (cppVar_2190 & cppMask_un_5_);
	cppVar_2191 = (0 << 5) | cppVar_2190;
	cppVar_2191 = (cppVar_2191 & cppMask_un_8_);
	cppVar_2192 = IRAM.rd(cppVar_2191);
	cppVar_2193 = ACC | cppVar_2192;
	cppVar_2183 = cppVar_2193;
	} else {
	cppVar_2195 = ROM.rd(PC);
	cppVar_2197 = (cppVar_2195 == 75);
	if (cppVar_2197) {
	cppVar_2199 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2201 = (cppVar_2199 << 3) | 3;
	cppVar_2201 = (cppVar_2201 & cppMask_un_5_);
	cppVar_2202 = (0 << 5) | cppVar_2201;
	cppVar_2202 = (cppVar_2202 & cppMask_un_8_);
	cppVar_2203 = IRAM.rd(cppVar_2202);
	cppVar_2204 = ACC | cppVar_2203;
	cppVar_2194 = cppVar_2204;
	} else {
	cppVar_2206 = ROM.rd(PC);
	cppVar_2208 = (cppVar_2206 == 74);
	if (cppVar_2208) {
	cppVar_2210 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2212 = (cppVar_2210 << 3) | 2;
	cppVar_2212 = (cppVar_2212 & cppMask_un_5_);
	cppVar_2213 = (0 << 5) | cppVar_2212;
	cppVar_2213 = (cppVar_2213 & cppMask_un_8_);
	cppVar_2214 = IRAM.rd(cppVar_2213);
	cppVar_2215 = ACC | cppVar_2214;
	cppVar_2205 = cppVar_2215;
	} else {
	cppVar_2217 = ROM.rd(PC);
	cppVar_2219 = (cppVar_2217 == 73);
	if (cppVar_2219) {
	cppVar_2221 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2223 = (cppVar_2221 << 3) | 1;
	cppVar_2223 = (cppVar_2223 & cppMask_un_5_);
	cppVar_2224 = (0 << 5) | cppVar_2223;
	cppVar_2224 = (cppVar_2224 & cppMask_un_8_);
	cppVar_2225 = IRAM.rd(cppVar_2224);
	cppVar_2226 = ACC | cppVar_2225;
	cppVar_2216 = cppVar_2226;
	} else {
	cppVar_2228 = ROM.rd(PC);
	cppVar_2230 = (cppVar_2228 == 72);
	if (cppVar_2230) {
	cppVar_2232 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2234 = (cppVar_2232 << 3) | 0;
	cppVar_2234 = (cppVar_2234 & cppMask_un_5_);
	cppVar_2235 = (0 << 5) | cppVar_2234;
	cppVar_2235 = (cppVar_2235 & cppMask_un_8_);
	cppVar_2236 = IRAM.rd(cppVar_2235);
	cppVar_2237 = ACC | cppVar_2236;
	cppVar_2227 = cppVar_2237;
	} else {
	cppVar_2239 = ROM.rd(PC);
	cppVar_2241 = (cppVar_2239 == 71);
	if (cppVar_2241) {
	cppVar_2243 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2245 = (cppVar_2243 << 3) | 1;
	cppVar_2245 = (cppVar_2245 & cppMask_un_5_);
	cppVar_2246 = (0 << 5) | cppVar_2245;
	cppVar_2246 = (cppVar_2246 & cppMask_un_8_);
	cppVar_2247 = IRAM.rd(cppVar_2246);
	cppVar_2248 = IRAM.rd(cppVar_2247);
	cppVar_2249 = ACC | cppVar_2248;
	cppVar_2238 = cppVar_2249;
	} else {
	cppVar_2251 = ROM.rd(PC);
	cppVar_2253 = (cppVar_2251 == 70);
	if (cppVar_2253) {
	cppVar_2255 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2257 = (cppVar_2255 << 3) | 0;
	cppVar_2257 = (cppVar_2257 & cppMask_un_5_);
	cppVar_2258 = (0 << 5) | cppVar_2257;
	cppVar_2258 = (cppVar_2258 & cppMask_un_8_);
	cppVar_2259 = IRAM.rd(cppVar_2258);
	cppVar_2260 = IRAM.rd(cppVar_2259);
	cppVar_2261 = ACC | cppVar_2260;
	cppVar_2250 = cppVar_2261;
	} else {
	cppVar_2263 = ROM.rd(PC);
	cppVar_2265 = (cppVar_2263 == 69);
	if (cppVar_2265) {
	cppVar_2268 = PC + 1;
	cppVar_2268 = (cppVar_2268 & cppMask_un_16_);
	cppVar_2269 = ROM.rd(cppVar_2268);
	cppVar_2270 = (cppVar_2269 >> 7) & cppMask_un_1_;
	cppVar_2272 = (cppVar_2270 == 0);
	if (cppVar_2272) {
	cppVar_2273 = PC + 1;
	cppVar_2273 = (cppVar_2273 & cppMask_un_16_);
	cppVar_2274 = ROM.rd(cppVar_2273);
	cppVar_2275 = IRAM.rd(cppVar_2274);
	cppVar_2266 = cppVar_2275;
	} else {
	cppVar_2277 = PC + 1;
	cppVar_2277 = (cppVar_2277 & cppMask_un_16_);
	cppVar_2278 = ROM.rd(cppVar_2277);
	cppVar_2280 = (cppVar_2278 == 128);
	if (cppVar_2280) {
	cppVar_2276 = P0;
	} else {
	cppVar_2282 = PC + 1;
	cppVar_2282 = (cppVar_2282 & cppMask_un_16_);
	cppVar_2283 = ROM.rd(cppVar_2282);
	cppVar_2285 = (cppVar_2283 == 129);
	if (cppVar_2285) {
	cppVar_2281 = SP;
	} else {
	cppVar_2287 = PC + 1;
	cppVar_2287 = (cppVar_2287 & cppMask_un_16_);
	cppVar_2288 = ROM.rd(cppVar_2287);
	cppVar_2290 = (cppVar_2288 == 130);
	if (cppVar_2290) {
	cppVar_2286 = DPL;
	} else {
	cppVar_2292 = PC + 1;
	cppVar_2292 = (cppVar_2292 & cppMask_un_16_);
	cppVar_2293 = ROM.rd(cppVar_2292);
	cppVar_2295 = (cppVar_2293 == 131);
	if (cppVar_2295) {
	cppVar_2291 = DPH;
	} else {
	cppVar_2297 = PC + 1;
	cppVar_2297 = (cppVar_2297 & cppMask_un_16_);
	cppVar_2298 = ROM.rd(cppVar_2297);
	cppVar_2300 = (cppVar_2298 == 135);
	if (cppVar_2300) {
	cppVar_2296 = PCON;
	} else {
	cppVar_2302 = PC + 1;
	cppVar_2302 = (cppVar_2302 & cppMask_un_16_);
	cppVar_2303 = ROM.rd(cppVar_2302);
	cppVar_2305 = (cppVar_2303 == 136);
	if (cppVar_2305) {
	cppVar_2301 = TCON;
	} else {
	cppVar_2307 = PC + 1;
	cppVar_2307 = (cppVar_2307 & cppMask_un_16_);
	cppVar_2308 = ROM.rd(cppVar_2307);
	cppVar_2310 = (cppVar_2308 == 137);
	if (cppVar_2310) {
	cppVar_2306 = TMOD;
	} else {
	cppVar_2312 = PC + 1;
	cppVar_2312 = (cppVar_2312 & cppMask_un_16_);
	cppVar_2313 = ROM.rd(cppVar_2312);
	cppVar_2315 = (cppVar_2313 == 138);
	if (cppVar_2315) {
	cppVar_2311 = TL0;
	} else {
	cppVar_2317 = PC + 1;
	cppVar_2317 = (cppVar_2317 & cppMask_un_16_);
	cppVar_2318 = ROM.rd(cppVar_2317);
	cppVar_2320 = (cppVar_2318 == 140);
	if (cppVar_2320) {
	cppVar_2316 = TH0;
	} else {
	cppVar_2322 = PC + 1;
	cppVar_2322 = (cppVar_2322 & cppMask_un_16_);
	cppVar_2323 = ROM.rd(cppVar_2322);
	cppVar_2325 = (cppVar_2323 == 139);
	if (cppVar_2325) {
	cppVar_2321 = TL1;
	} else {
	cppVar_2327 = PC + 1;
	cppVar_2327 = (cppVar_2327 & cppMask_un_16_);
	cppVar_2328 = ROM.rd(cppVar_2327);
	cppVar_2330 = (cppVar_2328 == 141);
	if (cppVar_2330) {
	cppVar_2326 = TH1;
	} else {
	cppVar_2332 = PC + 1;
	cppVar_2332 = (cppVar_2332 & cppMask_un_16_);
	cppVar_2333 = ROM.rd(cppVar_2332);
	cppVar_2335 = (cppVar_2333 == 144);
	if (cppVar_2335) {
	cppVar_2331 = P1;
	} else {
	cppVar_2337 = PC + 1;
	cppVar_2337 = (cppVar_2337 & cppMask_un_16_);
	cppVar_2338 = ROM.rd(cppVar_2337);
	cppVar_2340 = (cppVar_2338 == 152);
	if (cppVar_2340) {
	cppVar_2336 = SCON;
	} else {
	cppVar_2342 = PC + 1;
	cppVar_2342 = (cppVar_2342 & cppMask_un_16_);
	cppVar_2343 = ROM.rd(cppVar_2342);
	cppVar_2345 = (cppVar_2343 == 153);
	if (cppVar_2345) {
	cppVar_2341 = SBUF;
	} else {
	cppVar_2347 = PC + 1;
	cppVar_2347 = (cppVar_2347 & cppMask_un_16_);
	cppVar_2348 = ROM.rd(cppVar_2347);
	cppVar_2350 = (cppVar_2348 == 160);
	if (cppVar_2350) {
	cppVar_2346 = P2;
	} else {
	cppVar_2352 = PC + 1;
	cppVar_2352 = (cppVar_2352 & cppMask_un_16_);
	cppVar_2353 = ROM.rd(cppVar_2352);
	cppVar_2355 = (cppVar_2353 == 168);
	if (cppVar_2355) {
	cppVar_2351 = IE;
	} else {
	cppVar_2357 = PC + 1;
	cppVar_2357 = (cppVar_2357 & cppMask_un_16_);
	cppVar_2358 = ROM.rd(cppVar_2357);
	cppVar_2360 = (cppVar_2358 == 176);
	if (cppVar_2360) {
	cppVar_2356 = P3;
	} else {
	cppVar_2362 = PC + 1;
	cppVar_2362 = (cppVar_2362 & cppMask_un_16_);
	cppVar_2363 = ROM.rd(cppVar_2362);
	cppVar_2365 = (cppVar_2363 == 184);
	if (cppVar_2365) {
	cppVar_2361 = IP;
	} else {
	cppVar_2367 = PC + 1;
	cppVar_2367 = (cppVar_2367 & cppMask_un_16_);
	cppVar_2368 = ROM.rd(cppVar_2367);
	cppVar_2370 = (cppVar_2368 == 208);
	if (cppVar_2370) {
	cppVar_2366 = PSW;
	} else {
	cppVar_2372 = PC + 1;
	cppVar_2372 = (cppVar_2372 & cppMask_un_16_);
	cppVar_2373 = ROM.rd(cppVar_2372);
	cppVar_2375 = (cppVar_2373 == 224);
	if (cppVar_2375) {
	cppVar_2371 = ACC;
	} else {
	cppVar_2377 = PC + 1;
	cppVar_2377 = (cppVar_2377 & cppMask_un_16_);
	cppVar_2378 = ROM.rd(cppVar_2377);
	cppVar_2380 = (cppVar_2378 == 240);
	if (cppVar_2380) {
	cppVar_2376 = B;
	} else {
	cppVar_2376 = 0;
	}
	cppVar_2371 = cppVar_2376;
	}
	cppVar_2366 = cppVar_2371;
	}
	cppVar_2361 = cppVar_2366;
	}
	cppVar_2356 = cppVar_2361;
	}
	cppVar_2351 = cppVar_2356;
	}
	cppVar_2346 = cppVar_2351;
	}
	cppVar_2341 = cppVar_2346;
	}
	cppVar_2336 = cppVar_2341;
	}
	cppVar_2331 = cppVar_2336;
	}
	cppVar_2326 = cppVar_2331;
	}
	cppVar_2321 = cppVar_2326;
	}
	cppVar_2316 = cppVar_2321;
	}
	cppVar_2311 = cppVar_2316;
	}
	cppVar_2306 = cppVar_2311;
	}
	cppVar_2301 = cppVar_2306;
	}
	cppVar_2296 = cppVar_2301;
	}
	cppVar_2291 = cppVar_2296;
	}
	cppVar_2286 = cppVar_2291;
	}
	cppVar_2281 = cppVar_2286;
	}
	cppVar_2276 = cppVar_2281;
	}
	cppVar_2266 = cppVar_2276;
	}
	cppVar_2382 = ACC | cppVar_2266;
	cppVar_2262 = cppVar_2382;
	} else {
	cppVar_2384 = ROM.rd(PC);
	cppVar_2386 = (cppVar_2384 == 68);
	if (cppVar_2386) {
	cppVar_2388 = PC + 1;
	cppVar_2388 = (cppVar_2388 & cppMask_un_16_);
	cppVar_2389 = ROM.rd(cppVar_2388);
	cppVar_2390 = ACC | cppVar_2389;
	cppVar_2383 = cppVar_2390;
	} else {
	cppVar_2392 = ROM.rd(PC);
	cppVar_2394 = (cppVar_2392 == 63);
	if (cppVar_2394) {
	cppVar_2396 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2398 = (cppVar_2396 << 3) | 7;
	cppVar_2398 = (cppVar_2398 & cppMask_un_5_);
	cppVar_2399 = (0 << 5) | cppVar_2398;
	cppVar_2399 = (cppVar_2399 & cppMask_un_8_);
	cppVar_2400 = IRAM.rd(cppVar_2399);
	cppVar_2401 = ACC + cppVar_2400;
	cppVar_2401 = (cppVar_2401 & cppMask_un_8_);
	cppVar_2402 = (PSW >> 7) & cppMask_un_1_;
	cppVar_2403 = (cppVar_2402 & cppMask_un_1_);
	cppVar_2404 = cppVar_2401 + cppVar_2403;
	cppVar_2404 = (cppVar_2404 & cppMask_un_8_);
	cppVar_2391 = cppVar_2404;
	} else {
	cppVar_2406 = ROM.rd(PC);
	cppVar_2408 = (cppVar_2406 == 62);
	if (cppVar_2408) {
	cppVar_2410 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2412 = (cppVar_2410 << 3) | 6;
	cppVar_2412 = (cppVar_2412 & cppMask_un_5_);
	cppVar_2413 = (0 << 5) | cppVar_2412;
	cppVar_2413 = (cppVar_2413 & cppMask_un_8_);
	cppVar_2414 = IRAM.rd(cppVar_2413);
	cppVar_2415 = ACC + cppVar_2414;
	cppVar_2415 = (cppVar_2415 & cppMask_un_8_);
	cppVar_2416 = (PSW >> 7) & cppMask_un_1_;
	cppVar_2417 = (cppVar_2416 & cppMask_un_1_);
	cppVar_2418 = cppVar_2415 + cppVar_2417;
	cppVar_2418 = (cppVar_2418 & cppMask_un_8_);
	cppVar_2405 = cppVar_2418;
	} else {
	cppVar_2420 = ROM.rd(PC);
	cppVar_2422 = (cppVar_2420 == 61);
	if (cppVar_2422) {
	cppVar_2424 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2426 = (cppVar_2424 << 3) | 5;
	cppVar_2426 = (cppVar_2426 & cppMask_un_5_);
	cppVar_2427 = (0 << 5) | cppVar_2426;
	cppVar_2427 = (cppVar_2427 & cppMask_un_8_);
	cppVar_2428 = IRAM.rd(cppVar_2427);
	cppVar_2429 = ACC + cppVar_2428;
	cppVar_2429 = (cppVar_2429 & cppMask_un_8_);
	cppVar_2430 = (PSW >> 7) & cppMask_un_1_;
	cppVar_2431 = (cppVar_2430 & cppMask_un_1_);
	cppVar_2432 = cppVar_2429 + cppVar_2431;
	cppVar_2432 = (cppVar_2432 & cppMask_un_8_);
	cppVar_2419 = cppVar_2432;
	} else {
	cppVar_2434 = ROM.rd(PC);
	cppVar_2436 = (cppVar_2434 == 60);
	if (cppVar_2436) {
	cppVar_2438 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2440 = (cppVar_2438 << 3) | 4;
	cppVar_2440 = (cppVar_2440 & cppMask_un_5_);
	cppVar_2441 = (0 << 5) | cppVar_2440;
	cppVar_2441 = (cppVar_2441 & cppMask_un_8_);
	cppVar_2442 = IRAM.rd(cppVar_2441);
	cppVar_2443 = ACC + cppVar_2442;
	cppVar_2443 = (cppVar_2443 & cppMask_un_8_);
	cppVar_2444 = (PSW >> 7) & cppMask_un_1_;
	cppVar_2445 = (cppVar_2444 & cppMask_un_1_);
	cppVar_2446 = cppVar_2443 + cppVar_2445;
	cppVar_2446 = (cppVar_2446 & cppMask_un_8_);
	cppVar_2433 = cppVar_2446;
	} else {
	cppVar_2448 = ROM.rd(PC);
	cppVar_2450 = (cppVar_2448 == 59);
	if (cppVar_2450) {
	cppVar_2452 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2454 = (cppVar_2452 << 3) | 3;
	cppVar_2454 = (cppVar_2454 & cppMask_un_5_);
	cppVar_2455 = (0 << 5) | cppVar_2454;
	cppVar_2455 = (cppVar_2455 & cppMask_un_8_);
	cppVar_2456 = IRAM.rd(cppVar_2455);
	cppVar_2457 = ACC + cppVar_2456;
	cppVar_2457 = (cppVar_2457 & cppMask_un_8_);
	cppVar_2458 = (PSW >> 7) & cppMask_un_1_;
	cppVar_2459 = (cppVar_2458 & cppMask_un_1_);
	cppVar_2460 = cppVar_2457 + cppVar_2459;
	cppVar_2460 = (cppVar_2460 & cppMask_un_8_);
	cppVar_2447 = cppVar_2460;
	} else {
	cppVar_2462 = ROM.rd(PC);
	cppVar_2464 = (cppVar_2462 == 58);
	if (cppVar_2464) {
	cppVar_2466 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2468 = (cppVar_2466 << 3) | 2;
	cppVar_2468 = (cppVar_2468 & cppMask_un_5_);
	cppVar_2469 = (0 << 5) | cppVar_2468;
	cppVar_2469 = (cppVar_2469 & cppMask_un_8_);
	cppVar_2470 = IRAM.rd(cppVar_2469);
	cppVar_2471 = ACC + cppVar_2470;
	cppVar_2471 = (cppVar_2471 & cppMask_un_8_);
	cppVar_2472 = (PSW >> 7) & cppMask_un_1_;
	cppVar_2473 = (cppVar_2472 & cppMask_un_1_);
	cppVar_2474 = cppVar_2471 + cppVar_2473;
	cppVar_2474 = (cppVar_2474 & cppMask_un_8_);
	cppVar_2461 = cppVar_2474;
	} else {
	cppVar_2476 = ROM.rd(PC);
	cppVar_2478 = (cppVar_2476 == 57);
	if (cppVar_2478) {
	cppVar_2480 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2482 = (cppVar_2480 << 3) | 1;
	cppVar_2482 = (cppVar_2482 & cppMask_un_5_);
	cppVar_2483 = (0 << 5) | cppVar_2482;
	cppVar_2483 = (cppVar_2483 & cppMask_un_8_);
	cppVar_2484 = IRAM.rd(cppVar_2483);
	cppVar_2485 = ACC + cppVar_2484;
	cppVar_2485 = (cppVar_2485 & cppMask_un_8_);
	cppVar_2486 = (PSW >> 7) & cppMask_un_1_;
	cppVar_2487 = (cppVar_2486 & cppMask_un_1_);
	cppVar_2488 = cppVar_2485 + cppVar_2487;
	cppVar_2488 = (cppVar_2488 & cppMask_un_8_);
	cppVar_2475 = cppVar_2488;
	} else {
	cppVar_2490 = ROM.rd(PC);
	cppVar_2492 = (cppVar_2490 == 56);
	if (cppVar_2492) {
	cppVar_2494 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2496 = (cppVar_2494 << 3) | 0;
	cppVar_2496 = (cppVar_2496 & cppMask_un_5_);
	cppVar_2497 = (0 << 5) | cppVar_2496;
	cppVar_2497 = (cppVar_2497 & cppMask_un_8_);
	cppVar_2498 = IRAM.rd(cppVar_2497);
	cppVar_2499 = ACC + cppVar_2498;
	cppVar_2499 = (cppVar_2499 & cppMask_un_8_);
	cppVar_2500 = (PSW >> 7) & cppMask_un_1_;
	cppVar_2501 = (cppVar_2500 & cppMask_un_1_);
	cppVar_2502 = cppVar_2499 + cppVar_2501;
	cppVar_2502 = (cppVar_2502 & cppMask_un_8_);
	cppVar_2489 = cppVar_2502;
	} else {
	cppVar_2504 = ROM.rd(PC);
	cppVar_2506 = (cppVar_2504 == 55);
	if (cppVar_2506) {
	cppVar_2508 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2510 = (cppVar_2508 << 3) | 1;
	cppVar_2510 = (cppVar_2510 & cppMask_un_5_);
	cppVar_2511 = (0 << 5) | cppVar_2510;
	cppVar_2511 = (cppVar_2511 & cppMask_un_8_);
	cppVar_2512 = IRAM.rd(cppVar_2511);
	cppVar_2513 = IRAM.rd(cppVar_2512);
	cppVar_2514 = ACC + cppVar_2513;
	cppVar_2514 = (cppVar_2514 & cppMask_un_8_);
	cppVar_2515 = (PSW >> 7) & cppMask_un_1_;
	cppVar_2516 = (cppVar_2515 & cppMask_un_1_);
	cppVar_2517 = cppVar_2514 + cppVar_2516;
	cppVar_2517 = (cppVar_2517 & cppMask_un_8_);
	cppVar_2503 = cppVar_2517;
	} else {
	cppVar_2519 = ROM.rd(PC);
	cppVar_2521 = (cppVar_2519 == 54);
	if (cppVar_2521) {
	cppVar_2523 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2525 = (cppVar_2523 << 3) | 0;
	cppVar_2525 = (cppVar_2525 & cppMask_un_5_);
	cppVar_2526 = (0 << 5) | cppVar_2525;
	cppVar_2526 = (cppVar_2526 & cppMask_un_8_);
	cppVar_2527 = IRAM.rd(cppVar_2526);
	cppVar_2528 = IRAM.rd(cppVar_2527);
	cppVar_2529 = ACC + cppVar_2528;
	cppVar_2529 = (cppVar_2529 & cppMask_un_8_);
	cppVar_2530 = (PSW >> 7) & cppMask_un_1_;
	cppVar_2531 = (cppVar_2530 & cppMask_un_1_);
	cppVar_2532 = cppVar_2529 + cppVar_2531;
	cppVar_2532 = (cppVar_2532 & cppMask_un_8_);
	cppVar_2518 = cppVar_2532;
	} else {
	cppVar_2534 = ROM.rd(PC);
	cppVar_2536 = (cppVar_2534 == 53);
	if (cppVar_2536) {
	cppVar_2539 = PC + 1;
	cppVar_2539 = (cppVar_2539 & cppMask_un_16_);
	cppVar_2540 = ROM.rd(cppVar_2539);
	cppVar_2541 = (cppVar_2540 >> 7) & cppMask_un_1_;
	cppVar_2543 = (cppVar_2541 == 0);
	if (cppVar_2543) {
	cppVar_2544 = PC + 1;
	cppVar_2544 = (cppVar_2544 & cppMask_un_16_);
	cppVar_2545 = ROM.rd(cppVar_2544);
	cppVar_2546 = IRAM.rd(cppVar_2545);
	cppVar_2537 = cppVar_2546;
	} else {
	cppVar_2548 = PC + 1;
	cppVar_2548 = (cppVar_2548 & cppMask_un_16_);
	cppVar_2549 = ROM.rd(cppVar_2548);
	cppVar_2551 = (cppVar_2549 == 128);
	if (cppVar_2551) {
	cppVar_2547 = P0;
	} else {
	cppVar_2553 = PC + 1;
	cppVar_2553 = (cppVar_2553 & cppMask_un_16_);
	cppVar_2554 = ROM.rd(cppVar_2553);
	cppVar_2556 = (cppVar_2554 == 129);
	if (cppVar_2556) {
	cppVar_2552 = SP;
	} else {
	cppVar_2558 = PC + 1;
	cppVar_2558 = (cppVar_2558 & cppMask_un_16_);
	cppVar_2559 = ROM.rd(cppVar_2558);
	cppVar_2561 = (cppVar_2559 == 130);
	if (cppVar_2561) {
	cppVar_2557 = DPL;
	} else {
	cppVar_2563 = PC + 1;
	cppVar_2563 = (cppVar_2563 & cppMask_un_16_);
	cppVar_2564 = ROM.rd(cppVar_2563);
	cppVar_2566 = (cppVar_2564 == 131);
	if (cppVar_2566) {
	cppVar_2562 = DPH;
	} else {
	cppVar_2568 = PC + 1;
	cppVar_2568 = (cppVar_2568 & cppMask_un_16_);
	cppVar_2569 = ROM.rd(cppVar_2568);
	cppVar_2571 = (cppVar_2569 == 135);
	if (cppVar_2571) {
	cppVar_2567 = PCON;
	} else {
	cppVar_2573 = PC + 1;
	cppVar_2573 = (cppVar_2573 & cppMask_un_16_);
	cppVar_2574 = ROM.rd(cppVar_2573);
	cppVar_2576 = (cppVar_2574 == 136);
	if (cppVar_2576) {
	cppVar_2572 = TCON;
	} else {
	cppVar_2578 = PC + 1;
	cppVar_2578 = (cppVar_2578 & cppMask_un_16_);
	cppVar_2579 = ROM.rd(cppVar_2578);
	cppVar_2581 = (cppVar_2579 == 137);
	if (cppVar_2581) {
	cppVar_2577 = TMOD;
	} else {
	cppVar_2583 = PC + 1;
	cppVar_2583 = (cppVar_2583 & cppMask_un_16_);
	cppVar_2584 = ROM.rd(cppVar_2583);
	cppVar_2586 = (cppVar_2584 == 138);
	if (cppVar_2586) {
	cppVar_2582 = TL0;
	} else {
	cppVar_2588 = PC + 1;
	cppVar_2588 = (cppVar_2588 & cppMask_un_16_);
	cppVar_2589 = ROM.rd(cppVar_2588);
	cppVar_2591 = (cppVar_2589 == 140);
	if (cppVar_2591) {
	cppVar_2587 = TH0;
	} else {
	cppVar_2593 = PC + 1;
	cppVar_2593 = (cppVar_2593 & cppMask_un_16_);
	cppVar_2594 = ROM.rd(cppVar_2593);
	cppVar_2596 = (cppVar_2594 == 139);
	if (cppVar_2596) {
	cppVar_2592 = TL1;
	} else {
	cppVar_2598 = PC + 1;
	cppVar_2598 = (cppVar_2598 & cppMask_un_16_);
	cppVar_2599 = ROM.rd(cppVar_2598);
	cppVar_2601 = (cppVar_2599 == 141);
	if (cppVar_2601) {
	cppVar_2597 = TH1;
	} else {
	cppVar_2603 = PC + 1;
	cppVar_2603 = (cppVar_2603 & cppMask_un_16_);
	cppVar_2604 = ROM.rd(cppVar_2603);
	cppVar_2606 = (cppVar_2604 == 144);
	if (cppVar_2606) {
	cppVar_2602 = P1;
	} else {
	cppVar_2608 = PC + 1;
	cppVar_2608 = (cppVar_2608 & cppMask_un_16_);
	cppVar_2609 = ROM.rd(cppVar_2608);
	cppVar_2611 = (cppVar_2609 == 152);
	if (cppVar_2611) {
	cppVar_2607 = SCON;
	} else {
	cppVar_2613 = PC + 1;
	cppVar_2613 = (cppVar_2613 & cppMask_un_16_);
	cppVar_2614 = ROM.rd(cppVar_2613);
	cppVar_2616 = (cppVar_2614 == 153);
	if (cppVar_2616) {
	cppVar_2612 = SBUF;
	} else {
	cppVar_2618 = PC + 1;
	cppVar_2618 = (cppVar_2618 & cppMask_un_16_);
	cppVar_2619 = ROM.rd(cppVar_2618);
	cppVar_2621 = (cppVar_2619 == 160);
	if (cppVar_2621) {
	cppVar_2617 = P2;
	} else {
	cppVar_2623 = PC + 1;
	cppVar_2623 = (cppVar_2623 & cppMask_un_16_);
	cppVar_2624 = ROM.rd(cppVar_2623);
	cppVar_2626 = (cppVar_2624 == 168);
	if (cppVar_2626) {
	cppVar_2622 = IE;
	} else {
	cppVar_2628 = PC + 1;
	cppVar_2628 = (cppVar_2628 & cppMask_un_16_);
	cppVar_2629 = ROM.rd(cppVar_2628);
	cppVar_2631 = (cppVar_2629 == 176);
	if (cppVar_2631) {
	cppVar_2627 = P3;
	} else {
	cppVar_2633 = PC + 1;
	cppVar_2633 = (cppVar_2633 & cppMask_un_16_);
	cppVar_2634 = ROM.rd(cppVar_2633);
	cppVar_2636 = (cppVar_2634 == 184);
	if (cppVar_2636) {
	cppVar_2632 = IP;
	} else {
	cppVar_2638 = PC + 1;
	cppVar_2638 = (cppVar_2638 & cppMask_un_16_);
	cppVar_2639 = ROM.rd(cppVar_2638);
	cppVar_2641 = (cppVar_2639 == 208);
	if (cppVar_2641) {
	cppVar_2637 = PSW;
	} else {
	cppVar_2643 = PC + 1;
	cppVar_2643 = (cppVar_2643 & cppMask_un_16_);
	cppVar_2644 = ROM.rd(cppVar_2643);
	cppVar_2646 = (cppVar_2644 == 224);
	if (cppVar_2646) {
	cppVar_2642 = ACC;
	} else {
	cppVar_2648 = PC + 1;
	cppVar_2648 = (cppVar_2648 & cppMask_un_16_);
	cppVar_2649 = ROM.rd(cppVar_2648);
	cppVar_2651 = (cppVar_2649 == 240);
	if (cppVar_2651) {
	cppVar_2647 = B;
	} else {
	cppVar_2647 = 0;
	}
	cppVar_2642 = cppVar_2647;
	}
	cppVar_2637 = cppVar_2642;
	}
	cppVar_2632 = cppVar_2637;
	}
	cppVar_2627 = cppVar_2632;
	}
	cppVar_2622 = cppVar_2627;
	}
	cppVar_2617 = cppVar_2622;
	}
	cppVar_2612 = cppVar_2617;
	}
	cppVar_2607 = cppVar_2612;
	}
	cppVar_2602 = cppVar_2607;
	}
	cppVar_2597 = cppVar_2602;
	}
	cppVar_2592 = cppVar_2597;
	}
	cppVar_2587 = cppVar_2592;
	}
	cppVar_2582 = cppVar_2587;
	}
	cppVar_2577 = cppVar_2582;
	}
	cppVar_2572 = cppVar_2577;
	}
	cppVar_2567 = cppVar_2572;
	}
	cppVar_2562 = cppVar_2567;
	}
	cppVar_2557 = cppVar_2562;
	}
	cppVar_2552 = cppVar_2557;
	}
	cppVar_2547 = cppVar_2552;
	}
	cppVar_2537 = cppVar_2547;
	}
	cppVar_2653 = ACC + cppVar_2537;
	cppVar_2653 = (cppVar_2653 & cppMask_un_8_);
	cppVar_2654 = (PSW >> 7) & cppMask_un_1_;
	cppVar_2655 = (cppVar_2654 & cppMask_un_1_);
	cppVar_2656 = cppVar_2653 + cppVar_2655;
	cppVar_2656 = (cppVar_2656 & cppMask_un_8_);
	cppVar_2533 = cppVar_2656;
	} else {
	cppVar_2658 = ROM.rd(PC);
	cppVar_2660 = (cppVar_2658 == 52);
	if (cppVar_2660) {
	cppVar_2662 = PC + 1;
	cppVar_2662 = (cppVar_2662 & cppMask_un_16_);
	cppVar_2663 = ROM.rd(cppVar_2662);
	cppVar_2664 = ACC + cppVar_2663;
	cppVar_2664 = (cppVar_2664 & cppMask_un_8_);
	cppVar_2665 = (PSW >> 7) & cppMask_un_1_;
	cppVar_2666 = (cppVar_2665 & cppMask_un_1_);
	cppVar_2667 = cppVar_2664 + cppVar_2666;
	cppVar_2667 = (cppVar_2667 & cppMask_un_8_);
	cppVar_2657 = cppVar_2667;
	} else {
	cppVar_2669 = ROM.rd(PC);
	cppVar_2671 = (cppVar_2669 == 51);
	if (cppVar_2671) {
	cppVar_2672 = (PSW >> 7) & cppMask_un_1_;
	cppVar_2673 = (cppVar_2672 << 8) | ACC;
	cppVar_2673 = (cppVar_2673 & cppMask_un_9_);
	cppVar_2674 = (cppVar_2673 & cppMask_un_9_);
	cppVar_2674 = ((cppVar_2674 << 1) | ( cppVar_2674 >> 8)) & cppMask_un_9_;
	cppVar_2675 = (cppVar_2674 >> 0) & cppMask_un_8_;
	cppVar_2668 = cppVar_2675;
	} else {
	cppVar_2677 = ROM.rd(PC);
	cppVar_2679 = (cppVar_2677 == 47);
	if (cppVar_2679) {
	cppVar_2681 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2683 = (cppVar_2681 << 3) | 7;
	cppVar_2683 = (cppVar_2683 & cppMask_un_5_);
	cppVar_2684 = (0 << 5) | cppVar_2683;
	cppVar_2684 = (cppVar_2684 & cppMask_un_8_);
	cppVar_2685 = IRAM.rd(cppVar_2684);
	cppVar_2686 = ACC + cppVar_2685;
	cppVar_2686 = (cppVar_2686 & cppMask_un_8_);
	cppVar_2676 = cppVar_2686;
	} else {
	cppVar_2688 = ROM.rd(PC);
	cppVar_2690 = (cppVar_2688 == 46);
	if (cppVar_2690) {
	cppVar_2692 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2694 = (cppVar_2692 << 3) | 6;
	cppVar_2694 = (cppVar_2694 & cppMask_un_5_);
	cppVar_2695 = (0 << 5) | cppVar_2694;
	cppVar_2695 = (cppVar_2695 & cppMask_un_8_);
	cppVar_2696 = IRAM.rd(cppVar_2695);
	cppVar_2697 = ACC + cppVar_2696;
	cppVar_2697 = (cppVar_2697 & cppMask_un_8_);
	cppVar_2687 = cppVar_2697;
	} else {
	cppVar_2699 = ROM.rd(PC);
	cppVar_2701 = (cppVar_2699 == 45);
	if (cppVar_2701) {
	cppVar_2703 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2705 = (cppVar_2703 << 3) | 5;
	cppVar_2705 = (cppVar_2705 & cppMask_un_5_);
	cppVar_2706 = (0 << 5) | cppVar_2705;
	cppVar_2706 = (cppVar_2706 & cppMask_un_8_);
	cppVar_2707 = IRAM.rd(cppVar_2706);
	cppVar_2708 = ACC + cppVar_2707;
	cppVar_2708 = (cppVar_2708 & cppMask_un_8_);
	cppVar_2698 = cppVar_2708;
	} else {
	cppVar_2710 = ROM.rd(PC);
	cppVar_2712 = (cppVar_2710 == 44);
	if (cppVar_2712) {
	cppVar_2714 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2716 = (cppVar_2714 << 3) | 4;
	cppVar_2716 = (cppVar_2716 & cppMask_un_5_);
	cppVar_2717 = (0 << 5) | cppVar_2716;
	cppVar_2717 = (cppVar_2717 & cppMask_un_8_);
	cppVar_2718 = IRAM.rd(cppVar_2717);
	cppVar_2719 = ACC + cppVar_2718;
	cppVar_2719 = (cppVar_2719 & cppMask_un_8_);
	cppVar_2709 = cppVar_2719;
	} else {
	cppVar_2721 = ROM.rd(PC);
	cppVar_2723 = (cppVar_2721 == 43);
	if (cppVar_2723) {
	cppVar_2725 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2727 = (cppVar_2725 << 3) | 3;
	cppVar_2727 = (cppVar_2727 & cppMask_un_5_);
	cppVar_2728 = (0 << 5) | cppVar_2727;
	cppVar_2728 = (cppVar_2728 & cppMask_un_8_);
	cppVar_2729 = IRAM.rd(cppVar_2728);
	cppVar_2730 = ACC + cppVar_2729;
	cppVar_2730 = (cppVar_2730 & cppMask_un_8_);
	cppVar_2720 = cppVar_2730;
	} else {
	cppVar_2732 = ROM.rd(PC);
	cppVar_2734 = (cppVar_2732 == 42);
	if (cppVar_2734) {
	cppVar_2736 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2738 = (cppVar_2736 << 3) | 2;
	cppVar_2738 = (cppVar_2738 & cppMask_un_5_);
	cppVar_2739 = (0 << 5) | cppVar_2738;
	cppVar_2739 = (cppVar_2739 & cppMask_un_8_);
	cppVar_2740 = IRAM.rd(cppVar_2739);
	cppVar_2741 = ACC + cppVar_2740;
	cppVar_2741 = (cppVar_2741 & cppMask_un_8_);
	cppVar_2731 = cppVar_2741;
	} else {
	cppVar_2743 = ROM.rd(PC);
	cppVar_2745 = (cppVar_2743 == 41);
	if (cppVar_2745) {
	cppVar_2747 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2749 = (cppVar_2747 << 3) | 1;
	cppVar_2749 = (cppVar_2749 & cppMask_un_5_);
	cppVar_2750 = (0 << 5) | cppVar_2749;
	cppVar_2750 = (cppVar_2750 & cppMask_un_8_);
	cppVar_2751 = IRAM.rd(cppVar_2750);
	cppVar_2752 = ACC + cppVar_2751;
	cppVar_2752 = (cppVar_2752 & cppMask_un_8_);
	cppVar_2742 = cppVar_2752;
	} else {
	cppVar_2754 = ROM.rd(PC);
	cppVar_2756 = (cppVar_2754 == 40);
	if (cppVar_2756) {
	cppVar_2758 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2760 = (cppVar_2758 << 3) | 0;
	cppVar_2760 = (cppVar_2760 & cppMask_un_5_);
	cppVar_2761 = (0 << 5) | cppVar_2760;
	cppVar_2761 = (cppVar_2761 & cppMask_un_8_);
	cppVar_2762 = IRAM.rd(cppVar_2761);
	cppVar_2763 = ACC + cppVar_2762;
	cppVar_2763 = (cppVar_2763 & cppMask_un_8_);
	cppVar_2753 = cppVar_2763;
	} else {
	cppVar_2765 = ROM.rd(PC);
	cppVar_2767 = (cppVar_2765 == 39);
	if (cppVar_2767) {
	cppVar_2769 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2771 = (cppVar_2769 << 3) | 1;
	cppVar_2771 = (cppVar_2771 & cppMask_un_5_);
	cppVar_2772 = (0 << 5) | cppVar_2771;
	cppVar_2772 = (cppVar_2772 & cppMask_un_8_);
	cppVar_2773 = IRAM.rd(cppVar_2772);
	cppVar_2774 = IRAM.rd(cppVar_2773);
	cppVar_2775 = ACC + cppVar_2774;
	cppVar_2775 = (cppVar_2775 & cppMask_un_8_);
	cppVar_2764 = cppVar_2775;
	} else {
	cppVar_2777 = ROM.rd(PC);
	cppVar_2779 = (cppVar_2777 == 38);
	if (cppVar_2779) {
	cppVar_2781 = (PSW >> 3) & cppMask_un_2_;
	cppVar_2783 = (cppVar_2781 << 3) | 0;
	cppVar_2783 = (cppVar_2783 & cppMask_un_5_);
	cppVar_2784 = (0 << 5) | cppVar_2783;
	cppVar_2784 = (cppVar_2784 & cppMask_un_8_);
	cppVar_2785 = IRAM.rd(cppVar_2784);
	cppVar_2786 = IRAM.rd(cppVar_2785);
	cppVar_2787 = ACC + cppVar_2786;
	cppVar_2787 = (cppVar_2787 & cppMask_un_8_);
	cppVar_2776 = cppVar_2787;
	} else {
	cppVar_2789 = ROM.rd(PC);
	cppVar_2791 = (cppVar_2789 == 37);
	if (cppVar_2791) {
	cppVar_2794 = PC + 1;
	cppVar_2794 = (cppVar_2794 & cppMask_un_16_);
	cppVar_2795 = ROM.rd(cppVar_2794);
	cppVar_2796 = (cppVar_2795 >> 7) & cppMask_un_1_;
	cppVar_2798 = (cppVar_2796 == 0);
	if (cppVar_2798) {
	cppVar_2799 = PC + 1;
	cppVar_2799 = (cppVar_2799 & cppMask_un_16_);
	cppVar_2800 = ROM.rd(cppVar_2799);
	cppVar_2801 = IRAM.rd(cppVar_2800);
	cppVar_2792 = cppVar_2801;
	} else {
	cppVar_2803 = PC + 1;
	cppVar_2803 = (cppVar_2803 & cppMask_un_16_);
	cppVar_2804 = ROM.rd(cppVar_2803);
	cppVar_2806 = (cppVar_2804 == 128);
	if (cppVar_2806) {
	cppVar_2802 = P0;
	} else {
	cppVar_2808 = PC + 1;
	cppVar_2808 = (cppVar_2808 & cppMask_un_16_);
	cppVar_2809 = ROM.rd(cppVar_2808);
	cppVar_2811 = (cppVar_2809 == 129);
	if (cppVar_2811) {
	cppVar_2807 = SP;
	} else {
	cppVar_2813 = PC + 1;
	cppVar_2813 = (cppVar_2813 & cppMask_un_16_);
	cppVar_2814 = ROM.rd(cppVar_2813);
	cppVar_2816 = (cppVar_2814 == 130);
	if (cppVar_2816) {
	cppVar_2812 = DPL;
	} else {
	cppVar_2818 = PC + 1;
	cppVar_2818 = (cppVar_2818 & cppMask_un_16_);
	cppVar_2819 = ROM.rd(cppVar_2818);
	cppVar_2821 = (cppVar_2819 == 131);
	if (cppVar_2821) {
	cppVar_2817 = DPH;
	} else {
	cppVar_2823 = PC + 1;
	cppVar_2823 = (cppVar_2823 & cppMask_un_16_);
	cppVar_2824 = ROM.rd(cppVar_2823);
	cppVar_2826 = (cppVar_2824 == 135);
	if (cppVar_2826) {
	cppVar_2822 = PCON;
	} else {
	cppVar_2828 = PC + 1;
	cppVar_2828 = (cppVar_2828 & cppMask_un_16_);
	cppVar_2829 = ROM.rd(cppVar_2828);
	cppVar_2831 = (cppVar_2829 == 136);
	if (cppVar_2831) {
	cppVar_2827 = TCON;
	} else {
	cppVar_2833 = PC + 1;
	cppVar_2833 = (cppVar_2833 & cppMask_un_16_);
	cppVar_2834 = ROM.rd(cppVar_2833);
	cppVar_2836 = (cppVar_2834 == 137);
	if (cppVar_2836) {
	cppVar_2832 = TMOD;
	} else {
	cppVar_2838 = PC + 1;
	cppVar_2838 = (cppVar_2838 & cppMask_un_16_);
	cppVar_2839 = ROM.rd(cppVar_2838);
	cppVar_2841 = (cppVar_2839 == 138);
	if (cppVar_2841) {
	cppVar_2837 = TL0;
	} else {
	cppVar_2843 = PC + 1;
	cppVar_2843 = (cppVar_2843 & cppMask_un_16_);
	cppVar_2844 = ROM.rd(cppVar_2843);
	cppVar_2846 = (cppVar_2844 == 140);
	if (cppVar_2846) {
	cppVar_2842 = TH0;
	} else {
	cppVar_2848 = PC + 1;
	cppVar_2848 = (cppVar_2848 & cppMask_un_16_);
	cppVar_2849 = ROM.rd(cppVar_2848);
	cppVar_2851 = (cppVar_2849 == 139);
	if (cppVar_2851) {
	cppVar_2847 = TL1;
	} else {
	cppVar_2853 = PC + 1;
	cppVar_2853 = (cppVar_2853 & cppMask_un_16_);
	cppVar_2854 = ROM.rd(cppVar_2853);
	cppVar_2856 = (cppVar_2854 == 141);
	if (cppVar_2856) {
	cppVar_2852 = TH1;
	} else {
	cppVar_2858 = PC + 1;
	cppVar_2858 = (cppVar_2858 & cppMask_un_16_);
	cppVar_2859 = ROM.rd(cppVar_2858);
	cppVar_2861 = (cppVar_2859 == 144);
	if (cppVar_2861) {
	cppVar_2857 = P1;
	} else {
	cppVar_2863 = PC + 1;
	cppVar_2863 = (cppVar_2863 & cppMask_un_16_);
	cppVar_2864 = ROM.rd(cppVar_2863);
	cppVar_2866 = (cppVar_2864 == 152);
	if (cppVar_2866) {
	cppVar_2862 = SCON;
	} else {
	cppVar_2868 = PC + 1;
	cppVar_2868 = (cppVar_2868 & cppMask_un_16_);
	cppVar_2869 = ROM.rd(cppVar_2868);
	cppVar_2871 = (cppVar_2869 == 153);
	if (cppVar_2871) {
	cppVar_2867 = SBUF;
	} else {
	cppVar_2873 = PC + 1;
	cppVar_2873 = (cppVar_2873 & cppMask_un_16_);
	cppVar_2874 = ROM.rd(cppVar_2873);
	cppVar_2876 = (cppVar_2874 == 160);
	if (cppVar_2876) {
	cppVar_2872 = P2;
	} else {
	cppVar_2878 = PC + 1;
	cppVar_2878 = (cppVar_2878 & cppMask_un_16_);
	cppVar_2879 = ROM.rd(cppVar_2878);
	cppVar_2881 = (cppVar_2879 == 168);
	if (cppVar_2881) {
	cppVar_2877 = IE;
	} else {
	cppVar_2883 = PC + 1;
	cppVar_2883 = (cppVar_2883 & cppMask_un_16_);
	cppVar_2884 = ROM.rd(cppVar_2883);
	cppVar_2886 = (cppVar_2884 == 176);
	if (cppVar_2886) {
	cppVar_2882 = P3;
	} else {
	cppVar_2888 = PC + 1;
	cppVar_2888 = (cppVar_2888 & cppMask_un_16_);
	cppVar_2889 = ROM.rd(cppVar_2888);
	cppVar_2891 = (cppVar_2889 == 184);
	if (cppVar_2891) {
	cppVar_2887 = IP;
	} else {
	cppVar_2893 = PC + 1;
	cppVar_2893 = (cppVar_2893 & cppMask_un_16_);
	cppVar_2894 = ROM.rd(cppVar_2893);
	cppVar_2896 = (cppVar_2894 == 208);
	if (cppVar_2896) {
	cppVar_2892 = PSW;
	} else {
	cppVar_2898 = PC + 1;
	cppVar_2898 = (cppVar_2898 & cppMask_un_16_);
	cppVar_2899 = ROM.rd(cppVar_2898);
	cppVar_2901 = (cppVar_2899 == 224);
	if (cppVar_2901) {
	cppVar_2897 = ACC;
	} else {
	cppVar_2903 = PC + 1;
	cppVar_2903 = (cppVar_2903 & cppMask_un_16_);
	cppVar_2904 = ROM.rd(cppVar_2903);
	cppVar_2906 = (cppVar_2904 == 240);
	if (cppVar_2906) {
	cppVar_2902 = B;
	} else {
	cppVar_2902 = 0;
	}
	cppVar_2897 = cppVar_2902;
	}
	cppVar_2892 = cppVar_2897;
	}
	cppVar_2887 = cppVar_2892;
	}
	cppVar_2882 = cppVar_2887;
	}
	cppVar_2877 = cppVar_2882;
	}
	cppVar_2872 = cppVar_2877;
	}
	cppVar_2867 = cppVar_2872;
	}
	cppVar_2862 = cppVar_2867;
	}
	cppVar_2857 = cppVar_2862;
	}
	cppVar_2852 = cppVar_2857;
	}
	cppVar_2847 = cppVar_2852;
	}
	cppVar_2842 = cppVar_2847;
	}
	cppVar_2837 = cppVar_2842;
	}
	cppVar_2832 = cppVar_2837;
	}
	cppVar_2827 = cppVar_2832;
	}
	cppVar_2822 = cppVar_2827;
	}
	cppVar_2817 = cppVar_2822;
	}
	cppVar_2812 = cppVar_2817;
	}
	cppVar_2807 = cppVar_2812;
	}
	cppVar_2802 = cppVar_2807;
	}
	cppVar_2792 = cppVar_2802;
	}
	cppVar_2908 = ACC + cppVar_2792;
	cppVar_2908 = (cppVar_2908 & cppMask_un_8_);
	cppVar_2788 = cppVar_2908;
	} else {
	cppVar_2910 = ROM.rd(PC);
	cppVar_2912 = (cppVar_2910 == 36);
	if (cppVar_2912) {
	cppVar_2914 = PC + 1;
	cppVar_2914 = (cppVar_2914 & cppMask_un_16_);
	cppVar_2915 = ROM.rd(cppVar_2914);
	cppVar_2916 = ACC + cppVar_2915;
	cppVar_2916 = (cppVar_2916 & cppMask_un_8_);
	cppVar_2909 = cppVar_2916;
	} else {
	cppVar_2918 = ROM.rd(PC);
	cppVar_2920 = (cppVar_2918 == 35);
	if (cppVar_2920) {
	cppVar_2921 = (ACC & cppMask_un_8_);
	cppVar_2921 = ((cppVar_2921 << 1) | ( cppVar_2921 >> 7)) & cppMask_un_8_;
	cppVar_2917 = cppVar_2921;
	} else {
	cppVar_2923 = ROM.rd(PC);
	cppVar_2925 = (cppVar_2923 == 20);
	if (cppVar_2925) {
	cppVar_2927 = ACC - 1;
	cppVar_2927 = (cppVar_2927 & cppMask_un_8_);
	cppVar_2922 = cppVar_2927;
	} else {
	cppVar_2929 = ROM.rd(PC);
	cppVar_2931 = (cppVar_2929 == 19);
	if (cppVar_2931) {
	cppVar_2932 = (PSW >> 7) & cppMask_un_1_;
	cppVar_2933 = (ACC << 1) | cppVar_2932;
	cppVar_2933 = (cppVar_2933 & cppMask_un_9_);
	cppVar_2934 = (cppVar_2933 & cppMask_un_9_);
	cppVar_2934 = ((cppVar_2934 << 8) | ( cppVar_2934 >> 1)) & cppMask_un_9_;
	cppVar_2935 = (cppVar_2934 >> 1) & cppMask_un_8_;
	cppVar_2928 = cppVar_2935;
	} else {
	cppVar_2937 = ROM.rd(PC);
	cppVar_2939 = (cppVar_2937 == 4);
	if (cppVar_2939) {
	cppVar_2941 = ACC + 1;
	cppVar_2941 = (cppVar_2941 & cppMask_un_8_);
	cppVar_2936 = cppVar_2941;
	} else {
	cppVar_2943 = ROM.rd(PC);
	cppVar_2945 = (cppVar_2943 == 3);
	if (cppVar_2945) {
	cppVar_2946 = (ACC & cppMask_un_8_);
	cppVar_2946 = ((cppVar_2946 << 7) | ( cppVar_2946 >> 1)) & cppMask_un_8_;
	cppVar_2942 = cppVar_2946;
	} else {
	cppVar_2942 = ACC;
	}
	cppVar_2936 = cppVar_2942;
	}
	cppVar_2928 = cppVar_2936;
	}
	cppVar_2922 = cppVar_2928;
	}
	cppVar_2917 = cppVar_2922;
	}
	cppVar_2909 = cppVar_2917;
	}
	cppVar_2788 = cppVar_2909;
	}
	cppVar_2776 = cppVar_2788;
	}
	cppVar_2764 = cppVar_2776;
	}
	cppVar_2753 = cppVar_2764;
	}
	cppVar_2742 = cppVar_2753;
	}
	cppVar_2731 = cppVar_2742;
	}
	cppVar_2720 = cppVar_2731;
	}
	cppVar_2709 = cppVar_2720;
	}
	cppVar_2698 = cppVar_2709;
	}
	cppVar_2687 = cppVar_2698;
	}
	cppVar_2676 = cppVar_2687;
	}
	cppVar_2668 = cppVar_2676;
	}
	cppVar_2657 = cppVar_2668;
	}
	cppVar_2533 = cppVar_2657;
	}
	cppVar_2518 = cppVar_2533;
	}
	cppVar_2503 = cppVar_2518;
	}
	cppVar_2489 = cppVar_2503;
	}
	cppVar_2475 = cppVar_2489;
	}
	cppVar_2461 = cppVar_2475;
	}
	cppVar_2447 = cppVar_2461;
	}
	cppVar_2433 = cppVar_2447;
	}
	cppVar_2419 = cppVar_2433;
	}
	cppVar_2405 = cppVar_2419;
	}
	cppVar_2391 = cppVar_2405;
	}
	cppVar_2383 = cppVar_2391;
	}
	cppVar_2262 = cppVar_2383;
	}
	cppVar_2250 = cppVar_2262;
	}
	cppVar_2238 = cppVar_2250;
	}
	cppVar_2227 = cppVar_2238;
	}
	cppVar_2216 = cppVar_2227;
	}
	cppVar_2205 = cppVar_2216;
	}
	cppVar_2194 = cppVar_2205;
	}
	cppVar_2183 = cppVar_2194;
	}
	cppVar_2172 = cppVar_2183;
	}
	cppVar_2161 = cppVar_2172;
	}
	cppVar_2150 = cppVar_2161;
	}
	cppVar_2142 = cppVar_2150;
	}
	cppVar_2021 = cppVar_2142;
	}
	cppVar_2009 = cppVar_2021;
	}
	cppVar_1997 = cppVar_2009;
	}
	cppVar_1986 = cppVar_1997;
	}
	cppVar_1975 = cppVar_1986;
	}
	cppVar_1964 = cppVar_1975;
	}
	cppVar_1953 = cppVar_1964;
	}
	cppVar_1942 = cppVar_1953;
	}
	cppVar_1931 = cppVar_1942;
	}
	cppVar_1920 = cppVar_1931;
	}
	cppVar_1909 = cppVar_1920;
	}
	cppVar_1901 = cppVar_1909;
	}
	cppVar_1780 = cppVar_1901;
	}
	cppVar_1768 = cppVar_1780;
	}
	cppVar_1756 = cppVar_1768;
	}
	cppVar_1745 = cppVar_1756;
	}
	cppVar_1734 = cppVar_1745;
	}
	cppVar_1723 = cppVar_1734;
	}
	cppVar_1712 = cppVar_1723;
	}
	cppVar_1701 = cppVar_1712;
	}
	cppVar_1690 = cppVar_1701;
	}
	cppVar_1679 = cppVar_1690;
	}
	cppVar_1668 = cppVar_1679;
	}
	cppVar_1661 = cppVar_1668;
	}
	cppVar_1652 = cppVar_1661;
	}
	cppVar_1643 = cppVar_1652;
	}
	cppVar_1635 = cppVar_1643;
	}
	cppVar_1624 = cppVar_1635;
	}
	cppVar_1500 = cppVar_1624;
	}
	cppVar_1485 = cppVar_1500;
	}
	cppVar_1470 = cppVar_1485;
	}
	cppVar_1456 = cppVar_1470;
	}
	cppVar_1442 = cppVar_1456;
	}
	cppVar_1428 = cppVar_1442;
	}
	cppVar_1414 = cppVar_1428;
	}
	cppVar_1400 = cppVar_1414;
	}
	cppVar_1386 = cppVar_1400;
	}
	cppVar_1372 = cppVar_1386;
	}
	cppVar_1358 = cppVar_1372;
	}
	cppVar_1350 = cppVar_1358;
	}
	cppVar_1343 = cppVar_1350;
	}
	cppVar_1219 = cppVar_1343;
	}
	cppVar_1204 = cppVar_1219;
	}
	cppVar_1189 = cppVar_1204;
	}
	cppVar_1041 = cppVar_1189;
	}
	cppVar_893 = cppVar_1041;
	}
	cppVar_745 = cppVar_893;
	}
	cppVar_597 = cppVar_745;
	}
	cppVar_449 = cppVar_597;
	}
	cppVar_435 = cppVar_449;
	}
	cppVar_425 = cppVar_435;
	}
	cppVar_277 = cppVar_425;
	}
	cppVar_221 = cppVar_277;
	}
	cppVar_207 = cppVar_221;
	}
	cppVar_193 = cppVar_207;
	}
	cppVar_181 = cppVar_193;
	}
	cppVar_176 = cppVar_181;
	}
	cppVar_32 = cppVar_176;
	}
	cppVar_27 = cppVar_32;
	}
	return cppVar_27;
}
