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
#ifndef CMA_BUFFER_T_DEFINED
#define CMA_BUFFER_T_DEFINED
struct mMap;
typedef struct cma_buffer_t {
  unsigned int id; // ID flag for internal use
  unsigned int width; // Width of the image
  unsigned int stride; // Stride between rows, in pixels. This must be >= width
  unsigned int height; // Height of the image
  unsigned int depth; // Byte-depth of the image
  unsigned int phys_addr; // Bus address for DMA
  void* kern_addr; // Kernel virtual address
  struct mMap* cvals;
  unsigned int mmap_offset;
} cma_buffer_t;
#endif
// Zynq runtime API
int halide_zynq_init();
void halide_zynq_free(void *user_context, void *ptr);
int halide_zynq_cma_alloc(struct buffer_t *buf);
int halide_zynq_cma_free(struct buffer_t *buf);
int halide_zynq_subimage(const struct buffer_t* image, struct cma_buffer_t* subimage, void *address_of_subimage_origin, int width, int height);
int halide_zynq_hwacc_launch(struct cma_buffer_t bufs[]);
int halide_zynq_hwacc_sync(int task_id);

#ifdef __cplusplus
extern "C" {
#endif
int32_t  halide_error_access_out_of_bounds(void *, const char *, int32_t , int32_t , int32_t , int32_t , int32_t );
int32_t  halide_error_bad_elem_size(void *, const char *, const char *, int32_t , int32_t );
int32_t  halide_error_buffer_allocation_too_large(void *, const char *, int64_t , int64_t );
int32_t  halide_error_buffer_extents_too_large(void *, const char *, int64_t , int64_t );
int32_t  halide_error_constraint_violated(void *, const char *, int32_t , const char *, int32_t );


static int __pipeline_zynq(buffer_t *_p2___in_buffer, buffer_t *_output__1_buffer) HALIDE_FUNCTION_ATTRS {
 uint8_t *_p2___in = (uint8_t *)(_p2___in_buffer->host);
 (void)_p2___in;
 const bool _p2___in_host_and_dev_are_null = (_p2___in_buffer->host == nullptr) && (_p2___in_buffer->dev == 0);
 (void)_p2___in_host_and_dev_are_null;
 const int32_t _p2___in_min_0 = _p2___in_buffer->min[0];
 (void)_p2___in_min_0;
 const int32_t _p2___in_min_1 = _p2___in_buffer->min[1];
 (void)_p2___in_min_1;
 const int32_t _p2___in_min_2 = _p2___in_buffer->min[2];
 (void)_p2___in_min_2;
 const int32_t _p2___in_min_3 = _p2___in_buffer->min[3];
 (void)_p2___in_min_3;
 const int32_t _p2___in_extent_0 = _p2___in_buffer->extent[0];
 (void)_p2___in_extent_0;
 const int32_t _p2___in_extent_1 = _p2___in_buffer->extent[1];
 (void)_p2___in_extent_1;
 const int32_t _p2___in_extent_2 = _p2___in_buffer->extent[2];
 (void)_p2___in_extent_2;
 const int32_t _p2___in_extent_3 = _p2___in_buffer->extent[3];
 (void)_p2___in_extent_3;
 const int32_t _p2___in_stride_0 = _p2___in_buffer->stride[0];
 (void)_p2___in_stride_0;
 const int32_t _p2___in_stride_1 = _p2___in_buffer->stride[1];
 (void)_p2___in_stride_1;
 const int32_t _p2___in_stride_2 = _p2___in_buffer->stride[2];
 (void)_p2___in_stride_2;
 const int32_t _p2___in_stride_3 = _p2___in_buffer->stride[3];
 (void)_p2___in_stride_3;
 const int32_t _p2___in_elem_size = _p2___in_buffer->elem_size;
 (void)_p2___in_elem_size;
 uint8_t *_output__1 = (uint8_t *)(_output__1_buffer->host);
 (void)_output__1;
 const bool _output__1_host_and_dev_are_null = (_output__1_buffer->host == nullptr) && (_output__1_buffer->dev == 0);
 (void)_output__1_host_and_dev_are_null;
 const int32_t _output__1_min_0 = _output__1_buffer->min[0];
 (void)_output__1_min_0;
 const int32_t _output__1_min_1 = _output__1_buffer->min[1];
 (void)_output__1_min_1;
 const int32_t _output__1_min_2 = _output__1_buffer->min[2];
 (void)_output__1_min_2;
 const int32_t _output__1_min_3 = _output__1_buffer->min[3];
 (void)_output__1_min_3;
 const int32_t _output__1_extent_0 = _output__1_buffer->extent[0];
 (void)_output__1_extent_0;
 const int32_t _output__1_extent_1 = _output__1_buffer->extent[1];
 (void)_output__1_extent_1;
 const int32_t _output__1_extent_2 = _output__1_buffer->extent[2];
 (void)_output__1_extent_2;
 const int32_t _output__1_extent_3 = _output__1_buffer->extent[3];
 (void)_output__1_extent_3;
 const int32_t _output__1_stride_0 = _output__1_buffer->stride[0];
 (void)_output__1_stride_0;
 const int32_t _output__1_stride_1 = _output__1_buffer->stride[1];
 (void)_output__1_stride_1;
 const int32_t _output__1_stride_2 = _output__1_buffer->stride[2];
 (void)_output__1_stride_2;
 const int32_t _output__1_stride_3 = _output__1_buffer->stride[3];
 (void)_output__1_stride_3;
 const int32_t _output__1_elem_size = _output__1_buffer->elem_size;
 (void)_output__1_elem_size;
 int32_t _692 = _output__1_extent_0 + -1;
 int32_t _693 = _692 / 480;
 int32_t _694 = _693 * 480;
 int32_t _695 = _692 - _694;
 int32_t _696 = _695 >> 31;
 int32_t _697 = 480 >> 31;
 int32_t _698 = _696 & _697;
 int32_t _699 = _693 - _698;
 int32_t _700 = ~_697;
 int32_t _701 = _696 & _700;
 int32_t _702 = _699 + _701;
 int32_t _703 = _702 * 480;
 int32_t _704 = _703 + _output__1_min_0;
 int32_t _705 = _704 + 479;
 int32_t _706 = _output__1_min_0 + _output__1_extent_0;
 int32_t _707 = _706 + -1;
 int32_t _708 = min(_705, _707);
 int32_t _709 = _706 + -480;
 int32_t _710 = min(_output__1_min_0, _709);
 int32_t _711 = _708 - _710;
 int32_t _712 = _output__1_extent_1 + -1;
 int32_t _713 = _712 / 640;
 int32_t _714 = _713 * 640;
 int32_t _715 = _712 - _714;
 int32_t _716 = _715 >> 31;
 int32_t _717 = 640 >> 31;
 int32_t _718 = _716 & _717;
 int32_t _719 = _713 - _718;
 int32_t _720 = ~_717;
 int32_t _721 = _716 & _720;
 int32_t _722 = _719 + _721;
 int32_t _723 = _722 * 640;
 int32_t _724 = _723 + _output__1_min_1;
 int32_t _725 = _724 + 639;
 int32_t _726 = _output__1_min_1 + _output__1_extent_1;
 int32_t _727 = _726 + -1;
 int32_t _728 = min(_725, _727);
 int32_t _729 = _726 + -640;
 int32_t _730 = min(_output__1_min_1, _729);
 int32_t _731 = _728 - _730;
 if (_output__1_host_and_dev_are_null)
 {
  int32_t _732 = _711 + 1;
  int32_t _733 = _731 + 1;
  bool _734 = halide_rewrite_buffer(_output__1_buffer, 1, _710, _732, 1, _730, _733, _732, 0, 0, 0, 0, 0, 0);
  (void)_734;
 } // if _output__1_host_and_dev_are_null
 if (_p2___in_host_and_dev_are_null)
 {
  int32_t _735 = _output__1_extent_0 + 8;
  int32_t _736 = _output__1_extent_1 + 8;
  bool _737 = halide_rewrite_buffer(_p2___in_buffer, 1, _output__1_min_0, _735, 1, _output__1_min_1, _736, _735, 0, 0, 0, 0, 0, 0);
  (void)_737;
 } // if _p2___in_host_and_dev_are_null
 bool _738 = _output__1_host_and_dev_are_null || _p2___in_host_and_dev_are_null;
 bool _739 = !(_738);
 if (_739)
 {
  bool _740 = _output__1_elem_size == 1;
  if (!_740)   {
   int32_t _741 = halide_error_bad_elem_size(nullptr, "Output buffer output$1", "uint8", _output__1_elem_size, 1);
   return _741;
  }
  bool _742 = _p2___in_elem_size == 1;
  if (!_742)   {
   int32_t _743 = halide_error_bad_elem_size(nullptr, "Input buffer p2:in", "uint8", _p2___in_elem_size, 1);
   return _743;
  }
  bool _744 = _output__1_min_0 <= _710;
  int32_t _745 = _710 + _711;
  int32_t _746 = _745 - _output__1_extent_0;
  int32_t _747 = _746 + 1;
  bool _748 = _747 <= _output__1_min_0;
  bool _749 = _744 && _748;
  if (!_749)   {
   int32_t _750 = _710 + _711;
   int32_t _751 = _output__1_min_0 + _output__1_extent_0;
   int32_t _752 = _751 + -1;
   int32_t _753 = halide_error_access_out_of_bounds(nullptr, "Output buffer output$1", 0, _710, _750, _output__1_min_0, _752);
   return _753;
  }
  bool _754 = _output__1_min_1 <= _730;
  int32_t _755 = _730 + _731;
  int32_t _756 = _755 - _output__1_extent_1;
  int32_t _757 = _756 + 1;
  bool _758 = _757 <= _output__1_min_1;
  bool _759 = _754 && _758;
  if (!_759)   {
   int32_t _760 = _730 + _731;
   int32_t _761 = _output__1_min_1 + _output__1_extent_1;
   int32_t _762 = _761 + -1;
   int32_t _763 = halide_error_access_out_of_bounds(nullptr, "Output buffer output$1", 1, _730, _760, _output__1_min_1, _762);
   return _763;
  }
  bool _764 = _p2___in_min_0 <= _output__1_min_0;
  int32_t _765 = _output__1_min_0 + _output__1_extent_0;
  int32_t _766 = _765 - _p2___in_extent_0;
  int32_t _767 = _766 + 8;
  bool _768 = _767 <= _p2___in_min_0;
  bool _769 = _764 && _768;
  if (!_769)   {
   int32_t _770 = _output__1_min_0 + _output__1_extent_0;
   int32_t _771 = _770 + 7;
   int32_t _772 = _p2___in_min_0 + _p2___in_extent_0;
   int32_t _773 = _772 + -1;
   int32_t _774 = halide_error_access_out_of_bounds(nullptr, "Input buffer p2:in", 0, _output__1_min_0, _771, _p2___in_min_0, _773);
   return _774;
  }
  bool _775 = _p2___in_min_1 <= _output__1_min_1;
  int32_t _776 = _output__1_min_1 + _output__1_extent_1;
  int32_t _777 = _776 - _p2___in_extent_1;
  int32_t _778 = _777 + 8;
  bool _779 = _778 <= _p2___in_min_1;
  bool _780 = _775 && _779;
  if (!_780)   {
   int32_t _781 = _output__1_min_1 + _output__1_extent_1;
   int32_t _782 = _781 + 7;
   int32_t _783 = _p2___in_min_1 + _p2___in_extent_1;
   int32_t _784 = _783 + -1;
   int32_t _785 = halide_error_access_out_of_bounds(nullptr, "Input buffer p2:in", 1, _output__1_min_1, _782, _p2___in_min_1, _784);
   return _785;
  }
  bool _786 = _output__1_stride_0 == 1;
  if (!_786)   {
   int32_t _787 = halide_error_constraint_violated(nullptr, "output$1.stride.0", _output__1_stride_0, "1", 1);
   return _787;
  }
  bool _788 = _p2___in_stride_0 == 1;
  if (!_788)   {
   int32_t _789 = halide_error_constraint_violated(nullptr, "p2:in.stride.0", _p2___in_stride_0, "1", 1);
   return _789;
  }
  int64_t _790 = (int64_t)(_output__1_extent_1);
  int64_t _791 = (int64_t)(_output__1_extent_0);
  int64_t _792 = _790 * _791;
  int64_t _793 = (int64_t)(_p2___in_extent_1);
  int64_t _794 = (int64_t)(_p2___in_extent_0);
  int64_t _795 = _793 * _794;
  int64_t _796 = (int64_t)(2147483647);
  bool _797 = _791 <= _796;
  if (!_797)   {
   int64_t _798 = (int64_t)(_output__1_extent_0);
   int64_t _799 = (int64_t)(2147483647);
   int32_t _800 = halide_error_buffer_allocation_too_large(nullptr, "output$1", _798, _799);
   return _800;
  }
  int64_t _801 = (int64_t)(_output__1_extent_1);
  int64_t _802 = (int64_t)(_output__1_stride_1);
  int64_t _803 = _801 * _802;
  int64_t _804 = (int64_t)(2147483647);
  bool _805 = _803 <= _804;
  if (!_805)   {
   int64_t _806 = (int64_t)(_output__1_extent_1);
   int64_t _807 = (int64_t)(_output__1_stride_1);
   int64_t _808 = _806 * _807;
   int64_t _809 = (int64_t)(2147483647);
   int32_t _810 = halide_error_buffer_allocation_too_large(nullptr, "output$1", _808, _809);
   return _810;
  }
  int64_t _811 = (int64_t)(2147483647);
  bool _812 = _792 <= _811;
  if (!_812)   {
   int64_t _813 = (int64_t)(2147483647);
   int32_t _814 = halide_error_buffer_extents_too_large(nullptr, "output$1", _792, _813);
   return _814;
  }
  int64_t _815 = (int64_t)(_p2___in_extent_0);
  int64_t _816 = (int64_t)(2147483647);
  bool _817 = _815 <= _816;
  if (!_817)   {
   int64_t _818 = (int64_t)(_p2___in_extent_0);
   int64_t _819 = (int64_t)(2147483647);
   int32_t _820 = halide_error_buffer_allocation_too_large(nullptr, "p2:in", _818, _819);
   return _820;
  }
  int64_t _821 = (int64_t)(_p2___in_extent_1);
  int64_t _822 = (int64_t)(_p2___in_stride_1);
  int64_t _823 = _821 * _822;
  int64_t _824 = (int64_t)(2147483647);
  bool _825 = _823 <= _824;
  if (!_825)   {
   int64_t _826 = (int64_t)(_p2___in_extent_1);
   int64_t _827 = (int64_t)(_p2___in_stride_1);
   int64_t _828 = _826 * _827;
   int64_t _829 = (int64_t)(2147483647);
   int32_t _830 = halide_error_buffer_allocation_too_large(nullptr, "p2:in", _828, _829);
   return _830;
  }
  int64_t _831 = (int64_t)(2147483647);
  bool _832 = _795 <= _831;
  if (!_832)   {
   int64_t _833 = (int64_t)(2147483647);
   int32_t _834 = halide_error_buffer_extents_too_large(nullptr, "p2:in", _795, _833);
   return _834;
  }
  // produce output$1
  int32_t _835 = _output__1_extent_1 + 639;
  int32_t _836 = _835 / 640;
  int32_t _837 = _836 * 640;
  int32_t _838 = _835 - _837;
  int32_t _839 = _838 >> 31;
  int32_t _840 = 640 >> 31;
  int32_t _841 = _839 & _840;
  int32_t _842 = _836 - _841;
  int32_t _843 = ~_840;
  int32_t _844 = _839 & _843;
  int32_t _845 = _842 + _844;
  for (int _output__1_s0_y_yo = 0; _output__1_s0_y_yo < 0 + _845; _output__1_s0_y_yo++)
  {
   int32_t _846 = _output__1_s0_y_yo * 640;
   int32_t _847 = _846 + _output__1_min_1;
   int32_t _848 = _output__1_min_1 + _output__1_extent_1;
   int32_t _849 = _848 + -640;
   int32_t _850 = min(_847, _849);
   int32_t _851 = _output__1_extent_0 + 479;
   int32_t _852 = _851 / 480;
   int32_t _853 = _852 * 480;
   int32_t _854 = _851 - _853;
   int32_t _855 = _854 >> 31;
   int32_t _856 = 480 >> 31;
   int32_t _857 = _855 & _856;
   int32_t _858 = _852 - _857;
   int32_t _859 = ~_856;
   int32_t _860 = _855 & _859;
   int32_t _861 = _858 + _860;
   for (int _output__1_s0_x_xo = 0; _output__1_s0_x_xo < 0 + _861; _output__1_s0_x_xo++)
   {
    int32_t _862 = _output__1_s0_x_xo * 480;
    int32_t _863 = _862 + _output__1_min_0;
    int32_t _864 = _output__1_min_0 + _output__1_extent_0;
    int32_t _865 = _864 + -480;
    int32_t _866 = min(_863, _865);
    void *_867 = nullptr;
    int32_t _868 = _866 + -4;
    int32_t _869 = _850 + -4;
    buffer_t B2 = {0};
    B2.host = const_cast<uint8_t *>((const uint8_t *)(_867));
    B2.elem_size = 1;
    B2.min[0] = _868;
    B2.extent[0] = 488;
    B2.stride[0] = 1;
    B2.min[1] = _869;
    B2.extent[1] = 648;
    B2.stride[1] = 488;
    struct buffer_t *_870 = (&B2);
    int32_t _871 = halide_zynq_cma_alloc(_870);
    bool _872 = _871 == 0;
    if (!_872)     {
     return _871;
    }
    {
     void *_873 = ((buffer_t *)(_870))->host;
     uint8_t *_p2___in_bounded = (uint8_t *) (_873);
     // produce p2:in_bounded
     int32_t _874 = _850 + -4;
     for (int _p2___in_bounded_s0_y = _874; _p2___in_bounded_s0_y < _874 + 648; _p2___in_bounded_s0_y++)
     {
      int32_t _875 = _866 + -4;
      for (int _p2___in_bounded_s0_x = _875; _p2___in_bounded_s0_x < _875 + 488; _p2___in_bounded_s0_x++)
      {
       int32_t _876 = _p2___in_bounded_s0_x - _866;
       int32_t _877 = _p2___in_bounded_s0_y - _850;
       int32_t _878 = _877 * 488;
       int32_t _879 = _876 + _878;
       int32_t _880 = _879 + 1956;
       int32_t _881 = _p2___in_bounded_s0_y + 4;
       int32_t _882 = _881 * _p2___in_stride_1;
       int32_t _883 = _p2___in_bounded_s0_x + _882;
       int32_t _884 = _p2___in_min_1 * _p2___in_stride_1;
       int32_t _885 = _p2___in_min_0 + _884;
       int32_t _886 = _883 - _885;
       int32_t _887 = _886 + 4;
       uint8_t _888 = _p2___in[_887];
       _p2___in_bounded[_880] = _888;
      } // for _p2___in_bounded_s0_x
     } // for _p2___in_bounded_s0_y
     // consume p2:in_bounded
     void *_889 = nullptr;
     buffer_t B3 = {0};
     B3.host = const_cast<uint8_t *>((const uint8_t *)(_889));
     B3.elem_size = 1;
     B3.min[0] = _866;
     B3.extent[0] = 480;
     B3.stride[0] = 1;
     B3.min[1] = _850;
     B3.extent[1] = 640;
     B3.stride[1] = 480;
     struct buffer_t *_890 = (&B3);
     int32_t _891 = halide_zynq_cma_alloc(_890);
     bool _892 = _891 == 0;
     if (!_892)      {
      return _891;
     }
     {
      void *_893 = ((buffer_t *)(_890))->host;
      uint8_t *_hw_output__1 = (uint8_t *) (_893);
      // produce hw_output$1
      {
       cma_buffer_t _p2___in_bounded_stencil_update_stream;
       void *_894 = ((uint8_t *)_p2___in_bounded + 0);
       halide_zynq_subimage(_870, &_p2___in_bounded_stencil_update_stream, _894, 488, 648);
       (void)648;
       {
        cma_buffer_t _hw_output__1_stencil_stream;
        void *_895 = ((uint8_t *)_hw_output__1 + 0);
        halide_zynq_subimage(_890, &_hw_output__1_stencil_stream, _895, 480, 640);
        (void)640;
        cma_buffer_t _cma_bufs[2];
        _cma_bufs[0] = _p2___in_bounded_stencil_update_stream;
        _cma_bufs[1] = _hw_output__1_stencil_stream;
        int _process_id = halide_zynq_hwacc_launch(_cma_bufs);
        halide_zynq_hwacc_sync(_process_id);
       } // hw_output$1.stencil.stream
      } // p2:in_bounded.stencil_update.stream
      // consume hw_output$1
      for (int _output__1_s0_y_yi = 0; _output__1_s0_y_yi < 0 + 640; _output__1_s0_y_yi++)
      {
       for (int _output__1_s0_x_xi = 0; _output__1_s0_x_xi < 0 + 480; _output__1_s0_x_xi++)
       {
        int32_t _896 = _866 + _output__1_s0_x_xi;
        int32_t _897 = _850 + _output__1_s0_y_yi;
        int32_t _898 = _897 * _output__1_stride_1;
        int32_t _899 = _896 + _898;
        int32_t _900 = _output__1_min_1 * _output__1_stride_1;
        int32_t _901 = _output__1_min_0 + _900;
        int32_t _902 = _899 - _901;
        int32_t _903 = _output__1_s0_y_yi * 480;
        int32_t _904 = _output__1_s0_x_xi + _903;
        uint8_t _905 = _hw_output__1[_904];
        _output__1[_902] = _905;
       } // for _output__1_s0_x_xi
      } // for _output__1_s0_y_yi
      halide_zynq_cma_free(_890);
      (void)_890;
      halide_zynq_free(nullptr, _hw_output__1);
     } // alloc _hw_output__1
     halide_zynq_cma_free(_870);
     (void)_870;
     halide_zynq_free(nullptr, _p2___in_bounded);
    } // alloc _p2___in_bounded
   } // for _output__1_s0_x_xo
  } // for _output__1_s0_y_yo
  // consume output$1
 } // if _739
 return 0;
}


int pipeline_zynq(buffer_t *_p2___in_buffer, buffer_t *_output__1_buffer) HALIDE_FUNCTION_ATTRS {
 uint8_t *_p2___in = (uint8_t *)(_p2___in_buffer->host);
 (void)_p2___in;
 const bool _p2___in_host_and_dev_are_null = (_p2___in_buffer->host == nullptr) && (_p2___in_buffer->dev == 0);
 (void)_p2___in_host_and_dev_are_null;
 const int32_t _p2___in_min_0 = _p2___in_buffer->min[0];
 (void)_p2___in_min_0;
 const int32_t _p2___in_min_1 = _p2___in_buffer->min[1];
 (void)_p2___in_min_1;
 const int32_t _p2___in_min_2 = _p2___in_buffer->min[2];
 (void)_p2___in_min_2;
 const int32_t _p2___in_min_3 = _p2___in_buffer->min[3];
 (void)_p2___in_min_3;
 const int32_t _p2___in_extent_0 = _p2___in_buffer->extent[0];
 (void)_p2___in_extent_0;
 const int32_t _p2___in_extent_1 = _p2___in_buffer->extent[1];
 (void)_p2___in_extent_1;
 const int32_t _p2___in_extent_2 = _p2___in_buffer->extent[2];
 (void)_p2___in_extent_2;
 const int32_t _p2___in_extent_3 = _p2___in_buffer->extent[3];
 (void)_p2___in_extent_3;
 const int32_t _p2___in_stride_0 = _p2___in_buffer->stride[0];
 (void)_p2___in_stride_0;
 const int32_t _p2___in_stride_1 = _p2___in_buffer->stride[1];
 (void)_p2___in_stride_1;
 const int32_t _p2___in_stride_2 = _p2___in_buffer->stride[2];
 (void)_p2___in_stride_2;
 const int32_t _p2___in_stride_3 = _p2___in_buffer->stride[3];
 (void)_p2___in_stride_3;
 const int32_t _p2___in_elem_size = _p2___in_buffer->elem_size;
 (void)_p2___in_elem_size;
 uint8_t *_output__1 = (uint8_t *)(_output__1_buffer->host);
 (void)_output__1;
 const bool _output__1_host_and_dev_are_null = (_output__1_buffer->host == nullptr) && (_output__1_buffer->dev == 0);
 (void)_output__1_host_and_dev_are_null;
 const int32_t _output__1_min_0 = _output__1_buffer->min[0];
 (void)_output__1_min_0;
 const int32_t _output__1_min_1 = _output__1_buffer->min[1];
 (void)_output__1_min_1;
 const int32_t _output__1_min_2 = _output__1_buffer->min[2];
 (void)_output__1_min_2;
 const int32_t _output__1_min_3 = _output__1_buffer->min[3];
 (void)_output__1_min_3;
 const int32_t _output__1_extent_0 = _output__1_buffer->extent[0];
 (void)_output__1_extent_0;
 const int32_t _output__1_extent_1 = _output__1_buffer->extent[1];
 (void)_output__1_extent_1;
 const int32_t _output__1_extent_2 = _output__1_buffer->extent[2];
 (void)_output__1_extent_2;
 const int32_t _output__1_extent_3 = _output__1_buffer->extent[3];
 (void)_output__1_extent_3;
 const int32_t _output__1_stride_0 = _output__1_buffer->stride[0];
 (void)_output__1_stride_0;
 const int32_t _output__1_stride_1 = _output__1_buffer->stride[1];
 (void)_output__1_stride_1;
 const int32_t _output__1_stride_2 = _output__1_buffer->stride[2];
 (void)_output__1_stride_2;
 const int32_t _output__1_stride_3 = _output__1_buffer->stride[3];
 (void)_output__1_stride_3;
 const int32_t _output__1_elem_size = _output__1_buffer->elem_size;
 (void)_output__1_elem_size;
 int32_t _906 = __pipeline_zynq(_p2___in_buffer, _output__1_buffer);
 bool _907 = _906 == 0;
 if (!_907)  {
  return _906;
 }
 return 0;
}

#ifdef __cplusplus
}  // extern "C"
#endif
