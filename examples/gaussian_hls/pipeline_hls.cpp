#include <iostream>
#include <math.h>
#include <float.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#ifndef HALIDE_ATTRIBUTE_ALIGN
  #ifdef _MSC_VER
    #define HALIDE_ATTRIBUTE_ALIGN(x) __declspec(align(x))
  #else
    #define HALIDE_ATTRIBUTE_ALIGN(x) __attribute__((aligned(x)))
  #endif
#endif
#ifndef BUFFER_T_DEFINED
#define BUFFER_T_DEFINED
#include <stdbool.h>
#include <stdint.h>
typedef struct buffer_t {
    uint64_t dev;
    uint8_t* host;
    int32_t extent[4];
    int32_t stride[4];
    int32_t min[4];
    int32_t elem_size;
    HALIDE_ATTRIBUTE_ALIGN(1) bool host_dirty;
    HALIDE_ATTRIBUTE_ALIGN(1) bool dev_dirty;
    HALIDE_ATTRIBUTE_ALIGN(1) uint8_t _padding[10 - sizeof(void *)];
} buffer_t;
#endif
struct halide_filter_metadata_t;
extern "C" {
void *halide_malloc(void *ctx, size_t);
void halide_free(void *ctx, void *ptr);
void *halide_print(void *ctx, const void *str);
void *halide_error(void *ctx, const void *str);
int halide_debug_to_file(void *ctx, const char *filename, int, struct buffer_t *buf);
int halide_start_clock(void *ctx);
int64_t halide_current_time_ns(void *ctx);
void halide_profiler_pipeline_end(void *, void *);
}

#ifdef _WIN32
float roundf(float);
double round(double);
#else
inline float asinh_f32(float x) {return asinhf(x);}
inline float acosh_f32(float x) {return acoshf(x);}
inline float atanh_f32(float x) {return atanhf(x);}
inline double asinh_f64(double x) {return asinh(x);}
inline double acosh_f64(double x) {return acosh(x);}
inline double atanh_f64(double x) {return atanh(x);}
#endif
inline float sqrt_f32(float x) {return sqrtf(x);}
inline float sin_f32(float x) {return sinf(x);}
inline float asin_f32(float x) {return asinf(x);}
inline float cos_f32(float x) {return cosf(x);}
inline float acos_f32(float x) {return acosf(x);}
inline float tan_f32(float x) {return tanf(x);}
inline float atan_f32(float x) {return atanf(x);}
inline float sinh_f32(float x) {return sinhf(x);}
inline float cosh_f32(float x) {return coshf(x);}
inline float tanh_f32(float x) {return tanhf(x);}
inline float hypot_f32(float x, float y) {return hypotf(x, y);}
inline float exp_f32(float x) {return expf(x);}
inline float log_f32(float x) {return logf(x);}
inline float pow_f32(float x, float y) {return powf(x, y);}
inline float floor_f32(float x) {return floorf(x);}
inline float ceil_f32(float x) {return ceilf(x);}
inline float round_f32(float x) {return roundf(x);}

inline double sqrt_f64(double x) {return sqrt(x);}
inline double sin_f64(double x) {return sin(x);}
inline double asin_f64(double x) {return asin(x);}
inline double cos_f64(double x) {return cos(x);}
inline double acos_f64(double x) {return acos(x);}
inline double tan_f64(double x) {return tan(x);}
inline double atan_f64(double x) {return atan(x);}
inline double sinh_f64(double x) {return sinh(x);}
inline double cosh_f64(double x) {return cosh(x);}
inline double tanh_f64(double x) {return tanh(x);}
inline double hypot_f64(double x, double y) {return hypot(x, y);}
inline double exp_f64(double x) {return exp(x);}
inline double log_f64(double x) {return log(x);}
inline double pow_f64(double x, double y) {return pow(x, y);}
inline double floor_f64(double x) {return floor(x);}
inline double ceil_f64(double x) {return ceil(x);}
inline double round_f64(double x) {return round(x);}

inline float nan_f32() {return NAN;}
inline float neg_inf_f32() {return -INFINITY;}
inline float inf_f32() {return INFINITY;}
inline bool is_nan_f32(float x) {return x != x;}
inline bool is_nan_f64(double x) {return x != x;}
inline float float_from_bits(uint32_t bits) {
 union {
  uint32_t as_uint;
  float as_float;
 } u;
 u.as_uint = bits;
 return u.as_float;
}

