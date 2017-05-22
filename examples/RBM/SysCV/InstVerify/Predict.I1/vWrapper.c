/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;
/* Structure forward decls */
struct l_class_OC_SysCArray1D;
struct l_class_OC_SysCArray2D;
struct l_class_OC_SysCArray2Dst;
struct l_class_OC_model_predict;
struct l_class_OC_sc_signal_bool;
struct l_class_OC_sc_signal_int32;
struct l_class_OC_sc_signal_u16;
struct l_struct_OC_rbm;
struct l_unnamed0;
struct l_unnamed1;
struct l_unnamed10;
struct l_unnamed11;
struct l_unnamed12;
struct l_unnamed13;
struct l_unnamed14;
struct l_unnamed15;
struct l_unnamed16;
struct l_unnamed17;
struct l_unnamed18;
struct l_unnamed19;
struct l_unnamed2;
struct l_unnamed20;
struct l_unnamed21;
struct l_unnamed3;
struct l_unnamed4;
struct l_unnamed5;
struct l_unnamed6;
struct l_unnamed7;
struct l_unnamed8;
struct l_unnamed9;

/* Typedefs */
typedef struct l_class_OC_SysCArray1D l_class_OC_SysCArray1D;
typedef struct l_class_OC_SysCArray2D l_class_OC_SysCArray2D;
typedef struct l_class_OC_SysCArray2Dst l_class_OC_SysCArray2Dst;
typedef struct l_class_OC_model_predict l_class_OC_model_predict;
typedef struct l_class_OC_sc_signal_bool l_class_OC_sc_signal_bool;
typedef struct l_class_OC_sc_signal_int32 l_class_OC_sc_signal_int32;
typedef struct l_class_OC_sc_signal_u16 l_class_OC_sc_signal_u16;
typedef struct l_struct_OC_rbm l_struct_OC_rbm;
typedef struct l_unnamed0 l_unnamed0;
typedef struct l_unnamed1 l_unnamed1;
typedef struct l_unnamed10 l_unnamed10;
typedef struct l_unnamed11 l_unnamed11;
typedef struct l_unnamed12 l_unnamed12;
typedef struct l_unnamed13 l_unnamed13;
typedef struct l_unnamed14 l_unnamed14;
typedef struct l_unnamed15 l_unnamed15;
typedef struct l_unnamed16 l_unnamed16;
typedef struct l_unnamed17 l_unnamed17;
typedef struct l_unnamed18 l_unnamed18;
typedef struct l_unnamed19 l_unnamed19;
typedef struct l_unnamed2 l_unnamed2;
typedef struct l_unnamed20 l_unnamed20;
typedef struct l_unnamed21 l_unnamed21;
typedef struct l_unnamed3 l_unnamed3;
typedef struct l_unnamed4 l_unnamed4;
typedef struct l_unnamed5 l_unnamed5;
typedef struct l_unnamed6 l_unnamed6;
typedef struct l_unnamed7 l_unnamed7;
typedef struct l_unnamed8 l_unnamed8;
typedef struct l_unnamed9 l_unnamed9;

/* Structure contents */
struct l_class_OC_SysCArray1D {
  unsigned char *field0;
};

struct l_class_OC_SysCArray2D {
  float *field0;
};

struct l_class_OC_SysCArray2Dst {
  unsigned char *field0;
  unsigned char *field1;
};

struct l_unnamed1 {
  unsigned int *field0;
};

struct l_unnamed2 {
  unsigned short *field0;
};

struct l_class_OC_model_predict {
  unsigned long long field0;
  struct l_class_OC_SysCArray1D field1;
  unsigned long long field2;
  unsigned long long field3;
  struct l_class_OC_SysCArray1D field4;
  unsigned long long field5;
  struct l_class_OC_SysCArray1D field6;
  unsigned long long field7;
  unsigned long long field8;
  unsigned long long field9;
  unsigned long long field10;
  unsigned long long field11;
  unsigned long long field12;
  unsigned long long field13;
  unsigned long long field14;
  unsigned long long field15;
  unsigned long long field16;
  unsigned long long field17;
  struct l_unnamed1 field18;
  unsigned long long field19;
  unsigned long long field20;
  unsigned long long field21;
  struct l_class_OC_SysCArray1D field22;
  unsigned long long field23;
  unsigned long long field24;
  unsigned long long field25;
  struct l_class_OC_SysCArray1D field26;
  unsigned long long field27;
  unsigned long long field28;
  unsigned long long field29;
  unsigned long long field30;
  unsigned long long field31;
  unsigned long long field32;
  unsigned long long field33;
  unsigned long long field34;
  struct l_unnamed2 field35;
  unsigned long long field36;
  unsigned long long field37;
  unsigned long long field38;
  unsigned long long field39;
  unsigned long long field40;
  unsigned long long field41;
  unsigned long long field42;
  unsigned long long field43;
  unsigned long long field44;
  unsigned long long field45;
  unsigned long long field46;
  unsigned long long field47;
  unsigned long long field48;
  unsigned long long field49;
  unsigned long long field50;
  unsigned long long field51;
  unsigned long long field52;
  unsigned long long field53;
  unsigned long long field54;
  unsigned long long field55;
};

struct l_class_OC_sc_signal_bool {
  unsigned char field0;
};

struct l_class_OC_sc_signal_int32 {
  unsigned int field0;
};

struct l_class_OC_sc_signal_u16 {
  unsigned short field0;
};

struct l_unnamed4 { unsigned int array[624]; };

struct l_struct_OC_rbm {
  struct l_class_OC_sc_signal_bool field0;
  struct l_class_OC_sc_signal_bool field1;
  struct l_class_OC_sc_signal_int32 field2;
  struct l_class_OC_sc_signal_int32 field3;
  struct l_class_OC_sc_signal_bool field4;
  struct l_class_OC_sc_signal_bool field5;
  struct l_class_OC_sc_signal_int32 field6;
  struct l_class_OC_sc_signal_int32 field7;
  struct l_class_OC_sc_signal_int32 field8;
  struct l_class_OC_sc_signal_bool field9;
  struct l_class_OC_sc_signal_bool field10;
  struct l_class_OC_sc_signal_int32 field11;
  struct l_class_OC_sc_signal_bool field12;
  struct l_class_OC_sc_signal_bool field13;
  struct l_class_OC_sc_signal_int32 field14;
  struct l_class_OC_sc_signal_int32 field15;
  struct l_class_OC_sc_signal_int32 field16;
  struct l_class_OC_sc_signal_int32 field17;
  struct l_class_OC_sc_signal_int32 field18;
  struct l_class_OC_sc_signal_int32 field19;
  struct l_class_OC_SysCArray2Dst field20;
  struct l_class_OC_SysCArray1D field21;
  struct l_class_OC_SysCArray1D field22;
  struct l_class_OC_SysCArray2D field23;
  struct l_class_OC_SysCArray1D field24;
  struct l_class_OC_SysCArray1D field25;
  struct l_class_OC_SysCArray2D field26;
  struct l_class_OC_SysCArray1D field27;
  struct l_class_OC_SysCArray2Dst field28;
  struct l_unnamed4 field29;
  struct l_class_OC_sc_signal_u16 field30;
  struct l_class_OC_sc_signal_u16 field31;
  struct l_class_OC_sc_signal_u16 field32;
  struct l_class_OC_sc_signal_u16 field33;
  struct l_class_OC_sc_signal_u16 field34;
  struct l_class_OC_sc_signal_u16 field35;
  struct l_class_OC_sc_signal_bool field36;
  struct l_class_OC_sc_signal_bool field37;
  struct l_class_OC_sc_signal_bool field38;
  struct l_class_OC_sc_signal_bool field39;
  struct l_class_OC_sc_signal_bool field40;
  struct l_class_OC_sc_signal_int32 field41;
  struct l_class_OC_sc_signal_bool field42;
  struct l_class_OC_sc_signal_bool field43;
  struct l_class_OC_sc_signal_bool field44;
  struct l_class_OC_sc_signal_bool field45;
};

struct l_unnamed0 { unsigned char array[6]; };

struct l_unnamed10 { unsigned char array[15]; };

struct l_unnamed11 { unsigned char array[10]; };

struct l_unnamed12 { unsigned char array[25]; };

struct l_unnamed13 { unsigned char array[13]; };

struct l_unnamed14 { unsigned char array[8]; };

struct l_unnamed15 { unsigned char array[21]; };

struct l_unnamed16 { unsigned char array[4]; };

struct l_unnamed17 { unsigned char array[9]; };

struct l_unnamed18 { unsigned char array[5]; };

struct l_unnamed19 { unsigned char array[19]; };

struct l_unnamed3 {
  unsigned int field0;
  void  (*field1) (void);
};

struct l_unnamed20 { struct l_unnamed3 array[1]; };

struct l_unnamed21 { float array[5]; };

struct l_unnamed5 { unsigned char array[16]; };

struct l_unnamed6 { unsigned char array[11]; };

struct l_unnamed7 { unsigned char array[17]; };

struct l_unnamed8 { unsigned char array[18]; };

struct l_unnamed9 { unsigned char array[20]; };


/* External Global Variable Declarations */
extern unsigned short divide_p1;
extern unsigned short divide_p2;
extern unsigned short divide_r;
extern unsigned short rand_r;
extern unsigned short sigmoid_p1;
extern unsigned short sigmoid_r;
extern unsigned short to_int_exp_p1;
extern unsigned short to_int_exp_r;
extern unsigned short round_p1;
extern unsigned short round_r;
extern unsigned char t;
extern struct l_class_OC_model_predict GM;
extern unsigned char *__dso_handle;
extern struct l_class_OC_sc_signal_bool _ZSt4cout;
extern unsigned int _ZSt4endl;
extern unsigned int cycleCnt;
extern unsigned char conf_done_inp;
extern unsigned int conf_num_hidden_inp;
extern unsigned int conf_num_visible_inp;
extern unsigned int conf_num_users_inp;
extern unsigned int conf_num_loops_inp;
extern unsigned int conf_num_testusers_inp;
extern unsigned int conf_num_movies_inp;
extern unsigned char rst_inp;
extern unsigned char rd_grant_inp;
extern unsigned int data_in_inp;
extern unsigned char wr_grant_inp;
extern unsigned int per_v_pc;
extern unsigned int predict_upc;
extern unsigned int upc;
extern struct l_struct_OC_rbm IMPL;

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
unsigned short _Z6dividell(unsigned long long llvm_cbe_cppVar_480, unsigned long long llvm_cbe_cppVar_481);
void __CPROVER_assert(bool , unsigned char *);
unsigned short _Z4randv(void);
unsigned short _Z7sigmoidl(unsigned long long llvm_cbe_cppVar_486);
unsigned short _Z10to_int_expl(unsigned long long llvm_cbe_cppVar_489);
unsigned short _Z5roundl(unsigned long long llvm_cbe_cppVar_1257);
bool _ZN13model_predict9assumps_0Elllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_predict18cppUpdateFun_countElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_predict17cppUpdateFun_doneElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_predict24cppUpdateFun_expectationElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN8type_memIjLj8EE2rdEl(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_addr) __ATTRIBUTE_WEAK__;
struct l_class_OC_SysCArray1D _ZN13model_predict24cppUpdateFun_hidden_unitElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN8type_memIbLj128EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned int __gxx_personality_v0(int vararg_dummy_arg,...);
void _Unwind_Resume_or_Rethrow(unsigned char *);
unsigned long long _ZN8type_memIhLj512EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) __ATTRIBUTE_WEAK__;
unsigned long long _ZN8type_memIhLj65536EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) __ATTRIBUTE_WEAK__;
struct l_class_OC_SysCArray1D *_ZN8type_memIbLj128EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj128EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj128EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZSt9terminatev(void);
unsigned long long _ZN13model_predict18cppUpdateFun_indexElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_predict19cppUpdateFun_jstateElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_predict21cppUpdateFun_per_v_pcElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
struct l_unnamed1 _ZN13model_predict17cppUpdateFun_pow2Elllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN8type_memIjLj8EEC1Ev(struct l_unnamed1 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
struct l_unnamed1 *_ZN8type_memIjLj8EEaSERKS0_(struct l_unnamed1 *llvm_cbe_this, struct l_unnamed1 *llvm_cbe_r) __ATTRIBUTE_WEAK__;
unsigned long long _ZN8type_memItLj8EE2rdEl(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_addr) __ATTRIBUTE_WEAK__;
void _ZN8type_memIjLj8EE2wrEll(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) __ATTRIBUTE_WEAK__;
void _ZN8type_memIjLj8EED1Ev(struct l_unnamed1 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned long long _ZN13model_predict26cppUpdateFun_predict_h_cntElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_predict31cppUpdateFun_predict_input_doneElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_predict24cppUpdateFun_predict_maxElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN8type_memIbLj128EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) __ATTRIBUTE_WEAK__;
struct l_class_OC_SysCArray1D _ZN13model_predict27cppUpdateFun_predict_resultElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN8type_memIhLj128EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
struct l_class_OC_SysCArray1D *_ZN8type_memIhLj128EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned long long _ZN13model_predict24cppUpdateFun_predict_sumElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_predict24cppUpdateFun_predict_upcElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_predict26cppUpdateFun_predict_v_cntElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
struct l_class_OC_SysCArray1D _ZN13model_predict27cppUpdateFun_predict_vectorElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN8type_memIbLj512EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
struct l_class_OC_SysCArray1D *_ZN8type_memIbLj512EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj512EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj512EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned long long _ZN13model_predict23cppUpdateFun_predictionElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN8type_memIbLj512EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) __ATTRIBUTE_WEAK__;
unsigned long long _ZN13model_predict22cppUpdateFun_sumOfpow2Elllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_predict16cppUpdateFun_upcElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
struct l_unnamed2 _ZN13model_predict28cppUpdateFun_visibleEnergiesElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN8type_memItLj8EEC1Ev(struct l_unnamed2 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
struct l_unnamed2 *_ZN8type_memItLj8EEaSERKS0_(struct l_unnamed2 *llvm_cbe_this, struct l_unnamed2 *llvm_cbe_r) __ATTRIBUTE_WEAK__;
void _ZN8type_memItLj8EE2wrEll(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) __ATTRIBUTE_WEAK__;
void _ZN8type_memItLj8EED1Ev(struct l_unnamed2 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned long long _ZN13model_predict24cppUpdateFun_wr_completeElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_predict21cppUpdateFun_wr_indexElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_predict22cppUpdateFun_wr_lengthElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_predict23cppUpdateFun_wr_requestElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN13model_predict6updateElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
static void __cxx_global_var_init(void);
void _ZN13model_predictC1Ev(struct l_class_OC_model_predict *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN13model_predictD1Ev(struct l_class_OC_model_predict *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned int __cxa_atexit(void  (*) (unsigned char *), unsigned char *, unsigned char *);
void _Z4waitv(void);
void _Z15reset_signal_isib(unsigned int , bool );
void _Z14set_stack_sizei(unsigned int );
unsigned long long _Z8_c_16_15f(float llvm_cbe_in);
float _Z8_b_16_15l(unsigned long long llvm_cbe_in);
void _ZN3rbm11predict_rbmEv(struct l_struct_OC_rbm *llvm_cbe_this);
bool _ZN14sc_signal_boolaSERKb(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_d) __ATTRIBUTE_WEAK__;
void _ZN14sc_signal_bool5writeERKb(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_d) __ATTRIBUTE_WEAK__;
bool _ZN14sc_signal_bool4readEv(struct l_class_OC_sc_signal_bool *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN13sc_signal_u165writeERKt(struct l_class_OC_sc_signal_u16 *llvm_cbe_this, unsigned short *llvm_cbe_d) __ATTRIBUTE_WEAK__;
unsigned short _ZN13sc_signal_u164readEv(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN3rbm27activateHiddenUnits_predictEbtt(struct l_struct_OC_rbm *llvm_cbe_this, bool llvm_cbe_pingpong, unsigned short llvm_cbe_nh, unsigned short llvm_cbe_nv);
void _ZN3rbm28activateVisibleUnits_predictEtt(struct l_struct_OC_rbm *llvm_cbe_this, unsigned short llvm_cbe_nh, unsigned short llvm_cbe_nv);
unsigned char *_ZN11SysCArray1DIbLj512EEixEj(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned int llvm_cbe_idx) __ATTRIBUTE_WEAK__;
unsigned char *_ZN13SysCArray2DstIhLj2ELj128EEixEj(struct l_class_OC_SysCArray2Dst *llvm_cbe_this, unsigned int llvm_cbe_Xidx) __ATTRIBUTE_WEAK__;
unsigned char *_ZN13SysCArray2DstIhLj2ELj512EEixEj(struct l_class_OC_SysCArray2Dst *llvm_cbe_this, unsigned int llvm_cbe_Xidx) __ATTRIBUTE_WEAK__;
float *_ZN11SysCArray2DIfLj501ELj101EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) __ATTRIBUTE_WEAK__;
unsigned char *_ZN11SysCArray1DIbLj128EEixEj(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned int llvm_cbe_idx) __ATTRIBUTE_WEAK__;
unsigned int _ZN13sc_signal_u324readEv(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
bool __CPROVER_array_equal(unsigned char *, unsigned char *);
void _ZN13sc_signal_u325writeERKj(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned int *llvm_cbe_d) __ATTRIBUTE_WEAK__;
void __CPROVER_array_copy(unsigned char *, unsigned char *);
void __CPROVER_assume(bool );
float *_ZN11SysCArray1DIfLj5EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_idx) __ATTRIBUTE_WEAK__;
static void __cxx_global_var_init30(void);
void _ZN3rbmC1Ev(struct l_struct_OC_rbm *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned int main(void);
void _ZN8type_memItLj8EEC2Ev(struct l_unnamed2 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned char *__CPROVER_malloc(unsigned long long );
void _ZN8type_memIbLj512EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIjLj8EEC2Ev(struct l_unnamed1 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj128EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memItLj8EED2Ev(struct l_unnamed2 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj512EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIjLj8EED2Ev(struct l_unnamed1 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj128EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN3rbmC2Ev(struct l_struct_OC_rbm *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN14sc_signal_boolC1EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) __ATTRIBUTE_WEAK__;
void _ZN13sc_signal_u32C1EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) __ATTRIBUTE_WEAK__;
void _ZN13SysCArray2DstIhLj2ELj512EEC1Ev(struct l_class_OC_SysCArray2Dst *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray1DIbLj512EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray1DIbLj128EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray2DIfLj501ELj101EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray2DIbLj501ELj101EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray1DIfLj5EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN13SysCArray2DstIhLj2ELj128EEC1Ev(struct l_class_OC_SysCArray2Dst *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN13sc_signal_u16C1Ev(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN14sc_signal_boolC1Ev(struct l_class_OC_sc_signal_bool *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN15sc_signal_int32C1Ev(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned char *_ZN14sc_signal_boolcvRbEv(struct l_class_OC_sc_signal_bool *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN15sc_signal_int32C2Ev(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN14sc_signal_boolC2Ev(struct l_class_OC_sc_signal_bool *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN13sc_signal_u16C2Ev(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN13SysCArray2DstIhLj2ELj128EEC2Ev(struct l_class_OC_SysCArray2Dst *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray1DIfLj5EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray2DIbLj501ELj101EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray2DIfLj501ELj101EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray1DIbLj128EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray1DIbLj512EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN13SysCArray2DstIhLj2ELj512EEC2Ev(struct l_class_OC_SysCArray2Dst *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN13sc_signal_u32C2EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) __ATTRIBUTE_WEAK__;
void _ZN14sc_signal_boolC2EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) __ATTRIBUTE_WEAK__;
void _ZN13model_predictD2Ev(struct l_class_OC_model_predict *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj65536EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj65536EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN13model_predictC2Ev(struct l_class_OC_model_predict *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj65536EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj128EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIjLj8EEC1El(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj512EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memItLj8EEC1El(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memItLj8EEC2El(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj512EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIjLj8EEC2El(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj128EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj65536EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
static void _GLOBAL__I_a(void) __ATTRIBUTE_CTOR__;
void abort(void);


/* Global Variable Declarations */
extern unsigned short divide_p1;
extern unsigned short divide_p2;
extern unsigned short divide_r;
extern unsigned short rand_r;
extern unsigned short sigmoid_p1;
extern unsigned short sigmoid_r;
extern unsigned short to_int_exp_p1;
extern unsigned short to_int_exp_r;
extern unsigned short round_p1;
extern unsigned short round_r;
extern unsigned char t;
static struct l_unnamed0 _OC_str;
extern struct l_class_OC_model_predict GM;
extern struct l_class_OC_sc_signal_bool _ZSt4cout;
extern unsigned int _ZSt4endl;
extern unsigned char conf_done_inp;
extern unsigned int conf_num_hidden_inp;
extern unsigned int conf_num_visible_inp;
extern unsigned int conf_num_users_inp;
extern unsigned int conf_num_loops_inp;
extern unsigned int conf_num_testusers_inp;
extern unsigned int conf_num_movies_inp;
extern unsigned char rst_inp;
extern unsigned char rd_grant_inp;
extern unsigned int data_in_inp;
extern unsigned char wr_grant_inp;
extern unsigned int per_v_pc;
extern unsigned int predict_upc;
extern unsigned int upc;
static struct l_unnamed5 _OC_str1;
static struct l_unnamed6 _OC_str2;
static struct l_unnamed7 _OC_str3;
static struct l_unnamed8 _OC_str4;
static struct l_unnamed5 _OC_str5;
static struct l_unnamed5 _OC_str6;
static struct l_unnamed9 _OC_str7;
static struct l_unnamed7 _OC_str8;
static struct l_unnamed10 _OC_str9;
static struct l_unnamed5 _OC_str10;
static struct l_unnamed7 _OC_str11;
static struct l_unnamed7 _OC_str12;
static struct l_unnamed10 _OC_str13;
static struct l_unnamed5 _OC_str14;
static struct l_unnamed10 _OC_str15;
static struct l_unnamed11 _OC_str16;
static struct l_unnamed12 _OC_str17;
static struct l_unnamed8 _OC_str18;
static struct l_unnamed8 _OC_str19;
static struct l_unnamed5 _OC_str20;
static struct l_unnamed10 _OC_str21;
static struct l_unnamed13 _OC_str22;
static struct l_unnamed8 _OC_str23;
static struct l_unnamed9 _OC_str24;
static struct l_unnamed9 _OC_str25;
static struct l_unnamed6 _OC_str26;
static struct l_unnamed15 _OC_str27;
static struct l_unnamed8 _OC_str28;
static struct l_unnamed14 _OC_str29;
extern struct l_struct_OC_rbm IMPL;
static struct l_unnamed16 _OC_str31;
static struct l_unnamed16 _OC_str32;
static struct l_unnamed17 _OC_str33;
static struct l_unnamed11 _OC_str34;
static struct l_unnamed6 _OC_str35;
static struct l_unnamed17 _OC_str36;
static struct l_unnamed14 _OC_str37;
static struct l_unnamed17 _OC_str38;
static struct l_unnamed11 _OC_str39;
static struct l_unnamed6 _OC_str40;
static struct l_unnamed17 _OC_str41;
static struct l_unnamed17 _OC_str42;
static struct l_unnamed18 _OC_str43;
static struct l_unnamed11 _OC_str44;
static struct l_unnamed5 _OC_str45;
static struct l_unnamed7 _OC_str46;
static struct l_unnamed10 _OC_str47;
static struct l_unnamed10 _OC_str48;
static struct l_unnamed19 _OC_str49;
static struct l_unnamed5 _OC_str50;


/* Global Variable Definitions and Initialization */
unsigned short divide_p1;
unsigned short divide_p2;
unsigned short divide_r;
unsigned short rand_r;
unsigned short sigmoid_p1;
unsigned short sigmoid_r;
unsigned short to_int_exp_p1;
unsigned short to_int_exp_r;
unsigned short round_p1;
unsigned short round_r;
unsigned char t;
static struct l_unnamed0 _OC_str = { "test3" };
struct l_class_OC_model_predict GM;
struct l_class_OC_sc_signal_bool _ZSt4cout;
unsigned int _ZSt4endl;
unsigned char conf_done_inp;
unsigned int conf_num_hidden_inp;
unsigned int conf_num_visible_inp;
unsigned int conf_num_users_inp;
unsigned int conf_num_loops_inp;
unsigned int conf_num_testusers_inp;
unsigned int conf_num_movies_inp;
unsigned char rst_inp;
unsigned char rd_grant_inp;
unsigned int data_in_inp;
unsigned char wr_grant_inp;
unsigned int per_v_pc;
unsigned int predict_upc;
unsigned int upc;
static struct l_unnamed5 _OC_str1 = { "init_done_match" };
static struct l_unnamed6 _OC_str2 = { "done_match" };
static struct l_unnamed7 _OC_str3 = { "num_hidden_match" };
static struct l_unnamed8 _OC_str4 = { "num_visible_match" };
static struct l_unnamed5 _OC_str5 = { "num_users_match" };
static struct l_unnamed5 _OC_str6 = { "num_loops_match" };
static struct l_unnamed9 _OC_str7 = { "num_testusers_match" };
static struct l_unnamed7 _OC_str8 = { "num_movies_match" };
static struct l_unnamed10 _OC_str9 = { "rd_index_match" };
static struct l_unnamed5 _OC_str10 = { "rd_length_match" };
static struct l_unnamed7 _OC_str11 = { "rd_request_match" };
static struct l_unnamed7 _OC_str12 = { "wr_request_match" };
static struct l_unnamed10 _OC_str13 = { "wr_index_match" };
static struct l_unnamed5 _OC_str14 = { "wr_length_match" };
static struct l_unnamed10 _OC_str15 = { "data_out_match" };
static struct l_unnamed11 _OC_str16 = { "upc_match" };
static struct l_unnamed12 _OC_str17 = { "predict_input_done_match" };
static struct l_unnamed8 _OC_str18 = { "predict_sum_match" };
static struct l_unnamed8 _OC_str19 = { "predict_max_match" };
static struct l_unnamed5 _OC_str20 = { "sumOfpow2_match" };
static struct l_unnamed10 _OC_str21 = { "per_v_pc_match" };
static struct l_unnamed13 _OC_str22 = { "jstate_match" };
static struct l_unnamed8 _OC_str23 = { "predict_upc_match" };
static struct l_unnamed9 _OC_str24 = { "predict_v_cnt_match" };
static struct l_unnamed9 _OC_str25 = { "predict_h_cnt_match" };
static struct l_unnamed6 _OC_str26 = { "data_match" };
static struct l_unnamed15 _OC_str27 = { "predict_result_match" };
static struct l_unnamed8 _OC_str28 = { "hidden_unit_match" };
static struct l_unnamed14 _OC_str29 = { "ind-inv" };
struct l_struct_OC_rbm IMPL;
static struct l_unnamed16 _OC_str31 = { "clk" };
static struct l_unnamed16 _OC_str32 = { "rst" };
static struct l_unnamed17 _OC_str33 = { "rd_index" };
static struct l_unnamed11 _OC_str34 = { "rd_length" };
static struct l_unnamed6 _OC_str35 = { "rd_request" };
static struct l_unnamed17 _OC_str36 = { "rd_grant" };
static struct l_unnamed14 _OC_str37 = { "data_in" };
static struct l_unnamed17 _OC_str38 = { "wr_index" };
static struct l_unnamed11 _OC_str39 = { "wr_length" };
static struct l_unnamed6 _OC_str40 = { "wr_request" };
static struct l_unnamed17 _OC_str41 = { "wr_grant" };
static struct l_unnamed17 _OC_str42 = { "data_out" };
static struct l_unnamed18 _OC_str43 = { "done" };
static struct l_unnamed11 _OC_str44 = { "cond_done" };
static struct l_unnamed5 _OC_str45 = { "conf_num_hidden" };
static struct l_unnamed7 _OC_str46 = { "conf_num_visible" };
static struct l_unnamed10 _OC_str47 = { "conf_num_users" };
static struct l_unnamed10 _OC_str48 = { "conf_num_loops" };
static struct l_unnamed19 _OC_str49 = { "conf_num_testusers" };
static struct l_unnamed5 _OC_str50 = { "conf_num_movies" };


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

unsigned short _Z6dividell(unsigned long long llvm_cbe_cppVar_480, unsigned long long llvm_cbe_cppVar_481) {
  unsigned long long llvm_cbe_tmp__1;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2;    /* Address-exposed local */
  unsigned long long llvm_cbe_ret;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3;
  unsigned short llvm_cbe_tmp__4;
  unsigned long long llvm_cbe_tmp__5;
  unsigned short llvm_cbe_tmp__6;
  unsigned short llvm_cbe_tmp__7;
  unsigned char llvm_cbe_tmp__8;
  unsigned long long llvm_cbe_tmp__9;
  unsigned long long llvm_cbe_tmp__10;
  unsigned long long llvm_cbe_tmp__11;
  unsigned long long llvm_cbe_tmp__12;

  *(&llvm_cbe_tmp__1) = llvm_cbe_cppVar_480;
  *(&llvm_cbe_tmp__2) = llvm_cbe_cppVar_481;
  llvm_cbe_tmp__3 = *(&llvm_cbe_tmp__1);
  llvm_cbe_tmp__4 = *(&divide_p1);
  if ((llvm_cbe_tmp__3 == (((unsigned long long )(unsigned short )llvm_cbe_tmp__4)))) {
    goto llvm_cbe_tmp__13;
  } else {
    goto llvm_cbe_tmp__14;
  }

llvm_cbe_tmp__13:
  llvm_cbe_tmp__5 = *(&llvm_cbe_tmp__2);
  llvm_cbe_tmp__6 = *(&divide_p2);
  if ((llvm_cbe_tmp__5 == (((unsigned long long )(unsigned short )llvm_cbe_tmp__6)))) {
    goto llvm_cbe_tmp__15;
  } else {
    goto llvm_cbe_tmp__14;
  }

llvm_cbe_tmp__15:
  llvm_cbe_tmp__7 = *(&divide_r);
  *(&llvm_cbe_ret) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__7));
  goto llvm_cbe_tmp__16;

llvm_cbe_tmp__14:
  llvm_cbe_tmp__8 = *(&t);
  if (((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__8&1u))&1)))) == 1u)) {
    goto llvm_cbe_tmp__17;
  } else {
    goto llvm_cbe_tmp__16;
  }

llvm_cbe_tmp__17:
  __CPROVER_assert(0, ((&_OC_str.array[((signed int )0u)])));
  goto llvm_cbe_tmp__16;

llvm_cbe_tmp__16:
  *(&t) = ((unsigned char )1);
  llvm_cbe_tmp__9 = *(&llvm_cbe_tmp__1);
  *(&divide_p1) = (((unsigned short )llvm_cbe_tmp__9));
  llvm_cbe_tmp__10 = *(&llvm_cbe_tmp__2);
  *(&divide_p2) = (((unsigned short )llvm_cbe_tmp__10));
  llvm_cbe_tmp__11 = *(&llvm_cbe_ret);
  *(&divide_r) = (((unsigned short )llvm_cbe_tmp__11));
  llvm_cbe_tmp__12 = *(&llvm_cbe_ret);
  return (((unsigned short )llvm_cbe_tmp__12));
}


unsigned short _Z4randv(void) {
  unsigned short llvm_cbe_tmp__18;

  llvm_cbe_tmp__18 = *(&rand_r);
  return llvm_cbe_tmp__18;
}


unsigned short _Z7sigmoidl(unsigned long long llvm_cbe_cppVar_486) {
  unsigned long long llvm_cbe_tmp__19;    /* Address-exposed local */
  unsigned long long llvm_cbe_ret;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__20;
  unsigned long long llvm_cbe_tmp__21;
  unsigned short llvm_cbe_tmp__22;
  unsigned long long llvm_cbe_tmp__23;
  unsigned long long llvm_cbe_tmp__24;
  unsigned long long llvm_cbe_tmp__25;

  *(&llvm_cbe_tmp__19) = llvm_cbe_cppVar_486;
  llvm_cbe_tmp__20 = *(&sigmoid_p1);
  llvm_cbe_tmp__21 = *(&llvm_cbe_tmp__19);
  if (((((unsigned long long )(unsigned short )llvm_cbe_tmp__20)) == llvm_cbe_tmp__21)) {
    goto llvm_cbe_tmp__26;
  } else {
    goto llvm_cbe_tmp__27;
  }

llvm_cbe_tmp__26:
  llvm_cbe_tmp__22 = *(&sigmoid_r);
  *(&llvm_cbe_ret) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__22));
  goto llvm_cbe_tmp__27;

llvm_cbe_tmp__27:
  llvm_cbe_tmp__23 = *(&llvm_cbe_ret);
  *(&sigmoid_r) = (((unsigned short )llvm_cbe_tmp__23));
  llvm_cbe_tmp__24 = *(&llvm_cbe_tmp__19);
  *(&sigmoid_p1) = (((unsigned short )llvm_cbe_tmp__24));
  llvm_cbe_tmp__25 = *(&llvm_cbe_ret);
  return (((unsigned short )llvm_cbe_tmp__25));
}


unsigned short _Z10to_int_expl(unsigned long long llvm_cbe_cppVar_489) {
  unsigned long long llvm_cbe_tmp__28;    /* Address-exposed local */
  unsigned long long llvm_cbe_ret;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__29;
  unsigned long long llvm_cbe_tmp__30;
  unsigned short llvm_cbe_tmp__31;
  unsigned long long llvm_cbe_tmp__32;
  unsigned long long llvm_cbe_tmp__33;
  unsigned long long llvm_cbe_tmp__34;

  *(&llvm_cbe_tmp__28) = llvm_cbe_cppVar_489;
  llvm_cbe_tmp__29 = *(&to_int_exp_p1);
  llvm_cbe_tmp__30 = *(&llvm_cbe_tmp__28);
  if (((((unsigned long long )(unsigned short )llvm_cbe_tmp__29)) == llvm_cbe_tmp__30)) {
    goto llvm_cbe_tmp__35;
  } else {
    goto llvm_cbe_tmp__36;
  }

llvm_cbe_tmp__35:
  llvm_cbe_tmp__31 = *(&to_int_exp_r);
  *(&llvm_cbe_ret) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__31));
  goto llvm_cbe_tmp__36;

llvm_cbe_tmp__36:
  llvm_cbe_tmp__32 = *(&llvm_cbe_ret);
  *(&to_int_exp_r) = (((unsigned short )llvm_cbe_tmp__32));
  llvm_cbe_tmp__33 = *(&llvm_cbe_tmp__28);
  *(&to_int_exp_p1) = (((unsigned short )llvm_cbe_tmp__33));
  llvm_cbe_tmp__34 = *(&llvm_cbe_ret);
  return (((unsigned short )llvm_cbe_tmp__34));
}


unsigned short _Z5roundl(unsigned long long llvm_cbe_cppVar_1257) {
  unsigned long long llvm_cbe_tmp__37;    /* Address-exposed local */
  unsigned long long llvm_cbe_ret;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__38;
  unsigned short llvm_cbe_tmp__39;
  unsigned short llvm_cbe_tmp__40;
  unsigned long long llvm_cbe_tmp__41;
  unsigned long long llvm_cbe_tmp__42;
  unsigned long long llvm_cbe_tmp__43;

  *(&llvm_cbe_tmp__37) = llvm_cbe_cppVar_1257;
  llvm_cbe_tmp__38 = *(&llvm_cbe_tmp__37);
  llvm_cbe_tmp__39 = *(&round_p1);
  if ((llvm_cbe_tmp__38 == (((unsigned long long )(unsigned short )llvm_cbe_tmp__39)))) {
    goto llvm_cbe_tmp__44;
  } else {
    goto llvm_cbe_tmp__45;
  }

llvm_cbe_tmp__44:
  llvm_cbe_tmp__40 = *(&round_r);
  *(&llvm_cbe_ret) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__40));
  goto llvm_cbe_tmp__45;

llvm_cbe_tmp__45:
  llvm_cbe_tmp__41 = *(&llvm_cbe_ret);
  *(&round_r) = (((unsigned short )llvm_cbe_tmp__41));
  llvm_cbe_tmp__42 = *(&llvm_cbe_tmp__37);
  *(&round_p1) = (((unsigned short )llvm_cbe_tmp__42));
  llvm_cbe_tmp__43 = *(&llvm_cbe_ret);
  return (((unsigned short )llvm_cbe_tmp__43));
}


bool _ZN13model_predict9assumps_0Elllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__46;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__47;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__48;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__49;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__50;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__51;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__52;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__53;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__54;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__55;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__56;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__57;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2166;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2167;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__58;
  unsigned long long llvm_cbe_tmp__59;
  unsigned char llvm_cbe_tmp__60;

  *(&llvm_cbe_tmp__46) = llvm_cbe_this;
  *(&llvm_cbe_tmp__47) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__48) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__49) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__50) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__51) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__52) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__53) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__54) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__55) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__56) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__57) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__58 = *(&llvm_cbe_tmp__46);
  llvm_cbe_tmp__59 = *((&llvm_cbe_tmp__58->field20));
  *(&llvm_cbe_cppVar_2167) = (((unsigned char )(bool )(llvm_cbe_tmp__59 == 1ull)));
  llvm_cbe_tmp__60 = *(&llvm_cbe_cppVar_2167);
  return (((((bool )llvm_cbe_tmp__60&1u))&1));
}


unsigned long long _ZN13model_predict18cppUpdateFun_countElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__61;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__62;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__63;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__64;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__65;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__66;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__67;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__68;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__69;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__70;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__71;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__72;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1287;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1265;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1266;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1269;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1270;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1289;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1290;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1297;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1298;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1267;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1284;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1285;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1275;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1276;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1277;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1278;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1279;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1280;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1281;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1282;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1272;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1273;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1274;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1283;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1286;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1271;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1292;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1293;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1294;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1295;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1291;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1296;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1288;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1268;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1264;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__73;
  unsigned long long llvm_cbe_tmp__74;
  unsigned char llvm_cbe_tmp__75;
  unsigned long long llvm_cbe_tmp__76;
  unsigned char llvm_cbe_tmp__77;
  unsigned long long llvm_cbe_tmp__78;
  unsigned char llvm_cbe_tmp__79;
  unsigned char llvm_cbe_tmp__80;
  bool llvm_cbe_tmp__81;
  bool llvm_cbe_tmp__82;
  bool llvm_cbe_tmp__82__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__83;
  unsigned long long llvm_cbe_tmp__84;
  unsigned long long llvm_cbe_tmp__85;
  unsigned long long llvm_cbe_tmp__86;
  unsigned long long llvm_cbe_tmp__87;
  unsigned long long llvm_cbe_tmp__88;
  unsigned long long llvm_cbe_tmp__89;
  unsigned long long llvm_cbe_tmp__90;
  unsigned long long llvm_cbe_tmp__91;
  unsigned char llvm_cbe_tmp__92;
  unsigned char llvm_cbe_tmp__93;
  bool llvm_cbe_tmp__94;
  bool llvm_cbe_tmp__95;
  bool llvm_cbe_tmp__95__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__96;
  unsigned char llvm_cbe_tmp__97;
  bool llvm_cbe_tmp__98;
  bool llvm_cbe_tmp__99;
  bool llvm_cbe_tmp__99__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__100;
  unsigned char llvm_cbe_tmp__101;
  unsigned char llvm_cbe_tmp__102;
  bool llvm_cbe_tmp__103;
  bool llvm_cbe_tmp__104;
  bool llvm_cbe_tmp__104__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__105;
  unsigned long long llvm_cbe_tmp__106;
  unsigned long long llvm_cbe_tmp__107;
  unsigned long long llvm_cbe_tmp__108;
  unsigned char llvm_cbe_tmp__109;
  unsigned long long llvm_cbe_tmp__110;
  unsigned char llvm_cbe_tmp__111;
  unsigned long long llvm_cbe_tmp__112;
  unsigned long long llvm_cbe_tmp__113;
  unsigned long long llvm_cbe_tmp__114;
  unsigned long long llvm_cbe_tmp__115;
  unsigned long long llvm_cbe_tmp__116;
  unsigned long long llvm_cbe_tmp__117;
  unsigned long long llvm_cbe_tmp__118;
  unsigned long long llvm_cbe_tmp__119;
  unsigned long long llvm_cbe_tmp__120;
  unsigned long long llvm_cbe_tmp__121;
  unsigned long long llvm_cbe_tmp__122;

  *(&llvm_cbe_tmp__61) = llvm_cbe_this;
  *(&llvm_cbe_tmp__62) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__63) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__64) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__65) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__66) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__67) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__68) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__69) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__70) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__71) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__72) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__73 = *(&llvm_cbe_tmp__61);
  llvm_cbe_tmp__74 = *((&llvm_cbe_tmp__73->field24));
  *(&llvm_cbe_cppVar_1266) = (((unsigned char )(bool )(llvm_cbe_tmp__74 == 0ull)));
  llvm_cbe_tmp__75 = *(&llvm_cbe_cppVar_1266);
  if ((((((bool )llvm_cbe_tmp__75&1u))&1))) {
    goto llvm_cbe_tmp__123;
  } else {
    goto llvm_cbe_tmp__124;
  }

llvm_cbe_tmp__123:
  *(&llvm_cbe_cppVar_1264) = 0ull;
  goto llvm_cbe_tmp__125;

llvm_cbe_tmp__124:
  llvm_cbe_tmp__76 = *((&llvm_cbe_tmp__73->field24));
  *(&llvm_cbe_cppVar_1270) = (((unsigned char )(bool )(llvm_cbe_tmp__76 == 1ull)));
  llvm_cbe_tmp__77 = *(&llvm_cbe_cppVar_1270);
  if ((((((bool )llvm_cbe_tmp__77&1u))&1))) {
    goto llvm_cbe_tmp__126;
  } else {
    goto llvm_cbe_tmp__127;
  }

llvm_cbe_tmp__126:
  llvm_cbe_tmp__78 = *((&llvm_cbe_tmp__73->field17));
  *(&llvm_cbe_cppVar_1273) = (((unsigned char )(bool )(llvm_cbe_tmp__78 == 4ull)));
  llvm_cbe_tmp__79 = *(&llvm_cbe_cppVar_1270);
  if ((((((bool )llvm_cbe_tmp__79&1u))&1))) {
    goto llvm_cbe_tmp__128;
  } else {
    llvm_cbe_tmp__82__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__129;
  }

llvm_cbe_tmp__128:
  llvm_cbe_tmp__80 = *(&llvm_cbe_cppVar_1273);
  llvm_cbe_tmp__81 = ((((bool )llvm_cbe_tmp__80&1u))&1);
  llvm_cbe_tmp__82__PHI_TEMPORARY = llvm_cbe_tmp__81;   /* for PHI node */
  goto llvm_cbe_tmp__129;

llvm_cbe_tmp__129:
  llvm_cbe_tmp__82 = ((llvm_cbe_tmp__82__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1274) = (((unsigned char )(bool )llvm_cbe_tmp__82));
  llvm_cbe_tmp__83 = *((&llvm_cbe_tmp__73->field25));
  *(&llvm_cbe_cppVar_1276) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__83) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__84 = *(&llvm_cbe_cppVar_1276);
  llvm_cbe_tmp__85 = *((&llvm_cbe_tmp__73->field41));
  *(&llvm_cbe_cppVar_1276) = (llvm_cbe_tmp__84 & llvm_cbe_tmp__85);
  llvm_cbe_tmp__86 = *(&llvm_cbe_cppVar_1276);
  llvm_cbe_tmp__87 = *((&llvm_cbe_tmp__73->field16));
  *(&llvm_cbe_cppVar_1277) = (((unsigned char )(bool )(llvm_cbe_tmp__86 == llvm_cbe_tmp__87)));
  llvm_cbe_tmp__88 = *((&llvm_cbe_tmp__73->field25));
  *(&llvm_cbe_cppVar_1279) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__88) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__89 = *(&llvm_cbe_cppVar_1279);
  llvm_cbe_tmp__90 = *((&llvm_cbe_tmp__73->field41));
  *(&llvm_cbe_cppVar_1279) = (llvm_cbe_tmp__89 & llvm_cbe_tmp__90);
  llvm_cbe_tmp__91 = *(&llvm_cbe_cppVar_1279);
  *(&llvm_cbe_cppVar_1281) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__91) >= ((signed long long )500ull))));
  llvm_cbe_tmp__92 = *(&llvm_cbe_cppVar_1277);
  if ((((((bool )llvm_cbe_tmp__92&1u))&1))) {
    llvm_cbe_tmp__95__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__130;
  } else {
    goto llvm_cbe_tmp__131;
  }

llvm_cbe_tmp__131:
  llvm_cbe_tmp__93 = *(&llvm_cbe_cppVar_1281);
  llvm_cbe_tmp__94 = ((((bool )llvm_cbe_tmp__93&1u))&1);
  llvm_cbe_tmp__95__PHI_TEMPORARY = llvm_cbe_tmp__94;   /* for PHI node */
  goto llvm_cbe_tmp__130;

llvm_cbe_tmp__130:
  llvm_cbe_tmp__95 = ((llvm_cbe_tmp__95__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1282) = (((unsigned char )(bool )llvm_cbe_tmp__95));
  llvm_cbe_tmp__96 = *(&llvm_cbe_cppVar_1274);
  if ((((((bool )llvm_cbe_tmp__96&1u))&1))) {
    goto llvm_cbe_tmp__132;
  } else {
    llvm_cbe_tmp__99__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__133;
  }

llvm_cbe_tmp__132:
  llvm_cbe_tmp__97 = *(&llvm_cbe_cppVar_1282);
  llvm_cbe_tmp__98 = ((((bool )llvm_cbe_tmp__97&1u))&1);
  llvm_cbe_tmp__99__PHI_TEMPORARY = llvm_cbe_tmp__98;   /* for PHI node */
  goto llvm_cbe_tmp__133;

llvm_cbe_tmp__133:
  llvm_cbe_tmp__99 = ((llvm_cbe_tmp__99__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1283) = (((unsigned char )(bool )llvm_cbe_tmp__99));
  llvm_cbe_tmp__100 = *((&llvm_cbe_tmp__73->field9));
  *(&llvm_cbe_cppVar_1285) = (((unsigned char )(bool )(llvm_cbe_tmp__100 == 4ull)));
  llvm_cbe_tmp__101 = *(&llvm_cbe_cppVar_1283);
  if ((((((bool )llvm_cbe_tmp__101&1u))&1))) {
    goto llvm_cbe_tmp__134;
  } else {
    llvm_cbe_tmp__104__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__135;
  }

llvm_cbe_tmp__134:
  llvm_cbe_tmp__102 = *(&llvm_cbe_cppVar_1285);
  llvm_cbe_tmp__103 = ((((bool )llvm_cbe_tmp__102&1u))&1);
  llvm_cbe_tmp__104__PHI_TEMPORARY = llvm_cbe_tmp__103;   /* for PHI node */
  goto llvm_cbe_tmp__135;

llvm_cbe_tmp__135:
  llvm_cbe_tmp__104 = ((llvm_cbe_tmp__104__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1286) = (((unsigned char )(bool )llvm_cbe_tmp__104));
  llvm_cbe_tmp__105 = *(&llvm_cbe_cppVar_1286);
  if ((((((bool )llvm_cbe_tmp__105&1u))&1))) {
    goto llvm_cbe_tmp__136;
  } else {
    goto llvm_cbe_tmp__137;
  }

llvm_cbe_tmp__136:
  *(&llvm_cbe_cppVar_1271) = 0ull;
  goto llvm_cbe_tmp__138;

llvm_cbe_tmp__137:
  llvm_cbe_tmp__106 = *((&llvm_cbe_tmp__73->field0));
  *(&llvm_cbe_cppVar_1271) = llvm_cbe_tmp__106;
  goto llvm_cbe_tmp__138;

llvm_cbe_tmp__138:
  llvm_cbe_tmp__107 = *(&llvm_cbe_cppVar_1271);
  *(&llvm_cbe_cppVar_1268) = llvm_cbe_tmp__107;
  goto llvm_cbe_tmp__139;

llvm_cbe_tmp__127:
  llvm_cbe_tmp__108 = *((&llvm_cbe_tmp__73->field24));
  *(&llvm_cbe_cppVar_1290) = (((unsigned char )(bool )(llvm_cbe_tmp__108 == 3ull)));
  llvm_cbe_tmp__109 = *(&llvm_cbe_cppVar_1290);
  if ((((((bool )llvm_cbe_tmp__109&1u))&1))) {
    goto llvm_cbe_tmp__140;
  } else {
    goto llvm_cbe_tmp__141;
  }

llvm_cbe_tmp__140:
  llvm_cbe_tmp__110 = *((&llvm_cbe_tmp__73->field9));
  *(&llvm_cbe_cppVar_1293) = (((unsigned char )(bool )(llvm_cbe_tmp__110 == 4ull)));
  llvm_cbe_tmp__111 = *(&llvm_cbe_cppVar_1293);
  llvm_cbe_tmp__112 = *((&llvm_cbe_tmp__73->field0));
  if ((((((bool )llvm_cbe_tmp__111&1u))&1))) {
    goto llvm_cbe_tmp__142;
  } else {
    goto llvm_cbe_tmp__143;
  }

llvm_cbe_tmp__142:
  *(&llvm_cbe_cppVar_1295) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__112) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__113 = *(&llvm_cbe_cppVar_1295);
  llvm_cbe_tmp__114 = *((&llvm_cbe_tmp__73->field49));
  *(&llvm_cbe_cppVar_1295) = (llvm_cbe_tmp__113 & llvm_cbe_tmp__114);
  llvm_cbe_tmp__115 = *(&llvm_cbe_cppVar_1295);
  *(&llvm_cbe_cppVar_1291) = llvm_cbe_tmp__115;
  goto llvm_cbe_tmp__144;

llvm_cbe_tmp__143:
  *(&llvm_cbe_cppVar_1291) = llvm_cbe_tmp__112;
  goto llvm_cbe_tmp__144;

llvm_cbe_tmp__144:
  llvm_cbe_tmp__116 = *(&llvm_cbe_cppVar_1291);
  *(&llvm_cbe_cppVar_1288) = llvm_cbe_tmp__116;
  goto llvm_cbe_tmp__145;

llvm_cbe_tmp__141:
  llvm_cbe_tmp__117 = *((&llvm_cbe_tmp__73->field24));
  *(&llvm_cbe_cppVar_1298) = (((unsigned char )(bool )(llvm_cbe_tmp__117 == 2ull)));
  llvm_cbe_tmp__118 = *((&llvm_cbe_tmp__73->field0));
  *(&llvm_cbe_cppVar_1296) = llvm_cbe_tmp__118;
  llvm_cbe_tmp__119 = *(&llvm_cbe_cppVar_1296);
  *(&llvm_cbe_cppVar_1288) = llvm_cbe_tmp__119;
  goto llvm_cbe_tmp__145;

llvm_cbe_tmp__145:
  llvm_cbe_tmp__120 = *(&llvm_cbe_cppVar_1288);
  *(&llvm_cbe_cppVar_1268) = llvm_cbe_tmp__120;
  goto llvm_cbe_tmp__139;

llvm_cbe_tmp__139:
  llvm_cbe_tmp__121 = *(&llvm_cbe_cppVar_1268);
  *(&llvm_cbe_cppVar_1264) = llvm_cbe_tmp__121;
  goto llvm_cbe_tmp__125;

llvm_cbe_tmp__125:
  llvm_cbe_tmp__122 = *(&llvm_cbe_cppVar_1264);
  return llvm_cbe_tmp__122;
}


unsigned long long _ZN13model_predict17cppUpdateFun_doneElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__146;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__147;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__148;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__149;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__150;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__151;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__152;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__153;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__154;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__155;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__156;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__157;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1322;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1321;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1301;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1302;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1304;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1305;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1307;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1308;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1310;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1311;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1312;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1313;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1314;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1315;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1316;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1317;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1318;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1319;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1320;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1309;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1306;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1303;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1300;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__158;
  unsigned long long llvm_cbe_tmp__159;
  unsigned char llvm_cbe_tmp__160;
  unsigned long long llvm_cbe_tmp__161;
  unsigned long long llvm_cbe_tmp__162;
  unsigned char llvm_cbe_tmp__163;
  unsigned long long llvm_cbe_tmp__164;
  unsigned long long llvm_cbe_tmp__165;
  unsigned char llvm_cbe_tmp__166;
  unsigned long long llvm_cbe_tmp__167;
  unsigned long long llvm_cbe_tmp__168;
  unsigned char llvm_cbe_tmp__169;
  unsigned char llvm_cbe_tmp__170;
  bool llvm_cbe_tmp__171;
  bool llvm_cbe_tmp__172;
  bool llvm_cbe_tmp__172__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__173;
  unsigned long long llvm_cbe_tmp__174;
  unsigned long long llvm_cbe_tmp__175;
  unsigned long long llvm_cbe_tmp__176;
  unsigned long long llvm_cbe_tmp__177;
  unsigned char llvm_cbe_tmp__178;
  unsigned char llvm_cbe_tmp__179;
  bool llvm_cbe_tmp__180;
  bool llvm_cbe_tmp__181;
  bool llvm_cbe_tmp__181__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__182;
  unsigned long long llvm_cbe_tmp__183;
  unsigned char llvm_cbe_tmp__184;
  unsigned char llvm_cbe_tmp__185;
  bool llvm_cbe_tmp__186;
  bool llvm_cbe_tmp__187;
  bool llvm_cbe_tmp__187__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__188;
  unsigned long long llvm_cbe_tmp__189;
  unsigned long long llvm_cbe_tmp__190;
  unsigned long long llvm_cbe_tmp__191;
  unsigned long long llvm_cbe_tmp__192;
  unsigned long long llvm_cbe_tmp__193;

  *(&llvm_cbe_tmp__146) = llvm_cbe_this;
  *(&llvm_cbe_tmp__147) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__148) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__149) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__150) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__151) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__152) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__153) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__154) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__155) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__156) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__157) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__158 = *(&llvm_cbe_tmp__146);
  llvm_cbe_tmp__159 = *((&llvm_cbe_tmp__158->field24));
  *(&llvm_cbe_cppVar_1302) = (((unsigned char )(bool )(llvm_cbe_tmp__159 == 0ull)));
  llvm_cbe_tmp__160 = *(&llvm_cbe_cppVar_1302);
  if ((((((bool )llvm_cbe_tmp__160&1u))&1))) {
    goto llvm_cbe_tmp__194;
  } else {
    goto llvm_cbe_tmp__195;
  }

llvm_cbe_tmp__194:
  llvm_cbe_tmp__161 = *((&llvm_cbe_tmp__158->field3));
  *(&llvm_cbe_cppVar_1300) = llvm_cbe_tmp__161;
  goto llvm_cbe_tmp__196;

llvm_cbe_tmp__195:
  llvm_cbe_tmp__162 = *((&llvm_cbe_tmp__158->field24));
  *(&llvm_cbe_cppVar_1305) = (((unsigned char )(bool )(llvm_cbe_tmp__162 == 1ull)));
  llvm_cbe_tmp__163 = *(&llvm_cbe_cppVar_1305);
  if ((((((bool )llvm_cbe_tmp__163&1u))&1))) {
    goto llvm_cbe_tmp__197;
  } else {
    goto llvm_cbe_tmp__198;
  }

llvm_cbe_tmp__197:
  llvm_cbe_tmp__164 = *((&llvm_cbe_tmp__158->field3));
  *(&llvm_cbe_cppVar_1303) = llvm_cbe_tmp__164;
  goto llvm_cbe_tmp__199;

llvm_cbe_tmp__198:
  llvm_cbe_tmp__165 = *((&llvm_cbe_tmp__158->field24));
  *(&llvm_cbe_cppVar_1308) = (((unsigned char )(bool )(llvm_cbe_tmp__165 == 2ull)));
  llvm_cbe_tmp__166 = *(&llvm_cbe_cppVar_1308);
  if ((((((bool )llvm_cbe_tmp__166&1u))&1))) {
    goto llvm_cbe_tmp__200;
  } else {
    goto llvm_cbe_tmp__201;
  }

llvm_cbe_tmp__200:
  llvm_cbe_tmp__167 = *((&llvm_cbe_tmp__158->field39));
  *(&llvm_cbe_cppVar_1311) = (((unsigned char )(bool )(llvm_cbe_tmp__167 == 0ull)));
  llvm_cbe_tmp__168 = *((&llvm_cbe_tmp__158->field36));
  *(&llvm_cbe_cppVar_1313) = (((unsigned char )(bool )(llvm_cbe_tmp__168 == 1ull)));
  llvm_cbe_tmp__169 = *(&llvm_cbe_cppVar_1311);
  if ((((((bool )llvm_cbe_tmp__169&1u))&1))) {
    goto llvm_cbe_tmp__202;
  } else {
    llvm_cbe_tmp__172__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__203;
  }

llvm_cbe_tmp__202:
  llvm_cbe_tmp__170 = *(&llvm_cbe_cppVar_1313);
  llvm_cbe_tmp__171 = ((((bool )llvm_cbe_tmp__170&1u))&1);
  llvm_cbe_tmp__172__PHI_TEMPORARY = llvm_cbe_tmp__171;   /* for PHI node */
  goto llvm_cbe_tmp__203;

llvm_cbe_tmp__203:
  llvm_cbe_tmp__172 = ((llvm_cbe_tmp__172__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1314) = (((unsigned char )(bool )llvm_cbe_tmp__172));
  llvm_cbe_tmp__173 = *((&llvm_cbe_tmp__158->field14));
  *(&llvm_cbe_cppVar_1316) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__173) - ((unsigned long long )1ull))));
  llvm_cbe_tmp__174 = *(&llvm_cbe_cppVar_1316);
  llvm_cbe_tmp__175 = *((&llvm_cbe_tmp__158->field41));
  *(&llvm_cbe_cppVar_1316) = (llvm_cbe_tmp__174 & llvm_cbe_tmp__175);
  llvm_cbe_tmp__176 = *((&llvm_cbe_tmp__158->field7));
  llvm_cbe_tmp__177 = *(&llvm_cbe_cppVar_1316);
  *(&llvm_cbe_cppVar_1317) = (((unsigned char )(bool )(llvm_cbe_tmp__176 == llvm_cbe_tmp__177)));
  llvm_cbe_tmp__178 = *(&llvm_cbe_cppVar_1314);
  if ((((((bool )llvm_cbe_tmp__178&1u))&1))) {
    goto llvm_cbe_tmp__204;
  } else {
    llvm_cbe_tmp__181__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__205;
  }

llvm_cbe_tmp__204:
  llvm_cbe_tmp__179 = *(&llvm_cbe_cppVar_1317);
  llvm_cbe_tmp__180 = ((((bool )llvm_cbe_tmp__179&1u))&1);
  llvm_cbe_tmp__181__PHI_TEMPORARY = llvm_cbe_tmp__180;   /* for PHI node */
  goto llvm_cbe_tmp__205;

llvm_cbe_tmp__205:
  llvm_cbe_tmp__181 = ((llvm_cbe_tmp__181__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1318) = (((unsigned char )(bool )llvm_cbe_tmp__181));
  llvm_cbe_tmp__182 = *((&llvm_cbe_tmp__158->field10));
  llvm_cbe_tmp__183 = *((&llvm_cbe_tmp__158->field12));
  *(&llvm_cbe_cppVar_1319) = (((unsigned char )(bool )(llvm_cbe_tmp__182 == llvm_cbe_tmp__183)));
  llvm_cbe_tmp__184 = *(&llvm_cbe_cppVar_1318);
  if ((((((bool )llvm_cbe_tmp__184&1u))&1))) {
    goto llvm_cbe_tmp__206;
  } else {
    llvm_cbe_tmp__187__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__207;
  }

llvm_cbe_tmp__206:
  llvm_cbe_tmp__185 = *(&llvm_cbe_cppVar_1319);
  llvm_cbe_tmp__186 = ((((bool )llvm_cbe_tmp__185&1u))&1);
  llvm_cbe_tmp__187__PHI_TEMPORARY = llvm_cbe_tmp__186;   /* for PHI node */
  goto llvm_cbe_tmp__207;

llvm_cbe_tmp__207:
  llvm_cbe_tmp__187 = ((llvm_cbe_tmp__187__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1320) = (((unsigned char )(bool )llvm_cbe_tmp__187));
  llvm_cbe_tmp__188 = *(&llvm_cbe_cppVar_1320);
  if ((((((bool )llvm_cbe_tmp__188&1u))&1))) {
    goto llvm_cbe_tmp__208;
  } else {
    goto llvm_cbe_tmp__209;
  }

llvm_cbe_tmp__208:
  *(&llvm_cbe_cppVar_1309) = 1ull;
  goto llvm_cbe_tmp__210;

llvm_cbe_tmp__209:
  *(&llvm_cbe_cppVar_1309) = 0ull;
  goto llvm_cbe_tmp__210;

llvm_cbe_tmp__210:
  llvm_cbe_tmp__189 = *(&llvm_cbe_cppVar_1309);
  *(&llvm_cbe_cppVar_1306) = llvm_cbe_tmp__189;
  goto llvm_cbe_tmp__211;

llvm_cbe_tmp__201:
  llvm_cbe_tmp__190 = *((&llvm_cbe_tmp__158->field3));
  *(&llvm_cbe_cppVar_1306) = llvm_cbe_tmp__190;
  goto llvm_cbe_tmp__211;

llvm_cbe_tmp__211:
  llvm_cbe_tmp__191 = *(&llvm_cbe_cppVar_1306);
  *(&llvm_cbe_cppVar_1303) = llvm_cbe_tmp__191;
  goto llvm_cbe_tmp__199;

llvm_cbe_tmp__199:
  llvm_cbe_tmp__192 = *(&llvm_cbe_cppVar_1303);
  *(&llvm_cbe_cppVar_1300) = llvm_cbe_tmp__192;
  goto llvm_cbe_tmp__196;

llvm_cbe_tmp__196:
  llvm_cbe_tmp__193 = *(&llvm_cbe_cppVar_1300);
  return llvm_cbe_tmp__193;
}


unsigned long long _ZN13model_predict24cppUpdateFun_expectationElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__212;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__213;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__214;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__215;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__216;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__217;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__218;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__219;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__220;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__221;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__222;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__223;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1325;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1326;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1328;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1329;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1337;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1351;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1352;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1331;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1332;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1333;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1338;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1339;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1340;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1341;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1342;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1343;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1335;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1336;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1334;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1344;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1345;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1346;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1347;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1348;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1349;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1330;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1350;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1327;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1324;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__224;
  unsigned long long llvm_cbe_tmp__225;
  unsigned char llvm_cbe_tmp__226;
  unsigned long long llvm_cbe_tmp__227;
  unsigned long long llvm_cbe_tmp__228;
  unsigned char llvm_cbe_tmp__229;
  unsigned long long llvm_cbe_tmp__230;
  unsigned char llvm_cbe_tmp__231;
  unsigned char llvm_cbe_tmp__232;
  bool llvm_cbe_tmp__233;
  bool llvm_cbe_tmp__234;
  bool llvm_cbe_tmp__234__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__235;
  unsigned long long llvm_cbe_tmp__236;
  unsigned char llvm_cbe_tmp__237;
  unsigned long long llvm_cbe_tmp__238;
  unsigned long long llvm_cbe_tmp__239;
  unsigned long long llvm_cbe_tmp__240;
  unsigned long long llvm_cbe_tmp__241;
  unsigned long long llvm_cbe_tmp__242;
  unsigned long long llvm_cbe_tmp__243;
  unsigned long long llvm_cbe_tmp__244;
  unsigned short llvm_cbe_tmp__245;
  unsigned long long llvm_cbe_tmp__246;
  unsigned long long llvm_cbe_tmp__247;
  unsigned long long llvm_cbe_tmp__248;
  unsigned long long llvm_cbe_tmp__249;
  unsigned long long llvm_cbe_tmp__250;
  unsigned long long llvm_cbe_tmp__251;
  unsigned long long llvm_cbe_tmp__252;
  unsigned long long llvm_cbe_tmp__253;
  unsigned long long llvm_cbe_tmp__254;
  unsigned long long llvm_cbe_tmp__255;
  unsigned long long llvm_cbe_tmp__256;
  unsigned long long llvm_cbe_tmp__257;
  unsigned long long llvm_cbe_tmp__258;
  unsigned long long llvm_cbe_tmp__259;
  unsigned long long llvm_cbe_tmp__260;
  unsigned long long llvm_cbe_tmp__261;
  unsigned long long llvm_cbe_tmp__262;
  unsigned long long llvm_cbe_tmp__263;
  unsigned long long llvm_cbe_tmp__264;
  unsigned long long llvm_cbe_tmp__265;
  unsigned long long llvm_cbe_tmp__266;
  unsigned long long llvm_cbe_tmp__267;
  unsigned long long llvm_cbe_tmp__268;
  unsigned long long llvm_cbe_tmp__269;
  unsigned long long llvm_cbe_tmp__270;
  unsigned long long llvm_cbe_tmp__271;
  unsigned long long llvm_cbe_tmp__272;
  unsigned long long llvm_cbe_tmp__273;
  unsigned long long llvm_cbe_tmp__274;
  unsigned long long llvm_cbe_tmp__275;
  unsigned long long llvm_cbe_tmp__276;
  unsigned long long llvm_cbe_tmp__277;

  *(&llvm_cbe_tmp__212) = llvm_cbe_this;
  *(&llvm_cbe_tmp__213) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__214) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__215) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__216) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__217) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__218) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__219) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__220) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__221) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__222) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__223) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__224 = *(&llvm_cbe_tmp__212);
  llvm_cbe_tmp__225 = *((&llvm_cbe_tmp__224->field24));
  *(&llvm_cbe_cppVar_1326) = (((unsigned char )(bool )(llvm_cbe_tmp__225 == 0ull)));
  llvm_cbe_tmp__226 = *(&llvm_cbe_cppVar_1326);
  if ((((((bool )llvm_cbe_tmp__226&1u))&1))) {
    goto llvm_cbe_tmp__278;
  } else {
    goto llvm_cbe_tmp__279;
  }

llvm_cbe_tmp__278:
  llvm_cbe_tmp__227 = *((&llvm_cbe_tmp__224->field5));
  *(&llvm_cbe_cppVar_1324) = llvm_cbe_tmp__227;
  goto llvm_cbe_tmp__280;

llvm_cbe_tmp__279:
  llvm_cbe_tmp__228 = *((&llvm_cbe_tmp__224->field24));
  *(&llvm_cbe_cppVar_1329) = (((unsigned char )(bool )(llvm_cbe_tmp__228 == 1ull)));
  llvm_cbe_tmp__229 = *(&llvm_cbe_cppVar_1329);
  if ((((((bool )llvm_cbe_tmp__229&1u))&1))) {
    goto llvm_cbe_tmp__281;
  } else {
    goto llvm_cbe_tmp__282;
  }

llvm_cbe_tmp__281:
  llvm_cbe_tmp__230 = *((&llvm_cbe_tmp__224->field17));
  *(&llvm_cbe_cppVar_1332) = (((unsigned char )(bool )(llvm_cbe_tmp__230 == 3ull)));
  llvm_cbe_tmp__231 = *(&llvm_cbe_cppVar_1329);
  if ((((((bool )llvm_cbe_tmp__231&1u))&1))) {
    goto llvm_cbe_tmp__283;
  } else {
    llvm_cbe_tmp__234__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__284;
  }

llvm_cbe_tmp__283:
  llvm_cbe_tmp__232 = *(&llvm_cbe_cppVar_1332);
  llvm_cbe_tmp__233 = ((((bool )llvm_cbe_tmp__232&1u))&1);
  llvm_cbe_tmp__234__PHI_TEMPORARY = llvm_cbe_tmp__233;   /* for PHI node */
  goto llvm_cbe_tmp__284;

llvm_cbe_tmp__284:
  llvm_cbe_tmp__234 = ((llvm_cbe_tmp__234__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1333) = (((unsigned char )(bool )llvm_cbe_tmp__234));
  llvm_cbe_tmp__235 = *(&llvm_cbe_cppVar_1333);
  if ((((((bool )llvm_cbe_tmp__235&1u))&1))) {
    goto llvm_cbe_tmp__285;
  } else {
    goto llvm_cbe_tmp__286;
  }

llvm_cbe_tmp__285:
  llvm_cbe_tmp__236 = *((&llvm_cbe_tmp__224->field9));
  *(&llvm_cbe_cppVar_1336) = (((unsigned char )(bool )(llvm_cbe_tmp__236 == 0ull)));
  llvm_cbe_tmp__237 = *(&llvm_cbe_cppVar_1336);
  if ((((((bool )llvm_cbe_tmp__237&1u))&1))) {
    goto llvm_cbe_tmp__287;
  } else {
    goto llvm_cbe_tmp__288;
  }

llvm_cbe_tmp__287:
  *(&llvm_cbe_cppVar_1334) = 0ull;
  goto llvm_cbe_tmp__289;

llvm_cbe_tmp__288:
  llvm_cbe_tmp__238 = *((&llvm_cbe_tmp__224->field5));
  *(&llvm_cbe_cppVar_1334) = llvm_cbe_tmp__238;
  goto llvm_cbe_tmp__289;

llvm_cbe_tmp__289:
  llvm_cbe_tmp__239 = *((&llvm_cbe_tmp__224->field9));
  llvm_cbe_tmp__240 = *((&llvm_cbe_tmp__224->field44));
  *(&llvm_cbe_cppVar_1338) = ((((signed long long )(((signed long long )llvm_cbe_tmp__239) >> ((signed long long )0ull)))) & llvm_cbe_tmp__240);
  llvm_cbe_tmp__241 = *(&llvm_cbe_cppVar_1338);
  llvm_cbe_tmp__242 = _ZN8type_memIjLj8EE2rdEl(((&llvm_cbe_tmp__224->field18)), llvm_cbe_tmp__241);
  *(&llvm_cbe_cppVar_1339) = llvm_cbe_tmp__242;
  llvm_cbe_tmp__243 = *(&llvm_cbe_cppVar_1339);
  llvm_cbe_tmp__244 = *((&llvm_cbe_tmp__224->field32));
  llvm_cbe_tmp__245 = _Z6dividell(llvm_cbe_tmp__243, llvm_cbe_tmp__244);
  *(&llvm_cbe_cppVar_1340) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__245));
  llvm_cbe_tmp__246 = *(&llvm_cbe_cppVar_1340);
  llvm_cbe_tmp__247 = *((&llvm_cbe_tmp__224->field47));
  *(&llvm_cbe_cppVar_1341) = (llvm_cbe_tmp__246 & llvm_cbe_tmp__247);
  llvm_cbe_tmp__248 = *((&llvm_cbe_tmp__224->field9));
  llvm_cbe_tmp__249 = *((&llvm_cbe_tmp__224->field41));
  *(&llvm_cbe_cppVar_1342) = (llvm_cbe_tmp__248 & llvm_cbe_tmp__249);
  llvm_cbe_tmp__250 = *(&llvm_cbe_cppVar_1341);
  llvm_cbe_tmp__251 = *(&llvm_cbe_cppVar_1342);
  *(&llvm_cbe_cppVar_1343) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__250) * ((unsigned long long )llvm_cbe_tmp__251))));
  llvm_cbe_tmp__252 = *(&llvm_cbe_cppVar_1343);
  llvm_cbe_tmp__253 = *((&llvm_cbe_tmp__224->field50));
  *(&llvm_cbe_cppVar_1343) = (llvm_cbe_tmp__252 & llvm_cbe_tmp__253);
  llvm_cbe_tmp__254 = *(&llvm_cbe_cppVar_1343);
  llvm_cbe_tmp__255 = *((&llvm_cbe_tmp__224->field42));
  *(&llvm_cbe_cppVar_1344) = ((((signed long long )(((signed long long )llvm_cbe_tmp__254) >> ((signed long long )63ull)))) & llvm_cbe_tmp__255);
  llvm_cbe_tmp__256 = *(&llvm_cbe_cppVar_1344);
  llvm_cbe_tmp__257 = *((&llvm_cbe_tmp__224->field44));
  *(&llvm_cbe_cppVar_1345) = ((((signed long long )(((signed long long )llvm_cbe_tmp__256) >> ((signed long long )0ull)))) & llvm_cbe_tmp__257);
  llvm_cbe_tmp__258 = *(&llvm_cbe_cppVar_1343);
  llvm_cbe_tmp__259 = *((&llvm_cbe_tmp__224->field46));
  *(&llvm_cbe_cppVar_1346) = ((((signed long long )(((signed long long )llvm_cbe_tmp__258) >> ((signed long long )0ull)))) & llvm_cbe_tmp__259);
  llvm_cbe_tmp__260 = *(&llvm_cbe_cppVar_1346);
  llvm_cbe_tmp__261 = *((&llvm_cbe_tmp__224->field43));
  *(&llvm_cbe_cppVar_1347) = ((((signed long long )(((signed long long )llvm_cbe_tmp__260) >> ((signed long long )34ull)))) & llvm_cbe_tmp__261);
  llvm_cbe_tmp__262 = *(&llvm_cbe_cppVar_1345);
  llvm_cbe_tmp__263 = *(&llvm_cbe_cppVar_1347);
  *(&llvm_cbe_cppVar_1348) = ((llvm_cbe_tmp__262 << 29ull) | llvm_cbe_tmp__263);
  llvm_cbe_tmp__264 = *(&llvm_cbe_cppVar_1348);
  llvm_cbe_tmp__265 = *((&llvm_cbe_tmp__224->field45));
  *(&llvm_cbe_cppVar_1348) = (llvm_cbe_tmp__264 & llvm_cbe_tmp__265);
  llvm_cbe_tmp__266 = *(&llvm_cbe_cppVar_1334);
  llvm_cbe_tmp__267 = *(&llvm_cbe_cppVar_1348);
  *(&llvm_cbe_cppVar_1349) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__266) + ((unsigned long long )llvm_cbe_tmp__267))));
  llvm_cbe_tmp__268 = *(&llvm_cbe_cppVar_1349);
  llvm_cbe_tmp__269 = *((&llvm_cbe_tmp__224->field45));
  *(&llvm_cbe_cppVar_1349) = (llvm_cbe_tmp__268 & llvm_cbe_tmp__269);
  llvm_cbe_tmp__270 = *(&llvm_cbe_cppVar_1349);
  *(&llvm_cbe_cppVar_1330) = llvm_cbe_tmp__270;
  goto llvm_cbe_tmp__290;

llvm_cbe_tmp__286:
  llvm_cbe_tmp__271 = *((&llvm_cbe_tmp__224->field5));
  *(&llvm_cbe_cppVar_1330) = llvm_cbe_tmp__271;
  goto llvm_cbe_tmp__290;

llvm_cbe_tmp__290:
  llvm_cbe_tmp__272 = *(&llvm_cbe_cppVar_1330);
  *(&llvm_cbe_cppVar_1327) = llvm_cbe_tmp__272;
  goto llvm_cbe_tmp__291;

llvm_cbe_tmp__282:
  llvm_cbe_tmp__273 = *((&llvm_cbe_tmp__224->field24));
  *(&llvm_cbe_cppVar_1352) = (((unsigned char )(bool )(llvm_cbe_tmp__273 == 2ull)));
  llvm_cbe_tmp__274 = *((&llvm_cbe_tmp__224->field5));
  *(&llvm_cbe_cppVar_1350) = llvm_cbe_tmp__274;
  llvm_cbe_tmp__275 = *(&llvm_cbe_cppVar_1350);
  *(&llvm_cbe_cppVar_1327) = llvm_cbe_tmp__275;
  goto llvm_cbe_tmp__291;

llvm_cbe_tmp__291:
  llvm_cbe_tmp__276 = *(&llvm_cbe_cppVar_1327);
  *(&llvm_cbe_cppVar_1324) = llvm_cbe_tmp__276;
  goto llvm_cbe_tmp__280;

llvm_cbe_tmp__280:
  llvm_cbe_tmp__277 = *(&llvm_cbe_cppVar_1324);
  return llvm_cbe_tmp__277;
}


unsigned long long _ZN8type_memIjLj8EE2rdEl(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_unnamed1 *llvm_cbe_tmp__292;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__293;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__294;
  unsigned long long llvm_cbe_tmp__295;
  unsigned int *llvm_cbe_tmp__296;
  unsigned int llvm_cbe_tmp__297;

  *(&llvm_cbe_tmp__292) = llvm_cbe_this;
  *(&llvm_cbe_tmp__293) = llvm_cbe_addr;
  llvm_cbe_tmp__294 = *(&llvm_cbe_tmp__292);
  llvm_cbe_tmp__295 = *(&llvm_cbe_tmp__293);
  llvm_cbe_tmp__296 = *((&llvm_cbe_tmp__294->field0));
  llvm_cbe_tmp__297 = *((&llvm_cbe_tmp__296[((signed long long )llvm_cbe_tmp__295)]));
  return (((unsigned long long )(unsigned int )llvm_cbe_tmp__297));
}


struct l_class_OC_SysCArray1D _ZN13model_predict24cppUpdateFun_hidden_unitElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_SysCArray1D StructReturn;  /* Struct return temporary */
  struct l_class_OC_SysCArray1D *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_predict *llvm_cbe_tmp__298;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__299;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__300;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__301;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__302;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__303;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__304;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__305;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__306;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__307;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__308;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__309;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2011;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2010;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1968;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1969;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2016;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2017;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2019;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2020;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1998;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1999;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2000;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1990;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1991;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1992;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1989;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1994;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1995;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1996;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1997;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2001;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2002;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2003;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2004;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2005;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2006;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1993;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2007;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1980;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1981;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1982;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1983;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1984;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1985;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1986;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1987;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1988;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2008;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2009;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1979;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1977;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1978;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_2012;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1976;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__310;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__311;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1971;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1972;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1973;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1974;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1975;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2013;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_2014;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1970;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_2018;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_2015;    /* Address-exposed local */
  bool llvm_cbe_tmp__312;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__313;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__314;
  unsigned long long llvm_cbe_tmp__315;
  unsigned char llvm_cbe_tmp__316;
  unsigned long long llvm_cbe_tmp__317;
  unsigned long long llvm_cbe_tmp__318;
  unsigned long long llvm_cbe_tmp__319;
  unsigned long long llvm_cbe_tmp__320;
  unsigned long long llvm_cbe_tmp__321;
  unsigned long long llvm_cbe_tmp__322;
  unsigned long long llvm_cbe_tmp__323;
  unsigned char llvm_cbe_tmp__324;
  unsigned char llvm_cbe_tmp__325;
  bool llvm_cbe_tmp__326;
  bool llvm_cbe_tmp__327;
  bool llvm_cbe_tmp__327__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__328;
  unsigned long long llvm_cbe_tmp__329;
  unsigned long long llvm_cbe_tmp__330;
  unsigned char llvm_cbe_tmp__331;
  unsigned long long llvm_cbe_tmp__332;
  unsigned long long llvm_cbe_tmp__333;
  unsigned long long llvm_cbe_tmp__334;
  unsigned long long llvm_cbe_tmp__335;
  unsigned long long llvm_cbe_tmp__336;
  unsigned long long llvm_cbe_tmp__337;
  unsigned long long llvm_cbe_tmp__338;
  unsigned long long llvm_cbe_tmp__339;
  unsigned long long llvm_cbe_tmp__340;
  unsigned long long llvm_cbe_tmp__341;
  unsigned char llvm_cbe_tmp__342;
  unsigned long long llvm_cbe_tmp__343;
  unsigned long long llvm_cbe_tmp__344;
  unsigned long long llvm_cbe_tmp__345;
  unsigned long long llvm_cbe_tmp__346;
  unsigned long long llvm_cbe_tmp__347;
  unsigned long long llvm_cbe_tmp__348;
  unsigned char llvm_cbe_tmp__349;
  unsigned long long llvm_cbe_tmp__350;
  unsigned long long llvm_cbe_tmp__351;
  unsigned long long llvm_cbe_tmp__352;
  unsigned long long llvm_cbe_tmp__353;
  unsigned long long llvm_cbe_tmp__354;
  unsigned long long llvm_cbe_tmp__355;
  unsigned long long llvm_cbe_tmp__356;
  unsigned long long llvm_cbe_tmp__357;
  unsigned long long llvm_cbe_tmp__358;
  unsigned long long llvm_cbe_tmp__359;
  unsigned long long llvm_cbe_tmp__360;
  unsigned long long llvm_cbe_tmp__361;
  unsigned long long llvm_cbe_tmp__362;
  unsigned long long llvm_cbe_tmp__363;
  unsigned long long llvm_cbe_tmp__364;
  unsigned long long llvm_cbe_tmp__365;
  unsigned long long llvm_cbe_tmp__366;
  unsigned long long llvm_cbe_tmp__366__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__367;
  unsigned long long llvm_cbe_tmp__368;
  unsigned long long llvm_cbe_tmp__369;
  unsigned long long llvm_cbe_tmp__370;
  unsigned long long llvm_cbe_tmp__371;
  unsigned long long llvm_cbe_tmp__372;
  unsigned long long llvm_cbe_tmp__373;
  unsigned long long llvm_cbe_tmp__374;
  unsigned long long llvm_cbe_tmp__375;
  unsigned long long llvm_cbe_tmp__376;
  unsigned long long llvm_cbe_tmp__377;
  unsigned long long llvm_cbe_tmp__378;
  unsigned short llvm_cbe_tmp__379;
  unsigned long long llvm_cbe_tmp__380;
  unsigned long long llvm_cbe_tmp__381;
  unsigned char llvm_cbe_tmp__382;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__383;
  unsigned long long llvm_cbe_tmp__384;
  unsigned long long llvm_cbe_tmp__385;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__386;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__387;
  unsigned long long llvm_cbe_tmp__388;
  unsigned long long llvm_cbe_tmp__389;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__390;
  unsigned long long llvm_cbe_tmp__391;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__392;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__393;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__394;
  unsigned long long llvm_cbe_tmp__395;
  unsigned char llvm_cbe_tmp__396;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__397;
  unsigned long long llvm_cbe_tmp__398;
  unsigned char llvm_cbe_tmp__399;
  bool llvm_cbe_tmp__400;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__401;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__402;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__403;
  bool llvm_cbe_tmp__404;

  *(&llvm_cbe_tmp__298) = llvm_cbe_this;
  *(&llvm_cbe_tmp__299) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__300) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__301) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__302) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__303) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__304) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__305) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__306) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__307) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__308) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__309) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__314 = *(&llvm_cbe_tmp__298);
  _ZN8type_memIbLj128EEC1Ev((&llvm_cbe_cppVar_2012));
  _ZN8type_memIbLj128EEC1Ev((&llvm_cbe_cppVar_1976));
  _ZN8type_memIbLj128EEC1Ev((&llvm_cbe_cppVar_2014));
  _ZN8type_memIbLj128EEC1Ev((&llvm_cbe_cppVar_1970));
  _ZN8type_memIbLj128EEC1Ev((&llvm_cbe_cppVar_2018));
  _ZN8type_memIbLj128EEC1Ev((&llvm_cbe_cppVar_2015));
  *(&llvm_cbe_tmp__312) = ((0) & 1);
  _ZN8type_memIbLj128EEC1Ev(llvm_cbe_agg_2e_result);
  llvm_cbe_tmp__315 = *((&llvm_cbe_tmp__314->field24));
  *(&llvm_cbe_cppVar_1969) = (((unsigned char )(bool )(llvm_cbe_tmp__315 == 0ull)));
  llvm_cbe_tmp__316 = *(&llvm_cbe_cppVar_1969);
  if ((((((bool )llvm_cbe_tmp__316&1u))&1))) {
    goto llvm_cbe_tmp__405;
  } else {
    goto llvm_cbe_tmp__406;
  }

llvm_cbe_tmp__405:
  llvm_cbe_tmp__317 = *((&llvm_cbe_tmp__314->field25));
  llvm_cbe_tmp__318 = *((&llvm_cbe_tmp__314->field16));
  *(&llvm_cbe_cppVar_1971) = (((unsigned char )(bool )(llvm_cbe_tmp__317 == llvm_cbe_tmp__318)));
  llvm_cbe_tmp__319 = *((&llvm_cbe_tmp__314->field11));
  *(&llvm_cbe_cppVar_1973) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__319) - ((unsigned long long )1ull))));
  llvm_cbe_tmp__320 = *(&llvm_cbe_cppVar_1973);
  llvm_cbe_tmp__321 = *((&llvm_cbe_tmp__314->field41));
  *(&llvm_cbe_cppVar_1973) = (llvm_cbe_tmp__320 & llvm_cbe_tmp__321);
  llvm_cbe_tmp__322 = *((&llvm_cbe_tmp__314->field19));
  llvm_cbe_tmp__323 = *(&llvm_cbe_cppVar_1973);
  *(&llvm_cbe_cppVar_1974) = (((unsigned char )(bool )(llvm_cbe_tmp__322 == llvm_cbe_tmp__323)));
  llvm_cbe_tmp__324 = *(&llvm_cbe_cppVar_1971);
  if ((((((bool )llvm_cbe_tmp__324&1u))&1))) {
    goto llvm_cbe_tmp__407;
  } else {
    llvm_cbe_tmp__327__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__408;
  }

llvm_cbe_tmp__407:
  llvm_cbe_tmp__325 = *(&llvm_cbe_cppVar_1974);
  llvm_cbe_tmp__326 = ((((bool )llvm_cbe_tmp__325&1u))&1);
  llvm_cbe_tmp__327__PHI_TEMPORARY = llvm_cbe_tmp__326;   /* for PHI node */
  goto llvm_cbe_tmp__408;

llvm_cbe_tmp__408:
  llvm_cbe_tmp__327 = ((llvm_cbe_tmp__327__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1975) = (((unsigned char )(bool )llvm_cbe_tmp__327));
  llvm_cbe_tmp__328 = *(&llvm_cbe_cppVar_1975);
  if ((((((bool )llvm_cbe_tmp__328&1u))&1))) {
    goto llvm_cbe_tmp__409;
  } else {
    goto llvm_cbe_tmp__410;
  }

llvm_cbe_tmp__409:
  llvm_cbe_tmp__329 = *((&llvm_cbe_tmp__314->field25));
  llvm_cbe_tmp__330 = *((&llvm_cbe_tmp__314->field16));
  *(&llvm_cbe_cppVar_1977) = (((unsigned char )(bool )(llvm_cbe_tmp__329 == llvm_cbe_tmp__330)));
  llvm_cbe_tmp__331 = *(&llvm_cbe_cppVar_1977);
  if ((((((bool )llvm_cbe_tmp__331&1u))&1))) {
    goto llvm_cbe_tmp__411;
  } else {
    goto llvm_cbe_tmp__412;
  }

llvm_cbe_tmp__411:
  llvm_cbe_tmp__332 = *((&llvm_cbe_tmp__314->field19));
  llvm_cbe_tmp__333 = *((&llvm_cbe_tmp__314->field48));
  *(&llvm_cbe_cppVar_1978) = ((((signed long long )(((signed long long )llvm_cbe_tmp__332) >> ((signed long long )0ull)))) & llvm_cbe_tmp__333);
  *(&llvm_cbe_cppVar_1983) = 0ull;
  llvm_cbe_tmp__334 = *(&llvm_cbe_cppVar_1983);
  llvm_cbe_tmp__335 = *((&llvm_cbe_tmp__314->field47));
  *(&llvm_cbe_cppVar_1983) = (llvm_cbe_tmp__334 & llvm_cbe_tmp__335);
  llvm_cbe_tmp__336 = *(&llvm_cbe_cppVar_1983);
  *(&llvm_cbe_cppVar_1984) = (0ull | llvm_cbe_tmp__336);
  *(&llvm_cbe_cppVar_1987) = 0ull;
  llvm_cbe_tmp__337 = *(&llvm_cbe_cppVar_1987);
  llvm_cbe_tmp__338 = *((&llvm_cbe_tmp__314->field47));
  *(&llvm_cbe_cppVar_1987) = (llvm_cbe_tmp__337 & llvm_cbe_tmp__338);
  llvm_cbe_tmp__339 = *(&llvm_cbe_cppVar_1984);
  llvm_cbe_tmp__340 = *(&llvm_cbe_cppVar_1987);
  *(&llvm_cbe_cppVar_1988) = (llvm_cbe_tmp__339 | llvm_cbe_tmp__340);
  llvm_cbe_tmp__341 = *((&llvm_cbe_tmp__314->field25));
  *(&llvm_cbe_cppVar_1991) = (((unsigned char )(bool )(llvm_cbe_tmp__341 == 0ull)));
  llvm_cbe_tmp__342 = *(&llvm_cbe_cppVar_1991);
  if ((((((bool )llvm_cbe_tmp__342&1u))&1))) {
    goto llvm_cbe_tmp__413;
  } else {
    goto llvm_cbe_tmp__414;
  }

llvm_cbe_tmp__413:
  *(&llvm_cbe_cppVar_1989) = 0ull;
  goto llvm_cbe_tmp__415;

llvm_cbe_tmp__414:
  llvm_cbe_tmp__343 = *((&llvm_cbe_tmp__314->field23));
  *(&llvm_cbe_cppVar_1989) = llvm_cbe_tmp__343;
  goto llvm_cbe_tmp__415;

llvm_cbe_tmp__415:
  llvm_cbe_tmp__344 = *((&llvm_cbe_tmp__314->field25));
  llvm_cbe_tmp__345 = *((&llvm_cbe_tmp__314->field51));
  *(&llvm_cbe_cppVar_1994) = ((((signed long long )(((signed long long )llvm_cbe_tmp__344) >> ((signed long long )0ull)))) & llvm_cbe_tmp__345);
  llvm_cbe_tmp__346 = *(&llvm_cbe_cppVar_1994);
  llvm_cbe_tmp__347 = _ZN8type_memIhLj512EE2rdEl(((&llvm_cbe_tmp__314->field1)), llvm_cbe_tmp__346);
  *(&llvm_cbe_cppVar_1995) = llvm_cbe_tmp__347;
  llvm_cbe_tmp__348 = *(&llvm_cbe_cppVar_1995);
  *(&llvm_cbe_cppVar_1997) = (((unsigned char )(bool )(llvm_cbe_tmp__348 == 1ull)));
  llvm_cbe_tmp__349 = *(&llvm_cbe_cppVar_1997);
  if ((((((bool )llvm_cbe_tmp__349&1u))&1))) {
    goto llvm_cbe_tmp__416;
  } else {
    goto llvm_cbe_tmp__417;
  }

llvm_cbe_tmp__416:
  llvm_cbe_tmp__350 = *((&llvm_cbe_tmp__314->field25));
  *(&llvm_cbe_cppVar_1999) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__350))));
  llvm_cbe_tmp__351 = *(&llvm_cbe_cppVar_1999);
  llvm_cbe_tmp__352 = *((&llvm_cbe_tmp__314->field41));
  *(&llvm_cbe_cppVar_1999) = (llvm_cbe_tmp__351 & llvm_cbe_tmp__352);
  llvm_cbe_tmp__353 = *(&llvm_cbe_cppVar_1999);
  llvm_cbe_tmp__354 = *((&llvm_cbe_tmp__314->field19));
  *(&llvm_cbe_cppVar_2000) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__353) + ((unsigned long long )llvm_cbe_tmp__354))));
  llvm_cbe_tmp__355 = *(&llvm_cbe_cppVar_2000);
  llvm_cbe_tmp__356 = *((&llvm_cbe_tmp__314->field41));
  *(&llvm_cbe_cppVar_2000) = (llvm_cbe_tmp__355 & llvm_cbe_tmp__356);
  llvm_cbe_tmp__357 = *(&llvm_cbe_cppVar_2000);
  llvm_cbe_tmp__358 = _ZN8type_memIhLj65536EE2rdEl(((&llvm_cbe_tmp__314->field4)), llvm_cbe_tmp__357);
  *(&llvm_cbe_cppVar_2001) = llvm_cbe_tmp__358;
  llvm_cbe_tmp__359 = *(&llvm_cbe_cppVar_2001);
  llvm_cbe_tmp__360 = *((&llvm_cbe_tmp__314->field48));
  *(&llvm_cbe_cppVar_2002) = ((((signed long long )(((signed long long )llvm_cbe_tmp__359) >> ((signed long long )1ull)))) & llvm_cbe_tmp__360);
  llvm_cbe_tmp__361 = *(&llvm_cbe_cppVar_2002);
  llvm_cbe_tmp__362 = *((&llvm_cbe_tmp__314->field53));
  llvm_cbe_tmp__363 = *(&llvm_cbe_cppVar_2002);
  if (((llvm_cbe_tmp__361 & llvm_cbe_tmp__362) != 0ull)) {
    goto llvm_cbe_tmp__418;
  } else {
    llvm_cbe_tmp__366__PHI_TEMPORARY = llvm_cbe_tmp__363;   /* for PHI node */
    goto llvm_cbe_tmp__419;
  }

llvm_cbe_tmp__418:
  llvm_cbe_tmp__364 = *((&llvm_cbe_tmp__314->field55));
  llvm_cbe_tmp__365 = llvm_cbe_tmp__363 | llvm_cbe_tmp__364;
  llvm_cbe_tmp__366__PHI_TEMPORARY = llvm_cbe_tmp__365;   /* for PHI node */
  goto llvm_cbe_tmp__419;

llvm_cbe_tmp__419:
  llvm_cbe_tmp__366 = llvm_cbe_tmp__366__PHI_TEMPORARY;
  *(&llvm_cbe_cppVar_2003) = llvm_cbe_tmp__366;
  llvm_cbe_tmp__367 = *(&llvm_cbe_cppVar_2001);
  llvm_cbe_tmp__368 = *((&llvm_cbe_tmp__314->field40));
  *(&llvm_cbe_cppVar_2004) = ((((signed long long )(((signed long long )llvm_cbe_tmp__367) >> ((signed long long )0ull)))) & llvm_cbe_tmp__368);
  llvm_cbe_tmp__369 = *(&llvm_cbe_cppVar_2003);
  llvm_cbe_tmp__370 = *(&llvm_cbe_cppVar_2004);
  *(&llvm_cbe_cppVar_2005) = ((llvm_cbe_tmp__369 << 1ull) | llvm_cbe_tmp__370);
  llvm_cbe_tmp__371 = *(&llvm_cbe_cppVar_2005);
  llvm_cbe_tmp__372 = *((&llvm_cbe_tmp__314->field41));
  *(&llvm_cbe_cppVar_2005) = (llvm_cbe_tmp__371 & llvm_cbe_tmp__372);
  llvm_cbe_tmp__373 = *(&llvm_cbe_cppVar_2005);
  *(&llvm_cbe_cppVar_1993) = llvm_cbe_tmp__373;
  goto llvm_cbe_tmp__420;

llvm_cbe_tmp__417:
  *(&llvm_cbe_cppVar_1993) = 0ull;
  goto llvm_cbe_tmp__420;

llvm_cbe_tmp__420:
  llvm_cbe_tmp__374 = *(&llvm_cbe_cppVar_1989);
  llvm_cbe_tmp__375 = *(&llvm_cbe_cppVar_1993);
  *(&llvm_cbe_cppVar_2007) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__374) + ((unsigned long long )llvm_cbe_tmp__375))));
  llvm_cbe_tmp__376 = *(&llvm_cbe_cppVar_2007);
  llvm_cbe_tmp__377 = *((&llvm_cbe_tmp__314->field41));
  *(&llvm_cbe_cppVar_2007) = (llvm_cbe_tmp__376 & llvm_cbe_tmp__377);
  llvm_cbe_tmp__378 = *(&llvm_cbe_cppVar_2007);
  llvm_cbe_tmp__379 = _Z7sigmoidl(llvm_cbe_tmp__378);
  *(&llvm_cbe_cppVar_2008) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__379));
  llvm_cbe_tmp__380 = *(&llvm_cbe_cppVar_1988);
  llvm_cbe_tmp__381 = *(&llvm_cbe_cppVar_2008);
  *(&llvm_cbe_cppVar_2009) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__380) < ((signed long long )llvm_cbe_tmp__381))));
  llvm_cbe_tmp__382 = *(&llvm_cbe_cppVar_2009);
  if ((((((bool )llvm_cbe_tmp__382&1u))&1))) {
    goto llvm_cbe_tmp__421;
  } else {
    goto llvm_cbe_tmp__422;
  }

llvm_cbe_tmp__421:
  *(&llvm_cbe_cppVar_1979) = 1ull;
  goto llvm_cbe_tmp__423;

llvm_cbe_tmp__422:
  *(&llvm_cbe_cppVar_1979) = 0ull;
  goto llvm_cbe_tmp__423;

llvm_cbe_tmp__423:
  llvm_cbe_tmp__383 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_2012), ((&llvm_cbe_tmp__314->field6)));
  llvm_cbe_tmp__384 = *(&llvm_cbe_cppVar_1978);
  llvm_cbe_tmp__385 = *(&llvm_cbe_cppVar_1979);
  _ZN8type_memIbLj128EE2wrEll((&llvm_cbe_cppVar_2012), llvm_cbe_tmp__384, llvm_cbe_tmp__385);
  llvm_cbe_tmp__386 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_1976), (&llvm_cbe_cppVar_2012));
  goto llvm_cbe_tmp__424;

llvm_cbe_tmp__412:
  llvm_cbe_tmp__387 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_1976), ((&llvm_cbe_tmp__314->field6)));
  goto llvm_cbe_tmp__424;

llvm_cbe_tmp__424:
  llvm_cbe_tmp__388 = *((&llvm_cbe_tmp__314->field11));
  llvm_cbe_tmp__389 = *((&llvm_cbe_tmp__314->field48));
  *(&llvm_cbe_cppVar_2013) = ((((signed long long )(((signed long long )llvm_cbe_tmp__388) >> ((signed long long )0ull)))) & llvm_cbe_tmp__389);
  llvm_cbe_tmp__390 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_2014), (&llvm_cbe_cppVar_1976));
  llvm_cbe_tmp__391 = *(&llvm_cbe_cppVar_2013);
  _ZN8type_memIbLj128EE2wrEll((&llvm_cbe_cppVar_2014), llvm_cbe_tmp__391, 1ull);
  llvm_cbe_tmp__392 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_1970), (&llvm_cbe_cppVar_2014));
  goto llvm_cbe_tmp__425;

llvm_cbe_tmp__410:
  llvm_cbe_tmp__393 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_1970), (&llvm_cbe_cppVar_1976));
  goto llvm_cbe_tmp__425;

llvm_cbe_tmp__425:
  llvm_cbe_tmp__394 = _ZN8type_memIbLj128EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_1970));
  goto llvm_cbe_tmp__426;

llvm_cbe_tmp__406:
  llvm_cbe_tmp__395 = *((&llvm_cbe_tmp__314->field24));
  *(&llvm_cbe_cppVar_2017) = (((unsigned char )(bool )(llvm_cbe_tmp__395 == 1ull)));
  llvm_cbe_tmp__396 = *(&llvm_cbe_cppVar_2017);
  if ((((((bool )llvm_cbe_tmp__396&1u))&1))) {
    goto llvm_cbe_tmp__427;
  } else {
    goto llvm_cbe_tmp__428;
  }

llvm_cbe_tmp__427:
  llvm_cbe_tmp__397 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_2015), ((&llvm_cbe_tmp__314->field6)));
  goto llvm_cbe_tmp__429;

llvm_cbe_tmp__428:
  llvm_cbe_tmp__398 = *((&llvm_cbe_tmp__314->field24));
  *(&llvm_cbe_cppVar_2020) = (((unsigned char )(bool )(llvm_cbe_tmp__398 == 2ull)));
  llvm_cbe_tmp__399 = *(&llvm_cbe_cppVar_2020);
  llvm_cbe_tmp__400 = ((((bool )llvm_cbe_tmp__399&1u))&1);
  llvm_cbe_tmp__401 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_2018), ((&llvm_cbe_tmp__314->field6)));
  llvm_cbe_tmp__402 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_2015), (&llvm_cbe_cppVar_2018));
  goto llvm_cbe_tmp__429;

llvm_cbe_tmp__429:
  llvm_cbe_tmp__403 = _ZN8type_memIbLj128EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_2015));
  goto llvm_cbe_tmp__426;

llvm_cbe_tmp__426:
  *(&llvm_cbe_tmp__312) = ((1) & 1);
  *(&llvm_cbe_tmp__313) = 1u;
  llvm_cbe_tmp__404 = ((*(&llvm_cbe_tmp__312))&1);
  if (llvm_cbe_tmp__404) {
    goto llvm_cbe_tmp__430;
  } else {
    goto llvm_cbe_tmp__431;
  }

llvm_cbe_tmp__431:
  _ZN8type_memIbLj128EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__430;

llvm_cbe_tmp__430:
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_2015));
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_2018));
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_1970));
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_2014));
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_1976));
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_2012));
  return StructReturn;
}


void _ZN8type_memIbLj128EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__432;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__433;

  *(&llvm_cbe_tmp__432) = llvm_cbe_this;
  llvm_cbe_tmp__433 = *(&llvm_cbe_tmp__432);
  _ZN8type_memIbLj128EEC2Ev(llvm_cbe_tmp__433);
  return;
}


unsigned long long _ZN8type_memIhLj512EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__434;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__435;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__436;
  unsigned long long llvm_cbe_tmp__437;
  unsigned char *llvm_cbe_tmp__438;
  unsigned char llvm_cbe_tmp__439;

  *(&llvm_cbe_tmp__434) = llvm_cbe_this;
  *(&llvm_cbe_tmp__435) = llvm_cbe_addr;
  llvm_cbe_tmp__436 = *(&llvm_cbe_tmp__434);
  llvm_cbe_tmp__437 = *(&llvm_cbe_tmp__435);
  llvm_cbe_tmp__438 = *((&llvm_cbe_tmp__436->field0));
  llvm_cbe_tmp__439 = *((&llvm_cbe_tmp__438[((signed long long )llvm_cbe_tmp__437)]));
  return (((unsigned long long )(unsigned char )llvm_cbe_tmp__439));
}


unsigned long long _ZN8type_memIhLj65536EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__440;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__441;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__442;
  unsigned long long llvm_cbe_tmp__443;
  unsigned char *llvm_cbe_tmp__444;
  unsigned char llvm_cbe_tmp__445;

  *(&llvm_cbe_tmp__440) = llvm_cbe_this;
  *(&llvm_cbe_tmp__441) = llvm_cbe_addr;
  llvm_cbe_tmp__442 = *(&llvm_cbe_tmp__440);
  llvm_cbe_tmp__443 = *(&llvm_cbe_tmp__441);
  llvm_cbe_tmp__444 = *((&llvm_cbe_tmp__442->field0));
  llvm_cbe_tmp__445 = *((&llvm_cbe_tmp__444[((signed long long )llvm_cbe_tmp__443)]));
  return (((unsigned long long )(unsigned char )llvm_cbe_tmp__445));
}


struct l_class_OC_SysCArray1D *_ZN8type_memIbLj128EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__446;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__447;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__448;
  unsigned char *llvm_cbe_tmp__449;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__450;
  unsigned char *llvm_cbe_tmp__451;

  *(&llvm_cbe_tmp__446) = llvm_cbe_this;
  *(&llvm_cbe_tmp__447) = llvm_cbe_r;
  llvm_cbe_tmp__448 = *(&llvm_cbe_tmp__446);
  llvm_cbe_tmp__449 = *((&llvm_cbe_tmp__448->field0));
  llvm_cbe_tmp__450 = *(&llvm_cbe_tmp__447);
  llvm_cbe_tmp__451 = *((&llvm_cbe_tmp__450->field0));
  __CPROVER_array_copy(llvm_cbe_tmp__449, llvm_cbe_tmp__451);
  return llvm_cbe_tmp__448;
}


void _ZN8type_memIbLj128EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__452;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__453;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__454;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__455;
  unsigned long long llvm_cbe_tmp__456;
  unsigned long long llvm_cbe_tmp__457;
  unsigned char *llvm_cbe_tmp__458;

  *(&llvm_cbe_tmp__452) = llvm_cbe_this;
  *(&llvm_cbe_tmp__453) = llvm_cbe_addr;
  *(&llvm_cbe_tmp__454) = llvm_cbe_data;
  llvm_cbe_tmp__455 = *(&llvm_cbe_tmp__452);
  llvm_cbe_tmp__456 = *(&llvm_cbe_tmp__454);
  llvm_cbe_tmp__457 = *(&llvm_cbe_tmp__453);
  llvm_cbe_tmp__458 = *((&llvm_cbe_tmp__455->field0));
  *((&llvm_cbe_tmp__458[((signed long long )llvm_cbe_tmp__457)])) = (((unsigned char )(bool )(llvm_cbe_tmp__456 != 0ull)));
  return;
}


void _ZN8type_memIbLj128EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__459;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__460;

  *(&llvm_cbe_tmp__459) = llvm_cbe_this;
  llvm_cbe_tmp__460 = *(&llvm_cbe_tmp__459);
  _ZN8type_memIbLj128EED2Ev(llvm_cbe_tmp__460);
  return;
}


unsigned long long _ZN13model_predict18cppUpdateFun_indexElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__461;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__462;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__463;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__464;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__465;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__466;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__467;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__468;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__469;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__470;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__471;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__472;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1355;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1356;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1358;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1359;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1361;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1362;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1364;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1365;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1366;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1367;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1368;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1370;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1371;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1372;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1373;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1374;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1375;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1376;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1369;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1363;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1360;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1357;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1354;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__473;
  unsigned long long llvm_cbe_tmp__474;
  unsigned char llvm_cbe_tmp__475;
  unsigned long long llvm_cbe_tmp__476;
  unsigned long long llvm_cbe_tmp__477;
  unsigned char llvm_cbe_tmp__478;
  unsigned long long llvm_cbe_tmp__479;
  unsigned long long llvm_cbe_tmp__480;
  unsigned char llvm_cbe_tmp__481;
  unsigned long long llvm_cbe_tmp__482;
  unsigned long long llvm_cbe_tmp__483;
  unsigned char llvm_cbe_tmp__484;
  unsigned char llvm_cbe_tmp__485;
  bool llvm_cbe_tmp__486;
  bool llvm_cbe_tmp__487;
  bool llvm_cbe_tmp__487__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__488;
  unsigned long long llvm_cbe_tmp__489;
  unsigned long long llvm_cbe_tmp__490;
  unsigned long long llvm_cbe_tmp__491;
  unsigned long long llvm_cbe_tmp__492;
  unsigned long long llvm_cbe_tmp__493;
  unsigned long long llvm_cbe_tmp__494;
  unsigned long long llvm_cbe_tmp__495;
  unsigned char llvm_cbe_tmp__496;
  unsigned char llvm_cbe_tmp__497;
  bool llvm_cbe_tmp__498;
  bool llvm_cbe_tmp__499;
  bool llvm_cbe_tmp__499__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__500;
  unsigned long long llvm_cbe_tmp__501;
  unsigned long long llvm_cbe_tmp__502;
  unsigned long long llvm_cbe_tmp__503;
  unsigned long long llvm_cbe_tmp__504;
  unsigned long long llvm_cbe_tmp__505;
  unsigned long long llvm_cbe_tmp__506;
  unsigned long long llvm_cbe_tmp__507;
  unsigned long long llvm_cbe_tmp__508;
  unsigned long long llvm_cbe_tmp__509;
  unsigned long long llvm_cbe_tmp__510;
  unsigned long long llvm_cbe_tmp__511;

  *(&llvm_cbe_tmp__461) = llvm_cbe_this;
  *(&llvm_cbe_tmp__462) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__463) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__464) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__465) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__466) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__467) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__468) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__469) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__470) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__471) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__472) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__473 = *(&llvm_cbe_tmp__461);
  llvm_cbe_tmp__474 = *((&llvm_cbe_tmp__473->field24));
  *(&llvm_cbe_cppVar_1356) = (((unsigned char )(bool )(llvm_cbe_tmp__474 == 0ull)));
  llvm_cbe_tmp__475 = *(&llvm_cbe_cppVar_1356);
  if ((((((bool )llvm_cbe_tmp__475&1u))&1))) {
    goto llvm_cbe_tmp__512;
  } else {
    goto llvm_cbe_tmp__513;
  }

llvm_cbe_tmp__512:
  llvm_cbe_tmp__476 = *((&llvm_cbe_tmp__473->field7));
  *(&llvm_cbe_cppVar_1354) = llvm_cbe_tmp__476;
  goto llvm_cbe_tmp__514;

llvm_cbe_tmp__513:
  llvm_cbe_tmp__477 = *((&llvm_cbe_tmp__473->field24));
  *(&llvm_cbe_cppVar_1359) = (((unsigned char )(bool )(llvm_cbe_tmp__477 == 1ull)));
  llvm_cbe_tmp__478 = *(&llvm_cbe_cppVar_1359);
  if ((((((bool )llvm_cbe_tmp__478&1u))&1))) {
    goto llvm_cbe_tmp__515;
  } else {
    goto llvm_cbe_tmp__516;
  }

llvm_cbe_tmp__515:
  llvm_cbe_tmp__479 = *((&llvm_cbe_tmp__473->field7));
  *(&llvm_cbe_cppVar_1357) = llvm_cbe_tmp__479;
  goto llvm_cbe_tmp__517;

llvm_cbe_tmp__516:
  llvm_cbe_tmp__480 = *((&llvm_cbe_tmp__473->field24));
  *(&llvm_cbe_cppVar_1362) = (((unsigned char )(bool )(llvm_cbe_tmp__480 == 2ull)));
  llvm_cbe_tmp__481 = *(&llvm_cbe_cppVar_1362);
  if ((((((bool )llvm_cbe_tmp__481&1u))&1))) {
    goto llvm_cbe_tmp__518;
  } else {
    goto llvm_cbe_tmp__519;
  }

llvm_cbe_tmp__518:
  llvm_cbe_tmp__482 = *((&llvm_cbe_tmp__473->field39));
  *(&llvm_cbe_cppVar_1365) = (((unsigned char )(bool )(llvm_cbe_tmp__482 == 0ull)));
  llvm_cbe_tmp__483 = *((&llvm_cbe_tmp__473->field36));
  *(&llvm_cbe_cppVar_1367) = (((unsigned char )(bool )(llvm_cbe_tmp__483 == 1ull)));
  llvm_cbe_tmp__484 = *(&llvm_cbe_cppVar_1365);
  if ((((((bool )llvm_cbe_tmp__484&1u))&1))) {
    goto llvm_cbe_tmp__520;
  } else {
    llvm_cbe_tmp__487__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__521;
  }

llvm_cbe_tmp__520:
  llvm_cbe_tmp__485 = *(&llvm_cbe_cppVar_1367);
  llvm_cbe_tmp__486 = ((((bool )llvm_cbe_tmp__485&1u))&1);
  llvm_cbe_tmp__487__PHI_TEMPORARY = llvm_cbe_tmp__486;   /* for PHI node */
  goto llvm_cbe_tmp__521;

llvm_cbe_tmp__521:
  llvm_cbe_tmp__487 = ((llvm_cbe_tmp__487__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1368) = (((unsigned char )(bool )llvm_cbe_tmp__487));
  llvm_cbe_tmp__488 = *(&llvm_cbe_cppVar_1368);
  if ((((((bool )llvm_cbe_tmp__488&1u))&1))) {
    goto llvm_cbe_tmp__522;
  } else {
    goto llvm_cbe_tmp__523;
  }

llvm_cbe_tmp__522:
  llvm_cbe_tmp__489 = *((&llvm_cbe_tmp__473->field14));
  *(&llvm_cbe_cppVar_1371) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__489) - ((unsigned long long )1ull))));
  llvm_cbe_tmp__490 = *(&llvm_cbe_cppVar_1371);
  llvm_cbe_tmp__491 = *((&llvm_cbe_tmp__473->field41));
  *(&llvm_cbe_cppVar_1371) = (llvm_cbe_tmp__490 & llvm_cbe_tmp__491);
  llvm_cbe_tmp__492 = *((&llvm_cbe_tmp__473->field7));
  llvm_cbe_tmp__493 = *(&llvm_cbe_cppVar_1371);
  *(&llvm_cbe_cppVar_1372) = (((unsigned char )(bool )(llvm_cbe_tmp__492 == llvm_cbe_tmp__493)));
  llvm_cbe_tmp__494 = *((&llvm_cbe_tmp__473->field10));
  llvm_cbe_tmp__495 = *((&llvm_cbe_tmp__473->field12));
  *(&llvm_cbe_cppVar_1373) = (((unsigned char )(bool )(llvm_cbe_tmp__494 == llvm_cbe_tmp__495)));
  llvm_cbe_tmp__496 = *(&llvm_cbe_cppVar_1372);
  if ((((((bool )llvm_cbe_tmp__496&1u))&1))) {
    goto llvm_cbe_tmp__524;
  } else {
    llvm_cbe_tmp__499__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__525;
  }

llvm_cbe_tmp__524:
  llvm_cbe_tmp__497 = *(&llvm_cbe_cppVar_1373);
  llvm_cbe_tmp__498 = ((((bool )llvm_cbe_tmp__497&1u))&1);
  llvm_cbe_tmp__499__PHI_TEMPORARY = llvm_cbe_tmp__498;   /* for PHI node */
  goto llvm_cbe_tmp__525;

llvm_cbe_tmp__525:
  llvm_cbe_tmp__499 = ((llvm_cbe_tmp__499__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1374) = (((unsigned char )(bool )llvm_cbe_tmp__499));
  llvm_cbe_tmp__500 = *(&llvm_cbe_cppVar_1374);
  llvm_cbe_tmp__501 = *((&llvm_cbe_tmp__473->field7));
  if ((((((bool )llvm_cbe_tmp__500&1u))&1))) {
    goto llvm_cbe_tmp__526;
  } else {
    goto llvm_cbe_tmp__527;
  }

llvm_cbe_tmp__526:
  *(&llvm_cbe_cppVar_1369) = llvm_cbe_tmp__501;
  goto llvm_cbe_tmp__528;

llvm_cbe_tmp__527:
  *(&llvm_cbe_cppVar_1376) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__501) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__502 = *(&llvm_cbe_cppVar_1376);
  llvm_cbe_tmp__503 = *((&llvm_cbe_tmp__473->field41));
  *(&llvm_cbe_cppVar_1376) = (llvm_cbe_tmp__502 & llvm_cbe_tmp__503);
  llvm_cbe_tmp__504 = *(&llvm_cbe_cppVar_1376);
  *(&llvm_cbe_cppVar_1369) = llvm_cbe_tmp__504;
  goto llvm_cbe_tmp__528;

llvm_cbe_tmp__528:
  llvm_cbe_tmp__505 = *(&llvm_cbe_cppVar_1369);
  *(&llvm_cbe_cppVar_1363) = llvm_cbe_tmp__505;
  goto llvm_cbe_tmp__529;

llvm_cbe_tmp__523:
  llvm_cbe_tmp__506 = *((&llvm_cbe_tmp__473->field7));
  *(&llvm_cbe_cppVar_1363) = llvm_cbe_tmp__506;
  goto llvm_cbe_tmp__529;

llvm_cbe_tmp__529:
  llvm_cbe_tmp__507 = *(&llvm_cbe_cppVar_1363);
  *(&llvm_cbe_cppVar_1360) = llvm_cbe_tmp__507;
  goto llvm_cbe_tmp__530;

llvm_cbe_tmp__519:
  llvm_cbe_tmp__508 = *((&llvm_cbe_tmp__473->field7));
  *(&llvm_cbe_cppVar_1360) = llvm_cbe_tmp__508;
  goto llvm_cbe_tmp__530;

llvm_cbe_tmp__530:
  llvm_cbe_tmp__509 = *(&llvm_cbe_cppVar_1360);
  *(&llvm_cbe_cppVar_1357) = llvm_cbe_tmp__509;
  goto llvm_cbe_tmp__517;

llvm_cbe_tmp__517:
  llvm_cbe_tmp__510 = *(&llvm_cbe_cppVar_1357);
  *(&llvm_cbe_cppVar_1354) = llvm_cbe_tmp__510;
  goto llvm_cbe_tmp__514;

llvm_cbe_tmp__514:
  llvm_cbe_tmp__511 = *(&llvm_cbe_cppVar_1354);
  return llvm_cbe_tmp__511;
}


unsigned long long _ZN13model_predict19cppUpdateFun_jstateElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__531;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__532;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__533;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__534;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__535;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__536;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__537;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__538;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__539;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__540;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__541;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__542;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1381;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1379;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1380;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1383;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1384;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1416;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1417;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1424;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1425;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1390;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1392;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1393;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1386;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1387;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1388;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1397;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1398;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1399;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1404;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1405;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1406;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1408;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1409;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1410;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1412;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1413;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1414;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1394;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1395;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1391;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1389;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1401;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1402;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1400;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1411;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1407;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1403;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1396;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1385;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1419;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1420;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1421;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1422;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1418;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1423;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1415;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1382;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1378;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__543;
  unsigned long long llvm_cbe_tmp__544;
  unsigned char llvm_cbe_tmp__545;
  unsigned long long llvm_cbe_tmp__546;
  unsigned char llvm_cbe_tmp__547;
  unsigned long long llvm_cbe_tmp__548;
  unsigned char llvm_cbe_tmp__549;
  unsigned char llvm_cbe_tmp__550;
  bool llvm_cbe_tmp__551;
  bool llvm_cbe_tmp__552;
  bool llvm_cbe_tmp__552__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__553;
  unsigned long long llvm_cbe_tmp__554;
  unsigned long long llvm_cbe_tmp__555;
  unsigned char llvm_cbe_tmp__556;
  unsigned long long llvm_cbe_tmp__557;
  unsigned char llvm_cbe_tmp__558;
  unsigned long long llvm_cbe_tmp__559;
  unsigned long long llvm_cbe_tmp__560;
  unsigned long long llvm_cbe_tmp__561;
  unsigned long long llvm_cbe_tmp__562;
  unsigned long long llvm_cbe_tmp__563;
  unsigned long long llvm_cbe_tmp__564;
  unsigned long long llvm_cbe_tmp__565;
  unsigned char llvm_cbe_tmp__566;
  unsigned char llvm_cbe_tmp__567;
  bool llvm_cbe_tmp__568;
  bool llvm_cbe_tmp__569;
  bool llvm_cbe_tmp__569__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__570;
  unsigned long long llvm_cbe_tmp__571;
  unsigned char llvm_cbe_tmp__572;
  unsigned long long llvm_cbe_tmp__573;
  unsigned long long llvm_cbe_tmp__574;
  unsigned long long llvm_cbe_tmp__575;
  unsigned long long llvm_cbe_tmp__576;
  unsigned long long llvm_cbe_tmp__577;
  unsigned long long llvm_cbe_tmp__578;
  unsigned char llvm_cbe_tmp__579;
  unsigned char llvm_cbe_tmp__580;
  bool llvm_cbe_tmp__581;
  bool llvm_cbe_tmp__582;
  bool llvm_cbe_tmp__582__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__583;
  unsigned long long llvm_cbe_tmp__584;
  unsigned long long llvm_cbe_tmp__585;
  unsigned char llvm_cbe_tmp__586;
  unsigned char llvm_cbe_tmp__587;
  bool llvm_cbe_tmp__588;
  bool llvm_cbe_tmp__589;
  bool llvm_cbe_tmp__589__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__590;
  unsigned long long llvm_cbe_tmp__591;
  unsigned long long llvm_cbe_tmp__592;
  unsigned char llvm_cbe_tmp__593;
  unsigned char llvm_cbe_tmp__594;
  bool llvm_cbe_tmp__595;
  bool llvm_cbe_tmp__596;
  bool llvm_cbe_tmp__596__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__597;
  unsigned long long llvm_cbe_tmp__598;
  unsigned long long llvm_cbe_tmp__599;
  unsigned long long llvm_cbe_tmp__600;
  unsigned long long llvm_cbe_tmp__601;
  unsigned long long llvm_cbe_tmp__602;
  unsigned long long llvm_cbe_tmp__603;
  unsigned long long llvm_cbe_tmp__604;
  unsigned long long llvm_cbe_tmp__605;
  unsigned char llvm_cbe_tmp__606;
  unsigned long long llvm_cbe_tmp__607;
  unsigned char llvm_cbe_tmp__608;
  unsigned long long llvm_cbe_tmp__609;
  unsigned long long llvm_cbe_tmp__610;
  unsigned long long llvm_cbe_tmp__611;
  unsigned long long llvm_cbe_tmp__612;
  unsigned long long llvm_cbe_tmp__613;
  unsigned long long llvm_cbe_tmp__614;
  unsigned long long llvm_cbe_tmp__615;
  unsigned long long llvm_cbe_tmp__616;
  unsigned long long llvm_cbe_tmp__617;
  unsigned long long llvm_cbe_tmp__618;
  unsigned long long llvm_cbe_tmp__619;

  *(&llvm_cbe_tmp__531) = llvm_cbe_this;
  *(&llvm_cbe_tmp__532) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__533) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__534) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__535) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__536) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__537) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__538) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__539) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__540) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__541) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__542) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__543 = *(&llvm_cbe_tmp__531);
  llvm_cbe_tmp__544 = *((&llvm_cbe_tmp__543->field24));
  *(&llvm_cbe_cppVar_1380) = (((unsigned char )(bool )(llvm_cbe_tmp__544 == 0ull)));
  llvm_cbe_tmp__545 = *(&llvm_cbe_cppVar_1380);
  if ((((((bool )llvm_cbe_tmp__545&1u))&1))) {
    goto llvm_cbe_tmp__620;
  } else {
    goto llvm_cbe_tmp__621;
  }

llvm_cbe_tmp__620:
  *(&llvm_cbe_cppVar_1378) = 0ull;
  goto llvm_cbe_tmp__622;

llvm_cbe_tmp__621:
  llvm_cbe_tmp__546 = *((&llvm_cbe_tmp__543->field24));
  *(&llvm_cbe_cppVar_1384) = (((unsigned char )(bool )(llvm_cbe_tmp__546 == 1ull)));
  llvm_cbe_tmp__547 = *(&llvm_cbe_cppVar_1384);
  if ((((((bool )llvm_cbe_tmp__547&1u))&1))) {
    goto llvm_cbe_tmp__623;
  } else {
    goto llvm_cbe_tmp__624;
  }

llvm_cbe_tmp__623:
  llvm_cbe_tmp__548 = *((&llvm_cbe_tmp__543->field17));
  *(&llvm_cbe_cppVar_1387) = (((unsigned char )(bool )(llvm_cbe_tmp__548 == 0ull)));
  llvm_cbe_tmp__549 = *(&llvm_cbe_cppVar_1384);
  if ((((((bool )llvm_cbe_tmp__549&1u))&1))) {
    goto llvm_cbe_tmp__625;
  } else {
    llvm_cbe_tmp__552__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__626;
  }

llvm_cbe_tmp__625:
  llvm_cbe_tmp__550 = *(&llvm_cbe_cppVar_1387);
  llvm_cbe_tmp__551 = ((((bool )llvm_cbe_tmp__550&1u))&1);
  llvm_cbe_tmp__552__PHI_TEMPORARY = llvm_cbe_tmp__551;   /* for PHI node */
  goto llvm_cbe_tmp__626;

llvm_cbe_tmp__626:
  llvm_cbe_tmp__552 = ((llvm_cbe_tmp__552__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1388) = (((unsigned char )(bool )llvm_cbe_tmp__552));
  llvm_cbe_tmp__553 = *(&llvm_cbe_cppVar_1388);
  if ((((((bool )llvm_cbe_tmp__553&1u))&1))) {
    goto llvm_cbe_tmp__627;
  } else {
    goto llvm_cbe_tmp__628;
  }

llvm_cbe_tmp__627:
  llvm_cbe_tmp__554 = *((&llvm_cbe_tmp__543->field19));
  llvm_cbe_tmp__555 = *((&llvm_cbe_tmp__543->field11));
  *(&llvm_cbe_cppVar_1390) = (((unsigned char )(bool )(llvm_cbe_tmp__554 == llvm_cbe_tmp__555)));
  llvm_cbe_tmp__556 = *(&llvm_cbe_cppVar_1390);
  llvm_cbe_tmp__557 = *((&llvm_cbe_tmp__543->field9));
  if ((((((bool )llvm_cbe_tmp__556&1u))&1))) {
    goto llvm_cbe_tmp__629;
  } else {
    goto llvm_cbe_tmp__630;
  }

llvm_cbe_tmp__629:
  *(&llvm_cbe_cppVar_1393) = (((unsigned char )(bool )(llvm_cbe_tmp__557 == 4ull)));
  llvm_cbe_tmp__558 = *(&llvm_cbe_cppVar_1393);
  if ((((((bool )llvm_cbe_tmp__558&1u))&1))) {
    goto llvm_cbe_tmp__631;
  } else {
    goto llvm_cbe_tmp__632;
  }

llvm_cbe_tmp__631:
  *(&llvm_cbe_cppVar_1391) = 0ull;
  goto llvm_cbe_tmp__633;

llvm_cbe_tmp__632:
  llvm_cbe_tmp__559 = *((&llvm_cbe_tmp__543->field9));
  *(&llvm_cbe_cppVar_1395) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__559) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__560 = *(&llvm_cbe_cppVar_1395);
  llvm_cbe_tmp__561 = *((&llvm_cbe_tmp__543->field41));
  *(&llvm_cbe_cppVar_1395) = (llvm_cbe_tmp__560 & llvm_cbe_tmp__561);
  llvm_cbe_tmp__562 = *(&llvm_cbe_cppVar_1395);
  *(&llvm_cbe_cppVar_1391) = llvm_cbe_tmp__562;
  goto llvm_cbe_tmp__633;

llvm_cbe_tmp__633:
  llvm_cbe_tmp__563 = *(&llvm_cbe_cppVar_1391);
  *(&llvm_cbe_cppVar_1389) = llvm_cbe_tmp__563;
  goto llvm_cbe_tmp__634;

llvm_cbe_tmp__630:
  *(&llvm_cbe_cppVar_1389) = llvm_cbe_tmp__557;
  goto llvm_cbe_tmp__634;

llvm_cbe_tmp__634:
  llvm_cbe_tmp__564 = *(&llvm_cbe_cppVar_1389);
  *(&llvm_cbe_cppVar_1385) = llvm_cbe_tmp__564;
  goto llvm_cbe_tmp__635;

llvm_cbe_tmp__628:
  llvm_cbe_tmp__565 = *((&llvm_cbe_tmp__543->field17));
  *(&llvm_cbe_cppVar_1398) = (((unsigned char )(bool )(llvm_cbe_tmp__565 == 1ull)));
  llvm_cbe_tmp__566 = *(&llvm_cbe_cppVar_1384);
  if ((((((bool )llvm_cbe_tmp__566&1u))&1))) {
    goto llvm_cbe_tmp__636;
  } else {
    llvm_cbe_tmp__569__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__637;
  }

llvm_cbe_tmp__636:
  llvm_cbe_tmp__567 = *(&llvm_cbe_cppVar_1398);
  llvm_cbe_tmp__568 = ((((bool )llvm_cbe_tmp__567&1u))&1);
  llvm_cbe_tmp__569__PHI_TEMPORARY = llvm_cbe_tmp__568;   /* for PHI node */
  goto llvm_cbe_tmp__637;

llvm_cbe_tmp__637:
  llvm_cbe_tmp__569 = ((llvm_cbe_tmp__569__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1399) = (((unsigned char )(bool )llvm_cbe_tmp__569));
  llvm_cbe_tmp__570 = *(&llvm_cbe_cppVar_1399);
  if ((((((bool )llvm_cbe_tmp__570&1u))&1))) {
    goto llvm_cbe_tmp__638;
  } else {
    goto llvm_cbe_tmp__639;
  }

llvm_cbe_tmp__638:
  llvm_cbe_tmp__571 = *((&llvm_cbe_tmp__543->field9));
  *(&llvm_cbe_cppVar_1393) = (((unsigned char )(bool )(llvm_cbe_tmp__571 == 4ull)));
  llvm_cbe_tmp__572 = *(&llvm_cbe_cppVar_1393);
  if ((((((bool )llvm_cbe_tmp__572&1u))&1))) {
    goto llvm_cbe_tmp__640;
  } else {
    goto llvm_cbe_tmp__641;
  }

llvm_cbe_tmp__640:
  *(&llvm_cbe_cppVar_1400) = 0ull;
  goto llvm_cbe_tmp__642;

llvm_cbe_tmp__641:
  llvm_cbe_tmp__573 = *((&llvm_cbe_tmp__543->field9));
  *(&llvm_cbe_cppVar_1402) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__573) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__574 = *(&llvm_cbe_cppVar_1402);
  llvm_cbe_tmp__575 = *((&llvm_cbe_tmp__543->field41));
  *(&llvm_cbe_cppVar_1402) = (llvm_cbe_tmp__574 & llvm_cbe_tmp__575);
  llvm_cbe_tmp__576 = *(&llvm_cbe_cppVar_1402);
  *(&llvm_cbe_cppVar_1400) = llvm_cbe_tmp__576;
  goto llvm_cbe_tmp__642;

llvm_cbe_tmp__642:
  llvm_cbe_tmp__577 = *(&llvm_cbe_cppVar_1400);
  *(&llvm_cbe_cppVar_1396) = llvm_cbe_tmp__577;
  goto llvm_cbe_tmp__643;

llvm_cbe_tmp__639:
  llvm_cbe_tmp__578 = *((&llvm_cbe_tmp__543->field17));
  *(&llvm_cbe_cppVar_1405) = (((unsigned char )(bool )(llvm_cbe_tmp__578 == 2ull)));
  llvm_cbe_tmp__579 = *(&llvm_cbe_cppVar_1384);
  if ((((((bool )llvm_cbe_tmp__579&1u))&1))) {
    goto llvm_cbe_tmp__644;
  } else {
    llvm_cbe_tmp__582__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__645;
  }

llvm_cbe_tmp__644:
  llvm_cbe_tmp__580 = *(&llvm_cbe_cppVar_1405);
  llvm_cbe_tmp__581 = ((((bool )llvm_cbe_tmp__580&1u))&1);
  llvm_cbe_tmp__582__PHI_TEMPORARY = llvm_cbe_tmp__581;   /* for PHI node */
  goto llvm_cbe_tmp__645;

llvm_cbe_tmp__645:
  llvm_cbe_tmp__582 = ((llvm_cbe_tmp__582__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1406) = (((unsigned char )(bool )llvm_cbe_tmp__582));
  llvm_cbe_tmp__583 = *(&llvm_cbe_cppVar_1406);
  if ((((((bool )llvm_cbe_tmp__583&1u))&1))) {
    goto llvm_cbe_tmp__646;
  } else {
    goto llvm_cbe_tmp__647;
  }

llvm_cbe_tmp__646:
  llvm_cbe_tmp__584 = *(&llvm_cbe_cppVar_1400);
  *(&llvm_cbe_cppVar_1403) = llvm_cbe_tmp__584;
  goto llvm_cbe_tmp__648;

llvm_cbe_tmp__647:
  llvm_cbe_tmp__585 = *((&llvm_cbe_tmp__543->field17));
  *(&llvm_cbe_cppVar_1409) = (((unsigned char )(bool )(llvm_cbe_tmp__585 == 3ull)));
  llvm_cbe_tmp__586 = *(&llvm_cbe_cppVar_1384);
  if ((((((bool )llvm_cbe_tmp__586&1u))&1))) {
    goto llvm_cbe_tmp__649;
  } else {
    llvm_cbe_tmp__589__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__650;
  }

llvm_cbe_tmp__649:
  llvm_cbe_tmp__587 = *(&llvm_cbe_cppVar_1409);
  llvm_cbe_tmp__588 = ((((bool )llvm_cbe_tmp__587&1u))&1);
  llvm_cbe_tmp__589__PHI_TEMPORARY = llvm_cbe_tmp__588;   /* for PHI node */
  goto llvm_cbe_tmp__650;

llvm_cbe_tmp__650:
  llvm_cbe_tmp__589 = ((llvm_cbe_tmp__589__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1410) = (((unsigned char )(bool )llvm_cbe_tmp__589));
  llvm_cbe_tmp__590 = *(&llvm_cbe_cppVar_1410);
  if ((((((bool )llvm_cbe_tmp__590&1u))&1))) {
    goto llvm_cbe_tmp__651;
  } else {
    goto llvm_cbe_tmp__652;
  }

llvm_cbe_tmp__651:
  llvm_cbe_tmp__591 = *(&llvm_cbe_cppVar_1400);
  *(&llvm_cbe_cppVar_1407) = llvm_cbe_tmp__591;
  goto llvm_cbe_tmp__653;

llvm_cbe_tmp__652:
  llvm_cbe_tmp__592 = *((&llvm_cbe_tmp__543->field17));
  *(&llvm_cbe_cppVar_1413) = (((unsigned char )(bool )(llvm_cbe_tmp__592 == 4ull)));
  llvm_cbe_tmp__593 = *(&llvm_cbe_cppVar_1384);
  if ((((((bool )llvm_cbe_tmp__593&1u))&1))) {
    goto llvm_cbe_tmp__654;
  } else {
    llvm_cbe_tmp__596__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__655;
  }

llvm_cbe_tmp__654:
  llvm_cbe_tmp__594 = *(&llvm_cbe_cppVar_1413);
  llvm_cbe_tmp__595 = ((((bool )llvm_cbe_tmp__594&1u))&1);
  llvm_cbe_tmp__596__PHI_TEMPORARY = llvm_cbe_tmp__595;   /* for PHI node */
  goto llvm_cbe_tmp__655;

llvm_cbe_tmp__655:
  llvm_cbe_tmp__596 = ((llvm_cbe_tmp__596__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1414) = (((unsigned char )(bool )llvm_cbe_tmp__596));
  llvm_cbe_tmp__597 = *(&llvm_cbe_cppVar_1414);
  if ((((((bool )llvm_cbe_tmp__597&1u))&1))) {
    goto llvm_cbe_tmp__656;
  } else {
    goto llvm_cbe_tmp__657;
  }

llvm_cbe_tmp__656:
  llvm_cbe_tmp__598 = *(&llvm_cbe_cppVar_1400);
  *(&llvm_cbe_cppVar_1411) = llvm_cbe_tmp__598;
  goto llvm_cbe_tmp__658;

llvm_cbe_tmp__657:
  llvm_cbe_tmp__599 = *((&llvm_cbe_tmp__543->field9));
  *(&llvm_cbe_cppVar_1411) = llvm_cbe_tmp__599;
  goto llvm_cbe_tmp__658;

llvm_cbe_tmp__658:
  llvm_cbe_tmp__600 = *(&llvm_cbe_cppVar_1411);
  *(&llvm_cbe_cppVar_1407) = llvm_cbe_tmp__600;
  goto llvm_cbe_tmp__653;

llvm_cbe_tmp__653:
  llvm_cbe_tmp__601 = *(&llvm_cbe_cppVar_1407);
  *(&llvm_cbe_cppVar_1403) = llvm_cbe_tmp__601;
  goto llvm_cbe_tmp__648;

llvm_cbe_tmp__648:
  llvm_cbe_tmp__602 = *(&llvm_cbe_cppVar_1403);
  *(&llvm_cbe_cppVar_1396) = llvm_cbe_tmp__602;
  goto llvm_cbe_tmp__643;

llvm_cbe_tmp__643:
  llvm_cbe_tmp__603 = *(&llvm_cbe_cppVar_1396);
  *(&llvm_cbe_cppVar_1385) = llvm_cbe_tmp__603;
  goto llvm_cbe_tmp__635;

llvm_cbe_tmp__635:
  llvm_cbe_tmp__604 = *(&llvm_cbe_cppVar_1385);
  *(&llvm_cbe_cppVar_1382) = llvm_cbe_tmp__604;
  goto llvm_cbe_tmp__659;

llvm_cbe_tmp__624:
  llvm_cbe_tmp__605 = *((&llvm_cbe_tmp__543->field24));
  *(&llvm_cbe_cppVar_1417) = (((unsigned char )(bool )(llvm_cbe_tmp__605 == 3ull)));
  llvm_cbe_tmp__606 = *(&llvm_cbe_cppVar_1417);
  if ((((((bool )llvm_cbe_tmp__606&1u))&1))) {
    goto llvm_cbe_tmp__660;
  } else {
    goto llvm_cbe_tmp__661;
  }

llvm_cbe_tmp__660:
  llvm_cbe_tmp__607 = *((&llvm_cbe_tmp__543->field9));
  *(&llvm_cbe_cppVar_1420) = (((unsigned char )(bool )(llvm_cbe_tmp__607 == 4ull)));
  llvm_cbe_tmp__608 = *(&llvm_cbe_cppVar_1420);
  if ((((((bool )llvm_cbe_tmp__608&1u))&1))) {
    goto llvm_cbe_tmp__662;
  } else {
    goto llvm_cbe_tmp__663;
  }

llvm_cbe_tmp__662:
  *(&llvm_cbe_cppVar_1418) = 0ull;
  goto llvm_cbe_tmp__664;

llvm_cbe_tmp__663:
  llvm_cbe_tmp__609 = *((&llvm_cbe_tmp__543->field9));
  *(&llvm_cbe_cppVar_1422) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__609) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__610 = *(&llvm_cbe_cppVar_1422);
  llvm_cbe_tmp__611 = *((&llvm_cbe_tmp__543->field41));
  *(&llvm_cbe_cppVar_1422) = (llvm_cbe_tmp__610 & llvm_cbe_tmp__611);
  llvm_cbe_tmp__612 = *(&llvm_cbe_cppVar_1422);
  *(&llvm_cbe_cppVar_1418) = llvm_cbe_tmp__612;
  goto llvm_cbe_tmp__664;

llvm_cbe_tmp__664:
  llvm_cbe_tmp__613 = *(&llvm_cbe_cppVar_1418);
  *(&llvm_cbe_cppVar_1415) = llvm_cbe_tmp__613;
  goto llvm_cbe_tmp__665;

llvm_cbe_tmp__661:
  llvm_cbe_tmp__614 = *((&llvm_cbe_tmp__543->field24));
  *(&llvm_cbe_cppVar_1425) = (((unsigned char )(bool )(llvm_cbe_tmp__614 == 2ull)));
  llvm_cbe_tmp__615 = *((&llvm_cbe_tmp__543->field9));
  *(&llvm_cbe_cppVar_1423) = llvm_cbe_tmp__615;
  llvm_cbe_tmp__616 = *(&llvm_cbe_cppVar_1423);
  *(&llvm_cbe_cppVar_1415) = llvm_cbe_tmp__616;
  goto llvm_cbe_tmp__665;

llvm_cbe_tmp__665:
  llvm_cbe_tmp__617 = *(&llvm_cbe_cppVar_1415);
  *(&llvm_cbe_cppVar_1382) = llvm_cbe_tmp__617;
  goto llvm_cbe_tmp__659;

llvm_cbe_tmp__659:
  llvm_cbe_tmp__618 = *(&llvm_cbe_cppVar_1382);
  *(&llvm_cbe_cppVar_1378) = llvm_cbe_tmp__618;
  goto llvm_cbe_tmp__622;

llvm_cbe_tmp__622:
  llvm_cbe_tmp__619 = *(&llvm_cbe_cppVar_1378);
  return llvm_cbe_tmp__619;
}


unsigned long long _ZN13model_predict21cppUpdateFun_per_v_pcElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__666;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__667;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__668;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__669;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__670;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__671;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__672;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__673;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__674;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__675;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__676;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__677;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1430;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1443;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1449;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1455;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1461;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1428;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1429;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1432;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1433;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1477;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1478;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1441;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1439;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1440;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1468;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1469;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1470;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1471;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1472;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1473;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1474;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1475;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1435;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1436;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1437;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1445;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1446;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1447;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1451;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1452;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1453;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1457;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1458;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1459;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1463;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1464;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1465;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1442;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1438;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1448;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1454;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1460;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1467;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1466;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1462;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1456;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1450;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1444;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1434;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1476;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1431;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1427;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__678;
  unsigned long long llvm_cbe_tmp__679;
  unsigned char llvm_cbe_tmp__680;
  unsigned long long llvm_cbe_tmp__681;
  unsigned char llvm_cbe_tmp__682;
  unsigned long long llvm_cbe_tmp__683;
  unsigned char llvm_cbe_tmp__684;
  unsigned char llvm_cbe_tmp__685;
  bool llvm_cbe_tmp__686;
  bool llvm_cbe_tmp__687;
  bool llvm_cbe_tmp__687__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__688;
  unsigned long long llvm_cbe_tmp__689;
  unsigned long long llvm_cbe_tmp__690;
  unsigned long long llvm_cbe_tmp__691;
  unsigned char llvm_cbe_tmp__692;
  unsigned char llvm_cbe_tmp__693;
  bool llvm_cbe_tmp__694;
  bool llvm_cbe_tmp__695;
  bool llvm_cbe_tmp__695__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__696;
  unsigned long long llvm_cbe_tmp__697;
  unsigned long long llvm_cbe_tmp__698;
  unsigned long long llvm_cbe_tmp__699;
  unsigned char llvm_cbe_tmp__700;
  unsigned char llvm_cbe_tmp__701;
  bool llvm_cbe_tmp__702;
  bool llvm_cbe_tmp__703;
  bool llvm_cbe_tmp__703__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__704;
  unsigned long long llvm_cbe_tmp__705;
  unsigned char llvm_cbe_tmp__706;
  unsigned long long llvm_cbe_tmp__707;
  unsigned long long llvm_cbe_tmp__708;
  unsigned long long llvm_cbe_tmp__709;
  unsigned char llvm_cbe_tmp__710;
  unsigned char llvm_cbe_tmp__711;
  bool llvm_cbe_tmp__712;
  bool llvm_cbe_tmp__713;
  bool llvm_cbe_tmp__713__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__714;
  unsigned long long llvm_cbe_tmp__715;
  unsigned char llvm_cbe_tmp__716;
  unsigned long long llvm_cbe_tmp__717;
  unsigned long long llvm_cbe_tmp__718;
  unsigned long long llvm_cbe_tmp__719;
  unsigned char llvm_cbe_tmp__720;
  unsigned char llvm_cbe_tmp__721;
  bool llvm_cbe_tmp__722;
  bool llvm_cbe_tmp__723;
  bool llvm_cbe_tmp__723__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__724;
  unsigned long long llvm_cbe_tmp__725;
  unsigned char llvm_cbe_tmp__726;
  unsigned long long llvm_cbe_tmp__727;
  unsigned long long llvm_cbe_tmp__728;
  unsigned long long llvm_cbe_tmp__729;
  unsigned char llvm_cbe_tmp__730;
  unsigned char llvm_cbe_tmp__731;
  bool llvm_cbe_tmp__732;
  bool llvm_cbe_tmp__733;
  bool llvm_cbe_tmp__733__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__734;
  unsigned long long llvm_cbe_tmp__735;
  unsigned char llvm_cbe_tmp__736;
  unsigned long long llvm_cbe_tmp__737;
  unsigned long long llvm_cbe_tmp__738;
  unsigned long long llvm_cbe_tmp__739;
  unsigned long long llvm_cbe_tmp__740;
  unsigned long long llvm_cbe_tmp__741;
  unsigned long long llvm_cbe_tmp__742;
  unsigned long long llvm_cbe_tmp__743;
  unsigned long long llvm_cbe_tmp__744;
  unsigned long long llvm_cbe_tmp__745;
  unsigned char llvm_cbe_tmp__746;
  unsigned char llvm_cbe_tmp__747;
  bool llvm_cbe_tmp__748;
  bool llvm_cbe_tmp__749;
  bool llvm_cbe_tmp__749__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__750;
  unsigned long long llvm_cbe_tmp__751;
  unsigned long long llvm_cbe_tmp__752;
  unsigned long long llvm_cbe_tmp__753;
  unsigned long long llvm_cbe_tmp__754;
  unsigned long long llvm_cbe_tmp__755;
  unsigned long long llvm_cbe_tmp__756;
  unsigned long long llvm_cbe_tmp__757;
  unsigned long long llvm_cbe_tmp__758;
  unsigned long long llvm_cbe_tmp__759;
  unsigned long long llvm_cbe_tmp__760;
  unsigned long long llvm_cbe_tmp__761;
  unsigned long long llvm_cbe_tmp__762;
  unsigned long long llvm_cbe_tmp__763;

  *(&llvm_cbe_tmp__666) = llvm_cbe_this;
  *(&llvm_cbe_tmp__667) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__668) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__669) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__670) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__671) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__672) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__673) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__674) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__675) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__676) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__677) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__678 = *(&llvm_cbe_tmp__666);
  llvm_cbe_tmp__679 = *((&llvm_cbe_tmp__678->field24));
  *(&llvm_cbe_cppVar_1429) = (((unsigned char )(bool )(llvm_cbe_tmp__679 == 0ull)));
  llvm_cbe_tmp__680 = *(&llvm_cbe_cppVar_1429);
  if ((((((bool )llvm_cbe_tmp__680&1u))&1))) {
    goto llvm_cbe_tmp__764;
  } else {
    goto llvm_cbe_tmp__765;
  }

llvm_cbe_tmp__764:
  *(&llvm_cbe_cppVar_1427) = 0ull;
  goto llvm_cbe_tmp__766;

llvm_cbe_tmp__765:
  llvm_cbe_tmp__681 = *((&llvm_cbe_tmp__678->field24));
  *(&llvm_cbe_cppVar_1433) = (((unsigned char )(bool )(llvm_cbe_tmp__681 == 1ull)));
  llvm_cbe_tmp__682 = *(&llvm_cbe_cppVar_1433);
  if ((((((bool )llvm_cbe_tmp__682&1u))&1))) {
    goto llvm_cbe_tmp__767;
  } else {
    goto llvm_cbe_tmp__768;
  }

llvm_cbe_tmp__767:
  llvm_cbe_tmp__683 = *((&llvm_cbe_tmp__678->field17));
  *(&llvm_cbe_cppVar_1436) = (((unsigned char )(bool )(llvm_cbe_tmp__683 == 0ull)));
  llvm_cbe_tmp__684 = *(&llvm_cbe_cppVar_1433);
  if ((((((bool )llvm_cbe_tmp__684&1u))&1))) {
    goto llvm_cbe_tmp__769;
  } else {
    llvm_cbe_tmp__687__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__770;
  }

llvm_cbe_tmp__769:
  llvm_cbe_tmp__685 = *(&llvm_cbe_cppVar_1436);
  llvm_cbe_tmp__686 = ((((bool )llvm_cbe_tmp__685&1u))&1);
  llvm_cbe_tmp__687__PHI_TEMPORARY = llvm_cbe_tmp__686;   /* for PHI node */
  goto llvm_cbe_tmp__770;

llvm_cbe_tmp__770:
  llvm_cbe_tmp__687 = ((llvm_cbe_tmp__687__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1437) = (((unsigned char )(bool )llvm_cbe_tmp__687));
  llvm_cbe_tmp__688 = *(&llvm_cbe_cppVar_1437);
  if ((((((bool )llvm_cbe_tmp__688&1u))&1))) {
    goto llvm_cbe_tmp__771;
  } else {
    goto llvm_cbe_tmp__772;
  }

llvm_cbe_tmp__771:
  llvm_cbe_tmp__689 = *((&llvm_cbe_tmp__678->field9));
  *(&llvm_cbe_cppVar_1440) = (((unsigned char )(bool )(llvm_cbe_tmp__689 == 4ull)));
  llvm_cbe_tmp__690 = *((&llvm_cbe_tmp__678->field19));
  llvm_cbe_tmp__691 = *((&llvm_cbe_tmp__678->field11));
  *(&llvm_cbe_cppVar_1441) = (((unsigned char )(bool )(llvm_cbe_tmp__690 == llvm_cbe_tmp__691)));
  llvm_cbe_tmp__692 = *(&llvm_cbe_cppVar_1440);
  if ((((((bool )llvm_cbe_tmp__692&1u))&1))) {
    goto llvm_cbe_tmp__773;
  } else {
    llvm_cbe_tmp__695__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__774;
  }

llvm_cbe_tmp__773:
  llvm_cbe_tmp__693 = *(&llvm_cbe_cppVar_1441);
  llvm_cbe_tmp__694 = ((((bool )llvm_cbe_tmp__693&1u))&1);
  llvm_cbe_tmp__695__PHI_TEMPORARY = llvm_cbe_tmp__694;   /* for PHI node */
  goto llvm_cbe_tmp__774;

llvm_cbe_tmp__774:
  llvm_cbe_tmp__695 = ((llvm_cbe_tmp__695__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1442) = (((unsigned char )(bool )llvm_cbe_tmp__695));
  llvm_cbe_tmp__696 = *(&llvm_cbe_cppVar_1442);
  if ((((((bool )llvm_cbe_tmp__696&1u))&1))) {
    goto llvm_cbe_tmp__775;
  } else {
    goto llvm_cbe_tmp__776;
  }

llvm_cbe_tmp__775:
  *(&llvm_cbe_cppVar_1438) = 1ull;
  goto llvm_cbe_tmp__777;

llvm_cbe_tmp__776:
  llvm_cbe_tmp__697 = *((&llvm_cbe_tmp__678->field17));
  *(&llvm_cbe_cppVar_1438) = llvm_cbe_tmp__697;
  goto llvm_cbe_tmp__777;

llvm_cbe_tmp__777:
  llvm_cbe_tmp__698 = *(&llvm_cbe_cppVar_1438);
  *(&llvm_cbe_cppVar_1434) = llvm_cbe_tmp__698;
  goto llvm_cbe_tmp__778;

llvm_cbe_tmp__772:
  llvm_cbe_tmp__699 = *((&llvm_cbe_tmp__678->field17));
  *(&llvm_cbe_cppVar_1446) = (((unsigned char )(bool )(llvm_cbe_tmp__699 == 1ull)));
  llvm_cbe_tmp__700 = *(&llvm_cbe_cppVar_1433);
  if ((((((bool )llvm_cbe_tmp__700&1u))&1))) {
    goto llvm_cbe_tmp__779;
  } else {
    llvm_cbe_tmp__703__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__780;
  }

llvm_cbe_tmp__779:
  llvm_cbe_tmp__701 = *(&llvm_cbe_cppVar_1446);
  llvm_cbe_tmp__702 = ((((bool )llvm_cbe_tmp__701&1u))&1);
  llvm_cbe_tmp__703__PHI_TEMPORARY = llvm_cbe_tmp__702;   /* for PHI node */
  goto llvm_cbe_tmp__780;

llvm_cbe_tmp__780:
  llvm_cbe_tmp__703 = ((llvm_cbe_tmp__703__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1447) = (((unsigned char )(bool )llvm_cbe_tmp__703));
  llvm_cbe_tmp__704 = *(&llvm_cbe_cppVar_1447);
  if ((((((bool )llvm_cbe_tmp__704&1u))&1))) {
    goto llvm_cbe_tmp__781;
  } else {
    goto llvm_cbe_tmp__782;
  }

llvm_cbe_tmp__781:
  llvm_cbe_tmp__705 = *((&llvm_cbe_tmp__678->field9));
  *(&llvm_cbe_cppVar_1440) = (((unsigned char )(bool )(llvm_cbe_tmp__705 == 4ull)));
  llvm_cbe_tmp__706 = *(&llvm_cbe_cppVar_1440);
  if ((((((bool )llvm_cbe_tmp__706&1u))&1))) {
    goto llvm_cbe_tmp__783;
  } else {
    goto llvm_cbe_tmp__784;
  }

llvm_cbe_tmp__783:
  *(&llvm_cbe_cppVar_1448) = 2ull;
  goto llvm_cbe_tmp__785;

llvm_cbe_tmp__784:
  llvm_cbe_tmp__707 = *((&llvm_cbe_tmp__678->field17));
  *(&llvm_cbe_cppVar_1448) = llvm_cbe_tmp__707;
  goto llvm_cbe_tmp__785;

llvm_cbe_tmp__785:
  llvm_cbe_tmp__708 = *(&llvm_cbe_cppVar_1448);
  *(&llvm_cbe_cppVar_1444) = llvm_cbe_tmp__708;
  goto llvm_cbe_tmp__786;

llvm_cbe_tmp__782:
  llvm_cbe_tmp__709 = *((&llvm_cbe_tmp__678->field17));
  *(&llvm_cbe_cppVar_1452) = (((unsigned char )(bool )(llvm_cbe_tmp__709 == 2ull)));
  llvm_cbe_tmp__710 = *(&llvm_cbe_cppVar_1433);
  if ((((((bool )llvm_cbe_tmp__710&1u))&1))) {
    goto llvm_cbe_tmp__787;
  } else {
    llvm_cbe_tmp__713__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__788;
  }

llvm_cbe_tmp__787:
  llvm_cbe_tmp__711 = *(&llvm_cbe_cppVar_1452);
  llvm_cbe_tmp__712 = ((((bool )llvm_cbe_tmp__711&1u))&1);
  llvm_cbe_tmp__713__PHI_TEMPORARY = llvm_cbe_tmp__712;   /* for PHI node */
  goto llvm_cbe_tmp__788;

llvm_cbe_tmp__788:
  llvm_cbe_tmp__713 = ((llvm_cbe_tmp__713__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1453) = (((unsigned char )(bool )llvm_cbe_tmp__713));
  llvm_cbe_tmp__714 = *(&llvm_cbe_cppVar_1453);
  if ((((((bool )llvm_cbe_tmp__714&1u))&1))) {
    goto llvm_cbe_tmp__789;
  } else {
    goto llvm_cbe_tmp__790;
  }

llvm_cbe_tmp__789:
  llvm_cbe_tmp__715 = *((&llvm_cbe_tmp__678->field9));
  *(&llvm_cbe_cppVar_1440) = (((unsigned char )(bool )(llvm_cbe_tmp__715 == 4ull)));
  llvm_cbe_tmp__716 = *(&llvm_cbe_cppVar_1440);
  if ((((((bool )llvm_cbe_tmp__716&1u))&1))) {
    goto llvm_cbe_tmp__791;
  } else {
    goto llvm_cbe_tmp__792;
  }

llvm_cbe_tmp__791:
  *(&llvm_cbe_cppVar_1454) = 3ull;
  goto llvm_cbe_tmp__793;

llvm_cbe_tmp__792:
  llvm_cbe_tmp__717 = *((&llvm_cbe_tmp__678->field17));
  *(&llvm_cbe_cppVar_1454) = llvm_cbe_tmp__717;
  goto llvm_cbe_tmp__793;

llvm_cbe_tmp__793:
  llvm_cbe_tmp__718 = *(&llvm_cbe_cppVar_1454);
  *(&llvm_cbe_cppVar_1450) = llvm_cbe_tmp__718;
  goto llvm_cbe_tmp__794;

llvm_cbe_tmp__790:
  llvm_cbe_tmp__719 = *((&llvm_cbe_tmp__678->field17));
  *(&llvm_cbe_cppVar_1458) = (((unsigned char )(bool )(llvm_cbe_tmp__719 == 3ull)));
  llvm_cbe_tmp__720 = *(&llvm_cbe_cppVar_1433);
  if ((((((bool )llvm_cbe_tmp__720&1u))&1))) {
    goto llvm_cbe_tmp__795;
  } else {
    llvm_cbe_tmp__723__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__796;
  }

llvm_cbe_tmp__795:
  llvm_cbe_tmp__721 = *(&llvm_cbe_cppVar_1458);
  llvm_cbe_tmp__722 = ((((bool )llvm_cbe_tmp__721&1u))&1);
  llvm_cbe_tmp__723__PHI_TEMPORARY = llvm_cbe_tmp__722;   /* for PHI node */
  goto llvm_cbe_tmp__796;

llvm_cbe_tmp__796:
  llvm_cbe_tmp__723 = ((llvm_cbe_tmp__723__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1459) = (((unsigned char )(bool )llvm_cbe_tmp__723));
  llvm_cbe_tmp__724 = *(&llvm_cbe_cppVar_1459);
  if ((((((bool )llvm_cbe_tmp__724&1u))&1))) {
    goto llvm_cbe_tmp__797;
  } else {
    goto llvm_cbe_tmp__798;
  }

llvm_cbe_tmp__797:
  llvm_cbe_tmp__725 = *((&llvm_cbe_tmp__678->field9));
  *(&llvm_cbe_cppVar_1440) = (((unsigned char )(bool )(llvm_cbe_tmp__725 == 4ull)));
  llvm_cbe_tmp__726 = *(&llvm_cbe_cppVar_1440);
  if ((((((bool )llvm_cbe_tmp__726&1u))&1))) {
    goto llvm_cbe_tmp__799;
  } else {
    goto llvm_cbe_tmp__800;
  }

llvm_cbe_tmp__799:
  *(&llvm_cbe_cppVar_1460) = 4ull;
  goto llvm_cbe_tmp__801;

llvm_cbe_tmp__800:
  llvm_cbe_tmp__727 = *((&llvm_cbe_tmp__678->field17));
  *(&llvm_cbe_cppVar_1460) = llvm_cbe_tmp__727;
  goto llvm_cbe_tmp__801;

llvm_cbe_tmp__801:
  llvm_cbe_tmp__728 = *(&llvm_cbe_cppVar_1460);
  *(&llvm_cbe_cppVar_1456) = llvm_cbe_tmp__728;
  goto llvm_cbe_tmp__802;

llvm_cbe_tmp__798:
  llvm_cbe_tmp__729 = *((&llvm_cbe_tmp__678->field17));
  *(&llvm_cbe_cppVar_1464) = (((unsigned char )(bool )(llvm_cbe_tmp__729 == 4ull)));
  llvm_cbe_tmp__730 = *(&llvm_cbe_cppVar_1433);
  if ((((((bool )llvm_cbe_tmp__730&1u))&1))) {
    goto llvm_cbe_tmp__803;
  } else {
    llvm_cbe_tmp__733__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__804;
  }

llvm_cbe_tmp__803:
  llvm_cbe_tmp__731 = *(&llvm_cbe_cppVar_1464);
  llvm_cbe_tmp__732 = ((((bool )llvm_cbe_tmp__731&1u))&1);
  llvm_cbe_tmp__733__PHI_TEMPORARY = llvm_cbe_tmp__732;   /* for PHI node */
  goto llvm_cbe_tmp__804;

llvm_cbe_tmp__804:
  llvm_cbe_tmp__733 = ((llvm_cbe_tmp__733__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1465) = (((unsigned char )(bool )llvm_cbe_tmp__733));
  llvm_cbe_tmp__734 = *(&llvm_cbe_cppVar_1465);
  if ((((((bool )llvm_cbe_tmp__734&1u))&1))) {
    goto llvm_cbe_tmp__805;
  } else {
    goto llvm_cbe_tmp__806;
  }

llvm_cbe_tmp__805:
  llvm_cbe_tmp__735 = *((&llvm_cbe_tmp__678->field9));
  *(&llvm_cbe_cppVar_1440) = (((unsigned char )(bool )(llvm_cbe_tmp__735 == 4ull)));
  llvm_cbe_tmp__736 = *(&llvm_cbe_cppVar_1440);
  if ((((((bool )llvm_cbe_tmp__736&1u))&1))) {
    goto llvm_cbe_tmp__807;
  } else {
    goto llvm_cbe_tmp__808;
  }

llvm_cbe_tmp__807:
  llvm_cbe_tmp__737 = *((&llvm_cbe_tmp__678->field25));
  *(&llvm_cbe_cppVar_1469) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__737) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__738 = *(&llvm_cbe_cppVar_1469);
  llvm_cbe_tmp__739 = *((&llvm_cbe_tmp__678->field41));
  *(&llvm_cbe_cppVar_1469) = (llvm_cbe_tmp__738 & llvm_cbe_tmp__739);
  llvm_cbe_tmp__740 = *(&llvm_cbe_cppVar_1469);
  llvm_cbe_tmp__741 = *((&llvm_cbe_tmp__678->field16));
  *(&llvm_cbe_cppVar_1470) = (((unsigned char )(bool )(llvm_cbe_tmp__740 == llvm_cbe_tmp__741)));
  llvm_cbe_tmp__742 = *((&llvm_cbe_tmp__678->field25));
  *(&llvm_cbe_cppVar_1472) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__742) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__743 = *(&llvm_cbe_cppVar_1472);
  llvm_cbe_tmp__744 = *((&llvm_cbe_tmp__678->field41));
  *(&llvm_cbe_cppVar_1472) = (llvm_cbe_tmp__743 & llvm_cbe_tmp__744);
  llvm_cbe_tmp__745 = *(&llvm_cbe_cppVar_1472);
  *(&llvm_cbe_cppVar_1474) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__745) >= ((signed long long )500ull))));
  llvm_cbe_tmp__746 = *(&llvm_cbe_cppVar_1470);
  if ((((((bool )llvm_cbe_tmp__746&1u))&1))) {
    llvm_cbe_tmp__749__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__809;
  } else {
    goto llvm_cbe_tmp__810;
  }

llvm_cbe_tmp__810:
  llvm_cbe_tmp__747 = *(&llvm_cbe_cppVar_1474);
  llvm_cbe_tmp__748 = ((((bool )llvm_cbe_tmp__747&1u))&1);
  llvm_cbe_tmp__749__PHI_TEMPORARY = llvm_cbe_tmp__748;   /* for PHI node */
  goto llvm_cbe_tmp__809;

llvm_cbe_tmp__809:
  llvm_cbe_tmp__749 = ((llvm_cbe_tmp__749__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1475) = (((unsigned char )(bool )llvm_cbe_tmp__749));
  *(&llvm_cbe_cppVar_1467) = 0ull;
  llvm_cbe_tmp__750 = *(&llvm_cbe_cppVar_1467);
  *(&llvm_cbe_cppVar_1466) = llvm_cbe_tmp__750;
  goto llvm_cbe_tmp__811;

llvm_cbe_tmp__808:
  llvm_cbe_tmp__751 = *((&llvm_cbe_tmp__678->field17));
  *(&llvm_cbe_cppVar_1466) = llvm_cbe_tmp__751;
  goto llvm_cbe_tmp__811;

llvm_cbe_tmp__811:
  llvm_cbe_tmp__752 = *(&llvm_cbe_cppVar_1466);
  *(&llvm_cbe_cppVar_1462) = llvm_cbe_tmp__752;
  goto llvm_cbe_tmp__812;

llvm_cbe_tmp__806:
  llvm_cbe_tmp__753 = *((&llvm_cbe_tmp__678->field17));
  *(&llvm_cbe_cppVar_1462) = llvm_cbe_tmp__753;
  goto llvm_cbe_tmp__812;

llvm_cbe_tmp__812:
  llvm_cbe_tmp__754 = *(&llvm_cbe_cppVar_1462);
  *(&llvm_cbe_cppVar_1456) = llvm_cbe_tmp__754;
  goto llvm_cbe_tmp__802;

llvm_cbe_tmp__802:
  llvm_cbe_tmp__755 = *(&llvm_cbe_cppVar_1456);
  *(&llvm_cbe_cppVar_1450) = llvm_cbe_tmp__755;
  goto llvm_cbe_tmp__794;

llvm_cbe_tmp__794:
  llvm_cbe_tmp__756 = *(&llvm_cbe_cppVar_1450);
  *(&llvm_cbe_cppVar_1444) = llvm_cbe_tmp__756;
  goto llvm_cbe_tmp__786;

llvm_cbe_tmp__786:
  llvm_cbe_tmp__757 = *(&llvm_cbe_cppVar_1444);
  *(&llvm_cbe_cppVar_1434) = llvm_cbe_tmp__757;
  goto llvm_cbe_tmp__778;

llvm_cbe_tmp__778:
  llvm_cbe_tmp__758 = *(&llvm_cbe_cppVar_1434);
  *(&llvm_cbe_cppVar_1431) = llvm_cbe_tmp__758;
  goto llvm_cbe_tmp__813;

llvm_cbe_tmp__768:
  llvm_cbe_tmp__759 = *((&llvm_cbe_tmp__678->field24));
  *(&llvm_cbe_cppVar_1478) = (((unsigned char )(bool )(llvm_cbe_tmp__759 == 2ull)));
  llvm_cbe_tmp__760 = *((&llvm_cbe_tmp__678->field17));
  *(&llvm_cbe_cppVar_1476) = llvm_cbe_tmp__760;
  llvm_cbe_tmp__761 = *(&llvm_cbe_cppVar_1476);
  *(&llvm_cbe_cppVar_1431) = llvm_cbe_tmp__761;
  goto llvm_cbe_tmp__813;

llvm_cbe_tmp__813:
  llvm_cbe_tmp__762 = *(&llvm_cbe_cppVar_1431);
  *(&llvm_cbe_cppVar_1427) = llvm_cbe_tmp__762;
  goto llvm_cbe_tmp__766;

llvm_cbe_tmp__766:
  llvm_cbe_tmp__763 = *(&llvm_cbe_cppVar_1427);
  return llvm_cbe_tmp__763;
}


struct l_unnamed1 _ZN13model_predict17cppUpdateFun_pow2Elllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_unnamed1 StructReturn;  /* Struct return temporary */
  struct l_unnamed1 *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_predict *llvm_cbe_tmp__814;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__815;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__816;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__817;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__818;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__819;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__820;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__821;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__822;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__823;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__824;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__825;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2023;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2024;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2026;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2027;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2054;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2055;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2029;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2030;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2031;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2033;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2034;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2035;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2037;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2038;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2039;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2046;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2047;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2048;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2050;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2051;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2052;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2041;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2042;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2043;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2040;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_2044;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_2049;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__826;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__827;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_2045;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_2036;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_2032;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_2028;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_2053;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_2025;    /* Address-exposed local */
  bool llvm_cbe_tmp__828;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__829;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__830;
  unsigned long long llvm_cbe_tmp__831;
  unsigned char llvm_cbe_tmp__832;
  struct l_unnamed1 *llvm_cbe_tmp__833;
  unsigned long long llvm_cbe_tmp__834;
  unsigned char llvm_cbe_tmp__835;
  unsigned long long llvm_cbe_tmp__836;
  unsigned char llvm_cbe_tmp__837;
  unsigned char llvm_cbe_tmp__838;
  bool llvm_cbe_tmp__839;
  bool llvm_cbe_tmp__840;
  bool llvm_cbe_tmp__840__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__841;
  struct l_unnamed1 *llvm_cbe_tmp__842;
  unsigned long long llvm_cbe_tmp__843;
  unsigned char llvm_cbe_tmp__844;
  unsigned char llvm_cbe_tmp__845;
  bool llvm_cbe_tmp__846;
  bool llvm_cbe_tmp__847;
  bool llvm_cbe_tmp__847__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__848;
  struct l_unnamed1 *llvm_cbe_tmp__849;
  unsigned long long llvm_cbe_tmp__850;
  unsigned char llvm_cbe_tmp__851;
  unsigned char llvm_cbe_tmp__852;
  bool llvm_cbe_tmp__853;
  bool llvm_cbe_tmp__854;
  bool llvm_cbe_tmp__854__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__855;
  unsigned long long llvm_cbe_tmp__856;
  unsigned long long llvm_cbe_tmp__857;
  unsigned long long llvm_cbe_tmp__858;
  unsigned long long llvm_cbe_tmp__859;
  unsigned long long llvm_cbe_tmp__860;
  unsigned long long llvm_cbe_tmp__861;
  unsigned long long llvm_cbe_tmp__862;
  unsigned short llvm_cbe_tmp__863;
  struct l_unnamed1 *llvm_cbe_tmp__864;
  unsigned long long llvm_cbe_tmp__865;
  unsigned long long llvm_cbe_tmp__866;
  struct l_unnamed1 *llvm_cbe_tmp__867;
  unsigned long long llvm_cbe_tmp__868;
  unsigned char llvm_cbe_tmp__869;
  unsigned char llvm_cbe_tmp__870;
  bool llvm_cbe_tmp__871;
  bool llvm_cbe_tmp__872;
  bool llvm_cbe_tmp__872__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__873;
  struct l_unnamed1 *llvm_cbe_tmp__874;
  unsigned long long llvm_cbe_tmp__875;
  unsigned char llvm_cbe_tmp__876;
  unsigned char llvm_cbe_tmp__877;
  bool llvm_cbe_tmp__878;
  bool llvm_cbe_tmp__879;
  bool llvm_cbe_tmp__879__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__880;
  bool llvm_cbe_tmp__881;
  struct l_unnamed1 *llvm_cbe_tmp__882;
  struct l_unnamed1 *llvm_cbe_tmp__883;
  struct l_unnamed1 *llvm_cbe_tmp__884;
  struct l_unnamed1 *llvm_cbe_tmp__885;
  struct l_unnamed1 *llvm_cbe_tmp__886;
  struct l_unnamed1 *llvm_cbe_tmp__887;
  unsigned long long llvm_cbe_tmp__888;
  unsigned char llvm_cbe_tmp__889;
  bool llvm_cbe_tmp__890;
  struct l_unnamed1 *llvm_cbe_tmp__891;
  struct l_unnamed1 *llvm_cbe_tmp__892;
  struct l_unnamed1 *llvm_cbe_tmp__893;
  bool llvm_cbe_tmp__894;

  *(&llvm_cbe_tmp__814) = llvm_cbe_this;
  *(&llvm_cbe_tmp__815) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__816) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__817) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__818) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__819) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__820) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__821) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__822) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__823) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__824) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__825) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__830 = *(&llvm_cbe_tmp__814);
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_2044));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_2049));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_2045));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_2036));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_2032));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_2028));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_2053));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_2025));
  *(&llvm_cbe_tmp__828) = ((0) & 1);
  _ZN8type_memIjLj8EEC1Ev(llvm_cbe_agg_2e_result);
  llvm_cbe_tmp__831 = *((&llvm_cbe_tmp__830->field24));
  *(&llvm_cbe_cppVar_2024) = (((unsigned char )(bool )(llvm_cbe_tmp__831 == 0ull)));
  llvm_cbe_tmp__832 = *(&llvm_cbe_cppVar_2024);
  if ((((((bool )llvm_cbe_tmp__832&1u))&1))) {
    goto llvm_cbe_tmp__895;
  } else {
    goto llvm_cbe_tmp__896;
  }

llvm_cbe_tmp__895:
  llvm_cbe_tmp__833 = _ZN8type_memIjLj8EEaSERKS0_(llvm_cbe_agg_2e_result, ((&llvm_cbe_tmp__830->field18)));
  goto llvm_cbe_tmp__897;

llvm_cbe_tmp__896:
  llvm_cbe_tmp__834 = *((&llvm_cbe_tmp__830->field24));
  *(&llvm_cbe_cppVar_2027) = (((unsigned char )(bool )(llvm_cbe_tmp__834 == 1ull)));
  llvm_cbe_tmp__835 = *(&llvm_cbe_cppVar_2027);
  if ((((((bool )llvm_cbe_tmp__835&1u))&1))) {
    goto llvm_cbe_tmp__898;
  } else {
    goto llvm_cbe_tmp__899;
  }

llvm_cbe_tmp__898:
  llvm_cbe_tmp__836 = *((&llvm_cbe_tmp__830->field17));
  *(&llvm_cbe_cppVar_2030) = (((unsigned char )(bool )(llvm_cbe_tmp__836 == 0ull)));
  llvm_cbe_tmp__837 = *(&llvm_cbe_cppVar_2027);
  if ((((((bool )llvm_cbe_tmp__837&1u))&1))) {
    goto llvm_cbe_tmp__900;
  } else {
    llvm_cbe_tmp__840__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__901;
  }

llvm_cbe_tmp__900:
  llvm_cbe_tmp__838 = *(&llvm_cbe_cppVar_2030);
  llvm_cbe_tmp__839 = ((((bool )llvm_cbe_tmp__838&1u))&1);
  llvm_cbe_tmp__840__PHI_TEMPORARY = llvm_cbe_tmp__839;   /* for PHI node */
  goto llvm_cbe_tmp__901;

llvm_cbe_tmp__901:
  llvm_cbe_tmp__840 = ((llvm_cbe_tmp__840__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_2031) = (((unsigned char )(bool )llvm_cbe_tmp__840));
  llvm_cbe_tmp__841 = *(&llvm_cbe_cppVar_2031);
  if ((((((bool )llvm_cbe_tmp__841&1u))&1))) {
    goto llvm_cbe_tmp__902;
  } else {
    goto llvm_cbe_tmp__903;
  }

llvm_cbe_tmp__902:
  llvm_cbe_tmp__842 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_2028), ((&llvm_cbe_tmp__830->field18)));
  goto llvm_cbe_tmp__904;

llvm_cbe_tmp__903:
  llvm_cbe_tmp__843 = *((&llvm_cbe_tmp__830->field17));
  *(&llvm_cbe_cppVar_2034) = (((unsigned char )(bool )(llvm_cbe_tmp__843 == 1ull)));
  llvm_cbe_tmp__844 = *(&llvm_cbe_cppVar_2027);
  if ((((((bool )llvm_cbe_tmp__844&1u))&1))) {
    goto llvm_cbe_tmp__905;
  } else {
    llvm_cbe_tmp__847__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__906;
  }

llvm_cbe_tmp__905:
  llvm_cbe_tmp__845 = *(&llvm_cbe_cppVar_2034);
  llvm_cbe_tmp__846 = ((((bool )llvm_cbe_tmp__845&1u))&1);
  llvm_cbe_tmp__847__PHI_TEMPORARY = llvm_cbe_tmp__846;   /* for PHI node */
  goto llvm_cbe_tmp__906;

llvm_cbe_tmp__906:
  llvm_cbe_tmp__847 = ((llvm_cbe_tmp__847__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_2035) = (((unsigned char )(bool )llvm_cbe_tmp__847));
  llvm_cbe_tmp__848 = *(&llvm_cbe_cppVar_2035);
  if ((((((bool )llvm_cbe_tmp__848&1u))&1))) {
    goto llvm_cbe_tmp__907;
  } else {
    goto llvm_cbe_tmp__908;
  }

llvm_cbe_tmp__907:
  llvm_cbe_tmp__849 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_2032), ((&llvm_cbe_tmp__830->field18)));
  goto llvm_cbe_tmp__909;

llvm_cbe_tmp__908:
  llvm_cbe_tmp__850 = *((&llvm_cbe_tmp__830->field17));
  *(&llvm_cbe_cppVar_2038) = (((unsigned char )(bool )(llvm_cbe_tmp__850 == 2ull)));
  llvm_cbe_tmp__851 = *(&llvm_cbe_cppVar_2027);
  if ((((((bool )llvm_cbe_tmp__851&1u))&1))) {
    goto llvm_cbe_tmp__910;
  } else {
    llvm_cbe_tmp__854__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__911;
  }

llvm_cbe_tmp__910:
  llvm_cbe_tmp__852 = *(&llvm_cbe_cppVar_2038);
  llvm_cbe_tmp__853 = ((((bool )llvm_cbe_tmp__852&1u))&1);
  llvm_cbe_tmp__854__PHI_TEMPORARY = llvm_cbe_tmp__853;   /* for PHI node */
  goto llvm_cbe_tmp__911;

llvm_cbe_tmp__911:
  llvm_cbe_tmp__854 = ((llvm_cbe_tmp__854__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_2039) = (((unsigned char )(bool )llvm_cbe_tmp__854));
  llvm_cbe_tmp__855 = *(&llvm_cbe_cppVar_2039);
  if ((((((bool )llvm_cbe_tmp__855&1u))&1))) {
    goto llvm_cbe_tmp__912;
  } else {
    goto llvm_cbe_tmp__913;
  }

llvm_cbe_tmp__912:
  llvm_cbe_tmp__856 = *((&llvm_cbe_tmp__830->field9));
  llvm_cbe_tmp__857 = *((&llvm_cbe_tmp__830->field44));
  *(&llvm_cbe_cppVar_2040) = ((((signed long long )(((signed long long )llvm_cbe_tmp__856) >> ((signed long long )0ull)))) & llvm_cbe_tmp__857);
  llvm_cbe_tmp__858 = *((&llvm_cbe_tmp__830->field9));
  llvm_cbe_tmp__859 = *((&llvm_cbe_tmp__830->field44));
  *(&llvm_cbe_cppVar_2041) = ((((signed long long )(((signed long long )llvm_cbe_tmp__858) >> ((signed long long )0ull)))) & llvm_cbe_tmp__859);
  llvm_cbe_tmp__860 = *(&llvm_cbe_cppVar_2041);
  llvm_cbe_tmp__861 = _ZN8type_memItLj8EE2rdEl(((&llvm_cbe_tmp__830->field35)), llvm_cbe_tmp__860);
  *(&llvm_cbe_cppVar_2042) = llvm_cbe_tmp__861;
  llvm_cbe_tmp__862 = *(&llvm_cbe_cppVar_2042);
  llvm_cbe_tmp__863 = _Z10to_int_expl(llvm_cbe_tmp__862);
  *(&llvm_cbe_cppVar_2043) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__863));
  llvm_cbe_tmp__864 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_2044), ((&llvm_cbe_tmp__830->field18)));
  llvm_cbe_tmp__865 = *(&llvm_cbe_cppVar_2040);
  llvm_cbe_tmp__866 = *(&llvm_cbe_cppVar_2043);
  _ZN8type_memIjLj8EE2wrEll((&llvm_cbe_cppVar_2044), llvm_cbe_tmp__865, llvm_cbe_tmp__866);
  llvm_cbe_tmp__867 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_2036), (&llvm_cbe_cppVar_2044));
  goto llvm_cbe_tmp__914;

llvm_cbe_tmp__913:
  llvm_cbe_tmp__868 = *((&llvm_cbe_tmp__830->field17));
  *(&llvm_cbe_cppVar_2047) = (((unsigned char )(bool )(llvm_cbe_tmp__868 == 3ull)));
  llvm_cbe_tmp__869 = *(&llvm_cbe_cppVar_2027);
  if ((((((bool )llvm_cbe_tmp__869&1u))&1))) {
    goto llvm_cbe_tmp__915;
  } else {
    llvm_cbe_tmp__872__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__916;
  }

llvm_cbe_tmp__915:
  llvm_cbe_tmp__870 = *(&llvm_cbe_cppVar_2047);
  llvm_cbe_tmp__871 = ((((bool )llvm_cbe_tmp__870&1u))&1);
  llvm_cbe_tmp__872__PHI_TEMPORARY = llvm_cbe_tmp__871;   /* for PHI node */
  goto llvm_cbe_tmp__916;

llvm_cbe_tmp__916:
  llvm_cbe_tmp__872 = ((llvm_cbe_tmp__872__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_2048) = (((unsigned char )(bool )llvm_cbe_tmp__872));
  llvm_cbe_tmp__873 = *(&llvm_cbe_cppVar_2048);
  if ((((((bool )llvm_cbe_tmp__873&1u))&1))) {
    goto llvm_cbe_tmp__917;
  } else {
    goto llvm_cbe_tmp__918;
  }

llvm_cbe_tmp__917:
  llvm_cbe_tmp__874 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_2045), ((&llvm_cbe_tmp__830->field18)));
  goto llvm_cbe_tmp__919;

llvm_cbe_tmp__918:
  llvm_cbe_tmp__875 = *((&llvm_cbe_tmp__830->field17));
  *(&llvm_cbe_cppVar_2051) = (((unsigned char )(bool )(llvm_cbe_tmp__875 == 4ull)));
  llvm_cbe_tmp__876 = *(&llvm_cbe_cppVar_2027);
  if ((((((bool )llvm_cbe_tmp__876&1u))&1))) {
    goto llvm_cbe_tmp__920;
  } else {
    llvm_cbe_tmp__879__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__921;
  }

llvm_cbe_tmp__920:
  llvm_cbe_tmp__877 = *(&llvm_cbe_cppVar_2051);
  llvm_cbe_tmp__878 = ((((bool )llvm_cbe_tmp__877&1u))&1);
  llvm_cbe_tmp__879__PHI_TEMPORARY = llvm_cbe_tmp__878;   /* for PHI node */
  goto llvm_cbe_tmp__921;

llvm_cbe_tmp__921:
  llvm_cbe_tmp__879 = ((llvm_cbe_tmp__879__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_2052) = (((unsigned char )(bool )llvm_cbe_tmp__879));
  llvm_cbe_tmp__880 = *(&llvm_cbe_cppVar_2052);
  llvm_cbe_tmp__881 = ((((bool )llvm_cbe_tmp__880&1u))&1);
  llvm_cbe_tmp__882 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_2049), ((&llvm_cbe_tmp__830->field18)));
  llvm_cbe_tmp__883 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_2045), (&llvm_cbe_cppVar_2049));
  goto llvm_cbe_tmp__919;

llvm_cbe_tmp__919:
  llvm_cbe_tmp__884 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_2036), (&llvm_cbe_cppVar_2045));
  goto llvm_cbe_tmp__914;

llvm_cbe_tmp__914:
  llvm_cbe_tmp__885 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_2032), (&llvm_cbe_cppVar_2036));
  goto llvm_cbe_tmp__909;

llvm_cbe_tmp__909:
  llvm_cbe_tmp__886 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_2028), (&llvm_cbe_cppVar_2032));
  goto llvm_cbe_tmp__904;

llvm_cbe_tmp__904:
  llvm_cbe_tmp__887 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_2025), (&llvm_cbe_cppVar_2028));
  goto llvm_cbe_tmp__922;

llvm_cbe_tmp__899:
  llvm_cbe_tmp__888 = *((&llvm_cbe_tmp__830->field24));
  *(&llvm_cbe_cppVar_2055) = (((unsigned char )(bool )(llvm_cbe_tmp__888 == 2ull)));
  llvm_cbe_tmp__889 = *(&llvm_cbe_cppVar_2055);
  llvm_cbe_tmp__890 = ((((bool )llvm_cbe_tmp__889&1u))&1);
  llvm_cbe_tmp__891 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_2053), ((&llvm_cbe_tmp__830->field18)));
  llvm_cbe_tmp__892 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_2025), (&llvm_cbe_cppVar_2053));
  goto llvm_cbe_tmp__922;

llvm_cbe_tmp__922:
  llvm_cbe_tmp__893 = _ZN8type_memIjLj8EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_2025));
  goto llvm_cbe_tmp__897;

llvm_cbe_tmp__897:
  *(&llvm_cbe_tmp__828) = ((1) & 1);
  *(&llvm_cbe_tmp__829) = 1u;
  llvm_cbe_tmp__894 = ((*(&llvm_cbe_tmp__828))&1);
  if (llvm_cbe_tmp__894) {
    goto llvm_cbe_tmp__923;
  } else {
    goto llvm_cbe_tmp__924;
  }

llvm_cbe_tmp__924:
  _ZN8type_memIjLj8EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__923;

llvm_cbe_tmp__923:
  _ZN8type_memIjLj8EED1Ev((&llvm_cbe_cppVar_2025));
  _ZN8type_memIjLj8EED1Ev((&llvm_cbe_cppVar_2053));
  _ZN8type_memIjLj8EED1Ev((&llvm_cbe_cppVar_2028));
  _ZN8type_memIjLj8EED1Ev((&llvm_cbe_cppVar_2032));
  _ZN8type_memIjLj8EED1Ev((&llvm_cbe_cppVar_2036));
  _ZN8type_memIjLj8EED1Ev((&llvm_cbe_cppVar_2045));
  _ZN8type_memIjLj8EED1Ev((&llvm_cbe_cppVar_2049));
  _ZN8type_memIjLj8EED1Ev((&llvm_cbe_cppVar_2044));
  return StructReturn;
}


void _ZN8type_memIjLj8EEC1Ev(struct l_unnamed1 *llvm_cbe_this) {
  struct l_unnamed1 *llvm_cbe_tmp__925;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__926;

  *(&llvm_cbe_tmp__925) = llvm_cbe_this;
  llvm_cbe_tmp__926 = *(&llvm_cbe_tmp__925);
  _ZN8type_memIjLj8EEC2Ev(llvm_cbe_tmp__926);
  return;
}


struct l_unnamed1 *_ZN8type_memIjLj8EEaSERKS0_(struct l_unnamed1 *llvm_cbe_this, struct l_unnamed1 *llvm_cbe_r) {
  struct l_unnamed1 *llvm_cbe_tmp__927;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__928;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__929;
  unsigned int *llvm_cbe_tmp__930;
  struct l_unnamed1 *llvm_cbe_tmp__931;
  unsigned int *llvm_cbe_tmp__932;

  *(&llvm_cbe_tmp__927) = llvm_cbe_this;
  *(&llvm_cbe_tmp__928) = llvm_cbe_r;
  llvm_cbe_tmp__929 = *(&llvm_cbe_tmp__927);
  llvm_cbe_tmp__930 = *((&llvm_cbe_tmp__929->field0));
  llvm_cbe_tmp__931 = *(&llvm_cbe_tmp__928);
  llvm_cbe_tmp__932 = *((&llvm_cbe_tmp__931->field0));
  __CPROVER_array_copy((((unsigned char *)llvm_cbe_tmp__930)), (((unsigned char *)llvm_cbe_tmp__932)));
  return llvm_cbe_tmp__929;
}


unsigned long long _ZN8type_memItLj8EE2rdEl(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_unnamed2 *llvm_cbe_tmp__933;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__934;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__935;
  unsigned long long llvm_cbe_tmp__936;
  unsigned short *llvm_cbe_tmp__937;
  unsigned short llvm_cbe_tmp__938;

  *(&llvm_cbe_tmp__933) = llvm_cbe_this;
  *(&llvm_cbe_tmp__934) = llvm_cbe_addr;
  llvm_cbe_tmp__935 = *(&llvm_cbe_tmp__933);
  llvm_cbe_tmp__936 = *(&llvm_cbe_tmp__934);
  llvm_cbe_tmp__937 = *((&llvm_cbe_tmp__935->field0));
  llvm_cbe_tmp__938 = *((&llvm_cbe_tmp__937[((signed long long )llvm_cbe_tmp__936)]));
  return (((unsigned long long )(unsigned short )llvm_cbe_tmp__938));
}


void _ZN8type_memIjLj8EE2wrEll(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) {
  struct l_unnamed1 *llvm_cbe_tmp__939;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__940;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__941;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__942;
  unsigned long long llvm_cbe_tmp__943;
  unsigned long long llvm_cbe_tmp__944;
  unsigned int *llvm_cbe_tmp__945;

  *(&llvm_cbe_tmp__939) = llvm_cbe_this;
  *(&llvm_cbe_tmp__940) = llvm_cbe_addr;
  *(&llvm_cbe_tmp__941) = llvm_cbe_data;
  llvm_cbe_tmp__942 = *(&llvm_cbe_tmp__939);
  llvm_cbe_tmp__943 = *(&llvm_cbe_tmp__941);
  llvm_cbe_tmp__944 = *(&llvm_cbe_tmp__940);
  llvm_cbe_tmp__945 = *((&llvm_cbe_tmp__942->field0));
  *((&llvm_cbe_tmp__945[((signed long long )llvm_cbe_tmp__944)])) = (((unsigned int )llvm_cbe_tmp__943));
  return;
}


void _ZN8type_memIjLj8EED1Ev(struct l_unnamed1 *llvm_cbe_this) {
  struct l_unnamed1 *llvm_cbe_tmp__946;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__947;

  *(&llvm_cbe_tmp__946) = llvm_cbe_this;
  llvm_cbe_tmp__947 = *(&llvm_cbe_tmp__946);
  _ZN8type_memIjLj8EED2Ev(llvm_cbe_tmp__947);
  return;
}


unsigned long long _ZN13model_predict26cppUpdateFun_predict_h_cntElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__948;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__949;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__950;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__951;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__952;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__953;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__954;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__955;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__956;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__957;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__958;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__959;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1489;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1481;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1482;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1493;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1494;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1520;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1521;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1484;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1486;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1487;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1488;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1490;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1491;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1485;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1483;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1500;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1496;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1497;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1498;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1504;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1505;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1506;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1508;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1509;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1510;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1512;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1513;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1514;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1516;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1517;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1518;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1501;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1502;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1499;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1515;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1511;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1507;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1503;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1495;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1519;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1492;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1480;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__960;
  unsigned long long llvm_cbe_tmp__961;
  unsigned char llvm_cbe_tmp__962;
  unsigned long long llvm_cbe_tmp__963;
  unsigned long long llvm_cbe_tmp__964;
  unsigned char llvm_cbe_tmp__965;
  unsigned long long llvm_cbe_tmp__966;
  unsigned long long llvm_cbe_tmp__967;
  unsigned long long llvm_cbe_tmp__968;
  unsigned long long llvm_cbe_tmp__969;
  unsigned long long llvm_cbe_tmp__970;
  unsigned char llvm_cbe_tmp__971;
  unsigned long long llvm_cbe_tmp__972;
  unsigned long long llvm_cbe_tmp__973;
  unsigned long long llvm_cbe_tmp__974;
  unsigned long long llvm_cbe_tmp__975;
  unsigned long long llvm_cbe_tmp__976;
  unsigned long long llvm_cbe_tmp__977;
  unsigned long long llvm_cbe_tmp__978;
  unsigned long long llvm_cbe_tmp__979;
  unsigned char llvm_cbe_tmp__980;
  unsigned long long llvm_cbe_tmp__981;
  unsigned char llvm_cbe_tmp__982;
  unsigned char llvm_cbe_tmp__983;
  bool llvm_cbe_tmp__984;
  bool llvm_cbe_tmp__985;
  bool llvm_cbe_tmp__985__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__986;
  unsigned long long llvm_cbe_tmp__987;
  unsigned long long llvm_cbe_tmp__988;
  unsigned char llvm_cbe_tmp__989;
  unsigned long long llvm_cbe_tmp__990;
  unsigned long long llvm_cbe_tmp__991;
  unsigned long long llvm_cbe_tmp__992;
  unsigned long long llvm_cbe_tmp__993;
  unsigned long long llvm_cbe_tmp__994;
  unsigned long long llvm_cbe_tmp__995;
  unsigned char llvm_cbe_tmp__996;
  unsigned char llvm_cbe_tmp__997;
  bool llvm_cbe_tmp__998;
  bool llvm_cbe_tmp__999;
  bool llvm_cbe_tmp__999__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1000;
  unsigned long long llvm_cbe_tmp__1001;
  unsigned long long llvm_cbe_tmp__1002;
  unsigned char llvm_cbe_tmp__1003;
  unsigned char llvm_cbe_tmp__1004;
  bool llvm_cbe_tmp__1005;
  bool llvm_cbe_tmp__1006;
  bool llvm_cbe_tmp__1006__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1007;
  unsigned long long llvm_cbe_tmp__1008;
  unsigned long long llvm_cbe_tmp__1009;
  unsigned char llvm_cbe_tmp__1010;
  unsigned char llvm_cbe_tmp__1011;
  bool llvm_cbe_tmp__1012;
  bool llvm_cbe_tmp__1013;
  bool llvm_cbe_tmp__1013__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1014;
  unsigned long long llvm_cbe_tmp__1015;
  unsigned long long llvm_cbe_tmp__1016;
  unsigned char llvm_cbe_tmp__1017;
  unsigned char llvm_cbe_tmp__1018;
  bool llvm_cbe_tmp__1019;
  bool llvm_cbe_tmp__1020;
  bool llvm_cbe_tmp__1020__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1021;
  unsigned long long llvm_cbe_tmp__1022;
  unsigned long long llvm_cbe_tmp__1023;
  unsigned long long llvm_cbe_tmp__1024;
  unsigned long long llvm_cbe_tmp__1025;
  unsigned long long llvm_cbe_tmp__1026;
  unsigned long long llvm_cbe_tmp__1027;
  unsigned long long llvm_cbe_tmp__1028;
  unsigned long long llvm_cbe_tmp__1029;
  unsigned long long llvm_cbe_tmp__1030;
  unsigned long long llvm_cbe_tmp__1031;

  *(&llvm_cbe_tmp__948) = llvm_cbe_this;
  *(&llvm_cbe_tmp__949) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__950) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__951) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__952) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__953) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__954) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__955) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__956) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__957) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__958) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__959) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__960 = *(&llvm_cbe_tmp__948);
  llvm_cbe_tmp__961 = *((&llvm_cbe_tmp__960->field24));
  *(&llvm_cbe_cppVar_1482) = (((unsigned char )(bool )(llvm_cbe_tmp__961 == 0ull)));
  llvm_cbe_tmp__962 = *(&llvm_cbe_cppVar_1482);
  if ((((((bool )llvm_cbe_tmp__962&1u))&1))) {
    goto llvm_cbe_tmp__1032;
  } else {
    goto llvm_cbe_tmp__1033;
  }

llvm_cbe_tmp__1032:
  llvm_cbe_tmp__963 = *((&llvm_cbe_tmp__960->field25));
  llvm_cbe_tmp__964 = *((&llvm_cbe_tmp__960->field16));
  *(&llvm_cbe_cppVar_1484) = (((unsigned char )(bool )(llvm_cbe_tmp__963 == llvm_cbe_tmp__964)));
  llvm_cbe_tmp__965 = *(&llvm_cbe_cppVar_1484);
  if ((((((bool )llvm_cbe_tmp__965&1u))&1))) {
    goto llvm_cbe_tmp__1034;
  } else {
    goto llvm_cbe_tmp__1035;
  }

llvm_cbe_tmp__1034:
  llvm_cbe_tmp__966 = *((&llvm_cbe_tmp__960->field11));
  *(&llvm_cbe_cppVar_1487) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__966) - ((unsigned long long )1ull))));
  llvm_cbe_tmp__967 = *(&llvm_cbe_cppVar_1487);
  llvm_cbe_tmp__968 = *((&llvm_cbe_tmp__960->field41));
  *(&llvm_cbe_cppVar_1487) = (llvm_cbe_tmp__967 & llvm_cbe_tmp__968);
  llvm_cbe_tmp__969 = *((&llvm_cbe_tmp__960->field19));
  llvm_cbe_tmp__970 = *(&llvm_cbe_cppVar_1487);
  *(&llvm_cbe_cppVar_1488) = (((unsigned char )(bool )(llvm_cbe_tmp__969 == llvm_cbe_tmp__970)));
  llvm_cbe_tmp__971 = *(&llvm_cbe_cppVar_1488);
  if ((((((bool )llvm_cbe_tmp__971&1u))&1))) {
    goto llvm_cbe_tmp__1036;
  } else {
    goto llvm_cbe_tmp__1037;
  }

llvm_cbe_tmp__1036:
  *(&llvm_cbe_cppVar_1485) = 0ull;
  goto llvm_cbe_tmp__1038;

llvm_cbe_tmp__1037:
  llvm_cbe_tmp__972 = *((&llvm_cbe_tmp__960->field19));
  *(&llvm_cbe_cppVar_1491) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__972) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__973 = *(&llvm_cbe_cppVar_1491);
  llvm_cbe_tmp__974 = *((&llvm_cbe_tmp__960->field41));
  *(&llvm_cbe_cppVar_1491) = (llvm_cbe_tmp__973 & llvm_cbe_tmp__974);
  llvm_cbe_tmp__975 = *(&llvm_cbe_cppVar_1491);
  *(&llvm_cbe_cppVar_1485) = llvm_cbe_tmp__975;
  goto llvm_cbe_tmp__1038;

llvm_cbe_tmp__1038:
  llvm_cbe_tmp__976 = *(&llvm_cbe_cppVar_1485);
  *(&llvm_cbe_cppVar_1483) = llvm_cbe_tmp__976;
  goto llvm_cbe_tmp__1039;

llvm_cbe_tmp__1035:
  llvm_cbe_tmp__977 = *((&llvm_cbe_tmp__960->field19));
  *(&llvm_cbe_cppVar_1483) = llvm_cbe_tmp__977;
  goto llvm_cbe_tmp__1039;

llvm_cbe_tmp__1039:
  llvm_cbe_tmp__978 = *(&llvm_cbe_cppVar_1483);
  *(&llvm_cbe_cppVar_1480) = llvm_cbe_tmp__978;
  goto llvm_cbe_tmp__1040;

llvm_cbe_tmp__1033:
  llvm_cbe_tmp__979 = *((&llvm_cbe_tmp__960->field24));
  *(&llvm_cbe_cppVar_1494) = (((unsigned char )(bool )(llvm_cbe_tmp__979 == 1ull)));
  llvm_cbe_tmp__980 = *(&llvm_cbe_cppVar_1494);
  if ((((((bool )llvm_cbe_tmp__980&1u))&1))) {
    goto llvm_cbe_tmp__1041;
  } else {
    goto llvm_cbe_tmp__1042;
  }

llvm_cbe_tmp__1041:
  llvm_cbe_tmp__981 = *((&llvm_cbe_tmp__960->field17));
  *(&llvm_cbe_cppVar_1497) = (((unsigned char )(bool )(llvm_cbe_tmp__981 == 0ull)));
  llvm_cbe_tmp__982 = *(&llvm_cbe_cppVar_1494);
  if ((((((bool )llvm_cbe_tmp__982&1u))&1))) {
    goto llvm_cbe_tmp__1043;
  } else {
    llvm_cbe_tmp__985__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1044;
  }

llvm_cbe_tmp__1043:
  llvm_cbe_tmp__983 = *(&llvm_cbe_cppVar_1497);
  llvm_cbe_tmp__984 = ((((bool )llvm_cbe_tmp__983&1u))&1);
  llvm_cbe_tmp__985__PHI_TEMPORARY = llvm_cbe_tmp__984;   /* for PHI node */
  goto llvm_cbe_tmp__1044;

llvm_cbe_tmp__1044:
  llvm_cbe_tmp__985 = ((llvm_cbe_tmp__985__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1498) = (((unsigned char )(bool )llvm_cbe_tmp__985));
  llvm_cbe_tmp__986 = *(&llvm_cbe_cppVar_1498);
  if ((((((bool )llvm_cbe_tmp__986&1u))&1))) {
    goto llvm_cbe_tmp__1045;
  } else {
    goto llvm_cbe_tmp__1046;
  }

llvm_cbe_tmp__1045:
  llvm_cbe_tmp__987 = *((&llvm_cbe_tmp__960->field19));
  llvm_cbe_tmp__988 = *((&llvm_cbe_tmp__960->field11));
  *(&llvm_cbe_cppVar_1500) = (((unsigned char )(bool )(llvm_cbe_tmp__987 == llvm_cbe_tmp__988)));
  llvm_cbe_tmp__989 = *(&llvm_cbe_cppVar_1500);
  if ((((((bool )llvm_cbe_tmp__989&1u))&1))) {
    goto llvm_cbe_tmp__1047;
  } else {
    goto llvm_cbe_tmp__1048;
  }

llvm_cbe_tmp__1047:
  *(&llvm_cbe_cppVar_1499) = 0ull;
  goto llvm_cbe_tmp__1049;

llvm_cbe_tmp__1048:
  llvm_cbe_tmp__990 = *((&llvm_cbe_tmp__960->field19));
  *(&llvm_cbe_cppVar_1502) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__990) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__991 = *(&llvm_cbe_cppVar_1502);
  llvm_cbe_tmp__992 = *((&llvm_cbe_tmp__960->field41));
  *(&llvm_cbe_cppVar_1502) = (llvm_cbe_tmp__991 & llvm_cbe_tmp__992);
  llvm_cbe_tmp__993 = *(&llvm_cbe_cppVar_1502);
  *(&llvm_cbe_cppVar_1499) = llvm_cbe_tmp__993;
  goto llvm_cbe_tmp__1049;

llvm_cbe_tmp__1049:
  llvm_cbe_tmp__994 = *(&llvm_cbe_cppVar_1499);
  *(&llvm_cbe_cppVar_1495) = llvm_cbe_tmp__994;
  goto llvm_cbe_tmp__1050;

llvm_cbe_tmp__1046:
  llvm_cbe_tmp__995 = *((&llvm_cbe_tmp__960->field17));
  *(&llvm_cbe_cppVar_1505) = (((unsigned char )(bool )(llvm_cbe_tmp__995 == 1ull)));
  llvm_cbe_tmp__996 = *(&llvm_cbe_cppVar_1494);
  if ((((((bool )llvm_cbe_tmp__996&1u))&1))) {
    goto llvm_cbe_tmp__1051;
  } else {
    llvm_cbe_tmp__999__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1052;
  }

llvm_cbe_tmp__1051:
  llvm_cbe_tmp__997 = *(&llvm_cbe_cppVar_1505);
  llvm_cbe_tmp__998 = ((((bool )llvm_cbe_tmp__997&1u))&1);
  llvm_cbe_tmp__999__PHI_TEMPORARY = llvm_cbe_tmp__998;   /* for PHI node */
  goto llvm_cbe_tmp__1052;

llvm_cbe_tmp__1052:
  llvm_cbe_tmp__999 = ((llvm_cbe_tmp__999__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1506) = (((unsigned char )(bool )llvm_cbe_tmp__999));
  llvm_cbe_tmp__1000 = *(&llvm_cbe_cppVar_1506);
  if ((((((bool )llvm_cbe_tmp__1000&1u))&1))) {
    goto llvm_cbe_tmp__1053;
  } else {
    goto llvm_cbe_tmp__1054;
  }

llvm_cbe_tmp__1053:
  llvm_cbe_tmp__1001 = *((&llvm_cbe_tmp__960->field19));
  *(&llvm_cbe_cppVar_1503) = llvm_cbe_tmp__1001;
  goto llvm_cbe_tmp__1055;

llvm_cbe_tmp__1054:
  llvm_cbe_tmp__1002 = *((&llvm_cbe_tmp__960->field17));
  *(&llvm_cbe_cppVar_1509) = (((unsigned char )(bool )(llvm_cbe_tmp__1002 == 2ull)));
  llvm_cbe_tmp__1003 = *(&llvm_cbe_cppVar_1494);
  if ((((((bool )llvm_cbe_tmp__1003&1u))&1))) {
    goto llvm_cbe_tmp__1056;
  } else {
    llvm_cbe_tmp__1006__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1057;
  }

llvm_cbe_tmp__1056:
  llvm_cbe_tmp__1004 = *(&llvm_cbe_cppVar_1509);
  llvm_cbe_tmp__1005 = ((((bool )llvm_cbe_tmp__1004&1u))&1);
  llvm_cbe_tmp__1006__PHI_TEMPORARY = llvm_cbe_tmp__1005;   /* for PHI node */
  goto llvm_cbe_tmp__1057;

llvm_cbe_tmp__1057:
  llvm_cbe_tmp__1006 = ((llvm_cbe_tmp__1006__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1510) = (((unsigned char )(bool )llvm_cbe_tmp__1006));
  llvm_cbe_tmp__1007 = *(&llvm_cbe_cppVar_1510);
  if ((((((bool )llvm_cbe_tmp__1007&1u))&1))) {
    goto llvm_cbe_tmp__1058;
  } else {
    goto llvm_cbe_tmp__1059;
  }

llvm_cbe_tmp__1058:
  llvm_cbe_tmp__1008 = *((&llvm_cbe_tmp__960->field19));
  *(&llvm_cbe_cppVar_1507) = llvm_cbe_tmp__1008;
  goto llvm_cbe_tmp__1060;

llvm_cbe_tmp__1059:
  llvm_cbe_tmp__1009 = *((&llvm_cbe_tmp__960->field17));
  *(&llvm_cbe_cppVar_1513) = (((unsigned char )(bool )(llvm_cbe_tmp__1009 == 3ull)));
  llvm_cbe_tmp__1010 = *(&llvm_cbe_cppVar_1494);
  if ((((((bool )llvm_cbe_tmp__1010&1u))&1))) {
    goto llvm_cbe_tmp__1061;
  } else {
    llvm_cbe_tmp__1013__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1062;
  }

llvm_cbe_tmp__1061:
  llvm_cbe_tmp__1011 = *(&llvm_cbe_cppVar_1513);
  llvm_cbe_tmp__1012 = ((((bool )llvm_cbe_tmp__1011&1u))&1);
  llvm_cbe_tmp__1013__PHI_TEMPORARY = llvm_cbe_tmp__1012;   /* for PHI node */
  goto llvm_cbe_tmp__1062;

llvm_cbe_tmp__1062:
  llvm_cbe_tmp__1013 = ((llvm_cbe_tmp__1013__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1514) = (((unsigned char )(bool )llvm_cbe_tmp__1013));
  llvm_cbe_tmp__1014 = *(&llvm_cbe_cppVar_1514);
  if ((((((bool )llvm_cbe_tmp__1014&1u))&1))) {
    goto llvm_cbe_tmp__1063;
  } else {
    goto llvm_cbe_tmp__1064;
  }

llvm_cbe_tmp__1063:
  llvm_cbe_tmp__1015 = *((&llvm_cbe_tmp__960->field19));
  *(&llvm_cbe_cppVar_1511) = llvm_cbe_tmp__1015;
  goto llvm_cbe_tmp__1065;

llvm_cbe_tmp__1064:
  llvm_cbe_tmp__1016 = *((&llvm_cbe_tmp__960->field17));
  *(&llvm_cbe_cppVar_1517) = (((unsigned char )(bool )(llvm_cbe_tmp__1016 == 4ull)));
  llvm_cbe_tmp__1017 = *(&llvm_cbe_cppVar_1494);
  if ((((((bool )llvm_cbe_tmp__1017&1u))&1))) {
    goto llvm_cbe_tmp__1066;
  } else {
    llvm_cbe_tmp__1020__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1067;
  }

llvm_cbe_tmp__1066:
  llvm_cbe_tmp__1018 = *(&llvm_cbe_cppVar_1517);
  llvm_cbe_tmp__1019 = ((((bool )llvm_cbe_tmp__1018&1u))&1);
  llvm_cbe_tmp__1020__PHI_TEMPORARY = llvm_cbe_tmp__1019;   /* for PHI node */
  goto llvm_cbe_tmp__1067;

llvm_cbe_tmp__1067:
  llvm_cbe_tmp__1020 = ((llvm_cbe_tmp__1020__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1518) = (((unsigned char )(bool )llvm_cbe_tmp__1020));
  llvm_cbe_tmp__1021 = *((&llvm_cbe_tmp__960->field19));
  *(&llvm_cbe_cppVar_1515) = llvm_cbe_tmp__1021;
  llvm_cbe_tmp__1022 = *(&llvm_cbe_cppVar_1515);
  *(&llvm_cbe_cppVar_1511) = llvm_cbe_tmp__1022;
  goto llvm_cbe_tmp__1065;

llvm_cbe_tmp__1065:
  llvm_cbe_tmp__1023 = *(&llvm_cbe_cppVar_1511);
  *(&llvm_cbe_cppVar_1507) = llvm_cbe_tmp__1023;
  goto llvm_cbe_tmp__1060;

llvm_cbe_tmp__1060:
  llvm_cbe_tmp__1024 = *(&llvm_cbe_cppVar_1507);
  *(&llvm_cbe_cppVar_1503) = llvm_cbe_tmp__1024;
  goto llvm_cbe_tmp__1055;

llvm_cbe_tmp__1055:
  llvm_cbe_tmp__1025 = *(&llvm_cbe_cppVar_1503);
  *(&llvm_cbe_cppVar_1495) = llvm_cbe_tmp__1025;
  goto llvm_cbe_tmp__1050;

llvm_cbe_tmp__1050:
  llvm_cbe_tmp__1026 = *(&llvm_cbe_cppVar_1495);
  *(&llvm_cbe_cppVar_1492) = llvm_cbe_tmp__1026;
  goto llvm_cbe_tmp__1068;

llvm_cbe_tmp__1042:
  llvm_cbe_tmp__1027 = *((&llvm_cbe_tmp__960->field24));
  *(&llvm_cbe_cppVar_1521) = (((unsigned char )(bool )(llvm_cbe_tmp__1027 == 2ull)));
  llvm_cbe_tmp__1028 = *((&llvm_cbe_tmp__960->field19));
  *(&llvm_cbe_cppVar_1519) = llvm_cbe_tmp__1028;
  llvm_cbe_tmp__1029 = *(&llvm_cbe_cppVar_1519);
  *(&llvm_cbe_cppVar_1492) = llvm_cbe_tmp__1029;
  goto llvm_cbe_tmp__1068;

llvm_cbe_tmp__1068:
  llvm_cbe_tmp__1030 = *(&llvm_cbe_cppVar_1492);
  *(&llvm_cbe_cppVar_1480) = llvm_cbe_tmp__1030;
  goto llvm_cbe_tmp__1040;

llvm_cbe_tmp__1040:
  llvm_cbe_tmp__1031 = *(&llvm_cbe_cppVar_1480);
  return llvm_cbe_tmp__1031;
}


unsigned long long _ZN13model_predict31cppUpdateFun_predict_input_doneElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__1069;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1070;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1071;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1072;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1073;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1074;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1075;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1076;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1077;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1078;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1079;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1080;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1538;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1524;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1525;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1527;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1528;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1530;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1531;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1533;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1534;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1535;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1536;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1537;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1532;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1529;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1526;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1523;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__1081;
  unsigned long long llvm_cbe_tmp__1082;
  unsigned char llvm_cbe_tmp__1083;
  unsigned long long llvm_cbe_tmp__1084;
  unsigned long long llvm_cbe_tmp__1085;
  unsigned char llvm_cbe_tmp__1086;
  unsigned long long llvm_cbe_tmp__1087;
  unsigned long long llvm_cbe_tmp__1088;
  unsigned char llvm_cbe_tmp__1089;
  unsigned long long llvm_cbe_tmp__1090;
  unsigned long long llvm_cbe_tmp__1091;
  unsigned char llvm_cbe_tmp__1092;
  unsigned char llvm_cbe_tmp__1093;
  bool llvm_cbe_tmp__1094;
  bool llvm_cbe_tmp__1095;
  bool llvm_cbe_tmp__1095__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1096;
  unsigned long long llvm_cbe_tmp__1097;
  unsigned long long llvm_cbe_tmp__1098;
  unsigned long long llvm_cbe_tmp__1099;
  unsigned long long llvm_cbe_tmp__1100;
  unsigned long long llvm_cbe_tmp__1101;
  unsigned long long llvm_cbe_tmp__1102;

  *(&llvm_cbe_tmp__1069) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1070) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1071) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1072) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1073) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1074) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1075) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1076) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1077) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1078) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1079) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1080) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1081 = *(&llvm_cbe_tmp__1069);
  llvm_cbe_tmp__1082 = *((&llvm_cbe_tmp__1081->field24));
  *(&llvm_cbe_cppVar_1525) = (((unsigned char )(bool )(llvm_cbe_tmp__1082 == 0ull)));
  llvm_cbe_tmp__1083 = *(&llvm_cbe_cppVar_1525);
  if ((((((bool )llvm_cbe_tmp__1083&1u))&1))) {
    goto llvm_cbe_tmp__1103;
  } else {
    goto llvm_cbe_tmp__1104;
  }

llvm_cbe_tmp__1103:
  llvm_cbe_tmp__1084 = *((&llvm_cbe_tmp__1081->field20));
  *(&llvm_cbe_cppVar_1523) = llvm_cbe_tmp__1084;
  goto llvm_cbe_tmp__1105;

llvm_cbe_tmp__1104:
  llvm_cbe_tmp__1085 = *((&llvm_cbe_tmp__1081->field24));
  *(&llvm_cbe_cppVar_1528) = (((unsigned char )(bool )(llvm_cbe_tmp__1085 == 1ull)));
  llvm_cbe_tmp__1086 = *(&llvm_cbe_cppVar_1528);
  if ((((((bool )llvm_cbe_tmp__1086&1u))&1))) {
    goto llvm_cbe_tmp__1106;
  } else {
    goto llvm_cbe_tmp__1107;
  }

llvm_cbe_tmp__1106:
  llvm_cbe_tmp__1087 = *((&llvm_cbe_tmp__1081->field20));
  *(&llvm_cbe_cppVar_1526) = llvm_cbe_tmp__1087;
  goto llvm_cbe_tmp__1108;

llvm_cbe_tmp__1107:
  llvm_cbe_tmp__1088 = *((&llvm_cbe_tmp__1081->field24));
  *(&llvm_cbe_cppVar_1531) = (((unsigned char )(bool )(llvm_cbe_tmp__1088 == 2ull)));
  llvm_cbe_tmp__1089 = *(&llvm_cbe_cppVar_1531);
  if ((((((bool )llvm_cbe_tmp__1089&1u))&1))) {
    goto llvm_cbe_tmp__1109;
  } else {
    goto llvm_cbe_tmp__1110;
  }

llvm_cbe_tmp__1109:
  llvm_cbe_tmp__1090 = *((&llvm_cbe_tmp__1081->field39));
  *(&llvm_cbe_cppVar_1534) = (((unsigned char )(bool )(llvm_cbe_tmp__1090 == 0ull)));
  llvm_cbe_tmp__1091 = *((&llvm_cbe_tmp__1081->field36));
  *(&llvm_cbe_cppVar_1536) = (((unsigned char )(bool )(llvm_cbe_tmp__1091 == 1ull)));
  llvm_cbe_tmp__1092 = *(&llvm_cbe_cppVar_1534);
  if ((((((bool )llvm_cbe_tmp__1092&1u))&1))) {
    goto llvm_cbe_tmp__1111;
  } else {
    llvm_cbe_tmp__1095__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1112;
  }

llvm_cbe_tmp__1111:
  llvm_cbe_tmp__1093 = *(&llvm_cbe_cppVar_1536);
  llvm_cbe_tmp__1094 = ((((bool )llvm_cbe_tmp__1093&1u))&1);
  llvm_cbe_tmp__1095__PHI_TEMPORARY = llvm_cbe_tmp__1094;   /* for PHI node */
  goto llvm_cbe_tmp__1112;

llvm_cbe_tmp__1112:
  llvm_cbe_tmp__1095 = ((llvm_cbe_tmp__1095__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1537) = (((unsigned char )(bool )llvm_cbe_tmp__1095));
  llvm_cbe_tmp__1096 = *(&llvm_cbe_cppVar_1537);
  if ((((((bool )llvm_cbe_tmp__1096&1u))&1))) {
    goto llvm_cbe_tmp__1113;
  } else {
    goto llvm_cbe_tmp__1114;
  }

llvm_cbe_tmp__1113:
  *(&llvm_cbe_cppVar_1532) = 0ull;
  goto llvm_cbe_tmp__1115;

llvm_cbe_tmp__1114:
  llvm_cbe_tmp__1097 = *((&llvm_cbe_tmp__1081->field20));
  *(&llvm_cbe_cppVar_1532) = llvm_cbe_tmp__1097;
  goto llvm_cbe_tmp__1115;

llvm_cbe_tmp__1115:
  llvm_cbe_tmp__1098 = *(&llvm_cbe_cppVar_1532);
  *(&llvm_cbe_cppVar_1529) = llvm_cbe_tmp__1098;
  goto llvm_cbe_tmp__1116;

llvm_cbe_tmp__1110:
  llvm_cbe_tmp__1099 = *((&llvm_cbe_tmp__1081->field20));
  *(&llvm_cbe_cppVar_1529) = llvm_cbe_tmp__1099;
  goto llvm_cbe_tmp__1116;

llvm_cbe_tmp__1116:
  llvm_cbe_tmp__1100 = *(&llvm_cbe_cppVar_1529);
  *(&llvm_cbe_cppVar_1526) = llvm_cbe_tmp__1100;
  goto llvm_cbe_tmp__1108;

llvm_cbe_tmp__1108:
  llvm_cbe_tmp__1101 = *(&llvm_cbe_cppVar_1526);
  *(&llvm_cbe_cppVar_1523) = llvm_cbe_tmp__1101;
  goto llvm_cbe_tmp__1105;

llvm_cbe_tmp__1105:
  llvm_cbe_tmp__1102 = *(&llvm_cbe_cppVar_1523);
  return llvm_cbe_tmp__1102;
}


unsigned long long _ZN13model_predict24cppUpdateFun_predict_maxElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__1117;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1118;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1119;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1120;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1121;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1122;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1123;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1124;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1125;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1126;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1127;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1128;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1556;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1541;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1542;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1544;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1545;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1599;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1600;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1562;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1563;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1564;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1551;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1547;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1548;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1549;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1578;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1579;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1580;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1587;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1588;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1589;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1591;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1592;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1593;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1595;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1596;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1597;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1554;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1555;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1553;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1558;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1559;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1560;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1561;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1565;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1566;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1567;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1568;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1569;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1557;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1570;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1572;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1573;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1574;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1575;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1571;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1576;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1552;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1550;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1584;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1582;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1583;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1585;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1581;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1594;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1590;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1586;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1577;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1546;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1598;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1543;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1540;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__1129;
  unsigned long long llvm_cbe_tmp__1130;
  unsigned char llvm_cbe_tmp__1131;
  unsigned long long llvm_cbe_tmp__1132;
  unsigned long long llvm_cbe_tmp__1133;
  unsigned char llvm_cbe_tmp__1134;
  unsigned long long llvm_cbe_tmp__1135;
  unsigned char llvm_cbe_tmp__1136;
  unsigned char llvm_cbe_tmp__1137;
  bool llvm_cbe_tmp__1138;
  bool llvm_cbe_tmp__1139;
  bool llvm_cbe_tmp__1139__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1140;
  unsigned long long llvm_cbe_tmp__1141;
  unsigned long long llvm_cbe_tmp__1142;
  unsigned char llvm_cbe_tmp__1143;
  unsigned long long llvm_cbe_tmp__1144;
  unsigned char llvm_cbe_tmp__1145;
  unsigned long long llvm_cbe_tmp__1146;
  unsigned long long llvm_cbe_tmp__1147;
  unsigned long long llvm_cbe_tmp__1148;
  unsigned long long llvm_cbe_tmp__1149;
  unsigned long long llvm_cbe_tmp__1150;
  unsigned long long llvm_cbe_tmp__1151;
  unsigned char llvm_cbe_tmp__1152;
  unsigned long long llvm_cbe_tmp__1153;
  unsigned long long llvm_cbe_tmp__1154;
  unsigned long long llvm_cbe_tmp__1155;
  unsigned long long llvm_cbe_tmp__1156;
  unsigned long long llvm_cbe_tmp__1157;
  unsigned long long llvm_cbe_tmp__1158;
  unsigned long long llvm_cbe_tmp__1159;
  unsigned long long llvm_cbe_tmp__1160;
  unsigned long long llvm_cbe_tmp__1161;
  unsigned long long llvm_cbe_tmp__1162;
  unsigned long long llvm_cbe_tmp__1163;
  unsigned long long llvm_cbe_tmp__1164;
  unsigned long long llvm_cbe_tmp__1165;
  unsigned long long llvm_cbe_tmp__1166;
  unsigned long long llvm_cbe_tmp__1167;
  unsigned long long llvm_cbe_tmp__1168;
  unsigned long long llvm_cbe_tmp__1169;
  unsigned long long llvm_cbe_tmp__1169__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1170;
  unsigned long long llvm_cbe_tmp__1171;
  unsigned long long llvm_cbe_tmp__1172;
  unsigned long long llvm_cbe_tmp__1173;
  unsigned long long llvm_cbe_tmp__1174;
  unsigned long long llvm_cbe_tmp__1175;
  unsigned long long llvm_cbe_tmp__1176;
  unsigned long long llvm_cbe_tmp__1177;
  unsigned long long llvm_cbe_tmp__1178;
  unsigned long long llvm_cbe_tmp__1179;
  unsigned long long llvm_cbe_tmp__1180;
  unsigned long long llvm_cbe_tmp__1181;
  unsigned char llvm_cbe_tmp__1182;
  unsigned long long llvm_cbe_tmp__1183;
  unsigned long long llvm_cbe_tmp__1184;
  unsigned long long llvm_cbe_tmp__1185;
  unsigned long long llvm_cbe_tmp__1186;
  unsigned long long llvm_cbe_tmp__1187;
  unsigned long long llvm_cbe_tmp__1188;
  unsigned long long llvm_cbe_tmp__1189;
  unsigned long long llvm_cbe_tmp__1190;
  unsigned long long llvm_cbe_tmp__1190__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1191;
  unsigned long long llvm_cbe_tmp__1192;
  unsigned long long llvm_cbe_tmp__1193;
  unsigned long long llvm_cbe_tmp__1194;
  unsigned long long llvm_cbe_tmp__1195;
  unsigned long long llvm_cbe_tmp__1196;
  unsigned long long llvm_cbe_tmp__1196__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1197;
  unsigned long long llvm_cbe_tmp__1198;
  unsigned long long llvm_cbe_tmp__1199;
  unsigned long long llvm_cbe_tmp__1200;
  unsigned long long llvm_cbe_tmp__1201;
  unsigned long long llvm_cbe_tmp__1202;
  unsigned long long llvm_cbe_tmp__1203;
  unsigned char llvm_cbe_tmp__1204;
  unsigned char llvm_cbe_tmp__1205;
  bool llvm_cbe_tmp__1206;
  bool llvm_cbe_tmp__1207;
  bool llvm_cbe_tmp__1207__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1208;
  unsigned long long llvm_cbe_tmp__1209;
  unsigned char llvm_cbe_tmp__1210;
  unsigned long long llvm_cbe_tmp__1211;
  unsigned long long llvm_cbe_tmp__1212;
  unsigned long long llvm_cbe_tmp__1213;
  unsigned long long llvm_cbe_tmp__1214;
  unsigned long long llvm_cbe_tmp__1215;
  unsigned long long llvm_cbe_tmp__1216;
  unsigned char llvm_cbe_tmp__1217;
  unsigned char llvm_cbe_tmp__1218;
  bool llvm_cbe_tmp__1219;
  bool llvm_cbe_tmp__1220;
  bool llvm_cbe_tmp__1220__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1221;
  unsigned long long llvm_cbe_tmp__1222;
  unsigned long long llvm_cbe_tmp__1223;
  unsigned char llvm_cbe_tmp__1224;
  unsigned char llvm_cbe_tmp__1225;
  bool llvm_cbe_tmp__1226;
  bool llvm_cbe_tmp__1227;
  bool llvm_cbe_tmp__1227__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1228;
  unsigned long long llvm_cbe_tmp__1229;
  unsigned long long llvm_cbe_tmp__1230;
  unsigned char llvm_cbe_tmp__1231;
  unsigned char llvm_cbe_tmp__1232;
  bool llvm_cbe_tmp__1233;
  bool llvm_cbe_tmp__1234;
  bool llvm_cbe_tmp__1234__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1235;
  unsigned long long llvm_cbe_tmp__1236;
  unsigned long long llvm_cbe_tmp__1237;
  unsigned long long llvm_cbe_tmp__1238;
  unsigned long long llvm_cbe_tmp__1239;
  unsigned long long llvm_cbe_tmp__1240;
  unsigned long long llvm_cbe_tmp__1241;
  unsigned long long llvm_cbe_tmp__1242;
  unsigned long long llvm_cbe_tmp__1243;
  unsigned long long llvm_cbe_tmp__1244;
  unsigned long long llvm_cbe_tmp__1245;

  *(&llvm_cbe_tmp__1117) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1118) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1119) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1120) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1121) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1122) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1123) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1124) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1125) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1126) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1127) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1128) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1129 = *(&llvm_cbe_tmp__1117);
  llvm_cbe_tmp__1130 = *((&llvm_cbe_tmp__1129->field24));
  *(&llvm_cbe_cppVar_1542) = (((unsigned char )(bool )(llvm_cbe_tmp__1130 == 0ull)));
  llvm_cbe_tmp__1131 = *(&llvm_cbe_cppVar_1542);
  if ((((((bool )llvm_cbe_tmp__1131&1u))&1))) {
    goto llvm_cbe_tmp__1246;
  } else {
    goto llvm_cbe_tmp__1247;
  }

llvm_cbe_tmp__1246:
  llvm_cbe_tmp__1132 = *((&llvm_cbe_tmp__1129->field21));
  *(&llvm_cbe_cppVar_1540) = llvm_cbe_tmp__1132;
  goto llvm_cbe_tmp__1248;

llvm_cbe_tmp__1247:
  llvm_cbe_tmp__1133 = *((&llvm_cbe_tmp__1129->field24));
  *(&llvm_cbe_cppVar_1545) = (((unsigned char )(bool )(llvm_cbe_tmp__1133 == 1ull)));
  llvm_cbe_tmp__1134 = *(&llvm_cbe_cppVar_1545);
  if ((((((bool )llvm_cbe_tmp__1134&1u))&1))) {
    goto llvm_cbe_tmp__1249;
  } else {
    goto llvm_cbe_tmp__1250;
  }

llvm_cbe_tmp__1249:
  llvm_cbe_tmp__1135 = *((&llvm_cbe_tmp__1129->field17));
  *(&llvm_cbe_cppVar_1548) = (((unsigned char )(bool )(llvm_cbe_tmp__1135 == 0ull)));
  llvm_cbe_tmp__1136 = *(&llvm_cbe_cppVar_1545);
  if ((((((bool )llvm_cbe_tmp__1136&1u))&1))) {
    goto llvm_cbe_tmp__1251;
  } else {
    llvm_cbe_tmp__1139__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1252;
  }

llvm_cbe_tmp__1251:
  llvm_cbe_tmp__1137 = *(&llvm_cbe_cppVar_1548);
  llvm_cbe_tmp__1138 = ((((bool )llvm_cbe_tmp__1137&1u))&1);
  llvm_cbe_tmp__1139__PHI_TEMPORARY = llvm_cbe_tmp__1138;   /* for PHI node */
  goto llvm_cbe_tmp__1252;

llvm_cbe_tmp__1252:
  llvm_cbe_tmp__1139 = ((llvm_cbe_tmp__1139__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1549) = (((unsigned char )(bool )llvm_cbe_tmp__1139));
  llvm_cbe_tmp__1140 = *(&llvm_cbe_cppVar_1549);
  if ((((((bool )llvm_cbe_tmp__1140&1u))&1))) {
    goto llvm_cbe_tmp__1253;
  } else {
    goto llvm_cbe_tmp__1254;
  }

llvm_cbe_tmp__1253:
  llvm_cbe_tmp__1141 = *((&llvm_cbe_tmp__1129->field19));
  llvm_cbe_tmp__1142 = *((&llvm_cbe_tmp__1129->field11));
  *(&llvm_cbe_cppVar_1551) = (((unsigned char )(bool )(llvm_cbe_tmp__1141 == llvm_cbe_tmp__1142)));
  llvm_cbe_tmp__1143 = *(&llvm_cbe_cppVar_1551);
  if ((((((bool )llvm_cbe_tmp__1143&1u))&1))) {
    goto llvm_cbe_tmp__1255;
  } else {
    goto llvm_cbe_tmp__1256;
  }

llvm_cbe_tmp__1255:
  llvm_cbe_tmp__1144 = *((&llvm_cbe_tmp__1129->field19));
  *(&llvm_cbe_cppVar_1555) = (((unsigned char )(bool )(llvm_cbe_tmp__1144 == 0ull)));
  llvm_cbe_tmp__1145 = *(&llvm_cbe_cppVar_1555);
  if ((((((bool )llvm_cbe_tmp__1145&1u))&1))) {
    goto llvm_cbe_tmp__1257;
  } else {
    goto llvm_cbe_tmp__1258;
  }

llvm_cbe_tmp__1257:
  *(&llvm_cbe_cppVar_1553) = 0ull;
  goto llvm_cbe_tmp__1259;

llvm_cbe_tmp__1258:
  llvm_cbe_tmp__1146 = *((&llvm_cbe_tmp__1129->field23));
  *(&llvm_cbe_cppVar_1553) = llvm_cbe_tmp__1146;
  goto llvm_cbe_tmp__1259;

llvm_cbe_tmp__1259:
  llvm_cbe_tmp__1147 = *((&llvm_cbe_tmp__1129->field19));
  llvm_cbe_tmp__1148 = *((&llvm_cbe_tmp__1129->field48));
  *(&llvm_cbe_cppVar_1558) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1147) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1148);
  llvm_cbe_tmp__1149 = *(&llvm_cbe_cppVar_1558);
  llvm_cbe_tmp__1150 = _ZN8type_memIbLj128EE2rdEl(((&llvm_cbe_tmp__1129->field6)), llvm_cbe_tmp__1149);
  *(&llvm_cbe_cppVar_1559) = llvm_cbe_tmp__1150;
  llvm_cbe_tmp__1151 = *(&llvm_cbe_cppVar_1559);
  *(&llvm_cbe_cppVar_1561) = (((unsigned char )(bool )(llvm_cbe_tmp__1151 == 1ull)));
  llvm_cbe_tmp__1152 = *(&llvm_cbe_cppVar_1561);
  if ((((((bool )llvm_cbe_tmp__1152&1u))&1))) {
    goto llvm_cbe_tmp__1260;
  } else {
    goto llvm_cbe_tmp__1261;
  }

llvm_cbe_tmp__1260:
  llvm_cbe_tmp__1153 = *((&llvm_cbe_tmp__1129->field25));
  *(&llvm_cbe_cppVar_1563) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__1153))));
  llvm_cbe_tmp__1154 = *(&llvm_cbe_cppVar_1563);
  llvm_cbe_tmp__1155 = *((&llvm_cbe_tmp__1129->field41));
  *(&llvm_cbe_cppVar_1563) = (llvm_cbe_tmp__1154 & llvm_cbe_tmp__1155);
  llvm_cbe_tmp__1156 = *(&llvm_cbe_cppVar_1563);
  llvm_cbe_tmp__1157 = *((&llvm_cbe_tmp__1129->field19));
  *(&llvm_cbe_cppVar_1564) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1156) + ((unsigned long long )llvm_cbe_tmp__1157))));
  llvm_cbe_tmp__1158 = *(&llvm_cbe_cppVar_1564);
  llvm_cbe_tmp__1159 = *((&llvm_cbe_tmp__1129->field41));
  *(&llvm_cbe_cppVar_1564) = (llvm_cbe_tmp__1158 & llvm_cbe_tmp__1159);
  llvm_cbe_tmp__1160 = *(&llvm_cbe_cppVar_1564);
  llvm_cbe_tmp__1161 = _ZN8type_memIhLj65536EE2rdEl(((&llvm_cbe_tmp__1129->field4)), llvm_cbe_tmp__1160);
  *(&llvm_cbe_cppVar_1565) = llvm_cbe_tmp__1161;
  llvm_cbe_tmp__1162 = *(&llvm_cbe_cppVar_1565);
  llvm_cbe_tmp__1163 = *((&llvm_cbe_tmp__1129->field48));
  *(&llvm_cbe_cppVar_1566) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1162) >> ((signed long long )1ull)))) & llvm_cbe_tmp__1163);
  llvm_cbe_tmp__1164 = *(&llvm_cbe_cppVar_1566);
  llvm_cbe_tmp__1165 = *((&llvm_cbe_tmp__1129->field53));
  llvm_cbe_tmp__1166 = *(&llvm_cbe_cppVar_1566);
  if (((llvm_cbe_tmp__1164 & llvm_cbe_tmp__1165) != 0ull)) {
    goto llvm_cbe_tmp__1262;
  } else {
    llvm_cbe_tmp__1169__PHI_TEMPORARY = llvm_cbe_tmp__1166;   /* for PHI node */
    goto llvm_cbe_tmp__1263;
  }

llvm_cbe_tmp__1262:
  llvm_cbe_tmp__1167 = *((&llvm_cbe_tmp__1129->field55));
  llvm_cbe_tmp__1168 = llvm_cbe_tmp__1166 | llvm_cbe_tmp__1167;
  llvm_cbe_tmp__1169__PHI_TEMPORARY = llvm_cbe_tmp__1168;   /* for PHI node */
  goto llvm_cbe_tmp__1263;

llvm_cbe_tmp__1263:
  llvm_cbe_tmp__1169 = llvm_cbe_tmp__1169__PHI_TEMPORARY;
  *(&llvm_cbe_cppVar_1567) = llvm_cbe_tmp__1169;
  llvm_cbe_tmp__1170 = *(&llvm_cbe_cppVar_1565);
  llvm_cbe_tmp__1171 = *((&llvm_cbe_tmp__1129->field40));
  *(&llvm_cbe_cppVar_1568) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1170) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1171);
  llvm_cbe_tmp__1172 = *(&llvm_cbe_cppVar_1567);
  llvm_cbe_tmp__1173 = *(&llvm_cbe_cppVar_1568);
  *(&llvm_cbe_cppVar_1569) = ((llvm_cbe_tmp__1172 << 1ull) | llvm_cbe_tmp__1173);
  llvm_cbe_tmp__1174 = *(&llvm_cbe_cppVar_1569);
  llvm_cbe_tmp__1175 = *((&llvm_cbe_tmp__1129->field41));
  *(&llvm_cbe_cppVar_1569) = (llvm_cbe_tmp__1174 & llvm_cbe_tmp__1175);
  llvm_cbe_tmp__1176 = *(&llvm_cbe_cppVar_1569);
  *(&llvm_cbe_cppVar_1557) = llvm_cbe_tmp__1176;
  goto llvm_cbe_tmp__1264;

llvm_cbe_tmp__1261:
  *(&llvm_cbe_cppVar_1557) = 0ull;
  goto llvm_cbe_tmp__1264;

llvm_cbe_tmp__1264:
  llvm_cbe_tmp__1177 = *(&llvm_cbe_cppVar_1553);
  llvm_cbe_tmp__1178 = *(&llvm_cbe_cppVar_1557);
  *(&llvm_cbe_cppVar_1570) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1177) + ((unsigned long long )llvm_cbe_tmp__1178))));
  llvm_cbe_tmp__1179 = *(&llvm_cbe_cppVar_1570);
  llvm_cbe_tmp__1180 = *((&llvm_cbe_tmp__1129->field41));
  *(&llvm_cbe_cppVar_1570) = (llvm_cbe_tmp__1179 & llvm_cbe_tmp__1180);
  llvm_cbe_tmp__1181 = *((&llvm_cbe_tmp__1129->field9));
  *(&llvm_cbe_cppVar_1573) = (((unsigned char )(bool )(llvm_cbe_tmp__1181 == 0ull)));
  llvm_cbe_tmp__1182 = *(&llvm_cbe_cppVar_1573);
  if ((((((bool )llvm_cbe_tmp__1182&1u))&1))) {
    goto llvm_cbe_tmp__1265;
  } else {
    goto llvm_cbe_tmp__1266;
  }

llvm_cbe_tmp__1265:
  *(&llvm_cbe_cppVar_1575) = 18446744073709550616ull;
  llvm_cbe_tmp__1183 = *(&llvm_cbe_cppVar_1575);
  *(&llvm_cbe_cppVar_1571) = llvm_cbe_tmp__1183;
  goto llvm_cbe_tmp__1267;

llvm_cbe_tmp__1266:
  llvm_cbe_tmp__1184 = *((&llvm_cbe_tmp__1129->field21));
  *(&llvm_cbe_cppVar_1571) = llvm_cbe_tmp__1184;
  goto llvm_cbe_tmp__1267;

llvm_cbe_tmp__1267:
  llvm_cbe_tmp__1185 = *(&llvm_cbe_cppVar_1570);
  llvm_cbe_tmp__1186 = *((&llvm_cbe_tmp__1129->field52));
  llvm_cbe_tmp__1187 = *(&llvm_cbe_cppVar_1570);
  if (((llvm_cbe_tmp__1185 & llvm_cbe_tmp__1186) != 0ull)) {
    goto llvm_cbe_tmp__1268;
  } else {
    llvm_cbe_tmp__1190__PHI_TEMPORARY = llvm_cbe_tmp__1187;   /* for PHI node */
    goto llvm_cbe_tmp__1269;
  }

llvm_cbe_tmp__1268:
  llvm_cbe_tmp__1188 = *((&llvm_cbe_tmp__1129->field54));
  llvm_cbe_tmp__1189 = llvm_cbe_tmp__1187 | llvm_cbe_tmp__1188;
  llvm_cbe_tmp__1190__PHI_TEMPORARY = llvm_cbe_tmp__1189;   /* for PHI node */
  goto llvm_cbe_tmp__1269;

llvm_cbe_tmp__1269:
  llvm_cbe_tmp__1190 = llvm_cbe_tmp__1190__PHI_TEMPORARY;
  llvm_cbe_tmp__1191 = *(&llvm_cbe_cppVar_1571);
  llvm_cbe_tmp__1192 = *((&llvm_cbe_tmp__1129->field52));
  llvm_cbe_tmp__1193 = *(&llvm_cbe_cppVar_1571);
  if (((llvm_cbe_tmp__1191 & llvm_cbe_tmp__1192) != 0ull)) {
    goto llvm_cbe_tmp__1270;
  } else {
    llvm_cbe_tmp__1196__PHI_TEMPORARY = llvm_cbe_tmp__1193;   /* for PHI node */
    goto llvm_cbe_tmp__1271;
  }

llvm_cbe_tmp__1270:
  llvm_cbe_tmp__1194 = *((&llvm_cbe_tmp__1129->field54));
  llvm_cbe_tmp__1195 = llvm_cbe_tmp__1193 | llvm_cbe_tmp__1194;
  llvm_cbe_tmp__1196__PHI_TEMPORARY = llvm_cbe_tmp__1195;   /* for PHI node */
  goto llvm_cbe_tmp__1271;

llvm_cbe_tmp__1271:
  llvm_cbe_tmp__1196 = llvm_cbe_tmp__1196__PHI_TEMPORARY;
  *(&llvm_cbe_cppVar_1576) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__1190) > ((signed long long )llvm_cbe_tmp__1196))));
  llvm_cbe_tmp__1197 = *(&llvm_cbe_cppVar_1576);
  if ((((((bool )llvm_cbe_tmp__1197&1u))&1))) {
    goto llvm_cbe_tmp__1272;
  } else {
    goto llvm_cbe_tmp__1273;
  }

llvm_cbe_tmp__1272:
  llvm_cbe_tmp__1198 = *(&llvm_cbe_cppVar_1570);
  *(&llvm_cbe_cppVar_1552) = llvm_cbe_tmp__1198;
  goto llvm_cbe_tmp__1274;

llvm_cbe_tmp__1273:
  llvm_cbe_tmp__1199 = *(&llvm_cbe_cppVar_1571);
  *(&llvm_cbe_cppVar_1552) = llvm_cbe_tmp__1199;
  goto llvm_cbe_tmp__1274;

llvm_cbe_tmp__1274:
  llvm_cbe_tmp__1200 = *(&llvm_cbe_cppVar_1552);
  *(&llvm_cbe_cppVar_1550) = llvm_cbe_tmp__1200;
  goto llvm_cbe_tmp__1275;

llvm_cbe_tmp__1256:
  llvm_cbe_tmp__1201 = *((&llvm_cbe_tmp__1129->field21));
  *(&llvm_cbe_cppVar_1550) = llvm_cbe_tmp__1201;
  goto llvm_cbe_tmp__1275;

llvm_cbe_tmp__1275:
  llvm_cbe_tmp__1202 = *(&llvm_cbe_cppVar_1550);
  *(&llvm_cbe_cppVar_1546) = llvm_cbe_tmp__1202;
  goto llvm_cbe_tmp__1276;

llvm_cbe_tmp__1254:
  llvm_cbe_tmp__1203 = *((&llvm_cbe_tmp__1129->field17));
  *(&llvm_cbe_cppVar_1579) = (((unsigned char )(bool )(llvm_cbe_tmp__1203 == 1ull)));
  llvm_cbe_tmp__1204 = *(&llvm_cbe_cppVar_1545);
  if ((((((bool )llvm_cbe_tmp__1204&1u))&1))) {
    goto llvm_cbe_tmp__1277;
  } else {
    llvm_cbe_tmp__1207__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1278;
  }

llvm_cbe_tmp__1277:
  llvm_cbe_tmp__1205 = *(&llvm_cbe_cppVar_1579);
  llvm_cbe_tmp__1206 = ((((bool )llvm_cbe_tmp__1205&1u))&1);
  llvm_cbe_tmp__1207__PHI_TEMPORARY = llvm_cbe_tmp__1206;   /* for PHI node */
  goto llvm_cbe_tmp__1278;

llvm_cbe_tmp__1278:
  llvm_cbe_tmp__1207 = ((llvm_cbe_tmp__1207__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1580) = (((unsigned char )(bool )llvm_cbe_tmp__1207));
  llvm_cbe_tmp__1208 = *(&llvm_cbe_cppVar_1580);
  if ((((((bool )llvm_cbe_tmp__1208&1u))&1))) {
    goto llvm_cbe_tmp__1279;
  } else {
    goto llvm_cbe_tmp__1280;
  }

llvm_cbe_tmp__1279:
  llvm_cbe_tmp__1209 = *((&llvm_cbe_tmp__1129->field9));
  *(&llvm_cbe_cppVar_1583) = (((unsigned char )(bool )(llvm_cbe_tmp__1209 == 0ull)));
  llvm_cbe_tmp__1210 = *(&llvm_cbe_cppVar_1583);
  llvm_cbe_tmp__1211 = *((&llvm_cbe_tmp__1129->field21));
  if ((((((bool )llvm_cbe_tmp__1210&1u))&1))) {
    goto llvm_cbe_tmp__1281;
  } else {
    goto llvm_cbe_tmp__1282;
  }

llvm_cbe_tmp__1281:
  *(&llvm_cbe_cppVar_1585) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1211) - ((unsigned long long )62ull))));
  llvm_cbe_tmp__1212 = *(&llvm_cbe_cppVar_1585);
  llvm_cbe_tmp__1213 = *((&llvm_cbe_tmp__1129->field41));
  *(&llvm_cbe_cppVar_1585) = (llvm_cbe_tmp__1212 & llvm_cbe_tmp__1213);
  llvm_cbe_tmp__1214 = *(&llvm_cbe_cppVar_1585);
  *(&llvm_cbe_cppVar_1581) = llvm_cbe_tmp__1214;
  goto llvm_cbe_tmp__1283;

llvm_cbe_tmp__1282:
  *(&llvm_cbe_cppVar_1581) = llvm_cbe_tmp__1211;
  goto llvm_cbe_tmp__1283;

llvm_cbe_tmp__1283:
  llvm_cbe_tmp__1215 = *(&llvm_cbe_cppVar_1581);
  *(&llvm_cbe_cppVar_1577) = llvm_cbe_tmp__1215;
  goto llvm_cbe_tmp__1284;

llvm_cbe_tmp__1280:
  llvm_cbe_tmp__1216 = *((&llvm_cbe_tmp__1129->field17));
  *(&llvm_cbe_cppVar_1588) = (((unsigned char )(bool )(llvm_cbe_tmp__1216 == 2ull)));
  llvm_cbe_tmp__1217 = *(&llvm_cbe_cppVar_1545);
  if ((((((bool )llvm_cbe_tmp__1217&1u))&1))) {
    goto llvm_cbe_tmp__1285;
  } else {
    llvm_cbe_tmp__1220__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1286;
  }

llvm_cbe_tmp__1285:
  llvm_cbe_tmp__1218 = *(&llvm_cbe_cppVar_1588);
  llvm_cbe_tmp__1219 = ((((bool )llvm_cbe_tmp__1218&1u))&1);
  llvm_cbe_tmp__1220__PHI_TEMPORARY = llvm_cbe_tmp__1219;   /* for PHI node */
  goto llvm_cbe_tmp__1286;

llvm_cbe_tmp__1286:
  llvm_cbe_tmp__1220 = ((llvm_cbe_tmp__1220__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1589) = (((unsigned char )(bool )llvm_cbe_tmp__1220));
  llvm_cbe_tmp__1221 = *(&llvm_cbe_cppVar_1589);
  if ((((((bool )llvm_cbe_tmp__1221&1u))&1))) {
    goto llvm_cbe_tmp__1287;
  } else {
    goto llvm_cbe_tmp__1288;
  }

llvm_cbe_tmp__1287:
  llvm_cbe_tmp__1222 = *((&llvm_cbe_tmp__1129->field21));
  *(&llvm_cbe_cppVar_1586) = llvm_cbe_tmp__1222;
  goto llvm_cbe_tmp__1289;

llvm_cbe_tmp__1288:
  llvm_cbe_tmp__1223 = *((&llvm_cbe_tmp__1129->field17));
  *(&llvm_cbe_cppVar_1592) = (((unsigned char )(bool )(llvm_cbe_tmp__1223 == 3ull)));
  llvm_cbe_tmp__1224 = *(&llvm_cbe_cppVar_1545);
  if ((((((bool )llvm_cbe_tmp__1224&1u))&1))) {
    goto llvm_cbe_tmp__1290;
  } else {
    llvm_cbe_tmp__1227__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1291;
  }

llvm_cbe_tmp__1290:
  llvm_cbe_tmp__1225 = *(&llvm_cbe_cppVar_1592);
  llvm_cbe_tmp__1226 = ((((bool )llvm_cbe_tmp__1225&1u))&1);
  llvm_cbe_tmp__1227__PHI_TEMPORARY = llvm_cbe_tmp__1226;   /* for PHI node */
  goto llvm_cbe_tmp__1291;

llvm_cbe_tmp__1291:
  llvm_cbe_tmp__1227 = ((llvm_cbe_tmp__1227__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1593) = (((unsigned char )(bool )llvm_cbe_tmp__1227));
  llvm_cbe_tmp__1228 = *(&llvm_cbe_cppVar_1593);
  if ((((((bool )llvm_cbe_tmp__1228&1u))&1))) {
    goto llvm_cbe_tmp__1292;
  } else {
    goto llvm_cbe_tmp__1293;
  }

llvm_cbe_tmp__1292:
  llvm_cbe_tmp__1229 = *((&llvm_cbe_tmp__1129->field21));
  *(&llvm_cbe_cppVar_1590) = llvm_cbe_tmp__1229;
  goto llvm_cbe_tmp__1294;

llvm_cbe_tmp__1293:
  llvm_cbe_tmp__1230 = *((&llvm_cbe_tmp__1129->field17));
  *(&llvm_cbe_cppVar_1596) = (((unsigned char )(bool )(llvm_cbe_tmp__1230 == 4ull)));
  llvm_cbe_tmp__1231 = *(&llvm_cbe_cppVar_1545);
  if ((((((bool )llvm_cbe_tmp__1231&1u))&1))) {
    goto llvm_cbe_tmp__1295;
  } else {
    llvm_cbe_tmp__1234__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1296;
  }

llvm_cbe_tmp__1295:
  llvm_cbe_tmp__1232 = *(&llvm_cbe_cppVar_1596);
  llvm_cbe_tmp__1233 = ((((bool )llvm_cbe_tmp__1232&1u))&1);
  llvm_cbe_tmp__1234__PHI_TEMPORARY = llvm_cbe_tmp__1233;   /* for PHI node */
  goto llvm_cbe_tmp__1296;

llvm_cbe_tmp__1296:
  llvm_cbe_tmp__1234 = ((llvm_cbe_tmp__1234__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1597) = (((unsigned char )(bool )llvm_cbe_tmp__1234));
  llvm_cbe_tmp__1235 = *((&llvm_cbe_tmp__1129->field21));
  *(&llvm_cbe_cppVar_1594) = llvm_cbe_tmp__1235;
  llvm_cbe_tmp__1236 = *(&llvm_cbe_cppVar_1594);
  *(&llvm_cbe_cppVar_1590) = llvm_cbe_tmp__1236;
  goto llvm_cbe_tmp__1294;

llvm_cbe_tmp__1294:
  llvm_cbe_tmp__1237 = *(&llvm_cbe_cppVar_1590);
  *(&llvm_cbe_cppVar_1586) = llvm_cbe_tmp__1237;
  goto llvm_cbe_tmp__1289;

llvm_cbe_tmp__1289:
  llvm_cbe_tmp__1238 = *(&llvm_cbe_cppVar_1586);
  *(&llvm_cbe_cppVar_1577) = llvm_cbe_tmp__1238;
  goto llvm_cbe_tmp__1284;

llvm_cbe_tmp__1284:
  llvm_cbe_tmp__1239 = *(&llvm_cbe_cppVar_1577);
  *(&llvm_cbe_cppVar_1546) = llvm_cbe_tmp__1239;
  goto llvm_cbe_tmp__1276;

llvm_cbe_tmp__1276:
  llvm_cbe_tmp__1240 = *(&llvm_cbe_cppVar_1546);
  *(&llvm_cbe_cppVar_1543) = llvm_cbe_tmp__1240;
  goto llvm_cbe_tmp__1297;

llvm_cbe_tmp__1250:
  llvm_cbe_tmp__1241 = *((&llvm_cbe_tmp__1129->field24));
  *(&llvm_cbe_cppVar_1600) = (((unsigned char )(bool )(llvm_cbe_tmp__1241 == 2ull)));
  llvm_cbe_tmp__1242 = *((&llvm_cbe_tmp__1129->field21));
  *(&llvm_cbe_cppVar_1598) = llvm_cbe_tmp__1242;
  llvm_cbe_tmp__1243 = *(&llvm_cbe_cppVar_1598);
  *(&llvm_cbe_cppVar_1543) = llvm_cbe_tmp__1243;
  goto llvm_cbe_tmp__1297;

llvm_cbe_tmp__1297:
  llvm_cbe_tmp__1244 = *(&llvm_cbe_cppVar_1543);
  *(&llvm_cbe_cppVar_1540) = llvm_cbe_tmp__1244;
  goto llvm_cbe_tmp__1248;

llvm_cbe_tmp__1248:
  llvm_cbe_tmp__1245 = *(&llvm_cbe_cppVar_1540);
  return llvm_cbe_tmp__1245;
}


unsigned long long _ZN8type_memIbLj128EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1298;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1299;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1300;
  unsigned long long llvm_cbe_tmp__1301;
  unsigned char *llvm_cbe_tmp__1302;
  unsigned char llvm_cbe_tmp__1303;

  *(&llvm_cbe_tmp__1298) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1299) = llvm_cbe_addr;
  llvm_cbe_tmp__1300 = *(&llvm_cbe_tmp__1298);
  llvm_cbe_tmp__1301 = *(&llvm_cbe_tmp__1299);
  llvm_cbe_tmp__1302 = *((&llvm_cbe_tmp__1300->field0));
  llvm_cbe_tmp__1303 = *((&llvm_cbe_tmp__1302[((signed long long )llvm_cbe_tmp__1301)]));
  return (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__1303&1u))&1))));
}


struct l_class_OC_SysCArray1D _ZN13model_predict27cppUpdateFun_predict_resultElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_SysCArray1D StructReturn;  /* Struct return temporary */
  struct l_class_OC_SysCArray1D *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_predict *llvm_cbe_tmp__1304;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1305;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1306;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1307;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1308;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1309;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1310;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1311;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1312;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1313;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1314;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1315;    /* Address-exposed local */
  bool llvm_cbe_tmp__1316;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2058;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2059;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2061;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2062;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2063;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_2064;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__1317;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1318;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_2060;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1319;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__1320;
  unsigned long long llvm_cbe_tmp__1321;
  unsigned char llvm_cbe_tmp__1322;
  unsigned long long llvm_cbe_tmp__1323;
  unsigned char llvm_cbe_tmp__1324;
  unsigned long long llvm_cbe_tmp__1325;
  unsigned long long llvm_cbe_tmp__1326;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1327;
  unsigned long long llvm_cbe_tmp__1328;
  unsigned long long llvm_cbe_tmp__1329;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1330;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1331;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1332;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1333;
  bool llvm_cbe_tmp__1334;

  *(&llvm_cbe_tmp__1304) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1305) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1306) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1307) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1308) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1309) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1310) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1311) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1312) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1313) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1314) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1315) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1320 = *(&llvm_cbe_tmp__1304);
  *(&llvm_cbe_tmp__1316) = ((0) & 1);
  _ZN8type_memIhLj128EEC1Ev(llvm_cbe_agg_2e_result);
  _ZN8type_memIhLj128EEC1Ev((&llvm_cbe_cppVar_2064));
  _ZN8type_memIhLj128EEC1Ev((&llvm_cbe_cppVar_2060));
  llvm_cbe_tmp__1321 = *((&llvm_cbe_tmp__1320->field24));
  *(&llvm_cbe_cppVar_2059) = (((unsigned char )(bool )(llvm_cbe_tmp__1321 == 3ull)));
  llvm_cbe_tmp__1322 = *(&llvm_cbe_cppVar_2059);
  if ((((((bool )llvm_cbe_tmp__1322&1u))&1))) {
    goto llvm_cbe_tmp__1335;
  } else {
    goto llvm_cbe_tmp__1336;
  }

llvm_cbe_tmp__1335:
  llvm_cbe_tmp__1323 = *((&llvm_cbe_tmp__1320->field9));
  *(&llvm_cbe_cppVar_2062) = (((unsigned char )(bool )(llvm_cbe_tmp__1323 == 4ull)));
  llvm_cbe_tmp__1324 = *(&llvm_cbe_cppVar_2062);
  if ((((((bool )llvm_cbe_tmp__1324&1u))&1))) {
    goto llvm_cbe_tmp__1337;
  } else {
    goto llvm_cbe_tmp__1338;
  }

llvm_cbe_tmp__1337:
  llvm_cbe_tmp__1325 = *((&llvm_cbe_tmp__1320->field0));
  llvm_cbe_tmp__1326 = *((&llvm_cbe_tmp__1320->field48));
  *(&llvm_cbe_cppVar_2063) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1325) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1326);
  llvm_cbe_tmp__1327 = _ZN8type_memIhLj128EEaSERKS0_((&llvm_cbe_cppVar_2064), ((&llvm_cbe_tmp__1320->field22)));
  llvm_cbe_tmp__1328 = *(&llvm_cbe_cppVar_2063);
  llvm_cbe_tmp__1329 = *((&llvm_cbe_tmp__1320->field27));
  _ZN8type_memIhLj128EE2wrEll((&llvm_cbe_cppVar_2064), llvm_cbe_tmp__1328, llvm_cbe_tmp__1329);
  llvm_cbe_tmp__1330 = _ZN8type_memIhLj128EEaSERKS0_((&llvm_cbe_cppVar_2060), (&llvm_cbe_cppVar_2064));
  goto llvm_cbe_tmp__1339;

llvm_cbe_tmp__1338:
  llvm_cbe_tmp__1331 = _ZN8type_memIhLj128EEaSERKS0_((&llvm_cbe_cppVar_2060), ((&llvm_cbe_tmp__1320->field22)));
  goto llvm_cbe_tmp__1339;

llvm_cbe_tmp__1339:
  llvm_cbe_tmp__1332 = _ZN8type_memIhLj128EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_2060));
  goto llvm_cbe_tmp__1340;

llvm_cbe_tmp__1336:
  llvm_cbe_tmp__1333 = _ZN8type_memIhLj128EEaSERKS0_(llvm_cbe_agg_2e_result, ((&llvm_cbe_tmp__1320->field22)));
  goto llvm_cbe_tmp__1340;

llvm_cbe_tmp__1340:
  *(&llvm_cbe_tmp__1316) = ((1) & 1);
  *(&llvm_cbe_tmp__1319) = 1u;
  _ZN8type_memIhLj128EED1Ev((&llvm_cbe_cppVar_2060));
  _ZN8type_memIhLj128EED1Ev((&llvm_cbe_cppVar_2064));
  llvm_cbe_tmp__1334 = ((*(&llvm_cbe_tmp__1316))&1);
  if (llvm_cbe_tmp__1334) {
    goto llvm_cbe_tmp__1341;
  } else {
    goto llvm_cbe_tmp__1342;
  }

llvm_cbe_tmp__1342:
  _ZN8type_memIhLj128EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__1341;

llvm_cbe_tmp__1341:
  return StructReturn;
}


void _ZN8type_memIhLj128EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1343;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1344;

  *(&llvm_cbe_tmp__1343) = llvm_cbe_this;
  llvm_cbe_tmp__1344 = *(&llvm_cbe_tmp__1343);
  _ZN8type_memIhLj128EEC2Ev(llvm_cbe_tmp__1344);
  return;
}


struct l_class_OC_SysCArray1D *_ZN8type_memIhLj128EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1345;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1346;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1347;
  unsigned char *llvm_cbe_tmp__1348;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1349;
  unsigned char *llvm_cbe_tmp__1350;

  *(&llvm_cbe_tmp__1345) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1346) = llvm_cbe_r;
  llvm_cbe_tmp__1347 = *(&llvm_cbe_tmp__1345);
  llvm_cbe_tmp__1348 = *((&llvm_cbe_tmp__1347->field0));
  llvm_cbe_tmp__1349 = *(&llvm_cbe_tmp__1346);
  llvm_cbe_tmp__1350 = *((&llvm_cbe_tmp__1349->field0));
  __CPROVER_array_copy(llvm_cbe_tmp__1348, llvm_cbe_tmp__1350);
  return llvm_cbe_tmp__1347;
}


void _ZN8type_memIhLj128EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1351;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1352;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1353;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1354;
  unsigned long long llvm_cbe_tmp__1355;
  unsigned long long llvm_cbe_tmp__1356;
  unsigned char *llvm_cbe_tmp__1357;

  *(&llvm_cbe_tmp__1351) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1352) = llvm_cbe_addr;
  *(&llvm_cbe_tmp__1353) = llvm_cbe_data;
  llvm_cbe_tmp__1354 = *(&llvm_cbe_tmp__1351);
  llvm_cbe_tmp__1355 = *(&llvm_cbe_tmp__1353);
  llvm_cbe_tmp__1356 = *(&llvm_cbe_tmp__1352);
  llvm_cbe_tmp__1357 = *((&llvm_cbe_tmp__1354->field0));
  *((&llvm_cbe_tmp__1357[((signed long long )llvm_cbe_tmp__1356)])) = (((unsigned char )llvm_cbe_tmp__1355));
  return;
}


void _ZN8type_memIhLj128EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1358;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1359;

  *(&llvm_cbe_tmp__1358) = llvm_cbe_this;
  llvm_cbe_tmp__1359 = *(&llvm_cbe_tmp__1358);
  _ZN8type_memIhLj128EED2Ev(llvm_cbe_tmp__1359);
  return;
}


unsigned long long _ZN13model_predict24cppUpdateFun_predict_sumElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__1360;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1361;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1362;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1363;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1364;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1365;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1366;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1367;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1368;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1369;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1370;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1371;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1634;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1603;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1604;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1625;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1626;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1663;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1664;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1614;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1615;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1616;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1606;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1607;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1608;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1605;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1610;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1611;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1612;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1613;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1617;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1618;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1619;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1620;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1621;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1622;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1609;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1623;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1628;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1629;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1630;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1647;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1648;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1649;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1651;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1652;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1653;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1655;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1656;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1657;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1659;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1660;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1661;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1632;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1633;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1631;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1636;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1637;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1638;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1639;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1640;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1641;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1642;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1643;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1644;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1635;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1645;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1658;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1654;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1650;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1646;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1627;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1662;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1624;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1602;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__1372;
  unsigned long long llvm_cbe_tmp__1373;
  unsigned char llvm_cbe_tmp__1374;
  unsigned long long llvm_cbe_tmp__1375;
  unsigned char llvm_cbe_tmp__1376;
  unsigned long long llvm_cbe_tmp__1377;
  unsigned long long llvm_cbe_tmp__1378;
  unsigned long long llvm_cbe_tmp__1379;
  unsigned long long llvm_cbe_tmp__1380;
  unsigned long long llvm_cbe_tmp__1381;
  unsigned long long llvm_cbe_tmp__1382;
  unsigned char llvm_cbe_tmp__1383;
  unsigned long long llvm_cbe_tmp__1384;
  unsigned long long llvm_cbe_tmp__1385;
  unsigned long long llvm_cbe_tmp__1386;
  unsigned long long llvm_cbe_tmp__1387;
  unsigned long long llvm_cbe_tmp__1388;
  unsigned long long llvm_cbe_tmp__1389;
  unsigned long long llvm_cbe_tmp__1390;
  unsigned long long llvm_cbe_tmp__1391;
  unsigned long long llvm_cbe_tmp__1392;
  unsigned long long llvm_cbe_tmp__1393;
  unsigned long long llvm_cbe_tmp__1394;
  unsigned long long llvm_cbe_tmp__1395;
  unsigned long long llvm_cbe_tmp__1396;
  unsigned long long llvm_cbe_tmp__1397;
  unsigned long long llvm_cbe_tmp__1398;
  unsigned long long llvm_cbe_tmp__1399;
  unsigned long long llvm_cbe_tmp__1400;
  unsigned long long llvm_cbe_tmp__1400__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1401;
  unsigned long long llvm_cbe_tmp__1402;
  unsigned long long llvm_cbe_tmp__1403;
  unsigned long long llvm_cbe_tmp__1404;
  unsigned long long llvm_cbe_tmp__1405;
  unsigned long long llvm_cbe_tmp__1406;
  unsigned long long llvm_cbe_tmp__1407;
  unsigned long long llvm_cbe_tmp__1408;
  unsigned long long llvm_cbe_tmp__1409;
  unsigned long long llvm_cbe_tmp__1410;
  unsigned long long llvm_cbe_tmp__1411;
  unsigned long long llvm_cbe_tmp__1412;
  unsigned long long llvm_cbe_tmp__1413;
  unsigned char llvm_cbe_tmp__1414;
  unsigned long long llvm_cbe_tmp__1415;
  unsigned char llvm_cbe_tmp__1416;
  unsigned char llvm_cbe_tmp__1417;
  bool llvm_cbe_tmp__1418;
  bool llvm_cbe_tmp__1419;
  bool llvm_cbe_tmp__1419__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1420;
  unsigned long long llvm_cbe_tmp__1421;
  unsigned char llvm_cbe_tmp__1422;
  unsigned long long llvm_cbe_tmp__1423;
  unsigned long long llvm_cbe_tmp__1424;
  unsigned long long llvm_cbe_tmp__1425;
  unsigned long long llvm_cbe_tmp__1426;
  unsigned long long llvm_cbe_tmp__1427;
  unsigned long long llvm_cbe_tmp__1428;
  unsigned char llvm_cbe_tmp__1429;
  unsigned long long llvm_cbe_tmp__1430;
  unsigned long long llvm_cbe_tmp__1431;
  unsigned long long llvm_cbe_tmp__1432;
  unsigned long long llvm_cbe_tmp__1433;
  unsigned long long llvm_cbe_tmp__1434;
  unsigned long long llvm_cbe_tmp__1435;
  unsigned long long llvm_cbe_tmp__1436;
  unsigned long long llvm_cbe_tmp__1437;
  unsigned long long llvm_cbe_tmp__1438;
  unsigned long long llvm_cbe_tmp__1439;
  unsigned long long llvm_cbe_tmp__1439__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1440;
  unsigned long long llvm_cbe_tmp__1441;
  unsigned long long llvm_cbe_tmp__1442;
  unsigned long long llvm_cbe_tmp__1443;
  unsigned long long llvm_cbe_tmp__1444;
  unsigned long long llvm_cbe_tmp__1445;
  unsigned long long llvm_cbe_tmp__1446;
  unsigned long long llvm_cbe_tmp__1447;
  unsigned long long llvm_cbe_tmp__1448;
  unsigned long long llvm_cbe_tmp__1449;
  unsigned long long llvm_cbe_tmp__1450;
  unsigned long long llvm_cbe_tmp__1451;
  unsigned long long llvm_cbe_tmp__1452;
  unsigned char llvm_cbe_tmp__1453;
  unsigned char llvm_cbe_tmp__1454;
  bool llvm_cbe_tmp__1455;
  bool llvm_cbe_tmp__1456;
  bool llvm_cbe_tmp__1456__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1457;
  unsigned long long llvm_cbe_tmp__1458;
  unsigned long long llvm_cbe_tmp__1459;
  unsigned char llvm_cbe_tmp__1460;
  unsigned char llvm_cbe_tmp__1461;
  bool llvm_cbe_tmp__1462;
  bool llvm_cbe_tmp__1463;
  bool llvm_cbe_tmp__1463__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1464;
  unsigned long long llvm_cbe_tmp__1465;
  unsigned long long llvm_cbe_tmp__1466;
  unsigned char llvm_cbe_tmp__1467;
  unsigned char llvm_cbe_tmp__1468;
  bool llvm_cbe_tmp__1469;
  bool llvm_cbe_tmp__1470;
  bool llvm_cbe_tmp__1470__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1471;
  unsigned long long llvm_cbe_tmp__1472;
  unsigned long long llvm_cbe_tmp__1473;
  unsigned char llvm_cbe_tmp__1474;
  unsigned char llvm_cbe_tmp__1475;
  bool llvm_cbe_tmp__1476;
  bool llvm_cbe_tmp__1477;
  bool llvm_cbe_tmp__1477__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1478;
  unsigned long long llvm_cbe_tmp__1479;
  unsigned long long llvm_cbe_tmp__1480;
  unsigned long long llvm_cbe_tmp__1481;
  unsigned long long llvm_cbe_tmp__1482;
  unsigned long long llvm_cbe_tmp__1483;
  unsigned long long llvm_cbe_tmp__1484;
  unsigned long long llvm_cbe_tmp__1485;
  unsigned long long llvm_cbe_tmp__1486;
  unsigned long long llvm_cbe_tmp__1487;
  unsigned long long llvm_cbe_tmp__1488;

  *(&llvm_cbe_tmp__1360) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1361) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1362) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1363) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1364) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1365) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1366) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1367) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1368) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1369) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1370) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1371) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1372 = *(&llvm_cbe_tmp__1360);
  llvm_cbe_tmp__1373 = *((&llvm_cbe_tmp__1372->field24));
  *(&llvm_cbe_cppVar_1604) = (((unsigned char )(bool )(llvm_cbe_tmp__1373 == 0ull)));
  llvm_cbe_tmp__1374 = *(&llvm_cbe_cppVar_1604);
  if ((((((bool )llvm_cbe_tmp__1374&1u))&1))) {
    goto llvm_cbe_tmp__1489;
  } else {
    goto llvm_cbe_tmp__1490;
  }

llvm_cbe_tmp__1489:
  llvm_cbe_tmp__1375 = *((&llvm_cbe_tmp__1372->field25));
  *(&llvm_cbe_cppVar_1607) = (((unsigned char )(bool )(llvm_cbe_tmp__1375 == 0ull)));
  llvm_cbe_tmp__1376 = *(&llvm_cbe_cppVar_1607);
  if ((((((bool )llvm_cbe_tmp__1376&1u))&1))) {
    goto llvm_cbe_tmp__1491;
  } else {
    goto llvm_cbe_tmp__1492;
  }

llvm_cbe_tmp__1491:
  *(&llvm_cbe_cppVar_1605) = 0ull;
  goto llvm_cbe_tmp__1493;

llvm_cbe_tmp__1492:
  llvm_cbe_tmp__1377 = *((&llvm_cbe_tmp__1372->field23));
  *(&llvm_cbe_cppVar_1605) = llvm_cbe_tmp__1377;
  goto llvm_cbe_tmp__1493;

llvm_cbe_tmp__1493:
  llvm_cbe_tmp__1378 = *((&llvm_cbe_tmp__1372->field25));
  llvm_cbe_tmp__1379 = *((&llvm_cbe_tmp__1372->field51));
  *(&llvm_cbe_cppVar_1610) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1378) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1379);
  llvm_cbe_tmp__1380 = *(&llvm_cbe_cppVar_1610);
  llvm_cbe_tmp__1381 = _ZN8type_memIhLj512EE2rdEl(((&llvm_cbe_tmp__1372->field1)), llvm_cbe_tmp__1380);
  *(&llvm_cbe_cppVar_1611) = llvm_cbe_tmp__1381;
  llvm_cbe_tmp__1382 = *(&llvm_cbe_cppVar_1611);
  *(&llvm_cbe_cppVar_1613) = (((unsigned char )(bool )(llvm_cbe_tmp__1382 == 1ull)));
  llvm_cbe_tmp__1383 = *(&llvm_cbe_cppVar_1613);
  if ((((((bool )llvm_cbe_tmp__1383&1u))&1))) {
    goto llvm_cbe_tmp__1494;
  } else {
    goto llvm_cbe_tmp__1495;
  }

llvm_cbe_tmp__1494:
  llvm_cbe_tmp__1384 = *((&llvm_cbe_tmp__1372->field25));
  *(&llvm_cbe_cppVar_1615) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__1384))));
  llvm_cbe_tmp__1385 = *(&llvm_cbe_cppVar_1615);
  llvm_cbe_tmp__1386 = *((&llvm_cbe_tmp__1372->field41));
  *(&llvm_cbe_cppVar_1615) = (llvm_cbe_tmp__1385 & llvm_cbe_tmp__1386);
  llvm_cbe_tmp__1387 = *(&llvm_cbe_cppVar_1615);
  llvm_cbe_tmp__1388 = *((&llvm_cbe_tmp__1372->field19));
  *(&llvm_cbe_cppVar_1616) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1387) + ((unsigned long long )llvm_cbe_tmp__1388))));
  llvm_cbe_tmp__1389 = *(&llvm_cbe_cppVar_1616);
  llvm_cbe_tmp__1390 = *((&llvm_cbe_tmp__1372->field41));
  *(&llvm_cbe_cppVar_1616) = (llvm_cbe_tmp__1389 & llvm_cbe_tmp__1390);
  llvm_cbe_tmp__1391 = *(&llvm_cbe_cppVar_1616);
  llvm_cbe_tmp__1392 = _ZN8type_memIhLj65536EE2rdEl(((&llvm_cbe_tmp__1372->field4)), llvm_cbe_tmp__1391);
  *(&llvm_cbe_cppVar_1617) = llvm_cbe_tmp__1392;
  llvm_cbe_tmp__1393 = *(&llvm_cbe_cppVar_1617);
  llvm_cbe_tmp__1394 = *((&llvm_cbe_tmp__1372->field48));
  *(&llvm_cbe_cppVar_1618) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1393) >> ((signed long long )1ull)))) & llvm_cbe_tmp__1394);
  llvm_cbe_tmp__1395 = *(&llvm_cbe_cppVar_1618);
  llvm_cbe_tmp__1396 = *((&llvm_cbe_tmp__1372->field53));
  llvm_cbe_tmp__1397 = *(&llvm_cbe_cppVar_1618);
  if (((llvm_cbe_tmp__1395 & llvm_cbe_tmp__1396) != 0ull)) {
    goto llvm_cbe_tmp__1496;
  } else {
    llvm_cbe_tmp__1400__PHI_TEMPORARY = llvm_cbe_tmp__1397;   /* for PHI node */
    goto llvm_cbe_tmp__1497;
  }

llvm_cbe_tmp__1496:
  llvm_cbe_tmp__1398 = *((&llvm_cbe_tmp__1372->field55));
  llvm_cbe_tmp__1399 = llvm_cbe_tmp__1397 | llvm_cbe_tmp__1398;
  llvm_cbe_tmp__1400__PHI_TEMPORARY = llvm_cbe_tmp__1399;   /* for PHI node */
  goto llvm_cbe_tmp__1497;

llvm_cbe_tmp__1497:
  llvm_cbe_tmp__1400 = llvm_cbe_tmp__1400__PHI_TEMPORARY;
  *(&llvm_cbe_cppVar_1619) = llvm_cbe_tmp__1400;
  llvm_cbe_tmp__1401 = *(&llvm_cbe_cppVar_1617);
  llvm_cbe_tmp__1402 = *((&llvm_cbe_tmp__1372->field40));
  *(&llvm_cbe_cppVar_1620) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1401) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1402);
  llvm_cbe_tmp__1403 = *(&llvm_cbe_cppVar_1619);
  llvm_cbe_tmp__1404 = *(&llvm_cbe_cppVar_1620);
  *(&llvm_cbe_cppVar_1621) = ((llvm_cbe_tmp__1403 << 1ull) | llvm_cbe_tmp__1404);
  llvm_cbe_tmp__1405 = *(&llvm_cbe_cppVar_1621);
  llvm_cbe_tmp__1406 = *((&llvm_cbe_tmp__1372->field41));
  *(&llvm_cbe_cppVar_1621) = (llvm_cbe_tmp__1405 & llvm_cbe_tmp__1406);
  llvm_cbe_tmp__1407 = *(&llvm_cbe_cppVar_1621);
  *(&llvm_cbe_cppVar_1609) = llvm_cbe_tmp__1407;
  goto llvm_cbe_tmp__1498;

llvm_cbe_tmp__1495:
  *(&llvm_cbe_cppVar_1609) = 0ull;
  goto llvm_cbe_tmp__1498;

llvm_cbe_tmp__1498:
  llvm_cbe_tmp__1408 = *(&llvm_cbe_cppVar_1605);
  llvm_cbe_tmp__1409 = *(&llvm_cbe_cppVar_1609);
  *(&llvm_cbe_cppVar_1623) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1408) + ((unsigned long long )llvm_cbe_tmp__1409))));
  llvm_cbe_tmp__1410 = *(&llvm_cbe_cppVar_1623);
  llvm_cbe_tmp__1411 = *((&llvm_cbe_tmp__1372->field41));
  *(&llvm_cbe_cppVar_1623) = (llvm_cbe_tmp__1410 & llvm_cbe_tmp__1411);
  llvm_cbe_tmp__1412 = *(&llvm_cbe_cppVar_1623);
  *(&llvm_cbe_cppVar_1602) = llvm_cbe_tmp__1412;
  goto llvm_cbe_tmp__1499;

llvm_cbe_tmp__1490:
  llvm_cbe_tmp__1413 = *((&llvm_cbe_tmp__1372->field24));
  *(&llvm_cbe_cppVar_1626) = (((unsigned char )(bool )(llvm_cbe_tmp__1413 == 1ull)));
  llvm_cbe_tmp__1414 = *(&llvm_cbe_cppVar_1626);
  if ((((((bool )llvm_cbe_tmp__1414&1u))&1))) {
    goto llvm_cbe_tmp__1500;
  } else {
    goto llvm_cbe_tmp__1501;
  }

llvm_cbe_tmp__1500:
  llvm_cbe_tmp__1415 = *((&llvm_cbe_tmp__1372->field17));
  *(&llvm_cbe_cppVar_1629) = (((unsigned char )(bool )(llvm_cbe_tmp__1415 == 0ull)));
  llvm_cbe_tmp__1416 = *(&llvm_cbe_cppVar_1626);
  if ((((((bool )llvm_cbe_tmp__1416&1u))&1))) {
    goto llvm_cbe_tmp__1502;
  } else {
    llvm_cbe_tmp__1419__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1503;
  }

llvm_cbe_tmp__1502:
  llvm_cbe_tmp__1417 = *(&llvm_cbe_cppVar_1629);
  llvm_cbe_tmp__1418 = ((((bool )llvm_cbe_tmp__1417&1u))&1);
  llvm_cbe_tmp__1419__PHI_TEMPORARY = llvm_cbe_tmp__1418;   /* for PHI node */
  goto llvm_cbe_tmp__1503;

llvm_cbe_tmp__1503:
  llvm_cbe_tmp__1419 = ((llvm_cbe_tmp__1419__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1630) = (((unsigned char )(bool )llvm_cbe_tmp__1419));
  llvm_cbe_tmp__1420 = *(&llvm_cbe_cppVar_1630);
  if ((((((bool )llvm_cbe_tmp__1420&1u))&1))) {
    goto llvm_cbe_tmp__1504;
  } else {
    goto llvm_cbe_tmp__1505;
  }

llvm_cbe_tmp__1504:
  llvm_cbe_tmp__1421 = *((&llvm_cbe_tmp__1372->field19));
  *(&llvm_cbe_cppVar_1633) = (((unsigned char )(bool )(llvm_cbe_tmp__1421 == 0ull)));
  llvm_cbe_tmp__1422 = *(&llvm_cbe_cppVar_1633);
  if ((((((bool )llvm_cbe_tmp__1422&1u))&1))) {
    goto llvm_cbe_tmp__1506;
  } else {
    goto llvm_cbe_tmp__1507;
  }

llvm_cbe_tmp__1506:
  *(&llvm_cbe_cppVar_1631) = 0ull;
  goto llvm_cbe_tmp__1508;

llvm_cbe_tmp__1507:
  llvm_cbe_tmp__1423 = *((&llvm_cbe_tmp__1372->field23));
  *(&llvm_cbe_cppVar_1631) = llvm_cbe_tmp__1423;
  goto llvm_cbe_tmp__1508;

llvm_cbe_tmp__1508:
  llvm_cbe_tmp__1424 = *((&llvm_cbe_tmp__1372->field19));
  llvm_cbe_tmp__1425 = *((&llvm_cbe_tmp__1372->field48));
  *(&llvm_cbe_cppVar_1636) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1424) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1425);
  llvm_cbe_tmp__1426 = *(&llvm_cbe_cppVar_1636);
  llvm_cbe_tmp__1427 = _ZN8type_memIbLj128EE2rdEl(((&llvm_cbe_tmp__1372->field6)), llvm_cbe_tmp__1426);
  *(&llvm_cbe_cppVar_1637) = llvm_cbe_tmp__1427;
  llvm_cbe_tmp__1428 = *(&llvm_cbe_cppVar_1637);
  *(&llvm_cbe_cppVar_1639) = (((unsigned char )(bool )(llvm_cbe_tmp__1428 == 1ull)));
  llvm_cbe_tmp__1429 = *(&llvm_cbe_cppVar_1639);
  if ((((((bool )llvm_cbe_tmp__1429&1u))&1))) {
    goto llvm_cbe_tmp__1509;
  } else {
    goto llvm_cbe_tmp__1510;
  }

llvm_cbe_tmp__1509:
  llvm_cbe_tmp__1430 = *(&llvm_cbe_cppVar_1616);
  llvm_cbe_tmp__1431 = _ZN8type_memIhLj65536EE2rdEl(((&llvm_cbe_tmp__1372->field4)), llvm_cbe_tmp__1430);
  *(&llvm_cbe_cppVar_1640) = llvm_cbe_tmp__1431;
  llvm_cbe_tmp__1432 = *(&llvm_cbe_cppVar_1640);
  llvm_cbe_tmp__1433 = *((&llvm_cbe_tmp__1372->field48));
  *(&llvm_cbe_cppVar_1641) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1432) >> ((signed long long )1ull)))) & llvm_cbe_tmp__1433);
  llvm_cbe_tmp__1434 = *(&llvm_cbe_cppVar_1641);
  llvm_cbe_tmp__1435 = *((&llvm_cbe_tmp__1372->field53));
  llvm_cbe_tmp__1436 = *(&llvm_cbe_cppVar_1641);
  if (((llvm_cbe_tmp__1434 & llvm_cbe_tmp__1435) != 0ull)) {
    goto llvm_cbe_tmp__1511;
  } else {
    llvm_cbe_tmp__1439__PHI_TEMPORARY = llvm_cbe_tmp__1436;   /* for PHI node */
    goto llvm_cbe_tmp__1512;
  }

llvm_cbe_tmp__1511:
  llvm_cbe_tmp__1437 = *((&llvm_cbe_tmp__1372->field55));
  llvm_cbe_tmp__1438 = llvm_cbe_tmp__1436 | llvm_cbe_tmp__1437;
  llvm_cbe_tmp__1439__PHI_TEMPORARY = llvm_cbe_tmp__1438;   /* for PHI node */
  goto llvm_cbe_tmp__1512;

llvm_cbe_tmp__1512:
  llvm_cbe_tmp__1439 = llvm_cbe_tmp__1439__PHI_TEMPORARY;
  *(&llvm_cbe_cppVar_1642) = llvm_cbe_tmp__1439;
  llvm_cbe_tmp__1440 = *(&llvm_cbe_cppVar_1640);
  llvm_cbe_tmp__1441 = *((&llvm_cbe_tmp__1372->field40));
  *(&llvm_cbe_cppVar_1643) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1440) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1441);
  llvm_cbe_tmp__1442 = *(&llvm_cbe_cppVar_1642);
  llvm_cbe_tmp__1443 = *(&llvm_cbe_cppVar_1643);
  *(&llvm_cbe_cppVar_1644) = ((llvm_cbe_tmp__1442 << 1ull) | llvm_cbe_tmp__1443);
  llvm_cbe_tmp__1444 = *(&llvm_cbe_cppVar_1644);
  llvm_cbe_tmp__1445 = *((&llvm_cbe_tmp__1372->field41));
  *(&llvm_cbe_cppVar_1644) = (llvm_cbe_tmp__1444 & llvm_cbe_tmp__1445);
  llvm_cbe_tmp__1446 = *(&llvm_cbe_cppVar_1644);
  *(&llvm_cbe_cppVar_1635) = llvm_cbe_tmp__1446;
  goto llvm_cbe_tmp__1513;

llvm_cbe_tmp__1510:
  *(&llvm_cbe_cppVar_1635) = 0ull;
  goto llvm_cbe_tmp__1513;

llvm_cbe_tmp__1513:
  llvm_cbe_tmp__1447 = *(&llvm_cbe_cppVar_1631);
  llvm_cbe_tmp__1448 = *(&llvm_cbe_cppVar_1635);
  *(&llvm_cbe_cppVar_1645) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1447) + ((unsigned long long )llvm_cbe_tmp__1448))));
  llvm_cbe_tmp__1449 = *(&llvm_cbe_cppVar_1645);
  llvm_cbe_tmp__1450 = *((&llvm_cbe_tmp__1372->field41));
  *(&llvm_cbe_cppVar_1645) = (llvm_cbe_tmp__1449 & llvm_cbe_tmp__1450);
  llvm_cbe_tmp__1451 = *(&llvm_cbe_cppVar_1645);
  *(&llvm_cbe_cppVar_1627) = llvm_cbe_tmp__1451;
  goto llvm_cbe_tmp__1514;

llvm_cbe_tmp__1505:
  llvm_cbe_tmp__1452 = *((&llvm_cbe_tmp__1372->field17));
  *(&llvm_cbe_cppVar_1648) = (((unsigned char )(bool )(llvm_cbe_tmp__1452 == 1ull)));
  llvm_cbe_tmp__1453 = *(&llvm_cbe_cppVar_1626);
  if ((((((bool )llvm_cbe_tmp__1453&1u))&1))) {
    goto llvm_cbe_tmp__1515;
  } else {
    llvm_cbe_tmp__1456__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1516;
  }

llvm_cbe_tmp__1515:
  llvm_cbe_tmp__1454 = *(&llvm_cbe_cppVar_1648);
  llvm_cbe_tmp__1455 = ((((bool )llvm_cbe_tmp__1454&1u))&1);
  llvm_cbe_tmp__1456__PHI_TEMPORARY = llvm_cbe_tmp__1455;   /* for PHI node */
  goto llvm_cbe_tmp__1516;

llvm_cbe_tmp__1516:
  llvm_cbe_tmp__1456 = ((llvm_cbe_tmp__1456__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1649) = (((unsigned char )(bool )llvm_cbe_tmp__1456));
  llvm_cbe_tmp__1457 = *(&llvm_cbe_cppVar_1649);
  if ((((((bool )llvm_cbe_tmp__1457&1u))&1))) {
    goto llvm_cbe_tmp__1517;
  } else {
    goto llvm_cbe_tmp__1518;
  }

llvm_cbe_tmp__1517:
  llvm_cbe_tmp__1458 = *((&llvm_cbe_tmp__1372->field23));
  *(&llvm_cbe_cppVar_1646) = llvm_cbe_tmp__1458;
  goto llvm_cbe_tmp__1519;

llvm_cbe_tmp__1518:
  llvm_cbe_tmp__1459 = *((&llvm_cbe_tmp__1372->field17));
  *(&llvm_cbe_cppVar_1652) = (((unsigned char )(bool )(llvm_cbe_tmp__1459 == 2ull)));
  llvm_cbe_tmp__1460 = *(&llvm_cbe_cppVar_1626);
  if ((((((bool )llvm_cbe_tmp__1460&1u))&1))) {
    goto llvm_cbe_tmp__1520;
  } else {
    llvm_cbe_tmp__1463__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1521;
  }

llvm_cbe_tmp__1520:
  llvm_cbe_tmp__1461 = *(&llvm_cbe_cppVar_1652);
  llvm_cbe_tmp__1462 = ((((bool )llvm_cbe_tmp__1461&1u))&1);
  llvm_cbe_tmp__1463__PHI_TEMPORARY = llvm_cbe_tmp__1462;   /* for PHI node */
  goto llvm_cbe_tmp__1521;

llvm_cbe_tmp__1521:
  llvm_cbe_tmp__1463 = ((llvm_cbe_tmp__1463__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1653) = (((unsigned char )(bool )llvm_cbe_tmp__1463));
  llvm_cbe_tmp__1464 = *(&llvm_cbe_cppVar_1653);
  if ((((((bool )llvm_cbe_tmp__1464&1u))&1))) {
    goto llvm_cbe_tmp__1522;
  } else {
    goto llvm_cbe_tmp__1523;
  }

llvm_cbe_tmp__1522:
  llvm_cbe_tmp__1465 = *((&llvm_cbe_tmp__1372->field23));
  *(&llvm_cbe_cppVar_1650) = llvm_cbe_tmp__1465;
  goto llvm_cbe_tmp__1524;

llvm_cbe_tmp__1523:
  llvm_cbe_tmp__1466 = *((&llvm_cbe_tmp__1372->field17));
  *(&llvm_cbe_cppVar_1656) = (((unsigned char )(bool )(llvm_cbe_tmp__1466 == 3ull)));
  llvm_cbe_tmp__1467 = *(&llvm_cbe_cppVar_1626);
  if ((((((bool )llvm_cbe_tmp__1467&1u))&1))) {
    goto llvm_cbe_tmp__1525;
  } else {
    llvm_cbe_tmp__1470__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1526;
  }

llvm_cbe_tmp__1525:
  llvm_cbe_tmp__1468 = *(&llvm_cbe_cppVar_1656);
  llvm_cbe_tmp__1469 = ((((bool )llvm_cbe_tmp__1468&1u))&1);
  llvm_cbe_tmp__1470__PHI_TEMPORARY = llvm_cbe_tmp__1469;   /* for PHI node */
  goto llvm_cbe_tmp__1526;

llvm_cbe_tmp__1526:
  llvm_cbe_tmp__1470 = ((llvm_cbe_tmp__1470__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1657) = (((unsigned char )(bool )llvm_cbe_tmp__1470));
  llvm_cbe_tmp__1471 = *(&llvm_cbe_cppVar_1657);
  if ((((((bool )llvm_cbe_tmp__1471&1u))&1))) {
    goto llvm_cbe_tmp__1527;
  } else {
    goto llvm_cbe_tmp__1528;
  }

llvm_cbe_tmp__1527:
  llvm_cbe_tmp__1472 = *((&llvm_cbe_tmp__1372->field23));
  *(&llvm_cbe_cppVar_1654) = llvm_cbe_tmp__1472;
  goto llvm_cbe_tmp__1529;

llvm_cbe_tmp__1528:
  llvm_cbe_tmp__1473 = *((&llvm_cbe_tmp__1372->field17));
  *(&llvm_cbe_cppVar_1660) = (((unsigned char )(bool )(llvm_cbe_tmp__1473 == 4ull)));
  llvm_cbe_tmp__1474 = *(&llvm_cbe_cppVar_1626);
  if ((((((bool )llvm_cbe_tmp__1474&1u))&1))) {
    goto llvm_cbe_tmp__1530;
  } else {
    llvm_cbe_tmp__1477__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1531;
  }

llvm_cbe_tmp__1530:
  llvm_cbe_tmp__1475 = *(&llvm_cbe_cppVar_1660);
  llvm_cbe_tmp__1476 = ((((bool )llvm_cbe_tmp__1475&1u))&1);
  llvm_cbe_tmp__1477__PHI_TEMPORARY = llvm_cbe_tmp__1476;   /* for PHI node */
  goto llvm_cbe_tmp__1531;

llvm_cbe_tmp__1531:
  llvm_cbe_tmp__1477 = ((llvm_cbe_tmp__1477__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1661) = (((unsigned char )(bool )llvm_cbe_tmp__1477));
  llvm_cbe_tmp__1478 = *((&llvm_cbe_tmp__1372->field23));
  *(&llvm_cbe_cppVar_1658) = llvm_cbe_tmp__1478;
  llvm_cbe_tmp__1479 = *(&llvm_cbe_cppVar_1658);
  *(&llvm_cbe_cppVar_1654) = llvm_cbe_tmp__1479;
  goto llvm_cbe_tmp__1529;

llvm_cbe_tmp__1529:
  llvm_cbe_tmp__1480 = *(&llvm_cbe_cppVar_1654);
  *(&llvm_cbe_cppVar_1650) = llvm_cbe_tmp__1480;
  goto llvm_cbe_tmp__1524;

llvm_cbe_tmp__1524:
  llvm_cbe_tmp__1481 = *(&llvm_cbe_cppVar_1650);
  *(&llvm_cbe_cppVar_1646) = llvm_cbe_tmp__1481;
  goto llvm_cbe_tmp__1519;

llvm_cbe_tmp__1519:
  llvm_cbe_tmp__1482 = *(&llvm_cbe_cppVar_1646);
  *(&llvm_cbe_cppVar_1627) = llvm_cbe_tmp__1482;
  goto llvm_cbe_tmp__1514;

llvm_cbe_tmp__1514:
  llvm_cbe_tmp__1483 = *(&llvm_cbe_cppVar_1627);
  *(&llvm_cbe_cppVar_1624) = llvm_cbe_tmp__1483;
  goto llvm_cbe_tmp__1532;

llvm_cbe_tmp__1501:
  llvm_cbe_tmp__1484 = *((&llvm_cbe_tmp__1372->field24));
  *(&llvm_cbe_cppVar_1664) = (((unsigned char )(bool )(llvm_cbe_tmp__1484 == 2ull)));
  llvm_cbe_tmp__1485 = *((&llvm_cbe_tmp__1372->field23));
  *(&llvm_cbe_cppVar_1662) = llvm_cbe_tmp__1485;
  llvm_cbe_tmp__1486 = *(&llvm_cbe_cppVar_1662);
  *(&llvm_cbe_cppVar_1624) = llvm_cbe_tmp__1486;
  goto llvm_cbe_tmp__1532;

llvm_cbe_tmp__1532:
  llvm_cbe_tmp__1487 = *(&llvm_cbe_cppVar_1624);
  *(&llvm_cbe_cppVar_1602) = llvm_cbe_tmp__1487;
  goto llvm_cbe_tmp__1499;

llvm_cbe_tmp__1499:
  llvm_cbe_tmp__1488 = *(&llvm_cbe_cppVar_1602);
  return llvm_cbe_tmp__1488;
}


unsigned long long _ZN13model_predict24cppUpdateFun_predict_upcElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__1533;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1534;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1535;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1536;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1537;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1538;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1539;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1540;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1541;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1542;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1543;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1544;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1667;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1668;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1676;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1678;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1679;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1675;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1698;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1699;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1696;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1714;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1715;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1712;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1670;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1671;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1672;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1673;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1674;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1669;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1684;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1685;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1687;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1688;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1689;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1690;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1691;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1692;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1693;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1694;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1681;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1682;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1683;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1686;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1695;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1680;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1701;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1702;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1703;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1704;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1705;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1706;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1707;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1708;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1709;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1710;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1711;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1700;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1717;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1718;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1719;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1720;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1721;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1716;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1713;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1697;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1677;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1666;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__1545;
  unsigned long long llvm_cbe_tmp__1546;
  unsigned char llvm_cbe_tmp__1547;
  unsigned long long llvm_cbe_tmp__1548;
  unsigned long long llvm_cbe_tmp__1549;
  unsigned long long llvm_cbe_tmp__1550;
  unsigned long long llvm_cbe_tmp__1551;
  unsigned long long llvm_cbe_tmp__1552;
  unsigned long long llvm_cbe_tmp__1553;
  unsigned long long llvm_cbe_tmp__1554;
  unsigned char llvm_cbe_tmp__1555;
  unsigned char llvm_cbe_tmp__1556;
  bool llvm_cbe_tmp__1557;
  bool llvm_cbe_tmp__1558;
  bool llvm_cbe_tmp__1558__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1559;
  unsigned long long llvm_cbe_tmp__1560;
  unsigned long long llvm_cbe_tmp__1561;
  unsigned char llvm_cbe_tmp__1562;
  unsigned long long llvm_cbe_tmp__1563;
  unsigned char llvm_cbe_tmp__1564;
  unsigned char llvm_cbe_tmp__1565;
  bool llvm_cbe_tmp__1566;
  bool llvm_cbe_tmp__1567;
  bool llvm_cbe_tmp__1567__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1568;
  unsigned char llvm_cbe_tmp__1569;
  unsigned char llvm_cbe_tmp__1570;
  bool llvm_cbe_tmp__1571;
  bool llvm_cbe_tmp__1572;
  bool llvm_cbe_tmp__1572__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1573;
  unsigned long long llvm_cbe_tmp__1574;
  unsigned long long llvm_cbe_tmp__1575;
  unsigned long long llvm_cbe_tmp__1576;
  unsigned long long llvm_cbe_tmp__1577;
  unsigned long long llvm_cbe_tmp__1578;
  unsigned long long llvm_cbe_tmp__1579;
  unsigned long long llvm_cbe_tmp__1580;
  unsigned long long llvm_cbe_tmp__1581;
  unsigned char llvm_cbe_tmp__1582;
  unsigned char llvm_cbe_tmp__1583;
  bool llvm_cbe_tmp__1584;
  bool llvm_cbe_tmp__1585;
  bool llvm_cbe_tmp__1585__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1586;
  unsigned char llvm_cbe_tmp__1587;
  bool llvm_cbe_tmp__1588;
  bool llvm_cbe_tmp__1589;
  bool llvm_cbe_tmp__1589__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1590;
  unsigned long long llvm_cbe_tmp__1591;
  unsigned long long llvm_cbe_tmp__1592;
  unsigned char llvm_cbe_tmp__1593;
  unsigned long long llvm_cbe_tmp__1594;
  unsigned long long llvm_cbe_tmp__1595;
  unsigned long long llvm_cbe_tmp__1596;
  unsigned long long llvm_cbe_tmp__1597;
  unsigned long long llvm_cbe_tmp__1598;
  unsigned long long llvm_cbe_tmp__1599;
  unsigned long long llvm_cbe_tmp__1600;
  unsigned long long llvm_cbe_tmp__1601;
  unsigned long long llvm_cbe_tmp__1602;
  unsigned char llvm_cbe_tmp__1603;
  unsigned char llvm_cbe_tmp__1604;
  bool llvm_cbe_tmp__1605;
  bool llvm_cbe_tmp__1606;
  bool llvm_cbe_tmp__1606__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1607;
  unsigned char llvm_cbe_tmp__1608;
  unsigned char llvm_cbe_tmp__1609;
  bool llvm_cbe_tmp__1610;
  bool llvm_cbe_tmp__1611;
  bool llvm_cbe_tmp__1611__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1612;
  unsigned long long llvm_cbe_tmp__1613;
  unsigned long long llvm_cbe_tmp__1614;
  unsigned char llvm_cbe_tmp__1615;
  unsigned long long llvm_cbe_tmp__1616;
  unsigned long long llvm_cbe_tmp__1617;
  unsigned char llvm_cbe_tmp__1618;
  unsigned char llvm_cbe_tmp__1619;
  bool llvm_cbe_tmp__1620;
  bool llvm_cbe_tmp__1621;
  bool llvm_cbe_tmp__1621__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1622;
  unsigned long long llvm_cbe_tmp__1623;
  unsigned long long llvm_cbe_tmp__1624;
  unsigned long long llvm_cbe_tmp__1625;
  unsigned long long llvm_cbe_tmp__1626;
  unsigned long long llvm_cbe_tmp__1627;

  *(&llvm_cbe_tmp__1533) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1534) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1535) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1536) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1537) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1538) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1539) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1540) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1541) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1542) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1543) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1544) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1545 = *(&llvm_cbe_tmp__1533);
  llvm_cbe_tmp__1546 = *((&llvm_cbe_tmp__1545->field24));
  *(&llvm_cbe_cppVar_1668) = (((unsigned char )(bool )(llvm_cbe_tmp__1546 == 0ull)));
  llvm_cbe_tmp__1547 = *(&llvm_cbe_cppVar_1668);
  if ((((((bool )llvm_cbe_tmp__1547&1u))&1))) {
    goto llvm_cbe_tmp__1628;
  } else {
    goto llvm_cbe_tmp__1629;
  }

llvm_cbe_tmp__1628:
  llvm_cbe_tmp__1548 = *((&llvm_cbe_tmp__1545->field25));
  llvm_cbe_tmp__1549 = *((&llvm_cbe_tmp__1545->field16));
  *(&llvm_cbe_cppVar_1670) = (((unsigned char )(bool )(llvm_cbe_tmp__1548 == llvm_cbe_tmp__1549)));
  llvm_cbe_tmp__1550 = *((&llvm_cbe_tmp__1545->field11));
  *(&llvm_cbe_cppVar_1672) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1550) - ((unsigned long long )1ull))));
  llvm_cbe_tmp__1551 = *(&llvm_cbe_cppVar_1672);
  llvm_cbe_tmp__1552 = *((&llvm_cbe_tmp__1545->field41));
  *(&llvm_cbe_cppVar_1672) = (llvm_cbe_tmp__1551 & llvm_cbe_tmp__1552);
  llvm_cbe_tmp__1553 = *((&llvm_cbe_tmp__1545->field19));
  llvm_cbe_tmp__1554 = *(&llvm_cbe_cppVar_1672);
  *(&llvm_cbe_cppVar_1673) = (((unsigned char )(bool )(llvm_cbe_tmp__1553 == llvm_cbe_tmp__1554)));
  llvm_cbe_tmp__1555 = *(&llvm_cbe_cppVar_1670);
  if ((((((bool )llvm_cbe_tmp__1555&1u))&1))) {
    goto llvm_cbe_tmp__1630;
  } else {
    llvm_cbe_tmp__1558__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1631;
  }

llvm_cbe_tmp__1630:
  llvm_cbe_tmp__1556 = *(&llvm_cbe_cppVar_1673);
  llvm_cbe_tmp__1557 = ((((bool )llvm_cbe_tmp__1556&1u))&1);
  llvm_cbe_tmp__1558__PHI_TEMPORARY = llvm_cbe_tmp__1557;   /* for PHI node */
  goto llvm_cbe_tmp__1631;

llvm_cbe_tmp__1631:
  llvm_cbe_tmp__1558 = ((llvm_cbe_tmp__1558__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1674) = (((unsigned char )(bool )llvm_cbe_tmp__1558));
  llvm_cbe_tmp__1559 = *(&llvm_cbe_cppVar_1674);
  if ((((((bool )llvm_cbe_tmp__1559&1u))&1))) {
    goto llvm_cbe_tmp__1632;
  } else {
    goto llvm_cbe_tmp__1633;
  }

llvm_cbe_tmp__1632:
  *(&llvm_cbe_cppVar_1669) = 1ull;
  goto llvm_cbe_tmp__1634;

llvm_cbe_tmp__1633:
  *(&llvm_cbe_cppVar_1669) = 0ull;
  goto llvm_cbe_tmp__1634;

llvm_cbe_tmp__1634:
  llvm_cbe_tmp__1560 = *(&llvm_cbe_cppVar_1669);
  *(&llvm_cbe_cppVar_1666) = llvm_cbe_tmp__1560;
  goto llvm_cbe_tmp__1635;

llvm_cbe_tmp__1629:
  llvm_cbe_tmp__1561 = *((&llvm_cbe_tmp__1545->field24));
  *(&llvm_cbe_cppVar_1679) = (((unsigned char )(bool )(llvm_cbe_tmp__1561 == 1ull)));
  llvm_cbe_tmp__1562 = *(&llvm_cbe_cppVar_1679);
  if ((((((bool )llvm_cbe_tmp__1562&1u))&1))) {
    goto llvm_cbe_tmp__1636;
  } else {
    goto llvm_cbe_tmp__1637;
  }

llvm_cbe_tmp__1636:
  llvm_cbe_tmp__1563 = *((&llvm_cbe_tmp__1545->field17));
  *(&llvm_cbe_cppVar_1682) = (((unsigned char )(bool )(llvm_cbe_tmp__1563 == 4ull)));
  llvm_cbe_tmp__1564 = *(&llvm_cbe_cppVar_1679);
  if ((((((bool )llvm_cbe_tmp__1564&1u))&1))) {
    goto llvm_cbe_tmp__1638;
  } else {
    llvm_cbe_tmp__1567__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1639;
  }

llvm_cbe_tmp__1638:
  llvm_cbe_tmp__1565 = *(&llvm_cbe_cppVar_1682);
  llvm_cbe_tmp__1566 = ((((bool )llvm_cbe_tmp__1565&1u))&1);
  llvm_cbe_tmp__1567__PHI_TEMPORARY = llvm_cbe_tmp__1566;   /* for PHI node */
  goto llvm_cbe_tmp__1639;

llvm_cbe_tmp__1639:
  llvm_cbe_tmp__1567 = ((llvm_cbe_tmp__1567__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1683) = (((unsigned char )(bool )llvm_cbe_tmp__1567));
  llvm_cbe_tmp__1568 = *((&llvm_cbe_tmp__1545->field9));
  *(&llvm_cbe_cppVar_1685) = (((unsigned char )(bool )(llvm_cbe_tmp__1568 == 4ull)));
  llvm_cbe_tmp__1569 = *(&llvm_cbe_cppVar_1683);
  if ((((((bool )llvm_cbe_tmp__1569&1u))&1))) {
    goto llvm_cbe_tmp__1640;
  } else {
    llvm_cbe_tmp__1572__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1641;
  }

llvm_cbe_tmp__1640:
  llvm_cbe_tmp__1570 = *(&llvm_cbe_cppVar_1685);
  llvm_cbe_tmp__1571 = ((((bool )llvm_cbe_tmp__1570&1u))&1);
  llvm_cbe_tmp__1572__PHI_TEMPORARY = llvm_cbe_tmp__1571;   /* for PHI node */
  goto llvm_cbe_tmp__1641;

llvm_cbe_tmp__1641:
  llvm_cbe_tmp__1572 = ((llvm_cbe_tmp__1572__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1686) = (((unsigned char )(bool )llvm_cbe_tmp__1572));
  llvm_cbe_tmp__1573 = *((&llvm_cbe_tmp__1545->field25));
  *(&llvm_cbe_cppVar_1688) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1573) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1574 = *(&llvm_cbe_cppVar_1688);
  llvm_cbe_tmp__1575 = *((&llvm_cbe_tmp__1545->field41));
  *(&llvm_cbe_cppVar_1688) = (llvm_cbe_tmp__1574 & llvm_cbe_tmp__1575);
  llvm_cbe_tmp__1576 = *(&llvm_cbe_cppVar_1688);
  llvm_cbe_tmp__1577 = *((&llvm_cbe_tmp__1545->field16));
  *(&llvm_cbe_cppVar_1689) = (((unsigned char )(bool )(llvm_cbe_tmp__1576 == llvm_cbe_tmp__1577)));
  llvm_cbe_tmp__1578 = *((&llvm_cbe_tmp__1545->field25));
  *(&llvm_cbe_cppVar_1691) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1578) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1579 = *(&llvm_cbe_cppVar_1691);
  llvm_cbe_tmp__1580 = *((&llvm_cbe_tmp__1545->field41));
  *(&llvm_cbe_cppVar_1691) = (llvm_cbe_tmp__1579 & llvm_cbe_tmp__1580);
  llvm_cbe_tmp__1581 = *(&llvm_cbe_cppVar_1691);
  *(&llvm_cbe_cppVar_1693) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__1581) >= ((signed long long )500ull))));
  llvm_cbe_tmp__1582 = *(&llvm_cbe_cppVar_1689);
  if ((((((bool )llvm_cbe_tmp__1582&1u))&1))) {
    llvm_cbe_tmp__1585__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__1642;
  } else {
    goto llvm_cbe_tmp__1643;
  }

llvm_cbe_tmp__1643:
  llvm_cbe_tmp__1583 = *(&llvm_cbe_cppVar_1693);
  llvm_cbe_tmp__1584 = ((((bool )llvm_cbe_tmp__1583&1u))&1);
  llvm_cbe_tmp__1585__PHI_TEMPORARY = llvm_cbe_tmp__1584;   /* for PHI node */
  goto llvm_cbe_tmp__1642;

llvm_cbe_tmp__1642:
  llvm_cbe_tmp__1585 = ((llvm_cbe_tmp__1585__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1694) = (((unsigned char )(bool )llvm_cbe_tmp__1585));
  llvm_cbe_tmp__1586 = *(&llvm_cbe_cppVar_1686);
  if ((((((bool )llvm_cbe_tmp__1586&1u))&1))) {
    goto llvm_cbe_tmp__1644;
  } else {
    llvm_cbe_tmp__1589__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1645;
  }

llvm_cbe_tmp__1644:
  llvm_cbe_tmp__1587 = *(&llvm_cbe_cppVar_1694);
  llvm_cbe_tmp__1588 = ((((bool )llvm_cbe_tmp__1587&1u))&1);
  llvm_cbe_tmp__1589__PHI_TEMPORARY = llvm_cbe_tmp__1588;   /* for PHI node */
  goto llvm_cbe_tmp__1645;

llvm_cbe_tmp__1645:
  llvm_cbe_tmp__1589 = ((llvm_cbe_tmp__1589__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1695) = (((unsigned char )(bool )llvm_cbe_tmp__1589));
  llvm_cbe_tmp__1590 = *(&llvm_cbe_cppVar_1695);
  if ((((((bool )llvm_cbe_tmp__1590&1u))&1))) {
    goto llvm_cbe_tmp__1646;
  } else {
    goto llvm_cbe_tmp__1647;
  }

llvm_cbe_tmp__1646:
  *(&llvm_cbe_cppVar_1680) = 3ull;
  goto llvm_cbe_tmp__1648;

llvm_cbe_tmp__1647:
  *(&llvm_cbe_cppVar_1680) = 1ull;
  goto llvm_cbe_tmp__1648;

llvm_cbe_tmp__1648:
  llvm_cbe_tmp__1591 = *(&llvm_cbe_cppVar_1680);
  *(&llvm_cbe_cppVar_1677) = llvm_cbe_tmp__1591;
  goto llvm_cbe_tmp__1649;

llvm_cbe_tmp__1637:
  llvm_cbe_tmp__1592 = *((&llvm_cbe_tmp__1545->field24));
  *(&llvm_cbe_cppVar_1699) = (((unsigned char )(bool )(llvm_cbe_tmp__1592 == 3ull)));
  llvm_cbe_tmp__1593 = *(&llvm_cbe_cppVar_1699);
  if ((((((bool )llvm_cbe_tmp__1593&1u))&1))) {
    goto llvm_cbe_tmp__1650;
  } else {
    goto llvm_cbe_tmp__1651;
  }

llvm_cbe_tmp__1650:
  llvm_cbe_tmp__1594 = *((&llvm_cbe_tmp__1545->field25));
  *(&llvm_cbe_cppVar_1702) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1594) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1595 = *(&llvm_cbe_cppVar_1702);
  llvm_cbe_tmp__1596 = *((&llvm_cbe_tmp__1545->field41));
  *(&llvm_cbe_cppVar_1702) = (llvm_cbe_tmp__1595 & llvm_cbe_tmp__1596);
  llvm_cbe_tmp__1597 = *(&llvm_cbe_cppVar_1702);
  llvm_cbe_tmp__1598 = *((&llvm_cbe_tmp__1545->field16));
  *(&llvm_cbe_cppVar_1703) = (((unsigned char )(bool )(llvm_cbe_tmp__1597 == llvm_cbe_tmp__1598)));
  llvm_cbe_tmp__1599 = *((&llvm_cbe_tmp__1545->field25));
  *(&llvm_cbe_cppVar_1705) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1599) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1600 = *(&llvm_cbe_cppVar_1705);
  llvm_cbe_tmp__1601 = *((&llvm_cbe_tmp__1545->field41));
  *(&llvm_cbe_cppVar_1705) = (llvm_cbe_tmp__1600 & llvm_cbe_tmp__1601);
  llvm_cbe_tmp__1602 = *(&llvm_cbe_cppVar_1705);
  *(&llvm_cbe_cppVar_1707) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__1602) >= ((signed long long )500ull))));
  llvm_cbe_tmp__1603 = *(&llvm_cbe_cppVar_1703);
  if ((((((bool )llvm_cbe_tmp__1603&1u))&1))) {
    llvm_cbe_tmp__1606__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__1652;
  } else {
    goto llvm_cbe_tmp__1653;
  }

llvm_cbe_tmp__1653:
  llvm_cbe_tmp__1604 = *(&llvm_cbe_cppVar_1707);
  llvm_cbe_tmp__1605 = ((((bool )llvm_cbe_tmp__1604&1u))&1);
  llvm_cbe_tmp__1606__PHI_TEMPORARY = llvm_cbe_tmp__1605;   /* for PHI node */
  goto llvm_cbe_tmp__1652;

llvm_cbe_tmp__1652:
  llvm_cbe_tmp__1606 = ((llvm_cbe_tmp__1606__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1708) = (((unsigned char )(bool )llvm_cbe_tmp__1606));
  llvm_cbe_tmp__1607 = *((&llvm_cbe_tmp__1545->field9));
  *(&llvm_cbe_cppVar_1710) = (((unsigned char )(bool )(llvm_cbe_tmp__1607 == 4ull)));
  llvm_cbe_tmp__1608 = *(&llvm_cbe_cppVar_1708);
  if ((((((bool )llvm_cbe_tmp__1608&1u))&1))) {
    goto llvm_cbe_tmp__1654;
  } else {
    llvm_cbe_tmp__1611__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1655;
  }

llvm_cbe_tmp__1654:
  llvm_cbe_tmp__1609 = *(&llvm_cbe_cppVar_1710);
  llvm_cbe_tmp__1610 = ((((bool )llvm_cbe_tmp__1609&1u))&1);
  llvm_cbe_tmp__1611__PHI_TEMPORARY = llvm_cbe_tmp__1610;   /* for PHI node */
  goto llvm_cbe_tmp__1655;

llvm_cbe_tmp__1655:
  llvm_cbe_tmp__1611 = ((llvm_cbe_tmp__1611__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1711) = (((unsigned char )(bool )llvm_cbe_tmp__1611));
  llvm_cbe_tmp__1612 = *(&llvm_cbe_cppVar_1711);
  if ((((((bool )llvm_cbe_tmp__1612&1u))&1))) {
    goto llvm_cbe_tmp__1656;
  } else {
    goto llvm_cbe_tmp__1657;
  }

llvm_cbe_tmp__1656:
  *(&llvm_cbe_cppVar_1700) = 2ull;
  goto llvm_cbe_tmp__1658;

llvm_cbe_tmp__1657:
  *(&llvm_cbe_cppVar_1700) = 3ull;
  goto llvm_cbe_tmp__1658;

llvm_cbe_tmp__1658:
  llvm_cbe_tmp__1613 = *(&llvm_cbe_cppVar_1700);
  *(&llvm_cbe_cppVar_1697) = llvm_cbe_tmp__1613;
  goto llvm_cbe_tmp__1659;

llvm_cbe_tmp__1651:
  llvm_cbe_tmp__1614 = *((&llvm_cbe_tmp__1545->field24));
  *(&llvm_cbe_cppVar_1715) = (((unsigned char )(bool )(llvm_cbe_tmp__1614 == 2ull)));
  llvm_cbe_tmp__1615 = *(&llvm_cbe_cppVar_1715);
  if ((((((bool )llvm_cbe_tmp__1615&1u))&1))) {
    goto llvm_cbe_tmp__1660;
  } else {
    goto llvm_cbe_tmp__1661;
  }

llvm_cbe_tmp__1660:
  llvm_cbe_tmp__1616 = *((&llvm_cbe_tmp__1545->field39));
  *(&llvm_cbe_cppVar_1718) = (((unsigned char )(bool )(llvm_cbe_tmp__1616 == 0ull)));
  llvm_cbe_tmp__1617 = *((&llvm_cbe_tmp__1545->field36));
  *(&llvm_cbe_cppVar_1720) = (((unsigned char )(bool )(llvm_cbe_tmp__1617 == 1ull)));
  llvm_cbe_tmp__1618 = *(&llvm_cbe_cppVar_1718);
  if ((((((bool )llvm_cbe_tmp__1618&1u))&1))) {
    goto llvm_cbe_tmp__1662;
  } else {
    llvm_cbe_tmp__1621__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1663;
  }

llvm_cbe_tmp__1662:
  llvm_cbe_tmp__1619 = *(&llvm_cbe_cppVar_1720);
  llvm_cbe_tmp__1620 = ((((bool )llvm_cbe_tmp__1619&1u))&1);
  llvm_cbe_tmp__1621__PHI_TEMPORARY = llvm_cbe_tmp__1620;   /* for PHI node */
  goto llvm_cbe_tmp__1663;

llvm_cbe_tmp__1663:
  llvm_cbe_tmp__1621 = ((llvm_cbe_tmp__1621__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1721) = (((unsigned char )(bool )llvm_cbe_tmp__1621));
  *(&llvm_cbe_cppVar_1716) = 2ull;
  llvm_cbe_tmp__1622 = *(&llvm_cbe_cppVar_1716);
  *(&llvm_cbe_cppVar_1713) = llvm_cbe_tmp__1622;
  goto llvm_cbe_tmp__1664;

llvm_cbe_tmp__1661:
  llvm_cbe_tmp__1623 = *((&llvm_cbe_tmp__1545->field24));
  *(&llvm_cbe_cppVar_1713) = llvm_cbe_tmp__1623;
  goto llvm_cbe_tmp__1664;

llvm_cbe_tmp__1664:
  llvm_cbe_tmp__1624 = *(&llvm_cbe_cppVar_1713);
  *(&llvm_cbe_cppVar_1697) = llvm_cbe_tmp__1624;
  goto llvm_cbe_tmp__1659;

llvm_cbe_tmp__1659:
  llvm_cbe_tmp__1625 = *(&llvm_cbe_cppVar_1697);
  *(&llvm_cbe_cppVar_1677) = llvm_cbe_tmp__1625;
  goto llvm_cbe_tmp__1649;

llvm_cbe_tmp__1649:
  llvm_cbe_tmp__1626 = *(&llvm_cbe_cppVar_1677);
  *(&llvm_cbe_cppVar_1666) = llvm_cbe_tmp__1626;
  goto llvm_cbe_tmp__1635;

llvm_cbe_tmp__1635:
  llvm_cbe_tmp__1627 = *(&llvm_cbe_cppVar_1666);
  return llvm_cbe_tmp__1627;
}


unsigned long long _ZN13model_predict26cppUpdateFun_predict_v_cntElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__1665;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1666;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1667;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1668;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1669;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1670;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1671;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1672;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1673;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1674;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1675;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1676;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1728;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1724;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1725;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1732;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1733;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1753;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1754;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1769;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1770;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1727;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1729;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1730;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1726;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1738;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1739;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1742;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1743;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1744;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1745;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1746;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1747;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1748;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1749;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1735;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1736;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1737;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1740;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1750;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1751;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1741;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1734;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1756;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1757;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1758;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1759;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1760;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1761;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1762;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1763;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1764;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1765;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1766;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1767;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1755;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1768;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1752;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1731;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1723;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__1677;
  unsigned long long llvm_cbe_tmp__1678;
  unsigned char llvm_cbe_tmp__1679;
  unsigned long long llvm_cbe_tmp__1680;
  unsigned long long llvm_cbe_tmp__1681;
  unsigned char llvm_cbe_tmp__1682;
  unsigned long long llvm_cbe_tmp__1683;
  unsigned long long llvm_cbe_tmp__1684;
  unsigned long long llvm_cbe_tmp__1685;
  unsigned long long llvm_cbe_tmp__1686;
  unsigned long long llvm_cbe_tmp__1687;
  unsigned long long llvm_cbe_tmp__1688;
  unsigned char llvm_cbe_tmp__1689;
  unsigned long long llvm_cbe_tmp__1690;
  unsigned char llvm_cbe_tmp__1691;
  unsigned char llvm_cbe_tmp__1692;
  bool llvm_cbe_tmp__1693;
  bool llvm_cbe_tmp__1694;
  bool llvm_cbe_tmp__1694__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1695;
  unsigned char llvm_cbe_tmp__1696;
  unsigned char llvm_cbe_tmp__1697;
  bool llvm_cbe_tmp__1698;
  bool llvm_cbe_tmp__1699;
  bool llvm_cbe_tmp__1699__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1700;
  unsigned long long llvm_cbe_tmp__1701;
  unsigned long long llvm_cbe_tmp__1702;
  unsigned long long llvm_cbe_tmp__1703;
  unsigned long long llvm_cbe_tmp__1704;
  unsigned long long llvm_cbe_tmp__1705;
  unsigned long long llvm_cbe_tmp__1706;
  unsigned long long llvm_cbe_tmp__1707;
  unsigned long long llvm_cbe_tmp__1708;
  unsigned long long llvm_cbe_tmp__1709;
  unsigned char llvm_cbe_tmp__1710;
  unsigned char llvm_cbe_tmp__1711;
  bool llvm_cbe_tmp__1712;
  bool llvm_cbe_tmp__1713;
  bool llvm_cbe_tmp__1713__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1714;
  unsigned long long llvm_cbe_tmp__1715;
  unsigned long long llvm_cbe_tmp__1716;
  unsigned long long llvm_cbe_tmp__1717;
  unsigned long long llvm_cbe_tmp__1718;
  unsigned long long llvm_cbe_tmp__1719;
  unsigned long long llvm_cbe_tmp__1720;
  unsigned long long llvm_cbe_tmp__1721;
  unsigned char llvm_cbe_tmp__1722;
  unsigned long long llvm_cbe_tmp__1723;
  unsigned long long llvm_cbe_tmp__1724;
  unsigned long long llvm_cbe_tmp__1725;
  unsigned long long llvm_cbe_tmp__1726;
  unsigned long long llvm_cbe_tmp__1727;
  unsigned long long llvm_cbe_tmp__1728;
  unsigned long long llvm_cbe_tmp__1729;
  unsigned long long llvm_cbe_tmp__1730;
  unsigned long long llvm_cbe_tmp__1731;
  unsigned char llvm_cbe_tmp__1732;
  unsigned char llvm_cbe_tmp__1733;
  bool llvm_cbe_tmp__1734;
  bool llvm_cbe_tmp__1735;
  bool llvm_cbe_tmp__1735__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1736;
  unsigned long long llvm_cbe_tmp__1737;
  unsigned long long llvm_cbe_tmp__1738;
  unsigned long long llvm_cbe_tmp__1739;
  unsigned long long llvm_cbe_tmp__1740;
  unsigned long long llvm_cbe_tmp__1741;
  unsigned long long llvm_cbe_tmp__1742;
  unsigned long long llvm_cbe_tmp__1743;
  unsigned long long llvm_cbe_tmp__1744;
  unsigned long long llvm_cbe_tmp__1745;
  unsigned long long llvm_cbe_tmp__1746;
  unsigned long long llvm_cbe_tmp__1747;
  unsigned long long llvm_cbe_tmp__1748;
  unsigned long long llvm_cbe_tmp__1749;
  unsigned long long llvm_cbe_tmp__1750;
  unsigned long long llvm_cbe_tmp__1751;

  *(&llvm_cbe_tmp__1665) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1666) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1667) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1668) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1669) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1670) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1671) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1672) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1673) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1674) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1675) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1676) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1677 = *(&llvm_cbe_tmp__1665);
  llvm_cbe_tmp__1678 = *((&llvm_cbe_tmp__1677->field24));
  *(&llvm_cbe_cppVar_1725) = (((unsigned char )(bool )(llvm_cbe_tmp__1678 == 0ull)));
  llvm_cbe_tmp__1679 = *(&llvm_cbe_cppVar_1725);
  if ((((((bool )llvm_cbe_tmp__1679&1u))&1))) {
    goto llvm_cbe_tmp__1752;
  } else {
    goto llvm_cbe_tmp__1753;
  }

llvm_cbe_tmp__1752:
  llvm_cbe_tmp__1680 = *((&llvm_cbe_tmp__1677->field25));
  llvm_cbe_tmp__1681 = *((&llvm_cbe_tmp__1677->field16));
  *(&llvm_cbe_cppVar_1727) = (((unsigned char )(bool )(llvm_cbe_tmp__1680 == llvm_cbe_tmp__1681)));
  llvm_cbe_tmp__1682 = *(&llvm_cbe_cppVar_1727);
  if ((((((bool )llvm_cbe_tmp__1682&1u))&1))) {
    goto llvm_cbe_tmp__1754;
  } else {
    goto llvm_cbe_tmp__1755;
  }

llvm_cbe_tmp__1754:
  *(&llvm_cbe_cppVar_1726) = 0ull;
  goto llvm_cbe_tmp__1756;

llvm_cbe_tmp__1755:
  llvm_cbe_tmp__1683 = *((&llvm_cbe_tmp__1677->field25));
  *(&llvm_cbe_cppVar_1730) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1683) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__1684 = *(&llvm_cbe_cppVar_1730);
  llvm_cbe_tmp__1685 = *((&llvm_cbe_tmp__1677->field41));
  *(&llvm_cbe_cppVar_1730) = (llvm_cbe_tmp__1684 & llvm_cbe_tmp__1685);
  llvm_cbe_tmp__1686 = *(&llvm_cbe_cppVar_1730);
  *(&llvm_cbe_cppVar_1726) = llvm_cbe_tmp__1686;
  goto llvm_cbe_tmp__1756;

llvm_cbe_tmp__1756:
  llvm_cbe_tmp__1687 = *(&llvm_cbe_cppVar_1726);
  *(&llvm_cbe_cppVar_1723) = llvm_cbe_tmp__1687;
  goto llvm_cbe_tmp__1757;

llvm_cbe_tmp__1753:
  llvm_cbe_tmp__1688 = *((&llvm_cbe_tmp__1677->field24));
  *(&llvm_cbe_cppVar_1733) = (((unsigned char )(bool )(llvm_cbe_tmp__1688 == 1ull)));
  llvm_cbe_tmp__1689 = *(&llvm_cbe_cppVar_1733);
  if ((((((bool )llvm_cbe_tmp__1689&1u))&1))) {
    goto llvm_cbe_tmp__1758;
  } else {
    goto llvm_cbe_tmp__1759;
  }

llvm_cbe_tmp__1758:
  llvm_cbe_tmp__1690 = *((&llvm_cbe_tmp__1677->field17));
  *(&llvm_cbe_cppVar_1736) = (((unsigned char )(bool )(llvm_cbe_tmp__1690 == 4ull)));
  llvm_cbe_tmp__1691 = *(&llvm_cbe_cppVar_1733);
  if ((((((bool )llvm_cbe_tmp__1691&1u))&1))) {
    goto llvm_cbe_tmp__1760;
  } else {
    llvm_cbe_tmp__1694__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1761;
  }

llvm_cbe_tmp__1760:
  llvm_cbe_tmp__1692 = *(&llvm_cbe_cppVar_1736);
  llvm_cbe_tmp__1693 = ((((bool )llvm_cbe_tmp__1692&1u))&1);
  llvm_cbe_tmp__1694__PHI_TEMPORARY = llvm_cbe_tmp__1693;   /* for PHI node */
  goto llvm_cbe_tmp__1761;

llvm_cbe_tmp__1761:
  llvm_cbe_tmp__1694 = ((llvm_cbe_tmp__1694__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1737) = (((unsigned char )(bool )llvm_cbe_tmp__1694));
  llvm_cbe_tmp__1695 = *((&llvm_cbe_tmp__1677->field9));
  *(&llvm_cbe_cppVar_1739) = (((unsigned char )(bool )(llvm_cbe_tmp__1695 == 4ull)));
  llvm_cbe_tmp__1696 = *(&llvm_cbe_cppVar_1737);
  if ((((((bool )llvm_cbe_tmp__1696&1u))&1))) {
    goto llvm_cbe_tmp__1762;
  } else {
    llvm_cbe_tmp__1699__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1763;
  }

llvm_cbe_tmp__1762:
  llvm_cbe_tmp__1697 = *(&llvm_cbe_cppVar_1739);
  llvm_cbe_tmp__1698 = ((((bool )llvm_cbe_tmp__1697&1u))&1);
  llvm_cbe_tmp__1699__PHI_TEMPORARY = llvm_cbe_tmp__1698;   /* for PHI node */
  goto llvm_cbe_tmp__1763;

llvm_cbe_tmp__1763:
  llvm_cbe_tmp__1699 = ((llvm_cbe_tmp__1699__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1740) = (((unsigned char )(bool )llvm_cbe_tmp__1699));
  llvm_cbe_tmp__1700 = *(&llvm_cbe_cppVar_1740);
  llvm_cbe_tmp__1701 = *((&llvm_cbe_tmp__1677->field25));
  if ((((((bool )llvm_cbe_tmp__1700&1u))&1))) {
    goto llvm_cbe_tmp__1764;
  } else {
    goto llvm_cbe_tmp__1765;
  }

llvm_cbe_tmp__1764:
  *(&llvm_cbe_cppVar_1743) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1701) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1702 = *(&llvm_cbe_cppVar_1743);
  llvm_cbe_tmp__1703 = *((&llvm_cbe_tmp__1677->field41));
  *(&llvm_cbe_cppVar_1743) = (llvm_cbe_tmp__1702 & llvm_cbe_tmp__1703);
  llvm_cbe_tmp__1704 = *(&llvm_cbe_cppVar_1743);
  llvm_cbe_tmp__1705 = *((&llvm_cbe_tmp__1677->field16));
  *(&llvm_cbe_cppVar_1744) = (((unsigned char )(bool )(llvm_cbe_tmp__1704 == llvm_cbe_tmp__1705)));
  llvm_cbe_tmp__1706 = *((&llvm_cbe_tmp__1677->field25));
  *(&llvm_cbe_cppVar_1746) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1706) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1707 = *(&llvm_cbe_cppVar_1746);
  llvm_cbe_tmp__1708 = *((&llvm_cbe_tmp__1677->field41));
  *(&llvm_cbe_cppVar_1746) = (llvm_cbe_tmp__1707 & llvm_cbe_tmp__1708);
  llvm_cbe_tmp__1709 = *(&llvm_cbe_cppVar_1746);
  *(&llvm_cbe_cppVar_1748) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__1709) >= ((signed long long )500ull))));
  llvm_cbe_tmp__1710 = *(&llvm_cbe_cppVar_1744);
  if ((((((bool )llvm_cbe_tmp__1710&1u))&1))) {
    llvm_cbe_tmp__1713__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__1766;
  } else {
    goto llvm_cbe_tmp__1767;
  }

llvm_cbe_tmp__1767:
  llvm_cbe_tmp__1711 = *(&llvm_cbe_cppVar_1748);
  llvm_cbe_tmp__1712 = ((((bool )llvm_cbe_tmp__1711&1u))&1);
  llvm_cbe_tmp__1713__PHI_TEMPORARY = llvm_cbe_tmp__1712;   /* for PHI node */
  goto llvm_cbe_tmp__1766;

llvm_cbe_tmp__1766:
  llvm_cbe_tmp__1713 = ((llvm_cbe_tmp__1713__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1749) = (((unsigned char )(bool )llvm_cbe_tmp__1713));
  llvm_cbe_tmp__1714 = *(&llvm_cbe_cppVar_1749);
  if ((((((bool )llvm_cbe_tmp__1714&1u))&1))) {
    goto llvm_cbe_tmp__1768;
  } else {
    goto llvm_cbe_tmp__1769;
  }

llvm_cbe_tmp__1768:
  *(&llvm_cbe_cppVar_1741) = 0ull;
  goto llvm_cbe_tmp__1770;

llvm_cbe_tmp__1769:
  llvm_cbe_tmp__1715 = *((&llvm_cbe_tmp__1677->field25));
  *(&llvm_cbe_cppVar_1751) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1715) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1716 = *(&llvm_cbe_cppVar_1751);
  llvm_cbe_tmp__1717 = *((&llvm_cbe_tmp__1677->field41));
  *(&llvm_cbe_cppVar_1751) = (llvm_cbe_tmp__1716 & llvm_cbe_tmp__1717);
  llvm_cbe_tmp__1718 = *(&llvm_cbe_cppVar_1751);
  *(&llvm_cbe_cppVar_1741) = llvm_cbe_tmp__1718;
  goto llvm_cbe_tmp__1770;

llvm_cbe_tmp__1770:
  llvm_cbe_tmp__1719 = *(&llvm_cbe_cppVar_1741);
  *(&llvm_cbe_cppVar_1734) = llvm_cbe_tmp__1719;
  goto llvm_cbe_tmp__1771;

llvm_cbe_tmp__1765:
  *(&llvm_cbe_cppVar_1734) = llvm_cbe_tmp__1701;
  goto llvm_cbe_tmp__1771;

llvm_cbe_tmp__1771:
  llvm_cbe_tmp__1720 = *(&llvm_cbe_cppVar_1734);
  *(&llvm_cbe_cppVar_1731) = llvm_cbe_tmp__1720;
  goto llvm_cbe_tmp__1772;

llvm_cbe_tmp__1759:
  llvm_cbe_tmp__1721 = *((&llvm_cbe_tmp__1677->field24));
  *(&llvm_cbe_cppVar_1754) = (((unsigned char )(bool )(llvm_cbe_tmp__1721 == 3ull)));
  llvm_cbe_tmp__1722 = *(&llvm_cbe_cppVar_1754);
  if ((((((bool )llvm_cbe_tmp__1722&1u))&1))) {
    goto llvm_cbe_tmp__1773;
  } else {
    goto llvm_cbe_tmp__1774;
  }

llvm_cbe_tmp__1773:
  llvm_cbe_tmp__1723 = *((&llvm_cbe_tmp__1677->field25));
  *(&llvm_cbe_cppVar_1757) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1723) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1724 = *(&llvm_cbe_cppVar_1757);
  llvm_cbe_tmp__1725 = *((&llvm_cbe_tmp__1677->field41));
  *(&llvm_cbe_cppVar_1757) = (llvm_cbe_tmp__1724 & llvm_cbe_tmp__1725);
  llvm_cbe_tmp__1726 = *(&llvm_cbe_cppVar_1757);
  llvm_cbe_tmp__1727 = *((&llvm_cbe_tmp__1677->field16));
  *(&llvm_cbe_cppVar_1758) = (((unsigned char )(bool )(llvm_cbe_tmp__1726 == llvm_cbe_tmp__1727)));
  llvm_cbe_tmp__1728 = *((&llvm_cbe_tmp__1677->field25));
  *(&llvm_cbe_cppVar_1760) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1728) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1729 = *(&llvm_cbe_cppVar_1760);
  llvm_cbe_tmp__1730 = *((&llvm_cbe_tmp__1677->field41));
  *(&llvm_cbe_cppVar_1760) = (llvm_cbe_tmp__1729 & llvm_cbe_tmp__1730);
  llvm_cbe_tmp__1731 = *(&llvm_cbe_cppVar_1760);
  *(&llvm_cbe_cppVar_1762) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__1731) >= ((signed long long )500ull))));
  llvm_cbe_tmp__1732 = *(&llvm_cbe_cppVar_1758);
  if ((((((bool )llvm_cbe_tmp__1732&1u))&1))) {
    llvm_cbe_tmp__1735__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__1775;
  } else {
    goto llvm_cbe_tmp__1776;
  }

llvm_cbe_tmp__1776:
  llvm_cbe_tmp__1733 = *(&llvm_cbe_cppVar_1762);
  llvm_cbe_tmp__1734 = ((((bool )llvm_cbe_tmp__1733&1u))&1);
  llvm_cbe_tmp__1735__PHI_TEMPORARY = llvm_cbe_tmp__1734;   /* for PHI node */
  goto llvm_cbe_tmp__1775;

llvm_cbe_tmp__1775:
  llvm_cbe_tmp__1735 = ((llvm_cbe_tmp__1735__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1763) = (((unsigned char )(bool )llvm_cbe_tmp__1735));
  llvm_cbe_tmp__1736 = *(&llvm_cbe_cppVar_1763);
  llvm_cbe_tmp__1737 = *((&llvm_cbe_tmp__1677->field25));
  llvm_cbe_tmp__1738 = ((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1737) + ((unsigned long long )5ull)));
  if ((((((bool )llvm_cbe_tmp__1736&1u))&1))) {
    goto llvm_cbe_tmp__1777;
  } else {
    goto llvm_cbe_tmp__1778;
  }

llvm_cbe_tmp__1777:
  *(&llvm_cbe_cppVar_1765) = llvm_cbe_tmp__1738;
  llvm_cbe_tmp__1739 = *(&llvm_cbe_cppVar_1765);
  llvm_cbe_tmp__1740 = *((&llvm_cbe_tmp__1677->field41));
  *(&llvm_cbe_cppVar_1765) = (llvm_cbe_tmp__1739 & llvm_cbe_tmp__1740);
  llvm_cbe_tmp__1741 = *(&llvm_cbe_cppVar_1765);
  *(&llvm_cbe_cppVar_1755) = llvm_cbe_tmp__1741;
  goto llvm_cbe_tmp__1779;

llvm_cbe_tmp__1778:
  *(&llvm_cbe_cppVar_1767) = llvm_cbe_tmp__1738;
  llvm_cbe_tmp__1742 = *(&llvm_cbe_cppVar_1767);
  llvm_cbe_tmp__1743 = *((&llvm_cbe_tmp__1677->field41));
  *(&llvm_cbe_cppVar_1767) = (llvm_cbe_tmp__1742 & llvm_cbe_tmp__1743);
  llvm_cbe_tmp__1744 = *(&llvm_cbe_cppVar_1767);
  *(&llvm_cbe_cppVar_1755) = llvm_cbe_tmp__1744;
  goto llvm_cbe_tmp__1779;

llvm_cbe_tmp__1779:
  llvm_cbe_tmp__1745 = *(&llvm_cbe_cppVar_1755);
  *(&llvm_cbe_cppVar_1752) = llvm_cbe_tmp__1745;
  goto llvm_cbe_tmp__1780;

llvm_cbe_tmp__1774:
  llvm_cbe_tmp__1746 = *((&llvm_cbe_tmp__1677->field24));
  *(&llvm_cbe_cppVar_1770) = (((unsigned char )(bool )(llvm_cbe_tmp__1746 == 2ull)));
  llvm_cbe_tmp__1747 = *((&llvm_cbe_tmp__1677->field25));
  *(&llvm_cbe_cppVar_1768) = llvm_cbe_tmp__1747;
  llvm_cbe_tmp__1748 = *(&llvm_cbe_cppVar_1768);
  *(&llvm_cbe_cppVar_1752) = llvm_cbe_tmp__1748;
  goto llvm_cbe_tmp__1780;

llvm_cbe_tmp__1780:
  llvm_cbe_tmp__1749 = *(&llvm_cbe_cppVar_1752);
  *(&llvm_cbe_cppVar_1731) = llvm_cbe_tmp__1749;
  goto llvm_cbe_tmp__1772;

llvm_cbe_tmp__1772:
  llvm_cbe_tmp__1750 = *(&llvm_cbe_cppVar_1731);
  *(&llvm_cbe_cppVar_1723) = llvm_cbe_tmp__1750;
  goto llvm_cbe_tmp__1757;

llvm_cbe_tmp__1757:
  llvm_cbe_tmp__1751 = *(&llvm_cbe_cppVar_1723);
  return llvm_cbe_tmp__1751;
}


struct l_class_OC_SysCArray1D _ZN13model_predict27cppUpdateFun_predict_vectorElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_SysCArray1D StructReturn;  /* Struct return temporary */
  struct l_class_OC_SysCArray1D *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_predict *llvm_cbe_tmp__1781;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1782;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1783;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1784;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1785;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1786;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1787;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1788;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1789;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1790;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1791;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1792;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2096;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2095;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2067;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2068;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2070;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2071;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2101;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2102;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2086;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2087;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2077;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2078;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2079;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2080;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2081;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2082;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2083;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2084;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2073;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2074;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2075;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2092;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2093;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2094;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2091;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2089;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2090;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_2097;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2085;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2088;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2098;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_2099;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__1793;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1794;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_2076;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_2072;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_2100;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_2069;    /* Address-exposed local */
  bool llvm_cbe_tmp__1795;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1796;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__1797;
  unsigned long long llvm_cbe_tmp__1798;
  unsigned char llvm_cbe_tmp__1799;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1800;
  unsigned long long llvm_cbe_tmp__1801;
  unsigned char llvm_cbe_tmp__1802;
  unsigned long long llvm_cbe_tmp__1803;
  unsigned char llvm_cbe_tmp__1804;
  unsigned char llvm_cbe_tmp__1805;
  bool llvm_cbe_tmp__1806;
  bool llvm_cbe_tmp__1807;
  bool llvm_cbe_tmp__1807__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1808;
  unsigned long long llvm_cbe_tmp__1809;
  unsigned long long llvm_cbe_tmp__1810;
  unsigned long long llvm_cbe_tmp__1811;
  unsigned long long llvm_cbe_tmp__1812;
  unsigned long long llvm_cbe_tmp__1813;
  unsigned long long llvm_cbe_tmp__1814;
  unsigned long long llvm_cbe_tmp__1815;
  unsigned long long llvm_cbe_tmp__1816;
  unsigned long long llvm_cbe_tmp__1817;
  unsigned char llvm_cbe_tmp__1818;
  unsigned char llvm_cbe_tmp__1819;
  bool llvm_cbe_tmp__1820;
  bool llvm_cbe_tmp__1821;
  bool llvm_cbe_tmp__1821__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1822;
  unsigned char llvm_cbe_tmp__1823;
  bool llvm_cbe_tmp__1824;
  bool llvm_cbe_tmp__1825;
  bool llvm_cbe_tmp__1825__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1826;
  unsigned char llvm_cbe_tmp__1827;
  unsigned char llvm_cbe_tmp__1828;
  bool llvm_cbe_tmp__1829;
  bool llvm_cbe_tmp__1830;
  bool llvm_cbe_tmp__1830__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1831;
  unsigned long long llvm_cbe_tmp__1832;
  unsigned long long llvm_cbe_tmp__1833;
  unsigned long long llvm_cbe_tmp__1834;
  unsigned long long llvm_cbe_tmp__1835;
  unsigned long long llvm_cbe_tmp__1836;
  unsigned long long llvm_cbe_tmp__1837;
  unsigned long long llvm_cbe_tmp__1838;
  unsigned short llvm_cbe_tmp__1839;
  unsigned long long llvm_cbe_tmp__1840;
  unsigned long long llvm_cbe_tmp__1841;
  unsigned long long llvm_cbe_tmp__1842;
  unsigned long long llvm_cbe_tmp__1843;
  unsigned char llvm_cbe_tmp__1844;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1845;
  unsigned long long llvm_cbe_tmp__1846;
  unsigned long long llvm_cbe_tmp__1847;
  unsigned long long llvm_cbe_tmp__1848;
  unsigned long long llvm_cbe_tmp__1849;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1850;
  unsigned long long llvm_cbe_tmp__1851;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1852;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1853;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1854;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1855;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1856;
  unsigned long long llvm_cbe_tmp__1857;
  unsigned char llvm_cbe_tmp__1858;
  bool llvm_cbe_tmp__1859;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1860;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1861;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1862;
  bool llvm_cbe_tmp__1863;

  *(&llvm_cbe_tmp__1781) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1782) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1783) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1784) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1785) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1786) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1787) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1788) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1789) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1790) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1791) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1792) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1797 = *(&llvm_cbe_tmp__1781);
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_2097));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_2099));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_2076));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_2072));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_2100));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_2069));
  *(&llvm_cbe_tmp__1795) = ((0) & 1);
  _ZN8type_memIbLj512EEC1Ev(llvm_cbe_agg_2e_result);
  llvm_cbe_tmp__1798 = *((&llvm_cbe_tmp__1797->field24));
  *(&llvm_cbe_cppVar_2068) = (((unsigned char )(bool )(llvm_cbe_tmp__1798 == 0ull)));
  llvm_cbe_tmp__1799 = *(&llvm_cbe_cppVar_2068);
  if ((((((bool )llvm_cbe_tmp__1799&1u))&1))) {
    goto llvm_cbe_tmp__1864;
  } else {
    goto llvm_cbe_tmp__1865;
  }

llvm_cbe_tmp__1864:
  llvm_cbe_tmp__1800 = _ZN8type_memIbLj512EEaSERKS0_(llvm_cbe_agg_2e_result, ((&llvm_cbe_tmp__1797->field26)));
  goto llvm_cbe_tmp__1866;

llvm_cbe_tmp__1865:
  llvm_cbe_tmp__1801 = *((&llvm_cbe_tmp__1797->field24));
  *(&llvm_cbe_cppVar_2071) = (((unsigned char )(bool )(llvm_cbe_tmp__1801 == 1ull)));
  llvm_cbe_tmp__1802 = *(&llvm_cbe_cppVar_2071);
  if ((((((bool )llvm_cbe_tmp__1802&1u))&1))) {
    goto llvm_cbe_tmp__1867;
  } else {
    goto llvm_cbe_tmp__1868;
  }

llvm_cbe_tmp__1867:
  llvm_cbe_tmp__1803 = *((&llvm_cbe_tmp__1797->field17));
  *(&llvm_cbe_cppVar_2074) = (((unsigned char )(bool )(llvm_cbe_tmp__1803 == 4ull)));
  llvm_cbe_tmp__1804 = *(&llvm_cbe_cppVar_2071);
  if ((((((bool )llvm_cbe_tmp__1804&1u))&1))) {
    goto llvm_cbe_tmp__1869;
  } else {
    llvm_cbe_tmp__1807__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1870;
  }

llvm_cbe_tmp__1869:
  llvm_cbe_tmp__1805 = *(&llvm_cbe_cppVar_2074);
  llvm_cbe_tmp__1806 = ((((bool )llvm_cbe_tmp__1805&1u))&1);
  llvm_cbe_tmp__1807__PHI_TEMPORARY = llvm_cbe_tmp__1806;   /* for PHI node */
  goto llvm_cbe_tmp__1870;

llvm_cbe_tmp__1870:
  llvm_cbe_tmp__1807 = ((llvm_cbe_tmp__1807__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_2075) = (((unsigned char )(bool )llvm_cbe_tmp__1807));
  llvm_cbe_tmp__1808 = *(&llvm_cbe_cppVar_2075);
  if ((((((bool )llvm_cbe_tmp__1808&1u))&1))) {
    goto llvm_cbe_tmp__1871;
  } else {
    goto llvm_cbe_tmp__1872;
  }

llvm_cbe_tmp__1871:
  llvm_cbe_tmp__1809 = *((&llvm_cbe_tmp__1797->field25));
  *(&llvm_cbe_cppVar_2078) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1809) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1810 = *(&llvm_cbe_cppVar_2078);
  llvm_cbe_tmp__1811 = *((&llvm_cbe_tmp__1797->field41));
  *(&llvm_cbe_cppVar_2078) = (llvm_cbe_tmp__1810 & llvm_cbe_tmp__1811);
  llvm_cbe_tmp__1812 = *(&llvm_cbe_cppVar_2078);
  llvm_cbe_tmp__1813 = *((&llvm_cbe_tmp__1797->field16));
  *(&llvm_cbe_cppVar_2079) = (((unsigned char )(bool )(llvm_cbe_tmp__1812 == llvm_cbe_tmp__1813)));
  llvm_cbe_tmp__1814 = *((&llvm_cbe_tmp__1797->field25));
  *(&llvm_cbe_cppVar_2081) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1814) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1815 = *(&llvm_cbe_cppVar_2081);
  llvm_cbe_tmp__1816 = *((&llvm_cbe_tmp__1797->field41));
  *(&llvm_cbe_cppVar_2081) = (llvm_cbe_tmp__1815 & llvm_cbe_tmp__1816);
  llvm_cbe_tmp__1817 = *(&llvm_cbe_cppVar_2081);
  *(&llvm_cbe_cppVar_2083) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__1817) >= ((signed long long )500ull))));
  llvm_cbe_tmp__1818 = *(&llvm_cbe_cppVar_2079);
  if ((((((bool )llvm_cbe_tmp__1818&1u))&1))) {
    llvm_cbe_tmp__1821__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__1873;
  } else {
    goto llvm_cbe_tmp__1874;
  }

llvm_cbe_tmp__1874:
  llvm_cbe_tmp__1819 = *(&llvm_cbe_cppVar_2083);
  llvm_cbe_tmp__1820 = ((((bool )llvm_cbe_tmp__1819&1u))&1);
  llvm_cbe_tmp__1821__PHI_TEMPORARY = llvm_cbe_tmp__1820;   /* for PHI node */
  goto llvm_cbe_tmp__1873;

llvm_cbe_tmp__1873:
  llvm_cbe_tmp__1821 = ((llvm_cbe_tmp__1821__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_2084) = (((unsigned char )(bool )llvm_cbe_tmp__1821));
  llvm_cbe_tmp__1822 = *(&llvm_cbe_cppVar_2075);
  if ((((((bool )llvm_cbe_tmp__1822&1u))&1))) {
    goto llvm_cbe_tmp__1875;
  } else {
    llvm_cbe_tmp__1825__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1876;
  }

llvm_cbe_tmp__1875:
  llvm_cbe_tmp__1823 = *(&llvm_cbe_cppVar_2084);
  llvm_cbe_tmp__1824 = ((((bool )llvm_cbe_tmp__1823&1u))&1);
  llvm_cbe_tmp__1825__PHI_TEMPORARY = llvm_cbe_tmp__1824;   /* for PHI node */
  goto llvm_cbe_tmp__1876;

llvm_cbe_tmp__1876:
  llvm_cbe_tmp__1825 = ((llvm_cbe_tmp__1825__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_2085) = (((unsigned char )(bool )llvm_cbe_tmp__1825));
  llvm_cbe_tmp__1826 = *((&llvm_cbe_tmp__1797->field9));
  *(&llvm_cbe_cppVar_2087) = (((unsigned char )(bool )(llvm_cbe_tmp__1826 == 4ull)));
  llvm_cbe_tmp__1827 = *(&llvm_cbe_cppVar_2085);
  if ((((((bool )llvm_cbe_tmp__1827&1u))&1))) {
    goto llvm_cbe_tmp__1877;
  } else {
    llvm_cbe_tmp__1830__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1878;
  }

llvm_cbe_tmp__1877:
  llvm_cbe_tmp__1828 = *(&llvm_cbe_cppVar_2087);
  llvm_cbe_tmp__1829 = ((((bool )llvm_cbe_tmp__1828&1u))&1);
  llvm_cbe_tmp__1830__PHI_TEMPORARY = llvm_cbe_tmp__1829;   /* for PHI node */
  goto llvm_cbe_tmp__1878;

llvm_cbe_tmp__1878:
  llvm_cbe_tmp__1830 = ((llvm_cbe_tmp__1830__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_2088) = (((unsigned char )(bool )llvm_cbe_tmp__1830));
  llvm_cbe_tmp__1831 = *(&llvm_cbe_cppVar_2088);
  if ((((((bool )llvm_cbe_tmp__1831&1u))&1))) {
    goto llvm_cbe_tmp__1879;
  } else {
    goto llvm_cbe_tmp__1880;
  }

llvm_cbe_tmp__1879:
  llvm_cbe_tmp__1832 = *((&llvm_cbe_tmp__1797->field25));
  llvm_cbe_tmp__1833 = *((&llvm_cbe_tmp__1797->field9));
  *(&llvm_cbe_cppVar_2089) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1832) + ((unsigned long long )llvm_cbe_tmp__1833))));
  llvm_cbe_tmp__1834 = *(&llvm_cbe_cppVar_2089);
  llvm_cbe_tmp__1835 = *((&llvm_cbe_tmp__1797->field41));
  *(&llvm_cbe_cppVar_2089) = (llvm_cbe_tmp__1834 & llvm_cbe_tmp__1835);
  llvm_cbe_tmp__1836 = *(&llvm_cbe_cppVar_2089);
  llvm_cbe_tmp__1837 = *((&llvm_cbe_tmp__1797->field51));
  *(&llvm_cbe_cppVar_2090) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1836) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1837);
  llvm_cbe_tmp__1838 = *((&llvm_cbe_tmp__1797->field5));
  llvm_cbe_tmp__1839 = _Z5roundl(llvm_cbe_tmp__1838);
  *(&llvm_cbe_cppVar_2092) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__1839));
  llvm_cbe_tmp__1840 = *(&llvm_cbe_cppVar_2092);
  llvm_cbe_tmp__1841 = *((&llvm_cbe_tmp__1797->field49));
  *(&llvm_cbe_cppVar_2093) = (llvm_cbe_tmp__1840 & llvm_cbe_tmp__1841);
  llvm_cbe_tmp__1842 = *((&llvm_cbe_tmp__1797->field9));
  llvm_cbe_tmp__1843 = *(&llvm_cbe_cppVar_2093);
  *(&llvm_cbe_cppVar_2094) = (((unsigned char )(bool )(llvm_cbe_tmp__1842 == llvm_cbe_tmp__1843)));
  llvm_cbe_tmp__1844 = *(&llvm_cbe_cppVar_2094);
  if ((((((bool )llvm_cbe_tmp__1844&1u))&1))) {
    goto llvm_cbe_tmp__1881;
  } else {
    goto llvm_cbe_tmp__1882;
  }

llvm_cbe_tmp__1881:
  *(&llvm_cbe_cppVar_2091) = 1ull;
  goto llvm_cbe_tmp__1883;

llvm_cbe_tmp__1882:
  *(&llvm_cbe_cppVar_2091) = 0ull;
  goto llvm_cbe_tmp__1883;

llvm_cbe_tmp__1883:
  llvm_cbe_tmp__1845 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_2097), ((&llvm_cbe_tmp__1797->field26)));
  llvm_cbe_tmp__1846 = *(&llvm_cbe_cppVar_2090);
  llvm_cbe_tmp__1847 = *(&llvm_cbe_cppVar_2091);
  _ZN8type_memIbLj512EE2wrEll((&llvm_cbe_cppVar_2097), llvm_cbe_tmp__1846, llvm_cbe_tmp__1847);
  llvm_cbe_tmp__1848 = *((&llvm_cbe_tmp__1797->field16));
  llvm_cbe_tmp__1849 = *((&llvm_cbe_tmp__1797->field51));
  *(&llvm_cbe_cppVar_2098) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1848) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1849);
  llvm_cbe_tmp__1850 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_2099), (&llvm_cbe_cppVar_2097));
  llvm_cbe_tmp__1851 = *(&llvm_cbe_cppVar_2098);
  _ZN8type_memIbLj512EE2wrEll((&llvm_cbe_cppVar_2099), llvm_cbe_tmp__1851, 1ull);
  llvm_cbe_tmp__1852 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_2076), (&llvm_cbe_cppVar_2099));
  goto llvm_cbe_tmp__1884;

llvm_cbe_tmp__1880:
  llvm_cbe_tmp__1853 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_2076), (&llvm_cbe_cppVar_2097));
  goto llvm_cbe_tmp__1884;

llvm_cbe_tmp__1884:
  llvm_cbe_tmp__1854 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_2072), (&llvm_cbe_cppVar_2076));
  goto llvm_cbe_tmp__1885;

llvm_cbe_tmp__1872:
  llvm_cbe_tmp__1855 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_2072), ((&llvm_cbe_tmp__1797->field26)));
  goto llvm_cbe_tmp__1885;

llvm_cbe_tmp__1885:
  llvm_cbe_tmp__1856 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_2069), (&llvm_cbe_cppVar_2072));
  goto llvm_cbe_tmp__1886;

llvm_cbe_tmp__1868:
  llvm_cbe_tmp__1857 = *((&llvm_cbe_tmp__1797->field24));
  *(&llvm_cbe_cppVar_2102) = (((unsigned char )(bool )(llvm_cbe_tmp__1857 == 2ull)));
  llvm_cbe_tmp__1858 = *(&llvm_cbe_cppVar_2102);
  llvm_cbe_tmp__1859 = ((((bool )llvm_cbe_tmp__1858&1u))&1);
  llvm_cbe_tmp__1860 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_2100), ((&llvm_cbe_tmp__1797->field26)));
  llvm_cbe_tmp__1861 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_2069), (&llvm_cbe_cppVar_2100));
  goto llvm_cbe_tmp__1886;

llvm_cbe_tmp__1886:
  llvm_cbe_tmp__1862 = _ZN8type_memIbLj512EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_2069));
  goto llvm_cbe_tmp__1866;

llvm_cbe_tmp__1866:
  *(&llvm_cbe_tmp__1795) = ((1) & 1);
  *(&llvm_cbe_tmp__1796) = 1u;
  llvm_cbe_tmp__1863 = ((*(&llvm_cbe_tmp__1795))&1);
  if (llvm_cbe_tmp__1863) {
    goto llvm_cbe_tmp__1887;
  } else {
    goto llvm_cbe_tmp__1888;
  }

llvm_cbe_tmp__1888:
  _ZN8type_memIbLj512EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__1887;

llvm_cbe_tmp__1887:
  _ZN8type_memIbLj512EED1Ev((&llvm_cbe_cppVar_2069));
  _ZN8type_memIbLj512EED1Ev((&llvm_cbe_cppVar_2100));
  _ZN8type_memIbLj512EED1Ev((&llvm_cbe_cppVar_2072));
  _ZN8type_memIbLj512EED1Ev((&llvm_cbe_cppVar_2076));
  _ZN8type_memIbLj512EED1Ev((&llvm_cbe_cppVar_2099));
  _ZN8type_memIbLj512EED1Ev((&llvm_cbe_cppVar_2097));
  return StructReturn;
}


void _ZN8type_memIbLj512EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1889;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1890;

  *(&llvm_cbe_tmp__1889) = llvm_cbe_this;
  llvm_cbe_tmp__1890 = *(&llvm_cbe_tmp__1889);
  _ZN8type_memIbLj512EEC2Ev(llvm_cbe_tmp__1890);
  return;
}


struct l_class_OC_SysCArray1D *_ZN8type_memIbLj512EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1891;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1892;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1893;
  unsigned char *llvm_cbe_tmp__1894;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1895;
  unsigned char *llvm_cbe_tmp__1896;

  *(&llvm_cbe_tmp__1891) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1892) = llvm_cbe_r;
  llvm_cbe_tmp__1893 = *(&llvm_cbe_tmp__1891);
  llvm_cbe_tmp__1894 = *((&llvm_cbe_tmp__1893->field0));
  llvm_cbe_tmp__1895 = *(&llvm_cbe_tmp__1892);
  llvm_cbe_tmp__1896 = *((&llvm_cbe_tmp__1895->field0));
  __CPROVER_array_copy(llvm_cbe_tmp__1894, llvm_cbe_tmp__1896);
  return llvm_cbe_tmp__1893;
}


void _ZN8type_memIbLj512EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1897;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1898;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1899;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1900;
  unsigned long long llvm_cbe_tmp__1901;
  unsigned long long llvm_cbe_tmp__1902;
  unsigned char *llvm_cbe_tmp__1903;

  *(&llvm_cbe_tmp__1897) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1898) = llvm_cbe_addr;
  *(&llvm_cbe_tmp__1899) = llvm_cbe_data;
  llvm_cbe_tmp__1900 = *(&llvm_cbe_tmp__1897);
  llvm_cbe_tmp__1901 = *(&llvm_cbe_tmp__1899);
  llvm_cbe_tmp__1902 = *(&llvm_cbe_tmp__1898);
  llvm_cbe_tmp__1903 = *((&llvm_cbe_tmp__1900->field0));
  *((&llvm_cbe_tmp__1903[((signed long long )llvm_cbe_tmp__1902)])) = (((unsigned char )(bool )(llvm_cbe_tmp__1901 != 0ull)));
  return;
}


void _ZN8type_memIbLj512EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1904;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1905;

  *(&llvm_cbe_tmp__1904) = llvm_cbe_this;
  llvm_cbe_tmp__1905 = *(&llvm_cbe_tmp__1904);
  _ZN8type_memIbLj512EED2Ev(llvm_cbe_tmp__1905);
  return;
}


unsigned long long _ZN13model_predict23cppUpdateFun_predictionElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__1906;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1907;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1908;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1909;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1910;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1911;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1912;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1913;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1914;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1915;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1916;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1917;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1787;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1773;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1774;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1785;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1786;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1784;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1776;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1777;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1778;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1779;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1780;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1781;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1782;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1783;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1775;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1772;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__1918;
  unsigned long long llvm_cbe_tmp__1919;
  unsigned char llvm_cbe_tmp__1920;
  unsigned long long llvm_cbe_tmp__1921;
  unsigned long long llvm_cbe_tmp__1922;
  unsigned long long llvm_cbe_tmp__1923;
  unsigned long long llvm_cbe_tmp__1924;
  unsigned long long llvm_cbe_tmp__1925;
  unsigned long long llvm_cbe_tmp__1926;
  unsigned long long llvm_cbe_tmp__1927;
  unsigned long long llvm_cbe_tmp__1928;
  unsigned long long llvm_cbe_tmp__1929;
  unsigned char llvm_cbe_tmp__1930;
  unsigned long long llvm_cbe_tmp__1931;
  unsigned long long llvm_cbe_tmp__1932;
  unsigned long long llvm_cbe_tmp__1933;
  unsigned long long llvm_cbe_tmp__1934;
  unsigned long long llvm_cbe_tmp__1935;
  unsigned long long llvm_cbe_tmp__1936;
  unsigned char llvm_cbe_tmp__1937;
  unsigned long long llvm_cbe_tmp__1938;
  unsigned long long llvm_cbe_tmp__1939;
  unsigned long long llvm_cbe_tmp__1940;
  unsigned long long llvm_cbe_tmp__1941;
  unsigned long long llvm_cbe_tmp__1942;

  *(&llvm_cbe_tmp__1906) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1907) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1908) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1909) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1910) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1911) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1912) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1913) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1914) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1915) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1916) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1917) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1918 = *(&llvm_cbe_tmp__1906);
  llvm_cbe_tmp__1919 = *((&llvm_cbe_tmp__1918->field24));
  *(&llvm_cbe_cppVar_1774) = (((unsigned char )(bool )(llvm_cbe_tmp__1919 == 3ull)));
  llvm_cbe_tmp__1920 = *(&llvm_cbe_cppVar_1774);
  if ((((((bool )llvm_cbe_tmp__1920&1u))&1))) {
    goto llvm_cbe_tmp__1943;
  } else {
    goto llvm_cbe_tmp__1944;
  }

llvm_cbe_tmp__1943:
  llvm_cbe_tmp__1921 = *((&llvm_cbe_tmp__1918->field25));
  llvm_cbe_tmp__1922 = *((&llvm_cbe_tmp__1918->field9));
  *(&llvm_cbe_cppVar_1776) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1921) + ((unsigned long long )llvm_cbe_tmp__1922))));
  llvm_cbe_tmp__1923 = *(&llvm_cbe_cppVar_1776);
  llvm_cbe_tmp__1924 = *((&llvm_cbe_tmp__1918->field41));
  *(&llvm_cbe_cppVar_1776) = (llvm_cbe_tmp__1923 & llvm_cbe_tmp__1924);
  llvm_cbe_tmp__1925 = *(&llvm_cbe_cppVar_1776);
  llvm_cbe_tmp__1926 = *((&llvm_cbe_tmp__1918->field51));
  *(&llvm_cbe_cppVar_1777) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1925) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1926);
  llvm_cbe_tmp__1927 = *(&llvm_cbe_cppVar_1777);
  llvm_cbe_tmp__1928 = _ZN8type_memIbLj512EE2rdEl(((&llvm_cbe_tmp__1918->field26)), llvm_cbe_tmp__1927);
  *(&llvm_cbe_cppVar_1778) = llvm_cbe_tmp__1928;
  llvm_cbe_tmp__1929 = *(&llvm_cbe_cppVar_1778);
  *(&llvm_cbe_cppVar_1780) = (((unsigned char )(bool )(llvm_cbe_tmp__1929 == 1ull)));
  llvm_cbe_tmp__1930 = *(&llvm_cbe_cppVar_1780);
  llvm_cbe_tmp__1931 = *((&llvm_cbe_tmp__1918->field9));
  if ((((((bool )llvm_cbe_tmp__1930&1u))&1))) {
    goto llvm_cbe_tmp__1945;
  } else {
    goto llvm_cbe_tmp__1946;
  }

llvm_cbe_tmp__1945:
  *(&llvm_cbe_cppVar_1782) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1931) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__1932 = *(&llvm_cbe_cppVar_1782);
  llvm_cbe_tmp__1933 = *((&llvm_cbe_tmp__1918->field41));
  *(&llvm_cbe_cppVar_1782) = (llvm_cbe_tmp__1932 & llvm_cbe_tmp__1933);
  llvm_cbe_tmp__1934 = *(&llvm_cbe_cppVar_1782);
  llvm_cbe_tmp__1935 = *((&llvm_cbe_tmp__1918->field49));
  *(&llvm_cbe_cppVar_1783) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1934) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1935);
  llvm_cbe_tmp__1936 = *(&llvm_cbe_cppVar_1783);
  *(&llvm_cbe_cppVar_1775) = llvm_cbe_tmp__1936;
  goto llvm_cbe_tmp__1947;

llvm_cbe_tmp__1946:
  *(&llvm_cbe_cppVar_1786) = (((unsigned char )(bool )(llvm_cbe_tmp__1931 == 0ull)));
  llvm_cbe_tmp__1937 = *(&llvm_cbe_cppVar_1786);
  if ((((((bool )llvm_cbe_tmp__1937&1u))&1))) {
    goto llvm_cbe_tmp__1948;
  } else {
    goto llvm_cbe_tmp__1949;
  }

llvm_cbe_tmp__1948:
  *(&llvm_cbe_cppVar_1784) = 0ull;
  goto llvm_cbe_tmp__1950;

llvm_cbe_tmp__1949:
  llvm_cbe_tmp__1938 = *((&llvm_cbe_tmp__1918->field27));
  *(&llvm_cbe_cppVar_1784) = llvm_cbe_tmp__1938;
  goto llvm_cbe_tmp__1950;

llvm_cbe_tmp__1950:
  llvm_cbe_tmp__1939 = *(&llvm_cbe_cppVar_1784);
  *(&llvm_cbe_cppVar_1775) = llvm_cbe_tmp__1939;
  goto llvm_cbe_tmp__1947;

llvm_cbe_tmp__1947:
  llvm_cbe_tmp__1940 = *(&llvm_cbe_cppVar_1775);
  *(&llvm_cbe_cppVar_1772) = llvm_cbe_tmp__1940;
  goto llvm_cbe_tmp__1951;

llvm_cbe_tmp__1944:
  llvm_cbe_tmp__1941 = *((&llvm_cbe_tmp__1918->field27));
  *(&llvm_cbe_cppVar_1772) = llvm_cbe_tmp__1941;
  goto llvm_cbe_tmp__1951;

llvm_cbe_tmp__1951:
  llvm_cbe_tmp__1942 = *(&llvm_cbe_cppVar_1772);
  return llvm_cbe_tmp__1942;
}


unsigned long long _ZN8type_memIbLj512EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1952;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1953;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1954;
  unsigned long long llvm_cbe_tmp__1955;
  unsigned char *llvm_cbe_tmp__1956;
  unsigned char llvm_cbe_tmp__1957;

  *(&llvm_cbe_tmp__1952) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1953) = llvm_cbe_addr;
  llvm_cbe_tmp__1954 = *(&llvm_cbe_tmp__1952);
  llvm_cbe_tmp__1955 = *(&llvm_cbe_tmp__1953);
  llvm_cbe_tmp__1956 = *((&llvm_cbe_tmp__1954->field0));
  llvm_cbe_tmp__1957 = *((&llvm_cbe_tmp__1956[((signed long long )llvm_cbe_tmp__1955)]));
  return (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__1957&1u))&1))));
}


unsigned long long _ZN13model_predict22cppUpdateFun_sumOfpow2Elllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__1958;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1959;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1960;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1961;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1962;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1963;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1964;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1965;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1966;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1967;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1968;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1969;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1790;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1791;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1793;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1794;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1826;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1827;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1810;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1796;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1797;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1798;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1800;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1801;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1802;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1804;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1805;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1806;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1818;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1819;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1820;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1822;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1823;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1824;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1811;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1812;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1813;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1814;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1815;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1808;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1809;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1807;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1816;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1821;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1817;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1803;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1799;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1795;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1825;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1792;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1789;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__1970;
  unsigned long long llvm_cbe_tmp__1971;
  unsigned char llvm_cbe_tmp__1972;
  unsigned long long llvm_cbe_tmp__1973;
  unsigned long long llvm_cbe_tmp__1974;
  unsigned char llvm_cbe_tmp__1975;
  unsigned long long llvm_cbe_tmp__1976;
  unsigned char llvm_cbe_tmp__1977;
  unsigned char llvm_cbe_tmp__1978;
  bool llvm_cbe_tmp__1979;
  bool llvm_cbe_tmp__1980;
  bool llvm_cbe_tmp__1980__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1981;
  unsigned long long llvm_cbe_tmp__1982;
  unsigned long long llvm_cbe_tmp__1983;
  unsigned char llvm_cbe_tmp__1984;
  unsigned char llvm_cbe_tmp__1985;
  bool llvm_cbe_tmp__1986;
  bool llvm_cbe_tmp__1987;
  bool llvm_cbe_tmp__1987__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1988;
  unsigned long long llvm_cbe_tmp__1989;
  unsigned long long llvm_cbe_tmp__1990;
  unsigned char llvm_cbe_tmp__1991;
  unsigned char llvm_cbe_tmp__1992;
  bool llvm_cbe_tmp__1993;
  bool llvm_cbe_tmp__1994;
  bool llvm_cbe_tmp__1994__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1995;
  unsigned long long llvm_cbe_tmp__1996;
  unsigned char llvm_cbe_tmp__1997;
  unsigned long long llvm_cbe_tmp__1998;
  unsigned long long llvm_cbe_tmp__1999;
  unsigned long long llvm_cbe_tmp__2000;
  unsigned long long llvm_cbe_tmp__2001;
  unsigned long long llvm_cbe_tmp__2002;
  unsigned long long llvm_cbe_tmp__2003;
  unsigned short llvm_cbe_tmp__2004;
  unsigned long long llvm_cbe_tmp__2005;
  unsigned long long llvm_cbe_tmp__2006;
  unsigned long long llvm_cbe_tmp__2007;
  unsigned long long llvm_cbe_tmp__2008;
  unsigned long long llvm_cbe_tmp__2009;
  unsigned long long llvm_cbe_tmp__2010;
  unsigned long long llvm_cbe_tmp__2011;
  unsigned long long llvm_cbe_tmp__2012;
  unsigned long long llvm_cbe_tmp__2013;
  unsigned long long llvm_cbe_tmp__2014;
  unsigned char llvm_cbe_tmp__2015;
  unsigned char llvm_cbe_tmp__2016;
  bool llvm_cbe_tmp__2017;
  bool llvm_cbe_tmp__2018;
  bool llvm_cbe_tmp__2018__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2019;
  unsigned long long llvm_cbe_tmp__2020;
  unsigned long long llvm_cbe_tmp__2021;
  unsigned char llvm_cbe_tmp__2022;
  unsigned char llvm_cbe_tmp__2023;
  bool llvm_cbe_tmp__2024;
  bool llvm_cbe_tmp__2025;
  bool llvm_cbe_tmp__2025__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__2026;
  unsigned long long llvm_cbe_tmp__2027;
  unsigned long long llvm_cbe_tmp__2028;
  unsigned long long llvm_cbe_tmp__2029;
  unsigned long long llvm_cbe_tmp__2030;
  unsigned long long llvm_cbe_tmp__2031;
  unsigned long long llvm_cbe_tmp__2032;
  unsigned long long llvm_cbe_tmp__2033;
  unsigned long long llvm_cbe_tmp__2034;
  unsigned long long llvm_cbe_tmp__2035;
  unsigned long long llvm_cbe_tmp__2036;

  *(&llvm_cbe_tmp__1958) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1959) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1960) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1961) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1962) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1963) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1964) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1965) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1966) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1967) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1968) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1969) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1970 = *(&llvm_cbe_tmp__1958);
  llvm_cbe_tmp__1971 = *((&llvm_cbe_tmp__1970->field24));
  *(&llvm_cbe_cppVar_1791) = (((unsigned char )(bool )(llvm_cbe_tmp__1971 == 0ull)));
  llvm_cbe_tmp__1972 = *(&llvm_cbe_cppVar_1791);
  if ((((((bool )llvm_cbe_tmp__1972&1u))&1))) {
    goto llvm_cbe_tmp__2037;
  } else {
    goto llvm_cbe_tmp__2038;
  }

llvm_cbe_tmp__2037:
  llvm_cbe_tmp__1973 = *((&llvm_cbe_tmp__1970->field32));
  *(&llvm_cbe_cppVar_1789) = llvm_cbe_tmp__1973;
  goto llvm_cbe_tmp__2039;

llvm_cbe_tmp__2038:
  llvm_cbe_tmp__1974 = *((&llvm_cbe_tmp__1970->field24));
  *(&llvm_cbe_cppVar_1794) = (((unsigned char )(bool )(llvm_cbe_tmp__1974 == 1ull)));
  llvm_cbe_tmp__1975 = *(&llvm_cbe_cppVar_1794);
  if ((((((bool )llvm_cbe_tmp__1975&1u))&1))) {
    goto llvm_cbe_tmp__2040;
  } else {
    goto llvm_cbe_tmp__2041;
  }

llvm_cbe_tmp__2040:
  llvm_cbe_tmp__1976 = *((&llvm_cbe_tmp__1970->field17));
  *(&llvm_cbe_cppVar_1797) = (((unsigned char )(bool )(llvm_cbe_tmp__1976 == 0ull)));
  llvm_cbe_tmp__1977 = *(&llvm_cbe_cppVar_1794);
  if ((((((bool )llvm_cbe_tmp__1977&1u))&1))) {
    goto llvm_cbe_tmp__2042;
  } else {
    llvm_cbe_tmp__1980__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2043;
  }

llvm_cbe_tmp__2042:
  llvm_cbe_tmp__1978 = *(&llvm_cbe_cppVar_1797);
  llvm_cbe_tmp__1979 = ((((bool )llvm_cbe_tmp__1978&1u))&1);
  llvm_cbe_tmp__1980__PHI_TEMPORARY = llvm_cbe_tmp__1979;   /* for PHI node */
  goto llvm_cbe_tmp__2043;

llvm_cbe_tmp__2043:
  llvm_cbe_tmp__1980 = ((llvm_cbe_tmp__1980__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1798) = (((unsigned char )(bool )llvm_cbe_tmp__1980));
  llvm_cbe_tmp__1981 = *(&llvm_cbe_cppVar_1798);
  if ((((((bool )llvm_cbe_tmp__1981&1u))&1))) {
    goto llvm_cbe_tmp__2044;
  } else {
    goto llvm_cbe_tmp__2045;
  }

llvm_cbe_tmp__2044:
  llvm_cbe_tmp__1982 = *((&llvm_cbe_tmp__1970->field32));
  *(&llvm_cbe_cppVar_1795) = llvm_cbe_tmp__1982;
  goto llvm_cbe_tmp__2046;

llvm_cbe_tmp__2045:
  llvm_cbe_tmp__1983 = *((&llvm_cbe_tmp__1970->field17));
  *(&llvm_cbe_cppVar_1801) = (((unsigned char )(bool )(llvm_cbe_tmp__1983 == 1ull)));
  llvm_cbe_tmp__1984 = *(&llvm_cbe_cppVar_1794);
  if ((((((bool )llvm_cbe_tmp__1984&1u))&1))) {
    goto llvm_cbe_tmp__2047;
  } else {
    llvm_cbe_tmp__1987__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2048;
  }

llvm_cbe_tmp__2047:
  llvm_cbe_tmp__1985 = *(&llvm_cbe_cppVar_1801);
  llvm_cbe_tmp__1986 = ((((bool )llvm_cbe_tmp__1985&1u))&1);
  llvm_cbe_tmp__1987__PHI_TEMPORARY = llvm_cbe_tmp__1986;   /* for PHI node */
  goto llvm_cbe_tmp__2048;

llvm_cbe_tmp__2048:
  llvm_cbe_tmp__1987 = ((llvm_cbe_tmp__1987__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1802) = (((unsigned char )(bool )llvm_cbe_tmp__1987));
  llvm_cbe_tmp__1988 = *(&llvm_cbe_cppVar_1802);
  if ((((((bool )llvm_cbe_tmp__1988&1u))&1))) {
    goto llvm_cbe_tmp__2049;
  } else {
    goto llvm_cbe_tmp__2050;
  }

llvm_cbe_tmp__2049:
  llvm_cbe_tmp__1989 = *((&llvm_cbe_tmp__1970->field32));
  *(&llvm_cbe_cppVar_1799) = llvm_cbe_tmp__1989;
  goto llvm_cbe_tmp__2051;

llvm_cbe_tmp__2050:
  llvm_cbe_tmp__1990 = *((&llvm_cbe_tmp__1970->field17));
  *(&llvm_cbe_cppVar_1805) = (((unsigned char )(bool )(llvm_cbe_tmp__1990 == 2ull)));
  llvm_cbe_tmp__1991 = *(&llvm_cbe_cppVar_1794);
  if ((((((bool )llvm_cbe_tmp__1991&1u))&1))) {
    goto llvm_cbe_tmp__2052;
  } else {
    llvm_cbe_tmp__1994__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2053;
  }

llvm_cbe_tmp__2052:
  llvm_cbe_tmp__1992 = *(&llvm_cbe_cppVar_1805);
  llvm_cbe_tmp__1993 = ((((bool )llvm_cbe_tmp__1992&1u))&1);
  llvm_cbe_tmp__1994__PHI_TEMPORARY = llvm_cbe_tmp__1993;   /* for PHI node */
  goto llvm_cbe_tmp__2053;

llvm_cbe_tmp__2053:
  llvm_cbe_tmp__1994 = ((llvm_cbe_tmp__1994__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1806) = (((unsigned char )(bool )llvm_cbe_tmp__1994));
  llvm_cbe_tmp__1995 = *(&llvm_cbe_cppVar_1806);
  if ((((((bool )llvm_cbe_tmp__1995&1u))&1))) {
    goto llvm_cbe_tmp__2054;
  } else {
    goto llvm_cbe_tmp__2055;
  }

llvm_cbe_tmp__2054:
  llvm_cbe_tmp__1996 = *((&llvm_cbe_tmp__1970->field9));
  *(&llvm_cbe_cppVar_1809) = (((unsigned char )(bool )(llvm_cbe_tmp__1996 == 0ull)));
  llvm_cbe_tmp__1997 = *(&llvm_cbe_cppVar_1809);
  if ((((((bool )llvm_cbe_tmp__1997&1u))&1))) {
    goto llvm_cbe_tmp__2056;
  } else {
    goto llvm_cbe_tmp__2057;
  }

llvm_cbe_tmp__2056:
  *(&llvm_cbe_cppVar_1807) = 0ull;
  goto llvm_cbe_tmp__2058;

llvm_cbe_tmp__2057:
  llvm_cbe_tmp__1998 = *((&llvm_cbe_tmp__1970->field32));
  *(&llvm_cbe_cppVar_1807) = llvm_cbe_tmp__1998;
  goto llvm_cbe_tmp__2058;

llvm_cbe_tmp__2058:
  llvm_cbe_tmp__1999 = *((&llvm_cbe_tmp__1970->field9));
  llvm_cbe_tmp__2000 = *((&llvm_cbe_tmp__1970->field44));
  *(&llvm_cbe_cppVar_1811) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1999) >> ((signed long long )0ull)))) & llvm_cbe_tmp__2000);
  llvm_cbe_tmp__2001 = *(&llvm_cbe_cppVar_1811);
  llvm_cbe_tmp__2002 = _ZN8type_memItLj8EE2rdEl(((&llvm_cbe_tmp__1970->field35)), llvm_cbe_tmp__2001);
  *(&llvm_cbe_cppVar_1812) = llvm_cbe_tmp__2002;
  llvm_cbe_tmp__2003 = *(&llvm_cbe_cppVar_1812);
  llvm_cbe_tmp__2004 = _Z10to_int_expl(llvm_cbe_tmp__2003);
  *(&llvm_cbe_cppVar_1813) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__2004));
  llvm_cbe_tmp__2005 = *(&llvm_cbe_cppVar_1813);
  llvm_cbe_tmp__2006 = *((&llvm_cbe_tmp__1970->field45));
  *(&llvm_cbe_cppVar_1814) = ((((signed long long )(((signed long long )llvm_cbe_tmp__2005) >> ((signed long long )0ull)))) & llvm_cbe_tmp__2006);
  llvm_cbe_tmp__2007 = *(&llvm_cbe_cppVar_1814);
  llvm_cbe_tmp__2008 = *((&llvm_cbe_tmp__1970->field45));
  *(&llvm_cbe_cppVar_1815) = (llvm_cbe_tmp__2007 & llvm_cbe_tmp__2008);
  llvm_cbe_tmp__2009 = *(&llvm_cbe_cppVar_1807);
  llvm_cbe_tmp__2010 = *(&llvm_cbe_cppVar_1815);
  *(&llvm_cbe_cppVar_1816) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2009) + ((unsigned long long )llvm_cbe_tmp__2010))));
  llvm_cbe_tmp__2011 = *(&llvm_cbe_cppVar_1816);
  llvm_cbe_tmp__2012 = *((&llvm_cbe_tmp__1970->field47));
  *(&llvm_cbe_cppVar_1816) = (llvm_cbe_tmp__2011 & llvm_cbe_tmp__2012);
  llvm_cbe_tmp__2013 = *(&llvm_cbe_cppVar_1816);
  *(&llvm_cbe_cppVar_1803) = llvm_cbe_tmp__2013;
  goto llvm_cbe_tmp__2059;

llvm_cbe_tmp__2055:
  llvm_cbe_tmp__2014 = *((&llvm_cbe_tmp__1970->field17));
  *(&llvm_cbe_cppVar_1819) = (((unsigned char )(bool )(llvm_cbe_tmp__2014 == 3ull)));
  llvm_cbe_tmp__2015 = *(&llvm_cbe_cppVar_1794);
  if ((((((bool )llvm_cbe_tmp__2015&1u))&1))) {
    goto llvm_cbe_tmp__2060;
  } else {
    llvm_cbe_tmp__2018__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2061;
  }

llvm_cbe_tmp__2060:
  llvm_cbe_tmp__2016 = *(&llvm_cbe_cppVar_1819);
  llvm_cbe_tmp__2017 = ((((bool )llvm_cbe_tmp__2016&1u))&1);
  llvm_cbe_tmp__2018__PHI_TEMPORARY = llvm_cbe_tmp__2017;   /* for PHI node */
  goto llvm_cbe_tmp__2061;

llvm_cbe_tmp__2061:
  llvm_cbe_tmp__2018 = ((llvm_cbe_tmp__2018__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1820) = (((unsigned char )(bool )llvm_cbe_tmp__2018));
  llvm_cbe_tmp__2019 = *(&llvm_cbe_cppVar_1820);
  if ((((((bool )llvm_cbe_tmp__2019&1u))&1))) {
    goto llvm_cbe_tmp__2062;
  } else {
    goto llvm_cbe_tmp__2063;
  }

llvm_cbe_tmp__2062:
  llvm_cbe_tmp__2020 = *((&llvm_cbe_tmp__1970->field32));
  *(&llvm_cbe_cppVar_1817) = llvm_cbe_tmp__2020;
  goto llvm_cbe_tmp__2064;

llvm_cbe_tmp__2063:
  llvm_cbe_tmp__2021 = *((&llvm_cbe_tmp__1970->field17));
  *(&llvm_cbe_cppVar_1823) = (((unsigned char )(bool )(llvm_cbe_tmp__2021 == 4ull)));
  llvm_cbe_tmp__2022 = *(&llvm_cbe_cppVar_1794);
  if ((((((bool )llvm_cbe_tmp__2022&1u))&1))) {
    goto llvm_cbe_tmp__2065;
  } else {
    llvm_cbe_tmp__2025__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2066;
  }

llvm_cbe_tmp__2065:
  llvm_cbe_tmp__2023 = *(&llvm_cbe_cppVar_1823);
  llvm_cbe_tmp__2024 = ((((bool )llvm_cbe_tmp__2023&1u))&1);
  llvm_cbe_tmp__2025__PHI_TEMPORARY = llvm_cbe_tmp__2024;   /* for PHI node */
  goto llvm_cbe_tmp__2066;

llvm_cbe_tmp__2066:
  llvm_cbe_tmp__2025 = ((llvm_cbe_tmp__2025__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1824) = (((unsigned char )(bool )llvm_cbe_tmp__2025));
  llvm_cbe_tmp__2026 = *((&llvm_cbe_tmp__1970->field32));
  *(&llvm_cbe_cppVar_1821) = llvm_cbe_tmp__2026;
  llvm_cbe_tmp__2027 = *(&llvm_cbe_cppVar_1821);
  *(&llvm_cbe_cppVar_1817) = llvm_cbe_tmp__2027;
  goto llvm_cbe_tmp__2064;

llvm_cbe_tmp__2064:
  llvm_cbe_tmp__2028 = *(&llvm_cbe_cppVar_1817);
  *(&llvm_cbe_cppVar_1803) = llvm_cbe_tmp__2028;
  goto llvm_cbe_tmp__2059;

llvm_cbe_tmp__2059:
  llvm_cbe_tmp__2029 = *(&llvm_cbe_cppVar_1803);
  *(&llvm_cbe_cppVar_1799) = llvm_cbe_tmp__2029;
  goto llvm_cbe_tmp__2051;

llvm_cbe_tmp__2051:
  llvm_cbe_tmp__2030 = *(&llvm_cbe_cppVar_1799);
  *(&llvm_cbe_cppVar_1795) = llvm_cbe_tmp__2030;
  goto llvm_cbe_tmp__2046;

llvm_cbe_tmp__2046:
  llvm_cbe_tmp__2031 = *(&llvm_cbe_cppVar_1795);
  *(&llvm_cbe_cppVar_1792) = llvm_cbe_tmp__2031;
  goto llvm_cbe_tmp__2067;

llvm_cbe_tmp__2041:
  llvm_cbe_tmp__2032 = *((&llvm_cbe_tmp__1970->field24));
  *(&llvm_cbe_cppVar_1827) = (((unsigned char )(bool )(llvm_cbe_tmp__2032 == 2ull)));
  llvm_cbe_tmp__2033 = *((&llvm_cbe_tmp__1970->field32));
  *(&llvm_cbe_cppVar_1825) = llvm_cbe_tmp__2033;
  llvm_cbe_tmp__2034 = *(&llvm_cbe_cppVar_1825);
  *(&llvm_cbe_cppVar_1792) = llvm_cbe_tmp__2034;
  goto llvm_cbe_tmp__2067;

llvm_cbe_tmp__2067:
  llvm_cbe_tmp__2035 = *(&llvm_cbe_cppVar_1792);
  *(&llvm_cbe_cppVar_1789) = llvm_cbe_tmp__2035;
  goto llvm_cbe_tmp__2039;

llvm_cbe_tmp__2039:
  llvm_cbe_tmp__2036 = *(&llvm_cbe_cppVar_1789);
  return llvm_cbe_tmp__2036;
}


unsigned long long _ZN13model_predict16cppUpdateFun_upcElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__2068;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2069;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2070;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2071;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2072;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2073;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2074;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2075;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2076;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2077;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2078;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2079;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1851;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1850;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1830;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1831;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1833;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1834;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1836;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1837;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1839;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1840;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1841;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1842;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1843;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1845;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1846;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1847;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1848;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1849;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1844;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1838;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1835;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1832;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1829;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__2080;
  unsigned long long llvm_cbe_tmp__2081;
  unsigned char llvm_cbe_tmp__2082;
  unsigned long long llvm_cbe_tmp__2083;
  unsigned long long llvm_cbe_tmp__2084;
  unsigned char llvm_cbe_tmp__2085;
  unsigned long long llvm_cbe_tmp__2086;
  unsigned long long llvm_cbe_tmp__2087;
  unsigned char llvm_cbe_tmp__2088;
  unsigned long long llvm_cbe_tmp__2089;
  unsigned long long llvm_cbe_tmp__2090;
  unsigned char llvm_cbe_tmp__2091;
  unsigned char llvm_cbe_tmp__2092;
  bool llvm_cbe_tmp__2093;
  bool llvm_cbe_tmp__2094;
  bool llvm_cbe_tmp__2094__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2095;
  unsigned long long llvm_cbe_tmp__2096;
  unsigned long long llvm_cbe_tmp__2097;
  unsigned long long llvm_cbe_tmp__2098;
  unsigned long long llvm_cbe_tmp__2099;
  unsigned long long llvm_cbe_tmp__2100;
  unsigned long long llvm_cbe_tmp__2101;
  unsigned long long llvm_cbe_tmp__2102;
  unsigned char llvm_cbe_tmp__2103;
  unsigned char llvm_cbe_tmp__2104;
  bool llvm_cbe_tmp__2105;
  bool llvm_cbe_tmp__2106;
  bool llvm_cbe_tmp__2106__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2107;
  unsigned long long llvm_cbe_tmp__2108;
  unsigned long long llvm_cbe_tmp__2109;
  unsigned long long llvm_cbe_tmp__2110;
  unsigned long long llvm_cbe_tmp__2111;
  unsigned long long llvm_cbe_tmp__2112;
  unsigned long long llvm_cbe_tmp__2113;
  unsigned long long llvm_cbe_tmp__2114;

  *(&llvm_cbe_tmp__2068) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2069) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__2070) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__2071) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__2072) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__2073) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__2074) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__2075) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__2076) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__2077) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__2078) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__2079) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__2080 = *(&llvm_cbe_tmp__2068);
  llvm_cbe_tmp__2081 = *((&llvm_cbe_tmp__2080->field24));
  *(&llvm_cbe_cppVar_1831) = (((unsigned char )(bool )(llvm_cbe_tmp__2081 == 0ull)));
  llvm_cbe_tmp__2082 = *(&llvm_cbe_cppVar_1831);
  if ((((((bool )llvm_cbe_tmp__2082&1u))&1))) {
    goto llvm_cbe_tmp__2115;
  } else {
    goto llvm_cbe_tmp__2116;
  }

llvm_cbe_tmp__2115:
  llvm_cbe_tmp__2083 = *((&llvm_cbe_tmp__2080->field34));
  *(&llvm_cbe_cppVar_1829) = llvm_cbe_tmp__2083;
  goto llvm_cbe_tmp__2117;

llvm_cbe_tmp__2116:
  llvm_cbe_tmp__2084 = *((&llvm_cbe_tmp__2080->field24));
  *(&llvm_cbe_cppVar_1834) = (((unsigned char )(bool )(llvm_cbe_tmp__2084 == 1ull)));
  llvm_cbe_tmp__2085 = *(&llvm_cbe_cppVar_1834);
  if ((((((bool )llvm_cbe_tmp__2085&1u))&1))) {
    goto llvm_cbe_tmp__2118;
  } else {
    goto llvm_cbe_tmp__2119;
  }

llvm_cbe_tmp__2118:
  llvm_cbe_tmp__2086 = *((&llvm_cbe_tmp__2080->field34));
  *(&llvm_cbe_cppVar_1832) = llvm_cbe_tmp__2086;
  goto llvm_cbe_tmp__2120;

llvm_cbe_tmp__2119:
  llvm_cbe_tmp__2087 = *((&llvm_cbe_tmp__2080->field24));
  *(&llvm_cbe_cppVar_1837) = (((unsigned char )(bool )(llvm_cbe_tmp__2087 == 2ull)));
  llvm_cbe_tmp__2088 = *(&llvm_cbe_cppVar_1837);
  if ((((((bool )llvm_cbe_tmp__2088&1u))&1))) {
    goto llvm_cbe_tmp__2121;
  } else {
    goto llvm_cbe_tmp__2122;
  }

llvm_cbe_tmp__2121:
  llvm_cbe_tmp__2089 = *((&llvm_cbe_tmp__2080->field39));
  *(&llvm_cbe_cppVar_1840) = (((unsigned char )(bool )(llvm_cbe_tmp__2089 == 0ull)));
  llvm_cbe_tmp__2090 = *((&llvm_cbe_tmp__2080->field36));
  *(&llvm_cbe_cppVar_1842) = (((unsigned char )(bool )(llvm_cbe_tmp__2090 == 1ull)));
  llvm_cbe_tmp__2091 = *(&llvm_cbe_cppVar_1840);
  if ((((((bool )llvm_cbe_tmp__2091&1u))&1))) {
    goto llvm_cbe_tmp__2123;
  } else {
    llvm_cbe_tmp__2094__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2124;
  }

llvm_cbe_tmp__2123:
  llvm_cbe_tmp__2092 = *(&llvm_cbe_cppVar_1842);
  llvm_cbe_tmp__2093 = ((((bool )llvm_cbe_tmp__2092&1u))&1);
  llvm_cbe_tmp__2094__PHI_TEMPORARY = llvm_cbe_tmp__2093;   /* for PHI node */
  goto llvm_cbe_tmp__2124;

llvm_cbe_tmp__2124:
  llvm_cbe_tmp__2094 = ((llvm_cbe_tmp__2094__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1843) = (((unsigned char )(bool )llvm_cbe_tmp__2094));
  llvm_cbe_tmp__2095 = *(&llvm_cbe_cppVar_1843);
  if ((((((bool )llvm_cbe_tmp__2095&1u))&1))) {
    goto llvm_cbe_tmp__2125;
  } else {
    goto llvm_cbe_tmp__2126;
  }

llvm_cbe_tmp__2125:
  llvm_cbe_tmp__2096 = *((&llvm_cbe_tmp__2080->field14));
  *(&llvm_cbe_cppVar_1846) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2096) - ((unsigned long long )1ull))));
  llvm_cbe_tmp__2097 = *(&llvm_cbe_cppVar_1846);
  llvm_cbe_tmp__2098 = *((&llvm_cbe_tmp__2080->field41));
  *(&llvm_cbe_cppVar_1846) = (llvm_cbe_tmp__2097 & llvm_cbe_tmp__2098);
  llvm_cbe_tmp__2099 = *((&llvm_cbe_tmp__2080->field7));
  llvm_cbe_tmp__2100 = *(&llvm_cbe_cppVar_1846);
  *(&llvm_cbe_cppVar_1847) = (((unsigned char )(bool )(llvm_cbe_tmp__2099 == llvm_cbe_tmp__2100)));
  llvm_cbe_tmp__2101 = *((&llvm_cbe_tmp__2080->field10));
  llvm_cbe_tmp__2102 = *((&llvm_cbe_tmp__2080->field12));
  *(&llvm_cbe_cppVar_1848) = (((unsigned char )(bool )(llvm_cbe_tmp__2101 == llvm_cbe_tmp__2102)));
  llvm_cbe_tmp__2103 = *(&llvm_cbe_cppVar_1847);
  if ((((((bool )llvm_cbe_tmp__2103&1u))&1))) {
    goto llvm_cbe_tmp__2127;
  } else {
    llvm_cbe_tmp__2106__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2128;
  }

llvm_cbe_tmp__2127:
  llvm_cbe_tmp__2104 = *(&llvm_cbe_cppVar_1848);
  llvm_cbe_tmp__2105 = ((((bool )llvm_cbe_tmp__2104&1u))&1);
  llvm_cbe_tmp__2106__PHI_TEMPORARY = llvm_cbe_tmp__2105;   /* for PHI node */
  goto llvm_cbe_tmp__2128;

llvm_cbe_tmp__2128:
  llvm_cbe_tmp__2106 = ((llvm_cbe_tmp__2106__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1849) = (((unsigned char )(bool )llvm_cbe_tmp__2106));
  llvm_cbe_tmp__2107 = *(&llvm_cbe_cppVar_1849);
  if ((((((bool )llvm_cbe_tmp__2107&1u))&1))) {
    goto llvm_cbe_tmp__2129;
  } else {
    goto llvm_cbe_tmp__2130;
  }

llvm_cbe_tmp__2129:
  *(&llvm_cbe_cppVar_1844) = 3ull;
  goto llvm_cbe_tmp__2131;

llvm_cbe_tmp__2130:
  *(&llvm_cbe_cppVar_1844) = 0ull;
  goto llvm_cbe_tmp__2131;

llvm_cbe_tmp__2131:
  llvm_cbe_tmp__2108 = *(&llvm_cbe_cppVar_1844);
  *(&llvm_cbe_cppVar_1838) = llvm_cbe_tmp__2108;
  goto llvm_cbe_tmp__2132;

llvm_cbe_tmp__2126:
  llvm_cbe_tmp__2109 = *((&llvm_cbe_tmp__2080->field34));
  *(&llvm_cbe_cppVar_1838) = llvm_cbe_tmp__2109;
  goto llvm_cbe_tmp__2132;

llvm_cbe_tmp__2132:
  llvm_cbe_tmp__2110 = *(&llvm_cbe_cppVar_1838);
  *(&llvm_cbe_cppVar_1835) = llvm_cbe_tmp__2110;
  goto llvm_cbe_tmp__2133;

llvm_cbe_tmp__2122:
  llvm_cbe_tmp__2111 = *((&llvm_cbe_tmp__2080->field34));
  *(&llvm_cbe_cppVar_1835) = llvm_cbe_tmp__2111;
  goto llvm_cbe_tmp__2133;

llvm_cbe_tmp__2133:
  llvm_cbe_tmp__2112 = *(&llvm_cbe_cppVar_1835);
  *(&llvm_cbe_cppVar_1832) = llvm_cbe_tmp__2112;
  goto llvm_cbe_tmp__2120;

llvm_cbe_tmp__2120:
  llvm_cbe_tmp__2113 = *(&llvm_cbe_cppVar_1832);
  *(&llvm_cbe_cppVar_1829) = llvm_cbe_tmp__2113;
  goto llvm_cbe_tmp__2117;

llvm_cbe_tmp__2117:
  llvm_cbe_tmp__2114 = *(&llvm_cbe_cppVar_1829);
  return llvm_cbe_tmp__2114;
}


struct l_unnamed2 _ZN13model_predict28cppUpdateFun_visibleEnergiesElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_unnamed2 StructReturn;  /* Struct return temporary */
  struct l_unnamed2 *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_predict *llvm_cbe_tmp__2134;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2135;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2136;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2137;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2138;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2139;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2140;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2141;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2142;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2143;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2144;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2145;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2120;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2105;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2106;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2108;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2109;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2163;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2164;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2126;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2127;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2128;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2115;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2111;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2112;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2113;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2137;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2138;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2139;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2151;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2152;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2153;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2155;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2156;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2157;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2159;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2160;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2161;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2118;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2119;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2117;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2122;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2123;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2124;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2125;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2129;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2130;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2131;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2132;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2133;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2121;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2134;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2116;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_2135;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_2114;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__2146;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2147;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2146;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2144;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_2145;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2147;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2143;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2141;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2142;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2148;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_2140;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_2149;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_2158;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_2154;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_2150;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_2136;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_2110;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_2162;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_2107;    /* Address-exposed local */
  bool llvm_cbe_tmp__2148;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2149;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__2150;
  unsigned long long llvm_cbe_tmp__2151;
  unsigned char llvm_cbe_tmp__2152;
  struct l_unnamed2 *llvm_cbe_tmp__2153;
  unsigned long long llvm_cbe_tmp__2154;
  unsigned char llvm_cbe_tmp__2155;
  unsigned long long llvm_cbe_tmp__2156;
  unsigned char llvm_cbe_tmp__2157;
  unsigned char llvm_cbe_tmp__2158;
  bool llvm_cbe_tmp__2159;
  bool llvm_cbe_tmp__2160;
  bool llvm_cbe_tmp__2160__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2161;
  unsigned long long llvm_cbe_tmp__2162;
  unsigned long long llvm_cbe_tmp__2163;
  unsigned char llvm_cbe_tmp__2164;
  unsigned long long llvm_cbe_tmp__2165;
  unsigned long long llvm_cbe_tmp__2166;
  unsigned long long llvm_cbe_tmp__2167;
  unsigned char llvm_cbe_tmp__2168;
  unsigned long long llvm_cbe_tmp__2169;
  unsigned long long llvm_cbe_tmp__2170;
  unsigned long long llvm_cbe_tmp__2171;
  unsigned long long llvm_cbe_tmp__2172;
  unsigned long long llvm_cbe_tmp__2173;
  unsigned long long llvm_cbe_tmp__2174;
  unsigned char llvm_cbe_tmp__2175;
  unsigned long long llvm_cbe_tmp__2176;
  unsigned long long llvm_cbe_tmp__2177;
  unsigned long long llvm_cbe_tmp__2178;
  unsigned long long llvm_cbe_tmp__2179;
  unsigned long long llvm_cbe_tmp__2180;
  unsigned long long llvm_cbe_tmp__2181;
  unsigned long long llvm_cbe_tmp__2182;
  unsigned long long llvm_cbe_tmp__2183;
  unsigned long long llvm_cbe_tmp__2184;
  unsigned long long llvm_cbe_tmp__2185;
  unsigned long long llvm_cbe_tmp__2186;
  unsigned long long llvm_cbe_tmp__2187;
  unsigned long long llvm_cbe_tmp__2188;
  unsigned long long llvm_cbe_tmp__2189;
  unsigned long long llvm_cbe_tmp__2190;
  unsigned long long llvm_cbe_tmp__2191;
  unsigned long long llvm_cbe_tmp__2192;
  unsigned long long llvm_cbe_tmp__2192__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__2193;
  unsigned long long llvm_cbe_tmp__2194;
  unsigned long long llvm_cbe_tmp__2195;
  unsigned long long llvm_cbe_tmp__2196;
  unsigned long long llvm_cbe_tmp__2197;
  unsigned long long llvm_cbe_tmp__2198;
  unsigned long long llvm_cbe_tmp__2199;
  unsigned long long llvm_cbe_tmp__2200;
  unsigned long long llvm_cbe_tmp__2201;
  unsigned long long llvm_cbe_tmp__2202;
  unsigned long long llvm_cbe_tmp__2203;
  struct l_unnamed2 *llvm_cbe_tmp__2204;
  unsigned long long llvm_cbe_tmp__2205;
  unsigned long long llvm_cbe_tmp__2206;
  struct l_unnamed2 *llvm_cbe_tmp__2207;
  struct l_unnamed2 *llvm_cbe_tmp__2208;
  struct l_unnamed2 *llvm_cbe_tmp__2209;
  unsigned long long llvm_cbe_tmp__2210;
  unsigned char llvm_cbe_tmp__2211;
  unsigned char llvm_cbe_tmp__2212;
  bool llvm_cbe_tmp__2213;
  bool llvm_cbe_tmp__2214;
  bool llvm_cbe_tmp__2214__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2215;
  unsigned long long llvm_cbe_tmp__2216;
  unsigned long long llvm_cbe_tmp__2217;
  unsigned long long llvm_cbe_tmp__2218;
  unsigned long long llvm_cbe_tmp__2219;
  unsigned long long llvm_cbe_tmp__2220;
  unsigned long long llvm_cbe_tmp__2221;
  unsigned long long llvm_cbe_tmp__2222;
  unsigned char llvm_cbe_tmp__2223;
  unsigned long long llvm_cbe_tmp__2224;
  unsigned long long llvm_cbe_tmp__2225;
  unsigned long long llvm_cbe_tmp__2226;
  unsigned long long llvm_cbe_tmp__2227;
  unsigned long long llvm_cbe_tmp__2228;
  unsigned long long llvm_cbe_tmp__2229;
  unsigned long long llvm_cbe_tmp__2230;
  unsigned long long llvm_cbe_tmp__2231;
  struct l_unnamed2 *llvm_cbe_tmp__2232;
  unsigned long long llvm_cbe_tmp__2233;
  unsigned long long llvm_cbe_tmp__2234;
  struct l_unnamed2 *llvm_cbe_tmp__2235;
  unsigned long long llvm_cbe_tmp__2236;
  unsigned char llvm_cbe_tmp__2237;
  unsigned char llvm_cbe_tmp__2238;
  bool llvm_cbe_tmp__2239;
  bool llvm_cbe_tmp__2240;
  bool llvm_cbe_tmp__2240__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2241;
  struct l_unnamed2 *llvm_cbe_tmp__2242;
  unsigned long long llvm_cbe_tmp__2243;
  unsigned char llvm_cbe_tmp__2244;
  unsigned char llvm_cbe_tmp__2245;
  bool llvm_cbe_tmp__2246;
  bool llvm_cbe_tmp__2247;
  bool llvm_cbe_tmp__2247__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2248;
  struct l_unnamed2 *llvm_cbe_tmp__2249;
  unsigned long long llvm_cbe_tmp__2250;
  unsigned char llvm_cbe_tmp__2251;
  unsigned char llvm_cbe_tmp__2252;
  bool llvm_cbe_tmp__2253;
  bool llvm_cbe_tmp__2254;
  bool llvm_cbe_tmp__2254__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2255;
  bool llvm_cbe_tmp__2256;
  struct l_unnamed2 *llvm_cbe_tmp__2257;
  struct l_unnamed2 *llvm_cbe_tmp__2258;
  struct l_unnamed2 *llvm_cbe_tmp__2259;
  struct l_unnamed2 *llvm_cbe_tmp__2260;
  struct l_unnamed2 *llvm_cbe_tmp__2261;
  struct l_unnamed2 *llvm_cbe_tmp__2262;
  unsigned long long llvm_cbe_tmp__2263;
  unsigned char llvm_cbe_tmp__2264;
  bool llvm_cbe_tmp__2265;
  struct l_unnamed2 *llvm_cbe_tmp__2266;
  struct l_unnamed2 *llvm_cbe_tmp__2267;
  struct l_unnamed2 *llvm_cbe_tmp__2268;
  bool llvm_cbe_tmp__2269;

  *(&llvm_cbe_tmp__2134) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2135) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__2136) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__2137) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__2138) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__2139) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__2140) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__2141) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__2142) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__2143) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__2144) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__2145) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__2150 = *(&llvm_cbe_tmp__2134);
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_2135));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_2114));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_2149));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_2158));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_2154));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_2150));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_2136));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_2110));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_2162));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_2107));
  *(&llvm_cbe_tmp__2148) = ((0) & 1);
  _ZN8type_memItLj8EEC1Ev(llvm_cbe_agg_2e_result);
  llvm_cbe_tmp__2151 = *((&llvm_cbe_tmp__2150->field24));
  *(&llvm_cbe_cppVar_2106) = (((unsigned char )(bool )(llvm_cbe_tmp__2151 == 0ull)));
  llvm_cbe_tmp__2152 = *(&llvm_cbe_cppVar_2106);
  if ((((((bool )llvm_cbe_tmp__2152&1u))&1))) {
    goto llvm_cbe_tmp__2270;
  } else {
    goto llvm_cbe_tmp__2271;
  }

llvm_cbe_tmp__2270:
  llvm_cbe_tmp__2153 = _ZN8type_memItLj8EEaSERKS0_(llvm_cbe_agg_2e_result, ((&llvm_cbe_tmp__2150->field35)));
  goto llvm_cbe_tmp__2272;

llvm_cbe_tmp__2271:
  llvm_cbe_tmp__2154 = *((&llvm_cbe_tmp__2150->field24));
  *(&llvm_cbe_cppVar_2109) = (((unsigned char )(bool )(llvm_cbe_tmp__2154 == 1ull)));
  llvm_cbe_tmp__2155 = *(&llvm_cbe_cppVar_2109);
  if ((((((bool )llvm_cbe_tmp__2155&1u))&1))) {
    goto llvm_cbe_tmp__2273;
  } else {
    goto llvm_cbe_tmp__2274;
  }

llvm_cbe_tmp__2273:
  llvm_cbe_tmp__2156 = *((&llvm_cbe_tmp__2150->field17));
  *(&llvm_cbe_cppVar_2112) = (((unsigned char )(bool )(llvm_cbe_tmp__2156 == 0ull)));
  llvm_cbe_tmp__2157 = *(&llvm_cbe_cppVar_2109);
  if ((((((bool )llvm_cbe_tmp__2157&1u))&1))) {
    goto llvm_cbe_tmp__2275;
  } else {
    llvm_cbe_tmp__2160__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2276;
  }

llvm_cbe_tmp__2275:
  llvm_cbe_tmp__2158 = *(&llvm_cbe_cppVar_2112);
  llvm_cbe_tmp__2159 = ((((bool )llvm_cbe_tmp__2158&1u))&1);
  llvm_cbe_tmp__2160__PHI_TEMPORARY = llvm_cbe_tmp__2159;   /* for PHI node */
  goto llvm_cbe_tmp__2276;

llvm_cbe_tmp__2276:
  llvm_cbe_tmp__2160 = ((llvm_cbe_tmp__2160__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_2113) = (((unsigned char )(bool )llvm_cbe_tmp__2160));
  llvm_cbe_tmp__2161 = *(&llvm_cbe_cppVar_2113);
  if ((((((bool )llvm_cbe_tmp__2161&1u))&1))) {
    goto llvm_cbe_tmp__2277;
  } else {
    goto llvm_cbe_tmp__2278;
  }

llvm_cbe_tmp__2277:
  llvm_cbe_tmp__2162 = *((&llvm_cbe_tmp__2150->field19));
  llvm_cbe_tmp__2163 = *((&llvm_cbe_tmp__2150->field11));
  *(&llvm_cbe_cppVar_2115) = (((unsigned char )(bool )(llvm_cbe_tmp__2162 == llvm_cbe_tmp__2163)));
  llvm_cbe_tmp__2164 = *(&llvm_cbe_cppVar_2115);
  if ((((((bool )llvm_cbe_tmp__2164&1u))&1))) {
    goto llvm_cbe_tmp__2279;
  } else {
    goto llvm_cbe_tmp__2280;
  }

llvm_cbe_tmp__2279:
  llvm_cbe_tmp__2165 = *((&llvm_cbe_tmp__2150->field9));
  llvm_cbe_tmp__2166 = *((&llvm_cbe_tmp__2150->field44));
  *(&llvm_cbe_cppVar_2116) = ((((signed long long )(((signed long long )llvm_cbe_tmp__2165) >> ((signed long long )0ull)))) & llvm_cbe_tmp__2166);
  llvm_cbe_tmp__2167 = *((&llvm_cbe_tmp__2150->field19));
  *(&llvm_cbe_cppVar_2119) = (((unsigned char )(bool )(llvm_cbe_tmp__2167 == 0ull)));
  llvm_cbe_tmp__2168 = *(&llvm_cbe_cppVar_2119);
  if ((((((bool )llvm_cbe_tmp__2168&1u))&1))) {
    goto llvm_cbe_tmp__2281;
  } else {
    goto llvm_cbe_tmp__2282;
  }

llvm_cbe_tmp__2281:
  *(&llvm_cbe_cppVar_2117) = 0ull;
  goto llvm_cbe_tmp__2283;

llvm_cbe_tmp__2282:
  llvm_cbe_tmp__2169 = *((&llvm_cbe_tmp__2150->field23));
  *(&llvm_cbe_cppVar_2117) = llvm_cbe_tmp__2169;
  goto llvm_cbe_tmp__2283;

llvm_cbe_tmp__2283:
  llvm_cbe_tmp__2170 = *((&llvm_cbe_tmp__2150->field19));
  llvm_cbe_tmp__2171 = *((&llvm_cbe_tmp__2150->field48));
  *(&llvm_cbe_cppVar_2122) = ((((signed long long )(((signed long long )llvm_cbe_tmp__2170) >> ((signed long long )0ull)))) & llvm_cbe_tmp__2171);
  llvm_cbe_tmp__2172 = *(&llvm_cbe_cppVar_2122);
  llvm_cbe_tmp__2173 = _ZN8type_memIbLj128EE2rdEl(((&llvm_cbe_tmp__2150->field6)), llvm_cbe_tmp__2172);
  *(&llvm_cbe_cppVar_2123) = llvm_cbe_tmp__2173;
  llvm_cbe_tmp__2174 = *(&llvm_cbe_cppVar_2123);
  *(&llvm_cbe_cppVar_2125) = (((unsigned char )(bool )(llvm_cbe_tmp__2174 == 1ull)));
  llvm_cbe_tmp__2175 = *(&llvm_cbe_cppVar_2125);
  if ((((((bool )llvm_cbe_tmp__2175&1u))&1))) {
    goto llvm_cbe_tmp__2284;
  } else {
    goto llvm_cbe_tmp__2285;
  }

llvm_cbe_tmp__2284:
  llvm_cbe_tmp__2176 = *((&llvm_cbe_tmp__2150->field25));
  *(&llvm_cbe_cppVar_2127) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__2176))));
  llvm_cbe_tmp__2177 = *(&llvm_cbe_cppVar_2127);
  llvm_cbe_tmp__2178 = *((&llvm_cbe_tmp__2150->field41));
  *(&llvm_cbe_cppVar_2127) = (llvm_cbe_tmp__2177 & llvm_cbe_tmp__2178);
  llvm_cbe_tmp__2179 = *(&llvm_cbe_cppVar_2127);
  llvm_cbe_tmp__2180 = *((&llvm_cbe_tmp__2150->field19));
  *(&llvm_cbe_cppVar_2128) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2179) + ((unsigned long long )llvm_cbe_tmp__2180))));
  llvm_cbe_tmp__2181 = *(&llvm_cbe_cppVar_2128);
  llvm_cbe_tmp__2182 = *((&llvm_cbe_tmp__2150->field41));
  *(&llvm_cbe_cppVar_2128) = (llvm_cbe_tmp__2181 & llvm_cbe_tmp__2182);
  llvm_cbe_tmp__2183 = *(&llvm_cbe_cppVar_2128);
  llvm_cbe_tmp__2184 = _ZN8type_memIhLj65536EE2rdEl(((&llvm_cbe_tmp__2150->field4)), llvm_cbe_tmp__2183);
  *(&llvm_cbe_cppVar_2129) = llvm_cbe_tmp__2184;
  llvm_cbe_tmp__2185 = *(&llvm_cbe_cppVar_2129);
  llvm_cbe_tmp__2186 = *((&llvm_cbe_tmp__2150->field48));
  *(&llvm_cbe_cppVar_2130) = ((((signed long long )(((signed long long )llvm_cbe_tmp__2185) >> ((signed long long )1ull)))) & llvm_cbe_tmp__2186);
  llvm_cbe_tmp__2187 = *(&llvm_cbe_cppVar_2130);
  llvm_cbe_tmp__2188 = *((&llvm_cbe_tmp__2150->field53));
  llvm_cbe_tmp__2189 = *(&llvm_cbe_cppVar_2130);
  if (((llvm_cbe_tmp__2187 & llvm_cbe_tmp__2188) != 0ull)) {
    goto llvm_cbe_tmp__2286;
  } else {
    llvm_cbe_tmp__2192__PHI_TEMPORARY = llvm_cbe_tmp__2189;   /* for PHI node */
    goto llvm_cbe_tmp__2287;
  }

llvm_cbe_tmp__2286:
  llvm_cbe_tmp__2190 = *((&llvm_cbe_tmp__2150->field55));
  llvm_cbe_tmp__2191 = llvm_cbe_tmp__2189 | llvm_cbe_tmp__2190;
  llvm_cbe_tmp__2192__PHI_TEMPORARY = llvm_cbe_tmp__2191;   /* for PHI node */
  goto llvm_cbe_tmp__2287;

llvm_cbe_tmp__2287:
  llvm_cbe_tmp__2192 = llvm_cbe_tmp__2192__PHI_TEMPORARY;
  *(&llvm_cbe_cppVar_2131) = llvm_cbe_tmp__2192;
  llvm_cbe_tmp__2193 = *(&llvm_cbe_cppVar_2129);
  llvm_cbe_tmp__2194 = *((&llvm_cbe_tmp__2150->field40));
  *(&llvm_cbe_cppVar_2132) = ((((signed long long )(((signed long long )llvm_cbe_tmp__2193) >> ((signed long long )0ull)))) & llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2195 = *(&llvm_cbe_cppVar_2131);
  llvm_cbe_tmp__2196 = *(&llvm_cbe_cppVar_2132);
  *(&llvm_cbe_cppVar_2133) = ((llvm_cbe_tmp__2195 << 1ull) | llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2197 = *(&llvm_cbe_cppVar_2133);
  llvm_cbe_tmp__2198 = *((&llvm_cbe_tmp__2150->field41));
  *(&llvm_cbe_cppVar_2133) = (llvm_cbe_tmp__2197 & llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2199 = *(&llvm_cbe_cppVar_2133);
  *(&llvm_cbe_cppVar_2121) = llvm_cbe_tmp__2199;
  goto llvm_cbe_tmp__2288;

llvm_cbe_tmp__2285:
  *(&llvm_cbe_cppVar_2121) = 0ull;
  goto llvm_cbe_tmp__2288;

llvm_cbe_tmp__2288:
  llvm_cbe_tmp__2200 = *(&llvm_cbe_cppVar_2117);
  llvm_cbe_tmp__2201 = *(&llvm_cbe_cppVar_2121);
  *(&llvm_cbe_cppVar_2134) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2200) + ((unsigned long long )llvm_cbe_tmp__2201))));
  llvm_cbe_tmp__2202 = *(&llvm_cbe_cppVar_2134);
  llvm_cbe_tmp__2203 = *((&llvm_cbe_tmp__2150->field41));
  *(&llvm_cbe_cppVar_2134) = (llvm_cbe_tmp__2202 & llvm_cbe_tmp__2203);
  llvm_cbe_tmp__2204 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_2135), ((&llvm_cbe_tmp__2150->field35)));
  llvm_cbe_tmp__2205 = *(&llvm_cbe_cppVar_2116);
  llvm_cbe_tmp__2206 = *(&llvm_cbe_cppVar_2134);
  _ZN8type_memItLj8EE2wrEll((&llvm_cbe_cppVar_2135), llvm_cbe_tmp__2205, llvm_cbe_tmp__2206);
  llvm_cbe_tmp__2207 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_2114), (&llvm_cbe_cppVar_2135));
  goto llvm_cbe_tmp__2289;

llvm_cbe_tmp__2280:
  llvm_cbe_tmp__2208 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_2114), ((&llvm_cbe_tmp__2150->field35)));
  goto llvm_cbe_tmp__2289;

llvm_cbe_tmp__2289:
  llvm_cbe_tmp__2209 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_2110), (&llvm_cbe_cppVar_2114));
  goto llvm_cbe_tmp__2290;

llvm_cbe_tmp__2278:
  llvm_cbe_tmp__2210 = *((&llvm_cbe_tmp__2150->field17));
  *(&llvm_cbe_cppVar_2138) = (((unsigned char )(bool )(llvm_cbe_tmp__2210 == 1ull)));
  llvm_cbe_tmp__2211 = *(&llvm_cbe_cppVar_2109);
  if ((((((bool )llvm_cbe_tmp__2211&1u))&1))) {
    goto llvm_cbe_tmp__2291;
  } else {
    llvm_cbe_tmp__2214__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2292;
  }

llvm_cbe_tmp__2291:
  llvm_cbe_tmp__2212 = *(&llvm_cbe_cppVar_2138);
  llvm_cbe_tmp__2213 = ((((bool )llvm_cbe_tmp__2212&1u))&1);
  llvm_cbe_tmp__2214__PHI_TEMPORARY = llvm_cbe_tmp__2213;   /* for PHI node */
  goto llvm_cbe_tmp__2292;

llvm_cbe_tmp__2292:
  llvm_cbe_tmp__2214 = ((llvm_cbe_tmp__2214__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_2139) = (((unsigned char )(bool )llvm_cbe_tmp__2214));
  llvm_cbe_tmp__2215 = *(&llvm_cbe_cppVar_2139);
  if ((((((bool )llvm_cbe_tmp__2215&1u))&1))) {
    goto llvm_cbe_tmp__2293;
  } else {
    goto llvm_cbe_tmp__2294;
  }

llvm_cbe_tmp__2293:
  llvm_cbe_tmp__2216 = *((&llvm_cbe_tmp__2150->field9));
  llvm_cbe_tmp__2217 = *((&llvm_cbe_tmp__2150->field44));
  *(&llvm_cbe_cppVar_2140) = ((((signed long long )(((signed long long )llvm_cbe_tmp__2216) >> ((signed long long )0ull)))) & llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2218 = *((&llvm_cbe_tmp__2150->field9));
  llvm_cbe_tmp__2219 = *((&llvm_cbe_tmp__2150->field44));
  *(&llvm_cbe_cppVar_2141) = ((((signed long long )(((signed long long )llvm_cbe_tmp__2218) >> ((signed long long )0ull)))) & llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2220 = *(&llvm_cbe_cppVar_2141);
  llvm_cbe_tmp__2221 = _ZN8type_memItLj8EE2rdEl(((&llvm_cbe_tmp__2150->field35)), llvm_cbe_tmp__2220);
  *(&llvm_cbe_cppVar_2142) = llvm_cbe_tmp__2221;
  llvm_cbe_tmp__2222 = *((&llvm_cbe_tmp__2150->field9));
  *(&llvm_cbe_cppVar_2145) = (((unsigned char )(bool )(llvm_cbe_tmp__2222 == 0ull)));
  llvm_cbe_tmp__2223 = *(&llvm_cbe_cppVar_2145);
  llvm_cbe_tmp__2224 = *((&llvm_cbe_tmp__2150->field21));
  if ((((((bool )llvm_cbe_tmp__2223&1u))&1))) {
    goto llvm_cbe_tmp__2295;
  } else {
    goto llvm_cbe_tmp__2296;
  }

llvm_cbe_tmp__2295:
  *(&llvm_cbe_cppVar_2147) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2224) - ((unsigned long long )62ull))));
  llvm_cbe_tmp__2225 = *(&llvm_cbe_cppVar_2147);
  llvm_cbe_tmp__2226 = *((&llvm_cbe_tmp__2150->field41));
  *(&llvm_cbe_cppVar_2147) = (llvm_cbe_tmp__2225 & llvm_cbe_tmp__2226);
  llvm_cbe_tmp__2227 = *(&llvm_cbe_cppVar_2147);
  *(&llvm_cbe_cppVar_2143) = llvm_cbe_tmp__2227;
  goto llvm_cbe_tmp__2297;

llvm_cbe_tmp__2296:
  *(&llvm_cbe_cppVar_2143) = llvm_cbe_tmp__2224;
  goto llvm_cbe_tmp__2297;

llvm_cbe_tmp__2297:
  llvm_cbe_tmp__2228 = *(&llvm_cbe_cppVar_2142);
  llvm_cbe_tmp__2229 = *(&llvm_cbe_cppVar_2143);
  *(&llvm_cbe_cppVar_2148) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2228) - ((unsigned long long )llvm_cbe_tmp__2229))));
  llvm_cbe_tmp__2230 = *(&llvm_cbe_cppVar_2148);
  llvm_cbe_tmp__2231 = *((&llvm_cbe_tmp__2150->field41));
  *(&llvm_cbe_cppVar_2148) = (llvm_cbe_tmp__2230 & llvm_cbe_tmp__2231);
  llvm_cbe_tmp__2232 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_2149), ((&llvm_cbe_tmp__2150->field35)));
  llvm_cbe_tmp__2233 = *(&llvm_cbe_cppVar_2140);
  llvm_cbe_tmp__2234 = *(&llvm_cbe_cppVar_2148);
  _ZN8type_memItLj8EE2wrEll((&llvm_cbe_cppVar_2149), llvm_cbe_tmp__2233, llvm_cbe_tmp__2234);
  llvm_cbe_tmp__2235 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_2136), (&llvm_cbe_cppVar_2149));
  goto llvm_cbe_tmp__2298;

llvm_cbe_tmp__2294:
  llvm_cbe_tmp__2236 = *((&llvm_cbe_tmp__2150->field17));
  *(&llvm_cbe_cppVar_2152) = (((unsigned char )(bool )(llvm_cbe_tmp__2236 == 2ull)));
  llvm_cbe_tmp__2237 = *(&llvm_cbe_cppVar_2109);
  if ((((((bool )llvm_cbe_tmp__2237&1u))&1))) {
    goto llvm_cbe_tmp__2299;
  } else {
    llvm_cbe_tmp__2240__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2300;
  }

llvm_cbe_tmp__2299:
  llvm_cbe_tmp__2238 = *(&llvm_cbe_cppVar_2152);
  llvm_cbe_tmp__2239 = ((((bool )llvm_cbe_tmp__2238&1u))&1);
  llvm_cbe_tmp__2240__PHI_TEMPORARY = llvm_cbe_tmp__2239;   /* for PHI node */
  goto llvm_cbe_tmp__2300;

llvm_cbe_tmp__2300:
  llvm_cbe_tmp__2240 = ((llvm_cbe_tmp__2240__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_2153) = (((unsigned char )(bool )llvm_cbe_tmp__2240));
  llvm_cbe_tmp__2241 = *(&llvm_cbe_cppVar_2153);
  if ((((((bool )llvm_cbe_tmp__2241&1u))&1))) {
    goto llvm_cbe_tmp__2301;
  } else {
    goto llvm_cbe_tmp__2302;
  }

llvm_cbe_tmp__2301:
  llvm_cbe_tmp__2242 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_2150), ((&llvm_cbe_tmp__2150->field35)));
  goto llvm_cbe_tmp__2303;

llvm_cbe_tmp__2302:
  llvm_cbe_tmp__2243 = *((&llvm_cbe_tmp__2150->field17));
  *(&llvm_cbe_cppVar_2156) = (((unsigned char )(bool )(llvm_cbe_tmp__2243 == 3ull)));
  llvm_cbe_tmp__2244 = *(&llvm_cbe_cppVar_2109);
  if ((((((bool )llvm_cbe_tmp__2244&1u))&1))) {
    goto llvm_cbe_tmp__2304;
  } else {
    llvm_cbe_tmp__2247__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2305;
  }

llvm_cbe_tmp__2304:
  llvm_cbe_tmp__2245 = *(&llvm_cbe_cppVar_2156);
  llvm_cbe_tmp__2246 = ((((bool )llvm_cbe_tmp__2245&1u))&1);
  llvm_cbe_tmp__2247__PHI_TEMPORARY = llvm_cbe_tmp__2246;   /* for PHI node */
  goto llvm_cbe_tmp__2305;

llvm_cbe_tmp__2305:
  llvm_cbe_tmp__2247 = ((llvm_cbe_tmp__2247__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_2157) = (((unsigned char )(bool )llvm_cbe_tmp__2247));
  llvm_cbe_tmp__2248 = *(&llvm_cbe_cppVar_2157);
  if ((((((bool )llvm_cbe_tmp__2248&1u))&1))) {
    goto llvm_cbe_tmp__2306;
  } else {
    goto llvm_cbe_tmp__2307;
  }

llvm_cbe_tmp__2306:
  llvm_cbe_tmp__2249 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_2154), ((&llvm_cbe_tmp__2150->field35)));
  goto llvm_cbe_tmp__2308;

llvm_cbe_tmp__2307:
  llvm_cbe_tmp__2250 = *((&llvm_cbe_tmp__2150->field17));
  *(&llvm_cbe_cppVar_2160) = (((unsigned char )(bool )(llvm_cbe_tmp__2250 == 4ull)));
  llvm_cbe_tmp__2251 = *(&llvm_cbe_cppVar_2109);
  if ((((((bool )llvm_cbe_tmp__2251&1u))&1))) {
    goto llvm_cbe_tmp__2309;
  } else {
    llvm_cbe_tmp__2254__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2310;
  }

llvm_cbe_tmp__2309:
  llvm_cbe_tmp__2252 = *(&llvm_cbe_cppVar_2160);
  llvm_cbe_tmp__2253 = ((((bool )llvm_cbe_tmp__2252&1u))&1);
  llvm_cbe_tmp__2254__PHI_TEMPORARY = llvm_cbe_tmp__2253;   /* for PHI node */
  goto llvm_cbe_tmp__2310;

llvm_cbe_tmp__2310:
  llvm_cbe_tmp__2254 = ((llvm_cbe_tmp__2254__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_2161) = (((unsigned char )(bool )llvm_cbe_tmp__2254));
  llvm_cbe_tmp__2255 = *(&llvm_cbe_cppVar_2161);
  llvm_cbe_tmp__2256 = ((((bool )llvm_cbe_tmp__2255&1u))&1);
  llvm_cbe_tmp__2257 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_2158), ((&llvm_cbe_tmp__2150->field35)));
  llvm_cbe_tmp__2258 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_2154), (&llvm_cbe_cppVar_2158));
  goto llvm_cbe_tmp__2308;

llvm_cbe_tmp__2308:
  llvm_cbe_tmp__2259 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_2150), (&llvm_cbe_cppVar_2154));
  goto llvm_cbe_tmp__2303;

llvm_cbe_tmp__2303:
  llvm_cbe_tmp__2260 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_2136), (&llvm_cbe_cppVar_2150));
  goto llvm_cbe_tmp__2298;

llvm_cbe_tmp__2298:
  llvm_cbe_tmp__2261 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_2110), (&llvm_cbe_cppVar_2136));
  goto llvm_cbe_tmp__2290;

llvm_cbe_tmp__2290:
  llvm_cbe_tmp__2262 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_2107), (&llvm_cbe_cppVar_2110));
  goto llvm_cbe_tmp__2311;

llvm_cbe_tmp__2274:
  llvm_cbe_tmp__2263 = *((&llvm_cbe_tmp__2150->field24));
  *(&llvm_cbe_cppVar_2164) = (((unsigned char )(bool )(llvm_cbe_tmp__2263 == 2ull)));
  llvm_cbe_tmp__2264 = *(&llvm_cbe_cppVar_2164);
  llvm_cbe_tmp__2265 = ((((bool )llvm_cbe_tmp__2264&1u))&1);
  llvm_cbe_tmp__2266 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_2162), ((&llvm_cbe_tmp__2150->field35)));
  llvm_cbe_tmp__2267 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_2107), (&llvm_cbe_cppVar_2162));
  goto llvm_cbe_tmp__2311;

llvm_cbe_tmp__2311:
  llvm_cbe_tmp__2268 = _ZN8type_memItLj8EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_2107));
  goto llvm_cbe_tmp__2272;

llvm_cbe_tmp__2272:
  *(&llvm_cbe_tmp__2148) = ((1) & 1);
  *(&llvm_cbe_tmp__2149) = 1u;
  llvm_cbe_tmp__2269 = ((*(&llvm_cbe_tmp__2148))&1);
  if (llvm_cbe_tmp__2269) {
    goto llvm_cbe_tmp__2312;
  } else {
    goto llvm_cbe_tmp__2313;
  }

llvm_cbe_tmp__2313:
  _ZN8type_memItLj8EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__2312;

llvm_cbe_tmp__2312:
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_2107));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_2162));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_2110));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_2136));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_2150));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_2154));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_2158));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_2149));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_2114));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_2135));
  return StructReturn;
}


void _ZN8type_memItLj8EEC1Ev(struct l_unnamed2 *llvm_cbe_this) {
  struct l_unnamed2 *llvm_cbe_tmp__2314;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__2315;

  *(&llvm_cbe_tmp__2314) = llvm_cbe_this;
  llvm_cbe_tmp__2315 = *(&llvm_cbe_tmp__2314);
  _ZN8type_memItLj8EEC2Ev(llvm_cbe_tmp__2315);
  return;
}


struct l_unnamed2 *_ZN8type_memItLj8EEaSERKS0_(struct l_unnamed2 *llvm_cbe_this, struct l_unnamed2 *llvm_cbe_r) {
  struct l_unnamed2 *llvm_cbe_tmp__2316;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__2317;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__2318;
  unsigned short *llvm_cbe_tmp__2319;
  struct l_unnamed2 *llvm_cbe_tmp__2320;
  unsigned short *llvm_cbe_tmp__2321;

  *(&llvm_cbe_tmp__2316) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2317) = llvm_cbe_r;
  llvm_cbe_tmp__2318 = *(&llvm_cbe_tmp__2316);
  llvm_cbe_tmp__2319 = *((&llvm_cbe_tmp__2318->field0));
  llvm_cbe_tmp__2320 = *(&llvm_cbe_tmp__2317);
  llvm_cbe_tmp__2321 = *((&llvm_cbe_tmp__2320->field0));
  __CPROVER_array_copy((((unsigned char *)llvm_cbe_tmp__2319)), (((unsigned char *)llvm_cbe_tmp__2321)));
  return llvm_cbe_tmp__2318;
}


void _ZN8type_memItLj8EE2wrEll(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) {
  struct l_unnamed2 *llvm_cbe_tmp__2322;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2323;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2324;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__2325;
  unsigned long long llvm_cbe_tmp__2326;
  unsigned long long llvm_cbe_tmp__2327;
  unsigned short *llvm_cbe_tmp__2328;

  *(&llvm_cbe_tmp__2322) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2323) = llvm_cbe_addr;
  *(&llvm_cbe_tmp__2324) = llvm_cbe_data;
  llvm_cbe_tmp__2325 = *(&llvm_cbe_tmp__2322);
  llvm_cbe_tmp__2326 = *(&llvm_cbe_tmp__2324);
  llvm_cbe_tmp__2327 = *(&llvm_cbe_tmp__2323);
  llvm_cbe_tmp__2328 = *((&llvm_cbe_tmp__2325->field0));
  *((&llvm_cbe_tmp__2328[((signed long long )llvm_cbe_tmp__2327)])) = (((unsigned short )llvm_cbe_tmp__2326));
  return;
}


void _ZN8type_memItLj8EED1Ev(struct l_unnamed2 *llvm_cbe_this) {
  struct l_unnamed2 *llvm_cbe_tmp__2329;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__2330;

  *(&llvm_cbe_tmp__2329) = llvm_cbe_this;
  llvm_cbe_tmp__2330 = *(&llvm_cbe_tmp__2329);
  _ZN8type_memItLj8EED2Ev(llvm_cbe_tmp__2330);
  return;
}


unsigned long long _ZN13model_predict24cppUpdateFun_wr_completeElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__2331;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2332;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2333;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2334;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2335;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2336;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2337;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2338;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2339;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2340;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2341;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2342;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1874;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1854;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1855;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1857;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1858;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1860;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1861;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1876;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1877;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1863;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1864;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1865;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1866;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1867;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1868;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1869;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1870;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1871;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1872;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1873;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1862;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1879;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1880;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1881;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1882;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1883;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1878;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1875;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1859;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1856;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1853;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__2343;
  unsigned long long llvm_cbe_tmp__2344;
  unsigned char llvm_cbe_tmp__2345;
  unsigned long long llvm_cbe_tmp__2346;
  unsigned long long llvm_cbe_tmp__2347;
  unsigned char llvm_cbe_tmp__2348;
  unsigned long long llvm_cbe_tmp__2349;
  unsigned long long llvm_cbe_tmp__2350;
  unsigned char llvm_cbe_tmp__2351;
  unsigned long long llvm_cbe_tmp__2352;
  unsigned long long llvm_cbe_tmp__2353;
  unsigned long long llvm_cbe_tmp__2354;
  unsigned long long llvm_cbe_tmp__2355;
  unsigned long long llvm_cbe_tmp__2356;
  unsigned long long llvm_cbe_tmp__2357;
  unsigned long long llvm_cbe_tmp__2358;
  unsigned long long llvm_cbe_tmp__2359;
  unsigned long long llvm_cbe_tmp__2360;
  unsigned char llvm_cbe_tmp__2361;
  unsigned char llvm_cbe_tmp__2362;
  bool llvm_cbe_tmp__2363;
  bool llvm_cbe_tmp__2364;
  bool llvm_cbe_tmp__2364__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__2365;
  unsigned char llvm_cbe_tmp__2366;
  unsigned char llvm_cbe_tmp__2367;
  bool llvm_cbe_tmp__2368;
  bool llvm_cbe_tmp__2369;
  bool llvm_cbe_tmp__2369__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2370;
  unsigned long long llvm_cbe_tmp__2371;
  unsigned long long llvm_cbe_tmp__2372;
  unsigned long long llvm_cbe_tmp__2373;
  unsigned char llvm_cbe_tmp__2374;
  unsigned long long llvm_cbe_tmp__2375;
  unsigned long long llvm_cbe_tmp__2376;
  unsigned char llvm_cbe_tmp__2377;
  unsigned char llvm_cbe_tmp__2378;
  bool llvm_cbe_tmp__2379;
  bool llvm_cbe_tmp__2380;
  bool llvm_cbe_tmp__2380__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2381;
  unsigned long long llvm_cbe_tmp__2382;
  unsigned long long llvm_cbe_tmp__2383;
  unsigned long long llvm_cbe_tmp__2384;
  unsigned long long llvm_cbe_tmp__2385;
  unsigned long long llvm_cbe_tmp__2386;
  unsigned long long llvm_cbe_tmp__2387;
  unsigned long long llvm_cbe_tmp__2388;

  *(&llvm_cbe_tmp__2331) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2332) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__2333) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__2334) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__2335) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__2336) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__2337) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__2338) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__2339) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__2340) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__2341) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__2342) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__2343 = *(&llvm_cbe_tmp__2331);
  llvm_cbe_tmp__2344 = *((&llvm_cbe_tmp__2343->field24));
  *(&llvm_cbe_cppVar_1855) = (((unsigned char )(bool )(llvm_cbe_tmp__2344 == 0ull)));
  llvm_cbe_tmp__2345 = *(&llvm_cbe_cppVar_1855);
  if ((((((bool )llvm_cbe_tmp__2345&1u))&1))) {
    goto llvm_cbe_tmp__2389;
  } else {
    goto llvm_cbe_tmp__2390;
  }

llvm_cbe_tmp__2389:
  llvm_cbe_tmp__2346 = *((&llvm_cbe_tmp__2343->field36));
  *(&llvm_cbe_cppVar_1853) = llvm_cbe_tmp__2346;
  goto llvm_cbe_tmp__2391;

llvm_cbe_tmp__2390:
  llvm_cbe_tmp__2347 = *((&llvm_cbe_tmp__2343->field24));
  *(&llvm_cbe_cppVar_1858) = (((unsigned char )(bool )(llvm_cbe_tmp__2347 == 1ull)));
  llvm_cbe_tmp__2348 = *(&llvm_cbe_cppVar_1858);
  if ((((((bool )llvm_cbe_tmp__2348&1u))&1))) {
    goto llvm_cbe_tmp__2392;
  } else {
    goto llvm_cbe_tmp__2393;
  }

llvm_cbe_tmp__2392:
  llvm_cbe_tmp__2349 = *((&llvm_cbe_tmp__2343->field36));
  *(&llvm_cbe_cppVar_1856) = llvm_cbe_tmp__2349;
  goto llvm_cbe_tmp__2394;

llvm_cbe_tmp__2393:
  llvm_cbe_tmp__2350 = *((&llvm_cbe_tmp__2343->field24));
  *(&llvm_cbe_cppVar_1861) = (((unsigned char )(bool )(llvm_cbe_tmp__2350 == 3ull)));
  llvm_cbe_tmp__2351 = *(&llvm_cbe_cppVar_1861);
  if ((((((bool )llvm_cbe_tmp__2351&1u))&1))) {
    goto llvm_cbe_tmp__2395;
  } else {
    goto llvm_cbe_tmp__2396;
  }

llvm_cbe_tmp__2395:
  llvm_cbe_tmp__2352 = *((&llvm_cbe_tmp__2343->field25));
  *(&llvm_cbe_cppVar_1864) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2352) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__2353 = *(&llvm_cbe_cppVar_1864);
  llvm_cbe_tmp__2354 = *((&llvm_cbe_tmp__2343->field41));
  *(&llvm_cbe_cppVar_1864) = (llvm_cbe_tmp__2353 & llvm_cbe_tmp__2354);
  llvm_cbe_tmp__2355 = *(&llvm_cbe_cppVar_1864);
  llvm_cbe_tmp__2356 = *((&llvm_cbe_tmp__2343->field16));
  *(&llvm_cbe_cppVar_1865) = (((unsigned char )(bool )(llvm_cbe_tmp__2355 == llvm_cbe_tmp__2356)));
  llvm_cbe_tmp__2357 = *((&llvm_cbe_tmp__2343->field25));
  *(&llvm_cbe_cppVar_1867) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2357) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__2358 = *(&llvm_cbe_cppVar_1867);
  llvm_cbe_tmp__2359 = *((&llvm_cbe_tmp__2343->field41));
  *(&llvm_cbe_cppVar_1867) = (llvm_cbe_tmp__2358 & llvm_cbe_tmp__2359);
  llvm_cbe_tmp__2360 = *(&llvm_cbe_cppVar_1867);
  *(&llvm_cbe_cppVar_1869) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__2360) >= ((signed long long )500ull))));
  llvm_cbe_tmp__2361 = *(&llvm_cbe_cppVar_1865);
  if ((((((bool )llvm_cbe_tmp__2361&1u))&1))) {
    llvm_cbe_tmp__2364__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__2397;
  } else {
    goto llvm_cbe_tmp__2398;
  }

llvm_cbe_tmp__2398:
  llvm_cbe_tmp__2362 = *(&llvm_cbe_cppVar_1869);
  llvm_cbe_tmp__2363 = ((((bool )llvm_cbe_tmp__2362&1u))&1);
  llvm_cbe_tmp__2364__PHI_TEMPORARY = llvm_cbe_tmp__2363;   /* for PHI node */
  goto llvm_cbe_tmp__2397;

llvm_cbe_tmp__2397:
  llvm_cbe_tmp__2364 = ((llvm_cbe_tmp__2364__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1870) = (((unsigned char )(bool )llvm_cbe_tmp__2364));
  llvm_cbe_tmp__2365 = *((&llvm_cbe_tmp__2343->field9));
  *(&llvm_cbe_cppVar_1872) = (((unsigned char )(bool )(llvm_cbe_tmp__2365 == 4ull)));
  llvm_cbe_tmp__2366 = *(&llvm_cbe_cppVar_1870);
  if ((((((bool )llvm_cbe_tmp__2366&1u))&1))) {
    goto llvm_cbe_tmp__2399;
  } else {
    llvm_cbe_tmp__2369__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2400;
  }

llvm_cbe_tmp__2399:
  llvm_cbe_tmp__2367 = *(&llvm_cbe_cppVar_1872);
  llvm_cbe_tmp__2368 = ((((bool )llvm_cbe_tmp__2367&1u))&1);
  llvm_cbe_tmp__2369__PHI_TEMPORARY = llvm_cbe_tmp__2368;   /* for PHI node */
  goto llvm_cbe_tmp__2400;

llvm_cbe_tmp__2400:
  llvm_cbe_tmp__2369 = ((llvm_cbe_tmp__2369__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1873) = (((unsigned char )(bool )llvm_cbe_tmp__2369));
  llvm_cbe_tmp__2370 = *(&llvm_cbe_cppVar_1873);
  if ((((((bool )llvm_cbe_tmp__2370&1u))&1))) {
    goto llvm_cbe_tmp__2401;
  } else {
    goto llvm_cbe_tmp__2402;
  }

llvm_cbe_tmp__2401:
  *(&llvm_cbe_cppVar_1862) = 0ull;
  goto llvm_cbe_tmp__2403;

llvm_cbe_tmp__2402:
  llvm_cbe_tmp__2371 = *((&llvm_cbe_tmp__2343->field36));
  *(&llvm_cbe_cppVar_1862) = llvm_cbe_tmp__2371;
  goto llvm_cbe_tmp__2403;

llvm_cbe_tmp__2403:
  llvm_cbe_tmp__2372 = *(&llvm_cbe_cppVar_1862);
  *(&llvm_cbe_cppVar_1859) = llvm_cbe_tmp__2372;
  goto llvm_cbe_tmp__2404;

llvm_cbe_tmp__2396:
  llvm_cbe_tmp__2373 = *((&llvm_cbe_tmp__2343->field24));
  *(&llvm_cbe_cppVar_1877) = (((unsigned char )(bool )(llvm_cbe_tmp__2373 == 2ull)));
  llvm_cbe_tmp__2374 = *(&llvm_cbe_cppVar_1877);
  if ((((((bool )llvm_cbe_tmp__2374&1u))&1))) {
    goto llvm_cbe_tmp__2405;
  } else {
    goto llvm_cbe_tmp__2406;
  }

llvm_cbe_tmp__2405:
  llvm_cbe_tmp__2375 = *((&llvm_cbe_tmp__2343->field39));
  *(&llvm_cbe_cppVar_1880) = (((unsigned char )(bool )(llvm_cbe_tmp__2375 == 0ull)));
  llvm_cbe_tmp__2376 = *((&llvm_cbe_tmp__2343->field36));
  *(&llvm_cbe_cppVar_1882) = (((unsigned char )(bool )(llvm_cbe_tmp__2376 == 1ull)));
  llvm_cbe_tmp__2377 = *(&llvm_cbe_cppVar_1880);
  if ((((((bool )llvm_cbe_tmp__2377&1u))&1))) {
    goto llvm_cbe_tmp__2407;
  } else {
    llvm_cbe_tmp__2380__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2408;
  }

llvm_cbe_tmp__2407:
  llvm_cbe_tmp__2378 = *(&llvm_cbe_cppVar_1882);
  llvm_cbe_tmp__2379 = ((((bool )llvm_cbe_tmp__2378&1u))&1);
  llvm_cbe_tmp__2380__PHI_TEMPORARY = llvm_cbe_tmp__2379;   /* for PHI node */
  goto llvm_cbe_tmp__2408;

llvm_cbe_tmp__2408:
  llvm_cbe_tmp__2380 = ((llvm_cbe_tmp__2380__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1883) = (((unsigned char )(bool )llvm_cbe_tmp__2380));
  llvm_cbe_tmp__2381 = *(&llvm_cbe_cppVar_1883);
  if ((((((bool )llvm_cbe_tmp__2381&1u))&1))) {
    goto llvm_cbe_tmp__2409;
  } else {
    goto llvm_cbe_tmp__2410;
  }

llvm_cbe_tmp__2409:
  *(&llvm_cbe_cppVar_1878) = 0ull;
  goto llvm_cbe_tmp__2411;

llvm_cbe_tmp__2410:
  llvm_cbe_tmp__2382 = *((&llvm_cbe_tmp__2343->field36));
  *(&llvm_cbe_cppVar_1878) = llvm_cbe_tmp__2382;
  goto llvm_cbe_tmp__2411;

llvm_cbe_tmp__2411:
  llvm_cbe_tmp__2383 = *(&llvm_cbe_cppVar_1878);
  *(&llvm_cbe_cppVar_1875) = llvm_cbe_tmp__2383;
  goto llvm_cbe_tmp__2412;

llvm_cbe_tmp__2406:
  llvm_cbe_tmp__2384 = *((&llvm_cbe_tmp__2343->field36));
  *(&llvm_cbe_cppVar_1875) = llvm_cbe_tmp__2384;
  goto llvm_cbe_tmp__2412;

llvm_cbe_tmp__2412:
  llvm_cbe_tmp__2385 = *(&llvm_cbe_cppVar_1875);
  *(&llvm_cbe_cppVar_1859) = llvm_cbe_tmp__2385;
  goto llvm_cbe_tmp__2404;

llvm_cbe_tmp__2404:
  llvm_cbe_tmp__2386 = *(&llvm_cbe_cppVar_1859);
  *(&llvm_cbe_cppVar_1856) = llvm_cbe_tmp__2386;
  goto llvm_cbe_tmp__2394;

llvm_cbe_tmp__2394:
  llvm_cbe_tmp__2387 = *(&llvm_cbe_cppVar_1856);
  *(&llvm_cbe_cppVar_1853) = llvm_cbe_tmp__2387;
  goto llvm_cbe_tmp__2391;

llvm_cbe_tmp__2391:
  llvm_cbe_tmp__2388 = *(&llvm_cbe_cppVar_1853);
  return llvm_cbe_tmp__2388;
}


unsigned long long _ZN13model_predict21cppUpdateFun_wr_indexElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__2413;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2414;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2415;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2416;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2417;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2418;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2419;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2420;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2421;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2422;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2423;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2424;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1886;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1887;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1889;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1890;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1892;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1893;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1911;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1912;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1895;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1896;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1897;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1898;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1899;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1900;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1901;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1902;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1903;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1904;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1905;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1907;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1908;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1909;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1894;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1906;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1910;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1891;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1888;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1885;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__2425;
  unsigned long long llvm_cbe_tmp__2426;
  unsigned char llvm_cbe_tmp__2427;
  unsigned long long llvm_cbe_tmp__2428;
  unsigned long long llvm_cbe_tmp__2429;
  unsigned char llvm_cbe_tmp__2430;
  unsigned long long llvm_cbe_tmp__2431;
  unsigned long long llvm_cbe_tmp__2432;
  unsigned char llvm_cbe_tmp__2433;
  unsigned long long llvm_cbe_tmp__2434;
  unsigned long long llvm_cbe_tmp__2435;
  unsigned long long llvm_cbe_tmp__2436;
  unsigned long long llvm_cbe_tmp__2437;
  unsigned long long llvm_cbe_tmp__2438;
  unsigned long long llvm_cbe_tmp__2439;
  unsigned long long llvm_cbe_tmp__2440;
  unsigned long long llvm_cbe_tmp__2441;
  unsigned long long llvm_cbe_tmp__2442;
  unsigned char llvm_cbe_tmp__2443;
  unsigned char llvm_cbe_tmp__2444;
  bool llvm_cbe_tmp__2445;
  bool llvm_cbe_tmp__2446;
  bool llvm_cbe_tmp__2446__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__2447;
  unsigned char llvm_cbe_tmp__2448;
  unsigned char llvm_cbe_tmp__2449;
  bool llvm_cbe_tmp__2450;
  bool llvm_cbe_tmp__2451;
  bool llvm_cbe_tmp__2451__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2452;
  unsigned long long llvm_cbe_tmp__2453;
  unsigned long long llvm_cbe_tmp__2454;
  unsigned long long llvm_cbe_tmp__2455;
  unsigned long long llvm_cbe_tmp__2456;
  unsigned long long llvm_cbe_tmp__2457;
  unsigned long long llvm_cbe_tmp__2458;
  unsigned long long llvm_cbe_tmp__2459;
  unsigned long long llvm_cbe_tmp__2460;
  unsigned long long llvm_cbe_tmp__2461;
  unsigned long long llvm_cbe_tmp__2462;
  unsigned long long llvm_cbe_tmp__2463;
  unsigned long long llvm_cbe_tmp__2464;
  unsigned long long llvm_cbe_tmp__2465;
  unsigned long long llvm_cbe_tmp__2466;
  unsigned long long llvm_cbe_tmp__2467;
  unsigned long long llvm_cbe_tmp__2468;
  unsigned long long llvm_cbe_tmp__2469;
  unsigned long long llvm_cbe_tmp__2470;
  unsigned long long llvm_cbe_tmp__2471;

  *(&llvm_cbe_tmp__2413) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2414) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__2415) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__2416) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__2417) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__2418) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__2419) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__2420) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__2421) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__2422) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__2423) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__2424) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__2425 = *(&llvm_cbe_tmp__2413);
  llvm_cbe_tmp__2426 = *((&llvm_cbe_tmp__2425->field24));
  *(&llvm_cbe_cppVar_1887) = (((unsigned char )(bool )(llvm_cbe_tmp__2426 == 0ull)));
  llvm_cbe_tmp__2427 = *(&llvm_cbe_cppVar_1887);
  if ((((((bool )llvm_cbe_tmp__2427&1u))&1))) {
    goto llvm_cbe_tmp__2472;
  } else {
    goto llvm_cbe_tmp__2473;
  }

llvm_cbe_tmp__2472:
  llvm_cbe_tmp__2428 = *((&llvm_cbe_tmp__2425->field37));
  *(&llvm_cbe_cppVar_1885) = llvm_cbe_tmp__2428;
  goto llvm_cbe_tmp__2474;

llvm_cbe_tmp__2473:
  llvm_cbe_tmp__2429 = *((&llvm_cbe_tmp__2425->field24));
  *(&llvm_cbe_cppVar_1890) = (((unsigned char )(bool )(llvm_cbe_tmp__2429 == 1ull)));
  llvm_cbe_tmp__2430 = *(&llvm_cbe_cppVar_1890);
  if ((((((bool )llvm_cbe_tmp__2430&1u))&1))) {
    goto llvm_cbe_tmp__2475;
  } else {
    goto llvm_cbe_tmp__2476;
  }

llvm_cbe_tmp__2475:
  llvm_cbe_tmp__2431 = *((&llvm_cbe_tmp__2425->field37));
  *(&llvm_cbe_cppVar_1888) = llvm_cbe_tmp__2431;
  goto llvm_cbe_tmp__2477;

llvm_cbe_tmp__2476:
  llvm_cbe_tmp__2432 = *((&llvm_cbe_tmp__2425->field24));
  *(&llvm_cbe_cppVar_1893) = (((unsigned char )(bool )(llvm_cbe_tmp__2432 == 3ull)));
  llvm_cbe_tmp__2433 = *(&llvm_cbe_cppVar_1893);
  if ((((((bool )llvm_cbe_tmp__2433&1u))&1))) {
    goto llvm_cbe_tmp__2478;
  } else {
    goto llvm_cbe_tmp__2479;
  }

llvm_cbe_tmp__2478:
  llvm_cbe_tmp__2434 = *((&llvm_cbe_tmp__2425->field25));
  *(&llvm_cbe_cppVar_1896) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2434) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__2435 = *(&llvm_cbe_cppVar_1896);
  llvm_cbe_tmp__2436 = *((&llvm_cbe_tmp__2425->field41));
  *(&llvm_cbe_cppVar_1896) = (llvm_cbe_tmp__2435 & llvm_cbe_tmp__2436);
  llvm_cbe_tmp__2437 = *(&llvm_cbe_cppVar_1896);
  llvm_cbe_tmp__2438 = *((&llvm_cbe_tmp__2425->field16));
  *(&llvm_cbe_cppVar_1897) = (((unsigned char )(bool )(llvm_cbe_tmp__2437 == llvm_cbe_tmp__2438)));
  llvm_cbe_tmp__2439 = *((&llvm_cbe_tmp__2425->field25));
  *(&llvm_cbe_cppVar_1899) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2439) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__2440 = *(&llvm_cbe_cppVar_1899);
  llvm_cbe_tmp__2441 = *((&llvm_cbe_tmp__2425->field41));
  *(&llvm_cbe_cppVar_1899) = (llvm_cbe_tmp__2440 & llvm_cbe_tmp__2441);
  llvm_cbe_tmp__2442 = *(&llvm_cbe_cppVar_1899);
  *(&llvm_cbe_cppVar_1901) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__2442) >= ((signed long long )500ull))));
  llvm_cbe_tmp__2443 = *(&llvm_cbe_cppVar_1897);
  if ((((((bool )llvm_cbe_tmp__2443&1u))&1))) {
    llvm_cbe_tmp__2446__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__2480;
  } else {
    goto llvm_cbe_tmp__2481;
  }

llvm_cbe_tmp__2481:
  llvm_cbe_tmp__2444 = *(&llvm_cbe_cppVar_1901);
  llvm_cbe_tmp__2445 = ((((bool )llvm_cbe_tmp__2444&1u))&1);
  llvm_cbe_tmp__2446__PHI_TEMPORARY = llvm_cbe_tmp__2445;   /* for PHI node */
  goto llvm_cbe_tmp__2480;

llvm_cbe_tmp__2480:
  llvm_cbe_tmp__2446 = ((llvm_cbe_tmp__2446__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1902) = (((unsigned char )(bool )llvm_cbe_tmp__2446));
  llvm_cbe_tmp__2447 = *((&llvm_cbe_tmp__2425->field9));
  *(&llvm_cbe_cppVar_1904) = (((unsigned char )(bool )(llvm_cbe_tmp__2447 == 4ull)));
  llvm_cbe_tmp__2448 = *(&llvm_cbe_cppVar_1902);
  if ((((((bool )llvm_cbe_tmp__2448&1u))&1))) {
    goto llvm_cbe_tmp__2482;
  } else {
    llvm_cbe_tmp__2451__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2483;
  }

llvm_cbe_tmp__2482:
  llvm_cbe_tmp__2449 = *(&llvm_cbe_cppVar_1904);
  llvm_cbe_tmp__2450 = ((((bool )llvm_cbe_tmp__2449&1u))&1);
  llvm_cbe_tmp__2451__PHI_TEMPORARY = llvm_cbe_tmp__2450;   /* for PHI node */
  goto llvm_cbe_tmp__2483;

llvm_cbe_tmp__2483:
  llvm_cbe_tmp__2451 = ((llvm_cbe_tmp__2451__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1905) = (((unsigned char )(bool )llvm_cbe_tmp__2451));
  llvm_cbe_tmp__2452 = *(&llvm_cbe_cppVar_1905);
  if ((((((bool )llvm_cbe_tmp__2452&1u))&1))) {
    goto llvm_cbe_tmp__2484;
  } else {
    goto llvm_cbe_tmp__2485;
  }

llvm_cbe_tmp__2484:
  llvm_cbe_tmp__2453 = *((&llvm_cbe_tmp__2425->field13));
  llvm_cbe_tmp__2454 = *((&llvm_cbe_tmp__2425->field41));
  *(&llvm_cbe_cppVar_1906) = (llvm_cbe_tmp__2453 & llvm_cbe_tmp__2454);
  llvm_cbe_tmp__2455 = *(&llvm_cbe_cppVar_1906);
  llvm_cbe_tmp__2456 = *((&llvm_cbe_tmp__2425->field45));
  *(&llvm_cbe_cppVar_1907) = (llvm_cbe_tmp__2455 & llvm_cbe_tmp__2456);
  llvm_cbe_tmp__2457 = *((&llvm_cbe_tmp__2425->field7));
  llvm_cbe_tmp__2458 = *((&llvm_cbe_tmp__2425->field41));
  *(&llvm_cbe_cppVar_1908) = (llvm_cbe_tmp__2457 & llvm_cbe_tmp__2458);
  llvm_cbe_tmp__2459 = *(&llvm_cbe_cppVar_1907);
  llvm_cbe_tmp__2460 = *(&llvm_cbe_cppVar_1908);
  *(&llvm_cbe_cppVar_1909) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2459) * ((unsigned long long )llvm_cbe_tmp__2460))));
  llvm_cbe_tmp__2461 = *(&llvm_cbe_cppVar_1909);
  llvm_cbe_tmp__2462 = *((&llvm_cbe_tmp__2425->field45));
  *(&llvm_cbe_cppVar_1909) = (llvm_cbe_tmp__2461 & llvm_cbe_tmp__2462);
  llvm_cbe_tmp__2463 = *(&llvm_cbe_cppVar_1909);
  *(&llvm_cbe_cppVar_1894) = llvm_cbe_tmp__2463;
  goto llvm_cbe_tmp__2486;

llvm_cbe_tmp__2485:
  llvm_cbe_tmp__2464 = *((&llvm_cbe_tmp__2425->field37));
  *(&llvm_cbe_cppVar_1894) = llvm_cbe_tmp__2464;
  goto llvm_cbe_tmp__2486;

llvm_cbe_tmp__2486:
  llvm_cbe_tmp__2465 = *(&llvm_cbe_cppVar_1894);
  *(&llvm_cbe_cppVar_1891) = llvm_cbe_tmp__2465;
  goto llvm_cbe_tmp__2487;

llvm_cbe_tmp__2479:
  llvm_cbe_tmp__2466 = *((&llvm_cbe_tmp__2425->field24));
  *(&llvm_cbe_cppVar_1912) = (((unsigned char )(bool )(llvm_cbe_tmp__2466 == 2ull)));
  llvm_cbe_tmp__2467 = *((&llvm_cbe_tmp__2425->field37));
  *(&llvm_cbe_cppVar_1910) = llvm_cbe_tmp__2467;
  llvm_cbe_tmp__2468 = *(&llvm_cbe_cppVar_1910);
  *(&llvm_cbe_cppVar_1891) = llvm_cbe_tmp__2468;
  goto llvm_cbe_tmp__2487;

llvm_cbe_tmp__2487:
  llvm_cbe_tmp__2469 = *(&llvm_cbe_cppVar_1891);
  *(&llvm_cbe_cppVar_1888) = llvm_cbe_tmp__2469;
  goto llvm_cbe_tmp__2477;

llvm_cbe_tmp__2477:
  llvm_cbe_tmp__2470 = *(&llvm_cbe_cppVar_1888);
  *(&llvm_cbe_cppVar_1885) = llvm_cbe_tmp__2470;
  goto llvm_cbe_tmp__2474;

llvm_cbe_tmp__2474:
  llvm_cbe_tmp__2471 = *(&llvm_cbe_cppVar_1885);
  return llvm_cbe_tmp__2471;
}


unsigned long long _ZN13model_predict22cppUpdateFun_wr_lengthElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__2488;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2489;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2490;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2491;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2492;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2493;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2494;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2495;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2496;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2497;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2498;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2499;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1915;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1916;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1918;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1919;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1921;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1922;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1938;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1939;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1924;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1925;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1926;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1927;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1928;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1929;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1930;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1931;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1932;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1933;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1934;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1936;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1923;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1935;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1937;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1920;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1917;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1914;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__2500;
  unsigned long long llvm_cbe_tmp__2501;
  unsigned char llvm_cbe_tmp__2502;
  unsigned long long llvm_cbe_tmp__2503;
  unsigned long long llvm_cbe_tmp__2504;
  unsigned char llvm_cbe_tmp__2505;
  unsigned long long llvm_cbe_tmp__2506;
  unsigned long long llvm_cbe_tmp__2507;
  unsigned char llvm_cbe_tmp__2508;
  unsigned long long llvm_cbe_tmp__2509;
  unsigned long long llvm_cbe_tmp__2510;
  unsigned long long llvm_cbe_tmp__2511;
  unsigned long long llvm_cbe_tmp__2512;
  unsigned long long llvm_cbe_tmp__2513;
  unsigned long long llvm_cbe_tmp__2514;
  unsigned long long llvm_cbe_tmp__2515;
  unsigned long long llvm_cbe_tmp__2516;
  unsigned long long llvm_cbe_tmp__2517;
  unsigned char llvm_cbe_tmp__2518;
  unsigned char llvm_cbe_tmp__2519;
  bool llvm_cbe_tmp__2520;
  bool llvm_cbe_tmp__2521;
  bool llvm_cbe_tmp__2521__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__2522;
  unsigned char llvm_cbe_tmp__2523;
  unsigned char llvm_cbe_tmp__2524;
  bool llvm_cbe_tmp__2525;
  bool llvm_cbe_tmp__2526;
  bool llvm_cbe_tmp__2526__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2527;
  unsigned long long llvm_cbe_tmp__2528;
  unsigned long long llvm_cbe_tmp__2529;
  unsigned long long llvm_cbe_tmp__2530;
  unsigned long long llvm_cbe_tmp__2531;
  unsigned long long llvm_cbe_tmp__2532;
  unsigned long long llvm_cbe_tmp__2533;
  unsigned long long llvm_cbe_tmp__2534;
  unsigned long long llvm_cbe_tmp__2535;
  unsigned long long llvm_cbe_tmp__2536;
  unsigned long long llvm_cbe_tmp__2537;
  unsigned long long llvm_cbe_tmp__2538;
  unsigned long long llvm_cbe_tmp__2539;
  unsigned long long llvm_cbe_tmp__2540;

  *(&llvm_cbe_tmp__2488) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2489) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__2490) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__2491) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__2492) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__2493) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__2494) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__2495) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__2496) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__2497) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__2498) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__2499) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__2500 = *(&llvm_cbe_tmp__2488);
  llvm_cbe_tmp__2501 = *((&llvm_cbe_tmp__2500->field24));
  *(&llvm_cbe_cppVar_1916) = (((unsigned char )(bool )(llvm_cbe_tmp__2501 == 0ull)));
  llvm_cbe_tmp__2502 = *(&llvm_cbe_cppVar_1916);
  if ((((((bool )llvm_cbe_tmp__2502&1u))&1))) {
    goto llvm_cbe_tmp__2541;
  } else {
    goto llvm_cbe_tmp__2542;
  }

llvm_cbe_tmp__2541:
  llvm_cbe_tmp__2503 = *((&llvm_cbe_tmp__2500->field38));
  *(&llvm_cbe_cppVar_1914) = llvm_cbe_tmp__2503;
  goto llvm_cbe_tmp__2543;

llvm_cbe_tmp__2542:
  llvm_cbe_tmp__2504 = *((&llvm_cbe_tmp__2500->field24));
  *(&llvm_cbe_cppVar_1919) = (((unsigned char )(bool )(llvm_cbe_tmp__2504 == 1ull)));
  llvm_cbe_tmp__2505 = *(&llvm_cbe_cppVar_1919);
  if ((((((bool )llvm_cbe_tmp__2505&1u))&1))) {
    goto llvm_cbe_tmp__2544;
  } else {
    goto llvm_cbe_tmp__2545;
  }

llvm_cbe_tmp__2544:
  llvm_cbe_tmp__2506 = *((&llvm_cbe_tmp__2500->field38));
  *(&llvm_cbe_cppVar_1917) = llvm_cbe_tmp__2506;
  goto llvm_cbe_tmp__2546;

llvm_cbe_tmp__2545:
  llvm_cbe_tmp__2507 = *((&llvm_cbe_tmp__2500->field24));
  *(&llvm_cbe_cppVar_1922) = (((unsigned char )(bool )(llvm_cbe_tmp__2507 == 3ull)));
  llvm_cbe_tmp__2508 = *(&llvm_cbe_cppVar_1922);
  if ((((((bool )llvm_cbe_tmp__2508&1u))&1))) {
    goto llvm_cbe_tmp__2547;
  } else {
    goto llvm_cbe_tmp__2548;
  }

llvm_cbe_tmp__2547:
  llvm_cbe_tmp__2509 = *((&llvm_cbe_tmp__2500->field25));
  *(&llvm_cbe_cppVar_1925) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2509) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__2510 = *(&llvm_cbe_cppVar_1925);
  llvm_cbe_tmp__2511 = *((&llvm_cbe_tmp__2500->field41));
  *(&llvm_cbe_cppVar_1925) = (llvm_cbe_tmp__2510 & llvm_cbe_tmp__2511);
  llvm_cbe_tmp__2512 = *(&llvm_cbe_cppVar_1925);
  llvm_cbe_tmp__2513 = *((&llvm_cbe_tmp__2500->field16));
  *(&llvm_cbe_cppVar_1926) = (((unsigned char )(bool )(llvm_cbe_tmp__2512 == llvm_cbe_tmp__2513)));
  llvm_cbe_tmp__2514 = *((&llvm_cbe_tmp__2500->field25));
  *(&llvm_cbe_cppVar_1928) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2514) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__2515 = *(&llvm_cbe_cppVar_1928);
  llvm_cbe_tmp__2516 = *((&llvm_cbe_tmp__2500->field41));
  *(&llvm_cbe_cppVar_1928) = (llvm_cbe_tmp__2515 & llvm_cbe_tmp__2516);
  llvm_cbe_tmp__2517 = *(&llvm_cbe_cppVar_1928);
  *(&llvm_cbe_cppVar_1930) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__2517) >= ((signed long long )500ull))));
  llvm_cbe_tmp__2518 = *(&llvm_cbe_cppVar_1926);
  if ((((((bool )llvm_cbe_tmp__2518&1u))&1))) {
    llvm_cbe_tmp__2521__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__2549;
  } else {
    goto llvm_cbe_tmp__2550;
  }

llvm_cbe_tmp__2550:
  llvm_cbe_tmp__2519 = *(&llvm_cbe_cppVar_1930);
  llvm_cbe_tmp__2520 = ((((bool )llvm_cbe_tmp__2519&1u))&1);
  llvm_cbe_tmp__2521__PHI_TEMPORARY = llvm_cbe_tmp__2520;   /* for PHI node */
  goto llvm_cbe_tmp__2549;

llvm_cbe_tmp__2549:
  llvm_cbe_tmp__2521 = ((llvm_cbe_tmp__2521__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1931) = (((unsigned char )(bool )llvm_cbe_tmp__2521));
  llvm_cbe_tmp__2522 = *((&llvm_cbe_tmp__2500->field9));
  *(&llvm_cbe_cppVar_1933) = (((unsigned char )(bool )(llvm_cbe_tmp__2522 == 4ull)));
  llvm_cbe_tmp__2523 = *(&llvm_cbe_cppVar_1931);
  if ((((((bool )llvm_cbe_tmp__2523&1u))&1))) {
    goto llvm_cbe_tmp__2551;
  } else {
    llvm_cbe_tmp__2526__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2552;
  }

llvm_cbe_tmp__2551:
  llvm_cbe_tmp__2524 = *(&llvm_cbe_cppVar_1933);
  llvm_cbe_tmp__2525 = ((((bool )llvm_cbe_tmp__2524&1u))&1);
  llvm_cbe_tmp__2526__PHI_TEMPORARY = llvm_cbe_tmp__2525;   /* for PHI node */
  goto llvm_cbe_tmp__2552;

llvm_cbe_tmp__2552:
  llvm_cbe_tmp__2526 = ((llvm_cbe_tmp__2526__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1934) = (((unsigned char )(bool )llvm_cbe_tmp__2526));
  llvm_cbe_tmp__2527 = *(&llvm_cbe_cppVar_1934);
  if ((((((bool )llvm_cbe_tmp__2527&1u))&1))) {
    goto llvm_cbe_tmp__2553;
  } else {
    goto llvm_cbe_tmp__2554;
  }

llvm_cbe_tmp__2553:
  llvm_cbe_tmp__2528 = *((&llvm_cbe_tmp__2500->field13));
  llvm_cbe_tmp__2529 = *((&llvm_cbe_tmp__2500->field41));
  *(&llvm_cbe_cppVar_1935) = (llvm_cbe_tmp__2528 & llvm_cbe_tmp__2529);
  llvm_cbe_tmp__2530 = *(&llvm_cbe_cppVar_1935);
  llvm_cbe_tmp__2531 = *((&llvm_cbe_tmp__2500->field45));
  *(&llvm_cbe_cppVar_1936) = (llvm_cbe_tmp__2530 & llvm_cbe_tmp__2531);
  llvm_cbe_tmp__2532 = *(&llvm_cbe_cppVar_1936);
  *(&llvm_cbe_cppVar_1923) = llvm_cbe_tmp__2532;
  goto llvm_cbe_tmp__2555;

llvm_cbe_tmp__2554:
  llvm_cbe_tmp__2533 = *((&llvm_cbe_tmp__2500->field38));
  *(&llvm_cbe_cppVar_1923) = llvm_cbe_tmp__2533;
  goto llvm_cbe_tmp__2555;

llvm_cbe_tmp__2555:
  llvm_cbe_tmp__2534 = *(&llvm_cbe_cppVar_1923);
  *(&llvm_cbe_cppVar_1920) = llvm_cbe_tmp__2534;
  goto llvm_cbe_tmp__2556;

llvm_cbe_tmp__2548:
  llvm_cbe_tmp__2535 = *((&llvm_cbe_tmp__2500->field24));
  *(&llvm_cbe_cppVar_1939) = (((unsigned char )(bool )(llvm_cbe_tmp__2535 == 2ull)));
  llvm_cbe_tmp__2536 = *((&llvm_cbe_tmp__2500->field38));
  *(&llvm_cbe_cppVar_1937) = llvm_cbe_tmp__2536;
  llvm_cbe_tmp__2537 = *(&llvm_cbe_cppVar_1937);
  *(&llvm_cbe_cppVar_1920) = llvm_cbe_tmp__2537;
  goto llvm_cbe_tmp__2556;

llvm_cbe_tmp__2556:
  llvm_cbe_tmp__2538 = *(&llvm_cbe_cppVar_1920);
  *(&llvm_cbe_cppVar_1917) = llvm_cbe_tmp__2538;
  goto llvm_cbe_tmp__2546;

llvm_cbe_tmp__2546:
  llvm_cbe_tmp__2539 = *(&llvm_cbe_cppVar_1917);
  *(&llvm_cbe_cppVar_1914) = llvm_cbe_tmp__2539;
  goto llvm_cbe_tmp__2543;

llvm_cbe_tmp__2543:
  llvm_cbe_tmp__2540 = *(&llvm_cbe_cppVar_1914);
  return llvm_cbe_tmp__2540;
}


unsigned long long _ZN13model_predict23cppUpdateFun_wr_requestElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__2557;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2558;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2559;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2560;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2561;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2562;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2563;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2564;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2565;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2566;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2567;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2568;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1962;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1942;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1943;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1945;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1946;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1948;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1949;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1964;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1965;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1951;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1952;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1953;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1954;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1955;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1956;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1957;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1958;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1959;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1960;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1961;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1950;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1963;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1947;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1944;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1941;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__2569;
  unsigned long long llvm_cbe_tmp__2570;
  unsigned char llvm_cbe_tmp__2571;
  unsigned long long llvm_cbe_tmp__2572;
  unsigned long long llvm_cbe_tmp__2573;
  unsigned char llvm_cbe_tmp__2574;
  unsigned long long llvm_cbe_tmp__2575;
  unsigned long long llvm_cbe_tmp__2576;
  unsigned char llvm_cbe_tmp__2577;
  unsigned long long llvm_cbe_tmp__2578;
  unsigned long long llvm_cbe_tmp__2579;
  unsigned long long llvm_cbe_tmp__2580;
  unsigned long long llvm_cbe_tmp__2581;
  unsigned long long llvm_cbe_tmp__2582;
  unsigned long long llvm_cbe_tmp__2583;
  unsigned long long llvm_cbe_tmp__2584;
  unsigned long long llvm_cbe_tmp__2585;
  unsigned long long llvm_cbe_tmp__2586;
  unsigned char llvm_cbe_tmp__2587;
  unsigned char llvm_cbe_tmp__2588;
  bool llvm_cbe_tmp__2589;
  bool llvm_cbe_tmp__2590;
  bool llvm_cbe_tmp__2590__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__2591;
  unsigned char llvm_cbe_tmp__2592;
  unsigned char llvm_cbe_tmp__2593;
  bool llvm_cbe_tmp__2594;
  bool llvm_cbe_tmp__2595;
  bool llvm_cbe_tmp__2595__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2596;
  unsigned long long llvm_cbe_tmp__2597;
  unsigned long long llvm_cbe_tmp__2598;
  unsigned long long llvm_cbe_tmp__2599;
  unsigned long long llvm_cbe_tmp__2600;
  unsigned long long llvm_cbe_tmp__2601;
  unsigned long long llvm_cbe_tmp__2602;
  unsigned long long llvm_cbe_tmp__2603;
  unsigned long long llvm_cbe_tmp__2604;

  *(&llvm_cbe_tmp__2557) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2558) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__2559) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__2560) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__2561) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__2562) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__2563) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__2564) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__2565) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__2566) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__2567) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__2568) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__2569 = *(&llvm_cbe_tmp__2557);
  llvm_cbe_tmp__2570 = *((&llvm_cbe_tmp__2569->field24));
  *(&llvm_cbe_cppVar_1943) = (((unsigned char )(bool )(llvm_cbe_tmp__2570 == 0ull)));
  llvm_cbe_tmp__2571 = *(&llvm_cbe_cppVar_1943);
  if ((((((bool )llvm_cbe_tmp__2571&1u))&1))) {
    goto llvm_cbe_tmp__2605;
  } else {
    goto llvm_cbe_tmp__2606;
  }

llvm_cbe_tmp__2605:
  llvm_cbe_tmp__2572 = *((&llvm_cbe_tmp__2569->field39));
  *(&llvm_cbe_cppVar_1941) = llvm_cbe_tmp__2572;
  goto llvm_cbe_tmp__2607;

llvm_cbe_tmp__2606:
  llvm_cbe_tmp__2573 = *((&llvm_cbe_tmp__2569->field24));
  *(&llvm_cbe_cppVar_1946) = (((unsigned char )(bool )(llvm_cbe_tmp__2573 == 1ull)));
  llvm_cbe_tmp__2574 = *(&llvm_cbe_cppVar_1946);
  if ((((((bool )llvm_cbe_tmp__2574&1u))&1))) {
    goto llvm_cbe_tmp__2608;
  } else {
    goto llvm_cbe_tmp__2609;
  }

llvm_cbe_tmp__2608:
  llvm_cbe_tmp__2575 = *((&llvm_cbe_tmp__2569->field39));
  *(&llvm_cbe_cppVar_1944) = llvm_cbe_tmp__2575;
  goto llvm_cbe_tmp__2610;

llvm_cbe_tmp__2609:
  llvm_cbe_tmp__2576 = *((&llvm_cbe_tmp__2569->field24));
  *(&llvm_cbe_cppVar_1949) = (((unsigned char )(bool )(llvm_cbe_tmp__2576 == 3ull)));
  llvm_cbe_tmp__2577 = *(&llvm_cbe_cppVar_1949);
  if ((((((bool )llvm_cbe_tmp__2577&1u))&1))) {
    goto llvm_cbe_tmp__2611;
  } else {
    goto llvm_cbe_tmp__2612;
  }

llvm_cbe_tmp__2611:
  llvm_cbe_tmp__2578 = *((&llvm_cbe_tmp__2569->field25));
  *(&llvm_cbe_cppVar_1952) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2578) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__2579 = *(&llvm_cbe_cppVar_1952);
  llvm_cbe_tmp__2580 = *((&llvm_cbe_tmp__2569->field41));
  *(&llvm_cbe_cppVar_1952) = (llvm_cbe_tmp__2579 & llvm_cbe_tmp__2580);
  llvm_cbe_tmp__2581 = *(&llvm_cbe_cppVar_1952);
  llvm_cbe_tmp__2582 = *((&llvm_cbe_tmp__2569->field16));
  *(&llvm_cbe_cppVar_1953) = (((unsigned char )(bool )(llvm_cbe_tmp__2581 == llvm_cbe_tmp__2582)));
  llvm_cbe_tmp__2583 = *((&llvm_cbe_tmp__2569->field25));
  *(&llvm_cbe_cppVar_1955) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2583) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__2584 = *(&llvm_cbe_cppVar_1955);
  llvm_cbe_tmp__2585 = *((&llvm_cbe_tmp__2569->field41));
  *(&llvm_cbe_cppVar_1955) = (llvm_cbe_tmp__2584 & llvm_cbe_tmp__2585);
  llvm_cbe_tmp__2586 = *(&llvm_cbe_cppVar_1955);
  *(&llvm_cbe_cppVar_1957) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__2586) >= ((signed long long )500ull))));
  llvm_cbe_tmp__2587 = *(&llvm_cbe_cppVar_1953);
  if ((((((bool )llvm_cbe_tmp__2587&1u))&1))) {
    llvm_cbe_tmp__2590__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__2613;
  } else {
    goto llvm_cbe_tmp__2614;
  }

llvm_cbe_tmp__2614:
  llvm_cbe_tmp__2588 = *(&llvm_cbe_cppVar_1957);
  llvm_cbe_tmp__2589 = ((((bool )llvm_cbe_tmp__2588&1u))&1);
  llvm_cbe_tmp__2590__PHI_TEMPORARY = llvm_cbe_tmp__2589;   /* for PHI node */
  goto llvm_cbe_tmp__2613;

llvm_cbe_tmp__2613:
  llvm_cbe_tmp__2590 = ((llvm_cbe_tmp__2590__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1958) = (((unsigned char )(bool )llvm_cbe_tmp__2590));
  llvm_cbe_tmp__2591 = *((&llvm_cbe_tmp__2569->field9));
  *(&llvm_cbe_cppVar_1960) = (((unsigned char )(bool )(llvm_cbe_tmp__2591 == 4ull)));
  llvm_cbe_tmp__2592 = *(&llvm_cbe_cppVar_1958);
  if ((((((bool )llvm_cbe_tmp__2592&1u))&1))) {
    goto llvm_cbe_tmp__2615;
  } else {
    llvm_cbe_tmp__2595__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2616;
  }

llvm_cbe_tmp__2615:
  llvm_cbe_tmp__2593 = *(&llvm_cbe_cppVar_1960);
  llvm_cbe_tmp__2594 = ((((bool )llvm_cbe_tmp__2593&1u))&1);
  llvm_cbe_tmp__2595__PHI_TEMPORARY = llvm_cbe_tmp__2594;   /* for PHI node */
  goto llvm_cbe_tmp__2616;

llvm_cbe_tmp__2616:
  llvm_cbe_tmp__2595 = ((llvm_cbe_tmp__2595__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1961) = (((unsigned char )(bool )llvm_cbe_tmp__2595));
  llvm_cbe_tmp__2596 = *(&llvm_cbe_cppVar_1961);
  if ((((((bool )llvm_cbe_tmp__2596&1u))&1))) {
    goto llvm_cbe_tmp__2617;
  } else {
    goto llvm_cbe_tmp__2618;
  }

llvm_cbe_tmp__2617:
  *(&llvm_cbe_cppVar_1950) = 1ull;
  goto llvm_cbe_tmp__2619;

llvm_cbe_tmp__2618:
  llvm_cbe_tmp__2597 = *((&llvm_cbe_tmp__2569->field39));
  *(&llvm_cbe_cppVar_1950) = llvm_cbe_tmp__2597;
  goto llvm_cbe_tmp__2619;

llvm_cbe_tmp__2619:
  llvm_cbe_tmp__2598 = *(&llvm_cbe_cppVar_1950);
  *(&llvm_cbe_cppVar_1947) = llvm_cbe_tmp__2598;
  goto llvm_cbe_tmp__2620;

llvm_cbe_tmp__2612:
  llvm_cbe_tmp__2599 = *((&llvm_cbe_tmp__2569->field24));
  *(&llvm_cbe_cppVar_1965) = (((unsigned char )(bool )(llvm_cbe_tmp__2599 == 2ull)));
  llvm_cbe_tmp__2600 = *((&llvm_cbe_tmp__2569->field39));
  *(&llvm_cbe_cppVar_1963) = llvm_cbe_tmp__2600;
  llvm_cbe_tmp__2601 = *(&llvm_cbe_cppVar_1963);
  *(&llvm_cbe_cppVar_1947) = llvm_cbe_tmp__2601;
  goto llvm_cbe_tmp__2620;

llvm_cbe_tmp__2620:
  llvm_cbe_tmp__2602 = *(&llvm_cbe_cppVar_1947);
  *(&llvm_cbe_cppVar_1944) = llvm_cbe_tmp__2602;
  goto llvm_cbe_tmp__2610;

llvm_cbe_tmp__2610:
  llvm_cbe_tmp__2603 = *(&llvm_cbe_cppVar_1944);
  *(&llvm_cbe_cppVar_1941) = llvm_cbe_tmp__2603;
  goto llvm_cbe_tmp__2607;

llvm_cbe_tmp__2607:
  llvm_cbe_tmp__2604 = *(&llvm_cbe_cppVar_1941);
  return llvm_cbe_tmp__2604;
}


void _ZN13model_predict6updateElllllllllll(struct l_class_OC_model_predict *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__2621;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2622;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2623;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2624;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2625;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2626;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2627;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2628;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2629;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2630;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2631;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2632;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1299;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1323;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1353;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1377;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1426;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1479;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1522;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1539;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1601;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1665;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1722;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1771;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1788;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1828;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1852;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1884;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1913;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1940;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1966;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_2021;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_2056;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__2633;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2634;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_2065;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_2103;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_2165;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2635;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__2636;
  unsigned long long llvm_cbe_tmp__2637;
  unsigned long long llvm_cbe_tmp__2638;
  unsigned long long llvm_cbe_tmp__2639;
  unsigned long long llvm_cbe_tmp__2640;
  unsigned long long llvm_cbe_tmp__2641;
  unsigned long long llvm_cbe_tmp__2642;
  unsigned long long llvm_cbe_tmp__2643;
  unsigned long long llvm_cbe_tmp__2644;
  unsigned long long llvm_cbe_tmp__2645;
  unsigned long long llvm_cbe_tmp__2646;
  unsigned long long llvm_cbe_tmp__2647;
  unsigned long long llvm_cbe_tmp__2648;
  unsigned long long llvm_cbe_tmp__2649;
  unsigned long long llvm_cbe_tmp__2650;
  unsigned long long llvm_cbe_tmp__2651;
  unsigned long long llvm_cbe_tmp__2652;
  unsigned long long llvm_cbe_tmp__2653;
  unsigned long long llvm_cbe_tmp__2654;
  unsigned long long llvm_cbe_tmp__2655;
  unsigned long long llvm_cbe_tmp__2656;
  unsigned long long llvm_cbe_tmp__2657;
  unsigned long long llvm_cbe_tmp__2658;
  unsigned long long llvm_cbe_tmp__2659;
  unsigned long long llvm_cbe_tmp__2660;
  unsigned long long llvm_cbe_tmp__2661;
  unsigned long long llvm_cbe_tmp__2662;
  unsigned long long llvm_cbe_tmp__2663;
  unsigned long long llvm_cbe_tmp__2664;
  unsigned long long llvm_cbe_tmp__2665;
  unsigned long long llvm_cbe_tmp__2666;
  unsigned long long llvm_cbe_tmp__2667;
  unsigned long long llvm_cbe_tmp__2668;
  unsigned long long llvm_cbe_tmp__2669;
  unsigned long long llvm_cbe_tmp__2670;
  unsigned long long llvm_cbe_tmp__2671;
  unsigned long long llvm_cbe_tmp__2672;
  unsigned long long llvm_cbe_tmp__2673;
  unsigned long long llvm_cbe_tmp__2674;
  unsigned long long llvm_cbe_tmp__2675;
  unsigned long long llvm_cbe_tmp__2676;
  unsigned long long llvm_cbe_tmp__2677;
  unsigned long long llvm_cbe_tmp__2678;
  unsigned long long llvm_cbe_tmp__2679;
  unsigned long long llvm_cbe_tmp__2680;
  unsigned long long llvm_cbe_tmp__2681;
  unsigned long long llvm_cbe_tmp__2682;
  unsigned long long llvm_cbe_tmp__2683;
  unsigned long long llvm_cbe_tmp__2684;
  unsigned long long llvm_cbe_tmp__2685;
  unsigned long long llvm_cbe_tmp__2686;
  unsigned long long llvm_cbe_tmp__2687;
  unsigned long long llvm_cbe_tmp__2688;
  unsigned long long llvm_cbe_tmp__2689;
  unsigned long long llvm_cbe_tmp__2690;
  unsigned long long llvm_cbe_tmp__2691;
  unsigned long long llvm_cbe_tmp__2692;
  unsigned long long llvm_cbe_tmp__2693;
  unsigned long long llvm_cbe_tmp__2694;
  unsigned long long llvm_cbe_tmp__2695;
  unsigned long long llvm_cbe_tmp__2696;
  unsigned long long llvm_cbe_tmp__2697;
  unsigned long long llvm_cbe_tmp__2698;
  unsigned long long llvm_cbe_tmp__2699;
  unsigned long long llvm_cbe_tmp__2700;
  unsigned long long llvm_cbe_tmp__2701;
  unsigned long long llvm_cbe_tmp__2702;
  unsigned long long llvm_cbe_tmp__2703;
  unsigned long long llvm_cbe_tmp__2704;
  unsigned long long llvm_cbe_tmp__2705;
  unsigned long long llvm_cbe_tmp__2706;
  unsigned long long llvm_cbe_tmp__2707;
  unsigned long long llvm_cbe_tmp__2708;
  unsigned long long llvm_cbe_tmp__2709;
  unsigned long long llvm_cbe_tmp__2710;
  unsigned long long llvm_cbe_tmp__2711;
  unsigned long long llvm_cbe_tmp__2712;
  unsigned long long llvm_cbe_tmp__2713;
  unsigned long long llvm_cbe_tmp__2714;
  unsigned long long llvm_cbe_tmp__2715;
  unsigned long long llvm_cbe_tmp__2716;
  unsigned long long llvm_cbe_tmp__2717;
  unsigned long long llvm_cbe_tmp__2718;
  unsigned long long llvm_cbe_tmp__2719;
  unsigned long long llvm_cbe_tmp__2720;
  unsigned long long llvm_cbe_tmp__2721;
  unsigned long long llvm_cbe_tmp__2722;
  unsigned long long llvm_cbe_tmp__2723;
  unsigned long long llvm_cbe_tmp__2724;
  unsigned long long llvm_cbe_tmp__2725;
  unsigned long long llvm_cbe_tmp__2726;
  unsigned long long llvm_cbe_tmp__2727;
  unsigned long long llvm_cbe_tmp__2728;
  unsigned long long llvm_cbe_tmp__2729;
  unsigned long long llvm_cbe_tmp__2730;
  unsigned long long llvm_cbe_tmp__2731;
  unsigned long long llvm_cbe_tmp__2732;
  unsigned long long llvm_cbe_tmp__2733;
  unsigned long long llvm_cbe_tmp__2734;
  unsigned long long llvm_cbe_tmp__2735;
  unsigned long long llvm_cbe_tmp__2736;
  unsigned long long llvm_cbe_tmp__2737;
  unsigned long long llvm_cbe_tmp__2738;
  unsigned long long llvm_cbe_tmp__2739;
  unsigned long long llvm_cbe_tmp__2740;
  unsigned long long llvm_cbe_tmp__2741;
  unsigned long long llvm_cbe_tmp__2742;
  unsigned long long llvm_cbe_tmp__2743;
  unsigned long long llvm_cbe_tmp__2744;
  unsigned long long llvm_cbe_tmp__2745;
  unsigned long long llvm_cbe_tmp__2746;
  unsigned long long llvm_cbe_tmp__2747;
  unsigned long long llvm_cbe_tmp__2748;
  unsigned long long llvm_cbe_tmp__2749;
  unsigned long long llvm_cbe_tmp__2750;
  unsigned long long llvm_cbe_tmp__2751;
  unsigned long long llvm_cbe_tmp__2752;
  unsigned long long llvm_cbe_tmp__2753;
  unsigned long long llvm_cbe_tmp__2754;
  unsigned long long llvm_cbe_tmp__2755;
  unsigned long long llvm_cbe_tmp__2756;
  unsigned long long llvm_cbe_tmp__2757;
  unsigned long long llvm_cbe_tmp__2758;
  unsigned long long llvm_cbe_tmp__2759;
  unsigned long long llvm_cbe_tmp__2760;
  unsigned long long llvm_cbe_tmp__2761;
  unsigned long long llvm_cbe_tmp__2762;
  unsigned long long llvm_cbe_tmp__2763;
  unsigned long long llvm_cbe_tmp__2764;
  unsigned long long llvm_cbe_tmp__2765;
  unsigned long long llvm_cbe_tmp__2766;
  unsigned long long llvm_cbe_tmp__2767;
  unsigned long long llvm_cbe_tmp__2768;
  unsigned long long llvm_cbe_tmp__2769;
  unsigned long long llvm_cbe_tmp__2770;
  unsigned long long llvm_cbe_tmp__2771;
  unsigned long long llvm_cbe_tmp__2772;
  unsigned long long llvm_cbe_tmp__2773;
  unsigned long long llvm_cbe_tmp__2774;
  unsigned long long llvm_cbe_tmp__2775;
  unsigned long long llvm_cbe_tmp__2776;
  unsigned long long llvm_cbe_tmp__2777;
  unsigned long long llvm_cbe_tmp__2778;
  unsigned long long llvm_cbe_tmp__2779;
  unsigned long long llvm_cbe_tmp__2780;
  unsigned long long llvm_cbe_tmp__2781;
  unsigned long long llvm_cbe_tmp__2782;
  unsigned long long llvm_cbe_tmp__2783;
  unsigned long long llvm_cbe_tmp__2784;
  unsigned long long llvm_cbe_tmp__2785;
  unsigned long long llvm_cbe_tmp__2786;
  unsigned long long llvm_cbe_tmp__2787;
  unsigned long long llvm_cbe_tmp__2788;
  unsigned long long llvm_cbe_tmp__2789;
  unsigned long long llvm_cbe_tmp__2790;
  unsigned long long llvm_cbe_tmp__2791;
  unsigned long long llvm_cbe_tmp__2792;
  unsigned long long llvm_cbe_tmp__2793;
  unsigned long long llvm_cbe_tmp__2794;
  unsigned long long llvm_cbe_tmp__2795;
  unsigned long long llvm_cbe_tmp__2796;
  unsigned long long llvm_cbe_tmp__2797;
  unsigned long long llvm_cbe_tmp__2798;
  unsigned long long llvm_cbe_tmp__2799;
  unsigned long long llvm_cbe_tmp__2800;
  unsigned long long llvm_cbe_tmp__2801;
  unsigned long long llvm_cbe_tmp__2802;
  unsigned long long llvm_cbe_tmp__2803;
  unsigned long long llvm_cbe_tmp__2804;
  unsigned long long llvm_cbe_tmp__2805;
  unsigned long long llvm_cbe_tmp__2806;
  unsigned long long llvm_cbe_tmp__2807;
  unsigned long long llvm_cbe_tmp__2808;
  unsigned long long llvm_cbe_tmp__2809;
  unsigned long long llvm_cbe_tmp__2810;
  unsigned long long llvm_cbe_tmp__2811;
  unsigned long long llvm_cbe_tmp__2812;
  unsigned long long llvm_cbe_tmp__2813;
  unsigned long long llvm_cbe_tmp__2814;
  unsigned long long llvm_cbe_tmp__2815;
  unsigned long long llvm_cbe_tmp__2816;
  unsigned long long llvm_cbe_tmp__2817;
  unsigned long long llvm_cbe_tmp__2818;
  unsigned long long llvm_cbe_tmp__2819;
  unsigned long long llvm_cbe_tmp__2820;
  unsigned long long llvm_cbe_tmp__2821;
  unsigned long long llvm_cbe_tmp__2822;
  unsigned long long llvm_cbe_tmp__2823;
  unsigned long long llvm_cbe_tmp__2824;
  unsigned long long llvm_cbe_tmp__2825;
  unsigned long long llvm_cbe_tmp__2826;
  unsigned long long llvm_cbe_tmp__2827;
  unsigned long long llvm_cbe_tmp__2828;
  unsigned long long llvm_cbe_tmp__2829;
  unsigned long long llvm_cbe_tmp__2830;
  unsigned long long llvm_cbe_tmp__2831;
  unsigned long long llvm_cbe_tmp__2832;
  unsigned long long llvm_cbe_tmp__2833;
  unsigned long long llvm_cbe_tmp__2834;
  unsigned long long llvm_cbe_tmp__2835;
  unsigned long long llvm_cbe_tmp__2836;
  unsigned long long llvm_cbe_tmp__2837;
  unsigned long long llvm_cbe_tmp__2838;
  unsigned long long llvm_cbe_tmp__2839;
  unsigned long long llvm_cbe_tmp__2840;
  unsigned long long llvm_cbe_tmp__2841;
  unsigned long long llvm_cbe_tmp__2842;
  unsigned long long llvm_cbe_tmp__2843;
  unsigned long long llvm_cbe_tmp__2844;
  unsigned long long llvm_cbe_tmp__2845;
  unsigned long long llvm_cbe_tmp__2846;
  unsigned long long llvm_cbe_tmp__2847;
  unsigned long long llvm_cbe_tmp__2848;
  unsigned long long llvm_cbe_tmp__2849;
  unsigned long long llvm_cbe_tmp__2850;
  unsigned long long llvm_cbe_tmp__2851;
  unsigned long long llvm_cbe_tmp__2852;
  unsigned long long llvm_cbe_tmp__2853;
  unsigned long long llvm_cbe_tmp__2854;
  unsigned long long llvm_cbe_tmp__2855;
  unsigned long long llvm_cbe_tmp__2856;
  unsigned long long llvm_cbe_tmp__2857;
  unsigned long long llvm_cbe_tmp__2858;
  unsigned long long llvm_cbe_tmp__2859;
  unsigned long long llvm_cbe_tmp__2860;
  unsigned long long llvm_cbe_tmp__2861;
  unsigned long long llvm_cbe_tmp__2862;
  unsigned long long llvm_cbe_tmp__2863;
  unsigned long long llvm_cbe_tmp__2864;
  unsigned long long llvm_cbe_tmp__2865;
  unsigned long long llvm_cbe_tmp__2866;
  unsigned long long llvm_cbe_tmp__2867;
  unsigned long long llvm_cbe_tmp__2868;
  unsigned long long llvm_cbe_tmp__2869;
  unsigned long long llvm_cbe_tmp__2870;
  unsigned long long llvm_cbe_tmp__2871;
  unsigned long long llvm_cbe_tmp__2872;
  unsigned long long llvm_cbe_tmp__2873;
  unsigned long long llvm_cbe_tmp__2874;
  unsigned long long llvm_cbe_tmp__2875;
  unsigned long long llvm_cbe_tmp__2876;
  unsigned long long llvm_cbe_tmp__2877;
  unsigned long long llvm_cbe_tmp__2878;
  unsigned long long llvm_cbe_tmp__2879;
  unsigned long long llvm_cbe_tmp__2880;
  unsigned long long llvm_cbe_tmp__2881;
  unsigned long long llvm_cbe_tmp__2882;
  unsigned long long llvm_cbe_tmp__2883;
  unsigned long long llvm_cbe_tmp__2884;
  unsigned long long llvm_cbe_tmp__2885;
  unsigned long long llvm_cbe_tmp__2886;
  unsigned long long llvm_cbe_tmp__2887;
  unsigned long long llvm_cbe_tmp__2888;
  unsigned long long llvm_cbe_tmp__2889;
  unsigned long long llvm_cbe_tmp__2890;
  unsigned long long llvm_cbe_tmp__2891;
  unsigned long long llvm_cbe_tmp__2892;
  unsigned long long llvm_cbe_tmp__2893;
  unsigned long long llvm_cbe_tmp__2894;
  unsigned long long llvm_cbe_tmp__2895;
  unsigned long long llvm_cbe_tmp__2896;
  unsigned long long llvm_cbe_tmp__2897;
  unsigned long long llvm_cbe_tmp__2898;
  unsigned long long llvm_cbe_tmp__2899;
  unsigned long long llvm_cbe_tmp__2900;
  unsigned long long llvm_cbe_tmp__2901;
  unsigned long long llvm_cbe_tmp__2902;
  unsigned long long llvm_cbe_tmp__2903;
  unsigned long long llvm_cbe_tmp__2904;
  unsigned long long llvm_cbe_tmp__2905;
  unsigned long long llvm_cbe_tmp__2906;
  unsigned long long llvm_cbe_tmp__2907;
  unsigned long long llvm_cbe_tmp__2908;
  unsigned long long llvm_cbe_tmp__2909;
  unsigned long long llvm_cbe_tmp__2910;
  unsigned long long llvm_cbe_tmp__2911;
  unsigned long long llvm_cbe_tmp__2912;
  unsigned long long llvm_cbe_tmp__2913;
  unsigned long long llvm_cbe_tmp__2914;
  unsigned long long llvm_cbe_tmp__2915;
  unsigned long long llvm_cbe_tmp__2916;
  unsigned long long llvm_cbe_tmp__2917;
  unsigned long long llvm_cbe_tmp__2918;
  unsigned long long llvm_cbe_tmp__2919;
  unsigned long long llvm_cbe_tmp__2920;
  unsigned long long llvm_cbe_tmp__2921;
  unsigned long long llvm_cbe_tmp__2922;
  unsigned long long llvm_cbe_tmp__2923;
  unsigned long long llvm_cbe_tmp__2924;
  unsigned long long llvm_cbe_tmp__2925;
  unsigned long long llvm_cbe_tmp__2926;
  unsigned long long llvm_cbe_tmp__2927;
  unsigned long long llvm_cbe_tmp__2928;
  unsigned long long llvm_cbe_tmp__2929;
  unsigned long long llvm_cbe_tmp__2930;
  unsigned long long llvm_cbe_tmp__2931;
  unsigned long long llvm_cbe_tmp__2932;
  unsigned long long llvm_cbe_tmp__2933;
  unsigned long long llvm_cbe_tmp__2934;
  unsigned long long llvm_cbe_tmp__2935;
  unsigned long long llvm_cbe_tmp__2936;
  unsigned long long llvm_cbe_tmp__2937;
  unsigned long long llvm_cbe_tmp__2938;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2939;
  struct l_unnamed1 *llvm_cbe_tmp__2940;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2941;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2942;
  struct l_unnamed2 *llvm_cbe_tmp__2943;

  *(&llvm_cbe_tmp__2621) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2622) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__2623) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__2624) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__2625) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__2626) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__2627) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__2628) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__2629) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__2630) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__2631) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__2632) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__2636 = *(&llvm_cbe_tmp__2621);
  llvm_cbe_tmp__2637 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2638 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2639 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2640 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2641 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2642 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2643 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2644 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2645 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2646 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2647 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2648 = _ZN13model_predict18cppUpdateFun_countElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2637, llvm_cbe_tmp__2638, llvm_cbe_tmp__2639, llvm_cbe_tmp__2640, llvm_cbe_tmp__2641, llvm_cbe_tmp__2642, llvm_cbe_tmp__2643, llvm_cbe_tmp__2644, llvm_cbe_tmp__2645, llvm_cbe_tmp__2646, llvm_cbe_tmp__2647);
  *(&llvm_cbe_cppVar_1299) = llvm_cbe_tmp__2648;
  llvm_cbe_tmp__2649 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2650 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2651 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2652 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2653 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2654 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2655 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2656 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2657 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2658 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2659 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2660 = _ZN13model_predict17cppUpdateFun_doneElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2649, llvm_cbe_tmp__2650, llvm_cbe_tmp__2651, llvm_cbe_tmp__2652, llvm_cbe_tmp__2653, llvm_cbe_tmp__2654, llvm_cbe_tmp__2655, llvm_cbe_tmp__2656, llvm_cbe_tmp__2657, llvm_cbe_tmp__2658, llvm_cbe_tmp__2659);
  *(&llvm_cbe_cppVar_1323) = llvm_cbe_tmp__2660;
  llvm_cbe_tmp__2661 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2662 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2663 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2664 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2665 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2666 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2667 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2668 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2669 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2670 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2671 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2672 = _ZN13model_predict24cppUpdateFun_expectationElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2661, llvm_cbe_tmp__2662, llvm_cbe_tmp__2663, llvm_cbe_tmp__2664, llvm_cbe_tmp__2665, llvm_cbe_tmp__2666, llvm_cbe_tmp__2667, llvm_cbe_tmp__2668, llvm_cbe_tmp__2669, llvm_cbe_tmp__2670, llvm_cbe_tmp__2671);
  *(&llvm_cbe_cppVar_1353) = llvm_cbe_tmp__2672;
  llvm_cbe_tmp__2673 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2674 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2675 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2676 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2677 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2678 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2679 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2680 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2681 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2682 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2683 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2684 = _ZN13model_predict18cppUpdateFun_indexElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2673, llvm_cbe_tmp__2674, llvm_cbe_tmp__2675, llvm_cbe_tmp__2676, llvm_cbe_tmp__2677, llvm_cbe_tmp__2678, llvm_cbe_tmp__2679, llvm_cbe_tmp__2680, llvm_cbe_tmp__2681, llvm_cbe_tmp__2682, llvm_cbe_tmp__2683);
  *(&llvm_cbe_cppVar_1377) = llvm_cbe_tmp__2684;
  llvm_cbe_tmp__2685 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2686 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2687 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2688 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2689 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2690 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2691 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2692 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2693 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2694 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2695 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2696 = _ZN13model_predict19cppUpdateFun_jstateElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2685, llvm_cbe_tmp__2686, llvm_cbe_tmp__2687, llvm_cbe_tmp__2688, llvm_cbe_tmp__2689, llvm_cbe_tmp__2690, llvm_cbe_tmp__2691, llvm_cbe_tmp__2692, llvm_cbe_tmp__2693, llvm_cbe_tmp__2694, llvm_cbe_tmp__2695);
  *(&llvm_cbe_cppVar_1426) = llvm_cbe_tmp__2696;
  llvm_cbe_tmp__2697 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2698 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2699 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2700 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2701 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2702 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2703 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2704 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2705 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2706 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2707 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2708 = _ZN13model_predict21cppUpdateFun_per_v_pcElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2697, llvm_cbe_tmp__2698, llvm_cbe_tmp__2699, llvm_cbe_tmp__2700, llvm_cbe_tmp__2701, llvm_cbe_tmp__2702, llvm_cbe_tmp__2703, llvm_cbe_tmp__2704, llvm_cbe_tmp__2705, llvm_cbe_tmp__2706, llvm_cbe_tmp__2707);
  *(&llvm_cbe_cppVar_1479) = llvm_cbe_tmp__2708;
  llvm_cbe_tmp__2709 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2710 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2711 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2712 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2713 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2714 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2715 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2716 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2717 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2718 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2719 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2720 = _ZN13model_predict26cppUpdateFun_predict_h_cntElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2709, llvm_cbe_tmp__2710, llvm_cbe_tmp__2711, llvm_cbe_tmp__2712, llvm_cbe_tmp__2713, llvm_cbe_tmp__2714, llvm_cbe_tmp__2715, llvm_cbe_tmp__2716, llvm_cbe_tmp__2717, llvm_cbe_tmp__2718, llvm_cbe_tmp__2719);
  *(&llvm_cbe_cppVar_1522) = llvm_cbe_tmp__2720;
  llvm_cbe_tmp__2721 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2722 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2723 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2724 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2725 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2726 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2727 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2728 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2729 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2730 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2731 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2732 = _ZN13model_predict31cppUpdateFun_predict_input_doneElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2721, llvm_cbe_tmp__2722, llvm_cbe_tmp__2723, llvm_cbe_tmp__2724, llvm_cbe_tmp__2725, llvm_cbe_tmp__2726, llvm_cbe_tmp__2727, llvm_cbe_tmp__2728, llvm_cbe_tmp__2729, llvm_cbe_tmp__2730, llvm_cbe_tmp__2731);
  *(&llvm_cbe_cppVar_1539) = llvm_cbe_tmp__2732;
  llvm_cbe_tmp__2733 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2734 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2735 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2736 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2737 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2738 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2739 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2740 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2741 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2742 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2743 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2744 = _ZN13model_predict24cppUpdateFun_predict_maxElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2733, llvm_cbe_tmp__2734, llvm_cbe_tmp__2735, llvm_cbe_tmp__2736, llvm_cbe_tmp__2737, llvm_cbe_tmp__2738, llvm_cbe_tmp__2739, llvm_cbe_tmp__2740, llvm_cbe_tmp__2741, llvm_cbe_tmp__2742, llvm_cbe_tmp__2743);
  *(&llvm_cbe_cppVar_1601) = llvm_cbe_tmp__2744;
  llvm_cbe_tmp__2745 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2746 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2747 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2748 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2749 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2750 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2751 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2752 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2753 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2754 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2755 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2756 = _ZN13model_predict24cppUpdateFun_predict_sumElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2745, llvm_cbe_tmp__2746, llvm_cbe_tmp__2747, llvm_cbe_tmp__2748, llvm_cbe_tmp__2749, llvm_cbe_tmp__2750, llvm_cbe_tmp__2751, llvm_cbe_tmp__2752, llvm_cbe_tmp__2753, llvm_cbe_tmp__2754, llvm_cbe_tmp__2755);
  *(&llvm_cbe_cppVar_1665) = llvm_cbe_tmp__2756;
  llvm_cbe_tmp__2757 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2758 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2759 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2760 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2761 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2762 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2763 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2764 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2765 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2766 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2767 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2768 = _ZN13model_predict24cppUpdateFun_predict_upcElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2757, llvm_cbe_tmp__2758, llvm_cbe_tmp__2759, llvm_cbe_tmp__2760, llvm_cbe_tmp__2761, llvm_cbe_tmp__2762, llvm_cbe_tmp__2763, llvm_cbe_tmp__2764, llvm_cbe_tmp__2765, llvm_cbe_tmp__2766, llvm_cbe_tmp__2767);
  *(&llvm_cbe_cppVar_1722) = llvm_cbe_tmp__2768;
  llvm_cbe_tmp__2769 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2770 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2771 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2772 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2773 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2774 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2775 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2776 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2777 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2778 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2779 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2780 = _ZN13model_predict26cppUpdateFun_predict_v_cntElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2769, llvm_cbe_tmp__2770, llvm_cbe_tmp__2771, llvm_cbe_tmp__2772, llvm_cbe_tmp__2773, llvm_cbe_tmp__2774, llvm_cbe_tmp__2775, llvm_cbe_tmp__2776, llvm_cbe_tmp__2777, llvm_cbe_tmp__2778, llvm_cbe_tmp__2779);
  *(&llvm_cbe_cppVar_1771) = llvm_cbe_tmp__2780;
  llvm_cbe_tmp__2781 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2782 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2783 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2784 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2785 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2786 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2787 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2788 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2789 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2790 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2791 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2792 = _ZN13model_predict23cppUpdateFun_predictionElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2781, llvm_cbe_tmp__2782, llvm_cbe_tmp__2783, llvm_cbe_tmp__2784, llvm_cbe_tmp__2785, llvm_cbe_tmp__2786, llvm_cbe_tmp__2787, llvm_cbe_tmp__2788, llvm_cbe_tmp__2789, llvm_cbe_tmp__2790, llvm_cbe_tmp__2791);
  *(&llvm_cbe_cppVar_1788) = llvm_cbe_tmp__2792;
  llvm_cbe_tmp__2793 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2794 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2795 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2796 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2797 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2798 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2799 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2800 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2801 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2802 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2803 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2804 = _ZN13model_predict22cppUpdateFun_sumOfpow2Elllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2793, llvm_cbe_tmp__2794, llvm_cbe_tmp__2795, llvm_cbe_tmp__2796, llvm_cbe_tmp__2797, llvm_cbe_tmp__2798, llvm_cbe_tmp__2799, llvm_cbe_tmp__2800, llvm_cbe_tmp__2801, llvm_cbe_tmp__2802, llvm_cbe_tmp__2803);
  *(&llvm_cbe_cppVar_1828) = llvm_cbe_tmp__2804;
  llvm_cbe_tmp__2805 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2806 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2807 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2808 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2809 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2810 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2811 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2812 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2813 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2814 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2815 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2816 = _ZN13model_predict16cppUpdateFun_upcElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2805, llvm_cbe_tmp__2806, llvm_cbe_tmp__2807, llvm_cbe_tmp__2808, llvm_cbe_tmp__2809, llvm_cbe_tmp__2810, llvm_cbe_tmp__2811, llvm_cbe_tmp__2812, llvm_cbe_tmp__2813, llvm_cbe_tmp__2814, llvm_cbe_tmp__2815);
  *(&llvm_cbe_cppVar_1852) = llvm_cbe_tmp__2816;
  llvm_cbe_tmp__2817 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2818 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2819 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2820 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2821 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2822 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2823 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2824 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2825 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2826 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2827 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2828 = _ZN13model_predict24cppUpdateFun_wr_completeElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2817, llvm_cbe_tmp__2818, llvm_cbe_tmp__2819, llvm_cbe_tmp__2820, llvm_cbe_tmp__2821, llvm_cbe_tmp__2822, llvm_cbe_tmp__2823, llvm_cbe_tmp__2824, llvm_cbe_tmp__2825, llvm_cbe_tmp__2826, llvm_cbe_tmp__2827);
  *(&llvm_cbe_cppVar_1884) = llvm_cbe_tmp__2828;
  llvm_cbe_tmp__2829 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2830 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2831 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2832 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2833 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2834 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2835 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2836 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2837 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2838 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2839 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2840 = _ZN13model_predict21cppUpdateFun_wr_indexElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2829, llvm_cbe_tmp__2830, llvm_cbe_tmp__2831, llvm_cbe_tmp__2832, llvm_cbe_tmp__2833, llvm_cbe_tmp__2834, llvm_cbe_tmp__2835, llvm_cbe_tmp__2836, llvm_cbe_tmp__2837, llvm_cbe_tmp__2838, llvm_cbe_tmp__2839);
  *(&llvm_cbe_cppVar_1913) = llvm_cbe_tmp__2840;
  llvm_cbe_tmp__2841 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2842 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2843 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2844 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2845 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2846 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2847 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2848 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2849 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2850 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2851 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2852 = _ZN13model_predict22cppUpdateFun_wr_lengthElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2841, llvm_cbe_tmp__2842, llvm_cbe_tmp__2843, llvm_cbe_tmp__2844, llvm_cbe_tmp__2845, llvm_cbe_tmp__2846, llvm_cbe_tmp__2847, llvm_cbe_tmp__2848, llvm_cbe_tmp__2849, llvm_cbe_tmp__2850, llvm_cbe_tmp__2851);
  *(&llvm_cbe_cppVar_1940) = llvm_cbe_tmp__2852;
  llvm_cbe_tmp__2853 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2854 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2855 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2856 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2857 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2858 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2859 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2860 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2861 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2862 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2863 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_tmp__2864 = _ZN13model_predict23cppUpdateFun_wr_requestElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2853, llvm_cbe_tmp__2854, llvm_cbe_tmp__2855, llvm_cbe_tmp__2856, llvm_cbe_tmp__2857, llvm_cbe_tmp__2858, llvm_cbe_tmp__2859, llvm_cbe_tmp__2860, llvm_cbe_tmp__2861, llvm_cbe_tmp__2862, llvm_cbe_tmp__2863);
  *(&llvm_cbe_cppVar_1966) = llvm_cbe_tmp__2864;
  llvm_cbe_tmp__2865 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2866 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2867 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2868 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2869 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2870 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2871 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2872 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2873 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2874 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2875 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_cppVar_2021 = _ZN13model_predict24cppUpdateFun_hidden_unitElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2865, llvm_cbe_tmp__2866, llvm_cbe_tmp__2867, llvm_cbe_tmp__2868, llvm_cbe_tmp__2869, llvm_cbe_tmp__2870, llvm_cbe_tmp__2871, llvm_cbe_tmp__2872, llvm_cbe_tmp__2873, llvm_cbe_tmp__2874, llvm_cbe_tmp__2875);
  llvm_cbe_tmp__2876 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2877 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2878 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2879 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2880 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2881 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2882 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2883 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2884 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2885 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2886 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_cppVar_2056 = _ZN13model_predict17cppUpdateFun_pow2Elllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2876, llvm_cbe_tmp__2877, llvm_cbe_tmp__2878, llvm_cbe_tmp__2879, llvm_cbe_tmp__2880, llvm_cbe_tmp__2881, llvm_cbe_tmp__2882, llvm_cbe_tmp__2883, llvm_cbe_tmp__2884, llvm_cbe_tmp__2885, llvm_cbe_tmp__2886);
  llvm_cbe_tmp__2887 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2888 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2889 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2890 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2891 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2892 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2893 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2894 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2895 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2896 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2897 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_cppVar_2065 = _ZN13model_predict27cppUpdateFun_predict_resultElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2887, llvm_cbe_tmp__2888, llvm_cbe_tmp__2889, llvm_cbe_tmp__2890, llvm_cbe_tmp__2891, llvm_cbe_tmp__2892, llvm_cbe_tmp__2893, llvm_cbe_tmp__2894, llvm_cbe_tmp__2895, llvm_cbe_tmp__2896, llvm_cbe_tmp__2897);
  llvm_cbe_tmp__2898 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2899 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2900 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2901 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2902 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2903 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2904 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2905 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2906 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2907 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2908 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_cppVar_2103 = _ZN13model_predict27cppUpdateFun_predict_vectorElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2898, llvm_cbe_tmp__2899, llvm_cbe_tmp__2900, llvm_cbe_tmp__2901, llvm_cbe_tmp__2902, llvm_cbe_tmp__2903, llvm_cbe_tmp__2904, llvm_cbe_tmp__2905, llvm_cbe_tmp__2906, llvm_cbe_tmp__2907, llvm_cbe_tmp__2908);
  llvm_cbe_tmp__2909 = *(&llvm_cbe_tmp__2622);
  llvm_cbe_tmp__2910 = *(&llvm_cbe_tmp__2623);
  llvm_cbe_tmp__2911 = *(&llvm_cbe_tmp__2624);
  llvm_cbe_tmp__2912 = *(&llvm_cbe_tmp__2625);
  llvm_cbe_tmp__2913 = *(&llvm_cbe_tmp__2626);
  llvm_cbe_tmp__2914 = *(&llvm_cbe_tmp__2627);
  llvm_cbe_tmp__2915 = *(&llvm_cbe_tmp__2628);
  llvm_cbe_tmp__2916 = *(&llvm_cbe_tmp__2629);
  llvm_cbe_tmp__2917 = *(&llvm_cbe_tmp__2630);
  llvm_cbe_tmp__2918 = *(&llvm_cbe_tmp__2631);
  llvm_cbe_tmp__2919 = *(&llvm_cbe_tmp__2632);
  llvm_cbe_cppVar_2165 = _ZN13model_predict28cppUpdateFun_visibleEnergiesElllllllllll(llvm_cbe_tmp__2636, llvm_cbe_tmp__2909, llvm_cbe_tmp__2910, llvm_cbe_tmp__2911, llvm_cbe_tmp__2912, llvm_cbe_tmp__2913, llvm_cbe_tmp__2914, llvm_cbe_tmp__2915, llvm_cbe_tmp__2916, llvm_cbe_tmp__2917, llvm_cbe_tmp__2918, llvm_cbe_tmp__2919);
  llvm_cbe_tmp__2920 = *(&llvm_cbe_cppVar_1299);
  *((&llvm_cbe_tmp__2636->field0)) = llvm_cbe_tmp__2920;
  llvm_cbe_tmp__2921 = *(&llvm_cbe_cppVar_1323);
  *((&llvm_cbe_tmp__2636->field3)) = llvm_cbe_tmp__2921;
  llvm_cbe_tmp__2922 = *(&llvm_cbe_cppVar_1353);
  *((&llvm_cbe_tmp__2636->field5)) = llvm_cbe_tmp__2922;
  llvm_cbe_tmp__2923 = *(&llvm_cbe_cppVar_1377);
  *((&llvm_cbe_tmp__2636->field7)) = llvm_cbe_tmp__2923;
  llvm_cbe_tmp__2924 = *(&llvm_cbe_cppVar_1426);
  *((&llvm_cbe_tmp__2636->field9)) = llvm_cbe_tmp__2924;
  llvm_cbe_tmp__2925 = *(&llvm_cbe_cppVar_1479);
  *((&llvm_cbe_tmp__2636->field17)) = llvm_cbe_tmp__2925;
  llvm_cbe_tmp__2926 = *(&llvm_cbe_cppVar_1522);
  *((&llvm_cbe_tmp__2636->field19)) = llvm_cbe_tmp__2926;
  llvm_cbe_tmp__2927 = *(&llvm_cbe_cppVar_1539);
  *((&llvm_cbe_tmp__2636->field20)) = llvm_cbe_tmp__2927;
  llvm_cbe_tmp__2928 = *(&llvm_cbe_cppVar_1601);
  *((&llvm_cbe_tmp__2636->field21)) = llvm_cbe_tmp__2928;
  llvm_cbe_tmp__2929 = *(&llvm_cbe_cppVar_1665);
  *((&llvm_cbe_tmp__2636->field23)) = llvm_cbe_tmp__2929;
  llvm_cbe_tmp__2930 = *(&llvm_cbe_cppVar_1722);
  *((&llvm_cbe_tmp__2636->field24)) = llvm_cbe_tmp__2930;
  llvm_cbe_tmp__2931 = *(&llvm_cbe_cppVar_1771);
  *((&llvm_cbe_tmp__2636->field25)) = llvm_cbe_tmp__2931;
  llvm_cbe_tmp__2932 = *(&llvm_cbe_cppVar_1788);
  *((&llvm_cbe_tmp__2636->field27)) = llvm_cbe_tmp__2932;
  llvm_cbe_tmp__2933 = *(&llvm_cbe_cppVar_1828);
  *((&llvm_cbe_tmp__2636->field32)) = llvm_cbe_tmp__2933;
  llvm_cbe_tmp__2934 = *(&llvm_cbe_cppVar_1852);
  *((&llvm_cbe_tmp__2636->field34)) = llvm_cbe_tmp__2934;
  llvm_cbe_tmp__2935 = *(&llvm_cbe_cppVar_1884);
  *((&llvm_cbe_tmp__2636->field36)) = llvm_cbe_tmp__2935;
  llvm_cbe_tmp__2936 = *(&llvm_cbe_cppVar_1913);
  *((&llvm_cbe_tmp__2636->field37)) = llvm_cbe_tmp__2936;
  llvm_cbe_tmp__2937 = *(&llvm_cbe_cppVar_1940);
  *((&llvm_cbe_tmp__2636->field38)) = llvm_cbe_tmp__2937;
  llvm_cbe_tmp__2938 = *(&llvm_cbe_cppVar_1966);
  *((&llvm_cbe_tmp__2636->field39)) = llvm_cbe_tmp__2938;
  llvm_cbe_tmp__2939 = _ZN8type_memIbLj128EEaSERKS0_(((&llvm_cbe_tmp__2636->field6)), (&llvm_cbe_cppVar_2021));
  llvm_cbe_tmp__2940 = _ZN8type_memIjLj8EEaSERKS0_(((&llvm_cbe_tmp__2636->field18)), (&llvm_cbe_cppVar_2056));
  llvm_cbe_tmp__2941 = _ZN8type_memIhLj128EEaSERKS0_(((&llvm_cbe_tmp__2636->field22)), (&llvm_cbe_cppVar_2065));
  llvm_cbe_tmp__2942 = _ZN8type_memIbLj512EEaSERKS0_(((&llvm_cbe_tmp__2636->field26)), (&llvm_cbe_cppVar_2103));
  llvm_cbe_tmp__2943 = _ZN8type_memItLj8EEaSERKS0_(((&llvm_cbe_tmp__2636->field35)), (&llvm_cbe_cppVar_2165));
  *(&llvm_cbe_tmp__2635) = 1u;
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_2165));
  _ZN8type_memIbLj512EED1Ev((&llvm_cbe_cppVar_2103));
  _ZN8type_memIhLj128EED1Ev((&llvm_cbe_cppVar_2065));
  _ZN8type_memIjLj8EED1Ev((&llvm_cbe_cppVar_2056));
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_2021));
  return;
}


static void __cxx_global_var_init(void) {
  unsigned int llvm_cbe_tmp__2944;

  _ZN13model_predictC1Ev((&GM));
  llvm_cbe_tmp__2944 = __cxa_atexit(((void  (*) (unsigned char *))_ZN13model_predictD1Ev), ((unsigned char *)(&GM)), ((unsigned char *)(&__dso_handle)));
  return;
}


void _ZN13model_predictC1Ev(struct l_class_OC_model_predict *llvm_cbe_this) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__2945;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__2946;

  *(&llvm_cbe_tmp__2945) = llvm_cbe_this;
  llvm_cbe_tmp__2946 = *(&llvm_cbe_tmp__2945);
  _ZN13model_predictC2Ev(llvm_cbe_tmp__2946);
  return;
}


void _ZN13model_predictD1Ev(struct l_class_OC_model_predict *llvm_cbe_this) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__2947;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__2948;

  *(&llvm_cbe_tmp__2947) = llvm_cbe_this;
  llvm_cbe_tmp__2948 = *(&llvm_cbe_tmp__2947);
  _ZN13model_predictD2Ev(llvm_cbe_tmp__2948);
  return;
}


void _Z4waitv(void) {
  unsigned int llvm_cbe_tmp__2949;

  llvm_cbe_tmp__2949 = *(&cycleCnt);
  *(&cycleCnt) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__2949) + ((unsigned int )1u))));
  return;
}


void _Z15reset_signal_isib(unsigned int llvm_cbe_tmp__2950, bool llvm_cbe_tmp__2951) {
  unsigned int llvm_cbe_tmp__2952;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2953;    /* Address-exposed local */

  *(&llvm_cbe_tmp__2952) = llvm_cbe_tmp__2950;
  *(&llvm_cbe_tmp__2953) = (((unsigned char )(bool )llvm_cbe_tmp__2951));
  return;
}


void _Z14set_stack_sizei(unsigned int llvm_cbe_tmp__2954) {
  unsigned int llvm_cbe_tmp__2955;    /* Address-exposed local */

  *(&llvm_cbe_tmp__2955) = llvm_cbe_tmp__2954;
  return;
}


unsigned long long _Z8_c_16_15f(float llvm_cbe_in) {
  float llvm_cbe_tmp__2956;    /* Address-exposed local */
  float llvm_cbe_tmp__2957;

  *(&llvm_cbe_tmp__2956) = llvm_cbe_in;
  llvm_cbe_tmp__2957 = *(&llvm_cbe_tmp__2956);
  return ((((signed long long )(((float )(llvm_cbe_tmp__2957 * 0x1p+1))))) & 65535ull);
}


float _Z8_b_16_15l(unsigned long long llvm_cbe_in) {
  unsigned long long llvm_cbe_tmp__2958;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2959;

  *(&llvm_cbe_tmp__2958) = llvm_cbe_in;
  llvm_cbe_tmp__2959 = *(&llvm_cbe_tmp__2958);
  return (((float )((((double )(signed long long )(llvm_cbe_tmp__2959 & 65535ull))) / 0x1p+1)));
}


void _ZN3rbm11predict_rbmEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__2960;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2961;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2962;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2963;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2964;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2965;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2966;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2967;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2968;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2969;    /* Address-exposed local */
  unsigned short llvm_cbe_ntu;    /* Address-exposed local */
  unsigned short llvm_cbe_nv;    /* Address-exposed local */
  unsigned short llvm_cbe_nh;    /* Address-exposed local */
  unsigned short llvm_cbe_nu;    /* Address-exposed local */
  unsigned short llvm_cbe_nlp;    /* Address-exposed local */
  unsigned short llvm_cbe_user;    /* Address-exposed local */
  unsigned char llvm_cbe_prediction;    /* Address-exposed local */
  unsigned char llvm_cbe_j;    /* Address-exposed local */
  unsigned char llvm_cbe_count;    /* Address-exposed local */
  unsigned short llvm_cbe_i;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp1;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp2;    /* Address-exposed local */
  unsigned char llvm_cbe_pingpong;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2970;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2971;    /* Address-exposed local */
  unsigned char llvm_cbe_current_pv;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2972;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2973;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__2974;
  bool llvm_cbe_tmp__2975;
  bool llvm_cbe_tmp__2976;
  unsigned long long llvm_cbe_tmp__2977;
  unsigned long long llvm_cbe_tmp__2978;
  unsigned long long llvm_cbe_tmp__2979;
  unsigned long long llvm_cbe_tmp__2980;
  unsigned long long llvm_cbe_tmp__2981;
  unsigned long long llvm_cbe_tmp__2982;
  unsigned short llvm_cbe_tmp__2983;
  unsigned short llvm_cbe_tmp__2984;
  unsigned short llvm_cbe_tmp__2985;
  unsigned short llvm_cbe_tmp__2986;
  unsigned short llvm_cbe_tmp__2987;
  unsigned short llvm_cbe_tmp__2988;
  unsigned short llvm_cbe_tmp__2989;

  *(&llvm_cbe_tmp__2960) = llvm_cbe_this;
  llvm_cbe_tmp__2974 = *(&llvm_cbe_tmp__2960);
  *(&llvm_cbe_tmp__2961) = ((unsigned char )1);
  llvm_cbe_tmp__2975 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__2974->field36)), (&llvm_cbe_tmp__2961)))&1);
  *(&llvm_cbe_tmp__2962) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2974->field42)), (&llvm_cbe_tmp__2962));
  *(&llvm_cbe_tmp__2963) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2974->field43)), (&llvm_cbe_tmp__2963));
  goto llvm_cbe_tmp__2990;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2990:
  _Z4waitv();
  llvm_cbe_tmp__2976 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2974->field36))))&1);
  if ((((llvm_cbe_tmp__2976 ^ 1)&1))) {
    goto llvm_cbe_tmp__2990;
  } else {
    goto llvm_cbe_tmp__2991;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2991:
  llvm_cbe_tmp__2977 = *((&GM.field11));
  *(&llvm_cbe_tmp__2964) = (((unsigned short )llvm_cbe_tmp__2977));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2974->field30)), (&llvm_cbe_tmp__2964));
  llvm_cbe_tmp__2978 = *((&GM.field16));
  *(&llvm_cbe_tmp__2965) = (((unsigned short )llvm_cbe_tmp__2978));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2974->field31)), (&llvm_cbe_tmp__2965));
  llvm_cbe_tmp__2979 = *((&GM.field15));
  *(&llvm_cbe_tmp__2966) = (((unsigned short )llvm_cbe_tmp__2979));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2974->field32)), (&llvm_cbe_tmp__2966));
  llvm_cbe_tmp__2980 = *((&GM.field12));
  *(&llvm_cbe_tmp__2967) = (((unsigned short )llvm_cbe_tmp__2980));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2974->field33)), (&llvm_cbe_tmp__2967));
  llvm_cbe_tmp__2981 = *((&GM.field14));
  *(&llvm_cbe_tmp__2968) = (((unsigned short )llvm_cbe_tmp__2981));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2974->field34)), (&llvm_cbe_tmp__2968));
  llvm_cbe_tmp__2982 = *((&GM.field13));
  *(&llvm_cbe_tmp__2969) = (((unsigned short )llvm_cbe_tmp__2982));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2974->field35)), (&llvm_cbe_tmp__2969));
  llvm_cbe_tmp__2983 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2974->field34)));
  *(&llvm_cbe_ntu) = llvm_cbe_tmp__2983;
  llvm_cbe_tmp__2984 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2974->field31)));
  *(&llvm_cbe_nv) = llvm_cbe_tmp__2984;
  llvm_cbe_tmp__2985 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2974->field30)));
  *(&llvm_cbe_nh) = llvm_cbe_tmp__2985;
  llvm_cbe_tmp__2986 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2974->field32)));
  *(&llvm_cbe_nu) = llvm_cbe_tmp__2986;
  llvm_cbe_tmp__2987 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2974->field33)));
  *(&llvm_cbe_nlp) = llvm_cbe_tmp__2987;
  *(&llvm_cbe_user) = ((unsigned short )0);
  *(&llvm_cbe_count) = ((unsigned char )0);
  *(&predict_upc) = 3u;
  llvm_cbe_tmp__2988 = *(&llvm_cbe_nh);
  llvm_cbe_tmp__2989 = *(&llvm_cbe_nv);
  _ZN3rbm28activateVisibleUnits_predictEtt(llvm_cbe_tmp__2974, llvm_cbe_tmp__2988, llvm_cbe_tmp__2989);
  return;
}


bool _ZN14sc_signal_boolaSERKb(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_d) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2992;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__2993;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2994;
  unsigned char *llvm_cbe_tmp__2995;
  unsigned char llvm_cbe_tmp__2996;
  unsigned char llvm_cbe_tmp__2997;

  *(&llvm_cbe_tmp__2992) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2993) = llvm_cbe_d;
  llvm_cbe_tmp__2994 = *(&llvm_cbe_tmp__2992);
  llvm_cbe_tmp__2995 = *(&llvm_cbe_tmp__2993);
  llvm_cbe_tmp__2996 = *llvm_cbe_tmp__2995;
  *((&llvm_cbe_tmp__2994->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__2996&1u))&1))));
  llvm_cbe_tmp__2997 = *((&llvm_cbe_tmp__2994->field0));
  return (((((bool )llvm_cbe_tmp__2997&1u))&1));
}


void _ZN14sc_signal_bool5writeERKb(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_d) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2998;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__2999;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3000;
  unsigned char *llvm_cbe_tmp__3001;
  unsigned char llvm_cbe_tmp__3002;

  *(&llvm_cbe_tmp__2998) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2999) = llvm_cbe_d;
  llvm_cbe_tmp__3000 = *(&llvm_cbe_tmp__2998);
  llvm_cbe_tmp__3001 = *(&llvm_cbe_tmp__2999);
  llvm_cbe_tmp__3002 = *llvm_cbe_tmp__3001;
  *((&llvm_cbe_tmp__3000->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__3002&1u))&1))));
  return;
}


bool _ZN14sc_signal_bool4readEv(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3003;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3004;
  unsigned char llvm_cbe_tmp__3005;

  *(&llvm_cbe_tmp__3003) = llvm_cbe_this;
  llvm_cbe_tmp__3004 = *(&llvm_cbe_tmp__3003);
  llvm_cbe_tmp__3005 = *((&llvm_cbe_tmp__3004->field0));
  return (((((bool )llvm_cbe_tmp__3005&1u))&1));
}


void _ZN13sc_signal_u165writeERKt(struct l_class_OC_sc_signal_u16 *llvm_cbe_this, unsigned short *llvm_cbe_d) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__3006;    /* Address-exposed local */
  unsigned short *llvm_cbe_tmp__3007;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__3008;
  unsigned short *llvm_cbe_tmp__3009;
  unsigned short llvm_cbe_tmp__3010;

  *(&llvm_cbe_tmp__3006) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3007) = llvm_cbe_d;
  llvm_cbe_tmp__3008 = *(&llvm_cbe_tmp__3006);
  llvm_cbe_tmp__3009 = *(&llvm_cbe_tmp__3007);
  llvm_cbe_tmp__3010 = *llvm_cbe_tmp__3009;
  *((&llvm_cbe_tmp__3008->field0)) = llvm_cbe_tmp__3010;
  return;
}


unsigned short _ZN13sc_signal_u164readEv(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__3011;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__3012;
  unsigned short llvm_cbe_tmp__3013;

  *(&llvm_cbe_tmp__3011) = llvm_cbe_this;
  llvm_cbe_tmp__3012 = *(&llvm_cbe_tmp__3011);
  llvm_cbe_tmp__3013 = *((&llvm_cbe_tmp__3012->field0));
  return llvm_cbe_tmp__3013;
}


void _ZN3rbm27activateHiddenUnits_predictEbtt(struct l_struct_OC_rbm *llvm_cbe_this, bool llvm_cbe_pingpong, unsigned short llvm_cbe_nh, unsigned short llvm_cbe_nv) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__3014;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__3015;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__3016;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__3017;    /* Address-exposed local */
  unsigned short llvm_cbe_h;    /* Address-exposed local */
  unsigned short llvm_cbe_v;    /* Address-exposed local */
  float llvm_cbe_sum;    /* Address-exposed local */
  float llvm_cbe_tmp;    /* Address-exposed local */
  float llvm_cbe_prob;    /* Address-exposed local */
  float llvm_cbe_tmp1;    /* Address-exposed local */
  unsigned char llvm_cbe_current_data;    /* Address-exposed local */
  unsigned char llvm_cbe_comp;    /* Address-exposed local */
  unsigned char llvm_cbe_th;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__3018;
  unsigned short llvm_cbe_tmp__3019;
  unsigned short llvm_cbe_tmp__3020;
  unsigned short llvm_cbe_tmp__3021;
  unsigned short llvm_cbe_tmp__3022;
  unsigned short llvm_cbe_tmp__3023;
  unsigned short llvm_cbe_tmp__3024;
  unsigned short llvm_cbe_tmp__3025;
  unsigned char llvm_cbe_tmp__3026;
  unsigned char *llvm_cbe_tmp__3027;
  unsigned char llvm_cbe_tmp__3028;
  unsigned char llvm_cbe_tmp__3029;
  unsigned short llvm_cbe_tmp__3030;
  unsigned short llvm_cbe_tmp__3031;
  float *llvm_cbe_tmp__3032;
  float llvm_cbe_tmp__3033;
  float llvm_cbe_tmp__3034;
  float llvm_cbe_tmp__3035;
  unsigned short llvm_cbe_tmp__3036;
  float llvm_cbe_tmp__3037;
  unsigned long long llvm_cbe_tmp__3038;
  unsigned short llvm_cbe_tmp__3039;
  float llvm_cbe_tmp__3040;
  float llvm_cbe_tmp__3041;
  unsigned char llvm_cbe_tmp__3042;
  unsigned char llvm_cbe_tmp__3043;
  unsigned short llvm_cbe_tmp__3044;
  unsigned char *llvm_cbe_tmp__3045;
  unsigned short llvm_cbe_tmp__3046;
  unsigned short llvm_cbe_tmp__3047;
  unsigned char *llvm_cbe_tmp__3048;

  *(&llvm_cbe_tmp__3014) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3015) = (((unsigned char )(bool )llvm_cbe_pingpong));
  *(&llvm_cbe_tmp__3016) = llvm_cbe_nh;
  *(&llvm_cbe_tmp__3017) = llvm_cbe_nv;
  llvm_cbe_tmp__3018 = *(&llvm_cbe_tmp__3014);
  *(&llvm_cbe_h) = ((unsigned short )0);
  goto llvm_cbe_tmp__3049;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3049:
  llvm_cbe_tmp__3019 = *(&llvm_cbe_h);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3019))) < ((signed int )100u))) {
    goto llvm_cbe_tmp__3050;
  } else {
    goto llvm_cbe_tmp__3051;
  }

llvm_cbe_tmp__3052:
  llvm_cbe_tmp__3043 = *(&llvm_cbe_th);
  llvm_cbe_tmp__3044 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3045 = _ZN11SysCArray1DIbLj128EEixEj(((&llvm_cbe_tmp__3018->field22)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3044)));
  *llvm_cbe_tmp__3045 = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__3043&1u))&1))));
  _Z4waitv();
  llvm_cbe_tmp__3046 = *(&llvm_cbe_h);
  *(&llvm_cbe_h) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3046) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3049;

llvm_cbe_tmp__3053:
  *(&llvm_cbe_th) = ((unsigned char )1);
  goto llvm_cbe_tmp__3052;

llvm_cbe_tmp__3054:
  llvm_cbe_tmp__3037 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__3038 = _Z8_c_16_15f(llvm_cbe_tmp__3037);
  llvm_cbe_tmp__3039 = _Z7sigmoidl(llvm_cbe_tmp__3038);
  llvm_cbe_tmp__3040 = _Z8_b_16_15l((((unsigned long long )(unsigned short )llvm_cbe_tmp__3039)));
  *(&llvm_cbe_prob) = llvm_cbe_tmp__3040;
  llvm_cbe_tmp__3041 = *(&llvm_cbe_prob);
  *(&llvm_cbe_comp) = (((unsigned char )(bool )(llvm_fcmp_olt(0x1p-1, llvm_cbe_tmp__3041))));
  llvm_cbe_tmp__3042 = *(&llvm_cbe_comp);
  if ((((((bool )llvm_cbe_tmp__3042&1u))&1))) {
    goto llvm_cbe_tmp__3053;
  } else {
    goto llvm_cbe_tmp__3055;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3056:
  llvm_cbe_tmp__3022 = *(&llvm_cbe_v);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3022))) < ((signed int )501u))) {
    goto llvm_cbe_tmp__3057;
  } else {
    goto llvm_cbe_tmp__3054;
  }

llvm_cbe_tmp__3058:
  llvm_cbe_tmp__3036 = *(&llvm_cbe_v);
  *(&llvm_cbe_v) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3036) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3056;

llvm_cbe_tmp__3059:
  llvm_cbe_tmp__3030 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3031 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3032 = _ZN11SysCArray2DIfLj501ELj101EEixEj(((&llvm_cbe_tmp__3018->field23)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3031)));
  llvm_cbe_tmp__3033 = *((&llvm_cbe_tmp__3032[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__3030)))]));
  *(&llvm_cbe_tmp) = llvm_cbe_tmp__3033;
  _Z4waitv();
  llvm_cbe_tmp__3034 = *(&llvm_cbe_tmp);
  llvm_cbe_tmp__3035 = *(&llvm_cbe_sum);
  *(&llvm_cbe_sum) = (((float )(llvm_cbe_tmp__3035 + llvm_cbe_tmp__3034)));
  goto llvm_cbe_tmp__3058;

llvm_cbe_tmp__3060:
  *(&per_v_pc) = 0u;
  *(&predict_upc) = 0u;
  llvm_cbe_tmp__3025 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3026 = *(&llvm_cbe_tmp__3015);
  llvm_cbe_tmp__3027 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__3018->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__3026&1u))&1)))));
  llvm_cbe_tmp__3028 = *((&llvm_cbe_tmp__3027[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__3025)))]));
  *(&llvm_cbe_current_data) = llvm_cbe_tmp__3028;
  _Z4waitv();
  llvm_cbe_tmp__3029 = *(&llvm_cbe_current_data);
  if (((((unsigned int )(unsigned char )llvm_cbe_tmp__3029)) == 1u)) {
    goto llvm_cbe_tmp__3059;
  } else {
    goto llvm_cbe_tmp__3058;
  }

llvm_cbe_tmp__3057:
  llvm_cbe_tmp__3023 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3024 = *(&llvm_cbe_tmp__3017);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__3023)) == (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3024))) + ((unsigned int )1u)))))) {
    goto llvm_cbe_tmp__3054;
  } else {
    goto llvm_cbe_tmp__3060;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3061:
  *(&llvm_cbe_sum) = 0x0p+0;
  *(&llvm_cbe_v) = ((unsigned short )0);
  goto llvm_cbe_tmp__3056;

llvm_cbe_tmp__3050:
  llvm_cbe_tmp__3020 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3021 = *(&llvm_cbe_tmp__3016);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__3020)) == (((unsigned int )(unsigned short )llvm_cbe_tmp__3021)))) {
    goto llvm_cbe_tmp__3051;
  } else {
    goto llvm_cbe_tmp__3061;
  }

llvm_cbe_tmp__3055:
  *(&llvm_cbe_th) = ((unsigned char )0);
  goto llvm_cbe_tmp__3052;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3051:
  llvm_cbe_tmp__3047 = *(&llvm_cbe_tmp__3016);
  llvm_cbe_tmp__3048 = _ZN11SysCArray1DIbLj128EEixEj(((&llvm_cbe_tmp__3018->field22)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3047)));
  *llvm_cbe_tmp__3048 = ((unsigned char )1);
  _Z4waitv();
  *(&per_v_pc) = 0u;
  *(&predict_upc) = 1u;
  return;
}


void _ZN3rbm28activateVisibleUnits_predictEtt(struct l_struct_OC_rbm *llvm_cbe_this, unsigned short llvm_cbe_nh, unsigned short llvm_cbe_nv) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__3062;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__3063;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__3064;    /* Address-exposed local */
  unsigned short llvm_cbe_v;    /* Address-exposed local */
  unsigned short llvm_cbe_h;    /* Address-exposed local */
  float llvm_cbe_sum;    /* Address-exposed local */
  float llvm_cbe_max;    /* Address-exposed local */
  float llvm_cbe_probs;    /* Address-exposed local */
  struct l_unnamed21 llvm_cbe_pow2;    /* Address-exposed local */
  float llvm_cbe_sumOfpow2;    /* Address-exposed local */
  float llvm_cbe_expectation;    /* Address-exposed local */
  unsigned char llvm_cbe_prediction;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp;    /* Address-exposed local */
  float llvm_cbe_tmp1;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp2;    /* Address-exposed local */
  unsigned short llvm_cbe_j;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__3065;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__3066;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__3067;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__3068;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__3069;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__3070;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3071;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3072;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__3073;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__3074;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3075;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3076;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3077;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__3078;    /* Address-exposed local */
  float llvm_cbe_dp;    /* Address-exposed local */
  float llvm_cbe_dp1;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__3079;
  bool llvm_cbe_tmp__3080;
  bool llvm_cbe_tmp__3081;
  bool llvm_cbe_tmp__3082;
  bool llvm_cbe_tmp__3083;
  unsigned char llvm_cbe_tmp__3084;
  unsigned int llvm_cbe_tmp__3085;
  unsigned int llvm_cbe_tmp__3086;
  unsigned int llvm_cbe_tmp__3087;
  unsigned int llvm_cbe_tmp__3088;
  unsigned int llvm_cbe_tmp__3089;
  unsigned int llvm_cbe_tmp__3090;
  unsigned char llvm_cbe_tmp__3091;
  unsigned long long llvm_cbe_tmp__3092;
  unsigned long long llvm_cbe_tmp__3093;
  unsigned long long llvm_cbe_tmp__3094;
  unsigned long long llvm_cbe_tmp__3095;
  unsigned long long llvm_cbe_tmp__3096;
  unsigned char llvm_cbe_tmp__3097;
  unsigned int llvm_cbe_tmp__3098;
  unsigned char llvm_cbe_tmp__3099;
  unsigned long long llvm_cbe_tmp__3100;
  unsigned long long llvm_cbe_tmp__3101;
  unsigned long long llvm_cbe_tmp__3102;
  unsigned long long llvm_cbe_tmp__3103;
  unsigned long long llvm_cbe_tmp__3104;
  unsigned long long llvm_cbe_tmp__3105;
  unsigned long long llvm_cbe_tmp__3106;
  unsigned long long llvm_cbe_tmp__3107;
  unsigned long long llvm_cbe_tmp__3108;
  unsigned long long llvm_cbe_tmp__3109;
  unsigned long long llvm_cbe_tmp__3110;
  unsigned char *llvm_cbe_tmp__3111;
  unsigned char *llvm_cbe_tmp__3112;
  unsigned char *llvm_cbe_tmp__3113;
  unsigned char *llvm_cbe_tmp__3114;
  float *llvm_cbe_tmp__3115;
  unsigned char *llvm_cbe_tmp__3116;
  unsigned char *llvm_cbe_tmp__3117;
  unsigned char *llvm_cbe_tmp__3118;
  float *llvm_cbe_tmp__3119;
  unsigned short *llvm_cbe_tmp__3120;
  unsigned int *llvm_cbe_tmp__3121;
  unsigned short llvm_cbe_tmp__3122;
  unsigned short llvm_cbe_tmp__3123;
  unsigned short llvm_cbe_tmp__3124;
  unsigned short llvm_cbe_tmp__3125;
  unsigned short llvm_cbe_tmp__3126;
  unsigned char *llvm_cbe_tmp__3127;
  unsigned char llvm_cbe_tmp__3128;
  unsigned short llvm_cbe_tmp__3129;
  unsigned short llvm_cbe_tmp__3130;
  unsigned short llvm_cbe_tmp__3131;
  float *llvm_cbe_tmp__3132;
  float llvm_cbe_tmp__3133;
  unsigned char llvm_cbe_tmp__3134;
  unsigned short llvm_cbe_tmp__3135;
  unsigned short llvm_cbe_tmp__3136;
  unsigned short llvm_cbe_tmp__3137;
  unsigned char llvm_cbe_tmp__3138;
  unsigned int llvm_cbe_tmp__3139;
  unsigned int llvm_cbe_tmp__3140;
  unsigned int llvm_cbe_tmp__3141;
  unsigned int llvm_cbe_tmp__3142;
  unsigned int llvm_cbe_tmp__3143;
  unsigned int llvm_cbe_tmp__3144;
  unsigned char llvm_cbe_tmp__3145;
  unsigned char llvm_cbe_tmp__3146;
  unsigned int llvm_cbe_tmp__3147;
  unsigned char llvm_cbe_tmp__3148;
  bool llvm_cbe_tmp__3149;
  unsigned long long llvm_cbe_tmp__3150;
  bool llvm_cbe_tmp__3151;
  unsigned long long llvm_cbe_tmp__3152;
  unsigned short llvm_cbe_tmp__3153;
  unsigned long long llvm_cbe_tmp__3154;
  unsigned short llvm_cbe_tmp__3155;
  unsigned long long llvm_cbe_tmp__3156;
  unsigned short llvm_cbe_tmp__3157;
  unsigned long long llvm_cbe_tmp__3158;
  unsigned short llvm_cbe_tmp__3159;
  unsigned long long llvm_cbe_tmp__3160;
  unsigned short llvm_cbe_tmp__3161;
  unsigned long long llvm_cbe_tmp__3162;
  unsigned short llvm_cbe_tmp__3163;
  unsigned long long llvm_cbe_tmp__3164;
  unsigned int llvm_cbe_tmp__3165;
  unsigned long long llvm_cbe_tmp__3166;
  unsigned int llvm_cbe_tmp__3167;
  unsigned long long llvm_cbe_tmp__3168;
  bool llvm_cbe_tmp__3169;
  unsigned long long llvm_cbe_tmp__3170;
  bool llvm_cbe_tmp__3171;
  unsigned long long llvm_cbe_tmp__3172;
  unsigned int llvm_cbe_tmp__3173;
  unsigned long long llvm_cbe_tmp__3174;
  unsigned int llvm_cbe_tmp__3175;
  unsigned long long llvm_cbe_tmp__3176;
  unsigned int llvm_cbe_tmp__3177;
  unsigned long long llvm_cbe_tmp__3178;
  unsigned int llvm_cbe_tmp__3179;
  unsigned long long llvm_cbe_tmp__3180;
  bool llvm_cbe_tmp__3181;
  unsigned long long llvm_cbe_tmp__3182;
  float llvm_cbe_tmp__3183;
  unsigned long long llvm_cbe_tmp__3184;
  float llvm_cbe_tmp__3185;
  unsigned long long llvm_cbe_tmp__3186;
  float llvm_cbe_tmp__3187;
  unsigned long long llvm_cbe_tmp__3188;
  unsigned int llvm_cbe_tmp__3189;
  unsigned long long llvm_cbe_tmp__3190;
  unsigned short llvm_cbe_tmp__3191;
  unsigned long long llvm_cbe_tmp__3192;
  unsigned int llvm_cbe_tmp__3193;
  unsigned long long llvm_cbe_tmp__3194;
  unsigned short llvm_cbe_tmp__3195;
  unsigned long long llvm_cbe_tmp__3196;
  unsigned short llvm_cbe_tmp__3197;
  unsigned long long llvm_cbe_tmp__3198;
  unsigned char *llvm_cbe_tmp__3199;
  unsigned char *llvm_cbe_tmp__3200;
  bool llvm_cbe_tmp__3201;
  unsigned char *llvm_cbe_tmp__3202;
  unsigned char *llvm_cbe_tmp__3203;
  bool llvm_cbe_tmp__3204;
  unsigned char *llvm_cbe_tmp__3205;
  unsigned char *llvm_cbe_tmp__3206;
  bool llvm_cbe_tmp__3207;
  unsigned short llvm_cbe_tmp__3208;
  unsigned short llvm_cbe_tmp__3209;
  unsigned short llvm_cbe_tmp__3210;
  unsigned short llvm_cbe_tmp__3211;
  float llvm_cbe_tmp__3212;
  float llvm_cbe_tmp__3213;
  unsigned short llvm_cbe_tmp__3214;
  float llvm_cbe_tmp__3215;
  unsigned short llvm_cbe_tmp__3216;
  float *llvm_cbe_tmp__3217;
  float llvm_cbe_tmp__3218;
  float llvm_cbe_tmp__3219;
  float llvm_cbe_tmp__3220;
  unsigned short llvm_cbe_tmp__3221;
  unsigned short llvm_cbe_tmp__3222;
  unsigned char llvm_cbe_tmp__3223;
  unsigned int llvm_cbe_tmp__3224;
  unsigned int llvm_cbe_tmp__3225;
  unsigned int llvm_cbe_tmp__3226;
  unsigned int llvm_cbe_tmp__3227;
  unsigned int llvm_cbe_tmp__3228;
  unsigned int llvm_cbe_tmp__3229;
  unsigned char llvm_cbe_tmp__3230;
  unsigned char llvm_cbe_tmp__3231;
  unsigned int llvm_cbe_tmp__3232;
  unsigned char llvm_cbe_tmp__3233;
  bool llvm_cbe_tmp__3234;
  unsigned long long llvm_cbe_tmp__3235;
  bool llvm_cbe_tmp__3236;
  unsigned long long llvm_cbe_tmp__3237;
  unsigned short llvm_cbe_tmp__3238;
  unsigned long long llvm_cbe_tmp__3239;
  unsigned short llvm_cbe_tmp__3240;
  unsigned long long llvm_cbe_tmp__3241;
  unsigned short llvm_cbe_tmp__3242;
  unsigned long long llvm_cbe_tmp__3243;
  unsigned short llvm_cbe_tmp__3244;
  unsigned long long llvm_cbe_tmp__3245;
  unsigned short llvm_cbe_tmp__3246;
  unsigned long long llvm_cbe_tmp__3247;
  unsigned short llvm_cbe_tmp__3248;
  unsigned long long llvm_cbe_tmp__3249;
  unsigned int llvm_cbe_tmp__3250;
  unsigned long long llvm_cbe_tmp__3251;
  unsigned int llvm_cbe_tmp__3252;
  unsigned long long llvm_cbe_tmp__3253;
  bool llvm_cbe_tmp__3254;
  unsigned long long llvm_cbe_tmp__3255;
  bool llvm_cbe_tmp__3256;
  unsigned long long llvm_cbe_tmp__3257;
  unsigned int llvm_cbe_tmp__3258;
  unsigned long long llvm_cbe_tmp__3259;
  unsigned int llvm_cbe_tmp__3260;
  unsigned long long llvm_cbe_tmp__3261;
  unsigned int llvm_cbe_tmp__3262;
  unsigned long long llvm_cbe_tmp__3263;
  unsigned int llvm_cbe_tmp__3264;
  unsigned long long llvm_cbe_tmp__3265;
  bool llvm_cbe_tmp__3266;
  unsigned long long llvm_cbe_tmp__3267;
  float llvm_cbe_tmp__3268;
  unsigned long long llvm_cbe_tmp__3269;
  float llvm_cbe_tmp__3270;
  unsigned long long llvm_cbe_tmp__3271;
  float llvm_cbe_tmp__3272;
  unsigned long long llvm_cbe_tmp__3273;
  unsigned int llvm_cbe_tmp__3274;
  unsigned long long llvm_cbe_tmp__3275;
  unsigned short llvm_cbe_tmp__3276;
  unsigned long long llvm_cbe_tmp__3277;
  unsigned int llvm_cbe_tmp__3278;
  unsigned long long llvm_cbe_tmp__3279;
  unsigned short llvm_cbe_tmp__3280;
  unsigned long long llvm_cbe_tmp__3281;
  unsigned short llvm_cbe_tmp__3282;
  unsigned long long llvm_cbe_tmp__3283;
  unsigned char *llvm_cbe_tmp__3284;
  unsigned char *llvm_cbe_tmp__3285;
  bool llvm_cbe_tmp__3286;
  unsigned char *llvm_cbe_tmp__3287;
  unsigned char *llvm_cbe_tmp__3288;
  bool llvm_cbe_tmp__3289;
  unsigned char *llvm_cbe_tmp__3290;
  unsigned char *llvm_cbe_tmp__3291;
  bool llvm_cbe_tmp__3292;

  *(&llvm_cbe_tmp__3062) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3063) = llvm_cbe_nh;
  *(&llvm_cbe_tmp__3064) = llvm_cbe_nv;
  llvm_cbe_tmp__3079 = *(&llvm_cbe_tmp__3062);
  *(&llvm_cbe_tmp__3065) = ((unsigned char )1);
  llvm_cbe_tmp__3080 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__3079->field36)), (&llvm_cbe_tmp__3065)))&1);
  *(&llvm_cbe_tmp__3066) = ((unsigned char )0);
  llvm_cbe_tmp__3081 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__3079->field37)), (&llvm_cbe_tmp__3066)))&1);
  *((&GM.field17)) = 0ull;
  *(&llvm_cbe_tmp__3067) = ((unsigned char )0);
  llvm_cbe_tmp__3082 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__3079->field12)), (&llvm_cbe_tmp__3067)))&1);
  *(&rst_inp) = ((unsigned char )0);
  *((&GM.field34)) = 2ull;
  *(&llvm_cbe_tmp__3068) = ((unsigned char )1);
  llvm_cbe_tmp__3083 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__3079->field38)), (&llvm_cbe_tmp__3068)))&1);
  *((&GM.field24)) = 1ull;
  *(&upc) = 2u;
  llvm_cbe_tmp__3084 = *(&conf_done_inp);
  *((&((&llvm_cbe_tmp__3079->field13))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__3084&1u))&1))));
  llvm_cbe_tmp__3085 = *(&conf_num_hidden_inp);
  *((&((&llvm_cbe_tmp__3079->field14))->field0)) = llvm_cbe_tmp__3085;
  llvm_cbe_tmp__3086 = *(&conf_num_visible_inp);
  *((&((&llvm_cbe_tmp__3079->field15))->field0)) = llvm_cbe_tmp__3086;
  llvm_cbe_tmp__3087 = *(&conf_num_users_inp);
  *((&((&llvm_cbe_tmp__3079->field16))->field0)) = llvm_cbe_tmp__3087;
  llvm_cbe_tmp__3088 = *(&conf_num_loops_inp);
  *((&((&llvm_cbe_tmp__3079->field17))->field0)) = llvm_cbe_tmp__3088;
  llvm_cbe_tmp__3089 = *(&conf_num_testusers_inp);
  *((&((&llvm_cbe_tmp__3079->field18))->field0)) = llvm_cbe_tmp__3089;
  llvm_cbe_tmp__3090 = *(&conf_num_movies_inp);
  *((&((&llvm_cbe_tmp__3079->field19))->field0)) = llvm_cbe_tmp__3090;
  llvm_cbe_tmp__3091 = *(&rst_inp);
  *((&((&llvm_cbe_tmp__3079->field1))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__3091&1u))&1))));
  llvm_cbe_tmp__3092 = *((&GM.field8));
  *(&llvm_cbe_tmp__3069) = (((unsigned char )(bool )(llvm_cbe_tmp__3092 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__3079->field36)), (&llvm_cbe_tmp__3069));
  llvm_cbe_tmp__3093 = *((&GM.field3));
  *(&llvm_cbe_tmp__3070) = (((unsigned char )(bool )(llvm_cbe_tmp__3093 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__3079->field12)), (&llvm_cbe_tmp__3070));
  llvm_cbe_tmp__3094 = *((&GM.field29));
  *(&llvm_cbe_tmp__3071) = (((unsigned int )llvm_cbe_tmp__3094));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__3079->field2)), (&llvm_cbe_tmp__3071));
  llvm_cbe_tmp__3095 = *((&GM.field30));
  *(&llvm_cbe_tmp__3072) = (((unsigned int )llvm_cbe_tmp__3095));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__3079->field3)), (&llvm_cbe_tmp__3072));
  llvm_cbe_tmp__3096 = *((&GM.field31));
  *(&llvm_cbe_tmp__3073) = (((unsigned char )(bool )(llvm_cbe_tmp__3096 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__3079->field4)), (&llvm_cbe_tmp__3073));
  llvm_cbe_tmp__3097 = *(&rd_grant_inp);
  *((&((&llvm_cbe_tmp__3079->field5))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__3097&1u))&1))));
  llvm_cbe_tmp__3098 = *(&data_in_inp);
  *((&((&llvm_cbe_tmp__3079->field6))->field0)) = llvm_cbe_tmp__3098;
  llvm_cbe_tmp__3099 = *(&wr_grant_inp);
  *((&((&llvm_cbe_tmp__3079->field10))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__3099&1u))&1))));
  llvm_cbe_tmp__3100 = *((&GM.field39));
  *(&llvm_cbe_tmp__3074) = (((unsigned char )(bool )(llvm_cbe_tmp__3100 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__3079->field9)), (&llvm_cbe_tmp__3074));
  llvm_cbe_tmp__3101 = *((&GM.field37));
  *(&llvm_cbe_tmp__3075) = (((unsigned int )llvm_cbe_tmp__3101));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__3079->field7)), (&llvm_cbe_tmp__3075));
  llvm_cbe_tmp__3102 = *((&GM.field38));
  *(&llvm_cbe_tmp__3076) = (((unsigned int )llvm_cbe_tmp__3102));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__3079->field8)), (&llvm_cbe_tmp__3076));
  llvm_cbe_tmp__3103 = *((&GM.field2));
  *(&llvm_cbe_tmp__3077) = (((unsigned int )llvm_cbe_tmp__3103));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__3079->field11)), (&llvm_cbe_tmp__3077));
  llvm_cbe_tmp__3104 = *((&GM.field20));
  *(&llvm_cbe_tmp__3078) = (((unsigned char )(bool )(llvm_cbe_tmp__3104 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__3079->field38)), (&llvm_cbe_tmp__3078));
  llvm_cbe_tmp__3105 = *((&GM.field23));
  *(&llvm_cbe_sum) = (((float )((((double )(signed long long )(llvm_cbe_tmp__3105 & 65535ull))) / 0x1p+1)));
  llvm_cbe_tmp__3106 = *((&GM.field21));
  *(&llvm_cbe_max) = (((float )((((double )(signed long long )(llvm_cbe_tmp__3106 & 65535ull))) / 0x1p+1)));
  llvm_cbe_tmp__3107 = *((&GM.field32));
  *(&llvm_cbe_sumOfpow2) = (((float )((((double )(unsigned long long )llvm_cbe_tmp__3107)) / 0x1p+0)));
  llvm_cbe_tmp__3108 = *((&GM.field9));
  *(&llvm_cbe_j) = (((unsigned short )llvm_cbe_tmp__3108));
  llvm_cbe_tmp__3109 = *((&GM.field25));
  *(&llvm_cbe_v) = (((unsigned short )llvm_cbe_tmp__3109));
  llvm_cbe_tmp__3110 = *((&GM.field19));
  *(&llvm_cbe_h) = (((unsigned short )llvm_cbe_tmp__3110));
  llvm_cbe_tmp__3111 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__3079->field20)), 0u);
  llvm_cbe_tmp__3112 = *((&GM.field1.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__3111, llvm_cbe_tmp__3112);
  llvm_cbe_tmp__3113 = _ZN13SysCArray2DstIhLj2ELj128EEixEj(((&llvm_cbe_tmp__3079->field28)), 0u);
  llvm_cbe_tmp__3114 = *((&GM.field22.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__3113, llvm_cbe_tmp__3114);
  llvm_cbe_tmp__3115 = *((&((&llvm_cbe_tmp__3079->field23))->field0));
  llvm_cbe_tmp__3116 = *((&GM.field4.field0));
  __CPROVER_array_copy((((unsigned char *)llvm_cbe_tmp__3115)), llvm_cbe_tmp__3116);
  llvm_cbe_tmp__3117 = *((&((&llvm_cbe_tmp__3079->field22))->field0));
  llvm_cbe_tmp__3118 = *((&GM.field6.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__3117, llvm_cbe_tmp__3118);
  llvm_cbe_tmp__3119 = *((&((&llvm_cbe_tmp__3079->field26))->field0));
  llvm_cbe_tmp__3120 = *((&GM.field35.field0));
  __CPROVER_array_copy((((unsigned char *)llvm_cbe_tmp__3119)), (((unsigned char *)llvm_cbe_tmp__3120)));
  llvm_cbe_tmp__3121 = *((&GM.field18.field0));
  __CPROVER_array_copy((((unsigned char *)((&llvm_cbe_pow2.array[((signed int )0u)])))), (((unsigned char *)llvm_cbe_tmp__3121)));
  llvm_cbe_tmp__3122 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3123 = *(&llvm_cbe_tmp__3063);
  __CPROVER_assume((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3122))) <= ((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3123)))));
  llvm_cbe_tmp__3124 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3125 = *(&llvm_cbe_tmp__3064);
  __CPROVER_assume((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3124))) < ((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3125)))));
  llvm_cbe_tmp__3126 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3127 = _ZN11SysCArray1DIbLj128EEixEj(((&llvm_cbe_tmp__3079->field22)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3126)));
  llvm_cbe_tmp__3128 = *llvm_cbe_tmp__3127;
  *(&llvm_cbe_tmp2) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__3128&1u))&1))));
  _Z4waitv();
  llvm_cbe_tmp__3129 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3130 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3131 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3132 = _ZN11SysCArray2DIfLj501ELj101EEixEj(((&llvm_cbe_tmp__3079->field23)), (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3130))) + ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3131)))))));
  llvm_cbe_tmp__3133 = *((&llvm_cbe_tmp__3132[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__3129)))]));
  *(&llvm_cbe_tmp1) = llvm_cbe_tmp__3133;
  _Z4waitv();
  llvm_cbe_tmp__3134 = *(&llvm_cbe_tmp2);
  if ((((((bool )llvm_cbe_tmp__3134&1u))&1))) {
    goto llvm_cbe_tmp__3293;
  } else {
    goto llvm_cbe_tmp__3294;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3295:
  llvm_cbe_tmp__3135 = *(&llvm_cbe_h);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3135))) < ((signed int )101u))) {
    goto llvm_cbe_tmp__3296;
  } else {
    goto llvm_cbe_tmp__3297;
  }

llvm_cbe_tmp__3298:
  *(&llvm_cbe_sum) = 0x0p+0;
  *(&llvm_cbe_h) = ((unsigned short )0);
  goto llvm_cbe_tmp__3295;

llvm_cbe_tmp__3299:
  llvm_cbe_tmp__3221 = *(&llvm_cbe_j);
  *(&llvm_cbe_j) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3221) + ((unsigned short )((unsigned short )1)))))));
  llvm_cbe_tmp__3222 = *(&llvm_cbe_j);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3222))) < ((signed int )5u))) {
    goto llvm_cbe_tmp__3298;
  } else {
    goto llvm_cbe_tmp__3300;
  }

llvm_cbe_tmp__3301:
  llvm_cbe_tmp__3220 = *(&llvm_cbe_sum);
  *(&llvm_cbe_max) = llvm_cbe_tmp__3220;
  goto llvm_cbe_tmp__3299;

llvm_cbe_tmp__3297:
  llvm_cbe_tmp__3215 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__3216 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3217 = _ZN11SysCArray1DIfLj5EEixEj(((&llvm_cbe_tmp__3079->field26)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3216)));
  *llvm_cbe_tmp__3217 = llvm_cbe_tmp__3215;
  _Z4waitv();
  llvm_cbe_tmp__3218 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__3219 = *(&llvm_cbe_max);
  if ((llvm_fcmp_ogt(llvm_cbe_tmp__3218, llvm_cbe_tmp__3219))) {
    goto llvm_cbe_tmp__3301;
  } else {
    goto llvm_cbe_tmp__3299;
  }

llvm_cbe_tmp__3296:
  llvm_cbe_tmp__3136 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3137 = *(&llvm_cbe_tmp__3063);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__3136)) == (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3137))) + ((unsigned int )1u)))))) {
    goto llvm_cbe_tmp__3297;
  } else {
    goto llvm_cbe_tmp__3302;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3302:
  llvm_cbe_tmp__3138 = *(&conf_done_inp);
  llvm_cbe_tmp__3139 = *(&conf_num_hidden_inp);
  llvm_cbe_tmp__3140 = *(&conf_num_visible_inp);
  llvm_cbe_tmp__3141 = *(&conf_num_users_inp);
  llvm_cbe_tmp__3142 = *(&conf_num_loops_inp);
  llvm_cbe_tmp__3143 = *(&conf_num_testusers_inp);
  llvm_cbe_tmp__3144 = *(&conf_num_movies_inp);
  llvm_cbe_tmp__3145 = *(&rst_inp);
  llvm_cbe_tmp__3146 = *(&rd_grant_inp);
  llvm_cbe_tmp__3147 = *(&data_in_inp);
  llvm_cbe_tmp__3148 = *(&wr_grant_inp);
  _ZN13model_predict6updateElllllllllll((&GM), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3138&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3139)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3140)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3141)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3142)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3143)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3144)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3145&1u))&1)))), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3146&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3147)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3148&1u))&1)))));
  llvm_cbe_tmp__3149 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__3079->field36))))&1);
  llvm_cbe_tmp__3150 = *((&GM.field8));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3149)) == llvm_cbe_tmp__3150), ((&_OC_str1.array[((signed int )0u)])));
  llvm_cbe_tmp__3151 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__3079->field12))))&1);
  llvm_cbe_tmp__3152 = *((&GM.field3));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3151)) == llvm_cbe_tmp__3152), ((&_OC_str2.array[((signed int )0u)])));
  llvm_cbe_tmp__3153 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__3079->field30)));
  llvm_cbe_tmp__3154 = *((&GM.field11));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3153)) == llvm_cbe_tmp__3154), ((&_OC_str3.array[((signed int )0u)])));
  llvm_cbe_tmp__3155 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__3079->field31)));
  llvm_cbe_tmp__3156 = *((&GM.field16));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3155)) == llvm_cbe_tmp__3156), ((&_OC_str4.array[((signed int )0u)])));
  llvm_cbe_tmp__3157 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__3079->field32)));
  llvm_cbe_tmp__3158 = *((&GM.field15));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3157)) == llvm_cbe_tmp__3158), ((&_OC_str5.array[((signed int )0u)])));
  llvm_cbe_tmp__3159 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__3079->field33)));
  llvm_cbe_tmp__3160 = *((&GM.field12));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3159)) == llvm_cbe_tmp__3160), ((&_OC_str6.array[((signed int )0u)])));
  llvm_cbe_tmp__3161 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__3079->field34)));
  llvm_cbe_tmp__3162 = *((&GM.field14));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3161)) == llvm_cbe_tmp__3162), ((&_OC_str7.array[((signed int )0u)])));
  llvm_cbe_tmp__3163 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__3079->field35)));
  llvm_cbe_tmp__3164 = *((&GM.field13));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3163)) == llvm_cbe_tmp__3164), ((&_OC_str8.array[((signed int )0u)])));
  llvm_cbe_tmp__3165 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__3079->field2)));
  llvm_cbe_tmp__3166 = *((&GM.field29));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3165)) == llvm_cbe_tmp__3166), ((&_OC_str9.array[((signed int )0u)])));
  llvm_cbe_tmp__3167 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__3079->field3)));
  llvm_cbe_tmp__3168 = *((&GM.field30));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3167)) == llvm_cbe_tmp__3168), ((&_OC_str10.array[((signed int )0u)])));
  llvm_cbe_tmp__3169 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__3079->field4))))&1);
  llvm_cbe_tmp__3170 = *((&GM.field31));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3169)) == llvm_cbe_tmp__3170), ((&_OC_str11.array[((signed int )0u)])));
  llvm_cbe_tmp__3171 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__3079->field9))))&1);
  llvm_cbe_tmp__3172 = *((&GM.field39));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3171)) == llvm_cbe_tmp__3172), ((&_OC_str12.array[((signed int )0u)])));
  llvm_cbe_tmp__3173 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__3079->field7)));
  llvm_cbe_tmp__3174 = *((&GM.field37));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3173)) == llvm_cbe_tmp__3174), ((&_OC_str13.array[((signed int )0u)])));
  llvm_cbe_tmp__3175 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__3079->field8)));
  llvm_cbe_tmp__3176 = *((&GM.field38));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3175)) == llvm_cbe_tmp__3176), ((&_OC_str14.array[((signed int )0u)])));
  llvm_cbe_tmp__3177 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__3079->field11)));
  llvm_cbe_tmp__3178 = *((&GM.field2));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3177)) == llvm_cbe_tmp__3178), ((&_OC_str15.array[((signed int )0u)])));
  llvm_cbe_tmp__3179 = *(&upc);
  llvm_cbe_tmp__3180 = *((&GM.field34));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3179)) == llvm_cbe_tmp__3180), ((&_OC_str16.array[((signed int )0u)])));
  llvm_cbe_tmp__3181 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__3079->field38))))&1);
  llvm_cbe_tmp__3182 = *((&GM.field20));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3181)) == llvm_cbe_tmp__3182), ((&_OC_str17.array[((signed int )0u)])));
  llvm_cbe_tmp__3183 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__3184 = *((&GM.field23));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__3183)), ((((double )(signed long long )(llvm_cbe_tmp__3184 & 65535ull))) / 0x1p+1))), ((&_OC_str18.array[((signed int )0u)])));
  llvm_cbe_tmp__3185 = *(&llvm_cbe_max);
  llvm_cbe_tmp__3186 = *((&GM.field21));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__3185)), ((((double )(signed long long )(llvm_cbe_tmp__3186 & 65535ull))) / 0x1p+1))), ((&_OC_str19.array[((signed int )0u)])));
  llvm_cbe_tmp__3187 = *(&llvm_cbe_sumOfpow2);
  llvm_cbe_tmp__3188 = *((&GM.field32));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__3187)), ((((double )(unsigned long long )llvm_cbe_tmp__3188)) / 0x1p+0))), ((&_OC_str20.array[((signed int )0u)])));
  llvm_cbe_tmp__3189 = *(&per_v_pc);
  llvm_cbe_tmp__3190 = *((&GM.field17));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3189)) == llvm_cbe_tmp__3190), ((&_OC_str21.array[((signed int )0u)])));
  llvm_cbe_tmp__3191 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3192 = *((&GM.field9));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3191)) == llvm_cbe_tmp__3192), ((&_OC_str22.array[((signed int )0u)])));
  llvm_cbe_tmp__3193 = *(&predict_upc);
  llvm_cbe_tmp__3194 = *((&GM.field24));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3193)) == llvm_cbe_tmp__3194), ((&_OC_str23.array[((signed int )0u)])));
  llvm_cbe_tmp__3195 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3196 = *((&GM.field25));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3195)) == llvm_cbe_tmp__3196), ((&_OC_str24.array[((signed int )0u)])));
  llvm_cbe_tmp__3197 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3198 = *((&GM.field19));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3197)) == llvm_cbe_tmp__3198), ((&_OC_str25.array[((signed int )0u)])));
  llvm_cbe_tmp__3199 = *((&GM.field1.field0));
  llvm_cbe_tmp__3200 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__3079->field20)), 0u);
  llvm_cbe_tmp__3201 = ((__CPROVER_array_equal(llvm_cbe_tmp__3199, llvm_cbe_tmp__3200))&1);
  __CPROVER_assert(llvm_cbe_tmp__3201, ((&_OC_str26.array[((signed int )0u)])));
  llvm_cbe_tmp__3202 = *((&GM.field22.field0));
  llvm_cbe_tmp__3203 = _ZN13SysCArray2DstIhLj2ELj128EEixEj(((&llvm_cbe_tmp__3079->field28)), 0u);
  llvm_cbe_tmp__3204 = ((__CPROVER_array_equal(llvm_cbe_tmp__3202, llvm_cbe_tmp__3203))&1);
  __CPROVER_assert(llvm_cbe_tmp__3204, ((&_OC_str27.array[((signed int )0u)])));
  llvm_cbe_tmp__3205 = *((&GM.field6.field0));
  llvm_cbe_tmp__3206 = *((&((&llvm_cbe_tmp__3079->field22))->field0));
  llvm_cbe_tmp__3207 = ((__CPROVER_array_equal(llvm_cbe_tmp__3205, llvm_cbe_tmp__3206))&1);
  __CPROVER_assert(llvm_cbe_tmp__3207, ((&_OC_str28.array[((signed int )0u)])));
  llvm_cbe_tmp__3208 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3209 = *(&llvm_cbe_tmp__3063);
  __CPROVER_assert((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3208))) <= ((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3209)))), ((&_OC_str29.array[((signed int )0u)])));
  llvm_cbe_tmp__3210 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3211 = *(&llvm_cbe_tmp__3064);
  __CPROVER_assert((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3210))) < ((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3211)))), ((&_OC_str29.array[((signed int )0u)])));
  goto llvm_cbe_tmp__3303;

llvm_cbe_tmp__3293:
  llvm_cbe_tmp__3212 = *(&llvm_cbe_tmp1);
  llvm_cbe_tmp__3213 = *(&llvm_cbe_sum);
  *(&llvm_cbe_sum) = (((float )(llvm_cbe_tmp__3213 + llvm_cbe_tmp__3212)));
  goto llvm_cbe_tmp__3294;

llvm_cbe_tmp__3294:
  _Z4waitv();
  llvm_cbe_tmp__3214 = *(&llvm_cbe_h);
  *(&llvm_cbe_h) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3214) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3295;

llvm_cbe_tmp__3300:
  *(&per_v_pc) = 1u;
  *(&predict_upc) = 1u;
  llvm_cbe_tmp__3223 = *(&conf_done_inp);
  llvm_cbe_tmp__3224 = *(&conf_num_hidden_inp);
  llvm_cbe_tmp__3225 = *(&conf_num_visible_inp);
  llvm_cbe_tmp__3226 = *(&conf_num_users_inp);
  llvm_cbe_tmp__3227 = *(&conf_num_loops_inp);
  llvm_cbe_tmp__3228 = *(&conf_num_testusers_inp);
  llvm_cbe_tmp__3229 = *(&conf_num_movies_inp);
  llvm_cbe_tmp__3230 = *(&rst_inp);
  llvm_cbe_tmp__3231 = *(&rd_grant_inp);
  llvm_cbe_tmp__3232 = *(&data_in_inp);
  llvm_cbe_tmp__3233 = *(&wr_grant_inp);
  _ZN13model_predict6updateElllllllllll((&GM), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3223&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3224)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3225)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3226)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3227)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3228)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3229)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3230&1u))&1)))), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3231&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3232)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3233&1u))&1)))));
  llvm_cbe_tmp__3234 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__3079->field36))))&1);
  llvm_cbe_tmp__3235 = *((&GM.field8));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3234)) == llvm_cbe_tmp__3235), ((&_OC_str1.array[((signed int )0u)])));
  llvm_cbe_tmp__3236 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__3079->field12))))&1);
  llvm_cbe_tmp__3237 = *((&GM.field3));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3236)) == llvm_cbe_tmp__3237), ((&_OC_str2.array[((signed int )0u)])));
  llvm_cbe_tmp__3238 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__3079->field30)));
  llvm_cbe_tmp__3239 = *((&GM.field11));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3238)) == llvm_cbe_tmp__3239), ((&_OC_str3.array[((signed int )0u)])));
  llvm_cbe_tmp__3240 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__3079->field31)));
  llvm_cbe_tmp__3241 = *((&GM.field16));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3240)) == llvm_cbe_tmp__3241), ((&_OC_str4.array[((signed int )0u)])));
  llvm_cbe_tmp__3242 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__3079->field32)));
  llvm_cbe_tmp__3243 = *((&GM.field15));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3242)) == llvm_cbe_tmp__3243), ((&_OC_str5.array[((signed int )0u)])));
  llvm_cbe_tmp__3244 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__3079->field33)));
  llvm_cbe_tmp__3245 = *((&GM.field12));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3244)) == llvm_cbe_tmp__3245), ((&_OC_str6.array[((signed int )0u)])));
  llvm_cbe_tmp__3246 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__3079->field34)));
  llvm_cbe_tmp__3247 = *((&GM.field14));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3246)) == llvm_cbe_tmp__3247), ((&_OC_str7.array[((signed int )0u)])));
  llvm_cbe_tmp__3248 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__3079->field35)));
  llvm_cbe_tmp__3249 = *((&GM.field13));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3248)) == llvm_cbe_tmp__3249), ((&_OC_str8.array[((signed int )0u)])));
  llvm_cbe_tmp__3250 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__3079->field2)));
  llvm_cbe_tmp__3251 = *((&GM.field29));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3250)) == llvm_cbe_tmp__3251), ((&_OC_str9.array[((signed int )0u)])));
  llvm_cbe_tmp__3252 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__3079->field3)));
  llvm_cbe_tmp__3253 = *((&GM.field30));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3252)) == llvm_cbe_tmp__3253), ((&_OC_str10.array[((signed int )0u)])));
  llvm_cbe_tmp__3254 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__3079->field4))))&1);
  llvm_cbe_tmp__3255 = *((&GM.field31));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3254)) == llvm_cbe_tmp__3255), ((&_OC_str11.array[((signed int )0u)])));
  llvm_cbe_tmp__3256 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__3079->field9))))&1);
  llvm_cbe_tmp__3257 = *((&GM.field39));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3256)) == llvm_cbe_tmp__3257), ((&_OC_str12.array[((signed int )0u)])));
  llvm_cbe_tmp__3258 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__3079->field7)));
  llvm_cbe_tmp__3259 = *((&GM.field37));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3258)) == llvm_cbe_tmp__3259), ((&_OC_str13.array[((signed int )0u)])));
  llvm_cbe_tmp__3260 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__3079->field8)));
  llvm_cbe_tmp__3261 = *((&GM.field38));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3260)) == llvm_cbe_tmp__3261), ((&_OC_str14.array[((signed int )0u)])));
  llvm_cbe_tmp__3262 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__3079->field11)));
  llvm_cbe_tmp__3263 = *((&GM.field2));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3262)) == llvm_cbe_tmp__3263), ((&_OC_str15.array[((signed int )0u)])));
  llvm_cbe_tmp__3264 = *(&upc);
  llvm_cbe_tmp__3265 = *((&GM.field34));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3264)) == llvm_cbe_tmp__3265), ((&_OC_str16.array[((signed int )0u)])));
  llvm_cbe_tmp__3266 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__3079->field38))))&1);
  llvm_cbe_tmp__3267 = *((&GM.field20));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3266)) == llvm_cbe_tmp__3267), ((&_OC_str17.array[((signed int )0u)])));
  llvm_cbe_tmp__3268 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__3269 = *((&GM.field23));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__3268)), ((((double )(signed long long )(llvm_cbe_tmp__3269 & 65535ull))) / 0x1p+1))), ((&_OC_str18.array[((signed int )0u)])));
  llvm_cbe_tmp__3270 = *(&llvm_cbe_max);
  llvm_cbe_tmp__3271 = *((&GM.field21));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__3270)), ((((double )(signed long long )(llvm_cbe_tmp__3271 & 65535ull))) / 0x1p+1))), ((&_OC_str19.array[((signed int )0u)])));
  llvm_cbe_tmp__3272 = *(&llvm_cbe_sumOfpow2);
  llvm_cbe_tmp__3273 = *((&GM.field32));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__3272)), ((((double )(unsigned long long )llvm_cbe_tmp__3273)) / 0x1p+0))), ((&_OC_str20.array[((signed int )0u)])));
  llvm_cbe_tmp__3274 = *(&per_v_pc);
  llvm_cbe_tmp__3275 = *((&GM.field17));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3274)) == llvm_cbe_tmp__3275), ((&_OC_str21.array[((signed int )0u)])));
  llvm_cbe_tmp__3276 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3277 = *((&GM.field9));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3276)) == llvm_cbe_tmp__3277), ((&_OC_str22.array[((signed int )0u)])));
  llvm_cbe_tmp__3278 = *(&predict_upc);
  llvm_cbe_tmp__3279 = *((&GM.field24));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3278)) == llvm_cbe_tmp__3279), ((&_OC_str23.array[((signed int )0u)])));
  llvm_cbe_tmp__3280 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3281 = *((&GM.field25));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3280)) == llvm_cbe_tmp__3281), ((&_OC_str24.array[((signed int )0u)])));
  llvm_cbe_tmp__3282 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3283 = *((&GM.field19));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3282)) == llvm_cbe_tmp__3283), ((&_OC_str25.array[((signed int )0u)])));
  llvm_cbe_tmp__3284 = *((&GM.field1.field0));
  llvm_cbe_tmp__3285 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__3079->field20)), 0u);
  llvm_cbe_tmp__3286 = ((__CPROVER_array_equal(llvm_cbe_tmp__3284, llvm_cbe_tmp__3285))&1);
  __CPROVER_assert(llvm_cbe_tmp__3286, ((&_OC_str26.array[((signed int )0u)])));
  llvm_cbe_tmp__3287 = *((&GM.field22.field0));
  llvm_cbe_tmp__3288 = _ZN13SysCArray2DstIhLj2ELj128EEixEj(((&llvm_cbe_tmp__3079->field28)), 0u);
  llvm_cbe_tmp__3289 = ((__CPROVER_array_equal(llvm_cbe_tmp__3287, llvm_cbe_tmp__3288))&1);
  __CPROVER_assert(llvm_cbe_tmp__3289, ((&_OC_str27.array[((signed int )0u)])));
  llvm_cbe_tmp__3290 = *((&GM.field6.field0));
  llvm_cbe_tmp__3291 = *((&((&llvm_cbe_tmp__3079->field22))->field0));
  llvm_cbe_tmp__3292 = ((__CPROVER_array_equal(llvm_cbe_tmp__3290, llvm_cbe_tmp__3291))&1);
  __CPROVER_assert(llvm_cbe_tmp__3292, ((&_OC_str28.array[((signed int )0u)])));
  goto llvm_cbe_tmp__3303;

llvm_cbe_tmp__3303:
  return;
}


unsigned char *_ZN11SysCArray1DIbLj512EEixEj(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned int llvm_cbe_idx) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3304;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3305;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3306;
  unsigned int llvm_cbe_tmp__3307;
  unsigned char *llvm_cbe_tmp__3308;

  *(&llvm_cbe_tmp__3304) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3305) = llvm_cbe_idx;
  llvm_cbe_tmp__3306 = *(&llvm_cbe_tmp__3304);
  llvm_cbe_tmp__3307 = *(&llvm_cbe_tmp__3305);
  llvm_cbe_tmp__3308 = *((&llvm_cbe_tmp__3306->field0));
  return ((&llvm_cbe_tmp__3308[((signed long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__3307)))]));
}


unsigned char *_ZN13SysCArray2DstIhLj2ELj128EEixEj(struct l_class_OC_SysCArray2Dst *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  unsigned char *llvm_cbe_tmp__3309;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3310;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3311;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3312;
  unsigned int llvm_cbe_tmp__3313;
  unsigned char *llvm_cbe_tmp__3314;
  unsigned int llvm_cbe_tmp__3315;
  unsigned char *llvm_cbe_tmp__3316;
  unsigned char *llvm_cbe_tmp__3317;

  *(&llvm_cbe_tmp__3310) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3311) = llvm_cbe_Xidx;
  llvm_cbe_tmp__3312 = *(&llvm_cbe_tmp__3310);
  llvm_cbe_tmp__3313 = *(&llvm_cbe_tmp__3311);
  if ((llvm_cbe_tmp__3313 == 0u)) {
    goto llvm_cbe_tmp__3318;
  } else {
    goto llvm_cbe_tmp__3319;
  }

llvm_cbe_tmp__3318:
  llvm_cbe_tmp__3314 = *((&llvm_cbe_tmp__3312->field1));
  *(&llvm_cbe_tmp__3309) = llvm_cbe_tmp__3314;
  goto llvm_cbe_tmp__3320;

llvm_cbe_tmp__3319:
  llvm_cbe_tmp__3315 = *(&llvm_cbe_tmp__3311);
  llvm_cbe_tmp__3316 = *((&llvm_cbe_tmp__3312->field0));
  *(&llvm_cbe_tmp__3309) = ((&llvm_cbe_tmp__3316[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__3315) * ((unsigned int )128u)))))))]));
  goto llvm_cbe_tmp__3320;

llvm_cbe_tmp__3320:
  llvm_cbe_tmp__3317 = *(&llvm_cbe_tmp__3309);
  return llvm_cbe_tmp__3317;
}


unsigned char *_ZN13SysCArray2DstIhLj2ELj512EEixEj(struct l_class_OC_SysCArray2Dst *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  unsigned char *llvm_cbe_tmp__3321;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3322;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3323;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3324;
  unsigned int llvm_cbe_tmp__3325;
  unsigned char *llvm_cbe_tmp__3326;
  unsigned int llvm_cbe_tmp__3327;
  unsigned char *llvm_cbe_tmp__3328;
  unsigned char *llvm_cbe_tmp__3329;

  *(&llvm_cbe_tmp__3322) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3323) = llvm_cbe_Xidx;
  llvm_cbe_tmp__3324 = *(&llvm_cbe_tmp__3322);
  llvm_cbe_tmp__3325 = *(&llvm_cbe_tmp__3323);
  if ((llvm_cbe_tmp__3325 == 0u)) {
    goto llvm_cbe_tmp__3330;
  } else {
    goto llvm_cbe_tmp__3331;
  }

llvm_cbe_tmp__3330:
  llvm_cbe_tmp__3326 = *((&llvm_cbe_tmp__3324->field1));
  *(&llvm_cbe_tmp__3321) = llvm_cbe_tmp__3326;
  goto llvm_cbe_tmp__3332;

llvm_cbe_tmp__3331:
  llvm_cbe_tmp__3327 = *(&llvm_cbe_tmp__3323);
  llvm_cbe_tmp__3328 = *((&llvm_cbe_tmp__3324->field0));
  *(&llvm_cbe_tmp__3321) = ((&llvm_cbe_tmp__3328[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__3327) * ((unsigned int )512u)))))))]));
  goto llvm_cbe_tmp__3332;

llvm_cbe_tmp__3332:
  llvm_cbe_tmp__3329 = *(&llvm_cbe_tmp__3321);
  return llvm_cbe_tmp__3329;
}


float *_ZN11SysCArray2DIfLj501ELj101EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3333;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3334;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3335;
  unsigned int llvm_cbe_tmp__3336;
  float *llvm_cbe_tmp__3337;

  *(&llvm_cbe_tmp__3333) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3334) = llvm_cbe_Xidx;
  llvm_cbe_tmp__3335 = *(&llvm_cbe_tmp__3333);
  llvm_cbe_tmp__3336 = *(&llvm_cbe_tmp__3334);
  llvm_cbe_tmp__3337 = *((&llvm_cbe_tmp__3335->field0));
  return ((&llvm_cbe_tmp__3337[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__3336) * ((unsigned int )101u)))))))]));
}


unsigned char *_ZN11SysCArray1DIbLj128EEixEj(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned int llvm_cbe_idx) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3338;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3339;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3340;
  unsigned int llvm_cbe_tmp__3341;
  unsigned char *llvm_cbe_tmp__3342;

  *(&llvm_cbe_tmp__3338) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3339) = llvm_cbe_idx;
  llvm_cbe_tmp__3340 = *(&llvm_cbe_tmp__3338);
  llvm_cbe_tmp__3341 = *(&llvm_cbe_tmp__3339);
  llvm_cbe_tmp__3342 = *((&llvm_cbe_tmp__3340->field0));
  return ((&llvm_cbe_tmp__3342[((signed long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__3341)))]));
}


unsigned int _ZN13sc_signal_u324readEv(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3343;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3344;
  unsigned int llvm_cbe_tmp__3345;

  *(&llvm_cbe_tmp__3343) = llvm_cbe_this;
  llvm_cbe_tmp__3344 = *(&llvm_cbe_tmp__3343);
  llvm_cbe_tmp__3345 = *((&llvm_cbe_tmp__3344->field0));
  return llvm_cbe_tmp__3345;
}


void _ZN13sc_signal_u325writeERKj(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned int *llvm_cbe_d) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3346;    /* Address-exposed local */
  unsigned int *llvm_cbe_tmp__3347;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3348;
  unsigned int *llvm_cbe_tmp__3349;
  unsigned int llvm_cbe_tmp__3350;

  *(&llvm_cbe_tmp__3346) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3347) = llvm_cbe_d;
  llvm_cbe_tmp__3348 = *(&llvm_cbe_tmp__3346);
  llvm_cbe_tmp__3349 = *(&llvm_cbe_tmp__3347);
  llvm_cbe_tmp__3350 = *llvm_cbe_tmp__3349;
  *((&llvm_cbe_tmp__3348->field0)) = llvm_cbe_tmp__3350;
  return;
}


float *_ZN11SysCArray1DIfLj5EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_idx) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3351;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3352;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3353;
  unsigned int llvm_cbe_tmp__3354;
  float *llvm_cbe_tmp__3355;

  *(&llvm_cbe_tmp__3351) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3352) = llvm_cbe_idx;
  llvm_cbe_tmp__3353 = *(&llvm_cbe_tmp__3351);
  llvm_cbe_tmp__3354 = *(&llvm_cbe_tmp__3352);
  llvm_cbe_tmp__3355 = *((&llvm_cbe_tmp__3353->field0));
  return ((&llvm_cbe_tmp__3355[((signed long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__3354)))]));
}


static void __cxx_global_var_init30(void) {
  _ZN3rbmC1Ev((&IMPL));
  return;
}


void _ZN3rbmC1Ev(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__3356;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__3357;

  *(&llvm_cbe_tmp__3356) = llvm_cbe_this;
  llvm_cbe_tmp__3357 = *(&llvm_cbe_tmp__3356);
  _ZN3rbmC2Ev(llvm_cbe_tmp__3357);
  return;
}


unsigned int main(void) {
  unsigned int llvm_cbe_tmp__3358;    /* Address-exposed local */
  _GLOBAL__I_a();  CODE_FOR_MAIN();
  *(&llvm_cbe_tmp__3358) = 0u;
  _ZN3rbm11predict_rbmEv((&IMPL));
  return 0u;
}


void _ZN8type_memItLj8EEC2Ev(struct l_unnamed2 *llvm_cbe_this) {
  struct l_unnamed2 *llvm_cbe_tmp__3359;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__3360;
  unsigned char *llvm_cbe_tmp__3361;

  *(&llvm_cbe_tmp__3359) = llvm_cbe_this;
  llvm_cbe_tmp__3360 = *(&llvm_cbe_tmp__3359);
  llvm_cbe_tmp__3361 = __CPROVER_malloc(16ull);
  *((&llvm_cbe_tmp__3360->field0)) = (((unsigned short *)llvm_cbe_tmp__3361));
  return;
}


void _ZN8type_memIbLj512EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3362;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3363;
  unsigned char *llvm_cbe_tmp__3364;

  *(&llvm_cbe_tmp__3362) = llvm_cbe_this;
  llvm_cbe_tmp__3363 = *(&llvm_cbe_tmp__3362);
  llvm_cbe_tmp__3364 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__3363->field0)) = llvm_cbe_tmp__3364;
  return;
}


void _ZN8type_memIhLj128EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3365;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3366;
  unsigned char *llvm_cbe_tmp__3367;

  *(&llvm_cbe_tmp__3365) = llvm_cbe_this;
  llvm_cbe_tmp__3366 = *(&llvm_cbe_tmp__3365);
  llvm_cbe_tmp__3367 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__3366->field0)) = llvm_cbe_tmp__3367;
  return;
}


void _ZN8type_memIjLj8EEC2Ev(struct l_unnamed1 *llvm_cbe_this) {
  struct l_unnamed1 *llvm_cbe_tmp__3368;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__3369;
  unsigned char *llvm_cbe_tmp__3370;

  *(&llvm_cbe_tmp__3368) = llvm_cbe_this;
  llvm_cbe_tmp__3369 = *(&llvm_cbe_tmp__3368);
  llvm_cbe_tmp__3370 = __CPROVER_malloc(32ull);
  *((&llvm_cbe_tmp__3369->field0)) = (((unsigned int *)llvm_cbe_tmp__3370));
  return;
}


void _ZN8type_memIbLj128EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3371;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3372;
  unsigned char *llvm_cbe_tmp__3373;

  *(&llvm_cbe_tmp__3371) = llvm_cbe_this;
  llvm_cbe_tmp__3372 = *(&llvm_cbe_tmp__3371);
  llvm_cbe_tmp__3373 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__3372->field0)) = llvm_cbe_tmp__3373;
  return;
}


void _ZN8type_memItLj8EED2Ev(struct l_unnamed2 *llvm_cbe_this) {
  struct l_unnamed2 *llvm_cbe_tmp__3374;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__3375;

  *(&llvm_cbe_tmp__3374) = llvm_cbe_this;
  llvm_cbe_tmp__3375 = *(&llvm_cbe_tmp__3374);
  return;
}


void _ZN8type_memIbLj512EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3376;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3377;

  *(&llvm_cbe_tmp__3376) = llvm_cbe_this;
  llvm_cbe_tmp__3377 = *(&llvm_cbe_tmp__3376);
  return;
}


void _ZN8type_memIhLj128EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3378;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3379;

  *(&llvm_cbe_tmp__3378) = llvm_cbe_this;
  llvm_cbe_tmp__3379 = *(&llvm_cbe_tmp__3378);
  return;
}


void _ZN8type_memIjLj8EED2Ev(struct l_unnamed1 *llvm_cbe_this) {
  struct l_unnamed1 *llvm_cbe_tmp__3380;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__3381;

  *(&llvm_cbe_tmp__3380) = llvm_cbe_this;
  llvm_cbe_tmp__3381 = *(&llvm_cbe_tmp__3380);
  return;
}


void _ZN8type_memIbLj128EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3382;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3383;

  *(&llvm_cbe_tmp__3382) = llvm_cbe_this;
  llvm_cbe_tmp__3383 = *(&llvm_cbe_tmp__3382);
  return;
}


void _ZN3rbmC2Ev(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__3384;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__3385;
  unsigned char *llvm_cbe_tmp__3386;
  unsigned char llvm_cbe_tmp__3387;
  unsigned char *llvm_cbe_tmp__3388;
  unsigned char llvm_cbe_tmp__3389;
  unsigned char *llvm_cbe_tmp__3390;
  unsigned char llvm_cbe_tmp__3391;
  unsigned char *llvm_cbe_tmp__3392;
  unsigned char llvm_cbe_tmp__3393;
  unsigned char *llvm_cbe_tmp__3394;
  unsigned char llvm_cbe_tmp__3395;

  *(&llvm_cbe_tmp__3384) = llvm_cbe_this;
  llvm_cbe_tmp__3385 = *(&llvm_cbe_tmp__3384);
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3385->field0)), ((&_OC_str31.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3385->field1)), ((&_OC_str32.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3385->field2)), ((&_OC_str33.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3385->field3)), ((&_OC_str34.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3385->field4)), ((&_OC_str35.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3385->field5)), ((&_OC_str36.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3385->field6)), ((&_OC_str37.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3385->field7)), ((&_OC_str38.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3385->field8)), ((&_OC_str39.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3385->field9)), ((&_OC_str40.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3385->field10)), ((&_OC_str41.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3385->field11)), ((&_OC_str42.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3385->field12)), ((&_OC_str43.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3385->field13)), ((&_OC_str44.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3385->field14)), ((&_OC_str45.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3385->field15)), ((&_OC_str46.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3385->field16)), ((&_OC_str47.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3385->field17)), ((&_OC_str48.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3385->field18)), ((&_OC_str49.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3385->field19)), ((&_OC_str50.array[((signed int )0u)])));
  _ZN13SysCArray2DstIhLj2ELj512EEC1Ev(((&llvm_cbe_tmp__3385->field20)));
  _ZN11SysCArray1DIbLj512EEC1Ev(((&llvm_cbe_tmp__3385->field21)));
  _ZN11SysCArray1DIbLj128EEC1Ev(((&llvm_cbe_tmp__3385->field22)));
  _ZN11SysCArray2DIfLj501ELj101EEC1Ev(((&llvm_cbe_tmp__3385->field23)));
  _ZN11SysCArray2DIbLj501ELj101EEC1Ev(((&llvm_cbe_tmp__3385->field24)));
  _ZN11SysCArray2DIbLj501ELj101EEC1Ev(((&llvm_cbe_tmp__3385->field25)));
  _ZN11SysCArray1DIfLj5EEC1Ev(((&llvm_cbe_tmp__3385->field26)));
  _ZN11SysCArray1DIbLj512EEC1Ev(((&llvm_cbe_tmp__3385->field27)));
  _ZN13SysCArray2DstIhLj2ELj128EEC1Ev(((&llvm_cbe_tmp__3385->field28)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__3385->field30)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__3385->field31)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__3385->field32)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__3385->field33)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__3385->field34)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__3385->field35)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3385->field36)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3385->field37)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3385->field38)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3385->field39)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3385->field40)));
  _ZN15sc_signal_int32C1Ev(((&llvm_cbe_tmp__3385->field41)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3385->field42)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3385->field43)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3385->field44)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3385->field45)));
  llvm_cbe_tmp__3386 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__3385->field1)));
  llvm_cbe_tmp__3387 = *llvm_cbe_tmp__3386;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__3387&1u))&1)))), 0);
  llvm_cbe_tmp__3388 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__3385->field1)));
  llvm_cbe_tmp__3389 = *llvm_cbe_tmp__3388;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__3389&1u))&1)))), 0);
  llvm_cbe_tmp__3390 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__3385->field1)));
  llvm_cbe_tmp__3391 = *llvm_cbe_tmp__3390;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__3391&1u))&1)))), 0);
  _Z14set_stack_sizei(5242880u);
  llvm_cbe_tmp__3392 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__3385->field1)));
  llvm_cbe_tmp__3393 = *llvm_cbe_tmp__3392;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__3393&1u))&1)))), 0);
  _Z14set_stack_sizei(5242880u);
  llvm_cbe_tmp__3394 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__3385->field1)));
  llvm_cbe_tmp__3395 = *llvm_cbe_tmp__3394;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__3395&1u))&1)))), 0);
  return;
}


void _ZN14sc_signal_boolC1EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3396;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__3397;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3398;
  unsigned char *llvm_cbe_tmp__3399;

  *(&llvm_cbe_tmp__3396) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3397) = llvm_cbe_p;
  llvm_cbe_tmp__3398 = *(&llvm_cbe_tmp__3396);
  llvm_cbe_tmp__3399 = *(&llvm_cbe_tmp__3397);
  _ZN14sc_signal_boolC2EPKc(llvm_cbe_tmp__3398, llvm_cbe_tmp__3399);
  return;
}


void _ZN13sc_signal_u32C1EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3400;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__3401;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3402;
  unsigned char *llvm_cbe_tmp__3403;

  *(&llvm_cbe_tmp__3400) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3401) = llvm_cbe_p;
  llvm_cbe_tmp__3402 = *(&llvm_cbe_tmp__3400);
  llvm_cbe_tmp__3403 = *(&llvm_cbe_tmp__3401);
  _ZN13sc_signal_u32C2EPKc(llvm_cbe_tmp__3402, llvm_cbe_tmp__3403);
  return;
}


void _ZN13SysCArray2DstIhLj2ELj512EEC1Ev(struct l_class_OC_SysCArray2Dst *llvm_cbe_this) {
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3404;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3405;

  *(&llvm_cbe_tmp__3404) = llvm_cbe_this;
  llvm_cbe_tmp__3405 = *(&llvm_cbe_tmp__3404);
  _ZN13SysCArray2DstIhLj2ELj512EEC2Ev(llvm_cbe_tmp__3405);
  return;
}


void _ZN11SysCArray1DIbLj512EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3406;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3407;

  *(&llvm_cbe_tmp__3406) = llvm_cbe_this;
  llvm_cbe_tmp__3407 = *(&llvm_cbe_tmp__3406);
  _ZN11SysCArray1DIbLj512EEC2Ev(llvm_cbe_tmp__3407);
  return;
}


void _ZN11SysCArray1DIbLj128EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3408;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3409;

  *(&llvm_cbe_tmp__3408) = llvm_cbe_this;
  llvm_cbe_tmp__3409 = *(&llvm_cbe_tmp__3408);
  _ZN11SysCArray1DIbLj128EEC2Ev(llvm_cbe_tmp__3409);
  return;
}


void _ZN11SysCArray2DIfLj501ELj101EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3410;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3411;

  *(&llvm_cbe_tmp__3410) = llvm_cbe_this;
  llvm_cbe_tmp__3411 = *(&llvm_cbe_tmp__3410);
  _ZN11SysCArray2DIfLj501ELj101EEC2Ev(llvm_cbe_tmp__3411);
  return;
}


void _ZN11SysCArray2DIbLj501ELj101EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3412;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3413;

  *(&llvm_cbe_tmp__3412) = llvm_cbe_this;
  llvm_cbe_tmp__3413 = *(&llvm_cbe_tmp__3412);
  _ZN11SysCArray2DIbLj501ELj101EEC2Ev(llvm_cbe_tmp__3413);
  return;
}


void _ZN11SysCArray1DIfLj5EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3414;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3415;

  *(&llvm_cbe_tmp__3414) = llvm_cbe_this;
  llvm_cbe_tmp__3415 = *(&llvm_cbe_tmp__3414);
  _ZN11SysCArray1DIfLj5EEC2Ev(llvm_cbe_tmp__3415);
  return;
}


void _ZN13SysCArray2DstIhLj2ELj128EEC1Ev(struct l_class_OC_SysCArray2Dst *llvm_cbe_this) {
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3416;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3417;

  *(&llvm_cbe_tmp__3416) = llvm_cbe_this;
  llvm_cbe_tmp__3417 = *(&llvm_cbe_tmp__3416);
  _ZN13SysCArray2DstIhLj2ELj128EEC2Ev(llvm_cbe_tmp__3417);
  return;
}


void _ZN13sc_signal_u16C1Ev(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__3418;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__3419;

  *(&llvm_cbe_tmp__3418) = llvm_cbe_this;
  llvm_cbe_tmp__3419 = *(&llvm_cbe_tmp__3418);
  _ZN13sc_signal_u16C2Ev(llvm_cbe_tmp__3419);
  return;
}


void _ZN14sc_signal_boolC1Ev(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3420;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3421;

  *(&llvm_cbe_tmp__3420) = llvm_cbe_this;
  llvm_cbe_tmp__3421 = *(&llvm_cbe_tmp__3420);
  _ZN14sc_signal_boolC2Ev(llvm_cbe_tmp__3421);
  return;
}


void _ZN15sc_signal_int32C1Ev(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3422;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3423;

  *(&llvm_cbe_tmp__3422) = llvm_cbe_this;
  llvm_cbe_tmp__3423 = *(&llvm_cbe_tmp__3422);
  _ZN15sc_signal_int32C2Ev(llvm_cbe_tmp__3423);
  return;
}


unsigned char *_ZN14sc_signal_boolcvRbEv(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3424;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3425;

  *(&llvm_cbe_tmp__3424) = llvm_cbe_this;
  llvm_cbe_tmp__3425 = *(&llvm_cbe_tmp__3424);
  return ((&llvm_cbe_tmp__3425->field0));
}


void _ZN15sc_signal_int32C2Ev(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3426;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3427;

  *(&llvm_cbe_tmp__3426) = llvm_cbe_this;
  llvm_cbe_tmp__3427 = *(&llvm_cbe_tmp__3426);
  return;
}


void _ZN14sc_signal_boolC2Ev(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3428;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3429;

  *(&llvm_cbe_tmp__3428) = llvm_cbe_this;
  llvm_cbe_tmp__3429 = *(&llvm_cbe_tmp__3428);
  return;
}


void _ZN13sc_signal_u16C2Ev(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__3430;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__3431;

  *(&llvm_cbe_tmp__3430) = llvm_cbe_this;
  llvm_cbe_tmp__3431 = *(&llvm_cbe_tmp__3430);
  return;
}


void _ZN13SysCArray2DstIhLj2ELj128EEC2Ev(struct l_class_OC_SysCArray2Dst *llvm_cbe_this) {
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3432;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3433;
  unsigned char *llvm_cbe_tmp__3434;
  unsigned char *llvm_cbe_tmp__3435;

  *(&llvm_cbe_tmp__3432) = llvm_cbe_this;
  llvm_cbe_tmp__3433 = *(&llvm_cbe_tmp__3432);
  llvm_cbe_tmp__3434 = __CPROVER_malloc(256ull);
  *((&llvm_cbe_tmp__3433->field0)) = llvm_cbe_tmp__3434;
  llvm_cbe_tmp__3435 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__3433->field1)) = llvm_cbe_tmp__3435;
  return;
}


void _ZN11SysCArray1DIfLj5EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3436;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3437;
  unsigned char *llvm_cbe_tmp__3438;

  *(&llvm_cbe_tmp__3436) = llvm_cbe_this;
  llvm_cbe_tmp__3437 = *(&llvm_cbe_tmp__3436);
  llvm_cbe_tmp__3438 = __CPROVER_malloc(20ull);
  *((&llvm_cbe_tmp__3437->field0)) = (((float *)llvm_cbe_tmp__3438));
  return;
}


void _ZN11SysCArray2DIbLj501ELj101EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3439;    /* Address-exposed local */
  unsigned int llvm_cbe_eqsize;    /* Address-exposed local */
  unsigned int llvm_cbe_acsize;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3440;
  unsigned int llvm_cbe_tmp__3441;
  unsigned int llvm_cbe_tmp__3442;
  unsigned int llvm_cbe_tmp__3443;
  unsigned int llvm_cbe_tmp__3444;
  unsigned int llvm_cbe_tmp__3445;
  unsigned int llvm_cbe_tmp__3446;
  unsigned int llvm_cbe_tmp__3447;
  unsigned int llvm_cbe_tmp__3448;
  unsigned int llvm_cbe_tmp__3449;
  unsigned int llvm_cbe_tmp__3450;
  unsigned int llvm_cbe_tmp__3451;
  unsigned int llvm_cbe_tmp__3452;
  unsigned int llvm_cbe_tmp__3453;
  unsigned int llvm_cbe_tmp__3454;
  unsigned int llvm_cbe_tmp__3455;
  unsigned int llvm_cbe_tmp__3456;
  unsigned int llvm_cbe_tmp__3457;
  unsigned int llvm_cbe_tmp__3458;
  unsigned int llvm_cbe_tmp__3459;
  unsigned int llvm_cbe_tmp__3460;
  unsigned int llvm_cbe_tmp__3461;
  unsigned int llvm_cbe_tmp__3462;
  unsigned int llvm_cbe_tmp__3463;
  unsigned int llvm_cbe_tmp__3464;
  unsigned int llvm_cbe_tmp__3465;
  unsigned int llvm_cbe_tmp__3466;
  unsigned int llvm_cbe_tmp__3467;
  unsigned int llvm_cbe_tmp__3468;
  unsigned int llvm_cbe_tmp__3469;
  unsigned int llvm_cbe_tmp__3470;
  unsigned int llvm_cbe_tmp__3471;
  unsigned int llvm_cbe_tmp__3472;
  unsigned int llvm_cbe_tmp__3473;
  unsigned char *llvm_cbe_tmp__3474;

  *(&llvm_cbe_tmp__3439) = llvm_cbe_this;
  llvm_cbe_tmp__3440 = *(&llvm_cbe_tmp__3439);
  *(&llvm_cbe_acsize) = 50601u;
  llvm_cbe_tmp__3441 = *(&llvm_cbe_acsize);
  if ((llvm_cbe_tmp__3441 == 1u)) {
    goto llvm_cbe_tmp__3475;
  } else {
    goto llvm_cbe_tmp__3476;
  }

llvm_cbe_tmp__3475:
  *(&llvm_cbe_eqsize) = 1u;
  goto llvm_cbe_tmp__3477;

llvm_cbe_tmp__3476:
  llvm_cbe_tmp__3442 = *(&llvm_cbe_acsize);
  if ((llvm_cbe_tmp__3442 == 2u)) {
    goto llvm_cbe_tmp__3478;
  } else {
    goto llvm_cbe_tmp__3479;
  }

llvm_cbe_tmp__3478:
  *(&llvm_cbe_eqsize) = 2u;
  goto llvm_cbe_tmp__3477;

llvm_cbe_tmp__3479:
  llvm_cbe_tmp__3443 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3444 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3443) > ((unsigned int )2u)) & (((unsigned int )llvm_cbe_tmp__3444) <= ((unsigned int )4u)))&1))) {
    goto llvm_cbe_tmp__3480;
  } else {
    goto llvm_cbe_tmp__3481;
  }

llvm_cbe_tmp__3480:
  *(&llvm_cbe_eqsize) = 4u;
  goto llvm_cbe_tmp__3477;

llvm_cbe_tmp__3481:
  llvm_cbe_tmp__3445 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3446 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3445) > ((unsigned int )4u)) & (((unsigned int )llvm_cbe_tmp__3446) <= ((unsigned int )8u)))&1))) {
    goto llvm_cbe_tmp__3482;
  } else {
    goto llvm_cbe_tmp__3483;
  }

llvm_cbe_tmp__3482:
  *(&llvm_cbe_eqsize) = 8u;
  goto llvm_cbe_tmp__3477;

llvm_cbe_tmp__3483:
  llvm_cbe_tmp__3447 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3448 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3447) > ((unsigned int )8u)) & (((unsigned int )llvm_cbe_tmp__3448) <= ((unsigned int )16u)))&1))) {
    goto llvm_cbe_tmp__3484;
  } else {
    goto llvm_cbe_tmp__3485;
  }

llvm_cbe_tmp__3484:
  *(&llvm_cbe_eqsize) = 16u;
  goto llvm_cbe_tmp__3477;

llvm_cbe_tmp__3485:
  llvm_cbe_tmp__3449 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3450 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3449) > ((unsigned int )16u)) & (((unsigned int )llvm_cbe_tmp__3450) <= ((unsigned int )32u)))&1))) {
    goto llvm_cbe_tmp__3486;
  } else {
    goto llvm_cbe_tmp__3487;
  }

llvm_cbe_tmp__3486:
  *(&llvm_cbe_eqsize) = 32u;
  goto llvm_cbe_tmp__3477;

llvm_cbe_tmp__3487:
  llvm_cbe_tmp__3451 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3452 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3451) > ((unsigned int )32u)) & (((unsigned int )llvm_cbe_tmp__3452) <= ((unsigned int )64u)))&1))) {
    goto llvm_cbe_tmp__3488;
  } else {
    goto llvm_cbe_tmp__3489;
  }

llvm_cbe_tmp__3488:
  *(&llvm_cbe_eqsize) = 64u;
  goto llvm_cbe_tmp__3477;

llvm_cbe_tmp__3489:
  llvm_cbe_tmp__3453 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3454 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3453) > ((unsigned int )64u)) & (((unsigned int )llvm_cbe_tmp__3454) <= ((unsigned int )128u)))&1))) {
    goto llvm_cbe_tmp__3490;
  } else {
    goto llvm_cbe_tmp__3491;
  }

llvm_cbe_tmp__3490:
  *(&llvm_cbe_eqsize) = 128u;
  goto llvm_cbe_tmp__3477;

llvm_cbe_tmp__3491:
  llvm_cbe_tmp__3455 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3456 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3455) > ((unsigned int )128u)) & (((unsigned int )llvm_cbe_tmp__3456) <= ((unsigned int )256u)))&1))) {
    goto llvm_cbe_tmp__3492;
  } else {
    goto llvm_cbe_tmp__3493;
  }

llvm_cbe_tmp__3492:
  *(&llvm_cbe_eqsize) = 256u;
  goto llvm_cbe_tmp__3477;

llvm_cbe_tmp__3493:
  llvm_cbe_tmp__3457 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3458 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3457) > ((unsigned int )256u)) & (((unsigned int )llvm_cbe_tmp__3458) <= ((unsigned int )512u)))&1))) {
    goto llvm_cbe_tmp__3494;
  } else {
    goto llvm_cbe_tmp__3495;
  }

llvm_cbe_tmp__3494:
  *(&llvm_cbe_eqsize) = 512u;
  goto llvm_cbe_tmp__3477;

llvm_cbe_tmp__3495:
  llvm_cbe_tmp__3459 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3460 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3459) > ((unsigned int )512u)) & (((unsigned int )llvm_cbe_tmp__3460) <= ((unsigned int )1024u)))&1))) {
    goto llvm_cbe_tmp__3496;
  } else {
    goto llvm_cbe_tmp__3497;
  }

llvm_cbe_tmp__3496:
  *(&llvm_cbe_eqsize) = 1024u;
  goto llvm_cbe_tmp__3477;

llvm_cbe_tmp__3497:
  llvm_cbe_tmp__3461 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3462 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3461) > ((unsigned int )1024u)) & (((unsigned int )llvm_cbe_tmp__3462) <= ((unsigned int )2048u)))&1))) {
    goto llvm_cbe_tmp__3498;
  } else {
    goto llvm_cbe_tmp__3499;
  }

llvm_cbe_tmp__3498:
  *(&llvm_cbe_eqsize) = 2048u;
  goto llvm_cbe_tmp__3477;

llvm_cbe_tmp__3499:
  llvm_cbe_tmp__3463 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3464 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3463) > ((unsigned int )2048u)) & (((unsigned int )llvm_cbe_tmp__3464) <= ((unsigned int )4096u)))&1))) {
    goto llvm_cbe_tmp__3500;
  } else {
    goto llvm_cbe_tmp__3501;
  }

llvm_cbe_tmp__3500:
  *(&llvm_cbe_eqsize) = 4096u;
  goto llvm_cbe_tmp__3477;

llvm_cbe_tmp__3501:
  llvm_cbe_tmp__3465 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3466 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3465) > ((unsigned int )4096u)) & (((unsigned int )llvm_cbe_tmp__3466) <= ((unsigned int )8192u)))&1))) {
    goto llvm_cbe_tmp__3502;
  } else {
    goto llvm_cbe_tmp__3503;
  }

llvm_cbe_tmp__3502:
  *(&llvm_cbe_eqsize) = 8192u;
  goto llvm_cbe_tmp__3477;

llvm_cbe_tmp__3503:
  llvm_cbe_tmp__3467 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3468 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3467) > ((unsigned int )8192u)) & (((unsigned int )llvm_cbe_tmp__3468) <= ((unsigned int )16384u)))&1))) {
    goto llvm_cbe_tmp__3504;
  } else {
    goto llvm_cbe_tmp__3505;
  }

llvm_cbe_tmp__3504:
  *(&llvm_cbe_eqsize) = 16384u;
  goto llvm_cbe_tmp__3477;

llvm_cbe_tmp__3505:
  llvm_cbe_tmp__3469 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3470 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3469) > ((unsigned int )16384u)) & (((unsigned int )llvm_cbe_tmp__3470) <= ((unsigned int )32768u)))&1))) {
    goto llvm_cbe_tmp__3506;
  } else {
    goto llvm_cbe_tmp__3507;
  }

llvm_cbe_tmp__3506:
  *(&llvm_cbe_eqsize) = 32768u;
  goto llvm_cbe_tmp__3477;

llvm_cbe_tmp__3507:
  llvm_cbe_tmp__3471 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3472 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3471) > ((unsigned int )32768u)) & (((unsigned int )llvm_cbe_tmp__3472) <= ((unsigned int )65536u)))&1))) {
    goto llvm_cbe_tmp__3508;
  } else {
    goto llvm_cbe_tmp__3477;
  }

llvm_cbe_tmp__3508:
  *(&llvm_cbe_eqsize) = 65536u;
  goto llvm_cbe_tmp__3477;

llvm_cbe_tmp__3477:
  llvm_cbe_tmp__3473 = *(&llvm_cbe_eqsize);
  llvm_cbe_tmp__3474 = __CPROVER_malloc((((unsigned long long )(((unsigned long long )1ull) * ((unsigned long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__3473)))))));
  *((&llvm_cbe_tmp__3440->field0)) = llvm_cbe_tmp__3474;
  return;
}


void _ZN11SysCArray2DIfLj501ELj101EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3509;    /* Address-exposed local */
  unsigned int llvm_cbe_eqsize;    /* Address-exposed local */
  unsigned int llvm_cbe_acsize;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3510;
  unsigned int llvm_cbe_tmp__3511;
  unsigned int llvm_cbe_tmp__3512;
  unsigned int llvm_cbe_tmp__3513;
  unsigned int llvm_cbe_tmp__3514;
  unsigned int llvm_cbe_tmp__3515;
  unsigned int llvm_cbe_tmp__3516;
  unsigned int llvm_cbe_tmp__3517;
  unsigned int llvm_cbe_tmp__3518;
  unsigned int llvm_cbe_tmp__3519;
  unsigned int llvm_cbe_tmp__3520;
  unsigned int llvm_cbe_tmp__3521;
  unsigned int llvm_cbe_tmp__3522;
  unsigned int llvm_cbe_tmp__3523;
  unsigned int llvm_cbe_tmp__3524;
  unsigned int llvm_cbe_tmp__3525;
  unsigned int llvm_cbe_tmp__3526;
  unsigned int llvm_cbe_tmp__3527;
  unsigned int llvm_cbe_tmp__3528;
  unsigned int llvm_cbe_tmp__3529;
  unsigned int llvm_cbe_tmp__3530;
  unsigned int llvm_cbe_tmp__3531;
  unsigned int llvm_cbe_tmp__3532;
  unsigned int llvm_cbe_tmp__3533;
  unsigned int llvm_cbe_tmp__3534;
  unsigned int llvm_cbe_tmp__3535;
  unsigned int llvm_cbe_tmp__3536;
  unsigned int llvm_cbe_tmp__3537;
  unsigned int llvm_cbe_tmp__3538;
  unsigned int llvm_cbe_tmp__3539;
  unsigned int llvm_cbe_tmp__3540;
  unsigned int llvm_cbe_tmp__3541;
  unsigned int llvm_cbe_tmp__3542;
  unsigned int llvm_cbe_tmp__3543;
  unsigned char *llvm_cbe_tmp__3544;

  *(&llvm_cbe_tmp__3509) = llvm_cbe_this;
  llvm_cbe_tmp__3510 = *(&llvm_cbe_tmp__3509);
  *(&llvm_cbe_acsize) = 50601u;
  llvm_cbe_tmp__3511 = *(&llvm_cbe_acsize);
  if ((llvm_cbe_tmp__3511 == 1u)) {
    goto llvm_cbe_tmp__3545;
  } else {
    goto llvm_cbe_tmp__3546;
  }

llvm_cbe_tmp__3545:
  *(&llvm_cbe_eqsize) = 1u;
  goto llvm_cbe_tmp__3547;

llvm_cbe_tmp__3546:
  llvm_cbe_tmp__3512 = *(&llvm_cbe_acsize);
  if ((llvm_cbe_tmp__3512 == 2u)) {
    goto llvm_cbe_tmp__3548;
  } else {
    goto llvm_cbe_tmp__3549;
  }

llvm_cbe_tmp__3548:
  *(&llvm_cbe_eqsize) = 2u;
  goto llvm_cbe_tmp__3547;

llvm_cbe_tmp__3549:
  llvm_cbe_tmp__3513 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3514 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3513) > ((unsigned int )2u)) & (((unsigned int )llvm_cbe_tmp__3514) <= ((unsigned int )4u)))&1))) {
    goto llvm_cbe_tmp__3550;
  } else {
    goto llvm_cbe_tmp__3551;
  }

llvm_cbe_tmp__3550:
  *(&llvm_cbe_eqsize) = 4u;
  goto llvm_cbe_tmp__3547;

llvm_cbe_tmp__3551:
  llvm_cbe_tmp__3515 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3516 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3515) > ((unsigned int )4u)) & (((unsigned int )llvm_cbe_tmp__3516) <= ((unsigned int )8u)))&1))) {
    goto llvm_cbe_tmp__3552;
  } else {
    goto llvm_cbe_tmp__3553;
  }

llvm_cbe_tmp__3552:
  *(&llvm_cbe_eqsize) = 8u;
  goto llvm_cbe_tmp__3547;

llvm_cbe_tmp__3553:
  llvm_cbe_tmp__3517 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3518 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3517) > ((unsigned int )8u)) & (((unsigned int )llvm_cbe_tmp__3518) <= ((unsigned int )16u)))&1))) {
    goto llvm_cbe_tmp__3554;
  } else {
    goto llvm_cbe_tmp__3555;
  }

llvm_cbe_tmp__3554:
  *(&llvm_cbe_eqsize) = 16u;
  goto llvm_cbe_tmp__3547;

llvm_cbe_tmp__3555:
  llvm_cbe_tmp__3519 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3520 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3519) > ((unsigned int )16u)) & (((unsigned int )llvm_cbe_tmp__3520) <= ((unsigned int )32u)))&1))) {
    goto llvm_cbe_tmp__3556;
  } else {
    goto llvm_cbe_tmp__3557;
  }

llvm_cbe_tmp__3556:
  *(&llvm_cbe_eqsize) = 32u;
  goto llvm_cbe_tmp__3547;

llvm_cbe_tmp__3557:
  llvm_cbe_tmp__3521 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3522 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3521) > ((unsigned int )32u)) & (((unsigned int )llvm_cbe_tmp__3522) <= ((unsigned int )64u)))&1))) {
    goto llvm_cbe_tmp__3558;
  } else {
    goto llvm_cbe_tmp__3559;
  }

llvm_cbe_tmp__3558:
  *(&llvm_cbe_eqsize) = 64u;
  goto llvm_cbe_tmp__3547;

llvm_cbe_tmp__3559:
  llvm_cbe_tmp__3523 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3524 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3523) > ((unsigned int )64u)) & (((unsigned int )llvm_cbe_tmp__3524) <= ((unsigned int )128u)))&1))) {
    goto llvm_cbe_tmp__3560;
  } else {
    goto llvm_cbe_tmp__3561;
  }

llvm_cbe_tmp__3560:
  *(&llvm_cbe_eqsize) = 128u;
  goto llvm_cbe_tmp__3547;

llvm_cbe_tmp__3561:
  llvm_cbe_tmp__3525 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3526 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3525) > ((unsigned int )128u)) & (((unsigned int )llvm_cbe_tmp__3526) <= ((unsigned int )256u)))&1))) {
    goto llvm_cbe_tmp__3562;
  } else {
    goto llvm_cbe_tmp__3563;
  }

llvm_cbe_tmp__3562:
  *(&llvm_cbe_eqsize) = 256u;
  goto llvm_cbe_tmp__3547;

llvm_cbe_tmp__3563:
  llvm_cbe_tmp__3527 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3528 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3527) > ((unsigned int )256u)) & (((unsigned int )llvm_cbe_tmp__3528) <= ((unsigned int )512u)))&1))) {
    goto llvm_cbe_tmp__3564;
  } else {
    goto llvm_cbe_tmp__3565;
  }

llvm_cbe_tmp__3564:
  *(&llvm_cbe_eqsize) = 512u;
  goto llvm_cbe_tmp__3547;

llvm_cbe_tmp__3565:
  llvm_cbe_tmp__3529 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3530 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3529) > ((unsigned int )512u)) & (((unsigned int )llvm_cbe_tmp__3530) <= ((unsigned int )1024u)))&1))) {
    goto llvm_cbe_tmp__3566;
  } else {
    goto llvm_cbe_tmp__3567;
  }

llvm_cbe_tmp__3566:
  *(&llvm_cbe_eqsize) = 1024u;
  goto llvm_cbe_tmp__3547;

llvm_cbe_tmp__3567:
  llvm_cbe_tmp__3531 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3532 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3531) > ((unsigned int )1024u)) & (((unsigned int )llvm_cbe_tmp__3532) <= ((unsigned int )2048u)))&1))) {
    goto llvm_cbe_tmp__3568;
  } else {
    goto llvm_cbe_tmp__3569;
  }

llvm_cbe_tmp__3568:
  *(&llvm_cbe_eqsize) = 2048u;
  goto llvm_cbe_tmp__3547;

llvm_cbe_tmp__3569:
  llvm_cbe_tmp__3533 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3534 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3533) > ((unsigned int )2048u)) & (((unsigned int )llvm_cbe_tmp__3534) <= ((unsigned int )4096u)))&1))) {
    goto llvm_cbe_tmp__3570;
  } else {
    goto llvm_cbe_tmp__3571;
  }

llvm_cbe_tmp__3570:
  *(&llvm_cbe_eqsize) = 4096u;
  goto llvm_cbe_tmp__3547;

llvm_cbe_tmp__3571:
  llvm_cbe_tmp__3535 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3536 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3535) > ((unsigned int )4096u)) & (((unsigned int )llvm_cbe_tmp__3536) <= ((unsigned int )8192u)))&1))) {
    goto llvm_cbe_tmp__3572;
  } else {
    goto llvm_cbe_tmp__3573;
  }

llvm_cbe_tmp__3572:
  *(&llvm_cbe_eqsize) = 8192u;
  goto llvm_cbe_tmp__3547;

llvm_cbe_tmp__3573:
  llvm_cbe_tmp__3537 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3538 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3537) > ((unsigned int )8192u)) & (((unsigned int )llvm_cbe_tmp__3538) <= ((unsigned int )16384u)))&1))) {
    goto llvm_cbe_tmp__3574;
  } else {
    goto llvm_cbe_tmp__3575;
  }

llvm_cbe_tmp__3574:
  *(&llvm_cbe_eqsize) = 16384u;
  goto llvm_cbe_tmp__3547;

llvm_cbe_tmp__3575:
  llvm_cbe_tmp__3539 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3540 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3539) > ((unsigned int )16384u)) & (((unsigned int )llvm_cbe_tmp__3540) <= ((unsigned int )32768u)))&1))) {
    goto llvm_cbe_tmp__3576;
  } else {
    goto llvm_cbe_tmp__3577;
  }

llvm_cbe_tmp__3576:
  *(&llvm_cbe_eqsize) = 32768u;
  goto llvm_cbe_tmp__3547;

llvm_cbe_tmp__3577:
  llvm_cbe_tmp__3541 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3542 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3541) > ((unsigned int )32768u)) & (((unsigned int )llvm_cbe_tmp__3542) <= ((unsigned int )65536u)))&1))) {
    goto llvm_cbe_tmp__3578;
  } else {
    goto llvm_cbe_tmp__3547;
  }

llvm_cbe_tmp__3578:
  *(&llvm_cbe_eqsize) = 65536u;
  goto llvm_cbe_tmp__3547;

llvm_cbe_tmp__3547:
  llvm_cbe_tmp__3543 = *(&llvm_cbe_eqsize);
  llvm_cbe_tmp__3544 = __CPROVER_malloc((((unsigned long long )(((unsigned long long )4ull) * ((unsigned long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__3543)))))));
  *((&llvm_cbe_tmp__3510->field0)) = (((float *)llvm_cbe_tmp__3544));
  return;
}


void _ZN11SysCArray1DIbLj128EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3579;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3580;
  unsigned char *llvm_cbe_tmp__3581;

  *(&llvm_cbe_tmp__3579) = llvm_cbe_this;
  llvm_cbe_tmp__3580 = *(&llvm_cbe_tmp__3579);
  llvm_cbe_tmp__3581 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__3580->field0)) = llvm_cbe_tmp__3581;
  return;
}


void _ZN11SysCArray1DIbLj512EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3582;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3583;
  unsigned char *llvm_cbe_tmp__3584;

  *(&llvm_cbe_tmp__3582) = llvm_cbe_this;
  llvm_cbe_tmp__3583 = *(&llvm_cbe_tmp__3582);
  llvm_cbe_tmp__3584 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__3583->field0)) = llvm_cbe_tmp__3584;
  return;
}


void _ZN13SysCArray2DstIhLj2ELj512EEC2Ev(struct l_class_OC_SysCArray2Dst *llvm_cbe_this) {
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3585;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3586;
  unsigned char *llvm_cbe_tmp__3587;
  unsigned char *llvm_cbe_tmp__3588;

  *(&llvm_cbe_tmp__3585) = llvm_cbe_this;
  llvm_cbe_tmp__3586 = *(&llvm_cbe_tmp__3585);
  llvm_cbe_tmp__3587 = __CPROVER_malloc(1024ull);
  *((&llvm_cbe_tmp__3586->field0)) = llvm_cbe_tmp__3587;
  llvm_cbe_tmp__3588 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__3586->field1)) = llvm_cbe_tmp__3588;
  return;
}


void _ZN13sc_signal_u32C2EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3589;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__3590;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3591;

  *(&llvm_cbe_tmp__3589) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3590) = llvm_cbe_p;
  llvm_cbe_tmp__3591 = *(&llvm_cbe_tmp__3589);
  return;
}


void _ZN14sc_signal_boolC2EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3592;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__3593;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3594;

  *(&llvm_cbe_tmp__3592) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3593) = llvm_cbe_p;
  llvm_cbe_tmp__3594 = *(&llvm_cbe_tmp__3592);
  return;
}


void _ZN13model_predictD2Ev(struct l_class_OC_model_predict *llvm_cbe_this) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__3595;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__3596;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3597;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__3598;

  *(&llvm_cbe_tmp__3595) = llvm_cbe_this;
  llvm_cbe_tmp__3598 = *(&llvm_cbe_tmp__3595);
  _ZN8type_memItLj8EED1Ev(((&llvm_cbe_tmp__3598->field35)));
  _ZN8type_memIbLj512EED1Ev(((&llvm_cbe_tmp__3598->field26)));
  _ZN8type_memIhLj128EED1Ev(((&llvm_cbe_tmp__3598->field22)));
  _ZN8type_memIjLj8EED1Ev(((&llvm_cbe_tmp__3598->field18)));
  _ZN8type_memIbLj128EED1Ev(((&llvm_cbe_tmp__3598->field6)));
  _ZN8type_memIhLj65536EED1Ev(((&llvm_cbe_tmp__3598->field4)));
  _ZN8type_memIhLj512EED1Ev(((&llvm_cbe_tmp__3598->field1)));
  return;
}


void _ZN8type_memIhLj65536EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3599;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3600;

  *(&llvm_cbe_tmp__3599) = llvm_cbe_this;
  llvm_cbe_tmp__3600 = *(&llvm_cbe_tmp__3599);
  _ZN8type_memIhLj65536EED2Ev(llvm_cbe_tmp__3600);
  return;
}


void _ZN8type_memIhLj512EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3601;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3602;

  *(&llvm_cbe_tmp__3601) = llvm_cbe_this;
  llvm_cbe_tmp__3602 = *(&llvm_cbe_tmp__3601);
  _ZN8type_memIhLj512EED2Ev(llvm_cbe_tmp__3602);
  return;
}


void _ZN8type_memIhLj512EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3603;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3604;

  *(&llvm_cbe_tmp__3603) = llvm_cbe_this;
  llvm_cbe_tmp__3604 = *(&llvm_cbe_tmp__3603);
  return;
}


void _ZN8type_memIhLj65536EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3605;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3606;

  *(&llvm_cbe_tmp__3605) = llvm_cbe_this;
  llvm_cbe_tmp__3606 = *(&llvm_cbe_tmp__3605);
  return;
}


void _ZN13model_predictC2Ev(struct l_class_OC_model_predict *llvm_cbe_this) {
  struct l_class_OC_model_predict *llvm_cbe_tmp__3607;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__3608;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3609;    /* Address-exposed local */
  struct l_class_OC_model_predict *llvm_cbe_tmp__3610;
  unsigned long long llvm_cbe_tmp__3611;
  unsigned long long llvm_cbe_tmp__3612;

  *(&llvm_cbe_tmp__3607) = llvm_cbe_this;
  llvm_cbe_tmp__3610 = *(&llvm_cbe_tmp__3607);
  _ZN8type_memIhLj512EEC1El(((&llvm_cbe_tmp__3610->field1)), 0ull);
  _ZN8type_memIhLj65536EEC1El(((&llvm_cbe_tmp__3610->field4)), 0ull);
  _ZN8type_memIbLj128EEC1El(((&llvm_cbe_tmp__3610->field6)), 0ull);
  _ZN8type_memIjLj8EEC1El(((&llvm_cbe_tmp__3610->field18)), 0ull);
  _ZN8type_memIhLj128EEC1El(((&llvm_cbe_tmp__3610->field22)), 0ull);
  _ZN8type_memIbLj512EEC1El(((&llvm_cbe_tmp__3610->field26)), 0ull);
  _ZN8type_memItLj8EEC1El(((&llvm_cbe_tmp__3610->field35)), 0ull);
  *((&llvm_cbe_tmp__3610->field40)) = 1ull;
  *((&llvm_cbe_tmp__3610->field41)) = 65535ull;
  *((&llvm_cbe_tmp__3610->field42)) = 131071ull;
  *((&llvm_cbe_tmp__3610->field43)) = 536870911ull;
  *((&llvm_cbe_tmp__3610->field44)) = 7ull;
  *((&llvm_cbe_tmp__3610->field45)) = 4294967295ull;
  *((&llvm_cbe_tmp__3610->field46)) = 9223372036854775807ull;
  *((&llvm_cbe_tmp__3610->field47)) = 18446744073709551615ull;
  *((&llvm_cbe_tmp__3610->field48)) = 127ull;
  *((&llvm_cbe_tmp__3610->field49)) = 255ull;
  *((&llvm_cbe_tmp__3610->field50)) = 18446744073709551615ull;
  *((&llvm_cbe_tmp__3610->field51)) = 511ull;
  *((&llvm_cbe_tmp__3610->field52)) = 32768ull;
  *((&llvm_cbe_tmp__3610->field53)) = 64ull;
  llvm_cbe_tmp__3611 = *((&llvm_cbe_tmp__3610->field41));
  *((&llvm_cbe_tmp__3610->field54)) = (llvm_cbe_tmp__3611 ^ 18446744073709551615ull);
  llvm_cbe_tmp__3612 = *((&llvm_cbe_tmp__3610->field48));
  *((&llvm_cbe_tmp__3610->field55)) = (llvm_cbe_tmp__3612 ^ 18446744073709551615ull);
  return;
}


void _ZN8type_memIhLj512EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3613;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3614;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3615;
  unsigned long long llvm_cbe_tmp__3616;

  *(&llvm_cbe_tmp__3613) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3614) = llvm_cbe_def;
  llvm_cbe_tmp__3615 = *(&llvm_cbe_tmp__3613);
  llvm_cbe_tmp__3616 = *(&llvm_cbe_tmp__3614);
  _ZN8type_memIhLj512EEC2El(llvm_cbe_tmp__3615, llvm_cbe_tmp__3616);
  return;
}


void _ZN8type_memIhLj65536EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3617;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3618;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3619;
  unsigned long long llvm_cbe_tmp__3620;

  *(&llvm_cbe_tmp__3617) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3618) = llvm_cbe_def;
  llvm_cbe_tmp__3619 = *(&llvm_cbe_tmp__3617);
  llvm_cbe_tmp__3620 = *(&llvm_cbe_tmp__3618);
  _ZN8type_memIhLj65536EEC2El(llvm_cbe_tmp__3619, llvm_cbe_tmp__3620);
  return;
}


void _ZN8type_memIbLj128EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3621;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3622;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3623;
  unsigned long long llvm_cbe_tmp__3624;

  *(&llvm_cbe_tmp__3621) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3622) = llvm_cbe_def;
  llvm_cbe_tmp__3623 = *(&llvm_cbe_tmp__3621);
  llvm_cbe_tmp__3624 = *(&llvm_cbe_tmp__3622);
  _ZN8type_memIbLj128EEC2El(llvm_cbe_tmp__3623, llvm_cbe_tmp__3624);
  return;
}


void _ZN8type_memIjLj8EEC1El(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_unnamed1 *llvm_cbe_tmp__3625;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3626;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__3627;
  unsigned long long llvm_cbe_tmp__3628;

  *(&llvm_cbe_tmp__3625) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3626) = llvm_cbe_def;
  llvm_cbe_tmp__3627 = *(&llvm_cbe_tmp__3625);
  llvm_cbe_tmp__3628 = *(&llvm_cbe_tmp__3626);
  _ZN8type_memIjLj8EEC2El(llvm_cbe_tmp__3627, llvm_cbe_tmp__3628);
  return;
}


void _ZN8type_memIhLj128EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3629;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3630;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3631;
  unsigned long long llvm_cbe_tmp__3632;

  *(&llvm_cbe_tmp__3629) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3630) = llvm_cbe_def;
  llvm_cbe_tmp__3631 = *(&llvm_cbe_tmp__3629);
  llvm_cbe_tmp__3632 = *(&llvm_cbe_tmp__3630);
  _ZN8type_memIhLj128EEC2El(llvm_cbe_tmp__3631, llvm_cbe_tmp__3632);
  return;
}


void _ZN8type_memIbLj512EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3633;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3634;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3635;
  unsigned long long llvm_cbe_tmp__3636;

  *(&llvm_cbe_tmp__3633) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3634) = llvm_cbe_def;
  llvm_cbe_tmp__3635 = *(&llvm_cbe_tmp__3633);
  llvm_cbe_tmp__3636 = *(&llvm_cbe_tmp__3634);
  _ZN8type_memIbLj512EEC2El(llvm_cbe_tmp__3635, llvm_cbe_tmp__3636);
  return;
}


void _ZN8type_memItLj8EEC1El(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_unnamed2 *llvm_cbe_tmp__3637;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3638;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__3639;
  unsigned long long llvm_cbe_tmp__3640;

  *(&llvm_cbe_tmp__3637) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3638) = llvm_cbe_def;
  llvm_cbe_tmp__3639 = *(&llvm_cbe_tmp__3637);
  llvm_cbe_tmp__3640 = *(&llvm_cbe_tmp__3638);
  _ZN8type_memItLj8EEC2El(llvm_cbe_tmp__3639, llvm_cbe_tmp__3640);
  return;
}


void _ZN8type_memItLj8EEC2El(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_unnamed2 *llvm_cbe_tmp__3641;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3642;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__3643;
  unsigned char *llvm_cbe_tmp__3644;

  *(&llvm_cbe_tmp__3641) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3642) = llvm_cbe_def;
  llvm_cbe_tmp__3643 = *(&llvm_cbe_tmp__3641);
  llvm_cbe_tmp__3644 = __CPROVER_malloc(16ull);
  *((&llvm_cbe_tmp__3643->field0)) = (((unsigned short *)llvm_cbe_tmp__3644));
  return;
}


void _ZN8type_memIbLj512EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3645;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3646;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3647;
  unsigned char *llvm_cbe_tmp__3648;

  *(&llvm_cbe_tmp__3645) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3646) = llvm_cbe_def;
  llvm_cbe_tmp__3647 = *(&llvm_cbe_tmp__3645);
  llvm_cbe_tmp__3648 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__3647->field0)) = llvm_cbe_tmp__3648;
  return;
}


void _ZN8type_memIhLj128EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3649;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3650;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3651;
  unsigned char *llvm_cbe_tmp__3652;

  *(&llvm_cbe_tmp__3649) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3650) = llvm_cbe_def;
  llvm_cbe_tmp__3651 = *(&llvm_cbe_tmp__3649);
  llvm_cbe_tmp__3652 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__3651->field0)) = llvm_cbe_tmp__3652;
  return;
}


void _ZN8type_memIjLj8EEC2El(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_unnamed1 *llvm_cbe_tmp__3653;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3654;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__3655;
  unsigned char *llvm_cbe_tmp__3656;

  *(&llvm_cbe_tmp__3653) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3654) = llvm_cbe_def;
  llvm_cbe_tmp__3655 = *(&llvm_cbe_tmp__3653);
  llvm_cbe_tmp__3656 = __CPROVER_malloc(32ull);
  *((&llvm_cbe_tmp__3655->field0)) = (((unsigned int *)llvm_cbe_tmp__3656));
  return;
}


void _ZN8type_memIbLj128EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3657;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3658;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3659;
  unsigned char *llvm_cbe_tmp__3660;

  *(&llvm_cbe_tmp__3657) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3658) = llvm_cbe_def;
  llvm_cbe_tmp__3659 = *(&llvm_cbe_tmp__3657);
  llvm_cbe_tmp__3660 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__3659->field0)) = llvm_cbe_tmp__3660;
  return;
}


void _ZN8type_memIhLj65536EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3661;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3662;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3663;
  unsigned char *llvm_cbe_tmp__3664;

  *(&llvm_cbe_tmp__3661) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3662) = llvm_cbe_def;
  llvm_cbe_tmp__3663 = *(&llvm_cbe_tmp__3661);
  llvm_cbe_tmp__3664 = __CPROVER_malloc(65536ull);
  *((&llvm_cbe_tmp__3663->field0)) = llvm_cbe_tmp__3664;
  return;
}


void _ZN8type_memIhLj512EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3665;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3666;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3667;
  unsigned char *llvm_cbe_tmp__3668;

  *(&llvm_cbe_tmp__3665) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3666) = llvm_cbe_def;
  llvm_cbe_tmp__3667 = *(&llvm_cbe_tmp__3665);
  llvm_cbe_tmp__3668 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__3667->field0)) = llvm_cbe_tmp__3668;
  return;
}


static void _GLOBAL__I_a(void) {
  __cxx_global_var_init();
  __cxx_global_var_init30();
  return;
}

