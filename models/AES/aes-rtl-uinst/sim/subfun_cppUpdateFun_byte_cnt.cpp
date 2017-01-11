#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_byte_cnt(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_4052;
	bool cppVar_4054 = (aes_state != 0);
	if (cppVar_4054) {
	BIT_VEC cppVar_4055;
	bool cppVar_4057 = (aes_state == 2);
	bool cppVar_4059 = (byte_cnt == 0);
	bool cppVar_4060 = cppVar_4057 && cppVar_4059;
	if (cppVar_4060) {
	cppVar_4055 = 0;
	} else {
	BIT_VEC cppVar_4062;
	bool cppVar_4064 = (aes_state == 3);
	bool cppVar_4066 = (byte_cnt == 15);
	bool cppVar_4067 = cppVar_4064 && cppVar_4066;
	bool cppVar_4069 = (aes_state == 1);
	bool cppVar_4071 = (byte_cnt == 15);
	bool cppVar_4072 = cppVar_4069 && cppVar_4071;
	bool cppVar_4074 = (aes_state == 3);
	bool cppVar_4076 = (byte_cnt == 14);
	bool cppVar_4077 = cppVar_4074 && cppVar_4076;
	bool cppVar_4079 = (aes_state == 1);
	bool cppVar_4081 = (byte_cnt == 14);
	bool cppVar_4082 = cppVar_4079 && cppVar_4081;
	bool cppVar_4084 = (aes_state == 3);
	bool cppVar_4086 = (byte_cnt == 13);
	bool cppVar_4087 = cppVar_4084 && cppVar_4086;
	bool cppVar_4089 = (aes_state == 1);
	bool cppVar_4091 = (byte_cnt == 13);
	bool cppVar_4092 = cppVar_4089 && cppVar_4091;
	bool cppVar_4094 = (aes_state == 3);
	bool cppVar_4096 = (byte_cnt == 12);
	bool cppVar_4097 = cppVar_4094 && cppVar_4096;
	bool cppVar_4099 = (aes_state == 1);
	bool cppVar_4101 = (byte_cnt == 12);
	bool cppVar_4102 = cppVar_4099 && cppVar_4101;
	bool cppVar_4104 = (aes_state == 3);
	bool cppVar_4106 = (byte_cnt == 11);
	bool cppVar_4107 = cppVar_4104 && cppVar_4106;
	bool cppVar_4109 = (aes_state == 1);
	bool cppVar_4111 = (byte_cnt == 11);
	bool cppVar_4112 = cppVar_4109 && cppVar_4111;
	bool cppVar_4114 = (aes_state == 3);
	bool cppVar_4116 = (byte_cnt == 10);
	bool cppVar_4117 = cppVar_4114 && cppVar_4116;
	bool cppVar_4119 = (aes_state == 1);
	bool cppVar_4121 = (byte_cnt == 10);
	bool cppVar_4122 = cppVar_4119 && cppVar_4121;
	bool cppVar_4124 = (aes_state == 3);
	bool cppVar_4126 = (byte_cnt == 9);
	bool cppVar_4127 = cppVar_4124 && cppVar_4126;
	bool cppVar_4129 = (aes_state == 1);
	bool cppVar_4131 = (byte_cnt == 9);
	bool cppVar_4132 = cppVar_4129 && cppVar_4131;
	bool cppVar_4134 = (aes_state == 3);
	bool cppVar_4136 = (byte_cnt == 8);
	bool cppVar_4137 = cppVar_4134 && cppVar_4136;
	bool cppVar_4139 = (aes_state == 1);
	bool cppVar_4141 = (byte_cnt == 8);
	bool cppVar_4142 = cppVar_4139 && cppVar_4141;
	bool cppVar_4144 = (aes_state == 3);
	bool cppVar_4146 = (byte_cnt == 7);
	bool cppVar_4147 = cppVar_4144 && cppVar_4146;
	bool cppVar_4149 = (aes_state == 1);
	bool cppVar_4151 = (byte_cnt == 7);
	bool cppVar_4152 = cppVar_4149 && cppVar_4151;
	bool cppVar_4154 = (aes_state == 3);
	bool cppVar_4156 = (byte_cnt == 6);
	bool cppVar_4157 = cppVar_4154 && cppVar_4156;
	bool cppVar_4159 = (aes_state == 1);
	bool cppVar_4161 = (byte_cnt == 6);
	bool cppVar_4162 = cppVar_4159 && cppVar_4161;
	bool cppVar_4164 = (aes_state == 3);
	bool cppVar_4166 = (byte_cnt == 5);
	bool cppVar_4167 = cppVar_4164 && cppVar_4166;
	bool cppVar_4169 = (aes_state == 1);
	bool cppVar_4171 = (byte_cnt == 5);
	bool cppVar_4172 = cppVar_4169 && cppVar_4171;
	bool cppVar_4174 = (aes_state == 3);
	bool cppVar_4176 = (byte_cnt == 4);
	bool cppVar_4177 = cppVar_4174 && cppVar_4176;
	bool cppVar_4179 = (aes_state == 1);
	bool cppVar_4181 = (byte_cnt == 4);
	bool cppVar_4182 = cppVar_4179 && cppVar_4181;
	bool cppVar_4184 = (aes_state == 3);
	bool cppVar_4186 = (byte_cnt == 3);
	bool cppVar_4187 = cppVar_4184 && cppVar_4186;
	bool cppVar_4189 = (aes_state == 1);
	bool cppVar_4191 = (byte_cnt == 3);
	bool cppVar_4192 = cppVar_4189 && cppVar_4191;
	bool cppVar_4194 = (aes_state == 3);
	bool cppVar_4196 = (byte_cnt == 2);
	bool cppVar_4197 = cppVar_4194 && cppVar_4196;
	bool cppVar_4199 = (aes_state == 1);
	bool cppVar_4201 = (byte_cnt == 2);
	bool cppVar_4202 = cppVar_4199 && cppVar_4201;
	bool cppVar_4204 = (aes_state == 3);
	bool cppVar_4206 = (byte_cnt == 1);
	bool cppVar_4207 = cppVar_4204 && cppVar_4206;
	bool cppVar_4209 = (aes_state == 1);
	bool cppVar_4211 = (byte_cnt == 1);
	bool cppVar_4212 = cppVar_4209 && cppVar_4211;
	bool cppVar_4214 = (aes_state == 3);
	bool cppVar_4216 = (byte_cnt == 0);
	bool cppVar_4217 = cppVar_4214 && cppVar_4216;
	bool cppVar_4219 = (aes_state == 1);
	bool cppVar_4221 = (byte_cnt == 0);
	bool cppVar_4222 = cppVar_4219 && cppVar_4221;
	bool cppVar_4223 = cppVar_4217 || cppVar_4222;
	bool cppVar_4224 = cppVar_4212 || cppVar_4223;
	bool cppVar_4225 = cppVar_4207 || cppVar_4224;
	bool cppVar_4226 = cppVar_4202 || cppVar_4225;
	bool cppVar_4227 = cppVar_4197 || cppVar_4226;
	bool cppVar_4228 = cppVar_4192 || cppVar_4227;
	bool cppVar_4229 = cppVar_4187 || cppVar_4228;
	bool cppVar_4230 = cppVar_4182 || cppVar_4229;
	bool cppVar_4231 = cppVar_4177 || cppVar_4230;
	bool cppVar_4232 = cppVar_4172 || cppVar_4231;
	bool cppVar_4233 = cppVar_4167 || cppVar_4232;
	bool cppVar_4234 = cppVar_4162 || cppVar_4233;
	bool cppVar_4235 = cppVar_4157 || cppVar_4234;
	bool cppVar_4236 = cppVar_4152 || cppVar_4235;
	bool cppVar_4237 = cppVar_4147 || cppVar_4236;
	bool cppVar_4238 = cppVar_4142 || cppVar_4237;
	bool cppVar_4239 = cppVar_4137 || cppVar_4238;
	bool cppVar_4240 = cppVar_4132 || cppVar_4239;
	bool cppVar_4241 = cppVar_4127 || cppVar_4240;
	bool cppVar_4242 = cppVar_4122 || cppVar_4241;
	bool cppVar_4243 = cppVar_4117 || cppVar_4242;
	bool cppVar_4244 = cppVar_4112 || cppVar_4243;
	bool cppVar_4245 = cppVar_4107 || cppVar_4244;
	bool cppVar_4246 = cppVar_4102 || cppVar_4245;
	bool cppVar_4247 = cppVar_4097 || cppVar_4246;
	bool cppVar_4248 = cppVar_4092 || cppVar_4247;
	bool cppVar_4249 = cppVar_4087 || cppVar_4248;
	bool cppVar_4250 = cppVar_4082 || cppVar_4249;
	bool cppVar_4251 = cppVar_4077 || cppVar_4250;
	bool cppVar_4252 = cppVar_4072 || cppVar_4251;
	bool cppVar_4253 = cppVar_4067 || cppVar_4252;
	if (cppVar_4253) {
	BIT_VEC cppVar_4255 = byte_cnt + 1;
	cppVar_4255 = (cppVar_4255 & cppMask_un_4_);
	cppVar_4062 = cppVar_4255;
	} else {
	cppVar_4062 = byte_cnt;
	}
	cppVar_4055 = cppVar_4062;
	}
	cppVar_4052 = cppVar_4055;
	} else {
	cppVar_4052 = byte_cnt;
	}
	return cppVar_4052;
}