template<typename T> T max(T a, T b) {if (a > b) return a; return b;}
template<typename T> T min(T a, T b) {if (a < b) return a; return b;}
template<typename A, typename B> A reinterpret(B b) {A a; memcpy(&a, &b, sizeof(a)); return a;}

inline static bool halide_rewrite_buffer(buffer_t *b, int32_t elem_size,
                           int32_t min0, int32_t extent0, int32_t stride0,
                           int32_t min1, int32_t extent1, int32_t stride1,
                           int32_t min2, int32_t extent2, int32_t stride2,
                           int32_t min3, int32_t extent3, int32_t stride3) {
 b->min[0] = min0;
 b->min[1] = min1;
 b->min[2] = min2;
 b->min[3] = min3;
 b->extent[0] = extent0;
 b->extent[1] = extent1;
 b->extent[2] = extent2;
 b->extent[3] = extent3;
 b->stride[0] = stride0;
 b->stride[1] = stride1;
 b->stride[2] = stride2;
 b->stride[3] = stride3;
 return true;
}
#ifndef HALIDE_FUNCTION_ATTRS
#define HALIDE_FUNCTION_ATTRS
#endif
#include <hls_stream.h>
#include "Stencil.h"
#include "hls_target.h"

#ifdef __cplusplus
extern "C" {
#endif
int32_t  halide_error_access_out_of_bounds(void *, const char *, int32_t , int32_t , int32_t , int32_t , int32_t );
int32_t  halide_error_bad_elem_size(void *, const char *, const char *, int32_t , int32_t );
int32_t  halide_error_buffer_allocation_too_large(void *, const char *, int64_t , int64_t );
int32_t  halide_error_buffer_extents_too_large(void *, const char *, int64_t , int64_t );
int32_t  halide_error_constraint_violated(void *, const char *, int32_t , const char *, int32_t );


#ifdef __cplusplus
}  // extern "C"
#endif

