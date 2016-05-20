#include "common.hpp"
#include "model_aes_class.hpp"

type_mem model_aes::cppUpdateFun_XRAM(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	type_mem cppVar_3856;
	bool cppVar_3858 = (aes_state != 0);
	if (cppVar_3858) {
	type_mem cppVar_3859;
	bool cppVar_3861 = (aes_state == 3);
	bool cppVar_3863 = (byte_cnt == 15);
	bool cppVar_3864 = cppVar_3861 && cppVar_3863;
	if (cppVar_3864) {
	BIT_VEC cppVar_3865 = aes_addr + blk_cnt;
	cppVar_3865 = (cppVar_3865 & cppMask_un_16_);
	BIT_VEC cppVar_3866 = (byte_cnt & cppMask_un_4_);
	BIT_VEC cppVar_3867 = cppVar_3865 + cppVar_3866;
	cppVar_3867 = (cppVar_3867 & cppMask_un_16_);
	BIT_VEC cppVar_3868 = (enc_data >> 120) & cppMask_un_8_;
	type_mem cppVar_3869 = XRAM;
	cppVar_3869.wr(cppVar_3867, cppVar_3868);
	cppVar_3859 = cppVar_3869;
	} else {
	type_mem cppVar_3870;
	bool cppVar_3872 = (aes_state == 3);
	bool cppVar_3874 = (byte_cnt == 14);
	bool cppVar_3875 = cppVar_3872 && cppVar_3874;
	if (cppVar_3875) {
	BIT_VEC cppVar_3876 = aes_addr + blk_cnt;
	cppVar_3876 = (cppVar_3876 & cppMask_un_16_);
	BIT_VEC cppVar_3877 = (byte_cnt & cppMask_un_4_);
	BIT_VEC cppVar_3878 = cppVar_3876 + cppVar_3877;
	cppVar_3878 = (cppVar_3878 & cppMask_un_16_);
	BIT_VEC cppVar_3879 = (enc_data >> 112) & cppMask_un_8_;
	type_mem cppVar_3880 = XRAM;
	cppVar_3880.wr(cppVar_3878, cppVar_3879);
	cppVar_3870 = cppVar_3880;
	} else {
	type_mem cppVar_3881;
	bool cppVar_3883 = (aes_state == 3);
	bool cppVar_3885 = (byte_cnt == 13);
	bool cppVar_3886 = cppVar_3883 && cppVar_3885;
	if (cppVar_3886) {
	BIT_VEC cppVar_3887 = aes_addr + blk_cnt;
	cppVar_3887 = (cppVar_3887 & cppMask_un_16_);
	BIT_VEC cppVar_3888 = (byte_cnt & cppMask_un_4_);
	BIT_VEC cppVar_3889 = cppVar_3887 + cppVar_3888;
	cppVar_3889 = (cppVar_3889 & cppMask_un_16_);
	BIT_VEC cppVar_3890 = (enc_data >> 104) & cppMask_un_8_;
	type_mem cppVar_3891 = XRAM;
	cppVar_3891.wr(cppVar_3889, cppVar_3890);
	cppVar_3881 = cppVar_3891;
	} else {
	type_mem cppVar_3892;
	bool cppVar_3894 = (aes_state == 3);
	bool cppVar_3896 = (byte_cnt == 12);
	bool cppVar_3897 = cppVar_3894 && cppVar_3896;
	if (cppVar_3897) {
	BIT_VEC cppVar_3898 = aes_addr + blk_cnt;
	cppVar_3898 = (cppVar_3898 & cppMask_un_16_);
	BIT_VEC cppVar_3899 = (byte_cnt & cppMask_un_4_);
	BIT_VEC cppVar_3900 = cppVar_3898 + cppVar_3899;
	cppVar_3900 = (cppVar_3900 & cppMask_un_16_);
	BIT_VEC cppVar_3901 = (enc_data >> 96) & cppMask_un_8_;
	type_mem cppVar_3902 = XRAM;
	cppVar_3902.wr(cppVar_3900, cppVar_3901);
	cppVar_3892 = cppVar_3902;
	} else {
	type_mem cppVar_3903;
	bool cppVar_3905 = (aes_state == 3);
	bool cppVar_3907 = (byte_cnt == 11);
	bool cppVar_3908 = cppVar_3905 && cppVar_3907;
	if (cppVar_3908) {
	BIT_VEC cppVar_3909 = aes_addr + blk_cnt;
	cppVar_3909 = (cppVar_3909 & cppMask_un_16_);
	BIT_VEC cppVar_3910 = (byte_cnt & cppMask_un_4_);
	BIT_VEC cppVar_3911 = cppVar_3909 + cppVar_3910;
	cppVar_3911 = (cppVar_3911 & cppMask_un_16_);
	BIT_VEC cppVar_3912 = (enc_data >> 88) & cppMask_un_8_;
	type_mem cppVar_3913 = XRAM;
	cppVar_3913.wr(cppVar_3911, cppVar_3912);
	cppVar_3903 = cppVar_3913;
	} else {
	type_mem cppVar_3914;
	bool cppVar_3916 = (aes_state == 3);
	bool cppVar_3918 = (byte_cnt == 10);
	bool cppVar_3919 = cppVar_3916 && cppVar_3918;
	if (cppVar_3919) {
	BIT_VEC cppVar_3920 = aes_addr + blk_cnt;
	cppVar_3920 = (cppVar_3920 & cppMask_un_16_);
	BIT_VEC cppVar_3921 = (byte_cnt & cppMask_un_4_);
	BIT_VEC cppVar_3922 = cppVar_3920 + cppVar_3921;
	cppVar_3922 = (cppVar_3922 & cppMask_un_16_);
	BIT_VEC cppVar_3923 = (enc_data >> 80) & cppMask_un_8_;
	type_mem cppVar_3924 = XRAM;
	cppVar_3924.wr(cppVar_3922, cppVar_3923);
	cppVar_3914 = cppVar_3924;
	} else {
	type_mem cppVar_3925;
	bool cppVar_3927 = (aes_state == 3);
	bool cppVar_3929 = (byte_cnt == 9);
	bool cppVar_3930 = cppVar_3927 && cppVar_3929;
	if (cppVar_3930) {
	BIT_VEC cppVar_3931 = aes_addr + blk_cnt;
	cppVar_3931 = (cppVar_3931 & cppMask_un_16_);
	BIT_VEC cppVar_3932 = (byte_cnt & cppMask_un_4_);
	BIT_VEC cppVar_3933 = cppVar_3931 + cppVar_3932;
	cppVar_3933 = (cppVar_3933 & cppMask_un_16_);
	BIT_VEC cppVar_3934 = (enc_data >> 72) & cppMask_un_8_;
	type_mem cppVar_3935 = XRAM;
	cppVar_3935.wr(cppVar_3933, cppVar_3934);
	cppVar_3925 = cppVar_3935;
	} else {
	type_mem cppVar_3936;
	bool cppVar_3938 = (aes_state == 3);
	bool cppVar_3940 = (byte_cnt == 8);
	bool cppVar_3941 = cppVar_3938 && cppVar_3940;
	if (cppVar_3941) {
	BIT_VEC cppVar_3942 = aes_addr + blk_cnt;
	cppVar_3942 = (cppVar_3942 & cppMask_un_16_);
	BIT_VEC cppVar_3943 = (byte_cnt & cppMask_un_4_);
	BIT_VEC cppVar_3944 = cppVar_3942 + cppVar_3943;
	cppVar_3944 = (cppVar_3944 & cppMask_un_16_);
	BIT_VEC cppVar_3945 = (enc_data >> 64) & cppMask_un_8_;
	type_mem cppVar_3946 = XRAM;
	cppVar_3946.wr(cppVar_3944, cppVar_3945);
	cppVar_3936 = cppVar_3946;
	} else {
	type_mem cppVar_3947;
	bool cppVar_3949 = (aes_state == 3);
	bool cppVar_3951 = (byte_cnt == 7);
	bool cppVar_3952 = cppVar_3949 && cppVar_3951;
	if (cppVar_3952) {
	BIT_VEC cppVar_3953 = aes_addr + blk_cnt;
	cppVar_3953 = (cppVar_3953 & cppMask_un_16_);
	BIT_VEC cppVar_3954 = (byte_cnt & cppMask_un_4_);
	BIT_VEC cppVar_3955 = cppVar_3953 + cppVar_3954;
	cppVar_3955 = (cppVar_3955 & cppMask_un_16_);
	BIT_VEC cppVar_3956 = (enc_data >> 56) & cppMask_un_8_;
	type_mem cppVar_3957 = XRAM;
	cppVar_3957.wr(cppVar_3955, cppVar_3956);
	cppVar_3947 = cppVar_3957;
	} else {
	type_mem cppVar_3958;
	bool cppVar_3960 = (aes_state == 3);
	bool cppVar_3962 = (byte_cnt == 6);
	bool cppVar_3963 = cppVar_3960 && cppVar_3962;
	if (cppVar_3963) {
	BIT_VEC cppVar_3964 = aes_addr + blk_cnt;
	cppVar_3964 = (cppVar_3964 & cppMask_un_16_);
	BIT_VEC cppVar_3965 = (byte_cnt & cppMask_un_4_);
	BIT_VEC cppVar_3966 = cppVar_3964 + cppVar_3965;
	cppVar_3966 = (cppVar_3966 & cppMask_un_16_);
	BIT_VEC cppVar_3967 = (enc_data >> 48) & cppMask_un_8_;
	type_mem cppVar_3968 = XRAM;
	cppVar_3968.wr(cppVar_3966, cppVar_3967);
	cppVar_3958 = cppVar_3968;
	} else {
	type_mem cppVar_3969;
	bool cppVar_3971 = (aes_state == 3);
	bool cppVar_3973 = (byte_cnt == 5);
	bool cppVar_3974 = cppVar_3971 && cppVar_3973;
	if (cppVar_3974) {
	BIT_VEC cppVar_3975 = aes_addr + blk_cnt;
	cppVar_3975 = (cppVar_3975 & cppMask_un_16_);
	BIT_VEC cppVar_3976 = (byte_cnt & cppMask_un_4_);
	BIT_VEC cppVar_3977 = cppVar_3975 + cppVar_3976;
	cppVar_3977 = (cppVar_3977 & cppMask_un_16_);
	BIT_VEC cppVar_3978 = (enc_data >> 40) & cppMask_un_8_;
	type_mem cppVar_3979 = XRAM;
	cppVar_3979.wr(cppVar_3977, cppVar_3978);
	cppVar_3969 = cppVar_3979;
	} else {
	type_mem cppVar_3980;
	bool cppVar_3982 = (aes_state == 3);
	bool cppVar_3984 = (byte_cnt == 4);
	bool cppVar_3985 = cppVar_3982 && cppVar_3984;
	if (cppVar_3985) {
	BIT_VEC cppVar_3986 = aes_addr + blk_cnt;
	cppVar_3986 = (cppVar_3986 & cppMask_un_16_);
	BIT_VEC cppVar_3987 = (byte_cnt & cppMask_un_4_);
	BIT_VEC cppVar_3988 = cppVar_3986 + cppVar_3987;
	cppVar_3988 = (cppVar_3988 & cppMask_un_16_);
	BIT_VEC cppVar_3989 = (enc_data >> 32) & cppMask_un_8_;
	type_mem cppVar_3990 = XRAM;
	cppVar_3990.wr(cppVar_3988, cppVar_3989);
	cppVar_3980 = cppVar_3990;
	} else {
	type_mem cppVar_3991;
	bool cppVar_3993 = (aes_state == 3);
	bool cppVar_3995 = (byte_cnt == 3);
	bool cppVar_3996 = cppVar_3993 && cppVar_3995;
	if (cppVar_3996) {
	BIT_VEC cppVar_3997 = aes_addr + blk_cnt;
	cppVar_3997 = (cppVar_3997 & cppMask_un_16_);
	BIT_VEC cppVar_3998 = (byte_cnt & cppMask_un_4_);
	BIT_VEC cppVar_3999 = cppVar_3997 + cppVar_3998;
	cppVar_3999 = (cppVar_3999 & cppMask_un_16_);
	BIT_VEC cppVar_4000 = (enc_data >> 24) & cppMask_un_8_;
	type_mem cppVar_4001 = XRAM;
	cppVar_4001.wr(cppVar_3999, cppVar_4000);
	cppVar_3991 = cppVar_4001;
	} else {
	type_mem cppVar_4002;
	bool cppVar_4004 = (aes_state == 3);
	bool cppVar_4006 = (byte_cnt == 2);
	bool cppVar_4007 = cppVar_4004 && cppVar_4006;
	if (cppVar_4007) {
	BIT_VEC cppVar_4008 = aes_addr + blk_cnt;
	cppVar_4008 = (cppVar_4008 & cppMask_un_16_);
	BIT_VEC cppVar_4009 = (byte_cnt & cppMask_un_4_);
	BIT_VEC cppVar_4010 = cppVar_4008 + cppVar_4009;
	cppVar_4010 = (cppVar_4010 & cppMask_un_16_);
	BIT_VEC cppVar_4011 = (enc_data >> 16) & cppMask_un_8_;
	type_mem cppVar_4012 = XRAM;
	cppVar_4012.wr(cppVar_4010, cppVar_4011);
	cppVar_4002 = cppVar_4012;
	} else {
	type_mem cppVar_4013;
	bool cppVar_4015 = (aes_state == 3);
	bool cppVar_4017 = (byte_cnt == 1);
	bool cppVar_4018 = cppVar_4015 && cppVar_4017;
	if (cppVar_4018) {
	BIT_VEC cppVar_4019 = aes_addr + blk_cnt;
	cppVar_4019 = (cppVar_4019 & cppMask_un_16_);
	BIT_VEC cppVar_4020 = (byte_cnt & cppMask_un_4_);
	BIT_VEC cppVar_4021 = cppVar_4019 + cppVar_4020;
	cppVar_4021 = (cppVar_4021 & cppMask_un_16_);
	BIT_VEC cppVar_4022 = (enc_data >> 8) & cppMask_un_8_;
	type_mem cppVar_4023 = XRAM;
	cppVar_4023.wr(cppVar_4021, cppVar_4022);
	cppVar_4013 = cppVar_4023;
	} else {
	type_mem cppVar_4024;
	bool cppVar_4026 = (aes_state == 3);
	bool cppVar_4028 = (byte_cnt == 0);
	bool cppVar_4029 = cppVar_4026 && cppVar_4028;
	if (cppVar_4029) {
	BIT_VEC cppVar_4030 = aes_addr + blk_cnt;
	cppVar_4030 = (cppVar_4030 & cppMask_un_16_);
	BIT_VEC cppVar_4031 = (byte_cnt & cppMask_un_4_);
	BIT_VEC cppVar_4032 = cppVar_4030 + cppVar_4031;
	cppVar_4032 = (cppVar_4032 & cppMask_un_16_);
	BIT_VEC cppVar_4033 = (enc_data >> 0) & cppMask_un_8_;
	type_mem cppVar_4034 = XRAM;
	cppVar_4034.wr(cppVar_4032, cppVar_4033);
	cppVar_4024 = cppVar_4034;
	} else {
	cppVar_4024 = XRAM;
	}
	cppVar_4013 = cppVar_4024;
	}
	cppVar_4002 = cppVar_4013;
	}
	cppVar_3991 = cppVar_4002;
	}
	cppVar_3980 = cppVar_3991;
	}
	cppVar_3969 = cppVar_3980;
	}
	cppVar_3958 = cppVar_3969;
	}
	cppVar_3947 = cppVar_3958;
	}
	cppVar_3936 = cppVar_3947;
	}
	cppVar_3925 = cppVar_3936;
	}
	cppVar_3914 = cppVar_3925;
	}
	cppVar_3903 = cppVar_3914;
	}
	cppVar_3892 = cppVar_3903;
	}
	cppVar_3881 = cppVar_3892;
	}
	cppVar_3870 = cppVar_3881;
	}
	cppVar_3859 = cppVar_3870;
	}
	cppVar_3856 = cppVar_3859;
	} else {
	cppVar_3856 = XRAM;
	}
	return cppVar_3856;
}
