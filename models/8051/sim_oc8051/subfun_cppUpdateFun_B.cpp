#include "common.hpp"
#include "model_oc8051_class.hpp"

BIT_VEC model_oc8051::cppUpdateFun_B()
{
	BIT_VEC cppVar_2949;
	BIT_VEC cppVar_2950;
	bool cppVar_2951;
	BIT_VEC cppVar_2954;
	BIT_VEC cppVar_2955;
	BIT_VEC cppVar_2956;
	BIT_VEC cppVar_2957;
	BIT_VEC cppVar_2958;
	bool cppVar_2959;
	BIT_VEC cppVar_2960;
	BIT_VEC cppVar_2961;
	BIT_VEC cppVar_2962;
	BIT_VEC cppVar_2963;
	BIT_VEC cppVar_2964;
	BIT_VEC cppVar_2965;
	BIT_VEC cppVar_2966;
	BIT_VEC cppVar_2967;
	BIT_VEC cppVar_2968;
	BIT_VEC cppVar_2969;
	BIT_VEC cppVar_2970;
	BIT_VEC cppVar_2953;
	BIT_VEC cppVar_2971;
	bool cppVar_2972;
	BIT_VEC cppVar_2973;
	BIT_VEC cppVar_2974;
	BIT_VEC cppVar_2975;
	BIT_VEC cppVar_2976;
	BIT_VEC cppVar_2977;
	BIT_VEC cppVar_2978;
	BIT_VEC cppVar_2979;
	BIT_VEC cppVar_2982;
	BIT_VEC cppVar_2983;
	BIT_VEC cppVar_2984;
	bool cppVar_2985;
	BIT_VEC cppVar_2986;
	BIT_VEC cppVar_2987;
	BIT_VEC cppVar_2988;
	BIT_VEC cppVar_2989;
	BIT_VEC cppVar_2990;
	BIT_VEC cppVar_2991;
	BIT_VEC cppVar_2992;
	BIT_VEC cppVar_2993;
	BIT_VEC cppVar_2994;
	BIT_VEC cppVar_2981;
	BIT_VEC cppVar_2995;
	BIT_VEC cppVar_2996;
	bool cppVar_2997;
	BIT_VEC cppVar_2999;
	BIT_VEC cppVar_3000;
	BIT_VEC cppVar_3001;
	bool cppVar_3002;
	BIT_VEC cppVar_3003;
	BIT_VEC cppVar_3004;
	BIT_VEC cppVar_3005;
	BIT_VEC cppVar_3006;
	BIT_VEC cppVar_3007;
	BIT_VEC cppVar_3008;
	BIT_VEC cppVar_3009;
	BIT_VEC cppVar_3010;
	BIT_VEC cppVar_3011;
	BIT_VEC cppVar_2998;
	BIT_VEC cppVar_3012;
	BIT_VEC cppVar_3015;
	BIT_VEC cppVar_3016;
	BIT_VEC cppVar_3017;
	bool cppVar_3018;
	BIT_VEC cppVar_3019;
	BIT_VEC cppVar_3020;
	BIT_VEC cppVar_3021;
	BIT_VEC cppVar_3022;
	BIT_VEC cppVar_3023;
	BIT_VEC cppVar_3024;
	BIT_VEC cppVar_3025;
	BIT_VEC cppVar_3026;
	BIT_VEC cppVar_3027;
	BIT_VEC cppVar_3014;
	BIT_VEC cppVar_3028;
	bool cppVar_3029;
	BIT_VEC cppVar_3032;
	BIT_VEC cppVar_3033;
	BIT_VEC cppVar_3034;
	bool cppVar_3035;
	BIT_VEC cppVar_3036;
	BIT_VEC cppVar_3037;
	BIT_VEC cppVar_3038;
	BIT_VEC cppVar_3039;
	BIT_VEC cppVar_3040;
	BIT_VEC cppVar_3041;
	BIT_VEC cppVar_3042;
	BIT_VEC cppVar_3043;
	BIT_VEC cppVar_3044;
	BIT_VEC cppVar_3031;
	BIT_VEC cppVar_3045;
	bool cppVar_3046;
	BIT_VEC cppVar_3049;
	BIT_VEC cppVar_3050;
	BIT_VEC cppVar_3051;
	bool cppVar_3052;
	BIT_VEC cppVar_3053;
	BIT_VEC cppVar_3054;
	BIT_VEC cppVar_3055;
	BIT_VEC cppVar_3056;
	BIT_VEC cppVar_3057;
	BIT_VEC cppVar_3058;
	BIT_VEC cppVar_3059;
	BIT_VEC cppVar_3060;
	BIT_VEC cppVar_3061;
	BIT_VEC cppVar_3048;
	BIT_VEC cppVar_3062;
	bool cppVar_3063;
	BIT_VEC cppVar_3066;
	BIT_VEC cppVar_3067;
	BIT_VEC cppVar_3068;
	bool cppVar_3069;
	BIT_VEC cppVar_3070;
	BIT_VEC cppVar_3071;
	BIT_VEC cppVar_3072;
	BIT_VEC cppVar_3073;
	BIT_VEC cppVar_3074;
	BIT_VEC cppVar_3075;
	BIT_VEC cppVar_3076;
	BIT_VEC cppVar_3077;
	BIT_VEC cppVar_3078;
	BIT_VEC cppVar_3065;
	BIT_VEC cppVar_3079;
	bool cppVar_3080;
	BIT_VEC cppVar_3083;
	BIT_VEC cppVar_3084;
	BIT_VEC cppVar_3085;
	bool cppVar_3086;
	BIT_VEC cppVar_3087;
	BIT_VEC cppVar_3088;
	BIT_VEC cppVar_3089;
	BIT_VEC cppVar_3090;
	BIT_VEC cppVar_3091;
	BIT_VEC cppVar_3092;
	BIT_VEC cppVar_3093;
	BIT_VEC cppVar_3094;
	BIT_VEC cppVar_3095;
	BIT_VEC cppVar_3082;
	BIT_VEC cppVar_3096;
	bool cppVar_3097;
	BIT_VEC cppVar_3100;
	BIT_VEC cppVar_3101;
	BIT_VEC cppVar_3102;
	bool cppVar_3103;
	BIT_VEC cppVar_3104;
	BIT_VEC cppVar_3105;
	BIT_VEC cppVar_3106;
	BIT_VEC cppVar_3107;
	BIT_VEC cppVar_3108;
	BIT_VEC cppVar_3109;
	BIT_VEC cppVar_3110;
	BIT_VEC cppVar_3111;
	BIT_VEC cppVar_3112;
	BIT_VEC cppVar_3099;
	BIT_VEC cppVar_3113;
	bool cppVar_3114;
	BIT_VEC cppVar_3117;
	BIT_VEC cppVar_3118;
	BIT_VEC cppVar_3119;
	bool cppVar_3120;
	BIT_VEC cppVar_3121;
	BIT_VEC cppVar_3122;
	BIT_VEC cppVar_3123;
	BIT_VEC cppVar_3124;
	BIT_VEC cppVar_3125;
	BIT_VEC cppVar_3126;
	BIT_VEC cppVar_3127;
	BIT_VEC cppVar_3128;
	BIT_VEC cppVar_3129;
	BIT_VEC cppVar_3116;
	BIT_VEC cppVar_3130;
	bool cppVar_3131;
	BIT_VEC cppVar_3134;
	BIT_VEC cppVar_3135;
	BIT_VEC cppVar_3136;
	bool cppVar_3137;
	BIT_VEC cppVar_3138;
	BIT_VEC cppVar_3139;
	BIT_VEC cppVar_3140;
	BIT_VEC cppVar_3141;
	BIT_VEC cppVar_3142;
	BIT_VEC cppVar_3143;
	BIT_VEC cppVar_3144;
	BIT_VEC cppVar_3145;
	BIT_VEC cppVar_3146;
	BIT_VEC cppVar_3133;
	BIT_VEC cppVar_3147;
	bool cppVar_3148;
	BIT_VEC cppVar_3151;
	BIT_VEC cppVar_3152;
	BIT_VEC cppVar_3153;
	bool cppVar_3154;
	BIT_VEC cppVar_3155;
	BIT_VEC cppVar_3156;
	BIT_VEC cppVar_3157;
	BIT_VEC cppVar_3158;
	BIT_VEC cppVar_3159;
	BIT_VEC cppVar_3160;
	BIT_VEC cppVar_3161;
	BIT_VEC cppVar_3162;
	BIT_VEC cppVar_3163;
	BIT_VEC cppVar_3150;
	BIT_VEC cppVar_3164;
	bool cppVar_3165;
	BIT_VEC cppVar_3168;
	BIT_VEC cppVar_3169;
	BIT_VEC cppVar_3170;
	bool cppVar_3171;
	BIT_VEC cppVar_3172;
	BIT_VEC cppVar_3173;
	BIT_VEC cppVar_3174;
	BIT_VEC cppVar_3175;
	BIT_VEC cppVar_3176;
	BIT_VEC cppVar_3177;
	BIT_VEC cppVar_3178;
	BIT_VEC cppVar_3179;
	BIT_VEC cppVar_3180;
	BIT_VEC cppVar_3167;
	BIT_VEC cppVar_3181;
	bool cppVar_3182;
	BIT_VEC cppVar_3185;
	BIT_VEC cppVar_3186;
	BIT_VEC cppVar_3187;
	bool cppVar_3188;
	BIT_VEC cppVar_3189;
	BIT_VEC cppVar_3190;
	BIT_VEC cppVar_3191;
	BIT_VEC cppVar_3192;
	BIT_VEC cppVar_3193;
	BIT_VEC cppVar_3194;
	BIT_VEC cppVar_3195;
	BIT_VEC cppVar_3196;
	BIT_VEC cppVar_3197;
	BIT_VEC cppVar_3184;
	BIT_VEC cppVar_3198;
	bool cppVar_3199;
	BIT_VEC cppVar_3202;
	BIT_VEC cppVar_3203;
	BIT_VEC cppVar_3204;
	bool cppVar_3205;
	BIT_VEC cppVar_3206;
	BIT_VEC cppVar_3207;
	BIT_VEC cppVar_3208;
	BIT_VEC cppVar_3209;
	BIT_VEC cppVar_3210;
	BIT_VEC cppVar_3211;
	BIT_VEC cppVar_3212;
	BIT_VEC cppVar_3213;
	BIT_VEC cppVar_3214;
	BIT_VEC cppVar_3201;
	BIT_VEC cppVar_3215;
	bool cppVar_3216;
	BIT_VEC cppVar_3219;
	BIT_VEC cppVar_3220;
	BIT_VEC cppVar_3221;
	bool cppVar_3222;
	BIT_VEC cppVar_3223;
	BIT_VEC cppVar_3224;
	BIT_VEC cppVar_3225;
	BIT_VEC cppVar_3226;
	BIT_VEC cppVar_3227;
	BIT_VEC cppVar_3228;
	BIT_VEC cppVar_3229;
	BIT_VEC cppVar_3230;
	BIT_VEC cppVar_3231;
	BIT_VEC cppVar_3218;
	BIT_VEC cppVar_3232;
	bool cppVar_3233;
	BIT_VEC cppVar_3236;
	BIT_VEC cppVar_3237;
	BIT_VEC cppVar_3238;
	bool cppVar_3239;
	BIT_VEC cppVar_3240;
	BIT_VEC cppVar_3241;
	BIT_VEC cppVar_3242;
	BIT_VEC cppVar_3243;
	BIT_VEC cppVar_3244;
	BIT_VEC cppVar_3245;
	BIT_VEC cppVar_3246;
	BIT_VEC cppVar_3247;
	BIT_VEC cppVar_3248;
	BIT_VEC cppVar_3235;
	BIT_VEC cppVar_3249;
	bool cppVar_3250;
	BIT_VEC cppVar_3253;
	BIT_VEC cppVar_3254;
	BIT_VEC cppVar_3255;
	bool cppVar_3256;
	BIT_VEC cppVar_3257;
	BIT_VEC cppVar_3258;
	BIT_VEC cppVar_3259;
	BIT_VEC cppVar_3260;
	BIT_VEC cppVar_3261;
	BIT_VEC cppVar_3262;
	BIT_VEC cppVar_3263;
	BIT_VEC cppVar_3264;
	BIT_VEC cppVar_3265;
	BIT_VEC cppVar_3252;
	BIT_VEC cppVar_3266;
	bool cppVar_3267;
	BIT_VEC cppVar_3270;
	BIT_VEC cppVar_3271;
	BIT_VEC cppVar_3272;
	bool cppVar_3273;
	BIT_VEC cppVar_3274;
	BIT_VEC cppVar_3275;
	BIT_VEC cppVar_3276;
	BIT_VEC cppVar_3277;
	BIT_VEC cppVar_3278;
	BIT_VEC cppVar_3279;
	BIT_VEC cppVar_3280;
	BIT_VEC cppVar_3281;
	BIT_VEC cppVar_3282;
	BIT_VEC cppVar_3269;
	BIT_VEC cppVar_3283;
	bool cppVar_3284;
	BIT_VEC cppVar_3287;
	BIT_VEC cppVar_3288;
	BIT_VEC cppVar_3289;
	bool cppVar_3290;
	BIT_VEC cppVar_3291;
	BIT_VEC cppVar_3292;
	BIT_VEC cppVar_3293;
	BIT_VEC cppVar_3294;
	BIT_VEC cppVar_3295;
	BIT_VEC cppVar_3296;
	BIT_VEC cppVar_3297;
	BIT_VEC cppVar_3298;
	BIT_VEC cppVar_3299;
	BIT_VEC cppVar_3286;
	BIT_VEC cppVar_3300;
	bool cppVar_3301;
	BIT_VEC cppVar_3304;
	BIT_VEC cppVar_3305;
	BIT_VEC cppVar_3306;
	bool cppVar_3307;
	BIT_VEC cppVar_3308;
	BIT_VEC cppVar_3309;
	BIT_VEC cppVar_3310;
	BIT_VEC cppVar_3311;
	BIT_VEC cppVar_3312;
	BIT_VEC cppVar_3313;
	BIT_VEC cppVar_3314;
	BIT_VEC cppVar_3315;
	BIT_VEC cppVar_3316;
	BIT_VEC cppVar_3303;
	BIT_VEC cppVar_3317;
	bool cppVar_3318;
	BIT_VEC cppVar_3321;
	BIT_VEC cppVar_3322;
	BIT_VEC cppVar_3323;
	bool cppVar_3324;
	BIT_VEC cppVar_3325;
	BIT_VEC cppVar_3326;
	BIT_VEC cppVar_3327;
	BIT_VEC cppVar_3328;
	BIT_VEC cppVar_3329;
	BIT_VEC cppVar_3330;
	BIT_VEC cppVar_3331;
	BIT_VEC cppVar_3332;
	BIT_VEC cppVar_3333;
	BIT_VEC cppVar_3320;
	BIT_VEC cppVar_3334;
	bool cppVar_3335;
	BIT_VEC cppVar_3338;
	BIT_VEC cppVar_3339;
	BIT_VEC cppVar_3340;
	bool cppVar_3341;
	BIT_VEC cppVar_3342;
	BIT_VEC cppVar_3343;
	BIT_VEC cppVar_3344;
	BIT_VEC cppVar_3345;
	BIT_VEC cppVar_3346;
	BIT_VEC cppVar_3347;
	BIT_VEC cppVar_3348;
	BIT_VEC cppVar_3349;
	BIT_VEC cppVar_3350;
	BIT_VEC cppVar_3337;
	BIT_VEC cppVar_3351;
	bool cppVar_3352;
	BIT_VEC cppVar_3355;
	BIT_VEC cppVar_3356;
	BIT_VEC cppVar_3357;
	bool cppVar_3358;
	BIT_VEC cppVar_3359;
	BIT_VEC cppVar_3360;
	BIT_VEC cppVar_3361;
	BIT_VEC cppVar_3362;
	BIT_VEC cppVar_3363;
	BIT_VEC cppVar_3364;
	BIT_VEC cppVar_3365;
	BIT_VEC cppVar_3366;
	BIT_VEC cppVar_3367;
	BIT_VEC cppVar_3354;
	BIT_VEC cppVar_3368;
	bool cppVar_3369;
	BIT_VEC cppVar_3370;
	BIT_VEC cppVar_3353;
	BIT_VEC cppVar_3336;
	BIT_VEC cppVar_3319;
	BIT_VEC cppVar_3302;
	BIT_VEC cppVar_3285;
	BIT_VEC cppVar_3268;
	BIT_VEC cppVar_3251;
	BIT_VEC cppVar_3234;
	BIT_VEC cppVar_3217;
	BIT_VEC cppVar_3200;
	BIT_VEC cppVar_3183;
	BIT_VEC cppVar_3166;
	BIT_VEC cppVar_3149;
	BIT_VEC cppVar_3132;
	BIT_VEC cppVar_3115;
	BIT_VEC cppVar_3098;
	BIT_VEC cppVar_3081;
	BIT_VEC cppVar_3064;
	BIT_VEC cppVar_3047;
	BIT_VEC cppVar_3030;
	BIT_VEC cppVar_3013;
	BIT_VEC cppVar_2980;
	BIT_VEC cppVar_3371;
	BIT_VEC cppVar_3372;
	BIT_VEC cppVar_3373;
	BIT_VEC cppVar_3374;
	BIT_VEC cppVar_3375;
	BIT_VEC cppVar_3376;
	BIT_VEC cppVar_3377;
	BIT_VEC cppVar_3378;
	BIT_VEC cppVar_3379;
	BIT_VEC cppVar_2952;
	BIT_VEC cppVar_3381;
	BIT_VEC cppVar_3382;
	bool cppVar_3383;
	BIT_VEC cppVar_3385;
	BIT_VEC cppVar_3386;
	BIT_VEC cppVar_3387;
	BIT_VEC cppVar_3388;
	bool cppVar_3389;
	BIT_VEC cppVar_3390;
	BIT_VEC cppVar_3384;
	BIT_VEC cppVar_3392;
	BIT_VEC cppVar_3393;
	bool cppVar_3394;
	BIT_VEC cppVar_3395;
	BIT_VEC cppVar_3396;
	bool cppVar_3397;
	bool cppVar_3398;
	BIT_VEC cppVar_3400;
	BIT_VEC cppVar_3401;
	BIT_VEC cppVar_3402;
	BIT_VEC cppVar_3403;
	bool cppVar_3404;
	BIT_VEC cppVar_3399;
	BIT_VEC cppVar_3406;
	BIT_VEC cppVar_3407;
	bool cppVar_3408;
	BIT_VEC cppVar_3411;
	BIT_VEC cppVar_3412;
	BIT_VEC cppVar_3413;
	BIT_VEC cppVar_3414;
	BIT_VEC cppVar_3415;
	bool cppVar_3416;
	BIT_VEC cppVar_3417;
	BIT_VEC cppVar_3418;
	BIT_VEC cppVar_3419;
	BIT_VEC cppVar_3420;
	BIT_VEC cppVar_3421;
	BIT_VEC cppVar_3422;
	BIT_VEC cppVar_3423;
	BIT_VEC cppVar_3424;
	BIT_VEC cppVar_3425;
	BIT_VEC cppVar_3426;
	BIT_VEC cppVar_3427;
	BIT_VEC cppVar_3410;
	BIT_VEC cppVar_3428;
	bool cppVar_3429;
	BIT_VEC cppVar_3430;
	BIT_VEC cppVar_3431;
	BIT_VEC cppVar_3432;
	BIT_VEC cppVar_3433;
	BIT_VEC cppVar_3434;
	BIT_VEC cppVar_3435;
	BIT_VEC cppVar_3436;
	BIT_VEC cppVar_3439;
	BIT_VEC cppVar_3440;
	BIT_VEC cppVar_3441;
	bool cppVar_3442;
	BIT_VEC cppVar_3443;
	BIT_VEC cppVar_3444;
	BIT_VEC cppVar_3445;
	BIT_VEC cppVar_3446;
	BIT_VEC cppVar_3447;
	BIT_VEC cppVar_3448;
	BIT_VEC cppVar_3449;
	BIT_VEC cppVar_3450;
	BIT_VEC cppVar_3451;
	BIT_VEC cppVar_3438;
	BIT_VEC cppVar_3452;
	BIT_VEC cppVar_3453;
	bool cppVar_3454;
	BIT_VEC cppVar_3456;
	BIT_VEC cppVar_3457;
	BIT_VEC cppVar_3458;
	bool cppVar_3459;
	BIT_VEC cppVar_3460;
	BIT_VEC cppVar_3461;
	BIT_VEC cppVar_3462;
	BIT_VEC cppVar_3463;
	BIT_VEC cppVar_3464;
	BIT_VEC cppVar_3465;
	BIT_VEC cppVar_3466;
	BIT_VEC cppVar_3467;
	BIT_VEC cppVar_3468;
	BIT_VEC cppVar_3455;
	BIT_VEC cppVar_3469;
	BIT_VEC cppVar_3472;
	BIT_VEC cppVar_3473;
	BIT_VEC cppVar_3474;
	bool cppVar_3475;
	BIT_VEC cppVar_3476;
	BIT_VEC cppVar_3477;
	BIT_VEC cppVar_3478;
	BIT_VEC cppVar_3479;
	BIT_VEC cppVar_3480;
	BIT_VEC cppVar_3481;
	BIT_VEC cppVar_3482;
	BIT_VEC cppVar_3483;
	BIT_VEC cppVar_3484;
	BIT_VEC cppVar_3471;
	BIT_VEC cppVar_3485;
	bool cppVar_3486;
	BIT_VEC cppVar_3489;
	BIT_VEC cppVar_3490;
	BIT_VEC cppVar_3491;
	bool cppVar_3492;
	BIT_VEC cppVar_3493;
	BIT_VEC cppVar_3494;
	BIT_VEC cppVar_3495;
	BIT_VEC cppVar_3496;
	BIT_VEC cppVar_3497;
	BIT_VEC cppVar_3498;
	BIT_VEC cppVar_3499;
	BIT_VEC cppVar_3500;
	BIT_VEC cppVar_3501;
	BIT_VEC cppVar_3488;
	BIT_VEC cppVar_3502;
	bool cppVar_3503;
	BIT_VEC cppVar_3506;
	BIT_VEC cppVar_3507;
	BIT_VEC cppVar_3508;
	bool cppVar_3509;
	BIT_VEC cppVar_3510;
	BIT_VEC cppVar_3511;
	BIT_VEC cppVar_3512;
	BIT_VEC cppVar_3513;
	BIT_VEC cppVar_3514;
	BIT_VEC cppVar_3515;
	BIT_VEC cppVar_3516;
	BIT_VEC cppVar_3517;
	BIT_VEC cppVar_3518;
	BIT_VEC cppVar_3505;
	BIT_VEC cppVar_3519;
	bool cppVar_3520;
	BIT_VEC cppVar_3523;
	BIT_VEC cppVar_3524;
	BIT_VEC cppVar_3525;
	bool cppVar_3526;
	BIT_VEC cppVar_3527;
	BIT_VEC cppVar_3528;
	BIT_VEC cppVar_3529;
	BIT_VEC cppVar_3530;
	BIT_VEC cppVar_3531;
	BIT_VEC cppVar_3532;
	BIT_VEC cppVar_3533;
	BIT_VEC cppVar_3534;
	BIT_VEC cppVar_3535;
	BIT_VEC cppVar_3522;
	BIT_VEC cppVar_3536;
	bool cppVar_3537;
	BIT_VEC cppVar_3540;
	BIT_VEC cppVar_3541;
	BIT_VEC cppVar_3542;
	bool cppVar_3543;
	BIT_VEC cppVar_3544;
	BIT_VEC cppVar_3545;
	BIT_VEC cppVar_3546;
	BIT_VEC cppVar_3547;
	BIT_VEC cppVar_3548;
	BIT_VEC cppVar_3549;
	BIT_VEC cppVar_3550;
	BIT_VEC cppVar_3551;
	BIT_VEC cppVar_3552;
	BIT_VEC cppVar_3539;
	BIT_VEC cppVar_3553;
	bool cppVar_3554;
	BIT_VEC cppVar_3557;
	BIT_VEC cppVar_3558;
	BIT_VEC cppVar_3559;
	bool cppVar_3560;
	BIT_VEC cppVar_3561;
	BIT_VEC cppVar_3562;
	BIT_VEC cppVar_3563;
	BIT_VEC cppVar_3564;
	BIT_VEC cppVar_3565;
	BIT_VEC cppVar_3566;
	BIT_VEC cppVar_3567;
	BIT_VEC cppVar_3568;
	BIT_VEC cppVar_3569;
	BIT_VEC cppVar_3556;
	BIT_VEC cppVar_3570;
	bool cppVar_3571;
	BIT_VEC cppVar_3574;
	BIT_VEC cppVar_3575;
	BIT_VEC cppVar_3576;
	bool cppVar_3577;
	BIT_VEC cppVar_3578;
	BIT_VEC cppVar_3579;
	BIT_VEC cppVar_3580;
	BIT_VEC cppVar_3581;
	BIT_VEC cppVar_3582;
	BIT_VEC cppVar_3583;
	BIT_VEC cppVar_3584;
	BIT_VEC cppVar_3585;
	BIT_VEC cppVar_3586;
	BIT_VEC cppVar_3573;
	BIT_VEC cppVar_3587;
	bool cppVar_3588;
	BIT_VEC cppVar_3591;
	BIT_VEC cppVar_3592;
	BIT_VEC cppVar_3593;
	bool cppVar_3594;
	BIT_VEC cppVar_3595;
	BIT_VEC cppVar_3596;
	BIT_VEC cppVar_3597;
	BIT_VEC cppVar_3598;
	BIT_VEC cppVar_3599;
	BIT_VEC cppVar_3600;
	BIT_VEC cppVar_3601;
	BIT_VEC cppVar_3602;
	BIT_VEC cppVar_3603;
	BIT_VEC cppVar_3590;
	BIT_VEC cppVar_3604;
	bool cppVar_3605;
	BIT_VEC cppVar_3608;
	BIT_VEC cppVar_3609;
	BIT_VEC cppVar_3610;
	bool cppVar_3611;
	BIT_VEC cppVar_3612;
	BIT_VEC cppVar_3613;
	BIT_VEC cppVar_3614;
	BIT_VEC cppVar_3615;
	BIT_VEC cppVar_3616;
	BIT_VEC cppVar_3617;
	BIT_VEC cppVar_3618;
	BIT_VEC cppVar_3619;
	BIT_VEC cppVar_3620;
	BIT_VEC cppVar_3607;
	BIT_VEC cppVar_3621;
	bool cppVar_3622;
	BIT_VEC cppVar_3625;
	BIT_VEC cppVar_3626;
	BIT_VEC cppVar_3627;
	bool cppVar_3628;
	BIT_VEC cppVar_3629;
	BIT_VEC cppVar_3630;
	BIT_VEC cppVar_3631;
	BIT_VEC cppVar_3632;
	BIT_VEC cppVar_3633;
	BIT_VEC cppVar_3634;
	BIT_VEC cppVar_3635;
	BIT_VEC cppVar_3636;
	BIT_VEC cppVar_3637;
	BIT_VEC cppVar_3624;
	BIT_VEC cppVar_3638;
	bool cppVar_3639;
	BIT_VEC cppVar_3642;
	BIT_VEC cppVar_3643;
	BIT_VEC cppVar_3644;
	bool cppVar_3645;
	BIT_VEC cppVar_3646;
	BIT_VEC cppVar_3647;
	BIT_VEC cppVar_3648;
	BIT_VEC cppVar_3649;
	BIT_VEC cppVar_3650;
	BIT_VEC cppVar_3651;
	BIT_VEC cppVar_3652;
	BIT_VEC cppVar_3653;
	BIT_VEC cppVar_3654;
	BIT_VEC cppVar_3641;
	BIT_VEC cppVar_3655;
	bool cppVar_3656;
	BIT_VEC cppVar_3659;
	BIT_VEC cppVar_3660;
	BIT_VEC cppVar_3661;
	bool cppVar_3662;
	BIT_VEC cppVar_3663;
	BIT_VEC cppVar_3664;
	BIT_VEC cppVar_3665;
	BIT_VEC cppVar_3666;
	BIT_VEC cppVar_3667;
	BIT_VEC cppVar_3668;
	BIT_VEC cppVar_3669;
	BIT_VEC cppVar_3670;
	BIT_VEC cppVar_3671;
	BIT_VEC cppVar_3658;
	BIT_VEC cppVar_3672;
	bool cppVar_3673;
	BIT_VEC cppVar_3676;
	BIT_VEC cppVar_3677;
	BIT_VEC cppVar_3678;
	bool cppVar_3679;
	BIT_VEC cppVar_3680;
	BIT_VEC cppVar_3681;
	BIT_VEC cppVar_3682;
	BIT_VEC cppVar_3683;
	BIT_VEC cppVar_3684;
	BIT_VEC cppVar_3685;
	BIT_VEC cppVar_3686;
	BIT_VEC cppVar_3687;
	BIT_VEC cppVar_3688;
	BIT_VEC cppVar_3675;
	BIT_VEC cppVar_3689;
	bool cppVar_3690;
	BIT_VEC cppVar_3693;
	BIT_VEC cppVar_3694;
	BIT_VEC cppVar_3695;
	bool cppVar_3696;
	BIT_VEC cppVar_3697;
	BIT_VEC cppVar_3698;
	BIT_VEC cppVar_3699;
	BIT_VEC cppVar_3700;
	BIT_VEC cppVar_3701;
	BIT_VEC cppVar_3702;
	BIT_VEC cppVar_3703;
	BIT_VEC cppVar_3704;
	BIT_VEC cppVar_3705;
	BIT_VEC cppVar_3692;
	BIT_VEC cppVar_3706;
	bool cppVar_3707;
	BIT_VEC cppVar_3710;
	BIT_VEC cppVar_3711;
	BIT_VEC cppVar_3712;
	bool cppVar_3713;
	BIT_VEC cppVar_3714;
	BIT_VEC cppVar_3715;
	BIT_VEC cppVar_3716;
	BIT_VEC cppVar_3717;
	BIT_VEC cppVar_3718;
	BIT_VEC cppVar_3719;
	BIT_VEC cppVar_3720;
	BIT_VEC cppVar_3721;
	BIT_VEC cppVar_3722;
	BIT_VEC cppVar_3709;
	BIT_VEC cppVar_3723;
	bool cppVar_3724;
	BIT_VEC cppVar_3727;
	BIT_VEC cppVar_3728;
	BIT_VEC cppVar_3729;
	bool cppVar_3730;
	BIT_VEC cppVar_3731;
	BIT_VEC cppVar_3732;
	BIT_VEC cppVar_3733;
	BIT_VEC cppVar_3734;
	BIT_VEC cppVar_3735;
	BIT_VEC cppVar_3736;
	BIT_VEC cppVar_3737;
	BIT_VEC cppVar_3738;
	BIT_VEC cppVar_3739;
	BIT_VEC cppVar_3726;
	BIT_VEC cppVar_3740;
	bool cppVar_3741;
	BIT_VEC cppVar_3744;
	BIT_VEC cppVar_3745;
	BIT_VEC cppVar_3746;
	bool cppVar_3747;
	BIT_VEC cppVar_3748;
	BIT_VEC cppVar_3749;
	BIT_VEC cppVar_3750;
	BIT_VEC cppVar_3751;
	BIT_VEC cppVar_3752;
	BIT_VEC cppVar_3753;
	BIT_VEC cppVar_3754;
	BIT_VEC cppVar_3755;
	BIT_VEC cppVar_3756;
	BIT_VEC cppVar_3743;
	BIT_VEC cppVar_3757;
	bool cppVar_3758;
	BIT_VEC cppVar_3761;
	BIT_VEC cppVar_3762;
	BIT_VEC cppVar_3763;
	bool cppVar_3764;
	BIT_VEC cppVar_3765;
	BIT_VEC cppVar_3766;
	BIT_VEC cppVar_3767;
	BIT_VEC cppVar_3768;
	BIT_VEC cppVar_3769;
	BIT_VEC cppVar_3770;
	BIT_VEC cppVar_3771;
	BIT_VEC cppVar_3772;
	BIT_VEC cppVar_3773;
	BIT_VEC cppVar_3760;
	BIT_VEC cppVar_3774;
	bool cppVar_3775;
	BIT_VEC cppVar_3778;
	BIT_VEC cppVar_3779;
	BIT_VEC cppVar_3780;
	bool cppVar_3781;
	BIT_VEC cppVar_3782;
	BIT_VEC cppVar_3783;
	BIT_VEC cppVar_3784;
	BIT_VEC cppVar_3785;
	BIT_VEC cppVar_3786;
	BIT_VEC cppVar_3787;
	BIT_VEC cppVar_3788;
	BIT_VEC cppVar_3789;
	BIT_VEC cppVar_3790;
	BIT_VEC cppVar_3777;
	BIT_VEC cppVar_3791;
	bool cppVar_3792;
	BIT_VEC cppVar_3795;
	BIT_VEC cppVar_3796;
	BIT_VEC cppVar_3797;
	bool cppVar_3798;
	BIT_VEC cppVar_3799;
	BIT_VEC cppVar_3800;
	BIT_VEC cppVar_3801;
	BIT_VEC cppVar_3802;
	BIT_VEC cppVar_3803;
	BIT_VEC cppVar_3804;
	BIT_VEC cppVar_3805;
	BIT_VEC cppVar_3806;
	BIT_VEC cppVar_3807;
	BIT_VEC cppVar_3794;
	BIT_VEC cppVar_3808;
	bool cppVar_3809;
	BIT_VEC cppVar_3812;
	BIT_VEC cppVar_3813;
	BIT_VEC cppVar_3814;
	bool cppVar_3815;
	BIT_VEC cppVar_3816;
	BIT_VEC cppVar_3817;
	BIT_VEC cppVar_3818;
	BIT_VEC cppVar_3819;
	BIT_VEC cppVar_3820;
	BIT_VEC cppVar_3821;
	BIT_VEC cppVar_3822;
	BIT_VEC cppVar_3823;
	BIT_VEC cppVar_3824;
	BIT_VEC cppVar_3811;
	BIT_VEC cppVar_3825;
	bool cppVar_3826;
	BIT_VEC cppVar_3827;
	BIT_VEC cppVar_3810;
	BIT_VEC cppVar_3793;
	BIT_VEC cppVar_3776;
	BIT_VEC cppVar_3759;
	BIT_VEC cppVar_3742;
	BIT_VEC cppVar_3725;
	BIT_VEC cppVar_3708;
	BIT_VEC cppVar_3691;
	BIT_VEC cppVar_3674;
	BIT_VEC cppVar_3657;
	BIT_VEC cppVar_3640;
	BIT_VEC cppVar_3623;
	BIT_VEC cppVar_3606;
	BIT_VEC cppVar_3589;
	BIT_VEC cppVar_3572;
	BIT_VEC cppVar_3555;
	BIT_VEC cppVar_3538;
	BIT_VEC cppVar_3521;
	BIT_VEC cppVar_3504;
	BIT_VEC cppVar_3487;
	BIT_VEC cppVar_3470;
	BIT_VEC cppVar_3437;
	BIT_VEC cppVar_3828;
	BIT_VEC cppVar_3831;
	BIT_VEC cppVar_3832;
	BIT_VEC cppVar_3833;
	BIT_VEC cppVar_3834;
	bool cppVar_3835;
	BIT_VEC cppVar_3836;
	BIT_VEC cppVar_3837;
	BIT_VEC cppVar_3838;
	BIT_VEC cppVar_3839;
	BIT_VEC cppVar_3840;
	BIT_VEC cppVar_3841;
	BIT_VEC cppVar_3842;
	BIT_VEC cppVar_3843;
	BIT_VEC cppVar_3844;
	BIT_VEC cppVar_3845;
	BIT_VEC cppVar_3846;
	BIT_VEC cppVar_3830;
	BIT_VEC cppVar_3847;
	BIT_VEC cppVar_3848;
	bool cppVar_3849;
	BIT_VEC cppVar_3851;
	BIT_VEC cppVar_3852;
	BIT_VEC cppVar_3853;
	bool cppVar_3854;
	BIT_VEC cppVar_3855;
	BIT_VEC cppVar_3856;
	BIT_VEC cppVar_3857;
	BIT_VEC cppVar_3858;
	BIT_VEC cppVar_3859;
	BIT_VEC cppVar_3860;
	BIT_VEC cppVar_3861;
	BIT_VEC cppVar_3862;
	BIT_VEC cppVar_3863;
	BIT_VEC cppVar_3850;
	BIT_VEC cppVar_3864;
	BIT_VEC cppVar_3867;
	BIT_VEC cppVar_3868;
	BIT_VEC cppVar_3869;
	bool cppVar_3870;
	BIT_VEC cppVar_3871;
	BIT_VEC cppVar_3872;
	BIT_VEC cppVar_3873;
	BIT_VEC cppVar_3874;
	BIT_VEC cppVar_3875;
	BIT_VEC cppVar_3876;
	BIT_VEC cppVar_3877;
	BIT_VEC cppVar_3878;
	BIT_VEC cppVar_3879;
	BIT_VEC cppVar_3866;
	BIT_VEC cppVar_3880;
	bool cppVar_3881;
	BIT_VEC cppVar_3884;
	BIT_VEC cppVar_3885;
	BIT_VEC cppVar_3886;
	bool cppVar_3887;
	BIT_VEC cppVar_3888;
	BIT_VEC cppVar_3889;
	BIT_VEC cppVar_3890;
	BIT_VEC cppVar_3891;
	BIT_VEC cppVar_3892;
	BIT_VEC cppVar_3893;
	BIT_VEC cppVar_3894;
	BIT_VEC cppVar_3895;
	BIT_VEC cppVar_3896;
	BIT_VEC cppVar_3883;
	BIT_VEC cppVar_3897;
	bool cppVar_3898;
	BIT_VEC cppVar_3901;
	BIT_VEC cppVar_3902;
	BIT_VEC cppVar_3903;
	bool cppVar_3904;
	BIT_VEC cppVar_3905;
	BIT_VEC cppVar_3906;
	BIT_VEC cppVar_3907;
	BIT_VEC cppVar_3908;
	BIT_VEC cppVar_3909;
	BIT_VEC cppVar_3910;
	BIT_VEC cppVar_3911;
	BIT_VEC cppVar_3912;
	BIT_VEC cppVar_3913;
	BIT_VEC cppVar_3900;
	BIT_VEC cppVar_3914;
	bool cppVar_3915;
	BIT_VEC cppVar_3918;
	BIT_VEC cppVar_3919;
	BIT_VEC cppVar_3920;
	bool cppVar_3921;
	BIT_VEC cppVar_3922;
	BIT_VEC cppVar_3923;
	BIT_VEC cppVar_3924;
	BIT_VEC cppVar_3925;
	BIT_VEC cppVar_3926;
	BIT_VEC cppVar_3927;
	BIT_VEC cppVar_3928;
	BIT_VEC cppVar_3929;
	BIT_VEC cppVar_3930;
	BIT_VEC cppVar_3917;
	BIT_VEC cppVar_3931;
	bool cppVar_3932;
	BIT_VEC cppVar_3935;
	BIT_VEC cppVar_3936;
	BIT_VEC cppVar_3937;
	bool cppVar_3938;
	BIT_VEC cppVar_3939;
	BIT_VEC cppVar_3940;
	BIT_VEC cppVar_3941;
	BIT_VEC cppVar_3942;
	BIT_VEC cppVar_3943;
	BIT_VEC cppVar_3944;
	BIT_VEC cppVar_3945;
	BIT_VEC cppVar_3946;
	BIT_VEC cppVar_3947;
	BIT_VEC cppVar_3934;
	BIT_VEC cppVar_3948;
	bool cppVar_3949;
	BIT_VEC cppVar_3952;
	BIT_VEC cppVar_3953;
	BIT_VEC cppVar_3954;
	bool cppVar_3955;
	BIT_VEC cppVar_3956;
	BIT_VEC cppVar_3957;
	BIT_VEC cppVar_3958;
	BIT_VEC cppVar_3959;
	BIT_VEC cppVar_3960;
	BIT_VEC cppVar_3961;
	BIT_VEC cppVar_3962;
	BIT_VEC cppVar_3963;
	BIT_VEC cppVar_3964;
	BIT_VEC cppVar_3951;
	BIT_VEC cppVar_3965;
	bool cppVar_3966;
	BIT_VEC cppVar_3969;
	BIT_VEC cppVar_3970;
	BIT_VEC cppVar_3971;
	bool cppVar_3972;
	BIT_VEC cppVar_3973;
	BIT_VEC cppVar_3974;
	BIT_VEC cppVar_3975;
	BIT_VEC cppVar_3976;
	BIT_VEC cppVar_3977;
	BIT_VEC cppVar_3978;
	BIT_VEC cppVar_3979;
	BIT_VEC cppVar_3980;
	BIT_VEC cppVar_3981;
	BIT_VEC cppVar_3968;
	BIT_VEC cppVar_3982;
	bool cppVar_3983;
	BIT_VEC cppVar_3986;
	BIT_VEC cppVar_3987;
	BIT_VEC cppVar_3988;
	bool cppVar_3989;
	BIT_VEC cppVar_3990;
	BIT_VEC cppVar_3991;
	BIT_VEC cppVar_3992;
	BIT_VEC cppVar_3993;
	BIT_VEC cppVar_3994;
	BIT_VEC cppVar_3995;
	BIT_VEC cppVar_3996;
	BIT_VEC cppVar_3997;
	BIT_VEC cppVar_3998;
	BIT_VEC cppVar_3985;
	BIT_VEC cppVar_3999;
	bool cppVar_4000;
	BIT_VEC cppVar_4003;
	BIT_VEC cppVar_4004;
	BIT_VEC cppVar_4005;
	bool cppVar_4006;
	BIT_VEC cppVar_4007;
	BIT_VEC cppVar_4008;
	BIT_VEC cppVar_4009;
	BIT_VEC cppVar_4010;
	BIT_VEC cppVar_4011;
	BIT_VEC cppVar_4012;
	BIT_VEC cppVar_4013;
	BIT_VEC cppVar_4014;
	BIT_VEC cppVar_4015;
	BIT_VEC cppVar_4002;
	BIT_VEC cppVar_4016;
	bool cppVar_4017;
	BIT_VEC cppVar_4020;
	BIT_VEC cppVar_4021;
	BIT_VEC cppVar_4022;
	bool cppVar_4023;
	BIT_VEC cppVar_4024;
	BIT_VEC cppVar_4025;
	BIT_VEC cppVar_4026;
	BIT_VEC cppVar_4027;
	BIT_VEC cppVar_4028;
	BIT_VEC cppVar_4029;
	BIT_VEC cppVar_4030;
	BIT_VEC cppVar_4031;
	BIT_VEC cppVar_4032;
	BIT_VEC cppVar_4019;
	BIT_VEC cppVar_4033;
	bool cppVar_4034;
	BIT_VEC cppVar_4037;
	BIT_VEC cppVar_4038;
	BIT_VEC cppVar_4039;
	bool cppVar_4040;
	BIT_VEC cppVar_4041;
	BIT_VEC cppVar_4042;
	BIT_VEC cppVar_4043;
	BIT_VEC cppVar_4044;
	BIT_VEC cppVar_4045;
	BIT_VEC cppVar_4046;
	BIT_VEC cppVar_4047;
	BIT_VEC cppVar_4048;
	BIT_VEC cppVar_4049;
	BIT_VEC cppVar_4036;
	BIT_VEC cppVar_4050;
	bool cppVar_4051;
	BIT_VEC cppVar_4054;
	BIT_VEC cppVar_4055;
	BIT_VEC cppVar_4056;
	bool cppVar_4057;
	BIT_VEC cppVar_4058;
	BIT_VEC cppVar_4059;
	BIT_VEC cppVar_4060;
	BIT_VEC cppVar_4061;
	BIT_VEC cppVar_4062;
	BIT_VEC cppVar_4063;
	BIT_VEC cppVar_4064;
	BIT_VEC cppVar_4065;
	BIT_VEC cppVar_4066;
	BIT_VEC cppVar_4053;
	BIT_VEC cppVar_4067;
	bool cppVar_4068;
	BIT_VEC cppVar_4071;
	BIT_VEC cppVar_4072;
	BIT_VEC cppVar_4073;
	bool cppVar_4074;
	BIT_VEC cppVar_4075;
	BIT_VEC cppVar_4076;
	BIT_VEC cppVar_4077;
	BIT_VEC cppVar_4078;
	BIT_VEC cppVar_4079;
	BIT_VEC cppVar_4080;
	BIT_VEC cppVar_4081;
	BIT_VEC cppVar_4082;
	BIT_VEC cppVar_4083;
	BIT_VEC cppVar_4070;
	BIT_VEC cppVar_4084;
	bool cppVar_4085;
	BIT_VEC cppVar_4088;
	BIT_VEC cppVar_4089;
	BIT_VEC cppVar_4090;
	bool cppVar_4091;
	BIT_VEC cppVar_4092;
	BIT_VEC cppVar_4093;
	BIT_VEC cppVar_4094;
	BIT_VEC cppVar_4095;
	BIT_VEC cppVar_4096;
	BIT_VEC cppVar_4097;
	BIT_VEC cppVar_4098;
	BIT_VEC cppVar_4099;
	BIT_VEC cppVar_4100;
	BIT_VEC cppVar_4087;
	BIT_VEC cppVar_4101;
	bool cppVar_4102;
	BIT_VEC cppVar_4105;
	BIT_VEC cppVar_4106;
	BIT_VEC cppVar_4107;
	bool cppVar_4108;
	BIT_VEC cppVar_4109;
	BIT_VEC cppVar_4110;
	BIT_VEC cppVar_4111;
	BIT_VEC cppVar_4112;
	BIT_VEC cppVar_4113;
	BIT_VEC cppVar_4114;
	BIT_VEC cppVar_4115;
	BIT_VEC cppVar_4116;
	BIT_VEC cppVar_4117;
	BIT_VEC cppVar_4104;
	BIT_VEC cppVar_4118;
	bool cppVar_4119;
	BIT_VEC cppVar_4122;
	BIT_VEC cppVar_4123;
	BIT_VEC cppVar_4124;
	bool cppVar_4125;
	BIT_VEC cppVar_4126;
	BIT_VEC cppVar_4127;
	BIT_VEC cppVar_4128;
	BIT_VEC cppVar_4129;
	BIT_VEC cppVar_4130;
	BIT_VEC cppVar_4131;
	BIT_VEC cppVar_4132;
	BIT_VEC cppVar_4133;
	BIT_VEC cppVar_4134;
	BIT_VEC cppVar_4121;
	BIT_VEC cppVar_4135;
	bool cppVar_4136;
	BIT_VEC cppVar_4139;
	BIT_VEC cppVar_4140;
	BIT_VEC cppVar_4141;
	bool cppVar_4142;
	BIT_VEC cppVar_4143;
	BIT_VEC cppVar_4144;
	BIT_VEC cppVar_4145;
	BIT_VEC cppVar_4146;
	BIT_VEC cppVar_4147;
	BIT_VEC cppVar_4148;
	BIT_VEC cppVar_4149;
	BIT_VEC cppVar_4150;
	BIT_VEC cppVar_4151;
	BIT_VEC cppVar_4138;
	BIT_VEC cppVar_4152;
	bool cppVar_4153;
	BIT_VEC cppVar_4156;
	BIT_VEC cppVar_4157;
	BIT_VEC cppVar_4158;
	bool cppVar_4159;
	BIT_VEC cppVar_4160;
	BIT_VEC cppVar_4161;
	BIT_VEC cppVar_4162;
	BIT_VEC cppVar_4163;
	BIT_VEC cppVar_4164;
	BIT_VEC cppVar_4165;
	BIT_VEC cppVar_4166;
	BIT_VEC cppVar_4167;
	BIT_VEC cppVar_4168;
	BIT_VEC cppVar_4155;
	BIT_VEC cppVar_4169;
	bool cppVar_4170;
	BIT_VEC cppVar_4173;
	BIT_VEC cppVar_4174;
	BIT_VEC cppVar_4175;
	bool cppVar_4176;
	BIT_VEC cppVar_4177;
	BIT_VEC cppVar_4178;
	BIT_VEC cppVar_4179;
	BIT_VEC cppVar_4180;
	BIT_VEC cppVar_4181;
	BIT_VEC cppVar_4182;
	BIT_VEC cppVar_4183;
	BIT_VEC cppVar_4184;
	BIT_VEC cppVar_4185;
	BIT_VEC cppVar_4172;
	BIT_VEC cppVar_4186;
	bool cppVar_4187;
	BIT_VEC cppVar_4190;
	BIT_VEC cppVar_4191;
	BIT_VEC cppVar_4192;
	bool cppVar_4193;
	BIT_VEC cppVar_4194;
	BIT_VEC cppVar_4195;
	BIT_VEC cppVar_4196;
	BIT_VEC cppVar_4197;
	BIT_VEC cppVar_4198;
	BIT_VEC cppVar_4199;
	BIT_VEC cppVar_4200;
	BIT_VEC cppVar_4201;
	BIT_VEC cppVar_4202;
	BIT_VEC cppVar_4189;
	BIT_VEC cppVar_4203;
	bool cppVar_4204;
	BIT_VEC cppVar_4207;
	BIT_VEC cppVar_4208;
	BIT_VEC cppVar_4209;
	bool cppVar_4210;
	BIT_VEC cppVar_4211;
	BIT_VEC cppVar_4212;
	BIT_VEC cppVar_4213;
	BIT_VEC cppVar_4214;
	BIT_VEC cppVar_4215;
	BIT_VEC cppVar_4216;
	BIT_VEC cppVar_4217;
	BIT_VEC cppVar_4218;
	BIT_VEC cppVar_4219;
	BIT_VEC cppVar_4206;
	BIT_VEC cppVar_4220;
	bool cppVar_4221;
	BIT_VEC cppVar_4222;
	BIT_VEC cppVar_4205;
	BIT_VEC cppVar_4188;
	BIT_VEC cppVar_4171;
	BIT_VEC cppVar_4154;
	BIT_VEC cppVar_4137;
	BIT_VEC cppVar_4120;
	BIT_VEC cppVar_4103;
	BIT_VEC cppVar_4086;
	BIT_VEC cppVar_4069;
	BIT_VEC cppVar_4052;
	BIT_VEC cppVar_4035;
	BIT_VEC cppVar_4018;
	BIT_VEC cppVar_4001;
	BIT_VEC cppVar_3984;
	BIT_VEC cppVar_3967;
	BIT_VEC cppVar_3950;
	BIT_VEC cppVar_3933;
	BIT_VEC cppVar_3916;
	BIT_VEC cppVar_3899;
	BIT_VEC cppVar_3882;
	BIT_VEC cppVar_3865;
	BIT_VEC cppVar_3829;
	BIT_VEC cppVar_4223;
	BIT_VEC cppVar_4224;
	BIT_VEC cppVar_4225;
	BIT_VEC cppVar_4226;
	BIT_VEC cppVar_4227;
	BIT_VEC cppVar_4228;
	BIT_VEC cppVar_4229;
	BIT_VEC cppVar_4230;
	BIT_VEC cppVar_4231;
	BIT_VEC cppVar_4232;
	BIT_VEC cppVar_4233;
	BIT_VEC cppVar_4234;
	BIT_VEC cppVar_3409;
	BIT_VEC cppVar_4236;
	BIT_VEC cppVar_4237;
	bool cppVar_4238;
	BIT_VEC cppVar_4239;
	BIT_VEC cppVar_4240;
	BIT_VEC cppVar_4241;
	BIT_VEC cppVar_4242;
	BIT_VEC cppVar_4244;
	BIT_VEC cppVar_4245;
	bool cppVar_4246;
	BIT_VEC cppVar_4249;
	BIT_VEC cppVar_4250;
	BIT_VEC cppVar_4251;
	BIT_VEC cppVar_4252;
	BIT_VEC cppVar_4253;
	bool cppVar_4254;
	BIT_VEC cppVar_4255;
	BIT_VEC cppVar_4256;
	BIT_VEC cppVar_4257;
	BIT_VEC cppVar_4258;
	BIT_VEC cppVar_4259;
	BIT_VEC cppVar_4260;
	BIT_VEC cppVar_4261;
	BIT_VEC cppVar_4262;
	BIT_VEC cppVar_4263;
	BIT_VEC cppVar_4264;
	BIT_VEC cppVar_4265;
	BIT_VEC cppVar_4248;
	BIT_VEC cppVar_4266;
	bool cppVar_4267;
	BIT_VEC cppVar_4268;
	BIT_VEC cppVar_4269;
	BIT_VEC cppVar_4270;
	BIT_VEC cppVar_4271;
	BIT_VEC cppVar_4272;
	BIT_VEC cppVar_4273;
	BIT_VEC cppVar_4274;
	BIT_VEC cppVar_4277;
	BIT_VEC cppVar_4278;
	BIT_VEC cppVar_4279;
	bool cppVar_4280;
	BIT_VEC cppVar_4281;
	BIT_VEC cppVar_4282;
	BIT_VEC cppVar_4283;
	BIT_VEC cppVar_4284;
	BIT_VEC cppVar_4285;
	BIT_VEC cppVar_4286;
	BIT_VEC cppVar_4287;
	BIT_VEC cppVar_4288;
	BIT_VEC cppVar_4289;
	BIT_VEC cppVar_4276;
	BIT_VEC cppVar_4290;
	BIT_VEC cppVar_4291;
	bool cppVar_4292;
	BIT_VEC cppVar_4294;
	BIT_VEC cppVar_4295;
	BIT_VEC cppVar_4296;
	bool cppVar_4297;
	BIT_VEC cppVar_4298;
	BIT_VEC cppVar_4299;
	BIT_VEC cppVar_4300;
	BIT_VEC cppVar_4301;
	BIT_VEC cppVar_4302;
	BIT_VEC cppVar_4303;
	BIT_VEC cppVar_4304;
	BIT_VEC cppVar_4305;
	BIT_VEC cppVar_4306;
	BIT_VEC cppVar_4293;
	BIT_VEC cppVar_4307;
	BIT_VEC cppVar_4310;
	BIT_VEC cppVar_4311;
	BIT_VEC cppVar_4312;
	bool cppVar_4313;
	BIT_VEC cppVar_4314;
	BIT_VEC cppVar_4315;
	BIT_VEC cppVar_4316;
	BIT_VEC cppVar_4317;
	BIT_VEC cppVar_4318;
	BIT_VEC cppVar_4319;
	BIT_VEC cppVar_4320;
	BIT_VEC cppVar_4321;
	BIT_VEC cppVar_4322;
	BIT_VEC cppVar_4309;
	BIT_VEC cppVar_4323;
	bool cppVar_4324;
	BIT_VEC cppVar_4327;
	BIT_VEC cppVar_4328;
	BIT_VEC cppVar_4329;
	bool cppVar_4330;
	BIT_VEC cppVar_4331;
	BIT_VEC cppVar_4332;
	BIT_VEC cppVar_4333;
	BIT_VEC cppVar_4334;
	BIT_VEC cppVar_4335;
	BIT_VEC cppVar_4336;
	BIT_VEC cppVar_4337;
	BIT_VEC cppVar_4338;
	BIT_VEC cppVar_4339;
	BIT_VEC cppVar_4326;
	BIT_VEC cppVar_4340;
	bool cppVar_4341;
	BIT_VEC cppVar_4344;
	BIT_VEC cppVar_4345;
	BIT_VEC cppVar_4346;
	bool cppVar_4347;
	BIT_VEC cppVar_4348;
	BIT_VEC cppVar_4349;
	BIT_VEC cppVar_4350;
	BIT_VEC cppVar_4351;
	BIT_VEC cppVar_4352;
	BIT_VEC cppVar_4353;
	BIT_VEC cppVar_4354;
	BIT_VEC cppVar_4355;
	BIT_VEC cppVar_4356;
	BIT_VEC cppVar_4343;
	BIT_VEC cppVar_4357;
	bool cppVar_4358;
	BIT_VEC cppVar_4361;
	BIT_VEC cppVar_4362;
	BIT_VEC cppVar_4363;
	bool cppVar_4364;
	BIT_VEC cppVar_4365;
	BIT_VEC cppVar_4366;
	BIT_VEC cppVar_4367;
	BIT_VEC cppVar_4368;
	BIT_VEC cppVar_4369;
	BIT_VEC cppVar_4370;
	BIT_VEC cppVar_4371;
	BIT_VEC cppVar_4372;
	BIT_VEC cppVar_4373;
	BIT_VEC cppVar_4360;
	BIT_VEC cppVar_4374;
	bool cppVar_4375;
	BIT_VEC cppVar_4378;
	BIT_VEC cppVar_4379;
	BIT_VEC cppVar_4380;
	bool cppVar_4381;
	BIT_VEC cppVar_4382;
	BIT_VEC cppVar_4383;
	BIT_VEC cppVar_4384;
	BIT_VEC cppVar_4385;
	BIT_VEC cppVar_4386;
	BIT_VEC cppVar_4387;
	BIT_VEC cppVar_4388;
	BIT_VEC cppVar_4389;
	BIT_VEC cppVar_4390;
	BIT_VEC cppVar_4377;
	BIT_VEC cppVar_4391;
	bool cppVar_4392;
	BIT_VEC cppVar_4395;
	BIT_VEC cppVar_4396;
	BIT_VEC cppVar_4397;
	bool cppVar_4398;
	BIT_VEC cppVar_4399;
	BIT_VEC cppVar_4400;
	BIT_VEC cppVar_4401;
	BIT_VEC cppVar_4402;
	BIT_VEC cppVar_4403;
	BIT_VEC cppVar_4404;
	BIT_VEC cppVar_4405;
	BIT_VEC cppVar_4406;
	BIT_VEC cppVar_4407;
	BIT_VEC cppVar_4394;
	BIT_VEC cppVar_4408;
	bool cppVar_4409;
	BIT_VEC cppVar_4412;
	BIT_VEC cppVar_4413;
	BIT_VEC cppVar_4414;
	bool cppVar_4415;
	BIT_VEC cppVar_4416;
	BIT_VEC cppVar_4417;
	BIT_VEC cppVar_4418;
	BIT_VEC cppVar_4419;
	BIT_VEC cppVar_4420;
	BIT_VEC cppVar_4421;
	BIT_VEC cppVar_4422;
	BIT_VEC cppVar_4423;
	BIT_VEC cppVar_4424;
	BIT_VEC cppVar_4411;
	BIT_VEC cppVar_4425;
	bool cppVar_4426;
	BIT_VEC cppVar_4429;
	BIT_VEC cppVar_4430;
	BIT_VEC cppVar_4431;
	bool cppVar_4432;
	BIT_VEC cppVar_4433;
	BIT_VEC cppVar_4434;
	BIT_VEC cppVar_4435;
	BIT_VEC cppVar_4436;
	BIT_VEC cppVar_4437;
	BIT_VEC cppVar_4438;
	BIT_VEC cppVar_4439;
	BIT_VEC cppVar_4440;
	BIT_VEC cppVar_4441;
	BIT_VEC cppVar_4428;
	BIT_VEC cppVar_4442;
	bool cppVar_4443;
	BIT_VEC cppVar_4446;
	BIT_VEC cppVar_4447;
	BIT_VEC cppVar_4448;
	bool cppVar_4449;
	BIT_VEC cppVar_4450;
	BIT_VEC cppVar_4451;
	BIT_VEC cppVar_4452;
	BIT_VEC cppVar_4453;
	BIT_VEC cppVar_4454;
	BIT_VEC cppVar_4455;
	BIT_VEC cppVar_4456;
	BIT_VEC cppVar_4457;
	BIT_VEC cppVar_4458;
	BIT_VEC cppVar_4445;
	BIT_VEC cppVar_4459;
	bool cppVar_4460;
	BIT_VEC cppVar_4463;
	BIT_VEC cppVar_4464;
	BIT_VEC cppVar_4465;
	bool cppVar_4466;
	BIT_VEC cppVar_4467;
	BIT_VEC cppVar_4468;
	BIT_VEC cppVar_4469;
	BIT_VEC cppVar_4470;
	BIT_VEC cppVar_4471;
	BIT_VEC cppVar_4472;
	BIT_VEC cppVar_4473;
	BIT_VEC cppVar_4474;
	BIT_VEC cppVar_4475;
	BIT_VEC cppVar_4462;
	BIT_VEC cppVar_4476;
	bool cppVar_4477;
	BIT_VEC cppVar_4480;
	BIT_VEC cppVar_4481;
	BIT_VEC cppVar_4482;
	bool cppVar_4483;
	BIT_VEC cppVar_4484;
	BIT_VEC cppVar_4485;
	BIT_VEC cppVar_4486;
	BIT_VEC cppVar_4487;
	BIT_VEC cppVar_4488;
	BIT_VEC cppVar_4489;
	BIT_VEC cppVar_4490;
	BIT_VEC cppVar_4491;
	BIT_VEC cppVar_4492;
	BIT_VEC cppVar_4479;
	BIT_VEC cppVar_4493;
	bool cppVar_4494;
	BIT_VEC cppVar_4497;
	BIT_VEC cppVar_4498;
	BIT_VEC cppVar_4499;
	bool cppVar_4500;
	BIT_VEC cppVar_4501;
	BIT_VEC cppVar_4502;
	BIT_VEC cppVar_4503;
	BIT_VEC cppVar_4504;
	BIT_VEC cppVar_4505;
	BIT_VEC cppVar_4506;
	BIT_VEC cppVar_4507;
	BIT_VEC cppVar_4508;
	BIT_VEC cppVar_4509;
	BIT_VEC cppVar_4496;
	BIT_VEC cppVar_4510;
	bool cppVar_4511;
	BIT_VEC cppVar_4514;
	BIT_VEC cppVar_4515;
	BIT_VEC cppVar_4516;
	bool cppVar_4517;
	BIT_VEC cppVar_4518;
	BIT_VEC cppVar_4519;
	BIT_VEC cppVar_4520;
	BIT_VEC cppVar_4521;
	BIT_VEC cppVar_4522;
	BIT_VEC cppVar_4523;
	BIT_VEC cppVar_4524;
	BIT_VEC cppVar_4525;
	BIT_VEC cppVar_4526;
	BIT_VEC cppVar_4513;
	BIT_VEC cppVar_4527;
	bool cppVar_4528;
	BIT_VEC cppVar_4531;
	BIT_VEC cppVar_4532;
	BIT_VEC cppVar_4533;
	bool cppVar_4534;
	BIT_VEC cppVar_4535;
	BIT_VEC cppVar_4536;
	BIT_VEC cppVar_4537;
	BIT_VEC cppVar_4538;
	BIT_VEC cppVar_4539;
	BIT_VEC cppVar_4540;
	BIT_VEC cppVar_4541;
	BIT_VEC cppVar_4542;
	BIT_VEC cppVar_4543;
	BIT_VEC cppVar_4530;
	BIT_VEC cppVar_4544;
	bool cppVar_4545;
	BIT_VEC cppVar_4548;
	BIT_VEC cppVar_4549;
	BIT_VEC cppVar_4550;
	bool cppVar_4551;
	BIT_VEC cppVar_4552;
	BIT_VEC cppVar_4553;
	BIT_VEC cppVar_4554;
	BIT_VEC cppVar_4555;
	BIT_VEC cppVar_4556;
	BIT_VEC cppVar_4557;
	BIT_VEC cppVar_4558;
	BIT_VEC cppVar_4559;
	BIT_VEC cppVar_4560;
	BIT_VEC cppVar_4547;
	BIT_VEC cppVar_4561;
	bool cppVar_4562;
	BIT_VEC cppVar_4565;
	BIT_VEC cppVar_4566;
	BIT_VEC cppVar_4567;
	bool cppVar_4568;
	BIT_VEC cppVar_4569;
	BIT_VEC cppVar_4570;
	BIT_VEC cppVar_4571;
	BIT_VEC cppVar_4572;
	BIT_VEC cppVar_4573;
	BIT_VEC cppVar_4574;
	BIT_VEC cppVar_4575;
	BIT_VEC cppVar_4576;
	BIT_VEC cppVar_4577;
	BIT_VEC cppVar_4564;
	BIT_VEC cppVar_4578;
	bool cppVar_4579;
	BIT_VEC cppVar_4582;
	BIT_VEC cppVar_4583;
	BIT_VEC cppVar_4584;
	bool cppVar_4585;
	BIT_VEC cppVar_4586;
	BIT_VEC cppVar_4587;
	BIT_VEC cppVar_4588;
	BIT_VEC cppVar_4589;
	BIT_VEC cppVar_4590;
	BIT_VEC cppVar_4591;
	BIT_VEC cppVar_4592;
	BIT_VEC cppVar_4593;
	BIT_VEC cppVar_4594;
	BIT_VEC cppVar_4581;
	BIT_VEC cppVar_4595;
	bool cppVar_4596;
	BIT_VEC cppVar_4599;
	BIT_VEC cppVar_4600;
	BIT_VEC cppVar_4601;
	bool cppVar_4602;
	BIT_VEC cppVar_4603;
	BIT_VEC cppVar_4604;
	BIT_VEC cppVar_4605;
	BIT_VEC cppVar_4606;
	BIT_VEC cppVar_4607;
	BIT_VEC cppVar_4608;
	BIT_VEC cppVar_4609;
	BIT_VEC cppVar_4610;
	BIT_VEC cppVar_4611;
	BIT_VEC cppVar_4598;
	BIT_VEC cppVar_4612;
	bool cppVar_4613;
	BIT_VEC cppVar_4616;
	BIT_VEC cppVar_4617;
	BIT_VEC cppVar_4618;
	bool cppVar_4619;
	BIT_VEC cppVar_4620;
	BIT_VEC cppVar_4621;
	BIT_VEC cppVar_4622;
	BIT_VEC cppVar_4623;
	BIT_VEC cppVar_4624;
	BIT_VEC cppVar_4625;
	BIT_VEC cppVar_4626;
	BIT_VEC cppVar_4627;
	BIT_VEC cppVar_4628;
	BIT_VEC cppVar_4615;
	BIT_VEC cppVar_4629;
	bool cppVar_4630;
	BIT_VEC cppVar_4633;
	BIT_VEC cppVar_4634;
	BIT_VEC cppVar_4635;
	bool cppVar_4636;
	BIT_VEC cppVar_4637;
	BIT_VEC cppVar_4638;
	BIT_VEC cppVar_4639;
	BIT_VEC cppVar_4640;
	BIT_VEC cppVar_4641;
	BIT_VEC cppVar_4642;
	BIT_VEC cppVar_4643;
	BIT_VEC cppVar_4644;
	BIT_VEC cppVar_4645;
	BIT_VEC cppVar_4632;
	BIT_VEC cppVar_4646;
	bool cppVar_4647;
	BIT_VEC cppVar_4650;
	BIT_VEC cppVar_4651;
	BIT_VEC cppVar_4652;
	bool cppVar_4653;
	BIT_VEC cppVar_4654;
	BIT_VEC cppVar_4655;
	BIT_VEC cppVar_4656;
	BIT_VEC cppVar_4657;
	BIT_VEC cppVar_4658;
	BIT_VEC cppVar_4659;
	BIT_VEC cppVar_4660;
	BIT_VEC cppVar_4661;
	BIT_VEC cppVar_4662;
	BIT_VEC cppVar_4649;
	BIT_VEC cppVar_4663;
	bool cppVar_4664;
	BIT_VEC cppVar_4665;
	BIT_VEC cppVar_4648;
	BIT_VEC cppVar_4631;
	BIT_VEC cppVar_4614;
	BIT_VEC cppVar_4597;
	BIT_VEC cppVar_4580;
	BIT_VEC cppVar_4563;
	BIT_VEC cppVar_4546;
	BIT_VEC cppVar_4529;
	BIT_VEC cppVar_4512;
	BIT_VEC cppVar_4495;
	BIT_VEC cppVar_4478;
	BIT_VEC cppVar_4461;
	BIT_VEC cppVar_4444;
	BIT_VEC cppVar_4427;
	BIT_VEC cppVar_4410;
	BIT_VEC cppVar_4393;
	BIT_VEC cppVar_4376;
	BIT_VEC cppVar_4359;
	BIT_VEC cppVar_4342;
	BIT_VEC cppVar_4325;
	BIT_VEC cppVar_4308;
	BIT_VEC cppVar_4275;
	BIT_VEC cppVar_4666;
	BIT_VEC cppVar_4667;
	BIT_VEC cppVar_4668;
	BIT_VEC cppVar_4669;
	BIT_VEC cppVar_4670;
	BIT_VEC cppVar_4671;
	BIT_VEC cppVar_4672;
	BIT_VEC cppVar_4673;
	BIT_VEC cppVar_4674;
	BIT_VEC cppVar_4247;
	BIT_VEC cppVar_4676;
	BIT_VEC cppVar_4677;
	bool cppVar_4678;
	BIT_VEC cppVar_4680;
	BIT_VEC cppVar_4681;
	BIT_VEC cppVar_4682;
	BIT_VEC cppVar_4683;
	bool cppVar_4684;
	BIT_VEC cppVar_4686;
	BIT_VEC cppVar_4687;
	BIT_VEC cppVar_4688;
	BIT_VEC cppVar_4689;
	BIT_VEC cppVar_4690;
	BIT_VEC cppVar_4691;
	BIT_VEC cppVar_4692;
	bool cppVar_4693;
	BIT_VEC cppVar_4694;
	BIT_VEC cppVar_4695;
	BIT_VEC cppVar_4696;
	BIT_VEC cppVar_4697;
	BIT_VEC cppVar_4699;
	BIT_VEC cppVar_4700;
	BIT_VEC cppVar_4701;
	BIT_VEC cppVar_4702;
	bool cppVar_4703;
	BIT_VEC cppVar_4705;
	BIT_VEC cppVar_4706;
	BIT_VEC cppVar_4707;
	BIT_VEC cppVar_4708;
	bool cppVar_4709;
	BIT_VEC cppVar_4711;
	BIT_VEC cppVar_4712;
	BIT_VEC cppVar_4713;
	BIT_VEC cppVar_4714;
	bool cppVar_4715;
	BIT_VEC cppVar_4717;
	BIT_VEC cppVar_4718;
	BIT_VEC cppVar_4719;
	BIT_VEC cppVar_4720;
	bool cppVar_4721;
	BIT_VEC cppVar_4723;
	BIT_VEC cppVar_4724;
	BIT_VEC cppVar_4725;
	BIT_VEC cppVar_4726;
	bool cppVar_4727;
	BIT_VEC cppVar_4729;
	BIT_VEC cppVar_4730;
	BIT_VEC cppVar_4731;
	BIT_VEC cppVar_4732;
	bool cppVar_4733;
	BIT_VEC cppVar_4735;
	BIT_VEC cppVar_4736;
	BIT_VEC cppVar_4737;
	BIT_VEC cppVar_4738;
	bool cppVar_4739;
	BIT_VEC cppVar_4741;
	BIT_VEC cppVar_4742;
	BIT_VEC cppVar_4743;
	BIT_VEC cppVar_4744;
	bool cppVar_4745;
	BIT_VEC cppVar_4747;
	BIT_VEC cppVar_4748;
	BIT_VEC cppVar_4749;
	BIT_VEC cppVar_4750;
	bool cppVar_4751;
	BIT_VEC cppVar_4753;
	BIT_VEC cppVar_4754;
	BIT_VEC cppVar_4755;
	BIT_VEC cppVar_4756;
	bool cppVar_4757;
	BIT_VEC cppVar_4759;
	BIT_VEC cppVar_4760;
	BIT_VEC cppVar_4761;
	BIT_VEC cppVar_4762;
	bool cppVar_4763;
	BIT_VEC cppVar_4765;
	BIT_VEC cppVar_4766;
	BIT_VEC cppVar_4767;
	BIT_VEC cppVar_4768;
	bool cppVar_4769;
	BIT_VEC cppVar_4771;
	BIT_VEC cppVar_4772;
	BIT_VEC cppVar_4773;
	BIT_VEC cppVar_4774;
	bool cppVar_4775;
	BIT_VEC cppVar_4777;
	BIT_VEC cppVar_4778;
	BIT_VEC cppVar_4779;
	BIT_VEC cppVar_4780;
	bool cppVar_4781;
	BIT_VEC cppVar_4783;
	BIT_VEC cppVar_4784;
	BIT_VEC cppVar_4785;
	BIT_VEC cppVar_4786;
	bool cppVar_4787;
	BIT_VEC cppVar_4789;
	BIT_VEC cppVar_4790;
	BIT_VEC cppVar_4791;
	BIT_VEC cppVar_4792;
	bool cppVar_4793;
	BIT_VEC cppVar_4795;
	BIT_VEC cppVar_4796;
	BIT_VEC cppVar_4797;
	BIT_VEC cppVar_4798;
	bool cppVar_4799;
	BIT_VEC cppVar_4801;
	BIT_VEC cppVar_4802;
	BIT_VEC cppVar_4803;
	BIT_VEC cppVar_4804;
	bool cppVar_4805;
	BIT_VEC cppVar_4807;
	BIT_VEC cppVar_4808;
	BIT_VEC cppVar_4809;
	BIT_VEC cppVar_4810;
	bool cppVar_4811;
	BIT_VEC cppVar_4813;
	BIT_VEC cppVar_4814;
	BIT_VEC cppVar_4815;
	BIT_VEC cppVar_4816;
	bool cppVar_4817;
	BIT_VEC cppVar_4819;
	BIT_VEC cppVar_4820;
	BIT_VEC cppVar_4821;
	BIT_VEC cppVar_4822;
	bool cppVar_4823;
	BIT_VEC cppVar_4824;
	BIT_VEC cppVar_4818;
	BIT_VEC cppVar_4812;
	BIT_VEC cppVar_4806;
	BIT_VEC cppVar_4800;
	BIT_VEC cppVar_4794;
	BIT_VEC cppVar_4788;
	BIT_VEC cppVar_4782;
	BIT_VEC cppVar_4776;
	BIT_VEC cppVar_4770;
	BIT_VEC cppVar_4764;
	BIT_VEC cppVar_4758;
	BIT_VEC cppVar_4752;
	BIT_VEC cppVar_4746;
	BIT_VEC cppVar_4740;
	BIT_VEC cppVar_4734;
	BIT_VEC cppVar_4728;
	BIT_VEC cppVar_4722;
	BIT_VEC cppVar_4716;
	BIT_VEC cppVar_4710;
	BIT_VEC cppVar_4704;
	BIT_VEC cppVar_4698;
	BIT_VEC cppVar_4685;
	BIT_VEC cppVar_4679;
	BIT_VEC cppVar_4826;
	BIT_VEC cppVar_4827;
	bool cppVar_4828;
	BIT_VEC cppVar_4830;
	BIT_VEC cppVar_4831;
	BIT_VEC cppVar_4832;
	BIT_VEC cppVar_4833;
	bool cppVar_4834;
	BIT_VEC cppVar_4836;
	BIT_VEC cppVar_4837;
	BIT_VEC cppVar_4838;
	BIT_VEC cppVar_4839;
	BIT_VEC cppVar_4840;
	BIT_VEC cppVar_4841;
	BIT_VEC cppVar_4842;
	bool cppVar_4843;
	BIT_VEC cppVar_4844;
	BIT_VEC cppVar_4845;
	BIT_VEC cppVar_4846;
	BIT_VEC cppVar_4847;
	BIT_VEC cppVar_4849;
	BIT_VEC cppVar_4850;
	BIT_VEC cppVar_4851;
	BIT_VEC cppVar_4852;
	bool cppVar_4853;
	BIT_VEC cppVar_4855;
	BIT_VEC cppVar_4856;
	BIT_VEC cppVar_4857;
	BIT_VEC cppVar_4858;
	bool cppVar_4859;
	BIT_VEC cppVar_4861;
	BIT_VEC cppVar_4862;
	BIT_VEC cppVar_4863;
	BIT_VEC cppVar_4864;
	bool cppVar_4865;
	BIT_VEC cppVar_4867;
	BIT_VEC cppVar_4868;
	BIT_VEC cppVar_4869;
	BIT_VEC cppVar_4870;
	bool cppVar_4871;
	BIT_VEC cppVar_4873;
	BIT_VEC cppVar_4874;
	BIT_VEC cppVar_4875;
	BIT_VEC cppVar_4876;
	bool cppVar_4877;
	BIT_VEC cppVar_4879;
	BIT_VEC cppVar_4880;
	BIT_VEC cppVar_4881;
	BIT_VEC cppVar_4882;
	bool cppVar_4883;
	BIT_VEC cppVar_4885;
	BIT_VEC cppVar_4886;
	BIT_VEC cppVar_4887;
	BIT_VEC cppVar_4888;
	bool cppVar_4889;
	BIT_VEC cppVar_4891;
	BIT_VEC cppVar_4892;
	BIT_VEC cppVar_4893;
	BIT_VEC cppVar_4894;
	bool cppVar_4895;
	BIT_VEC cppVar_4897;
	BIT_VEC cppVar_4898;
	BIT_VEC cppVar_4899;
	BIT_VEC cppVar_4900;
	bool cppVar_4901;
	BIT_VEC cppVar_4903;
	BIT_VEC cppVar_4904;
	BIT_VEC cppVar_4905;
	BIT_VEC cppVar_4906;
	bool cppVar_4907;
	BIT_VEC cppVar_4909;
	BIT_VEC cppVar_4910;
	BIT_VEC cppVar_4911;
	BIT_VEC cppVar_4912;
	bool cppVar_4913;
	BIT_VEC cppVar_4915;
	BIT_VEC cppVar_4916;
	BIT_VEC cppVar_4917;
	BIT_VEC cppVar_4918;
	bool cppVar_4919;
	BIT_VEC cppVar_4921;
	BIT_VEC cppVar_4922;
	BIT_VEC cppVar_4923;
	BIT_VEC cppVar_4924;
	bool cppVar_4925;
	BIT_VEC cppVar_4927;
	BIT_VEC cppVar_4928;
	BIT_VEC cppVar_4929;
	BIT_VEC cppVar_4930;
	bool cppVar_4931;
	BIT_VEC cppVar_4933;
	BIT_VEC cppVar_4934;
	BIT_VEC cppVar_4935;
	BIT_VEC cppVar_4936;
	bool cppVar_4937;
	BIT_VEC cppVar_4939;
	BIT_VEC cppVar_4940;
	BIT_VEC cppVar_4941;
	BIT_VEC cppVar_4942;
	bool cppVar_4943;
	BIT_VEC cppVar_4945;
	BIT_VEC cppVar_4946;
	BIT_VEC cppVar_4947;
	BIT_VEC cppVar_4948;
	bool cppVar_4949;
	BIT_VEC cppVar_4951;
	BIT_VEC cppVar_4952;
	BIT_VEC cppVar_4953;
	BIT_VEC cppVar_4954;
	bool cppVar_4955;
	BIT_VEC cppVar_4957;
	BIT_VEC cppVar_4958;
	BIT_VEC cppVar_4959;
	BIT_VEC cppVar_4960;
	bool cppVar_4961;
	BIT_VEC cppVar_4963;
	BIT_VEC cppVar_4964;
	BIT_VEC cppVar_4965;
	BIT_VEC cppVar_4966;
	bool cppVar_4967;
	BIT_VEC cppVar_4969;
	BIT_VEC cppVar_4970;
	BIT_VEC cppVar_4971;
	BIT_VEC cppVar_4972;
	bool cppVar_4973;
	BIT_VEC cppVar_4974;
	BIT_VEC cppVar_4968;
	BIT_VEC cppVar_4962;
	BIT_VEC cppVar_4956;
	BIT_VEC cppVar_4950;
	BIT_VEC cppVar_4944;
	BIT_VEC cppVar_4938;
	BIT_VEC cppVar_4932;
	BIT_VEC cppVar_4926;
	BIT_VEC cppVar_4920;
	BIT_VEC cppVar_4914;
	BIT_VEC cppVar_4908;
	BIT_VEC cppVar_4902;
	BIT_VEC cppVar_4896;
	BIT_VEC cppVar_4890;
	BIT_VEC cppVar_4884;
	BIT_VEC cppVar_4878;
	BIT_VEC cppVar_4872;
	BIT_VEC cppVar_4866;
	BIT_VEC cppVar_4860;
	BIT_VEC cppVar_4854;
	BIT_VEC cppVar_4848;
	BIT_VEC cppVar_4835;
	BIT_VEC cppVar_4829;
	BIT_VEC cppVar_4976;
	BIT_VEC cppVar_4977;
	bool cppVar_4978;
	BIT_VEC cppVar_4980;
	BIT_VEC cppVar_4981;
	BIT_VEC cppVar_4982;
	BIT_VEC cppVar_4983;
	bool cppVar_4984;
	BIT_VEC cppVar_4986;
	BIT_VEC cppVar_4987;
	BIT_VEC cppVar_4988;
	BIT_VEC cppVar_4989;
	BIT_VEC cppVar_4990;
	BIT_VEC cppVar_4991;
	BIT_VEC cppVar_4992;
	bool cppVar_4993;
	BIT_VEC cppVar_4994;
	BIT_VEC cppVar_4995;
	BIT_VEC cppVar_4996;
	BIT_VEC cppVar_4997;
	BIT_VEC cppVar_4999;
	BIT_VEC cppVar_5000;
	BIT_VEC cppVar_5001;
	BIT_VEC cppVar_5002;
	bool cppVar_5003;
	BIT_VEC cppVar_5005;
	BIT_VEC cppVar_5006;
	BIT_VEC cppVar_5007;
	BIT_VEC cppVar_5008;
	bool cppVar_5009;
	BIT_VEC cppVar_5011;
	BIT_VEC cppVar_5012;
	BIT_VEC cppVar_5013;
	BIT_VEC cppVar_5014;
	bool cppVar_5015;
	BIT_VEC cppVar_5017;
	BIT_VEC cppVar_5018;
	BIT_VEC cppVar_5019;
	BIT_VEC cppVar_5020;
	bool cppVar_5021;
	BIT_VEC cppVar_5023;
	BIT_VEC cppVar_5024;
	BIT_VEC cppVar_5025;
	BIT_VEC cppVar_5026;
	bool cppVar_5027;
	BIT_VEC cppVar_5029;
	BIT_VEC cppVar_5030;
	BIT_VEC cppVar_5031;
	BIT_VEC cppVar_5032;
	bool cppVar_5033;
	BIT_VEC cppVar_5035;
	BIT_VEC cppVar_5036;
	BIT_VEC cppVar_5037;
	BIT_VEC cppVar_5038;
	bool cppVar_5039;
	BIT_VEC cppVar_5041;
	BIT_VEC cppVar_5042;
	BIT_VEC cppVar_5043;
	BIT_VEC cppVar_5044;
	bool cppVar_5045;
	BIT_VEC cppVar_5047;
	BIT_VEC cppVar_5048;
	BIT_VEC cppVar_5049;
	BIT_VEC cppVar_5050;
	bool cppVar_5051;
	BIT_VEC cppVar_5053;
	BIT_VEC cppVar_5054;
	BIT_VEC cppVar_5055;
	BIT_VEC cppVar_5056;
	bool cppVar_5057;
	BIT_VEC cppVar_5059;
	BIT_VEC cppVar_5060;
	BIT_VEC cppVar_5061;
	BIT_VEC cppVar_5062;
	bool cppVar_5063;
	BIT_VEC cppVar_5065;
	BIT_VEC cppVar_5066;
	BIT_VEC cppVar_5067;
	BIT_VEC cppVar_5068;
	bool cppVar_5069;
	BIT_VEC cppVar_5071;
	BIT_VEC cppVar_5072;
	BIT_VEC cppVar_5073;
	BIT_VEC cppVar_5074;
	bool cppVar_5075;
	BIT_VEC cppVar_5077;
	BIT_VEC cppVar_5078;
	BIT_VEC cppVar_5079;
	BIT_VEC cppVar_5080;
	bool cppVar_5081;
	BIT_VEC cppVar_5083;
	BIT_VEC cppVar_5084;
	BIT_VEC cppVar_5085;
	BIT_VEC cppVar_5086;
	bool cppVar_5087;
	BIT_VEC cppVar_5089;
	BIT_VEC cppVar_5090;
	BIT_VEC cppVar_5091;
	BIT_VEC cppVar_5092;
	bool cppVar_5093;
	BIT_VEC cppVar_5095;
	BIT_VEC cppVar_5096;
	BIT_VEC cppVar_5097;
	BIT_VEC cppVar_5098;
	bool cppVar_5099;
	BIT_VEC cppVar_5101;
	BIT_VEC cppVar_5102;
	BIT_VEC cppVar_5103;
	BIT_VEC cppVar_5104;
	bool cppVar_5105;
	BIT_VEC cppVar_5107;
	BIT_VEC cppVar_5108;
	BIT_VEC cppVar_5109;
	BIT_VEC cppVar_5110;
	bool cppVar_5111;
	BIT_VEC cppVar_5113;
	BIT_VEC cppVar_5114;
	BIT_VEC cppVar_5115;
	BIT_VEC cppVar_5116;
	bool cppVar_5117;
	BIT_VEC cppVar_5119;
	BIT_VEC cppVar_5120;
	BIT_VEC cppVar_5121;
	BIT_VEC cppVar_5122;
	bool cppVar_5123;
	BIT_VEC cppVar_5124;
	BIT_VEC cppVar_5118;
	BIT_VEC cppVar_5112;
	BIT_VEC cppVar_5106;
	BIT_VEC cppVar_5100;
	BIT_VEC cppVar_5094;
	BIT_VEC cppVar_5088;
	BIT_VEC cppVar_5082;
	BIT_VEC cppVar_5076;
	BIT_VEC cppVar_5070;
	BIT_VEC cppVar_5064;
	BIT_VEC cppVar_5058;
	BIT_VEC cppVar_5052;
	BIT_VEC cppVar_5046;
	BIT_VEC cppVar_5040;
	BIT_VEC cppVar_5034;
	BIT_VEC cppVar_5028;
	BIT_VEC cppVar_5022;
	BIT_VEC cppVar_5016;
	BIT_VEC cppVar_5010;
	BIT_VEC cppVar_5004;
	BIT_VEC cppVar_4998;
	BIT_VEC cppVar_4985;
	BIT_VEC cppVar_4979;
	BIT_VEC cppVar_5126;
	BIT_VEC cppVar_5127;
	bool cppVar_5128;
	BIT_VEC cppVar_5130;
	BIT_VEC cppVar_5131;
	BIT_VEC cppVar_5132;
	BIT_VEC cppVar_5133;
	bool cppVar_5134;
	BIT_VEC cppVar_5136;
	BIT_VEC cppVar_5137;
	BIT_VEC cppVar_5138;
	BIT_VEC cppVar_5139;
	BIT_VEC cppVar_5140;
	BIT_VEC cppVar_5141;
	BIT_VEC cppVar_5142;
	bool cppVar_5143;
	BIT_VEC cppVar_5144;
	BIT_VEC cppVar_5145;
	BIT_VEC cppVar_5146;
	BIT_VEC cppVar_5147;
	BIT_VEC cppVar_5149;
	BIT_VEC cppVar_5150;
	BIT_VEC cppVar_5151;
	BIT_VEC cppVar_5152;
	bool cppVar_5153;
	BIT_VEC cppVar_5155;
	BIT_VEC cppVar_5156;
	BIT_VEC cppVar_5157;
	BIT_VEC cppVar_5158;
	bool cppVar_5159;
	BIT_VEC cppVar_5161;
	BIT_VEC cppVar_5162;
	BIT_VEC cppVar_5163;
	BIT_VEC cppVar_5164;
	bool cppVar_5165;
	BIT_VEC cppVar_5167;
	BIT_VEC cppVar_5168;
	BIT_VEC cppVar_5169;
	BIT_VEC cppVar_5170;
	bool cppVar_5171;
	BIT_VEC cppVar_5173;
	BIT_VEC cppVar_5174;
	BIT_VEC cppVar_5175;
	BIT_VEC cppVar_5176;
	bool cppVar_5177;
	BIT_VEC cppVar_5179;
	BIT_VEC cppVar_5180;
	BIT_VEC cppVar_5181;
	BIT_VEC cppVar_5182;
	bool cppVar_5183;
	BIT_VEC cppVar_5185;
	BIT_VEC cppVar_5186;
	BIT_VEC cppVar_5187;
	BIT_VEC cppVar_5188;
	bool cppVar_5189;
	BIT_VEC cppVar_5191;
	BIT_VEC cppVar_5192;
	BIT_VEC cppVar_5193;
	BIT_VEC cppVar_5194;
	bool cppVar_5195;
	BIT_VEC cppVar_5197;
	BIT_VEC cppVar_5198;
	BIT_VEC cppVar_5199;
	BIT_VEC cppVar_5200;
	bool cppVar_5201;
	BIT_VEC cppVar_5203;
	BIT_VEC cppVar_5204;
	BIT_VEC cppVar_5205;
	BIT_VEC cppVar_5206;
	bool cppVar_5207;
	BIT_VEC cppVar_5209;
	BIT_VEC cppVar_5210;
	BIT_VEC cppVar_5211;
	BIT_VEC cppVar_5212;
	bool cppVar_5213;
	BIT_VEC cppVar_5215;
	BIT_VEC cppVar_5216;
	BIT_VEC cppVar_5217;
	BIT_VEC cppVar_5218;
	bool cppVar_5219;
	BIT_VEC cppVar_5221;
	BIT_VEC cppVar_5222;
	BIT_VEC cppVar_5223;
	BIT_VEC cppVar_5224;
	bool cppVar_5225;
	BIT_VEC cppVar_5227;
	BIT_VEC cppVar_5228;
	BIT_VEC cppVar_5229;
	BIT_VEC cppVar_5230;
	bool cppVar_5231;
	BIT_VEC cppVar_5233;
	BIT_VEC cppVar_5234;
	BIT_VEC cppVar_5235;
	BIT_VEC cppVar_5236;
	bool cppVar_5237;
	BIT_VEC cppVar_5239;
	BIT_VEC cppVar_5240;
	BIT_VEC cppVar_5241;
	BIT_VEC cppVar_5242;
	bool cppVar_5243;
	BIT_VEC cppVar_5245;
	BIT_VEC cppVar_5246;
	BIT_VEC cppVar_5247;
	BIT_VEC cppVar_5248;
	bool cppVar_5249;
	BIT_VEC cppVar_5251;
	BIT_VEC cppVar_5252;
	BIT_VEC cppVar_5253;
	BIT_VEC cppVar_5254;
	bool cppVar_5255;
	BIT_VEC cppVar_5257;
	BIT_VEC cppVar_5258;
	BIT_VEC cppVar_5259;
	BIT_VEC cppVar_5260;
	bool cppVar_5261;
	BIT_VEC cppVar_5263;
	BIT_VEC cppVar_5264;
	BIT_VEC cppVar_5265;
	BIT_VEC cppVar_5266;
	bool cppVar_5267;
	BIT_VEC cppVar_5269;
	BIT_VEC cppVar_5270;
	BIT_VEC cppVar_5271;
	BIT_VEC cppVar_5272;
	bool cppVar_5273;
	BIT_VEC cppVar_5274;
	BIT_VEC cppVar_5268;
	BIT_VEC cppVar_5262;
	BIT_VEC cppVar_5256;
	BIT_VEC cppVar_5250;
	BIT_VEC cppVar_5244;
	BIT_VEC cppVar_5238;
	BIT_VEC cppVar_5232;
	BIT_VEC cppVar_5226;
	BIT_VEC cppVar_5220;
	BIT_VEC cppVar_5214;
	BIT_VEC cppVar_5208;
	BIT_VEC cppVar_5202;
	BIT_VEC cppVar_5196;
	BIT_VEC cppVar_5190;
	BIT_VEC cppVar_5184;
	BIT_VEC cppVar_5178;
	BIT_VEC cppVar_5172;
	BIT_VEC cppVar_5166;
	BIT_VEC cppVar_5160;
	BIT_VEC cppVar_5154;
	BIT_VEC cppVar_5148;
	BIT_VEC cppVar_5135;
	BIT_VEC cppVar_5129;
	BIT_VEC cppVar_5276;
	BIT_VEC cppVar_5277;
	bool cppVar_5278;
	BIT_VEC cppVar_5280;
	BIT_VEC cppVar_5281;
	BIT_VEC cppVar_5282;
	BIT_VEC cppVar_5283;
	bool cppVar_5284;
	BIT_VEC cppVar_5286;
	BIT_VEC cppVar_5287;
	BIT_VEC cppVar_5288;
	BIT_VEC cppVar_5289;
	BIT_VEC cppVar_5290;
	BIT_VEC cppVar_5291;
	BIT_VEC cppVar_5292;
	bool cppVar_5293;
	BIT_VEC cppVar_5294;
	BIT_VEC cppVar_5295;
	BIT_VEC cppVar_5296;
	BIT_VEC cppVar_5297;
	BIT_VEC cppVar_5299;
	BIT_VEC cppVar_5300;
	BIT_VEC cppVar_5301;
	BIT_VEC cppVar_5302;
	bool cppVar_5303;
	BIT_VEC cppVar_5305;
	BIT_VEC cppVar_5306;
	BIT_VEC cppVar_5307;
	BIT_VEC cppVar_5308;
	bool cppVar_5309;
	BIT_VEC cppVar_5311;
	BIT_VEC cppVar_5312;
	BIT_VEC cppVar_5313;
	BIT_VEC cppVar_5314;
	bool cppVar_5315;
	BIT_VEC cppVar_5317;
	BIT_VEC cppVar_5318;
	BIT_VEC cppVar_5319;
	BIT_VEC cppVar_5320;
	bool cppVar_5321;
	BIT_VEC cppVar_5323;
	BIT_VEC cppVar_5324;
	BIT_VEC cppVar_5325;
	BIT_VEC cppVar_5326;
	bool cppVar_5327;
	BIT_VEC cppVar_5329;
	BIT_VEC cppVar_5330;
	BIT_VEC cppVar_5331;
	BIT_VEC cppVar_5332;
	bool cppVar_5333;
	BIT_VEC cppVar_5335;
	BIT_VEC cppVar_5336;
	BIT_VEC cppVar_5337;
	BIT_VEC cppVar_5338;
	bool cppVar_5339;
	BIT_VEC cppVar_5341;
	BIT_VEC cppVar_5342;
	BIT_VEC cppVar_5343;
	BIT_VEC cppVar_5344;
	bool cppVar_5345;
	BIT_VEC cppVar_5347;
	BIT_VEC cppVar_5348;
	BIT_VEC cppVar_5349;
	BIT_VEC cppVar_5350;
	bool cppVar_5351;
	BIT_VEC cppVar_5353;
	BIT_VEC cppVar_5354;
	BIT_VEC cppVar_5355;
	BIT_VEC cppVar_5356;
	bool cppVar_5357;
	BIT_VEC cppVar_5359;
	BIT_VEC cppVar_5360;
	BIT_VEC cppVar_5361;
	BIT_VEC cppVar_5362;
	bool cppVar_5363;
	BIT_VEC cppVar_5365;
	BIT_VEC cppVar_5366;
	BIT_VEC cppVar_5367;
	BIT_VEC cppVar_5368;
	bool cppVar_5369;
	BIT_VEC cppVar_5371;
	BIT_VEC cppVar_5372;
	BIT_VEC cppVar_5373;
	BIT_VEC cppVar_5374;
	bool cppVar_5375;
	BIT_VEC cppVar_5377;
	BIT_VEC cppVar_5378;
	BIT_VEC cppVar_5379;
	BIT_VEC cppVar_5380;
	bool cppVar_5381;
	BIT_VEC cppVar_5383;
	BIT_VEC cppVar_5384;
	BIT_VEC cppVar_5385;
	BIT_VEC cppVar_5386;
	bool cppVar_5387;
	BIT_VEC cppVar_5389;
	BIT_VEC cppVar_5390;
	BIT_VEC cppVar_5391;
	BIT_VEC cppVar_5392;
	bool cppVar_5393;
	BIT_VEC cppVar_5395;
	BIT_VEC cppVar_5396;
	BIT_VEC cppVar_5397;
	BIT_VEC cppVar_5398;
	bool cppVar_5399;
	BIT_VEC cppVar_5401;
	BIT_VEC cppVar_5402;
	BIT_VEC cppVar_5403;
	BIT_VEC cppVar_5404;
	bool cppVar_5405;
	BIT_VEC cppVar_5407;
	BIT_VEC cppVar_5408;
	BIT_VEC cppVar_5409;
	BIT_VEC cppVar_5410;
	bool cppVar_5411;
	BIT_VEC cppVar_5413;
	BIT_VEC cppVar_5414;
	BIT_VEC cppVar_5415;
	BIT_VEC cppVar_5416;
	bool cppVar_5417;
	BIT_VEC cppVar_5419;
	BIT_VEC cppVar_5420;
	BIT_VEC cppVar_5421;
	BIT_VEC cppVar_5422;
	bool cppVar_5423;
	BIT_VEC cppVar_5424;
	BIT_VEC cppVar_5418;
	BIT_VEC cppVar_5412;
	BIT_VEC cppVar_5406;
	BIT_VEC cppVar_5400;
	BIT_VEC cppVar_5394;
	BIT_VEC cppVar_5388;
	BIT_VEC cppVar_5382;
	BIT_VEC cppVar_5376;
	BIT_VEC cppVar_5370;
	BIT_VEC cppVar_5364;
	BIT_VEC cppVar_5358;
	BIT_VEC cppVar_5352;
	BIT_VEC cppVar_5346;
	BIT_VEC cppVar_5340;
	BIT_VEC cppVar_5334;
	BIT_VEC cppVar_5328;
	BIT_VEC cppVar_5322;
	BIT_VEC cppVar_5316;
	BIT_VEC cppVar_5310;
	BIT_VEC cppVar_5304;
	BIT_VEC cppVar_5298;
	BIT_VEC cppVar_5285;
	BIT_VEC cppVar_5279;
	BIT_VEC cppVar_5426;
	BIT_VEC cppVar_5427;
	bool cppVar_5428;
	BIT_VEC cppVar_5430;
	BIT_VEC cppVar_5431;
	BIT_VEC cppVar_5432;
	BIT_VEC cppVar_5433;
	bool cppVar_5434;
	BIT_VEC cppVar_5436;
	BIT_VEC cppVar_5437;
	BIT_VEC cppVar_5438;
	BIT_VEC cppVar_5439;
	BIT_VEC cppVar_5440;
	BIT_VEC cppVar_5441;
	BIT_VEC cppVar_5442;
	bool cppVar_5443;
	BIT_VEC cppVar_5444;
	BIT_VEC cppVar_5445;
	BIT_VEC cppVar_5446;
	BIT_VEC cppVar_5447;
	BIT_VEC cppVar_5449;
	BIT_VEC cppVar_5450;
	BIT_VEC cppVar_5451;
	BIT_VEC cppVar_5452;
	bool cppVar_5453;
	BIT_VEC cppVar_5455;
	BIT_VEC cppVar_5456;
	BIT_VEC cppVar_5457;
	BIT_VEC cppVar_5458;
	bool cppVar_5459;
	BIT_VEC cppVar_5461;
	BIT_VEC cppVar_5462;
	BIT_VEC cppVar_5463;
	BIT_VEC cppVar_5464;
	bool cppVar_5465;
	BIT_VEC cppVar_5467;
	BIT_VEC cppVar_5468;
	BIT_VEC cppVar_5469;
	BIT_VEC cppVar_5470;
	bool cppVar_5471;
	BIT_VEC cppVar_5473;
	BIT_VEC cppVar_5474;
	BIT_VEC cppVar_5475;
	BIT_VEC cppVar_5476;
	bool cppVar_5477;
	BIT_VEC cppVar_5479;
	BIT_VEC cppVar_5480;
	BIT_VEC cppVar_5481;
	BIT_VEC cppVar_5482;
	bool cppVar_5483;
	BIT_VEC cppVar_5485;
	BIT_VEC cppVar_5486;
	BIT_VEC cppVar_5487;
	BIT_VEC cppVar_5488;
	bool cppVar_5489;
	BIT_VEC cppVar_5491;
	BIT_VEC cppVar_5492;
	BIT_VEC cppVar_5493;
	BIT_VEC cppVar_5494;
	bool cppVar_5495;
	BIT_VEC cppVar_5497;
	BIT_VEC cppVar_5498;
	BIT_VEC cppVar_5499;
	BIT_VEC cppVar_5500;
	bool cppVar_5501;
	BIT_VEC cppVar_5503;
	BIT_VEC cppVar_5504;
	BIT_VEC cppVar_5505;
	BIT_VEC cppVar_5506;
	bool cppVar_5507;
	BIT_VEC cppVar_5509;
	BIT_VEC cppVar_5510;
	BIT_VEC cppVar_5511;
	BIT_VEC cppVar_5512;
	bool cppVar_5513;
	BIT_VEC cppVar_5515;
	BIT_VEC cppVar_5516;
	BIT_VEC cppVar_5517;
	BIT_VEC cppVar_5518;
	bool cppVar_5519;
	BIT_VEC cppVar_5521;
	BIT_VEC cppVar_5522;
	BIT_VEC cppVar_5523;
	BIT_VEC cppVar_5524;
	bool cppVar_5525;
	BIT_VEC cppVar_5527;
	BIT_VEC cppVar_5528;
	BIT_VEC cppVar_5529;
	BIT_VEC cppVar_5530;
	bool cppVar_5531;
	BIT_VEC cppVar_5533;
	BIT_VEC cppVar_5534;
	BIT_VEC cppVar_5535;
	BIT_VEC cppVar_5536;
	bool cppVar_5537;
	BIT_VEC cppVar_5539;
	BIT_VEC cppVar_5540;
	BIT_VEC cppVar_5541;
	BIT_VEC cppVar_5542;
	bool cppVar_5543;
	BIT_VEC cppVar_5545;
	BIT_VEC cppVar_5546;
	BIT_VEC cppVar_5547;
	BIT_VEC cppVar_5548;
	bool cppVar_5549;
	BIT_VEC cppVar_5551;
	BIT_VEC cppVar_5552;
	BIT_VEC cppVar_5553;
	BIT_VEC cppVar_5554;
	bool cppVar_5555;
	BIT_VEC cppVar_5557;
	BIT_VEC cppVar_5558;
	BIT_VEC cppVar_5559;
	BIT_VEC cppVar_5560;
	bool cppVar_5561;
	BIT_VEC cppVar_5563;
	BIT_VEC cppVar_5564;
	BIT_VEC cppVar_5565;
	BIT_VEC cppVar_5566;
	bool cppVar_5567;
	BIT_VEC cppVar_5569;
	BIT_VEC cppVar_5570;
	BIT_VEC cppVar_5571;
	BIT_VEC cppVar_5572;
	bool cppVar_5573;
	BIT_VEC cppVar_5574;
	BIT_VEC cppVar_5568;
	BIT_VEC cppVar_5562;
	BIT_VEC cppVar_5556;
	BIT_VEC cppVar_5550;
	BIT_VEC cppVar_5544;
	BIT_VEC cppVar_5538;
	BIT_VEC cppVar_5532;
	BIT_VEC cppVar_5526;
	BIT_VEC cppVar_5520;
	BIT_VEC cppVar_5514;
	BIT_VEC cppVar_5508;
	BIT_VEC cppVar_5502;
	BIT_VEC cppVar_5496;
	BIT_VEC cppVar_5490;
	BIT_VEC cppVar_5484;
	BIT_VEC cppVar_5478;
	BIT_VEC cppVar_5472;
	BIT_VEC cppVar_5466;
	BIT_VEC cppVar_5460;
	BIT_VEC cppVar_5454;
	BIT_VEC cppVar_5448;
	BIT_VEC cppVar_5435;
	BIT_VEC cppVar_5429;
	BIT_VEC cppVar_5576;
	BIT_VEC cppVar_5577;
	bool cppVar_5578;
	BIT_VEC cppVar_5580;
	BIT_VEC cppVar_5581;
	BIT_VEC cppVar_5582;
	BIT_VEC cppVar_5583;
	bool cppVar_5584;
	BIT_VEC cppVar_5586;
	BIT_VEC cppVar_5587;
	BIT_VEC cppVar_5588;
	BIT_VEC cppVar_5589;
	BIT_VEC cppVar_5590;
	BIT_VEC cppVar_5591;
	BIT_VEC cppVar_5592;
	bool cppVar_5593;
	BIT_VEC cppVar_5594;
	BIT_VEC cppVar_5595;
	BIT_VEC cppVar_5596;
	BIT_VEC cppVar_5597;
	BIT_VEC cppVar_5599;
	BIT_VEC cppVar_5600;
	BIT_VEC cppVar_5601;
	BIT_VEC cppVar_5602;
	bool cppVar_5603;
	BIT_VEC cppVar_5605;
	BIT_VEC cppVar_5606;
	BIT_VEC cppVar_5607;
	BIT_VEC cppVar_5608;
	bool cppVar_5609;
	BIT_VEC cppVar_5611;
	BIT_VEC cppVar_5612;
	BIT_VEC cppVar_5613;
	BIT_VEC cppVar_5614;
	bool cppVar_5615;
	BIT_VEC cppVar_5617;
	BIT_VEC cppVar_5618;
	BIT_VEC cppVar_5619;
	BIT_VEC cppVar_5620;
	bool cppVar_5621;
	BIT_VEC cppVar_5623;
	BIT_VEC cppVar_5624;
	BIT_VEC cppVar_5625;
	BIT_VEC cppVar_5626;
	bool cppVar_5627;
	BIT_VEC cppVar_5629;
	BIT_VEC cppVar_5630;
	BIT_VEC cppVar_5631;
	BIT_VEC cppVar_5632;
	bool cppVar_5633;
	BIT_VEC cppVar_5635;
	BIT_VEC cppVar_5636;
	BIT_VEC cppVar_5637;
	BIT_VEC cppVar_5638;
	bool cppVar_5639;
	BIT_VEC cppVar_5641;
	BIT_VEC cppVar_5642;
	BIT_VEC cppVar_5643;
	BIT_VEC cppVar_5644;
	bool cppVar_5645;
	BIT_VEC cppVar_5647;
	BIT_VEC cppVar_5648;
	BIT_VEC cppVar_5649;
	BIT_VEC cppVar_5650;
	bool cppVar_5651;
	BIT_VEC cppVar_5653;
	BIT_VEC cppVar_5654;
	BIT_VEC cppVar_5655;
	BIT_VEC cppVar_5656;
	bool cppVar_5657;
	BIT_VEC cppVar_5659;
	BIT_VEC cppVar_5660;
	BIT_VEC cppVar_5661;
	BIT_VEC cppVar_5662;
	bool cppVar_5663;
	BIT_VEC cppVar_5665;
	BIT_VEC cppVar_5666;
	BIT_VEC cppVar_5667;
	BIT_VEC cppVar_5668;
	bool cppVar_5669;
	BIT_VEC cppVar_5671;
	BIT_VEC cppVar_5672;
	BIT_VEC cppVar_5673;
	BIT_VEC cppVar_5674;
	bool cppVar_5675;
	BIT_VEC cppVar_5677;
	BIT_VEC cppVar_5678;
	BIT_VEC cppVar_5679;
	BIT_VEC cppVar_5680;
	bool cppVar_5681;
	BIT_VEC cppVar_5683;
	BIT_VEC cppVar_5684;
	BIT_VEC cppVar_5685;
	BIT_VEC cppVar_5686;
	bool cppVar_5687;
	BIT_VEC cppVar_5689;
	BIT_VEC cppVar_5690;
	BIT_VEC cppVar_5691;
	BIT_VEC cppVar_5692;
	bool cppVar_5693;
	BIT_VEC cppVar_5695;
	BIT_VEC cppVar_5696;
	BIT_VEC cppVar_5697;
	BIT_VEC cppVar_5698;
	bool cppVar_5699;
	BIT_VEC cppVar_5701;
	BIT_VEC cppVar_5702;
	BIT_VEC cppVar_5703;
	BIT_VEC cppVar_5704;
	bool cppVar_5705;
	BIT_VEC cppVar_5707;
	BIT_VEC cppVar_5708;
	BIT_VEC cppVar_5709;
	BIT_VEC cppVar_5710;
	bool cppVar_5711;
	BIT_VEC cppVar_5713;
	BIT_VEC cppVar_5714;
	BIT_VEC cppVar_5715;
	BIT_VEC cppVar_5716;
	bool cppVar_5717;
	BIT_VEC cppVar_5719;
	BIT_VEC cppVar_5720;
	BIT_VEC cppVar_5721;
	BIT_VEC cppVar_5722;
	bool cppVar_5723;
	BIT_VEC cppVar_5724;
	BIT_VEC cppVar_5718;
	BIT_VEC cppVar_5712;
	BIT_VEC cppVar_5706;
	BIT_VEC cppVar_5700;
	BIT_VEC cppVar_5694;
	BIT_VEC cppVar_5688;
	BIT_VEC cppVar_5682;
	BIT_VEC cppVar_5676;
	BIT_VEC cppVar_5670;
	BIT_VEC cppVar_5664;
	BIT_VEC cppVar_5658;
	BIT_VEC cppVar_5652;
	BIT_VEC cppVar_5646;
	BIT_VEC cppVar_5640;
	BIT_VEC cppVar_5634;
	BIT_VEC cppVar_5628;
	BIT_VEC cppVar_5622;
	BIT_VEC cppVar_5616;
	BIT_VEC cppVar_5610;
	BIT_VEC cppVar_5604;
	BIT_VEC cppVar_5598;
	BIT_VEC cppVar_5585;
	BIT_VEC cppVar_5579;
	BIT_VEC cppVar_5726;
	BIT_VEC cppVar_5727;
	bool cppVar_5728;
	BIT_VEC cppVar_5730;
	BIT_VEC cppVar_5731;
	BIT_VEC cppVar_5732;
	BIT_VEC cppVar_5733;
	bool cppVar_5734;
	BIT_VEC cppVar_5736;
	BIT_VEC cppVar_5737;
	BIT_VEC cppVar_5738;
	BIT_VEC cppVar_5739;
	BIT_VEC cppVar_5740;
	BIT_VEC cppVar_5741;
	BIT_VEC cppVar_5742;
	bool cppVar_5743;
	BIT_VEC cppVar_5744;
	BIT_VEC cppVar_5745;
	BIT_VEC cppVar_5746;
	BIT_VEC cppVar_5747;
	BIT_VEC cppVar_5749;
	BIT_VEC cppVar_5750;
	BIT_VEC cppVar_5751;
	BIT_VEC cppVar_5752;
	bool cppVar_5753;
	BIT_VEC cppVar_5755;
	BIT_VEC cppVar_5756;
	BIT_VEC cppVar_5757;
	BIT_VEC cppVar_5758;
	bool cppVar_5759;
	BIT_VEC cppVar_5761;
	BIT_VEC cppVar_5762;
	BIT_VEC cppVar_5763;
	BIT_VEC cppVar_5764;
	bool cppVar_5765;
	BIT_VEC cppVar_5767;
	BIT_VEC cppVar_5768;
	BIT_VEC cppVar_5769;
	BIT_VEC cppVar_5770;
	bool cppVar_5771;
	BIT_VEC cppVar_5773;
	BIT_VEC cppVar_5774;
	BIT_VEC cppVar_5775;
	BIT_VEC cppVar_5776;
	bool cppVar_5777;
	BIT_VEC cppVar_5779;
	BIT_VEC cppVar_5780;
	BIT_VEC cppVar_5781;
	BIT_VEC cppVar_5782;
	bool cppVar_5783;
	BIT_VEC cppVar_5785;
	BIT_VEC cppVar_5786;
	BIT_VEC cppVar_5787;
	BIT_VEC cppVar_5788;
	bool cppVar_5789;
	BIT_VEC cppVar_5791;
	BIT_VEC cppVar_5792;
	BIT_VEC cppVar_5793;
	BIT_VEC cppVar_5794;
	bool cppVar_5795;
	BIT_VEC cppVar_5797;
	BIT_VEC cppVar_5798;
	BIT_VEC cppVar_5799;
	BIT_VEC cppVar_5800;
	bool cppVar_5801;
	BIT_VEC cppVar_5803;
	BIT_VEC cppVar_5804;
	BIT_VEC cppVar_5805;
	BIT_VEC cppVar_5806;
	bool cppVar_5807;
	BIT_VEC cppVar_5809;
	BIT_VEC cppVar_5810;
	BIT_VEC cppVar_5811;
	BIT_VEC cppVar_5812;
	bool cppVar_5813;
	BIT_VEC cppVar_5815;
	BIT_VEC cppVar_5816;
	BIT_VEC cppVar_5817;
	BIT_VEC cppVar_5818;
	bool cppVar_5819;
	BIT_VEC cppVar_5821;
	BIT_VEC cppVar_5822;
	BIT_VEC cppVar_5823;
	BIT_VEC cppVar_5824;
	bool cppVar_5825;
	BIT_VEC cppVar_5827;
	BIT_VEC cppVar_5828;
	BIT_VEC cppVar_5829;
	BIT_VEC cppVar_5830;
	bool cppVar_5831;
	BIT_VEC cppVar_5833;
	BIT_VEC cppVar_5834;
	BIT_VEC cppVar_5835;
	BIT_VEC cppVar_5836;
	bool cppVar_5837;
	BIT_VEC cppVar_5839;
	BIT_VEC cppVar_5840;
	BIT_VEC cppVar_5841;
	BIT_VEC cppVar_5842;
	bool cppVar_5843;
	BIT_VEC cppVar_5845;
	BIT_VEC cppVar_5846;
	BIT_VEC cppVar_5847;
	BIT_VEC cppVar_5848;
	bool cppVar_5849;
	BIT_VEC cppVar_5851;
	BIT_VEC cppVar_5852;
	BIT_VEC cppVar_5853;
	BIT_VEC cppVar_5854;
	bool cppVar_5855;
	BIT_VEC cppVar_5857;
	BIT_VEC cppVar_5858;
	BIT_VEC cppVar_5859;
	BIT_VEC cppVar_5860;
	bool cppVar_5861;
	BIT_VEC cppVar_5863;
	BIT_VEC cppVar_5864;
	BIT_VEC cppVar_5865;
	BIT_VEC cppVar_5866;
	bool cppVar_5867;
	BIT_VEC cppVar_5869;
	BIT_VEC cppVar_5870;
	BIT_VEC cppVar_5871;
	BIT_VEC cppVar_5872;
	bool cppVar_5873;
	BIT_VEC cppVar_5874;
	BIT_VEC cppVar_5868;
	BIT_VEC cppVar_5862;
	BIT_VEC cppVar_5856;
	BIT_VEC cppVar_5850;
	BIT_VEC cppVar_5844;
	BIT_VEC cppVar_5838;
	BIT_VEC cppVar_5832;
	BIT_VEC cppVar_5826;
	BIT_VEC cppVar_5820;
	BIT_VEC cppVar_5814;
	BIT_VEC cppVar_5808;
	BIT_VEC cppVar_5802;
	BIT_VEC cppVar_5796;
	BIT_VEC cppVar_5790;
	BIT_VEC cppVar_5784;
	BIT_VEC cppVar_5778;
	BIT_VEC cppVar_5772;
	BIT_VEC cppVar_5766;
	BIT_VEC cppVar_5760;
	BIT_VEC cppVar_5754;
	BIT_VEC cppVar_5748;
	BIT_VEC cppVar_5735;
	BIT_VEC cppVar_5729;
	BIT_VEC cppVar_5876;
	BIT_VEC cppVar_5877;
	bool cppVar_5878;
	BIT_VEC cppVar_5880;
	BIT_VEC cppVar_5881;
	BIT_VEC cppVar_5882;
	BIT_VEC cppVar_5883;
	bool cppVar_5884;
	BIT_VEC cppVar_5885;
	BIT_VEC cppVar_5886;
	BIT_VEC cppVar_5887;
	BIT_VEC cppVar_5888;
	BIT_VEC cppVar_5889;
	BIT_VEC cppVar_5890;
	BIT_VEC cppVar_5891;
	BIT_VEC cppVar_5879;
	BIT_VEC cppVar_5893;
	BIT_VEC cppVar_5894;
	bool cppVar_5895;
	BIT_VEC cppVar_5897;
	BIT_VEC cppVar_5898;
	BIT_VEC cppVar_5899;
	BIT_VEC cppVar_5900;
	bool cppVar_5901;
	BIT_VEC cppVar_5902;
	BIT_VEC cppVar_5903;
	BIT_VEC cppVar_5904;
	BIT_VEC cppVar_5905;
	BIT_VEC cppVar_5906;
	BIT_VEC cppVar_5907;
	BIT_VEC cppVar_5908;
	BIT_VEC cppVar_5896;
	BIT_VEC cppVar_5910;
	BIT_VEC cppVar_5911;
	bool cppVar_5912;
	BIT_VEC cppVar_5914;
	BIT_VEC cppVar_5915;
	BIT_VEC cppVar_5916;
	BIT_VEC cppVar_5917;
	bool cppVar_5918;
	BIT_VEC cppVar_5920;
	BIT_VEC cppVar_5921;
	BIT_VEC cppVar_5922;
	BIT_VEC cppVar_5923;
	BIT_VEC cppVar_5924;
	bool cppVar_5925;
	BIT_VEC cppVar_5926;
	BIT_VEC cppVar_5927;
	BIT_VEC cppVar_5928;
	BIT_VEC cppVar_5930;
	BIT_VEC cppVar_5931;
	BIT_VEC cppVar_5932;
	bool cppVar_5933;
	BIT_VEC cppVar_5935;
	BIT_VEC cppVar_5936;
	BIT_VEC cppVar_5937;
	bool cppVar_5938;
	BIT_VEC cppVar_5940;
	BIT_VEC cppVar_5941;
	BIT_VEC cppVar_5942;
	bool cppVar_5943;
	BIT_VEC cppVar_5945;
	BIT_VEC cppVar_5946;
	BIT_VEC cppVar_5947;
	bool cppVar_5948;
	BIT_VEC cppVar_5950;
	BIT_VEC cppVar_5951;
	BIT_VEC cppVar_5952;
	bool cppVar_5953;
	BIT_VEC cppVar_5955;
	BIT_VEC cppVar_5956;
	BIT_VEC cppVar_5957;
	bool cppVar_5958;
	BIT_VEC cppVar_5960;
	BIT_VEC cppVar_5961;
	BIT_VEC cppVar_5962;
	bool cppVar_5963;
	BIT_VEC cppVar_5965;
	BIT_VEC cppVar_5966;
	BIT_VEC cppVar_5967;
	bool cppVar_5968;
	BIT_VEC cppVar_5970;
	BIT_VEC cppVar_5971;
	BIT_VEC cppVar_5972;
	bool cppVar_5973;
	BIT_VEC cppVar_5975;
	BIT_VEC cppVar_5976;
	BIT_VEC cppVar_5977;
	bool cppVar_5978;
	BIT_VEC cppVar_5980;
	BIT_VEC cppVar_5981;
	BIT_VEC cppVar_5982;
	bool cppVar_5983;
	BIT_VEC cppVar_5985;
	BIT_VEC cppVar_5986;
	BIT_VEC cppVar_5987;
	bool cppVar_5988;
	BIT_VEC cppVar_5990;
	BIT_VEC cppVar_5991;
	BIT_VEC cppVar_5992;
	bool cppVar_5993;
	BIT_VEC cppVar_5995;
	BIT_VEC cppVar_5996;
	BIT_VEC cppVar_5997;
	bool cppVar_5998;
	BIT_VEC cppVar_6000;
	BIT_VEC cppVar_6001;
	BIT_VEC cppVar_6002;
	bool cppVar_6003;
	BIT_VEC cppVar_6005;
	BIT_VEC cppVar_6006;
	BIT_VEC cppVar_6007;
	bool cppVar_6008;
	BIT_VEC cppVar_6010;
	BIT_VEC cppVar_6011;
	BIT_VEC cppVar_6012;
	bool cppVar_6013;
	BIT_VEC cppVar_6015;
	BIT_VEC cppVar_6016;
	BIT_VEC cppVar_6017;
	bool cppVar_6018;
	BIT_VEC cppVar_6020;
	BIT_VEC cppVar_6021;
	BIT_VEC cppVar_6022;
	bool cppVar_6023;
	BIT_VEC cppVar_6025;
	BIT_VEC cppVar_6026;
	BIT_VEC cppVar_6027;
	bool cppVar_6028;
	BIT_VEC cppVar_6030;
	BIT_VEC cppVar_6031;
	BIT_VEC cppVar_6032;
	bool cppVar_6033;
	BIT_VEC cppVar_6034;
	BIT_VEC cppVar_6029;
	BIT_VEC cppVar_6024;
	BIT_VEC cppVar_6019;
	BIT_VEC cppVar_6014;
	BIT_VEC cppVar_6009;
	BIT_VEC cppVar_6004;
	BIT_VEC cppVar_5999;
	BIT_VEC cppVar_5994;
	BIT_VEC cppVar_5989;
	BIT_VEC cppVar_5984;
	BIT_VEC cppVar_5979;
	BIT_VEC cppVar_5974;
	BIT_VEC cppVar_5969;
	BIT_VEC cppVar_5964;
	BIT_VEC cppVar_5959;
	BIT_VEC cppVar_5954;
	BIT_VEC cppVar_5949;
	BIT_VEC cppVar_5944;
	BIT_VEC cppVar_5939;
	BIT_VEC cppVar_5934;
	BIT_VEC cppVar_5929;
	BIT_VEC cppVar_5919;
	BIT_VEC cppVar_5913;
	BIT_VEC cppVar_6036;
	BIT_VEC cppVar_6037;
	bool cppVar_6038;
	BIT_VEC cppVar_6040;
	bool cppVar_6041;
	BIT_VEC cppVar_6042;
	BIT_VEC cppVar_6039;
	BIT_VEC cppVar_6044;
	BIT_VEC cppVar_6045;
	bool cppVar_6046;
	BIT_VEC cppVar_6048;
	BIT_VEC cppVar_6049;
	BIT_VEC cppVar_6050;
	BIT_VEC cppVar_6051;
	bool cppVar_6052;
	BIT_VEC cppVar_6053;
	BIT_VEC cppVar_6054;
	BIT_VEC cppVar_6055;
	BIT_VEC cppVar_6047;
	BIT_VEC cppVar_6057;
	BIT_VEC cppVar_6058;
	bool cppVar_6059;
	BIT_VEC cppVar_6061;
	BIT_VEC cppVar_6062;
	BIT_VEC cppVar_6063;
	BIT_VEC cppVar_6064;
	bool cppVar_6065;
	BIT_VEC cppVar_6067;
	BIT_VEC cppVar_6068;
	BIT_VEC cppVar_6069;
	BIT_VEC cppVar_6070;
	bool cppVar_6071;
	BIT_VEC cppVar_6072;
	BIT_VEC cppVar_6073;
	BIT_VEC cppVar_6074;
	BIT_VEC cppVar_6076;
	BIT_VEC cppVar_6077;
	BIT_VEC cppVar_6078;
	bool cppVar_6079;
	BIT_VEC cppVar_6081;
	BIT_VEC cppVar_6082;
	BIT_VEC cppVar_6083;
	bool cppVar_6084;
	BIT_VEC cppVar_6086;
	BIT_VEC cppVar_6087;
	BIT_VEC cppVar_6088;
	bool cppVar_6089;
	BIT_VEC cppVar_6091;
	BIT_VEC cppVar_6092;
	BIT_VEC cppVar_6093;
	bool cppVar_6094;
	BIT_VEC cppVar_6096;
	BIT_VEC cppVar_6097;
	BIT_VEC cppVar_6098;
	bool cppVar_6099;
	BIT_VEC cppVar_6101;
	BIT_VEC cppVar_6102;
	BIT_VEC cppVar_6103;
	bool cppVar_6104;
	BIT_VEC cppVar_6106;
	BIT_VEC cppVar_6107;
	BIT_VEC cppVar_6108;
	bool cppVar_6109;
	BIT_VEC cppVar_6111;
	BIT_VEC cppVar_6112;
	BIT_VEC cppVar_6113;
	bool cppVar_6114;
	BIT_VEC cppVar_6116;
	BIT_VEC cppVar_6117;
	BIT_VEC cppVar_6118;
	bool cppVar_6119;
	BIT_VEC cppVar_6121;
	BIT_VEC cppVar_6122;
	BIT_VEC cppVar_6123;
	bool cppVar_6124;
	BIT_VEC cppVar_6126;
	BIT_VEC cppVar_6127;
	BIT_VEC cppVar_6128;
	bool cppVar_6129;
	BIT_VEC cppVar_6131;
	BIT_VEC cppVar_6132;
	BIT_VEC cppVar_6133;
	bool cppVar_6134;
	BIT_VEC cppVar_6136;
	BIT_VEC cppVar_6137;
	BIT_VEC cppVar_6138;
	bool cppVar_6139;
	BIT_VEC cppVar_6141;
	BIT_VEC cppVar_6142;
	BIT_VEC cppVar_6143;
	bool cppVar_6144;
	BIT_VEC cppVar_6146;
	BIT_VEC cppVar_6147;
	BIT_VEC cppVar_6148;
	bool cppVar_6149;
	BIT_VEC cppVar_6151;
	BIT_VEC cppVar_6152;
	BIT_VEC cppVar_6153;
	bool cppVar_6154;
	BIT_VEC cppVar_6156;
	BIT_VEC cppVar_6157;
	BIT_VEC cppVar_6158;
	bool cppVar_6159;
	BIT_VEC cppVar_6161;
	BIT_VEC cppVar_6162;
	BIT_VEC cppVar_6163;
	bool cppVar_6164;
	BIT_VEC cppVar_6166;
	BIT_VEC cppVar_6167;
	BIT_VEC cppVar_6168;
	bool cppVar_6169;
	BIT_VEC cppVar_6171;
	BIT_VEC cppVar_6172;
	BIT_VEC cppVar_6173;
	bool cppVar_6174;
	BIT_VEC cppVar_6176;
	BIT_VEC cppVar_6177;
	BIT_VEC cppVar_6178;
	bool cppVar_6179;
	BIT_VEC cppVar_6180;
	BIT_VEC cppVar_6175;
	BIT_VEC cppVar_6170;
	BIT_VEC cppVar_6165;
	BIT_VEC cppVar_6160;
	BIT_VEC cppVar_6155;
	BIT_VEC cppVar_6150;
	BIT_VEC cppVar_6145;
	BIT_VEC cppVar_6140;
	BIT_VEC cppVar_6135;
	BIT_VEC cppVar_6130;
	BIT_VEC cppVar_6125;
	BIT_VEC cppVar_6120;
	BIT_VEC cppVar_6115;
	BIT_VEC cppVar_6110;
	BIT_VEC cppVar_6105;
	BIT_VEC cppVar_6100;
	BIT_VEC cppVar_6095;
	BIT_VEC cppVar_6090;
	BIT_VEC cppVar_6085;
	BIT_VEC cppVar_6080;
	BIT_VEC cppVar_6075;
	BIT_VEC cppVar_6066;
	BIT_VEC cppVar_6181;
	BIT_VEC cppVar_6182;
	BIT_VEC cppVar_6183;
	BIT_VEC cppVar_6184;
	BIT_VEC cppVar_6060;
	BIT_VEC cppVar_6186;
	BIT_VEC cppVar_6187;
	bool cppVar_6188;
	BIT_VEC cppVar_6190;
	BIT_VEC cppVar_6191;
	BIT_VEC cppVar_6192;
	BIT_VEC cppVar_6193;
	bool cppVar_6194;
	BIT_VEC cppVar_6196;
	BIT_VEC cppVar_6197;
	BIT_VEC cppVar_6198;
	BIT_VEC cppVar_6199;
	bool cppVar_6200;
	BIT_VEC cppVar_6201;
	BIT_VEC cppVar_6202;
	BIT_VEC cppVar_6203;
	BIT_VEC cppVar_6205;
	BIT_VEC cppVar_6206;
	BIT_VEC cppVar_6207;
	bool cppVar_6208;
	BIT_VEC cppVar_6210;
	BIT_VEC cppVar_6211;
	BIT_VEC cppVar_6212;
	bool cppVar_6213;
	BIT_VEC cppVar_6215;
	BIT_VEC cppVar_6216;
	BIT_VEC cppVar_6217;
	bool cppVar_6218;
	BIT_VEC cppVar_6220;
	BIT_VEC cppVar_6221;
	BIT_VEC cppVar_6222;
	bool cppVar_6223;
	BIT_VEC cppVar_6225;
	BIT_VEC cppVar_6226;
	BIT_VEC cppVar_6227;
	bool cppVar_6228;
	BIT_VEC cppVar_6230;
	BIT_VEC cppVar_6231;
	BIT_VEC cppVar_6232;
	bool cppVar_6233;
	BIT_VEC cppVar_6235;
	BIT_VEC cppVar_6236;
	BIT_VEC cppVar_6237;
	bool cppVar_6238;
	BIT_VEC cppVar_6240;
	BIT_VEC cppVar_6241;
	BIT_VEC cppVar_6242;
	bool cppVar_6243;
	BIT_VEC cppVar_6245;
	BIT_VEC cppVar_6246;
	BIT_VEC cppVar_6247;
	bool cppVar_6248;
	BIT_VEC cppVar_6250;
	BIT_VEC cppVar_6251;
	BIT_VEC cppVar_6252;
	bool cppVar_6253;
	BIT_VEC cppVar_6255;
	BIT_VEC cppVar_6256;
	BIT_VEC cppVar_6257;
	bool cppVar_6258;
	BIT_VEC cppVar_6260;
	BIT_VEC cppVar_6261;
	BIT_VEC cppVar_6262;
	bool cppVar_6263;
	BIT_VEC cppVar_6265;
	BIT_VEC cppVar_6266;
	BIT_VEC cppVar_6267;
	bool cppVar_6268;
	BIT_VEC cppVar_6270;
	BIT_VEC cppVar_6271;
	BIT_VEC cppVar_6272;
	bool cppVar_6273;
	BIT_VEC cppVar_6275;
	BIT_VEC cppVar_6276;
	BIT_VEC cppVar_6277;
	bool cppVar_6278;
	BIT_VEC cppVar_6280;
	BIT_VEC cppVar_6281;
	BIT_VEC cppVar_6282;
	bool cppVar_6283;
	BIT_VEC cppVar_6285;
	BIT_VEC cppVar_6286;
	BIT_VEC cppVar_6287;
	bool cppVar_6288;
	BIT_VEC cppVar_6290;
	BIT_VEC cppVar_6291;
	BIT_VEC cppVar_6292;
	bool cppVar_6293;
	BIT_VEC cppVar_6295;
	BIT_VEC cppVar_6296;
	BIT_VEC cppVar_6297;
	bool cppVar_6298;
	BIT_VEC cppVar_6300;
	BIT_VEC cppVar_6301;
	BIT_VEC cppVar_6302;
	bool cppVar_6303;
	BIT_VEC cppVar_6305;
	BIT_VEC cppVar_6306;
	BIT_VEC cppVar_6307;
	bool cppVar_6308;
	BIT_VEC cppVar_6309;
	BIT_VEC cppVar_6304;
	BIT_VEC cppVar_6299;
	BIT_VEC cppVar_6294;
	BIT_VEC cppVar_6289;
	BIT_VEC cppVar_6284;
	BIT_VEC cppVar_6279;
	BIT_VEC cppVar_6274;
	BIT_VEC cppVar_6269;
	BIT_VEC cppVar_6264;
	BIT_VEC cppVar_6259;
	BIT_VEC cppVar_6254;
	BIT_VEC cppVar_6249;
	BIT_VEC cppVar_6244;
	BIT_VEC cppVar_6239;
	BIT_VEC cppVar_6234;
	BIT_VEC cppVar_6229;
	BIT_VEC cppVar_6224;
	BIT_VEC cppVar_6219;
	BIT_VEC cppVar_6214;
	BIT_VEC cppVar_6209;
	BIT_VEC cppVar_6204;
	BIT_VEC cppVar_6195;
	BIT_VEC cppVar_6310;
	BIT_VEC cppVar_6189;
	BIT_VEC cppVar_6312;
	BIT_VEC cppVar_6313;
	bool cppVar_6314;
	BIT_VEC cppVar_6316;
	BIT_VEC cppVar_6317;
	BIT_VEC cppVar_6318;
	BIT_VEC cppVar_6319;
	bool cppVar_6320;
	BIT_VEC cppVar_6322;
	BIT_VEC cppVar_6323;
	BIT_VEC cppVar_6324;
	BIT_VEC cppVar_6325;
	bool cppVar_6326;
	BIT_VEC cppVar_6327;
	BIT_VEC cppVar_6328;
	BIT_VEC cppVar_6329;
	BIT_VEC cppVar_6331;
	BIT_VEC cppVar_6332;
	BIT_VEC cppVar_6333;
	bool cppVar_6334;
	BIT_VEC cppVar_6336;
	BIT_VEC cppVar_6337;
	BIT_VEC cppVar_6338;
	bool cppVar_6339;
	BIT_VEC cppVar_6341;
	BIT_VEC cppVar_6342;
	BIT_VEC cppVar_6343;
	bool cppVar_6344;
	BIT_VEC cppVar_6346;
	BIT_VEC cppVar_6347;
	BIT_VEC cppVar_6348;
	bool cppVar_6349;
	BIT_VEC cppVar_6351;
	BIT_VEC cppVar_6352;
	BIT_VEC cppVar_6353;
	bool cppVar_6354;
	BIT_VEC cppVar_6356;
	BIT_VEC cppVar_6357;
	BIT_VEC cppVar_6358;
	bool cppVar_6359;
	BIT_VEC cppVar_6361;
	BIT_VEC cppVar_6362;
	BIT_VEC cppVar_6363;
	bool cppVar_6364;
	BIT_VEC cppVar_6366;
	BIT_VEC cppVar_6367;
	BIT_VEC cppVar_6368;
	bool cppVar_6369;
	BIT_VEC cppVar_6371;
	BIT_VEC cppVar_6372;
	BIT_VEC cppVar_6373;
	bool cppVar_6374;
	BIT_VEC cppVar_6376;
	BIT_VEC cppVar_6377;
	BIT_VEC cppVar_6378;
	bool cppVar_6379;
	BIT_VEC cppVar_6381;
	BIT_VEC cppVar_6382;
	BIT_VEC cppVar_6383;
	bool cppVar_6384;
	BIT_VEC cppVar_6386;
	BIT_VEC cppVar_6387;
	BIT_VEC cppVar_6388;
	bool cppVar_6389;
	BIT_VEC cppVar_6391;
	BIT_VEC cppVar_6392;
	BIT_VEC cppVar_6393;
	bool cppVar_6394;
	BIT_VEC cppVar_6396;
	BIT_VEC cppVar_6397;
	BIT_VEC cppVar_6398;
	bool cppVar_6399;
	BIT_VEC cppVar_6401;
	BIT_VEC cppVar_6402;
	BIT_VEC cppVar_6403;
	bool cppVar_6404;
	BIT_VEC cppVar_6406;
	BIT_VEC cppVar_6407;
	BIT_VEC cppVar_6408;
	bool cppVar_6409;
	BIT_VEC cppVar_6411;
	BIT_VEC cppVar_6412;
	BIT_VEC cppVar_6413;
	bool cppVar_6414;
	BIT_VEC cppVar_6416;
	BIT_VEC cppVar_6417;
	BIT_VEC cppVar_6418;
	bool cppVar_6419;
	BIT_VEC cppVar_6421;
	BIT_VEC cppVar_6422;
	BIT_VEC cppVar_6423;
	bool cppVar_6424;
	BIT_VEC cppVar_6426;
	BIT_VEC cppVar_6427;
	BIT_VEC cppVar_6428;
	bool cppVar_6429;
	BIT_VEC cppVar_6431;
	BIT_VEC cppVar_6432;
	BIT_VEC cppVar_6433;
	bool cppVar_6434;
	BIT_VEC cppVar_6435;
	BIT_VEC cppVar_6430;
	BIT_VEC cppVar_6425;
	BIT_VEC cppVar_6420;
	BIT_VEC cppVar_6415;
	BIT_VEC cppVar_6410;
	BIT_VEC cppVar_6405;
	BIT_VEC cppVar_6400;
	BIT_VEC cppVar_6395;
	BIT_VEC cppVar_6390;
	BIT_VEC cppVar_6385;
	BIT_VEC cppVar_6380;
	BIT_VEC cppVar_6375;
	BIT_VEC cppVar_6370;
	BIT_VEC cppVar_6365;
	BIT_VEC cppVar_6360;
	BIT_VEC cppVar_6355;
	BIT_VEC cppVar_6350;
	BIT_VEC cppVar_6345;
	BIT_VEC cppVar_6340;
	BIT_VEC cppVar_6335;
	BIT_VEC cppVar_6330;
	BIT_VEC cppVar_6321;
	BIT_VEC cppVar_6436;
	BIT_VEC cppVar_6437;
	BIT_VEC cppVar_6438;
	BIT_VEC cppVar_6439;
	BIT_VEC cppVar_6315;
	BIT_VEC cppVar_6441;
	BIT_VEC cppVar_6442;
	bool cppVar_6443;
	BIT_VEC cppVar_6445;
	BIT_VEC cppVar_6446;
	BIT_VEC cppVar_6447;
	BIT_VEC cppVar_6448;
	bool cppVar_6449;
	BIT_VEC cppVar_6451;
	BIT_VEC cppVar_6452;
	BIT_VEC cppVar_6453;
	BIT_VEC cppVar_6454;
	bool cppVar_6455;
	BIT_VEC cppVar_6456;
	BIT_VEC cppVar_6457;
	BIT_VEC cppVar_6458;
	BIT_VEC cppVar_6460;
	BIT_VEC cppVar_6461;
	BIT_VEC cppVar_6462;
	bool cppVar_6463;
	BIT_VEC cppVar_6465;
	BIT_VEC cppVar_6466;
	BIT_VEC cppVar_6467;
	bool cppVar_6468;
	BIT_VEC cppVar_6470;
	BIT_VEC cppVar_6471;
	BIT_VEC cppVar_6472;
	bool cppVar_6473;
	BIT_VEC cppVar_6475;
	BIT_VEC cppVar_6476;
	BIT_VEC cppVar_6477;
	bool cppVar_6478;
	BIT_VEC cppVar_6480;
	BIT_VEC cppVar_6481;
	BIT_VEC cppVar_6482;
	bool cppVar_6483;
	BIT_VEC cppVar_6485;
	BIT_VEC cppVar_6486;
	BIT_VEC cppVar_6487;
	bool cppVar_6488;
	BIT_VEC cppVar_6490;
	BIT_VEC cppVar_6491;
	BIT_VEC cppVar_6492;
	bool cppVar_6493;
	BIT_VEC cppVar_6495;
	BIT_VEC cppVar_6496;
	BIT_VEC cppVar_6497;
	bool cppVar_6498;
	BIT_VEC cppVar_6500;
	BIT_VEC cppVar_6501;
	BIT_VEC cppVar_6502;
	bool cppVar_6503;
	BIT_VEC cppVar_6505;
	BIT_VEC cppVar_6506;
	BIT_VEC cppVar_6507;
	bool cppVar_6508;
	BIT_VEC cppVar_6510;
	BIT_VEC cppVar_6511;
	BIT_VEC cppVar_6512;
	bool cppVar_6513;
	BIT_VEC cppVar_6515;
	BIT_VEC cppVar_6516;
	BIT_VEC cppVar_6517;
	bool cppVar_6518;
	BIT_VEC cppVar_6520;
	BIT_VEC cppVar_6521;
	BIT_VEC cppVar_6522;
	bool cppVar_6523;
	BIT_VEC cppVar_6525;
	BIT_VEC cppVar_6526;
	BIT_VEC cppVar_6527;
	bool cppVar_6528;
	BIT_VEC cppVar_6530;
	BIT_VEC cppVar_6531;
	BIT_VEC cppVar_6532;
	bool cppVar_6533;
	BIT_VEC cppVar_6535;
	BIT_VEC cppVar_6536;
	BIT_VEC cppVar_6537;
	bool cppVar_6538;
	BIT_VEC cppVar_6540;
	BIT_VEC cppVar_6541;
	BIT_VEC cppVar_6542;
	bool cppVar_6543;
	BIT_VEC cppVar_6545;
	BIT_VEC cppVar_6546;
	BIT_VEC cppVar_6547;
	bool cppVar_6548;
	BIT_VEC cppVar_6550;
	BIT_VEC cppVar_6551;
	BIT_VEC cppVar_6552;
	bool cppVar_6553;
	BIT_VEC cppVar_6555;
	BIT_VEC cppVar_6556;
	BIT_VEC cppVar_6557;
	bool cppVar_6558;
	BIT_VEC cppVar_6560;
	BIT_VEC cppVar_6561;
	BIT_VEC cppVar_6562;
	bool cppVar_6563;
	BIT_VEC cppVar_6564;
	BIT_VEC cppVar_6559;
	BIT_VEC cppVar_6554;
	BIT_VEC cppVar_6549;
	BIT_VEC cppVar_6544;
	BIT_VEC cppVar_6539;
	BIT_VEC cppVar_6534;
	BIT_VEC cppVar_6529;
	BIT_VEC cppVar_6524;
	BIT_VEC cppVar_6519;
	BIT_VEC cppVar_6514;
	BIT_VEC cppVar_6509;
	BIT_VEC cppVar_6504;
	BIT_VEC cppVar_6499;
	BIT_VEC cppVar_6494;
	BIT_VEC cppVar_6489;
	BIT_VEC cppVar_6484;
	BIT_VEC cppVar_6479;
	BIT_VEC cppVar_6474;
	BIT_VEC cppVar_6469;
	BIT_VEC cppVar_6464;
	BIT_VEC cppVar_6459;
	BIT_VEC cppVar_6450;
	BIT_VEC cppVar_6565;
	BIT_VEC cppVar_6444;
	BIT_VEC cppVar_6567;
	BIT_VEC cppVar_6568;
	bool cppVar_6569;
	BIT_VEC cppVar_6571;
	BIT_VEC cppVar_6572;
	BIT_VEC cppVar_6573;
	BIT_VEC cppVar_6574;
	bool cppVar_6575;
	BIT_VEC cppVar_6577;
	BIT_VEC cppVar_6578;
	BIT_VEC cppVar_6579;
	BIT_VEC cppVar_6580;
	bool cppVar_6581;
	BIT_VEC cppVar_6582;
	BIT_VEC cppVar_6583;
	BIT_VEC cppVar_6584;
	BIT_VEC cppVar_6586;
	BIT_VEC cppVar_6587;
	BIT_VEC cppVar_6588;
	bool cppVar_6589;
	BIT_VEC cppVar_6591;
	BIT_VEC cppVar_6592;
	BIT_VEC cppVar_6593;
	bool cppVar_6594;
	BIT_VEC cppVar_6596;
	BIT_VEC cppVar_6597;
	BIT_VEC cppVar_6598;
	bool cppVar_6599;
	BIT_VEC cppVar_6601;
	BIT_VEC cppVar_6602;
	BIT_VEC cppVar_6603;
	bool cppVar_6604;
	BIT_VEC cppVar_6606;
	BIT_VEC cppVar_6607;
	BIT_VEC cppVar_6608;
	bool cppVar_6609;
	BIT_VEC cppVar_6611;
	BIT_VEC cppVar_6612;
	BIT_VEC cppVar_6613;
	bool cppVar_6614;
	BIT_VEC cppVar_6616;
	BIT_VEC cppVar_6617;
	BIT_VEC cppVar_6618;
	bool cppVar_6619;
	BIT_VEC cppVar_6621;
	BIT_VEC cppVar_6622;
	BIT_VEC cppVar_6623;
	bool cppVar_6624;
	BIT_VEC cppVar_6626;
	BIT_VEC cppVar_6627;
	BIT_VEC cppVar_6628;
	bool cppVar_6629;
	BIT_VEC cppVar_6631;
	BIT_VEC cppVar_6632;
	BIT_VEC cppVar_6633;
	bool cppVar_6634;
	BIT_VEC cppVar_6636;
	BIT_VEC cppVar_6637;
	BIT_VEC cppVar_6638;
	bool cppVar_6639;
	BIT_VEC cppVar_6641;
	BIT_VEC cppVar_6642;
	BIT_VEC cppVar_6643;
	bool cppVar_6644;
	BIT_VEC cppVar_6646;
	BIT_VEC cppVar_6647;
	BIT_VEC cppVar_6648;
	bool cppVar_6649;
	BIT_VEC cppVar_6651;
	BIT_VEC cppVar_6652;
	BIT_VEC cppVar_6653;
	bool cppVar_6654;
	BIT_VEC cppVar_6656;
	BIT_VEC cppVar_6657;
	BIT_VEC cppVar_6658;
	bool cppVar_6659;
	BIT_VEC cppVar_6661;
	BIT_VEC cppVar_6662;
	BIT_VEC cppVar_6663;
	bool cppVar_6664;
	BIT_VEC cppVar_6666;
	BIT_VEC cppVar_6667;
	BIT_VEC cppVar_6668;
	bool cppVar_6669;
	BIT_VEC cppVar_6671;
	BIT_VEC cppVar_6672;
	BIT_VEC cppVar_6673;
	bool cppVar_6674;
	BIT_VEC cppVar_6676;
	BIT_VEC cppVar_6677;
	BIT_VEC cppVar_6678;
	bool cppVar_6679;
	BIT_VEC cppVar_6681;
	BIT_VEC cppVar_6682;
	BIT_VEC cppVar_6683;
	bool cppVar_6684;
	BIT_VEC cppVar_6686;
	BIT_VEC cppVar_6687;
	BIT_VEC cppVar_6688;
	bool cppVar_6689;
	BIT_VEC cppVar_6690;
	BIT_VEC cppVar_6685;
	BIT_VEC cppVar_6680;
	BIT_VEC cppVar_6675;
	BIT_VEC cppVar_6670;
	BIT_VEC cppVar_6665;
	BIT_VEC cppVar_6660;
	BIT_VEC cppVar_6655;
	BIT_VEC cppVar_6650;
	BIT_VEC cppVar_6645;
	BIT_VEC cppVar_6640;
	BIT_VEC cppVar_6635;
	BIT_VEC cppVar_6630;
	BIT_VEC cppVar_6625;
	BIT_VEC cppVar_6620;
	BIT_VEC cppVar_6615;
	BIT_VEC cppVar_6610;
	BIT_VEC cppVar_6605;
	BIT_VEC cppVar_6600;
	BIT_VEC cppVar_6595;
	BIT_VEC cppVar_6590;
	BIT_VEC cppVar_6585;
	BIT_VEC cppVar_6576;
	BIT_VEC cppVar_6691;
	BIT_VEC cppVar_6692;
	BIT_VEC cppVar_6693;
	BIT_VEC cppVar_6694;
	BIT_VEC cppVar_6570;
	BIT_VEC cppVar_6696;
	BIT_VEC cppVar_6697;
	bool cppVar_6698;
	BIT_VEC cppVar_6700;
	BIT_VEC cppVar_6701;
	BIT_VEC cppVar_6702;
	BIT_VEC cppVar_6703;
	bool cppVar_6704;
	BIT_VEC cppVar_6706;
	BIT_VEC cppVar_6707;
	BIT_VEC cppVar_6708;
	BIT_VEC cppVar_6709;
	bool cppVar_6710;
	BIT_VEC cppVar_6711;
	BIT_VEC cppVar_6712;
	BIT_VEC cppVar_6713;
	BIT_VEC cppVar_6715;
	BIT_VEC cppVar_6716;
	BIT_VEC cppVar_6717;
	bool cppVar_6718;
	BIT_VEC cppVar_6720;
	BIT_VEC cppVar_6721;
	BIT_VEC cppVar_6722;
	bool cppVar_6723;
	BIT_VEC cppVar_6725;
	BIT_VEC cppVar_6726;
	BIT_VEC cppVar_6727;
	bool cppVar_6728;
	BIT_VEC cppVar_6730;
	BIT_VEC cppVar_6731;
	BIT_VEC cppVar_6732;
	bool cppVar_6733;
	BIT_VEC cppVar_6735;
	BIT_VEC cppVar_6736;
	BIT_VEC cppVar_6737;
	bool cppVar_6738;
	BIT_VEC cppVar_6740;
	BIT_VEC cppVar_6741;
	BIT_VEC cppVar_6742;
	bool cppVar_6743;
	BIT_VEC cppVar_6745;
	BIT_VEC cppVar_6746;
	BIT_VEC cppVar_6747;
	bool cppVar_6748;
	BIT_VEC cppVar_6750;
	BIT_VEC cppVar_6751;
	BIT_VEC cppVar_6752;
	bool cppVar_6753;
	BIT_VEC cppVar_6755;
	BIT_VEC cppVar_6756;
	BIT_VEC cppVar_6757;
	bool cppVar_6758;
	BIT_VEC cppVar_6760;
	BIT_VEC cppVar_6761;
	BIT_VEC cppVar_6762;
	bool cppVar_6763;
	BIT_VEC cppVar_6765;
	BIT_VEC cppVar_6766;
	BIT_VEC cppVar_6767;
	bool cppVar_6768;
	BIT_VEC cppVar_6770;
	BIT_VEC cppVar_6771;
	BIT_VEC cppVar_6772;
	bool cppVar_6773;
	BIT_VEC cppVar_6775;
	BIT_VEC cppVar_6776;
	BIT_VEC cppVar_6777;
	bool cppVar_6778;
	BIT_VEC cppVar_6780;
	BIT_VEC cppVar_6781;
	BIT_VEC cppVar_6782;
	bool cppVar_6783;
	BIT_VEC cppVar_6785;
	BIT_VEC cppVar_6786;
	BIT_VEC cppVar_6787;
	bool cppVar_6788;
	BIT_VEC cppVar_6790;
	BIT_VEC cppVar_6791;
	BIT_VEC cppVar_6792;
	bool cppVar_6793;
	BIT_VEC cppVar_6795;
	BIT_VEC cppVar_6796;
	BIT_VEC cppVar_6797;
	bool cppVar_6798;
	BIT_VEC cppVar_6800;
	BIT_VEC cppVar_6801;
	BIT_VEC cppVar_6802;
	bool cppVar_6803;
	BIT_VEC cppVar_6805;
	BIT_VEC cppVar_6806;
	BIT_VEC cppVar_6807;
	bool cppVar_6808;
	BIT_VEC cppVar_6810;
	BIT_VEC cppVar_6811;
	BIT_VEC cppVar_6812;
	bool cppVar_6813;
	BIT_VEC cppVar_6815;
	BIT_VEC cppVar_6816;
	BIT_VEC cppVar_6817;
	bool cppVar_6818;
	BIT_VEC cppVar_6819;
	BIT_VEC cppVar_6814;
	BIT_VEC cppVar_6809;
	BIT_VEC cppVar_6804;
	BIT_VEC cppVar_6799;
	BIT_VEC cppVar_6794;
	BIT_VEC cppVar_6789;
	BIT_VEC cppVar_6784;
	BIT_VEC cppVar_6779;
	BIT_VEC cppVar_6774;
	BIT_VEC cppVar_6769;
	BIT_VEC cppVar_6764;
	BIT_VEC cppVar_6759;
	BIT_VEC cppVar_6754;
	BIT_VEC cppVar_6749;
	BIT_VEC cppVar_6744;
	BIT_VEC cppVar_6739;
	BIT_VEC cppVar_6734;
	BIT_VEC cppVar_6729;
	BIT_VEC cppVar_6724;
	BIT_VEC cppVar_6719;
	BIT_VEC cppVar_6714;
	BIT_VEC cppVar_6705;
	BIT_VEC cppVar_6820;
	BIT_VEC cppVar_6699;
	BIT_VEC cppVar_6822;
	BIT_VEC cppVar_6823;
	bool cppVar_6824;
	BIT_VEC cppVar_6825;
	BIT_VEC cppVar_6826;
	bool cppVar_6827;
	bool cppVar_6828;
	BIT_VEC cppVar_6830;
	BIT_VEC cppVar_6831;
	BIT_VEC cppVar_6832;
	BIT_VEC cppVar_6833;
	bool cppVar_6834;
	BIT_VEC cppVar_6836;
	BIT_VEC cppVar_6837;
	BIT_VEC cppVar_6838;
	BIT_VEC cppVar_6839;
	bool cppVar_6840;
	BIT_VEC cppVar_6841;
	BIT_VEC cppVar_6842;
	BIT_VEC cppVar_6843;
	BIT_VEC cppVar_6845;
	BIT_VEC cppVar_6846;
	BIT_VEC cppVar_6847;
	bool cppVar_6848;
	BIT_VEC cppVar_6850;
	BIT_VEC cppVar_6851;
	BIT_VEC cppVar_6852;
	bool cppVar_6853;
	BIT_VEC cppVar_6855;
	BIT_VEC cppVar_6856;
	BIT_VEC cppVar_6857;
	bool cppVar_6858;
	BIT_VEC cppVar_6860;
	BIT_VEC cppVar_6861;
	BIT_VEC cppVar_6862;
	bool cppVar_6863;
	BIT_VEC cppVar_6865;
	BIT_VEC cppVar_6866;
	BIT_VEC cppVar_6867;
	bool cppVar_6868;
	BIT_VEC cppVar_6870;
	BIT_VEC cppVar_6871;
	BIT_VEC cppVar_6872;
	bool cppVar_6873;
	BIT_VEC cppVar_6875;
	BIT_VEC cppVar_6876;
	BIT_VEC cppVar_6877;
	bool cppVar_6878;
	BIT_VEC cppVar_6880;
	BIT_VEC cppVar_6881;
	BIT_VEC cppVar_6882;
	bool cppVar_6883;
	BIT_VEC cppVar_6885;
	BIT_VEC cppVar_6886;
	BIT_VEC cppVar_6887;
	bool cppVar_6888;
	BIT_VEC cppVar_6890;
	BIT_VEC cppVar_6891;
	BIT_VEC cppVar_6892;
	bool cppVar_6893;
	BIT_VEC cppVar_6895;
	BIT_VEC cppVar_6896;
	BIT_VEC cppVar_6897;
	bool cppVar_6898;
	BIT_VEC cppVar_6900;
	BIT_VEC cppVar_6901;
	BIT_VEC cppVar_6902;
	bool cppVar_6903;
	BIT_VEC cppVar_6905;
	BIT_VEC cppVar_6906;
	BIT_VEC cppVar_6907;
	bool cppVar_6908;
	BIT_VEC cppVar_6910;
	BIT_VEC cppVar_6911;
	BIT_VEC cppVar_6912;
	bool cppVar_6913;
	BIT_VEC cppVar_6915;
	BIT_VEC cppVar_6916;
	BIT_VEC cppVar_6917;
	bool cppVar_6918;
	BIT_VEC cppVar_6920;
	BIT_VEC cppVar_6921;
	BIT_VEC cppVar_6922;
	bool cppVar_6923;
	BIT_VEC cppVar_6925;
	BIT_VEC cppVar_6926;
	BIT_VEC cppVar_6927;
	bool cppVar_6928;
	BIT_VEC cppVar_6930;
	BIT_VEC cppVar_6931;
	BIT_VEC cppVar_6932;
	bool cppVar_6933;
	BIT_VEC cppVar_6935;
	BIT_VEC cppVar_6936;
	BIT_VEC cppVar_6937;
	bool cppVar_6938;
	BIT_VEC cppVar_6940;
	BIT_VEC cppVar_6941;
	BIT_VEC cppVar_6942;
	bool cppVar_6943;
	BIT_VEC cppVar_6945;
	BIT_VEC cppVar_6946;
	BIT_VEC cppVar_6947;
	bool cppVar_6948;
	BIT_VEC cppVar_6949;
	BIT_VEC cppVar_6944;
	BIT_VEC cppVar_6939;
	BIT_VEC cppVar_6934;
	BIT_VEC cppVar_6929;
	BIT_VEC cppVar_6924;
	BIT_VEC cppVar_6919;
	BIT_VEC cppVar_6914;
	BIT_VEC cppVar_6909;
	BIT_VEC cppVar_6904;
	BIT_VEC cppVar_6899;
	BIT_VEC cppVar_6894;
	BIT_VEC cppVar_6889;
	BIT_VEC cppVar_6884;
	BIT_VEC cppVar_6879;
	BIT_VEC cppVar_6874;
	BIT_VEC cppVar_6869;
	BIT_VEC cppVar_6864;
	BIT_VEC cppVar_6859;
	BIT_VEC cppVar_6854;
	BIT_VEC cppVar_6849;
	BIT_VEC cppVar_6844;
	BIT_VEC cppVar_6835;
	BIT_VEC cppVar_6950;
	BIT_VEC cppVar_6951;
	BIT_VEC cppVar_6829;
	BIT_VEC cppVar_6953;
	BIT_VEC cppVar_6954;
	bool cppVar_6955;
	BIT_VEC cppVar_6956;
	BIT_VEC cppVar_6957;
	bool cppVar_6958;
	bool cppVar_6959;
	BIT_VEC cppVar_6962;
	BIT_VEC cppVar_6963;
	BIT_VEC cppVar_6964;
	BIT_VEC cppVar_6965;
	BIT_VEC cppVar_6966;
	bool cppVar_6967;
	BIT_VEC cppVar_6968;
	BIT_VEC cppVar_6969;
	BIT_VEC cppVar_6970;
	BIT_VEC cppVar_6971;
	BIT_VEC cppVar_6972;
	BIT_VEC cppVar_6973;
	BIT_VEC cppVar_6974;
	BIT_VEC cppVar_6975;
	BIT_VEC cppVar_6976;
	BIT_VEC cppVar_6977;
	BIT_VEC cppVar_6978;
	BIT_VEC cppVar_6961;
	BIT_VEC cppVar_6979;
	bool cppVar_6980;
	BIT_VEC cppVar_6981;
	BIT_VEC cppVar_6982;
	BIT_VEC cppVar_6983;
	BIT_VEC cppVar_6984;
	BIT_VEC cppVar_6985;
	BIT_VEC cppVar_6986;
	BIT_VEC cppVar_6987;
	BIT_VEC cppVar_6990;
	BIT_VEC cppVar_6991;
	BIT_VEC cppVar_6992;
	bool cppVar_6993;
	BIT_VEC cppVar_6994;
	BIT_VEC cppVar_6995;
	BIT_VEC cppVar_6996;
	BIT_VEC cppVar_6997;
	BIT_VEC cppVar_6998;
	BIT_VEC cppVar_6999;
	BIT_VEC cppVar_7000;
	BIT_VEC cppVar_7001;
	BIT_VEC cppVar_7002;
	BIT_VEC cppVar_6989;
	BIT_VEC cppVar_7003;
	BIT_VEC cppVar_7004;
	bool cppVar_7005;
	BIT_VEC cppVar_7007;
	BIT_VEC cppVar_7008;
	BIT_VEC cppVar_7009;
	bool cppVar_7010;
	BIT_VEC cppVar_7011;
	BIT_VEC cppVar_7012;
	BIT_VEC cppVar_7013;
	BIT_VEC cppVar_7014;
	BIT_VEC cppVar_7015;
	BIT_VEC cppVar_7016;
	BIT_VEC cppVar_7017;
	BIT_VEC cppVar_7018;
	BIT_VEC cppVar_7019;
	BIT_VEC cppVar_7006;
	BIT_VEC cppVar_7020;
	BIT_VEC cppVar_7023;
	BIT_VEC cppVar_7024;
	BIT_VEC cppVar_7025;
	bool cppVar_7026;
	BIT_VEC cppVar_7027;
	BIT_VEC cppVar_7028;
	BIT_VEC cppVar_7029;
	BIT_VEC cppVar_7030;
	BIT_VEC cppVar_7031;
	BIT_VEC cppVar_7032;
	BIT_VEC cppVar_7033;
	BIT_VEC cppVar_7034;
	BIT_VEC cppVar_7035;
	BIT_VEC cppVar_7022;
	BIT_VEC cppVar_7036;
	bool cppVar_7037;
	BIT_VEC cppVar_7040;
	BIT_VEC cppVar_7041;
	BIT_VEC cppVar_7042;
	bool cppVar_7043;
	BIT_VEC cppVar_7044;
	BIT_VEC cppVar_7045;
	BIT_VEC cppVar_7046;
	BIT_VEC cppVar_7047;
	BIT_VEC cppVar_7048;
	BIT_VEC cppVar_7049;
	BIT_VEC cppVar_7050;
	BIT_VEC cppVar_7051;
	BIT_VEC cppVar_7052;
	BIT_VEC cppVar_7039;
	BIT_VEC cppVar_7053;
	bool cppVar_7054;
	BIT_VEC cppVar_7057;
	BIT_VEC cppVar_7058;
	BIT_VEC cppVar_7059;
	bool cppVar_7060;
	BIT_VEC cppVar_7061;
	BIT_VEC cppVar_7062;
	BIT_VEC cppVar_7063;
	BIT_VEC cppVar_7064;
	BIT_VEC cppVar_7065;
	BIT_VEC cppVar_7066;
	BIT_VEC cppVar_7067;
	BIT_VEC cppVar_7068;
	BIT_VEC cppVar_7069;
	BIT_VEC cppVar_7056;
	BIT_VEC cppVar_7070;
	bool cppVar_7071;
	BIT_VEC cppVar_7074;
	BIT_VEC cppVar_7075;
	BIT_VEC cppVar_7076;
	bool cppVar_7077;
	BIT_VEC cppVar_7078;
	BIT_VEC cppVar_7079;
	BIT_VEC cppVar_7080;
	BIT_VEC cppVar_7081;
	BIT_VEC cppVar_7082;
	BIT_VEC cppVar_7083;
	BIT_VEC cppVar_7084;
	BIT_VEC cppVar_7085;
	BIT_VEC cppVar_7086;
	BIT_VEC cppVar_7073;
	BIT_VEC cppVar_7087;
	bool cppVar_7088;
	BIT_VEC cppVar_7091;
	BIT_VEC cppVar_7092;
	BIT_VEC cppVar_7093;
	bool cppVar_7094;
	BIT_VEC cppVar_7095;
	BIT_VEC cppVar_7096;
	BIT_VEC cppVar_7097;
	BIT_VEC cppVar_7098;
	BIT_VEC cppVar_7099;
	BIT_VEC cppVar_7100;
	BIT_VEC cppVar_7101;
	BIT_VEC cppVar_7102;
	BIT_VEC cppVar_7103;
	BIT_VEC cppVar_7090;
	BIT_VEC cppVar_7104;
	bool cppVar_7105;
	BIT_VEC cppVar_7108;
	BIT_VEC cppVar_7109;
	BIT_VEC cppVar_7110;
	bool cppVar_7111;
	BIT_VEC cppVar_7112;
	BIT_VEC cppVar_7113;
	BIT_VEC cppVar_7114;
	BIT_VEC cppVar_7115;
	BIT_VEC cppVar_7116;
	BIT_VEC cppVar_7117;
	BIT_VEC cppVar_7118;
	BIT_VEC cppVar_7119;
	BIT_VEC cppVar_7120;
	BIT_VEC cppVar_7107;
	BIT_VEC cppVar_7121;
	bool cppVar_7122;
	BIT_VEC cppVar_7125;
	BIT_VEC cppVar_7126;
	BIT_VEC cppVar_7127;
	bool cppVar_7128;
	BIT_VEC cppVar_7129;
	BIT_VEC cppVar_7130;
	BIT_VEC cppVar_7131;
	BIT_VEC cppVar_7132;
	BIT_VEC cppVar_7133;
	BIT_VEC cppVar_7134;
	BIT_VEC cppVar_7135;
	BIT_VEC cppVar_7136;
	BIT_VEC cppVar_7137;
	BIT_VEC cppVar_7124;
	BIT_VEC cppVar_7138;
	bool cppVar_7139;
	BIT_VEC cppVar_7142;
	BIT_VEC cppVar_7143;
	BIT_VEC cppVar_7144;
	bool cppVar_7145;
	BIT_VEC cppVar_7146;
	BIT_VEC cppVar_7147;
	BIT_VEC cppVar_7148;
	BIT_VEC cppVar_7149;
	BIT_VEC cppVar_7150;
	BIT_VEC cppVar_7151;
	BIT_VEC cppVar_7152;
	BIT_VEC cppVar_7153;
	BIT_VEC cppVar_7154;
	BIT_VEC cppVar_7141;
	BIT_VEC cppVar_7155;
	bool cppVar_7156;
	BIT_VEC cppVar_7159;
	BIT_VEC cppVar_7160;
	BIT_VEC cppVar_7161;
	bool cppVar_7162;
	BIT_VEC cppVar_7163;
	BIT_VEC cppVar_7164;
	BIT_VEC cppVar_7165;
	BIT_VEC cppVar_7166;
	BIT_VEC cppVar_7167;
	BIT_VEC cppVar_7168;
	BIT_VEC cppVar_7169;
	BIT_VEC cppVar_7170;
	BIT_VEC cppVar_7171;
	BIT_VEC cppVar_7158;
	BIT_VEC cppVar_7172;
	bool cppVar_7173;
	BIT_VEC cppVar_7176;
	BIT_VEC cppVar_7177;
	BIT_VEC cppVar_7178;
	bool cppVar_7179;
	BIT_VEC cppVar_7180;
	BIT_VEC cppVar_7181;
	BIT_VEC cppVar_7182;
	BIT_VEC cppVar_7183;
	BIT_VEC cppVar_7184;
	BIT_VEC cppVar_7185;
	BIT_VEC cppVar_7186;
	BIT_VEC cppVar_7187;
	BIT_VEC cppVar_7188;
	BIT_VEC cppVar_7175;
	BIT_VEC cppVar_7189;
	bool cppVar_7190;
	BIT_VEC cppVar_7193;
	BIT_VEC cppVar_7194;
	BIT_VEC cppVar_7195;
	bool cppVar_7196;
	BIT_VEC cppVar_7197;
	BIT_VEC cppVar_7198;
	BIT_VEC cppVar_7199;
	BIT_VEC cppVar_7200;
	BIT_VEC cppVar_7201;
	BIT_VEC cppVar_7202;
	BIT_VEC cppVar_7203;
	BIT_VEC cppVar_7204;
	BIT_VEC cppVar_7205;
	BIT_VEC cppVar_7192;
	BIT_VEC cppVar_7206;
	bool cppVar_7207;
	BIT_VEC cppVar_7210;
	BIT_VEC cppVar_7211;
	BIT_VEC cppVar_7212;
	bool cppVar_7213;
	BIT_VEC cppVar_7214;
	BIT_VEC cppVar_7215;
	BIT_VEC cppVar_7216;
	BIT_VEC cppVar_7217;
	BIT_VEC cppVar_7218;
	BIT_VEC cppVar_7219;
	BIT_VEC cppVar_7220;
	BIT_VEC cppVar_7221;
	BIT_VEC cppVar_7222;
	BIT_VEC cppVar_7209;
	BIT_VEC cppVar_7223;
	bool cppVar_7224;
	BIT_VEC cppVar_7227;
	BIT_VEC cppVar_7228;
	BIT_VEC cppVar_7229;
	bool cppVar_7230;
	BIT_VEC cppVar_7231;
	BIT_VEC cppVar_7232;
	BIT_VEC cppVar_7233;
	BIT_VEC cppVar_7234;
	BIT_VEC cppVar_7235;
	BIT_VEC cppVar_7236;
	BIT_VEC cppVar_7237;
	BIT_VEC cppVar_7238;
	BIT_VEC cppVar_7239;
	BIT_VEC cppVar_7226;
	BIT_VEC cppVar_7240;
	bool cppVar_7241;
	BIT_VEC cppVar_7244;
	BIT_VEC cppVar_7245;
	BIT_VEC cppVar_7246;
	bool cppVar_7247;
	BIT_VEC cppVar_7248;
	BIT_VEC cppVar_7249;
	BIT_VEC cppVar_7250;
	BIT_VEC cppVar_7251;
	BIT_VEC cppVar_7252;
	BIT_VEC cppVar_7253;
	BIT_VEC cppVar_7254;
	BIT_VEC cppVar_7255;
	BIT_VEC cppVar_7256;
	BIT_VEC cppVar_7243;
	BIT_VEC cppVar_7257;
	bool cppVar_7258;
	BIT_VEC cppVar_7261;
	BIT_VEC cppVar_7262;
	BIT_VEC cppVar_7263;
	bool cppVar_7264;
	BIT_VEC cppVar_7265;
	BIT_VEC cppVar_7266;
	BIT_VEC cppVar_7267;
	BIT_VEC cppVar_7268;
	BIT_VEC cppVar_7269;
	BIT_VEC cppVar_7270;
	BIT_VEC cppVar_7271;
	BIT_VEC cppVar_7272;
	BIT_VEC cppVar_7273;
	BIT_VEC cppVar_7260;
	BIT_VEC cppVar_7274;
	bool cppVar_7275;
	BIT_VEC cppVar_7278;
	BIT_VEC cppVar_7279;
	BIT_VEC cppVar_7280;
	bool cppVar_7281;
	BIT_VEC cppVar_7282;
	BIT_VEC cppVar_7283;
	BIT_VEC cppVar_7284;
	BIT_VEC cppVar_7285;
	BIT_VEC cppVar_7286;
	BIT_VEC cppVar_7287;
	BIT_VEC cppVar_7288;
	BIT_VEC cppVar_7289;
	BIT_VEC cppVar_7290;
	BIT_VEC cppVar_7277;
	BIT_VEC cppVar_7291;
	bool cppVar_7292;
	BIT_VEC cppVar_7295;
	BIT_VEC cppVar_7296;
	BIT_VEC cppVar_7297;
	bool cppVar_7298;
	BIT_VEC cppVar_7299;
	BIT_VEC cppVar_7300;
	BIT_VEC cppVar_7301;
	BIT_VEC cppVar_7302;
	BIT_VEC cppVar_7303;
	BIT_VEC cppVar_7304;
	BIT_VEC cppVar_7305;
	BIT_VEC cppVar_7306;
	BIT_VEC cppVar_7307;
	BIT_VEC cppVar_7294;
	BIT_VEC cppVar_7308;
	bool cppVar_7309;
	BIT_VEC cppVar_7312;
	BIT_VEC cppVar_7313;
	BIT_VEC cppVar_7314;
	bool cppVar_7315;
	BIT_VEC cppVar_7316;
	BIT_VEC cppVar_7317;
	BIT_VEC cppVar_7318;
	BIT_VEC cppVar_7319;
	BIT_VEC cppVar_7320;
	BIT_VEC cppVar_7321;
	BIT_VEC cppVar_7322;
	BIT_VEC cppVar_7323;
	BIT_VEC cppVar_7324;
	BIT_VEC cppVar_7311;
	BIT_VEC cppVar_7325;
	bool cppVar_7326;
	BIT_VEC cppVar_7329;
	BIT_VEC cppVar_7330;
	BIT_VEC cppVar_7331;
	bool cppVar_7332;
	BIT_VEC cppVar_7333;
	BIT_VEC cppVar_7334;
	BIT_VEC cppVar_7335;
	BIT_VEC cppVar_7336;
	BIT_VEC cppVar_7337;
	BIT_VEC cppVar_7338;
	BIT_VEC cppVar_7339;
	BIT_VEC cppVar_7340;
	BIT_VEC cppVar_7341;
	BIT_VEC cppVar_7328;
	BIT_VEC cppVar_7342;
	bool cppVar_7343;
	BIT_VEC cppVar_7346;
	BIT_VEC cppVar_7347;
	BIT_VEC cppVar_7348;
	bool cppVar_7349;
	BIT_VEC cppVar_7350;
	BIT_VEC cppVar_7351;
	BIT_VEC cppVar_7352;
	BIT_VEC cppVar_7353;
	BIT_VEC cppVar_7354;
	BIT_VEC cppVar_7355;
	BIT_VEC cppVar_7356;
	BIT_VEC cppVar_7357;
	BIT_VEC cppVar_7358;
	BIT_VEC cppVar_7345;
	BIT_VEC cppVar_7359;
	bool cppVar_7360;
	BIT_VEC cppVar_7363;
	BIT_VEC cppVar_7364;
	BIT_VEC cppVar_7365;
	bool cppVar_7366;
	BIT_VEC cppVar_7367;
	BIT_VEC cppVar_7368;
	BIT_VEC cppVar_7369;
	BIT_VEC cppVar_7370;
	BIT_VEC cppVar_7371;
	BIT_VEC cppVar_7372;
	BIT_VEC cppVar_7373;
	BIT_VEC cppVar_7374;
	BIT_VEC cppVar_7375;
	BIT_VEC cppVar_7362;
	BIT_VEC cppVar_7376;
	bool cppVar_7377;
	BIT_VEC cppVar_7378;
	BIT_VEC cppVar_7361;
	BIT_VEC cppVar_7344;
	BIT_VEC cppVar_7327;
	BIT_VEC cppVar_7310;
	BIT_VEC cppVar_7293;
	BIT_VEC cppVar_7276;
	BIT_VEC cppVar_7259;
	BIT_VEC cppVar_7242;
	BIT_VEC cppVar_7225;
	BIT_VEC cppVar_7208;
	BIT_VEC cppVar_7191;
	BIT_VEC cppVar_7174;
	BIT_VEC cppVar_7157;
	BIT_VEC cppVar_7140;
	BIT_VEC cppVar_7123;
	BIT_VEC cppVar_7106;
	BIT_VEC cppVar_7089;
	BIT_VEC cppVar_7072;
	BIT_VEC cppVar_7055;
	BIT_VEC cppVar_7038;
	BIT_VEC cppVar_7021;
	BIT_VEC cppVar_6988;
	BIT_VEC cppVar_7379;
	BIT_VEC cppVar_7380;
	BIT_VEC cppVar_7381;
	BIT_VEC cppVar_7382;
	BIT_VEC cppVar_7383;
	BIT_VEC cppVar_7384;
	BIT_VEC cppVar_7385;
	BIT_VEC cppVar_7386;
	BIT_VEC cppVar_7387;
	BIT_VEC cppVar_6960;
	BIT_VEC cppVar_7389;
	BIT_VEC cppVar_7390;
	bool cppVar_7391;
	BIT_VEC cppVar_7393;
	BIT_VEC cppVar_7394;
	BIT_VEC cppVar_7395;
	BIT_VEC cppVar_7396;
	bool cppVar_7397;
	BIT_VEC cppVar_7399;
	BIT_VEC cppVar_7400;
	BIT_VEC cppVar_7401;
	BIT_VEC cppVar_7402;
	bool cppVar_7403;
	BIT_VEC cppVar_7404;
	BIT_VEC cppVar_7405;
	BIT_VEC cppVar_7406;
	BIT_VEC cppVar_7408;
	BIT_VEC cppVar_7409;
	BIT_VEC cppVar_7410;
	bool cppVar_7411;
	BIT_VEC cppVar_7413;
	BIT_VEC cppVar_7414;
	BIT_VEC cppVar_7415;
	bool cppVar_7416;
	BIT_VEC cppVar_7418;
	BIT_VEC cppVar_7419;
	BIT_VEC cppVar_7420;
	bool cppVar_7421;
	BIT_VEC cppVar_7423;
	BIT_VEC cppVar_7424;
	BIT_VEC cppVar_7425;
	bool cppVar_7426;
	BIT_VEC cppVar_7428;
	BIT_VEC cppVar_7429;
	BIT_VEC cppVar_7430;
	bool cppVar_7431;
	BIT_VEC cppVar_7433;
	BIT_VEC cppVar_7434;
	BIT_VEC cppVar_7435;
	bool cppVar_7436;
	BIT_VEC cppVar_7438;
	BIT_VEC cppVar_7439;
	BIT_VEC cppVar_7440;
	bool cppVar_7441;
	BIT_VEC cppVar_7443;
	BIT_VEC cppVar_7444;
	BIT_VEC cppVar_7445;
	bool cppVar_7446;
	BIT_VEC cppVar_7448;
	BIT_VEC cppVar_7449;
	BIT_VEC cppVar_7450;
	bool cppVar_7451;
	BIT_VEC cppVar_7453;
	BIT_VEC cppVar_7454;
	BIT_VEC cppVar_7455;
	bool cppVar_7456;
	BIT_VEC cppVar_7458;
	BIT_VEC cppVar_7459;
	BIT_VEC cppVar_7460;
	bool cppVar_7461;
	BIT_VEC cppVar_7463;
	BIT_VEC cppVar_7464;
	BIT_VEC cppVar_7465;
	bool cppVar_7466;
	BIT_VEC cppVar_7468;
	BIT_VEC cppVar_7469;
	BIT_VEC cppVar_7470;
	bool cppVar_7471;
	BIT_VEC cppVar_7473;
	BIT_VEC cppVar_7474;
	BIT_VEC cppVar_7475;
	bool cppVar_7476;
	BIT_VEC cppVar_7478;
	BIT_VEC cppVar_7479;
	BIT_VEC cppVar_7480;
	bool cppVar_7481;
	BIT_VEC cppVar_7483;
	BIT_VEC cppVar_7484;
	BIT_VEC cppVar_7485;
	bool cppVar_7486;
	BIT_VEC cppVar_7488;
	BIT_VEC cppVar_7489;
	BIT_VEC cppVar_7490;
	bool cppVar_7491;
	BIT_VEC cppVar_7493;
	BIT_VEC cppVar_7494;
	BIT_VEC cppVar_7495;
	bool cppVar_7496;
	BIT_VEC cppVar_7498;
	BIT_VEC cppVar_7499;
	BIT_VEC cppVar_7500;
	bool cppVar_7501;
	BIT_VEC cppVar_7503;
	BIT_VEC cppVar_7504;
	BIT_VEC cppVar_7505;
	bool cppVar_7506;
	BIT_VEC cppVar_7508;
	BIT_VEC cppVar_7509;
	BIT_VEC cppVar_7510;
	bool cppVar_7511;
	BIT_VEC cppVar_7512;
	BIT_VEC cppVar_7507;
	BIT_VEC cppVar_7502;
	BIT_VEC cppVar_7497;
	BIT_VEC cppVar_7492;
	BIT_VEC cppVar_7487;
	BIT_VEC cppVar_7482;
	BIT_VEC cppVar_7477;
	BIT_VEC cppVar_7472;
	BIT_VEC cppVar_7467;
	BIT_VEC cppVar_7462;
	BIT_VEC cppVar_7457;
	BIT_VEC cppVar_7452;
	BIT_VEC cppVar_7447;
	BIT_VEC cppVar_7442;
	BIT_VEC cppVar_7437;
	BIT_VEC cppVar_7432;
	BIT_VEC cppVar_7427;
	BIT_VEC cppVar_7422;
	BIT_VEC cppVar_7417;
	BIT_VEC cppVar_7412;
	BIT_VEC cppVar_7407;
	BIT_VEC cppVar_7398;
	BIT_VEC cppVar_7513;
	BIT_VEC cppVar_7514;
	BIT_VEC cppVar_7392;
	BIT_VEC cppVar_7388;
	BIT_VEC cppVar_6952;
	BIT_VEC cppVar_6821;
	BIT_VEC cppVar_6695;
	BIT_VEC cppVar_6566;
	BIT_VEC cppVar_6440;
	BIT_VEC cppVar_6311;
	BIT_VEC cppVar_6185;
	BIT_VEC cppVar_6056;
	BIT_VEC cppVar_6043;
	BIT_VEC cppVar_6035;
	BIT_VEC cppVar_5909;
	BIT_VEC cppVar_5892;
	BIT_VEC cppVar_5875;
	BIT_VEC cppVar_5725;
	BIT_VEC cppVar_5575;
	BIT_VEC cppVar_5425;
	BIT_VEC cppVar_5275;
	BIT_VEC cppVar_5125;
	BIT_VEC cppVar_4975;
	BIT_VEC cppVar_4825;
	BIT_VEC cppVar_4675;
	BIT_VEC cppVar_4243;
	BIT_VEC cppVar_4235;
	BIT_VEC cppVar_3405;
	BIT_VEC cppVar_3391;
	BIT_VEC cppVar_3380;
	BIT_VEC cppVar_2948;
	cppVar_2949 = ROM.rd(PC);
	cppVar_2951 = (cppVar_2949 == 210);
	if (cppVar_2951) {
	cppVar_2955 = PC + 1;
	cppVar_2955 = (cppVar_2955 & cppMask_un_16_);
	cppVar_2956 = ROM.rd(cppVar_2955);
	cppVar_2957 = (cppVar_2956 >> 7) & cppMask_un_1_;
	cppVar_2959 = (cppVar_2957 == 1);
	if (cppVar_2959) {
	cppVar_2960 = PC + 1;
	cppVar_2960 = (cppVar_2960 & cppMask_un_16_);
	cppVar_2961 = ROM.rd(cppVar_2960);
	cppVar_2962 = (cppVar_2961 >> 3) & cppMask_un_5_;
	cppVar_2964 = (cppVar_2962 << 3) | 0;
	cppVar_2964 = (cppVar_2964 & cppMask_un_8_);
	cppVar_2953 = cppVar_2964;
	} else {
	cppVar_2965 = PC + 1;
	cppVar_2965 = (cppVar_2965 & cppMask_un_16_);
	cppVar_2966 = ROM.rd(cppVar_2965);
	cppVar_2967 = (cppVar_2966 >> 3) & cppMask_un_5_;
	cppVar_2968 = (cppVar_2967 & cppMask_un_5_);
	cppVar_2970 = cppVar_2968 + 32;
	cppVar_2970 = (cppVar_2970 & cppMask_un_8_);
	cppVar_2953 = cppVar_2970;
	}
	cppVar_2972 = (cppVar_2953 == 240);
	if (cppVar_2972) {
	cppVar_2974 = PC + 1;
	cppVar_2974 = (cppVar_2974 & cppMask_un_16_);
	cppVar_2975 = ROM.rd(cppVar_2974);
	cppVar_2976 = (cppVar_2975 >> 0) & cppMask_un_3_;
	cppVar_2977 = (cppVar_2976 & cppMask_un_3_);
	cppVar_2978 = 1 << static_cast<unsigned>(cppVar_2977);
	cppVar_2978 = (cppVar_2978 & cppMask_un_8_);
	cppVar_2979 = ~cppVar_2978;
	cppVar_2982 = PC + 1;
	cppVar_2982 = (cppVar_2982 & cppMask_un_16_);
	cppVar_2983 = ROM.rd(cppVar_2982);
	cppVar_2984 = (cppVar_2983 >> 7) & cppMask_un_1_;
	cppVar_2985 = (cppVar_2984 == 1);
	if (cppVar_2985) {
	cppVar_2986 = PC + 1;
	cppVar_2986 = (cppVar_2986 & cppMask_un_16_);
	cppVar_2987 = ROM.rd(cppVar_2986);
	cppVar_2988 = (cppVar_2987 >> 3) & cppMask_un_5_;
	cppVar_2989 = (cppVar_2988 << 3) | 0;
	cppVar_2989 = (cppVar_2989 & cppMask_un_8_);
	cppVar_2981 = cppVar_2989;
	} else {
	cppVar_2990 = PC + 1;
	cppVar_2990 = (cppVar_2990 & cppMask_un_16_);
	cppVar_2991 = ROM.rd(cppVar_2990);
	cppVar_2992 = (cppVar_2991 >> 3) & cppMask_un_5_;
	cppVar_2993 = (cppVar_2992 & cppMask_un_5_);
	cppVar_2994 = cppVar_2993 + 32;
	cppVar_2994 = (cppVar_2994 & cppMask_un_8_);
	cppVar_2981 = cppVar_2994;
	}
	cppVar_2995 = (cppVar_2981 >> 7) & cppMask_un_1_;
	cppVar_2997 = (cppVar_2995 == 0);
	if (cppVar_2997) {
	cppVar_2999 = PC + 1;
	cppVar_2999 = (cppVar_2999 & cppMask_un_16_);
	cppVar_3000 = ROM.rd(cppVar_2999);
	cppVar_3001 = (cppVar_3000 >> 7) & cppMask_un_1_;
	cppVar_3002 = (cppVar_3001 == 1);
	if (cppVar_3002) {
	cppVar_3003 = PC + 1;
	cppVar_3003 = (cppVar_3003 & cppMask_un_16_);
	cppVar_3004 = ROM.rd(cppVar_3003);
	cppVar_3005 = (cppVar_3004 >> 3) & cppMask_un_5_;
	cppVar_3006 = (cppVar_3005 << 3) | 0;
	cppVar_3006 = (cppVar_3006 & cppMask_un_8_);
	cppVar_2998 = cppVar_3006;
	} else {
	cppVar_3007 = PC + 1;
	cppVar_3007 = (cppVar_3007 & cppMask_un_16_);
	cppVar_3008 = ROM.rd(cppVar_3007);
	cppVar_3009 = (cppVar_3008 >> 3) & cppMask_un_5_;
	cppVar_3010 = (cppVar_3009 & cppMask_un_5_);
	cppVar_3011 = cppVar_3010 + 32;
	cppVar_3011 = (cppVar_3011 & cppMask_un_8_);
	cppVar_2998 = cppVar_3011;
	}
	cppVar_3012 = IRAM.rd(cppVar_2998);
	cppVar_2980 = cppVar_3012;
	} else {
	cppVar_3015 = PC + 1;
	cppVar_3015 = (cppVar_3015 & cppMask_un_16_);
	cppVar_3016 = ROM.rd(cppVar_3015);
	cppVar_3017 = (cppVar_3016 >> 7) & cppMask_un_1_;
	cppVar_3018 = (cppVar_3017 == 1);
	if (cppVar_3018) {
	cppVar_3019 = PC + 1;
	cppVar_3019 = (cppVar_3019 & cppMask_un_16_);
	cppVar_3020 = ROM.rd(cppVar_3019);
	cppVar_3021 = (cppVar_3020 >> 3) & cppMask_un_5_;
	cppVar_3022 = (cppVar_3021 << 3) | 0;
	cppVar_3022 = (cppVar_3022 & cppMask_un_8_);
	cppVar_3014 = cppVar_3022;
	} else {
	cppVar_3023 = PC + 1;
	cppVar_3023 = (cppVar_3023 & cppMask_un_16_);
	cppVar_3024 = ROM.rd(cppVar_3023);
	cppVar_3025 = (cppVar_3024 >> 3) & cppMask_un_5_;
	cppVar_3026 = (cppVar_3025 & cppMask_un_5_);
	cppVar_3027 = cppVar_3026 + 32;
	cppVar_3027 = (cppVar_3027 & cppMask_un_8_);
	cppVar_3014 = cppVar_3027;
	}
	cppVar_3029 = (cppVar_3014 == 128);
	if (cppVar_3029) {
	cppVar_3013 = P0;
	} else {
	cppVar_3032 = PC + 1;
	cppVar_3032 = (cppVar_3032 & cppMask_un_16_);
	cppVar_3033 = ROM.rd(cppVar_3032);
	cppVar_3034 = (cppVar_3033 >> 7) & cppMask_un_1_;
	cppVar_3035 = (cppVar_3034 == 1);
	if (cppVar_3035) {
	cppVar_3036 = PC + 1;
	cppVar_3036 = (cppVar_3036 & cppMask_un_16_);
	cppVar_3037 = ROM.rd(cppVar_3036);
	cppVar_3038 = (cppVar_3037 >> 3) & cppMask_un_5_;
	cppVar_3039 = (cppVar_3038 << 3) | 0;
	cppVar_3039 = (cppVar_3039 & cppMask_un_8_);
	cppVar_3031 = cppVar_3039;
	} else {
	cppVar_3040 = PC + 1;
	cppVar_3040 = (cppVar_3040 & cppMask_un_16_);
	cppVar_3041 = ROM.rd(cppVar_3040);
	cppVar_3042 = (cppVar_3041 >> 3) & cppMask_un_5_;
	cppVar_3043 = (cppVar_3042 & cppMask_un_5_);
	cppVar_3044 = cppVar_3043 + 32;
	cppVar_3044 = (cppVar_3044 & cppMask_un_8_);
	cppVar_3031 = cppVar_3044;
	}
	cppVar_3046 = (cppVar_3031 == 129);
	if (cppVar_3046) {
	cppVar_3030 = SP;
	} else {
	cppVar_3049 = PC + 1;
	cppVar_3049 = (cppVar_3049 & cppMask_un_16_);
	cppVar_3050 = ROM.rd(cppVar_3049);
	cppVar_3051 = (cppVar_3050 >> 7) & cppMask_un_1_;
	cppVar_3052 = (cppVar_3051 == 1);
	if (cppVar_3052) {
	cppVar_3053 = PC + 1;
	cppVar_3053 = (cppVar_3053 & cppMask_un_16_);
	cppVar_3054 = ROM.rd(cppVar_3053);
	cppVar_3055 = (cppVar_3054 >> 3) & cppMask_un_5_;
	cppVar_3056 = (cppVar_3055 << 3) | 0;
	cppVar_3056 = (cppVar_3056 & cppMask_un_8_);
	cppVar_3048 = cppVar_3056;
	} else {
	cppVar_3057 = PC + 1;
	cppVar_3057 = (cppVar_3057 & cppMask_un_16_);
	cppVar_3058 = ROM.rd(cppVar_3057);
	cppVar_3059 = (cppVar_3058 >> 3) & cppMask_un_5_;
	cppVar_3060 = (cppVar_3059 & cppMask_un_5_);
	cppVar_3061 = cppVar_3060 + 32;
	cppVar_3061 = (cppVar_3061 & cppMask_un_8_);
	cppVar_3048 = cppVar_3061;
	}
	cppVar_3063 = (cppVar_3048 == 130);
	if (cppVar_3063) {
	cppVar_3047 = DPL;
	} else {
	cppVar_3066 = PC + 1;
	cppVar_3066 = (cppVar_3066 & cppMask_un_16_);
	cppVar_3067 = ROM.rd(cppVar_3066);
	cppVar_3068 = (cppVar_3067 >> 7) & cppMask_un_1_;
	cppVar_3069 = (cppVar_3068 == 1);
	if (cppVar_3069) {
	cppVar_3070 = PC + 1;
	cppVar_3070 = (cppVar_3070 & cppMask_un_16_);
	cppVar_3071 = ROM.rd(cppVar_3070);
	cppVar_3072 = (cppVar_3071 >> 3) & cppMask_un_5_;
	cppVar_3073 = (cppVar_3072 << 3) | 0;
	cppVar_3073 = (cppVar_3073 & cppMask_un_8_);
	cppVar_3065 = cppVar_3073;
	} else {
	cppVar_3074 = PC + 1;
	cppVar_3074 = (cppVar_3074 & cppMask_un_16_);
	cppVar_3075 = ROM.rd(cppVar_3074);
	cppVar_3076 = (cppVar_3075 >> 3) & cppMask_un_5_;
	cppVar_3077 = (cppVar_3076 & cppMask_un_5_);
	cppVar_3078 = cppVar_3077 + 32;
	cppVar_3078 = (cppVar_3078 & cppMask_un_8_);
	cppVar_3065 = cppVar_3078;
	}
	cppVar_3080 = (cppVar_3065 == 131);
	if (cppVar_3080) {
	cppVar_3064 = DPH;
	} else {
	cppVar_3083 = PC + 1;
	cppVar_3083 = (cppVar_3083 & cppMask_un_16_);
	cppVar_3084 = ROM.rd(cppVar_3083);
	cppVar_3085 = (cppVar_3084 >> 7) & cppMask_un_1_;
	cppVar_3086 = (cppVar_3085 == 1);
	if (cppVar_3086) {
	cppVar_3087 = PC + 1;
	cppVar_3087 = (cppVar_3087 & cppMask_un_16_);
	cppVar_3088 = ROM.rd(cppVar_3087);
	cppVar_3089 = (cppVar_3088 >> 3) & cppMask_un_5_;
	cppVar_3090 = (cppVar_3089 << 3) | 0;
	cppVar_3090 = (cppVar_3090 & cppMask_un_8_);
	cppVar_3082 = cppVar_3090;
	} else {
	cppVar_3091 = PC + 1;
	cppVar_3091 = (cppVar_3091 & cppMask_un_16_);
	cppVar_3092 = ROM.rd(cppVar_3091);
	cppVar_3093 = (cppVar_3092 >> 3) & cppMask_un_5_;
	cppVar_3094 = (cppVar_3093 & cppMask_un_5_);
	cppVar_3095 = cppVar_3094 + 32;
	cppVar_3095 = (cppVar_3095 & cppMask_un_8_);
	cppVar_3082 = cppVar_3095;
	}
	cppVar_3097 = (cppVar_3082 == 135);
	if (cppVar_3097) {
	cppVar_3081 = PCON;
	} else {
	cppVar_3100 = PC + 1;
	cppVar_3100 = (cppVar_3100 & cppMask_un_16_);
	cppVar_3101 = ROM.rd(cppVar_3100);
	cppVar_3102 = (cppVar_3101 >> 7) & cppMask_un_1_;
	cppVar_3103 = (cppVar_3102 == 1);
	if (cppVar_3103) {
	cppVar_3104 = PC + 1;
	cppVar_3104 = (cppVar_3104 & cppMask_un_16_);
	cppVar_3105 = ROM.rd(cppVar_3104);
	cppVar_3106 = (cppVar_3105 >> 3) & cppMask_un_5_;
	cppVar_3107 = (cppVar_3106 << 3) | 0;
	cppVar_3107 = (cppVar_3107 & cppMask_un_8_);
	cppVar_3099 = cppVar_3107;
	} else {
	cppVar_3108 = PC + 1;
	cppVar_3108 = (cppVar_3108 & cppMask_un_16_);
	cppVar_3109 = ROM.rd(cppVar_3108);
	cppVar_3110 = (cppVar_3109 >> 3) & cppMask_un_5_;
	cppVar_3111 = (cppVar_3110 & cppMask_un_5_);
	cppVar_3112 = cppVar_3111 + 32;
	cppVar_3112 = (cppVar_3112 & cppMask_un_8_);
	cppVar_3099 = cppVar_3112;
	}
	cppVar_3114 = (cppVar_3099 == 136);
	if (cppVar_3114) {
	cppVar_3098 = TCON;
	} else {
	cppVar_3117 = PC + 1;
	cppVar_3117 = (cppVar_3117 & cppMask_un_16_);
	cppVar_3118 = ROM.rd(cppVar_3117);
	cppVar_3119 = (cppVar_3118 >> 7) & cppMask_un_1_;
	cppVar_3120 = (cppVar_3119 == 1);
	if (cppVar_3120) {
	cppVar_3121 = PC + 1;
	cppVar_3121 = (cppVar_3121 & cppMask_un_16_);
	cppVar_3122 = ROM.rd(cppVar_3121);
	cppVar_3123 = (cppVar_3122 >> 3) & cppMask_un_5_;
	cppVar_3124 = (cppVar_3123 << 3) | 0;
	cppVar_3124 = (cppVar_3124 & cppMask_un_8_);
	cppVar_3116 = cppVar_3124;
	} else {
	cppVar_3125 = PC + 1;
	cppVar_3125 = (cppVar_3125 & cppMask_un_16_);
	cppVar_3126 = ROM.rd(cppVar_3125);
	cppVar_3127 = (cppVar_3126 >> 3) & cppMask_un_5_;
	cppVar_3128 = (cppVar_3127 & cppMask_un_5_);
	cppVar_3129 = cppVar_3128 + 32;
	cppVar_3129 = (cppVar_3129 & cppMask_un_8_);
	cppVar_3116 = cppVar_3129;
	}
	cppVar_3131 = (cppVar_3116 == 137);
	if (cppVar_3131) {
	cppVar_3115 = TMOD;
	} else {
	cppVar_3134 = PC + 1;
	cppVar_3134 = (cppVar_3134 & cppMask_un_16_);
	cppVar_3135 = ROM.rd(cppVar_3134);
	cppVar_3136 = (cppVar_3135 >> 7) & cppMask_un_1_;
	cppVar_3137 = (cppVar_3136 == 1);
	if (cppVar_3137) {
	cppVar_3138 = PC + 1;
	cppVar_3138 = (cppVar_3138 & cppMask_un_16_);
	cppVar_3139 = ROM.rd(cppVar_3138);
	cppVar_3140 = (cppVar_3139 >> 3) & cppMask_un_5_;
	cppVar_3141 = (cppVar_3140 << 3) | 0;
	cppVar_3141 = (cppVar_3141 & cppMask_un_8_);
	cppVar_3133 = cppVar_3141;
	} else {
	cppVar_3142 = PC + 1;
	cppVar_3142 = (cppVar_3142 & cppMask_un_16_);
	cppVar_3143 = ROM.rd(cppVar_3142);
	cppVar_3144 = (cppVar_3143 >> 3) & cppMask_un_5_;
	cppVar_3145 = (cppVar_3144 & cppMask_un_5_);
	cppVar_3146 = cppVar_3145 + 32;
	cppVar_3146 = (cppVar_3146 & cppMask_un_8_);
	cppVar_3133 = cppVar_3146;
	}
	cppVar_3148 = (cppVar_3133 == 138);
	if (cppVar_3148) {
	cppVar_3132 = TL0;
	} else {
	cppVar_3151 = PC + 1;
	cppVar_3151 = (cppVar_3151 & cppMask_un_16_);
	cppVar_3152 = ROM.rd(cppVar_3151);
	cppVar_3153 = (cppVar_3152 >> 7) & cppMask_un_1_;
	cppVar_3154 = (cppVar_3153 == 1);
	if (cppVar_3154) {
	cppVar_3155 = PC + 1;
	cppVar_3155 = (cppVar_3155 & cppMask_un_16_);
	cppVar_3156 = ROM.rd(cppVar_3155);
	cppVar_3157 = (cppVar_3156 >> 3) & cppMask_un_5_;
	cppVar_3158 = (cppVar_3157 << 3) | 0;
	cppVar_3158 = (cppVar_3158 & cppMask_un_8_);
	cppVar_3150 = cppVar_3158;
	} else {
	cppVar_3159 = PC + 1;
	cppVar_3159 = (cppVar_3159 & cppMask_un_16_);
	cppVar_3160 = ROM.rd(cppVar_3159);
	cppVar_3161 = (cppVar_3160 >> 3) & cppMask_un_5_;
	cppVar_3162 = (cppVar_3161 & cppMask_un_5_);
	cppVar_3163 = cppVar_3162 + 32;
	cppVar_3163 = (cppVar_3163 & cppMask_un_8_);
	cppVar_3150 = cppVar_3163;
	}
	cppVar_3165 = (cppVar_3150 == 140);
	if (cppVar_3165) {
	cppVar_3149 = TH0;
	} else {
	cppVar_3168 = PC + 1;
	cppVar_3168 = (cppVar_3168 & cppMask_un_16_);
	cppVar_3169 = ROM.rd(cppVar_3168);
	cppVar_3170 = (cppVar_3169 >> 7) & cppMask_un_1_;
	cppVar_3171 = (cppVar_3170 == 1);
	if (cppVar_3171) {
	cppVar_3172 = PC + 1;
	cppVar_3172 = (cppVar_3172 & cppMask_un_16_);
	cppVar_3173 = ROM.rd(cppVar_3172);
	cppVar_3174 = (cppVar_3173 >> 3) & cppMask_un_5_;
	cppVar_3175 = (cppVar_3174 << 3) | 0;
	cppVar_3175 = (cppVar_3175 & cppMask_un_8_);
	cppVar_3167 = cppVar_3175;
	} else {
	cppVar_3176 = PC + 1;
	cppVar_3176 = (cppVar_3176 & cppMask_un_16_);
	cppVar_3177 = ROM.rd(cppVar_3176);
	cppVar_3178 = (cppVar_3177 >> 3) & cppMask_un_5_;
	cppVar_3179 = (cppVar_3178 & cppMask_un_5_);
	cppVar_3180 = cppVar_3179 + 32;
	cppVar_3180 = (cppVar_3180 & cppMask_un_8_);
	cppVar_3167 = cppVar_3180;
	}
	cppVar_3182 = (cppVar_3167 == 139);
	if (cppVar_3182) {
	cppVar_3166 = TL1;
	} else {
	cppVar_3185 = PC + 1;
	cppVar_3185 = (cppVar_3185 & cppMask_un_16_);
	cppVar_3186 = ROM.rd(cppVar_3185);
	cppVar_3187 = (cppVar_3186 >> 7) & cppMask_un_1_;
	cppVar_3188 = (cppVar_3187 == 1);
	if (cppVar_3188) {
	cppVar_3189 = PC + 1;
	cppVar_3189 = (cppVar_3189 & cppMask_un_16_);
	cppVar_3190 = ROM.rd(cppVar_3189);
	cppVar_3191 = (cppVar_3190 >> 3) & cppMask_un_5_;
	cppVar_3192 = (cppVar_3191 << 3) | 0;
	cppVar_3192 = (cppVar_3192 & cppMask_un_8_);
	cppVar_3184 = cppVar_3192;
	} else {
	cppVar_3193 = PC + 1;
	cppVar_3193 = (cppVar_3193 & cppMask_un_16_);
	cppVar_3194 = ROM.rd(cppVar_3193);
	cppVar_3195 = (cppVar_3194 >> 3) & cppMask_un_5_;
	cppVar_3196 = (cppVar_3195 & cppMask_un_5_);
	cppVar_3197 = cppVar_3196 + 32;
	cppVar_3197 = (cppVar_3197 & cppMask_un_8_);
	cppVar_3184 = cppVar_3197;
	}
	cppVar_3199 = (cppVar_3184 == 141);
	if (cppVar_3199) {
	cppVar_3183 = TH1;
	} else {
	cppVar_3202 = PC + 1;
	cppVar_3202 = (cppVar_3202 & cppMask_un_16_);
	cppVar_3203 = ROM.rd(cppVar_3202);
	cppVar_3204 = (cppVar_3203 >> 7) & cppMask_un_1_;
	cppVar_3205 = (cppVar_3204 == 1);
	if (cppVar_3205) {
	cppVar_3206 = PC + 1;
	cppVar_3206 = (cppVar_3206 & cppMask_un_16_);
	cppVar_3207 = ROM.rd(cppVar_3206);
	cppVar_3208 = (cppVar_3207 >> 3) & cppMask_un_5_;
	cppVar_3209 = (cppVar_3208 << 3) | 0;
	cppVar_3209 = (cppVar_3209 & cppMask_un_8_);
	cppVar_3201 = cppVar_3209;
	} else {
	cppVar_3210 = PC + 1;
	cppVar_3210 = (cppVar_3210 & cppMask_un_16_);
	cppVar_3211 = ROM.rd(cppVar_3210);
	cppVar_3212 = (cppVar_3211 >> 3) & cppMask_un_5_;
	cppVar_3213 = (cppVar_3212 & cppMask_un_5_);
	cppVar_3214 = cppVar_3213 + 32;
	cppVar_3214 = (cppVar_3214 & cppMask_un_8_);
	cppVar_3201 = cppVar_3214;
	}
	cppVar_3216 = (cppVar_3201 == 144);
	if (cppVar_3216) {
	cppVar_3200 = P1;
	} else {
	cppVar_3219 = PC + 1;
	cppVar_3219 = (cppVar_3219 & cppMask_un_16_);
	cppVar_3220 = ROM.rd(cppVar_3219);
	cppVar_3221 = (cppVar_3220 >> 7) & cppMask_un_1_;
	cppVar_3222 = (cppVar_3221 == 1);
	if (cppVar_3222) {
	cppVar_3223 = PC + 1;
	cppVar_3223 = (cppVar_3223 & cppMask_un_16_);
	cppVar_3224 = ROM.rd(cppVar_3223);
	cppVar_3225 = (cppVar_3224 >> 3) & cppMask_un_5_;
	cppVar_3226 = (cppVar_3225 << 3) | 0;
	cppVar_3226 = (cppVar_3226 & cppMask_un_8_);
	cppVar_3218 = cppVar_3226;
	} else {
	cppVar_3227 = PC + 1;
	cppVar_3227 = (cppVar_3227 & cppMask_un_16_);
	cppVar_3228 = ROM.rd(cppVar_3227);
	cppVar_3229 = (cppVar_3228 >> 3) & cppMask_un_5_;
	cppVar_3230 = (cppVar_3229 & cppMask_un_5_);
	cppVar_3231 = cppVar_3230 + 32;
	cppVar_3231 = (cppVar_3231 & cppMask_un_8_);
	cppVar_3218 = cppVar_3231;
	}
	cppVar_3233 = (cppVar_3218 == 152);
	if (cppVar_3233) {
	cppVar_3217 = SCON;
	} else {
	cppVar_3236 = PC + 1;
	cppVar_3236 = (cppVar_3236 & cppMask_un_16_);
	cppVar_3237 = ROM.rd(cppVar_3236);
	cppVar_3238 = (cppVar_3237 >> 7) & cppMask_un_1_;
	cppVar_3239 = (cppVar_3238 == 1);
	if (cppVar_3239) {
	cppVar_3240 = PC + 1;
	cppVar_3240 = (cppVar_3240 & cppMask_un_16_);
	cppVar_3241 = ROM.rd(cppVar_3240);
	cppVar_3242 = (cppVar_3241 >> 3) & cppMask_un_5_;
	cppVar_3243 = (cppVar_3242 << 3) | 0;
	cppVar_3243 = (cppVar_3243 & cppMask_un_8_);
	cppVar_3235 = cppVar_3243;
	} else {
	cppVar_3244 = PC + 1;
	cppVar_3244 = (cppVar_3244 & cppMask_un_16_);
	cppVar_3245 = ROM.rd(cppVar_3244);
	cppVar_3246 = (cppVar_3245 >> 3) & cppMask_un_5_;
	cppVar_3247 = (cppVar_3246 & cppMask_un_5_);
	cppVar_3248 = cppVar_3247 + 32;
	cppVar_3248 = (cppVar_3248 & cppMask_un_8_);
	cppVar_3235 = cppVar_3248;
	}
	cppVar_3250 = (cppVar_3235 == 153);
	if (cppVar_3250) {
	cppVar_3234 = SBUF;
	} else {
	cppVar_3253 = PC + 1;
	cppVar_3253 = (cppVar_3253 & cppMask_un_16_);
	cppVar_3254 = ROM.rd(cppVar_3253);
	cppVar_3255 = (cppVar_3254 >> 7) & cppMask_un_1_;
	cppVar_3256 = (cppVar_3255 == 1);
	if (cppVar_3256) {
	cppVar_3257 = PC + 1;
	cppVar_3257 = (cppVar_3257 & cppMask_un_16_);
	cppVar_3258 = ROM.rd(cppVar_3257);
	cppVar_3259 = (cppVar_3258 >> 3) & cppMask_un_5_;
	cppVar_3260 = (cppVar_3259 << 3) | 0;
	cppVar_3260 = (cppVar_3260 & cppMask_un_8_);
	cppVar_3252 = cppVar_3260;
	} else {
	cppVar_3261 = PC + 1;
	cppVar_3261 = (cppVar_3261 & cppMask_un_16_);
	cppVar_3262 = ROM.rd(cppVar_3261);
	cppVar_3263 = (cppVar_3262 >> 3) & cppMask_un_5_;
	cppVar_3264 = (cppVar_3263 & cppMask_un_5_);
	cppVar_3265 = cppVar_3264 + 32;
	cppVar_3265 = (cppVar_3265 & cppMask_un_8_);
	cppVar_3252 = cppVar_3265;
	}
	cppVar_3267 = (cppVar_3252 == 160);
	if (cppVar_3267) {
	cppVar_3251 = P2;
	} else {
	cppVar_3270 = PC + 1;
	cppVar_3270 = (cppVar_3270 & cppMask_un_16_);
	cppVar_3271 = ROM.rd(cppVar_3270);
	cppVar_3272 = (cppVar_3271 >> 7) & cppMask_un_1_;
	cppVar_3273 = (cppVar_3272 == 1);
	if (cppVar_3273) {
	cppVar_3274 = PC + 1;
	cppVar_3274 = (cppVar_3274 & cppMask_un_16_);
	cppVar_3275 = ROM.rd(cppVar_3274);
	cppVar_3276 = (cppVar_3275 >> 3) & cppMask_un_5_;
	cppVar_3277 = (cppVar_3276 << 3) | 0;
	cppVar_3277 = (cppVar_3277 & cppMask_un_8_);
	cppVar_3269 = cppVar_3277;
	} else {
	cppVar_3278 = PC + 1;
	cppVar_3278 = (cppVar_3278 & cppMask_un_16_);
	cppVar_3279 = ROM.rd(cppVar_3278);
	cppVar_3280 = (cppVar_3279 >> 3) & cppMask_un_5_;
	cppVar_3281 = (cppVar_3280 & cppMask_un_5_);
	cppVar_3282 = cppVar_3281 + 32;
	cppVar_3282 = (cppVar_3282 & cppMask_un_8_);
	cppVar_3269 = cppVar_3282;
	}
	cppVar_3284 = (cppVar_3269 == 168);
	if (cppVar_3284) {
	cppVar_3268 = IE;
	} else {
	cppVar_3287 = PC + 1;
	cppVar_3287 = (cppVar_3287 & cppMask_un_16_);
	cppVar_3288 = ROM.rd(cppVar_3287);
	cppVar_3289 = (cppVar_3288 >> 7) & cppMask_un_1_;
	cppVar_3290 = (cppVar_3289 == 1);
	if (cppVar_3290) {
	cppVar_3291 = PC + 1;
	cppVar_3291 = (cppVar_3291 & cppMask_un_16_);
	cppVar_3292 = ROM.rd(cppVar_3291);
	cppVar_3293 = (cppVar_3292 >> 3) & cppMask_un_5_;
	cppVar_3294 = (cppVar_3293 << 3) | 0;
	cppVar_3294 = (cppVar_3294 & cppMask_un_8_);
	cppVar_3286 = cppVar_3294;
	} else {
	cppVar_3295 = PC + 1;
	cppVar_3295 = (cppVar_3295 & cppMask_un_16_);
	cppVar_3296 = ROM.rd(cppVar_3295);
	cppVar_3297 = (cppVar_3296 >> 3) & cppMask_un_5_;
	cppVar_3298 = (cppVar_3297 & cppMask_un_5_);
	cppVar_3299 = cppVar_3298 + 32;
	cppVar_3299 = (cppVar_3299 & cppMask_un_8_);
	cppVar_3286 = cppVar_3299;
	}
	cppVar_3301 = (cppVar_3286 == 176);
	if (cppVar_3301) {
	cppVar_3285 = P3;
	} else {
	cppVar_3304 = PC + 1;
	cppVar_3304 = (cppVar_3304 & cppMask_un_16_);
	cppVar_3305 = ROM.rd(cppVar_3304);
	cppVar_3306 = (cppVar_3305 >> 7) & cppMask_un_1_;
	cppVar_3307 = (cppVar_3306 == 1);
	if (cppVar_3307) {
	cppVar_3308 = PC + 1;
	cppVar_3308 = (cppVar_3308 & cppMask_un_16_);
	cppVar_3309 = ROM.rd(cppVar_3308);
	cppVar_3310 = (cppVar_3309 >> 3) & cppMask_un_5_;
	cppVar_3311 = (cppVar_3310 << 3) | 0;
	cppVar_3311 = (cppVar_3311 & cppMask_un_8_);
	cppVar_3303 = cppVar_3311;
	} else {
	cppVar_3312 = PC + 1;
	cppVar_3312 = (cppVar_3312 & cppMask_un_16_);
	cppVar_3313 = ROM.rd(cppVar_3312);
	cppVar_3314 = (cppVar_3313 >> 3) & cppMask_un_5_;
	cppVar_3315 = (cppVar_3314 & cppMask_un_5_);
	cppVar_3316 = cppVar_3315 + 32;
	cppVar_3316 = (cppVar_3316 & cppMask_un_8_);
	cppVar_3303 = cppVar_3316;
	}
	cppVar_3318 = (cppVar_3303 == 184);
	if (cppVar_3318) {
	cppVar_3302 = IP;
	} else {
	cppVar_3321 = PC + 1;
	cppVar_3321 = (cppVar_3321 & cppMask_un_16_);
	cppVar_3322 = ROM.rd(cppVar_3321);
	cppVar_3323 = (cppVar_3322 >> 7) & cppMask_un_1_;
	cppVar_3324 = (cppVar_3323 == 1);
	if (cppVar_3324) {
	cppVar_3325 = PC + 1;
	cppVar_3325 = (cppVar_3325 & cppMask_un_16_);
	cppVar_3326 = ROM.rd(cppVar_3325);
	cppVar_3327 = (cppVar_3326 >> 3) & cppMask_un_5_;
	cppVar_3328 = (cppVar_3327 << 3) | 0;
	cppVar_3328 = (cppVar_3328 & cppMask_un_8_);
	cppVar_3320 = cppVar_3328;
	} else {
	cppVar_3329 = PC + 1;
	cppVar_3329 = (cppVar_3329 & cppMask_un_16_);
	cppVar_3330 = ROM.rd(cppVar_3329);
	cppVar_3331 = (cppVar_3330 >> 3) & cppMask_un_5_;
	cppVar_3332 = (cppVar_3331 & cppMask_un_5_);
	cppVar_3333 = cppVar_3332 + 32;
	cppVar_3333 = (cppVar_3333 & cppMask_un_8_);
	cppVar_3320 = cppVar_3333;
	}
	cppVar_3335 = (cppVar_3320 == 208);
	if (cppVar_3335) {
	cppVar_3319 = PSW;
	} else {
	cppVar_3338 = PC + 1;
	cppVar_3338 = (cppVar_3338 & cppMask_un_16_);
	cppVar_3339 = ROM.rd(cppVar_3338);
	cppVar_3340 = (cppVar_3339 >> 7) & cppMask_un_1_;
	cppVar_3341 = (cppVar_3340 == 1);
	if (cppVar_3341) {
	cppVar_3342 = PC + 1;
	cppVar_3342 = (cppVar_3342 & cppMask_un_16_);
	cppVar_3343 = ROM.rd(cppVar_3342);
	cppVar_3344 = (cppVar_3343 >> 3) & cppMask_un_5_;
	cppVar_3345 = (cppVar_3344 << 3) | 0;
	cppVar_3345 = (cppVar_3345 & cppMask_un_8_);
	cppVar_3337 = cppVar_3345;
	} else {
	cppVar_3346 = PC + 1;
	cppVar_3346 = (cppVar_3346 & cppMask_un_16_);
	cppVar_3347 = ROM.rd(cppVar_3346);
	cppVar_3348 = (cppVar_3347 >> 3) & cppMask_un_5_;
	cppVar_3349 = (cppVar_3348 & cppMask_un_5_);
	cppVar_3350 = cppVar_3349 + 32;
	cppVar_3350 = (cppVar_3350 & cppMask_un_8_);
	cppVar_3337 = cppVar_3350;
	}
	cppVar_3352 = (cppVar_3337 == 224);
	if (cppVar_3352) {
	cppVar_3336 = ACC;
	} else {
	cppVar_3355 = PC + 1;
	cppVar_3355 = (cppVar_3355 & cppMask_un_16_);
	cppVar_3356 = ROM.rd(cppVar_3355);
	cppVar_3357 = (cppVar_3356 >> 7) & cppMask_un_1_;
	cppVar_3358 = (cppVar_3357 == 1);
	if (cppVar_3358) {
	cppVar_3359 = PC + 1;
	cppVar_3359 = (cppVar_3359 & cppMask_un_16_);
	cppVar_3360 = ROM.rd(cppVar_3359);
	cppVar_3361 = (cppVar_3360 >> 3) & cppMask_un_5_;
	cppVar_3362 = (cppVar_3361 << 3) | 0;
	cppVar_3362 = (cppVar_3362 & cppMask_un_8_);
	cppVar_3354 = cppVar_3362;
	} else {
	cppVar_3363 = PC + 1;
	cppVar_3363 = (cppVar_3363 & cppMask_un_16_);
	cppVar_3364 = ROM.rd(cppVar_3363);
	cppVar_3365 = (cppVar_3364 >> 3) & cppMask_un_5_;
	cppVar_3366 = (cppVar_3365 & cppMask_un_5_);
	cppVar_3367 = cppVar_3366 + 32;
	cppVar_3367 = (cppVar_3367 & cppMask_un_8_);
	cppVar_3354 = cppVar_3367;
	}
	cppVar_3369 = (cppVar_3354 == 240);
	if (cppVar_3369) {
	cppVar_3353 = B;
	} else {
	cppVar_3353 = 0;
	}
	cppVar_3336 = cppVar_3353;
	}
	cppVar_3319 = cppVar_3336;
	}
	cppVar_3302 = cppVar_3319;
	}
	cppVar_3285 = cppVar_3302;
	}
	cppVar_3268 = cppVar_3285;
	}
	cppVar_3251 = cppVar_3268;
	}
	cppVar_3234 = cppVar_3251;
	}
	cppVar_3217 = cppVar_3234;
	}
	cppVar_3200 = cppVar_3217;
	}
	cppVar_3183 = cppVar_3200;
	}
	cppVar_3166 = cppVar_3183;
	}
	cppVar_3149 = cppVar_3166;
	}
	cppVar_3132 = cppVar_3149;
	}
	cppVar_3115 = cppVar_3132;
	}
	cppVar_3098 = cppVar_3115;
	}
	cppVar_3081 = cppVar_3098;
	}
	cppVar_3064 = cppVar_3081;
	}
	cppVar_3047 = cppVar_3064;
	}
	cppVar_3030 = cppVar_3047;
	}
	cppVar_3013 = cppVar_3030;
	}
	cppVar_2980 = cppVar_3013;
	}
	cppVar_3371 = cppVar_2979 & cppVar_2980;
	cppVar_3373 = 1;
	cppVar_3374 = PC + 1;
	cppVar_3374 = (cppVar_3374 & cppMask_un_16_);
	cppVar_3375 = ROM.rd(cppVar_3374);
	cppVar_3376 = (cppVar_3375 >> 0) & cppMask_un_3_;
	cppVar_3377 = (cppVar_3376 & cppMask_un_3_);
	cppVar_3378 = cppVar_3373 << static_cast<unsigned>(cppVar_3377);
	cppVar_3378 = (cppVar_3378 & cppMask_un_8_);
	cppVar_3379 = cppVar_3371 | cppVar_3378;
	cppVar_2952 = cppVar_3379;
	} else {
	cppVar_2952 = B;
	}
	cppVar_2948 = cppVar_2952;
	} else {
	cppVar_3381 = ROM.rd(PC);
	cppVar_3383 = (cppVar_3381 == 208);
	if (cppVar_3383) {
	cppVar_3386 = PC + 1;
	cppVar_3386 = (cppVar_3386 & cppMask_un_16_);
	cppVar_3387 = ROM.rd(cppVar_3386);
	cppVar_3389 = (cppVar_3387 == 240);
	if (cppVar_3389) {
	cppVar_3390 = IRAM.rd(SP);
	cppVar_3384 = cppVar_3390;
	} else {
	cppVar_3384 = B;
	}
	cppVar_3380 = cppVar_3384;
	} else {
	cppVar_3392 = ROM.rd(PC);
	cppVar_3394 = (cppVar_3392 == 245);
	cppVar_3395 = ROM.rd(PC);
	cppVar_3397 = (cppVar_3395 == 197);
	cppVar_3398 = cppVar_3394 || cppVar_3397;
	if (cppVar_3398) {
	cppVar_3401 = PC + 1;
	cppVar_3401 = (cppVar_3401 & cppMask_un_16_);
	cppVar_3402 = ROM.rd(cppVar_3401);
	cppVar_3404 = (cppVar_3402 == 240);
	if (cppVar_3404) {
	cppVar_3399 = ACC;
	} else {
	cppVar_3399 = B;
	}
	cppVar_3391 = cppVar_3399;
	} else {
	cppVar_3406 = ROM.rd(PC);
	cppVar_3408 = (cppVar_3406 == 178);
	if (cppVar_3408) {
	cppVar_3412 = PC + 1;
	cppVar_3412 = (cppVar_3412 & cppMask_un_16_);
	cppVar_3413 = ROM.rd(cppVar_3412);
	cppVar_3414 = (cppVar_3413 >> 7) & cppMask_un_1_;
	cppVar_3416 = (cppVar_3414 == 1);
	if (cppVar_3416) {
	cppVar_3417 = PC + 1;
	cppVar_3417 = (cppVar_3417 & cppMask_un_16_);
	cppVar_3418 = ROM.rd(cppVar_3417);
	cppVar_3419 = (cppVar_3418 >> 3) & cppMask_un_5_;
	cppVar_3421 = (cppVar_3419 << 3) | 0;
	cppVar_3421 = (cppVar_3421 & cppMask_un_8_);
	cppVar_3410 = cppVar_3421;
	} else {
	cppVar_3422 = PC + 1;
	cppVar_3422 = (cppVar_3422 & cppMask_un_16_);
	cppVar_3423 = ROM.rd(cppVar_3422);
	cppVar_3424 = (cppVar_3423 >> 3) & cppMask_un_5_;
	cppVar_3425 = (cppVar_3424 & cppMask_un_5_);
	cppVar_3427 = cppVar_3425 + 32;
	cppVar_3427 = (cppVar_3427 & cppMask_un_8_);
	cppVar_3410 = cppVar_3427;
	}
	cppVar_3429 = (cppVar_3410 == 240);
	if (cppVar_3429) {
	cppVar_3431 = PC + 1;
	cppVar_3431 = (cppVar_3431 & cppMask_un_16_);
	cppVar_3432 = ROM.rd(cppVar_3431);
	cppVar_3433 = (cppVar_3432 >> 0) & cppMask_un_3_;
	cppVar_3434 = (cppVar_3433 & cppMask_un_3_);
	cppVar_3435 = 1 << static_cast<unsigned>(cppVar_3434);
	cppVar_3435 = (cppVar_3435 & cppMask_un_8_);
	cppVar_3436 = ~cppVar_3435;
	cppVar_3439 = PC + 1;
	cppVar_3439 = (cppVar_3439 & cppMask_un_16_);
	cppVar_3440 = ROM.rd(cppVar_3439);
	cppVar_3441 = (cppVar_3440 >> 7) & cppMask_un_1_;
	cppVar_3442 = (cppVar_3441 == 1);
	if (cppVar_3442) {
	cppVar_3443 = PC + 1;
	cppVar_3443 = (cppVar_3443 & cppMask_un_16_);
	cppVar_3444 = ROM.rd(cppVar_3443);
	cppVar_3445 = (cppVar_3444 >> 3) & cppMask_un_5_;
	cppVar_3446 = (cppVar_3445 << 3) | 0;
	cppVar_3446 = (cppVar_3446 & cppMask_un_8_);
	cppVar_3438 = cppVar_3446;
	} else {
	cppVar_3447 = PC + 1;
	cppVar_3447 = (cppVar_3447 & cppMask_un_16_);
	cppVar_3448 = ROM.rd(cppVar_3447);
	cppVar_3449 = (cppVar_3448 >> 3) & cppMask_un_5_;
	cppVar_3450 = (cppVar_3449 & cppMask_un_5_);
	cppVar_3451 = cppVar_3450 + 32;
	cppVar_3451 = (cppVar_3451 & cppMask_un_8_);
	cppVar_3438 = cppVar_3451;
	}
	cppVar_3452 = (cppVar_3438 >> 7) & cppMask_un_1_;
	cppVar_3454 = (cppVar_3452 == 0);
	if (cppVar_3454) {
	cppVar_3456 = PC + 1;
	cppVar_3456 = (cppVar_3456 & cppMask_un_16_);
	cppVar_3457 = ROM.rd(cppVar_3456);
	cppVar_3458 = (cppVar_3457 >> 7) & cppMask_un_1_;
	cppVar_3459 = (cppVar_3458 == 1);
	if (cppVar_3459) {
	cppVar_3460 = PC + 1;
	cppVar_3460 = (cppVar_3460 & cppMask_un_16_);
	cppVar_3461 = ROM.rd(cppVar_3460);
	cppVar_3462 = (cppVar_3461 >> 3) & cppMask_un_5_;
	cppVar_3463 = (cppVar_3462 << 3) | 0;
	cppVar_3463 = (cppVar_3463 & cppMask_un_8_);
	cppVar_3455 = cppVar_3463;
	} else {
	cppVar_3464 = PC + 1;
	cppVar_3464 = (cppVar_3464 & cppMask_un_16_);
	cppVar_3465 = ROM.rd(cppVar_3464);
	cppVar_3466 = (cppVar_3465 >> 3) & cppMask_un_5_;
	cppVar_3467 = (cppVar_3466 & cppMask_un_5_);
	cppVar_3468 = cppVar_3467 + 32;
	cppVar_3468 = (cppVar_3468 & cppMask_un_8_);
	cppVar_3455 = cppVar_3468;
	}
	cppVar_3469 = IRAM.rd(cppVar_3455);
	cppVar_3437 = cppVar_3469;
	} else {
	cppVar_3472 = PC + 1;
	cppVar_3472 = (cppVar_3472 & cppMask_un_16_);
	cppVar_3473 = ROM.rd(cppVar_3472);
	cppVar_3474 = (cppVar_3473 >> 7) & cppMask_un_1_;
	cppVar_3475 = (cppVar_3474 == 1);
	if (cppVar_3475) {
	cppVar_3476 = PC + 1;
	cppVar_3476 = (cppVar_3476 & cppMask_un_16_);
	cppVar_3477 = ROM.rd(cppVar_3476);
	cppVar_3478 = (cppVar_3477 >> 3) & cppMask_un_5_;
	cppVar_3479 = (cppVar_3478 << 3) | 0;
	cppVar_3479 = (cppVar_3479 & cppMask_un_8_);
	cppVar_3471 = cppVar_3479;
	} else {
	cppVar_3480 = PC + 1;
	cppVar_3480 = (cppVar_3480 & cppMask_un_16_);
	cppVar_3481 = ROM.rd(cppVar_3480);
	cppVar_3482 = (cppVar_3481 >> 3) & cppMask_un_5_;
	cppVar_3483 = (cppVar_3482 & cppMask_un_5_);
	cppVar_3484 = cppVar_3483 + 32;
	cppVar_3484 = (cppVar_3484 & cppMask_un_8_);
	cppVar_3471 = cppVar_3484;
	}
	cppVar_3486 = (cppVar_3471 == 128);
	if (cppVar_3486) {
	cppVar_3470 = P0;
	} else {
	cppVar_3489 = PC + 1;
	cppVar_3489 = (cppVar_3489 & cppMask_un_16_);
	cppVar_3490 = ROM.rd(cppVar_3489);
	cppVar_3491 = (cppVar_3490 >> 7) & cppMask_un_1_;
	cppVar_3492 = (cppVar_3491 == 1);
	if (cppVar_3492) {
	cppVar_3493 = PC + 1;
	cppVar_3493 = (cppVar_3493 & cppMask_un_16_);
	cppVar_3494 = ROM.rd(cppVar_3493);
	cppVar_3495 = (cppVar_3494 >> 3) & cppMask_un_5_;
	cppVar_3496 = (cppVar_3495 << 3) | 0;
	cppVar_3496 = (cppVar_3496 & cppMask_un_8_);
	cppVar_3488 = cppVar_3496;
	} else {
	cppVar_3497 = PC + 1;
	cppVar_3497 = (cppVar_3497 & cppMask_un_16_);
	cppVar_3498 = ROM.rd(cppVar_3497);
	cppVar_3499 = (cppVar_3498 >> 3) & cppMask_un_5_;
	cppVar_3500 = (cppVar_3499 & cppMask_un_5_);
	cppVar_3501 = cppVar_3500 + 32;
	cppVar_3501 = (cppVar_3501 & cppMask_un_8_);
	cppVar_3488 = cppVar_3501;
	}
	cppVar_3503 = (cppVar_3488 == 129);
	if (cppVar_3503) {
	cppVar_3487 = SP;
	} else {
	cppVar_3506 = PC + 1;
	cppVar_3506 = (cppVar_3506 & cppMask_un_16_);
	cppVar_3507 = ROM.rd(cppVar_3506);
	cppVar_3508 = (cppVar_3507 >> 7) & cppMask_un_1_;
	cppVar_3509 = (cppVar_3508 == 1);
	if (cppVar_3509) {
	cppVar_3510 = PC + 1;
	cppVar_3510 = (cppVar_3510 & cppMask_un_16_);
	cppVar_3511 = ROM.rd(cppVar_3510);
	cppVar_3512 = (cppVar_3511 >> 3) & cppMask_un_5_;
	cppVar_3513 = (cppVar_3512 << 3) | 0;
	cppVar_3513 = (cppVar_3513 & cppMask_un_8_);
	cppVar_3505 = cppVar_3513;
	} else {
	cppVar_3514 = PC + 1;
	cppVar_3514 = (cppVar_3514 & cppMask_un_16_);
	cppVar_3515 = ROM.rd(cppVar_3514);
	cppVar_3516 = (cppVar_3515 >> 3) & cppMask_un_5_;
	cppVar_3517 = (cppVar_3516 & cppMask_un_5_);
	cppVar_3518 = cppVar_3517 + 32;
	cppVar_3518 = (cppVar_3518 & cppMask_un_8_);
	cppVar_3505 = cppVar_3518;
	}
	cppVar_3520 = (cppVar_3505 == 130);
	if (cppVar_3520) {
	cppVar_3504 = DPL;
	} else {
	cppVar_3523 = PC + 1;
	cppVar_3523 = (cppVar_3523 & cppMask_un_16_);
	cppVar_3524 = ROM.rd(cppVar_3523);
	cppVar_3525 = (cppVar_3524 >> 7) & cppMask_un_1_;
	cppVar_3526 = (cppVar_3525 == 1);
	if (cppVar_3526) {
	cppVar_3527 = PC + 1;
	cppVar_3527 = (cppVar_3527 & cppMask_un_16_);
	cppVar_3528 = ROM.rd(cppVar_3527);
	cppVar_3529 = (cppVar_3528 >> 3) & cppMask_un_5_;
	cppVar_3530 = (cppVar_3529 << 3) | 0;
	cppVar_3530 = (cppVar_3530 & cppMask_un_8_);
	cppVar_3522 = cppVar_3530;
	} else {
	cppVar_3531 = PC + 1;
	cppVar_3531 = (cppVar_3531 & cppMask_un_16_);
	cppVar_3532 = ROM.rd(cppVar_3531);
	cppVar_3533 = (cppVar_3532 >> 3) & cppMask_un_5_;
	cppVar_3534 = (cppVar_3533 & cppMask_un_5_);
	cppVar_3535 = cppVar_3534 + 32;
	cppVar_3535 = (cppVar_3535 & cppMask_un_8_);
	cppVar_3522 = cppVar_3535;
	}
	cppVar_3537 = (cppVar_3522 == 131);
	if (cppVar_3537) {
	cppVar_3521 = DPH;
	} else {
	cppVar_3540 = PC + 1;
	cppVar_3540 = (cppVar_3540 & cppMask_un_16_);
	cppVar_3541 = ROM.rd(cppVar_3540);
	cppVar_3542 = (cppVar_3541 >> 7) & cppMask_un_1_;
	cppVar_3543 = (cppVar_3542 == 1);
	if (cppVar_3543) {
	cppVar_3544 = PC + 1;
	cppVar_3544 = (cppVar_3544 & cppMask_un_16_);
	cppVar_3545 = ROM.rd(cppVar_3544);
	cppVar_3546 = (cppVar_3545 >> 3) & cppMask_un_5_;
	cppVar_3547 = (cppVar_3546 << 3) | 0;
	cppVar_3547 = (cppVar_3547 & cppMask_un_8_);
	cppVar_3539 = cppVar_3547;
	} else {
	cppVar_3548 = PC + 1;
	cppVar_3548 = (cppVar_3548 & cppMask_un_16_);
	cppVar_3549 = ROM.rd(cppVar_3548);
	cppVar_3550 = (cppVar_3549 >> 3) & cppMask_un_5_;
	cppVar_3551 = (cppVar_3550 & cppMask_un_5_);
	cppVar_3552 = cppVar_3551 + 32;
	cppVar_3552 = (cppVar_3552 & cppMask_un_8_);
	cppVar_3539 = cppVar_3552;
	}
	cppVar_3554 = (cppVar_3539 == 135);
	if (cppVar_3554) {
	cppVar_3538 = PCON;
	} else {
	cppVar_3557 = PC + 1;
	cppVar_3557 = (cppVar_3557 & cppMask_un_16_);
	cppVar_3558 = ROM.rd(cppVar_3557);
	cppVar_3559 = (cppVar_3558 >> 7) & cppMask_un_1_;
	cppVar_3560 = (cppVar_3559 == 1);
	if (cppVar_3560) {
	cppVar_3561 = PC + 1;
	cppVar_3561 = (cppVar_3561 & cppMask_un_16_);
	cppVar_3562 = ROM.rd(cppVar_3561);
	cppVar_3563 = (cppVar_3562 >> 3) & cppMask_un_5_;
	cppVar_3564 = (cppVar_3563 << 3) | 0;
	cppVar_3564 = (cppVar_3564 & cppMask_un_8_);
	cppVar_3556 = cppVar_3564;
	} else {
	cppVar_3565 = PC + 1;
	cppVar_3565 = (cppVar_3565 & cppMask_un_16_);
	cppVar_3566 = ROM.rd(cppVar_3565);
	cppVar_3567 = (cppVar_3566 >> 3) & cppMask_un_5_;
	cppVar_3568 = (cppVar_3567 & cppMask_un_5_);
	cppVar_3569 = cppVar_3568 + 32;
	cppVar_3569 = (cppVar_3569 & cppMask_un_8_);
	cppVar_3556 = cppVar_3569;
	}
	cppVar_3571 = (cppVar_3556 == 136);
	if (cppVar_3571) {
	cppVar_3555 = TCON;
	} else {
	cppVar_3574 = PC + 1;
	cppVar_3574 = (cppVar_3574 & cppMask_un_16_);
	cppVar_3575 = ROM.rd(cppVar_3574);
	cppVar_3576 = (cppVar_3575 >> 7) & cppMask_un_1_;
	cppVar_3577 = (cppVar_3576 == 1);
	if (cppVar_3577) {
	cppVar_3578 = PC + 1;
	cppVar_3578 = (cppVar_3578 & cppMask_un_16_);
	cppVar_3579 = ROM.rd(cppVar_3578);
	cppVar_3580 = (cppVar_3579 >> 3) & cppMask_un_5_;
	cppVar_3581 = (cppVar_3580 << 3) | 0;
	cppVar_3581 = (cppVar_3581 & cppMask_un_8_);
	cppVar_3573 = cppVar_3581;
	} else {
	cppVar_3582 = PC + 1;
	cppVar_3582 = (cppVar_3582 & cppMask_un_16_);
	cppVar_3583 = ROM.rd(cppVar_3582);
	cppVar_3584 = (cppVar_3583 >> 3) & cppMask_un_5_;
	cppVar_3585 = (cppVar_3584 & cppMask_un_5_);
	cppVar_3586 = cppVar_3585 + 32;
	cppVar_3586 = (cppVar_3586 & cppMask_un_8_);
	cppVar_3573 = cppVar_3586;
	}
	cppVar_3588 = (cppVar_3573 == 137);
	if (cppVar_3588) {
	cppVar_3572 = TMOD;
	} else {
	cppVar_3591 = PC + 1;
	cppVar_3591 = (cppVar_3591 & cppMask_un_16_);
	cppVar_3592 = ROM.rd(cppVar_3591);
	cppVar_3593 = (cppVar_3592 >> 7) & cppMask_un_1_;
	cppVar_3594 = (cppVar_3593 == 1);
	if (cppVar_3594) {
	cppVar_3595 = PC + 1;
	cppVar_3595 = (cppVar_3595 & cppMask_un_16_);
	cppVar_3596 = ROM.rd(cppVar_3595);
	cppVar_3597 = (cppVar_3596 >> 3) & cppMask_un_5_;
	cppVar_3598 = (cppVar_3597 << 3) | 0;
	cppVar_3598 = (cppVar_3598 & cppMask_un_8_);
	cppVar_3590 = cppVar_3598;
	} else {
	cppVar_3599 = PC + 1;
	cppVar_3599 = (cppVar_3599 & cppMask_un_16_);
	cppVar_3600 = ROM.rd(cppVar_3599);
	cppVar_3601 = (cppVar_3600 >> 3) & cppMask_un_5_;
	cppVar_3602 = (cppVar_3601 & cppMask_un_5_);
	cppVar_3603 = cppVar_3602 + 32;
	cppVar_3603 = (cppVar_3603 & cppMask_un_8_);
	cppVar_3590 = cppVar_3603;
	}
	cppVar_3605 = (cppVar_3590 == 138);
	if (cppVar_3605) {
	cppVar_3589 = TL0;
	} else {
	cppVar_3608 = PC + 1;
	cppVar_3608 = (cppVar_3608 & cppMask_un_16_);
	cppVar_3609 = ROM.rd(cppVar_3608);
	cppVar_3610 = (cppVar_3609 >> 7) & cppMask_un_1_;
	cppVar_3611 = (cppVar_3610 == 1);
	if (cppVar_3611) {
	cppVar_3612 = PC + 1;
	cppVar_3612 = (cppVar_3612 & cppMask_un_16_);
	cppVar_3613 = ROM.rd(cppVar_3612);
	cppVar_3614 = (cppVar_3613 >> 3) & cppMask_un_5_;
	cppVar_3615 = (cppVar_3614 << 3) | 0;
	cppVar_3615 = (cppVar_3615 & cppMask_un_8_);
	cppVar_3607 = cppVar_3615;
	} else {
	cppVar_3616 = PC + 1;
	cppVar_3616 = (cppVar_3616 & cppMask_un_16_);
	cppVar_3617 = ROM.rd(cppVar_3616);
	cppVar_3618 = (cppVar_3617 >> 3) & cppMask_un_5_;
	cppVar_3619 = (cppVar_3618 & cppMask_un_5_);
	cppVar_3620 = cppVar_3619 + 32;
	cppVar_3620 = (cppVar_3620 & cppMask_un_8_);
	cppVar_3607 = cppVar_3620;
	}
	cppVar_3622 = (cppVar_3607 == 140);
	if (cppVar_3622) {
	cppVar_3606 = TH0;
	} else {
	cppVar_3625 = PC + 1;
	cppVar_3625 = (cppVar_3625 & cppMask_un_16_);
	cppVar_3626 = ROM.rd(cppVar_3625);
	cppVar_3627 = (cppVar_3626 >> 7) & cppMask_un_1_;
	cppVar_3628 = (cppVar_3627 == 1);
	if (cppVar_3628) {
	cppVar_3629 = PC + 1;
	cppVar_3629 = (cppVar_3629 & cppMask_un_16_);
	cppVar_3630 = ROM.rd(cppVar_3629);
	cppVar_3631 = (cppVar_3630 >> 3) & cppMask_un_5_;
	cppVar_3632 = (cppVar_3631 << 3) | 0;
	cppVar_3632 = (cppVar_3632 & cppMask_un_8_);
	cppVar_3624 = cppVar_3632;
	} else {
	cppVar_3633 = PC + 1;
	cppVar_3633 = (cppVar_3633 & cppMask_un_16_);
	cppVar_3634 = ROM.rd(cppVar_3633);
	cppVar_3635 = (cppVar_3634 >> 3) & cppMask_un_5_;
	cppVar_3636 = (cppVar_3635 & cppMask_un_5_);
	cppVar_3637 = cppVar_3636 + 32;
	cppVar_3637 = (cppVar_3637 & cppMask_un_8_);
	cppVar_3624 = cppVar_3637;
	}
	cppVar_3639 = (cppVar_3624 == 139);
	if (cppVar_3639) {
	cppVar_3623 = TL1;
	} else {
	cppVar_3642 = PC + 1;
	cppVar_3642 = (cppVar_3642 & cppMask_un_16_);
	cppVar_3643 = ROM.rd(cppVar_3642);
	cppVar_3644 = (cppVar_3643 >> 7) & cppMask_un_1_;
	cppVar_3645 = (cppVar_3644 == 1);
	if (cppVar_3645) {
	cppVar_3646 = PC + 1;
	cppVar_3646 = (cppVar_3646 & cppMask_un_16_);
	cppVar_3647 = ROM.rd(cppVar_3646);
	cppVar_3648 = (cppVar_3647 >> 3) & cppMask_un_5_;
	cppVar_3649 = (cppVar_3648 << 3) | 0;
	cppVar_3649 = (cppVar_3649 & cppMask_un_8_);
	cppVar_3641 = cppVar_3649;
	} else {
	cppVar_3650 = PC + 1;
	cppVar_3650 = (cppVar_3650 & cppMask_un_16_);
	cppVar_3651 = ROM.rd(cppVar_3650);
	cppVar_3652 = (cppVar_3651 >> 3) & cppMask_un_5_;
	cppVar_3653 = (cppVar_3652 & cppMask_un_5_);
	cppVar_3654 = cppVar_3653 + 32;
	cppVar_3654 = (cppVar_3654 & cppMask_un_8_);
	cppVar_3641 = cppVar_3654;
	}
	cppVar_3656 = (cppVar_3641 == 141);
	if (cppVar_3656) {
	cppVar_3640 = TH1;
	} else {
	cppVar_3659 = PC + 1;
	cppVar_3659 = (cppVar_3659 & cppMask_un_16_);
	cppVar_3660 = ROM.rd(cppVar_3659);
	cppVar_3661 = (cppVar_3660 >> 7) & cppMask_un_1_;
	cppVar_3662 = (cppVar_3661 == 1);
	if (cppVar_3662) {
	cppVar_3663 = PC + 1;
	cppVar_3663 = (cppVar_3663 & cppMask_un_16_);
	cppVar_3664 = ROM.rd(cppVar_3663);
	cppVar_3665 = (cppVar_3664 >> 3) & cppMask_un_5_;
	cppVar_3666 = (cppVar_3665 << 3) | 0;
	cppVar_3666 = (cppVar_3666 & cppMask_un_8_);
	cppVar_3658 = cppVar_3666;
	} else {
	cppVar_3667 = PC + 1;
	cppVar_3667 = (cppVar_3667 & cppMask_un_16_);
	cppVar_3668 = ROM.rd(cppVar_3667);
	cppVar_3669 = (cppVar_3668 >> 3) & cppMask_un_5_;
	cppVar_3670 = (cppVar_3669 & cppMask_un_5_);
	cppVar_3671 = cppVar_3670 + 32;
	cppVar_3671 = (cppVar_3671 & cppMask_un_8_);
	cppVar_3658 = cppVar_3671;
	}
	cppVar_3673 = (cppVar_3658 == 144);
	if (cppVar_3673) {
	cppVar_3657 = P1;
	} else {
	cppVar_3676 = PC + 1;
	cppVar_3676 = (cppVar_3676 & cppMask_un_16_);
	cppVar_3677 = ROM.rd(cppVar_3676);
	cppVar_3678 = (cppVar_3677 >> 7) & cppMask_un_1_;
	cppVar_3679 = (cppVar_3678 == 1);
	if (cppVar_3679) {
	cppVar_3680 = PC + 1;
	cppVar_3680 = (cppVar_3680 & cppMask_un_16_);
	cppVar_3681 = ROM.rd(cppVar_3680);
	cppVar_3682 = (cppVar_3681 >> 3) & cppMask_un_5_;
	cppVar_3683 = (cppVar_3682 << 3) | 0;
	cppVar_3683 = (cppVar_3683 & cppMask_un_8_);
	cppVar_3675 = cppVar_3683;
	} else {
	cppVar_3684 = PC + 1;
	cppVar_3684 = (cppVar_3684 & cppMask_un_16_);
	cppVar_3685 = ROM.rd(cppVar_3684);
	cppVar_3686 = (cppVar_3685 >> 3) & cppMask_un_5_;
	cppVar_3687 = (cppVar_3686 & cppMask_un_5_);
	cppVar_3688 = cppVar_3687 + 32;
	cppVar_3688 = (cppVar_3688 & cppMask_un_8_);
	cppVar_3675 = cppVar_3688;
	}
	cppVar_3690 = (cppVar_3675 == 152);
	if (cppVar_3690) {
	cppVar_3674 = SCON;
	} else {
	cppVar_3693 = PC + 1;
	cppVar_3693 = (cppVar_3693 & cppMask_un_16_);
	cppVar_3694 = ROM.rd(cppVar_3693);
	cppVar_3695 = (cppVar_3694 >> 7) & cppMask_un_1_;
	cppVar_3696 = (cppVar_3695 == 1);
	if (cppVar_3696) {
	cppVar_3697 = PC + 1;
	cppVar_3697 = (cppVar_3697 & cppMask_un_16_);
	cppVar_3698 = ROM.rd(cppVar_3697);
	cppVar_3699 = (cppVar_3698 >> 3) & cppMask_un_5_;
	cppVar_3700 = (cppVar_3699 << 3) | 0;
	cppVar_3700 = (cppVar_3700 & cppMask_un_8_);
	cppVar_3692 = cppVar_3700;
	} else {
	cppVar_3701 = PC + 1;
	cppVar_3701 = (cppVar_3701 & cppMask_un_16_);
	cppVar_3702 = ROM.rd(cppVar_3701);
	cppVar_3703 = (cppVar_3702 >> 3) & cppMask_un_5_;
	cppVar_3704 = (cppVar_3703 & cppMask_un_5_);
	cppVar_3705 = cppVar_3704 + 32;
	cppVar_3705 = (cppVar_3705 & cppMask_un_8_);
	cppVar_3692 = cppVar_3705;
	}
	cppVar_3707 = (cppVar_3692 == 153);
	if (cppVar_3707) {
	cppVar_3691 = SBUF;
	} else {
	cppVar_3710 = PC + 1;
	cppVar_3710 = (cppVar_3710 & cppMask_un_16_);
	cppVar_3711 = ROM.rd(cppVar_3710);
	cppVar_3712 = (cppVar_3711 >> 7) & cppMask_un_1_;
	cppVar_3713 = (cppVar_3712 == 1);
	if (cppVar_3713) {
	cppVar_3714 = PC + 1;
	cppVar_3714 = (cppVar_3714 & cppMask_un_16_);
	cppVar_3715 = ROM.rd(cppVar_3714);
	cppVar_3716 = (cppVar_3715 >> 3) & cppMask_un_5_;
	cppVar_3717 = (cppVar_3716 << 3) | 0;
	cppVar_3717 = (cppVar_3717 & cppMask_un_8_);
	cppVar_3709 = cppVar_3717;
	} else {
	cppVar_3718 = PC + 1;
	cppVar_3718 = (cppVar_3718 & cppMask_un_16_);
	cppVar_3719 = ROM.rd(cppVar_3718);
	cppVar_3720 = (cppVar_3719 >> 3) & cppMask_un_5_;
	cppVar_3721 = (cppVar_3720 & cppMask_un_5_);
	cppVar_3722 = cppVar_3721 + 32;
	cppVar_3722 = (cppVar_3722 & cppMask_un_8_);
	cppVar_3709 = cppVar_3722;
	}
	cppVar_3724 = (cppVar_3709 == 160);
	if (cppVar_3724) {
	cppVar_3708 = P2;
	} else {
	cppVar_3727 = PC + 1;
	cppVar_3727 = (cppVar_3727 & cppMask_un_16_);
	cppVar_3728 = ROM.rd(cppVar_3727);
	cppVar_3729 = (cppVar_3728 >> 7) & cppMask_un_1_;
	cppVar_3730 = (cppVar_3729 == 1);
	if (cppVar_3730) {
	cppVar_3731 = PC + 1;
	cppVar_3731 = (cppVar_3731 & cppMask_un_16_);
	cppVar_3732 = ROM.rd(cppVar_3731);
	cppVar_3733 = (cppVar_3732 >> 3) & cppMask_un_5_;
	cppVar_3734 = (cppVar_3733 << 3) | 0;
	cppVar_3734 = (cppVar_3734 & cppMask_un_8_);
	cppVar_3726 = cppVar_3734;
	} else {
	cppVar_3735 = PC + 1;
	cppVar_3735 = (cppVar_3735 & cppMask_un_16_);
	cppVar_3736 = ROM.rd(cppVar_3735);
	cppVar_3737 = (cppVar_3736 >> 3) & cppMask_un_5_;
	cppVar_3738 = (cppVar_3737 & cppMask_un_5_);
	cppVar_3739 = cppVar_3738 + 32;
	cppVar_3739 = (cppVar_3739 & cppMask_un_8_);
	cppVar_3726 = cppVar_3739;
	}
	cppVar_3741 = (cppVar_3726 == 168);
	if (cppVar_3741) {
	cppVar_3725 = IE;
	} else {
	cppVar_3744 = PC + 1;
	cppVar_3744 = (cppVar_3744 & cppMask_un_16_);
	cppVar_3745 = ROM.rd(cppVar_3744);
	cppVar_3746 = (cppVar_3745 >> 7) & cppMask_un_1_;
	cppVar_3747 = (cppVar_3746 == 1);
	if (cppVar_3747) {
	cppVar_3748 = PC + 1;
	cppVar_3748 = (cppVar_3748 & cppMask_un_16_);
	cppVar_3749 = ROM.rd(cppVar_3748);
	cppVar_3750 = (cppVar_3749 >> 3) & cppMask_un_5_;
	cppVar_3751 = (cppVar_3750 << 3) | 0;
	cppVar_3751 = (cppVar_3751 & cppMask_un_8_);
	cppVar_3743 = cppVar_3751;
	} else {
	cppVar_3752 = PC + 1;
	cppVar_3752 = (cppVar_3752 & cppMask_un_16_);
	cppVar_3753 = ROM.rd(cppVar_3752);
	cppVar_3754 = (cppVar_3753 >> 3) & cppMask_un_5_;
	cppVar_3755 = (cppVar_3754 & cppMask_un_5_);
	cppVar_3756 = cppVar_3755 + 32;
	cppVar_3756 = (cppVar_3756 & cppMask_un_8_);
	cppVar_3743 = cppVar_3756;
	}
	cppVar_3758 = (cppVar_3743 == 176);
	if (cppVar_3758) {
	cppVar_3742 = P3;
	} else {
	cppVar_3761 = PC + 1;
	cppVar_3761 = (cppVar_3761 & cppMask_un_16_);
	cppVar_3762 = ROM.rd(cppVar_3761);
	cppVar_3763 = (cppVar_3762 >> 7) & cppMask_un_1_;
	cppVar_3764 = (cppVar_3763 == 1);
	if (cppVar_3764) {
	cppVar_3765 = PC + 1;
	cppVar_3765 = (cppVar_3765 & cppMask_un_16_);
	cppVar_3766 = ROM.rd(cppVar_3765);
	cppVar_3767 = (cppVar_3766 >> 3) & cppMask_un_5_;
	cppVar_3768 = (cppVar_3767 << 3) | 0;
	cppVar_3768 = (cppVar_3768 & cppMask_un_8_);
	cppVar_3760 = cppVar_3768;
	} else {
	cppVar_3769 = PC + 1;
	cppVar_3769 = (cppVar_3769 & cppMask_un_16_);
	cppVar_3770 = ROM.rd(cppVar_3769);
	cppVar_3771 = (cppVar_3770 >> 3) & cppMask_un_5_;
	cppVar_3772 = (cppVar_3771 & cppMask_un_5_);
	cppVar_3773 = cppVar_3772 + 32;
	cppVar_3773 = (cppVar_3773 & cppMask_un_8_);
	cppVar_3760 = cppVar_3773;
	}
	cppVar_3775 = (cppVar_3760 == 184);
	if (cppVar_3775) {
	cppVar_3759 = IP;
	} else {
	cppVar_3778 = PC + 1;
	cppVar_3778 = (cppVar_3778 & cppMask_un_16_);
	cppVar_3779 = ROM.rd(cppVar_3778);
	cppVar_3780 = (cppVar_3779 >> 7) & cppMask_un_1_;
	cppVar_3781 = (cppVar_3780 == 1);
	if (cppVar_3781) {
	cppVar_3782 = PC + 1;
	cppVar_3782 = (cppVar_3782 & cppMask_un_16_);
	cppVar_3783 = ROM.rd(cppVar_3782);
	cppVar_3784 = (cppVar_3783 >> 3) & cppMask_un_5_;
	cppVar_3785 = (cppVar_3784 << 3) | 0;
	cppVar_3785 = (cppVar_3785 & cppMask_un_8_);
	cppVar_3777 = cppVar_3785;
	} else {
	cppVar_3786 = PC + 1;
	cppVar_3786 = (cppVar_3786 & cppMask_un_16_);
	cppVar_3787 = ROM.rd(cppVar_3786);
	cppVar_3788 = (cppVar_3787 >> 3) & cppMask_un_5_;
	cppVar_3789 = (cppVar_3788 & cppMask_un_5_);
	cppVar_3790 = cppVar_3789 + 32;
	cppVar_3790 = (cppVar_3790 & cppMask_un_8_);
	cppVar_3777 = cppVar_3790;
	}
	cppVar_3792 = (cppVar_3777 == 208);
	if (cppVar_3792) {
	cppVar_3776 = PSW;
	} else {
	cppVar_3795 = PC + 1;
	cppVar_3795 = (cppVar_3795 & cppMask_un_16_);
	cppVar_3796 = ROM.rd(cppVar_3795);
	cppVar_3797 = (cppVar_3796 >> 7) & cppMask_un_1_;
	cppVar_3798 = (cppVar_3797 == 1);
	if (cppVar_3798) {
	cppVar_3799 = PC + 1;
	cppVar_3799 = (cppVar_3799 & cppMask_un_16_);
	cppVar_3800 = ROM.rd(cppVar_3799);
	cppVar_3801 = (cppVar_3800 >> 3) & cppMask_un_5_;
	cppVar_3802 = (cppVar_3801 << 3) | 0;
	cppVar_3802 = (cppVar_3802 & cppMask_un_8_);
	cppVar_3794 = cppVar_3802;
	} else {
	cppVar_3803 = PC + 1;
	cppVar_3803 = (cppVar_3803 & cppMask_un_16_);
	cppVar_3804 = ROM.rd(cppVar_3803);
	cppVar_3805 = (cppVar_3804 >> 3) & cppMask_un_5_;
	cppVar_3806 = (cppVar_3805 & cppMask_un_5_);
	cppVar_3807 = cppVar_3806 + 32;
	cppVar_3807 = (cppVar_3807 & cppMask_un_8_);
	cppVar_3794 = cppVar_3807;
	}
	cppVar_3809 = (cppVar_3794 == 224);
	if (cppVar_3809) {
	cppVar_3793 = ACC;
	} else {
	cppVar_3812 = PC + 1;
	cppVar_3812 = (cppVar_3812 & cppMask_un_16_);
	cppVar_3813 = ROM.rd(cppVar_3812);
	cppVar_3814 = (cppVar_3813 >> 7) & cppMask_un_1_;
	cppVar_3815 = (cppVar_3814 == 1);
	if (cppVar_3815) {
	cppVar_3816 = PC + 1;
	cppVar_3816 = (cppVar_3816 & cppMask_un_16_);
	cppVar_3817 = ROM.rd(cppVar_3816);
	cppVar_3818 = (cppVar_3817 >> 3) & cppMask_un_5_;
	cppVar_3819 = (cppVar_3818 << 3) | 0;
	cppVar_3819 = (cppVar_3819 & cppMask_un_8_);
	cppVar_3811 = cppVar_3819;
	} else {
	cppVar_3820 = PC + 1;
	cppVar_3820 = (cppVar_3820 & cppMask_un_16_);
	cppVar_3821 = ROM.rd(cppVar_3820);
	cppVar_3822 = (cppVar_3821 >> 3) & cppMask_un_5_;
	cppVar_3823 = (cppVar_3822 & cppMask_un_5_);
	cppVar_3824 = cppVar_3823 + 32;
	cppVar_3824 = (cppVar_3824 & cppMask_un_8_);
	cppVar_3811 = cppVar_3824;
	}
	cppVar_3826 = (cppVar_3811 == 240);
	if (cppVar_3826) {
	cppVar_3810 = B;
	} else {
	cppVar_3810 = 0;
	}
	cppVar_3793 = cppVar_3810;
	}
	cppVar_3776 = cppVar_3793;
	}
	cppVar_3759 = cppVar_3776;
	}
	cppVar_3742 = cppVar_3759;
	}
	cppVar_3725 = cppVar_3742;
	}
	cppVar_3708 = cppVar_3725;
	}
	cppVar_3691 = cppVar_3708;
	}
	cppVar_3674 = cppVar_3691;
	}
	cppVar_3657 = cppVar_3674;
	}
	cppVar_3640 = cppVar_3657;
	}
	cppVar_3623 = cppVar_3640;
	}
	cppVar_3606 = cppVar_3623;
	}
	cppVar_3589 = cppVar_3606;
	}
	cppVar_3572 = cppVar_3589;
	}
	cppVar_3555 = cppVar_3572;
	}
	cppVar_3538 = cppVar_3555;
	}
	cppVar_3521 = cppVar_3538;
	}
	cppVar_3504 = cppVar_3521;
	}
	cppVar_3487 = cppVar_3504;
	}
	cppVar_3470 = cppVar_3487;
	}
	cppVar_3437 = cppVar_3470;
	}
	cppVar_3828 = cppVar_3436 & cppVar_3437;
	cppVar_3831 = PC + 1;
	cppVar_3831 = (cppVar_3831 & cppMask_un_16_);
	cppVar_3832 = ROM.rd(cppVar_3831);
	cppVar_3833 = (cppVar_3832 >> 7) & cppMask_un_1_;
	cppVar_3835 = (cppVar_3833 == 1);
	if (cppVar_3835) {
	cppVar_3836 = PC + 1;
	cppVar_3836 = (cppVar_3836 & cppMask_un_16_);
	cppVar_3837 = ROM.rd(cppVar_3836);
	cppVar_3838 = (cppVar_3837 >> 3) & cppMask_un_5_;
	cppVar_3840 = (cppVar_3838 << 3) | 0;
	cppVar_3840 = (cppVar_3840 & cppMask_un_8_);
	cppVar_3830 = cppVar_3840;
	} else {
	cppVar_3841 = PC + 1;
	cppVar_3841 = (cppVar_3841 & cppMask_un_16_);
	cppVar_3842 = ROM.rd(cppVar_3841);
	cppVar_3843 = (cppVar_3842 >> 3) & cppMask_un_5_;
	cppVar_3844 = (cppVar_3843 & cppMask_un_5_);
	cppVar_3846 = cppVar_3844 + 32;
	cppVar_3846 = (cppVar_3846 & cppMask_un_8_);
	cppVar_3830 = cppVar_3846;
	}
	cppVar_3847 = (cppVar_3830 >> 7) & cppMask_un_1_;
	cppVar_3849 = (cppVar_3847 == 0);
	if (cppVar_3849) {
	cppVar_3851 = PC + 1;
	cppVar_3851 = (cppVar_3851 & cppMask_un_16_);
	cppVar_3852 = ROM.rd(cppVar_3851);
	cppVar_3853 = (cppVar_3852 >> 7) & cppMask_un_1_;
	cppVar_3854 = (cppVar_3853 == 1);
	if (cppVar_3854) {
	cppVar_3855 = PC + 1;
	cppVar_3855 = (cppVar_3855 & cppMask_un_16_);
	cppVar_3856 = ROM.rd(cppVar_3855);
	cppVar_3857 = (cppVar_3856 >> 3) & cppMask_un_5_;
	cppVar_3858 = (cppVar_3857 << 3) | 0;
	cppVar_3858 = (cppVar_3858 & cppMask_un_8_);
	cppVar_3850 = cppVar_3858;
	} else {
	cppVar_3859 = PC + 1;
	cppVar_3859 = (cppVar_3859 & cppMask_un_16_);
	cppVar_3860 = ROM.rd(cppVar_3859);
	cppVar_3861 = (cppVar_3860 >> 3) & cppMask_un_5_;
	cppVar_3862 = (cppVar_3861 & cppMask_un_5_);
	cppVar_3863 = cppVar_3862 + 32;
	cppVar_3863 = (cppVar_3863 & cppMask_un_8_);
	cppVar_3850 = cppVar_3863;
	}
	cppVar_3864 = IRAM.rd(cppVar_3850);
	cppVar_3829 = cppVar_3864;
	} else {
	cppVar_3867 = PC + 1;
	cppVar_3867 = (cppVar_3867 & cppMask_un_16_);
	cppVar_3868 = ROM.rd(cppVar_3867);
	cppVar_3869 = (cppVar_3868 >> 7) & cppMask_un_1_;
	cppVar_3870 = (cppVar_3869 == 1);
	if (cppVar_3870) {
	cppVar_3871 = PC + 1;
	cppVar_3871 = (cppVar_3871 & cppMask_un_16_);
	cppVar_3872 = ROM.rd(cppVar_3871);
	cppVar_3873 = (cppVar_3872 >> 3) & cppMask_un_5_;
	cppVar_3874 = (cppVar_3873 << 3) | 0;
	cppVar_3874 = (cppVar_3874 & cppMask_un_8_);
	cppVar_3866 = cppVar_3874;
	} else {
	cppVar_3875 = PC + 1;
	cppVar_3875 = (cppVar_3875 & cppMask_un_16_);
	cppVar_3876 = ROM.rd(cppVar_3875);
	cppVar_3877 = (cppVar_3876 >> 3) & cppMask_un_5_;
	cppVar_3878 = (cppVar_3877 & cppMask_un_5_);
	cppVar_3879 = cppVar_3878 + 32;
	cppVar_3879 = (cppVar_3879 & cppMask_un_8_);
	cppVar_3866 = cppVar_3879;
	}
	cppVar_3881 = (cppVar_3866 == 128);
	if (cppVar_3881) {
	cppVar_3865 = P0;
	} else {
	cppVar_3884 = PC + 1;
	cppVar_3884 = (cppVar_3884 & cppMask_un_16_);
	cppVar_3885 = ROM.rd(cppVar_3884);
	cppVar_3886 = (cppVar_3885 >> 7) & cppMask_un_1_;
	cppVar_3887 = (cppVar_3886 == 1);
	if (cppVar_3887) {
	cppVar_3888 = PC + 1;
	cppVar_3888 = (cppVar_3888 & cppMask_un_16_);
	cppVar_3889 = ROM.rd(cppVar_3888);
	cppVar_3890 = (cppVar_3889 >> 3) & cppMask_un_5_;
	cppVar_3891 = (cppVar_3890 << 3) | 0;
	cppVar_3891 = (cppVar_3891 & cppMask_un_8_);
	cppVar_3883 = cppVar_3891;
	} else {
	cppVar_3892 = PC + 1;
	cppVar_3892 = (cppVar_3892 & cppMask_un_16_);
	cppVar_3893 = ROM.rd(cppVar_3892);
	cppVar_3894 = (cppVar_3893 >> 3) & cppMask_un_5_;
	cppVar_3895 = (cppVar_3894 & cppMask_un_5_);
	cppVar_3896 = cppVar_3895 + 32;
	cppVar_3896 = (cppVar_3896 & cppMask_un_8_);
	cppVar_3883 = cppVar_3896;
	}
	cppVar_3898 = (cppVar_3883 == 129);
	if (cppVar_3898) {
	cppVar_3882 = SP;
	} else {
	cppVar_3901 = PC + 1;
	cppVar_3901 = (cppVar_3901 & cppMask_un_16_);
	cppVar_3902 = ROM.rd(cppVar_3901);
	cppVar_3903 = (cppVar_3902 >> 7) & cppMask_un_1_;
	cppVar_3904 = (cppVar_3903 == 1);
	if (cppVar_3904) {
	cppVar_3905 = PC + 1;
	cppVar_3905 = (cppVar_3905 & cppMask_un_16_);
	cppVar_3906 = ROM.rd(cppVar_3905);
	cppVar_3907 = (cppVar_3906 >> 3) & cppMask_un_5_;
	cppVar_3908 = (cppVar_3907 << 3) | 0;
	cppVar_3908 = (cppVar_3908 & cppMask_un_8_);
	cppVar_3900 = cppVar_3908;
	} else {
	cppVar_3909 = PC + 1;
	cppVar_3909 = (cppVar_3909 & cppMask_un_16_);
	cppVar_3910 = ROM.rd(cppVar_3909);
	cppVar_3911 = (cppVar_3910 >> 3) & cppMask_un_5_;
	cppVar_3912 = (cppVar_3911 & cppMask_un_5_);
	cppVar_3913 = cppVar_3912 + 32;
	cppVar_3913 = (cppVar_3913 & cppMask_un_8_);
	cppVar_3900 = cppVar_3913;
	}
	cppVar_3915 = (cppVar_3900 == 130);
	if (cppVar_3915) {
	cppVar_3899 = DPL;
	} else {
	cppVar_3918 = PC + 1;
	cppVar_3918 = (cppVar_3918 & cppMask_un_16_);
	cppVar_3919 = ROM.rd(cppVar_3918);
	cppVar_3920 = (cppVar_3919 >> 7) & cppMask_un_1_;
	cppVar_3921 = (cppVar_3920 == 1);
	if (cppVar_3921) {
	cppVar_3922 = PC + 1;
	cppVar_3922 = (cppVar_3922 & cppMask_un_16_);
	cppVar_3923 = ROM.rd(cppVar_3922);
	cppVar_3924 = (cppVar_3923 >> 3) & cppMask_un_5_;
	cppVar_3925 = (cppVar_3924 << 3) | 0;
	cppVar_3925 = (cppVar_3925 & cppMask_un_8_);
	cppVar_3917 = cppVar_3925;
	} else {
	cppVar_3926 = PC + 1;
	cppVar_3926 = (cppVar_3926 & cppMask_un_16_);
	cppVar_3927 = ROM.rd(cppVar_3926);
	cppVar_3928 = (cppVar_3927 >> 3) & cppMask_un_5_;
	cppVar_3929 = (cppVar_3928 & cppMask_un_5_);
	cppVar_3930 = cppVar_3929 + 32;
	cppVar_3930 = (cppVar_3930 & cppMask_un_8_);
	cppVar_3917 = cppVar_3930;
	}
	cppVar_3932 = (cppVar_3917 == 131);
	if (cppVar_3932) {
	cppVar_3916 = DPH;
	} else {
	cppVar_3935 = PC + 1;
	cppVar_3935 = (cppVar_3935 & cppMask_un_16_);
	cppVar_3936 = ROM.rd(cppVar_3935);
	cppVar_3937 = (cppVar_3936 >> 7) & cppMask_un_1_;
	cppVar_3938 = (cppVar_3937 == 1);
	if (cppVar_3938) {
	cppVar_3939 = PC + 1;
	cppVar_3939 = (cppVar_3939 & cppMask_un_16_);
	cppVar_3940 = ROM.rd(cppVar_3939);
	cppVar_3941 = (cppVar_3940 >> 3) & cppMask_un_5_;
	cppVar_3942 = (cppVar_3941 << 3) | 0;
	cppVar_3942 = (cppVar_3942 & cppMask_un_8_);
	cppVar_3934 = cppVar_3942;
	} else {
	cppVar_3943 = PC + 1;
	cppVar_3943 = (cppVar_3943 & cppMask_un_16_);
	cppVar_3944 = ROM.rd(cppVar_3943);
	cppVar_3945 = (cppVar_3944 >> 3) & cppMask_un_5_;
	cppVar_3946 = (cppVar_3945 & cppMask_un_5_);
	cppVar_3947 = cppVar_3946 + 32;
	cppVar_3947 = (cppVar_3947 & cppMask_un_8_);
	cppVar_3934 = cppVar_3947;
	}
	cppVar_3949 = (cppVar_3934 == 135);
	if (cppVar_3949) {
	cppVar_3933 = PCON;
	} else {
	cppVar_3952 = PC + 1;
	cppVar_3952 = (cppVar_3952 & cppMask_un_16_);
	cppVar_3953 = ROM.rd(cppVar_3952);
	cppVar_3954 = (cppVar_3953 >> 7) & cppMask_un_1_;
	cppVar_3955 = (cppVar_3954 == 1);
	if (cppVar_3955) {
	cppVar_3956 = PC + 1;
	cppVar_3956 = (cppVar_3956 & cppMask_un_16_);
	cppVar_3957 = ROM.rd(cppVar_3956);
	cppVar_3958 = (cppVar_3957 >> 3) & cppMask_un_5_;
	cppVar_3959 = (cppVar_3958 << 3) | 0;
	cppVar_3959 = (cppVar_3959 & cppMask_un_8_);
	cppVar_3951 = cppVar_3959;
	} else {
	cppVar_3960 = PC + 1;
	cppVar_3960 = (cppVar_3960 & cppMask_un_16_);
	cppVar_3961 = ROM.rd(cppVar_3960);
	cppVar_3962 = (cppVar_3961 >> 3) & cppMask_un_5_;
	cppVar_3963 = (cppVar_3962 & cppMask_un_5_);
	cppVar_3964 = cppVar_3963 + 32;
	cppVar_3964 = (cppVar_3964 & cppMask_un_8_);
	cppVar_3951 = cppVar_3964;
	}
	cppVar_3966 = (cppVar_3951 == 136);
	if (cppVar_3966) {
	cppVar_3950 = TCON;
	} else {
	cppVar_3969 = PC + 1;
	cppVar_3969 = (cppVar_3969 & cppMask_un_16_);
	cppVar_3970 = ROM.rd(cppVar_3969);
	cppVar_3971 = (cppVar_3970 >> 7) & cppMask_un_1_;
	cppVar_3972 = (cppVar_3971 == 1);
	if (cppVar_3972) {
	cppVar_3973 = PC + 1;
	cppVar_3973 = (cppVar_3973 & cppMask_un_16_);
	cppVar_3974 = ROM.rd(cppVar_3973);
	cppVar_3975 = (cppVar_3974 >> 3) & cppMask_un_5_;
	cppVar_3976 = (cppVar_3975 << 3) | 0;
	cppVar_3976 = (cppVar_3976 & cppMask_un_8_);
	cppVar_3968 = cppVar_3976;
	} else {
	cppVar_3977 = PC + 1;
	cppVar_3977 = (cppVar_3977 & cppMask_un_16_);
	cppVar_3978 = ROM.rd(cppVar_3977);
	cppVar_3979 = (cppVar_3978 >> 3) & cppMask_un_5_;
	cppVar_3980 = (cppVar_3979 & cppMask_un_5_);
	cppVar_3981 = cppVar_3980 + 32;
	cppVar_3981 = (cppVar_3981 & cppMask_un_8_);
	cppVar_3968 = cppVar_3981;
	}
	cppVar_3983 = (cppVar_3968 == 137);
	if (cppVar_3983) {
	cppVar_3967 = TMOD;
	} else {
	cppVar_3986 = PC + 1;
	cppVar_3986 = (cppVar_3986 & cppMask_un_16_);
	cppVar_3987 = ROM.rd(cppVar_3986);
	cppVar_3988 = (cppVar_3987 >> 7) & cppMask_un_1_;
	cppVar_3989 = (cppVar_3988 == 1);
	if (cppVar_3989) {
	cppVar_3990 = PC + 1;
	cppVar_3990 = (cppVar_3990 & cppMask_un_16_);
	cppVar_3991 = ROM.rd(cppVar_3990);
	cppVar_3992 = (cppVar_3991 >> 3) & cppMask_un_5_;
	cppVar_3993 = (cppVar_3992 << 3) | 0;
	cppVar_3993 = (cppVar_3993 & cppMask_un_8_);
	cppVar_3985 = cppVar_3993;
	} else {
	cppVar_3994 = PC + 1;
	cppVar_3994 = (cppVar_3994 & cppMask_un_16_);
	cppVar_3995 = ROM.rd(cppVar_3994);
	cppVar_3996 = (cppVar_3995 >> 3) & cppMask_un_5_;
	cppVar_3997 = (cppVar_3996 & cppMask_un_5_);
	cppVar_3998 = cppVar_3997 + 32;
	cppVar_3998 = (cppVar_3998 & cppMask_un_8_);
	cppVar_3985 = cppVar_3998;
	}
	cppVar_4000 = (cppVar_3985 == 138);
	if (cppVar_4000) {
	cppVar_3984 = TL0;
	} else {
	cppVar_4003 = PC + 1;
	cppVar_4003 = (cppVar_4003 & cppMask_un_16_);
	cppVar_4004 = ROM.rd(cppVar_4003);
	cppVar_4005 = (cppVar_4004 >> 7) & cppMask_un_1_;
	cppVar_4006 = (cppVar_4005 == 1);
	if (cppVar_4006) {
	cppVar_4007 = PC + 1;
	cppVar_4007 = (cppVar_4007 & cppMask_un_16_);
	cppVar_4008 = ROM.rd(cppVar_4007);
	cppVar_4009 = (cppVar_4008 >> 3) & cppMask_un_5_;
	cppVar_4010 = (cppVar_4009 << 3) | 0;
	cppVar_4010 = (cppVar_4010 & cppMask_un_8_);
	cppVar_4002 = cppVar_4010;
	} else {
	cppVar_4011 = PC + 1;
	cppVar_4011 = (cppVar_4011 & cppMask_un_16_);
	cppVar_4012 = ROM.rd(cppVar_4011);
	cppVar_4013 = (cppVar_4012 >> 3) & cppMask_un_5_;
	cppVar_4014 = (cppVar_4013 & cppMask_un_5_);
	cppVar_4015 = cppVar_4014 + 32;
	cppVar_4015 = (cppVar_4015 & cppMask_un_8_);
	cppVar_4002 = cppVar_4015;
	}
	cppVar_4017 = (cppVar_4002 == 140);
	if (cppVar_4017) {
	cppVar_4001 = TH0;
	} else {
	cppVar_4020 = PC + 1;
	cppVar_4020 = (cppVar_4020 & cppMask_un_16_);
	cppVar_4021 = ROM.rd(cppVar_4020);
	cppVar_4022 = (cppVar_4021 >> 7) & cppMask_un_1_;
	cppVar_4023 = (cppVar_4022 == 1);
	if (cppVar_4023) {
	cppVar_4024 = PC + 1;
	cppVar_4024 = (cppVar_4024 & cppMask_un_16_);
	cppVar_4025 = ROM.rd(cppVar_4024);
	cppVar_4026 = (cppVar_4025 >> 3) & cppMask_un_5_;
	cppVar_4027 = (cppVar_4026 << 3) | 0;
	cppVar_4027 = (cppVar_4027 & cppMask_un_8_);
	cppVar_4019 = cppVar_4027;
	} else {
	cppVar_4028 = PC + 1;
	cppVar_4028 = (cppVar_4028 & cppMask_un_16_);
	cppVar_4029 = ROM.rd(cppVar_4028);
	cppVar_4030 = (cppVar_4029 >> 3) & cppMask_un_5_;
	cppVar_4031 = (cppVar_4030 & cppMask_un_5_);
	cppVar_4032 = cppVar_4031 + 32;
	cppVar_4032 = (cppVar_4032 & cppMask_un_8_);
	cppVar_4019 = cppVar_4032;
	}
	cppVar_4034 = (cppVar_4019 == 139);
	if (cppVar_4034) {
	cppVar_4018 = TL1;
	} else {
	cppVar_4037 = PC + 1;
	cppVar_4037 = (cppVar_4037 & cppMask_un_16_);
	cppVar_4038 = ROM.rd(cppVar_4037);
	cppVar_4039 = (cppVar_4038 >> 7) & cppMask_un_1_;
	cppVar_4040 = (cppVar_4039 == 1);
	if (cppVar_4040) {
	cppVar_4041 = PC + 1;
	cppVar_4041 = (cppVar_4041 & cppMask_un_16_);
	cppVar_4042 = ROM.rd(cppVar_4041);
	cppVar_4043 = (cppVar_4042 >> 3) & cppMask_un_5_;
	cppVar_4044 = (cppVar_4043 << 3) | 0;
	cppVar_4044 = (cppVar_4044 & cppMask_un_8_);
	cppVar_4036 = cppVar_4044;
	} else {
	cppVar_4045 = PC + 1;
	cppVar_4045 = (cppVar_4045 & cppMask_un_16_);
	cppVar_4046 = ROM.rd(cppVar_4045);
	cppVar_4047 = (cppVar_4046 >> 3) & cppMask_un_5_;
	cppVar_4048 = (cppVar_4047 & cppMask_un_5_);
	cppVar_4049 = cppVar_4048 + 32;
	cppVar_4049 = (cppVar_4049 & cppMask_un_8_);
	cppVar_4036 = cppVar_4049;
	}
	cppVar_4051 = (cppVar_4036 == 141);
	if (cppVar_4051) {
	cppVar_4035 = TH1;
	} else {
	cppVar_4054 = PC + 1;
	cppVar_4054 = (cppVar_4054 & cppMask_un_16_);
	cppVar_4055 = ROM.rd(cppVar_4054);
	cppVar_4056 = (cppVar_4055 >> 7) & cppMask_un_1_;
	cppVar_4057 = (cppVar_4056 == 1);
	if (cppVar_4057) {
	cppVar_4058 = PC + 1;
	cppVar_4058 = (cppVar_4058 & cppMask_un_16_);
	cppVar_4059 = ROM.rd(cppVar_4058);
	cppVar_4060 = (cppVar_4059 >> 3) & cppMask_un_5_;
	cppVar_4061 = (cppVar_4060 << 3) | 0;
	cppVar_4061 = (cppVar_4061 & cppMask_un_8_);
	cppVar_4053 = cppVar_4061;
	} else {
	cppVar_4062 = PC + 1;
	cppVar_4062 = (cppVar_4062 & cppMask_un_16_);
	cppVar_4063 = ROM.rd(cppVar_4062);
	cppVar_4064 = (cppVar_4063 >> 3) & cppMask_un_5_;
	cppVar_4065 = (cppVar_4064 & cppMask_un_5_);
	cppVar_4066 = cppVar_4065 + 32;
	cppVar_4066 = (cppVar_4066 & cppMask_un_8_);
	cppVar_4053 = cppVar_4066;
	}
	cppVar_4068 = (cppVar_4053 == 144);
	if (cppVar_4068) {
	cppVar_4052 = P1;
	} else {
	cppVar_4071 = PC + 1;
	cppVar_4071 = (cppVar_4071 & cppMask_un_16_);
	cppVar_4072 = ROM.rd(cppVar_4071);
	cppVar_4073 = (cppVar_4072 >> 7) & cppMask_un_1_;
	cppVar_4074 = (cppVar_4073 == 1);
	if (cppVar_4074) {
	cppVar_4075 = PC + 1;
	cppVar_4075 = (cppVar_4075 & cppMask_un_16_);
	cppVar_4076 = ROM.rd(cppVar_4075);
	cppVar_4077 = (cppVar_4076 >> 3) & cppMask_un_5_;
	cppVar_4078 = (cppVar_4077 << 3) | 0;
	cppVar_4078 = (cppVar_4078 & cppMask_un_8_);
	cppVar_4070 = cppVar_4078;
	} else {
	cppVar_4079 = PC + 1;
	cppVar_4079 = (cppVar_4079 & cppMask_un_16_);
	cppVar_4080 = ROM.rd(cppVar_4079);
	cppVar_4081 = (cppVar_4080 >> 3) & cppMask_un_5_;
	cppVar_4082 = (cppVar_4081 & cppMask_un_5_);
	cppVar_4083 = cppVar_4082 + 32;
	cppVar_4083 = (cppVar_4083 & cppMask_un_8_);
	cppVar_4070 = cppVar_4083;
	}
	cppVar_4085 = (cppVar_4070 == 152);
	if (cppVar_4085) {
	cppVar_4069 = SCON;
	} else {
	cppVar_4088 = PC + 1;
	cppVar_4088 = (cppVar_4088 & cppMask_un_16_);
	cppVar_4089 = ROM.rd(cppVar_4088);
	cppVar_4090 = (cppVar_4089 >> 7) & cppMask_un_1_;
	cppVar_4091 = (cppVar_4090 == 1);
	if (cppVar_4091) {
	cppVar_4092 = PC + 1;
	cppVar_4092 = (cppVar_4092 & cppMask_un_16_);
	cppVar_4093 = ROM.rd(cppVar_4092);
	cppVar_4094 = (cppVar_4093 >> 3) & cppMask_un_5_;
	cppVar_4095 = (cppVar_4094 << 3) | 0;
	cppVar_4095 = (cppVar_4095 & cppMask_un_8_);
	cppVar_4087 = cppVar_4095;
	} else {
	cppVar_4096 = PC + 1;
	cppVar_4096 = (cppVar_4096 & cppMask_un_16_);
	cppVar_4097 = ROM.rd(cppVar_4096);
	cppVar_4098 = (cppVar_4097 >> 3) & cppMask_un_5_;
	cppVar_4099 = (cppVar_4098 & cppMask_un_5_);
	cppVar_4100 = cppVar_4099 + 32;
	cppVar_4100 = (cppVar_4100 & cppMask_un_8_);
	cppVar_4087 = cppVar_4100;
	}
	cppVar_4102 = (cppVar_4087 == 153);
	if (cppVar_4102) {
	cppVar_4086 = SBUF;
	} else {
	cppVar_4105 = PC + 1;
	cppVar_4105 = (cppVar_4105 & cppMask_un_16_);
	cppVar_4106 = ROM.rd(cppVar_4105);
	cppVar_4107 = (cppVar_4106 >> 7) & cppMask_un_1_;
	cppVar_4108 = (cppVar_4107 == 1);
	if (cppVar_4108) {
	cppVar_4109 = PC + 1;
	cppVar_4109 = (cppVar_4109 & cppMask_un_16_);
	cppVar_4110 = ROM.rd(cppVar_4109);
	cppVar_4111 = (cppVar_4110 >> 3) & cppMask_un_5_;
	cppVar_4112 = (cppVar_4111 << 3) | 0;
	cppVar_4112 = (cppVar_4112 & cppMask_un_8_);
	cppVar_4104 = cppVar_4112;
	} else {
	cppVar_4113 = PC + 1;
	cppVar_4113 = (cppVar_4113 & cppMask_un_16_);
	cppVar_4114 = ROM.rd(cppVar_4113);
	cppVar_4115 = (cppVar_4114 >> 3) & cppMask_un_5_;
	cppVar_4116 = (cppVar_4115 & cppMask_un_5_);
	cppVar_4117 = cppVar_4116 + 32;
	cppVar_4117 = (cppVar_4117 & cppMask_un_8_);
	cppVar_4104 = cppVar_4117;
	}
	cppVar_4119 = (cppVar_4104 == 160);
	if (cppVar_4119) {
	cppVar_4103 = P2;
	} else {
	cppVar_4122 = PC + 1;
	cppVar_4122 = (cppVar_4122 & cppMask_un_16_);
	cppVar_4123 = ROM.rd(cppVar_4122);
	cppVar_4124 = (cppVar_4123 >> 7) & cppMask_un_1_;
	cppVar_4125 = (cppVar_4124 == 1);
	if (cppVar_4125) {
	cppVar_4126 = PC + 1;
	cppVar_4126 = (cppVar_4126 & cppMask_un_16_);
	cppVar_4127 = ROM.rd(cppVar_4126);
	cppVar_4128 = (cppVar_4127 >> 3) & cppMask_un_5_;
	cppVar_4129 = (cppVar_4128 << 3) | 0;
	cppVar_4129 = (cppVar_4129 & cppMask_un_8_);
	cppVar_4121 = cppVar_4129;
	} else {
	cppVar_4130 = PC + 1;
	cppVar_4130 = (cppVar_4130 & cppMask_un_16_);
	cppVar_4131 = ROM.rd(cppVar_4130);
	cppVar_4132 = (cppVar_4131 >> 3) & cppMask_un_5_;
	cppVar_4133 = (cppVar_4132 & cppMask_un_5_);
	cppVar_4134 = cppVar_4133 + 32;
	cppVar_4134 = (cppVar_4134 & cppMask_un_8_);
	cppVar_4121 = cppVar_4134;
	}
	cppVar_4136 = (cppVar_4121 == 168);
	if (cppVar_4136) {
	cppVar_4120 = IE;
	} else {
	cppVar_4139 = PC + 1;
	cppVar_4139 = (cppVar_4139 & cppMask_un_16_);
	cppVar_4140 = ROM.rd(cppVar_4139);
	cppVar_4141 = (cppVar_4140 >> 7) & cppMask_un_1_;
	cppVar_4142 = (cppVar_4141 == 1);
	if (cppVar_4142) {
	cppVar_4143 = PC + 1;
	cppVar_4143 = (cppVar_4143 & cppMask_un_16_);
	cppVar_4144 = ROM.rd(cppVar_4143);
	cppVar_4145 = (cppVar_4144 >> 3) & cppMask_un_5_;
	cppVar_4146 = (cppVar_4145 << 3) | 0;
	cppVar_4146 = (cppVar_4146 & cppMask_un_8_);
	cppVar_4138 = cppVar_4146;
	} else {
	cppVar_4147 = PC + 1;
	cppVar_4147 = (cppVar_4147 & cppMask_un_16_);
	cppVar_4148 = ROM.rd(cppVar_4147);
	cppVar_4149 = (cppVar_4148 >> 3) & cppMask_un_5_;
	cppVar_4150 = (cppVar_4149 & cppMask_un_5_);
	cppVar_4151 = cppVar_4150 + 32;
	cppVar_4151 = (cppVar_4151 & cppMask_un_8_);
	cppVar_4138 = cppVar_4151;
	}
	cppVar_4153 = (cppVar_4138 == 176);
	if (cppVar_4153) {
	cppVar_4137 = P3;
	} else {
	cppVar_4156 = PC + 1;
	cppVar_4156 = (cppVar_4156 & cppMask_un_16_);
	cppVar_4157 = ROM.rd(cppVar_4156);
	cppVar_4158 = (cppVar_4157 >> 7) & cppMask_un_1_;
	cppVar_4159 = (cppVar_4158 == 1);
	if (cppVar_4159) {
	cppVar_4160 = PC + 1;
	cppVar_4160 = (cppVar_4160 & cppMask_un_16_);
	cppVar_4161 = ROM.rd(cppVar_4160);
	cppVar_4162 = (cppVar_4161 >> 3) & cppMask_un_5_;
	cppVar_4163 = (cppVar_4162 << 3) | 0;
	cppVar_4163 = (cppVar_4163 & cppMask_un_8_);
	cppVar_4155 = cppVar_4163;
	} else {
	cppVar_4164 = PC + 1;
	cppVar_4164 = (cppVar_4164 & cppMask_un_16_);
	cppVar_4165 = ROM.rd(cppVar_4164);
	cppVar_4166 = (cppVar_4165 >> 3) & cppMask_un_5_;
	cppVar_4167 = (cppVar_4166 & cppMask_un_5_);
	cppVar_4168 = cppVar_4167 + 32;
	cppVar_4168 = (cppVar_4168 & cppMask_un_8_);
	cppVar_4155 = cppVar_4168;
	}
	cppVar_4170 = (cppVar_4155 == 184);
	if (cppVar_4170) {
	cppVar_4154 = IP;
	} else {
	cppVar_4173 = PC + 1;
	cppVar_4173 = (cppVar_4173 & cppMask_un_16_);
	cppVar_4174 = ROM.rd(cppVar_4173);
	cppVar_4175 = (cppVar_4174 >> 7) & cppMask_un_1_;
	cppVar_4176 = (cppVar_4175 == 1);
	if (cppVar_4176) {
	cppVar_4177 = PC + 1;
	cppVar_4177 = (cppVar_4177 & cppMask_un_16_);
	cppVar_4178 = ROM.rd(cppVar_4177);
	cppVar_4179 = (cppVar_4178 >> 3) & cppMask_un_5_;
	cppVar_4180 = (cppVar_4179 << 3) | 0;
	cppVar_4180 = (cppVar_4180 & cppMask_un_8_);
	cppVar_4172 = cppVar_4180;
	} else {
	cppVar_4181 = PC + 1;
	cppVar_4181 = (cppVar_4181 & cppMask_un_16_);
	cppVar_4182 = ROM.rd(cppVar_4181);
	cppVar_4183 = (cppVar_4182 >> 3) & cppMask_un_5_;
	cppVar_4184 = (cppVar_4183 & cppMask_un_5_);
	cppVar_4185 = cppVar_4184 + 32;
	cppVar_4185 = (cppVar_4185 & cppMask_un_8_);
	cppVar_4172 = cppVar_4185;
	}
	cppVar_4187 = (cppVar_4172 == 208);
	if (cppVar_4187) {
	cppVar_4171 = PSW;
	} else {
	cppVar_4190 = PC + 1;
	cppVar_4190 = (cppVar_4190 & cppMask_un_16_);
	cppVar_4191 = ROM.rd(cppVar_4190);
	cppVar_4192 = (cppVar_4191 >> 7) & cppMask_un_1_;
	cppVar_4193 = (cppVar_4192 == 1);
	if (cppVar_4193) {
	cppVar_4194 = PC + 1;
	cppVar_4194 = (cppVar_4194 & cppMask_un_16_);
	cppVar_4195 = ROM.rd(cppVar_4194);
	cppVar_4196 = (cppVar_4195 >> 3) & cppMask_un_5_;
	cppVar_4197 = (cppVar_4196 << 3) | 0;
	cppVar_4197 = (cppVar_4197 & cppMask_un_8_);
	cppVar_4189 = cppVar_4197;
	} else {
	cppVar_4198 = PC + 1;
	cppVar_4198 = (cppVar_4198 & cppMask_un_16_);
	cppVar_4199 = ROM.rd(cppVar_4198);
	cppVar_4200 = (cppVar_4199 >> 3) & cppMask_un_5_;
	cppVar_4201 = (cppVar_4200 & cppMask_un_5_);
	cppVar_4202 = cppVar_4201 + 32;
	cppVar_4202 = (cppVar_4202 & cppMask_un_8_);
	cppVar_4189 = cppVar_4202;
	}
	cppVar_4204 = (cppVar_4189 == 224);
	if (cppVar_4204) {
	cppVar_4188 = ACC;
	} else {
	cppVar_4207 = PC + 1;
	cppVar_4207 = (cppVar_4207 & cppMask_un_16_);
	cppVar_4208 = ROM.rd(cppVar_4207);
	cppVar_4209 = (cppVar_4208 >> 7) & cppMask_un_1_;
	cppVar_4210 = (cppVar_4209 == 1);
	if (cppVar_4210) {
	cppVar_4211 = PC + 1;
	cppVar_4211 = (cppVar_4211 & cppMask_un_16_);
	cppVar_4212 = ROM.rd(cppVar_4211);
	cppVar_4213 = (cppVar_4212 >> 3) & cppMask_un_5_;
	cppVar_4214 = (cppVar_4213 << 3) | 0;
	cppVar_4214 = (cppVar_4214 & cppMask_un_8_);
	cppVar_4206 = cppVar_4214;
	} else {
	cppVar_4215 = PC + 1;
	cppVar_4215 = (cppVar_4215 & cppMask_un_16_);
	cppVar_4216 = ROM.rd(cppVar_4215);
	cppVar_4217 = (cppVar_4216 >> 3) & cppMask_un_5_;
	cppVar_4218 = (cppVar_4217 & cppMask_un_5_);
	cppVar_4219 = cppVar_4218 + 32;
	cppVar_4219 = (cppVar_4219 & cppMask_un_8_);
	cppVar_4206 = cppVar_4219;
	}
	cppVar_4221 = (cppVar_4206 == 240);
	if (cppVar_4221) {
	cppVar_4205 = B;
	} else {
	cppVar_4205 = 0;
	}
	cppVar_4188 = cppVar_4205;
	}
	cppVar_4171 = cppVar_4188;
	}
	cppVar_4154 = cppVar_4171;
	}
	cppVar_4137 = cppVar_4154;
	}
	cppVar_4120 = cppVar_4137;
	}
	cppVar_4103 = cppVar_4120;
	}
	cppVar_4086 = cppVar_4103;
	}
	cppVar_4069 = cppVar_4086;
	}
	cppVar_4052 = cppVar_4069;
	}
	cppVar_4035 = cppVar_4052;
	}
	cppVar_4018 = cppVar_4035;
	}
	cppVar_4001 = cppVar_4018;
	}
	cppVar_3984 = cppVar_4001;
	}
	cppVar_3967 = cppVar_3984;
	}
	cppVar_3950 = cppVar_3967;
	}
	cppVar_3933 = cppVar_3950;
	}
	cppVar_3916 = cppVar_3933;
	}
	cppVar_3899 = cppVar_3916;
	}
	cppVar_3882 = cppVar_3899;
	}
	cppVar_3865 = cppVar_3882;
	}
	cppVar_3829 = cppVar_3865;
	}
	cppVar_4223 = PC + 1;
	cppVar_4223 = (cppVar_4223 & cppMask_un_16_);
	cppVar_4224 = ROM.rd(cppVar_4223);
	cppVar_4225 = (cppVar_4224 >> 0) & cppMask_un_3_;
	cppVar_4226 = (cppVar_3829 >> static_cast<unsigned>(cppVar_4225)) & 0x1;
	cppVar_4227 = ~cppVar_4226;
	cppVar_4228 = (cppVar_4227 & cppMask_un_1_);
	cppVar_4229 = PC + 1;
	cppVar_4229 = (cppVar_4229 & cppMask_un_16_);
	cppVar_4230 = ROM.rd(cppVar_4229);
	cppVar_4231 = (cppVar_4230 >> 0) & cppMask_un_3_;
	cppVar_4232 = (cppVar_4231 & cppMask_un_3_);
	cppVar_4233 = cppVar_4228 << static_cast<unsigned>(cppVar_4232);
	cppVar_4233 = (cppVar_4233 & cppMask_un_8_);
	cppVar_4234 = cppVar_3828 | cppVar_4233;
	cppVar_3409 = cppVar_4234;
	} else {
	cppVar_3409 = B;
	}
	cppVar_3405 = cppVar_3409;
	} else {
	cppVar_4236 = ROM.rd(PC);
	cppVar_4238 = (cppVar_4236 == 164);
	if (cppVar_4238) {
	cppVar_4239 = (ACC & cppMask_un_8_);
	cppVar_4240 = (B & cppMask_un_8_);
	cppVar_4241 = cppVar_4239 * cppVar_4240;
	cppVar_4241 = (cppVar_4241 & cppMask_un_16_);
	cppVar_4242 = (cppVar_4241 >> 8) & cppMask_un_8_;
	cppVar_4235 = cppVar_4242;
	} else {
	cppVar_4244 = ROM.rd(PC);
	cppVar_4246 = (cppVar_4244 == 146);
	if (cppVar_4246) {
	cppVar_4250 = PC + 1;
	cppVar_4250 = (cppVar_4250 & cppMask_un_16_);
	cppVar_4251 = ROM.rd(cppVar_4250);
	cppVar_4252 = (cppVar_4251 >> 7) & cppMask_un_1_;
	cppVar_4254 = (cppVar_4252 == 1);
	if (cppVar_4254) {
	cppVar_4255 = PC + 1;
	cppVar_4255 = (cppVar_4255 & cppMask_un_16_);
	cppVar_4256 = ROM.rd(cppVar_4255);
	cppVar_4257 = (cppVar_4256 >> 3) & cppMask_un_5_;
	cppVar_4259 = (cppVar_4257 << 3) | 0;
	cppVar_4259 = (cppVar_4259 & cppMask_un_8_);
	cppVar_4248 = cppVar_4259;
	} else {
	cppVar_4260 = PC + 1;
	cppVar_4260 = (cppVar_4260 & cppMask_un_16_);
	cppVar_4261 = ROM.rd(cppVar_4260);
	cppVar_4262 = (cppVar_4261 >> 3) & cppMask_un_5_;
	cppVar_4263 = (cppVar_4262 & cppMask_un_5_);
	cppVar_4265 = cppVar_4263 + 32;
	cppVar_4265 = (cppVar_4265 & cppMask_un_8_);
	cppVar_4248 = cppVar_4265;
	}
	cppVar_4267 = (cppVar_4248 == 240);
	if (cppVar_4267) {
	cppVar_4269 = PC + 1;
	cppVar_4269 = (cppVar_4269 & cppMask_un_16_);
	cppVar_4270 = ROM.rd(cppVar_4269);
	cppVar_4271 = (cppVar_4270 >> 0) & cppMask_un_3_;
	cppVar_4272 = (cppVar_4271 & cppMask_un_3_);
	cppVar_4273 = 1 << static_cast<unsigned>(cppVar_4272);
	cppVar_4273 = (cppVar_4273 & cppMask_un_8_);
	cppVar_4274 = ~cppVar_4273;
	cppVar_4277 = PC + 1;
	cppVar_4277 = (cppVar_4277 & cppMask_un_16_);
	cppVar_4278 = ROM.rd(cppVar_4277);
	cppVar_4279 = (cppVar_4278 >> 7) & cppMask_un_1_;
	cppVar_4280 = (cppVar_4279 == 1);
	if (cppVar_4280) {
	cppVar_4281 = PC + 1;
	cppVar_4281 = (cppVar_4281 & cppMask_un_16_);
	cppVar_4282 = ROM.rd(cppVar_4281);
	cppVar_4283 = (cppVar_4282 >> 3) & cppMask_un_5_;
	cppVar_4284 = (cppVar_4283 << 3) | 0;
	cppVar_4284 = (cppVar_4284 & cppMask_un_8_);
	cppVar_4276 = cppVar_4284;
	} else {
	cppVar_4285 = PC + 1;
	cppVar_4285 = (cppVar_4285 & cppMask_un_16_);
	cppVar_4286 = ROM.rd(cppVar_4285);
	cppVar_4287 = (cppVar_4286 >> 3) & cppMask_un_5_;
	cppVar_4288 = (cppVar_4287 & cppMask_un_5_);
	cppVar_4289 = cppVar_4288 + 32;
	cppVar_4289 = (cppVar_4289 & cppMask_un_8_);
	cppVar_4276 = cppVar_4289;
	}
	cppVar_4290 = (cppVar_4276 >> 7) & cppMask_un_1_;
	cppVar_4292 = (cppVar_4290 == 0);
	if (cppVar_4292) {
	cppVar_4294 = PC + 1;
	cppVar_4294 = (cppVar_4294 & cppMask_un_16_);
	cppVar_4295 = ROM.rd(cppVar_4294);
	cppVar_4296 = (cppVar_4295 >> 7) & cppMask_un_1_;
	cppVar_4297 = (cppVar_4296 == 1);
	if (cppVar_4297) {
	cppVar_4298 = PC + 1;
	cppVar_4298 = (cppVar_4298 & cppMask_un_16_);
	cppVar_4299 = ROM.rd(cppVar_4298);
	cppVar_4300 = (cppVar_4299 >> 3) & cppMask_un_5_;
	cppVar_4301 = (cppVar_4300 << 3) | 0;
	cppVar_4301 = (cppVar_4301 & cppMask_un_8_);
	cppVar_4293 = cppVar_4301;
	} else {
	cppVar_4302 = PC + 1;
	cppVar_4302 = (cppVar_4302 & cppMask_un_16_);
	cppVar_4303 = ROM.rd(cppVar_4302);
	cppVar_4304 = (cppVar_4303 >> 3) & cppMask_un_5_;
	cppVar_4305 = (cppVar_4304 & cppMask_un_5_);
	cppVar_4306 = cppVar_4305 + 32;
	cppVar_4306 = (cppVar_4306 & cppMask_un_8_);
	cppVar_4293 = cppVar_4306;
	}
	cppVar_4307 = IRAM.rd(cppVar_4293);
	cppVar_4275 = cppVar_4307;
	} else {
	cppVar_4310 = PC + 1;
	cppVar_4310 = (cppVar_4310 & cppMask_un_16_);
	cppVar_4311 = ROM.rd(cppVar_4310);
	cppVar_4312 = (cppVar_4311 >> 7) & cppMask_un_1_;
	cppVar_4313 = (cppVar_4312 == 1);
	if (cppVar_4313) {
	cppVar_4314 = PC + 1;
	cppVar_4314 = (cppVar_4314 & cppMask_un_16_);
	cppVar_4315 = ROM.rd(cppVar_4314);
	cppVar_4316 = (cppVar_4315 >> 3) & cppMask_un_5_;
	cppVar_4317 = (cppVar_4316 << 3) | 0;
	cppVar_4317 = (cppVar_4317 & cppMask_un_8_);
	cppVar_4309 = cppVar_4317;
	} else {
	cppVar_4318 = PC + 1;
	cppVar_4318 = (cppVar_4318 & cppMask_un_16_);
	cppVar_4319 = ROM.rd(cppVar_4318);
	cppVar_4320 = (cppVar_4319 >> 3) & cppMask_un_5_;
	cppVar_4321 = (cppVar_4320 & cppMask_un_5_);
	cppVar_4322 = cppVar_4321 + 32;
	cppVar_4322 = (cppVar_4322 & cppMask_un_8_);
	cppVar_4309 = cppVar_4322;
	}
	cppVar_4324 = (cppVar_4309 == 128);
	if (cppVar_4324) {
	cppVar_4308 = P0;
	} else {
	cppVar_4327 = PC + 1;
	cppVar_4327 = (cppVar_4327 & cppMask_un_16_);
	cppVar_4328 = ROM.rd(cppVar_4327);
	cppVar_4329 = (cppVar_4328 >> 7) & cppMask_un_1_;
	cppVar_4330 = (cppVar_4329 == 1);
	if (cppVar_4330) {
	cppVar_4331 = PC + 1;
	cppVar_4331 = (cppVar_4331 & cppMask_un_16_);
	cppVar_4332 = ROM.rd(cppVar_4331);
	cppVar_4333 = (cppVar_4332 >> 3) & cppMask_un_5_;
	cppVar_4334 = (cppVar_4333 << 3) | 0;
	cppVar_4334 = (cppVar_4334 & cppMask_un_8_);
	cppVar_4326 = cppVar_4334;
	} else {
	cppVar_4335 = PC + 1;
	cppVar_4335 = (cppVar_4335 & cppMask_un_16_);
	cppVar_4336 = ROM.rd(cppVar_4335);
	cppVar_4337 = (cppVar_4336 >> 3) & cppMask_un_5_;
	cppVar_4338 = (cppVar_4337 & cppMask_un_5_);
	cppVar_4339 = cppVar_4338 + 32;
	cppVar_4339 = (cppVar_4339 & cppMask_un_8_);
	cppVar_4326 = cppVar_4339;
	}
	cppVar_4341 = (cppVar_4326 == 129);
	if (cppVar_4341) {
	cppVar_4325 = SP;
	} else {
	cppVar_4344 = PC + 1;
	cppVar_4344 = (cppVar_4344 & cppMask_un_16_);
	cppVar_4345 = ROM.rd(cppVar_4344);
	cppVar_4346 = (cppVar_4345 >> 7) & cppMask_un_1_;
	cppVar_4347 = (cppVar_4346 == 1);
	if (cppVar_4347) {
	cppVar_4348 = PC + 1;
	cppVar_4348 = (cppVar_4348 & cppMask_un_16_);
	cppVar_4349 = ROM.rd(cppVar_4348);
	cppVar_4350 = (cppVar_4349 >> 3) & cppMask_un_5_;
	cppVar_4351 = (cppVar_4350 << 3) | 0;
	cppVar_4351 = (cppVar_4351 & cppMask_un_8_);
	cppVar_4343 = cppVar_4351;
	} else {
	cppVar_4352 = PC + 1;
	cppVar_4352 = (cppVar_4352 & cppMask_un_16_);
	cppVar_4353 = ROM.rd(cppVar_4352);
	cppVar_4354 = (cppVar_4353 >> 3) & cppMask_un_5_;
	cppVar_4355 = (cppVar_4354 & cppMask_un_5_);
	cppVar_4356 = cppVar_4355 + 32;
	cppVar_4356 = (cppVar_4356 & cppMask_un_8_);
	cppVar_4343 = cppVar_4356;
	}
	cppVar_4358 = (cppVar_4343 == 130);
	if (cppVar_4358) {
	cppVar_4342 = DPL;
	} else {
	cppVar_4361 = PC + 1;
	cppVar_4361 = (cppVar_4361 & cppMask_un_16_);
	cppVar_4362 = ROM.rd(cppVar_4361);
	cppVar_4363 = (cppVar_4362 >> 7) & cppMask_un_1_;
	cppVar_4364 = (cppVar_4363 == 1);
	if (cppVar_4364) {
	cppVar_4365 = PC + 1;
	cppVar_4365 = (cppVar_4365 & cppMask_un_16_);
	cppVar_4366 = ROM.rd(cppVar_4365);
	cppVar_4367 = (cppVar_4366 >> 3) & cppMask_un_5_;
	cppVar_4368 = (cppVar_4367 << 3) | 0;
	cppVar_4368 = (cppVar_4368 & cppMask_un_8_);
	cppVar_4360 = cppVar_4368;
	} else {
	cppVar_4369 = PC + 1;
	cppVar_4369 = (cppVar_4369 & cppMask_un_16_);
	cppVar_4370 = ROM.rd(cppVar_4369);
	cppVar_4371 = (cppVar_4370 >> 3) & cppMask_un_5_;
	cppVar_4372 = (cppVar_4371 & cppMask_un_5_);
	cppVar_4373 = cppVar_4372 + 32;
	cppVar_4373 = (cppVar_4373 & cppMask_un_8_);
	cppVar_4360 = cppVar_4373;
	}
	cppVar_4375 = (cppVar_4360 == 131);
	if (cppVar_4375) {
	cppVar_4359 = DPH;
	} else {
	cppVar_4378 = PC + 1;
	cppVar_4378 = (cppVar_4378 & cppMask_un_16_);
	cppVar_4379 = ROM.rd(cppVar_4378);
	cppVar_4380 = (cppVar_4379 >> 7) & cppMask_un_1_;
	cppVar_4381 = (cppVar_4380 == 1);
	if (cppVar_4381) {
	cppVar_4382 = PC + 1;
	cppVar_4382 = (cppVar_4382 & cppMask_un_16_);
	cppVar_4383 = ROM.rd(cppVar_4382);
	cppVar_4384 = (cppVar_4383 >> 3) & cppMask_un_5_;
	cppVar_4385 = (cppVar_4384 << 3) | 0;
	cppVar_4385 = (cppVar_4385 & cppMask_un_8_);
	cppVar_4377 = cppVar_4385;
	} else {
	cppVar_4386 = PC + 1;
	cppVar_4386 = (cppVar_4386 & cppMask_un_16_);
	cppVar_4387 = ROM.rd(cppVar_4386);
	cppVar_4388 = (cppVar_4387 >> 3) & cppMask_un_5_;
	cppVar_4389 = (cppVar_4388 & cppMask_un_5_);
	cppVar_4390 = cppVar_4389 + 32;
	cppVar_4390 = (cppVar_4390 & cppMask_un_8_);
	cppVar_4377 = cppVar_4390;
	}
	cppVar_4392 = (cppVar_4377 == 135);
	if (cppVar_4392) {
	cppVar_4376 = PCON;
	} else {
	cppVar_4395 = PC + 1;
	cppVar_4395 = (cppVar_4395 & cppMask_un_16_);
	cppVar_4396 = ROM.rd(cppVar_4395);
	cppVar_4397 = (cppVar_4396 >> 7) & cppMask_un_1_;
	cppVar_4398 = (cppVar_4397 == 1);
	if (cppVar_4398) {
	cppVar_4399 = PC + 1;
	cppVar_4399 = (cppVar_4399 & cppMask_un_16_);
	cppVar_4400 = ROM.rd(cppVar_4399);
	cppVar_4401 = (cppVar_4400 >> 3) & cppMask_un_5_;
	cppVar_4402 = (cppVar_4401 << 3) | 0;
	cppVar_4402 = (cppVar_4402 & cppMask_un_8_);
	cppVar_4394 = cppVar_4402;
	} else {
	cppVar_4403 = PC + 1;
	cppVar_4403 = (cppVar_4403 & cppMask_un_16_);
	cppVar_4404 = ROM.rd(cppVar_4403);
	cppVar_4405 = (cppVar_4404 >> 3) & cppMask_un_5_;
	cppVar_4406 = (cppVar_4405 & cppMask_un_5_);
	cppVar_4407 = cppVar_4406 + 32;
	cppVar_4407 = (cppVar_4407 & cppMask_un_8_);
	cppVar_4394 = cppVar_4407;
	}
	cppVar_4409 = (cppVar_4394 == 136);
	if (cppVar_4409) {
	cppVar_4393 = TCON;
	} else {
	cppVar_4412 = PC + 1;
	cppVar_4412 = (cppVar_4412 & cppMask_un_16_);
	cppVar_4413 = ROM.rd(cppVar_4412);
	cppVar_4414 = (cppVar_4413 >> 7) & cppMask_un_1_;
	cppVar_4415 = (cppVar_4414 == 1);
	if (cppVar_4415) {
	cppVar_4416 = PC + 1;
	cppVar_4416 = (cppVar_4416 & cppMask_un_16_);
	cppVar_4417 = ROM.rd(cppVar_4416);
	cppVar_4418 = (cppVar_4417 >> 3) & cppMask_un_5_;
	cppVar_4419 = (cppVar_4418 << 3) | 0;
	cppVar_4419 = (cppVar_4419 & cppMask_un_8_);
	cppVar_4411 = cppVar_4419;
	} else {
	cppVar_4420 = PC + 1;
	cppVar_4420 = (cppVar_4420 & cppMask_un_16_);
	cppVar_4421 = ROM.rd(cppVar_4420);
	cppVar_4422 = (cppVar_4421 >> 3) & cppMask_un_5_;
	cppVar_4423 = (cppVar_4422 & cppMask_un_5_);
	cppVar_4424 = cppVar_4423 + 32;
	cppVar_4424 = (cppVar_4424 & cppMask_un_8_);
	cppVar_4411 = cppVar_4424;
	}
	cppVar_4426 = (cppVar_4411 == 137);
	if (cppVar_4426) {
	cppVar_4410 = TMOD;
	} else {
	cppVar_4429 = PC + 1;
	cppVar_4429 = (cppVar_4429 & cppMask_un_16_);
	cppVar_4430 = ROM.rd(cppVar_4429);
	cppVar_4431 = (cppVar_4430 >> 7) & cppMask_un_1_;
	cppVar_4432 = (cppVar_4431 == 1);
	if (cppVar_4432) {
	cppVar_4433 = PC + 1;
	cppVar_4433 = (cppVar_4433 & cppMask_un_16_);
	cppVar_4434 = ROM.rd(cppVar_4433);
	cppVar_4435 = (cppVar_4434 >> 3) & cppMask_un_5_;
	cppVar_4436 = (cppVar_4435 << 3) | 0;
	cppVar_4436 = (cppVar_4436 & cppMask_un_8_);
	cppVar_4428 = cppVar_4436;
	} else {
	cppVar_4437 = PC + 1;
	cppVar_4437 = (cppVar_4437 & cppMask_un_16_);
	cppVar_4438 = ROM.rd(cppVar_4437);
	cppVar_4439 = (cppVar_4438 >> 3) & cppMask_un_5_;
	cppVar_4440 = (cppVar_4439 & cppMask_un_5_);
	cppVar_4441 = cppVar_4440 + 32;
	cppVar_4441 = (cppVar_4441 & cppMask_un_8_);
	cppVar_4428 = cppVar_4441;
	}
	cppVar_4443 = (cppVar_4428 == 138);
	if (cppVar_4443) {
	cppVar_4427 = TL0;
	} else {
	cppVar_4446 = PC + 1;
	cppVar_4446 = (cppVar_4446 & cppMask_un_16_);
	cppVar_4447 = ROM.rd(cppVar_4446);
	cppVar_4448 = (cppVar_4447 >> 7) & cppMask_un_1_;
	cppVar_4449 = (cppVar_4448 == 1);
	if (cppVar_4449) {
	cppVar_4450 = PC + 1;
	cppVar_4450 = (cppVar_4450 & cppMask_un_16_);
	cppVar_4451 = ROM.rd(cppVar_4450);
	cppVar_4452 = (cppVar_4451 >> 3) & cppMask_un_5_;
	cppVar_4453 = (cppVar_4452 << 3) | 0;
	cppVar_4453 = (cppVar_4453 & cppMask_un_8_);
	cppVar_4445 = cppVar_4453;
	} else {
	cppVar_4454 = PC + 1;
	cppVar_4454 = (cppVar_4454 & cppMask_un_16_);
	cppVar_4455 = ROM.rd(cppVar_4454);
	cppVar_4456 = (cppVar_4455 >> 3) & cppMask_un_5_;
	cppVar_4457 = (cppVar_4456 & cppMask_un_5_);
	cppVar_4458 = cppVar_4457 + 32;
	cppVar_4458 = (cppVar_4458 & cppMask_un_8_);
	cppVar_4445 = cppVar_4458;
	}
	cppVar_4460 = (cppVar_4445 == 140);
	if (cppVar_4460) {
	cppVar_4444 = TH0;
	} else {
	cppVar_4463 = PC + 1;
	cppVar_4463 = (cppVar_4463 & cppMask_un_16_);
	cppVar_4464 = ROM.rd(cppVar_4463);
	cppVar_4465 = (cppVar_4464 >> 7) & cppMask_un_1_;
	cppVar_4466 = (cppVar_4465 == 1);
	if (cppVar_4466) {
	cppVar_4467 = PC + 1;
	cppVar_4467 = (cppVar_4467 & cppMask_un_16_);
	cppVar_4468 = ROM.rd(cppVar_4467);
	cppVar_4469 = (cppVar_4468 >> 3) & cppMask_un_5_;
	cppVar_4470 = (cppVar_4469 << 3) | 0;
	cppVar_4470 = (cppVar_4470 & cppMask_un_8_);
	cppVar_4462 = cppVar_4470;
	} else {
	cppVar_4471 = PC + 1;
	cppVar_4471 = (cppVar_4471 & cppMask_un_16_);
	cppVar_4472 = ROM.rd(cppVar_4471);
	cppVar_4473 = (cppVar_4472 >> 3) & cppMask_un_5_;
	cppVar_4474 = (cppVar_4473 & cppMask_un_5_);
	cppVar_4475 = cppVar_4474 + 32;
	cppVar_4475 = (cppVar_4475 & cppMask_un_8_);
	cppVar_4462 = cppVar_4475;
	}
	cppVar_4477 = (cppVar_4462 == 139);
	if (cppVar_4477) {
	cppVar_4461 = TL1;
	} else {
	cppVar_4480 = PC + 1;
	cppVar_4480 = (cppVar_4480 & cppMask_un_16_);
	cppVar_4481 = ROM.rd(cppVar_4480);
	cppVar_4482 = (cppVar_4481 >> 7) & cppMask_un_1_;
	cppVar_4483 = (cppVar_4482 == 1);
	if (cppVar_4483) {
	cppVar_4484 = PC + 1;
	cppVar_4484 = (cppVar_4484 & cppMask_un_16_);
	cppVar_4485 = ROM.rd(cppVar_4484);
	cppVar_4486 = (cppVar_4485 >> 3) & cppMask_un_5_;
	cppVar_4487 = (cppVar_4486 << 3) | 0;
	cppVar_4487 = (cppVar_4487 & cppMask_un_8_);
	cppVar_4479 = cppVar_4487;
	} else {
	cppVar_4488 = PC + 1;
	cppVar_4488 = (cppVar_4488 & cppMask_un_16_);
	cppVar_4489 = ROM.rd(cppVar_4488);
	cppVar_4490 = (cppVar_4489 >> 3) & cppMask_un_5_;
	cppVar_4491 = (cppVar_4490 & cppMask_un_5_);
	cppVar_4492 = cppVar_4491 + 32;
	cppVar_4492 = (cppVar_4492 & cppMask_un_8_);
	cppVar_4479 = cppVar_4492;
	}
	cppVar_4494 = (cppVar_4479 == 141);
	if (cppVar_4494) {
	cppVar_4478 = TH1;
	} else {
	cppVar_4497 = PC + 1;
	cppVar_4497 = (cppVar_4497 & cppMask_un_16_);
	cppVar_4498 = ROM.rd(cppVar_4497);
	cppVar_4499 = (cppVar_4498 >> 7) & cppMask_un_1_;
	cppVar_4500 = (cppVar_4499 == 1);
	if (cppVar_4500) {
	cppVar_4501 = PC + 1;
	cppVar_4501 = (cppVar_4501 & cppMask_un_16_);
	cppVar_4502 = ROM.rd(cppVar_4501);
	cppVar_4503 = (cppVar_4502 >> 3) & cppMask_un_5_;
	cppVar_4504 = (cppVar_4503 << 3) | 0;
	cppVar_4504 = (cppVar_4504 & cppMask_un_8_);
	cppVar_4496 = cppVar_4504;
	} else {
	cppVar_4505 = PC + 1;
	cppVar_4505 = (cppVar_4505 & cppMask_un_16_);
	cppVar_4506 = ROM.rd(cppVar_4505);
	cppVar_4507 = (cppVar_4506 >> 3) & cppMask_un_5_;
	cppVar_4508 = (cppVar_4507 & cppMask_un_5_);
	cppVar_4509 = cppVar_4508 + 32;
	cppVar_4509 = (cppVar_4509 & cppMask_un_8_);
	cppVar_4496 = cppVar_4509;
	}
	cppVar_4511 = (cppVar_4496 == 144);
	if (cppVar_4511) {
	cppVar_4495 = P1;
	} else {
	cppVar_4514 = PC + 1;
	cppVar_4514 = (cppVar_4514 & cppMask_un_16_);
	cppVar_4515 = ROM.rd(cppVar_4514);
	cppVar_4516 = (cppVar_4515 >> 7) & cppMask_un_1_;
	cppVar_4517 = (cppVar_4516 == 1);
	if (cppVar_4517) {
	cppVar_4518 = PC + 1;
	cppVar_4518 = (cppVar_4518 & cppMask_un_16_);
	cppVar_4519 = ROM.rd(cppVar_4518);
	cppVar_4520 = (cppVar_4519 >> 3) & cppMask_un_5_;
	cppVar_4521 = (cppVar_4520 << 3) | 0;
	cppVar_4521 = (cppVar_4521 & cppMask_un_8_);
	cppVar_4513 = cppVar_4521;
	} else {
	cppVar_4522 = PC + 1;
	cppVar_4522 = (cppVar_4522 & cppMask_un_16_);
	cppVar_4523 = ROM.rd(cppVar_4522);
	cppVar_4524 = (cppVar_4523 >> 3) & cppMask_un_5_;
	cppVar_4525 = (cppVar_4524 & cppMask_un_5_);
	cppVar_4526 = cppVar_4525 + 32;
	cppVar_4526 = (cppVar_4526 & cppMask_un_8_);
	cppVar_4513 = cppVar_4526;
	}
	cppVar_4528 = (cppVar_4513 == 152);
	if (cppVar_4528) {
	cppVar_4512 = SCON;
	} else {
	cppVar_4531 = PC + 1;
	cppVar_4531 = (cppVar_4531 & cppMask_un_16_);
	cppVar_4532 = ROM.rd(cppVar_4531);
	cppVar_4533 = (cppVar_4532 >> 7) & cppMask_un_1_;
	cppVar_4534 = (cppVar_4533 == 1);
	if (cppVar_4534) {
	cppVar_4535 = PC + 1;
	cppVar_4535 = (cppVar_4535 & cppMask_un_16_);
	cppVar_4536 = ROM.rd(cppVar_4535);
	cppVar_4537 = (cppVar_4536 >> 3) & cppMask_un_5_;
	cppVar_4538 = (cppVar_4537 << 3) | 0;
	cppVar_4538 = (cppVar_4538 & cppMask_un_8_);
	cppVar_4530 = cppVar_4538;
	} else {
	cppVar_4539 = PC + 1;
	cppVar_4539 = (cppVar_4539 & cppMask_un_16_);
	cppVar_4540 = ROM.rd(cppVar_4539);
	cppVar_4541 = (cppVar_4540 >> 3) & cppMask_un_5_;
	cppVar_4542 = (cppVar_4541 & cppMask_un_5_);
	cppVar_4543 = cppVar_4542 + 32;
	cppVar_4543 = (cppVar_4543 & cppMask_un_8_);
	cppVar_4530 = cppVar_4543;
	}
	cppVar_4545 = (cppVar_4530 == 153);
	if (cppVar_4545) {
	cppVar_4529 = SBUF;
	} else {
	cppVar_4548 = PC + 1;
	cppVar_4548 = (cppVar_4548 & cppMask_un_16_);
	cppVar_4549 = ROM.rd(cppVar_4548);
	cppVar_4550 = (cppVar_4549 >> 7) & cppMask_un_1_;
	cppVar_4551 = (cppVar_4550 == 1);
	if (cppVar_4551) {
	cppVar_4552 = PC + 1;
	cppVar_4552 = (cppVar_4552 & cppMask_un_16_);
	cppVar_4553 = ROM.rd(cppVar_4552);
	cppVar_4554 = (cppVar_4553 >> 3) & cppMask_un_5_;
	cppVar_4555 = (cppVar_4554 << 3) | 0;
	cppVar_4555 = (cppVar_4555 & cppMask_un_8_);
	cppVar_4547 = cppVar_4555;
	} else {
	cppVar_4556 = PC + 1;
	cppVar_4556 = (cppVar_4556 & cppMask_un_16_);
	cppVar_4557 = ROM.rd(cppVar_4556);
	cppVar_4558 = (cppVar_4557 >> 3) & cppMask_un_5_;
	cppVar_4559 = (cppVar_4558 & cppMask_un_5_);
	cppVar_4560 = cppVar_4559 + 32;
	cppVar_4560 = (cppVar_4560 & cppMask_un_8_);
	cppVar_4547 = cppVar_4560;
	}
	cppVar_4562 = (cppVar_4547 == 160);
	if (cppVar_4562) {
	cppVar_4546 = P2;
	} else {
	cppVar_4565 = PC + 1;
	cppVar_4565 = (cppVar_4565 & cppMask_un_16_);
	cppVar_4566 = ROM.rd(cppVar_4565);
	cppVar_4567 = (cppVar_4566 >> 7) & cppMask_un_1_;
	cppVar_4568 = (cppVar_4567 == 1);
	if (cppVar_4568) {
	cppVar_4569 = PC + 1;
	cppVar_4569 = (cppVar_4569 & cppMask_un_16_);
	cppVar_4570 = ROM.rd(cppVar_4569);
	cppVar_4571 = (cppVar_4570 >> 3) & cppMask_un_5_;
	cppVar_4572 = (cppVar_4571 << 3) | 0;
	cppVar_4572 = (cppVar_4572 & cppMask_un_8_);
	cppVar_4564 = cppVar_4572;
	} else {
	cppVar_4573 = PC + 1;
	cppVar_4573 = (cppVar_4573 & cppMask_un_16_);
	cppVar_4574 = ROM.rd(cppVar_4573);
	cppVar_4575 = (cppVar_4574 >> 3) & cppMask_un_5_;
	cppVar_4576 = (cppVar_4575 & cppMask_un_5_);
	cppVar_4577 = cppVar_4576 + 32;
	cppVar_4577 = (cppVar_4577 & cppMask_un_8_);
	cppVar_4564 = cppVar_4577;
	}
	cppVar_4579 = (cppVar_4564 == 168);
	if (cppVar_4579) {
	cppVar_4563 = IE;
	} else {
	cppVar_4582 = PC + 1;
	cppVar_4582 = (cppVar_4582 & cppMask_un_16_);
	cppVar_4583 = ROM.rd(cppVar_4582);
	cppVar_4584 = (cppVar_4583 >> 7) & cppMask_un_1_;
	cppVar_4585 = (cppVar_4584 == 1);
	if (cppVar_4585) {
	cppVar_4586 = PC + 1;
	cppVar_4586 = (cppVar_4586 & cppMask_un_16_);
	cppVar_4587 = ROM.rd(cppVar_4586);
	cppVar_4588 = (cppVar_4587 >> 3) & cppMask_un_5_;
	cppVar_4589 = (cppVar_4588 << 3) | 0;
	cppVar_4589 = (cppVar_4589 & cppMask_un_8_);
	cppVar_4581 = cppVar_4589;
	} else {
	cppVar_4590 = PC + 1;
	cppVar_4590 = (cppVar_4590 & cppMask_un_16_);
	cppVar_4591 = ROM.rd(cppVar_4590);
	cppVar_4592 = (cppVar_4591 >> 3) & cppMask_un_5_;
	cppVar_4593 = (cppVar_4592 & cppMask_un_5_);
	cppVar_4594 = cppVar_4593 + 32;
	cppVar_4594 = (cppVar_4594 & cppMask_un_8_);
	cppVar_4581 = cppVar_4594;
	}
	cppVar_4596 = (cppVar_4581 == 176);
	if (cppVar_4596) {
	cppVar_4580 = P3;
	} else {
	cppVar_4599 = PC + 1;
	cppVar_4599 = (cppVar_4599 & cppMask_un_16_);
	cppVar_4600 = ROM.rd(cppVar_4599);
	cppVar_4601 = (cppVar_4600 >> 7) & cppMask_un_1_;
	cppVar_4602 = (cppVar_4601 == 1);
	if (cppVar_4602) {
	cppVar_4603 = PC + 1;
	cppVar_4603 = (cppVar_4603 & cppMask_un_16_);
	cppVar_4604 = ROM.rd(cppVar_4603);
	cppVar_4605 = (cppVar_4604 >> 3) & cppMask_un_5_;
	cppVar_4606 = (cppVar_4605 << 3) | 0;
	cppVar_4606 = (cppVar_4606 & cppMask_un_8_);
	cppVar_4598 = cppVar_4606;
	} else {
	cppVar_4607 = PC + 1;
	cppVar_4607 = (cppVar_4607 & cppMask_un_16_);
	cppVar_4608 = ROM.rd(cppVar_4607);
	cppVar_4609 = (cppVar_4608 >> 3) & cppMask_un_5_;
	cppVar_4610 = (cppVar_4609 & cppMask_un_5_);
	cppVar_4611 = cppVar_4610 + 32;
	cppVar_4611 = (cppVar_4611 & cppMask_un_8_);
	cppVar_4598 = cppVar_4611;
	}
	cppVar_4613 = (cppVar_4598 == 184);
	if (cppVar_4613) {
	cppVar_4597 = IP;
	} else {
	cppVar_4616 = PC + 1;
	cppVar_4616 = (cppVar_4616 & cppMask_un_16_);
	cppVar_4617 = ROM.rd(cppVar_4616);
	cppVar_4618 = (cppVar_4617 >> 7) & cppMask_un_1_;
	cppVar_4619 = (cppVar_4618 == 1);
	if (cppVar_4619) {
	cppVar_4620 = PC + 1;
	cppVar_4620 = (cppVar_4620 & cppMask_un_16_);
	cppVar_4621 = ROM.rd(cppVar_4620);
	cppVar_4622 = (cppVar_4621 >> 3) & cppMask_un_5_;
	cppVar_4623 = (cppVar_4622 << 3) | 0;
	cppVar_4623 = (cppVar_4623 & cppMask_un_8_);
	cppVar_4615 = cppVar_4623;
	} else {
	cppVar_4624 = PC + 1;
	cppVar_4624 = (cppVar_4624 & cppMask_un_16_);
	cppVar_4625 = ROM.rd(cppVar_4624);
	cppVar_4626 = (cppVar_4625 >> 3) & cppMask_un_5_;
	cppVar_4627 = (cppVar_4626 & cppMask_un_5_);
	cppVar_4628 = cppVar_4627 + 32;
	cppVar_4628 = (cppVar_4628 & cppMask_un_8_);
	cppVar_4615 = cppVar_4628;
	}
	cppVar_4630 = (cppVar_4615 == 208);
	if (cppVar_4630) {
	cppVar_4614 = PSW;
	} else {
	cppVar_4633 = PC + 1;
	cppVar_4633 = (cppVar_4633 & cppMask_un_16_);
	cppVar_4634 = ROM.rd(cppVar_4633);
	cppVar_4635 = (cppVar_4634 >> 7) & cppMask_un_1_;
	cppVar_4636 = (cppVar_4635 == 1);
	if (cppVar_4636) {
	cppVar_4637 = PC + 1;
	cppVar_4637 = (cppVar_4637 & cppMask_un_16_);
	cppVar_4638 = ROM.rd(cppVar_4637);
	cppVar_4639 = (cppVar_4638 >> 3) & cppMask_un_5_;
	cppVar_4640 = (cppVar_4639 << 3) | 0;
	cppVar_4640 = (cppVar_4640 & cppMask_un_8_);
	cppVar_4632 = cppVar_4640;
	} else {
	cppVar_4641 = PC + 1;
	cppVar_4641 = (cppVar_4641 & cppMask_un_16_);
	cppVar_4642 = ROM.rd(cppVar_4641);
	cppVar_4643 = (cppVar_4642 >> 3) & cppMask_un_5_;
	cppVar_4644 = (cppVar_4643 & cppMask_un_5_);
	cppVar_4645 = cppVar_4644 + 32;
	cppVar_4645 = (cppVar_4645 & cppMask_un_8_);
	cppVar_4632 = cppVar_4645;
	}
	cppVar_4647 = (cppVar_4632 == 224);
	if (cppVar_4647) {
	cppVar_4631 = ACC;
	} else {
	cppVar_4650 = PC + 1;
	cppVar_4650 = (cppVar_4650 & cppMask_un_16_);
	cppVar_4651 = ROM.rd(cppVar_4650);
	cppVar_4652 = (cppVar_4651 >> 7) & cppMask_un_1_;
	cppVar_4653 = (cppVar_4652 == 1);
	if (cppVar_4653) {
	cppVar_4654 = PC + 1;
	cppVar_4654 = (cppVar_4654 & cppMask_un_16_);
	cppVar_4655 = ROM.rd(cppVar_4654);
	cppVar_4656 = (cppVar_4655 >> 3) & cppMask_un_5_;
	cppVar_4657 = (cppVar_4656 << 3) | 0;
	cppVar_4657 = (cppVar_4657 & cppMask_un_8_);
	cppVar_4649 = cppVar_4657;
	} else {
	cppVar_4658 = PC + 1;
	cppVar_4658 = (cppVar_4658 & cppMask_un_16_);
	cppVar_4659 = ROM.rd(cppVar_4658);
	cppVar_4660 = (cppVar_4659 >> 3) & cppMask_un_5_;
	cppVar_4661 = (cppVar_4660 & cppMask_un_5_);
	cppVar_4662 = cppVar_4661 + 32;
	cppVar_4662 = (cppVar_4662 & cppMask_un_8_);
	cppVar_4649 = cppVar_4662;
	}
	cppVar_4664 = (cppVar_4649 == 240);
	if (cppVar_4664) {
	cppVar_4648 = B;
	} else {
	cppVar_4648 = 0;
	}
	cppVar_4631 = cppVar_4648;
	}
	cppVar_4614 = cppVar_4631;
	}
	cppVar_4597 = cppVar_4614;
	}
	cppVar_4580 = cppVar_4597;
	}
	cppVar_4563 = cppVar_4580;
	}
	cppVar_4546 = cppVar_4563;
	}
	cppVar_4529 = cppVar_4546;
	}
	cppVar_4512 = cppVar_4529;
	}
	cppVar_4495 = cppVar_4512;
	}
	cppVar_4478 = cppVar_4495;
	}
	cppVar_4461 = cppVar_4478;
	}
	cppVar_4444 = cppVar_4461;
	}
	cppVar_4427 = cppVar_4444;
	}
	cppVar_4410 = cppVar_4427;
	}
	cppVar_4393 = cppVar_4410;
	}
	cppVar_4376 = cppVar_4393;
	}
	cppVar_4359 = cppVar_4376;
	}
	cppVar_4342 = cppVar_4359;
	}
	cppVar_4325 = cppVar_4342;
	}
	cppVar_4308 = cppVar_4325;
	}
	cppVar_4275 = cppVar_4308;
	}
	cppVar_4666 = cppVar_4274 & cppVar_4275;
	cppVar_4667 = (PSW >> 7) & cppMask_un_1_;
	cppVar_4668 = (cppVar_4667 & cppMask_un_1_);
	cppVar_4669 = PC + 1;
	cppVar_4669 = (cppVar_4669 & cppMask_un_16_);
	cppVar_4670 = ROM.rd(cppVar_4669);
	cppVar_4671 = (cppVar_4670 >> 0) & cppMask_un_3_;
	cppVar_4672 = (cppVar_4671 & cppMask_un_3_);
	cppVar_4673 = cppVar_4668 << static_cast<unsigned>(cppVar_4672);
	cppVar_4673 = (cppVar_4673 & cppMask_un_8_);
	cppVar_4674 = cppVar_4666 | cppVar_4673;
	cppVar_4247 = cppVar_4674;
	} else {
	cppVar_4247 = B;
	}
	cppVar_4243 = cppVar_4247;
	} else {
	cppVar_4676 = ROM.rd(PC);
	cppVar_4678 = (cppVar_4676 == 143);
	if (cppVar_4678) {
	cppVar_4681 = PC + 1;
	cppVar_4681 = (cppVar_4681 & cppMask_un_16_);
	cppVar_4682 = ROM.rd(cppVar_4681);
	cppVar_4684 = (cppVar_4682 == 240);
	if (cppVar_4684) {
	cppVar_4687 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4689 = (cppVar_4687 << 3) | 7;
	cppVar_4689 = (cppVar_4689 & cppMask_un_5_);
	cppVar_4690 = (0 << 5) | cppVar_4689;
	cppVar_4690 = (cppVar_4690 & cppMask_un_8_);
	cppVar_4691 = (cppVar_4690 >> 7) & cppMask_un_1_;
	cppVar_4693 = (cppVar_4691 == 0);
	if (cppVar_4693) {
	cppVar_4694 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4695 = (cppVar_4694 << 3) | 7;
	cppVar_4695 = (cppVar_4695 & cppMask_un_5_);
	cppVar_4696 = (0 << 5) | cppVar_4695;
	cppVar_4696 = (cppVar_4696 & cppMask_un_8_);
	cppVar_4697 = IRAM.rd(cppVar_4696);
	cppVar_4685 = cppVar_4697;
	} else {
	cppVar_4699 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4700 = (cppVar_4699 << 3) | 7;
	cppVar_4700 = (cppVar_4700 & cppMask_un_5_);
	cppVar_4701 = (0 << 5) | cppVar_4700;
	cppVar_4701 = (cppVar_4701 & cppMask_un_8_);
	cppVar_4703 = (cppVar_4701 == 128);
	if (cppVar_4703) {
	cppVar_4698 = P0;
	} else {
	cppVar_4705 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4706 = (cppVar_4705 << 3) | 7;
	cppVar_4706 = (cppVar_4706 & cppMask_un_5_);
	cppVar_4707 = (0 << 5) | cppVar_4706;
	cppVar_4707 = (cppVar_4707 & cppMask_un_8_);
	cppVar_4709 = (cppVar_4707 == 129);
	if (cppVar_4709) {
	cppVar_4704 = SP;
	} else {
	cppVar_4711 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4712 = (cppVar_4711 << 3) | 7;
	cppVar_4712 = (cppVar_4712 & cppMask_un_5_);
	cppVar_4713 = (0 << 5) | cppVar_4712;
	cppVar_4713 = (cppVar_4713 & cppMask_un_8_);
	cppVar_4715 = (cppVar_4713 == 130);
	if (cppVar_4715) {
	cppVar_4710 = DPL;
	} else {
	cppVar_4717 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4718 = (cppVar_4717 << 3) | 7;
	cppVar_4718 = (cppVar_4718 & cppMask_un_5_);
	cppVar_4719 = (0 << 5) | cppVar_4718;
	cppVar_4719 = (cppVar_4719 & cppMask_un_8_);
	cppVar_4721 = (cppVar_4719 == 131);
	if (cppVar_4721) {
	cppVar_4716 = DPH;
	} else {
	cppVar_4723 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4724 = (cppVar_4723 << 3) | 7;
	cppVar_4724 = (cppVar_4724 & cppMask_un_5_);
	cppVar_4725 = (0 << 5) | cppVar_4724;
	cppVar_4725 = (cppVar_4725 & cppMask_un_8_);
	cppVar_4727 = (cppVar_4725 == 135);
	if (cppVar_4727) {
	cppVar_4722 = PCON;
	} else {
	cppVar_4729 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4730 = (cppVar_4729 << 3) | 7;
	cppVar_4730 = (cppVar_4730 & cppMask_un_5_);
	cppVar_4731 = (0 << 5) | cppVar_4730;
	cppVar_4731 = (cppVar_4731 & cppMask_un_8_);
	cppVar_4733 = (cppVar_4731 == 136);
	if (cppVar_4733) {
	cppVar_4728 = TCON;
	} else {
	cppVar_4735 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4736 = (cppVar_4735 << 3) | 7;
	cppVar_4736 = (cppVar_4736 & cppMask_un_5_);
	cppVar_4737 = (0 << 5) | cppVar_4736;
	cppVar_4737 = (cppVar_4737 & cppMask_un_8_);
	cppVar_4739 = (cppVar_4737 == 137);
	if (cppVar_4739) {
	cppVar_4734 = TMOD;
	} else {
	cppVar_4741 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4742 = (cppVar_4741 << 3) | 7;
	cppVar_4742 = (cppVar_4742 & cppMask_un_5_);
	cppVar_4743 = (0 << 5) | cppVar_4742;
	cppVar_4743 = (cppVar_4743 & cppMask_un_8_);
	cppVar_4745 = (cppVar_4743 == 138);
	if (cppVar_4745) {
	cppVar_4740 = TL0;
	} else {
	cppVar_4747 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4748 = (cppVar_4747 << 3) | 7;
	cppVar_4748 = (cppVar_4748 & cppMask_un_5_);
	cppVar_4749 = (0 << 5) | cppVar_4748;
	cppVar_4749 = (cppVar_4749 & cppMask_un_8_);
	cppVar_4751 = (cppVar_4749 == 140);
	if (cppVar_4751) {
	cppVar_4746 = TH0;
	} else {
	cppVar_4753 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4754 = (cppVar_4753 << 3) | 7;
	cppVar_4754 = (cppVar_4754 & cppMask_un_5_);
	cppVar_4755 = (0 << 5) | cppVar_4754;
	cppVar_4755 = (cppVar_4755 & cppMask_un_8_);
	cppVar_4757 = (cppVar_4755 == 139);
	if (cppVar_4757) {
	cppVar_4752 = TL1;
	} else {
	cppVar_4759 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4760 = (cppVar_4759 << 3) | 7;
	cppVar_4760 = (cppVar_4760 & cppMask_un_5_);
	cppVar_4761 = (0 << 5) | cppVar_4760;
	cppVar_4761 = (cppVar_4761 & cppMask_un_8_);
	cppVar_4763 = (cppVar_4761 == 141);
	if (cppVar_4763) {
	cppVar_4758 = TH1;
	} else {
	cppVar_4765 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4766 = (cppVar_4765 << 3) | 7;
	cppVar_4766 = (cppVar_4766 & cppMask_un_5_);
	cppVar_4767 = (0 << 5) | cppVar_4766;
	cppVar_4767 = (cppVar_4767 & cppMask_un_8_);
	cppVar_4769 = (cppVar_4767 == 144);
	if (cppVar_4769) {
	cppVar_4764 = P1;
	} else {
	cppVar_4771 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4772 = (cppVar_4771 << 3) | 7;
	cppVar_4772 = (cppVar_4772 & cppMask_un_5_);
	cppVar_4773 = (0 << 5) | cppVar_4772;
	cppVar_4773 = (cppVar_4773 & cppMask_un_8_);
	cppVar_4775 = (cppVar_4773 == 152);
	if (cppVar_4775) {
	cppVar_4770 = SCON;
	} else {
	cppVar_4777 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4778 = (cppVar_4777 << 3) | 7;
	cppVar_4778 = (cppVar_4778 & cppMask_un_5_);
	cppVar_4779 = (0 << 5) | cppVar_4778;
	cppVar_4779 = (cppVar_4779 & cppMask_un_8_);
	cppVar_4781 = (cppVar_4779 == 153);
	if (cppVar_4781) {
	cppVar_4776 = SBUF;
	} else {
	cppVar_4783 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4784 = (cppVar_4783 << 3) | 7;
	cppVar_4784 = (cppVar_4784 & cppMask_un_5_);
	cppVar_4785 = (0 << 5) | cppVar_4784;
	cppVar_4785 = (cppVar_4785 & cppMask_un_8_);
	cppVar_4787 = (cppVar_4785 == 160);
	if (cppVar_4787) {
	cppVar_4782 = P2;
	} else {
	cppVar_4789 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4790 = (cppVar_4789 << 3) | 7;
	cppVar_4790 = (cppVar_4790 & cppMask_un_5_);
	cppVar_4791 = (0 << 5) | cppVar_4790;
	cppVar_4791 = (cppVar_4791 & cppMask_un_8_);
	cppVar_4793 = (cppVar_4791 == 168);
	if (cppVar_4793) {
	cppVar_4788 = IE;
	} else {
	cppVar_4795 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4796 = (cppVar_4795 << 3) | 7;
	cppVar_4796 = (cppVar_4796 & cppMask_un_5_);
	cppVar_4797 = (0 << 5) | cppVar_4796;
	cppVar_4797 = (cppVar_4797 & cppMask_un_8_);
	cppVar_4799 = (cppVar_4797 == 176);
	if (cppVar_4799) {
	cppVar_4794 = P3;
	} else {
	cppVar_4801 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4802 = (cppVar_4801 << 3) | 7;
	cppVar_4802 = (cppVar_4802 & cppMask_un_5_);
	cppVar_4803 = (0 << 5) | cppVar_4802;
	cppVar_4803 = (cppVar_4803 & cppMask_un_8_);
	cppVar_4805 = (cppVar_4803 == 184);
	if (cppVar_4805) {
	cppVar_4800 = IP;
	} else {
	cppVar_4807 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4808 = (cppVar_4807 << 3) | 7;
	cppVar_4808 = (cppVar_4808 & cppMask_un_5_);
	cppVar_4809 = (0 << 5) | cppVar_4808;
	cppVar_4809 = (cppVar_4809 & cppMask_un_8_);
	cppVar_4811 = (cppVar_4809 == 208);
	if (cppVar_4811) {
	cppVar_4806 = PSW;
	} else {
	cppVar_4813 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4814 = (cppVar_4813 << 3) | 7;
	cppVar_4814 = (cppVar_4814 & cppMask_un_5_);
	cppVar_4815 = (0 << 5) | cppVar_4814;
	cppVar_4815 = (cppVar_4815 & cppMask_un_8_);
	cppVar_4817 = (cppVar_4815 == 224);
	if (cppVar_4817) {
	cppVar_4812 = ACC;
	} else {
	cppVar_4819 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4820 = (cppVar_4819 << 3) | 7;
	cppVar_4820 = (cppVar_4820 & cppMask_un_5_);
	cppVar_4821 = (0 << 5) | cppVar_4820;
	cppVar_4821 = (cppVar_4821 & cppMask_un_8_);
	cppVar_4823 = (cppVar_4821 == 240);
	if (cppVar_4823) {
	cppVar_4818 = B;
	} else {
	cppVar_4818 = 0;
	}
	cppVar_4812 = cppVar_4818;
	}
	cppVar_4806 = cppVar_4812;
	}
	cppVar_4800 = cppVar_4806;
	}
	cppVar_4794 = cppVar_4800;
	}
	cppVar_4788 = cppVar_4794;
	}
	cppVar_4782 = cppVar_4788;
	}
	cppVar_4776 = cppVar_4782;
	}
	cppVar_4770 = cppVar_4776;
	}
	cppVar_4764 = cppVar_4770;
	}
	cppVar_4758 = cppVar_4764;
	}
	cppVar_4752 = cppVar_4758;
	}
	cppVar_4746 = cppVar_4752;
	}
	cppVar_4740 = cppVar_4746;
	}
	cppVar_4734 = cppVar_4740;
	}
	cppVar_4728 = cppVar_4734;
	}
	cppVar_4722 = cppVar_4728;
	}
	cppVar_4716 = cppVar_4722;
	}
	cppVar_4710 = cppVar_4716;
	}
	cppVar_4704 = cppVar_4710;
	}
	cppVar_4698 = cppVar_4704;
	}
	cppVar_4685 = cppVar_4698;
	}
	cppVar_4679 = cppVar_4685;
	} else {
	cppVar_4679 = B;
	}
	cppVar_4675 = cppVar_4679;
	} else {
	cppVar_4826 = ROM.rd(PC);
	cppVar_4828 = (cppVar_4826 == 142);
	if (cppVar_4828) {
	cppVar_4831 = PC + 1;
	cppVar_4831 = (cppVar_4831 & cppMask_un_16_);
	cppVar_4832 = ROM.rd(cppVar_4831);
	cppVar_4834 = (cppVar_4832 == 240);
	if (cppVar_4834) {
	cppVar_4837 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4839 = (cppVar_4837 << 3) | 6;
	cppVar_4839 = (cppVar_4839 & cppMask_un_5_);
	cppVar_4840 = (0 << 5) | cppVar_4839;
	cppVar_4840 = (cppVar_4840 & cppMask_un_8_);
	cppVar_4841 = (cppVar_4840 >> 7) & cppMask_un_1_;
	cppVar_4843 = (cppVar_4841 == 0);
	if (cppVar_4843) {
	cppVar_4844 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4845 = (cppVar_4844 << 3) | 6;
	cppVar_4845 = (cppVar_4845 & cppMask_un_5_);
	cppVar_4846 = (0 << 5) | cppVar_4845;
	cppVar_4846 = (cppVar_4846 & cppMask_un_8_);
	cppVar_4847 = IRAM.rd(cppVar_4846);
	cppVar_4835 = cppVar_4847;
	} else {
	cppVar_4849 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4850 = (cppVar_4849 << 3) | 6;
	cppVar_4850 = (cppVar_4850 & cppMask_un_5_);
	cppVar_4851 = (0 << 5) | cppVar_4850;
	cppVar_4851 = (cppVar_4851 & cppMask_un_8_);
	cppVar_4853 = (cppVar_4851 == 128);
	if (cppVar_4853) {
	cppVar_4848 = P0;
	} else {
	cppVar_4855 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4856 = (cppVar_4855 << 3) | 6;
	cppVar_4856 = (cppVar_4856 & cppMask_un_5_);
	cppVar_4857 = (0 << 5) | cppVar_4856;
	cppVar_4857 = (cppVar_4857 & cppMask_un_8_);
	cppVar_4859 = (cppVar_4857 == 129);
	if (cppVar_4859) {
	cppVar_4854 = SP;
	} else {
	cppVar_4861 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4862 = (cppVar_4861 << 3) | 6;
	cppVar_4862 = (cppVar_4862 & cppMask_un_5_);
	cppVar_4863 = (0 << 5) | cppVar_4862;
	cppVar_4863 = (cppVar_4863 & cppMask_un_8_);
	cppVar_4865 = (cppVar_4863 == 130);
	if (cppVar_4865) {
	cppVar_4860 = DPL;
	} else {
	cppVar_4867 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4868 = (cppVar_4867 << 3) | 6;
	cppVar_4868 = (cppVar_4868 & cppMask_un_5_);
	cppVar_4869 = (0 << 5) | cppVar_4868;
	cppVar_4869 = (cppVar_4869 & cppMask_un_8_);
	cppVar_4871 = (cppVar_4869 == 131);
	if (cppVar_4871) {
	cppVar_4866 = DPH;
	} else {
	cppVar_4873 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4874 = (cppVar_4873 << 3) | 6;
	cppVar_4874 = (cppVar_4874 & cppMask_un_5_);
	cppVar_4875 = (0 << 5) | cppVar_4874;
	cppVar_4875 = (cppVar_4875 & cppMask_un_8_);
	cppVar_4877 = (cppVar_4875 == 135);
	if (cppVar_4877) {
	cppVar_4872 = PCON;
	} else {
	cppVar_4879 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4880 = (cppVar_4879 << 3) | 6;
	cppVar_4880 = (cppVar_4880 & cppMask_un_5_);
	cppVar_4881 = (0 << 5) | cppVar_4880;
	cppVar_4881 = (cppVar_4881 & cppMask_un_8_);
	cppVar_4883 = (cppVar_4881 == 136);
	if (cppVar_4883) {
	cppVar_4878 = TCON;
	} else {
	cppVar_4885 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4886 = (cppVar_4885 << 3) | 6;
	cppVar_4886 = (cppVar_4886 & cppMask_un_5_);
	cppVar_4887 = (0 << 5) | cppVar_4886;
	cppVar_4887 = (cppVar_4887 & cppMask_un_8_);
	cppVar_4889 = (cppVar_4887 == 137);
	if (cppVar_4889) {
	cppVar_4884 = TMOD;
	} else {
	cppVar_4891 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4892 = (cppVar_4891 << 3) | 6;
	cppVar_4892 = (cppVar_4892 & cppMask_un_5_);
	cppVar_4893 = (0 << 5) | cppVar_4892;
	cppVar_4893 = (cppVar_4893 & cppMask_un_8_);
	cppVar_4895 = (cppVar_4893 == 138);
	if (cppVar_4895) {
	cppVar_4890 = TL0;
	} else {
	cppVar_4897 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4898 = (cppVar_4897 << 3) | 6;
	cppVar_4898 = (cppVar_4898 & cppMask_un_5_);
	cppVar_4899 = (0 << 5) | cppVar_4898;
	cppVar_4899 = (cppVar_4899 & cppMask_un_8_);
	cppVar_4901 = (cppVar_4899 == 140);
	if (cppVar_4901) {
	cppVar_4896 = TH0;
	} else {
	cppVar_4903 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4904 = (cppVar_4903 << 3) | 6;
	cppVar_4904 = (cppVar_4904 & cppMask_un_5_);
	cppVar_4905 = (0 << 5) | cppVar_4904;
	cppVar_4905 = (cppVar_4905 & cppMask_un_8_);
	cppVar_4907 = (cppVar_4905 == 139);
	if (cppVar_4907) {
	cppVar_4902 = TL1;
	} else {
	cppVar_4909 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4910 = (cppVar_4909 << 3) | 6;
	cppVar_4910 = (cppVar_4910 & cppMask_un_5_);
	cppVar_4911 = (0 << 5) | cppVar_4910;
	cppVar_4911 = (cppVar_4911 & cppMask_un_8_);
	cppVar_4913 = (cppVar_4911 == 141);
	if (cppVar_4913) {
	cppVar_4908 = TH1;
	} else {
	cppVar_4915 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4916 = (cppVar_4915 << 3) | 6;
	cppVar_4916 = (cppVar_4916 & cppMask_un_5_);
	cppVar_4917 = (0 << 5) | cppVar_4916;
	cppVar_4917 = (cppVar_4917 & cppMask_un_8_);
	cppVar_4919 = (cppVar_4917 == 144);
	if (cppVar_4919) {
	cppVar_4914 = P1;
	} else {
	cppVar_4921 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4922 = (cppVar_4921 << 3) | 6;
	cppVar_4922 = (cppVar_4922 & cppMask_un_5_);
	cppVar_4923 = (0 << 5) | cppVar_4922;
	cppVar_4923 = (cppVar_4923 & cppMask_un_8_);
	cppVar_4925 = (cppVar_4923 == 152);
	if (cppVar_4925) {
	cppVar_4920 = SCON;
	} else {
	cppVar_4927 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4928 = (cppVar_4927 << 3) | 6;
	cppVar_4928 = (cppVar_4928 & cppMask_un_5_);
	cppVar_4929 = (0 << 5) | cppVar_4928;
	cppVar_4929 = (cppVar_4929 & cppMask_un_8_);
	cppVar_4931 = (cppVar_4929 == 153);
	if (cppVar_4931) {
	cppVar_4926 = SBUF;
	} else {
	cppVar_4933 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4934 = (cppVar_4933 << 3) | 6;
	cppVar_4934 = (cppVar_4934 & cppMask_un_5_);
	cppVar_4935 = (0 << 5) | cppVar_4934;
	cppVar_4935 = (cppVar_4935 & cppMask_un_8_);
	cppVar_4937 = (cppVar_4935 == 160);
	if (cppVar_4937) {
	cppVar_4932 = P2;
	} else {
	cppVar_4939 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4940 = (cppVar_4939 << 3) | 6;
	cppVar_4940 = (cppVar_4940 & cppMask_un_5_);
	cppVar_4941 = (0 << 5) | cppVar_4940;
	cppVar_4941 = (cppVar_4941 & cppMask_un_8_);
	cppVar_4943 = (cppVar_4941 == 168);
	if (cppVar_4943) {
	cppVar_4938 = IE;
	} else {
	cppVar_4945 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4946 = (cppVar_4945 << 3) | 6;
	cppVar_4946 = (cppVar_4946 & cppMask_un_5_);
	cppVar_4947 = (0 << 5) | cppVar_4946;
	cppVar_4947 = (cppVar_4947 & cppMask_un_8_);
	cppVar_4949 = (cppVar_4947 == 176);
	if (cppVar_4949) {
	cppVar_4944 = P3;
	} else {
	cppVar_4951 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4952 = (cppVar_4951 << 3) | 6;
	cppVar_4952 = (cppVar_4952 & cppMask_un_5_);
	cppVar_4953 = (0 << 5) | cppVar_4952;
	cppVar_4953 = (cppVar_4953 & cppMask_un_8_);
	cppVar_4955 = (cppVar_4953 == 184);
	if (cppVar_4955) {
	cppVar_4950 = IP;
	} else {
	cppVar_4957 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4958 = (cppVar_4957 << 3) | 6;
	cppVar_4958 = (cppVar_4958 & cppMask_un_5_);
	cppVar_4959 = (0 << 5) | cppVar_4958;
	cppVar_4959 = (cppVar_4959 & cppMask_un_8_);
	cppVar_4961 = (cppVar_4959 == 208);
	if (cppVar_4961) {
	cppVar_4956 = PSW;
	} else {
	cppVar_4963 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4964 = (cppVar_4963 << 3) | 6;
	cppVar_4964 = (cppVar_4964 & cppMask_un_5_);
	cppVar_4965 = (0 << 5) | cppVar_4964;
	cppVar_4965 = (cppVar_4965 & cppMask_un_8_);
	cppVar_4967 = (cppVar_4965 == 224);
	if (cppVar_4967) {
	cppVar_4962 = ACC;
	} else {
	cppVar_4969 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4970 = (cppVar_4969 << 3) | 6;
	cppVar_4970 = (cppVar_4970 & cppMask_un_5_);
	cppVar_4971 = (0 << 5) | cppVar_4970;
	cppVar_4971 = (cppVar_4971 & cppMask_un_8_);
	cppVar_4973 = (cppVar_4971 == 240);
	if (cppVar_4973) {
	cppVar_4968 = B;
	} else {
	cppVar_4968 = 0;
	}
	cppVar_4962 = cppVar_4968;
	}
	cppVar_4956 = cppVar_4962;
	}
	cppVar_4950 = cppVar_4956;
	}
	cppVar_4944 = cppVar_4950;
	}
	cppVar_4938 = cppVar_4944;
	}
	cppVar_4932 = cppVar_4938;
	}
	cppVar_4926 = cppVar_4932;
	}
	cppVar_4920 = cppVar_4926;
	}
	cppVar_4914 = cppVar_4920;
	}
	cppVar_4908 = cppVar_4914;
	}
	cppVar_4902 = cppVar_4908;
	}
	cppVar_4896 = cppVar_4902;
	}
	cppVar_4890 = cppVar_4896;
	}
	cppVar_4884 = cppVar_4890;
	}
	cppVar_4878 = cppVar_4884;
	}
	cppVar_4872 = cppVar_4878;
	}
	cppVar_4866 = cppVar_4872;
	}
	cppVar_4860 = cppVar_4866;
	}
	cppVar_4854 = cppVar_4860;
	}
	cppVar_4848 = cppVar_4854;
	}
	cppVar_4835 = cppVar_4848;
	}
	cppVar_4829 = cppVar_4835;
	} else {
	cppVar_4829 = B;
	}
	cppVar_4825 = cppVar_4829;
	} else {
	cppVar_4976 = ROM.rd(PC);
	cppVar_4978 = (cppVar_4976 == 141);
	if (cppVar_4978) {
	cppVar_4981 = PC + 1;
	cppVar_4981 = (cppVar_4981 & cppMask_un_16_);
	cppVar_4982 = ROM.rd(cppVar_4981);
	cppVar_4984 = (cppVar_4982 == 240);
	if (cppVar_4984) {
	cppVar_4987 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4989 = (cppVar_4987 << 3) | 5;
	cppVar_4989 = (cppVar_4989 & cppMask_un_5_);
	cppVar_4990 = (0 << 5) | cppVar_4989;
	cppVar_4990 = (cppVar_4990 & cppMask_un_8_);
	cppVar_4991 = (cppVar_4990 >> 7) & cppMask_un_1_;
	cppVar_4993 = (cppVar_4991 == 0);
	if (cppVar_4993) {
	cppVar_4994 = (PSW >> 3) & cppMask_un_2_;
	cppVar_4995 = (cppVar_4994 << 3) | 5;
	cppVar_4995 = (cppVar_4995 & cppMask_un_5_);
	cppVar_4996 = (0 << 5) | cppVar_4995;
	cppVar_4996 = (cppVar_4996 & cppMask_un_8_);
	cppVar_4997 = IRAM.rd(cppVar_4996);
	cppVar_4985 = cppVar_4997;
	} else {
	cppVar_4999 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5000 = (cppVar_4999 << 3) | 5;
	cppVar_5000 = (cppVar_5000 & cppMask_un_5_);
	cppVar_5001 = (0 << 5) | cppVar_5000;
	cppVar_5001 = (cppVar_5001 & cppMask_un_8_);
	cppVar_5003 = (cppVar_5001 == 128);
	if (cppVar_5003) {
	cppVar_4998 = P0;
	} else {
	cppVar_5005 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5006 = (cppVar_5005 << 3) | 5;
	cppVar_5006 = (cppVar_5006 & cppMask_un_5_);
	cppVar_5007 = (0 << 5) | cppVar_5006;
	cppVar_5007 = (cppVar_5007 & cppMask_un_8_);
	cppVar_5009 = (cppVar_5007 == 129);
	if (cppVar_5009) {
	cppVar_5004 = SP;
	} else {
	cppVar_5011 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5012 = (cppVar_5011 << 3) | 5;
	cppVar_5012 = (cppVar_5012 & cppMask_un_5_);
	cppVar_5013 = (0 << 5) | cppVar_5012;
	cppVar_5013 = (cppVar_5013 & cppMask_un_8_);
	cppVar_5015 = (cppVar_5013 == 130);
	if (cppVar_5015) {
	cppVar_5010 = DPL;
	} else {
	cppVar_5017 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5018 = (cppVar_5017 << 3) | 5;
	cppVar_5018 = (cppVar_5018 & cppMask_un_5_);
	cppVar_5019 = (0 << 5) | cppVar_5018;
	cppVar_5019 = (cppVar_5019 & cppMask_un_8_);
	cppVar_5021 = (cppVar_5019 == 131);
	if (cppVar_5021) {
	cppVar_5016 = DPH;
	} else {
	cppVar_5023 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5024 = (cppVar_5023 << 3) | 5;
	cppVar_5024 = (cppVar_5024 & cppMask_un_5_);
	cppVar_5025 = (0 << 5) | cppVar_5024;
	cppVar_5025 = (cppVar_5025 & cppMask_un_8_);
	cppVar_5027 = (cppVar_5025 == 135);
	if (cppVar_5027) {
	cppVar_5022 = PCON;
	} else {
	cppVar_5029 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5030 = (cppVar_5029 << 3) | 5;
	cppVar_5030 = (cppVar_5030 & cppMask_un_5_);
	cppVar_5031 = (0 << 5) | cppVar_5030;
	cppVar_5031 = (cppVar_5031 & cppMask_un_8_);
	cppVar_5033 = (cppVar_5031 == 136);
	if (cppVar_5033) {
	cppVar_5028 = TCON;
	} else {
	cppVar_5035 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5036 = (cppVar_5035 << 3) | 5;
	cppVar_5036 = (cppVar_5036 & cppMask_un_5_);
	cppVar_5037 = (0 << 5) | cppVar_5036;
	cppVar_5037 = (cppVar_5037 & cppMask_un_8_);
	cppVar_5039 = (cppVar_5037 == 137);
	if (cppVar_5039) {
	cppVar_5034 = TMOD;
	} else {
	cppVar_5041 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5042 = (cppVar_5041 << 3) | 5;
	cppVar_5042 = (cppVar_5042 & cppMask_un_5_);
	cppVar_5043 = (0 << 5) | cppVar_5042;
	cppVar_5043 = (cppVar_5043 & cppMask_un_8_);
	cppVar_5045 = (cppVar_5043 == 138);
	if (cppVar_5045) {
	cppVar_5040 = TL0;
	} else {
	cppVar_5047 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5048 = (cppVar_5047 << 3) | 5;
	cppVar_5048 = (cppVar_5048 & cppMask_un_5_);
	cppVar_5049 = (0 << 5) | cppVar_5048;
	cppVar_5049 = (cppVar_5049 & cppMask_un_8_);
	cppVar_5051 = (cppVar_5049 == 140);
	if (cppVar_5051) {
	cppVar_5046 = TH0;
	} else {
	cppVar_5053 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5054 = (cppVar_5053 << 3) | 5;
	cppVar_5054 = (cppVar_5054 & cppMask_un_5_);
	cppVar_5055 = (0 << 5) | cppVar_5054;
	cppVar_5055 = (cppVar_5055 & cppMask_un_8_);
	cppVar_5057 = (cppVar_5055 == 139);
	if (cppVar_5057) {
	cppVar_5052 = TL1;
	} else {
	cppVar_5059 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5060 = (cppVar_5059 << 3) | 5;
	cppVar_5060 = (cppVar_5060 & cppMask_un_5_);
	cppVar_5061 = (0 << 5) | cppVar_5060;
	cppVar_5061 = (cppVar_5061 & cppMask_un_8_);
	cppVar_5063 = (cppVar_5061 == 141);
	if (cppVar_5063) {
	cppVar_5058 = TH1;
	} else {
	cppVar_5065 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5066 = (cppVar_5065 << 3) | 5;
	cppVar_5066 = (cppVar_5066 & cppMask_un_5_);
	cppVar_5067 = (0 << 5) | cppVar_5066;
	cppVar_5067 = (cppVar_5067 & cppMask_un_8_);
	cppVar_5069 = (cppVar_5067 == 144);
	if (cppVar_5069) {
	cppVar_5064 = P1;
	} else {
	cppVar_5071 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5072 = (cppVar_5071 << 3) | 5;
	cppVar_5072 = (cppVar_5072 & cppMask_un_5_);
	cppVar_5073 = (0 << 5) | cppVar_5072;
	cppVar_5073 = (cppVar_5073 & cppMask_un_8_);
	cppVar_5075 = (cppVar_5073 == 152);
	if (cppVar_5075) {
	cppVar_5070 = SCON;
	} else {
	cppVar_5077 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5078 = (cppVar_5077 << 3) | 5;
	cppVar_5078 = (cppVar_5078 & cppMask_un_5_);
	cppVar_5079 = (0 << 5) | cppVar_5078;
	cppVar_5079 = (cppVar_5079 & cppMask_un_8_);
	cppVar_5081 = (cppVar_5079 == 153);
	if (cppVar_5081) {
	cppVar_5076 = SBUF;
	} else {
	cppVar_5083 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5084 = (cppVar_5083 << 3) | 5;
	cppVar_5084 = (cppVar_5084 & cppMask_un_5_);
	cppVar_5085 = (0 << 5) | cppVar_5084;
	cppVar_5085 = (cppVar_5085 & cppMask_un_8_);
	cppVar_5087 = (cppVar_5085 == 160);
	if (cppVar_5087) {
	cppVar_5082 = P2;
	} else {
	cppVar_5089 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5090 = (cppVar_5089 << 3) | 5;
	cppVar_5090 = (cppVar_5090 & cppMask_un_5_);
	cppVar_5091 = (0 << 5) | cppVar_5090;
	cppVar_5091 = (cppVar_5091 & cppMask_un_8_);
	cppVar_5093 = (cppVar_5091 == 168);
	if (cppVar_5093) {
	cppVar_5088 = IE;
	} else {
	cppVar_5095 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5096 = (cppVar_5095 << 3) | 5;
	cppVar_5096 = (cppVar_5096 & cppMask_un_5_);
	cppVar_5097 = (0 << 5) | cppVar_5096;
	cppVar_5097 = (cppVar_5097 & cppMask_un_8_);
	cppVar_5099 = (cppVar_5097 == 176);
	if (cppVar_5099) {
	cppVar_5094 = P3;
	} else {
	cppVar_5101 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5102 = (cppVar_5101 << 3) | 5;
	cppVar_5102 = (cppVar_5102 & cppMask_un_5_);
	cppVar_5103 = (0 << 5) | cppVar_5102;
	cppVar_5103 = (cppVar_5103 & cppMask_un_8_);
	cppVar_5105 = (cppVar_5103 == 184);
	if (cppVar_5105) {
	cppVar_5100 = IP;
	} else {
	cppVar_5107 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5108 = (cppVar_5107 << 3) | 5;
	cppVar_5108 = (cppVar_5108 & cppMask_un_5_);
	cppVar_5109 = (0 << 5) | cppVar_5108;
	cppVar_5109 = (cppVar_5109 & cppMask_un_8_);
	cppVar_5111 = (cppVar_5109 == 208);
	if (cppVar_5111) {
	cppVar_5106 = PSW;
	} else {
	cppVar_5113 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5114 = (cppVar_5113 << 3) | 5;
	cppVar_5114 = (cppVar_5114 & cppMask_un_5_);
	cppVar_5115 = (0 << 5) | cppVar_5114;
	cppVar_5115 = (cppVar_5115 & cppMask_un_8_);
	cppVar_5117 = (cppVar_5115 == 224);
	if (cppVar_5117) {
	cppVar_5112 = ACC;
	} else {
	cppVar_5119 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5120 = (cppVar_5119 << 3) | 5;
	cppVar_5120 = (cppVar_5120 & cppMask_un_5_);
	cppVar_5121 = (0 << 5) | cppVar_5120;
	cppVar_5121 = (cppVar_5121 & cppMask_un_8_);
	cppVar_5123 = (cppVar_5121 == 240);
	if (cppVar_5123) {
	cppVar_5118 = B;
	} else {
	cppVar_5118 = 0;
	}
	cppVar_5112 = cppVar_5118;
	}
	cppVar_5106 = cppVar_5112;
	}
	cppVar_5100 = cppVar_5106;
	}
	cppVar_5094 = cppVar_5100;
	}
	cppVar_5088 = cppVar_5094;
	}
	cppVar_5082 = cppVar_5088;
	}
	cppVar_5076 = cppVar_5082;
	}
	cppVar_5070 = cppVar_5076;
	}
	cppVar_5064 = cppVar_5070;
	}
	cppVar_5058 = cppVar_5064;
	}
	cppVar_5052 = cppVar_5058;
	}
	cppVar_5046 = cppVar_5052;
	}
	cppVar_5040 = cppVar_5046;
	}
	cppVar_5034 = cppVar_5040;
	}
	cppVar_5028 = cppVar_5034;
	}
	cppVar_5022 = cppVar_5028;
	}
	cppVar_5016 = cppVar_5022;
	}
	cppVar_5010 = cppVar_5016;
	}
	cppVar_5004 = cppVar_5010;
	}
	cppVar_4998 = cppVar_5004;
	}
	cppVar_4985 = cppVar_4998;
	}
	cppVar_4979 = cppVar_4985;
	} else {
	cppVar_4979 = B;
	}
	cppVar_4975 = cppVar_4979;
	} else {
	cppVar_5126 = ROM.rd(PC);
	cppVar_5128 = (cppVar_5126 == 140);
	if (cppVar_5128) {
	cppVar_5131 = PC + 1;
	cppVar_5131 = (cppVar_5131 & cppMask_un_16_);
	cppVar_5132 = ROM.rd(cppVar_5131);
	cppVar_5134 = (cppVar_5132 == 240);
	if (cppVar_5134) {
	cppVar_5137 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5139 = (cppVar_5137 << 3) | 4;
	cppVar_5139 = (cppVar_5139 & cppMask_un_5_);
	cppVar_5140 = (0 << 5) | cppVar_5139;
	cppVar_5140 = (cppVar_5140 & cppMask_un_8_);
	cppVar_5141 = (cppVar_5140 >> 7) & cppMask_un_1_;
	cppVar_5143 = (cppVar_5141 == 0);
	if (cppVar_5143) {
	cppVar_5144 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5145 = (cppVar_5144 << 3) | 4;
	cppVar_5145 = (cppVar_5145 & cppMask_un_5_);
	cppVar_5146 = (0 << 5) | cppVar_5145;
	cppVar_5146 = (cppVar_5146 & cppMask_un_8_);
	cppVar_5147 = IRAM.rd(cppVar_5146);
	cppVar_5135 = cppVar_5147;
	} else {
	cppVar_5149 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5150 = (cppVar_5149 << 3) | 4;
	cppVar_5150 = (cppVar_5150 & cppMask_un_5_);
	cppVar_5151 = (0 << 5) | cppVar_5150;
	cppVar_5151 = (cppVar_5151 & cppMask_un_8_);
	cppVar_5153 = (cppVar_5151 == 128);
	if (cppVar_5153) {
	cppVar_5148 = P0;
	} else {
	cppVar_5155 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5156 = (cppVar_5155 << 3) | 4;
	cppVar_5156 = (cppVar_5156 & cppMask_un_5_);
	cppVar_5157 = (0 << 5) | cppVar_5156;
	cppVar_5157 = (cppVar_5157 & cppMask_un_8_);
	cppVar_5159 = (cppVar_5157 == 129);
	if (cppVar_5159) {
	cppVar_5154 = SP;
	} else {
	cppVar_5161 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5162 = (cppVar_5161 << 3) | 4;
	cppVar_5162 = (cppVar_5162 & cppMask_un_5_);
	cppVar_5163 = (0 << 5) | cppVar_5162;
	cppVar_5163 = (cppVar_5163 & cppMask_un_8_);
	cppVar_5165 = (cppVar_5163 == 130);
	if (cppVar_5165) {
	cppVar_5160 = DPL;
	} else {
	cppVar_5167 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5168 = (cppVar_5167 << 3) | 4;
	cppVar_5168 = (cppVar_5168 & cppMask_un_5_);
	cppVar_5169 = (0 << 5) | cppVar_5168;
	cppVar_5169 = (cppVar_5169 & cppMask_un_8_);
	cppVar_5171 = (cppVar_5169 == 131);
	if (cppVar_5171) {
	cppVar_5166 = DPH;
	} else {
	cppVar_5173 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5174 = (cppVar_5173 << 3) | 4;
	cppVar_5174 = (cppVar_5174 & cppMask_un_5_);
	cppVar_5175 = (0 << 5) | cppVar_5174;
	cppVar_5175 = (cppVar_5175 & cppMask_un_8_);
	cppVar_5177 = (cppVar_5175 == 135);
	if (cppVar_5177) {
	cppVar_5172 = PCON;
	} else {
	cppVar_5179 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5180 = (cppVar_5179 << 3) | 4;
	cppVar_5180 = (cppVar_5180 & cppMask_un_5_);
	cppVar_5181 = (0 << 5) | cppVar_5180;
	cppVar_5181 = (cppVar_5181 & cppMask_un_8_);
	cppVar_5183 = (cppVar_5181 == 136);
	if (cppVar_5183) {
	cppVar_5178 = TCON;
	} else {
	cppVar_5185 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5186 = (cppVar_5185 << 3) | 4;
	cppVar_5186 = (cppVar_5186 & cppMask_un_5_);
	cppVar_5187 = (0 << 5) | cppVar_5186;
	cppVar_5187 = (cppVar_5187 & cppMask_un_8_);
	cppVar_5189 = (cppVar_5187 == 137);
	if (cppVar_5189) {
	cppVar_5184 = TMOD;
	} else {
	cppVar_5191 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5192 = (cppVar_5191 << 3) | 4;
	cppVar_5192 = (cppVar_5192 & cppMask_un_5_);
	cppVar_5193 = (0 << 5) | cppVar_5192;
	cppVar_5193 = (cppVar_5193 & cppMask_un_8_);
	cppVar_5195 = (cppVar_5193 == 138);
	if (cppVar_5195) {
	cppVar_5190 = TL0;
	} else {
	cppVar_5197 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5198 = (cppVar_5197 << 3) | 4;
	cppVar_5198 = (cppVar_5198 & cppMask_un_5_);
	cppVar_5199 = (0 << 5) | cppVar_5198;
	cppVar_5199 = (cppVar_5199 & cppMask_un_8_);
	cppVar_5201 = (cppVar_5199 == 140);
	if (cppVar_5201) {
	cppVar_5196 = TH0;
	} else {
	cppVar_5203 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5204 = (cppVar_5203 << 3) | 4;
	cppVar_5204 = (cppVar_5204 & cppMask_un_5_);
	cppVar_5205 = (0 << 5) | cppVar_5204;
	cppVar_5205 = (cppVar_5205 & cppMask_un_8_);
	cppVar_5207 = (cppVar_5205 == 139);
	if (cppVar_5207) {
	cppVar_5202 = TL1;
	} else {
	cppVar_5209 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5210 = (cppVar_5209 << 3) | 4;
	cppVar_5210 = (cppVar_5210 & cppMask_un_5_);
	cppVar_5211 = (0 << 5) | cppVar_5210;
	cppVar_5211 = (cppVar_5211 & cppMask_un_8_);
	cppVar_5213 = (cppVar_5211 == 141);
	if (cppVar_5213) {
	cppVar_5208 = TH1;
	} else {
	cppVar_5215 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5216 = (cppVar_5215 << 3) | 4;
	cppVar_5216 = (cppVar_5216 & cppMask_un_5_);
	cppVar_5217 = (0 << 5) | cppVar_5216;
	cppVar_5217 = (cppVar_5217 & cppMask_un_8_);
	cppVar_5219 = (cppVar_5217 == 144);
	if (cppVar_5219) {
	cppVar_5214 = P1;
	} else {
	cppVar_5221 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5222 = (cppVar_5221 << 3) | 4;
	cppVar_5222 = (cppVar_5222 & cppMask_un_5_);
	cppVar_5223 = (0 << 5) | cppVar_5222;
	cppVar_5223 = (cppVar_5223 & cppMask_un_8_);
	cppVar_5225 = (cppVar_5223 == 152);
	if (cppVar_5225) {
	cppVar_5220 = SCON;
	} else {
	cppVar_5227 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5228 = (cppVar_5227 << 3) | 4;
	cppVar_5228 = (cppVar_5228 & cppMask_un_5_);
	cppVar_5229 = (0 << 5) | cppVar_5228;
	cppVar_5229 = (cppVar_5229 & cppMask_un_8_);
	cppVar_5231 = (cppVar_5229 == 153);
	if (cppVar_5231) {
	cppVar_5226 = SBUF;
	} else {
	cppVar_5233 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5234 = (cppVar_5233 << 3) | 4;
	cppVar_5234 = (cppVar_5234 & cppMask_un_5_);
	cppVar_5235 = (0 << 5) | cppVar_5234;
	cppVar_5235 = (cppVar_5235 & cppMask_un_8_);
	cppVar_5237 = (cppVar_5235 == 160);
	if (cppVar_5237) {
	cppVar_5232 = P2;
	} else {
	cppVar_5239 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5240 = (cppVar_5239 << 3) | 4;
	cppVar_5240 = (cppVar_5240 & cppMask_un_5_);
	cppVar_5241 = (0 << 5) | cppVar_5240;
	cppVar_5241 = (cppVar_5241 & cppMask_un_8_);
	cppVar_5243 = (cppVar_5241 == 168);
	if (cppVar_5243) {
	cppVar_5238 = IE;
	} else {
	cppVar_5245 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5246 = (cppVar_5245 << 3) | 4;
	cppVar_5246 = (cppVar_5246 & cppMask_un_5_);
	cppVar_5247 = (0 << 5) | cppVar_5246;
	cppVar_5247 = (cppVar_5247 & cppMask_un_8_);
	cppVar_5249 = (cppVar_5247 == 176);
	if (cppVar_5249) {
	cppVar_5244 = P3;
	} else {
	cppVar_5251 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5252 = (cppVar_5251 << 3) | 4;
	cppVar_5252 = (cppVar_5252 & cppMask_un_5_);
	cppVar_5253 = (0 << 5) | cppVar_5252;
	cppVar_5253 = (cppVar_5253 & cppMask_un_8_);
	cppVar_5255 = (cppVar_5253 == 184);
	if (cppVar_5255) {
	cppVar_5250 = IP;
	} else {
	cppVar_5257 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5258 = (cppVar_5257 << 3) | 4;
	cppVar_5258 = (cppVar_5258 & cppMask_un_5_);
	cppVar_5259 = (0 << 5) | cppVar_5258;
	cppVar_5259 = (cppVar_5259 & cppMask_un_8_);
	cppVar_5261 = (cppVar_5259 == 208);
	if (cppVar_5261) {
	cppVar_5256 = PSW;
	} else {
	cppVar_5263 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5264 = (cppVar_5263 << 3) | 4;
	cppVar_5264 = (cppVar_5264 & cppMask_un_5_);
	cppVar_5265 = (0 << 5) | cppVar_5264;
	cppVar_5265 = (cppVar_5265 & cppMask_un_8_);
	cppVar_5267 = (cppVar_5265 == 224);
	if (cppVar_5267) {
	cppVar_5262 = ACC;
	} else {
	cppVar_5269 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5270 = (cppVar_5269 << 3) | 4;
	cppVar_5270 = (cppVar_5270 & cppMask_un_5_);
	cppVar_5271 = (0 << 5) | cppVar_5270;
	cppVar_5271 = (cppVar_5271 & cppMask_un_8_);
	cppVar_5273 = (cppVar_5271 == 240);
	if (cppVar_5273) {
	cppVar_5268 = B;
	} else {
	cppVar_5268 = 0;
	}
	cppVar_5262 = cppVar_5268;
	}
	cppVar_5256 = cppVar_5262;
	}
	cppVar_5250 = cppVar_5256;
	}
	cppVar_5244 = cppVar_5250;
	}
	cppVar_5238 = cppVar_5244;
	}
	cppVar_5232 = cppVar_5238;
	}
	cppVar_5226 = cppVar_5232;
	}
	cppVar_5220 = cppVar_5226;
	}
	cppVar_5214 = cppVar_5220;
	}
	cppVar_5208 = cppVar_5214;
	}
	cppVar_5202 = cppVar_5208;
	}
	cppVar_5196 = cppVar_5202;
	}
	cppVar_5190 = cppVar_5196;
	}
	cppVar_5184 = cppVar_5190;
	}
	cppVar_5178 = cppVar_5184;
	}
	cppVar_5172 = cppVar_5178;
	}
	cppVar_5166 = cppVar_5172;
	}
	cppVar_5160 = cppVar_5166;
	}
	cppVar_5154 = cppVar_5160;
	}
	cppVar_5148 = cppVar_5154;
	}
	cppVar_5135 = cppVar_5148;
	}
	cppVar_5129 = cppVar_5135;
	} else {
	cppVar_5129 = B;
	}
	cppVar_5125 = cppVar_5129;
	} else {
	cppVar_5276 = ROM.rd(PC);
	cppVar_5278 = (cppVar_5276 == 139);
	if (cppVar_5278) {
	cppVar_5281 = PC + 1;
	cppVar_5281 = (cppVar_5281 & cppMask_un_16_);
	cppVar_5282 = ROM.rd(cppVar_5281);
	cppVar_5284 = (cppVar_5282 == 240);
	if (cppVar_5284) {
	cppVar_5287 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5289 = (cppVar_5287 << 3) | 3;
	cppVar_5289 = (cppVar_5289 & cppMask_un_5_);
	cppVar_5290 = (0 << 5) | cppVar_5289;
	cppVar_5290 = (cppVar_5290 & cppMask_un_8_);
	cppVar_5291 = (cppVar_5290 >> 7) & cppMask_un_1_;
	cppVar_5293 = (cppVar_5291 == 0);
	if (cppVar_5293) {
	cppVar_5294 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5295 = (cppVar_5294 << 3) | 3;
	cppVar_5295 = (cppVar_5295 & cppMask_un_5_);
	cppVar_5296 = (0 << 5) | cppVar_5295;
	cppVar_5296 = (cppVar_5296 & cppMask_un_8_);
	cppVar_5297 = IRAM.rd(cppVar_5296);
	cppVar_5285 = cppVar_5297;
	} else {
	cppVar_5299 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5300 = (cppVar_5299 << 3) | 3;
	cppVar_5300 = (cppVar_5300 & cppMask_un_5_);
	cppVar_5301 = (0 << 5) | cppVar_5300;
	cppVar_5301 = (cppVar_5301 & cppMask_un_8_);
	cppVar_5303 = (cppVar_5301 == 128);
	if (cppVar_5303) {
	cppVar_5298 = P0;
	} else {
	cppVar_5305 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5306 = (cppVar_5305 << 3) | 3;
	cppVar_5306 = (cppVar_5306 & cppMask_un_5_);
	cppVar_5307 = (0 << 5) | cppVar_5306;
	cppVar_5307 = (cppVar_5307 & cppMask_un_8_);
	cppVar_5309 = (cppVar_5307 == 129);
	if (cppVar_5309) {
	cppVar_5304 = SP;
	} else {
	cppVar_5311 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5312 = (cppVar_5311 << 3) | 3;
	cppVar_5312 = (cppVar_5312 & cppMask_un_5_);
	cppVar_5313 = (0 << 5) | cppVar_5312;
	cppVar_5313 = (cppVar_5313 & cppMask_un_8_);
	cppVar_5315 = (cppVar_5313 == 130);
	if (cppVar_5315) {
	cppVar_5310 = DPL;
	} else {
	cppVar_5317 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5318 = (cppVar_5317 << 3) | 3;
	cppVar_5318 = (cppVar_5318 & cppMask_un_5_);
	cppVar_5319 = (0 << 5) | cppVar_5318;
	cppVar_5319 = (cppVar_5319 & cppMask_un_8_);
	cppVar_5321 = (cppVar_5319 == 131);
	if (cppVar_5321) {
	cppVar_5316 = DPH;
	} else {
	cppVar_5323 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5324 = (cppVar_5323 << 3) | 3;
	cppVar_5324 = (cppVar_5324 & cppMask_un_5_);
	cppVar_5325 = (0 << 5) | cppVar_5324;
	cppVar_5325 = (cppVar_5325 & cppMask_un_8_);
	cppVar_5327 = (cppVar_5325 == 135);
	if (cppVar_5327) {
	cppVar_5322 = PCON;
	} else {
	cppVar_5329 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5330 = (cppVar_5329 << 3) | 3;
	cppVar_5330 = (cppVar_5330 & cppMask_un_5_);
	cppVar_5331 = (0 << 5) | cppVar_5330;
	cppVar_5331 = (cppVar_5331 & cppMask_un_8_);
	cppVar_5333 = (cppVar_5331 == 136);
	if (cppVar_5333) {
	cppVar_5328 = TCON;
	} else {
	cppVar_5335 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5336 = (cppVar_5335 << 3) | 3;
	cppVar_5336 = (cppVar_5336 & cppMask_un_5_);
	cppVar_5337 = (0 << 5) | cppVar_5336;
	cppVar_5337 = (cppVar_5337 & cppMask_un_8_);
	cppVar_5339 = (cppVar_5337 == 137);
	if (cppVar_5339) {
	cppVar_5334 = TMOD;
	} else {
	cppVar_5341 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5342 = (cppVar_5341 << 3) | 3;
	cppVar_5342 = (cppVar_5342 & cppMask_un_5_);
	cppVar_5343 = (0 << 5) | cppVar_5342;
	cppVar_5343 = (cppVar_5343 & cppMask_un_8_);
	cppVar_5345 = (cppVar_5343 == 138);
	if (cppVar_5345) {
	cppVar_5340 = TL0;
	} else {
	cppVar_5347 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5348 = (cppVar_5347 << 3) | 3;
	cppVar_5348 = (cppVar_5348 & cppMask_un_5_);
	cppVar_5349 = (0 << 5) | cppVar_5348;
	cppVar_5349 = (cppVar_5349 & cppMask_un_8_);
	cppVar_5351 = (cppVar_5349 == 140);
	if (cppVar_5351) {
	cppVar_5346 = TH0;
	} else {
	cppVar_5353 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5354 = (cppVar_5353 << 3) | 3;
	cppVar_5354 = (cppVar_5354 & cppMask_un_5_);
	cppVar_5355 = (0 << 5) | cppVar_5354;
	cppVar_5355 = (cppVar_5355 & cppMask_un_8_);
	cppVar_5357 = (cppVar_5355 == 139);
	if (cppVar_5357) {
	cppVar_5352 = TL1;
	} else {
	cppVar_5359 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5360 = (cppVar_5359 << 3) | 3;
	cppVar_5360 = (cppVar_5360 & cppMask_un_5_);
	cppVar_5361 = (0 << 5) | cppVar_5360;
	cppVar_5361 = (cppVar_5361 & cppMask_un_8_);
	cppVar_5363 = (cppVar_5361 == 141);
	if (cppVar_5363) {
	cppVar_5358 = TH1;
	} else {
	cppVar_5365 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5366 = (cppVar_5365 << 3) | 3;
	cppVar_5366 = (cppVar_5366 & cppMask_un_5_);
	cppVar_5367 = (0 << 5) | cppVar_5366;
	cppVar_5367 = (cppVar_5367 & cppMask_un_8_);
	cppVar_5369 = (cppVar_5367 == 144);
	if (cppVar_5369) {
	cppVar_5364 = P1;
	} else {
	cppVar_5371 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5372 = (cppVar_5371 << 3) | 3;
	cppVar_5372 = (cppVar_5372 & cppMask_un_5_);
	cppVar_5373 = (0 << 5) | cppVar_5372;
	cppVar_5373 = (cppVar_5373 & cppMask_un_8_);
	cppVar_5375 = (cppVar_5373 == 152);
	if (cppVar_5375) {
	cppVar_5370 = SCON;
	} else {
	cppVar_5377 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5378 = (cppVar_5377 << 3) | 3;
	cppVar_5378 = (cppVar_5378 & cppMask_un_5_);
	cppVar_5379 = (0 << 5) | cppVar_5378;
	cppVar_5379 = (cppVar_5379 & cppMask_un_8_);
	cppVar_5381 = (cppVar_5379 == 153);
	if (cppVar_5381) {
	cppVar_5376 = SBUF;
	} else {
	cppVar_5383 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5384 = (cppVar_5383 << 3) | 3;
	cppVar_5384 = (cppVar_5384 & cppMask_un_5_);
	cppVar_5385 = (0 << 5) | cppVar_5384;
	cppVar_5385 = (cppVar_5385 & cppMask_un_8_);
	cppVar_5387 = (cppVar_5385 == 160);
	if (cppVar_5387) {
	cppVar_5382 = P2;
	} else {
	cppVar_5389 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5390 = (cppVar_5389 << 3) | 3;
	cppVar_5390 = (cppVar_5390 & cppMask_un_5_);
	cppVar_5391 = (0 << 5) | cppVar_5390;
	cppVar_5391 = (cppVar_5391 & cppMask_un_8_);
	cppVar_5393 = (cppVar_5391 == 168);
	if (cppVar_5393) {
	cppVar_5388 = IE;
	} else {
	cppVar_5395 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5396 = (cppVar_5395 << 3) | 3;
	cppVar_5396 = (cppVar_5396 & cppMask_un_5_);
	cppVar_5397 = (0 << 5) | cppVar_5396;
	cppVar_5397 = (cppVar_5397 & cppMask_un_8_);
	cppVar_5399 = (cppVar_5397 == 176);
	if (cppVar_5399) {
	cppVar_5394 = P3;
	} else {
	cppVar_5401 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5402 = (cppVar_5401 << 3) | 3;
	cppVar_5402 = (cppVar_5402 & cppMask_un_5_);
	cppVar_5403 = (0 << 5) | cppVar_5402;
	cppVar_5403 = (cppVar_5403 & cppMask_un_8_);
	cppVar_5405 = (cppVar_5403 == 184);
	if (cppVar_5405) {
	cppVar_5400 = IP;
	} else {
	cppVar_5407 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5408 = (cppVar_5407 << 3) | 3;
	cppVar_5408 = (cppVar_5408 & cppMask_un_5_);
	cppVar_5409 = (0 << 5) | cppVar_5408;
	cppVar_5409 = (cppVar_5409 & cppMask_un_8_);
	cppVar_5411 = (cppVar_5409 == 208);
	if (cppVar_5411) {
	cppVar_5406 = PSW;
	} else {
	cppVar_5413 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5414 = (cppVar_5413 << 3) | 3;
	cppVar_5414 = (cppVar_5414 & cppMask_un_5_);
	cppVar_5415 = (0 << 5) | cppVar_5414;
	cppVar_5415 = (cppVar_5415 & cppMask_un_8_);
	cppVar_5417 = (cppVar_5415 == 224);
	if (cppVar_5417) {
	cppVar_5412 = ACC;
	} else {
	cppVar_5419 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5420 = (cppVar_5419 << 3) | 3;
	cppVar_5420 = (cppVar_5420 & cppMask_un_5_);
	cppVar_5421 = (0 << 5) | cppVar_5420;
	cppVar_5421 = (cppVar_5421 & cppMask_un_8_);
	cppVar_5423 = (cppVar_5421 == 240);
	if (cppVar_5423) {
	cppVar_5418 = B;
	} else {
	cppVar_5418 = 0;
	}
	cppVar_5412 = cppVar_5418;
	}
	cppVar_5406 = cppVar_5412;
	}
	cppVar_5400 = cppVar_5406;
	}
	cppVar_5394 = cppVar_5400;
	}
	cppVar_5388 = cppVar_5394;
	}
	cppVar_5382 = cppVar_5388;
	}
	cppVar_5376 = cppVar_5382;
	}
	cppVar_5370 = cppVar_5376;
	}
	cppVar_5364 = cppVar_5370;
	}
	cppVar_5358 = cppVar_5364;
	}
	cppVar_5352 = cppVar_5358;
	}
	cppVar_5346 = cppVar_5352;
	}
	cppVar_5340 = cppVar_5346;
	}
	cppVar_5334 = cppVar_5340;
	}
	cppVar_5328 = cppVar_5334;
	}
	cppVar_5322 = cppVar_5328;
	}
	cppVar_5316 = cppVar_5322;
	}
	cppVar_5310 = cppVar_5316;
	}
	cppVar_5304 = cppVar_5310;
	}
	cppVar_5298 = cppVar_5304;
	}
	cppVar_5285 = cppVar_5298;
	}
	cppVar_5279 = cppVar_5285;
	} else {
	cppVar_5279 = B;
	}
	cppVar_5275 = cppVar_5279;
	} else {
	cppVar_5426 = ROM.rd(PC);
	cppVar_5428 = (cppVar_5426 == 138);
	if (cppVar_5428) {
	cppVar_5431 = PC + 1;
	cppVar_5431 = (cppVar_5431 & cppMask_un_16_);
	cppVar_5432 = ROM.rd(cppVar_5431);
	cppVar_5434 = (cppVar_5432 == 240);
	if (cppVar_5434) {
	cppVar_5437 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5439 = (cppVar_5437 << 3) | 2;
	cppVar_5439 = (cppVar_5439 & cppMask_un_5_);
	cppVar_5440 = (0 << 5) | cppVar_5439;
	cppVar_5440 = (cppVar_5440 & cppMask_un_8_);
	cppVar_5441 = (cppVar_5440 >> 7) & cppMask_un_1_;
	cppVar_5443 = (cppVar_5441 == 0);
	if (cppVar_5443) {
	cppVar_5444 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5445 = (cppVar_5444 << 3) | 2;
	cppVar_5445 = (cppVar_5445 & cppMask_un_5_);
	cppVar_5446 = (0 << 5) | cppVar_5445;
	cppVar_5446 = (cppVar_5446 & cppMask_un_8_);
	cppVar_5447 = IRAM.rd(cppVar_5446);
	cppVar_5435 = cppVar_5447;
	} else {
	cppVar_5449 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5450 = (cppVar_5449 << 3) | 2;
	cppVar_5450 = (cppVar_5450 & cppMask_un_5_);
	cppVar_5451 = (0 << 5) | cppVar_5450;
	cppVar_5451 = (cppVar_5451 & cppMask_un_8_);
	cppVar_5453 = (cppVar_5451 == 128);
	if (cppVar_5453) {
	cppVar_5448 = P0;
	} else {
	cppVar_5455 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5456 = (cppVar_5455 << 3) | 2;
	cppVar_5456 = (cppVar_5456 & cppMask_un_5_);
	cppVar_5457 = (0 << 5) | cppVar_5456;
	cppVar_5457 = (cppVar_5457 & cppMask_un_8_);
	cppVar_5459 = (cppVar_5457 == 129);
	if (cppVar_5459) {
	cppVar_5454 = SP;
	} else {
	cppVar_5461 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5462 = (cppVar_5461 << 3) | 2;
	cppVar_5462 = (cppVar_5462 & cppMask_un_5_);
	cppVar_5463 = (0 << 5) | cppVar_5462;
	cppVar_5463 = (cppVar_5463 & cppMask_un_8_);
	cppVar_5465 = (cppVar_5463 == 130);
	if (cppVar_5465) {
	cppVar_5460 = DPL;
	} else {
	cppVar_5467 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5468 = (cppVar_5467 << 3) | 2;
	cppVar_5468 = (cppVar_5468 & cppMask_un_5_);
	cppVar_5469 = (0 << 5) | cppVar_5468;
	cppVar_5469 = (cppVar_5469 & cppMask_un_8_);
	cppVar_5471 = (cppVar_5469 == 131);
	if (cppVar_5471) {
	cppVar_5466 = DPH;
	} else {
	cppVar_5473 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5474 = (cppVar_5473 << 3) | 2;
	cppVar_5474 = (cppVar_5474 & cppMask_un_5_);
	cppVar_5475 = (0 << 5) | cppVar_5474;
	cppVar_5475 = (cppVar_5475 & cppMask_un_8_);
	cppVar_5477 = (cppVar_5475 == 135);
	if (cppVar_5477) {
	cppVar_5472 = PCON;
	} else {
	cppVar_5479 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5480 = (cppVar_5479 << 3) | 2;
	cppVar_5480 = (cppVar_5480 & cppMask_un_5_);
	cppVar_5481 = (0 << 5) | cppVar_5480;
	cppVar_5481 = (cppVar_5481 & cppMask_un_8_);
	cppVar_5483 = (cppVar_5481 == 136);
	if (cppVar_5483) {
	cppVar_5478 = TCON;
	} else {
	cppVar_5485 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5486 = (cppVar_5485 << 3) | 2;
	cppVar_5486 = (cppVar_5486 & cppMask_un_5_);
	cppVar_5487 = (0 << 5) | cppVar_5486;
	cppVar_5487 = (cppVar_5487 & cppMask_un_8_);
	cppVar_5489 = (cppVar_5487 == 137);
	if (cppVar_5489) {
	cppVar_5484 = TMOD;
	} else {
	cppVar_5491 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5492 = (cppVar_5491 << 3) | 2;
	cppVar_5492 = (cppVar_5492 & cppMask_un_5_);
	cppVar_5493 = (0 << 5) | cppVar_5492;
	cppVar_5493 = (cppVar_5493 & cppMask_un_8_);
	cppVar_5495 = (cppVar_5493 == 138);
	if (cppVar_5495) {
	cppVar_5490 = TL0;
	} else {
	cppVar_5497 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5498 = (cppVar_5497 << 3) | 2;
	cppVar_5498 = (cppVar_5498 & cppMask_un_5_);
	cppVar_5499 = (0 << 5) | cppVar_5498;
	cppVar_5499 = (cppVar_5499 & cppMask_un_8_);
	cppVar_5501 = (cppVar_5499 == 140);
	if (cppVar_5501) {
	cppVar_5496 = TH0;
	} else {
	cppVar_5503 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5504 = (cppVar_5503 << 3) | 2;
	cppVar_5504 = (cppVar_5504 & cppMask_un_5_);
	cppVar_5505 = (0 << 5) | cppVar_5504;
	cppVar_5505 = (cppVar_5505 & cppMask_un_8_);
	cppVar_5507 = (cppVar_5505 == 139);
	if (cppVar_5507) {
	cppVar_5502 = TL1;
	} else {
	cppVar_5509 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5510 = (cppVar_5509 << 3) | 2;
	cppVar_5510 = (cppVar_5510 & cppMask_un_5_);
	cppVar_5511 = (0 << 5) | cppVar_5510;
	cppVar_5511 = (cppVar_5511 & cppMask_un_8_);
	cppVar_5513 = (cppVar_5511 == 141);
	if (cppVar_5513) {
	cppVar_5508 = TH1;
	} else {
	cppVar_5515 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5516 = (cppVar_5515 << 3) | 2;
	cppVar_5516 = (cppVar_5516 & cppMask_un_5_);
	cppVar_5517 = (0 << 5) | cppVar_5516;
	cppVar_5517 = (cppVar_5517 & cppMask_un_8_);
	cppVar_5519 = (cppVar_5517 == 144);
	if (cppVar_5519) {
	cppVar_5514 = P1;
	} else {
	cppVar_5521 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5522 = (cppVar_5521 << 3) | 2;
	cppVar_5522 = (cppVar_5522 & cppMask_un_5_);
	cppVar_5523 = (0 << 5) | cppVar_5522;
	cppVar_5523 = (cppVar_5523 & cppMask_un_8_);
	cppVar_5525 = (cppVar_5523 == 152);
	if (cppVar_5525) {
	cppVar_5520 = SCON;
	} else {
	cppVar_5527 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5528 = (cppVar_5527 << 3) | 2;
	cppVar_5528 = (cppVar_5528 & cppMask_un_5_);
	cppVar_5529 = (0 << 5) | cppVar_5528;
	cppVar_5529 = (cppVar_5529 & cppMask_un_8_);
	cppVar_5531 = (cppVar_5529 == 153);
	if (cppVar_5531) {
	cppVar_5526 = SBUF;
	} else {
	cppVar_5533 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5534 = (cppVar_5533 << 3) | 2;
	cppVar_5534 = (cppVar_5534 & cppMask_un_5_);
	cppVar_5535 = (0 << 5) | cppVar_5534;
	cppVar_5535 = (cppVar_5535 & cppMask_un_8_);
	cppVar_5537 = (cppVar_5535 == 160);
	if (cppVar_5537) {
	cppVar_5532 = P2;
	} else {
	cppVar_5539 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5540 = (cppVar_5539 << 3) | 2;
	cppVar_5540 = (cppVar_5540 & cppMask_un_5_);
	cppVar_5541 = (0 << 5) | cppVar_5540;
	cppVar_5541 = (cppVar_5541 & cppMask_un_8_);
	cppVar_5543 = (cppVar_5541 == 168);
	if (cppVar_5543) {
	cppVar_5538 = IE;
	} else {
	cppVar_5545 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5546 = (cppVar_5545 << 3) | 2;
	cppVar_5546 = (cppVar_5546 & cppMask_un_5_);
	cppVar_5547 = (0 << 5) | cppVar_5546;
	cppVar_5547 = (cppVar_5547 & cppMask_un_8_);
	cppVar_5549 = (cppVar_5547 == 176);
	if (cppVar_5549) {
	cppVar_5544 = P3;
	} else {
	cppVar_5551 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5552 = (cppVar_5551 << 3) | 2;
	cppVar_5552 = (cppVar_5552 & cppMask_un_5_);
	cppVar_5553 = (0 << 5) | cppVar_5552;
	cppVar_5553 = (cppVar_5553 & cppMask_un_8_);
	cppVar_5555 = (cppVar_5553 == 184);
	if (cppVar_5555) {
	cppVar_5550 = IP;
	} else {
	cppVar_5557 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5558 = (cppVar_5557 << 3) | 2;
	cppVar_5558 = (cppVar_5558 & cppMask_un_5_);
	cppVar_5559 = (0 << 5) | cppVar_5558;
	cppVar_5559 = (cppVar_5559 & cppMask_un_8_);
	cppVar_5561 = (cppVar_5559 == 208);
	if (cppVar_5561) {
	cppVar_5556 = PSW;
	} else {
	cppVar_5563 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5564 = (cppVar_5563 << 3) | 2;
	cppVar_5564 = (cppVar_5564 & cppMask_un_5_);
	cppVar_5565 = (0 << 5) | cppVar_5564;
	cppVar_5565 = (cppVar_5565 & cppMask_un_8_);
	cppVar_5567 = (cppVar_5565 == 224);
	if (cppVar_5567) {
	cppVar_5562 = ACC;
	} else {
	cppVar_5569 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5570 = (cppVar_5569 << 3) | 2;
	cppVar_5570 = (cppVar_5570 & cppMask_un_5_);
	cppVar_5571 = (0 << 5) | cppVar_5570;
	cppVar_5571 = (cppVar_5571 & cppMask_un_8_);
	cppVar_5573 = (cppVar_5571 == 240);
	if (cppVar_5573) {
	cppVar_5568 = B;
	} else {
	cppVar_5568 = 0;
	}
	cppVar_5562 = cppVar_5568;
	}
	cppVar_5556 = cppVar_5562;
	}
	cppVar_5550 = cppVar_5556;
	}
	cppVar_5544 = cppVar_5550;
	}
	cppVar_5538 = cppVar_5544;
	}
	cppVar_5532 = cppVar_5538;
	}
	cppVar_5526 = cppVar_5532;
	}
	cppVar_5520 = cppVar_5526;
	}
	cppVar_5514 = cppVar_5520;
	}
	cppVar_5508 = cppVar_5514;
	}
	cppVar_5502 = cppVar_5508;
	}
	cppVar_5496 = cppVar_5502;
	}
	cppVar_5490 = cppVar_5496;
	}
	cppVar_5484 = cppVar_5490;
	}
	cppVar_5478 = cppVar_5484;
	}
	cppVar_5472 = cppVar_5478;
	}
	cppVar_5466 = cppVar_5472;
	}
	cppVar_5460 = cppVar_5466;
	}
	cppVar_5454 = cppVar_5460;
	}
	cppVar_5448 = cppVar_5454;
	}
	cppVar_5435 = cppVar_5448;
	}
	cppVar_5429 = cppVar_5435;
	} else {
	cppVar_5429 = B;
	}
	cppVar_5425 = cppVar_5429;
	} else {
	cppVar_5576 = ROM.rd(PC);
	cppVar_5578 = (cppVar_5576 == 137);
	if (cppVar_5578) {
	cppVar_5581 = PC + 1;
	cppVar_5581 = (cppVar_5581 & cppMask_un_16_);
	cppVar_5582 = ROM.rd(cppVar_5581);
	cppVar_5584 = (cppVar_5582 == 240);
	if (cppVar_5584) {
	cppVar_5587 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5589 = (cppVar_5587 << 3) | 1;
	cppVar_5589 = (cppVar_5589 & cppMask_un_5_);
	cppVar_5590 = (0 << 5) | cppVar_5589;
	cppVar_5590 = (cppVar_5590 & cppMask_un_8_);
	cppVar_5591 = (cppVar_5590 >> 7) & cppMask_un_1_;
	cppVar_5593 = (cppVar_5591 == 0);
	if (cppVar_5593) {
	cppVar_5594 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5595 = (cppVar_5594 << 3) | 1;
	cppVar_5595 = (cppVar_5595 & cppMask_un_5_);
	cppVar_5596 = (0 << 5) | cppVar_5595;
	cppVar_5596 = (cppVar_5596 & cppMask_un_8_);
	cppVar_5597 = IRAM.rd(cppVar_5596);
	cppVar_5585 = cppVar_5597;
	} else {
	cppVar_5599 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5600 = (cppVar_5599 << 3) | 1;
	cppVar_5600 = (cppVar_5600 & cppMask_un_5_);
	cppVar_5601 = (0 << 5) | cppVar_5600;
	cppVar_5601 = (cppVar_5601 & cppMask_un_8_);
	cppVar_5603 = (cppVar_5601 == 128);
	if (cppVar_5603) {
	cppVar_5598 = P0;
	} else {
	cppVar_5605 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5606 = (cppVar_5605 << 3) | 1;
	cppVar_5606 = (cppVar_5606 & cppMask_un_5_);
	cppVar_5607 = (0 << 5) | cppVar_5606;
	cppVar_5607 = (cppVar_5607 & cppMask_un_8_);
	cppVar_5609 = (cppVar_5607 == 129);
	if (cppVar_5609) {
	cppVar_5604 = SP;
	} else {
	cppVar_5611 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5612 = (cppVar_5611 << 3) | 1;
	cppVar_5612 = (cppVar_5612 & cppMask_un_5_);
	cppVar_5613 = (0 << 5) | cppVar_5612;
	cppVar_5613 = (cppVar_5613 & cppMask_un_8_);
	cppVar_5615 = (cppVar_5613 == 130);
	if (cppVar_5615) {
	cppVar_5610 = DPL;
	} else {
	cppVar_5617 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5618 = (cppVar_5617 << 3) | 1;
	cppVar_5618 = (cppVar_5618 & cppMask_un_5_);
	cppVar_5619 = (0 << 5) | cppVar_5618;
	cppVar_5619 = (cppVar_5619 & cppMask_un_8_);
	cppVar_5621 = (cppVar_5619 == 131);
	if (cppVar_5621) {
	cppVar_5616 = DPH;
	} else {
	cppVar_5623 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5624 = (cppVar_5623 << 3) | 1;
	cppVar_5624 = (cppVar_5624 & cppMask_un_5_);
	cppVar_5625 = (0 << 5) | cppVar_5624;
	cppVar_5625 = (cppVar_5625 & cppMask_un_8_);
	cppVar_5627 = (cppVar_5625 == 135);
	if (cppVar_5627) {
	cppVar_5622 = PCON;
	} else {
	cppVar_5629 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5630 = (cppVar_5629 << 3) | 1;
	cppVar_5630 = (cppVar_5630 & cppMask_un_5_);
	cppVar_5631 = (0 << 5) | cppVar_5630;
	cppVar_5631 = (cppVar_5631 & cppMask_un_8_);
	cppVar_5633 = (cppVar_5631 == 136);
	if (cppVar_5633) {
	cppVar_5628 = TCON;
	} else {
	cppVar_5635 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5636 = (cppVar_5635 << 3) | 1;
	cppVar_5636 = (cppVar_5636 & cppMask_un_5_);
	cppVar_5637 = (0 << 5) | cppVar_5636;
	cppVar_5637 = (cppVar_5637 & cppMask_un_8_);
	cppVar_5639 = (cppVar_5637 == 137);
	if (cppVar_5639) {
	cppVar_5634 = TMOD;
	} else {
	cppVar_5641 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5642 = (cppVar_5641 << 3) | 1;
	cppVar_5642 = (cppVar_5642 & cppMask_un_5_);
	cppVar_5643 = (0 << 5) | cppVar_5642;
	cppVar_5643 = (cppVar_5643 & cppMask_un_8_);
	cppVar_5645 = (cppVar_5643 == 138);
	if (cppVar_5645) {
	cppVar_5640 = TL0;
	} else {
	cppVar_5647 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5648 = (cppVar_5647 << 3) | 1;
	cppVar_5648 = (cppVar_5648 & cppMask_un_5_);
	cppVar_5649 = (0 << 5) | cppVar_5648;
	cppVar_5649 = (cppVar_5649 & cppMask_un_8_);
	cppVar_5651 = (cppVar_5649 == 140);
	if (cppVar_5651) {
	cppVar_5646 = TH0;
	} else {
	cppVar_5653 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5654 = (cppVar_5653 << 3) | 1;
	cppVar_5654 = (cppVar_5654 & cppMask_un_5_);
	cppVar_5655 = (0 << 5) | cppVar_5654;
	cppVar_5655 = (cppVar_5655 & cppMask_un_8_);
	cppVar_5657 = (cppVar_5655 == 139);
	if (cppVar_5657) {
	cppVar_5652 = TL1;
	} else {
	cppVar_5659 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5660 = (cppVar_5659 << 3) | 1;
	cppVar_5660 = (cppVar_5660 & cppMask_un_5_);
	cppVar_5661 = (0 << 5) | cppVar_5660;
	cppVar_5661 = (cppVar_5661 & cppMask_un_8_);
	cppVar_5663 = (cppVar_5661 == 141);
	if (cppVar_5663) {
	cppVar_5658 = TH1;
	} else {
	cppVar_5665 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5666 = (cppVar_5665 << 3) | 1;
	cppVar_5666 = (cppVar_5666 & cppMask_un_5_);
	cppVar_5667 = (0 << 5) | cppVar_5666;
	cppVar_5667 = (cppVar_5667 & cppMask_un_8_);
	cppVar_5669 = (cppVar_5667 == 144);
	if (cppVar_5669) {
	cppVar_5664 = P1;
	} else {
	cppVar_5671 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5672 = (cppVar_5671 << 3) | 1;
	cppVar_5672 = (cppVar_5672 & cppMask_un_5_);
	cppVar_5673 = (0 << 5) | cppVar_5672;
	cppVar_5673 = (cppVar_5673 & cppMask_un_8_);
	cppVar_5675 = (cppVar_5673 == 152);
	if (cppVar_5675) {
	cppVar_5670 = SCON;
	} else {
	cppVar_5677 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5678 = (cppVar_5677 << 3) | 1;
	cppVar_5678 = (cppVar_5678 & cppMask_un_5_);
	cppVar_5679 = (0 << 5) | cppVar_5678;
	cppVar_5679 = (cppVar_5679 & cppMask_un_8_);
	cppVar_5681 = (cppVar_5679 == 153);
	if (cppVar_5681) {
	cppVar_5676 = SBUF;
	} else {
	cppVar_5683 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5684 = (cppVar_5683 << 3) | 1;
	cppVar_5684 = (cppVar_5684 & cppMask_un_5_);
	cppVar_5685 = (0 << 5) | cppVar_5684;
	cppVar_5685 = (cppVar_5685 & cppMask_un_8_);
	cppVar_5687 = (cppVar_5685 == 160);
	if (cppVar_5687) {
	cppVar_5682 = P2;
	} else {
	cppVar_5689 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5690 = (cppVar_5689 << 3) | 1;
	cppVar_5690 = (cppVar_5690 & cppMask_un_5_);
	cppVar_5691 = (0 << 5) | cppVar_5690;
	cppVar_5691 = (cppVar_5691 & cppMask_un_8_);
	cppVar_5693 = (cppVar_5691 == 168);
	if (cppVar_5693) {
	cppVar_5688 = IE;
	} else {
	cppVar_5695 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5696 = (cppVar_5695 << 3) | 1;
	cppVar_5696 = (cppVar_5696 & cppMask_un_5_);
	cppVar_5697 = (0 << 5) | cppVar_5696;
	cppVar_5697 = (cppVar_5697 & cppMask_un_8_);
	cppVar_5699 = (cppVar_5697 == 176);
	if (cppVar_5699) {
	cppVar_5694 = P3;
	} else {
	cppVar_5701 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5702 = (cppVar_5701 << 3) | 1;
	cppVar_5702 = (cppVar_5702 & cppMask_un_5_);
	cppVar_5703 = (0 << 5) | cppVar_5702;
	cppVar_5703 = (cppVar_5703 & cppMask_un_8_);
	cppVar_5705 = (cppVar_5703 == 184);
	if (cppVar_5705) {
	cppVar_5700 = IP;
	} else {
	cppVar_5707 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5708 = (cppVar_5707 << 3) | 1;
	cppVar_5708 = (cppVar_5708 & cppMask_un_5_);
	cppVar_5709 = (0 << 5) | cppVar_5708;
	cppVar_5709 = (cppVar_5709 & cppMask_un_8_);
	cppVar_5711 = (cppVar_5709 == 208);
	if (cppVar_5711) {
	cppVar_5706 = PSW;
	} else {
	cppVar_5713 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5714 = (cppVar_5713 << 3) | 1;
	cppVar_5714 = (cppVar_5714 & cppMask_un_5_);
	cppVar_5715 = (0 << 5) | cppVar_5714;
	cppVar_5715 = (cppVar_5715 & cppMask_un_8_);
	cppVar_5717 = (cppVar_5715 == 224);
	if (cppVar_5717) {
	cppVar_5712 = ACC;
	} else {
	cppVar_5719 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5720 = (cppVar_5719 << 3) | 1;
	cppVar_5720 = (cppVar_5720 & cppMask_un_5_);
	cppVar_5721 = (0 << 5) | cppVar_5720;
	cppVar_5721 = (cppVar_5721 & cppMask_un_8_);
	cppVar_5723 = (cppVar_5721 == 240);
	if (cppVar_5723) {
	cppVar_5718 = B;
	} else {
	cppVar_5718 = 0;
	}
	cppVar_5712 = cppVar_5718;
	}
	cppVar_5706 = cppVar_5712;
	}
	cppVar_5700 = cppVar_5706;
	}
	cppVar_5694 = cppVar_5700;
	}
	cppVar_5688 = cppVar_5694;
	}
	cppVar_5682 = cppVar_5688;
	}
	cppVar_5676 = cppVar_5682;
	}
	cppVar_5670 = cppVar_5676;
	}
	cppVar_5664 = cppVar_5670;
	}
	cppVar_5658 = cppVar_5664;
	}
	cppVar_5652 = cppVar_5658;
	}
	cppVar_5646 = cppVar_5652;
	}
	cppVar_5640 = cppVar_5646;
	}
	cppVar_5634 = cppVar_5640;
	}
	cppVar_5628 = cppVar_5634;
	}
	cppVar_5622 = cppVar_5628;
	}
	cppVar_5616 = cppVar_5622;
	}
	cppVar_5610 = cppVar_5616;
	}
	cppVar_5604 = cppVar_5610;
	}
	cppVar_5598 = cppVar_5604;
	}
	cppVar_5585 = cppVar_5598;
	}
	cppVar_5579 = cppVar_5585;
	} else {
	cppVar_5579 = B;
	}
	cppVar_5575 = cppVar_5579;
	} else {
	cppVar_5726 = ROM.rd(PC);
	cppVar_5728 = (cppVar_5726 == 136);
	if (cppVar_5728) {
	cppVar_5731 = PC + 1;
	cppVar_5731 = (cppVar_5731 & cppMask_un_16_);
	cppVar_5732 = ROM.rd(cppVar_5731);
	cppVar_5734 = (cppVar_5732 == 240);
	if (cppVar_5734) {
	cppVar_5737 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5739 = (cppVar_5737 << 3) | 0;
	cppVar_5739 = (cppVar_5739 & cppMask_un_5_);
	cppVar_5740 = (0 << 5) | cppVar_5739;
	cppVar_5740 = (cppVar_5740 & cppMask_un_8_);
	cppVar_5741 = (cppVar_5740 >> 7) & cppMask_un_1_;
	cppVar_5743 = (cppVar_5741 == 0);
	if (cppVar_5743) {
	cppVar_5744 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5745 = (cppVar_5744 << 3) | 0;
	cppVar_5745 = (cppVar_5745 & cppMask_un_5_);
	cppVar_5746 = (0 << 5) | cppVar_5745;
	cppVar_5746 = (cppVar_5746 & cppMask_un_8_);
	cppVar_5747 = IRAM.rd(cppVar_5746);
	cppVar_5735 = cppVar_5747;
	} else {
	cppVar_5749 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5750 = (cppVar_5749 << 3) | 0;
	cppVar_5750 = (cppVar_5750 & cppMask_un_5_);
	cppVar_5751 = (0 << 5) | cppVar_5750;
	cppVar_5751 = (cppVar_5751 & cppMask_un_8_);
	cppVar_5753 = (cppVar_5751 == 128);
	if (cppVar_5753) {
	cppVar_5748 = P0;
	} else {
	cppVar_5755 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5756 = (cppVar_5755 << 3) | 0;
	cppVar_5756 = (cppVar_5756 & cppMask_un_5_);
	cppVar_5757 = (0 << 5) | cppVar_5756;
	cppVar_5757 = (cppVar_5757 & cppMask_un_8_);
	cppVar_5759 = (cppVar_5757 == 129);
	if (cppVar_5759) {
	cppVar_5754 = SP;
	} else {
	cppVar_5761 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5762 = (cppVar_5761 << 3) | 0;
	cppVar_5762 = (cppVar_5762 & cppMask_un_5_);
	cppVar_5763 = (0 << 5) | cppVar_5762;
	cppVar_5763 = (cppVar_5763 & cppMask_un_8_);
	cppVar_5765 = (cppVar_5763 == 130);
	if (cppVar_5765) {
	cppVar_5760 = DPL;
	} else {
	cppVar_5767 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5768 = (cppVar_5767 << 3) | 0;
	cppVar_5768 = (cppVar_5768 & cppMask_un_5_);
	cppVar_5769 = (0 << 5) | cppVar_5768;
	cppVar_5769 = (cppVar_5769 & cppMask_un_8_);
	cppVar_5771 = (cppVar_5769 == 131);
	if (cppVar_5771) {
	cppVar_5766 = DPH;
	} else {
	cppVar_5773 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5774 = (cppVar_5773 << 3) | 0;
	cppVar_5774 = (cppVar_5774 & cppMask_un_5_);
	cppVar_5775 = (0 << 5) | cppVar_5774;
	cppVar_5775 = (cppVar_5775 & cppMask_un_8_);
	cppVar_5777 = (cppVar_5775 == 135);
	if (cppVar_5777) {
	cppVar_5772 = PCON;
	} else {
	cppVar_5779 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5780 = (cppVar_5779 << 3) | 0;
	cppVar_5780 = (cppVar_5780 & cppMask_un_5_);
	cppVar_5781 = (0 << 5) | cppVar_5780;
	cppVar_5781 = (cppVar_5781 & cppMask_un_8_);
	cppVar_5783 = (cppVar_5781 == 136);
	if (cppVar_5783) {
	cppVar_5778 = TCON;
	} else {
	cppVar_5785 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5786 = (cppVar_5785 << 3) | 0;
	cppVar_5786 = (cppVar_5786 & cppMask_un_5_);
	cppVar_5787 = (0 << 5) | cppVar_5786;
	cppVar_5787 = (cppVar_5787 & cppMask_un_8_);
	cppVar_5789 = (cppVar_5787 == 137);
	if (cppVar_5789) {
	cppVar_5784 = TMOD;
	} else {
	cppVar_5791 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5792 = (cppVar_5791 << 3) | 0;
	cppVar_5792 = (cppVar_5792 & cppMask_un_5_);
	cppVar_5793 = (0 << 5) | cppVar_5792;
	cppVar_5793 = (cppVar_5793 & cppMask_un_8_);
	cppVar_5795 = (cppVar_5793 == 138);
	if (cppVar_5795) {
	cppVar_5790 = TL0;
	} else {
	cppVar_5797 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5798 = (cppVar_5797 << 3) | 0;
	cppVar_5798 = (cppVar_5798 & cppMask_un_5_);
	cppVar_5799 = (0 << 5) | cppVar_5798;
	cppVar_5799 = (cppVar_5799 & cppMask_un_8_);
	cppVar_5801 = (cppVar_5799 == 140);
	if (cppVar_5801) {
	cppVar_5796 = TH0;
	} else {
	cppVar_5803 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5804 = (cppVar_5803 << 3) | 0;
	cppVar_5804 = (cppVar_5804 & cppMask_un_5_);
	cppVar_5805 = (0 << 5) | cppVar_5804;
	cppVar_5805 = (cppVar_5805 & cppMask_un_8_);
	cppVar_5807 = (cppVar_5805 == 139);
	if (cppVar_5807) {
	cppVar_5802 = TL1;
	} else {
	cppVar_5809 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5810 = (cppVar_5809 << 3) | 0;
	cppVar_5810 = (cppVar_5810 & cppMask_un_5_);
	cppVar_5811 = (0 << 5) | cppVar_5810;
	cppVar_5811 = (cppVar_5811 & cppMask_un_8_);
	cppVar_5813 = (cppVar_5811 == 141);
	if (cppVar_5813) {
	cppVar_5808 = TH1;
	} else {
	cppVar_5815 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5816 = (cppVar_5815 << 3) | 0;
	cppVar_5816 = (cppVar_5816 & cppMask_un_5_);
	cppVar_5817 = (0 << 5) | cppVar_5816;
	cppVar_5817 = (cppVar_5817 & cppMask_un_8_);
	cppVar_5819 = (cppVar_5817 == 144);
	if (cppVar_5819) {
	cppVar_5814 = P1;
	} else {
	cppVar_5821 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5822 = (cppVar_5821 << 3) | 0;
	cppVar_5822 = (cppVar_5822 & cppMask_un_5_);
	cppVar_5823 = (0 << 5) | cppVar_5822;
	cppVar_5823 = (cppVar_5823 & cppMask_un_8_);
	cppVar_5825 = (cppVar_5823 == 152);
	if (cppVar_5825) {
	cppVar_5820 = SCON;
	} else {
	cppVar_5827 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5828 = (cppVar_5827 << 3) | 0;
	cppVar_5828 = (cppVar_5828 & cppMask_un_5_);
	cppVar_5829 = (0 << 5) | cppVar_5828;
	cppVar_5829 = (cppVar_5829 & cppMask_un_8_);
	cppVar_5831 = (cppVar_5829 == 153);
	if (cppVar_5831) {
	cppVar_5826 = SBUF;
	} else {
	cppVar_5833 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5834 = (cppVar_5833 << 3) | 0;
	cppVar_5834 = (cppVar_5834 & cppMask_un_5_);
	cppVar_5835 = (0 << 5) | cppVar_5834;
	cppVar_5835 = (cppVar_5835 & cppMask_un_8_);
	cppVar_5837 = (cppVar_5835 == 160);
	if (cppVar_5837) {
	cppVar_5832 = P2;
	} else {
	cppVar_5839 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5840 = (cppVar_5839 << 3) | 0;
	cppVar_5840 = (cppVar_5840 & cppMask_un_5_);
	cppVar_5841 = (0 << 5) | cppVar_5840;
	cppVar_5841 = (cppVar_5841 & cppMask_un_8_);
	cppVar_5843 = (cppVar_5841 == 168);
	if (cppVar_5843) {
	cppVar_5838 = IE;
	} else {
	cppVar_5845 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5846 = (cppVar_5845 << 3) | 0;
	cppVar_5846 = (cppVar_5846 & cppMask_un_5_);
	cppVar_5847 = (0 << 5) | cppVar_5846;
	cppVar_5847 = (cppVar_5847 & cppMask_un_8_);
	cppVar_5849 = (cppVar_5847 == 176);
	if (cppVar_5849) {
	cppVar_5844 = P3;
	} else {
	cppVar_5851 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5852 = (cppVar_5851 << 3) | 0;
	cppVar_5852 = (cppVar_5852 & cppMask_un_5_);
	cppVar_5853 = (0 << 5) | cppVar_5852;
	cppVar_5853 = (cppVar_5853 & cppMask_un_8_);
	cppVar_5855 = (cppVar_5853 == 184);
	if (cppVar_5855) {
	cppVar_5850 = IP;
	} else {
	cppVar_5857 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5858 = (cppVar_5857 << 3) | 0;
	cppVar_5858 = (cppVar_5858 & cppMask_un_5_);
	cppVar_5859 = (0 << 5) | cppVar_5858;
	cppVar_5859 = (cppVar_5859 & cppMask_un_8_);
	cppVar_5861 = (cppVar_5859 == 208);
	if (cppVar_5861) {
	cppVar_5856 = PSW;
	} else {
	cppVar_5863 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5864 = (cppVar_5863 << 3) | 0;
	cppVar_5864 = (cppVar_5864 & cppMask_un_5_);
	cppVar_5865 = (0 << 5) | cppVar_5864;
	cppVar_5865 = (cppVar_5865 & cppMask_un_8_);
	cppVar_5867 = (cppVar_5865 == 224);
	if (cppVar_5867) {
	cppVar_5862 = ACC;
	} else {
	cppVar_5869 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5870 = (cppVar_5869 << 3) | 0;
	cppVar_5870 = (cppVar_5870 & cppMask_un_5_);
	cppVar_5871 = (0 << 5) | cppVar_5870;
	cppVar_5871 = (cppVar_5871 & cppMask_un_8_);
	cppVar_5873 = (cppVar_5871 == 240);
	if (cppVar_5873) {
	cppVar_5868 = B;
	} else {
	cppVar_5868 = 0;
	}
	cppVar_5862 = cppVar_5868;
	}
	cppVar_5856 = cppVar_5862;
	}
	cppVar_5850 = cppVar_5856;
	}
	cppVar_5844 = cppVar_5850;
	}
	cppVar_5838 = cppVar_5844;
	}
	cppVar_5832 = cppVar_5838;
	}
	cppVar_5826 = cppVar_5832;
	}
	cppVar_5820 = cppVar_5826;
	}
	cppVar_5814 = cppVar_5820;
	}
	cppVar_5808 = cppVar_5814;
	}
	cppVar_5802 = cppVar_5808;
	}
	cppVar_5796 = cppVar_5802;
	}
	cppVar_5790 = cppVar_5796;
	}
	cppVar_5784 = cppVar_5790;
	}
	cppVar_5778 = cppVar_5784;
	}
	cppVar_5772 = cppVar_5778;
	}
	cppVar_5766 = cppVar_5772;
	}
	cppVar_5760 = cppVar_5766;
	}
	cppVar_5754 = cppVar_5760;
	}
	cppVar_5748 = cppVar_5754;
	}
	cppVar_5735 = cppVar_5748;
	}
	cppVar_5729 = cppVar_5735;
	} else {
	cppVar_5729 = B;
	}
	cppVar_5725 = cppVar_5729;
	} else {
	cppVar_5876 = ROM.rd(PC);
	cppVar_5878 = (cppVar_5876 == 135);
	if (cppVar_5878) {
	cppVar_5881 = PC + 1;
	cppVar_5881 = (cppVar_5881 & cppMask_un_16_);
	cppVar_5882 = ROM.rd(cppVar_5881);
	cppVar_5884 = (cppVar_5882 == 240);
	if (cppVar_5884) {
	cppVar_5886 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5888 = (cppVar_5886 << 3) | 1;
	cppVar_5888 = (cppVar_5888 & cppMask_un_5_);
	cppVar_5889 = (0 << 5) | cppVar_5888;
	cppVar_5889 = (cppVar_5889 & cppMask_un_8_);
	cppVar_5890 = IRAM.rd(cppVar_5889);
	cppVar_5891 = IRAM.rd(cppVar_5890);
	cppVar_5879 = cppVar_5891;
	} else {
	cppVar_5879 = B;
	}
	cppVar_5875 = cppVar_5879;
	} else {
	cppVar_5893 = ROM.rd(PC);
	cppVar_5895 = (cppVar_5893 == 134);
	if (cppVar_5895) {
	cppVar_5898 = PC + 1;
	cppVar_5898 = (cppVar_5898 & cppMask_un_16_);
	cppVar_5899 = ROM.rd(cppVar_5898);
	cppVar_5901 = (cppVar_5899 == 240);
	if (cppVar_5901) {
	cppVar_5903 = (PSW >> 3) & cppMask_un_2_;
	cppVar_5905 = (cppVar_5903 << 3) | 0;
	cppVar_5905 = (cppVar_5905 & cppMask_un_5_);
	cppVar_5906 = (0 << 5) | cppVar_5905;
	cppVar_5906 = (cppVar_5906 & cppMask_un_8_);
	cppVar_5907 = IRAM.rd(cppVar_5906);
	cppVar_5908 = IRAM.rd(cppVar_5907);
	cppVar_5896 = cppVar_5908;
	} else {
	cppVar_5896 = B;
	}
	cppVar_5892 = cppVar_5896;
	} else {
	cppVar_5910 = ROM.rd(PC);
	cppVar_5912 = (cppVar_5910 == 133);
	if (cppVar_5912) {
	cppVar_5915 = PC + 2;
	cppVar_5915 = (cppVar_5915 & cppMask_un_16_);
	cppVar_5916 = ROM.rd(cppVar_5915);
	cppVar_5918 = (cppVar_5916 == 240);
	if (cppVar_5918) {
	cppVar_5921 = PC + 1;
	cppVar_5921 = (cppVar_5921 & cppMask_un_16_);
	cppVar_5922 = ROM.rd(cppVar_5921);
	cppVar_5923 = (cppVar_5922 >> 7) & cppMask_un_1_;
	cppVar_5925 = (cppVar_5923 == 0);
	if (cppVar_5925) {
	cppVar_5926 = PC + 1;
	cppVar_5926 = (cppVar_5926 & cppMask_un_16_);
	cppVar_5927 = ROM.rd(cppVar_5926);
	cppVar_5928 = IRAM.rd(cppVar_5927);
	cppVar_5919 = cppVar_5928;
	} else {
	cppVar_5930 = PC + 1;
	cppVar_5930 = (cppVar_5930 & cppMask_un_16_);
	cppVar_5931 = ROM.rd(cppVar_5930);
	cppVar_5933 = (cppVar_5931 == 128);
	if (cppVar_5933) {
	cppVar_5929 = P0;
	} else {
	cppVar_5935 = PC + 1;
	cppVar_5935 = (cppVar_5935 & cppMask_un_16_);
	cppVar_5936 = ROM.rd(cppVar_5935);
	cppVar_5938 = (cppVar_5936 == 129);
	if (cppVar_5938) {
	cppVar_5934 = SP;
	} else {
	cppVar_5940 = PC + 1;
	cppVar_5940 = (cppVar_5940 & cppMask_un_16_);
	cppVar_5941 = ROM.rd(cppVar_5940);
	cppVar_5943 = (cppVar_5941 == 130);
	if (cppVar_5943) {
	cppVar_5939 = DPL;
	} else {
	cppVar_5945 = PC + 1;
	cppVar_5945 = (cppVar_5945 & cppMask_un_16_);
	cppVar_5946 = ROM.rd(cppVar_5945);
	cppVar_5948 = (cppVar_5946 == 131);
	if (cppVar_5948) {
	cppVar_5944 = DPH;
	} else {
	cppVar_5950 = PC + 1;
	cppVar_5950 = (cppVar_5950 & cppMask_un_16_);
	cppVar_5951 = ROM.rd(cppVar_5950);
	cppVar_5953 = (cppVar_5951 == 135);
	if (cppVar_5953) {
	cppVar_5949 = PCON;
	} else {
	cppVar_5955 = PC + 1;
	cppVar_5955 = (cppVar_5955 & cppMask_un_16_);
	cppVar_5956 = ROM.rd(cppVar_5955);
	cppVar_5958 = (cppVar_5956 == 136);
	if (cppVar_5958) {
	cppVar_5954 = TCON;
	} else {
	cppVar_5960 = PC + 1;
	cppVar_5960 = (cppVar_5960 & cppMask_un_16_);
	cppVar_5961 = ROM.rd(cppVar_5960);
	cppVar_5963 = (cppVar_5961 == 137);
	if (cppVar_5963) {
	cppVar_5959 = TMOD;
	} else {
	cppVar_5965 = PC + 1;
	cppVar_5965 = (cppVar_5965 & cppMask_un_16_);
	cppVar_5966 = ROM.rd(cppVar_5965);
	cppVar_5968 = (cppVar_5966 == 138);
	if (cppVar_5968) {
	cppVar_5964 = TL0;
	} else {
	cppVar_5970 = PC + 1;
	cppVar_5970 = (cppVar_5970 & cppMask_un_16_);
	cppVar_5971 = ROM.rd(cppVar_5970);
	cppVar_5973 = (cppVar_5971 == 140);
	if (cppVar_5973) {
	cppVar_5969 = TH0;
	} else {
	cppVar_5975 = PC + 1;
	cppVar_5975 = (cppVar_5975 & cppMask_un_16_);
	cppVar_5976 = ROM.rd(cppVar_5975);
	cppVar_5978 = (cppVar_5976 == 139);
	if (cppVar_5978) {
	cppVar_5974 = TL1;
	} else {
	cppVar_5980 = PC + 1;
	cppVar_5980 = (cppVar_5980 & cppMask_un_16_);
	cppVar_5981 = ROM.rd(cppVar_5980);
	cppVar_5983 = (cppVar_5981 == 141);
	if (cppVar_5983) {
	cppVar_5979 = TH1;
	} else {
	cppVar_5985 = PC + 1;
	cppVar_5985 = (cppVar_5985 & cppMask_un_16_);
	cppVar_5986 = ROM.rd(cppVar_5985);
	cppVar_5988 = (cppVar_5986 == 144);
	if (cppVar_5988) {
	cppVar_5984 = P1;
	} else {
	cppVar_5990 = PC + 1;
	cppVar_5990 = (cppVar_5990 & cppMask_un_16_);
	cppVar_5991 = ROM.rd(cppVar_5990);
	cppVar_5993 = (cppVar_5991 == 152);
	if (cppVar_5993) {
	cppVar_5989 = SCON;
	} else {
	cppVar_5995 = PC + 1;
	cppVar_5995 = (cppVar_5995 & cppMask_un_16_);
	cppVar_5996 = ROM.rd(cppVar_5995);
	cppVar_5998 = (cppVar_5996 == 153);
	if (cppVar_5998) {
	cppVar_5994 = SBUF;
	} else {
	cppVar_6000 = PC + 1;
	cppVar_6000 = (cppVar_6000 & cppMask_un_16_);
	cppVar_6001 = ROM.rd(cppVar_6000);
	cppVar_6003 = (cppVar_6001 == 160);
	if (cppVar_6003) {
	cppVar_5999 = P2;
	} else {
	cppVar_6005 = PC + 1;
	cppVar_6005 = (cppVar_6005 & cppMask_un_16_);
	cppVar_6006 = ROM.rd(cppVar_6005);
	cppVar_6008 = (cppVar_6006 == 168);
	if (cppVar_6008) {
	cppVar_6004 = IE;
	} else {
	cppVar_6010 = PC + 1;
	cppVar_6010 = (cppVar_6010 & cppMask_un_16_);
	cppVar_6011 = ROM.rd(cppVar_6010);
	cppVar_6013 = (cppVar_6011 == 176);
	if (cppVar_6013) {
	cppVar_6009 = P3;
	} else {
	cppVar_6015 = PC + 1;
	cppVar_6015 = (cppVar_6015 & cppMask_un_16_);
	cppVar_6016 = ROM.rd(cppVar_6015);
	cppVar_6018 = (cppVar_6016 == 184);
	if (cppVar_6018) {
	cppVar_6014 = IP;
	} else {
	cppVar_6020 = PC + 1;
	cppVar_6020 = (cppVar_6020 & cppMask_un_16_);
	cppVar_6021 = ROM.rd(cppVar_6020);
	cppVar_6023 = (cppVar_6021 == 208);
	if (cppVar_6023) {
	cppVar_6019 = PSW;
	} else {
	cppVar_6025 = PC + 1;
	cppVar_6025 = (cppVar_6025 & cppMask_un_16_);
	cppVar_6026 = ROM.rd(cppVar_6025);
	cppVar_6028 = (cppVar_6026 == 224);
	if (cppVar_6028) {
	cppVar_6024 = ACC;
	} else {
	cppVar_6030 = PC + 1;
	cppVar_6030 = (cppVar_6030 & cppMask_un_16_);
	cppVar_6031 = ROM.rd(cppVar_6030);
	cppVar_6033 = (cppVar_6031 == 240);
	if (cppVar_6033) {
	cppVar_6029 = B;
	} else {
	cppVar_6029 = 0;
	}
	cppVar_6024 = cppVar_6029;
	}
	cppVar_6019 = cppVar_6024;
	}
	cppVar_6014 = cppVar_6019;
	}
	cppVar_6009 = cppVar_6014;
	}
	cppVar_6004 = cppVar_6009;
	}
	cppVar_5999 = cppVar_6004;
	}
	cppVar_5994 = cppVar_5999;
	}
	cppVar_5989 = cppVar_5994;
	}
	cppVar_5984 = cppVar_5989;
	}
	cppVar_5979 = cppVar_5984;
	}
	cppVar_5974 = cppVar_5979;
	}
	cppVar_5969 = cppVar_5974;
	}
	cppVar_5964 = cppVar_5969;
	}
	cppVar_5959 = cppVar_5964;
	}
	cppVar_5954 = cppVar_5959;
	}
	cppVar_5949 = cppVar_5954;
	}
	cppVar_5944 = cppVar_5949;
	}
	cppVar_5939 = cppVar_5944;
	}
	cppVar_5934 = cppVar_5939;
	}
	cppVar_5929 = cppVar_5934;
	}
	cppVar_5919 = cppVar_5929;
	}
	cppVar_5913 = cppVar_5919;
	} else {
	cppVar_5913 = B;
	}
	cppVar_5909 = cppVar_5913;
	} else {
	cppVar_6036 = ROM.rd(PC);
	cppVar_6038 = (cppVar_6036 == 132);
	if (cppVar_6038) {
	cppVar_6041 = (B == 0);
	if (cppVar_6041) {
	cppVar_6039 = ACC;
	} else {
	cppVar_6042 = ACC % B;
	cppVar_6042 = (cppVar_6042 & cppMask_un_8_);
	cppVar_6039 = cppVar_6042;
	}
	cppVar_6035 = cppVar_6039;
	} else {
	cppVar_6044 = ROM.rd(PC);
	cppVar_6046 = (cppVar_6044 == 117);
	if (cppVar_6046) {
	cppVar_6049 = PC + 1;
	cppVar_6049 = (cppVar_6049 & cppMask_un_16_);
	cppVar_6050 = ROM.rd(cppVar_6049);
	cppVar_6052 = (cppVar_6050 == 240);
	if (cppVar_6052) {
	cppVar_6054 = PC + 2;
	cppVar_6054 = (cppVar_6054 & cppMask_un_16_);
	cppVar_6055 = ROM.rd(cppVar_6054);
	cppVar_6047 = cppVar_6055;
	} else {
	cppVar_6047 = B;
	}
	cppVar_6043 = cppVar_6047;
	} else {
	cppVar_6057 = ROM.rd(PC);
	cppVar_6059 = (cppVar_6057 == 99);
	if (cppVar_6059) {
	cppVar_6062 = PC + 1;
	cppVar_6062 = (cppVar_6062 & cppMask_un_16_);
	cppVar_6063 = ROM.rd(cppVar_6062);
	cppVar_6065 = (cppVar_6063 == 240);
	if (cppVar_6065) {
	cppVar_6067 = PC + 1;
	cppVar_6067 = (cppVar_6067 & cppMask_un_16_);
	cppVar_6068 = ROM.rd(cppVar_6067);
	cppVar_6069 = (cppVar_6068 >> 7) & cppMask_un_1_;
	cppVar_6071 = (cppVar_6069 == 0);
	if (cppVar_6071) {
	cppVar_6072 = PC + 1;
	cppVar_6072 = (cppVar_6072 & cppMask_un_16_);
	cppVar_6073 = ROM.rd(cppVar_6072);
	cppVar_6074 = IRAM.rd(cppVar_6073);
	cppVar_6066 = cppVar_6074;
	} else {
	cppVar_6076 = PC + 1;
	cppVar_6076 = (cppVar_6076 & cppMask_un_16_);
	cppVar_6077 = ROM.rd(cppVar_6076);
	cppVar_6079 = (cppVar_6077 == 128);
	if (cppVar_6079) {
	cppVar_6075 = P0;
	} else {
	cppVar_6081 = PC + 1;
	cppVar_6081 = (cppVar_6081 & cppMask_un_16_);
	cppVar_6082 = ROM.rd(cppVar_6081);
	cppVar_6084 = (cppVar_6082 == 129);
	if (cppVar_6084) {
	cppVar_6080 = SP;
	} else {
	cppVar_6086 = PC + 1;
	cppVar_6086 = (cppVar_6086 & cppMask_un_16_);
	cppVar_6087 = ROM.rd(cppVar_6086);
	cppVar_6089 = (cppVar_6087 == 130);
	if (cppVar_6089) {
	cppVar_6085 = DPL;
	} else {
	cppVar_6091 = PC + 1;
	cppVar_6091 = (cppVar_6091 & cppMask_un_16_);
	cppVar_6092 = ROM.rd(cppVar_6091);
	cppVar_6094 = (cppVar_6092 == 131);
	if (cppVar_6094) {
	cppVar_6090 = DPH;
	} else {
	cppVar_6096 = PC + 1;
	cppVar_6096 = (cppVar_6096 & cppMask_un_16_);
	cppVar_6097 = ROM.rd(cppVar_6096);
	cppVar_6099 = (cppVar_6097 == 135);
	if (cppVar_6099) {
	cppVar_6095 = PCON;
	} else {
	cppVar_6101 = PC + 1;
	cppVar_6101 = (cppVar_6101 & cppMask_un_16_);
	cppVar_6102 = ROM.rd(cppVar_6101);
	cppVar_6104 = (cppVar_6102 == 136);
	if (cppVar_6104) {
	cppVar_6100 = TCON;
	} else {
	cppVar_6106 = PC + 1;
	cppVar_6106 = (cppVar_6106 & cppMask_un_16_);
	cppVar_6107 = ROM.rd(cppVar_6106);
	cppVar_6109 = (cppVar_6107 == 137);
	if (cppVar_6109) {
	cppVar_6105 = TMOD;
	} else {
	cppVar_6111 = PC + 1;
	cppVar_6111 = (cppVar_6111 & cppMask_un_16_);
	cppVar_6112 = ROM.rd(cppVar_6111);
	cppVar_6114 = (cppVar_6112 == 138);
	if (cppVar_6114) {
	cppVar_6110 = TL0;
	} else {
	cppVar_6116 = PC + 1;
	cppVar_6116 = (cppVar_6116 & cppMask_un_16_);
	cppVar_6117 = ROM.rd(cppVar_6116);
	cppVar_6119 = (cppVar_6117 == 140);
	if (cppVar_6119) {
	cppVar_6115 = TH0;
	} else {
	cppVar_6121 = PC + 1;
	cppVar_6121 = (cppVar_6121 & cppMask_un_16_);
	cppVar_6122 = ROM.rd(cppVar_6121);
	cppVar_6124 = (cppVar_6122 == 139);
	if (cppVar_6124) {
	cppVar_6120 = TL1;
	} else {
	cppVar_6126 = PC + 1;
	cppVar_6126 = (cppVar_6126 & cppMask_un_16_);
	cppVar_6127 = ROM.rd(cppVar_6126);
	cppVar_6129 = (cppVar_6127 == 141);
	if (cppVar_6129) {
	cppVar_6125 = TH1;
	} else {
	cppVar_6131 = PC + 1;
	cppVar_6131 = (cppVar_6131 & cppMask_un_16_);
	cppVar_6132 = ROM.rd(cppVar_6131);
	cppVar_6134 = (cppVar_6132 == 144);
	if (cppVar_6134) {
	cppVar_6130 = P1;
	} else {
	cppVar_6136 = PC + 1;
	cppVar_6136 = (cppVar_6136 & cppMask_un_16_);
	cppVar_6137 = ROM.rd(cppVar_6136);
	cppVar_6139 = (cppVar_6137 == 152);
	if (cppVar_6139) {
	cppVar_6135 = SCON;
	} else {
	cppVar_6141 = PC + 1;
	cppVar_6141 = (cppVar_6141 & cppMask_un_16_);
	cppVar_6142 = ROM.rd(cppVar_6141);
	cppVar_6144 = (cppVar_6142 == 153);
	if (cppVar_6144) {
	cppVar_6140 = SBUF;
	} else {
	cppVar_6146 = PC + 1;
	cppVar_6146 = (cppVar_6146 & cppMask_un_16_);
	cppVar_6147 = ROM.rd(cppVar_6146);
	cppVar_6149 = (cppVar_6147 == 160);
	if (cppVar_6149) {
	cppVar_6145 = P2;
	} else {
	cppVar_6151 = PC + 1;
	cppVar_6151 = (cppVar_6151 & cppMask_un_16_);
	cppVar_6152 = ROM.rd(cppVar_6151);
	cppVar_6154 = (cppVar_6152 == 168);
	if (cppVar_6154) {
	cppVar_6150 = IE;
	} else {
	cppVar_6156 = PC + 1;
	cppVar_6156 = (cppVar_6156 & cppMask_un_16_);
	cppVar_6157 = ROM.rd(cppVar_6156);
	cppVar_6159 = (cppVar_6157 == 176);
	if (cppVar_6159) {
	cppVar_6155 = P3;
	} else {
	cppVar_6161 = PC + 1;
	cppVar_6161 = (cppVar_6161 & cppMask_un_16_);
	cppVar_6162 = ROM.rd(cppVar_6161);
	cppVar_6164 = (cppVar_6162 == 184);
	if (cppVar_6164) {
	cppVar_6160 = IP;
	} else {
	cppVar_6166 = PC + 1;
	cppVar_6166 = (cppVar_6166 & cppMask_un_16_);
	cppVar_6167 = ROM.rd(cppVar_6166);
	cppVar_6169 = (cppVar_6167 == 208);
	if (cppVar_6169) {
	cppVar_6165 = PSW;
	} else {
	cppVar_6171 = PC + 1;
	cppVar_6171 = (cppVar_6171 & cppMask_un_16_);
	cppVar_6172 = ROM.rd(cppVar_6171);
	cppVar_6174 = (cppVar_6172 == 224);
	if (cppVar_6174) {
	cppVar_6170 = ACC;
	} else {
	cppVar_6176 = PC + 1;
	cppVar_6176 = (cppVar_6176 & cppMask_un_16_);
	cppVar_6177 = ROM.rd(cppVar_6176);
	cppVar_6179 = (cppVar_6177 == 240);
	if (cppVar_6179) {
	cppVar_6175 = B;
	} else {
	cppVar_6175 = 0;
	}
	cppVar_6170 = cppVar_6175;
	}
	cppVar_6165 = cppVar_6170;
	}
	cppVar_6160 = cppVar_6165;
	}
	cppVar_6155 = cppVar_6160;
	}
	cppVar_6150 = cppVar_6155;
	}
	cppVar_6145 = cppVar_6150;
	}
	cppVar_6140 = cppVar_6145;
	}
	cppVar_6135 = cppVar_6140;
	}
	cppVar_6130 = cppVar_6135;
	}
	cppVar_6125 = cppVar_6130;
	}
	cppVar_6120 = cppVar_6125;
	}
	cppVar_6115 = cppVar_6120;
	}
	cppVar_6110 = cppVar_6115;
	}
	cppVar_6105 = cppVar_6110;
	}
	cppVar_6100 = cppVar_6105;
	}
	cppVar_6095 = cppVar_6100;
	}
	cppVar_6090 = cppVar_6095;
	}
	cppVar_6085 = cppVar_6090;
	}
	cppVar_6080 = cppVar_6085;
	}
	cppVar_6075 = cppVar_6080;
	}
	cppVar_6066 = cppVar_6075;
	}
	cppVar_6182 = PC + 2;
	cppVar_6182 = (cppVar_6182 & cppMask_un_16_);
	cppVar_6183 = ROM.rd(cppVar_6182);
	cppVar_6184 = cppVar_6066 ^ cppVar_6183;
	cppVar_6060 = cppVar_6184;
	} else {
	cppVar_6060 = B;
	}
	cppVar_6056 = cppVar_6060;
	} else {
	cppVar_6186 = ROM.rd(PC);
	cppVar_6188 = (cppVar_6186 == 98);
	if (cppVar_6188) {
	cppVar_6191 = PC + 1;
	cppVar_6191 = (cppVar_6191 & cppMask_un_16_);
	cppVar_6192 = ROM.rd(cppVar_6191);
	cppVar_6194 = (cppVar_6192 == 240);
	if (cppVar_6194) {
	cppVar_6196 = PC + 1;
	cppVar_6196 = (cppVar_6196 & cppMask_un_16_);
	cppVar_6197 = ROM.rd(cppVar_6196);
	cppVar_6198 = (cppVar_6197 >> 7) & cppMask_un_1_;
	cppVar_6200 = (cppVar_6198 == 0);
	if (cppVar_6200) {
	cppVar_6201 = PC + 1;
	cppVar_6201 = (cppVar_6201 & cppMask_un_16_);
	cppVar_6202 = ROM.rd(cppVar_6201);
	cppVar_6203 = IRAM.rd(cppVar_6202);
	cppVar_6195 = cppVar_6203;
	} else {
	cppVar_6205 = PC + 1;
	cppVar_6205 = (cppVar_6205 & cppMask_un_16_);
	cppVar_6206 = ROM.rd(cppVar_6205);
	cppVar_6208 = (cppVar_6206 == 128);
	if (cppVar_6208) {
	cppVar_6204 = P0;
	} else {
	cppVar_6210 = PC + 1;
	cppVar_6210 = (cppVar_6210 & cppMask_un_16_);
	cppVar_6211 = ROM.rd(cppVar_6210);
	cppVar_6213 = (cppVar_6211 == 129);
	if (cppVar_6213) {
	cppVar_6209 = SP;
	} else {
	cppVar_6215 = PC + 1;
	cppVar_6215 = (cppVar_6215 & cppMask_un_16_);
	cppVar_6216 = ROM.rd(cppVar_6215);
	cppVar_6218 = (cppVar_6216 == 130);
	if (cppVar_6218) {
	cppVar_6214 = DPL;
	} else {
	cppVar_6220 = PC + 1;
	cppVar_6220 = (cppVar_6220 & cppMask_un_16_);
	cppVar_6221 = ROM.rd(cppVar_6220);
	cppVar_6223 = (cppVar_6221 == 131);
	if (cppVar_6223) {
	cppVar_6219 = DPH;
	} else {
	cppVar_6225 = PC + 1;
	cppVar_6225 = (cppVar_6225 & cppMask_un_16_);
	cppVar_6226 = ROM.rd(cppVar_6225);
	cppVar_6228 = (cppVar_6226 == 135);
	if (cppVar_6228) {
	cppVar_6224 = PCON;
	} else {
	cppVar_6230 = PC + 1;
	cppVar_6230 = (cppVar_6230 & cppMask_un_16_);
	cppVar_6231 = ROM.rd(cppVar_6230);
	cppVar_6233 = (cppVar_6231 == 136);
	if (cppVar_6233) {
	cppVar_6229 = TCON;
	} else {
	cppVar_6235 = PC + 1;
	cppVar_6235 = (cppVar_6235 & cppMask_un_16_);
	cppVar_6236 = ROM.rd(cppVar_6235);
	cppVar_6238 = (cppVar_6236 == 137);
	if (cppVar_6238) {
	cppVar_6234 = TMOD;
	} else {
	cppVar_6240 = PC + 1;
	cppVar_6240 = (cppVar_6240 & cppMask_un_16_);
	cppVar_6241 = ROM.rd(cppVar_6240);
	cppVar_6243 = (cppVar_6241 == 138);
	if (cppVar_6243) {
	cppVar_6239 = TL0;
	} else {
	cppVar_6245 = PC + 1;
	cppVar_6245 = (cppVar_6245 & cppMask_un_16_);
	cppVar_6246 = ROM.rd(cppVar_6245);
	cppVar_6248 = (cppVar_6246 == 140);
	if (cppVar_6248) {
	cppVar_6244 = TH0;
	} else {
	cppVar_6250 = PC + 1;
	cppVar_6250 = (cppVar_6250 & cppMask_un_16_);
	cppVar_6251 = ROM.rd(cppVar_6250);
	cppVar_6253 = (cppVar_6251 == 139);
	if (cppVar_6253) {
	cppVar_6249 = TL1;
	} else {
	cppVar_6255 = PC + 1;
	cppVar_6255 = (cppVar_6255 & cppMask_un_16_);
	cppVar_6256 = ROM.rd(cppVar_6255);
	cppVar_6258 = (cppVar_6256 == 141);
	if (cppVar_6258) {
	cppVar_6254 = TH1;
	} else {
	cppVar_6260 = PC + 1;
	cppVar_6260 = (cppVar_6260 & cppMask_un_16_);
	cppVar_6261 = ROM.rd(cppVar_6260);
	cppVar_6263 = (cppVar_6261 == 144);
	if (cppVar_6263) {
	cppVar_6259 = P1;
	} else {
	cppVar_6265 = PC + 1;
	cppVar_6265 = (cppVar_6265 & cppMask_un_16_);
	cppVar_6266 = ROM.rd(cppVar_6265);
	cppVar_6268 = (cppVar_6266 == 152);
	if (cppVar_6268) {
	cppVar_6264 = SCON;
	} else {
	cppVar_6270 = PC + 1;
	cppVar_6270 = (cppVar_6270 & cppMask_un_16_);
	cppVar_6271 = ROM.rd(cppVar_6270);
	cppVar_6273 = (cppVar_6271 == 153);
	if (cppVar_6273) {
	cppVar_6269 = SBUF;
	} else {
	cppVar_6275 = PC + 1;
	cppVar_6275 = (cppVar_6275 & cppMask_un_16_);
	cppVar_6276 = ROM.rd(cppVar_6275);
	cppVar_6278 = (cppVar_6276 == 160);
	if (cppVar_6278) {
	cppVar_6274 = P2;
	} else {
	cppVar_6280 = PC + 1;
	cppVar_6280 = (cppVar_6280 & cppMask_un_16_);
	cppVar_6281 = ROM.rd(cppVar_6280);
	cppVar_6283 = (cppVar_6281 == 168);
	if (cppVar_6283) {
	cppVar_6279 = IE;
	} else {
	cppVar_6285 = PC + 1;
	cppVar_6285 = (cppVar_6285 & cppMask_un_16_);
	cppVar_6286 = ROM.rd(cppVar_6285);
	cppVar_6288 = (cppVar_6286 == 176);
	if (cppVar_6288) {
	cppVar_6284 = P3;
	} else {
	cppVar_6290 = PC + 1;
	cppVar_6290 = (cppVar_6290 & cppMask_un_16_);
	cppVar_6291 = ROM.rd(cppVar_6290);
	cppVar_6293 = (cppVar_6291 == 184);
	if (cppVar_6293) {
	cppVar_6289 = IP;
	} else {
	cppVar_6295 = PC + 1;
	cppVar_6295 = (cppVar_6295 & cppMask_un_16_);
	cppVar_6296 = ROM.rd(cppVar_6295);
	cppVar_6298 = (cppVar_6296 == 208);
	if (cppVar_6298) {
	cppVar_6294 = PSW;
	} else {
	cppVar_6300 = PC + 1;
	cppVar_6300 = (cppVar_6300 & cppMask_un_16_);
	cppVar_6301 = ROM.rd(cppVar_6300);
	cppVar_6303 = (cppVar_6301 == 224);
	if (cppVar_6303) {
	cppVar_6299 = ACC;
	} else {
	cppVar_6305 = PC + 1;
	cppVar_6305 = (cppVar_6305 & cppMask_un_16_);
	cppVar_6306 = ROM.rd(cppVar_6305);
	cppVar_6308 = (cppVar_6306 == 240);
	if (cppVar_6308) {
	cppVar_6304 = B;
	} else {
	cppVar_6304 = 0;
	}
	cppVar_6299 = cppVar_6304;
	}
	cppVar_6294 = cppVar_6299;
	}
	cppVar_6289 = cppVar_6294;
	}
	cppVar_6284 = cppVar_6289;
	}
	cppVar_6279 = cppVar_6284;
	}
	cppVar_6274 = cppVar_6279;
	}
	cppVar_6269 = cppVar_6274;
	}
	cppVar_6264 = cppVar_6269;
	}
	cppVar_6259 = cppVar_6264;
	}
	cppVar_6254 = cppVar_6259;
	}
	cppVar_6249 = cppVar_6254;
	}
	cppVar_6244 = cppVar_6249;
	}
	cppVar_6239 = cppVar_6244;
	}
	cppVar_6234 = cppVar_6239;
	}
	cppVar_6229 = cppVar_6234;
	}
	cppVar_6224 = cppVar_6229;
	}
	cppVar_6219 = cppVar_6224;
	}
	cppVar_6214 = cppVar_6219;
	}
	cppVar_6209 = cppVar_6214;
	}
	cppVar_6204 = cppVar_6209;
	}
	cppVar_6195 = cppVar_6204;
	}
	cppVar_6310 = cppVar_6195 ^ ACC;
	cppVar_6189 = cppVar_6310;
	} else {
	cppVar_6189 = B;
	}
	cppVar_6185 = cppVar_6189;
	} else {
	cppVar_6312 = ROM.rd(PC);
	cppVar_6314 = (cppVar_6312 == 83);
	if (cppVar_6314) {
	cppVar_6317 = PC + 1;
	cppVar_6317 = (cppVar_6317 & cppMask_un_16_);
	cppVar_6318 = ROM.rd(cppVar_6317);
	cppVar_6320 = (cppVar_6318 == 240);
	if (cppVar_6320) {
	cppVar_6322 = PC + 1;
	cppVar_6322 = (cppVar_6322 & cppMask_un_16_);
	cppVar_6323 = ROM.rd(cppVar_6322);
	cppVar_6324 = (cppVar_6323 >> 7) & cppMask_un_1_;
	cppVar_6326 = (cppVar_6324 == 0);
	if (cppVar_6326) {
	cppVar_6327 = PC + 1;
	cppVar_6327 = (cppVar_6327 & cppMask_un_16_);
	cppVar_6328 = ROM.rd(cppVar_6327);
	cppVar_6329 = IRAM.rd(cppVar_6328);
	cppVar_6321 = cppVar_6329;
	} else {
	cppVar_6331 = PC + 1;
	cppVar_6331 = (cppVar_6331 & cppMask_un_16_);
	cppVar_6332 = ROM.rd(cppVar_6331);
	cppVar_6334 = (cppVar_6332 == 128);
	if (cppVar_6334) {
	cppVar_6330 = P0;
	} else {
	cppVar_6336 = PC + 1;
	cppVar_6336 = (cppVar_6336 & cppMask_un_16_);
	cppVar_6337 = ROM.rd(cppVar_6336);
	cppVar_6339 = (cppVar_6337 == 129);
	if (cppVar_6339) {
	cppVar_6335 = SP;
	} else {
	cppVar_6341 = PC + 1;
	cppVar_6341 = (cppVar_6341 & cppMask_un_16_);
	cppVar_6342 = ROM.rd(cppVar_6341);
	cppVar_6344 = (cppVar_6342 == 130);
	if (cppVar_6344) {
	cppVar_6340 = DPL;
	} else {
	cppVar_6346 = PC + 1;
	cppVar_6346 = (cppVar_6346 & cppMask_un_16_);
	cppVar_6347 = ROM.rd(cppVar_6346);
	cppVar_6349 = (cppVar_6347 == 131);
	if (cppVar_6349) {
	cppVar_6345 = DPH;
	} else {
	cppVar_6351 = PC + 1;
	cppVar_6351 = (cppVar_6351 & cppMask_un_16_);
	cppVar_6352 = ROM.rd(cppVar_6351);
	cppVar_6354 = (cppVar_6352 == 135);
	if (cppVar_6354) {
	cppVar_6350 = PCON;
	} else {
	cppVar_6356 = PC + 1;
	cppVar_6356 = (cppVar_6356 & cppMask_un_16_);
	cppVar_6357 = ROM.rd(cppVar_6356);
	cppVar_6359 = (cppVar_6357 == 136);
	if (cppVar_6359) {
	cppVar_6355 = TCON;
	} else {
	cppVar_6361 = PC + 1;
	cppVar_6361 = (cppVar_6361 & cppMask_un_16_);
	cppVar_6362 = ROM.rd(cppVar_6361);
	cppVar_6364 = (cppVar_6362 == 137);
	if (cppVar_6364) {
	cppVar_6360 = TMOD;
	} else {
	cppVar_6366 = PC + 1;
	cppVar_6366 = (cppVar_6366 & cppMask_un_16_);
	cppVar_6367 = ROM.rd(cppVar_6366);
	cppVar_6369 = (cppVar_6367 == 138);
	if (cppVar_6369) {
	cppVar_6365 = TL0;
	} else {
	cppVar_6371 = PC + 1;
	cppVar_6371 = (cppVar_6371 & cppMask_un_16_);
	cppVar_6372 = ROM.rd(cppVar_6371);
	cppVar_6374 = (cppVar_6372 == 140);
	if (cppVar_6374) {
	cppVar_6370 = TH0;
	} else {
	cppVar_6376 = PC + 1;
	cppVar_6376 = (cppVar_6376 & cppMask_un_16_);
	cppVar_6377 = ROM.rd(cppVar_6376);
	cppVar_6379 = (cppVar_6377 == 139);
	if (cppVar_6379) {
	cppVar_6375 = TL1;
	} else {
	cppVar_6381 = PC + 1;
	cppVar_6381 = (cppVar_6381 & cppMask_un_16_);
	cppVar_6382 = ROM.rd(cppVar_6381);
	cppVar_6384 = (cppVar_6382 == 141);
	if (cppVar_6384) {
	cppVar_6380 = TH1;
	} else {
	cppVar_6386 = PC + 1;
	cppVar_6386 = (cppVar_6386 & cppMask_un_16_);
	cppVar_6387 = ROM.rd(cppVar_6386);
	cppVar_6389 = (cppVar_6387 == 144);
	if (cppVar_6389) {
	cppVar_6385 = P1;
	} else {
	cppVar_6391 = PC + 1;
	cppVar_6391 = (cppVar_6391 & cppMask_un_16_);
	cppVar_6392 = ROM.rd(cppVar_6391);
	cppVar_6394 = (cppVar_6392 == 152);
	if (cppVar_6394) {
	cppVar_6390 = SCON;
	} else {
	cppVar_6396 = PC + 1;
	cppVar_6396 = (cppVar_6396 & cppMask_un_16_);
	cppVar_6397 = ROM.rd(cppVar_6396);
	cppVar_6399 = (cppVar_6397 == 153);
	if (cppVar_6399) {
	cppVar_6395 = SBUF;
	} else {
	cppVar_6401 = PC + 1;
	cppVar_6401 = (cppVar_6401 & cppMask_un_16_);
	cppVar_6402 = ROM.rd(cppVar_6401);
	cppVar_6404 = (cppVar_6402 == 160);
	if (cppVar_6404) {
	cppVar_6400 = P2;
	} else {
	cppVar_6406 = PC + 1;
	cppVar_6406 = (cppVar_6406 & cppMask_un_16_);
	cppVar_6407 = ROM.rd(cppVar_6406);
	cppVar_6409 = (cppVar_6407 == 168);
	if (cppVar_6409) {
	cppVar_6405 = IE;
	} else {
	cppVar_6411 = PC + 1;
	cppVar_6411 = (cppVar_6411 & cppMask_un_16_);
	cppVar_6412 = ROM.rd(cppVar_6411);
	cppVar_6414 = (cppVar_6412 == 176);
	if (cppVar_6414) {
	cppVar_6410 = P3;
	} else {
	cppVar_6416 = PC + 1;
	cppVar_6416 = (cppVar_6416 & cppMask_un_16_);
	cppVar_6417 = ROM.rd(cppVar_6416);
	cppVar_6419 = (cppVar_6417 == 184);
	if (cppVar_6419) {
	cppVar_6415 = IP;
	} else {
	cppVar_6421 = PC + 1;
	cppVar_6421 = (cppVar_6421 & cppMask_un_16_);
	cppVar_6422 = ROM.rd(cppVar_6421);
	cppVar_6424 = (cppVar_6422 == 208);
	if (cppVar_6424) {
	cppVar_6420 = PSW;
	} else {
	cppVar_6426 = PC + 1;
	cppVar_6426 = (cppVar_6426 & cppMask_un_16_);
	cppVar_6427 = ROM.rd(cppVar_6426);
	cppVar_6429 = (cppVar_6427 == 224);
	if (cppVar_6429) {
	cppVar_6425 = ACC;
	} else {
	cppVar_6431 = PC + 1;
	cppVar_6431 = (cppVar_6431 & cppMask_un_16_);
	cppVar_6432 = ROM.rd(cppVar_6431);
	cppVar_6434 = (cppVar_6432 == 240);
	if (cppVar_6434) {
	cppVar_6430 = B;
	} else {
	cppVar_6430 = 0;
	}
	cppVar_6425 = cppVar_6430;
	}
	cppVar_6420 = cppVar_6425;
	}
	cppVar_6415 = cppVar_6420;
	}
	cppVar_6410 = cppVar_6415;
	}
	cppVar_6405 = cppVar_6410;
	}
	cppVar_6400 = cppVar_6405;
	}
	cppVar_6395 = cppVar_6400;
	}
	cppVar_6390 = cppVar_6395;
	}
	cppVar_6385 = cppVar_6390;
	}
	cppVar_6380 = cppVar_6385;
	}
	cppVar_6375 = cppVar_6380;
	}
	cppVar_6370 = cppVar_6375;
	}
	cppVar_6365 = cppVar_6370;
	}
	cppVar_6360 = cppVar_6365;
	}
	cppVar_6355 = cppVar_6360;
	}
	cppVar_6350 = cppVar_6355;
	}
	cppVar_6345 = cppVar_6350;
	}
	cppVar_6340 = cppVar_6345;
	}
	cppVar_6335 = cppVar_6340;
	}
	cppVar_6330 = cppVar_6335;
	}
	cppVar_6321 = cppVar_6330;
	}
	cppVar_6437 = PC + 2;
	cppVar_6437 = (cppVar_6437 & cppMask_un_16_);
	cppVar_6438 = ROM.rd(cppVar_6437);
	cppVar_6439 = cppVar_6321 & cppVar_6438;
	cppVar_6315 = cppVar_6439;
	} else {
	cppVar_6315 = B;
	}
	cppVar_6311 = cppVar_6315;
	} else {
	cppVar_6441 = ROM.rd(PC);
	cppVar_6443 = (cppVar_6441 == 82);
	if (cppVar_6443) {
	cppVar_6446 = PC + 1;
	cppVar_6446 = (cppVar_6446 & cppMask_un_16_);
	cppVar_6447 = ROM.rd(cppVar_6446);
	cppVar_6449 = (cppVar_6447 == 240);
	if (cppVar_6449) {
	cppVar_6451 = PC + 1;
	cppVar_6451 = (cppVar_6451 & cppMask_un_16_);
	cppVar_6452 = ROM.rd(cppVar_6451);
	cppVar_6453 = (cppVar_6452 >> 7) & cppMask_un_1_;
	cppVar_6455 = (cppVar_6453 == 0);
	if (cppVar_6455) {
	cppVar_6456 = PC + 1;
	cppVar_6456 = (cppVar_6456 & cppMask_un_16_);
	cppVar_6457 = ROM.rd(cppVar_6456);
	cppVar_6458 = IRAM.rd(cppVar_6457);
	cppVar_6450 = cppVar_6458;
	} else {
	cppVar_6460 = PC + 1;
	cppVar_6460 = (cppVar_6460 & cppMask_un_16_);
	cppVar_6461 = ROM.rd(cppVar_6460);
	cppVar_6463 = (cppVar_6461 == 128);
	if (cppVar_6463) {
	cppVar_6459 = P0;
	} else {
	cppVar_6465 = PC + 1;
	cppVar_6465 = (cppVar_6465 & cppMask_un_16_);
	cppVar_6466 = ROM.rd(cppVar_6465);
	cppVar_6468 = (cppVar_6466 == 129);
	if (cppVar_6468) {
	cppVar_6464 = SP;
	} else {
	cppVar_6470 = PC + 1;
	cppVar_6470 = (cppVar_6470 & cppMask_un_16_);
	cppVar_6471 = ROM.rd(cppVar_6470);
	cppVar_6473 = (cppVar_6471 == 130);
	if (cppVar_6473) {
	cppVar_6469 = DPL;
	} else {
	cppVar_6475 = PC + 1;
	cppVar_6475 = (cppVar_6475 & cppMask_un_16_);
	cppVar_6476 = ROM.rd(cppVar_6475);
	cppVar_6478 = (cppVar_6476 == 131);
	if (cppVar_6478) {
	cppVar_6474 = DPH;
	} else {
	cppVar_6480 = PC + 1;
	cppVar_6480 = (cppVar_6480 & cppMask_un_16_);
	cppVar_6481 = ROM.rd(cppVar_6480);
	cppVar_6483 = (cppVar_6481 == 135);
	if (cppVar_6483) {
	cppVar_6479 = PCON;
	} else {
	cppVar_6485 = PC + 1;
	cppVar_6485 = (cppVar_6485 & cppMask_un_16_);
	cppVar_6486 = ROM.rd(cppVar_6485);
	cppVar_6488 = (cppVar_6486 == 136);
	if (cppVar_6488) {
	cppVar_6484 = TCON;
	} else {
	cppVar_6490 = PC + 1;
	cppVar_6490 = (cppVar_6490 & cppMask_un_16_);
	cppVar_6491 = ROM.rd(cppVar_6490);
	cppVar_6493 = (cppVar_6491 == 137);
	if (cppVar_6493) {
	cppVar_6489 = TMOD;
	} else {
	cppVar_6495 = PC + 1;
	cppVar_6495 = (cppVar_6495 & cppMask_un_16_);
	cppVar_6496 = ROM.rd(cppVar_6495);
	cppVar_6498 = (cppVar_6496 == 138);
	if (cppVar_6498) {
	cppVar_6494 = TL0;
	} else {
	cppVar_6500 = PC + 1;
	cppVar_6500 = (cppVar_6500 & cppMask_un_16_);
	cppVar_6501 = ROM.rd(cppVar_6500);
	cppVar_6503 = (cppVar_6501 == 140);
	if (cppVar_6503) {
	cppVar_6499 = TH0;
	} else {
	cppVar_6505 = PC + 1;
	cppVar_6505 = (cppVar_6505 & cppMask_un_16_);
	cppVar_6506 = ROM.rd(cppVar_6505);
	cppVar_6508 = (cppVar_6506 == 139);
	if (cppVar_6508) {
	cppVar_6504 = TL1;
	} else {
	cppVar_6510 = PC + 1;
	cppVar_6510 = (cppVar_6510 & cppMask_un_16_);
	cppVar_6511 = ROM.rd(cppVar_6510);
	cppVar_6513 = (cppVar_6511 == 141);
	if (cppVar_6513) {
	cppVar_6509 = TH1;
	} else {
	cppVar_6515 = PC + 1;
	cppVar_6515 = (cppVar_6515 & cppMask_un_16_);
	cppVar_6516 = ROM.rd(cppVar_6515);
	cppVar_6518 = (cppVar_6516 == 144);
	if (cppVar_6518) {
	cppVar_6514 = P1;
	} else {
	cppVar_6520 = PC + 1;
	cppVar_6520 = (cppVar_6520 & cppMask_un_16_);
	cppVar_6521 = ROM.rd(cppVar_6520);
	cppVar_6523 = (cppVar_6521 == 152);
	if (cppVar_6523) {
	cppVar_6519 = SCON;
	} else {
	cppVar_6525 = PC + 1;
	cppVar_6525 = (cppVar_6525 & cppMask_un_16_);
	cppVar_6526 = ROM.rd(cppVar_6525);
	cppVar_6528 = (cppVar_6526 == 153);
	if (cppVar_6528) {
	cppVar_6524 = SBUF;
	} else {
	cppVar_6530 = PC + 1;
	cppVar_6530 = (cppVar_6530 & cppMask_un_16_);
	cppVar_6531 = ROM.rd(cppVar_6530);
	cppVar_6533 = (cppVar_6531 == 160);
	if (cppVar_6533) {
	cppVar_6529 = P2;
	} else {
	cppVar_6535 = PC + 1;
	cppVar_6535 = (cppVar_6535 & cppMask_un_16_);
	cppVar_6536 = ROM.rd(cppVar_6535);
	cppVar_6538 = (cppVar_6536 == 168);
	if (cppVar_6538) {
	cppVar_6534 = IE;
	} else {
	cppVar_6540 = PC + 1;
	cppVar_6540 = (cppVar_6540 & cppMask_un_16_);
	cppVar_6541 = ROM.rd(cppVar_6540);
	cppVar_6543 = (cppVar_6541 == 176);
	if (cppVar_6543) {
	cppVar_6539 = P3;
	} else {
	cppVar_6545 = PC + 1;
	cppVar_6545 = (cppVar_6545 & cppMask_un_16_);
	cppVar_6546 = ROM.rd(cppVar_6545);
	cppVar_6548 = (cppVar_6546 == 184);
	if (cppVar_6548) {
	cppVar_6544 = IP;
	} else {
	cppVar_6550 = PC + 1;
	cppVar_6550 = (cppVar_6550 & cppMask_un_16_);
	cppVar_6551 = ROM.rd(cppVar_6550);
	cppVar_6553 = (cppVar_6551 == 208);
	if (cppVar_6553) {
	cppVar_6549 = PSW;
	} else {
	cppVar_6555 = PC + 1;
	cppVar_6555 = (cppVar_6555 & cppMask_un_16_);
	cppVar_6556 = ROM.rd(cppVar_6555);
	cppVar_6558 = (cppVar_6556 == 224);
	if (cppVar_6558) {
	cppVar_6554 = ACC;
	} else {
	cppVar_6560 = PC + 1;
	cppVar_6560 = (cppVar_6560 & cppMask_un_16_);
	cppVar_6561 = ROM.rd(cppVar_6560);
	cppVar_6563 = (cppVar_6561 == 240);
	if (cppVar_6563) {
	cppVar_6559 = B;
	} else {
	cppVar_6559 = 0;
	}
	cppVar_6554 = cppVar_6559;
	}
	cppVar_6549 = cppVar_6554;
	}
	cppVar_6544 = cppVar_6549;
	}
	cppVar_6539 = cppVar_6544;
	}
	cppVar_6534 = cppVar_6539;
	}
	cppVar_6529 = cppVar_6534;
	}
	cppVar_6524 = cppVar_6529;
	}
	cppVar_6519 = cppVar_6524;
	}
	cppVar_6514 = cppVar_6519;
	}
	cppVar_6509 = cppVar_6514;
	}
	cppVar_6504 = cppVar_6509;
	}
	cppVar_6499 = cppVar_6504;
	}
	cppVar_6494 = cppVar_6499;
	}
	cppVar_6489 = cppVar_6494;
	}
	cppVar_6484 = cppVar_6489;
	}
	cppVar_6479 = cppVar_6484;
	}
	cppVar_6474 = cppVar_6479;
	}
	cppVar_6469 = cppVar_6474;
	}
	cppVar_6464 = cppVar_6469;
	}
	cppVar_6459 = cppVar_6464;
	}
	cppVar_6450 = cppVar_6459;
	}
	cppVar_6565 = cppVar_6450 & ACC;
	cppVar_6444 = cppVar_6565;
	} else {
	cppVar_6444 = B;
	}
	cppVar_6440 = cppVar_6444;
	} else {
	cppVar_6567 = ROM.rd(PC);
	cppVar_6569 = (cppVar_6567 == 67);
	if (cppVar_6569) {
	cppVar_6572 = PC + 1;
	cppVar_6572 = (cppVar_6572 & cppMask_un_16_);
	cppVar_6573 = ROM.rd(cppVar_6572);
	cppVar_6575 = (cppVar_6573 == 240);
	if (cppVar_6575) {
	cppVar_6577 = PC + 1;
	cppVar_6577 = (cppVar_6577 & cppMask_un_16_);
	cppVar_6578 = ROM.rd(cppVar_6577);
	cppVar_6579 = (cppVar_6578 >> 7) & cppMask_un_1_;
	cppVar_6581 = (cppVar_6579 == 0);
	if (cppVar_6581) {
	cppVar_6582 = PC + 1;
	cppVar_6582 = (cppVar_6582 & cppMask_un_16_);
	cppVar_6583 = ROM.rd(cppVar_6582);
	cppVar_6584 = IRAM.rd(cppVar_6583);
	cppVar_6576 = cppVar_6584;
	} else {
	cppVar_6586 = PC + 1;
	cppVar_6586 = (cppVar_6586 & cppMask_un_16_);
	cppVar_6587 = ROM.rd(cppVar_6586);
	cppVar_6589 = (cppVar_6587 == 128);
	if (cppVar_6589) {
	cppVar_6585 = P0;
	} else {
	cppVar_6591 = PC + 1;
	cppVar_6591 = (cppVar_6591 & cppMask_un_16_);
	cppVar_6592 = ROM.rd(cppVar_6591);
	cppVar_6594 = (cppVar_6592 == 129);
	if (cppVar_6594) {
	cppVar_6590 = SP;
	} else {
	cppVar_6596 = PC + 1;
	cppVar_6596 = (cppVar_6596 & cppMask_un_16_);
	cppVar_6597 = ROM.rd(cppVar_6596);
	cppVar_6599 = (cppVar_6597 == 130);
	if (cppVar_6599) {
	cppVar_6595 = DPL;
	} else {
	cppVar_6601 = PC + 1;
	cppVar_6601 = (cppVar_6601 & cppMask_un_16_);
	cppVar_6602 = ROM.rd(cppVar_6601);
	cppVar_6604 = (cppVar_6602 == 131);
	if (cppVar_6604) {
	cppVar_6600 = DPH;
	} else {
	cppVar_6606 = PC + 1;
	cppVar_6606 = (cppVar_6606 & cppMask_un_16_);
	cppVar_6607 = ROM.rd(cppVar_6606);
	cppVar_6609 = (cppVar_6607 == 135);
	if (cppVar_6609) {
	cppVar_6605 = PCON;
	} else {
	cppVar_6611 = PC + 1;
	cppVar_6611 = (cppVar_6611 & cppMask_un_16_);
	cppVar_6612 = ROM.rd(cppVar_6611);
	cppVar_6614 = (cppVar_6612 == 136);
	if (cppVar_6614) {
	cppVar_6610 = TCON;
	} else {
	cppVar_6616 = PC + 1;
	cppVar_6616 = (cppVar_6616 & cppMask_un_16_);
	cppVar_6617 = ROM.rd(cppVar_6616);
	cppVar_6619 = (cppVar_6617 == 137);
	if (cppVar_6619) {
	cppVar_6615 = TMOD;
	} else {
	cppVar_6621 = PC + 1;
	cppVar_6621 = (cppVar_6621 & cppMask_un_16_);
	cppVar_6622 = ROM.rd(cppVar_6621);
	cppVar_6624 = (cppVar_6622 == 138);
	if (cppVar_6624) {
	cppVar_6620 = TL0;
	} else {
	cppVar_6626 = PC + 1;
	cppVar_6626 = (cppVar_6626 & cppMask_un_16_);
	cppVar_6627 = ROM.rd(cppVar_6626);
	cppVar_6629 = (cppVar_6627 == 140);
	if (cppVar_6629) {
	cppVar_6625 = TH0;
	} else {
	cppVar_6631 = PC + 1;
	cppVar_6631 = (cppVar_6631 & cppMask_un_16_);
	cppVar_6632 = ROM.rd(cppVar_6631);
	cppVar_6634 = (cppVar_6632 == 139);
	if (cppVar_6634) {
	cppVar_6630 = TL1;
	} else {
	cppVar_6636 = PC + 1;
	cppVar_6636 = (cppVar_6636 & cppMask_un_16_);
	cppVar_6637 = ROM.rd(cppVar_6636);
	cppVar_6639 = (cppVar_6637 == 141);
	if (cppVar_6639) {
	cppVar_6635 = TH1;
	} else {
	cppVar_6641 = PC + 1;
	cppVar_6641 = (cppVar_6641 & cppMask_un_16_);
	cppVar_6642 = ROM.rd(cppVar_6641);
	cppVar_6644 = (cppVar_6642 == 144);
	if (cppVar_6644) {
	cppVar_6640 = P1;
	} else {
	cppVar_6646 = PC + 1;
	cppVar_6646 = (cppVar_6646 & cppMask_un_16_);
	cppVar_6647 = ROM.rd(cppVar_6646);
	cppVar_6649 = (cppVar_6647 == 152);
	if (cppVar_6649) {
	cppVar_6645 = SCON;
	} else {
	cppVar_6651 = PC + 1;
	cppVar_6651 = (cppVar_6651 & cppMask_un_16_);
	cppVar_6652 = ROM.rd(cppVar_6651);
	cppVar_6654 = (cppVar_6652 == 153);
	if (cppVar_6654) {
	cppVar_6650 = SBUF;
	} else {
	cppVar_6656 = PC + 1;
	cppVar_6656 = (cppVar_6656 & cppMask_un_16_);
	cppVar_6657 = ROM.rd(cppVar_6656);
	cppVar_6659 = (cppVar_6657 == 160);
	if (cppVar_6659) {
	cppVar_6655 = P2;
	} else {
	cppVar_6661 = PC + 1;
	cppVar_6661 = (cppVar_6661 & cppMask_un_16_);
	cppVar_6662 = ROM.rd(cppVar_6661);
	cppVar_6664 = (cppVar_6662 == 168);
	if (cppVar_6664) {
	cppVar_6660 = IE;
	} else {
	cppVar_6666 = PC + 1;
	cppVar_6666 = (cppVar_6666 & cppMask_un_16_);
	cppVar_6667 = ROM.rd(cppVar_6666);
	cppVar_6669 = (cppVar_6667 == 176);
	if (cppVar_6669) {
	cppVar_6665 = P3;
	} else {
	cppVar_6671 = PC + 1;
	cppVar_6671 = (cppVar_6671 & cppMask_un_16_);
	cppVar_6672 = ROM.rd(cppVar_6671);
	cppVar_6674 = (cppVar_6672 == 184);
	if (cppVar_6674) {
	cppVar_6670 = IP;
	} else {
	cppVar_6676 = PC + 1;
	cppVar_6676 = (cppVar_6676 & cppMask_un_16_);
	cppVar_6677 = ROM.rd(cppVar_6676);
	cppVar_6679 = (cppVar_6677 == 208);
	if (cppVar_6679) {
	cppVar_6675 = PSW;
	} else {
	cppVar_6681 = PC + 1;
	cppVar_6681 = (cppVar_6681 & cppMask_un_16_);
	cppVar_6682 = ROM.rd(cppVar_6681);
	cppVar_6684 = (cppVar_6682 == 224);
	if (cppVar_6684) {
	cppVar_6680 = ACC;
	} else {
	cppVar_6686 = PC + 1;
	cppVar_6686 = (cppVar_6686 & cppMask_un_16_);
	cppVar_6687 = ROM.rd(cppVar_6686);
	cppVar_6689 = (cppVar_6687 == 240);
	if (cppVar_6689) {
	cppVar_6685 = B;
	} else {
	cppVar_6685 = 0;
	}
	cppVar_6680 = cppVar_6685;
	}
	cppVar_6675 = cppVar_6680;
	}
	cppVar_6670 = cppVar_6675;
	}
	cppVar_6665 = cppVar_6670;
	}
	cppVar_6660 = cppVar_6665;
	}
	cppVar_6655 = cppVar_6660;
	}
	cppVar_6650 = cppVar_6655;
	}
	cppVar_6645 = cppVar_6650;
	}
	cppVar_6640 = cppVar_6645;
	}
	cppVar_6635 = cppVar_6640;
	}
	cppVar_6630 = cppVar_6635;
	}
	cppVar_6625 = cppVar_6630;
	}
	cppVar_6620 = cppVar_6625;
	}
	cppVar_6615 = cppVar_6620;
	}
	cppVar_6610 = cppVar_6615;
	}
	cppVar_6605 = cppVar_6610;
	}
	cppVar_6600 = cppVar_6605;
	}
	cppVar_6595 = cppVar_6600;
	}
	cppVar_6590 = cppVar_6595;
	}
	cppVar_6585 = cppVar_6590;
	}
	cppVar_6576 = cppVar_6585;
	}
	cppVar_6692 = PC + 2;
	cppVar_6692 = (cppVar_6692 & cppMask_un_16_);
	cppVar_6693 = ROM.rd(cppVar_6692);
	cppVar_6694 = cppVar_6576 | cppVar_6693;
	cppVar_6570 = cppVar_6694;
	} else {
	cppVar_6570 = B;
	}
	cppVar_6566 = cppVar_6570;
	} else {
	cppVar_6696 = ROM.rd(PC);
	cppVar_6698 = (cppVar_6696 == 66);
	if (cppVar_6698) {
	cppVar_6701 = PC + 1;
	cppVar_6701 = (cppVar_6701 & cppMask_un_16_);
	cppVar_6702 = ROM.rd(cppVar_6701);
	cppVar_6704 = (cppVar_6702 == 240);
	if (cppVar_6704) {
	cppVar_6706 = PC + 1;
	cppVar_6706 = (cppVar_6706 & cppMask_un_16_);
	cppVar_6707 = ROM.rd(cppVar_6706);
	cppVar_6708 = (cppVar_6707 >> 7) & cppMask_un_1_;
	cppVar_6710 = (cppVar_6708 == 0);
	if (cppVar_6710) {
	cppVar_6711 = PC + 1;
	cppVar_6711 = (cppVar_6711 & cppMask_un_16_);
	cppVar_6712 = ROM.rd(cppVar_6711);
	cppVar_6713 = IRAM.rd(cppVar_6712);
	cppVar_6705 = cppVar_6713;
	} else {
	cppVar_6715 = PC + 1;
	cppVar_6715 = (cppVar_6715 & cppMask_un_16_);
	cppVar_6716 = ROM.rd(cppVar_6715);
	cppVar_6718 = (cppVar_6716 == 128);
	if (cppVar_6718) {
	cppVar_6714 = P0;
	} else {
	cppVar_6720 = PC + 1;
	cppVar_6720 = (cppVar_6720 & cppMask_un_16_);
	cppVar_6721 = ROM.rd(cppVar_6720);
	cppVar_6723 = (cppVar_6721 == 129);
	if (cppVar_6723) {
	cppVar_6719 = SP;
	} else {
	cppVar_6725 = PC + 1;
	cppVar_6725 = (cppVar_6725 & cppMask_un_16_);
	cppVar_6726 = ROM.rd(cppVar_6725);
	cppVar_6728 = (cppVar_6726 == 130);
	if (cppVar_6728) {
	cppVar_6724 = DPL;
	} else {
	cppVar_6730 = PC + 1;
	cppVar_6730 = (cppVar_6730 & cppMask_un_16_);
	cppVar_6731 = ROM.rd(cppVar_6730);
	cppVar_6733 = (cppVar_6731 == 131);
	if (cppVar_6733) {
	cppVar_6729 = DPH;
	} else {
	cppVar_6735 = PC + 1;
	cppVar_6735 = (cppVar_6735 & cppMask_un_16_);
	cppVar_6736 = ROM.rd(cppVar_6735);
	cppVar_6738 = (cppVar_6736 == 135);
	if (cppVar_6738) {
	cppVar_6734 = PCON;
	} else {
	cppVar_6740 = PC + 1;
	cppVar_6740 = (cppVar_6740 & cppMask_un_16_);
	cppVar_6741 = ROM.rd(cppVar_6740);
	cppVar_6743 = (cppVar_6741 == 136);
	if (cppVar_6743) {
	cppVar_6739 = TCON;
	} else {
	cppVar_6745 = PC + 1;
	cppVar_6745 = (cppVar_6745 & cppMask_un_16_);
	cppVar_6746 = ROM.rd(cppVar_6745);
	cppVar_6748 = (cppVar_6746 == 137);
	if (cppVar_6748) {
	cppVar_6744 = TMOD;
	} else {
	cppVar_6750 = PC + 1;
	cppVar_6750 = (cppVar_6750 & cppMask_un_16_);
	cppVar_6751 = ROM.rd(cppVar_6750);
	cppVar_6753 = (cppVar_6751 == 138);
	if (cppVar_6753) {
	cppVar_6749 = TL0;
	} else {
	cppVar_6755 = PC + 1;
	cppVar_6755 = (cppVar_6755 & cppMask_un_16_);
	cppVar_6756 = ROM.rd(cppVar_6755);
	cppVar_6758 = (cppVar_6756 == 140);
	if (cppVar_6758) {
	cppVar_6754 = TH0;
	} else {
	cppVar_6760 = PC + 1;
	cppVar_6760 = (cppVar_6760 & cppMask_un_16_);
	cppVar_6761 = ROM.rd(cppVar_6760);
	cppVar_6763 = (cppVar_6761 == 139);
	if (cppVar_6763) {
	cppVar_6759 = TL1;
	} else {
	cppVar_6765 = PC + 1;
	cppVar_6765 = (cppVar_6765 & cppMask_un_16_);
	cppVar_6766 = ROM.rd(cppVar_6765);
	cppVar_6768 = (cppVar_6766 == 141);
	if (cppVar_6768) {
	cppVar_6764 = TH1;
	} else {
	cppVar_6770 = PC + 1;
	cppVar_6770 = (cppVar_6770 & cppMask_un_16_);
	cppVar_6771 = ROM.rd(cppVar_6770);
	cppVar_6773 = (cppVar_6771 == 144);
	if (cppVar_6773) {
	cppVar_6769 = P1;
	} else {
	cppVar_6775 = PC + 1;
	cppVar_6775 = (cppVar_6775 & cppMask_un_16_);
	cppVar_6776 = ROM.rd(cppVar_6775);
	cppVar_6778 = (cppVar_6776 == 152);
	if (cppVar_6778) {
	cppVar_6774 = SCON;
	} else {
	cppVar_6780 = PC + 1;
	cppVar_6780 = (cppVar_6780 & cppMask_un_16_);
	cppVar_6781 = ROM.rd(cppVar_6780);
	cppVar_6783 = (cppVar_6781 == 153);
	if (cppVar_6783) {
	cppVar_6779 = SBUF;
	} else {
	cppVar_6785 = PC + 1;
	cppVar_6785 = (cppVar_6785 & cppMask_un_16_);
	cppVar_6786 = ROM.rd(cppVar_6785);
	cppVar_6788 = (cppVar_6786 == 160);
	if (cppVar_6788) {
	cppVar_6784 = P2;
	} else {
	cppVar_6790 = PC + 1;
	cppVar_6790 = (cppVar_6790 & cppMask_un_16_);
	cppVar_6791 = ROM.rd(cppVar_6790);
	cppVar_6793 = (cppVar_6791 == 168);
	if (cppVar_6793) {
	cppVar_6789 = IE;
	} else {
	cppVar_6795 = PC + 1;
	cppVar_6795 = (cppVar_6795 & cppMask_un_16_);
	cppVar_6796 = ROM.rd(cppVar_6795);
	cppVar_6798 = (cppVar_6796 == 176);
	if (cppVar_6798) {
	cppVar_6794 = P3;
	} else {
	cppVar_6800 = PC + 1;
	cppVar_6800 = (cppVar_6800 & cppMask_un_16_);
	cppVar_6801 = ROM.rd(cppVar_6800);
	cppVar_6803 = (cppVar_6801 == 184);
	if (cppVar_6803) {
	cppVar_6799 = IP;
	} else {
	cppVar_6805 = PC + 1;
	cppVar_6805 = (cppVar_6805 & cppMask_un_16_);
	cppVar_6806 = ROM.rd(cppVar_6805);
	cppVar_6808 = (cppVar_6806 == 208);
	if (cppVar_6808) {
	cppVar_6804 = PSW;
	} else {
	cppVar_6810 = PC + 1;
	cppVar_6810 = (cppVar_6810 & cppMask_un_16_);
	cppVar_6811 = ROM.rd(cppVar_6810);
	cppVar_6813 = (cppVar_6811 == 224);
	if (cppVar_6813) {
	cppVar_6809 = ACC;
	} else {
	cppVar_6815 = PC + 1;
	cppVar_6815 = (cppVar_6815 & cppMask_un_16_);
	cppVar_6816 = ROM.rd(cppVar_6815);
	cppVar_6818 = (cppVar_6816 == 240);
	if (cppVar_6818) {
	cppVar_6814 = B;
	} else {
	cppVar_6814 = 0;
	}
	cppVar_6809 = cppVar_6814;
	}
	cppVar_6804 = cppVar_6809;
	}
	cppVar_6799 = cppVar_6804;
	}
	cppVar_6794 = cppVar_6799;
	}
	cppVar_6789 = cppVar_6794;
	}
	cppVar_6784 = cppVar_6789;
	}
	cppVar_6779 = cppVar_6784;
	}
	cppVar_6774 = cppVar_6779;
	}
	cppVar_6769 = cppVar_6774;
	}
	cppVar_6764 = cppVar_6769;
	}
	cppVar_6759 = cppVar_6764;
	}
	cppVar_6754 = cppVar_6759;
	}
	cppVar_6749 = cppVar_6754;
	}
	cppVar_6744 = cppVar_6749;
	}
	cppVar_6739 = cppVar_6744;
	}
	cppVar_6734 = cppVar_6739;
	}
	cppVar_6729 = cppVar_6734;
	}
	cppVar_6724 = cppVar_6729;
	}
	cppVar_6719 = cppVar_6724;
	}
	cppVar_6714 = cppVar_6719;
	}
	cppVar_6705 = cppVar_6714;
	}
	cppVar_6820 = cppVar_6705 | ACC;
	cppVar_6699 = cppVar_6820;
	} else {
	cppVar_6699 = B;
	}
	cppVar_6695 = cppVar_6699;
	} else {
	cppVar_6822 = ROM.rd(PC);
	cppVar_6824 = (cppVar_6822 == 213);
	cppVar_6825 = ROM.rd(PC);
	cppVar_6827 = (cppVar_6825 == 21);
	cppVar_6828 = cppVar_6824 || cppVar_6827;
	if (cppVar_6828) {
	cppVar_6831 = PC + 1;
	cppVar_6831 = (cppVar_6831 & cppMask_un_16_);
	cppVar_6832 = ROM.rd(cppVar_6831);
	cppVar_6834 = (cppVar_6832 == 240);
	if (cppVar_6834) {
	cppVar_6836 = PC + 1;
	cppVar_6836 = (cppVar_6836 & cppMask_un_16_);
	cppVar_6837 = ROM.rd(cppVar_6836);
	cppVar_6838 = (cppVar_6837 >> 7) & cppMask_un_1_;
	cppVar_6840 = (cppVar_6838 == 0);
	if (cppVar_6840) {
	cppVar_6841 = PC + 1;
	cppVar_6841 = (cppVar_6841 & cppMask_un_16_);
	cppVar_6842 = ROM.rd(cppVar_6841);
	cppVar_6843 = IRAM.rd(cppVar_6842);
	cppVar_6835 = cppVar_6843;
	} else {
	cppVar_6845 = PC + 1;
	cppVar_6845 = (cppVar_6845 & cppMask_un_16_);
	cppVar_6846 = ROM.rd(cppVar_6845);
	cppVar_6848 = (cppVar_6846 == 128);
	if (cppVar_6848) {
	cppVar_6844 = P0;
	} else {
	cppVar_6850 = PC + 1;
	cppVar_6850 = (cppVar_6850 & cppMask_un_16_);
	cppVar_6851 = ROM.rd(cppVar_6850);
	cppVar_6853 = (cppVar_6851 == 129);
	if (cppVar_6853) {
	cppVar_6849 = SP;
	} else {
	cppVar_6855 = PC + 1;
	cppVar_6855 = (cppVar_6855 & cppMask_un_16_);
	cppVar_6856 = ROM.rd(cppVar_6855);
	cppVar_6858 = (cppVar_6856 == 130);
	if (cppVar_6858) {
	cppVar_6854 = DPL;
	} else {
	cppVar_6860 = PC + 1;
	cppVar_6860 = (cppVar_6860 & cppMask_un_16_);
	cppVar_6861 = ROM.rd(cppVar_6860);
	cppVar_6863 = (cppVar_6861 == 131);
	if (cppVar_6863) {
	cppVar_6859 = DPH;
	} else {
	cppVar_6865 = PC + 1;
	cppVar_6865 = (cppVar_6865 & cppMask_un_16_);
	cppVar_6866 = ROM.rd(cppVar_6865);
	cppVar_6868 = (cppVar_6866 == 135);
	if (cppVar_6868) {
	cppVar_6864 = PCON;
	} else {
	cppVar_6870 = PC + 1;
	cppVar_6870 = (cppVar_6870 & cppMask_un_16_);
	cppVar_6871 = ROM.rd(cppVar_6870);
	cppVar_6873 = (cppVar_6871 == 136);
	if (cppVar_6873) {
	cppVar_6869 = TCON;
	} else {
	cppVar_6875 = PC + 1;
	cppVar_6875 = (cppVar_6875 & cppMask_un_16_);
	cppVar_6876 = ROM.rd(cppVar_6875);
	cppVar_6878 = (cppVar_6876 == 137);
	if (cppVar_6878) {
	cppVar_6874 = TMOD;
	} else {
	cppVar_6880 = PC + 1;
	cppVar_6880 = (cppVar_6880 & cppMask_un_16_);
	cppVar_6881 = ROM.rd(cppVar_6880);
	cppVar_6883 = (cppVar_6881 == 138);
	if (cppVar_6883) {
	cppVar_6879 = TL0;
	} else {
	cppVar_6885 = PC + 1;
	cppVar_6885 = (cppVar_6885 & cppMask_un_16_);
	cppVar_6886 = ROM.rd(cppVar_6885);
	cppVar_6888 = (cppVar_6886 == 140);
	if (cppVar_6888) {
	cppVar_6884 = TH0;
	} else {
	cppVar_6890 = PC + 1;
	cppVar_6890 = (cppVar_6890 & cppMask_un_16_);
	cppVar_6891 = ROM.rd(cppVar_6890);
	cppVar_6893 = (cppVar_6891 == 139);
	if (cppVar_6893) {
	cppVar_6889 = TL1;
	} else {
	cppVar_6895 = PC + 1;
	cppVar_6895 = (cppVar_6895 & cppMask_un_16_);
	cppVar_6896 = ROM.rd(cppVar_6895);
	cppVar_6898 = (cppVar_6896 == 141);
	if (cppVar_6898) {
	cppVar_6894 = TH1;
	} else {
	cppVar_6900 = PC + 1;
	cppVar_6900 = (cppVar_6900 & cppMask_un_16_);
	cppVar_6901 = ROM.rd(cppVar_6900);
	cppVar_6903 = (cppVar_6901 == 144);
	if (cppVar_6903) {
	cppVar_6899 = P1;
	} else {
	cppVar_6905 = PC + 1;
	cppVar_6905 = (cppVar_6905 & cppMask_un_16_);
	cppVar_6906 = ROM.rd(cppVar_6905);
	cppVar_6908 = (cppVar_6906 == 152);
	if (cppVar_6908) {
	cppVar_6904 = SCON;
	} else {
	cppVar_6910 = PC + 1;
	cppVar_6910 = (cppVar_6910 & cppMask_un_16_);
	cppVar_6911 = ROM.rd(cppVar_6910);
	cppVar_6913 = (cppVar_6911 == 153);
	if (cppVar_6913) {
	cppVar_6909 = SBUF;
	} else {
	cppVar_6915 = PC + 1;
	cppVar_6915 = (cppVar_6915 & cppMask_un_16_);
	cppVar_6916 = ROM.rd(cppVar_6915);
	cppVar_6918 = (cppVar_6916 == 160);
	if (cppVar_6918) {
	cppVar_6914 = P2;
	} else {
	cppVar_6920 = PC + 1;
	cppVar_6920 = (cppVar_6920 & cppMask_un_16_);
	cppVar_6921 = ROM.rd(cppVar_6920);
	cppVar_6923 = (cppVar_6921 == 168);
	if (cppVar_6923) {
	cppVar_6919 = IE;
	} else {
	cppVar_6925 = PC + 1;
	cppVar_6925 = (cppVar_6925 & cppMask_un_16_);
	cppVar_6926 = ROM.rd(cppVar_6925);
	cppVar_6928 = (cppVar_6926 == 176);
	if (cppVar_6928) {
	cppVar_6924 = P3;
	} else {
	cppVar_6930 = PC + 1;
	cppVar_6930 = (cppVar_6930 & cppMask_un_16_);
	cppVar_6931 = ROM.rd(cppVar_6930);
	cppVar_6933 = (cppVar_6931 == 184);
	if (cppVar_6933) {
	cppVar_6929 = IP;
	} else {
	cppVar_6935 = PC + 1;
	cppVar_6935 = (cppVar_6935 & cppMask_un_16_);
	cppVar_6936 = ROM.rd(cppVar_6935);
	cppVar_6938 = (cppVar_6936 == 208);
	if (cppVar_6938) {
	cppVar_6934 = PSW;
	} else {
	cppVar_6940 = PC + 1;
	cppVar_6940 = (cppVar_6940 & cppMask_un_16_);
	cppVar_6941 = ROM.rd(cppVar_6940);
	cppVar_6943 = (cppVar_6941 == 224);
	if (cppVar_6943) {
	cppVar_6939 = ACC;
	} else {
	cppVar_6945 = PC + 1;
	cppVar_6945 = (cppVar_6945 & cppMask_un_16_);
	cppVar_6946 = ROM.rd(cppVar_6945);
	cppVar_6948 = (cppVar_6946 == 240);
	if (cppVar_6948) {
	cppVar_6944 = B;
	} else {
	cppVar_6944 = 0;
	}
	cppVar_6939 = cppVar_6944;
	}
	cppVar_6934 = cppVar_6939;
	}
	cppVar_6929 = cppVar_6934;
	}
	cppVar_6924 = cppVar_6929;
	}
	cppVar_6919 = cppVar_6924;
	}
	cppVar_6914 = cppVar_6919;
	}
	cppVar_6909 = cppVar_6914;
	}
	cppVar_6904 = cppVar_6909;
	}
	cppVar_6899 = cppVar_6904;
	}
	cppVar_6894 = cppVar_6899;
	}
	cppVar_6889 = cppVar_6894;
	}
	cppVar_6884 = cppVar_6889;
	}
	cppVar_6879 = cppVar_6884;
	}
	cppVar_6874 = cppVar_6879;
	}
	cppVar_6869 = cppVar_6874;
	}
	cppVar_6864 = cppVar_6869;
	}
	cppVar_6859 = cppVar_6864;
	}
	cppVar_6854 = cppVar_6859;
	}
	cppVar_6849 = cppVar_6854;
	}
	cppVar_6844 = cppVar_6849;
	}
	cppVar_6835 = cppVar_6844;
	}
	cppVar_6951 = cppVar_6835 - 1;
	cppVar_6951 = (cppVar_6951 & cppMask_un_8_);
	cppVar_6829 = cppVar_6951;
	} else {
	cppVar_6829 = B;
	}
	cppVar_6821 = cppVar_6829;
	} else {
	cppVar_6953 = ROM.rd(PC);
	cppVar_6955 = (cppVar_6953 == 194);
	cppVar_6956 = ROM.rd(PC);
	cppVar_6958 = (cppVar_6956 == 16);
	cppVar_6959 = cppVar_6955 || cppVar_6958;
	if (cppVar_6959) {
	cppVar_6963 = PC + 1;
	cppVar_6963 = (cppVar_6963 & cppMask_un_16_);
	cppVar_6964 = ROM.rd(cppVar_6963);
	cppVar_6965 = (cppVar_6964 >> 7) & cppMask_un_1_;
	cppVar_6967 = (cppVar_6965 == 1);
	if (cppVar_6967) {
	cppVar_6968 = PC + 1;
	cppVar_6968 = (cppVar_6968 & cppMask_un_16_);
	cppVar_6969 = ROM.rd(cppVar_6968);
	cppVar_6970 = (cppVar_6969 >> 3) & cppMask_un_5_;
	cppVar_6972 = (cppVar_6970 << 3) | 0;
	cppVar_6972 = (cppVar_6972 & cppMask_un_8_);
	cppVar_6961 = cppVar_6972;
	} else {
	cppVar_6973 = PC + 1;
	cppVar_6973 = (cppVar_6973 & cppMask_un_16_);
	cppVar_6974 = ROM.rd(cppVar_6973);
	cppVar_6975 = (cppVar_6974 >> 3) & cppMask_un_5_;
	cppVar_6976 = (cppVar_6975 & cppMask_un_5_);
	cppVar_6978 = cppVar_6976 + 32;
	cppVar_6978 = (cppVar_6978 & cppMask_un_8_);
	cppVar_6961 = cppVar_6978;
	}
	cppVar_6980 = (cppVar_6961 == 240);
	if (cppVar_6980) {
	cppVar_6982 = PC + 1;
	cppVar_6982 = (cppVar_6982 & cppMask_un_16_);
	cppVar_6983 = ROM.rd(cppVar_6982);
	cppVar_6984 = (cppVar_6983 >> 0) & cppMask_un_3_;
	cppVar_6985 = (cppVar_6984 & cppMask_un_3_);
	cppVar_6986 = 1 << static_cast<unsigned>(cppVar_6985);
	cppVar_6986 = (cppVar_6986 & cppMask_un_8_);
	cppVar_6987 = ~cppVar_6986;
	cppVar_6990 = PC + 1;
	cppVar_6990 = (cppVar_6990 & cppMask_un_16_);
	cppVar_6991 = ROM.rd(cppVar_6990);
	cppVar_6992 = (cppVar_6991 >> 7) & cppMask_un_1_;
	cppVar_6993 = (cppVar_6992 == 1);
	if (cppVar_6993) {
	cppVar_6994 = PC + 1;
	cppVar_6994 = (cppVar_6994 & cppMask_un_16_);
	cppVar_6995 = ROM.rd(cppVar_6994);
	cppVar_6996 = (cppVar_6995 >> 3) & cppMask_un_5_;
	cppVar_6997 = (cppVar_6996 << 3) | 0;
	cppVar_6997 = (cppVar_6997 & cppMask_un_8_);
	cppVar_6989 = cppVar_6997;
	} else {
	cppVar_6998 = PC + 1;
	cppVar_6998 = (cppVar_6998 & cppMask_un_16_);
	cppVar_6999 = ROM.rd(cppVar_6998);
	cppVar_7000 = (cppVar_6999 >> 3) & cppMask_un_5_;
	cppVar_7001 = (cppVar_7000 & cppMask_un_5_);
	cppVar_7002 = cppVar_7001 + 32;
	cppVar_7002 = (cppVar_7002 & cppMask_un_8_);
	cppVar_6989 = cppVar_7002;
	}
	cppVar_7003 = (cppVar_6989 >> 7) & cppMask_un_1_;
	cppVar_7005 = (cppVar_7003 == 0);
	if (cppVar_7005) {
	cppVar_7007 = PC + 1;
	cppVar_7007 = (cppVar_7007 & cppMask_un_16_);
	cppVar_7008 = ROM.rd(cppVar_7007);
	cppVar_7009 = (cppVar_7008 >> 7) & cppMask_un_1_;
	cppVar_7010 = (cppVar_7009 == 1);
	if (cppVar_7010) {
	cppVar_7011 = PC + 1;
	cppVar_7011 = (cppVar_7011 & cppMask_un_16_);
	cppVar_7012 = ROM.rd(cppVar_7011);
	cppVar_7013 = (cppVar_7012 >> 3) & cppMask_un_5_;
	cppVar_7014 = (cppVar_7013 << 3) | 0;
	cppVar_7014 = (cppVar_7014 & cppMask_un_8_);
	cppVar_7006 = cppVar_7014;
	} else {
	cppVar_7015 = PC + 1;
	cppVar_7015 = (cppVar_7015 & cppMask_un_16_);
	cppVar_7016 = ROM.rd(cppVar_7015);
	cppVar_7017 = (cppVar_7016 >> 3) & cppMask_un_5_;
	cppVar_7018 = (cppVar_7017 & cppMask_un_5_);
	cppVar_7019 = cppVar_7018 + 32;
	cppVar_7019 = (cppVar_7019 & cppMask_un_8_);
	cppVar_7006 = cppVar_7019;
	}
	cppVar_7020 = IRAM.rd(cppVar_7006);
	cppVar_6988 = cppVar_7020;
	} else {
	cppVar_7023 = PC + 1;
	cppVar_7023 = (cppVar_7023 & cppMask_un_16_);
	cppVar_7024 = ROM.rd(cppVar_7023);
	cppVar_7025 = (cppVar_7024 >> 7) & cppMask_un_1_;
	cppVar_7026 = (cppVar_7025 == 1);
	if (cppVar_7026) {
	cppVar_7027 = PC + 1;
	cppVar_7027 = (cppVar_7027 & cppMask_un_16_);
	cppVar_7028 = ROM.rd(cppVar_7027);
	cppVar_7029 = (cppVar_7028 >> 3) & cppMask_un_5_;
	cppVar_7030 = (cppVar_7029 << 3) | 0;
	cppVar_7030 = (cppVar_7030 & cppMask_un_8_);
	cppVar_7022 = cppVar_7030;
	} else {
	cppVar_7031 = PC + 1;
	cppVar_7031 = (cppVar_7031 & cppMask_un_16_);
	cppVar_7032 = ROM.rd(cppVar_7031);
	cppVar_7033 = (cppVar_7032 >> 3) & cppMask_un_5_;
	cppVar_7034 = (cppVar_7033 & cppMask_un_5_);
	cppVar_7035 = cppVar_7034 + 32;
	cppVar_7035 = (cppVar_7035 & cppMask_un_8_);
	cppVar_7022 = cppVar_7035;
	}
	cppVar_7037 = (cppVar_7022 == 128);
	if (cppVar_7037) {
	cppVar_7021 = P0;
	} else {
	cppVar_7040 = PC + 1;
	cppVar_7040 = (cppVar_7040 & cppMask_un_16_);
	cppVar_7041 = ROM.rd(cppVar_7040);
	cppVar_7042 = (cppVar_7041 >> 7) & cppMask_un_1_;
	cppVar_7043 = (cppVar_7042 == 1);
	if (cppVar_7043) {
	cppVar_7044 = PC + 1;
	cppVar_7044 = (cppVar_7044 & cppMask_un_16_);
	cppVar_7045 = ROM.rd(cppVar_7044);
	cppVar_7046 = (cppVar_7045 >> 3) & cppMask_un_5_;
	cppVar_7047 = (cppVar_7046 << 3) | 0;
	cppVar_7047 = (cppVar_7047 & cppMask_un_8_);
	cppVar_7039 = cppVar_7047;
	} else {
	cppVar_7048 = PC + 1;
	cppVar_7048 = (cppVar_7048 & cppMask_un_16_);
	cppVar_7049 = ROM.rd(cppVar_7048);
	cppVar_7050 = (cppVar_7049 >> 3) & cppMask_un_5_;
	cppVar_7051 = (cppVar_7050 & cppMask_un_5_);
	cppVar_7052 = cppVar_7051 + 32;
	cppVar_7052 = (cppVar_7052 & cppMask_un_8_);
	cppVar_7039 = cppVar_7052;
	}
	cppVar_7054 = (cppVar_7039 == 129);
	if (cppVar_7054) {
	cppVar_7038 = SP;
	} else {
	cppVar_7057 = PC + 1;
	cppVar_7057 = (cppVar_7057 & cppMask_un_16_);
	cppVar_7058 = ROM.rd(cppVar_7057);
	cppVar_7059 = (cppVar_7058 >> 7) & cppMask_un_1_;
	cppVar_7060 = (cppVar_7059 == 1);
	if (cppVar_7060) {
	cppVar_7061 = PC + 1;
	cppVar_7061 = (cppVar_7061 & cppMask_un_16_);
	cppVar_7062 = ROM.rd(cppVar_7061);
	cppVar_7063 = (cppVar_7062 >> 3) & cppMask_un_5_;
	cppVar_7064 = (cppVar_7063 << 3) | 0;
	cppVar_7064 = (cppVar_7064 & cppMask_un_8_);
	cppVar_7056 = cppVar_7064;
	} else {
	cppVar_7065 = PC + 1;
	cppVar_7065 = (cppVar_7065 & cppMask_un_16_);
	cppVar_7066 = ROM.rd(cppVar_7065);
	cppVar_7067 = (cppVar_7066 >> 3) & cppMask_un_5_;
	cppVar_7068 = (cppVar_7067 & cppMask_un_5_);
	cppVar_7069 = cppVar_7068 + 32;
	cppVar_7069 = (cppVar_7069 & cppMask_un_8_);
	cppVar_7056 = cppVar_7069;
	}
	cppVar_7071 = (cppVar_7056 == 130);
	if (cppVar_7071) {
	cppVar_7055 = DPL;
	} else {
	cppVar_7074 = PC + 1;
	cppVar_7074 = (cppVar_7074 & cppMask_un_16_);
	cppVar_7075 = ROM.rd(cppVar_7074);
	cppVar_7076 = (cppVar_7075 >> 7) & cppMask_un_1_;
	cppVar_7077 = (cppVar_7076 == 1);
	if (cppVar_7077) {
	cppVar_7078 = PC + 1;
	cppVar_7078 = (cppVar_7078 & cppMask_un_16_);
	cppVar_7079 = ROM.rd(cppVar_7078);
	cppVar_7080 = (cppVar_7079 >> 3) & cppMask_un_5_;
	cppVar_7081 = (cppVar_7080 << 3) | 0;
	cppVar_7081 = (cppVar_7081 & cppMask_un_8_);
	cppVar_7073 = cppVar_7081;
	} else {
	cppVar_7082 = PC + 1;
	cppVar_7082 = (cppVar_7082 & cppMask_un_16_);
	cppVar_7083 = ROM.rd(cppVar_7082);
	cppVar_7084 = (cppVar_7083 >> 3) & cppMask_un_5_;
	cppVar_7085 = (cppVar_7084 & cppMask_un_5_);
	cppVar_7086 = cppVar_7085 + 32;
	cppVar_7086 = (cppVar_7086 & cppMask_un_8_);
	cppVar_7073 = cppVar_7086;
	}
	cppVar_7088 = (cppVar_7073 == 131);
	if (cppVar_7088) {
	cppVar_7072 = DPH;
	} else {
	cppVar_7091 = PC + 1;
	cppVar_7091 = (cppVar_7091 & cppMask_un_16_);
	cppVar_7092 = ROM.rd(cppVar_7091);
	cppVar_7093 = (cppVar_7092 >> 7) & cppMask_un_1_;
	cppVar_7094 = (cppVar_7093 == 1);
	if (cppVar_7094) {
	cppVar_7095 = PC + 1;
	cppVar_7095 = (cppVar_7095 & cppMask_un_16_);
	cppVar_7096 = ROM.rd(cppVar_7095);
	cppVar_7097 = (cppVar_7096 >> 3) & cppMask_un_5_;
	cppVar_7098 = (cppVar_7097 << 3) | 0;
	cppVar_7098 = (cppVar_7098 & cppMask_un_8_);
	cppVar_7090 = cppVar_7098;
	} else {
	cppVar_7099 = PC + 1;
	cppVar_7099 = (cppVar_7099 & cppMask_un_16_);
	cppVar_7100 = ROM.rd(cppVar_7099);
	cppVar_7101 = (cppVar_7100 >> 3) & cppMask_un_5_;
	cppVar_7102 = (cppVar_7101 & cppMask_un_5_);
	cppVar_7103 = cppVar_7102 + 32;
	cppVar_7103 = (cppVar_7103 & cppMask_un_8_);
	cppVar_7090 = cppVar_7103;
	}
	cppVar_7105 = (cppVar_7090 == 135);
	if (cppVar_7105) {
	cppVar_7089 = PCON;
	} else {
	cppVar_7108 = PC + 1;
	cppVar_7108 = (cppVar_7108 & cppMask_un_16_);
	cppVar_7109 = ROM.rd(cppVar_7108);
	cppVar_7110 = (cppVar_7109 >> 7) & cppMask_un_1_;
	cppVar_7111 = (cppVar_7110 == 1);
	if (cppVar_7111) {
	cppVar_7112 = PC + 1;
	cppVar_7112 = (cppVar_7112 & cppMask_un_16_);
	cppVar_7113 = ROM.rd(cppVar_7112);
	cppVar_7114 = (cppVar_7113 >> 3) & cppMask_un_5_;
	cppVar_7115 = (cppVar_7114 << 3) | 0;
	cppVar_7115 = (cppVar_7115 & cppMask_un_8_);
	cppVar_7107 = cppVar_7115;
	} else {
	cppVar_7116 = PC + 1;
	cppVar_7116 = (cppVar_7116 & cppMask_un_16_);
	cppVar_7117 = ROM.rd(cppVar_7116);
	cppVar_7118 = (cppVar_7117 >> 3) & cppMask_un_5_;
	cppVar_7119 = (cppVar_7118 & cppMask_un_5_);
	cppVar_7120 = cppVar_7119 + 32;
	cppVar_7120 = (cppVar_7120 & cppMask_un_8_);
	cppVar_7107 = cppVar_7120;
	}
	cppVar_7122 = (cppVar_7107 == 136);
	if (cppVar_7122) {
	cppVar_7106 = TCON;
	} else {
	cppVar_7125 = PC + 1;
	cppVar_7125 = (cppVar_7125 & cppMask_un_16_);
	cppVar_7126 = ROM.rd(cppVar_7125);
	cppVar_7127 = (cppVar_7126 >> 7) & cppMask_un_1_;
	cppVar_7128 = (cppVar_7127 == 1);
	if (cppVar_7128) {
	cppVar_7129 = PC + 1;
	cppVar_7129 = (cppVar_7129 & cppMask_un_16_);
	cppVar_7130 = ROM.rd(cppVar_7129);
	cppVar_7131 = (cppVar_7130 >> 3) & cppMask_un_5_;
	cppVar_7132 = (cppVar_7131 << 3) | 0;
	cppVar_7132 = (cppVar_7132 & cppMask_un_8_);
	cppVar_7124 = cppVar_7132;
	} else {
	cppVar_7133 = PC + 1;
	cppVar_7133 = (cppVar_7133 & cppMask_un_16_);
	cppVar_7134 = ROM.rd(cppVar_7133);
	cppVar_7135 = (cppVar_7134 >> 3) & cppMask_un_5_;
	cppVar_7136 = (cppVar_7135 & cppMask_un_5_);
	cppVar_7137 = cppVar_7136 + 32;
	cppVar_7137 = (cppVar_7137 & cppMask_un_8_);
	cppVar_7124 = cppVar_7137;
	}
	cppVar_7139 = (cppVar_7124 == 137);
	if (cppVar_7139) {
	cppVar_7123 = TMOD;
	} else {
	cppVar_7142 = PC + 1;
	cppVar_7142 = (cppVar_7142 & cppMask_un_16_);
	cppVar_7143 = ROM.rd(cppVar_7142);
	cppVar_7144 = (cppVar_7143 >> 7) & cppMask_un_1_;
	cppVar_7145 = (cppVar_7144 == 1);
	if (cppVar_7145) {
	cppVar_7146 = PC + 1;
	cppVar_7146 = (cppVar_7146 & cppMask_un_16_);
	cppVar_7147 = ROM.rd(cppVar_7146);
	cppVar_7148 = (cppVar_7147 >> 3) & cppMask_un_5_;
	cppVar_7149 = (cppVar_7148 << 3) | 0;
	cppVar_7149 = (cppVar_7149 & cppMask_un_8_);
	cppVar_7141 = cppVar_7149;
	} else {
	cppVar_7150 = PC + 1;
	cppVar_7150 = (cppVar_7150 & cppMask_un_16_);
	cppVar_7151 = ROM.rd(cppVar_7150);
	cppVar_7152 = (cppVar_7151 >> 3) & cppMask_un_5_;
	cppVar_7153 = (cppVar_7152 & cppMask_un_5_);
	cppVar_7154 = cppVar_7153 + 32;
	cppVar_7154 = (cppVar_7154 & cppMask_un_8_);
	cppVar_7141 = cppVar_7154;
	}
	cppVar_7156 = (cppVar_7141 == 138);
	if (cppVar_7156) {
	cppVar_7140 = TL0;
	} else {
	cppVar_7159 = PC + 1;
	cppVar_7159 = (cppVar_7159 & cppMask_un_16_);
	cppVar_7160 = ROM.rd(cppVar_7159);
	cppVar_7161 = (cppVar_7160 >> 7) & cppMask_un_1_;
	cppVar_7162 = (cppVar_7161 == 1);
	if (cppVar_7162) {
	cppVar_7163 = PC + 1;
	cppVar_7163 = (cppVar_7163 & cppMask_un_16_);
	cppVar_7164 = ROM.rd(cppVar_7163);
	cppVar_7165 = (cppVar_7164 >> 3) & cppMask_un_5_;
	cppVar_7166 = (cppVar_7165 << 3) | 0;
	cppVar_7166 = (cppVar_7166 & cppMask_un_8_);
	cppVar_7158 = cppVar_7166;
	} else {
	cppVar_7167 = PC + 1;
	cppVar_7167 = (cppVar_7167 & cppMask_un_16_);
	cppVar_7168 = ROM.rd(cppVar_7167);
	cppVar_7169 = (cppVar_7168 >> 3) & cppMask_un_5_;
	cppVar_7170 = (cppVar_7169 & cppMask_un_5_);
	cppVar_7171 = cppVar_7170 + 32;
	cppVar_7171 = (cppVar_7171 & cppMask_un_8_);
	cppVar_7158 = cppVar_7171;
	}
	cppVar_7173 = (cppVar_7158 == 140);
	if (cppVar_7173) {
	cppVar_7157 = TH0;
	} else {
	cppVar_7176 = PC + 1;
	cppVar_7176 = (cppVar_7176 & cppMask_un_16_);
	cppVar_7177 = ROM.rd(cppVar_7176);
	cppVar_7178 = (cppVar_7177 >> 7) & cppMask_un_1_;
	cppVar_7179 = (cppVar_7178 == 1);
	if (cppVar_7179) {
	cppVar_7180 = PC + 1;
	cppVar_7180 = (cppVar_7180 & cppMask_un_16_);
	cppVar_7181 = ROM.rd(cppVar_7180);
	cppVar_7182 = (cppVar_7181 >> 3) & cppMask_un_5_;
	cppVar_7183 = (cppVar_7182 << 3) | 0;
	cppVar_7183 = (cppVar_7183 & cppMask_un_8_);
	cppVar_7175 = cppVar_7183;
	} else {
	cppVar_7184 = PC + 1;
	cppVar_7184 = (cppVar_7184 & cppMask_un_16_);
	cppVar_7185 = ROM.rd(cppVar_7184);
	cppVar_7186 = (cppVar_7185 >> 3) & cppMask_un_5_;
	cppVar_7187 = (cppVar_7186 & cppMask_un_5_);
	cppVar_7188 = cppVar_7187 + 32;
	cppVar_7188 = (cppVar_7188 & cppMask_un_8_);
	cppVar_7175 = cppVar_7188;
	}
	cppVar_7190 = (cppVar_7175 == 139);
	if (cppVar_7190) {
	cppVar_7174 = TL1;
	} else {
	cppVar_7193 = PC + 1;
	cppVar_7193 = (cppVar_7193 & cppMask_un_16_);
	cppVar_7194 = ROM.rd(cppVar_7193);
	cppVar_7195 = (cppVar_7194 >> 7) & cppMask_un_1_;
	cppVar_7196 = (cppVar_7195 == 1);
	if (cppVar_7196) {
	cppVar_7197 = PC + 1;
	cppVar_7197 = (cppVar_7197 & cppMask_un_16_);
	cppVar_7198 = ROM.rd(cppVar_7197);
	cppVar_7199 = (cppVar_7198 >> 3) & cppMask_un_5_;
	cppVar_7200 = (cppVar_7199 << 3) | 0;
	cppVar_7200 = (cppVar_7200 & cppMask_un_8_);
	cppVar_7192 = cppVar_7200;
	} else {
	cppVar_7201 = PC + 1;
	cppVar_7201 = (cppVar_7201 & cppMask_un_16_);
	cppVar_7202 = ROM.rd(cppVar_7201);
	cppVar_7203 = (cppVar_7202 >> 3) & cppMask_un_5_;
	cppVar_7204 = (cppVar_7203 & cppMask_un_5_);
	cppVar_7205 = cppVar_7204 + 32;
	cppVar_7205 = (cppVar_7205 & cppMask_un_8_);
	cppVar_7192 = cppVar_7205;
	}
	cppVar_7207 = (cppVar_7192 == 141);
	if (cppVar_7207) {
	cppVar_7191 = TH1;
	} else {
	cppVar_7210 = PC + 1;
	cppVar_7210 = (cppVar_7210 & cppMask_un_16_);
	cppVar_7211 = ROM.rd(cppVar_7210);
	cppVar_7212 = (cppVar_7211 >> 7) & cppMask_un_1_;
	cppVar_7213 = (cppVar_7212 == 1);
	if (cppVar_7213) {
	cppVar_7214 = PC + 1;
	cppVar_7214 = (cppVar_7214 & cppMask_un_16_);
	cppVar_7215 = ROM.rd(cppVar_7214);
	cppVar_7216 = (cppVar_7215 >> 3) & cppMask_un_5_;
	cppVar_7217 = (cppVar_7216 << 3) | 0;
	cppVar_7217 = (cppVar_7217 & cppMask_un_8_);
	cppVar_7209 = cppVar_7217;
	} else {
	cppVar_7218 = PC + 1;
	cppVar_7218 = (cppVar_7218 & cppMask_un_16_);
	cppVar_7219 = ROM.rd(cppVar_7218);
	cppVar_7220 = (cppVar_7219 >> 3) & cppMask_un_5_;
	cppVar_7221 = (cppVar_7220 & cppMask_un_5_);
	cppVar_7222 = cppVar_7221 + 32;
	cppVar_7222 = (cppVar_7222 & cppMask_un_8_);
	cppVar_7209 = cppVar_7222;
	}
	cppVar_7224 = (cppVar_7209 == 144);
	if (cppVar_7224) {
	cppVar_7208 = P1;
	} else {
	cppVar_7227 = PC + 1;
	cppVar_7227 = (cppVar_7227 & cppMask_un_16_);
	cppVar_7228 = ROM.rd(cppVar_7227);
	cppVar_7229 = (cppVar_7228 >> 7) & cppMask_un_1_;
	cppVar_7230 = (cppVar_7229 == 1);
	if (cppVar_7230) {
	cppVar_7231 = PC + 1;
	cppVar_7231 = (cppVar_7231 & cppMask_un_16_);
	cppVar_7232 = ROM.rd(cppVar_7231);
	cppVar_7233 = (cppVar_7232 >> 3) & cppMask_un_5_;
	cppVar_7234 = (cppVar_7233 << 3) | 0;
	cppVar_7234 = (cppVar_7234 & cppMask_un_8_);
	cppVar_7226 = cppVar_7234;
	} else {
	cppVar_7235 = PC + 1;
	cppVar_7235 = (cppVar_7235 & cppMask_un_16_);
	cppVar_7236 = ROM.rd(cppVar_7235);
	cppVar_7237 = (cppVar_7236 >> 3) & cppMask_un_5_;
	cppVar_7238 = (cppVar_7237 & cppMask_un_5_);
	cppVar_7239 = cppVar_7238 + 32;
	cppVar_7239 = (cppVar_7239 & cppMask_un_8_);
	cppVar_7226 = cppVar_7239;
	}
	cppVar_7241 = (cppVar_7226 == 152);
	if (cppVar_7241) {
	cppVar_7225 = SCON;
	} else {
	cppVar_7244 = PC + 1;
	cppVar_7244 = (cppVar_7244 & cppMask_un_16_);
	cppVar_7245 = ROM.rd(cppVar_7244);
	cppVar_7246 = (cppVar_7245 >> 7) & cppMask_un_1_;
	cppVar_7247 = (cppVar_7246 == 1);
	if (cppVar_7247) {
	cppVar_7248 = PC + 1;
	cppVar_7248 = (cppVar_7248 & cppMask_un_16_);
	cppVar_7249 = ROM.rd(cppVar_7248);
	cppVar_7250 = (cppVar_7249 >> 3) & cppMask_un_5_;
	cppVar_7251 = (cppVar_7250 << 3) | 0;
	cppVar_7251 = (cppVar_7251 & cppMask_un_8_);
	cppVar_7243 = cppVar_7251;
	} else {
	cppVar_7252 = PC + 1;
	cppVar_7252 = (cppVar_7252 & cppMask_un_16_);
	cppVar_7253 = ROM.rd(cppVar_7252);
	cppVar_7254 = (cppVar_7253 >> 3) & cppMask_un_5_;
	cppVar_7255 = (cppVar_7254 & cppMask_un_5_);
	cppVar_7256 = cppVar_7255 + 32;
	cppVar_7256 = (cppVar_7256 & cppMask_un_8_);
	cppVar_7243 = cppVar_7256;
	}
	cppVar_7258 = (cppVar_7243 == 153);
	if (cppVar_7258) {
	cppVar_7242 = SBUF;
	} else {
	cppVar_7261 = PC + 1;
	cppVar_7261 = (cppVar_7261 & cppMask_un_16_);
	cppVar_7262 = ROM.rd(cppVar_7261);
	cppVar_7263 = (cppVar_7262 >> 7) & cppMask_un_1_;
	cppVar_7264 = (cppVar_7263 == 1);
	if (cppVar_7264) {
	cppVar_7265 = PC + 1;
	cppVar_7265 = (cppVar_7265 & cppMask_un_16_);
	cppVar_7266 = ROM.rd(cppVar_7265);
	cppVar_7267 = (cppVar_7266 >> 3) & cppMask_un_5_;
	cppVar_7268 = (cppVar_7267 << 3) | 0;
	cppVar_7268 = (cppVar_7268 & cppMask_un_8_);
	cppVar_7260 = cppVar_7268;
	} else {
	cppVar_7269 = PC + 1;
	cppVar_7269 = (cppVar_7269 & cppMask_un_16_);
	cppVar_7270 = ROM.rd(cppVar_7269);
	cppVar_7271 = (cppVar_7270 >> 3) & cppMask_un_5_;
	cppVar_7272 = (cppVar_7271 & cppMask_un_5_);
	cppVar_7273 = cppVar_7272 + 32;
	cppVar_7273 = (cppVar_7273 & cppMask_un_8_);
	cppVar_7260 = cppVar_7273;
	}
	cppVar_7275 = (cppVar_7260 == 160);
	if (cppVar_7275) {
	cppVar_7259 = P2;
	} else {
	cppVar_7278 = PC + 1;
	cppVar_7278 = (cppVar_7278 & cppMask_un_16_);
	cppVar_7279 = ROM.rd(cppVar_7278);
	cppVar_7280 = (cppVar_7279 >> 7) & cppMask_un_1_;
	cppVar_7281 = (cppVar_7280 == 1);
	if (cppVar_7281) {
	cppVar_7282 = PC + 1;
	cppVar_7282 = (cppVar_7282 & cppMask_un_16_);
	cppVar_7283 = ROM.rd(cppVar_7282);
	cppVar_7284 = (cppVar_7283 >> 3) & cppMask_un_5_;
	cppVar_7285 = (cppVar_7284 << 3) | 0;
	cppVar_7285 = (cppVar_7285 & cppMask_un_8_);
	cppVar_7277 = cppVar_7285;
	} else {
	cppVar_7286 = PC + 1;
	cppVar_7286 = (cppVar_7286 & cppMask_un_16_);
	cppVar_7287 = ROM.rd(cppVar_7286);
	cppVar_7288 = (cppVar_7287 >> 3) & cppMask_un_5_;
	cppVar_7289 = (cppVar_7288 & cppMask_un_5_);
	cppVar_7290 = cppVar_7289 + 32;
	cppVar_7290 = (cppVar_7290 & cppMask_un_8_);
	cppVar_7277 = cppVar_7290;
	}
	cppVar_7292 = (cppVar_7277 == 168);
	if (cppVar_7292) {
	cppVar_7276 = IE;
	} else {
	cppVar_7295 = PC + 1;
	cppVar_7295 = (cppVar_7295 & cppMask_un_16_);
	cppVar_7296 = ROM.rd(cppVar_7295);
	cppVar_7297 = (cppVar_7296 >> 7) & cppMask_un_1_;
	cppVar_7298 = (cppVar_7297 == 1);
	if (cppVar_7298) {
	cppVar_7299 = PC + 1;
	cppVar_7299 = (cppVar_7299 & cppMask_un_16_);
	cppVar_7300 = ROM.rd(cppVar_7299);
	cppVar_7301 = (cppVar_7300 >> 3) & cppMask_un_5_;
	cppVar_7302 = (cppVar_7301 << 3) | 0;
	cppVar_7302 = (cppVar_7302 & cppMask_un_8_);
	cppVar_7294 = cppVar_7302;
	} else {
	cppVar_7303 = PC + 1;
	cppVar_7303 = (cppVar_7303 & cppMask_un_16_);
	cppVar_7304 = ROM.rd(cppVar_7303);
	cppVar_7305 = (cppVar_7304 >> 3) & cppMask_un_5_;
	cppVar_7306 = (cppVar_7305 & cppMask_un_5_);
	cppVar_7307 = cppVar_7306 + 32;
	cppVar_7307 = (cppVar_7307 & cppMask_un_8_);
	cppVar_7294 = cppVar_7307;
	}
	cppVar_7309 = (cppVar_7294 == 176);
	if (cppVar_7309) {
	cppVar_7293 = P3;
	} else {
	cppVar_7312 = PC + 1;
	cppVar_7312 = (cppVar_7312 & cppMask_un_16_);
	cppVar_7313 = ROM.rd(cppVar_7312);
	cppVar_7314 = (cppVar_7313 >> 7) & cppMask_un_1_;
	cppVar_7315 = (cppVar_7314 == 1);
	if (cppVar_7315) {
	cppVar_7316 = PC + 1;
	cppVar_7316 = (cppVar_7316 & cppMask_un_16_);
	cppVar_7317 = ROM.rd(cppVar_7316);
	cppVar_7318 = (cppVar_7317 >> 3) & cppMask_un_5_;
	cppVar_7319 = (cppVar_7318 << 3) | 0;
	cppVar_7319 = (cppVar_7319 & cppMask_un_8_);
	cppVar_7311 = cppVar_7319;
	} else {
	cppVar_7320 = PC + 1;
	cppVar_7320 = (cppVar_7320 & cppMask_un_16_);
	cppVar_7321 = ROM.rd(cppVar_7320);
	cppVar_7322 = (cppVar_7321 >> 3) & cppMask_un_5_;
	cppVar_7323 = (cppVar_7322 & cppMask_un_5_);
	cppVar_7324 = cppVar_7323 + 32;
	cppVar_7324 = (cppVar_7324 & cppMask_un_8_);
	cppVar_7311 = cppVar_7324;
	}
	cppVar_7326 = (cppVar_7311 == 184);
	if (cppVar_7326) {
	cppVar_7310 = IP;
	} else {
	cppVar_7329 = PC + 1;
	cppVar_7329 = (cppVar_7329 & cppMask_un_16_);
	cppVar_7330 = ROM.rd(cppVar_7329);
	cppVar_7331 = (cppVar_7330 >> 7) & cppMask_un_1_;
	cppVar_7332 = (cppVar_7331 == 1);
	if (cppVar_7332) {
	cppVar_7333 = PC + 1;
	cppVar_7333 = (cppVar_7333 & cppMask_un_16_);
	cppVar_7334 = ROM.rd(cppVar_7333);
	cppVar_7335 = (cppVar_7334 >> 3) & cppMask_un_5_;
	cppVar_7336 = (cppVar_7335 << 3) | 0;
	cppVar_7336 = (cppVar_7336 & cppMask_un_8_);
	cppVar_7328 = cppVar_7336;
	} else {
	cppVar_7337 = PC + 1;
	cppVar_7337 = (cppVar_7337 & cppMask_un_16_);
	cppVar_7338 = ROM.rd(cppVar_7337);
	cppVar_7339 = (cppVar_7338 >> 3) & cppMask_un_5_;
	cppVar_7340 = (cppVar_7339 & cppMask_un_5_);
	cppVar_7341 = cppVar_7340 + 32;
	cppVar_7341 = (cppVar_7341 & cppMask_un_8_);
	cppVar_7328 = cppVar_7341;
	}
	cppVar_7343 = (cppVar_7328 == 208);
	if (cppVar_7343) {
	cppVar_7327 = PSW;
	} else {
	cppVar_7346 = PC + 1;
	cppVar_7346 = (cppVar_7346 & cppMask_un_16_);
	cppVar_7347 = ROM.rd(cppVar_7346);
	cppVar_7348 = (cppVar_7347 >> 7) & cppMask_un_1_;
	cppVar_7349 = (cppVar_7348 == 1);
	if (cppVar_7349) {
	cppVar_7350 = PC + 1;
	cppVar_7350 = (cppVar_7350 & cppMask_un_16_);
	cppVar_7351 = ROM.rd(cppVar_7350);
	cppVar_7352 = (cppVar_7351 >> 3) & cppMask_un_5_;
	cppVar_7353 = (cppVar_7352 << 3) | 0;
	cppVar_7353 = (cppVar_7353 & cppMask_un_8_);
	cppVar_7345 = cppVar_7353;
	} else {
	cppVar_7354 = PC + 1;
	cppVar_7354 = (cppVar_7354 & cppMask_un_16_);
	cppVar_7355 = ROM.rd(cppVar_7354);
	cppVar_7356 = (cppVar_7355 >> 3) & cppMask_un_5_;
	cppVar_7357 = (cppVar_7356 & cppMask_un_5_);
	cppVar_7358 = cppVar_7357 + 32;
	cppVar_7358 = (cppVar_7358 & cppMask_un_8_);
	cppVar_7345 = cppVar_7358;
	}
	cppVar_7360 = (cppVar_7345 == 224);
	if (cppVar_7360) {
	cppVar_7344 = ACC;
	} else {
	cppVar_7363 = PC + 1;
	cppVar_7363 = (cppVar_7363 & cppMask_un_16_);
	cppVar_7364 = ROM.rd(cppVar_7363);
	cppVar_7365 = (cppVar_7364 >> 7) & cppMask_un_1_;
	cppVar_7366 = (cppVar_7365 == 1);
	if (cppVar_7366) {
	cppVar_7367 = PC + 1;
	cppVar_7367 = (cppVar_7367 & cppMask_un_16_);
	cppVar_7368 = ROM.rd(cppVar_7367);
	cppVar_7369 = (cppVar_7368 >> 3) & cppMask_un_5_;
	cppVar_7370 = (cppVar_7369 << 3) | 0;
	cppVar_7370 = (cppVar_7370 & cppMask_un_8_);
	cppVar_7362 = cppVar_7370;
	} else {
	cppVar_7371 = PC + 1;
	cppVar_7371 = (cppVar_7371 & cppMask_un_16_);
	cppVar_7372 = ROM.rd(cppVar_7371);
	cppVar_7373 = (cppVar_7372 >> 3) & cppMask_un_5_;
	cppVar_7374 = (cppVar_7373 & cppMask_un_5_);
	cppVar_7375 = cppVar_7374 + 32;
	cppVar_7375 = (cppVar_7375 & cppMask_un_8_);
	cppVar_7362 = cppVar_7375;
	}
	cppVar_7377 = (cppVar_7362 == 240);
	if (cppVar_7377) {
	cppVar_7361 = B;
	} else {
	cppVar_7361 = 0;
	}
	cppVar_7344 = cppVar_7361;
	}
	cppVar_7327 = cppVar_7344;
	}
	cppVar_7310 = cppVar_7327;
	}
	cppVar_7293 = cppVar_7310;
	}
	cppVar_7276 = cppVar_7293;
	}
	cppVar_7259 = cppVar_7276;
	}
	cppVar_7242 = cppVar_7259;
	}
	cppVar_7225 = cppVar_7242;
	}
	cppVar_7208 = cppVar_7225;
	}
	cppVar_7191 = cppVar_7208;
	}
	cppVar_7174 = cppVar_7191;
	}
	cppVar_7157 = cppVar_7174;
	}
	cppVar_7140 = cppVar_7157;
	}
	cppVar_7123 = cppVar_7140;
	}
	cppVar_7106 = cppVar_7123;
	}
	cppVar_7089 = cppVar_7106;
	}
	cppVar_7072 = cppVar_7089;
	}
	cppVar_7055 = cppVar_7072;
	}
	cppVar_7038 = cppVar_7055;
	}
	cppVar_7021 = cppVar_7038;
	}
	cppVar_6988 = cppVar_7021;
	}
	cppVar_7379 = cppVar_6987 & cppVar_6988;
	cppVar_7381 = 0;
	cppVar_7382 = PC + 1;
	cppVar_7382 = (cppVar_7382 & cppMask_un_16_);
	cppVar_7383 = ROM.rd(cppVar_7382);
	cppVar_7384 = (cppVar_7383 >> 0) & cppMask_un_3_;
	cppVar_7385 = (cppVar_7384 & cppMask_un_3_);
	cppVar_7386 = cppVar_7381 << static_cast<unsigned>(cppVar_7385);
	cppVar_7386 = (cppVar_7386 & cppMask_un_8_);
	cppVar_7387 = cppVar_7379 | cppVar_7386;
	cppVar_6960 = cppVar_7387;
	} else {
	cppVar_6960 = B;
	}
	cppVar_6952 = cppVar_6960;
	} else {
	cppVar_7389 = ROM.rd(PC);
	cppVar_7391 = (cppVar_7389 == 5);
	if (cppVar_7391) {
	cppVar_7394 = PC + 1;
	cppVar_7394 = (cppVar_7394 & cppMask_un_16_);
	cppVar_7395 = ROM.rd(cppVar_7394);
	cppVar_7397 = (cppVar_7395 == 240);
	if (cppVar_7397) {
	cppVar_7399 = PC + 1;
	cppVar_7399 = (cppVar_7399 & cppMask_un_16_);
	cppVar_7400 = ROM.rd(cppVar_7399);
	cppVar_7401 = (cppVar_7400 >> 7) & cppMask_un_1_;
	cppVar_7403 = (cppVar_7401 == 0);
	if (cppVar_7403) {
	cppVar_7404 = PC + 1;
	cppVar_7404 = (cppVar_7404 & cppMask_un_16_);
	cppVar_7405 = ROM.rd(cppVar_7404);
	cppVar_7406 = IRAM.rd(cppVar_7405);
	cppVar_7398 = cppVar_7406;
	} else {
	cppVar_7408 = PC + 1;
	cppVar_7408 = (cppVar_7408 & cppMask_un_16_);
	cppVar_7409 = ROM.rd(cppVar_7408);
	cppVar_7411 = (cppVar_7409 == 128);
	if (cppVar_7411) {
	cppVar_7407 = P0;
	} else {
	cppVar_7413 = PC + 1;
	cppVar_7413 = (cppVar_7413 & cppMask_un_16_);
	cppVar_7414 = ROM.rd(cppVar_7413);
	cppVar_7416 = (cppVar_7414 == 129);
	if (cppVar_7416) {
	cppVar_7412 = SP;
	} else {
	cppVar_7418 = PC + 1;
	cppVar_7418 = (cppVar_7418 & cppMask_un_16_);
	cppVar_7419 = ROM.rd(cppVar_7418);
	cppVar_7421 = (cppVar_7419 == 130);
	if (cppVar_7421) {
	cppVar_7417 = DPL;
	} else {
	cppVar_7423 = PC + 1;
	cppVar_7423 = (cppVar_7423 & cppMask_un_16_);
	cppVar_7424 = ROM.rd(cppVar_7423);
	cppVar_7426 = (cppVar_7424 == 131);
	if (cppVar_7426) {
	cppVar_7422 = DPH;
	} else {
	cppVar_7428 = PC + 1;
	cppVar_7428 = (cppVar_7428 & cppMask_un_16_);
	cppVar_7429 = ROM.rd(cppVar_7428);
	cppVar_7431 = (cppVar_7429 == 135);
	if (cppVar_7431) {
	cppVar_7427 = PCON;
	} else {
	cppVar_7433 = PC + 1;
	cppVar_7433 = (cppVar_7433 & cppMask_un_16_);
	cppVar_7434 = ROM.rd(cppVar_7433);
	cppVar_7436 = (cppVar_7434 == 136);
	if (cppVar_7436) {
	cppVar_7432 = TCON;
	} else {
	cppVar_7438 = PC + 1;
	cppVar_7438 = (cppVar_7438 & cppMask_un_16_);
	cppVar_7439 = ROM.rd(cppVar_7438);
	cppVar_7441 = (cppVar_7439 == 137);
	if (cppVar_7441) {
	cppVar_7437 = TMOD;
	} else {
	cppVar_7443 = PC + 1;
	cppVar_7443 = (cppVar_7443 & cppMask_un_16_);
	cppVar_7444 = ROM.rd(cppVar_7443);
	cppVar_7446 = (cppVar_7444 == 138);
	if (cppVar_7446) {
	cppVar_7442 = TL0;
	} else {
	cppVar_7448 = PC + 1;
	cppVar_7448 = (cppVar_7448 & cppMask_un_16_);
	cppVar_7449 = ROM.rd(cppVar_7448);
	cppVar_7451 = (cppVar_7449 == 140);
	if (cppVar_7451) {
	cppVar_7447 = TH0;
	} else {
	cppVar_7453 = PC + 1;
	cppVar_7453 = (cppVar_7453 & cppMask_un_16_);
	cppVar_7454 = ROM.rd(cppVar_7453);
	cppVar_7456 = (cppVar_7454 == 139);
	if (cppVar_7456) {
	cppVar_7452 = TL1;
	} else {
	cppVar_7458 = PC + 1;
	cppVar_7458 = (cppVar_7458 & cppMask_un_16_);
	cppVar_7459 = ROM.rd(cppVar_7458);
	cppVar_7461 = (cppVar_7459 == 141);
	if (cppVar_7461) {
	cppVar_7457 = TH1;
	} else {
	cppVar_7463 = PC + 1;
	cppVar_7463 = (cppVar_7463 & cppMask_un_16_);
	cppVar_7464 = ROM.rd(cppVar_7463);
	cppVar_7466 = (cppVar_7464 == 144);
	if (cppVar_7466) {
	cppVar_7462 = P1;
	} else {
	cppVar_7468 = PC + 1;
	cppVar_7468 = (cppVar_7468 & cppMask_un_16_);
	cppVar_7469 = ROM.rd(cppVar_7468);
	cppVar_7471 = (cppVar_7469 == 152);
	if (cppVar_7471) {
	cppVar_7467 = SCON;
	} else {
	cppVar_7473 = PC + 1;
	cppVar_7473 = (cppVar_7473 & cppMask_un_16_);
	cppVar_7474 = ROM.rd(cppVar_7473);
	cppVar_7476 = (cppVar_7474 == 153);
	if (cppVar_7476) {
	cppVar_7472 = SBUF;
	} else {
	cppVar_7478 = PC + 1;
	cppVar_7478 = (cppVar_7478 & cppMask_un_16_);
	cppVar_7479 = ROM.rd(cppVar_7478);
	cppVar_7481 = (cppVar_7479 == 160);
	if (cppVar_7481) {
	cppVar_7477 = P2;
	} else {
	cppVar_7483 = PC + 1;
	cppVar_7483 = (cppVar_7483 & cppMask_un_16_);
	cppVar_7484 = ROM.rd(cppVar_7483);
	cppVar_7486 = (cppVar_7484 == 168);
	if (cppVar_7486) {
	cppVar_7482 = IE;
	} else {
	cppVar_7488 = PC + 1;
	cppVar_7488 = (cppVar_7488 & cppMask_un_16_);
	cppVar_7489 = ROM.rd(cppVar_7488);
	cppVar_7491 = (cppVar_7489 == 176);
	if (cppVar_7491) {
	cppVar_7487 = P3;
	} else {
	cppVar_7493 = PC + 1;
	cppVar_7493 = (cppVar_7493 & cppMask_un_16_);
	cppVar_7494 = ROM.rd(cppVar_7493);
	cppVar_7496 = (cppVar_7494 == 184);
	if (cppVar_7496) {
	cppVar_7492 = IP;
	} else {
	cppVar_7498 = PC + 1;
	cppVar_7498 = (cppVar_7498 & cppMask_un_16_);
	cppVar_7499 = ROM.rd(cppVar_7498);
	cppVar_7501 = (cppVar_7499 == 208);
	if (cppVar_7501) {
	cppVar_7497 = PSW;
	} else {
	cppVar_7503 = PC + 1;
	cppVar_7503 = (cppVar_7503 & cppMask_un_16_);
	cppVar_7504 = ROM.rd(cppVar_7503);
	cppVar_7506 = (cppVar_7504 == 224);
	if (cppVar_7506) {
	cppVar_7502 = ACC;
	} else {
	cppVar_7508 = PC + 1;
	cppVar_7508 = (cppVar_7508 & cppMask_un_16_);
	cppVar_7509 = ROM.rd(cppVar_7508);
	cppVar_7511 = (cppVar_7509 == 240);
	if (cppVar_7511) {
	cppVar_7507 = B;
	} else {
	cppVar_7507 = 0;
	}
	cppVar_7502 = cppVar_7507;
	}
	cppVar_7497 = cppVar_7502;
	}
	cppVar_7492 = cppVar_7497;
	}
	cppVar_7487 = cppVar_7492;
	}
	cppVar_7482 = cppVar_7487;
	}
	cppVar_7477 = cppVar_7482;
	}
	cppVar_7472 = cppVar_7477;
	}
	cppVar_7467 = cppVar_7472;
	}
	cppVar_7462 = cppVar_7467;
	}
	cppVar_7457 = cppVar_7462;
	}
	cppVar_7452 = cppVar_7457;
	}
	cppVar_7447 = cppVar_7452;
	}
	cppVar_7442 = cppVar_7447;
	}
	cppVar_7437 = cppVar_7442;
	}
	cppVar_7432 = cppVar_7437;
	}
	cppVar_7427 = cppVar_7432;
	}
	cppVar_7422 = cppVar_7427;
	}
	cppVar_7417 = cppVar_7422;
	}
	cppVar_7412 = cppVar_7417;
	}
	cppVar_7407 = cppVar_7412;
	}
	cppVar_7398 = cppVar_7407;
	}
	cppVar_7514 = cppVar_7398 + 1;
	cppVar_7514 = (cppVar_7514 & cppMask_un_8_);
	cppVar_7392 = cppVar_7514;
	} else {
	cppVar_7392 = B;
	}
	cppVar_7388 = cppVar_7392;
	} else {
	cppVar_7388 = B;
	}
	cppVar_6952 = cppVar_7388;
	}
	cppVar_6821 = cppVar_6952;
	}
	cppVar_6695 = cppVar_6821;
	}
	cppVar_6566 = cppVar_6695;
	}
	cppVar_6440 = cppVar_6566;
	}
	cppVar_6311 = cppVar_6440;
	}
	cppVar_6185 = cppVar_6311;
	}
	cppVar_6056 = cppVar_6185;
	}
	cppVar_6043 = cppVar_6056;
	}
	cppVar_6035 = cppVar_6043;
	}
	cppVar_5909 = cppVar_6035;
	}
	cppVar_5892 = cppVar_5909;
	}
	cppVar_5875 = cppVar_5892;
	}
	cppVar_5725 = cppVar_5875;
	}
	cppVar_5575 = cppVar_5725;
	}
	cppVar_5425 = cppVar_5575;
	}
	cppVar_5275 = cppVar_5425;
	}
	cppVar_5125 = cppVar_5275;
	}
	cppVar_4975 = cppVar_5125;
	}
	cppVar_4825 = cppVar_4975;
	}
	cppVar_4675 = cppVar_4825;
	}
	cppVar_4243 = cppVar_4675;
	}
	cppVar_4235 = cppVar_4243;
	}
	cppVar_3405 = cppVar_4235;
	}
	cppVar_3391 = cppVar_3405;
	}
	cppVar_3380 = cppVar_3391;
	}
	cppVar_2948 = cppVar_3380;
	}
	return cppVar_2948;
}