static int __pipeline_hls(buffer_t *_p2_in_buffer, buffer_t *_output_1_buffer) HALIDE_FUNCTION_ATTRS {
 uint8_t *_p2_in = (uint8_t *)(_p2_in_buffer->host);
 (void)_p2_in;
 const bool _p2_in_host_and_dev_are_null = (_p2_in_buffer->host == nullptr) && (_p2_in_buffer->dev == 0);
 (void)_p2_in_host_and_dev_are_null;
 const int32_t _p2_in_min_0 = _p2_in_buffer->min[0];
 (void)_p2_in_min_0;
 const int32_t _p2_in_min_1 = _p2_in_buffer->min[1];
 (void)_p2_in_min_1;
 const int32_t _p2_in_min_2 = _p2_in_buffer->min[2];
 (void)_p2_in_min_2;
 const int32_t _p2_in_min_3 = _p2_in_buffer->min[3];
 (void)_p2_in_min_3;
 const int32_t _p2_in_extent_0 = _p2_in_buffer->extent[0];
 (void)_p2_in_extent_0;
 const int32_t _p2_in_extent_1 = _p2_in_buffer->extent[1];
 (void)_p2_in_extent_1;
 const int32_t _p2_in_extent_2 = _p2_in_buffer->extent[2];
 (void)_p2_in_extent_2;
 const int32_t _p2_in_extent_3 = _p2_in_buffer->extent[3];
 (void)_p2_in_extent_3;
 const int32_t _p2_in_stride_0 = _p2_in_buffer->stride[0];
 (void)_p2_in_stride_0;
 const int32_t _p2_in_stride_1 = _p2_in_buffer->stride[1];
 (void)_p2_in_stride_1;
 const int32_t _p2_in_stride_2 = _p2_in_buffer->stride[2];
 (void)_p2_in_stride_2;
 const int32_t _p2_in_stride_3 = _p2_in_buffer->stride[3];
 (void)_p2_in_stride_3;
 const int32_t _p2_in_elem_size = _p2_in_buffer->elem_size;
 (void)_p2_in_elem_size;
 uint8_t *_output_1 = (uint8_t *)(_output_1_buffer->host);
 (void)_output_1;
 const bool _output_1_host_and_dev_are_null = (_output_1_buffer->host == nullptr) && (_output_1_buffer->dev == 0);
 (void)_output_1_host_and_dev_are_null;
 const int32_t _output_1_min_0 = _output_1_buffer->min[0];
 (void)_output_1_min_0;
 const int32_t _output_1_min_1 = _output_1_buffer->min[1];
 (void)_output_1_min_1;
 const int32_t _output_1_min_2 = _output_1_buffer->min[2];
 (void)_output_1_min_2;
 const int32_t _output_1_min_3 = _output_1_buffer->min[3];
 (void)_output_1_min_3;
 const int32_t _output_1_extent_0 = _output_1_buffer->extent[0];
 (void)_output_1_extent_0;
 const int32_t _output_1_extent_1 = _output_1_buffer->extent[1];
 (void)_output_1_extent_1;
 const int32_t _output_1_extent_2 = _output_1_buffer->extent[2];
 (void)_output_1_extent_2;
 const int32_t _output_1_extent_3 = _output_1_buffer->extent[3];
 (void)_output_1_extent_3;
 const int32_t _output_1_stride_0 = _output_1_buffer->stride[0];
 (void)_output_1_stride_0;
 const int32_t _output_1_stride_1 = _output_1_buffer->stride[1];
 (void)_output_1_stride_1;
 const int32_t _output_1_stride_2 = _output_1_buffer->stride[2];
 (void)_output_1_stride_2;
 const int32_t _output_1_stride_3 = _output_1_buffer->stride[3];
 (void)_output_1_stride_3;
 const int32_t _output_1_elem_size = _output_1_buffer->elem_size;
 (void)_output_1_elem_size;
 int32_t _0 = _output_1_extent_0 + -1;
 int32_t _1 = _0 / 480;
 int32_t _2 = _1 * 480;
 int32_t _3 = _0 - _2;
 int32_t _4 = _3 >> 31;
 int32_t _5 = 480 >> 31;
 int32_t _6 = _4 & _5;
 int32_t _7 = _1 - _6;
 int32_t _8 = ~_5;
 int32_t _9 = _4 & _8;
 int32_t _10 = _7 + _9;
 int32_t _11 = _10 * 480;
 int32_t _12 = _11 + _output_1_min_0;
 int32_t _13 = _12 + 479;
 int32_t _14 = _output_1_min_0 + _output_1_extent_0;
 int32_t _15 = _14 + -1;
 int32_t _16 = min(_13, _15);
 int32_t _17 = _14 + -480;
 int32_t _18 = min(_output_1_min_0, _17);
 int32_t _19 = _16 - _18;
 int32_t _20 = _output_1_extent_1 + -1;
 int32_t _21 = _20 / 640;
 int32_t _22 = _21 * 640;
 int32_t _23 = _20 - _22;
 int32_t _24 = _23 >> 31;
 int32_t _25 = 640 >> 31;
 int32_t _26 = _24 & _25;
 int32_t _27 = _21 - _26;
 int32_t _28 = ~_25;
 int32_t _29 = _24 & _28;
 int32_t _30 = _27 + _29;
 int32_t _31 = _30 * 640;
 int32_t _32 = _31 + _output_1_min_1;
 int32_t _33 = _32 + 639;
 int32_t _34 = _output_1_min_1 + _output_1_extent_1;
 int32_t _35 = _34 + -1;
 int32_t _36 = min(_33, _35);
 int32_t _37 = _34 + -640;
 int32_t _38 = min(_output_1_min_1, _37);
 int32_t _39 = _36 - _38;
 if (_output_1_host_and_dev_are_null)
 {
  int32_t _40 = _19 + 1;
  int32_t _41 = _39 + 1;
  bool _42 = halide_rewrite_buffer(_output_1_buffer, 1, _18, _40, 1, _38, _41, _40, 0, 0, 0, 0, 0, 0);
  (void)_42;
 } // if _output_1_host_and_dev_are_null
 if (_p2_in_host_and_dev_are_null)
 {
  int32_t _43 = _output_1_extent_0 + 8;
  int32_t _44 = _output_1_extent_1 + 8;
  bool _45 = halide_rewrite_buffer(_p2_in_buffer, 1, _output_1_min_0, _43, 1, _output_1_min_1, _44, _43, 0, 0, 0, 0, 0, 0);
  (void)_45;
 } // if _p2_in_host_and_dev_are_null
 bool _46 = _output_1_host_and_dev_are_null || _p2_in_host_and_dev_are_null;
 bool _47 = !(_46);
 if (_47)
 {
  bool _48 = _output_1_elem_size == 1;
  if (!_48)   {
   int32_t _49 = halide_error_bad_elem_size(nullptr, "Output buffer output$1", "uint8", _output_1_elem_size, 1);
   return _49;
  }
  bool _50 = _p2_in_elem_size == 1;
  if (!_50)   {
   int32_t _51 = halide_error_bad_elem_size(nullptr, "Input buffer p2:in", "uint8", _p2_in_elem_size, 1);
   return _51;
  }
  bool _52 = _output_1_min_0 <= _18;
  int32_t _53 = _18 + _19;
  int32_t _54 = _53 - _output_1_extent_0;
  int32_t _55 = _54 + 1;
  bool _56 = _55 <= _output_1_min_0;
  bool _57 = _52 && _56;
  if (!_57)   {
   int32_t _58 = _18 + _19;
   int32_t _59 = _output_1_min_0 + _output_1_extent_0;
   int32_t _60 = _59 + -1;
   int32_t _61 = halide_error_access_out_of_bounds(nullptr, "Output buffer output$1", 0, _18, _58, _output_1_min_0, _60);
   return _61;
  }
  bool _62 = _output_1_min_1 <= _38;
  int32_t _63 = _38 + _39;
  int32_t _64 = _63 - _output_1_extent_1;
  int32_t _65 = _64 + 1;
  bool _66 = _65 <= _output_1_min_1;
  bool _67 = _62 && _66;
  if (!_67)   {
   int32_t _68 = _38 + _39;
   int32_t _69 = _output_1_min_1 + _output_1_extent_1;
   int32_t _70 = _69 + -1;
   int32_t _71 = halide_error_access_out_of_bounds(nullptr, "Output buffer output$1", 1, _38, _68, _output_1_min_1, _70);
   return _71;
  }
  bool _72 = _p2_in_min_0 <= _output_1_min_0;
  int32_t _73 = _output_1_min_0 + _output_1_extent_0;
  int32_t _74 = _73 - _p2_in_extent_0;
  int32_t _75 = _74 + 8;
  bool _76 = _75 <= _p2_in_min_0;
  bool _77 = _72 && _76;
  if (!_77)   {
   int32_t _78 = _output_1_min_0 + _output_1_extent_0;
   int32_t _79 = _78 + 7;
   int32_t _80 = _p2_in_min_0 + _p2_in_extent_0;
   int32_t _81 = _80 + -1;
   int32_t _82 = halide_error_access_out_of_bounds(nullptr, "Input buffer p2:in", 0, _output_1_min_0, _79, _p2_in_min_0, _81);
   return _82;
  }
  bool _83 = _p2_in_min_1 <= _output_1_min_1;
  int32_t _84 = _output_1_min_1 + _output_1_extent_1;
  int32_t _85 = _84 - _p2_in_extent_1;
  int32_t _86 = _85 + 8;
  bool _87 = _86 <= _p2_in_min_1;
  bool _88 = _83 && _87;
  if (!_88)   {
   int32_t _89 = _output_1_min_1 + _output_1_extent_1;
   int32_t _90 = _89 + 7;
   int32_t _91 = _p2_in_min_1 + _p2_in_extent_1;
   int32_t _92 = _91 + -1;
   int32_t _93 = halide_error_access_out_of_bounds(nullptr, "Input buffer p2:in", 1, _output_1_min_1, _90, _p2_in_min_1, _92);
   return _93;
  }
  bool _94 = _output_1_stride_0 == 1;
  if (!_94)   {
   int32_t _95 = halide_error_constraint_violated(nullptr, "output$1.stride.0", _output_1_stride_0, "1", 1);
   return _95;
  }
  bool _96 = _p2_in_stride_0 == 1;
  if (!_96)   {
   int32_t _97 = halide_error_constraint_violated(nullptr, "p2:in.stride.0", _p2_in_stride_0, "1", 1);
   return _97;
  }
  int64_t _98 = (int64_t)(_output_1_extent_1);
  int64_t _99 = (int64_t)(_output_1_extent_0);
  int64_t _100 = _98 * _99;
  int64_t _101 = (int64_t)(_p2_in_extent_1);
  int64_t _102 = (int64_t)(_p2_in_extent_0);
  int64_t _103 = _101 * _102;
  int64_t _104 = (int64_t)(2147483647);
  bool _105 = _99 <= _104;
  if (!_105)   {
   int64_t _106 = (int64_t)(_output_1_extent_0);
   int64_t _107 = (int64_t)(2147483647);
   int32_t _108 = halide_error_buffer_allocation_too_large(nullptr, "output$1", _106, _107);
   return _108;
  }
  int64_t _109 = (int64_t)(_output_1_extent_1);
  int64_t _110 = (int64_t)(_output_1_stride_1);
  int64_t _111 = _109 * _110;
  int64_t _112 = (int64_t)(2147483647);
  bool _113 = _111 <= _112;
  if (!_113)   {
   int64_t _114 = (int64_t)(_output_1_extent_1);
   int64_t _115 = (int64_t)(_output_1_stride_1);
   int64_t _116 = _114 * _115;
   int64_t _117 = (int64_t)(2147483647);
   int32_t _118 = halide_error_buffer_allocation_too_large(nullptr, "output$1", _116, _117);
   return _118;
  }
  int64_t _119 = (int64_t)(2147483647);
  bool _120 = _100 <= _119;
  if (!_120)   {
   int64_t _121 = (int64_t)(2147483647);
   int32_t _122 = halide_error_buffer_extents_too_large(nullptr, "output$1", _100, _121);
   return _122;
  }
  int64_t _123 = (int64_t)(_p2_in_extent_0);
  int64_t _124 = (int64_t)(2147483647);
  bool _125 = _123 <= _124;
  if (!_125)   {
   int64_t _126 = (int64_t)(_p2_in_extent_0);
   int64_t _127 = (int64_t)(2147483647);
   int32_t _128 = halide_error_buffer_allocation_too_large(nullptr, "p2:in", _126, _127);
   return _128;
  }
  int64_t _129 = (int64_t)(_p2_in_extent_1);
  int64_t _130 = (int64_t)(_p2_in_stride_1);
  int64_t _131 = _129 * _130;
  int64_t _132 = (int64_t)(2147483647);
  bool _133 = _131 <= _132;
  if (!_133)   {
   int64_t _134 = (int64_t)(_p2_in_extent_1);
   int64_t _135 = (int64_t)(_p2_in_stride_1);
   int64_t _136 = _134 * _135;
   int64_t _137 = (int64_t)(2147483647);
   int32_t _138 = halide_error_buffer_allocation_too_large(nullptr, "p2:in", _136, _137);
   return _138;
  }
  int64_t _139 = (int64_t)(2147483647);
  bool _140 = _103 <= _139;
  if (!_140)   {
   int64_t _141 = (int64_t)(2147483647);
   int32_t _142 = halide_error_buffer_extents_too_large(nullptr, "p2:in", _103, _141);
   return _142;
  }
  // produce output$1
  int32_t _143 = _output_1_extent_1 + 639;
  int32_t _144 = _143 / 640;
  int32_t _145 = _144 * 640;
  int32_t _146 = _143 - _145;
  int32_t _147 = _146 >> 31;
  int32_t _148 = 640 >> 31;
  int32_t _149 = _147 & _148;
  int32_t _150 = _144 - _149;
  int32_t _151 = ~_148;
  int32_t _152 = _147 & _151;
  int32_t _153 = _150 + _152;
  for (int _output_1_s0_y_yo = 0; _output_1_s0_y_yo < 0 + _153; _output_1_s0_y_yo++)
  {
   int32_t _154 = _output_1_s0_y_yo * 640;
   int32_t _155 = _154 + _output_1_min_1;
   int32_t _156 = _output_1_min_1 + _output_1_extent_1;
   int32_t _157 = _156 + -640;
   int32_t _158 = min(_155, _157);
   int32_t _159 = _output_1_extent_0 + 479;
   int32_t _160 = _159 / 480;
   int32_t _161 = _160 * 480;
   int32_t _162 = _159 - _161;
   int32_t _163 = _162 >> 31;
   int32_t _164 = 480 >> 31;
   int32_t _165 = _163 & _164;
   int32_t _166 = _160 - _165;
   int32_t _167 = ~_164;
   int32_t _168 = _163 & _167;
   int32_t _169 = _166 + _168;
   for (int _output_1_s0_x_xo = 0; _output_1_s0_x_xo < 0 + _169; _output_1_s0_x_xo++)
   {
    int32_t _170 = _output_1_s0_x_xo * 480;
    int32_t _171 = _170 + _output_1_min_0;
    int32_t _172 = _output_1_min_0 + _output_1_extent_0;
    int32_t _173 = _172 + -480;
    int32_t _174 = min(_171, _173);
    {
     int64_t _175 = 316224;
     uint8_t *_p2_in_bounded = (uint8_t *)halide_malloc(nullptr, sizeof(uint8_t)*_175);
     void *_176 = ((uint8_t *)_p2_in_bounded + 0);
     int32_t _177 = _174 + -4;
     int32_t _178 = _158 + -4;
     buffer_t B0 = {0};
     B0.host = const_cast<uint8_t *>((const uint8_t *)(_176));
     B0.elem_size = 1;
     B0.min[0] = _177;
     B0.extent[0] = 488;
     B0.stride[0] = 1;
     B0.min[1] = _178;
     B0.extent[1] = 648;
     B0.stride[1] = 488;
     struct buffer_t *_179 = (&B0);
     // produce p2:in_bounded
     for (int _p2_in_bounded_s0_y = _178; _p2_in_bounded_s0_y < _178 + 648; _p2_in_bounded_s0_y++)
     {
      int32_t _180 = _174 + -4;
      for (int _p2_in_bounded_s0_x = _180; _p2_in_bounded_s0_x < _180 + 488; _p2_in_bounded_s0_x++)
      {
       int32_t _181 = _p2_in_bounded_s0_x - _174;
       int32_t _182 = _p2_in_bounded_s0_y - _158;
       int32_t _183 = _182 * 488;
       int32_t _184 = _181 + _183;
       int32_t _185 = _184 + 1956;
       int32_t _186 = _p2_in_bounded_s0_y + 4;
       int32_t _187 = _186 * _p2_in_stride_1;
       int32_t _188 = _p2_in_bounded_s0_x + _187;
       int32_t _189 = _p2_in_min_1 * _p2_in_stride_1;
       int32_t _190 = _p2_in_min_0 + _189;
       int32_t _191 = _188 - _190;
       int32_t _192 = _191 + 4;
       uint8_t _193 = _p2_in[_192];
       _p2_in_bounded[_185] = _193;
      } // for _p2_in_bounded_s0_x
     } // for _p2_in_bounded_s0_y
     // consume p2:in_bounded
     {
      int64_t _194 = 307200;
      uint8_t *_hw_output_1 = (uint8_t *)halide_malloc(nullptr, sizeof(uint8_t)*_194);
      void *_195 = ((uint8_t *)_hw_output_1 + 0);
      buffer_t B1 = {0};
      B1.host = const_cast<uint8_t *>((const uint8_t *)(_195));
      B1.elem_size = 1;
      B1.min[0] = _174;
      B1.extent[0] = 480;
      B1.stride[0] = 1;
      B1.min[1] = _158;
      B1.extent[1] = 640;
      B1.stride[1] = 480;
      struct buffer_t *_196 = (&B1);
      // produce hw_output$1
      hls::stream<AxiPackedStencil<uint8_t, 1, 1> > _p2_in_bounded_stencil_update_stream;
      void *_197 = ((uint8_t *)_p2_in_bounded + 0);
      subimage_to_stream(_179, _p2_in_bounded_stencil_update_stream, _197, 1, 488, 488, 648);
      (void)0;
      halide_free(nullptr, _p2_in_bounded);
      hls::stream<AxiPackedStencil<uint8_t, 1, 1> > _hw_output_1_stencil_stream;
      hls_target(_hw_output_1_stencil_stream, _p2_in_bounded_stencil_update_stream);
      stream_to_subimage(_196, _hw_output_1_stencil_stream, _195, 1, 480, 480, 640);
      (void)0;
      // consume hw_output$1
      for (int _output_1_s0_y_yi = 0; _output_1_s0_y_yi < 0 + 640; _output_1_s0_y_yi++)
      {
       for (int _output_1_s0_x_xi = 0; _output_1_s0_x_xi < 0 + 480; _output_1_s0_x_xi++)
       {
        int32_t _680 = _174 + _output_1_s0_x_xi;
        int32_t _681 = _158 + _output_1_s0_y_yi;
        int32_t _682 = _681 * _output_1_stride_1;
        int32_t _683 = _680 + _682;
        int32_t _684 = _output_1_min_1 * _output_1_stride_1;
        int32_t _685 = _output_1_min_0 + _684;
        int32_t _686 = _683 - _685;
        int32_t _687 = _output_1_s0_y_yi * 480;
        int32_t _688 = _output_1_s0_x_xi + _687;
        uint8_t _689 = _hw_output_1[_688];
        _output_1[_686] = _689;
       } // for _output_1_s0_x_xi
      } // for _output_1_s0_y_yi
      halide_free(nullptr, _hw_output_1);
     } // alloc _hw_output_1
    } // alloc _p2_in_bounded
   } // for _output_1_s0_x_xo
  } // for _output_1_s0_y_yo
  // consume output$1
 } // if _47
 return 0;
}


int pipeline_hls(buffer_t *_p2_in_buffer, buffer_t *_output_1_buffer) HALIDE_FUNCTION_ATTRS {
 uint8_t *_p2_in = (uint8_t *)(_p2_in_buffer->host);
 (void)_p2_in;
 const bool _p2_in_host_and_dev_are_null = (_p2_in_buffer->host == nullptr) && (_p2_in_buffer->dev == 0);
 (void)_p2_in_host_and_dev_are_null;
 const int32_t _p2_in_min_0 = _p2_in_buffer->min[0];
 (void)_p2_in_min_0;
 const int32_t _p2_in_min_1 = _p2_in_buffer->min[1];
 (void)_p2_in_min_1;
 const int32_t _p2_in_min_2 = _p2_in_buffer->min[2];
 (void)_p2_in_min_2;
 const int32_t _p2_in_min_3 = _p2_in_buffer->min[3];
 (void)_p2_in_min_3;
 const int32_t _p2_in_extent_0 = _p2_in_buffer->extent[0];
 (void)_p2_in_extent_0;
 const int32_t _p2_in_extent_1 = _p2_in_buffer->extent[1];
 (void)_p2_in_extent_1;
 const int32_t _p2_in_extent_2 = _p2_in_buffer->extent[2];
 (void)_p2_in_extent_2;
 const int32_t _p2_in_extent_3 = _p2_in_buffer->extent[3];
 (void)_p2_in_extent_3;
 const int32_t _p2_in_stride_0 = _p2_in_buffer->stride[0];
 (void)_p2_in_stride_0;
 const int32_t _p2_in_stride_1 = _p2_in_buffer->stride[1];
 (void)_p2_in_stride_1;
 const int32_t _p2_in_stride_2 = _p2_in_buffer->stride[2];
 (void)_p2_in_stride_2;
 const int32_t _p2_in_stride_3 = _p2_in_buffer->stride[3];
 (void)_p2_in_stride_3;
 const int32_t _p2_in_elem_size = _p2_in_buffer->elem_size;
 (void)_p2_in_elem_size;
 uint8_t *_output_1 = (uint8_t *)(_output_1_buffer->host);
 (void)_output_1;
 const bool _output_1_host_and_dev_are_null = (_output_1_buffer->host == nullptr) && (_output_1_buffer->dev == 0);
 (void)_output_1_host_and_dev_are_null;
 const int32_t _output_1_min_0 = _output_1_buffer->min[0];
 (void)_output_1_min_0;
 const int32_t _output_1_min_1 = _output_1_buffer->min[1];
 (void)_output_1_min_1;
 const int32_t _output_1_min_2 = _output_1_buffer->min[2];
 (void)_output_1_min_2;
 const int32_t _output_1_min_3 = _output_1_buffer->min[3];
 (void)_output_1_min_3;
 const int32_t _output_1_extent_0 = _output_1_buffer->extent[0];
 (void)_output_1_extent_0;
 const int32_t _output_1_extent_1 = _output_1_buffer->extent[1];
 (void)_output_1_extent_1;
 const int32_t _output_1_extent_2 = _output_1_buffer->extent[2];
 (void)_output_1_extent_2;
 const int32_t _output_1_extent_3 = _output_1_buffer->extent[3];
 (void)_output_1_extent_3;
 const int32_t _output_1_stride_0 = _output_1_buffer->stride[0];
 (void)_output_1_stride_0;
 const int32_t _output_1_stride_1 = _output_1_buffer->stride[1];
 (void)_output_1_stride_1;
 const int32_t _output_1_stride_2 = _output_1_buffer->stride[2];
 (void)_output_1_stride_2;
 const int32_t _output_1_stride_3 = _output_1_buffer->stride[3];
 (void)_output_1_stride_3;
 const int32_t _output_1_elem_size = _output_1_buffer->elem_size;
 (void)_output_1_elem_size;
 int32_t _690 = __pipeline_hls(_p2_in_buffer, _output_1_buffer);
 bool _691 = _690 == 0;
 if (!_691)  {
  return _690;
 }
 return 0;
}
